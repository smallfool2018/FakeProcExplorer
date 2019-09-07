#pragma once

#include "resource.h"
#include "./include/FakeDDK.h"

#define IDS_PROCEXPOLER		L"Process Explorer"


#define WM_TREEVIEW_SORT	0x7E8
#define WM_NOTIFY_TRAYICON	0x7E9
#define WM_MSG_7EA			0x7EA
#define WM_MSG_7EB			0x7EB
#define WM_MSG_7EC			0x7EC
#define WM_MSG_7ED			0x7ED
#define WM_MSG_7EE			0x7EE
#define WM_MSG_7EF			0x7EF
#define WM_MSG_7F0			0x7F0
#define WM_MSG_7F1			0x7F1
#define WM_MSG_7F2			0x7F2
#define WM_MSG_7F3			0x7F3
#define WM_MSG_7F4			0x7F4
#define WM_MSG_7F5			0x7F5
#define WM_MSG_7F6			0x7F6
#define WM_MSG_7F7			0x7F7
#define WM_MSG_7F8			0x7F8
#define WM_MSG_7F9			0x7F9

///#define WM_PE_MSG1	0x7F2


enum WindowPlacementType
{
	Windowplacement,		///
	FindWindowplacement = 1,

	PropWindowplacement = 2,
	DllPropWindowplacement = 3,
	SysinfoWindowplacement = 4,
	StackWindowPlacement,
};

enum WindowType
{
	WINDOW_NONE,
	WINDOW_NORMAL,
	WINDOW_FRAME,
	WINDOW_DIALOG,
	WINDOW_MDICHILD,
};

//输出风格
enum TRACEFLAGS
{
	TRACE_MSG = 1,
	TRACE_ALV = 2,
	TRACE_WARNING = 4,
	TRACE_ERROR = 8,
	TRACE_OUT = 0x10,
	TRACE_IN = 0x20,
	TRACE_DUMP = 0x40,
	TRACE_FATAL = 0x80,

	///	这似乎是WINSTA.DLL内部所使用
	TRACE_TSAPI_OUT = 0x100,
	TRACE_TSAPI_IN = 0x200,
	TRACE_TSRPC_OUT = 0x400,
	TRACE_TSRPC_IN = 0x800,
	TRACE_BVT = 0x1000,
	TRACE_PERF = 0x2000,
};

enum EOsType
{
	WINDOWS_VISTA = 0x1,
	WINDOWS_7 = 0x2,
	WINDOWS_8 = 0x3,
	WINDOWS_10 = 0x4,
};

//////////////////////////////////////////////////////////////////////////
///定义工具条内的图标索引
///
enum EBmpIndex
{
	BMP_STAR,
	BMP_VIEW_DLLS,
	BMP_SEARCH,
	BMP_SAVE,
	BMP_VIEW_HANDLES,
	BMP_KILL_PROCESS,
	BMP_PROPERTIES,
	BMP_REFRESH,
	BMP_SHOW_PROCESS_TREE,
	BMP_SHOW_LOWER_PANE,
	BMP_HIDE_LOWER_PANE,
	BMP_STOP_SEARCH,
	BMP_FIND_PROCESS_BY_WINDOW,
	BMP_VIEW_SYSTEM_INFORMATION,
};


#define __ERROR__	GetLastError()
#define __TID__		GetCurrentThreadId()
#define __PID__		GetCurrentProcessId()
#define __THREAD__	GetCurrentThread()
#define __PROCESS__	GetCurrentProcess()

#define LoadArrowCursor()		LoadCursor(NULL,IDC_ARROW)
#define LoadAppStringCursor()	LoadCursor(NULL,IDC_APPSTARTING)
#define LoadWaitCursor()		LoadCursor(NULL,IDC_WAIT)
#define LoadHandCursor()		LoadCursor(NULL,IDC_HAND)

#define SetArrowCursor()		SetCursor(LoadCursor(NULL,IDC_ARROW))
#define SetAppStringCursor()	SetCursor(LoadCursor(NULL,IDC_APPSTARTING))
#define SetWaitCursor()			SetCursor(LoadCursor(NULL,IDC_WAIT))
#define SetHandCursor()			SetCursor(LoadCursor(NULL,IDC_HAND))

#define ErrorMsgBox(hWnd,lpszText)					MessageBoxW(hWnd,lpszText,L"Process Explorer Error",MB_ICONERROR)

#define Tooltips_SetDelayTime(hWnd, Flags, Time)	SendMessage((hWnd),TTM_SETDELAYTIME, (Flags), (Time))
#define Tooltips_SetMaxWidth(hWnd,nWidth)			SendMessage((hWnd),TTM_SETMAXTIPWIDTH, 0, (nWidth))

#define DEFINEPATHTEXT(Name)						WCHAR sz##Name[_MAX_PATH] ={ 0 }

#define EXTERN_DEFINE(Name)							extern LPFN_##Name  gpfn_##Name;
#define INIT_LOAD(Name)								LPFN_##Name		gpfn_##Name = (LPFN_##Name)GetProcAddress(GetModuleHandleW(L"NTDLL.DLL"),#Name);
#define INIT_DEFINE(Name)							LPFN_##Name		gpfn_##Name = NULL;
#define INIT_LOADAPI(hModule,Name)					LPFN_##Name		gpfn_##Name = (LPFN_##Name)GetProcAddress(hModule,#Name);

