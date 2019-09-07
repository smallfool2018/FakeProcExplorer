#include "stdafx.h"
#include "..\include\TreeList.h"
#include <commctrl.h>
#pragma comment(lib,"Comctl32.lib")

#define WC_TREELIST TEXT("TreeListWindowClass")

static ATOM gAtomTreeList = CTreeList::Register();
static ATOM gszTreeListPropName = GlobalAddAtom(TEXT("TreeListProperty"));
static CModule gUxthemeHandle(TEXT("uxtheme.dll"));

#define TIMERID_REFRESH_TOOLTIPS	100
#define TIMEOUT_REFRESH_TOOLTIPS	500

bool gbWindowTextFlags = false;
WCHAR* gpszWindowText = NULL;
DWORD gdwWindowTextLength = 0;
HWND ghMainWndBackup = NULL;
DWORD gdwProcessIdSelected = 0;
LONG gnRefCount = 0;

DWORD WINAPI PropertiesThreadProc(void* p);

LPFN_CloseThemeData gpfnCloseThemeData = (LPFN_CloseThemeData)gUxthemeHandle.GetFunc("CloseThemeData");
LPFN_OpenThemeData gpfnOpenThemeData = (LPFN_OpenThemeData)gUxthemeHandle.GetFunc("OpenThemeData");
LPFN_IsThemeActive gpfnIsThemeActive = (LPFN_IsThemeActive)gUxthemeHandle.GetFunc("IsThemeActive");
LPFN_DrawThemeBackground gpfnDrawThemeBackground = (LPFN_DrawThemeBackground)gUxthemeHandle.GetFunc("DrawThemeBackground");
LPFN_EnableThemeDialogTexture gpfnEnableThemeDialogTexture = (LPFN_EnableThemeDialogTexture)gUxthemeHandle.GetFunc("EnableThemeDialogTexture");


tagTREEVIEWITEMPARAM* gpTreeViewListItemParam = NULL;
INT_PTR CALLBACK ProcPropSheet(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

BOOL __stdcall EnumChildrenWindows(HWND hWnd, LPARAM lParam);

extern CGraphData* InitGraphData(int nCount, int nChildID, BOOL fFlags);

//////////////////////////////////////////////////////////////////////////
///
void TreeViewItemParam_InitGraph(tagTREEVIEWITEMPARAM* pItem)
{
	const double dbl_onehundred = 100.0;
	const double dbl_one = 1.0;

	if (!pItem->pGraphData1)
	{
		pItem->pGraphData1 = InitGraphData(1, 2, 0);
		pItem->pGraphData1->m_nItemID = 0;
		pItem->pGraphData1->m_Color = RGB(60,148,60);	///有点偏深绿色
		pItem->pGraphData1->m_dbMemorySize = dbl_onehundred;
		if (pItem->pGraphData1->m_nChildID == 2)
		{
			pItem->pGraphData1->m_Item[0].dwValue[5] = 255;
			*(double*)&pItem->pGraphData1->m_Item[0].dwValue[3] = dbl_onehundred;
		}
		if (pItem->dwProcessId)
		{
			if (pItem->dwProcessId == -10)
				pItem->pGraphData1->m_Color = 255;
		}
		else
		{
			pItem->pGraphData1->m_Item[0].dwValue[5] = RGB(60, 148, 60);///有点偏深绿色
		}
	}
	if (!pItem->pGraphData2)
	{
		pItem->pGraphData2 = InitGraphData(1, 1, 0);
		pItem->pGraphData2->m_nItemID = 1;
		pItem->pGraphData2->m_Color = RGB(0,170,170); ///0xAAAA	///有点蓝绿色
		pItem->pGraphData2->m_dbMemorySize = dbl_onehundred;
	}
	if (!pItem->pGraphDataPROCCPU)
	{
		pItem->pGraphDataPROCCPU = InitGraphData(1, 2, 0);
		pItem->pGraphDataPROCCPU->m_nItemID = 2;
		pItem->pGraphDataPROCCPU->m_Color = RGB(200, 60, 30);	/// 0xC83C1E;
		pItem->pGraphDataPROCCPU->m_dbMemorySize = dbl_one;
		pItem->pGraphDataPROCCPU->m_Item[0].dwValue[5] = RGB(200, 60, 200);/// 0xC83CC8;
		*(double*)&pItem->pGraphDataPROCCPU->m_Item[0].dwValue[3] = dbl_one;
	}
	if (gdwAdapterRuntingTime)
	{
		pItem->pGraphData4 = InitGraphData(1, 1, 0);

		pItem->pGraphData4->m_nItemID = 4;
		pItem->pGraphData4->m_Color = RGB(128, 128, 255);///0x8080FF;
		pItem->pGraphData4->m_dbMemorySize = dbl_onehundred;
		pItem->pGraphData5 = InitGraphData(1, 1, 0);
		pItem->pGraphData5->m_nItemID = 7;
		pItem->pGraphData5->m_Color = RGB(255, 192, 128);/// 0xFFC080;
		pItem->pGraphData5->m_dbMemorySize = dbl_one;
		pItem->pGraphData6 = InitGraphData(1, 1, 0);
		pItem->pGraphData6->m_nItemID = 5;
		pItem->pGraphData6->m_Color = RGB(0, 170, 170); ///0xAAAA	///有点蓝绿色
		pItem->pGraphData6->m_dbMemorySize = dbl_one;
		pItem->pGraphData7 = InitGraphData(1, 1, 0);
		pItem->pGraphData7->m_nItemID = 6;
		pItem->pGraphData7->m_Color = RGB(64, 128, 255);/// 0x4080FF;
		pItem->pGraphData7->m_dbMemorySize = dbl_one;
	}
}

void TreeViewItemParam_AddRef(tagTREEVIEWITEMPARAM* pItem)
{
	InterlockedIncrement(&pItem->nRefCount);
}
void TreeViewItemParam_Release(tagTREEVIEWITEMPARAM*& pItem)
{
	if (!InterlockedDecrement(&pItem->nRefCount))
		delete pItem;
}


//////////////////////////////////////////////////////////////////////////
CTreeList::CTreeList()
	:m_hWnd(NULL)
	,m_hWndHeaderLeft(NULL)
	,m_hWndHeaderRight(NULL)
{
}


CTreeList::~CTreeList()
{
}

//////////////////////////////////////////////////////////////////////////
//
//	CTreeList::WndProc
//	
//////////////////////////////////////////////////////////////////////////
LRESULT CALLBACK CTreeList::WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	CTreeList* pThis = (CTreeList*)GetProp(hWnd, MAKEINTATOM(gszTreeListPropName));
	if (pThis)
		return pThis->TreeWndProc(hWnd, msg, wParam, lParam);
	return DefWindowProc(hWnd, msg, wParam, lParam);
}

void CTreeList::InitToolTips(HWND hWndTooltips)
{
	SendMessageW(hWndTooltips, TTM_SETDELAYTIME, TTDT_INITIAL, 0);
	SendMessageW(hWndTooltips, TTM_SETMAXTIPWIDTH, 0, 4000);
	SendMessageW(hWndTooltips, TTM_SETDELAYTIME, TTDT_AUTOPOP, 1000000);
}

extern FILETIME RequerySystemStatus(SYSTEM_PROCESS_INFORMATION **ppSystemProcessInfo,
	PULONG cbRet,
	SYSTEM_PROCESSOR_PERFORMANCE_INFORMATION *pSystemProcessorPerformanceInfo,
	SYSTEM_INTERRUPT_INFORMATION *pSystemInterruptInfo,
	SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *pSystemProcessorCycleTimeInfo,
	void *pBufferIn,
	int* pdwBufLen);

BOOL IsColumnIDValid(HWND hWnd, UINT nID)
{
	DWORD nIndex = 0;
	if (gConfig.dwProcessColumnCount <= 0)
		return FALSE;
	while (gConfig.dwProcessColumnMap[nIndex] != nID)
	{
		if (++nIndex >= gConfig.dwProcessColumnCount)
			return FALSE;
	}
	return TRUE;
}

BOOL CTreeList::InitTreeList(HWND hWndList, BOOL Flags /* = TRUE */)
{
	PE_FlushTrace(&gProperties);

	////if (gbShowProcessTreeLast)
	////{

	////}
	PVOID pBuffer = NULL;
	gpSystemProcessInfoLast = gpSystemProcessInfo;
	gnSystemProcessInfoLengthLast = gnSystemProcessInfoLengthLast;
	
	gTimeQuerySystemInfoLast = gTimeQuerySystemInfo;

	int	cbRet = 0;
	gTimeQuerySystemInfo = RequerySystemStatus(&gpSystemProcessInfo,
		&gnSystemProcessInfoLength,
		gpSystemPerformanceInfo,
		gpSystemInterruptInfo,
		gpSystemProcessorCycleTimeInfo,
		pBuffer,
		&cbRet);

	//if (gTreeViewListItemParam)
	//{

	//}

	if (IsColumnIDValid(ghWndTreeListView, 35)
		|| IsColumnIDValid(ghWndTreeListView, 1196))
	{
		WCHAR	szText[256] = { 0 };
		wcscpy_s(szText, 256, gszNullString);
		ghMainWndBackup = NULL;
		if ((DWORD)gpSystemProcessInfo->UniqueProcessId == GetCurrentProcessId())
		{
			ghMainWndBackup = ghMainWnd;
			GetWindowTextW(ghMainWnd, gpszWindowText, 256);
		}
		else
		{
			gbWindowTextFlags = false;
			gpszWindowText = szText;
			gdwWindowTextLength = 256;
			EnumWindows(EnumChildrenWindows, (DWORD)gpSystemProcessInfo->UniqueProcessId);
		}

		//BOOL fHungFlags = gpTreeViewListItemParam->bMainWndIsHung;
		//if (IsColumnIDValid(ghWndTreeListView, 1196) && ghMainWndBackup)
		//{
		//	fHungFlags = IsHungAppWindow(ghMainWndBackup);
		//}
	}

	return TRUE;
}

//////////////////////////////////////////////////////////////////////////
//
//	CTreeList::Register
//	
//////////////////////////////////////////////////////////////////////////
ATOM CTreeList::Register()
{
	WNDCLASSEXW wc = { sizeof(wc) };

	wc.cbSize = sizeof(WNDCLASSEXW);
	wc.lpfnWndProc = CTreeList::WndProc;
	wc.hCursor = LoadCursorW(0, IDC_ARROW);
	wc.hbrBackground = 0;
	wc.lpszMenuName = 0;
	wc.style = CS_DBLCLKS;
	wc.lpszClassName = WC_TREELIST;
	return RegisterClassExW(&wc);
}

//////////////////////////////////////////////////////////////////////////
//
//	CTreeList::CreateTooltips
//	
//////////////////////////////////////////////////////////////////////////
HWND CTreeList::CreateTooltips(HINSTANCE hInst, HWND hWndParent)
{
	TOOLINFOW ToolInfo = { sizeof(ToolInfo) };
	DWORD dwStyle = WS_POPUP| TTS_NOPREFIX | TTS_ALWAYSTIP | TTS_NOANIMATE | TTS_NOFADE;
	HWND hWnd = CreateWindowExW(0, L"tooltips_class32", L"", dwStyle, 0, 0, 0, 0, hWndParent, 0, hInst, NULL);
	ToolInfo.uFlags = TTF_TRANSPARENT;
	ToolInfo.hwnd = hWndParent;
	ToolInfo.lpszText = (LPWSTR)(-1);
	GetClientRect(hWndParent, &ToolInfo.rect);
	SendMessage(hWnd, TTM_ADDTOOLW, 0, (LPARAM)&ToolInfo);
	return hWnd;
}

//////////////////////////////////////////////////////////////////////////
//
//	CTreeList::Init
//	
//	hWndParent:
//	hInstance:
//	hMenuID:
//	dwStyle:
//	lprc:
//
//	Return value:
//
//////////////////////////////////////////////////////////////////////////
HWND CTreeList::Init(HWND hWndParent, HINSTANCE hInstance, HMENU hMenuID, DWORD dwStyle, RECT *lprc)
{
	CTreeList *pThis = new CTreeList();
	pThis->m_hWnd = CreateWindowEx(0, 
		MAKEINTATOM(gAtomTreeList), 
		TEXT(""), 
		dwStyle | WS_CLIPCHILDREN, 
		lprc->left, 
		lprc->top,
		lprc->right - lprc->left,
		lprc->bottom - lprc->top, 
		hWndParent, 
		hMenuID, 
		hInstance, 
		(LPVOID)pThis);

	pThis->OnInited();

	return pThis->m_hWnd;
}

CTreeList* CTreeList::GetTreeList(HWND hWnd)
{
	return (CTreeList*)GetPropW(hWnd, MAKEINTRESOURCEW(gszTreeListPropName));
}



//////////////////////////////////////////////////////////////////////////
//
//	CTreeList::Proxy_TooltipWndProc
//	
//////////////////////////////////////////////////////////////////////////
LRESULT CALLBACK CTreeList::Proxy_TooltipWndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	CTreeList* pThis = (CTreeList*)GetProp(hWnd, MAKEINTRESOURCE(gszTreeListPropName));
	if (pThis)
	{
		if (msg != WM_TIMER)
			return CallWindowProc(pThis->m_TooltipWndProc, hWnd, msg, wParam, lParam);
		if(!pThis->m_bSkipTimerForTooltip)
			return CallWindowProc(pThis->m_TooltipWndProc, hWnd, msg, wParam, lParam);
		return 0;
	}
	
	return DefWindowProc(hWnd, msg, wParam, lParam);
}

void CTreeList::ResetImageList(HIMAGELIST hImgList, bool flags)
{
	if (!this->m_ImageList || m_NotMyImageList)
		m_ImageList = hImgList;
	else
	{
		ImageList_Destroy(m_ImageList);
		m_ImageList = hImgList;
	}
	m_NotMyImageList = flags;
}

void CTreeList::SetSortFlagsImageList(HIMAGELIST hImgList, int x, int y)
{

}

bool gbBitmapOnRight = false;

