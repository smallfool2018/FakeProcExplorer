#include "stdafx.h"
#include "../ProcExplorer.h"

extern HWND	ghWndSysinfoPropSheet;


INIT_LOAD(ImageNtHeader);
//////////////////////////////////////////////////////////////////////////
//
//
//
//
//
//
//////////////////////////////////////////////////////////////////////////
FILETIME GetSystemProcessInfo(void** ppBuffer,size_t* cbRet)
{
	FILETIME ret;
	GetSystemTimeAsFileTime(&ret);
	size_t nBufLen = cbRet ? *cbRet : 0;
	if (!*ppBuffer)
	{
		nBufLen = 1000;
		*ppBuffer = malloc(1000);
	}

	if (gpfnNtQuerySystemInformation(SystemProcessInformation,
		*ppBuffer,
		nBufLen,
		(PSIZE_T)cbRet))
	{
		do 
		{
			free(*ppBuffer);
			nBufLen += 10000;
			*ppBuffer = malloc(nBufLen);
		} while (gpfnNtQuerySystemInformation(SystemProcessInformation,
			*ppBuffer,
			nBufLen,
			(PSIZE_T)cbRet));
	}

	return  ret;
}

//////////////////////////////////////////////////////////////////////////
//
//
//
//
//
//
//////////////////////////////////////////////////////////////////////////
WCHAR gszDbgHelpModuleName[_MAX_PATH] = { 0 };
bool LoadSystemApis()
{
	HMODULE hModule = LoadLibraryW(gszDbgHelpModuleName);
	if (!hModule)
	{
		ULONG cbLength = _MAX_PATH * sizeof(WCHAR);
		ATL::CRegKey reg;
		if (reg.Open(HKEY_CURRENT_USER, TEXT("Software\\Microsoft\\DebuggingTools")))
		{
			RegQueryValueExW(reg.m_hKey, L"Windbg", NULL, NULL, (LPBYTE)gszDbgHelpModuleName, &cbLength);
			reg.Close();
			wcscat_s(gszDbgHelpModuleName, MAX_PATH, L"DbgHelp.dll");
			hModule = LoadLibraryW(gszDbgHelpModuleName);
			if (!hModule)
			{
				ExpandEnvironmentStringsW(
					L"%ProgramFiles%\\Debugging Tools for Windows (x86)\\dbghelp.dll",
					gszDbgHelpModuleName,
					MAX_PATH);
				hModule = LoadLibraryW(gszDbgHelpModuleName);
				if (!hModule)
				{
					GetCurrentDirectoryW(MAX_PATH, gszDbgHelpModuleName);
					wcscat_s(gszDbgHelpModuleName, MAX_PATH, L"\\dbghelp.dll");

					hModule = LoadLibraryW(gszDbgHelpModuleName);
					if (!hModule)
					{
						hModule = LoadLibraryW(L"dbghelp.dll");
						if (!hModule)
						{
							hModule = LoadLibraryW(L"imagehlp.dll");
						}
					}
				}
			}
		}
	}
	if (hModule == NULL)
		return false;

	GetModuleFileNameW(hModule, gszDbgHelpModuleName, MAX_PATH);

	LoadDbgHelp(gszDbgHelpModuleName);

	return true;
}

