#include "stdafx.h"
#include "..\include\Resizer.h"

//////////////////////////////////////////////////////////////////////////
CResizer::CResizer(HWND hDlg)
	:m_hWnd(hDlg)
	, m_OldWndProc(NULL)
	,m_nWidth(0)
	,m_nHeight(0)
	,m_nWidth3(0)
	,m_nHeight3(0)
	,m_hDWP(NULL)
	,m_nXRatio(50)
	,m_nYRatio(67)
	,m_FixedBorder(true)
	,m_Buffer(NULL)
	,m_dwBufferCount(0)
{
	m_ptMinTrackSize.x = 0;
	m_ptMinTrackSize.y = 0;
	InitWnd(hDlg);
}


CResizer::~CResizer()
{
	if (GetWindowLongPtr(m_hWnd, GWLP_WNDPROC) == (LONG_PTR)CResizer::Proxy_WndProc)
		SetWindowLongPtr(m_hWnd, GWLP_WNDPROC, (LONG_PTR)m_OldWndProc);

	m_hWnd = NULL;
	if (m_hThemeHandle != NULL)
	{
		gpfnCloseThemeData(m_hThemeHandle);
		m_hThemeHandle = NULL;
	}

	if (m_Buffer != NULL)
	{
		free(m_Buffer);
		m_Buffer = NULL;
	}
}

//////////////////////////////////////////////////////////////////////////
//	CResizer::InitWnd:	拦截指定的窗口句柄
//	hWnd:
//
//	返回值:
//
//////////////////////////////////////////////////////////////////////////
BOOL CResizer::InitWnd(HWND hWnd)
{
	m_hWnd = hWnd;

	///拦截默认的窗口处理函数
	SetProp(hWnd, TEXT("ResizerClass"), (HANDLE)this);
	m_OldWndProc = (WNDPROC)GetWindowLongPtrW(hWnd, GWLP_WNDPROC);
	SetWindowLongPtr(hWnd, GWLP_WNDPROC, (LONG_PTR)CResizer::Proxy_WndProc);

	if (m_hThemeHandle != NULL)
	{
		gpfnCloseThemeData(m_hThemeHandle);
	}
	m_hThemeHandle = NULL;
	if (gpfnIsThemeActive&&gpfnIsThemeActive())
	{
		m_hThemeHandle = gpfnOpenThemeData(hWnd, GetName());
	}

	RECT rcWindow;
	GetWindowRect(m_hWnd, &rcWindow);
	/// 保留当前窗口尺寸大小
	m_nWidth = rcWindow.right - rcWindow.left;
	m_ptMinTrackSize.x = m_nWidth;

	m_nHeight = rcWindow.bottom - rcWindow.top;
	m_ptMinTrackSize.y = m_nHeight;

	return TRUE;
}

//////////////////////////////////////////////////////////////////////////
//	CResizer::Proxy_WndProc:	拦截指定的窗口句柄
//	hWnd:
//
//	返回值:
//
//////////////////////////////////////////////////////////////////////////
LRESULT CALLBACK CResizer::Proxy_WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	CResizer* pThis = (CResizer*)GetProp(hWnd, TEXT("ResizerClass"));
	switch (msg)
	{
	case WM_DESTROY:	
	{
		///销毁窗口，恢复原始窗口处理函数
		WNDPROC pfnWndProc = pThis->m_OldWndProc;
		SetWindowLongPtr(hWnd, GWLP_WNDPROC, (LONG_PTR)pThis->m_OldWndProc);
		delete pThis;
		return CallWindowProc(pfnWndProc, hWnd, msg, wParam, lParam);
	}
	case WM_SIZE:
	{
		///尺寸调整
		if (!pThis->m_FixedBorder || wParam != SIZE_MAXIMIZED&&wParam)
			return pThis->HandleMessage(hWnd, msg, wParam, lParam);

		RECT rcWindow;
		if (GetWindowRect(hWnd, &rcWindow))
		{
			int nWidth = rcWindow.right - rcWindow.left;
			int nHeight = rcWindow.bottom - rcWindow.top;
			if (nWidth < pThis->m_ptMinTrackSize.x)
				nWidth = pThis->m_ptMinTrackSize.x;
			if (nHeight < pThis->m_ptMinTrackSize.y)
				nHeight = pThis->m_ptMinTrackSize.y;
			///保留当前最新窗口尺寸
			pThis->m_nWidth3 = nWidth;
			pThis->m_nHeight3 = nHeight;
			pThis->Refresh();
		}

		return pThis->HandleMessage(hWnd, msg, wParam, lParam);
	}
	break;
	case WM_PAINT:
	{
		///执行绘画操作
		PAINTSTRUCT ps;
		if (!(GetWindowLong(hWnd, GWL_STYLE)&WS_CHILD)
			&& !IsZoomed(hWnd))
		{
			HDC hDC = BeginPaint(hWnd, &ps);
			RECT rcItem;
			GetClientRect(hWnd, &rcItem);
			rcItem.top = rcItem.bottom - GetSystemMetrics(SM_CXHSCROLL);

			if (pThis->m_hThemeHandle)
				gpfnDrawThemeBackground(pThis->m_hThemeHandle, hDC, SBP_THUMBBTNVERT, 0, &rcItem, NULL);
			else
				DrawFrameControl(hDC, &rcItem, DFC_SCROLL, DFCS_SCROLLSIZEGRIP);
			EndPaint(hWnd, &ps);
		}
		return pThis->HandleMessage(hWnd, msg, wParam, lParam);
	}
	break;
	case WM_GETMINMAXINFO:
	{
		///获取最大最小窗口尺寸
		MINMAXINFO* pMinMaxInfo = (MINMAXINFO*)lParam;
		pMinMaxInfo->ptMinTrackSize = pThis->m_ptMinTrackSize;
		return 0;
	}
	break;
	case WM_NCHITTEST:
	{
		///非客户去单击测试
		RECT rcWindow;
		LRESULT lresult = CallWindowProc(pThis->m_OldWndProc, hWnd, msg, wParam, lParam);
		if ((GetWindowLong(hWnd, GWL_STYLE)&WS_CHILD)
			|| lresult != HTCLIENT
			|| IsZoomed(hWnd))
		{
			GetWindowRect(hWnd, &rcWindow);
			rcWindow.left = rcWindow.right - GetSystemMetrics(SM_CXHSCROLL);
			rcWindow.top = rcWindow.bottom - GetSystemMetrics(SM_CYVSCROLL);
			POINT pt;
			pt.x = LOWORD(lParam);
			pt.y = HIWORD(lParam);
			if (!PtInRect(&rcWindow, pt))
				return lresult;
		}
		return HTBOTTOMRIGHT;
	}
	break;
	case WM_THEMECHANGED:
	{
		///窗口主题发生改变
		if (pThis->m_hThemeHandle != NULL)
		{
			gpfnCloseThemeData(pThis->m_hThemeHandle);
		}
		pThis->m_hThemeHandle = NULL;
		if (gpfnIsThemeActive&&gpfnIsThemeActive())
		{
			pThis->m_hThemeHandle = gpfnOpenThemeData(hWnd, pThis->GetName());
		}
		return pThis->HandleMessage(hWnd, msg, wParam, lParam);
	}
		break;
	default:
		return pThis->HandleMessage(hWnd, msg, wParam, lParam);
		break;
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}



