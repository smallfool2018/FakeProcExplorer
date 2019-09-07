#ifndef __TREELIST_H__
#define __TREELIST_H__
#pragma once


//////////////////////////////////////////////////////////////////////////
class CModule
{
public:
	CModule(LPCTSTR lpModuleName)
		:m_hModule(NULL)
	{
		m_hModule = LoadLibrary(lpModuleName);
	}
	~CModule()
	{
		if (m_hModule != NULL)
		{
			FreeLibrary(m_hModule);
			m_hModule = NULL;
		}
	}
	FARPROC GetFunc(LPCSTR lpszFuncName)
	{
		return m_hModule ? GetProcAddress(m_hModule, lpszFuncName) : NULL;
	}
public:
	HMODULE m_hModule;
};

#include "Resizer.h"

//////////////////////////////////////////////////////////////////////////
///针对子项的消息传递
///
enum ETreeMsg
{
	TREELIST_MSG_2000 = 0x2000,		///wParam = tagTreeViewChildItem*
	TREELIST_MSG_2001 = 0x2001,		///wParam = tagTreeViewChildItem*
	TREELIST_MSG_2002 = 0x2002,		///wParam = tagTreeViewChildItem*,返回tagTreeViewChildItem::m_nCount;
	TREELIST_MSG_2003 = 0x2003,		///wParam = tagTreeViewChildItem*,刷新指定的子项
	TREELIST_MSG_2004 = 0x2004,
	TREELIST_MSG_2005 = 0x2005,		///wParam = tagTreeViewChildItem*,搜索指定子项的子项
	TREELIST_MSG_2006 = 0x2006,
};
//CTreeList::SendNotify(pThis, pThis->m_hWnd, 2000, 0, 0, pChild, 0);
//if (!CTreeList::SendNotify(this, this->m_hWnd, 2001, 0, a2, 0, 0))
//if (!CTreeList::SendNotify(this, this->m_hWnd, 2002, 0, a2, 0, 0))
//CTreeList::SendNotify(this, this->m_hWnd, 2000, 0, pItem, pChildLast, 0);
//CTreeList::SendNotify(pThis, pThis->m_hWnd, -2, 0, pChild, 0, 0);
//
//CTreeList::SendNotify(
//	pThis,
//	pThis->m_hWndTooltipOfTreeList,
//	2005,
//	pThis->m_nHeaderItemCount,
//	pThis->m_point.y,
//	0,
//	0);
//if (CTreeList::SendNotify(pThis, pThis->m_hWnd, 2004, pThis->m_nHeaderItemCount, v33, 0, lParam + 12))
enum ETreeViewNotification
{
	TVN_7D0 = 0x7D0,
	TVN_7D1,
	TVN_7D2,
};


#define TVLS_HASCHILD		0x10
#define TVLS_SHOWSERVICES	0x20
#define TVLS_0X_40			0x40

#define ItemHasChild(pItem) (((pItem)->m_dwStyle >> 4) & 1)

#define TVLS_ENABLEJOBS		0x800	///进程支持JOB作业

#define TVLN_FFFFFF65		(LVN_FIRST-55)


//////////////////////////////////////////////////////////////////////////
typedef struct tagHeaderItem
{
	TCHAR*	szText;
	int		nWidth;
	bool	fRight;
}HEADERITEM,*PHEADERITEM,*LPHEADERITEM;

enum EListParamType
{
	LISTPARAM_DllInfos = 1,
};

//////////////////////////////////////////////////////////////////////////
///0x88
typedef struct tagNetCclrInfo
{

}NETCCLRINFO, *PNETCCLRINFO, *LPNETCCLRINFO;

