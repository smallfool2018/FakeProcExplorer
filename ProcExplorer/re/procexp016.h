//----- (010357D0) --------------------------------------------------------
int __cdecl CMainWnd::HandleClose(HWND hWnd)
{
  if ( gConfig.bHideWhenMinimized )
    CMainWnd::Hide(ghMainWnd);
  else
    CMainWnd::HandleDestroy(hWnd);
  return 0;
}

//----- (01035810) --------------------------------------------------------
int CMainWnd::HandleEndSession()
{
  UpdateWindowPlacement(ghMainWnd, 1);
  return 0;
}

//----- (01035830) --------------------------------------------------------
int __cdecl CMainWnd::HandleDestroy(HWND hWnd)
{
  signed int nIndex; // esi
  HANDLE v2; // eax

  ShowWindow(hWnd, 0);
  UpdateWindowPlacement(ghMainWnd, 1);
  nIndex = 1;
  do
    TrayIcon_Delete(hWnd, nIndex++);
  while ( nIndex < 8 );
  SetEvent(ghEvent3);
  PE_RunTrace(&gProperties, 0);
  TerminateThread(ghBackupRefreshThreadHandle, 0);
  v2 = GetCurrentProcess();
  TerminateProcess(v2, 0);
  PostQuitMessage(0);
  return 0;
}

//----- (010358B0) --------------------------------------------------------
int __cdecl CMainWnd::HandleDrawItem(HWND a1, unsigned int a2, unsigned int a3, LPDRAWITEMSTRUCT a4)
{
  if ( a4->CtlType != 1 )
    return CMainWnd::DrawList(a4);
  DrawIconEx(a4->hDC, a4->rcItem.left - 15, a4->rcItem.top, a4->itemData, 16, 16, 0, 0, 3u);
  return 0;
}

