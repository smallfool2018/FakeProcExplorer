//----- (00FD85F0) --------------------------------------------------------
int __stdcall sub_FD85F0(HWND hDlg, int a2, int a3, int a4)
{
  HWND v4; // eax
  HWND v5; // eax
  unsigned int v6; // kr00_4
  WCHAR *v7; // edx
  WCHAR v8; // ax
  HWND v9; // eax
  HWND v10; // eax
  HWND v11; // eax
  HWND v13; // eax
  DWORD v14; // ST14_4
  HANDLE v15; // eax
  HWND v16; // eax
  HWND v17; // eax
  HWND v18; // eax
  int v19; // [esp+Ch] [ebp-82Ch]
  __int16 *v20; // [esp+10h] [ebp-828h]
  char ArgList; // [esp+14h] [ebp-824h]
  wchar_t Dst; // [esp+21Ch] [ebp-61Ch]
  WCHAR v23; // [esp+424h] [ebp-414h]
  __int16 v24; // [esp+426h] [ebp-412h]
  WCHAR String; // [esp+62Ch] [ebp-20Ch]

  if ( a2 != 272 )
  {
    if ( a2 != 273 )
      return 0;
    if ( a3 == 1 )
    {
      v4 = GetDlgItem(hDlg, 1302);
      GetWindowTextW(v4, &String, 260);
      v5 = GetDlgItem(hDlg, 1303);
      GetWindowTextW(v5, &v23, 260);
      v6 = wcslen(&String);
      v7 = &v23;
      v20 = &v24;
      do
      {
        v8 = *v7;
        ++v7;
      }
      while ( v8 );
      if ( !WTSSendMessageW(0, dword_106A914, &v23, 2 * ((v7 - v20) >> 1), &String, 2 * v6, 0, 0, &v19, 0) )
        ReportMsg(L"Error sending message", ghMainWnd);
    }
    else if ( a3 != 2 )
    {
LABEL_11:
      if ( a3 >> 16 == 768 )
      {
        v9 = GetDlgItem(hDlg, 1302);
        GetWindowTextW(v9, &String, 260);
        v10 = GetDlgItem(hDlg, 1303);
        GetWindowTextW(v10, &v23, 260);
        if ( String && v23 )
        {
          v11 = GetDlgItem(hDlg, 1);
          EnableWindow(v11, 1);
          return 0;
        }
        v13 = GetDlgItem(hDlg, 1);
        EnableWindow(v13, 0);
      }
      return 0;
    }
    EndDialog(hDlg, 0);
    goto LABEL_11;
  }
  dword_106A914 = a4;
  v14 = GetCurrentProcessId();
  v15 = GetCurrentProcess();
  QueryProcessUsers(v15, v14, 0, &Dst, 0x104u, &ArgList, 0x104u, 0, 0, 0, 0);
  swprintf(&String, L"Message from %s\\%s", &ArgList, &Dst);
  v16 = GetDlgItem(hDlg, 1303);
  SetWindowTextW(v16, &String);
  v17 = GetDlgItem(hDlg, 1302);
  SetWindowTextW(v17, &gszNullString);
  v18 = GetDlgItem(hDlg, 1303);
  SetFocus(v18);
  return 1;
}
// 1040EE8: using guessed type wchar_t aErrorSendingMe[22];
// 106F350: using guessed type int (__stdcall *WTSSendMessageW)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);

//----- (00FD8860) --------------------------------------------------------
BOOL __stdcall DlgSymbolConfig(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
  HANDLE v4; // esi
  BOOL v5; // eax
  BOOL v6; // ST0C_4
  HWND v7; // eax
  BOOL result; // eax
  HWND v9; // eax
  HWND v10; // eax
  struct tagOFNW OpenFileName; // [esp+8h] [ebp-4B4h]
  struct _WIN32_FIND_DATAW FindFileData; // [esp+60h] [ebp-45Ch]
  WCHAR szText[260]; // [esp+2B0h] [ebp-20Ch]

  if ( uMsg == WM_INITDIALOG )
  {
    SetDlgItemTextW(hDlg, IDC_DLG_SYMBOLCONFIG_EDIT_DBGHELPDLL_PATH, gConfig.strDbgHelpModuleName);
    SetDlgItemTextW(hDlg, IDC_DLG_SYMBOLCONFIG_EDIT_SYMBOLS_PATH, gConfig.strNtSymbolPath);
    if ( gpfnSHAutoComplete )
    {
      v9 = GetDlgItem(hDlg, IDC_DLG_SYMBOLCONFIG_EDIT_DBGHELPDLL_PATH);
      gpfnSHAutoComplete(v9, 1u);
    }
    v10 = GetDlgItem(hDlg, IDC_DLG_SYMBOLCONFIG_EDIT_DBGHELPDLL_PATH);
    SetFocus(v10);
    result = 1;
  }
  else
  {
    if ( uMsg == WM_COMMAND )
    {
      if ( wParam > IDC_DLG_SYMBOLCONFIG_BUTTON_BROWSE_DBGHELPDLL_PATH )
      {
        if ( wParam == IDC_DLG_SYMBOLCONFIG_BUTTON_BROWSE_SYMBOLS_PATH )
        {
          GetDlgItemTextW(hDlg, IDC_DLG_SYMBOLCONFIG_EDIT_SYMBOLS_PATH, szText, MAX_PATH);
          if ( BrowseSymbolPath(hDlg, szText) )
            SetDlgItemTextW(hDlg, IDC_DLG_SYMBOLCONFIG_EDIT_SYMBOLS_PATH, szText);
        }
      }
      else
      {
        switch ( wParam )
        {
          case IDC_DLG_SYMBOLCONFIG_BUTTON_BROWSE_DBGHELPDLL_PATH:
            GetDlgItemTextW(hDlg, IDC_DLG_SYMBOLCONFIG_EDIT_DBGHELPDLL_PATH, szText, MAX_PATH);
            memset(&OpenFileName, 0, 0x58u);
            OpenFileName.hInstance = ghInstance;
            OpenFileName.lpstrFile = szText;
            *&OpenFileName.nFileOffset = 0;
            OpenFileName.lpfnHook = 0;
            OpenFileName.lStructSize = 76;
            OpenFileName.hwndOwner = hDlg;
            OpenFileName.lpstrCustomFilter = 0;
            OpenFileName.nMaxCustFilter = 0;
            OpenFileName.nFilterIndex = 1;
            OpenFileName.nMaxFile = 256;
            OpenFileName.lpstrFileTitle = 0;
            OpenFileName.nMaxFileTitle = 0;
            OpenFileName.lpstrInitialDir = 0;
            OpenFileName.Flags = 0x200000;
            OpenFileName.lpstrTitle = L"Specify dbghelp.dll...";
            OpenFileName.lpstrDefExt = L"*.dll";
            OpenFileName.lpstrFilter = L"Dbghelp DLL (dbghelp.dll)";
            if ( GetOpenFileNameW(&OpenFileName) )
              SetDlgItemTextW(hDlg, 1088, szText);
            break;
          case 1u:
            GetDlgItemTextW(hDlg, 1088, szText, 260);
            if ( LoadDbgHelp(szText) )
            {
              GetDlgItemTextW(hDlg, 1089, gConfig.strNtSymbolPath, 260);
              wcscpy_s(gConfig.strDbgHelpModuleName, 0x104u, szText);
              SetEnvironmentVariableW(L"_NT_SYMBOL_PATH", gConfig.strNtSymbolPath);
              dword_105E0DC = 1;
              ShowSymbolConfigWarning(hDlg);
              EndDialog(hDlg, 0);
            }
            else
            {
              MessageBoxW(
                hDlg,
                L"The DLL you specified is not a valid version of the Debugging Tools Help File.",
                L"Process Explorer Error",
                0x10u);
            }
            break;
          case IDC_MYICON:
            EndDialog(hDlg, 0);
            break;
        }
      }
      if ( wParam >> 16 == 768 )
      {
        GetDlgItemTextW(hDlg, 1088, szText, 260);
        v4 = FindFirstFileW(szText, &FindFileData);
        v5 = v4 != -1 && !(FindFileData.dwFileAttributes & 0x10);
        v6 = v5;
        v7 = GetDlgItem(hDlg, 1);
        EnableWindow(v7, v6);
        if ( v4 )
          FindClose(v4);
      }
    }
    result = 0;
  }
  return result;
}
// 1041578: using guessed type wchar_t aSpecifyDbghelp[23];
// 10415A8: using guessed type wchar_t aDll_2[6];
// 10415B4: using guessed type wchar_t aDbghelpDllDbgh[26];
// 105E0DC: using guessed type int dword_105E0DC;
// 106A8F4: using guessed type int (__stdcall *gpfnSHAutoComplete)(struct HWND__ *, unsigned int);

//----- (00FD8B70) --------------------------------------------------------
char __cdecl BrowseSymbolPath(HWND hWnd, LPWSTR pszPath)
{
  void *pBuffer; // esi
  char result; // al
  const ITEMIDLIST *pItemList; // eax
  ITEMIDLIST *pItemList_1; // edi
  struct _browseinfoW bi; // [esp+4h] [ebp-28h]
  LPITEMIDLIST pidl; // [esp+24h] [ebp-8h]
  IMalloc *pMalloc; // [esp+28h] [ebp-4h]

  SHGetMalloc(&pMalloc);
  pBuffer = pMalloc->lpVtbl->Alloc(pMalloc, MAX_PATH);
  if ( !pBuffer )
    return 0;
  if ( SHGetSpecialFolderLocation(hWnd, 0, &pidl) >= 0 )
  {
    bi.pidlRoot = pidl;
    bi.hwndOwner = hWnd;
    bi.pszDisplayName = pszPath;
    bi.lpszTitle = L"Browse for Symbols Directory";
    bi.ulFlags = 0x11;
    bi.lpfn = 0;
    bi.lParam = 0;
    pItemList = SHBrowseForFolderW(&bi);
    pItemList_1 = pItemList;
    if ( pItemList )
    {
      SHGetPathFromIDListW(pItemList, pszPath);
      pMalloc->lpVtbl->Free(pMalloc, pItemList_1);
      pMalloc->lpVtbl->Free(pMalloc, pidl);
      pMalloc->lpVtbl->Free(pMalloc, pBuffer);
      result = 1;
    }
    else
    {
      pMalloc->lpVtbl->Free(pMalloc, pidl);
      pMalloc->lpVtbl->Free(pMalloc, pBuffer);
      result = 0;
    }
  }
  else
  {
    pMalloc->lpVtbl->Free(pMalloc, pBuffer);
    result = 0;
  }
  return result;
}
// 10414DC: using guessed type wchar_t aBrowseForSymbo[29];

//----- (00FD8C50) --------------------------------------------------------
BOOL BackendSysInfoPropSheetThreadProc()
{
  HICON v0; // edi
  BOOL result; // eax
  struct tagMSG msg; // [esp+8h] [ebp-20h]
  HACCEL hAccel; // [esp+24h] [ebp-4h]

  ghWndSysinfoPropSheet = CreateDialogParamW(ghInstance, L"SYSINFOPROPSHEET", 0, SysinfoPropSheet, 0);
  v0 = LoadIconW(ghInstance, 101);
  SendMessageW(ghWndSysinfoPropSheet, WM_SETICON, 0, v0);
  SendMessageW(ghWndSysinfoPropSheet, WM_SETICON, 1u, v0);
  SetEvent(ghSystemInfoSheetThreadEvent);
  hAccel = LoadAcceleratorsW(ghInstance, L"PROCPROPERTIES");
  for ( result = GetMessageW(&msg, 0, 0, 0); result; result = GetMessageW(&msg, 0, 0, 0) )
  {
    if ( !TranslateAcceleratorW(ghWndSysinfoPropSheet, hAccel, &msg) && !IsDialogMessageW(ghWndSysinfoPropSheet, &msg) )
    {
      TranslateMessage(&msg);
      DispatchMessageW(&msg);
    }
  }
  return result;
}

//----- (00FD8D50) --------------------------------------------------------
const wchar_t *__cdecl sub_FD8D50(int a1)
{
  const wchar_t *result; // eax

  switch ( a1 )
  {
    case 1:
      result = L"16";
      break;
    case 2:
      result = L"256";
      break;
    case 4:
      result = L"65536";
      break;
    case 8:
    case 24:
      result = L"2^24";
      break;
    case 16:
      result = L"2^15";
      break;
    case 32:
      result = L"2^32";
      break;
    default:
      result = L"<?>";
      break;
  }
  return result;
}
// 1040E34: using guessed type wchar_t a16[3];
// 1040E3C: using guessed type wchar_t a256[4];
// 1040E44: using guessed type wchar_t a65536[6];
// 1040E50: using guessed type wchar_t a224[5];
// 1040E5C: using guessed type wchar_t a215[5];
// 1040E68: using guessed type wchar_t a232[5];
// 1040E74: using guessed type wchar_t asc_1040E74[4];

//----- (00FD8DE0) --------------------------------------------------------
BOOL __stdcall sub_FD8DE0(HWND hDlg, UINT a2, WPARAM a3, LPARAM a4)
{
  WCHAR *v5; // eax
  struct _WTS_SESSION_INFOW *v6; // eax
  const wchar_t *v7; // eax
  _DWORD *v8; // ecx
  PWTS_SESSION_INFOW SessionInfo; // [esp+4h] [ebp-22Ch]
  LPCWSTR lpString; // [esp+8h] [ebp-228h]
  PWTS_SESSION_INFOW v11; // [esp+Ch] [ebp-224h]
  char ArgList[4]; // [esp+10h] [ebp-220h]
  PWTS_SESSION_INFOW v13; // [esp+14h] [ebp-21Ch]
  PWTS_SESSION_INFOW v14; // [esp+18h] [ebp-218h]
  PWTS_SESSION_INFOW v15; // [esp+1Ch] [ebp-214h]
  DWORD pBytesReturned; // [esp+20h] [ebp-210h]
  WCHAR String; // [esp+24h] [ebp-20Ch]

  if ( a2 == 43 )
  {
    CMainWnd::DrawList(a4);
    return 0;
  }
  if ( a2 != 272 )
  {
    if ( a2 == 273 && a3 - 1 <= 1 )
    {
      EndDialog(hDlg, 0);
      return 0;
    }
    return 0;
  }
  SessionId = a4;
  swprintf(&String, L"%d", a4);
  SetDlgItemTextW(hDlg, 108, &String);
  v15 = 0;
  WTSQuerySessionInformationW(0, SessionId, WTSClientProtocolType, &v15, &pBytesReturned);
  if ( WTSQuerySessionInformationW(0, SessionId, WTSUserName, &SessionInfo, &pBytesReturned) )
  {
    if ( WTSQuerySessionInformationW(0, SessionId, WTSDomainName, ArgList, &pBytesReturned) )
    {
      swprintf(&String, L"%s\\%s", *ArgList, SessionInfo);
      SetDlgItemTextW(hDlg, 106, &String);
      WTSFreeMemory(*ArgList);
    }
    WTSFreeMemory(SessionInfo);
  }
  if ( WTSQuerySessionInformationW(0, SessionId, WTSConnectState, &v14, &pBytesReturned) )
  {
    if ( v14->SessionId >= 0xA )
    {
      swprintf(&String, L"Unknown (%d)", v14->SessionId);
      v5 = &String;
    }
    else
    {
      v5 = &aActive[32 * v14->SessionId];
    }
    SetDlgItemTextW(hDlg, 1083, v5);
    WTSFreeMemory(v14);
  }
  v6 = v15;
  if ( v15 )
  {
    if ( LOWORD(v15->SessionId) )
    {
      if ( WTSQuerySessionInformationW(0, SessionId, WTSClientName, &lpString, &pBytesReturned) )
      {
        SetDlgItemTextW(hDlg, 110, lpString);
        WTSFreeMemory(lpString);
      }
      if ( WTSQuerySessionInformationW(0, SessionId, WTSClientAddress, &v13, &pBytesReturned) && v13->pWinStationName )
      {
        swprintf(
          &String,
          L"%d.%d.%d.%d",
          BYTE2(v13->pWinStationName),
          HIBYTE(v13->pWinStationName),
          LOBYTE(v13->State),
          BYTE1(v13->State));
        SetDlgItemTextW(hDlg, 111, &String);
        WTSFreeMemory(v13);
      }
      if ( WTSQuerySessionInformationW(0, SessionId, WTSClientDisplay, &v11, &pBytesReturned) )
      {
        v7 = sub_FD8D50(v11->State);
        swprintf(&String, L"%dx%d by %s colors", *v8, v8[1], v7);
        SetDlgItemTextW(hDlg, 112, &String);
        WTSFreeMemory(v11);
      }
      v6 = v15;
    }
    if ( v6 )
      WTSFreeMemory(v6);
  }
  return 1;
}
// 105E130: using guessed type wchar_t aActive[7];

//----- (00FD90F0) --------------------------------------------------------
CGraphData *HandleTaskbarCreated()
{
  signed int v0; // esi
  CGraphData *result; // eax
  int v2; // esi

  v0 = 1;
  do
    result = TrayIcon_Delete(ghMainWnd, v0++);
  while ( v0 < 5 );
  v2 = 1;
  if ( gConfig.bShowPhysTray )
  {
    dword_106A3F0 = 1;
    result = TrayIcon_Add(ghMainWnd, 1u, gpGraphInfoOfPhysicalMemory, &gszNullString);
    v2 = 2;
  }
  else
  {
    dword_106A3F0 = 0;
  }
  if ( gConfig.bShowIoTray )
  {
    dword_106A3C8 = v2;
    result = TrayIcon_Add(ghMainWnd, v2++, gIOGraphInfo.pGraphData, &gszNullString);
  }
  else
  {
    dword_106A3C8 = 0;
  }
  if ( gConfig.bShowDiskTray )
  {
    dword_106A3F4 = v2;
    result = TrayIcon_Add(ghMainWnd, v2++, gDiskGraphInfo.pGraphData, &gszNullString);
  }
  else
  {
    dword_106A3F4 = 0;
  }
  if ( gConfig.bShowGpuHistory && (result = gpGraphInfoOfGPU) != 0 )
  {
    dword_106A3C0 = v2;
    result = TrayIcon_Add(ghMainWnd, v2++, gpGraphInfoOfGPU, &gszNullString);
  }
  else
  {
    dword_106A3C0 = 0;
  }
  if ( gConfig.bShowNetTray )
  {
    dword_106A600 = v2;
    result = TrayIcon_Add(ghMainWnd, v2++, gNetworkGraphInfo.pGraphData, &gszNullString);
  }
  else
  {
    dword_106A600 = 0;
  }
  if ( gConfig.bShowCommitTray )
  {
    dword_106A3C4 = v2;
    result = TrayIcon_Add(ghMainWnd, v2++, gpGraphInfoOfMemory, &gszNullString);
  }
  else
  {
    dword_106A3C4 = 0;
  }
  if ( gConfig.bTrayCPUHistory )
  {
    dword_106A3BC = v2;
    result = TrayIcon_Add(ghMainWnd, v2, gpGraphInfoOfCPU, &gszNullString);
  }
  else
  {
    dword_106A3BC = 0;
  }
  return result;
}
// 106A3BC: using guessed type int dword_106A3BC;

//----- (00FD92A0) --------------------------------------------------------
void __cdecl ShowSymbolConfigWarning(HWND hWnd)
{
  DWORD cbLength; // esi
  _DWORD *pVersionInfo; // ebx
  DWORD dwHandle; // [esp+4h] [ebp-4h]

  dwHandle = 0;
  if ( !_wcsnicmp(L"srv*", gConfig.strNtSymbolPath, 4u) )
  {
    cbLength = GetFileVersionInfoSizeW(gConfig.strDbgHelpModuleName, &dwHandle);
    pVersionInfo = malloc(cbLength);
    if ( GetFileVersionInfoW(gConfig.strDbgHelpModuleName, 0, cbLength, pVersionInfo) && pVersionInfo[12] < 0x60000u )
    {
      if ( hWnd )
        DialogBoxParamW(ghInstance, L"SYMBOLDBGHELPGWARNING", 0, DlgAbout, 0);
      else
        DialogBoxParamW(ghInstance, L"SYMBOLCONFIGWARNING", 0, DlgAbout, 0);
    }
    free(pVersionInfo);
  }
  if ( !LOBYTE(gConfig.bSymbolWarningShown) && (!SymInitialize || !gConfig.strNtSymbolPath[0]) )
  {
    DialogBoxParamW(ghInstance, L"SYMBOLCONFIGWARNING", 0, DlgAbout, 0);
    LOBYTE(gConfig.bSymbolWarningShown) = 1;
    UpdateWindowPlacement(ghMainWnd, 1);
  }
}

//----- (00FD9380) --------------------------------------------------------
int __cdecl SearchWindow(HWND hWnd)
{
  int result; // eax
  HWND v2; // eax
  unsigned int nCount; // edi
  WPARAM nIndex; // esi
  DWORD dwProcessId_1; // ecx
  tagTREEVIEWLISTITEMPARAM *pTreeViewListItemParam; // eax
  LVITEMW Item; // [esp+8h] [ebp-244h]
  DWORD dwProcessId; // [esp+3Ch] [ebp-210h]
  WCHAR szBuffer[260]; // [esp+40h] [ebp-20Ch]

  if ( gbWindowFinding )
  {
    SetCursor(ghFindCursor);
    ReleaseCapture();
    gbWindowFinding = 0;
    SendMessageW(ghWndToolbar, TB_PRESSBUTTON, IDM_FIND_PROCESS_BY_WINDOW, 0);
    SetWindowPos(hWnd, -(gConfig.bAlwaysOntop != 0), 0, 0, 0, 0, SWP_NOMOVE|SWP_NOSIZE);
    if ( ghWndHungWindow )
    {
      DrawHungWindow(ghWndHungWindow);
      if ( !HungWindowFromGhostWindow || (v2 = HungWindowFromGhostWindow(ghWndHungWindow)) == 0 )
        v2 = ghWndHungWindow;
      GetWindowThreadProcessId(v2, &dwProcessId);
      nCount = SendMessageW(ghWndTreeListView, LVM_GETITEMCOUNT, 0, 0);
      nIndex = 0;
      if ( nCount )
      {
        while ( 1 )
        {
          Item.mask = LVIF_PARAM;
          Item.iItem = nIndex;
          Item.iSubItem = 0;
          SendMessageW(ghWndTreeListView, LVM_GETITEMW, 0, &Item);
          dwProcessId_1 = dwProcessId;
          if ( Item.lParam->dwProcessId == dwProcessId )
            break;
          if ( ++nIndex >= nCount )
            goto __BREAK;
        }
        Item.mask = LVIF_STATE;
        Item.stateMask = LVIS_SELECTED;
        Item.state = LVIS_SELECTED;
        SendMessageW(ghWndTreeListView, LVM_SETITEMW, 0, &Item);
        SendMessageW(ghWndTreeListView, LVM_ENSUREVISIBLE, nIndex, 0);
        SetFocus(ghWndTreeListView);
      }
      dwProcessId_1 = dwProcessId;
__BREAK:
      if ( nIndex == nCount )
      {
        pTreeViewListItemParam = gpTreeViewListItemParam;
        if ( gpTreeViewListItemParam )
        {
          while ( pTreeViewListItemParam->dwProcessId != dwProcessId_1 )
          {
            pTreeViewListItemParam = pTreeViewListItemParam->m_Prev;
            if ( !pTreeViewListItemParam )
              goto __ReportError;
          }
          swprintf(
            szBuffer,
            L"The owning process is %s (process ID %d), which is not currently visible in the process list.",
            pTreeViewListItemParam->szProcessName2,
            pTreeViewListItemParam->dwProcessId);
          MessageBoxW(ghWndTreeListView, szBuffer, L"Process Explorer Error", MB_ICONASTERISK);
        }
        else
        {
__ReportError:
          MessageBoxW(
            ghWndTreeListView,
            L"Unable to find the window's owning process in the current process list",
            L"Process Explorer Error",
            MB_ICONERROR);
        }
      }
    }
    result = 0;
  }
  else
  {
    SetWindowPos(hWnd, HWND_BOTTOM, 0, 0, 0, 0, SWP_NOMOVE|SWP_NOSIZE);
    SetWindowPos(hWnd, HWND_BOTTOM, 0, 0, 0, 0, SWP_NOMOVE|SWP_NOSIZE);
    ghFindCursor = SetCursor(ghFindCursor);
    SetCapture(hWnd);
    gbWindowFinding = 1;
    result = 0;
    ghWndHungWindow = 0;
  }
  return result;
}
// 106A38B: using guessed type char gbWindowFinding;

//----- (00FD95D0) --------------------------------------------------------
LRESULT __stdcall CMainWnd::MainWndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
  if ( Msg == gShellIconMsg )
    HandleTaskbarCreated();
  return HandleMsgHandler(&CMainWnd::gMsgHandler, hWnd, Msg, wParam, lParam);
}
// 106A884: using guessed type int gShellIconMsg;

//----- (00FD9600) --------------------------------------------------------
int __cdecl DumpFileProcess(int hFile, HANDLE Process, char a3)
{
  HMODULE v3; // eax
  signed int v4; // eax
  MINIDUMP_TYPE v5; // ST0C_4
  DWORD v6; // eax

  v3 = LoadLibraryW(L"Dbghelp.dll");
  if ( GetProcAddress(v3, "EnumDirTreeW") )
  {
    v4 = 4357;
    if ( a3 )
      v4 = 6407;
  }
  else
  {
    v4 = 261;
    if ( a3 )
      v4 = 263;
  }
  v5 = v4;
  v6 = GetProcessId(Process);
  return MiniDumpWriteDump(Process, v6, hFile, v5, 0, 0, 0);
}

//----- (00FD9660) --------------------------------------------------------
int __cdecl sub_FD9660(int a1, int a2, wchar_t *Dst)
{
  return swprintf_s(Dst, 0x400u, L"%d.%d.%d.%d", a2 >> 16, a2, a1 >> 16, a1);
}

//----- (00FD9690) --------------------------------------------------------
_DWORD *__thiscall sub_FD9690(_DWORD *this, int a2)
{
  _DWORD *result; // eax

  result = sub_FF5470(this);
  *(result + 6) = 0;
  if ( result != -16 )
  {
    result[4] = *a2;
    _mm_storeu_si128((result + 6), _mm_loadu_si128((a2 + 8)));
    _mm_storeu_si128((result + 10), _mm_loadu_si128((a2 + 24)));
    _mm_storeu_si128((result + 14), _mm_loadu_si128((a2 + 40)));
  }
  return result;
}