//////////////////////////////////////////////////////////////////////////
///
///
///0x5C0
///
typedef struct tagTREEVIEWITEMPARAM
{
	DWORD	field_4;///
	///24
	LONG	nRefCount;
	///28
	DWORD	dwStyle;

	///34
	HICON	hIcon;
	HICON	hFileIcon;
	WCHAR*	szProcessName2;
	int		nImage;
	///44
	DWORD	dwProcessId;
	WCHAR*	pszSystemName;
	DWORD	InheritedFromUniqueProcessId;
	///50

	///54
	PVOID	pItemParam;
	
	///5C
	DWORD	HandleCount;


	///268
	HWND	hMainWndBackup;
	bool	bMainWndIsHung;
	FILETIME CreateTime;


	///310
	WCHAR*	pszTitle;

	WCHAR*	szProcessName;
	WCHAR*	pszComments;

	WCHAR*	pszFullUserName;

	WCHAR*	pszPackageFullName;

	///34C
	void*	m_ItemDataForVirusTotal;

	///360;
	WCHAR*	szServiceName;	///ServiceType;
	///364
	BOOL	bSupportWMIProviders;

	///0000036C
	DWORD	VirtualSize;
	DWORD	PageFaultCount;///  dd ?
	
	///00000374 field_374   ///    dd ?
	///00000378
	DWORD	PagefileUsage;///   dd ?
		///0000037C field_37C       //dd ?
		///00000380 
	DWORD	PeakPagefileUsage; ///dd ?
	///00000384 
	DWORD	WorkingSetSize;  ///dd ?
	///00000388 
	DWORD	PeakWorkingSetSize; ///dd ?
	///0000038C 
	CGraphData*		pGraphData2;     ///dd ?


	///428
	CGraphData	*pGraphDataPROCCPU;

	///504
	tagNetCclrInfo	*pNetCclrInfo;

	///530
	FILETIME	KernelTime;

	///558
	DWORD		ProcessBasePriority;
	CGraphData	*pGraphData1;

	///570
	CGraphData	*pGraphData4;

	///588
	CGraphData	*pGraphData6;

	///598
	CGraphData	*pGraphData7;

	///5A8
	CGraphData	*pGraphData5;

	///5B0
	tagTREEVIEWITEMPARAM*	m_Prev;
	tagTREEVIEWITEMPARAM*	m_Next;
	///5B8
	///5BC
}TREEVIEWITEMPARAM, *PTREEVIEWITEMPARAM, *LPTREEVIEWITEMPARAM;

extern tagTREEVIEWITEMPARAM* gpTreeViewListItemParam;
//////////////////////////////////////////////////////////////////////////
///DLL List Param....
///0x188
///sub_447790
typedef struct tagDLLLISTITEMPARAM
{
	LONG	m_nRefCount;
	//0x44
	DWORD dwProcessId;


	CString m_strPath;

	CString m_strLocation;

	//0x184
	tagDLLLISTITEMPARAM* m_Prev;
	tagDLLLISTITEMPARAM* m_Next;
}DLLLISTITEMPARAM,*PDLLLISTITEMPARAM,*LPDLLLISTITEMPARAM;

typedef struct tagDLLINFOLISTITEMPARAM
{
	LONG		m_nRefCount;
	DWORD		m_dwType;	//m_dwType == LISTPARAM_DllInfos

	//0x24
	DWORD		m_LoadAddress;

	DWORD		m_dwStyle;

	DWORD		m_MappedSize;

	//0x44
	DWORD		dwProcessId;
	time_t		m_BuildTime;

	WCHAR		m_szVersion[17];

	CString		m_strDescription;
	CString		m_strCompanyInfo;
	CString		m_strPath;

	CString		m_strLocation;

	///16C
	void*		m_HashData;

	//0x184
	tagDLLINFOLISTITEMPARAM* m_Prev;
	tagDLLINFOLISTITEMPARAM* m_Next;
}DLLINFOLISTITEMPARAM, *PDLLINFOLISTITEMPARAM, *LPDLLINFOLISTITEMPARAM;





typedef struct tagHANDLELISTITEMPARAM
{
	DWORD	dwValue;
}HANDLELISTITEMPARAM, *PHANDLELISTITEMPARAM, *LPHANDLELISTITEMPARAM;


extern LPDLLLISTITEMPARAM gpDllListItemParamHeader;
extern void tagDLLLISTITEMPARAM_Release(tagDLLLISTITEMPARAM*& pItem);
extern void tagDLLLISTITEMPARAM_AddRef(tagDLLLISTITEMPARAM* pItem);

extern void TreeViewItemParam_InitGraph(tagTREEVIEWITEMPARAM* pItem);
extern void TreeViewItemParam_AddRef(tagTREEVIEWITEMPARAM* pItem);
extern void TreeViewItemParam_Release(tagTREEVIEWITEMPARAM*& pItem);

__forceinline BOOL ProcessIsNetCclr(tagTREEVIEWITEMPARAM* pItem)
{
	if (!pItem || !pItem->dwProcessId || !gpfn_EnableTraceEx)
		return FALSE;
	DWORD dwFlags = 0;
	QueryNetCclrProcessFlags(pItem->dwProcessId, &dwFlags);
	return dwFlags != 0;
}

class CTreeListData;
class CTreeList;

//////////////////////////////////////////////////////////////////////////
///tagTreeViewChildItem
typedef struct tagTreeViewChildItem
{
	CTreeList*	m_TreeList;
	//04
	CTreeListData *m_TreeListData;
	tagTreeViewChildItem* m_Current;
	
	tagTreeViewChildItem* m_Item0C;
	///10
	tagTreeViewChildItem* m_Prev;
	tagTreeViewChildItem* m_Next;
	tagTreeViewChildItem* m_Item18;
	///1C
	int		m_nCount;
	DWORD	m_dwStyle;
}TREEVIEWCHILDITEM, PTREEVIEWCHILDITEM, *LPTREEVIEWCHILDITEM;

