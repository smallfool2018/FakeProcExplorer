#include "stdafx.h"
#include "../ProcExplorer.h"

#include <Dbghelp.h>
#pragma comment(lib,"Dbghelp.lib")

#define WM_SEARCH_RESULTS 0x465

bool gbFindHandleOrDll = true;
//////HWND ghWndNewOwner = NULL;
HANDLE ghEventRefreshSearchResult = NULL;

extern DWORD	gdwTopLastTreeList;
extern HWND	ghSysinfoPropSheetDlg;

extern HWND	ghWndDllsListCtrl;
extern HWND	ghWndHandlesListCtrl;
extern HWND	ghWndTreeListView;
extern HWND	ghWndReBar;
extern HWND	ghWndToolbar;
extern HWND	ghWndCPUGraph;
extern HWND	ghWndMemoryGraph;
extern HWND	ghWndPhysicalMemoryGraph;
extern HWND	ghWndGPUGraph;
extern HWND	ghWndIOGraph;
extern HWND	ghWndNetworkGraph;
extern HWND	ghWndDiskGraph;
extern HWND	ghWndStatusBar;

extern DWORD	gwStatusBarCount;



HWND ghFindDlg = NULL;
HWND ghWndThreadStack = NULL;
HWND ghListResultFound = NULL;


WCHAR gszStringToSearch[256] = { 0 };
WCHAR gszStringSearchLast[256] = { 0 };

RECT  gRectOfFindDlg = { 0 };

bool  gbSearching = false;

HANDLE ghSearchThread = NULL;



DWORD WINAPI SearchThreadProc(PVOID p);

INT_PTR CALLBACK DlgFind(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam);

//////////////////////////////////////////////////////////////////////////
//
//	ShowFindDialog 显示搜索对话框
//
//	nID:
//
//	返回值:
//	
//////////////////////////////////////////////////////////////////////////
INT_PTR CALLBACK ShowFindDialog(int, WORD nID)
{
	gbFindHandleOrDll = nID == IDM_FIND_HANDLE_OR_DLL;
	if (ghFindDlg)
	{
		ShowWindow(ghFindDlg, SW_SHOW);
		SetFocus(ghFindDlg);
	}
	else
	{
		ghFindDlg = CreateDialogParamW(ghInstance, MAKEINTRESOURCEW(IDD_SEARCH), ghMainWnd, DlgFind, (LPARAM)ghFindDlg);
	}
	return 0;
}

//////////////////////////////////////////////////////////////////////////
//
//	DlgFind
//
//
//	返回值:
//	
//////////////////////////////////////////////////////////////////////////
INT_PTR CALLBACK DlgFind(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{

	return 0;
}

//////////////////////////////////////////////////////////////////////////
//
//	SearchThreadProc
//
//
//	返回值:
//	
//////////////////////////////////////////////////////////////////////////
DWORD WINAPI SearchThreadProc(PVOID p)
{

	return 0;
}


//////////////////////////////////////////////////////////////////////////
//
//
//
//
//
//
//////////////////////////////////////////////////////////////////////////
LRESULT CALLBACK Proxy_ListResultFoundWndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_KEYDOWN:
	{
		LVM_SETITEMSTATE;
		HWND hWndNow = ghWndTreeListView;
		UINT nKey = LOWORD(wParam);
		switch (nKey)
		{
		case VK_TAB:
		{
			TCM_INSERTITEM;
			if (hWnd == hWndNow)
			{
				hWndNow = ghWndDllsListCtrl;
				if (gConfig.bShowDllView)
					hWndNow = ghWndHandlesListCtrl;
			}

			int nNextItem = SendMessage(hWndNow, LVM_GETNEXTITEM, (WPARAM)-1, (LPARAM)2);
			if (nNextItem == -1)
				nNextItem = 0;
			SetFocus(hWndNow);
			LVITEM item = { 0 };
			item.stateMask = LVIF_TEXT|LVIF_IMAGE;
			item.state = LVIS_SELECTED | LVIS_FOCUSED;
			SendMessage(hWndNow, LVM_SETITEMSTATE, nNextItem, (LPARAM)&item);
			return 0;
		}
		break;
		case VK_RETURN:
		case VK_END:
		case VK_HOME:
			break;
		default:
			break;
		}
	}
		break;
	}
	return 0;
}

bool gbWindowFinding = false;
HCURSOR ghFindCursor = NULL;
HWND ghWndHungWindow = NULL;

typedef HWND(WINAPI* LPFN_HungWindowFromGhostWindow)(HWND);

LPFN_HungWindowFromGhostWindow gpfn_HungWindowFromGhostWindow = NULL;