#define LOADKERNELAPI(Name)							LPFN_##Name		pfn_##Name = (LPFN_##Name)GetProcAddress(GetModuleHanleW(L"Kernel32.dll"),#Name)
#define LOADKERNELBASEAPI(Name)						LPFN_##Name		pfn_##Name = (LPFN_##Name)GetProcAddress(GetModuleHanleW(L"KernelBase.dll"),#Name)



#define C_PAGES		4
#define sz_Or_Ord	WORD
#define titleLen	30
#define stringLen	30


//0x64=100
typedef struct
{
	WORD      dlgVer;			//0
	WORD      signature;		//0x02
	DWORD     helpID;			//0x04
	DWORD     exStyle;			//0x08
	DWORD     style;			//0x0C
	WORD      cDlgItems;		//0x0E
	short     x;				//0x10
	short     y;				//0x12
	short     cx;				//0x14
	short     cy;				//0x16
	sz_Or_Ord menu;				//0x18
	sz_Or_Ord windowClass;		//0x20
	WCHAR     title[titleLen];	//0x22
	WORD      pointsize;		//0x40	
	WORD      weight;			//0x42
	BYTE      italic;			//0x44
	BYTE      charset;			//0x45
	WCHAR     typeface[stringLen];//0x46
}DLGTEMPLATEEX;


typedef struct {
	DWORD     helpID;
	DWORD     exStyle;
	DWORD     style;
	short     x;
	short     y;
	short     cx;
	short     cy;
	DWORD     id;
	sz_Or_Ord windowClass;
	sz_Or_Ord title;
	WORD      extraCount;
} DLGITEMTEMPLATEEX;

#define MAX_TEMPLATE_NAME_LEN	256
#define MAX_PROPITEM_COUNT		32

//////////////////////////////////////////////////////////////////////////
///PE主菜单对应的各项
enum EMainMenuIndex
{
	MAINMENU_File,		///文件菜单
	MAINMENU_Options,	///Options菜单
	MAINMENU_View,		///View菜单
	MAINMENU_Process,	///Process菜单
	MAINMENU_Find,		///Find菜单
	MAINMENU_Help,		///Help菜单
};

#define GetFileMenu(hWnd)		GetSubMenu(GetMenu(hWnd),MAINMENU_File)
#define GetOptionsMenu(hWnd)	GetSubMenu(GetMenu(hWnd),MAINMENU_Options)
#define GetViewMenu(hWnd)		GetSubMenu(GetMenu(hWnd),MAINMENU_View)
#define GetProcessMenu(hWnd)	GetSubMenu(GetMenu(hWnd),MAINMENU_Process)
#define GetFindMenu(hWnd)		GetSubMenu(GetMenu(hWnd),MAINMENU_Find)
#define GetHelpMenu(hWnd)		GetSubMenu(GetMenu(hWnd),MAINMENU_Help)


//////////////////////////////////////////////////////////////////////////
///PE用到的系统配置变量结构
typedef struct tagConfigItem
{
	WCHAR* 	Name;		///变量名称
	DWORD 	RegType;	///用于Registry操作的类型
	DWORD 	StructSize;	///结构大小或偏移尺寸
	PVOID 	Address;	///对应的内存中变量地址
	DWORD 	dwValue1;
	DWORD	dwInitValue;///初始化变量值，有时候和dwValue1组成一个double或64位变量

}CONFIGITEM,*PCONFIGITEM,*LPCONFIGITEM;


//////////////////////////////////////////////////////////////////////////
///用于操作Registry的变量结构
typedef struct tagRegKeyInfo
{
	WCHAR*	szKeyName;	///变量对应的键值名称
	HKEY	hKey;		///所属键
	int		nLength;	///变量内存长度
}REGKEYINFO,*PREGKEYINFO,*LPREGKEYINFO;

//////////////////////////////////////////////////////////////////////////
///列表框中一栏对应的结构
typedef struct tagCOLUMNKEYITEM
{
	WORD	wID;		///对应的字符串ID号
	WORD	nWidth;		///该栏宽度
}COLUMNKEYITEM,*PCOLUMNKEYITEM,*LPCOLUMNKEYITEM;


//////////////////////////////////////////////////////////////////////////
///用于初始化PropPage页面的结构信息
typedef struct tagPropPageData
{
	HWND	hWnd;									///本Page窗口句柄
	TCHAR	szTemplateName[MAX_TEMPLATE_NAME_LEN];	///本Page的模板名称
	UINT	nTabId;									///对应PropSheet中的Tab控件Item的ID号
	DLGPROC PageWndProc;							///本Page对应的DlgProc函数

}PROPPAGEDATA,*PPROPPAGEDATA,*LPPROPPAGEDATA;

//////////////////////////////////////////////////////////////////////////
///用于初始化PropSheet页面的结构信息
typedef struct tagPropItem
{
	UINT	nTabIndex;	///当前对应活动Page索引
	void*	pListItem;	///对应当前TreeViewList中的所选中的Item，
						///用于标识对应进程信息 
	PROPPAGEDATA PageData[MAX_PROPITEM_COUNT];///一组Page信息，最多不超过32个页面
}PROPITEM,*PPROPITEM,*LPPROPITEM;


//////////////////////////////////////////////////////////////////////////
///
typedef struct tagListItem
{
	LONG	m_nRefCount;
}LISTITEM,*PLISTITEM,*LPLISTITEM;

