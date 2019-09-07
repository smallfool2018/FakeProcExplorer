#ifndef __REGSETTINGS_H__
#define __REGSETTINGS_H__

#pragma once
enum ERegSettingsConst
{
	Max_WindowPlacement = 6,
	MAX_NumColumnsets = 10,
	MAX_ToolBandInfo = 10,
	MAX_ProcessColumnCount = 96,
	MAX_HandleColumnCount = 32,
	MAX_DllColumnCount = 32,
};
//////////////////////////////////////////////////////////////////////////
//
//
//////////////////////////////////////////////////////////////////////////
struct CRegVar
{
	WCHAR ColumnSetName[_MAX_PATH];
	WORD ProcessImageColumnWidth;
	WORD ShowProcessTree;
	LONG PrcessColumnCount;
	SHORT ProcessColumns[MAX_ProcessColumnCount];
	LONG ProcessColumnMap[MAX_ProcessColumnCount];
	LONG ProcessSortColumn;
	LONG ProcessSortDirection;
	LONG StatusBarColumns;
	LONG HandleColumnCount;
	WORD HandleColumns[MAX_HandleColumnCount];
	LONG DllColumnMap[MAX_HandleColumnCount];
	LONG DllSortColumn;
	LONG DllSortDirection;
	LONG DllColumnCount;
	WORD DllColumns[MAX_DllColumnCount];
	LONG HandleColumnMap[MAX_DllColumnCount];
	LONG HandleSortColumn;
	LONG HandleSortDirection;
};

extern void RegVar_ReadWrite(BOOL fSave, DWORD dwCount, CRegVar* pVariable);

typedef struct tagToolBandInfo
{
	int nWidth;
	UINT nID;
	bool fBreak;
}TOOLBANDINFO,*PTOOLBANDINFO,*LPTOOLBANDINFO;

//////////////////////////////////////////////////////////////////////////
//	CRegSettings
//
//
//	47E4=18404
//////////////////////////////////////////////////////////////////////////
class CRegSettings
{
public:

	WINDOWPLACEMENT WindowPlacement[Max_WindowPlacement];
	LOGFONTW UnicodeFont;
	double dbDivider;		//0.5
	double dbSavedDivider;	//0.5	
	DWORD dwRefreshRate;
	DWORD dwHighlightDuration;

	//////////////////////////////////////////////////////////////////////////
	///CurrentRegVar
	/// CRegVar
	union
	{
		struct
		{
			WCHAR szColumnSetName[_MAX_PATH];
			WORD wProcessImageColumnWidth[2];
			////WORD bShowProcessTree;
			DWORD dwProcessColumnCount;
			SHORT dwProcessColumns[MAX_ProcessColumnCount];
			int dwProcessColumnMap[MAX_ProcessColumnCount];
			DWORD dwProcessSortColumn;
			bool bProcessSortDirection;
			BYTE byReserved2[3];
			DWORD dwStatusBarColumns;
			DWORD dwHandleColumnCount;
			WORD dwHandleColumns[MAX_HandleColumnCount];	//byHandleColumns[64];
			DWORD dwDllColumnMap[MAX_HandleColumnCount];	//wDllColumnMap[64];
			DWORD dwDllSortColumn;
			DWORD bDllSortDirection;
			DWORD dwDllColumnCount;
			WORD dwDllColumns[MAX_DllColumnCount];
			DWORD dwIdsOfHandleColumnMap[MAX_DllColumnCount];
			DWORD dwHandleSortColumn;
			DWORD bHandleSortDirection;
		};
		CRegVar CurrentColumnSet;
	};

	///End CRegVar

	DWORD dwNumColumnsets;
	CRegVar strMenuCulumnSet[MAX_NumColumnsets];
	bool bHighlightJobs;
	bool bHighlightServices;
	bool bHighlightOwnProcesses;
	bool bHighliteNetProcess;
	bool bHighlightNewProc;
	bool bHighlightDelProc;
	bool bHighlightPacked;
	bool bHighlightImmersive;
	bool bHighlightSuspend;
	bool bHighlightProtected;
	bool bTrayCPUHistory;
	bool bShowCommitTray;
	bool bShowPhysTray;
	bool bShowIoTray;
	bool bShowNetTray;
	bool bShowDiskTray;
	bool bShowGpuHistory;
	bool bShowCpuFractions;
	bool bShowUnnamedHandles;
	bool byReserved_00;
	bool bShowDllView;
	bool bShowLowerPane;
	bool bHighlightRelocatedDlls;
	bool bShowColumnHeatmaps;
	bool bShowAllUsers;
	bool bHideWhenMinimized;
	bool bAlwaysOntop;
	bool bAllOneInstance;
	bool bConfirmKill;
	bool bFormatIoBytes;
	bool byte_14012ADFE;
	bool bVerifySignatures;
	bool bShowAllCpus;
	bool bShowAllGpus;
	bool bUseGoogle;
	bool bShowNewProcesses;
	DWORD dwGpuNodeUsageMask;
	bool bAllOneInstance2;
	bool bVirusTotalSubmitUnknown;
	bool bETWStandardUserWarning;
	bool byReserved;
	DWORD dwOpacity;
	DWORD dwDefaultProcPropPage;
	DWORD dwDefaultDllPropPage;
	DWORD dwDefaultSysInfoPage;
	WCHAR strDbgHelpModuleName[_MAX_PATH];
	WORD bSymbolWarningShown;
	WCHAR strNtSymbolPath[_MAX_PATH];
	COLORREF ColorOwn;
	COLORREF ColorService;
	COLORREF ColorRelocatedDlls;
	COLORREF ColorJobs;
	COLORREF ColorNet;
	COLORREF ColorNewProc;
	COLORREF ColorDelProc;
	COLORREF ColorPacked;
	COLORREF ColorGraphBk;
	COLORREF ColorImmersive;
	COLORREF ColorSuspend;
	COLORREF ColorProtected;
	TOOLBANDINFO	ToolBandInfo[MAX_ToolBandInfo];
public:
	CRegSettings();
};

extern CRegSettings gConfig;


//////////////////////////////////////////////////////////////////////////

#endif //__REGSETTINGS_H__