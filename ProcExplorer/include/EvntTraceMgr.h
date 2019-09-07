#ifndef __EVENTTRACEMGR_H__
#define __EVENTTRACEMGR_H__

#pragma once

typedef ULONG(WINAPI* LPFN_StartTraceW)(PTRACEHANDLE TraceHandle, LPCWSTR InstanceName, PEVENT_TRACE_PROPERTIES Properties);
typedef TRACEHANDLE(WINAPI* LPFN_OpenTraceW)(PEVENT_TRACE_LOGFILEW  LogFile);
typedef ULONG(WINAPI *LPFN_FlushTraceW)(TRACEHANDLE TraceHandle, LPCWSTR InstanceName, PEVENT_TRACE_PROPERTIES Properties);
typedef ULONG(WINAPI *LPFN_ProcessTrace)(PTRACEHANDLE TraceHandle, ULONG HandleCount, LPFILETIME StartTime, LPFILETIME EndTime);
typedef ULONG(WINAPI *LPFN_ControlTraceW)(TRACEHANDLE TraceHandle, LPCWSTR InstanceName, PEVENT_TRACE_PROPERTIES Properties, ULONG ControlCode);
extern LPFN_ControlTraceW gpfnControlTraceW;
extern LPFN_StartTraceW gpfnStartTraceW;
extern LPFN_OpenTraceW gpfnOpenTraceW;
extern LPFN_FlushTraceW gpfnFlushTraceW;
extern LPFN_ProcessTrace gpfnProcessTrace;


//////////////////////////////////////////////////////////////////////////
//
class CEventTraceMgr : public EVENT_TRACE_PROPERTIES
{
public:
	CEventTraceMgr();


	WCHAR			m_LoggerName[_MAX_PATH];
	WCHAR			m_LogFileName[_MAX_PATH];

	TRACEHANDLE		m_TraceHandle;

	bool			m_bFuncsLoaded;
	HANDLE			m_hEvent;
	HANDLE			m_hThread;

	TRACEHANDLE		m_LogHandle;
	bool			m_bStarted;

	HFONT			m_hFont;

	BOOL Load(BOOL flags = TRUE);

	static DWORD WINAPI TraceEventThreadProc(void* p);
	DWORD RunLog();
	static ULONG WINAPI BufferCallback(PEVENT_TRACE_LOGFILE LogFile);
	static void WINAPI EventRecordCallback(PEVENT_RECORD EventRecord);
	void ScanAllThreads();
};

extern CEventTraceMgr gEventTraceMgr;
extern UINT GetEventNameID(WCHAR* lpszName);

#endif //__EVENTTRACEMGR_H__