//////////////////////////////////////////////////////////////////////////
///
typedef struct tagThreadInfo
{

	DWORD	m_dwThreadId;
	HANDLE	m_ThreadHandle;
}THREADINFO,*PTHREADINFO,*LPTHREADINFO;

//////////////////////////////////////////////////////////////////////////
///
typedef struct tagServerInfo
{
	PTHREADINFO				m_ThreadInfo;
	SECURITY_INFORMATION	m_RequestInformation;
	PSECURITY_DESCRIPTOR	m_SecurityDescriptor;
	DWORD	m_dwError;

	DWORD	m_dwProcessId;

	SC_HANDLE	m_SCHandle;
}SERVERINFO,*PSERVERINFO,*LPSERVERINFO;



#include "include/Lock.h"

//////////////////////////////////////////////////////////////////////////
///Graph对应的结构信息
typedef struct tagGraphItem
{
	double*	pBuffer;
	DWORD	dwValue[2];
	double	dbMemorySize;
	DWORD	dwValue3;
}GRAPHITEM,*PGRAPHITEM,*LPGRAPHITEM;

//////////////////////////////////////////////////////////////////////////
//SIZE 0x898 = 2200
struct CGraphData
{
	CLock			m_Lock;
	int				m_nWidth;
	UINT			m_nChildID;
	UINT			m_nItemID;	//ItemCount

	double			m_dbMemorySize;
	COLORREF		m_Color;
	tagGraphItem	m_Item[16];

	///

	PVOID			m_Buffer;
	FILETIME		m_Time;

	DWORD			m_dwValue868;
	//86C
	PVOID			m_Buffer2;


	//878
	DWORD			m_ProcessorID;
	//87C
	CGraphData*		m_GraphData;

	PVOID			m_ScreenBuffer;
};

//////////////////////////////////////////////////////////////////////////
///
typedef struct tagGraphInfo
{
	_bstr_t		strName;		///标题
	CGraphData*	pGraphData;		///图像结构对象
	double		dbValue;		///
	int			nType;			///类型

	tagGraphInfo()
		:strName()
		, pGraphData(NULL)
		, dbValue(0.0)
		, nType(0)
	{

	}

	tagGraphInfo(LPCSTR lpszText,int type)
		:strName(lpszText)
		, pGraphData(NULL)
		, dbValue(0.0)
		, nType(type)
	{
	}
}GRAPHINFO,*PGRAPHINFO,*LPGRAPHINFO;

typedef struct tagProcessComment
{
	WCHAR* pszName;
	LPBYTE	pszComment;
}PROCESSCOMMENT, *PPROCESSCOMMENT, *LPPROCESSCOMMENT;

//////////////////////////////////////////////////////////////////////////
//
typedef struct tagLogPixelSize
{
	DWORD cx;
	DWORD cy;
	tagLogPixelSize()
	{
		HDC hDC = CreateCompatibleDC(NULL);
		cx = GetDeviceCaps(hDC, LOGPIXELSX);
		cy = GetDeviceCaps(hDC, LOGPIXELSY);
		DeleteDC(hDC);
	}
}LOGPIXELSIZE;


class Process;
//////////////////////////////////////////////////////////////////////////
///-0x28
typedef struct tagPROPCCLRINFO
{
	DWORD	m_dwProcessID;
	HWND	m_hWndTreeList;
	HWND	m_hWndParent;
	LONG	m_nRefCount;

	Process* m_Process;
}PROPCCLRINFO, *PPROPCCLRINFO, *LPPROPCCLRINFO;

//////////////////////////////////////////////////////////////////////////
///记录系统用户帐号相关的信息
///
///0x620=
typedef struct tagAccountInfo
{
	BOOL	bIsSystemUser;
	UINT	nMenuID;			///对应菜单项的ID号
	WCHAR	szUserName[_MAX_PATH];
	WCHAR	szReferenceName[_MAX_PATH];	///
	WCHAR	szProfileImgPath[_MAX_PATH];	///
}ACCOUNTINFO, *PACCOUNTINFO;

#ifdef DBG
class CAccountInfoMap : public map<UINT, PACCOUNTINFO>
{
public:
	CAccountInfoMap() {}
};
#else
typedef map<UINT, PACCOUNTINFO> CAccountInfoMap;
#endif 

typedef vector<PACCOUNTINFO> CAccountInfoArray;

//////////////////////////////////////////////////////////////////////////
///
typedef struct tagKeyName
{
	_bstr_t bstrText1;
	DWORD	dwValue;
	_bstr_t	bstrText2;
}KEYNAME,*PKEYNAME,*LPKEYNAME;

typedef map<LPCWSTR, tagKeyName> CKeyNameMap;;

//////////////////////////////////////////////////////////////////////////
typedef struct tagStreamThreadInfo
{
	WCHAR*  pszServer;
	LONG	nRefCount;
	HRESULT hresult;
	HANDLE  hEvent1;

	HANDLE	hEvent2;
	HANDLE  hEventLoadFailed;
	HANDLE  hThread;
	LPSTREAM pStream;

	BOOL	bRelease;

}STREAMTHREADINFO, *PSTREAMTHREADINFO;


//////////////////////////////////////////////////////////////////////////
typedef struct tagMsgItem
{
	WCHAR*	szText;
	UINT	nID;
}MSGITEM, *PMSGITEM, *LPMSGITEM;