INT_PTR CALLBACK SysinfoPropSheet(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

//////////////////////////////////////////////////////////////////////////
//
DWORD WINAPI BackendSysInfoPropSheetThreadProc(void* p)
{
	MSG msg = { 0 };
	BOOL result = FALSE;
	ghWndSysinfoPropSheet = CreateDialogParam(ghInstance, MAKEINTRESOURCE(IDD_SYSINFO_PROPSHEET), 0, SysinfoPropSheet, 0);
	HICON hIcon  = LoadIcon(ghInstance, MAKEINTRESOURCE(IDI_PROCEXPLORER));
	SendMessage(ghWndSysinfoPropSheet, WM_SETICON, FALSE, (LPARAM)hIcon);
	SendMessage(ghWndSysinfoPropSheet, WM_SETICON, TRUE, (LPARAM)hIcon);
	SetEvent(ghSystemInfoSheetThreadEvent);
	HACCEL hAccel = LoadAccelerators(ghInstance, MAKEINTRESOURCE(IDC_PROCPROPERTIES));
	for (result = GetMessageW(&msg, 0, 0, 0); result; result = GetMessage(&msg, 0, 0, 0))
	{
		if (!TranslateAccelerator(ghWndSysinfoPropSheet, hAccel, &msg) 
			&& !IsDialogMessage(ghWndSysinfoPropSheet, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	return result;
}

INT_PTR CALLBACK PropSummary(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK PropSystemInfoSumETW(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK PropSystemInfoMem(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK PropSystemInfoMemXP(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK PropSystemInfoIO(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK PropSystemInfoGPU(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);



INT_PTR CALLBACK SysinfoPropSheet(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	HWND hWndTab = GetDlgItem(hWnd, IDC_SYSINFO_PROPSHEET_TAB);
	if (msg == WM_INITDIALOG)
	{
		BOOL fAdmin = IsBuiltinAdministrative();

		WCHAR *szText[] =
		{
			L"Summary",L"CPU",L"Memory",L"I/O",L"GPU",
		};
		WCHAR* szTemplateName[]=
		{
			fAdmin ? L"SYSTEMINFOSUMETW":L"SYSTEMINFOSUM",
			L"SYSTEMINFOCPU",
			gdwVersion >= WINDOWS_VISTA ? L"SYSTEMINFOMEM":L"SYSTEMINFOMEMXP",
			fAdmin ?  L"SYSTEMINFOIOETW" : L"SYSTEMINFOIO",
			L"SYSTEMINFOGPU"
		};
		DLGPROC Funcs[]=
		{
			PropSummary,PropSystemInfoSumETW,gdwVersion >= WINDOWS_VISTA ? PropSystemInfoMem:PropSystemInfoMemXP,
			PropSystemInfoMem,
			PropSystemInfoIO,
			PropSystemInfoGPU,
		};

		CResizer *r = new CResizer(hWnd);
		CResizer *r1 = new CResizer(hWndTab);
		TCITEM Item = { 0 };
		Item.mask = TCIF_TEXT;
		RECT	rcTab;

		for (int i = 0; i < sizeof(szText) / sizeof(*szText); i++)
		{
			Item.pszText = szText[i];
			TabCtrl_InsertItem(hWndTab, i, &Item);
			GetClientRect(hWndTab, &rcTab);
			TabCtrl_AdjustRect(hWndTab, FALSE, &rcTab);

			HWND hWndPage = CreateDialogParam(ghInstance, szTemplateName[i], hWndTab, Funcs[i], 0);
			MoveWindow(hWndPage, rcTab.left, rcTab.top, rcTab.right - rcTab.left, rcTab.bottom - rcTab.top, TRUE);
			ShowWindow(hWndPage, SW_HIDE);
			Item.mask = TCIF_PARAM;
			Item.lParam = (LPARAM)hWndPage;
			TabCtrl_SetItem(hWnd, i, &Item);
		}
	}
	else if (msg == WM_COMMAND)
	{
		UINT nID = LOWORD(wParam);
		switch (nID)
		{
		case IDM_VIEW_REFRESH_NOW:
			SetEvent(ghRefreshEventHandle);
			break;
		case IDOK:
		case IDCANCEL:
		case IDM_FILE_EXIT:
			SendMessage(hWnd, WM_CLOSE, 0, 0);
			break;
		case IDM_VIEW_UPDATESPEED_PAUSED_SPACE:
		case IDM_VIEW_UPDATESPEED_TWO_SECONDS:
		case IDM_VIEW_UPDATESPEED_FIVE_SECONDS:
		case IDM_VIEW_UPDATESPEED_ONE_SECOND:
		case IDM_VIEW_UPDATESPEED_TEN_SECONDS:
		case IDM_VIEW_UPDATESPEED_HALF_SECONDS:
			PostMessage(ghMainWnd, WM_COMMAND, wParam, lParam);
			break;
		case 40092:
		case 40093:
		{
			int nTab = TabCtrl_GetCurSel(hWndTab);
			int nTabCount = TabCtrl_GetItemCount(hWndTab);
			int nNewTab = (nID == 40092) ? (nTabCount + nTab) : (nTabCount + nTab - 2);
			nNewTab = nNewTab % nTabCount;
			TabCtrl_SetCurSel(hWndTab, nNewTab);
			
			TCITEM Item = { 0 };
			Item.mask = TCIF_PARAM;
			TabCtrl_GetItem(hWndTab, nTab, &Item);
			HWND hWndPage = (HWND)Item.lParam;
			ShowWindow(hWndPage, SW_HIDE);
			TabCtrl_GetItem(hWndTab, nNewTab, &Item);
			hWndPage = (HWND)Item.lParam;
			ShowWindow(hWndPage, SW_SHOW);
		}
		default:
			break;
		}
	}
	else if (msg == WM_TIMER)
	{

		int nTabCount = TabCtrl_GetItemCount(hWndTab);
		TCITEM Item = { 0 };
		for (int nTab = 0; nTab < nTabCount; nTab++)
		{
			Item.mask = TCIF_PARAM;
			TabCtrl_GetItem(hWndTab, nTab, &Item);
			HWND hWndPage = (HWND)Item.lParam;
			SendMessage(hWndPage, WM_TIMER, 0, 0);
		}
	}
	else if (msg == WM_CLOSE)
	{
		DestroyWindow(hWnd);
	}
	else if (msg == WM_NOTIFY)
	{

	}
	return 0;
}

INT_PTR CALLBACK PropSummary(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return 0;
}
INT_PTR CALLBACK PropSystemInfoSumETW(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return 0;
}
INT_PTR CALLBACK PropSystemInfoMem(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return 0;
}
INT_PTR CALLBACK PropSystemInfoMemXP(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return 0;
}
INT_PTR CALLBACK PropSystemInfoIO(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return 0;
}
INT_PTR CALLBACK PropSystemInfoGPU(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return 0;
}