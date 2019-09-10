
//----- (00FD0150) --------------------------------------------------------
int __cdecl Command_ShowDllsPane(HWND hWnd)
{
  HMENU v1; // eax
  signed int v2; // eax
  UINT v3; // ST10_4
  HMENU v4; // eax
  LPARAM v5; // eax
  int v6; // eax
  int v7; // eax
  HMENU v8; // eax
  UINT_PTR v9; // ST0C_4
  HMENU v10; // eax
  LRESULT v11; // eax

  gConfig.bShowDllView = 1;
  v1 = GetMenu(hWnd);
  CheckMenuItem(v1, 0x9C4Bu, 8u);
  v2 = 0;
  if ( !gConfig.bShowDllView )
    v2 = 8;
  v3 = v2;
  v4 = GetMenu(hWnd);
  CheckMenuItem(v4, 0x9C46u, v3);
  v5 = 1;
  if ( gConfig.bShowDllView )
    v5 = 4;
  PostMessageW(ghWndToolbar, 0x42Bu, 0x9C5Eu, v5);
  InvalidateRect(ghWndToolbar, 0, 1);
  if ( hWnd )
    SetEvent(ghRefreshEventHandle);
  v6 = 5;
  if ( gConfig.bShowDllView )
    v6 = 0;
  ShowWindow(ghWndHandlesListCtrl, v6);
  v7 = 0;
  if ( gConfig.bShowDllView )
    v7 = 5;
  ShowWindow(ghWndDllsListCtrl, v7);
  if ( gConfig.bShowLowerPane )
  {
    v8 = GetMenu(ghMainWnd);
    RemoveMenu(v8, 5u, 0x400u);
    v9 = ghDllMenuPopup;
    v10 = GetMenu(ghMainWnd);
    InsertMenuW(v10, 5u, 0x410u, v9, L"&DLL");
  }
  v11 = SendMessageW(ghWndDllsListCtrl, 0x100Cu, 0xFFFFFFFF, 2);
  UpdateMenuStatus(v11 != -1, 5);
  DrawMenuBar(ghMainWnd);
  if ( !gConfig.bShowLowerPane )
    Command_ShowLowerPane(ghMainWnd);
  return 0;
}

//----- (00FD02B0) --------------------------------------------------------
int __cdecl Command_ShowHandlesPane(HWND hWnd)
{
  HMENU v1; // eax
  signed int v2; // eax
  UINT v3; // ST10_4
  HMENU v4; // eax
  LPARAM v5; // eax
  int v6; // eax
  int v7; // eax
  HMENU v8; // eax
  UINT_PTR v9; // ST0C_4
  HMENU v10; // eax
  LRESULT v11; // eax

  gConfig.bShowDllView = 0;
  v1 = GetMenu(hWnd);
  CheckMenuItem(v1, 0x9C4Bu, 0);
  v2 = 0;
  if ( !gConfig.bShowDllView )
    v2 = 8;
  v3 = v2;
  v4 = GetMenu(hWnd);
  CheckMenuItem(v4, 0x9C46u, v3);
  v5 = 1;
  if ( gConfig.bShowDllView )
    v5 = 4;
  PostMessageW(ghWndToolbar, 0x42Bu, 0x9C5Eu, v5);
  PostMessageW(ghWndToolbar, 0x401u, 0x9C47u, gConfig.bShowDllView == 0);
  InvalidateRect(ghWndToolbar, 0, 1);
  if ( hWnd )
    SetEvent(ghRefreshEventHandle);
  v6 = 5;
  if ( gConfig.bShowDllView )
    v6 = 0;
  ShowWindow(ghWndHandlesListCtrl, v6);
  v7 = 0;
  if ( gConfig.bShowDllView )
    v7 = 5;
  ShowWindow(ghWndDllsListCtrl, v7);
  if ( !gConfig.bShowLowerPane )
    goto LABEL_17;
  v8 = GetMenu(ghMainWnd);
  RemoveMenu(v8, 5u, 0x400u);
  v9 = ghHandleMenuPopup;
  v10 = GetMenu(ghMainWnd);
  InsertMenuW(v10, 5u, 0x410u, v9, L"H&andle");
  v11 = SendMessageW(ghWndHandlesListCtrl, 0x100Cu, 0xFFFFFFFF, 2);
  UpdateMenuStatus(v11 != -1, 5);
  DrawMenuBar(ghMainWnd);
  if ( !gConfig.bShowLowerPane )
LABEL_17:
    Command_ShowLowerPane(ghMainWnd);
  return 0;
}

//----- (00FD0430) --------------------------------------------------------
int __cdecl Command_ViewDllsProperties(HWND hWnd)
{
  if ( gConfig.bShowDllView )
    Command_ShowHandlesPane(hWnd);
  else
    Command_ShowDllsPane(hWnd);
  if ( ghFindDlg )
    SendMessageW(ghFindDlg, 0x18u, 0, 0);
  return 0;
}

//----- (00FD0480) --------------------------------------------------------
int __cdecl Command_UnnamedHandlesAndMappings(HWND hWnd)
{
  signed int v1; // eax
  bool v2; // zf
  UINT v3; // ST0C_4
  HMENU v4; // eax

  v1 = 0;
  v2 = gConfig.bShowUnnamedHandles != 0;
  gConfig.bShowUnnamedHandles = gConfig.bShowUnnamedHandles == 0;
  if ( !v2 )
    v1 = 8;
  v3 = v1;
  v4 = GetMenu(hWnd);
  CheckMenuItem(v4, 0x9C47u, v3);
  if ( gConfig.bShowLowerPane && gdwProcessIdSelected != -1 )
    SetEvent(ghEvent2);
  SendMessageW(ghWndToolbar, 0x403u, 0x9C47u, gConfig.bShowUnnamedHandles);
  return 0;
}

//----- (00FD0500) --------------------------------------------------------
int __cdecl Command_HighlightRelocatedDlls(HWND hWnd)
{
  signed int v1; // eax
  bool v2; // zf
  UINT v3; // ST08_4
  HMENU v4; // eax

  v1 = 0;
  v2 = gConfig.bHighlightRelocatedDlls != 0;
  gConfig.bHighlightRelocatedDlls = gConfig.bHighlightRelocatedDlls == 0;
  if ( !v2 )
    v1 = 8;
  v3 = v1;
  v4 = GetMenu(hWnd);
  CheckMenuItem(v4, 0x9C50u, v3);
  InvalidateRgn(ghWndDllsListCtrl, 0, 1);
  return 0;
}

//----- (00FD0550) --------------------------------------------------------
int __cdecl Command_ScrollToNewProcess(HWND hWnd)
{
  signed int v1; // eax
  bool v2; // zf
  UINT v3; // ST08_4
  HMENU v4; // eax

  v1 = 0;
  v2 = gConfig.bShowNewProcesses != 0;
  gConfig.bShowNewProcesses = gConfig.bShowNewProcesses == 0;
  if ( !v2 )
    v1 = 8;
  v3 = v1;
  v4 = GetMenu(hWnd);
  CheckMenuItem(v4, 0x9F0Du, v3);
  UpdateWindowPlacement(ghMainWnd, 1);
  return 0;
}

//----- (00FD05A0) --------------------------------------------------------
int __cdecl Command_Help(int a1)
{
  wchar_t *v1; // eax
  WCHAR FileName; // [esp+4h] [ebp-414h]
  WCHAR Filename; // [esp+20Ch] [ebp-20Ch]

  GetModuleFileNameW(0, &Filename, 0x104u);
  v1 = wcsrchr(&Filename, 0x5Cu);
  wcscpy_s(v1, 260 - (v1 - &Filename), L"\\procexp.chm");
  swprintf(&FileName, L"%s:Zone.Identifier", &Filename);
  DeleteFileW(&FileName);
  if ( !sub_F71149(a1, &Filename, 0, 0) )
  {
    SetLastError(0);
    ReportMsg(L"Unable to open help file", ghMainWnd);
  }
  return 0;
}
// 1041864: using guessed type wchar_t aUnableToOpenHe[25];

//----- (00FD0660) --------------------------------------------------------
int __cdecl Command_SearchOnline(HWND hWnd, __int16 a2)
{
  HWND v2; // esi
  HWND v3; // eax
  LRESULT v4; // eax
  const WCHAR *v5; // eax
  int v6; // esi
  LPARAM lParam; // [esp+4h] [ebp-34h]
  LRESULT v9; // [esp+8h] [ebp-30h]
  int v10; // [esp+Ch] [ebp-2Ch]
  int v11; // [esp+24h] [ebp-14h]

  lParam = 0;
  memset(&v9, 0, 0x30u);
  if ( a2 == -25424 )
  {
    v2 = ghWndDllsListCtrl;
  }
  else
  {
    v3 = GetFocus();
    v2 = ghWndTreeListView;
    if ( v3 == ghWndDllsListCtrl )
      v2 = ghWndDllsListCtrl;
  }
  v4 = SendMessageW(v2, 0x100Cu, 0xFFFFFFFF, 2);
  if ( v4 != -1 )
  {
    v9 = v4;
    v10 = 0;
    lParam = 4;
    if ( SendMessageW(v2, 0x104Bu, 0, &lParam) )
    {
      if ( v2 == ghWndTreeListView )
      {
        v5 = *(v11 + 60);
      }
      else
      {
        v6 = v11;
        if ( *(v11 + 44) & 8 )
        {
          MessageBoxW(
            ghWndTreeListView,
            L"Search not supported on pagefile-backed sections",
            L"Process Explorer Error",
            0x10u);
          return 0;
        }
        if ( wcsrchr(*(v11 + 344), 0x5Cu) )
          v5 = wcsrchr(*(v6 + 344), 0x5Cu) + 1;
        else
          v5 = *(v6 + 344);
      }
      LaunchWebBrowser(hWnd, 1, v5);
    }
  }
  return 0;
}

//----- (00FD0770) --------------------------------------------------------
int __cdecl Command_FindInProcess(HWND a1, __int16 nID)
{
  byte_105E104 = nID == 40062;
  if ( ghFindDlg )
  {
    ShowWindow(ghFindDlg, 5);
    SetFocus(ghFindDlg);
  }
  else
  {
    ghFindDlg = CreateDialogParamW(ghInstance, L"FINDDIALOG", ghMainWnd, DlgFind, ghFindDlg);
  }
  return 0;
}
// 105E104: using guessed type char byte_105E104;

//----- (00FD07D0) --------------------------------------------------------
int __cdecl Command_Cancel(HWND hWnd)
{
  int result; // eax

  if ( gbWindowFinding )
  {
    SearchWindow(hWnd);
    result = 0;
  }
  else
  {
    if ( gConfig.bHideWhenMinimized )
      CMainWnd::Hide(ghMainWnd);
    else
      CMainWnd::HandleDestroy(hWnd);
    result = 0;
  }
  return result;
}
// 106A38B: using guessed type char gbWindowFinding;

//----- (00FD0830) --------------------------------------------------------
int Options_ShowHiddenProcess()
{
  WCHAR **v0; // eax
  int v1; // esi
  WCHAR **v2; // ecx
  WCHAR **v3; // eax
  tagTREEVIEWLISTITEMPARAM *i; // eax
  HMENU v5; // eax

  v0 = gpHiddenProcesses;
  v1 = 0;
  if ( *gpHiddenProcesses )
  {
    v2 = gpHiddenProcesses;
    do
    {
      free(*v2);
      v0 = gpHiddenProcesses;
      v2 = &gpHiddenProcesses[++v1];
    }
    while ( *v2 );
  }
  free(v0);
  v3 = malloc(4u);
  gpHiddenProcesses = v3;
  *v3 = 0;
  for ( i = gpTreeViewListItemParam; i; i = i->m_Prev )
    i->dwStyle &= 0xFFFFFFFE;
  SaveHiddenProcessesToRegistry();
  v5 = GetMenu(ghMainWnd);
  EnableMenuItem(v5, 0x9C9Bu, 1u);
  SetEvent(ghTimerRefreshEvent);
  return 0;
}

//----- (00FD08C0) --------------------------------------------------------
int __cdecl Command_Font(HWND hWnd)
{
  sub_FB9980(hWnd);
  return 0;
}

//----- (00FD08E0) --------------------------------------------------------
int Command_OnProperties()
{
  HWND v0; // esi
  int nIndex; // eax
  tagLVITEMW ItemInfo; // [esp+4h] [ebp-34h]

  ItemInfo.mask = 0;
  memset(&ItemInfo.iItem, 0, 0x30u);
  v0 = ghWndTreeListView;
  nIndex = SendMessageW(ghWndTreeListView, LVM_GETNEXTITEM, 0xFFFFFFFF, LVFI_STRING);
  if ( nIndex != -1 )
  {
    ItemInfo.iItem = nIndex;
    ItemInfo.iSubItem = 0;
    ItemInfo.mask = LVIF_PARAM;
    if ( SendMessageW(v0, LVM_GETITEMW, 0, &ItemInfo) )
    {
      InterlockedIncrement(&ItemInfo.lParam->field_0);
      ItemInfo.lParam->dwProcessId = gdwProcessIdSelected;
      _beginthread(PropertiesThreadProc, 0, ItemInfo.lParam);
    }
  }
  return 0;
}

//----- (00FD0970) --------------------------------------------------------
int __cdecl sub_FD0970(int a1, __int16 a2)
{
  tagTREEVIEWLISTITEMPARAM *v2; // esi
  int FindInfoParam; // eax
  int v4; // ecx
  int v5; // eax
  unsigned int v6; // eax
  LRESULT v7; // eax
  tagLVITEMW ItemInfo2; // [esp+0h] [ebp-80h]
  tagLVITEMW ItemInfo; // [esp+34h] [ebp-4Ch]
  tagLVFINDINFOW FindInfo; // [esp+68h] [ebp-18h]

  if ( GetFocus() != ghWndTreeListView )
    return 0;
  ItemInfo.iItem = SendMessageW(ghWndTreeListView, LVM_GETNEXTITEM, 0xFFFFFFFF, 2);
  if ( ItemInfo.iItem != -1 )
  {
    ItemInfo.iSubItem = 0;
    ItemInfo.mask = 4;
    if ( SendMessageW(ghWndTreeListView, LVM_GETITEMW, 0, &ItemInfo) )
    {
      v2 = ItemInfo.lParam;
      if ( a2 == 40087 )
      {
        if ( ItemInfo.lParam->field_28 & 4 )
        {
          ItemInfo2.stateMask = 3;
          ++ItemInfo.iItem;
          ItemInfo2.state = 3;
          SendMessageW(ghWndTreeListView, LVM_SETITEMSTATE, ItemInfo.iItem, &ItemInfo2);
LABEL_20:
          v7 = SendMessageW(ghWndTreeListView, LVM_GETNEXTITEM, 0xFFFFFFFF, 2);
          SendMessageW(ghWndTreeListView, LVM_ENSUREVISIBLE, v7, 0);
          return 0;
        }
      }
      else if ( a2 == 40088 && !(ItemInfo.lParam->field_28 & 4) )
      {
        FindInfoParam = ItemInfo.lParam[1].field_0;
        if ( FindInfoParam )
        {
          while ( 1 )
          {
            v4 = *(FindInfoParam + 40);
            if ( v4 & 2 )
            {
              if ( !(v4 & 1) || !gConfig.byte_14012ADFE )
                break;
            }
            FindInfoParam = *(FindInfoParam + 84);
            if ( !FindInfoParam )
              goto LABEL_20;
          }
          FindInfo.lParam = FindInfoParam;
          FindInfo.flags = 1;
          ItemInfo.iItem = SendMessageW(ghWndTreeListView, LVM_FINDITEMW, 0xFFFFFFFF, &FindInfo);
          ItemInfo2.stateMask = 3;
          ItemInfo2.state = 3;
          SendMessageW(ghWndTreeListView, LVM_SETITEMSTATE, ItemInfo.iItem, &ItemInfo2);
        }
        goto LABEL_20;
      }
      v5 = ItemInfo.lParam->field_28;
      if ( v5 & 4 )
        v6 = v5 & 0xFFFFFFFB;
      else
        v6 = v5 | 4;
      ItemInfo.lParam->field_28 = v6;
      SendMessageW(ghWndTreeListView, TREELIST_MSG_2001, v2->field_5B8, (v6 >> 2) & 1);
      sub_FB8DA0(v2);
      goto LABEL_20;
    }
  }
  return 0;
}

