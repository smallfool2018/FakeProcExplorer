#include "stdafx.h"
#include "../ProcExplorer.h"

INT_PTR CALLBACK PropPageProcPerf(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam);
INIT_DEFINE(AllocateAndGetTcpExTable2FromStack);
INIT_DEFINE(AllocateAndGetUdpExTable2FromStack);

///Registry Editor Key Settings
ACLEDITENTRY aclEditEntryRegistry[] = {
	{ 2, KEY_QUERY_VALUE,                 0, L"&Query Value" },
	{ 2, KEY_SET_VALUE,                   0, L"&Set Value" },
	{ 2, KEY_CREATE_SUB_KEY,              0, L"&Create Subkeys" },
	{ 2, KEY_ENUMERATE_SUB_KEYS,          0, L"&Enumerate Subkeys" },
	{ 2, KEY_NOTIFY,                      0, L"No&tify" },
	{ 2, KEY_CREATE_LINK,                 0, L"Create &Link" },
	{ 2, DELETE,                          0, L"&Delete" },
	{ 2, WRITE_DAC,                       0, L"&Write DAC" },
	{ 2, WRITE_OWNER,                     0, L"Write &Owner" },
	{ 2, READ_CONTROL,                    0, L"&Read Control" },
	{ 1, 0x2019,                          0, L"Read" },
	{ 1, GENERIC_ALL,                     0, L"Full Control" },
};
///Explorer Directory Settings
ACLEDITENTRY aclEditEntryDirectory[] = {
	{ 2, GENERIC_READ,                    0, L"&Read (R)" },
	{ 2, GENERIC_WRITE,                   0, L"&Write (W)" },
	{ 2, GENERIC_EXECUTE,                 0, L"E&xecute (X)" },
	{ 2, ACCESS_SYSTEM_SECURITY,          0, L"&View/Change Audits (A)" },
	{ 2, DELETE,                          0, L"&Delete (D)" },
	{ 2, WRITE_DAC,                       0, L"Change &Permissions (P)" },
	{ 2, WRITE_OWNER,                     0, L"Take &Ownership (O)" },
	{ 2, FILE_LIST_DIRECTORY,             0, L"&List (L)" },
	{ 2, FILE_ADD_FILE,                   0, L"Add &Entry (N)" },
	{ 2, READ_CONTROL,                    0, L"Read &Control (T)" },
	{ 3, 0,                               0, L"No Access" },
	{ 3, FILE_LIST_DIRECTORY | READ_CONTROL, (DWORD)-1, L"List" },
	{ 3, GENERIC_READ | GENERIC_EXECUTE,
	GENERIC_READ | GENERIC_EXECUTE, L"Read" },
	{ 3, GENERIC_WRITE | GENERIC_EXECUTE, (DWORD)-1, L"Add" },
	{ 3, GENERIC_WRITE | GENERIC_READ | GENERIC_EXECUTE,
	GENERIC_READ | GENERIC_EXECUTE, L"Add Read" },
	{ 3, GENERIC_WRITE | GENERIC_READ | GENERIC_EXECUTE | DELETE,
	GENERIC_WRITE | GENERIC_READ |
	GENERIC_EXECUTE | DELETE, L"Change" },
	{ 3, GENERIC_ALL, GENERIC_ALL, L"Full Control" },
	{ 4, GENERIC_READ,                    0, L"Read" },
	{ 4, GENERIC_WRITE,                   0, L"Write" },
	{ 4, DELETE,                          0, L"Delete (D)" },
	{ 4, WRITE_DAC,                       0, L"Change Permissions (P)" },
	{ 4, WRITE_OWNER,                     0, L"Take Ownership (O)" },
};
///Explorer File Settings
ACLEDITENTRY aclEditEntryFile[] = {
	{ 2, GENERIC_READ,                    0, L"&Read (R)" },
	{ 2, GENERIC_WRITE,                   0, L"&Write (W)" },
	{ 2, GENERIC_EXECUTE,                 0, L"E&xecute (X)" },
	{ 2, DELETE,                          0, L"&Delete (D)" },
	{ 2, WRITE_DAC,                       0, L"Change &Permissions (P)" },
	{ 2, WRITE_OWNER,                     0, L"Change &Owner (O)" },
	{ 1, 0,                               0, L"No Access" },
	{ 1, GENERIC_READ | GENERIC_EXECUTE,  0, L"Read" },
	{ 1, GENERIC_READ | GENERIC_WRITE | GENERIC_EXECUTE,
	0, L"Change" },
	{ 1, GENERIC_ALL,                     0, L"Full Control" },
};
///Explorer and Registry SACL Settings
///The following is the entry used for the SedSystemAclEditor function :

