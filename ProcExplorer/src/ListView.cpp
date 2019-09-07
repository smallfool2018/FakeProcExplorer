#include "stdafx.h"
#include "../ProcExplorer.h"


LONG gnCounter = 0;
HCURSOR ghCursorArrow = NULL;
HCURSOR ghCursorFind = NULL;
WNDPROC gOldListWndProc = NULL;

void UpdateTooltips(HWND hWndTooltips);

//////////////////////////////////////////////////////////////////////////
//
//
//
//
//
//
//////////////////////////////////////////////////////////////////////////
HWND CreateListCtrl(HWND hWndParent, DWORD dwStyle, USHORT* pnWidths, int* pnIDs, ULONG ColumnCount, UINT nCtrlID)
{
	InitCommonControls();
	RECT rcClient;
	GetClientRect(hWndParent, &rcClient);

	HWND hWndList = CreateWindowEx(0,
		WC_LISTVIEW,
		TEXT(""),
		dwStyle,
		rcClient.left,
		rcClient.top,
		rcClient.right,
		rcClient.bottom,
		hWndParent,
		(HMENU)nCtrlID,
		ghInstance,
		NULL);
	if (!hWndList)
		return NULL;

	if (!InitListCtrl(hWndList, pnWidths, pnIDs, ColumnCount))
	{
		DestroyWindow(hWndList);
		return NULL;
	}

	SetClassLong(hWndList, GCLP_HCURSOR, NULL);
	gOldListWndProc = (WNDPROC)SetWindowLongPtr(hWndList, GWLP_WNDPROC, (LONG_PTR)Proxy_ListCtrlWndProc);

	DWORD dwExStyle = LVS_EX_HEADERDRAGDROP|LVS_EX_FULLROWSELECT|LVS_EX_LABELTIP;
	SendMessage(hWndList, LVM_SETEXTENDEDLISTVIEWSTYLE, dwExStyle, dwStyle);

	HWND hWndHeader = ListView_GetHeader(hWndList);
		///(HWND)SendMessage(hWndList, LVM_GETHEADER, 0, 0);


	HWND hWndTooltips = ListView_GetToolTips(hWndList);

	///	(HWND)SendMessage(hWndList, LVM_GETTOOLTIPS, 0, 0);

	UpdateTooltips(hWndTooltips);

	HIMAGELIST hImageList = InitSortableImageList();
	SetWindowLongPtr(hWndList, GWL_STYLE, GetWindowLongPtr(hWndList, GWL_STYLE) | LVS_SHAREIMAGELISTS);
	SendMessage(hWndList, LVM_SETIMAGELIST, (WPARAM)TRUE, (LPARAM)hImageList);

	return hWndList;
}

//////////////////////////////////////////////////////////////////////////
//
//
//
//
//
//
//////////////////////////////////////////////////////////////////////////
BOOL InitListCtrl(HWND hWndList, USHORT* pnWidths, int* pnIDs, ULONG ColumnCount)
{
	return TRUE;
}

//////////////////////////////////////////////////////////////////////////
//
//
//
//
//
//
//////////////////////////////////////////////////////////////////////////
void UpdateTooltips(HWND hWndTooltips)
{
	Tooltips_SetDelayTime(hWndTooltips,TTDT_INITIAL, 0);
	Tooltips_SetMaxWidth(hWndTooltips, 4000);
	Tooltips_SetDelayTime(hWndTooltips, TTDT_AUTOPOP, 1000000);

	////SendMessage(hWndTooltips, TTM_SETDELAYTIME, TTDT_INITIAL, 0);
	////SendMessage(hWndTooltips, TTM_SETMAXTIPWIDTH, 0, 4000);
	////SendMessage(hWndTooltips, TTM_SETDELAYTIME, TTDT_AUTOPOP, 1000000);


}

//////////////////////////////////////////////////////////////////////////
//
//
//
//
//
//
//////////////////////////////////////////////////////////////////////////
LRESULT CALLBACK Proxy_ListCtrlWndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_KEYDOWN:
		break;
	case WM_MOUSEMOVE:
		break;
	case WM_NOTIFY:
		break;
	case WM_SETFOCUS:
	case WM_KILLFOCUS:
		if (hWnd == ghWndTreeListView && (HWND)wParam != ghWndTreeListView)
			InvalidateRect(ghWndTreeListView, NULL, FALSE);
		break;
	case WM_ERASEBKGND:
	{
		int nItemCount = ListView_GetItemCount(hWnd);
		if (!nItemCount)
			break;
		RECT rcClient;
		RECT rcItem;
		GetClientRect(hWnd, &rcClient);
		//ListView_GetItemRect(hWnd, nItem - 1, &rcItem, );
		SendMessage(hWnd, LVM_GETITEMRECT, nItemCount - 1, (LPARAM)&rcItem);
		HDC hDC = (HDC)wParam;
		RECT rc;
		rc.left = rcItem.right;
		FillRect(hDC, &rc, GetSysColorBrush(COLOR_WINDOW));

	}
		break;
	case WM_SETCURSOR:
		if (hWnd == ghWndDllsListCtrl)
		{
			SetCursor(ghCursorArrow);
			return TRUE;
		}
		else
		{
			if (gnCounter)
			{
				SetAppStringCursor();
			}
			else
			{
				SetArrowCursor();
			}
		}
		return TRUE;
		break;
	default:
		break;
	}
	return CallWindowProc(gOldListWndProc, hWnd, msg, wParam, lParam);
}