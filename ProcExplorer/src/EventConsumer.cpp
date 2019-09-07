#include "stdafx.h"
#include "..\include\EventConsumer.h"

typedef map<WCHAR*, EventConsumerDescBase*> CEventConsumerMap;
CEventConsumerMap gEventConsumerMap;

//////////////////////////////////////////////////////////////////////////
void EventConsumerDescBase::AppendDescription(LPCWSTR lpszText, int nLength /* = -1 */, int nPos /* = 0 */)
{
	int nLengthExisting = wcslen(m_pszDescription);
	int nLengthNew = nLength;
	if (nLengthNew > nLengthExisting)
		nLengthNew = nLengthExisting;

}

bool EventConsumerDescBase::GetWorkingDirectory(IWbemClassObject* pClassObject, WCHAR** ppszWorkingDirectory)
{
	WCHAR* psz = GetClassObjectName(pClassObject, L"WorkingDirectory");
	WCHAR* p = *ppszWorkingDirectory;
	*ppszWorkingDirectory = _wcsdup(psz);
	free(p);
	int nLen = wcslen(psz);
	free(psz);
	return nLen > 0;
}


//////////////////////////////////////////////////////////////////////////
CommandLineEventConsumer gCommandLineEventConsumer;
CommandLineEventConsumer::CommandLineEventConsumer()
{
	gEventConsumerMap[L"CommandLineEventConsumer"] = this;
	WCHAR* pszURL = m_pszURL;
	WCHAR* pszDesc = m_pszDescription;
	m_pszURL= _wcsdup(L"http://msdn.microsoft.com/en-us/library/aa389231(v=vs.85).aspx");
	this->m_pszDescription = _wcsdup(L"The CommandLineEventConsumer class starts an arbitrary process in the local system ");
	free(pszDesc);
	free(pszURL);
	AppendDescription(L"language when an event is delivered to it. This class is one of the standard event consumers that WMI provides.");
}


CommandLineEventConsumer::~CommandLineEventConsumer()
{
}

WCHAR* CommandLineEventConsumer::GetExecutablePath(IWbemClassObject* pClassObject)
{
	WCHAR* res = GetClassObjectName(pClassObject, L"CommndLineTemplate");
	int len = wcslen(res);
	if (!len)
	{
		free(res);
		res = GetClassObjectName(pClassObject, L"ExecutablePath");
	}
	return res;
}

//////////////////////////////////////////////////////////////////////////
ActiveScriptEventConsumer::ActiveScriptEventConsumer()
{
	gEventConsumerMap[L"ActiveScriptEventConsumer"] = this;
	WCHAR* pszURL = m_pszURL;
	WCHAR* pszDesc = m_pszDescription;
	m_pszURL = _wcsdup(L"http://msdn.microsoft.com/en-us/library/aa384749(v=vs.85).aspx");
	this->m_pszDescription = _wcsdup(L"The ActiveScriptEventConsumer class runs a predefined script in an arbitrary scripting ");
	free(pszDesc);
	free(pszURL);

	AppendDescription(L"language when an event is delivered to it.This class is one of the standard event consumers that WMI provides.");
}

ActiveScriptEventConsumer::~ActiveScriptEventConsumer()
{

}

ActiveScriptEventConsumer gActiveScriptEventConsumer;
