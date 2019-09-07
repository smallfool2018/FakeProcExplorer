#ifndef __PROCESS_H__
#define __PROCESS_H__
#pragma once
#include "TreeListData.h"

class Runtime;

//////////////////////////////////////////////////////////////////////////
//0x18=
class Process :	public CTreeListData
{
public:
	Process();
	virtual ~Process();

	typedef vector<Runtime*> CRuntimeArray;

	void AddRuntime(DWORD dwProcessID, WORD wID);

	static int CleanMemory();
public:
	DWORD			m_ProcessId;
	CString			m_strText;
	CRuntimeArray	m_arrRuntimes;
};
//////////////////////////////////////////////////////////////////////////
//0x38=
class Runtime :
	public CTreeListData
{
public:
	Runtime(DWORD dwProcessID, WORD wID);
	virtual ~Runtime();

public:
	CString m_str1;
	CString m_str2;
	CString m_str3;
	CString m_str4;
	WORD	m_wID;
	CString m_strVersion;
	DWORD	m_dwProcessID;


};

//////////////////////////////////////////////////////////////////////////
//0x28=
class AppDomain :
	public CTreeListData
{
public:
	AppDomain();
	virtual ~AppDomain();

public:
};

//////////////////////////////////////////////////////////////////////////
//0x20=
class Assembly :
	public CTreeListData
{
public:
	Assembly();
	virtual ~Assembly();

public:
};



#endif //__PROCESS_H__