//----- (010358F0) --------------------------------------------------------
signed int __cdecl CMainWnd::HandleSetFocus(HWND a1)
{
  signed int result; // eax

  gdwTickLast = GetTickCount();
  if ( ghWndFocusedLast )
  {
    SetFocus(ghWndFocusedLast);
    result = 1;
  }
  else if ( a1 == ghMainWnd )
  {
    SetFocus(ghWndTreeListView);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 10CA380: using guessed type unsigned int gdwTickLast;

//----- (01035940) --------------------------------------------------------
LRESULT __cdecl CMainWnd::HandleContextMenu(HWND hWnd_1, UINT Msg, HWND hWnd, LPARAM a4)
{
  UINT uID; // edi
  LRESULT v5; // eax
  HWND hWnd_2; // [esp+8h] [ebp-48h]
  struct tagPOINT Point; // [esp+34h] [ebp-1Ch]
  RECT lParam; // [esp+3Ch] [ebp-14h]

  if ( hWnd == ghWndTreeListView )
  {
    uID = IDC_TREEVIEW_LIST;
  }
  else if ( hWnd == ghWndHandlesListCtrl )
  {
    uID = IDC_LISTCTRL_HANDLES;
  }
  else
  {
    if ( hWnd != ghWndDllsListCtrl )
      return DefWindowProcW(hWnd_1, Msg, hWnd, a4);
    uID = IDC_LISTCTRL_DLLS;
  }
  hWnd_2 = hWnd_1;
  Point.x = a4;
  Point.y = SHIWORD(a4);
  if ( a4 != -1 )
    return 0;
  v5 = SendMessageW(hWnd, LVM_GETNEXTITEM, a4, 2);
  if ( v5 != -1 )
  {
    lParam.left = 0;
    SendMessageW(hWnd, LVM_GETITEMRECT, v5, &lParam);
    Point.y = lParam.bottom;
    Point.x = lParam.left + 10;
    ClientToScreen(hWnd, &Point);
  }
  return UpdateListViewContextMenu(uID, &hWnd_2, &Point);
}

//----- (01035A40) --------------------------------------------------------
int __cdecl CMainWnd::HandleMsg7EF(int _8, int a2, int a3, void *a1)
{
  sub_1018460(a1);
  return 0;
}

//----- (01035A60) --------------------------------------------------------
int __cdecl CMainWnd::HandleMsg7F8(HWND a1, unsigned int a2, unsigned int a3, const wchar_t **a4)
{
  tagTREEVIEWLISTITEMPARAM *v4; // esi
  char v5; // cl
  tagTREEVIEWLISTITEMPARAM *v6; // ebx
  const wchar_t *v7; // eax
  wchar_t *v8; // eax
  const wchar_t *v9; // eax
  DLLLISTITEMPARAM *v10; // esi
  char v11; // bl
  const wchar_t *v12; // eax
  char v14; // [esp+Bh] [ebp-1h]

  v4 = gpTreeViewListItemParam;
  v5 = 0;
  v6 = 0;
  v14 = 0;
  if ( !gpTreeViewListItemParam )
    return 0;
  do
  {
    v7 = v4->szProcessName;
    if ( v4->dwProcessId == gdwProcessIdSelected )
      v6 = v4;
    if ( v7 )
    {
      if ( _wcsicmp(v7, a4[1]) || _wcsicmp(L"system", *a4) && _wcsicmp(v4->pszName, *a4) )
      {
        v5 = v14;
      }
      else
      {
        v8 = _wcsdup(a4[2]);
        v5 = 1;
        v4->field_33C = v8;
        v14 = 1;
      }
    }
    v4 = v4->m_Prev;
  }
  while ( v4 );
  if ( v5 )
  {
    if ( RedrawColumn(1, ghWndTreeListView, 1656, 0) )
    {
      InvalidateRect(ghWndTreeListView, 0, 0);
      sub_101FAA0(0x65);
    }
    else if ( IsColumnIDValid(ghWndTreeListView, 0x678u) )
    {
      InvalidateRect(ghWndTreeListView, 0, 0);
    }
  }
  if ( v6 )
  {
    if ( IsWindowVisible(ghWndDllsListCtrl) )
    {
      if ( !_wcsicmp(L"system", *a4) || (v9 = v6->pszName) != 0 && !_wcsicmp(v9, *a4) )
      {
        v10 = gpDllListItemParamHeader;
        v11 = 0;
        if ( gpDllListItemParamHeader )
        {
          do
          {
            v12 = v10->m_strPath.pszData;
            if ( v12 && !_wcsicmp(v12, a4[1]) )
            {
              v10->m_strLocation = _wcsdup(a4[2]);
              v11 = 1;
            }
            v10 = v10->m_Prev;
          }
          while ( v10 );
          if ( v11 )
          {
            InvalidateRect(ghWndDllsListCtrl, 0, 0);
            sub_101FAA0(0x68);
          }
        }
      }
    }
  }
  return 0;
}

//----- (01035C10) --------------------------------------------------------
int __cdecl CMainWnd::HandleMsg7F6(int a1, int a2, int a3, HWND hWnd)
{
  InvalidateRect(hWnd, 0, 0);
  return 0;
}

//----- (01035C30) --------------------------------------------------------
signed int CMainWnd::HandleKillFocus()
{
  ghWndFocusedLast = GetFocus();
  return 1;
}

//----- (01035C50) --------------------------------------------------------
int __cdecl CMainWnd::HandleMsg7F0(HWND a1, unsigned int a2, unsigned int a3, int pListItem)
{
  if ( *(pListItem + 4) )
  {
    if ( *(pListItem + 356) )
      free(*(pListItem + 356));
    *(pListItem + 356) = _wcsdup(*(pListItem + 360));
    if ( IsColumnIDValid(ghWndDllsListCtrl, 0x4A3u) )
      InvalidateRect(ghWndDllsListCtrl, 0, 0);
  }
  else
  {
    if ( *(pListItem + 836) )
      free(*(pListItem + 836));
    *(pListItem + 836) = _wcsdup(*(pListItem + 840));
    if ( RedrawColumn(1, ghWndTreeListView, 1187, 0) )
    {
      InvalidateRect(ghWndTreeListView, 0, 0);
      sub_101FAA0(0x65);
      return 0;
    }
    if ( IsColumnIDValid(ghWndTreeListView, 0x4A3u) )
    {
      InvalidateRect(ghWndTreeListView, 0, 0);
      return 0;
    }
  }
  return 0;
}

//----- (01035D40) --------------------------------------------------------
_DWORD *__cdecl CMainWnd::HandleMsg7EE(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
  LRESULT ret; // esi
  tagTREEVIEWLISTITEMPARAM *nItem; // ebx

  ret = -1;
  if ( !gConfig.bShowNewProcesses )
  {
    ret = SendMessageW(ghWndTreeListView, LVM_GETNEXTITEM, 0xFFFFFFFF, 2);
    if ( !SendMessageW(ghWndTreeListView, LVM_ISITEMVISIBLE, ret, 0) )
      ret = -1;
  }
  nItem = CTreeList::FindItem(ghWndTreeListView, lParam);
  if ( ret != -1 )
    SendMessageW(ghWndTreeListView, LVM_ENSUREVISIBLE, ret, 0);
  return &nItem->field_0;
}

//----- (01035DC0) --------------------------------------------------------
int __cdecl CMainWnd::HandleInitMenuPopup(HWND hWnd, unsigned int nPos, HMENU hMenu)
{
  UINT v3; // esi
  DWORD v4; // esi
  int nIndex; // ebx
  HMENU hMenuUser; // esi
  UINT_PTR v7; // ST0C_4
  UINT v8; // esi
  MENUINFO MenuInfo; // [esp+0h] [ebp-244h]
  DWORD cbRet; // [esp+1Ch] [ebp-228h]
  UINT uPosition; // [esp+20h] [ebp-224h]
  PWTS_SESSION_INFOW pszDomainName; // [esp+24h] [ebp-220h]
  DWORD v14; // [esp+28h] [ebp-21Ch]
  PWTS_SESSION_INFOW pszUserName; // [esp+2Ch] [ebp-218h]
  DWORD nCount; // [esp+30h] [ebp-214h]
  PWTS_SESSION_INFOW pSessionInfo; // [esp+34h] [ebp-210h]
  __int16 NewItem[260]; // [esp+38h] [ebp-20Ch]

  if ( hMenu != ghUserPopupMenuHandle )
    return 0;
  nCount = GetMenuItemCount(ghUserPopupMenuHandle);
  v3 = nCount - 1;
  if ( nCount )
  {
    do
      DeleteMenu(ghUserPopupMenuHandle, v3--, MF_BYPOSITION);
    while ( v3 != -1 );
  }
  if ( WTSEnumerateSessionsW(0, 0, 1u, &pSessionInfo, &nCount) )
  {
    v4 = 0;
    uPosition = 0;
    v14 = 0;
    if ( nCount )
    {
      nIndex = 0;
      do
      {
        if ( WTSQuerySessionInformationW(0, pSessionInfo[nIndex].SessionId, WTSUserName, &pszUserName, &cbRet) )
        {
          if ( WTSQuerySessionInformationW(0, pSessionInfo[nIndex].SessionId, WTSDomainName, &pszDomainName, &cbRet) )
          {
            if ( LOWORD(pszUserName->SessionId) )
            {
              swprintf(NewItem, L"%d: %s\\%s", pSessionInfo[nIndex].SessionId, pszDomainName, pszUserName);
              hMenuUser = LoadMenuW(ghInstance, L"USERS");
              MenuInfo.cbSize = 28;
              MenuInfo.fMask = 0x80000018;
              MenuInfo.dwStyle = MNS_NOTIFYBYPOS;
              MenuInfo.dwMenuData = pSessionInfo[nIndex].SessionId;
              SetMenuInfo(hMenuUser, &MenuInfo);
              switch ( pSessionInfo[nIndex].State )
              {
                case WTSActive:
                case WTSShadow:
                  break;
                case WTSConnected:
                  EnableMenuItem(hMenuUser, IDM_USERS_CONNECT, MF_GRAYED);
                  EnableMenuItem(hMenuUser, IDM_USERS_LOGOFF, MF_GRAYED);
                  EnableMenuItem(hMenuUser, IDM_USERS_SEND_MESSAGE, MF_GRAYED);
                  break;
                case WTSDisconnected:
                  EnableMenuItem(hMenuUser, IDM_USERS_DISCONNECT, MF_GRAYED);
                  EnableMenuItem(hMenuUser, IDM_USERS_SEND_MESSAGE, MF_GRAYED);
                  break;
                default:
                  EnableMenuItem(hMenuUser, IDM_USERS_CONNECT, MF_GRAYED);
                  EnableMenuItem(hMenuUser, IDM_USERS_SEND_MESSAGE, MF_GRAYED);
                  EnableMenuItem(hMenuUser, IDM_USERS_LOGOFF, MF_GRAYED);
                  EnableMenuItem(hMenuUser, IDM_USERS_DISCONNECT, MF_GRAYED);
                  EnableMenuItem(hMenuUser, IDM_USERS_REMOTE_CONTROL, MF_GRAYED);
                  break;
              }
              v7 = hMenuUser;
              v8 = uPosition;
              InsertMenuW(ghUserPopupMenuHandle, uPosition, 0x410u, v7, NewItem);
              uPosition = v8 + 1;
              v4 = v14;
            }
            WTSFreeMemory(pszDomainName);
          }
          WTSFreeMemory(pszUserName);
        }
        ++v4;
        ++nIndex;
        v14 = v4;
      }
      while ( v4 < nCount );
    }
    WTSFreeMemory(pSessionInfo);
  }
  return 0;
}

//----- (01036050) --------------------------------------------------------
LRESULT __cdecl CMainWnd::HandleMenuCommand(HWND hWnd, int a2, int nPos, HMENU hMenu)
{
  UINT v4; // eax
  UINT v5; // esi
  LRESULT result; // eax
  int v7; // eax
  int *v8; // eax
  int v9; // eax
  char v10; // bl
  DWORD v11; // eax
  int v12; // [esp+Ch] [ebp-458h]
  HWND v13; // [esp+10h] [ebp-454h]
  const wchar_t *v14; // [esp+14h] [ebp-450h]
  const wchar_t *v15; // [esp+18h] [ebp-44Ch]
  int v16; // [esp+1Ch] [ebp-448h]
  struct tagMENUINFO v17; // [esp+20h] [ebp-444h]
  LPWSTR ppBuffer; // [esp+3Ch] [ebp-428h]
  _bstr_t v19; // [esp+40h] [ebp-424h]
  int v20; // [esp+44h] [ebp-420h]
  int v21; // [esp+48h] [ebp-41Ch]
  DWORD nSize; // [esp+4Ch] [ebp-418h]
  WCHAR Buffer; // [esp+50h] [ebp-414h]
  OLECHAR psz; // [esp+258h] [ebp-20Ch]
  char v25; // [esp+25Ah] [ebp-20Ah]

  psz = 0;
  memset(&v25, 0, 0x206u);
  v4 = GetMenuItemID(hMenu, nPos);
  v5 = v4;
  if ( v4 != 40621 && v4 != 40622 && v4 != 40623 && v4 != 40625 && v4 != 40743 && v4 != 40744 )
    return HandleCmdHandler(&CMainWnd::gCmdHandler, hWnd, v4, 0);
  v17.cbSize = 28;
  v17.fMask = 8;
  GetMenuInfo(hMenu, &v17);
  switch ( v5 )
  {
    case 0x9EADu:
      if ( WTSDisconnectSession(0, v17.dwMenuData, 0) )
        goto LABEL_32;
      ReportMsg(L"Error disconnecting session", ghMainWnd);
      return 0;
    case 0x9EAEu:
      if ( WTSLogoffSessio(0, v17.dwMenuData, 0) )
        goto LABEL_32;
      ReportMsg(L"Error logging off session", ghMainWnd);
      return 0;
    case 0x9EAFu:
      DialogBoxParamW(ghInstance, L"SENDMESSAGE", ghMainWnd, sub_10385F0, v17.dwMenuData);
      goto LABEL_32;
    case 0x9EB1u:
      DialogBoxParamW(ghInstance, L"TSINFO", ghMainWnd, sub_1038DE0, v17.dwMenuData);
      goto LABEL_32;
    case 0x9F27u:
      if ( WTSQuerySessionInformationW(0, v17.dwMenuData, WTSUserName, &ppBuffer, &nSize) )
      {
        v13 = hWnd;
        v20 = 0;
        v12 = 20;
        v14 = L"Enter the selected user's password";
        v15 = L"Process Explorer Connect Password";
        v16 = 0;
        do
        {
          v7 = CredUIPromptForCredentialsW(&v12, &gszNullString, 0, 1326, ppBuffer, nSize, &psz, 260, &v20, 1310850);
          if ( !v7 )
          {
            v8 = *_bstr_t::_bstr_t(&v19, &psz);
            if ( v8 )
              v9 = *v8;
            else
              v9 = 0;
            v10 = WinStationConnectW(0, v17.dwMenuData, -1, v9, 1);
            _bstr_t::_Free(&v19);
            if ( v10 )
              goto LABEL_32;
            v7 = GetLastError();
          }
        }
        while ( v7 == 1326 );
      }
      else
      {
        v7 = GetLastError();
      }
      if ( !v7 )
        goto LABEL_32;
      SetLastError(v7);
      ReportMsg(L"Error connecting to session", ghMainWnd);
      result = 0;
      break;
    case 0x9F28u:
      v11 = GetCurrentProcessId();
      gpfnProcessIdToSessionId(v11, &v21);
      if ( WTSGetActiveConsoleSessionId() == v21 )
      {
        ReportMsg(L"Remote control is not supported from a console session", ghMainWnd);
        result = 0;
      }
      else
      {
        nSize = 260;
        GetComputerNameW(&Buffer, &nSize);
        if ( WinStationShadow(0, &Buffer, v17.dwMenuData, 112, 2) )
        {
LABEL_32:
          result = 0;
        }
        else
        {
          ReportMsg(L"Error starting remote control", ghMainWnd);
          result = 0;
        }
      }
      break;
    default:
      goto LABEL_32;
  }
  return result;
}
// 108C83C: using guessed type int __stdcall CredUIPromptForCredentialsW(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 10A0F14: using guessed type wchar_t aErrorDisconnec[28];
// 10A0F50: using guessed type wchar_t aEnterTheSelect[35];
// 10A0F98: using guessed type wchar_t aProcessExplore_5[34];
// 10A0FDC: using guessed type wchar_t aErrorConnectin[28];
// 10A1018: using guessed type wchar_t aRemoteControlI[55];
// 10A1088: using guessed type wchar_t aErrorStartingR[30];
// 10A10C4: using guessed type wchar_t aErrorLoggingOf[26];
// 10A10F8: using guessed type wchar_t aSendmessage[12];
// 10BE11C: using guessed type struct tagMSGHANDLER CMainWnd::gCmdHandler;
// 10CF280: using guessed type int (__stdcall *gpfnProcessIdToSessionId)(_DWORD, _DWORD);
// 10CF334: using guessed type int (__stdcall *WTSDisconnectSession)(_DWORD, _DWORD, _DWORD);
// 10CF338: using guessed type int (__stdcall *WinStationConnectW)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 10CF33C: using guessed type int (__stdcall *WinStationShadow)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 10CF34C: using guessed type int (__stdcall *WTSLogoffSessio)(_DWORD, _DWORD, _DWORD);

//----- (01036470) --------------------------------------------------------
signed int __cdecl CMainWnd::HandleCopyData(HWND hWnd, UINT msg, WPARAM wParam, PCOPYDATASTRUCT lParam)
{
  tagTREEVIEWLISTITEMPARAM *pItemParam; // esi
  signed int ret; // esi
  CHAR *v6; // edi
  CString strData; // [esp+8h] [ebp-34h]
  WINDOWPLACEMENT wndpl; // [esp+Ch] [ebp-30h]

  pItemParam = gpTreeViewListItemParam;
  ATL::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>(
    &strData,
    lParam->lpData,
    lParam->cbData);
  if ( pItemParam )
  {
    while ( _wcsicmp(pItemParam->szProcessName2, strData.pszData) )
    {
      pItemParam = pItemParam->m_Prev;
      if ( !pItemParam )
        goto LABEL_4;
    }
    CTreeList::FillTreeViewParam(pItemParam);
    if ( !IsWindowVisible(ghMainWnd) )
    {
      wndpl.length = 44;
      GetWindowPlacement(ghMainWnd, &wndpl);
      ShowWindow(ghMainWnd, 4 * (wndpl.showCmd == 2) + 5);
      SetForegroundWindow(ghMainWnd);
      SetFocus(ghMainWnd);
      gbMainWndMinimized1 = 1;
      gbMainWndMinimized = 0;
    }
    ret = 2;
  }
  else
  {
LABEL_4:
    ret = 1;
  }
  v6 = strData.pszData - 16;
  if ( _InterlockedDecrement(strData.pszData - 1) <= 0 )
    (*(**v6 + 4))(v6);
  return ret;
}
// 10CA389: using guessed type char gbMainWndMinimized;
// 10CA393: using guessed type char gbMainWndMinimized1;

//----- (01036570) --------------------------------------------------------
int __cdecl CMainWnd::HandleMsg7F3(HWND a1, unsigned int a2, unsigned int a3, int a4)
{
  CTreeList *v4; // eax
  HICON v5; // ST08_4
  struct _IMAGELIST *v6; // eax

  v4 = CTreeList::GetTreeList(ghWndTreeListView);
  if ( *(a4 + 52) )
  {
    v5 = *(a4 + 52);
    v6 = CTreeList::GetImageList(v4);
    *(a4 + 64) = ImageList_ReplaceIcon(v6, -1, v5);
  }
  else
  {
    *(a4 + 64) = 0;
  }
  return 0;
}

//----- (010365C0) --------------------------------------------------------
int __cdecl CMainWnd::HandleMsg7E8(int a1, int a2, HWND hWnd)
{
  HWND v3; // esi
  LRESULT v4; // edi

  if ( hWnd == 101 )
  {
    v3 = ghWndTreeListView;
  }
  else if ( hWnd == 102 )
  {
    v3 = ghWndHandlesListCtrl;
  }
  else if ( (hWnd - 102) == 2 )
  {
    v3 = ghWndDllsListCtrl;
  }
  else
  {
    v3 = hWnd;
  }
  v4 = -1;
  if ( !gConfig.bShowNewProcesses )
  {
    v4 = SendMessageW(v3, 0x100Cu, 0xFFFFFFFF, 2);
    if ( !SendMessageW(v3, 0x10B6u, v4, 0) )
      v4 = -1;
  }
  if ( hWnd == 101 )
    sub_1056020(gpTreeViewListItemParam);
  sub_101FAA0(hWnd);
  if ( v4 != -1 )
    SendMessageW(v3, 0x1013u, v4, 0);
  return 0;
}

//----- (01036660) --------------------------------------------------------
int __cdecl CMainWnd::HandleMsg7E9(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
  HMENU v4; // eax
  HMENU v5; // eax
  int v6; // ST14_4
  HMENU v7; // edi
  HMENU v8; // eax
  HMENU v9; // eax
  HMENU v10; // eax
  HMODULE v12; // eax
  void (*EndMenu)(void); // eax
  struct tagPOINT Point; // [esp+4h] [ebp-38h]
  WINDOWPLACEMENT wndpl; // [esp+Ch] [ebp-30h]

  if ( lParam == 123 )
    goto LABEL_4;
  if ( lParam != 513 )
  {
    if ( lParam != 517 )
      return 0;
LABEL_4:
    GetCursorPos(&Point);
    SetForegroundWindow(hWnd);
    v4 = LoadMenuW(ghInstance, L"TRAYMENU");
    v5 = GetSubMenu(v4, 0);
    v6 = gdwMenuItemCountAppendedInRuntime;
    v7 = v5;
    v8 = GetMenu(hWnd);
    v9 = GetSubMenu(v8, 0);
    v10 = GetSubMenu(v9, v6);
    InsertMenuW(v7, 0, 0x410u, v10, L"S&hutdown");
    TrackPopupMenu(v7, 0, Point.x, Point.y, 0, hWnd, 0);
    return 0;
  }
  v12 = GetModuleHandleW(L"user32.dll");
  EndMenu = GetProcAddress(v12, "EndMenu");
  if ( EndMenu )
    EndMenu();
  else
    SendMessageW(hWnd, WM_CANCELMODE, 0, 0);
  wndpl.length = 44;
  GetWindowPlacement(ghMainWnd, &wndpl);
  if ( !IsWindowVisible(ghMainWnd) || wndpl.showCmd == SW_SHOWMINIMIZED )
  {
LABEL_14:
    gbMainWndMinimized1 = 1;
    Command_OpenProcExp();
    return 0;
  }
  if ( sub_1037A60(ghWndTreeListView) )
  {
    if ( gConfig.bHideWhenMinimized )
    {
      CMainWnd::Hide(ghMainWnd);
      return 0;
    }
    goto LABEL_14;
  }
  SetForegroundWindow(ghMainWnd);
  return 0;
}
// 10CA393: using guessed type char gbMainWndMinimized1;

//----- (010367F0) --------------------------------------------------------
LRESULT __cdecl CMainWnd::HandleSysCommand(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
  if ( !gConfig.bHideWhenMinimized || wParam != SC_MINIMIZE )
    return DefWindowProcW(hWnd, Msg, wParam, lParam);
  gbMainWndMinimized = 1;
  CMainWnd::Hide(hWnd);
  return 0;
}
// 10CA389: using guessed type char gbMainWndMinimized;

//----- (01036830) --------------------------------------------------------
int __cdecl CMainWnd::HandleMsg7EB(int a1, int a2, WPARAM wParam, WPARAM wParam_1)
{
  CTreeList *v4; // eax
  int result; // eax
  RECT Rect; // [esp+0h] [ebp-14h]

  if ( wParam == -2 )
  {
    v4 = CTreeList::GetTreeList(ghWndTreeListView);
    CTreeList::RefreshHeaderItem(v4, wParam_1);
    result = 0;
  }
  else
  {
    if ( wParam_1 == -1 )
    {
      SendMessageW(ghWndTreeListView, 0x1015u, wParam, wParam);
    }
    else
    {
      sub_101A880(ghWndTreeListView, wParam, wParam_1, &Rect);
      Rect.right += Rect.left;
      Rect.bottom += Rect.top;
      InvalidateRect(ghWndTreeListView, &Rect, 0);
    }
    result = 0;
  }
  return result;
}

//----- (010368E0) --------------------------------------------------------
int sub_10368E0(wchar_t *Dst, wchar_t *Format, ...)
{
  va_list ArgList; // [esp+10h] [ebp+10h]

  va_start(ArgList, Format);
  return vswprintf_s(Dst, 0x410u, Format, ArgList);
}

//----- (01036900) --------------------------------------------------------
CString *__thiscall ATL::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>(CString *this, LPCSTR lpMultiByteStr, int cbMultiByte)
{
  CString *v3; // esi
  IAtlStringMgr *v4; // ecx
  int v5; // eax
  int v6; // edi

  v3 = this;
  v4 = ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>::GetDefaultManager();
  if ( !v4 )
    ATL::AtlThrowImpl(E_FAIL);
  v3->pszData = ((v4->vtptr->GetNilData)() + 16);
  if ( cbMultiByte > 0 )
  {
    if ( !lpMultiByteStr )
      goto LABEL_15;
    v5 = MultiByteToWideChar(3u, 0, lpMultiByteStr, cbMultiByte, 0, 0);
    v6 = v5;
    if ( v5 < 0 )
      ATL::AtlThrowImpl(E_INVALIDARG);
    if ( ((*(v3->pszData - 2) - v5) | (1 - *(v3->pszData - 1))) < 0 )
      ATL::CSimpleStringT<wchar_t,0>::PrepareWrite2(v3, v5);
    MultiByteToWideChar(3u, 0, lpMultiByteStr, cbMultiByte, v3->pszData, v6);
    if ( v6 > *(v3->pszData - 2) )
LABEL_15:
      ATL::AtlThrowImpl(E_INVALIDARG);
    *(v3->pszData - 3) = v6;
    *&v3->pszData[2 * v6] = 0;
  }
  return v3;
}

//----- (010369F0) --------------------------------------------------------
HBRUSH __stdcall DlgSelectColor(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
  COLORREF v4; // esi
  HBRUSH result; // eax
  COLORREF v6; // esi
  BOOL v7; // ST08_4
  BOOL v8; // ST08_4
  BOOL v9; // ST08_4
  BOOL v10; // ST08_4
  BOOL v11; // ST08_4
  BOOL v12; // ST08_4
  BOOL v13; // ST08_4
  BOOL v14; // ST08_4
  BOOL v15; // ST08_4
  BOOL v16; // ST08_4
  UINT v17; // eax
  UINT v18; // eax
  UINT v19; // eax
  UINT v20; // eax
  UINT v21; // eax
  UINT v22; // eax
  UINT v23; // eax
  UINT v24; // eax
  UINT v25; // eax
  UINT v26; // eax
  HWND v27; // eax
  HWND v28; // eax
  HWND v29; // eax
  HWND v30; // eax
  HWND v31; // eax
  HWND v32; // eax
  HWND v33; // eax
  HWND v34; // eax
  HWND v35; // eax
  HWND v36; // eax
  HWND v37; // eax
  HWND v38; // eax
  HWND v39; // eax

  if ( uMsg == WM_INITDIALOG )
  {
    gColorOwnProcessStatic = gConfig.ColorOwn;
    gColorServices = gConfig.ColorService;
    gColorRelocatedDlls = gConfig.ColorRelocatedDlls;
    gColorJobs = gConfig.ColorJobs;
    gColorDotNetProcesses = gConfig.ColorNet;
    gColorNewObjectes = gConfig.ColorNewProc;
    gColorDeletedObjects = gConfig.ColorDelProc;
    gColorPackedImages = gConfig.ColorPacked;
    gColorPagingListsStandby = gConfig.ColorGraphBk;
    gColorWSShared = gConfig.ColorImmersive;
    gColorSuspendedProcess = gConfig.ColorSuspend;
    gColorProtectedProcess = gConfig.ColorProtected;
    CheckDlgButton(hDlg, IDD_CHOOSECOLORS_CHECKBOX_DELETED_OBJECTS, gConfig.bHighlightDelProc != 0);
    CheckDlgButton(hDlg, IDD_CHOOSECOLORS_CHECKBOX_NEW_OBJECTS, gConfig.bHighlightNewProc != 0);
    CheckDlgButton(hDlg, IDD_CHOOSECOLORS_CHECKBOX_OWN_PROCESSES, gConfig.bHighlightOwnProcesses != 0);
    CheckDlgButton(hDlg, IDD_CHOOSECOLORS_CHECKBOX_SERVICES, gConfig.bHighlightServices != 0);
    CheckDlgButton(hDlg, IDD_CHOOSECOLORS_CHECKBOX_RELOCATED_DLLS, gConfig.bHighlightRelocatedDlls != 0);
    CheckDlgButton(hDlg, IDD_CHOOSECOLORS_CHECKBOX_PACKED_IMAGES, gConfig.bHighlightPacked != 0);
    CheckDlgButton(hDlg, IDD_CHOOSECOLORS_CHECKBOX_SUSPENDED_PROCESSES, gConfig.bHighlightSuspend != 0);
    CheckDlgButton(hDlg, IDD_CHOOSECOLORS_CHECKBOX_PROTECTED_PROCESS, gConfig.bHighlightProtected != 0);
    v27 = GetDlgItem(hDlg, IDD_CHOOSECOLORS_CHECKBOX_IMMERSIVE_PROCESS);
    EnableWindow(v27, 0);
    if ( gdwVersion >= 1 && IsBuiltinAdministrative() )
    {
      v28 = GetDlgItem(hDlg, IDD_CHOOSECOLORS_CHECKBOX_PROTECTED_PROCESS);
      EnableWindow(v28, 1);
      v29 = GetDlgItem(hDlg, IDD_CHOOSECOLORS_STATIC_PROTECTED_PROCESS);
      EnableWindow(v29, 1);
      v30 = GetDlgItem(hDlg, IDD_CHOOSECOLORS_BUTTON_PROTECTED_PROCESS_CHANGE);
      EnableWindow(v30, 1);
    }
    if ( *IsProcessInJob )
    {
      v31 = GetDlgItem(hDlg, IDD_CHOOSECOLORS_CHECKBOX_JOBS);
      EnableWindow(v31, 1);
      v32 = GetDlgItem(hDlg, IDD_CHOOSECOLORS_BUTTON_JOBS_CHANGE);
      EnableWindow(v32, 1);
      CheckDlgButton(hDlg, IDD_CHOOSECOLORS_CHECKBOX_JOBS, gConfig.bHighlightJobs != 0);
    }
    v33 = GetDlgItem(hDlg, IDD_CHOOSECOLORS_STATIC_JOBS);
    EnableWindow(v33, 1);
    if ( IsImmersiveProcess )
    {
      v34 = GetDlgItem(hDlg, IDD_CHOOSECOLORS_CHECKBOX_IMMERSIVE_PROCESS);
      EnableWindow(v34, 1);
      v35 = GetDlgItem(hDlg, IDD_CHOOSECOLORS_BUTTON_IMMERSIVE_PROCESS_CHANGE);
      EnableWindow(v35, 1);
      CheckDlgButton(hDlg, IDD_CHOOSECOLORS_CHECKBOX_IMMERSIVE_PROCESS, gConfig.bHighlightImmersive != 0);
    }
    v36 = GetDlgItem(hDlg, IDD_CHOOSECOLORS_STATIC_IMMERSIVE_PROCESS);
    EnableWindow(v36, 1);
    if ( gNetClrMemoryPerfInfoLoaded )
    {
      v37 = GetDlgItem(hDlg, IDD_CHOOSECOLORS_CHECKBOX_DOTNET_PROCESSES);
      EnableWindow(v37, 1);
      v38 = GetDlgItem(hDlg, IDD_CHOOSECOLORS_BUTTON_DOTNET_PROCESSES_CHANGE);
      EnableWindow(v38, 1);
      CheckDlgButton(hDlg, IDD_CHOOSECOLORS_CHECKBOX_DOTNET_PROCESSES, gConfig.bHighliteNetProcess != 0);
    }
    v39 = GetDlgItem(hDlg, IDD_CHOOSECOLORS_STATIC_DOTNET_PROCESSES);
    EnableWindow(v39, 1);
    result = 1;
  }
  else
  {
    if ( uMsg != WM_COMMAND )
    {
      if ( uMsg == WM_CTLCOLORSTATIC )
      {
        if ( lParam == GetDlgItem(hDlg, IDD_CHOOSECOLORS_STATIC_OWN_PROCESSES) )
        {
          SetBkColor(wParam, gColorOwnProcessStatic);
          v4 = gColorOwnProcessStatic;
          if ( gBrushOfOwnProcessStatic )
            DeleteObject(gBrushOfOwnProcessStatic);
          result = CreateSolidBrush(v4);
          gBrushOfOwnProcessStatic = result;
          return result;
        }
        if ( lParam == GetDlgItem(hDlg, IDD_CHOOSECOLORS_STATIC_IMMERSIVE_PROCESS) )
        {
          SetBkColor(wParam, gColorWSShared);
          v6 = gColorWSShared;
          if ( gBrushImmsiveProcess )
            DeleteObject(gBrushImmsiveProcess);
          result = CreateSolidBrush(v6);
          gBrushImmsiveProcess = result;
          return result;
        }
        if ( lParam == GetDlgItem(hDlg, IDD_CHOOSECOLORS_STATIC_SERVICES) )
        {
          SetBkColor(wParam, gColorServices);
          return BrushFromColor(gColorServices, &gBrushServices);
        }
        if ( lParam == GetDlgItem(hDlg, IDD_CHOOSECOLORS_STATIC_GRAPH_BACKGROUND) )
        {
          SetTextColor(wParam, 255 - gColorPagingListsStandby);
          SetBkColor(wParam, gColorPagingListsStandby);
          return BrushFromColor(gColorPagingListsStandby, &gBrushPagingListsStandby);
        }
        if ( lParam == GetDlgItem(hDlg, IDD_CHOOSECOLORS_STATIC_RELOCATED_DLLS) )
        {
          SetBkColor(wParam, gColorRelocatedDlls);
          return BrushFromColor(gColorRelocatedDlls, &gBrushRelocatedDlls);
        }
        if ( lParam == GetDlgItem(hDlg, IDD_CHOOSECOLORS_STATIC_PACKED_IMAGES) )
        {
          SetBkColor(wParam, gColorPackedImages);
          return BrushFromColor(gColorPackedImages, &gBrushPackedImages);
        }
        if ( lParam == GetDlgItem(hDlg, IDD_CHOOSECOLORS_STATIC_SUSPENDED_PROCESSES) )
        {
          SetBkColor(wParam, gColorSuspendedProcess);
          return BrushFromColor(gColorSuspendedProcess, &gBrushSuspendedProcess);
        }
        if ( lParam == GetDlgItem(hDlg, IDD_CHOOSECOLORS_STATIC_JOBS) )
        {
          SetBkColor(wParam, gColorJobs);
          return BrushFromColor(gColorJobs, &gBrushJobs);
        }
        if ( lParam == GetDlgItem(hDlg, IDD_CHOOSECOLORS_STATIC_DOTNET_PROCESSES) )
        {
          SetBkColor(wParam, gColorDotNetProcesses);
          return BrushFromColor(gColorDotNetProcesses, &gBrushDotNetProcesses);
        }
        if ( lParam == GetDlgItem(hDlg, IDD_CHOOSECOLORS_STATIC_NEW_OBJECTS) )
        {
          SetBkColor(wParam, gColorNewObjectes);
          return BrushFromColor(gColorNewObjectes, &gBrushNewObjects);
        }
        if ( lParam == GetDlgItem(hDlg, IDD_CHOOSECOLORS_STATIC_DELETED_OBJECTS) )
        {
          SetBkColor(wParam, gColorDeletedObjects);
          return BrushFromColor(gColorDeletedObjects, &gBrushDeletedObjects);
        }
        if ( lParam == GetDlgItem(hDlg, IDD_CHOOSECOLORS_STATIC_PROTECTED_PROCESS) && IsWindowEnabled(lParam) )
        {
          SetBkColor(wParam, gColorProtectedProcess);
          return BrushFromColor(gColorProtectedProcess, &gBrushDeletedObjects);
        }
      }
      return 0;
    }
    if ( !(wParam >> 16) )
    {
      switch ( wParam )
      {
        case IDD_CHOOSECOLORS_STATIC_OWN_PROCESSES:
          v7 = IsDlgButtonChecked(hDlg, IDD_CHOOSECOLORS_CHECKBOX_OWN_PROCESSES) != 1;
          CheckDlgButton(hDlg, IDD_CHOOSECOLORS_CHECKBOX_OWN_PROCESSES, v7);
          break;
        case IDD_CHOOSECOLORS_STATIC_SERVICES:
          v8 = IsDlgButtonChecked(hDlg, IDD_CHOOSECOLORS_CHECKBOX_SERVICES) != 1;
          CheckDlgButton(hDlg, IDD_CHOOSECOLORS_CHECKBOX_SERVICES, v8);
          break;
        case IDD_CHOOSECOLORS_STATIC_RELOCATED_DLLS:
          v10 = IsDlgButtonChecked(hDlg, IDD_CHOOSECOLORS_CHECKBOX_RELOCATED_DLLS) != 1;
          CheckDlgButton(hDlg, IDD_CHOOSECOLORS_CHECKBOX_RELOCATED_DLLS, v10);
          break;
        case IDD_CHOOSECOLORS_STATIC_JOBS:
          v11 = IsDlgButtonChecked(hDlg, IDD_CHOOSECOLORS_CHECKBOX_JOBS) != 1;
          CheckDlgButton(hDlg, IDD_CHOOSECOLORS_CHECKBOX_JOBS, v11);
          break;
        case IDD_CHOOSECOLORS_STATIC_DOTNET_PROCESSES:
          v12 = IsDlgButtonChecked(hDlg, IDD_CHOOSECOLORS_CHECKBOX_DOTNET_PROCESSES) != 1;
          CheckDlgButton(hDlg, IDD_CHOOSECOLORS_CHECKBOX_DOTNET_PROCESSES, v12);
          break;
        case IDD_CHOOSECOLORS_STATIC_DELETED_OBJECTS:
          v15 = IsDlgButtonChecked(hDlg, IDD_CHOOSECOLORS_CHECKBOX_DELETED_OBJECTS) != 1;
          CheckDlgButton(hDlg, IDD_CHOOSECOLORS_CHECKBOX_DELETED_OBJECTS, v15);
          break;
        case IDD_CHOOSECOLORS_STATIC_NEW_OBJECTS:
          v14 = IsDlgButtonChecked(hDlg, IDD_CHOOSECOLORS_CHECKBOX_NEW_OBJECTS) != 1;
          CheckDlgButton(hDlg, IDD_CHOOSECOLORS_CHECKBOX_NEW_OBJECTS, v14);
          break;
        case IDD_CHOOSECOLORS_STATIC_PACKED_IMAGES:
          v9 = IsDlgButtonChecked(hDlg, IDD_CHOOSECOLORS_CHECKBOX_PACKED_IMAGES) != 1;
          CheckDlgButton(hDlg, IDD_CHOOSECOLORS_CHECKBOX_PACKED_IMAGES, v9);
          break;
        case IDS_COMPANY_NAME:
          v13 = IsDlgButtonChecked(hDlg, IDD_CHOOSECOLORS_CHECKBOX_SUSPENDED_PROCESSES) != 1;
          CheckDlgButton(hDlg, IDD_CHOOSECOLORS_CHECKBOX_SUSPENDED_PROCESSES, v13);
          break;
        case IDD_ABOUT_STATIC_ADDRESS:
          v16 = IsDlgButtonChecked(hDlg, IDD_CHOOSECOLORS_CHECKBOX_PROTECTED_PROCESS) != 1;
          CheckDlgButton(hDlg, IDD_CHOOSECOLORS_CHECKBOX_PROTECTED_PROCESS, v16);
          break;
        default:
          break;
      }
    }
    if ( wParam <= IDD_CHOOSECOLORS_BUTTON_OWN_PROCESSES_CHANGE )
    {
      switch ( wParam )
      {
        case IDD_CHOOSECOLORS_BUTTON_OWN_PROCESSES_CHANGE:
          return SelectColor(hDlg, &gColorOwnProcessStatic);
        case 1u:
          gConfig.ColorJobs = gColorJobs;
          DeleteObject(gBrushJobs);
          v17 = IsDlgButtonChecked(hDlg, IDD_CHOOSECOLORS_CHECKBOX_JOBS);
          gConfig.ColorRelocatedDlls = gColorRelocatedDlls;
          gConfig.bHighlightJobs = v17 == 1;
          DeleteObject(gBrushRelocatedDlls);
          v18 = IsDlgButtonChecked(hDlg, IDD_CHOOSECOLORS_CHECKBOX_RELOCATED_DLLS);
          gConfig.ColorOwn = gColorOwnProcessStatic;
          gConfig.bHighlightRelocatedDlls = v18 == 1;
          DeleteObject(gBrushOfOwnProcessStatic);
          v19 = IsDlgButtonChecked(hDlg, IDD_CHOOSECOLORS_CHECKBOX_OWN_PROCESSES);
          gConfig.ColorService = gColorServices;
          gConfig.bHighlightOwnProcesses = v19 == 1;
          DeleteObject(gBrushServices);
          v20 = IsDlgButtonChecked(hDlg, IDD_CHOOSECOLORS_CHECKBOX_SERVICES);
          gConfig.ColorNet = gColorDotNetProcesses;
          gConfig.bHighlightServices = v20 == 1;
          DeleteObject(gBrushDotNetProcesses);
          v21 = IsDlgButtonChecked(hDlg, IDD_CHOOSECOLORS_CHECKBOX_DOTNET_PROCESSES);
          gConfig.ColorSuspend = gColorSuspendedProcess;
          gConfig.bHighliteNetProcess = v21 == 1;
          DeleteObject(gBrushSuspendedProcess);
          v22 = IsDlgButtonChecked(hDlg, IDD_CHOOSECOLORS_CHECKBOX_SUSPENDED_PROCESSES);
          gConfig.ColorNewProc = gColorNewObjectes;
          gConfig.bHighlightSuspend = v22 == 1;
          DeleteObject(gBrushNewObjects);
          v23 = IsDlgButtonChecked(hDlg, IDD_CHOOSECOLORS_CHECKBOX_NEW_OBJECTS);
          gConfig.ColorDelProc = gColorDeletedObjects;
          gConfig.bHighlightNewProc = v23 == 1;
          DeleteObject(gBrushDeletedObjects);
          v24 = IsDlgButtonChecked(hDlg, IDD_CHOOSECOLORS_CHECKBOX_DELETED_OBJECTS);
          gConfig.ColorPacked = gColorPackedImages;
          gConfig.bHighlightDelProc = v24 == 1;
          DeleteObject(gBrushPackedImages);
          gConfig.bHighlightPacked = IsDlgButtonChecked(hDlg, IDD_CHOOSECOLORS_CHECKBOX_PACKED_IMAGES) == 1;
          gConfig.ColorGraphBk = gColorPagingListsStandby;
          DeleteObject(gBrushPagingListsStandby);
          v25 = IsDlgButtonChecked(hDlg, IDD_CHOOSECOLORS_CHECKBOX_IMMERSIVE_PROCESS);
          gConfig.ColorImmersive = gColorWSShared;
          gConfig.bHighlightImmersive = v25 == 1;
          DeleteObject(gBrushImmsiveProcess);
          v26 = IsDlgButtonChecked(hDlg, IDD_CHOOSECOLORS_CHECKBOX_PROTECTED_PROCESS);
          gConfig.ColorProtected = gColorProtectedProcess;
          gConfig.bHighlightProtected = v26 == 1;
          DeleteObject(ho);
          SetEvent(ghTimerRefreshEvent);
          break;
        case IDC_MYICON:
          break;
        default:
          return 0;
      }
      EndDialog(hDlg, 0);
      return 0;
    }
    switch ( wParam )
    {
      case IDD_CHOOSECOLORS_BUTTON_SERVICES_CHANGE:
        result = SelectColor(hDlg, &gColorServices);
        break;
      case IDD_CHOOSECOLORS_BUTTON_RELOCATED_DLLS_CHANGE:
        result = SelectColor(hDlg, &gColorRelocatedDlls);
        break;
      case IDD_CHOOSECOLORS_BUTTON_JOBS_CHANGE:
        result = SelectColor(hDlg, &gColorJobs);
        break;
      case IDD_CHOOSECOLORS_BUTTON_DELETE_OBJECTS_CHANGE:
        result = SelectColor(hDlg, &gColorDeletedObjects);
        break;
      case IDD_CHOOSECOLORS_BUTTON_DOTNET_PROCESSES_CHANGE:
        result = SelectColor(hDlg, &gColorDotNetProcesses);
        break;
      case IDD_CHOOSECOLORS_BUTTON_NEW_OBJECTS_CHANGE:
        result = SelectColor(hDlg, &gColorNewObjectes);
        break;
      case IDD_CHOOSECOLORS_BUTTON_PACKED_IMAGES_CHANGE:
        result = SelectColor(hDlg, &gColorPackedImages);
        break;
      case IDC_SYSINFO_MEMORY_STATIC_PAGING_LISTS_STANDBY_VALUE:
        SelectColor(hDlg, &gColorPagingListsStandby);
        result = 1;
        break;
      case IDS_WS_SHARED:
        result = SelectColor(hDlg, &gColorWSShared);
        break;
      case IDD_CHOOSECOLORS_BUTTON_SUSPENDED_PROCESSES_CHANGE:
        result = SelectColor(hDlg, &gColorSuspendedProcess);
        break;
      case IDD_CHOOSECOLORS_BUTTON_PROTECTED_PROCESS_CHANGE:
        result = SelectColor(hDlg, &gColorProtectedProcess);
        break;
      case IDD_CHOOSECOLORS_BUTTON_DEFAULTS:
        gColorOwnProcessStatic = 0xFFD0D0;
        gColorServices = 0xD0D0FF;
        gColorRelocatedDlls = 0xA0FFFF;
        gColorJobs = 0x6CD0;
        gColorDotNetProcesses = 0xA0FFFF;
        gColorWSShared = 0xEAEA00;
        gColorNewObjectes = 0x46FF46;
        gColorDeletedObjects = 0x4646FF;
        gColorPackedImages = 0xFF0080;
        gColorSuspendedProcess = 0x808080;
        gColorProtectedProcess = 0x8000FF;
        gColorPagingListsStandby = GetSysColor(COLOR_BTNFACE);
        InvalidateRect(hDlg, 0, 0);
        result = 1;
        break;
      default:
        return 0;
    }
  }
  return result;
}
// 10C4E54: using guessed type int gdwVersion;
// 10CA098: using guessed type char gNetClrMemoryPerfInfoLoaded;
// 10DBA4C: using guessed type int (__stdcall *IsImmersiveProcess)(_DWORD);

//----- (010374D0) --------------------------------------------------------
int __stdcall PropColumnSetsForStatusBar(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
  double v4; // st6
  double v5; // st7
  __int16 v6; // ax
  char v8; // [esp+8h] [ebp-64h]
  char v9; // [esp+10h] [ebp-5Ch]
  char v10; // [esp+18h] [ebp-54h]

  if ( msg == 78 )
  {
    if ( *(lParam + 8) == -202 )
    {
      gConfig.dwStatusBarColumns = 0;
      if ( IsDlgButtonChecked(hWnd, 1107) == 1 )
        gConfig.dwStatusBarColumns |= 1u;
      if ( IsDlgButtonChecked(hWnd, 1114) == 1 )
        gConfig.dwStatusBarColumns |= 2u;
      if ( IsDlgButtonChecked(hWnd, 1109) == 1 )
        gConfig.dwStatusBarColumns |= 4u;
      if ( IsDlgButtonChecked(hWnd, 1115) == 1 )
        gConfig.dwStatusBarColumns |= 8u;
      if ( IsDlgButtonChecked(hWnd, 1108) == 1 )
        gConfig.dwStatusBarColumns |= 0x10u;
      if ( IsDlgButtonChecked(hWnd, 1111) == 1 )
        gConfig.dwStatusBarColumns |= 0x20u;
      if ( IsDlgButtonChecked(hWnd, 1112) == 1 )
        gConfig.dwStatusBarColumns |= 0x40u;
      if ( IsDlgButtonChecked(hWnd, 1116) == 1 )
        gConfig.dwStatusBarColumns |= 0x80u;
      if ( IsDlgButtonChecked(hWnd, 1110) == 1 )
        gConfig.dwStatusBarColumns |= 0x100u;
      if ( IsDlgButtonChecked(hWnd, 1117) == 1 )
        gConfig.dwStatusBarColumns |= 0x200u;
      if ( IsDlgButtonChecked(hWnd, 1113) == 1 )
        gConfig.dwStatusBarColumns |= 0x400u;
      if ( IsDlgButtonChecked(hWnd, 1118) == 1 )
        gConfig.dwStatusBarColumns |= 0x800u;
      if ( IsDlgButtonChecked(hWnd, 1325) == 1 )
        gConfig.dwStatusBarColumns |= 0x1000u;
      if ( IsDlgButtonChecked(hWnd, 1119) == 1 )
        gConfig.dwStatusBarColumns |= 0x2000u;
      if ( IsDlgButtonChecked(hWnd, 1120) == 1 )
        gConfig.dwStatusBarColumns |= 0x4000u;
      memset(&v10, 0, 0x50u);
      sub_1060410(v5, v4, 0, &v10, &v9, &v8);
      CMainWnd::InitStatusBar(ghWndStatusBar);
      SetEvent(ghRefreshEventHandle);
      return 1;
    }
    return 0;
  }
  if ( msg != 272 )
    return 0;
  v6 = gConfig.dwStatusBarColumns;
  if ( gConfig.dwStatusBarColumns & 1 )
  {
    CheckDlgButton(hWnd, 1107, 1u);
    v6 = gConfig.dwStatusBarColumns;
  }
  if ( v6 & 2 )
  {
    CheckDlgButton(hWnd, 1114, 1u);
    v6 = gConfig.dwStatusBarColumns;
  }
  if ( v6 & 4 )
  {
    CheckDlgButton(hWnd, 1109, 1u);
    v6 = gConfig.dwStatusBarColumns;
  }
  if ( v6 & 8 )
  {
    CheckDlgButton(hWnd, 1115, 1u);
    v6 = gConfig.dwStatusBarColumns;
  }
  if ( v6 & 0x10 )
  {
    CheckDlgButton(hWnd, 1108, 1u);
    v6 = gConfig.dwStatusBarColumns;
  }
  if ( v6 & 0x20 )
  {
    CheckDlgButton(hWnd, 1111, 1u);
    v6 = gConfig.dwStatusBarColumns;
  }
  if ( v6 & 0x40 )
  {
    CheckDlgButton(hWnd, 1112, 1u);
    v6 = gConfig.dwStatusBarColumns;
  }
  if ( (v6 & 0x80u) != 0 )
  {
    CheckDlgButton(hWnd, 1116, 1u);
    v6 = gConfig.dwStatusBarColumns;
  }
  if ( v6 & 0x100 )
  {
    CheckDlgButton(hWnd, 1110, 1u);
    v6 = gConfig.dwStatusBarColumns;
  }
  if ( v6 & 0x200 )
  {
    CheckDlgButton(hWnd, 1117, 1u);
    v6 = gConfig.dwStatusBarColumns;
  }
  if ( v6 & 0x400 )
  {
    CheckDlgButton(hWnd, 1113, 1u);
    v6 = gConfig.dwStatusBarColumns;
  }
  if ( v6 & 0x800 )
  {
    CheckDlgButton(hWnd, 1118, 1u);
    v6 = gConfig.dwStatusBarColumns;
  }
  if ( v6 & 0x1000 )
  {
    CheckDlgButton(hWnd, 1325, 1u);
    v6 = gConfig.dwStatusBarColumns;
  }
  if ( v6 & 0x2000 )
  {
    CheckDlgButton(hWnd, 1119, 1u);
    v6 = gConfig.dwStatusBarColumns;
  }
  if ( v6 & 0x4000 )
    CheckDlgButton(hWnd, 1120, 1u);
  return 1;
}

//----- (01037810) --------------------------------------------------------
BOOL __stdcall DialogFunc(HWND hDlg, UINT a2, WPARAM a3, LPARAM a4)
{
  BOOL result; // eax
  HWND v5; // eax
  HWND v6; // eax
  WCHAR String; // [esp+4h] [ebp-204h]
  __int16 v8; // [esp+8h] [ebp-200h]

  if ( a2 == 272 )
  {
    wsprintf(&String, L"%d", gConfig.dwHighlightDuration / 1000);
    SetDlgItemTextW(hDlg, 1105, &String);
    v5 = GetDlgItem(hDlg, 1105);
    SendMessageW(v5, 0xC5u, 1u, 0);
    v6 = GetDlgItem(hDlg, 1022);
    SendMessageW(v6, 0x465u, 0, 9);
    result = 1;
  }
  else
  {
    if ( a2 == 273 )
    {
      if ( a3 == 1 )
      {
        GetDlgItemTextW(hDlg, 1105, &String, 2);
        v8 = 0;
        gConfig.dwHighlightDuration = 1000 * _wtoi(&String);
      }
      else if ( a3 != 2 )
      {
        return 0;
      }
      EndDialog(hDlg, 0);
    }
    result = 0;
  }
  return result;
}

//----- (01037930) --------------------------------------------------------
void __cdecl sub_1037930(int a1)
{
  int v1; // eax
  signed __int16 v2; // ax

  if ( *(a1 + 720) != 3 )
  {
    memmove((a1 + 724), (a1 + 720), 4 * *(a1 + 524));
    v1 = *(a1 + 524);
    *(a1 + 720) = 3;
    memmove((a1 + 530), (a1 + 528), 2 * v1);
    v2 = *(a1 + 520);
    if ( !v2 )
      v2 = 200;
    ++*(a1 + 524);
    *(a1 + 528) = v2;
  }
}

//----- (010379B0) --------------------------------------------------------
HBRUSH __cdecl BrushFromColor(COLORREF color, HBRUSH *BrushHandle)
{
  HBRUSH result; // eax

  if ( *BrushHandle )
    DeleteObject(*BrushHandle);
  result = CreateSolidBrush(color);
  *BrushHandle = result;
  return result;
}

//----- (010379E0) --------------------------------------------------------
char __cdecl sub_10379E0(char a1)
{
  if ( a1
    || !gConfig.bHideWhenMinimized
    || gConfig.bShowPhysTray
     + gConfig.bShowIoTray
     + gConfig.bTrayCPUHistory
     + gConfig.bShowCommitTray
     + gConfig.bShowNetTray
     + gConfig.bShowGpuHistory
     + gConfig.bShowDiskTray != 1 )
  {
    return 0;
  }
  MessageBoxW(
    ghWndTreeListView,
    L"Because the Hide When Minimized option is selected, you must maintain at least one tray icon so that you can activat"
     "e Process Explorer when it is minimized.",
    L"Process Explorer Error",
    0x10u);
  return 1;
}

//----- (01037A60) --------------------------------------------------------
BOOL __cdecl sub_1037A60(HWND hWnd)
{
  POINT v1; // ST00_8
  struct tagRECT Rect; // [esp+4h] [ebp-14h]

  if ( !IsWindow(hWnd) )
    return 0;
  GetWindowRect(hWnd, &Rect);
  v1.y = Rect.top + (Rect.bottom - Rect.top) / 2;
  v1.x = Rect.left + (Rect.right - Rect.left) / 2;
  return WindowFromPoint(v1) == hWnd;
}

//----- (01037AE0) --------------------------------------------------------
int __cdecl SelectColor(HWND hWnd, COLORREF *ColorReturned)
{
  struct tagCHOOSECOLORW cc; // [esp+8h] [ebp-24h]

  cc.hInstance = ghInstance;
  cc.rgbResult = *ColorReturned;
  cc.lStructSize = 36;
  cc.hwndOwner = hWnd;
  cc.lpCustColors = gColorCustomized;
  cc.lCustData = 0;
  cc.Flags = 1;
  if ( ChooseColorW(&cc) )
  {
    *ColorReturned = cc.rgbResult;
    InvalidateRect(ghWndTreeListView, 0, 1);
    InvalidateRect(ghWndDllsListCtrl, 0, 1);
    InvalidateRect(ghWndHandlesListCtrl, 0, 1);
    InvalidateRect(hWnd, 0, 1);
  }
  return 0;
}

//----- (01037B70) --------------------------------------------------------
int __stdcall CMainWnd::BackendRefreshThreadProc(struct VOID *a1)
{
  char v1; // bl
  DWORD dwTimeout; // ecx
  DWORD dwRet; // esi
  DWORD v4; // ebx
  float v5; // xmm1_4
  float v6; // xmm1_4
  float v7; // xmm1_4
  float v8; // xmm1_4
  float v9; // xmm1_4
  __int16 v10; // bx
  DWORD dwTimeoutNew; // ecx
  char v13; // [esp+2h] [ebp-76h]
  char v14; // [esp+3h] [ebp-75h]
  MEMORYSTATUSEX MemoryStatusEx; // [esp+4h] [ebp-74h]
  struct _MEMORYSTATUS MemoryStatus; // [esp+44h] [ebp-34h]
  HANDLE Handles[4]; // [esp+64h] [ebp-14h]

  Handles[0] = ghRefreshEventHandle;
  Handles[1] = ghTimerRefreshEvent;
  Handles[2] = ghEvent2;
  Handles[3] = ghEvent3;
  if ( gNetClrMemoryPerfInfoLoaded )
    CoInitialize(0);
  v1 = gbFlagsInProcPropSheet;
  v13 = gbFlagsInProcPropSheet;
  SetErrorMode(SEM_FAILCRITICALERRORS);
  dwTimeout = -1;
  if ( gConfig.dwRefreshRate )
    dwTimeout = gConfig.dwRefreshRate;
  for ( dwRet = WaitForMultipleObjects(4u, Handles, 0, dwTimeout);
        dwRet != 3;
        dwRet = WaitForMultipleObjects(4u, Handles, 0, dwTimeoutNew) )
  {
    if ( dwRet == 2 )
    {
      gdwValue_4F10B8[0] = -1;
      gdwValue_4F10B8[1] = -1;
      gdwValue_4F10B8[2] = -1;
    }
    if ( gConfig.dwRefreshRate || dwRet != WAIT_TIMEOUT )
    {
      if ( ghWndSysinfoPropSheet )
        PostMessageW(ghWndSysinfoPropSheet, WM_TIMER, 0, 0);
      ++gdwRefreshCount;
      if ( v1 )
        PE_RunTrace(&gProperties, 1);
      if ( dwRet != 2 )
      {
        v4 = GetTickCount();
        if ( (v4 - gdwRefreshTickCountLast) > 10000 )
        {
          GraphInfo_Refresh(&gIOGraphInfo);
          GraphInfo_Refresh(&gNetworkGraphInfo);
          GraphInfo_Refresh(&gDiskGraphInfo);
          gdwRefreshTickCountLast = v4;
        }
        if ( GlobalMemoryStatusEx )
        {
          MemoryStatusEx.dwLength = 64;
          GlobalMemoryStatusEx(&MemoryStatusEx);
          v5 = MemoryStatusEx.ullTotalPageFile;
          v6 = v5 * 0.0009765625;
          if ( v6 > gpGraphInfoOfMemory->m_dbMemorySize )
            gpGraphInfoOfMemory->m_dbMemorySize = v6;
          v7 = MemoryStatusEx.ullTotalPhys;
          v8 = v7 * 0.0009765625;
        }
        else
        {
          MemoryStatus.dwLength = 32;
          GlobalMemoryStatus(&MemoryStatus);
          v9 = MemoryStatus.dwTotalPageFile * 0.0009765625;
          if ( v9 > gpGraphInfoOfMemory->m_dbMemorySize )
            gpGraphInfoOfMemory->m_dbMemorySize = v9;
          v8 = MemoryStatus.dwTotalPhys * 0.0009765625;
        }
        if ( v8 > gpGraphInfoOfPhysicalMemory->m_dbMemorySize )
          gpGraphInfoOfPhysicalMemory->m_dbMemorySize = v8;
      }
      v10 = 0;
      v14 = 0;
      if ( dwRet != 2 )
      {
        v14 = CTreeList::InitTreeList(ghWndTreeListView, dwRet == 1);
        PulseEvent(ghTimerRefreshProcPageEventHandle);
        PostMessageW(ghWndCPUGraph, WM_USER, 0, 0);
        PostMessageW(ghWndMemoryGraph, WM_USER, 0, 0);
        PostMessageW(ghWndPhysicalMemoryGraph, WM_USER, 0, 0);
        if ( ghWndIOGraphCtrl )
          PostMessageW(ghWndIOGraphCtrl, WM_USER, 0, 0);
        if ( ghWndNetworkGraph )
          PostMessageW(ghWndNetworkGraph, WM_USER, 0, 0);
        if ( ghWndDiskGraph )
          PostMessageW(ghWndDiskGraph, WM_USER, 0, 0);
        if ( ghWndGPUGraph )
          PostMessageW(ghWndGPUGraph, WM_USER, 0, 0);
      }
      if ( !gbMainWndMinimized )
      {
        if ( gdwProcessIdSelected == -1 )
        {
          gdwValue_4F10B8[0] = -2;
          gdwValue_4F10B8[2] = -1;
          gdwValue_4F10B8[1] = -2;
          if ( gConfig.bShowDllView )
            SendMessageW(ghWndDllsListCtrl, LVM_DELETEALLITEMS, 0, 0);
          else
            SendMessageW(ghWndHandlesListCtrl, LVM_DELETEALLITEMS, 0, 0);
        }
        else if ( gConfig.bShowDllView )
        {
          HIBYTE(v10) = CMainWnd::RefreshDllsView(0, ghWndDllsListCtrl, gdwProcessIdSelected, 0);
        }
        else
        {
          LOBYTE(v10) = CMainWnd::RefreshHandlesView(0, ghWndHandlesListCtrl, gdwProcessIdSelected, 0);
        }
      }
      ++gdwRefreshCount;
      if ( v14 )
        PostMessageW(ghMainWnd, WM_TREEVIEW_SORT, IDC_TREEVIEW_LIST, gConfig.bShowProcessTree);
      if ( v10 )
        PostMessageW(ghMainWnd, WM_TREEVIEW_SORT, IDC_LISTCTRL_HANDLES, 0);
      if ( HIBYTE(v10) )
        PostMessageW(ghMainWnd, WM_TREEVIEW_SORT, IDC_LISTCTRL_DLLS, 0);
      v1 = v13;
    }
    dwTimeoutNew = -1;
    if ( gConfig.dwRefreshRate )
      dwTimeoutNew = gConfig.dwRefreshRate;
  }
  return 0;
}
// 10C10B8: using guessed type int gdwValue_4F10B8[3];
// 10C5390: using guessed type char gbFlagsInProcPropSheet;
// 10CA098: using guessed type char gNetClrMemoryPerfInfoLoaded;
// 10CA11C: using guessed type int gdwRefreshCount;
// 10CA389: using guessed type char gbMainWndMinimized;
// 10CA90C: using guessed type int gdwRefreshTickCountLast;
// 10CF2E8: using guessed type int (__stdcall *GlobalMemoryStatusEx)(_DWORD);

//----- (01037F60) --------------------------------------------------------
BOOL __stdcall sub_1037F60(HWND hDlg, UINT a2, WPARAM a3, LPARAM hData)
{
  wchar_t *v4; // eax
  int v6; // eax
  int v7; // eax
  HANDLE v8; // eax
  HANDLE v9; // esi
  HANDLE v10; // ST28_4
  DWORD v11; // ecx
  HINSTANCE v12; // eax
  HWND v13; // eax
  LONG v14; // eax
  unsigned int v15; // esi
  struct HWND__ *v16; // eax
  struct _STARTUPINFOW StartupInfo; // [esp+Ch] [ebp-6F8h]
  struct _PROCESS_INFORMATION ProcessInformation; // [esp+50h] [ebp-6B4h]
  struct tagOFNW v19; // [esp+60h] [ebp-6A4h]
  LPARAM lParam; // [esp+B8h] [ebp-64Ch]
  int v21; // [esp+BCh] [ebp-648h]
  wchar_t *v22; // [esp+C0h] [ebp-644h]
  HANDLE TokenHandle; // [esp+E0h] [ebp-624h]
  HKEY phkResult; // [esp+E4h] [ebp-620h]
  DWORD cbData; // [esp+E8h] [ebp-61Ch]
  DWORD dwErrCode; // [esp+ECh] [ebp-618h]
  wchar_t v27[260]; // [esp+F0h] [ebp-614h]
  wchar_t Dst; // [esp+2F8h] [ebp-40Ch]
  BYTE Data[2]; // [esp+500h] [ebp-204h]
  char v30; // [esp+502h] [ebp-202h]

  *Data = 0;
  memset(&v30, 0, 0x1FEu);
  dwErrCode = 65;
  if ( a2 == 272 )
  {
    SetPropW(hDlg, L"Runas", hData);
    if ( hData == 40121 )
    {
      SetWindowTextW(hDlg, L"Runas");
      SetDlgItemTextW(hDlg, 1318, L"Runas:");
      SetDlgItemTextW(hDlg, 1319, L"Select the program to run and then you will be prompted for alternate credentials.");
    }
    else if ( hData == 40122 )
    {
      SetWindowTextW(hDlg, L"Run as Limited User");
      SetDlgItemTextW(hDlg, 1319, L"Select the program to run with standard user privileges.");
    }
    v13 = GetDlgItem(hDlg, 1097);
    hWnd = v13;
    v14 = GetWindowLongW(v13, -16);
    SetWindowLongW(hWnd, -16, v14 | 0x40);
    v21 = -1;
    lParam = 1;
    if ( CommandLine )
    {
      v22 = &CommandLine;
      SendMessageW(hWnd, 0x40Bu, 0, &lParam);
    }
    SendMessageW(hWnd, 0x141u, 0x104u, 0);
    if ( !RegOpenKeyW(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\RunMRU", &phkResult) )
    {
      cbData = 512;
      RegQueryValueExW(phkResult, L"MRUList", 0, 0, Data, &cbData);
      v15 = 0;
      if ( wcslen(Data) )
      {
        do
        {
          LOWORD(dwErrCode) = *&Data[2 * v15];
          cbData = 520;
          if ( !RegQueryValueExW(phkResult, &dwErrCode, 0, 0, v27, &cbData) )
          {
            if ( wcsrchr(v27, 0x5Cu) )
              *wcsrchr(v27, 0x5Cu) = 0;
            v22 = v27;
            SendMessageW(hWnd, 0x40Bu, 0, &lParam);
          }
          ++v15;
        }
        while ( v15 < wcslen(Data) );
      }
      RegCloseKey(phkResult);
    }
    SetFocus(hWnd);
    if ( gpfnSHAutoComplete )
    {
      v16 = SendMessageW(hWnd, 0x407u, 0, 0);
      gpfnSHAutoComplete(v16, 1u);
    }
    SendMessageW(hWnd, 0x14Eu, 0, 0);
    SendMessageW(hWnd, 0x142u, 0, -1);
    SetFocus(hWnd);
    return 1;
  }
  if ( a2 != 273 )
    return 0;
  if ( a3 == 1 )
  {
    GetDlgItemTextW(hDlg, 1097, &CommandLine, 260);
    v6 = GetPropW(hDlg, L"Runas") - 40061;
    if ( v6 )
    {
      v7 = v6 - 60;
      if ( v7 )
      {
        if ( v7 == 1 )
        {
          v8 = GetCurrentProcess();
          OpenProcessToken(v8, 0xF01FFu, &TokenHandle);
          v9 = sub_1026DB0(TokenHandle);
          if ( !v9 )
          {
            ReportMsg(L"Unable to execute process", ghMainWnd);
            return 0;
          }
          memset(&StartupInfo, 0, 0x44u);
          StartupInfo.cb = 68;
          StartupInfo.dwFlags = 1;
          StartupInfo.wShowWindow = 5;
          v10 = TokenHandle;
          _mm_storeu_si128(&ProcessInformation, 0i64);
          CloseHandle(v10);
          if ( !CreateProcessAsUserW(v9, 0, &CommandLine, 0, 0, 0, 0x10u, 0, 0, &StartupInfo, &ProcessInformation) )
          {
            ReportMsg(L"Unable to execute process", ghMainWnd);
            CloseHandle(v9);
            return 0;
          }
          sub_1023300(&CommandLine);
          EndDialog(hDlg, 0);
          CloseHandle(v9);
          return 0;
        }
        v11 = dwErrCode;
        goto LABEL_23;
      }
      v12 = ShellExecuteW(hDlg, L"runas", &CommandLine, 0, 0, 1);
    }
    else
    {
      v12 = ShellExecuteW(hDlg, L"open", &CommandLine, 0, 0, 1);
    }
    v11 = v12;
LABEL_23:
    switch ( v11 )
    {
      case 0u:
      case 8u:
        v11 = 8;
        break;
      case 1u:
      case 2u:
      case 3u:
      case 4u:
      case 6u:
      case 7u:
      case 9u:
      case 0xAu:
      case 0xBu:
      case 0xCu:
      case 0xDu:
      case 0xEu:
      case 0xFu:
      case 0x10u:
      case 0x11u:
      case 0x12u:
      case 0x13u:
      case 0x14u:
      case 0x15u:
      case 0x16u:
      case 0x17u:
      case 0x18u:
      case 0x19u:
      case 0x1Bu:
      case 0x1Cu:
      case 0x1Du:
      case 0x1Eu:
      case 0x1Fu:
        break;
      case 5u:
        v11 = 5;
        break;
      case 0x1Au:
        v11 = 32;
        break;
      case 0x20u:
        v11 = 2;
        break;
      default:
        sub_1023300(&CommandLine);
        goto LABEL_30;
    }
    SetLastError(v11);
    ReportMsg(L"Unable to execute process", ghMainWnd);
    SetFocus(hWnd);
    return 0;
  }
  if ( a3 != 2 )
  {
    if ( a3 == 4 )
    {
      memset(&v19, 0, 0x58u);
      v19.lStructSize = 76;
      v19.hwndOwner = hDlg;
      v19.hInstance = ghInstance;
      v19.nMaxFile = 256;
      v19.Flags = 2097156;
      v19.lpstrTitle = L"Specify executable...";
      v19.lpstrDefExt = L"*.exe";
      v19.nFilterIndex = 1;
      v19.lpstrFilter = L"Executables";
      GetDlgItemTextW(hDlg, 1097, &CommandLine, 260);
      if ( wcschr(&CommandLine, 0x5Cu) )
      {
        wcscpy_s(&Dst, 0x104u, &CommandLine);
        v4 = wcschr(&Dst, 0x5Cu);
        wcscpy_s(&CommandLine, 0x104u, v4 + 1);
        wcschr(&Dst, 0x5Cu)[1] = 0;
        v19.lpstrInitialDir = &Dst;
      }
      v19.lpstrFile = &CommandLine;
      if ( GetOpenFileNameW(&v19) )
      {
        SetDlgItemTextW(hDlg, 1097, &CommandLine);
        return 0;
      }
    }
    return 0;
  }
LABEL_30:
  EndDialog(hDlg, 0);
  return 0;
}
// 10A19EC: using guessed type wchar_t aSpecifyExecuta[22];
// 10A1A18: using guessed type wchar_t aExe_0[6];
// 10A1A28: using guessed type wchar_t aExecutables[12];
// 10A1A6C: using guessed type wchar_t aRunas_0[6];
// 10A1A78: using guessed type wchar_t aUnableToExecut[26];
// 10CA8F4: using guessed type int (__stdcall *gpfnSHAutoComplete)(struct HWND__ *, unsigned int);

//----- (010385F0) --------------------------------------------------------
int __stdcall sub_10385F0(HWND hDlg, int a2, int a3, int a4)
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
      if ( !WTSSendMessageW(0, dword_10CA914, &v23, 2 * ((v7 - v20) >> 1), &String, 2 * v6, 0, 0, &v19, 0) )
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
  dword_10CA914 = a4;
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
// 10A0EE8: using guessed type wchar_t aErrorSendingMe[22];
// 10CF350: using guessed type int (__stdcall *WTSSendMessageW)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);

//----- (01038860) --------------------------------------------------------
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
              dword_10BE0DC = 1;
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
// 10A1578: using guessed type wchar_t aSpecifyDbghelp[23];
// 10A15A8: using guessed type wchar_t aDll_2[6];
// 10A15B4: using guessed type wchar_t aDbghelpDllDbgh[26];
// 10BE0DC: using guessed type int dword_10BE0DC;
// 10CA8F4: using guessed type int (__stdcall *gpfnSHAutoComplete)(struct HWND__ *, unsigned int);

//----- (01038B70) --------------------------------------------------------
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
// 10A14DC: using guessed type wchar_t aBrowseForSymbo[29];

//----- (01038C50) --------------------------------------------------------
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

//----- (01038D50) --------------------------------------------------------
const wchar_t *__cdecl sub_1038D50(int a1)
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
// 10A0E34: using guessed type wchar_t a16[3];
// 10A0E3C: using guessed type wchar_t a256[4];
// 10A0E44: using guessed type wchar_t a65536[6];
// 10A0E50: using guessed type wchar_t a224[5];
// 10A0E5C: using guessed type wchar_t a215[5];
// 10A0E68: using guessed type wchar_t a232[5];
// 10A0E74: using guessed type wchar_t asc_10A0E74[4];

//----- (01038DE0) --------------------------------------------------------
BOOL __stdcall sub_1038DE0(HWND hDlg, UINT a2, WPARAM a3, LPARAM a4)
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
        v7 = sub_1038D50(v11->State);
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
// 10BE130: using guessed type wchar_t aActive[7];

//----- (010390F0) --------------------------------------------------------
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
    dword_10CA3F0 = 1;
    result = TrayIcon_Add(ghMainWnd, 1u, gpGraphInfoOfPhysicalMemory, &gszNullString);
    v2 = 2;
  }
  else
  {
    dword_10CA3F0 = 0;
  }
  if ( gConfig.bShowIoTray )
  {
    dword_10CA3C8 = v2;
    result = TrayIcon_Add(ghMainWnd, v2++, gIOGraphInfo.pGraphData, &gszNullString);
  }
  else
  {
    dword_10CA3C8 = 0;
  }
  if ( gConfig.bShowDiskTray )
  {
    dword_10CA3F4 = v2;
    result = TrayIcon_Add(ghMainWnd, v2++, gDiskGraphInfo.pGraphData, &gszNullString);
  }
  else
  {
    dword_10CA3F4 = 0;
  }
  if ( gConfig.bShowGpuHistory && (result = gpGraphInfoOfGPU) != 0 )
  {
    dword_10CA3C0 = v2;
    result = TrayIcon_Add(ghMainWnd, v2++, gpGraphInfoOfGPU, &gszNullString);
  }
  else
  {
    dword_10CA3C0 = 0;
  }
  if ( gConfig.bShowNetTray )
  {
    dword_10CA600 = v2;
    result = TrayIcon_Add(ghMainWnd, v2++, gNetworkGraphInfo.pGraphData, &gszNullString);
  }
  else
  {
    dword_10CA600 = 0;
  }
  if ( gConfig.bShowCommitTray )
  {
    dword_10CA3C4 = v2;
    result = TrayIcon_Add(ghMainWnd, v2++, gpGraphInfoOfMemory, &gszNullString);
  }
  else
  {
    dword_10CA3C4 = 0;
  }
  if ( gConfig.bTrayCPUHistory )
  {
    dword_10CA3BC = v2;
    result = TrayIcon_Add(ghMainWnd, v2, gpGraphInfoOfCPU, &gszNullString);
  }
  else
  {
    dword_10CA3BC = 0;
  }
  return result;
}
// 10CA3BC: using guessed type int dword_10CA3BC;

//----- (010392A0) --------------------------------------------------------
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

//----- (01039380) --------------------------------------------------------
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
// 10CA38B: using guessed type char gbWindowFinding;

//----- (010395D0) --------------------------------------------------------
LRESULT __stdcall CMainWnd::MainWndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
  if ( Msg == gShellIconMsg )
    HandleTaskbarCreated();
  return HandleMsgHandler(&CMainWnd::gMsgHandler, hWnd, Msg, wParam, lParam);
}
// 10CA884: using guessed type int gShellIconMsg;

//----- (01039600) --------------------------------------------------------
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

//----- (01039660) --------------------------------------------------------
int __cdecl sub_1039660(int a1, int a2, wchar_t *Dst)
{
  return swprintf_s(Dst, 0x400u, L"%d.%d.%d.%d", a2 >> 16, a2, a1 >> 16, a1);
}

//----- (01039690) --------------------------------------------------------
_DWORD *__thiscall sub_1039690(_DWORD *this, int a2)
{
  _DWORD *result; // eax

  result = sub_1055470(this);
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

//----- (010396D0) --------------------------------------------------------
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

//----- (010398E0) --------------------------------------------------------
_DWORD *__thiscall sub_10398E0(_DWORD *this, _DWORD *a2, char a3, _DWORD *a4, int a5, int a6)
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
  v7 = sub_1039690(this, a5);
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

//----- (01039AF0) --------------------------------------------------------
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
// 10681AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);

//----- (01039C10) --------------------------------------------------------
int __thiscall sub_1039C10(_DWORD *this, int a2, _DWORD *a3, _DWORD *a4, int a5)
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
      v13 = sub_10398E0(v5, &a3, 1, v9, a4, a5);
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
    v13 = sub_10398E0(v5, &a4, v19, v9, v8, a5);
    goto LABEL_14;
  }
  *a2 = v12;
  result = a2;
  *(a2 + 4) = 0;
  return result;
}
// 10681AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);

