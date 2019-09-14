
//----- (0101F490) --------------------------------------------------------
int __cdecl sub_101F490(int a1, int a2)
{
  WPARAM v2; // eax
  int result; // eax

  if ( a1 != 101 || (v2 = *(a2 + 12), v2 != 9) && v2 != 36 && v2 != 35 && v2 != 13 )
    result = 0;
  else
    result = Proxy_ListCtrlWndProc(*a2, 256u, v2, 0);
  return result;
}

//----- (0101F4D0) --------------------------------------------------------
int __cdecl sub_101F4D0(HMENU uCtrlID)
{
  HWND v1; // edi
  LRESULT v2; // eax
  tagTREEVIEWLISTITEMPARAM *v3; // edi
  int v4; // eax
  HMENU v5; // eax
  int v6; // ecx
  HMENU v7; // esi
  const WCHAR *v8; // eax
  const WCHAR *v9; // eax
  BOOL v10; // ST10_4
  HMENU v11; // eax
  HMENU v12; // eax
  LVITEMW v14; // [esp+8h] [ebp-68h]
  LVITEMW lParam; // [esp+3Ch] [ebp-34h]
  HMENU hMnua; // [esp+78h] [ebp+8h]

  lParam.mask = 0;
  memset(&lParam.iItem, 0, 0x30u);
  if ( uCtrlID == 101 )
  {
    v1 = ghWndTreeListView;
  }
  else if ( uCtrlID == 102 )
  {
    v1 = ghWndHandlesListCtrl;
  }
  else
  {
    if ( uCtrlID != 104 )
      return 0;
    v1 = ghWndDllsListCtrl;
  }
  lParam.iItem = SendMessageW(v1, LVM_GETNEXTITEM, 0xFFFFFFFF, 2);
  lParam.iSubItem = 0;
  lParam.stateMask = 2;
  lParam.mask = 12;
  v2 = SendMessageW(v1, LVM_GETITEMW, 0, &lParam);
  if ( uCtrlID == 101 )
  {
    if ( v2 == 1 && lParam.state & 2 )
    {
      v3 = lParam.lParam;
      v4 = lParam.lParam->dwProcessId;
      if ( gdwProcessIdSelected != v4 )
      {
        gdwProcessIdSelected = lParam.lParam->dwProcessId;
        UpdateMenuStatus(1, 3);
        v5 = GetMenu(ghMainWnd);
        v6 = v3->ProcessBasePriority;
        v7 = v5;
        hMnua = v5;
        if ( v6 == 4 && !v3->m_ProcessIoPriority )
          v6 = 0;
        sub_105EF00(v5, v6);
        v14.stateMask = 2;
        v14.state = 2;
        SendMessageW(ghWndDllsListCtrl, LVM_SETITEMSTATE, 0, &v14);
        v14.stateMask = 2;
        v14.state = 2;
        SendMessageW(ghWndHandlesListCtrl, LVM_SETITEMSTATE, 0, &v14);
        v8 = L"R&esume";
        if ( SLOBYTE(v3->dwStyle) >= 0 )
          v8 = L"S&uspend";
        ModifyMenuW(v7, 0x9C6Au, 0, 0x9C6Au, v8);
        v9 = L"Un&hide";
        if ( !(v3->dwStyle & 1) )
          v9 = L"&Hide";
        ModifyMenuW(hMnua, 0x9C9Au, 0, 0x9C9Au, v9);
        RefreshMenuWithTreeViewItemStatus(v3);
        RefreshVirusTotalMenuItem(v3);
        if ( gConfig.bShowLowerPane )
          UpdateMenuStatus(0, 5);
        v10 = gConfig.bShowProcessTree == 0;
        v11 = GetMenu(ghMainWnd);
        EnableMenuItem(v11, 0x9C6Cu, v10);
LABEL_23:
        if ( gConfig.bShowLowerPane && !IsWindowVisible(ghFindDlg) && ghEvent2 )
        {
          SetEvent(ghEvent2);
          return 0;
        }
        return 0;
      }
    }
    else
    {
      gdwProcessIdSelected = -1;
      UpdateMenuStatus(0, 3);
      v12 = GetMenu(ghMainWnd);
      EnableMenuItem(v12, 0x9C6Cu, 1u);
      if ( gConfig.bShowLowerPane )
      {
        UpdateMenuStatus(0, 5);
        goto LABEL_23;
      }
    }
  }
  else if ( gConfig.bShowLowerPane )
  {
    if ( v2 == 1 && lParam.state & 2 )
    {
      UpdateMenuStatus(1, 5);
      return 0;
    }
    UpdateMenuStatus(0, 5);
  }
  return 0;
}
// 109E398: using guessed type wchar_t aREsume[8];
// 109E3BC: using guessed type wchar_t aUnHide[8];

//----- (0101F750) --------------------------------------------------------
int __cdecl UpdateListViewContextMenu(UINT nID, HWND hWnd, POINT *pt)
{
  HWND hWndList; // edi
  int v4; // eax
  HMENU v5; // eax
  HMENU v6; // eax
  tagTREEVIEWLISTITEMPARAM *v7; // esi
  HMENU v8; // eax
  DLLINFOLISTITEMPARAM *v9; // esi
  char v10; // bl
  HMENU v11; // eax
  HMENU v12; // edx
  ListItemData1 *v13; // ecx
  const WCHAR *v14; // eax
  CHAR *v15; // eax
  int result; // eax
  HWND hWndParent; // eax
  UINT_PTR uID; // esi
  LVITEMW lParam; // [esp+8h] [ebp-34h]

  lParam.mask = 0;
  memset(&lParam.iItem, 0, 0x30u);
  switch ( nID )
  {
    case IDC_DLG_RUNDLG_BUTTON_BROWSE|IDS_REFERENCES|0x40:
      hWndList = ghWndTreeListView;
      goto LABEL_7;
    case IDC_DLG_RUNDLG_BUTTON_BROWSE|IDS_PARENT|0x40:
      hWndList = ghWndHandlesListCtrl;
      goto LABEL_7;
    case IDM_ABOUT:
      hWndList = ghWndDllsListCtrl;
LABEL_7:
      v4 = SendMessageW(hWndList, LVM_GETNEXTITEM, 0xFFFFFFFF, 2);
      if ( v4 != -1 )
      {
        lParam.iItem = v4;
        lParam.iSubItem = 0;
        lParam.mask = 4;
        if ( SendMessageW(hWndList, LVM_GETITEMW, 0, &lParam) == 1 )
        {
          ghSelectColumnPopupMenuHandle = CreatePopupMenu();
          if ( nID == IDC_TREEVIEW_LIST )
          {
            v5 = GetMenu(ghMainWnd);
            v6 = GetSubMenu(v5, 3);
            v7 = lParam.lParam;
            ghSelectColumnPopupMenuHandle = v6;
            RefreshMenuWithTreeViewItemStatus(lParam.lParam);
            RefreshVirusTotalMenuItem(v7);
          }
          else if ( nID == IDC_LISTCTRL_HANDLES )
          {
            v8 = GetMenu(ghMainWnd);
            ghSelectColumnPopupMenuHandle = GetSubMenu(v8, 5);
          }
          else
          {
            v9 = lParam.lParam;
            v10 = 0;
            v11 = GetMenu(ghMainWnd);
            v12 = GetSubMenu(v11, 5);
            ghSelectColumnPopupMenuHandle = v12;
            v13 = v9->m_ItemData1;
            if ( !v13 || (v14 = L"&Submit to VirusTotal", v13->field_4 != 6) )
              v14 = L"&Check VirusTotal";
            ModifyMenuW(v12, IDM_CHECK_VIRUSTOTALDOTCOM, 0, IDM_CHECK_VIRUSTOTALDOTCOM, v14);
            v15 = v9->m_strPath.pszData;
            if ( v15 && *v15 != '[' )
            {
              v10 = 0;
              if ( sub_1061C10(v9->m_ItemData1) )
                v10 = 1;
            }
            EnableMenuItem(ghSelectColumnPopupMenuHandle, IDM_CHECK_VIRUSTOTALDOTCOM, v10 == 0);
          }
          TrackPopupMenuEx(ghSelectColumnPopupMenuHandle, 0, pt->x, pt->y, ghMainWnd, 0);
          ghSelectColumnPopupMenuHandle = 0;
        }
      }
      return 0;
    case IDC_STATUSBAR:
      ghSelectColumnPopupMenuHandle = CreatePopupMenu();
      AppendMenuW(ghSelectColumnPopupMenuHandle, 0, IDM_SELECT_STATUSBAR_COLUMN, L"&Select Status Bar Columns...");
      TrackPopupMenuEx(ghSelectColumnPopupMenuHandle, 0, pt->x, pt->y, ghMainWnd, 0);
      ghSelectColumnPopupMenuHandle = 0;
      result = 0;
      break;
    default:
      hWndParent = GetParent(*hWnd);
      if ( hWndParent == ghWndTreeListView )
      {
        uID = IDM_SELECT_TREEVIEWLIST_COLUMN;
      }
      else if ( hWndParent == ghWndDllsListCtrl )
      {
        uID = IDM_SELECT_DLLSLIST_COLUMN;
      }
      else
      {
        uID = IDM_VIEW_SELECT_COLUMN;
        if ( hWndParent == ghWndHandlesListCtrl )
          uID = IDM_SELECT_HANDLESLIST_COLUMN;
      }
      ghSelectColumnPopupMenuHandle = CreatePopupMenu();
      AppendMenuW(ghSelectColumnPopupMenuHandle, 0, uID, L"&Select Columns...");
      TrackPopupMenuEx(ghSelectColumnPopupMenuHandle, 0, pt->x, pt->y, ghMainWnd, 0);
      ghSelectColumnPopupMenuHandle = 0;
      result = 0;
      break;
  }
  return result;
}
// 109E374: using guessed type wchar_t aCheckVirustota[18];

//----- (0101F9E0) --------------------------------------------------------
bool __cdecl CTreeList::InitHeaderColumn(HWND hWnd, WPARAM wParam, HWND nItem, char flags)
{
  CTreeList *v4; // eax
  HWND v6; // ebx
  HWND hWndHeader; // eax
  _HD_ITEMW hditem; // [esp+4h] [ebp-2Ch]

  v4 = CTreeList::GetTreeList(hWnd);
  if ( v4 )
    return CTreeList::InitHeaderColumn(v4, nItem, flags != 0);
  v6 = SendMessageW(hWnd, LVM_GETHEADER, 0, 0);
  hditem.mask = 4;
  SendMessageW(v6, HDM_GETITEMW, wParam, &hditem);
  if ( gbBitmapOnRight )
    hditem.fmt &= -0x2601u;                     // -(HDF_BITMAP | HDF_SORTUP | HDF_SORTDOWN | HDF_RIGHT)
  else
    hditem.fmt &= -0x1801u;                     // -(HDF_BITMAP_ON_RIGHT | HDF_SORTDOWN | HDF_SORTDOWN | HDF_RIGHT)
  SendMessageW(v6, HDM_SETITEMW, wParam, &hditem);
  UpdateWindow(v6);
  hWndHeader = SendMessageW(hWnd, LVM_GETHEADER, 0, 0);
  return CTreeList::SetHeaderItem(hWndHeader, nItem, 2 * (flags != 0) - 1);
}
// 10CA8F8: using guessed type char gbBitmapOnRight;

//----- (0101FAA0) --------------------------------------------------------
LRESULT __cdecl sub_101FAA0(HWND hWnd)
{
  DWORD v1; // ecx
  HWND v2; // ebx
  LRESULT v3; // eax
  BOOL v4; // eax
  UINT v5; // ST0C_4
  HMENU v6; // eax
  LPARAM lParam; // [esp+Ch] [ebp-3Ch]
  WPARAM v9; // [esp+10h] [ebp-38h]
  int v10; // [esp+14h] [ebp-34h]
  int v11; // [esp+2Ch] [ebp-1Ch]
  WPARAM wParam; // [esp+40h] [ebp-8h]
  DWORD v13; // [esp+44h] [ebp-4h]

  v1 = -1;
  wParam = hWnd;
  if ( hWnd == 101 )
  {
    v1 = gConfig.dwProcessSortColumn;
    v2 = ghWndTreeListView;
  }
  else if ( hWnd == 102 )
  {
    v1 = gConfig.dwHandleSortColumn;
    v2 = ghWndHandlesListCtrl;
  }
  else
  {
    if ( (hWnd - 102) != 2 )
    {
      v2 = hWnd;
      goto LABEL_9;
    }
    v1 = gConfig.dwDllSortColumn;
    v2 = ghWndDllsListCtrl;
  }
  if ( v1 != -1 )
  {
    if ( hWnd != 101 )
      goto LABEL_14;
    goto LABEL_13;
  }
LABEL_9:
  if ( hWnd != 101 || !gConfig.bShowProcessTree )
    return SendMessageW(v2, 0xBu, 1u, 0);
LABEL_13:
  byte_10C53B5 = 1;
LABEL_14:
  v13 = v1;
  SendMessageW(v2, 0x1030u, &wParam, PropProcThreadsSortCallback);
  if ( hWnd == 101 )
  {
    if ( gConfig.bShowNewProcesses )
    {
      lParam = 4;
      v10 = 0;
      v9 = 0;
      if ( SendMessageW(ghWndTreeListView, 0x1004u, 0, 0) > 0 )
      {
        while ( 1 )
        {
          SendMessageW(ghWndTreeListView, 0x104Bu, 0, &lParam);
          if ( *(v11 + 16) == 2 && !*(v11 + 20) )
            break;
          ++v9;
          v3 = SendMessageW(ghWndTreeListView, 0x1004u, 0, 0);
          if ( v9 >= v3 )
            goto LABEL_22;
        }
        SendMessageW(ghWndTreeListView, 0x1013u, v9, 0);
      }
    }
LABEL_22:
    byte_10C53B5 = 0;
    v4 = !gConfig.bShowProcessTree || SendMessageW(v2, 0x100Cu, 0xFFFFFFFF, 2) == -1;
    v5 = v4;
    v6 = GetMenu(ghMainWnd);
    EnableMenuItem(v6, 0x9C6Cu, v5);
  }
  return SendMessageW(v2, 0xBu, 1u, 0);
}
// 10C53B5: using guessed type char byte_10C53B5;

//----- (0101FC20) --------------------------------------------------------
BOOL __stdcall DlgColumnSets(HWND hWndIn, UINT msg, WPARAM nID, NMLVDISPINFOW *lParam)
{
  HWND hWndList; // edi
  int nCurItem; // ebx
  tagTREEVIEWLISTITEMPARAM *v6; // ecx
  BOOL result; // eax
  LRESULT v8; // esi
  signed int i; // esi
  int v10; // ST0C_4
  HMENU v11; // eax
  HMENU v12; // eax
  HMENU v13; // eax
  void (__stdcall *SendMessageW_1)(HWND, UINT, WPARAM, LPARAM); // esi
  int nColumn; // ebx
  int v16; // eax
  int v17; // ST08_4
  HMENU v18; // eax
  HMENU v19; // eax
  HMENU v20; // eax
  LRESULT v21; // ST10_4
  void (__stdcall *SendMessageW)(HWND, UINT, WPARAM, LPARAM); // ebx
  tagTREEVIEWLISTITEMPARAM *Index; // esi
  CRegVar *regVar; // ebx
  int nLength; // eax
  UINT code; // eax
  LRESULT nCurItem2; // esi
  HWND v28; // eax
  HWND v29; // eax
  BOOL v30; // eax
  BOOL v31; // ST14_4
  HWND v32; // eax
  BOOL v33; // eax
  BOOL v34; // ST14_4
  HWND v35; // eax
  WCHAR *v36; // eax
  int v37; // ST10_4
  LVCOLUMNW ColumnInfo; // [esp+Ch] [ebp-44A4h]
  LVITEMW Item2; // [esp+2Ch] [ebp-4484h]
  LVITEMW ItemState; // [esp+60h] [ebp-4450h]
  LVITEMW ItemInfo; // [esp+94h] [ebp-441Ch]
  LVITEMW Item; // [esp+C8h] [ebp-43E8h]
  HWND hWndList_1; // [esp+FCh] [ebp-43B4h]
  HWND hWnd; // [esp+100h] [ebp-43B0h]
  CRegVar tempRegVar[10]; // [esp+104h] [ebp-43ACh]
  WCHAR szMenuName[520]; // [esp+3C8Ch] [ebp-824h]
  WCHAR szText[260]; // [esp+409Ch] [ebp-414h]
  WCHAR szName[260]; // [esp+42A4h] [ebp-20Ch]

  hWnd = hWndIn;
  ColumnInfo.mask = 0;
  _mm_storeu_si128(&ColumnInfo.fmt, 0i64);
  ColumnInfo.iOrder = 0;
  *&ColumnInfo.iSubItem = 0i64;
  ItemInfo.mask = 0;
  memset(&ItemInfo.iItem, 0, 0x30u);
  hWndList = GetDlgItem(hWndIn, IDC_DLG_COLUMN_SETS_LIST);
  hWndList_1 = hWndList;
  if ( msg == WM_NOTIFY )
  {
    code = lParam->hdr.code;
    if ( code != LVN_ENDLABELEDITW )
    {
      if ( code == LVN_BEGINLABELEDITW )
      {
        sbEditFlags = 1;
      }
      else if ( code == LVN_ITEMCHANGED && !sbEditFlags )
      {
        nCurItem2 = ::SendMessageW(hWndList, LVM_GETNEXTITEM, 0xFFFFFFFF, LVFI_STRING);
        v28 = GetDlgItem(hWnd, IDC_DLG_COLUMN_SETS_BUTTON_RENAME);
        EnableWindow(v28, nCurItem2 != -1);
        v29 = GetDlgItem(hWnd, IDC_DLG_COLUMN_SETS_BUTTON_DELETE);
        EnableWindow(v29, nCurItem2 != -1);
        v30 = nCurItem2 != -1 && nCurItem2;
        v31 = v30;
        v32 = GetDlgItem(hWnd, IDC_DLG_COLUMN_SETS_BUTTON_MOVEUP);
        EnableWindow(v32, v31);
        v33 = nCurItem2 != -1 && nCurItem2 != ::SendMessageW(hWndList, LVM_GETITEMCOUNT, 0, 0) - 1;
        v34 = v33;
        v35 = GetDlgItem(hWnd, IDC_DLG_COLUMN_SETS_BUTTON_MOVEDOWN);
        EnableWindow(v35, v34);
      }
      return 0;
    }
    v36 = lParam->item.pszText;
    sbEditFlags = 0;
    if ( !v36 )
      return 0;
    ItemState.pszText = v36;
    v37 = lParam->item.iItem;
    ItemState.iSubItem = 0;
    ::SendMessageW(hWndList, LVM_SETITEMTEXTW, v37, &ItemState);
    result = 1;
  }
  else
  {
    if ( msg != WM_INITDIALOG )
    {
      if ( msg == 273 )
      {
        if ( nID <= IDC_DLG_COLUMN_SETS_BUTTON_DELETE )
        {
          if ( nID == IDC_DLG_COLUMN_SETS_BUTTON_DELETE )
          {
            v8 = ::SendMessageW(hWndList, LVM_GETNEXTITEM, 0xFFFFFFFF, 2);
            ::SendMessageW(hWndList, LVM_DELETEITEM, v8, 0);
            if ( v8 )
              --v8;
            ItemState.stateMask = 3;
            ItemState.state = 3;
            ::SendMessageW(hWndList, LVM_SETITEMSTATE, v8, &ItemState);
            return 0;
          }
          if ( nID != 2 )
          {
            // if(nID<=IDC_DLG_COLUMN_SETS_BUTTON_MOVEDOWN)
            if ( nID - 1210 <= 1 )
            {
              nCurItem = ::SendMessageW(hWndList, LVM_GETNEXTITEM, 0xFFFFFFFF, 2);
              Item.mask = 5;
              if ( nID == IDC_DLG_COLUMN_SETS_BUTTON_MOVEUP )
                Item.iItem = nCurItem - 1;
              else
                Item.iItem = nCurItem + 1;
              Item.cchTextMax = 259;
              Item.pszText = szName;
              Item.iSubItem = 0;
              ::SendMessageW(hWndList, LVM_GETITEMW, 0, &Item);
              Item2.mask = 5;
              Item2.pszText = szText;
              Item2.iItem = nCurItem;
              Item2.cchTextMax = 259;
              Item2.iSubItem = 0;
              ::SendMessageW(hWndList, LVM_GETITEMW, 0, &Item2);
              v6 = Item.lParam;
              Item.pszText = szText;
              Item2.pszText = szName;
              Item.lParam = Item2.lParam;
              Item2.lParam = v6;
              ::SendMessageW(hWndList, LVM_SETITEMW, 0, &Item);
              ::SendMessageW(hWndList, LVM_SETITEMW, 0, &Item2);
              ItemState.stateMask = 3;
              ItemState.state = 3;
              ::SendMessageW(hWndList, LVM_SETITEMSTATE, Item.iItem, &ItemState);
            }
            return 0;
          }
          goto LABEL_28;
        }
        if ( nID == IDC_DLG_COLUMN_SETS_BUTTON_RENAME )
        {
          SetFocus(hWndList);
          v21 = ::SendMessageW(hWndList, LVM_GETNEXTITEM, 0xFFFFFFFF, 2);
          ::SendMessageW(hWndList, LVM_EDITLABELW, v21, 0);
          return 0;
        }
        if ( nID == IDC_DLG_COLUMN_SETS_BUTTON_OK )
        {
          for ( i = 0; i < gConfig.dwNumColumnsets; ++i )
          {
            v10 = gdwMenuItemPosLast;
            v11 = GetMenu(ghMainWnd);
            v12 = GetSubMenu(v11, 2);
            v13 = GetSubMenu(v12, v10);
            DeleteMenu(v13, 0, MF_BYPOSITION);
          }
          memmove_0(tempRegVar, gConfig.strMenuCulumnSet, 15240u);
          SendMessageW_1 = ::SendMessageW;
          nColumn = 0;
          gConfig.dwNumColumnsets = ::SendMessageW(hWndList, LVM_GETITEMCOUNT, 0, 0);
          if ( gConfig.dwNumColumnsets > 0 )
          {
            do
            {
              Item.mask = 5;
              Item.pszText = szName;
              Item.iItem = nColumn;
              Item.cchTextMax = 259;
              Item.iSubItem = 0;
              SendMessageW_1(hWndList, LVM_GETITEMW, 0, &Item);
              qmemcpy(
                &gConfig.strMenuCulumnSet[nColumn],
                &tempRegVar[Item.lParam],
                sizeof(gConfig.strMenuCulumnSet[nColumn]));
              wcscpy_s(gConfig.strMenuCulumnSet[nColumn].ColumnSetName, MAX_PATH, szName);
              if ( nColumn >= 10 )
              {
                wcscpy_s(szMenuName, 0x208u, szName);
              }
              else
              {
                if ( nColumn == 9 )
                  v16 = 0;
                else
                  v16 = nColumn + 1;
                MakeHandlePropSheetCaption(szMenuName, L"%s\tCtrl+%d", szName, v16);
              }
              v17 = gdwMenuItemPosLast;
              v18 = GetMenu(ghMainWnd);
              v19 = GetSubMenu(v18, 2);
              v20 = GetSubMenu(v19, v17);
              AppendMenuW(v20, 0, nColumn + IDM_PROCESS_PRIORITY_BASE, szMenuName);
              hWndList = hWndList_1;
              ++nColumn;
              SendMessageW_1 = ::SendMessageW;
            }
            while ( nColumn < gConfig.dwNumColumnsets );
          }
LABEL_28:
          EndDialog(hWnd, 0);
          return 0;
        }
      }
      return 0;
    }
    // WM_INITDIALOG
    SendMessageW = ::SendMessageW;
    sbEditFlags = 0;
    ::SendMessageW(hWndList, LVM_SETEXTENDEDLISTVIEWSTYLE, LVS_EX_FULLROWSELECT, LVS_EX_FULLROWSELECT);
    ::SendMessageW(hWndList, LVM_INSERTCOLUMNW, 0, &ColumnInfo);
    Index = 0;
    ItemInfo.mask = 0xD;                        // LVIF_TEXT|LVIF_IMAGE|LVIF_PARAM|LVIF_STATE
    ItemInfo.iItem = 0x7FFFFFFF;
    ItemInfo.iSubItem = 0;
    ItemInfo.state = 0;
    ItemInfo.stateMask = 0;
    if ( gConfig.dwNumColumnsets > 0 )
    {
      regVar = gConfig.strMenuCulumnSet;
      do
      {
        ItemInfo.pszText = regVar;
        nLength = lstrlenW(regVar->ColumnSetName);
        ItemInfo.iImage = 0;
        ItemInfo.cchTextMax = nLength + 1;
        ItemInfo.lParam = Index;
        ::SendMessageW(hWndList, LVM_INSERTITEMW, 0, &ItemInfo);
        Index = (Index + 1);
        ++regVar;
      }
      while ( Index < gConfig.dwNumColumnsets );
      SendMessageW = ::SendMessageW;
    }
    SendMessageW(hWndList, LVM_SETCOLUMNWIDTH, 0, 0xFFFE);// LVSCW_AUTOSIZE
    ItemState.stateMask = 3;                    // LVIS_SELECTED | LVIS_FOCUSED
    ItemState.state = 3;                        // LVIS_SELECTED | LVIS_FOCUSED
    SendMessageW(hWndList, LVM_SETITEMSTATE, 0, &ItemState);
    SetFocus(hWndList);
    result = 1;
  }
  return result;
}
// 10C9E70: using guessed type char sbEditFlags;
// 101FF58: user specified stroff has not been processed: CRegVar offset 1524

