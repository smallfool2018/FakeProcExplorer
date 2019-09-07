#ifndef __EVENTCONSUMER_H__
#define __EVENTCONSUMER_H__
#pragma once

//////////////////////////////////////////////////////////////////////////
class EventConsumerDescBase
{
public:
	EventConsumerDescBase()
		:m_pszDescription(NULL)
		,m_pszURL(NULL)
	{
		m_pszDescription = new WCHAR[1];
		m_pszURL = new WCHAR[1];
	}
	virtual ~EventConsumerDescBase()
	{
		free(m_pszURL);
		free(m_pszDescription);
	}
	virtual WCHAR* GetExecutablePath(IWbemClassObject* pClassObject) { return TEXT(""); }

	virtual bool GetWorkingDirectory(IWbemClassObject* pClassObject, WCHAR** ppszWorkingDirectory);

public:
	WCHAR* m_pszDescription;
	WCHAR* m_pszURL;
protected:
	void AppendDescription(LPCWSTR lpszText, int nLength = -1, int nPos = 0);
};

//////////////////////////////////////////////////////////////////////////
class CommandLineEventConsumer : public EventConsumerDescBase
{
public:
	CommandLineEventConsumer();
	virtual WCHAR* GetExecutablePath(IWbemClassObject* pClassObject);
	virtual ~CommandLineEventConsumer();
};
extern CommandLineEventConsumer gCommandLineEventConsumer;

//////////////////////////////////////////////////////////////////////////
class ActiveScriptEventConsumer : public EventConsumerDescBase
{
public:
	ActiveScriptEventConsumer();
	virtual WCHAR* GetExecutablePath(IWbemClassObject* pClassObject)
	{
		return _wcsdup(gpszTargetName);
	}
	virtual ~ActiveScriptEventConsumer();
};

extern ActiveScriptEventConsumer gActiveScriptEventConsumer;


#endif //__EVENTCONSUMER_H__