void CTreeList::SetHeaderItem(HWND hWndHeader, int nItem, BOOL Flags)
{
	HDITEMW Item = { 0 };
	DWORD	dwFormat = 0;
	if (gbBitmapOnRight)
	{
		dwFormat = -(HDF_BITMAP | HDF_SORTUP | HDF_SORTDOWN | HDF_RIGHT);
	}
	else
	{
		dwFormat = -(HDF_BITMAP_ON_RIGHT | HDF_SORTDOWN | HDF_SORTDOWN | HDF_RIGHT);
	}

	if (Flags)
	{
		if (gbBitmapOnRight)
		{
			Item.mask = HDI_FORMAT;
			Header_GetItem(hWndHeader, nItem, &Item);
			Item.fmt = Item.fmt & dwFormat | (Flags >= 0 ? HDF_SORTDOWN : HDF_SORTUP);
		}
		else
		{
			Item.mask = HDI_FORMAT | HDI_IMAGE;
			Header_GetItem(hWndHeader, nItem, &Item);
			Item.fmt |= HDF_BITMAP_ON_RIGHT | HDF_IMAGE;
			Item.iImage = Flags < 0 ? 1 : 0;
		}
	}
	else
	{
		Item.mask = HDI_FORMAT;
		Header_GetItem(hWndHeader, nItem, &Item);
		if (gbBitmapOnRight)
		{
			Item.fmt &= -(HDF_BITMAP | HDF_SORTUP | HDF_SORTDOWN | HDF_RIGHT);
		}
		else
		{
			Item.fmt &= -(HDF_BITMAP_ON_RIGHT | HDF_SORTDOWN | HDF_SORTDOWN | HDF_RIGHT);
		}
	}
	Header_SetItem(hWndHeader, nItem, &Item);
	UpdateWindow(hWndHeader);
	//IMAGEAPI
	//	SymGetSymFromName(
	//		HANDLE hProcess,PCSTR Name,	PIMAGEHLP_SYMBOL Symbol
	//	);
	//FindExecutableImage(PCSTR FileName,PCSTR SymbolPath,PSTR ImageFilePath)
	//SymLoadModuleExW(
	//	HANDLE hProcess,HANDLE hFile,PCWSTR ImageName,PCWSTR ModuleName,DWORD64 BaseOfDll,DWORD DllSize,PMODLOAD_DATA Data,DWORD Flags
	//);
}

//////////////////////////////////////////////////////////////////////////
///
///
///
///
///
//////////////////////////////////////////////////////////////////////////
int CTreeList::FindChild(tagTreeViewChildItem* pChild)
{
	if (!pChild)
		return -1;
	tagTreeViewChildItem* pChildren = m_ChildItem;
	if (!pChildren)
		return -1;
	int index = 0;

	while (pChildren != pChild)
	{
		++index;
		if (pChildren->m_Next && (pChildren->m_dwStyle >> 4) & 1)
		{
			pChildren = pChildren->m_Next;
		}
		else if (pChildren->m_Prev)
		{
			pChildren = pChildren->m_Prev;
		}
		else
		{
			tagTreeViewChildItem* pCurrent = pChildren->m_Current;
			if (!pCurrent)
				return -1;
			while (!pCurrent->m_Prev)
			{
				pCurrent = pCurrent->m_Current;
				if (!pCurrent)
					return -1;
			}
			pChildren = pCurrent->m_Prev;
		}
		if (!pChildren)
			return -1;
	}
	return index;

}
//////////////////////////////////////////////////////////////////////////
LRESULT CTreeList::FindItem(HWND hWndTree, LPARAM lParam)
{
	SendMessage(hWndTree, WM_SETREDRAW, 0, 0);

	tagTREEVIEWITEMPARAM* pItemParam = new tagTREEVIEWITEMPARAM();
	////CopyMemory(pItemParam, lParam, sizeof(tagTREEVIEWITEMPARAM));



	return LRESULT(pItemParam);
}

void CTreeList::InitHeaderColumn(int nItem, bool flags /* = false */)
{

}

void CTreeList::InitHeaderColumn(HWND hWndTreeListView, int nItem /* = -1 */, DWORD dwProcessSortColumn /* = 0 */, bool bProcessSortDirection /* = false */)
{
	CTreeList* pTreeList = CTreeList::GetTreeList(hWndTreeListView);
	if (pTreeList)
		pTreeList->InitHeaderColumn(dwProcessSortColumn, bProcessSortDirection);
	else
	{
		HWND hWndHeader = ListView_GetHeader(hWndTreeListView);
		HDITEMW		hditem = { 0 };
		hditem.mask = HDI_FORMAT;
		Header_GetItem(hWndHeader, nItem, &hditem);
		if (gbBitmapOnRight)
		{
			hditem.fmt &= -(HDF_BITMAP | HDF_SORTUP | HDF_SORTDOWN | HDF_RIGHT);
		}
		else
		{
			hditem.fmt &= -(HDF_BITMAP_ON_RIGHT | HDF_SORTDOWN | HDF_SORTDOWN | HDF_RIGHT);
		}
		Header_SetItem(hWndHeader, nItem, &hditem);
		UpdateWindow(hWndHeader);

		hWndHeader = ListView_GetHeader(hWndTreeListView);

		SetHeaderItem(hWndHeader, nItem, bProcessSortDirection ? 1 : -1);
	}
}


void CTreeList::DrawHeader(HWND hWnd, HDC hDC, RECT rc)
{


	int nCount = 0;
	if (hWnd == m_hWndHeaderLeft)
	{
		nCount = 1;
	}
	else
	{
		nCount = Header_GetItemCount(m_hWndHeaderRight);
		if (!nCount)
		{
			FillRect(hDC, &rc, GetSysColorBrush(COLOR_WINDOW));
			return;
		}
	}

	UINT *pnIds = new UINT[nCount];
	if (hWnd == m_hWndHeaderLeft)
		*pnIds = 0;
	else
		Header_GetOrderArray(m_hWndHeaderRight, nCount, pnIds);
	RECT *pRect = new RECT[nCount];
	UINT *pFormat = new UINT[nCount];
	HDITEMW Item = { 0 };

	int index = 0;
	for (index = 0; index < nCount; index++)
	{
		Header_GetItemRect(hWnd, pnIds[index], &pRect[index]);
		InflateRect(&pRect[index], -2, -2);

		//////if (m_nScrollBar)
		//////{
		//////	SCROLLINFO ScrollInfo = { sizeof(SCROLLINFO) };
		//////	ScrollInfo.fMask = SIF_POS;
		//////	GetScrollInfo(m_hWndScrollBarLeftBottom, SB_CTL, &ScrollInfo);

		//////	pRect[index].left -= ScrollInfo.nPos;
		//////	int right = pRect[index].left + m_nChildWidthLast;
		//////	if (pRect[index].right < right)
		//////		pRect[index].right = right;
		//////}


		pFormat[index] = m_Format;
		if (hWnd != m_hWndHeaderLeft)
		{
			Item.mask = HDI_FORMAT;
			Header_GetItem(m_hWndHeaderRight, pnIds[index], &Item);
			if (Item.fmt & HDF_RIGHT)
				pFormat[index] |= DT_RIGHT;
		}

		if (nCount > index&&pRect[index].right > rc.left)
			nCount = index;
		if (pRect[index].left < rc.right)
		{

		}
	}
	HDC hDCWindow = GetDC(hWnd);
	SelectObject(hDCWindow, m_Font);
	TEXTMETRIC tm = { 0 };
	GetTextMetrics(hDCWindow, &tm);
	ReleaseDC(m_hWnd, hDCWindow);

	if (m_ImageList)
		GetSystemMetrics(SM_CYSMICON);

	RECT	rcLeftHeader;
	GetWindowRect(m_hWndHeaderRight, &rcLeftHeader);

	HFONT hOldFont = (HFONT)::SelectObject(hDC, m_Font);
	HPEN hPen = CreatePen(PS_SOLID, 1, GetSysColor(COLOR_3DDKSHADOW));
	HPEN hOldPen = (HPEN)SelectObject(hDC, hPen);

	{
		UINT* nFormat = &pFormat[nCount];
		RECT* rcItem = &pRect[nCount];
		int nOffset = pnIds - pFormat;
		WCHAR szText[260] = { 0 };
		RECT rcText = { 0 };
		UINT nCount0 = 0;
		do
		{
			COLORREF BkColor = GetBkColor(hDC);
			if (hWnd == this->m_hWndHeaderLeft)
				nCount0 = nCount;
			else
				nCount0 = *(nFormat + nOffset) + 1;
			if ((this->m_DrawBack)(nCount0, hDC, &BkColor))
			{
				ValidateRect(hWnd, rcItem);
				HBRUSH hBrush = CreateSolidBrush(BkColor);
				GetBkMode(hDC);
				Item.pszText = szText;
				Item.mask = HDI_TEXT;
				Item.cchTextMax = 260;
				Header_GetItem(hWnd, *(nFormat + nOffset), &Item);

				rcText.left = this->m_nImageWidth + rcItem->left;
				rcText.top = this->m_Height + rcItem->top;
				rcText.right = rcItem->right - this->m_nImageWidth;
				rcText.bottom = rcItem->bottom;
				ZeroMemory(&rcLeftHeader, sizeof(RECT));

				DrawTextW(hDC, szText, -1, &rcLeftHeader, *nFormat | DT_CALCRECT);
				if (rcText.bottom - rcText.top < rcLeftHeader.bottom)
					rcText.top = rcText.bottom - rcLeftHeader.bottom;
				SetBkColor(hDC, BkColor);
				FillRect(hDC, rcItem, hBrush);
				DrawTextW(hDC, szText, -1, &rcText, *nFormat);
				DeleteObject(hBrush);
			}
			++rcItem;
			++nCount;
			++nFormat;
		} while (nCount <= index);
	}

	SelectObject(hDC, hOldPen);
	SelectObject(hDC, hOldFont);

	delete[]pFormat;
	delete[]pnIds;
	delete[]pRect;
}
//////////////////////////////////////////////////////////////////////////
//
//	CTreeList::Proxy_HeaderWndProc
//	
//////////////////////////////////////////////////////////////////////////
LRESULT CALLBACK CTreeList::Proxy_HeaderWndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	CTreeList* pThis = (CTreeList*)GetProp(hWnd, MAKEINTRESOURCE(gszTreeListPropName));
	if (pThis)
		return pThis->HeaderWndProc(hWnd, msg, wParam, lParam);
	return DefWindowProc(hWnd, msg, wParam, lParam);
}

//////////////////////////////////////////////////////////////////////////
//
//	CTreeList::HeaderWndProc
//	
//////////////////////////////////////////////////////////////////////////
LRESULT CTreeList::HeaderWndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	HWND hWndTooltip = hWnd == m_hWndHeaderLeft ? m_hWndTooltipOfLeftHeader : m_hWndTooltipOfRightHeader;

	if (msg <= WM_XBUTTONDBLCLK)
	{
		POINT point;
		point.x = LOWORD(lParam);
		point.y = HIWORD(lParam);

		MapWindowPoints(hWnd, m_hWnd, &point, 1);
		this->PopTooltip(hWndTooltip, &point);
		MSG Msg = { 0 };
		Msg.hwnd = hWnd;
		Msg.message = msg;
		Msg.wParam = wParam;
		Msg.lParam = lParam;
		Msg.pt.x = 0;
		Msg.pt.y = 0;

		SendMessage(hWndTooltip, TTM_RELAYEVENT, 0, (LPARAM)&Msg);

		return CallWindowProc(m_HeaderWndProc, hWnd, msg, wParam, lParam);

	}
	if (msg == WM_PAINT)
	{
		if (m_DrawBack)
		{
			HDC hDC = GetDC(hWnd);
			RECT rc = { 0 };
			GetUpdateRect(hWnd, &rc, FALSE);
			this->DrawHeader(hWnd, hDC, rc);
			ReleaseDC(hWnd, hDC);
		}
	}
	else if (msg == WM_NOTIFY)
	{
		if (hWnd != m_hWndTooltipOfLeftHeader)
			return CallWindowProc(m_HeaderWndProc, hWnd, msg, wParam, lParam);
		NMHDR* pNMHDR = (NMHDR*)lParam;
		if(pNMHDR->hwndFrom!=hWndTooltip)
			return CallWindowProc(m_HeaderWndProc, hWnd, msg, wParam, lParam);
		 
		if (pNMHDR->code == TTN_NEEDTEXTW)
		{
			tagNMLVGETINFOTIPW* pNMHDRX = (tagNMLVGETINFOTIPW*)pNMHDR;

			HDITEMW Item = { 0 };
			Item.mask = HDI_TEXT | HDI_FORMAT | HDI_WIDTH;
			Item.pszText = pNMHDRX->pszText;
			Item.cchTextMax = 80;
			int nItem = m_nHeaderItemCount;
			if (nItem != -1)
			{
				if (hWndTooltip != m_hWndTooltipOfLeftHeader)
					--nItem;
			}

			//////if (ListView_GetItem(hWnd, &Item))
			//////{
			//////	nItem = m_nHeaderItemCount;
			//////	if (nItem != -1)
			//////	{
			//////		if (hWndTooltip != m_hWndTooltipOfLeftHeader)
			//////			--nItem;
			//////	}

			//////	RECT rcItem;
			//////	Header_GetItemRect(hWnd, nItem, &rcItem);
			//////	RECT rc = { 0 };
			//////	if (rcItem.left >= 0)
			//////	{
			//////		rc.left = 0;
			//////		rc.top = 0;
			//////		rcItem.right -= 2 * rcItem.bottom;
			//////		rc.right = GetSystemMetrics(SM_CXVIRTUALSCREEN);
			//////		UINT Format = this->m_Format;
			//////		rc.bottom = this->GetLineHeight();;
			//////		HDC hDC = GetDC(m_hWnd);
			//////		HFONT hOldFont = (HFONT)SelectObject(hDC, this->m_Font);
			//////		Format = (Format & (-(HDF_STRING| HDF_RIGHT | HDF_IMAGE | HDF_SORTUP)) | HDF_SORTUP);
			//////		DrawTextW(hDC, pNMHDRX->pszText, -1, &rc, Format);
			//////		SelectObject(hDC, hOldFont);
			//////		ReleaseDC(this->m_hWnd, hDC);
			//////		pNMHDRX->dwFlags = 0;
			//////		if (rc.right - rc.left > rcItem.right - rcItem.left)
			//////			pNMHDRX->dwFlags = (DWORD)pNMHDRX->pszText;

			//////	}
			//////	else
			//////	{
			//////		pNMHDRX->dwFlags = 0;
			//////	}
			//////}
		}
		else if (pNMHDR->code == TTN_SHOW)
		{
			int nItem = this->m_nHeaderItemCount;
			if (hWndTooltip != this->m_hWndTooltipOfLeftHeader)
				--nItem;
			RECT rcItem;
			Header_GetItemRect(hWnd, nItem, &rcItem);

			MapWindowPoints(hWnd, 0, (LPPOINT)&rcItem, 2);
			rcItem.left = rcItem.bottom - rcItem.top + rcItem.left;
			rcItem.top = rcItem.bottom + rcItem.bottom - rcItem.top;
			SetWindowPos(hWndTooltip, 0, rcItem.left, rcItem.top, 0, 0, SWP_NOACTIVATE | SWP_NOZORDER | SWP_NOSIZE);
			::SendMessageW(hWndTooltip, WM_SETFONT, (WPARAM)m_Font, 0);
			return 1;
		}
	}

	return CallWindowProc(m_HeaderWndProc, hWnd, msg, wParam, lParam);
}