//////////////////////////////////////////////////////////////////////////
///用在PropProcThreads中的每个线程信息
/// 
typedef struct tagThreadItemInProcThreads
{
	tagThreadItemInProcThreads*	m_Next;
	bool			m_bValue0;

	HANDLE			m_hEvent2;
	HANDLE			m_hEvent3;
	HANDLE			m_hThread;
	HANDLE			m_hEvent;
	bool			m_bValue1;

	LONG			m_nRefCount;
	LPARAM			m_Param;	///指向对应ListCtrl的每个Item的.lParam参数
	HWND			m_hWndList;
	RTL_PROCESS_MODULES* m_SystemModules;
	HANDLE			m_hProcess;

	PRTL_DEBUG_BUFFER	m_DebugBuffer;
	bool			m_bValue2;
	FILETIME		m_TimeLast;
	ULONGLONG		m_CycleTimeLast;
	bool			m_bSymInited;

	DWORD			m_dwValue4C;

}THREADITEMINPROCTHREADS, *PTHREADITEMINPROCTHREADS, *LPTHREADITEMINPROCTHREADS;

typedef struct tagSYSTEMHANDLEINFO
{
	union
	{
		SYSTEM_HANDLE_INFORMATION* pInfoV1;
		SYSTEM_HANDLE_INFORMATION_EX* pInfoV2;
	};
}SYSTEMHANDLEINFO, *PSYSTEMHANDLEINFO, *LPSYSTEMHANDLEINFO;

typedef struct _EVENT_TRACE_PROPERTIES_EX
{
	_EVENT_TRACE_PROPERTIES baseclass;
	WCHAR		szSessionName[_MAX_PATH];
	WCHAR		szLogFileName[_MAX_PATH];
	DWORD 		dwValue488[10];
	TRACEHANDLE SessionHandle;
	bool		ApiLoaded;

	HANDLE		EventHandle;
	HANDLE		ThreadHandle;
	DWORD		dwValue4C4;
	TRACEHANDLE TraceHandle;
	bool		fTraceStarted;

	_EVENT_TRACE_PROPERTIES_EX()
	{
		ZeroMemory(this, sizeof(*this));
		EventHandle = CreateEvent(NULL, FALSE, FALSE, NULL);
	}
}EVENT_TRACE_PROPERTIES_EX, *PEVENT_TRACE_PROPERTIES_EX, *LPEVENT_TRACE_PROPERTIES_EX;

class PerformanceInfo
{
public:
	PerformanceInfo(BOOL flags = FALSE);
	~PerformanceInfo();
	int FindPerf(LPCWSTR lpszName);
public:
	DWORD m_dwLastCounterOfLastHelp;
	WCHAR** m_LastCounterOfLastHelp;
	WCHAR* m_PerfValue;
};
class PerformanceInfoInMemory
{
public:
	PerformanceInfoInMemory(PerformanceInfo* pInfo)
		:m_PerfInfo(pInfo)
		, m_Buffer(NULL)
	{

	}

	BOOL FindPerf(LPCWSTR lpszName, WCHAR* pszBuffer, int nLength);
	BOOL Load(LPCWSTR lpszRootName, LPCTSTR lpszName);
	void SetPerfInfo(PerformanceInfo* pInfo)
	{
		m_PerfInfo = pInfo;
		m_Buffer = NULL;
	}
public:
	PerformanceInfo* m_PerfInfo;
	PVOID m_Buffer;
};

class PE_PerfInfo
{
public:
	PE_PerfInfo(PerformanceInfoInMemory* p, PerformanceInfo* pInfo)
		:m_PerfInfoInMemory(p)
		, m_PerfInfo(pInfo)
	{

	}

	void SetInfo(PerformanceInfoInMemory* p, PerformanceInfo* pInfo)
	{
		m_PerfInfoInMemory = p;
		m_PerfInfo = pInfo;
	}
	bool Load(LPCWSTR lpszName);

public:
	PerformanceInfoInMemory* m_PerfInfoInMemory;
	PerformanceInfo* m_PerfInfo;
};

typedef struct PE_Time
{
	FILETIME		FileTime;
	LARGE_INTEGER	Performance;
	LARGE_INTEGER	Frequency;

	PE_Time()
	{
		GetSystemTimeAsFileTime(&FileTime);
		QueryPerformanceCounter(&Performance);
		QueryPerformanceFrequency(&Frequency);
	}

	unsigned __int64 ComputeTime(__int64 time)
	{
		if (time < 0)
			return ComputeTime(-time);
		return 0;
		/*return time % ((*__int64*)&this->Frequency);*/
		//return (10000000i64*(time % ((*unsigned __int64*)&this->Frequency))) / ((*unsigned __int64*)&this->Frequency)
		//	+ (10000000i64*(time / ((*unsigned __int64*)&this->Frequency)));
	}
}PE_TIME, *PPE_TIME, *LPPE_TIME;
typedef struct tagBitmapItem
{
	HBITMAP hBitmapHandle;
	int		nHeight;
	int		nWidth;
	HDC		hCompatibleDC;
	void*	pBits;
}BITMAPITEM, *PBITMAPITEM, *LPBITMAPITEM;

typedef struct SystemDirInfo
{
	WCHAR szBuffer[_MAX_PATH];
	CLock Lock;
	WCHAR szPathName[_MAX_PATH];
}SYSTEMDIRINFO, *PSYSTEMDIRINFO;


struct tagEventItem;
typedef list<tagEventItem*> CEventItemList;

