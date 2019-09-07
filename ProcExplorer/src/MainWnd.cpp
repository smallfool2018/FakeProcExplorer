#include "stdafx.h"
#include "../ProcExplorer.h"
#include "../include/RegSettings.h"
#include "../include/MainWnd.h"


#include <Dbghelp.h>
#pragma comment(lib,"Dbghelp.lib")

HINSTANCE		ghInstance = NULL;
DWORD			gdwVersion = NULL;
WCHAR			gszMainClassName[12] = { 0 };
WCHAR			gszMainWindowName[40] = { 0 };


WCHAR*			gszCmdLine = NULL;

RECT			gMainWndRect = { 0 };
HWND			ghMainWnd = NULL;


DWORD			gdwTopLastTreeList = 0L;
HWND			ghSysinfoPropSheetDlg = NULL;


HWND			ghWndDllsListCtrl = NULL;
HWND				ghWndHandlesListCtrl = NULL;
HWND			ghWndTreeListView = NULL;
HWND				ghWndReBar = NULL;
HWND			ghWndToolbar = NULL;
HWND			ghWndCPUGraph = NULL;
HWND			ghWndMemoryGraph = NULL;
HWND			ghWndPhysicalMemoryGraph = NULL;
HWND			ghWndGPUGraph = NULL;
HWND			ghWndIOGraph = NULL;
HWND			ghWndNetworkGraph = NULL;
HWND			ghWndDiskGraph = NULL;
HWND			ghWndStatusBar = NULL;

HWND			ghWndFocusedLast = NULL;


DWORD			gwStatusBarCount = 0;
DWORD			gdwTickCountSetFocusLast = 0;

PSYSTEMHANDLEINFO gpSystemHandleInfo = NULL;
PSYSTEMHANDLEINFO gpSystemHandleInfo2 = NULL;
PSYSTEMHANDLEINFO gpSystemHandleInfo3 = NULL;
DWORD			gdwSystemHandleInfoLength;
bool			gbSupportExtendedSystemHandleInformation = false;
bool			gbProcessIdToSessionIdValid = false;
SC_HANDLE		ghSCManagerHandle	= NULL;

CGraphData*		gpGraphInfoOfMemory = NULL;
CGraphData*		gpGraphInfoOfCPU = NULL;
CGraphData*		gpGraphInfoOfGPU = NULL;
CGraphData*		gpGraphInfoOfSystemMemory = NULL;
CGraphData*		gpGraphInfoOfDedicatedMemory = NULL;
CGraphData*		gpGraphInfoOfPhysicalMemory = NULL;

_SYSTEM_PROCESS_INFORMATION*	gpSystemProcessInfo = NULL;
ULONG			gnSystemProcessInfoLength = NULL;


_SYSTEM_PROCESSOR_PERFORMANCE_INFORMATION*	gpSystemPerformanceInfo = NULL;
_SYSTEM_INTERRUPT_INFORMATION*	gpSystemInterruptInfo = NULL;
_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION*	gpSystemProcessorCycleTimeInfo = NULL;

PSYSTEM_PROCESS_INFORMATION gpSystemProcessInfoLast = NULL;
ULONG			gnSystemProcessInfoLengthLast = 0;
FILETIME		gTimeQuerySystemInfo = { 0 };
FILETIME		gTimeQuerySystemInfoLast = { 0 };

CGraphData*		gpGraphData = NULL;

BOOL	InitDrawEngine();
BOOL	OnBeforeInit();
HCURSOR ghWaitCursor = NULL;
BOOL	gbHide = FALSE;
BOOL	gbMainWndMinimized = FALSE;
bool	gbMainWndMinimized1 = false;

INIT_DEFINE(LockWorkStation);
INIT_DEFINE(SetSuspendState);

HMENU	ghUserPopupMenuHandle = NULL;
WCHAR	gszMainTitle[_MAX_PATH] = { 0 };
COLORREF gColorCustomized[16] = { 0 };
WCHAR*	gpszAuthInfo = NULL;
CGraphData** gppGraphInfo = NULL;

PSYSTEM_LOGICAL_PROCESSOR_INFORMATION gpSystemLogicalProcessorInfo = NULL;
DWORD	gdwLogicalProcessorInfoItemCount = 0;;
HMENU	ghDllsMenuPopup = NULL;
HMENU	ghHandlesMenuPopup = NULL;
bool	gbLaunchDepends = false;
WCHAR	gszApplicationName[_MAX_PATH] = { 0 };
WCHAR	gszAeDebuggerPath[_MAX_PATH] = { 0 };
int		gnToolbarHeight = 0;
HCURSOR ghSplitterCursor = NULL;
HCURSOR ghResizeCursor = NULL;
HANDLE	ghSystemInfoSheetThreadEvent = NULL;
RECT	gRectWindow = { 0 };
RECT	gRectPane = { 0 };
HANDLE	ghRefreshEventHandle = NULL;
HANDLE	ghEvent2 = NULL;
HANDLE	ghExitEventHandle = NULL;
HANDLE	ghTimerRefreshEvent = NULL;	///定时刷新事件?
HANDLE	ghTimerRefreshProcPageEventHandle = NULL;
HANDLE	ghEvent6 = NULL;
HANDLE	ghBackupRefreshThreadHandle = NULL;
DWORD	gdwAdapterRuntingTime = 0;
DWORD	gdwVirtualScreenWidth = 0;
BOOL	gbDbghelpModuleLoaded = FALSE;
UINT	gdwRefreshMenuIDLast = 0;



BOOL	gbProcessDEPEnabled = FALSE;
UINT	gdwComdlg_FindReplaceMessageID = 0;
DWORD	gdwMenuItemPosLast = 0;
HMENU	ghPriorityPopupMenuHandle = NULL;
DWORD	gdwMenuItemCountAppendedInRuntime = 0;
DWORD	gdwValue_4F10B8[] = { (DWORD)-2,(DWORD)-2,(DWORD)-1 };
HWND	ghWndSysinfoPropSheet = NULL;
DWORD	gdwRefreshCount = 0;
bool	gbETWFlagsInProcPropSheet = false;
DWORD	gdwRefresTickCountLast = 0;

static MSGFUNC gWindowMsgFunc[] =
{
	{ WM_COMMAND,&CMainWnd::HandleCommand },
	{ WM_PAINT,&CMainWnd::HandlePaint },
	{ WM_SIZE,&CMainWnd::HandleSize },
	{ WM_LBUTTONDOWN,&CMainWnd::HandleLBtnDown },

	{ WM_LBUTTONUP,&CMainWnd::HandleLBtnUp },
	{ WM_MOUSEMOVE,&CMainWnd::HandleMouseMove },
	{ WM_DRAWITEM,&CMainWnd::HandleDrawItem },
	{ WM_GETMINMAXINFO,&CMainWnd::HandleGetMinmaxInfo },

	{ WM_NOTIFY,&CMainWnd::HandleNotify },
	{ WM_MEASUREITEM,&CMainWnd::HandleMeasureItem },
	{ WM_CREATE,&CMainWnd::HandleCreate },
	{ WM_CLOSE,&CMainWnd::HandleClose },

	{ WM_ENDSESSION,&CMainWnd::HandleEndSession },
	{ WM_DESTROY,&CMainWnd::HandleDestroy },
	{ WM_SETFOCUS,&CMainWnd::HandleSetFocus },
	{ WM_KILLFOCUS,&CMainWnd::HandleKillFocus },

	{ WM_TREEVIEW_SORT,&CMainWnd::HandleTreeViewSort },
	{ WM_NOTIFY_TRAYICON,&CMainWnd::HandleTrayIcon },
	{ WM_SYSCOMMAND,&CMainWnd::HandleSysCommand },
	{ WM_MSG_7EB,&CMainWnd::HandleMsg7EB },

	{ WM_MSG_7ED,&CMainWnd::HandleMsg7ED },
	{ WM_MSG_7EF,&CMainWnd::HandleMsg7EF },
	{ WM_MSG_7F8,&CMainWnd::HandleMsg7F8 },
	{ WM_MSG_7F0,&CMainWnd::HandleMsg7F0 },

	{ WM_MSG_7EE,&CMainWnd::HandleMsg7EE },
	{ WM_MSG_7F6,&CMainWnd::HandleMsg7F6 },
	{ WM_CONTEXTMENU,&CMainWnd::HandleContextMenu },
	{ WM_INITMENUPOPUP,&CMainWnd::HandleInitMenuPopup },

	{ WM_MENUCOMMAND,&CMainWnd::HandleMenuCommand },
	{ WM_COPYDATA,&CMainWnd::HandleCopyData },
	{ WM_MSG_7F2,&CMainWnd::HandleMsg7F2 },
	{ WM_MSG_7F3,&CMainWnd::HandleMsg7F3 },

	{ WM_DEVICECHANGE,&CMainWnd::HandlePaint },
	{ WM_MSG_7F9,&CMainWnd::HandleCreate },

};
MSGHANDLER gMsgHandler = { sizeof(gWindowMsgFunc) / sizeof(*gWindowMsgFunc),gWindowMsgFunc,MSG_Windows };

void ShowSymbolConfigWarning(HWND hWnd);


BOOL IsProcessDEPEnabled();
BOOL ReplaceMenuIconFromStockIcon(HMENU hMenu, UINT nItem);
extern BOOL InitAdapterList(__int64* dbMinSegments, __int64* dbNbSegments);

//////////////////////////////////////////////////////////////////////////
//	
//
//
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
///
///	InitMainWnd 创建主窗口
///
///
///
///
///
//////////////////////////////////////////////////////////////////////////
BOOL InitMainWnd(HINSTANCE hInst, int nCmdShow)
{
	LoadStringW(hInst, IDS_MAINCLASSNAME, gszMainClassName, sizeof(gszMainClassName)/sizeof(*gszMainClassName));
	LoadStringW(hInst, IDS_MAINWINDOWNAME, gszMainWindowName, sizeof(gszMainWindowName) / sizeof(*gszMainWindowName));

	ghInstance = hInst;

	InitDrawEngine();

	if (gConfig.bAllOneInstance)
	{
		HANDLE hEvent = OpenEvent(SYNCHRONIZE, FALSE, TEXT("ProcessExplorerElevating"));
		if (hEvent)
		{
			CloseHandle(hEvent);
		}
		else
		{
			HWND hWnd = FindWindow(gszMainClassName, NULL);
			if (hWnd != NULL)
			{
				PostMessage(hWnd, WM_MSG_7F2, 0, 0);
				return 0;
			}
		}
	}

	if (!OnBeforeInit())
	{
		return FALSE;
	}

	ghWaitCursor = LoadCursor(NULL, IDC_WAIT);
	WNDCLASSEX wc = { sizeof(wc) };
	wc.lpfnWndProc = CMainWnd::MainWndProc;
	wc.hInstance = hInst;
	wc.lpszMenuName = MAKEINTRESOURCE(IDC_PROCEXPLORER);
	wc.hIcon = LoadIcon(hInst, MAKEINTRESOURCE(IDI_PROCEXPLORER));
	wc.lpszClassName = gszMainClassName;
	///wc.hIconSm = (HICON)LoadImage(hInst, MAKEINTRESOURCE(IDC_PROCEXPLORER), GetSystemMetrics(SM_CXSMICON), GetSystemMetrics(SM_CYSMICON), 0);
	if (!RegisterClassEx(&wc) )
		//|| !RegisterClass((WNDCLASS*)&wc.style))
		return FALSE;

	wc.cbSize = sizeof(wc);
	wc.lpfnWndProc = CGraphWnd::ChartWndProc;
	wc.hInstance = hInst;
	wc.hbrBackground = (HBRUSH)CreateSolidBrush((COLORREF)-1);
	wc.lpszClassName = TEXT("CpuGraphClassChart");
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	RegisterClassEx(&wc);

	wc.cbSize = sizeof(wc);
	wc.lpfnWndProc = CGraphWnd::GraphWndProc;
	wc.hInstance = hInst;
	wc.hbrBackground = (HBRUSH)CreateSolidBrush(gConfig.ColorGraphBk);
	wc.lpszClassName = TEXT("CpuGraphClassGraph");
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	RegisterClassEx(&wc);

	HWND hMainWnd = CreateWindowEx(0,
		gszMainClassName,
		TEXT("Process Explorer - Sysinternals: www.sysinternals.com"),
		WS_OVERLAPPEDWINDOW,
		0,
		0,
		780,
		550,
		0,
		NULL,
		hInst,
		NULL);
	if (!hMainWnd)
		return FALSE;

	if (gConfig.WindowPlacement[0].length)
	{
		int nCmdShowType = gConfig.WindowPlacement[0].showCmd;
		if (gConfig.WindowPlacement[0].showCmd == SW_MINIMIZE)
			nCmdShowType = SW_SHOWNORMAL;
		if (gbHide)
			nCmdShowType = SW_HIDE;
		gConfig.WindowPlacement[0].showCmd = nCmdShowType;
		int nScreenWidth = gcxFullScreen;
		if (!nScreenWidth)
			nScreenWidth = gcxFullScreen;
		int nScreenHeight = gcyFullScreen;
		if (!nScreenHeight)
			nScreenHeight = gcyFullScreen;
		int left = gConfig.WindowPlacement[0].rcNormalPosition.left;
		int right = gConfig.WindowPlacement[0].rcNormalPosition.right;
		if (gConfig.WindowPlacement[0].rcNormalPosition.left >= nScreenWidth - 10)
			left = 100;
		gConfig.WindowPlacement[0].rcNormalPosition.left = left;
		int top = gConfig.WindowPlacement[0].rcNormalPosition.top;
		if (gConfig.WindowPlacement[0].rcNormalPosition.right > nScreenWidth)
			right = nScreenWidth;
		gConfig.WindowPlacement[0].rcNormalPosition.right = right;
		if (gConfig.WindowPlacement[0].rcNormalPosition.top >= nScreenHeight - 10)
			top = 100;
		gConfig.WindowPlacement[0].rcNormalPosition.top = top;
		if (nCmdShow == SW_SHOWMINNOACTIVE)
		{
			if (gConfig.bHideWhenMinimized)
				gConfig.WindowPlacement[0].showCmd = SW_HIDE;
		}

		SetWindowPlacement(hMainWnd, &gConfig.WindowPlacement[0]);
	}
	else
	{
		int nCmdShow = SW_SHOW;
		if (gbHide)
		{
			nCmdShow = SW_HIDE;
		}
		ShowWindow(hMainWnd, nCmdShow);
	}
	if (gbHide)
		gbMainWndMinimized = TRUE;

	UpdateWindow(hMainWnd);

	////DWORD dwStyle = GetWindowLong(hMainWnd, GWL_STYLE);
	////DWORD dwStyle1 = dwStyle;
	////dwStyle = dwStyle >> 28;
	////BOOL b = dwStyle & 1;

	return TRUE;
}

//////////////////////////////////////////////////////////////////////////
//	CMainWnd::HandlePaint
//	hWnd
//
//////////////////////////////////////////////////////////////////////////
LRESULT CMainWnd::HandlePaint(HWND hWnd,UINT,WPARAM,LPARAM)
{
	PAINTSTRUCT ps;
	HDC hDC = BeginPaint(hWnd, &ps);

	if (gConfig.bShowLowerPane)
		DrawEdge(hDC, &gMainWndRect, BDR_RAISEDOUTER| BDR_RAISEDINNER, BF_MIDDLE| BF_BOTTOMLEFT);
	
	EndPaint(hWnd,&ps);
	return 0;
}


//////////////////////////////////////////////////////////////////////////
///
///
///
///
///
///
///
//////////////////////////////////////////////////////////////////////////
int GetButtonSize()
{
	int cyHeight = GetSystemMetrics(SM_CYSMICON);
	cyHeight = cyHeight << 16;
	int cxWidth = GetSystemMetrics(SM_CXMAXIMIZED);
	SendMessage(ghWndToolbar, TB_SETBITMAPSIZE, 0, (LPARAM)(cyHeight | cxWidth));
	int nSize = SendMessage(ghWndToolbar, TB_GETBUTTONSIZE, 0, 0);
	SendMessage(ghWndToolbar, TB_SETBITMAPSIZE, 0, (LPARAM)0xF0010);
	SendMessage(ghWndToolbar, TB_SETBUTTONSIZE, 0, (LPARAM)nSize);
	return nSize;
}

//////////////////////////////////////////////////////////////////////////
///
///
///
///
///
///
///
//////////////////////////////////////////////////////////////////////////
CGraphData* InitGraphData(int nCount, int nChildID, BOOL fFlags)
{
	CGraphData* pGraphData = (CGraphData*)malloc(nCount * sizeof(CGraphData));
	//CGraphData** ppGraphData = (CGraphData**)pGraphData;
	for (int index = 0; index < nCount; index++)
	{
		ZeroMemory(&pGraphData[index], sizeof(CGraphData));

		GetSystemTimeAsFileTime(&pGraphData[index].m_Time);
		pGraphData[index].m_Lock.Init();
		pGraphData[index].m_nChildID = nChildID;
		pGraphData[index].m_Buffer2 = malloc(gdwVirtualScreenWidth * sizeof(DWORD));
		ZeroMemory(pGraphData[index].m_Buffer2, gdwVirtualScreenWidth * sizeof(DWORD));
		if (fFlags)
		{
			pGraphData[index].m_Buffer = malloc(gdwVirtualScreenWidth * sizeof(DWORD));
			ZeroMemory(pGraphData[index].m_Buffer, gdwVirtualScreenWidth * sizeof(DWORD));
		}
		if (nChildID > 0)
		{
			for (int j = 0; j < nChildID; j++)
			{
				pGraphData[index].m_Item[j].pBuffer =(double*) malloc(gdwVirtualScreenWidth * sizeof(double));
				ZeroMemory(pGraphData[index].m_Item[j].pBuffer, gdwVirtualScreenWidth * sizeof(double));
			}
		}
	}
	//CGraphData* pGraphData = (CGraphData*)malloc(sizeof(CGraphData)*nCount);
	//if (nCount > 0)
	//{
	//	int nCountIn = 0;
	//	PUCHAR pBuffer = (PUCHAR)&pGraphData->m_Buffer;
	//	do 
	//	{
	//		ZeroMemory(&pGraphData[nCountIn], sizeof(CGraphData));
	//		pGraphData[nCountIn].m_nChildID = nChildID;
	//		GetSystemTimeAsFileTime(&pGraphData[nCountIn].m_Time);
	//		pGraphData[nCountIn].m_ScreenBuffer = malloc(sizeof(DWORD)*gdwVirtualScreenWidth);
	//		ZeroMemory(pGraphData[nCountIn].m_ScreenBuffer, sizeof(DWORD)*gdwVirtualScreenWidth);
	//		
	//		if (fFlags)
	//		{
	//			pBuffer =(PUCHAR) malloc(sizeof(DWORD)*gdwVirtualScreenWidth);
	//			ZeroMemory(pBuffer, sizeof(DWORD)*gdwVirtualScreenWidth);
	//		}

	//		if (nChildID > 0)
	//		{
	//			//pBuffer =
	//		}

	//		pBuffer += sizeof(CGraphData);
	//		++nCountIn;
	//	} while (nCountIn < nCount);
	//}

	return pGraphData;
}


