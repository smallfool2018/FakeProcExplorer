#ifndef __TREELISTDATA_H__
#define __TREELISTDATA_H__
#pragma once

struct tagTreeViewChildItem;

/// 
///Size = 8;
class CTreeListData
{
public:
	CTreeListData();
	virtual ~CTreeListData();
	
public:
	DWORD	m_Value;
};

//////////////////////////////////////////////////////////////////////////
///Size = 8;
class CListViewData :public CTreeListData
{
public:
	CListViewData();
	virtual ~CListViewData();

	virtual WCHAR* GetItemText(tagTreeViewChildItem* pChild, UINT iSubItem, WCHAR* pszText, PDWORD cbSize);

public:

};

#endif //__TREELISTDATA_H__
