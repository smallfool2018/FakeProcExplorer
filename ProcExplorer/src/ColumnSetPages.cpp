#include "stdafx.h"

#include "../ProcExplorer.h"
#include <prsht.h>

INT_PTR CALLBACK PropColumnSetsForProcess(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK PropColumnSetsForHandles(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK PropColumnSetsForDlls(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK PropColumnSetsForNet(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK PropColumnSetsForStatusBar(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

INT_PTR CALLBACK PropColumnSetsForProcess(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return 0;
}

INT_PTR CALLBACK PropColumnSetsForHandles(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return 0;
}

INT_PTR CALLBACK PropColumnSetsForDlls(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return 0;
}
INT_PTR CALLBACK PropColumnSetsForNet(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return 0;
}

INT_PTR CALLBACK PropColumnSetsForStatusBar(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return 0;
}

struct PE_PROPSHEETPAGEW : public PROPSHEETPAGEW
{
	DWORD	dwValue;
};

extern void UpdateWindowPlacement(HWND hWnd, BOOL fSave);

int Command_SelectColumn(HWND hWnd, UINT nID)
{
	WCHAR szText[256] = { 0 };
	int		nPageIndex = 0;
	int nStartPage = 0;
	PE_PROPSHEETPAGEW	Pages[13];
	
	if (nID == 40041)
	{
		HWND hWndFocus = GetFocus();
		if (hWndFocus == ghWndTreeListView)
			nID = 40015;
		else if (hWndFocus == ghWndDllsListCtrl)
			nID = 40104;
		else if (hWndFocus == ghWndHandlesListCtrl)
			nID = 40106;
	}
	
	ZeroMemory(Pages, sizeof(Pages));
	if (nID == 40015)
		nStartPage = 0;


	Pages[nPageIndex].dwSize = sizeof(PE_PROPSHEETPAGEW);
	Pages[nPageIndex].dwFlags = PSP_USETITLE;
	Pages[nPageIndex].hInstance = ghInstance;
	Pages[nPageIndex].pszTemplate = L"PROCCOLUMNS";
	Pages[nPageIndex].hIcon = NULL;
	Pages[nPageIndex].pfnDlgProc = PropColumnSetsForProcess;
	Pages[nPageIndex].pszTitle = L"Process Image";
	Pages[nPageIndex].pfnCallback = NULL;
	nPageIndex++;

	Pages[nPageIndex].dwSize = sizeof(PE_PROPSHEETPAGEW);
	Pages[nPageIndex].dwFlags = PSP_USETITLE;
	Pages[nPageIndex].hInstance = ghInstance;
	Pages[nPageIndex].pszTemplate = L"PROCPERFCOLUMNS";
	Pages[nPageIndex].hIcon = NULL;
	Pages[nPageIndex].pfnDlgProc = PropColumnSetsForProcess;
	Pages[nPageIndex].pszTitle = L"Process Performance";
	Pages[nPageIndex].lParam = 0;
	Pages[nPageIndex].pfnCallback = NULL;
	nPageIndex++;

	Pages[nPageIndex].dwSize = sizeof(PE_PROPSHEETPAGEW);
	Pages[nPageIndex].dwFlags = PSP_USETITLE;
	Pages[nPageIndex].hInstance = ghInstance;
	Pages[nPageIndex].pszTemplate = L"PROCIOCOLUMNS";
	Pages[nPageIndex].hIcon = NULL;
	Pages[nPageIndex].pfnDlgProc = PropColumnSetsForProcess;
	Pages[nPageIndex].pszTitle = L"Process I/O";
	Pages[nPageIndex].lParam = 0;
	Pages[nPageIndex].pfnCallback = NULL;
	nPageIndex++;

	if (IsBuiltinAdministrative() || gConfig.bETWStandardUserWarning == 1)
	{
		Pages[nPageIndex].dwSize = sizeof(PE_PROPSHEETPAGEW);
		Pages[nPageIndex].dwFlags = PSP_USETITLE;
		Pages[nPageIndex].hInstance = ghInstance;
		Pages[nPageIndex].pszTemplate = L"PROCNETWORKCOLUMNS";
		Pages[nPageIndex].hIcon = NULL;
		Pages[nPageIndex].pfnDlgProc = PropColumnSetsForProcess;
		Pages[nPageIndex].pszTitle = L"Process Network";
		Pages[nPageIndex].lParam = 0;
		Pages[nPageIndex].pfnCallback = NULL;
		nPageIndex++;

		Pages[nPageIndex].dwSize = sizeof(PE_PROPSHEETPAGEW);
		Pages[nPageIndex].dwFlags = PSP_USETITLE;
		Pages[nPageIndex].hInstance = ghInstance;
		Pages[nPageIndex].pszTemplate = L"PROCDISKCOLUMNS";
		Pages[nPageIndex].hIcon = NULL;
		Pages[nPageIndex].pfnDlgProc = PropColumnSetsForProcess;
		Pages[nPageIndex].pszTitle = L"Process Disk";
		Pages[nPageIndex].lParam = 0;
		Pages[nPageIndex].pfnCallback = NULL;
		nPageIndex++;

	}

	Pages[nPageIndex].dwSize = sizeof(PE_PROPSHEETPAGEW);
	Pages[nPageIndex].dwFlags = PSP_USETITLE;
	Pages[nPageIndex].hInstance = ghInstance;
	Pages[nPageIndex].pszTemplate = L"PROCMEMCOLUMNS";
	Pages[nPageIndex].hIcon = NULL;
	Pages[nPageIndex].pfnDlgProc = PropColumnSetsForProcess;
	Pages[nPageIndex].pszTitle = L"Process Memory";
	Pages[nPageIndex].lParam = 0;
	Pages[nPageIndex].pfnCallback = NULL;
	nPageIndex++;


	if (gdwAdapterRuntingTime != 0)
	{
		Pages[nPageIndex].dwSize = sizeof(PE_PROPSHEETPAGEW);
		Pages[nPageIndex].dwFlags = PSP_USETITLE;
		Pages[nPageIndex].hInstance = ghInstance;
		Pages[nPageIndex].pszTemplate = L"PROCGPUCOLUMNS";
		Pages[nPageIndex].hIcon = NULL;
		Pages[nPageIndex].pfnDlgProc = PropColumnSetsForProcess;
		Pages[nPageIndex].pszTitle = L"Process GPU";
		Pages[nPageIndex].lParam = 0;
		Pages[nPageIndex].pfnCallback = NULL;
		nPageIndex++;
	}
	Pages[nPageIndex].lParam = 0;
	Pages[nPageIndex].dwSize = sizeof(PE_PROPSHEETPAGEW);
	Pages[nPageIndex].dwFlags = PSP_USETITLE;
	Pages[nPageIndex].hInstance = ghInstance;
	Pages[nPageIndex].pszTemplate = L"HANDLECOLUMNS";
	Pages[nPageIndex].hIcon = NULL;
	Pages[nPageIndex].pfnDlgProc = PropColumnSetsForHandles;
	Pages[nPageIndex].pszTitle = L"Handle";
	Pages[nPageIndex].pfnCallback = NULL;
	nPageIndex++;
	
	Pages[nPageIndex].dwSize = sizeof(PE_PROPSHEETPAGEW);
	Pages[nPageIndex].dwFlags = PSP_USETITLE;
	Pages[nPageIndex].hInstance = ghInstance;
	Pages[nPageIndex].pszTemplate = L"DLLCOLUMNS";
	Pages[nPageIndex].hIcon = NULL;
	Pages[nPageIndex].pfnDlgProc = PropColumnSetsForDlls;
	Pages[nPageIndex].pszTitle = L"DLL";
	Pages[nPageIndex].lParam = 0;
	Pages[nPageIndex].pfnCallback = NULL;
	nPageIndex++;

	if (gNetClrMemoryPerfInfoLoaded)
	{
		Pages[nPageIndex].dwSize = sizeof(PE_PROPSHEETPAGEW);
		Pages[nPageIndex].dwFlags = PSP_USETITLE;
		Pages[nPageIndex].hInstance = ghInstance;
		Pages[nPageIndex].pszTemplate = L"NETCOLUMNS";
		Pages[nPageIndex].hIcon = NULL;
		Pages[nPageIndex].pfnDlgProc = PropColumnSetsForNet;
		Pages[nPageIndex].pszTitle = L".NET";
		Pages[nPageIndex].lParam = 0;
		Pages[nPageIndex].pfnCallback = NULL;
		nPageIndex++;
	}
	Pages[nPageIndex].dwSize = sizeof(PE_PROPSHEETPAGEW);
	Pages[nPageIndex].dwFlags = PSP_USETITLE;
	Pages[nPageIndex].hInstance = ghInstance;
	Pages[nPageIndex].pszTemplate = L"STATUSBARCOLUMNS";
	Pages[nPageIndex].hIcon = NULL;
	Pages[nPageIndex].pfnDlgProc = PropColumnSetsForStatusBar;
	Pages[nPageIndex].pszTitle = L"Status Bar";
	Pages[nPageIndex].lParam = 0;
	Pages[nPageIndex].pfnCallback = NULL;

	PROPSHEETHEADERW PropSheet = { sizeof(PropSheet) };
	PropSheet.nPages = nPageIndex + 1;
	PropSheet.hwndParent = ghMainWnd;
	PropSheet.nStartPage = 0;
	PropSheet.pfnCallback = NULL;
	wsprintfW(szText, L"Select Columns");
	PropSheet.pszCaption = szText;
	PropSheet.hInstance = ghInstance;
	PropSheet.dwFlags = PSH_NOAPPLYNOW | PSH_PROPSHEETPAGE;
	PropertySheetW(&PropSheet);

	UpdateWindowPlacement(ghMainWnd, TRUE);

	return	0;
}


////int __cdecl Command_SelectColumn(HWND hWnd, signed __int16 uID)
////{
////
////
////	ZeroParam = 0;
////	nID = uID;
////	PropSheet.dwSize = 0;
////	if (uID == 40041)
////	{
////		hWndFocus = GetFocus();
////		if (hWndFocus == ghWndTreeListView)
////		{
////			nID = 40105;
////		}
////		else if (hWndFocus == ghWndDllsListCtrl)
////		{
////			nID = 40104;
////		}
////		else if (hWndFocus == ghWndHandlesListCtrl)
////		{
////			nID = 40106;
////		}
////	}
////	Pages[nPageIndex].dwSize = 0;
////	nStartPage = PropSheet.nStartPage;
////
////	if (nID == 40105)
////		nStartPage = 0;
////
////	PropSheet.nStartPage = nStartPage;
////
////	ghInstance = ghInstance;
////	if (IsBuiltinAdministrative() || gConfig.bETWStandardUserWarning == 1)
////	{
////		nPageIndex_1 = 5;
////
////	}
////	nPageIndex_2 = nPageIndex_1;
////	nPageIndex_3 = nPageIndex_1 + 1;
////	fNoAdapterRuntime = gdwAdapterRuntingTime == 0;
////
////
////	if (nID == 40106)
////		nPageIndex_6 = nPageIndex_3;
////	nPageIndex_5 = nPageIndex_3;
////	nPageIndex_6 = PropSheet.nStartPage;
////	nPageIndex_7 = nPageIndex_3 + 1;
////	nPageIndex_8 = nPageIndex_7;
////
////
////
////	if (nID == 40104)
////		nPageIndex_6 = nPageIndex_7;
////	nPageIndex = nPageIndex_7 + 1;
////
////	nPageIndex_10 = nPageIndex;
////	PropSheet.dwFlags = 0x88;                     // PSH_NOAPPLYNOW| PSH_PROPSHEETPAGE
////	PropSheet.dwSize = sizeof(PROPSHEETHEADERW);
////	PropSheet.hInstance = ghInstance;
////
////	PropSheet.nPages = nPageIndex + 1;
////	PropSheet.ppsp = Pages;
////	if (nID == 40107)
////		nPageIndex_6 = nPageIndex;
////	PropSheet.hwndParent = ghMainWnd;
////	PropSheet.nStartPage = nPageIndex_6;
////	swprintf(Dst, L"Select Columns");
////	PropSheet.pfnCallback = NULL;
////	PropSheet.pszCaption = Dst;
////	PropertySheetW(&PropSheet);
////	if (ZeroParam)
////		UpdateWindowPlacement(ghMainWnd, 1);
////	return 0;
////}