//////////////////////////////////////////////////////////////////////////
//	CResizer::Refresh:	刷新窗口
//	hWnd:
//
//	返回值:
//
//////////////////////////////////////////////////////////////////////////
void CResizer::Refresh()
{
	if (this->m_nHeight != m_nHeight3 || m_nWidth != m_nWidth3)
	{
		m_hDWP = BeginDeferWindowPos(512);
		EnumChildWindows(m_hWnd, EnumChildCallback, (LPARAM)this);

		EndDeferWindowPos(m_hDWP);

		RECT rcItem;
		GetClientRect(m_hWnd, &rcItem);
		RECT rcSrc;
		rcSrc.left = rcItem.right - GetSystemMetrics(SM_CXHSCROLL);
		rcSrc.top = rcItem.bottom - GetSystemMetrics(SM_CYVSCROLL);
		rcSrc.right = rcItem.right;
		rcSrc.bottom = rcItem.bottom;

		RECT rcOffset, rcDest;
		CopyRect(&rcOffset, &rcSrc);
		OffsetRect(&rcOffset, m_nWidth - m_nWidth3, m_nHeight - m_nHeight3);
		UnionRect(&rcDest, &rcOffset, &rcSrc);
		InvalidateRect(m_hWnd, &rcDest, TRUE);

		///备份尺寸
		m_nWidth = m_nWidth3;
		m_nHeight = m_nHeight3;
		InvalidateRect(m_hWnd, NULL, TRUE);
	}
}

//////////////////////////////////////////////////////////////////////////
//	CResizer::EnumChildCallback:	扫描所有的子窗口
//	hWnd:
//
//	返回值:
//
//////////////////////////////////////////////////////////////////////////
BOOL CALLBACK CResizer::EnumChildCallback(HWND hWnd, LPARAM lParam)
{
	BOOL ret = TRUE;
	RECT rcWindow;
	TCHAR szClassName[_MAX_PATH] = { 0 };
	CResizer* pThis = (CResizer*)lParam;

	if (GetParent(hWnd) == pThis->m_hWnd)
	{
		GetWindowRect(hWnd, &rcWindow);
		ScreenToClient(pThis->m_hWnd, (LPPOINT)&rcWindow);
		ScreenToClient(pThis->m_hWnd, (LPPOINT)&rcWindow.right);
		
		double dxScale1 = 0.0, dxScale2 = 0.0;
		int nWidth = (pThis->m_nWidth * pThis->m_nXRatio / 100);

		if (rcWindow.left >= nWidth)
			dxScale1 = 1.0;
		if (rcWindow.right >= nWidth)
			dxScale2 = 1.0;

		double dyScale1 = 0.0, dyScale2 = 0.0;
		int nHeight = (pThis->m_nHeight*pThis->m_nYRatio) / 100;
		if (rcWindow.top >= nHeight)
			dyScale1 = 1.0;
		if (rcWindow.bottom >= nHeight)
			dyScale2 = 1.0;
		
		GetClassName(hWnd, szClassName, _MAX_PATH);

		if (!_tcsicmp(szClassName, TEXT("Button")))
		{
			DWORD dwStyle = (DWORD)GetWindowLong(hWnd, GWL_STYLE);
			dwStyle = dwStyle & BS_TYPEMASK;
			if (!dwStyle || dwStyle == BS_DEFPUSHBUTTON || dwStyle == BS_OWNERDRAW || dwStyle == BS_USERBUTTON)
				ret = FALSE;
		}
		if (!_tcsicmp(szClassName, TEXT("Static")))
			InvalidateRect(NULL, NULL, FALSE);

	}

	return ret;
}


//////////////////////////////////////////////////////////////////////////
//	CResizer::AddItem:	
//	hWnd:
//	fFlags:	
//
//	返回值:
//
//////////////////////////////////////////////////////////////////////////
LPRESIZERITEM CResizer::AddItem(HWND hWnd, bool fFlags)
{
	LPRESIZERITEM ret = NULL;
	if (!hWnd)
		return NULL;
	if (m_dwBufferCount <= 0)
	{

	}
	else
	{

	}
	return NULL;
}