//----- (01039D20) --------------------------------------------------------
int MakeDriverName(wchar_t *pszText, wchar_t *lpszFormat, ...)
{
  va_list ArgList; // [esp+10h] [ebp+10h]

  va_start(ArgList, lpszFormat);
  return vswprintf_s(pszText, 10u, lpszFormat, ArgList);
}

//----- (01039D40) --------------------------------------------------------
int wsprintfW(wchar_t *Dst, wchar_t *Format, ...)
{
  va_list ArgList; // [esp+10h] [ebp+10h]

  va_start(ArgList, Format);
  return vswprintf_s(Dst, 0x1000u, Format, ArgList);
}

//----- (01039D60) --------------------------------------------------------
int sub_1039D60(wchar_t *Dst, wchar_t *Format, ...)
{
  va_list ArgList; // [esp+10h] [ebp+10h]

  va_start(ArgList, Format);
  return vswprintf_s(Dst, 0x105u, Format, ArgList);
}

//----- (01039D80) --------------------------------------------------------
int wsprintf_s(wchar_t *Dst, wchar_t *Format, ...)
{
  va_list ArgList; // [esp+10h] [ebp+10h]

  va_start(ArgList, Format);
  return vswprintf_s(Dst, 0x20u, Format, ArgList);
}

//----- (01039DA0) --------------------------------------------------------
int sub_1039DA0(wchar_t *Dst, wchar_t *Format, ...)
{
  va_list ArgList; // [esp+10h] [ebp+10h]

  va_start(ArgList, Format);
  return vswprintf_s(Dst, 0x32u, Format, ArgList);
}