//////////////////////////////////////////////////////////////////////////
//
//	CTreeList::TooltipWndProc
//	
//////////////////////////////////////////////////////////////////////////
LRESULT CTreeList::TooltipWndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return CallWindowProc(m_TooltipWndProc, hWnd, msg, wParam, lParam);
}

LRESULT CTreeList::HandleListViewMsg(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case LVM_GETITEMCOUNT:
		break;
	default:
		break;
	}

	return 0;
}

tagTreeViewChildItem* CTreeList::GetCurScrollChildItem()
{
	SCROLLINFO ScrollInfo = { sizeof(ScrollInfo) };
	ScrollInfo.fMask = SIF_POS;
	GetScrollInfo(m_hWndScrollBarRightRight, SB_CTL, &ScrollInfo);

	tagTreeViewChildItem* pCurrent = NULL;
	tagTreeViewChildItem* pChildren = m_ChildItem;
	int nIndex = 0;
	if (!pChildren)
	{
		return NULL;
	}
	do 
	{
		if (nIndex >= ScrollInfo.nPos)
			break;

		if (pChildren->m_Next && (pChildren->m_dwStyle >> 4) & 1)
		{
			pChildren = pChildren->m_Next;
		}
		else if (pChildren->m_Prev)
		{
			pChildren = pChildren->m_Prev;
		}
		else
		{
			pCurrent = pChildren->m_Current;
			if (pCurrent)
			{
				while (!pCurrent->m_Prev)
				{
					pCurrent = pCurrent->m_Current;
					if (!pCurrent)
					{
						goto __NEXT;
					}
				}
				pChildren = pCurrent->m_Prev;
			}
			else
			{
__NEXT:
				pChildren = NULL;
			}
		}
		++nIndex;

	} while (pChildren);


	return pChildren;
}

//////////////////////////////////////////////////////////////////////////
//
//	CTreeList::TreeWndProc
//	
//////////////////////////////////////////////////////////////////////////
LRESULT CTreeList::TreeWndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	LVM_ISITEMVISIBLE;
	if (msg <= (LVM_FIRST+0xFF))
	{
		return this->HandleListViewMsg(hWnd, msg, wParam, lParam);
	}
	if (msg <= WM_XBUTTONDBLCLK)
	{
		MSG Event = { 0 };
		Event.hwnd = hWnd;
		Event.message = msg;
		Event.wParam = wParam;
		Event.lParam = lParam;
		

		SendMessage(m_hWndTooltipOfTreeList, TTM_RELAYEVENT, 0, (LPARAM)&Event);
	}
	if (msg == WM_LBUTTONDOWN)
	{
		POINT pt;
		pt.x = GET_X_LPARAM(lParam);
		pt.y = GET_Y_LPARAM(lParam);
		if (this->field_BC)
		{
			if (abs(pt.x - m_nBottomScrollBarWidthOrHeight) <= 8)
			{
				m_ptDownLast.x = pt.x;
				m_ptDownLast.y = pt.y;

				SetCapture(hWnd);
				SetCursor(m_hCursor);

				SetFocus(hWnd);


				int xx = 0;
				int nItem = 0;
				tagTreeViewChildItem* pChildItem = NULL;

				DWORD dwStyle = this->Query(m_ptDownLast.x, m_ptDownLast.y, &xx, 0, &pChildItem);
				if (dwStyle & (TVIF_INTEGRAL | TVIF_CHILDREN | TVIF_SELECTEDIMAGE))
				{
					this->SendNotify(m_hWnd, -2, 0, pChildItem, NULL, 0);
				}
				if (dwStyle&TVIF_CHILDREN)
				{

				}
				else if (dwStyle & (TVIF_STATEEX | TVIF_INTEGRAL | TVIF_CHILDREN | TVIF_SELECTEDIMAGE))
				{
					this->RedrawChild(pChildItem);
				}
				return this->HandleMessage(hWnd, msg, wParam, lParam);
			}
			SetCursor((HCURSOR)GetClassLongPtr(m_hWnd, GCLP_HCURSOR));
		}

		return this->HandleMessage(hWnd, msg, wParam, lParam);
	}
	if (msg == WM_LBUTTONUP)
	{
		if (GetCapture() == hWnd)
		{
			ReleaseCapture();
			SetCursor((HCURSOR)GetClassLongPtr(m_hWnd, GCLP_HCURSOR));
		}
		return this->HandleMessage(hWnd, msg, wParam, lParam);
	}
	if (msg == WM_MOUSEMOVE)
	{
		UINT fwKeys = wParam;
		BOOL bControl = fwKeys&MK_CONTROL;
		BOOL bLButton = fwKeys&MK_LBUTTON;
		POINT pt;
		pt.x = GET_X_LPARAM(lParam);
		pt.y = GET_Y_LPARAM(lParam);
		if (field_BC)
		{
			if (GetCapture() == hWnd&&bLButton)
			{
				int dx = pt.x - m_ptDownLast.x;
				if (dx)
				{
					if (m_nBottomScrollBarWidthOrHeight + dx < this->field_94)
						dx = this->field_94 - m_nBottomScrollBarWidthOrHeight;
					m_ptDownLast.x += dx;
					///移动各Header控件
					this->MoveHeaders(dx + m_nBottomScrollBarWidthOrHeight);

					///左边Header只有一个Item
					///调整左边Header的首个Item
					HDITEMW Item = { 0 };
					Item.mask = HDI_WIDTH;
					Item.cxy = dx + m_nBottomScrollBarWidthOrHeight;
					Header_SetItem(m_hWndHeaderLeft, 0, &Item);

					/// 
					this->OnSize();
				}

				SetCursor(m_hCursor);
				return this->HandleMessage(hWnd, msg, wParam, lParam);
			}
			if (abs(pt.x - m_nBottomScrollBarWidthOrHeight) <= 8)
			{
				SetCursor(m_hCursor);
				return this->HandleMessage(hWnd, msg, wParam, lParam);
			}

			HCURSOR hCursor = (HCURSOR)GetClassLongPtr(m_hWnd, GCLP_HCURSOR);
			if (m_pfnGetChildCursor)
			{
				int xx = 0; int nItem = 0;
				tagTreeViewChildItem* pItem = NULL;
				this->Query(pt.x, pt.y, &xx, &nItem, &pItem);
				if (pItem)
				{
					hCursor = m_pfnGetChildCursor(pItem, nItem);
				}
			}
			SetCursor(hCursor);
		}
		return this->HandleMessage(hWnd, msg, wParam, lParam);
	}
	if (msg == WM_MOUSEHWHEEL)
	{
		WHEEL_DELTA;
		UINT fwKeys = GET_KEYSTATE_WPARAM(wParam);
		UINT zDelta = GET_WHEEL_DELTA_WPARAM(wParam);

		////UINT nCode = LOWORD(wParam);
		////UINT nDelta = HIWORD(wParam);

		////POINT pt;
		////pt.x = GET_X_LPARAM(lParam);
		////pt.y = GET_Y_LPARAM(lParam);

		int nPos = m_nLastVScrollPos2 + zDelta;
		m_nLastVScrollPos2 = nPos;
		if (abs(nPos) > 40)
		{
			m_nLastVScrollPos2 = nPos - 40 * (nPos / 40);
			this->UpdateVScrollBars(-nPos / 40);
		}
		return this->HandleMessage(hWnd, msg, wParam, lParam);

	}
	if (msg == WM_TIMER)
	{
		if (wParam == TIMERID_REFRESH_TOOLTIPS)
		{
			POINT ptCursor;
			GetCursorPos(&ptCursor);
			MapWindowPoints(NULL, hWnd, &ptCursor, 1);
			PopTooltip(m_hWndTooltipOfTreeList, &ptCursor);
		}
		return this->HandleMessage(hWnd, msg, wParam, lParam);
	}
	if (msg == WM_HSCROLL)
	{
		if (!lParam)
			return this->HandleMessage(hWnd, msg, wParam, lParam);
		HWND hWndIn = (HWND)lParam;
		SCROLLINFO ScrollInfo = { sizeof(SCROLLINFO) };
		ScrollInfo.fMask = SIF_POS | SIF_RANGE;
		UINT nSBCode = LOWORD(wParam);
		int nPos = HIWORD(wParam);
		switch (nSBCode)
		{
		case SB_HORZ:
			--ScrollInfo.nPos;
			break;
		case SB_VERT:
			++ScrollInfo.nPos;
			break;
		case SB_CTL:
			ScrollInfo.nPos -= ScrollInfo.nPage;
			break;
		case SB_BOTH:
			ScrollInfo.nPos += ScrollInfo.nPage;
			break;
		case SB_THUMBPOSITION:
		case SB_THUMBTRACK:
			ScrollInfo.nPos = nPos;
			break;
		case SB_TOP:
			ScrollInfo.nPos = 0;
			break;
		case SB_BOTTOM:
			ScrollInfo.nPos = ScrollInfo.nMax;
			break;
		case SB_ENDSCROLL:
			return TRUE;
		default:
			return FALSE;
		}
		SetHScrollPos(hWndIn, ScrollInfo.nPos);
		return this->HandleMessage(hWnd, msg, wParam, lParam);
	}
	if (msg == WM_VSCROLL)
	{
		HWND hWndIn = m_hWndScrollBarRightRight;
		SCROLLINFO ScrollInfo = { sizeof(SCROLLINFO) };
		ScrollInfo.fMask = SIF_POS | SIF_RANGE;
		UINT nSBCode = LOWORD(wParam);
		int nPos = HIWORD(wParam);
		switch (nSBCode)
		{
		case SB_HORZ:
			--ScrollInfo.nPos;
			break;
		case SB_VERT:
			++ScrollInfo.nPos;
			break;
		case SB_CTL:
			ScrollInfo.nPos -= ScrollInfo.nPage;
			break;
		case SB_BOTH:
			ScrollInfo.nPos += ScrollInfo.nPage;
			break;
		case SB_THUMBPOSITION:
		case SB_THUMBTRACK:
			ScrollInfo.nPos = nPos;
			break;
		case SB_TOP:
			ScrollInfo.nPos = 0;
			break;
		case SB_BOTTOM:
			ScrollInfo.nPos = ScrollInfo.nMax;
			break;
		case SB_ENDSCROLL:
			return TRUE;
		default:
			return FALSE;
		}
		SetVScrollPos(hWndIn, ScrollInfo.nPos);
		return this->HandleMessage(hWnd, msg, wParam, lParam);
	}
	if (msg == WM_THEMECHANGED)
	{
		if (this->m_hThemeHandle)
		{
			gpfnCloseThemeData(m_hThemeHandle);
		}
		m_hThemeHandle = NULL;
		if (gpfnIsThemeActive&&gpfnIsThemeActive())
			gpfnOpenThemeData(hWnd, GetName());
		return this->HandleMessage(hWnd, msg, wParam, lParam);
	}
	if (msg == WM_CHAR)
	{

	}

	if (msg == WM_KEYDOWN)
	{
		switch (wParam)
		{
		case VK_PRIOR:
		case VK_NEXT:
		case VK_LEFT:
		case VK_RIGHT:
		case VK_UP:
		case VK_DOWN:
			break;
		case VK_ADD:
			if (GetKeyState(VK_LCONTROL))
			{
				int nCount = SendMessage(m_hWndHeaderRight, HDM_GETITEMCOUNT, 0, 0) + 1;
				if (nCount > 0)
				{
					int nIndex = 0;
					do 
					{
						if (nIndex)
						{

						}
						nIndex++;
					} while (nIndex < nCount);
				}
			}
			break;
		default:
			break;
		}
	}

	if (msg == WM_DESTROY)
	{
		this->OnDestroy();

		return this->HandleMessage(hWnd, msg, wParam, lParam);
		
	}
	else if (msg == WM_SIZE)
	{
		this->OnSize();
		this->RepositionHeaders();
		this->RepositionHeaders();
		tagTOOLINFOW ToolInfo = { sizeof(ToolInfo) };
		ToolInfo.hwnd = m_hWnd;
		GetClientRect(m_hWnd, &ToolInfo.rect);
		SendMessage(m_hWndTooltipOfTreeList, TTM_NEWTOOLRECTW, 0, (LPARAM)&ToolInfo);
		return this->HandleMessage(hWnd, msg, wParam, lParam);
	}
	else if (msg == WM_SETREDRAW)
	{
		if (wParam)
		{
			LRESULT lret = DefWindowProcW(hWnd, msg, wParam, lParam);
			m_bSkipTimerForTooltip = false;
			this->Refresh();
			return lret;
		}
		else
		{
			m_bSkipTimerForTooltip = true;
			return DefWindowProcW(hWnd, msg, wParam, lParam);
		}
	}
	else if (msg == WM_PAINT)
	{
		HRGN hRgn = CreateRectRgn(0, 0, 0, 0);
		if (GetUpdateRgn(hWnd, hRgn, FALSE) != 1)
		{
			PAINTSTRUCT ps = { 0 };
			BeginPaint(hWnd, &ps);

			this->DrawTree(&ps, hRgn);

			EndPaint(hWnd, &ps);
		}
		DeleteObject(hRgn);
		return 0;
	}
	else if (msg == WM_ERASEBKGND)
	{
		return TRUE;
	}
	else if (msg == WM_SETCURSOR)
	{
		HWND hWndCursor = (HWND)wParam;
		int nHitCode = LOWORD(lParam);
		int nMsg = HIWORD(lParam);
		if (hWndCursor != hWnd)
		{

		}
		return TRUE;
	}
	else if (msg == WM_SETFONT)
	{
		m_Font = (HFONT)wParam;
		RECT rc = { 0 };

		SendMessageW(m_hWndHeaderLeft, WM_SETFONT, (WPARAM)m_Font, lParam != 0);
		SendMessageW(this->m_hWndHeaderRight, WM_SETFONT, (WPARAM)this->m_Font, lParam != 0);
		SendMessageW(this->m_hWndTooltipOfTreeList, WM_SETFONT, (WPARAM)this->m_Font, lParam != 0);
		SendMessageW(this->m_hWndTooltipOfLeftHeader, WM_SETFONT, (WPARAM)this->m_Font, lParam != 0);
		SendMessageW(this->m_hWndTooltipOfRightHeader, WM_SETFONT, (WPARAM) this->m_Font, lParam != 0);
		HDLAYOUT Layout = { 0 };
		WINDOWPOS WindowPos = { 0 };
		GetClientRect(this->m_hWnd, &rc);
		Layout.prc = &rc;
		Layout.pwpos = &WindowPos;
		Header_Layout(m_hWndHeaderLeft, &Layout);
		SetWindowPos(
			this->m_hWndHeaderLeft,
			WindowPos.hwndInsertAfter,
			0,
			0,
			this->m_nBottomScrollBarWidthOrHeight,
			WindowPos.cy,
			WindowPos.flags | SWP_SHOWWINDOW);
		SetWindowPos(
			this->m_hWndHeaderRight,
			this->m_hWndHeaderLeft,
			this->m_nBottomScrollBarWidthOrHeight,
			0,
			WindowPos.cx - this->m_nBottomScrollBarWidthOrHeight,
			WindowPos.cy,
			WindowPos.flags | SWP_SHOWWINDOW);
		if (lParam == 0)
			return 0;
		this->Refresh();
		return	0;
	}
	else if (msg == WM_NOTIFY)
	{

	}
	else if (msg == WM_SETFOCUS || msg == WM_KILLFOCUS)
	{
		if (m_ChildLast != NULL)
		{
			this->RefreshChildItem(m_ChildItem);
		}
		return this->HandleMessage(hWnd, msg, wParam, lParam);
	}
	else if (msg == WM_NCDESTROY)
	{
		if (m_ImageList && !m_NotMyImageList)
		{
			ImageList_Destroy(m_ImageList);
		}
		SetProp(hWnd, MAKEINTRESOURCE(gszTreeListPropName), NULL);
		delete this;
		return DefWindowProcW(hWnd, msg, wParam, lParam);
	}
	else if (msg == WM_GETDLGCODE)
	{
		return (DefWindowProcW(hWnd, msg, wParam, lParam) | DLGC_WANTARROWS);
		DLGC_BUTTON;
	}
	else if (msg >= TREELIST_MSG_2000 
		&& msg < TREELIST_MSG_2006)
	{
		switch (msg)
		{
		case TREELIST_MSG_2000:
			this->OnMsg2000((tagTreeViewChildItem*)wParam, lParam != 0);
			return 0;
		case TREELIST_MSG_2001:
			this->OnMsg2001((tagTreeViewChildItem*)wParam, lParam != 0);
			return 0;
		case TREELIST_MSG_2002:
		{
			///wParam = *
			tagTreeViewChildItem* pItem = (tagTreeViewChildItem*)wParam;
			return pItem->m_nCount;
		}
			return 0;
		case TREELIST_MSG_2003:
			this->RefreshChildItem((tagTreeViewChildItem*)wParam);
			return 0;
		case TREELIST_MSG_2004:
			return 0;
		case TREELIST_MSG_2005:
			return this->FindChild((tagTreeViewChildItem*)wParam);
		default:
			return 0;
		}
	}
	return DefWindowProcW(hWnd, msg, wParam, lParam);
}