//////////////////////////////////////////////////////////////////////////
typedef struct tagEventItem
{
	_bstr_t		strEventTrace;
	DWORD		dwValue_04;
	GUID		guid;
	CEventItemList	ItemList;
	_bstr_t		strHeader;
	WORD		Type;
	WORD		Version;
	BYTE		Level;
	tagEventItem()
	{

	}

	tagEventItem(GUID* pIID, WORD aType, WORD bVersion, BYTE cLevel)
	{
		CopyMemory(&guid, pIID, sizeof(GUID));
		this->Type = aType;
		this->Version = bVersion;
		this->Level = cLevel;
	}
	void SetEventTraceText(LPCWSTR lpszText)
	{
		strEventTrace = lpszText;
	}
	void SetHeaderText(LPCWSTR lpszText)
	{
		strHeader = lpszText;
	}
}EVENTITEM, *PEVENTITEM, *LPEVENTITEM;



//////////////////////////////////////////////////////////////////////////
///
struct tagWbemServicesList
{
	IWbemServices*		pWbemSevices;	///
	CEventItemList		EventItemList;	///
};


//////////////////////////////////////////////////////////////////////////
extern CONFIGITEM			gConfigItems[];
extern SYSTEM_INFO			gSystemInfo;
extern HINSTANCE			ghInstance;
extern DWORD				gdwVersion;
extern WCHAR				gszMainClassName[];
extern WCHAR				gszMainWindowName[];
extern WCHAR*				gszCmdLine;
extern int					gnNumArgs;
extern WCHAR				gszStringToSearch[];
extern WCHAR				gszStringSearchLast[];
extern HINSTANCE			ghMainInstance;
extern HWND					ghFindDlg;
extern HWND					ghWndThreadStack;
extern HWND					ghListResultFound;
extern HWND					ghMainWnd;
extern DWORD				gdwTopLastTreeList;
extern HWND					ghSysinfoPropSheetDlg;
extern HWND					ghWndDllsListCtrl;
extern HWND					ghWndHandlesListCtrl;
extern HWND					ghWndTreeListView;
extern HWND					ghWndReBar;
extern HWND					ghWndToolbar;
extern HWND					ghWndCPUGraph;
extern HWND					ghWndMemoryGraph;
extern HWND					ghWndPhysicalMemoryGraph;
extern HWND					ghWndGPUGraph;
extern HWND					ghWndIOGraph;
extern HWND					ghWndNetworkGraph;
extern HWND					ghWndDiskGraph;
extern HWND					ghWndStatusBar;
extern DWORD				gwStatusBarCount;
extern bool					gbFindHandleOrDll;
extern CGraphData*			gpGraphData;
extern tagGraphInfo			gIOGraphInfo;
extern tagGraphInfo			gNetworkGraphInfo;
extern tagGraphInfo			gDiskGraphInfo;
extern HICON				ghStockIcon;
typedef list<LUID>			CAdapterList;
extern CAdapterList			gAdapterList;
extern ULONG				gdwGraphCount;
extern DWORD				gdwVirtualScreenWidth;
extern WCHAR				gszLocaleInfo[];
extern tagProcessComment*	gpProcessComments;
extern WCHAR**				gpHiddenProcesses;
extern bool					gbWintrustInited;
extern UINT					gShellIconMsg;
extern tagLogPixelSize		gLogPixelSize;
extern LONG					gnCounter;
extern HCURSOR				ghCursorArrow;
extern HCURSOR				ghCursorFind;
extern HCURSOR				ghSplitterCursor;
extern HCURSOR				ghResizeCursor;
extern CAccountInfoMap		gAccoutInfoMap;
extern tagStreamThreadInfo* gpStreamThreadInfo;
extern DWORD				gdwTimeout;
extern WCHAR*				gpszTargetName;
extern tagMsgItem			gEventNameItem[];
extern tagMsgItem			gEventCmdItem[];
extern HWND					ghWndComboBoxInRunDlg;
extern WCHAR				gszCommandLine[];
extern WCHAR				gszDbgHelpModuleName[];
extern int					gcyScreen;
extern int					gcxScreen;
extern int					gcxFullScreen;
extern int					gcyFullScreen;
extern BOOL					gbProcessDEPEnabled;
extern HFONT				ghConfigFont;
extern HFONT				ghConfigUnderlineFont;
extern HFONT				ghDefaultUnderlineFontHandle;
extern UINT					gdwComdlg_FindReplaceMessageID;
extern DWORD				gdwMenuItemPosLast;
extern HMENU				ghPriorityPopupMenuHandle;
extern DWORD				gdwMenuItemCountAppendedInRuntime;
extern HMENU				ghUserPopupMenuHandle;
extern WCHAR				gszMainTitle[];
extern COLORREF				gColorCustomized[];
extern WCHAR*				gpszAuthInfo;
extern DWORD				gdwLogicalProcessorInfoItemCount;
extern CGraphData**			gppGraphInfo;
extern HMENU				ghDllsMenuPopup;
extern HMENU				ghHandlesMenuPopup;
extern bool					gbLaunchDepends;
extern WCHAR				gszApplicationName[];
extern WCHAR				gszAeDebuggerPath[];
extern int					gnToolbarHeight;
extern HANDLE				ghSystemInfoSheetThreadEvent;
extern RECT					gRectWindow;
extern RECT					gRectPane;
extern HANDLE				ghRefreshEventHandle;
extern HANDLE				ghEvent2;
extern HANDLE				ghExitEventHandle;
extern HANDLE				ghTimerRefreshEvent;
extern HANDLE				ghTimerRefreshProcPageEventHandle;
extern HANDLE				ghEvent6;
extern HANDLE				ghBackupRefreshThreadHandle;
extern DWORD				gdwAdapterRuntingTime;
extern DWORD				gdwProcessIdSelected;
extern PSYSTEMHANDLEINFO	gpSystemHandleInfo;
extern PSYSTEMHANDLEINFO	gpSystemHandleInfo2;
extern PSYSTEMHANDLEINFO	gpSystemHandleInfo3;
extern DWORD				gdwSystemHandleInfoLength;
extern bool					gbSupportExtendedSystemHandleInformation;
extern bool					gbProcessIdToSessionIdValid;
extern SC_HANDLE			ghSCManagerHandle;
extern bool					gbWindowFinding;
extern HCURSOR				ghFindCursor;
extern HWND					ghWndHungWindow;
extern HKEY					ghLocalMachineKey;
extern HKEY					ghCurrentUserKey;
extern bool					gbRestorePrivilegeFailed;
extern HANDLE				ghAppToken;

