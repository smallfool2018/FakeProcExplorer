#include "stdafx.h"
#include "../ProcExplorer.h"

DWORD WINAPI TraceEventThreadProc(void* p);

extern WCHAR* gszNullString;
PE_TIME	gTime;


CEventItemList	gEventItemList;

//void EventItem_Initialize(tagEventItem& Item, GUID* pIID, WORD a, WORD b, bool c)
//{
//	Item.wValue_24 = a;
//	Item.wValue_26 = b;
//	Item.bValue_28 = c;
//}

EVENT_TRACE_PROPERTIES_EX gProperties;
//////////////////////////////////////////////////////////////////////////
/// 线程ID-到进程ID映射关系的表
typedef map<DWORD, DWORD> CThreadProcessMap;

CThreadProcessMap gThreadProcessMap;


#define EVENT_TRACE_TYPE_PROCEXP	10
#define EVENT_TRACE_TYPE_PROCEXP2	11

void ScanAllThreads();


ULONG PE_RunTrace(LPEVENT_TRACE_PROPERTIES_EX Properties, bool fStart)
{
	ULONG ret = 0;
	if (Properties->fTraceStarted == fStart)
		return ret;
	if (!Properties->ApiLoaded)
	{
		Properties->ApiLoaded = true;
	}
	Properties->baseclass.Wnode.BufferSize =
		sizeof(EVENT_TRACE_PROPERTIES_EX);
	Properties->baseclass.Wnode.Flags = WNODE_FLAG_TRACED_GUID;
	Properties->baseclass.FlushTimer = 1;	///1秒一次记录

	/// Query performance counter (QPC).
	Properties->baseclass.Wnode.ClientContext = 1;

	ULONG LogMode = 0;
	if (gdwVersion < WINDOWS_8)
		LogMode = EVENT_TRACE_FLAG_FILE_IO;
	Properties->baseclass.LogFileMode = LogMode | EVENT_TRACE_REAL_TIME_MODE;

	Properties->baseclass.LoggerNameOffset = sizeof(EVENT_TRACE_PROPERTIES);
	Properties->baseclass.LogFileNameOffset = sizeof(EVENT_TRACE_PROPERTIES) + _MAX_PATH * sizeof(WCHAR);
	wcscpy_s(Properties->szSessionName, MAX_PATH,
		gdwVersion < WINDOWS_8 ? L"NT Kernel Logger" : L"PROCEXP TRACE");
	wcscpy_s(Properties->szLogFileName, MAX_PATH, gszNullString);
	Properties->baseclass.EnableFlags = EVENT_TRACE_FLAG_DISK_IO | EVENT_TRACE_FLAG_NETWORK_TCPIP;
	if (gdwVersion >= WINDOWS_8)
		Properties->baseclass.EnableFlags |= EVENT_TRACE_FLAG_THREAD;

	if (fStart)
	{
		///启动跟踪
		ret = StartTraceW(&Properties->SessionHandle,
			Properties->szSessionName,
			(PEVENT_TRACE_PROPERTIES)Properties);
		if (!ret || ret == ERROR_ALIAS_EXISTS)
		{
			Properties->fTraceStarted = true;
			DWORD dwThreadId = 0;
			Properties->ThreadHandle
				= CreateThread(NULL, 0, TraceEventThreadProc, (void*)Properties, 0, &dwThreadId);
			if (gdwVersion >= WINDOWS_8)
			{
				ScanAllThreads();
				return 0;
			}
		}
	}
	else
	{
		///停止相关的事件跟踪
		SetEvent(Properties->EventHandle);
		ret = ControlTraceW(Properties->SessionHandle,
			Properties->szSessionName,
			(PEVENT_TRACE_PROPERTIES)Properties,
			EVENT_TRACE_CONTROL_STOP);

		///等候线程结束
		WaitForSingleObject(Properties->ThreadHandle, INFINITE);

		///清理
		CloseHandle(Properties->ThreadHandle);
		Properties->ThreadHandle = NULL;
		ResetEvent(Properties->EventHandle);
	}

	return ret;
}