ACLEDITENTRY saclEditEntry[] = {
	{ 5, GENERIC_READ | ACCESS_SYSTEM_SECURITY, 0, L"&Read" },
	{ 5, GENERIC_WRITE | ACCESS_SYSTEM_SECURITY, 0, L"&Write" },
	{ 5, GENERIC_EXECUTE, 0, L"E&xecute" },
	{ 5, DELETE, 0, L"&Delete" },
	{ 5, WRITE_DAC, 0, L"Change &Permissions" },
	{ 5, WRITE_OWNER, 0, L"&Take Ownership" },
};

DWORD            AccessMasks[4] = {
	0x120089, 0x120116, 0x1200A0, 0x1F01FF
};


DWORD            RegistryAccessMasks[4] = {
	0x120019, 0x20006, 0x20019, 0xF003F
};

//////////////////////////////////////////////////////////////////////////
//
//
//
//
//
//
//////////////////////////////////////////////////////////////////////////
INT_PTR CALLBACK DlgPropSheet(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
	HWND hWndTab = GetDlgItem(hDlg, IDS_PROCPROPSHEET_TABCTRL);

	LPPROPITEM PropItem = (LPPROPITEM)GetWindowLongPtr(hDlg, GWLP_USERDATA);


	if (msg == WM_INITDIALOG)
	{
		TCITEM tabItem = { 0 };

		ShowWindow(hDlg, SW_HIDE);
		CResizer* Resizer = new CResizer(hDlg);
		PPROPITEM PropItem = (PPROPITEM)lParam;

		SetWindowLongPtr(hDlg, GWLP_USERDATA, (LPARAM)lParam);
		PropItem = (LPPROPITEM)lParam;

		tabItem.mask = TCIF_TEXT | TCIF_IMAGE;
		tabItem.iImage = -1;

		SetWindowLong(hWndTab, GWL_EXSTYLE, GetWindowLong(hWndTab, GWL_EXSTYLE) | WS_EX_CONTROLPARENT);
		SetWindowLong(hWndTab, GWL_STYLE, GetWindowLong(hWndTab, GWL_STYLE) | WS_CLIPCHILDREN);

		if (PropItem->pListItem)
		{
			tabItem.pszText = TEXT("Image");
			TabCtrl_InsertItem(hWndTab, 0, &tabItem);

			_tcscpy_s(PropItem->PageData[1].szTemplateName, MAX_TEMPLATE_NAME_LEN, L"PROCPERF");
			PropItem->PageData[1].nTabId = 2;
			//PropItem->PageData[1].PageWndProc = (WNDPROC)PropPageProcPerf;
			tabItem.pszText = TEXT("Performance");
			TabCtrl_InsertItem(hWndTab, 1, &tabItem);

			PSH_NOAPPLYNOW;
		}


	}
	return TRUE;
}

//////////////////////////////////////////////////////////////////////////
//
//
//
//
//
//
//
//////////////////////////////////////////////////////////////////////////
INT_PTR CALLBACK PropPageProcCclr(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_INITDIALOG:
	{
		HWND hWndParent = GetParent(hWnd);
		PVOID pUserData = (PVOID)GetWindowLongPtr(hWndParent, GWLP_USERDATA);
		CResizer* pResizer = new CResizer(hWnd);
		//UpdateTabPos(hWnd);
		//if (IsBuiltinAndAdministrative()
		//	&& gpfnGetVersion() >= 6)
		//{
		//	PROPCCLRINFO* pInfo = new PROPCCLRINFO();
		//	pInfo->m_hWndParent = hWnd;
		//	pInfo->m_dwProcessID;
		//}
		break;
	}
	default:
		break;
	}

	return 0;
}

//////////////////////////////////////////////////////////////////////////
//
//
//
//
//
//
//
//////////////////////////////////////////////////////////////////////////
DWORD WINAPI PropSheetThreadProc(PVOID p)
{

	PPROPITEM PropItem = new PROPITEM();

	HWND hWndPropSheet = CreateDialogParam(ghMainInstance,
		MAKEINTRESOURCE(IDD_PROCPROPSHEET),
		ghMainWnd,
		(DLGPROC)DlgPropSheet,
		(LPARAM)PropItem);


	return 0;
}


HRESULT PropSheet_UpdateTab(HWND hWnd)
{
	HWND hWndParent = GetParent(hWnd);
	HWND hWndTab = GetDlgItem(hWndParent, IDS_PROCPROPSHEET_TABCTRL);
	if (hWndTab)
	{
		RECT rect;
		GetWindowRect(hWndTab, &rect);
		SendMessage(hWndTab, TCM_ADJUSTRECT, 0, (LPARAM)&rect);
		MapWindowPoints(NULL, hWnd, (LPPOINT)&rect, 2);
		SetWindowPos(hWnd, NULL, rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top, SWP_NOACTIVATE);
		if (gpfnEnableThemeDialogTexture)
			return gpfnEnableThemeDialogTexture(hWnd, ETDT_ENABLE|ETDT_USETABTEXTURE);

	}
	return S_OK;
}