//----- (00FD0B10) --------------------------------------------------------
int Command_OptionsToConfirmKill()
{
  signed int v0; // eax
  bool v1; // zf
  UINT v2; // ST08_4
  HMENU v3; // eax

  v0 = 0;
  v1 = gConfig.bConfirmKill != 0;
  gConfig.bConfirmKill = gConfig.bConfirmKill == 0;
  if ( !v1 )
    v0 = 8;
  v2 = v0;
  v3 = GetMenu(ghMainWnd);
  CheckMenuItem(v3, IDM_OPTIONS_CONFIRM_KILL, v2);
  UpdateWindowPlacement(ghMainWnd, 1);
  return 0;
}

//----- (00FD0B60) --------------------------------------------------------
int Command_ShowNewProcesses()
{
  signed int v0; // eax
  bool v1; // zf
  UINT v2; // ST08_4
  HMENU v3; // eax

  v0 = 0;
  v1 = gConfig.bFormatIoBytes != 0;
  gConfig.bFormatIoBytes = gConfig.bFormatIoBytes == 0;
  if ( !v1 )
    v0 = 8;
  v2 = v0;
  v3 = GetMenu(ghMainWnd);
  CheckMenuItem(v3, 0x9F25u, v2);
  UpdateWindowPlacement(ghMainWnd, 1);
  InvalidateRect(ghMainWnd, 0, 0);
  return 0;
}

//----- (00FD0BC0) --------------------------------------------------------
int Command_SaveHiddenProcesses()
{
  int v0; // eax
  tagTREEVIEWLISTITEMPARAM *v1; // esi
  tagTREEVIEWITEMPARAM *i; // edi
  int v3; // eax
  unsigned int v4; // eax
  int v5; // esi
  HMENU v6; // eax
  WCHAR **v8; // eax
  int v9; // ecx
  bool v10; // zf
  WCHAR **j; // ecx
  tagLVITEMW ItemInfo; // [esp+4h] [ebp-34h]

  ItemInfo.mask = 0;
  memset(&ItemInfo.iItem, 0, 0x30u);
  v0 = SendMessageW(ghWndTreeListView, LVM_GETNEXTITEM, 0xFFFFFFFF, 2);
  if ( v0 == -1 )
    return 0;
  ItemInfo.iItem = v0;
  ItemInfo.iSubItem = 0;
  ItemInfo.mask = LVIF_PARAM;
  if ( !SendMessageW(ghWndTreeListView, LVM_GETITEMW, 0, &ItemInfo) )
    return 0;
  v1 = gpTreeViewListItemParam;
  for ( i = ItemInfo.lParam; v1; v1 = v1->m_Prev )
  {
    if ( !_wcsicmp(v1->szProcessName2, i->field_3C) )
    {
      v3 = v1->dwStyle;
      if ( v3 & 1 )
        v4 = v3 & 0xFFFFFFFE;
      else
        v4 = v3 | 1;
      v1->dwStyle = v4;
    }
  }
  v5 = 0;
  if ( !(i->field_28 & 1) )
  {
    v8 = gpHiddenProcesses;
    if ( *gpHiddenProcesses )
    {
      v9 = 0;
      while ( 1 )
      {
        v10 = _wcsicmp(v8[v9], i->field_3C) == 0;
        v8 = gpHiddenProcesses;
        if ( v10 )
          break;
        v9 = ++v5;
        if ( !gpHiddenProcesses[v5] )
        {
          SaveHiddenProcessesToRegistry();
          return 0;
        }
      }
      free(gpHiddenProcesses[v5]);
      for ( j = &gpHiddenProcesses[v5]; gpHiddenProcesses[v5]; j = &gpHiddenProcesses[v5] )
      {
        ++v5;
        *j = j[1];
      }
    }
    SaveHiddenProcessesToRegistry();
    return 0;
  }
  if ( *gpHiddenProcesses )
  {
    do
      ++v5;
    while ( gpHiddenProcesses[v5] );
  }
  gpHiddenProcesses = realloc(gpHiddenProcesses, 4 * v5 + 8);
  gpHiddenProcesses[v5] = _wcsdup(i->field_3C);
  gpHiddenProcesses[v5 + 1] = 0;
  SetEvent(ghTimerRefreshEvent);
  v6 = GetMenu(ghMainWnd);
  EnableMenuItem(v6, IDM_VIEW_SHOW_HIDDEN_PROCESSES, 0);
  SaveHiddenProcessesToRegistry();
  return 0;
}

//----- (00FD0D80) --------------------------------------------------------
int __cdecl Command_DifferenceHiliteDuration(HWND hWndParent)
{
  DialogBoxParamW(ghInstance, L"DIFFDURATION", hWndParent, DialogFunc, 0);
  return 0;
}

//----- (00FD0DB0) --------------------------------------------------------
int Command_Save()
{
  sub_FFE3B0(0);
  return 0;
}

//----- (00FD0DC0) --------------------------------------------------------
int __cdecl Command_CpuHistory(HWND hWndParent)
{
  HWND v1; // esi
  LRESULT v2; // eax
  HANDLE v3; // eax
  void *v4; // esi
  LPARAM lParam; // [esp+4h] [ebp-34h]
  LRESULT v7; // [esp+8h] [ebp-30h]
  int v8; // [esp+Ch] [ebp-2Ch]
  int v9; // [esp+24h] [ebp-14h]

  lParam = 0;
  memset(&v7, 0, 0x30u);
  v1 = ghWndTreeListView;
  v2 = SendMessageW(ghWndTreeListView, 0x100Cu, 0xFFFFFFFF, 2);
  if ( v2 != -1 )
  {
    v7 = v2;
    v8 = 0;
    lParam = 4;
    if ( SendMessageW(v1, 0x104Bu, 0, &lParam) )
    {
      if ( v1 == ghWndTreeListView )
      {
        v3 = OpenProcess(0x600u, 0, *(v9 + 68));
        v4 = v3;
        if ( !v3 )
        {
          ReportMsg(L"Unable to set process affinity", ghMainWnd);
          return 0;
        }
        DialogBoxParamW(ghInstance, L"CPUAFFINITY", hWndParent, sub_FFEDC0, v3);
        CloseHandle(v4);
      }
    }
  }
  return 0;
}
// 104141C: using guessed type wchar_t aUnableToSetPro[31];

//----- (00FD0E90) --------------------------------------------------------
int Command_SaveAs()
{
  sub_FFE3B0(1);
  return 0;
}

//----- (00FD0EA0) --------------------------------------------------------
int Command_CloseHandle()
{
  HWND v0; // esi
  LRESULT v1; // eax
  _DWORD *v2; // esi
  LPARAM v4; // [esp+8h] [ebp-78h]
  int v5; // [esp+14h] [ebp-6Ch]
  int v6; // [esp+18h] [ebp-68h]
  LPARAM lParam; // [esp+3Ch] [ebp-44h]
  LRESULT v8; // [esp+40h] [ebp-40h]
  int v9; // [esp+44h] [ebp-3Ch]
  _DWORD *v10; // [esp+5Ch] [ebp-24h]
  int InBuffer; // [esp+70h] [ebp-10h]
  int v12; // [esp+74h] [ebp-Ch]
  int v13; // [esp+7Ch] [ebp-4h]

  lParam = 0;
  memset(&v8, 0, 0x30u);
  v0 = GetFocus();
  if ( v0 == ghWndDllsListCtrl )
    v0 = ghWndTreeListView;
  v1 = SendMessageW(v0, 0x100Cu, 0xFFFFFFFF, 2);
  if ( v1 == -1 )
  {
    if ( v0 == ghWndTreeListView )
    {
      MessageBoxW(ghWndTreeListView, L"No process selected", L"Process Explorer Error", 0x10u);
      return 0;
    }
    if ( v0 == ghWndHandlesListCtrl )
    {
      MessageBoxW(ghWndTreeListView, L"No handle selected", L"Process Explorer Error", 0x10u);
      return 0;
    }
    MessageBoxW(ghWndTreeListView, L"No handle or process selected", L"Process Explorer Error", 0x10u);
    return 0;
  }
  v8 = v1;
  v9 = 0;
  lParam = 4;
  if ( !SendMessageW(v0, 0x104Bu, 0, &lParam) )
    return 0;
  if ( v0 == ghWndTreeListView || v0 == ghWndDllsListCtrl )
  {
    if ( sub_FF8030(v10[15], v10[17]) )
    {
      SetEvent(ghRefreshEventHandle);
      v6 = 3;
      v5 = 3;
      SendMessageW(ghWndTreeListView, 0x102Bu, v8 - 1, &v4);
      return 0;
    }
    return 0;
  }
  if ( v0 != ghWndHandlesListCtrl )
    return 0;
  v2 = v10;
  if ( !IsBuiltinAdministrative() )
  {
    MessageBoxW(
      ghWndHandlesListCtrl,
      L"Closing handles requires administrative rights.",
      L"Process Explorer Error",
      0x10u);
    return 0;
  }
  if ( !v2[9] )
  {
    MessageBoxW(
      ghWndHandlesListCtrl,
      L"Handles in the Idle process cannot be closed.",
      L"Process Explorer Error",
      0x10u);
    return 0;
  }
  if ( gConfig.bConfirmKill
    && MessageBoxW(
         ghWndHandlesListCtrl,
         L"Forcing a handle closed can lead to an application crash and system instability.\nContinue with close?",
         L"Process Explorer Warning",
         0x34u) != 6 )
  {
    return 0;
  }
  v13 = v2[11];
  InBuffer = v2[9];
  v12 = v2[10];
  if ( CDriver::Control(0x83350004, &InBuffer, 0x10u, 0, 0) )
  {
    SetEvent(ghRefreshEventHandle);
    v6 = 3;
    v5 = 3;
    SendMessageW(ghWndHandlesListCtrl, LVM_SETITEMSTATE, v8 - 1, &v4);
    SetFocus(ghWndHandlesListCtrl);
  }
  else
  {
    ReportMsg(L"Error opening process", ghMainWnd);
  }
  return 0;
}
// 1042088: using guessed type wchar_t aErrorOpeningPr[22];

//----- (00FD10F0) --------------------------------------------------------
int Command_SuspendProcess()
{
  HWND v0; // esi
  LRESULT v1; // eax
  int v2; // esi
  int v3; // eax
  unsigned int v4; // eax
  const WCHAR *v5; // eax
  const WCHAR *v6; // ST10_4
  HMENU v7; // eax
  int result; // eax
  LPARAM lParam; // [esp+8h] [ebp-38h]
  WPARAM wParam; // [esp+Ch] [ebp-34h]
  int v11; // [esp+10h] [ebp-30h]
  int v12; // [esp+28h] [ebp-18h]
  char v13; // [esp+3Ch] [ebp-4h]

  lParam = 0;
  memset(&wParam, 0, 0x30u);
  v0 = ghWndTreeListView;
  v1 = SendMessageW(ghWndTreeListView, 0x100Cu, 0xFFFFFFFF, 2);
  if ( v1 != -1
    && (wParam = v1, v11 = 0, lParam = 4, SendMessageW(v0, 0x104Bu, 0, &lParam))
    && (v2 = v12, SetFocus(ghWndTreeListView), v2) )
  {
    if ( sub_FFF0A0(~(*(v2 + 40) >> 7) & 1, *(v2 + 68), &v13) )
    {
      ReportMsg(L"Unable to suspend the process", ghMainWnd);
    }
    else
    {
      v3 = *(v2 + 40);
      if ( (v3 & 0x80u) == 0 )
        v4 = v3 | 0x80;
      else
        v4 = v3 & 0xFFFFFF7F;
      *(v2 + 40) = v4;
    }
    SendMessageW(ghWndTreeListView, 0x1015u, wParam, wParam);
    v5 = L"R&esume";
    if ( *(v12 + 40) >= 0 )
      v5 = L"S&uspend";
    v6 = v5;
    v7 = GetMenu(ghMainWnd);
    ModifyMenuW(v7, 0x9C6Au, 0, 0x9C6Au, v6);
    result = 0;
  }
  else
  {
    MessageBoxW(ghWndTreeListView, L"No process is selected", L"Process Explorer Error", 0x10u);
    result = 0;
  }
  return result;
}
// 103E398: using guessed type wchar_t aREsume[8];
// 1042024: using guessed type wchar_t aUnableToSuspen[30];

//----- (00FD1230) --------------------------------------------------------
int __cdecl Command_ShowLowerPane(HWND a1)
{
  HMENU v1; // ebx
  UINT v2; // ecx
  bool v3; // zf
  HMENU v4; // eax
  HWND v6; // edi
  LRESULT v7; // eax
  const WCHAR *v8; // eax
  UINT_PTR v9; // eax
  LRESULT v10; // eax
  const WCHAR *v11; // [esp-4h] [ebp-24h]
  struct tagRECT Rect; // [esp+Ch] [ebp-14h]

  v1 = GetMenu(ghMainWnd);
  v2 = 0;
  v3 = gConfig.bShowLowerPane != 0;
  gConfig.bShowLowerPane = gConfig.bShowLowerPane == 0;
  if ( !v3 )
    v2 = 8;
  CheckMenuItem(v1, 0x9C6Eu, v2);
  SendMessageW(ghWndToolbar, 0x42Bu, 0x9C6Eu, (gConfig.bShowLowerPane != 0) + 9);
  InvalidateRect(ghWndToolbar, 0, 1);
  GetClientRect(ghMainWnd, &Rect);
  if ( gConfig.bShowLowerPane )
  {
    gConfig.dbDivider = gConfig.dbSavedDivider;
    CMainWnd::HandleSize(
      ghMainWnd,
      0,
      0,
      (LOWORD(Rect.right) - LOWORD(Rect.left)) | ((LOWORD(Rect.bottom) - LOWORD(Rect.top)) << 16));
    v6 = ghWndHandlesListCtrl;
    if ( gConfig.bShowDllView )
      v6 = ghWndDllsListCtrl;
    v7 = SendMessageW(ghWndTreeListView, 0x100Cu, 0xFFFFFFFF, 2);
    SendMessageW(ghWndTreeListView, 0x1013u, v7, 0);
    ShowWindow(v6, 5);
    if ( a1 )
      SetEvent(ghRefreshEventHandle);
    v8 = L"&DLL";
    if ( !gConfig.bShowDllView )
      v8 = L"H&andle";
    v11 = v8;
    v9 = ghHandleMenuPopup;
    if ( gConfig.bShowDllView )
      v9 = ghDllMenuPopup;
    InsertMenuW(v1, 5u, 0x410u, v9, v11);
    DrawMenuBar(ghMainWnd);
    v10 = SendMessageW(v6, 0x100Cu, 0xFFFFFFFF, 2);
    UpdateMenuStatus(v10 != -1, 5);
  }
  else if ( IsWindowVisible(ghWndHandlesListCtrl) || IsWindowVisible(ghWndDllsListCtrl) )
  {
    ShowWindow(ghWndHandlesListCtrl, 0);
    ShowWindow(ghWndDllsListCtrl, 0);
    v4 = GetMenu(ghMainWnd);
    RemoveMenu(v4, 5u, 0x400u);
    DrawMenuBar(ghMainWnd);
    gConfig.dbSavedDivider = gConfig.dbDivider;
    gConfig.dbDivider = db_one;
    CMainWnd::HandleSize(
      ghMainWnd,
      0,
      0,
      (LOWORD(Rect.right) - LOWORD(Rect.left)) | ((LOWORD(Rect.bottom) - LOWORD(Rect.top)) << 16));
    return 0;
  }
  return 0;
}