//----- (010202A0) --------------------------------------------------------
BOOL __cdecl CMainWnd::Draw(int nColumn, HDC hdc, COLORREF *pColorReturned)
{
  WORD v3; // cx
  int v4; // eax
  __int32 v5; // eax
  double v6; // xmm0_8
  WORD v7; // cx
  COLORREF v8; // eax
  bool v9; // cf
  COLORREF v11; // [esp-10h] [ebp-2Ch]
  double v12; // [esp+0h] [ebp-1Ch]
  double pArg1; // [esp+8h] [ebp-14h]
  WORD pwHue[2]; // [esp+10h] [ebp-Ch]
  WORD pwSaturation[2]; // [esp+14h] [ebp-8h]
  WORD pwLuminance[2]; // [esp+18h] [ebp-4h]

  v3 = 0;
  *pwLuminance = 0;
  if ( !gConfig.bShowColumnHeatmaps )
    return v3 != 0;
  v4 = gConfig.dwProcessColumnMap[nColumn];
  if ( v4 > 1063 )
  {
    if ( v4 != 1650 )
      return v3 != 0;
    GraphData_QueryData(gpGraphInfoOfGPU, &pArg1, 0);
    v6 = pArg1 / gpGraphInfoOfGPU->m_dbMemorySize;
    v11 = 0x8080FF;
  }
  else if ( v4 == 1063 )
  {
    GraphData_QueryData(gpGraphInfoOfPhysicalMemory, &pArg1, 0);
    v6 = pArg1 / gpGraphInfoOfPhysicalMemory->m_dbMemorySize;
    v11 = 0x4080FF;
  }
  else
  {
    v5 = v4 - IDS_CPU;
    if ( !v5 )
    {
      GraphData_QueryData(gpGraphInfoOfCPU, &pArg1, 0);
      v12 = pArg1 / gpGraphInfoOfCPU->m_dbMemorySize;
      if ( pArg1 / gpGraphInfoOfCPU->m_dbMemorySize > 100.0 )
        v12 = db_onehundred;
      ColorRGBToHLS(0x3C943Cu, pwHue, pwLuminance, pwSaturation);
      goto LABEL_14;
    }
    if ( v5 != 5 )
      return v3 != 0;
    GraphData_QueryData(gpGraphInfoOfMemory, &pArg1, 0);
    v6 = pArg1 / gpGraphInfoOfMemory->m_dbMemorySize;
    v11 = 0x82A0;
  }
  v12 = v6;
  ColorRGBToHLS(v11, pwHue, pwLuminance, pwSaturation);
LABEL_14:
  v3 = pwLuminance[0];
  if ( pwLuminance[0] )
  {
    v7 = 5 * (46 - (v12 * 100.0) / 5);
    if ( v12 == 0.0 )
      v7 = 230;
    *pwLuminance = v7;
    v8 = ColorHLSToRGB(pwHue[0], v7, pwSaturation[0]);
    v9 = pwLuminance[0] < 110u;
    *pColorReturned = v8;
    if ( v9 )
      SetTextColor(hdc, 0xFFFFFFu);
    else
      SetTextColor(hdc, 0);
    SetBkColor(hdc, *pColorReturned);
    v3 = pwLuminance[0];
  }
  return v3 != 0;
}
// 109CDC0: using guessed type double db_onehundred;