//////////////////////////////////////////////////////////////////////////
///
///	InitToolbar			创建主工具条
///	HWND hWnd:			父窗口句柄
///	UINT nIDToolbar:	工具条ID号
///
///	返回值:
///
//////////////////////////////////////////////////////////////////////////
HWND InitToolbar(HWND hWnd, UINT nIDToolbar)
{
	INITCOMMONCONTROLSEX	picce = { sizeof(picce) };
	picce.dwICC = ICC_COOL_CLASSES | ICC_USEREX_CLASSES | ICC_BAR_CLASSES;
	InitCommonControlsEx(&picce);

	UINT nButtonIDs[] = {
		IDM_FILE_SAVE,
		0,
		IDM_VIEW_REFRESH_NOW,
		0,
		IDM_TRAYMENU_CONTEXT_SYSTEM_INFORMATION,

		IDM_VIEW_SHOW_PROCESS_TREE,
		IDM_VIEW_SHOW_LOWER_PANE,
		IDM_POPUP_DLL_PROPERTIES,
		0,
		IDM_VIEW_PROCESS_PROPERTIES,
		IDM_PROCESS_KILL_PROCESS,
		0,
		IDM_SEARCH_IN_PROCESS,
		IDM_FIND_PROCESS_BY_WINDOW,
	};

	int nBitmapIndies[] =
	{
		BMP_SAVE,0,BMP_REFRESH,0,BMP_VIEW_SYSTEM_INFORMATION,
		BMP_SHOW_PROCESS_TREE,BMP_SHOW_LOWER_PANE,BMP_VIEW_HANDLES,0,
		BMP_PROPERTIES,BMP_KILL_PROCESS,
		0,
		BMP_SEARCH,
		BMP_FIND_PROCESS_BY_WINDOW,
	};

	UINT nStates[] =
	{
		TBSTATE_ENABLED,
		TBSTATE_ENABLED | 0x100,
		TBSTATE_ENABLED,
		TBSTATE_ENABLED | 0x100,
		TBSTATE_ENABLED,

		TBSTATE_ENABLED,
		TBSTATE_ENABLED,
		TBSTATE_ENABLED,
		TBSTATE_ENABLED | 0x100,
		TBSTATE_ENABLED,

		TBSTATE_ENABLED,
		TBSTATE_ENABLED | 0x100,
		TBSTATE_ENABLED,
		TBSTATE_ENABLED,

	};


	TBBUTTON buttons[14] = { 0 };
	for (int i = 0; i < sizeof(buttons) / sizeof(*buttons); i++)
	{
		buttons[i].idCommand = nButtonIDs[i];
		buttons[i].iBitmap = nBitmapIndies[i];
		buttons[i].fsState = nStates[i];
	}

	/// 创建Rebar
	ghWndReBar = CreateWindowEx(WS_EX_TOOLWINDOW,
		REBARCLASSNAME,
		NULL,
		WS_CHILD | WS_VISIBLE | WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_BORDER | CCS_NODIVIDER | RBS_BANDBORDERS | CCS_NOPARENTALIGN,
		0,
		0,
		400,
		275,
		hWnd,
		NULL,
		ghInstance,
		0);
	REBARINFO RebarInfo = { sizeof(RebarInfo) };
	RebarInfo.fMask = 0;
	if (!SendMessage(ghWndReBar, RB_SETBARINFO, 0, (LPARAM)&RebarInfo))
		return FALSE;

	///创建内嵌的工具条
	ghWndToolbar = CreateToolbarEx(ghWndReBar,
		WS_CHILD | WS_VISIBLE | WS_CLIPCHILDREN | WS_CLIPSIBLINGS | TBSTYLE_TOOLTIPS | TBSTYLE_FLAT | CCS_NODIVIDER | TBSTYLE_GROUP,
		nIDToolbar,
		12,
		ghInstance,
		IDB_MAINTOOLBAR,
		(LPCTBBUTTON)&buttons,
		sizeof(buttons) / sizeof(*buttons),
		0,
		0,
		0,
		0,
		20);
	if (!ghWndToolbar)
		return FALSE;
	///设置工具条的尺寸
	int nButtonSize = GetButtonSize();
	RECT rcItem1, rcItem2, rect;
	SendMessage(ghWndToolbar, TB_GETRECT, IDM_FILE_SAVE, (LPARAM)&rcItem1);
	SendMessage(ghWndToolbar, TB_GETRECT, IDM_FIND_PROCESS_BY_WINDOW, (LPARAM)&rcItem1);
	UnionRect(&rect, &rcItem1, &rcItem2);

	///将工具条嵌入到Rebar中
	REBARBANDINFO RebarBandInfo = { sizeof(RebarBandInfo) };
	RebarBandInfo.fMask = RBBIM_ID | RBBIM_CHILD | RBBIM_CHILDSIZE | RBBIM_SIZE | RBBIM_STYLE | RBBIM_COLORS;
	RebarBandInfo.fStyle = RBBS_GRIPPERALWAYS;
	RebarBandInfo.hwndChild = ghWndToolbar;
	RebarBandInfo.cxMinChild = 0;
	RebarBandInfo.clrFore = GetSysColor(COLOR_BTNTEXT);
	RebarBandInfo.clrBack = GetSysColor(COLOR_BTNFACE);
	RebarBandInfo.cx = rect.right - rect.left;
	RebarBandInfo.cxMinChild = RebarBandInfo.cx;
	RebarBandInfo.cyMinChild = nButtonSize >> 16;
	RebarBandInfo.wID = 0;
	SendMessage(ghWndReBar, RB_INSERTBAND, 0xFFFFFFFF, (LPARAM)&RebarBandInfo);

	///创建内嵌的CPU走势图
	ghWndCPUGraph = CreateWindowEx(0,
		GRAPHCLASSNAME,
		TEXT(""),
		WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_TABSTOP | 0x4,
		0,
		0,
		0,
		0,
		ghWndReBar,
		(HMENU)IDC_GRAPH_IN_REBAR,
		ghInstance,
		(void*)gpGraphInfoOfCPU);

	/*ReBar_InsertBand()*/
	///嵌入到Rebar中
	RebarBandInfo.hwndChild = ghWndCPUGraph;
	RebarBandInfo.cxMinChild = 0;
	RebarBandInfo.wID = 1;
	SendMessage(ghWndReBar, RB_INSERTBAND, 0xFFFFFFFF, (LPARAM)&RebarBandInfo);





	return ghWndToolbar;
}
//////////////////////////////////////////////////////////////////////////
///
///
///
///
///
///
///
//////////////////////////////////////////////////////////////////////////
LONG LoadHiddenProcessesFromRegistry()
{

	gpHiddenProcesses = new WCHAR*[1];
	*gpHiddenProcesses = NULL;
	
	HKEY hKey = NULL;
	LONG nRet = RegOpenKeyEx(HKEY_CURRENT_USER,
		TEXT("Software\\Sysinternals\\Process Explorer"),
		0,
		KEY_READ,
		&hKey);
	if (!nRet)
	{
		DWORD dwType = 0;
		DWORD cbData = 0;
		WCHAR* pszHiddenProcs = NULL;
		if (!RegQueryValueEx(hKey, TEXT("HiddenProcs"), NULL, &dwType, NULL, &cbData))
		{
			pszHiddenProcs = (WCHAR*)malloc(cbData);
			RegQueryValueEx(hKey, TEXT("HiddenProcs"), NULL, &dwType, (BYTE*)pszHiddenProcs, &cbData);
			if (pszHiddenProcs < (pszHiddenProcs + cbData))
			{
				WCHAR* pszHiddenProcesses = pszHiddenProcs;
				int nIndex = 0;
				do 
				{
					if (!*pszHiddenProcesses)
						break;
					gpHiddenProcesses = (WCHAR**)realloc(gpHiddenProcesses, nIndex * sizeof(WCHAR*) + 8);
					gpHiddenProcesses[nIndex] = _wcsdup(pszHiddenProcesses);

					gpHiddenProcesses[nIndex] = NULL;
					++nIndex;
					pszHiddenProcesses += wcslen(pszHiddenProcesses) + 1;
				} while (pszHiddenProcesses < (pszHiddenProcs + cbData));
			}
		}

		nRet = RegCloseKey(hKey);
	}

	return nRet;
}

//////////////////////////////////////////////////////////////////////////
///
///
///
///
///
///
///
//////////////////////////////////////////////////////////////////////////
LONG SaveHiddenProcessesToRegistry()
{
	ATL::CRegKey reg;
	if (reg.Open(HKEY_CURRENT_USER, TEXT("Software\\Sysinternals\\Process Explorer")))
	{
		int nLength = 0;
		WCHAR** ppHiddenProcesses = gpHiddenProcesses;
		while (ppHiddenProcesses)
		{
			nLength += (lstrlenW(*ppHiddenProcesses) + 1);
			ppHiddenProcesses++;
		}
		if (nLength > 0)
		{
			LPBYTE pData = new BYTE[nLength << 1];
			WCHAR* pNewString = (WCHAR*)pData;
			ppHiddenProcesses = gpHiddenProcesses;
			WCHAR* pNewStringBuf = pNewString;
			int nLengthLeft = nLength;
			while (ppHiddenProcesses)
			{
				if (*ppHiddenProcesses)
				{
					wcscpy_s(pNewStringBuf, nLengthLeft, *ppHiddenProcesses);
					nLengthLeft -= (lstrlenW(*ppHiddenProcesses) + 1);
					pNewStringBuf += (lstrlenW(*ppHiddenProcesses) + 1);
				}
				ppHiddenProcesses++;
			}

			*pNewString = 0;
			RegSetValueExW(reg.m_hKey, L"HiddenProcs", NULL, REG_MULTI_SZ, pData, nLength << 1);
			reg.Close();
			delete[]pData;
		}
		else
		{
			reg.DeleteValue(TEXT("HiddenProcs"));
			reg.Close();
		}
	}
	return 0;
}
//////////////////////////////////////////////////////////////////////////
///
///
///
///
///
///
///
//////////////////////////////////////////////////////////////////////////
LONG LoadProcessCommentsFromRegistry()
{
	int nIndex = 0;
	HKEY hKey = NULL;
	WCHAR szValueName[1024] = { 0 };
	DWORD cbValueName = 1024;
	DWORD dwType = 0;
	DWORD cbData = 0;

	LONG nRet = RegOpenKeyEx(HKEY_CURRENT_USER,
		TEXT("Software\\Sysinternals\\Process Explorer\\ProcessComments"),
		0,
		KEY_READ,
		&hKey);
	if (!nRet)
	{
		if (!RegEnumValue(hKey, 0, szValueName, &cbValueName, NULL, &dwType, NULL, &cbData))
		{
			do 
			{
				gpProcessComments = (PROCESSCOMMENT*)realloc(gpProcessComments, sizeof(PROCESSCOMMENT)*nIndex + 16);
				gpProcessComments[nIndex].pszName = _wcsdup(szValueName);
				gpProcessComments[nIndex].pszComment = new BYTE[cbData];
				cbValueName += 2;
				RegEnumValue(hKey, nIndex, szValueName, &cbValueName, 0, &dwType, gpProcessComments[nIndex].pszComment, &cbData);
				gpProcessComments[nIndex + 1].pszName = NULL;
				cbValueName = 1024;
				nIndex++;
			} while (!RegEnumValue(hKey,nIndex,szValueName,&cbValueName,NULL,&dwType,NULL,&cbData));
		}
		nRet = RegCloseKey(hKey);
	}
	return nRet;
}