ULONG __stdcall LogBufferCallback(PEVENT_TRACE_LOGFILEW LogFile)
{
	return 1;
}

HRESULT SetProxyAccessRights(tagWbemServicesList* pList)
{
	CComPtr<IWbemLocator> pWbemLocator;

	CoInitialize(NULL);
	CComBSTR strNetworkResource(L"root\\wmi");
	HRESULT hr = CoCreateInstance(CLSID_WbemLocator, NULL, CLSCTX_INPROC_SERVER, __uuidof(IWbemLocator), (void**)&pWbemLocator);
	if (SUCCEEDED(hr))
	{
		/*WBEM_FLAG_CONNECT_REPOSITORY_ONLY;*/
		hr = pWbemLocator->ConnectServer(strNetworkResource, NULL, NULL, NULL, 0, NULL, NULL, &pList->pWbemSevices);
		if (SUCCEEDED(hr))
		{
			hr = CoSetProxyBlanket(pList->pWbemSevices,
				RPC_C_AUTHN_WINNT,			///NTLMSSP
				RPC_C_AUTHZ_NONE,			///The server performs no authorization. Currently, RPC_C_AUTHN_WINNT, 
											///RPC_C_AUTHN_GSS_SCHANNEL, and RPC_C_AUTHN_GSS_KERBEROS all use
											///only RPC_C_AUTHZ_NONE
				NULL,
				RPC_C_AUTHN_LEVEL_PKT,		///Authenticates that all data received is from the expected client.
				RPC_C_IMP_LEVEL_IMPERSONATE,///The server process can impersonate the client's security context 
											///while acting on behalf of the client. This level of impersonation 
											///can be used to access local resources such as files. When 
											///impersonating at this level, the impersonation token can only be 
											///passed across one machine boundary. The Schannel authentication
											///service only supports this level of impersonation. 
				NULL,
				EOAC_NONE);					///Indicates that no capability flags are set.
		}
	}
	return hr;
}

_bstr_t* QueryEventTraceNameEx(tagWbemServicesList* pList,IWbemClassObject* pClassObject, GUID& iid, WORD Version, BYTE Level, WORD wType)
{
	_bstr_t* ret = NULL;
	CComBSTR bstrClass(L"__CLASS");
	CComBSTR bstrDataId(L"WmiDataId");
	CComBSTR bstrEventType(L"EventType");
	CComBSTR bstrTypeName(L"EventTypeName");
	CComBSTR bstrDisplyName(L"DisplayName");

	CComVariant vtValue;
	CEventItemList tmpList;

	DEFINEPATHTEXT(Text);

	HRESULT hres = pClassObject->Get(bstrClass, 0, &vtValue, NULL, NULL);
	if (SUCCEEDED(hres))
	{
		CComBSTR bstrClassValue(vtValue.bstrVal);

		wcscpy_s(szText, _MAX_PATH, vtValue.bstrVal);
		CComPtr<IWbemQualifierSet>	pQualifierSet;
		hres = pClassObject->GetQualifierSet(&pQualifierSet);
		if (SUCCEEDED(hres))
		{
			CComVariant vtRet;
			hres = pQualifierSet->Get(bstrDisplyName, 0, &vtRet, NULL);
			if (SUCCEEDED(hres))
			{
				wcscpy_s(szText, _MAX_PATH, vtRet.bstrVal);
				
				tagEventItem* pItem = new tagEventItem(&iid, -1, -1, -1);
				pItem->SetEventTraceText(szText);
				tmpList.push_back(pItem);

				CComPtr<IEnumWbemClassObject> pEnum;
				hres = pList->pWbemSevices->CreateClassEnum(bstrClassValue,
					WBEM_FLAG_USE_AMENDED_QUALIFIERS | WBEM_FLAG_SHALLOW,
					NULL,
					&pEnum);
				if (SUCCEEDED(hres))
				{

				}
			}
		}
	}
	return ret;
}

