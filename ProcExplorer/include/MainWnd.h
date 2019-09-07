#ifndef __MAINWINDOW_H__
#define __MANNWINDOW_H__
#pragma once

typedef LRESULT(*LPFN_MSGHANDLER)(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

#define	WM_GRAPH_REFRESH	WM_USER


enum EMsgType
{
	MSG_Windows= 1,
	MSG_Dialogs,
	MSG_MDIChild,
	MSG_Frame,
};



typedef struct tagMSGFUNC
{
	UINT msg;
	LPFN_MSGHANDLER pfn;
}MSGFUNC,*PMSGFUNC;

typedef struct tagMSGHANDLER
{
	UINT		nLength;
	PMSGFUNC	WindowMsgFunc;
	BOOL		Flags;
}MSGHANDLER,*PMSGHANDLER;

#define HWNDISVISIBLE(hWnd) ((GetWindowLong(hWnd,GWL_STYLE)>>28)&1)

//////////////////////////////////////////////////////////////////////////
//
//
//
//////////////////////////////////////////////////////////////////////////
class CMainWnd
{
public:
	CMainWnd();

	static LRESULT HandleCommand(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	static LRESULT HandleCreate(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	static LRESULT HandlePaint(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	static LRESULT HandleSize(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	static LRESULT HandleLBtnDown(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	static LRESULT HandleLBtnUp(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	static LRESULT HandleMouseMove(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	static LRESULT HandleDrawItem(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	static LRESULT HandleGetMinmaxInfo(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	static LRESULT HandleNotify(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	static LRESULT HandleMeasureItem(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	static LRESULT HandleClose(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	static LRESULT HandleEndSession(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	static LRESULT HandleDestroy(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	static LRESULT HandleSetFocus(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	static LRESULT HandleKillFocus(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	static LRESULT HandleSysCommand(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	static LRESULT HandleContextMenu(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	static LRESULT HandleInitMenuPopup(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	static LRESULT HandleMenuCommand(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	static LRESULT HandleCopyData(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	static LRESULT HandleDeviceChange(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	
	
	static LRESULT HandleTreeViewSort(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	static LRESULT HandleTrayIcon(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

	static LRESULT HandleMsg7E8(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	static LRESULT HandleMsg7E9(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

	static LRESULT HandleMsg7EB(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	static LRESULT HandleMsg7ED(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	static LRESULT HandleMsg7EE(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	static LRESULT HandleMsg7EF(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	static LRESULT HandleMsg7F8(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	static LRESULT HandleMsg7F0(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	static LRESULT HandleMsg7F6(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	static LRESULT HandleMsg7F2(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	static LRESULT HandleMsg7F3(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	static LRESULT HandleMsg7F9(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	static DWORD WINAPI BackendRefreshThreadProc(void* p);
	static BOOL Hide(HWND hWnd);
public:
	static LRESULT CALLBACK MainWndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	static BOOL Draw(int nColumn, HDC hDC, COLORREF* pColorReturned);
	static HCURSOR GetDynamicCursor(int nColumn, int nIndex);


private:
	static bool RefreshDllsView(HWND hWndList, UINT nID, LPARAM lParam);
	static bool RefreshHandlesView(HWND hWndList, UINT nID, LPARAM lParam);
	static bool DrawList(LPDRAWITEMSTRUCT lpDis);

};


#define GRAPHCLASSNAME TEXT("CpuGraphClassGraph")

extern RECT gMainWndRect;

extern HWND InitToolbar(HWND hWnd, UINT nIDToolbar);
extern void InitStatusBar(HWND hWndSB);

struct CGraphData;

extern CGraphData*	gpGraphInfoOfMemory;
extern CGraphData*	gpGraphInfoOfCPU;
extern CGraphData*	gpGraphInfoOfGPU;
extern CGraphData*	gpGraphInfoOfSystemMemory;
extern CGraphData*	gpGraphInfoOfDedicatedMemory;
extern CGraphData*	gpGraphInfoOfPhysicalMemory;
extern UINT gdwRefreshMenuIDLast;
extern bool gbETWFlagsInProcPropSheet;
extern DWORD	gdwValue_4F10B8[];


extern BOOL UpdateMenuStatus(BOOL bEnabled, int nPos);
extern void Command_ShowLowerPane(HWND hWnd);
extern BOOL Command_SaveColumnSet(HWND hWnd);
extern int Command_Cancel(HWND hWnd);
extern int Command_OpenProcExp(HWND hWnd);
extern BOOL Command_SetProcessPriority(HWND hWnd,WPARAM wParam);
extern void StartBackendThread();
extern BOOL ProcessPriority_Set(HWND hWnd, WORD uID);
extern int Command_SystemInformation(HWND hWnd);

#define EnableDlgItem(hWnd,nID,State) EnableWindow(GetDlgItem(hWnd,nID),(State))


#endif //