//////////////////////////////////////////////////////////////////////////
///
///
///
///
///
///
///
//////////////////////////////////////////////////////////////////////////
LRESULT CMainWnd::HandleCreate(HWND hWnd,UINT,WPARAM,LPARAM)
{
	WSADATA		WSAData = { 0 };
	CoInitialize(NULL);
	
	//CString strText;

	//strText = TEXT("Test");
	//strText += TEXT("OK");


	WSAStartup(MAKEWORD(1, 1), &WSAData);
	GetLocaleInfoW(LOCALE_USER_DEFAULT, LOCALE_SDECIMAL, gszLocaleInfo, 16);// sizeof(gszLocaleInfo) / sizeof(*gszLocaleInfo));

	gLock1.Init();
	gLock2.Init();
	gLock3.Init();
	gVerificationItemListLock.Init();
	
	LoadHiddenProcessesFromRegistry();
	LoadProcessCommentsFromRegistry();


	gpfnCreateRestrictedToken = (LPFN_CreateRestrictedToken)GetProcAddress(LoadLibraryW(L"Advapi32.DLL"), "CreateRestrictedToken");

	gbWintrustInited = LoadWintrust();

	ghMainWnd = hWnd;

	gbProcessDEPEnabled = IsProcessDEPEnabled();

	SetCursor(LoadCursor(NULL, IDC_WAIT));
	ghCursorArrow = LoadCursor(NULL, IDC_ARROW);
	ghCursorFind = LoadCursor(NULL, MAKEINTRESOURCE(IDC_FIND));

	HMENU hMenuMain = GetMenu(hWnd);

	EnableMenuItem(hMenuMain, IDM_VIEW_SHOW_HIDDEN_PROCESSES, *gpHiddenProcesses == 0);

	LOGFONT LogFont = { 0 };
	HFONT hFont = (HFONT)GetStockObject(DEFAULT_GUI_FONT);
	GetObject(hFont, sizeof(LOGFONT), &LogFont);
	ghDefaultUnderlineFontHandle = CreateFontIndirect(&LogFont);
	gdwComdlg_FindReplaceMessageID = RegisterWindowMessageW(L"commdlg_FindReplace");

	DeleteMenu(hMenuMain, IDM_VIEW_LOADCOLUMNSET_TEST, MF_BYCOMMAND);
	HMENU hFileMenu = GetSubMenu(hMenuMain, 0);
	HMENU hOptionMenu = GetSubMenu(hMenuMain, 1);
	HMENU hViewMenu = GetSubMenu(hMenuMain, 2);
	HMENU hProcessMenu = GetSubMenu(hMenuMain, 3);

	DeleteMenu(hViewMenu, 0, MF_BYPOSITION);

	WCHAR szMenuItemName[_MAX_PATH] = { 0 };
	UINT nID = 0;
	for (DWORD i = 0; i < gConfig.dwNumColumnsets; ++i)
	{
		if (i >= MAX_NumColumnsets)
		{
			wcscpy_s(szMenuItemName, MAX_PATH, gConfig.strMenuCulumnSet[i].ColumnSetName);
		}
		else
		{
			if (i == MAX_NumColumnsets - 1)
				nID = 0;
			else
				nID = i + 1;
			wsprintfW(szMenuItemName, L"%s\tCtrl+%i", gConfig.strMenuCulumnSet[i].ColumnSetName, nID);
		}

		AppendMenuW(GetSubMenu(hViewMenu, gdwMenuItemPosLast), MF_BYCOMMAND, i + IDM_PROCESS_PRIORITY_BASE, szMenuItemName);
	}

	ghPriorityPopupMenuHandle = LoadMenu(ghInstance, MAKEINTRESOURCE(IDM_POPUP_PRIORITYMENU));
	if (gpfnCreateRestrictedToken)
	{
		InsertMenu(hFileMenu, 1, MF_BYPOSITION, IDM_RUN_AS_LIMITED_USER, TEXT("Run as &Limited User..."));
		++gdwMenuItemCountAppendedInRuntime;
	}

	if (gdwVersion < WINDOWS_VISTA)
	{
		InsertMenu(hFileMenu, 1, MF_BYPOSITION, IDM_RUN_AS, TEXT("R&unas..."));
		++gdwMenuItemCountAppendedInRuntime;
	}
	if (!IsBuiltinAdministrative())
	{
		InsertMenu(hFileMenu, 1, MF_BYPOSITION, IDM_RUN_AS, TEXT("R&un as Administrator..."));
		++gdwMenuItemCountAppendedInRuntime;
	}
	
	InsertMenuW(
		hMenuMain,
		IDM_PRIORITY_NORMAL,
		MF_BYCOMMAND,
		IDM_PROCESS_SETPRIORITY_ABOVE_NORMAL_TEN,
		L"&Above Normal: 10");
	InsertMenuW(
		ghPriorityPopupMenuHandle,
		IDM_PROCESS_SETPRIORITY_NORMAL,
		MF_BYCOMMAND,
		IDM_PROCESS_SETPRIORITY_ABOVE_NORMAL_TEN,
		L"&Above Normal: 10");
	InsertMenuW(
		hMenuMain,
		IDM_PROCESS_SETPRIORITY_IDLE,
		MF_BYCOMMAND,
		IDM_PROCESS_SETPRIORITY_BELOW_NORMAL_SIX,
		L"&Below Normal: 6");
	InsertMenuW(
		ghPriorityPopupMenuHandle,
		IDM_PROCESS_SETPRIORITY_IDLE,
		MF_BYCOMMAND,
		IDM_PROCESS_SETPRIORITY_BELOW_NORMAL_SIX,
		L"&Below Normal: 6");

	if (gdwVersion < WINDOWS_VISTA
		|| (InsertMenuW(
			hMenuMain,
			IDM_PRIORITY_IDLE,
			MF_BYCOMMAND,
			IDM_PROCESS_SETPRIORITY_BACKGROUND_FOUR,
			L"Back&ground: 4 (Low I/O and Memory Priority)"),
			InsertMenuW(
				ghPriorityPopupMenuHandle,
				IDM_PRIORITY_IDLE,
				MF_BYCOMMAND,
				IDM_PROCESS_SETPRIORITY_BACKGROUND_FOUR,
				L"Back&ground: 4 (Low I/O and Memory Priority)"),
			gdwVersion < WINDOWS_VISTA)
		|| IsBuiltinAdministrative())
	{
		ChangeWindowMessageFilter(WM_MSG_7F2, MSGFLT_ADD);
	}
	else
	{
		InsertMenuW(hFileMenu, 3, MF_BYPOSITION | MF_SEPARATOR, 0, NULL);// 0xC00 = MF_BYPOSITION|MF_SEPARATOR
		++gdwMenuItemCountAppendedInRuntime;
		InsertMenuW(
			hFileMenu,
			4,
			MF_BYPOSITION,
			IDM_SHOW_DETAILS_FOR_ALL_PROCESSES,
			L"Show &Details for All Processes");
		ReplaceMenuIconFromStockIcon(hMenuMain, IDM_SHOW_DETAILS_FOR_ALL_PROCESSES);
		++gdwMenuItemCountAppendedInRuntime;
	}

	HMENU hOpacityPopupMenuHandle = LoadMenuW(ghInstance, L"OPACITY");
	InsertMenuW(hMenuMain, IDM_VIEW_SHOW_LOWER_PANE, MF_POPUP, (UINT)hOpacityPopupMenuHandle, L"Opacity");
	InsertMenuW(hMenuMain, IDM_VIEW_SHOW_LOWER_PANE, MF_SEPARATOR, 0, NULL);

#define CHECKMAINMENU(nID,State)	CheckMenuItem(hMenuMain,nID,State)
#define CHECKMAINMENUBYCONFIG(nID,Name)	CHECKMAINMENU(nID, (gConfig.##Name ? MF_CHECKED : 0) )

	CHECKMAINMENU(IDM_OPTIONS_VERIFY_IMAGE_SIGNATURE, (gConfig.bVerifySignatures ? MF_CHECKED : 0) );

	CHECKMAINMENU(IDM_OPTIONS_CHECK_VIRTULTOALDOTCOM, (gConfig.bAllOneInstance2 ? MF_CHECKED : 0));
	EnableMenuItem(hMenuMain, IDM_OPTIONS_SUBMIT_UNKNOWN_EXECUTABLES, gConfig.bAllOneInstance2 == false);
	if (gConfig.bAllOneInstance2)
	{
		SubmitExeToVirusTotalDotCom();
	}
	CHECKMAINMENUBYCONFIG(IDM_OPTIONS_TRAYICON_CPU_HISTORY, bTrayCPUHistory);
	CHECKMAINMENUBYCONFIG(IDM_OPTIONS_TRAYICON_IO_HISTORY, bShowIoTray);

	CHECKMAINMENUBYCONFIG(IDM_OPTIONS_TRAYICON_COMMIT_HISTORY, bShowCommitTray);
	CHECKMAINMENUBYCONFIG(IDM_OPTIONS_TRAYICON_PHYSICAL_MEMORY_HISTORY, bShowPhysTray);
	CHECKMAINMENUBYCONFIG(IDM_OPTIONS_ALLOW_ONLY_ONE_INSTANCE, bAllOneInstance);

	gConfig.bAlwaysOntop = gConfig.bAlwaysOntop == false;
	Command_SetTopmost(ghMainWnd);

	CHECKMAINMENUBYCONFIG(IDM_OPTIONS_HIDE_WHEN_MINIMIZED, bHideWhenMinimized);

	CHECKMAINMENUBYCONFIG(IDM_VIEW_SHOW_COLUMN_HEATMAPS, bShowColumnHeatmaps);
	CHECKMAINMENUBYCONFIG(IDM_PROCESS_CONFIRM_TO_KILL, bShowCpuFractions);
	CHECKMAINMENUBYCONFIG(IDM_OPTIONS_CONFIRM_KILL, bConfirmKill);
	CHECKMAINMENUBYCONFIG(IDM_SHOW_NEW_PROCESS, bFormatIoBytes);

	CHECKMAINMENUBYCONFIG(IDM_VIEW_SCROLL_TO_NEW_PROCESSES, bShowNewProcesses);

	__int64 dwMinSegments = 0i64;
	__int64 dwNbSegments = 0i64;

	if (InitAdapterList(&dwMinSegments, &dwNbSegments))
	{
		gpGraphInfoOfCPU = InitGraphData(1, 1, TRUE);
		gpGraphInfoOfCPU->m_nItemID = 4;
		gpGraphInfoOfCPU->m_Color = RGB(0x80, 0x80, 0xFF);
		gpGraphInfoOfCPU->m_dbMemorySize = 100.0;

		gpGraphInfoOfPhysicalMemory = InitGraphData(1, 1, FALSE);
		gpGraphInfoOfPhysicalMemory->m_nItemID = 5;
		gpGraphInfoOfPhysicalMemory->m_Color = RGB(0, 0xAA,0xAA);
		gpGraphInfoOfPhysicalMemory->m_dbMemorySize = dwMinSegments ? (*(double*)&dwMinSegments) : 1.0;

		gpGraphInfoOfDedicatedMemory = InitGraphData(1, 1, FALSE);
		gpGraphInfoOfDedicatedMemory->m_nItemID = 6;
		gpGraphInfoOfDedicatedMemory->m_Color = RGB(0x40,0x80,0xFF);
		gpGraphInfoOfDedicatedMemory->m_dbMemorySize = dwNbSegments ? (*(double*)&dwNbSegments) : 1.0;
	}

	InsertMenuW(hMenuMain, IDM_VIEW_SHOW_PROCESS_TREE, MF_SEPARATOR, 0, NULL);
	InsertMenuW(
		hMenuMain,
		IDM_OPTIONS_HIDE_WHEN_MINIMIZED,
		MF_BYCOMMAND,
		IDM_OPTIONS_REPLACE_TASK_MANAGER,
		L"Replace &Task Manager");

	CHECKMAINMENU(IDM_OPTIONS_REPLACE_TASK_MANAGER,(CanReplaceTaskManager() ? MF_CHECKED : 0));
	if (gdwVersion >= WINDOWS_VISTA && !IsBuiltinAdministrative())
	{
		ReplaceMenuIconFromStockIcon(hMenuMain, IDM_OPTIONS_REPLACE_TASK_MANAGER);
	}
	if (CanReplaceTaskManager())
	{
		ReplaceTaskManager(hWnd, FALSE);
	}

	CHECKMAINMENU(IDM_OPTIONS_RUN_AT_LOGON, (IsProcessExplorerRunAtStartup() ? MF_CHECKED : 0));

	CHECKMAINMENUBYCONFIG(IDM_VIEW_SHOW_PROCESSES_FROM_ALL_USERS, bShowAllUsers);

	InsertMenuW(
		hMenuMain,
		IDM_OPTIONS_DIFFERENCE_HIGHLIGHT_DURATION,
		MF_BYCOMMAND,
		IDM_VIEW_CONFIGURE_SYMBOLS,
		L"Configure &Symbols...");
	DeleteMenu(hMenuMain, IDM_OPTIONS_HIGHLIGHT_RELOCATED_DLLS, MF_BYCOMMAND);
	InsertMenuW(
		hMenuMain,
		IDM_OPTIONS_DIFFERENCE_HIGHLIGHT_DURATION,
		MF_BYCOMMAND,
		IDM_VIEW_CONFIGURE_COLORS,
		L"&Configure Colors...");

	PWTS_SESSION_INFO pSessionInfo = NULL;
	DWORD dwSessionCount = 0;
	if (WTSEnumerateSessionsW(NULL, 0, 1, &pSessionInfo, &dwSessionCount)
		&& dwSessionCount)
	{
		MENUINFO MenuInfo = { sizeof(MenuInfo) };
		MenuInfo.fMask = MIM_APPLYTOSUBMENUS| MIM_MENUDATA|MIM_STYLE;
		MenuInfo.dwStyle = MNS_NOTIFYBYPOS;
		SetMenuInfo(hMenuMain, &MenuInfo);
		ghUserPopupMenuHandle = CreateMenu();
		InsertMenu(hMenuMain, 5, MF_BYPOSITION | MF_DISABLED|MF_CHECKED, (UINT)ghUserPopupMenuHandle, TEXT("&Users"));
		WTSFreeMemory(pSessionInfo);
	}



	//CHECKMAINMENUBYCONFIG(, );
	//CHECKMAINMENUBYCONFIG(, );
	//CHECKMAINMENUBYCONFIG(, );
	//CHECKMAINMENUBYCONFIG(, );
	//CHECKMAINMENUBYCONFIG(, );
	//CHECKMAINMENUBYCONFIG(, );
	//CHECKMAINMENUBYCONFIG(, );
	//CHECKMAINMENUBYCONFIG(, );
	//CHECKMAINMENUBYCONFIG(, );
	//CHECKMAINMENUBYCONFIG(, );
	//CHECKMAINMENUBYCONFIG(, );
	//CHECKMAINMENUBYCONFIG(, );
	//CHECKMAINMENUBYCONFIG(, );
	//CHECKMAINMENUBYCONFIG(, );
	WCHAR szMainText[_MAX_PATH] = { 0 };
	WCHAR szUserName[_MAX_PATH] = { 0 };
	WCHAR szDomainName[_MAX_PATH] = { 0 };
	WCHAR* psz = L"\\";
	QueryProcessUsers(GetCurrentProcess(), GetCurrentProcessId(), NULL, szUserName, _MAX_PATH, szDomainName, _MAX_PATH, NULL, 0, NULL, NULL);
	if (!*szDomainName || !*szUserName)
		psz = 0;
	wsprintfW(gszMainTitle, L"%s%s%s", szDomainName, psz, szUserName);
	int nLen1= GetWindowText(ghMainWnd, szMainText, _MAX_PATH);
	int nLength = wcslen(szMainText);
	swprintf_s(szMainText + nLen1, _MAX_PATH - nLen1, L" [%s]", gszMainTitle);
	SetWindowTextW(ghMainWnd, szMainText);

	gColorCustomized[0] = gConfig.ColorOwn;
	gColorCustomized[1] = gConfig.ColorService;
	gColorCustomized[2] = gConfig.ColorRelocatedDlls;
	gColorCustomized[3] = gConfig.ColorJobs;
	gColorCustomized[4] = gConfig.ColorNet;

	QueryCurrentAuthorityInfo(&gpszAuthInfo);

	if (gSystemInfo.dwNumberOfProcessors > 1)
	{
		InsertMenuW(hProcessMenu, 2, MF_BYPOSITION, IDC_PROCESS_SET_AFFINITY, L"Set &Affinity...");
		CheckMenuItem(hMenuMain, (gConfig.bShowAllCpus != 0) + IDM_PROCESSOR_ONE_GRAPH_ALL_CPUS, MF_CHECKED);

		DWORD	cbData = 0;
		FARPROC pfn = GetProcAddress(GetModuleHandleW(L"KERNEL32.DLL"), "GetLogicalProcessorInformation");
		if (!pfn)
		{
			gpSystemLogicalProcessorInfo = Fake_GetLogicalProcessorInformation(&gdwLogicalProcessorInfoItemCount);
		}
		else
		{
			GetLogicalProcessorInformation(NULL, &cbData);

			PSYSTEM_LOGICAL_PROCESSOR_INFORMATION pBuffer = (PSYSTEM_LOGICAL_PROCESSOR_INFORMATION)malloc(cbData);
			GetLogicalProcessorInformation(pBuffer, &cbData);

			gpSystemLogicalProcessorInfo = pBuffer;
			gdwLogicalProcessorInfoItemCount = cbData / sizeof(PSYSTEM_LOGICAL_PROCESSOR_INFORMATION);
		}
	}

	gppGraphInfo = new CGraphData*[gSystemInfo.dwNumberOfProcessors];
	for (DWORD dwIndex = 0; dwIndex < gSystemInfo.dwNumberOfProcessors; dwIndex++)
	{
		gppGraphInfo[dwIndex] = InitGraphData(gSystemInfo.dwNumberOfProcessors, 2, FALSE);
		gppGraphInfo[dwIndex]->m_ProcessorID = dwIndex;

		gppGraphInfo[dwIndex]->m_nChildID = 2;
		gppGraphInfo[dwIndex]->m_nItemID = 0;
		gppGraphInfo[dwIndex]->m_Color = RGB(0x3C, 0x94, 0x3C);
		gppGraphInfo[dwIndex]->m_dbMemorySize = 100.0;
		gppGraphInfo[dwIndex]->m_Item[0].dwValue[5] = 255;
		*(double*)&(gppGraphInfo[dwIndex]->m_Item[0].dwValue[3]) = 100.0;
		gppGraphInfo[dwIndex]->m_GraphData = gpGraphInfoOfCPU;
		if (dwIndex)
		{
			gppGraphInfo[dwIndex]->m_Time = gppGraphInfo[0]->m_Time;
			gppGraphInfo[dwIndex]->m_dwValue868 = gppGraphInfo[0]->m_dwValue868;
		}
	}
	HMODULE hModule = LoadLibraryW(L"Powrprof.dll");

	FARPROC pfn = GetProcAddress(hModule, "SetSuspendState");
	if (pfn)
	{
		LPFN_IsXXXX IsPwrHibernateAllowed = (LPFN_IsXXXX)GetProcAddress(hModule, "IsPwrHibernateAllowed");
		if(IsPwrHibernateAllowed())
			InsertMenuW(hMenuMain, IDM_FILE_SHUTDOWN_RESTART, MF_BYCOMMAND, IDC_FILE_HIBERNATE, L"&Hibernate");
		LPFN_IsXXXX IsPwrSuspendAllowed = (LPFN_IsXXXX)GetProcAddress(hModule, "IsPwrSuspendAllowed");
		if(IsPwrSuspendAllowed())
			InsertMenuW(hMenuMain, IDM_FILE_SHUTDOWN_RESTART, MF_BYCOMMAND, IDC_FILE_STANDBY, L"Stand &By");
	}

	hModule = LoadLibraryW(L"User32.dll");
	gpfn_LockWorkStation = (LPFN_LockWorkStation)GetProcAddress(hModule, "LockWorkStation");
	//GetMonitorInfoA()
	///	MonitorFromPoint();
	ghDllsMenuPopup = LoadMenu(ghInstance, MAKEINTRESOURCE(IDM_POPUP_DLLMENU));
	ghHandlesMenuPopup = LoadMenu(ghInstance, MAKEINTRESOURCE(IDM_POPUP_HANDLEMENU));

	//CHECKMAINMENUBYCONFIG(, );
	//CHECKMAINMENUBYCONFIG(, );
	CHECKMAINMENUBYCONFIG(IDM_OPTIONS_HIGHLIGHT_RELOCATED_DLLS, bHighlightRelocatedDlls);
	CHECKMAINMENUBYCONFIG(IDM_VIEW_SHOW_UNNAMED_HANDLES_AND_MAPPINGS, bShowUnnamedHandles);

	ATL::CRegKey reg;
	if (reg.Open(HKEY_CLASSES_ROOT, TEXT("exefile\\shell\\View Dependencies")))
	{
		*gszApplicationName = 0;
		DWORD dwSize = GetEnvironmentVariable(TEXT("Path"), NULL, 0);
		if (dwSize)
		{
			WCHAR* pszPath = new WCHAR[dwSize + 1];
			GetEnvironmentVariable(TEXT("Path"), pszPath, dwSize);

			if (MakeApplicationName(L"depends.exe", pszPath, dwSize, gszApplicationName))
			{
				InsertMenuW(hMenuMain, IDM_PROCESS_TEMP, MF_BYCOMMAND, IDM_PROCESS_LAUNCH_DEPENDS, L"&Launch Depends...");
				InsertMenuW(
					ghDllsMenuPopup,
					IDM_DLLMENU_BASE_ITEM,
					MF_BYCOMMAND,
					IDM_DLLMENU_LAUNCH_DEPENDS,
					L"&Launch Depends...");
				gbLaunchDepends = true;
			}

			else
			{
				*gszApplicationName = 0;
			}
			delete[]pszPath;
		}
		else
		{
			gbLaunchDepends = true;
			InsertMenuW(hMenuMain, IDM_PROCESS_TEMP, MF_BYCOMMAND, IDM_PROCESS_LAUNCH_DEPENDS, L"&Launch Depends...");
			InsertMenuW(ghDllsMenuPopup, IDM_DLLMENU_BASE_ITEM, MF_BYCOMMAND, IDM_DLLMENU_LAUNCH_DEPENDS, L"&Launch Depends...");
			*gszApplicationName = 0;
		}
		reg.Close();
	}

	if (reg.Open(HKEY_LOCAL_MACHINE, TEXT("Software\\Microsoft\\Windows NT\\CurrentVersion\\AeDebug")))
	{
		WCHAR szPathName[_MAX_PATH] = { 0 };
		DWORD dwType = 0;
		DWORD cbData = _MAX_PATH * sizeof(WCHAR);
		if (!RegQueryValueExW(reg.m_hKey, L"Debugger", NULL, &dwType, (LPBYTE)szPathName, &cbData))
		{
			_wcslwr_s(gszAeDebuggerPath, MAX_PATH);
			_wcslwr_s(gszAeDebuggerPath, MAX_PATH);
			if (szPathName[0] == L'"')
			{
				wcscpy_s(gszAeDebuggerPath, MAX_PATH, &szPathName[1]);
				if (wcschr(gszAeDebuggerPath, L'"'))
				{
					psz = wcschr(gszAeDebuggerPath, L'"');
					*psz = 0;
				}
			}
			else
			{
				wcscpy_s(gszAeDebuggerPath, MAX_PATH, szPathName);
				if (wcschr(gszAeDebuggerPath, L' '))
				{
					psz = wcschr(gszAeDebuggerPath, L' ');
					*psz = 0;
				}
			}
		}

		reg.Close();
	}

	if (*gszAeDebuggerPath)
		InsertMenuW(hMenuMain, IDM_PROCESS_TEMP, MF_BYCOMMAND, IDM_PROCESS_DEBUG, L"&Debug");
	DeleteMenu(hMenuMain, IDM_PROCESS_TEMP, MF_BYCOMMAND);

	ghWndToolbar = InitToolbar(hWnd, IDC_MAINTOOLBAR);
	if (!ghWndToolbar)
		return -1;
	UpdateMenuStatus(FALSE, 3);
	RECT rcToolbar;
	GetWindowRect(ghWndToolbar, &rcToolbar);
	gnToolbarHeight = rcToolbar.bottom - rcToolbar.top + 2;
	RECT rcTreeList = { 0 };


	ghWndTreeListView = CTreeList::Init(hWnd, ghInstance, (HMENU)IDC_TREEVIEW_LIST, WS_CHILD| WS_BORDER|WS_TABSTOP| LVS_EDITLABELS, &rcTreeList);

	if (!ghWndTreeListView)
		return -1;

	CTreeList* pTreeList = CTreeList::GetTreeList(ghWndTreeListView);
	pTreeList->m_DrawBack =(LPFN_DrawBack)&CMainWnd::Draw;
	pTreeList->m_Callback1 =(FARPROC)&CMainWnd::GetDynamicCursor;

	pTreeList->UpdateSB(false);
	pTreeList->SetSplitterCursor(LoadCursor(ghInstance, MAKEINTRESOURCE(IDC_SPLITTER)));

	CTreeList::InitToolTips(pTreeList->GetTooltipOfTreeList());
	CTreeList::InitToolTips(pTreeList->GetTooltipOfLeftHeader());
	CTreeList::InitToolTips(pTreeList->GetTooltipOfRightHeader());

	DWORD dwProcessColumnCount = gConfig.dwProcessColumnCount;
	if (gConfig.dwProcessColumnMap[0] != IDS_PROCESS)
	{
		memmove(&gConfig.dwProcessColumnMap[1], gConfig.dwProcessColumnMap, sizeof(DWORD) * gConfig.dwProcessColumnCount);
		gConfig.dwProcessColumnMap[0] = IDS_PROCESS;
		memmove(&gConfig.dwProcessColumns[1], gConfig.dwProcessColumns, sizeof(WORD) * gConfig.dwProcessColumnCount);
		WORD wProcessImageColumnWidth = gConfig.wProcessImageColumnWidth[0];
		if (!gConfig.wProcessImageColumnWidth[0])
			wProcessImageColumnWidth = 200;
		gConfig.dwProcessColumns[0] = wProcessImageColumnWidth;
		dwProcessColumnCount = gConfig.dwProcessColumnCount++ + 1;
	}

	HIMAGELIST hImg = ImageList_Create(GetSystemMetrics(SM_CXSMICON), GetSystemMetrics(SM_CYSMICON), ILC_MASK|ILC_COLOR32, 256, 256);
	pTreeList->ResetImageList(hImg,false);
	ImageList_ReplaceIcon(hImg, -1, LoadIcon(NULL, IDC_ARROW));



	HIMAGELIST hImgList = InitSortableImageList();
	pTreeList->SetSortFlagsImageList(hImgList, 1, 0);

	if (!LOBYTE(gConfig.wProcessImageColumnWidth[1]))
	{
		CTreeList::InitHeaderColumn(ghWndTreeListView, -1, gConfig.dwProcessSortColumn, gConfig.bProcessSortDirection);
	}

	ghWndHandlesListCtrl = CreateListCtrl(hWnd, WS_CHILD | WS_BORDER | WS_TABSTOP | LVS_REPORT | LVS_SINGLESEL | LVS_EDITLABELS | LVS_OWNERDRAWFIXED,
		(USHORT*)gConfig.dwIdsOfHandleColumnMap,
		(int*)gConfig.dwHandleColumns,
		gConfig.dwHandleColumnCount,
		IDC_LISTCTRL_HANDLES);

	if (!ghWndHandlesListCtrl)
		return -1;
	CTreeList::InitHeaderColumn(ghWndHandlesListCtrl, -1, gConfig.dwHandleSortColumn, gConfig.bHandleSortDirection == TRUE);


	ghWndDllsListCtrl = CreateListCtrl(hWnd,
		WS_CHILD | WS_BORDER | WS_TABSTOP | LVS_REPORT | LVS_SINGLESEL | LVS_EDITLABELS | LVS_OWNERDRAWFIXED,
		(USHORT*)gConfig.dwDllColumnMap,
		(int*)gConfig.dwDllColumns,
		gConfig.dwDllColumnCount,
		IDC_LISTCTRL_DLLS);

	if (!ghWndDllsListCtrl)
		return -1;
	CTreeList::InitHeaderColumn(ghWndDllsListCtrl, -1, gConfig.dwDllSortColumn, gConfig.bDllSortDirection == TRUE);

	ghWndStatusBar = CreateStatusWindowW(WS_CHILD | WS_VISIBLE, TEXT(""), hWnd, IDC_STATUSBAR);
	InitStatusBar(ghWndStatusBar);

	ghResizeCursor = LoadCursor(ghInstance, MAKEINTRESOURCE(IDC_RESIZE));
	if (!ghResizeCursor)
		ghResizeCursor = LoadCursor(NULL, IDC_ARROW);
	ghSplitterCursor = LoadCursor(ghInstance, MAKEINTRESOURCE(IDC_SPLITTER));
	if (!ghSplitterCursor)
		ghSplitterCursor = LoadCursor(NULL, IDC_ARROW);

	CHECKMAINMENUBYCONFIG(IDM_OPTIONS_HIGHLIGHT_RELOCATED_DLLS, bHighlightRelocatedDlls);

	ShowWindow(ghWndTreeListView, SW_SHOW);

	if (gConfig.bShowLowerPane)
	{
		if (gConfig.bShowDllView)
		{
			CHECKMAINMENUBYCONFIG(IDM_VIEW_LOWERPANEVIEW_DLLS, bShowDllView);
			ShowWindow(ghWndDllsListCtrl, SW_SHOW);
		}
		else
		{
			CHECKMAINMENUBYCONFIG(IDM_VIEW_LOWERPANEVIEW_HANDLES, bShowDllView);
			ShowWindow(ghWndHandlesListCtrl, SW_SHOW);
		}
	}
	int nBmpIndex = BMP_VIEW_DLLS;
	if (gConfig.bShowDllView)
		nBmpIndex = BMP_VIEW_HANDLES;
	SendMessageW(ghWndToolbar, TB_CHANGEBITMAP, IDM_POPUP_DLL_PROPERTIES, nBmpIndex);
	SendMessageW(ghWndToolbar, TB_ENABLEBUTTON, IDM_VIEW_SHOW_PROCESS_TREE, LOBYTE(gConfig.wProcessImageColumnWidth[1])== false);

	EnableMenuItem(hMenuMain, IDM_VIEW_SHOW_PROCESS_TREE, LOBYTE(gConfig.wProcessImageColumnWidth[1]) != 0);

	EnableMenuItem(hMenuMain, IDM_PROCESS_KILL_PROCESS_TREE, MF_GRAYED);

	ghSystemInfoSheetThreadEvent = CreateEvent(NULL, FALSE, FALSE, NULL);
	GetClientRect(hWnd, &gRectWindow);
	gRectPane.left = 0;
	gRectWindow.top = gRectWindow.top - 1 + gnToolbarHeight;
	gRectWindow.bottom -= gRectWindow.top;
	gRectPane.top = (LONG)(gRectWindow.top + ((gRectWindow.bottom - gRectWindow.top) * gConfig.dbDivider));
	gRectPane.bottom = gRectPane.top + 7;
	gRectPane.right = gRectWindow.right;
	if (gConfig.bShowLowerPane)
		gConfig.dbDivider = gConfig.dbSavedDivider;
	else
		gConfig.dbDivider = 1.0;
	gConfig.bShowLowerPane = gConfig.bShowLowerPane == 0;
	
	Command_ShowLowerPane(FALSE);

	gShellIconMsg = RegisterWindowMessageW(L"TaskbarCreated");
	StartBackendThread();

	CTreeList::InitTreeList(ghWndTreeListView, 1);
	SendMessageW(ghMainWnd, WM_TREEVIEW_SORT, IDC_TREEVIEW_LIST, (LPARAM)LOBYTE(gConfig.wProcessImageColumnWidth[1]));
	SetFocus(ghWndTreeListView);
	tagLVITEMW lvItem = { 0 };

	lvItem.iItem = SendMessageW(ghWndTreeListView, LVM_GETNEXTITEM, 0xFFFFFFFF, (LPARAM)LVFI_STRING);
	lvItem.iSubItem = 0;
	lvItem.mask = LVIF_PARAM;
	SendMessageW(ghWndTreeListView, LVM_GETITEMW, 0, (LPARAM)&lvItem);
	//sub_4569D0(lvItem.lParam);

	tagLVITEMW Item = { 0 };

	Item.stateMask = LVIS_FOCUSED| LVIS_SELECTED;
	Item.state = LVIS_FOCUSED | LVIS_SELECTED;;
	SendMessageW(ghWndDllsListCtrl, LVM_SETITEMSTATE, 0, (LPARAM)&Item);
	Item.stateMask = LVIS_FOCUSED | LVIS_SELECTED;
	Item.state = LVIS_FOCUSED | LVIS_SELECTED;
	SendMessageW(ghWndHandlesListCtrl, LVM_SETITEMSTATE, 0, (LPARAM)&Item);

	if (IsBuiltinAdministrative() && !PE_RunTrace(&gProperties, true))
	{
		InsertMenuW(
			hMenuMain,
			IDM_OPTIONS_TRAYICON_COMMIT_HISTORY,
			MF_BYCOMMAND,
			IDM_OPTIONS_COMMIT_DISK_HISTORY,
			L"&Disk History");
		CheckMenuItem(hMenuMain, IDM_OPTIONS_COMMIT_DISK_HISTORY, gConfig.bShowDiskTray ? MF_CHANGE : MF_ENABLED);
		InsertMenuW(
			hMenuMain,
			IDM_OPTIONS_TRAYICON_COMMIT_HISTORY,
			MF_BYCOMMAND,
			IDM_OPTIONS_COMMIT_NETWORK_HISTORY,
			L"&Network History");
		CheckMenuItem(hMenuMain, IDM_OPTIONS_COMMIT_NETWORK_HISTORY, gConfig.bShowNetTray ? MF_CHECKED : MF_ENABLED);
	}
	if (gdwAdapterRuntingTime)
	{
		InsertMenuW(
			hMenuMain,
			IDM_OPTIONS_TRAYICON_COMMIT_HISTORY,
			MF_BYCOMMAND,
			IDM_OPTIONS_COMMIT_GPU_HISTORY,
			L"&GPU History");
		CheckMenuItem(hMenuMain, IDM_OPTIONS_COMMIT_GPU_HISTORY, gConfig.bShowGpuHistory ? MF_CHECKED : MF_ENABLED);
	}

	ghRefreshEventHandle = CreateEventW(0, 0, 0, 0);
	ghEvent2 = CreateEventW(0, 0, 0, 0);
	ghExitEventHandle = CreateEventW(0, 1, 0, 0);
	ghTimerRefreshEvent = CreateEventW(0, 0, 0, 0);
	ghTimerRefreshProcPageEventHandle = CreateEventW(0, 1, 0, 0);
	ghEvent6 = CreateEventW(0, 0, 0, 0);


	///定时刷新线程
	ghBackupRefreshThreadHandle = CreateThread(NULL, 0, BackendRefreshThreadProc, NULL, 0, NULL);

	UINT nMenuID = 0;
	if (gConfig.dwRefreshRate > 2000)
	{
		if (gConfig.dwRefreshRate == 5000)
		{
			nMenuID = IDM_VIEW_UPDATESPEED_FIVE_SECONDS;
			CheckMenuRadioItem(hMenuMain, IDM_VIEW_UPDATESPEED_PAUSED_SPACE, IDM_VIEW_UPDATESPEED_HALF_SECONDS, nMenuID, MF_BYCOMMAND);
		}
		if (gConfig.dwRefreshRate == 10000)
		{
			nMenuID = IDM_VIEW_UPDATESPEED_TEN_SECONDS;
			CheckMenuRadioItem(hMenuMain, IDM_VIEW_UPDATESPEED_PAUSED_SPACE, IDM_VIEW_UPDATESPEED_HALF_SECONDS, nMenuID, MF_BYCOMMAND);
		}
	}
	else
	{
		if (gConfig.dwRefreshRate == 2000)
		{
			nMenuID = IDM_VIEW_UPDATESPEED_TWO_SECONDS;
			CheckMenuRadioItem(hMenuMain, IDM_VIEW_UPDATESPEED_PAUSED_SPACE, IDM_VIEW_UPDATESPEED_HALF_SECONDS, nMenuID, MF_BYCOMMAND);
		}
		if (gConfig.dwRefreshRate)
		{
if (gConfig.dwRefreshRate == 500)
{
	nMenuID = IDM_VIEW_UPDATESPEED_HALF_SECONDS;
	CheckMenuRadioItem(hMenuMain, IDM_VIEW_UPDATESPEED_PAUSED_SPACE, IDM_VIEW_UPDATESPEED_HALF_SECONDS, nMenuID, MF_BYCOMMAND);
}
if (gConfig.dwRefreshRate == 1000)
{
	nMenuID = IDM_VIEW_UPDATESPEED_ONE_SECOND;
	CheckMenuRadioItem(hMenuMain, IDM_VIEW_UPDATESPEED_PAUSED_SPACE, IDM_VIEW_UPDATESPEED_HALF_SECONDS, nMenuID, MF_BYCOMMAND);
}
		}
		else
		{
			CheckMenuRadioItem(
				hMenuMain,
				IDM_VIEW_UPDATESPEED_PAUSED_SPACE,
				IDM_VIEW_UPDATESPEED_HALF_SECONDS,
				IDM_VIEW_UPDATESPEED_PAUSED_SPACE,
				MF_BYCOMMAND);
			//SendMessageW(ghWndStatusBar, SB_SETTEXTW, dword_515720 - 1, L"Paused");
		}
	}

	InvalidateRect(ghWndToolbar, 0, 1);
	//SetCursor(hCursor);
	//if (!gpGraphInfoOfIO)
	//	DeleteMenu(hMenuMain, IDM_OPTIONS_TRAYICON_IO_HISTORY, 0);
	HandleTaskbarCreated();

	gpfnSHAutoComplete = (LPFN_SHAutoComplete)GetProcAddress(LoadLibraryW(L"shlwapi.dll"), "SHAutoComplete");


	if (gConfig.dwOpacity != 100)
	{
		DWORD dwExStyle = GetWindowLongW(ghMainWnd, GWL_EXSTYLE);
		SetWindowLongW(ghMainWnd, GWL_EXSTYLE, dwExStyle | WS_EX_LAYERED);
		SetLayeredWindowAttributes(ghMainWnd, RGB(0,0,0), (BYTE)((255 * gConfig.dwOpacity) / 100), LWA_ALPHA);
		RedrawWindow(ghMainWnd, 0, 0, RDW_ERASE | RDW_INVALIDATE | RDW_ALLCHILDREN | RDW_FRAME);
	}
	nMenuID = (((0x66666667i64 * gConfig.dwOpacity) >> 32) >> 2) + (((0x66666667i64 * gConfig.dwOpacity) >> 32) >> 31) + 40093;
	CheckMenuItem(hMenuMain, nMenuID, MF_CHECKED);
	
	
	if (gbHide)
		CMainWnd::Hide(ghMainWnd);

	return TRUE;
}