__forceinline int TreeViewChildItem_GetSiblingCount(tagTreeViewChildItem* pItem)
{
	tagTreeViewChildItem* pCurrent = pItem->m_Current;
	int ret = -1;
	for (; pCurrent; ++ret)
		pCurrent = pCurrent->m_Current;
	return ret;
}

__forceinline int TreeViewChildItem_GetChildCount(tagTreeViewChildItem* pItem)
{
	if (!((pItem->m_dwStyle >> 4) & 1))
		return 0;

	tagTreeViewChildItem* p = pItem->m_Next;
	int ret = pItem->m_nCount;
	while (p)
	{
		ret += TreeViewChildItem_GetChildCount(p);
		p = p->m_Prev;
	}
	return ret;
}

extern tagTreeViewChildItem* TreeViewChildItem_GetChild(tagTreeViewChildItem* pItem, int nPos);

typedef struct tagTVNMHDR
{
	NMHDR nmhdr;
	tagTreeViewChildItem* pChild;
	tagTreeViewChildItem* pSibling;
	int		nMsg;
	int		nItem;
}TVNMHDR,*PTVNMHDR,*LPTVNMHDR;

//////////////////////////////////////////////////////////////////////////
//220 = 0xDC

typedef BOOL (*LPFN_DrawBack)(int nColumn, HDC hDC, COLORREF* pColorReturned);
typedef HCURSOR(*LPFN_GetChildCursor)(tagTreeViewChildItem* pItem, int nItem);



class CTreeList : public CThemedWindow
{
public:
	CTreeList();
	virtual ~CTreeList();

	virtual TCHAR* GetName() { return TEXT("treeview"); }

	BOOL OnInited();
	static CTreeList* GetTreeList(HWND hWnd);

	static HWND Init(HWND hWndParent, HINSTANCE hInstance, HMENU hMenuID, DWORD dwStyle, RECT *lprc);
	static ATOM Register();
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	static LRESULT CALLBACK Proxy_HeaderWndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	static LRESULT CALLBACK Proxy_TooltipWndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	static HWND CreateTooltips(HINSTANCE hInst, HWND hWndParent);
	static void InitToolTips(HWND hWndTooltips);
	static void InitHeaderColumn(HWND hWndTreeListView, int nItem = -1, DWORD dwProcessSortColumn = 0, bool bProcessSortDirection = false);

	HWND GetTooltipOfTreeList() { return m_hWndTooltipOfTreeList; }
	HWND GetTooltipOfLeftHeader() { return m_hWndTooltipOfLeftHeader; }
	HWND GetTooltipOfRightHeader() { return m_hWndTooltipOfRightHeader; }
	HIMAGELIST GetImageList() { return m_ImageList; }
	void ResetImageList(HIMAGELIST hImgList, bool flags = false);
	bool UpdateLeftBottomSB(HWND hWnd, bool fHide, bool fSBVisible);
	bool UpdateRightRightSB(bool fHide, bool fSBVisible);

	int FindChild(tagTreeViewChildItem* pChild);
	BOOL ShowCaption(BOOL bVisible);

	BOOL SendNotify(HWND hWnd, int Code, int msg, tagTreeViewChildItem* pSibling, tagTreeViewChildItem* pChild, int nItem);
	BOOL SendNotifyEx(HWND hWndParent, TVNMHDR* pNMHDR);

	void RedrawZone(int nStart, int nEnd);

	static LRESULT FindItem(HWND hWndTree, LPARAM lParam);

	static BOOL InitTreeList(HWND hWndList, BOOL Flags = TRUE);

	void OnDestroy();
	void OnSize();

	void RepositionHeaders();
	void RepositionTooltips();
	int RefreshChildItem(tagTreeViewChildItem* pItem);
	int Refresh();
	void DrawTree(PAINTSTRUCT* lpps, HRGN hRgn);
	void RedrawChild(tagTreeViewChildItem* pItem);

	static DWORD WINAPI BackendFillTreeViewParamThreadProc(void* p);
	static void FillTreeViewParam(tagTREEVIEWITEMPARAM* pItem);

public:
	/// 本窗口句柄
	HWND		m_hWnd;
	/// 左边Pane的头部窗口句柄
	HWND		m_hWndHeaderLeft;
	/// 左边头部窗口的提示窗口句柄
	HWND		m_hWndTooltipOfLeftHeader;
	///	右边头部窗口句柄
	HWND		m_hWndHeaderRight;
	/// 右边头部窗口的提示窗口句柄
	HWND		m_hWndTooltipOfRightHeader;