//----- (00FD96D0) --------------------------------------------------------
int __thiscall std::_Tree<std::_Tmap_traits<unsigned long,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *>>,0>>::_Insert_at<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *> &,std::_Tree_node<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *>,void *> *>(CSystemProcessInfoMap *this, int a2, char a3, int a4, int a5, CSystemProcessInfoMapNode *_Node)
{
  CSystemProcessInfoMap *v6; // edi
  unsigned int v7; // eax
  CSystemProcessInfoMapNode *v8; // eax
  std__Tree_node *v9; // ecx
  std__Tree_node *v10; // esi
  std__Tree_node *v11; // edx
  CSystemProcessInfoMapNode **v12; // edx
  CSystemProcessInfoMapNode **v13; // ecx
  CSystemProcessInfoMapNode *v14; // edx
  std__Tree_node *v15; // esi
  std__Tree_node_For__bstr_t *v16; // ecx
  _DWORD *v17; // ecx
  std__Tree_node *v18; // edx
  std__Tree_node_For__bstr_t *v19; // ecx
  CSystemProcessInfoMapNode *v20; // ecx
  CSystemProcessInfoMapNode **v21; // ecx
  int result; // eax

  v6 = this;
  v7 = this->_Size;
  if ( v7 >= 0xAAAAAA9 )
  {
    j__free(_Node);
    std::_Xlength_error("map/set<T> too long");
  }
  this->_Size = v7 + 1;
  _Node->baseclass._Parent = a4;
  if ( a4 == this->_Header )
  {
    this->_Header->_Parent = _Node;
    this->_Header->_Left = _Node;
    this->_Header->_Right = _Node;
  }
  else if ( a3 )
  {
    *a4 = _Node;
    if ( a4 == this->_Header->_Left )
      this->_Header->_Left = _Node;
  }
  else
  {
    *(a4 + 8) = _Node;
    if ( a4 == this->_Header->_Right )
      this->_Header->_Right = _Node;
  }
  v8 = _Node;
  while ( !v8->baseclass._Parent->baseclass._Color )
  {
    v9 = v8->baseclass._Parent;
    v10 = v9->_Parent;
    v11 = v10->_Left;
    if ( v9 == v10->_Left )
    {
      v11 = v10->_Right;
      if ( v11->_Color )
      {
        if ( v8 == v9->_Right )
        {
          v8 = v8->baseclass._Parent;
          v12 = v9->_Right;
          v9->_Right = *v12;
          if ( !(*v12)->baseclass._isnil )
            (*v12)->baseclass._Parent = v9;
          v12[1] = v9->_Parent;
          if ( v9 == v6->_Header->_Parent )
          {
            v6->_Header->_Parent = v12;
          }
          else
          {
            v13 = v9->_Parent;
            if ( v8 == *v13 )
              *v13 = v12;
            else
              v13[2] = v12;
          }
          *v12 = v8;
          v8->baseclass._Parent = v12;
        }
        v8->baseclass._Parent->baseclass._Color = 1;
        v8->baseclass._Parent->baseclass._Parent->baseclass._Color = 0;
        v14 = v8->baseclass._Parent->baseclass._Parent;
        v15 = v14->baseclass._Left;
        v14->baseclass._Left = v14->baseclass._Left->baseclass._Right;
        v16 = v15->_Right;
        if ( !v16->_IsNil )
          v16->_Parent = v14;
        v15->_Parent = v14->baseclass._Parent;
        if ( v14 == v6->_Header->_Parent )
        {
          v6->_Header->_Parent = v15;
          v15->_Right = v14;
        }
        else
        {
          v17 = &v14->baseclass._Parent->baseclass._Left;
          if ( v14 == v17[2] )
            v17[2] = v15;
          else
            *v17 = v15;
          v15->_Right = v14;
        }
LABEL_48:
        v14->baseclass._Parent = v15;
        continue;
      }
    }
    else if ( v11->_Color )
    {
      if ( v8 == v9->_Left )
      {
        v8 = v8->baseclass._Parent;
        v18 = v9->_Left;
        v9->_Left = v9->_Left->_Right;
        v19 = v18->_Right;
        if ( !v19->_IsNil )
          v19->_Parent = v8;
        v18->_Parent = v8->baseclass._Parent;
        if ( v8 == v6->_Header->_Parent )
        {
          v6->_Header->_Parent = v18;
        }
        else
        {
          v20 = v8->baseclass._Parent;
          if ( v8 == v20->baseclass._Right )
            v20->baseclass._Right = v18;
          else
            v20->baseclass._Left = v18;
        }
        v18->_Right = v8;
        v8->baseclass._Parent = v18;
      }
      v8->baseclass._Parent->baseclass._Color = 1;
      v8->baseclass._Parent->baseclass._Parent->baseclass._Color = 0;
      v14 = v8->baseclass._Parent->baseclass._Parent;
      v15 = v14->baseclass._Right;
      v14->baseclass._Right = v15->_Left;
      if ( !v15->_Left->_IsNil )
        v15->_Left->_Parent = v14;
      v15->_Parent = v14->baseclass._Parent;
      if ( v14 == v6->_Header->_Parent )
      {
        v6->_Header->_Parent = v15;
      }
      else
      {
        v21 = &v14->baseclass._Parent->baseclass._Left;
        if ( v14 == *v21 )
          *v21 = v15;
        else
          v21[2] = v15;
      }
      v15->_Left = v14;
      goto LABEL_48;
    }
    v9->_Color = 1;
    v11->_Color = 1;
    v8->baseclass._Parent->baseclass._Parent->baseclass._Color = 0;
    v8 = v8->baseclass._Parent->baseclass._Parent;
  }
  v6->_Header->_Parent->_Color = 1;
  result = a2;
  *a2 = _Node;
  return result;
}

//----- (00FD98E0) --------------------------------------------------------
_DWORD *__thiscall sub_FD98E0(_DWORD *this, _DWORD *a2, char a3, _DWORD *a4, int a5, int a6)
{
  _DWORD *v6; // edi
  _DWORD *v7; // eax
  _DWORD *v8; // ebx
  int v9; // eax
  _DWORD *v10; // eax
  int *v11; // ecx
  int *v12; // esi
  int *v13; // edx
  _DWORD *v14; // edx
  _DWORD *v15; // ecx
  _DWORD *v16; // edx
  _DWORD *v17; // esi
  int v18; // ecx
  _DWORD *v19; // ecx
  int v20; // edx
  int v21; // ecx
  _DWORD *v22; // ecx
  _DWORD *v23; // ecx
  _DWORD *result; // eax

  v6 = this;
  if ( this[1] >= 0x38E38E2u )
    std::_Xlength_error("map/set<T> too long");
  v7 = sub_FD9690(this, a5);
  ++v6[1];
  v8 = v7;
  v7[1] = a4;
  if ( a4 == *v6 )
  {
    *(*v6 + 4) = v7;
    **v6 = v7;
    v9 = *v6;
LABEL_8:
    *(v9 + 8) = v8;
    goto LABEL_9;
  }
  if ( !a3 )
  {
    a4[2] = v7;
    v9 = *v6;
    if ( a4 != *(*v6 + 8) )
      goto LABEL_9;
    goto LABEL_8;
  }
  *a4 = v7;
  if ( a4 == **v6 )
    **v6 = v7;
LABEL_9:
  v10 = v8;
  while ( !*(v10[1] + 12) )
  {
    v11 = v10[1];
    v12 = v11[1];
    v13 = *v12;
    if ( v11 == *v12 )
    {
      v13 = v12[2];
      if ( *(v13 + 12) )
      {
        if ( v10 == v11[2] )
        {
          v10 = v10[1];
          v14 = v11[2];
          v11[2] = *v14;
          if ( !*(*v14 + 13) )
            *(*v14 + 4) = v11;
          v14[1] = v11[1];
          if ( v11 == *(*v6 + 4) )
          {
            *(*v6 + 4) = v14;
          }
          else
          {
            v15 = v11[1];
            if ( v10 == *v15 )
              *v15 = v14;
            else
              v15[2] = v14;
          }
          *v14 = v10;
          v10[1] = v14;
        }
        *(v10[1] + 12) = 1;
        *(*(v10[1] + 4) + 12) = 0;
        v16 = *(v10[1] + 4);
        v17 = *v16;
        *v16 = *(*v16 + 8);
        v18 = v17[2];
        if ( !*(v18 + 13) )
          *(v18 + 4) = v16;
        v17[1] = v16[1];
        if ( v16 == *(*v6 + 4) )
        {
          *(*v6 + 4) = v17;
          v17[2] = v16;
        }
        else
        {
          v19 = v16[1];
          if ( v16 == v19[2] )
            v19[2] = v17;
          else
            *v19 = v17;
          v17[2] = v16;
        }
LABEL_48:
        v16[1] = v17;
        continue;
      }
    }
    else if ( *(v13 + 12) )
    {
      if ( v10 == *v11 )
      {
        v10 = v10[1];
        v20 = *v11;
        *v11 = *(*v11 + 8);
        v21 = *(v20 + 8);
        if ( !*(v21 + 13) )
          *(v21 + 4) = v10;
        *(v20 + 4) = v10[1];
        if ( v10 == *(*v6 + 4) )
        {
          *(*v6 + 4) = v20;
        }
        else
        {
          v22 = v10[1];
          if ( v10 == v22[2] )
            v22[2] = v20;
          else
            *v22 = v20;
        }
        *(v20 + 8) = v10;
        v10[1] = v20;
      }
      *(v10[1] + 12) = 1;
      *(*(v10[1] + 4) + 12) = 0;
      v16 = *(v10[1] + 4);
      v17 = v16[2];
      v16[2] = *v17;
      if ( !*(*v17 + 13) )
        *(*v17 + 4) = v16;
      v17[1] = v16[1];
      if ( v16 == *(*v6 + 4) )
      {
        *(*v6 + 4) = v17;
      }
      else
      {
        v23 = v16[1];
        if ( v16 == *v23 )
          *v23 = v17;
        else
          v23[2] = v17;
      }
      *v17 = v16;
      goto LABEL_48;
    }
    *(v11 + 12) = 1;
    *(v13 + 12) = 1;
    *(*(v10[1] + 4) + 12) = 0;
    v10 = *(v10[1] + 4);
  }
  *(*(*v6 + 4) + 12) = 1;
  result = a2;
  *a2 = v8;
  return result;
}

//----- (00FD9AF0) --------------------------------------------------------
int __thiscall std::_Tree<std::_Tmap_traits<unsigned long,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *>>,0>>::_Insert_hint<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *> &,std::_Tree_node<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *>,void *> *>(CSystemProcessInfoMap *this, int a2, int _Where, int _Val, CSystemProcessInfoMapNode *_Newnode)
{
  std__Tree_node *v5; // ecx
  bool v6; // dl
  _DWORD *v7; // ebx
  int v8; // edi
  std__Tree_node *v9; // eax
  std__Tree_node *v10; // ecx
  int v11; // esi
  int *v12; // eax
  int v13; // ecx
  int result; // eax
  int v15; // [esp+0h] [ebp-2Ch]
  std__Tree_node *v16; // [esp+10h] [ebp-1Ch]
  CSystemProcessInfoMap *v17; // [esp+14h] [ebp-18h]
  int v18; // [esp+18h] [ebp-14h]
  int *v19; // [esp+1Ch] [ebp-10h]
  int v20; // [esp+28h] [ebp-4h]

  v19 = &v15;
  v17 = this;
  v5 = this->_Header;
  v6 = 1;
  v7 = _Val;
  v8 = v5;
  v20 = 0;
  v16 = v5;
  v9 = v5->_Parent;
  LOBYTE(v18) = 1;
  if ( !v9->_IsNil )
  {
    v10 = *_Val;
    do
    {
      v8 = v9;
      if ( _Where )
        v6 = v9[1]._Left >= v10;
      else
        v6 = v10 < v9[1]._Left;
      LOBYTE(v18) = v6;
      if ( v6 )
        v9 = v9->_Left;
      else
        v9 = v9->_Right;
    }
    while ( !v9->_IsNil );
    v5 = v16;
  }
  v11 = v8;
  _Where = v8;
  if ( v6 )
  {
    if ( v8 == v5->_Left )
    {
      v12 = std::_Tree<std::_Tmap_traits<unsigned long,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *>>,0>>::_Insert_at<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *> &,std::_Tree_node<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *>,void *> *>(
              v17,
              &_Where,
              1,
              v8,
              _Val,
              _Newnode);
LABEL_14:
      v13 = *v12;
      result = a2;
      *a2 = v13;
      *(a2 + 4) = 1;
      return result;
    }
    std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *>>>,std::_Iterator_base0>::operator--(&_Where);
    v11 = _Where;
  }
  if ( *(v11 + 16) < *v7 )
  {
    v12 = std::_Tree<std::_Tmap_traits<unsigned long,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *>>,0>>::_Insert_at<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *> &,std::_Tree_node<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *>,void *> *>(
            v17,
            &_Where,
            v18,
            v8,
            v7,
            _Newnode);
    goto LABEL_14;
  }
  j__free(_Newnode);
  result = a2;
  *a2 = v11;
  *(a2 + 4) = 0;
  return result;
}
// 10081AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);

//----- (00FD9C10) --------------------------------------------------------
int __thiscall sub_FD9C10(_DWORD *this, int a2, _DWORD *a3, _DWORD *a4, int a5)
{
  _DWORD *v5; // ebx
  _DWORD *v6; // ecx
  bool v7; // dl
  _DWORD *v8; // edi
  _DWORD *v9; // esi
  int *v10; // eax
  unsigned int v11; // ecx
  _DWORD *v12; // eax
  int *v13; // eax
  int v14; // ecx
  int result; // eax
  int v16; // [esp+0h] [ebp-2Ch]
  _DWORD *v17; // [esp+10h] [ebp-1Ch]
  _DWORD *v18; // [esp+14h] [ebp-18h]
  int v19; // [esp+18h] [ebp-14h]
  int *v20; // [esp+1Ch] [ebp-10h]
  int v21; // [esp+28h] [ebp-4h]

  v20 = &v16;
  v5 = this;
  v17 = this;
  v6 = *this;
  v7 = 1;
  v8 = a4;
  v9 = v6;
  v21 = 0;
  v18 = v6;
  v10 = v6[1];
  LOBYTE(v19) = 1;
  if ( !*(v10 + 13) )
  {
    v11 = *a4;
    do
    {
      v9 = v10;
      if ( a3 )
        v7 = v10[4] >= v11;
      else
        v7 = v11 < v10[4];
      LOBYTE(v19) = v7;
      if ( v7 )
        v10 = *v10;
      else
        v10 = v10[2];
    }
    while ( !*(v10 + 13) );
    v6 = v18;
    v5 = v17;
  }
  v12 = v9;
  a3 = v9;
  if ( v7 )
  {
    if ( v9 == *v6 )
    {
      v13 = sub_FD98E0(v5, &a3, 1, v9, a4, a5);
LABEL_14:
      v14 = *v13;
      result = a2;
      *a2 = v14;
      *(a2 + 4) = 1;
      return result;
    }
    std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *>>>,std::_Iterator_base0>::operator--(&a3);
    v12 = a3;
  }
  if ( v12[4] < *v8 )
  {
    v13 = sub_FD98E0(v5, &a4, v19, v9, v8, a5);
    goto LABEL_14;
  }
  *a2 = v12;
  result = a2;
  *(a2 + 4) = 0;
  return result;
}
// 10081AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);

//----- (00FD9D20) --------------------------------------------------------
int MakeDriverName(wchar_t *pszText, wchar_t *lpszFormat, ...)
{
  va_list ArgList; // [esp+10h] [ebp+10h]

  va_start(ArgList, lpszFormat);
  return vswprintf_s(pszText, 10u, lpszFormat, ArgList);
}

//----- (00FD9D40) --------------------------------------------------------
int wsprintfW(wchar_t *Dst, wchar_t *Format, ...)
{
  va_list ArgList; // [esp+10h] [ebp+10h]

  va_start(ArgList, Format);
  return vswprintf_s(Dst, 0x1000u, Format, ArgList);
}

//----- (00FD9D60) --------------------------------------------------------
int sub_FD9D60(wchar_t *Dst, wchar_t *Format, ...)
{
  va_list ArgList; // [esp+10h] [ebp+10h]

  va_start(ArgList, Format);
  return vswprintf_s(Dst, 0x105u, Format, ArgList);
}

//----- (00FD9D80) --------------------------------------------------------
int wsprintf_s(wchar_t *Dst, wchar_t *Format, ...)
{
  va_list ArgList; // [esp+10h] [ebp+10h]

  va_start(ArgList, Format);
  return vswprintf_s(Dst, 0x20u, Format, ArgList);
}

//----- (00FD9DA0) --------------------------------------------------------
int sub_FD9DA0(wchar_t *Dst, wchar_t *Format, ...)
{
  va_list ArgList; // [esp+10h] [ebp+10h]

  va_start(ArgList, Format);
  return vswprintf_s(Dst, 0x32u, Format, ArgList);
}

//----- (00FD9DC0) --------------------------------------------------------
int MakeDeviceName(wchar_t *Dst, wchar_t *Format, ...)
{
  va_list ArgList; // [esp+10h] [ebp+10h]

  va_start(ArgList, Format);
  return vswprintf_s(Dst, 0x40u, Format, ArgList);
}

//----- (00FD9DE0) --------------------------------------------------------
int sub_FD9DE0(wchar_t *Dst, wchar_t *Format, ...)
{
  va_list ArgList; // [esp+10h] [ebp+10h]

  va_start(ArgList, Format);
  return vswprintf_s(Dst, 0x41u, Format, ArgList);
}

//----- (00FD9E00) --------------------------------------------------------
int *__thiscall sub_FD9E00(_DWORD *this, LPCWSTR lpWideCharStr)
{
  int *v2; // esi
  IAtlStringMgr *v3; // ecx
  CHAR *v4; // eax

  v2 = this;
  v3 = ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>::GetDefaultManager();
  if ( !v3 )
    ATL::AtlThrowImpl(E_FAIL);
  *v2 = (v3->vtptr->GetNilData)() + 16;
  if ( !lpWideCharStr || lpWideCharStr & 0xFFFF0000 )
  {
    sub_FD9FE0(v2, lpWideCharStr);
  }
  else
  {
    v4 = ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>::FindStringResourceInstance(lpWideCharStr, 0);
    if ( v4 )
      sub_FDF660(v2, v4, lpWideCharStr);
  }
  return v2;
}

//----- (00FD9EA0) --------------------------------------------------------
CString *__thiscall ATL::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>(CString *this, LPCSTR lpMultiByteStr)
{
  CString *v2; // esi
  IAtlStringMgr *v3; // ecx

  v2 = this;
  v3 = ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>::GetDefaultManager();
  if ( !v3 )
    ATL::AtlThrowImpl(0x80004005);
  v2->pszData = ((v3->vtptr->GetNilData)() + 16);
  ATL::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>::operator=(v2, lpMultiByteStr);
  return v2;
}

//----- (00FD9F20) --------------------------------------------------------
void __thiscall sub_FD9F20(void **this)
{
  void **v1; // eax
  _DWORD *v2; // ebx
  void *v3; // edi
  unsigned int v4; // esi
  int v5; // ecx
  void **v6; // [esp+4h] [ebp-4h]

  v1 = this;
  v6 = this;
  v2 = *this;
  if ( *this )
  {
    v3 = this[1];
    v4 = 0;
    if ( v3 )
    {
      do
      {
        v5 = v2[v4];
        if ( v5 )
          (*(*v5 + 8))(v2[v4]);
        ++v4;
      }
      while ( v4 < v3 );
      v1 = v6;
    }
    free(*v1);
  }
}

//----- (00FD9F70) --------------------------------------------------------
void __thiscall PerformanceInfoInMemory::~PerformanceInfoInMemory(PerformanceInfoInMemory *this)
{
  PerformanceInfoInMemory *v1; // esi

  v1 = this;
  j__free(this->m_pBuffer);
  v1->m_pBuffer = 0;
}

//----- (00FD9FB0) --------------------------------------------------------
void __thiscall sub_FD9FB0(CSystemProcessInfoMap *this)
{
  CSystemProcessInfoMap *v1; // esi
  int *a2; // [esp+4h] [ebp-4h]

  v1 = this;
  sub_FF5510(this, &a2, this->_Header->_Left, this->_Header);
  j__free(v1->_Header);
}

//----- (00FD9FE0) --------------------------------------------------------
int *__thiscall sub_FD9FE0(int *this, LPCWSTR lpWideCharStr)
{
  int *v2; // edi
  int v3; // esi
  int *result; // eax

  v2 = this;
  if ( lpWideCharStr && (v3 = WideCharToMultiByte(3u, 0, lpWideCharStr, -1, 0, 0, 0, 0) - 1, v3 > 0) )
  {
    if ( ((*(*v2 - 8) - v3) | (1 - *(*v2 - 4))) < 0 )
      sub_FE2330(v2, v3);
    WideCharToMultiByte(3u, 0, lpWideCharStr, -1, *v2, v3, 0, 0);
    if ( v3 > *(*v2 - 8) )
      ATL::AtlThrowImpl(-2147024809);
    *(*v2 - 12) = v3;
    *(v3 + *v2) = 0;
    result = v2;
  }
  else
  {
    sub_FDB8D0(v2);
    result = v2;
  }
  return result;
}

//----- (00FDA070) --------------------------------------------------------
char *__cdecl sub_FDA070(HWND hWnd, char a2, int a3, int a4, int a5, int a6, int a7, u_long hostlong, int a9, int port, int a11, int a12, int a13, int a14)
{
  const __m128i *v14; // esi
  const __m128i *v15; // edi
  int v16; // esi
  __int32 *v17; // edx
  _DWORD *v18; // ecx
  unsigned int v19; // edi
  bool v20; // cf
  LRESULT v21; // eax
  signed int v22; // eax
  int *v23; // edi
  const wchar_t *v24; // eax
  char *result; // eax
  int v26; // eax
  int v27; // edi
  _BYTE *v28; // edi
  char v29; // dl
  char v30; // al
  signed int v31; // ecx
  _DWORD *v32; // edx
  _DWORD *v33; // ecx
  unsigned int v34; // edi
  unsigned int v35; // kr00_4
  HWND v36; // ebx
  char v37; // [esp-890h] [ebp-13B0h]
  char v38; // [esp+Ch] [ebp-B14h]
  int v39; // [esp+10h] [ebp-B10h]
  int v40; // [esp+1Ch] [ebp-B04h]
  char v41; // [esp+30h] [ebp-AF0h]
  int v42; // [esp+34h] [ebp-AECh]
  int v43; // [esp+38h] [ebp-AE8h]
  __int128 v44; // [esp+3Ch] [ebp-AE4h]
  int v45; // [esp+254h] [ebp-8CCh]
  u_long v46; // [esp+460h] [ebp-6C0h]
  __int128 v47; // [esp+464h] [ebp-6BCh]
  int v48; // [esp+67Ch] [ebp-4A4h]
  int v49; // [esp+888h] [ebp-298h]
  int *v50; // [esp+88Ch] [ebp-294h]
  int v51; // [esp+890h] [ebp-290h]
  wchar_t *v52; // [esp+894h] [ebp-28Ch]
  LPARAM v53; // [esp+89Ch] [ebp-284h]
  int v54; // [esp+8A4h] [ebp-27Ch]
  const wchar_t *v55; // [esp+8B0h] [ebp-270h]
  LPARAM lParam; // [esp+8D0h] [ebp-250h]
  WPARAM wParam; // [esp+8D4h] [ebp-24Ch]
  int v58; // [esp+8D8h] [ebp-248h]
  int v59; // [esp+8F0h] [ebp-230h]
  const __m128i *v60; // [esp+904h] [ebp-21Ch]
  _BYTE *v61; // [esp+908h] [ebp-218h]
  int *v62; // [esp+90Ch] [ebp-214h]
  int v63; // [esp+910h] [ebp-210h]
  HWND v64; // [esp+914h] [ebp-20Ch]
  int v65; // [esp+918h] [ebp-208h]
  __int16 Dst[256]; // [esp+91Ch] [ebp-204h]

  v14 = a9;
  v65 = a4;
  v15 = a6;
  v62 = a12;
  v61 = a14;
  v64 = hWnd;
  v60 = a6;
  v63 = a9;
  lParam = 4;
  wParam = 0;
  v58 = 0;
  if ( !SendMessageW(hWnd, 0x104Bu, 0, &lParam) )
  {
LABEL_15:
    memset(&v38, 0, 0x890u);
    v39 = 5;
    v41 = 1;
    v22 = 2;
    v42 = a3;
    if ( a2 )
      v22 = 0;
    v40 = v22;
    v49 = v65;
    v43 = a5;
    if ( v15 )
      _mm_storeu_si128(&v44, _mm_loadu_si128(v15));
    v45 = a7;
    v46 = hostlong;
    if ( v14 )
      _mm_storeu_si128(&v47, _mm_loadu_si128(v14));
    v23 = v62;
    v48 = port;
    if ( gdwVersion >= 1 && !a13 && v62 )
    {
      if ( *v62 )
      {
        v24 = sub_FFEFB0(*v62);
        v52 = _wcsdup(v24);
      }
    }
    v50 = v23;
    v51 = a13;
    qmemcpy(&v37, &v38, 0x890u);
    return sub_FB7DD0(v64, v37);
  }
  while ( 1 )
  {
    if ( (v16 = v59, a3) && a3 != 1 || *(v59 + 44) == a5 )
    {
      if ( a3 == 2 || a3 == 3 )
      {
        v17 = v15;
        v18 = (v59 + 48);
        v19 = 12;
        while ( *v18 == *v17 )
        {
          ++v18;
          ++v17;
          v20 = v19 < 4;
          v19 -= 4;
          if ( v20 )
            goto LABEL_10;
        }
        goto LABEL_13;
      }
LABEL_10:
      if ( !*(v59 + 36) && *(v59 + 40) == a3 && *(v59 + 584) == a7 )
        break;
    }
LABEL_13:
    ++wParam;
    v21 = SendMessageW(v64, 0x104Bu, 0, &lParam);
    v15 = v60;
    if ( !v21 )
    {
      v14 = v63;
      goto LABEL_15;
    }
  }
  if ( a3 == 1 || a3 == 3 )
  {
LABEL_31:
    v26 = v65;
    goto LABEL_32;
  }
  if ( a3 )
  {
    if ( a3 != 2 )
      goto LABEL_41;
    v32 = v63;
    v33 = (v59 + 1112);
    v34 = 12;
    while ( *v33 == *v32 )
    {
      ++v33;
      ++v32;
      v20 = v34 < 4;
      v34 -= 4;
      if ( v20 )
        goto LABEL_41;
    }
    goto LABEL_31;
  }
  if ( *(v59 + 1108) != hostlong )
    goto LABEL_31;
LABEL_41:
  v26 = v65;
  if ( *(v59 + 2172) != v65 )
  {
    v27 = port;
LABEL_43:
    *(v59 + 2172) = v26;
    *(v16 + 1108) = hostlong;
    *(v16 + 1648) = v27;
    if ( a3 )
    {
      v54 = 2;
      v55 = L"*:*";
      SendMessageW(v64, 0x1074u, wParam, &v53);
    }
    else
    {
      sub_FC44B0(0, 1, 0, hostlong, v63, Dst, 0x100u);
      v35 = wcslen(Dst);
      sub_FC4670(1, v27, gszProtocolNames[0], &Dst[v35], 256 - v35);
      v36 = v64;
      v55 = Dst;
      v54 = 2;
      SendMessageW(v64, 0x1074u, wParam, &v53);
      v54 = 3;
      v55 = gszNetStatus[v65];
      SendMessageW(v36, 0x1074u, wParam, &v53);
    }
    v28 = v61;
    *v61 = 1;
    goto LABEL_34;
  }
LABEL_32:
  v27 = port;
  if ( *(v59 + 1648) != port )
    goto LABEL_43;
  v28 = v61;
LABEL_34:
  v29 = *(v16 + 24);
  v30 = 0;
  if ( v29 )
  {
    v31 = *(v16 + 28);
    if ( v31 < gConfig.dwHighlightDuration )
    {
      *(v16 + 16) = 2;
      result = 0;
      *(v16 + 20) = v31;
      *(v16 + 36) = 1;
      return result;
    }
    if ( v29 )
    {
      v30 = 1;
      *(v16 + 24) = 0;
    }
  }
  *(v16 + 16) = 0;
  if ( v30 )
    *v28 = 1;
  result = 0;
  *(v16 + 36) = 1;
  return result;
}
// 103E250: using guessed type wchar_t asc_103E250[4];
// 105D238: using guessed type wchar_t *gszNetStatus[13];
// 1064E54: using guessed type int gdwVersion;
// FDA070: using guessed type wchar_t Dst[256];

//----- (00FDA4A0) --------------------------------------------------------
CHAR *__thiscall sub_FDA4A0(CString *this, __int16 a2)
{
  CString *v2; // edi
  int v3; // ebx
  int v4; // esi
  CHAR *result; // eax

  v2 = this;
  v3 = *(this->pszData - 3);
  v4 = v3 + 1;
  if ( v3 + 1 < 0 )
    goto LABEL_9;
  if ( ((*(this->pszData - 2) - v4) | (1 - *(this->pszData - 1))) < 0 )
    ATL::CSimpleStringT<wchar_t,0>::PrepareWrite2(this, v3 + 1);
  *&v2->pszData[2 * v3] = a2;
  if ( v4 > *(v2->pszData - 2) )
LABEL_9:
    ATL::AtlThrowImpl(-2147024809);
  *(v2->pszData - 3) = v4;
  result = v2->pszData;
  *&v2->pszData[2 * v4] = 0;
  return result;
}

//----- (00FDA500) --------------------------------------------------------
int __cdecl sub_FDA500(SYSTEM_PROCESS_INFORMATION *pSystemProcessInfo)
{
  SYSTEM_PROCESS_INFORMATION *pNext; // eax
  ULONG NumberOfThreads; // ecx
  signed int v3; // edx
  PUCHAR pKernelTime; // eax
  unsigned int v5; // esi
  int v6; // kr00_4
  int result; // eax

  if ( GetVersion() <= 4u )
    pNext = (pSystemProcessInfo + 0x88);
  else
    pNext = pSystemProcessInfo + 1;
  NumberOfThreads = pSystemProcessInfo->NumberOfThreads;
  if ( !NumberOfThreads )
    goto __quit;
  v3 = 0;
  pKernelTime = &pNext->KernelTime;
  v5 = 0;
  do
  {
    v6 = *pKernelTime + v5;
    v3 = (*pKernelTime + __PAIR__(v3, v5)) >> 32;
    v5 += *pKernelTime;
    pKernelTime += 0x40;
    --NumberOfThreads;
  }
  while ( NumberOfThreads );
  if ( v3 >= 0 && (v3 > 0 || v6) )
    result = v6;
  else
__quit:
    result = 0;
  return result;
}