extern PSYSTEM_LOGICAL_PROCESSOR_INFORMATION			gpSystemLogicalProcessorInfo;

extern _SYSTEM_PROCESS_INFORMATION*						gpSystemProcessInfo;
extern ULONG											gnSystemProcessInfoLength;
extern _SYSTEM_PROCESSOR_PERFORMANCE_INFORMATION*		gpSystemPerformanceInfo;
extern _SYSTEM_INTERRUPT_INFORMATION*					gpSystemInterruptInfo;
extern _SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION*	gpSystemProcessorCycleTimeInfo;
extern PSYSTEM_PROCESS_INFORMATION						gpSystemProcessInfoLast;
extern ULONG											gnSystemProcessInfoLengthLast;
extern FILETIME											gTimeQuerySystemInfo;
extern FILETIME											gTimeQuerySystemInfoLast;

extern PerformanceInfo									gPerformanceInfo;
extern PerformanceInfoInMemory							gPerformanceInfoInMemory;
extern bool												gNetClrMemoryPerfInfoLoaded;
extern FILETIME											gLoadNetClrMemoryPerfInfoTime, 
														gLoadNetClrMemoryPerfInfoTimeLast;
extern WCHAR*											gszNullString;
extern EVENT_TRACE_PROPERTIES_EX						gProperties;
extern PE_TIME											gTime;
extern CLock											gServiceLock;
extern WCHAR*											gpszServiceNames;
extern DWORD											gdwServiceNamesLength;
extern DWORD											gdwServiceReturned;
extern CLock											gBackendThreadLock;
extern SystemDirInfo									gSystemDirInfo;
extern WCHAR											gszWindowsDirectory[];
extern WCHAR											gszProgramW6432EnvValue[];
extern WCHAR											gszProgameFilesX86EnvValueValue[];
extern DWORD											gdwTlsIndex;
extern WCHAR*											gpszSystemPathInfo;
extern tagWbemServicesList								gWbemServiceList;

extern CAccountInfoArray								garrAccountInfo;
extern tagAccountInfo*									gpAccountInfo;
extern CKeyNameMap										gKeyNameMap;

EXTERN_DEFINE(LockWorkStation);
EXTERN_DEFINE(SetSuspendState);
EXTERN_DEFINE(AllocateAndGetUdpExTable2FromStack);
EXTERN_DEFINE(AllocateAndGetTcpExTable2FromStack);
EXTERN_DEFINE(ImageNtHeader);
EXTERN_DEFINE(NtOpenSymbolicLinkObject);
EXTERN_DEFINE(NtQuerySymbolicLinkObject);
EXTERN_DEFINE(NtQueryInformationProcess);


extern LPFN_CreateRestrictedToken gpfnCreateRestrictedToken;
extern LPFN_WinVerifyTrust  gpfnWinVerifyTrust;
extern LPFN_WTHelperGetProvSignerFromChain  gpfnWTHelperGetProvSignerFromChain;
extern LPFN_WTHelperProvDataFromStateData  gpfnWTHelperProvDataFromStateData;
extern LPFN_CryptCATAdminReleaseContext  gpfnCryptCATAdminReleaseContext;
extern LPFN_CryptCATAdminReleaseCatalogContext  gpfnCryptCATAdminReleaseCatalogContext;
extern LPFN_CryptCATCatalogInfoFromContext  gpfnCryptCATCatalogInfoFromContext;
extern LPFN_CryptCATAdminEnumCatalogFromHash  gpfnCryptCATAdminEnumCatalogFromHash;
extern LPFN_CryptCATAdminCalcHashFromFileHandle  gpfnCryptCATAdminCalcHashFromFileHandle;
extern LPFN_CryptCATAdminAcquireContext  gpfnCryptCATAdminAcquireContext;
extern LPFN_CertNameToStrW  gpfnCertNameToStrW;
extern LPFN_CryptCATAdminAddCatalog  gpfnCryptCATAdminAddCatalog;
extern LPFN_CryptCATAdminRemoveCatalog  gpfnCryptCATAdminRemoveCatalog;
extern LPFN_IsCatalogFile  gpfnIsCatalogFile;
extern LPFN_NtQueryInformationProcess gpfnNtQueryInformationProcess;
extern LPFN_NtQueryInformationThread gpfnNtQueryInformationThread;
extern LPFN_NtQuerySystemInformation gpfnNtQuerySystemInformation;
extern LPFN_SHAutoComplete gpfnSHAutoComplete;
extern LPFN_GetVersion gpfnGetVersion;
extern LPFN_RunFileDlg gpfnRunFileDlg;
extern LPFN_RtlInitUnicodeString gpfnRtlInitUnicodeString;
extern LPFN_RtlNtStatusToDosError gpfnRtlNtStatusToDosError;
extern LPFN_I_QueryTagInformation gpfn_I_QueryTagInformation;
extern LPFN_EnableTraceEx gpfn_EnableTraceEx;
extern LPFN_ZwOpenKey gpfn_NtOpenKey;
extern LPFN_ZwCreateKey gpfn_NtCreateKey;