	///	右边Pane的右边竖直滚动条
	HWND		m_hWndScrollBarRightRight;
	/// 左边Pane的下面水平滚动条
	HWND		m_hWndScrollBarLeftBottom;
	/// 右边Pane的下面水平滚动条
	HWND		m_hWndScrollBarRightBottom;

	/// 
	HWND		m_hWndStatic;
	///	本窗口的工具提示窗口句柄
	HWND		m_hWndTooltipOfTreeList;
	HFONT		m_Font;
	HCURSOR		m_hCursor;
	HIMAGELIST	m_ImageList;
	bool		m_NotMyImageList;
	
	///54
	tagTreeViewChildItem*	m_ChildItem;

	///5C
	int			m_nChildCount;

	/// 60
	DWORD		m_dwTreeStyle;
	///
	POINT		m_ptOffset;

	///68
	int			m_nHeight;
	///0x6C
	int			m_nImageWidth;
	int			m_Height;

	///78
	int			m_nChildWidth;
	///当前操作的子对象
	tagTreeViewChildItem	*m_ChildLast;
	///80
	int			m_nLastVScrollPos;

	int			m_nLastVScrollPos2;
	/// 底部滚动条的宽度或高度  
	/// -0x90
	int			m_nBottomScrollBarWidthOrHeight;
	int			field_94;
	///98
	int			m_nChildWidthLast;
	bool		m_bValue1;
	bool		m_bSkipTimerForTooltip;

	///0xA0
	UINT		m_Format;	//DT_SINGLELINE;
	int			m_nHeaderItemCount;
	POINT		m_point;

	///0xB0
	WNDPROC		m_TooltipWndProc;
	bool		field_BC;

	///0xC0
	POINT		m_ptDownLast;
	///0xC8
	WNDPROC		m_HeaderWndProc;
	///0xCC
	DWORD		m_dwTickCountLast;
	LPFN_DrawBack		m_DrawBack;
	FARPROC		m_Callback1;

	///0xD0
	_bstr_t		m_strText;

	//
	LPFN_DrawBack			m_pfnDrawBack;
	///0xD8
	LPFN_GetChildCursor		m_pfnGetChildCursor;
	///End of Offset
public:
	bool UpdateSB(bool flags);
	void SetSplitterCursor(HCURSOR hCursor);
	void SetSortFlagsImageList(HIMAGELIST hImgList, int x, int y);
	int Query(int xPos, int yPos, int* pxx, int* pnItem, tagTreeViewChildItem** ppItem);

	tagTreeViewChildItem* GetCurScrollChildItem();
	int GetScrollInfos(SCROLLINFO* RightScrollInfo, SCROLLINFO* BottomScrollInfo);

private:
	int GetChildWidth(int nChildID);

	void PopTooltip(HWND hWndTooltip, LPPOINT pt);
	BOOL MapToHeader(int nItem, LPRECT lprc);
	int GetRightScrollbarPos();
	BOOL SetHScrollPos(HWND hWnd, int nPos);
	BOOL SetVScrollPos(HWND hWnd, int nPos);
	BOOL UpdateVScrollBars(int nPos);
	int GetLineHeight();
	BOOL UpdateHeaderPos(HWND hWnd, int nPos);
	BOOL AddColumnToHeader(tagHeaderItem* pItem, int nCount);
	void MoveHeaders(int cxy);
	LRESULT HandleListViewMsg(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
private:
	LRESULT HeaderWndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	LRESULT TooltipWndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	LRESULT TreeWndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	static void SetHeaderItem(HWND hWndHeader, int nItem, BOOL Flags);
	void InitHeaderColumn(int nItem, bool flags = false);
	void DrawHeader(HWND hWnd, HDC hDC, RECT rc);
	void OnMsg2000(tagTreeViewChildItem* pItem, bool flags);
	bool OnMsg2001(tagTreeViewChildItem* pItem, bool fChild);

};

extern BOOL Command_OnProperties(HWND hWnd);
extern bool gbBitmapOnRight;

#define TreeList_GetCurSel(hWnd)		ListView_GetNextItem((hWnd),(-1),(LVFI_STRING))
#define TreeList_GetItemParam(hWnd,i)	do{LVITEM Item = {0};Item.iItem = i;Item.mask = LVIF_PARAM;ListView_GetItem((hWnd),(&Item));while(0)

extern BOOL RepositionWindows(HWND hWnd, tagTREEVIEWITEMPARAM* pItem);


#endif //__TREELIST_H__