_bstr_t* QueryEventTraceName(tagWbemServicesList* pList, GUID& iid, WORD Type, WORD Version, BYTE Level)
{
	_bstr_t* ret = NULL;
	if (!pList->pWbemSevices || SetProxyAccessRights(pList))
		return ret;
	CComVariant vtName, vtValue;
	WCHAR szText[_MAX_PATH] = { 0 };
	DEFINEPATHTEXT(Qualifier);

	HRESULT hres;

	swprintf_s(
		szText,
		_MAX_PATH,
		L"{%08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x}",
		iid.Data1,
		iid.Data2,
		iid.Data3,
		iid.Data4[0],
		iid.Data4[1],
		iid.Data4[2],
		iid.Data4[3],
		iid.Data4[4],
		iid.Data4[5],
		iid.Data4[6],
		iid.Data4[7]);

	CComBSTR bstrTrace(L"EventTrace");
	CComBSTR bstrClass(L"__CLASS");
	CComBSTR bstrGuid(L"Guid");
	CComBSTR bstrVersion(L"EventVersion");

	ULONG uRet = 1;
	ULONG uReturned = 1;
	CComPtr<IEnumWbemClassObject> pEnum;
	CComPtr<IEnumWbemClassObject> pEnum2;
	CComPtr<IWbemClassObject>	pClassObject;
	CComPtr<IWbemClassObject>	pClassObject2;

	HRESULT hr = pList->pWbemSevices->CreateClassEnum(bstrTrace,
		WBEM_FLAG_USE_AMENDED_QUALIFIERS | WBEM_FLAG_SHALLOW,
		NULL,
		&pEnum);

	if (FAILED(hr))
		return ret;

	do 
	{
		if(pEnum->Next(5000,1,&pClassObject,&uReturned))
			continue;
		if(pClassObject->Get(bstrClass,0,&vtValue,NULL,NULL))
			continue;;
		CComBSTR bstrRealName(vtValue.bstrVal);

		pList->pWbemSevices->CreateClassEnum(bstrRealName,
			WBEM_FLAG_USE_AMENDED_QUALIFIERS | WBEM_FLAG_SHALLOW,
			NULL,
			&pEnum2);


		uRet = 1;
		do 
		{
			if (pEnum2)
			{
				if (pEnum2->Next(5000, 1, &pClassObject2, &uRet))
					continue;
				if (uRet != 1)
					break;
			}
			else
			{
				pClassObject2 = pClassObject;
				uRet = 1;
			}
			hres = pClassObject2->Get(bstrClass, 0, &vtName, NULL, NULL);
			if (SUCCEEDED(hres))
			{
				CComPtr<IWbemQualifierSet>	pQualifierSet;
				hres = pClassObject2->GetQualifierSet(&pQualifierSet);
				if (SUCCEEDED(hres))
				{
					CComVariant vtRet;
					hres = pQualifierSet->Get(bstrGuid, 0, &vtRet, NULL);
					if (SUCCEEDED(hres))
					{
						wcscpy_s(szQualifier, _MAX_PATH, vtRet.bstrVal);
						WCHAR* pstr = wcsstr(szQualifier, L"{");
						if (!pstr)
							wsprintfW(szQualifier, L"{%s}", szQualifier);

						if (!_wcsicmp(szQualifier, szText))
						{
							CComVariant vtVersion;
							hres = pQualifierSet->Get(bstrVersion, 0, &vtVersion, NULL);
							if (FAILED(hres))
							{
								return QueryEventTraceNameEx(pList, pClassObject2, iid, 0xFFFF, Level, Type);
							}
							else
							{
								return QueryEventTraceNameEx(pList, pClassObject2, iid, vtVersion.iVal, Level, Type);
							}
						}
					}
				}
			}
		} while (uRet == 1);
	} while (uReturned == 1);



	return ret;
}

tagWbemServicesList gWbemServiceList;