//----- (01039DC0) --------------------------------------------------------
int MakeDeviceName(wchar_t *Dst, wchar_t *Format, ...)
{
  va_list ArgList; // [esp+10h] [ebp+10h]

  va_start(ArgList, Format);
  return vswprintf_s(Dst, 0x40u, Format, ArgList);
}

//----- (01039DE0) --------------------------------------------------------
int sub_1039DE0(wchar_t *Dst, wchar_t *Format, ...)
{
  va_list ArgList; // [esp+10h] [ebp+10h]

  va_start(ArgList, Format);
  return vswprintf_s(Dst, 0x41u, Format, ArgList);
}

//----- (01039E00) --------------------------------------------------------
int *__thiscall sub_1039E00(_DWORD *this, LPCWSTR lpWideCharStr)
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
    sub_1039FE0(v2, lpWideCharStr);
  }
  else
  {
    v4 = ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>::FindStringResourceInstance(lpWideCharStr, 0);
    if ( v4 )
      sub_103F660(v2, v4, lpWideCharStr);
  }
  return v2;
}

//----- (01039EA0) --------------------------------------------------------
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

//----- (01039F20) --------------------------------------------------------
void __thiscall sub_1039F20(void **this)
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

//----- (01039F70) --------------------------------------------------------
void __thiscall PerformanceInfoInMemory::~PerformanceInfoInMemory(PerformanceInfoInMemory *this)
{
  PerformanceInfoInMemory *v1; // esi

  v1 = this;
  j__free(this->m_pBuffer);
  v1->m_pBuffer = 0;
}

