#include "stdafx.h"


HRESULT SelectColor(HWND hWnd, COLORREF* ColorReturned)
{
	CHOOSECOLORW cc = { sizeof(cc) };

	cc.hInstance = (HWND)ghInstance;
	cc.rgbResult = *ColorReturned;

	cc.hwndOwner = hWnd;
	cc.lpCustColors = gColorCustomized;
	cc.lCustData = 0;
	cc.Flags = 1;
	if (ChooseColorW(&cc))
	{
		*ColorReturned = cc.rgbResult;
		InvalidateRect(ghWndTreeListView, NULL, TRUE);
		InvalidateRect(ghWndDllsListCtrl, NULL, TRUE);
		InvalidateRect(ghWndHandlesListCtrl, NULL, TRUE);
		InvalidateRect(hWnd, NULL, TRUE);
	}
	return S_OK;
}

HBRUSH BrushFromColor(COLORREF clr, HBRUSH* BrushHandle)
{
	if (*BrushHandle)
	{
		DeleteObject(*BrushHandle);
	}
	HBRUSH ret = CreateSolidBrush(clr);
	*BrushHandle = ret;
	return ret;
}

INT_PTR CALLBACK DlgSelectColor(HWND hDlg, UINT nMsg, WPARAM wParam, LPARAM lParam)
{

	return 0;
}