void CTreeList::RedrawChild(tagTreeViewChildItem* pItem)
{
	tagTreeViewChildItem *pChildLast = this->m_ChildLast;
	if (pItem != pChildLast)
	{
		if (pChildLast)
		{
			pChildLast->m_dwStyle &= -TVIF_IMAGE;
			int nPos = this->FindChild(this->m_ChildLast);
			if (nPos >= 0)
				this->RedrawZone(nPos, nPos);
			this->m_ChildLast = NULL;
		}
		if (pItem)
		{
			pItem->m_dwStyle |= TVIF_TEXT;
			int nPos = this->FindChild(pItem);
			if (nPos >= 0)
				this->RedrawZone(nPos, nPos);
			this->m_ChildLast = pItem;
		}
		this->SendNotify(this->m_hWnd, TREELIST_MSG_2000, 0, pItem, pChildLast, 0);
	}

}

void CTreeList::OnMsg2000(tagTreeViewChildItem* pItem, bool flags)
{
	if (flags)
	{
		pItem->m_dwStyle |= TVLS_0X_40;
		if (!pItem->m_nCount)
			pItem->m_dwStyle &= ~TVLS_HASCHILD;
	}
	else
		pItem->m_dwStyle |= ~TVLS_0X_40;
}

bool CTreeList::OnMsg2001(tagTreeViewChildItem* pItem, bool fChild)
{
	if (!pItem)
		return true;
	bool HasChild = ItemHasChild(pItem);
	int nCount = 0;

	if (fChild != HasChild)
	{
		if (fChild)
		{
			if (!this->SendNotify(m_hWnd, TREELIST_MSG_2001, 0, pItem, NULL, 0))
			{
				pItem->m_dwStyle |= TVLS_HASCHILD | TVLS_SHOWSERVICES;
				nCount = TreeViewChildItem_GetChildCount(pItem);
			}
		}
	}
	else
	{
		if (!this->SendNotify(m_hWnd, TREELIST_MSG_2002, 0, pItem, NULL, 0))
		{
			nCount = TreeViewChildItem_GetChildCount(pItem);
			pItem->m_dwStyle &= ~TVLS_HASCHILD;
		}
	}

	if (nCount)
	{
		int nChild = this->FindChild(pItem);
		this->RedrawZone(nChild, nChild);
		if (!fChild)
			nCount = -nCount;
		///*this->SetVScrollPos(nChild + 1, nCount);*/
		if (!fChild)
		{
			tagTreeViewChildItem* pChild = m_ChildLast;
			while (pChild&&pChild != pItem)
			{
				pChild = pChild->m_Current;
				if (!pChild)
					return true;
			}
			this->RedrawChild(pItem);
		}
	}

	return true;
}


void CTreeList::DrawTree(PAINTSTRUCT* lpps, HRGN hRgn)
{
	TEXTMETRIC tm = { 0 };
	RECT	rcLeftHeader;
	HDC hDC = GetDC(this->m_hWnd);
	SelectObject(hDC, this->m_Font);
	GetTextMetricsW(hDC, &tm);
	ReleaseDC(m_hWnd, hDC);

	int nHeight = tm.tmHeight;
	if (m_ImageList)
	{
		if (nHeight < GetSystemMetrics(SM_CYSMICON))
			nHeight = GetSystemMetrics(SM_CYSMICON);
	}

	GetWindowRect(m_hWndHeaderLeft, &rcLeftHeader);

}

void CTreeList::OnDestroy()
{

}

void CTreeList::OnSize()
{

}

void CTreeList::RepositionHeaders()
{

}

void CTreeList::RepositionTooltips()
{

}

int CTreeList::RefreshChildItem(tagTreeViewChildItem* pItem)
{

	return -1;
}

int CTreeList::Refresh()
{
	InvalidateRect(m_hWnd, NULL, FALSE);
	InvalidateRect(m_hWndHeaderLeft, NULL, FALSE);
	InvalidateRect(m_hWndHeaderRight, NULL, FALSE);

	m_nChildWidthLast = this->GetChildWidth(0);

	this->OnSize();
	this->RepositionHeaders();
	this->RepositionTooltips();

	return 0;
}

int CTreeList::GetChildWidth(int nChildID)
{
	RECT rc = { 0,0,500,500 };
	WCHAR szText[_MAX_PATH] = { 0 };
	DWORD cbText = _MAX_PATH;
	int nWidth = 0;
	int nIconWidth = GetSystemMetrics(SM_CXSMICON);
	nWidth = nIconWidth;

	HDC hDC = GetDC(m_hWnd);
	HFONT hFontOld = (HFONT)SelectObject(hDC, m_Font);
	tagTreeViewChildItem* pChildren = m_ChildItem;

	while (pChildren)
	{



		///便利所有子项
		if (pChildren->m_Next
			&& (pChildren->m_dwStyle >> 4) & 1)
		{
			pChildren = pChildren->m_Next;
		}
		else if (pChildren->m_Prev)
		{
			pChildren = pChildren->m_Prev;
		}
		else
		{
			tagTreeViewChildItem* pCurrent = pChildren->m_Current;
			if (pCurrent)
			{
				while (!pCurrent->m_Prev)
				{
					pCurrent = pCurrent->m_Current;
					if (!pCurrent)
						pChildren = NULL;
				}
				pChildren = pCurrent->m_Prev;
			}
			else
			{
				pChildren = NULL;
			}
		}
	}



	SelectObject(hDC, hFontOld);
	ReleaseDC(m_hWnd, hDC);

	return nWidth;

}


//////////////////////////////////////////////////////////////////////////
//
//	CTreeList::OnInited
//	
//////////////////////////////////////////////////////////////////////////
BOOL CTreeList::OnInited()
{
	RECT rcItem;
	HINSTANCE hInst = (HINSTANCE)GetModuleHandle(NULL);
	GetClientRect(this->m_hWnd, &rcItem);
	SetProp(m_hWnd, MAKEINTRESOURCE(gszTreeListPropName), (HANDLE)this);

	if (m_hThemeHandle != NULL)
	{
		gpfnCloseThemeData(m_hThemeHandle);
	}
	m_hThemeHandle = NULL;
 	if (gpfnIsThemeActive&&gpfnIsThemeActive())
	{
		m_hThemeHandle = gpfnOpenThemeData(m_hWnd, GetName());
	}
	///创建左边顶部栏头部窗口
	DWORD dwStyle = WS_CHILD | WS_CLIPSIBLINGS | HDS_FULLDRAG | HDS_BUTTONS;
	m_hWndHeaderLeft = CreateWindowEx(0, WC_HEADER, TEXT(""), dwStyle, 0, 0, 0, 0, m_hWnd, (HMENU)IDC_HEADERCTRL_1_IN_TREELIST, hInst, NULL);
	SetProp(m_hWndHeaderLeft, MAKEINTRESOURCE(gszTreeListPropName), (HANDLE)this);
	m_HeaderWndProc = (WNDPROC)::SetWindowLongPtr(m_hWndHeaderLeft, GWLP_WNDPROC, (LONG_PTR)CTreeList::Proxy_HeaderWndProc);
	
	///创建右边顶部栏头部窗口
	dwStyle |= HDS_DRAGDROP; 
	m_hWndHeaderRight = CreateWindowEx(0, WC_HEADER, TEXT(""), dwStyle, 0, 0, 0, 0, m_hWnd, (HMENU)IDC_HEADERCTRL_2_IN_TREELIST, hInst, NULL);
	SetProp(m_hWndHeaderRight, MAKEINTRESOURCE(gszTreeListPropName), (HANDLE)this);
	::SetWindowLongPtr(m_hWndHeaderRight, GWLP_WNDPROC, (LONG_PTR)CTreeList::Proxy_HeaderWndProc);

	/// 创建右边PANE的右边垂直滚动条
	
	dwStyle = WS_CHILD | WS_CLIPCHILDREN | SBS_RIGHTALIGN | SBS_VERT;
	m_hWndScrollBarRightRight = CreateWindowEx(0, WC_SCROLLBAR, TEXT(""), dwStyle, 0, 0, 0, 0, m_hWnd, (HMENU)IDC_SCROLLBAR_1_IN_TREELIST, hInst, NULL);

	///创建左边PANE的下面水平滚动条
	dwStyle = WS_CHILD | WS_CLIPCHILDREN | SBS_BOTTOMALIGN | SBS_HORZ;
	m_hWndScrollBarLeftBottom = CreateWindowEx(0, WC_SCROLLBAR, TEXT(""), dwStyle, 0, 0, 0, 0, m_hWnd, (HMENU)IDC_SCROLLBAR_2_IN_TREELIST, hInst, NULL);
	
	///创建右边PANE的下面水平滚动条
	m_hWndScrollBarRightBottom = CreateWindowEx(0, WC_SCROLLBAR, TEXT(""), dwStyle, 0, 0, 0, 0, m_hWnd, (HMENU)IDC_SCROLLBAR_3_IN_TREELIST, hInst, NULL);

	dwStyle = WS_CHILD | WS_CLIPCHILDREN;
	m_hWndStatic = CreateWindowEx(0, WC_STATIC, TEXT(""), dwStyle, 0, 0, 0, 0, m_hWnd, (HMENU)IDC_STATIC_IN_TREELIST, hInst, NULL);

	INITCOMMONCONTROLSEX iccex = { sizeof(iccex) };
	iccex.dwICC = ICC_BAR_CLASSES;
	InitCommonControlsEx(&iccex);

	m_hWndTooltipOfTreeList = CreateTooltips(hInst, m_hWnd);
	SetProp(m_hWndTooltipOfTreeList, MAKEINTRESOURCE(gszTreeListPropName), (HANDLE)this);
	m_TooltipWndProc = (WNDPROC)::SetWindowLongPtr(m_hWndTooltipOfTreeList, GWLP_WNDPROC, (LONG_PTR)CTreeList::Proxy_TooltipWndProc);
	SetTimer(m_hWnd, TIMERID_REFRESH_TOOLTIPS, TIMEOUT_REFRESH_TOOLTIPS, 0);

	m_hWndTooltipOfLeftHeader = CreateTooltips(hInst, m_hWndHeaderLeft);

	m_hWndTooltipOfRightHeader = CreateTooltips(hInst, m_hWndHeaderRight);

	SendMessage(m_hWnd,WM_SETFONT, (WPARAM)(HFONT)GetStockObject(DEFAULT_GUI_FONT), 0);

	m_hCursor = LoadCursor(hInst, MAKEINTRESOURCE(IDC_SPLITTER));

	m_dwTreeStyle = TVIF_HANDLE;

	InvalidateRect(m_hWnd, NULL, TRUE);
	return TRUE;
}