//----- (00FD1490) --------------------------------------------------------
int __cdecl OnProperties(HWND a1, __int16 a2)
{
  HWND v2; // esi
  int nItem; // eax
  tagTREEVIEWITEMPARAM *v4; // esi
  tagLVITEMW ItemInfo; // [esp+4h] [ebp-34h]

  ItemInfo.mask = 0;
  memset(&ItemInfo.iItem, 0, 0x30u);
  switch ( a2 )
  {
    case IDM_DLL_PROPERTIES:
      v2 = ghWndDllsListCtrl;
      break;
    case IDM_HANDLE_PROPERTIES:
      v2 = ghWndHandlesListCtrl;
      break;
    case IDM_PROCESS_PROPERTIES:
      v2 = ghWndTreeListView;
      break;
    default:
      v2 = GetFocus();
      break;
  }
  nItem = SendMessageW(v2, LVM_GETNEXTITEM, 0xFFFFFFFF, LVFI_STRING);
  if ( nItem == -1 )
  {
    if ( v2 == ghWndTreeListView )
    {
      MessageBoxW(ghWndTreeListView, L"No process is selected", L"Process Explorer Error", 0x10u);
      return 0;
    }
    if ( v2 == ghWndDllsListCtrl )
    {
      MessageBoxW(ghWndTreeListView, L"No DLL is selected", L"Process Explorer Error", 0x10u);
      return 0;
    }
    if ( v2 == ghWndHandlesListCtrl )
      MessageBoxW(ghWndTreeListView, L"No object is selected", L"Process Explorer Error", 0x10u);
    return 0;
  }
  ItemInfo.iItem = nItem;
  ItemInfo.iSubItem = 0;
  ItemInfo.mask = LVIF_PARAM;
  if ( !SendMessageW(v2, LVM_GETITEMW, 0, &ItemInfo) )
    return 0;
  if ( v2 == ghWndDllsListCtrl )
  {
    v4 = ItemInfo.lParam;
    if ( ItemInfo.lParam->field_2C & 8 )
    {
      MessageBoxW(
        ghWndTreeListView,
        L"Properties not supported on pagefile-backed sections",
        L"Process Explorer Error",
        0x10u);
      return 0;
    }
    if ( ItemInfo.lParam[4].field_8 )
    {
      InterlockedIncrement(&ItemInfo.lParam->field_0);
      v4->field_28 = gdwProcessIdSelected;
      _beginthread(PropertiesThreadProc, 0, v4);
      return 0;
    }
    return 0;
  }
  if ( v2 == ghWndHandlesListCtrl )
    FillHandleListParam(v2, ItemInfo.lParam);
  else
    CTreeList::FillTreeViewParam(ItemInfo.lParam);
  return 0;
}

//----- (00FD1620) --------------------------------------------------------
int __cdecl UpdateSpeedOptions_Update(HWND a1, UINT a2)
{
  signed int v2; // eax
  UINT v3; // ebx
  signed int v4; // eax
  HMENU v5; // eax
  HMENU v6; // eax
  UINT v8; // [esp-14h] [ebp-14h]

  v2 = gConfig.dwRefreshRate;
  if ( gdwRefreshMenuIDLast == -1 )
  {
    if ( gConfig.dwRefreshRate > 2000 )
    {
      if ( gConfig.dwRefreshRate == 5000 )
      {
        gdwRefreshMenuIDLast = IDM_VIEW_UPDATESPEED_FIVE_SECONDS;
      }
      else if ( gConfig.dwRefreshRate == 10000 )
      {
        gdwRefreshMenuIDLast = 40022;
      }
    }
    else if ( gConfig.dwRefreshRate == 2000 )
    {
      gdwRefreshMenuIDLast = 40019;
    }
    else if ( gConfig.dwRefreshRate )
    {
      if ( gConfig.dwRefreshRate == 500 )
      {
        gdwRefreshMenuIDLast = 40023;
      }
      else if ( gConfig.dwRefreshRate == 1000 )
      {
        gdwRefreshMenuIDLast = 40021;
      }
    }
    else
    {
      gdwRefreshMenuIDLast = 40018;
    }
  }
  LOWORD(v3) = a2;
  if ( a2 == -25518 && !gConfig.dwRefreshRate )
  {
    SendMessageW(ghWndStatusBar, 0x40Bu, gnStatusBarItemCount - 1, &gszNullString);
    v4 = gdwRefreshMenuIDLast;
    if ( gdwRefreshMenuIDLast == -1 )
      v4 = 1000;
    v3 = v4;
    gdwRefreshMenuIDLast = v4;
    v2 = gConfig.dwRefreshRate;
    a2 = v3;
  }
  if ( v2 > 2000 )
  {
    if ( v2 == 5000 )
    {
      v8 = 40020;
    }
    else
    {
      if ( v2 != 10000 )
        goto LABEL_34;
      v8 = 40022;
    }
  }
  else if ( v2 == 2000 )
  {
    v8 = 40019;
  }
  else if ( v2 )
  {
    if ( v2 == 500 )
    {
      v8 = 40023;
    }
    else
    {
      if ( v2 != 1000 )
        goto LABEL_34;
      v8 = 40021;
    }
  }
  else
  {
    v8 = 40018;
  }
  v5 = GetMenu(ghMainWnd);
  CheckMenuItem(v5, v8, 0);
LABEL_34:
  v3 = v3;
  switch ( v3 )
  {
    case 0x9C52u:
      gConfig.dwRefreshRate = 0;
      SendMessageW(ghWndStatusBar, 0x40Bu, gnStatusBarItemCount - 1, L"Paused");
      break;
    case 0x9C53u:
      gConfig.dwRefreshRate = 2000;
      break;
    case 0x9C54u:
      gConfig.dwRefreshRate = 5000;
      break;
    case 0x9C55u:
      gConfig.dwRefreshRate = 1000;
      break;
    case 0x9C56u:
      gConfig.dwRefreshRate = 10000;
      break;
    case 0x9C57u:
      gConfig.dwRefreshRate = 500;
      break;
    default:
      break;
  }
  v6 = GetMenu(ghMainWnd);
  CheckMenuItem(v6, v3, 8u);
  if ( a2 != -25518 )
  {
    SendMessageW(ghWndStatusBar, 0x40Bu, gnStatusBarItemCount - 1, &gszNullString);
    SetEvent(ghRefreshEventHandle);
    gdwRefreshMenuIDLast = v3;
  }
  return 0;
}
// 1040D80: using guessed type wchar_t aPaused[7];
// 105E10C: using guessed type int gdwRefreshMenuIDLast;
// 1085720: using guessed type int gnStatusBarItemCount;

//----- (00FD1850) --------------------------------------------------------
int OnProcessProperties()
{
  HWND hWndTreeListView; // [esp+0h] [ebp-2Ch]
  __int128 v2; // [esp+4h] [ebp-28h]
  __int128 v3; // [esp+14h] [ebp-18h]
  __int64 v4; // [esp+24h] [ebp-8h]

  hWndTreeListView = ghWndTreeListView;
  _mm_storeu_si128(&v2, 0i64);
  gConfig.bShowProcessTree = 0;
  gConfig.bProcessSortDirection = 0;
  _mm_storeu_si128(&v3, 0i64);
  LODWORD(v2) = 101;
  v4 = 0i64;
  HIDWORD(v2) = 0;
  sub_FBD040(101u, &hWndTreeListView);
  return 0;
}

//----- (00FD18A0) --------------------------------------------------------
int __usercall ProcessPriority_Update@<eax>(int a1@<edi>, HWND a2, __int16 a3)
{
  HWND v3; // esi
  LRESULT v4; // eax
  signed int v5; // ebx
  UINT v6; // esi
  signed int v7; // edi
  HANDLE v8; // eax
  DWORD v9; // ST0C_4
  void *v10; // edi
  HMENU v11; // eax
  int v13; // [esp-4h] [ebp-4Ch]
  int v14; // [esp+0h] [ebp-48h]
  LPARAM lParam; // [esp+8h] [ebp-40h]
  WPARAM wParam; // [esp+Ch] [ebp-3Ch]
  int v17; // [esp+10h] [ebp-38h]
  int v18; // [esp+28h] [ebp-20h]
  UINT v19; // [esp+3Ch] [ebp-Ch]
  int v20; // [esp+40h] [ebp-8h]
  int v21; // [esp+44h] [ebp-4h]

  lParam = 0;
  memset(&wParam, 0, 0x30u);
  v3 = ghWndTreeListView;
  v4 = SendMessageW(ghWndTreeListView, 0x100Cu, 0xFFFFFFFF, 2);
  if ( v4 == -1 )
  {
    if ( v3 == ghWndTreeListView )
      MessageBoxW(ghWndTreeListView, L"No process selected", L"Process Explorer Error", 0x10u);
    return 0;
  }
  wParam = v4;
  v17 = 0;
  lParam = 4;
  if ( !SendMessageW(v3, 0x104Bu, 0, &lParam) || v3 != ghWndTreeListView )
    return 0;
  v13 = a1;
  switch ( a3 )
  {
    case 0x9CBB:
      v5 = 4;
      v6 = 40123;
      v7 = 64;
      break;
    case 0x9CBC:
      v5 = 4;
      v6 = 40124;
      v7 = 64;
      break;
    case 0x9CBD:
      v5 = 6;
      v6 = 40125;
      v7 = 0x4000;
      break;
    case 0x9CBE:
      v5 = 8;
      v6 = 40126;
      v7 = 32;
      break;
    case 0x9CBF:
      v5 = 10;
      v6 = 40127;
      v7 = 0x8000;
      break;
    case 0x9CC0:
      v5 = 13;
      v6 = 40128;
      v7 = 128;
      break;
    case 0x9CC1:
      v5 = 24;
      v6 = 40129;
      v7 = 256;
      break;
    default:
      v5 = v19;
      v6 = v19;
      v7 = v19;
      break;
  }
  v8 = OpenProcess(0x200u, 0, *(v18 + 68));
  if ( v8 )
  {
    v9 = v7;
    v10 = v8;
    if ( SetPriorityClass(v8, v9) )
    {
      if ( v6 == 40124 )
      {
        v21 = 0;
        NtSetInformationProcess(v10, 33, &v21, 4, v13);
        v20 = 1;
      }
      else
      {
        v21 = 2;
        NtSetInformationProcess(v10, 33, &v21, 4, v13);
        v20 = 5;
      }
      NtSetInformationProcess(v10, 39, &v20, 4, v14);
      *(v18 + 1368) = v5;
      v11 = GetMenu(ghMainWnd);
      CheckMenuRadioItem(v11, 0x9CBBu, 0x9CC1u, v6, 0);
      SendMessageW(ghWndTreeListView, 0x1015u, wParam, wParam);
      goto LABEL_21;
    }
  }
  else
  {
    v10 = 0;
  }
  MessageBoxW(ghWndTreeListView, L"Unable to set process priority", L"Process Explorer Error", 0x10u);
LABEL_21:
  if ( v10 )
    CloseHandle(v10);
  return 0;
}
// FD18A0: could not find valid save-restore pair for edi
// 106B1C8: using guessed type int (__stdcall *NtSetInformationProcess)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD);

//----- (00FD1AD0) --------------------------------------------------------
int Options_AllowOneInstance()
{
  signed int v0; // eax
  bool v1; // zf
  UINT v2; // ST08_4
  HMENU v3; // eax

  v0 = 0;
  v1 = gConfig.bAllOneInstance != 0;
  gConfig.bAllOneInstance = gConfig.bAllOneInstance == 0;
  if ( !v1 )
    v0 = 8;
  v2 = v0;
  v3 = GetMenu(ghMainWnd);
  CheckMenuItem(v3, IDM_OPTIONS_ALLOW_ONLY_ONE_INSTANCE, v2);
  UpdateWindowPlacement(ghMainWnd, 1);
  return 0;
}

//----- (00FD1B20) --------------------------------------------------------
int __cdecl Command_Run(HWND hWndParent, int a2)
{
  HMODULE v2; // eax
  FARPROC v3; // eax

  v2 = LoadLibraryW(L"shell32.dll");
  v3 = GetProcAddress(v2, 0x3D);
  dword_106A8D8 = v3;
  if ( v3 )
    (v3)(hWndParent, 0, 0, 0, 0, 0);
  else
    DialogBoxParamW(ghInstance, L"RUNDLG", hWndParent, sub_FD7F60, a2);
  return 0;
}
// 106A8D8: using guessed type int dword_106A8D8;

//----- (00FD1B80) --------------------------------------------------------
int __cdecl Command_RunAs(HWND hWndParent, int a2)
{
  DialogBoxParamW(ghInstance, L"RUNDLG", hWndParent, sub_FD7F60, a2);
  return 0;
}

//----- (00FD1BB0) --------------------------------------------------------
int __cdecl Options_HideWhenMinimized(HWND hWnd)
{
  signed int v1; // eax
  bool v2; // zf
  UINT v3; // ST0C_4
  HMENU v4; // eax

  v1 = 0;
  v2 = gConfig.bHideWhenMinimized != 0;
  gConfig.bHideWhenMinimized = gConfig.bHideWhenMinimized == 0;
  if ( !v2 )
    v1 = 8;
  v3 = v1;
  v4 = GetMenu(hWnd);
  CheckMenuItem(v4, 0x9C75u, v3);
  if ( gConfig.bHideWhenMinimized
    && !gConfig.bTrayCPUHistory
    && !gConfig.bShowCommitTray
    && !gConfig.bShowPhysTray
    && !gConfig.bShowIoTray )
  {
    Command_ViewCpuHistory(hWnd);
  }
  UpdateWindowPlacement(ghMainWnd, 1);
  return 0;
}

//----- (00FD1C40) --------------------------------------------------------
int __cdecl OpacityOptions_Update(HWND hWnd, int a2)
{
  UINT v2; // ST08_4
  HMENU v3; // eax
  LONG v4; // eax
  UINT v5; // ST08_4
  HMENU v6; // eax

  v2 = (((1717986919i64 * gConfig.dwOpacity) >> 32) >> 2) + (((1717986919i64 * gConfig.dwOpacity) >> 32) >> 31) + 40093;
  v3 = GetMenu(hWnd);
  CheckMenuItem(v3, v2, 0);
  gConfig.dwOpacity = 10 * (a2 - 40093);
  v4 = GetWindowLongW(ghMainWnd, -20);
  if ( gConfig.dwOpacity == 100 )
  {
    SetWindowLongW(ghMainWnd, -20, v4 & 0xFFF7FFFF);
  }
  else
  {
    SetWindowLongW(ghMainWnd, -20, v4 | 0x80000);
    SetLayeredWindowAttributes(ghMainWnd, 0, (255 * gConfig.dwOpacity) / 100, 2u);
  }
  RedrawWindow(ghMainWnd, 0, 0, 0x485u);
  v5 = (((1717986919i64 * gConfig.dwOpacity) >> 32) >> 2) + (((1717986919i64 * gConfig.dwOpacity) >> 32) >> 31) + 40093;
  v6 = GetMenu(hWnd);
  CheckMenuItem(v6, v5, 8u);
  return 0;
}

//----- (00FD1D40) --------------------------------------------------------
int __cdecl UserAccount_Refresh(HWND a1, __int16 a2)
{
  char v2; // al
  char v4; // [esp+7h] [ebp-405h]
  WCHAR Text; // [esp+8h] [ebp-404h]
  wchar_t Dst; // [esp+208h] [ebp-204h]

  switch ( a2 )
  {
    case 0x9C84:
      wcscpy_s(&Dst, 0x100u, L"logoff");
      break;
    case 0x9C85:
      wcscpy_s(&Dst, 0x100u, L"shutdown");
      break;
    case 0x9C86:
      wcscpy_s(&Dst, 0x100u, L"restart");
      break;
    case 0x9C87:
      wcscpy_s(&Dst, 0x100u, L"hibernate");
      break;
    case 0x9C88:
      wcscpy_s(&Dst, 0x100u, L"stand by");
      break;
    case 0x9C92:
      wcscpy_s(&Dst, 0x100u, L"lock the computer");
      break;
    default:
      break;
  }
  wsprintf(&Text, L"Do you really want to %s?", &Dst);
  if ( MessageBoxW(ghWndTreeListView, &Text, L"Process Explorer Shutdown", 0x24u) != 7 )
  {
    UpdateWindowPlacement(ghMainWnd, 1);
    TmAdjustPrivilege(L"SeShutdownPrivilege");
    switch ( a2 )
    {
      case 0:
        v2 = ExitWindowsEx(0, 0);
        break;
      case 1:
        if ( ExitWindowsEx(8u, 0) )
          return 0;
        v2 = ExitWindowsEx(1u, 0);
        break;
      case 2:
        v2 = ExitWindowsEx(2u, 0);
        break;
      case 3:
        v2 = SetSuspendState(1u, 1u, 0);
        break;
      case 4:
        v2 = SetSuspendState(0, 1u, 0);
        break;
      case 0xE:
        v2 = LockWorkStation();
        break;
      default:
        v2 = v4;
        break;
    }
    if ( !v2 )
    {
      wsprintf(&Text, L"Error trying to %s", &Dst);
      ReportMsg(&Text, ghMainWnd);
    }
  }
  return 0;
}
// 1041C74: using guessed type wchar_t aShutdown[9];
// 1041C88: using guessed type wchar_t aRestart[8];
// 1041C98: using guessed type wchar_t aLogoff[7];
// 1041CA8: using guessed type wchar_t aHibernate[10];
// 1041CBC: using guessed type wchar_t aStandBy[9];