//----- (00FDA580) --------------------------------------------------------
int __stdcall pfnAclChangeCallback(HWND Owner, HANDLE Instance, PVOID CallbackContext, PSECURITY_DESCRIPTOR NewSD, PSECURITY_DESCRIPTOR NewObjectSD, BOOLEAN ApplyToSubContainers, BOOLEAN ApplyToSubObjects, PDWORD ChangeContextStatus)
{
  PVOID v8; // esi
  int v9; // eax
  int v10; // eax
  PDWORD v11; // eax
  void *v12; // edi
  int result; // eax
  unsigned int v14; // eax
  bool v15; // zf
  DWORD nLengthNeeded; // [esp+8h] [ebp-4h]

  v8 = CallbackContext;
  v9 = *(CallbackContext + 2);
  if ( v9 )
  {
    v10 = v9 - 1;
    if ( v10 )
    {
      if ( v10 == 1 )
      {
        CallbackContext = 1;
        v11 = 0x80000;
      }
      else
      {
        v11 = ChangeContextStatus;
      }
    }
    else
    {
      CallbackContext = 8;
      v11 = (&loc_FFFFFE + 2);
    }
  }
  else
  {
    CallbackContext = 4;
    v11 = 0x40000;
  }
  v12 = PE_DuplicateProcessHandle(*v8, *(v8 + 1), v11);
  if ( v12 )
  {
    if ( SetUserObjectSecurity(v12, &CallbackContext, NewSD) )
    {
      v14 = CallbackContext | 3;
      v15 = *(v8 + 2) == 2;
      CallbackContext = (CallbackContext | 3);
      if ( v15 )
        CallbackContext = (v14 | 4);
      **(v8 + 5) = GetUserObjectSecurity(v12, &CallbackContext, *(v8 + 4), 0x2000u, &nLengthNeeded);
    }
    else
    {
      MessageBoxW(0, L"Unable to modify the object's Security Information.", L"WinObj", 0x10u);
    }
    CloseHandle(v12);
    *ChangeContextStatus = 1;
    result = 0;
  }
  else
  {
    MessageBoxW(0, L"Unable to modify the object's Security Information.", L"WinObj", 0x10u);
    *ChangeContextStatus = 1;
    result = 0;
  }
  return result;
}

//----- (00FDA670) --------------------------------------------------------
HBRUSH __stdcall DlgDllInfo(HWND hWnd, UINT msg, WPARAM uID, DLLINFOLISTITEMPARAM *pListItem)
{
  DLLLISTITEMPARAM *pItemParam; // edi
  CResizer *v5; // eax
  CResizer *pResizer; // eax
  HWND v7; // eax
  struct tagResizerItem *v8; // eax
  HWND v9; // eax
  struct tagResizerItem *v10; // eax
  CHAR *psz; // eax
  const WCHAR *v12; // eax
  const WCHAR *v13; // ecx
  BOOL v14; // ST10_4
  HWND v15; // eax
  BOOL v16; // ST10_4
  HWND v17; // eax
  HICON v18; // ST10_4
  HWND v19; // eax
  HICON v20; // ST10_4
  HWND hWndParent; // eax
  const WCHAR *pszCompanyInfo; // ST10_4
  HWND v23; // eax
  HWND v24; // eax
  _WORD *v25; // eax
  HWND v26; // eax
  HWND v27; // eax
  CHAR *v28; // eax
  int v29; // ST10_4
  HWND v30; // eax
  const WCHAR *v31; // ecx
  wchar_t *v32; // eax
  int v34; // eax
  HWND v35; // eax
  const WCHAR *v36; // eax
  int v37; // eax
  char v38; // cl
  HWND v39; // eax
  int v40; // ST10_4
  HWND v41; // eax
  HWND v42; // eax
  WPARAM v43; // [esp-8h] [ebp-E38h]
  int v44; // [esp-4h] [ebp-E34h]
  CResizer *pResizer_1; // [esp+1Ch] [ebp-E14h]
  WCHAR szTitle[1024]; // [esp+20h] [ebp-E10h]
  WCHAR String[256]; // [esp+820h] [ebp-610h]
  WCHAR v48[256]; // [esp+A20h] [ebp-410h]
  WCHAR Dest[256]; // [esp+C20h] [ebp-210h]
  int v50; // [esp+E2Ch] [ebp-4h]

  pItemParam = GetWindowLongW(hWnd, GWLP_USERDATA);
  switch ( msg )
  {
    case WM_INITDIALOG:
      v5 = operator new(0x40u);
      v50 = 0;
      if ( v5 )
        pResizer = CResizer::CResizer(v5, hWnd);
      else
        pResizer = 0;
      pResizer_1 = pResizer;
      v50 = -1;
      pResizer->m_nXRatio = 85;
      pResizer->m_nYRatio = 100;
      v7 = GetDlgItem(hWnd, IDC_DLG_DLLINFO_EDIT_PATH);
      if ( v7 )
      {
        v8 = CResizer::AddItem(pResizer_1, v7, 1);
        *&v8->m_rect1.left = 0i64;
        *&v8->m_rect1.right = db_one;
      }
      v9 = GetDlgItem(hWnd, IDC_DLG_DLLINFO_EDIT_AUTOSTART_LOCATION);
      if ( v9 )
      {
        v10 = CResizer::AddItem(pResizer_1, v9, 1);
        *&v10->m_rect1.left = 0i64;
        *&v10->m_rect1.right = db_one;
      }
      SetWindowLongW(hWnd, GWLP_USERDATA, pListItem);
      if ( wcsrchr(pListItem->m_strPath.pszData, '\\') )
        psz = (wcsrchr(pListItem->m_strPath.pszData, '\\') + 1);
      else
        psz = pListItem->m_strPath.pszData;
      wsprintfW(szTitle, L"%s Properties", psz);
      SetWindowTextW(hWnd, szTitle);
      if ( pListItem->m_dwStyle & 4 )
        SetDlgItemTextW(hWnd, IDC_DLG_DLLINFO_STATIC_PATH, L"Path (Image is probably packed):");
      v12 = L"Data";
      if ( !(pListItem->m_dwStyle & 2) )
        v12 = L"Image";
      SetDlgItemTextW(hWnd, IDC_DLG_DLLINFO_STATIC_MAPPING_TYPE_VALUE, v12);
      SetDlgItemTextW(hWnd, IDC_DLG_DLLINFO_EDIT_PATH, pListItem->m_strPath.pszData);
      v13 = L"n/a";
      if ( pListItem->m_strLocation )
        v13 = pListItem->m_strLocation;
      SetDlgItemTextW(hWnd, IDC_DLG_DLLINFO_EDIT_AUTOSTART_LOCATION, v13);
      v14 = pListItem->m_strPath.pszData != 0;
      v15 = GetDlgItem(hWnd, IDC_DLG_DLLINFO_BUTTON_EXPLORE_PATH);
      EnableWindow(v15, v14);
      v16 = pListItem->m_strLocation != 0;
      v17 = GetDlgItem(hWnd, IDC_DLG_DLLINFO_BUTTON_EXPLORE_LOCATION);
      EnableWindow(v17, v16);
      v18 = LoadIconW(ghInstance, 154);
      v19 = GetParent(hWnd);
      SendMessageW(v19, WM_SETICON, 1u, v18);
      v20 = LoadIconW(ghInstance, 154);
      hWndParent = GetParent(hWnd);
      SendMessageW(hWndParent, WM_SETICON, 0, v20);
      if ( pListItem->m_strDescription )
        SetDlgItemTextW(hWnd, IDC_DLG_DLLINFO_EDIT_DESCRIPTION, pListItem->m_strDescription);
      else
        SetDlgItemTextW(hWnd, IDC_DLG_DLLINFO_EDIT_DESCRIPTION, L"n/a");
      if ( pListItem->m_strCompanyInfo )
      {
        pszCompanyInfo = VerifyImage(pListItem, gConfig.bVerifySignatures);
        SetDlgItemTextW(hWnd, IDC_DLG_DLLINFO_EDIT_COMPANY, pszCompanyInfo);
      }
      else
      {
        SetDlgItemTextW(hWnd, IDC_DLG_DLLINFO_EDIT_COMPANY, L"n/a");
      }
      v23 = GetDlgItem(hWnd, IDC_DLG_DLLINFO_STATIC_IMAGE_TYPE);
      ShowWindow(v23, 0);
      if ( gbWintrustInited )
      {
        if ( pListItem->field_160 || (v25 = pListItem->m_strCompanyInfo) == 0 || *v25 == '[' )
        {
          v26 = GetDlgItem(hWnd, IDC_DLG_DLLINFO_BUTTON_VERIFY);
          EnableWindow(v26, 0);
        }
      }
      else
      {
        v24 = GetDlgItem(hWnd, IDC_DLG_DLLINFO_BUTTON_VERIFY);
        ShowWindow(v24, 0);
      }
      v27 = GetDlgItem(hWnd, IDC_DLG_DLLINFO_EDIT_VIRUSTOTAL);
      SetWindowSubclass(v27, EditVTClassCallback, 0, 0);
      sub_1001A50(pListItem->m_ItemData1, Dest);
      SetDlgItemTextW(hWnd, IDC_DLG_DLLINFO_EDIT_VIRUSTOTAL, Dest);
      v28 = pListItem->m_strPath.pszData;
      if ( v28 && *v28 != '[' )
      {
        v29 = sub_1001C10(pListItem->m_ItemData1);
        v30 = GetDlgItem(hWnd, IDC_DLG_DLLINFO_BUTTON_SUBMIT);
        EnableWindow(v30, v29);
      }
      v31 = L"n/a";
      if ( pListItem->m_szVersion[0] )
        v31 = pListItem->m_szVersion;
      SetDlgItemTextW(hWnd, IDC_DLG_DLLINFO_EDIT_VERSION, v31);
      wsprintfW(szTitle, L"0x%X", pListItem->m_LoadAddress);
      SetDlgItemTextW(hWnd, IDC_DLG_DLLINFO_STATIC_LOAD_ADDRESS_VALUE, szTitle);
      wsprintfW(szTitle, L"0x%X bytes", pListItem->m_MappedSize);
      SetDlgItemTextW(hWnd, IDC_DLG_DLLINFO_STATIC_MAPED_SIZE_VALUE, szTitle);
      if ( pListItem->m_BuildTime )
        v32 = _wctime32(&pListItem->m_BuildTime);
      else
        v32 = L"n/a";
      SetDlgItemTextW(hWnd, IDC_DLG_DLLINFO_EDIT_BUILD_TIME, v32);
      SetTimer(hWnd, 0, 0x3E8u, 0);
      PropSheet_UpdateTab(hWnd);
      ShowWindow(hWnd, 1);
      return 1;
    case WM_COMMAND:
      if ( uID > IDC_DLG_DLLINFO_BUTTON_EXPLORE_PATH )
      {
        if ( uID > IDM_FILE_EXIT )
        {
          if ( uID - 40092 > 1 )
            return 0;
          v43 = uID;
        }
        else
        {
          if ( uID != IDM_FILE_EXIT )
          {
            if ( uID == IDC_DLG_DLLINFO_BUTTON_SUBMIT )
            {
              if ( !SubmitExeToVirusTotalDotCom() )
                return 1;
              v37 = pItemParam->m_HashData;
              v38 = 0;
              if ( v37 )
              {
                v38 = 1;
                *(v37 + 4) = 6;
              }
              sub_1001C30(pItemParam, ~(pItemParam->field_2C >> 1) & 1, v38 != 0);
              v39 = GetDlgItem(hWnd, IDC_DLG_DLLINFO_BUTTON_SUBMIT);
              EnableWindow(v39, 0);
              sub_1001A50(pItemParam->m_HashData, v48);
              v40 = sub_1001C10(pItemParam->m_HashData);
              v41 = GetDlgItem(hWnd, IDC_DLG_DLLINFO_BUTTON_SUBMIT);
              EnableWindow(v41, v40);
              SetDlgItemTextW(hWnd, IDC_DLG_DLLINFO_EDIT_VIRUSTOTAL, v48);
              PostMessageW(ghMainWnd, 0x7F9u, 0, pItemParam->m_HashData);
              return 1;
            }
            return 0;
          }
          v43 = 40014;
        }
        v42 = GetParent(hWnd);
        PostMessageW(v42, WM_COMMAND, v43, 0);
        return 0;
      }
      if ( uID == IDC_DLG_DLLINFO_BUTTON_EXPLORE_PATH )
      {
        sub_FAB780(hWnd, pItemParam->m_strPath);
        return 1;
      }
      if ( uID > 1005 )
      {
        if ( uID == IDC_DLG_DLLINFO_BUTTON_EXPLORE_LOCATION )
        {
          sub_FAB780(hWnd, pItemParam->m_strLocation);
          return 1;
        }
        return 0;
      }
      if ( uID != 1005 )
      {
        if ( uID != 1 )
        {
          if ( uID == 2 )
            return 1;
          return 0;
        }
        return 1;
      }
      v36 = VerifyImage(pItemParam, 1);
      SetDlgItemTextW(hWnd, 3, v36);
      v44 = 0;
      v35 = GetDlgItem(hWnd, IDC_DLG_DLLINFO_BUTTON_VERIFY);
LABEL_44:
      EnableWindow(v35, v44);
      return 1;
    case WM_TIMER:
      GetDlgItemTextW(hWnd, IDC_DLG_DLLINFO_EDIT_VIRUSTOTAL, String, 256);
      sub_1001A50(pItemParam->m_HashData, Dest);
      v34 = wcscmp(String, Dest);
      if ( v34 )
        v34 = -(v34 < 0) | 1;
      if ( !v34 )
        return 1;
      SetDlgItemTextW(hWnd, IDC_DLG_DLLINFO_EDIT_VIRUSTOTAL, Dest);
      v44 = sub_1001C10(pItemParam->m_HashData);
      v35 = GetDlgItem(hWnd, IDC_DLG_DLLINFO_BUTTON_SUBMIT);
      goto LABEL_44;
    case WM_CTLCOLORSTATIC:
      if ( pListItem != GetDlgItem(hWnd, IDC_DLG_DLLINFO_EDIT_VIRUSTOTAL) || !sub_1001820(pItemParam->m_HashData) )
        return 0;
      if ( sub_1002910(pItemParam->m_HashData) )
        SetTextColor(uID, 0xFFu);
      else
        SetTextColor(uID, 0xFF0000u);
      SelectObject(uID, ghDefaultUnderlineFontHandle);
      return GetSysColorBrush(COLOR_BTNHILIGHT);
    default:
      return 0;
  }
}
// 103E220: using guessed type wchar_t aData_0[5];
// 106A391: using guessed type char gbWintrustInited;

//----- (00FDADD0) --------------------------------------------------------
BOOL __stdcall ProcPropSheet(HWND hDlg, UINT uMsg, WPARAM wParam, PROPITEM *PropItem)
{
  LONG v4; // eax
  tagTREEVIEWLISTITEMPARAM **v5; // ebx
  HWND *v7; // esi
  signed int v8; // ebx
  LRESULT v9; // eax
  tagTREEVIEWLISTITEMPARAM *v10; // esi
  HWND v11; // eax
  int v12; // ecx
  HWND v13; // esi
  HWND *v14; // esi
  HWND v15; // ecx
  void (__stdcall *SendMessageW)(HWND, UINT, WPARAM, LPARAM); // esi
  WPARAM v17; // eax
  LRESULT v18; // eax
  WPARAM v19; // ecx
  _DWORD *i; // eax
  CResizer *pResizer; // eax
  HWND v22; // ebx
  bool v23; // zf
  void *v24; // eax
  wchar_t *v25; // eax
  HWND hDlgDllInfo; // eax
  UINT v27; // eax
  WPARAM v28; // ecx
  POINT v29; // ST10_8
  HCURSOR v30; // eax
  tagTCITEMW tcitem; // [esp+10h] [ebp-260h]
  struct tagPOINT Point; // [esp+2Ch] [ebp-244h]
  CResizer *hWnd; // [esp+34h] [ebp-23Ch]
  NMHDR lParam; // [esp+38h] [ebp-238h]
  HWND hWndTab; // [esp+44h] [ebp-22Ch]
  struct tagRECT Rect; // [esp+48h] [ebp-228h]
  WCHAR String; // [esp+58h] [ebp-218h]
  int v38; // [esp+26Ch] [ebp-4h]

  hWnd = hDlg;
  hWndTab = GetDlgItem(hDlg, IDS_PROCPROPSHEET_TABCTRL);
  v4 = GetWindowLongW(hDlg, GWLP_USERDATA);
  v5 = v4;
  if ( uMsg > WM_NOTIFY )
  {
    if ( uMsg == WM_INITDIALOG )
    {
      pResizer = operator new(0x40u);
      hWnd = pResizer;
      v38 = 0;
      if ( pResizer )
        CResizer::CResizer(pResizer, hDlg);
      SetWindowLongW(hDlg, GWLP_USERDATA, PropItem);
      v22 = hWndTab;
      tcitem.mask = 3;
      tcitem.iImage = -1;
      tcitem.pszText = L"Image";
      ::SendMessageW(hWndTab, TCM_INSERTITEMW, 0, &tcitem);
      wcscpy_s(PropItem->PageData[1].szTemplateName, 0x100u, L"PROCSTRINGS");
      PropItem->PageData[1].nTabId = 13;
      PropItem->PageData[1].PageWndProc = PageProcStrings;
      tcitem.pszText = L"Strings";
      ::SendMessageW(v22, TCM_INSERTITEMW, 1u, &tcitem);
      v23 = wcsrchr(*(PropItem->pListItem + 86), '\\') == 0;
      v24 = PropItem->pListItem;
      if ( v23 )
        v25 = *(v24 + 86);
      else
        v25 = wcsrchr(*(v24 + 86), '\\') + 1;
      swprintf(&String, L"%s Properties", v25);
      SetWindowTextW(hDlg, &String);
      hDlgDllInfo = CreateDialogParamW(ghMainInstance, L"DLLINFO", hDlg, DlgDllInfo, PropItem->pListItem);
      PropItem->PageData[0].hWnd = hDlgDllInfo;
      PropItem->PageData[0].nTabId = 1;
      ShowWindow(hDlgDllInfo, 5);
      SetForegroundWindow(hDlg);
      v27 = PropItem->PageData[0].nTabId;
      v28 = 0;
      if ( v27 )
      {
        while ( gConfig.dwDefaultDllPropPage != v27 )
        {
          v27 = *(&PropItem->nTabIndex + 131 * (++v28 + 1));
          if ( !v27 )
            goto LABEL_47;
        }
      }
      else
      {
LABEL_47:
        v28 = 0;
      }
      ::SendMessageW(v22, TCM_SETCURSEL, v28, 0);
      lParam.idFrom = 1110;
      lParam.code = TCN_SELCHANGE;
      ::SendMessageW(hDlg, WM_NOTIFY, 0, &lParam);
      if ( gConfig.WindowPlacement[3].rcNormalPosition.right == gConfig.WindowPlacement[3].rcNormalPosition.left )
      {
        GetCursorPos(&Point);
        v29.y = Point.y - 408;
        v29.x = Point.x - 385;
        PE_SetWindowPlacement(hDlg, v29);
      }
      else
      {
        sub_FEDC50(hDlg, PropItem->pListItem);
      }
      ShowWindow(hDlg, 5);
      InterlockedDecrement(&gnRefCount);
      v30 = LoadCursorW(0, 0x7F00);
      SetCursor(v30);
      return 1;
    }
    if ( uMsg == 273 )
    {
      if ( wParam > 40092 )
      {
        if ( wParam != 40093 )
          return 0;
        v18 = ::SendMessageW(hWndTab, TCM_GETCURSEL, 0, 0);
        v19 = v18 - 1;
        if ( !v18 )
        {
          v19 = 0;
          for ( i = v5 + 263; *i; ++v19 )
            i += 131;
        }
        SendMessageW = ::SendMessageW;
        ::SendMessageW(hWndTab, TCM_SETCURSEL, v19, 0);
      }
      else
      {
        if ( wParam != 40092 )
        {
          if ( wParam > 0 && (wParam <= 2 || wParam == 40014) )
          {
            v14 = (v4 + 8);
            v15 = 32;
            hWndTab = 32;
            while ( 1 )
            {
              if ( *v14 )
              {
                ::SendMessageW(*v14, WM_COMMAND, wParam, 0);
                DestroyWindow(*v14);
                v15 = hWndTab;
              }
              v14 += 131;
              v15 = (v15 - 1);
              hWndTab = v15;
              if ( !v15 )
              {
                DLLLISTITEMPARAM_Release(v5[1]);
                free(v5);
                GetWindowPlacement(hWnd, &gConfig.WindowPlacement[3]);
                DestroyWindow(hWnd);
                _endthread();
              }
            }
          }
          return 0;
        }
        SendMessageW = ::SendMessageW;
        v17 = ::SendMessageW(hWndTab, TCM_GETCURSEL, 0, 0) + 1;
        if ( !v5[131 * v17 + 132] )
          v17 = 0;
        ::SendMessageW(hWndTab, TCM_SETCURSEL, v17, 0);
      }
      lParam.idFrom = IDS_PROCPROPSHEET_TABCTRL;
      lParam.code = TCN_SELCHANGE;
      SendMessageW(hDlg, WM_NOTIFY, 0, &lParam);
    }
    return 0;
  }
  if ( uMsg == WM_NOTIFY )
  {
    if ( PropItem->pListItem == IDS_PROCPROPSHEET_TABCTRL && PropItem->PageData[0].hWnd == -0x227 )
    {
      v9 = ::SendMessageW(hWndTab, TCM_GETCURSEL, 0, 0);
      v10 = v9;
      v11 = &v5[131 * v9];
      gConfig.dwDefaultDllPropPage = *(v11 + 524);
      v12 = 131 * *v5;
      hWndTab = v11;
      ShowWindow(v5[v12 + 2], 0);
      *v5 = v10;
      v13 = hWndTab;
      if ( !*(hWndTab + 2) )
        *(hWndTab + 2) = CreateDialogParamW(ghMainInstance, hWndTab + 6, hDlg, *(hWndTab + 132), v5[1]);
      ShowWindow(*(v13 + 2), 5);
      return 0;
    }
    return 0;
  }
  if ( uMsg != WM_SIZE )
  {
    if ( uMsg == WM_GETMINMAXINFO )
    {
      PropItem->PageData[0].hWnd = (2 * gdwVirtualScreenWidth);
      return 0;
    }
    return 0;
  }
  v7 = (v4 + 8);
  v8 = 32;
  do
  {
    if ( *v7 )
    {
      GetWindowRect(hWndTab, &Rect);
      ::SendMessageW(hWndTab, TCM_ADJUSTRECT, 0, &Rect);
      MapWindowPoints(0, hDlg, &Rect, 2u);
      MoveWindow(*v7, Rect.left, Rect.top, Rect.right - Rect.left, Rect.bottom - Rect.top, 1);
    }
    v7 += 131;
    --v8;
  }
  while ( v8 );
  return 0;
}
// 100A009: using guessed type int _endthread(void);
// 10465E8: using guessed type wchar_t aStrings[8];
// 1064E28: using guessed type int gdwVirtualScreenWidth;

//----- (00FDB330) --------------------------------------------------------
signed int CDriver::Load()
{
  WCHAR szDirName[260]; // [esp+0h] [ebp-414h]
  WCHAR szPathName[260]; // [esp+208h] [ebp-20Ch]

  if ( !CDriver::Open(L"PROCEXP152", &ghDriverHandle) )
  {
    GetSystemDirectoryW(szDirName, MAX_PATH);
    swprintf(szPathName, L"%s\\Drivers\\%s", szDirName, L"PROCEXP152.SYS");
    if ( !CDriver::SaveDriverFromResource(0x96, szPathName) )
    {
      swprintf(szDirName, L"%%TEMP%%\\%s", L"PROCEXP152.SYS");
      ExpandEnvironmentStringsW(szDirName, szPathName, MAX_PATH);
      if ( !CDriver::SaveDriverFromResource(0x96, szPathName) )
      {
        GetCurrentDirectoryW(MAX_PATH, szDirName);
        swprintf(szPathName, L"%s\\s", szDirName, L"PROCEXP152.SYS");
        if ( !CDriver::SaveDriverFromResource(0x96, szPathName) )
          return 0;
      }
    }
    if ( !CDriver::OpenEx(L"PROCEXP152", szPathName, &ghDriverHandle) )
    {
      DeleteFileW(szPathName);
      return 0;
    }
    DeleteFileW(szPathName);
  }
  return 1;
}
// 1042E08: using guessed type wchar_t aProcexp152Sys[15];