//////////////////////////////////////////////////////////////////////////
//
//	CTreeList::RedrawZone
//	
//////////////////////////////////////////////////////////////////////////
void CTreeList::RedrawZone(int nStart, int nEnd)
{
	if (nEnd >= nStart)
	{
		RECT Rect, rcClient;

		SCROLLINFO ScrollInfo = { sizeof(ScrollInfo) };
		TEXTMETRIC tm = { 0 };

		ScrollInfo.nTrackPos = 0;
		ScrollInfo.fMask = SIF_POS;
		GetScrollInfo(m_hWndScrollBarRightRight, SB_CTL, &ScrollInfo);
		HDC hDC = GetDC(this->m_hWnd);
		SelectObject(hDC, this->m_Font);
		GetTextMetricsW(hDC, &tm);
		int nHeight = tm.tmHeight;
		ReleaseDC(this->m_hWnd, hDC);
		if (this->m_ImageList)
		{
			if (nHeight < GetSystemMetrics(SM_CYSMICON))
				nHeight = GetSystemMetrics(SM_CYSMICON);
		}
		int nTotalHeight = nHeight + this->m_nHeight;
		GetWindowRect(this->m_hWndHeaderLeft, &Rect);
		GetClientRect(this->m_hWnd, &rcClient);
		rcClient.top = Rect.bottom - Rect.top + nTotalHeight * (nStart - ScrollInfo.nPos);
		rcClient.bottom = Rect.bottom - Rect.top
			+ nTotalHeight * (nEnd - ScrollInfo.nPos + 1);

		InvalidateRect(this->m_hWnd, &rcClient, FALSE);
	}
}

//////////////////////////////////////////////////////////////////////////
//
//	CTreeList::PopTooltip
//	
//////////////////////////////////////////////////////////////////////////
void CTreeList::PopTooltip(HWND hWndTooltip, LPPOINT pt)
{
	TVIF_CHILDREN;

	int xx = 0,  nItemCount = 0;
	tagTreeViewChildItem* pChild = NULL;
	this->Query(pt->x, pt->y, &xx, &nItemCount, &pChild);

	//if (m_point.y != yy || nItemCount != m_nHeaderItemCount)
	//{
	//	m_nHeaderItemCount = nItemCount;
	//	m_point.x = xx;
	//	m_point.y = yy;
	//	SendMessage(hWndTooltip, TTM_POP, 0, 0);
	//}
}

//////////////////////////////////////////////////////////////////////////
//
//
//
//
//////////////////////////////////////////////////////////////////////////
int CTreeList::GetScrollInfos(SCROLLINFO* RightScrollInfo, SCROLLINFO* BottomScrollInfo)
{
	RECT rcClient, rcWindow, rcStartItem, rcEndItem;
	TEXTMETRIC tm = { 0 };

	GetClientRect(this->m_hWnd, &rcClient);
	int cxscroll = GetSystemMetrics(SM_CXVSCROLL);
	int cyscroll = GetSystemMetrics(SM_CYHSCROLL);
	int nCount = SendMessageW(this->m_hWndHeaderRight, HDM_GETITEMCOUNT, 0, 0);
	int nStartItem = SendMessageW(this->m_hWndHeaderRight, HDM_ORDERTOINDEX, 0, 0);
	int nEndItem = SendMessageW(this->m_hWndHeaderRight, HDM_ORDERTOINDEX, nCount - 1, 0);
	SendMessageW(this->m_hWndHeaderRight, HDM_GETITEMRECT, nStartItem, (LPARAM)&rcStartItem);
	SendMessageW(this->m_hWndHeaderRight, HDM_GETITEMRECT, nEndItem, (LPARAM)&rcEndItem);
	int nWidth = rcEndItem.right - rcStartItem.left;
	int nClientWidth = rcClient.right - this->m_nBottomScrollBarWidthOrHeight - rcClient.left;
	
	
	HDC hDC = GetDC(this->m_hWnd);
	SelectObject(hDC, this->m_Font);
	GetTextMetricsW(hDC, &tm);
	int nTextHeight = tm.tmHeight;
	ReleaseDC(this->m_hWnd, hDC);
	if (this->m_ImageList)
	{
		if (nTextHeight < GetSystemMetrics(SM_CYSMICON))
			nTextHeight = GetSystemMetrics(SM_CYSMICON);
	}
	int nLineHeight = nTextHeight + this->m_nHeight;
	GetWindowRect(this->m_hWndHeaderLeft, &rcWindow);
	int nHeight = rcClient.bottom + rcWindow.top - rcWindow.bottom - rcClient.top;
	int nChildCount = 0;

	if (this->m_dwTreeStyle&TVIF_CHILDREN)
	{
		nChildCount = m_nChildCount;
		tagTreeViewChildItem* pChild = m_ChildItem;
		while (pChild)
		{
			nChildCount += TreeViewChildItem_GetChildCount(pChild);
			pChild = pChild->m_Prev;
		}
	}

	////RightScrollInfo->nMax = v16 / nLineHeight;
	////RightScrollInfo->nPage = v11 / nLineHeight;
	////RightScrollInfo->cbSize = sizeof(SCROLLINFO);
	////RightScrollInfo->fMask = 3;
	////RightScrollInfo->nMin = 0;
	////BottomScrollInfo->nPage = nPage;
	////BottomScrollInfo->cbSize = sizeof(SCROLLINFO);
	////BottomScrollInfo->fMask = 3;
	////BottomScrollInfo->nMin = 0;
	////BottomScrollInfo->nMax = nWidth - 1;
	return nWidth - 1;


	return 0;
}
BOOL CTreeList::SendNotifyEx(HWND hWndParent, TVNMHDR* pNMHDR)
{

	return TRUE;
}


BOOL CTreeList::SendNotify(HWND hWnd, int Code, int msg, tagTreeViewChildItem* pSibling, tagTreeViewChildItem* pChild, int nItem)
{
	tagTVNMHDR	nmhdr = { 0 };
	nmhdr.nmhdr.hwndFrom = hWnd;
	nmhdr.nmhdr.idFrom = GetWindowLongPtr(hWnd, GWLP_ID);
	nmhdr.pChild = pChild;
	nmhdr.pSibling = pSibling;
	nmhdr.nMsg = msg;
	nmhdr.nItem = nItem;

	bool bFlags = LOWORD(m_ptDownLast.y) != 0;
	if (bFlags)
	{
		return SendMessage(GetParent(m_hWnd), WM_NOTIFY, nmhdr.nmhdr.idFrom, (LPARAM)&nmhdr);
	}
	else
	{
		return SendNotifyEx(GetParent(m_hWnd), &nmhdr);
	}
	return TRUE;
}
//////////////////////////////////////////////////////////////////////////
//
//
//
//
//////////////////////////////////////////////////////////////////////////
int CTreeList::Query(int xPos, int yPos, int* pxx, int* pnItem, tagTreeViewChildItem** pyy)
{
	RECT	rwTreeList, rwHeaderLeft;

	GetClientRect(this->m_hWnd, &rwTreeList);
	if (pxx)
		*pxx = -1;
	if (pnItem)
		*pnItem = -1;
	if (pyy)
		*pyy = NULL;
	if (xPos < rwTreeList.left)
		return 4;
	if (xPos >= rwTreeList.right)
		return 8;
	if (yPos < rwTreeList.top)
		return 1;
	if (yPos >= rwTreeList.bottom)
		return 2;
	int xOffset = 0;
	int nItem = -1;
	int nIndex = 0;

	int nRightHeaderItemCount = SendMessageW(this->m_hWndHeaderRight, HDM_GETITEMCOUNT, 0, 0) + 1;
	if (nRightHeaderItemCount > 0)
	{
		while (1)
		{
			this->MapToHeader(nIndex, &rwHeaderLeft);
			if (xPos >= rwHeaderLeft.left && xPos < rwHeaderLeft.right)
			{
				nItem = nIndex;
				xOffset = xPos - rwHeaderLeft.left;
				if (pnItem)
					*pnItem = nIndex;
				break;
			}

			if (++nIndex >= nRightHeaderItemCount)
				break;
		}
	}
	GetWindowRect(this->m_hWndHeaderLeft, &rwHeaderLeft);

	int nLeftHeaderHeight = rwHeaderLeft.bottom - rwHeaderLeft.top;
	if (yPos < rwHeaderLeft.bottom - rwHeaderLeft.top)
		return 512;

	tagTreeViewChildItem* pChild = GetCurScrollChildItem();
	if (!pChild)
		return 16;

	int nPos = this->GetRightScrollbarPos();
	int bottom = nPos + (yPos - nLeftHeaderHeight) / GetLineHeight();
	pChild = TreeViewChildItem_GetChild(pChild, bottom - nPos);
	if (!pChild)
		return 16;
	if (pxx)
		*pxx = bottom;

	if (pyy)
		*pyy = pChild;

	if (nItem)
		return 128;

	int nLeft = xOffset - m_nChildWidth * TreeViewChildItem_GetChildCount(pChild);

	if (nLeft)
		return 256;
	int cx = GetSystemMetrics(SM_CXSMICON);
	nLeft = nLeft - cx;
	if (nLeft < 0)
	{
		if ((pChild->m_dwStyle >> 6) & 1)
			return 64;
		return 256;
	}

	if (!this->m_ImageList)
		return 128;
	if (nLeft >= cx)
		return 128;
	return 32;
}

//////////////////////////////////////////////////////////////////////////
//
//
//
//
//////////////////////////////////////////////////////////////////////////
BOOL CTreeList::ShowCaption(BOOL bVisible)
{
	if (!bVisible)
		ShowWindow(m_hWndStatic, SW_HIDE);
	RECT rcClient;
	GetClientRect(m_hWnd, &rcClient);
	rcClient.left = rcClient.right - GetSystemMetrics(SM_CXVSCROLL);
	rcClient.top = rcClient.bottom - GetSystemMetrics(SM_CYHSCROLL);

	return SetWindowPos(m_hWndStatic, NULL,
		rcClient.left,
		rcClient.bottom - GetSystemMetrics(SM_CYHSCROLL),
		rcClient.right - rcClient.left,
		GetSystemMetrics(SM_CYHSCROLL),
		SWP_SHOWWINDOW | SWP_NOZORDER);
}


//////////////////////////////////////////////////////////////////////////
//
//
//
//
//////////////////////////////////////////////////////////////////////////
tagTreeViewChildItem* TreeViewChildItem_GetChild(tagTreeViewChildItem* pItem, int nPos)
{
	if (!pItem)
		return NULL;
	tagTreeViewChildItem* pCurrent = NULL;
	tagTreeViewChildItem* pNode = NULL;

	tagTreeViewChildItem* i = NULL;
	while (nPos < 0)
	{
		pNode = pItem->m_Item0C;
		if (pNode)
		{
			pItem = pItem->m_Item0C;
			for (i = pNode->m_Item18; i; i = i->m_Item18)
			{
				if (!((pItem->m_dwStyle >> 4) & 1))
					break;
				pItem = i;
			}
		}
		else
		{
			pItem = pItem->m_Current;
			if (pItem && !pItem->m_TreeListData)
				return NULL;
		}
		++nPos;
		if (!pItem)
			return NULL;
	}
	for (; pItem; --nPos)
	{
		if (nPos <= 0)
			break;
		if (pItem->m_Next && (pItem->m_dwStyle >> 4) & 1)
		{
			pItem = pItem->m_Next;
		}
		else if (pItem->m_Prev)
		{
			pItem = pItem->m_Prev;
		}
		else
		{
			pCurrent = pItem->m_Current;
			if (pCurrent)
			{
				while (!pCurrent->m_Prev)
				{
					pCurrent = pCurrent->m_Current;
					if (!pCurrent)
						goto __NEXT;
				}
				pItem = pCurrent->m_Prev;
			}
			else
			{
__NEXT:
				pItem = NULL;
			}
		}
	}
	return pItem;
}

//////////////////////////////////////////////////////////////////////////
//
//	CTreeList::MapToHeader
//	
//////////////////////////////////////////////////////////////////////////
BOOL CTreeList::MapToHeader(int nItem, LPRECT lprc)
{
	LRESULT lresult = 0;
	HWND hWndTo = m_hWnd;
	HWND hWndFrom = NULL;
	if (nItem)
	{
		lresult = SendMessage(m_hWndHeaderRight, HDM_GETITEMRECT, nItem - 1, (LPARAM)lprc);
		hWndFrom = m_hWndHeaderRight;
	}
	else
	{
		lresult = SendMessage(m_hWndHeaderLeft, HDM_GETITEMRECT, nItem - 1, (LPARAM)lprc);
		hWndFrom = m_hWndHeaderLeft;
	}
	MapWindowPoints(hWndFrom, m_hWnd, (LPPOINT)lprc, 2);
	return lresult != 0;
}

//////////////////////////////////////////////////////////////////////////
//
//	CTreeList::GetRightScrollbarPos
//	
//////////////////////////////////////////////////////////////////////////
int CTreeList::GetRightScrollbarPos()
{
	SCROLLINFO ScrollInfo = { sizeof(ScrollInfo) };
	ScrollInfo.fMask = SIF_POS;
	GetScrollInfo(m_hWndScrollBarRightRight, SB_CTL, &ScrollInfo);
	return ScrollInfo.nPos;
}

//////////////////////////////////////////////////////////////////////////
//
//	CTreeList::SetHScrollPos
//	
//////////////////////////////////////////////////////////////////////////
BOOL CTreeList::SetHScrollPos(HWND hWnd, int nPos)
{
	SCROLLINFO ScrollInfo = { sizeof(ScrollInfo) };
	ScrollInfo.fMask = SIF_POS;
	ScrollInfo.nPos = nPos;

	SetScrollInfo(hWnd, SB_CTL, &ScrollInfo, TRUE);


	return TRUE;
}

//////////////////////////////////////////////////////////////////////////
//
//	CTreeList::SetVScrollPos
//	
//////////////////////////////////////////////////////////////////////////
BOOL CTreeList::SetVScrollPos(HWND hWnd, int nPos)
{
	SCROLLINFO ScrollInfo = { sizeof(ScrollInfo) };
	ScrollInfo.fMask = SIF_POS;
	ScrollInfo.nPos = nPos;

	SetScrollInfo(hWnd, SB_CTL, &ScrollInfo, TRUE);

	UpdateVScrollBars(nPos);

	return TRUE;
}