//////////////////////////////////////////////////////////////////////////
///
/// CMainWnd::BackendRefreshThreadProc
///	后台刷新线程
///
//////////////////////////////////////////////////////////////////////////
DWORD WINAPI CMainWnd::BackendRefreshThreadProc(void* p)
{
	UNREFERENCED_PARAMETER(p);
	DWORD dwTimeout = INFINITE;
	DWORD dwTimeoutNew = 0;

	HANDLE Handles[] = { ghRefreshEventHandle,ghTimerRefreshEvent,ghEvent2,ghExitEventHandle };
	if (gNetClrMemoryPerfInfoLoaded)
		CoInitialize(NULL);
	SetErrorMode(SEM_FAILCRITICALERRORS);
	if (gConfig.dwRefreshRate)
		dwTimeout = gConfig.dwRefreshRate;
	DWORD dwRet = 0;

	for (dwRet = WaitForMultipleObjects(4, Handles, FALSE, dwTimeout);
		dwRet != WAIT_OBJECT_0 + 3;	///ghExitEventHandle
		dwRet = WaitForMultipleObjects(4, Handles, FALSE, dwTimeoutNew))
	{
		if (dwRet == WAIT_OBJECT_0 + 2)	///ghEvent2
		{
			gdwValue_4F10B8[0] = gdwValue_4F10B8[1] = gdwValue_4F10B8[2] = -1;
		}

		if (gConfig.dwRefreshRate || dwRet != WAIT_TIMEOUT)
		{
			///定时更新ghWndSysinfoPropSheet窗口
			if (ghWndSysinfoPropSheet)
			{
				PostMessage(ghWndSysinfoPropSheet, WM_TIMER, 0, 0);
			}
			gdwRefreshCount++;

			if (gbETWFlagsInProcPropSheet)
			{
				PE_RunTrace(&gProperties, TRUE);
			}

			if (dwRet != WAIT_OBJECT_0 + 2)///ghEvent2
			{
				DWORD dwTick = GetTickCount();
				if ((dwTick - gdwRefresTickCountLast) > 10000)
				{
					///更新GraphInfo
					GraphInfo_Refresh(&gIOGraphInfo);
					GraphInfo_Refresh(&gNetworkGraphInfo);
					GraphInfo_Refresh(&gDiskGraphInfo);

					gdwRefresTickCountLast = dwTick;
				}


				///更新内存
				double dbRatio = 0.0009765625;

				MEMORYSTATUSEX MemoryStatusEx = { sizeof(MemoryStatusEx) };
				GlobalMemoryStatusEx(&MemoryStatusEx);
				double dbValue = MemoryStatusEx.ullTotalPageFile*dbRatio;
				if (dbValue > gpGraphInfoOfMemory->m_dbMemorySize)
					gpGraphInfoOfMemory->m_dbMemorySize = dbValue;
				dbValue = MemoryStatusEx.ullTotalPhys*dbRatio;

				if (dbValue > gpGraphInfoOfPhysicalMemory->m_dbMemorySize)
					gpGraphInfoOfPhysicalMemory->m_dbMemorySize = dbValue;
			}

			BOOL fUpdateTreeView = FALSE;
			///更新TreeViewList
			if (dwRet != WAIT_OBJECT_0 + 2)
			{
				fUpdateTreeView = CTreeList::InitTreeList(ghWndTreeListView, dwRet == WAIT_OBJECT_0 + 1);	///ghTimerRefreshEvent
				PulseEvent(ghTimerRefreshProcPageEventHandle);
				PostMessage(ghWndCPUGraph, WM_GRAPH_REFRESH, 0, 0);
				PostMessage(ghWndMemoryGraph, WM_GRAPH_REFRESH, 0, 0);
				PostMessage(ghWndPhysicalMemoryGraph, WM_GRAPH_REFRESH, 0, 0);
				if (ghWndIOGraph)
					PostMessage(ghWndIOGraph, WM_GRAPH_REFRESH, 0, 0);
				if (ghWndNetworkGraph)
					PostMessage(ghWndNetworkGraph, WM_GRAPH_REFRESH, 0, 0);
				if (ghWndDiskGraph)
					PostMessage(ghWndDiskGraph, WM_GRAPH_REFRESH, 0, 0);
				if (ghWndGPUGraph)
					PostMessage(ghWndGPUGraph, WM_GRAPH_REFRESH, 0, 0);
			}
			bool bUpdateList1 = false;
			bool bUpdateList2 = false;
			if (!gbMainWndMinimized)
			{
				if (gdwProcessIdSelected == -1)	//GetCurrentProcessId();
				{
					gdwValue_4F10B8[0] = -2;
					gdwValue_4F10B8[1] = -2;
					gdwValue_4F10B8[2] = -1;

					if (gConfig.bShowDllView)
						ListView_DeleteAllItems(ghWndDllsListCtrl);
					else
						ListView_DeleteAllItems(ghWndHandlesListCtrl);
				}
				else if (gConfig.bShowDllView)
				{
					bUpdateList1 = RefreshDllsView(ghWndDllsListCtrl, gdwProcessIdSelected, 0);
				}
				else
				{
					bUpdateList2 = RefreshHandlesView(ghWndHandlesListCtrl, gdwProcessIdSelected, 0);
				}
			}

			++ gdwRefreshCount;
			if(fUpdateTreeView)
				PostMessage(ghMainWnd, WM_TREEVIEW_SORT, IDC_TREEVIEW_LIST, LOBYTE(gConfig.wProcessImageColumnWidth[1]));
			if (bUpdateList2)
				PostMessage(ghMainWnd, WM_TREEVIEW_SORT, IDC_LISTCTRL_HANDLES, 0);
			if(bUpdateList1)
				PostMessage(ghMainWnd, WM_TREEVIEW_SORT, IDC_LISTCTRL_DLLS, 0);

		}

		dwTimeoutNew = INFINITE;
		if (gConfig.dwRefreshRate)
			dwTimeoutNew = gConfig.dwRefreshRate;
	}

	return 0;
}

//////////////////////////////////////////////////////////////////////////
///
///
///
///
///
///
///
//////////////////////////////////////////////////////////////////////////
BOOL UpdateMenuStatus(BOOL bEnabled, int nPos)
{
	HMENU hMainMenu = GetMenu(ghMainWnd);
	HMENU hSubMenu = GetSubMenu(hMainMenu, nPos);
	int nCount = GetMenuItemCount(hSubMenu);
	for (int nIndex = 0; nIndex < nCount; nIndex++)
	{
		UINT nID = GetMenuItemID(hSubMenu, nIndex);
		if (nID == IDM_VIEW_SHOW_UNNAMED_HANDLES_AND_MAPPINGS
			|| nID == IDM_OPTIONS_HIGHLIGHT_RELOCATED_DLLS)
		{

		}
		else
		{
			EnableMenuItem(hSubMenu, nIndex, (bEnabled == TRUE ? MF_ENABLED : MF_GRAYED) | MF_BYPOSITION);
		}
		if (nID == IDM_PROCESS_PROPERTIES)
			break;
		if (nID == IDM_PROCESS_KILL_PROCESS)
		{
			SendMessage(ghWndToolbar, TB_ENABLEBUTTON, nID, bEnabled);
		}
	}
	return TRUE;
}

//////////////////////////////////////////////////////////////////////////
///
///
///
///
///
///
///
//////////////////////////////////////////////////////////////////////////
BOOL CMainWnd::Draw(int nColumn, HDC hDC, COLORREF* pColorReturned)
{
	if (!gConfig.bShowColumnHeatmaps)
		return FALSE;

	double dbValue = 0.0;
	COLORREF color;
	UINT nID = gConfig.dwProcessColumnMap[nColumn];
	if (nID == IDS_GPU2)// > IDS_WORKING_SET)
	{
		//if (nID != IDS_GPU2)
		//	return FALSE;
		GraphData_QueryData(gpGraphInfoOfGPU, &dbValue, NULL);
		color = RGB(128, 128, 255);
		dbValue = dbValue / gpGraphInfoOfGPU->m_dbMemorySize;
	}
	else if (nID == IDS_WORKING_SET)
	{
		GraphData_QueryData(gpGraphInfoOfPhysicalMemory, &dbValue, NULL);
		color = RGB(64, 128, 255);
		dbValue = dbValue / gpGraphInfoOfPhysicalMemory->m_dbMemorySize;
	}
	else if (nID == IDS_CPU)
	{
		GraphData_QueryData(gpGraphInfoOfCPU, &dbValue, NULL);
		color = RGB(60, 148, 60);
		dbValue = dbValue / gpGraphInfoOfCPU->m_dbMemorySize;
		if (dbValue > 100.0)
			dbValue = 100.0;

	}
	else if (nID == IDS_PRIVATE_BYTES)
	{
		GraphData_QueryData(gpGraphInfoOfMemory, &dbValue, NULL);
		color = RGB(0, 130, 160);
		dbValue = dbValue / gpGraphInfoOfMemory->m_dbMemorySize;
	}
	WORD wHue = 0, wLuminance = 0, wSaturation = 0;
	ColorRGBToHLS(color, &wHue, &wLuminance, &wSaturation);

	if (wLuminance)
	{
		double db = 5 * (46 - (dbValue*100.0) / 5);
		if (dbValue == 0.0)
			db = 230;
		wLuminance = (WORD)db;
		color = ColorHLSToRGB(wHue, wLuminance, wSaturation);
		*pColorReturned = color;
		if (wLuminance < 110)
		{
			SetTextColor(hDC, RGB(255, 255, 255));
		}
		else
		{
			SetTextColor(hDC, RGB(0, 0, 0));
		}
		SetBkColor(hDC,color);
	}

	return wLuminance != 0;
}

//////////////////////////////////////////////////////////////////////////
///
///
///
///
///
///
///
//////////////////////////////////////////////////////////////////////////
HCURSOR CMainWnd::GetDynamicCursor(int nColumn, int nIndex)
{
	if (gConfig.dwProcessColumnMap[nIndex] == IDS_VIRUSTOTAL)
	{
		return LoadCursor(ghInstance, MAKEINTRESOURCE(IDC_PE_HAND));
	}
	return NULL;
}

//////////////////////////////////////////////////////////////////////////
///
///
///
///
///
///
///
//////////////////////////////////////////////////////////////////////////
bool CMainWnd::RefreshDllsView(HWND hWndList, UINT nID, LPARAM lParam)
{
	return true;
}

//////////////////////////////////////////////////////////////////////////
///
///
///
///
///
///
///
//////////////////////////////////////////////////////////////////////////
bool CMainWnd::RefreshHandlesView(HWND hWndList, UINT nID, LPARAM lParam)
{

	if (!lParam && (!gConfig.dwHandleColumnCount || !gConfig.bShowLowerPane))
		return false;

	QuerySystemHandleInfo(lParam != 0);

	return true;
}