//----- (00FDB490) --------------------------------------------------------
HCURSOR __cdecl sub_FDB490(HWND hWnd, int a2)
{
  HWND v2; // ST14_4
  HCURSOR result; // eax
  HCURSOR v4; // edi
  int v5; // ecx
  HCURSOR v6; // eax
  void *v7; // eax
  HANDLE v8; // eax
  void *v9; // eax
  ULONG v10; // esi
  void *v11; // eax
  int v12; // eax
  PRTL_DEBUG_BUFFER v13; // eax
  int v14; // ecx
  void *v15; // esi
  HWND v16; // ST10_4
  int v17; // edi
  HCURSOR v18; // eax
  unsigned int v19; // esi
  unsigned int v20; // eax
  int v21; // eax
  int v22; // eax
  DWORD ThreadId; // [esp+8h] [ebp-4ECh]
  LPARAM lParam; // [esp+Ch] [ebp-4E8h]
  HCURSOR v25; // [esp+10h] [ebp-4E4h]
  int v26; // [esp+14h] [ebp-4E0h]
  int v27; // [esp+18h] [ebp-4DCh]
  int v28; // [esp+1Ch] [ebp-4D8h]
  wchar_t *v29; // [esp+20h] [ebp-4D4h]
  int v30; // [esp+28h] [ebp-4CCh]
  int v31; // [esp+2Ch] [ebp-4C8h]
  int v32; // [esp+40h] [ebp-4B4h]
  PRTL_DEBUG_BUFFER v33; // [esp+44h] [ebp-4B0h]
  DWORD ExitCode; // [esp+48h] [ebp-4ACh]
  HWND v35; // [esp+4Ch] [ebp-4A8h]
  char ArgList[4]; // [esp+50h] [ebp-4A4h]
  ULONG ReturnLength; // [esp+54h] [ebp-4A0h]
  HCURSOR hCursor; // [esp+58h] [ebp-49Ch]
  char v39; // [esp+5Fh] [ebp-495h]
  char v40; // [esp+60h] [ebp-494h]
  int v41; // [esp+8Ch] [ebp-468h]
  char v42; // [esp+94h] [ebp-460h]
  wchar_t Dst; // [esp+2F0h] [ebp-204h]

  v35 = hWnd;
  *ArgList = 0;
  hCursor = 0;
  v39 = 0;
  SendMessageW(hWnd, 0x1009u, 0, 0);
  v2 = *(a2 + 4);
  v41 = 0;
  result = SendMessageW(v2, 0x100Cu, 0xFFFFFFFF, 2);
  v25 = result;
  if ( result != -1 )
  {
    if ( !*(a2 + 20) )
    {
      GetSystemProcessInfo(&hCursor, 0);
      v4 = hCursor;
      v5 = *(*a2 + 68);
      if ( *(hCursor + 17) != v5 )
      {
        while ( *v4 )
        {
          v4 = (v4 + *v4);
          if ( *(v4 + 17) == v5 )
            goto LABEL_8;
        }
        v4 = 0;
      }
LABEL_8:
      v6 = LoadCursorW(0, 0x7F02);
      SetCursor(v6);
      *(a2 + 12) = OpenProcess(0x80000000, 0, *(*a2 + 68));
      if ( SymInitialize )
      {
        EnterCriticalSection(&gProcThreadsLock);
        v39 = 1;
        SymSetOptions(0x10027u);
        v7 = *(a2 + 12);
        if ( v7 )
          *(a2 + 20) = SymInitialize(v7, 0, 1);
        if ( !*(a2 + 20) )
        {
          if ( *(a2 + 12) )
            CloseHandle(*(a2 + 12));
          v8 = GetCurrentProcess();
          *(a2 + 12) = v8;
          *(a2 + 20) = SymInitialize(v8, 0, 1);
        }
      }
      ReturnLength = 1000;
      v9 = malloc(0x3E8u);
      *(a2 + 8) = v9;
      if ( NtQuerySystemInformation(SystemModuleInformation, v9, 0x3E8u, &ReturnLength) )
      {
        do
        {
          free(*(a2 + 8));
          ReturnLength += 1000;
          v10 = ReturnLength;
          v11 = malloc(ReturnLength);
          *(a2 + 8) = v11;
        }
        while ( NtQuerySystemInformation(SystemModuleInformation, v11, v10, &ReturnLength) );
      }
      v12 = *a2;
      *(a2 + 16) = 0;
      if ( !(*(v12 + 40) & 0x10) )
      {
        v13 = RtlCreateQueryDebugBuffer(0, 0);
        *(a2 + 16) = v13;
        if ( v13 )
        {
          v14 = *(v4 + 17);
          v33 = v13;
          v32 = v14;
          v15 = _beginthreadex(0, 0, QueryProcessDebugInforThreadProc, &v32, 0, &ThreadId);
          if ( WaitForSingleObject(v15, 0xFA0u) == 258 )
            TerminateThread(v15, 1u);
          GetExitCodeThread(v15, &ExitCode);
          if ( ExitCode )
          {
            RtlDestroyQueryDebugBuffer(*(a2 + 16));
            *(a2 + 16) = 0;
          }
          CloseHandle(v15);
        }
      }
    }
    v26 = 0;
    v16 = *(a2 + 4);
    lParam = 4;
    SendMessageW(v16, 0x104Bu, 0, &lParam);
    v17 = v31;
    v18 = LoadCursorW(0, 0x7F02);
    v19 = 0;
    hCursor = SetCursor(v18);
    if ( *(v17 + 2180) & 0xFFFFFFFC )
    {
      do
      {
        v20 = *(*(v17 + 2176) + 4 * v19);
        if ( v20 && v20 != -1 )
        {
          sub_FDDD60(1, v20, &v40, *(a2 + 12), 0, 0, *(a2 + 16), *(a2 + 8));
          v21 = wcscmp(&v42, L"0x0");
          if ( v21 )
            v21 = -(v21 < 0) | 1;
          if ( v21 )
          {
            lParam = 5;
            v25 = 0x7FFFFFFF;
            v26 = 0;
            v28 = 0;
            v27 = 0;
            wsprintf(&Dst, L"%d", ArgList[0]);
            v30 = 0;
            v29 = &Dst;
            v22 = *ArgList + 1;
            *ArgList = v22;
            v31 = v22;
            result = SendMessageW(v35, 0x104Du, 0, &lParam);
            if ( result == -1 )
              return result;
            v25 = result;
            v29 = &v42;
            lParam = 1;
            v26 = 1;
            SendMessageW(v35, 0x104Cu, 0, &lParam);
          }
        }
        ++v19;
      }
      while ( v19 < *(v17 + 2180) >> 2 );
    }
    if ( v39 )
      LeaveCriticalSection(&gProcThreadsLock);
    result = SetCursor(hCursor);
  }
  return result;
}
// 1045208: using guessed type wchar_t a0x0[4];
// 106F264: using guessed type int (__stdcall *RtlDestroyQueryDebugBuffer)(_DWORD);

//----- (00FDB8D0) --------------------------------------------------------
_BYTE *__thiscall sub_FDB8D0(_DWORD *this)
{
  _DWORD *v1; // esi
  _BYTE *result; // eax
  volatile signed __int32 *v3; // edx
  volatile signed __int32 v4; // edi

  v1 = this;
  result = *this;
  v3 = (*this - 16);
  v4 = *v3;
  if ( *(*this - 12) )
  {
    if ( *(v3 + 3) >= 0 )
    {
      if ( _InterlockedDecrement(v3 + 3) <= 0 )
        (*(**v3 + 4))(v3);
      result = ((*(*v4 + 12))(v4) + 16);
      *v1 = result;
    }
    else
    {
      if ( *(result - 2) < 0 )
        ATL::AtlThrowImpl(-2147024809);
      *(result - 3) = 0;
      result = *this;
      **this = 0;
    }
  }
  return result;
}

//----- (00FDB930) --------------------------------------------------------
void __cdecl QueryProcessCommandLineArgs(HANDLE hProcess, LPCVOID lpBaseAddress, WCHAR **ppCommandBuffer, WCHAR **ppszCurrentDirectory, WCHAR **ppszEnvBlock)
{
  BOOL (__stdcall *ReadProcessMemory)(HANDLE, LPCVOID, LPVOID, SIZE_T, SIZE_T *); // edi
  SIZE_T v6; // edi
  void *CommandBuffer; // esi
  SIZE_T BufLen; // ST0C_4
  SIZE_T v9; // edi
  SIZE_T v10; // ST0C_4
  signed int dwEnvironmentBufLen; // esi
  unsigned __int16 *v12; // esi
  size_t v13; // edi
  CHAR *v14; // esi
  size_t v15; // edi
  WCHAR *v16; // eax
  CStringData *v17; // esi
  SIZE_T dwRet; // [esp+18h] [ebp-80514h]
  CString strText; // [esp+1Ch] [ebp-80510h]
  _PEB Peb; // [esp+20h] [ebp-8050Ch]
  _RTL_USER_PROCESS_PARAMETERS ProcessParameters; // [esp+270h] [ebp-802BCh]
  __int16 szEnvironmentBuffer[262144]; // [esp+518h] [ebp-80014h]
  int v23; // [esp+80518h] [ebp-14h]
  int v24; // [esp+80528h] [ebp-4h]

  ReadProcessMemory = ::ReadProcessMemory;
  strText.pszData = ppszCurrentDirectory;
  if ( ::ReadProcessMemory(hProcess, lpBaseAddress, &Peb, 592u, &dwRet)
    && ::ReadProcessMemory(hProcess, Peb.ProcessParameters, &ProcessParameters, 680u, &dwRet)
    && ProcessParameters.CommandLine.Buffer )
  {
    if ( ppCommandBuffer )
    {
      v6 = ProcessParameters.CommandLine.Length;
      CommandBuffer = malloc(ProcessParameters.CommandLine.Length + 2);
      BufLen = v6;
      ReadProcessMemory = ::ReadProcessMemory;
      if ( !::ReadProcessMemory(hProcess, ProcessParameters.CommandLine.Buffer, CommandBuffer, BufLen, &dwRet) )
      {
LABEL_6:
        j__free(CommandBuffer);
        return;
      }
      *(CommandBuffer + (ProcessParameters.CommandLine.Length >> 1)) = 0;
      *ppCommandBuffer = CommandBuffer;
      j__free(0);
    }
    if ( strText.pszData )
    {
      v9 = ProcessParameters.CurrentDirectory.DosPath.Length;
      CommandBuffer = malloc(ProcessParameters.CurrentDirectory.DosPath.Length + 2);
      v10 = v9;
      ReadProcessMemory = ::ReadProcessMemory;
      if ( !::ReadProcessMemory(hProcess, ProcessParameters.CurrentDirectory.DosPath.Buffer, CommandBuffer, v10, &dwRet) )
        goto LABEL_6;
      *(CommandBuffer + (ProcessParameters.CurrentDirectory.DosPath.Length >> 1)) = 0;
      *strText.pszData = CommandBuffer;
      j__free(0);
    }
    if ( ppszEnvBlock )
    {
      dwEnvironmentBufLen = 0x80000;
      while ( !ReadProcessMemory(
                 hProcess,
                 ProcessParameters.Environment,
                 szEnvironmentBuffer,
                 dwEnvironmentBufLen,
                 &dwRet) )
      {
        dwEnvironmentBufLen -= 4096;
        if ( dwEnvironmentBufLen <= 0 )
          return;
      }
      if ( dwEnvironmentBufLen > 0 )
      {
        v23 = 0;
        ATL::CSimpleStringT<wchar_t,0>::CSimpleStringT<wchar_t,0>(&strText);
        v12 = szEnvironmentBuffer;
        v24 = 0;
        if ( szEnvironmentBuffer[0] )
        {
          do
          {
            if ( *v12 == 61 )
            {
              do
                ++v12;
              while ( *v12 );
            }
            else
            {
              v13 = wcslen(v12);
              sub_FADB80(&strText, v12, v13);
              sub_FDA4A0(&strText, 0);
              v12 += v13;
            }
            ++v12;
          }
          while ( *v12 );
        }
        v14 = strText.pszData;
        v15 = 2 * *(strText.pszData - 3) + 2;
        v16 = malloc(v15);
        *ppszEnvBlock = v16;
        memmove_0(v16, v14, v15);
        v17 = (v14 - 16);
        v24 = -1;
        if ( _InterlockedDecrement(&v17->nRefs) <= 0 )
          (v17->pStringMgr->vtptr->Free)(v17);
      }
    }
  }
}

//----- (00FDBBC0) --------------------------------------------------------
int __stdcall FindDlg_SortCallback(int a1, int a2, int a3)
{
  int v3; // eax
  int v4; // ecx

  if ( a3 )
  {
    if ( a3 == 1 )
    {
      v4 = *(a1 + 168) - *(a2 + 168);
      goto LABEL_9;
    }
    if ( a3 == 2 )
      v3 = _wcsicmp((a1 + 40), (a2 + 40));
    else
      v3 = _wcsicmp(*(a1 + 180), *(a2 + 180));
  }
  else
  {
    v3 = _wcsicmp(*(a1 + 36), *(a2 + 36));
  }
  v4 = v3;
LABEL_9:
  if ( !byte_105E8B0 )
    v4 = -v4;
  return v4;
}
// FDBBC0: using guessed type int __stdcall FindDlg_SortCallback(int, int, int);
// 105E8B0: using guessed type char byte_105E8B0;

//----- (00FDBC30) --------------------------------------------------------
HANDLE __stdcall FindExecutableImageExW_1(PCWSTR FileName, PCWSTR SymbolPath, PWSTR ImageFilePath, PFIND_EXE_FILE_CALLBACKW Callback, PVOID CallerData)
{
  return FindExecutableImageExW(FileName, SymbolPath, ImageFilePath, 0, 0);
}

//----- (00FDBC50) --------------------------------------------------------
int __stdcall sub_FDBC50(LPCWSTR a1, LPCWSTR a2, int a3)
{
  int *SymbolPath; // esi
  int *FileName; // eax
  int v5; // eax
  int v6; // edi
  int v7; // ebx
  int v8; // edx
  int v10; // [esp+10h] [ebp-124h]
  int v11; // [esp+14h] [ebp-120h]
  CHAR MultiByteStr; // [esp+18h] [ebp-11Ch]
  LPWSTR lpWideCharStr; // [esp+120h] [ebp-14h]
  int v14; // [esp+130h] [ebp-4h]

  lpWideCharStr = a3;
  v14 = 0;
  SymbolPath = sub_FD9E00(&v11, a2);
  LOBYTE(v14) = 1;
  FileName = sub_FD9E00(&v10, a1);
  LOBYTE(v14) = 2;
  v5 = FindExecutableImage(*FileName, *SymbolPath, &MultiByteStr);
  v6 = v10 - 16;
  LOBYTE(v14) = 1;
  v7 = v5;
  if ( _InterlockedDecrement((v10 - 16 + 12)) <= 0 )
    (*(**v6 + 4))(v6);
  v8 = v11 - 16;
  LOBYTE(v14) = 0;
  if ( _InterlockedDecrement((v11 - 16 + 12)) <= 0 )
    (*(**v8 + 4))(v8);
  MultiByteToWideChar(0, 0, &MultiByteStr, 261, lpWideCharStr, 261);
  return v7;
}

//----- (00FDBD50) --------------------------------------------------------
int __userpurge FindDlg_SearchThreadProc@<eax>(signed int a1@<ebx>, _BYTE *wParam)
{
  HWND v2; // eax

  CMainWnd::RefreshDllsView(a1, ghWndListInFindDlg, 0, wParam);
  CMainWnd::RefreshHandlesView(a1, ghWndListInFindDlg, 0, wParam);
  v2 = GetParent(ghWndListInFindDlg);
  PostMessageW(v2, 0x464u, 0, 0);
  return 0;
}

//----- (00FDBDA0) --------------------------------------------------------
HWND __cdecl sub_FDBDA0(HWND hWndParent)
{
  HWND v1; // eax
  HWND result; // eax

  v1 = FindWindowExW(hWndParent, 0, 0, L"OK");
  if ( v1 )
    ShowWindow(v1, 0);
  result = FindWindowExW(hWndParent, 0, 0, L"Cancel");
  if ( result )
    result = SetWindowTextW(result, L"&OK");
  return result;
}

//----- (00FDBDF0) --------------------------------------------------------
int *__thiscall sub_FDBDF0(int *this, int a2)
{
  volatile signed __int32 *v2; // esi
  int v3; // ebx
  int (__thiscall ***v4)(_DWORD, int, signed int); // eax
  int v5; // edi
  int v6; // eax
  int v7; // ebx
  int *result; // eax
  int *v9; // [esp+Ch] [ebp-8h]
  int v10; // [esp+10h] [ebp-4h]
  int v11; // [esp+1Ch] [ebp+8h]

  v9 = this;
  v2 = (*this - 16);
  v3 = *(v2 + 1);
  v10 = *(v2 + 1);
  v4 = (*(**v2 + 16))();
  v5 = a2;
  v6 = (**v4)(v4, a2, 1);
  v11 = v6;
  if ( !v6 )
    ATL::CSimpleStringT<wchar_t,0>::ThrowMemoryException();
  if ( v3 < v5 )
    v5 = v3;
  v7 = v6 + 16;
  memcpy_s((v6 + 16), v5 + 1, (v2 + 4), v5 + 1);
  *(v11 + 4) = v10;
  if ( _InterlockedDecrement(v2 + 3) <= 0 )
    (*(**v2 + 4))(v2);
  result = v9;
  *v9 = v7;
  return result;
}

//----- (00FDBE70) --------------------------------------------------------
HLOCAL __cdecl sub_FDBE70(wchar_t *Dst, size_t SizeInWords)
{
  int v2; // ecx
  DWORD v3; // eax
  WCHAR Buffer[2]; // [esp+0h] [ebp-4h]

  *Buffer = v2;
  v3 = GetLastError();
  FormatMessageW(0x1100u, 0, v3, 0x400u, Buffer, 0, 0);
  swprintf_s(Dst, SizeInWords, L"%s", *Buffer);
  return LocalFree(*Buffer);
}

//----- (00FDBEC0) --------------------------------------------------------
int __cdecl sub_FDBEC0(int a1, int a2, wchar_t *Dst, size_t SizeInWords)
{
  return swprintf_s(Dst, SizeInWords, L"%d.%d.%d.%d", a2 >> 16, a2, a1 >> 16, a1);
}

//----- (00FDBEF0) --------------------------------------------------------
unsigned int __cdecl Fake_GetProcessMitigationPolicy(tagTREEVIEWLISTITEMPARAM *pItem, HANDLE ProcessHandle)
{
  HANDLE v2; // esi
  int (__stdcall *pfnGetProcessMitigationPolicy)(HANDLE, _PROCESS_MITIGATION_POLICY, PVOID, SIZE_T); // eax
  HMODULE v4; // eax
  unsigned int result; // eax
  _PROCESS_MITIGATION_DEP_POLICY Policy; // [esp+4h] [ebp-10h]
  DWORD Flags; // [esp+Ch] [ebp-8h]
  unsigned int ret; // [esp+10h] [ebp-4h]

  v2 = ProcessHandle;
  LOBYTE(ret) = -1;
  if ( !ProcessHandle )
    return ret;
  if ( gdwVersion >= WINDOWS_8 )
  {
    pfnGetProcessMitigationPolicy = GetProcessMitigationPolicy;
    if ( !GetProcessMitigationPolicy )
    {
      v4 = GetModuleHandleW(L"KERNEL32.DLL");
      pfnGetProcessMitigationPolicy = GetProcAddress(v4, "GetProcessMitigationPolicy");
      GetProcessMitigationPolicy = pfnGetProcessMitigationPolicy;
      if ( !pfnGetProcessMitigationPolicy )
      {
        SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
        return ret;
      }
    }
    if ( pfnGetProcessMitigationPolicy(v2, ProcessDEPPolicy, &Policy, 8) )
    {
      result = 0;
      if ( Policy.DUMMYUNIONNAME.Flags & 1 )
        result = 1;
      if ( Policy.DUMMYUNIONNAME.Flags & 2 )
        result |= 4u;
      if ( Policy.Permanent )
        result |= 8u;
      return result;
    }
    return ret;
  }
  if ( gdwVersion < 2 )
  {
    if ( gdwVersion < 1 )
    {
      DeviceIoControl(
        ghDriverHandle,
        CTRLCODE_QUERY_PROCESS_DEPPOLICY,
        &ProcessHandle,
        4u,
        &ret,
        4u,
        &Policy.Permanent,
        0);
      return ret;
    }
    if ( NtQueryInformationProcess(ProcessHandle, ProcessExecuteFlags, &ret, 4u, 0) )
      return ret;
    result = ret & 0xFFFFFF0B;
    ret &= 0xFFFFFF0B;
    if ( ret & 2 )
      result &= 0xFFFFFFF6;
  }
  else
  {
    if ( !Fake_GetProcessDEPPolicy(ProcessHandle, &Flags, &Policy.Permanent) )
      return ret;
    result = 0;
    if ( Flags & 1 )
      result = 1;
    if ( Flags & 2 )
      result |= 4u;
    if ( *&Policy.Permanent )
      result |= 8u;
  }
  return result;
}
// 1064E54: using guessed type int gdwVersion;

//----- (00FDC020) --------------------------------------------------------
int __stdcall BackendQueryObjectThreadProc(void *a1)
{
  ULONG ReturnedLength; // [esp+4h] [ebp-4h]

  while ( !WaitForSingleObject(lpName, 0xFFFFFFFF) )
  {
    ReturnedLength = gObjectNameInformation->Name.Length + 8;
    gulQueryObjectResult = NtQueryObject(
                             Handle,
                             ObjectNameInformation,
                             gObjectNameInformation,
                             ReturnedLength,
                             &ReturnedLength);
    SetEvent(hHandle);
  }
  return 0;
}
// 106ABA0: using guessed type int gulQueryObjectResult;

//----- (00FDC090) --------------------------------------------------------
int __stdcall sub_FDC090(DWORD nLengthNeeded)
{
  DWORD v1; // edi
  DWORD v2; // edx
  signed int v3; // eax
  signed int v4; // esi
  void *v5; // ebx
  BOOL v6; // esi
  int result; // eax

  v1 = nLengthNeeded;
  v2 = 0;
  v3 = 1;
  v4 = 32;
  do
  {
    if ( *(nLengthNeeded + 4) & v3 )
    {
      switch ( v3 )
      {
        case 1:
          v2 |= 0xE0000u;
          break;
        case 4:
        case 16:
          v2 |= 0x60000u;
          break;
        case 8:
          v2 |= 0x1000000u;
          break;
        default:
          break;
      }
    }
    v3 = __ROL4__(v3, 1);
    --v4;
  }
  while ( v4 );
  v5 = PE_DuplicateProcessHandle(*(*nLengthNeeded + 36), *(*nLengthNeeded + 44), v2);
  if ( v5 )
  {
    GetKernelObjectSecurity(v5, *(v1 + 4), 0, 0, &nLengthNeeded);
    **(v1 + 8) = LocalAlloc(0x40u, nLengthNeeded);
    v6 = GetKernelObjectSecurity(v5, *(v1 + 4), **(v1 + 8), nLengthNeeded, &nLengthNeeded);
    CloseHandle(v5);
    if ( v6 )
    {
      result = 0;
      *(v1 + 12) = 0;
    }
    else
    {
      *(v1 + 12) = GetLastError();
      result = 0;
    }
  }
  else
  {
    *(v1 + 12) = 6;
    result = 0;
  }
  return result;
}

//----- (00FDC190) --------------------------------------------------------
LPVOID __cdecl sub_FDC190(LPCVOID pBlock, int a2, unsigned __int16 a3, int a4)
{
  BOOL v4; // eax
  BOOL v5; // ecx
  LPVOID result; // eax
  unsigned int puLen; // [esp+10h] [ebp-228h]
  LPVOID lpBuffer; // [esp+14h] [ebp-224h]
  BOOL v9; // [esp+18h] [ebp-220h]
  WCHAR SubBlock; // [esp+1Ch] [ebp-21Ch]
  CPPEH_RECORD ms_exc; // [esp+220h] [ebp-18h]

  v9 = 0;
  wsprintf(&SubBlock, L"\\StringFileInfo\\%04X%04X\\%s", a2, a3, a4);
  ms_exc.registration.TryLevel = 0;
  v4 = VerQueryValueW(pBlock, &SubBlock, &lpBuffer, &puLen);
  v5 = v4;
  v9 = v4;
  ms_exc.registration.TryLevel = -2;
  result = lpBuffer;
  if ( !v5 )
    result = 0;
  return result;
}

//----- (00FDC270) --------------------------------------------------------
__int16 *__cdecl sub_FDC270(int a1, rsize_t SizeInWords)
{
  __int16 *v2; // ecx
  __int16 v3; // ax
  int v4; // edi
  __int16 *v5; // ecx
  __int16 v6; // ax
  wchar_t *v7; // esi

  if ( !*GetLongPathNameW )
    return *a1;
  v2 = *a1;
  do
  {
    v3 = *v2;
    ++v2;
  }
  while ( v3 );
  if ( SizeInWords <= ((v2 - *a1 - 2) >> 1) + 1 )
  {
    v5 = *a1;
    do
    {
      v6 = *v5;
      ++v5;
    }
    while ( v6 );
    v4 = ((v5 - *a1 - 2) >> 1) + 1;
  }
  else
  {
    v4 = SizeInWords;
  }
  v7 = malloc(2 * v4);
  wcscpy_s(v7, v4, *a1);
  GetLongPathNameW(v7, *a1, SizeInWords);
  j__free(v7);
  return *a1;
}

//----- (00FDC350) --------------------------------------------------------
void __cdecl PE_GetFullPathName(LPCWSTR *ppszShortPath)
{
  DWORD v1; // eax
  DWORD cbSize; // ebx
  WCHAR *pszLongPathName; // ST1C_4

  if ( *GetLongPathNameW )
  {
    v1 = GetLongPathNameW(*ppszShortPath, 0, 0);
    cbSize = v1;
    if ( v1 )
    {
      pszLongPathName = malloc(2 * v1 + 2);
      GetLongPathNameW(*ppszShortPath, pszLongPathName, cbSize + 1);
      free(*ppszShortPath);
      *ppszShortPath = pszLongPathName;
      j__free(0);
    }
  }
}

//----- (00FDC3E0) --------------------------------------------------------
int __stdcall QueryProcessDebugInforThreadProc(_DWORD *a1)
{
  return RtlQueryProcessDebugInformation(*a1, 1, a1[1]);
}
// 106F260: using guessed type int (__stdcall *RtlQueryProcessDebugInformation)(_DWORD, _DWORD, _DWORD);

//----- (00FDC400) --------------------------------------------------------
char __cdecl sub_FDC400(int *a1, _DWORD *a2)
{
  int v2; // ecx
  int v3; // edx
  int v4; // ebx
  int v6; // edi
  int *v7; // esi
  int v8; // eax
  unsigned int v9; // ecx
  bool v10; // cf
  bool v11; // zf
  DWORD v12; // eax
  DWORD v13; // esi
  DWORD v14; // edi
  DWORD v15; // ecx
  bool v16; // bl
  bool v17; // dl
  int v18; // [esp+8h] [ebp-Ch]
  int v19; // [esp+Ch] [ebp-8h]
  int v20; // [esp+10h] [ebp-4h]
  unsigned int v21; // [esp+1Ch] [ebp+8h]

  v2 = 0;
  v3 = 0;
  v4 = 0;
  v20 = 0;
  v18 = 0;
  v19 = 0;
  if ( !a1 )
    return 0;
  v6 = *a1;
  if ( *a1 )
  {
    v7 = a1 + 1;
    do
    {
      v8 = *v7;
      v21 = *v7 & 0xFFFFF000;
      v2 = v20;
      if ( v21 >= a2[9] )
      {
        v9 = a2[9] + a2[14];
        v10 = v21 < v9;
        v11 = v21 == v9;
        v2 = v20;
        if ( v10 || v11 )
        {
          v2 = v20++ + 1;
          if ( v8 & 0x100 )
          {
            ++v18;
            if ( (*v7 & 0xE0u) > 0x20 )
              ++v19;
          }
          else
          {
            ++v4;
          }
        }
      }
      ++v7;
      --v6;
    }
    while ( v6 );
    v3 = v19;
  }
  v12 = v2 * gSystemInfo.dwPageSize;
  v13 = v18 * gSystemInfo.dwPageSize;
  v14 = v3 * gSystemInfo.dwPageSize;
  v15 = v4 * gSystemInfo.dwPageSize;
  v11 = v12 == a2[92];
  a2[92] = v12;
  v16 = !v11;
  v11 = v15 == a2[93];
  a2[93] = v15;
  v17 = !v11;
  v11 = v13 == a2[94];
  a2[94] = v13;
  LOBYTE(v12) = v14 != a2[95];
  a2[95] = v14;
  return v16 | v17 | !v11 | v12;
}

//----- (00FDC4F0) --------------------------------------------------------
char __cdecl sub_FDC4F0(LPVOID lpInBuffer, int a2, int a3, int a4)
{
  char v4; // bl
  HANDLE v6; // eax
  BOOL (__stdcall *DeviceIoControl)(HANDLE, DWORD, LPVOID, DWORD, LPVOID, DWORD, LPDWORD, LPOVERLAPPED); // esi
  int v8; // eax
  char v9; // [esp+8h] [ebp-78h]
  int v10; // [esp+18h] [ebp-68h]
  struct _OVERLAPPED Overlapped; // [esp+20h] [ebp-60h]
  DWORD InBuffer; // [esp+34h] [ebp-4Ch]
  int v13; // [esp+38h] [ebp-48h]
  char v14; // [esp+3Ch] [ebp-44h]
  HANDLE v15; // [esp+40h] [ebp-40h]
  _DWORD *v16; // [esp+44h] [ebp-3Ch]
  _DWORD *v17; // [esp+48h] [ebp-38h]
  DWORD BytesReturned; // [esp+4Ch] [ebp-34h]
  int OutBuffer; // [esp+50h] [ebp-30h]
  _DWORD *v20; // [esp+54h] [ebp-2Ch]
  HANDLE TargetHandle; // [esp+58h] [ebp-28h]
  LPVOID lpOutBuffer; // [esp+5Ch] [ebp-24h]
  char v23; // [esp+60h] [ebp-20h]
  unsigned __int16 v24; // [esp+6Ch] [ebp-14h]
  int v25; // [esp+6Eh] [ebp-12h]

  v17 = a2;
  v4 = 0;
  v20 = a3;
  v16 = a4;
  if ( !lpInBuffer )
  {
    if ( dword_10610D4 != -1 )
    {
      CloseHandle(ghSourceProcessHandle);
      dword_10610D4 = -1;
    }
    return 0;
  }
  if ( dword_10610D4 != *(lpInBuffer + 1) )
  {
    if ( dword_10610D4 != -1 )
    {
      dword_10610D4 = -1;
      CloseHandle(ghSourceProcessHandle);
    }
    ghSourceProcessHandle = OpenProcess(PROCESS_DUP_HANDLE, 0, *(lpInBuffer + 1));
    if ( !ghSourceProcessHandle )
      return 0;
    dword_10610D4 = *(lpInBuffer + 1);
  }
  v6 = GetCurrentProcess();
  if ( !DuplicateHandle(ghSourceProcessHandle, *(lpInBuffer + 2), v6, &TargetHandle, 0, 0, 0) )
    return 0;
  lpOutBuffer = malloc(0x408u);
  InBuffer = GetCurrentProcessId();
  v13 = *lpInBuffer;
  v15 = TargetHandle;
  v14 = 0;
  if ( ::DeviceIoControl(ghDriverHandle, 0x83350048, &InBuffer, 0x10u, lpOutBuffer, 0x408u, &BytesReturned, 0)
    && (!_wcsicmp(lpOutBuffer + 2, L"\\Device\\Tcp") || !_wcsicmp(lpOutBuffer + 2, L"\\Device\\Udp")) )
  {
    if ( GetVersion() >= 5u )
    {
      DeviceIoControl = ::DeviceIoControl;
    }
    else
    {
      DeviceIoControl = ::DeviceIoControl;
      ::DeviceIoControl(ghDriverHandle, 0x83350020, lpInBuffer, 4u, &OutBuffer, 4u, &BytesReturned, 0);
    }
    if ( GetVersion() >= 5u || OutBuffer == 1 || OutBuffer == 2 )
    {
      Overlapped.hEvent = 0;
      _mm_storeu_si128(&Overlapped, 0i64);
      Overlapped.hEvent = CreateEventW(0, 0, 0, 0);
      v10 = 3;
      if ( DeviceIoControl(TargetHandle, 0x210012u, &v9, 0x18u, &v23, 0x1Au, 0, &Overlapped) )
      {
        v8 = _wcsicmp(lpOutBuffer + 2, L"\\Device\\Tcp");
        v4 = 1;
        *v17 = v8 != 0;
        *v16 = v24;
        *v20 = v25;
      }
      else
      {
        v4 = 0;
      }
      CloseHandle(Overlapped.hEvent);
    }
  }
  free(lpOutBuffer);
  CloseHandle(TargetHandle);
  return v4;
}
// 10610D4: using guessed type int dword_10610D4;