//////////////////////////////////////////////////////////////////////////
//
//	CTreeList::UpdateVScrollBars
//	
//////////////////////////////////////////////////////////////////////////
BOOL CTreeList::UpdateVScrollBars(int nPos)
{
	BOOL bMaximized = FALSE;
	DWORD dwStyle = (DWORD)GetWindowLong(m_hWndScrollBarRightRight, GWL_STYLE);
	if (dwStyle & WS_MAXIMIZE)
	{
		bMaximized = TRUE;

		SCROLLINFO ScrollInfo = { sizeof(ScrollInfo) };
		ScrollInfo.fMask = SIF_POS;
		ScrollInfo.nPos = nPos;
		if (nPos)
		{
			GetScrollInfo(m_hWndScrollBarRightRight, SB_CTL, &ScrollInfo);
			ScrollInfo.nPos += nPos;
			SetScrollInfo(m_hWndScrollBarRightRight, SB_CTL, &ScrollInfo, TRUE);
		}
		GetScrollInfo(m_hWndScrollBarRightRight, SB_CTL, &ScrollInfo);
		int nPos = ScrollInfo.nPos;
		if (ScrollInfo.nPos != m_nLastVScrollPos)
		{
			int nLineHeight = GetLineHeight();
			RECT rcItem, rcWindow,rcScroll;
			GetClientRect(m_hWnd, &rcItem);
			int nDeltaPos = m_nLastVScrollPos - nPos;
			m_nLastVScrollPos = nPos;
			rcScroll.left = rcItem.left;
			GetWindowRect(m_hWndHeaderLeft, &rcWindow);
			rcScroll.top = rcWindow.bottom - rcWindow.top;
			rcScroll.right = rcItem.right;
			rcScroll.bottom = rcItem.bottom;

			return ScrollWindowEx(m_hWnd, 0, nLineHeight*nDeltaPos, &rcScroll, NULL, NULL, NULL, SW_INVALIDATE);

		}
	}

	return FALSE;
}

//////////////////////////////////////////////////////////////////////////
//
//	CTreeList::SetVScrollPos
//	
//////////////////////////////////////////////////////////////////////////
int CTreeList::GetLineHeight()
{
	int ret = 0;
	TEXTMETRIC tm = { 0 };

	/// 获取当前字体的高度
	HDC hDC = GetDC(m_hWnd);
	SelectObject(hDC, m_Font);
	GetTextMetrics(hDC, &tm);
	ReleaseDC(m_hWnd, hDC);
	ret = tm.tmHeight;

	if (m_ImageList)
	{
		///如果支持图像列表，则比较SMALLICON模式下的尺寸
		int cySmallIcon = GetSystemMetrics(SM_CYSMICON);
		if (ret < cySmallIcon)
			ret = cySmallIcon;
	}

	return ret + m_nHeight;
}

bool CTreeList::UpdateRightRightSB(bool fHide, bool fSBVisible)
{
	RECT rcClient;

	GetClientRect(m_hWnd, &rcClient);

	BOOL bWindowVisible = HWNDISVISIBLE(m_hWndScrollBarRightRight);

	if (fHide)
	{
		int nLeft = rcClient.right - rcClient.left - GetSystemMetrics(SM_CXVSCROLL);
		int nHeight = rcClient.bottom - rcClient.top;
		if (fSBVisible)
			nHeight -= GetSystemMetrics(SM_CYHSCROLL);
		SetWindowPos(
			m_hWndScrollBarRightRight,
			0,
			nLeft,
			0,
			rcClient.right - rcClient.left - nLeft,
			nHeight,
			SWP_SHOWWINDOW | SWP_NOZORDER);
		return true;
	}
	else
	{
		if (bWindowVisible)
		{
			SCROLLINFO ScrollInfo = { sizeof(ScrollInfo) };
			ScrollInfo.nTrackPos = 0;
			ScrollInfo.fMask = SIF_POS;
			ScrollInfo.nPos = 0;
			SetScrollInfo(m_hWndScrollBarRightRight, SB_CTL, &ScrollInfo, TRUE);
			this->UpdateVScrollBars(0);
			ShowWindow(m_hWndScrollBarRightRight, SW_HIDE);
		}
	}

	return true;
}

//////////////////////////////////////////////////////////////////////////
//
//
//
//
//
//
//////////////////////////////////////////////////////////////////////////
bool CTreeList::UpdateLeftBottomSB(HWND hWnd, bool fShow, bool fSBVisible)
{
	RECT rcClient;

	GetClientRect(m_hWnd, &rcClient);

	BOOL bWindowVisible = HWNDISVISIBLE(hWnd);

	if (fShow)
	{
		int cxVScroll = GetSystemMetrics(SM_CXVSCROLL);
		int cyHScroll = GetSystemMetrics(SM_CYHSCROLL);
		//
		HWND hWndScrollbar = m_hWndScrollBarLeftBottom;
		int nRight = 0;
		int nLeft = 0;
		if (hWnd == hWndScrollbar)
		{
			nRight = m_nBottomScrollBarWidthOrHeight;
			nLeft = 0;
		}
		else
		{
			/// 客户区域的右边
			nRight = rcClient.right - rcClient.left;
			/// 
			nLeft = m_nBottomScrollBarWidthOrHeight;
		}
		/// 客户区域的底部
		int nTop = rcClient.bottom - rcClient.top - cyHScroll;
		/// 滚动条的高度
		int nBottom = nTop + cyHScroll;

		/// 做点偏移调整
		if (fSBVisible)
			nRight -= cxVScroll;
		SetWindowPos(hWnd, NULL, nLeft, nTop, nRight - nLeft, nBottom - nTop, SWP_SHOWWINDOW | SWP_NOZORDER);
	}
	else
	{
		if (bWindowVisible)
		{
			SCROLLINFO ScrollInfo = { sizeof(ScrollInfo) };
			ScrollInfo.nTrackPos = 0;
			ScrollInfo.fMask = SIF_POS;
			ScrollInfo.nPos = 0;
			SetScrollInfo(hWnd, SB_CTL, &ScrollInfo, TRUE);
			this->UpdateHeaderPos(hWnd, 0);
			ShowWindow(hWnd, SW_HIDE);
		}
	}

	//HDM_INSERTITEM;
	return true;
}

