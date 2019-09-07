#include "stdafx.h"
#include "..\include\TreeListData.h"


CTreeListData::CTreeListData()
{
}


CTreeListData::~CTreeListData()
{
}


//////////////////////////////////////////////////////////////////////////
CListViewData::CListViewData()
{

}

CListViewData::~CListViewData()
{

}

WCHAR* CListViewData::GetItemText(tagTreeViewChildItem* pChild, UINT iSubItem, WCHAR* pszText, PDWORD cbSize)
{

	int nItem = pChild->m_TreeList->FindChild(pChild);
	UINT nID = GetWindowLongPtr(pChild->m_TreeList->m_hWnd, GWLP_ID);

	NMLVDISPINFOW Info = { 0 };
	Info.hdr.hwndFrom = pChild->m_TreeList->m_hWnd;
	Info.hdr.idFrom = nID;
	Info.hdr.code = LVN_GETDISPINFOW;

	Info.item.mask = LVIF_TEXT;
	Info.item.lParam = m_Value;
	Info.item.cchTextMax = *cbSize;
	Info.item.pszText = pszText;
	Info.item.iSubItem = iSubItem;
	Info.item.iItem = nItem;

	SendMessage(GetParent(pChild->m_TreeList->m_hWnd), WM_NOTIFY, nID, (LPARAM)&Info);
	return pszText;
}