//----- (00FD1F10) --------------------------------------------------------
int __cdecl Command_ReplaceTaskManager(HWND hWnd)
{
  HKEY v1; // ecx
  UINT v2; // ST08_4
  HMENU v3; // eax

  if ( gdwVersion < 1 || IsBuiltinAdministrative() )
  {
    if ( CanReplaceTaskManager() )
      sub_FC5E40(v1);
    else
      ReplaceTaskManager(hWnd, 1);
  }
  else
  {
    sub_FC6180(L"/rt", 5, 1);
  }
  v2 = CanReplaceTaskManager() != 0 ? 8 : 0;
  v3 = GetMenu(hWnd);
  CheckMenuItem(v3, 0x9C7Bu, v2);
  return 0;
}
// 10416AC: using guessed type wchar_t aRt_0[4];
// 1064E54: using guessed type int gdwVersion;

//----- (00FD1F80) --------------------------------------------------------
int __cdecl Command_ConfigSymbols(HWND hWndParent)
{
  DialogBoxParamW(ghInstance, L"SYMBOLCONFIG", hWndParent, DlgSymbolConfig, 0);
  return 0;
}

//----- (00FD1FB0) --------------------------------------------------------
int Command_SystemInformation()
{
  HCURSOR v1; // eax
  HCURSOR v2; // esi

  if ( ghWndSysinfoPropSheet )
  {
    ShowWindow(ghWndSysinfoPropSheet, SW_RESTORE);
    SetFocus(ghWndSysinfoPropSheet);
    SetForegroundWindow(ghWndSysinfoPropSheet);
  }
  else
  {
    v1 = LoadCursorW(0, IDC_WAIT);
    v2 = SetCursor(v1);
    _beginthread(BackendSysInfoPropSheetThreadProc, 0, 0);
    WaitForSingleObject(ghSystemInfoSheetThreadEvent, 0xFFFFFFFF);
    SetCursor(v2);
  }
  return 0;
}

//----- (00FD2020) --------------------------------------------------------
int __cdecl Command_ConfirmToKillProcess(HWND hWnd)
{
  signed int v1; // eax
  bool v2; // zf
  UINT v3; // ST08_4
  HMENU v4; // eax

  v1 = 0;
  v2 = gConfig.bShowCpuFractions != 0;
  gConfig.bShowCpuFractions = gConfig.bShowCpuFractions == 0;
  if ( !v2 )
    v1 = 8;
  v3 = v1;
  v4 = GetMenu(hWnd);
  CheckMenuItem(v4, 0x9C6Du, v3);
  InvalidateRgn(ghWndTreeListView, 0, 1);
  return 0;
}

//----- (00FD2070) --------------------------------------------------------
int __cdecl Command_ConfigColors(HWND hWndParent)
{
  DialogBoxParamW(ghInstance, L"CHOOSECOLORS", hWndParent, DlgSelectColor, 0);
  return 0;
}

//----- (00FD20A0) --------------------------------------------------------
int Process_CleanMemory()
{
  HWND ghWndTreeListView; // esi
  int nCurItem; // eax
  HANDLE ProcessHandle; // eax
  void *v3; // esi
  LVITEMW Item; // [esp+4h] [ebp-34h]

  Item.mask = 0;
  memset(&Item.iItem, 0, 0x30u);
  ghWndTreeListView = ::ghWndTreeListView;
  nCurItem = SendMessageW(::ghWndTreeListView, 0x100Cu, 0xFFFFFFFF, 2);
  if ( nCurItem == -1 )
  {
    if ( ghWndTreeListView == ::ghWndTreeListView )
      MessageBoxW(::ghWndTreeListView, L"No process selected", L"Process Explorer Error", MB_ICONSTOP);
  }
  else
  {
    Item.iItem = nCurItem;
    Item.iSubItem = 0;
    Item.mask = LVIF_PARAM;
    if ( SendMessageW(ghWndTreeListView, LVM_GETITEMW, 0, &Item) )
    {
      ProcessHandle = OpenProcess(0x100u, 0, Item.lParam->dwProcessId);
      v3 = ProcessHandle;
      // If both dwMinimumWorkingSetSize and dwMaximumWorkingSetSize have the value (SIZE_T)â€?, the function removes as many pages as possible from the working set of the specified process.
      if ( ProcessHandle && SetProcessWorkingSetSize(ProcessHandle, 0xFFFFFFFF, 0xFFFFFFFF) )
        SetEvent(ghRefreshEventHandle);
      else
        ReportMsg(L"Unable to trim process working set", ghMainWnd);
      if ( v3 )
      {
        CloseHandle(v3);
        return 0;
      }
    }
  }
  return 0;
}
// 10425B8: using guessed type wchar_t aUnableToTrimPr[35];

//----- (00FD2190) --------------------------------------------------------
int __cdecl WindowOptions_Refresh(HWND a1, int a2)
{
  HWND v2; // esi
  LRESULT v3; // eax
  tagTREEVIEWLISTITEMPARAM *v4; // esi
  LPARAM lParam; // [esp+4h] [ebp-34h]
  LRESULT v7; // [esp+8h] [ebp-30h]
  int v8; // [esp+Ch] [ebp-2Ch]
  tagTREEVIEWLISTITEMPARAM *pItem; // [esp+24h] [ebp-14h]

  lParam = 0;
  memset(&v7, 0, 0x30u);
  v2 = ghWndTreeListView;
  v3 = SendMessageW(ghWndTreeListView, 0x100Cu, 0xFFFFFFFF, 2);
  if ( v3 != -1 )
  {
    v7 = v3;
    v8 = 0;
    lParam = 4;
    if ( SendMessageW(v2, 0x104Bu, 0, &lParam) )
    {
      v4 = pItem;
      sub_FC6B90(0, a2, pItem->dwProcessId);
      RefreshMenuWithTreeViewItemStatus(v4);
    }
  }
  return 0;
}

//----- (00FD2210) --------------------------------------------------------
int Command_ShowColumnHeatmaps()
{
  signed int v0; // eax
  bool v1; // zf
  UINT v2; // ST08_4
  HMENU v3; // eax

  v0 = 0;
  v1 = gConfig.bShowColumnHeatmaps != 0;
  gConfig.bShowColumnHeatmaps = gConfig.bShowColumnHeatmaps == 0;
  if ( !v1 )
    v0 = 8;
  v2 = v0;
  v3 = GetMenu(ghMainWnd);
  CheckMenuItem(v3, 0x9C99u, v2);
  SetEvent(ghTimerRefreshEvent);
  return 0;
}

//----- (00FD2260) --------------------------------------------------------
int __cdecl Command_VerifyImage(HWND hWnd)
{
  signed int v1; // eax
  bool v2; // zf
  UINT v3; // ST24_4
  HMENU v4; // eax
  int v5; // edi
  tagTREEVIEWITEMPARAM *v6; // esi
  tagLVITEMW ItemInfo; // [esp+0h] [ebp-34h]

  ItemInfo.mask = 0;
  memset(&ItemInfo.iItem, 0, 0x30u);
  v1 = 0;
  v2 = gConfig.bVerifySignatures != 0;
  gConfig.bVerifySignatures = gConfig.bVerifySignatures == 0;
  if ( !v2 )
    v1 = 8;
  v3 = v1;
  v4 = GetMenu(hWnd);
  CheckMenuItem(v4, IDM_OPTIONS_VERIFY_IMAGE_SIGNATURE, v3);
  if ( !gConfig.bVerifySignatures )
    return 0;
  TreeView_InsertVerifyColumn(
    ghWndTreeListView,
    IDS_VERIFIED_SIGNER,
    gConfig.dwProcessColumnMap,
    &gConfig.dwProcessColumnCount);
  TreeView_InsertVerifyColumn(ghWndDllsListCtrl, IDS_VERIFIED_SIGNER, gConfig.dwDllColumnMap, &gConfig.dwDllColumnCount);
  v5 = SendMessageW(ghWndTreeListView, LVM_GETITEMCOUNT, 0, 0);
  ItemInfo.iItem = 0;
  if ( v5 <= 0 )
    return 0;
  do
  {
    ItemInfo.iSubItem = 0;
    ItemInfo.mask = LVIF_PARAM;
    if ( SendMessageW(ghWndTreeListView, LVM_GETITEMW, 0, &ItemInfo) )
    {
      v6 = ItemInfo.lParam;
      InterlockedIncrement(&ItemInfo.lParam->field_24);
      _beginthread(VerifyImageThreadProc, 0, v6);
    }
    ++ItemInfo.iItem;
  }
  while ( ItemInfo.iItem < v5 );
  return 0;
}

//----- (00FD2390) --------------------------------------------------------
int __cdecl Command_CheckVirusTotalDotCom(HWND hWnd)
{
  signed int v1; // eax
  UINT v2; // ST0C_4
  HMENU v3; // eax
  BOOL v4; // ST0C_4
  HMENU v5; // eax
  DLLLISTITEMPARAM *v6; // esi
  DLLLISTITEMPARAM *v7; // edi
  int v8; // eax
  DLLLISTITEMPARAM *i; // esi
  int v10; // eax

  if ( !SubmitExeToVirusTotalDotCom() )
    return 0;
  v1 = 0;
  gConfig.bCheckVirusTotal = gConfig.bCheckVirusTotal == 0;
  if ( gConfig.bCheckVirusTotal )
    v1 = 8;
  v2 = v1;
  v3 = GetMenu(hWnd);
  CheckMenuItem(v3, 0x9CB3u, v2);
  v4 = gConfig.bCheckVirusTotal == 0;
  v5 = GetMenu(hWnd);
  EnableMenuItem(v5, 0x9F36u, v4);
  if ( gConfig.bCheckVirusTotal )
  {
    v6 = gpTreeViewListItemParam;
    v7 = 0;
    TreeView_InsertVerifyColumn(ghWndTreeListView, 0x686u, gConfig.dwProcessColumnMap, &gConfig.dwProcessColumnCount);
    for ( ; v6; v6 = v6[3].field_118 )
    {
      v8 = v6[2].field_3C;
      if ( v6->field_44 == gdwProcessIdSelected )
        v7 = v6;
      if ( v8 && *(v8 + 4) == 1 )
        *(v8 + 4) = 6;
      if ( v6[2].field_8 )
        sub_1001C30(v6, 1, 0);
    }
    InvalidateRect(ghWndTreeListView, 0, 0);
    TreeView_InsertVerifyColumn(ghWndDllsListCtrl, 0x686u, gConfig.dwDllColumnMap, &gConfig.dwDllColumnCount);
    if ( v7 && IsWindowVisible(ghWndDllsListCtrl) )
    {
      for ( i = gpDllListItemParamHeader; i; i = i->m_Prev )
      {
        v10 = i->m_HashData;
        if ( v10 && *(v10 + 4) == 1 )
          *(v10 + 4) = 6;
        if ( i->m_strPath.pszData )
          sub_1001C30(i, ~(i->field_2C >> 1) & 1, 0);
      }
      InvalidateRect(ghWndDllsListCtrl, 0, 0);
    }
  }
  return 0;
}

//----- (00FD2520) --------------------------------------------------------
int __cdecl Command_SubmitUnkownExecutables(HWND hWnd)
{
  signed int v1; // eax
  bool v2; // zf
  UINT v3; // ST10_4
  HMENU v4; // eax
  DLLLISTITEMPARAM *v5; // esi
  DLLLISTITEMPARAM *v6; // edi
  int v7; // eax
  DLLLISTITEMPARAM *i; // esi
  int v9; // eax
  unsigned int v10; // eax

  if ( !SubmitExeToVirusTotalDotCom() )
    return 0;
  v1 = 0;
  v2 = gConfig.bVirusTotalSubmitUnknown != 0;
  gConfig.bVirusTotalSubmitUnknown = gConfig.bVirusTotalSubmitUnknown == 0;
  if ( !v2 )
    v1 = 8;
  v3 = v1;
  v4 = GetMenu(hWnd);
  CheckMenuItem(v4, 0x9F36u, v3);
  if ( !gConfig.bVirusTotalSubmitUnknown )
    return 0;
  v5 = gpTreeViewListItemParam;
  v6 = 0;
  if ( gpTreeViewListItemParam )
  {
    do
    {
      v7 = v5[2].field_3C;
      if ( v5->field_44 == gdwProcessIdSelected )
        v6 = v5;
      if ( v7 && *(v7 + 4) == 6 && *v7 )
        sub_1001C30(v5, 1, 1);
      v5 = v5[3].field_118;
    }
    while ( v5 );
  }
  InvalidateRect(ghWndTreeListView, 0, 0);
  if ( v6 && IsWindowVisible(ghWndDllsListCtrl) )
  {
    for ( i = gpDllListItemParamHeader; i; i = i->m_Prev )
    {
      v9 = i->m_HashData;
      if ( v9 && *(v9 + 4) == 6 )
      {
        v10 = i->field_2C >> 1;
        if ( !(v10 & 1) )
          sub_1001C30(i, ~v10 & 1, 1);
      }
    }
    InvalidateRect(ghWndDllsListCtrl, 0, 0);
  }
  return 0;
}

//----- (00FD2640) --------------------------------------------------------
int Command_CheckVirusTotalDotCom()
{
  HWND v0; // esi
  char v1; // bl
  LRESULT v2; // eax
  DLLLISTITEMPARAM *v3; // esi
  int v4; // eax
  LPARAM lParam; // [esp+8h] [ebp-34h]
  LRESULT v7; // [esp+Ch] [ebp-30h]
  int v8; // [esp+10h] [ebp-2Ch]
  DLLLISTITEMPARAM *pItemParam; // [esp+28h] [ebp-14h]

  lParam = 0;
  memset(&v7, 0, 0x30u);
  v0 = ghWndTreeListView;
  v1 = 0;
  v2 = SendMessageW(ghWndTreeListView, 0x100Cu, 0xFFFFFFFF, 2);
  if ( v2 != -1 )
  {
    v7 = v2;
    v8 = 0;
    lParam = 4;
    if ( SendMessageW(v0, 0x104Bu, 0, &lParam) )
    {
      v3 = pItemParam;
      SetFocus(ghWndTreeListView);
      if ( v3 )
      {
        if ( SubmitExeToVirusTotalDotCom() )
        {
          TreeView_InsertVerifyColumn(
            ghWndTreeListView,
            0x686u,
            gConfig.dwProcessColumnMap,
            &gConfig.dwProcessColumnCount);
          v4 = v3[2].field_3C;
          if ( v4 )
          {
            if ( *(v4 + 4) == 6 )
            {
              v1 = 1;
            }
            else if ( v4 && *(v4 + 4) == 1 )
            {
              *(v4 + 4) = 6;
            }
          }
          sub_1001C30(v3, 1, v1 != 0);
          InvalidateRect(ghWndTreeListView, 0, 0);
        }
      }
    }
  }
  return 0;
}

//----- (00FD2740) --------------------------------------------------------
int Command_Check_VirusTotalDotCom()
{
  HWND v0; // esi
  char v1; // bl
  LRESULT v2; // eax
  DLLLISTITEMPARAM *v3; // esi
  int v4; // eax
  LPARAM lParam; // [esp+8h] [ebp-34h]
  LRESULT v7; // [esp+Ch] [ebp-30h]
  int v8; // [esp+10h] [ebp-2Ch]
  DLLLISTITEMPARAM *pItemParam; // [esp+28h] [ebp-14h]

  lParam = 0;
  memset(&v7, 0, 0x30u);
  v0 = ghWndDllsListCtrl;
  v1 = 0;
  v2 = SendMessageW(ghWndDllsListCtrl, 0x100Cu, 0xFFFFFFFF, 2);
  if ( v2 != -1 )
  {
    v7 = v2;
    v8 = 0;
    lParam = 4;
    if ( SendMessageW(v0, 0x104Bu, 0, &lParam) )
    {
      v3 = pItemParam;
      SetFocus(ghWndTreeListView);
      if ( v3 )
      {
        if ( SubmitExeToVirusTotalDotCom() )
        {
          TreeView_InsertVerifyColumn(ghWndDllsListCtrl, 0x686u, gConfig.dwDllColumnMap, &gConfig.dwDllColumnCount);
          v4 = v3->m_HashData;
          if ( v4 )
          {
            if ( *(v4 + 4) == 6 )
            {
              v1 = 1;
            }
            else if ( v4 && *(v4 + 4) == 1 )
            {
              *(v4 + 4) = 6;
            }
          }
          sub_1001C30(v3, 1, v1 != 0);
          InvalidateRect(ghWndDllsListCtrl, 0, 0);
        }
      }
    }
  }
  return 0;
}