//----- (00FDC750) --------------------------------------------------------
void __cdecl sub_FDC750(wchar_t *a1, int a2, wchar_t *Dst, rsize_t SizeInWords, _DWORD *a5)
{
  rsize_t v5; // esi
  int v6; // eax
  void *v7; // eax
  size_t v8; // esi
  void *v9; // eax
  BOOL v10; // eax
  HANDLE v11; // esi
  size_t v12; // esi
  const wchar_t **v13; // eax
  ULONG v14; // ST20_4
  const wchar_t **v15; // esi
  int v16; // eax
  void *v17; // edi
  int v18; // ebx
  void *v19; // eax
  void *v20; // ebx
  size_t v21; // esi
  void *v22; // eax
  int v23; // ecx
  bool v24; // zf
  wchar_t *v25; // ebx
  void *v26; // ebx
  __m128i *v27; // edi
  HANDLE v28; // eax
  int v29; // eax
  void *v30; // ebx
  PROCESS_BASIC_INFORMATION ProcessInfo; // [esp+Ch] [ebp-10C0h]
  THREAD_BASIC_INFORMATION ThreadInfo; // [esp+24h] [ebp-10A8h]
  enum _SID_NAME_USE peUse; // [esp+40h] [ebp-108Ch]
  DWORD ThreadId; // [esp+44h] [ebp-1088h]
  DWORD cchReferencedDomainName; // [esp+48h] [ebp-1084h]
  DWORD cchName; // [esp+4Ch] [ebp-1080h]
  int InBuffer; // [esp+50h] [ebp-107Ch]
  int v38; // [esp+54h] [ebp-1078h]
  bool v39; // [esp+58h] [ebp-1074h]
  int v40; // [esp+5Ch] [ebp-1070h]
  _DWORD *v41; // [esp+60h] [ebp-106Ch]
  DWORD ReturnLength; // [esp+64h] [ebp-1068h]
  HANDLE hObject; // [esp+68h] [ebp-1064h]
  size_t cbRet; // [esp+6Ch] [ebp-1060h]
  wchar_t *v45; // [esp+70h] [ebp-105Ch]
  DWORD BytesReturned; // [esp+74h] [ebp-1058h]
  char TokenInformation; // [esp+78h] [ebp-1054h]
  int v48; // [esp+80h] [ebp-104Ch]
  DWORD v49; // [esp+84h] [ebp-1048h]
  PSID Sid; // [esp+B0h] [ebp-101Ch]
  WCHAR Name; // [esp+8B0h] [ebp-81Ch]
  WCHAR ReferencedDomainName; // [esp+AB8h] [ebp-614h]
  wchar_t v53; // [esp+CC0h] [ebp-40Ch]
  wchar_t pszText; // [esp+EC8h] [ebp-204h]

  v5 = SizeInWords;
  v45 = Dst;
  v41 = a5;
  wcscpy_s(Dst, SizeInWords, &gszNullString);
  if ( a5 )
    *v41 = 0;
  if ( !*a1 )
    goto LABEL_55;
  v6 = wcscmp(a1, L"<Unknown type>");
  if ( v6 )
    v6 = -(v6 < 0) | 1;
  if ( !v6 )
  {
LABEL_55:
    v7 = PE_DuplicateProcessHandle(*(a2 + 4), *(a2 + 8), 0);
    hObject = v7;
    if ( v7 )
    {
      NtQueryObject(v7, ObjectTypeInformation, 0, 0, &cbRet);
      v12 = cbRet;
      v13 = malloc(cbRet);
      v14 = v12;
      v15 = v13;
      v16 = NtQueryObject(hObject, ObjectTypeInformation, v13, v14, 0);
      if ( v16 )
        MakeDeviceName(a1, L"<Unknown type: %X>", v16);
      else
        wcsncpy_s(a1, 0x40u, v15[1], *v15 >> 1);
      free(v15);
      CloseHandle(hObject);
LABEL_17:
      v5 = SizeInWords;
      goto LABEL_18;
    }
    if ( ghDriverHandle != -1 )
    {
      v8 = 2 * SizeInWords + 8;
      v9 = malloc(v8);
      InBuffer = *(a2 + 4);
      v38 = *a2;
      v40 = *(a2 + 8);
      hObject = v9;
      v10 = DeviceIoControl(ghDriverHandle, 0x8335004C, &InBuffer, 0x10u, v9, v8, &BytesReturned, 0);
      v11 = hObject;
      if ( v10 )
        wcscpy_s(a1, 0x40u, hObject + 2);
      free(v11);
      goto LABEL_17;
    }
    MakeDeviceName(a1, L"<Unknown type>");
  }
LABEL_18:
  if ( _wcsicmp(a1, L"process") && _wcsicmp(a1, L"thread") )
  {
    if ( _wcsicmp(a1, L"token") )
    {
      if ( _wcsicmp(a1, L"EtwRegistration") )
      {
        if ( ghDriverHandle == -1 )
        {
          v26 = PE_DuplicateProcessHandle(*(a2 + 4), *(a2 + 8), 0);
          if ( v26 )
          {
            cbRet = 1024;
            v27 = malloc(0x400u);
            _mm_storel_epi64(v27, 0i64);
            LOWORD(v27->m128i_i32[0]) = cbRet - 8;
            if ( !ghBackendQueryObjectThreadHandle )
              ghBackendQueryObjectThreadHandle = _beginthreadex(0, 0, BackendQueryObjectThreadProc, 0, 0, &ThreadId);
            v28 = lpName;
            if ( !lpName )
            {
              lpName = CreateEventW(lpName, lpName, lpName, lpName);
              hHandle = CreateEventW(0, 0, 0, 0);
              v28 = lpName;
            }
            gObjectNameInformation = v27;
            Handle = v26;
            SetEvent(v28);
            if ( WaitForSingleObject(hHandle, 0x3E8u) == 258 )
            {
              TerminateThread(ghBackendQueryObjectThreadHandle, 1u);
              CloseHandle(ghBackendQueryObjectThreadHandle);
              ghBackendQueryObjectThreadHandle = 0;
              free(v27);
              CloseHandle(v26);
            }
            else
            {
              if ( !gulQueryObjectResult )
                sub_FF5230(v45, SizeInWords, v27);
              free(v27);
              CloseHandle(v26);
            }
          }
        }
        else
        {
          v21 = 2 * v5 + 8;
          v22 = malloc(v21);
          InBuffer = *(a2 + 4);
          v23 = *a2;
          BytesReturned = v22;
          v38 = v23;
          v24 = _wcsicmp(a1, L"file") == 0;
          v25 = BytesReturned;
          v40 = *(a2 + 8);
          v39 = v24;
          if ( CDriver::Control(0x83350048, &InBuffer, 0x10u, BytesReturned, v21) )
          {
            wcscpy_s(v45, SizeInWords, v25 + 2);
            if ( v41 )
              *v41 = *v25;
          }
          free(v25);
        }
      }
      else
      {
        v19 = PE_DuplicateProcessHandle(*(a2 + 4), *(a2 + 8), 0);
        v20 = v19;
        if ( v19 )
        {
          CloseHandle(v19);
          CloseHandle(v20);
        }
      }
    }
    else
    {
      v17 = PE_DuplicateProcessHandle(*(a2 + 4), *(a2 + 8), 8u);
      if ( v17 )
      {
        v49 = 0;
        v48 = 0;
        ReturnLength = 56;
        GetTokenInformation(v17, TokenStatistics, &TokenInformation, 0x38u, &ReturnLength);
        v18 = v48;
        BytesReturned = v49;
        ReturnLength = 2048;
        if ( GetTokenInformation(v17, TokenUser, &Sid, 0x800u, &ReturnLength) )
        {
          cchName = 260;
          cchReferencedDomainName = 260;
          if ( LookupAccountSidW(
                 &gszNullString,
                 Sid,
                 &Name,
                 &cchName,
                 &ReferencedDomainName,
                 &cchReferencedDomainName,
                 &peUse) )
          {
            swprintf_s(v45, SizeInWords, L"%s\\%s:%x", &ReferencedDomainName, &Name, v18, BytesReturned);
          }
        }
        CloseHandle(v17);
      }
    }
  }
  else
  {
    v29 = _wcsicmp(a1, L"process");
    v30 = PE_DuplicateProcessHandle(*(a2 + 4), *(a2 + 8), v29 != 0 ? 64 : 1024);
    if ( v30 )
    {
      if ( _wcsicmp(a1, L"Process") )
      {
        if ( !NtQueryInformationThread(
                v30,
                ThreadBasicInformation,
                &ThreadInfo,
                sizeof(_THREAD_BASIC_INFORMATION),
                &cbRet) )
        {
          SystemProcessInfo_GetSystemProcessName(ThreadInfo.ClientId.UniqueProcess, 0, &pszText, 0x100u);
          swprintf_s(
            v45,
            v5,
            L"%s(%d): %d",
            &pszText,
            ThreadInfo.ClientId.UniqueProcess,
            ThreadInfo.ClientId.UniqueThread);
        }
      }
      else if ( !NtQueryInformationProcess(
                   v30,
                   ProcessBasicInformation,
                   &ProcessInfo,
                   sizeof(PROCESS_BASIC_INFORMATION),
                   &cbRet) )
      {
        SystemProcessInfo_GetSystemProcessName(ProcessInfo.UniqueProcessId, 0, &pszText, 0x100u);
        swprintf_s(v45, v5, L"%s(%d)", &pszText, ProcessInfo.UniqueProcessId);
        CloseHandle(v30);
        return;
      }
      CloseHandle(v30);
    }
    else if ( ghDriverHandle != -1 )
    {
      sub_FDBE70(&v53, 0x104u);
      swprintf_s(v45, v5, L"<%s>", &v53);
    }
  }
}
// 106ABA0: using guessed type int gulQueryObjectResult;

//----- (00FDCE20) --------------------------------------------------------
int __cdecl sub_FDCE20(DWORD BytesReturned, LPVOID lpOutBuffer)
{
  _DWORD *v2; // esi
  _DWORD *v3; // edi
  DWORD dwSymbolAddress; // eax
  unsigned __int64 v5; // rax
  double v6; // xmm0_8

  v2 = BytesReturned;
  v3 = lpOutBuffer;
  *BytesReturned = 0;
  v2[1] = 0;
  *v3 = 0;
  v3[1] = 0;
  if ( gdwSymbolAddressOfMmMaximumNonPagedPoolInBytes || !dword_105E0DC )
  {
    dwSymbolAddress = gdwSymbolAddressOfMmSizeOfPagedPoolInBytes;
  }
  else
  {
    gdwSymbolAddressOfMmMaximumNonPagedPoolInBytes = LoadSystemModulesSymbolAddress("MmMaximumNonPagedPoolInBytes");
    dwSymbolAddress = LoadSystemModulesSymbolAddress("MmSizeOfPagedPoolInBytes");
    gdwSymbolAddressOfMmSizeOfPagedPoolInBytes = dwSymbolAddress;
    dword_105E0DC = 0;
  }
  if ( dwSymbolAddress )
    DeviceIoControl(
      ghDriverHandle,
      0x83350044,
      &gdwSymbolAddressOfMmSizeOfPagedPoolInBytes,
      4u,
      v3,
      8u,
      &BytesReturned,
      0);
  if ( gdwSymbolAddressOfMmMaximumNonPagedPoolInBytes )
  {
    LODWORD(v5) = DeviceIoControl(
                    ghDriverHandle,
                    0x83350044,
                    &gdwSymbolAddressOfMmMaximumNonPagedPoolInBytes,
                    4u,
                    v2,
                    8u,
                    &BytesReturned,
                    0);
    v2[1] = 0;
    v3[1] = 0;
  }
  else
  {
    *v2 = 0x200000;
    v2[1] = 0;
    v6 = gpGraphInfoOfPhysicalMemory->m_dbMemorySize;
    v5 = v6 << 10;
    if ( is_mul_ok(0x400u, v6) && v5 < 0x200000 )
      *v2 = v5;
    v2[1] = 0;
    v3[1] = 0;
  }
  return v5;
}
// 105E0DC: using guessed type int dword_105E0DC;
// 10850E8: using guessed type int gdwSymbolAddressOfMmMaximumNonPagedPoolInBytes;
// 10850EC: using guessed type int gdwSymbolAddressOfMmSizeOfPagedPoolInBytes;

//----- (00FDCF30) --------------------------------------------------------
char __cdecl sub_FDCF30(HANDLE hProcess, WCHAR **ppszFileName)
{
  SIZE_T v3; // ebx
  wchar_t *v4; // esi
  char v5; // bl
  wchar_t *v6; // eax
  PROCESS_BASIC_INFORMATION ProcessInformation; // [esp+4h] [ebp-520h]
  ULONG ReturnLength; // [esp+1Ch] [ebp-508h]
  WCHAR **v9; // [esp+20h] [ebp-504h]
  SIZE_T dwRet; // [esp+24h] [ebp-500h]
  char Buffer; // [esp+28h] [ebp-4FCh]
  LPCVOID lpBaseAddress; // [esp+38h] [ebp-4ECh]
  PEB Peb; // [esp+278h] [ebp-2ACh]

  v9 = ppszFileName;
  if ( NtQueryInformationProcess(hProcess, 0, &ProcessInformation, 0x18u, &ReturnLength)
    || !ProcessInformation.PebBaseAddress )
  {
    return 0;
  }
  if ( !ReadProcessMemory(hProcess, ProcessInformation.PebBaseAddress, &Buffer, 0x250u, &dwRet)
    || !ReadProcessMemory(hProcess, lpBaseAddress, &Peb, 0x2A8u, &dwRet)
    || !Peb.TlsExpansionCounter )
  {
    return 0;
  }
  v3 = LOWORD(Peb.FreeList);
  v4 = malloc(LOWORD(Peb.FreeList) + 2);
  if ( ReadProcessMemory(hProcess, Peb.TlsExpansionCounter, v4, v3, &dwRet) )
  {
    v4[v3 >> 1] = 0;
    v6 = _wcsdup(v4);
    v5 = 1;
    *v9 = v6;
  }
  else
  {
    v5 = 0;
  }
  j__free(v4);
  return v5;
}

//----- (00FDD050) --------------------------------------------------------
HICON __cdecl ExtractApplicationIcon(LPCWSTR pszPath, int uFlags)
{
  SHFILEINFOW FileInfo; // [esp+0h] [ebp-2B8h]

  FileInfo.hIcon = 0;
  if ( !pszPath )
    return 0;
  SHGetFileInfoW(pszPath, 0, &FileInfo, sizeof(SHFILEINFOW), uFlags | SHGFI_ICON);
  return FileInfo.hIcon;
}

//----- (00FDD0C0) --------------------------------------------------------
char __cdecl sub_FDD0C0(HANDLE hProcess, tagTREEVIEWLISTITEMPARAM *pItem)
{
  wchar_t *v2; // ebx
  unsigned int v3; // kr00_4
  wchar_t *v4; // esi
  const WCHAR *v5; // ecx
  const wchar_t *v6; // eax
  wchar_t *v7; // eax
  wchar_t *v8; // ebx
  int v9; // edx
  wchar_t v10; // cx
  wchar_t *v11; // eax
  wchar_t *v12; // eax
  wchar_t *v13; // esi
  wchar_t i; // ax
  char v15; // cl
  int v16; // eax
  DWORD v17; // eax
  WCHAR *v18; // eax
  wchar_t *v19; // ecx
  wchar_t *v20; // ecx
  HWND v21; // eax
  HWND v22; // esi
  char v23; // al
  wchar_t *v24; // ebx
  wchar_t *v26; // eax
  wchar_t *v27; // esi
  LPWSTR FilePart; // [esp+Ch] [ebp-2A0h]
  char hObject; // [esp+13h] [ebp-299h]
  wchar_t *pszFileName; // [esp+14h] [ebp-298h]
  DWORD nBufferLength; // [esp+18h] [ebp-294h]
  char v32; // [esp+1Fh] [ebp-28Dh]
  __int16 ClassName[260]; // [esp+20h] [ebp-28Ch]
  __int16 Dst[64]; // [esp+228h] [ebp-84h]

  pszFileName = 0;
  v32 = 0;
  if ( pItem->szProcessName )
    return 0;
  if ( !sub_FE0A90(hProcess, pItem->dwProcessId, &pszFileName, pItem) )
  {
    if ( pItem->dwProcessId <= 8u )
    {
      v27 = pszFileName;
    }
    else
    {
      v26 = malloc(0x208u);
      v27 = v26;
      if ( hProcess )
      {
        sub_FDBE70(v26 + 1, 0x103u);
        *v27 = 91;
        if ( wcschr(v27, 0xDu) )
          *wcschr(v27, 0xDu) = 0;
        wcscat_s(v27, 0x104u, L"]");
      }
      else
      {
        swprintf_s(v26, 0x104u, L"[Error opening process]");
      }
      pItem->szProcessName = _wcsdup(v27);
    }
    if ( v27 )
      free(v27);
    return 0;
  }
  v2 = pszFileName;
  if ( sub_FC43C0(pszFileName, &pItem->field_28C + 1, 0x41u, &pItem->pszTitle, &pItem->field_314)
    && GetLastError() != ERROR_RESOURCE_TYPE_NOT_FOUND )
  {
    v3 = wcslen(v2);
    v4 = malloc(2 * (v3 + 260));
    wcscpy_s(v4, v3 + 260, pszFileName);
    sub_FDBE70(v4 + 1, v3 + 259);
    *v4 = 91;
    if ( wcschr(v4, 0xDu) )
      *wcschr(v4, 0xDu) = 0;
    wcscat_s(v4, v3 + 260, L"]");
    pItem->szProcessName = v4;
  }
  else
  {
    nBufferLength = _wcsdup(v2);
    PE_GetFullPathName(&nBufferLength);
    v5 = nBufferLength;
    pItem->szProcessName = nBufferLength;
    if ( sub_FCE970(v5, &pItem->field_280, &hObject, &pItem->field_288 + 2) )
      pItem->dwStyle |= 0x100u;
    else
      pItem->dwStyle &= 0xFFFFFEFF;
    if ( !_wcsicmp(pItem->szProcessName2, L"rundll32.exe") && (v6 = pItem->pszCommandLine) != 0 && wcschr(v6, 0x2Cu) )
    {
      v7 = _wcsdup(pItem->pszCommandLine);
      v8 = v7;
      v9 = (v7 + 1);
      do
      {
        v10 = *v7;
        ++v7;
      }
      while ( v10 );
      _wcsupr_s(v8, ((v7 - v9) >> 1) + 1);
      if ( wcsstr(v8, L"SHELL32.DLL") && wcsstr(v8, L"CONTROL_RUNDLL ") )
      {
        v11 = wcsstr(v8, L"CONTROL_RUNDLL");
        v12 = wcschr(v11, 0x20u);
        v13 = v12;
        for ( i = *v12; i; ++v13 )
        {
          if ( i != 32 )
            break;
          i = v13[1];
        }
        if ( *v13 == 34 )
        {
          ++v13;
          if ( wcschr(v13, 0x22u) )
            *wcschr(v13, 0x22u) = 0;
        }
      }
      else
      {
        v13 = wcschr(v8, 0x2Cu);
        v15 = 0;
        for ( *v13 = 0; v13 != v8; --v13 )
        {
          if ( v15 )
          {
            if ( *v13 == 34 )
              break;
          }
          else
          {
            v16 = *v13;
            if ( v16 == 32 )
              goto LABEL_33;
            if ( v16 == 34 )
            {
              v15 = 1;
              *v13 = 0;
            }
          }
        }
        if ( *v13 == 32 )
LABEL_33:
          ++v13;
        if ( *v13 == 34 )
          ++v13;
        if ( !*v13 )
          ++v13;
      }
      v17 = SearchPathW(0, v13, 0, 0, 0, 0);
      nBufferLength = v17;
      if ( v17 )
      {
        v18 = malloc(2 * v17);
        pItem->m_ExtensionName = v18;
        SearchPathW(0, v13, 0, nBufferLength, v18, &FilePart);
        _wcslwr_s(pItem->m_ExtensionName, nBufferLength);
        sub_FC43C0(pItem->m_ExtensionName, Dst, 0x40u, &pItem->field_358, &pItem->field_354);
      }
      free(v8);
    }
    else if ( _wcsicmp(pItem->szProcessName2, L"svchost.exe") || (v19 = pItem->pszCommandLine) == 0 )
    {
      if ( !_wcsicmp(pItem->szProcessName2, L"dllhost.exe") )
      {
        v20 = pItem->pszCommandLine;
        if ( v20 )
          sub_FC3F80(v20, &pItem->field_350, &pItem->m_ExtensionName, &pItem->field_358, &pItem->field_354);
      }
    }
    else
    {
      sub_FC4730(v19, &pItem->szServiceName);
    }
    if ( !_wcsicmp(pItem->szProcessName2, L"mmc.exe") && SLOBYTE(pItem->dwStyle) >= 0 )
    {
      v21 = GetDesktopWindow();
      v22 = GetWindow(v21, 5u);
      nBufferLength = 0;
      while ( 1 )
      {
        GetWindowThreadProcessId(v22, &nBufferLength);
        ClassName[0] = 0;
        GetClassNameW(v22, ClassName, 260);
        if ( nBufferLength == pItem->dwProcessId && !wcsncmp(ClassName, &off_104421C, 0x104u) )
        {
          SendMessageTimeoutW(v22, 0x7Fu, 0, 0, 0, 0xC8u, &pItem->hIcon);
          SendMessageTimeoutW(v22, 0x7Fu, 1u, 0, 0, 0xC8u, &pItem->hFileIcon);
          v23 = 1;
          v32 = 1;
        }
        else
        {
          v22 = GetWindow(v22, 2u);
          v23 = v32;
        }
        if ( !v22 )
          break;
        if ( v23 )
          goto LABEL_59;
      }
      if ( v23 )
        goto LABEL_59;
    }
  }
  v24 = pszFileName;
  pItem->hIcon = ExtractApplicationIcon(pszFileName, 1);
  SendMessageW(ghMainWnd, WM_MSG_7F3, 0, pItem);
  pItem->hFileIcon = ExtractApplicationIcon(v24, 0);
LABEL_59:
  if ( pszFileName )
    free(pszFileName);
  return 1;
}

//----- (00FDD670) --------------------------------------------------------
int __cdecl VerifyImage(tagTREEVIEWLISTITEMPARAM *pItem, char a2)
{
  WCHAR *v2; // eax
  int *v3; // ecx
  const unsigned __int16 *v4; // ebx
  int *v5; // edx
  wchar_t **v6; // esi
  int v7; // eax
  int v8; // esi
  HCURSOR v9; // eax
  DWORD v10; // eax
  DWORD v11; // esi
  wchar_t *v12; // esi
  int v13; // ecx
  wchar_t v14; // ax
  size_t v15; // esi
  wchar_t *v16; // ebx
  wchar_t *v17; // eax
  unsigned int v18; // esi
  unsigned int v19; // ecx
  size_t v20; // esi
  wchar_t *v21; // eax
  wchar_t *v22; // eax
  HCURSOR hCursor; // [esp+Ch] [ebp-8C0h]
  wchar_t *v25; // [esp+10h] [ebp-8BCh]
  int a6; // [esp+14h] [ebp-8B8h]
  wchar_t *a1; // [esp+18h] [ebp-8B4h]
  int *v28; // [esp+1Ch] [ebp-8B0h]
  wchar_t **v29; // [esp+20h] [ebp-8ACh]
  int *v30; // [esp+24h] [ebp-8A8h]
  wchar_t *v31[32]; // [esp+28h] [ebp-8A4h]
  __int16 szBuffer[1040]; // [esp+A8h] [ebp-824h]

  if ( pItem->nListType == 1 )
  {
    v2 = *&pItem->gap154[4];
    v3 = &pItem->gap154[12];
    v4 = *pItem->gap154;
    v5 = &pItem->gap154[16];
    v6 = &pItem->gap154[20];
  }
  else
  {
    v2 = pItem->szProcessName;
    v3 = &pItem->field_340;
    v4 = pItem->field_314;
    v5 = &pItem->field_344;
    v6 = &pItem->field_348;
  }
  v29 = v6;
  v28 = v5;
  a1 = v2;
  v30 = v3;
  if ( !v2 || *v2 == 91 )
    return 0;
  if ( !*v3 )
  {
    if ( a2 )
    {
      v7 = sub_FE0D70(v2);
      v8 = v7;
      if ( v7 )
      {
        *v29 = _wcsdup(*(v7 + 4));
        *v30 = *(v8 + 8);
      }
      else
      {
        *v29 = _wcsdup(L"Verifying...");
        SendMessageW(ghMainWnd, WM_MSG_7F0, 0, pItem);
        v9 = LoadCursorW(0, IDC_WAIT);
        hCursor = SetCursor(v9);
        a6 = 32;
        v10 = sub_F99BB0(a1, 0, 0, 0, 0, &a6, v31, 0, 0, 0, 0, 0, -1);
        v11 = v10;
        if ( v10 )
        {
          SetLastError(v10);
          if ( v11 == 0x800B0101 )
            wcscpy_s(szBuffer, 0x410u, L"Certificate expired");
          else
            sub_FDBE70(szBuffer, 0x410u);
          if ( wcschr(szBuffer, 0x2Eu) )
            *wcschr(szBuffer, 0x2Eu) = 0;
          if ( v4 )
            v19 = wcslen(v4);
          else
            v19 = 1;
          v20 = wcslen(szBuffer) + v19 + 32;
          v21 = malloc(2 * v20);
          v25 = v21;
          *v30 = 2;
          if ( v4 )
            swprintf_s(v21, v20, L"(%s) %s", szBuffer, v4);
          else
            swprintf_s(v21, v20, L"(%s)", szBuffer);
          v16 = v25;
        }
        else
        {
          v12 = v31[0];
          *v30 = 1;
          v13 = (v12 + 1);
          do
          {
            v14 = *v12;
            ++v12;
          }
          while ( v14 );
          v15 = ((v12 - v13) >> 1) + 64;
          v16 = malloc(2 * v15);
          swprintf_s(v16, v15, L"(Verified) %s", v31[0]);
          v17 = _wcsdup(v31[0]);
          v18 = 0;
          *v28 = v17;
          if ( a6 )
          {
            do
              free(v31[v18++]);
            while ( v18 < a6 );
          }
        }
        SetCursor(hCursor);
        v22 = _wcsdup(v16);
        *v29 = v22;
        sub_FF53D0(a1, *v30, v22);
        free(v16);
      }
    }
    else
    {
      *v6 = _wcsdup(v4);
    }
    SendMessageW(ghMainWnd, WM_MSG_7F0, 0, pItem);
  }
  return *v28;
}

//----- (00FDD9D0) --------------------------------------------------------
SYSTEM_HANDLE_INFORMATION *__cdecl sub_FDD9D0(SYSTEM_HANDLE_INFORMATION *a1)
{
  SYSTEM_HANDLE_INFORMATION *result; // eax

  result = a1;
  if ( a1 )
    result = a1->NumberOfHandles;
  return result;
}