//----- (01020490) --------------------------------------------------------
HCURSOR __cdecl CMainWnd::GetDynamicCursor(int a1, int nIndex)
{
  int v2; // eax
  HCURSOR result; // eax

  if ( gConfig.dwProcessColumnMap[nIndex] == IDS_VIRUSTOTAL
    && (CTreeList::GetTreeList(ghWndTreeListView), v2 = sub_FFE5D0(a1), sub_1061820(*(v2 + 0x34C))) )
  {
    result = LoadCursorW(ghInstance, L"HAND");
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (010204F0) --------------------------------------------------------
char __cdecl RedrawColumn(int fRedraw, HWND hWnd, int uID, WPARAM wParam)
{
  char bRet; // bl
  LPARAM dwIndex; // eax

  bRet = 0;
  if ( !fRedraw )
    return 0;
  if ( hWnd == ghWndTreeListView )
  {
    if ( gConfig.dwProcessSortColumn == -1
      || gConfig.bShowProcessTree
      || gConfig.dwProcessColumnMap[gConfig.dwProcessSortColumn] != uID )
    {
      if ( !gbMainWndMinimized )
      {
        dwIndex = 0;
        if ( gConfig.dwProcessColumnCount > 0 )
        {
          while ( gConfig.dwProcessColumnMap[dwIndex] != uID )
          {
            if ( ++dwIndex >= gConfig.dwProcessColumnCount )
              return 0;
          }
          // 尝试发送消息进行指定COLUMN的刷�?
          PostMessageW(ghMainWnd, WM_MSG_7EB, wParam, dwIndex);
        }
      }
    }
    else
    {
      bRet = 1;
      if ( gConfig.dwProcessColumnCount < 16 && !gConfig.bShowLowerPane )
      {
        SendMessageW(hWnd, WM_SETREDRAW, 0, 0);
        return 1;
      }
    }
  }
  return bRet;
}
// 10CA389: using guessed type char gbMainWndMinimized;

//----- (010205A0) --------------------------------------------------------
BOOL __stdcall DlgColumnSetSave(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
  double v4; // st6
  double v5; // st7
  HWND hWnd_1; // ecx
  HWND hWndCB_1; // eax
  signed int index_1; // ebx
  CRegVar *var_1; // esi
  int v11; // eax
  int v12; // ST08_4
  HMENU v13; // eax
  HMENU hViewMenu; // eax
  HMENU hSubMenu; // eax
  int index; // ebx
  DWORD dwNumColumnsets; // eax
  signed int dwColumnIndex; // esi
  CRegVar *var; // edi
  bool found; // zf
  void (__stdcall *SendMessageW)(HWND, UINT, WPARAM, LPARAM); // esi
  HWND hWndCB; // ebx
  signed int dwColumn; // edi
  CRegVar *pVar; // esi
  WCHAR szNewItem[520]; // [esp+10h] [ebp-61Ch]
  __int16 String[260]; // [esp+420h] [ebp-20Ch]

  hWnd_1 = hWnd;
  if ( uMsg == WM_INITDIALOG )
  {
    index = 0;
    do
    {
      swprintf(String, L"Column Set %d", index);
      dwNumColumnsets = gConfig.dwNumColumnsets;
      dwColumnIndex = 0;
      if ( gConfig.dwNumColumnsets > 0 )
      {
        var = gConfig.strMenuCulumnSet;
        while ( 1 )
        {
          found = _wcsicmp(String, var->ColumnSetName) == 0;
          dwNumColumnsets = gConfig.dwNumColumnsets;
          if ( found )
            break;
          ++dwColumnIndex;
          ++var;
          if ( dwColumnIndex >= gConfig.dwNumColumnsets )
            goto LABEL_31;
        }
        ++index;
      }
LABEL_31:
      ;
    }
    while ( dwColumnIndex != dwNumColumnsets );
    SendMessageW = ::SendMessageW;
    hWndCB = GetDlgItem(hWnd, IDC_DLG_COLUMN_SET_SAVE_COMBO);
    ::SendMessageW(hWndCB, CB_ADDSTRING, 0, String);
    dwColumn = 0;
    if ( gConfig.dwNumColumnsets > 0 )
    {
      pVar = gConfig.strMenuCulumnSet;
      do
      {
        ::SendMessageW(hWndCB, CB_ADDSTRING, 0, pVar);
        ++dwColumn;
        ++pVar;
      }
      while ( dwColumn < gConfig.dwNumColumnsets );
      SendMessageW = ::SendMessageW;
    }
    SendMessageW(hWndCB, CB_SETCURSEL, 0, 0);
    SendMessageW(hWndCB, CB_SETEDITSEL, 0, 0xFFFF0000);
  }
  else
  {
    if ( uMsg != WM_COMMAND )
      return 0;
    if ( wParam != 1 )
    {
      if ( wParam != 2 )
        return 0;
      goto LABEL_22;
    }
    hWndCB_1 = GetDlgItem(hWnd, IDC_DLG_COLUMN_SET_SAVE_COMBO);
    GetWindowTextW(hWndCB_1, String, 260);
    index_1 = 0;
    if ( gConfig.dwNumColumnsets <= 0 )
      goto LABEL_13;
    var_1 = gConfig.strMenuCulumnSet;
    do
    {
      if ( !_wcsicmp(String, var_1->ColumnSetName) )
        break;
      ++index_1;
      ++var_1;
    }
    while ( index_1 < gConfig.dwNumColumnsets );
    if ( index_1 != 10 )
    {
LABEL_13:
      UpdateWindowPlacement(ghMainWnd, 0);
      qmemcpy(&gConfig.strMenuCulumnSet[index_1], gConfig.szColumnSetName, sizeof(gConfig.strMenuCulumnSet[index_1]));
      wcscpy_s(gConfig.strMenuCulumnSet[index_1].ColumnSetName, MAX_PATH, String);
      if ( index_1 == gConfig.dwNumColumnsets )
      {
        if ( index_1 >= 10 )
        {
          wcscpy_s(szNewItem, 0x208u, String);
        }
        else
        {
          if ( index_1 == 9 )
            v11 = 0;
          else
            v11 = index_1 + 1;
          MakeHandlePropSheetCaption(szNewItem, L"%s\tCtrl+%d", String, v11);
        }
        v12 = gdwMenuItemPosLast;
        v13 = GetMenu(ghMainWnd);
        hViewMenu = GetSubMenu(v13, 2);
        hSubMenu = GetSubMenu(hViewMenu, v12);
        AppendMenuW(hSubMenu, 0, index_1 + IDM_PROCESS_PRIORITY_BASE, szNewItem);
        ++gConfig.dwNumColumnsets;
      }
      Command_SetColumn(v5, v4, 0, index_1 - 0x6127);
      hWnd_1 = hWnd;
LABEL_22:
      EndDialog(hWnd_1, 0);
      return 0;
    }
    while ( MessageBoxW(
              ghMainWnd,
              L"You must delete at least one column set before you can save a new column set.\n"
               "Do you want to open the Column Set Organizer dialog?",
              L"Process Explorer Warning",
              // MB_ICONEXCLAMATION | MB_YESNO
              0x34u) != IDNO )
    {
      DialogBoxParamW(ghInstance, L"COLUMNSETS", ghMainWnd, DlgColumnSets, 0);
      index_1 = gConfig.dwNumColumnsets;
      if ( gConfig.dwNumColumnsets != 10 )
        goto LABEL_13;
    }
  }
  return 1;
}

//----- (010208A0) --------------------------------------------------------
void __cdecl UpdateWindowPlacement(HWND hWnd, char bSave)
{
  WPARAM v2; // ebx
  unsigned int iBand; // esi
  HKEY v4; // ebx
  LRESULT v5; // eax
  int v6; // edx
  signed int v7; // ecx
  __m128i v8; // xmm1
  char *v9; // esi
  int v10; // ebx
  unsigned int v11; // eax
  __m128i v12; // xmm0
  int i; // ecx
  int v14; // esi
  int v15; // eax
  DWORD v16; // ecx
  int index; // esi
  HKEY v18; // ebx
  LRESULT v19; // eax
  signed int dwHandleColumnCount; // edx
  signed int v21; // ecx
  __m128i v22; // xmm1
  char *v23; // esi
  signed int v24; // ebx
  unsigned int v25; // eax
  __m128i v26; // xmm0
  signed int j; // ecx
  signed int dwIndex_1; // esi
  DWORD v29; // eax
  DWORD dwHandleSortColumn; // ecx
  signed int nColumn; // esi
  HKEY v32; // ebx
  LRESULT nOrderCount; // eax
  signed int dwDllColumnCount_1; // edx
  signed int dwIndex; // ecx
  __m128i v36; // xmm1
  char *v37; // esi
  signed int dwDllColumnCount; // ebx
  unsigned int v39; // eax
  __m128i v40; // xmm0
  signed int k; // ecx
  signed int v42; // esi
  DWORD v43; // eax
  DWORD v44; // ecx
  signed int v45; // esi
  int v46; // esi
  CRegVar *v47; // edi
  char v48[18400]; // [esp+8h] [ebp-4B3Ch]
  REBARBANDINFOW BandInfo; // [esp+47E8h] [ebp-35Ch]
  tagRegKeyInfo pThis; // [esp+4838h] [ebp-30Ch]
  int arrIDs[4]; // [esp+49C0h] [ebp-184h]
  char v52[368]; // [esp+49D0h] [ebp-174h]

  memmove_0(v48, &gConfig, sizeof(CRegSettings));
  gConfig.WindowPlacement[0].length = 44;
  GetWindowPlacement(hWnd, gConfig.WindowPlacement);
  if ( gConfig.bShowLowerPane )
    gConfig.dbSavedDivider = gConfig.dbDivider;
  if ( ghFindDlg )
  {
    gConfig.WindowPlacement[1].length = 44;
    GetWindowPlacement(ghFindDlg, &gConfig.WindowPlacement[1]);
  }                                             // ?gdwRefreshMenuIDLast@@3IA
  if ( !gConfig.dwRefreshRate )
  {
    switch ( gdwRefreshMenuIDLast )
    {
      case IDM_VIEW_UPDATESPEED_TWO_SECONDS:
        gConfig.dwRefreshRate = 2000;
        break;
      case IDM_VIEW_UPDATESPEED_FIVE_SECONDS:
        gConfig.dwRefreshRate = 5000;
        break;
      case IDM_VIEW_UPDATESPEED_TEN_SECONDS:
        gConfig.dwRefreshRate = 10000;
        break;
      case IDM_VIEW_UPDATESPEED_HALF_SECONDS:
        gConfig.dwRefreshRate = 500;
        break;
      default:
        gConfig.dwRefreshRate = 1000;
        break;
    }
  }
  v2 = 0;
  BandInfo.cbSize = sizeof(REBARBANDINFOW);
  BandInfo.fMask = 0x141;                       // RBBIM_ID|RBBIM_SIZE|RBBIM_STYLE
  iBand = 0;
  do
  {
    SendMessageW(ghWndReBar, RB_GETBANDINFOW, v2, &BandInfo);
    gConfig.ToolBandInfo[iBand].nWidth = MulDiv(BandInfo.cx, 96, gLogPixelSize.x);
    ++v2;
    gConfig.ToolBandInfo[iBand].nID = BandInfo.wID;
    gConfig.ToolBandInfo[iBand].fBreak = BandInfo.fStyle & RBBS_BREAK;
    ++iBand;
  }
  while ( iBand < 8 );
  gConfig.wProcessImageColumnWidth = SendMessageW(ghWndTreeListView, LVM_GETCOLUMNWIDTH, 0, 0);
  v4 = gConfig.dwProcessColumnMap[gConfig.dwProcessSortColumn];
  pThis.hKey = gConfig.dwProcessColumnMap[gConfig.dwProcessSortColumn];
  v5 = SendMessageW(ghWndTreeListView, 0x103Bu, gConfig.dwProcessColumnCount, arrIDs);
  v6 = gConfig.dwProcessColumnCount;
  if ( !v5 )
  {
    v7 = 0;
    if ( gConfig.dwProcessColumnCount > 0 )
    {
      if ( gConfig.dwProcessColumnCount >= 8u )
      {
        v8 = _mm_load_si128(&gIntArray);
        v9 = v52;
        v10 = gConfig.dwProcessColumnCount - gConfig.dwProcessColumnCount % 8;
        do
        {
          v11 = v7 + 4;
          v9 += 32;
          v12 = _mm_add_epi32(_mm_shuffle_epi32(_mm_cvtsi32_si128(v7), 0), v8);
          v7 += 8;
          _mm_storeu_si128(v9 - 3, v12);
          _mm_storeu_si128(v9 - 2, _mm_add_epi32(_mm_shuffle_epi32(_mm_cvtsi32_si128(v11), 0), v8));
        }
        while ( v7 < v10 );
        v4 = pThis.hKey;
      }
      for ( ; v7 < v6; ++v7 )
        arrIDs[v7] = v7;
    }
  }
  for ( i = 0; i < v6; ++i )
    *(&pThis.nLength + i) = gConfig.dwProcessColumnMap[arrIDs[i]];
  v14 = 0;
  if ( v6 > 0 )
  {
    do
    {
      v15 = *(&pThis.nLength + v14);
      gConfig.dwProcessColumnMap[v14] = v15;
      v16 = gConfig.dwProcessSortColumn;
      v6 = gConfig.dwProcessColumnCount;
      if ( v15 == v4 )
        v16 = v14;
      ++v14;
      gConfig.dwProcessSortColumn = v16;
    }
    while ( v14 < gConfig.dwProcessColumnCount );
  }
  index = 0;
  if ( v6 > 0 )
  {
    do
    {
      gConfig.dwProcessColumns[index] = SendMessageW(ghWndTreeListView, 0x101Du, arrIDs[index], 0);
      ++index;
    }
    while ( index < gConfig.dwProcessColumnCount );
  }
  v18 = gConfig.dwIdsOfHandleColumnMap[gConfig.dwHandleSortColumn];
  pThis.hKey = gConfig.dwIdsOfHandleColumnMap[gConfig.dwHandleSortColumn];
  v19 = SendMessageW(ghWndHandlesListCtrl, 0x103Bu, gConfig.dwHandleColumnCount, arrIDs);
  dwHandleColumnCount = gConfig.dwHandleColumnCount;
  if ( !v19 )
  {
    v21 = 0;
    if ( gConfig.dwHandleColumnCount > 0 )
    {
      if ( gConfig.dwHandleColumnCount >= 8 )
      {
        v22 = _mm_load_si128(&gIntArray);
        v23 = v52;
        v24 = gConfig.dwHandleColumnCount - gConfig.dwHandleColumnCount % 8;
        do
        {
          v25 = v21 + 4;
          v23 += 32;
          v26 = _mm_add_epi32(_mm_shuffle_epi32(_mm_cvtsi32_si128(v21), 0), v22);
          v21 += 8;
          _mm_storeu_si128(v23 - 3, v26);
          _mm_storeu_si128(v23 - 2, _mm_add_epi32(_mm_shuffle_epi32(_mm_cvtsi32_si128(v25), 0), v22));
        }
        while ( v21 < v24 );
        v18 = pThis.hKey;
      }
      for ( ; v21 < dwHandleColumnCount; ++v21 )
        arrIDs[v21] = v21;
    }
  }
  for ( j = 0; j < dwHandleColumnCount; ++j )
    *(&pThis.nLength + j) = gConfig.dwIdsOfHandleColumnMap[arrIDs[j]];
  dwIndex_1 = 0;
  if ( dwHandleColumnCount > 0 )
  {
    do
    {
      v29 = *(&pThis.nLength + dwIndex_1);
      gConfig.dwIdsOfHandleColumnMap[dwIndex_1] = v29;
      dwHandleSortColumn = gConfig.dwHandleSortColumn;
      dwHandleColumnCount = gConfig.dwHandleColumnCount;
      if ( v29 == v18 )
        dwHandleSortColumn = dwIndex_1;
      ++dwIndex_1;
      gConfig.dwHandleSortColumn = dwHandleSortColumn;
    }
    while ( dwIndex_1 < gConfig.dwHandleColumnCount );
  }
  nColumn = 0;
  if ( dwHandleColumnCount > 0 )
  {
    do
    {
      gConfig.dwHandleColumns[nColumn] = SendMessageW(ghWndHandlesListCtrl, LVM_GETCOLUMNWIDTH, arrIDs[nColumn], 0);
      ++nColumn;
    }
    while ( nColumn < gConfig.dwHandleColumnCount );
  }
  v32 = gConfig.dwDllColumnMap[gConfig.dwDllSortColumn];
  pThis.hKey = gConfig.dwDllColumnMap[gConfig.dwDllSortColumn];
  nOrderCount = SendMessageW(ghWndDllsListCtrl, LVM_GETCOLUMNORDERARRAY, gConfig.dwDllColumnCount, arrIDs);
  dwDllColumnCount_1 = gConfig.dwDllColumnCount;
  if ( !nOrderCount )
  {
    dwIndex = 0;
    if ( gConfig.dwDllColumnCount > 0 )
    {
      if ( gConfig.dwDllColumnCount >= 8 )
      {
        v36 = _mm_load_si128(&gIntArray);
        v37 = v52;
        dwDllColumnCount = gConfig.dwDllColumnCount - gConfig.dwDllColumnCount % 8;
        do
        {
          v39 = dwIndex + 4;
          v37 += 32;
          v40 = _mm_add_epi32(_mm_shuffle_epi32(_mm_cvtsi32_si128(dwIndex), 0), v36);
          dwIndex += 8;
          _mm_storeu_si128(v37 - 3, v40);
          _mm_storeu_si128(v37 - 2, _mm_add_epi32(_mm_shuffle_epi32(_mm_cvtsi32_si128(v39), 0), v36));
        }
        while ( dwIndex < dwDllColumnCount );
        v32 = pThis.hKey;
      }
      for ( ; dwIndex < dwDllColumnCount_1; ++dwIndex )
        arrIDs[dwIndex] = dwIndex;
    }
  }
  for ( k = 0; k < dwDllColumnCount_1; ++k )
    *(&pThis.nLength + k) = gConfig.dwDllColumnMap[arrIDs[k]];
  v42 = 0;
  if ( dwDllColumnCount_1 > 0 )
  {
    do
    {
      v43 = *(&pThis.nLength + v42);
      gConfig.dwDllColumnMap[v42] = v43;
      v44 = gConfig.dwDllSortColumn;
      dwDllColumnCount_1 = gConfig.dwDllColumnCount;
      if ( v43 == v32 )
        v44 = v42;
      ++v42;
      gConfig.dwDllSortColumn = v44;
    }
    while ( v42 < gConfig.dwDllColumnCount );
  }
  v45 = 0;
  if ( dwDllColumnCount_1 > 0 )
  {
    do
    {
      gConfig.dwDllColumns[v45] = SendMessageW(ghWndDllsListCtrl, 0x101Du, arrIDs[v45], 0);
      ++v45;
    }
    while ( v45 < gConfig.dwDllColumnCount );
  }
  if ( bSave )
  {
    pThis.szKeyName = _wcsdup(L"Software\\Sysinternals\\Process Explorer");
    gConfig.UnicodeFont.lfHeight = -MulDiv(gConfig.UnicodeFont.lfHeight, 72, gLogPixelSize.y);
    SaveConfigItemToRegistry(&pThis, gConfigItems);
    memmove_0(&gConfig, v48, 0x47E0u);
    v46 = 0;
    if ( gConfig.dwNumColumnsets > 0 )
    {
      v47 = gConfig.strMenuCulumnSet;
      do
      {
        RegVar_ReadWrite(1, v46++, v47);
        ++v47;
      }
      while ( v46 < gConfig.dwNumColumnsets );
    }
    free(pThis.szKeyName);
  }
}
// 109EA50: using guessed type RECT gIntArray;
// 10BE10C: using guessed type int gdwRefreshMenuIDLast;
// 10208A0: using guessed type LPARAM arrIDs[4];

//----- (01020E90) --------------------------------------------------------
int __stdcall PropColumnSetsForDlls(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
  HWND v4; // edi
  HWND v5; // eax
  BOOL v6; // ST0C_4
  HWND v7; // eax
  BOOL v8; // ST0C_4
  HWND v9; // eax
  BOOL v10; // ST0C_4
  HWND v11; // eax
  signed int v12; // esi
  UINT (__stdcall *v14)(HWND, int); // eax
  signed int i; // esi
  DWORD v16; // ecx
  unsigned int v17; // esi
  LPARAM lParama; // [esp+Ch] [ebp-ACh]
  char *v19; // [esp+18h] [ebp-A0h]
  int v20; // [esp+1Ch] [ebp-9Ch]
  LPARAM v21; // [esp+2Ch] [ebp-8Ch]
  HWND v22; // [esp+30h] [ebp-88h]
  char v23; // [esp+34h] [ebp-84h]

  v21 = lParam;
  v4 = hWnd;
  v22 = hWnd;
  if ( msg == 78 )
  {
    if ( *(lParam + 8) == -202 )
    {
      lParama = 7;
      v20 = 64;
      v19 = &v23;
      SendMessageW(ghWndDllsListCtrl, 0xBu, 0, 0);
      v14 = IsDlgButtonChecked;
      for ( i = 0; i < gConfig.dwDllColumnCount; ++i )
      {
        if ( v14(v4, gConfig.dwDllColumnMap[i]) != 1 )
        {
          v16 = gConfig.dwDllColumnCount;
          if ( i < (gConfig.dwDllColumnCount - 1) )
          {
            do
            {
              SendMessageW(ghWndDllsListCtrl, 0x105Fu, i + 1, &lParama);
              SendMessageW(ghWndDllsListCtrl, 0x1060u, i, &lParama);
              gConfig.dwDllColumnMap[i] = gConfig.dwDllColumnMap[i + 1];
              ++i;
              v16 = gConfig.dwDllColumnCount;
            }
            while ( i < (gConfig.dwDllColumnCount - 1) );
            v4 = v22;
          }
          gConfig.dwDllColumnCount = v16 - 1;
          SendMessageW(ghWndDllsListCtrl, 0x101Cu, v16 - 1, 0);
          SetWindowLongW(ghWndDllsListCtrl, -21, gConfig.dwDllColumnCount);
          i = -1;
          *dword_10C9E60 = 1;
        }
        v14 = IsDlgButtonChecked;
      }
      v17 = 0;
      do
      {
        if ( v14(v4, dword_10BD7F8[v17]) )
          CTreeList_InsertVerifyColumn(
            ghWndDllsListCtrl,
            dword_10BD7F8[v17],
            gConfig.dwDllColumnMap,
            &gConfig.dwDllColumnCount);
        v14 = IsDlgButtonChecked;
        ++v17;
      }
      while ( v17 < 21 );
      SendMessageW(ghWndDllsListCtrl, 0xBu, 1u, 0);
      InvalidateRect(ghWndDllsListCtrl, 0, 1);
      return 1;
    }
    return 0;
  }
  if ( msg != 272 )
    return 0;
  v5 = GetDlgItem(hWnd, 1190);
  EnableWindow(v5, 0);
  v6 = gdwVersion >= 1;
  v7 = GetDlgItem(v22, 1338);
  EnableWindow(v7, v6);
  v8 = gdwVersion >= 4;
  v9 = GetDlgItem(v22, 40757);
  EnableWindow(v9, v8);
  v10 = IsImmersiveProcess != 0;
  v11 = GetDlgItem(v22, 1654);
  EnableWindow(v11, v10);
  v12 = 0;
  for ( dword_10C9E60 = *(v21 + 28); v12 < gConfig.dwDllColumnCount; ++v12 )
    CheckDlgButton(v22, gConfig.dwDllColumnMap[v12], 1u);
  return 1;
}
// 10BD7F8: using guessed type int dword_10BD7F8[];
// 10C4E54: using guessed type int gdwVersion;
// 10C9E60: using guessed type int dword_10C9E60;
// 10DBA4C: using guessed type int (__stdcall *IsImmersiveProcess)(_DWORD);

//----- (01021110) --------------------------------------------------------
int __stdcall PropColumnSetsForHandles(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
  HWND v4; // edi
  signed int v5; // esi
  UINT (__stdcall *v7)(HWND, int); // eax
  signed int i; // esi
  DWORD v9; // ecx
  unsigned int v10; // esi
  signed int j; // eax
  signed int v12; // ST0C_4
  WPARAM v13; // ecx
  LPARAM lParama; // [esp+Ch] [ebp-A8h]
  BOOL v15; // [esp+10h] [ebp-A4h]
  int v16; // [esp+14h] [ebp-A0h]
  WCHAR *v17; // [esp+18h] [ebp-9Ch]
  int v18; // [esp+1Ch] [ebp-98h]
  DWORD v19; // [esp+20h] [ebp-94h]
  HWND v20; // [esp+2Ch] [ebp-88h]
  WCHAR Buffer; // [esp+30h] [ebp-84h]

  v4 = hWnd;
  v20 = hWnd;
  if ( msg == 78 )
  {
    if ( *(lParam + 8) == -202 )
    {
      lParama = 7;
      v15 = 0;
      v18 = 64;
      v17 = &Buffer;
      SendMessageW(ghWndHandlesListCtrl, 0xBu, 0, 0);
      v7 = IsDlgButtonChecked;
      for ( i = 0; i < gConfig.dwHandleColumnCount; ++i )
      {
        if ( v7(v4, gConfig.dwIdsOfHandleColumnMap[i]) != 1 )
        {
          v9 = gConfig.dwHandleColumnCount;
          if ( i < (gConfig.dwHandleColumnCount - 1) )
          {
            do
            {
              SendMessageW(ghWndHandlesListCtrl, 0x105Fu, i + 1, &lParama);
              SendMessageW(ghWndHandlesListCtrl, 0x1060u, i, &lParama);
              gConfig.dwIdsOfHandleColumnMap[i] = gConfig.dwIdsOfHandleColumnMap[i + 1];
              ++i;
              v9 = gConfig.dwHandleColumnCount;
            }
            while ( i < (gConfig.dwHandleColumnCount - 1) );
            v4 = v20;
          }
          gConfig.dwHandleColumnCount = v9 - 1;
          SendMessageW(ghWndHandlesListCtrl, 0x101Cu, v9 - 1, 0);
          SetWindowLongW(ghWndHandlesListCtrl, -21, gConfig.dwHandleColumnCount);
          i = -1;
          *dword_10C9E64 = 1;
        }
        v7 = IsDlgButtonChecked;
      }
      v10 = 0;
      do
      {
        if ( v7(v4, dword_10BD7DC[v10]) )
        {
          for ( j = 0; j < gConfig.dwHandleColumnCount; ++j )
          {
            if ( gConfig.dwIdsOfHandleColumnMap[j] == dword_10BD7DC[v10] )
              break;
          }
          if ( j == gConfig.dwHandleColumnCount )
          {
            v19 = gConfig.dwHandleColumnCount;
            v16 = MulDiv(100, gLogPixelSize.x, 96);
            LoadStringW(ghInstance, dword_10BD7DC[v10], &Buffer, 64);
            v12 = dword_10BD7DC[v10];
            gConfig.dwIdsOfHandleColumnMap[gConfig.dwHandleColumnCount] = v12;
            v15 = IsStringID(v12) != 0;
            v13 = gConfig.dwHandleColumnCount++;
            SendMessageW(ghWndHandlesListCtrl, 0x1061u, v13, &lParama);
            SetWindowLongW(ghWndHandlesListCtrl, -21, gConfig.dwHandleColumnCount);
            *dword_10C9E64 = 1;
          }
        }
        v7 = IsDlgButtonChecked;
        ++v10;
      }
      while ( v10 < 7 );
      SendMessageW(ghWndHandlesListCtrl, 0xBu, 1u, 0);
      InvalidateRect(ghWndHandlesListCtrl, 0, 1);
      return 1;
    }
    return 0;
  }
  if ( msg != 272 )
    return 0;
  v5 = 0;
  for ( dword_10C9E64 = *(lParam + 28); v5 < gConfig.dwHandleColumnCount; ++v5 )
    CheckDlgButton(hWnd, gConfig.dwIdsOfHandleColumnMap[v5], 1u);
  return 1;
}
// 10BD7DC: using guessed type int dword_10BD7DC[];
// 10C9E64: using guessed type int dword_10C9E64;

//----- (010213D0) --------------------------------------------------------
int __stdcall PropColumnSetsForNet(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
  HWND v4; // edi
  int v5; // esi
  int v7; // esi
  int v8; // ecx
  unsigned int v9; // esi
  int j; // eax
  signed int v11; // ST0C_4
  WPARAM v12; // ecx
  LPARAM lParama; // [esp+Ch] [ebp-A8h]
  BOOL v14; // [esp+10h] [ebp-A4h]
  int v15; // [esp+14h] [ebp-A0h]
  WCHAR *i; // [esp+18h] [ebp-9Ch]
  int v17; // [esp+1Ch] [ebp-98h]
  int v18; // [esp+20h] [ebp-94h]
  HWND v19; // [esp+2Ch] [ebp-88h]
  WCHAR Buffer; // [esp+30h] [ebp-84h]

  v4 = hWnd;
  v19 = hWnd;
  if ( msg == 78 )
  {
    if ( *(lParam + 8) == -202 )
    {
      v7 = 0;
      lParama = 7;
      v14 = 0;
      v17 = 64;
      for ( i = &Buffer; v7 < gConfig.dwProcessColumnCount; ++v7 )
      {
        if ( GetDlgItem(v4, gConfig.dwProcessColumnMap[v7])
          && IsDlgButtonChecked(v4, gConfig.dwProcessColumnMap[v7]) != 1 )
        {
          v8 = gConfig.dwProcessColumnCount;
          if ( v7 < gConfig.dwProcessColumnCount - 1 )
          {
            do
            {
              SendMessageW(ghWndTreeListView, 0x105Fu, v7 + 1, &lParama);
              SendMessageW(ghWndTreeListView, 0x1060u, v7, &lParama);
              gConfig.dwProcessColumnMap[v7] = gConfig.dwProcessColumnMap[v7 + 1];
              ++v7;
              v8 = gConfig.dwProcessColumnCount;
            }
            while ( v7 < gConfig.dwProcessColumnCount - 1 );
            v4 = v19;
          }
          gConfig.dwProcessColumnCount = v8 - 1;
          SendMessageW(ghWndTreeListView, 0x101Cu, v8 - 1, 0);
          SetWindowLongW(ghWndTreeListView, -21, gConfig.dwProcessColumnCount);
          v7 = -1;
          *dword_10C9E6C = 1;
        }
      }
      v9 = 0;
      do
      {
        if ( IsDlgButtonChecked(v4, dword_10BD798[v9]) )
        {
          for ( j = 0; j < gConfig.dwProcessColumnCount; ++j )
          {
            if ( gConfig.dwProcessColumnMap[j] == dword_10BD798[v9] )
              break;
          }
          if ( j == gConfig.dwProcessColumnCount )
          {
            v18 = gConfig.dwProcessColumnCount;
            v15 = MulDiv(100, gLogPixelSize.x, 96);
            LoadStringW(ghInstance, dword_10BD798[v9], &Buffer, 64);
            v11 = dword_10BD798[v9];
            gConfig.dwProcessColumnMap[gConfig.dwProcessColumnCount] = v11;
            v14 = IsStringID(v11) != 0;
            v12 = gConfig.dwProcessColumnCount++;
            SendMessageW(ghWndTreeListView, 0x1061u, v12, &lParama);
            SetWindowLongW(ghWndTreeListView, -21, gConfig.dwProcessColumnCount);
            *dword_10C9E6C = 1;
          }
        }
        ++v9;
      }
      while ( v9 < 17 );
      return 1;
    }
    return 0;
  }
  if ( msg != 272 )
    return 0;
  v5 = 0;
  for ( dword_10C9E6C = *(lParam + 28); v5 < gConfig.dwProcessColumnCount; ++v5 )
    CheckDlgButton(hWnd, gConfig.dwProcessColumnMap[v5], 1u);
  return 1;
}
// 10BD798: using guessed type int dword_10BD798[];
// 10C9E6C: using guessed type int dword_10C9E6C;

//----- (01021680) --------------------------------------------------------
int __stdcall PropColumnSetsForProcess(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
  HWND v4; // eax
  int v5; // ST0C_4
  HWND v6; // eax
  int v7; // ST0C_4
  HWND v8; // eax
  BOOL v9; // ST0C_4
  HWND v10; // eax
  BOOL v11; // ST0C_4
  HWND v12; // eax
  BOOL v13; // ST0C_4
  HWND v14; // eax
  BOOL v15; // ST0C_4
  HWND v16; // eax
  BOOL v17; // ST0C_4
  HWND v18; // eax
  BOOL v19; // ST0C_4
  HWND v20; // eax
  BOOL v21; // ST0C_4
  HWND v22; // eax
  BOOL v23; // ST0C_4
  HWND v24; // eax
  BOOL v25; // ST0C_4
  HWND v26; // eax
  BOOL v27; // ST0C_4
  HWND v28; // eax
  BOOL v29; // ST0C_4
  HWND v30; // eax
  BOOL v31; // ST0C_4
  HWND v32; // eax
  void (__stdcall *v33)(HWND, int, UINT); // eax
  int j; // esi
  HWND v35; // eax
  void (__stdcall *v36)(HWND, BOOL); // esi
  HWND v37; // eax
  HWND v38; // eax
  HWND v39; // eax
  HWND v40; // eax
  HWND v41; // eax
  HWND v42; // eax
  HWND v43; // eax
  HWND v44; // eax
  HWND v45; // eax
  void (__stdcall *v47)(HWND, UINT, WPARAM, LPARAM); // edi
  HWND (__stdcall *v48)(HWND, int); // eax
  int i; // esi
  int v50; // ecx
  unsigned int v51; // esi
  LPARAM lParama; // [esp+Ch] [ebp-A4h]
  int v53; // [esp+10h] [ebp-A0h]
  char *v54; // [esp+18h] [ebp-98h]
  int v55; // [esp+1Ch] [ebp-94h]
  char v56; // [esp+2Ch] [ebp-84h]

  if ( msg == WM_NOTIFY )
  {
    if ( *(lParam + 8) == -202 )
    {
      v47 = SendMessageW;
      lParama = 7;
      v53 = 0;
      v55 = 64;
      v54 = &v56;
      SendMessageW(ghWndTreeListView, 0xBu, 0, 0);
      v48 = GetDlgItem;
      for ( i = 0; i < gConfig.dwProcessColumnCount; ++i )
      {
        if ( v48(hWnd, gConfig.dwProcessColumnMap[i]) && IsDlgButtonChecked(hWnd, gConfig.dwProcessColumnMap[i]) != 1 )
        {
          v50 = gConfig.dwProcessColumnCount;
          if ( i < gConfig.dwProcessColumnCount - 1 )
          {
            do
            {
              SendMessageW(ghWndTreeListView, 0x105Fu, i + 1, &lParama);
              SendMessageW(ghWndTreeListView, 0x1060u, i, &lParama);
              gConfig.dwProcessColumnMap[i] = gConfig.dwProcessColumnMap[i + 1];
              ++i;
              v50 = gConfig.dwProcessColumnCount;
            }
            while ( i < gConfig.dwProcessColumnCount - 1 );
            v47 = SendMessageW;
          }
          gConfig.dwProcessColumnCount = v50 - 1;
          v47(ghWndTreeListView, 0x101Cu, v50 - 1, 0);
          SetWindowLongW(ghWndTreeListView, -21, gConfig.dwProcessColumnCount);
          i = -1;
          *dword_10C9E68 = 1;
        }
        v48 = GetDlgItem;
      }
      v51 = 0;
      do
      {
        if ( v48(hWnd, dword_10BD5F0[v51]) && IsDlgButtonChecked(hWnd, dword_10BD5F0[v51]) )
          CTreeList_InsertVerifyColumn(
            ghWndTreeListView,
            dword_10BD5F0[v51],
            gConfig.dwProcessColumnMap,
            &gConfig.dwProcessColumnCount);
        v48 = GetDlgItem;
        ++v51;
      }
      while ( v51 < 105 );
      v47(ghWndTreeListView, 0xBu, 1u, 0);
      InvalidateRect(ghWndTreeListView, 0, 1);
      return 1;
    }
    return 0;
  }
  if ( msg != WM_INITDIALOG )
    return 0;
  dword_10C9E68 = *(lParam + 28);
  v4 = GetDlgItem(hWnd, 1190);
  EnableWindow(v4, 0);
  v5 = gbWintrustInited;
  v6 = GetDlgItem(hWnd, 1187);
  EnableWindow(v6, v5);
  v7 = gbIsProcessDEPEnabled;
  v8 = GetDlgItem(hWnd, 1199);
  EnableWindow(v8, v7);
  v9 = gdwVersion >= 1;
  v10 = GetDlgItem(hWnd, 1337);
  EnableWindow(v10, v9);
  v11 = gdwVersion >= 1;
  v12 = GetDlgItem(hWnd, 1336);
  EnableWindow(v12, v11);
  v13 = gdwVersion >= 1;
  v14 = GetDlgItem(hWnd, 1180);
  EnableWindow(v14, v13);
  v15 = gdwVersion >= 1;
  v16 = GetDlgItem(hWnd, 1338);
  EnableWindow(v16, v15);
  v17 = gdwVersion >= 4;
  v18 = GetDlgItem(hWnd, 40757);
  EnableWindow(v18, v17);
  v19 = gdwVersion >= 1;
  v20 = GetDlgItem(hWnd, 1340);
  EnableWindow(v20, v19);
  v21 = gdwVersion >= 1;
  v22 = GetDlgItem(hWnd, 1339);
  EnableWindow(v22, v21);
  v23 = GetProcessDpiAwareness != 0;
  v24 = GetDlgItem(hWnd, 1667);
  EnableWindow(v24, v23);
  v25 = gdwVersion >= 1;
  v26 = GetDlgItem(hWnd, 1674);
  EnableWindow(v26, v25);
  v27 = gdwVersion >= 3;
  v28 = GetDlgItem(hWnd, 1673);
  EnableWindow(v28, v27);
  v29 = GetProcessorSystemCycleTime != 0;
  v30 = GetDlgItem(hWnd, 7);
  EnableWindow(v30, v29);
  v31 = IsImmersiveProcess != 0;
  v32 = GetDlgItem(hWnd, 1654);
  EnableWindow(v32, v31);
  v33 = CheckDlgButton;
  for ( j = 0; j < gConfig.dwProcessColumnCount; ++j )
  {
    v33(hWnd, gConfig.dwProcessColumnMap[j], 1u);
    v33 = CheckDlgButton;
  }
  v33(hWnd, 3, 1u);
  if ( gbProcessIdToSessionIdValid )
  {
    v36 = EnableWindow;
  }
  else
  {
    v35 = GetDlgItem(hWnd, 1056);
    v36 = EnableWindow;
    EnableWindow(v35, 0);
  }
  if ( !QueryProcessCycleTime )
  {
    v37 = GetDlgItem(hWnd, 1195);
    v36(v37, 0);
    v38 = GetDlgItem(hWnd, 1200);
    v36(v38, 0);
  }
  if ( !*GetGuiResources )
  {
    v39 = GetDlgItem(hWnd, 1067);
    v36(v39, 0);
    v40 = GetDlgItem(hWnd, 1066);
    v36(v40, 0);
  }
  if ( !gdwAdapterRuntingTime )
  {
    v41 = GetDlgItem(hWnd, 1650);
    v36(v41, 0);
  }
  if ( !*QueryWorkingSet )
  {
    v42 = GetDlgItem(hWnd, 1115);
    v36(v42, 0);
    v43 = GetDlgItem(hWnd, 1116);
    v36(v43, 0);
    v44 = GetDlgItem(hWnd, 1317);
    v36(v44, 0);
    v45 = GetDlgItem(hWnd, 1118);
    v36(v45, 0);
  }
  return 1;
}
// 10BD5F0: using guessed type int dword_10BD5F0[];
// 10C4E54: using guessed type int gdwVersion;
// 10C9E68: using guessed type int dword_10C9E68;
// 10CA38A: using guessed type char gbProcessIdToSessionIdValid;
// 10CA390: using guessed type char gbIsProcessDEPEnabled;
// 10CA391: using guessed type char gbWintrustInited;
// 10CF2F4: using guessed type int GetProcessorSystemCycleTime;
// 10CF36C: using guessed type int (__stdcall *GetProcessDpiAwareness)(_DWORD, _DWORD);
// 10DBA4C: using guessed type int (__stdcall *IsImmersiveProcess)(_DWORD);

//----- (01021AF0) --------------------------------------------------------
int __cdecl sub_1021AF0(_DWORD *a1, _DWORD *a2)
{
  int v2; // ebx
  unsigned int v3; // edi
  unsigned int v5; // edx
  int v6; // esi
  bool v7; // zf
  bool v8; // sf
  unsigned __int8 v9; // of

  v2 = a1[157];
  v3 = a1[156];
  if ( !*(a1 + 78) )
  {
    if ( *(a2 + 78) )
      return -1;
    return a1[17] - a2[17];
  }
  v5 = a2[156];
  v6 = a2[157];
  if ( !*(a2 + 78) )
    return 1;
  if ( v5 == v3 )
  {
    v9 = __OFSUB__(v2, v6);
    v7 = v2 == v6;
    v8 = v2 - v6 < 0;
    if ( v2 == v6 )
      return a1[17] - a2[17];
  }
  else
  {
    v9 = __OFSUB__(v2, v6);
    v7 = v2 == v6;
    v8 = v2 - v6 < 0;
  }
  if ( !(v8 ^ v9) && (!((v8 ^ v9) | v7) || v3 > v5) )
    return 1;
  return -1;
}

//----- (01021B70) --------------------------------------------------------
signed int __cdecl sub_1021B70(int a1, HWND *a2)
{
  HWND *v2; // esi
  int v3; // eax
  _bstr_t *v4; // edi
  Data_t_bstr_t *v5; // eax

  v2 = a2;
  if ( !sub_1012A70(*a2) )
    return 1;
  if ( *v2 == ghWndTreeListView && !v2[5] )
  {
    if ( !(dword_10C9E54 & 1) )
    {
      stru_10C9E50.m_Data = 0;
      dword_10C9E54 |= 1u;
      atexit(sub_108A970);
    }
    CTreeList::GetTreeList(*v2);
    v3 = sub_FFE5D0(v2[4]);
    v4 = sub_1016270(&a2, v3);
    if ( v4 != &stru_10C9E50 )
    {
      _bstr_t::_Free(&stru_10C9E50);
      v5 = v4->m_Data;
      stru_10C9E50.m_Data = v5;
      if ( v5 )
        InterlockedIncrement(&v5->m_RefCount);
    }
    _bstr_t::_Free(&a2);
    if ( stru_10C9E50.m_Data )
    {
      *v2[6] = stru_10C9E50.m_Data->m_wstr;
      return 1;
    }
    *v2[6] = 0;
    return 1;
  }
  return 0;
}
// 10C9E54: using guessed type int dword_10C9E54;

//----- (01021C50) --------------------------------------------------------
signed int __cdecl sub_1021C50(int a1, int a2)
{
  HMONITOR v2; // eax
  struct tagPOINT Point; // [esp+8h] [ebp-54h]
  struct tagMONITORINFO mi; // [esp+10h] [ebp-4Ch]
  __int128 pvParam; // [esp+38h] [ebp-24h]
  struct tagRECT Rect; // [esp+48h] [ebp-14h]

  GetCursorPos(&Point);
  if ( *MonitorFromPoint )
  {
    v2 = MonitorFromPoint(Point, 2u);
    if ( v2 )
    {
      mi.cbSize = 40;
      if ( GetMonitorInfoA(v2, &mi) )
        _mm_storeu_si128(&pvParam, _mm_loadu_si128(&mi.rcWork));
    }
  }
  else
  {
    SystemParametersInfoW(0x30u, 0, &pvParam, 0);
  }
  DWORD2(pvParam) -= 10;
  HIDWORD(pvParam) -= 10;
  GetWindowRect(*a2, &Rect);
  if ( !*(a2 + 20) )
    OffsetRect(&Rect, Point.x - Rect.left + 17, 34);
  if ( Rect.right > SDWORD2(pvParam) )
    OffsetRect(&Rect, DWORD2(pvParam) - Rect.right, 0);
  if ( Rect.bottom > SHIDWORD(pvParam) )
    OffsetRect(&Rect, 0, HIDWORD(pvParam) - Rect.bottom);
  SetWindowPos(*a2, 0, Rect.left, Rect.top, 0, 0, 0x15u);
  return 1;
}

//----- (01021D40) --------------------------------------------------------
BOOL RefreshTreeView()
{
  return InvalidateRect(ghWndTreeListView, 0, 0);
}

//----- (01021D60) --------------------------------------------------------
int MakeAddressInfo(char *DstBuf, char *Format, ...)
{
  va_list ArgList; // [esp+10h] [ebp+10h]

  va_start(ArgList, Format);
  return vsprintf_s(DstBuf, 0x104u, Format, ArgList);
}

//----- (01021D80) --------------------------------------------------------
int sub_1021D80(wchar_t *Dst, wchar_t *Format, ...)
{
  va_list ArgList; // [esp+10h] [ebp+10h]

  va_start(ArgList, Format);
  return vswprintf_s(Dst, 3u, Format, ArgList);
}

//----- (01021DA0) --------------------------------------------------------
int *__thiscall sub_1021DA0(int *this, void *a2)
{
  int *v2; // esi

  v2 = this;
  this[5] = 7;
  this[4] = 0;
  *this = 0;
  if ( *a2 )
    sub_1009760(this, a2, wcslen(a2));
  else
    sub_1009760(this, a2, 0);
  return v2;
}

//----- (01021E00) --------------------------------------------------------
string *__thiscall sub_1021E00(void *this, void *a2)
{
  string *result; // eax

  if ( *a2 )
    result = sub_10231B0(this, a2, wcslen(a2));
  else
    result = sub_10231B0(this, a2, 0);
  return result;
}

//----- (01021E50) --------------------------------------------------------
HRESULT __cdecl sub_1021E50(char a1, OLECHAR *a2)
{
  HRESULT v2; // esi
  __m128i v3; // xmm0
  LPVOID v4; // ecx
  int v5; // edx
  BOOL **v6; // eax
  BOOL *v7; // edx
  int v8; // eax
  OLECHAR *v9; // eax
  BOOL **v10; // edx
  BOOL *v11; // edx
  int v12; // ecx
  int v13; // ecx
  int (__stdcall **v14)(int, void *, int *); // ecx
  BOOL **v15; // eax
  BOOL *v16; // edx
  HANDLE v17; // eax
  OLECHAR *v18; // eax
  BOOL **v19; // edx
  BOOL *v20; // edx
  int v21; // eax
  int v22; // ecx
  int (__stdcall **v23)(int, void *, int *); // ecx
  _DWORD *v24; // eax
  BOOL *v25; // edx
  int v26; // eax
  _DWORD *v27; // edx
  BOOL *v28; // edx
  BOOL *v29; // edx
  BSTR v30; // ecx
  VARIANTARG *v31; // esi
  signed int v32; // ebx
  __m128i v33; // xmm0
  __m128i v34; // xmm0
  BOOL *v35; // eax
  int *v36; // edi
  int v37; // edi
  __m128i v38; // xmm0
  int v39; // esi
  char v40; // al
  __m128i v41; // xmm0
  __m128i v42; // xmm0
  int v44; // [esp-40h] [ebp-548h]
  signed int v45; // [esp-3Ch] [ebp-544h]
  int v46; // [esp-38h] [ebp-540h]
  int v47; // [esp-34h] [ebp-53Ch]
  int v48; // [esp-30h] [ebp-538h]
  int v49; // [esp-2Ch] [ebp-534h]
  DWORD v50; // [esp-28h] [ebp-530h]
  int v51; // [esp-24h] [ebp-52Ch]
  wchar_t *v52; // [esp-20h] [ebp-528h]
  DWORD v53; // [esp-1Ch] [ebp-524h]
  WCHAR *v54; // [esp-18h] [ebp-520h]
  DWORD v55; // [esp-14h] [ebp-51Ch]
  WCHAR *v56; // [esp-10h] [ebp-518h]
  LPVOID v57; // [esp-Ch] [ebp-514h]
  BOOL *v58; // [esp-8h] [ebp-510h]
  BOOL *v59; // [esp-4h] [ebp-50Ch]
  __int128 v60; // [esp+10h] [ebp-4F8h]
  __int128 v61; // [esp+20h] [ebp-4E8h]
  __int128 v62; // [esp+30h] [ebp-4D8h]
  VARIANTARG v63; // [esp+40h] [ebp-4C8h]
  VARIANTARG v64; // [esp+50h] [ebp-4B8h]
  VARIANTARG v65; // [esp+60h] [ebp-4A8h]
  VARIANTARG pvarg; // [esp+70h] [ebp-498h]
  int *v67; // [esp+80h] [ebp-488h]
  int (__stdcall ***v68)(int, void *, int *); // [esp+84h] [ebp-484h]
  BOOL *v69; // [esp+88h] [ebp-480h]
  int (__stdcall ***v70)(int, void *, int *); // [esp+8Ch] [ebp-47Ch]
  int *v71; // [esp+90h] [ebp-478h]
  BOOL *v72; // [esp+94h] [ebp-474h]
  BOOL *v73; // [esp+98h] [ebp-470h]
  BOOL *v74; // [esp+9Ch] [ebp-46Ch]
  _bstr_t v75; // [esp+A0h] [ebp-468h]
  _bstr_t v76; // [esp+A4h] [ebp-464h]
  LPVOID ppv; // [esp+A8h] [ebp-460h]
  _bstr_t v78; // [esp+ACh] [ebp-45Ch]
  int *v79; // [esp+B0h] [ebp-458h]
  BOOL *v80; // [esp+B4h] [ebp-454h]
  OLECHAR *psz; // [esp+B8h] [ebp-450h]
  unsigned int v82; // [esp+CCh] [ebp-43Ch]
  OLECHAR *v83; // [esp+D0h] [ebp-438h]
  unsigned int v84; // [esp+E4h] [ebp-424h]
  WCHAR szDomainName[2]; // [esp+E8h] [ebp-420h]
  wchar_t Dst; // [esp+2F0h] [ebp-218h]
  int v87; // [esp+504h] [ebp-4h]

  v76.m_Data = a2;
  v78.m_Data = 0;
  sub_10226B0(&psz);
  v87 = 0;
  ppv = 0;
  v2 = CoCreateInstance(&stru_10A78CC, 0, 1u, &riid, &ppv);
  if ( v2 >= 0 )
  {
    VariantInit(&pvarg);
    _mm_storeu_si128(&v60, _mm_loadu_si128(&pvarg));
    VariantInit(&v65);
    _mm_storeu_si128(&v61, _mm_loadu_si128(&v65));
    VariantInit(&v64);
    _mm_storeu_si128(&v62, _mm_loadu_si128(&v64));
    VariantInit(&v63);
    v3 = _mm_loadu_si128(&v60);
    v4 = ppv;
    LOBYTE(v87) = 4;
    v5 = *ppv;
    _mm_storeu_si128(&v56, v3);
    _mm_storeu_si128(&v52, _mm_loadu_si128(&v61));
    _mm_storeu_si128(&v48, _mm_loadu_si128(&v62));
    _mm_storeu_si128(&v44, _mm_loadu_si128(&v63));
    v2 = (*(v5 + 40))(v4, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59);
    VariantClear(&v63);
    VariantClear(&v64);
    VariantClear(&v65);
    LOBYTE(v87) = 0;
    VariantClear(&pvarg);
    if ( v2 < 0 )
    {
      v59 = ppv;
      (*(*ppv + 8))(ppv);
      goto LABEL_64;
    }
    v79 = 0;
    v6 = *_bstr_t::_bstr_t(&v75, L"\\");
    LOBYTE(v87) = 5;
    if ( v6 )
      v7 = *v6;
    else
      v7 = 0;
    v59 = &v79;
    v58 = v7;
    v57 = ppv;
    v8 = (*(*ppv + 28))(ppv, v7, &v79);
    LOBYTE(v87) = 0;
    v2 = v8;
    _bstr_t::_Free(&v75);
    if ( v2 < 0 )
    {
      v59 = ppv;
      (*(*ppv + 8))(ppv);
      goto LABEL_64;
    }
    v9 = &psz;
    if ( v82 >= 8 )
      v9 = psz;
    v10 = *_bstr_t::_bstr_t(&v75, v9);
    LOBYTE(v87) = 6;
    if ( v10 )
      v11 = *v10;
    else
      v11 = 0;
    v59 = 0;
    v58 = v11;
    v57 = v79;
    (*(*v79 + 60))(v79, v11, 0);
    LOBYTE(v87) = 0;
    _bstr_t::_Free(&v75);
    if ( a1 )
    {
      v59 = &v80;
      v80 = 0;
      v58 = 0;
      v12 = *ppv;
      v57 = ppv;
      v2 = (*(v12 + 36))(ppv, 0, &v80);
      v59 = ppv;
      (*(*ppv + 8))(ppv);
      if ( v2 < 0 )
      {
        v59 = v79;
        (*(*v79 + 8))(v79);
        goto LABEL_64;
      }
      v69 = 0;
      v59 = &v69;
      v58 = v80;
      v2 = (*(*v80 + 28))(v80, &v69);
      if ( v2 < 0 )
        goto LABEL_69;
      v59 = L"Process Explorer";
      v58 = v69;
      v2 = (*(*v69 + 40))(v69, L"Process Explorer");
      v59 = v69;
      (*(*v69 + 8))(v69);
      if ( v2 < 0 )
        goto LABEL_69;
      v73 = 0;
      v59 = &v73;
      v58 = v80;
      v2 = (*(*v80 + 44))(v80, &v73);
      if ( v2 < 0 )
        goto LABEL_69;
      v59 = -1;
      v58 = v73;
      v2 = (*(*v73 + 88))(v73, -1);
      v59 = v73;
      (*(*v73 + 8))(v73);
      if ( v2 < 0 )
        goto LABEL_69;
      v59 = 0;
      v58 = v73;
      (*(*v73 + 72))(v73, 0);
      v67 = 0;
      v59 = &v67;
      v58 = v80;
      v2 = (*(*v80 + 36))(v80, &v67);
      if ( v2 < 0 )
        goto LABEL_69;
      v59 = &v70;
      v70 = 0;
      v58 = 9;
      v13 = *v67;
      v57 = v67;
      v2 = (*(v13 + 40))(v67, 9, &v70);
      v59 = v67;
      (*(*v67 + 8))(v67);
      if ( v2 < 0 )
        goto LABEL_69;
      v59 = &v72;
      v72 = 0;
      v58 = &unk_10A776C;
      v14 = *v70;
      v57 = v70;
      v2 = (*v14)(v70, &unk_10A776C, &v72);
      v59 = v70;
      ((*v70)[2])(v70);
      if ( v2 < 0 )
      {
LABEL_69:
        v59 = v79;
        (*(*v79 + 8))(v79);
        v59 = v80;
        (*(*v80 + 8))(v80);
        goto LABEL_64;
      }
      v15 = *_bstr_t::_bstr_t(&v78, L"Logon Trigger");
      LOBYTE(v87) = 7;
      if ( v15 )
        v16 = *v15;
      else
        v16 = 0;
      v59 = v16;
      v58 = v72;
      (*(*v72 + 36))(v72, v16);
      LOBYTE(v87) = 0;
      _bstr_t::_Free(&v78);
      v59 = 0;
      v58 = 0;
      v57 = 0;
      v56 = 0;
      v55 = 260;
      v54 = szDomainName;
      v53 = 260;
      v52 = &Dst;
      v51 = 0;
      v50 = GetCurrentProcessId();
      v17 = GetCurrentProcess();
      QueryProcessUsers(v17, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59);
      sub_1021DA0(&v83, szDomainName);
      LOBYTE(v87) = 8;
      sub_1021E00(&v83, L"\\");
      sub_1021E00(&v83, &Dst);
      v18 = &v83;
      if ( v84 >= 8 )
        v18 = v83;
      v19 = *_bstr_t::_bstr_t(&v78, v18);
      LOBYTE(v87) = 9;
      if ( v19 )
        v20 = *v19;
      else
        v20 = 0;
      v59 = v20;
      v58 = v72;
      v21 = (*(*v72 + 92))(v72, v20);
      LOBYTE(v87) = 8;
      v2 = v21;
      _bstr_t::_Free(&v78);
      v59 = v72;
      (*(*v72 + 8))(v72);
      if ( v2 < 0 )
        goto LABEL_70;
      v71 = 0;
      v59 = &v71;
      v58 = v80;
      v2 = (*(*v80 + 68))(v80, &v71);
      if ( v2 < 0 )
        goto LABEL_70;
      v59 = &v68;
      v68 = 0;
      v58 = 0;
      v22 = *v71;
      v57 = v71;
      v2 = (*(v22 + 48))(v71, 0, &v68);
      v59 = v71;
      (*(*v71 + 8))(v71);
      if ( v2 < 0 )
        goto LABEL_70;
      v59 = &v74;
      v74 = 0;
      v58 = &unk_10A781C;
      v23 = *v68;
      v57 = v68;
      v2 = (*v23)(v68, &unk_10A781C, &v74);
      v59 = v68;
      ((*v68)[2])(v68);
      if ( v2 < 0 )
        goto LABEL_70;
      v24 = *_bstr_t::_bstr_t(&v76, v76.m_Data);
      LOBYTE(v87) = 10;
      v25 = (v24 ? *v24 : 0);
      v59 = v25;
      v58 = v74;
      v26 = (*(*v74 + 44))(v74, v25);
      LOBYTE(v87) = 8;
      v2 = v26;
      _bstr_t::_Free(&v76);
      v27 = *_bstr_t::_bstr_t(&v76, L"/t");
      LOBYTE(v87) = 11;
      v28 = (v27 ? *v27 : 0);
      v59 = v28;
      v58 = v74;
      (*(*v74 + 52))(v74, v28);
      LOBYTE(v87) = 8;
      _bstr_t::_Free(&v76);
      v59 = v74;
      (*(*v74 + 8))(v74);
      if ( v2 < 0 )
        goto LABEL_70;
      if ( IsBuiltinAdministrative() )
      {
        v78.m_Data = 0;
        v59 = &v78;
        v58 = v80;
        (*(*v80 + 60))(v80, &v78);
        v29 = &v83;
        if ( v84 >= 8 )
          v29 = v83;
        v30 = v78.m_Data->m_wstr;
        v59 = v29;
        v58 = v78.m_Data;
        (*(v30 + 12))(v78.m_Data, v29);
        v59 = 1;
        v58 = v78.m_Data;
        (*(v78.m_Data->m_wstr + 18))(v78.m_Data, 1);
        v59 = v78.m_Data;
        (*(v78.m_Data->m_wstr + 2))(v78.m_Data);
      }
      v75.m_Data = 0;
      if ( IsBuiltinAdministrative() )
      {
        v31 = sub_FF93D0(&v63, L"Builtin\\Administrators");
        LOBYTE(v87) = 12;
        v32 = 1;
      }
      else
      {
        VariantInit(&v65);
        v31 = &v65;
        v87 = 13;
        v32 = 2;
      }
      v78.m_Data = v32;
      v33 = _mm_loadu_si128(sub_FF93D0(&v64, &gszNullString));
      v87 = 14;
      v59 = &pvarg;
      _mm_storeu_si128(&v62, v33);
      VariantInit(v59);
      v34 = _mm_loadu_si128(&pvarg);
      v35 = &psz;
      LOBYTE(v87) = 15;
      if ( v82 >= 8 )
        v35 = psz;
      _mm_storeu_si128(&v61, v34);
      v59 = v35;
      _mm_storeu_si128(&v60, _mm_loadu_si128(v31));
      v36 = *_bstr_t::_bstr_t(&v76, v59);
      LOBYTE(v87) = 16;
      if ( v36 )
        v37 = *v36;
      else
        v37 = 0;
      v38 = _mm_loadu_si128(&v62);
      v39 = *v79;
      v59 = &v75;
      _mm_storeu_si128(&v55, v38);
      v40 = IsBuiltinAdministrative();
      v41 = _mm_loadu_si128(&v61);
      v54 = ((v40 != 0) + 3);
      _mm_storeu_si128(&v50, v41);
      v42 = _mm_loadu_si128(&v60);
      v45 = 6;
      v44 = v80;
      _mm_storeu_si128(&v46, v42);
      v2 = (*(v39 + 68))(v79, v37, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, v56, v57, v58, v59);
      _bstr_t::_Free(&v76);
      VariantClear(&pvarg);
      VariantClear(&v64);
      if ( v32 & 2 )
      {
        LOBYTE(v32) = v32 & 0xFD;
        VariantClear(&v65);
      }
      v87 = 8;
      if ( v32 & 1 )
        VariantClear(&v63);
      if ( v2 < 0 )
      {
LABEL_70:
        v59 = v79;
        (*(*v79 + 8))(v79);
        v59 = v80;
        (*(*v80 + 8))(v80);
        sub_FD3820(&v83);
        goto LABEL_64;
      }
      v59 = v80;
      (*(*v80 + 8))(v80);
      v59 = v75.m_Data;
      (*(v75.m_Data->m_wstr + 2))(v75.m_Data);
      LOBYTE(v87) = 0;
      sub_FD3820(&v83);
    }
    v59 = v79;
    (*(*v79 + 8))(v79);
    v2 = 0;
  }
LABEL_64:
  if ( v82 >= 8 )
    j__free(psz);
  return v2;
}

//----- (010226B0) --------------------------------------------------------
void *__cdecl sub_10226B0(void *a1)
{
  DWORD v1; // ST04_4
  HANDLE v2; // eax
  int v3; // ecx
  int v4; // ecx
  void *v6; // [esp+10h] [ebp-438h]
  int v7; // [esp+20h] [ebp-428h]
  unsigned int v8; // [esp+24h] [ebp-424h]
  WCHAR szDomainName[2]; // [esp+28h] [ebp-420h]
  wchar_t Dst; // [esp+230h] [ebp-218h]
  int v11; // [esp+444h] [ebp-4h]

  v11 = 0;
  v1 = GetCurrentProcessId();
  v2 = GetCurrentProcess();
  QueryProcessUsers(v2, v1, 0, &Dst, 0x104u, szDomainName, 0x104u, 0, 0, 0, 0);
  v8 = 7;
  v7 = 0;
  LOWORD(v6) = 0;
  if ( szDomainName[0] )
    v3 = wcslen(szDomainName);
  else
    v3 = 0;
  sub_1009760(&v6, szDomainName, v3);
  v11 = 1;
  sub_10231B0(&v6, L"-", 1);
  if ( Dst )
    v4 = wcslen(&Dst);
  else
    v4 = 0;
  sub_10231B0(&v6, &Dst, v4);
  *(a1 + 5) = 7;
  *(a1 + 4) = 0;
  *a1 = 0;
  sub_1009760(a1, L"Process Explorer-", 17);
  sub_10230E0(a1, &v6, 0, -1);
  if ( v8 >= 8 )
    j__free(v6);
  return a1;
}
// 109F134: using guessed type wchar_t asc_109F134[2];
// 109F138: using guessed type wchar_t aProcessExplore_3[18];

//----- (01022850) --------------------------------------------------------
errno_t __cdecl sub_1022850(wchar_t *Dst, rsize_t SizeInWords)
{
  DWORD nLength; // [esp+Ch] [ebp-420h]
  WCHAR RemoteName; // [esp+10h] [ebp-41Ch]
  WCHAR LocalName; // [esp+420h] [ebp-Ch]

  GetModuleFileNameW(0, Dst + 1, SizeInWords - 2);
  sub_1021D80(&LocalName, L"%c:", Dst[1]);
  nLength = 520;
  if ( !WNetGetConnectionW(&LocalName, &RemoteName, &nLength) )
  {
    wcscat_s(&RemoteName, 0x208u, Dst + 2);
    wcscpy_s(Dst + 1, SizeInWords - 1, &RemoteName);
  }
  *Dst = 34;
  wcscat_s(Dst, SizeInWords, L"\"");
  return _wcsupr_s(Dst, SizeInWords);
}

//----- (01022910) --------------------------------------------------------
char __cdecl sub_1022910(int a1, int a2, int a3, wchar_t *Dst, rsize_t SizeInWords)
{
  tagItem124_InTcpUdp *v5; // edi
  _DWORD *v6; // eax
  int *v7; // edx
  unsigned int v8; // esi
  bool v9; // cf
  const wchar_t **v10; // eax
  int v11; // edx
  int v13; // [esp+Ch] [ebp-4h]

  v5 = gpItem124_InTcpUdp;
  if ( !gpItem124_InTcpUdp )
    return 0;
  while ( 1 )
  {
    if ( a1 && a1 != 1 || v5->field_0 && v5->field_0 != 1 )
    {
      if ( (a1 == 2 || a1 == 3) && (v5->field_0 == 2 || v5->field_0 == 3) )
      {
        v6 = a3;
        v7 = &v5->field_110;
        v8 = 12;
        while ( *v7 == *v6 )
        {
          ++v7;
          ++v6;
          v9 = v8 < 4;
          v8 -= 4;
          if ( v9 )
            goto LABEL_13;
        }
      }
      goto LABEL_17;
    }
    if ( v5->field_10C == a2 )
      break;
LABEL_17:
    v5 = v5->pNext;
    if ( !v5 )
      return 0;
  }
LABEL_13:
  v10 = sub_1014BD0(&v13, v5->szAddress);
  wcscpy_s(Dst, SizeInWords, *v10);
  v11 = v13 - 16;
  if ( _InterlockedDecrement((v13 - 16 + 12)) <= 0 )
    (*(**v11 + 4))(v11);
  return 1;
}

//----- (010229E0) --------------------------------------------------------
WCHAR *__cdecl PE_LoadEnvKey(HKEY hKey, LPCWSTR lpValueName)
{
  WCHAR *v2; // esi
  WCHAR *v3; // ebx
  DWORD v4; // edi
  DWORD cbData; // [esp+8h] [ebp-4h]

  v2 = 0;
  cbData = 0;
  if ( !RegQueryValueExW(hKey, lpValueName, 0, 0, 0, &cbData) )
  {
    v3 = malloc(cbData);
    if ( !RegQueryValueExW(hKey, lpValueName, 0, 0, v3, &cbData) )
    {
      v4 = ExpandEnvironmentStringsW(v3, 0, 0);
      cbData = v4;
      if ( v4 )
      {
        v2 = malloc(2 * v4);
        ExpandEnvironmentStringsW(v3, v2, v4);
      }
    }
    free(v3);
  }
  return v2;
}

//----- (01022A70) --------------------------------------------------------
void __cdecl tagItem124_InTcpUdp_Query(tagItem124_InTcpUdp *a1)
{
  struct hostent *v1; // eax
  void (__stdcall *v2)(LPCRITICAL_SECTION); // edi
  tagItem124_InTcpUdp *v3; // ebx
  int v4; // ST24_4
  int v5; // ST20_4
  int v6; // ST1C_4
  int v7; // ST18_4
  int v8; // ST14_4
  int v9; // ST10_4
  int v10; // ST0C_4
  u_short v11; // ax
  struct hostent *v12; // eax
  tagItem124_InTcpUdp *pItem; // esi
  tagItem124_InTcpUdp *v14; // eax
  char szAddress[260]; // [esp+10h] [ebp-108h]

  EnterCriticalSection(&gLock3);
  if ( a1->field_0 && a1->field_0 != 1 )
  {
    v1 = gethostbyaddr(&a1->field_110, 16, 23);
    if ( v1 )
    {
      strcpy_s(szAddress, 0x104u, v1->h_name);
      v2 = LeaveCriticalSection;
      LeaveCriticalSection(&gLock3);
    }
    else
    {
      v2 = LeaveCriticalSection;
      LeaveCriticalSection(&gLock3);
      v4 = htons(HIWORD(a1->field_11C));
      v5 = htons(a1->field_11C);
      v6 = htons(HIWORD(a1->field_118));
      v7 = htons(a1->field_118);
      v8 = htons(HIWORD(a1->field_114));
      v9 = htons(a1->field_114);
      v10 = htons(HIWORD(a1->field_110));
      v11 = htons(a1->field_110);
      MakeAddressInfo(szAddress, "[%x:%x:%x:%x:%x:%x:%x:%x]", v11, v10, v9, v8, v7, v6, v5, v4);
    }
    v3 = a1;
  }
  else
  {
    v3 = htonl(a1->field_108);
    v12 = gethostbyaddr(&a1->field_108, 4, 2);
    if ( v12 )
    {
      strcpy_s(szAddress, 0x104u, v12->h_name);
      v2 = LeaveCriticalSection;
      LeaveCriticalSection(&gLock3);
    }
    else
    {
      v2 = LeaveCriticalSection;
      LeaveCriticalSection(&gLock3);
      MakeAddressInfo(szAddress, "%d.%d.%d.%d", v3 >> 24, (v3 >> 16) & 0xFF, v3 >> 8, v3);
    }
  }
  _strlwr_s(szAddress, 0x104u);
  EnterCriticalSection(&gLock2);
  pItem = malloc(0x124u);
  strcpy_s(pItem->szAddress, 0x104u, szAddress);
  pItem->field_10C = v3;
  _mm_storeu_si128(&pItem->field_110, _mm_loadu_si128(&a1->field_110));
  pItem->field_0 = a1->field_0;
  pItem->pNext = gpItem124_InTcpUdp;
  v14 = dword_10C9E7C;
  gpItem124_InTcpUdp = pItem;
  if ( dword_10C9E7C )
  {
    while ( v14->field_10C != v3 )
    {
      v14 = v14->pNext;
      if ( !v14 )
        goto LABEL_15;
    }
    dword_10C9E7C = v14->pNext;
    free(v14);
  }
LABEL_15:
  SetEvent(ghEvent6);
  v2(&gLock2);
}

//----- (01022CD0) --------------------------------------------------------
char __cdecl WriteStringToList(HWND a1, unsigned int a2, int a3, unsigned int a4)
{
  int v4; // ebx
  volatile signed __int32 *v5; // eax
  unsigned int v6; // ecx
  unsigned int v7; // edx
  unsigned int v8; // esi
  unsigned int v9; // edi
  unsigned int v10; // ebx
  signed int v11; // edx
  int v12; // ecx
  unsigned int v13; // ebx
  WCHAR *v14; // eax
  int v15; // eax
  __int16 v16; // ax
  unsigned int v17; // ebx
  unsigned int v18; // esi
  unsigned int v19; // edi
  int v20; // ecx
  unsigned int v21; // ebx
  unsigned int v22; // edx
  int v23; // eax
  int v24; // edx
  LVITEMW Item; // [esp+4h] [ebp-30050h]
  unsigned int v27; // [esp+38h] [ebp-3001Ch]
  char *v28; // [esp+3Ch] [ebp-30018h]
  HWND hWnd; // [esp+40h] [ebp-30014h]
  WCHAR *v30; // [esp+44h] [ebp-30010h]
  int v31; // [esp+48h] [ebp-3000Ch]
  int v32; // [esp+4Ch] [ebp-30008h]
  char MultiByteStr[1024]; // [esp+50h] [ebp-30004h]
  char v34; // [esp+450h] [ebp-2FC04h]
  __int16 v35[65536]; // [esp+10050h] [ebp-20004h]

  v4 = a3;
  hWnd = a1;
  v32 = a3;
  Item.mask = 0;
  LOBYTE(v5) = memset(&Item.iItem, 0, 0x30u);
  v6 = a4;
  v7 = a2;
  if ( a4 >= a2 )
  {
    v8 = -1;
    v9 = 0;
    if ( a4 )
    {
      while ( 1 )
      {
        v10 = *(v4 + v9);
        v5 = _ismbcprint(v10);
        if ( !v5 && v10 != 126 )
        {
          if ( v8 != -1 )
          {
            v11 = a2;
            LOBYTE(v5) = 2 * a2;
            if ( v9 - v8 >= 2 * a2 )
            {
              v12 = 0;
              v13 = 0;
              v31 = 0;
              if ( v8 < v9 )
              {
                v14 = (a4 - a2 + 1);
                v30 = (a4 - a2 + 1);
                do
                {
                  if ( v8 >= v14 )
                    break;
                  v15 = iswalpha(*(v32 + v8));
                  v12 = v31;
                  if ( v15 )
                    v12 = v31++ + 1;
                  v16 = *(v32 + v8);
                  v8 += 2;
                  v35[v13++] = v16;
                  v14 = v30;
                }
                while ( v8 < v9 );
                v11 = a2;
              }
              v17 = v13;
              if ( v17 >= 0x10000 )
              {
LABEL_51:
                __report_rangecheckfailure();
                JUMPOUT(*algn_1022FF0);
              }
              LOBYTE(v5) = 0;
              v35[v17] = 0;
              if ( v12 >= v11 )
              {
                v34 = 0;
                Item.pszText = v35;
                Item.mask = 5;
                Item.iItem = 0x7FFFFFFF;
                Item.lParam = 1;
                LOBYTE(v5) = SendMessageW(hWnd, LVM_INSERTITEMW, 0, &Item);
              }
            }
            v8 = -1;
          }
          goto LABEL_24;
        }
        if ( v10 == 32 )
        {
          if ( v8 == -1 )
            goto LABEL_24;
        }
        else if ( v8 == -1 )
        {
          v8 = v9;
        }
        ++v9;
LABEL_24:
        v6 = a4;
        ++v9;
        v4 = v32;
        if ( v9 >= a4 )
        {
          v7 = a2;
          break;
        }
      }
    }
    v18 = -1;
    v19 = 0;
    if ( v6 )
    {
      do
      {
        LOBYTE(v5) = *(v4 + v19);
        if ( (v5 < 32 || v5 >= 126) && v5 != 126 )
        {
          if ( v18 != -1 )
          {
            LOBYTE(v5) = v19 - v18;
            if ( v19 - v18 >= v7 )
            {
              v20 = 0;
              v21 = 0;
              v31 = 0;
              if ( v18 < v19 )
              {
                v22 = a4 - v7 + 1;
                v27 = v22;
                v5 = &MultiByteStr[-v18];
                v28 = &MultiByteStr[-v18];
                do
                {
                  if ( v18 >= v22 )
                    break;
                  v23 = isalpha(*(v32 + v18));
                  v20 = v31;
                  if ( v23 )
                    v20 = v31++ + 1;
                  ++v21;
                  LOBYTE(v5) = *(v32 + v18);
                  v28[v18++] = v5;
                  v22 = v27;
                }
                while ( v18 < v19 );
                if ( v21 >= 0x10000 )
                  goto LABEL_51;
                v7 = a2;
              }
              MultiByteStr[v21] = 0;
              if ( v20 >= v7 )
              {
                sub_1014BD0(&v30, MultiByteStr);
                Item.pszText = v30;
                Item.mask = 5;
                Item.iItem = 0x7FFFFFFF;
                v34 = 0;
                Item.lParam = 1;
                SendMessageW(hWnd, 0x104Du, 0, &Item);
                v24 = (v30 - 8);
                v5 = (v30 - 2);
                if ( _InterlockedDecrement(v5) <= 0 )
                  LOBYTE(v5) = (*(**v24 + 4))(v24);
                v7 = a2;
              }
              v4 = v32;
              v6 = a4;
            }
            v18 = -1;
          }
        }
        else if ( v5 != 32 && v18 == -1 )
        {
          v18 = v19;
        }
        ++v19;
      }
      while ( v19 < v6 );
    }
  }
  return v5;
}
// 10667E8: using guessed type int __report_rangecheckfailure(void);
// 1022CD0: using guessed type __int16 var_20004[65536];
// 1022CD0: using guessed type CHAR MultiByteStr[1024];

//----- (01023000) --------------------------------------------------------
BOOL __cdecl IsServer(LPCWSTR lpszServerName)
{
  BOOL ret; // ebx
  WCHAR *pszSuiteName; // eax
  WCHAR *pszName; // edi
  WCHAR *lpszName; // esi
  DWORD dwType; // [esp+4h] [ebp-Ch]
  DWORD cbData; // [esp+8h] [ebp-8h]
  HKEY hKey; // [esp+Ch] [ebp-4h]

  ret = 0;
  hKey = 0;
  dwType = 0;
  cbData = 0;
  if ( !RegOpenKeyW(HKEY_LOCAL_MACHINE, L"System\\CurrentControlSet\\Control\\ProductOptions", &hKey)
    && !RegQueryValueExW(hKey, L"ProductSuite", 0u, &dwType, 0u, &cbData) )
  {
    if ( cbData )
    {
      pszSuiteName = LocalAlloc(LMEM_ZEROINIT, cbData);
      pszName = pszSuiteName;
      if ( pszSuiteName )
      {
        if ( !RegQueryValueExW(hKey, L"ProductSuite", 0u, &dwType, pszSuiteName, &cbData) && dwType == REG_MULTI_SZ )
        {
          lpszName = pszName;
          if ( *pszName )
          {
            while ( lstrcmpW(lpszName, lpszServerName) )
            {
              lpszName += lstrlenW(lpszName) + 1;
              if ( !*lpszName )
                goto __free;
            }
            ret = 1;
          }
        }
__free:
        LocalFree(pszName);
      }
    }
  }
  if ( hKey )
    RegCloseKey(hKey);
  return ret;
}

//----- (010230E0) --------------------------------------------------------
string *__thiscall sub_10230E0(void *this, int a2, int a3, int a4)
{
  _DWORD *v4; // edi
  string *v5; // esi
  unsigned int v6; // eax
  unsigned int v7; // ebx
  unsigned int v8; // eax
  int v9; // ecx
  string *v10; // ecx
  int v11; // ecx
  bool v12; // cf
  int v14; // [esp+14h] [ebp+8h]

  v4 = a2;
  v5 = this;
  v6 = *(a2 + 16);
  if ( v6 < a3 )
    std::_Xout_of_range("invalid string position");
  v7 = a4;
  v8 = v6 - a3;
  v9 = *(this + 4);
  v14 = v5->_Myval2._Mysize;
  if ( v8 < a4 )
    v7 = v8;
  if ( -1 - v9 <= v7 )
    std::_Xlength_error("string too long");
  if ( v7 && sub_FDFC40(v5, v9 + v7, 0) )
  {
    if ( v4[5] >= 8u )
      v4 = *v4;
    if ( v5->_Myval2._Myres < 8 )
      v10 = v5;
    else
      v10 = v5->_Myval2._Bx._Ptr;
    if ( v7 )
      memmove_0(&v10->_Myval2._Bx._Buf[v5->_Myval2._Mysize], v4 + 2 * a3, 2 * v7);
    v11 = v7 + v14;
    v12 = v5->_Myval2._Myres < 8;
    v5->_Myval2._Mysize = v7 + v14;
    if ( !v12 )
    {
      *&v5->_Myval2._Bx._Ptr[2 * v11] = 0;
      return v5;
    }
    v5->_Myval2._Bx._Buf[v11] = 0;
  }
  return v5;
}

//----- (010231B0) --------------------------------------------------------
string *__thiscall sub_10231B0(void *this, void *a2, int a3)
{
  void *v3; // edi
  string *v4; // esi
  unsigned int v5; // ecx
  unsigned int v6; // eax
  string *v7; // edx
  string *v8; // eax
  string *result; // eax
  char *v10; // ecx
  string *v11; // ecx
  int v12; // ecx
  bool v13; // cf
  char *v14; // [esp+10h] [ebp+8h]

  v3 = a2;
  v4 = this;
  if ( a2
    && ((v5 = *(this + 5), v5 < 8) ? (v6 = v4) : (v6 = v4->_Myval2._Bx._Ptr),
        a2 >= v6 && (v5 < 8 ? (v7 = v4) : (v7 = v4->_Myval2._Bx._Ptr), v7 + 2 * v4->_Myval2._Mysize > a2)) )
  {
    if ( v5 < 8 )
      v8 = v4;
    else
      v8 = v4->_Myval2._Bx._Ptr;
    result = sub_10230E0(v4, v4, (a2 - v8) >> 1, a3);
  }
  else
  {
    v10 = v4->_Myval2._Mysize;
    v14 = v10;
    if ( -1 - v10 <= a3 )
      std::_Xlength_error("string too long");
    if ( a3 && sub_FDFC40(v4, &v10[a3], 0) )
    {
      if ( v4->_Myval2._Myres < 8 )
        v11 = v4;
      else
        v11 = v4->_Myval2._Bx._Ptr;
      if ( a3 )
        memmove_0(&v11->_Myval2._Bx._Buf[v4->_Myval2._Mysize], v3, 2 * a3);
      v12 = &v14[a3];
      v13 = v4->_Myval2._Myres < 8;
      v4->_Myval2._Mysize = &v14[a3];
      if ( !v13 )
      {
        *&v4->_Myval2._Bx._Ptr[2 * v12] = 0;
        return v4;
      }
      v4->_Myval2._Bx._Buf[v12] = 0;
    }
    result = v4;
  }
  return result;
}

//----- (01023290) --------------------------------------------------------
LPCWSTR __cdecl PE_GetNumberFormat(LPCWSTR lpValue, rsize_t SizeInWords)
{
  wchar_t *v2; // eax
  __int16 NumberStr[1024]; // [esp+4h] [ebp-804h]

  GetNumberFormatW(0x400u, 0, lpValue, 0, NumberStr, 1024);
  wcscpy_s(lpValue, SizeInWords, NumberStr);
  v2 = wcsstr(lpValue, &gszLocaleInfo);
  if ( v2 )
    *v2 = 0;
  return lpValue;
}

//----- (01023300) --------------------------------------------------------
void __cdecl sub_1023300(wchar_t *a1)
{
  int v1; // edi
  int v2; // esi
  int v3; // edx
  WCHAR v4; // ax
  WCHAR v5; // cx
  wchar_t *v6; // esi
  wchar_t v7; // ax
  size_t v8; // esi
  wchar_t *v9; // edi
  wchar_t *v10; // ecx
  wchar_t v11; // ax
  DWORD cbData; // [esp+8h] [ebp-618h]
  WCHAR ValueName[2]; // [esp+Ch] [ebp-614h]
  HKEY phkResult; // [esp+10h] [ebp-610h]
  wchar_t v15[260]; // [esp+14h] [ebp-60Ch]
  BYTE v16[2]; // [esp+21Ch] [ebp-404h]
  wchar_t Dst; // [esp+21Eh] [ebp-402h]
  __int16 v18; // [esp+250h] [ebp-3D0h]
  BYTE Data[2]; // [esp+41Ch] [ebp-204h]
  char v20; // [esp+41Eh] [ebp-202h]
  WCHAR v21; // [esp+44Eh] [ebp-1D2h]

  *Data = 0;
  memset(&v20, 0, 0x1FEu);
  *v16 = 0;
  memset(&Dst, 0, 0x1FEu);
  *ValueName = 65;
  v1 = 0;
  if ( !RegOpenKeyW(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\RunMRU", &phkResult) )
  {
    cbData = 512;
    RegQueryValueExW(phkResult, L"MRUList", 0, 0, Data, &cbData);
    _wcslwr_s(Data, 0x100u);
    v2 = 0;
    if ( wcslen(Data) <= 0 )
    {
LABEL_8:
      wcscpy_s(&Dst, 0xFFu, Data);
      v18 = 0;
      v3 = 0;
      while ( (1 << v3) & v1 )
      {
        if ( ++v3 >= 26 )
        {
          v4 = *v16;
          goto LABEL_14;
        }
      }
      v4 = v3 + 97;
LABEL_14:
      v5 = v4;
      v6 = a1;
      if ( v3 == 26 )
        v5 = v21;
      *v16 = v5;
      ValueName[0] = v5;
      do
      {
        v7 = *v6;
        ++v6;
      }
      while ( v7 );
      v8 = v6 - (a1 + 1) + 3;
      v9 = malloc(2 * v8);
      swprintf_s(v9, v8, L"%s\\1", a1);
      v10 = v9;
      do
      {
        v11 = *v10;
        ++v10;
      }
      while ( v11 );
      RegSetValueExW(phkResult, ValueName, 0, 1u, v9, 2 * (v10 - (v9 + 1)) + 2);
      RegSetValueExW(phkResult, L"MRUList", 0, 1u, v16, 2 * wcslen(v16) + 2);
      RegCloseKey(phkResult);
      free(v9);
    }
    else
    {
      while ( 1 )
      {
        ValueName[0] = *&Data[2 * v2];
        cbData = 520;
        v1 |= 122 - ValueName[0] > 1;
        if ( !RegQueryValueExW(phkResult, ValueName, 0, 0, v15, &cbData) )
        {
          if ( wcsrchr(v15, 0x5Cu) )
            *wcsrchr(v15, 0x5Cu) = 0;
          if ( !_wcsicmp(a1, v15) )
            break;
        }
        if ( ++v2 >= wcslen(Data) )
          goto LABEL_8;
      }
      RegCloseKey(phkResult);
    }
  }
}

//----- (010235F0) --------------------------------------------------------
BOOL __cdecl ReplaceMenuIconFromStockIcon(HMENU hmenu, UINT item)
{
  DWORD v2; // esi
  MENUITEMINFOW mii; // [esp+8h] [ebp-24Ch]
  int v5; // [esp+38h] [ebp-21Ch]
  DWORD v6; // [esp+3Ch] [ebp-218h]

  v2 = dword_10C9E80;
  if ( !dword_10C9E80 )
  {
    memset(&v6, dword_10C9E80, 0x214u);
    v5 = 536;
    SHGetStockIconInfo(77, 257, &v5);
    v2 = v6;
    dword_10C9E80 = v6;
  }
  memset(&mii.fMask, 0, 0x2Cu);
  mii.cbSize = 48;
  mii.fMask = 160;
  mii.hbmpItem = -1;
  mii.dwItemData = v2;
  return SetMenuItemInfoW(hmenu, item, 0, &mii);
}
// 10DBA50: using guessed type int (__stdcall *SHGetStockIconInfo)(_DWORD, _DWORD, _DWORD);

//----- (010236B0) --------------------------------------------------------
bool __cdecl sub_10236B0(int a1, unsigned int a2, char a3, char a4)
{
  unsigned int v4; // esi
  _DWORD *v5; // edx

  v4 = 0;
  if ( !a2 )
    return 0;
  v5 = (a1 + 4);
  while ( *v5 != 1 && *v5 || !((1 << a3) & *(v5 - 1)) )
  {
    ++v4;
    v5 += 6;
    if ( v4 >= a2 )
      return 0;
  }
  return ((1 << a4) & *(a1 + 24 * v4)) != 0;
}

//----- (01023710) --------------------------------------------------------
HWND __cdecl PropSheet_UpdateTab(HWND hWnd)
{
  HWND hWndParent; // eax
  HWND hWndTab; // eax
  HWND v3; // edi
  struct tagRECT Rect; // [esp+8h] [ebp-14h]

  hWndParent = GetParent(hWnd);
  hWndTab = GetDlgItem(hWndParent, IDS_PROCPROPSHEET_TABCTRL);
  v3 = hWndTab;
  if ( hWndTab )
  {
    GetWindowRect(hWndTab, &Rect);
    SendMessageW(v3, TCM_ADJUSTRECT, 0, &Rect);
    MapWindowPoints(0, hWnd, &Rect, 2u);
    SetWindowPos(hWnd, 0, Rect.left, Rect.top, Rect.right - Rect.left, Rect.bottom - Rect.top, SWP_NOACTIVATE);
    hWndTab = gpfnEnableThemeDialogTexture;
    if ( gpfnEnableThemeDialogTexture )
      hWndTab = gpfnEnableThemeDialogTexture(hWnd, 6);
  }
  return hWndTab;
}
// 10C9E88: using guessed type int (__stdcall *gpfnEnableThemeDialogTexture)(_DWORD, _DWORD);

//----- (010237B0) --------------------------------------------------------
signed int __cdecl sub_10237B0(unsigned __int64 a1, unsigned __int64 a2)
{
  signed int result; // eax

  if ( HIDWORD(a1) < HIDWORD(a2) )
    goto LABEL_10;
  if ( HIDWORD(a1) > HIDWORD(a2) || a1 > a2 )
    return 1;
  if ( a1 >= a2 )
    result = 0;
  else
LABEL_10:
    result = -1;
  return result;
}

//----- (010237F0) --------------------------------------------------------
BOOL __cdecl sub_10237F0(char a1)
{
  DWORD v1; // esi
  HKEY phkResult; // [esp+4h] [ebp-418h]
  BYTE Data[2]; // [esp+8h] [ebp-414h]
  char v5; // [esp+Ah] [ebp-412h]

  *Data = 0;
  memset(&v5, 0, 0x40Eu);
  sub_1022850(Data, 0x208u);
  if ( gdwVersion < 1 )
  {
    v1 = RegOpenKeyExW(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Run", 0, 2u, &phkResult);
    if ( v1 )
    {
LABEL_10:
      SetLastError(v1);
      ReportMsg(L"Error configuring auto start", ghMainWnd);
      return v1 == 0;
    }
    if ( a1 )
    {
      wcscat_s(Data, 0x208u, L" /t");
      v1 = RegSetValueExW(phkResult, L"Process Explorer", 0, 1u, Data, 2 * wcslen(Data) + 2);
    }
    else
    {
      v1 = RegDeleteValueW(phkResult, L"Process Explorer");
      if ( v1 == 2 )
        v1 = 0;
    }
    RegCloseKey(phkResult);
  }
  else
  {
    v1 = sub_1021E50(a1, Data);
  }
  if ( v1 )
    goto LABEL_10;
  return v1 == 0;
}
// 109F218: using guessed type wchar_t aErrorConfiguri[29];
// 10C4E54: using guessed type int gdwVersion;

//----- (01023940) --------------------------------------------------------
LRESULT __cdecl CTreeList::InitToolTips(HWND hWnd)
{
  SendMessageW(hWnd, TTM_SETDELAYTIME, 3u, 0);
  SendMessageW(hWnd, TTM_SETMAXTIPWIDTH, 0, 4000);
  return SendMessageW(hWnd, TTM_SETDELAYTIME, 2u, 1000000);
}

//----- (01023980) --------------------------------------------------------
BOOL __cdecl DrawLine(HWND hWnd, int y)
{
  HPEN hPen; // eax
  HPEN v3; // esi
  HPEN ho; // ST1C_4
  HDC hDC; // eax
  HDC v6; // ebx
  HDC hdc; // ST24_4
  HGDIOBJ hOldpen; // edi
  struct tagRECT rcClient; // [esp+18h] [ebp-14h]

  hPen = CreatePen(PS_COSMETIC, 5, 0);
  v3 = hPen;
  ho = hPen;
  GetClientRect(hWnd, &rcClient);
  hDC = GetDC(hWnd);
  v6 = hDC;
  hdc = hDC;
  hOldpen = SelectObject(hDC, v3);
  SetROP2(v6, R2_NOT);
  MoveToEx(hdc, 0, y + 6, 0);
  LineTo(hdc, rcClient.right, y + 6);
  SelectObject(hdc, hOldpen);
  SetROP2(hdc, R2_NOP);
  ReleaseDC(hWnd, hdc);
  return DeleteObject(ho);
}

//----- (01023A30) --------------------------------------------------------
char __cdecl MakeApplicationName(LPCWSTR lpFileName, wchar_t *Src, int a3, wchar_t *Dst)
{
  char result; // al
  rsize_t v5; // ebx
  wchar_t *v6; // edi
  wchar_t *v7; // esi
  wchar_t *v8; // eax
  wchar_t *v9; // eax

  if ( GetFileAttributesW(lpFileName) == -1 )
  {
    v5 = wcslen(lpFileName) + a3 + 2;
    v6 = Src;
    v7 = malloc(2 * v5);
    if ( Src )
    {
      while ( *v6 )
      {
        wcscpy_s(v7, v5, v6);
        v8 = wcschr(v7, 0x3Bu);
        if ( v8 )
          *v8 = 0;
        wcscat_s(v7, v5, L"\\");
        wcscat_s(v7, v5, lpFileName);
        if ( GetFileAttributesW(v7) != -1 )
        {
          wcscpy_s(Dst, 0x104u, v7);
          j__free(v7);
          return 1;
        }
        v9 = wcschr(v6, 0x3Bu);
        if ( v9 )
        {
          v6 = v9 + 1;
          if ( v9 != -2 )
            continue;
        }
        break;
      }
    }
    j__free(v7);
    result = 0;
  }
  else
  {
    wcscpy_s(Dst, 0x104u, lpFileName);
    result = 1;
  }
  return result;
}

//----- (01023B30) --------------------------------------------------------
HWND __cdecl QueryTopMostWindowByProcessID(int dwProcessId_1)
{
  HWND ret; // edi
  HWND hWndFound; // esi
  HWND v3; // eax
  HWND v4; // eax
  DWORD dwPid; // [esp+8h] [ebp-1004h]
  WINDOWPLACEMENT wp; // [esp+Ch] [ebp-1000h]
  WCHAR szText[2024]; // [esp+38h] [ebp-FD4h]

  ret = 0;
  hWndFound = FindWindowExW(0, 0, 0, 0);
  if ( !hWndFound )
    return 0;
  do
  {
    GetWindowThreadProcessId(hWndFound, &dwPid);
    if ( dwPid == dwProcessId_1 && (IsWindowVisible(hWndFound) || IsIconic(hWndFound)) )
    {
      if ( !IsIconic(hWndFound)
        || (GetWindowPlacement(hWndFound, &wp), wp.rcNormalPosition.right - wp.rcNormalPosition.left > 1) )
      {
        if ( GetWindowTextW(hWndFound, szText, 2024) )
        {
          ret = hWndFound;
          if ( !GetParent(hWndFound) )
            break;
          v3 = GetParent(hWndFound);
          if ( !GetParent(v3) )
          {
            v4 = GetParent(hWndFound);
            if ( !IsWindowVisible(v4) )
              break;
          }
        }
      }
    }
    hWndFound = FindWindowExW(0, hWndFound, 0, 0);
  }
  while ( hWndFound );
  return ret;
}

//----- (01023C40) --------------------------------------------------------
int __cdecl PE_FormatDoubleFlow(WCHAR *pszText, DWORD dwLength, double dbValue)
{
  double dbValueNew; // xmm0_8
  const wchar_t *pszUnit; // [esp+8h] [ebp-4Ch]
  __int16 szBuffer[32]; // [esp+10h] [ebp-44h]

  szBuffer[0] = 0;
  memset(&szBuffer[1], 0, 62u);
  dbValueNew = dbValue;
  if ( dbValue < 1073741824.0 )
  {
    if ( dbValue < 1048576.0 )
    {
      if ( dbValue < 1024.0 )
        goto LABEL_8;
      dbValueNew = dbValue * 0.0009765625;
      pszUnit = L" KB";
    }
    else
    {
      dbValueNew = dbValue * 0.00000095367431640625;
      pszUnit = L" MB";
    }
  }
  else
  {
    dbValueNew = dbValue * 9.313225746154785e-10;
    pszUnit = L" GB";
  }
  wcscpy_s(szBuffer, 32u, pszUnit);
LABEL_8:
  if ( szBuffer[0] )
    return swprintf_s(pszText, dwLength, L"%0.1f %s", LODWORD(dbValueNew), HIDWORD(dbValueNew), szBuffer);
  if ( dbValueNew == 0.0 )
    return swprintf_s(pszText, dwLength, L"0");
  return swprintf_s(pszText, dwLength, L"%0.0f B", LODWORD(dbValueNew), HIDWORD(dbValueNew));
}
// 109CBE0: using guessed type wchar_t aGb[4];

//----- (01023D60) --------------------------------------------------------
char __cdecl UserInfoWithSIDList_Find(PSID pSID, LPWSTR pszName, DWORD cbName, LPWSTR pszDomainName, DWORD cbDomainName)
{
  tagUserInfoWithSID *v5; // esi
  tagUserInfoWithSID *v6; // edi
  DWORD v7; // eax
  void *v8; // eax
  void *v9; // ST14_4
  DWORD v10; // eax
  char result; // al
  enum _SID_NAME_USE nUse; // [esp+Ch] [ebp-4h]

  v5 = gpUserInfoWithSIDList;
  if ( gpUserInfoWithSIDList )
  {
    while ( !EqualSid(v5->pSID, pSID) )
    {
      v5 = v5->pNext;
      if ( !v5 )
        goto LABEL_4;
    }
    wcscpy_s(pszName, cbName, v5->szName);
    wcscpy_s(pszDomainName, cbDomainName, v5->szDomainName);
    result = 1;
  }
  else
  {
LABEL_4:
    if ( LookupAccountSidW(&gszNullString, pSID, pszName, &cbName, pszDomainName, &cbDomainName, &nUse) )
    {
      v6 = malloc(sizeof(tagUserInfoWithSID));
      v7 = GetLengthSid(pSID);
      v8 = malloc(v7);
      v6->pSID = v8;
      v9 = v8;
      v10 = GetLengthSid(pSID);
      CopySid(v10, v9, pSID);
      wcscpy_s(v6->szName, 0x104u, pszName);
      wcscpy_s(v6->szDomainName, 0x104u, pszDomainName);
      v6->pNext = gpUserInfoWithSIDList;
      result = 1;
      gpUserInfoWithSIDList = v6;
    }
    else
    {
      result = 0;
    }
  }
  return result;
}

//----- (01023E70) --------------------------------------------------------
int *__cdecl sub_1023E70(PSYSTEM_LOGICAL_PROCESSOR_INFORMATION pSystemLogicalProcessorInfo, int dwCount, signed int dwProcessorID, signed int *pnValue1, int *pnValue2)
{
  int dwCount_1; // edi
  signed int v6; // ecx
  signed int dwProcessorCoreCount_1; // ebx
  unsigned int dwNumaNodeCount; // esi
  signed int dwProcessorCoreCount; // edx
  PUCHAR pRelationShip; // ecx
  int RelationShip; // eax
  int *result; // eax
  signed int NodeNumber; // [esp+Ch] [ebp-4h]

  dwCount_1 = dwCount;
  v6 = -1;
  dwProcessorCoreCount_1 = -1;
  NodeNumber = -1;
  dwNumaNodeCount = -1;
  dwProcessorCoreCount = 0;
  if ( !dwCount )
    goto __quit;
  pRelationShip = &pSystemLogicalProcessorInfo->Relationship;
  do
  {
    if ( (1 << dwProcessorID) & *(pRelationShip - 1) )
    {
      RelationShip = *pRelationShip;
      if ( *pRelationShip == RelationNumaNode )
      {
        NodeNumber = *(pRelationShip + 1);
      }
      else
      {
        if ( RelationShip )
          goto LABEL_10;
        // RelationProcessorCore
        dwProcessorCoreCount_1 = dwProcessorCoreCount;
      }
    }
    RelationShip = *pRelationShip;
    if ( !*pRelationShip )
    {
      // RelationProcessorCore
      ++dwProcessorCoreCount;
      goto __Next;
    }
LABEL_10:
    if ( RelationShip == RelationNumaNode )
      ++dwNumaNodeCount;
__Next:
    pRelationShip += sizeof(SYSTEM_LOGICAL_PROCESSOR_INFORMATION);
    --dwCount_1;
  }
  while ( dwCount_1 );
  if ( dwNumaNodeCount > 1 )
  {
    v6 = NodeNumber;
__quit:
    *pnValue1 = v6;
    result = pnValue2;
    *pnValue2 = 1;
    return result;
  }
  if ( dwProcessorCoreCount_1 == -1 )
  {
    *pnValue1 = dwProcessorID;
    result = pnValue2;
    *pnValue2 = -1;
  }
  else
  {
    *pnValue1 = dwProcessorCoreCount_1;
    result = pnValue2;
    *pnValue2 = 0;
  }
  return result;
}
// 1023ECC: CONTAINING_RECORD: no field 'PUCHAR' in struct 'SYSTEM_LOGICAL_PROCESSOR_INFORMATION' at 24

//----- (01023F20) --------------------------------------------------------
int __cdecl sub_1023F20(_DWORD *a1, unsigned int a2, int a3)
{
  int v3; // edx
  _DWORD *v4; // esi
  unsigned int v5; // ecx
  int v7; // [esp+Ch] [ebp-4h]

  v3 = 0;
  v7 = 0;
  if ( a2 )
  {
    v4 = a1;
    while ( 2 )
    {
      v5 = 0;
      do
      {
        if ( !v4[1] )
        {
          if ( (1 << v5) & *v4 && a3 == v3 )
            return v5;
          ++v3;
        }
        ++v5;
      }
      while ( v5 < 0x20 );
      v4 += 6;
      if ( ++v7 < a2 )
        continue;
      break;
    }
  }
  return a3;
}

//----- (01023F80) --------------------------------------------------------
void __cdecl PE_LoadProductCopyright(wchar_t *pszFileName_1, _bstr_t *strText1, _bstr_t *strText2, _bstr_t *bstrDesc, _bstr_t *strCopyright)
{
  wchar_t *v5; // ecx
  wchar_t v6; // ax
  Data_t_bstr_t *v7; // esi
  const wchar_t *v8; // eax
  const wchar_t *v9; // eax
  wchar_t *v10; // eax
  _bstr_t *bstrPid; // edi
  Data_t_bstr_t *v12; // eax
  const WCHAR *bstrKeyName; // eax
  bool lRet; // bl
  OLECHAR *v15; // eax
  HKEY v16; // ST20_4
  _bstr_t *v17; // eax
  Data_t_bstr_t *v18; // eax
  const WCHAR *bstrKeyName2; // eax
  bool v20; // bl
  WCHAR *pstrEnvKey; // eax
  wchar_t *pszFileName; // edi
  WCHAR *v23; // ecx
  int v24; // edx
  WCHAR v25; // ax
  Data_t_bstr_t *v26; // eax
  WCHAR **v27; // ST10_4
  DWORD cbData; // [esp+Ch] [ebp-2A8h]
  DWORD dwLen; // [esp+10h] [ebp-2A4h]
  _bstr_t a1; // [esp+14h] [ebp-2A0h]
  _bstr_t bstrResult; // [esp+18h] [ebp-29Ch]
  HKEY hSubKey; // [esp+1Ch] [ebp-298h]
  _bstr_t str; // [esp+20h] [ebp-294h]
  _bstr_t bstrText; // [esp+24h] [ebp-290h]
  WCHAR szValue[260]; // [esp+28h] [ebp-28Ch]
  __int16 Dst[64]; // [esp+230h] [ebp-84h]

  bstrResult.m_Data = strText1;
  v5 = pszFileName_1;
  dwLen = bstrDesc;
  bstrText.m_Data = 0;
  do
  {
    v6 = *v5;
    ++v5;
  }
  while ( v6 );
  _wcsupr_s(pszFileName_1, v5 - (pszFileName_1 + 1) + 1);
  _bstr_t::operator=(&bstrText, pszFileName_1);
  v7 = bstrText.m_Data;
  if ( bstrText.m_Data )
    v8 = bstrText.m_Data->m_wstr;
  else
    v8 = 0;
  if ( wcsstr(v8, L"/PROCESSID:") )
  {
    if ( v7 )
      v9 = v7->m_wstr;
    else
      v9 = 0;
    v10 = wcsstr(v9, L"/PROCESSID:");
    bstrPid = _bstr_t::_bstr_t(&str, v10 + 11);
    if ( &bstrText != bstrPid )
    {
      _bstr_t::_Free(&bstrText);
      v7 = bstrPid->m_Data;
      bstrText.m_Data = v7;
      if ( v7 )
        InterlockedIncrement(&v7->m_RefCount);
    }
    _bstr_t::_Free(&str);
    v12 = _bstr_t::operator+(&str, L"CLSID\\", &bstrText)->m_Data;
    if ( v12 )
      bstrKeyName = v12->m_wstr;
    else
      bstrKeyName = 0;
    lRet = RegOpenKeyExW(HKEY_CLASSES_ROOT, bstrKeyName, 0, KEY_READ, &hSubKey) == 0;
    _bstr_t::_Free(&str);
    if ( lRet )
    {
      cbData = 520;
      if ( !RegQueryValueExW(hSubKey, 0, 0, 0, szValue, &cbData) )
      {
        v15 = _wcsdup(szValue);
        v16 = hSubKey;
        bstrResult.m_Data->m_wstr = v15;
        RegCloseKey(v16);
      }
      _bstr_t::_bstr_t(&str, L"\\InProcServer32");
      v17 = _bstr_t::operator+(&a1, L"CLSID\\", &bstrText);
      v18 = _bstr_t::operator+(v17, &bstrResult, &str)->m_Data;
      if ( v18 )
        bstrKeyName2 = v18->m_wstr;
      else
        bstrKeyName2 = 0;
      v20 = RegOpenKeyExW(HKEY_CLASSES_ROOT, bstrKeyName2, 0, KEY_READ, &hSubKey) == 0;
      _bstr_t::_Free(&bstrResult);
      _bstr_t::_Free(&a1);
      _bstr_t::_Free(&str);
      if ( v20 )
      {
        pstrEnvKey = PE_LoadEnvKey(hSubKey, 0);
        pszFileName = pstrEnvKey;
        if ( pstrEnvKey )
        {
          v23 = pstrEnvKey;
          v24 = (pstrEnvKey + 1);
          do
          {
            v25 = *v23;
            ++v23;
          }
          while ( v25 );
          _wcslwr_s(pszFileName, ((v23 - v24) >> 1) + 1);
          v26 = _wcsdup(pszFileName);
          v27 = dwLen;
          strText2->m_Data = v26;
          PE_GetProductCopyright(pszFileName, Dst, 0x40u, v27, strCopyright);
          free(pszFileName);
        }
        RegCloseKey(hSubKey);
      }
    }
  }
  if ( v7 && !InterlockedDecrement(&v7->m_RefCount) )
  {
    if ( v7->m_wstr )
    {
      SysFreeString(v7->m_wstr);
      v7->m_wstr = 0;
    }
    if ( v7->m_str )
    {
      j_j__free(v7->m_str);
      v7->m_str = 0;
    }
    j__free(v7);
  }
}

//----- (01024280) --------------------------------------------------------
wchar_t *__cdecl sub_1024280(wchar_t *a1)
{
  rsize_t v1; // ebx
  wchar_t *v2; // esi
  wchar_t *v3; // eax
  wchar_t *result; // eax
  WCHAR Buffer; // [esp+Ch] [ebp-20Ch]
  wchar_t v6; // [esp+12h] [ebp-206h]

  GetSystemDirectoryW(&Buffer, 0x104u);
  v1 = wcslen(&Buffer) + wcslen(a1) + 19;
  v2 = malloc(2 * v1);
  *wcschr(&v6, 0x5Cu) = 0;
  if ( _wcsnicmp(a1, L"\\SystemRoot\\", 0xCu) )
  {
    if ( !wcsncmp(a1, L"\\??\\", 4u) )
    {
      wcscpy_s(v2, v1, a1 + 4);
      result = v2;
    }
    else
    {
      if ( *a1 == 92 )
        swprintf_s(v2, v1, L"%c:%s", Buffer, a1);
      else
        swprintf_s(v2, v1, L"%s\\System32\\Drivers\\%s", &Buffer, a1);
      result = v2;
    }
  }
  else
  {
    v3 = wcschr(a1 + 1, 0x5Cu);
    swprintf_s(v2, v1, L"%s%s", &Buffer, v3);
    result = v2;
  }
  return result;
}
// 109EF74: using guessed type wchar_t aCS[6];

//----- (010243C0) --------------------------------------------------------
DWORD __cdecl PE_GetProductCopyright(LPCWSTR lpszFileName, wchar_t *pszBuffer, rsize_t cbBufLen, WCHAR **ppszDesc, WCHAR **ppszCopyright)
{
  WCHAR **v5; // edi
  DWORD v6; // eax
  int *pBlock; // esi
  const wchar_t *pszFileDesc; // eax
  const wchar_t *pszCompany; // eax
  DWORD dwHandle; // [esp+8h] [ebp-4h]
  WCHAR **dwLena; // [esp+20h] [ebp+14h]

  wcscpy_s(pszBuffer, cbBufLen, &gszNullString);
  v5 = ppszDesc;
  *ppszDesc = 0;
  *ppszCopyright = 0;
  v6 = GetFileVersionInfoSizeW(lpszFileName, &dwHandle);
  dwLena = v6;
  if ( !v6 )
    return GetLastError();
  pBlock = malloc(v6);
  if ( GetFileVersionInfoW(lpszFileName, 0, dwLena, pBlock) )
  {
    PE_MakeFileVersion(pBlock[13], pBlock[12], pszBuffer, cbBufLen);
    pszFileDesc = PE_QueryFileVersionBlock(pBlock, L"FileDescription");
    if ( pszFileDesc || (pszFileDesc = PE_QueryFileVersionBlock(pBlock, L"ProductDescription")) != 0 )
      *v5 = _wcsdup(pszFileDesc);
    pszCompany = PE_QueryFileVersionBlock(pBlock, L"CompanyName");
    if ( pszCompany || (pszCompany = PE_QueryFileVersionBlock(pBlock, L"Copyright")) != 0 )
      *ppszCopyright = _wcsdup(pszCompany);
  }
  free(pBlock);
  return 0;
}

//----- (010244B0) --------------------------------------------------------
char __cdecl sub_10244B0(int a1, char a2, int a3, u_long hostlong, tagItem124_InTcpUdp *a5, wchar_t *Dst, size_t SizeInWords)
{
  unsigned int v7; // eax
  unsigned int v8; // ebx
  int v9; // ST28_4
  int v10; // ST24_4
  int v11; // ST20_4
  int v12; // ST1C_4
  int v13; // ST18_4
  int v14; // ST14_4
  int v15; // ST10_4
  u_short v16; // ax
  char result; // al
  tagItem124_InTcpUdp *v18; // eax
  tagItem124_InTcpUdp *v19; // ecx

  v7 = htonl(hostlong);
  v8 = v7;
  if ( a2 )
  {
    if ( sub_1022910(a1, v7, a5, Dst, SizeInWords) )
    {
      result = 1;
    }
    else
    {
      swprintf_s(Dst, SizeInWords, L"%d.%d.%d.%d", v8 >> 24, (v8 >> 16) & 0xFF, v8 >> 8, v8);
      EnterCriticalSection(&gLock2);
      v18 = dword_10C9E7C;
      if ( dword_10C9E7C )
      {
        while ( v18->field_10C != v8 )
        {
          v18 = v18->pNext;
          if ( !v18 )
            goto LABEL_11;
        }
      }
      else
      {
LABEL_11:
        v19 = malloc(0x124u);
        v19->field_0 = a1;
        v19->field_108 = hostlong;
        v19->field_10C = v8;
        if ( a5 )
          _mm_storeu_si128(&v19->field_110, _mm_loadu_si128(a5));
        v19->pNext = dword_10C9E7C;
        dword_10C9E7C = v19;
        _beginthread(tagItem124_InTcpUdp_Query, 0, v19);
      }
      LeaveCriticalSection(&gLock2);
      result = 0;
    }
  }
  else if ( a1 && a1 != 1 )
  {
    v9 = htons(*&a5->szAddress[10]);
    v10 = htons(*&a5->szAddress[8]);
    v11 = htons(*&a5->szAddress[6]);
    v12 = htons(*&a5->szAddress[4]);
    v13 = htons(*&a5->szAddress[2]);
    v14 = htons(*a5->szAddress);
    v15 = htons(HIWORD(a5->field_0));
    v16 = htons(a5->field_0);
    swprintf_s(Dst, SizeInWords, L"[%x:%x:%x:%x:%x:%x:%x:%x]", v16, v15, v14, v13, v12, v11, v10, v9);
    result = 0;
  }
  else
  {
    swprintf_s(Dst, SizeInWords, L"%d.%d.%d.%d", v7 >> 24, (v7 >> 16) & 0xFF, v7 >> 8, v7);
    result = 0;
  }
  return result;
}

//----- (01024670) --------------------------------------------------------
wchar_t *__cdecl sub_1024670(char a1, int port, char *proto, wchar_t *Dst, size_t SizeInWords)
{
  u_short v5; // ax
  struct servent *v6; // eax

  if ( a1 )
  {
    v6 = getservbyport(port, proto);
    if ( v6 )
    {
      swprintf_s(Dst, SizeInWords, L":%S", v6->s_name);
      return Dst;
    }
    v5 = htons(port);
  }
  else
  {
    v5 = htons(port);
  }
  swprintf_s(Dst, SizeInWords, L":%d", v5);
  return Dst;
}

//----- (010246D0) --------------------------------------------------------
wchar_t *__cdecl ProcessComment_Find(wchar_t *ProcessName)
{
  int index; // esi
  tagProcessComment *pHiddenProcesses; // eax
  int v3; // ecx
  bool found; // zf

  index = 0;
  if ( !ProcessName )
    return 0;
  pHiddenProcesses = gpProcessComments;
  if ( !gpProcessComments || !gpProcessComments->pszName )
    return 0;
  v3 = 0;
  while ( 1 )
  {
    found = _wcsicmp(ProcessName, pHiddenProcesses[v3].pszName) == 0;
    pHiddenProcesses = gpProcessComments;
    if ( found )
      break;
    v3 = ++index;
    if ( !gpProcessComments[index].pszName )
      return 0;
  }
  return _wcsdup(gpProcessComments[index].pszComment);
}

//----- (01024730) --------------------------------------------------------
int __cdecl sub_1024730(wchar_t *a1, int a2)
{
  int result; // eax

  *a2 = 0;
  result = wcsstr(a1, L"-k");
  if ( result )
  {
    result = (wcsstr(a1, L"-k") + 3);
    if ( result )
    {
      result = _wcsdup(result);
      *a2 = result;
    }
  }
  return result;
}

//----- (01024780) --------------------------------------------------------
WCHAR *__cdecl sub_1024780(wchar_t *a1, LPCWSTR lpServiceName)
{
  WCHAR *v2; // ebx
  wchar_t *v3; // esi
  wchar_t *v4; // ecx
  wchar_t v5; // ax
  LPCWSTR v6; // ecx
  WCHAR v7; // ax
  wchar_t *v8; // esi
  WCHAR *result; // eax
  DWORD v10; // esi
  DWORD v11; // ST10_4
  SC_HANDLE v12; // esi
  DWORD v13; // eax
  DWORD v14; // edi
  DWORD v15; // eax
  DWORD v16; // edi
  WCHAR *v17; // esi
  LPWSTR FilePart; // [esp+Ch] [ebp-14h]
  struct _QUERY_SERVICE_CONFIGW *v19; // [esp+10h] [ebp-10h]
  DWORD pcbBytesNeeded; // [esp+14h] [ebp-Ch]
  SC_HANDLE hService; // [esp+18h] [ebp-8h]
  HKEY phkResult; // [esp+1Ch] [ebp-4h]

  v2 = 0;
  v3 = _wcsdup(a1);
  v4 = v3;
  do
  {
    v5 = *v4;
    ++v4;
  }
  while ( v5 );
  _wcsupr_s(v3, v4 - (v3 + 1) + 1);
  if ( wcsstr(v3, L"SVCHOST.EXE") )
  {
    v6 = lpServiceName;
    do
    {
      v7 = *v6;
      ++v6;
    }
    while ( v7 );
    hService = (v6 - (lpServiceName + 1) + 46);
    v8 = malloc(2 * hService);
    swprintf_s(v8, hService, L"System\\CurrentControlSet\\Services\\%s", lpServiceName);
    if ( !RegOpenKeyExW(HKEY_LOCAL_MACHINE, v8, 0, 0x20019u, &phkResult) )
    {
      v2 = PE_LoadEnvKey(phkResult, L"ServiceDll");
      if ( !v2 )
      {
        RegCloseKey(phkResult);
        swprintf_s(v8, hService, L"System\\CurrentControlSet\\Services\\%s\\Parameters", lpServiceName);
        if ( !RegOpenKeyExW(HKEY_LOCAL_MACHINE, v8, 0, 0x20019u, &phkResult) )
        {
          v2 = PE_LoadEnvKey(phkResult, L"ServiceDll");
          RegCloseKey(phkResult);
        }
      }
    }
  }
  else
  {
    result = OpenServiceW(ghSCManagerHandle, lpServiceName, 5u);
    hService = result;
    if ( !result )
      return result;
    QueryServiceConfigW(result, 0, 0, &pcbBytesNeeded);
    v10 = pcbBytesNeeded;
    v19 = malloc(pcbBytesNeeded);
    v11 = v10;
    v12 = hService;
    QueryServiceConfigW(hService, v19, v11, &pcbBytesNeeded);
    CloseServiceHandle(v12);
    v8 = v19;
    v13 = ExpandEnvironmentStringsW(v19->lpBinaryPathName, 0, 0);
    v14 = v13;
    if ( v13 )
    {
      v2 = malloc(2 * v13);
      ExpandEnvironmentStringsW(v19->lpBinaryPathName, v2, v14);
    }
  }
  free(v8);
  if ( GetFileAttributesW(v2) == -1 )
  {
    v15 = SearchPathW(0, v2, 0, 0, 0, 0);
    v16 = v15;
    if ( v15 )
    {
      v17 = malloc(2 * v15);
      SearchPathW(0, v2, 0, v16, v17, &FilePart);
      _wcslwr_s(v17, v16);
      free(v2);
      v2 = v17;
    }
  }
  return v2;
}

//----- (01024990) --------------------------------------------------------
wchar_t *__cdecl sub_1024990(int a1)
{
  wchar_t *v1; // ebx
  Data_t_bstr_t *v2; // esi
  LPVOID v3; // ecx
  int v4; // edx
  int v5; // edi
  int v6; // ecx
  LONG i; // ebx
  __m128i v8; // xmm0
  _bstr_t v9; // edx
  int v10; // edi
  _bstr_t *v11; // eax
  _bstr_t *v12; // eax
  _bstr_t *v13; // eax
  _bstr_t *v14; // eax
  _bstr_t *v15; // eax
  _bstr_t *v16; // eax
  _bstr_t *v17; // eax
  int v19; // [esp-40h] [ebp-FCh]
  int v20; // [esp-3Ch] [ebp-F8h]
  int v21; // [esp-38h] [ebp-F4h]
  int v22; // [esp-34h] [ebp-F0h]
  int v23; // [esp-30h] [ebp-ECh]
  int v24; // [esp-2Ch] [ebp-E8h]
  int v25; // [esp-28h] [ebp-E4h]
  int v26; // [esp-24h] [ebp-E0h]
  int v27; // [esp-20h] [ebp-DCh]
  int v28; // [esp-1Ch] [ebp-D8h]
  int v29; // [esp-18h] [ebp-D4h]
  int v30; // [esp-14h] [ebp-D0h]
  int v31; // [esp-10h] [ebp-CCh]
  LPVOID v32; // [esp-Ch] [ebp-C8h]
  _bstr_t *v33; // [esp-8h] [ebp-C4h]
  int *v34; // [esp-4h] [ebp-C0h]
  __int128 v35; // [esp+Ch] [ebp-B0h]
  __int128 v36; // [esp+1Ch] [ebp-A0h]
  __int128 v37; // [esp+2Ch] [ebp-90h]
  VARIANTARG v38; // [esp+3Ch] [ebp-80h]
  VARIANTARG v39; // [esp+4Ch] [ebp-70h]
  VARIANTARG pvarg; // [esp+5Ch] [ebp-60h]
  VARIANTARG v41; // [esp+6Ch] [ebp-50h]
  OLECHAR *psz; // [esp+7Ch] [ebp-40h]
  _bstr_t a1a; // [esp+80h] [ebp-3Ch]
  _bstr_t v44; // [esp+84h] [ebp-38h]
  int v45; // [esp+88h] [ebp-34h]
  _bstr_t v46; // [esp+8Ch] [ebp-30h]
  OLECHAR *v47; // [esp+90h] [ebp-2Ch]
  _bstr_t v48; // [esp+94h] [ebp-28h]
  _bstr_t v49; // [esp+98h] [ebp-24h]
  _bstr_t v50; // [esp+9Ch] [ebp-20h]
  _bstr_t v51; // [esp+A0h] [ebp-1Ch]
  int v52; // [esp+A4h] [ebp-18h]
  _bstr_t v53; // [esp+A8h] [ebp-14h]
  _bstr_t *v54; // [esp+ACh] [ebp-10h]
  LPVOID ppv; // [esp+B0h] [ebp-Ch]
  _bstr_t *v56; // [esp+B4h] [ebp-8h]
  _bstr_t v57; // [esp+B8h] [ebp-4h]

  v1 = 0;
  v2 = 0;
  ppv = 0;
  v57.m_Data = 0;
  if ( CoCreateInstance(&stru_109F100, 0, 1u, &CLSID_ITaskService, &ppv) >= 0 )
  {
    VariantInit(&pvarg);
    _mm_storeu_si128(&v37, _mm_loadu_si128(&pvarg));
    VariantInit(&v39);
    _mm_storeu_si128(&v36, _mm_loadu_si128(&v39));
    VariantInit(&v38);
    _mm_storeu_si128(&v35, _mm_loadu_si128(&v38));
    VariantInit(&v41);
    v3 = ppv;
    v4 = *ppv;
    _mm_storeu_si128(&v31, _mm_loadu_si128(&v37));
    _mm_storeu_si128(&v27, _mm_loadu_si128(&v36));
    _mm_storeu_si128(&v23, _mm_loadu_si128(&v35));
    _mm_storeu_si128(&v19, _mm_loadu_si128(&v41));
    v5 = (*(v4 + 40))(v3, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34);
    VariantClear(&v41);
    VariantClear(&v38);
    VariantClear(&v39);
    VariantClear(&pvarg);
    if ( v5 >= 0 )
    {
      v34 = &v56;
      v56 = 0;
      v33 = 1;
      v6 = *ppv;
      v32 = ppv;
      if ( (*(v6 + 32))(ppv, 1, &v56) >= 0 )
      {
        v34 = &v52;
        v33 = v56;
        (v56->m_Data[2].m_str)(v56, &v52);
        for ( i = 1; i < v52 + 1; ++i )
        {
          v41.vt = 3;
          v34 = &v54;
          v41.lVal = i;
          v8 = _mm_loadu_si128(&v41);
          v9.m_Data = v56->m_Data;
          v29 = v56;
          _mm_storeu_si128(&v30, v8);
          v10 = (v9.m_Data[2].m_RefCount)(v29, v30, v31, v32, v33, v34);
          VariantClear(&v41);
          if ( v10 >= 0 )
          {
            v34 = &v45;
            v33 = v54;
            if ( (v54->m_Data[4].m_RefCount)(v54, &v45) >= 0 && v45 == a1 )
            {
              v34 = &psz;
              v33 = v54;
              if ( (v54->m_Data[3].m_RefCount)(v54, &psz) >= 0 )
              {
                if ( v2 )
                {
                  if ( v2->m_wstr )
                  {
                    v34 = v2->m_wstr;
                    if ( SysStringLen(v34) )
                    {
                      v11 = _bstr_t::_bstr_t(&v48, L"\n");
                      v12 = _bstr_t::operator+(&v57, &v44, v11);
                      sub_FD3A50(&v57, v12);
                      _bstr_t::_Free(&v44);
                      _bstr_t::_Free(&v48);
                    }
                  }
                }
                v13 = _bstr_t::_bstr_t(&v51, psz);
                v14 = _bstr_t::operator+(&a1a, L"   ", v13);
                _bstr_t::operator+=(&v57, v14);
                _bstr_t::_Free(&a1a);
                _bstr_t::_Free(&v51);
                v34 = &v47;
                v33 = v54;
                if ( (v54->m_Data[3].m_wstr)(v54, &v47) >= 0 )
                {
                  _bstr_t::_bstr_t(&v53, L"]");
                  v34 = &v53;
                  v33 = &v46;
                  v15 = _bstr_t::_bstr_t(&v49, v47);
                  v16 = _bstr_t::operator+(&v50, L" [", v15);
                  v17 = _bstr_t::operator+(v16, v33, v34);
                  _bstr_t::operator+=(&v57, v17);
                  _bstr_t::_Free(&v46);
                  _bstr_t::_Free(&v50);
                  _bstr_t::_Free(&v49);
                  _bstr_t::_Free(&v53);
                }
                v2 = v57.m_Data;
              }
            }
            v34 = v54;
            (v54->m_Data->m_RefCount)(v54);
          }
        }
        v34 = v56;
        (v56->m_Data->m_RefCount)(v56);
        v1 = 0;
      }
    }
    v34 = ppv;
    (*(*ppv + 8))(ppv);
    if ( v2 )
    {
      if ( v2->m_wstr )
      {
        v34 = v2->m_wstr;
        if ( SysStringLen(v34) )
        {
          v34 = v2->m_wstr;
          v1 = _wcsdup(v34);
        }
      }
      if ( !InterlockedDecrement(&v2->m_RefCount) )
      {
        if ( v2->m_wstr )
        {
          SysFreeString(v2->m_wstr);
          v2->m_wstr = 0;
        }
        if ( v2->m_str )
        {
          j_j__free(v2->m_str);
          v2->m_str = 0;
        }
        j__free(v2);
      }
    }
  }
  return v1;
}

//----- (01024CC0) --------------------------------------------------------
BOOL __cdecl DrawHungWindow(HWND hWnd)
{
  int nWidth; // esi
  HDC hDCWindow; // eax
  HDC hDCWindow_1; // edi
  HDC hDCWindow_2; // ST24_4
  int hDC; // ebx
  HPEN hPen; // edi
  HGDIOBJ hBrush; // eax
  struct tagRECT rcWindow; // [esp+14h] [ebp-14h]

  nWidth = 3 * GetSystemMetrics(SM_CXBORDER);
  hDCWindow = GetWindowDC(hWnd);
  hDCWindow_1 = hDCWindow;
  hDCWindow_2 = hDCWindow;
  GetWindowRect(hWnd, &rcWindow);
  hDC = SaveDC(hDCWindow_1);
  SetROP2(hDCWindow_1, R2_NOT);
  hPen = CreatePen(PS_INSIDEFRAME, nWidth, 0);
  SelectObject(hDCWindow_2, hPen);
  hBrush = GetStockObject(NULL_BRUSH);
  SelectObject(hDCWindow_2, hBrush);
  Rectangle(hDCWindow_2, 0, 0, rcWindow.right - rcWindow.left, rcWindow.bottom - rcWindow.top);
  RestoreDC(hDCWindow_2, hDC);
  ReleaseDC(hWnd, hDCWindow_2);
  return DeleteObject(hPen);
}

//----- (01024D80) --------------------------------------------------------
bool __usercall IsProcessExplorerRunAtStartup@<al>(int a1@<ebp>, _DWORD *a2@<edi>)
{
  _DWORD *v2; // ecx
  int v3; // edx
  int v4; // edi
  _DWORD *v5; // eax
  OLECHAR *v6; // edx
  int v7; // esi
  OLECHAR *v8; // eax
  BSTR **v9; // eax
  BSTR v10; // edx
  LSTATUS v11; // esi
  int v13; // [esp-310h] [ebp-31Ch]
  int v14; // [esp-30Ch] [ebp-318h]
  int v15; // [esp-308h] [ebp-314h]
  int v16; // [esp-304h] [ebp-310h]
  int v17; // [esp-300h] [ebp-30Ch]
  int v18; // [esp-2FCh] [ebp-308h]
  int v19; // [esp-2F8h] [ebp-304h]
  int v20; // [esp-2F4h] [ebp-300h]
  int v21; // [esp-2F0h] [ebp-2FCh]
  int v22; // [esp-2ECh] [ebp-2F8h]
  int v23; // [esp-2E8h] [ebp-2F4h]
  int v24; // [esp-2E4h] [ebp-2F0h]
  int v25; // [esp-2E0h] [ebp-2ECh]
  int v26; // [esp-2DCh] [ebp-2E8h]
  _DWORD *v27; // [esp-2D8h] [ebp-2E4h]
  BSTR v28; // [esp-2D4h] [ebp-2E0h]
  _DWORD *v29; // [esp-2D0h] [ebp-2DCh]
  int v30; // [esp-2C0h] [ebp-2CCh]
  int v31; // [esp-2B0h] [ebp-2BCh]
  int v32; // [esp-2A0h] [ebp-2ACh]
  int v33; // [esp-290h] [ebp-29Ch]
  int v34; // [esp-280h] [ebp-28Ch]
  int v35; // [esp-270h] [ebp-27Ch]
  int v36; // [esp-260h] [ebp-26Ch]
  int v37; // [esp-244h] [ebp-250h]
  signed int v38; // [esp-240h] [ebp-24Ch]
  _DWORD *v39; // [esp-23Ch] [ebp-248h]
  _DWORD *v40; // [esp-238h] [ebp-244h]
  HKEY v41; // [esp-234h] [ebp-240h]
  int v42; // [esp-230h] [ebp-23Ch]
  _DWORD *v43; // [esp-22Ch] [ebp-238h]
  OLECHAR *v44; // [esp-228h] [ebp-234h]
  unsigned int v45; // [esp-214h] [ebp-220h]
  int v46; // [esp-210h] [ebp-21Ch]
  unsigned int v47; // [esp-4h] [ebp-10h]
  int v48; // [esp+0h] [ebp-Ch]
  int v49; // [esp+4h] [ebp-8h]
  int retaddr; // [esp+Ch] [ebp+0h]

  v48 = a1;
  v49 = retaddr;
  v47 = &v48 ^ __security_cookie;
  v29 = a2;
  if ( gdwVersion < 1 )
  {
    v11 = RegOpenKeyExW(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Run", 0, 1u, &v41);
    if ( !v11 )
    {
      v38 = 520;
      v11 = RegQueryValueExW(v41, L"Process Explorer", 0, &v37, &v46, &v38);
      RegCloseKey(v41);
    }
    return v11 == 0;
  }
  sub_10226B0(&v44);
  v43 = 0;
  if ( CoCreateInstance(&stru_10A78CC, 0, 1u, &riid, &v43) >= 0 )
  {
    VariantInit(&v35);
    _mm_store_si128(&v31, _mm_load_si128(&v35));
    VariantInit(&v34);
    _mm_store_si128(&v32, _mm_load_si128(&v34));
    VariantInit(&v33);
    _mm_store_si128(&v30, _mm_load_si128(&v33));
    VariantInit(&v36);
    v2 = v43;
    v3 = *v43;
    _mm_storeu_si128(&v25, _mm_load_si128(&v31));
    _mm_storeu_si128(&v21, _mm_load_si128(&v32));
    _mm_storeu_si128(&v17, _mm_load_si128(&v30));
    _mm_storeu_si128(&v13, _mm_loadu_si128(&v36));
    v4 = (*(v3 + 40))(v2, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29);
    VariantClear(&v36);
    VariantClear(&v33);
    VariantClear(&v34);
    VariantClear(&v35);
    if ( v4 >= 0 )
    {
      v40 = 0;
      v5 = *_bstr_t::_bstr_t(&v42, L"\\");
      v6 = (v5 ? *v5 : 0);
      v29 = &v40;
      v28 = v6;
      v27 = v43;
      v7 = (*(*v43 + 28))(v43, v6, &v40);
      _bstr_t::_Free(&v42);
      if ( v7 >= 0 )
      {
        v8 = &v44;
        if ( v45 >= 8 )
          v8 = v44;
        v9 = _bstr_t::_bstr_t(&v42, v8);
        if ( *v9 )
          v10 = **v9;
        else
          v10 = 0;
        v29 = &v39;
        v28 = v10;
        v27 = v40;
        v11 = (*(*v40 + 52))(v40, v10, &v39);
        _bstr_t::_Free(&v42);
        if ( !v11 )
        {
          v29 = v39;
          (*(*v39 + 8))(v39);
        }
        v29 = v43;
        (*(*v43 + 8))(v43);
        sub_FD3820(&v44);
        return v11 == 0;
      }
    }
    v29 = v43;
    (*(*v43 + 8))(v43);
  }
  if ( v45 >= 8 )
    j__free(v44);
  return 0;
}
// 1024D80: could not find valid save-restore pair for ebp
// 1024D80: could not find valid save-restore pair for edi
// 10C4E54: using guessed type int gdwVersion;

//----- (01025050) --------------------------------------------------------
bool IsXPDll()
{
  HMODULE v0; // eax
  FARPROC DllGetVersion; // eax
  DLLVERSIONINFO VersionInfo; // [esp+0h] [ebp-18h]

  v0 = LoadLibraryW(L"comctl32.dll");
  DllGetVersion = GetProcAddress(v0, "DllGetVersion");
  if ( !DllGetVersion )
    return 0;
  VersionInfo.cbSize = sizeof(DLLVERSIONINFO);
  VersionInfo.dwMajorVersion = 0;
  *&VersionInfo.dwMinorVersion = 0i64;
  VersionInfo.dwPlatformID = 0;
  return (DllGetVersion)(&VersionInfo) >= 0 && VersionInfo.dwMajorVersion >= 6;// Windows XP
}

//----- (010250E0) --------------------------------------------------------
char __cdecl sub_10250E0(wchar_t *a1)
{
  WCHAR **v1; // eax
  int v2; // esi
  int v3; // eax

  v1 = gpHiddenProcesses;
  if ( !*gpHiddenProcesses )
    return 0;
  v2 = 0;
  while ( 1 )
  {
    v3 = _wcsicmp(v1[v2], a1);
    ++v2;
    if ( !v3 )
      break;
    v1 = gpHiddenProcesses;
    if ( !gpHiddenProcesses[v2] )
      return 0;
  }
  return 1;
}

//----- (01025120) --------------------------------------------------------
char IsPAEEnabled()
{
  HMODULE v0; // eax
  int (__stdcall *IsProcessorFeaturePresent)(); // eax
  char result; // al

  v0 = GetModuleHandleW(L"Kernel32.dll");
  IsProcessorFeaturePresent = GetProcAddress(v0, "IsProcessorFeaturePresent");
  if ( IsProcessorFeaturePresent )
    result = IsProcessorFeaturePresent();
  else
    result = 0;
  return result;
}

//----- (01025150) --------------------------------------------------------
char CanReplaceTaskManager()
{
  wchar_t *v0; // esi
  wchar_t *v1; // eax
  int v2; // eax
  DWORD cbData; // [esp+4h] [ebp-41Ch]
  HKEY phkResult; // [esp+8h] [ebp-418h]
  wchar_t Data[260]; // [esp+Ch] [ebp-414h]
  wchar_t Dst; // [esp+214h] [ebp-20Ch]
  WCHAR Filename; // [esp+216h] [ebp-20Ah]

  if ( !RegOpenKeyW(
          HKEY_LOCAL_MACHINE,
          L"Software\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options\\taskmgr.exe",
          &phkResult) )
  {
    cbData = 520;
    if ( !RegQueryValueExW(phkResult, L"Debugger", 0, 0, Data, &cbData) )
    {
      _wcsupr_s(Data, 0x104u);
      GetModuleFileNameW(0, &Filename, 0x102u);
      Dst = 34;
      wcscat_s(&Dst, 0x104u, L"\"");
      _wcsupr_s(&Dst, 0x104u);
      v0 = wcsrchr(Data, 0x5Cu);
      v1 = wcsrchr(&Dst, 0x5Cu);
      if ( v1 )
      {
        if ( v0 )
        {
          v2 = wcscmp(v0, v1);
          if ( v2 )
            v2 = -(v2 < 0) | 1;
          if ( !v2 )
          {
            RegCloseKey(phkResult);
            return 1;
          }
        }
      }
    }
    RegCloseKey(phkResult);
  }
  return 0;
}

//----- (010252B0) --------------------------------------------------------
int __usercall IsWinServer@<eax>(int a1@<ebx>, int a2@<esi>)
{
  DWORD dwVersion; // eax
  HMODULE v4; // eax
  ULONGLONG *VerSetConditionMask; // eax
  HMODULE v6; // eax
  BOOL VerifyVersionInfoA; // esi
  _OSVERSIONINFOEXA VerInfo; // [esp+4h] [ebp-A0h]

  dwVersion = GetVersion();
  if ( (dwVersion & 0x80000000) != 0 )
    return 0;
  if ( dwVersion <= 4u )
    return IsServer(L"Terminal Server");
  if ( dwVersion >= 5u && dwVersion >> 16 > 0x893 )
    return 1;
  v4 = GetModuleHandleW(L"ntdll.dll");
  if ( !v4 )
    return 0;
  VerSetConditionMask = GetProcAddress(v4, "VerSetConditionMask");
  if ( !VerSetConditionMask )
    return 0;
  // NTSYSAPI ULONGLONG VerSetConditionMask(
  //   ULONGLONG ConditionMask,
  //   DWORD     TypeMask,
  //   BYTE      Condition
  // );
  (VerSetConditionMask)(0, 0, VER_SUITENAME, VER_AND, a1, a2);
  v6 = GetModuleHandleW(L"KERNEL32.DLL");
  if ( !v6 )
    return 0;
  VerifyVersionInfoA = GetProcAddress(v6, "VerifyVersionInfoA");
  if ( !VerifyVersionInfoA )
    return 0;
  memset(&VerInfo, 0, sizeof(_OSVERSIONINFOEXA));
  VerInfo.dwOSVersionInfoSize = sizeof(_OSVERSIONINFOEXA);
  VerInfo.wReserved[0] = VER_SERVICEPACKMINOR;
  // BOOL VerifyVersionInfoA(
  //   LPOSVERSIONINFOEXA lpVersionInformation,
  //   DWORD              dwTypeMask,
  //   DWORDLONG          dwlConditionMask
  // );
  return (VerifyVersionInfoA)(&VerInfo, VER_SUITENAME);
}
// 10252B0: could not find valid save-restore pair for esi

//----- (010253F0) --------------------------------------------------------
BOOL __cdecl CMainWnd::Hide(HWND hWnd)
{
  BOOL result; // eax

  result = ShowWindow(hWnd, 0);
  gbMainWndMinimized = 1;
  return result;
}
// 10CA389: using guessed type char gbMainWndMinimized;

//----- (01025420) --------------------------------------------------------
char *__cdecl Fake_GetLogicalProcessorInformation(PDWORD pdwCount)
{
  PDWORD v1; // esi
  DWORD_PTR (__stdcall *SetThreadAffinityMask)(HANDLE, DWORD_PTR); // ebx
  DWORD_PTR dwMask; // edi
  HANDLE v4; // eax
  int meax; // eax
  char v15; // cl
  unsigned int v16; // esi
  unsigned int i; // eax
  DWORD v18; // eax
  int v19; // edx
  DWORD v20; // ecx
  int v21; // ebx
  bool v22; // sf
  unsigned __int8 v23; // of
  HANDLE v24; // eax
  ULONG_PTR v25; // ST08_4
  HANDLE v26; // eax
  DWORD v27; // esi
  char *v28; // eax
  DWORD v29; // edx
  char *v30; // edi
  int v31; // ecx
  int v32; // eax
  int dwIndex; // [esp+20h] [ebp-118h]
  ULONG_PTR ProcessAffinityMask; // [esp+24h] [ebp-114h]
  int dwMaskBuf[64]; // [esp+28h] [ebp-110h]
  int mebx; // [esp+128h] [ebp-10h]
  int medx; // [esp+12Ch] [ebp-Ch]
  int mecx; // [esp+130h] [ebp-8h]

  // https://blog.csdn.net/linyanhou/article/details/14109095
  v1 = pdwCount;
  *pdwCount = 0;
  dwMaskBuf[0] = 0;
  memset(&dwMaskBuf[1], 0, 0xFCu);
  SetThreadAffinityMask = ::SetThreadAffinityMask;
  dwIndex = 0;
  dwMask = 1;
  do
  {
    v4 = GetCurrentThread();
    if ( !SetThreadAffinityMask(v4, dwMask) )
      break;
    Sleep(0);
    meax = 0;
    __asm { cpuid }
    mebx = _EBX;
    medx = _EDX;
    mecx = _ECX;
    _EAX = 1;
    __asm { cpuid }
    if ( ((_EAX & 0xF00) == 0xF00 || _EAX & 0xF00000)
      && mebx == 'uneG'
      && medx == 'Ieni'
      && mecx == 'letn'
      && (_EDX >> 28) & 1 )
    {
      v15 = 0;
      v16 = (_EBX >> 16) & 0xFF;
      for ( i = 1; i < v16; ++v15 )
        i *= 2;
      v1 = pdwCount;
      v18 = 0;
      v19 = _EBX >> 24 >> v15;
      v20 = *pdwCount;
      if ( *pdwCount )
      {
        do
        {
          if ( v19 == dwMaskBuf[2 * v18] )
            break;
          ++v18;
        }
        while ( v18 < v20 );
      }
      if ( v18 >= v20 )
        *pdwCount = v20 + 1;
      dwMaskBuf[2 * v18 + 1] |= dwMask;
      dwMaskBuf[2 * v18] = v19;
    }
    v21 = dwIndex + 1;
    dwMask = __ROL4__(dwMask, 1);
    dwIndex = v21;
    v23 = __OFSUB__(v21, 32);
    v22 = v21 - 32 < 0;
    SetThreadAffinityMask = ::SetThreadAffinityMask;
  }
  while ( v22 ^ v23 );
  ProcessAffinityMask = -1;
  v24 = GetCurrentProcess();
  GetProcessAffinityMask(v24, &ProcessAffinityMask, &ProcessAffinityMask);
  v25 = ProcessAffinityMask;
  v26 = GetCurrentThread();
  SetThreadAffinityMask(v26, v25);
  v27 = *v1;
  if ( !v27 )
    return 0;
  v28 = malloc(24 * v27);
  v29 = 0;
  v30 = v28;
  if ( v27 )
  {
    v31 = (v28 + 8);
    do
    {
      v32 = dwMaskBuf[2 * v29 + 1];
      v31 += 24;
      ++v29;
      *(v31 - 28) = 0;
      *(v31 - 24) = 1;
      *(v31 - 32) = v32;
    }
    while ( v29 < v27 );
  }
  return v30;
}

//----- (01025670) --------------------------------------------------------
BOOL __cdecl PE_SetWindowPlacement(HWND hWnd, POINT pt)
{
  LONG left; // esi
  int top; // edi
  int v4; // eax
  LONG bottom; // ecx
  int v6; // eax
  int v7; // eax
  WINDOWPLACEMENT wp; // [esp+10h] [ebp-40h]
  struct tagRECT rcClient; // [esp+3Ch] [ebp-14h]

  left = pt.x;
  top = pt.y;
  if ( pt.x < 0 )
    left = 10;
  if ( pt.y < 0 )
    top = 10;
  GetClientRect(hWnd, &rcClient);
  if ( GetSystemMetrics(SM_CXVIRTUALSCREEN) )
  {
    if ( GetSystemMetrics(SM_CXVIRTUALSCREEN) - rcClient.right < left )
      left = GetSystemMetrics(SM_CXVIRTUALSCREEN) - rcClient.right;
    v4 = GetSystemMetrics(SM_CYVIRTUALSCREEN);
    bottom = rcClient.bottom;
    if ( v4 - rcClient.bottom < top )
    {
      v6 = GetSystemMetrics(SM_CYVIRTUALSCREEN);
LABEL_14:
      bottom = rcClient.bottom;
      top = v6 - rcClient.bottom;
      goto LABEL_15;
    }
  }
  else
  {
    if ( GetSystemMetrics(SM_CXSCREEN) - rcClient.right < left )
      left = GetSystemMetrics(SM_CXSCREEN) - rcClient.right;
    v7 = GetSystemMetrics(SM_CYSCREEN);
    bottom = rcClient.bottom;
    if ( v7 - rcClient.bottom < top )
    {
      v6 = GetSystemMetrics(SM_CYSCREEN);
      goto LABEL_14;
    }
  }
LABEL_15:
  wp.flags = WPF_SETMINPOSITION;
  wp.rcNormalPosition.right = left + rcClient.right;
  wp.rcNormalPosition.bottom = bottom + top;
  wp.rcNormalPosition.left = left;
  wp.rcNormalPosition.top = top;
  return SetWindowPlacement(hWnd, &wp);
}

//----- (01025750) --------------------------------------------------------
char __cdecl LaunchWebBrowser(HWND hWnd, bool flags, LPCWSTR lpszURL)
{
  LPCWSTR v3; // edi
  LSTATUS v4; // esi
  wchar_t *pszParameters; // esi
  wchar_t *v6; // eax
  const wchar_t *v7; // ebx
  wchar_t *v8; // eax
  int v9; // esi
  WCHAR v10; // ax
  char result; // al
  OLECHAR *pszFile; // [esp+Ch] [ebp-224h]
  wchar_t *Dst; // [esp+10h] [ebp-220h]
  HWND hWnda; // [esp+14h] [ebp-21Ch]
  unsigned int SizeInWords; // [esp+18h] [ebp-218h]
  DWORD cbData; // [esp+1Ch] [ebp-214h]
  HKEY phkResult; // [esp+20h] [ebp-210h]
  BYTE Data[2]; // [esp+24h] [ebp-20Ch]
  wchar_t v19; // [esp+26h] [ebp-20Ah]

  v3 = lpszURL;
  v4 = RegOpenKeyExW(
         HKEY_CURRENT_USER,
         L"Software\\Microsoft\\Windows\\Shell\\Associations\\UrlAssociations\\http\\UserChoice",
         0,
         0x20019u,
         &phkResult);
  if ( !v4 )
  {
    cbData = 260;
    v4 = RegQueryValueExW(phkResult, L"ProgId", 0, 0, Data, &cbData);
    RegCloseKey(phkResult);
    if ( !v4 )
    {
      wcscat_s(Data, 0x104u, L"\\shell\\open\\command");
      if ( RegOpenKeyExW(HKEY_CLASSES_ROOT, Data, 0, 0x20019u, &phkResult) )
        goto LABEL_22;
      cbData = 260;
      v4 = RegQueryValueExW(phkResult, 0, 0, 0, Data, &cbData);
      RegCloseKey(phkResult);
      if ( !v4 )
        goto LABEL_22;
    }
  }
  if ( !RegOpenKeyExW(HKEY_CLASSES_ROOT, L"http\\shell\\open\\command", 0, 0x20019u, &phkResult) )
  {
    cbData = 260;
    v4 = RegQueryValueExW(phkResult, 0, 0, 0, Data, &cbData);
    RegCloseKey(phkResult);
  }
  if ( v4 )
  {
    MessageBoxW(hWnd, L"No web browser is configured.", L"Process Explorer Error", 0x10u);
    result = 0;
  }
  else
  {
LABEL_22:
    SizeInWords = wcslen(Data) + wcslen(lpszURL) + 6;
    pszParameters = malloc(2 * SizeInWords);
    Dst = pszParameters;
    pszFile = Data;
    if ( *Data == 34 )
    {
      strcpy(Data, "\"");
      pszFile = &v19;
      v6 = wcschr(&v19, '"');
    }
    else
    {
      v6 = wcschr(Data, ' ');
    }
    v7 = v6;
    if ( v6 )
    {
      *v6 = 0;
      v7 = v6 + 1;
    }
    if ( flags )
    {
      v8 = wcsstr(Data, L"\"%1\"");
      hWnda = v8;
      if ( v8 )
      {
        v9 = v8 - v7;
        wcsncpy_s(Dst, SizeInWords, v7, v9 + 1);
        wcscpy_s(&Dst[v9 + 1], SizeInWords - v9 - 1, L"? ");
        pszParameters = Dst;
        wcscat_s(Dst, SizeInWords, lpszURL);
        wcscat_s(Dst, SizeInWords, hWnda + 3);
      }
      else
      {
        swprintf_s(pszParameters, SizeInWords, L"\"? %s\"", lpszURL);
      }
    }
    else
    {
      do
      {
        v10 = *v3;
        ++v3;
        *(v3 + pszParameters - lpszURL - 2) = v10;
      }
      while ( v10 );
    }
    PE_ShellExecute(pszFile, pszParameters, 0);
    free(pszParameters);
    result = 1;
  }
  return result;
}

//----- (01025A60) --------------------------------------------------------
int __cdecl sub_1025A60(const void *a1, const void *a2)
{
  return _stricmp(*a1, *a2);
}

//----- (01025A80) --------------------------------------------------------
LSTATUS LoadHiddenProcessesFromRegistry()
{
  WCHAR **v0; // eax
  LSTATUS result; // eax
  BYTE *v2; // ebx
  const wchar_t *v3; // esi
  int v4; // edi
  WCHAR *v5; // eax
  WCHAR v6; // cx
  int v7; // [esp+0h] [ebp-10h]
  DWORD Type; // [esp+4h] [ebp-Ch]
  HKEY hKey; // [esp+8h] [ebp-8h]
  DWORD cbData; // [esp+Ch] [ebp-4h]

  cbData = 0;
  v0 = malloc(4u);
  gpHiddenProcesses = v0;
  *v0 = 0;
  result = RegOpenKeyExW(HKEY_CURRENT_USER, L"Software\\Sysinternals\\Process Explorer", 0, KEY_READ, &hKey);
  if ( !result )
  {
    if ( !RegQueryValueExW(hKey, L"HiddenProcs", 0, &Type, 0, &cbData) )
    {
      v2 = malloc(cbData);
      RegQueryValueExW(hKey, L"HiddenProcs", 0, &Type, v2, &cbData);
      v3 = v2;
      if ( v2 < &v2[2 * cbData] )
      {
        v4 = 0;
        do
        {
          if ( !*v3 )
            break;
          gpHiddenProcesses = realloc(gpHiddenProcesses, v4 * 4 + 8);
          gpHiddenProcesses[v4] = _wcsdup(v3);
          v5 = gpHiddenProcesses[v4];
          v7 = (v5 + 1);
          do
          {
            v6 = *v5;
            ++v5;
          }
          while ( v6 );
          gpHiddenProcesses[v4 + 1] = 0;
          ++v4;
          v3 += ((v5 - v7) >> 1) + 1;
        }
        while ( v3 < &v2[2 * cbData] );
      }
    }
    result = RegCloseKey(hKey);
  }
  return result;
}

//----- (01025BA0) --------------------------------------------------------
LSTATUS LoadProcessCommentsFromRegistry()
{
  DWORD v0; // esi
  LSTATUS result; // eax
  DWORD Type; // [esp+4h] [ebp-814h]
  DWORD cbData; // [esp+8h] [ebp-810h]
  HKEY phkResult; // [esp+Ch] [ebp-80Ch]
  DWORD cchValueName; // [esp+10h] [ebp-808h]
  WCHAR ValueName; // [esp+14h] [ebp-804h]

  v0 = 0;
  result = RegOpenKeyExW(
             HKEY_CURRENT_USER,
             L"Software\\Sysinternals\\Process Explorer\\ProcessComments",
             0,
             0x20019u,
             &phkResult);
  if ( !result )
  {
    cchValueName = 1024;
    if ( !RegEnumValueW(phkResult, 0, &ValueName, &cchValueName, 0, &Type, 0, &cbData) )
    {
      do
      {
        gpProcessComments = realloc(gpProcessComments, 8 * v0 + 16);
        gpProcessComments[v0].pszName = _wcsdup(&ValueName);
        gpProcessComments[v0].pszComment = malloc(cbData);
        cchValueName += 2;
        RegEnumValueW(phkResult, v0, &ValueName, &cchValueName, 0, &Type, gpProcessComments[v0].pszComment, &cbData);
        gpProcessComments[v0 + 1].pszName = 0;
        cchValueName = 1024;
        ++v0;
      }
      while ( !RegEnumValueW(phkResult, v0, &ValueName, &cchValueName, 0, &Type, 0, &cbData) );
    }
    result = RegCloseKey(phkResult);
  }
  return result;
}

//----- (01025D10) --------------------------------------------------------
char __cdecl ReplaceTaskManager(HWND a1, char a2)
{
  DWORD v2; // eax
  DWORD v3; // esi
  char result; // al
  HKEY phkResult; // [esp+0h] [ebp-418h]
  BYTE Data[2]; // [esp+4h] [ebp-414h]
  char v7; // [esp+6h] [ebp-412h]

  *Data = 0;
  memset(&v7, 0, 0x40Eu);
  sub_1022850(Data, 0x208u);
  v2 = RegCreateKeyW(
         HKEY_LOCAL_MACHINE,
         L"Software\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options\\taskmgr.exe",
         &phkResult);
  if ( v2 )
  {
    if ( a2 )
    {
      SetLastError(v2);
      ReportMsg(L"Error replacing Task Manager", ghMainWnd);
    }
    result = 0;
  }
  else
  {
    v3 = RegSetValueExW(phkResult, L"Debugger", 0, 1u, Data, 2 * wcslen(Data) + 2);
    RegCloseKey(phkResult);
    if ( v3 )
    {
      if ( a2 )
      {
        SetLastError(v3);
        ReportMsg(L"Error replacing Task Manager", ghMainWnd);
      }
      result = 0;
    }
    else
    {
      result = 1;
    }
  }
  return result;
}
// 109EE00: using guessed type wchar_t aErrorReplacing[29];

//----- (01025E40) --------------------------------------------------------
char __thiscall sub_1025E40(HKEY this)
{
  DWORD v1; // eax
  HKEY phkResult; // [esp+0h] [ebp-4h]

  phkResult = this;
  if ( !CanReplaceTaskManager() )
    return 1;
  v1 = RegOpenKeyW(
         HKEY_LOCAL_MACHINE,
         L"Software\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options\\taskmgr.exe",
         &phkResult);
  if ( !v1 )
  {
    RegDeleteValueW(phkResult, L"Debugger");
    RegCloseKey(phkResult);
    return 1;
  }
  SetLastError(v1);
  ReportMsg(L"Error restoring Task Manager", ghMainWnd);
  return 0;
}
// 109EDC4: using guessed type wchar_t aErrorRestoring[29];

//----- (01025EB0) --------------------------------------------------------
DWORD __cdecl LaunchProcExplorer64(int a1, WORD a2)
{
  DWORD result; // eax
  unsigned __int16 v3; // si
  wchar_t *v4; // eax
  WCHAR *v5; // eax
  struct _STARTUPINFOW StartupInfo; // [esp+0h] [ebp-46Ch]
  struct _PROCESS_INFORMATION ProcessInformation; // [esp+44h] [ebp-428h]
  HKEY hSubKey; // [esp+54h] [ebp-418h]
  WCHAR szPathName; // [esp+58h] [ebp-414h]
  WCHAR szFileName; // [esp+260h] [ebp-20Ch]

  StartupInfo.cb = 68;
  StartupInfo.lpReserved = 0;
  memset(&StartupInfo.lpDesktop, 0, 0x3Cu);
  _mm_storeu_si128(&ProcessInformation, 0i64);
  result = GetModuleFileNameW(0, &szFileName, 0x103u);
  if ( result )
  {
    if ( !RegCreateKeyW(HKEY_CURRENT_USER, L"Software\\Sysinternals\\Process Explorer", &hSubKey) )
    {
      RegSetValueExW(hSubKey, L"OriginalPath", 0, 1u, &szFileName, 2 * wcslen(&szFileName));
      RegCloseKey(hSubKey);
    }
    *wcsrchr(&szFileName, 0x2Eu) = 0;
    wcscat_s(&szFileName, 0x104u, L"64.exe");
    if ( gSystemInfo.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_IA64 )
    {
      v3 = IDS_DRIVER_64;
    }
    else
    {
      if ( gSystemInfo.wProcessorArchitecture != PROCESSOR_ARCHITECTURE_AMD64 )
      {
        swprintf(&szFileName, L"Unsupported processor type: %d\n", gSystemInfo.wProcessorArchitecture);
        MessageBoxW(0, &szFileName, L"Process Explorer", 0x10u);
        return 0;
      }
      v3 = IDS_DRIVER_32;
    }
    ExpandEnvironmentStringsW(L"%TEMP%", &szPathName, 0x104u);
    v4 = wcsrchr(&szFileName, '\\');
    wcscat_s(&szPathName, 0x104u, v4);
    wcscpy_s(&szFileName, 0x104u, &szPathName);
    if ( !CDriver::SaveDriverFromResource(v3, &szFileName) && GetFileAttributesW(&szFileName) == -1 )
      return 0;
    if ( !RegOpenKeyW(HKEY_CURRENT_USER, L"Software\\Sysinternals\\Process Explorer", &hSubKey) )
    {
      RegSetValueExW(hSubKey, L"Path", 0, 1u, &szFileName, 2 * wcslen(&szFileName));
      RegCloseKey(hSubKey);
    }
    StartupInfo.wShowWindow = a2;
    StartupInfo.dwFlags = 1;
    v5 = GetCommandLineW();
    if ( !CreateProcessW(&szFileName, v5, 0, 0, 0, 0, 0, 0, &StartupInfo, &ProcessInformation) )
      return 0;
    if ( a1 )
    {
      WaitForSingleObject(ProcessInformation.hProcess, 0xFFFFFFFF);
      DeleteFileW(&szFileName);
    }
    CloseHandle(ProcessInformation.hProcess);
    CloseHandle(ProcessInformation.hThread);
    result = 1;
  }
  return result;
}

//----- (01026180) --------------------------------------------------------
DWORD __cdecl sub_1026180(const WCHAR *a1, int a2, char a3)
{
  SHELLEXECUTEINFOW pExecInfo; // [esp+4h] [ebp-450h]
  wchar_t Dst; // [esp+40h] [ebp-414h]

  sub_1022850(&Dst, 0x208u);
  memset(&pExecInfo, 0, 0x3Cu);
  pExecInfo.nShow = a2;
  pExecInfo.lpFile = &Dst;
  pExecInfo.cbSize = 60;
  pExecInfo.fMask = 64;
  pExecInfo.hwnd = 0;
  pExecInfo.lpVerb = L"Runas";
  pExecInfo.lpParameters = a1;
  if ( !ShellExecuteExW(&pExecInfo) )
    return GetLastError();
  if ( a3 )
    WaitForSingleObject(pExecInfo.hProcess, 0xFFFFFFFF);
  CloseHandle(pExecInfo.hProcess);
  return 0;
}

//----- (01026260) --------------------------------------------------------
int Fake_IsWow64Process()
{
  HMODULE v0; // eax
  FARPROC v1; // esi
  HANDLE v2; // eax
  int v4; // [esp+4h] [ebp-4h]

  v4 = 0;
  v0 = GetModuleHandleW(L"kernel32.dll");
  v1 = GetProcAddress(v0, "IsWow64Process");
  if ( v1 )
  {
    v2 = GetCurrentProcess();
    (v1)(v2, &v4);
  }
  return v4;
}

//----- (010262A0) --------------------------------------------------------
LSTATUS __cdecl sub_10262A0(int a1, wchar_t *a2)
{
  int v2; // eax
  const wchar_t *v3; // ebx
  int v4; // edi
  tagTREEVIEWLISTITEMPARAM *v5; // esi
  const wchar_t *v6; // eax
  const wchar_t *v7; // eax
  LRESULT v8; // eax
  tagProcessComment *v9; // ecx
  int v10; // eax
  int v11; // esi
  LSTATUS result; // eax
  tagProcessComment *v13; // edx
  const BYTE *v14; // esi
  LPARAM lParam; // [esp+Ch] [ebp-1Ch]
  tagTREEVIEWLISTITEMPARAM *v16; // [esp+14h] [ebp-14h]
  HKEY phkResult; // [esp+24h] [ebp-4h]

  v2 = a1;
  v3 = *(a1 + 792);
  v4 = 0;
  if ( !v3 )
    v3 = *(a1 + 60);
  v5 = gpTreeViewListItemParam;
  if ( gpTreeViewListItemParam )
  {
    do
    {
      if ( *(v2 + 792) && (v6 = v5->szProcessName) != 0 && !_wcsicmp(v6, v3)
        || (v7 = v5->szProcessName2) != 0 && !_wcsicmp(v7, v3) )
      {
        free(v5->pszComments);
        v5->pszComments = (*a2 ? _wcsdup(a2) : 0);
        lParam = 1;
        v16 = v5;
        v8 = SendMessageW(ghWndTreeListView, 0x1053u, 0xFFFFFFFF, &lParam);
        if ( v8 != -1 )
          PostMessageW(ghMainWnd, 0x7EBu, v8, -1);
      }
      v5 = v5->m_Prev;
      v2 = a1;
    }
    while ( v5 );
    v4 = 0;
  }
  v9 = gpProcessComments;
  if ( !gpProcessComments )
    goto LABEL_33;
  if ( gpProcessComments->pszName )
  {
    v10 = 0;
    while ( _wcsicmp(v9[v10].pszName, v3) )
    {
      v9 = gpProcessComments;
      v10 = ++v4;
      if ( !gpProcessComments[v4].pszName )
        goto LABEL_23;
    }
    free(gpProcessComments[v4].pszComment);
    gpProcessComments[v4].pszComment = _wcsdup(a2);
    v9 = gpProcessComments;
  }
LABEL_23:
  if ( !v9 )
    goto LABEL_33;
  v11 = v4;
  if ( !v9[v4].pszName )
  {
LABEL_33:
    gpProcessComments = realloc(v9, 8 * v4 + 16);
    v11 = v4;
    gpProcessComments[v11].pszName = _wcsdup(v3);
    gpProcessComments[v11].pszComment = _wcsdup(a2);
    gpProcessComments[v11 + 1].pszName = 0;
  }
  result = RegCreateKeyW(HKEY_CURRENT_USER, L"Software\\Sysinternals\\Process Explorer\\ProcessComments", &phkResult);
  if ( !result )
  {
    v13 = &gpProcessComments[v11];
    v14 = gpProcessComments[v11].pszComment;
    if ( *v14 )
      RegSetValueExW(phkResult, v13->pszName, 0, 1u, v14, 2 * wcslen(v14) + 2);
    else
      RegDeleteValueW(phkResult, v13->pszName);
    result = RegCloseKey(phkResult);
  }
  return result;
}

//----- (010264C0) --------------------------------------------------------
char __cdecl sub_10264C0(HWND hWnd, LPCWSTR lpFileName)
{
  HANDLE v2; // esi
  char result; // al
  HCURSOR v4; // eax
  LPARAM lParam; // [esp+8h] [ebp-10048h]
  int v6; // [esp+Ch] [ebp-10044h]
  const wchar_t *v7; // [esp+1Ch] [ebp-10034h]
  int v8; // [esp+28h] [ebp-10028h]
  HCURSOR hCursor; // [esp+3Ch] [ebp-10014h]
  DWORD NumberOfBytesRead; // [esp+40h] [ebp-10010h]
  char Buffer; // [esp+44h] [ebp-1000Ch]

  v2 = CreateFileW(lpFileName, 0x80000000, 3u, 0, 3u, 0, 0);
  if ( v2 == -1 )
  {
    lParam = 5;
    v6 = 0x7FFFFFFF;
    v7 = L"<Error opening file>";
    v8 = 1;
    SendMessageW(hWnd, 0x104Du, 0, &lParam);
    result = 0;
  }
  else
  {
    v4 = ghWaitCursor;
    if ( !ghWaitCursor )
    {
      v4 = LoadCursorW(ghWaitCursor, 0x7F02);
      ghWaitCursor = v4;
    }
    hCursor = SetCursor(v4);
    while ( ReadFile(v2, &Buffer, 0x10008u, &NumberOfBytesRead, 0) )
    {
      if ( !NumberOfBytesRead )
        break;
      WriteStringToList(hWnd, 3u, &Buffer, NumberOfBytesRead);
      if ( NumberOfBytesRead == 65544 )
        SetFilePointer(v2, -2, 0, 1u);
    }
    CloseHandle(v2);
    SetCursor(hCursor);
    result = 1;
  }
  return result;
}
// 109EBF4: using guessed type wchar_t aErrorOpeningFi[21];

//----- (01026620) --------------------------------------------------------
HCURSOR __cdecl LoadStringToList(HWND hWnd, HANDLE ProcessHandle, LPCVOID lpBaseAddress, DWORD dwSize)
{
  HCURSOR v4; // eax
  char *pAddress; // edi
  DWORD v6; // esi
  SIZE_T dwLength; // ecx
  HCURSOR hCursor; // [esp+Ch] [ebp-10010h]
  SIZE_T dwRet; // [esp+14h] [ebp-10008h]
  char Buffer[65536]; // [esp+18h] [ebp-10004h]

  v4 = ghWaitCursor;
  pAddress = lpBaseAddress;
  if ( !ghWaitCursor )
  {
    v4 = LoadCursorW(ghWaitCursor, IDC_WAIT);
    ghWaitCursor = v4;
  }
  v6 = dwSize;
  hCursor = SetCursor(v4);
  do
  {
    dwLength = v6;
    if ( v6 > 0x10000 )
      dwLength = 0x10000;
    dwRet = dwLength;
    if ( !ReadProcessMemory(ProcessHandle, pAddress, Buffer, dwLength, &dwRet) )
      break;
    WriteStringToList(hWnd, 3u, Buffer, dwRet);
    v6 -= dwRet;
    pAddress += dwRet;
    if ( dwRet == 0x10000 )
    {
      v6 += 2;
      pAddress -= 2;
    }
  }
  while ( v6 );
  return SetCursor(hCursor);
}

//----- (01026710) --------------------------------------------------------
int __cdecl PE_FillControl(int a1, HDC hdc)
{
  if ( !ghBlackBrush )
    ghBlackBrush = CreateSolidBrush(0xFFFFFFu);
  SetBkColor(hdc, 0xFFFFFFu);
  return ghBlackBrush;
}
// 10C9E8C: using guessed type int ghBlackBrush;

//----- (01026750) --------------------------------------------------------
int __cdecl QueryTagInformationEx(PVOID *ppv, PDWORD pdwValue2, PDWORD pdwValue3, PDWORD pdwValue4)
{
  int result; // eax
  DWORD *v5; // edx
  TAG_INFO_NAME_TAG_MAPPING *QueryIn; // [esp+Ch] [ebp-8h]
  DWORD *pValue; // [esp+10h] [ebp-4h]

  if ( *ppv )
  {
    LocalFree(*ppv);
    *pdwValue4 = 0;
    *pdwValue3 = 0;
  }
  QueryIn = pdwValue2;
  pValue = 0;
  result = I_QueryTagInformation(0, ServiceNameTagMappingInformation, &QueryIn);
  if ( !result )
  {
    v5 = pValue;
    *pdwValue3 = *pValue;
    *pdwValue4 = v5[1];
    *ppv = v5;
  }
  return result;
}

//----- (010267B0) --------------------------------------------------------
BOOL __cdecl TrayIcon_Add(HWND hWnd, UINT nID, CGraphData *pGraphData, LPCWSTR lpszTipText)
{
  HICON v4; // edi
  BOOL v5; // esi
  struct _NOTIFYICONDATAW Data; // [esp+14h] [ebp-3CCh]
  RECT rc; // [esp+3CCh] [ebp-14h]

  _mm_storeu_si128(&rc, _mm_load_si128(&stru_109F270));
  memset(&Data, 0, 0x3B8u);
  Data.uID = nID;
  Data.cbSize = 952;
  Data.hWnd = hWnd;
  Data.uFlags = 7;
  Data.uCallbackMessage = WM_NOTIFY_TRAYICON;
  v4 = GraphData_DrawChart(pGraphData, 0, &rc, gConfig.ColorGraphBk, 0, 0.0);
  Data.hIcon = v4;
  if ( lpszTipText )
    wcsncpy_s(Data.szTip, 0x80u, lpszTipText, 0xFFFFFFFF);
  else
    Data.szTip[0] = 0;
  v5 = Shell_NotifyIconW(NIM_ADD, &Data);
  DestroyIcon(v4);
  return v5;
}
// 109F270: using guessed type RECT stru_109F270;

//----- (010268A0) --------------------------------------------------------
BOOL __cdecl TrayIcon_Delete(HWND hWnd, UINT nID)
{
  struct _NOTIFYICONDATAW Data; // [esp+4h] [ebp-3BCh]

  memset(&Data, 0, 952u);
  Data.uID = nID;
  Data.cbSize = 952;
  Data.hWnd = hWnd;
  return Shell_NotifyIconW(NIM_DELETE, &Data);
}

//----- (01026910) --------------------------------------------------------
BOOL __cdecl sub_1026910(int a1, int a2, int a3, wchar_t *Src)
{
  struct _NOTIFYICONDATAW Data; // [esp+Ch] [ebp-3BCh]

  wcscpy_s(&Dst, 0x100u, Src);
  memset(&Data, 0, 0x3B8u);
  Data.cbSize = 952;
  Data.hWnd = a1;
  Data.uID = a2;
  Data.uFlags = 6;
  Data.hIcon = a3;
  if ( Src )
    wcsncpy_s(Data.szTip, 0x80u, Src, 0xFFFFFFFF);
  else
    Data.szTip[0] = 0;
  return Shell_NotifyIconW(1u, &Data);
}

//----- (010269D0) --------------------------------------------------------
BOOL __cdecl RefreshVirusTotalMenuItem(tagTREEVIEWLISTITEMPARAM *pItemParam)
{
  char v1; // bl
  ListItemData1 *v2; // eax
  bool v3; // zf
  const WCHAR *v4; // eax
  const WCHAR *v5; // ST10_4
  HMENU v6; // eax
  WCHAR *v7; // eax
  HMENU v8; // eax

  v1 = 0;
  v2 = pItemParam->m_ItemDataForVirusTotal;
  if ( !v2 || (v3 = v2->field_4 == 6, v4 = L"&Submit to VirusTotal", !v3) )
    v4 = L"&Check VirusTotal";
  v5 = v4;
  v6 = GetMenu(ghMainWnd);
  ModifyMenuW(v6, IDM_PROCESS_CHECK_VIRUSTOTALDOTCOM, MF_BYCOMMAND, IDM_PROCESS_CHECK_VIRUSTOTALDOTCOM, v5);
  v7 = pItemParam->szProcessName;
  if ( v7 )
  {
    if ( *v7 != '[' )
    {
      v1 = 0;
      if ( sub_1061C10(pItemParam->m_ItemDataForVirusTotal) )
        v1 = 1;
    }
  }
  v8 = GetMenu(ghMainWnd);
  return EnableMenuItem(v8, IDM_PROCESS_CHECK_VIRUSTOTALDOTCOM, v1 == 0);
}
// 109E374: using guessed type wchar_t aCheckVirustota[18];

//----- (01026A70) --------------------------------------------------------
BOOL __cdecl RefreshMenuWithTreeViewItemStatus(tagTREEVIEWLISTITEMPARAM *pItem)
{
  HMENU hMainMenu; // edi
  HWND hWnd; // eax
  HMENU v3; // eax
  BOOL result; // eax
  HMENU v5; // eax
  BOOL v6; // eax
  BOOL v7; // eax
  BOOL v8; // eax

  hMainMenu = GetMenu(ghMainWnd);
  hWnd = QueryTopMostWindowByProcessID(pItem->dwProcessId);
  pItem->hMainWndBackup = hWnd;
  if ( hWnd )
  {
    v5 = GetSubMenu(hMainMenu, 3);
    EnableMenuItem(v5, 0, MF_BYPOSITION);
    EnableMenuItem(hMainMenu, IDM_PROCESS_WINDOW_BRING_TO_FRONT, 0);
    EnableMenuItem(hMainMenu, IDM_PROCESS_WINDOW_CLOSE, 0);
    v6 = !IsIconic(pItem->hMainWndBackup) && !IsZoomed(pItem->hMainWndBackup);
    EnableMenuItem(hMainMenu, IDM_PROCESS_WINDOW_RESTORE, v6);
    v7 = IsIconic(pItem->hMainWndBackup);
    EnableMenuItem(hMainMenu, IDM_PROCESS_WINDOW_MINIMIZE, v7 != 0);
    v8 = IsZoomed(pItem->hMainWndBackup);
    result = EnableMenuItem(hMainMenu, IDM_PROCESS_WINDOW_MAXIMIZE, v8 != 0);
  }
  else
  {
    v3 = GetSubMenu(hMainMenu, 3);
    EnableMenuItem(v3, 0, 0x401u);
    EnableMenuItem(hMainMenu, IDM_PROCESS_WINDOW_BRING_TO_FRONT, MF_GRAYED);
    EnableMenuItem(hMainMenu, IDM_PROCESS_WINDOW_CLOSE, MF_GRAYED);
    EnableMenuItem(hMainMenu, IDM_PROCESS_WINDOW_RESTORE, MF_GRAYED);
    EnableMenuItem(hMainMenu, IDM_PROCESS_WINDOW_MINIMIZE, MF_GRAYED);
    result = EnableMenuItem(hMainMenu, IDM_PROCESS_WINDOW_MAXIMIZE, MF_GRAYED);
  }
  return result;
}