//----- (00FD2840) --------------------------------------------------------
int Command_ShowDetailsForAllProcesses()
{
  DWORD v0; // eax

  UpdateWindowPlacement(ghMainWnd, 1);
  CreateEventW(0, 0, 1, L"ProcessExplorerElevating");
  v0 = sub_FC6180(gszCmdLine, 5, 0);
  if ( v0 )
  {
    if ( v0 != 1223 )
    {
      ReportMsg(L"Error elevating", ghMainWnd);
      return 0;
    }
  }
  else
  {
    DestroyWindow(ghMainWnd);
  }
  return 0;
}
// 1041D84: using guessed type wchar_t aErrorElevating[16];
// 106A38C: using guessed type int gszCmdLine;

//----- (00FD28B0) --------------------------------------------------------
int __cdecl Command_SetTopmost(HWND hWnd)
{
  signed int v1; // eax
  UINT v2; // ST18_4
  HMENU v3; // eax

  v1 = 0;
  gConfig.bAlwaysOntop = gConfig.bAlwaysOntop == 0;
  if ( gConfig.bAlwaysOntop )
    v1 = 8;
  v2 = v1;
  v3 = GetMenu(hWnd);
  CheckMenuItem(v3, 0x9C82u, v2);
  if ( gConfig.bAlwaysOntop )
  {
    SetWindowPos(hWnd, HWND_MESSAGE|0x2, 0, 0, 0, 0, SWP_NOMOVE|SWP_NOSIZE);
    if ( ghWndSysinfoPropSheet )
    {
      SetWindowPos(ghWndSysinfoPropSheet, HWND_MESSAGE|0x2, 0, 0, 0, 0, SWP_NOMOVE|SWP_NOSIZE);
      return 0;
    }
  }
  else
  {
    if ( ghWndSysinfoPropSheet )
      SetWindowPos(ghWndSysinfoPropSheet, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE|SWP_NOSIZE);
    SetWindowPos(hWnd, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE|SWP_NOSIZE);
  }
  return 0;
}

//----- (00FD2960) --------------------------------------------------------
int __cdecl Command_ViewCpuHistory(HWND hWnd)
{
  signed int v1; // eax
  UINT v2; // ST08_4
  HMENU v3; // eax

  if ( !sub_FD79E0(gConfig.bTrayCPUHistory == 0) )
  {
    v1 = 0;
    gConfig.bTrayCPUHistory = gConfig.bTrayCPUHistory == 0;
    if ( gConfig.bTrayCPUHistory )
      v1 = 8;
    v2 = v1;
    v3 = GetMenu(hWnd);
    CheckMenuItem(v3, 0x9EC4u, v2);
    HandleTaskbarCreated();
  }
  return 0;
}

//----- (00FD29C0) --------------------------------------------------------
int __cdecl Command_ViewIoHistory(HWND hWnd)
{
  signed int v1; // eax
  UINT v2; // ST08_4
  HMENU v3; // eax

  if ( !sub_FD79E0(gConfig.bShowIoTray == 0) )
  {
    v1 = 0;
    gConfig.bShowIoTray = gConfig.bShowIoTray == 0;
    if ( gConfig.bShowIoTray )
      v1 = 8;
    v2 = v1;
    v3 = GetMenu(hWnd);
    CheckMenuItem(v3, 0x9F0Fu, v2);
    HandleTaskbarCreated();
  }
  return 0;
}

//----- (00FD2A20) --------------------------------------------------------
int __cdecl Command_CommitNetworkHistory(HWND hWnd)
{
  signed int v1; // eax
  UINT v2; // ST08_4
  HMENU v3; // eax

  if ( !sub_FD79E0(gConfig.bShowNetTray == 0) )
  {
    v1 = 0;
    gConfig.bShowNetTray = gConfig.bShowNetTray == 0;
    if ( gConfig.bShowNetTray )
      v1 = 8;
    v2 = v1;
    v3 = GetMenu(hWnd);
    CheckMenuItem(v3, 0x9F2Bu, v2);
    HandleTaskbarCreated();
  }
  return 0;
}

//----- (00FD2A80) --------------------------------------------------------
int __cdecl Command_CommitDiskHistory(HWND hWnd)
{
  signed int v1; // eax
  UINT v2; // ST08_4
  HMENU v3; // eax

  if ( !sub_FD79E0(gConfig.bShowDiskTray == 0) )
  {
    v1 = 0;
    gConfig.bShowDiskTray = gConfig.bShowDiskTray == 0;
    if ( gConfig.bShowDiskTray )
      v1 = 8;
    v2 = v1;
    v3 = GetMenu(hWnd);
    CheckMenuItem(v3, 0x9F2Au, v2);
    HandleTaskbarCreated();
  }
  return 0;
}

//----- (00FD2AE0) --------------------------------------------------------
int __cdecl Command_CommitGPUHistory(HWND hWnd)
{
  signed int v1; // eax
  UINT v2; // ST08_4
  HMENU v3; // eax

  if ( !sub_FD79E0(gConfig.bShowGpuHistory == 0) )
  {
    v1 = 0;
    gConfig.bShowGpuHistory = gConfig.bShowGpuHistory == 0;
    if ( gConfig.bShowGpuHistory )
      v1 = 8;
    v2 = v1;
    v3 = GetMenu(hWnd);
    CheckMenuItem(v3, 0x9F2Cu, v2);
    HandleTaskbarCreated();
  }
  return 0;
}

//----- (00FD2B40) --------------------------------------------------------
int __usercall Command_RunAtLogon@<eax>(_DWORD *a1@<edi>, HWND hWnd)
{
  bool v2; // al
  UINT v3; // ST08_4
  HMENU v4; // eax
  int savedregs; // [esp+0h] [ebp+0h]

  v2 = IsProcessExplorerRunAtStartup(&savedregs, a1);
  sub_FC37F0(v2 == 0);
  v3 = IsProcessExplorerRunAtStartup(&savedregs, a1) != 0 ? 8 : 0;
  v4 = GetMenu(hWnd);
  CheckMenuItem(v4, 0x9F30u, v3);
  return 0;
}

//----- (00FD2B90) --------------------------------------------------------
int __cdecl Command_ViewCommitHistory(HWND hWnd)
{
  signed int v1; // eax
  UINT v2; // ST08_4
  HMENU v3; // eax

  if ( !sub_FD79E0(gConfig.bShowCommitTray == 0) )
  {
    v1 = 0;
    gConfig.bShowCommitTray = gConfig.bShowCommitTray == 0;
    if ( gConfig.bShowCommitTray )
      v1 = 8;
    v2 = v1;
    v3 = GetMenu(hWnd);
    CheckMenuItem(v3, 0x9F16u, v2);
    HandleTaskbarCreated();
  }
  return 0;
}

//----- (00FD2BF0) --------------------------------------------------------
int __cdecl Command_ViewPhysicalMemoryHistory(HWND hWnd)
{
  signed int v1; // eax
  UINT v2; // ST08_4
  HMENU v3; // eax

  if ( !sub_FD79E0(gConfig.bShowPhysTray == 0) )
  {
    v1 = 0;
    gConfig.bShowPhysTray = gConfig.bShowPhysTray == 0;
    if ( gConfig.bShowPhysTray )
      v1 = 8;
    v2 = v1;
    v3 = GetMenu(hWnd);
    CheckMenuItem(v3, 0x9F17u, v2);
    HandleTaskbarCreated();
  }
  return 0;
}

//----- (00FD2C50) --------------------------------------------------------
signed int __usercall Command_SetColumn@<eax>(double a1@<st0>, double a2@<st1>, HWND hWnd, unsigned __int16 uID)
{
  __int32 index; // esi
  BOOL v6; // ST2C_4
  HMENU v7; // eax
  LRESULT v8; // eax
  char v9; // [esp+0h] [ebp-A0h]
  char v10; // [esp+8h] [ebp-98h]
  int pThis; // [esp+10h] [ebp-90h]
  __int128 v12; // [esp+14h] [ebp-8Ch]
  __int128 v13; // [esp+24h] [ebp-7Ch]
  __int64 v14; // [esp+34h] [ebp-6Ch]
  char v15; // [esp+3Ch] [ebp-64h]
  struct tagRECT Rect; // [esp+8Ch] [ebp-14h]

  index = uID - IDM_PROCESS_PRIORITY_BASE;
  pThis = 0;
  _mm_storeu_si128(&v12, 0i64);
  _mm_storeu_si128(&v13, 0i64);
  v14 = 0i64;
  if ( index >= gConfig.dwNumColumnsets )
    return 1;
  SendMessageW(ghWndTreeListView, WM_SETREDRAW, 0, 0);
  SendMessageW(ghWndHandlesListCtrl, WM_SETREDRAW, 0, 0);
  SendMessageW(ghWndDllsListCtrl, WM_SETREDRAW, 0, 0);
  qmemcpy(gConfig.szColumnSetName, &gConfig.strMenuCulumnSet[index], 0x5F4u);
  sub_FD7930(gConfig.szColumnSetName);
  CTreeView::InitListHeader(
    ghWndTreeListView,
    gConfig.dwProcessColumnMap,
    gConfig.dwProcessColumns,
    gConfig.dwProcessColumnCount);
  CTreeView::InitListHeader(
    ghWndHandlesListCtrl,
    gConfig.dwIdsOfHandleColumnMap,
    gConfig.dwHandleColumns,
    gConfig.dwHandleColumnCount);
  CTreeView::InitListHeader(ghWndDllsListCtrl, gConfig.dwDllColumnMap, gConfig.dwDllColumns, gConfig.dwDllColumnCount);
  GetClientRect(ghMainWnd, &Rect);
  CMainWnd::HandleSize(ghMainWnd, 0, 0, LOWORD(Rect.right) | (LOWORD(Rect.bottom) << 16));
  CTreeList::InitHeaderColumn(
    ghWndHandlesListCtrl,
    0xFFFFFFFF,
    gConfig.dwHandleSortColumn,
    gConfig.bHandleSortDirection);
  CTreeList::InitHeaderColumn(ghWndDllsListCtrl, 0xFFFFFFFF, gConfig.dwDllSortColumn, gConfig.bDllSortDirection);
  LODWORD(v12) = 101;
  pThis = ghWndTreeListView;
  if ( gConfig.bShowProcessTree )
  {
    gConfig.bShowProcessTree = 0;
    gConfig.bProcessSortDirection = 0;
    HIDWORD(v12) = 0;
  }
  else
  {
    gConfig.bProcessSortDirection = gConfig.bProcessSortDirection == 0;
    HIDWORD(v12) = gConfig.dwProcessSortColumn;
  }
  sub_FBD040(0x65u, &pThis);
  SendMessageW(ghWndToolbar, 0x401u, 0x9C67u, gConfig.bShowProcessTree == 0);
  v6 = gConfig.bShowProcessTree != 0;
  v7 = GetMenu(ghMainWnd);
  EnableMenuItem(v7, 0x9C67u, v6);
  memset(&v15, 0, 0x50u);
  sub_1000410(a1, a2, 0, &v15, &v9, &v10);
  CMainWnd::InitStatusBar(ghWndStatusBar);
  sub_FBFAA0(0x66);
  sub_FBFAA0(0x68);
  SendMessageW(ghWndTreeListView, 0xBu, 1u, 0);
  SendMessageW(ghWndHandlesListCtrl, 0xBu, 1u, 0);
  SendMessageW(ghWndDllsListCtrl, 0xBu, 1u, 0);
  v8 = SendMessageW(ghWndTreeListView, 0x100Cu, 0xFFFFFFFF, 2);
  SendMessageW(ghWndTreeListView, 0x1013u, v8, 0);
  return 0;
}

//----- (00FD2F00) --------------------------------------------------------
int sub_FD2F00()
{
  gConfig.bUseGoogle = 1;
  return 0;
}

//----- (00FD2F10) --------------------------------------------------------
int sub_FD2F10()
{
  gConfig.bUseGoogle = 0;
  return 0;
}

//----- (00FD2F20) --------------------------------------------------------
int __cdecl Command_LaunchDepends(HWND a1, __int16 a2)
{
  HWND v2; // edi
  const WCHAR *v3; // esi
  LRESULT v4; // eax
  struct _STARTUPINFOW StartupInfo; // [esp+8h] [ebp-8E8h]
  SHELLEXECUTEINFOW pExecInfo; // [esp+4Ch] [ebp-8A4h]
  LPARAM lParam; // [esp+88h] [ebp-868h]
  LRESULT v9; // [esp+8Ch] [ebp-864h]
  int v10; // [esp+90h] [ebp-860h]
  int v11; // [esp+A8h] [ebp-848h]
  struct _PROCESS_INFORMATION ProcessInformation; // [esp+BCh] [ebp-834h]
  WCHAR CommandLine; // [esp+CCh] [ebp-824h]

  lParam = 0;
  memset(&v9, 0, 0x30u);
  v2 = ghWndTreeListView;
  v3 = 0;
  if ( a2 == -25504 )
    v2 = ghWndDllsListCtrl;
  if ( v2 == ghWndHandlesListCtrl )
    v2 = ghWndTreeListView;
  v4 = SendMessageW(v2, 0x100Cu, 0xFFFFFFFF, 2);
  if ( v4 != -1 )
  {
    v9 = v4;
    v10 = 0;
    lParam = 4;
    if ( SendMessageW(v2, 0x104Bu, 0, &lParam) )
    {
      if ( v2 == ghWndDllsListCtrl )
      {
        if ( *(v11 + 44) & 8 )
        {
          MessageBoxW(
            ghWndTreeListView,
            L"Depends not supported on pagefile-backed sections",
            L"Process Explorer Error",
            0x10u);
          return 0;
        }
        v3 = *(v11 + 344);
        SetFocus(ghWndDllsListCtrl);
      }
      else
      {
        v3 = *(v11 + 792);
        if ( !v3 )
        {
          MessageBoxW(ghWndTreeListView, L"No process image file.", L"Process Explorer Error", 0x10u);
          return 0;
        }
        SetFocus(ghWndTreeListView);
      }
    }
  }
  if ( !*v3 )
  {
    MessageBoxW(ghWndTreeListView, L"No process or DLL is selected", L"Process Explorer Error", 0x10u);
    return 0;
  }
  if ( gstrApplicationName )
  {
    sub_FD68E0(&CommandLine, L"depends \"%s\"", v3);
    memset(&StartupInfo, 0, 0x44u);
    StartupInfo.dwFlags = 1;
    StartupInfo.cb = 68;
    StartupInfo.wShowWindow = 5;
    _mm_storeu_si128(&ProcessInformation, 0i64);
    if ( CreateProcessW(&gstrApplicationName, &CommandLine, 0, 0, 0, 0x200u, 0, 0, &StartupInfo, &ProcessInformation) )
    {
      CloseHandle(ProcessInformation.hThread);
      CloseHandle(ProcessInformation.hProcess);
      return 0;
    }
  }
  else
  {
    memset(&pExecInfo, 0, 0x3Cu);
    pExecInfo.cbSize = 60;
    pExecInfo.lpFile = v3;
    pExecInfo.lpVerb = L"View Dependencies";
    pExecInfo.fMask = 0;
    pExecInfo.nShow = 5;
    ShellExecuteExW(&pExecInfo);
  }
  return 0;
}
// 1041F14: using guessed type wchar_t aViewDependenci[18];