//////////////////////////////////////////////////////////////////////////
///
///	SearchWindow:查找指定的窗口所对应的应用程序
///
///
//////////////////////////////////////////////////////////////////////////
int SearchWindow(HWND hWnd)
{
	HWND hWndHung = NULL;
	DWORD dwProcessId = 0;
	LVITEMW Item = { 0 };
	tagDLLLISTITEMPARAM *pItemParam = NULL;
	WCHAR	szBuffer[_MAX_PATH] = { 0 };

	if (gbWindowFinding)
	{
		SetCursor(ghFindCursor);
		ReleaseCapture();
		gbWindowFinding = 0;
		SendMessageW(ghWndToolbar, TB_PRESSBUTTON, IDM_FIND_PROCESS_BY_WINDOW, 0);
		SetWindowPos(hWnd, (gConfig.bAlwaysOntop) ? HWND_TOPMOST : HWND_TOP, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
		if (ghWndHungWindow)
		{
			DrawHungWindow(ghWndHungWindow);
			if (!gpfn_HungWindowFromGhostWindow || (hWndHung = gpfn_HungWindowFromGhostWindow(ghWndHungWindow)) == 0)
				hWndHung = ghWndHungWindow;
			GetWindowThreadProcessId(hWndHung, &dwProcessId);
			int nCount = SendMessageW(ghWndTreeListView, LVM_GETITEMCOUNT, 0, 0);
			int nIndex = 0;
			if (nCount)
			{
				while (1)
				{
					Item.mask = LVIF_PARAM;
					Item.iItem = nIndex;
					Item.iSubItem = 0;
					SendMessageW(ghWndTreeListView, LVM_GETITEMW, 0, (LPARAM)&Item);
					tagDLLLISTITEMPARAM *pItemParam = (tagDLLLISTITEMPARAM *)Item.lParam;

					if (pItemParam->dwProcessId == dwProcessId)
						break;
					if (++nIndex >= nCount)
						goto __BREAK;
				}
				Item.mask = LVIF_STATE;
				Item.stateMask = LVIS_SELECTED;
				Item.state = LVIS_SELECTED;
				SendMessageW(ghWndTreeListView, LVM_SETITEMW, 0,(LPARAM) &Item);
				SendMessageW(ghWndTreeListView, LVM_ENSUREVISIBLE, nIndex, 0);
				SetFocus(ghWndTreeListView);
			}
		__BREAK:
			if (nIndex == nCount)
			{
				tagTREEVIEWITEMPARAM*         pTreeViewListItemParam = gpTreeViewListItemParam;
				if (pTreeViewListItemParam)
				{
					while (pTreeViewListItemParam->dwProcessId != dwProcessId)
					{
						pTreeViewListItemParam = pTreeViewListItemParam->m_Prev;
						if (!pTreeViewListItemParam)
							goto __ReportError;
					}
					wsprintfW(
						szBuffer,
						L"The owning process is %s (process ID %d), which is not currently visible in the process list.",
						pTreeViewListItemParam->szProcessName2,
						pTreeViewListItemParam->dwProcessId);
					MessageBoxW(ghWndTreeListView, szBuffer, L"Process Explorer Error", MB_ICONASTERISK);
				}
				else
				{
				__ReportError:
					MessageBoxW(
						ghWndTreeListView,
						L"Unable to find the window's owning process in the current process list",
						L"Process Explorer Error",
						MB_ICONERROR);
				}
			}
		}
		return 0;
	}
	else
	{
		SetWindowPos(hWnd, HWND_BOTTOM, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
		SetWindowPos(hWnd, HWND_BOTTOM, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
		ghFindCursor = SetCursor(ghFindCursor);
		SetCapture(hWnd);
		gbWindowFinding = true;
		ghWndHungWindow = NULL;
	}
	return 0;
}

BOOL DrawHungWindow(HWND hWnd)
{
	RECT rcWindow;
	int nWidth = 3 * GetSystemMetrics(SM_CXBORDER);
	HDC hDCWindow = GetWindowDC(hWnd);
	GetWindowRect(hWnd, &rcWindow);
	int hDC = SaveDC(hDCWindow);
	SetROP2(hDCWindow, R2_NOT);
	HPEN hPen = CreatePen(PS_INSIDEFRAME, nWidth, 0);
	SelectObject(hDCWindow, hPen);
	HBRUSH hBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
	SelectObject(hDCWindow, hBrush);
	Rectangle(hDCWindow, 0, 0, rcWindow.right - rcWindow.left, rcWindow.bottom - rcWindow.top);
	RestoreDC(hDCWindow, hDC);
	ReleaseDC(hWnd, hDCWindow);
	return DeleteObject(hPen);
}
