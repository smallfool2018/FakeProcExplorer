#include "stdafx.h"
#include "../ProcExplorer.h"

LPFN_ControlTraceW gpfnControlTraceW = NULL;
LPFN_StartTraceW gpfnStartTraceW = NULL;
LPFN_OpenTraceW gpfnOpenTraceW = NULL;
LPFN_FlushTraceW gpfnFlushTraceW = NULL;
LPFN_ProcessTrace gpfnProcessTrace = NULL;

CEventTraceMgr gEventTraceMgr

typedef map<DWORD, DWORD> CThreadIdMap;
CThreadIdMap gThreadIdMap;

tagMsgItem gEventNameItem[56] = { 0 };
tagMsgItem gEventCmdItem[24] = { 0 };

UINT GetEventNameID(WCHAR* lpszName)
{
	for (int i = 0; i < sizeof(gEventNameItem) / sizeof(*gEventNameItem); i++)
	{
		if (!wcscmp(gEventNameItem[i], lpszName))
			return gEventNameItem[i].nID;
	}
	return 0;
}

//////////////////////////////////////////////////////////////////////////
CEventTraceMgr::CEventTraceMgr()
{
	this->Wnode.BufferSize = 1200;
	this->Wnode.Flags = WNODE_FLAG_TRACED_GUID;
	this->FlushTimer = 1;

	//Query performance counter (QPC).
	this->Wnode.ClientContext = 1;
	this->LogFileMode = EVENT_TRACE_SYSTEM_LOGGER_MODE;
	if (gdwVersion < 3)
		this->LogFileMode |= EVENT_TRACE_REAL_TIME_MODE;
	CopyMemory(&this->Wnode.Guid, &SystemTraceControlGuid, sizeof(GUID));
	this->LogFileNameOffset = 640;
	this->LoggerNameOffset = 120;

	if (gdwVersion < 3)
		wcscpy_s(m_LoggerName, _MAX_PATH, L"NT Kernel Logger");
	else
		wcscpy_s(m_LoggerName, _MAX_PATH, L"PROCEXP TRACE");

	wcscpy_s(m_LogFileName, _MAX_PATH, gpszTargetName);

	EnableFlags = EVENT_TRACE_FLAG_ALPC | EVENT_TRACE_FLAG_DISK_IO;
	if (gdwVersion >= 3)
		EnableFlags |= EVENT_TRACE_FLAG_THREAD;
}

BOOL CEventTraceMgr::Load(BOOL flags /* = TRUE */)
{
	if (m_bStarted)
		return FALSE;
	if (!m_bFuncsLoaded)
	{
		HMODULE hModule = LoadLibraryW(L"advapi32.dll");
		gpfnStartTraceW = (LPFN_StartTraceW)::GetProcAddress(hModule, "StartTraceW");
		gpfnControlTraceW = (LPFN_ControlTraceW)::GetProcAddress(hModule, "ControlTraceW");
		gpfnOpenTraceW = (LPFN_OpenTraceW)GetProcAddress(hModule, "OpenTraceW");
		gpfnProcessTrace = (LPFN_ProcessTrace)GetProcAddress(hModule, "ProcessTrace");
		m_bFuncsLoaded = true;
	}

	if (!gpfnStartTraceW)
		return TRUE;

	if (flags)
	{
		ULONG ret = gpfnStartTraceW(&m_TraceHandle, m_LoggerName, this);
		if (!ret || ret == ERROR_ALIAS_EXISTS)
		{
			m_bStarted = true;
			ret = 0;
			DWORD ThreadId = 0;
			m_hThread = CreateThread(NULL, 0, TraceEventThreadProc, (void*)this, 0, &dwThreadId);
			if (gdwVersion >= 3)
			{
				ScanAllThreads();
				return 0;
			}
		}
		return ret;
	}
	else
	{
		SetEvent(m_hEvent);
		ULONG ret = gpfnControlTraceW(m_TraceHandle, m_LoggerName, this, TRUE);
		WaitForSingleObject(m_hThread, INFINITE);
		CloseHandle(m_hThread);
		m_hThread = NULL;
		ResetEvent(m_hEvent);
		return ret;
	}

	return TRUE;
}

DWORD WINAPI CEventTraceMgr::TraceEventThreadProc(void* p)
{
	CEventTraceMgr* pThis = (CEventTraceMgr*)p;
	return pThis->RunLog();
}

ULONG WINAPI CEventTraceMgr::BufferCallback(PEVENT_TRACE_LOGFILE LogFile)
{
	return 1;
}
void WINAPI CEventTraceMgr::EventRecordCallback(PEVENT_RECORD EventRecord)
{

}


DWORD CEventTraceMgr::RunLog()
{
	DWORD	ret = 0;
	EVENT_TRACE_LOGFILE LogFile;
	ZeroMemory(&LogFile, sizeof(LogFile));
	LogFile.BuffersRead = 0;
	LogFile.LoggerName = gdwVersion < 3 ? L"NT Kernel Logger" : L"PROCEXP TRACE";
	LogFile.DUMMYUNIONNAME2.EventRecordCallback = CEventTraceMgr::EventRecordCallback;
	LogFile.BufferCallback = CEventTraceMgr::BufferCallback;
	LogFile.DUMMYUNIONNAME.ProcessTraceMode = PROCESS_TRACE_MODE_RAW_TIMESTAMP | PROCESS_TRACE_MODE_REAL_TIME;
	m_LogHandle = gpfnOpenTraceW(&LogFile);
	if (m_LogHandle)
	{
		do
		{
			ret = gpfnProcessTrace(&m_LogHandle, 1, NULL, NULL);
			if (ret)
				break;
			if (WaitForSingleObject(m_hEvent, 0) == WAIT_TIMEOUT)
			{
				ret = this->Load(TRUE);
				m_LogHandle = gpfnOpenTraceW(&LogFile);
				if (ret)
					break;
			}
		} while (WaitForSingleObject(m_hEvent, 0) == WAIT_TIMEOUT);
	}
	else
	{
		ret = -1;
	}
	this->m_bStarted = false;
	return ret;
}

void CEventTraceMgr::ScanAllThreads()
{
	THREADENTRY32 ThreadEntry = { 0 };
	HANDLE hFound = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);
	if (hFound != INVALID_HANDLE_VALUE)
	{

		ThreadEntry.dwSize = sizeof(THREADENTRY32);
		if (Thread32First(hFound, &ThreadEntry))
		{
			do 
			{

			} while (Thread32Next(hFound,&ThreadEntry));
		}
		CloseHandle(hFound);
	}
	return;
}