//----- (00FDD9E0) --------------------------------------------------------
SYSTEM_HANDLE_TABLE_ENTRY_INFO **__cdecl GetHandleTableEntry(SYSTEM_HANDLE_INFORMATION *pHandleInfo, int nIndex, SYSTEM_HANDLE_TABLE_ENTRY_INFO **pEntry)
{
  SYSTEM_HANDLE_TABLE_ENTRY_INFO **result; // eax
  SYSTEM_HANDLE_TABLE_ENTRY_INFO *v4; // ecx

  if ( gbSupportExtendedSystemHandleInformation )
  {
    result = pEntry;
    *pEntry = (pHandleInfo->Handles + sizeof(SYSTEM_HANDLE_TABLE_ENTRY_INFO_EX) * nIndex + 4);
  }
  else
  {
    v4 = (pHandleInfo + sizeof(SYSTEM_HANDLE_TABLE_ENTRY_INFO) * nIndex);
    word_107BC1C = v4->HandleValue;
    dword_107BC18 = *&v4[1].UniqueProcessId;
    byte_107BC20 = BYTE1(v4->Object);
    dword_107BC14 = HIWORD(v4->Object);
    dword_107BC0C = v4->GrantedAccess;
    word_107BC1E = LOBYTE(v4->Object);
    dword_107BC10 = *&v4->ObjectTypeIndex;
    result = pEntry;
    *pEntry = &dword_107BC0C;
  }
  return result;
}
// 106ABA5: using guessed type char gbSupportExtendedSystemHandleInformation;
// 107BC0C: using guessed type int dword_107BC0C;
// 107BC10: using guessed type int dword_107BC10;
// 107BC14: using guessed type int dword_107BC14;
// 107BC18: using guessed type int dword_107BC18;
// 107BC1C: using guessed type __int16 word_107BC1C;
// 107BC1E: using guessed type __int16 word_107BC1E;
// 107BC20: using guessed type char byte_107BC20;

//----- (00FDDA60) --------------------------------------------------------
struct _FILETIME __cdecl GetSystemProcessInfo(SYSTEM_PROCESS_INFORMATION **ppSystemProcessInfo, PULONG cbRet)
{
  PULONG cbLength; // esi
  SYSTEM_PROCESS_INFORMATION *v3; // eax
  struct _FILETIME SystemTimeAsFileTime; // [esp+8h] [ebp-Ch]
  char v6; // [esp+10h] [ebp-4h]

  cbLength = &v6;
  if ( cbRet )
    cbLength = cbRet;
  if ( !*ppSystemProcessInfo )
  {
    *cbLength = 1000;
    *ppSystemProcessInfo = malloc(1000u);
  }
  GetSystemTimeAsFileTime(&SystemTimeAsFileTime);
  if ( NtQuerySystemInformation(SystemProcessInformation, *ppSystemProcessInfo, *cbLength, &cbRet) )
  {
    do
    {
      free(*ppSystemProcessInfo);
      *cbLength += 10000;
      v3 = malloc(*cbLength);
      *ppSystemProcessInfo = v3;
    }
    while ( NtQuerySystemInformation(SystemProcessInformation, v3, *cbLength, &cbRet) );
  }
  return SystemTimeAsFileTime;
}

//----- (00FDDAF0) --------------------------------------------------------
FILETIME __cdecl RequerySystemStatus(SYSTEM_PROCESS_INFORMATION **ppSystemProcessInfo, PULONG cbRet, SYSTEM_PROCESSOR_PERFORMANCE_INFORMATION *pSystemProcessorPerformanceInfo, SYSTEM_INTERRUPT_INFORMATION *pSystemInterruptInfo, SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *pSystemProcessorCycleTimeInfo, CSystemProcessInfoMap *pMap, int dwBufLen)
{
  struct _FILETIME timeReturned; // rax
  DWORD v8; // ebx
  SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *pSystemProcessorCycleTimeInfo_1; // edi
  SYSTEM_PROCESS_INFORMATION *gpSystemProcessInfoLast; // esi
  CSystemProcessInfoMapNode *_Node; // eax
  ULONG i; // eax
  CSystemProcessInfoMapNode *_Node_1; // eax
  std__Tree_node *pNodeRet; // eax
  CSystemProcessInfoMap *pMapIn; // ecx
  CSystemProcessInfoMap LocalMap; // rax
  CSystemProcessInfoMap *pLocalMapIn; // ST0C_4
  int _Where; // [esp+10h] [ebp-2Ch]
  CSystemProcessInfoMapPair pair; // [esp+18h] [ebp-24h]
  CSystemProcessInfoMap *pLocalMap; // [esp+20h] [ebp-1Ch]
  int v22; // [esp+24h] [ebp-18h]
  ULONG nSize; // [esp+28h] [ebp-14h]
  unsigned int v24; // [esp+2Ch] [ebp-10h]
  int v25; // [esp+38h] [ebp-4h]

  timeReturned = GetSystemProcessInfo(ppSystemProcessInfo, cbRet);
  v24 = timeReturned.dwHighDateTime;
  v8 = timeReturned.dwLowDateTime;
  if ( pSystemProcessorPerformanceInfo )
    NtQuerySystemInformation(
      SystemProcessorPerformanceInformation,
      pSystemProcessorPerformanceInfo,
      sizeof(SYSTEM_PROCESSOR_PERFORMANCE_INFORMATION) * gSystemInfo.dwNumberOfProcessors,
      &nSize);
  if ( pSystemInterruptInfo )
    NtQuerySystemInformation(
      SystemInterruptInformation,
      pSystemInterruptInfo,
      sizeof(SYSTEM_INTERRUPT_INFORMATION) * gSystemInfo.dwNumberOfProcessors,
      &nSize);
  pSystemProcessorCycleTimeInfo_1 = pSystemProcessorCycleTimeInfo;
  if ( pSystemProcessorCycleTimeInfo )
    NtQuerySystemInformation(
      SystemProcessorCycleTimeInformation,
      pSystemProcessorCycleTimeInfo,
      sizeof(SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION) * gSystemInfo.dwNumberOfProcessors,
      &nSize);
  if ( GetProcessorSystemCycleTime && pSystemProcessorCycleTimeInfo_1 )
  {
    v22 = 0;
    pLocalMap = std::_Tree_comp_alloc<std::_Tmap_traits<unsigned long,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *>>,0>>::_Buyheadnode();
    gpSystemProcessInfoLast = ::gpSystemProcessInfoLast;
    v25 = 0;
    if ( ::gpSystemProcessInfoLast )
    {
      pair._Key = ::gpSystemProcessInfoLast->UniqueProcessId;
      pair._Value = ::gpSystemProcessInfoLast;
      _Node = std::_Tree_comp_alloc<std::_Tmap_traits<unsigned long,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *>>,0>>::_Buynode<std::piecewise_construct_t const &,std::tuple<unsigned long &&>,std::tuple<>>(
                &pLocalMap,
                &pair);
      std::_Tree<std::_Tmap_traits<unsigned long,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *>>,0>>::_Insert_hint<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *> &,std::_Tree_node<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *>,void *> *>(
        &pLocalMap,
        &_Where,
        0,
        &_Node->_Keyvalue,
        _Node);
      for ( i = gpSystemProcessInfoLast->NextEntryOffset;
            gpSystemProcessInfoLast->NextEntryOffset;
            i = gpSystemProcessInfoLast->NextEntryOffset )
      {
        gpSystemProcessInfoLast = (gpSystemProcessInfoLast + i);
        pair._Value = gpSystemProcessInfoLast;
        pair._Key = gpSystemProcessInfoLast->UniqueProcessId;
        _Node_1 = std::_Tree_comp_alloc<std::_Tmap_traits<unsigned long,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *>>,0>>::_Buynode<std::piecewise_construct_t const &,std::tuple<unsigned long &&>,std::tuple<>>(
                    &pLocalMap,
                    &pair);
        std::_Tree<std::_Tmap_traits<unsigned long,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *>>,0>>::_Insert_hint<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *> &,std::_Tree_node<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *>,void *> *>(
          &pLocalMap,
          &_Where,
          0,
          &_Node_1->_Keyvalue,
          _Node_1);
      }
    }
    pNodeRet = sub_FDE4B0(&pLocalMap, *ppSystemProcessInfo, pSystemProcessorCycleTimeInfo_1, dwBufLen);
    pMapIn = pMap;
    pMap->_Header = pNodeRet;
    LocalMap._Header = pLocalMap;
    pLocalMapIn = pLocalMap;
    pMapIn->_Size = LocalMap._Size;
    sub_FF5510(&pLocalMap, &pSystemProcessorPerformanceInfo, LocalMap._Header->_Left, pLocalMapIn);
    j__free(pLocalMap);
  }
  return __PAIR__(v24, v8);
}
// 106F2F4: using guessed type int GetProcessorSystemCycleTime;

//----- (00FDDC80) --------------------------------------------------------
void QueryServiceNames()
{
  DWORD v0; // esi
  char cbSizeNeeded; // [esp+0h] [ebp-8h]
  int dwResumeHandle; // [esp+4h] [ebp-4h]

  if ( *EnumServicesStatusExW )
  {
    EnterCriticalSection(&gServiceLock);
    dwResumeHandle = 0;
    if ( !EnumServicesStatusExW(
            ghSCManagerHandle,
            SC_ENUM_PROCESS_INFO,
            SERVICE_WIN32,
            SERVICE_ACTIVE,
            gpszServiceNames,
            gdwServiceNamesLength,
            &cbSizeNeeded,
            &gdwServiceReturned,
            &dwResumeHandle,
            0) )
    {
      do
      {
        if ( GetLastError() != ERROR_MORE_DATA )
          break;
        dwResumeHandle = 0;
        if ( gpszServiceNames )
          free(gpszServiceNames);
        gdwServiceNamesLength += 16384;
        v0 = gdwServiceNamesLength;
        gpszServiceNames = malloc(gdwServiceNamesLength);
      }
      while ( !EnumServicesStatusExW(
                 ghSCManagerHandle,
                 0,
                 SERVICE_WIN32,
                 SERVICE_ACTIVE,
                 gpszServiceNames,
                 v0,
                 &cbSizeNeeded,
                 &gdwServiceReturned,
                 &dwResumeHandle,
                 0) );
    }
    LeaveCriticalSection(&gServiceLock);
  }
}

//----- (00FDDD60) --------------------------------------------------------
void __cdecl sub_FDDD60(char a1, unsigned int a2, int a3, unsigned int a4, int a5, int a6, int a7, unsigned int *a8)
{
  int v8; // esi
  unsigned int v9; // edx
  wchar_t *v10; // edi
  int v11; // ebx
  signed int v12; // eax
  const CHAR *v13; // ecx
  unsigned int v14; // ebx
  int v15; // esi
  int v16; // eax
  const CHAR *v17; // ebx
  const wchar_t **v18; // eax
  wchar_t *v19; // eax
  volatile signed __int32 *v20; // edx
  CString *v21; // eax
  HANDLE v22; // esi
  int v23; // ebx
  LPCSTR v24; // ebx
  CHAR *v25; // ecx
  int v26; // eax
  void *v27; // ebx
  int v28; // edx
  unsigned int v29; // ebx
  int v30; // esi
  char *v31; // eax
  LPCSTR v32; // eax
  int v33; // eax
  HANDLE v34; // esi
  const wchar_t **v35; // eax
  bool v36; // bl
  bool v37; // zf
  int v38; // ebx
  CString *v39; // eax
  const wchar_t **v40; // eax
  const wchar_t **v41; // eax
  wchar_t *v42; // eax
  DWORD v43; // ST28_4
  int v44; // eax
  int v45; // esi
  __int16 *v46; // ecx
  __int16 v47; // ax
  int v48; // ecx
  wchar_t v49; // ax
  __int16 v50; // ax
  int v51; // ecx
  wchar_t v52; // ax
  BOOL (__stdcall *v53)(HANDLE, PCWSTR, PVOID); // [esp+0h] [ebp-1288h]
  struct _MODLOAD_DATA *v54; // [esp+0h] [ebp-1288h]
  void *v55; // [esp+4h] [ebp-1284h]
  DWORD v56; // [esp+4h] [ebp-1284h]
  BOOL (__stdcall *v57)(HANDLE, PCWSTR, PVOID); // [esp+8h] [ebp-1280h]
  void *v58; // [esp+Ch] [ebp-127Ch]
  CString v59; // [esp+10h] [ebp-1278h]
  unsigned __int64 Displacement; // [esp+14h] [ebp-1274h]
  CString v61; // [esp+1Ch] [ebp-126Ch]
  CString v62; // [esp+20h] [ebp-1268h]
  int v63; // [esp+24h] [ebp-1264h]
  int v64; // [esp+28h] [ebp-1260h]
  int v65; // [esp+2Ch] [ebp-125Ch]
  CString v66; // [esp+30h] [ebp-1258h]
  int v67; // [esp+34h] [ebp-1254h]
  int v68; // [esp+38h] [ebp-1250h]
  unsigned int *v69; // [esp+3Ch] [ebp-124Ch]
  int v70; // [esp+40h] [ebp-1248h]
  int v71; // [esp+44h] [ebp-1244h]
  LPCSTR lpMultiByteStr; // [esp+48h] [ebp-1240h]
  unsigned int *v73; // [esp+4Ch] [ebp-123Ch]
  DWORD64 Address; // [esp+50h] [ebp-1238h]
  wchar_t v75; // [esp+58h] [ebp-1230h]
  struct _SYMBOL_INFOW Symbol; // [esp+858h] [ebp-A30h]
  WCHAR Buffer; // [esp+C58h] [ebp-630h]
  WCHAR Src; // [esp+E60h] [ebp-428h]
  WCHAR Dst; // [esp+106Ch] [ebp-21Ch]
  int v80; // [esp+1284h] [ebp-4h]

  HIDWORD(Displacement) = a6;
  Address = __PAIR__(a4, a2);
  v71 = a3;
  v64 = a5;
  v63 = a7;
  v69 = a8;
  if ( !a2 )
  {
    v8 = sub_FDE420(*(a3 + 44));
    if ( !v8 )
      v8 = a5;
    LODWORD(Address) = v8;
  }
  EnterCriticalSection(&gProcThreadsLock);
  GetSystemDirectoryW(&Buffer, 0x104u);
  v9 = Address;
  v10 = (a3 + 52);
  while ( 1 )
  {
    v11 = v63;
    v12 = -1;
    v73 = -1;
    *v10 = 0;
    if ( !v11 )
      goto LABEL_74;
    v70 = -1;
    v13 = *(v11 + 48);
    v14 = 0;
    lpMultiByteStr = v13;
    if ( !*v13 )
      goto LABEL_74;
    v15 = (v13 + 12);
    do
    {
      if ( v9 > *v15 )
      {
        if ( v9 >= *v15 + *(v15 + 4) )
        {
          v12 = v73;
        }
        else
        {
          v16 = *(v15 + 18) + 20;
          v70 = *v15;
          swprintf(v10, L"%S", v15 + v16);
          v9 = Address;
          v12 = v14;
          v73 = v14;
        }
      }
      ++v14;
      v15 += 284;
    }
    while ( v14 < *lpMultiByteStr );
    if ( v12 == -1 )
    {
LABEL_74:
      v29 = 0;
      v70 = -1;
      if ( !*v69 )
        goto LABEL_52;
      v30 = (v69 + 3);
      do
      {
        if ( v9 > *v30 )
        {
          if ( v9 >= *v30 + *(v30 + 4) )
          {
            v12 = v73;
          }
          else
          {
            v70 = *v30;
            lpMultiByteStr = (v30 + 20);
            v31 = strrchr((v30 + 20), 92);
            if ( v31 )
              v32 = v31 + 1;
            else
              v32 = lpMultiByteStr;
            swprintf(v10, L"%S", v32);
            v9 = Address;
            v12 = v29;
            v73 = v29;
          }
        }
        ++v29;
        v30 += 284;
      }
      while ( v29 < *v69 );
      if ( v12 == -1 )
      {
LABEL_52:
        v27 = HIDWORD(Address);
        goto LABEL_53;
      }
      v33 = 71 * v12;
      v34 = 0;
      v73 = &v69[v33];
      lpMultiByteStr = &v69[v33 + 8];
      v35 = ATL::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>(
              &v61,
              lpMultiByteStr);
      v36 = _wcsnicmp(*v35, L"\\SystemRoot\\", 0xCu) == 0;
      ATL::CSimpleStringT<wchar_t,0>::~CSimpleStringT<wchar_t,0>(&v61);
      v37 = v36 == 0;
      v38 = v73;
      if ( v37 )
      {
        if ( *(v73 + 33) == 58 )
        {
          v40 = ATL::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>(
                  &v66,
                  lpMultiByteStr);
          wcscpy_s(&Dst, 0x105u, *v40);
          ATL::CSimpleStringT<wchar_t,0>::~CSimpleStringT<wchar_t,0>(&v66);
        }
        else
        {
          if ( *(v73 + 37) != 58 )
          {
            sub_FD9D60(&Dst, L"%s\\drivers\\%s", &Buffer, v10);
            v34 = FindExecutableImageExW_0(&Dst, &Buffer, &Src, v53, v55);
            if ( v34 )
            {
              if ( !_wcsicmp(&Src, &Dst) )
                goto LABEL_46;
              CloseHandle(v34);
            }
            sub_FD9D60(&Src, L"%s\\drivers\\%s", &Buffer, v10);
            v34 = FindExecutableImageExW_0(&Src, &Buffer, &Dst, v57, v58);
            goto LABEL_46;
          }
          v41 = ATL::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>(
                  &v62,
                  v73 + 36);
          wcscpy_s(&Dst, 0x105u, *v41);
          ATL::CSimpleStringT<wchar_t,0>::~CSimpleStringT<wchar_t,0>(&v62);
        }
      }
      else
      {
        v39 = ATL::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>(
                &v59,
                v73 + 44);
        sub_FD9D60(&Src, L"%%SystemRoot%%\\%s", v39->pszData);
        ATL::CSimpleStringT<wchar_t,0>::~CSimpleStringT<wchar_t,0>(&v59);
        ExpandEnvironmentStringsW(&Src, &Dst, 0x105u);
      }
LABEL_46:
      v42 = _wcsdup(&Dst);
      *(v71 + 572) = v42;
      if ( SymLoadModuleExW_1 && a1 )
      {
        v43 = *(v38 + 16);
        v44 = *(v38 + 12);
        v27 = HIDWORD(Address);
        SymLoadModuleExW_1(HIDWORD(Address), v34, &Dst, 0, v44, v43, v59.pszData, Displacement);
      }
      else
      {
        v27 = HIDWORD(Address);
      }
      if ( v34 )
        CloseHandle(v34);
      goto LABEL_53;
    }
    if ( !a1 )
      goto LABEL_52;
    lpMultiByteStr += 284 * v12;
    v17 = lpMultiByteStr + 32;
    v18 = ATL::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>(
            &v67,
            lpMultiByteStr + 32);
    v19 = _wcsdup(*v18);
    v20 = (v67 - 16);
    *(v71 + 572) = v19;
    if ( _InterlockedDecrement(v20 + 3) <= 0 )
      (*(**v20 + 4))(v20);
    if ( !SymLoadModuleExW_1 )
      goto LABEL_52;
    v21 = ATL::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>(
            &v65,
            v17);
    v80 = 0;
    v22 = FindExecutableImageExW_0(v21->pszData, 0, &Dst, v53, v55);
    v23 = v65 - 16;
    v80 = -1;
    if ( _InterlockedDecrement((v65 - 16 + 12)) <= 0 )
      (*(**v23 + 4))(v23);
    v24 = lpMultiByteStr;
    v25 = ATL::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>(
            &v68,
            lpMultiByteStr + 32)->pszData;
    v26 = *(v24 + 3);
    v27 = HIDWORD(Address);
    v80 = 1;
    SymLoadModuleExW_1(HIDWORD(Address), v22, v25, 0, v26, 0, v54, v56);
    v28 = v68 - 16;
    v80 = -1;
    if ( _InterlockedDecrement((v68 - 16 + 12)) <= 0 )
      (*(**v28 + 4))(v28);
    if ( v22 )
      CloseHandle(v22);
LABEL_53:
    v45 = Address;
    Symbol.SizeOfStruct = 88;
    Symbol.MaxNameLen = 469;
    if ( a1 )
    {
      if ( *SymFromAddrW && SymFromAddrW(v27, Address, &Displacement, &Symbol) )
        break;
    }
    if ( *v10 )
    {
      wsprintfW(&v75, L"+0x%x", v45 - v70);
      goto LABEL_70;
    }
    if ( v45 == v64 )
    {
      wsprintfW(&v75, L"0x%x", v45);
LABEL_70:
      wcscat_s(v10, 0x104u, &v75);
      goto LABEL_71;
    }
    v9 = v64;
    LODWORD(Address) = v64;
  }
  v46 = (a3 + 52);
  LOBYTE(Symbol.Name[Symbol.NameLen]) = 0;
  if ( Displacement )
  {
    do
    {
      v47 = *v46;
      ++v46;
    }
    while ( v47 );
    v48 = (v46 - a3 - 54) >> 1;
    do
    {
      v49 = *v10;
      ++v10;
    }
    while ( v49 );
    _snwprintf_s((v71 + 2 * ((v10 - a3 - 54) >> 1) + 52), 260 - v48, 0xFFFFFFFF, L"!%s+0x%x", Symbol.Name, Displacement);
  }
  else
  {
    do
    {
      v50 = *v46;
      ++v46;
    }
    while ( v50 );
    v51 = (v46 - a3 - 54) >> 1;
    do
    {
      v52 = *v10;
      ++v10;
    }
    while ( v52 );
    _snwprintf_s((v71 + 2 * ((v10 - a3 - 54) >> 1) + 52), 260 - v51, 0xFFFFFFFF, L"!%s", Symbol.Name);
  }
LABEL_71:
  LeaveCriticalSection(&gProcThreadsLock);
}
// 1042BE0: using guessed type wchar_t a0xX_0[5];

//----- (00FDE420) --------------------------------------------------------
int __cdecl sub_FDE420(HANDLE hObject)
{
  HANDLE v1; // esi
  struct _OBJECT_ATTRIBUTES ObjectAttributes; // [esp+0h] [ebp-28h]
  struct _CLIENT_ID ClientId; // [esp+18h] [ebp-10h]
  ULONG ReturnLength; // [esp+20h] [ebp-8h]
  int ThreadInformation; // [esp+24h] [ebp-4h]

  ClientId.UniqueThread = hObject;
  ThreadInformation = 0;
  ClientId.UniqueProcess = 0;
  ObjectAttributes.Length = 24;
  ObjectAttributes.RootDirectory = 0;
  ObjectAttributes.Attributes = 0;
  ObjectAttributes.ObjectName = 0;
  ObjectAttributes.SecurityDescriptor = 0;
  ObjectAttributes.SecurityQualityOfService = 0;
  if ( NtOpenThread(&hObject, 0x40u, &ObjectAttributes, &ClientId) )
    return ThreadInformation;
  v1 = hObject;
  if ( hObject )
  {
    NtQueryInformationThread(hObject, ThreadQuerySetWin32StartAddress, &ThreadInformation, 4u, &ReturnLength);
    CloseHandle(v1);
  }
  return ThreadInformation;
}