//----- (00FD31A0) --------------------------------------------------------
int Command_DebugProcess()
{
  HWND v0; // edi
  int v1; // esi
  LRESULT v2; // eax
  struct _STARTUPINFOW StartupInfo; // [esp+8h] [ebp-49Ch]
  LPARAM lParam; // [esp+4Ch] [ebp-458h]
  LRESULT v6; // [esp+50h] [ebp-454h]
  int v7; // [esp+54h] [ebp-450h]
  int v8; // [esp+6Ch] [ebp-438h]
  struct _PROCESS_INFORMATION ProcessInformation; // [esp+80h] [ebp-424h]
  WCHAR CommandLine; // [esp+90h] [ebp-414h]

  lParam = 0;
  memset(&v6, 0, 0x30u);
  v0 = ghWndTreeListView;
  v1 = 0;
  v2 = SendMessageW(ghWndTreeListView, 0x100Cu, 0xFFFFFFFF, 2);
  if ( v2 != -1
    && (v6 = v2, v7 = 0, lParam = 4, SendMessageW(v0, 0x104Bu, 0, &lParam))
    && (v1 = v8, SetFocus(ghWndTreeListView), v1) )
  {
    if ( MessageBoxW(
           ghWndTreeListView,
           L"WARNING: Debugging this process may result in loss of data.\nAre you sure you wish to attach the debugger?",
           L"Process Explorer Warning",
           0x31u) == 2 )
      return 0;
  }
  else
  {
    MessageBoxW(ghWndTreeListView, L"No process is selected", L"Process Explorer Error", 0x10u);
  }
  MakeHandlePropSheetCaption(&CommandLine, L"\"%s\" -p %d", gszAeDebuggerPath, *(v1 + 68));
  memset(&StartupInfo, 0, 0x44u);
  StartupInfo.dwFlags = 1;
  StartupInfo.cb = 68;
  StartupInfo.wShowWindow = 5;
  _mm_storeu_si128(&ProcessInformation, 0i64);
  if ( CreateProcessW(0, &CommandLine, 0, 0, 0, 0x200u, 0, 0, &StartupInfo, &ProcessInformation) )
  {
    CloseHandle(ProcessInformation.hThread);
    CloseHandle(ProcessInformation.hProcess);
  }
  return 0;
}

//----- (00FD3330) --------------------------------------------------------
int __cdecl Command_ShowProcessesForAllUsers(HWND hWnd)
{
  signed int v1; // eax
  bool v2; // zf
  UINT v3; // ST0C_4
  HMENU v4; // eax
  tagTREEVIEWLISTITEMPARAM *i; // eax
  int v6; // ecx
  LRESULT v7; // ebx
  void *v8; // edi
  int v9; // esi
  LRESULT k; // edi
  int v11; // esi
  int v12; // eax
  LPARAM lParam; // [esp+Ch] [ebp-38h]
  int v15; // [esp+10h] [ebp-34h]
  int v16; // [esp+14h] [ebp-30h]
  int v17; // [esp+2Ch] [ebp-18h]
  void *j; // [esp+40h] [ebp-4h]

  SendMessageW(ghWndTreeListView, 0xBu, 0, 0);
  v1 = 0;
  v2 = gConfig.bShowAllUsers != 0;
  gConfig.bShowAllUsers = gConfig.bShowAllUsers == 0;
  if ( !v2 )
    v1 = 8;
  v3 = v1;
  v4 = GetMenu(hWnd);
  CheckMenuItem(v4, 0x9C77u, v3);
  for ( i = gpTreeViewListItemParam; i; i = i->m_Prev )
  {
    if ( gConfig.bShowAllUsers || (v6 = i->dwStyle, v6 & 0x40) )
      i->dwStyle |= 2u;
    else
      i->dwStyle = v6 & 0xFFFFFFFD;
  }
  v7 = SendMessageW(ghWndTreeListView, 0x1004u, 0, 0);
  v8 = operator new[](4 * v7);
  v9 = 0;
  for ( j = v8; v9 < v7; ++v9 )
  {
    v15 = v9;
    v16 = 0;
    lParam = 4;
    SendMessageW(ghWndTreeListView, 0x104Bu, 0, &lParam);
    *(v8 + v9) = v17;
  }
  SendMessageW(ghWndTreeListView, 0x1009u, 0, 0);
  for ( k = 0; k < v7; *(v11 + 1464) = v12 )
  {
    v11 = *(j + k);
    v12 = sub_FB7F20(ghWndTreeListView, *(j + k++));
  }
  j_j__free(j);
  byte_10653B5 = 1;
  SetEvent(ghTimerRefreshEvent);
  return 0;
}
// 10653B5: using guessed type char byte_10653B5;

//----- (00FD3490) --------------------------------------------------------
int __cdecl Command_SaveColumnSet(HWND hWndParent)
{
  DialogBoxParamW(ghInstance, L"COLUMNSETSAVE", hWndParent, DlgColumnSetSave, 0);
  return 0;
}

//----- (00FD34C0) --------------------------------------------------------
int __cdecl Command_OrganizeColumnSets(HWND hWnd)
{
  if ( gConfig.dwNumColumnsets )
    DialogBoxParamW(ghInstance, L"COLUMNSETS", hWnd, DlgColumnSets, 0);
  else
    MessageBoxW(
      hWnd,
      L"There are no column sets defined. Use View->Save Column Set to save a column set.",
      L"Process Explorer",
      0x30u);
  return 0;
}

//----- (00FD3510) --------------------------------------------------------
LRESULT __cdecl CMainWnd::HandleCommand(HWND hWnd, int a2, WPARAM wParam, LPARAM lParam)
{
  return HandleCmdHandler(&CMainWnd::gCmdHandler, hWnd, wParam, lParam);
}
// 105E11C: using guessed type struct tagMSGHANDLER CMainWnd::gCmdHandler;

//----- (00FD3530) --------------------------------------------------------
int __cdecl CMainWnd::HandlePaint(HWND hWnd)
{
  HDC v1; // eax
  struct tagPAINTSTRUCT Paint; // [esp+4h] [ebp-44h]

  v1 = BeginPaint(hWnd, &Paint);
  if ( gConfig.bShowLowerPane )
    DrawEdge(v1, &gRectPane, 5u, 0x80Au);
  EndPaint(hWnd, &Paint);
  return 0;
}

//----- (00FD3590) --------------------------------------------------------
int __cdecl CMainWnd::HandleSize(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
  int nHeight; // edi
  HWND hWndRebar; // eax
  LONG top; // ebx
  int v8; // ST14_4
  int v9; // ST10_4
  HWND v10; // eax
  struct tagRECT rcStatusBar; // [esp+Ch] [ebp-24h]
  struct tagRECT rcReBar; // [esp+1Ch] [ebp-14h]

  if ( wParam == 1 )
  {
    if ( gConfig.bHideWhenMinimized )
    {
      CMainWnd::Hide(ghMainWnd);
      return 0;
    }
  }
  else
  {
    GetWindowRect(ghWndStatusBar, &rcStatusBar);
    nHeight = rcStatusBar.bottom - rcStatusBar.top;
    hWndRebar = GetParent(ghWndCPUGraph);
    GetWindowRect(hWndRebar, &rcReBar);
    GetClientRect(hWnd, &gRectWindow);
    top = (lParam >> 16) - (rcReBar.bottom - rcReBar.top + gRectWindow.top);
    gRectWindow.top += rcReBar.bottom - rcReBar.top;
    gRectWindow.right = lParam;
    gRectWindow.bottom = top;
    InvalidateRect(hWnd, &gRectPane, 0);
    gRectPane.right = lParam;
    gRectPane.top = ((gRectWindow.top + gRectWindow.bottom - nHeight) * gConfig.dbDivider);
    gRectPane.bottom = gRectPane.top + 7;
    MoveWindow(ghWndTreeListView, 0, gRectWindow.top, lParam, gRectPane.top - gRectWindow.top, 1);
    MoveWindow(
      ghWndHandlesListCtrl,
      0,
      gRectPane.bottom - 1,
      lParam,
      gRectWindow.bottom - gRectPane.bottom - nHeight + gRectWindow.top + 1,
      TRUE);
    MoveWindow(
      ghWndDllsListCtrl,
      0,
      gRectPane.bottom - 1,
      lParam,
      gRectWindow.bottom - gRectPane.bottom - nHeight + gRectWindow.top + 1,
      TRUE);
    MoveWindow(ghWndStatusBar, 0, gRectWindow.top + gRectWindow.bottom - nHeight, lParam, nHeight, 1);
    v8 = gnToolbarHeight;
    v9 = gRectWindow.right;
    v10 = GetDlgItem(hWnd, IDC_MAINTOOLBAR);
    MoveWindow(v10, 0, 0, v9, v8, TRUE);
    InvalidateRgn(ghWndStatusBar, 0, FALSE);
    MoveWindow(ghWndReBar, 0, 0, gRectWindow.right - gRectWindow.left, 0, TRUE);
  }
  return 0;
}

//----- (00FD3780) --------------------------------------------------------
int __cdecl CMainWnd::HandleGetMinmaxInfo(HWND a1, unsigned int a2, unsigned int a3, MINMAXINFO *a4)
{
  a4->ptMinTrackSize.x = 200;
  a4->ptMinTrackSize.y = 200;
  return 0;
}

//----- (00FD37A0) --------------------------------------------------------
int __cdecl CMainWnd::HandleLBtnDown(HWND hWnd, int a2, int a3, int a4)
{
  POINT v4; // ST04_8

  v4.y = a4 >> 16;
  v4.x = a4;
  if ( PtInRect(&gRectPane, v4) )
  {
    SetCursor(ghResizeCursor);
    SetCapture(hWnd);
    DrawLine(hWnd, (a4 >> 16) - 6);
    gyMouseDown = (a4 >> 16) - 6;
  }
  return 0;
}

//----- (00FD37F0) --------------------------------------------------------
int __cdecl CMainWnd::HandleLBtnUp(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
  signed int v4; // esi
  struct tagRECT Rect; // [esp+Ch] [ebp-14h]

  v4 = lParam >> 16;
  if ( gbWindowFinding )
  {
    SearchWindow(hWnd);
    return 0;
  }
  if ( GetCapture() )
  {
    SetCursor(ghResizeCursor);
    ReleaseCapture();
    DrawLine(hWnd, gyMouseDown);
    if ( v4 > gRectWindow.bottom - 30 )
      return Command_ShowLowerPane(hWnd);
    if ( v4 < gRectWindow.top + 40 )
      LOWORD(v4) = LOWORD(gRectWindow.top) + 40;
    gRectPane.top = v4 - 3;
    gRectPane.bottom = gRectPane.top + 7;
    gConfig.dbDivider = (v4 - 3) / (gRectWindow.top + gRectWindow.bottom);
    GetClientRect(ghMainWnd, &Rect);
    CMainWnd::HandleSize(
      ghMainWnd,
      0,
      0,
      (LOWORD(Rect.right) - LOWORD(Rect.left)) | ((LOWORD(Rect.bottom) - LOWORD(Rect.top)) << 16));
    InvalidateRect(hWnd, &gRectPane, 0);
  }
  return 0;
}
// 106A38B: using guessed type char gbWindowFinding;

//----- (00FD3940) --------------------------------------------------------
int __cdecl CMainWnd::HandleMouseMove(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
  signed int y; // esi
  HWND hWndTemp; // edi
  HWND hWndParent; // eax
  HCURSOR v7; // eax
  int result; // eax
  HCURSOR v9; // eax
  int v10; // esi
  POINT v11; // ST08_8
  struct tagPOINT Point; // [esp+8h] [ebp-8h]

  y = lParam >> 16;
  if ( gbWindowFinding )
  {
    Point.x = lParam;
    Point.y = SHIWORD(lParam);
    ClientToScreen(hWnd, &Point);
    hWndTemp = WindowFromPoint(Point);
    if ( hWndTemp != ghWndHungWindow )
    {
      if ( ghWndHungWindow )
        DrawHungWindow(ghWndHungWindow);
      hWndParent = hWndTemp;
      while ( hWndParent != ghMainWnd )
      {
        hWndParent = GetParent(hWndParent);
        if ( !hWndParent )
        {
          if ( ghMainWnd )
          {
            ghWndHungWindow = hWndTemp;
            DrawHungWindow(hWndTemp);
            v7 = LoadCursorW(ghInstance, 10);
            SetCursor(v7);
            return 0;
          }
          break;
        }
      }
      ghWndHungWindow = 0;
    }
    v9 = LoadCursorW(ghInstance, 0xA);
    SetCursor(v9);
    result = 0;
  }
  else if ( GetCapture() )
  {
    if ( y > gRectWindow.bottom - 5 )
      LOWORD(y) = LOWORD(gRectWindow.bottom) - 5;
    if ( y < gRectWindow.top + 40 )
      LOWORD(y) = LOWORD(gRectWindow.top) + 40;
    DrawLine(hWnd, gyMouseDown);
    v10 = (y - 3);
    DrawLine(hWnd, v10);
    gyMouseDown = v10;
    result = 0;
  }
  else
  {
    v11.y = lParam >> 16;
    v11.x = lParam;
    if ( PtInRect(&gRectPane, v11) )
      SetCursor(ghResizeCursor);
    result = 0;
  }
  return result;
}
// 106A38B: using guessed type char gbWindowFinding;

//----- (00FD3AA0) --------------------------------------------------------
BOOL __cdecl CMainWnd::HandleMeasureItem(HWND a1, unsigned int a2, unsigned int a3, LPMEASUREITEMSTRUCT lpmis)
{
  HDC hDC; // ebx
  BOOL result; // eax
  int v6; // edi
  struct tagTEXTMETRICW tm; // [esp+8h] [ebp-40h]

  if ( lpmis->CtlType == IDC_LISTCTRL_HANDLES || lpmis->CtlID == IDC_TREEVIEW_LIST )
  {
    hDC = GetDC(ghWndTreeListView);
    SelectObject(hDC, ghConfigFont);
    result = GetTextMetricsW(hDC, &tm);
    if ( !result )
      return result;
    if ( lpmis->CtlID == IDC_TREEVIEW_LIST )
    {
      v6 = tm.tmHeight + 2;
      if ( v6 <= GetSystemMetrics(SM_CYSMICON) )
        v6 = GetSystemMetrics(SM_CYSMICON);
      lpmis->itemHeight = v6;
    }
    else
    {
      lpmis->itemHeight = tm.tmHeight + 2;
    }
    ReleaseDC(ghWndTreeListView, hDC);
  }
  else if ( lpmis->CtlType == ODT_MENU )
  {
    lpmis->itemWidth = 16;
    lpmis->itemHeight = 16;
  }
  return 1;
}

//----- (00FD3B70) --------------------------------------------------------
int __cdecl CMainWnd::HandleNotify(HWND hWnd, UINT msg, WPARAM wParam, NMHDR *lParam)
{
  UINT code; // eax
  int v5; // eax
  struct tagPOINT Point; // [esp+4h] [ebp-1Ch]
  struct tagRECT Rect; // [esp+Ch] [ebp-14h]

  code = lParam->code;
  if ( code > LVN_GETDISPINFOW )
  {
    switch ( code )
    {
      case 4294967121u:
        // LVN_DELETEITEM
        return 1;
      case 4294967141u:
        return sub_FBF490(wParam, lParam);
      case 4294967188u:
        return sub_FBD040(wParam, lParam);
      case 4294967193u:
        return sub_FBD4B0(wParam, lParam);
      case 4294967195u:
        return sub_FBF4D0(wParam);
      case 4294967274u:
        if ( wParam == 103 )
          GetButtonSize();
        return 0;
      case 4294967291u:
        GetCursorPos(&Point);
        return UpdateListViewContextMenu(wParam, lParam, &Point);
      case 4294967293u:
        return FillList(wParam);
      case 4294967294u:
        return sub_FBCDD0(wParam, lParam);
      default:
        return 0;
    }
  }
  else
  {
    if ( code == LVN_GETDISPINFOW )
      return sub_FBD7B0(wParam, lParam);
    if ( code > 0xFFFFFCC1 )
    {
      switch ( code )
      {
        case 0xFFFFFD43:
          if ( lParam[1].hwndFrom == 40109 )
          {
            SearchWindow(hWnd);
            return 0;
          }
          break;
        case 0xFFFFFDEE:
          return sub_FFFA90(wParam, lParam);
        case 0xFFFFFF4D:
          return sub_FBD7A0(wParam);
      }
    }
    else
    {
      if ( code == 0xFFFFFCC1 )
      {
        GetClientRect(ghMainWnd, &Rect);
        CMainWnd::HandleSize(
          ghMainWnd,
          0,
          0,
          (LOWORD(Rect.right) - LOWORD(Rect.left)) | ((LOWORD(Rect.bottom) - LOWORD(Rect.top)) << 16));
        InvalidateRect(ghWndTreeListView, 0, 0);
        return 0;
      }
      if ( code > 0x7D4 )
      {
        if ( code == 2005 )
          return sub_FC1C50(wParam, lParam);
        if ( code == -839 )
        {
          InvalidateRect(lParam->hwndFrom, 0, 0);
          return 0;
        }
      }
      else
      {
        if ( code == 2004 )
          return sub_FC1B70(wParam, &lParam->hwndFrom);
        v5 = code - 2001;
        if ( !v5 )
          return sub_101F550();
        if ( v5 == 1 )
          return CAboutWnd::HandleInitDialog();
      }
    }
  }
  return 0;
}