//////////////////////////////////////////////////////////////////////////
///
///
///
///
///
///
///
//////////////////////////////////////////////////////////////////////////
void InitStatusBar(HWND hWndSB)
{

}
//////////////////////////////////////////////////////////////////////////
///
///
///
///
///
///
///
//////////////////////////////////////////////////////////////////////////
void Command_ShowLowerPane(HWND hWnd)
{


}
//////////////////////////////////////////////////////////////////////////
///
///
///
///
///
///
///
//////////////////////////////////////////////////////////////////////////
extern DWORD WINAPI BackendThreadProc(void *p);
void StartBackendThread()
{
	gBackendThreadLock.Init();
	CreateThread(NULL, 0, BackendThreadProc, NULL, 0, NULL);
}
//////////////////////////////////////////////////////////////////////////
///
///
///
///
///
///
///
//////////////////////////////////////////////////////////////////////////
LRESULT HandleMsgHandler(MSGHANDLER* pMsgHander, HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	BOOL bFound = FALSE;
	if (pMsgHander->nLength > 0)
	{
		for (UINT nIndex = 0; nIndex < pMsgHander->nLength; nIndex++)
		{
			bFound = pMsgHander->WindowMsgFunc[nIndex].msg == msg;
			if (bFound)
			{
				return pMsgHander->WindowMsgFunc[nIndex].pfn(hWnd, msg, wParam, lParam);
			}
		}
	}


	if (!bFound || pMsgHander->nLength <= 0)
	{
		switch (pMsgHander->Flags)
		{
		case MSG_Windows:
			return DefWindowProc(hWnd, msg, wParam, lParam);
		case MSG_Dialogs:
			return DefDlgProc(hWnd, msg, wParam, lParam);
		case MSG_MDIChild:
			return DefMDIChildProc(hWnd, msg, wParam, lParam);
		case MSG_Frame:
			return DefFrameProc(hWnd, 0, msg, wParam, lParam);
		default:
			return 0;
		}
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}
//////////////////////////////////////////////////////////////////////////
///
///
///
///
///
///
///
//////////////////////////////////////////////////////////////////////////
LRESULT CALLBACK CMainWnd::MainWndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if (msg == gShellIconMsg)
		HandleTaskbarCreated();

	return HandleMsgHandler(&gMsgHandler, hWnd, msg, wParam, lParam);
}
//////////////////////////////////////////////////////////////////////////
///
///
///
///
///
///
///
//////////////////////////////////////////////////////////////////////////
BOOL InitDrawEngine()
{
	RegDeleteKeyW(HKEY_CURRENT_USER, L"Software\\Systems Internals\\Process Explorer");

	ZeroMemory(&gConfig, sizeof(gConfig));

	gConfig.WindowPlacement[Windowplacement].showCmd = SW_SHOWNORMAL;
	gConfig.WindowPlacement[Windowplacement].rcNormalPosition.top = MulDiv(50, gLogPixelSize.cy, 96);
	gConfig.WindowPlacement[Windowplacement].rcNormalPosition.bottom = MulDiv(650, gLogPixelSize.cy, 96);
	gConfig.WindowPlacement[Windowplacement].rcNormalPosition.left = MulDiv(100, gLogPixelSize.cx, 96);
	gConfig.WindowPlacement[Windowplacement].rcNormalPosition.right = MulDiv(900, gLogPixelSize.cx, 96);
	gConfig.WindowPlacement[Windowplacement].length = sizeof(WINDOWPLACEMENT);
	gConfig.WindowPlacement[FindWindowplacement].rcNormalPosition.top = MulDiv(150, gLogPixelSize.cy, 96);
	gConfig.WindowPlacement[FindWindowplacement].rcNormalPosition.left = MulDiv(150, gLogPixelSize.cx, 96);
	gConfig.WindowPlacement[FindWindowplacement].length = sizeof(WINDOWPLACEMENT);
	gConfig.WindowPlacement[PropWindowplacement].rcNormalPosition.top = MulDiv(40, gLogPixelSize.cy, 96);
	gConfig.WindowPlacement[PropWindowplacement].rcNormalPosition.left = MulDiv(40, gLogPixelSize.cx, 96);
	gConfig.WindowPlacement[PropWindowplacement].length = sizeof(WINDOWPLACEMENT);
	gConfig.WindowPlacement[DllPropWindowplacement].rcNormalPosition.top = MulDiv(40, gLogPixelSize.cy, 96);
	gConfig.WindowPlacement[DllPropWindowplacement].rcNormalPosition.left = MulDiv(40, gLogPixelSize.cx, 96);
	gConfig.WindowPlacement[DllPropWindowplacement].length = sizeof(WINDOWPLACEMENT);
	gConfig.WindowPlacement[SysinfoWindowplacement].rcNormalPosition.top = MulDiv(40, gLogPixelSize.cy, 96);
	gConfig.WindowPlacement[SysinfoWindowplacement].rcNormalPosition.left = MulDiv(40, gLogPixelSize.cx, 96);
	gConfig.WindowPlacement[SysinfoWindowplacement].length = sizeof(WINDOWPLACEMENT);
	//gConfig.dwToolbarBands = -1;
	//gConfig.dwGraphReBarCtrlIds[2] = -1;
	//gConfig.dwGraphReBarCtrlIds[5] = -1;
	//gConfig.dwGraphReBarCtrlIds[8] = -1;
	//gConfig.dwGraphReBarCtrlIds[11] = -1;
	//gConfig.dwGraphReBarCtrlIds[14] = -1;
	//gConfig.dwGraphReBarCtrlIds[17] = -1;
	//gConfig.dwGraphReBarCtrlIds[20] = -1;

	static tagCOLUMNKEYITEM gProcessColumnWidth[] = {
		{1055, 40},
		{1060, 80},
		{1063, 80},
		{4, 40},
		{38, 150},
		{1033, 140}
	};

	gConfig.dwProcessColumnCount = sizeof(gProcessColumnWidth) / sizeof(*gProcessColumnWidth);

	DWORD index = 0;

	for (index = 0; index < gConfig.dwProcessColumnCount; index++)
	{
		gConfig.dwProcessColumnMap[index] = gProcessColumnWidth[index].wID;
		gConfig.dwProcessColumns[index] = MulDiv(gProcessColumnWidth[index].nWidth, gLogPixelSize.cx, 96);
	}

	static tagCOLUMNKEYITEM gHandleColumns[] =
	{
		{ 31,100 },
		{ 32,450 }
	};
	gConfig.dwHandleColumnCount = sizeof(gHandleColumns) / sizeof(*gHandleColumns);
	for (index = 0; index < gConfig.dwHandleColumnCount; index++)
	{
		gConfig.dwIdsOfHandleColumnMap[index] = gHandleColumns[index].wID;
		gConfig.dwHandleColumns[index] = MulDiv(gHandleColumns[index].nWidth, gLogPixelSize.cx, 96);
	}

	static tagCOLUMNKEYITEM gDllColumns[] =
	{
		{ 26,110 },
		{ 42, 180 },
		{ 1033, 140 },
		{ 1111, 300 },

	};

	gConfig.dwDllColumnCount = sizeof(gDllColumns) / sizeof(*gDllColumns);
	for (index = 0; index < gConfig.dwDllColumnCount; index++)
	{
		gConfig.dwDllColumnMap[index] = gDllColumns[index].wID;
		gConfig.dwDllColumns[index] = MulDiv(gDllColumns[index].nWidth, gLogPixelSize.cx, 96);
	}

	HFONT hFont = (HFONT)GetStockObject(DEFAULT_GUI_FONT);
	LOGFONTW LogFont = { 0 };
	GetObject(hFont, sizeof(LOGFONTW), &LogFont);

	LogFont.lfWeight = FW_NORMAL;
	LogFont.lfHeight = MulDiv(8, gLogPixelSize.cy, 72);
	CopyMemory(&gConfig.UnicodeFont, &LogFont, sizeof(LOGFONTW));

	tagRegKeyInfo RegKeyInfo;
	RegKeyInfo.szKeyName = _wcsdup(L"Software\\Sysinternals\\Process Explorer");

	LoadConfigItemFromRegistry(&RegKeyInfo, gConfigItems);

	if (LogFont.lfHeight > 0)
	{
		gConfig.UnicodeFont.lfHeight = -MulDiv(gConfig.UnicodeFont.lfHeight, gLogPixelSize.cy, 72);
	}

	HKEY hSubKey = NULL;
	if (!RegOpenKeyExW(HKEY_CURRENT_USER, L"Software\\Sysinternals\\Process Explorer",0,KEY_READ, &hSubKey))
	{
		DWORD cbSize = 1784;
		DWORD dwValue = 0;
		if (!RegQueryValueExW(hSubKey, L"Settings", NULL, NULL, (LPBYTE)&dwValue, &cbSize)
			&& dwValue <= 821)
		{

		}


		RegCloseKey(hSubKey);
	}

	index = 0;
	if (gConfig.dwProcessColumnCount > 0)
	{
		SHORT* pwProcessColumns = gConfig.dwProcessColumns;
		int* pdwProcessColumnMap = gConfig.dwProcessColumnMap;
		do
		{
			if (*pdwProcessColumnMap == 3)
			{
				memmove(pdwProcessColumnMap, pdwProcessColumnMap + 1, sizeof(DWORD) * (--gConfig.dwProcessColumnCount - index));
				memmove(pwProcessColumns, pwProcessColumns + 1, sizeof(WORD) * (gConfig.dwProcessColumnCount - index));
			}
			++index;
			++pdwProcessColumnMap;
			++pwProcessColumns;
		} while (index < gConfig.dwProcessColumnCount);
	}

	index = 0;
	if (gConfig.dwProcessColumnCount > 0)
	{
		do
		{
			if (gConfig.dwProcessColumnMap[index] == IDS_PID)
			{
				if (gConfig.bETWStandardUserWarning)
					break;
			}
			else if (!IsBuiltinAdministrative() && !gConfig.bETWStandardUserWarning)
			{
				int uID = gConfig.dwProcessColumnMap[index];
				if (uID >= IDS_NETWORK_RECEIVES && uID <= IDS_DISK_DELTA_TOTAL_BYTES)
				{
					gConfig.bETWStandardUserWarning = true;
					MessageBoxW(
						0,
						L"Note that Disk and Networking information requires administrative rights",
						L"Process Explorer",
						MB_ICONEXCLAMATION);
					if (index != -1)
					{
						gConfig.dwProcessColumnMap[index] = IDS_PID;
						gConfig.dwProcessColumns[index] = 200;
						++gConfig.dwProcessColumnCount;
					}
				}
			}
			++index;
		} while (index < gConfig.dwProcessColumnCount);
	}

	if (index != -1)
	{
		gConfig.dwProcessColumnMap[index] = IDS_PID;
		gConfig.dwProcessColumns[index] = 200;
		++gConfig.dwProcessColumnCount;
	}

	index = 0;
	if (gConfig.dwNumColumnsets > 0)
	{
		do
		{
			RegVar_ReadWrite(FALSE, index, &gConfig.strMenuCulumnSet[index]);
			index++;
		} while (index < gConfig.dwNumColumnsets);
	}

	if (!gConfig.strNtSymbolPath[0])
		GetEnvironmentVariableW(L"_NT_SYMBOL_PATH", gConfig.strNtSymbolPath, _MAX_PATH);

	ghConfigFont = CreateFontIndirectW(&gConfig.UnicodeFont);

	CopyMemory(&LogFont, &gConfig.UnicodeFont, sizeof(LogFont));
	
	LogFont.lfUnderline = TRUE;
	
	ghConfigUnderlineFont = CreateFontIndirectW(&LogFont);


	free(RegKeyInfo.szKeyName);

	return TRUE;
}

//////////////////////////////////////////////////////////////////////////
///
///
///
///
///
///
///
//////////////////////////////////////////////////////////////////////////
ULONG QueryTagInformation(PVOID* ppv, PDWORD pdwValue2, PDWORD pdwValue3, PDWORD pdwValue4)
{
	///pfnI_QueryTagInformation = (FN_I_QueryTagInformation)GetProcAddress(advapi32, "I_QueryTagInformation");
	/*ServiceNameTagMappingInformation;*/

	gpfn_I_QueryTagInformation = (LPFN_I_QueryTagInformation)
		::GetProcAddress(LoadLibraryW(L"Advapi32.dll"), "I_QueryTagInformation");
	if (gpfn_I_QueryTagInformation == NULL)
		return -1;

	TAG_INFO_NAME_TAG_MAPPING* pBuffer = (TAG_INFO_NAME_TAG_MAPPING*)LocalAlloc(LMEM_ZEROINIT, 1024);


	ULONG ret = gpfn_I_QueryTagInformation(NULL, eTagInfoLevelNameTagMapping, pBuffer);
	if (!ret)
	{
		//WCHAR szBuffer[_MAX_PATH] = { 0 };
		//for (DWORD dwIndex = 0; dwIndex < pBuffer->pOutParams->cElements; dwIndex++)
		//{
		//	wsprintfW(szBuffer,L"%x, %x, %s\r\n", pBuffer->pOutParams->pNameTagMappingElements[dwIndex].dwTag, pBuffer->pOutParams->pNameTagMappingElements[dwIndex].eTagType, pBuffer->pOutParams->pNameTagMappingElements[dwIndex].pszName);
		//	OutputDebugStringW(szBuffer);
		//}
	}

	return ret;


}
//////////////////////////////////////////////////////////////////////////
///
///
///
///
///
///
///
//////////////////////////////////////////////////////////////////////////
BOOL OnBeforeInit()
{
	PVOID pOutBuffer = NULL;

	ghMainInstance = ghInstance;
	gdwVirtualScreenWidth = gcxFullScreen;
	if (!gdwVirtualScreenWidth)
		gdwVirtualScreenWidth = gcxScreen;
	gdwVirtualScreenWidth = gdwVirtualScreenWidth / 2;

	gpSystemPerformanceInfo = (SYSTEM_PROCESSOR_PERFORMANCE_INFORMATION*)malloc(sizeof(SYSTEM_PROCESSOR_PERFORMANCE_INFORMATION) * gSystemInfo.dwNumberOfProcessors);
	gpSystemInterruptInfo = (SYSTEM_INTERRUPT_INFORMATION*)malloc(sizeof(SYSTEM_INTERRUPT_INFORMATION) * gSystemInfo.dwNumberOfProcessors);
	gpSystemProcessorCycleTimeInfo = (SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION*)malloc(sizeof(SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION)*gSystemInfo.dwNumberOfProcessors);


	TmAdjustPrivilege(TEXT("SeDebugPrivilege"));
	TmAdjustPrivilege(TEXT("SeBackupPrivilege"));
	TmAdjustPrivilege(TEXT("SeSecurityPrivilege"));

	if (!theDriver.Load())
	{
	}

	pOutBuffer = VirtualAlloc(NULL, sizeof(DWORD), MEM_COMMIT, PAGE_READWRITE);
	DWORD dwValue = 152;

	if (theDriver.Control(CTRLCODE_LOAD_DRIVER_VERSION, &dwValue, sizeof(DWORD), pOutBuffer, sizeof(DWORD)))
	{
		DWORD dwOutValue = *(DWORD*)pOutBuffer;

		if (dwOutValue < dwValue)
		{
			theDriver.Close();
			theDriver.Load();
			theDriver.Control(CTRLCODE_LOAD_DRIVER_VERSION, &dwValue, sizeof(DWORD), pOutBuffer, sizeof(DWORD));
			dwOutValue = *(DWORD*)pOutBuffer;

			if (dwOutValue >= dwValue)
			{
				return 0;
			}
			//MessageBoxW(
			//	0,
			//	L"Driver version mismatch. You must reboot before you can run this version of Process Explorer.",
			//	L"Process Explorer",
			//	MB_ICONERROR);
		}
		VirtualFree(pOutBuffer, sizeof(DWORD), MEM_DECOMMIT);
	}


#define STATUS_INVALID_INFO_CLASS	0xC0000003
#define STATUS_NOT_IMPLEMENTED		0xC0000002

	///
	if (LoadSystemApis())
	{
		if (gpfnNtQuerySystemInformation == NULL)
			gpfnNtQuerySystemInformation = (LPFN_NtQuerySystemInformation)
			GetProcAddress(GetModuleHandleW(L"NTDLL.DLL"), "NtQuerySystemInformation");

		NTSTATUS Status = gpfnNtQuerySystemInformation(SystemExtendedHandleInformation, NULL, 0, NULL);
		if (Status == STATUS_INVALID_INFO_CLASS
			|| (gbSupportExtendedSystemHandleInformation&&Status == STATUS_NOT_IMPLEMENTED))
		{
			gbSupportExtendedSystemHandleInformation = false;
		}

		ghSCManagerHandle = OpenSCManagerW(NULL, NULL, SC_MANAGER_ENUMERATE_SERVICE);

		if (IsWinServer())
		{
			gbProcessIdToSessionIdValid = true;
			///ProcessIdToSessionId()
		}

		gServiceLock.Init();

		GetDriverNameAndLinkInfo();


		////LoadNetClrMemoryPerformanceInfo();

		if (gdwVersion > WINDOWS_VISTA)
		{

			/// sub_456750();
			///_I_QueryTagInformation()
		}
	}
	

	return TRUE;
}

