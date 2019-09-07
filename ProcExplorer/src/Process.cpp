#include "stdafx.h"
#include "..\include\Process.h"


Process::Process()
{
}


Process::~Process()
{
}

void Process::AddRuntime(DWORD dwProcessID, WORD wID)
{
	Runtime *pRuntime = new Runtime(dwProcessID, wID);
	m_arrRuntimes.push_back(pRuntime);
}

int Process::CleanMemory()
{
	LVITEMW Item = { 0 };
	int nCurItem = ListView_GetNextItem(ghWndTreeListView, -1, LVFI_STRING);
	if (nCurItem == -1)
	{
		ErrorMsgBox(ghWndTreeListView, L"No process selected");
	}
	else
	{
		Item.mask = LVIF_PARAM;
		Item.iItem = nCurItem;
		Item.iSubItem = 0;

		if (ListView_GetItem(ghWndTreeListView, &Item))
		{
			tagTREEVIEWITEMPARAM* pItemParam = (tagTREEVIEWITEMPARAM*)Item.lParam;
			HANDLE ProcessHandle = OpenProcess(PROCESS_SET_QUOTA, 0, pItemParam->dwProcessId);
			if (ProcessHandle
				&&SetProcessWorkingSetSize(ProcessHandle, 0xFFFFFFFF, 0xFFFFFFFF))
			{
				SetEvent(ghRefreshEventHandle);
			}
			else
			{
				ReportMsg(L"Unable to trim process working set", ghMainWnd);
			}
			if (ProcessHandle)
			{
				CloseHandle(ProcessHandle);
				return 0;
			}
		}
	}
	return 0;
}

//////////////////////////////////////////////////////////////////////////
//
Runtime::Runtime(DWORD dwProcessID, WORD wID)
	:m_wID(wID)
	,m_dwProcessID(dwProcessID)
{
}


Runtime::~Runtime()
{
}


//////////////////////////////////////////////////////////////////////////
//
AppDomain::AppDomain()
{
	
}


AppDomain::~AppDomain()
{
}


//////////////////////////////////////////////////////////////////////////
//
Assembly::Assembly()
{
}


Assembly::~Assembly()
{
}