//----- (00FD3F40) --------------------------------------------------------
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
  HMENU (__stdcall *GetMenu)(HWND); // esi
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
  void (__stdcall *RegCloseKey)(HKEY); // esi
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
  int (__stdcall *v127)(HWND, RECT *, DWORD, DWORD); // eax
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
  for ( i = 0; i < gConfig.dwNumColumnsets; ++i )
  {
    if ( i >= 10 )
    {
      wcscpy_s(szMenuItemName, MAX_PATH, gConfig.strMenuCulumnSet[i].ColumnSetName);
    }
    else
    {
      if ( i == 9 )
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
  if ( gpfnCreateRestrictedToken )
  {
    v16 = GetSubMenu(hMainMenuHandle, 0);
    InsertMenuW(v16, 1u, MF_BYPOSITION, IDM_RUN_AS_LIMITED_USER, L"Run as &Limited User...");
    ++gdwMenuItemCountAppendedInRuntime;
  }
  if ( gdwVersion < 1 )
  {
    v133 = L"R&unas...";
    goto LABEL_15;
  }
  if ( !IsBuiltinAdministrative() )
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
  if ( gdwVersion < WINDOWS_VISTA
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
        gdwVersion < WINDOWS_VISTA)
    || IsBuiltinAdministrative() )
  {
    if ( ChangeWindowMessageFilter )
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
  if ( gConfig.bVerifySignatures )
    v23 = MF_CHECKED;
  CheckMenuItem(hMainMenuHandle, IDM_OPTIONS_VERIFY_IMAGE_SIGNATURE, v23);
  v24 = 0;
  if ( gConfig.bCheckVirusTotal )
    v24 = MF_CHECKED;
  CheckMenuItem(hMainMenuHandle, IDM_OPTIONS_CHECK_VIRTULTOALDOTCOM, v24);
  EnableMenuItem(hMainMenuHandle, IDM_OPTIONS_SUBMIT_UNKNOWN_EXECUTABLES, gConfig.bCheckVirusTotal == 0);
  if ( gConfig.bCheckVirusTotal )
    SubmitExeToVirusTotalDotCom();
  v25 = 0;
  if ( gConfig.bTrayCPUHistory )
    v25 = MF_CHECKED;
  v26 = v25;
  v27 = GetMenu(hWnd_1);
  CheckMenuItem(v27, IDM_OPTIONS_TRAYICON_CPU_HISTORY, v26);
  v28 = 0;
  if ( gConfig.bShowIoTray )
    v28 = MF_CHECKED;
  v29 = v28;
  v30 = GetMenu(hWnd_1);
  CheckMenuItem(v30, IDM_OPTIONS_TRAYICON_IO_HISTORY, v29);
  v31 = 0;
  if ( gConfig.bShowCommitTray )
    v31 = MF_CHECKED;
  v32 = v31;
  v33 = GetMenu(hWnd_1);
  CheckMenuItem(v33, IDM_OPTIONS_TRAYICON_COMMIT_HISTORY, v32);
  v34 = 0;
  if ( gConfig.bShowPhysTray )
    v34 = MF_CHECKED;
  v35 = v34;
  v36 = GetMenu(hWnd_1);
  CheckMenuItem(v36, IDM_OPTIONS_TRAYICON_PHYSICAL_MEMORY_HISTORY, v35);
  v37 = 0;
  if ( gConfig.bAllOneInstance )
    v37 = MF_CHECKED;
  CheckMenuItem(hMainMenuHandle, IDM_OPTIONS_ALLOW_ONLY_ONE_INSTANCE, v37);
  v38 = 0;
  if ( gConfig.bHideWhenMinimized )
    v38 = MF_CHECKED;
  CheckMenuItem(hMainMenuHandle, IDM_OPTIONS_HIDE_WHEN_MINIMIZED, v38);
  v39 = 0;
  if ( gConfig.bShowColumnHeatmaps )
    v39 = MF_CHECKED;
  CheckMenuItem(hMainMenuHandle, IDM_VIEW_SHOW_COLUMN_HEATMAPS, v39);
  gConfig.bAlwaysOntop = gConfig.bAlwaysOntop == 0;
  Command_SetTopmost(ghMainWnd);
  v40 = 0;
  if ( gConfig.bShowCpuFractions )
    v40 = MF_CHECKED;
  CheckMenuItem(hMainMenuHandle, IDM_PROCESS_CONFIRM_TO_KILL, v40);
  v41 = 0;
  if ( gConfig.bConfirmKill )
    v41 = MF_CHECKED;
  CheckMenuItem(hMainMenuHandle, IDM_OPTIONS_CONFIRM_KILL, v41);
  v42 = 0;
  if ( gConfig.bFormatIoBytes )
    v42 = MF_CHECKED;
  CheckMenuItem(hMainMenuHandle, IDM_SHOW_NEW_PROCESS, v42);
  v43 = 0;
  if ( gConfig.bShowNewProcesses )
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
  if ( Init3DStatistics(&dwMinSegments, &dwNbSegments) )
  {
    gpGraphInfoOfGPU = InitGraphData(1, 1, 1);
    gpGraphInfoOfGPU->m_nItemID = 4;
    gpGraphInfoOfGPU->m_Color = 0x8080FF;
    gpGraphInfoOfGPU->m_dbMemorySize = db_onehundred;
    gpGraphInfoOfSystemMemory = InitGraphData(1, 1, 0);
    gpGraphInfoOfSystemMemory->m_nItemID = 5;
    gpGraphInfoOfSystemMemory->m_Color = 0xAAAA;
    if ( dwMinSegments )
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
    if ( dwNbSegments )
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
  if ( gdwVersion >= 1 && !IsBuiltinAdministrative() )
    ReplaceMenuIconFromStockIcon(hMainMenuHandle, IDM_OPTIONS_REPLACE_TASK_MANAGER);
  if ( CanReplaceTaskManager() )
    ReplaceTaskManager(hWnd_1, 0);
  v52 = IsProcessExplorerRunAtStartup(&savedregs, hMainMenuHandle) != 0 ? MF_CHECKED : 0;
  v53 = GetMenu(hWnd_1);
  CheckMenuItem(v53, IDM_OPTIONS_RUN_AT_LOGON, v52);
  v54 = 0;
  if ( gConfig.bShowAllUsers )
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
  if ( WTSEnumerateSessionsW
    && *SetMenuInfo
    && WTSEnumerateSessionsW(0, 0, 1u, &pSessionInfo, &nSessionCount)
    && nSessionCount )
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
  if ( !szDomainName[0] || (psz_1 = L"\\", !szUserName[0]) )
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
  if ( gSystemInfo.dwNumberOfProcessors > 1 )
  {
    hProcessMenu = GetSubMenu(hMainMenuHandle, 3);
    InsertMenuW(hProcessMenu, 2u, MF_BYPOSITION, IDC_PROCESS_SET_AFFINITY, L"Set &Affinity...");
    CheckMenuItem(hMainMenuHandle, (gConfig.bShowAllCpus != 0) + IDM_PROCESSOR_ONE_GRAPH_ALL_CPUS, MF_CHECKED);
    if ( *GetLogicalProcessorInformation )
    {
      cbData = 0;
      GetLogicalProcessorInformation(0, &cbData);
      if ( GetLastError() == ERROR_INSUFFICIENT_BUFFER )
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
    for ( index = 0; index < gSystemInfo.dwNumberOfProcessors; ++index )
    {
      gppGraphInfo[index] = InitGraphData(NumberOfProcessors, 2, 0);
      gppGraphInfo[index]->m_ProcessorID = index;
      sub_FC3E70(
        gpLogicalProcessorInfo,
        gdwLogicalProcessorInfoItemCount,
        index,
        &gppGraphInfo[index]->field_874,
        &gppGraphInfo[index]->field_870);
      gppGraphInfo[index]->m_nChildID = 2;
      gppGraphInfo[index]->m_nItemID = 0;
      gppGraphInfo[index]->m_Color = 0x3C943C;
      gppGraphInfo[index]->m_dbMemorySize = db_onehundred;
      gppGraphInfo[index]->m_Item[0].Color = 255;
      gppGraphInfo[index]->m_Item[0].dbMemorySize = db_onehundred;
      gppGraphInfo[index]->m_GraphData = gpGraphInfoOfCPU;
      if ( index )
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
  if ( *SetSuspendState )
  {
    v65 = LoadLibraryW(L"Powrprof.dll");
    *IsPwrHibernateAllowed = GetProcAddress(v65, "IsPwrHibernateAllowed");
    if ( IsPwrHibernateAllowed() )
      InsertMenuW(hMainMenuHandle, IDM_FILE_SHUTDOWN_RESTART, MF_BYCOMMAND, IDC_FILE_HIBERNATE, L"&Hibernate");
    v66 = LoadLibraryW(L"Powrprof.dll");
    *IsPwrSuspendAllowed = GetProcAddress(v66, "IsPwrSuspendAllowed");
    if ( IsPwrSuspendAllowed() )
      InsertMenuW(hMainMenuHandle, IDM_FILE_SHUTDOWN_RESTART, MF_BYCOMMAND, IDC_FILE_STANDBY, L"Stand &By");
  }
  v67 = LoadLibraryW(L"User32.dll");
  *LockWorkStation = GetProcAddress(v67, "LockWorkStation");
  if ( *LockWorkStation )
    InsertMenuW(hMainMenuHandle, IDM_FILE_SHUTDOWN_RESTART, MF_BYCOMMAND, IDC_THREADSTACK_BUTTON_COPY, L"Loc&k");
  v68 = LoadLibraryW(L"User32.dll");
  *GetMonitorInfoA = GetProcAddress(v68, "GetMonitorInfoA");
  v69 = LoadLibraryW(L"User32.dll");
  *MonitorFromPoint = GetProcAddress(v69, "MonitorFromPoint");
  v70 = LoadMenuW(ghInstance, L"DLLMENU");
  v71 = 0;
  ghDllMenuPopup = v70;
  if ( gConfig.bHighlightRelocatedDlls )
    v71 = 8;
  CheckMenuItem(v70, IDM_OPTIONS_HIGHLIGHT_RELOCATED_DLLS, v71);
  ghHandleMenuPopup = LoadMenuW(ghInstance, L"HANDLEMENU");
  v72 = 0;
  if ( gConfig.bShowUnnamedHandles )
    v72 = 8;
  v73 = v72;
  v74 = GetMenu(hWnd_1);
  CheckMenuItem(v74, IDM_VIEW_SHOW_UNNAMED_HANDLES_AND_MAPPINGS, v73);
  RegCloseKey = ::RegCloseKey;
  if ( RegOpenKeyW(HKEY_CLASSES_ROOT, L"exefile\\shell\\View Dependencies", &hSubKey) )
  {
    gstrApplicationName = 0;
    dwRet = GetEnvironmentVariableW(L"PATH", 0, 0);
    dwSize = dwRet;
    if ( dwRet )
    {
      pszPath = malloc(2 * dwRet + 2);
      GetEnvironmentVariableW(L"PATH", pszPath, dwSize);
      dwSize_1 = dwSize;
      pszPath_1 = pszPath;
      if ( MakeApplicationName(L"depends.exe", pszPath, dwSize_1, &gstrApplicationName) )
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
  if ( !RegOpenKeyW(HKEY_LOCAL_MACHINE, L"Software\\Microsoft\\Windows NT\\CurrentVersion\\AeDebug", &hSubKey) )
  {
    cbData = 520;
    if ( !RegQueryValueExW(hSubKey, L"Debugger", 0, &Type, szPathName, &cbData) )
    {
      _wcslwr_s(gszAeDebuggerPath, MAX_PATH);
      if ( szPathName[0] == '"' )
      {
        wcscpy_s(gszAeDebuggerPath, MAX_PATH, &szPathName[1]);
        if ( wcschr(gszAeDebuggerPath, '"') )
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
        if ( wcschr(gszAeDebuggerPath, ' ') )
        {
          psz = wcschr(gszAeDebuggerPath, ' ');
          goto LABEL_110;
        }
      }
    }
LABEL_111:
    RegCloseKey(hSubKey);
  }
  if ( gszAeDebuggerPath[0] )
    InsertMenuW(hMainMenuHandle, IDM_PROCESS_TEMP, MF_BYCOMMAND, IDM_PROCESS_DEBUG, L"&Debug");
  DeleteMenu(hMainMenuHandle, IDM_PROCESS_TEMP, MF_BYCOMMAND);
  hWnd_2 = hWnd_1;
  ghWndToolbar = InitToolbar(hWnd_1, IDC_MAINTOOLBAR);
  if ( !ghWndToolbar )
    return -1;
  UpdateMenuStatus(0, 3);
  GetWindowRect(ghWndToolbar, &rcToolbar);
  gnToolbarHeight = rcToolbar.bottom - rcToolbar.top + 2;
  hInst = ghInstance;
  _mm_storeu_si128(&rcTreeList, 0i64);
  hWndTreeListView = CTreeList::Init(hWnd_2, hInst, IDC_TREEVIEW_LIST, 0x40810200, &rcTreeList);
  ghWndTreeListView = hWndTreeListView;
  if ( !hWndTreeListView )
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
  sub_F9BDA0(pTreeList_1, 1);
  sub_F9F210(pTreeList_1, 0);
  sub_F9F230(pTreeList_1, 0);
  v88 = CTreeList::GetTooltipOfTreeList(pTreeList_1);
  CTreeList::InitToolTips(v88);
  v89 = CTreeList::GetTooltipOfLeftHeader(pTreeList_1);
  CTreeList::InitToolTips(v89);
  v90 = CTreeList::GetTooltipOfRightHeader(pTreeList_1);
  CTreeList::InitToolTips(v90);
  dwProcessColumnCount = gConfig.dwProcessColumnCount;
  if ( gConfig.dwProcessColumnMap[0] != IDS_PROCESS )
  {
    memmove(&gConfig.dwProcessColumnMap[1], gConfig.dwProcessColumnMap, 4 * gConfig.dwProcessColumnCount);
    gConfig.dwProcessColumnMap[0] = IDS_PROCESS;
    memmove(&gConfig.dwProcessColumns[1], gConfig.dwProcessColumns, 2 * gConfig.dwProcessColumnCount);
    wProcessImageColumnWidth = gConfig.wProcessImageColumnWidth;
    if ( !gConfig.wProcessImageColumnWidth )
      wProcessImageColumnWidth = 200;
    gConfig.dwProcessColumns[0] = wProcessImageColumnWidth;
    dwProcessColumnCount = gConfig.dwProcessColumnCount++ + 1;
  }
  if ( !CTreeView::InitListHeader(
          ghWndTreeListView,
          gConfig.dwProcessColumnMap,
          gConfig.dwProcessColumns,
          dwProcessColumnCount) )
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
  if ( !gConfig.bShowProcessTree )
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
  ghWndHandlesListCtrl = v101;
  if ( !v101 )
    return -1;
  CTreeList::InitHeaderColumn(v101, 0xFFFFFFFF, gConfig.dwHandleSortColumn, gConfig.bHandleSortDirection);
  v102 = CreateListCtrl(
           v100,
           0x40810605u,
           gConfig.dwDllColumnMap,
           gConfig.dwDllColumns,
           gConfig.dwDllColumnCount,
           IDC_LISTCTRL_DLLS);
  ghWndDllsListCtrl = v102;
  if ( !v102 )
    return -1;
  CTreeList::InitHeaderColumn(v102, 0xFFFFFFFF, gConfig.dwDllSortColumn, gConfig.bDllSortDirection);
  ghWndStatusBar = CreateStatusWindowW(0x50000000, &gszNullString, v100, 0x6Au);
  CMainWnd::InitStatusBar(ghWndStatusBar);
  ghResizeCursor = LoadCursorW(ghInstance, 0x69);
  if ( !ghResizeCursor )
    ghResizeCursor = LoadCursorW(0, 0x7F00);
  ghSplitterCursor = LoadCursorW(ghInstance, 0x6A);
  if ( !ghSplitterCursor )
    ghSplitterCursor = LoadCursorW(0, 0x7F00);
  v103 = 0;
  if ( gConfig.bHighlightRelocatedDlls )
    v103 = 8;
  v104 = v103;
  v105 = ::GetMenu(v100);
  CheckMenuItem(v105, IDM_OPTIONS_HIGHLIGHT_RELOCATED_DLLS, v104);
  ShowWindow(ghWndTreeListView, SW_SHOW);
  if ( gConfig.bShowLowerPane )
  {
    if ( gConfig.bShowDllView )
    {
      v106 = ::GetMenu(hWnd_1);
      CheckMenuItem(v106, IDM_VIEW_LOWERPANEVIEW_DLLS, MF_CHECKED);
      ShowWindow(ghWndDllsListCtrl, SW_SHOW);
    }
    else
    {
      v107 = ::GetMenu(hWnd_1);
      CheckMenuItem(v107, IDM_VIEW_LOWERPANEVIEW_HANDLES, MF_CHECKED);
      ShowWindow(ghWndHandlesListCtrl, SW_SHOW);
    }
  }
  nBmpIndex = 1;
  if ( gConfig.bShowDllView )
    nBmpIndex = 4;
  SendMessageW(ghWndToolbar, TB_CHANGEBITMAP, IDM_POPUP_DLL_PROPERTIES, nBmpIndex);
  SendMessageW(ghWndToolbar, TB_ENABLEBUTTON, IDM_VIEW_SHOW_PROCESS_TREE, gConfig.bShowProcessTree == 0);
  v109 = gConfig.bShowProcessTree != 0;
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
  if ( gConfig.bShowLowerPane )
    v112 = gConfig.dbSavedDivider;
  else
    v112 = db_one;
  gConfig.dbDivider = v112;
  gConfig.bShowLowerPane = gConfig.bShowLowerPane == 0;
  Command_ShowLowerPane(0);
  gShellIconMsg = RegisterWindowMessageW(L"TaskbarCreated");
  StartBackendThread();
  CTreeList::InitTreeList(ghWndTreeListView, 1);
  SendMessageW(ghMainWnd, WM_TREEVIEW_SORT, IDC_TREEVIEW_LIST, gConfig.bShowProcessTree);
  SetFocus(ghWndTreeListView);
  lvItem.iItem = SendMessageW(ghWndTreeListView, LVM_GETNEXTITEM, 0xFFFFFFFF, LVFI_STRING);
  lvItem.iSubItem = 0;
  lvItem.mask = 4;
  SendMessageW(ghWndTreeListView, LVM_GETITEMW, 0, &lvItem);
  RefreshVirusTotalMenuItem(lvItem.lParam);
  Item.stateMask = 3;
  Item.state = 3;
  SendMessageW(ghWndDllsListCtrl, LVM_SETITEMSTATE, 0, &Item);
  Item.stateMask = 3;
  Item.state = 3;
  SendMessageW(ghWndHandlesListCtrl, LVM_SETITEMSTATE, 0, &Item);
  if ( IsBuiltinAdministrative() && !PE_RunTrace(&gProperties, 1) )
  {
    InsertMenuW(
      hMainMenuHandle,
      IDM_OPTIONS_TRAYICON_COMMIT_HISTORY,
      MF_BYCOMMAND,
      IDM_OPTIONS_COMMIT_DISK_HISTORY,
      L"&Disk History");
    v113 = 0;
    if ( gConfig.bShowDiskTray )
      v113 = 8;
    v114 = v113;
    v115 = ::GetMenu(hWnd_1);
    CheckMenuItem(v115, IDM_OPTIONS_COMMIT_DISK_HISTORY, v114);
    InsertMenuW(hMainMenuHandle, 40726u, MF_BYCOMMAND, IDM_OPTIONS_COMMIT_NETWORK_HISTORY, L"&Network History");
    v116 = 0;
    if ( gConfig.bShowNetTray )
      v116 = 8;
    v117 = v116;
    v118 = ::GetMenu(hWnd_1);
    CheckMenuItem(v118, IDM_OPTIONS_COMMIT_NETWORK_HISTORY, v117);
  }
  if ( gdwAdapterRuntingTime )
  {
    InsertMenuW(hMainMenuHandle, IDM_OPTIONS_TRAYICON_COMMIT_HISTORY, MF_BYCOMMAND, 40748u, L"&GPU History");
    v119 = hWnd_1;
    v120 = 0;
    if ( gConfig.bShowGpuHistory )
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
  if ( gConfig.dwRefreshRate > 2000 )
  {
    if ( gConfig.dwRefreshRate == 5000 )
    {
      v132 = IDM_VIEW_UPDATESPEED_FIVE_SECONDS;
      goto __RefreshMenuItem;
    }
    if ( gConfig.dwRefreshRate == 10000 )
    {
      v132 = IDM_VIEW_UPDATESPEED_TEN_SECONDS;
      goto __RefreshMenuItem;
    }
  }
  else
  {
    if ( gConfig.dwRefreshRate == 2000 )
    {
      v132 = IDM_VIEW_UPDATESPEED_TWO_SECONDS;
      goto __RefreshMenuItem;
    }
    if ( gConfig.dwRefreshRate )
    {
      if ( gConfig.dwRefreshRate == 500 )
      {
        v132 = IDM_VIEW_UPDATESPEED_HALF_SECONDS;
        goto __RefreshMenuItem;
      }
      if ( gConfig.dwRefreshRate == 1000 )
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
  if ( !gIOGraphInfo.pGraphData )
    DeleteMenu(hMainMenuHandle, IDM_OPTIONS_TRAYICON_IO_HISTORY, 0);
  HandleTaskbarCreated();
  v125 = GetModuleHandleW(L"Shlwapi.dll");
  gpfnSHAutoComplete = GetProcAddress(v125, "SHAutoComplete");
  v126 = LoadLibraryW(L"user32.dll");
  v127 = GetProcAddress(v126, "SetLayeredWindowAttributes");
  dwOpacity = gConfig.dwOpacity;
  SetLayeredWindowAttributes = v127;
  if ( gConfig.dwOpacity != 100 )
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
  if ( gbHide )
    CMainWnd::Hide(ghMainWnd);
  return 0;
}
// F99F40: using guessed type bool __cdecl LoadWintrust();
// FF6620: using guessed type bool __cdecl GetProcessDEPStatus();
// 103CDC0: using guessed type double db_onehundred;
// 10408AC: using guessed type wchar_t aRUnAsAdministr[25];
// 1040D80: using guessed type wchar_t aPaused[7];
// 1064E54: using guessed type int gdwVersion;
// 106A118: using guessed type int (__stdcall *gpfnCreateRestrictedToken)(void *, unsigned int, unsigned int, struct _SID_AND_ATTRIBUTES *, unsigned int, struct _LUID_AND_ATTRIBUTES *, unsigned int, struct _SID_AND_ATTRIBUTES *, void **);
// 106A32C: using guessed type int gdwComdlg_FindReplaceMessageID;
// 106A388: using guessed type char gbHide;
// 106A390: using guessed type char gbIsProcessDEPEnabled;
// 106A391: using guessed type char gbWintrustInited;
// 106A392: using guessed type char gbLaunchDepends;
// 106A884: using guessed type int gShellIconMsg;
// 106A8F4: using guessed type int (__stdcall *gpfnSHAutoComplete)(struct HWND__ *, unsigned int);
// 106A908: using guessed type int ghSplitterCursor;
// 106F360: using guessed type int (__stdcall *ChangeWindowMessageFilter)(_DWORD, _DWORD);
// 1085720: using guessed type int gnStatusBarItemCount;

//----- (00FD57D0) --------------------------------------------------------
int __cdecl CMainWnd::HandleClose(HWND hWnd)
{
  if ( gConfig.bHideWhenMinimized )
    CMainWnd::Hide(ghMainWnd);
  else
    CMainWnd::HandleDestroy(hWnd);
  return 0;
}

//----- (00FD5810) --------------------------------------------------------
int CMainWnd::HandleEndSession()
{
  UpdateWindowPlacement(ghMainWnd, 1);
  return 0;
}

//----- (00FD5830) --------------------------------------------------------
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

//----- (00FD58B0) --------------------------------------------------------
int __cdecl CMainWnd::HandleDrawItem(HWND a1, unsigned int a2, unsigned int a3, LPDRAWITEMSTRUCT a4)
{
  if ( a4->CtlType != 1 )
    return CMainWnd::DrawList(a4);
  DrawIconEx(a4->hDC, a4->rcItem.left - 15, a4->rcItem.top, a4->itemData, 16, 16, 0, 0, 3u);
  return 0;
}

//----- (00FD58F0) --------------------------------------------------------
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
// 106A380: using guessed type unsigned int gdwTickLast;

//----- (00FD5940) --------------------------------------------------------
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

//----- (00FD5A40) --------------------------------------------------------
int __cdecl CMainWnd::HandleMsg7EF(int _8, int a2, int a3, void *a1)
{
  sub_FB8460(a1);
  return 0;
}

//----- (00FD5A60) --------------------------------------------------------
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
      sub_FBFAA0(0x65);
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
            sub_FBFAA0(0x68);
          }
        }
      }
    }
  }
  return 0;
}

//----- (00FD5C10) --------------------------------------------------------
int __cdecl CMainWnd::HandleMsg7F6(int a1, int a2, int a3, HWND hWnd)
{
  InvalidateRect(hWnd, 0, 0);
  return 0;
}

//----- (00FD5C30) --------------------------------------------------------
signed int CMainWnd::HandleKillFocus()
{
  ghWndFocusedLast = GetFocus();
  return 1;
}

//----- (00FD5C50) --------------------------------------------------------
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
      sub_FBFAA0(0x65);
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

//----- (00FD5D40) --------------------------------------------------------
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

//----- (00FD5DC0) --------------------------------------------------------
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

//----- (00FD6050) --------------------------------------------------------
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
      DialogBoxParamW(ghInstance, L"SENDMESSAGE", ghMainWnd, sub_FD85F0, v17.dwMenuData);
      goto LABEL_32;
    case 0x9EB1u:
      DialogBoxParamW(ghInstance, L"TSINFO", ghMainWnd, sub_FD8DE0, v17.dwMenuData);
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
// 102C83C: using guessed type int __stdcall CredUIPromptForCredentialsW(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 1040F14: using guessed type wchar_t aErrorDisconnec[28];
// 1040F50: using guessed type wchar_t aEnterTheSelect[35];
// 1040F98: using guessed type wchar_t aProcessExplore_5[34];
// 1040FDC: using guessed type wchar_t aErrorConnectin[28];
// 1041018: using guessed type wchar_t aRemoteControlI[55];
// 1041088: using guessed type wchar_t aErrorStartingR[30];
// 10410C4: using guessed type wchar_t aErrorLoggingOf[26];
// 10410F8: using guessed type wchar_t aSendmessage[12];
// 105E11C: using guessed type struct tagMSGHANDLER CMainWnd::gCmdHandler;
// 106F280: using guessed type int (__stdcall *gpfnProcessIdToSessionId)(_DWORD, _DWORD);
// 106F334: using guessed type int (__stdcall *WTSDisconnectSession)(_DWORD, _DWORD, _DWORD);
// 106F338: using guessed type int (__stdcall *WinStationConnectW)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 106F33C: using guessed type int (__stdcall *WinStationShadow)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 106F34C: using guessed type int (__stdcall *WTSLogoffSessio)(_DWORD, _DWORD, _DWORD);

//----- (00FD6470) --------------------------------------------------------
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
// 106A389: using guessed type char gbMainWndMinimized;
// 106A393: using guessed type char gbMainWndMinimized1;

//----- (00FD6570) --------------------------------------------------------
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

//----- (00FD65C0) --------------------------------------------------------
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
    sub_FF6020(gpTreeViewListItemParam);
  sub_FBFAA0(hWnd);
  if ( v4 != -1 )
    SendMessageW(v3, 0x1013u, v4, 0);
  return 0;
}

//----- (00FD6660) --------------------------------------------------------
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
  if ( sub_FD7A60(ghWndTreeListView) )
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
// 106A393: using guessed type char gbMainWndMinimized1;

//----- (00FD67F0) --------------------------------------------------------
LRESULT __cdecl CMainWnd::HandleSysCommand(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
  if ( !gConfig.bHideWhenMinimized || wParam != SC_MINIMIZE )
    return DefWindowProcW(hWnd, Msg, wParam, lParam);
  gbMainWndMinimized = 1;
  CMainWnd::Hide(hWnd);
  return 0;
}
// 106A389: using guessed type char gbMainWndMinimized;

//----- (00FD6830) --------------------------------------------------------
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
      sub_FBA880(ghWndTreeListView, wParam, wParam_1, &Rect);
      Rect.right += Rect.left;
      Rect.bottom += Rect.top;
      InvalidateRect(ghWndTreeListView, &Rect, 0);
    }
    result = 0;
  }
  return result;
}