//----- (01039FB0) --------------------------------------------------------
void __thiscall sub_1039FB0(CSystemProcessInfoMap *this)
{
  CSystemProcessInfoMap *v1; // esi
  int *a2; // [esp+4h] [ebp-4h]

  v1 = this;
  sub_1055510(this, &a2, this->_Header->_Left, this->_Header);
  j__free(v1->_Header);
}

//----- (01039FE0) --------------------------------------------------------
int *__thiscall sub_1039FE0(int *this, LPCWSTR lpWideCharStr)
{
  int *v2; // edi
  int v3; // esi
  int *result; // eax

  v2 = this;
  if ( lpWideCharStr && (v3 = WideCharToMultiByte(3u, 0, lpWideCharStr, -1, 0, 0, 0, 0) - 1, v3 > 0) )
  {
    if ( ((*(*v2 - 8) - v3) | (1 - *(*v2 - 4))) < 0 )
      sub_1042330(v2, v3);
    WideCharToMultiByte(3u, 0, lpWideCharStr, -1, *v2, v3, 0, 0);
    if ( v3 > *(*v2 - 8) )
      ATL::AtlThrowImpl(-2147024809);
    *(*v2 - 12) = v3;
    *(v3 + *v2) = 0;
    result = v2;
  }
  else
  {
    sub_103B8D0(v2);
    result = v2;
  }
  return result;
}