INT_PTR CALLBACK DlgSymbolConfig(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
//////////////////////////////////////////////////////////////////////////
///
///
///
///
///
///
///
//////////////////////////////////////////////////////////////////////////
BOOL OpenSymbolConfigDlg(HWND hWndParent)
{
	DialogBoxParam(ghInstance, MAKEINTRESOURCE(IDD_SYMBOLCONFIG), hWndParent, DlgSymbolConfig, 0);
	return 0;
}
//////////////////////////////////////////////////////////////////////////
///
///
///
///
///
///
///
//////////////////////////////////////////////////////////////////////////
BOOL BrowseSymbolPath(HWND hWnd, LPWSTR pszPath)
{
	void *pBuffer = NULL;
	BOOL result = FALSE;
	const ITEMIDLIST *pItemList = NULL;
	_browseinfoW bi = { 0 };
	LPITEMIDLIST pidl = NULL;
	IMalloc *pMalloc = NULL; 

	SHGetMalloc(&pMalloc);
	pBuffer = pMalloc->Alloc(MAX_PATH);
	if (!pBuffer)
		return FALSE;

	if (SHGetSpecialFolderLocation(hWnd, 0, &pidl) >= 0)
	{
		bi.pidlRoot = pidl;
		bi.hwndOwner = hWnd;
		bi.pszDisplayName = pszPath;
		bi.lpszTitle = L"Browse for Symbols Directory";
		bi.ulFlags = BIF_RETURNONLYFSDIRS | BIF_EDITBOX;
		bi.lpfn = 0;
		bi.lParam = 0;
		pItemList = SHBrowseForFolderW(&bi);
		if (pItemList)
		{
			SHGetPathFromIDListW(pItemList, pszPath);
			pMalloc->Free((void*)pItemList);
			pMalloc->Free(pidl);
			pMalloc->Free(pBuffer);
			result = TRUE;
		}
		else
		{
			pMalloc->Free(pidl);
			pMalloc->Free(pBuffer);
			result = FALSE;
		}
	}
	else
	{
		pMalloc->Free(pBuffer);
		result = FALSE;
	}
	return result;
}

//////////////////////////////////////////////////////////////////////////
///
///
///
///
///
///
///
//////////////////////////////////////////////////////////////////////////
INT_PTR CALLBACK DlgSymbolConfig(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	WCHAR szPath[_MAX_PATH] = { 0 };
	if (uMsg == WM_INITDIALOG)
	{
		SetDlgItemText(hWnd, IDC_DLG_SYMBOLCONFIG_EDIT_DBGHELPDLL_PATH, gConfig.strDbgHelpModuleName);
		SetDlgItemText(hWnd, IDC_DLG_SYMBOLCONFIG_EDIT_SYMBOLS_PATH, gConfig.strNtSymbolPath);
		if (gpfnSHAutoComplete)
		{
			gpfnSHAutoComplete(GetDlgItem(hWnd, IDC_DLG_SYMBOLCONFIG_EDIT_DBGHELPDLL_PATH), SHACF_FILESYSTEM);
		}
		SetFocus(GetDlgItem(hWnd, IDC_DLG_SYMBOLCONFIG_EDIT_DBGHELPDLL_PATH));
		return 1;
	}
	if (uMsg == WM_COMMAND)
	{
		UINT uID = LOWORD(wParam);
		if (uID == IDC_DLG_SYMBOLCONFIG_BUTTON_BROWSE_SYMBOLS_PATH)
		{
			HWND hWndEdit = GetDlgItem(hWnd,IDC_DLG_SYMBOLCONFIG_EDIT_SYMBOLS_PATH);
			GetWindowTextW(hWndEdit, szPath, _MAX_PATH);
			if (BrowseSymbolPath(hWnd, szPath))
			{
				SetWindowTextW(hWndEdit, szPath);
			}
		}
		else if (uID == IDC_DLG_SYMBOLCONFIG_BUTTON_BROWSE_DBGHELPDLL_PATH)
		{
			HWND hWndEdit = GetDlgItem(hWnd,IDC_DLG_SYMBOLCONFIG_EDIT_DBGHELPDLL_PATH);
			GetWindowTextW(hWndEdit, szPath, _MAX_PATH);
			tagOFNW OpenFileName = { 0 };
			OpenFileName.lStructSize = sizeof(tagOFNW);
			OpenFileName.hInstance = ghInstance;
			OpenFileName.lpstrFile = szPath;
			OpenFileName.hwndOwner = hWnd;
			OpenFileName.nMaxFile = 256;
			OpenFileName.Flags = OFN_LONGNAMES;
			OpenFileName.lpstrTitle = L"Specify dbghelp.dll...";
			OpenFileName.lpstrDefExt = L"*.dll";
			OpenFileName.lpstrFilter = L"Dbghelp DLL(dbghelp.dll)";
			if (GetOpenFileNameW(&OpenFileName))
			{
				SetWindowTextW(hWndEdit, szPath);
			}
		}
		else if (uID == IDOK)
		{
			HWND hWndEdit = GetDlgItem(hWnd,IDC_DLG_SYMBOLCONFIG_EDIT_DBGHELPDLL_PATH);
			GetWindowTextW(hWndEdit, szPath, _MAX_PATH);
			if (LoadDbgHelp(szPath))
			{
				GetDlgItemTextW(hWnd, IDC_DLG_SYMBOLCONFIG_EDIT_SYMBOLS_PATH, gConfig.strNtSymbolPath, _MAX_PATH);
				wcscpy_s(gConfig.strDbgHelpModuleName, _MAX_PATH, szPath);
				gbDbghelpModuleLoaded = TRUE;
				ShowSymbolConfigWarning(hWnd);
				EndDialog(hWnd, 0);
			}
		}
		else if (uID == IDCANCEL)
		{
			EndDialog(hWnd, 0);
		}
	}

	return	0;
}

void UpdateWindowPlacement(HWND hWnd, BOOL fSave)
{
	CRegSettings Config;
	CopyMemory(&Config, &gConfig, sizeof(CRegSettings));
	gConfig.WindowPlacement[Windowplacement].length = sizeof(WINDOWPLACEMENT);
	GetWindowPlacement(hWnd,&gConfig.WindowPlacement[0]);
	if (gConfig.bShowLowerPane)
		gConfig.dbSavedDivider = gConfig.dbDivider;
	if (ghFindDlg)
	{
		gConfig.WindowPlacement[1].length = sizeof(WINDOWPLACEMENT);
		GetWindowPlacement(ghFindDlg,&gConfig.WindowPlacement[1]);
	}
	if (!gConfig.dwRefreshRate)
	{
		switch (gdwRefreshMenuIDLast)
		{
		case IDM_VIEW_UPDATESPEED_TWO_SECONDS:
			gConfig.dwRefreshRate = 2000;
			break;
		case IDM_VIEW_UPDATESPEED_FIVE_SECONDS:
			gConfig.dwRefreshRate = 5000;
			break;
		case IDM_VIEW_UPDATESPEED_TEN_SECONDS:
			gConfig.dwRefreshRate = 10000;
			break;
		case IDM_VIEW_UPDATESPEED_HALF_SECONDS:
			gConfig.dwRefreshRate = 500;
			break;
		default:
			gConfig.dwRefreshRate = 1000;
			break;
		}
	}

	REBARBANDINFO BandInfo = { sizeof(BandInfo) };
	BandInfo.fMask = RBBIM_ID | RBBIM_SIZE | RBBIM_STYLE;
	for (int i = 0; i < 8; i++)
	{
		SendMessage(ghWndReBar, RB_GETBANDINFO, i, (LPARAM)&BandInfo);
		gConfig.ToolBandInfo[i].nWidth = MulDiv(BandInfo.cx, 96, gLogPixelSize.cx);
		gConfig.ToolBandInfo[i].nID = BandInfo.wID;
		gConfig.ToolBandInfo[i].fBreak = BandInfo.fStyle&RBBS_BREAK;
	}

	gConfig.wProcessImageColumnWidth[0] = LOWORD(SendMessageW(ghWndTreeListView, LVM_GETCOLUMNWIDTH, 0, 0));

}

//////////////////////////////////////////////////////////////////////////
///
///
///
///
///
///
///
//////////////////////////////////////////////////////////////////////////
void ShowSymbolConfigWarning(HWND hWnd)
{
	DWORD dwHandle = 0;
	if (!_wcsnicmp(L"srv*", gConfig.strNtSymbolPath, 4))
	{
		DWORD cbLength = GetFileVersionInfoSizeW(gConfig.strDbgHelpModuleName, &dwHandle);
		void *pVersionInfo = malloc(cbLength);
		if (GetFileVersionInfoW(gConfig.strDbgHelpModuleName, 
			0,
			cbLength,
			pVersionInfo) 
			/*&& *(DWORD*)&pVersionInfo[12] < 0x60000*/)
		{
			//if (hWnd)
			//	DialogBoxParam(ghInstance, MAKEINTRESOURCE(IDD_SYMBOLDBGHELPGWARNING), 0, DlgAbout, 0);
			//else
			//	DialogBoxParam(ghInstance, MAKEINTRESOURCE(IDD_SYMBOLCONFIGWARNING), 0, DlgAbout, 0);
		}
		free(pVersionInfo);
	}
	if (!gConfig.bSymbolWarningShown
		&&!gConfig.strNtSymbolPath[0])
	{
		//DialogBoxParam(ghInstance, MAKEINTRESOURCE(IDD_SYMBOLCONFIGWARNING), 0, DlgAbout, 0);
		gConfig.bSymbolWarningShown = true;
		UpdateWindowPlacement(ghMainWnd, TRUE);
	}
}


//////////////////////////////////////////////////////////////////////////
///
///
///
///
///
///
///
//////////////////////////////////////////////////////////////////////////
LRESULT CMainWnd::HandleCommand(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	UINT nID = (UINT)wParam;
	if (nID == IDM_FILE_EXIT)
		Command_Cancel(hWnd);
	return 0;
}

//////////////////////////////////////////////////////////////////////////
///
///
///
///
///
///
///
//////////////////////////////////////////////////////////////////////////
LRESULT CMainWnd::HandleSize(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return 0;
}

//////////////////////////////////////////////////////////////////////////
///
///
///
///
///
///
///
//////////////////////////////////////////////////////////////////////////
BOOL DrawLine(HWND hWnd, int y)
{
	RECT	rcClient;
	HPEN hPen = CreatePen(PS_COSMETIC, 5, 0);
	GetClientRect(hWnd, &rcClient);
	HDC hDC = GetDC(hWnd);
	HPEN hOldpen = (HPEN)SelectObject(hDC, hPen);
	SetROP2(hDC, R2_NOT);
	MoveToEx(hDC, 0, y + 6, 0);
	LineTo(hDC, rcClient.right, y + 6);
	SelectObject(hDC, hOldpen);
	SetROP2(hDC, R2_NOP);
	ReleaseDC(hWnd, hDC);
	return DeleteObject(hPen);
}

//////////////////////////////////////////////////////////////////////////
///
///
///
///
///
///
///
//////////////////////////////////////////////////////////////////////////
static int gyMouseDown = 0;
LRESULT CMainWnd::HandleLBtnDown(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	POINT pt;
	pt.x = LOWORD(lParam);
	pt.y = HIWORD(lParam);
	if (PtInRect(&gRectPane, pt))
	{
		SetCursor(ghResizeCursor);
		SetCapture(hWnd);
		DrawLine(hWnd, pt.y - 6);
		gyMouseDown = pt.y - 6;
	}
	return 0;
}



//////////////////////////////////////////////////////////////////////////
///
///
///
///
///
///
///
//////////////////////////////////////////////////////////////////////////
LRESULT CMainWnd::HandleLBtnUp(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	int x = LOWORD(lParam);
	int y = HIWORD(lParam);
	if (gbWindowFinding)
	{
		SearchWindow(hWnd);
		return 0;
	}

	if (GetCapture())
	{
		SetCursor(ghResizeCursor);
		ReleaseCapture();
		DrawLine(hWnd, gyMouseDown);
		if (y > gRectWindow.bottom - 30)
		{
			Command_ShowLowerPane(hWnd);
			return 0;
		}
		if (y < gRectWindow.top + 40)
			y = LOWORD(gRectWindow.top) + 40;
		gRectPane.top = y - 3;
		gRectPane.bottom = gRectPane.top + 7;
		gConfig.dbDivider = (y - 3) / (gRectWindow.top + gRectWindow.bottom);
		RECT	rcClient;
		GetClientRect(hWnd, &rcClient);
		////CMainWnd::HandleSize(ghMainWnd, 0, 0, MAKELPARAM(LOWORD(rect.right) - LOWORD(rect.left),
		////	LOWORD(rect.bottom) - LOWORD(rect.top)));

		InvalidateRect(hWnd, &gRectPane, FALSE);

	}
	return 0;
}

//////////////////////////////////////////////////////////////////////////
///
///
///
///
///
///
///
//////////////////////////////////////////////////////////////////////////
LRESULT CMainWnd::HandleMouseMove(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	POINT pt;
	pt.x = LOWORD(lParam);
	pt.y = HIWORD(lParam);

	if (gbWindowFinding)
	{
		ClientToScreen(hWnd, &pt);
		HWND hWndTemp = WindowFromPoint(pt);
		if (hWndTemp != ghWndHungWindow)
		{
			if (ghWndHungWindow)
				DrawHungWindow(ghWndHungWindow);
			while (hWndTemp != ghMainWnd)
			{
				HWND hWndParent = GetParent(hWndTemp);
				if (!hWndParent)
				{
					if (ghMainWnd)
					{
						ghWndHungWindow = hWndTemp;
						DrawHungWindow(hWndTemp);
						SetCursor(LoadCursor(ghInstance, MAKEINTRESOURCE(IDC_FIND)));
						return 0;
					}
					break;
				}
			}
			ghWndHungWindow = NULL;
		}
		SetCursor(LoadCursor(ghInstance, MAKEINTRESOURCE(IDC_FIND)));
		return 0;
	}
	else if (GetCapture())
	{
		if (pt.y > gRectWindow.bottom - 5)
			pt.y = LOWORD(gRectWindow.bottom) - 5;
		if (pt.y < gRectWindow.top + 40)
			pt.y = LOWORD(gRectWindow.top) + 40;
		DrawLine(hWnd, gyMouseDown);
		DrawLine(hWnd, pt.y - 3);
		gyMouseDown = pt.y - 3;
	}
	return 0;
}

//////////////////////////////////////////////////////////////////////////
///
///
///
///
///
///
///
//////////////////////////////////////////////////////////////////////////
LRESULT CMainWnd::HandleDrawItem(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	WM_DRAWITEM;
	UINT nID = (UINT)wParam;
	LPDRAWITEMSTRUCT lpDis = (LPDRAWITEMSTRUCT)lParam;
	if (lpDis->CtlType != ODT_MENU)
		return DrawList(lpDis);
	DrawIconEx(lpDis->hDC,
		lpDis->rcItem.left + 15,
		lpDis->rcItem.top,
		(HICON)lpDis->itemData,
		16,
		16,
		0,
		0,
		DI_IMAGE|DI_MASK);
	return 0;
}

bool QueryListItemColor(HWND hWnd, int nItem, BOOL bFocused, COLORREF* pTextColor, COLORREF *pBackColor)
{

	return false;
}

bool CMainWnd::DrawList(LPDRAWITEMSTRUCT lpDis)
{
	UINT nColumn = GetWindowLongPtr(lpDis->hwndItem, GWLP_USERDATA);
	LVITEM Item = { 0 };
	Item.mask = LVIF_PARAM | LVIF_IMAGE | LVIF_TEXT | LVIF_STATE;
	Item.iItem = lpDis->itemID;
	Item.iSubItem = 0;
	ListView_GetItem(lpDis->hwndItem, &Item);

	return true;
}

//////////////////////////////////////////////////////////////////////////
///
///
///
///
///
///
///
//////////////////////////////////////////////////////////////////////////
LRESULT CMainWnd::HandleGetMinmaxInfo(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	WM_GETMINMAXINFO;
	MINMAXINFO* pInfo = (MINMAXINFO*)lParam;
	pInfo->ptMinTrackSize.x = 200;
	pInfo->ptMinTrackSize.y = 200;
	return 0;
}

//////////////////////////////////////////////////////////////////////////
///
///
///
///
///
///
///
//////////////////////////////////////////////////////////////////////////
LRESULT CMainWnd::HandleNotify(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	NMHDR* pNMHDR = (NMHDR*)lParam;
	if (pNMHDR->code > LVN_GETDISPINFOW)
	{
		switch (pNMHDR->code)
		{
		case LVN_BEGINLABELEDITW:
			return 1;
		/*case LV*/
		default:
			break;
		}
	}
	return 0;
}

//////////////////////////////////////////////////////////////////////////
///
///
///
///
///
///
///
//////////////////////////////////////////////////////////////////////////
LRESULT CMainWnd::HandleMeasureItem(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
///	GetTokenInformation(ProcessHandle, TokenStatistics;
	LPMEASUREITEMSTRUCT lpmis = (LPMEASUREITEMSTRUCT)lParam;
	if (lpmis->CtlType == IDC_LISTCTRL_HANDLES || lpmis->CtlID == IDC_TREEVIEW_LIST)
	{
		TEXTMETRIC tm = { 0 };
		HDC hDC = GetDC(ghWndTreeListView);
		SelectObject(hDC, ghConfigFont);
		if (!GetTextMetrics(hDC, &tm))
			return 0;
		if (lpmis->CtlID == IDC_TREEVIEW_LIST)
		{
			int v6 = tm.tmHeight + 2;
			if (v6 <= GetSystemMetrics(SM_CYSMICON))
				v6 = GetSystemMetrics(SM_CYSMICON);
			lpmis->itemHeight = v6;
		}
		else
		{
			lpmis->itemHeight = tm.tmHeight + 2;
		}
		ReleaseDC(ghWndTreeListView, hDC);
	}
	else if (lpmis->CtlType == ODT_MENU)
	{
		lpmis->itemWidth = 16;
		lpmis->itemHeight = 16;
	}
	return 1;
}

//////////////////////////////////////////////////////////////////////////
///
///
///
///
///
///
///
//////////////////////////////////////////////////////////////////////////
LRESULT CMainWnd::HandleClose(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if (gConfig.bHideWhenMinimized)
		Hide(ghMainWnd);
	else
		HandleDestroy(hWnd, msg, wParam, lParam);
	return 0;
}

//////////////////////////////////////////////////////////////////////////
///
///
///
///
///
///
///
//////////////////////////////////////////////////////////////////////////
LRESULT CMainWnd::HandleEndSession(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	UpdateWindowPlacement(ghMainWnd, TRUE);
	return 0;
}

//////////////////////////////////////////////////////////////////////////
///
///
///
///
///
///
///
//////////////////////////////////////////////////////////////////////////
LRESULT CMainWnd::HandleDestroy(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	ShowWindow(hWnd, SW_HIDE);
	UpdateWindowPlacement(ghMainWnd, TRUE);
	for (int i = 0; i < 8; i++)
	{
		TrayIcon_Delete(hWnd, i);
	}
	SetEvent(ghExitEventHandle);
	PE_RunTrace(&gProperties, false);
	///关闭后台刷新线程
	TerminateThread(ghBackupRefreshThreadHandle, 0);
	TerminateThread(GetCurrentThread(), 0);
	PostQuitMessage(0);
	GRAY_BRUSH;
	return 0;
}

//////////////////////////////////////////////////////////////////////////
///
///
///
///
///
///
///
//////////////////////////////////////////////////////////////////////////
LRESULT CMainWnd::HandleSetFocus(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	gdwTickCountSetFocusLast = GetTickCount();
	if (ghWndFocusedLast)
	{
		SetFocus(ghWndFocusedLast);
		return 1;
	}
	else if (hWnd == ghMainWnd)
	{
		SetFocus(ghWndTreeListView);
		return 1;
	}
	return 0;
}

//////////////////////////////////////////////////////////////////////////
///
///
///
///
///
///
///
//////////////////////////////////////////////////////////////////////////
LRESULT CMainWnd::HandleKillFocus(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	ghWndFocusedLast = GetFocus();
	return 1;
}

//////////////////////////////////////////////////////////////////////////
///
///
///
///
///
///
///
//////////////////////////////////////////////////////////////////////////
LRESULT CMainWnd::HandleSysCommand(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	WM_SYSCOMMAND;
	if (!gConfig.bHideWhenMinimized || wParam != SC_MINIMIZE)
		return DefWindowProcW(hWnd, msg, wParam, lParam);
	gbMainWndMinimized = true;
	CMainWnd::Hide(hWnd);
	return 0;
}

BOOL RefreshMenuWithTreeViewItemStatus(tagTREEVIEWITEMPARAM* pItem)
{
	HMENU hMainMenu = GetMenu(ghMainWnd);
	HWND hWnd = QueryTopMostWindowByProcessID(pItem->dwProcessId);
	pItem->hMainWndBackup = hWnd;
	if (hWnd)
	{
		HMENU hProcessMenu = GetSubMenu(hMainMenu, MAINMENU_Process);
		EnableMenuItem(hProcessMenu, 0, MF_BYPOSITION);
		EnableMenuItem(hMainMenu, IDM_PROCESS_WINDOW_BRING_TO_FRONT, MF_ENABLED);
		EnableMenuItem(hMainMenu, IDM_PROCESS_WINDOW_CLOSE, MF_ENABLED);
		EnableMenuItem(hMainMenu, IDM_PROCESS_WINDOW_RESTORE, (!IsIconic(pItem->hMainWndBackup) && !IsZoomed(pItem->hMainWndBackup)));
		EnableMenuItem(hMainMenu, IDM_PROCESS_WINDOW_MINIMIZE, IsIconic(pItem->hMainWndBackup));
		return EnableMenuItem(hMainMenu, IDM_PROCESS_WINDOW_MAXIMIZE, IsZoomed(pItem->hMainWndBackup));
	}
	else
	{
		HMENU hProcessMenu = GetSubMenu(hMainMenu, MAINMENU_Process);
		EnableMenuItem(hProcessMenu, 0, MF_GRAYED | MF_BYPOSITION);
		EnableMenuItem(hMainMenu, IDM_PROCESS_WINDOW_BRING_TO_FRONT, MF_GRAYED);
		EnableMenuItem(hMainMenu, IDM_PROCESS_WINDOW_CLOSE, MF_GRAYED);
		EnableMenuItem(hMainMenu, IDM_PROCESS_WINDOW_RESTORE, MF_GRAYED);
		EnableMenuItem(hMainMenu, IDM_PROCESS_WINDOW_MINIMIZE, MF_GRAYED);
		return EnableMenuItem(hMainMenu, IDM_PROCESS_WINDOW_MAXIMIZE, MF_GRAYED);
	}
	return TRUE;
}

BOOL RefreshVirusTotalMenuItem(tagTREEVIEWITEMPARAM* pItem)
{
	if (pItem->m_ItemDataForVirusTotal)
	{

	}
	HMENU hMenu = GetMenu(ghMainWnd);
	TCHAR* pszNewText = _TEXT("&Submit to VirusTotal");
	ModifyMenu(hMenu, IDM_CHECK_VIRUSTOTALDOTCOM, MF_BYCOMMAND, IDM_CHECK_VIRUSTOTALDOTCOM, pszNewText);

	EnableMenuItem(hMenu, IDM_PROCESS_CHECK_VIRUSTOTALDOTCOM, MF_CHECKED);


	return TRUE;
}

//////////////////////////////////////////////////////////////////////////
///
///
///
///
///
///
///
//////////////////////////////////////////////////////////////////////////
int UpdateListViewContextMenu(UINT nID, HWND hWnd, POINT* pt)
{
	static HMENU ghSelectColumnPopupMenuHandle = NULL;

	LVITEM Item = { 0 };
	HWND hWndList = NULL;
	switch (nID)
	{
	case IDC_LISTCTRL_DLLS:
		hWndList = ghWndDllsListCtrl;
		break;
	case IDC_LISTCTRL_HANDLES:
		hWndList = ghWndHandlesListCtrl;
		break;
	case IDC_TREEVIEW_LIST:
		hWndList = ghWndTreeListView;
		break;
	case IDC_STATUSBAR:
		ghSelectColumnPopupMenuHandle = CreatePopupMenu();
		AppendMenu(ghSelectColumnPopupMenuHandle, MF_BYCOMMAND, IDM_SELECT_STATUSBAR_COLUMN, TEXT("&Select Status Bar Columns..."));
		TrackPopupMenuEx(ghSelectColumnPopupMenuHandle, MF_BYCOMMAND, pt->x, pt->y, ghMainWnd, NULL);
		return 0;
	default:
	{
		HWND hWndParent = GetParent(hWnd);
		UINT uID = IDM_VIEW_SELECT_COLUMN;
		if (hWndParent == ghWndTreeListView)
		{
			uID = IDM_SELECT_TREEVIEWLIST_COLUMN;
		}
		else if (hWndParent == ghWndDllsListCtrl)
		{
			uID = IDM_SELECT_DLLSLIST_COLUMN;
		}
		else
		{
			uID = IDM_VIEW_SELECT_COLUMN;
			if (hWndParent == ghWndHandlesListCtrl)
				uID = IDM_SELECT_HANDLESLIST_COLUMN;
		}
		ghSelectColumnPopupMenuHandle = CreatePopupMenu();
		AppendMenu(ghSelectColumnPopupMenuHandle, MF_BYCOMMAND, uID, _TEXT("&Select Columns..."));
		TrackPopupMenuEx(ghSelectColumnPopupMenuHandle, MF_BYCOMMAND, pt->x, pt->y, ghMainWnd, NULL);
		ghSelectColumnPopupMenuHandle = NULL;
	}
	return 0;
	}

	int nItem = ListView_GetNextItem(hWndList, -1, LVFI_STRING);
	if (nItem != -1)
	{
		Item.iItem = nItem;
		Item.iSubItem = 0;
		Item.mask = LVIF_PARAM;
		ListView_GetItem(hWndList, &Item);
		///BUG???
		ghSelectColumnPopupMenuHandle = CreatePopupMenu();

		if (nID == IDC_LISTCTRL_DLLS)
		{
			ghSelectColumnPopupMenuHandle = GetHelpMenu(ghMainWnd);

		}
		else if (nID == IDC_LISTCTRL_HANDLES)
		{
			ghSelectColumnPopupMenuHandle = GetHelpMenu(ghMainWnd);
			tagDLLINFOLISTITEMPARAM* pItem = (tagDLLINFOLISTITEMPARAM*)Item.lParam;
			if (pItem->m_HashData)
			{

			}
			TCHAR* pszNewText = _TEXT("&Submit to VirusTotal");
			ModifyMenu(ghSelectColumnPopupMenuHandle, IDM_CHECK_VIRUSTOTALDOTCOM, MF_BYCOMMAND, IDM_CHECK_VIRUSTOTALDOTCOM, pszNewText);

			EnableMenuItem(ghSelectColumnPopupMenuHandle, IDM_CHECK_VIRUSTOTALDOTCOM, MF_CHECKED);
		}
		else
		{
			tagTREEVIEWITEMPARAM* pItem = (tagTREEVIEWITEMPARAM*)Item.lParam;
			ghSelectColumnPopupMenuHandle = GetProcessMenu(ghMainWnd);
			RefreshMenuWithTreeViewItemStatus(pItem);
			RefreshVirusTotalMenuItem(pItem);
		}
		TrackPopupMenuEx(ghSelectColumnPopupMenuHandle, MF_BYCOMMAND, pt->x, pt->y, ghMainWnd, NULL);
		ghSelectColumnPopupMenuHandle = NULL;
	}
	return 0;
}

//////////////////////////////////////////////////////////////////////////
///
///
///
///
///
///
///
//////////////////////////////////////////////////////////////////////////
LRESULT CMainWnd::HandleContextMenu(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	UINT nTabID = 0;
	if (hWnd == ghWndTreeListView)
		nTabID = IDC_TREEVIEW_LIST;
	else if (hWnd == ghWndHandlesListCtrl)
		nTabID = IDC_LISTCTRL_HANDLES;
	else if (hWnd == ghWndDllsListCtrl)
		nTabID = IDC_LISTCTRL_DLLS;
	else
		return DefWindowProc(hWnd, msg, wParam, lParam);
	POINT pt;
	pt.x = GET_X_LPARAM(lParam);
	pt.y = GET_Y_LPARAM(lParam);
	if (lParam != -1)
		return 0;

	int nItem = ListView_GetNextItem(hWnd, -1, LVFI_STRING);
	if (nItem != -1)
	{
		RECT rcItem;
		ListView_GetItemRect(hWnd, nItem, &rcItem, LVIR_BOUNDS);
		pt.y = rcItem.bottom;
		pt.x = rcItem.left + 10;
		ClientToScreen(hWnd, &pt);
	}

	UpdateListViewContextMenu(nTabID, hWnd, &pt);

	return 0;
}

//////////////////////////////////////////////////////////////////////////
///
///	CMainWnd::HandleInitMenuPopup
///
///
///
///
///
//////////////////////////////////////////////////////////////////////////
LRESULT CMainWnd::HandleInitMenuPopup(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	WM_INITMENUPOPUP;
	HMENU hMenu = (HMENU)wParam;
	int nPos = LOWORD(lParam);
	BOOL bWindowMenu = HIWORD(lParam);

	if (hMenu != ghUserPopupMenuHandle)
		return 0;
	int nCount = GetMenuItemCount(ghUserPopupMenuHandle);
	nCount = nCount - 1;
	if (nCount)
	{
		do 
		{
			DeleteMenu(ghUserPopupMenuHandle, nCount--, MF_BYPOSITION);
		} while (nCount!=-1);
	}

	PWTS_SESSION_INFOW pSessionInfo = NULL;
	DWORD dwCount = 0;
	if (WTSEnumerateSessionsW(NULL, NULL, 1, &pSessionInfo, &dwCount))
	{
		for (DWORD index = 0; index < dwCount; index++)
		{
			DWORD cbRet = 0;
			WCHAR* pszUserName = NULL, *pszDomainName = NULL;
			WCHAR szMenuItem[_MAX_PATH] = { 0 };
			if (WTSQuerySessionInformationW(NULL, pSessionInfo[index].SessionId, WTSUserName, &pszUserName, &cbRet)
				&& WTSQuerySessionInformationW(NULL, pSessionInfo[index].SessionId, WTSDomainName, &pszDomainName, &cbRet))
			{
				wsprintfW(szMenuItem, L"%d: %s\\%s", pSessionInfo[index].SessionId, pszUserName, pszDomainName);
				WTSFreeMemory(pszUserName);
				WTSFreeMemory(pszDomainName);
				MENUINFO mi = { sizeof(mi) };
				HMENU hMenuUser = LoadMenu(ghInstance, MAKEINTRESOURCE(IDM_POPUP_USERSMENU));
				mi.dwMenuData = pSessionInfo[index].SessionId;
				mi.fMask = MIM_APPLYTOSUBMENUS | MIM_STYLE | MIM_MENUDATA;
				mi.dwStyle = MNS_NOTIFYBYPOS;
				SetMenuInfo(hMenuUser, &mi);

				switch (pSessionInfo[index].State)
				{
				case WTSActive:
				case WTSShadow:
					break;
				case WTSConnected:
					EnableMenuItem(hMenuUser, IDM_USERS_CONNECT, MF_GRAYED);
					EnableMenuItem(hMenuUser, IDM_USERS_LOGOFF, MF_GRAYED);
					EnableMenuItem(hMenuUser, IDM_USERS_SEND_MESSAGE, MF_GRAYED);
					break;
				case WTSDisconnected:
					EnableMenuItem(hMenuUser, IDM_USERS_DISCONNECT, MF_GRAYED);
					EnableMenuItem(hMenuUser, IDM_USERS_SEND_MESSAGE, MF_GRAYED);
					break;
				default:
					EnableMenuItem(hMenuUser, IDM_USERS_CONNECT, MF_GRAYED);
					EnableMenuItem(hMenuUser, IDM_USERS_SEND_MESSAGE, MF_GRAYED);
					EnableMenuItem(hMenuUser, IDM_USERS_LOGOFF, MF_GRAYED);
					EnableMenuItem(hMenuUser, IDM_USERS_DISCONNECT, MF_GRAYED);
					EnableMenuItem(hMenuUser, IDM_USERS_REMOTE_CONTROL, MF_GRAYED);
					break;
				}
				
				InsertMenu(ghUserPopupMenuHandle, index, MF_BYPOSITION | MF_POPUP, (UINT)hMenuUser, szMenuItem);
			}
		}
		WTSFreeMemory(pSessionInfo);
	}
	return 0;
}

//////////////////////////////////////////////////////////////////////////
///
///
///
///
///
///
///
//////////////////////////////////////////////////////////////////////////

INT_PTR CALLBACK DlgSendMessage(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK DlgTSInfo(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

LRESULT CMainWnd::HandleMenuCommand(HWND hWnd, UINT /*msg*/, WPARAM wParam, LPARAM lParam)
{
	HMENU hMenu = (HMENU)lParam;
	WCHAR* pszUserName = NULL;
	DWORD dwSize = 0;
	WCHAR szPassword[_MAX_PATH] = { 0 };
	CREDUI_INFOW CreduiInfo = { sizeof(CreduiInfo) };
	WCHAR szServerName[_MAX_PATH] = { 0 };

	int nPos = (int)wParam;
	UINT uMenuID = GetMenuItemID(hMenu, nPos);
	if (uMenuID != IDM_USERS_DISCONNECT
		|| uMenuID != IDM_USERS_LOGOFF
		|| uMenuID != IDM_USERS_SEND_MESSAGE
		|| uMenuID != IDM_USERS_PROPERTIES
		|| uMenuID != IDM_USERS_CONNECT
		|| uMenuID != IDM_USERS_REMOTE_CONTROL)
	{
	}

	MENUINFO MenuInfo = { sizeof(MenuInfo) };
	MenuInfo.fMask = MIIM_CHECKMARKS;
	GetMenuInfo(hMenu, &MenuInfo);
	DWORD dwRet = 0;

	DWORD dwSessionID = MenuInfo.dwMenuData;
	
	typedef int(WINAPI *LPFN_WinStationConnectW)(HANDLE hServer, ULONG SessionId, ULONG TargetSessionId, PWSTR pPassword, BOOLEAN bWait);
	typedef int(WINAPI *LPFN_WinStationShadow)(HANDLE hServer, PWSTR TargetServerName, ULONG TargetSessionId, UCHAR HotKeyVk, USHORT HotkeyModifiers);


	switch (uMenuID)
	{
	case IDM_USERS_DISCONNECT:
		if (!WTSDisconnectSession(NULL, dwSessionID, FALSE))
			return 0;
		ReportMsg(TEXT("Error disconnecting session"), ghMainWnd);
		return 0;
	case IDM_USERS_LOGOFF:
		if (WTSLogoffSession(NULL, dwSessionID, FALSE))
			return 0;
		ReportMsg(TEXT("Error logging off session"), ghMainWnd);
		return 0;
	case IDM_USERS_SEND_MESSAGE:
		DialogBoxParam(ghInstance, MAKEINTRESOURCE(IDD_SENDMESSAGE), ghMainWnd, DlgSendMessage, (LPARAM)dwSessionID);
		return 0;
	case IDM_USERS_PROPERTIES:
		DialogBoxParam(ghInstance, MAKEINTRESOURCE(IDD_TSINFO), ghMainWnd, DlgTSInfo, (LPARAM)dwSessionID);
		return 0;	
	case IDM_USERS_CONNECT:
		if (WTSQuerySessionInformationW(NULL, MenuInfo.dwMenuData, WTSUserName, &pszUserName, &dwSize))
		{
			CreduiInfo.hwndParent = hWnd;
			CreduiInfo.pszMessageText = L"Enter the selected user's password";
			CreduiInfo.pszCaptionText = L"Process Explorer Connect Password";

			do 
			{
				//CREDUI_MAX_USERNAME_LENGTH
				dwRet = CredUIPromptForCredentialsW(&CreduiInfo,
					gpszTargetName,
					NULL,
					0x52E,
					pszUserName,
					dwSize,
					szPassword,
					_MAX_PATH,
					NULL,
					CREDUI_FLAGS_ALWAYS_SHOW_UI | CREDUI_FLAGS_DO_NOT_PERSIST | CREDUI_FLAGS_GENERIC_CREDENTIALS | CREDUI_FLAGS_KEEP_USERNAME);

				if (!dwRet)
				{
					_bstr_t bstrPassword(szPassword);

					////tagPESTR* str = PEStrFromString(szPassword);
					LPFN_WinStationConnectW pfnWinStationConnectW = (LPFN_WinStationConnectW)::GetProcAddress(LoadLibraryW(L"winsta.dll"), "WinStationConnectW");

					int ret = pfnWinStationConnectW(NULL, dwSessionID, -1, bstrPassword.GetBSTR(), TRUE);
					////PEStrRelease(str);
					if (ret)
						return 0;
					dwRet = GetLastError();
				}
			} while (dwRet == ERROR_LOGON_FAILURE);

		}
		else
		{
			dwRet = GetLastError();
		}
		if (!dwRet)
			SetLastError(dwRet);
		ReportMsg(TEXT("Error connecting to session"), ghMainWnd);
		return 0;
		break;
	case IDM_USERS_REMOTE_CONTROL:
		ProcessIdToSessionId(GetCurrentProcessId(), &dwSessionID);
		if (WTSGetActiveConsoleSessionId() == dwSessionID)
		{
			ReportMsg(TEXT("Remote control is not supported from a console session"), ghMainWnd);
			return 0;
		}
		else
		{
			DWORD dwSize = _MAX_PATH;
			GetComputerNameW(szServerName, &dwSize);
			LPFN_WinStationShadow pfnWinStationShadow =
				(LPFN_WinStationShadow)GetProcAddress(LoadLibraryW(L"winsta.dll"), "WinStationShadow");

			if (pfnWinStationShadow(NULL, szServerName, dwSessionID, VK_F1, 2))
			{
				return 0;
			}
			else
			{
				ReportMsg(TEXT("Error starting remote control"), ghMainWnd);
				return 0;
			}
		}
		break;
	default:
		break;
	}
	return 0;
}

//////////////////////////////////////////////////////////////////////////
///
///
///
///
///
///
///
//////////////////////////////////////////////////////////////////////////
LRESULT CMainWnd::HandleCopyData(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	PCOPYDATASTRUCT	pData = (PCOPYDATASTRUCT)lParam;
	CString strData((CHAR*)pData->lpData, pData->cbData);
	if (gpTreeViewListItemParam)
	{
		tagTREEVIEWITEMPARAM* pItem = gpTreeViewListItemParam;
		while (_wcsicmp(pItem->szProcessName2, strData.GetString()))
		{
			pItem = pItem->m_Prev;
			if (!pItem)
				return 1;
		}
		
		CTreeList::FillTreeViewParam(pItem);

		if (!IsWindowEnabled(ghMainWnd))
		{
			WINDOWPLACEMENT wp = { sizeof(wp) };
			GetWindowPlacement(ghMainWnd, &wp);
			ShowWindow(ghMainWnd, (wp.showCmd == SW_SHOWMINIMIZED) ? SW_RESTORE : SW_SHOW);
			SetForegroundWindow(ghMainWnd);
			SetFocus(ghMainWnd);
			gbMainWndMinimized1 = true;
			gbMainWndMinimized = FALSE;
		}
		return 2;
	}
	return 1;
}

//////////////////////////////////////////////////////////////////////////
///
///
///
///
///
///
///
//////////////////////////////////////////////////////////////////////////
LRESULT CMainWnd::HandleDeviceChange(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	WM_DEVICECHANGE;
	if (wParam == DBT_DEVICEARRIVAL)
	{
		_DEV_BROADCAST_HDR* pHDR = (_DEV_BROADCAST_HDR*)lParam;
		if (pHDR->dbch_devicetype == DBT_DEVTYP_VOLUME)
			GetDriverNameAndLinkInfo();
	}
	return 0;
}


//////////////////////////////////////////////////////////////////////////
///
///
///
///
///
///
///
//////////////////////////////////////////////////////////////////////////

LRESULT CMainWnd::HandleTreeViewSort(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return 0;
}

//////////////////////////////////////////////////////////////////////////
///
///
///
///
///
///
///
//////////////////////////////////////////////////////////////////////////
LRESULT CMainWnd::HandleTrayIcon(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return 0;
}

//////////////////////////////////////////////////////////////////////////
///
///
///
///
///
///
///
//////////////////////////////////////////////////////////////////////////
LRESULT CMainWnd::HandleMsg7EB(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return 0;
}

LRESULT CMainWnd::HandleMsg7ED(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return 0;
}

//////////////////////////////////////////////////////////////////////////
//
//	lParam: tagTREEVIEWITEMPARAM*
//
//
//////////////////////////////////////////////////////////////////////////
///
///
///
///
///
///
///
//////////////////////////////////////////////////////////////////////////
LRESULT CMainWnd::HandleMsg7EE(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	int ret = -1;
	if (!gConfig.bShowNewProcesses)
	{
		ret = ListView_GetNextItem(ghWndTreeListView, -1, LVFI_STRING);
		if (!ListView_IsItemVisible(ghWndTreeListView, ret))
			ret = -1;
	}
	LRESULT lRet = CTreeList::FindItem(ghWndTreeListView, lParam);
	if (ret != -1)
	{
		ListView_EnsureVisible(ghWndTreeListView, ret, FALSE);
	}
	return lRet;
}


//////////////////////////////////////////////////////////////////////////
///
///
///
///
///
///
///
//////////////////////////////////////////////////////////////////////////
LRESULT CMainWnd::HandleMsg7EF(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return 0;
}

//////////////////////////////////////////////////////////////////////////
///
///
///
///
///
///
///
//////////////////////////////////////////////////////////////////////////
LRESULT CMainWnd::HandleMsg7F8(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return 0;
}

//////////////////////////////////////////////////////////////////////////
///
///
///
///
///
///
///
//////////////////////////////////////////////////////////////////////////
static BOOL Fake_sub_467A60(HWND hWnd)
{
	if (!IsWindow(hWnd))
		return FALSE;
	RECT rc;
	GetWindowRect(hWnd, &rc);
	POINT pt;
	pt.x = rc.left + (rc.right - rc.left) / 2;
	pt.y = rc.top + (rc.bottom - rc.top) / 2;
	return WindowFromPoint(pt) == hWnd;
}

//////////////////////////////////////////////////////////////////////////
///
///
///
///
///
///
///
//////////////////////////////////////////////////////////////////////////
LRESULT CMainWnd::HandleMsg7E9(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	UINT nID = (UINT)wParam;
	
	if (lParam == 123 || lParam == 513 || lParam == 517)
	{

		return 0;
	}

	typedef BOOL(WINAPI *LPFN_EndMenu)(void);
	LPFN_EndMenu pfnEndMenu = (LPFN_EndMenu)::GetProcAddress(LoadLibraryW(L"USER32.DLL"), "EndMenu");
	if (pfnEndMenu)
		pfnEndMenu();
	else
		SendMessage(hWnd, WM_CANCELMODE, 0, 0);

	WINDOWPLACEMENT wp = { sizeof(wp) };
	GetWindowPlacement(ghMainWnd, &wp);
	if (!IsWindowVisible(ghMainWnd)
		|| wp.showCmd == SW_SHOWMINIMIZED)
	{
		gbMainWndMinimized1 = false;
		Command_OpenProcExp(NULL);
		return 0;
	}
	if (Fake_sub_467A60(ghWndTreeListView))
	{
		if (gConfig.bHideWhenMinimized)
		{
			CMainWnd::Hide(ghMainWnd);
			return 0;

		}
		gbMainWndMinimized1 = false;
		Command_OpenProcExp(NULL);
		return 0;
	}

	SetForegroundWindow(ghMainWnd);

	return 0;


	return 0;
}
//////////////////////////////////////////////////////////////////////////
///
///
///
///
///
///
///
//////////////////////////////////////////////////////////////////////////
LRESULT CMainWnd::HandleMsg7E8(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return 0;
}



//////////////////////////////////////////////////////////////////////////
///
///
///
///
///
///
///
//////////////////////////////////////////////////////////////////////////
LRESULT CMainWnd::HandleMsg7F0(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return 0;
}

////LRESULT CMainWnd::HandleMsg7EE(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
////{
////	return 0;
////}

//////////////////////////////////////////////////////////////////////////
///
///
///
///
///
///
///
//////////////////////////////////////////////////////////////////////////
LRESULT CMainWnd::HandleMsg7F6(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return 0;
}

//////////////////////////////////////////////////////////////////////////
///
///
///
///
///
///
///
//////////////////////////////////////////////////////////////////////////
LRESULT CMainWnd::HandleMsg7F2(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return 0;
}

//////////////////////////////////////////////////////////////////////////
///
///
///
///
///
///
///
//////////////////////////////////////////////////////////////////////////
LRESULT CMainWnd::HandleMsg7F3(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return 0;
}


//////////////////////////////////////////////////////////////////////////
///
///
///
///
///
///
///
//////////////////////////////////////////////////////////////////////////
LRESULT CMainWnd::HandleMsg7F9(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return 0;
}

//////////////////////////////////////////////////////////////////////////
///
///
///
///
///
///
///
//////////////////////////////////////////////////////////////////////////
INT_PTR CALLBACK DlgSendMessage(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return 0;
}

//////////////////////////////////////////////////////////////////////////
///
///
///
///
///
///
///
//////////////////////////////////////////////////////////////////////////
INT_PTR CALLBACK DlgTSInfo(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return 0;
}


//////////////////////////////////////////////////////////////////////////
///
///
///
///
///
///
///
//////////////////////////////////////////////////////////////////////////
BOOL IsProcessDEPEnabled()
{
	ULONG cbLength = 0;
	DWORD dwFlags = 0;
	if (gdwVersion >= WINDOWS_8 || gdwVersion >= WINDOWS_7)
		return TRUE;
	if (gdwVersion >= WINDOWS_VISTA)
		return FALSE;

	HANDLE ProcessHandle = OpenProcess(PROCESS_VM_OPERATION, FALSE, GetCurrentProcessId());
	if (!ProcessHandle)
		return FALSE;

	NTSTATUS Status =  gpfn_NtQueryInformationProcess(ProcessHandle, ProcessExecuteFlags, &dwFlags, sizeof(DWORD), &cbLength);
	CloseHandle(ProcessHandle);

	return Status == STATUS_SUCCESS || Status == STATUS_INVALID_PARAMETER;
}

extern BOOL SetMenuIcon(HMENU hMenu, UINT nItem);

//////////////////////////////////////////////////////////////////////////
///
///
///
///
///
///
///
//////////////////////////////////////////////////////////////////////////
BOOL ReplaceMenuIconFromStockIcon(HMENU hMenu, UINT nItem)
{
	return SetMenuIcon(hMenu, nItem);
}

//////////////////////////////////////////////////////////////////////////
///
///
///
///
///
///
///
//////////////////////////////////////////////////////////////////////////
extern INT_PTR CALLBACK DlgFind(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam);

BOOL Commmand_FindInProcess(HWND hWnd, USHORT nID)
{
	if (ghFindDlg)
	{
		ShowWindow(ghFindDlg, SW_SHOW);
		SetFocus(ghFindDlg);
	}
	else
	{
		ghFindDlg = CreateDialogParam(ghInstance,
			MAKEINTRESOURCE(IDD_SEARCH),
			ghMainWnd,
			DlgFind,
			(LPARAM)ghFindDlg);
	}

	return 0;
}

LRESULT CALLBACK EditVTClassCallback(HWND hWnd, UINT uMsg, WPARAM wParam,LPARAM lParam, UINT_PTR uIdSubclass, DWORD_PTR dwRefData);



//////////////////////////////////////////////////////////////////////////
///
///
///
///
///
///
///
//////////////////////////////////////////////////////////////////////////
INT_PTR CALLBACK DlgDllInfo(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if(msg == WM_INITDIALOG)
	{
		CResizer* pResizer = new CResizer(hWnd);
		pResizer->m_nXRatio = 85;
		pResizer->m_nYRatio = 100;

		pResizer->AddItem(GetDlgItem(hWnd, IDC_DLG_DLLINFO_EDIT_PATH), true);
		pResizer->AddItem(GetDlgItem(hWnd, IDC_DLG_DLLINFO_EDIT_AUTOSTART_LOCATION), true);
		
		DLLINFOLISTITEMPARAM* pItem = (DLLINFOLISTITEMPARAM*)lParam;
		SetWindowLongPtr(hWnd, GWLP_USERDATA, (LONG)lParam);
		const WCHAR* pstr = pItem->m_strPath.GetString();
		const WCHAR* psz = wcsrchr(pstr, L'\\');
		if (psz != NULL)
			psz++;
		else
			psz = (WCHAR*)pstr;

		WCHAR szText[1024] = { 0 };
		wsprintfW(szText, L"%s Properties", psz);
		SetWindowTextW(hWnd, szText);

		if(pItem->m_dwStyle&4)
			SetDlgItemTextW(hWnd, IDC_DLG_DLLINFO_STATIC_PATH, L"Path (Image is probably packed):");
		SetDlgItemTextW(hWnd, IDC_DLG_DLLINFO_STATIC_MAPPING_TYPE_VALUE, !(pItem->m_dwStyle & 2) ? L"Image" : L"Data");
		SetDlgItemTextW(hWnd, IDC_DLG_DLLINFO_EDIT_PATH, pstr);
		if (pItem->m_strLocation.IsEmpty())
			SetDlgItemTextW(hWnd, IDC_DLG_DLLINFO_EDIT_AUTOSTART_LOCATION, L"n/a");
		else
			SetDlgItemTextW(hWnd, IDC_DLG_DLLINFO_EDIT_AUTOSTART_LOCATION, pItem->m_strLocation.GetString());
		EnableWindow(GetDlgItem(hWnd, IDC_DLG_DLLINFO_BUTTON_EXPLORE_PATH), pItem->m_strPath.IsEmpty());
		EnableWindow(GetDlgItem(hWnd, IDC_DLG_DLLINFO_EDIT_AUTOSTART_LOCATION), pItem->m_strLocation.IsEmpty());

		HICON hIcon = LoadIcon(ghInstance, MAKEINTRESOURCE(IDI_PROPERTIES));
		SendMessage(hWnd, WM_SETICON, (WPARAM)TRUE, (LPARAM)hIcon);
		SendMessage(hWnd, WM_SETICON, (WPARAM)FALSE, (LPARAM)hIcon);
		SendMessage(GetParent(hWnd), WM_SETICON, (WPARAM)FALSE, (LPARAM)hIcon);

		if (pItem->m_strDescription.IsEmpty())
			SetDlgItemTextW(hWnd, IDC_DLG_DLLINFO_EDIT_DESCRIPTION, L"n/a");
		else
			SetDlgItemTextW(hWnd, IDC_DLG_DLLINFO_EDIT_DESCRIPTION, pItem->m_strDescription.GetString());

		if (!pItem->m_strCompanyInfo.IsEmpty())
		{

		}
		else
		{
			SetDlgItemTextW(hWnd, IDC_DLG_DLLINFO_EDIT_COMPANY, L"n/a");
		}
	
		ShowWindow(GetDlgItem(hWnd, IDC_DLG_DLLINFO_STATIC_IMAGE_TYPE), SW_HIDE);

		if (gbWintrustInited)
		{

		}
		else
		{
			ShowWindow(GetDlgItem(hWnd, IDC_DLG_DLLINFO_BUTTON_VERIFY), SW_HIDE);
		}

		SetWindowSubclass(GetDlgItem(hWnd, IDC_DLG_DLLINFO_EDIT_VIRUSTOTAL), EditVTClassCallback, 0, 0);

		//sub_491A50(pListItem->field_16C, Dest);
		//SetDlgItemTextW(hWnd, IDC_DLG_DLLINFO_EDIT_VIRUSTOTAL, Dest);
		if (*pstr == L'[')
		{
			EnableWindow(GetDlgItem(hWnd, IDC_DLG_DLLINFO_BUTTON_SUBMIT), FALSE);
		}

		SetDlgItemTextW(hWnd, IDC_DLG_DLLINFO_EDIT_VERSION, *pItem->m_szVersion ? pItem->m_szVersion : L"n/a");

		wsprintfW(szText, L"0x%X", pItem->m_LoadAddress);
		SetDlgItemTextW(hWnd, IDC_DLG_DLLINFO_STATIC_LOAD_ADDRESS_VALUE, szText);

		wsprintfW(szText, L"0x%X bytes", pItem->m_MappedSize);
		SetDlgItemTextW(hWnd, IDC_DLG_DLLINFO_STATIC_MAPED_SIZE_VALUE, szText);

		SetDlgItemTextW(hWnd, IDC_DLG_DLLINFO_EDIT_BUILD_TIME, pItem->m_BuildTime?_wctime(&pItem->m_BuildTime):L"n/a");


	/*	SetTimer(hWnd, 1000, NULL);*/

		PropSheet_UpdateTab(hWnd);

		ShowWindow(hWnd, SW_SHOW);

		return 0;
	}
	DLLINFOLISTITEMPARAM* pItem = (DLLINFOLISTITEMPARAM*)GetWindowLongPtr(hWnd, GWLP_USERDATA);
	
	switch (msg)
	{
	case WM_TIMER:
	case WM_COMMAND:
	{
		UINT nID = LOWORD(wParam);
		if (nID >= 40093)
		{

		}
	}
	case WM_NOTIFY:
		break;
	case WM_CTLCOLORSTATIC:
		break;
	default:
		break;
	}

	return 0;
}



//////////////////////////////////////////////////////////////////////////
///
///
///
///
///
///
///
//////////////////////////////////////////////////////////////////////////
LRESULT CALLBACK EditVTClassCallback(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, UINT_PTR uIdSubclass, DWORD_PTR dwRefData)
{

	HWND hWndParent = GetParent(hWnd);
	DLLINFOLISTITEMPARAM *pItem = (DLLINFOLISTITEMPARAM*)GetWindowLongPtr(hWndParent, GWLP_USERDATA);

	LRESULT ret = DefSubclassProc(hWnd, uMsg, wParam, lParam);

	SetCursor(LoadCursor(ghInstance, IDC_HAND));
	return ret;
}

//////////////////////////////////////////////////////////////////////////
///
///
///
///
///
///
///
//////////////////////////////////////////////////////////////////////////

INT_PTR CALLBACK DlgColumnSets(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK DlgColumnSetSave(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
BOOL Command_SaveColumnSet(HWND hWnd)
{
	DialogBoxParam(ghInstance,
		MAKEINTRESOURCE(IDD_COLUMN_SET_SAVE),
		hWnd,
		DlgColumnSetSave, 0);
	return TRUE;
}

//////////////////////////////////////////////////////////////////////////
///
///
///
///
///
///
///
//////////////////////////////////////////////////////////////////////////

int ColumnSet_Set(HWND hWnd,LPCWSTR szString, DWORD dwColumnIndex)
{
	WCHAR szMenuItem[_MAX_PATH + _MAX_PATH] = { 0 };

	UpdateWindowPlacement(ghMainWnd, FALSE);
	CopyMemory(&gConfig.strMenuCulumnSet[dwColumnIndex],
		gConfig.szColumnSetName,
		sizeof(gConfig.strMenuCulumnSet[dwColumnIndex]));
	wcscpy_s(gConfig.strMenuCulumnSet[dwColumnIndex].ColumnSetName, szString);
	if (dwColumnIndex == gConfig.dwNumColumnsets)
	{
		if (dwColumnIndex >= MAX_NumColumnsets)
		{
			wcscpy_s(szMenuItem, _MAX_PATH + _MAX_PATH, szString);
		}
		else
		{
			wsprintfW(szMenuItem, L"%s\tCtrl+%d", szString, dwColumnIndex == (MAX_NumColumnsets - 1) ? 0 : (dwColumnIndex + 1));
		}

		HMENU hMenu = GetMenu(ghMainWnd);
		HMENU hViewSubMenu = GetSubMenu(hMenu, MAINMENU_View);
		HMENU hSubMenu = GetSubMenu(hViewSubMenu, gdwMenuItemPosLast);
		AppendMenuW(hSubMenu, MF_BYCOMMAND, dwColumnIndex + IDM_PROCESS_PRIORITY_BASE, szMenuItem);
		++gConfig.dwNumColumnsets;
	}

	ProcessPriority_Set(NULL, LOWORD(dwColumnIndex - 0x6127));
	EndDialog(hWnd, 0);
	return 0;
}

//////////////////////////////////////////////////////////////////////////
///
///
///
///
///
///
///
//////////////////////////////////////////////////////////////////////////

INT_PTR CALLBACK DlgColumnSetSave(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	WCHAR szString[_MAX_PATH] = { 0 };

	if (msg == WM_INITDIALOG)
	{
		DWORD dwColumnIndex = 0;
		int index = 0;
		do 
		{
			wsprintfW(szString, L"Column Set %d", index);
			for (int j = 0; j < 10; j++)
			{
				if (_wcsicmp(szString, gConfig.strMenuCulumnSet[j].ColumnSetName) == 0)
					break;
			}
		} while (dwColumnIndex<gConfig.dwNumColumnsets);

		HWND hWndCB = GetDlgItem(hWnd, IDC_DLG_COLUMN_SET_SAVE_COMBO);

		ComboBox_AddString(hWndCB, szString);
		for (DWORD k = 0; k < gConfig.dwNumColumnsets; k++)
		{
			ComboBox_AddString(hWndCB, gConfig.strMenuCulumnSet[k].ColumnSetName);
		}
	}
	else if (msg == WM_COMMAND)
	{
		UINT nID = LOWORD(wParam);
		if (nID != IDOK&&nID != IDCANCEL)
			return 0;
		HWND hWndCB = GetDlgItem(hWnd, IDC_DLG_COLUMN_SET_SAVE_COMBO);
		GetWindowTextW(hWndCB, szString, _MAX_PATH);
		DWORD k = 0;
		for ( k = 0; k < gConfig.dwNumColumnsets; k++)
		{
			if (!_wcsicmp(gConfig.strMenuCulumnSet[k].ColumnSetName, szString))
				break;
		}
		if (k != MAX_NumColumnsets)
		{
			return ColumnSet_Set(hWnd, szString, k);
		}

		while (1)
		{
			if (MessageBoxW(
				ghMainWnd,
				L"You must delete at least one column set before you can save a new column set.\n"
				"Do you want to open the Column Set Organizer dialog?",
				L"Process Explorer Warning",
				MB_ICONEXCLAMATION | MB_YESNO) == IDNO)
				return 1;

			else
			{
				DialogBoxParam(ghInstance, MAKEINTRESOURCE(IDD_COLUMN_SETS), ghMainWnd, DlgColumnSets, 0);

				if (gConfig.dwNumColumnsets != MAX_NumColumnsets)
				{
					return ColumnSet_Set(hWnd, szString, gConfig.dwNumColumnsets);
				}
			}
		}
	}
	return 1;
}


//////////////////////////////////////////////////////////////////////////
///
///
///
///
///
///
///
//////////////////////////////////////////////////////////////////////////
BOOL ProcessPriority_Set(HWND hWnd, WORD uID)
{
	int index = (int)(uID - IDM_PROCESS_PRIORITY_BASE);

	return FALSE;
}

//////////////////////////////////////////////////////////////////////////
///
///
///
///
///
///
///
//////////////////////////////////////////////////////////////////////////
BOOL Command_SetProcessPriority(HWND hWnd, WPARAM wParam)
{
	return ProcessPriority_Set(hWnd, LOWORD(wParam));
}


//////////////////////////////////////////////////////////////////////////
///
///
///
///
///
///
///
//////////////////////////////////////////////////////////////////////////
INT_PTR CALLBACK DlgColumnSets(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	static bool sbEditFlags = false;

	HWND hWndList = GetDlgItem(hWnd, IDC_DLG_COLUMN_SETS_LIST);
	if(msg == WM_INITDIALOG)
	{
		LVCOLUMN ColumnInfo = { 0 };
		sbEditFlags = false;
		ListView_SetExtendedListViewStyle(hWndList, LVS_EX_FULLROWSELECT);
		ListView_InsertColumn(hWndList, 0, &ColumnInfo);
		LVITEMW Item = { 0 };
		Item.mask = LVIF_TEXT | LVIF_PARAM | LVIF_IMAGE | LVIF_STATE;
		Item.iItem = 0x7FFFFFFF;

		for (DWORD k = 0; k < gConfig.dwNumColumnsets; k++)
		{
			Item.pszText = gConfig.strMenuCulumnSet[k].ColumnSetName;
			Item.iImage = 0;
			Item.cchTextMax = lstrlenW(gConfig.strMenuCulumnSet[k].ColumnSetName) + 1;
			Item.lParam = k;

			ListView_InsertItem(hWndList, &Item);
		}

		ListView_SetColumnWidth(hWndList, 0, LVSCW_AUTOSIZE);
		ListView_SetItemState(hWndList, 0, LVIS_SELECTED | LVIS_FOCUSED, LVIS_SELECTED | LVIS_FOCUSED);
		SetFocus(hWndList);
		return 1;
	}
	else if (msg == WM_COMMAND)
	{
		UINT nID = LOWORD(wParam);
		if (nID == IDC_DLG_COLUMN_SETS_BUTTON_DELETE) // 1212
		{
			int nCurItem = ListView_GetNextItem(hWndList, -1, LVFI_STRING);// ::SendMessageW(hWndList, LVM_GETNEXTITEM, 0xFFFFFFFF, LVFI_STRING);
			ListView_DeleteItem(hWndList, nCurItem);

			if (nCurItem)
				--nCurItem;
			ListView_SetItemState(hWndList, nCurItem, LVIS_SELECTED | LVIS_FOCUSED, LVIS_SELECTED | LVIS_FOCUSED);
			return 0;
		}
		if (nID == IDCANCEL)
			return 0;
		if (nID <= IDC_DLG_COLUMN_SETS_BUTTON_MOVEDOWN) //1211
		{
			WCHAR szText1[_MAX_PATH] = { 0 };
			WCHAR szText2[_MAX_PATH] = { 0 };

			int  nCurItem = ListView_GetNextItem(hWndList, -1, LVFI_STRING);
			LVITEMW Item = { 0 };
			Item.mask = LVIF_TEXT | LVIF_PARAM;
			if (nID == IDC_DLG_COLUMN_SETS_BUTTON_MOVEUP)
				Item.iItem = nCurItem - 1;
			else
				Item.iImage = nCurItem + 1;
			Item.cchTextMax = _MAX_PATH - 1;
			Item.pszText = szText1;
			Item.iSubItem = 0;
			ListView_GetItem(hWndList, &Item);
			LVITEMW Item2 = { 0 };
			Item2.mask = LVIF_TEXT | LVIF_PARAM;
			Item2.iImage = nCurItem;
			Item2.cchTextMax = _MAX_PATH - 1;
			Item2.pszText = szText2;
			Item2.iSubItem = 0;
			ListView_GetItem(hWndList, &Item2);

			/// 
			/// 进行交换
			Item2.pszText = szText1;
			Item.pszText = szText2;
			LPARAM temp = Item.lParam;
			Item.lParam = Item2.lParam;
			Item2.lParam = temp;
			ListView_SetItem(hWndList, &Item2);
			ListView_SetItem(hWndList, &Item);
			ListView_SetItemState(hWndList, Item.iItem, LVIS_SELECTED | LVIS_FOCUSED, LVIS_SELECTED | LVIS_FOCUSED);
			return 0;
		}
		if (nID == IDC_DLG_COLUMN_SETS_BUTTON_RENAME)//1214
		{
			/// 开始编辑
			SetFocus(hWndList);
			ListView_EditLabel(hWndList, ListView_GetNextItem(hWndList, -1, LVFI_STRING));
			return 0;
		}
		if (nID == IDC_DLG_COLUMN_SETS_BUTTON_OK)//1213
		{
			HMENU hMenu = GetViewMenu(ghMainWnd);
			HMENU hSubMeu = GetSubMenu(hMenu, gdwMenuItemPosLast);
			/// 删除对应的菜单
			DWORD k = 0;
			for (k = 0; k < gConfig.dwNumColumnsets; k++)
			{
				DeleteMenu(hSubMeu, 0, MF_BYPOSITION);
			}

			/// 做一个简单的备份
			CRegVar temp[MAX_NumColumnsets] = { 0 };
			CopyMemory(&temp, gConfig.strMenuCulumnSet, sizeof(gConfig.strMenuCulumnSet));
			
			gConfig.dwNumColumnsets = ListView_GetItemCount(hWndList);

			WCHAR szText[_MAX_PATH] = { 0 };
			WCHAR szMenuItem[_MAX_PATH + _MAX_PATH] = { 0 };
			
			LVITEMW Item = { 0 };
			///重新生成各项菜单
			for (k = 0; k < gConfig.dwNumColumnsets; k++)
			{
				Item.mask = LVIF_TEXT | LVIF_PARAM;
				Item.cchTextMax = _MAX_PATH - 1;
				Item.pszText = szText;
				Item.iItem = k;
				Item.iSubItem = 0;

				ListView_GetItem(hWndList, &Item);

				///移动数据
				CopyMemory(&gConfig.strMenuCulumnSet[k],
					&temp[Item.lParam],
					sizeof(gConfig.strMenuCulumnSet[k]));
				wcscpy_s(gConfig.strMenuCulumnSet[k].ColumnSetName, _MAX_PATH, szText);

				if (k >= MAX_NumColumnsets)
				{
					wcscpy_s(szMenuItem, _MAX_PATH + _MAX_PATH, szText);
				}
				else
				{
					wsprintfW(szMenuItem, L"%s\\Ctrl+%d", szText, k == (MAX_NumColumnsets - 1) ? 0 : (k + 1));
				}
				///在进程优先级菜单后面添加这些菜单
				hSubMeu = GetSubMenu(hMenu, gdwMenuItemPosLast);
				AppendMenuW(hSubMeu, MF_BYCOMMAND, k + IDM_PROCESS_PRIORITY_BASE, szMenuItem);
			}
			EndDialog(hWnd, 0);
			return 0;
		}
	}
	else if (msg == WM_NOTIFY)
	{
		NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)lParam;
		if (pNMListView->hdr.code == LVN_ENDLABELEDITW)
		{
			///结束编辑
			NMLVDISPINFOW* p = (NMLVDISPINFOW*)lParam;
			sbEditFlags = false;
			WCHAR* pszText = p->item.pszText;
			if (!pszText)
				return 0;
			ListView_SetItemText(hWndList, pNMListView->iSubItem, 0, pszText);
			return 1;
		}
		else if(pNMListView->hdr.code == LVN_BEGINLABELEDITW)
		{
			///开始编辑
			sbEditFlags = true;
			return	0;
		}
		else if (pNMListView->hdr.code == LVN_ITEMCHANGED
			&& !sbEditFlags)
		{
			///更改有效
			int  nCurItem = ListView_GetNextItem(hWndList, -1, LVFI_STRING);

			EnableDlgItem(hWnd, IDC_DLG_COLUMN_SETS_BUTTON_RENAME, nCurItem != -1);
			EnableDlgItem(hWnd, IDC_DLG_COLUMN_SETS_BUTTON_DELETE, nCurItem != -1);
			EnableDlgItem(hWnd, IDC_DLG_COLUMN_SETS_BUTTON_MOVEUP, nCurItem != -1 && nCurItem);
			EnableDlgItem(hWnd, IDC_DLG_COLUMN_SETS_BUTTON_MOVEDOWN, nCurItem != -1 && nCurItem != ListView_GetItemCount(hWndList));
			return 0;
		}
	}
	return 1;
}

int Command_Cancel(HWND hWnd)
{
	if (ghWndHungWindow)
	{
		SearchWindow(hWnd);
		return 0;
	}
	else
	{
		if (gConfig.bHideWhenMinimized)
		{
			CMainWnd::Hide(ghMainWnd);
		}
		else
			CMainWnd::HandleDestroy(hWnd,0,0,0);
	}
	return 0;
}

//////////////////////////////////////////////////////////////////////////
///
///
///
///
///
///
///
//////////////////////////////////////////////////////////////////////////
BOOL CMainWnd::Hide(HWND hWnd)
{
	BOOL ret = ShowWindow(hWnd, SW_HIDE);
	gbMainWndMinimized = true;
	return ret;
}

//////////////////////////////////////////////////////////////////////////
///
///
///
///
///
///
///
//////////////////////////////////////////////////////////////////////////
int Command_OpenProcExp(HWND hWnd)
{
	LVHITTESTINFO;

	WINDOWPLACEMENT wp = { sizeof(wp) };
	GetWindowPlacement(ghMainWnd, &wp);
	ShowWindow(ghMainWnd, (wp.showCmd == SW_SHOWMINIMIZED) ? SW_RESTORE : SW_SHOW);
	SetForegroundWindow(ghMainWnd);
	SetFocus(ghMainWnd);
	gbMainWndMinimized1 = true;
	gbMainWndMinimized = FALSE;
	return 0;
}

extern DWORD WINAPI BackendSysInfoPropSheetThreadProc(void* p);

//////////////////////////////////////////////////////////////////////////
///
///
///
///
///
///
///
//////////////////////////////////////////////////////////////////////////
int Command_SystemInformation(HWND hWnd)
{
	if (ghWndSysinfoPropSheet)
	{
		ShowWindow(ghWndSysinfoPropSheet, SW_RESTORE);
		SetFocus(ghWndSysinfoPropSheet);
		SetForegroundWindow(ghWndSysinfoPropSheet);
	}
	else
	{
		HCURSOR h = SetCursor(LoadCursorW(NULL, IDC_WAIT));
		CreateThread(NULL,0,BackendSysInfoPropSheetThreadProc, NULL, 0,NULL);
		WaitForSingleObject(ghSystemInfoSheetThreadEvent, INFINITE);
		SetCursor(h);
	}

	return 0;
}