static const GUID  GUID_PROCEXP_EVENT =
{ 0xFDD900, 0x4A3E, 0x11D1,{ 0x84, 0xF4, 0, 0, 0xF8, 0x4, 0x64, 0xE3 } };


VOID __stdcall LogEventCallback(PEVENT_TRACE EventTrace)
{
	if (gWbemServiceList.EventItemList.empty())
	{
		tagEventItem* pItem = new tagEventItem((GUID*)&GUID_PROCEXP_EVENT,
			-1, 0, 0);
		gWbemServiceList.EventItemList.push_back(pItem);
		pItem->SetEventTraceText(L"EventTrace");
		pItem->SetHeaderText(L"Header");
	}
	_bstr_t* pstrFound = NULL;
	BOOL bFound = FALSE;
	for (auto it = gWbemServiceList.EventItemList.begin(); it != gWbemServiceList.EventItemList.end(); it++)
	{
		if (IsEqualGUID( (*it)->guid , EventTrace->Header.Guid) )
		{
			bFound = TRUE;
			pstrFound = &((*it)->strEventTrace);
			break;
		}
	}
	if (!pstrFound)
	{
		pstrFound = QueryEventTraceName(&gWbemServiceList, EventTrace->Header.Guid,
			EventTrace->Header.Class.Type, EventTrace->Header.Class.Version, EventTrace->Header.Class.Level);
		tagEventItem* pItem = new tagEventItem(&EventTrace->Header.Guid,
			EventTrace->Header.Class.Type,
			EventTrace->Header.Class.Version,
			EventTrace->Header.Class.Level);
		pItem->SetEventTraceText(L"Unknown");
		gWbemServiceList.EventItemList.push_back(pItem);
	}



	
}

DWORD WINAPI TraceEventThreadProc(void* p)
{
	LPEVENT_TRACE_PROPERTIES_EX Properties
		= (LPEVENT_TRACE_PROPERTIES_EX)p;
	ULONG	ret = 0;
	EVENT_TRACE_LOGFILEW LogFile = { 0 };
	LogFile.LogFileName = NULL;
	LogFile.Context = 0;
	WCHAR* pszLoggerName = L"PROCEXP TRACE";
	LogFile.BufferCallback = LogBufferCallback;
	if (gdwVersion < WINDOWS_8)
		pszLoggerName = L"NT Kernel Logger";
	LogFile.BuffersRead = 0;
	LogFile.LoggerName = pszLoggerName;
	LogFile.CurrentTime = 0i64;
	LogFile.EventCallback = LogEventCallback;
	LogFile.LogFileMode = PROCESS_TRACE_MODE_RAW_TIMESTAMP | PROCESS_TRACE_MODE_REAL_TIME;

	Properties->TraceHandle = OpenTraceW(&LogFile);
	if (Properties->TraceHandle)
	{
		do 
		{
			ret = ProcessTrace(&Properties->TraceHandle, 1, NULL, NULL);
			if (ret)
				break;
			if (WaitForSingleObject(Properties->EventHandle, 0) == WAIT_TIMEOUT)
			{
				ret = PE_RunTrace(Properties, true);
				Properties->TraceHandle = OpenTraceW(&LogFile);
				if (ret)
					break;
			}
		} while (WaitForSingleObject(Properties->EventHandle,0)==WAIT_TIMEOUT);
	}

	Properties->fTraceStarted = false;
	return 0;
}

void ScanAllThreads()
{
	HANDLE hFound = INVALID_HANDLE_VALUE;
	THREADENTRY32 ThreadEntry = { sizeof(ThreadEntry) };

	hFound = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);
	if (hFound == INVALID_HANDLE_VALUE)
		return;
	if (Thread32First(hFound, &ThreadEntry))
	{
		do 
		{
			///
			/// 每一个线程都有一个对应的所属进程
			gThreadProcessMap[ThreadEntry.th32ThreadID]
				= ThreadEntry.th32OwnerProcessID;
		} while (Thread32Next(hFound,&ThreadEntry));
	}
	CloseHandle(hFound);
}