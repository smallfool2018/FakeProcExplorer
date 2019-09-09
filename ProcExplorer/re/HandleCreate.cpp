int __cdecl CMainWnd::HandleCreate(HWND hWnd)
{
	HMODULE v1; // eax
	bool v2; // al
	HMENU hMainMenuHandle; // edi
	HCURSOR v4; // eax
	HGDIOBJ v5; // eax
	int dwMenuItemPosLast; // ST20_4
	HMENU hMainMenu; // eax
	HMENU hSubMenuView_1; // eax
	HMENU v9; // eax
	signed int i; // esi
	int nIdIndex; // eax
	int v12; // ST1C_4
	HMENU hMainMenu_1; // eax
	HMENU hSubMenuView; // eax
	HMENU v15; // eax
	HMENU v16; // eax
	HMENU hFileSubMenu; // eax
	HMENU hSubMenuFile; // eax
	HMENU hSubMenuFile_1; // eax
	HMENU(__stdcall *GetMenu)(HWND); // esi
	HMENU hMainMenu_2; // eax
	HMENU hOpacityPopupMenuHandle; // eax
	UINT v23; // eax
	UINT v24; // eax
	MACRO_MF v25; // eax
	UINT v26; // ST28_4
	HMENU v27; // eax
	MACRO_MF v28; // eax
	UINT v29; // ST28_4
	HMENU v30; // eax
	MACRO_MF v31; // eax
	UINT v32; // ST28_4
	HMENU v33; // eax
	MACRO_MF v34; // eax
	UINT v35; // ST28_4
	HMENU v36; // eax
	UINT v37; // eax
	UINT v38; // eax
	UINT v39; // eax
	UINT v40; // eax
	UINT v41; // eax
	UINT v42; // eax
	MACRO_MF v43; // eax
	UINT v44; // ST28_4
	HMENU v45; // eax
	float v46; // xmm0_4
	double v47; // xmm0_8
	float v48; // xmm0_4
	double v49; // xmm0_8
	UINT v50; // ST28_4
	HMENU v51; // eax
	UINT v52; // ST28_4
	HMENU v53; // eax
	UINT v54; // eax
	DWORD dwProcessId; // ST04_4
	HANDLE hProcessHandle; // eax
	const WCHAR **psz_1; // eax
	unsigned int nLength; // kr00_4
	HMENU hProcessMenu; // eax
	int NumberOfProcessors; // eax
	int index; // esi
	CGraphData *v62; // ecx
	CGraphData *v63; // edx
	HMODULE v64; // eax
	HMODULE v65; // eax
	HMODULE v66; // eax
	HMODULE v67; // eax
	HMODULE v68; // eax
	HMODULE v69; // eax
	HMENU v70; // eax
	UINT v71; // ecx
	signed int v72; // eax
	UINT v73; // ST28_4
	HMENU v74; // eax
	void(__stdcall *RegCloseKey)(HKEY); // esi
	DWORD dwRet; // eax
	DWORD dwSize; // esi
	int dwSize_1; // ST24_4
	wchar_t *pszPath_1; // esi
	wchar_t *psz; // eax
	HWND hWnd_2; // esi
	HINSTANCE hInst; // ST1C_4
	HWND hWndTreeListView; // eax
	CTreeList *pTreeList; // eax
	CTreeList *pTreeList_1; // esi
	HCURSOR v87; // eax
	HWND v88; // eax
	HWND v89; // eax
	HWND v90; // eax
	int dwProcessColumnCount; // eax
	__int16 wProcessImageColumnWidth; // ax
	int v93; // ST18_4
	int v94; // eax
	HIMAGELIST hImgList; // eax
	CTreeList *pTreeList_2; // esi
	HICON v97; // ST28_4
	struct _IMAGELIST *v98; // eax
	struct _IMAGELIST *v99; // eax
	HWND v100; // esi
	HWND v101; // ecx
	HWND v102; // ecx
	signed int v103; // eax
	UINT v104; // ST28_4
	HMENU v105; // eax
	HMENU v106; // eax
	HMENU v107; // eax
	LPARAM nBmpIndex; // eax
	BOOL v109; // ST28_4
	HMENU v110; // eax
	HMENU v111; // eax
	double v112; // xmm0_8
	signed int v113; // eax
	UINT v114; // ST28_4
	HMENU v115; // eax
	signed int v116; // eax
	UINT v117; // ST28_4
	HMENU v118; // eax
	HWND v119; // ebx
	signed int v120; // eax
	UINT v121; // ST28_4
	HMENU v122; // eax
	HMENU hMenuMain; // eax
	HMENU hMenuMain_1; // eax
	HMODULE v125; // eax
	HMODULE v126; // eax
	int(__stdcall *v127)(HWND, RECT *, DWORD, DWORD); // eax
	signed int dwOpacity; // ecx
	LONG v129; // eax
	UINT uId; // ST24_4
	HMENU v131; // eax
	UINT v132; // [esp-8h] [ebp-CE4h]
	const WCHAR *v133; // [esp-4h] [ebp-CE0h]
	tagLVITEMW lvItem; // [esp+Ch] [ebp-CD0h]
	tagLVITEMW Item; // [esp+40h] [ebp-C9Ch]
	DWORD Type; // [esp+74h] [ebp-C68h]
	__int64 dwNbSegments; // [esp+78h] [ebp-C64h]
	__int64 dwMinSegments; // [esp+80h] [ebp-C5Ch]
	int pSessionInfo; // [esp+88h] [ebp-C54h]
	int nSessionCount; // [esp+8Ch] [ebp-C50h]
	HCURSOR hCursor_____; // [esp+90h] [ebp-C4Ch]
	wchar_t *pszPath; // [esp+94h] [ebp-C48h]
	HKEY hSubKey; // [esp+98h] [ebp-C44h]
	size_t cbData; // [esp+9Ch] [ebp-C40h]
	HWND hWnd_1; // [esp+A0h] [ebp-C3Ch]
	struct WSAData WSAData; // [esp+A4h] [ebp-C38h]
	tagLOGFONTW LogFont; // [esp+234h] [ebp-AA8h]
	RECT rcTreeList; // [esp+290h] [ebp-A4Ch]
	struct tagRECT rcToolbar; // [esp+2A0h] [ebp-A3Ch]
	wchar_t szUserName[260]; // [esp+2B0h] [ebp-A2Ch]
	wchar_t szMenuItemName[260]; // [esp+4B8h] [ebp-824h]
	__int16 szDomainName[260]; // [esp+6C0h] [ebp-61Ch]
	WCHAR szMainName[260]; // [esp+8C8h] [ebp-414h]
	WCHAR szPathName[260]; // [esp+AD0h] [ebp-20Ch]
	int savedregs; // [esp+CDCh] [ebp+0h]

	hWnd_1 = hWnd;
	_mm_storeu_si128(&rcToolbar, 0i64);
	lvItem.mask = 0;
	memset(&lvItem.iItem, 0, 0x30u);
	CoInitialize(0);
	WSAStartup(0x101u, &WSAData);
	GetLocaleInfoW(LOCALE_USER_DEFAULT, 0xEu, &gszLocaleInfo, 16);
	InitializeCriticalSection(&gSysInfoPropSheetLock);
	InitializeCriticalSection(&gLock2);
	InitializeCriticalSection(&gLock3);
	InitializeCriticalSection(&gProcThreadsLock);
	LoadHiddenProcessesFromRegistry();
	LoadProcessCommentsFromRegistry();
	v1 = LoadLibraryW(L"Advapi32.dll");
	gpfnCreateRestrictedToken = GetProcAddress(v1, "CreateRestrictedToken");
	gbWintrustInited = LoadWintrust();
	v2 = GetProcessDEPStatus();
	ghMainWnd = hWnd;
	gbIsProcessDEPEnabled = v2;
	hMainMenuHandle = ::GetMenu(hWnd);
	v4 = LoadCursorW(0, IDC_WAIT);
	hCursor_____ = SetCursor(v4);
	ghArrowCursor = LoadCursorW(0, IDC_ARROW);
	ghFindCursor = LoadCursorW(ghInstance, 10);
	EnableMenuItem(hMainMenuHandle, IDM_VIEW_SHOW_HIDDEN_PROCESSES, *gpHiddenProcesses == 0);
	v5 = GetStockObject(DEFAULT_GUI_FONT);
	GetObjectW(v5, sizeof(LOGFONTW), &LogFont);
	LogFont.lfUnderline = 1;
	ghDefaultUnderlineFontHandle = CreateFontIndirectW(&LogFont);
	gdwComdlg_FindReplaceMessageID = RegisterWindowMessageW(L"commdlg_FindReplace");
	DeleteMenu(hMainMenuHandle, IDM_VIEW_LOADCOLUMNSET_TEST, 0);
	dwMenuItemPosLast = gdwMenuItemPosLast;
	hMainMenu = ::GetMenu(ghMainWnd);
	hSubMenuView_1 = GetSubMenu(hMainMenu, 2);
	v9 = GetSubMenu(hSubMenuView_1, dwMenuItemPosLast);
	DeleteMenu(v9, 0, MF_BYPOSITION);
	for (i = 0; i < gConfig.dwNumColumnsets; ++i)
	{
		if (i >= 10)
		{
			wcscpy_s(szMenuItemName, MAX_PATH, gConfig.strMenuCulumnSet[i].ColumnSetName);
		}
		else
		{
			if (i == 9)
				nIdIndex = 0;
			else
				nIdIndex = i + 1;
			swprintf(szMenuItemName, L"%s\tCtrl+%i", &gConfig.strMenuCulumnSet[i], nIdIndex);
		}
		v12 = gdwMenuItemPosLast;
		hMainMenu_1 = ::GetMenu(ghMainWnd);
		hSubMenuView = GetSubMenu(hMainMenu_1, 2);
		v15 = GetSubMenu(hSubMenuView, v12);
		AppendMenuW(v15, 0, i + IDM_PROCESS_PRIORITY_BASE, szMenuItemName);
	}
	ghPriorityPopMenuHandle = LoadMenuW(ghInstance, L"PRIORITY");
	if (gpfnCreateRestrictedToken)
	{
		v16 = GetSubMenu(hMainMenuHandle, 0);
		InsertMenuW(v16, 1u, MF_BYPOSITION, IDM_RUN_AS_LIMITED_USER, L"Run as &Limited User...");
		++gdwMenuItemCountAppendedInRuntime;
	}
	if (gdwVersion < 1)
	{
		v133 = L"R&unas...";
		goto LABEL_15;
	}
	if (!IsBuiltinAdministrative())
	{
		v133 = L"R&un as Administrator...";
	LABEL_15:
		hFileSubMenu = GetSubMenu(hMainMenuHandle, 0);
		InsertMenuW(hFileSubMenu, 1u, MF_BYPOSITION, IDM_RUN_AS, v133);
		++gdwMenuItemCountAppendedInRuntime;
	}
	InsertMenuW(hMainMenuHandle, IDM_PRIORITY_NORMAL, 0, IDM_PROCESS_SETPRIORITY_ABOVE_NORMAL_TEN, L"&Above Normal: 10");
	InsertMenuW(
		ghPriorityPopMenuHandle,
		IDM_PROCESS_SETPRIORITY_NORMAL,
		0,
		IDM_PROCESS_SETPRIORITY_ABOVE_NORMAL_TEN,
		L"&Above Normal: 10");
	InsertMenuW(
		hMainMenuHandle,
		IDM_PROCESS_SETPRIORITY_IDLE,
		0,
		IDM_PROCESS_SETPRIORITY_BELOW_NORMAL_SIX,
		L"&Below Normal: 6");
	InsertMenuW(
		ghPriorityPopMenuHandle,
		IDM_PROCESS_SETPRIORITY_IDLE,
		0,
		IDM_PROCESS_SETPRIORITY_BELOW_NORMAL_SIX,
		L"&Below Normal: 6");
	if (gdwVersion < 1
		|| (InsertMenuW(
			hMainMenuHandle,
			IDM_PRIORITY_IDLE,
			0,
			IDM_PROCESS_SETPRIORITY_BACKGROUND_FOUR,
			L"Back&ground: 4 (Low I/O and Memory Priority)"),
			InsertMenuW(
				ghPriorityPopMenuHandle,
				IDM_PRIORITY_IDLE,
				0,
				IDM_PROCESS_SETPRIORITY_BACKGROUND_FOUR,
				L"Back&ground: 4 (Low I/O and Memory Priority)"),
			gdwVersion < 1)
		|| IsBuiltinAdministrative())
	{
		if (ChangeWindowMessageFilter)
			ChangeWindowMessageFilter(WM_MSG_7F2, 1);
		GetMenu = ::GetMenu;
	}
	else
	{
		hSubMenuFile = GetSubMenu(hMainMenuHandle, 0);
		InsertMenuW(hSubMenuFile, 3u, 0xC00u, 0, 0);// 0xC00 = MF_BYPOSITION|MF_SEPARATOR
		++gdwMenuItemCountAppendedInRuntime;
		hSubMenuFile_1 = GetSubMenu(hMainMenuHandle, 0);
		InsertMenuW(
			hSubMenuFile_1,
			4u,
			MF_BYPOSITION,
			IDM_SHOW_DETAILS_FOR_ALL_PROCESSES,
			L"Show &Details for All Processes");
		GetMenu = ::GetMenu;
		hMainMenu_2 = ::GetMenu(hWnd_1);
		ReplaceMenuIconFromStockIcon(hMainMenu_2, IDM_SHOW_DETAILS_FOR_ALL_PROCESSES);
		++gdwMenuItemCountAppendedInRuntime;
	}
	hOpacityPopupMenuHandle = LoadMenuW(ghInstance, L"OPACITY");
	InsertMenuW(hMainMenuHandle, IDM_VIEW_SHOW_LOWER_PANE, MF_POPUP, hOpacityPopupMenuHandle, L"Opacity");
	InsertMenuW(hMainMenuHandle, IDM_VIEW_SHOW_LOWER_PANE, MF_SEPARATOR, 0, 0);
	v23 = 0;
	if (gConfig.bVerifySignatures)
		v23 = MF_CHECKED;
	CheckMenuItem(hMainMenuHandle, IDM_OPTIONS_VERIFY_IMAGE_SIGNATURE, v23);
	v24 = 0;
	if (gConfig.bAllOneInstance2)
		v24 = MF_CHECKED;
	CheckMenuItem(hMainMenuHandle, IDM_OPTIONS_CHECK_VIRTULTOALDOTCOM, v24);
	EnableMenuItem(hMainMenuHandle, IDM_OPTIONS_SUBMIT_UNKNOWN_EXECUTABLES, gConfig.bAllOneInstance2 == 0);
	if (gConfig.bAllOneInstance2)
		SubmitExeToVirusTotalDotCom();
	v25 = 0;
	if (gConfig.bTrayCPUHistory)
		v25 = MF_CHECKED;
	v26 = v25;
	v27 = GetMenu(hWnd_1);
	CheckMenuItem(v27, IDM_OPTIONS_TRAYICON_CPU_HISTORY, v26);
	v28 = 0;
	if (gConfig.bShowIoTray)
		v28 = MF_CHECKED;
	v29 = v28;
	v30 = GetMenu(hWnd_1);
	CheckMenuItem(v30, IDM_OPTIONS_TRAYICON_IO_HISTORY, v29);
	v31 = 0;
	if (gConfig.bShowCommitTray)
		v31 = MF_CHECKED;
	v32 = v31;
	v33 = GetMenu(hWnd_1);
	CheckMenuItem(v33, IDM_OPTIONS_TRAYICON_COMMIT_HISTORY, v32);
	v34 = 0;
	if (gConfig.bShowPhysTray)
		v34 = MF_CHECKED;
	v35 = v34;
	v36 = GetMenu(hWnd_1);
	CheckMenuItem(v36, IDM_OPTIONS_TRAYICON_PHYSICAL_MEMORY_HISTORY, v35);
	v37 = 0;
	if (gConfig.bAllOneInstance)
		v37 = MF_CHECKED;
	CheckMenuItem(hMainMenuHandle, IDM_OPTIONS_ALLOW_ONLY_ONE_INSTANCE, v37);
	v38 = 0;
	if (gConfig.bHideWhenMinimized)
		v38 = MF_CHECKED;
	CheckMenuItem(hMainMenuHandle, IDM_OPTIONS_HIDE_WHEN_MINIMIZED, v38);
	v39 = 0;
	if (gConfig.bShowColumnHeatmaps)
		v39 = MF_CHECKED;
	CheckMenuItem(hMainMenuHandle, IDM_VIEW_SHOW_COLUMN_HEATMAPS, v39);
	gConfig.bAlwaysOntop = gConfig.bAlwaysOntop == 0;
	Command_SetTopmost(ghMainWnd);
	v40 = 0;
	if (gConfig.bShowCpuFractions)
		v40 = MF_CHECKED;
	CheckMenuItem(hMainMenuHandle, IDM_PROCESS_CONFIRM_TO_KILL, v40);
	v41 = 0;
	if (gConfig.bConfirmKill)
		v41 = MF_CHECKED;
	CheckMenuItem(hMainMenuHandle, IDM_OPTIONS_CONFIRM_KILL, v41);
	v42 = 0;
	if (gConfig.bFormatIoBytes)
		v42 = MF_CHECKED;
	CheckMenuItem(hMainMenuHandle, IDM_SHOW_NEW_PROCESS, v42);
	v43 = 0;
	if (gConfig.bShowNewProcesses)
		v43 = MF_CHECKED;
	v44 = v43;
	v45 = GetMenu(hWnd_1);
	CheckMenuItem(v45, IDM_VIEW_SCROLL_TO_NEW_PROCESSES, v44);
	InsertMenuW(
		hMainMenuHandle,
		IDM_VIEW_SHOW_PROCESS_TREE,
		0,
		IDM_TRAYMENU_CONTEXT_SYSTEM_INFORMATION,
		L"System &Information...\tCtrl+I");
	if (Init3DStatistics(&dwMinSegments, &dwNbSegments))
	{
		gpGraphInfoOfGPU = InitGraphData(1, 1, 1);
		gpGraphInfoOfGPU->m_nItemID = 4;
		gpGraphInfoOfGPU->m_Color = 0x8080FF;
		gpGraphInfoOfGPU->m_dbMemorySize = dbl_4CCDC0;
		gpGraphInfoOfSystemMemory = InitGraphData(1, 1, 0);
		gpGraphInfoOfSystemMemory->m_nItemID = 5;
		gpGraphInfoOfSystemMemory->m_Color = 0xAAAA;
		if (dwMinSegments)
		{
			v46 = dwMinSegments;
			v47 = v46;
		}
		else
		{
			v47 = db_one;
		}
		gpGraphInfoOfSystemMemory->m_dbMemorySize = v47;
		gpGraphInfoOfDedicatedMemory = InitGraphData(1, 1, 0);
		gpGraphInfoOfDedicatedMemory->m_nItemID = 6;
		gpGraphInfoOfDedicatedMemory->m_Color = 0x4080FF;
		if (dwNbSegments)
		{
			v48 = dwNbSegments;
			v49 = v48;
		}
		else
		{
			v49 = db_one;
		}
		gpGraphInfoOfDedicatedMemory->m_dbMemorySize = v49;
	}
	InsertMenuW(hMainMenuHandle, IDM_VIEW_SHOW_PROCESS_TREE, MF_SEPARATOR, 0, 0);
	InsertMenuW(
		hMainMenuHandle,
		IDM_OPTIONS_HIDE_WHEN_MINIMIZED,
		0,
		IDM_OPTIONS_REPLACE_TASK_MANAGER,
		L"Replace &Task Manager");
	v50 = CanReplaceTaskManager() != 0 ? MF_CHECKED : 0;
	v51 = GetMenu(hWnd_1);
	CheckMenuItem(v51, IDM_OPTIONS_REPLACE_TASK_MANAGER, v50);
	if (gdwVersion >= 1 && !IsBuiltinAdministrative())
		ReplaceMenuIconFromStockIcon(hMainMenuHandle, IDM_OPTIONS_REPLACE_TASK_MANAGER);
	if (CanReplaceTaskManager())
		ReplaceTaskManager(hWnd_1, 0);
	v52 = IsProcessExplorerRunAtStartup(&savedregs, hMainMenuHandle) != 0 ? MF_CHECKED : 0;
	v53 = GetMenu(hWnd_1);
	CheckMenuItem(v53, IDM_OPTIONS_RUN_AT_LOGON, v52);
	v54 = 0;
	if (gConfig.bShowAllUsers)
		v54 = MF_CHECKED;
	CheckMenuItem(hMainMenuHandle, IDM_VIEW_SHOW_PROCESSES_FROM_ALL_USERS, v54);
	InsertMenuW(
		hMainMenuHandle,
		IDM_OPTIONS_DIFFERENCE_HIGHLIGHT_DURATION,
		0,
		IDM_VIEW_CONFIGURE_SYMBOLS,
		L"Configure &Symbols...");
	DeleteMenu(hMainMenuHandle, IDM_OPTIONS_HIGHLIGHT_RELOCATED_DLLS, 0);
	InsertMenuW(
		hMainMenuHandle,
		IDM_OPTIONS_DIFFERENCE_HIGHLIGHT_DURATION,
		0,
		IDM_VIEW_CONFIGURE_COLORS,
		L"&Configure Colors...");
	if (WTSEnumerateSessionsW
		&& *SetMenuInfo
		&& WTSEnumerateSessionsW(0, 0, 1u, &pSessionInfo, &nSessionCount)
		&& nSessionCount)
	{
		Item.cchTextMax = sizeof(MENUINFO);
		Item.iImage = 0x80000010;
		Item.lParam = MNS_NOTIFYBYPOS;
		SetMenuInfo(hMainMenuHandle, &Item.cchTextMax);
		ghUserPopupMenuHandle = CreateMenu();
		InsertMenuW(hMainMenuHandle, 5u, 0x410u, ghUserPopupMenuHandle, L"&Users");
		WTSFreeMemory(pSessionInfo);
	}
	dwProcessId = GetCurrentProcessId();
	hProcessHandle = GetCurrentProcess();
	QueryProcessUsers(hProcessHandle, dwProcessId, 0, szUserName, MAX_PATH, szDomainName, MAX_PATH, 0, 0, 0, 0);
	if (!szDomainName[0] || (psz_1 = L"\\", !szUserName[0]))
		psz_1 = &gszNullString;
	swprintf(gszMainTitle, L"%s%s%s", szDomainName, psz_1, szUserName);
	GetWindowTextW(ghMainWnd, szMainName, 260);
	nLength = wcslen(szMainName);
	swprintf_s(&szMainName[nLength], 260 - nLength, L" [%s]", gszMainTitle);
	SetWindowTextW(ghMainWnd, szMainName);
	gColorCustomized[0] = gConfig.ColorOwn;
	gColorCustomized[1] = gConfig.ColorService;
	gColorCustomized[2] = gConfig.ColorRelocatedDlls;
	gColorCustomized[3] = gConfig.ColorJobs;
	gColorCustomized[4] = gConfig.ColorNet;
	QueryCurrentAuthorityInfo(&gpszCurAuthInfo);
	if (gSystemInfo.dwNumberOfProcessors > 1)
	{
		hProcessMenu = GetSubMenu(hMainMenuHandle, 3);
		InsertMenuW(hProcessMenu, 2u, MF_BYPOSITION, IDC_PROCESS_SET_AFFINITY, L"Set &Affinity...");
		CheckMenuItem(hMainMenuHandle, (gConfig.bShowAllCpus != 0) + IDM_PROCESSOR_ONE_GRAPH_ALL_CPUS, MF_CHECKED);
		if (*GetLogicalProcessorInformation)
		{
			cbData = 0;
			GetLogicalProcessorInformation(0, &cbData);
			if (GetLastError() == ERROR_INSUFFICIENT_BUFFER)
			{
				gpLogicalProcessorInfo = malloc(cbData);
				GetLogicalProcessorInformation(gpLogicalProcessorInfo, &cbData);
				gdwLogicalProcessorInfoItemCount = cbData / sizeof(SYSTEM_LOGICAL_PROCESSOR_INFORMATION);
			}
		}
		else
		{
			gpLogicalProcessorInfo = Fake_GetLogicalProcessorInformation(&gdwLogicalProcessorInfoItemCount);
		}
		gppGraphInfo = malloc(4 * gSystemInfo.dwNumberOfProcessors);
		NumberOfProcessors = gSystemInfo.dwNumberOfProcessors;
		for (index = 0; index < gSystemInfo.dwNumberOfProcessors; ++index)
		{
			gppGraphInfo[index] = InitGraphData(NumberOfProcessors, 2, 0);
			gppGraphInfo[index]->m_ProcessorID = index;
			sub_453E70(
				gpLogicalProcessorInfo,
				gdwLogicalProcessorInfoItemCount,
				index,
				&gppGraphInfo[index]->field_874,
				&gppGraphInfo[index]->field_870);
			gppGraphInfo[index]->m_nChildID = 2;
			gppGraphInfo[index]->m_nItemID = 0;
			gppGraphInfo[index]->m_Color = 0x3C943C;
			gppGraphInfo[index]->m_dbMemorySize = dbl_4CCDC0;
			gppGraphInfo[index]->m_Item[0].dwValue[5] = 255;
			*&gppGraphInfo[index]->m_Item[0].dwValue[3] = dbl_4CCDC0;
			gppGraphInfo[index]->m_GraphData = gpGraphInfoOfCPU;
			if (index)
			{
				v62 = *gppGraphInfo;
				v63 = gppGraphInfo[index];
				v63->m_Time.dwLowDateTime = (*gppGraphInfo)->m_Time.dwLowDateTime;
				v63->m_Time.dwHighDateTime = v62->m_Time.dwHighDateTime;
			}
			NumberOfProcessors = gSystemInfo.dwNumberOfProcessors;
		}
		GetMenu = ::GetMenu;
	}
	v64 = LoadLibraryW(L"Powrprof.dll");
	*SetSuspendState = GetProcAddress(v64, "SetSuspendState");
	if (*SetSuspendState)
	{
		v65 = LoadLibraryW(L"Powrprof.dll");
		*IsPwrHibernateAllowed = GetProcAddress(v65, "IsPwrHibernateAllowed");
		if (IsPwrHibernateAllowed())
			InsertMenuW(hMainMenuHandle, IDM_FILE_SHUTDOWN_RESTART, MF_BYCOMMAND, IDC_FILE_HIBERNATE, L"&Hibernate");
		v66 = LoadLibraryW(L"Powrprof.dll");
		*IsPwrSuspendAllowed = GetProcAddress(v66, "IsPwrSuspendAllowed");
		if (IsPwrSuspendAllowed())
			InsertMenuW(hMainMenuHandle, IDM_FILE_SHUTDOWN_RESTART, MF_BYCOMMAND, IDC_FILE_STANDBY, L"Stand &By");
	}
	v67 = LoadLibraryW(L"User32.dll");
	*LockWorkStation = GetProcAddress(v67, "LockWorkStation");
	if (*LockWorkStation)
		InsertMenuW(hMainMenuHandle, IDM_FILE_SHUTDOWN_RESTART, MF_BYCOMMAND, IDC_THREADSTACK_BUTTON_COPY, L"Loc&k");
	v68 = LoadLibraryW(L"User32.dll");
	*GetMonitorInfoA = GetProcAddress(v68, "GetMonitorInfoA");
	v69 = LoadLibraryW(L"User32.dll");
	*MonitorFromPoint = GetProcAddress(v69, "MonitorFromPoint");
	v70 = LoadMenuW(ghInstance, L"DLLMENU");
	v71 = 0;
	ghDllMenuPopup = v70;
	if (gConfig.bHighlightRelocatedDlls)
		v71 = 8;
	CheckMenuItem(v70, IDM_OPTIONS_HIGHLIGHT_RELOCATED_DLLS, v71);
	ghHandleMenuPopup = LoadMenuW(ghInstance, L"HANDLEMENU");
	v72 = 0;
	if (gConfig.bShowUnnamedHandles)
		v72 = 8;
	v73 = v72;
	v74 = GetMenu(hWnd_1);
	CheckMenuItem(v74, IDM_VIEW_SHOW_UNNAMED_HANDLES_AND_MAPPINGS, v73);
	RegCloseKey = ::RegCloseKey;
	if (RegOpenKeyW(HKEY_CLASSES_ROOT, L"exefile\\shell\\View Dependencies", &hSubKey))
	{
		gstrApplicationName = 0;
		dwRet = GetEnvironmentVariableW(L"PATH", 0, 0);
		dwSize = dwRet;
		if (dwRet)
		{
			pszPath = malloc(2 * dwRet + 2);
			GetEnvironmentVariableW(L"PATH", pszPath, dwSize);
			dwSize_1 = dwSize;
			pszPath_1 = pszPath;
			if (MakeApplicationName(L"depends.exe", pszPath, dwSize_1, &gstrApplicationName))
			{
				InsertMenuW(hMainMenuHandle, IDM_PROCESS_TEMP, MF_BYCOMMAND, IDM_PROCESS_LAUNCH_DEPENDS, L"&Launch Depends...");
				InsertMenuW(
					ghDllMenuPopup,
					IDM_DLLMENU_BASE_ITEM,
					MF_BYCOMMAND,
					IDM_DLLMENU_LAUNCH_DEPENDS,
					L"&Launch Depends...");
				gbLaunchDepends = 1;
			}
			else
			{
				gstrApplicationName = 0;
			}
			free(pszPath_1);
		}
		RegCloseKey = ::RegCloseKey;
	}
	else
	{
		gbLaunchDepends = 1;
		InsertMenuW(hMainMenuHandle, IDM_PROCESS_TEMP, MF_BYCOMMAND, IDM_PROCESS_LAUNCH_DEPENDS, L"&Launch Depends...");
		InsertMenuW(ghDllMenuPopup, IDM_DLLMENU_BASE_ITEM, MF_BYCOMMAND, IDM_DLLMENU_LAUNCH_DEPENDS, L"&Launch Depends...");
		gstrApplicationName = 0;
		::RegCloseKey(hSubKey);
	}
	if (!RegOpenKeyW(HKEY_LOCAL_MACHINE, L"Software\\Microsoft\\Windows NT\\CurrentVersion\\AeDebug", &hSubKey))
	{
		cbData = 520;
		if (!RegQueryValueExW(hSubKey, L"Debugger", 0, &Type, szPathName, &cbData))
		{
			_wcslwr_s(gszAeDebuggerPath, MAX_PATH);
			if (szPathName[0] == '"')
			{
				wcscpy_s(gszAeDebuggerPath, MAX_PATH, &szPathName[1]);
				if (wcschr(gszAeDebuggerPath, '"'))
				{
					psz = wcschr(gszAeDebuggerPath, '"');
				LABEL_110:
					*psz = 0;
					goto LABEL_111;
				}
			}
			else
			{
				wcscpy_s(gszAeDebuggerPath, MAX_PATH, szPathName);
				if (wcschr(gszAeDebuggerPath, ' '))
				{
					psz = wcschr(gszAeDebuggerPath, ' ');
					goto LABEL_110;
				}
			}
		}
	LABEL_111:
		RegCloseKey(hSubKey);
	}
	if (gszAeDebuggerPath[0])
		InsertMenuW(hMainMenuHandle, IDM_PROCESS_TEMP, MF_BYCOMMAND, IDM_PROCESS_DEBUG, L"&Debug");
	DeleteMenu(hMainMenuHandle, IDM_PROCESS_TEMP, MF_BYCOMMAND);
	hWnd_2 = hWnd_1;
	ghWndToolbar = InitToolbar(hWnd_1, IDC_MAINTOOLBAR);
	if (!ghWndToolbar)
		return -1;
	UpdateMenuStatus(0, 3);
	GetWindowRect(ghWndToolbar, &rcToolbar);
	gnToolbarHeight = rcToolbar.bottom - rcToolbar.top + 2;
	hInst = ghInstance;
	_mm_storeu_si128(&rcTreeList, 0i64);
	hWndTreeListView = CTreeList::Init(hWnd_2, hInst, IDC_TREEVIEW_LIST, 0x40810200, &rcTreeList);
	ghWndTreeListView = hWndTreeListView;
	if (!hWndTreeListView)
		return -1;
	InitTreeList(hWndTreeListView, ghConfigFont);
	pTreeList = CTreeList::GetTreeList(ghWndTreeListView);
	pTreeList_1 = pTreeList;
	pszPath = pTreeList;
	pTreeList->m_pfnDrawBack = CMainWnd::Draw;
	CTreeList::UpdateSB(pTreeList, 0);
	pTreeList_1->m_pfnGetChildCursor = CMainWnd::GetDynamicCursor;
	v87 = LoadCursorW(ghInstance, 0x6A);
	CTreeList::SetSplitterCursor(pTreeList_1, v87);
	sub_42BDA0(pTreeList_1, 1);
	sub_42F210(pTreeList_1, 0);
	sub_42F230(pTreeList_1, 0);
	v88 = CTreeList::GetTooltipOfTreeList(pTreeList_1);
	CTreeList::InitToolTips(v88);
	v89 = CTreeList::GetTooltipOfLeftHeader(pTreeList_1);
	CTreeList::InitToolTips(v89);
	v90 = CTreeList::GetTooltipOfRightHeader(pTreeList_1);
	CTreeList::InitToolTips(v90);
	dwProcessColumnCount = gConfig.dwProcessColumnCount;
	if (gConfig.dwProcessColumnMap[0] != IDS_PROCESS)
	{
		memmove(&gConfig.dwProcessColumnMap[1], gConfig.dwProcessColumnMap, 4 * gConfig.dwProcessColumnCount);
		gConfig.dwProcessColumnMap[0] = IDS_PROCESS;
		memmove(&gConfig.dwProcessColumns[1], gConfig.dwProcessColumns, 2 * gConfig.dwProcessColumnCount);
		wProcessImageColumnWidth = gConfig.wProcessImageColumnWidth;
		if (!gConfig.wProcessImageColumnWidth)
			wProcessImageColumnWidth = 200;
		gConfig.dwProcessColumns[0] = wProcessImageColumnWidth;
		dwProcessColumnCount = gConfig.dwProcessColumnCount++ + 1;
	}
	if (!InitListHeader(ghWndTreeListView, gConfig.dwProcessColumnMap, gConfig.dwProcessColumns, dwProcessColumnCount))
		return -1;
	v93 = GetSystemMetrics(SM_CYSMICON);
	v94 = GetSystemMetrics(SM_CXSMICON);
	hImgList = ImageList_Create(v94, v93, 0x21u, 256, 256);
	pTreeList_2 = pszPath;
	CTreeList::ResetImageList(pszPath, hImgList, 0);
	v97 = LoadIconW(0, IDC_ARROW);
	v98 = CTreeList::GetImageList(pTreeList_2);
	ImageList_ReplaceIcon(v98, -1, v97);
	v99 = InitSortableImageList();
	CTreeList::SetSortFlagsImageList(pTreeList_2, v99, 1, 0);
	if (!gConfig.bShowNewTree)
		CTreeList::InitHeaderColumn(
			ghWndTreeListView,
			0xFFFFFFFF,
			gConfig.dwProcessSortColumn,
			gConfig.bProcessSortDirection);
	v100 = hWnd_1;
	v101 = CreateListCtrl(
		hWnd_1,
		0x40810605u,
		gConfig.dwIdsOfHandleColumnMap,
		gConfig.dwHandleColumns,
		gConfig.dwHandleColumnCount,
		IDC_LISTCTRL_HANDLES);
	ghWndHandlesList = v101;
	if (!v101)
		return -1;
	CTreeList::InitHeaderColumn(v101, 0xFFFFFFFF, gConfig.dwHandleSortColumn, gConfig.bHandleSortDirection);
	v102 = CreateListCtrl(
		v100,
		0x40810605u,
		gConfig.dwDllColumnMap,
		gConfig.dwDllColumns,
		gConfig.dwDllColumnCount,
		IDC_LISTCTRL_DLLS);
	ghWndDllsList = v102;
	if (!v102)
		return -1;
	CTreeList::InitHeaderColumn(v102, 0xFFFFFFFF, gConfig.dwDllSortColumn, gConfig.bDllSortDirection);
	ghWndStatusBar = CreateStatusWindowW(0x50000000, &gszNullString, v100, 0x6Au);
	InitStatusBar(ghWndStatusBar);
	ghResizeCursor = LoadCursorW(ghInstance, 0x69);
	if (!ghResizeCursor)
		ghResizeCursor = LoadCursorW(0, 0x7F00);
	ghSplitterCursor = LoadCursorW(ghInstance, 0x6A);
	if (!ghSplitterCursor)
		ghSplitterCursor = LoadCursorW(0, 0x7F00);
	v103 = 0;
	if (gConfig.bHighlightRelocatedDlls)
		v103 = 8;
	v104 = v103;
	v105 = ::GetMenu(v100);
	CheckMenuItem(v105, IDM_OPTIONS_HIGHLIGHT_RELOCATED_DLLS, v104);
	ShowWindow(ghWndTreeListView, SW_SHOW);
	if (gConfig.bShowLowerPane)
	{
		if (gConfig.bShowDllView)
		{
			v106 = ::GetMenu(hWnd_1);
			CheckMenuItem(v106, IDM_VIEW_LOWERPANEVIEW_DLLS, MF_CHECKED);
			ShowWindow(ghWndDllsList, SW_SHOW);
		}
		else
		{
			v107 = ::GetMenu(hWnd_1);
			CheckMenuItem(v107, IDM_VIEW_LOWERPANEVIEW_HANDLES, MF_CHECKED);
			ShowWindow(ghWndHandlesList, SW_SHOW);
		}
	}
	nBmpIndex = 1;
	if (gConfig.bShowDllView)
		nBmpIndex = 4;
	SendMessageW(ghWndToolbar, TB_CHANGEBITMAP, IDM_POPUP_DLL_PROPERTIES, nBmpIndex);
	SendMessageW(ghWndToolbar, TB_ENABLEBUTTON, IDM_VIEW_SHOW_PROCESS_TREE, gConfig.bShowNewTree == 0);
	v109 = gConfig.bShowNewTree != 0;
	v110 = ::GetMenu(ghMainWnd);
	EnableMenuItem(v110, IDM_VIEW_SHOW_PROCESS_TREE, v109);
	v111 = ::GetMenu(ghMainWnd);
	EnableMenuItem(v111, IDM_PROCESS_KILL_PROCESS_TREE, MF_GRAYED);
	ghSystemInfoSheetThreadEvent = CreateEventW(0, 0, 0, 0);
	GetClientRect(hWnd_1, &gRectWindow);
	gRectPane.left = 0;
	gRectWindow.top = gRectWindow.top - 1 + gnToolbarHeight;
	gRectWindow.bottom -= gRectWindow.top;
	gRectPane.top = gRectWindow.top + ((gRectWindow.bottom - gRectWindow.top) * gConfig.dbDivider);
	gRectPane.bottom = gRectPane.top + 7;
	gRectPane.right = gRectWindow.right;
	if (gConfig.bShowLowerPane)
		v112 = gConfig.dbSavedDivider;
	else
		v112 = db_one;
	gConfig.dbDivider = v112;
	gConfig.bShowLowerPane = gConfig.bShowLowerPane == 0;
	Command_ShowLowerPane(0);
	gShellIconMsg = RegisterWindowMessageW(L"TaskbarCreated");
	StartBackendThread();
	CTreeList::InitTreeList(ghWndTreeListView, 1);
	SendMessageW(ghMainWnd, WM_TREEVIEW_SORT, IDC_TREEVIEW_LIST, gConfig.bShowNewTree);
	SetFocus(ghWndTreeListView);
	lvItem.iItem = SendMessageW(ghWndTreeListView, LVM_GETNEXTITEM, 0xFFFFFFFF, LVFI_STRING);
	lvItem.iSubItem = 0;
	lvItem.mask = 4;
	SendMessageW(ghWndTreeListView, LVM_GETITEMW, 0, &lvItem);
	RefreshVirusTotalMenuItem(lvItem.lParam);
	Item.stateMask = 3;
	Item.state = 3;
	SendMessageW(ghWndDllsList, LVM_SETITEMSTATE, 0, &Item);
	Item.stateMask = 3;
	Item.state = 3;
	SendMessageW(ghWndHandlesList, LVM_SETITEMSTATE, 0, &Item);
	if (IsBuiltinAdministrative() && !PE_RunTrace(&gProperties, 1))
	{
		InsertMenuW(
			hMainMenuHandle,
			IDM_OPTIONS_TRAYICON_COMMIT_HISTORY,
			MF_BYCOMMAND,
			IDM_OPTIONS_COMMIT_DISK_HISTORY,
			L"&Disk History");
		v113 = 0;
		if (gConfig.bShowDiskTray)
			v113 = 8;
		v114 = v113;
		v115 = ::GetMenu(hWnd_1);
		CheckMenuItem(v115, IDM_OPTIONS_COMMIT_DISK_HISTORY, v114);
		InsertMenuW(hMainMenuHandle, 40726u, MF_BYCOMMAND, IDM_OPTIONS_COMMIT_NETWORK_HISTORY, L"&Network History");
		v116 = 0;
		if (gConfig.bShowNetTray)
			v116 = 8;
		v117 = v116;
		v118 = ::GetMenu(hWnd_1);
		CheckMenuItem(v118, IDM_OPTIONS_COMMIT_NETWORK_HISTORY, v117);
	}
	if (gdwAdapterRuntingTime)
	{
		InsertMenuW(hMainMenuHandle, IDM_OPTIONS_TRAYICON_COMMIT_HISTORY, MF_BYCOMMAND, 40748u, L"&GPU History");
		v119 = hWnd_1;
		v120 = 0;
		if (gConfig.bShowGpuHistory)
			v120 = 8;
		v121 = v120;
		v122 = ::GetMenu(hWnd_1);
		CheckMenuItem(v122, IDM_OPTIONS_COMMIT_GPU_HISTORY, v121);
	}
	else
	{
		v119 = hWnd_1;
	}
	ghRefreshEventHandle = CreateEventW(0, 0, 0, 0);
	ghEvent2 = CreateEventW(0, 0, 0, 0);
	ghEvent3 = CreateEventW(0, 1, 0, 0);
	ghTimerRefreshEvent = CreateEventW(0, 0, 0, 0);
	ghTimerRefreshProcPageEventHandle = CreateEventW(0, 1, 0, 0);
	ghEvent6 = CreateEventW(0, 0, 0, 0);
	ghBackupRefreshThreadHandle = _beginthreadex(0, 0, CMainWnd::BackendRefreshThreadProc, 0, 0, 0);
	if (gConfig.dwRefreshRate > 2000)
	{
		if (gConfig.dwRefreshRate == 5000)
		{
			v132 = IDM_VIEW_UPDATESPEED_FIVE_SECONDS;
			goto __RefreshMenuItem;
		}
		if (gConfig.dwRefreshRate == 10000)
		{
			v132 = IDM_VIEW_UPDATESPEED_TEN_SECONDS;
			goto __RefreshMenuItem;
		}
	}
	else
	{
		if (gConfig.dwRefreshRate == 2000)
		{
			v132 = IDM_VIEW_UPDATESPEED_TWO_SECONDS;
			goto __RefreshMenuItem;
		}
		if (gConfig.dwRefreshRate)
		{
			if (gConfig.dwRefreshRate == 500)
			{
				v132 = IDM_VIEW_UPDATESPEED_HALF_SECONDS;
				goto __RefreshMenuItem;
			}
			if (gConfig.dwRefreshRate == 1000)
			{
				v132 = IDM_VIEW_UPDATESPEED_ONE_SECOND;
			__RefreshMenuItem:
				hMenuMain_1 = ::GetMenu(ghMainWnd);
				CheckMenuRadioItem(hMenuMain_1, IDM_VIEW_UPDATESPEED_PAUSED_SPACE, IDM_VIEW_UPDATESPEED_HALF_SECONDS, v132, 0);
				goto LABEL_167;
			}
		}
		else
		{
			hMenuMain = ::GetMenu(ghMainWnd);
			CheckMenuRadioItem(
				hMenuMain,
				IDM_VIEW_UPDATESPEED_PAUSED_SPACE,
				IDM_VIEW_UPDATESPEED_HALF_SECONDS,
				IDM_VIEW_UPDATESPEED_PAUSED_SPACE,
				0);
			SendMessageW(ghWndStatusBar, SB_SETTEXTW, gnStatusBarItemCount - 1, L"Paused");
		}
	}
LABEL_167:
	InvalidateRect(ghWndToolbar, 0, 1);
	SetCursor(hCursor_____);
	if (!gIOGraphInfo.pGraphData)
		DeleteMenu(hMainMenuHandle, IDM_OPTIONS_TRAYICON_IO_HISTORY, 0);
	HandleTaskbarCreated();
	v125 = GetModuleHandleW(L"Shlwapi.dll");
	gpfnSHAutoComplete = GetProcAddress(v125, "SHAutoComplete");
	v126 = LoadLibraryW(L"user32.dll");
	v127 = GetProcAddress(v126, "SetLayeredWindowAttributes");
	dwOpacity = gConfig.dwOpacity;
	SetLayeredWindowAttributes = v127;
	if (gConfig.dwOpacity != 100)
	{
		v129 = GetWindowLongW(ghMainWnd, GWL_EXSTYLE);
		SetWindowLongW(ghMainWnd, -20, v129 | WS_EX_LAYERED);
		SetLayeredWindowAttributes(ghMainWnd, 0, (255 * gConfig.dwOpacity) / 100, LWA_ALPHA);
		RedrawWindow(ghMainWnd, 0, 0, 0x485u);
		dwOpacity = gConfig.dwOpacity;
	}
	uId = (((0x66666667i64 * dwOpacity) >> 32) >> 2) + (((0x66666667i64 * dwOpacity) >> 32) >> 31) + 40093;
	v131 = ::GetMenu(v119);
	CheckMenuItem(v131, uId, 8u);
	if (gbHide)
		CMainWnd::Hide(ghMainWnd);
	return 0;
}