//----- (0103A070) --------------------------------------------------------
tagTREEVIEWLISTITEMPARAM *__cdecl sub_103A070(HWND hWnd, char a2, int a3, int a4, int a5, int a6, int a7, u_long hostlong, int a9, int port, int a11, int a12, int a13, int a14)
{
  const __m128i *v14; // esi
  const __m128i *v15; // edi
  tagTREEVIEWLISTITEMPARAM *v16; // esi
  __int32 *v17; // edx
  int *v18; // ecx
  unsigned int v19; // edi
  bool v20; // cf
  LRESULT v21; // eax
  signed int v22; // eax
  int *v23; // edi
  const wchar_t *v24; // eax
  tagTREEVIEWLISTITEMPARAM *result; // eax
  int v26; // eax
  int v27; // edi
  _BYTE *v28; // edi
  char v29; // dl
  char v30; // al
  signed int v31; // ecx
  _DWORD *v32; // edx
  int *v33; // ecx
  unsigned int v34; // edi
  unsigned int v35; // kr00_4
  HWND v36; // ebx
  void *pItemInTcpUdp; // [esp-890h] [ebp-13B0h]
  char ItemInTcpUdp[2192]; // [esp+Ch] [ebp-B14h]
  LVITEMW ItemText; // [esp+89Ch] [ebp-284h]
  LVITEMW Item; // [esp+8D0h] [ebp-250h]
  const __m128i *v41; // [esp+904h] [ebp-21Ch]
  _BYTE *v42; // [esp+908h] [ebp-218h]
  int *v43; // [esp+90Ch] [ebp-214h]
  int v44; // [esp+910h] [ebp-210h]
  HWND v45; // [esp+914h] [ebp-20Ch]
  int v46; // [esp+918h] [ebp-208h]
  __int16 Dst[256]; // [esp+91Ch] [ebp-204h]

  v14 = a9;
  v46 = a4;
  v15 = a6;
  v43 = a12;
  v42 = a14;
  v45 = hWnd;
  v41 = a6;
  v44 = a9;
  Item.mask = 4;
  Item.iItem = 0;
  Item.iSubItem = 0;
  if ( !SendMessageW(hWnd, LVM_GETITEMW, 0, &Item) )
  {
LABEL_15:
    memset(ItemInTcpUdp, 0, 0x890u);
    *&ItemInTcpUdp[4] = 5;
    ItemInTcpUdp[36] = 1;
    v22 = 2;
    *&ItemInTcpUdp[40] = a3;
    if ( a2 )
      v22 = 0;
    *&ItemInTcpUdp[16] = v22;
    *&ItemInTcpUdp[2172] = v46;
    *&ItemInTcpUdp[44] = a5;
    if ( v15 )
      _mm_storeu_si128(&ItemInTcpUdp[48], _mm_loadu_si128(v15));
    *&ItemInTcpUdp[584] = a7;
    *&ItemInTcpUdp[1108] = hostlong;
    if ( v14 )
      _mm_storeu_si128(&ItemInTcpUdp[1112], _mm_loadu_si128(v14));
    v23 = v43;
    *&ItemInTcpUdp[1648] = port;
    if ( gdwVersion >= 1 && !a13 && v43 )
    {
      if ( *v43 )
      {
        v24 = sub_105EFB0(*v43);
        *&ItemInTcpUdp[2184] = _wcsdup(v24);
      }
    }
    *&ItemInTcpUdp[2176] = v23;
    *&ItemInTcpUdp[2180] = a13;
    qmemcpy(&pItemInTcpUdp, ItemInTcpUdp, 0x890u);
    return sub_1017DD0(v45, pItemInTcpUdp);
  }
  while ( 1 )
  {
    if ( (v16 = Item.lParam, a3) && a3 != 1 || Item.lParam->field_2C == a5 )
    {
      if ( a3 == 2 || a3 == 3 )
      {
        v17 = v15;
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
      if ( !LOBYTE(Item.lParam->nRefCount) && Item.lParam->dwStyle == a3 && *&Item.lParam->gap234[20] == a7 )
        break;
    }
LABEL_13:
    ++Item.iItem;
    v21 = SendMessageW(v45, LVM_GETITEMW, 0, &Item);
    v15 = v41;
    if ( !v21 )
    {
      v14 = v44;
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
    v32 = v44;
    v33 = &Item.lParam->field_458;
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
  if ( Item.lParam->field_454 != hostlong )
    goto LABEL_31;
LABEL_41:
  v26 = v46;
  if ( *&Item.lParam[1].field_28E[23] != v46 )
  {
    v27 = port;
LABEL_43:
    *&Item.lParam[1].field_28E[23] = v26;
    v16->field_454 = hostlong;
    v16[1].field_B0 = v27;
    if ( a3 )
    {
      ItemText.iSubItem = 2;
      ItemText.pszText = L"*:*";
      SendMessageW(v45, LVM_SETITEMTEXTW, Item.iItem, &ItemText);
    }
    else
    {
      sub_10244B0(0, 1, 0, hostlong, v44, Dst, 0x100u);
      v35 = wcslen(Dst);
      sub_1024670(1, v27, gszProtocolNames[0], &Dst[v35], 256 - v35);
      v36 = v45;
      ItemText.pszText = Dst;
      ItemText.iSubItem = 2;
      SendMessageW(v45, LVM_SETITEMTEXTW, Item.iItem, &ItemText);
      ItemText.iSubItem = 3;
      ItemText.pszText = gszNetStatus[v46];
      SendMessageW(v36, LVM_SETITEMTEXTW, Item.iItem, &ItemText);
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
  v29 = v16->field_18;
  v30 = 0;
  if ( v29 )
  {
    v31 = v16->field_1C;
    if ( v31 < gConfig.dwHighlightDuration )
    {
      v16->field_10 = 2;
      result = 0;
      v16->field_14 = v31;
      LOBYTE(v16->nRefCount) = 1;
      return result;
    }
    if ( v29 )
    {
      v30 = 1;
      LOBYTE(v16->field_18) = 0;
    }
  }
  v16->field_10 = 0;
  if ( v30 )
    *v28 = 1;
  result = 0;
  LOBYTE(v16->nRefCount) = 1;
  return result;
}
// 109E250: using guessed type wchar_t asc_109E250[4];
// 10BD238: using guessed type wchar_t *gszNetStatus[13];
// 10C4E54: using guessed type int gdwVersion;
// 103A070: using guessed type wchar_t Dst[256];

//----- (0103A4A0) --------------------------------------------------------
CHAR *__thiscall sub_103A4A0(CString *this, __int16 a2)
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

//----- (0103A500) --------------------------------------------------------
int __cdecl sub_103A500(SYSTEM_PROCESS_INFORMATION *pSystemProcessInfo)
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

//----- (0103A580) --------------------------------------------------------
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
      v11 = (&loc_FFFFFF + 1);
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

//----- (0103A670) --------------------------------------------------------
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
      sub_1061A50(pListItem->m_ItemData1, Dest);
      SetDlgItemTextW(hWnd, IDC_DLG_DLLINFO_EDIT_VIRUSTOTAL, Dest);
      v28 = pListItem->m_strPath.pszData;
      if ( v28 && *v28 != '[' )
      {
        v29 = sub_1061C10(pListItem->m_ItemData1);
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
              sub_1061C30(pItemParam, ~(pItemParam->field_2C >> 1) & 1, v38 != 0);
              v39 = GetDlgItem(hWnd, IDC_DLG_DLLINFO_BUTTON_SUBMIT);
              EnableWindow(v39, 0);
              sub_1061A50(pItemParam->m_HashData, v48);
              v40 = sub_1061C10(pItemParam->m_HashData);
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
        sub_100B780(hWnd, pItemParam->m_strPath);
        return 1;
      }
      if ( uID > 1005 )
      {
        if ( uID == IDC_DLG_DLLINFO_BUTTON_EXPLORE_LOCATION )
        {
          sub_100B780(hWnd, pItemParam->m_strLocation);
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
      sub_1061A50(pItemParam->m_HashData, Dest);
      v34 = wcscmp(String, Dest);
      if ( v34 )
        v34 = -(v34 < 0) | 1;
      if ( !v34 )
        return 1;
      SetDlgItemTextW(hWnd, IDC_DLG_DLLINFO_EDIT_VIRUSTOTAL, Dest);
      v44 = sub_1061C10(pItemParam->m_HashData);
      v35 = GetDlgItem(hWnd, IDC_DLG_DLLINFO_BUTTON_SUBMIT);
      goto LABEL_44;
    case WM_CTLCOLORSTATIC:
      if ( pListItem != GetDlgItem(hWnd, IDC_DLG_DLLINFO_EDIT_VIRUSTOTAL) || !sub_1061820(pItemParam->m_HashData) )
        return 0;
      if ( sub_1062910(pItemParam->m_HashData) )
        SetTextColor(uID, 0xFFu);
      else
        SetTextColor(uID, 0xFF0000u);
      SelectObject(uID, ghDefaultUnderlineFontHandle);
      return GetSysColorBrush(COLOR_BTNHILIGHT);
    default:
      return 0;
  }
}
// 109E220: using guessed type wchar_t aData_0[5];
// 10CA391: using guessed type char gbWintrustInited;

//----- (0103ADD0) --------------------------------------------------------
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
        sub_104DC50(hDlg, PropItem->pListItem);
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
// 106A009: using guessed type int _endthread(void);
// 10A65E8: using guessed type wchar_t aStrings[8];
// 10C4E28: using guessed type int gdwVirtualScreenWidth;

//----- (0103B330) --------------------------------------------------------
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
// 10A2E08: using guessed type wchar_t aProcexp152Sys[15];

//----- (0103B490) --------------------------------------------------------
HCURSOR __cdecl sub_103B490(HWND hWnd, tagTREEVIEWLISTITEMPARAM **pData)
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
  *ArgList = 0;
  hCursor = 0;
  v32 = 0;
  SendMessageW(hWnd, LVM_DELETEALLITEMS, 0, 0);
  hWnd_1 = pData[1];
  v34 = 0;
  result = SendMessageW(hWnd_1, LVM_GETNEXTITEM, 0xFFFFFFFF, 2);
  lParam.iItem = result;
  if ( result != -1 )
  {
    if ( !*(pData + 20) )
    {
      GetSystemProcessInfo(&hCursor, 0);
      v4 = hCursor;
      v5 = (*pData)->dwProcessId;
      if ( hCursor->UniqueProcessId != v5 )
      {
        while ( v4->NextEntryOffset )
        {
          v4 = (v4 + v4->NextEntryOffset);
          if ( v4->UniqueProcessId == v5 )
            goto LABEL_8;
        }
        v4 = 0;
      }
LABEL_8:
      v6 = LoadCursorW(0, 0x7F02);
      SetCursor(v6);
      pData[3] = OpenProcess(0x80000000, 0, (*pData)->dwProcessId);
      if ( SymInitialize )
      {
        EnterCriticalSection(&gPE_ImageItemVerifiedLock);
        v32 = 1;
        SymSetOptions(0x10027u);
        v7 = pData[3];
        if ( v7 )
          *(pData + 20) = SymInitialize(v7, 0, 1);
        if ( !*(pData + 20) )
        {
          if ( pData[3] )
            CloseHandle(pData[3]);
          v8 = GetCurrentProcess();
          pData[3] = v8;
          *(pData + 20) = SymInitialize(v8, 0, 1);
        }
      }
      ReturnLength = 1000;
      v9 = malloc(0x3E8u);
      pData[2] = v9;
      if ( NtQuerySystemInformation(SystemModuleInformation, v9, 0x3E8u, &ReturnLength) )
      {
        do
        {
          free(pData[2]);
          ReturnLength += 1000;
          v10 = ReturnLength;
          v11 = malloc(ReturnLength);
          pData[2] = v11;
        }
        while ( NtQuerySystemInformation(SystemModuleInformation, v11, v10, &ReturnLength) );
      }
      v12 = *pData;
      pData[4] = 0;
      if ( !(v12->dwStyle & 0x10) )
      {
        v13 = RtlCreateQueryDebugBuffer(0, 0);
        pData[4] = v13;
        if ( v13 )
        {
          v14 = v4->UniqueProcessId;
          v26 = v13;
          v25 = v14;
          v15 = _beginthreadex(0, 0, QueryProcessDebugInforThreadProc, &v25, 0, &ThreadId);
          if ( WaitForSingleObject(v15, 0xFA0u) == 258 )
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
    v16 = pData[1];
    lParam.mask = 4;
    SendMessageW(v16, LVM_GETITEMW, 0, &lParam);
    v17 = lParam.lParam;
    v18 = LoadCursorW(0, 0x7F02);
    v19 = 0;
    hCursor = SetCursor(v18);
    if ( *&v17[1].field_28E[27] & 0xFFFFFFFC )
    {
      do
      {
        v20 = *(*&v17[1].field_28E[25] + 4 * v19);
        if ( v20 && v20 != -1 )
        {
          sub_103DD60(1, v20, &v33, pData[3], 0, 0, pData[4], pData[2]);
          v21 = wcscmp(&v35, L"0x0");
          if ( v21 )
            v21 = -(v21 < 0) | 1;
          if ( v21 )
          {
            lParam.mask = 5;
            lParam.iItem = 0x7FFFFFFF;
            lParam.iSubItem = 0;
            lParam.stateMask = 0;
            lParam.state = 0;
            wsprintf(&Dst, L"%d", ArgList[0]);
            lParam.iImage = 0;
            lParam.pszText = &Dst;
            v22 = (*ArgList + 1);
            *ArgList = v22;
            lParam.lParam = v22;
            result = SendMessageW(v28, LVM_INSERTITEMW, 0, &lParam);
            if ( result == -1 )
              return result;
            lParam.iItem = result;
            lParam.pszText = &v35;
            lParam.mask = 1;
            lParam.iSubItem = 1;
            SendMessageW(v28, LVM_SETITEMW, 0, &lParam);
          }
        }
        ++v19;
      }
      while ( v19 < *&v17[1].field_28E[27] >> 2 );
    }
    if ( v32 )
      LeaveCriticalSection(&gPE_ImageItemVerifiedLock);
    result = SetCursor(hCursor);
  }
  return result;
}
// 10A5208: using guessed type wchar_t a0x0[4];
// 10CF264: using guessed type int (__stdcall *RtlDestroyQueryDebugBuffer)(_DWORD);

//----- (0103B8D0) --------------------------------------------------------
_BYTE *__thiscall sub_103B8D0(_DWORD *this)
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

//----- (0103B930) --------------------------------------------------------
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
              sub_100DB80(&strText, v12, v13);
              sub_103A4A0(&strText, 0);
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

//----- (0103BBC0) --------------------------------------------------------
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
  if ( !byte_10BE8B0 )
    v4 = -v4;
  return v4;
}
// 103BBC0: using guessed type int __stdcall FindDlg_SortCallback(int, int, int);
// 10BE8B0: using guessed type char byte_10BE8B0;

//----- (0103BC30) --------------------------------------------------------
HANDLE __stdcall FindExecutableImageExW_1(PCWSTR FileName, PCWSTR SymbolPath, PWSTR ImageFilePath, PFIND_EXE_FILE_CALLBACKW Callback, PVOID CallerData)
{
  return FindExecutableImageExW(FileName, SymbolPath, ImageFilePath, 0, 0);
}

//----- (0103BC50) --------------------------------------------------------
int __stdcall sub_103BC50(LPCWSTR a1, LPCWSTR a2, int a3)
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
  SymbolPath = sub_1039E00(&v11, a2);
  LOBYTE(v14) = 1;
  FileName = sub_1039E00(&v10, a1);
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

//----- (0103BD50) --------------------------------------------------------
int __userpurge FindDlg_SearchThreadProc@<eax>(signed int a1@<ebx>, _BYTE *wParam)
{
  HWND v2; // eax

  CMainWnd::RefreshDllsView(a1, ghWndListInFindDlg, 0, wParam);
  CMainWnd::RefreshHandlesView(a1, ghWndListInFindDlg, 0, wParam);
  v2 = GetParent(ghWndListInFindDlg);
  PostMessageW(v2, 0x464u, 0, 0);
  return 0;
}

//----- (0103BDA0) --------------------------------------------------------
HWND __cdecl sub_103BDA0(HWND hWndParent)
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

//----- (0103BDF0) --------------------------------------------------------
int *__thiscall sub_103BDF0(int *this, int a2)
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

//----- (0103BE70) --------------------------------------------------------
HLOCAL __cdecl GetErrorMsg(wchar_t *Dst, size_t SizeInWords)
{
  int v2; // ecx
  DWORD v3; // eax
  WCHAR Buffer[2]; // [esp+0h] [ebp-4h]

  *Buffer = v2;
  v3 = GetLastError();
  FormatMessageW(0x1100u, 0, v3, LOCALE_USER_DEFAULT, Buffer, 0, 0);
  swprintf_s(Dst, SizeInWords, L"%s", *Buffer);
  return LocalFree(*Buffer);
}

//----- (0103BEC0) --------------------------------------------------------
int __cdecl PE_MakeFileVersion(int a1, int a2, wchar_t *Dst, size_t SizeInWords)
{
  return swprintf_s(Dst, SizeInWords, L"%d.%d.%d.%d", a2 >> 16, a2, a1 >> 16, a1);
}

//----- (0103BEF0) --------------------------------------------------------
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
// 10C4E54: using guessed type int gdwVersion;

//----- (0103C020) --------------------------------------------------------
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
// 10CABA0: using guessed type int gulQueryObjectResult;

//----- (0103C090) --------------------------------------------------------
int __stdcall sub_103C090(DWORD nLengthNeeded)
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

//----- (0103C190) --------------------------------------------------------
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
  wsprintf(SubBlock, L"\\StringFileInfo\\%04X%04X\\%s", a2, a3, lpszName);
  ms_exc.registration.TryLevel = 0;
  v4 = VerQueryValueW(pBlock, SubBlock, &lpBuffer, &puLen);
  v5 = v4;
  v9 = v4;
  ms_exc.registration.TryLevel = -2;
  result = lpBuffer;
  if ( !v5 )
    result = 0;
  return result;
}

//----- (0103C270) --------------------------------------------------------
__int16 *__cdecl sub_103C270(int a1, rsize_t SizeInWords)
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

//----- (0103C350) --------------------------------------------------------
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

//----- (0103C3E0) --------------------------------------------------------
int __stdcall QueryProcessDebugInforThreadProc(_DWORD *a1)
{
  return RtlQueryProcessDebugInformation(*a1, 1, a1[1]);
}
// 10CF260: using guessed type int (__stdcall *RtlQueryProcessDebugInformation)(_DWORD, _DWORD, _DWORD);

//----- (0103C400) --------------------------------------------------------
char __cdecl sub_103C400(int *a1, _DWORD *a2)
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

//----- (0103C4F0) --------------------------------------------------------
char __cdecl sub_103C4F0(tagHandleTableEntryInfo *pInfo, int a2, int a3, int a4)
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
    && (!_wcsicmp(lpOutBuffer + 2, L"\\Device\\Tcp") || !_wcsicmp(lpOutBuffer + 2, L"\\Device\\Udp")) )
  {
    if ( GetVersion() >= 5u )
    {
      DeviceIoControl = ::DeviceIoControl;
    }
    else
    {
      DeviceIoControl = ::DeviceIoControl;
      ::DeviceIoControl(ghDriverHandle, 0x83350020, pInfo, 4u, &OutBuffer, 4u, &BytesReturned, 0);
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
// 10C10D4: using guessed type int sdwProcessIdInsub_103C4F0;

//----- (0103C750) --------------------------------------------------------
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
  wcscpy_s(pszBuffer, cbBufLen, &gszNullString);
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
    ProcessHandle = PE_DuplicateProcessHandle(pTableEntry->UniqueProcessId, pTableEntry->HandleValue, 0);
    hObject = ProcessHandle;
    if ( ProcessHandle )
    {
      NtQueryObject(ProcessHandle, ObjectTypeInformation, 0, 0, &cbRet);
      v12 = cbRet;
      pObjectType = malloc(cbRet);
      v14 = v12;
      v15 = pObjectType;
      v16 = NtQueryObject(hObject, ObjectTypeInformation, pObjectType, v14, 0);
      if ( v16 )
        MakeDeviceName(pszObjectTypeName, L"<Unknown type: %X>", v16);
      else
        wcsncpy_s(pszObjectTypeName, 0x40u, v15->TypeName.Buffer, v15->TypeName.Length >> 1);
      free(v15);
      CloseHandle(hObject);
LABEL_17:
      v5 = cbBufLen;
      goto LABEL_18;
    }
    if ( ghDriverHandle != -1 )
    {
      v8 = 2 * cbBufLen + 8;
      pInfo = malloc(v8);
      InBuffer[0] = pTableEntry->UniqueProcessId;
      InBuffer[1] = pTableEntry->Object;
      InBuffer[3] = pTableEntry->HandleValue;
      hObject = pInfo;
      v10 = DeviceIoControl(ghDriverHandle, CTRLCODE_QUERY_OBJECT_TYPE, InBuffer, 0x10u, pInfo, v8, &BytesReturned, 0);
      v11 = hObject;
      if ( v10 )
        wcscpy_s(pszObjectTypeName, 0x40u, &hObject->TypeName.Buffer);
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
        if ( ghDriverHandle == -1 )
        {
          v26 = PE_DuplicateProcessHandle(pTableEntry->UniqueProcessId, pTableEntry->HandleValue, 0);
          if ( v26 )
          {
            cbRet = 1024;
            v27 = malloc(0x400u);
            _mm_storel_epi64(v27, 0i64);
            v27->Name.Length = cbRet - 8;
            if ( !ghBackendQueryObjectThreadHandle )
              ghBackendQueryObjectThreadHandle = _beginthreadex(0, 0, BackendQueryObjectThreadProc, 0, 0, &ThreadId);
            v28 = ghExitEventForQueryObject;
            if ( !ghExitEventForQueryObject )
            {
              ghExitEventForQueryObject = CreateEventW(
                                            ghExitEventForQueryObject,
                                            ghExitEventForQueryObject,
                                            ghExitEventForQueryObject,
                                            ghExitEventForQueryObject);
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
                wcsncpy_s(Dst, cbBufLen, v27);
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
          BytesReturned = OutBuffer;
          InBuffer[1] = v23;
          v24 = _wcsicmp(pszObjectTypeName, L"file") == 0;
          v25 = BytesReturned;
          InBuffer[3] = pTableEntry->HandleValue;
          LOBYTE(InBuffer[2]) = v24;
          if ( CDriver::Control(CTRLCODE_DUPLICATE_HANDLE, InBuffer, 0x10u, BytesReturned, cbLength) )
          {
            wcscpy_s(Dst, cbBufLen, (v25 + 4));
            if ( v38 )
              *v38 = *v25;
          }
          free(v25);
        }
      }
      else
      {
        v19 = PE_DuplicateProcessHandle(pTableEntry->UniqueProcessId, pTableEntry->HandleValue, 0);
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
      ProcessHandle2 = PE_DuplicateProcessHandle(pTableEntry->UniqueProcessId, pTableEntry->HandleValue, 8u);
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
                 &gszNullString,
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
    ThreadHandle = PE_DuplicateProcessHandle(
                     pTableEntry->UniqueProcessId,
                     pTableEntry->HandleValue,
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
          SystemProcessInfo_GetSystemProcessName(ThreadInfo.ClientId.UniqueProcess, 0, pszText, 0x100u);
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
        SystemProcessInfo_GetSystemProcessName(ProcessInfo.UniqueProcessId, 0, pszText, 0x100u);
        swprintf_s(Dst, v5, L"%s(%d)", pszText, ProcessInfo.UniqueProcessId);
        CloseHandle(ThreadHandle);
        return;
      }
      CloseHandle(ThreadHandle);
    }
    else if ( ghDriverHandle != -1 )
    {
      GetErrorMsg(v48, 0x104u);
      swprintf_s(Dst, v5, L"<%s>", v48);
    }
  }
}
// 10CABA0: using guessed type int gulQueryObjectResult;

//----- (0103CE20) --------------------------------------------------------
int __cdecl sub_103CE20(DWORD BytesReturned, LPVOID lpOutBuffer)
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
  if ( gdwSymbolAddressOfMmMaximumNonPagedPoolInBytes || !dword_10BE0DC )
  {
    dwSymbolAddress = gdwSymbolAddressOfMmSizeOfPagedPoolInBytes;
  }
  else
  {
    gdwSymbolAddressOfMmMaximumNonPagedPoolInBytes = LoadSystemModulesSymbolAddress("MmMaximumNonPagedPoolInBytes");
    dwSymbolAddress = LoadSystemModulesSymbolAddress("MmSizeOfPagedPoolInBytes");
    gdwSymbolAddressOfMmSizeOfPagedPoolInBytes = dwSymbolAddress;
    dword_10BE0DC = 0;
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
// 10BE0DC: using guessed type int dword_10BE0DC;
// 10E50E8: using guessed type int gdwSymbolAddressOfMmMaximumNonPagedPoolInBytes;
// 10E50EC: using guessed type int gdwSymbolAddressOfMmSizeOfPagedPoolInBytes;

//----- (0103CF30) --------------------------------------------------------
char __cdecl sub_103CF30(HANDLE hProcess, WCHAR **ppszFileName)
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

//----- (0103D050) --------------------------------------------------------
HICON __cdecl ExtractApplicationIcon(LPCWSTR pszPath, int uFlags)
{
  SHFILEINFOW FileInfo; // [esp+0h] [ebp-2B8h]

  FileInfo.hIcon = 0;
  if ( !pszPath )
    return 0;
  SHGetFileInfoW(pszPath, 0, &FileInfo, sizeof(SHFILEINFOW), uFlags | SHGFI_ICON);
  return FileInfo.hIcon;
}

//----- (0103D0C0) --------------------------------------------------------
char __cdecl sub_103D0C0(HANDLE hProcess, tagTREEVIEWLISTITEMPARAM *pItem)
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
  if ( !sub_1040A90(hProcess, pItem->dwProcessId, &pszFileName, pItem) )
  {
    if ( pItem->dwProcessId <= 8u )
    {
      v27 = pszFileName;
    }
    else
    {
      pszErrorMsg = malloc(0x208u);
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
  if ( PE_GetProductCopyright(pszFileName, pItem->field_28E, 0x41u, &pItem->pszTitle, &pItem->pszValue314)
    && GetLastError() != ERROR_RESOURCE_TYPE_NOT_FOUND )
  {
    v3 = wcslen(pszFileName_1);
    v4 = malloc(2 * (v3 + 260));
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
    pszFileName2 = _wcsdup(pszFileName_1);
    PE_GetFullPathName(&pszFileName2);
    v5 = pszFileName2;
    pItem->szProcessName = pszFileName2;
    if ( PE_CheckExeFile(v5, &pItem->dwTimeDateStamp, &hObject, &pItem->field_28A) )
      pItem->dwStyle |= 0x100u;
    else
      pItem->dwStyle &= -0x101u;
    if ( !_wcsicmp(pItem->szProcessName2, L"rundll32.exe") && (v6 = pItem->pszCommandLine) != 0 && wcschr(v6, 0x2Cu) )
    {
      pszCommandLine = _wcsdup(pItem->pszCommandLine);
      pszCommandLine2 = pszCommandLine;
      v9 = (pszCommandLine + 1);
      do
      {
        v10 = *pszCommandLine;
        ++pszCommandLine;
      }
      while ( v10 );
      _wcsupr_s(pszCommandLine2, ((pszCommandLine - v9) >> 1) + 1);
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
        v18 = malloc(2 * v17);
        pItem->m_ExtensionName = v18;
        SearchPathW(0, lpFileName, 0, pszFileName2, v18, &FilePart);
        _wcslwr_s(pItem->m_ExtensionName, pszFileName2);
        PE_GetProductCopyright(pItem->m_ExtensionName, Dst, 0x40u, &pItem->pszFileDesc, &pItem->pszCompany);
      }
      free(pszCommandLine2);
    }
    else if ( _wcsicmp(pItem->szProcessName2, L"svchost.exe") || (v19 = pItem->pszCommandLine) == 0 )
    {
      if ( !_wcsicmp(pItem->szProcessName2, L"dllhost.exe") )
      {
        v20 = pItem->pszCommandLine;
        if ( v20 )
          PE_LoadProductCopyright(
            v20,
            &pItem->field_350,
            &pItem->m_ExtensionName,
            &pItem->pszFileDesc,
            &pItem->pszCompany);
      }
    }
    else
    {
      sub_1024730(v19, &pItem->szServiceName);
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
        GetClassNameW(hWndChild, ClassName, 260);
        if ( pszFileName2 == pItem->dwProcessId && !wcsncmp(ClassName, L"MMCMainFrame", 0x104u) )
        {
          SendMessageTimeoutW(hWndChild, WM_GETICON, 0, 0, 0, 200u, &pItem->hIcon);
          SendMessageTimeoutW(hWndChild, WM_GETICON, 1u, 0, 0, 200u, &pItem->hFileIcon);
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
  SendMessageW(ghMainWnd, WM_MSG_7F3, 0, pItem);
  pItem->hFileIcon = ExtractApplicationIcon(v24, 0);
LABEL_59:
  if ( pszFileName )
    free(pszFileName);
  return 1;
}

//----- (0103D670) --------------------------------------------------------
WCHAR *__cdecl VerifyImage(tagTREEVIEWLISTITEMPARAM *pItem, char fNeedVerify)
{
  WCHAR *v2; // eax
  int *v3; // ecx
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
  int *pdwVerifyValue; // [esp+24h] [ebp-8A8h]
  PCERT_CONTEXT pCertContext; // [esp+28h] [ebp-8A4h]
  __int16 szBuffer[1040]; // [esp+A8h] [ebp-824h]

  if ( pItem->nListType == 1 )
  {
    v2 = *&pItem->gap154[4];
    v3 = &pItem->gap154[12];
    pszDefault = *pItem->gap154;
    v5 = &pItem->gap154[16];
    v6 = &pItem->gap154[20];
  }
  else
  {
    v2 = pItem->szProcessName;
    v3 = &pItem->dwVerifyValue;
    pszDefault = pItem->pszValue314;
    v5 = &pItem->field_344;
    v6 = &pItem->pszVerifyTitle;
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
        *pdwVerifyValue = v8->dwValue;
      }
      else
      {
        *ppszVerifyTitle = _wcsdup(L"Verifying...");
        SendMessageW(ghMainWnd, WM_MSG_7F0, 0, pItem);
        v9 = LoadCursorW(0, IDC_WAIT);
        hCursor = SetCursor(v9);
        dwCertEncodingTypeCount = 32;
        lret = PE_DoubleVerify(
                 pcwszMemberFilePath,
                 0,
                 0,
                 0,
                 0,
                 &dwCertEncodingTypeCount,
                 &pCertContext,
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
            wcscpy_s(szBuffer, 1040u, L"Certificate expired");
          else
            GetErrorMsg(szBuffer, 0x410u);
          if ( wcschr(szBuffer, '.') )
            *wcschr(szBuffer, '.') = 0;
          if ( pszDefault )
            nDefLen = wcslen(pszDefault);
          else
            nDefLen = 1;
          v20 = wcslen(szBuffer) + nDefLen + 32;
          v21 = malloc(2 * v20);
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
          v12 = pCertContext;
          *pdwVerifyValue = 1;
          v13 = (v12 + 1);
          do
          {
            LOWORD(v14) = *v12;
            ++v12;
          }
          while ( v14 );
          v15 = ((v12 - v13) >> 1) + 0x40;
          pszText = malloc(2 * v15);
          swprintf_s(pszText, v15, L"(Verified) %s", pCertContext);
          v17 = _wcsdup(pCertContext);
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
    SendMessageW(ghMainWnd, WM_MSG_7F0, 0, pItem);
  }
  return *pRet;
}

//----- (0103D9D0) --------------------------------------------------------
SYSTEM_HANDLE_INFORMATION *__cdecl SystemHandleInfo_GetHandlesNumber(SYSTEM_HANDLE_INFORMATION *a1)
{
  SYSTEM_HANDLE_INFORMATION *result; // eax

  result = a1;
  if ( a1 )
    result = a1->NumberOfHandles;
  return result;
}

//----- (0103D9E0) --------------------------------------------------------
SYSTEM_HANDLE_TABLE_ENTRY_INFO **__cdecl GetHandleTableEntry(SYSTEM_HANDLE_INFORMATION *pHandleInfo, int nIndex, SYSTEM_HANDLE_TABLE_ENTRY_INFO **pEntry)
{
  SYSTEM_HANDLE_TABLE_ENTRY_INFO **result; // eax
  SYSTEM_HANDLE_TABLE_ENTRY_INFO *pInfo; // ecx

  if ( gbSupportExtendedSystemHandleInformation )
  {
    result = pEntry;
    *pEntry = (pHandleInfo->Handles + sizeof(SYSTEM_HANDLE_TABLE_ENTRY_INFO_EX) * nIndex + 4);
  }
  else
  {
    pInfo = (pHandleInfo + sizeof(SYSTEM_HANDLE_TABLE_ENTRY_INFO) * nIndex);
    stru_10DBC0C.field_10 = pInfo->HandleValue;
    stru_10DBC0C.GrantedAccess = *&pInfo[1].UniqueProcessId;
    LOBYTE(stru_10DBC0C.field_14) = BYTE1(pInfo->Object);
    stru_10DBC0C.Object = HIWORD(pInfo->Object);
    *&stru_10DBC0C.field_0 = pInfo->GrantedAccess;
    *(&stru_10DBC0C.field_10 + 1) = LOBYTE(pInfo->Object);
    *&stru_10DBC0C.ObjectTypeIndex = *&pInfo->ObjectTypeIndex;
    result = pEntry;
    *pEntry = &stru_10DBC0C;
  }
  return result;
}
// 10CABA5: using guessed type char gbSupportExtendedSystemHandleInformation;
// 10DBC0C: using guessed type PE_SYSTEM_HANDLE_TABLE_ENTRY_INFO stru_10DBC0C;

//----- (0103DA60) --------------------------------------------------------
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

//----- (0103DAF0) --------------------------------------------------------
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
    pNodeRet = sub_103E4B0(&pLocalMap, *ppSystemProcessInfo, pSystemProcessorCycleTimeInfo_1, dwBufLen);
    pMapIn = pMap;
    pMap->_Header = pNodeRet;
    LocalMap._Header = pLocalMap;
    pLocalMapIn = pLocalMap;
    pMapIn->_Size = LocalMap._Size;
    sub_1055510(&pLocalMap, &pSystemProcessorPerformanceInfo, LocalMap._Header->_Left, pLocalMapIn);
    j__free(pLocalMap);
  }
  return __PAIR__(v24, v8);
}
// 10CF2F4: using guessed type int GetProcessorSystemCycleTime;

//----- (0103DC80) --------------------------------------------------------
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