//////////////////////////////////////////////////////////////////////////
//
//
//
//
//
//
//////////////////////////////////////////////////////////////////////////
BOOL CTreeList::UpdateHeaderPos(HWND hWnd, int nPos)
{
	HWND hWndHeader = hWnd == m_hWndScrollBarLeftBottom ? m_hWndHeaderLeft : m_hWndHeaderRight;
	int nOffset = hWnd == m_hWndScrollBarLeftBottom ? m_ptOffset.x : m_ptOffset.y;

	BOOL bVisible = HWNDISVISIBLE(hWnd);
	if (bVisible)
	{
		SCROLLINFO ScrollInfo = { sizeof(ScrollInfo) };
		ScrollInfo.fMask = SIF_POS;
		if (nPos)
		{
			GetScrollInfo(hWnd, SB_CTL, &ScrollInfo);
			ScrollInfo.nPos += nPos;
			SetScrollInfo(hWnd, SB_CTL, &ScrollInfo, TRUE);
		}
		GetScrollInfo(hWnd, SB_CTL, &ScrollInfo);
		int nPosOld = ScrollInfo.nPos;
		if (ScrollInfo.nPos != nOffset)
		{
			RECT rcItem;
			GetClientRect(hWnd, &rcItem);
			int DeltaX = nOffset - nPosOld;
			nOffset = nPosOld;

			int nBottomScrollBarWidthOrHeight = m_nBottomScrollBarWidthOrHeight;
			if (hWnd == m_hWndScrollBarLeftBottom)
			{
				rcItem.right = nBottomScrollBarWidthOrHeight - 1;
				nBottomScrollBarWidthOrHeight = rcItem.left;
			}
			else
			{
				rcItem.left = nBottomScrollBarWidthOrHeight;
			}

			if (DeltaX > 0)
			{
				RECT rcScroll;
				rcScroll.left = nBottomScrollBarWidthOrHeight;
				RECT rcWindow;
				GetWindowRect(m_hWndHeaderLeft, &rcWindow);
				rcScroll.top = rcWindow.bottom - rcWindow.top;
				rcScroll.right = rcItem.right - DeltaX;
				rcScroll.bottom = rcItem.bottom - GetSystemMetrics(SM_CYHSCROLL);

				if(hWnd == m_hWndScrollBarRightBottom
					&& (HWNDISVISIBLE(m_hWndScrollBarRightRight)))
				{
					rcScroll.right -= GetSystemMetrics(SM_CXVSCROLL);
				}
				else
				{

				}
				if (rcScroll.right > rcScroll.left)
				{
					ScrollWindowEx(m_hWnd, DeltaX, 0, &rcScroll, NULL, NULL, NULL, SW_INVALIDATE);
					if (DeltaX > (rcScroll.right - rcScroll.left))
					{
						int nLeft = rcScroll.left;
						rcScroll.left = rcScroll.right;
						rcScroll.right = nLeft + DeltaX;
					}
					BOOL ret = InvalidateRect(m_hWnd, &rcScroll, FALSE);
					
					if (hWnd == m_hWndScrollBarRightBottom)
					{
						RECT	rcHeader;
						GetWindowRect(hWndHeader, &rcHeader);
						MapWindowPoints(NULL, m_hWnd,(LPPOINT)&rcHeader, 2);
						ret = SetWindowPos(hWndHeader, NULL,
							DeltaX + rcHeader.left,
							rcHeader.top,
							rcHeader.right - (DeltaX + rcHeader.left),
							rcHeader.bottom - rcHeader.top,
							SWP_NOZORDER);
					}
					return ret;
				}
			}
			else
			{
				RECT rcScroll;
				rcScroll.left = nBottomScrollBarWidthOrHeight - DeltaX;
				RECT rcWindow;
				GetWindowRect(m_hWndHeaderLeft, &rcWindow);
				rcScroll.top = rcWindow.bottom - rcWindow.top;
				rcScroll.right = rcItem.right;
				rcScroll.bottom = rcItem.bottom - GetSystemMetrics(SM_CYHSCROLL);

				if (hWnd == m_hWndScrollBarRightBottom
					&& (HWNDISVISIBLE(m_hWndScrollBarRightRight)))
				{
					rcScroll.right -= GetSystemMetrics(SM_CXVSCROLL);
				}
				if (rcScroll.right > rcScroll.left)
				{
					ScrollWindowEx(m_hWnd, DeltaX, 0, &rcScroll, NULL, NULL, NULL, SW_INVALIDATE);

					if (-DeltaX > rcScroll.right - rcScroll.left)
					{
						int nLeft = rcScroll.left;
						rcScroll.left = rcScroll.right + DeltaX;
						rcScroll.right = nLeft;
						InvalidateRect(m_hWnd, &rcScroll, FALSE);
					}

					if (hWnd == m_hWndScrollBarRightBottom)
					{
						RECT	rcHeader;
						GetWindowRect(hWndHeader, &rcHeader);
						MapWindowPoints(NULL, m_hWnd, (LPPOINT)&rcHeader, 2);
						return SetWindowPos(hWndHeader, NULL,
							DeltaX + rcHeader.left,
							rcHeader.top,
							rcHeader.right - (DeltaX + rcHeader.left),
							rcHeader.bottom - rcHeader.top,
							SWP_NOZORDER);
					}
					return TRUE;
				}
			}

			InvalidateRect(m_hWnd, &rcItem, FALSE);
			if (hWnd == m_hWndScrollBarRightBottom)
			{
				RECT	rcHeader;
				GetWindowRect(hWndHeader, &rcHeader);
				MapWindowPoints(NULL, m_hWnd, (LPPOINT)&rcHeader, 2);
				return SetWindowPos(hWndHeader, NULL,
					DeltaX + rcHeader.left,
					rcHeader.top,
					rcHeader.right - (DeltaX + rcHeader.left),
					rcHeader.bottom - rcHeader.top,
					SWP_NOZORDER);
			}
			return TRUE;
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
//////////////////////////////////////////////////////////////////////////
BOOL CTreeList::AddColumnToHeader(tagHeaderItem* pItem, int nCount)
{
	int nIndex = 0;
	for (nIndex = 0; nIndex < nCount; ++nIndex)
	{
		HDITEM HeadItem = { 0 };
		HeadItem.mask = HDI_TEXT|HDI_WIDTH| HDI_FORMAT;
		HeadItem.cxy = MulDiv(pItem[nIndex].nWidth, gLogPixelSize.cx, 96);
		HeadItem.pszText = pItem[nIndex].szText;
		if (pItem[nIndex].fRight)
			HeadItem.fmt = HDF_STRING | HDF_RIGHT;
		else
			HeadItem.fmt = HDF_STRING;

		if (nCount)
		{
			SendMessage(m_hWndHeaderRight, HDM_INSERTITEM, nIndex - 1, (LPARAM)&HeadItem);
		}
		else
		{
			SendMessage(m_hWndHeaderLeft, HDM_INSERTITEM, 0, (LPARAM)&HeadItem);
			MoveHeaders(HeadItem.cxy);
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
//////////////////////////////////////////////////////////////////////////
void CTreeList::MoveHeaders(int cxy)
{

	//HANDLE hFound = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, dwProcessID);

	m_nBottomScrollBarWidthOrHeight = cxy;
	RECT rcLeftHeader, rcRightHeader;
	GetWindowRect(m_hWndHeaderLeft, &rcLeftHeader);
	GetWindowRect(m_hWndHeaderRight, &rcRightHeader);
	MapWindowPoints(NULL, m_hWnd, (LPPOINT)&rcLeftHeader, 2);
	MapWindowPoints(NULL, m_hWnd, (LPPOINT)&rcRightHeader, 2);
	SCROLLINFO ScrollInfo1 = { sizeof(ScrollInfo1) };
	SCROLLINFO ScrollInfo2 = { sizeof(ScrollInfo2) };
	ScrollInfo1.fMask = ScrollInfo2.fMask = SIF_POS;

	GetScrollInfo(m_hWndScrollBarLeftBottom, SB_CTL, &ScrollInfo1);
	GetScrollInfo(m_hWndScrollBarRightBottom, SB_CTL, &ScrollInfo2);

	rcRightHeader.left = m_nBottomScrollBarWidthOrHeight - ScrollInfo2.nPos;
	rcLeftHeader.right = m_nBottomScrollBarWidthOrHeight;
	rcLeftHeader.left = 0;

	SetWindowPos(m_hWndHeaderLeft,
		NULL,
		0,
		rcLeftHeader.top,
		m_nBottomScrollBarWidthOrHeight,
		rcLeftHeader.bottom - rcLeftHeader.top,
		SWP_NOZORDER);

	SetWindowPos(m_hWndHeaderRight,
		NULL,
		rcRightHeader.left,
		rcRightHeader.top,
		rcRightHeader.right - rcRightHeader.left,
		rcRightHeader.bottom - rcRightHeader.top,
		SWP_NOZORDER);
	TOOLINFO ToolInfo = { sizeof(ToolInfo) };
	ToolInfo.hwnd = m_hWndHeaderRight;
	GetClientRect(m_hWndHeaderRight, &ToolInfo.rect);
	SendMessage(m_hWndTooltipOfRightHeader, TTM_NEWTOOLRECT, 0, (LPARAM)&ToolInfo);
	ToolInfo.hwnd = m_hWndHeaderLeft;
	GetClientRect(m_hWndHeaderLeft, &ToolInfo.rect);
	SendMessage(m_hWndTooltipOfLeftHeader, TTM_NEWTOOLRECT, 0, (LPARAM)&ToolInfo);

}
//////////////////////////////////////////////////////////////////////////
//
//
//
//
//
//
//////////////////////////////////////////////////////////////////////////
BOOL InitTreeView(HWND hWnd, bool fFlags)
{

	return TRUE;
}

DWORD WINAPI CTreeList::BackendFillTreeViewParamThreadProc(void* p)
{
	tagTREEVIEWITEMPARAM* pItem = (tagTREEVIEWITEMPARAM*)p;
	InterlockedIncrement(&gnRefCount);
	SetCursor(LoadCursor(NULL, IDC_APPSTARTING));

	PROPITEM* pPropItem = new PROPITEM();
	ZeroMemory(pPropItem, sizeof(PROPITEM));
	pPropItem->pListItem = pItem;

	HWND hDlgSheet = CreateDialogParam(ghMainInstance, MAKEINTRESOURCE(IDD_PROCPROPSHEET), ghMainWnd, ProcPropSheet, (LPARAM)pPropItem);
	HACCEL hAccel = LoadAccelerators(ghMainInstance, MAKEINTRESOURCE(IDC_PROCPROPERTIES));
	MSG msg;


	while (!PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
	{
		HANDLE Handles[] = { ghTimerRefreshProcPageEventHandle,ghEvent6 };
		DWORD dwRet = MsgWaitForMultipleObjects(2, Handles, FALSE, INFINITE, QS_ALLINPUT);
		if (dwRet != WAIT_OBJECT_0 + 2)
		{
			for (DWORD i = 0; i < MAX_PROPITEM_COUNT; i++)
			{
				if (pPropItem->PageData[i].hWnd)
				{
					PostMessage(pPropItem->PageData[i].hWnd, dwRet == WAIT_OBJECT_0 ? WM_TIMER : WM_USER, 1, 0);
				}
			}
		}

		PROPPAGEDATA* pCurPage = &pPropItem->PageData[pPropItem->nTabIndex];
		if (pCurPage->hWnd&&TranslateAccelerator(pCurPage->hWnd, hAccel, &msg))
		{
			continue;
		}
		
		HWND hWndFind = (HWND)GetProp(hDlgSheet, TEXT("FindWindow"));
		if (!hWndFind)
		{
			if (!IsDialogMessage(pCurPage->hWnd, &msg)
				&& !IsDialogMessage(hDlgSheet, &msg))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		if (!IsDialogMessage(hWndFind, &msg))
		{
			PostMessage(hWndFind, WM_COMMAND, IDABORT, 0);
			SetProp(hDlgSheet, TEXT("FindWindow"), NULL);
		}
	}

	return 0;
}

void CTreeList::FillTreeViewParam(tagTREEVIEWITEMPARAM* pItem)
{
	InterlockedIncrement(&pItem->nRefCount);
	DWORD	dwThreadId = 0;
	CreateThread(NULL, 0, CTreeList::BackendFillTreeViewParamThreadProc, (void*)pItem, 0, &dwThreadId);
}

bool CTreeList::UpdateSB(bool flags)
{
	return true;
}
void CTreeList::SetSplitterCursor(HCURSOR hCursor)
{

}


BOOL Command_OnProperties(HWND hWnd)
{
	int nItem = ListView_GetNextItem(ghWndTreeListView, -1, LVFI_STRING);
	if (nItem != -1)
	{
		LVITEM Item = { 0 };
		Item.iItem = nItem;
		Item.iSubItem = 0;
		Item.mask = LVIF_PARAM;
		ListView_GetItem(ghWndTreeListView, &Item);

		////PPROPSHEETLISTPARAM Param = (PPROPSHEETLISTPARAM)Item.lParam;
		////Param->dwProcessId = gdwProcessId;

		////DWORD dwThreadId = 0;
		////CreateThread(NULL, 0, PropertiesThreadProc, (void*)Param, 0, &dwThreadId);

	}
	return FALSE;
}



DWORD WINAPI PropertiesThreadProc(void* p)
{
	////PPROPSHEETLISTPARAM pListParam = (PPROPSHEETLISTPARAM)p;
	InterlockedIncrement(&gnRefCount);
	SetCursor(LoadCursor(NULL, IDC_APPSTARTING));

	PPROPITEM pPropItem = new PROPITEM();
	ZeroMemory(pPropItem, sizeof(PROPITEM));

	pPropItem->pListItem = p;// pListParam;

	HWND hDlgPropSheet = CreateDialogParam(ghMainInstance,
		MAKEINTRESOURCE(IDD_PROCPROPSHEET),
		ghMainWnd,
		ProcPropSheet,
		(LPARAM)pPropItem);

	BOOL result = FALSE;
	MSG msg = { 0 };


	HACCEL hAccel = LoadAcceleratorsW(ghMainInstance,MAKEINTRESOURCEW(IDC_DLLPROPERTIES));
	for (result = GetMessageW(&msg, 0, 0, 0);
		result;
		result = GetMessageW(&msg, 0, 0, 0))
	{
		HWND hWndTemp = pPropItem->PageData[pPropItem->nTabIndex].hWnd;
		if (hWndTemp && TranslateAcceleratorW(hWndTemp, hAccel, &msg))
			continue;
		HWND hWndFindWindow = (HWND)GetPropW(hDlgPropSheet, L"FindWindow");
		if (!hWndFindWindow)
		{
			if (!IsDialogMessageW(hWndTemp, &msg)
				&& !IsDialogMessageW(hDlgPropSheet, &msg))
			{
				TranslateMessage(&msg);
				DispatchMessageW(&msg);
			}
			continue;
		}
		if (IsDialogMessageW(hWndFindWindow, &msg))
		{
			if (msg.message != WM_COMMAND || LOWORD(msg.wParam) != 40014)
			{
				continue;
			}
		}
		else if (msg.message != WM_COMMAND || LOWORD(msg.wParam) != 40014)
		{
			if (!IsDialogMessageW(hWndTemp, &msg)
				&& !IsDialogMessageW(hDlgPropSheet, &msg))
			{
				TranslateMessage(&msg);
				DispatchMessageW(&msg);
			}
			continue;
		}
		PostMessageW(hWndFindWindow, WM_COMMAND, IDC_DLG_DLLINFO_EDIT_COMPANY, 0);
		SetPropW(hDlgPropSheet, L"FindWindow", 0);
	}
	return result;


}

enum EProcPageIndex
{
	PROCPAGE_Info,
	PROCPAGE_Performance,
	PROCPAGE_CPU,
	PROCPAGE_DiskAndNetwork,
	PROCPAGE_GPU,
	PROCPAGE_Services,
};

INT_PTR CALLBACK PageProcPerf(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK PageProcCPU(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK PageProcPerfETW(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK PageProcGPU(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK PageProcServices(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK PageProcWMIProviders(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK PageProcThreads(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK PageProcTcpUdp(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK PageProcSecurity(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK PageProcEnv(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);


INT_PTR CALLBACK PageProcJob(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK PageProcCclr(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK PageProcStrings(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK PageProcInfo(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK PageProcNetPerf(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

INT_PTR CALLBACK ProcPropSheet(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	HWND hWndTab = GetDlgItem(hWnd, IDS_PROCPROPSHEET_TABCTRL);

	if (msg == WM_INITDIALOG)
	{
		CResizer* pResizer = new CResizer(hWnd);
		SetWindowLongPtr(hWnd, GWLP_USERDATA, (LONG_PTR)lParam);

		tagPropItem* pPropItem = (tagPropItem*)lParam;

		tagTREEVIEWITEMPARAM* pItem = (tagTREEVIEWITEMPARAM*)pPropItem->pListItem;

		SetStyleEx(hWndTab, WS_EX_CONTROLPARENT);
		SetStyle(hWndTab, WS_CLIPCHILDREN);

		if (pItem)
		{
			int nTab = 0;
			int nPage = 0;

			TreeViewItemParam_InitGraph(pItem);
			HDITEM item = { 0 };
			item.mask = HDI_TEXT | HDI_IMAGE;
			item.iImage = -1;
			item.pszText = _TEXT("Image");
			Header_InsertItem(hWndTab, nTab++, &item);

			wcscpy_s(pPropItem->PageData[PROCPAGE_Performance].szTemplateName, 256, L"PROCPERF");
			pPropItem->PageData[PROCPAGE_Performance].nTabId = 2;
			pPropItem->PageData[PROCPAGE_Performance].PageWndProc = PageProcPerf;
			item.pszText = _TEXT("Performance");
			Header_InsertItem(hWndTab, nTab++, &item);


			wcscpy_s(pPropItem->PageData[PROCPAGE_CPU].szTemplateName, 256, pItem->pGraphDataPROCCPU ? L"PROCCPUIO" : L"PROCCPU");
			pPropItem->PageData[PROCPAGE_CPU].nTabId = 4;
			pPropItem->PageData[PROCPAGE_CPU].PageWndProc = PageProcCPU;
			item.pszText = _TEXT("Performance Graph");
			Header_InsertItem(hWndTab, nTab++, &item);


			if (gbETWFlagsInProcPropSheet)
			{
				wcscpy_s(pPropItem->PageData[PROCPAGE_DiskAndNetwork].szTemplateName, 256, L"PROCPERFETW");
				pPropItem->PageData[PROCPAGE_DiskAndNetwork].nTabId = 14;
				pPropItem->PageData[PROCPAGE_DiskAndNetwork].PageWndProc = PageProcPerfETW;
				item.pszText = _TEXT("Disk and Network");
				Header_InsertItem(hWndTab, nTab++, &item);
				nPage = nTab;
			}

			if (gdwAdapterRuntingTime)
			{
				wcscpy_s(pPropItem->PageData[nPage].szTemplateName, 256, L"PROCGPU");
				pPropItem->PageData[nPage].nTabId = 15;
				pPropItem->PageData[nPage].PageWndProc = PageProcGPU;

				item.pszText = _TEXT("GPU Graph");
				Header_InsertItem(hWndTab, nTab++, &item);
				nPage++;
			}

			if (pItem->dwStyle & TVLS_SHOWSERVICES)
			{
				wcscpy_s(pPropItem->PageData[nPage].szTemplateName, 256, L"PROCSERVICES");
				pPropItem->PageData[nPage].nTabId = 5;
				pPropItem->PageData[nPage].PageWndProc = PageProcServices;

				item.pszText = _TEXT("Services");
				Header_InsertItem(hWndTab, nTab++, &item);
				nPage++;
			}

			if (pItem->bSupportWMIProviders)
			{
				wcscpy_s(pPropItem->PageData[nPage].szTemplateName, 256, L"PROCWMIPROVIDERS");
				pPropItem->PageData[nPage].nTabId = 16;
				pPropItem->PageData[nPage].PageWndProc = PageProcWMIProviders;

				item.pszText = _TEXT("WMI Providers");
				Header_InsertItem(hWndTab, nTab++, &item);
				nPage++;
			}

			wcscpy_s(pPropItem->PageData[nPage].szTemplateName, 256, L"PROCTHREADS");
			pPropItem->PageData[nPage].nTabId = 6;
			pPropItem->PageData[nPage].PageWndProc = PageProcThreads;

			item.pszText = _TEXT("Threads");
			Header_InsertItem(hWndTab, nTab++, &item);
			nPage++;

			if (gpfn_AllocateAndGetUdpExTable2FromStack)
				wcscpy_s(pPropItem->PageData[nPage].szTemplateName, 256, L"PROCTCPUDPSTACK");
			else
				wcscpy_s(pPropItem->PageData[nPage].szTemplateName, 256, L"PROCTCPUDP");

			pPropItem->PageData[nPage].nTabId = 7;
			pPropItem->PageData[nPage].PageWndProc = PageProcTcpUdp;
			item.pszText = _TEXT("TCP/IP");
			Header_InsertItem(hWndTab, nTab++, &item);
			nPage++;


			wcscpy_s(pPropItem->PageData[nPage].szTemplateName, 256, L"PROCSECURITY");
			pPropItem->PageData[nPage].nTabId = 8;
			pPropItem->PageData[nPage].PageWndProc = PageProcSecurity;
			item.pszText = _TEXT("Security");
			Header_InsertItem(hWndTab, nTab++, &item);
			nPage++;

			wcscpy_s(pPropItem->PageData[nPage].szTemplateName, 256, L"PROCENV");
			pPropItem->PageData[nPage].nTabId = 9;
			pPropItem->PageData[nPage].PageWndProc = PageProcEnv;
			item.pszText = _TEXT("Environment");
			Header_InsertItem(hWndTab, nTab++, &item);
			nPage++;

			HANDLE ProcessHandle = PE_OpenProcess(MAXIMUM_ALLOWED, 0, pItem->dwProcessId);

			if (PE_IsProcessInJob(ProcessHandle, pItem->dwProcessId, NULL, 0))
			{
				pItem->dwStyle &= ~TVLS_ENABLEJOBS;
			}
			else
			{
				pItem->dwStyle |= TVLS_ENABLEJOBS;

				wcscpy_s(pPropItem->PageData[nPage].szTemplateName, 256, L"PROCJOB");
				pPropItem->PageData[nPage].nTabId = 10;
				pPropItem->PageData[nPage].PageWndProc = PageProcJob;
				item.pszText = _TEXT("Job");
				Header_InsertItem(hWndTab, nTab++, &item);
				nPage++;
			}
			
			if (ProcessIsNetCclr(pItem))
			{
				wcscpy_s(pPropItem->PageData[nPage].szTemplateName, 256, L"PROCCLR");
				pPropItem->PageData[nPage].nTabId = 11;
				pPropItem->PageData[nPage].PageWndProc = PageProcCclr;
				item.pszText = _TEXT(".NET Assemblies");

				Header_InsertItem(hWndTab, nTab++, &item);
				nPage++;

				if (pItem->pNetCclrInfo == NULL)
				{
					pItem->pNetCclrInfo = new tagNetCclrInfo();
					ZeroMemory(pItem->pNetCclrInfo, sizeof(tagNetCclrInfo));
				}
			}

			if (pItem->pNetCclrInfo)
			{
				CoInitialize(NULL);
				wcscpy_s(pPropItem->PageData[nPage].szTemplateName, 256, L"PROCNET");
				pPropItem->PageData[nPage].nTabId = 12;
				pPropItem->PageData[nPage].PageWndProc = PageProcNetPerf;
				item.pszText = _TEXT(".NET Performance");

				Header_InsertItem(hWndTab, nTab++, &item);
				nPage++;
			}

			wcscpy_s(pPropItem->PageData[nPage].szTemplateName, 256, L"PROCSTRINGS");
			pPropItem->PageData[nPage].nTabId = 13;
			pPropItem->PageData[nPage].PageWndProc = PageProcStrings;
			item.pszText = _TEXT("Strings");

			Header_InsertItem(hWndTab, nTab++, &item);
			nPage++;

			WCHAR	szText[_MAX_PATH] = { 0 };
			if (pItem->szServiceName)
				wsprintfW(szText, L"%s:%d (%s) Properties", pItem->szProcessName2, pItem->dwProcessId, pItem->szServiceName);
			else if (pItem->dwProcessId < 0)
				wsprintfW(szText, L"%s Properties", pItem->szProcessName2);
			else
				wsprintfW(szText, L"%s:%d Properties", pItem->szProcessName2, pItem->dwProcessId);

			SetWindowTextW(hWnd, szText);

			pPropItem->PageData[PROCPAGE_Info].hWnd = CreateDialogParam(ghMainInstance,
				MAKEINTRESOURCE(IDD_PROCINFO),
				hWnd,
				PageProcInfo,
				(LPARAM)pItem);

			pPropItem->PageData[PROCPAGE_Info].nTabId = 1;

		}


		ShowWindow(pPropItem->PageData[PROCPAGE_Info].hWnd, SW_SHOW);
		SetForegroundWindow(hWnd);
		DWORD dwCurTab = 0;
		for (DWORD dwIndex = 0; dwIndex < MAX_PROPITEM_COUNT; dwIndex++)
		{
			if (pPropItem->PageData[dwIndex].nTabId == gConfig.dwDefaultProcPropPage)
			{
				dwCurTab = dwIndex;
				break;
			}
		}

		TabCtrl_SetCurSel(hWndTab, dwCurTab);
		NMHDR nmhdr;
		nmhdr.code = TCN_SELCHANGE;
		nmhdr.idFrom = IDS_PROCPROPSHEET_TABCTRL;
		SendMessageW(hWnd, WM_NOTIFY, 0, (LPARAM)&nmhdr);

		if (gConfig.WindowPlacement[PropWindowplacement].rcNormalPosition.right
			== gConfig.WindowPlacement[PropWindowplacement].rcNormalPosition.left)
		{
			POINT pt;
			GetCursorPos(&pt);
			PE_SetWindowPlacement(hWnd, pt);
		}
		else
		{
			RepositionWindows(hWnd, pItem);
		}
		ShowWindow(hWnd, SW_SHOW);
		InterlockedDecrement(&gnRefCount);
		SetCursor(LoadCursor(NULL, IDC_ARROW));
		return	1;
	}

	else if (msg == WM_COMMAND)
	{
		UINT nID = LOWORD(wParam);
		PROPITEM* pPropItem = (PROPITEM*)GetWindowLongPtr(hWnd, GWLP_USERDATA);
		if (nID == 40093)	//IDM_SELECT_PROCESS_PERFORMANCE
		{
			int nTab = TabCtrl_GetCurSel(hWndTab);
			NMHDR nmhdr = { 0 };
			int nNewTab = nTab - 1;
			if (!nTab)
			{
				nNewTab = 0;
				for (DWORD dwIndex = 1; dwIndex < MAX_PROPITEM_COUNT; dwIndex++, nNewTab++)
				{
					if (pPropItem->PageData[dwIndex].PageWndProc == NULL)
						break;
				}
			}
			TabCtrl_SetCurSel(hWndTab, nNewTab);
			nmhdr.code = TCN_SELCHANGE;
			nmhdr.idFrom = IDS_PROCPROPSHEET_TABCTRL;
			SendMessageW(hWnd, WM_NOTIFY, 0, (LPARAM)&nmhdr);

		}
		else if (nID == 40092)
		{
			int nTab = TabCtrl_GetCurSel(hWndTab) + 1;
			NMHDR nmhdr = { 0 };
			if (!pPropItem->PageData[nTab].PageWndProc == NULL)
				nTab = 0;

			TabCtrl_SetCurSel(hWndTab, nTab);
			nmhdr.code = TCN_SELCHANGE;
			nmhdr.idFrom = IDS_PROCPROPSHEET_TABCTRL;
			SendMessageW(hWnd, WM_NOTIFY, 0, (LPARAM)&nmhdr);
		}
		else if(nID == IDOK || nID == IDCANCEL || nID == 40014)
		{
			ShowWindow(hWnd, SW_HIDE);

			for (DWORD dwIndex = 0, j = MAX_PROPITEM_COUNT; dwIndex < MAX_PROPITEM_COUNT; dwIndex++, j--)
			{
				SendMessageW(pPropItem->PageData[dwIndex].hWnd, WM_COMMAND, wParam, 0);
				SendMessageW(pPropItem->PageData[dwIndex].hWnd, WM_MSG_7F1, 0, 0);
				if (!j)
				{
					PostMessage(ghMainWnd, WM_MSG_7ED, 0, (LPARAM)pPropItem->pListItem);
					if (((tagTREEVIEWITEMPARAM*)pPropItem->pListItem)->pNetCclrInfo)
						CoUninitialize();
					free(pPropItem);
					GetWindowPlacement(hWnd, &gConfig.WindowPlacement[PropWindowplacement]);
					DestroyWindow(hWnd);
					_endthread();
				}
			}
		}
		return 0;
	}

	else if (msg == WM_NOTIFY)
	{
		PROPITEM* pPropItem = (PROPITEM*)GetWindowLongPtr(hWnd, GWLP_USERDATA);
		NMHDR* pNMHDR = (NMHDR*)lParam;
		if (pNMHDR->idFrom == IDS_PROCPROPSHEET_TABCTRL
			&&pNMHDR->code != TCN_SELCHANGE)
		{
			int nTab = TabCtrl_GetCurSel(hWndTab);
			if (nTab != -1)
			{
				gConfig.dwDefaultProcPropPage = pPropItem->PageData[PROCPAGE_Info].nTabId;
				ShowWindow(pPropItem->PageData[nTab].hWnd, SW_HIDE);
				if (pPropItem->PageData[PROCPAGE_Info].hWnd == NULL)
				{
					pPropItem->PageData[PROCPAGE_Info].hWnd = CreateDialogParam(ghMainInstance,
						pPropItem->PageData[PROCPAGE_Info].szTemplateName,
						hWnd,
						pPropItem->PageData[PROCPAGE_Info].PageWndProc,
						(LPARAM)pPropItem->pListItem);
				}
				ShowWindow(pPropItem->PageData[PROCPAGE_Info].hWnd, SW_SHOW);
				return 0;
			}
		}
		return	0;
	}
	else if (msg != WM_SIZE)
	{
		if (msg == WM_GETMINMAXINFO)
		{
			MINMAXINFO* pInfo = (MINMAXINFO*)lParam;
			pInfo->ptMaxSize.x = (gcxFullScreen + gcxFullScreen);
		}
		return 0;
	}
	else
	{
		RECT Rect;
		PROPITEM* pPropItem = (PROPITEM*)GetWindowLongPtr(hWnd, GWLP_USERDATA);
		///WM_SIZE
		for (DWORD dwIndex = 0; dwIndex < MAX_PROPITEM_COUNT; dwIndex++)
		{
			if (pPropItem->PageData[dwIndex].hWnd)
			{
				GetWindowRect(hWndTab, &Rect);
				SendMessageW(hWndTab, TCM_ADJUSTRECT, 0, (LPARAM)&Rect);
				MapWindowPoints(NULL, hWnd, (LPPOINT)&Rect, 2);
				MoveWindow(pPropItem->PageData[dwIndex].hWnd, Rect.left, Rect.top, Rect.right - Rect.left, Rect.bottom - Rect.top, TRUE);
				InvalidateRect(pPropItem->PageData[dwIndex].hWnd, NULL, TRUE);
			}
		}
	}
	return 0;
}

BOOL RepositionWindows(HWND hWnd, tagTREEVIEWITEMPARAM* pItem)
{
	WINDOWPLACEMENT wp = { sizeof(wp) };

	int cxFullScreen = gcxFullScreen;
	int cyFullScreen = gcyFullScreen;
	int nWidth = 0, nTotalWidth = 0;
	int nHeight = 0, nTotalHeight = 0;

	if (cxFullScreen)
	{
		nWidth = GetSystemMetrics(SM_XVIRTUALSCREEN);
		nTotalWidth = nWidth + cxFullScreen;
		nHeight = GetSystemMetrics(SM_YVIRTUALSCREEN);
		nTotalHeight = nHeight + cyFullScreen;
	}
	else
	{
		nWidth = 0;
		nHeight = 0;
		nTotalWidth = gcxScreen;
		nTotalHeight = gcyScreen;

	}

	RECT* lprc = NULL;
	if (pItem->field_4)
		lprc = &gConfig.WindowPlacement[DllPropWindowplacement].rcNormalPosition;
	else
		lprc = &gConfig.WindowPlacement[PropWindowplacement].rcNormalPosition;


	memset(&wp, 0, sizeof(WINDOWPLACEMENT));
	CopyRect(&wp.rcNormalPosition, lprc);
	wp.showCmd = SW_HIDE;
	SetWindowPlacement(hWnd, &wp);
	RECT Rect;

	GetWindowRect(hWnd, &Rect);
	DWORD dwProcessId = 0;
	int left = 0, top = 0, right = 0, bottom = 0;
	top = Rect.top;
	left = Rect.left;
	HWND hWndFound = FindWindowExW(GetDesktopWindow(), NULL, MAKEINTRESOURCEW(32727), NULL);
	if (hWndFound)
	{
		do
		{
			GetWindowThreadProcessId(hWndFound, &dwProcessId);
			if (dwProcessId == GetCurrentProcessId()
				&& hWndFound != hWnd)
			{
				RECT rcWindow;
				GetWindowRect(hWndFound, &rcWindow);
				top = Rect.top;
				if (rcWindow.top == Rect.top)
				{
					left = Rect.left;
					if (rcWindow.left == Rect.left)
					{
						if (Rect.top + 20 > nTotalHeight - 50 || Rect.left + 20 > nTotalWidth - 50)
						{
							break;
						}

						Rect.bottom += 20;
						Rect.right += 20;
						Rect.top += 20;
						Rect.left += 20;
						hWndFound = NULL;
					}
				}
			}

			hWndFound = FindWindowExW(GetDesktopWindow(), hWndFound, MAKEINTRESOURCEW(32727), NULL);

		} while (hWndFound);
	}

	right = Rect.right;
	if (Rect.right > nTotalWidth)
	{
		right = nTotalWidth;
		left += nTotalWidth - Rect.right;
		Rect.right = nTotalWidth;
		Rect.left = left;
	}
	if (left < nWidth)
	{
		left = nWidth;
		Rect.left = nWidth;
	}
	bottom = Rect.bottom;
	if (Rect.bottom > nTotalHeight)
	{
		bottom = nTotalHeight;
		top += nTotalHeight - Rect.bottom;
		Rect.bottom = nTotalHeight;
		Rect.top = top;
	}
	if (top < nHeight)
	{
		top = nHeight;
		Rect.top = nHeight;
	}
	return MoveWindow(hWnd, left, top, right - left, bottom - top, FALSE);
}



BOOL __stdcall EnumChildrenWindows(HWND hWnd, LPARAM lParam)
{
	if (GetParent(hWnd))
	{
		if (!GetParent(hWnd))
			return TRUE;
		if (IsWindowVisible(GetParent(hWnd)))
			return TRUE;
	}
	if (!IsWindowVisible(hWnd))
		return TRUE;
	DWORD dwPId = (DWORD)lParam;

	DWORD dwProcessId = 0;
	GetWindowThreadProcessId(hWnd, &dwProcessId);
	if (dwProcessId != dwPId)
		return TRUE;
	WCHAR szText[256] = { 0 };

	GetWindowTextW(hWnd, szText, 256);
	if (!szText[0])
		return TRUE;

	if (gbWindowTextFlags)
	{
		*gpszWindowText = 0;
	}
	else
	{
		gbWindowTextFlags = 1;
		wcsncpy_s(gpszWindowText, gdwWindowTextLength, szText, -1);
		ghMainWndBackup = hWnd;
	}
	return 0;
}


INT_PTR CALLBACK PageProcPerf(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return 0;
}
INT_PTR CALLBACK PageProcCPU(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return 0;
}
INT_PTR CALLBACK PageProcPerfETW(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return 0;
}
INT_PTR CALLBACK PageProcGPU(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return 0;
}
INT_PTR CALLBACK PageProcServices(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return 0;
}
INT_PTR CALLBACK PageProcWMIProviders(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return 0;
}
INT_PTR CALLBACK PageProcThreads(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return 0;
}
INT_PTR CALLBACK PageProcTcpUdp(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return 0;
}
INT_PTR CALLBACK PageProcSecurity(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return 0;
}
INT_PTR CALLBACK PageProcEnv(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return 0;
}


INT_PTR CALLBACK PageProcJob(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return 0;
}
INT_PTR CALLBACK PageProcCclr(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return 0;
}
INT_PTR CALLBACK PageProcInfo(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return 0;
}
INT_PTR CALLBACK PageProcNetPerf(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return 0;
}

INT_PTR CALLBACK PageProcStrings(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return 0;
}