//----- (00FD68E0) --------------------------------------------------------
int sub_FD68E0(wchar_t *Dst, wchar_t *Format, ...)
{
  va_list ArgList; // [esp+10h] [ebp+10h]

  va_start(ArgList, Format);
  return vswprintf_s(Dst, 0x410u, Format, ArgList);
}

//----- (00FD6900) --------------------------------------------------------
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

//----- (00FD69F0) --------------------------------------------------------
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
// 1064E54: using guessed type int gdwVersion;
// 106A098: using guessed type char gNetClrMemoryPerfInfoLoaded;
// 107BA4C: using guessed type int (__stdcall *IsImmersiveProcess)(_DWORD);

//----- (00FD74D0) --------------------------------------------------------
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
      sub_1000410(v5, v4, 0, &v10, &v9, &v8);
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

//----- (00FD7810) --------------------------------------------------------
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

//----- (00FD7930) --------------------------------------------------------
void __cdecl sub_FD7930(int a1)
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

//----- (00FD79B0) --------------------------------------------------------
HBRUSH __cdecl BrushFromColor(COLORREF color, HBRUSH *BrushHandle)
{
  HBRUSH result; // eax

  if ( *BrushHandle )
    DeleteObject(*BrushHandle);
  result = CreateSolidBrush(color);
  *BrushHandle = result;
  return result;
}

//----- (00FD79E0) --------------------------------------------------------
char __cdecl sub_FD79E0(char a1)
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

//----- (00FD7A60) --------------------------------------------------------
BOOL __cdecl sub_FD7A60(HWND hWnd)
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

//----- (00FD7AE0) --------------------------------------------------------
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

//----- (00FD7B70) --------------------------------------------------------
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
// 10610B8: using guessed type int gdwValue_4F10B8[3];
// 1065390: using guessed type char gbFlagsInProcPropSheet;
// 106A098: using guessed type char gNetClrMemoryPerfInfoLoaded;
// 106A11C: using guessed type int gdwRefreshCount;
// 106A389: using guessed type char gbMainWndMinimized;
// 106A90C: using guessed type int gdwRefreshTickCountLast;
// 106F2E8: using guessed type int (__stdcall *GlobalMemoryStatusEx)(_DWORD);

//----- (00FD7F60) --------------------------------------------------------
BOOL __stdcall sub_FD7F60(HWND hDlg, UINT a2, WPARAM a3, LPARAM hData)
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
          v9 = sub_FC6DB0(TokenHandle);
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
          sub_FC3300(&CommandLine);
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
        sub_FC3300(&CommandLine);
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
// 10419EC: using guessed type wchar_t aSpecifyExecuta[22];
// 1041A18: using guessed type wchar_t aExe_0[6];
// 1041A28: using guessed type wchar_t aExecutables[12];
// 1041A6C: using guessed type wchar_t aRunas_0[6];
// 1041A78: using guessed type wchar_t aUnableToExecut[26];
// 106A8F4: using guessed type int (__stdcall *gpfnSHAutoComplete)(struct HWND__ *, unsigned int);