//----- (00FDE4B0) --------------------------------------------------------
int __cdecl sub_FDE4B0(CSystemProcessInfoMap *theMap, SYSTEM_PROCESS_INFORMATION *pSystemProcessInfo, SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *pProcessorIdleCycleTimeInfo, unsigned int dwProcessorIdleCycleTimeInfoLen)
{
  unsigned __int64 ThisMap; // rcx
  SYSTEM_PROCESS_INFORMATION *SystemProcessInfo; // esi
  unsigned int v6; // edx
  DWORD dwNumberOfProcessors; // edi
  DWORD dwIndex; // edx
  __m128i v9; // xmm1
  __m128i v10; // xmm2
  char *v11; // eax
  __m128i v12; // xmm0
  __m128i v13; // xmm1
  __m128i v14; // xmm1
  unsigned __int64 v15; // kr08_8
  unsigned int v16; // eax
  unsigned int v17; // edi
  int v18; // kr18_4
  unsigned __int8 v19; // cf
  unsigned __int64 v20; // kr28_8
  DWORD v21; // kr04_4
  int v22; // ebx
  int v23; // ecx
  HANDLE v24; // edx
  int v25; // eax
  int *v26; // eax
  _DWORD *v27; // eax
  int v28; // edx
  CSystemProcessInfoMap *theMap_2; // esi
  std__Tree_node *_Node; // eax
  _DWORD *v31; // edi
  std__Tree_node *v32; // edx
  std__Tree_node_For__bstr_t *v33; // ecx
  std__Tree_node_For__bstr_t *_Node_1; // ecx
  std__Tree_node *_Node_2; // ecx
  std__Tree_node *_Node_3; // ecx
  unsigned int dwIndex_1; // edx
  __m128i v38; // xmm1
  __m128i v39; // xmm2
  SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *pProcessorIdleCycleTimeInfo2; // eax
  __m128i v41; // xmm0
  __m128i v42; // xmm1
  __m128i v43; // xmm1
  unsigned __int64 v44; // kr20_8
  unsigned __int64 v45; // rcx
  int v46; // eax
  unsigned int v47; // edi
  unsigned int v48; // eax
  ULONGLONG v49; // kr40_8
  ULONGLONG v50; // kr48_8
  unsigned int v51; // edi
  unsigned __int64 v52; // rax
  ULONG Buffer; // [esp+0h] [ebp-83Ch]
  int v55; // [esp+4h] [ebp-838h]
  int v56; // [esp+8h] [ebp-834h]
  DWORD v57; // [esp+Ch] [ebp-830h]
  _DWORD a2[2]; // [esp+10h] [ebp-82Ch]
  unsigned int dwProcessorIdleCycleTimeInfoLength; // [esp+18h] [ebp-824h]
  __int64 v60; // [esp+1Ch] [ebp-820h]
  __int64 v61; // [esp+24h] [ebp-818h]
  CSystemProcessInfoMap *theMap_1; // [esp+2Ch] [ebp-810h]
  unsigned int v63; // [esp+30h] [ebp-80Ch]
  unsigned int v64; // [esp+34h] [ebp-808h]
  ULONG64 ProcessorIdleCycleTime; // [esp+38h] [ebp-804h]
  int v66; // [esp+40h] [ebp-7FCh]
  int v67; // [esp+44h] [ebp-7F8h]
  char v68; // [esp+48h] [ebp-7F4h]

  ThisMap = theMap;
  SystemProcessInfo = pSystemProcessInfo;
  v60 = 0i64;
  v6 = 0;
  dwNumberOfProcessors = gSystemInfo.dwNumberOfProcessors;
  theMap_1 = theMap;
  dwProcessorIdleCycleTimeInfoLength = dwProcessorIdleCycleTimeInfoLen;
  v63 = 0;
  v64 = 0;
  while ( 1 )
  {
    if ( !SystemProcessInfo->UniqueProcessId && !SystemProcessInfo->SpareLi3.QuadPart )
    {
      Buffer = 8 * dwNumberOfProcessors;
      QueryIdleProcessorCycleTime(&Buffer, &ProcessorIdleCycleTime);
      dwNumberOfProcessors = gSystemInfo.dwNumberOfProcessors;
      dwIndex = 0;
      if ( gSystemInfo.dwNumberOfProcessors && gSystemInfo.dwNumberOfProcessors >= 4 )
      {
        v9 = 0i64;
        v10 = 0i64;
        v11 = &v68;
        do
        {
          v12 = _mm_loadu_si128(v11 - 1);
          dwIndex += 4;
          v11 += 32;
          v9 = _mm_add_epi64(v9, v12);
          v10 = _mm_add_epi64(v10, _mm_loadu_si128(v11 - 2));
        }
        while ( dwIndex < gSystemInfo.dwNumberOfProcessors - (gSystemInfo.dwNumberOfProcessors & 3) );
        v13 = _mm_add_epi64(v9, v10);
        v14 = _mm_add_epi64(v13, _mm_srli_si128(v13, 8));
        LODWORD(ThisMap) = _mm_cvtsi128_si32(v14);
        v15 = ThisMap + __PAIR__(_mm_cvtsi128_si32(_mm_srli_si128(v14, 4)), v64);
        HIDWORD(ThisMap) = HIDWORD(v15);
        v63 = v15 >> 32;
        v64 = v15;
      }
      v60 = 0i64;
      v61 = 0i64;
      if ( dwIndex >= gSystemInfo.dwNumberOfProcessors )
      {
        v6 = v64;
      }
      else
      {
        ThisMap = __PAIR__(HIDWORD(v61), v60);
        if ( gSystemInfo.dwNumberOfProcessors - dwIndex < 2 )
        {
          HIDWORD(v61) = v61;
          v16 = HIDWORD(v60);
        }
        else
        {
          v57 = gSystemInfo.dwNumberOfProcessors - 1;
          HIDWORD(v61) = v61;
          v16 = HIDWORD(v60);
          v17 = v61;
          do
          {
            v16 = (__PAIR__(*(&ProcessorIdleCycleTime + 2 * dwIndex + 1), *(&ProcessorIdleCycleTime + 2 * dwIndex))
                 + __PAIR__(v16, ThisMap)) >> 32;
            LODWORD(ThisMap) = *(&ProcessorIdleCycleTime + 2 * dwIndex) + ThisMap;
            v18 = *(&v66 + 2 * dwIndex) + v17;
            HIDWORD(ThisMap) = (__PAIR__(*(&v67 + 2 * dwIndex), *(&v66 + 2 * dwIndex)) + __PAIR__(HIDWORD(ThisMap), v17)) >> 32;
            v17 += *(&v66 + 2 * dwIndex);
            dwIndex += 2;
          }
          while ( dwIndex < v57 );
          HIDWORD(v61) = v18;
          dwNumberOfProcessors = gSystemInfo.dwNumberOfProcessors;
        }
        if ( dwIndex < dwNumberOfProcessors )
        {
          v19 = __CFADD__(*(&ProcessorIdleCycleTime + 2 * dwIndex), v64);
          v64 += *(&ProcessorIdleCycleTime + 2 * dwIndex);
          v63 += *(&ProcessorIdleCycleTime + 2 * dwIndex + 1) + v19;
          dwNumberOfProcessors = gSystemInfo.dwNumberOfProcessors;
        }
        v20 = __PAIR__(v16, HIDWORD(v61)) + ThisMap + __PAIR__(v63, v64);
        HIDWORD(ThisMap) = HIDWORD(v20);
        v6 = v20;
      }
      LODWORD(ThisMap) = theMap_1;
    }
    v21 = SystemProcessInfo->SpareLi3.LowPart;
    v64 = SystemProcessInfo->SpareLi3.LowPart + v6;
    HIDWORD(ThisMap) = (__PAIR__(HIDWORD(ThisMap), v21) + __PAIR__(SystemProcessInfo->SpareLi3.HighPart, v6)) >> 32;
    v6 += v21;
    v63 = HIDWORD(ThisMap);
    if ( ThisMap )
    {
      v22 = *ThisMap;
      v23 = v22;
      v24 = SystemProcessInfo->UniqueProcessId;
      v25 = *(v22 + 4);
      while ( !*(v25 + 13) )
      {
        if ( *(v25 + 16) >= v24 )
        {
          v23 = v25;
          v25 = *v25;
        }
        else
        {
          v25 = *(v25 + 8);
        }
      }
      if ( v23 == v22 || v24 < *(v23 + 16) )
      {
        v56 = v22;
        v26 = &v56;
      }
      else
      {
        v55 = v23;
        v26 = &v55;
      }
      v27 = *v26;
      if ( v27 != v22 )
      {
        v28 = v27[5];
        if ( *(v28 + 32) == SystemProcessInfo->CreateTime.LowPart )
        {
          LODWORD(ThisMap) = theMap_1;
          if ( *(v28 + 36) != SystemProcessInfo->CreateTime.HighPart )
          {
LABEL_35:
            v6 = v64;
            HIDWORD(ThisMap) = v63;
            goto LABEL_36;
          }
          sub_FF55B0(theMap_1, &a2[1], v27);
          dwNumberOfProcessors = gSystemInfo.dwNumberOfProcessors;
        }
      }
      LODWORD(ThisMap) = theMap_1;
      goto LABEL_35;
    }
LABEL_36:
    if ( !SystemProcessInfo->NextEntryOffset )
      break;
    SystemProcessInfo = (SystemProcessInfo + SystemProcessInfo->NextEntryOffset);
  }
  theMap_2 = theMap_1;
  if ( theMap_1 )
  {
    _Node = theMap_1->_Header->_Left;
    if ( _Node != theMap_1->_Header )
    {
      v31 = dwProcessorIdleCycleTimeInfoLength;
      do
      {
        v32 = _Node[1]._Parent;
        v33 = v32[1]._Right;
        v19 = __CFADD__(v33, *v31);
        *v31 += v33;
        v31[1] += *&v32[1]._Color + v19;
        if ( !_Node->_IsNil )
        {
          _Node_1 = _Node->_Right;
          if ( _Node_1->_IsNil )
          {
            for ( _Node_3 = _Node->_Parent; !_Node_3->_IsNil; _Node_3 = _Node_3->_Parent )
            {
              if ( _Node != _Node_3->_Right )
                break;
              _Node = _Node_3;
            }
            _Node = _Node_3;
          }
          else
          {
            _Node = _Node->_Right;
            for ( _Node_2 = _Node_1->_Left; !_Node_2->_IsNil; _Node_2 = _Node_2->_Left )
              _Node = _Node_2;
          }
        }
      }
      while ( _Node != theMap_2->_Header );
      dwNumberOfProcessors = gSystemInfo.dwNumberOfProcessors;
    }
  }
  dwIndex_1 = 0;
  if ( dwNumberOfProcessors && dwNumberOfProcessors >= 4 )
  {
    v38 = 0i64;
    v39 = 0i64;
    pProcessorIdleCycleTimeInfo2 = pProcessorIdleCycleTimeInfo + 2;
    do
    {
      *v41.m128i_i8 = pProcessorIdleCycleTimeInfo2[-2];
      pProcessorIdleCycleTimeInfo2 += 4;
      v41.m128i_i64[1] = pProcessorIdleCycleTimeInfo2[-5].CycleTime;
      dwIndex_1 += 4;
      v38 = _mm_add_epi64(v38, v41);
      *v41.m128i_i8 = pProcessorIdleCycleTimeInfo2[-4];
      v41.m128i_i64[1] = pProcessorIdleCycleTimeInfo2[-3].CycleTime;
      v39 = _mm_add_epi64(v39, v41);
    }
    while ( dwIndex_1 < dwNumberOfProcessors - (dwNumberOfProcessors & 3) );
    v42 = _mm_add_epi64(v38, v39);
    v43 = _mm_add_epi64(v42, _mm_srli_si128(v42, 8));
    LODWORD(ThisMap) = _mm_cvtsi128_si32(v43);
    v44 = ThisMap + __PAIR__(_mm_cvtsi128_si32(_mm_srli_si128(v43, 4)), v64);
    v63 = v44 >> 32;
    v64 = v44;
  }
  *a2 = 0i64;
  v60 = 0i64;
  if ( dwIndex_1 >= dwNumberOfProcessors )
  {
    LODWORD(v52) = v64;
  }
  else
  {
    v45 = __PAIR__(HIDWORD(v60), a2[0]);
    if ( dwNumberOfProcessors - dwIndex_1 < 2 )
    {
      HIDWORD(v61) = v60;
      v48 = a2[1];
    }
    else
    {
      v46 = dwNumberOfProcessors - 1;
      v47 = v60;
      dwProcessorIdleCycleTimeInfoLength = v46;
      v48 = a2[1];
      do
      {
        v49 = pProcessorIdleCycleTimeInfo[dwIndex_1].CycleTime + __PAIR__(v48, v45);
        v48 = HIDWORD(v49);
        LODWORD(v45) = v49;
        v50 = pProcessorIdleCycleTimeInfo[dwIndex_1 + 1].CycleTime + __PAIR__(HIDWORD(v45), v47);
        HIDWORD(v45) = HIDWORD(v50);
        v47 = v50;
        dwIndex_1 += 2;
      }
      while ( dwIndex_1 < dwProcessorIdleCycleTimeInfoLength );
      HIDWORD(v61) = v50;
      dwNumberOfProcessors = gSystemInfo.dwNumberOfProcessors;
    }
    if ( dwIndex_1 >= dwNumberOfProcessors )
    {
      v51 = v63;
    }
    else
    {
      v51 = (pProcessorIdleCycleTimeInfo[dwIndex_1].CycleTime + __PAIR__(v63, v64)) >> 32;
      v64 += LODWORD(pProcessorIdleCycleTimeInfo[dwIndex_1].CycleTime);
    }
    v52 = __PAIR__(v48, HIDWORD(v61)) + v45 + __PAIR__(v51, v64);
  }
  return v52;
}

//----- (00FDE920) --------------------------------------------------------
signed int sub_FDE920()
{
  HANDLE v0; // edi
  SYSTEM_HANDLE_INFORMATION *v1; // eax
  ULONG v2; // esi
  int v3; // esi
  signed int result; // eax
  SYSTEM_HANDLE_INFORMATION *v5; // eax
  ULONG v6; // esi
  int v7; // esi
  void *pEntry; // [esp+4h] [ebp-808h]
  __int16 v9; // [esp+8h] [ebp-804h]

  if ( *CreateJobObjectW )
  {
    v0 = CreateJobObjectW(0, 0);
    if ( v0 )
    {
      GetSystemProcessInfo(&gpSystemProcessInfo, &gnSystemProcessInfoLength);
      QuerySystemHandleInfo(0);
      v1 = gpSystemHandleInfo2;
      if ( gpSystemHandleInfo2 )
        v2 = gpSystemHandleInfo2->NumberOfHandles;
      else
        v2 = 0;
      v3 = v2 - 1;
      if ( v3 >= 0 )
      {
        while ( 1 )
        {
          GetHandleTableEntry(v1, v3, &pEntry);
          if ( *(pEntry + 1) == GetCurrentProcessId() && *(pEntry + 2) == v0 )
            break;
          if ( --v3 < 0 )
            goto LABEL_12;
          v1 = gpSystemHandleInfo2;
        }
        v9 = 0;
        sub_FDC750(&gpszObjectTypeNames[64 * *(pEntry + 9)], pEntry, &v9, 0x400u, 0);
      }
LABEL_12:
      CloseHandle(v0);
    }
    result = 1;
  }
  else
  {
    GetSystemProcessInfo(&gpSystemProcessInfo, &gnSystemProcessInfoLength);
    QuerySystemHandleInfo(0);
    v5 = gpSystemHandleInfo2;
    if ( gpSystemHandleInfo2 )
      v6 = gpSystemHandleInfo2->NumberOfHandles;
    else
      v6 = 0;
    v7 = v6 - 1;
    if ( v7 >= 0 )
    {
      while ( 1 )
      {
        GetHandleTableEntry(v5, v7, &pEntry);
        if ( !gpszObjectTypeNames[64 * *(pEntry + 9)] )
        {
          v9 = 0;
          sub_FDC750(&gpszObjectTypeNames[64 * *(pEntry + 9)], pEntry, &v9, 0x400u, 0);
        }
        if ( --v7 < 0 )
          break;
        v5 = gpSystemHandleInfo2;
      }
    }
    result = 1;
  }
  return result;
}

//----- (00FDEAA0) --------------------------------------------------------
LPVOID __cdecl sub_FDEAA0(LPCVOID pBlock, int a2)
{
  LPVOID result; // eax
  unsigned int puLen; // [esp+8h] [ebp-Ch]
  __int16 v4; // [esp+Ch] [ebp-8h]
  LPVOID lpBuffer; // [esp+10h] [ebp-4h]

  v4 = 1024;
  lpBuffer = &v4;
  VerQueryValueW(pBlock, L"\\VarFileInfo\\Translation", &lpBuffer, &puLen);
  result = sub_FDC190(pBlock, *lpBuffer, *(lpBuffer + 1), a2);
  if ( !result )
  {
    result = sub_FDC190(pBlock, *lpBuffer, 0x4E4u, a2);
    if ( !result )
      result = sub_FDC190(pBlock, 1033, 0x4E4u, a2);
  }
  return result;
}

//----- (00FDEB20) --------------------------------------------------------
DWORD __cdecl sub_FDEB20(void *a1, PVOID *a2, DWORD *a3, _DWORD *a4, _DWORD *a5, _DWORD *a6, DWORD *a7)
{
  DWORD result; // eax
  unsigned int v8; // ecx
  int v9; // eax

  *a4 = 0;
  *a5 = 0;
  *a6 = 0;
  *a7 = 0;
  while ( 1 )
  {
    if ( QueryWorkingSet(a1, *a2, *a3) )
    {
      if ( !*a2 )
        goto LABEL_7;
      if ( *a3 >= 4 * **a2 )
        break;
    }
    if ( *a2 )
      free(*a2);
LABEL_7:
    result = GetLastError();
    if ( result != 24 )
    {
      *a2 = 0;
      *a3 = 0;
      return result;
    }
    *a3 += 0x4000;
    *a2 = malloc(*a3);
  }
  v8 = 0;
  if ( **a2 )
  {
    do
    {
      v9 = *(*a2 + v8 + 1);
      ++*a4;
      if ( v9 & 0x100 )
      {
        ++*a6;
        if ( (v9 & 0xE0u) > 0x20 )
          ++*a7;
      }
      else
      {
        ++*a5;
      }
      ++v8;
    }
    while ( v8 < **a2 );
  }
  *a4 *= gSystemInfo.dwPageSize;
  *a5 *= gSystemInfo.dwPageSize;
  *a6 *= gSystemInfo.dwPageSize;
  result = gSystemInfo.dwPageSize * *a7;
  *a7 = result;
  return result;
}

