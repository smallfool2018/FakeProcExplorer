//----- (00C48860) --------------------------------------------------------
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
            *(_DWORD *)&OpenFileName.nFileOffset = 0;
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
              dword_CCE0DC = 1;
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
        v5 = v4 != (HANDLE)-1 && !(FindFileData.dwFileAttributes & 0x10);
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
// CB1578: using guessed type wchar_t aSpecifyDbghelp[23];
// CB15A8: using guessed type wchar_t aDll_2[6];
// CB15B4: using guessed type wchar_t aDbghelpDllDbgh[26];
// CCE0DC: using guessed type int dword_CCE0DC;
// CDA8F4: using guessed type int (__stdcall *gpfnSHAutoComplete)(struct HWND__ *, unsigned int);

//----- (00C48B70) --------------------------------------------------------
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
    pItemList_1 = (ITEMIDLIST *)pItemList;
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
// CB14DC: using guessed type wchar_t aBrowseForSymbo[29];

//----- (00C48C50) --------------------------------------------------------
BOOL BackendSysInfoPropSheetThreadProc()
{
  HICON v0; // edi
  BOOL result; // eax
  struct tagMSG msg; // [esp+8h] [ebp-20h]
  HACCEL hAccel; // [esp+24h] [ebp-4h]

  ghWndSysinfoPropSheet = CreateDialogParamW(ghInstance, L"SYSINFOPROPSHEET", 0, SysinfoPropSheet, 0);
  v0 = LoadIconW(ghInstance, (LPCWSTR)101);
  SendMessageW(ghWndSysinfoPropSheet, WM_SETICON, 0, (LPARAM)v0);
  SendMessageW(ghWndSysinfoPropSheet, WM_SETICON, 1u, (LPARAM)v0);
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

//----- (00C48D50) --------------------------------------------------------
const wchar_t *__cdecl sub_C48D50(int a1)
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
// CB0E34: using guessed type wchar_t a16[3];
// CB0E3C: using guessed type wchar_t a256[4];
// CB0E44: using guessed type wchar_t a65536[6];
// CB0E50: using guessed type wchar_t a224[5];
// CB0E5C: using guessed type wchar_t a215[5];
// CB0E68: using guessed type wchar_t a232[5];
// CB0E74: using guessed type wchar_t asc_CB0E74[4];

//----- (00C48DE0) --------------------------------------------------------
BOOL __stdcall DlgTsInfo(HWND hDlg, UINT a2, WPARAM a3, LPARAM a4)
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
    CMainWnd::DrawItem((LPDRAWITEMSTRUCT)a4);
    return 0;
  }
  if ( a2 != 272 )
  {
    if ( a2 == 273 && (unsigned int)(unsigned __int16)a3 - 1 <= 1 )
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
  WTSQuerySessionInformationW(0, SessionId, WTSClientProtocolType, (LPWSTR *)&v15, &pBytesReturned);
  if ( WTSQuerySessionInformationW(0, SessionId, WTSUserName, (LPWSTR *)&SessionInfo, &pBytesReturned) )
  {
    if ( WTSQuerySessionInformationW(0, SessionId, WTSDomainName, (LPWSTR *)ArgList, &pBytesReturned) )
    {
      swprintf(&String, L"%s\\%s", *(_DWORD *)ArgList, SessionInfo);
      SetDlgItemTextW(hDlg, 106, &String);
      WTSFreeMemory(*(PWTS_SESSION_INFOW *)ArgList);
    }
    WTSFreeMemory(SessionInfo);
  }
  if ( WTSQuerySessionInformationW(0, SessionId, WTSConnectState, (LPWSTR *)&v14, &pBytesReturned) )
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
      if ( WTSQuerySessionInformationW(0, SessionId, WTSClientName, (LPWSTR *)&lpString, &pBytesReturned) )
      {
        SetDlgItemTextW(hDlg, 110, lpString);
        WTSFreeMemory((PWTS_SESSION_INFOW)lpString);
      }
      if ( WTSQuerySessionInformationW(0, SessionId, WTSClientAddress, (LPWSTR *)&v13, &pBytesReturned)
        && v13->pWinStationName )
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
      if ( WTSQuerySessionInformationW(0, SessionId, WTSClientDisplay, (LPWSTR *)&v11, &pBytesReturned) )
      {
        v7 = sub_C48D50(v11->State);
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
// CCE130: using guessed type wchar_t aActive[7];

//----- (00C490F0) --------------------------------------------------------
CGraphData *HandleTaskbarCreated()
{
  signed int v0; // esi
  CGraphData *result; // eax
  int v2; // esi

  v0 = 1;
  do
    result = (CGraphData *)TrayIcon_Delete(ghMainWnd, v0++);
  while ( v0 < 5 );
  v2 = 1;
  if ( gConfig.bShowPhysTray )
  {
    dword_CDA3F0 = 1;
    result = (CGraphData *)TrayIcon_Add(ghMainWnd, 1u, gpGraphInfoOfPhysicalMemory, (LPCWSTR)&gszNullString);
    v2 = 2;
  }
  else
  {
    dword_CDA3F0 = 0;
  }
  if ( gConfig.bShowIoTray )
  {
    dword_CDA3C8 = v2;
    result = (CGraphData *)TrayIcon_Add(ghMainWnd, v2++, gIOGraphInfo.pGraphData, (LPCWSTR)&gszNullString);
  }
  else
  {
    dword_CDA3C8 = 0;
  }
  if ( gConfig.bShowDiskTray )
  {
    dword_CDA3F4 = v2;
    result = (CGraphData *)TrayIcon_Add(ghMainWnd, v2++, gDiskGraphInfo.pGraphData, (LPCWSTR)&gszNullString);
  }
  else
  {
    dword_CDA3F4 = 0;
  }
  if ( gConfig.bShowGpuHistory && (result = gpGraphInfoOfGPU) != 0 )
  {
    dword_CDA3C0 = v2;
    result = (CGraphData *)TrayIcon_Add(ghMainWnd, v2++, gpGraphInfoOfGPU, (LPCWSTR)&gszNullString);
  }
  else
  {
    dword_CDA3C0 = 0;
  }
  if ( gConfig.bShowNetTray )
  {
    dword_CDA600 = v2;
    result = (CGraphData *)TrayIcon_Add(ghMainWnd, v2++, gNetworkGraphInfo.pGraphData, (LPCWSTR)&gszNullString);
  }
  else
  {
    dword_CDA600 = 0;
  }
  if ( gConfig.bShowCommitTray )
  {
    dword_CDA3C4 = v2;
    result = (CGraphData *)TrayIcon_Add(ghMainWnd, v2++, gpGraphInfoOfMemory, (LPCWSTR)&gszNullString);
  }
  else
  {
    dword_CDA3C4 = 0;
  }
  if ( gConfig.bTrayCPUHistory )
  {
    dword_CDA3BC = v2;
    result = (CGraphData *)TrayIcon_Add(ghMainWnd, v2, gpGraphInfoOfCPU, (LPCWSTR)&gszNullString);
  }
  else
  {
    dword_CDA3BC = 0;
  }
  return result;
}
// CDA3BC: using guessed type int dword_CDA3BC;

//----- (00C492A0) --------------------------------------------------------
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
        DialogBoxParamW(ghInstance, L"SYMBOLDBGHELPGWARNING", 0, (DLGPROC)DlgAbout, 0);
      else
        DialogBoxParamW(ghInstance, L"SYMBOLCONFIGWARNING", 0, (DLGPROC)DlgAbout, 0);
    }
    free(pVersionInfo);
  }
  if ( !LOBYTE(gConfig.bSymbolWarningShown) && (!SymInitialize || !gConfig.strNtSymbolPath[0]) )
  {
    DialogBoxParamW(ghInstance, L"SYMBOLCONFIGWARNING", 0, (DLGPROC)DlgAbout, 0);
    LOBYTE(gConfig.bSymbolWarningShown) = 1;
    UpdateWindowPlacement(ghMainWnd, 1);
  }
}

//----- (00C49380) --------------------------------------------------------
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
    SetWindowPos(hWnd, (HWND)-(gConfig.bAlwaysOntop != 0), 0, 0, 0, 0, SWP_NOMOVE|SWP_NOSIZE);
    if ( ghWndHungWindow )
    {
      DrawHungWindow(ghWndHungWindow);
      if ( !HungWindowFromGhostWindow || (v2 = (HWND)HungWindowFromGhostWindow(ghWndHungWindow)) == 0 )
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
          SendMessageW(ghWndTreeListView, LVM_GETITEMW, 0, (LPARAM)&Item);
          dwProcessId_1 = dwProcessId;
          if ( Item.lParam->dwProcessId == dwProcessId )
            break;
          if ( ++nIndex >= nCount )
            goto __BREAK;
        }
        Item.mask = LVIF_STATE;
        Item.stateMask = LVIS_SELECTED;
        Item.state = LVIS_SELECTED;
        SendMessageW(ghWndTreeListView, LVM_SETITEMW, 0, (LPARAM)&Item);
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
    SetWindowPos(hWnd, (HWND)HWND_BOTTOM, 0, 0, 0, 0, SWP_NOMOVE|SWP_NOSIZE);
    SetWindowPos(hWnd, (HWND)HWND_BOTTOM, 0, 0, 0, 0, SWP_NOMOVE|SWP_NOSIZE);
    ghFindCursor = SetCursor(ghFindCursor);
    SetCapture(hWnd);
    gbWindowFinding = 1;
    result = 0;
    ghWndHungWindow = 0;
  }
  return result;
}
// CDA38B: using guessed type char gbWindowFinding;

//----- (00C495D0) --------------------------------------------------------
LRESULT __stdcall CMainWnd::MainWndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
  if ( Msg == gShellIconMsg )
    HandleTaskbarCreated();
  return HandleMsgHandler(&CMainWnd::gMsgHandler, hWnd, Msg, wParam, lParam);
}
// CDA884: using guessed type int gShellIconMsg;

//----- (00C49600) --------------------------------------------------------
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
  return MiniDumpWriteDump(Process, v6, (HANDLE)hFile, v5, 0, 0, 0);
}

//----- (00C49660) --------------------------------------------------------
int __cdecl PE_MakeFileVersion2(int a1, int a2, wchar_t *Dst)
{
  return swprintf_s(
           Dst,
           0x400u,
           L"%d.%d.%d.%d",
           (unsigned int)a2 >> 16,
           (unsigned __int16)a2,
           (unsigned int)a1 >> 16,
           (unsigned __int16)a1);
}

//----- (00C49690) --------------------------------------------------------
std__Tree_node *__thiscall sub_C49690(std__tree *this, int a2)
{
  std__Tree_node *result; // eax

  result = (std__Tree_node *)sub_C65470(this);
  *(_WORD *)&result->_Color = 0;
  if ( result != (std__Tree_node *)-16 )
  {
    result[1]._Left = *(std_Tree_node_for_tagKeyName **)a2;
    _mm_storeu_si128((__m128i *)&result[1]._Right, _mm_loadu_si128((const __m128i *)(a2 + 8)));
    _mm_storeu_si128((__m128i *)&result[2]._Right, _mm_loadu_si128((const __m128i *)(a2 + 24)));
    _mm_storeu_si128((__m128i *)&result[3]._Right, _mm_loadu_si128((const __m128i *)(a2 + 40)));
  }
  return result;
}

//----- (00C496D0) --------------------------------------------------------
int __thiscall std::_Tree<std::_Tmap_traits<unsigned long,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *>>,0>>::_Insert_at<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *> &,std::_Tree_node<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *>,void *> *>(CSystemProcessInfoMap *this, int a2, char a3, int a4, int a5, CSystemProcessInfoMapNode *_Node)
{
  CSystemProcessInfoMap *v6; // edi
  unsigned int v7; // eax
  CSystemProcessInfoMapNode *v8; // eax
  std_Tree_node_for_tagKeyName *v9; // ecx
  std_Tree_node_for_tagKeyName *v10; // esi
  std_Tree_node_for_tagKeyName *v11; // edx
  CSystemProcessInfoMapNode **v12; // edx
  CSystemProcessInfoMapNode **v13; // ecx
  CSystemProcessInfoMapNode *v14; // edx
  std_Tree_node_for_tagKeyName *v15; // esi
  std_Tree_node_for_tagKeyName *v16; // ecx
  _DWORD *v17; // ecx
  std_Tree_node_for_tagKeyName *v18; // edx
  std_Tree_node_for_tagKeyName *v19; // ecx
  CSystemProcessInfoMapNode *v20; // ecx
  CSystemProcessInfoMapNode **v21; // ecx
  int result; // eax

  v6 = this;
  v7 = this->_Size;
  if ( v7 >= 0xAAAAAA9 )
  {
    operator delete(_Node);
    std::_Xlength_error("map/set<T> too long");
  }
  this->_Size = v7 + 1;
  _Node->baseclass._Parent = (CSystemProcessInfoMapNode *)a4;
  if ( (std__Tree_node *)a4 == this->_Header )
  {
    this->_Header->_Parent = (std_Tree_node_for_tagKeyName *)_Node;
    this->_Header->_Left = (std_Tree_node_for_tagKeyName *)_Node;
    this->_Header->_Right = (std__Tree_node_For__bstr_t *)_Node;
  }
  else if ( a3 )
  {
    *(_DWORD *)a4 = _Node;
    if ( (std_Tree_node_for_tagKeyName *)a4 == this->_Header->_Left )
      this->_Header->_Left = (std_Tree_node_for_tagKeyName *)_Node;
  }
  else
  {
    *(_DWORD *)(a4 + 8) = _Node;
    if ( (std__Tree_node_For__bstr_t *)a4 == this->_Header->_Right )
      this->_Header->_Right = (std__Tree_node_For__bstr_t *)_Node;
  }
  v8 = _Node;
  while ( !v8->baseclass._Parent->baseclass._Color )
  {
    v9 = (std_Tree_node_for_tagKeyName *)v8->baseclass._Parent;
    v10 = v9->_Parent;
    v11 = v10->_Left;
    if ( v9 == v10->_Left )
    {
      v11 = v10->_Right;
      if ( v11->_Color )
      {
        if ( v8 == (CSystemProcessInfoMapNode *)v9->_Right )
        {
          v8 = v8->baseclass._Parent;
          v12 = (CSystemProcessInfoMapNode **)v9->_Right;
          v9->_Right = (std_Tree_node_for_tagKeyName *)*v12;
          if ( !(*v12)->baseclass._isnil )
            (*v12)->baseclass._Parent = (CSystemProcessInfoMapNode *)v9;
          v12[1] = (CSystemProcessInfoMapNode *)v9->_Parent;
          if ( v9 == v6->_Header->_Parent )
          {
            v6->_Header->_Parent = (std_Tree_node_for_tagKeyName *)v12;
          }
          else
          {
            v13 = (CSystemProcessInfoMapNode **)v9->_Parent;
            if ( v8 == *v13 )
              *v13 = (CSystemProcessInfoMapNode *)v12;
            else
              v13[2] = (CSystemProcessInfoMapNode *)v12;
          }
          *v12 = v8;
          v8->baseclass._Parent = (CSystemProcessInfoMapNode *)v12;
        }
        v8->baseclass._Parent->baseclass._Color = 1;
        v8->baseclass._Parent->baseclass._Parent->baseclass._Color = 0;
        v14 = v8->baseclass._Parent->baseclass._Parent;
        v15 = (std_Tree_node_for_tagKeyName *)v14->baseclass._Left;
        v14->baseclass._Left = v14->baseclass._Left->baseclass._Right;
        v16 = v15->_Right;
        if ( !v16->_IsNil )
          v16->_Parent = (std_Tree_node_for_tagKeyName *)v14;
        v15->_Parent = (std_Tree_node_for_tagKeyName *)v14->baseclass._Parent;
        if ( v14 == (CSystemProcessInfoMapNode *)v6->_Header->_Parent )
        {
          v6->_Header->_Parent = v15;
          v15->_Right = (std_Tree_node_for_tagKeyName *)v14;
        }
        else
        {
          v17 = &v14->baseclass._Parent->baseclass._Left;
          if ( v14 == (CSystemProcessInfoMapNode *)v17[2] )
            v17[2] = v15;
          else
            *v17 = v15;
          v15->_Right = (std_Tree_node_for_tagKeyName *)v14;
        }
LABEL_48:
        v14->baseclass._Parent = (CSystemProcessInfoMapNode *)v15;
        continue;
      }
    }
    else if ( v11->_Color )
    {
      if ( v8 == (CSystemProcessInfoMapNode *)v9->_Left )
      {
        v8 = v8->baseclass._Parent;
        v18 = v9->_Left;
        v9->_Left = v9->_Left->_Right;
        v19 = v18->_Right;
        if ( !v19->_IsNil )
          v19->_Parent = (std_Tree_node_for_tagKeyName *)v8;
        v18->_Parent = (std_Tree_node_for_tagKeyName *)v8->baseclass._Parent;
        if ( v8 == (CSystemProcessInfoMapNode *)v6->_Header->_Parent )
        {
          v6->_Header->_Parent = v18;
        }
        else
        {
          v20 = v8->baseclass._Parent;
          if ( v8 == v20->baseclass._Right )
            v20->baseclass._Right = (CSystemProcessInfoMapNode *)v18;
          else
            v20->baseclass._Left = (CSystemProcessInfoMapNode *)v18;
        }
        v18->_Right = (std_Tree_node_for_tagKeyName *)v8;
        v8->baseclass._Parent = (CSystemProcessInfoMapNode *)v18;
      }
      v8->baseclass._Parent->baseclass._Color = 1;
      v8->baseclass._Parent->baseclass._Parent->baseclass._Color = 0;
      v14 = v8->baseclass._Parent->baseclass._Parent;
      v15 = (std_Tree_node_for_tagKeyName *)v14->baseclass._Right;
      v14->baseclass._Right = (CSystemProcessInfoMapNode *)v15->_Left;
      if ( !v15->_Left->_IsNil )
        v15->_Left->_Parent = (std_Tree_node_for_tagKeyName *)v14;
      v15->_Parent = (std_Tree_node_for_tagKeyName *)v14->baseclass._Parent;
      if ( v14 == (CSystemProcessInfoMapNode *)v6->_Header->_Parent )
      {
        v6->_Header->_Parent = v15;
      }
      else
      {
        v21 = &v14->baseclass._Parent->baseclass._Left;
        if ( v14 == *v21 )
          *v21 = (CSystemProcessInfoMapNode *)v15;
        else
          v21[2] = (CSystemProcessInfoMapNode *)v15;
      }
      v15->_Left = (std_Tree_node_for_tagKeyName *)v14;
      goto LABEL_48;
    }
    v9->_Color = 1;
    v11->_Color = 1;
    v8->baseclass._Parent->baseclass._Parent->baseclass._Color = 0;
    v8 = v8->baseclass._Parent->baseclass._Parent;
  }
  v6->_Header->_Parent->_Color = 1;
  result = a2;
  *(_DWORD *)a2 = _Node;
  return result;
}

//----- (00C498E0) --------------------------------------------------------
_DWORD *__thiscall sub_C498E0(std__tree *this, _DWORD *a2, char a3, _DWORD *a4, int a5, int a6)
{
  std__tree *This; // edi
  std__Tree_node *v7; // eax
  std__Tree_node *v8; // ebx
  std__Tree_node *v9; // eax
  std__Tree_node *v10; // eax
  std_Tree_node_for_tagKeyName *v11; // ecx
  std_Tree_node_for_tagKeyName *v12; // esi
  std_Tree_node_for_tagKeyName *v13; // edx
  std_Tree_node_for_tagKeyName *v14; // edx
  std_Tree_node_for_tagKeyName *v15; // ecx
  std_Tree_node_for_tagKeyName *v16; // edx
  std__Tree_node *v17; // esi
  std__Tree_node *v18; // ecx
  std__Tree_node *v19; // ecx
  std__Tree_node *v20; // edx
  std__Tree_node *v21; // ecx
  std__Tree_node *v22; // ecx
  std__Tree_node *v23; // ecx
  _DWORD *result; // eax

  This = this;
  if ( this->_Mypair._Myval2._Mysize >= 0x38E38E2 )
    std::_Xlength_error("map/set<T> too long");
  v7 = sub_C49690(this, a5);
  ++This->_Mypair._Myval2._Mysize;
  v8 = v7;
  v7->_Parent = (std_Tree_node_for_tagKeyName *)a4;
  if ( a4 == (_DWORD *)This->_Mypair._Myval2._Myhead )
  {
    This->_Mypair._Myval2._Myhead->_Parent = (std_Tree_node_for_tagKeyName *)v7;
    This->_Mypair._Myval2._Myhead->_Left = (std_Tree_node_for_tagKeyName *)v7;
    v9 = This->_Mypair._Myval2._Myhead;
LABEL_8:
    v9->_Right = (std__Tree_node_For__bstr_t *)v8;
    goto LABEL_9;
  }
  if ( !a3 )
  {
    a4[2] = v7;
    v9 = This->_Mypair._Myval2._Myhead;
    if ( a4 != (_DWORD *)This->_Mypair._Myval2._Myhead->_Right )
      goto LABEL_9;
    goto LABEL_8;
  }
  *a4 = v7;
  if ( a4 == &This->_Mypair._Myval2._Myhead->_Left->_Left )
    This->_Mypair._Myval2._Myhead->_Left = (std_Tree_node_for_tagKeyName *)v7;
LABEL_9:
  v10 = v8;
  while ( !v10->_Parent->_Color )
  {
    v11 = v10->_Parent;
    v12 = v11->_Parent;
    v13 = v12->_Left;
    if ( v11 == v12->_Left )
    {
      v13 = v12->_Right;
      if ( v13->_Color )
      {
        if ( v10 == (std__Tree_node *)v11->_Right )
        {
          v10 = (std__Tree_node *)v10->_Parent;
          v14 = v11->_Right;
          v11->_Right = v14->_Left;
          if ( !v14->_Left->_IsNil )
            v14->_Left->_Parent = v11;
          v14->_Parent = v11->_Parent;
          if ( v11 == This->_Mypair._Myval2._Myhead->_Parent )
          {
            This->_Mypair._Myval2._Myhead->_Parent = v14;
          }
          else
          {
            v15 = v11->_Parent;
            if ( v10 == (std__Tree_node *)v15->_Left )
              v15->_Left = v14;
            else
              v15->_Right = v14;
          }
          v14->_Left = (std_Tree_node_for_tagKeyName *)v10;
          v10->_Parent = v14;
        }
        v10->_Parent->_Color = 1;
        v10->_Parent->_Parent->_Color = 0;
        v16 = v10->_Parent->_Parent;
        v17 = (std__Tree_node *)v16->_Left;
        v16->_Left = v16->_Left->_Right;
        v18 = (std__Tree_node *)v17->_Right;
        if ( !v18->_IsNil )
          v18->_Parent = v16;
        v17->_Parent = v16->_Parent;
        if ( v16 == This->_Mypair._Myval2._Myhead->_Parent )
        {
          This->_Mypair._Myval2._Myhead->_Parent = (std_Tree_node_for_tagKeyName *)v17;
          v17->_Right = (std__Tree_node_For__bstr_t *)v16;
        }
        else
        {
          v19 = (std__Tree_node *)v16->_Parent;
          if ( v16 == (std_Tree_node_for_tagKeyName *)v19->_Right )
            v19->_Right = (std__Tree_node_For__bstr_t *)v17;
          else
            v19->_Left = (std_Tree_node_for_tagKeyName *)v17;
          v17->_Right = (std__Tree_node_For__bstr_t *)v16;
        }
LABEL_48:
        v16->_Parent = (std_Tree_node_for_tagKeyName *)v17;
        continue;
      }
    }
    else if ( v13->_Color )
    {
      if ( v10 == (std__Tree_node *)v11->_Left )
      {
        v10 = (std__Tree_node *)v10->_Parent;
        v20 = (std__Tree_node *)v11->_Left;
        v11->_Left = v11->_Left->_Right;
        v21 = (std__Tree_node *)v20->_Right;
        if ( !v21->_IsNil )
          v21->_Parent = (std_Tree_node_for_tagKeyName *)v10;
        v20->_Parent = v10->_Parent;
        if ( v10 == (std__Tree_node *)This->_Mypair._Myval2._Myhead->_Parent )
        {
          This->_Mypair._Myval2._Myhead->_Parent = (std_Tree_node_for_tagKeyName *)v20;
        }
        else
        {
          v22 = (std__Tree_node *)v10->_Parent;
          if ( v10 == (std__Tree_node *)v22->_Right )
            v22->_Right = (std__Tree_node_For__bstr_t *)v20;
          else
            v22->_Left = (std_Tree_node_for_tagKeyName *)v20;
        }
        v20->_Right = (std__Tree_node_For__bstr_t *)v10;
        v10->_Parent = (std_Tree_node_for_tagKeyName *)v20;
      }
      v10->_Parent->_Color = 1;
      v10->_Parent->_Parent->_Color = 0;
      v16 = v10->_Parent->_Parent;
      v17 = (std__Tree_node *)v16->_Right;
      v16->_Right = v17->_Left;
      if ( !v17->_Left->_IsNil )
        v17->_Left->_Parent = v16;
      v17->_Parent = v16->_Parent;
      if ( v16 == This->_Mypair._Myval2._Myhead->_Parent )
      {
        This->_Mypair._Myval2._Myhead->_Parent = (std_Tree_node_for_tagKeyName *)v17;
      }
      else
      {
        v23 = (std__Tree_node *)v16->_Parent;
        if ( v16 == v23->_Left )
          v23->_Left = (std_Tree_node_for_tagKeyName *)v17;
        else
          v23->_Right = (std__Tree_node_For__bstr_t *)v17;
      }
      v17->_Left = v16;
      goto LABEL_48;
    }
    v11->_Color = 1;
    v13->_Color = 1;
    v10->_Parent->_Parent->_Color = 0;
    v10 = (std__Tree_node *)v10->_Parent->_Parent;
  }
  This->_Mypair._Myval2._Myhead->_Parent->_Color = 1;
  result = a2;
  *a2 = v8;
  return result;
}

//----- (00C49AF0) --------------------------------------------------------
int __thiscall std::_Tree<std::_Tmap_traits<unsigned long,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *>>,0>>::_Insert_hint<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *> &,std::_Tree_node<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *>,void *> *>(CSystemProcessInfoMap *this, int a2, int _Where, int _Val, CSystemProcessInfoMapNode *_Newnode)
{
  std__Tree_node *v5; // ecx
  bool v6; // dl
  _DWORD *v7; // ebx
  int v8; // edi
  std_Tree_node_for_tagKeyName *v9; // eax
  unsigned int v10; // ecx
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
  v7 = (_DWORD *)_Val;
  v8 = (int)v5;
  v20 = 0;
  v16 = v5;
  v9 = v5->_Parent;
  LOBYTE(v18) = 1;
  if ( !v9->_IsNil )
  {
    v10 = *(_DWORD *)_Val;
    do
    {
      v8 = (int)v9;
      if ( (_BYTE)_Where )
        v6 = v9->_Myval.first >= v10;
      else
        v6 = v10 < v9->_Myval.first;
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
    if ( (std_Tree_node_for_tagKeyName *)v8 == v5->_Left )
    {
      v12 = (int *)std::_Tree<std::_Tmap_traits<unsigned long,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *>>,0>>::_Insert_at<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *> &,std::_Tree_node<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *>,void *> *>(
                     v17,
                     (int)&_Where,
                     1,
                     v8,
                     _Val,
                     _Newnode);
LABEL_14:
      v13 = *v12;
      result = a2;
      *(_DWORD *)a2 = v13;
      *(_BYTE *)(a2 + 4) = 1;
      return result;
    }
    std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned long const,MAPITEM *>>>,std::_Iterator_base0>::operator--((std__tree *)&_Where);
    v11 = _Where;
  }
  if ( *(_DWORD *)(v11 + 16) < *v7 )
  {
    v12 = (int *)std::_Tree<std::_Tmap_traits<unsigned long,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *>>,0>>::_Insert_at<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *> &,std::_Tree_node<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *>,void *> *>(
                   v17,
                   (int)&_Where,
                   v18,
                   v8,
                   (int)v7,
                   _Newnode);
    goto LABEL_14;
  }
  operator delete(_Newnode);
  result = a2;
  *(_DWORD *)a2 = v11;
  *(_BYTE *)(a2 + 4) = 0;
  return result;
}
// C781AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);

//----- (00C49C10) --------------------------------------------------------
int __thiscall sub_C49C10(std__tree *this, int a2, _DWORD *a3, _DWORD *a4, int a5)
{
  std__tree *THIS; // ebx
  std__Tree_node *_Myhead; // ecx
  bool v7; // dl
  std__Tree_node **v8; // edi
  std__Tree_node *v9; // esi
  std__Tree_node *_Parent; // eax
  std__Tree_node *v11; // ecx
  std__Tree_node *v12; // eax
  int *v13; // eax
  int v14; // ecx
  int result; // eax
  int v16; // [esp+0h] [ebp-2Ch]
  std__tree *thIs; // [esp+10h] [ebp-1Ch]
  std__Tree_node *v18; // [esp+14h] [ebp-18h]
  int v19; // [esp+18h] [ebp-14h]
  int *v20; // [esp+1Ch] [ebp-10h]
  int v21; // [esp+28h] [ebp-4h]

  v20 = &v16;
  THIS = this;
  thIs = this;
  _Myhead = this->_Mypair._Myval2._Myhead;
  v7 = 1;
  v8 = (std__Tree_node **)a4;
  v9 = _Myhead;
  v21 = 0;
  v18 = _Myhead;
  _Parent = (std__Tree_node *)_Myhead->_Parent;
  LOBYTE(v19) = 1;
  if ( !_Parent->_IsNil )
  {
    v11 = (std__Tree_node *)*a4;
    do
    {
      v9 = _Parent;
      if ( (_BYTE)a3 )
        v7 = _Parent[1]._Left >= (std_Tree_node_for_tagKeyName *)v11;
      else
        v7 = (std_Tree_node_for_tagKeyName *)v11 < _Parent[1]._Left;
      LOBYTE(v19) = v7;
      if ( v7 )
        _Parent = (std__Tree_node *)_Parent->_Left;
      else
        _Parent = (std__Tree_node *)_Parent->_Right;
    }
    while ( !_Parent->_IsNil );
    _Myhead = v18;
    THIS = thIs;
  }
  v12 = v9;
  a3 = &v9->_Left;
  if ( v7 )
  {
    if ( v9 == (std__Tree_node *)_Myhead->_Left )
    {
      v13 = sub_C498E0(THIS, &a3, 1, v9, (int)a4, a5);
LABEL_14:
      v14 = *v13;
      result = a2;
      *(_DWORD *)a2 = v14;
      *(_BYTE *)(a2 + 4) = 1;
      return result;
    }
    std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned long const,MAPITEM *>>>,std::_Iterator_base0>::operator--((std__tree *)&a3);
    v12 = (std__Tree_node *)a3;
  }
  if ( v12[1]._Left < (std_Tree_node_for_tagKeyName *)*v8 )
  {
    v13 = sub_C498E0(THIS, &a4, v19, v9, (int)v8, a5);
    goto LABEL_14;
  }
  *(_DWORD *)a2 = v12;
  result = a2;
  *(_BYTE *)(a2 + 4) = 0;
  return result;
}
// C781AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);

//----- (00C49D20) --------------------------------------------------------
int MakeDriverName(wchar_t *pszText, wchar_t *lpszFormat, ...)
{
  va_list ArgList; // [esp+10h] [ebp+10h]

  va_start(ArgList, lpszFormat);
  return vswprintf_s(pszText, 10u, lpszFormat, ArgList);
}

//----- (00C49D40) --------------------------------------------------------
int wsprintfW(wchar_t *Dst, wchar_t *Format, ...)
{
  va_list ArgList; // [esp+10h] [ebp+10h]

  va_start(ArgList, Format);
  return vswprintf_s(Dst, 0x1000u, Format, ArgList);
}

//----- (00C49D60) --------------------------------------------------------
int sub_C49D60(wchar_t *Dst, wchar_t *Format, ...)
{
  va_list ArgList; // [esp+10h] [ebp+10h]

  va_start(ArgList, Format);
  return vswprintf_s(Dst, 0x105u, Format, ArgList);
}

//----- (00C49D80) --------------------------------------------------------
int wsprintf_s(wchar_t *Dst, wchar_t *Format, ...)
{
  va_list ArgList; // [esp+10h] [ebp+10h]

  va_start(ArgList, Format);
  return vswprintf_s(Dst, 0x20u, Format, ArgList);
}

//----- (00C49DA0) --------------------------------------------------------
int sub_C49DA0(wchar_t *Dst, wchar_t *Format, ...)
{
  va_list ArgList; // [esp+10h] [ebp+10h]

  va_start(ArgList, Format);
  return vswprintf_s(Dst, 0x32u, Format, ArgList);
}

//----- (00C49DC0) --------------------------------------------------------
int MakeDeviceName(wchar_t *Dst, wchar_t *Format, ...)
{
  va_list ArgList; // [esp+10h] [ebp+10h]

  va_start(ArgList, Format);
  return vswprintf_s(Dst, 0x40u, Format, ArgList);
}

//----- (00C49DE0) --------------------------------------------------------
int sub_C49DE0(wchar_t *Dst, wchar_t *Format, ...)
{
  va_list ArgList; // [esp+10h] [ebp+10h]

  va_start(ArgList, Format);
  return vswprintf_s(Dst, 0x41u, Format, ArgList);
}

//----- (00C49E00) --------------------------------------------------------
CString *__thiscall sub_C49E00(_DWORD *this, LPCWSTR lpWideCharStr)
{
  CString *v2; // esi
  IAtlStringMgr *v3; // ecx
  CHAR *v4; // eax

  v2 = (CString *)this;
  v3 = ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>::GetDefaultManager();
  if ( !v3 )
    ATL::AtlThrowImpl(E_FAIL);
  v2->pszData = (CHAR *)(((int (*)(void))v3->vtptr->GetNilData)() + 16);
  if ( !lpWideCharStr || (unsigned int)lpWideCharStr & 0xFFFF0000 )
  {
    ATL::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>::operator=(v2, lpWideCharStr);
  }
  else
  {
    v4 = ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>::FindStringResourceInstance(
           (unsigned __int16)lpWideCharStr,
           0);
    if ( v4 )
      sub_C4F660(v2, (HMODULE)v4, (unsigned __int16)lpWideCharStr);
  }
  return v2;
}

//----- (00C49EA0) --------------------------------------------------------
CString *__thiscall ATL::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>(CString *this, LPCSTR lpMultiByteStr)
{
  CString *v2; // esi
  IAtlStringMgr *v3; // ecx

  v2 = this;
  v3 = ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>::GetDefaultManager();
  if ( !v3 )
    ATL::AtlThrowImpl(0x80004005);
  v2->pszData = (CHAR *)(((int (*)(void))v3->vtptr->GetNilData)() + 16);
  ATL::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>::operator=(v2, lpMultiByteStr);
  return v2;
}

//----- (00C49F20) --------------------------------------------------------
void __thiscall sub_C49F20(CString *this)
{
  CString *v1; // eax
  CHAR *v2; // ebx
  CHAR *v3; // edi
  unsigned int v4; // esi
  int v5; // ecx
  CString *v6; // [esp+4h] [ebp-4h]

  v1 = this;
  v6 = this;
  v2 = this->pszData;
  if ( this->pszData )
  {
    v3 = this[1].pszData;
    v4 = 0;
    if ( v3 )
    {
      do
      {
        v5 = *(_DWORD *)&v2[4 * v4];
        if ( v5 )
          (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v5 + 8))(*(_DWORD *)&v2[4 * v4]);
        ++v4;
      }
      while ( v4 < (unsigned int)v3 );
      v1 = v6;
    }
    free(v1->pszData);
  }
}

//----- (00C49F70) --------------------------------------------------------
void __thiscall PerformanceInfoInMemory::~PerformanceInfoInMemory(PerformanceInfoInMemory *this)
{
  PerformanceInfoInMemory *v1; // esi

  v1 = this;
  operator delete(this->m_pBuffer);
  v1->m_pBuffer = 0;
}

//----- (00C49FB0) --------------------------------------------------------
void __thiscall sub_C49FB0(CSystemProcessInfoMap *this)
{
  CSystemProcessInfoMap *v1; // esi
  int *a2; // [esp+4h] [ebp-4h]

  v1 = this;
  sub_C65510((std__tree *)this, &a2, (std__Tree_node *)this->_Header->_Left, (int *)this->_Header);
  operator delete(v1->_Header);
}

//----- (00C49FE0) --------------------------------------------------------
CString *__thiscall ATL::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>::operator=(CString *this, LPCWSTR lpWideCharStr)
{
  CString *pThis; // edi
  int dwRet; // esi
  CString *result; // eax

  pThis = this;
  if ( lpWideCharStr && (dwRet = WideCharToMultiByte(CP_THREAD_ACP, 0, lpWideCharStr, -1, 0, 0, 0, 0) - 1, dwRet > 0) )
  {
    if ( ((*((_DWORD *)pThis->pszData - 2) - dwRet) | (1 - *((_DWORD *)pThis->pszData - 1))) < 0 )
      sub_C52330(pThis, dwRet);
    WideCharToMultiByte(CP_THREAD_ACP, 0, lpWideCharStr, -1, pThis->pszData, dwRet, 0, 0);
    if ( dwRet > *((_DWORD *)pThis->pszData - 2) )
      ATL::AtlThrowImpl(E_INVALIDARG);
    *((_DWORD *)pThis->pszData - 3) = dwRet;
    pThis->pszData[dwRet] = 0;
    result = pThis;
  }
  else
  {
    ATL::CSimpleStringT<wchar_t,0>::Empty(pThis);
    result = pThis;
  }
  return result;
}

//----- (00C4A070) --------------------------------------------------------
tagTREEVIEWLISTITEMPARAM *__cdecl sub_C4A070(HWND hWnd, char a2, int a3, int a4, int a5, int a6, int a7, u_long hostlong, int a9, int port, int a11, int a12, int a13, int a14)
{
  tagItem124_InTcpUdp *v14; // esi
  const __m128i *v15; // edi
  int v16; // esi
  __int32 *v17; // edx
  int *v18; // ecx
  unsigned int v19; // edi
  bool v20; // cf
  LRESULT v21; // eax
  int v22; // eax
  int *v23; // edi
  const wchar_t *v24; // eax
  tagTREEVIEWLISTITEMPARAM *result; // eax
  int v26; // eax
  int v27; // edi
  _BYTE *v28; // edi
  char v29; // dl
  char v30; // al
  signed int v31; // ecx
  tagItem124_InTcpUdp *v32; // edx
  int *v33; // ecx
  unsigned int v34; // edi
  unsigned int v35; // kr00_4
  HWND v36; // ebx
  void *pItemInTcpUdp; // [esp-890h] [ebp-13B0h]
  int ItemInTcpUdp[548]; // [esp+Ch] [ebp-B14h]
  LVITEMW ItemText; // [esp+89Ch] [ebp-284h]
  LVITEMW Item; // [esp+8D0h] [ebp-250h]
  const __m128i *v41; // [esp+904h] [ebp-21Ch]
  _BYTE *v42; // [esp+908h] [ebp-218h]
  int *v43; // [esp+90Ch] [ebp-214h]
  tagItem124_InTcpUdp *a5a; // [esp+910h] [ebp-210h]
  HWND v45; // [esp+914h] [ebp-20Ch]
  int v46; // [esp+918h] [ebp-208h]
  __int16 Dst[256]; // [esp+91Ch] [ebp-204h]

  v14 = (tagItem124_InTcpUdp *)a9;
  v46 = a4;
  v15 = (const __m128i *)a6;
  v43 = (int *)a12;
  v42 = (_BYTE *)a14;
  v45 = hWnd;
  v41 = (const __m128i *)a6;
  a5a = (tagItem124_InTcpUdp *)a9;
  Item.mask = 4;
  Item.iItem = 0;
  Item.iSubItem = 0;
  if ( !SendMessageW(hWnd, LVM_GETITEMW, 0, (LPARAM)&Item) )
  {
LABEL_15:
    memset(ItemInTcpUdp, 0, 0x890u);
    ItemInTcpUdp[1] = 5;
    LOBYTE(ItemInTcpUdp[9]) = 1;
    v22 = 2;
    ItemInTcpUdp[10] = a3;
    if ( a2 )
      v22 = 0;
    ItemInTcpUdp[4] = v22;
    ItemInTcpUdp[543] = v46;
    ItemInTcpUdp[11] = a5;
    if ( v15 )
      _mm_storeu_si128((__m128i *)&ItemInTcpUdp[12], _mm_loadu_si128(v15));
    ItemInTcpUdp[146] = a7;
    ItemInTcpUdp[277] = hostlong;
    if ( v14 )
      _mm_storeu_si128((__m128i *)&ItemInTcpUdp[278], _mm_loadu_si128((const __m128i *)v14));
    v23 = v43;
    ItemInTcpUdp[412] = port;
    if ( gdwVersion >= 1 && !a13 && v43 )
    {
      if ( *v43 )
      {
        v24 = (const wchar_t *)sub_C6EFB0(*v43);
        ItemInTcpUdp[546] = (int)_wcsdup(v24);
      }
    }
    ItemInTcpUdp[544] = (int)v23;
    ItemInTcpUdp[545] = a13;
    qmemcpy(&pItemInTcpUdp, ItemInTcpUdp, 2192u);
    return sub_C27DD0(v45, pItemInTcpUdp);
  }
  while ( 1 )
  {
    if ( (v16 = (int)Item.lParam, a3) && a3 != 1 || Item.lParam->field_2C == a5 )
    {
      if ( a3 == 2 || a3 == 3 )
      {
        v17 = (__int32 *)v15;
        v18 = &Item.lParam->field_30;
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
      if ( !LOBYTE(Item.lParam->nRefCount) && Item.lParam->dwStyle == a3 && *(_DWORD *)&Item.lParam->gap234[20] == a7 )
        break;
    }
LABEL_13:
    ++Item.iItem;
    v21 = SendMessageW(v45, LVM_GETITEMW, 0, (LPARAM)&Item);
    v15 = v41;
    if ( !v21 )
    {
      v14 = a5a;
      goto LABEL_15;
    }
  }
  if ( a3 == 1 || a3 == 3 )
  {
LABEL_31:
    v26 = v46;
    goto LABEL_32;
  }
  if ( a3 )
  {
    if ( a3 != 2 )
      goto LABEL_41;
    v32 = a5a;
    v33 = &Item.lParam->field_458;
    v34 = 12;
    while ( *v33 == v32->field_0 )
    {
      ++v33;
      v32 = (tagItem124_InTcpUdp *)((char *)v32 + 4);
      v20 = v34 < 4;
      v34 -= 4;
      if ( v20 )
        goto LABEL_41;
    }
    goto LABEL_31;
  }
  if ( Item.lParam->field_454 != hostlong )
    goto LABEL_31;
LABEL_41:
  v26 = v46;
  if ( *(_DWORD *)&Item.lParam[1].field_28E[23] != v46 )
  {
    v27 = port;
LABEL_43:
    *(_DWORD *)&Item.lParam[1].field_28E[23] = v26;
    *(_DWORD *)(v16 + 1108) = hostlong;
    *(_DWORD *)(v16 + 1648) = v27;
    if ( a3 )
    {
      ItemText.iSubItem = 2;
      ItemText.pszText = L"*:*";
      SendMessageW(v45, LVM_SETITEMTEXTW, Item.iItem, (LPARAM)&ItemText);
    }
    else
    {
      sub_C344B0(0, 1, 0, hostlong, a5a, (wchar_t *)Dst, 0x100u);
      v35 = wcslen((const unsigned __int16 *)Dst);
      sub_C34670(1, v27, gszProtocolNames[0], (wchar_t *)&Dst[v35], 256 - v35);
      v36 = v45;
      ItemText.pszText = (LPWSTR)Dst;
      ItemText.iSubItem = 2;
      SendMessageW(v45, LVM_SETITEMTEXTW, Item.iItem, (LPARAM)&ItemText);
      ItemText.iSubItem = 3;
      ItemText.pszText = gszNetStatus[v46];
      SendMessageW(v36, LVM_SETITEMTEXTW, Item.iItem, (LPARAM)&ItemText);
    }
    v28 = v42;
    *v42 = 1;
    goto LABEL_34;
  }
LABEL_32:
  v27 = port;
  if ( Item.lParam[1].field_B0 != port )
    goto LABEL_43;
  v28 = v42;
LABEL_34:
  v29 = *(_BYTE *)(v16 + 24);
  v30 = 0;
  if ( v29 )
  {
    v31 = *(_DWORD *)(v16 + 28);
    if ( v31 < (signed int)gConfig.dwHighlightDuration )
    {
      *(_DWORD *)(v16 + 16) = 2;
      result = 0;
      *(_DWORD *)(v16 + 20) = v31;
      *(_BYTE *)(v16 + 36) = 1;
      return result;
    }
    if ( v29 )
    {
      v30 = 1;
      *(_BYTE *)(v16 + 24) = 0;
    }
  }
  *(_DWORD *)(v16 + 16) = 0;
  if ( v30 )
    *v28 = 1;
  result = 0;
  *(_BYTE *)(v16 + 36) = 1;
  return result;
}
// CAE250: using guessed type wchar_t asc_CAE250[4];
// CCD238: using guessed type wchar_t *gszNetStatus[13];
// CD4E54: using guessed type int gdwVersion;
// C4A070: using guessed type wchar_t Dst[256];

//----- (00C4A4A0) --------------------------------------------------------
CHAR *__thiscall sub_C4A4A0(CString *this, __int16 a2)
{
  CString *v2; // edi
  int v3; // ebx
  int v4; // esi
  CHAR *result; // eax

  v2 = this;
  v3 = *((_DWORD *)this->pszData - 3);
  v4 = v3 + 1;
  if ( v3 + 1 < 0 )
    goto LABEL_9;
  if ( ((*((_DWORD *)this->pszData - 2) - v4) | (1 - *((_DWORD *)this->pszData - 1))) < 0 )
    ATL::CSimpleStringT<wchar_t,0>::PrepareWrite2(this, v3 + 1);
  *(_WORD *)&v2->pszData[2 * v3] = a2;
  if ( v4 > *((_DWORD *)v2->pszData - 2) )
LABEL_9:
    ATL::AtlThrowImpl(-2147024809);
  *((_DWORD *)v2->pszData - 3) = v4;
  result = v2->pszData;
  *(_WORD *)&v2->pszData[2 * v4] = 0;
  return result;
}

//----- (00C4A500) --------------------------------------------------------
double __cdecl PE_ComputeProcessThreadContextSwitchCount(SYSTEM_PROCESS_INFORMATION *pSystemProcessInfo)
{
  SYSTEM_THREAD_INFORMATION *pThreadInfo; // eax
  ULONG NumberOfThreads; // ecx
  unsigned int highpart; // edx
  PLONG pContextSwitches; // eax
  unsigned int nCount; // esi
  unsigned __int64 v6; // kr00_8

  if ( (unsigned __int8)GetVersion() <= 4u )
    pThreadInfo = (SYSTEM_THREAD_INFORMATION *)&pSystemProcessInfo->ReadOperationCount;
  else
    pThreadInfo = (SYSTEM_THREAD_INFORMATION *)&pSystemProcessInfo[1];
  NumberOfThreads = pSystemProcessInfo->NumberOfThreads;
  if ( NumberOfThreads )
  {
    highpart = 0;
    pContextSwitches = (PLONG)&pThreadInfo->ContextSwitches;
    nCount = 0;
    do
    {
      v6 = (unsigned int)*pContextSwitches + __PAIR__(highpart, nCount);
      highpart = v6 >> 32;
      nCount = v6;
      pContextSwitches += offsetof(SYSTEM_THREAD_INFORMATION, CreateTime);
      --NumberOfThreads;
    }
    while ( NumberOfThreads );
  }
}
// C4A545: CONTAINING_RECORD: no field 'PLONG' in struct 'SYSTEM_THREAD_INFORMATION' at 64

//----- (00C4A580) --------------------------------------------------------
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
  v9 = *((_DWORD *)CallbackContext + 2);
  if ( v9 )
  {
    v10 = v9 - 1;
    if ( v10 )
    {
      if ( v10 == 1 )
      {
        CallbackContext = (PVOID)1;
        v11 = (PDWORD)0x80000;
      }
      else
      {
        v11 = ChangeContextStatus;
      }
    }
    else
    {
      CallbackContext = (PVOID)8;
      v11 = (PDWORD)0x1000000;
    }
  }
  else
  {
    CallbackContext = (PVOID)4;
    v11 = (PDWORD)0x40000;
  }
  v12 = (void *)PE_DuplicateProcessHandle(*(_DWORD *)v8, *((HANDLE *)v8 + 1), (DWORD)v11);
  if ( v12 )
  {
    if ( SetUserObjectSecurity(v12, (PSECURITY_INFORMATION)&CallbackContext, NewSD) )
    {
      v14 = (unsigned int)CallbackContext | 3;
      v15 = *((_DWORD *)v8 + 2) == 2;
      CallbackContext = (PVOID)((unsigned int)CallbackContext | 3);
      if ( v15 )
        CallbackContext = (PVOID)(v14 | 4);
      **((_BYTE **)v8 + 5) = GetUserObjectSecurity(
                               v12,
                               (PSECURITY_INFORMATION)&CallbackContext,
                               *((PSECURITY_DESCRIPTOR *)v8 + 4),
                               0x2000u,
                               &nLengthNeeded);
    }
    else
    {
      MessageBoxW(0, L"Unable to modify the object's Security Information.", L"WinObj", 0x10u);
    }
    CloseHandle(v12);
    *(_BYTE *)ChangeContextStatus = 1;
    result = 0;
  }
  else
  {
    MessageBoxW(0, L"Unable to modify the object's Security Information.", L"WinObj", 0x10u);
    *(_BYTE *)ChangeContextStatus = 1;
    result = 0;
  }
  return result;
}

//----- (00C4A670) --------------------------------------------------------
HBRUSH __stdcall DlgDllInfo(HWND hWnd, UINT msg, WPARAM uID, DLLINFOLISTITEMPARAM *pListItem)
{
  tagDLLLISTITEMPARAM *pItemParam; // edi
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
  WCHAR *pszCompanyInfo; // ST10_4
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
  WCHAR *v36; // eax
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

  pItemParam = (tagDLLLISTITEMPARAM *)GetWindowLongW(hWnd, GWLP_USERDATA);
  switch ( msg )
  {
    case WM_INITDIALOG:
      v5 = (CResizer *)operator new(0x40u);
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
        *(_QWORD *)v8->gap0 = 0i64;
        *(double *)&v8->gap0[8] = db_one;
      }
      v9 = GetDlgItem(hWnd, IDC_DLG_DLLINFO_EDIT_AUTOSTART_LOCATION);
      if ( v9 )
      {
        v10 = CResizer::AddItem(pResizer_1, v9, 1);
        *(_QWORD *)v10->gap0 = 0i64;
        *(double *)&v10->gap0[8] = db_one;
      }
      SetWindowLongW(hWnd, GWLP_USERDATA, (LONG)pListItem);
      if ( wcsrchr((const wchar_t *)pListItem->m_strPath.pszData, '\\') )
        psz = (CHAR *)(wcsrchr((const wchar_t *)pListItem->m_strPath.pszData, '\\') + 1);
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
      SetDlgItemTextW(hWnd, IDC_DLG_DLLINFO_EDIT_PATH, (LPCWSTR)pListItem->m_strPath.pszData);
      v13 = L"n/a";
      if ( pListItem->m_strLocation )
        v13 = (const WCHAR *)pListItem->m_strLocation;
      SetDlgItemTextW(hWnd, IDC_DLG_DLLINFO_EDIT_AUTOSTART_LOCATION, v13);
      v14 = pListItem->m_strPath.pszData != 0;
      v15 = GetDlgItem(hWnd, IDC_DLG_DLLINFO_BUTTON_EXPLORE_PATH);
      EnableWindow(v15, v14);
      v16 = pListItem->m_strLocation != 0;
      v17 = GetDlgItem(hWnd, IDC_DLG_DLLINFO_BUTTON_EXPLORE_LOCATION);
      EnableWindow(v17, v16);
      v18 = LoadIconW(ghInstance, (LPCWSTR)154);
      v19 = GetParent(hWnd);
      SendMessageW(v19, WM_SETICON, 1u, (LPARAM)v18);
      v20 = LoadIconW(ghInstance, (LPCWSTR)154);
      hWndParent = GetParent(hWnd);
      SendMessageW(hWndParent, WM_SETICON, 0, (LPARAM)v20);
      if ( pListItem->m_strDescription )
        SetDlgItemTextW(hWnd, IDC_DLG_DLLINFO_EDIT_DESCRIPTION, (LPCWSTR)pListItem->m_strDescription);
      else
        SetDlgItemTextW(hWnd, IDC_DLG_DLLINFO_EDIT_DESCRIPTION, L"n/a");
      if ( pListItem->m_strCompanyInfo )
      {
        pszCompanyInfo = VerifyImage((tagTREEVIEWLISTITEMPARAM *)pListItem, gConfig.bVerifySignatures);
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
        if ( pListItem->field_160 || (v25 = (_WORD *)pListItem->m_strCompanyInfo) == 0 || *v25 == '[' )
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
      sub_C71A50(pListItem->m_ItemData1, Dest);
      SetDlgItemTextW(hWnd, IDC_DLG_DLLINFO_EDIT_VIRUSTOTAL, Dest);
      v28 = pListItem->m_strPath.pszData;
      if ( v28 && *(_WORD *)v28 != '[' )
      {
        v29 = (unsigned __int8)sub_C71C10((ListItemData1 *)pListItem->m_ItemData1);
        v30 = GetDlgItem(hWnd, IDC_DLG_DLLINFO_BUTTON_SUBMIT);
        EnableWindow(v30, v29);
      }
      v31 = L"n/a";
      if ( pListItem->m_szVersion[0] )
        v31 = (const WCHAR *)pListItem->m_szVersion;
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
      return (HBRUSH)1;
    case WM_COMMAND:
      if ( (unsigned __int16)uID > (signed int)IDC_DLG_DLLINFO_BUTTON_EXPLORE_PATH )
      {
        if ( (unsigned __int16)uID > (signed int)IDM_FILE_EXIT )
        {
          if ( (unsigned int)(unsigned __int16)uID - 40092 > 1 )
            return 0;
          v43 = uID;
        }
        else
        {
          if ( (unsigned __int16)uID != IDM_FILE_EXIT )
          {
            if ( (unsigned __int16)uID == IDC_DLG_DLLINFO_BUTTON_SUBMIT )
            {
              if ( !SubmitExeToVirusTotalDotCom() )
                return (HBRUSH)1;
              v37 = pItemParam->m_HashData;
              v38 = 0;
              if ( v37 )
              {
                v38 = 1;
                *(_DWORD *)(v37 + 4) = 6;
              }
              sub_C71C30(pItemParam, ~(unsigned __int8)((unsigned int)pItemParam->field_2C >> 1) & 1, v38 != 0);
              v39 = GetDlgItem(hWnd, IDC_DLG_DLLINFO_BUTTON_SUBMIT);
              EnableWindow(v39, 0);
              sub_C71A50(pItemParam->m_HashData, v48);
              v40 = (unsigned __int8)sub_C71C10((ListItemData1 *)pItemParam->m_HashData);
              v41 = GetDlgItem(hWnd, IDC_DLG_DLLINFO_BUTTON_SUBMIT);
              EnableWindow(v41, v40);
              SetDlgItemTextW(hWnd, IDC_DLG_DLLINFO_EDIT_VIRUSTOTAL, v48);
              PostMessageW(ghMainWnd, 0x7F9u, 0, pItemParam->m_HashData);
              return (HBRUSH)1;
            }
            return 0;
          }
          v43 = 40014;
        }
        v42 = GetParent(hWnd);
        PostMessageW(v42, WM_COMMAND, v43, 0);
        return 0;
      }
      if ( (unsigned __int16)uID == IDC_DLG_DLLINFO_BUTTON_EXPLORE_PATH )
      {
        PE_LaunchExe(hWnd, (CCmdString *)pItemParam->m_strPath.pszData);
        return (HBRUSH)1;
      }
      if ( (signed int)(unsigned __int16)uID > 1005 )
      {
        if ( (unsigned __int16)uID == IDC_DLG_DLLINFO_BUTTON_EXPLORE_LOCATION )
        {
          PE_LaunchExe(hWnd, (CCmdString *)pItemParam->m_strLocation);
          return (HBRUSH)1;
        }
        return 0;
      }
      if ( (unsigned __int16)uID != 1005 )
      {
        if ( (unsigned __int16)uID != 1 )
        {
          if ( (unsigned __int16)uID == 2 )
            return (HBRUSH)1;
          return 0;
        }
        return (HBRUSH)1;
      }
      v36 = VerifyImage((tagTREEVIEWLISTITEMPARAM *)pItemParam, 1);
      SetDlgItemTextW(hWnd, 3, v36);
      v44 = 0;
      v35 = GetDlgItem(hWnd, IDC_DLG_DLLINFO_BUTTON_VERIFY);
LABEL_44:
      EnableWindow(v35, v44);
      return (HBRUSH)1;
    case WM_TIMER:
      GetDlgItemTextW(hWnd, IDC_DLG_DLLINFO_EDIT_VIRUSTOTAL, String, 256);
      sub_C71A50(pItemParam->m_HashData, Dest);
      v34 = wcscmp(String, Dest);
      if ( v34 )
        v34 = -(v34 < 0) | 1;
      if ( !v34 )
        return (HBRUSH)1;
      SetDlgItemTextW(hWnd, IDC_DLG_DLLINFO_EDIT_VIRUSTOTAL, Dest);
      v44 = (unsigned __int8)sub_C71C10((ListItemData1 *)pItemParam->m_HashData);
      v35 = GetDlgItem(hWnd, IDC_DLG_DLLINFO_BUTTON_SUBMIT);
      goto LABEL_44;
    case WM_CTLCOLORSTATIC:
      if ( pListItem != (DLLINFOLISTITEMPARAM *)GetDlgItem(hWnd, IDC_DLG_DLLINFO_EDIT_VIRUSTOTAL)
        || !sub_C71820((ListItemData1 *)pItemParam->m_HashData) )
      {
        return 0;
      }
      if ( sub_C72910((ListItemData1 *)pItemParam->m_HashData) )
        SetTextColor((HDC)uID, 0xFFu);
      else
        SetTextColor((HDC)uID, 0xFF0000u);
      SelectObject((HDC)uID, ghDefaultUnderlineFontHandle);
      return GetSysColorBrush(COLOR_BTNHILIGHT);
    default:
      return 0;
  }
}
// CAE220: using guessed type wchar_t aData_0[5];
// CDA391: using guessed type char gbWintrustInited;

//----- (00C4ADD0) --------------------------------------------------------
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

  hWnd = (CResizer *)hDlg;
  hWndTab = GetDlgItem(hDlg, IDS_PROCPROPSHEET_TABCTRL);
  v4 = GetWindowLongW(hDlg, GWLP_USERDATA);
  v5 = (tagTREEVIEWLISTITEMPARAM **)v4;
  if ( uMsg > WM_NOTIFY )
  {
    if ( uMsg == WM_INITDIALOG )
    {
      pResizer = (CResizer *)operator new(0x40u);
      hWnd = pResizer;
      v38 = 0;
      if ( pResizer )
        CResizer::CResizer(pResizer, hDlg);
      SetWindowLongW(hDlg, GWLP_USERDATA, (LONG)PropItem);
      v22 = hWndTab;
      tcitem.mask = 3;
      tcitem.iImage = -1;
      tcitem.pszText = L"Image";
      ::SendMessageW(hWndTab, TCM_INSERTITEMW, 0, (LPARAM)&tcitem);
      wcscpy_s(PropItem->PageData[1].szTemplateName, 0x100u, L"PROCSTRINGS");
      PropItem->PageData[1].nTabId = 13;
      PropItem->PageData[1].PageWndProc = PageProcStrings;
      tcitem.pszText = L"Strings";
      ::SendMessageW(v22, TCM_INSERTITEMW, 1u, (LPARAM)&tcitem);
      v23 = wcsrchr(*((const wchar_t **)PropItem->pListItem + 86), '\\') == 0;
      v24 = PropItem->pListItem;
      if ( v23 )
        v25 = (wchar_t *)*((_DWORD *)v24 + 86);
      else
        v25 = wcsrchr(*((const wchar_t **)v24 + 86), '\\') + 1;
      swprintf(&String, L"%s Properties", v25);
      SetWindowTextW(hDlg, &String);
      hDlgDllInfo = CreateDialogParamW(
                      ghMainInstance,
                      L"DLLINFO",
                      hDlg,
                      (DLGPROC)DlgDllInfo,
                      (LPARAM)PropItem->pListItem);
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
      ::SendMessageW(hDlg, WM_NOTIFY, 0, (LPARAM)&lParam);
      if ( gConfig.WindowPlacement[6].length == gConfig.WindowPlacement[5].ptMaxPosition.x )
      {
        GetCursorPos(&Point);
        v29.y = Point.y - 408;
        v29.x = Point.x - 385;
        PE_SetWindowPlacement(hDlg, v29);
      }
      else
      {
        sub_C5DC50(hDlg, (tagTREEVIEWLISTITEMPARAM *)PropItem->pListItem);
      }
      ShowWindow(hDlg, 5);
      InterlockedDecrement(&gnRefCount);
      v30 = LoadCursorW(0, (LPCWSTR)0x7F00);
      SetCursor(v30);
      return 1;
    }
    if ( uMsg == 273 )
    {
      if ( (signed int)(unsigned __int16)wParam > 40092 )
      {
        if ( (unsigned __int16)wParam != 40093 )
          return 0;
        v18 = ::SendMessageW(hWndTab, TCM_GETCURSEL, 0, 0);
        v19 = v18 - 1;
        if ( !v18 )
        {
          v19 = 0;
          for ( i = v5 + 263; *i; ++v19 )
            i += 131;
        }
        SendMessageW = (void (__stdcall *)(HWND, UINT, WPARAM, LPARAM))::SendMessageW;
        ::SendMessageW(hWndTab, TCM_SETCURSEL, v19, 0);
      }
      else
      {
        if ( (unsigned __int16)wParam != 40092 )
        {
          if ( (signed int)(unsigned __int16)wParam > 0
            && ((signed int)(unsigned __int16)wParam <= 2 || (unsigned __int16)wParam == 40014) )
          {
            v14 = (HWND *)(v4 + 8);
            v15 = (HWND)32;
            hWndTab = (HWND)32;
            while ( 1 )
            {
              if ( *v14 )
              {
                ::SendMessageW(*v14, WM_COMMAND, wParam, 0);
                DestroyWindow(*v14);
                v15 = hWndTab;
              }
              v14 += 131;
              v15 = (HWND)((char *)v15 - 1);
              hWndTab = v15;
              if ( !v15 )
              {
                DLLLISTITEMPARAM_Release(v5[1]);
                free(v5);
                GetWindowPlacement((HWND)hWnd, (WINDOWPLACEMENT *)((char *)&gConfig.WindowPlacement[4] + 20));
                DestroyWindow((HWND)hWnd);
                _endthread();
              }
            }
          }
          return 0;
        }
        SendMessageW = (void (__stdcall *)(HWND, UINT, WPARAM, LPARAM))::SendMessageW;
        v17 = ::SendMessageW(hWndTab, TCM_GETCURSEL, 0, 0) + 1;
        if ( !v5[131 * v17 + 132] )
          v17 = 0;
        ::SendMessageW(hWndTab, TCM_SETCURSEL, v17, 0);
      }
      lParam.idFrom = IDS_PROCPROPSHEET_TABCTRL;
      lParam.code = TCN_SELCHANGE;
      SendMessageW(hDlg, WM_NOTIFY, 0, (LPARAM)&lParam);
    }
    return 0;
  }
  if ( uMsg == WM_NOTIFY )
  {
    if ( PropItem->pListItem == (void *)IDS_PROCPROPSHEET_TABCTRL && PropItem->PageData[0].hWnd == (HWND)-0x227 )
    {
      v9 = ::SendMessageW(hWndTab, TCM_GETCURSEL, 0, 0);
      v10 = (tagTREEVIEWLISTITEMPARAM *)v9;
      v11 = (HWND)&v5[131 * v9];
      gConfig.dwDefaultDllPropPage = *(_DWORD *)((char *)v11 + 524);
      v12 = 131 * (_DWORD)*v5;
      hWndTab = v11;
      ShowWindow((HWND)v5[v12 + 2], 0);
      *v5 = v10;
      v13 = hWndTab;
      if ( !*((_DWORD *)hWndTab + 2) )
        *((_DWORD *)hWndTab + 2) = CreateDialogParamW(
                                     ghMainInstance,
                                     (LPCWSTR)hWndTab + 6,
                                     hDlg,
                                     *((DLGPROC *)hWndTab + 132),
                                     (LPARAM)v5[1]);
      ShowWindow(*((HWND *)v13 + 2), 5);
      return 0;
    }
    return 0;
  }
  if ( uMsg != WM_SIZE )
  {
    if ( uMsg == WM_GETMINMAXINFO )
    {
      PropItem->PageData[0].hWnd = (HWND)(2 * gdwVirtualScreenWidth);
      return 0;
    }
    return 0;
  }
  v7 = (HWND *)(v4 + 8);
  v8 = 32;
  do
  {
    if ( *v7 )
    {
      GetWindowRect(hWndTab, &Rect);
      ::SendMessageW(hWndTab, TCM_ADJUSTRECT, 0, (LPARAM)&Rect);
      MapWindowPoints(0, hDlg, (LPPOINT)&Rect, 2u);
      MoveWindow(*v7, Rect.left, Rect.top, Rect.right - Rect.left, Rect.bottom - Rect.top, 1);
    }
    v7 += 131;
    --v8;
  }
  while ( v8 );
  return 0;
}
// C7A009: using guessed type int _endthread(void);
// CB65E8: using guessed type wchar_t aStrings[8];
// CD4E28: using guessed type int gdwVirtualScreenWidth;

//----- (00C4B330) --------------------------------------------------------
signed int CDriver::Load()
{
  WCHAR szDirName[260]; // [esp+0h] [ebp-414h]
  WCHAR szPathName[260]; // [esp+208h] [ebp-20Ch]

  if ( !CDriver::Open(L"PROCEXP152", &ghDriverHandle) )
  {
    GetSystemDirectoryW(szDirName, MAX_PATH);
    swprintf(szPathName, L"%s\\Drivers\\%s", szDirName, L"PROCEXP152.SYS");
    if ( !CDriver::SaveDriverFromResource((LPCWSTR)0x96, szPathName) )
    {
      swprintf(szDirName, L"%%TEMP%%\\%s", L"PROCEXP152.SYS");
      ExpandEnvironmentStringsW(szDirName, szPathName, MAX_PATH);
      if ( !CDriver::SaveDriverFromResource((LPCWSTR)0x96, szPathName) )
      {
        GetCurrentDirectoryW(MAX_PATH, szDirName);
        swprintf(szPathName, L"%s\\s", szDirName, L"PROCEXP152.SYS");
        if ( !CDriver::SaveDriverFromResource((LPCWSTR)0x96, szPathName) )
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
// CB2E08: using guessed type wchar_t aProcexp152Sys[15];

//----- (00C4B490) --------------------------------------------------------
HCURSOR __cdecl sub_C4B490(HWND hWnd, tagTREEVIEWLISTITEMPARAM **pData)
{
  HWND hWnd_1; // ST14_4
  HCURSOR result; // eax
  SYSTEM_PROCESS_INFORMATION *v4; // edi
  HANDLE v5; // ecx
  HCURSOR v6; // eax
  tagTREEVIEWLISTITEMPARAM *v7; // eax
  tagTREEVIEWLISTITEMPARAM *v8; // eax
  tagTREEVIEWLISTITEMPARAM *v9; // eax
  ULONG v10; // esi
  tagTREEVIEWLISTITEMPARAM *v11; // eax
  tagTREEVIEWLISTITEMPARAM *v12; // eax
  tagTREEVIEWLISTITEMPARAM *v13; // eax
  HANDLE v14; // ecx
  void *v15; // esi
  HWND v16; // ST10_4
  tagTREEVIEWLISTITEMPARAM *v17; // edi
  HCURSOR v18; // eax
  unsigned int v19; // esi
  unsigned int v20; // eax
  int v21; // eax
  tagTREEVIEWLISTITEMPARAM *v22; // eax
  DWORD ThreadId; // [esp+8h] [ebp-4ECh]
  LVITEMW lParam; // [esp+Ch] [ebp-4E8h]
  int v25; // [esp+40h] [ebp-4B4h]
  tagTREEVIEWLISTITEMPARAM *v26; // [esp+44h] [ebp-4B0h]
  DWORD ExitCode; // [esp+48h] [ebp-4ACh]
  HWND v28; // [esp+4Ch] [ebp-4A8h]
  char ArgList[4]; // [esp+50h] [ebp-4A4h]
  ULONG ReturnLength; // [esp+54h] [ebp-4A0h]
  SYSTEM_PROCESS_INFORMATION *hCursor; // [esp+58h] [ebp-49Ch]
  char v32; // [esp+5Fh] [ebp-495h]
  char v33; // [esp+60h] [ebp-494h]
  int v34; // [esp+8Ch] [ebp-468h]
  char v35; // [esp+94h] [ebp-460h]
  wchar_t Dst; // [esp+2F0h] [ebp-204h]

  v28 = hWnd;
  *(_DWORD *)ArgList = 0;
  hCursor = 0;
  v32 = 0;
  SendMessageW(hWnd, LVM_DELETEALLITEMS, 0, 0);
  hWnd_1 = (HWND)pData[1];
  v34 = 0;
  result = (HCURSOR)SendMessageW(hWnd_1, LVM_GETNEXTITEM, 0xFFFFFFFF, 2);
  lParam.iItem = (int)result;
  if ( result != (HCURSOR)-1 )
  {
    if ( !*((_BYTE *)pData + 20) )
    {
      GetSystemProcessInfo(&hCursor, 0);
      v4 = hCursor;
      v5 = (HANDLE)(*pData)->dwProcessId;
      if ( hCursor->UniqueProcessId != v5 )
      {
        while ( v4->NextEntryOffset )
        {
          v4 = (SYSTEM_PROCESS_INFORMATION *)((char *)v4 + v4->NextEntryOffset);
          if ( v4->UniqueProcessId == v5 )
            goto LABEL_8;
        }
        v4 = 0;
      }
LABEL_8:
      v6 = LoadCursorW(0, (LPCWSTR)0x7F02);
      SetCursor(v6);
      pData[3] = (tagTREEVIEWLISTITEMPARAM *)OpenProcess(0x80000000, 0, (*pData)->dwProcessId);
      if ( SymInitialize )
      {
        EnterCriticalSection(&gPE_ImageItemVerifiedLock);
        v32 = 1;
        SymSetOptions(0x10027u);
        v7 = pData[3];
        if ( v7 )
          *((_BYTE *)pData + 20) = SymInitialize(v7, 0, 1);
        if ( !*((_BYTE *)pData + 20) )
        {
          if ( pData[3] )
            CloseHandle(pData[3]);
          v8 = (tagTREEVIEWLISTITEMPARAM *)GetCurrentProcess();
          pData[3] = v8;
          *((_BYTE *)pData + 20) = SymInitialize(v8, 0, 1);
        }
      }
      ReturnLength = 1000;
      v9 = (tagTREEVIEWLISTITEMPARAM *)malloc(0x3E8u);
      pData[2] = v9;
      if ( NtQuerySystemInformation(SystemModuleInformation, v9, 0x3E8u, &ReturnLength) )
      {
        do
        {
          free(pData[2]);
          ReturnLength += 1000;
          v10 = ReturnLength;
          v11 = (tagTREEVIEWLISTITEMPARAM *)malloc(ReturnLength);
          pData[2] = v11;
        }
        while ( NtQuerySystemInformation(SystemModuleInformation, v11, v10, &ReturnLength) );
      }
      v12 = *pData;
      pData[4] = 0;
      if ( !(v12->dwStyle & 0x10) )
      {
        v13 = (tagTREEVIEWLISTITEMPARAM *)RtlCreateQueryDebugBuffer(0, 0);
        pData[4] = v13;
        if ( v13 )
        {
          v14 = v4->UniqueProcessId;
          v26 = v13;
          v25 = (int)v14;
          v15 = (void *)_beginthreadex(0, 0, (int)QueryProcessDebugInforThreadProc, (int)&v25, 0, &ThreadId);
          if ( WaitForSingleObject(v15, 4000u) == 258 )
            TerminateThread(v15, 1u);
          GetExitCodeThread(v15, &ExitCode);
          if ( ExitCode )
          {
            RtlDestroyQueryDebugBuffer(pData[4]);
            pData[4] = 0;
          }
          CloseHandle(v15);
        }
      }
    }
    lParam.iSubItem = 0;
    v16 = (HWND)pData[1];
    lParam.mask = 4;
    SendMessageW(v16, LVM_GETITEMW, 0, (LPARAM)&lParam);
    v17 = lParam.lParam;
    v18 = LoadCursorW(0, (LPCWSTR)0x7F02);
    v19 = 0;
    hCursor = (SYSTEM_PROCESS_INFORMATION *)SetCursor(v18);
    if ( *(_DWORD *)&v17[1].field_28E[27] & 0xFFFFFFFC )
    {
      do
      {
        v20 = *(_DWORD *)(*(_DWORD *)&v17[1].field_28E[25] + 4 * v19);
        if ( v20 && v20 != -1 )
        {
          sub_C4DD60(1, v20, (int)&v33, (unsigned int)pData[3], 0, 0, (int)pData[4], (unsigned int *)pData[2]);
          v21 = wcscmp((const unsigned __int16 *)&v35, L"0x0");
          if ( v21 )
            v21 = -(v21 < 0) | 1;
          if ( v21 )
          {
            lParam.mask = 5;
            lParam.iItem = 0x7FFFFFFF;
            lParam.iSubItem = 0;
            lParam.stateMask = 0;
            lParam.state = 0;
            wsprintf(&Dst, L"%d", *(_DWORD *)ArgList);
            lParam.iImage = 0;
            lParam.pszText = &Dst;
            v22 = (tagTREEVIEWLISTITEMPARAM *)(*(_DWORD *)ArgList + 1);
            *(_DWORD *)ArgList = v22;
            lParam.lParam = v22;
            result = (HCURSOR)SendMessageW(v28, LVM_INSERTITEMW, 0, (LPARAM)&lParam);
            if ( result == (HCURSOR)-1 )
              return result;
            lParam.iItem = (int)result;
            lParam.pszText = (LPWSTR)&v35;
            lParam.mask = 1;
            lParam.iSubItem = 1;
            SendMessageW(v28, LVM_SETITEMW, 0, (LPARAM)&lParam);
          }
        }
        ++v19;
      }
      while ( v19 < *(_DWORD *)&v17[1].field_28E[27] >> 2 );
    }
    if ( v32 )
      LeaveCriticalSection(&gPE_ImageItemVerifiedLock);
    result = SetCursor((HCURSOR)hCursor);
  }
  return result;
}
// CB5208: using guessed type wchar_t a0x0[4];
// CDF264: using guessed type int (__stdcall *RtlDestroyQueryDebugBuffer)(_DWORD);

//----- (00C4B8D0) --------------------------------------------------------
CHAR *__thiscall ATL::CSimpleStringT<wchar_t,0>::Empty(CString *this)
{
  CString *v1; // esi
  CHAR *result; // eax
  CStringData *v3; // edx
  IAtlStringMgr *v4; // edi

  v1 = this;
  result = this->pszData;
  v3 = (CStringData *)(this->pszData - 16);
  v4 = v3->pStringMgr;
  if ( *((_DWORD *)this->pszData - 3) )
  {
    if ( v3->nRefs >= 0 )
    {
      if ( _InterlockedDecrement(&v3->nRefs) <= 0 )
        ((void (__stdcall *)(CStringData *))v3->pStringMgr->vtptr->Free)(v3);
      result = (CHAR *)(((int (__thiscall *)(IAtlStringMgr *))v4->vtptr->GetNilData)(v4) + 16);
      v1->pszData = result;
    }
    else
    {
      if ( *((_DWORD *)result - 2) < 0 )
        ATL::AtlThrowImpl(E_INVALIDARG);
      *((_DWORD *)result - 3) = 0;
      result = this->pszData;
      *this->pszData = 0;
    }
  }
  return result;
}

//----- (00C4B930) --------------------------------------------------------
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
  strText.pszData = (CHAR *)ppszCurrentDirectory;
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
        operator delete(CommandBuffer);
        return;
      }
      *((_WORD *)CommandBuffer + ((unsigned int)ProcessParameters.CommandLine.Length >> 1)) = 0;
      *ppCommandBuffer = (WCHAR *)CommandBuffer;
      operator delete(0);
    }
    if ( strText.pszData )
    {
      v9 = ProcessParameters.CurrentDirectory.DosPath.Length;
      CommandBuffer = malloc(ProcessParameters.CurrentDirectory.DosPath.Length + 2);
      v10 = v9;
      ReadProcessMemory = ::ReadProcessMemory;
      if ( !::ReadProcessMemory(hProcess, ProcessParameters.CurrentDirectory.DosPath.Buffer, CommandBuffer, v10, &dwRet) )
        goto LABEL_6;
      *((_WORD *)CommandBuffer + ((unsigned int)ProcessParameters.CurrentDirectory.DosPath.Length >> 1)) = 0;
      *(_DWORD *)strText.pszData = CommandBuffer;
      operator delete(0);
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
        v12 = (unsigned __int16 *)szEnvironmentBuffer;
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
              sub_C1DB80(&strText, v12, v13);
              sub_C4A4A0(&strText, 0);
              v12 += v13;
            }
            ++v12;
          }
          while ( *v12 );
        }
        v14 = strText.pszData;
        v15 = 2 * *((_DWORD *)strText.pszData - 3) + 2;
        v16 = (WCHAR *)malloc(v15);
        *ppszEnvBlock = v16;
        memmove_0(v16, v14, v15);
        v17 = (CStringData *)(v14 - 16);
        v24 = -1;
        if ( _InterlockedDecrement(&v17->nRefs) <= 0 )
          ((void (__stdcall *)(CStringData *))v17->pStringMgr->vtptr->Free)(v17);
      }
    }
  }
}

//----- (00C4BBC0) --------------------------------------------------------
int __stdcall FindDlg_SortCallback(int a1, int a2, int a3)
{
  int v3; // eax
  int v4; // ecx

  if ( a3 )
  {
    if ( a3 == 1 )
    {
      v4 = *(_DWORD *)(a1 + 168) - *(_DWORD *)(a2 + 168);
      goto LABEL_9;
    }
    if ( a3 == 2 )
      v3 = _wcsicmp((const wchar_t *)(a1 + 40), (const wchar_t *)(a2 + 40));
    else
      v3 = _wcsicmp(*(const wchar_t **)(a1 + 180), *(const wchar_t **)(a2 + 180));
  }
  else
  {
    v3 = _wcsicmp(*(const wchar_t **)(a1 + 36), *(const wchar_t **)(a2 + 36));
  }
  v4 = v3;
LABEL_9:
  if ( !byte_CCE8B0 )
    v4 = -v4;
  return v4;
}
// C4BBC0: using guessed type int __stdcall FindDlg_SortCallback(int, int, int);
// CCE8B0: using guessed type char byte_CCE8B0;

//----- (00C4BC30) --------------------------------------------------------
HANDLE __stdcall FindExecutableImageExW_1(PCWSTR FileName, PCWSTR SymbolPath, PWSTR ImageFilePath, PFIND_EXE_FILE_CALLBACKW Callback, PVOID CallerData)
{
  return FindExecutableImageExW(FileName, SymbolPath, ImageFilePath, 0, 0);
}

//----- (00C4BC50) --------------------------------------------------------
int __stdcall sub_C4BC50(LPCWSTR a1, LPCWSTR a2, int a3)
{
  CString *SymbolPath; // esi
  CString *FileName; // eax
  int v5; // eax
  int v6; // edi
  int v7; // ebx
  int v8; // edx
  int v10; // [esp+10h] [ebp-124h]
  int v11; // [esp+14h] [ebp-120h]
  CHAR MultiByteStr; // [esp+18h] [ebp-11Ch]
  LPWSTR lpWideCharStr; // [esp+120h] [ebp-14h]
  int v14; // [esp+130h] [ebp-4h]

  lpWideCharStr = (LPWSTR)a3;
  v14 = 0;
  SymbolPath = sub_C49E00(&v11, a2);
  LOBYTE(v14) = 1;
  FileName = sub_C49E00(&v10, a1);
  LOBYTE(v14) = 2;
  v5 = FindExecutableImage(FileName->pszData, SymbolPath->pszData, &MultiByteStr);
  v6 = v10 - 16;
  LOBYTE(v14) = 1;
  v7 = v5;
  if ( _InterlockedDecrement((volatile signed __int32 *)(v10 - 16 + 12)) <= 0 )
    (*(void (__stdcall **)(int))(**(_DWORD **)v6 + 4))(v6);
  v8 = v11 - 16;
  LOBYTE(v14) = 0;
  if ( _InterlockedDecrement((volatile signed __int32 *)(v11 - 16 + 12)) <= 0 )
    (*(void (__stdcall **)(int))(**(_DWORD **)v8 + 4))(v8);
  MultiByteToWideChar(0, 0, &MultiByteStr, 261, lpWideCharStr, 261);
  return v7;
}

//----- (00C4BD50) --------------------------------------------------------
int __userpurge FindDlg_SearchThreadProc@<eax>(signed int a1@<ebx>, _BYTE *wParam)
{
  HWND v2; // eax

  CMainWnd::RefreshDllsView(a1, ghWndListInFindDlg, 0, (WPARAM)wParam);
  CMainWnd::RefreshHandlesView(a1, ghWndListInFindDlg, 0, wParam);
  v2 = GetParent(ghWndListInFindDlg);
  PostMessageW(v2, 0x464u, 0, 0);
  return 0;
}

//----- (00C4BDA0) --------------------------------------------------------
HWND __cdecl sub_C4BDA0(HWND hWndParent)
{
  HWND v1; // eax
  HWND result; // eax

  v1 = FindWindowExW(hWndParent, 0, 0, L"OK");
  if ( v1 )
    ShowWindow(v1, 0);
  result = FindWindowExW(hWndParent, 0, 0, L"Cancel");
  if ( result )
    result = (HWND)SetWindowTextW(result, L"&OK");
  return result;
}

//----- (00C4BDF0) --------------------------------------------------------
CHAR *__thiscall ATL::CSimpleStringT<wchar_t,0>::Fork(CString *this, int a2)
{
  CStringData *v2; // esi
  int v3; // ebx
  IAtlStringMgr *v4; // eax
  int nCharsToCopy; // edi
  CStringData *pNewData; // eax
  CStringData *v7; // ebx
  CHAR *result; // eax
  CString v9; // [esp+Ch] [ebp-8h]
  int v10; // [esp+10h] [ebp-4h]
  CStringData *v11; // [esp+1Ch] [ebp+8h]

  v9.pszData = (CHAR *)this;
  v2 = (CStringData *)(this->pszData - 16);
  v3 = v2->nDataLength;
  v10 = v2->nDataLength;
  v4 = (IAtlStringMgr *)((int (*)(void))v2->pStringMgr->vtptr->Clone)();
  nCharsToCopy = a2;
  pNewData = (CStringData *)((int (__thiscall *)(IAtlStringMgr *, int, signed int))v4->vtptr->Allocate)(v4, a2, 1);
  v11 = pNewData;
  if ( !pNewData )
    ATL::CSimpleStringT<wchar_t,0>::ThrowMemoryException();
  if ( v3 < nCharsToCopy )
    nCharsToCopy = v3;
  v7 = pNewData + 1;
  memcpy_s(&pNewData[1], nCharsToCopy + 1, &v2[1], nCharsToCopy + 1);
  v11->nDataLength = v10;
  if ( _InterlockedDecrement(&v2->nRefs) <= 0 )
    ((void (__stdcall *)(CStringData *))v2->pStringMgr->vtptr->Free)(v2);
  result = v9.pszData;
  *(_DWORD *)v9.pszData = v7;
  return result;
}

//----- (00C4BE70) --------------------------------------------------------
HLOCAL __cdecl GetErrorMsg(wchar_t *Dst, size_t SizeInWords)
{
  int v2; // ecx
  DWORD v3; // eax
  WCHAR Buffer[2]; // [esp+0h] [ebp-4h]

  *(_DWORD *)Buffer = v2;
  v3 = GetLastError();
  FormatMessageW(0x1100u, 0, v3, LOCALE_USER_DEFAULT, Buffer, 0, 0);
  swprintf_s(Dst, SizeInWords, L"%s", *(_DWORD *)Buffer);
  return LocalFree(*(HLOCAL *)Buffer);
}

//----- (00C4BEC0) --------------------------------------------------------
int __cdecl PE_MakeFileVersion(int a1, int a2, wchar_t *Dst, size_t SizeInWords)
{
  return swprintf_s(
           Dst,
           SizeInWords,
           L"%d.%d.%d.%d",
           (unsigned int)a2 >> 16,
           (unsigned __int16)a2,
           (unsigned int)a1 >> 16,
           (unsigned __int16)a1);
}

//----- (00C4BEF0) --------------------------------------------------------
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
      pfnGetProcessMitigationPolicy = (int (__stdcall *)(HANDLE, _PROCESS_MITIGATION_POLICY, PVOID, SIZE_T))GetProcAddress(v4, "GetProcessMitigationPolicy");
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
        (LPDWORD)&Policy.Permanent,
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
    if ( !Fake_GetProcessDEPPolicy(ProcessHandle, &Flags, (PBOOL)&Policy.Permanent) )
      return ret;
    result = 0;
    if ( Flags & 1 )
      result = 1;
    if ( Flags & 2 )
      result |= 4u;
    if ( *(_DWORD *)&Policy.Permanent )
      result |= 8u;
  }
  return result;
}
// CD4E54: using guessed type int gdwVersion;

//----- (00C4C020) --------------------------------------------------------
int __stdcall BackendQueryObjectThreadProc(void *a1)
{
  ULONG ReturnedLength; // [esp+4h] [ebp-4h]

  while ( !WaitForSingleObject(ghExitEventForQueryObject, 0xFFFFFFFF) )
  {
    ReturnedLength = gpObjectNameInformation->Name.Length + 8;
    gulQueryObjectResult = NtQueryObject(
                             ghProcessDuplicated,
                             ObjectNameInformation,
                             gpObjectNameInformation,
                             ReturnedLength,
                             &ReturnedLength);
    SetEvent(ghQueryObjectEventDone);
  }
  return 0;
}
// CDABA0: using guessed type int gulQueryObjectResult;

//----- (00C4C090) --------------------------------------------------------
int __stdcall BackendQueryProcessKernelObjectSecurity(SERVERINFO *nLengthNeeded)
{
  SERVERINFO *v1; // edi
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
    if ( nLengthNeeded->m_RequestInformation & v3 )
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
  v5 = (void *)PE_DuplicateProcessHandle(
                 (DWORD)nLengthNeeded->m_ThreadInfo[4].m_ThreadHandle,
                 nLengthNeeded->m_ThreadInfo[5].m_ThreadHandle,
                 v2);
  if ( v5 )
  {
    GetKernelObjectSecurity(v5, v1->m_RequestInformation, 0, 0, (LPDWORD)&nLengthNeeded);
    *(_DWORD *)v1->m_SecurityDescriptor = LocalAlloc(0x40u, (SIZE_T)nLengthNeeded);
    v6 = GetKernelObjectSecurity(
           v5,
           v1->m_RequestInformation,
           *(PSECURITY_DESCRIPTOR *)v1->m_SecurityDescriptor,
           (DWORD)nLengthNeeded,
           (LPDWORD)&nLengthNeeded);
    CloseHandle(v5);
    if ( v6 )
    {
      result = 0;
      v1->m_dwError = 0;
    }
    else
    {
      v1->m_dwError = GetLastError();
      result = 0;
    }
  }
  else
  {
    v1->m_dwError = 6;
    result = 0;
  }
  return result;
}

//----- (00C4C190) --------------------------------------------------------
LPVOID __cdecl PE_QueryVersionInfo(LPCVOID pBlock, int a2, unsigned __int16 a3, LPCWSTR lpszName)
{
  BOOL v4; // eax
  BOOL v5; // ecx
  LPVOID result; // eax
  unsigned int puLen; // [esp+10h] [ebp-228h]
  LPVOID lpBuffer; // [esp+14h] [ebp-224h]
  BOOL v9; // [esp+18h] [ebp-220h]
  __int16 SubBlock[256]; // [esp+1Ch] [ebp-21Ch]
  CPPEH_RECORD ms_exc; // [esp+220h] [ebp-18h]

  v9 = 0;
  wsprintf((wchar_t *)SubBlock, L"\\StringFileInfo\\%04X%04X\\%s", (unsigned __int16)a2, a3, lpszName);
  ms_exc.registration.TryLevel = 0;
  v4 = VerQueryValueW(pBlock, (LPCWSTR)SubBlock, &lpBuffer, &puLen);
  v5 = v4;
  v9 = v4;
  ms_exc.registration.TryLevel = -2;
  result = lpBuffer;
  if ( !v5 )
    result = 0;
  return result;
}

//----- (00C4C270) --------------------------------------------------------
CCmdString __cdecl CCmdString::GetLongPathName(CCmdString strPath, rsize_t SizeInWords)
{
  __int16 *v2; // ecx
  __int16 v3; // ax
  int nLength; // edi
  __int16 *v5; // ecx
  __int16 v6; // ax
  wchar_t *v7; // esi

  if ( !*(_DWORD *)GetLongPathNameW )
    return *(CCmdString *)strPath.m_String;
  v2 = *(__int16 **)strPath.m_String;
  do
  {
    v3 = *v2;
    ++v2;
  }
  while ( v3 );
  if ( SizeInWords <= ((signed int)((char *)v2 - *(_DWORD *)strPath.m_String - 2) >> 1) + 1 )
  {
    v5 = *(__int16 **)strPath.m_String;
    do
    {
      v6 = *v5;
      ++v5;
    }
    while ( v6 );
    nLength = ((signed int)((char *)v5 - *(_DWORD *)strPath.m_String - 2) >> 1) + 1;
  }
  else
  {
    nLength = SizeInWords;
  }
  v7 = (wchar_t *)malloc(2 * nLength);
  wcscpy_s(v7, nLength, *(const wchar_t **)strPath.m_String);
  GetLongPathNameW(v7, *(LPWSTR *)strPath.m_String, SizeInWords);
  operator delete(v7);
  return *(CCmdString *)strPath.m_String;
}

//----- (00C4C350) --------------------------------------------------------
void __cdecl CCmdString::GetFullPathName(CCmdString *strPath)
{
  DWORD v1; // eax
  DWORD cbSize; // ebx
  WCHAR *pszLongPathName; // ST1C_4

  if ( *(_DWORD *)GetLongPathNameW )
  {
    v1 = GetLongPathNameW(strPath->m_String, 0, 0);
    cbSize = v1;
    if ( v1 )
    {
      pszLongPathName = (WCHAR *)malloc(2 * v1 + 2);
      GetLongPathNameW(strPath->m_String, pszLongPathName, cbSize + 1);
      free(strPath->m_String);
      strPath->m_String = pszLongPathName;
      operator delete(0);
    }
  }
}

//----- (00C4C3E0) --------------------------------------------------------
int __stdcall QueryProcessDebugInforThreadProc(_DWORD *a1)
{
  return RtlQueryProcessDebugInformation(*a1, 1, a1[1]);
}
// CDF260: using guessed type int (__stdcall *RtlQueryProcessDebugInformation)(_DWORD, _DWORD, _DWORD);

//----- (00C4C400) --------------------------------------------------------
char __cdecl sub_C4C400(int *a1, _DWORD *a2)
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

//----- (00C4C4F0) --------------------------------------------------------
char __cdecl sub_C4C4F0(tagHandleTableEntryInfo *pInfo, int a2, int a3, int a4)
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

  v17 = (_DWORD *)a2;
  v4 = 0;
  v20 = (_DWORD *)a3;
  v16 = (_DWORD *)a4;
  if ( !pInfo )
  {
    if ( sdwProcessIdInsub_103C4F0 != -1 )
    {
      CloseHandle(ghSourceProcessHandle);
      sdwProcessIdInsub_103C4F0 = -1;
    }
    return 0;
  }
  if ( sdwProcessIdInsub_103C4F0 != pInfo->dwProcessId )
  {
    if ( sdwProcessIdInsub_103C4F0 != -1 )
    {
      sdwProcessIdInsub_103C4F0 = -1;
      CloseHandle(ghSourceProcessHandle);
    }
    ghSourceProcessHandle = OpenProcess(PROCESS_DUP_HANDLE, 0, pInfo->dwProcessId);
    if ( !ghSourceProcessHandle )
      return 0;
    sdwProcessIdInsub_103C4F0 = pInfo->dwProcessId;
  }
  v6 = GetCurrentProcess();
  if ( !DuplicateHandle(ghSourceProcessHandle, pInfo->hSourceHandle, v6, &TargetHandle, 0, 0, 0) )
    return 0;
  lpOutBuffer = malloc(0x408u);
  InBuffer = GetCurrentProcessId();
  v13 = pInfo->GrantedAccess;
  v15 = TargetHandle;
  v14 = 0;
  if ( ::DeviceIoControl(
         ghDriverHandle,
         CTRLCODE_DUPLICATE_HANDLE,
         &InBuffer,
         0x10u,
         lpOutBuffer,
         0x408u,
         &BytesReturned,
         0)
    && (!_wcsicmp((const wchar_t *)lpOutBuffer + 2, L"\\Device\\Tcp")
     || !_wcsicmp((const wchar_t *)lpOutBuffer + 2, L"\\Device\\Udp")) )
  {
    if ( (unsigned __int8)GetVersion() >= 5u )
    {
      DeviceIoControl = ::DeviceIoControl;
    }
    else
    {
      DeviceIoControl = ::DeviceIoControl;
      ::DeviceIoControl(ghDriverHandle, 0x83350020, pInfo, 4u, &OutBuffer, 4u, &BytesReturned, 0);
    }
    if ( (unsigned __int8)GetVersion() >= 5u || OutBuffer == 1 || OutBuffer == 2 )
    {
      Overlapped.hEvent = 0;
      _mm_storeu_si128((__m128i *)&Overlapped, (__m128i)0i64);
      Overlapped.hEvent = CreateEventW(0, 0, 0, 0);
      v10 = 3;
      if ( DeviceIoControl(TargetHandle, 0x210012u, &v9, 0x18u, &v23, 0x1Au, 0, &Overlapped) )
      {
        v8 = _wcsicmp((const wchar_t *)lpOutBuffer + 2, L"\\Device\\Tcp");
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
// CD10D4: using guessed type int sdwProcessIdInsub_103C4F0;

//----- (00C4C750) --------------------------------------------------------
void __cdecl PE_QueryObject(wchar_t *pszObjectTypeName, _SYSTEM_HANDLE_TABLE_ENTRY_INFO_EX *pTableEntry, wchar_t *pszBuffer, rsize_t cbBufLen, WCHAR **ppszText)
{
  rsize_t v5; // esi
  int v6; // eax
  OBJECT_TYPE_INFORMATION *ProcessHandle; // eax
  size_t v8; // esi
  OBJECT_TYPE_INFORMATION *pInfo; // eax
  BOOL v10; // eax
  OBJECT_TYPE_INFORMATION *v11; // esi
  size_t v12; // esi
  _OBJECT_TYPE_INFORMATION *pObjectType; // eax
  ULONG v14; // ST20_4
  OBJECT_TYPE_INFORMATION *v15; // esi
  int v16; // eax
  void *ProcessHandle2; // edi
  DWORD v18; // ebx
  void *v19; // eax
  void *v20; // ebx
  size_t cbLength; // esi
  void *OutBuffer; // eax
  PVOID v23; // ecx
  bool v24; // zf
  DWORD v25; // ebx
  void *v26; // ebx
  OBJECT_NAME_INFORMATION *v27; // edi
  HANDLE v28; // eax
  int v29; // eax
  void *ThreadHandle; // ebx
  PROCESS_BASIC_INFORMATION ProcessInfo; // [esp+Ch] [ebp-10C0h]
  THREAD_BASIC_INFORMATION ThreadInfo; // [esp+24h] [ebp-10A8h]
  enum _SID_NAME_USE peUse; // [esp+40h] [ebp-108Ch]
  DWORD ThreadId; // [esp+44h] [ebp-1088h]
  DWORD cchReferencedDomainName; // [esp+48h] [ebp-1084h]
  DWORD cchName; // [esp+4Ch] [ebp-1080h]
  int InBuffer[4]; // [esp+50h] [ebp-107Ch]
  WCHAR **v38; // [esp+60h] [ebp-106Ch]
  DWORD dwRet; // [esp+64h] [ebp-1068h]
  OBJECT_TYPE_INFORMATION *hObject; // [esp+68h] [ebp-1064h]
  size_t cbRet; // [esp+6Ch] [ebp-1060h]
  wchar_t *Dst; // [esp+70h] [ebp-105Ch]
  DWORD BytesReturned; // [esp+74h] [ebp-1058h]
  TOKEN_STATISTICS TokenStatistics; // [esp+78h] [ebp-1054h]
  TOKEN_USER TokenUser[256]; // [esp+B0h] [ebp-101Ch]
  WCHAR Name[260]; // [esp+8B0h] [ebp-81Ch]
  WCHAR ReferencedDomainName[260]; // [esp+AB8h] [ebp-614h]
  wchar_t v48[260]; // [esp+CC0h] [ebp-40Ch]
  WCHAR pszText[256]; // [esp+EC8h] [ebp-204h]

  v5 = cbBufLen;
  Dst = pszBuffer;
  v38 = ppszText;
  wcscpy_s(pszBuffer, cbBufLen, (const wchar_t *)&gszNullString);
  if ( ppszText )
    *v38 = 0;
  if ( !*pszObjectTypeName )
    goto LABEL_55;
  v6 = wcscmp(pszObjectTypeName, L"<Unknown type>");
  if ( v6 )
    v6 = -(v6 < 0) | 1;
  if ( !v6 )
  {
LABEL_55:
    ProcessHandle = (OBJECT_TYPE_INFORMATION *)PE_DuplicateProcessHandle(
                                                 pTableEntry->UniqueProcessId,
                                                 (HANDLE)pTableEntry->HandleValue,
                                                 0);
    hObject = ProcessHandle;
    if ( ProcessHandle )
    {
      NtQueryObject(ProcessHandle, ObjectTypeInformation, 0, 0, &cbRet);
      v12 = cbRet;
      pObjectType = (_OBJECT_TYPE_INFORMATION *)malloc(cbRet);
      v14 = v12;
      v15 = pObjectType;
      v16 = NtQueryObject(hObject, ObjectTypeInformation, pObjectType, v14, 0);
      if ( v16 )
        MakeDeviceName(pszObjectTypeName, L"<Unknown type: %X>", v16);
      else
        wcsncpy_s(pszObjectTypeName, 0x40u, v15->TypeName.Buffer, (unsigned int)v15->TypeName.Length >> 1);
      free(v15);
      CloseHandle(hObject);
LABEL_17:
      v5 = cbBufLen;
      goto LABEL_18;
    }
    if ( ghDriverHandle != (HANDLE)-1 )
    {
      v8 = 2 * cbBufLen + 8;
      pInfo = (OBJECT_TYPE_INFORMATION *)malloc(v8);
      InBuffer[0] = pTableEntry->UniqueProcessId;
      InBuffer[1] = (int)pTableEntry->Object;
      InBuffer[3] = pTableEntry->HandleValue;
      hObject = pInfo;
      v10 = DeviceIoControl(ghDriverHandle, CTRLCODE_QUERY_OBJECT_TYPE, InBuffer, 0x10u, pInfo, v8, &BytesReturned, 0);
      v11 = hObject;
      if ( v10 )
        wcscpy_s(pszObjectTypeName, 0x40u, (const wchar_t *)&hObject->TypeName.Buffer);
      free(v11);
      goto LABEL_17;
    }
    MakeDeviceName(pszObjectTypeName, L"<Unknown type>");
  }
LABEL_18:
  if ( _wcsicmp(pszObjectTypeName, L"process") && _wcsicmp(pszObjectTypeName, L"thread") )
  {
    if ( _wcsicmp(pszObjectTypeName, L"token") )
    {
      if ( _wcsicmp(pszObjectTypeName, L"EtwRegistration") )
      {
        if ( ghDriverHandle == (HANDLE)-1 )
        {
          v26 = (void *)PE_DuplicateProcessHandle(pTableEntry->UniqueProcessId, (HANDLE)pTableEntry->HandleValue, 0);
          if ( v26 )
          {
            cbRet = 1024;
            v27 = (OBJECT_NAME_INFORMATION *)malloc(0x400u);
            _mm_storel_epi64((__m128i *)v27, (__m128i)0i64);
            v27->Name.Length = cbRet - 8;
            if ( !ghBackendQueryObjectThreadHandle )
              ghBackendQueryObjectThreadHandle = (HANDLE)_beginthreadex(
                                                           0,
                                                           0,
                                                           (int)BackendQueryObjectThreadProc,
                                                           0,
                                                           0,
                                                           &ThreadId);
            v28 = ghExitEventForQueryObject;
            if ( !ghExitEventForQueryObject )
            {
              ghExitEventForQueryObject = CreateEventW(
                                            (LPSECURITY_ATTRIBUTES)ghExitEventForQueryObject,
                                            (BOOL)ghExitEventForQueryObject,
                                            (BOOL)ghExitEventForQueryObject,
                                            (LPCWSTR)ghExitEventForQueryObject);
              ghQueryObjectEventDone = CreateEventW(0, 0, 0, 0);
              v28 = ghExitEventForQueryObject;
            }
            gpObjectNameInformation = v27;
            ghProcessDuplicated = v26;
            SetEvent(v28);
            if ( WaitForSingleObject(ghQueryObjectEventDone, 0x3E8u) == 258 )
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
                wcsncpy_s(Dst, cbBufLen, (int)v27);
              free(v27);
              CloseHandle(v26);
            }
          }
        }
        else
        {
          cbLength = 2 * v5 + 8;
          OutBuffer = malloc(cbLength);
          InBuffer[0] = pTableEntry->UniqueProcessId;
          v23 = pTableEntry->Object;
          BytesReturned = (DWORD)OutBuffer;
          InBuffer[1] = (int)v23;
          v24 = _wcsicmp(pszObjectTypeName, L"file") == 0;
          v25 = BytesReturned;
          InBuffer[3] = pTableEntry->HandleValue;
          LOBYTE(InBuffer[2]) = v24;
          if ( CDriver::Control(CTRLCODE_DUPLICATE_HANDLE, InBuffer, 0x10u, (LPVOID)BytesReturned, cbLength) )
          {
            wcscpy_s(Dst, cbBufLen, (const wchar_t *)(v25 + 4));
            if ( v38 )
              *v38 = *(WCHAR **)v25;
          }
          free((void *)v25);
        }
      }
      else
      {
        v19 = (void *)PE_DuplicateProcessHandle(pTableEntry->UniqueProcessId, (HANDLE)pTableEntry->HandleValue, 0);
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
      ProcessHandle2 = (void *)PE_DuplicateProcessHandle(
                                 pTableEntry->UniqueProcessId,
                                 (HANDLE)pTableEntry->HandleValue,
                                 8u);
      if ( ProcessHandle2 )
      {
        TokenStatistics.AuthenticationId.HighPart = 0;
        TokenStatistics.AuthenticationId.LowPart = 0;
        dwRet = sizeof(TOKEN_STATISTICS);
        GetTokenInformation(ProcessHandle2, TokenStatistics, &TokenStatistics, sizeof(TOKEN_STATISTICS), &dwRet);
        v18 = TokenStatistics.AuthenticationId.LowPart;
        BytesReturned = TokenStatistics.AuthenticationId.HighPart;
        dwRet = 0x800;
        if ( GetTokenInformation(ProcessHandle2, TokenUser, TokenUser, 0x800u, &dwRet) )
        {
          cchName = 260;
          cchReferencedDomainName = 260;
          if ( LookupAccountSidW(
                 (LPCWSTR)&gszNullString,
                 TokenUser[0].User.Sid,
                 Name,
                 &cchName,
                 ReferencedDomainName,
                 &cchReferencedDomainName,
                 &peUse) )
          {
            swprintf_s(Dst, cbBufLen, L"%s\\%s:%x", ReferencedDomainName, Name, v18, BytesReturned);
          }
        }
        CloseHandle(ProcessHandle2);
      }
    }
  }
  else
  {
    v29 = _wcsicmp(pszObjectTypeName, L"process");
    ThreadHandle = (void *)PE_DuplicateProcessHandle(
                             pTableEntry->UniqueProcessId,
                             (HANDLE)pTableEntry->HandleValue,
                             v29 != 0 ? 64 : 1024);
    if ( ThreadHandle )
    {
      if ( _wcsicmp(pszObjectTypeName, L"Process") )
      {
        if ( !NtQueryInformationThread(
                ThreadHandle,
                ThreadBasicInformation,
                &ThreadInfo,
                sizeof(_THREAD_BASIC_INFORMATION),
                &cbRet) )
        {
          SystemProcessInfo_GetSystemProcessName((DWORD)ThreadInfo.ClientId.UniqueProcess, 0, pszText, 0x100u);
          swprintf_s(
            Dst,
            v5,
            L"%s(%d): %d",
            pszText,
            ThreadInfo.ClientId.UniqueProcess,
            ThreadInfo.ClientId.UniqueThread);
        }
      }
      else if ( !NtQueryInformationProcess(
                   ThreadHandle,
                   ProcessBasicInformation,
                   &ProcessInfo,
                   sizeof(PROCESS_BASIC_INFORMATION),
                   &cbRet) )
      {
        SystemProcessInfo_GetSystemProcessName((DWORD)ProcessInfo.UniqueProcessId, 0, pszText, 0x100u);
        swprintf_s(Dst, v5, L"%s(%d)", pszText, ProcessInfo.UniqueProcessId);
        CloseHandle(ThreadHandle);
        return;
      }
      CloseHandle(ThreadHandle);
    }
    else if ( ghDriverHandle != (HANDLE)-1 )
    {
      GetErrorMsg(v48, 0x104u);
      swprintf_s(Dst, v5, L"<%s>", v48);
    }
  }
}
// CDABA0: using guessed type int gulQueryObjectResult;

//----- (00C4CE20) --------------------------------------------------------
int __cdecl sub_C4CE20(DWORD BytesReturned, LPVOID lpOutBuffer)
{
  _DWORD *v2; // esi
  _DWORD *v3; // edi
  DWORD dwSymbolAddress; // eax
  unsigned __int64 v5; // rax
  double v6; // xmm0_8

  v2 = (_DWORD *)BytesReturned;
  v3 = lpOutBuffer;
  *(_DWORD *)BytesReturned = 0;
  v2[1] = 0;
  *v3 = 0;
  v3[1] = 0;
  if ( gdwSymbolAddressOfMmMaximumNonPagedPoolInBytes || !dword_CCE0DC )
  {
    dwSymbolAddress = gdwSymbolAddressOfMmSizeOfPagedPoolInBytes;
  }
  else
  {
    gdwSymbolAddressOfMmMaximumNonPagedPoolInBytes = LoadSystemModulesSymbolAddress("MmMaximumNonPagedPoolInBytes");
    dwSymbolAddress = LoadSystemModulesSymbolAddress("MmSizeOfPagedPoolInBytes");
    gdwSymbolAddressOfMmSizeOfPagedPoolInBytes = dwSymbolAddress;
    dword_CCE0DC = 0;
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
    v5 = (unsigned __int64)v6 << 10;
    if ( is_mul_ok(0x400u, (unsigned __int64)v6) && (unsigned int)v5 < 0x200000 )
      *v2 = v5;
    v2[1] = 0;
    v3[1] = 0;
  }
  return v5;
}
// CCE0DC: using guessed type int dword_CCE0DC;
// CF50E8: using guessed type int gdwSymbolAddressOfMmMaximumNonPagedPoolInBytes;
// CF50EC: using guessed type int gdwSymbolAddressOfMmSizeOfPagedPoolInBytes;

//----- (00C4CF30) --------------------------------------------------------
char __cdecl sub_C4CF30(HANDLE hProcess, WCHAR **ppszFileName)
{
  SIZE_T v3; // ebx
  wchar_t *v4; // esi
  char v5; // bl
  wchar_t *v6; // eax
  PROCESS_BASIC_INFORMATION ProcessInformation; // [esp+4h] [ebp-520h]
  ULONG cbRet; // [esp+1Ch] [ebp-508h]
  WCHAR **v9; // [esp+20h] [ebp-504h]
  SIZE_T dwRet; // [esp+24h] [ebp-500h]
  PEB Buffer; // [esp+28h] [ebp-4FCh]
  PEB Peb; // [esp+278h] [ebp-2ACh]

  v9 = ppszFileName;
  if ( NtQueryInformationProcess(hProcess, 0, &ProcessInformation, sizeof(PROCESS_BASIC_INFORMATION), &cbRet)
    || !ProcessInformation.PebBaseAddress )
  {
    return 0;
  }
  if ( !ReadProcessMemory(hProcess, ProcessInformation.PebBaseAddress, &Buffer, 0x250u, &dwRet)
    || !ReadProcessMemory(hProcess, Buffer.ProcessParameters, &Peb, 680u, &dwRet)
    || !Peb.TlsExpansionCounter )
  {
    return 0;
  }
  v3 = LOWORD(Peb.FreeList);
  v4 = (wchar_t *)malloc(LOWORD(Peb.FreeList) + 2);
  if ( ReadProcessMemory(hProcess, (LPCVOID)Peb.TlsExpansionCounter, v4, v3, &dwRet) )
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
  operator delete(v4);
  return v5;
}

//----- (00C4D050) --------------------------------------------------------
HICON __cdecl ExtractApplicationIcon(LPCWSTR pszPath, int uFlags)
{
  SHFILEINFOW FileInfo; // [esp+0h] [ebp-2B8h]

  FileInfo.hIcon = 0;
  if ( !pszPath )
    return 0;
  SHGetFileInfoW(pszPath, 0, &FileInfo, sizeof(SHFILEINFOW), uFlags | SHGFI_ICON);
  return FileInfo.hIcon;
}

//----- (00C4D0C0) --------------------------------------------------------
char __cdecl sub_C4D0C0(HANDLE hProcess, tagTREEVIEWLISTITEMPARAM *pItem)
{
  wchar_t *pszFileName_1; // ebx
  unsigned int v3; // kr00_4
  wchar_t *v4; // esi
  const WCHAR *v5; // ecx
  const wchar_t *v6; // eax
  wchar_t *pszCommandLine; // eax
  wchar_t *pszCommandLine2; // ebx
  int v9; // edx
  wchar_t v10; // cx
  wchar_t *v11; // eax
  wchar_t *v12; // eax
  wchar_t *lpFileName; // esi
  wchar_t i; // ax
  char v15; // cl
  int v16; // eax
  DWORD v17; // eax
  WCHAR *v18; // eax
  wchar_t *v19; // ecx
  wchar_t *v20; // ecx
  HWND v21; // eax
  HWND hWndChild; // esi
  char v23; // al
  wchar_t *v24; // ebx
  wchar_t *pszErrorMsg; // eax
  wchar_t *v27; // esi
  LPWSTR FilePart; // [esp+Ch] [ebp-2A0h]
  char hObject; // [esp+13h] [ebp-299h]
  wchar_t *pszFileName; // [esp+14h] [ebp-298h]
  DWORD pszFileName2; // [esp+18h] [ebp-294h]
  char v32; // [esp+1Fh] [ebp-28Dh]
  __int16 ClassName[260]; // [esp+20h] [ebp-28Ch]
  __int16 Dst[64]; // [esp+228h] [ebp-84h]

  pszFileName = 0;
  v32 = 0;
  if ( pItem->szProcessName )
    return 0;
  if ( !sub_C50A90(hProcess, pItem->dwProcessId, &pszFileName, pItem) )
  {
    if ( pItem->dwProcessId <= 8u )
    {
      v27 = pszFileName;
    }
    else
    {
      pszErrorMsg = (wchar_t *)malloc(0x208u);
      v27 = pszErrorMsg;
      if ( hProcess )
      {
        GetErrorMsg(pszErrorMsg + 1, 0x103u);
        *v27 = 91;
        if ( wcschr(v27, 0xDu) )
          *wcschr(v27, 0xDu) = 0;
        wcscat_s(v27, 0x104u, L"]");
      }
      else
      {
        swprintf_s(pszErrorMsg, 0x104u, L"[Error opening process]");
      }
      pItem->szProcessName = _wcsdup(v27);
    }
    if ( v27 )
      free(v27);
    return 0;
  }
  pszFileName_1 = pszFileName;
  if ( PE_GetProductCopyright(
         pszFileName,
         (wchar_t *)pItem->field_28E,
         0x41u,
         (WCHAR **)&pItem->pszTitle,
         (WCHAR **)&pItem->pszValue314)
    && GetLastError() != ERROR_RESOURCE_TYPE_NOT_FOUND )
  {
    v3 = wcslen(pszFileName_1);
    v4 = (wchar_t *)malloc(2 * (v3 + 260));
    wcscpy_s(v4, v3 + 260, pszFileName);
    GetErrorMsg(v4 + 1, v3 + 259);
    *v4 = 91;
    if ( wcschr(v4, 0xDu) )
      *wcschr(v4, 0xDu) = 0;
    wcscat_s(v4, v3 + 260, L"]");
    pItem->szProcessName = v4;
  }
  else
  {
    pszFileName2 = (DWORD)_wcsdup(pszFileName_1);
    CCmdString::GetFullPathName((CCmdString *)&pszFileName2);
    v5 = (const WCHAR *)pszFileName2;
    pItem->szProcessName = (WCHAR *)pszFileName2;
    if ( PE_CheckExeFile(v5, (DWORD *)&pItem->dwTimeDateStamp, (BOOL *)&hObject, &pItem->field_28A) )
      pItem->dwStyle |= 0x100u;
    else
      pItem->dwStyle &= -0x101u;
    if ( !_wcsicmp(pItem->szProcessName2, L"rundll32.exe")
      && (v6 = (const wchar_t *)pItem->pszCommandLine) != 0
      && wcschr(v6, 0x2Cu) )
    {
      pszCommandLine = _wcsdup((const wchar_t *)pItem->pszCommandLine);
      pszCommandLine2 = pszCommandLine;
      v9 = (int)(pszCommandLine + 1);
      do
      {
        v10 = *pszCommandLine;
        ++pszCommandLine;
      }
      while ( v10 );
      _wcsupr_s(pszCommandLine2, (((signed int)pszCommandLine - v9) >> 1) + 1);
      if ( wcsstr(pszCommandLine2, L"SHELL32.DLL") && wcsstr(pszCommandLine2, L"CONTROL_RUNDLL ") )
      {
        v11 = wcsstr(pszCommandLine2, L"CONTROL_RUNDLL");
        v12 = wcschr(v11, ' ');
        lpFileName = v12;
        for ( i = *v12; i; ++lpFileName )
        {
          if ( i != ' ' )
            break;
          i = lpFileName[1];
        }
        if ( *lpFileName == '"' )
        {
          ++lpFileName;
          if ( wcschr(lpFileName, '"') )
            *wcschr(lpFileName, '"') = 0;
        }
      }
      else
      {
        lpFileName = wcschr(pszCommandLine2, ',');
        v15 = 0;
        for ( *lpFileName = 0; lpFileName != pszCommandLine2; --lpFileName )
        {
          if ( v15 )
          {
            if ( *lpFileName == '"' )
              break;
          }
          else
          {
            v16 = *lpFileName;
            if ( v16 == ' ' )
              goto LABEL_33;
            if ( v16 == '"' )
            {
              v15 = 1;
              *lpFileName = 0;
            }
          }
        }
        if ( *lpFileName == ' ' )
LABEL_33:
          ++lpFileName;
        if ( *lpFileName == '"' )
          ++lpFileName;
        if ( !*lpFileName )
          ++lpFileName;
      }
      v17 = SearchPathW(0, lpFileName, 0, 0, 0, 0);
      pszFileName2 = v17;
      if ( v17 )
      {
        v18 = (WCHAR *)malloc(2 * v17);
        pItem->m_ExtensionName = v18;
        SearchPathW(0, lpFileName, 0, pszFileName2, v18, &FilePart);
        _wcslwr_s(pItem->m_ExtensionName, pszFileName2);
        PE_GetProductCopyright(
          pItem->m_ExtensionName,
          (wchar_t *)Dst,
          0x40u,
          (WCHAR **)&pItem->pszFileDesc,
          (WCHAR **)&pItem->pszCompany);
      }
      free(pszCommandLine2);
    }
    else if ( _wcsicmp(pItem->szProcessName2, L"svchost.exe") || (v19 = (wchar_t *)pItem->pszCommandLine) == 0 )
    {
      if ( !_wcsicmp(pItem->szProcessName2, L"dllhost.exe") )
      {
        v20 = (wchar_t *)pItem->pszCommandLine;
        if ( v20 )
          PE_LoadProductCopyright(
            v20,
            (_bstr_t *)&pItem->field_350,
            (_bstr_t *)&pItem->m_ExtensionName,
            (_bstr_t *)&pItem->pszFileDesc,
            (_bstr_t *)&pItem->pszCompany);
      }
    }
    else
    {
      sub_C34730(v19, (int)&pItem->szServiceName);
    }
    if ( !_wcsicmp(pItem->szProcessName2, L"mmc.exe") && SLOBYTE(pItem->dwStyle) >= 0 )
    {
      v21 = GetDesktopWindow();
      hWndChild = GetWindow(v21, GW_CHILD);
      pszFileName2 = 0;
      while ( 1 )
      {
        GetWindowThreadProcessId(hWndChild, &pszFileName2);
        ClassName[0] = 0;
        GetClassNameW(hWndChild, (LPWSTR)ClassName, 260);
        if ( pszFileName2 == pItem->dwProcessId && !wcsncmp((const wchar_t *)ClassName, L"MMCMainFrame", 0x104u) )
        {
          SendMessageTimeoutW(hWndChild, WM_GETICON, 0, 0, 0, 200u, (PDWORD_PTR)&pItem->hIcon);
          SendMessageTimeoutW(hWndChild, WM_GETICON, 1u, 0, 0, 200u, (PDWORD_PTR)&pItem->hFileIcon);
          v23 = 1;
          v32 = 1;
        }
        else
        {
          hWndChild = GetWindow(hWndChild, 2u);
          v23 = v32;
        }
        if ( !hWndChild )
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
  SendMessageW(ghMainWnd, WM_MSG_7F3, 0, (LPARAM)pItem);
  pItem->hFileIcon = (int)ExtractApplicationIcon(v24, 0);
LABEL_59:
  if ( pszFileName )
    free(pszFileName);
  return 1;
}

//----- (00C4D670) --------------------------------------------------------
WCHAR *__cdecl VerifyImage(tagTREEVIEWLISTITEMPARAM *pItem, char fNeedVerify)
{
  WCHAR *v2; // eax
  unsigned int *v3; // ecx
  const unsigned __int16 *pszDefault; // ebx
  WCHAR **v5; // edx
  wchar_t **v6; // esi
  PE_ImageItemVerified *v7; // eax
  PE_ImageItemVerified *v8; // esi
  HCURSOR v9; // eax
  LONG lret; // eax
  LONG v11; // esi
  WCHAR *v12; // esi
  _CRYPT_PROVIDER_CERT **v13; // ecx
  _CRYPT_PROVIDER_CERT *v14; // eax
  size_t v15; // esi
  wchar_t *pszText; // ebx
  WCHAR *v17; // eax
  unsigned int v18; // esi
  unsigned int nDefLen; // ecx
  size_t v20; // esi
  wchar_t *v21; // eax
  wchar_t *v22; // eax
  HCURSOR hCursor; // [esp+Ch] [ebp-8C0h]
  wchar_t *v25; // [esp+10h] [ebp-8BCh]
  int dwCertEncodingTypeCount; // [esp+14h] [ebp-8B8h]
  wchar_t *pcwszMemberFilePath; // [esp+18h] [ebp-8B4h]
  WCHAR **pRet; // [esp+1Ch] [ebp-8B0h]
  wchar_t **ppszVerifyTitle; // [esp+20h] [ebp-8ACh]
  unsigned int *pdwVerifyValue; // [esp+24h] [ebp-8A8h]
  PCERT_CONTEXT pCertContext; // [esp+28h] [ebp-8A4h]
  __int16 szBuffer[1040]; // [esp+A8h] [ebp-824h]

  if ( pItem->nListType == 1 )
  {
    v2 = *(WCHAR **)&pItem->gap154[4];
    v3 = (unsigned int *)&pItem->gap154[12];
    pszDefault = *(const unsigned __int16 **)pItem->gap154;
    v5 = (WCHAR **)&pItem->gap154[16];
    v6 = (wchar_t **)&pItem->gap154[20];
  }
  else
  {
    v2 = pItem->szProcessName;
    v3 = (unsigned int *)&pItem->dwVerifyValue;
    pszDefault = (const unsigned __int16 *)pItem->pszValue314;
    v5 = &pItem->field_344;
    v6 = (wchar_t **)&pItem->pszVerifyTitle;
  }
  ppszVerifyTitle = v6;
  pRet = v5;
  pcwszMemberFilePath = v2;
  pdwVerifyValue = v3;
  if ( !v2 || *v2 == '[' )
    return 0;
  if ( !*v3 )
  {
    if ( fNeedVerify )
    {
      v7 = PE_ImageItemVerified_Find(v2);
      v8 = v7;
      if ( v7 )
      {
        *ppszVerifyTitle = _wcsdup(v7->pszTitle);
        *pdwVerifyValue = (unsigned int)v8->dwValue;
      }
      else
      {
        *ppszVerifyTitle = _wcsdup(L"Verifying...");
        SendMessageW(ghMainWnd, WM_MSG_7F0, 0, (LPARAM)pItem);
        v9 = LoadCursorW(0, (LPCWSTR)IDC_WAIT);
        hCursor = SetCursor(v9);
        dwCertEncodingTypeCount = 32;
        lret = PE_DoubleVerify(
                 pcwszMemberFilePath,
                 0,
                 0,
                 0,
                 0,
                 (DWORD *)&dwCertEncodingTypeCount,
                 (PCCERT_CONTEXT *)&pCertContext,
                 0,
                 0,
                 0,
                 0,
                 0,
                 0xFFFFFFFF);
        v11 = lret;
        if ( lret )
        {
          SetLastError(lret);
          if ( v11 == CERT_E_EXPIRED )
            wcscpy_s((wchar_t *)szBuffer, 1040u, L"Certificate expired");
          else
            GetErrorMsg((wchar_t *)szBuffer, 0x410u);
          if ( wcschr((const wchar_t *)szBuffer, '.') )
            *wcschr((const wchar_t *)szBuffer, '.') = 0;
          if ( pszDefault )
            nDefLen = wcslen(pszDefault);
          else
            nDefLen = 1;
          v20 = wcslen((const unsigned __int16 *)szBuffer) + nDefLen + 32;
          v21 = (wchar_t *)malloc(2 * v20);
          v25 = v21;
          *pdwVerifyValue = 2;
          if ( pszDefault )
            swprintf_s(v21, v20, L"(%s) %s", szBuffer, pszDefault);
          else
            swprintf_s(v21, v20, L"(%s)", szBuffer);
          pszText = v25;
        }
        else
        {
          v12 = (WCHAR *)pCertContext;
          *pdwVerifyValue = 1;
          v13 = (_CRYPT_PROVIDER_CERT **)(v12 + 1);
          do
          {
            LOWORD(v14) = *v12;
            ++v12;
          }
          while ( (_WORD)v14 );
          v15 = (((char *)v12 - (char *)v13) >> 1) + 0x40;
          pszText = (wchar_t *)malloc(2 * v15);
          swprintf_s(pszText, v15, L"(Verified) %s", pCertContext);
          v17 = _wcsdup((const wchar_t *)pCertContext);
          v18 = 0;
          *pRet = v17;
          if ( dwCertEncodingTypeCount )
          {
            do
              free(*(&pCertContext + v18++));
            while ( v18 < dwCertEncodingTypeCount );
          }
        }
        SetCursor(hCursor);
        v22 = _wcsdup(pszText);
        *ppszVerifyTitle = v22;
        PE_ImageItemVerified_Create(pcwszMemberFilePath, *pdwVerifyValue, v22);
        free(pszText);
      }
    }
    else
    {
      *v6 = _wcsdup(pszDefault);
    }
    SendMessageW(ghMainWnd, WM_MSG_7F0, 0, (LPARAM)pItem);
  }
  return *pRet;
}

//----- (00C4D9D0) --------------------------------------------------------
SYSTEM_HANDLE_INFORMATION *__cdecl SystemHandleInfo_GetHandlesNumber(SYSTEM_HANDLE_INFORMATION *a1)
{
  SYSTEM_HANDLE_INFORMATION *result; // eax

  result = a1;
  if ( a1 )
    result = (SYSTEM_HANDLE_INFORMATION *)a1->NumberOfHandles;
  return result;
}

//----- (00C4D9E0) --------------------------------------------------------
SYSTEM_HANDLE_TABLE_ENTRY_INFO **__cdecl GetHandleTableEntry(SYSTEM_HANDLE_INFORMATION *pHandleInfo, int nIndex, SYSTEM_HANDLE_TABLE_ENTRY_INFO **pEntry)
{
  SYSTEM_HANDLE_TABLE_ENTRY_INFO **result; // eax
  SYSTEM_HANDLE_TABLE_ENTRY_INFO *pInfo; // ecx

  if ( gbSupportExtendedSystemHandleInformation )
  {
    result = pEntry;
    *pEntry = (SYSTEM_HANDLE_TABLE_ENTRY_INFO *)((char *)pHandleInfo->Handles
                                               + sizeof(SYSTEM_HANDLE_TABLE_ENTRY_INFO_EX) * nIndex
                                               + 4);
  }
  else
  {
    pInfo = (SYSTEM_HANDLE_TABLE_ENTRY_INFO *)((char *)pHandleInfo + sizeof(SYSTEM_HANDLE_TABLE_ENTRY_INFO) * nIndex);
    stru_CEBC0C.field_10 = pInfo->HandleValue;
    stru_CEBC0C.GrantedAccess = *(_DWORD *)&pInfo[1].UniqueProcessId;
    LOBYTE(stru_CEBC0C.field_14) = BYTE1(pInfo->Object);
    stru_CEBC0C.Object = (PVOID)HIWORD(pInfo->Object);
    *(_DWORD *)&stru_CEBC0C.field_0 = pInfo->GrantedAccess;
    *(&stru_CEBC0C.field_10 + 1) = LOBYTE(pInfo->Object);
    *(_DWORD *)&stru_CEBC0C.ObjectTypeIndex = *(unsigned __int16 *)&pInfo->ObjectTypeIndex;
    result = pEntry;
    *pEntry = (SYSTEM_HANDLE_TABLE_ENTRY_INFO *)&stru_CEBC0C;
  }
  return result;
}
// CDABA5: using guessed type char gbSupportExtendedSystemHandleInformation;
// CEBC0C: using guessed type PE_SYSTEM_HANDLE_TABLE_ENTRY_INFO stru_CEBC0C;

//----- (00C4DA60) --------------------------------------------------------
struct _FILETIME __cdecl GetSystemProcessInfo(SYSTEM_PROCESS_INFORMATION **ppSystemProcessInfo, PULONG cbRet)
{
  PULONG cbLength; // esi
  SYSTEM_PROCESS_INFORMATION *v3; // eax
  struct _FILETIME SystemTimeAsFileTime; // [esp+8h] [ebp-Ch]
  char v6; // [esp+10h] [ebp-4h]

  cbLength = (PULONG)&v6;
  if ( cbRet )
    cbLength = cbRet;
  if ( !*ppSystemProcessInfo )
  {
    *cbLength = 1000;
    *ppSystemProcessInfo = (SYSTEM_PROCESS_INFORMATION *)malloc(1000u);
  }
  GetSystemTimeAsFileTime(&SystemTimeAsFileTime);
  if ( NtQuerySystemInformation(SystemProcessInformation, *ppSystemProcessInfo, *cbLength, (PULONG)&cbRet) )
  {
    do
    {
      free(*ppSystemProcessInfo);
      *cbLength += 10000;
      v3 = (SYSTEM_PROCESS_INFORMATION *)malloc(*cbLength);
      *ppSystemProcessInfo = v3;
    }
    while ( NtQuerySystemInformation(SystemProcessInformation, v3, *cbLength, (PULONG)&cbRet) );
  }
  return SystemTimeAsFileTime;
}

//----- (00C4DAF0) --------------------------------------------------------
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
    pLocalMap = (CSystemProcessInfoMap *)std::_Tree_comp_alloc<std::_Tmap_traits<unsigned long,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *>>,0>>::_Buyheadnode();
    gpSystemProcessInfoLast = ::gpSystemProcessInfoLast;
    v25 = 0;
    if ( ::gpSystemProcessInfoLast )
    {
      pair._Key = (int)::gpSystemProcessInfoLast->UniqueProcessId;
      pair._Value = ::gpSystemProcessInfoLast;
      _Node = std::_Tree_comp_alloc<std::_Tmap_traits<unsigned long,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *>>,0>>::_Buynode<std::piecewise_construct_t const &,std::tuple<unsigned long &&>,std::tuple<>>(
                (CSystemProcessInfoMap *)&pLocalMap,
                &pair);
      std::_Tree<std::_Tmap_traits<unsigned long,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *>>,0>>::_Insert_hint<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *> &,std::_Tree_node<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *>,void *> *>(
        (CSystemProcessInfoMap *)&pLocalMap,
        (int)&_Where,
        0,
        (int)&_Node->_Keyvalue,
        _Node);
      for ( i = gpSystemProcessInfoLast->NextEntryOffset;
            gpSystemProcessInfoLast->NextEntryOffset;
            i = gpSystemProcessInfoLast->NextEntryOffset )
      {
        gpSystemProcessInfoLast = (SYSTEM_PROCESS_INFORMATION *)((char *)gpSystemProcessInfoLast + i);
        pair._Value = gpSystemProcessInfoLast;
        pair._Key = (int)gpSystemProcessInfoLast->UniqueProcessId;
        _Node_1 = std::_Tree_comp_alloc<std::_Tmap_traits<unsigned long,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *>>,0>>::_Buynode<std::piecewise_construct_t const &,std::tuple<unsigned long &&>,std::tuple<>>(
                    (CSystemProcessInfoMap *)&pLocalMap,
                    &pair);
        std::_Tree<std::_Tmap_traits<unsigned long,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *>>,0>>::_Insert_hint<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *> &,std::_Tree_node<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *>,void *> *>(
          (CSystemProcessInfoMap *)&pLocalMap,
          (int)&_Where,
          0,
          (int)&_Node_1->_Keyvalue,
          _Node_1);
      }
    }
    pNodeRet = (std__Tree_node *)sub_C4E4B0(
                                   (CSystemProcessInfoMap *)&pLocalMap,
                                   *ppSystemProcessInfo,
                                   pSystemProcessorCycleTimeInfo_1,
                                   dwBufLen);
    pMapIn = pMap;
    pMap->_Header = pNodeRet;
    LocalMap._Header = (std__Tree_node *)pLocalMap;
    pLocalMapIn = pLocalMap;
    pMapIn->_Size = LocalMap._Size;
    sub_C65510(
      (std__tree *)&pLocalMap,
      (int **)&pSystemProcessorPerformanceInfo,
      (std__Tree_node *)LocalMap._Header->_Left,
      (int *)pLocalMapIn);
    operator delete(pLocalMap);
  }
  return (FILETIME)__PAIR__(v24, v8);
}
// CDF2F4: using guessed type int GetProcessorSystemCycleTime;

//----- (00C4DC80) --------------------------------------------------------
void QueryServiceNames()
{
  DWORD v0; // esi
  char cbSizeNeeded; // [esp+0h] [ebp-8h]
  int dwResumeHandle; // [esp+4h] [ebp-4h]

  if ( *(_DWORD *)EnumServicesStatusExW )
  {
    EnterCriticalSection(&gServiceLock);
    dwResumeHandle = 0;
    if ( !EnumServicesStatusExW(
            ghSCManagerHandle,
            SC_ENUM_PROCESS_INFO,
            SERVICE_WIN32,
            SERVICE_ACTIVE,
            (LPBYTE)gpszServiceNames,
            gdwServiceNamesLength,
            (LPDWORD)&cbSizeNeeded,
            &gdwServiceReturned,
            (LPDWORD)&dwResumeHandle,
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
        gpszServiceNames = (_ENUM_SERVICE_STATUS_PROCESSW *)malloc(gdwServiceNamesLength);
      }
      while ( !EnumServicesStatusExW(
                 ghSCManagerHandle,
                 0,
                 SERVICE_WIN32,
                 SERVICE_ACTIVE,
                 (LPBYTE)gpszServiceNames,
                 v0,
                 (LPDWORD)&cbSizeNeeded,
                 &gdwServiceReturned,
                 (LPDWORD)&dwResumeHandle,
                 0) );
    }
    LeaveCriticalSection(&gServiceLock);
  }
}

//----- (00C4DD60) --------------------------------------------------------
void __cdecl sub_C4DD60(char a1, unsigned int a2, int a3, unsigned int a4, int a5, int a6, int a7, unsigned int *a8)
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
    v8 = PE_QueryThreadAddress(*(HANDLE *)(a3 + 44));
    if ( !v8 )
      v8 = a5;
    LODWORD(Address) = v8;
  }
  EnterCriticalSection(&gPE_ImageItemVerifiedLock);
  GetSystemDirectoryW(&Buffer, 0x104u);
  v9 = Address;
  v10 = (wchar_t *)(a3 + 52);
  while ( 1 )
  {
    v11 = v63;
    v12 = -1;
    v73 = (unsigned int *)-1;
    *v10 = 0;
    if ( !v11 )
      goto LABEL_74;
    v70 = -1;
    v13 = *(const CHAR **)(v11 + 48);
    v14 = 0;
    lpMultiByteStr = v13;
    if ( !*(_DWORD *)v13 )
      goto LABEL_74;
    v15 = (int)(v13 + 12);
    do
    {
      if ( v9 > *(_DWORD *)v15 )
      {
        if ( v9 >= *(_DWORD *)v15 + *(_DWORD *)(v15 + 4) )
        {
          v12 = (signed int)v73;
        }
        else
        {
          v16 = *(unsigned __int16 *)(v15 + 18) + 20;
          v70 = *(_DWORD *)v15;
          swprintf(v10, L"%S", v15 + v16);
          v9 = Address;
          v12 = v14;
          v73 = (unsigned int *)v14;
        }
      }
      ++v14;
      v15 += 284;
    }
    while ( v14 < *(_DWORD *)lpMultiByteStr );
    if ( v12 == -1 )
    {
LABEL_74:
      v29 = 0;
      v70 = -1;
      if ( !*v69 )
        goto LABEL_52;
      v30 = (int)(v69 + 3);
      do
      {
        if ( v9 > *(_DWORD *)v30 )
        {
          if ( v9 >= *(_DWORD *)v30 + *(_DWORD *)(v30 + 4) )
          {
            v12 = (signed int)v73;
          }
          else
          {
            v70 = *(_DWORD *)v30;
            lpMultiByteStr = (LPCSTR)(v30 + 20);
            v31 = strrchr((const char *)(v30 + 20), 92);
            if ( v31 )
              v32 = v31 + 1;
            else
              v32 = lpMultiByteStr;
            swprintf(v10, L"%S", v32);
            v9 = Address;
            v12 = v29;
            v73 = (unsigned int *)v29;
          }
        }
        ++v29;
        v30 += 284;
      }
      while ( v29 < *v69 );
      if ( v12 == -1 )
      {
LABEL_52:
        v27 = (void *)HIDWORD(Address);
        goto LABEL_53;
      }
      v33 = 71 * v12;
      v34 = 0;
      v73 = &v69[v33];
      lpMultiByteStr = (LPCSTR)&v69[v33 + 8];
      v35 = (const wchar_t **)ATL::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>(
                                &v61,
                                lpMultiByteStr);
      v36 = _wcsnicmp(*v35, L"\\SystemRoot\\", 0xCu) == 0;
      ATL::CSimpleStringT<wchar_t,0>::~CSimpleStringT<wchar_t,0>(&v61);
      v37 = v36 == 0;
      v38 = (int)v73;
      if ( v37 )
      {
        if ( *((_BYTE *)v73 + 33) == 58 )
        {
          v40 = (const wchar_t **)sub_C24BD0(&v66, lpMultiByteStr);
          wcscpy_s(&Dst, 0x105u, *v40);
          ATL::CSimpleStringT<wchar_t,0>::~CSimpleStringT<wchar_t,0>(&v66);
        }
        else
        {
          if ( *((_BYTE *)v73 + 37) != 58 )
          {
            sub_C49D60(&Dst, L"%s\\drivers\\%s", &Buffer, v10);
            v34 = FindExecutableImageExW_0(&Dst, &Buffer, &Src, v53, v55);
            if ( v34 )
            {
              if ( !_wcsicmp(&Src, &Dst) )
                goto LABEL_46;
              CloseHandle(v34);
            }
            sub_C49D60(&Src, L"%s\\drivers\\%s", &Buffer, v10);
            v34 = FindExecutableImageExW_0(&Src, &Buffer, &Dst, v57, v58);
            goto LABEL_46;
          }
          v41 = (const wchar_t **)sub_C24BD0(&v62, (LPCSTR)v73 + 36);
          wcscpy_s(&Dst, 0x105u, *v41);
          ATL::CSimpleStringT<wchar_t,0>::~CSimpleStringT<wchar_t,0>(&v62);
        }
      }
      else
      {
        v39 = ATL::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>(
                &v59,
                (LPCSTR)v73 + 44);
        sub_C49D60(&Src, L"%%SystemRoot%%\\%s", v39->pszData);
        ATL::CSimpleStringT<wchar_t,0>::~CSimpleStringT<wchar_t,0>(&v59);
        ExpandEnvironmentStringsW(&Src, &Dst, 0x105u);
      }
LABEL_46:
      v42 = _wcsdup(&Dst);
      *(_DWORD *)(v71 + 572) = v42;
      if ( SymLoadModuleExW_1 && a1 )
      {
        v43 = *(_DWORD *)(v38 + 16);
        v44 = *(_DWORD *)(v38 + 12);
        v27 = (void *)HIDWORD(Address);
        SymLoadModuleExW_1((HANDLE)HIDWORD(Address), v34, &Dst, 0, v44, v43, (PMODLOAD_DATA)v59.pszData, Displacement);
      }
      else
      {
        v27 = (void *)HIDWORD(Address);
      }
      if ( v34 )
        CloseHandle(v34);
      goto LABEL_53;
    }
    if ( !a1 )
      goto LABEL_52;
    lpMultiByteStr += 284 * v12;
    v17 = lpMultiByteStr + 32;
    v18 = (const wchar_t **)sub_C24BD0((CString *)&v67, lpMultiByteStr + 32);
    v19 = _wcsdup(*v18);
    v20 = (volatile signed __int32 *)(v67 - 16);
    *(_DWORD *)(v71 + 572) = v19;
    if ( _InterlockedDecrement(v20 + 3) <= 0 )
      (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v20 + 4))(v20);
    if ( !SymLoadModuleExW_1 )
      goto LABEL_52;
    v21 = sub_C24BD0((CString *)&v65, v17);
    v80 = 0;
    v22 = FindExecutableImageExW_0((PCWSTR)v21->pszData, 0, &Dst, v53, v55);
    v23 = v65 - 16;
    v80 = -1;
    if ( _InterlockedDecrement((volatile signed __int32 *)(v65 - 16 + 12)) <= 0 )
      (*(void (__stdcall **)(int))(**(_DWORD **)v23 + 4))(v23);
    v24 = lpMultiByteStr;
    v25 = sub_C24BD0((CString *)&v68, lpMultiByteStr + 32)->pszData;
    v26 = *((_DWORD *)v24 + 3);
    v27 = (void *)HIDWORD(Address);
    v80 = 1;
    SymLoadModuleExW_1((HANDLE)HIDWORD(Address), v22, (PCWSTR)v25, 0, v26, 0, v54, v56);
    v28 = v68 - 16;
    v80 = -1;
    if ( _InterlockedDecrement((volatile signed __int32 *)(v68 - 16 + 12)) <= 0 )
      (*(void (__stdcall **)(int))(**(_DWORD **)v28 + 4))(v28);
    if ( v22 )
      CloseHandle(v22);
LABEL_53:
    v45 = Address;
    Symbol.SizeOfStruct = 88;
    Symbol.MaxNameLen = 469;
    if ( a1 )
    {
      if ( *(_DWORD *)SymFromAddrW && SymFromAddrW(v27, (signed int)Address, &Displacement, &Symbol) )
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
  v46 = (__int16 *)(a3 + 52);
  LOBYTE(Symbol.Name[Symbol.NameLen]) = 0;
  if ( Displacement )
  {
    do
    {
      v47 = *v46;
      ++v46;
    }
    while ( v47 );
    v48 = (signed int)((char *)v46 - a3 - 54) >> 1;
    do
    {
      v49 = *v10;
      ++v10;
    }
    while ( v49 );
    _snwprintf_s(
      (wchar_t *)(v71 + 2 * ((signed int)((char *)v10 - a3 - 54) >> 1) + 52),
      260 - v48,
      0xFFFFFFFF,
      L"!%s+0x%x",
      Symbol.Name,
      Displacement);
  }
  else
  {
    do
    {
      v50 = *v46;
      ++v46;
    }
    while ( v50 );
    v51 = (signed int)((char *)v46 - a3 - 54) >> 1;
    do
    {
      v52 = *v10;
      ++v10;
    }
    while ( v52 );
    _snwprintf_s(
      (wchar_t *)(v71 + 2 * ((signed int)((char *)v10 - a3 - 54) >> 1) + 52),
      260 - v51,
      0xFFFFFFFF,
      L"!%s",
      Symbol.Name);
  }
LABEL_71:
  LeaveCriticalSection(&gPE_ImageItemVerifiedLock);
}
// CB2BE0: using guessed type wchar_t a0xX_0[5];

//----- (00C4E420) --------------------------------------------------------
int __cdecl PE_QueryThreadAddress(HANDLE hObject)
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

//----- (00C4E4B0) --------------------------------------------------------
int __cdecl sub_C4E4B0(CSystemProcessInfoMap *theMap, SYSTEM_PROCESS_INFORMATION *pSystemProcessInfo, SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *pProcessorIdleCycleTimeInfo, unsigned int dwProcessorIdleCycleTimeInfoLen)
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
  std_Tree_node_for_tagKeyName *v32; // edx
  Data_t_bstr_t *v33; // ecx
  std__Tree_node_For__bstr_t *_Node_1; // ecx
  std__Tree_node *_Node_2; // ecx
  std_Tree_node_for_tagKeyName *_Node_3; // ecx
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

  ThisMap = (unsigned int)theMap;
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
          v12 = _mm_loadu_si128((const __m128i *)v11 - 1);
          dwIndex += 4;
          v11 += 32;
          v9 = _mm_add_epi64(v9, v12);
          v10 = _mm_add_epi64(v10, _mm_loadu_si128((const __m128i *)v11 - 2));
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
        ThisMap = __PAIR__(HIDWORD(v61), (unsigned int)v60);
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
            v16 = (__PAIR__(
                     *((_DWORD *)&ProcessorIdleCycleTime + 2 * dwIndex + 1),
                     *((_DWORD *)&ProcessorIdleCycleTime + 2 * dwIndex))
                 + __PAIR__(v16, (unsigned int)ThisMap)) >> 32;
            LODWORD(ThisMap) = *((_DWORD *)&ProcessorIdleCycleTime + 2 * dwIndex) + ThisMap;
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
          v19 = __CFADD__(*((_DWORD *)&ProcessorIdleCycleTime + 2 * dwIndex), v64);
          v64 += *((_DWORD *)&ProcessorIdleCycleTime + 2 * dwIndex);
          v63 += *((_DWORD *)&ProcessorIdleCycleTime + 2 * dwIndex + 1) + v19;
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
    if ( (_DWORD)ThisMap )
    {
      v22 = *(_DWORD *)ThisMap;
      v23 = v22;
      v24 = SystemProcessInfo->UniqueProcessId;
      v25 = *(_DWORD *)(v22 + 4);
      while ( !*(_BYTE *)(v25 + 13) )
      {
        if ( *(_DWORD *)(v25 + 16) >= (unsigned int)v24 )
        {
          v23 = v25;
          v25 = *(_DWORD *)v25;
        }
        else
        {
          v25 = *(_DWORD *)(v25 + 8);
        }
      }
      if ( v23 == v22 || (unsigned int)v24 < *(_DWORD *)(v23 + 16) )
      {
        v56 = v22;
        v26 = &v56;
      }
      else
      {
        v55 = v23;
        v26 = &v55;
      }
      v27 = (_DWORD *)*v26;
      if ( v27 != (_DWORD *)v22 )
      {
        v28 = v27[5];
        if ( *(_DWORD *)(v28 + 32) == SystemProcessInfo->CreateTime.LowPart )
        {
          LODWORD(ThisMap) = theMap_1;
          if ( *(_DWORD *)(v28 + 36) != SystemProcessInfo->CreateTime.HighPart )
          {
LABEL_35:
            v6 = v64;
            HIDWORD(ThisMap) = v63;
            goto LABEL_36;
          }
          sub_C655B0((std__Tree_node *)theMap_1, &a2[1], v27);
          dwNumberOfProcessors = gSystemInfo.dwNumberOfProcessors;
        }
      }
      LODWORD(ThisMap) = theMap_1;
      goto LABEL_35;
    }
LABEL_36:
    if ( !SystemProcessInfo->NextEntryOffset )
      break;
    SystemProcessInfo = (SYSTEM_PROCESS_INFORMATION *)((char *)SystemProcessInfo + SystemProcessInfo->NextEntryOffset);
  }
  theMap_2 = theMap_1;
  if ( theMap_1 )
  {
    _Node = (std__Tree_node *)theMap_1->_Header->_Left;
    if ( _Node != theMap_1->_Header )
    {
      v31 = (_DWORD *)dwProcessorIdleCycleTimeInfoLength;
      do
      {
        v32 = _Node[1]._Parent;
        v33 = v32->_Myval.second.bstrText2.m_Data;
        v19 = __CFADD__(v33, *v31);
        *v31 += v33;
        v31[1] += v32->_Myval.second.dwValue + v19;
        if ( !_Node->_IsNil )
        {
          _Node_1 = _Node->_Right;
          if ( _Node_1->_IsNil )
          {
            for ( _Node_3 = _Node->_Parent; !_Node_3->_IsNil; _Node_3 = _Node_3->_Parent )
            {
              if ( _Node != (std__Tree_node *)_Node_3->_Right )
                break;
              _Node = (std__Tree_node *)_Node_3;
            }
            _Node = (std__Tree_node *)_Node_3;
          }
          else
          {
            _Node = (std__Tree_node *)_Node->_Right;
            for ( _Node_2 = (std__Tree_node *)_Node_1->_Left; !_Node_2->_IsNil; _Node_2 = (std__Tree_node *)_Node_2->_Left )
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
      *(SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *)v41.m128i_i8 = pProcessorIdleCycleTimeInfo2[-2];
      pProcessorIdleCycleTimeInfo2 += 4;
      v41.m128i_i64[1] = pProcessorIdleCycleTimeInfo2[-5].CycleTime;
      dwIndex_1 += 4;
      v38 = _mm_add_epi64(v38, v41);
      *(SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *)v41.m128i_i8 = pProcessorIdleCycleTimeInfo2[-4];
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
  *(_QWORD *)a2 = 0i64;
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
        v49 = pProcessorIdleCycleTimeInfo[dwIndex_1].CycleTime + __PAIR__(v48, (unsigned int)v45);
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

//----- (00C4E920) --------------------------------------------------------
signed int sub_C4E920()
{
  HANDLE v0; // edi
  SYSTEM_HANDLE_INFORMATION *v1; // eax
  ULONG v2; // esi
  int v3; // esi
  signed int result; // eax
  SYSTEM_HANDLE_INFORMATION *v5; // eax
  ULONG v6; // esi
  int v7; // esi
  _SYSTEM_HANDLE_TABLE_ENTRY_INFO_EX *pEntry; // [esp+4h] [ebp-808h]
  wchar_t Dst; // [esp+8h] [ebp-804h]

  if ( *(_DWORD *)CreateJobObjectW )
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
          GetHandleTableEntry(v1, v3, (SYSTEM_HANDLE_TABLE_ENTRY_INFO **)&pEntry);
          if ( pEntry->UniqueProcessId == GetCurrentProcessId() && (HANDLE)pEntry->HandleValue == v0 )
            break;
          if ( --v3 < 0 )
            goto LABEL_12;
          v1 = gpSystemHandleInfo2;
        }
        Dst = 0;
        PE_QueryObject(&gpszObjectTypeNames[0x40 * pEntry->ObjectTypeIndex], pEntry, &Dst, 0x400u, 0);
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
        GetHandleTableEntry(v5, v7, (SYSTEM_HANDLE_TABLE_ENTRY_INFO **)&pEntry);
        if ( !gpszObjectTypeNames[64 * pEntry->ObjectTypeIndex] )
        {
          Dst = 0;
          PE_QueryObject(&gpszObjectTypeNames[64 * pEntry->ObjectTypeIndex], pEntry, &Dst, 0x400u, 0);
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

//----- (00C4EAA0) --------------------------------------------------------
LPVOID __cdecl PE_QueryFileVersionBlock(LPCVOID pBlock, LPCWSTR lpszBlockName)
{
  LPVOID result; // eax
  unsigned int puLen; // [esp+8h] [ebp-Ch]
  __int16 v4; // [esp+Ch] [ebp-8h]
  DWORD *lpBuffer; // [esp+10h] [ebp-4h]

  v4 = 1024;
  lpBuffer = (DWORD *)&v4;
  VerQueryValueW(pBlock, L"\\VarFileInfo\\Translation", (LPVOID *)&lpBuffer, &puLen);
  result = PE_QueryVersionInfo(pBlock, *(unsigned __int16 *)lpBuffer, *((_WORD *)lpBuffer + 1), lpszBlockName);
  if ( !result )
  {
    result = PE_QueryVersionInfo(pBlock, *(unsigned __int16 *)lpBuffer, 1252u, lpszBlockName);
    if ( !result )
      result = PE_QueryVersionInfo(pBlock, 1033, 1252u, lpszBlockName);
  }
  return result;
}

//----- (00C4EB20) --------------------------------------------------------
DWORD __cdecl PE_QueryProcessWorkset(void *hProcess, _PSAPI_WORKING_SET_INFORMATION **ppBuffer, DWORD *pdwLength, _DWORD *a4, _DWORD *a5, _DWORD *a6, DWORD *a7)
{
  DWORD result; // eax
  ULONG_PTR dwIndex; // ecx
  PSAPI_WORKING_SET_BLOCK *dwFlags; // eax

  *a4 = 0;
  *a5 = 0;
  *a6 = 0;
  *a7 = 0;
  while ( 1 )
  {
    if ( QueryWorkingSet(hProcess, *ppBuffer, *pdwLength) )
    {
      if ( !*ppBuffer )
        goto LABEL_7;
      if ( *pdwLength >= 4 * (*ppBuffer)->NumberOfEntries )
        break;
    }
    if ( *ppBuffer )
      free(*ppBuffer);
LABEL_7:
    result = GetLastError();
    if ( result != ERROR_BAD_LENGTH )
    {
      *ppBuffer = 0;
      *pdwLength = 0;
      return result;
    }
    *pdwLength += 0x4000;
    *ppBuffer = (_PSAPI_WORKING_SET_INFORMATION *)malloc(*pdwLength);
  }
  dwIndex = 0;
  if ( (*ppBuffer)->NumberOfEntries )
  {
    do
    {
      dwFlags = (PSAPI_WORKING_SET_BLOCK *)(*ppBuffer)->WorkingSetInfo[dwIndex].Flags;
      ++*a4;
      if ( (unsigned __int16)dwFlags & 0x100 )
      {
        ++*a6;
        if ( ((unsigned __int8)dwFlags & 0xE0u) > 0x20 )
          ++*a7;
      }
      else
      {
        ++*a5;
      }
      ++dwIndex;
    }
    while ( dwIndex < (*ppBuffer)->NumberOfEntries );
  }
  *a4 *= gSystemInfo.dwPageSize;
  *a5 *= gSystemInfo.dwPageSize;
  *a6 *= gSystemInfo.dwPageSize;
  result = gSystemInfo.dwPageSize * *a7;
  *a7 = result;
  return result;
}

//----- (00C4EC30) --------------------------------------------------------
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
      return PE_FillControl((int)hDlg, (HDC)wParam);
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
      if ( (unsigned __int16)wParam == 1 )
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
              v37 = (1 << v38) | (unsigned int)hMenu;
              hMenu = (HMENU)((1 << v38) | (unsigned int)hMenu);
            }
            else
            {
              v37 = (DWORD)hMenu;
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
      else if ( (unsigned __int16)wParam == 2 )
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
      *(_DWORD *)(lParam + 8) = 2 * gdwVirtualScreenWidth;
    }
    return 0;
  }
  v11 = LoadIconW(ghInstance, (LPCWSTR)0x65);
  SendMessageW(hDlg, 0x80u, 0, (LPARAM)v11);
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
  MapWindowPoints(0, hDlg, (LPPOINT)&v65, 2u);
  if ( !dword_CEBA1C )
  {
    v18 = InitGraphData(gdwAdapterRuntingTime, 1, 0);
    v19 = 0;
    dword_CEBA1C = (int)v18;
    if ( gdwAdapterRuntingTime > 0 )
    {
      v20 = 0;
      while ( 1 )
      {
        v18[v20 / 0x898].m_ProcessorID = v19;
        *(_DWORD *)(v20 + dword_CEBA1C + 28) = 1;
        *(_DWORD *)(v20 + dword_CEBA1C + 32) = 4;
        *(_DWORD *)(v20 + dword_CEBA1C + 48) = 8421631;
        *(double *)(v20 + dword_CEBA1C + 40) = db_onehundred;
        *(_DWORD *)(v20 + dword_CEBA1C + 2172) = gpGraphInfoOfGPU;
        if ( v19 )
        {
          v21 = dword_CEBA1C;
          *(_DWORD *)(v20 + dword_CEBA1C + 2148) = *(_DWORD *)(dword_CEBA1C + 2148);
          *(_DWORD *)(v20 + dword_CEBA1C + 2152) = *(_DWORD *)(v21 + 2152);
        }
        ++v19;
        v20 += 2200;
        if ( v19 >= gdwAdapterRuntingTime )
          break;
        v18 = (CGraphData *)dword_CEBA1C;
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
    hMenu = (HMENU)2503;
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
        (HMENU)((char *)hMenu - 1),
        ghInstance,
        0);
      CreateGraphWindow(hDlg, (int)hMenu - 1, (PVOID)(v63 + dword_CEBA1C));
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
      sub_C113E0(&String, L"Engine %d", ArgLista);
      SetWindowTextW(v26, &String);
      SendMessageW(v26, 0x30u, wParama, 1);
      EnableWindow(v26, 1);
      ShowWindow(v26, 5);
      if ( (1 << ArgLista) & gConfig.dwGpuNodeUsageMask )
        CheckDlgButton(hDlg, (int)hMenu, 1u);
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
      hMenu = (HMENU)((char *)hMenu + 2);
    }
    while ( Point.y < gdwAdapterRuntingTime );
    v13 = v56;
  }
  v27 = (CResizer *)operator new(0x40u);
  v28 = v27;
  Point.y = (LONG)v27;
  v68 = 0;
  if ( v27 )
  {
    v27->baseclass.m_hThemeHandle = 0;
    LOBYTE(v68) = 1;
    v27->baseclass.vtptr = (CThemedWindowVTable *)&CResizer::`vftable';
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
  *(double *)&Point = 0.0;
  *(_QWORD *)&Rect.right = 0i64;
  v63 = 0;
  if ( gdwAdapterRuntingTime > 0 )
  {
    v29 = (char *)2502;
    hMenu = (HMENU)2502;
    v47 = 1.0 / (double)v13;
    v49 = 1.0 / (double)v58;
    do
    {
      v30 = GetDlgItem(hDlg, (int)v29);
      v59 = v49 + *(double *)&Rect.right;
      v53 = v49 + *(double *)&Rect.right;
      if ( v49 + *(double *)&Rect.right >= 0.99999 )
        v53 = db_one;
      v31 = CResizer::AddItem(v28, v30, 1);
      v32 = hMenu;
      *(_QWORD *)&v31->gap0[16] = *(_QWORD *)&Rect.right;
      *(double *)&v31->gap0[24] = v53;
      v33 = GetDlgItem(hDlg, (int)v32);
      v34 = v47 + *(double *)&Point;
      v51 = v47 + *(double *)&Point;
      v54 = v47 + *(double *)&Point;
      if ( v47 + *(double *)&Point >= 0.99999 )
        v54 = db_one;
      if ( v33 )
      {
        v35 = (double *)CResizer::AddItem(v28, v33, 1);
        *v35 = *(double *)&Point;
        v35[1] = v54;
        v34 = v51;
      }
      *(double *)&Point = v34;
      if ( !(++v63 % v13) )
      {
        *(double *)&Point = 0.0;
        *(double *)&Rect.right = v59;
      }
      v29 = (char *)hMenu + 2;
      hMenu = (HMENU)((char *)hMenu + 2);
    }
    while ( v63 < gdwAdapterRuntingTime );
  }
  SendMessageW(hDlg, 0x464u, 0, 0);
  SetTimer(hDlg, 0, 0x3E8u, 0);
  return 1;
}
// CAC888: using guessed type void *CResizer::`vftable';
// CACDC0: using guessed type double db_onehundred;
// CD4E28: using guessed type int gdwVirtualScreenWidth;
// CEBA1C: using guessed type int dword_CEBA1C;

//----- (00C4F3E0) --------------------------------------------------------
signed int __cdecl PE_QueryProcessKernelSecurity(SERVERINFO *ThreadId, int SecurityInformation, PSECURITY_DESCRIPTOR *pSecurityDescriptor)
{
  void *v3; // esi
  signed int result; // eax
  int v5; // [esp+4h] [ebp-10h]
  int v6; // [esp+8h] [ebp-Ch]
  PSECURITY_DESCRIPTOR *v7; // [esp+Ch] [ebp-8h]
  int v8; // [esp+10h] [ebp-4h]

  v5 = (int)ThreadId;
  v6 = SecurityInformation;
  v7 = pSecurityDescriptor;
  v3 = (void *)_beginthreadex(0, 0, (int)BackendQueryProcessKernelObjectSecurity, (int)&v5, 0, (LPDWORD)&ThreadId);
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

//----- (00C4F460) --------------------------------------------------------
char __cdecl PE_QueryObjectInfo(int pObjectInfo)
{
  SYSTEM_HANDLE_TABLE_ENTRY_INFO_EX *v1; // ecx
  SYSTEM_HANDLE_INFORMATION *v2; // eax
  unsigned int i; // esi
  SYSTEM_HANDLE_TABLE_ENTRY_INFO_EX *pEntry; // [esp+0h] [ebp-4h]

  pEntry = v1;
  v2 = gpSystemHandleInfo2;
  if ( !gpSystemHandleInfo2 )
    return 0;
  for ( i = 0; v2 && i < v2->NumberOfHandles; ++i )
  {
    GetHandleTableEntry(v2, i, (SYSTEM_HANDLE_TABLE_ENTRY_INFO **)&pEntry);
    if ( pEntry->UniqueProcessId == *(_DWORD *)(pObjectInfo + 0x24)
      && pEntry->HandleValue == *(_DWORD *)(pObjectInfo + 0x2C)
      && pEntry->Object == *(PVOID *)(pObjectInfo + 0x28) )
    {
      return 1;
    }
    v2 = gpSystemHandleInfo2;
  }
  return 0;
}

//----- (00C4F4D0) --------------------------------------------------------
int __cdecl PE_SetServiceObjectSecurity(SERVERINFO *a1, SECURITY_INFORMATION SecurityInformation, PSECURITY_DESCRIPTOR SecurityDescriptor, PSECURITY_DESCRIPTOR pSecurityDescriptor, int a5)
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
  v7 = (void *)PE_DuplicateProcessHandle(a1->field_24, (HANDLE)a1->hService, v6);
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
    *(_BYTE *)a5 = v12;
  }
  CloseHandle(v8);
  if ( !a5 )
    return 0;
  if ( *(_BYTE *)a5 )
    v10 = 0;
  return v10;
}

//----- (00C4F580) --------------------------------------------------------
int __stdcall Fake_GetProcessDEPPolicy(HANDLE hProcess, LPDWORD lpFlags, PBOOL lpPermanent)
{
  int (__stdcall *v3)(HANDLE, LPDWORD, PBOOL); // eax
  HMODULE v4; // eax

  v3 = GetProcessDEPPolicy;
  if ( GetProcessDEPPolicy )
    return v3(hProcess, lpFlags, lpPermanent);
  v4 = GetModuleHandleW(L"KERNEL32.DLL");
  v3 = (int (__stdcall *)(HANDLE, LPDWORD, PBOOL))GetProcAddress(v4, "GetProcessDEPPolicy");
  GetProcessDEPPolicy = v3;
  if ( v3 )
    return v3(hProcess, lpFlags, lpPermanent);
  SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
  return 0;
}

//----- (00C4F5C0) --------------------------------------------------------
int __stdcall Fske_GetProcessMitigationPolicy(int a1, int a2, int a3, int a4)
{
  int (__stdcall *v4)(int, int, int, int); // eax
  HMODULE v5; // eax

  v4 = (int (__stdcall *)(int, int, int, int))GetProcessMitigationPolicy;
  if ( GetProcessMitigationPolicy )
    return v4(a1, a2, a3, a4);
  v5 = GetModuleHandleW(L"KERNEL32.DLL");
  v4 = (int (__stdcall *)(int, int, int, int))GetProcAddress(v5, "GetProcessMitigationPolicy");
  GetProcessMitigationPolicy = (int (__stdcall *)(HANDLE, _PROCESS_MITIGATION_POLICY, PVOID, SIZE_T))v4;
  if ( v4 )
    return v4(a1, a2, a3, a4);
  SetLastError(0x78u);
  return 0;
}

//----- (00C4F600) --------------------------------------------------------
int __cdecl sub_C4F600(int a1, int a2, int a3, int a4)
{
  int result; // eax
  int v5; // ecx

  result = a1;
  if ( a1 )
  {
    while ( 1 )
    {
      if ( *(_DWORD *)(result + 40) == a2 && *(_DWORD *)(result + 584) == a4 )
      {
        v5 = *(_DWORD *)(result + 44);
        if ( v5 == a3 || v5 == 0x100007F && !a3 )
          break;
        if ( !v5 && a3 == 0x100007F )
          break;
      }
      result = *(_DWORD *)(result + 2188);
      if ( !result )
        goto LABEL_10;
    }
    LOBYTE(result) = 1;
  }
  else
  {
LABEL_10:
    LOBYTE(result) = 0;
  }
  return result;
}

//----- (00C4F660) --------------------------------------------------------
int __thiscall sub_C4F660(CString *this, HMODULE hModule, int uID)
{
  CString *v3; // edi
  HRSRC hRsrc; // eax
  unsigned __int16 *v5; // eax
  unsigned __int16 *v6; // ebx
  int v7; // eax
  int v8; // esi
  int result; // eax

  v3 = this;
  hRsrc = FindResourceW(hModule, (LPCWSTR)(unsigned __int16)(((unsigned int)uID >> 4) + 1), (LPCWSTR)RT_STRING);
  if ( !hRsrc )
    return 0;
  v5 = (unsigned __int16 *)ATL::AtlGetStringResourceImage(hModule, hRsrc, uID);
  v6 = v5;
  if ( !v5 )
    return 0;
  v7 = WideCharToMultiByte(3u, 0, v5 + 1, *v5, 0, 0, 0, 0);
  v8 = v7;
  if ( v7 < 0 )
    goto LABEL_12;
  if ( ((*((_DWORD *)v3->pszData - 2) - v7) | (1 - *((_DWORD *)v3->pszData - 1))) < 0 )
    sub_C52330(v3, v7);
  WideCharToMultiByte(3u, 0, v6 + 1, *v6, v3->pszData, v8, 0, 0);
  if ( v8 > *((_DWORD *)v3->pszData - 2) )
LABEL_12:
    ATL::AtlThrowImpl(E_INVALIDARG);
  *((_DWORD *)v3->pszData - 3) = v8;
  result = 1;
  v3->pszData[v8] = 0;
  return result;
}

//----- (00C4F720) --------------------------------------------------------
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
  NtQuerySystemInformation = (int (__stdcall *)(_SYSTEM_INFORMATION_CLASS, PVOID, ULONG, PULONG))GetProcAddress(
                                                                                                   v0,
                                                                                                   "NtQuerySystemInformation");
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
  gpfn_NtQuerySymbolicLinkObject = (int (__stdcall *)(HANDLE, PUNICODE_STRING, PULONG))GetProcAddress(
                                                                                         v2,
                                                                                         "NtQuerySymbolicLinkObject");
  if ( !gpfn_NtQuerySymbolicLinkObject )
  {
    swprintf(
      &Text,
      L"Not able to run on this version of Windows:\nMissing function: %s",
      L"Ntdll!NtQuerySymbolicLinkObject");
    goto LABEL_3;
  }
  v3 = GetModuleHandleW(L"ntdll.dll");
  NtQueryDirectoryObject = (int)GetProcAddress(v3, "NtQueryDirectoryObject");
  if ( !NtQueryDirectoryObject )
  {
    swprintf(
      &Text,
      L"Not able to run on this version of Windows:\nMissing function: %s",
      L"Ntdll!NtQueryDirectoryObject");
    goto LABEL_3;
  }
  v4 = GetModuleHandleW(L"ntdll.dll");
  gpfn_NtOpenSymbolicLinkObject = (int (__stdcall *)(PHANDLE, ACCESS_MASK, POBJECT_ATTRIBUTES))GetProcAddress(
                                                                                                 v4,
                                                                                                 "NtOpenSymbolicLinkObject");
  if ( !gpfn_NtOpenSymbolicLinkObject )
    return ReportMsg((int)L"Ntdll!NtOpenSymbolicLinkObject");
  v5 = GetModuleHandleW(L"ntdll.dll");
  NtOpenDirectoryObject = (int (__stdcall *)(HANDLE, PVOID, ULONG, BOOLEAN, BOOLEAN, PULONG, PULONG))GetProcAddress(v5, "NtOpenDirectoryObject");
  if ( !NtOpenDirectoryObject )
    return ReportMsg((int)L"Ntdll!NtOpenDirectoryObject");
  v6 = GetModuleHandleW(L"ntdll.dll");
  NtQueryObject = (int (__stdcall *)(HANDLE, OBJECT_INFORMATION_CLASS, PVOID, ULONG, PULONG))GetProcAddress(
                                                                                               v6,
                                                                                               "NtQueryObject");
  if ( !NtQueryObject )
    return ReportMsg((int)L"Ntdll!NtQueryObject");
  v7 = GetModuleHandleW(L"ntdll.dll");
  NtQueryInformationProcess = (int (__stdcall *)(HANDLE, PROCESSINFOCLASS, PVOID, ULONG, PULONG))GetProcAddress(
                                                                                                   v7,
                                                                                                   "NtQueryInformationProcess");
  if ( !NtQueryInformationProcess )
    return ReportMsg((int)L"Ntdll!NtQueryInformationProcess");
  v8 = GetModuleHandleW(L"ntdll.dll");
  NtSetInformationProcess = (int (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))GetProcAddress(
                                                                                         v8,
                                                                                         "NtSetInformationProcess");
  if ( !NtSetInformationProcess )
    return ReportMsg((int)L"Ntdll!NtSetInformationProcess");
  v9 = GetModuleHandleW(L"ntdll.dll");
  NtSetInformationProcess_0 = (int (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))GetProcAddress(
                                                                                           v9,
                                                                                           "NtQuerySemaphore");
  if ( !NtSetInformationProcess_0 )
    return ReportMsg((int)L"Ntdll!NtQuerySemaphore");
  v10 = GetModuleHandleW(L"ntdll.dll");
  gpfn_NtOpenSymbolicLinkObject = (int (__stdcall *)(PHANDLE, ACCESS_MASK, POBJECT_ATTRIBUTES))GetProcAddress(
                                                                                                 v10,
                                                                                                 "NtOpenSymbolicLinkObject");
  if ( !gpfn_NtOpenSymbolicLinkObject )
    return ReportMsg((int)L"Ntdll!NtOpenSymbolicLinkObject");
  v11 = GetModuleHandleW(L"ntdll.dll");
  NtQuerySection = (int (__stdcall *)(HANDLE, SECTION_INFORMATION_CLASS, PVOID, ULONG, PULONG))GetProcAddress(
                                                                                                 v11,
                                                                                                 "NtQuerySection");
  if ( !NtQuerySection )
    return ReportMsg((int)L"Ntdll!NtQuerySection");
  v12 = GetModuleHandleW(L"ntdll.dll");
  NtQueryEvent = (int (__stdcall *)(HANDLE, EVENT_INFORMATION_CLASS, PVOID, ULONG, PULONG))GetProcAddress(
                                                                                             v12,
                                                                                             "NtQueryEvent");
  if ( !NtQueryEvent )
    return ReportMsg((int)L"Ntdll!NtQueryEvent");
  v13 = GetModuleHandleW(L"ntdll.dll");
  NtQueryMutant = (int (__stdcall *)(HANDLE, MUTANT_INFORMATION_CLASS, PVOID, ULONG, PULONG))GetProcAddress(
                                                                                               v13,
                                                                                               "NtQueryMutant");
  if ( !NtQueryMutant )
    return ReportMsg((int)L"Ntdll!NtQueryMutant");
  v14 = GetModuleHandleW(L"ntdll.dll");
  NtResumeThread = (int (__thiscall *)(HANDLE, PULONG))GetProcAddress(v14, "NtResumeThread");
  if ( !NtResumeThread )
    return ReportMsg((int)L"Ntdll!NtResumeThread");
  v15 = GetModuleHandleW(L"ntdll.dll");
  NtSuspendThread = (int (__thiscall *)(HANDLE, PULONG))GetProcAddress(v15, "NtSuspendThread");
  if ( !NtSuspendThread )
    return ReportMsg((int)L"Ntdll!NtSuspendThread");
  v16 = GetModuleHandleW(L"ntdll.dll");
  NtOpenThread = (int (__stdcall *)(PHANDLE, ACCESS_MASK, POBJECT_ATTRIBUTES, PCLIENT_ID))GetProcAddress(
                                                                                            v16,
                                                                                            "NtOpenThread");
  if ( !NtOpenThread )
    return ReportMsg((int)L"Ntdll!NtOpenThread");
  v17 = GetModuleHandleW(L"ntdll.dll");
  NtQueryInformationThread = (int (__stdcall *)(HANDLE, THREADINFOCLASS, PVOID, ULONG, PULONG))GetProcAddress(
                                                                                                 v17,
                                                                                                 "NtQueryInformationThread");
  if ( !NtQueryInformationThread )
    return ReportMsg((int)L"Ntdll!NtQueryInformationThread");
  v18 = GetModuleHandleW(L"ntdll.dll");
  NtQueryVirtualMemory = (int (__stdcall *)(HANDLE, PVOID, MEMORY_INFORMATION_CLASS, PVOID, SIZE_T, PSIZE_T))GetProcAddress(v18, "NtQueryVirtualMemory");
  if ( !NtQueryVirtualMemory )
    return ReportMsg((int)L"Ntdll!NtQueryVirtualMemory");
  v19 = GetModuleHandleW(L"ntdll.dll");
  RtlCreateQueryDebugBuffer = (PRTL_DEBUG_BUFFER (__stdcall *)(ULONG, BOOLEAN))GetProcAddress(
                                                                                 v19,
                                                                                 "RtlCreateQueryDebugBuffer");
  if ( !RtlCreateQueryDebugBuffer )
    return ReportMsg((int)L"Ntdll!RtlCreateQueryDebugBuffer");
  v20 = GetModuleHandleW(L"ntdll.dll");
  RtlQueryProcessDebugInformation = (int (__stdcall *)(_DWORD, _DWORD, _DWORD))GetProcAddress(
                                                                                 v20,
                                                                                 "RtlQueryProcessDebugInformation");
  if ( !RtlQueryProcessDebugInformation )
    return ReportMsg((int)L"Ntdll!RtlQueryProcessDebugInformation");
  v21 = GetModuleHandleW(L"ntdll.dll");
  RtlDestroyQueryDebugBuffer = (int (__stdcall *)(_DWORD))GetProcAddress(v21, "RtlDestroyQueryDebugBuffer");
  if ( !RtlDestroyQueryDebugBuffer )
    return ReportMsg((int)L"Ntdll!RtlDestroyQueryDebugBuffer");
  v22 = GetModuleHandleW(L"ntdll.dll");
  RtlTimeToTimeFields = (int)GetProcAddress(v22, "RtlTimeToTimeFields");
  if ( !RtlTimeToTimeFields )
    return ReportMsg((int)L"Ntdll!RtlTimeToTimeFields");
  v23 = LoadLibraryW(L"aclui.dll");
  *(_DWORD *)CreateSecurityPage = GetProcAddress(v23, "CreateSecurityPage");
  if ( *(_DWORD *)CreateSecurityPage )
    goto LABEL_70;
  v24 = LoadLibraryW(L"acledit.dll");
  SedDiscretionaryAclEditor = (int (__stdcall *)(HWND, HINSTANCE, PWCHAR, PACLDLGCONTROL, PACLEDITCONTROL, PWCHAR, FARPROC, PVOID, PSECURITY_DESCRIPTOR, BOOLEAN, BOOLEAN, PDWORD, PVOID))GetProcAddress(v24, "SedDiscretionaryAclEditor");
  if ( !SedDiscretionaryAclEditor )
    return ReportMsg((int)L"Acledit!SedDiscretionaryAclEditor");
  v25 = GetModuleHandleW(L"acledit.dll");
  SedSystemAclEditor = (int (__stdcall *)(HWND, HINSTANCE, PWCHAR, PACLDLGCONTROL, PACLEDITCONTROL, PWCHAR, FARPROC, PVOID, PSECURITY_DESCRIPTOR, BOOLEAN, PDWORD, PVOID))GetProcAddress(v25, "SedSystemAclEditor");
  if ( !SedSystemAclEditor )
    return ReportMsg((int)L"Acledit!SedSystemAclEditor");
  v26 = GetModuleHandleW(L"acledit.dll");
  SedTakeOwnership = (int (__stdcall *)(HWND, HINSTANCE, PWCHAR, PWCHAR, PWCHAR, DWORD, FARPROC, PVOID, PSECURITY_DESCRIPTOR, BOOLEAN, BOOLEAN, PDWORD, PACLHELPCONTROL, PVOID))GetProcAddress(v26, "SedTakeOwnership");
  if ( !SedTakeOwnership )
    return ReportMsg((int)L"Acledit!SedTakeOwnership");
LABEL_70:
  v27 = LoadLibraryW(L"shcore.dll");
  GetProcessDpiAwareness = (int (__stdcall *)(_DWORD, _DWORD))GetProcAddress(v27, "GetProcessDpiAwareness");
  v28 = LoadLibraryW(L"iphlpapi.dll");
  *(_DWORD *)GetTcpTable = GetProcAddress(v28, "GetTcpTable");
  v29 = LoadLibraryW(L"iphlpapi.dll");
  *(_DWORD *)GetUdpTable = GetProcAddress(v29, "GetUdpTable");
  v30 = LoadLibraryW(L"iphlpapi.dll");
  AllocateAndGetTcpExTableFromStack = (int (__stdcall *)(PVOID *, BOOL, HANDLE, DWORD, DWORD))GetProcAddress(
                                                                                                v30,
                                                                                                "AllocateAndGetTcpExTableFromStack");
  v31 = LoadLibraryW(L"iphlpapi.dll");
  AllocateAndGetUdpExTableFromStack = (int (__stdcall *)(PVOID *, BOOL, HANDLE, DWORD, DWORD))GetProcAddress(
                                                                                                v31,
                                                                                                "AllocateAndGetUdpExTableFromStack");
  v32 = LoadLibraryW(L"iphlpapi.dll");
  *(_DWORD *)GetExtendedTcpTable = GetProcAddress(v32, "GetExtendedTcpTable");
  v33 = LoadLibraryW(L"iphlpapi.dll");
  *(_DWORD *)GetExtendedUdpTable = GetProcAddress(v33, "GetExtendedUdpTable");
  v34 = LoadLibraryW(L"iphlpapi.dll");
  AllocateAndGetTcpExTable2FromStack = (int (__stdcall *)(PVOID *, BOOL, HANDLE, DWORD, DWORD, TCP_TABLE_CLASS))GetProcAddress(v34, "AllocateAndGetTcpExTable2FromStack");
  v35 = LoadLibraryW(L"iphlpapi.dll");
  AllocateAndGetUdpExTable2FromStack = (int (__stdcall *)(PVOID *, BOOL, HANDLE, DWORD, DWORD, UDP_TABLE_CLASS))GetProcAddress(v35, "AllocateAndGetUdpExTable2FromStack");
  v36 = LoadLibraryW(L"user32.dll");
  *(_DWORD *)GetGuiResources = GetProcAddress(v36, "GetGuiResources");
  v37 = LoadLibraryW(L"psapi.dll");
  *(_DWORD *)QueryWorkingSet = GetProcAddress(v37, "QueryWorkingSet");
  v38 = LoadLibraryW(L"psapi.dll");
  *(_DWORD *)GetMappedFileNameW = GetProcAddress(v38, "GetMappedFileNameW");
  v39 = LoadLibraryW(L"psapi.dll");
  *(_DWORD *)EnumProcessModulesEx = GetProcAddress(v39, "EnumProcessModulesEx");
  v40 = LoadLibraryW(L"kernel32.dll");
  GlobalMemoryStatusEx = (int (__stdcall *)(_DWORD))GetProcAddress(v40, "GlobalMemoryStatusEx");
  v41 = LoadLibraryW(L"user32.dll");
  IsHungAppWindow = (int (__stdcall *)(HWND))GetProcAddress(v41, "IsHungAppWindow");
  v42 = LoadLibraryW(L"user32.dll");
  HungWindowFromGhostWindow = (int (__stdcall *)(HWND))GetProcAddress(v42, "HungWindowFromGhostWindow");
  v43 = LoadLibraryW(L"kernel32.dll");
  *(_DWORD *)GetLogicalProcessorInformation = GetProcAddress(v43, "GetLogicalProcessorInformation");
  v44 = LoadLibraryW(L"kernel32.dll");
  GetLogicalProcessorInformationEx = (int (__stdcall *)(LOGICAL_PROCESSOR_RELATIONSHIP, PSYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX, PDWORD))GetProcAddress(v44, "GetLogicalProcessorInformationEx");
  v45 = LoadLibraryW(L"kernel32.dll");
  SetThreadGroupAffinity = (int)GetProcAddress(v45, "SetThreadGroupAffinity");
  v46 = LoadLibraryW(L"wtsapi32.dll");
  WTSEnumerateSessionsW = (int (__stdcall *)(HANDLE, DWORD, DWORD, PWTS_SESSION_INFOW *, DWORD *))GetProcAddress(
                                                                                                    v46,
                                                                                                    "WTSEnumerateSessionsW");
  v47 = LoadLibraryW(L"wtsapi32.dll");
  WTSDisconnectSession = (int (__stdcall *)(HANDLE, DWORD, BOOL))GetProcAddress(v47, "WTSDisconnectSession");
  v48 = LoadLibraryW(L"winsta.dll");
  WinStationConnectW = (int (__stdcall *)(HANDLE, ULONG, ULONG, LPCWSTR, BOOL))GetProcAddress(v48, "WinStationConnectW");
  v49 = LoadLibraryW(L"winsta.dll");
  WinStationShadow = (int (__stdcall *)(HANDLE, LPCWSTR, ULONG, UCHAR, USHORT))GetProcAddress(v49, "WinStationShadow");
  v50 = LoadLibraryW(L"wtsapi32.dll");
  WTSLogoffSession = (int (__stdcall *)(HANDLE, DWORD, BOOL))GetProcAddress(v50, "WTSLogoffSession");
  v51 = LoadLibraryW(L"wtsapi32.dll");
  WTSSendMessageW = (int (__stdcall *)(HANDLE, DWORD, LPWSTR, DWORD, LPWSTR, DWORD, DWORD, DWORD, PDWORD, BOOL))GetProcAddress(v51, "WTSSendMessageW");
  v52 = LoadLibraryW(L"wtsapi32.dll");
  WTSFreeMemory = (int (__stdcall *)(PWTS_SESSION_INFOW))GetProcAddress(v52, "WTSFreeMemory");
  v53 = LoadLibraryW(L"wtsapi32.dll");
  WTSQuerySessionInformationW = (int (__stdcall *)(HANDLE, DWORD, WTS_INFO_CLASS, LPWSTR *, DWORD *))GetProcAddress(v53, "WTSQuerySessionInformationW");
  v54 = LoadLibraryW(L"kernel32.dll");
  *(_DWORD *)WTSGetActiveConsoleSessionId = GetProcAddress(v54, "WTSGetActiveConsoleSessionId");
  v55 = LoadLibraryW(L"user32.dll");
  *(_DWORD *)SetMenuInfo = GetProcAddress(v55, "SetMenuInfo");
  v56 = LoadLibraryW(L"user32.dll");
  *(_DWORD *)GetMenuInfo = GetProcAddress(v56, "GetMenuInfo");
  hModule_1 = LoadLibraryW(gConfig.strDbgHelpModuleName);
  hModule = hModule_1;
  if ( !hModule_1 )
  {
    if ( RegOpenKeyW(HKEY_CURRENT_USER, L"Software\\Microsoft\\DebuggingTools", &hKey) )
      goto __directLoad;
    cbLength = 520;
    RegQueryValueExW(hKey, L"Windbg", 0, 0, (LPBYTE)gConfig.strDbgHelpModuleName, &cbLength);
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
  if ( !*(_DWORD *)ImageNtHeader )
  {
    v58 = LoadLibraryW(L"imagehlp.dll");
    *(_DWORD *)ImageNtHeader = GetProcAddress(v58, "ImageNtHeader");
  }
  *(_DWORD *)FindExecutableImageExW = GetProcAddress(hModule, "FindExecutableImageExW");
  if ( *(_DWORD *)FindExecutableImageExW )
  {
    *(_DWORD *)FindExecutableImageExW_0 = FindExecutableImageExW_1;
  }
  else
  {
    v59 = LoadLibraryW(L"imagehlp.dll");
    FindExecutableImage = (int (__stdcall *)(PCSTR, PCSTR, PSTR))GetProcAddress(v59, "FindExecutableImage");
    v61 = 0;
    ::FindExecutableImage = FindExecutableImage;
    if ( FindExecutableImage )
      v61 = sub_C4BC50;
    *(_DWORD *)FindExecutableImageExW_0 = v61;
  }
  v62 = GetModuleHandleW(L"ntdll.dll");
  NtSuspendProcess = (int (__stdcall *)(HANDLE))GetProcAddress(v62, "NtSuspendProcess");
  v63 = GetModuleHandleW(L"ntdll.dll");
  NtResumeProcess = (int (__stdcall *)(HANDLE))GetProcAddress(v63, "NtResumeProcess");
  v64 = GetModuleHandleW(L"kernel32.dll");
  QueryProcessCycleTime = (int (__thiscall *)(HANDLE, PULONG64))GetProcAddress(v64, "QueryProcessCycleTime");
  v65 = GetModuleHandleW(L"kernel32.dll");
  QueryIdleProcessorCycleTime = (int (__stdcall *)(PULONG, PULONG64))GetProcAddress(v65, "QueryIdleProcessorCycleTime");
  v66 = GetModuleHandleW(L"kernel32.dll");
  QueryThreadCycleTime = (int (__stdcall *)(HANDLE, PULONG64))GetProcAddress(v66, "QueryThreadCycleTime");
  v67 = GetModuleHandleW(L"Shell32.dll");
  SHGetStockIconInfo = (int (__stdcall *)(_DWORD, _DWORD, _DWORD))GetProcAddress(v67, "SHGetStockIconInfo");
  v68 = GetModuleHandleW(L"kernel32.dll");
  *(_DWORD *)CreateJobObjectW = GetProcAddress(v68, "CreateJobObjectW");
  v69 = GetModuleHandleW(L"user32.dll");
  ChangeWindowMessageFilter = (int (__stdcall *)(_DWORD, _DWORD))GetProcAddress(v69, "ChangeWindowMessageFilter");
  v70 = LoadLibraryW(L"advapi32.dll");
  I_QueryTagInformation = (int (__stdcall *)(PVOID, _SC_SERVICE_TAG_QUERY_TYPE, _SC_SERVICE_TAG_QUERY *))GetProcAddress(v70, "I_QueryTagInformation");
  v71 = LoadLibraryW(L"wow64cpu");
  CpuGetContext = (int)GetProcAddress(v71, "CpuGetContext");
  v72 = LoadLibraryW(L"kernel32.dll");
  GetProcessorSystemCycleTime = (int)GetProcAddress(v72, "GetProcessorSystemCycleTime");
  v73 = LoadLibraryW(L"kernel32.dll");
  GetThreadIdealProcessorEx = (int (__stdcall *)(HANDLE, PPROCESSOR_NUMBER))GetProcAddress(
                                                                              v73,
                                                                              "GetThreadIdealProcessorEx");
  v74 = LoadLibraryW(L"user32.dll");
  IsImmersiveProcess = (int (__stdcall *)(_DWORD))GetProcAddress(v74, "IsImmersiveProcess");
  v75 = LoadLibraryW(L"kernel32.dll");
  GetPackageFullName = (int (__stdcall *)(HANDLE, UINT32 *, PWSTR))GetProcAddress(v75, "GetPackageFullName");
  return 1;
}
// CB3420: using guessed type wchar_t aNtdllNtquerysy[31];
// CB3480: using guessed type wchar_t aNtdllNtquerysy_0[32];
// CB34D8: using guessed type wchar_t aNtdllNtquerydi[29];
// CB3530: using guessed type wchar_t aNtdllNtopensym[31];
// CB3588: using guessed type wchar_t aNtdllNtopendir[28];
// CB35D0: using guessed type wchar_t aNtdllNtqueryob[20];
// CB3618: using guessed type wchar_t aNtdllNtqueryin[32];
// CB3670: using guessed type wchar_t aNtdllNtsetinfo[30];
// CB36C0: using guessed type wchar_t aNtdllNtqueryse[23];
// CB3700: using guessed type wchar_t aNtdllNtqueryse_0[21];
// CB373C: using guessed type wchar_t aNtdllNtqueryev[19];
// CB3774: using guessed type wchar_t aNtdllNtquerymu[20];
// CB37AC: using guessed type wchar_t aNtdllNtresumet[21];
// CB37E8: using guessed type wchar_t aNtdllNtsuspend[22];
// CB3824: using guessed type wchar_t aNtdllNtopenthr[19];
// CB3868: using guessed type wchar_t aNtdllNtqueryin_0[31];
// CB38C0: using guessed type wchar_t aNtdllNtqueryvi[27];
// CB3918: using guessed type wchar_t aNtdllRtlcreate[32];
// CB3978: using guessed type wchar_t aNtdllRtlqueryp[38];
// CB39E0: using guessed type wchar_t aNtdllRtldestro[33];
// CB3A38: using guessed type wchar_t aNtdllRtltimeto[26];
// CB3AC8: using guessed type wchar_t aAcleditSeddisc[34];
// CB3B20: using guessed type wchar_t aAcleditSedsyst[27];
// CB3B6C: using guessed type wchar_t aAcleditSedtake[25];
// CDB1C8: using guessed type int (__stdcall *NtSetInformationProcess)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// CDF220: using guessed type int RtlTimeToTimeFields;
// CDF224: using guessed type int NtQueryDirectoryObject;
// CDF228: using guessed type int (__stdcall *NtSetInformationProcess_0)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// CDF260: using guessed type int (__stdcall *RtlQueryProcessDebugInformation)(_DWORD, _DWORD, _DWORD);
// CDF264: using guessed type int (__stdcall *RtlDestroyQueryDebugBuffer)(_DWORD);
// CDF2E8: using guessed type int (__stdcall *GlobalMemoryStatusEx)(_DWORD);
// CDF2F4: using guessed type int GetProcessorSystemCycleTime;
// CDF32C: using guessed type int SetThreadGroupAffinity;
// CDF360: using guessed type int (__stdcall *ChangeWindowMessageFilter)(_DWORD, _DWORD);
// CDF364: using guessed type int CpuGetContext;
// CDF36C: using guessed type int (__stdcall *GetProcessDpiAwareness)(_DWORD, _DWORD);
// CEBA4C: using guessed type int (__stdcall *IsImmersiveProcess)(_DWORD);
// CEBA50: using guessed type int (__stdcall *SHGetStockIconInfo)(_DWORD, _DWORD, _DWORD);

//----- (00C501B0) --------------------------------------------------------
char InitTlhlpApis()
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

  v0 = GetModuleHandleW(L"kernel32.dll");
  *(_DWORD *)CreateToolhelp32Snapshot_0 = GetProcAddress(v0, "CreateToolhelp32Snapshot");
  if ( !*(_DWORD *)CreateToolhelp32Snapshot_0 )
    return 0;
  v2 = GetModuleHandleW(L"kernel32.dll");
  *(_DWORD *)Process32FirstW_0 = GetProcAddress(v2, "Process32FirstW");
  if ( !*(_DWORD *)Process32FirstW_0 )
    return 0;
  v3 = GetModuleHandleW(L"kernel32.dll");
  *(_DWORD *)Process32NextW_0 = GetProcAddress(v3, "Process32NextW");
  if ( !*(_DWORD *)Process32NextW_0 )
    return 0;
  v4 = GetModuleHandleW(L"kernel32.dll");
  *(_DWORD *)Thread32First_0 = GetProcAddress(v4, "Thread32First");
  if ( !*(_DWORD *)Thread32First_0 )
    return 0;
  v5 = GetModuleHandleW(L"kernel32.dll");
  *(_DWORD *)Thread32Next_0 = GetProcAddress(v5, "Thread32Next");
  if ( !*(_DWORD *)Thread32Next_0 )
    return 0;
  v6 = GetModuleHandleW(L"kernel32.dll");
  *(_DWORD *)Module32FirstW_0 = GetProcAddress(v6, "Module32FirstW");
  if ( !*(_DWORD *)Module32FirstW_0 )
    return 0;
  v7 = GetModuleHandleW(L"kernel32.dll");
  *(_DWORD *)Module32NextW_0 = GetProcAddress(v7, "Module32NextW");
  if ( !*(_DWORD *)Module32NextW_0 )
    return 0;
  v8 = LoadLibraryW(L"dbghelp.dll");
  *(_DWORD *)ImageNtHeader = GetProcAddress(v8, "ImageNtHeader");
  if ( !*(_DWORD *)ImageNtHeader )
  {
    v9 = LoadLibraryW(L"imagehlp.dll");
    *(_DWORD *)ImageNtHeader = GetProcAddress(v9, "ImageNtHeader");
  }
  v10 = LoadLibraryW(L"user32.dll");
  IsHungThread = (int)GetProcAddress(v10, "IsHungThread");
  return 1;
}
// CDF320: using guessed type int IsHungThread;

//----- (00C502C0) --------------------------------------------------------
void __cdecl QueryProcessArguments(HANDLE hProcess, ULONG_PTR dwProcessId, WCHAR **ppszCommandLine, WCHAR **ppszCurrentDirectory, WCHAR **ppszEnvBlock, PDWORD pbFlagsInExtendedProcessBasicInfo)
{
  PDWORD pdwValue6In; // eax
  WCHAR **ppszCommandLineIn; // edi
  CCmdString *ppszCurrentDirectoryIn; // esi
  WCHAR **ppszEnvBlockIn; // ebx
  WCHAR *v10; // eax
  _PROCESS_EXTENDED_BASIC_INFORMATION ProcessInformation; // [esp+0h] [ebp-20h]

  pdwValue6In = pbFlagsInExtendedProcessBasicInfo;
  ProcessInformation.Size = 0;
  *(_QWORD *)&ProcessInformation.BasicInfo.UniqueProcessId = 0i64;
  ProcessInformation.Flags = 0;
  _mm_storeu_si128((__m128i *)&ProcessInformation.BasicInfo, (__m128i)0i64);
  if ( pdwValue6In )
    *(_BYTE *)pdwValue6In = 0;
  ppszCommandLineIn = ppszCommandLine;
  if ( ppszCommandLine )
    *ppszCommandLine = 0;
  ppszCurrentDirectoryIn = (CCmdString *)ppszCurrentDirectory;
  if ( ppszCurrentDirectory )
    *ppszCurrentDirectory = 0;
  ppszEnvBlockIn = ppszEnvBlock;
  if ( ppszEnvBlock )
    *ppszEnvBlock = 0;
  if ( hProcess )
  {
    ProcessInformation.Size = 0x20;
    if ( !NtQueryInformationProcess(
            hProcess,
            ProcessBasicInformation,
            &ProcessInformation,
            sizeof(_PROCESS_EXTENDED_BASIC_INFORMATION),
            (PULONG)&ppszCommandLine)
      || !NtQueryInformationProcess(
            hProcess,
            ProcessBasicInformation,
            &ProcessInformation.BasicInfo,
            sizeof(PROCESS_BASIC_INFORMATION),
            (PULONG)&ppszCommandLine) )
    {
      if ( pbFlagsInExtendedProcessBasicInfo )
        *(_BYTE *)pbFlagsInExtendedProcessBasicInfo = ProcessInformation.Flags & 1;
      if ( ProcessInformation.BasicInfo.PebBaseAddress )
        QueryProcessCommandLineArgs(
          hProcess,
          ProcessInformation.BasicInfo.PebBaseAddress,
          ppszCommandLineIn,
          &ppszCurrentDirectoryIn->m_String,
          ppszEnvBlockIn);
      if ( ppszCurrentDirectoryIn )
      {
        if ( ppszCurrentDirectoryIn->m_String )
          CCmdString::GetFullPathName(ppszCurrentDirectoryIn);
        else
          ppszCurrentDirectoryIn->m_String = _wcsdup((const wchar_t *)&gszNullString);
      }
      if ( ppszCommandLineIn && !*ppszCommandLineIn )
        *ppszCommandLineIn = _wcsdup((const wchar_t *)&gszNullString);
      if ( ppszEnvBlockIn )
      {
        if ( !*ppszEnvBlockIn )
        {
          v10 = _wcsdup(L" ");
          *ppszEnvBlockIn = v10;
          *v10 = 0;
        }
      }
    }
  }
}

//----- (00C503E0) --------------------------------------------------------
char __cdecl sub_C503E0(HANDLE hProcess, DWORD dwPid, LPCWSTR lpszProcessName, LPVOID *ppBufer, PDWORD pdwSize)
{
  HANDLE v5; // ebx
  HANDLE v6; // ebx
  const wchar_t *v7; // eax
  WCHAR *v8; // edi
  DWORD v9; // eax
  DWORD v10; // ebx
  SIZE_T v12; // edi
  WCHAR *v13; // esi
  void *v14; // edi
  int v15; // ebx
  IAtlStringMgr *v16; // eax
  volatile signed __int32 *v17; // edi
  struct _MEMORY_BASIC_INFORMATION Buffer; // [esp+10h] [ebp-474h]
  WCHAR *v19; // [esp+2Ch] [ebp-458h]
  PDWORD v20; // [esp+30h] [ebp-454h]
  WCHAR *v21; // [esp+34h] [ebp-450h]
  wchar_t *v22; // [esp+38h] [ebp-44Ch]
  LPVOID *v23; // [esp+3Ch] [ebp-448h]
  wchar_t *v24; // [esp+40h] [ebp-444h]
  size_t SizeInWords; // [esp+44h] [ebp-440h]
  HANDLE v26; // [esp+48h] [ebp-43Ch]
  MODULEENTRY32W me; // [esp+4Ch] [ebp-438h]
  int v28; // [esp+480h] [ebp-4h]

  v5 = hProcess;
  v22 = (wchar_t *)lpszProcessName;
  v23 = ppBufer;
  v20 = pdwSize;
  v26 = hProcess;
  v24 = (wchar_t *)dwPid;
  if ( *(_DWORD *)CreateToolhelp32Snapshot_0 )
  {
    v6 = CreateToolhelp32Snapshot_0(8u, dwPid);
    v26 = v6;
    if ( v6 != (HANDLE)-1 )
    {
      me.dwSize = 1064;
      if ( Module32FirstW_0(v6, &me) )
      {
        do
        {
          v28 = 0;
          if ( !wcsncmp(me.szExePath, L"\\??\\", 4u) )
          {
            v7 = &me.szExePath[4];
          }
          else
          {
            if ( !_wcsnicmp(me.szExePath, L"\\Systemroot\\", 0xCu) )
            {
              SizeInWords = ExpandEnvironmentStringsW(L"%SystemRoot%", 0, 0) + 1 + wcslen(me.szExePath);
              v8 = (WCHAR *)malloc(2 * SizeInWords);
              v21 = v8;
              ExpandEnvironmentStringsW(L"%SystemRoot%", v8, SizeInWords);
              wcscat_s(v8, SizeInWords, &me.szExePath[11]);
              goto LABEL_10;
            }
            v7 = me.szExePath;
          }
          v8 = _wcsdup(v7);
          v21 = v8;
LABEL_10:
          if ( *(_DWORD *)GetLongPathNameW )
          {
            v9 = GetLongPathNameW(v8, 0, 0);
            v10 = v9;
            if ( v9 )
            {
              v19 = (WCHAR *)malloc(2 * v9 + 2);
              LOBYTE(v28) = 1;
              GetLongPathNameW(v8, v19, v10 + 1);
              free(v8);
              v8 = v19;
              LOBYTE(v28) = 0;
              operator delete(0);
            }
            v6 = v26;
          }
          if ( (wchar_t *)me.th32ProcessID == v24 && !_wcsicmp(v22, v8) )
          {
            *v23 = me.modBaseAddr;
            *v20 = me.modBaseSize;
            operator delete(v8);
            return 1;
          }
          v28 = -1;
          operator delete(v8);
        }
        while ( Module32NextW_0(v6, &me) );
      }
      CloseHandle(v6);
    }
    return 0;
  }
  Buffer.BaseAddress = 0;
  if ( !VirtualQueryEx(hProcess, 0, &Buffer, 0x1Cu) )
    return 0;
  while ( 1 )
  {
    if ( Buffer.Type != 0x40000
      || NtQueryVirtualMemory(v5, Buffer.BaseAddress, MemoryMappedFilenameInformation, 0, 0, &SizeInWords) != STATUS_INFO_LENGTH_MISMATCH )
    {
      goto LABEL_30;
    }
    v12 = SizeInWords;
    v13 = (WCHAR *)malloc(SizeInWords);
    v19 = v13;
    v28 = 2;
    if ( !NtQueryVirtualMemory(v5, Buffer.BaseAddress, MemoryMappedFilenameInformation, v13, v12, &SizeInWords) )
      break;
LABEL_29:
    v28 = -1;
    operator delete(v13);
LABEL_30:
    Buffer.BaseAddress = (char *)Buffer.BaseAddress + Buffer.RegionSize;
    if ( !VirtualQueryEx(v5, Buffer.BaseAddress, &Buffer, 0x1Cu) )
      return 0;
  }
  v14 = (void *)*((_DWORD *)v13 + 1);
  v15 = (unsigned int)*v13 >> 1;
  v16 = ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>::GetDefaultManager();
  sub_C1CF80((void **)&v24, v14, v15, (int)v16);
  v17 = (volatile signed __int32 *)(v24 - 8);
  if ( _wcsicmp(v24, v22) )
  {
    if ( _InterlockedDecrement(v17 + 3) <= 0 )
      (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v17 + 4))(v17);
    v5 = v26;
    goto LABEL_29;
  }
  *v23 = Buffer.BaseAddress;
  *v20 = Buffer.RegionSize;
  if ( _InterlockedDecrement(v17 + 3) <= 0 )
    (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v17 + 4))(v17);
  operator delete(v13);
  return 1;
}

//----- (00C507B0) --------------------------------------------------------
DWORD __cdecl LoadSystemModulesSymbolAddress(LPCWSTR lpszName)
{
  RTL_PROCESS_MODULES *ProcessModules; // edi
  ULONG v2; // esi
  ULONG Index; // esi
  const CHAR *v4; // ebx
  const wchar_t **v5; // eax
  CStringData *v6; // eax
  int BaseOfDll_1; // ebx
  HANDLE hFile; // edi
  HANDLE v9; // eax
  DWORD result; // eax
  HANDLE hProcess; // eax
  __int64 v12; // rax
  HANDLE v13; // eax
  const CHAR *Name_1; // ST1C_4
  HANDLE hProcess_1; // eax
  int v16; // eax
  HANDLE v17; // eax
  struct _MODLOAD_DATA *Data; // [esp-Ch] [ebp-740h]
  DWORD Flags; // [esp-8h] [ebp-73Ch]
  CStringData *v20; // [esp+0h] [ebp-734h]
  CString strFullPathName; // [esp+4h] [ebp-730h]
  PCSTR Name; // [esp+8h] [ebp-72Ch]
  DWORD64 BaseOfDll; // [esp+Ch] [ebp-728h]
  WCHAR szDir[260]; // [esp+14h] [ebp-720h]
  WCHAR FileName[260]; // [esp+21Ch] [ebp-518h]
  wchar_t ImageName[260]; // [esp+424h] [ebp-310h]
  IMAGEHLP_SYMBOL Symbol; // [esp+62Ch] [ebp-108h]

  Name = (PCSTR)lpszName;
  if ( !SymCleanup || !SymInitialize || !SymLoadModuleExW_1 || !SymGetSymFromName )
    return 0;
  HIDWORD(BaseOfDll) = 1000;
  ProcessModules = (RTL_PROCESS_MODULES *)malloc(0x3E8u);
  if ( NtQuerySystemInformation(SystemModuleInformation, ProcessModules, 0x3E8u, (PULONG)&BaseOfDll + 1) )
  {
    do
    {
      HIDWORD(BaseOfDll) += 1000;
      free(ProcessModules);
      v2 = HIDWORD(BaseOfDll);
      ProcessModules = (RTL_PROCESS_MODULES *)malloc(HIDWORD(BaseOfDll));
    }
    while ( NtQuerySystemInformation(SystemModuleInformation, ProcessModules, v2, (PULONG)&BaseOfDll + 1) );
  }
  if ( IsPAEEnabled() )
    wcscpy_s(ImageName, MAX_PATH, L"ntkrnlpa.exe");
  else
    wcscpy_s(ImageName, MAX_PATH, L"ntoskrnl.exe");
  Index = 0;
  if ( ProcessModules->NumberOfModules )
  {
    v4 = (const CHAR *)ProcessModules->Modules[0].FullPathName;
    while ( 1 )
    {
      v5 = (const wchar_t **)ATL::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>(
                               &strFullPathName,
                               v4);
      LODWORD(BaseOfDll) = wcsstr(*v5, ImageName);
      v6 = (CStringData *)(strFullPathName.pszData - 16);
      v20 = (CStringData *)(strFullPathName.pszData - 16);
      if ( _InterlockedDecrement((volatile signed __int32 *)strFullPathName.pszData - 1) <= 0 )
        ((void (__stdcall *)(CStringData *))v6->pStringMgr->vtptr->Free)(v20);
      if ( (_DWORD)BaseOfDll )
        break;
      ++Index;
      v4 += sizeof(RTL_PROCESS_MODULE_INFORMATION);
      if ( Index >= ProcessModules->NumberOfModules )
        goto LABEL_16;
    }
    BaseOfDll_1 = (int)ProcessModules->Modules[Index].ImageBase;
  }
  else
  {
LABEL_16:
    BaseOfDll_1 = BaseOfDll;
  }
  free(ProcessModules);
  GetSystemDirectoryW(szDir, MAX_PATH);
  swprintf(FileName, L"%s\\%s", szDir, ImageName);
  hFile = CreateFileW(FileName, GENERIC_READ, 3u, 0, OPEN_EXISTING, 0, 0);
  EnterCriticalSection(&gPE_ImageItemVerifiedLock);
  v9 = GetCurrentThread();
  if ( SymInitialize(v9, 0, 0) )
  {
    hProcess = GetCurrentThread();
    LODWORD(v12) = SymLoadModuleExW_1(hProcess, hFile, ImageName, 0, BaseOfDll_1, 0, Data, Flags);
    if ( v12 )
    {
      Symbol.SizeOfStruct = sizeof(IMAGEHLP_SYMBOL);
      Name_1 = Name;
      Symbol.MaxNameLength = 237;
      hProcess_1 = GetCurrentThread();
      v16 = SymGetSymFromName(hProcess_1, Name_1, &Symbol);
      Symbol.Address &= -(v16 != 0);
      CloseHandle(hFile);
      v17 = GetCurrentThread();
      SymCleanup(v17);
      LeaveCriticalSection(&gPE_ImageItemVerifiedLock);
      result = Symbol.Address;
    }
    else
    {
      CloseHandle(hFile);
      v13 = GetCurrentThread();
      SymCleanup(v13);
      LeaveCriticalSection(&gPE_ImageItemVerifiedLock);
      result = 0;
    }
  }
  else
  {
    LeaveCriticalSection(&gPE_ImageItemVerifiedLock);
    CloseHandle(hFile);
    result = 0;
  }
  return result;
}
// CB56FC: using guessed type wchar_t aNtkrnlpaExe[13];
// C509BE: user specified stroff has not been processed: RTL_PROCESS_MODULE_INFORMATION offset 284

//----- (00C50A90) --------------------------------------------------------
char __cdecl sub_C50A90(HANDLE hProcess, DWORD dwProcessId, LPWSTR *ppszFileName, tagTREEVIEWLISTITEMPARAM *pItem)
{
  DWORD dwIndex; // eax
  DWORD *v5; // ecx
  SC_HANDLE hService; // ebx
  DWORD v8; // esi
  wchar_t *pstr; // eax
  LPWSTR v10; // eax
  LPWSTR v11; // ecx
  int v12; // edx
  WCHAR v13; // ax
  rsize_t v14; // edi
  wchar_t *v15; // eax
  const wchar_t **v16; // esi
  DWORD v17; // eax
  DWORD v18; // edi
  WCHAR *v19; // eax
  DWORD v20; // eax
  DWORD v21; // esi
  WCHAR *v22; // eax
  LPWSTR v23; // ecx
  WCHAR v24; // ax
  struct _QUERY_SERVICE_CONFIGW *pServiceConfig; // [esp+Ch] [ebp-21Ch]
  LPWSTR *ppszFileNameIn; // [esp+14h] [ebp-214h]
  DWORD dwRet; // [esp+18h] [ebp-210h]
  __int16 Src[260]; // [esp+1Ch] [ebp-20Ch]

  ppszFileNameIn = ppszFileName;
  *ppszFileName = 0;
  if ( !hProcess )
  {
    if ( pItem->dwStyle & TVLS_SHOWSERVICE )
    {
      dwIndex = 0;
      if ( gdwServiceReturned )
      {
        v5 = &gpszServiceNames->ServiceStatusProcess.dwProcessId;
        while ( *v5 != dwProcessId )
        {
          ++dwIndex;
          v5 += 11;
          if ( dwIndex >= gdwServiceReturned )
            return 0;
        }
        hService = OpenServiceW(ghSCManagerHandle, gpszServiceNames[dwIndex].lpServiceName, 5u);
        QueryServiceConfigW(hService, 0, 0, &dwRet);
        v8 = dwRet;
        pServiceConfig = (struct _QUERY_SERVICE_CONFIGW *)malloc(dwRet);
        QueryServiceConfigW(hService, pServiceConfig, v8, &dwRet);
        if ( pServiceConfig->lpBinaryPathName )
        {
          if ( !pItem->pszCommandLine )
            pItem->pszCommandLine = (int)_wcsdup(pServiceConfig->lpBinaryPathName);
          pstr = wcsstr(pServiceConfig->lpBinaryPathName, L".exe");
          if ( pstr && pstr[4] )
            pstr[4] = 0;
          v10 = pServiceConfig->lpBinaryPathName;
          if ( *v10 == '"' )
            pServiceConfig->lpBinaryPathName = v10 + 1;
          v11 = pServiceConfig->lpBinaryPathName;
          v12 = (int)(v11 + 1);
          do
          {
            v13 = *v11;
            ++v11;
          }
          while ( v13 );
          v14 = (((signed int)v11 - v12) >> 1) + 5;
          v15 = (wchar_t *)malloc(2 * v14);
          v16 = (const wchar_t **)ppszFileNameIn;
          *ppszFileNameIn = v15;
          wcscpy_s(v15, v14, pServiceConfig->lpBinaryPathName);
          free(pServiceConfig);
          if ( GetFileAttributesW(*v16) == -1 )
          {
            if ( **v16 != '"' && wcschr(*v16, ' ') )
              *wcschr(*v16, ' ') = 0;
            if ( GetFileAttributesW(*v16) == -1 )
              wcscat_s((wchar_t *)*v16, v14, L".exe");
          }
          return 1;
        }
        free(pServiceConfig);
      }
    }
    return 0;
  }
  if ( !sub_C4CF30(hProcess, ppszFileName) )
  {
    v17 = GetModuleFileNameExW(hProcess, 0, (LPWSTR)&ppszFileNameIn, 2u);
    v18 = v17;
    if ( !v17 )
      return 0;
    v19 = (WCHAR *)malloc(2 * v17 + 2);
    *ppszFileName = v19;
    if ( !GetModuleFileNameExW(hProcess, 0, v19, v18) )
      return 0;
  }
  if ( !_wcsnicmp(*ppszFileName, L"\\SystemRoot\\", 0xCu) )
  {
    swprintf((wchar_t *)Src, L"%%SystemRoot%%\\%s", *ppszFileName + 12);
    v20 = ExpandEnvironmentStringsW((LPCWSTR)Src, 0, 0);
    v21 = v20;
    v22 = (WCHAR *)malloc(2 * v20);
    *ppszFileName = v22;
    ExpandEnvironmentStringsW((LPCWSTR)Src, v22, v21);
    return 1;
  }
  if ( !wcsncmp(*ppszFileName, L"\\??\\", 4u) )
  {
    v23 = *ppszFileName;
    do
    {
      v24 = *v23;
      ++v23;
    }
    while ( v24 );
    wcscpy_s(*ppszFileName, v23 - (*ppszFileName + 1), *ppszFileName + 4);
  }
  return 1;
}

//----- (00C50D70) --------------------------------------------------------
PE_ImageItemVerified *__cdecl PE_ImageItemVerified_Find(wchar_t *pszText)
{
  PE_ImageItemVerified *v1; // esi
  PE_ImageItemVerified *result; // eax

  EnterCriticalSection(&gPE_ImageItemVerifiedLock);
  v1 = gpPE_ImageItemVerified;
  if ( gpPE_ImageItemVerified )
  {
    while ( _wcsicmp((const wchar_t *)v1->pszText1, pszText) )
    {
      v1 = (PE_ImageItemVerified *)v1->pNext;
      if ( !v1 )
        goto LABEL_4;
    }
    LeaveCriticalSection(&gPE_ImageItemVerifiedLock);
    result = v1;
  }
  else
  {
LABEL_4:
    LeaveCriticalSection(&gPE_ImageItemVerifiedLock);
    result = 0;
  }
  return result;
}

//----- (00C50DD0) --------------------------------------------------------
void __cdecl sub_C50DD0(wchar_t *a1)
{
  int v1; // edi
  wchar_t *v2; // ebx
  WCHAR *v3; // ecx
  size_t v4; // esi
  int v5; // edx
  unsigned int v6; // ecx
  WCHAR *v7; // esi
  WCHAR v8; // ax
  int v9; // esi
  WCHAR *v10; // edx
  int v11; // esi
  int v12; // edi
  WCHAR v13; // ax

  v1 = 0;
  if ( gszDriverLinkName[0] )
  {
    v2 = a1;
    v3 = gszDriverLinkName;
    while ( 1 )
    {
      v4 = wcslen(v3);
      if ( !_wcsnicmp(v3, v2, v4) && v2[v4] == 92 )
        break;
      v3 = &gszDriverLinkName[257 * ++v1];
      if ( !gszDriverLinkName[257 * v1] )
        return;
    }
    v5 = 257 * v1;
    *v2 = gszDriverName[0][257 * v1];
    v2[1] = 58;
    v6 = wcslen(v2);
    v7 = &gszDriverLinkName[257 * v1 + 1];
    do
    {
      v8 = *v7;
      ++v7;
    }
    while ( v8 );
    v9 = (char *)v7 - (char *)&gszDriverLinkName[v5 + 2];
    v10 = &gszDriverLinkName[v5];
    v11 = v9 >> 1;
    v12 = (int)(v10 + 1);
    do
    {
      v13 = *v10;
      ++v10;
    }
    while ( v13 );
    memmove_0(v2 + 2, &v2[((signed int)v10 - v12) >> 1], 2 * (v6 - v11));
    CCmdString::GetLongPathName((CCmdString)&a1, 0x104u);
  }
}

//----- (00C50EE0) --------------------------------------------------------
int __cdecl sub_C50EE0(wchar_t *pszBuffer)
{
  int nIndex; // ebx
  WCHAR **pszPosition; // esi
  int v3; // ebx
  RegItem *v4; // esi
  int result; // eax
  int ret; // eax
  char found; // cl
  wchar_t *pszText; // esi
  wchar_t i; // ax
  const wchar_t *v10; // esi
  char found_1; // [esp+Ch] [ebp-Ch]

  nIndex = 0;
  pszPosition = dword_CD0560;
  do
  {
    if ( !_wcsnicmp(pszBuffer, (const wchar_t *)pszPosition - 288, (size_t)*pszPosition)
      && !_wcsnicmp(&pszBuffer[(_DWORD)*pszPosition], gpszCurAuthInfo, wcslen(gpszCurAuthInfo)) )
    {
      ret = _wcsnicmp(&pszBuffer[(_DWORD)dword_CD0560[145 * nIndex] + wcslen(gpszCurAuthInfo)], L"_Classes", 8u);
      found = 0;
      if ( !ret )
        found = 1;
      found_1 = found;
      pszText = &pszBuffer[(_DWORD)dword_CD0560[145 * nIndex]];
      for ( i = *pszText; i; ++pszText )
      {
        if ( i == '\\' )
          break;
        i = pszText[1];
      }
      wcscpy_s(pszBuffer, pszText - pszBuffer, &aHkcu_0[290 * nIndex]);
      if ( found_1 )
        wcscat_s(pszBuffer, pszText - pszBuffer, L"\\Software\\Classes");
      return wcscat_s(pszBuffer, 1024u, pszText);
    }
    pszPosition += 145;
    ++nIndex;
  }
  while ( (signed int)pszPosition < (signed int)dword_CD09E8 );
  v3 = 0;
  v4 = aRegistryUser_1;
  while ( 1 )
  {
    result = _wcsnicmp(pszBuffer, (const wchar_t *)v4, v4->field_240);
    if ( !result )
      break;
    ++v4;
    ++v3;
    if ( (signed int)v4 >= (signed int)gdwValue_4F10B8 )
      return result;
  }
  v10 = &pszBuffer[(_DWORD)dword_CD09E8[145 * v3]];
  wcscpy_s(pszBuffer, 2 * (signed int)dword_CD09E8[145 * v3] >> 1, &aHku_1[290 * v3]);
  return wcscat_s(pszBuffer, 1024u, v10);
}
// CD0520: using guessed type wchar_t aHkcu_0[5];
// CD09A8: using guessed type wchar_t aHku_1[4];
// CD10B8: using guessed type int gdwValue_4F10B8[3];

//----- (00C51080) --------------------------------------------------------
char __cdecl ReportMsg(int ArgList)
{
  WCHAR Text; // [esp+0h] [ebp-20Ch]

  swprintf(&Text, L"Not able to run on this version of Windows:\nMissing function: %s", ArgList);
  MessageBoxW(0, &Text, L"Process Explorer", 0x10u);
  return 0;
}

//----- (00C510E0) --------------------------------------------------------
signed int __stdcall PropHandleInfo(HWND hWnd, unsigned int a2, unsigned __int16 a3, int a4)
{
  HWND v5; // eax
  POINT v6; // ST18_8
  DWORD v7; // esi
  const WCHAR *v8; // ebx
  bool v9; // cl
  const WCHAR *v10; // esi
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  const wchar_t *v15; // eax
  const wchar_t *v16; // eax
  int v17; // eax
  void (__stdcall *v18)(HANDLE); // ebx
  const wchar_t *v19; // eax
  int v20; // eax
  HWND v21; // eax
  HWND v22; // eax
  HWND v23; // eax
  int ThreadInformation; // [esp+8h] [ebp-6C8h]
  DWORD dwProcessId; // [esp+10h] [ebp-6C0h]
  int v26; // [esp+14h] [ebp-6BCh]
  int InformationBuffer; // [esp+24h] [ebp-6ACh]
  int v28; // [esp+28h] [ebp-6A8h]
  char v29[4]; // [esp+2Ch] [ebp-6A4h]
  int v30; // [esp+30h] [ebp-6A0h]
  ULONG ResultLength; // [esp+34h] [ebp-69Ch]
  struct _FILETIME LocalFileTime; // [esp+38h] [ebp-698h]
  FILETIME FileTime; // [esp+40h] [ebp-690h]
  int EventInformation; // [esp+48h] [ebp-688h]
  int v35; // [esp+4Ch] [ebp-684h]
  int MutantInformation; // [esp+50h] [ebp-680h]
  char v37; // [esp+55h] [ebp-67Bh]
  struct tagPOINT Point; // [esp+58h] [ebp-678h]
  char v39[4]; // [esp+60h] [ebp-670h]
  char v40[4]; // [esp+64h] [ebp-66Ch]
  ULONG ReturnLength; // [esp+68h] [ebp-668h]
  struct _UNICODE_STRING LinkTarget; // [esp+6Ch] [ebp-664h]
  void *OutBuffer; // [esp+74h] [ebp-65Ch]
  DWORD BytesReturned; // [esp+78h] [ebp-658h]
  ULONG ReturnedLength; // [esp+7Ch] [ebp-654h]
  void *InBuffer; // [esp+80h] [ebp-650h]
  int ObjectInformation; // [esp+84h] [ebp-64Ch]
  int v48; // [esp+8Ch] [ebp-644h]
  int v49; // [esp+90h] [ebp-640h]
  char ArgList[4]; // [esp+94h] [ebp-63Ch]
  char v51[4]; // [esp+98h] [ebp-638h]
  FILETIME v52; // [esp+B4h] [ebp-61Ch]
  struct _SYSTEMTIME SystemTime; // [esp+BCh] [ebp-614h]
  char v54; // [esp+CCh] [ebp-604h]
  wchar_t Dst; // [esp+2CCh] [ebp-404h]
  WCHAR String; // [esp+4CCh] [ebp-204h]

  if ( a2 == 16 )
    goto LABEL_5;
  if ( a2 == 272 )
  {
    GetCursorPos(&Point);
    v5 = GetParent(hWnd);
    sub_C4BDA0(v5);
    v6.y = Point.y - 430;
    v6.x = Point.x - 375;
    PE_SetWindowPlacement(hWnd, v6);
    PostMessageW(hWnd, 0x46Bu, 0, 0);
    v7 = *(_DWORD *)(a4 + 28);
    BytesReturned = v7;
    v8 = (const WCHAR *)(v7 + 56);
    v9 = !_wcsicmp((const wchar_t *)(v7 + 56), L"Mutant")
      || !_wcsicmp((const wchar_t *)(v7 + 56), L"Section")
      || !_wcsicmp((const wchar_t *)(v7 + 56), L"Event")
      || !_wcsicmp((const wchar_t *)(v7 + 56), L"Semaphore");
    InBuffer = (void *)PE_DuplicateProcessHandle(*(_DWORD *)(v7 + 36), *(HANDLE *)(v7 + 44), v9 != 0);
    if ( !InBuffer )
    {
      if ( *(_DWORD *)(v7 + 16) == 1 )
        MessageBoxW(ghMainWnd, L"Object does not exist.", L"Object Properties Error", 0x10u);
      else
        MessageBoxW(ghMainWnd, L"Unable to query the object", L"Object Properties Error", 0x10u);
      v22 = GetParent(hWnd);
      EndDialog(v22, 0);
      v23 = GetParent(hWnd);
      PostMessageW(v23, 0x471u, 5u, 0);
      return 0;
    }
    v10 = (const WCHAR *)(v7 + 2232);
    wsprintf(&String, L"%s Properties", v10);
    SetWindowTextW(hWnd, &String);
    SetDlgItemTextW(hWnd, 1005, v10);
    SetDlgItemTextW(hWnd, 1006, v8);
    if ( _wcsicmp(v8, L"file") )
    {
      if ( _wcsicmp(v8, L"directory") )
      {
        if ( _wcsicmp(v8, L"symboliclink") )
        {
          if ( _wcsicmp(v8, L"key") )
          {
            if ( _wcsicmp(v8, L"process") )
            {
              v11 = wcscmp(v8, L"thread");
              if ( v11 )
                v11 = -(v11 < 0) | 1;
              if ( v11 )
              {
                if ( _wcsicmp(v8, L"iocompletion") )
                {
                  if ( _wcsicmp(v8, L"mutant") )
                  {
                    if ( _wcsicmp(v8, L"event") && _wcsicmp(v8, L"semaphore") )
                    {
                      if ( _wcsicmp(v8, L"windowstation") )
                      {
                        if ( _wcsicmp(v8, L"desktop") )
                        {
                          if ( _wcsicmp(v8, L"port") && _wcsicmp(v8, L"waitableport") )
                          {
                            if ( _wcsicmp(v8, L"section") )
                            {
                              if ( _wcsicmp(v8, L"token") )
                              {
                                if ( !_wcsicmp(v8, L"timer") )
                                  SetDlgItemTextW(hWnd, 1050, L"A time-based synchronization object.");
                              }
                              else
                              {
                                SetDlgItemTextW(hWnd, 1050, L"Identifies a security context.");
                              }
                            }
                            else
                            {
                              SetDlgItemTextW(hWnd, 1050, L"A memory mapped file or paging-file backed memory region.");
                            }
                          }
                          else
                          {
                            SetDlgItemTextW(hWnd, 1050, L"An interprocess communications endpoint.");
                          }
                        }
                        else
                        {
                          SetDlgItemTextW(hWnd, 1050, L"Contains application windows.");
                        }
                      }
                      else
                      {
                        SetDlgItemTextW(hWnd, 1050, L"Contains one or more desktops with windows.");
                      }
                    }
                    else
                    {
                      SetDlgItemTextW(hWnd, 1050, L"A synchronization object.");
                    }
                  }
                  else
                  {
                    SetDlgItemTextW(hWnd, 1050, L"A synchronization object (a Win32 mutex).");
                  }
                }
                else
                {
                  SetDlgItemTextW(hWnd, 1050, L"An asynchronous I/O notification object.");
                }
              }
              else
              {
                SetDlgItemTextW(hWnd, 1050, L"An object that executes program code.");
              }
            }
            else
            {
              SetDlgItemTextW(hWnd, 1050, L"Contains threads, an address space, and handles.");
            }
          }
          else
          {
            SetDlgItemTextW(hWnd, 1050, L"A Registry key.");
          }
        }
        else
        {
          SetDlgItemTextW(hWnd, 1050, L"An Object Manager namespace link.");
        }
      }
      else
      {
        SetDlgItemTextW(hWnd, 1050, L"An Object Manager namespace directory.");
      }
    }
    else
    {
      SetDlgItemTextW(hWnd, 1050, L"A disk file, communications endpoint, or driver interface.");
    }
    wsprintf(&String, L"0x%X", *(_DWORD *)(BytesReturned + 40));
    SetDlgItemTextW(hWnd, 1051, &String);
    NtQueryObject(InBuffer, 0, &ObjectInformation, 0x38u, &ReturnLength);
    wsprintf(&String, L"%d", v48 - 1);
    SetDlgItemTextW(hWnd, 1008, &String);
    wsprintf(&String, L"%d", v49 - 2);
    SetDlgItemTextW(hWnd, 1019, &String);
    wsprintf(&String, L"%d", *(_DWORD *)ArgList);
    SetDlgItemTextW(hWnd, 1010, &String);
    wsprintf(&String, L"%d", *(_DWORD *)v51);
    SetDlgItemTextW(hWnd, 1013, &String);
    v12 = wcscmp(v8, L"SymbolicLink");
    if ( v12 )
      v12 = -(v12 < 0) | 1;
    if ( !v12 )
    {
      SetDlgItemTextW(hWnd, 1025, L"Symbolic Link Info");
      SetDlgItemTextW(hWnd, 1024, L"Creation Time:");
      FileTime = v52;
      FileTimeToLocalFileTime(&FileTime, &LocalFileTime);
      FileTimeToSystemTime(&LocalFileTime, &SystemTime);
      wsprintf(
        &String,
        L"%d:%02d:%02d, %d/%d/%d",
        SystemTime.wHour,
        SystemTime.wMinute,
        SystemTime.wSecond,
        SystemTime.wMonth,
        SystemTime.wDay,
        SystemTime.wYear);
      SetDlgItemTextW(hWnd, 1022, &String);
      SetDlgItemTextW(hWnd, 1028, L"Link:");
      LinkTarget.MaximumLength = 256;
      LinkTarget.Buffer = (WORD *)&v54;
      if ( gpfn_NtQuerySymbolicLinkObject(InBuffer, &LinkTarget, &ReturnedLength) )
        wcscpy_s(&String, 0x100u, L"<Error Querying Link>");
      else
        wsprintf(&String, L"%s", LinkTarget.Buffer);
      SetDlgItemTextW(hWnd, 1027, &String);
      goto LABEL_94;
    }
    v13 = wcscmp(v8, L"Semaphore");
    if ( v13 )
      v13 = -(v13 < 0) | 1;
    if ( v13 )
    {
      v14 = wcscmp(v8, L"Event");
      if ( v14 )
        v14 = -(v14 < 0) | 1;
      if ( v14 )
      {
        v17 = wcscmp(v8, L"Mutant");
        if ( v17 )
          v17 = -(v17 < 0) | 1;
        if ( !v17 )
        {
          SetDlgItemTextW(hWnd, 1025, L"Mutant Info");
          SetDlgItemTextW(hWnd, 1024, L"Held:");
          NtQueryMutant(InBuffer, 0, &MutantInformation, 8u, &ReturnedLength);
          wsprintf(&String, L"FALSE");
          if ( MutantInformation <= 0
            && (wsprintf(&String, L"TRUE"),
                DeviceIoControl(ghDriverHandle, 0x8335002C, &InBuffer, 4u, &OutBuffer, 4u, &BytesReturned, 0))
            && OutBuffer )
          {
            if ( !NtQueryInformationThread(OutBuffer, 0, &ThreadInformation, 0x1Cu, &ReturnLength) )
            {
              SystemProcessInfo_GetSystemProcessName(dwProcessId, 0, &Dst, 0x100u);
              wsprintf(&String, L"%s(%d): %d", &Dst, dwProcessId, v26);
            }
            v18 = (void (__stdcall *)(HANDLE))CloseHandle;
            CloseHandle(OutBuffer);
          }
          else
          {
            v18 = (void (__stdcall *)(HANDLE))CloseHandle;
          }
          SetDlgItemTextW(hWnd, 1022, &String);
          SetDlgItemTextW(hWnd, 1028, L"Abandoned:");
          v19 = L"TRUE";
          if ( !v37 )
            v19 = L"FALSE";
          wsprintf(&String, L"%s", v19);
          SetDlgItemTextW(hWnd, 1027, &String);
          v18(InBuffer);
          return 1;
        }
        v20 = wcscmp(v8, L"Section");
        if ( v20 )
          v20 = -(v20 < 0) | 1;
        if ( v20 )
        {
          v21 = GetDlgItem(hWnd, 1025);
          ShowWindow(v21, 0);
        }
        else
        {
          SetDlgItemTextW(hWnd, 1025, L"Section Info");
          NtQuerySection(InBuffer, 0, &InformationBuffer, 0x10u, &ResultLength);
          if ( v28 & 0x1000000 )
          {
            SetDlgItemTextW(hWnd, 1024, L"Type:");
            wcscpy_s(&String, 0x100u, L"IMAGE");
          }
          else if ( v28 & 0x800000 )
          {
            SetDlgItemTextW(hWnd, 1024, L"Type:");
            wcscpy_s(&String, 0x100u, L"FILE");
          }
          else if ( v28 & 0x4000000 )
          {
            SetDlgItemTextW(hWnd, 1024, L"Type:");
            wcscpy_s(&String, 0x100u, L"RESERVED");
          }
          else if ( v28 & 0x8000000 )
          {
            SetDlgItemTextW(hWnd, 1024, L"Type:");
            wcscpy_s(&String, 0x100u, L"COMMITED");
          }
          SetDlgItemTextW(hWnd, 1022, &String);
          SetDlgItemTextW(hWnd, 1028, L"Size:");
          wsprintf(&String, L"0x%08x", *(_DWORD *)v29, v30);
          SetDlgItemTextW(hWnd, 1027, &String);
        }
LABEL_94:
        CloseHandle(InBuffer);
        return 1;
      }
      SetDlgItemTextW(hWnd, 1025, L"Event Info");
      SetDlgItemTextW(hWnd, 1024, L"Type:");
      NtQueryEvent(InBuffer, 0, &EventInformation, 8u, &ReturnedLength);
      v15 = L"Notification";
      if ( EventInformation )
        v15 = L"Synchronization";
      wsprintf(&String, L"%s", v15);
      SetDlgItemTextW(hWnd, 1022, &String);
      SetDlgItemTextW(hWnd, 1028, L"Signaled:");
      v16 = L"TRUE";
      if ( !v35 )
        v16 = L"FALSE";
      wsprintf(&String, L"%s", v16);
    }
    else
    {
      SetDlgItemTextW(hWnd, 1025, L"Semaphore Info");
      SetDlgItemTextW(hWnd, 1024, L"Count:");
      NtSetInformationProcess_0(InBuffer, 0, v39, 8, &ReturnedLength);
      wsprintf(&String, L"%d", *(_DWORD *)v39);
      SetDlgItemTextW(hWnd, 1022, &String);
      SetDlgItemTextW(hWnd, 1028, L"Limit:");
      wsprintf(&String, L"%d", *(_DWORD *)v40);
    }
    SetDlgItemTextW(hWnd, 1027, &String);
    goto LABEL_94;
  }
  if ( a2 == 273 && (unsigned int)a3 - 1 <= 1 )
  {
LABEL_5:
    DestroyWindow(hWnd);
    return 1;
  }
  return 0;
}
// CB48C0: using guessed type wchar_t aADiskFileCommu[59];
// CB4950: using guessed type wchar_t aAnObjectManage[39];
// CB49C0: using guessed type wchar_t aAnObjectManage_0[34];
// CB4A0C: using guessed type wchar_t aARegistryKey[16];
// CB4A30: using guessed type wchar_t aContainsThread[49];
// CB4A98: using guessed type wchar_t aAnObjectThatEx[38];
// CB4B00: using guessed type wchar_t aAnAsynchronous[41];
// CB4B68: using guessed type wchar_t aASynchronizati[42];
// CB4C30: using guessed type wchar_t aContainsOneOrM[44];
// CB4C98: using guessed type wchar_t aContainsApplic[30];
// CB4D00: using guessed type wchar_t aAnInterprocess[41];
// CB4D68: using guessed type wchar_t aAMemoryMappedF[58];
// CB4DDC: using guessed type wchar_t aIdentifiesASec[31];
// CB4E28: using guessed type wchar_t aATimeBasedSync[37];
// CB4E74: using guessed type wchar_t aSymboliclink_0[13];
// CB4FA4: using guessed type wchar_t aNotification[13];
// CB4FC0: using guessed type wchar_t aSynchronizatio[16];
// CB504C: using guessed type wchar_t aImage_0[6];
// CB5058: using guessed type wchar_t aFile_2[5];
// CB5064: using guessed type wchar_t aReserved[9];
// CB50D8: using guessed type wchar_t aObjectDoesNotE[23];
// CDF228: using guessed type int (__stdcall *NtSetInformationProcess_0)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD);

//----- (00C51C00) --------------------------------------------------------
int __stdcall PropSecurity(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
  int result; // eax
  HWND v5; // edi
  HWND v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // ecx
  char v11; // al
  void *v12; // esi
  HWND v13; // eax
  unsigned int v14; // edx
  const unsigned __int16 *v15; // ebx
  __int16 *v16; // ecx
  __int16 v17; // ax
  WCHAR *v18; // esi
  WCHAR v19; // ax
  unsigned int v20; // edx
  HWND hWnda; // [esp+8h] [ebp+8h]

  if ( msg == WM_INITDIALOG )
  {
    v5 = hDlg;
    PostMessageW(hDlg, EM_GETIMEOPTIONS, 0, 0);
    dword_CEC038 = *(_DWORD *)(lParam + 0x1C);
    hWnda = (HWND)PE_DuplicateProcessHandle(*(_DWORD *)(dword_CEC038 + 36), *(HANDLE *)(dword_CEC038 + 44), 0x80000000);
    if ( hWnda )
    {
      byte_CEC083 = 0;
      byte_CEC084 = 0;
      byte_CEC085 = 0;
      byte_CEC082 = 0;
      v7 = wcscmp((const unsigned __int16 *)(dword_CEC038 + 0x38), L"Directory");
      if ( v7 )
        v7 = -(v7 < 0) | 1;
      if ( v7 )
      {
        v8 = wcscmp((const unsigned __int16 *)(dword_CEC038 + 0x38), L"Device");
        if ( v8 )
          v8 = -(v8 < 0) | 1;
        if ( v8 )
        {
          v9 = wcscmp((const unsigned __int16 *)(dword_CEC038 + 0x38), L"Process");
          if ( v9 )
            v9 = -(v9 < 0) | 1;
          if ( v9 )
          {
            v10 = wcscmp((const unsigned __int16 *)(dword_CEC038 + 0x38), L"Key");
            if ( v10 )
              v10 = -(v10 < 0) | 1;
            v11 = byte_CEC084;
            if ( !v10 )
              v11 = 1;
            byte_CEC084 = v11;
          }
          else
          {
            byte_CEC082 = 1;
          }
        }
        else
        {
          byte_CEC085 = 1;
        }
      }
      else
      {
        byte_CEC083 = 1;
      }
      wParam = 23;
      byte_CEC080 = GetUserObjectSecurity(hWnda, &wParam, pSID, 0x2000u, &msg) != 0;
      CloseHandle(hWnda);
    }
    else
    {
      byte_CEC080 = 0;
      v6 = GetDlgItem(v5, 127);
      EnableWindow(v6, 0);
    }
    v12 = (void *)PE_DuplicateProcessHandle(*(_DWORD *)(dword_CEC038 + 36), *(HANDLE *)(dword_CEC038 + 44), 0x81000000);
    if ( v12
      || (v12 = (void *)PE_DuplicateProcessHandle(
                          *(_DWORD *)(dword_CEC038 + 36),
                          *(HANDLE *)(dword_CEC038 + 44),
                          0x1000000u)) != 0 )
    {
      wParam = 9;
      byte_CEC081 = GetUserObjectSecurity(v12, &wParam, ObjectSecurity, 0x2000u, &msg) != 0;
      CloseHandle(v12);
    }
    else
    {
      byte_CEC081 = 0;
      v13 = GetDlgItem(v5, 128);
      EnableWindow(v13, 0);
    }
    v14 = 0;
    v15 = (const unsigned __int16 *)(dword_CEC038 + 184);
    v16 = (__int16 *)(dword_CEC038 + 184);
    do
    {
      v17 = *v16;
      ++v16;
    }
    while ( v17 );
    if ( (signed int)((char *)v16 - dword_CEC038 - 186) >> 1 )
    {
      v18 = (WCHAR *)(dword_CEC038 + 184);
      do
      {
        v19 = *v18;
        ++v18;
        gObjectName[v14++] = v19;
      }
      while ( v14 < wcslen(v15) );
    }
    v20 = v14;
    if ( v20 >= 1024 )
    {
      __report_rangecheckfailure();
      JUMPOUT(*(_DWORD *)algn_C5224B);
    }
    gAclDlgControl.Version = 257;
    gObjectName[v20] = 0;
    if ( byte_CEC084 )
    {
      gAclDlgControl.GenericAccessMap = (PGENERIC_MAPPING)RegistryAccessMasks;
      gAclDlgControl.SpecificAccessMap = (PGENERIC_MAPPING)RegistryAccessMasks;
    }
    else
    {
      gAclDlgControl.GenericAccessMap = (PGENERIC_MAPPING)AccessMasks;
      gAclDlgControl.SpecificAccessMap = (PGENERIC_MAPPING)AccessMasks;
    }
    gAclDlgControl.Reserved = 0;
    gAclDlgControl.SubReplaceTitle = 0;
    gAclDlgControl.SubReplaceConfirmation = 0;
    result = 1;
    gAclDlgControl.DialogTitle = aObject_0;
    gAclDlgControl.HelpInfo = &HelpInfo;
    gAclDlgControl.SpecialAccess = aSpecialAccess;
    return result;
  }
  if ( msg != 273 )
    return 0;
  if ( (unsigned __int16)wParam != 127 )
  {
    if ( (unsigned __int16)wParam == 128 )
    {
      if ( !byte_CEC081 )
      {
        MessageBoxW(0, L"You do not have permission to view the Audit Information for\nthis object.", L"WinObj", 0x10u);
        return 0;
      }
      gAclEditControl.NumberOfEntries = 7;
      gAclEditControl.Entries = aclEditEntryFile;
      dword_CEC040 = *(_DWORD *)(dword_CEC038 + 44);
      dword_CEC03C = *(_DWORD *)(dword_CEC038 + 36);
      dword_CEC044 = 1;
      dword_CEC048 = (int)dword_CEBC38;
      dword_CEC04C = (int)ObjectSecurity;
      dword_CEC050 = (int)&byte_CEC081;
      if ( SedSystemAclEditor(
             0,
             0,
             0,
             &gAclDlgControl,
             &gAclEditControl,
             gObjectName,
             (FARPROC)pfnAclChangeCallback,
             &dword_CEC03C,
             ObjectSecurity,
             0,
             &msg,
             0) )
      {
        MessageBoxW(0, L"The SACL Editor does not understand the Security Information.", L"WinObj", 0x10u);
        return 0;
      }
      return 0;
    }
    if ( (unsigned __int16)wParam == 129 )
    {
      if ( byte_CEC080 )
      {
        dword_CEC040 = *(_DWORD *)(dword_CEC038 + 0x2C);
        dword_CEC03C = *(_DWORD *)(dword_CEC038 + 0x24);
        dword_CEC044 = 2;
        dword_CEC048 = (int)dword_CEBC38;
        dword_CEC04C = (int)pSID;
        dword_CEC050 = (int)&byte_CEC080;
        wcscpy_s(&gObjectType, 0x400u, L"&Object");
        if ( SedTakeOwnership(
               0,
               0,
               0,
               &gObjectType,
               gObjectName,
               1u,
               (FARPROC)pfnAclChangeCallback,
               &dword_CEC03C,
               pSID,
               0,
               0,
               &msg,
               &HelpInfo,
               0) )
        {
          if ( IsValidSecurityDescriptor(pSID) )
          {
            MessageBoxW(0, L"The Ownership Editor does not understand the Security Information.", L"WinObj", 0x10u);
            return 0;
          }
          goto LABEL_10;
        }
        return 0;
      }
      goto LABEL_29;
    }
    return 0;
  }
  if ( !byte_CEC080 )
  {
LABEL_29:
    MessageBoxW(0, L"You do not have permission to view the Security Information for\nthis object.", L"WinObj", 0x10u);
    return 0;
  }
  if ( !byte_CEC083 )
  {
    if ( byte_CEC084 )
    {
      gAclEditControl.Entries = stru_CD01C0;
    }
    else
    {
      if ( byte_CEC085 )
      {
        gAclEditControl.NumberOfEntries = 11;
        gAclEditControl.Entries = stru_CD0110;
        goto LABEL_26;
      }
      if ( byte_CEC082 )
      {
        gAclEditControl.NumberOfEntries = 14;
        gAclEditControl.Entries = (PACLEDITENTRY)&dword_CCFED0;
        goto LABEL_26;
      }
      gAclEditControl.Entries = (PACLEDITENTRY)&HelpInfo.Reserved1;
    }
    gAclEditControl.NumberOfEntries = 12;
    goto LABEL_26;
  }
  gAclEditControl.NumberOfEntries = 22;
  gAclEditControl.Entries = stru_CCFFB0;
LABEL_26:
  dword_CEC040 = *(_DWORD *)(dword_CEC038 + 44);
  dword_CEC03C = *(_DWORD *)(dword_CEC038 + 36);
  dword_CEC044 = 0;
  dword_CEC048 = (int)dword_CEBC38;
  dword_CEC04C = (int)pSID;
  dword_CEC050 = (int)&byte_CEC080;
  if ( !SedDiscretionaryAclEditor(
          0,
          0,
          0,
          &gAclDlgControl,
          &gAclEditControl,
          gObjectName,
          (FARPROC)pfnAclChangeCallback,
          &dword_CEC03C,
          pSID,
          0,
          0,
          &msg,
          0) )
    return 0;
  if ( !IsValidSecurityDescriptor(pSID) )
  {
LABEL_10:
    MessageBoxW(0, L"The Security Information is invalid.", L"WinObj", 0x10u);
    return 0;
  }
  MessageBoxW(0, L"The ACL Editor does not understand the Security Information.", L"WinObj", 0x10u);
  return 0;
}
// C767E8: using guessed type int __report_rangecheckfailure(void);
// CCFCB8: using guessed type wchar_t aObject_0[7];
// CCFCE0: using guessed type wchar_t aSpecialAccess[18];
// CCFED0: using guessed type int dword_CCFED0;
// CCFFB0: using guessed type _ACLEDITENTRY stru_CCFFB0[22];
// CD0110: using guessed type _ACLEDITENTRY stru_CD0110[11];
// CD01C0: using guessed type _ACLEDITENTRY stru_CD01C0[12];
// CD0280: using guessed type _ACLEDITENTRY aclEditEntryFile[7];
// CD02F0: using guessed type int AccessMasks[4];
// CD0300: using guessed type int RegistryAccessMasks[4];
// CEBC38: using guessed type int dword_CEBC38[256];
// CEC038: using guessed type int dword_CEC038;
// CEC03C: using guessed type int dword_CEC03C;
// CEC040: using guessed type int dword_CEC040;
// CEC044: using guessed type int dword_CEC044;
// CEC048: using guessed type int dword_CEC048;
// CEC04C: using guessed type int dword_CEC04C;
// CEC050: using guessed type int dword_CEC050;
// CEC080: using guessed type char byte_CEC080;
// CEC081: using guessed type char byte_CEC081;
// CEC082: using guessed type char byte_CEC082;
// CEC083: using guessed type char byte_CEC083;
// CEC084: using guessed type char byte_CEC084;
// CEC085: using guessed type char byte_CEC085;

//----- (00C52250) --------------------------------------------------------
int __cdecl PE_DuplicateProcessHandle(DWORD dwProcessId, HANDLE hSourceHandle, DWORD dwDesiredAccess)
{
  DWORD dwPid; // edi
  HANDLE ProcessHandle; // esi
  DWORD v5; // ST14_4
  HANDLE v6; // ST0C_4
  HANDLE SourceHandle; // edi
  DWORD DesiredAccess; // ST14_4
  HANDLE TargetHandle; // ST0C_4
  int InBuf[4]; // [esp+8h] [ebp-20h]
  DWORD v12; // [esp+18h] [ebp-10h]
  DWORD BytesReturned; // [esp+1Ch] [ebp-Ch]
  DWORD InBuffer; // [esp+20h] [ebp-8h]
  int pTargetHandle; // [esp+24h] [ebp-4h]

  dwPid = dwProcessId;
  pTargetHandle = 0;
  InBuffer = dwProcessId;
  ProcessHandle = OpenProcess(PROCESS_DUP_HANDLE, 0, dwProcessId);
  dwProcessId = (DWORD)ProcessHandle;
  if ( ProcessHandle )
    goto LABEL_14;
  if ( GetLastError() == ERROR_ACCESS_DENIED )
    DeviceIoControl(ghDriverHandle, CTRLCODE_QUERY_PROCESS_HANDLE, &InBuffer, 4u, &dwProcessId, 4u, &BytesReturned, 0);
  ProcessHandle = (HANDLE)dwProcessId;
  if ( dwProcessId )
  {
LABEL_14:
    if ( dwPid <= 8 )
    {
      InBuf[0] = dwPid;
      SourceHandle = hSourceHandle;
      InBuf[3] = (int)hSourceHandle;
      if ( ghDriverHandle == (HANDLE)-1
        || !DeviceIoControl(ghDriverHandle, 0x83350014, InBuf, 0x10u, &pTargetHandle, 4u, &v12, 0) )
      {
        DesiredAccess = dwDesiredAccess;
        TargetHandle = GetCurrentProcess();
        DuplicateHandle(ProcessHandle, SourceHandle, TargetHandle, (LPHANDLE)&pTargetHandle, DesiredAccess, 0, 0);
      }
    }
    else
    {
      v5 = dwDesiredAccess;
      v6 = GetCurrentProcess();
      DuplicateHandle(ProcessHandle, hSourceHandle, v6, (LPHANDLE)&pTargetHandle, v5, 0, 0);
    }
    CloseHandle(ProcessHandle);
  }
  return pTargetHandle;
}

//----- (00C52330) --------------------------------------------------------
CHAR *__thiscall sub_C52330(CString *this, int Length)
{
  int nLength; // esi
  CString *v3; // edi
  CHAR *v4; // ecx
  CHAR *result; // eax
  signed int v6; // ecx
  int v7; // ecx
  int v8; // ecx

  nLength = Length;
  v3 = this;
  v4 = this->pszData;
  if ( *((_DWORD *)v4 - 3) > Length )
    nLength = *((_DWORD *)v4 - 3);
  if ( *((_DWORD *)v4 - 1) > 1 )
    return ATL::CSimpleStringT<wchar_t,0>::Fork(v3, nLength);
  v6 = *((_DWORD *)v4 - 2);
  if ( v6 < nLength )
  {
    if ( v6 <= 0x40000000 )
    {
      v8 = v6 / 2 + v6;
      if ( v8 < nLength )
        v8 = nLength;
      result = sub_C5DE20(v3, v8);
    }
    else
    {
      v7 = v6 + 0x100000;
      if ( v7 < nLength )
        v7 = nLength;
      result = sub_C5DE20(v3, v7);
    }
  }
  return result;
}

//----- (00C523A0) --------------------------------------------------------
int __stdcall PageProcCPU(HWND hWnd, int a2, WPARAM wParam, LONG dwNewLong)
{
  HWND v4; // eax
  int result; // eax
  CResizer *v6; // eax
  LONG v7; // eax
  HWND (__stdcall *v8)(HWND, int); // esi
  HWND v9; // edi
  HWND v10; // esi
  HWND v11; // edi
  HWND v12; // esi
  HWND v13; // edi
  HWND v14; // esi
  CResizer *v15; // edi
  HWND v16; // eax
  HWND v17; // ST2C_4
  HWND v18; // eax
  HWND v19; // ST2C_4
  HWND v20; // eax
  HWND v21; // ST2C_4
  HWND v22; // eax
  HWND v23; // eax
  HWND v24; // eax
  HWND v25; // eax
  HWND v26; // eax
  HWND v27; // eax
  HWND v28; // eax
  HWND v29; // eax
  HWND v30; // eax
  WPARAM v31; // [esp-8h] [ebp-38h]
  CResizer *v32; // [esp+10h] [ebp-20h]
  HWND v33; // [esp+14h] [ebp-1Ch]
  HWND v34; // [esp+18h] [ebp-18h]
  HWND v35; // [esp+1Ch] [ebp-14h]
  int v36; // [esp+2Ch] [ebp-4h]

  GetWindowLongW(hWnd, -21);
  if ( (unsigned int)a2 > 0x113 )
  {
    if ( a2 == 307 || a2 == 310 || a2 == 312 )
      return PE_FillControl((int)hWnd, (HDC)wParam);
    return 0;
  }
  if ( a2 == 275 || a2 == 5 )
  {
    if ( IsWindowVisible(hWnd) )
    {
      v25 = GetDlgItem(hWnd, 1158);
      SendMessageW(v25, 0x400u, 0, 0);
      v26 = GetDlgItem(hWnd, 2000);
      SendMessageW(v26, 0x400u, 0, 0);
      v27 = GetDlgItem(hWnd, 1161);
      SendMessageW(v27, 0x400u, 0, 0);
      v28 = GetDlgItem(hWnd, 1159);
      SendMessageW(v28, 0x400u, 0, 0);
      v29 = GetDlgItem(hWnd, 1332);
      SendMessageW(v29, 0x400u, 0, 0);
      v30 = GetDlgItem(hWnd, 1330);
      SendMessageW(v30, 0x400u, 0, 0);
      return 0;
    }
    return 0;
  }
  if ( a2 != 272 )
  {
    if ( a2 == 273 )
    {
      switch ( (unsigned __int16)wParam )
      {
        case 0x9C41u:
          v31 = 40014;
          goto LABEL_8;
        case 0x9C42u:
          SetEvent(ghRefreshEventHandle);
          result = 0;
          break;
        case 0x9C9Cu:
        case 0x9C9Du:
          v31 = wParam;
LABEL_8:
          v4 = GetParent(hWnd);
          PostMessageW(v4, 0x111u, v31, 0);
          result = 0;
          break;
        default:
          return 0;
      }
      return result;
    }
    return 0;
  }
  v6 = (CResizer *)operator new(0x40u);
  v36 = 0;
  if ( v6 )
    v32 = CResizer::CResizer(v6, hWnd);
  else
    v32 = 0;
  v36 = -1;
  v7 = GetWindowLongW(hWnd, -16);
  SetWindowLongW(hWnd, -16, v7 | 0x2000000);
  SetWindowLongW(hWnd, -21, dwNewLong);
  CreateGraphWindow(hWnd, 1158, *(PVOID *)(dwNewLong + 1372));
  CreateGraphWindow(hWnd, 2000, *(PVOID *)(dwNewLong + 1372));
  CreateGraphWindow(hWnd, 1161, *(PVOID *)(dwNewLong + 908));
  CreateGraphWindow(hWnd, 1159, *(PVOID *)(dwNewLong + 908));
  if ( *(_DWORD *)(dwNewLong + 1064) )
  {
    CreateGraphWindow(hWnd, 1332, *(PVOID *)(dwNewLong + 1064));
    CreateGraphWindow(hWnd, 1330, *(PVOID *)(dwNewLong + 1064));
  }
  v8 = GetDlgItem;
  if ( *(_DWORD *)(dwNewLong + 1064) )
  {
    v9 = GetDlgItem(hWnd, 1331);
    v10 = GetDlgItem(hWnd, 1160);
    v33 = GetDlgItem(hWnd, 1157);
    v34 = v10;
    v35 = v9;
    sub_C60550(v32, 3, (int)&v33);
    v11 = GetDlgItem(hWnd, 1332);
    v12 = GetDlgItem(hWnd, 1161);
    v33 = GetDlgItem(hWnd, 1158);
    v34 = v12;
    v35 = v11;
    sub_C60550(v32, 3, (int)&v33);
    v13 = GetDlgItem(hWnd, 1330);
    v14 = GetDlgItem(hWnd, 1159);
    v33 = GetDlgItem(hWnd, 2000);
    v35 = v13;
    v15 = v32;
    v34 = v14;
    sub_C60550(v32, 3, (int)&v33);
    v8 = GetDlgItem;
    v16 = GetDlgItem(hWnd, 1331);
    *(double *)&CResizer::AddItem(v32, v16, 1)->gap0[24] = db_four;
  }
  else
  {
    v17 = GetDlgItem(hWnd, 1160);
    v18 = GetDlgItem(hWnd, 1157);
    v15 = v32;
    sub_C604E0(v32, (int)v18, (int)v17);
    v19 = GetDlgItem(hWnd, 1161);
    v20 = GetDlgItem(hWnd, 1158);
    sub_C604E0(v32, (int)v20, (int)v19);
    v21 = GetDlgItem(hWnd, 1159);
    v22 = GetDlgItem(hWnd, 2000);
    sub_C604E0(v32, (int)v22, (int)v21);
  }
  v23 = v8(hWnd, 1157);
  *(double *)&CResizer::AddItem(v15, v23, 1)->gap0[24] = db_four;
  v24 = v8(hWnd, 1160);
  *(double *)&CResizer::AddItem(v15, v24, 1)->gap0[24] = db_four;
  PropSheet_UpdateTab(hWnd);
  SendMessageW(hWnd, 0x113u, 0, 0);
  return 1;
}
// CACB38: using guessed type double db_four;

//----- (00C52810) --------------------------------------------------------
int __stdcall PageProcEnv(HWND hWnd, int a2, WPARAM wParam, int a4)
{
  HWND v4; // ebx
  CResizer *v5; // eax
  LONG v6; // eax
  void (__stdcall *v7)(HWND, UINT, WPARAM, LPARAM); // edi
  HWND v8; // eax
  __int16 *v9; // esi
  __int16 *v10; // ecx
  int v11; // edi
  __int16 i; // ax
  LRESULT v13; // edx
  char *v14; // ecx
  __int16 v15; // ax
  HWND v17; // eax
  LRESULT v18; // esi
  WPARAM v19; // [esp-8h] [ebp-2ACh]
  LPARAM v20; // [esp+10h] [ebp-294h]
  int v21; // [esp+1Ch] [ebp-288h]
  int v22; // [esp+20h] [ebp-284h]
  void *v23; // [esp+44h] [ebp-260h]
  LPARAM lParam; // [esp+48h] [ebp-25Ch]
  LRESULT v25; // [esp+4Ch] [ebp-258h]
  int v26; // [esp+50h] [ebp-254h]
  int v27; // [esp+54h] [ebp-250h]
  int v28; // [esp+58h] [ebp-24Ch]
  __int16 *v29; // [esp+5Ch] [ebp-248h]
  int v30; // [esp+64h] [ebp-240h]
  int v31; // [esp+68h] [ebp-23Ch]
  UINT pnIDs; // [esp+7Ch] [ebp-228h]
  int v33; // [esp+80h] [ebp-224h]
  WORD pnWidths[2]; // [esp+84h] [ebp-220h]
  LPMEASUREITEMSTRUCT lpmis; // [esp+88h] [ebp-21Ch]
  __int16 v36; // [esp+8Ch] [ebp-218h]
  int v37; // [esp+2A0h] [ebp-4h]

  lpmis = (LPMEASUREITEMSTRUCT)a4;
  GetWindowLongW(hWnd, -21);
  lParam = 0;
  memset(&v25, 0, 0x30u);
  v4 = GetDlgItem(hWnd, 1055);
  pnIDs = 1057;
  v33 = 1058;
  pnWidths[0] = MulDiv(100, gLogPixelSize.x, 96);
  pnWidths[1] = MulDiv(100, gLogPixelSize.x, 96);
  if ( (unsigned int)a2 > 0x111 )
  {
    if ( a2 == 307 || a2 == 310 || a2 == 312 )
      return PE_FillControl((int)hWnd, (HDC)wParam);
    return 0;
  }
  switch ( a2 )
  {
    case 273:
      if ( (signed int)(unsigned __int16)wParam <= 40093 )
      {
        if ( (signed int)(unsigned __int16)wParam >= 40092 )
        {
          v19 = wParam;
        }
        else
        {
          if ( (unsigned __int16)wParam != 40001 )
            return 0;
          v19 = 40014;
        }
        v17 = GetParent(hWnd);
        PostMessageW(v17, 0x111u, v19, 0);
        return 0;
      }
      if ( (unsigned __int16)wParam == 40631 )
      {
        v18 = 0;
        if ( SendMessageW(v4, 0x1004u, 0, 0) > 0 )
        {
          do
          {
            v22 = 2;
            v21 = 2;
            SendMessageW(v4, 0x102Bu, v18++, (LPARAM)&v20);
          }
          while ( v18 < SendMessageW(v4, 0x1004u, 0, 0) );
          return 0;
        }
      }
      return 0;
    case 43:
      CMainWnd::DrawItem((LPDRAWITEMSTRUCT)lpmis);
      return 0;
    case 44:
      return CMainWnd::HandleMeasureItem(hWnd, 0x2Cu, wParam, lpmis);
  }
  if ( a2 != 272 )
    return 0;
  v5 = (CResizer *)operator new(0x40u);
  v23 = v5;
  v37 = 0;
  if ( v5 )
    CResizer::CResizer(v5, hWnd);
  PropSheet_UpdateTab(hWnd);
  v6 = GetWindowLongW(v4, -16);
  SetWindowLongW(v4, -16, v6 & 0xFFFFFFFD | 1);
  v7 = (void (__stdcall *)(HWND, UINT, WPARAM, LPARAM))SendMessageW;
  SendMessageW(v4, 0x1036u, 0x4020u, 16416);
  v8 = (HWND)SendMessageW(v4, 0x104Eu, 0, 0);
  CTreeList::InitToolTips(v8);
  SetWindowLongW(v4, -4, (LONG)Proxy_ListCtrlWndProc);
  SendMessageW(v4, 0x30u, (WPARAM)ghConfigFont, 0);
  InitListHeader(v4, &pnIDs, pnWidths, 2);
  v9 = (__int16 *)lpmis[33].itemHeight;
  if ( v9 )
  {
    while ( *v9 )
    {
      v10 = &v36;
      v36 = 0;
      v11 = 0;
      for ( i = *v9; i; ++v9 )
      {
        if ( !v11 )
        {
          if ( i == 61 )
          {
            v11 = (int)(v9 + 1);
            *v10 = 0;
          }
          else
          {
            *v10 = i;
            ++v10;
          }
        }
        i = v9[1];
      }
      lParam = 5;
      v29 = &v36;
      v25 = 0x7FFFFFFF;
      v26 = 0;
      v27 = 0;
      v28 = 0;
      v30 = 0;
      v31 = 1;
      v13 = SendMessageW(v4, 0x104Du, 0, (LPARAM)&lParam);
      if ( v13 == -1 )
        return 0;
      if ( v11 )
      {
        v14 = (char *)v11;
        lpmis = (LPMEASUREITEMSTRUCT)(v11 + 2);
        do
        {
          v15 = *(_WORD *)v14;
          v14 += 2;
        }
        while ( v15 );
        if ( (unsigned int)((v14 - (char *)lpmis) >> 1) > 0x1FFF )
          *(_WORD *)(v11 + 16382) = 0;
        v29 = (__int16 *)v11;
        v7 = (void (__stdcall *)(HWND, UINT, WPARAM, LPARAM))SendMessageW;
        lParam = 1;
        v25 = v13;
        v26 = 1;
        SendMessageW(v4, 0x104Cu, 0, (LPARAM)&lParam);
      }
      else
      {
        v7 = (void (__stdcall *)(HWND, UINT, WPARAM, LPARAM))SendMessageW;
      }
      ++v9;
      if ( !v9 )
        break;
    }
  }
  v7(v4, 0x101Eu, 0, 0xFFFF);
  v7(v4, 0x101Eu, 1u, 0xFFFF);
  return 1;
}

//----- (00C52C20) --------------------------------------------------------
HBRUSH __stdcall PageProcInfo(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
  HWND v4; // ebx
  tagTREEVIEWLISTITEMPARAM *pItem; // edx
  const wchar_t **v6; // esi
  CResizer *v7; // eax
  CResizer *v8; // eax
  HWND v9; // eax
  struct tagResizerItem *v10; // eax
  HWND v11; // eax
  struct tagResizerItem *v12; // eax
  bool v13; // zf
  void *v14; // ST08_4
  void *v15; // ST04_4
  void *v16; // ST00_4
  const WCHAR *v17; // edi
  const WCHAR *v18; // eax
  BOOL v19; // ST2C_4
  HWND v20; // eax
  tagTREEVIEWLISTITEMPARAM *pUserData; // edi
  BOOL v22; // ST2C_4
  HWND v23; // eax
  HWND v24; // eax
  int v25; // ebx
  HWND v26; // eax
  HWND v27; // eax
  char v28; // al
  HWND v29; // eax
  HWND v30; // eax
  HWND v31; // eax
  OLECHAR *v32; // ST2C_4
  _bstr_t *v33; // edi
  _bstr_t *v34; // eax
  _bstr_t *v35; // eax
  _bstr_t *v36; // eax
  const WCHAR *v37; // eax
  WCHAR *v38; // eax
  HWND v39; // eax
  WCHAR *v40; // eax
  int v41; // ST2C_4
  HWND v42; // eax
  HWND v43; // eax
  WCHAR *v44; // eax
  HWND v45; // eax
  DWORD v46; // edi
  WCHAR *v47; // edi
  wchar_t *v48; // eax
  HICON v49; // eax
  LPARAM v50; // ST2C_4
  HWND v51; // eax
  HICON v52; // eax
  LPARAM v53; // ST2C_4
  HWND v54; // eax
  HICON v55; // eax
  LPARAM v56; // ST2C_4
  HWND v57; // eax
  int v58; // eax
  int v59; // ST2C_4
  HWND v60; // eax
  HBRUSH v61; // edi
  const unsigned __int16 *v62; // eax
  int v63; // eax
  HWND v64; // eax
  int v65; // ST2C_4
  HWND v66; // eax
  WCHAR *v67; // eax
  HWND v68; // eax
  tagTREEVIEWLISTITEMPARAM *v69; // edi
  char v70; // cl
  ListItemData1 *v71; // eax
  int v72; // ST2C_4
  HWND v73; // eax
  HWND v75; // eax
  WPARAM v76; // [esp-8h] [ebp-1664h]
  struct _FILETIME LocalFileTime; // [esp+10h] [ebp-164Ch]
  DWORD dwHandle; // [esp+18h] [ebp-1644h]
  _bstr_t v79; // [esp+1Ch] [ebp-1640h]
  _bstr_t v80; // [esp+20h] [ebp-163Ch]
  _bstr_t v81; // [esp+24h] [ebp-1638h]
  _bstr_t bstrRet; // [esp+28h] [ebp-1634h]
  DWORD pdwValue5; // [esp+2Ch] [ebp-1630h]
  char v84[5]; // [esp+33h] [ebp-1629h]
  tagTREEVIEWLISTITEMPARAM *lParama; // [esp+38h] [ebp-1624h]
  HANDLE hObject; // [esp+3Ch] [ebp-1620h]
  tagTREEVIEWLISTITEMPARAM *lpString; // [esp+40h] [ebp-161Ch]
  const wchar_t **pUserdata; // [esp+44h] [ebp-1618h]
  WPARAM uID; // [esp+48h] [ebp-1614h]
  WCHAR *ppszCommandLine; // [esp+4Ch] [ebp-1610h]
  const SYSTEMTIME v91; // [esp+50h] [ebp-160Ch]
  wchar_t v92[1024]; // [esp+60h] [ebp-15FCh]
  __int16 DateStr[256]; // [esp+860h] [ebp-DFCh]
  WCHAR v94[246]; // [esp+A60h] [ebp-BFCh]
  __int16 Dest[256]; // [esp+C4Ch] [ebp-A10h]
  __int16 String[1024]; // [esp+E4Ch] [ebp-810h]
  int v97; // [esp+1658h] [ebp-4h]

  v4 = hWnd;
  *(_DWORD *)&v84[1] = hWnd;
  uID = wParam;
  lParama = (tagTREEVIEWLISTITEMPARAM *)lParam;
  pItem = (tagTREEVIEWLISTITEMPARAM *)GetWindowLongW(hWnd, -21);
  v6 = 0;
  lpString = pItem;
  pUserdata = 0;
  v97 = 0;
  switch ( msg )
  {
    case WM_INITDIALOG:
      v7 = (CResizer *)operator new(0x40u);
      pdwValue5 = (DWORD)v7;
      LOBYTE(v97) = 1;
      if ( v7 )
        v8 = CResizer::CResizer(v7, hWnd);
      else
        v8 = 0;
      uID = (WPARAM)v8;
      LOBYTE(v97) = 0;
      v8->m_nXRatio = 85;
      v8->m_nYRatio = 100;
      v9 = GetDlgItem(hWnd, IDC_DLG_DLLINFO_EDIT_PATH);
      if ( v9 )
      {
        v10 = CResizer::AddItem((CResizer *)uID, v9, 1);
        *(_QWORD *)v10->gap0 = 0i64;
        *(double *)&v10->gap0[8] = db_one;
      }
      v11 = GetDlgItem(hWnd, 1656);
      if ( v11 )
      {
        v12 = CResizer::AddItem((CResizer *)uID, v11, 1);
        *(_QWORD *)v12->gap0 = 0i64;
        *(double *)&v12->gap0[8] = db_one;
      }
      SetWindowLongW(hWnd, -21, lParam);
      wsprintfW((wchar_t *)String, L"%s(%08X) (netsvcs) Properties", *(_DWORD *)(lParam + 60), *(_DWORD *)(lParam + 68));
      SetWindowTextW(hWnd, (LPCWSTR)String);
      v13 = (*(_DWORD *)(lParam + 40) & 0x100) == 0;
      lpString = *(tagTREEVIEWLISTITEMPARAM **)(lParam + 792);
      if ( !v13 )
        SetDlgItemTextW(hWnd, 106, L"Path (Image is probably packed):");
      hObject = PE_OpenProcess(0x2000000u, 0, *(_DWORD *)(lParam + 68));
      QueryProcessArguments(
        hObject,
        *(_DWORD *)(lParam + 68),
        &ppszCommandLine,
        (WCHAR **)&uID,
        (WCHAR **)&pdwValue5,
        (PDWORD)v84);
      v14 = *(void **)(lParam + 800);
      *(_DWORD *)(lParam + 800) = ppszCommandLine;
      free(v14);
      v15 = *(void **)(lParam + 804);
      *(_DWORD *)(lParam + 804) = uID;
      free(v15);
      v16 = *(void **)(lParam + 808);
      *(_DWORD *)(lParam + 808) = pdwValue5;
      free(v16);
      SetDlgItemTextW(hWnd, 1032, *(LPCWSTR *)(lParam + 800));
      SetDlgItemTextW(hWnd, 1035, *(LPCWSTR *)(lParam + 804));
      v17 = L"n/a";
      v18 = L"n/a";
      if ( lpString )
        v18 = (const WCHAR *)lpString;
      SetDlgItemTextW(hWnd, 1015, v18);
      SetDlgItemTextW(hWnd, 1190, (LPCWSTR)lParama->pszComments);
      if ( lParama->field_33C )
        v17 = (const WCHAR *)lParama->field_33C;
      SetDlgItemTextW(hWnd, 1656, v17);
      v19 = lpString != 0;
      v20 = GetDlgItem(hWnd, 1307);
      EnableWindow(v20, v19);
      pUserData = lParama;
      v22 = lParama->field_33C != 0;
      v23 = GetDlgItem(hWnd, 1306);
      EnableWindow(v23, v22);
      v24 = GetDlgItem(hWnd, 1195);
      ShowWindow(v24, 0);
      if ( gbIsProcessDEPEnabled )
      {
        Fake_GetProcessMitigationPolicy(pUserData, hObject);
        v25 = pUserData->ProcessMitigationPolicy;
        if ( (_BYTE)v25 == -1 )
        {
          wcscpy_s((wchar_t *)String, 0x400u, L"n/a");
        }
        else
        {
          if ( v25 & 1 )
            wcscpy_s((wchar_t *)String, 0x400u, L"Enabled");
          else
            wcscpy_s((wchar_t *)String, 0x400u, L"Disabled");
          if ( v25 & 8 )
            wcscat_s((wchar_t *)String, 0x400u, L" (permanent)");
        }
        v4 = *(HWND *)&v84[1];
        SetDlgItemTextW(*(HWND *)&v84[1], 1202, (LPCWSTR)String);
      }
      else
      {
        v26 = GetDlgItem(hWnd, 1203);
        ShowWindow(v26, 0);
        v27 = GetDlgItem(hWnd, 1202);
        ShowWindow(v27, 0);
      }
      if ( gdwVersion >= 3 && hObject )
      {
        if ( Fske_GetProcessMitigationPolicy((int)hObject, 1, (int)&uID, 4) )
        {
          _bstr_t::operator=((EventItem *)&pUserdata, (OLECHAR *)&gszNullString);
          v28 = uID;
          if ( uID & 8 )
          {
            _bstr_t::_bstr_t((tagEventSetItem *)&ppszCommandLine, L"Disallow-Stripped");
            LOBYTE(v97) = 2;
            _bstr_t::operator+=((_bstr_t *)&pUserdata, (_bstr_t *)&ppszCommandLine);
            LOBYTE(v97) = 0;
            _bstr_t::_Free((_bstr_t *)&ppszCommandLine);
            v28 = uID;
          }
          if ( v28 & 4 )
          {
            if ( _bstr_t::length((tagEventItem *)&pUserdata) )
            {
              _bstr_t::_bstr_t((tagEventSetItem *)&ppszCommandLine, L", ");
              LOBYTE(v97) = 3;
              _bstr_t::operator+=((_bstr_t *)&pUserdata, (_bstr_t *)&ppszCommandLine);
              LOBYTE(v97) = 0;
              _bstr_t::_Free((_bstr_t *)&ppszCommandLine);
            }
            _bstr_t::_bstr_t((tagEventSetItem *)&ppszCommandLine, L"High-Entropy");
            LOBYTE(v97) = 4;
            _bstr_t::operator+=((_bstr_t *)&pUserdata, (_bstr_t *)&ppszCommandLine);
            LOBYTE(v97) = 0;
            _bstr_t::_Free((_bstr_t *)&ppszCommandLine);
            v28 = uID;
          }
          if ( v28 & 1 )
          {
            if ( _bstr_t::length((tagEventItem *)&pUserdata) )
            {
              _bstr_t::_bstr_t((tagEventSetItem *)&ppszCommandLine, L", ");
              LOBYTE(v97) = 5;
              _bstr_t::operator+=((_bstr_t *)&pUserdata, (_bstr_t *)&ppszCommandLine);
              LOBYTE(v97) = 0;
              _bstr_t::_Free((_bstr_t *)&ppszCommandLine);
            }
            _bstr_t::_bstr_t((tagEventSetItem *)&ppszCommandLine, L"Bottom-Up");
            LOBYTE(v97) = 6;
            _bstr_t::operator+=((_bstr_t *)&pUserdata, (_bstr_t *)&ppszCommandLine);
            LOBYTE(v97) = 0;
            _bstr_t::_Free((_bstr_t *)&ppszCommandLine);
            v28 = uID;
          }
          if ( v28 & 2 )
          {
            if ( _bstr_t::length((tagEventItem *)&pUserdata) )
            {
              _bstr_t::_bstr_t((tagEventSetItem *)&ppszCommandLine, L", ");
              LOBYTE(v97) = 7;
              _bstr_t::operator+=((_bstr_t *)&pUserdata, (_bstr_t *)&ppszCommandLine);
              LOBYTE(v97) = 0;
              _bstr_t::_Free((_bstr_t *)&ppszCommandLine);
            }
            _bstr_t::_bstr_t((tagEventSetItem *)&ppszCommandLine, L"Force-Relocate");
            LOBYTE(v97) = 8;
            _bstr_t::operator+=((_bstr_t *)&pUserdata, (_bstr_t *)&ppszCommandLine);
            LOBYTE(v97) = 0;
            _bstr_t::_Free((_bstr_t *)&ppszCommandLine);
          }
          if ( _bstr_t::length((tagEventItem *)&pUserdata) )
          {
            v6 = pUserdata;
            if ( pUserdata )
              wcscpy_s((wchar_t *)String, 0x400u, *pUserdata);
            else
              wcscpy_s((wchar_t *)String, 0x400u, 0);
          }
          else
          {
            wcscat_s((wchar_t *)String, 0x400u, L"Disabled");
            v6 = pUserdata;
          }
        }
        else
        {
          GetErrorMsg((wchar_t *)String, 0x400u);
        }
      }
      else
      {
        if ( gdwVersion < 1 )
        {
          v29 = GetDlgItem(v4, 1204);
          ShowWindow(v29, 0);
          v30 = GetDlgItem(v4, 1205);
          ShowWindow(v30, 0);
          goto LABEL_56;
        }
        if ( pUserData->field_28A & 0x40 )
        {
          wcscpy_s((wchar_t *)String, 0x400u, L"Enabled");
        }
        else if ( pUserData->field_288 )
        {
          wcscpy_s((wchar_t *)String, 0x400u, L"Disabled");
        }
        else
        {
          wcscpy_s((wchar_t *)String, 0x400u, L"n/a");
        }
      }
      SetDlgItemTextW(v4, 1205, (LPCWSTR)String);
LABEL_56:
      if ( gdwVersion < 4 )
      {
        v31 = GetDlgItem(v4, 1666);
        ShowWindow(v31, 0);
      }
      else
      {
        if ( pUserData->field_28A & 0x4000 )
        {
          wcscpy_s((wchar_t *)String, 0x400u, L"Enabled");
        }
        else if ( pUserData->field_288 && pUserData->field_28A )
        {
          wcscpy_s((wchar_t *)String, 0x400u, L"Disabled");
        }
        else
        {
          wcscpy_s((wchar_t *)String, 0x400u, L"n/a");
        }
        SetDlgItemTextW(v4, 1666, (LPCWSTR)String);
      }
      if ( hObject )
        CloseHandle(hObject);
      if ( pUserData->pszTitle )
      {
        _bstr_t::_bstr_t((tagEventSetItem *)&hObject, (OLECHAR *)pUserData->pszTitle);
        v13 = pUserData->pszPackageFullName == 0;
        LOBYTE(v97) = 9;
        if ( !v13 )
        {
          _bstr_t::_bstr_t((tagEventSetItem *)&ppszCommandLine, L")");
          v32 = (OLECHAR *)pUserData->pszPackageFullName;
          LOBYTE(v97) = 10;
          v33 = (_bstr_t *)_bstr_t::_bstr_t((tagEventSetItem *)&v81, v32);
          LOBYTE(v97) = 11;
          v34 = (_bstr_t *)_bstr_t::_bstr_t((tagEventSetItem *)&v79, L" (");
          LOBYTE(v97) = 12;
          v35 = _bstr_t::operator+(v34, &bstrRet, v33);
          LOBYTE(v97) = 13;
          v36 = _bstr_t::operator+(v35, &v80, (_bstr_t *)&ppszCommandLine);
          LOBYTE(v97) = 14;
          _bstr_t::operator+=((_bstr_t *)&hObject, v36);
          _bstr_t::_Free(&v80);
          _bstr_t::_Free(&bstrRet);
          _bstr_t::_Free(&v79);
          _bstr_t::_Free(&v81);
          _bstr_t::_Free((_bstr_t *)&ppszCommandLine);
          pUserData = lParama;
        }
        if ( hObject )
          v37 = *(const WCHAR **)hObject;
        else
          v37 = 0;
        SetDlgItemTextW(v4, 1183, v37);
        LOBYTE(v97) = 0;
        _bstr_t::_Free((_bstr_t *)&hObject);
      }
      v38 = VerifyImage(pUserData, gConfig.bVerifySignatures);
      SetDlgItemTextW(v4, 3, v38);
      v39 = GetDlgItem(v4, IDC_DLG_DLLINFO_EDIT_VIRUSTOTAL);
      SetWindowSubclass(v39, EditVTClassCallback, 0, 0);
      sub_C71A50((int)pUserData->m_ItemDataForVirusTotal, (wchar_t *)String);
      SetDlgItemTextW(v4, IDC_DLG_DLLINFO_EDIT_VIRUSTOTAL, (LPCWSTR)String);
      v40 = pUserData->szProcessName;
      if ( v40 && *v40 != 91 )
      {
        v41 = (unsigned __int8)sub_C71C10(pUserData->m_ItemDataForVirusTotal);
        v42 = GetDlgItem(v4, IDC_DLG_DLLINFO_BUTTON_SUBMIT);
        EnableWindow(v42, v41);
      }
      if ( gbWintrustInited )
      {
        if ( pUserData->dwVerifyValue || (v44 = pUserData->szProcessName) == 0 || *v44 == '[' )
        {
          v45 = GetDlgItem(v4, IDC_DLG_DLLINFO_BUTTON_VERIFY);
          EnableWindow(v45, 0);
        }
      }
      else
      {
        v43 = GetDlgItem(v4, 1005);
        ShowWindow(v43, 0);
      }
      wsprintfW((wchar_t *)String, L"n/a");
      if ( lpString )
      {
        v84[1] = unknown_libname_2(255);
        v46 = GetFileVersionInfoSizeW((LPCWSTR)lpString, &dwHandle);
        ppszCommandLine = (WCHAR *)malloc(v46);
        if ( GetFileVersionInfoW((LPCWSTR)lpString, 0, v46, ppszCommandLine) )
        {
          v47 = ppszCommandLine;
          PE_MakeFileVersion2(*((_DWORD *)ppszCommandLine + 13), *((_DWORD *)ppszCommandLine + 12), (wchar_t *)String);
        }
        else
        {
          wsprintfW((wchar_t *)String, L"n/a");
          v47 = ppszCommandLine;
        }
        free(v47);
        unknown_libname_2(v84[1]);
        pUserData = lParama;
      }
      SetDlgItemTextW(v4, 25, (LPCWSTR)String);
      if ( pUserData->dwTimeDateStamp )
        v48 = _wctime32(&pUserData->dwTimeDateStamp);
      else
        v48 = L"n/a";
      SetDlgItemTextW(v4, 30, v48);
      v49 = (HICON)pUserData->hFileIcon;
      if ( !v49 )
        v49 = LoadIconW(0, (LPCWSTR)0x7F00);
      v50 = (LPARAM)v49;
      v51 = GetDlgItem(v4, 1033);
      SendMessageW(v51, 0x172u, 1u, v50);
      v52 = (HICON)pUserData->hFileIcon;
      if ( !v52 )
        v52 = LoadIconW(0, (LPCWSTR)0x7F00);
      v53 = (LPARAM)v52;
      v54 = GetParent(v4);
      SendMessageW(v54, 0x80u, 1u, v53);
      if ( pUserData->hFileIcon )
        v55 = pUserData->hIcon;
      else
        v55 = LoadIconW(0, (LPCWSTR)0x7F00);
      v56 = (LPARAM)v55;
      v57 = GetParent(v4);
      SendMessageW(v57, 0x80u, 0, v56);
      SetDlgItemTextW(v4, 35, (LPCWSTR)pUserData->pszSystemName);
      wsprintfW((wchar_t *)String, L"%d K", (unsigned int)pUserData->WorkingSetSize >> 10);
      SetDlgItemTextW(v4, 1008, (LPCWSTR)String);
      wsprintfW((wchar_t *)String, L"%d K", (unsigned int)pUserData->PagefileUsage >> 10);
      SetDlgItemTextW(v4, 1009, (LPCWSTR)String);
      if ( pUserData->CreateTime )
      {
        FileTimeToLocalFileTime(&pUserData->CreateTime, &LocalFileTime);
        FileTimeToSystemTime(&LocalFileTime, (LPSYSTEMTIME)&v91);
        GetTimeFormatW(0x400u, 0, &v91, 0, (LPWSTR)String, 512);
        GetDateFormatW(0x400u, 0, &v91, 0, (LPWSTR)DateStr, 128);
        wcscat_s((wchar_t *)String, 0x400u, L"   ");
        wcscat_s((wchar_t *)String, 0x400u, (const wchar_t *)DateStr);
      }
      else
      {
        wcscpy_s((wchar_t *)String, 0x400u, L"n/a");
      }
      SetDlgItemTextW(v4, 1007, (LPCWSTR)String);
      SetDlgItemTextW(v4, 19, (LPCWSTR)pUserData->pszName);
      PropSheet_UpdateTab(v4);
      ShowWindow(v4, 1);
      goto LABEL_141;
    case WM_COMMAND:
      if ( (signed int)(unsigned __int16)uID > 1306 )
      {
        if ( (signed int)(unsigned __int16)uID > 40001 )
        {
          if ( (unsigned __int16)uID == 40002 )
          {
            SetEvent(ghRefreshEventHandle);
            return 0;
          }
          if ( (unsigned int)(unsigned __int16)uID - 40092 > 1 )
            return 0;
          v76 = uID;
        }
        else
        {
          if ( (unsigned __int16)uID != 40001 )
          {
            if ( (unsigned __int16)uID == IDC_PAGE_PROCINFO_BUTTON_EXPLORE_PATH )
            {
              PE_LaunchExe(hWnd, (CCmdString *)pItem->szProcessName);
              goto LABEL_141;
            }
            if ( (unsigned __int16)uID != 1671 )
              return 0;
            if ( SubmitExeToVirusTotalDotCom() )
            {
              v69 = lpString;
              v70 = 0;
              v71 = lpString->m_ItemDataForVirusTotal;
              if ( v71 )
              {
                v70 = 1;
                v71->field_4 = 6;
              }
              sub_C71C30((tagDLLLISTITEMPARAM *)v69, 1, v70 != 0);
              v72 = (unsigned __int8)sub_C71C10(v69->m_ItemDataForVirusTotal);
              v73 = GetDlgItem(hWnd, 1671);
              EnableWindow(v73, v72);
              sub_C71A50((int)v69->m_ItemDataForVirusTotal, (wchar_t *)Dest);
              SetDlgItemTextW(hWnd, 1672, (LPCWSTR)Dest);
              PostMessageW(ghMainWnd, 0x7F9u, 0, (LPARAM)v69->m_ItemDataForVirusTotal);
            }
            goto LABEL_141;
          }
          v76 = 40014;
        }
        v75 = GetParent(hWnd);
        PostMessageW(v75, 0x111u, v76, 0);
        return 0;
      }
      if ( (unsigned __int16)uID == 1306 )
      {
        PE_LaunchExe(hWnd, (CCmdString *)pItem->field_33C);
        goto LABEL_141;
      }
      if ( (signed int)(unsigned __int16)uID > 1004 )
      {
        if ( (unsigned __int16)uID == 1005 )
        {
          v67 = VerifyImage(pItem, 1);
          SetDlgItemTextW(hWnd, 3, v67);
          v68 = GetDlgItem(hWnd, 1005);
          EnableWindow(v68, 0);
          goto LABEL_141;
        }
        if ( (unsigned __int16)uID == 1160 )
        {
          v65 = pItem->dwProcessId;
          v66 = GetParent(hWnd);
          sub_C36B90(v66, 40084, v65);
          RefreshMenuWithTreeViewItemStatus(lpString);
          goto LABEL_141;
        }
        return 0;
      }
      switch ( (unsigned __int16)uID )
      {
        case 0x3ECu:
          if ( PE_ConfirmToKillProcess(pItem->szProcessName2, pItem->dwProcessId) )
          {
            v64 = GetParent(hWnd);
            PostMessageW(v64, 0x471u, 5u, 0);
          }
          break;
        case 1u:
          GetDlgItemTextW(hWnd, 1190, v92, 1024);
          v62 = (const unsigned __int16 *)lpString->pszComments;
          if ( !v62 )
            goto LABEL_159;
          v63 = wcscmp(v92, v62);
          if ( v63 )
            v63 = -(v63 < 0) | 1;
          if ( v63 )
LABEL_159:
            sub_C362A0((int)lpString, v92);
          break;
        case 2u:
          break;
        default:
          return 0;
      }
LABEL_141:
      v61 = (HBRUSH)1;
LABEL_142:
      if ( v6 && !InterlockedDecrement((volatile LONG *)v6 + 2) )
      {
        if ( *v6 )
        {
          SysFreeString((BSTR)*v6);
          *v6 = 0;
        }
        if ( v6[1] )
        {
          operator delete[]((void *)v6[1]);
          v6[1] = 0;
        }
        operator delete(v6);
      }
      return v61;
    case WM_TIMER:
      GetDlgItemTextW(hWnd, 1672, v94, 245);
      sub_C71A50((int)lpString->m_ItemDataForVirusTotal, (wchar_t *)Dest);
      v58 = wcscmp(v94, (const unsigned __int16 *)Dest);
      if ( v58 )
        v58 = -(v58 < 0) | 1;
      if ( v58 )
      {
        SetDlgItemTextW(hWnd, 1672, (LPCWSTR)Dest);
        v59 = (unsigned __int8)sub_C71C10(lpString->m_ItemDataForVirusTotal);
        v60 = GetDlgItem(hWnd, 1671);
        EnableWindow(v60, v59);
      }
      goto LABEL_141;
    case WM_CTLCOLOREDIT:
    case WM_CTLCOLORDLG:
      goto LABEL_112;
    case WM_CTLCOLORSTATIC:
      if ( (HWND)lParam == GetDlgItem(hWnd, 1672) && sub_C71820(lpString->m_ItemDataForVirusTotal) )
      {
        if ( sub_C72910(lpString->m_ItemDataForVirusTotal) )
          SetTextColor((HDC)uID, 0xFFu);
        else
          SetTextColor((HDC)uID, 0xFF0000u);
        SelectObject((HDC)uID, ghDefaultUnderlineFontHandle);
        v61 = GetSysColorBrush(20);
      }
      else
      {
LABEL_112:
        v61 = (HBRUSH)PE_FillControl((int)hWnd, (HDC)uID);
      }
      goto LABEL_142;
    default:
      return 0;
  }
}
// CD4E54: using guessed type int gdwVersion;
// CDA390: using guessed type char gbIsProcessDEPEnabled;
// CDA391: using guessed type char gbWintrustInited;

//----- (00C53C50) --------------------------------------------------------
int __stdcall PageProcJob(HWND hWnd, int a2, WPARAM wParam, LONG dwNewLong)
{
  CResizer *v4; // eax
  void (__stdcall *v5)(HANDLE); // edi
  HWND v6; // edi
  LONG v7; // eax
  LRESULT (__stdcall *v8)(HWND, UINT, WPARAM, LPARAM); // esi
  DWORD *v9; // edi
  DWORD v10; // esi
  DWORD *v11; // eax
  HWND v12; // eax
  LRESULT v13; // eax
  HWND v14; // eax
  HWND v15; // ebx
  LONG v16; // eax
  HWND v17; // eax
  __int16 v18; // ax
  HANDLE v19; // esi
  char v20; // al
  void *v21; // edi
  DWORD v22; // esi
  int result; // eax
  HWND v24; // eax
  WPARAM v25; // [esp-8h] [ebp-1174h]
  LPARAM v26; // [esp+10h] [ebp-115Ch]
  int v27; // [esp+1Ch] [ebp-1150h]
  int v28; // [esp+20h] [ebp-114Ch]
  LPARAM lParam; // [esp+44h] [ebp-1128h]
  LRESULT v30; // [esp+48h] [ebp-1124h]
  int v31; // [esp+4Ch] [ebp-1120h]
  int v32; // [esp+50h] [ebp-111Ch]
  int v33; // [esp+54h] [ebp-1118h]
  wchar_t *v34; // [esp+58h] [ebp-1114h]
  int v35; // [esp+60h] [ebp-110Ch]
  HWND v36; // [esp+64h] [ebp-1108h]
  UINT v37; // [esp+78h] [ebp-10F4h]
  int v38; // [esp+7Ch] [ebp-10F0h]
  UINT pnIDs; // [esp+80h] [ebp-10ECh]
  int v40; // [esp+84h] [ebp-10E8h]
  DWORD dwValue4; // [esp+88h] [ebp-10E4h]
  HANDLE v42; // [esp+8Ch] [ebp-10E0h]
  WORD pnWidths[2]; // [esp+90h] [ebp-10DCh]
  _DWORD *v44; // [esp+94h] [ebp-10D8h]
  HANDLE hObject; // [esp+98h] [ebp-10D4h]
  HWND v46; // [esp+9Ch] [ebp-10D0h]
  HWND v47; // [esp+A0h] [ebp-10CCh]
  size_t ReturnLength; // [esp+A4h] [ebp-10C8h]
  int v49; // [esp+A8h] [ebp-10C4h]
  __int64 JobObjectInformation; // [esp+ACh] [ebp-10C0h]
  __int64 v51; // [esp+B4h] [ebp-10B8h]
  int v52; // [esp+BCh] [ebp-10B0h]
  unsigned int v53; // [esp+C0h] [ebp-10ACh]
  unsigned int v54; // [esp+C4h] [ebp-10A8h]
  char ArgList[4]; // [esp+C8h] [ebp-10A4h]
  char v56[4]; // [esp+CCh] [ebp-10A0h]
  char v57[4]; // [esp+D0h] [ebp-109Ch]
  char v58[4]; // [esp+D4h] [ebp-1098h]
  unsigned int v59; // [esp+10Ch] [ebp-1060h]
  unsigned int v60; // [esp+110h] [ebp-105Ch]
  wchar_t pszText; // [esp+11Ch] [ebp-1050h]
  wchar_t Dst; // [esp+91Ch] [ebp-850h]
  wchar_t v63; // [esp+111Ch] [ebp-50h]
  int v64; // [esp+1168h] [ebp-4h]

  GetWindowLongW(hWnd, -21);
  lParam = 0;
  memset(&v30, 0, 0x30u);
  pnIDs = 3;
  v40 = 4;
  v37 = 1075;
  v38 = 1058;
  pnWidths[0] = MulDiv(100, gLogPixelSize.x, 96);
  pnWidths[1] = MulDiv(100, gLogPixelSize.x, 96);
  if ( (unsigned int)a2 > 0x111 )
  {
    if ( a2 == 307 || a2 == 310 || a2 == 312 )
      return PE_FillControl((int)hWnd, (HDC)wParam);
    return 0;
  }
  switch ( a2 )
  {
    case 273:
      switch ( (unsigned __int16)wParam )
      {
        case 0x9C41u:
          v25 = 40014;
          goto LABEL_90;
        case 0x9C42u:
          SetEvent(ghRefreshEventHandle);
          result = 0;
          break;
        case 0x9C9Cu:
        case 0x9C9Du:
          v25 = wParam;
LABEL_90:
          v24 = GetParent(hWnd);
          PostMessageW(v24, 0x111u, v25, 0);
          result = 0;
          break;
        default:
          return 0;
      }
      return result;
    case 43:
      CMainWnd::DrawItem((LPDRAWITEMSTRUCT)dwNewLong);
      return 0;
    case 44:
      return CMainWnd::HandleMeasureItem(hWnd, 0x2Cu, wParam, (LPMEASUREITEMSTRUCT)dwNewLong);
  }
  if ( a2 != 272 )
    return 0;
  v4 = (CResizer *)operator new(0x40u);
  v42 = v4;
  v64 = 0;
  if ( v4 )
    CResizer::CResizer(v4, hWnd);
  v64 = -1;
  PropSheet_UpdateTab(hWnd);
  SetWindowLongW(hWnd, -21, dwNewLong);
  QuerySystemHandleInfo(1u);
  v42 = PE_OpenProcess(0x2000000u, 0, *(_DWORD *)(dwNewLong + 68));
  v5 = (void (__stdcall *)(HANDLE))CloseHandle;
  if ( PE_IsProcessInJob(v42, *(_DWORD *)(dwNewLong + 68), (DWORD *)&hObject, (DWORD)&dwValue4) )
  {
    if ( *(_WORD *)dwValue4 )
      SetDlgItemTextW(hWnd, 1075, (LPCWSTR)dwValue4);
    else
      SetDlgItemTextW(hWnd, 1075, L"<Unnamed Job>");
    v6 = GetDlgItem(hWnd, 1076);
    v46 = v6;
    v7 = GetWindowLongW(v6, -16);
    SetWindowLongW(v6, -16, v7 & 0xFFFFFFFD | 1);
    v8 = SendMessageW;
    SendMessageW(v6, 0x1036u, 0x4020u, 16416);
    gOldListWndProc = (WNDPROC)SetWindowLongW(v6, -4, (LONG)Proxy_ListCtrlWndProc);
    SendMessageW(v6, 0x30u, (WPARAM)ghConfigFont, 0);
    InitListHeader(v6, &pnIDs, pnWidths, 2);
    ReturnLength = 1200;
    v9 = (DWORD *)malloc(0x4B0u);
    if ( !QueryInformationJobObject(hObject, JobObjectBasicProcessIdList, v9, 0x4B0u, &ReturnLength) )
    {
      do
      {
        if ( GetLastError() != 24 )
          break;
        free(v9);
        v10 = ReturnLength;
        v9 = (DWORD *)malloc(ReturnLength);
      }
      while ( !QueryInformationJobObject(hObject, JobObjectBasicProcessIdList, v9, v10, &ReturnLength) );
      v8 = SendMessageW;
    }
    if ( v9 )
    {
      v47 = 0;
      if ( v9[1] )
      {
        v11 = v9 + 2;
        v44 = v9 + 2;
        do
        {
          SystemProcessInfo_GetSystemProcessName(*v11, 0, &pszText, 0x400u);
          wsprintf_s(&v63, L"%d", *v44);
          lParam = 5;
          v34 = &pszText;
          v12 = (HWND)((char *)v47 + 1);
          v30 = 0x7FFFFFFF;
          v47 = v12;
          v36 = v12;
          v31 = 0;
          v33 = 0;
          v32 = 0;
          v35 = 0;
          v13 = v8(v46, 0x104Du, 0, (LPARAM)&lParam);
          if ( v13 == -1 )
            return 0;
          v30 = v13;
          v34 = &v63;
          lParam = 1;
          v31 = 1;
          v8(v46, 0x104Cu, 0, (LPARAM)&lParam);
          v11 = v44 + 1;
          ++v44;
        }
        while ( (unsigned int)v47 < v9[1] );
      }
      v8(v46, 0x101Eu, 0, 0xFFFF);
      v8(v46, 0x101Eu, 1u, 65534);
      v28 = 3;
      v27 = 3;
      v8(v46, 0x102Bu, 0, (LPARAM)&v26);
      SetFocus(v46);
      free(v9);
    }
    v14 = GetDlgItem(hWnd, 1077);
    v15 = v14;
    v47 = v14;
    v16 = GetWindowLongW(v14, -16);
    SetWindowLongW(v15, -16, v16 & 0xFFFFFFFD | 1);
    v8(v15, 0x1036u, 0x4020u, 16416);
    v17 = (HWND)v8(v15, 0x104Eu, 0, 0);
    CTreeList::InitToolTips(v17);
    gOldListWndProc = (WNDPROC)SetWindowLongW(v15, -4, (LONG)Proxy_ListCtrlWndProc);
    v8(v15, 0x30u, (WPARAM)ghConfigFont, 0);
    InitListHeader(v15, &v37, pnWidths, 2);
    QueryInformationJobObject(
      hObject,
      MaxJobObjectInfoClass|JobObjectBasicAccountingInformation,
      &JobObjectInformation,
      0x70u,
      &ReturnLength);
    v18 = v52;
    if ( v52 & 0x2000 )
    {
      sub_C67F90(v15, (int)L"Kill on Job Close", (int)L"True");
      v18 = v52;
    }
    if ( v18 & 0x400 )
    {
      sub_C67F90(v15, (int)L"Die on Unhandled Exception", (int)L"True");
      v18 = v52;
    }
    if ( v18 & 0x800 )
    {
      sub_C67F90(v15, (int)L"Breakaway OK", (int)L"True");
      v18 = v52;
    }
    if ( v18 & 0x1000 )
    {
      sub_C67F90(v15, (int)L"Silent Breakaway OK", (int)L"True");
      v18 = v52;
    }
    if ( v18 & 0x40 )
    {
      sub_C67F90(v15, (int)L"Preserve Job Time", (int)L"True");
      v18 = v52;
    }
    if ( v18 & 0x4000 )
    {
      sub_C67F90(v15, (int)L"Subset Affinity Allowed", (int)L"True");
      v18 = v52;
    }
    if ( v18 & 2 )
    {
      wsprintfW(&Dst, L"%I64d s", JobObjectInformation / 10000000);
      sub_C67F90(v15, (int)L"Process CPU Limit", (int)&Dst);
      v18 = v52;
    }
    if ( v18 & 4 )
    {
      wsprintfW(&Dst, L"%I64d s", v51 / 10000000);
      sub_C67F90(v15, (int)L"User CPU Limit", (int)&Dst);
      v18 = v52;
    }
    if ( v18 & 1 )
    {
      wsprintfW(&Dst, L"%d", v53 >> 10);
      PE_GetNumberFormat(&Dst, 0x400u);
      wcscat_s(&Dst, 0x400u, L" KB");
      sub_C67F90(v15, (int)L"Min Working Set", (int)&Dst);
      v18 = v52;
      if ( v52 & 1 )
      {
        wsprintfW(&Dst, L"%d", v54 >> 10);
        PE_GetNumberFormat(&Dst, 0x400u);
        wcscat_s(&Dst, 0x400u, L" KB");
        sub_C67F90(v15, (int)L"Max Working Set", (int)&Dst);
        v18 = v52;
      }
    }
    if ( v18 & 0x100 )
    {
      wsprintfW(&Dst, L"%d", v59 >> 10);
      PE_GetNumberFormat(&Dst, 0x400u);
      wcscat_s(&Dst, 0x400u, L" KB");
      sub_C67F90(v15, (int)L"Process Memory Limit", (int)&Dst);
      v18 = v52;
    }
    if ( v18 & 0x200 )
    {
      wsprintfW(&Dst, L"%d", v60 >> 10);
      PE_GetNumberFormat(&Dst, 0x400u);
      wcscat_s(&Dst, 0x400u, L" KB");
      sub_C67F90(v15, (int)L"Job Memory Limit", (int)&Dst);
      LOBYTE(v18) = v52;
    }
    if ( v18 & 8 )
    {
      wsprintfW(&Dst, L"%d", *(_DWORD *)ArgList);
      sub_C67F90(v15, (int)L"Active Processes", (int)&Dst);
      LOBYTE(v18) = v52;
    }
    if ( v18 & 0x10 )
    {
      wsprintfW(&Dst, L"%x", *(_DWORD *)v56);
      sub_C67F90(v15, (int)L"Affinity", (int)&Dst);
      LOBYTE(v18) = v52;
    }
    if ( v18 & 0x20 )
    {
      wsprintfW(&Dst, L"%d", *(_DWORD *)v57);
      sub_C67F90(v15, (int)L"Priority Class", (int)&Dst);
      LOBYTE(v18) = v52;
    }
    if ( (v18 & 0x80u) != 0 )
    {
      wsprintfW(&Dst, L"%d", *(_DWORD *)v58);
      sub_C67F90(v15, (int)L"Scheduling Class", (int)&Dst);
      LOBYTE(v18) = v52;
    }
    if ( v18 & 4 )
    {
      wsprintfW(
        &Dst,
        L"%I64d:%02I64d:%02I64d.%03I64d",
        v51 / 0x861C46800ui64,
        v51 / 0x23C34600ui64 % 0x3C,
        v51 / 10000000 % 60,
        v51 % 10000000 / 10000);
      v15 = v47;
      sub_C67F90(v47, (int)L"Job Time", (int)&Dst);
      LOBYTE(v18) = v52;
    }
    if ( v18 & 2 )
    {
      wsprintfW(
        &Dst,
        L"%I64d:%02I64d:%02I64d.%03I64d",
        JobObjectInformation / 0x861C46800ui64,
        JobObjectInformation / 0x23C34600ui64 % 0x3C,
        JobObjectInformation / 10000000 % 60,
        JobObjectInformation % 10000000 / 10000);
      v15 = v47;
      sub_C67F90(v47, (int)L"Process Time", (int)&Dst);
    }
    v19 = hObject;
    QueryInformationJobObject(hObject, JobObjectBasicUIRestrictions, &v49, 4u, &ReturnLength);
    v20 = v49;
    if ( v49 & 0x40 )
    {
      sub_C67F90(v15, (int)L"Desktop", (int)L"Limited");
      v20 = v49;
    }
    if ( v20 & 0x10 )
    {
      sub_C67F90(v15, (int)L"Display Settings", (int)L"Limited");
      v20 = v49;
    }
    if ( v20 < 0 )
    {
      sub_C67F90(v15, (int)L"Exit Windows", (int)L"Limited");
      v20 = v49;
    }
    if ( v20 & 0x20 )
    {
      sub_C67F90(v15, (int)L"Global Atoms", (int)L"Limited");
      v20 = v49;
    }
    if ( v20 & 1 )
    {
      sub_C67F90(v15, (int)L"USER Handles", (int)L"Limited");
      v20 = v49;
    }
    if ( v20 & 2 )
    {
      sub_C67F90(v15, (int)L"Read Clipboard", (int)L"Limited");
      v20 = v49;
    }
    if ( v20 & 8 )
    {
      sub_C67F90(v15, (int)L"System Parameters", (int)L"Limited");
      v20 = v49;
    }
    if ( v20 & 4 )
      sub_C67F90(v15, (int)L"Write Clipboard", (int)L"Limited");
    ReturnLength = 2000;
    v21 = malloc(0x7D0u);
    if ( !QueryInformationJobObject(v19, JobObjectSecurityLimitInformation, v21, 0x7D0u, &ReturnLength) )
    {
      do
      {
        if ( GetLastError() != 24 )
          break;
        free(v21);
        v22 = ReturnLength;
        v21 = malloc(ReturnLength);
      }
      while ( !QueryInformationJobObject(hObject, JobObjectSecurityLimitInformation, v21, v22, &ReturnLength) );
    }
    if ( v49 & 1 )
      sub_C67F90(v15, (int)L"Administrator Access", (int)L"Limited");
    free(v21);
    if ( SendMessageW(v15, 0x1004u, 0, 0) )
    {
      SendMessageW(v15, 0x101Eu, 0, 0xFFFF);
      SendMessageW(v15, 0x101Eu, 1u, 65534);
      v28 = 3;
      v27 = 3;
      SendMessageW(v15, 0x102Bu, 0, (LPARAM)&v26);
    }
    v5 = (void (__stdcall *)(HANDLE))CloseHandle;
    CloseHandle(hObject);
    free((void *)dwValue4);
  }
  else
  {
    SetDlgItemTextW(hWnd, 1075, L"<Access denied>");
  }
  if ( v42 )
    v5(v42);
  return 1;
}
// CABDE8: using guessed type wchar_t aDesktop_0[8];
// CB5C9C: using guessed type wchar_t aTrue_1[5];
// CB5CA8: using guessed type wchar_t aKillOnJobClose[18];
// CB5CCC: using guessed type wchar_t aDieOnUnhandled[27];
// CB5D04: using guessed type wchar_t aBreakawayOk[13];
// CB5D20: using guessed type wchar_t aSilentBreakawa[20];
// CB5D48: using guessed type wchar_t aPreserveJobTim[18];
// CB5D6C: using guessed type wchar_t aSubsetAffinity[24];
// CB5DAC: using guessed type wchar_t aProcessCpuLimi[18];
// CB5DD0: using guessed type wchar_t aUserCpuLimit[15];
// CB5DF0: using guessed type wchar_t aMinWorkingSet[16];
// CB5E10: using guessed type wchar_t aMaxWorkingSet[16];
// CB5E30: using guessed type wchar_t aProcessMemoryL[21];
// CB5E5C: using guessed type wchar_t aJobMemoryLimit[17];
// CB5E80: using guessed type wchar_t aActiveProcesse[17];
// CB5EAC: using guessed type wchar_t aAffinity[9];
// CB5EC0: using guessed type wchar_t aPriorityClass[15];
// CB5EE0: using guessed type wchar_t aSchedulingClas[17];
// CB5F04: using guessed type wchar_t aJobTime[9];
// CB5F18: using guessed type wchar_t aProcessTime[13];
// CB5F34: using guessed type wchar_t aLimited[8];
// CB5F44: using guessed type wchar_t aDisplaySetting[17];
// CB5F68: using guessed type wchar_t aExitWindows[13];
// CB5F84: using guessed type wchar_t aGlobalAtoms[13];
// CB5FA0: using guessed type wchar_t aUserHandles[13];
// CB5FBC: using guessed type wchar_t aReadClipboard[15];
// CB5FDC: using guessed type wchar_t aSystemParamete[18];
// CB6000: using guessed type wchar_t aWriteClipboard[16];
// CB6020: using guessed type wchar_t aAdministratorA[21];

//----- (00C54990) --------------------------------------------------------
int __stdcall PageProcGPU(HWND hWnd, int a2, WPARAM wParam, LONG dwNewLong)
{
  HWND v4; // eax
  int result; // eax
  CResizer *v6; // eax
  LONG v7; // eax
  HWND v8; // ebx
  HWND v9; // edi
  HWND v10; // esi
  HWND v11; // ebx
  HWND v12; // edi
  HWND v13; // esi
  HWND v14; // ebx
  HWND v15; // edi
  HWND v16; // esi
  HWND v17; // eax
  HWND v18; // eax
  HWND v19; // eax
  HWND v20; // eax
  HWND v21; // eax
  HWND v22; // eax
  HWND v23; // eax
  HWND v24; // eax
  HWND v25; // eax
  HWND v26; // eax
  HWND v27; // eax
  HWND v28; // eax
  WPARAM v29; // [esp-8h] [ebp-40h]
  CResizer *v30; // [esp+10h] [ebp-28h]
  HWND v31; // [esp+18h] [ebp-20h]
  HWND v32; // [esp+1Ch] [ebp-1Ch]
  HWND v33; // [esp+20h] [ebp-18h]
  HWND v34; // [esp+24h] [ebp-14h]
  int v35; // [esp+34h] [ebp-4h]

  GetWindowLongW(hWnd, -21);
  if ( (unsigned int)a2 > 0x113 )
  {
    if ( a2 == 307 || a2 == 310 || a2 == 312 )
      return PE_FillControl((int)hWnd, (HDC)wParam);
    return 0;
  }
  if ( a2 == 275 || a2 == 5 )
  {
    if ( IsWindowVisible(hWnd) )
    {
      v21 = GetDlgItem(hWnd, 1158);
      SendMessageW(v21, 0x400u, 0, 0);
      v22 = GetDlgItem(hWnd, 2000);
      SendMessageW(v22, 0x400u, 0, 0);
      v23 = GetDlgItem(hWnd, 1160);
      SendMessageW(v23, 0x400u, 0, 0);
      v24 = GetDlgItem(hWnd, 2601);
      SendMessageW(v24, 0x400u, 0, 0);
      v25 = GetDlgItem(hWnd, 1162);
      SendMessageW(v25, 0x400u, 0, 0);
      v26 = GetDlgItem(hWnd, 2602);
      SendMessageW(v26, 0x400u, 0, 0);
      v27 = GetDlgItem(hWnd, 1164);
      SendMessageW(v27, 0x400u, 0, 0);
      v28 = GetDlgItem(hWnd, 2603);
      SendMessageW(v28, 0x400u, 0, 0);
      return 0;
    }
    return 0;
  }
  if ( a2 == 272 )
  {
    v6 = (CResizer *)operator new(0x40u);
    v35 = 0;
    if ( v6 )
      v30 = CResizer::CResizer(v6, hWnd);
    else
      v30 = 0;
    v35 = -1;
    v7 = GetWindowLongW(hWnd, -16);
    SetWindowLongW(hWnd, -16, v7 | 0x2000000);
    SetWindowLongW(hWnd, -21, dwNewLong);
    CreateGraphWindow(hWnd, 1158, *(PVOID *)(dwNewLong + 1392));
    CreateGraphWindow(hWnd, 2000, *(PVOID *)(dwNewLong + 1392));
    CreateGraphWindow(hWnd, 1160, *(PVOID *)(dwNewLong + 1432));
    CreateGraphWindow(hWnd, 2601, *(PVOID *)(dwNewLong + 1432));
    CreateGraphWindow(hWnd, 1162, *(PVOID *)(dwNewLong + 1416));
    CreateGraphWindow(hWnd, 2602, *(PVOID *)(dwNewLong + 1416));
    CreateGraphWindow(hWnd, 1164, *(PVOID *)(dwNewLong + 1448));
    CreateGraphWindow(hWnd, 2603, *(PVOID *)(dwNewLong + 1448));
    v8 = GetDlgItem(hWnd, 1659);
    v9 = GetDlgItem(hWnd, 1161);
    v10 = GetDlgItem(hWnd, 1159);
    v31 = GetDlgItem(hWnd, 1157);
    v32 = v10;
    v33 = v9;
    v34 = v8;
    sub_C60550(v30, 4, (int)&v31);
    v11 = GetDlgItem(hWnd, 1164);
    v12 = GetDlgItem(hWnd, 1162);
    v13 = GetDlgItem(hWnd, 1160);
    v31 = GetDlgItem(hWnd, 1158);
    v32 = v13;
    v33 = v12;
    v34 = v11;
    sub_C60550(v30, 4, (int)&v31);
    v14 = GetDlgItem(hWnd, 2603);
    v15 = GetDlgItem(hWnd, 2602);
    v16 = GetDlgItem(hWnd, 2601);
    v31 = GetDlgItem(hWnd, 2000);
    v33 = v15;
    v32 = v16;
    v34 = v14;
    sub_C60550(v30, 4, (int)&v31);
    v17 = GetDlgItem(hWnd, 1157);
    *(double *)&CResizer::AddItem(v30, v17, 1)->gap0[24] = db_four;
    v18 = GetDlgItem(hWnd, 1159);
    *(double *)&CResizer::AddItem(v30, v18, 1)->gap0[24] = db_four;
    v19 = GetDlgItem(hWnd, 1161);
    *(double *)&CResizer::AddItem(v30, v19, 1)->gap0[24] = db_four;
    v20 = GetDlgItem(hWnd, 1659);
    *(double *)&CResizer::AddItem(v30, v20, 1)->gap0[24] = db_four;
    PropSheet_UpdateTab(hWnd);
    SendMessageW(hWnd, 0x113u, 0, 0);
    return 1;
  }
  if ( a2 != 273 )
    return 0;
  switch ( (unsigned __int16)wParam )
  {
    case 0x9C41u:
      v29 = 40014;
      goto LABEL_8;
    case 0x9C42u:
      SetEvent(ghRefreshEventHandle);
      result = 0;
      break;
    case 0x9C9Cu:
    case 0x9C9Du:
      v29 = wParam;
LABEL_8:
      v4 = GetParent(hWnd);
      PostMessageW(v4, 0x111u, v29, 0);
      result = 0;
      break;
    default:
      return 0;
  }
  return result;
}
// CACB38: using guessed type double db_four;

//----- (00C54E40) --------------------------------------------------------
signed int __stdcall PageProcPerf(HWND hWnd, unsigned int a2, HDC hdc, int a4)
{
  HWND v4; // ebx
  char *v5; // esi
  HICON v6; // ST50_4
  HWND v7; // eax
  _PSAPI_WORKING_SET_INFORMATION *v8; // esi
  HANDLE v9; // edi
  HWND v10; // eax
  HWND v11; // eax
  HWND v12; // eax
  signed int result; // eax
  HWND v14; // eax
  HANDLE v15; // edi
  void (__stdcall *v16)(HWND, int, LPCWSTR); // esi
  const WCHAR *v17; // eax
  const WCHAR *v18; // eax
  const WCHAR *v19; // eax
  const WCHAR *v20; // eax
  const WCHAR *v21; // eax
  const WCHAR *v22; // eax
  __m128i *v23; // eax
  const WCHAR *v24; // eax
  int v25; // ecx
  const WCHAR *v26; // ST50_4
  const WCHAR *v27; // eax
  const WCHAR *v28; // ST50_4
  DWORD v29; // eax
  const WCHAR *v30; // eax
  DWORD v31; // eax
  const WCHAR *v32; // eax
  signed __int64 v33; // [esp+4Ch] [ebp-500h]
  int v34; // [esp+60h] [ebp-4ECh]
  char ArgList[4]; // [esp+6Ch] [ebp-4E0h]
  struct _FILETIME LocalFileTime; // [esp+78h] [ebp-4D4h]
  int a4a; // [esp+80h] [ebp-4CCh]
  _DWORD v38[2]; // [esp+84h] [ebp-4C8h]
  char v39[4]; // [esp+8Ch] [ebp-4C0h]
  char ProcessInformation[4]; // [esp+90h] [ebp-4BCh]
  char v41[4]; // [esp+94h] [ebp-4B8h]
  char v42[4]; // [esp+98h] [ebp-4B4h]
  int v43; // [esp+9Ch] [ebp-4B0h]
  int a6; // [esp+A0h] [ebp-4ACh]
  int a5; // [esp+A4h] [ebp-4A8h]
  DWORD pdwLength; // [esp+A8h] [ebp-4A4h]
  _PSAPI_WORKING_SET_INFORMATION *ppBuffer; // [esp+ACh] [ebp-4A0h]
  HWND hDlg; // [esp+B0h] [ebp-49Ch]
  ULONG ReturnLength; // [esp+B4h] [ebp-498h]
  char *v50; // [esp+B8h] [ebp-494h]
  struct _SYSTEMTIME SystemTime; // [esp+BCh] [ebp-490h]
  char v52[16]; // [esp+CCh] [ebp-480h]
  __int128 v53; // [esp+DCh] [ebp-470h]
  int v54; // [esp+ECh] [ebp-460h]
  unsigned int v55; // [esp+F0h] [ebp-45Ch]
  unsigned int v56; // [esp+F4h] [ebp-458h]
  char v57[16]; // [esp+F8h] [ebp-454h]
  char v58[16]; // [esp+108h] [ebp-444h]
  __int128 v59; // [esp+118h] [ebp-434h]
  FILETIME FileTime; // [esp+128h] [ebp-424h]
  __int64 v61; // [esp+138h] [ebp-414h]
  __int64 v62; // [esp+140h] [ebp-40Ch]
  WCHAR DateStr; // [esp+148h] [ebp-404h]
  WCHAR String; // [esp+348h] [ebp-204h]

  v4 = hWnd;
  hDlg = hWnd;
  v5 = (char *)GetWindowLongW(hWnd, -21);
  ppBuffer = 0;
  v50 = v5;
  if ( a2 <= 0x133 )
  {
    if ( a2 != 307 )
    {
      switch ( a2 )
      {
        case 0x100u:
          if ( hdc != (HDC)116 )
            return 0;
          PostMessageW(hWnd, 0x113u, 1u, 0);
          result = 0;
          break;
        case 0x110u:
          PropSheet_UpdateTab(hWnd);
          v6 = LoadIconW(ghInstance, (LPCWSTR)0x6E);
          v7 = GetDlgItem(hWnd, 1119);
          SendMessageW(v7, 0x172u, 1u, (LPARAM)v6);
          v8 = (_PSAPI_WORKING_SET_INFORMATION *)malloc(0x60u);
          ppBuffer = v8;
          v8->NumberOfEntries = a4;
          v9 = OpenProcess(0x400u, 0, *(_DWORD *)(a4 + 68));
          if ( v9 || (v9 = OpenProcess(0x1000u, 0, *(_DWORD *)(v8->NumberOfEntries + 68))) != 0 )
          {
            NtQueryInformationProcess(v9, ProcessVmCounters, v8->WorkingSetInfo, 0x2Cu, &ReturnLength);
            NtQueryInformationProcess(v9, ProcessIoCounters, &v8[6], 0x30u, &ReturnLength);
            if ( NtQueryInformationProcess(v9, ProcessHandleCount, ProcessInformation, 8u, &ReturnLength) )
            {
              v10 = GetDlgItem(hWnd, 1609);
              EnableWindow(v10, 0);
              v11 = GetDlgItem(hWnd, 1052);
              EnableWindow(v11, 0);
              v8 = ppBuffer;
            }
            CloseHandle(v9);
          }
          if ( !QueryProcessCycleTime )
          {
            v12 = GetDlgItem(hWnd, 1324);
            SetWindowTextW(v12, L"Context Switch Delta");
          }
          SetWindowLongW(hWnd, -21, (LONG)v8);
          SendMessageW(hWnd, 0x113u, 0, 0);
          result = 0;
          break;
        case 0x111u:
          switch ( (unsigned __int16)hdc )
          {
            case 0x9C41u:
              v33 = 40014i64;
              goto LABEL_18;
            case 0x9C42u:
              SetEvent(ghRefreshEventHandle);
              result = 0;
              break;
            case 0x9C9Cu:
            case 0x9C9Du:
              v33 = (unsigned int)hdc;
LABEL_18:
              v14 = GetParent(hWnd);
              PostMessageW(v14, 0x111u, v33, SHIDWORD(v33));
              result = 0;
              break;
            default:
              return 0;
          }
          break;
        case 0x113u:
          v15 = OpenProcess(0x400u, 0, *(_DWORD *)(*(_DWORD *)v5 + 68));
          pdwLength = (DWORD)v15;
          if ( v15 || (v15 = OpenProcess(0x1000u, 0, *(_DWORD *)(*(_DWORD *)v5 + 68)), (pdwLength = (DWORD)v15) != 0) )
          {
            v16 = (void (__stdcall *)(HWND, int, LPCWSTR))SetDlgItemTextW;
            if ( !NtQueryInformationProcess(v15, 0, &v34, 0x18u, &ReturnLength) )
            {
              wsprintf(&String, L"%d", *(_DWORD *)ArgList);
              SetDlgItemTextW(hWnd, 1042, &String);
            }
            if ( !NtQueryInformationProcess(v15, ProcessTimes, &FileTime, 0x20u, &ReturnLength) )
            {
              if ( FileTime )
              {
                FileTimeToLocalFileTime(&FileTime, &LocalFileTime);
                FileTimeToSystemTime(&LocalFileTime, &SystemTime);
                GetTimeFormatW(0x400u, 0, &SystemTime, 0, &String, 128);
                GetDateFormatW(0x400u, 0, &SystemTime, 0, &DateStr, 128);
                wcscat_s(&String, 0x100u, L"   ");
                wcscat_s(&String, 0x100u, &DateStr);
              }
              else
              {
                wcscpy_s(&String, 0x100u, L"n/a");
              }
              SetDlgItemTextW(hWnd, 1007, &String);
              wsprintf(
                &String,
                L"%I64d:%02I64d:%02I64d.%03I64d",
                v61 / 0x861C46800ui64,
                v61 / 0x23C34600ui64 % 0x3C,
                v61 / 10000000 % 60,
                v61 % 10000000 / 10000);
              SetDlgItemTextW(hDlg, 1012, &String);
              wsprintf(
                &String,
                L"%I64d:%02I64d:%02I64d.%03I64d",
                v62 / 0x861C46800ui64,
                v62 / 0x23C34600ui64 % 0x3C,
                v62 / 10000000 % 60,
                v62 % 10000000 / 10000);
              SetDlgItemTextW(hDlg, 1013, &String);
              a5 = v61 + v62;
              wsprintf(
                &String,
                L"%I64d:%02I64d:%02I64d.%03I64d",
                (v61 + v62) / 0x861C46800ui64,
                (v61 + v62) / 0x23C34600ui64 % 0x3C,
                (v61 + v62) / 0x989680ui64 % 0x3C,
                (v61 + v62) % 0x989680ui64 / 0x2710);
              v4 = hDlg;
              v16 = (void (__stdcall *)(HWND, int, LPCWSTR))SetDlgItemTextW;
              SetDlgItemTextW(hDlg, 1014, &String);
              v15 = (HANDLE)pdwLength;
            }
            if ( NtQueryInformationProcess(v15, ProcessIoCounters, v57, 0x30u, &ReturnLength) )
            {
              v23 = (__m128i *)v50;
            }
            else
            {
              wsprintf(&String, L"%I64d", *(_DWORD *)v57, *(_DWORD *)&v57[4]);
              v17 = PE_GetNumberFormat(&String, 0x100u);
              v16(v4, 1041, v17);
              wsprintf(&String, L"%I64d", *(_QWORD *)v57 - *((_QWORD *)v50 + 6));
              v18 = PE_GetNumberFormat(&String, 0x100u);
              v16(v4, 1044, v18);
              wsprintf(&String, L"%I64d", *(_DWORD *)&v57[8], *(_DWORD *)&v57[12]);
              v19 = PE_GetNumberFormat(&String, 0x100u);
              v16(v4, 1043, v19);
              wsprintf(&String, L"%I64d", *(_QWORD *)&v57[8] - *((_QWORD *)v50 + 7));
              v20 = PE_GetNumberFormat(&String, 0x100u);
              v16(v4, 1050, v20);
              wsprintf(&String, L"%I64d", *(_DWORD *)v58, *(_DWORD *)&v58[4]);
              v21 = PE_GetNumberFormat(&String, 0x100u);
              v16(v4, 1045, v21);
              wsprintf(&String, L"%I64d", *(_QWORD *)v58 - *((_QWORD *)v50 + 8));
              v22 = PE_GetNumberFormat(&String, 0x100u);
              v16(v4, 1049, v22);
              PE_FormatDouble(
                0,
                &String,
                0x100u,
                (double)(unsigned __int64)(v59 - *((_QWORD *)v50 + 10)),
                0.0,
                COERCE_LONG_DOUBLE(0i64 >> 63));
              v16(v4, 1334, &String);
              PE_FormatDouble(
                0,
                &String,
                0x100u,
                (double)(unsigned __int64)(*(_QWORD *)&v58[8] - *((_QWORD *)v50 + 9)),
                0.0,
                COERCE_LONG_DOUBLE(0i64 >> 63));
              v16(v4, 1333, &String);
              PE_FormatDouble(
                0,
                &String,
                0x100u,
                (double)(unsigned __int64)(*((_QWORD *)&v59 + 1) - *((_QWORD *)v50 + 11)),
                0.0,
                COERCE_LONG_DOUBLE(0i64 >> 63));
              v16(v4, 1051, &String);
              v23 = (__m128i *)v50;
              _mm_storeu_si128((__m128i *)v50 + 3, _mm_loadu_si128((const __m128i *)v57));
              _mm_storeu_si128(v23 + 4, _mm_loadu_si128((const __m128i *)v58));
              _mm_storeu_si128(v23 + 5, _mm_loadu_si128((const __m128i *)&v59));
            }
            if ( QueryProcessCycleTime )
            {
              QueryProcessCycleTime(QueryProcessCycleTime, (PULONG64)v15);
              wsprintf(&String, L"%I64u", v38[0], v38[1]);
            }
            else
            {
              wsprintf(&String, L"%I64d", *(_QWORD *)(v23->m128i_i32[0] + 1336));
            }
            v24 = PE_GetNumberFormat(&String, 0x100u);
            v16(v4, 1195, v24);
            if ( NtQueryInformationProcess(v15, ProcessPagePriority, v42, 4u, &ReturnLength) )
              wsprintf(&String, L"n/a");
            else
              wsprintf(&String, L"%d", *(_DWORD *)v42);
            v16(v4, 1339, &String);
            if ( NtQueryInformationProcess(v15, ProcessIoPriority, &v43, 4u, &ReturnLength) )
              wsprintf(&String, L"n/a");
            else
              sub_C67790(v43, &String, 0x100u);
            v16(v4, 1340, &String);
            pdwLength = 0;
            PE_QueryProcessWorkset(v15, &ppBuffer, &pdwLength, &a4a, &a5, &a6, (DWORD *)&hDlg);
            free(ppBuffer);
            wsprintf(&String, L"%ld", (unsigned int)a5 >> 10);
            PE_GetNumberFormat(&String, 0x100u);
            wcscat_s(&String, 0x100u, L" K");
            v16(v4, 1067, &String);
            wsprintf(&String, L"%ld", (unsigned int)hDlg >> 10);
            PE_GetNumberFormat(&String, 0x100u);
            wcscat_s(&String, 0x100u, L" K");
            v16(v4, 1069, &String);
            wsprintf(&String, L"%ld", (unsigned int)a6 >> 10);
            PE_GetNumberFormat(&String, 0x100u);
            wcscat_s(&String, 0x100u, L" K");
            v16(v4, 1068, &String);
            if ( !NtQueryInformationProcess(v15, ProcessVmCounters, v52, 0x2Cu, &ReturnLength) )
            {
              wsprintf(&String, L"%ld", (unsigned int)v53 >> 10);
              PE_GetNumberFormat(&String, 0x100u);
              wcscat_s(&String, 0x100u, L" K");
              v16(v4, 1008, &String);
              wsprintf(&String, L"%ld", *(_DWORD *)&v52[12] >> 10);
              PE_GetNumberFormat(&String, 0x100u);
              wcscat_s(&String, 0x100u, L" K");
              v16(v4, 1064, &String);
              wsprintf(&String, L"%ld", v55 >> 10);
              PE_GetNumberFormat(&String, 0x100u);
              wcscat_s(&String, 0x100u, L" K");
              v16(v4, 1009, &String);
              wsprintf(&String, L"%ld", v56 >> 10);
              PE_GetNumberFormat(&String, 0x100u);
              wcscat_s(&String, 0x100u, L" K");
              v16(v4, 1010, &String);
              wsprintf(&String, L"%I64u", *(_DWORD *)&v52[4] >> 10, 0);
              PE_GetNumberFormat(&String, 0x100u);
              wcscat_s(&String, 0x100u, L" K");
              v16(v4, 1060, &String);
              wsprintf(&String, L"%ld", *(_DWORD *)&v52[8]);
              PE_GetNumberFormat(&String, 0x100u);
              v16(v4, 1065, &String);
              wsprintf(&String, L"%d", *(_DWORD *)&v52[8] - *((_DWORD *)v50 + 3));
              PE_GetNumberFormat(&String, 0x100u);
              v16(v4, 1066, &String);
              v25 = (int)v50;
              _mm_storeu_si128((__m128i *)(v50 + 4), _mm_loadu_si128((const __m128i *)v52));
              _mm_storeu_si128((__m128i *)(v25 + 20), _mm_loadu_si128((const __m128i *)&v53));
              _mm_storel_epi64((__m128i *)(v25 + 36), _mm_loadl_epi64((const __m128i *)&v54));
              *(_DWORD *)(v25 + 44) = v56;
            }
            if ( NtQueryInformationProcess(v15, ProcessHandleCount, ProcessInformation, 8u, &ReturnLength) )
            {
              if ( !NtQueryInformationProcess(v15, ProcessHandleCount, v39, 4u, &ReturnLength) )
              {
                wsprintf(&String, L"%d", *(_DWORD *)v39);
                v26 = PE_GetNumberFormat(&String, 0x100u);
                v16(v4, 1048, v26);
              }
            }
            else
            {
              wsprintf(&String, L"%d", *(_DWORD *)ProcessInformation);
              v27 = PE_GetNumberFormat(&String, 0x100u);
              v16(v4, 1048, v27);
              wsprintf(&String, L"%d", *(_DWORD *)v41);
              v28 = PE_GetNumberFormat(&String, 0x100u);
              v16(v4, 1052, v28);
            }
            if ( *(_DWORD *)GetGuiResources )
            {
              v29 = GetGuiResources(v15, 0);
              wsprintf(&String, L"%d", v29);
              v30 = PE_GetNumberFormat(&String, 0x100u);
              v16(v4, 1046, v30);
              v31 = GetGuiResources(v15, 1u);
              wsprintf(&String, L"%d", v31);
              v32 = PE_GetNumberFormat(&String, 0x100u);
              v16(v4, 1047, v32);
            }
            CloseHandle(v15);
          }
          result = 1;
          break;
        default:
          return 0;
      }
      return result;
    }
    return PE_FillControl((int)hWnd, hdc);
  }
  if ( a2 == 310 || a2 == 312 )
    return PE_FillControl((int)hWnd, hdc);
  if ( a2 == 2033 )
  {
    free(v5);
    DestroyWindow(hWnd);
  }
  return 0;
}

//----- (00C55E50) --------------------------------------------------------
int __stdcall PageProcPerfETW(HWND hWnd, int a2, HDC hdc, int a4)
{
  void *v4; // eax
  void *v5; // ebx
  _DWORD *v6; // eax
  int result; // eax
  HWND v8; // eax
  const WCHAR *v9; // eax
  const WCHAR *v10; // eax
  const WCHAR *v11; // eax
  const WCHAR *v12; // eax
  const WCHAR *v13; // eax
  const WCHAR *v14; // eax
  const WCHAR *v15; // eax
  const WCHAR *v16; // eax
  const WCHAR *v17; // eax
  const WCHAR *v18; // eax
  const WCHAR *v19; // eax
  const WCHAR *v20; // eax
  signed __int64 v21; // [esp+10h] [ebp-218h]
  WCHAR String; // [esp+24h] [ebp-204h]

  v4 = (void *)GetWindowLongW(hWnd, -21);
  v5 = v4;
  if ( (unsigned int)a2 <= 0x133 )
  {
    if ( a2 != 307 )
    {
      switch ( a2 )
      {
        case 256:
          if ( hdc != (HDC)116 )
            return 0;
          PostMessageW(hWnd, 0x113u, 1u, 0);
          result = 0;
          break;
        case 272:
          PropSheet_UpdateTab(hWnd);
          v6 = malloc(0x60u);
          *v6 = a4;
          SetWindowLongW(hWnd, -21, (LONG)v6);
          SendMessageW(hWnd, 0x113u, 0, 0);
          result = 0;
          break;
        case 273:
          switch ( (unsigned __int16)hdc )
          {
            case 0x9C41u:
              v21 = 40014i64;
              goto LABEL_11;
            case 0x9C42u:
              SetEvent(ghRefreshEventHandle);
              result = 0;
              break;
            case 0x9C9Cu:
            case 0x9C9Du:
              v21 = (unsigned int)hdc;
LABEL_11:
              v8 = GetParent(hWnd);
              PostMessageW(v8, 0x111u, v21, SHIDWORD(v21));
              result = 0;
              break;
            default:
              return 0;
          }
          break;
        case 275:
          wsprintf(&String, L"%u", *(_DWORD *)(*(_DWORD *)v4 + 1176));
          v9 = PE_GetNumberFormat(&String, 0x100u);
          SetDlgItemTextW(hWnd, 1186, v9);
          wsprintf(&String, L"%u", *(_DWORD *)(*(_DWORD *)v5 + 1192));
          v10 = PE_GetNumberFormat(&String, 0x100u);
          SetDlgItemTextW(hWnd, 1048, v10);
          wsprintf(&String, L"%u", *(_DWORD *)(*(_DWORD *)v5 + 1208));
          v11 = PE_GetNumberFormat(&String, 0x100u);
          SetDlgItemTextW(hWnd, 1187, v11);
          wsprintf(&String, L"%u", *(_DWORD *)(*(_DWORD *)v5 + 1224));
          v12 = PE_GetNumberFormat(&String, 0x100u);
          SetDlgItemTextW(hWnd, 1053, v12);
          wsprintf(&String, L"%u", *(_DWORD *)(*(_DWORD *)v5 + 1240));
          v13 = PE_GetNumberFormat(&String, 0x100u);
          SetDlgItemTextW(hWnd, 1047, v13);
          wsprintf(&String, L"%u", *(_DWORD *)(*(_DWORD *)v5 + 1256));
          v14 = PE_GetNumberFormat(&String, 0x100u);
          SetDlgItemTextW(hWnd, 1052, v14);
          PE_FormatDouble(
            0,
            &String,
            0x100u,
            (double)*(signed __int64 *)(*(_DWORD *)v5 + 1232),
            0.0,
            COERCE_LONG_DOUBLE(0i64 >> 63));
          SetDlgItemTextW(hWnd, 1336, &String);
          PE_FormatDouble(
            0,
            &String,
            0x100u,
            (double)*(signed __int64 *)(*(_DWORD *)v5 + 1200),
            0.0,
            COERCE_LONG_DOUBLE(0i64 >> 63));
          SetDlgItemTextW(hWnd, 1335, &String);
          PE_FormatDouble(
            0,
            &String,
            0x100u,
            (double)*(signed __int64 *)(*(_DWORD *)v5 + 1264),
            0.0,
            COERCE_LONG_DOUBLE(0i64 >> 63));
          SetDlgItemTextW(hWnd, 1054, &String);
          PE_FormatDouble(
            0,
            &String,
            0x100u,
            (double)*(signed __int64 *)(*(_DWORD *)v5 + 1216),
            0.0,
            COERCE_LONG_DOUBLE(0i64 >> 63));
          SetDlgItemTextW(hWnd, 1204, &String);
          PE_FormatDouble(
            0,
            &String,
            0x100u,
            (double)*(signed __int64 *)(*(_DWORD *)v5 + 1184),
            0.0,
            COERCE_LONG_DOUBLE(0i64 >> 63));
          SetDlgItemTextW(hWnd, 1202, &String);
          PE_FormatDouble(
            0,
            &String,
            0x100u,
            (double)*(signed __int64 *)(*(_DWORD *)v5 + 1248),
            0.0,
            COERCE_LONG_DOUBLE(0i64 >> 63));
          SetDlgItemTextW(hWnd, 1206, &String);
          wsprintf(&String, L"%u", *(_DWORD *)(*(_DWORD *)v5 + 1072));
          v15 = PE_GetNumberFormat(&String, 0x100u);
          SetDlgItemTextW(hWnd, 1638, v15);
          wsprintf(&String, L"%u", *(_DWORD *)(*(_DWORD *)v5 + 1088));
          v16 = PE_GetNumberFormat(&String, 0x100u);
          SetDlgItemTextW(hWnd, 1639, v16);
          wsprintf(&String, L"%u", *(_DWORD *)(*(_DWORD *)v5 + 1104));
          v17 = PE_GetNumberFormat(&String, 0x100u);
          SetDlgItemTextW(hWnd, 1641, v17);
          wsprintf(&String, L"%u", *(_DWORD *)(*(_DWORD *)v5 + 1120));
          v18 = PE_GetNumberFormat(&String, 0x100u);
          SetDlgItemTextW(hWnd, 1643, v18);
          wsprintf(&String, L"%u", *(_DWORD *)(*(_DWORD *)v5 + 1136));
          v19 = PE_GetNumberFormat(&String, 0x100u);
          SetDlgItemTextW(hWnd, 1645, v19);
          wsprintf(&String, L"%u", *(_DWORD *)(*(_DWORD *)v5 + 1152));
          v20 = PE_GetNumberFormat(&String, 0x100u);
          SetDlgItemTextW(hWnd, 1646, v20);
          PE_FormatDouble(
            0,
            &String,
            0x100u,
            (double)*(signed __int64 *)(*(_DWORD *)v5 + 1128),
            0.0,
            COERCE_LONG_DOUBLE(0i64 >> 63));
          SetDlgItemTextW(hWnd, 1644, &String);
          PE_FormatDouble(
            0,
            &String,
            0x100u,
            (double)*(signed __int64 *)(*(_DWORD *)v5 + 1096),
            0.0,
            COERCE_LONG_DOUBLE(0i64 >> 63));
          SetDlgItemTextW(hWnd, 1640, &String);
          PE_FormatDouble(
            0,
            &String,
            0x100u,
            (double)*(signed __int64 *)(*(_DWORD *)v5 + 1160),
            0.0,
            COERCE_LONG_DOUBLE(0i64 >> 63));
          SetDlgItemTextW(hWnd, 1647, &String);
          PE_FormatDouble(
            0,
            &String,
            0x100u,
            (double)*(signed __int64 *)(*(_DWORD *)v5 + 1112),
            0.0,
            COERCE_LONG_DOUBLE(0i64 >> 63));
          SetDlgItemTextW(hWnd, 1205, &String);
          PE_FormatDouble(
            0,
            &String,
            0x100u,
            (double)*(signed __int64 *)(*(_DWORD *)v5 + 1080),
            0.0,
            COERCE_LONG_DOUBLE(0i64 >> 63));
          SetDlgItemTextW(hWnd, 1203, &String);
          PE_FormatDouble(
            0,
            &String,
            0x100u,
            (double)*(signed __int64 *)(*(_DWORD *)v5 + 1144),
            0.0,
            COERCE_LONG_DOUBLE(0i64 >> 63));
          SetDlgItemTextW(hWnd, 1207, &String);
          result = 1;
          break;
        default:
          return 0;
      }
      return result;
    }
    return PE_FillControl((int)hWnd, hdc);
  }
  if ( a2 == 310 || a2 == 312 )
    return PE_FillControl((int)hWnd, hdc);
  if ( a2 == 2033 )
  {
    free(v4);
    DestroyWindow(hWnd);
  }
  return 0;
}

//----- (00C566A0) --------------------------------------------------------
BOOL __stdcall ProcPropSheet(HWND hDlg, UINT uMsg, WPARAM wParam, PROPITEM *PropItem)
{
  HWND hWndTab; // eax
  HWND hWndTab_1; // ebx
  HWND *v6; // eax
  HWND *v8; // edi
  HWND v9; // eax
  LRESULT v10; // eax
  _DWORD *v11; // ebx
  LRESULT v12; // esi
  char *v13; // edi
  BOOL (__stdcall *v14)(HWND, UINT, WPARAM, LPARAM); // ST14_4
  signed int v15; // edi
  HWND *v16; // esi
  WPARAM v17; // eax
  LRESULT v18; // eax
  WPARAM v19; // ecx
  _DWORD *i; // eax
  CResizer *v21; // eax
  LONG v22; // eax
  LONG v23; // eax
  const wchar_t *v24; // ecx
  WPARAM nTabIndex; // ebx
  WPARAM nTabIndex_1; // esi
  WPARAM nTabIndex_2; // esi
  tagTREEVIEWLISTITEMPARAM *pListItem; // eax
  WPARAM nTabIndex_3; // esi
  WPARAM nTabIndex_4; // esi
  HWND hWndTab_3; // esi
  WPARAM nTabIdx; // ebx
  _DWORD *v33; // eax
  int nTabItem; // ebx
  int v35; // esi
  int nTabItem_1; // esi
  int v37; // ebx
  HANDLE ProcessHandle; // eax
  tagTREEVIEWLISTITEMPARAM *pListItem_1; // ecx
  HANDLE v40; // esi
  bool v41; // zf
  tagTREEVIEWLISTITEMPARAM *pListItem_2; // eax
  int v43; // esi
  int v44; // esi
  void *v45; // esi
  int v46; // esi
  int v47; // esi
  WPARAM v48; // ST14_4
  _DWORD *v49; // eax
  HWND hWnd; // esi
  UINT v51; // eax
  WPARAM nTab; // ecx
  POINT v53; // ST14_8
  HCURSOR v54; // eax
  struct tagPOINT Point; // [esp+10h] [ebp-264h]
  NMHDR lParam; // [esp+18h] [ebp-25Ch]
  tagTCITEMW tcitem; // [esp+24h] [ebp-250h]
  HWND hDlg_1; // [esp+40h] [ebp-234h]
  HWND hWndTab_2; // [esp+44h] [ebp-230h]
  HANDLE hObject; // [esp+48h] [ebp-22Ch]
  struct tagRECT Rect; // [esp+4Ch] [ebp-228h]
  WCHAR pszBuffer[260]; // [esp+5Ch] [ebp-218h]
  int v63; // [esp+270h] [ebp-4h]

  hDlg_1 = hDlg;
  hWndTab = GetDlgItem(hDlg, IDS_PROCPROPSHEET_TABCTRL);
  hWndTab_1 = hWndTab;
  hWndTab_2 = hWndTab;
  v6 = (HWND *)GetWindowLongW(hDlg, GWL_USERDATA);
  hObject = v6;
  if ( uMsg > WM_NOTIFY )
  {
    if ( uMsg == WM_INITDIALOG )
    {
      ShowWindow(hDlg, 0);
      v21 = (CResizer *)operator new(0x40u);
      hObject = v21;
      v63 = 0;
      if ( v21 )
        CResizer::CResizer(v21, hDlg);
      v63 = -1;
      SetWindowLongW(hDlg, GWL_USERDATA, (LONG)PropItem);
      tcitem.mask = 3;
      tcitem.iImage = -1;
      v22 = GetWindowLongW(hWndTab_1, GWL_EXSTYLE);
      SetWindowLongW(hWndTab_1, -20, v22 | WS_EX_CONTROLPARENT);
      v23 = GetWindowLongW(hWndTab_1, -16);
      SetWindowLongW(hWndTab_1, GWL_STYLE, v23 | WS_CLIPCHILDREN);
      if ( PropItem->pListItem )
      {
        TreeViewItemParam_InitGraph((tagTREEVIEWLISTITEMPARAM *)PropItem->pListItem);
        tcitem.pszText = L"Image";
        SendMessageW(hWndTab_1, TCM_INSERTITEMW, 0, (LPARAM)&tcitem);
        wcscpy_s(PropItem->PageData[1].szTemplateName, 256u, L"PROCPERF");
        PropItem->PageData[1].nTabId = 2;
        PropItem->PageData[1].PageWndProc = (WNDPROC)PageProcPerf;
        tcitem.pszText = L"Performance";
        SendMessageW(hWndTab_1, TCM_INSERTITEMW, 1u, (LPARAM)&tcitem);
        v24 = L"PROCCPUIO";
        if ( !*((_DWORD *)PropItem->pListItem + 266) )
          v24 = L"PROCCPU";
        wcscpy_s(PropItem->PageData[2].szTemplateName, 256u, v24);
        PropItem->PageData[2].nTabId = 4;
        PropItem->PageData[2].PageWndProc = (WNDPROC)PageProcCPU;
        tcitem.pszText = L"Performance Graph";
        SendMessageW(hWndTab_1, TCM_INSERTITEMW, 2u, (LPARAM)&tcitem);
        nTabIndex = 3;
        if ( gbFlagsInProcPropSheet )
        {
          wcscpy_s(PropItem->PageData[3].szTemplateName, 256u, L"PROCPERFETW");
          PropItem->PageData[3].nTabId = 14;
          PropItem->PageData[3].PageWndProc = (WNDPROC)PageProcPerfETW;
          tcitem.pszText = L"Disk and Network";
          SendMessageW(hWndTab_2, TCM_INSERTITEMW, 3u, (LPARAM)&tcitem);
          nTabIndex = 4;
        }
        if ( gdwAdapterRuntingTime )
        {
          nTabIndex_1 = nTabIndex;
          wcscpy_s(PropItem->PageData[nTabIndex].szTemplateName, 256u, L"PROCGPU");
          PropItem->PageData[nTabIndex_1].nTabId = 15;
          PropItem->PageData[nTabIndex_1].PageWndProc = (WNDPROC)PageProcGPU;
          tcitem.pszText = L"GPU Graph";
          SendMessageW(hWndTab_2, TCM_INSERTITEMW, nTabIndex++, (LPARAM)&tcitem);
        }
        if ( *((_BYTE *)PropItem->pListItem + 40) & 0x20 )
        {
          nTabIndex_2 = nTabIndex;
          wcscpy_s(PropItem->PageData[nTabIndex].szTemplateName, 256u, L"PROCSERVICES");
          PropItem->PageData[nTabIndex_2].nTabId = 5;
          PropItem->PageData[nTabIndex_2].PageWndProc = (WNDPROC)PageProcServices;
          tcitem.pszText = L"Services";
          SendMessageW(hWndTab_2, TCM_INSERTITEMW, nTabIndex++, (LPARAM)&tcitem);
        }
        pListItem = (tagTREEVIEWLISTITEMPARAM *)PropItem->pListItem;
        if ( pListItem && pListItem->bSupportWMIProviders )
        {
          nTabIndex_3 = nTabIndex;
          wcscpy_s(PropItem->PageData[nTabIndex].szTemplateName, 256u, L"PROCWMIPROVIDERS");
          PropItem->PageData[nTabIndex_3].nTabId = 16;
          PropItem->PageData[nTabIndex_3].PageWndProc = (WNDPROC)PageProcWMIProviders;
          tcitem.pszText = L"WMI Providers";
          SendMessageW(hWndTab_2, TCM_INSERTITEMW, nTabIndex++, (LPARAM)&tcitem);
        }
        nTabIndex_4 = nTabIndex;
        wcscpy_s(PropItem->PageData[nTabIndex].szTemplateName, 256u, L"PROCTHREADS");
        PropItem->PageData[nTabIndex_4].nTabId = 6;
        PropItem->PageData[nTabIndex_4].PageWndProc = (WNDPROC)PageProcThreads;
        hWndTab_3 = hWndTab_2;
        tcitem.pszText = L"Threads";
        SendMessageW(hWndTab_2, TCM_INSERTITEMW, nTabIndex, (LPARAM)&tcitem);
        nTabIdx = nTabIndex + 1;
        hObject = (char *)PropItem + sizeof(PROPPAGEDATA) * nTabIdx;
        if ( AllocateAndGetUdpExTable2FromStack )
          wcscpy_s((wchar_t *)hObject + 6, 256u, L"PROCTCPUDPSTACK");
        else
          wcscpy_s((wchar_t *)hObject + 6, 256u, L"PROCTCPUDP");
        v33 = hObject;
        tcitem.pszText = L"TCP/IP";
        *((_DWORD *)hObject + 131) = 7;
        v33[132] = PageProcTcpUdp;
        SendMessageW(hWndTab_3, TCM_INSERTITEMW, nTabIdx, (LPARAM)&tcitem);
        nTabItem = nTabIdx + 1;
        v35 = nTabItem;
        wcscpy_s(PropItem->PageData[nTabItem].szTemplateName, 256u, L"PROCSECURITY");
        PropItem->PageData[v35].nTabId = 8;
        PropItem->PageData[v35].PageWndProc = PageProcSecurity;
        tcitem.pszText = L"Security";
        SendMessageW(hWndTab_2, TCM_INSERTITEMW, nTabItem++, (LPARAM)&tcitem);
        nTabItem_1 = nTabItem;
        wcscpy_s(PropItem->PageData[nTabItem].szTemplateName, 256u, L"PROCENV");
        PropItem->PageData[nTabItem_1].nTabId = 9;
        PropItem->PageData[nTabItem_1].PageWndProc = (WNDPROC)PageProcEnv;
        tcitem.pszText = L"Environment";
        SendMessageW(hWndTab_2, TCM_INSERTITEMW, nTabItem, (LPARAM)&tcitem);
        v37 = nTabItem + 1;
        ProcessHandle = PE_OpenProcess(MAXIMUM_ALLOWED, 0, *((_DWORD *)PropItem->pListItem + 17));
        pListItem_1 = (tagTREEVIEWLISTITEMPARAM *)PropItem->pListItem;
        v40 = ProcessHandle;
        hObject = ProcessHandle;
        v41 = PE_IsProcessInJob(ProcessHandle, pListItem_1->dwProcessId, 0, 0) == 0;
        pListItem_2 = (tagTREEVIEWLISTITEMPARAM *)PropItem->pListItem;
        if ( v41 )
        {
          pListItem_2->dwStyle &= -0x801u;
        }
        else
        {
          pListItem_2->dwStyle |= 0x800u;
          v43 = v37;
          wcscpy_s(PropItem->PageData[v37].szTemplateName, 256u, L"PROCJOB");
          PropItem->PageData[v43].nTabId = 10;
          PropItem->PageData[v43].PageWndProc = (WNDPROC)PageProcJob;
          tcitem.pszText = L"Job";
          SendMessageW(hWndTab_2, TCM_INSERTITEMW, v37, (LPARAM)&tcitem);
          v40 = hObject;
          ++v37;
        }
        if ( v40 )
          CloseHandle(v40);
        if ( ProcessIsNetCclr_0((tagTREEVIEWLISTITEMPARAM *)PropItem->pListItem) )
        {
          v44 = v37;
          wcscpy_s(PropItem->PageData[v37].szTemplateName, 0x100u, L"PROCCLR");
          PropItem->PageData[v44].nTabId = 11;
          PropItem->PageData[v44].PageWndProc = (WNDPROC)PageProcCclr;
          tcitem.pszText = L".NET Assemblies";
          SendMessageW(hWndTab_2, TCM_INSERTITEMW, v37++, (LPARAM)&tcitem);
          if ( !*((_DWORD *)PropItem->pListItem + 321) )
          {
            v45 = malloc(0x88u);
            memset(v45, 0, 0x88u);
            *((_DWORD *)PropItem->pListItem + 321) = v45;
          }
        }
        if ( *((_DWORD *)PropItem->pListItem + 321) )
        {
          CoInitialize(0);
          v46 = v37;
          wcscpy_s(PropItem->PageData[v37].szTemplateName, 0x100u, L"PROCNET");
          PropItem->PageData[v46].nTabId = 12;
          PropItem->PageData[v46].PageWndProc = PageProcNet;
          tcitem.pszText = L".NET Performance";
          SendMessageW(hWndTab_2, TCM_INSERTITEMW, v37++, (LPARAM)&tcitem);
        }
        v47 = v37;
        wcscpy_s(PropItem->PageData[v37].szTemplateName, 0x100u, L"PROCSTRINGS");
        PropItem->PageData[v47].nTabId = 13;
        PropItem->PageData[v47].PageWndProc = PageProcStrings;
        tcitem.pszText = L"Strings";
        v48 = v37;
        hWndTab_1 = hWndTab_2;
        SendMessageW(hWndTab_2, TCM_INSERTITEMW, v48, (LPARAM)&tcitem);
        v49 = PropItem->pListItem;
        if ( v49[216] )
        {
          swprintf(pszBuffer, L"%s:%d (%s) Properties", v49[15], v49[17], v49[216]);
        }
        else if ( v49[17] < 0 )
        {
          swprintf(pszBuffer, L"%s Properties", v49[15]);
        }
        else
        {
          swprintf(pszBuffer, L"%s:%d Properties", v49[15], v49[17]);
        }
        hWnd = hDlg_1;
        SetWindowTextW(hDlg_1, pszBuffer);
        PropItem->PageData[0].hWnd = CreateDialogParamW(
                                       ghMainInstance,
                                       L"PROCINFO",
                                       hWnd,
                                       (DLGPROC)PageProcInfo,
                                       (LPARAM)PropItem->pListItem);
        PropItem->PageData[0].nTabId = 1;
      }
      else
      {
        hWnd = hDlg_1;
      }
      ShowWindow(PropItem->PageData[0].hWnd, SW_SHOW);
      SetForegroundWindow(hWnd);
      v51 = PropItem->PageData[0].nTabId;
      nTab = 0;
      if ( v51 )
      {
        while ( gConfig.dwDefaultProcPropPage != v51 )
        {
          v51 = *(&PropItem->nTabIndex + 131 * (++nTab + 1));
          if ( !v51 )
            goto LABEL_77;
        }
      }
      else
      {
LABEL_77:
        nTab = 0;
      }
      SendMessageW(hWndTab_1, TCM_SETCURSEL, nTab, 0);
      lParam.idFrom = IDS_PROCPROPSHEET_TABCTRL;
      lParam.code = TCN_SELCHANGE;
      SendMessageW(hWnd, WM_NOTIFY, 0, (LPARAM)&lParam);
      if ( gConfig.WindowPlacement[SysinfoWindowplacement].ptMinPosition.x == gConfig.WindowPlacement[SysinfoWindowplacement].flags )
      {
        GetCursorPos(&Point);
        v53.y = Point.y - 408;
        v53.x = Point.x - 385;
        PE_SetWindowPlacement(hWnd, v53);
      }
      else
      {
        sub_C5DC50(hWnd, (tagTREEVIEWLISTITEMPARAM *)PropItem->pListItem);
      }
      ShowWindow(hWnd, 5);
      InterlockedDecrement(&gnRefCount);
      v54 = LoadCursorW(0, (LPCWSTR)IDC_ARROW);
      SetCursor(v54);
      return 1;
    }
    if ( uMsg == 273 )
    {
      if ( (signed int)(unsigned __int16)wParam > 40092 )
      {
        if ( (unsigned __int16)wParam == 40093 )
        {
          v18 = SendMessageW(hWndTab_1, TCM_GETCURSEL, 0, 0);
          v19 = v18 - 1;
          if ( !v18 )
          {
            v19 = 0;
            for ( i = (char *)hObject + 1052; *i; ++v19 )
              i += 131;
          }
          SendMessageW(hWndTab_1, TCM_SETCURSEL, v19, 0);
          lParam.idFrom = 1110;
          lParam.code = -551;
          SendMessageW(hDlg, WM_NOTIFY, 0, (LPARAM)&lParam);
        }
      }
      else
      {
        if ( (unsigned __int16)wParam == 40092 )
        {
          v17 = SendMessageW(hWndTab_1, TCM_GETCURSEL, 0, 0) + 1;
          if ( !*((_DWORD *)hObject + 131 * v17 + 132) )
            v17 = 0;
          SendMessageW(hWndTab_1, TCM_SETCURSEL, v17, 0);
          lParam.idFrom = 1110;
          lParam.code = -551;
          SendMessageW(hDlg_1, WM_NOTIFY, 0, (LPARAM)&lParam);
          return 0;
        }
        if ( (signed int)(unsigned __int16)wParam > 0
          && ((signed int)(unsigned __int16)wParam <= 2 || (unsigned __int16)wParam == 40014) )
        {
          ShowWindow(hDlg, 0);
          v15 = 32;
          v16 = (HWND *)((char *)hObject + 8);
          while ( 1 )
          {
            if ( *v16 )
            {
              SendMessageW(*v16, WM_COMMAND, wParam, 0);
              SendMessageW(*v16, WM_MSG_7F1, 0, 0);
            }
            v16 += 131;
            if ( !--v15 )
            {
              PostMessageW(ghMainWnd, WM_MSG_7ED, 0, *((_DWORD *)hObject + 1));
              if ( *(_DWORD *)(*((_DWORD *)hObject + 1) + 1284) )
                CoUninitialize();
              free(hObject);
              GetWindowPlacement(hDlg_1, (WINDOWPLACEMENT *)((char *)&gConfig.WindowPlacement[3] + 4));
              DestroyWindow(hDlg_1);
              _endthread();
            }
          }
        }
      }
    }
    return 0;
  }
  if ( uMsg == WM_NOTIFY )
  {
    if ( PropItem->pListItem == (void *)1110 && PropItem->PageData[0].hWnd == (HWND)-551 )
    {
      v10 = SendMessageW(hWndTab_1, TCM_GETCURSEL, 0, 0);
      v11 = hObject;
      v12 = v10;
      v13 = (char *)hObject + 524 * v10;
      hObject = v13;
      gConfig.dwDefaultProcPropPage = *((_DWORD *)v13 + 131);
      ShowWindow((HWND)v11[131 * *v11 + 2], 0);
      *v11 = v12;
      if ( !*((_DWORD *)v13 + 2) )
      {
        v14 = (BOOL (__stdcall *)(HWND, UINT, WPARAM, LPARAM))*((_DWORD *)v13 + 132);
        v13 = (char *)hObject;
        *((_DWORD *)hObject + 2) = CreateDialogParamW(ghMainInstance, (LPCWSTR)hObject + 6, hDlg_1, v14, v11[1]);
      }
      ShowWindow(*((HWND *)v13 + 2), 5);
      return 0;
    }
    return 0;
  }
  if ( uMsg != 5 )
  {
    if ( uMsg == 36 )
    {
      PropItem->PageData[0].hWnd = (HWND)(2 * gdwVirtualScreenWidth);
      return 0;
    }
    return 0;
  }
  v8 = v6 + 2;
  v9 = (HWND)32;
  hDlg_1 = (HWND)32;
  do
  {
    if ( *v8 )
    {
      GetWindowRect(hWndTab_1, &Rect);
      SendMessageW(hWndTab_1, TCM_ADJUSTRECT, 0, (LPARAM)&Rect);
      MapWindowPoints(0, hDlg, (LPPOINT)&Rect, 2u);
      MoveWindow(*v8, Rect.left, Rect.top, Rect.right - Rect.left, Rect.bottom - Rect.top, 1);
      InvalidateRect(*v8, 0, 1);
      v9 = hDlg_1;
    }
    v8 += 131;
    v9 = (HWND)((char *)v9 - 1);
    hDlg_1 = v9;
  }
  while ( v9 );
  return 0;
}
// C7A009: using guessed type int _endthread(void);
// C9CFEC: using guessed type wchar_t aEnvironment[12];
// CB5168: using guessed type wchar_t aSecurity_0[9];
// CB6390: using guessed type wchar_t aPerformance[12];
// CB63A8: using guessed type wchar_t aProccpuio[10];
// CB63CC: using guessed type wchar_t aPerformanceGra[18];
// CB6408: using guessed type wchar_t aDiskAndNetwork[17];
// CB643C: using guessed type wchar_t aGpuGraph[10];
// CB646C: using guessed type wchar_t aServices_0[9];
// CB64A4: using guessed type wchar_t aWmiProviders_0[14];
// CB64D8: using guessed type wchar_t aThreads[8];
// CB64E8: using guessed type wchar_t aProctcpudpstac[16];
// CB6520: using guessed type wchar_t aTcpIp[7];
// CB657C: using guessed type wchar_t aNetAssemblies[16];
// CB65AC: using guessed type wchar_t aNetPerformance[17];
// CB65E8: using guessed type wchar_t aStrings[8];
// CD4E28: using guessed type int gdwVirtualScreenWidth;
// CD5390: using guessed type char gbFlagsInProcPropSheet;

//----- (00C57240) --------------------------------------------------------
void __cdecl __noreturn CTreeList::BackendFillTreeViewParamThreadProc(tagTREEVIEWLISTITEMPARAM *pItem)
{
  HCURSOR v1; // eax
  PROPITEM *PropItem; // esi
  HWND hDlgSheet; // ebx
  char *v4; // edi
  HWND v5; // eax
  HWND hWndFind; // esi
  DWORD dwRet; // ebx
  PROPPAGEDATA *PageData; // esi
  signed int nPageIndex; // edi
  UINT uMsg; // eax
  struct tagMSG msg; // [esp+Ch] [ebp-2Ch]
  HANDLE Handles[2]; // [esp+28h] [ebp-10h]
  HACCEL hAccel; // [esp+30h] [ebp-8h]
  PROPITEM *v14; // [esp+34h] [ebp-4h]
  tagTREEVIEWLISTITEMPARAM *pInfoa; // [esp+40h] [ebp+8h]

  InterlockedIncrement(&gnRefCount);
  v1 = LoadCursorW(0, (LPCWSTR)IDC_APPSTARTING);
  SetCursor(v1);
  PropItem = (PROPITEM *)malloc(sizeof(PROPITEM));
  v14 = PropItem;
  memset(PropItem, 0, sizeof(PROPITEM));
  PropItem->pListItem = pItem;
  hDlgSheet = CreateDialogParamW(ghMainInstance, L"PROCPROPSHEET", ghMainWnd, (DLGPROC)ProcPropSheet, (LPARAM)PropItem);
  pInfoa = (tagTREEVIEWLISTITEMPARAM *)hDlgSheet;
  hAccel = LoadAcceleratorsW(ghMainInstance, L"PROCPROPERTIES");
  while ( !PeekMessageW(&msg, 0, 0, 0, PM_REMOVE) )
  {
LABEL_15:
    Handles[0] = ghTimerRefreshProcPageEventHandle;
    Handles[1] = ghEvent6;
    dwRet = MsgWaitForMultipleObjects(2u, Handles, 0, 0xFFFFFFFF, QS_ALLINPUT);
    if ( dwRet != 2 )
    {
      PageData = PropItem->PageData;
      nPageIndex = 32;
      do
      {
        if ( PageData->hWnd )
        {
          uMsg = WM_USER;
          if ( !dwRet )
            uMsg = WM_TIMER;
          PostMessageW(PageData->hWnd, uMsg, 1u, 0);
        }
        ++PageData;
        --nPageIndex;
      }
      while ( nPageIndex );
      PropItem = v14;
    }
    hDlgSheet = (HWND)pInfoa;
  }
  while ( 1 )
  {
    v4 = (char *)PropItem + sizeof(PROPPAGEDATA) * PropItem->nTabIndex;
    v5 = (HWND)*((_DWORD *)v4 + 2);
    if ( v5 && TranslateAcceleratorW(v5, hAccel, &msg) )
      goto LABEL_14;
    hWndFind = (HWND)GetPropW(hDlgSheet, L"FindWindow");
    if ( !hWndFind )
    {
LABEL_10:
      if ( !IsDialogMessageW(*((HWND *)v4 + 2), &msg) && !IsDialogMessageW(hDlgSheet, &msg) )
      {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
      }
      goto LABEL_13;
    }
    if ( IsDialogMessageW(hWndFind, &msg) )
    {
      if ( msg.message != WM_COMMAND || LOWORD(msg.wParam) != 40014 )
        goto LABEL_13;
    }
    else if ( msg.message != WM_COMMAND || LOWORD(msg.wParam) != 40014 )
    {
      goto LABEL_10;
    }
    PostMessageW(hWndFind, WM_COMMAND, IDABORT, 0);
    SetPropW(hDlgSheet, L"FindWindow", 0);
LABEL_13:
    PropItem = v14;
LABEL_14:
    if ( !PeekMessageW(&msg, 0, 0, 0, 1u) )
      goto LABEL_15;
  }
}

//----- (00C57440) --------------------------------------------------------
int __stdcall sub_C57440(volatile LONG *lpAddend)
{
  signed int v1; // edi
  HWND v2; // ST0C_4
  DWORD v3; // eax
  void *v4; // ST18_4
  PSID v5; // ST14_4
  DWORD v6; // eax
  HWND v7; // eax
  wchar_t *v8; // eax
  LPARAM v9; // ST18_4
  HWND v10; // eax
  HWND v11; // ST0C_4
  LPARAM lParam; // [esp+Ch] [ebp-46Ch]
  int v14; // [esp+10h] [ebp-468h]
  int v15; // [esp+14h] [ebp-464h]
  int v16; // [esp+2Ch] [ebp-44Ch]
  enum _SID_NAME_USE peUse; // [esp+40h] [ebp-438h]
  WPARAM wParam; // [esp+44h] [ebp-434h]
  WPARAM v19; // [esp+48h] [ebp-430h]
  DWORD cchName; // [esp+4Ch] [ebp-42Ch]
  void *v21; // [esp+50h] [ebp-428h]
  DWORD cchReferencedDomainName; // [esp+54h] [ebp-424h]
  LRESULT v23; // [esp+58h] [ebp-420h]
  PSID Sid; // [esp+5Ch] [ebp-41Ch]
  int v25; // [esp+60h] [ebp-418h]
  WCHAR Name; // [esp+64h] [ebp-414h]
  WCHAR ReferencedDomainName; // [esp+26Ch] [ebp-20Ch]

  lParam = 0;
  memset(&v14, 0, 0x30u);
  EnterCriticalSection((LPCRITICAL_SECTION)(lpAddend + 3));
  v1 = 0;
  v23 = SendMessageW(*((HWND *)lpAddend + 9), 0x1004u, 0, 0);
  if ( v23 > 0 )
  {
    do
    {
      if ( *((_BYTE *)lpAddend + 40) == 1 )
        break;
      lParam = 4;
      v2 = (HWND)*((_DWORD *)lpAddend + 9);
      v14 = v1;
      v15 = 0;
      if ( !SendMessageW(v2, 0x104Bu, 0, (LPARAM)&lParam) )
        break;
      v25 = v16;
      v3 = GetLengthSid(*(PSID *)(v16 + 36));
      Sid = malloc(v3);
      v4 = *(void **)(v25 + 36);
      v5 = Sid;
      v6 = GetLengthSid(*(PSID *)(v25 + 36));
      CopySid(v6, v5, v4);
      LeaveCriticalSection((LPCRITICAL_SECTION)(lpAddend + 3));
      cchName = 260;
      cchReferencedDomainName = 260;
      if ( LookupAccountSidW(
             (LPCWSTR)&gszNullString,
             Sid,
             &Name,
             &cchName,
             &ReferencedDomainName,
             &cchReferencedDomainName,
             &peUse) )
      {
        if ( ReferencedDomainName )
        {
          wcscat_s(&ReferencedDomainName, 0x104u, L"\\");
          wcscat_s(&ReferencedDomainName, 0x104u, &Name);
        }
        else
        {
          wcscpy_s(&ReferencedDomainName, 0x104u, &Name);
        }
        EnterCriticalSection((LPCRITICAL_SECTION)(lpAddend + 3));
        if ( *((_BYTE *)lpAddend + 40) )
          break;
        LeaveCriticalSection((LPCRITICAL_SECTION)(lpAddend + 3));
        v7 = GetParent(*((HWND *)lpAddend + 9));
        SendMessageW(v7, 0x7F7u, v1, (LPARAM)&ReferencedDomainName);
        v21 = *(void **)(v25 + 40);
        v8 = _wcsdup(&ReferencedDomainName);
        *(_DWORD *)(v25 + 40) = v8;
        if ( v21 )
          free(v21);
      }
      EnterCriticalSection((LPCRITICAL_SECTION)(lpAddend + 3));
      free(Sid);
      ++v1;
    }
    while ( v1 < v23 );
  }
  v9 = *((_DWORD *)lpAddend + 9);
  v10 = GetParent(*((HWND *)lpAddend + 9));
  SendMessageW(v10, 0x7F6u, 0, v9);
  LeaveCriticalSection((LPCRITICAL_SECTION)(lpAddend + 3));
  SendMessageW(*((HWND *)lpAddend + 9), 0x101Eu, 0, 0xFFFF);
  if ( !InterlockedDecrement(lpAddend) )
  {
    DeleteCriticalSection((LPCRITICAL_SECTION)(lpAddend + 3));
    free((void *)lpAddend);
  }
  InvalidateRect(*((HWND *)lpAddend + 9), 0, 0);
  v19 = nItem;
  v11 = (HWND)*((_DWORD *)lpAddend + 9);
  wParam = 1040;
  SendMessageW(v11, 0x1030u, (WPARAM)&wParam, (LPARAM)BackendSortCallback);
  return 0;
}

//----- (00C57710) --------------------------------------------------------
int __stdcall PageProcSecurity(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
  LONG v4; // ebx
  CResizer *v5; // eax
  CResizer *v6; // esi
  HWND v7; // eax
  HWND v8; // eax
  HWND v9; // eax
  HWND v10; // eax
  HWND v11; // eax
  struct tagResizerItem *v12; // eax
  HWND v13; // eax
  HWND v14; // eax
  HWND v15; // eax
  HWND v16; // eax
  HWND v17; // eax
  HICON v18; // ST24_4
  HWND v19; // eax
  HICON v20; // ST24_4
  HWND v21; // eax
  HWND v22; // edi
  LONG v23; // eax
  HWND v24; // eax
  _IMAGELIST *v25; // edi
  HICON v26; // eax
  HICON v27; // eax
  HWND v28; // esi
  LONG v29; // eax
  LRESULT (__stdcall *SendMessageW)(HWND, UINT, WPARAM, LPARAM); // ebx
  HWND v31; // esi
  HWND v32; // edi
  LONG v33; // eax
  HWND v34; // eax
  void *v35; // esi
  HWND v36; // eax
  HWND v37; // eax
  HWND v38; // eax
  HWND v39; // eax
  HWND v40; // esi
  const WCHAR *v41; // esi
  const WCHAR *v42; // eax
  unsigned __int8 v43; // cl
  void (__stdcall *GetTokenInformatio)(HANDLE, TOKEN_INFORMATION_CLASS, LPVOID, DWORD, PDWORD); // ebx
  DWORD (__stdcall *GetLastError)(); // esi
  unsigned int v46; // eax
  TOKEN_INFORMATION_CLASS TokenClassInfo; // edi
  DWORD v48; // esi
  int *v49; // ebx
  bool v50; // zf
  int *v51; // esi
  void *v52; // edi
  tagTREEVIEWLISTITEMPARAM *v53; // ebx
  DWORD v54; // eax
  void *v55; // eax
  void *v56; // ST20_4
  DWORD v57; // eax
  DWORD v58; // esi
  PSID *v59; // edi
  tagTREEVIEWLISTITEMPARAM *v60; // eax
  tagTREEVIEWLISTITEMPARAM *v61; // ebx
  DWORD v62; // eax
  void *v63; // eax
  PSID v64; // ST24_4
  void *v65; // ST20_4
  DWORD v66; // eax
  HWND v67; // esi
  int v68; // eax
  wchar_t *v69; // eax
  DWORD v70; // esi
  DWORD v71; // esi
  void **v72; // edi
  void **v73; // ecx
  void *v74; // esi
  tagTREEVIEWLISTITEMPARAM *v75; // edi
  DWORD v76; // eax
  void *v77; // eax
  void *v78; // ST20_4
  DWORD v79; // eax
  HWND v80; // esi
  int v81; // eax
  wchar_t *v82; // eax
  unsigned int v83; // ecx
  char *v84; // eax
  int v85; // edi
  DWORD v86; // esi
  TOKEN_PRIVILEGES *v87; // eax
  struct _LUID *v88; // esi
  HWND v89; // esi
  HWND v90; // eax
  HWND v91; // edi
  HWND v93; // eax
  TOKEN_PRIVILEGES *v94; // ebx
  LONG v95; // eax
  HWND v96; // ST18_4
  HWND v97; // ST18_4
  WPARAM v98; // [esp-8h] [ebp-1C10h]
  WCHAR *v99; // [esp-4h] [ebp-1C0Ch]
  LVITEMW Item; // [esp+10h] [ebp-1BF8h]
  UINT v101; // [esp+44h] [ebp-1BC4h]
  int v102; // [esp+48h] [ebp-1BC0h]
  UINT pnIDs; // [esp+4Ch] [ebp-1BBCh]
  int v104; // [esp+50h] [ebp-1BB8h]
  WPARAM wParama; // [esp+54h] [ebp-1BB4h]
  WPARAM v106; // [esp+58h] [ebp-1BB0h]
  DWORD ReturnLength; // [esp+5Ch] [ebp-1BACh]
  DWORD cchName; // [esp+60h] [ebp-1BA8h]
  enum _SID_NAME_USE peUse; // [esp+64h] [ebp-1BA4h]
  WORD v110[2]; // [esp+68h] [ebp-1BA0h]
  WORD pnWidths[2]; // [esp+6Ch] [ebp-1B9Ch]
  DWORD cchReferencedDomainName; // [esp+70h] [ebp-1B98h]
  HWND v113; // [esp+74h] [ebp-1B94h]
  LVITEMW lParama; // [esp+78h] [ebp-1B90h]
  unsigned int v115; // [esp+ACh] [ebp-1B5Ch]
  HANDLE InBuffer; // [esp+B0h] [ebp-1B58h]
  int v117; // [esp+B4h] [ebp-1B54h]
  LPVOID TokenInformation; // [esp+B8h] [ebp-1B50h]
  HWND v119; // [esp+BCh] [ebp-1B4Ch]
  DWORD BytesReturned; // [esp+C0h] [ebp-1B48h]
  DWORD cbSid; // [esp+C4h] [ebp-1B44h]
  DWORD TokenInformationLength; // [esp+C8h] [ebp-1B40h]
  HANDLE OutBuffer; // [esp+CCh] [ebp-1B3Ch]
  HWND hDlg; // [esp+D0h] [ebp-1B38h]
  TOKEN_PRIVILEGES *pTokenPrivileges; // [esp+D4h] [ebp-1B34h]
  tagHANDLELISTITEMPARAM pListParam[71]; // [esp+D8h] [ebp-1B30h]
  TOKEN_STATISTICS TokenStatisticsInfo; // [esp+1198h] [ebp-A70h]
  WCHAR Name[260]; // [esp+11D0h] [ebp-A38h]
  WCHAR ReferencedDomainName[260]; // [esp+13D8h] [ebp-830h]
  WCHAR Dst[260]; // [esp+15E0h] [ebp-628h]
  WCHAR String[260]; // [esp+17E8h] [ebp-420h]
  WCHAR szBuffer[260]; // [esp+19F0h] [ebp-218h]
  int v133; // [esp+1C04h] [ebp-4h]

  hDlg = hWnd;
  pTokenPrivileges = (TOKEN_PRIVILEGES *)lParam;
  OutBuffer = 0;
  v4 = GetWindowLongW(hWnd, -21);
  lParama.mask = 0;
  v117 = v4;
  memset(&lParama.iItem, 0, 0x30u);
  pnIDs = 1046;
  v104 = 1049;
  pnWidths[0] = MulDiv(100, gLogPixelSize.x, 96);
  pnWidths[1] = MulDiv(100, gLogPixelSize.x, 96);
  v101 = 1047;
  v102 = 1051;
  v110[0] = MulDiv(100, gLogPixelSize.x, 96);
  v110[1] = MulDiv(100, gLogPixelSize.x, 96);
  if ( msg <= WM_CTLCOLOREDIT )
  {
    if ( msg != WM_CTLCOLOREDIT )
    {
      switch ( msg )
      {
        case WM_ALTTABACTIVE|WM_DESTROY:
          CMainWnd::DrawItem((LPDRAWITEMSTRUCT)pTokenPrivileges);
          return 0;
        case 0x2Cu:
          return CMainWnd::HandleMeasureItem(hWnd, msg, wParam, (LPMEASUREITEMSTRUCT)pTokenPrivileges);
        case WM_NOTIFY:
          v94 = pTokenPrivileges;
          v95 = pTokenPrivileges->Privileges[0].Luid.HighPart;
          if ( v95 == -108 )
            return CMainWnd::HandleLVNColumnClick(wParam, (LPNMLVKEYDOWN)pTokenPrivileges);
          if ( v95 == -101 || v95 == -2 )
          {
            v96 = (HWND)pTokenPrivileges->PrivilegeCount;
            lParama.mask = 4;
            lParama.iItem = ::SendMessageW(v96, 0x100Cu, 0xFFFFFFFF, 2);
            v97 = (HWND)v94->PrivilegeCount;
            lParama.iSubItem = 0;
            if ( ::SendMessageW(v97, LVM_GETITEMW, 0, (LPARAM)&lParama) && (_DWORD)lParama.lParam > 1 )
            {
              if ( (HWND)v94->PrivilegeCount == GetDlgItem(hWnd, 1040) )
              {
                cbSid = 260;
                QueryAuthorityInfoFromSID((PSID)lParama.lParam->nRefCount, String, (int)&cbSid);
                SetDlgItemTextW(hWnd, 1342, String);
              }
              else
              {
                GetDlgItem(hWnd, 1038);
              }
            }
          }
          return 0;
        case WM_INITDIALOG:
          v5 = (CResizer *)operator new(0x40u);
          BytesReturned = (DWORD)v5;
          v133 = 0;
          if ( v5 )
            v6 = CResizer::CResizer(v5, hWnd);
          else
            v6 = 0;
          v133 = -1;
          v7 = GetDlgItem(hWnd, 1337);
          if ( v7 )
            *(_OWORD *)CResizer::AddItem(v6, v7, 1)->gap0 = 0i64;
          v8 = GetDlgItem(hWnd, 1669);
          if ( v8 )
            *(_OWORD *)CResizer::AddItem(v6, v8, 1)->gap0 = 0i64;
          v9 = GetDlgItem(hWnd, 1668);
          if ( v9 )
            *(_OWORD *)CResizer::AddItem(v6, v9, 1)->gap0 = 0i64;
          v10 = GetDlgItem(hWnd, 1057);
          if ( v10 )
            *(_OWORD *)CResizer::AddItem(v6, v10, 1)->gap0 = 0i64;
          v11 = GetDlgItem(hWnd, 1040);
          if ( v11 )
          {
            v12 = CResizer::AddItem(v6, v11, 1);
            *(_QWORD *)&v12->gap0[16] = 0i64;
            *(double *)&v12->gap0[24] = db_one;
          }
          v13 = GetDlgItem(hWnd, 1342);
          if ( v13 )
            *(_OWORD *)&CResizer::AddItem(v6, v13, 1)->gap0[16] = xmmword_CB6C70;
          v14 = GetDlgItem(hWnd, 1346);
          if ( v14 )
            *(_OWORD *)&CResizer::AddItem(v6, v14, 1)->gap0[16] = xmmword_CB6C70;
          v15 = GetDlgItem(hWnd, 1128);
          if ( v15 )
            *(_OWORD *)&CResizer::AddItem(v6, v15, 1)->gap0[16] = xmmword_CB6C70;
          v16 = GetDlgItem(hWnd, 1038);
          if ( v16 )
            *(_OWORD *)&CResizer::AddItem(v6, v16, 1)->gap0[16] = xmmword_CB6C70;
          v17 = GetDlgItem(hWnd, 1038);
          if ( v17 )
            *(_OWORD *)&CResizer::AddItem(v6, v17, 1)->gap0[16] = xmmword_CB6C70;
          PropSheet_UpdateTab(hWnd);
          v18 = LoadIconW(ghInstance, (LPCWSTR)0x70);
          v19 = GetDlgItem(hWnd, 1127);
          ::SendMessageW(v19, STM_SETIMAGE, 1u, (LPARAM)v18);
          v20 = LoadIconW(ghInstance, (LPCWSTR)0x6F);
          v21 = GetDlgItem(hWnd, 1128);
          ::SendMessageW(v21, STM_SETIMAGE, 1u, (LPARAM)v20);
          SetDlgItemTextW(hWnd, 1342, L"n/a");
          SetDlgItemTextW(hDlg, 1057, L"n/a");
          v22 = GetDlgItem(hDlg, 1040);
          v119 = v22;
          v23 = GetWindowLongW(v22, -16);
          SetWindowLongW(v22, -16, v23 & 0xFFFFFFFD | 1);
          ::SendMessageW(v22, LVM_SETEXTENDEDLISTVIEWSTYLE, 0x4020u, 16416);
          v24 = (HWND)::SendMessageW(v22, LVM_GETTOOLTIPS, 0, 0);
          CTreeList::InitToolTips(v24);
          gOldListWndProc = (WNDPROC)SetWindowLongW(v22, -4, (LONG)Proxy_ListCtrlWndProc);
          ::SendMessageW(v22, 0x30u, (WPARAM)ghConfigFont, 0);
          InitListHeader(v22, &pnIDs, pnWidths, 2);
          v25 = ImageList_Create(16, 16, 1u, 256, 256);
          v26 = LoadIconW(ghInstance, (LPCWSTR)0xCB);
          ImageList_ReplaceIcon(v25, -1, v26);
          v27 = LoadIconW(ghInstance, (LPCWSTR)0x71);
          ImageList_ReplaceIcon(v25, -1, v27);
          v28 = v119;
          v29 = GetWindowLongW(v119, -16);
          SetWindowLongW(v28, -16, v29 | LVS_SHAREIMAGELISTS);
          SendMessageW = ::SendMessageW;
          ::SendMessageW(v28, LVM_SETIMAGELIST, 1u, (LPARAM)v25);
          CTreeList::InitHeaderColumn(v28, nItem, (HWND)nItem, byte_CCD224);
          v31 = hDlg;
          v32 = GetDlgItem(hDlg, 1038);
          v113 = v32;
          v33 = GetWindowLongW(v32, -16);
          SetWindowLongW(v32, -16, v33 & 0xFFFFFFFD | 1);
          ::SendMessageW(v32, LVM_SETEXTENDEDLISTVIEWSTYLE, 0x4020u, 16416);
          v34 = (HWND)::SendMessageW(v32, LVM_GETTOOLTIPS, 0, 0);
          CTreeList::InitToolTips(v34);
          gOldListWndProc = (WNDPROC)SetWindowLongW(v32, -4, (LONG)Proxy_ListCtrlWndProc);
          ::SendMessageW(v32, WM_SETFONT, (WPARAM)ghConfigFont, 0);
          InitListHeader(v32, &v101, v110, 2);
          SetDlgItemTextW(v31, 19, (LPCWSTR)pTokenPrivileges[5].Privileges[0].Luid.HighPart);
          cbSid = 0;
          cchReferencedDomainName = 0;
          LookupAccountNameW(
            0,
            (LPCWSTR)pTokenPrivileges[5].Privileges[0].Luid.HighPart,
            0,
            &cbSid,
            ReferencedDomainName,
            &cchReferencedDomainName,
            &peUse);
          if ( cbSid )
          {
            v35 = malloc(cbSid);
            LookupAccountNameW(
              0,
              (LPCWSTR)pTokenPrivileges[5].Privileges[0].Luid.HighPart,
              v35,
              &cbSid,
              ReferencedDomainName,
              &cchReferencedDomainName,
              &peUse);
            cbSid = 260;
            QueryAuthorityInfoFromSID(v35, String, (int)&cbSid);
            free(v35);
            v31 = hDlg;
          }
          else
          {
            swprintf(String, L"n/a");
          }
          SetDlgItemTextW(v31, 20, String);
          if ( pTokenPrivileges[6].Privileges[0].Luid.LowPart == -1 )
            swprintf(String, L"n/a");
          else
            swprintf(String, L"%d", pTokenPrivileges[6].Privileges[0].Luid.LowPart);
          SetDlgItemTextW(v31, 1056, String);
          if ( gdwVersion >= 1 )
          {
            v41 = L"Yes";
            v42 = L"Yes";
            if ( !(pTokenPrivileges[2].Privileges[0].Luid.HighPart & 0x200) )
              v42 = L"No";
            SetDlgItemTextW(hDlg, 1337, v42);
            if ( pTokenPrivileges[2].Privileges[0].Luid.HighPart & 0x400 && gdwVersion >= 3 )
            {
              v43 = BYTE1(pTokenPrivileges[40].Privileges[0].Luid.HighPart);
              Name[0] = 0;
              if ( (v43 & 0xF0u) < 0x70 )
                wcscat_s(Name, 0x104u, &aPsprotectedsig[64 * ((unsigned int)v43 >> 4)]);
              if ( (BYTE1(pTokenPrivileges[40].Privileges[0].Luid.HighPart) & 7) == 1 )
                wcscat_s(Name, 0x104u, L"-Light");
              v99 = Name;
            }
            else
            {
              if ( !(pTokenPrivileges[2].Privileges[0].Luid.HighPart & 0x400) )
                v41 = L"No";
              v99 = (WCHAR *)v41;
            }
            v40 = hDlg;
            SetDlgItemTextW(hDlg, 1668, v99);
          }
          else
          {
            v36 = GetDlgItem(v31, 1335);
            ShowWindow(v36, 0);
            v37 = GetDlgItem(hDlg, 1337);
            ShowWindow(v37, 0);
            v38 = GetDlgItem(hDlg, 1669);
            ShowWindow(v38, 0);
            v39 = GetDlgItem(hDlg, 1668);
            ShowWindow(v39, 0);
            v40 = hDlg;
          }
          InBuffer = PE_OpenProcess(0x400u, 0, pTokenPrivileges[4].Privileges[0].Luid.LowPart);
          if ( InBuffer )
          {
            if ( !DeviceIoControl(ghDriverHandle, 0x8335000C, &InBuffer, 4u, &OutBuffer, 4u, &BytesReturned, 0) )
              OpenProcessToken(InBuffer, 8u, &OutBuffer);
            if ( OutBuffer )
            {
              GetTokenInformatio = (void (__stdcall *)(HANDLE, TOKEN_INFORMATION_CLASS, LPVOID, DWORD, PDWORD))GetTokenInformation;
              TokenStatisticsInfo.AuthenticationId.HighPart = 0;
              TokenStatisticsInfo.AuthenticationId.LowPart = 0;
              ReturnLength = 56;
              GetTokenInformation(OutBuffer, TokenStatistics, &TokenStatisticsInfo, 0x38u, &ReturnLength);
              swprintf_s(
                String,
                0x104u,
                L"%x",
                TokenStatisticsInfo.AuthenticationId.LowPart,
                TokenStatisticsInfo.AuthenticationId.HighPart);
              SetDlgItemTextW(v40, 1057, String);
              GetLastError = ::GetLastError;
              v46 = 0;
              v117 = 0;
              do
              {
                TokenClassInfo = TokenRestrictedSids;
                if ( !v46 )
                  TokenClassInfo = TokenGroups;
                GetTokenInformatio(OutBuffer, TokenClassInfo, 0, 0, &TokenInformationLength);
                if ( GetLastError() == ERROR_INSUFFICIENT_BUFFER )
                {
                  v48 = TokenInformationLength;
                  v49 = (int *)malloc(TokenInformationLength);
                  TokenInformation = v49;
                  if ( GetTokenInformation(OutBuffer, TokenClassInfo, v49, v48, &TokenInformationLength) )
                  {
                    v50 = *v49 == 0;
                    v115 = 0;
                    if ( !v50 )
                    {
                      v51 = v49 + 2;
                      do
                      {
                        v52 = (void *)*(v51 - 1);
                        v53 = (tagTREEVIEWLISTITEMPARAM *)malloc(0x34u);
                        memset(v53, 0, 0x34u);
                        v53->field_2C = *v51;
                        v54 = GetLengthSid(v52);
                        v55 = malloc(v54);
                        v53->nRefCount = (int)v55;
                        v56 = v55;
                        v57 = GetLengthSid(v52);
                        CopySid(v57, v56, v52);
                        QueryAuthorityInfoFromSID(v52, String, (int)&cbSid);
                        if ( *GetSidSubAuthority(v52, 0) != 5 || *GetSidSubAuthority(v52, 1u) )
                          swprintf(ReferencedDomainName, L"%s", String);
                        else
                          swprintf(ReferencedDomainName, L"Logon SID (%s)", String);
                        lParama.pszText = ReferencedDomainName;
                        lParama.mask = 5;
                        lParama.iItem = 0x7FFFFFFF;
                        lParama.iSubItem = 0;
                        lParama.state = 0;
                        lParama.stateMask = 0;
                        lParama.iImage = 0;
                        lParama.lParam = v53;
                        BytesReturned = ::SendMessageW(v119, LVM_INSERTITEMW, 0, (LPARAM)&lParama);
                        if ( BytesReturned == -1 )
                          return 0;
                        szBuffer[0] = 0;
                        if ( *(_BYTE *)v51 & 0x10 )
                          wcscpy_s(szBuffer, 0x104u, L"Deny");
                        if ( *v51 & 0x20000000 )
                        {
                          if ( szBuffer[0] )
                            wcscat_s(szBuffer, 0x104u, L", ");
                          wcscat_s(szBuffer, 0x104u, L"Domain-Local");
                        }
                        if ( *v51 & 1 && !(*v51 & 8) )
                        {
                          if ( szBuffer[0] )
                            wcscat_s(szBuffer, 0x104u, L", ");
                          wcscat_s(szBuffer, 0x104u, L"Mandatory");
                        }
                        if ( *(_BYTE *)v51 & 8 )
                        {
                          if ( szBuffer[0] )
                            wcscat_s(szBuffer, 0x104u, L", ");
                          wcscat_s(szBuffer, 0x104u, L"Owner");
                        }
                        if ( *(_BYTE *)v51 & 0x20 )
                        {
                          if ( szBuffer[0] )
                            wcscat_s(szBuffer, 0x104u, L", ");
                          if ( *(_BYTE *)v51 & 0x40 )
                            wcscat_s(szBuffer, 0x104u, L"Integrity");
                          else
                            wcscat_s(szBuffer, 0x104u, L"DesktopIntegrity");
                        }
                        if ( v117 == 1 )
                        {
                          if ( szBuffer[0] )
                            wcscat_s(szBuffer, 0x104u, L", ");
                          wcscat_s(szBuffer, 0x104u, L"Restricted");
                        }
                        lParama.iItem = BytesReturned;
                        lParama.pszText = szBuffer;
                        lParama.mask = 1;
                        lParama.iSubItem = 1;
                        ::SendMessageW(v119, LVM_SETITEMW, 0, (LPARAM)&lParama);
                        v53->dwStyle = (int)_wcsdup(ReferencedDomainName);
                        v53->field_30 = (int)_wcsdup(szBuffer);
                        v51 += 2;
                        v49 = (int *)TokenInformation;
                        ++v115;
                      }
                      while ( v115 < *(_DWORD *)TokenInformation );
                    }
                  }
                  free(v49);
                  GetTokenInformatio = (void (__stdcall *)(HANDLE, TOKEN_INFORMATION_CLASS, LPVOID, DWORD, PDWORD))GetTokenInformation;
                  GetLastError = ::GetLastError;
                }
                v46 = v117 + 1;
                v117 = v46;
              }
              while ( v46 < 2 );
              GetTokenInformatio(OutBuffer, MaxTokenInfoClass|TokenGroups, 0, 0, &TokenInformationLength);
              if ( GetLastError() == 122 )
              {
                v58 = TokenInformationLength;
                v59 = (PSID *)malloc(TokenInformationLength);
                if ( ((BOOL (__stdcall *)(HANDLE, TOKEN_INFORMATION_CLASS, LPVOID, DWORD, PDWORD))GetTokenInformatio)(
                       OutBuffer,
                       MaxTokenInfoClass|TokenGroups,
                       v59,
                       v58,
                       &TokenInformationLength)
                  && *v59 )
                {
                  v60 = (tagTREEVIEWLISTITEMPARAM *)malloc(0x34u);
                  v61 = v60;
                  BytesReturned = (DWORD)v60;
                  memset(v60, 0, 0x34u);
                  v62 = GetLengthSid(*v59);
                  v63 = malloc(v62);
                  v61->nRefCount = (int)v63;
                  v64 = *v59;
                  v65 = v63;
                  v66 = GetLengthSid(*v59);
                  CopySid(v66, v65, v64);
                  QueryAuthorityInfoFromSID(*v59, String, (int)&cbSid);
                  v67 = v119;
                  lParama.pszText = String;
                  lParama.lParam = v61;
                  SendMessageW = ::SendMessageW;
                  lParama.mask = 5;
                  lParama.iItem = 0x7FFFFFFF;
                  lParama.iSubItem = 0;
                  lParama.state = 0;
                  lParama.stateMask = 0;
                  lParama.iImage = 0;
                  v68 = ::SendMessageW(v119, LVM_INSERTITEMW, 0, (LPARAM)&lParama);
                  if ( v68 == -1 )
                    return 0;
                  lParama.iItem = v68;
                  lParama.mask = 1;
                  lParama.iSubItem = 1;
                  lParama.pszText = L"AppContainer";
                  ::SendMessageW(v67, LVM_SETITEMW, 0, (LPARAM)&lParama);
                  v69 = _wcsdup(String);
                  v70 = BytesReturned;
                  *(_DWORD *)(BytesReturned + 40) = v69;
                  *(_DWORD *)(v70 + 48) = _wcsdup(lParama.pszText);
                  free(v59);
                  GetLastError = ::GetLastError;
                }
                else
                {
                  SendMessageW = ::SendMessageW;
                  free(v59);
                  GetLastError = ::GetLastError;
                }
              }
              else
              {
                SendMessageW = ::SendMessageW;
              }
              GetTokenInformation(OutBuffer, TokenLogonSid|TokenGroups, TokenInformation, 0, &TokenInformationLength);
              if ( GetLastError() == 122 )
              {
                v71 = TokenInformationLength;
                v72 = (void **)malloc(TokenInformationLength);
                BytesReturned = (DWORD)v72;
                if ( GetTokenInformation(OutBuffer, TokenLogonSid|TokenGroups, v72, v71, &TokenInformationLength) )
                {
                  v50 = *v72 == 0;
                  TokenInformation = 0;
                  if ( !v50 )
                  {
                    v73 = v72 + 1;
                    v115 = (unsigned int)(v72 + 1);
                    do
                    {
                      v74 = *v73;
                      v75 = (tagTREEVIEWLISTITEMPARAM *)malloc(0x34u);
                      memset(v75, 0, 0x34u);
                      v76 = GetLengthSid(v74);
                      v77 = malloc(v76);
                      v75->nRefCount = (int)v77;
                      v78 = v77;
                      v79 = GetLengthSid(v74);
                      CopySid(v79, v78, v74);
                      QueryAuthorityInfoFromSID(v74, String, (int)&cbSid);
                      v80 = v119;
                      lParama.pszText = String;
                      lParama.mask = 5;
                      lParama.iItem = 0x7FFFFFFF;
                      lParama.iSubItem = 0;
                      lParama.state = 0;
                      lParama.stateMask = 0;
                      lParama.iImage = 0;
                      lParama.lParam = v75;
                      v81 = SendMessageW(v119, LVM_INSERTITEMW, 0, (LPARAM)&lParama);
                      if ( v81 == -1 )
                        return 0;
                      lParama.iItem = v81;
                      lParama.mask = 1;
                      lParama.iSubItem = 1;
                      lParama.pszText = L"Capability";
                      SendMessageW(v80, LVM_SETITEMW, 0, (LPARAM)&lParama);
                      v75->dwStyle = (int)_wcsdup(String);
                      v82 = _wcsdup(lParama.pszText);
                      v83 = v115;
                      v75->field_30 = (int)v82;
                      v73 = (void **)(v83 + 8);
                      v72 = (void **)BytesReturned;
                      TokenInformation = (char *)TokenInformation + 1;
                      v115 = (unsigned int)v73;
                    }
                    while ( (unsigned int)TokenInformation < *(_DWORD *)BytesReturned );
                  }
                }
                free(v72);
              }
              v84 = (char *)malloc(0x2Cu);
              v85 = (int)v84;
              *((_DWORD *)v84 + 1) = pTokenPrivileges;
              *((_DWORD *)v84 + 9) = v119;
              *(_DWORD *)v84 = 2;
              v84[40] = 0;
              InitializeCriticalSection((LPCRITICAL_SECTION)(v84 + 12));
              *(_DWORD *)(v85 + 8) = _beginthreadex(0, 0, (int)sub_C57440, v85, 0, 0);
              SetWindowLongW(hDlg, GWLP_USERDATA, v85);
              GetTokenInformation(OutBuffer, TokenPrivileges, 0, 0, &TokenInformationLength);
              v86 = TokenInformationLength;
              pTokenPrivileges = (TOKEN_PRIVILEGES *)malloc(TokenInformationLength);
              v50 = GetTokenInformation(OutBuffer, TokenPrivileges, pTokenPrivileges, v86, &TokenInformationLength) == 0;
              v87 = pTokenPrivileges;
              if ( !v50 )
              {
                v50 = pTokenPrivileges->PrivilegeCount == 0;
                TokenInformation = 0;
                if ( !v50 )
                {
                  v88 = (struct _LUID *)&pTokenPrivileges->Privileges[0].Attributes;
                  do
                  {
                    cchName = 260;
                    if ( LookupPrivilegeNameW(0, v88 - 1, Name, &cchName) )
                    {
                      lParama.mask = 5;
                      lParama.pszText = Name;
                      lParama.iItem = 0x7FFFFFFF;
                      lParama.iSubItem = 0;
                      lParama.state = 0;
                      lParama.stateMask = 0;
                      lParama.iImage = 0;
                      lParama.lParam = (tagTREEVIEWLISTITEMPARAM *)1;
                      BytesReturned = SendMessageW(v113, 0x104Du, 0, (LPARAM)&lParama);
                      if ( BytesReturned == -1 )
                        return 0;
                      Dst[0] = 0;
                      if ( v88->LowPart & 2 )
                        wcscpy_s(Dst, 0x104u, L"Enabled");
                      else
                        wcscpy_s(Dst, 0x104u, L"Disabled");
                      if ( v88->LowPart & 1 )
                      {
                        if ( Dst[0] )
                          wcscat_s(Dst, 0x104u, L", ");
                        wcscpy_s(Dst, 0x104u, L"Default Enabled");
                      }
                      lParama.iItem = BytesReturned;
                      lParama.pszText = Dst;
                      lParama.mask = 1;
                      lParama.iSubItem = 1;
                      SendMessageW(v113, 0x104Cu, 0, (LPARAM)&lParama);
                    }
                    v88 = (struct _LUID *)((char *)v88 + 12);
                    TokenInformation = (char *)TokenInformation + 1;
                  }
                  while ( (unsigned int)TokenInformation < pTokenPrivileges->PrivilegeCount );
                  v87 = pTokenPrivileges;
                }
              }
              free(v87);
              CloseHandle(OutBuffer);
              CloseHandle(InBuffer);
              v89 = v119;
            }
            else
            {
              v85 = v117;
              CloseHandle(InBuffer);
              v89 = v119;
            }
          }
          else
          {
            v89 = v119;
            if ( pTokenPrivileges[2].Privileges[0].Luid.HighPart & 0x400 )
            {
              lParama.mask = 5;
              lParama.iItem = 0x7FFFFFFF;
              lParama.iSubItem = 0;
              lParama.state = 0;
              lParama.stateMask = 0;
              lParama.pszText = L"Error: Process is Protected";
              lParama.iImage = 0;
              lParama.lParam = (tagTREEVIEWLISTITEMPARAM *)1;
              if ( ::SendMessageW(v119, 0x104Du, 0, (LPARAM)&lParama) == -1 )
                return 0;
            }
            v85 = v117;
          }
          if ( !v85 )
          {
            v90 = GetDlgItem(hDlg, 1210);
            EnableWindow(v90, 0);
          }
          InvalidateRect(v89, 0, 0);
          v106 = nItem;
          wParama = 1040;
          SendMessageW(v89, 0x1030u, (WPARAM)&wParama, (LPARAM)BackendSortCallback);
          v91 = v113;
          SendMessageW(v113, 0x101Eu, 0, 0xFFFF);
          SendMessageW(v91, 0x101Eu, 1u, 65534);
          SendMessageW(v89, 0x101Eu, 0, 0xFFFF);
          SendMessageW(v89, 0x101Eu, 1u, 65534);
          return 1;
        case WM_COMMAND:
          if ( (signed int)(unsigned __int16)wParam > 40001 )
          {
            if ( (unsigned int)(unsigned __int16)wParam - 40092 > 1 )
              return 0;
            v98 = wParam;
          }
          else
          {
            if ( (unsigned __int16)wParam != 40001 )
            {
              if ( (unsigned __int16)wParam == 1210 )
              {
                InBuffer = OpenProcess(0xE0000u, 0, *(_DWORD *)(*(_DWORD *)(v4 + 4) + 68));
                if ( InBuffer || (InBuffer = OpenProcess(0x20000u, 0, *(_DWORD *)(*(_DWORD *)(v4 + 4) + 68))) != 0 )
                {
                  memset(pListParam, 0, 0x10C0u);
                  wsprintfW(
                    (wchar_t *)&pListParam[3].field_4,
                    L"%s: %d",
                    *(_DWORD *)(*(_DWORD *)(v4 + 4) + 60),
                    *(_DWORD *)(*(_DWORD *)(v4 + 4) + 68));
                  pListParam[0].field_28 = 0;
                  wcscpy_s((wchar_t *)&pListParam[0].field_38, 0x40u, L"Process");
                  pListParam[0].field_2C = (int)InBuffer;
                  pListParam[0].field_24 = GetCurrentProcessId();
                  FillHandleListParam(hWnd, pListParam);
                  CloseHandle(InBuffer);
                }
                else
                {
                  ReportMsg(L"Error opening process", hWnd);
                }
              }
              return 0;
            }
            v98 = 40014;
          }
          v93 = GetParent(hWnd);
          PostMessageW(v93, WM_COMMAND, v98, 0);
          return 0;
        default:
          return 0;
      }
    }
    return PE_FillControl((int)hWnd, (HDC)wParam);
  }
  if ( msg > 0x7F1 )
  {
    if ( msg == 2038 )
    {
      InvalidateRect((HWND)pTokenPrivileges, 0, 0);
    }
    else if ( msg == 2039 )
    {
      Item.pszText = (LPWSTR)pTokenPrivileges;
      Item.iSubItem = 0;
      ::SendMessageW(*(HWND *)(v4 + 36), LVM_SETITEMTEXTW, wParam, (LPARAM)&Item);
    }
    return 0;
  }
  if ( msg == 2033 )
  {
    if ( v4 )
    {
      EnterCriticalSection((LPCRITICAL_SECTION)(v4 + 12));
      *(_BYTE *)(v4 + 40) = 1;
      LeaveCriticalSection((LPCRITICAL_SECTION)(v4 + 12));
      if ( !InterlockedDecrement((volatile LONG *)v4) )
      {
        DeleteCriticalSection((LPCRITICAL_SECTION)(v4 + 12));
        free((void *)v4);
      }
    }
    return 0;
  }
  if ( msg == 310 || msg == 312 )
    return PE_FillControl((int)hWnd, (HDC)wParam);
  return 0;
}
// CB60B4: using guessed type wchar_t aYes[4];
// CB60C4: using guessed type wchar_t aLogonSidS[15];
// CB612C: using guessed type wchar_t aIntegrity[10];
// CB617C: using guessed type wchar_t aCapability[11];
// CB61B4: using guessed type wchar_t aErrorProcessIs[28];
// CB6C70: using guessed type __int128 xmmword_CB6C70;
// CCD224: using guessed type char byte_CCD224;
// CD4E54: using guessed type int gdwVersion;

//----- (00C58E00) --------------------------------------------------------
int __stdcall PageProcServices(HWND hDlg, int a2, WPARAM wParam, int a4)
{
  HWND v4; // edi
  CResizer *v5; // eax
  HWND v6; // eax
  struct tagResizerItem *v7; // eax
  HWND v8; // eax
  HICON v9; // ST20_4
  HWND v10; // eax
  LONG v11; // eax
  HWND v12; // eax
  void *v13; // ecx
  wchar_t *v14; // eax
  wchar_t *v15; // esi
  int v16; // edx
  wchar_t v17; // cx
  HWND v18; // eax
  DWORD v19; // ebx
  LONG v20; // edx
  int v21; // esi
  int v22; // eax
  WCHAR *v23; // eax
  int result; // eax
  LONG v25; // edi
  int v26; // eax
  int v27; // eax
  HWND v28; // eax
  HWND v29; // eax
  HWND v30; // eax
  HWND v31; // eax
  HWND v32; // eax
  HWND v33; // eax
  HWND v34; // ST14_4
  SC_HANDLE v35; // esi
  size_t v36; // esi
  BYTE *v37; // edi
  DWORD v38; // ST1C_4
  HWND v39; // eax
  BOOL v40; // ST20_4
  HWND v41; // eax
  BOOL v42; // eax
  BOOL v43; // ST20_4
  HWND v44; // eax
  BOOL v45; // ST20_4
  HWND v46; // eax
  BOOL v47; // eax
  BOOL v48; // ST20_4
  HWND v49; // eax
  BOOL v50; // eax
  BOOL v51; // ST20_4
  HWND v52; // eax
  HWND v53; // eax
  HWND v54; // eax
  HWND v55; // eax
  HWND v56; // eax
  HWND v57; // eax
  HWND v58; // eax
  SC_HANDLE v59; // esi
  INT_PTR v60; // eax
  HWND v61; // eax
  WPARAM v62; // [esp-8h] [ebp-13ACh]
  LPARAM lParam; // [esp+10h] [ebp-1394h]
  int v64; // [esp+1Ch] [ebp-1388h]
  int v65; // [esp+20h] [ebp-1384h]
  LPARAM v66; // [esp+44h] [ebp-1360h]
  int v67; // [esp+4Ch] [ebp-1358h]
  int v68; // [esp+50h] [ebp-1354h]
  size_t pcbBytesNeeded; // [esp+54h] [ebp-1350h]
  LVITEMW Item; // [esp+58h] [ebp-134Ch]
  void *v71; // [esp+8Ch] [ebp-1318h]
  SC_HANDLE hSCObject; // [esp+90h] [ebp-1314h]
  LONG dwNewLong; // [esp+94h] [ebp-1310h]
  char v74; // [esp+9Bh] [ebp-1309h]
  LPARAM pListParam; // [esp+9Ch] [ebp-1308h]
  DWORD v76; // [esp+C0h] [ebp-12E4h]
  int v77; // [esp+C4h] [ebp-12E0h]
  SC_HANDLE v78; // [esp+C8h] [ebp-12DCh]
  wchar_t v79; // [esp+D4h] [ebp-12D0h]
  wchar_t Dst; // [esp+154h] [ebp-1250h]
  struct _SERVICE_STATUS ServiceStatus; // [esp+115Ch] [ebp-248h]
  UINT pnIDs; // [esp+1178h] [ebp-22Ch]
  int v83; // [esp+117Ch] [ebp-228h]
  int v84; // [esp+1180h] [ebp-224h]
  WCHAR ServiceName; // [esp+1184h] [ebp-220h]
  WORD pnWidths[2]; // [esp+138Ch] [ebp-18h]
  __int16 v87; // [esp+1390h] [ebp-14h]
  int v88; // [esp+13A0h] [ebp-4h]

  dwNewLong = a4;
  v4 = GetDlgItem(hDlg, 1036);
  GetWindowLongW(hDlg, -21);
  Item.mask = 0;
  memset(&Item.iItem, 0, 0x30u);
  v74 = 0;
  pnIDs = 1039;
  v83 = 1044;
  v84 = 1061;
  pnWidths[0] = MulDiv(100, gLogPixelSize.x, 96);
  pnWidths[1] = MulDiv(100, gLogPixelSize.x, 96);
  v87 = MulDiv(100, gLogPixelSize.x, 96);
  if ( (unsigned int)a2 > 0x111 )
  {
    if ( a2 == 307 || a2 == 310 || a2 == 312 )
      return PE_FillControl((int)hDlg, (HDC)wParam);
    return 0;
  }
  if ( a2 == 273 )
  {
    v71 = (void *)(unsigned __int16)wParam;
    if ( (signed int)(unsigned __int16)wParam <= 40001 )
    {
      if ( (unsigned __int16)wParam != 40001 )
      {
        switch ( (unsigned __int16)wParam )
        {
          case 0x4BAu:
          case 0x4BBu:
          case 0x4BCu:
          case 0x4BDu:
          case 0x4BFu:
            Item.iItem = SendMessageW(v4, 0x100Cu, 0xFFFFFFFF, 2);
            Item.pszText = &ServiceName;
            Item.iSubItem = 0;
            Item.cchTextMax = 260;
            Item.mask = 1;
            SendMessageW(v4, 0x104Bu, 0, (LPARAM)&Item);
            Item.iSubItem = (int)v71;
            v60 = DialogBoxParamW(ghInstance, L"SERVICECONTROL", hDlg, DlgServiceControl, (LPARAM)&Item);
            if ( v60 == 1 )
            {
              MessageBoxW(
                hDlg,
                L"The service didn't respond to the control request in a timely manner",
                L"Process Explorer",
                0x10u);
            }
            else if ( v60 == 2 && (_WORD)wParam == 1210 )
            {
              SendMessageW(v4, 0x1008u, Item.iItem, 0);
            }
            v66 = (LPARAM)v4;
            v67 = -101;
            SendMessageW(hDlg, 0x4Eu, 0, (LPARAM)&v66);
            QueryServiceNames();
            SetFocus(v4);
            result = 0;
            break;
          case 0x51Au:
            Item.iItem = SendMessageW(v4, 0x100Cu, 0xFFFFFFFF, 2);
            Item.pszText = &ServiceName;
            Item.iSubItem = 0;
            Item.cchTextMax = 260;
            Item.mask = 1;
            SendMessageW(v4, 0x104Bu, 0, (LPARAM)&Item);
            v59 = OpenServiceW(ghSCManagerHandle, &ServiceName, 0x60000u);
            if ( v59 )
            {
              memset(&pListParam, 0, 0x10C0u);
              wcscpy_s(&Dst, 0x400u, &ServiceName);
              v77 = 0;
              wcscpy_s(&v79, 0x40u, L"Service");
              v78 = v59;
              v76 = GetCurrentProcessId();
              FillHandleListParam(hDlg, (tagHANDLELISTITEMPARAM *)&pListParam);
              CloseServiceHandle(v59);
            }
            else
            {
              ReportMsg(L"Error opening service", hDlg);
            }
            result = 0;
            break;
          default:
            return 0;
        }
        return result;
      }
      v62 = 40014;
LABEL_78:
      v61 = GetParent(hDlg);
      PostMessageW(v61, 0x111u, v62, 0);
      return 0;
    }
    if ( (unsigned __int16)wParam == 40002 )
    {
      SetEvent(ghRefreshEventHandle);
      return 0;
    }
    if ( (unsigned int)(unsigned __int16)wParam - 40092 <= 1 )
    {
      v62 = wParam;
      goto LABEL_78;
    }
    return 0;
  }
  switch ( a2 )
  {
    case 43:
      CMainWnd::DrawItem((LPDRAWITEMSTRUCT)dwNewLong);
      return 0;
    case 44:
      return CMainWnd::HandleMeasureItem(hDlg, a2, wParam, (LPMEASUREITEMSTRUCT)dwNewLong);
    case 78:
      v25 = dwNewLong;
      v26 = *(_DWORD *)(dwNewLong + 8);
      if ( v26 != -101 && (unsigned int)(v26 + 3) > 1 )
        return 0;
      SetDlgItemTextW(hDlg, 1059, (LPCWSTR)&gszNullString);
      v27 = SendMessageW(*(HWND *)v25, 0x100Cu, 0xFFFFFFFF, 2);
      if ( v27 == -1 )
      {
        v28 = GetDlgItem(hDlg, 1306);
        EnableWindow(v28, 0);
        v29 = GetDlgItem(hDlg, 1213);
        EnableWindow(v29, 0);
        v30 = GetDlgItem(hDlg, 1210);
        EnableWindow(v30, 0);
        v31 = GetDlgItem(hDlg, 1211);
        EnableWindow(v31, 0);
        v32 = GetDlgItem(hDlg, 1212);
        EnableWindow(v32, 0);
        v33 = GetDlgItem(hDlg, 1215);
        EnableWindow(v33, 0);
        return 0;
      }
      Item.iItem = v27;
      Item.pszText = &ServiceName;
      v34 = *(HWND *)v25;
      Item.iSubItem = 0;
      Item.cchTextMax = 260;
      Item.mask = 1;
      if ( SendMessageW(v34, 0x104Bu, 0, (LPARAM)&Item) != 1 )
        return 0;
      v35 = OpenServiceW(ghSCManagerHandle, &ServiceName, 5u);
      hSCObject = v35;
      if ( !v35 )
      {
        v53 = GetDlgItem(hDlg, 1306);
        EnableWindow(v53, 0);
        v54 = GetDlgItem(hDlg, 1213);
        EnableWindow(v54, 0);
        v55 = GetDlgItem(hDlg, 1215);
        EnableWindow(v55, 0);
        v56 = GetDlgItem(hDlg, 1210);
        EnableWindow(v56, 0);
        v57 = GetDlgItem(hDlg, 1211);
        EnableWindow(v57, 0);
        v58 = GetDlgItem(hDlg, 1212);
        EnableWindow(v58, 0);
        return 0;
      }
      if ( *(_DWORD *)QueryServiceConfig2W )
      {
        QueryServiceConfig2W(v35, 1u, 0, 0, &pcbBytesNeeded);
        if ( GetLastError() == 122 )
        {
          v36 = pcbBytesNeeded;
          v37 = (BYTE *)malloc(pcbBytesNeeded);
          v38 = v36;
          v35 = hSCObject;
          QueryServiceConfig2W(hSCObject, 1u, v37, v38, &pcbBytesNeeded);
          SetDlgItemTextW(hDlg, 1059, *(LPCWSTR *)v37);
          free(v37);
          v25 = dwNewLong;
        }
      }
      QueryServiceStatus(v35, &ServiceStatus);
      v39 = GetDlgItem(hDlg, 1306);
      EnableWindow(v39, 1);
      v40 = ServiceStatus.dwCurrentState == 1;
      v41 = GetDlgItem(hDlg, 1213);
      EnableWindow(v41, v40);
      v42 = ServiceStatus.dwCurrentState == 4 && ServiceStatus.dwControlsAccepted & 2;
      v43 = v42;
      v44 = GetDlgItem(hDlg, 1212);
      EnableWindow(v44, v43);
      v45 = ServiceStatus.dwCurrentState == 7;
      v46 = GetDlgItem(hDlg, 1211);
      EnableWindow(v46, v45);
      v47 = (ServiceStatus.dwCurrentState == 4 || ServiceStatus.dwCurrentState == 7)
         && ServiceStatus.dwControlsAccepted & 1;
      v48 = v47;
      v49 = GetDlgItem(hDlg, 1210);
      EnableWindow(v49, v48);
      v50 = (ServiceStatus.dwCurrentState == 4 || ServiceStatus.dwCurrentState == 7)
         && ServiceStatus.dwControlsAccepted & 1;
      v51 = v50;
      v52 = GetDlgItem(hDlg, 1215);
      EnableWindow(v52, v51);
      CloseServiceHandle(hSCObject);
      if ( *(_DWORD *)(v25 + 8) == -3 )
      {
        SendMessageW(hDlg, 0x111u, 0x51Au, 0);
        return 0;
      }
      return 0;
    case 272:
      v5 = (CResizer *)operator new(0x40u);
      v71 = v5;
      v88 = 0;
      if ( v5 )
        hSCObject = CResizer::CResizer(v5, hDlg);
      else
        hSCObject = 0;
      v88 = -1;
      v6 = GetDlgItem(hDlg, 1036);
      if ( v6 )
      {
        v7 = CResizer::AddItem((CResizer *)hSCObject, v6, 1);
        *(_QWORD *)&v7->gap0[16] = 0i64;
        *(double *)&v7->gap0[24] = db_one;
      }
      v8 = GetDlgItem(hDlg, 1210);
      if ( v8 )
        *(_OWORD *)CResizer::AddItem((CResizer *)hSCObject, v8, 1)->gap0 = xmmword_CB6C70;
      PropSheet_UpdateTab(hDlg);
      v9 = LoadIconW(ghInstance, (LPCWSTR)0xEB);
      v10 = GetDlgItem(hDlg, 1129);
      SendMessageW(v10, 0x172u, 1u, (LPARAM)v9);
      SetWindowLongW(hDlg, -21, dwNewLong);
      v11 = GetWindowLongW(v4, -16);
      SetWindowLongW(v4, -16, v11 & 0xFFFFFFFD | 1);
      SendMessageW(v4, 0x1036u, 0x4020u, 16416);
      v12 = (HWND)SendMessageW(v4, 0x104Eu, 0, 0);
      CTreeList::InitToolTips(v12);
      gOldListWndProc = (WNDPROC)SetWindowLongW(v4, -4, (LONG)Proxy_ListCtrlWndProc);
      SendMessageW(v4, 0x30u, (WPARAM)ghConfigFont, 0);
      v13 = *(void **)(dwNewLong + 792);
      hSCObject = v13;
      if ( !v13 )
      {
        v13 = *(void **)(dwNewLong + 60);
        hSCObject = *(SC_HANDLE *)(dwNewLong + 60);
      }
      v14 = _wcsdup((const wchar_t *)v13);
      v15 = v14;
      v16 = (int)(v14 + 1);
      do
      {
        v17 = *v14;
        ++v14;
      }
      while ( v17 );
      _wcsupr_s(v15, (((signed int)v14 - v16) >> 1) + 1);
      if ( wcsstr(v15, L"SVCHOST.EXE") )
      {
        InitListHeader(v4, &pnIDs, pnWidths, 3);
        v74 = 1;
      }
      else
      {
        InitListHeader(v4, &pnIDs, pnWidths, 2);
      }
      free(v15);
      if ( !*(_DWORD *)CreateSecurityPage )
      {
        v18 = GetDlgItem(hDlg, 1306);
        ShowWindow(v18, 0);
      }
      QueryServiceNames();
      EnterCriticalSection(&gServiceLock);
      v19 = 0;
      if ( !gdwServiceReturned )
        goto LABEL_29;
      v20 = dwNewLong;
      v21 = 0;
      break;
    default:
      return 0;
  }
  do
  {
    if ( gpszServiceNames[v21].ServiceStatusProcess.dwProcessId == *(_DWORD *)(v20 + 68) )
    {
      Item.mask = 5;
      Item.iItem = 0x7FFFFFFF;
      Item.iSubItem = 0;
      Item.stateMask = 0;
      Item.state = 0;
      Item.pszText = gpszServiceNames[v21].lpServiceName;
      Item.lParam = (tagTREEVIEWLISTITEMPARAM *)(v19 + 1);
      Item.iImage = 0;
      v22 = SendMessageW(v4, LVM_INSERTITEMW, 0, (LPARAM)&Item);
      v68 = v22;
      if ( v22 == -1 )
        return 0;
      Item.iItem = v22;
      Item.mask = 1;
      Item.iSubItem = 1;
      Item.pszText = gpszServiceNames[v21].lpDisplayName;
      SendMessageW(v4, 0x104Cu, 0, (LPARAM)&Item);
      if ( v74 )
      {
        v23 = sub_C34780((wchar_t *)hSCObject, gpszServiceNames[v21].lpServiceName);
        v71 = v23;
        if ( v23 )
        {
          Item.pszText = v23;
          Item.mask = 1;
          Item.iItem = v68;
          Item.iSubItem = 2;
          SendMessageW(v4, 0x104Cu, 0, (LPARAM)&Item);
          free(v71);
        }
      }
      v20 = dwNewLong;
    }
    ++v19;
    ++v21;
  }
  while ( v19 < gdwServiceReturned );
LABEL_29:
  LeaveCriticalSection(&gServiceLock);
  SendMessageW(v4, 0x101Eu, 0, 0xFFFF);
  SendMessageW(v4, 0x101Eu, 1u, (v74 != 0) + 65534);
  if ( v74 )
    SendMessageW(v4, 0x101Eu, 2u, 65534);
  v65 = 3;
  v64 = 3;
  SendMessageW(v4, 0x102Bu, 0, (LPARAM)&lParam);
  SetFocus(v4);
  return 1;
}
// CB6C70: using guessed type __int128 xmmword_CB6C70;