//////////////////////////////////////////////////////////////////////////
extern void ErrorReport(DWORD dwError);
extern void ReportMsg(LPCTSTR lpszMsg, HWND hWnd);
extern BOOL LoadConfigItemFromRegistry(PREGKEYINFO RegKeyInfo, PCONFIGITEM ConfigItem);
extern BOOL SaveConfigItemToRegistry(PREGKEYINFO RegKeyInfo, PCONFIGITEM ConfigItem);
extern void GraphInfo_Refresh(tagGraphInfo* pGrahInfo);
extern BOOL FakeIsWow64Process(VOID);
extern DWORD WINAPI LoadSharedMemory(VOID* p);
extern BOOL SaveDriverFromResource(LPCWSTR lpszResID, LPCWSTR lpszFileName);
extern BOOL LaunchProcExplorer64(BOOL fDeleteFile, int nCmdShow);
extern BOOL ParseArguments(LPCWSTR lpszTitle, int* pnArg, WCHAR* pszArguments);
extern BOOL InitMainWnd(HINSTANCE hInst, int nCmdShow);
extern BOOL TmAdjustPrivilege(LPCTSTR lpszName);
extern BOOL TrayIcon_Add(HWND hWnd, UINT nID, CGraphData* pGraphData, LPCWSTR lpszTipText);
extern BOOL TrayIcon_Delete(HWND hWnd, UINT nID);
extern INT_PTR CALLBACK DlgPropSheet(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam);
extern BOOL InitAdapterList(__int64* pMinSegments, __int64* pNbSegments);
extern WCHAR* ProcessComment_Find(LPCWSTR lpszName);
extern bool LoadWintrust();
extern BOOL HandleTaskbarCreated();
extern INT_PTR CALLBACK PropPageProcCclr(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
extern HIMAGELIST InitSortableImageList();
extern WNDPROC gOldListWndProc;
extern LRESULT CALLBACK Proxy_ListCtrlWndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
extern HWND CreateListCtrl(HWND hWndParent, DWORD dwStyle, USHORT* pnWidths, int* pnIDs, ULONG ColumnCount, UINT nCtrlID);
extern BOOL InitListCtrl(HWND hWndList, USHORT* pnWidths, int* pnIDs, ULONG ColumnCount);
__forceinline void StreamThreadInfo_Init(tagStreamThreadInfo* pInfo)
{
	ZeroMemory(pInfo, sizeof(tagStreamThreadInfo));
	InterlockedIncrement(&pInfo->nRefCount);
}
__forceinline void StreamThreadInfo_SetServerName(tagStreamThreadInfo* pInfo, WCHAR* lpszServerName)
{
	pInfo->pszServer = lpszServerName;
}
__forceinline void StreamThreadInfo_AddRef(tagStreamThreadInfo* pInfo)
{
	InterlockedIncrement(&pInfo->nRefCount);
}
__forceinline void StreamThreadInfo_Release(tagStreamThreadInfo* pInfo)
{
	if (!InterlockedDecrement(&pInfo->nRefCount))
	{
		if (pInfo->hEvent1)
		{
			CloseHandle(pInfo->hEvent1);
			pInfo->hEvent1 = NULL;
		}
		if (pInfo->hEvent2)
		{
			CloseHandle(pInfo->hEvent2);
			pInfo->hEvent2 = NULL;
		}
		if (pInfo->hEventLoadFailed)
		{
			CloseHandle(pInfo->hEventLoadFailed);
			pInfo->hEventLoadFailed = NULL;
		}
		if (pInfo->hThread)
		{
			CloseHandle(pInfo->hThread);
			pInfo->hThread = NULL;
		}
		if (pInfo->pStream)
		{
			pInfo->pStream->Release();
			CloseHandle(pInfo->hEvent1);
		}
		delete pInfo;
	}
}
extern HRESULT StreamThreadInfo_Load(tagStreamThreadInfo* pInfo, IWbemServices** ppv);
extern HRESULT LoadWbemServices(LPCWSTR lpszServerName, IWbemServices** ppv);
extern WCHAR* GetClassObjectName(IWbemClassObject* pClassObject, LPCWSTR lpszName);
extern BOOL IsBuiltinAndAdministrative();
//////////////////////////////////////////////////////////////////////////
///检测当前系统是否支持PAE(Physical Address Extension)
__forceinline BOOL IsPAEEnabled()
{
	LPFN_IsProcessorFeaturePresent pfnIsProcessorFeaturePresent
		= (LPFN_IsProcessorFeaturePresent)GetProcAddress(GetModuleHandleW(L"Kernel32.dll"), "IsProcessorFeaturePresent");
	return pfnIsProcessorFeaturePresent(PF_PAE_ENABLED);
}
extern BOOL DoRun(HWND hWndParent, WORD wID);
extern INT_PTR CALLBACK DlgRun(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
__forceinline DWORD SetStyle(HWND hWnd, DWORD dwStyle)
{
	DWORD dwOldStyle = GetWindowLongPtr(hWnd, GWL_STYLE);
	SetWindowLongPtr(hWnd, GWL_STYLE, dwOldStyle | dwStyle);
	return dwOldStyle;
}

__forceinline DWORD SetStyleEx(HWND hWnd, DWORD dwStyle)
{
	DWORD dwOldStyle = GetWindowLongPtr(hWnd, GWL_EXSTYLE);
	SetWindowLongPtr(hWnd, GWL_EXSTYLE, dwOldStyle | dwStyle);
	return dwOldStyle;
}

__forceinline void CB_SetLimitText(HWND hWndCB,int nLength)
{
	SendMessage(hWndCB, CB_LIMITTEXT, nLength, 0);
}

__forceinline void CB_SetCurSel(HWND hWndCB)
{
	SendMessage(hWndCB, CB_SETCURSEL, 0, 0);
}

__forceinline void CB_SetEditSel(HWND hWndCB)
{
	SendMessage(hWndCB, CB_SETEDITSEL, 0, 0);
}

__forceinline void CBX_InsertText(HWND hWndCBX, LPCTSTR lpszText)
{
	COMBOBOXEXITEM Item = { 0 };
	Item.iItem = -1;
	Item.mask = CBEIF_TEXT;
	Item.pszText = (TCHAR*)lpszText;
	SendMessage(hWndCBX, CBEM_INSERTITEM, 0, (LPARAM)&Item);
}

extern BOOL LoadDbgHelp(LPCWSTR lpszPathName);
extern HANDLE GetUserToken(IN HANDLE TokenHandle);
extern void SaveCmdLineToMRUList(LPCWSTR lpszCmdLine);
extern BOOL IsServer(LPCWSTR lpszServer);
extern BOOL IsWinServer();
extern int GetDriverNameAndLinkInfo();
extern bool LoadSystemApis();
extern ULONG QuerySystemHandleInfo(BOOL Flags);
extern BOOL QueryCurrentAuthorityInfo(wchar_t **ppUserInfo);
extern BOOL DrawHungWindow(HWND hWnd);
extern int SearchWindow(HWND hWnd);
extern BOOL IsBuiltinAdministrative();
extern BOOL CanReplaceTaskManager();
extern void ReplaceTaskManager(HWND hWnd,BOOL fEnabled);
extern BOOL IsProcessExplorerRunAtStartup();
extern void Command_SetTopmost(HWND hWnd);
extern void SubmitExeToVirusTotalDotCom();
extern bool QueryProcessUsers(HANDLE ProcessHandle, unsigned int ProcessId, __int64 *pValueInput, WCHAR* pszUserName, DWORD cbName, WCHAR *pszDomainName, DWORD cbDomain, WCHAR* pszText3, DWORD cbSize3, WCHAR *pszText4, PULONG pnLength);
extern PSYSTEM_LOGICAL_PROCESSOR_INFORMATION Fake_GetLogicalProcessorInformation(PDWORD pdwCount);
extern BOOL MakeApplicationName(LPCWSTR lpszFName, LPCWSTR lpszPathName, DWORD dwSize, WCHAR* szFullName);
extern void LoadNetClrMemoryPerformanceInfo();
extern ULONG QueryTagInformation(PVOID* ppv, PDWORD pdwValue2, PDWORD pdwValue3, PDWORD pdwValue4);
extern HRESULT PropSheet_UpdateTab(HWND hWnd);
extern DWORD LoadSystemModulesSymbolAddress(LPCSTR lpszName);
__forceinline ULONG PE_FlushTrace(LPEVENT_TRACE_PROPERTIES_EX Properties)
{
	return FlushTrace(Properties->TraceHandle, NULL, (_EVENT_TRACE_PROPERTIES*)Properties);
}
extern ULONG PE_RunTrace(LPEVENT_TRACE_PROPERTIES_EX Properties, bool fStart);
extern BOOL BitmapItem_Create(LPBITMAPITEM pItem, int nWidth, int nHeight);
extern BOOL BitmapItem_SetRectColor(LPBITMAPITEM pItem, RECT* lprc, COLORREF color);
extern void QueryServiceNames();
extern HWND QueryTopMostWindowByProcessID(DWORD dwProcessId);
extern HRESULT PE_ShellExecute(LPCWSTR lpszFile, LPCWSTR lpszParameters, LPCWSTR lpszDir);
extern HRESULT QueryNetCclrProcessFlags(DWORD dwProcessId, PDWORD pdwFlags);
extern BOOL PE_SetWindowPlacement(HWND hWnd, POINT pt);
extern BOOL InitSystemPath();
extern DWORD WINAPI BackendThreadProc(void *p);


__forceinline void GraphData_QueryData(CGraphData* pGraphData, double* pArg1, double* pArg2)
{
	pGraphData->m_Lock.Lock();
	int nWidth = pGraphData->m_nWidth - 1;
	if (nWidth < 0)
		nWidth = gdwVirtualScreenWidth - 1;
	*pArg1 = pGraphData->m_Item[0].pBuffer[nWidth];
	if(pArg2&&pGraphData->m_nChildID>1)
		*pArg2 = pGraphData->m_Item[1].pBuffer[nWidth];
	pGraphData->m_Lock.Unlock();
}