//----- (00FDEC30) --------------------------------------------------------
BOOL __stdcall DlgSystemInfoGPUNodes(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
  int v4; // ebx
  int v5; // esi
  HWND v6; // eax
  int v7; // ST24_4
  int v8; // ST20_4
  int v9; // ST1C_4
  HWND v10; // eax
  HICON v11; // eax
  HWND v12; // eax
  int v13; // ebx
  int v14; // eax
  int v15; // eax
  signed int v16; // esi
  HWND v17; // eax
  CGraphData *v18; // eax
  int v19; // esi
  unsigned int v20; // edx
  int v21; // ecx
  LONG v22; // eax
  LONG v23; // ecx
  int v24; // ebx
  int v25; // esi
  HWND v26; // esi
  CResizer *v27; // eax
  CResizer *v28; // esi
  char *v29; // eax
  HWND v30; // eax
  struct tagResizerItem *v31; // eax
  HMENU v32; // ST2C_4
  HWND v33; // eax
  double v34; // xmm0_8
  double *v35; // eax
  DWORD v37; // ecx
  int v38; // esi
  int v39; // ebx
  int v40; // esi
  int v41; // ebx
  HWND v42; // eax
  HWND v43; // eax
  int v44; // ebx
  int v45; // esi
  HWND v46; // eax
  double v47; // [esp+10h] [ebp-94h]
  LRESULT wParama; // [esp+14h] [ebp-90h]
  double v49; // [esp+18h] [ebp-8Ch]
  int v50; // [esp+1Ch] [ebp-88h]
  double v51; // [esp+20h] [ebp-84h]
  int v52; // [esp+24h] [ebp-80h]
  double v53; // [esp+28h] [ebp-7Ch]
  double v54; // [esp+28h] [ebp-7Ch]
  int v55; // [esp+2Ch] [ebp-78h]
  int v56; // [esp+30h] [ebp-74h]
  int nWidth; // [esp+34h] [ebp-70h]
  int v58; // [esp+38h] [ebp-6Ch]
  double v59; // [esp+3Ch] [ebp-68h]
  signed int ArgList; // [esp+40h] [ebp-64h]
  LONG ArgLista; // [esp+40h] [ebp-64h]
  struct tagPOINT Point; // [esp+44h] [ebp-60h]
  int v63; // [esp+4Ch] [ebp-58h]
  HMENU hMenu; // [esp+50h] [ebp-54h]
  struct tagRECT v65; // [esp+54h] [ebp-50h]
  struct tagRECT Rect; // [esp+64h] [ebp-40h]
  WCHAR String; // [esp+74h] [ebp-30h]
  int v68; // [esp+A0h] [ebp-4h]

  if ( msg > 0x113 )
  {
    if ( msg > 0x138 )
    {
      if ( msg == 1124 )
      {
        v43 = GetDlgItem(hDlg, 2501);
        ShowWindow(v43, 0);
        v44 = 1;
        if ( gdwAdapterRuntingTime + 1 > 1 )
        {
          v45 = 2503;
          do
          {
            v46 = GetDlgItem(hDlg, v45);
            ShowWindow(v46, 5);
            ++v44;
            v45 += 2;
          }
          while ( v44 < gdwAdapterRuntingTime + 1 );
        }
      }
    }
    else if ( msg == 312 || msg == 307 || msg == 310 )
    {
      return PE_FillControl(hDlg, wParam);
    }
    return 0;
  }
  if ( msg == 275 )
  {
    v40 = 0;
    if ( gdwAdapterRuntingTime > 0 )
    {
      v41 = 2502;
      do
      {
        v42 = GetDlgItem(hDlg, v41);
        SendMessageW(v42, 0x400u, 0, 0);
        ++v40;
        v41 += 2;
      }
      while ( v40 < gdwAdapterRuntingTime );
    }
    return 0;
  }
  if ( msg > 0x110 )
  {
    if ( msg == 273 )
    {
      if ( wParam == 1 )
      {
        v37 = 0;
        v38 = 0;
        hMenu = 0;
        if ( gdwAdapterRuntingTime > 0 )
        {
          v39 = 2503;
          do
          {
            if ( IsDlgButtonChecked(hDlg, v39) == 1 )
            {
              v37 = (1 << v38) | hMenu;
              hMenu = ((1 << v38) | hMenu);
            }
            else
            {
              v37 = hMenu;
            }
            ++v38;
            v39 += 2;
          }
          while ( v38 < gdwAdapterRuntingTime );
        }
        if ( v37 != gConfig.dwGpuNodeUsageMask )
        {
          gConfig.dwGpuNodeUsageMask = v37;
          gpGraphInfoOfGPU->field_888 = 0;
          gpGraphInfoOfGPU->field_88C = 0;
        }
        EndDialog(hDlg, 0);
      }
      else if ( wParam == 2 )
      {
        EndDialog(hDlg, 0);
      }
    }
    return 0;
  }
  if ( msg != 272 )
  {
    if ( msg == 5 )
    {
      v4 = 0;
      if ( gdwAdapterRuntingTime > 0 )
      {
        v5 = 2503;
        do
        {
          v6 = GetDlgItem(hDlg, v5 - 1);
          GetWindowRect(v6, &Rect);
          Point.x = Rect.left;
          Point.y = Rect.bottom + 2;
          ScreenToClient(hDlg, &Point);
          v7 = Rect.right - Rect.left;
          v8 = Point.y;
          v9 = Point.x;
          v10 = GetDlgItem(hDlg, v5);
          SetWindowPos(v10, 0, v9, v8, v7, 14, 0);
          ++v4;
          v5 += 2;
        }
        while ( v4 < gdwAdapterRuntingTime );
      }
    }
    else if ( msg == 36 )
    {
      *(lParam + 8) = 2 * gdwVirtualScreenWidth;
    }
    return 0;
  }
  v11 = LoadIconW(ghInstance, 0x65);
  SendMessageW(hDlg, 0x80u, 0, v11);
  v12 = GetDlgItem(hDlg, 2501);
  GetWindowRect(v12, &v65);
  v13 = gdwAdapterRuntingTime;
  v56 = gdwAdapterRuntingTime;
  if ( gdwAdapterRuntingTime > 8 )
  {
    v13 = 8 * (gdwAdapterRuntingTime / 8 > 16) + 8;
    v56 = 8 * (gdwAdapterRuntingTime / 8 > 16) + 8;
  }
  v14 = (v13 + gdwAdapterRuntingTime - 1) / v13;
  v58 = v14;
  v15 = v13 * v14 - gdwAdapterRuntingTime;
  if ( v15 )
  {
    v13 += v15 / -2;
    v56 = v13;
    v58 = (v13 + gdwAdapterRuntingTime - 1) / v13;
  }
  v16 = 4;
  if ( gdwAdapterRuntingTime > 16 )
    v16 = 3;
  ArgList = v16;
  if ( gdwAdapterRuntingTime > 32 )
    ArgList = --v16;
  nWidth = (v65.right - v16 * (v13 - 1) - v65.left) / v13;
  v52 = (v65.bottom - v16 * (v58 - 1) - v65.top) / v58;
  v17 = GetDlgItem(hDlg, 2501);
  GetWindowRect(v17, &v65);
  MapWindowPoints(0, hDlg, &v65, 2u);
  if ( !dword_107BA1C )
  {
    v18 = InitGraphData(gdwAdapterRuntingTime, 1, 0);
    v19 = 0;
    dword_107BA1C = v18;
    if ( gdwAdapterRuntingTime > 0 )
    {
      v20 = 0;
      while ( 1 )
      {
        v18[v20 / 0x898].m_ProcessorID = v19;
        *(v20 + dword_107BA1C + 28) = 1;
        *(v20 + dword_107BA1C + 32) = 4;
        *(v20 + dword_107BA1C + 48) = 8421631;
        *(v20 + dword_107BA1C + 40) = db_onehundred;
        *(v20 + dword_107BA1C + 2172) = gpGraphInfoOfGPU;
        if ( v19 )
        {
          v21 = dword_107BA1C;
          *(v20 + dword_107BA1C + 2148) = *(dword_107BA1C + 2148);
          *(v20 + dword_107BA1C + 2152) = *(v21 + 2152);
        }
        ++v19;
        v20 += 2200;
        if ( v19 >= gdwAdapterRuntingTime )
          break;
        v18 = dword_107BA1C;
      }
    }
    v16 = ArgList;
  }
  Rect.bottom = v65.left;
  wParama = SendMessageW(hDlg, 0x31u, 0, 0);
  v22 = 0;
  ArgLista = 0;
  if ( gdwAdapterRuntingTime > 0 )
  {
    v63 = 0;
    v50 = v16 + nWidth;
    v23 = v65.left;
    hMenu = 2503;
    do
    {
      v24 = 0;
      Point.y = v22 + 1;
      v55 = (v22 + 1) % v56;
      if ( !v55 )
        v24 = v65.right - v23 - nWidth;
      v25 = MulDiv(14, gLogPixelSize.y, 96);
      CreateWindowExW(
        0,
        L"Static",
        0,
        0x40000000u,
        v65.left,
        v65.top,
        v24 + nWidth,
        v52 - v25 - 1,
        hDlg,
        (hMenu - 1),
        ghInstance,
        0);
      CreateGraphWindow(hDlg, hMenu - 1, (v63 + dword_107BA1C));
      v26 = CreateWindowExW(
              0,
              L"Button",
              0,
              0x40010003u,
              v65.left,
              v52 + v65.top - v25,
              nWidth,
              v25,
              hDlg,
              hMenu,
              ghInstance,
              0);
      sub_FA13E0(&String, L"Engine %d", ArgLista);
      SetWindowTextW(v26, &String);
      SendMessageW(v26, 0x30u, wParama, 1);
      EnableWindow(v26, 1);
      ShowWindow(v26, 5);
      if ( (1 << ArgLista) & gConfig.dwGpuNodeUsageMask )
        CheckDlgButton(hDlg, hMenu, 1u);
      v23 = v50 + v65.left;
      v65.left += v50;
      if ( !v55 )
      {
        v23 = Rect.bottom;
        v65.left = Rect.bottom;
        v65.top += v52 + 2;
      }
      v22 = Point.y;
      v63 += 2200;
      ArgLista = Point.y;
      hMenu = (hMenu + 2);
    }
    while ( Point.y < gdwAdapterRuntingTime );
    v13 = v56;
  }
  v27 = operator new(0x40u);
  v28 = v27;
  Point.y = v27;
  v68 = 0;
  if ( v27 )
  {
    v27->baseclass.m_hThemeHandle = 0;
    LOBYTE(v68) = 1;
    v27->baseclass.vtptr = &CResizer::`vftable';
    v27->m_OldWndProc = 0;
    v27->m_nXRatio = 50;
    v27->m_nYRatio = 67;
    v27->m_pItem = 0;
    v27->m_dwItemCount = 0;
    v27->m_FixedBorder = 1;
    if ( hDlg )
      CResizer::InitWnd(v27, hDlg);
  }
  else
  {
    v28 = 0;
  }
  v68 = -1;
  *&Point = 0.0;
  *&Rect.right = 0i64;
  v63 = 0;
  if ( gdwAdapterRuntingTime > 0 )
  {
    v29 = 2502;
    hMenu = 2502;
    v47 = 1.0 / v13;
    v49 = 1.0 / v58;
    do
    {
      v30 = GetDlgItem(hDlg, v29);
      v59 = v49 + *&Rect.right;
      v53 = v49 + *&Rect.right;
      if ( v49 + *&Rect.right >= 0.99999 )
        v53 = db_one;
      v31 = CResizer::AddItem(v28, v30, 1);
      v32 = hMenu;
      *&v31->m_rect2.left = *&Rect.right;
      *&v31->m_rect2.right = v53;
      v33 = GetDlgItem(hDlg, v32);
      v34 = v47 + *&Point;
      v51 = v47 + *&Point;
      v54 = v47 + *&Point;
      if ( v47 + *&Point >= 0.99999 )
        v54 = db_one;
      if ( v33 )
      {
        v35 = CResizer::AddItem(v28, v33, 1);
        *v35 = *&Point;
        v35[1] = v54;
        v34 = v51;
      }
      *&Point = v34;
      if ( !(++v63 % v13) )
      {
        *&Point = 0.0;
        *&Rect.right = v59;
      }
      v29 = hMenu + 2;
      hMenu = (hMenu + 2);
    }
    while ( v63 < gdwAdapterRuntingTime );
  }
  SendMessageW(hDlg, 0x464u, 0, 0);
  SetTimer(hDlg, 0, 0x3E8u, 0);
  return 1;
}
// 103C888: using guessed type void *CResizer::`vftable';
// 103CDC0: using guessed type double db_onehundred;
// 1064E28: using guessed type int gdwVirtualScreenWidth;
// 107BA1C: using guessed type int dword_107BA1C;

//----- (00FDF3E0) --------------------------------------------------------
signed int __cdecl sub_FDF3E0(int ThreadId, int a2, int a3)
{
  void *v3; // esi
  signed int result; // eax
  int v5; // [esp+4h] [ebp-10h]
  int v6; // [esp+8h] [ebp-Ch]
  int v7; // [esp+Ch] [ebp-8h]
  int v8; // [esp+10h] [ebp-4h]

  v5 = ThreadId;
  v6 = a2;
  v7 = a3;
  v3 = _beginthreadex(0, 0, sub_FDC090, &v5, 0, &ThreadId);
  if ( WaitForSingleObject(v3, 0x1388u) == 258 )
  {
    TerminateThread(v3, 1u);
    CloseHandle(v3);
    result = 32;
  }
  else
  {
    CloseHandle(v3);
    result = v8;
  }
  return result;
}

//----- (00FDF460) --------------------------------------------------------
char __cdecl sub_FDF460(_DWORD *a1)
{
  void *v1; // ecx
  SYSTEM_HANDLE_INFORMATION *v2; // eax
  unsigned int i; // esi
  void *pEntry; // [esp+0h] [ebp-4h]

  pEntry = v1;
  v2 = gpSystemHandleInfo2;
  if ( !gpSystemHandleInfo2 )
    return 0;
  for ( i = 0; v2 && i < v2->NumberOfHandles; ++i )
  {
    GetHandleTableEntry(v2, i, &pEntry);
    if ( *(pEntry + 1) == a1[9] && *(pEntry + 2) == a1[11] && *pEntry == a1[10] )
      return 1;
    v2 = gpSystemHandleInfo2;
  }
  return 0;
}

//----- (00FDF4D0) --------------------------------------------------------
int __cdecl sub_FDF4D0(int a1, SECURITY_INFORMATION SecurityInformation, PSECURITY_DESCRIPTOR SecurityDescriptor, PSECURITY_DESCRIPTOR pSecurityDescriptor, int a5)
{
  SECURITY_INFORMATION v5; // esi
  DWORD v6; // eax
  void *v7; // eax
  void *v8; // ebx
  signed int v10; // edi
  int v11; // esi
  bool v12; // al

  v5 = SecurityInformation;
  switch ( SecurityInformation )
  {
    case 1u:
      v6 = 0x80000;
      break;
    case 4u:
      v6 = 0x40000;
      break;
    case 8u:
      v6 = 0x1000000;
      break;
    default:
      v6 = SecurityInformation;
      break;
  }
  v7 = PE_DuplicateProcessHandle(*(a1 + 36), *(a1 + 44), v6);
  v8 = v7;
  if ( !v7 || !SetKernelObjectSecurity(v7, v5, SecurityDescriptor) )
    return 5;
  v10 = 5;
  if ( pSecurityDescriptor )
  {
    v11 = v5 | 3;
    if ( v11 == 1 )
      v11 = 5;
    v12 = GetKernelObjectSecurity(v8, v11, pSecurityDescriptor, 0x2000u, &SecurityInformation);
    *a5 = v12;
  }
  CloseHandle(v8);
  if ( !a5 )
    return 0;
  if ( *a5 )
    v10 = 0;
  return v10;
}

//----- (00FDF580) --------------------------------------------------------
int __stdcall Fake_GetProcessDEPPolicy(HANDLE hProcess, LPDWORD lpFlags, PBOOL lpPermanent)
{
  int (__stdcall *v3)(HANDLE, LPDWORD, PBOOL); // eax
  HMODULE v4; // eax

  v3 = GetProcessDEPPolicy;
  if ( GetProcessDEPPolicy )
    return v3(hProcess, lpFlags, lpPermanent);
  v4 = GetModuleHandleW(L"KERNEL32.DLL");
  v3 = GetProcAddress(v4, "GetProcessDEPPolicy");
  GetProcessDEPPolicy = v3;
  if ( v3 )
    return v3(hProcess, lpFlags, lpPermanent);
  SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
  return 0;
}

//----- (00FDF5C0) --------------------------------------------------------
int __stdcall sub_FDF5C0(int a1, int a2, int a3, int a4)
{
  int (__stdcall *v4)(int, int, int, int); // eax
  HMODULE v5; // eax

  v4 = GetProcessMitigationPolicy;
  if ( GetProcessMitigationPolicy )
    return v4(a1, a2, a3, a4);
  v5 = GetModuleHandleW(L"KERNEL32.DLL");
  v4 = GetProcAddress(v5, "GetProcessMitigationPolicy");
  GetProcessMitigationPolicy = v4;
  if ( v4 )
    return v4(a1, a2, a3, a4);
  SetLastError(0x78u);
  return 0;
}

//----- (00FDF600) --------------------------------------------------------
char __cdecl sub_FDF600(_DWORD *a1, int a2, int a3, int a4)
{
  _DWORD *v4; // eax
  int v5; // ecx

  v4 = a1;
  if ( !a1 )
    return 0;
  while ( 1 )
  {
    if ( v4[10] == a2 && v4[146] == a4 )
    {
      v5 = v4[11];
      if ( v5 == a3 || v5 == 16777343 && !a3 )
        break;
      if ( !v5 && a3 == 16777343 )
        break;
    }
    v4 = v4[547];
    if ( !v4 )
      return 0;
  }
  return 1;
}

//----- (00FDF660) --------------------------------------------------------
int __thiscall sub_FDF660(int *this, HMODULE hModule, int a3)
{
  int *v3; // edi
  HRSRC v4; // eax
  unsigned __int16 *v5; // eax
  unsigned __int16 *v6; // ebx
  int v7; // eax
  int v8; // esi
  int result; // eax

  v3 = this;
  v4 = FindResourceW(hModule, ((a3 >> 4) + 1), 6);
  if ( !v4 )
    return 0;
  v5 = ATL::AtlGetStringResourceImage(hModule, v4, a3);
  v6 = v5;
  if ( !v5 )
    return 0;
  v7 = WideCharToMultiByte(3u, 0, v5 + 1, *v5, 0, 0, 0, 0);
  v8 = v7;
  if ( v7 < 0 )
    goto LABEL_12;
  if ( ((*(*v3 - 8) - v7) | (1 - *(*v3 - 4))) < 0 )
    sub_FE2330(v3, v7);
  WideCharToMultiByte(3u, 0, v6 + 1, *v6, *v3, v8, 0, 0);
  if ( v8 > *(*v3 - 8) )
LABEL_12:
    ATL::AtlThrowImpl(-2147024809);
  *(*v3 - 12) = v8;
  result = 1;
  *(v8 + *v3) = 0;
  return result;
}

//----- (00FDF720) --------------------------------------------------------
char LoadSystemApis()
{
  HMODULE v0; // eax
  HMODULE v2; // eax
  HMODULE v3; // eax
  HMODULE v4; // eax
  HMODULE v5; // eax
  HMODULE v6; // eax
  HMODULE v7; // eax
  HMODULE v8; // eax
  HMODULE v9; // eax
  HMODULE v10; // eax
  HMODULE v11; // eax
  HMODULE v12; // eax
  HMODULE v13; // eax
  HMODULE v14; // eax
  HMODULE v15; // eax
  HMODULE v16; // eax
  HMODULE v17; // eax
  HMODULE v18; // eax
  HMODULE v19; // eax
  HMODULE v20; // eax
  HMODULE v21; // eax
  HMODULE v22; // eax
  HMODULE v23; // eax
  HMODULE v24; // eax
  HMODULE v25; // eax
  HMODULE v26; // eax
  HMODULE v27; // eax
  HMODULE v28; // eax
  HMODULE v29; // eax
  HMODULE v30; // eax
  HMODULE v31; // eax
  HMODULE v32; // eax
  HMODULE v33; // eax
  HMODULE v34; // eax
  HMODULE v35; // eax
  HMODULE v36; // eax
  HMODULE v37; // eax
  HMODULE v38; // eax
  HMODULE v39; // eax
  HMODULE v40; // eax
  HMODULE v41; // eax
  HMODULE v42; // eax
  HMODULE v43; // eax
  HMODULE v44; // eax
  HMODULE v45; // eax
  HMODULE v46; // eax
  HMODULE v47; // eax
  HMODULE v48; // eax
  HMODULE v49; // eax
  HMODULE v50; // eax
  HMODULE v51; // eax
  HMODULE v52; // eax
  HMODULE v53; // eax
  HMODULE v54; // eax
  HMODULE v55; // eax
  HMODULE v56; // eax
  HMODULE hModule_1; // eax
  HMODULE v58; // eax
  HMODULE v59; // eax
  int (__stdcall *FindExecutableImage)(PCSTR, PCSTR, PSTR); // eax
  int (__stdcall *v61)(LPCWSTR, LPCWSTR, int); // ecx
  HMODULE v62; // eax
  HMODULE v63; // eax
  HMODULE v64; // eax
  HMODULE v65; // eax
  HMODULE v66; // eax
  HMODULE v67; // eax
  HMODULE v68; // eax
  HMODULE v69; // eax
  HMODULE v70; // eax
  HMODULE v71; // eax
  HMODULE v72; // eax
  HMODULE v73; // eax
  HMODULE v74; // eax
  HMODULE v75; // eax
  HKEY hKey; // [esp+8h] [ebp-218h]
  DWORD cbLength; // [esp+Ch] [ebp-214h]
  HMODULE hModule; // [esp+10h] [ebp-210h]
  WCHAR Text; // [esp+14h] [ebp-20Ch]

  InitTlhlpApis();
  v0 = GetModuleHandleW(L"ntdll.dll");
  NtQuerySystemInformation = GetProcAddress(v0, "NtQuerySystemInformation");
  if ( !NtQuerySystemInformation )
  {
    swprintf(
      &Text,
      L"Not able to run on this version of Windows:\nMissing function: %s",
      L"Ntdll!NtQuerySystemInformation");
LABEL_3:
    MessageBoxW(0, &Text, L"Process Explorer", 0x10u);
    return 0;
  }
  v2 = GetModuleHandleW(L"ntdll.dll");
  gpfn_NtQuerySymbolicLinkObject = GetProcAddress(v2, "NtQuerySymbolicLinkObject");
  if ( !gpfn_NtQuerySymbolicLinkObject )
  {
    swprintf(
      &Text,
      L"Not able to run on this version of Windows:\nMissing function: %s",
      L"Ntdll!NtQuerySymbolicLinkObject");
    goto LABEL_3;
  }
  v3 = GetModuleHandleW(L"ntdll.dll");
  NtQueryDirectoryObject = GetProcAddress(v3, "NtQueryDirectoryObject");
  if ( !NtQueryDirectoryObject )
  {
    swprintf(
      &Text,
      L"Not able to run on this version of Windows:\nMissing function: %s",
      L"Ntdll!NtQueryDirectoryObject");
    goto LABEL_3;
  }
  v4 = GetModuleHandleW(L"ntdll.dll");
  gpfn_NtOpenSymbolicLinkObject = GetProcAddress(v4, "NtOpenSymbolicLinkObject");
  if ( !gpfn_NtOpenSymbolicLinkObject )
    return ReportMsg(L"Ntdll!NtOpenSymbolicLinkObject");
  v5 = GetModuleHandleW(L"ntdll.dll");
  NtOpenDirectoryObject = GetProcAddress(v5, "NtOpenDirectoryObject");
  if ( !NtOpenDirectoryObject )
    return ReportMsg(L"Ntdll!NtOpenDirectoryObject");
  v6 = GetModuleHandleW(L"ntdll.dll");
  NtQueryObject = GetProcAddress(v6, "NtQueryObject");
  if ( !NtQueryObject )
    return ReportMsg(L"Ntdll!NtQueryObject");
  v7 = GetModuleHandleW(L"ntdll.dll");
  NtQueryInformationProcess = GetProcAddress(v7, "NtQueryInformationProcess");
  if ( !NtQueryInformationProcess )
    return ReportMsg(L"Ntdll!NtQueryInformationProcess");
  v8 = GetModuleHandleW(L"ntdll.dll");
  NtSetInformationProcess = GetProcAddress(v8, "NtSetInformationProcess");
  if ( !NtSetInformationProcess )
    return ReportMsg(L"Ntdll!NtSetInformationProcess");
  v9 = GetModuleHandleW(L"ntdll.dll");
  NtSetInformationProcess_0 = GetProcAddress(v9, "NtQuerySemaphore");
  if ( !NtSetInformationProcess_0 )
    return ReportMsg(L"Ntdll!NtQuerySemaphore");
  v10 = GetModuleHandleW(L"ntdll.dll");
  gpfn_NtOpenSymbolicLinkObject = GetProcAddress(v10, "NtOpenSymbolicLinkObject");
  if ( !gpfn_NtOpenSymbolicLinkObject )
    return ReportMsg(L"Ntdll!NtOpenSymbolicLinkObject");
  v11 = GetModuleHandleW(L"ntdll.dll");
  NtQuerySection = GetProcAddress(v11, "NtQuerySection");
  if ( !NtQuerySection )
    return ReportMsg(L"Ntdll!NtQuerySection");
  v12 = GetModuleHandleW(L"ntdll.dll");
  NtQueryEvent = GetProcAddress(v12, "NtQueryEvent");
  if ( !NtQueryEvent )
    return ReportMsg(L"Ntdll!NtQueryEvent");
  v13 = GetModuleHandleW(L"ntdll.dll");
  NtQueryMutant = GetProcAddress(v13, "NtQueryMutant");
  if ( !NtQueryMutant )
    return ReportMsg(L"Ntdll!NtQueryMutant");
  v14 = GetModuleHandleW(L"ntdll.dll");
  NtResumeThread = GetProcAddress(v14, "NtResumeThread");
  if ( !NtResumeThread )
    return ReportMsg(L"Ntdll!NtResumeThread");
  v15 = GetModuleHandleW(L"ntdll.dll");
  NtSuspendThread = GetProcAddress(v15, "NtSuspendThread");
  if ( !NtSuspendThread )
    return ReportMsg(L"Ntdll!NtSuspendThread");
  v16 = GetModuleHandleW(L"ntdll.dll");
  NtOpenThread = GetProcAddress(v16, "NtOpenThread");
  if ( !NtOpenThread )
    return ReportMsg(L"Ntdll!NtOpenThread");
  v17 = GetModuleHandleW(L"ntdll.dll");
  NtQueryInformationThread = GetProcAddress(v17, "NtQueryInformationThread");
  if ( !NtQueryInformationThread )
    return ReportMsg(L"Ntdll!NtQueryInformationThread");
  v18 = GetModuleHandleW(L"ntdll.dll");
  NtQueryVirtualMemory = GetProcAddress(v18, "NtQueryVirtualMemory");
  if ( !NtQueryVirtualMemory )
    return ReportMsg(L"Ntdll!NtQueryVirtualMemory");
  v19 = GetModuleHandleW(L"ntdll.dll");
  RtlCreateQueryDebugBuffer = GetProcAddress(v19, "RtlCreateQueryDebugBuffer");
  if ( !RtlCreateQueryDebugBuffer )
    return ReportMsg(L"Ntdll!RtlCreateQueryDebugBuffer");
  v20 = GetModuleHandleW(L"ntdll.dll");
  RtlQueryProcessDebugInformation = GetProcAddress(v20, "RtlQueryProcessDebugInformation");
  if ( !RtlQueryProcessDebugInformation )
    return ReportMsg(L"Ntdll!RtlQueryProcessDebugInformation");
  v21 = GetModuleHandleW(L"ntdll.dll");
  RtlDestroyQueryDebugBuffer = GetProcAddress(v21, "RtlDestroyQueryDebugBuffer");
  if ( !RtlDestroyQueryDebugBuffer )
    return ReportMsg(L"Ntdll!RtlDestroyQueryDebugBuffer");
  v22 = GetModuleHandleW(L"ntdll.dll");
  RtlTimeToTimeFields = GetProcAddress(v22, "RtlTimeToTimeFields");
  if ( !RtlTimeToTimeFields )
    return ReportMsg(L"Ntdll!RtlTimeToTimeFields");
  v23 = LoadLibraryW(L"aclui.dll");
  *CreateSecurityPage = GetProcAddress(v23, "CreateSecurityPage");
  if ( *CreateSecurityPage )
    goto LABEL_70;
  v24 = LoadLibraryW(L"acledit.dll");
  SedDiscretionaryAclEditor = GetProcAddress(v24, "SedDiscretionaryAclEditor");
  if ( !SedDiscretionaryAclEditor )
    return ReportMsg(L"Acledit!SedDiscretionaryAclEditor");
  v25 = GetModuleHandleW(L"acledit.dll");
  SedSystemAclEditor = GetProcAddress(v25, "SedSystemAclEditor");
  if ( !SedSystemAclEditor )
    return ReportMsg(L"Acledit!SedSystemAclEditor");
  v26 = GetModuleHandleW(L"acledit.dll");
  SedTakeOwnership = GetProcAddress(v26, "SedTakeOwnership");
  if ( !SedTakeOwnership )
    return ReportMsg(L"Acledit!SedTakeOwnership");
LABEL_70:
  v27 = LoadLibraryW(L"shcore.dll");
  GetProcessDpiAwareness = GetProcAddress(v27, "GetProcessDpiAwareness");
  v28 = LoadLibraryW(L"iphlpapi.dll");
  *GetTcpTable = GetProcAddress(v28, "GetTcpTable");
  v29 = LoadLibraryW(L"iphlpapi.dll");
  *GetUdpTable = GetProcAddress(v29, "GetUdpTable");
  v30 = LoadLibraryW(L"iphlpapi.dll");
  AllocateAndGetTcpExTableFromStack = GetProcAddress(v30, "AllocateAndGetTcpExTableFromStack");
  v31 = LoadLibraryW(L"iphlpapi.dll");
  AllocateAndGetUdpExTableFromStack = GetProcAddress(v31, "AllocateAndGetUdpExTableFromStack");
  v32 = LoadLibraryW(L"iphlpapi.dll");
  *GetExtendedTcpTable = GetProcAddress(v32, "GetExtendedTcpTable");
  v33 = LoadLibraryW(L"iphlpapi.dll");
  *GetExtendedUdpTable = GetProcAddress(v33, "GetExtendedUdpTable");
  v34 = LoadLibraryW(L"iphlpapi.dll");
  AllocateAndGetTcpExTable2FromStack = GetProcAddress(v34, "AllocateAndGetTcpExTable2FromStack");
  v35 = LoadLibraryW(L"iphlpapi.dll");
  AllocateAndGetUdpExTable2FromStack = GetProcAddress(v35, "AllocateAndGetUdpExTable2FromStack");
  v36 = LoadLibraryW(L"user32.dll");
  *GetGuiResources = GetProcAddress(v36, "GetGuiResources");
  v37 = LoadLibraryW(L"psapi.dll");
  *QueryWorkingSet = GetProcAddress(v37, "QueryWorkingSet");
  v38 = LoadLibraryW(L"psapi.dll");
  *GetMappedFileNameW = GetProcAddress(v38, "GetMappedFileNameW");
  v39 = LoadLibraryW(L"psapi.dll");
  *EnumProcessModulesEx = GetProcAddress(v39, "EnumProcessModulesEx");
  v40 = LoadLibraryW(L"kernel32.dll");
  GlobalMemoryStatusEx = GetProcAddress(v40, "GlobalMemoryStatusEx");
  v41 = LoadLibraryW(L"user32.dll");
  IsHungAppWindow = GetProcAddress(v41, "IsHungAppWindow");
  v42 = LoadLibraryW(L"user32.dll");
  HungWindowFromGhostWindow = GetProcAddress(v42, "HungWindowFromGhostWindow");
  v43 = LoadLibraryW(L"kernel32.dll");
  *GetLogicalProcessorInformation = GetProcAddress(v43, "GetLogicalProcessorInformation");
  v44 = LoadLibraryW(L"kernel32.dll");
  GetLogicalProcessorInformationEx = GetProcAddress(v44, "GetLogicalProcessorInformationEx");
  v45 = LoadLibraryW(L"kernel32.dll");
  SetThreadGroupAffinity = GetProcAddress(v45, "SetThreadGroupAffinity");
  v46 = LoadLibraryW(L"wtsapi32.dll");
  WTSEnumerateSessionsW = GetProcAddress(v46, "WTSEnumerateSessionsW");
  v47 = LoadLibraryW(L"wtsapi32.dll");
  WTSDisconnectSession = GetProcAddress(v47, "WTSDisconnectSession");
  v48 = LoadLibraryW(L"winsta.dll");
  WinStationConnectW = GetProcAddress(v48, "WinStationConnectW");
  v49 = LoadLibraryW(L"winsta.dll");
  WinStationShadow = GetProcAddress(v49, "WinStationShadow");
  v50 = LoadLibraryW(L"wtsapi32.dll");
  WTSLogoffSessio = GetProcAddress(v50, "WTSLogoffSession");
  v51 = LoadLibraryW(L"wtsapi32.dll");
  WTSSendMessageW = GetProcAddress(v51, "WTSSendMessageW");
  v52 = LoadLibraryW(L"wtsapi32.dll");
  WTSFreeMemory = GetProcAddress(v52, "WTSFreeMemory");
  v53 = LoadLibraryW(L"wtsapi32.dll");
  WTSQuerySessionInformationW = GetProcAddress(v53, "WTSQuerySessionInformationW");
  v54 = LoadLibraryW(L"kernel32.dll");
  *WTSGetActiveConsoleSessionId = GetProcAddress(v54, "WTSGetActiveConsoleSessionId");
  v55 = LoadLibraryW(L"user32.dll");
  *SetMenuInfo = GetProcAddress(v55, "SetMenuInfo");
  v56 = LoadLibraryW(L"user32.dll");
  *GetMenuInfo = GetProcAddress(v56, "GetMenuInfo");
  hModule_1 = LoadLibraryW(gConfig.strDbgHelpModuleName);
  hModule = hModule_1;
  if ( !hModule_1 )
  {
    if ( RegOpenKeyW(HKEY_CURRENT_USER, L"Software\\Microsoft\\DebuggingTools", &hKey) )
      goto __directLoad;
    cbLength = 520;
    RegQueryValueExW(hKey, L"Windbg", 0, 0, gConfig.strDbgHelpModuleName, &cbLength);
    wcscat_s(gConfig.strDbgHelpModuleName, MAX_PATH, L"DbgHelp.dll");
    hModule_1 = LoadLibraryW(gConfig.strDbgHelpModuleName);
    hModule = hModule_1;
    if ( !hModule_1 )
    {
      wcscpy_s(gConfig.strDbgHelpModuleName, MAX_PATH, L"C:\\Debuggers\\dbghelp.dll");
      hModule_1 = LoadLibraryW(gConfig.strDbgHelpModuleName);
      hModule = hModule_1;
      if ( !hModule_1 )
      {
        ExpandEnvironmentStringsW(
          L"%ProgramFiles%\\Debugging Tools for Windows (x86)\\dbghelp.dll",
          gConfig.strDbgHelpModuleName,
          MAX_PATH);
        hModule_1 = LoadLibraryW(gConfig.strDbgHelpModuleName);
        hModule = hModule_1;
        if ( !hModule_1 )
        {
          GetCurrentDirectoryW(MAX_PATH, gConfig.strDbgHelpModuleName);
          wcscat_s(gConfig.strDbgHelpModuleName, MAX_PATH, L"\\dbghelp.dll");
          hModule_1 = LoadLibraryW(gConfig.strDbgHelpModuleName);
          hModule = hModule_1;
          if ( !hModule_1 )
          {
__directLoad:
            hModule_1 = LoadLibraryW(L"dbghelp.dll");
            hModule = hModule_1;
            if ( !hModule_1 )
            {
              hModule_1 = LoadLibraryW(L"imagehlp.dll");
              hModule = hModule_1;
            }
          }
        }
      }
    }
  }
  GetModuleFileNameW(hModule_1, gConfig.strDbgHelpModuleName, MAX_PATH);
  LoadDbgHelp(gConfig.strDbgHelpModuleName);
  if ( !*ImageNtHeader )
  {
    v58 = LoadLibraryW(L"imagehlp.dll");
    *ImageNtHeader = GetProcAddress(v58, "ImageNtHeader");
  }
  *FindExecutableImageExW = GetProcAddress(hModule, "FindExecutableImageExW");
  if ( *FindExecutableImageExW )
  {
    *FindExecutableImageExW_0 = FindExecutableImageExW_1;
  }
  else
  {
    v59 = LoadLibraryW(L"imagehlp.dll");
    FindExecutableImage = GetProcAddress(v59, "FindExecutableImage");
    v61 = 0;
    ::FindExecutableImage = FindExecutableImage;
    if ( FindExecutableImage )
      v61 = sub_FDBC50;
    *FindExecutableImageExW_0 = v61;
  }
  v62 = GetModuleHandleW(L"ntdll.dll");
  NtSuspendProcess = GetProcAddress(v62, "NtSuspendProcess");
  v63 = GetModuleHandleW(L"ntdll.dll");
  NtResumeProcess = GetProcAddress(v63, "NtResumeProcess");
  v64 = GetModuleHandleW(L"kernel32.dll");
  QueryProcessCycleTime = GetProcAddress(v64, "QueryProcessCycleTime");
  v65 = GetModuleHandleW(L"kernel32.dll");
  QueryIdleProcessorCycleTime = GetProcAddress(v65, "QueryIdleProcessorCycleTime");
  v66 = GetModuleHandleW(L"kernel32.dll");
  QueryThreadCycleTime = GetProcAddress(v66, "QueryThreadCycleTime");
  v67 = GetModuleHandleW(L"Shell32.dll");
  SHGetStockIconInfo = GetProcAddress(v67, "SHGetStockIconInfo");
  v68 = GetModuleHandleW(L"kernel32.dll");
  *CreateJobObjectW = GetProcAddress(v68, "CreateJobObjectW");
  v69 = GetModuleHandleW(L"user32.dll");
  ChangeWindowMessageFilter = GetProcAddress(v69, "ChangeWindowMessageFilter");
  v70 = LoadLibraryW(L"advapi32.dll");
  I_QueryTagInformation = GetProcAddress(v70, "I_QueryTagInformation");
  v71 = LoadLibraryW(L"wow64cpu");
  CpuGetContext = GetProcAddress(v71, "CpuGetContext");
  v72 = LoadLibraryW(L"kernel32.dll");
  GetProcessorSystemCycleTime = GetProcAddress(v72, "GetProcessorSystemCycleTime");
  v73 = LoadLibraryW(L"kernel32.dll");
  GetThreadIdealProcessorEx = GetProcAddress(v73, "GetThreadIdealProcessorEx");
  v74 = LoadLibraryW(L"user32.dll");
  IsImmersiveProcess = GetProcAddress(v74, "IsImmersiveProcess");
  v75 = LoadLibraryW(L"kernel32.dll");
  GetPackageFullName = GetProcAddress(v75, "GetPackageFullName");
  return 1;
}
// 1043420: using guessed type wchar_t aNtdllNtquerysy[31];
// 1043480: using guessed type wchar_t aNtdllNtquerysy_0[32];
// 10434D8: using guessed type wchar_t aNtdllNtquerydi[29];
// 1043530: using guessed type wchar_t aNtdllNtopensym[31];
// 1043588: using guessed type wchar_t aNtdllNtopendir[28];
// 10435D0: using guessed type wchar_t aNtdllNtqueryob[20];
// 1043618: using guessed type wchar_t aNtdllNtqueryin[32];
// 1043670: using guessed type wchar_t aNtdllNtsetinfo[30];
// 10436C0: using guessed type wchar_t aNtdllNtqueryse[23];
// 1043700: using guessed type wchar_t aNtdllNtqueryse_0[21];
// 104373C: using guessed type wchar_t aNtdllNtqueryev[19];
// 1043774: using guessed type wchar_t aNtdllNtquerymu[20];
// 10437AC: using guessed type wchar_t aNtdllNtresumet[21];
// 10437E8: using guessed type wchar_t aNtdllNtsuspend[22];
// 1043824: using guessed type wchar_t aNtdllNtopenthr[19];
// 1043868: using guessed type wchar_t aNtdllNtqueryin_0[31];
// 10438C0: using guessed type wchar_t aNtdllNtqueryvi[27];
// 1043918: using guessed type wchar_t aNtdllRtlcreate[32];
// 1043978: using guessed type wchar_t aNtdllRtlqueryp[38];
// 10439E0: using guessed type wchar_t aNtdllRtldestro[33];
// 1043A38: using guessed type wchar_t aNtdllRtltimeto[26];
// 1043AC8: using guessed type wchar_t aAcleditSeddisc[34];
// 1043B20: using guessed type wchar_t aAcleditSedsyst[27];
// 1043B6C: using guessed type wchar_t aAcleditSedtake[25];
// 106B1C8: using guessed type int (__stdcall *NtSetInformationProcess)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 106F214: using guessed type int NtOpenDirectoryObject;
// 106F220: using guessed type int RtlTimeToTimeFields;
// 106F224: using guessed type int NtQueryDirectoryObject;
// 106F228: using guessed type int (__stdcall *NtSetInformationProcess_0)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 106F230: using guessed type int (__stdcall *NtQueryEvent)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 106F234: using guessed type int (__stdcall *NtQueryMutant)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 106F258: using guessed type int (__stdcall *GetThreadIdealProcessorEx)(_DWORD, _DWORD);
// 106F260: using guessed type int (__stdcall *RtlQueryProcessDebugInformation)(_DWORD, _DWORD, _DWORD);
// 106F264: using guessed type int (__stdcall *RtlDestroyQueryDebugBuffer)(_DWORD);
// 106F2E8: using guessed type int (__stdcall *GlobalMemoryStatusEx)(_DWORD);
// 106F2F4: using guessed type int GetProcessorSystemCycleTime;
// 106F328: using guessed type int (__stdcall *GetLogicalProcessorInformationEx)(_DWORD, _DWORD, _DWORD);
// 106F32C: using guessed type int SetThreadGroupAffinity;
// 106F334: using guessed type int (__stdcall *WTSDisconnectSession)(_DWORD, _DWORD, _DWORD);
// 106F338: using guessed type int (__stdcall *WinStationConnectW)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 106F33C: using guessed type int (__stdcall *WinStationShadow)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 106F34C: using guessed type int (__stdcall *WTSLogoffSessio)(_DWORD, _DWORD, _DWORD);
// 106F350: using guessed type int (__stdcall *WTSSendMessageW)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 106F360: using guessed type int (__stdcall *ChangeWindowMessageFilter)(_DWORD, _DWORD);
// 106F364: using guessed type int CpuGetContext;
// 106F36C: using guessed type int (__stdcall *GetProcessDpiAwareness)(_DWORD, _DWORD);
// 107BA4C: using guessed type int (__stdcall *IsImmersiveProcess)(_DWORD);
// 107BA50: using guessed type int (__stdcall *SHGetStockIconInfo)(_DWORD, _DWORD, _DWORD);
