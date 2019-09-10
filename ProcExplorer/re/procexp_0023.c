
//----- (00FB9980) --------------------------------------------------------
BOOL __cdecl sub_FB9980(HWND hWnd)
{
  HDC v1; // ebx
  struct tagCHOOSEFONTW v3; // [esp+Ch] [ebp-DCh]
  HWND v4; // [esp+48h] [ebp-A0h]
  LOGFONTW lf; // [esp+4Ch] [ebp-9Ch]
  WINDOWPLACEMENT wndpl; // [esp+A8h] [ebp-40h]
  struct tagRECT Rect; // [esp+D4h] [ebp-14h]

  v4 = hWnd;
  v1 = GetDC(hWnd);
  qmemcpy(&lf, &gConfig.UnicodeFont, sizeof(lf));
  v3.hDC = CreateCompatibleDC(v1);
  ReleaseDC(hWnd, v1);
  v3.lStructSize = 60;
  v3.lpLogFont = &lf;
  v3.hInstance = ghInstance;
  v3.nFontType = 0x2000;
  v3.hwndOwner = hWnd;
  v3.Flags = 8273;
  v3.rgbColors = 0;
  v3.lCustData = 0;
  v3.lpszStyle = 0;
  v3.nSizeMin = 0;
  v3.nSizeMax = 20;
  v3.lpfnHook = 0;
  v3.lpTemplateName = 1543;
  if ( ChooseFontW(&v3) )
  {
    qmemcpy(&gConfig.UnicodeFont, &lf, sizeof(gConfig.UnicodeFont));
    DeleteObject(ghConfigFont);
    ghConfigFont = CreateFontIndirectW(&gConfig.UnicodeFont);
    lf.lfUnderline = 1;
    ghConfigUnderlineFont = CreateFontIndirectW(&lf);
    InitTreeList(ghWndTreeListView, ghConfigFont);
    InitTreeList(ghWndDllsListCtrl, ghConfigFont);
    InitTreeList(ghWndHandlesListCtrl, ghConfigFont);
    GetWindowRect(ghMainWnd, &Rect);
    SetWindowPos(ghMainWnd, 0, Rect.left, Rect.top, Rect.right - Rect.left - 1, Rect.bottom - Rect.top, 4u);
    SetWindowPos(ghMainWnd, 0, Rect.left, Rect.top, Rect.right - Rect.left, Rect.bottom - Rect.top, 4u);
    if ( ghFindDlg )
    {
      EndDialog(ghFindDlg, 0);
      ghFindDlg = 0;
    }
    wndpl.flags = 0;
    wndpl.length = 44;
    GetWindowPlacement(hWnd, &wndpl);
    if ( wndpl.showCmd == 3 )
    {
      ShowWindow(hWnd, 9);
      ShowWindow(hWnd, 3);
    }
  }
  return DeleteDC(v3.hDC);
}

//----- (00FB9BB0) --------------------------------------------------------
LRESULT __cdecl sub_FB9BB0(HWND hWnd, LONG dwNewLong, UINT *pnIDs, WORD *pnWidths, char fSortable)
{
  LONG v5; // eax
  HWND v6; // eax
  LRESULT result; // eax
  struct _IMAGELIST *v8; // esi
  LONG v9; // eax

  v5 = GetWindowLongW(hWnd, -16);
  SetWindowLongW(hWnd, -16, v5 & 0xFFFFFFFD | 9);
  SetWindowLongW(hWnd, -21, dwNewLong);
  SendMessageW(hWnd, LVM_SETEXTENDEDLISTVIEWSTYLE, 0x4020u, 0x4020);
  v6 = SendMessageW(hWnd, LVM_GETTOOLTIPS, 0, 0);
  CTreeList::InitToolTips(v6);
  result = CTreeView::InitListHeader(hWnd, pnIDs, pnWidths, dwNewLong);
  if ( fSortable )
  {
    v8 = InitSortableImageList();
    v9 = GetWindowLongW(hWnd, -16);
    SetWindowLongW(hWnd, -16, v9 | LVS_SHAREIMAGELISTS);
    result = SendMessageW(hWnd, LVM_SETIMAGELIST, 1u, v8);
  }
  return result;
}

//----- (00FB9C50) --------------------------------------------------------
char __cdecl IsColumnIDValid(HWND hWnd, DWORD dwId)
{
  int nIndex; // eax

  nIndex = 0;
  if ( gConfig.dwProcessColumnCount <= 0 )
    return 0;
  while ( gConfig.dwProcessColumnMap[nIndex] != dwId )
  {
    if ( ++nIndex >= gConfig.dwProcessColumnCount )
      return 0;
  }
  return 1;
}

//----- (00FB9C80) --------------------------------------------------------
int __stdcall Proxy_ListCtrlWndProc(HWND hWnd, UINT Msg, WPARAM wParamIn, LPARAM lParamIn)
{
  HWND hWnd_1; // ebx
  LPARAM v5; // edi
  int result; // eax
  HCURSOR v7; // eax
  LRESULT nItemCount_1; // eax
  HBRUSH hBrush; // eax
  HBRUSH hBrush_1; // eax
  LRESULT nTopIndex; // eax
  HBRUSH hBrush_2; // eax
  int code; // eax
  signed int v14; // edi
  int v15; // ST18_4
  int v16; // ST14_4
  HWND v17; // eax
  int v18; // ST18_4
  int v19; // ST14_4
  HWND v20; // eax
  int nRet; // edi
  HDC v22; // esi
  int v23; // eax
  bool v24; // zf
  bool v25; // sf
  unsigned __int8 v26; // of
  LPARAM v27; // eax
  void *v28; // ST24_4
  LPARAM v29; // eax
  HWND hWndTooltips; // eax
  HANDLE v31; // eax
  HWND hWndTooltips_1; // eax
  HCURSOR hCursor; // eax
  unsigned int pUserData; // esi
  unsigned int nIndex; // ecx
  __m128i v36; // xmm1
  LPARAM *v37; // edx
  unsigned int v38; // eax
  __m128i v39; // xmm0
  HGLOBAL hGlobal; // edi
  int nLength; // ebx
  wchar_t *pBuffer; // esi
  LRESULT nItem_1; // ecx
  unsigned int nIdIndex; // eax
  HDC wParam_3; // ST20_4
  HWND hWndParent; // eax
  HWND hWndList; // edi
  int nItem; // eax
  int nID; // esi
  LRESULT nCount; // eax
  LRESULT v51; // eax
  LVITEMW Item; // [esp+Ch] [ebp-6254h]
  LVITEMW item; // [esp+40h] [ebp-6220h]
  unsigned int v54; // [esp+74h] [ebp-61ECh]
  HWND hWndNewOwner; // [esp+78h] [ebp-61E8h]
  unsigned __int32 nItemCount; // [esp+7Ch] [ebp-61E4h]
  LPARAM lParam_2; // [esp+80h] [ebp-61E0h]
  HDC wParam_2; // [esp+84h] [ebp-61DCh]
  struct tagPOINT Point; // [esp+88h] [ebp-61D8h]
  char v60; // [esp+90h] [ebp-61D0h]
  WPARAM uMsg; // [esp+94h] [ebp-61CCh]
  WPARAM wParam_1; // [esp+98h] [ebp-61C8h]
  RECT lParam_1; // [esp+9Ch] [ebp-61C4h]
  RECT rcItem; // [esp+ACh] [ebp-61B4h]
  struct tagRECT Rect; // [esp+BCh] [ebp-61A4h]
  RECT rc; // [esp+CCh] [ebp-6194h]
  LPARAM arrIDs[96]; // [esp+DCh] [ebp-6184h]
  WCHAR szText[8192]; // [esp+25Ch] [ebp-6004h]
  WCHAR chText[4096]; // [esp+425Ch] [ebp-2004h]

  hWnd_1 = hWnd;
  v5 = lParamIn;
  wParam_2 = wParamIn;
  hWndNewOwner = hWnd;
  lParam_2 = lParamIn;
  item.mask = 0;
  memset(&item.iItem, 0, 0x30u);
  if ( Msg > WM_NOTIFY )
  {
    if ( Msg == WM_KEYDOWN )
    {
      switch ( wParam_2 )
      {
        case VK_TAB:
          hWndList = ghWndTreeListView;
          if ( hWnd == ghWndTreeListView )
          {
            hWndList = ghWndHandlesListCtrl;
            if ( gConfig.bShowDllView )
              hWndList = ghWndDllsListCtrl;
          }
          item.iItem = 0;
          item.iSubItem = 0;
          item.stateMask = 2;
          item.mask = 12;
          nItem = SendMessageW(hWndList, LVM_GETNEXTITEM, 0xFFFFFFFF, 2);
          if ( nItem == -1 )
            nItem = 0;
          item.iItem = nItem;
          SetFocus(hWndList);
          Item.stateMask = 3;
          Item.state = 3;
          SendMessageW(hWndList, LVM_SETITEMSTATE, item.iItem, &Item);
          return 0;
        case VK_RETURN:
          if ( hWnd == ghWndTreeListView )
          {
            nID = IDC_TREEVIEW_LIST;
          }
          else
          {
            nItemCount = 2 * (hWnd == ghWndDllsListCtrl) + IDC_LISTCTRL_HANDLES;
            nID = 2 * (hWnd == ghWndDllsListCtrl) + IDC_LISTCTRL_HANDLES;
          }
          item.iItem = SendMessageW(hWnd, LVM_GETNEXTITEM, 0xFFFFFFFF, 2);
          if ( item.iItem != -1 )
            FillList(nID);
          return 0;
        case VK_END:
          Item.stateMask = 3;
          Item.state = 3;
          nCount = SendMessageW(hWnd, LVM_GETITEMCOUNT, 0, 0);
          SendMessageW(hWnd, LVM_SETITEMSTATE, nCount - 1, &Item);
          v51 = SendMessageW(hWnd, LVM_GETITEMCOUNT, 0, 0);
          SendMessageW(hWnd, LVM_ENSUREVISIBLE, v51 - 1, 0);
          return 0;
        case VK_HOME:
          Item.stateMask = 3;
          Item.state = 3;
          SendMessageW(hWnd, LVM_SETITEMSTATE, 0, &Item);
          SendMessageW(hWnd, LVM_ENSUREVISIBLE, 0, 0);
          return 0;
        case VK_CANCEL|0x40:
          if ( hWnd != ghWndTreeListView && GetKeyState(VK_LCONTROL) )
          {
            pUserData = GetWindowLongW(hWnd, GWLP_USERDATA);
            nItemCount = pUserData;
            if ( !SendMessageW(hWnd, LVM_GETCOLUMNORDERARRAY, pUserData, arrIDs) )
            {
              nIndex = 0;
              if ( pUserData )
              {
                if ( pUserData >= 8 )
                {
                  v36 = _mm_load_si128(&gIntArray);
                  v37 = &arrIDs[4];
                  do
                  {
                    v38 = nIndex + 4;
                    v37 += 8;
                    v39 = _mm_add_epi32(_mm_shuffle_epi32(_mm_cvtsi32_si128(nIndex), 0), v36);
                    nIndex += 8;
                    _mm_storeu_si128(v37 - 3, v39);
                    _mm_storeu_si128(v37 - 2, _mm_add_epi32(_mm_shuffle_epi32(_mm_cvtsi32_si128(v38), 0), v36));
                  }
                  while ( nIndex < pUserData - (pUserData & 7) );
                }
                for ( ; nIndex < pUserData; ++nIndex )
                  arrIDs[nIndex] = nIndex;
              }
            }
            hGlobal = 0;
            item.iItem = -1;
            nLength = 0;
            pBuffer = 0;
            nItem_1 = SendMessageW(hWndNewOwner, LVM_GETNEXTITEM, 0xFFFFFFFF, 2);
            for ( item.iItem = nItem_1; nItem_1 != -1; item.iItem = nItem_1 )
            {
              nIdIndex = 0;
              v54 = 0;
              if ( nItemCount )
              {
                while ( 1 )
                {
                  Item.iSubItem = arrIDs[nIdIndex];
                  Item.pszText = szText;
                  Item.cchTextMax = 8192;
                  SendMessageW(hWndNewOwner, LVM_GETITEMTEXTW, nItem_1, &Item);
                  nLength += wcslen(szText) + 2;
                  if ( pBuffer )
                  {
                    GlobalUnlock(hGlobal);
                    hGlobal = GlobalReAlloc(hGlobal, 2 * nLength + 2, 0);
                    pBuffer = GlobalLock(hGlobal);
                  }
                  else
                  {
                    hGlobal = GlobalAlloc(0x2002u, 2 * nLength + 2);
                    pBuffer = GlobalLock(hGlobal);
                    *pBuffer = 0;
                  }
                  wcscat_s(pBuffer, nLength + 1, szText);
                  if ( ++v54 >= nItemCount )
                    break;
                  wcscat_s(pBuffer, nLength + 1, L"\t");
                  nIdIndex = v54;
                  if ( v54 >= nItemCount )
                    break;
                  nItem_1 = item.iItem;
                }
              }
              wcscat_s(pBuffer, nLength + 1, L"\r\n");
              GlobalUnlock(hGlobal);
              nItem_1 = SendMessageW(hWndNewOwner, LVM_GETNEXTITEM, item.iItem, 2);
            }
            hWnd_1 = hWndNewOwner;
            SetFocus(hWndNewOwner);
            if ( hGlobal && OpenClipboard(hWnd_1) )
            {
              EmptyClipboard();
              SetClipboardData(CF_UNICODETEXT, hGlobal);
              CloseClipboard();
            }
            v5 = lParam_2;
          }
          goto LABEL_70;
        default:
LABEL_70:
          wParam_3 = wParam_2;
          hWndParent = GetParent(hWnd_1);
          SendMessageW(hWndParent, WM_KEYDOWN, wParam_3, v5);
          break;
      }
    }
    else if ( Msg == WM_MOUSEMOVE )
    {
      if ( gdwVersion < 1 )
      {
        hWndTooltips = SendMessageW(hWnd, LVM_GETTOOLTIPS, 0, 0);
        if ( !IsWindowVisible(hWndTooltips)
          || (Point.x = lParamIn, Point.y = SHIWORD(lParamIn), SendMessageW(hWnd, LVM_SUBITEMHITTEST, 0, &Point) >= 0)
          && (v31 = GetPropW(hWnd, L"hitrow"), wParam_1 != v31) )
        {
          hWndTooltips_1 = SendMessageW(hWnd, LVM_GETTOOLTIPS, 0, 0);
          SendMessageW(hWndTooltips_1, TTM_POP, 0, 0);
        }
      }
      if ( hWnd == ghWndDllsListCtrl )
      {
        GetCursorPos(&Point);
        ScreenToClient(hWnd, &Point);
        if ( SendMessageW(hWnd, LVM_SUBITEMHITTEST, 0, &Point) >= 0
          && gConfig.dwDllColumnMap[wParam_1] == IDS_VIRUSTOTAL )
        {
          item.iItem = uMsg;
          item.mask = LVIF_PARAM;
          SendMessageW(hWnd, LVM_GETITEMW, 0, &item);
          if ( sub_1001820(item.lParam[4].field_1C) )
          {
            hCursor = LoadCursorW(ghInstance, L"HAND");
            SetCursor(hCursor);
          }
        }
      }
    }
    return CallWindowProcW(gOldListWndProc, hWnd_1, Msg, wParam_2, v5);
  }
  if ( Msg != WM_NOTIFY )
  {
    switch ( Msg )
    {
      case WM_SETFOCUS:
      case WM_KILLFOCUS:
        if ( hWnd == ghWndTreeListView && wParam_2 != ghWndTreeListView )
          RefreshTreeView();
        return CallWindowProcW(gOldListWndProc, hWnd_1, Msg, wParam_2, v5);
      case WM_ERASEBKGND:
        if ( !SendMessageW(hWnd, LVM_GETITEMCOUNT, 0, 0) )
          return CallWindowProcW(gOldListWndProc, hWnd_1, Msg, wParam_2, v5);
        GetClientRect(hWnd, &Rect);
        rcItem.left = 0;
        nItemCount_1 = SendMessageW(hWnd, LVM_GETITEMCOUNT, 0, 0);
        SendMessageW(hWnd, LVM_GETITEMRECT, nItemCount_1 - 1, &rcItem);
        rc.left = rcItem.right;
        hBrush = GetSysColorBrush(COLOR_WINDOW);
        FillRect(wParam_2, &rc, hBrush);
        rc = Rect;
        rc.right = Rect.right;
        rc.top = rcItem.bottom;
        rc.bottom = Rect.bottom;
        hBrush_1 = GetSysColorBrush(COLOR_WINDOW);
        FillRect(wParam_2, &rc, hBrush_1);
        rcItem.left = 0;
        nTopIndex = SendMessageW(hWnd, LVM_GETTOPINDEX, 0, 0);
        SendMessageW(hWnd, LVM_GETITEMRECT, nTopIndex, &rcItem);
        rc.right = Rect.right;
        rc.left = 0;
        rc.top = 0;
        rc.bottom = rcItem.top;
        hBrush_2 = GetSysColorBrush(COLOR_WINDOW);
        FillRect(wParam_2, &rc, hBrush_2);
        return 1;
      case WM_SETCURSOR:
        if ( hWnd == ghWndHandlesListCtrl )
        {
          SetCursor(ghArrowCursor);
          result = 1;
        }
        else
        {
          if ( gnRefCount )
            v7 = LoadCursorW(0, IDC_APPSTARTING);
          else
            v7 = LoadCursorW(0, IDC_ARROW);
          SetCursor(v7);
          result = 1;
        }
        return result;
      default:
        return CallWindowProcW(gOldListWndProc, hWnd_1, Msg, wParam_2, v5);
    }
    return CallWindowProcW(gOldListWndProc, hWnd_1, Msg, wParam_2, v5);
  }
  // WM_NOTIFY
  if ( *lParamIn != SendMessageW(hWnd, LVM_GETTOOLTIPS, 0, 0) )
    return CallWindowProcW(gOldListWndProc, hWnd_1, Msg, wParam_2, v5);
  code = *(lParamIn + 8);
  if ( code != TTN_GETDISPINFOW )
  {
    if ( code == TTN_SHOW )
    {
      v14 = -1;
      if ( gdwVersion >= 1 )
        v14 = -4;
      GetCursorPos(&Point);
      ScreenToClient(hWnd, &Point);
      item.iItem = SendMessageW(hWnd, LVM_SUBITEMHITTEST, 0, &Point);
      if ( item.iItem != -1 && wParam_1 != -1 )
      {
        sub_FBA880(hWnd, uMsg, wParam_1, &lParam_1);
        Point.x = lParam_1.left;
        Point.y = lParam_1.top;
        ClientToScreen(hWnd, &Point);
        v15 = Point.y - 1;
        v16 = v14 + Point.x;
        v17 = SendMessageW(hWnd, LVM_GETTOOLTIPS, 0, 0);
        SetWindowPos(v17, 0, v16, v15, 0, 0, SWP_NOACTIVATE|SWP_NOSIZE);
        return 1;
      }
      v18 = Point.y - 1;
      v19 = v14 + Point.x;
      v20 = SendMessageW(hWnd, LVM_GETTOOLTIPS, 0, 0);
      SetWindowPos(v20, 0, v19, v18, 0, 0, SWP_NOACTIVATE);
      v5 = lParam_2;
    }
    return CallWindowProcW(gOldListWndProc, hWnd_1, Msg, wParam_2, v5);
  }
  if ( gdwVersion >= 1 )
    return CallWindowProcW(gOldListWndProc, hWnd_1, Msg, wParam_2, v5);
  nRet = CallWindowProcW(gOldListWndProc, hWnd, WM_NOTIFY, wParam_2, lParamIn);
  GetCursorPos(&Point);
  ScreenToClient(hWnd, &Point);
  if ( SendMessageW(hWnd, LVM_SUBITEMHITTEST, 0, &Point) < 0 || !(v60 & 0xE) || (wParam_1 & 0x80000000) != 0 )
    return nRet;
  item.iSubItem = wParam_1;
  item.iItem = uMsg;
  item.mask = 1;
  item.pszText = chText;
  item.cchTextMax = 4096;
  SendMessageW(hWnd, LVM_GETITEMW, 0, &item);
  if ( !chText[0] )
  {
    v29 = lParam_2;
    *(lParam_2 + 12) = 0;
    *(v29 + 16) = 0;
    return nRet;
  }
  Item.pszText = 2;
  SendMessageW(hWnd, LVM_GETCOLUMNW, wParam_1, &Item.pszText);
  _mm_storeu_si128(&lParam_1, 0i64);
  v22 = GetDC(hWnd);
  SelectObject(v22, ghConfigFont);
  DrawTextW(v22, chText, -1, &lParam_1, 0xD00u);
  v23 = lParam_1.right - lParam_1.left + 6;
  v26 = __OFSUB__(v23, Item.iImage);
  v24 = v23 == Item.iImage;
  v25 = v23 - Item.iImage < 0;
  v27 = lParam_2;
  if ( (v25 ^ v26) | v24 )
  {
    *(lParam_2 + 12) = 0;
    *(v27 + 16) = 0;
  }
  else
  {
    v28 = wParam_1;
    *(lParam_2 + 12) = chText;
    SetPropW(hWnd, L"hitrow", v28);
  }
  ReleaseDC(hWnd, v22);
  return nRet;
}
// 103EA50: using guessed type RECT gIntArray;
// 1064E54: using guessed type int gdwVersion;

//----- (00FBA880) --------------------------------------------------------
LRESULT __cdecl sub_FBA880(HWND hWnd, WPARAM uMsg, WPARAM wParam_1, RECT *lParam_1)
{
  HWND hwnd; // ebx
  void (__stdcall *SendMessageW)(HWND, UINT, WPARAM, LPARAM); // edi
  LRESULT bRet; // eax
  int dwProcessColumnCount_1; // edx
  signed int dwColumnCount; // ecx
  __m128i v9; // xmm1
  LPARAM *v10; // edi
  int dwProcessColumnCount; // ebx
  unsigned int v12; // eax
  __m128i v13; // xmm0
  CTreeList *v14; // eax
  LRESULT result; // eax
  RECT *rect; // eax
  unsigned int index; // eax
  RECT *v18; // eax
  RECT *v19; // eax
  HWND hWnd_1; // [esp+Ch] [ebp-188h]
  LPARAM arrIDs[96]; // [esp+10h] [ebp-184h]

  hwnd = hWnd;
  SendMessageW = ::SendMessageW;
  hWnd_1 = hWnd;
  bRet = ::SendMessageW(hWnd, LVM_GETCOLUMNORDERARRAY, gConfig.dwProcessColumnCount, arrIDs);
  dwProcessColumnCount_1 = gConfig.dwProcessColumnCount;
  if ( !bRet )
  {
    dwColumnCount = 0;
    if ( gConfig.dwProcessColumnCount > 0 )
    {
      if ( gConfig.dwProcessColumnCount >= 8u )
      {
        v9 = _mm_load_si128(&gIntArray);
        v10 = &arrIDs[4];
        dwProcessColumnCount = gConfig.dwProcessColumnCount - gConfig.dwProcessColumnCount % 8;
        do
        {
          v12 = dwColumnCount + 4;
          v10 += 8;
          v13 = _mm_add_epi32(_mm_shuffle_epi32(_mm_cvtsi32_si128(dwColumnCount), 0), v9);
          dwColumnCount += 8;
          _mm_storeu_si128(v10 - 3, v13);
          _mm_storeu_si128(v10 - 2, _mm_add_epi32(_mm_shuffle_epi32(_mm_cvtsi32_si128(v12), 0), v9));
        }
        while ( dwColumnCount < dwProcessColumnCount );
        hwnd = hWnd_1;
        SendMessageW = ::SendMessageW;
      }
      for ( ; dwColumnCount < dwProcessColumnCount_1; ++dwColumnCount )
        arrIDs[dwColumnCount] = dwColumnCount;
    }
  }
  if ( uMsg == -2 )
  {
    v14 = CTreeList::GetTreeList(hwnd);
    CTreeList::MapToHeader(v14, wParam_1, lParam_1);
    lParam_1->bottom -= lParam_1->top;
    result = lParam_1->left;
    lParam_1->right -= lParam_1->left;
  }
  else if ( wParam_1 )
  {
    if ( lParam_1 )
    {
      lParam_1->top = wParam_1;
      rect = lParam_1;
      lParam_1->left = 0;
    }
    else
    {
      rect = 0;
    }
    SendMessageW(hwnd, LVM_GETSUBITEMRECT, uMsg, rect);
    lParam_1->bottom -= lParam_1->top;
    result = lParam_1->left;
    lParam_1->right -= lParam_1->left;
  }
  else
  {
    index = 0;
    while ( arrIDs[index] )
    {
      if ( !arrIDs[index + 1] )
      {
        ++index;
        break;
      }
      if ( !arrIDs[index + 2] )
      {
        index += 2;
        break;
      }
      if ( !arrIDs[index + 3] )
      {
        index += 3;
        break;
      }
      if ( !arrIDs[index + 4] )
      {
        index += 4;
        break;
      }
      if ( !arrIDs[index + 5] )
      {
        index += 5;
        break;
      }
      index += 6;
      if ( index >= 96 )
        break;
    }
    if ( dwProcessColumnCount_1 == 1 )
    {
      if ( lParam_1 )
      {
        lParam_1->left = 0;
        result = (SendMessageW)(hwnd, LVM_GETITEMRECT, uMsg, lParam_1);
      }
      else
      {
        result = (SendMessageW)(hwnd, LVM_GETITEMRECT, uMsg, 0);
      }
    }
    else if ( index )
    {
      if ( lParam_1 )
      {
        lParam_1->top = *(&hWnd_1 + index);
        v18 = lParam_1;
        lParam_1->left = 0;
      }
      else
      {
        v18 = 0;
      }
      SendMessageW(hwnd, LVM_GETSUBITEMRECT, uMsg, v18);
      lParam_1->left = lParam_1->right;
      result = (SendMessageW)(hwnd, LVM_GETCOLUMNWIDTH, 0, 0);
      lParam_1->right = result;
    }
    else
    {
      if ( lParam_1 )
      {
        lParam_1->top = 1;
        v19 = lParam_1;
        lParam_1->left = 0;
      }
      else
      {
        v19 = 0;
      }
      SendMessageW(hwnd, LVM_GETSUBITEMRECT, uMsg, v19);
      lParam_1->bottom -= lParam_1->top;
      result = (SendMessageW)(hwnd, LVM_GETCOLUMNWIDTH, 0, 0);
      lParam_1->left = 0;
      lParam_1->right = result;
    }
  }
  return result;
}
// 103EA50: using guessed type RECT gIntArray;

//----- (00FBAB00) --------------------------------------------------------
BOOL __cdecl InitTreeList(HWND hWnd, WPARAM wParam)
{
  HWND v2; // eax
  struct tagRECT Rect; // [esp+Ch] [ebp-14h]

  v2 = SendMessageW(hWnd, 0x101Fu, 0, 0);
  SendMessageW(v2, 0x30u, wParam, 0);
  SendMessageW(hWnd, 0x30u, wParam, 0);
  GetClientRect(ghMainWnd, &Rect);
  CMainWnd::HandleSize(
    ghMainWnd,
    0,
    0,
    (LOWORD(Rect.right) - LOWORD(Rect.left)) | ((LOWORD(Rect.bottom) - LOWORD(Rect.top)) << 16));
  return InvalidateRgn(hWnd, 0, 1);
}

//----- (00FBABA0) --------------------------------------------------------
int __stdcall PropProcThreadsSortCallback(int a1, int a2, int *a3)
{
  _DWORD *v3; // esi
  signed int v4; // ebx
  int v5; // ecx
  _DWORD *v6; // edi
  _DWORD *v7; // edx
  unsigned int v8; // eax
  unsigned int v9; // ecx
  _DWORD *v10; // ebx
  bool v11; // cf
  int result; // eax
  int v13; // eax
  double v14; // xmm0_8
  double v15; // xmm1_8
  bool v16; // zf
  int v17; // ebx
  int v18; // edx
  unsigned int v19; // ecx
  unsigned int v20; // eax
  int v21; // ebx
  int v22; // edx
  unsigned int v23; // ecx
  unsigned int v24; // eax
  int v25; // eax
  _DWORD *v26; // ecx
  int v27; // ecx
  int v28; // ecx
  int v29; // ecx
  int v30; // ecx
  int v31; // ecx
  int v32; // ecx
  int v33; // ecx
  int v34; // ecx
  int v35; // ecx
  int v36; // ecx
  int v37; // ecx
  int v38; // ecx
  int v39; // ecx
  int v40; // ecx
  int v41; // ecx
  __int16 v42; // cx
  __int16 v43; // dx
  int v44; // ebx
  int v45; // eax
  const WCHAR *v46; // ecx
  int (__stdcall *v47)(LPCWSTR, LPCWSTR); // eax
  signed int v48; // eax
  int v49; // ebx
  int v50; // eax
  LPCWSTR v51; // eax
  LPCWSTR v52; // ebx
  int v53; // ecx
  int v54; // eax
  int v55; // ebx
  wchar_t **v56; // eax
  wchar_t *v57; // eax
  wchar_t **v58; // eax
  wchar_t *v59; // eax
  int v60; // eax
  signed int v61; // eax
  int v62; // eax
  int v63; // eax
  int v64; // eax
  unsigned int v65; // eax
  unsigned int v66; // ecx
  int v67; // eax
  int v68; // eax
  signed int v69; // eax
  unsigned int v70; // eax
  unsigned int v71; // ecx
  bool v72; // cf
  int v73; // eax
  const wchar_t *v74; // eax
  const wchar_t *v75; // eax
  int v76; // eax
  unsigned int v77; // ecx
  unsigned int v78; // eax
  unsigned int v79; // esi
  unsigned int v80; // edx
  unsigned __int64 v81; // kr18_8
  int v82; // eax
  int v83; // eax
  int v84; // eax
  int v85; // eax
  int v86; // eax
  int v87; // ebx
  unsigned int v88; // eax
  unsigned int v89; // ecx
  int v90; // eax
  int v91; // eax
  signed int v92; // eax
  int v93; // eax
  int v94; // eax
  int v95; // eax
  int v96; // eax
  int v97; // eax
  int v98; // ecx
  int v99; // eax
  int v100; // ebx
  wchar_t **v101; // eax
  wchar_t *v102; // eax
  wchar_t **v103; // eax
  wchar_t *v104; // eax
  int v105; // eax
  int v106; // eax
  int v107; // eax
  double v108; // xmm0_8
  int v109; // ebx
  int v110; // edx
  unsigned int v111; // ecx
  unsigned int v112; // eax
  unsigned int v113; // ecx
  signed int v114; // esi
  signed __int64 v115; // rax
  double v116; // xmm1_8
  int v117; // eax
  int v118; // eax
  int v119; // eax
  const wchar_t *v120; // ecx
  u_long v121; // esi
  u_long v122; // eax
  int v123; // esi
  u_short v124; // ax
  u_long v125; // esi
  u_long v126; // eax
  int v127; // esi
  u_short v128; // ax
  int v129; // eax
  int v130; // ebx
  int v131; // edi
  u_long v132; // edi
  int v133; // eax
  int v134; // ebx
  int v135; // edi
  u_long v136; // eax
  int v137; // [esp+10h] [ebp-424h]
  int v138; // [esp+14h] [ebp-420h]
  LPCWSTR lpString1; // [esp+18h] [ebp-41Ch]
  LPCWSTR v140; // [esp+1Ch] [ebp-418h]
  WCHAR String2; // [esp+20h] [ebp-414h]
  WCHAR String1; // [esp+228h] [ebp-20Ch]

  v3 = a1;
  v4 = 0;
  v5 = *a3;
  v140 = a1;
  v6 = a2;
  if ( v5 != 101 )
  {
    if ( v5 == 102 )
    {
      v61 = gConfig.dwIdsOfHandleColumnMap[a3[1]];
      if ( v61 > 39 )
      {
        v67 = v61 - 1185;
        if ( !v67 )
        {
          v4 = *(a1 + 40) - *(a2 + 40);
LABEL_274:
          v16 = LOBYTE(gConfig.bHandleSortDirection) == 0;
          goto LABEL_419;
        }
        v68 = v67 - 9;
        if ( !v68 )
        {
          v4 = *(a1 + 52) - *(a2 + 52);
          v16 = LOBYTE(gConfig.bHandleSortDirection) == 0;
          goto LABEL_419;
        }
        if ( v68 != 114 )
        {
LABEL_270:
          v4 = -1;
          v16 = LOBYTE(gConfig.bHandleSortDirection) == 0;
          goto LABEL_419;
        }
      }
      else if ( v61 != 39 )
      {
        v62 = v61 - 20;
        if ( v62 )
        {
          v63 = v62 - 1;
          if ( v63 )
          {
            if ( v63 == 1 )
            {
              v64 = lstrcmpiW((a1 + 2232), (a2 + 2232));
              v16 = LOBYTE(gConfig.bHandleSortDirection) == 0;
              v4 = v64;
              goto LABEL_419;
            }
            goto LABEL_270;
          }
          v4 = lstrcmpiW((a1 + 56), (a2 + 56));
          if ( !v4 )
          {
            v4 = *(a2 + 44) < *(a1 + 44) ? 1 : -1;
            v16 = LOBYTE(gConfig.bHandleSortDirection) == 0;
            goto LABEL_419;
          }
          goto LABEL_274;
        }
        v65 = *(a1 + 44);
        v66 = *(a2 + 44);
        if ( v65 <= v66 )
        {
          v4 = -(v65 < v66);
          v16 = LOBYTE(gConfig.bHandleSortDirection) == 0;
        }
        else
        {
          v16 = LOBYTE(gConfig.bHandleSortDirection) == 0;
          v4 = 1;
        }
        goto LABEL_419;
      }
      v4 = *(a1 + 48) - *(a2 + 48);
      v16 = LOBYTE(gConfig.bHandleSortDirection) == 0;
      goto LABEL_419;
    }
    if ( v5 == 104 )
    {
      v69 = gConfig.dwDllColumnMap[a3[1]];
      if ( v69 <= 30 )
      {
        if ( v69 != 30 )
        {
          switch ( v69 )
          {
            case 23:
              v70 = *(a1 + 36);
              v71 = *(a2 + 36);
              v72 = v70 < v71;
              if ( v70 <= v71 )
                goto LABEL_281;
              v16 = LOBYTE(gConfig.bDllSortDirection) == 0;
              v4 = 1;
              break;
            case 24:
              v4 = *(a1 + 56) - *(a2 + 56);
              v16 = LOBYTE(gConfig.bDllSortDirection) == 0;
              break;
            case 25:
              v73 = lstrcmpiW((a1 + 206), (a2 + 206));
              v16 = LOBYTE(gConfig.bDllSortDirection) == 0;
              v4 = v73;
              break;
            case 26:
              if ( wcsrchr(*(a1 + 344), 0x5Cu) )
                v74 = wcsrchr(*(a1 + 344), 0x5Cu) + 1;
              else
                v74 = *(a1 + 344);
              wcscpy_s(&String1, 0x104u, v74);
              if ( wcsrchr(*(a2 + 344), 0x5Cu) )
                v75 = wcsrchr(*(a2 + 344), 0x5Cu) + 1;
              else
                v75 = *(a2 + 344);
              wcscpy_s(&String2, 0x104u, v75);
              v76 = lstrcmpiW(&String1, &String2);
              v16 = LOBYTE(gConfig.bDllSortDirection) == 0;
              v4 = v76;
              break;
            default:
              goto LABEL_330;
          }
          goto LABEL_419;
        }
        v77 = *(a1 + 64);
        v78 = *(a1 + 68);
        v79 = *(a2 + 64);
        v80 = *(a2 + 68);
        if ( v77 == v79 && v78 == v80 )
        {
          v4 = 0;
          v16 = LOBYTE(gConfig.bDllSortDirection) == 0;
          goto LABEL_419;
        }
        v81 = __PAIR__(v78, v77) - __PAIR__(v80, v79);
        v137 = (__PAIR__(v78, v77) - __PAIR__(v80, v79)) >> 32;
        if ( v137 >= 0 && (__PAIR__(v78, v77) >= __PAIR__(v80, v79) && HIDWORD(v81) != 0 || v81) )
        {
          v16 = LOBYTE(gConfig.bDllSortDirection) == 0;
          v4 = 1;
          goto LABEL_419;
        }
        goto LABEL_330;
      }
      if ( v69 > 1118 )
      {
        if ( v69 > 1656 )
        {
          if ( v69 == 1670 )
          {
            v98 = *(a1 + 364);
            if ( v98 )
            {
              v99 = *(a2 + 364);
              if ( v99 )
              {
                v100 = *(v98 + 4);
                if ( v100 != 1 || *(v99 + 4) != 1 )
                {
                  v4 = v100 - *(v99 + 4);
                  v16 = LOBYTE(gConfig.bDllSortDirection) == 0;
                  goto LABEL_419;
                }
                v137 = *(v98 + 4);
                v138 = 1;
                lpString1 = -1;
                v140 = -1;
                v101 = *(v98 + 40);
                if ( v101 )
                  v102 = *v101;
                else
                  v102 = 0;
                scan_fn(v102, L"%d/%d", &v137);
                v103 = *(*(a2 + 364) + 40);
                if ( v103 )
                  v104 = *v103;
                else
                  v104 = 0;
                scan_fn(v104, L"%d/%d", &v138);
                v87 = v137;
                v86 = v138;
                if ( v137 == v138 )
                {
                  v4 = lpString1 - v140;
                  v16 = LOBYTE(gConfig.bDllSortDirection) == 0;
                  goto LABEL_419;
                }
                goto LABEL_308;
              }
            }
            v92 = sub_FC37B0(v98, *(a2 + 364));
            goto LABEL_350;
          }
          if ( v69 == 40757 )
          {
            v4 = (*(a1 + 54) & 0x4000) - (*(a2 + 54) & 0x4000);
            if ( (*(a1 + 54) & 0x4000) == (*(a2 + 54) & 0x4000) )
            {
              if ( *(a1 + 54) )
                v4 = *(a2 + 54) == 0;
              else
                v4 = -1;
              v16 = LOBYTE(gConfig.bDllSortDirection) == 0;
              goto LABEL_419;
            }
            goto LABEL_351;
          }
        }
        else
        {
          if ( v69 == 1656 )
          {
            v97 = lstrcmpiW(*(a1 + 348), *(a2 + 348));
            v16 = LOBYTE(gConfig.bDllSortDirection) == 0;
            v4 = v97;
            goto LABEL_419;
          }
          v94 = v69 - 1187;
          if ( !v94 )
          {
            v96 = lstrcmpiW(*(a1 + 356), *(a2 + 356));
            v16 = LOBYTE(gConfig.bDllSortDirection) == 0;
            v4 = v96;
            goto LABEL_419;
          }
          v95 = v94 - 130;
          if ( !v95 )
          {
            v92 = sub_FC37B0(*(a1 + 376), *(a2 + 376));
            goto LABEL_350;
          }
          if ( v95 == 21 )
          {
            v4 = (*(a1 + 54) & 0x40) - (*(a2 + 54) & 0x40);
            if ( (*(a1 + 54) & 0x40) == (*(a2 + 54) & 0x40) )
            {
              v4 = ((*(a2 + 44) >> 1) & 1) - ((*(a1 + 44) >> 1) & 1);
              v16 = LOBYTE(gConfig.bDllSortDirection) == 0;
              goto LABEL_419;
            }
            goto LABEL_351;
          }
        }
      }
      else
      {
        if ( v69 == 1118 )
        {
          v92 = sub_FC37B0(*(a1 + 380), *(a2 + 380));
          goto LABEL_350;
        }
        if ( v69 <= 1074 )
        {
          if ( v69 == 1074 )
          {
            v88 = *(a1 + 48);
            v89 = *(a2 + 48);
            v72 = v88 < v89;
            if ( v88 <= v89 )
            {
LABEL_281:
              v4 = -v72;
              v16 = LOBYTE(gConfig.bDllSortDirection) == 0;
            }
            else
            {
              v16 = LOBYTE(gConfig.bDllSortDirection) == 0;
              v4 = 1;
            }
            goto LABEL_419;
          }
          v82 = v69 - 40;
          if ( v82 )
          {
            v83 = v82 - 2;
            if ( !v83 )
            {
              v85 = lstrcmpiW(*(a1 + 336), *(a2 + 336));
              v16 = LOBYTE(gConfig.bDllSortDirection) == 0;
              v4 = v85;
              goto LABEL_419;
            }
            if ( v83 == 991 )
            {
              v84 = lstrcmpiW(*(a1 + 340), *(a2 + 340));
              v16 = LOBYTE(gConfig.bDllSortDirection) == 0;
              v4 = v84;
              goto LABEL_419;
            }
            goto LABEL_330;
          }
          v86 = (*(a2 + 44) >> 1) & 1;
          v87 = (*(a1 + 44) >> 1) & 1;
LABEL_308:
          v4 = v87 - v86;
          v16 = LOBYTE(gConfig.bDllSortDirection) == 0;
          goto LABEL_419;
        }
        v90 = v69 - 1111;
        if ( !v90 )
        {
          v93 = lstrcmpiW(*(a1 + 344), *(a2 + 344));
          v16 = LOBYTE(gConfig.bDllSortDirection) == 0;
          v4 = v93;
          goto LABEL_419;
        }
        v91 = v90 - 4;
        if ( !v91 )
        {
          v92 = sub_FC37B0(*(a1 + 368), *(a2 + 368));
          goto LABEL_350;
        }
        if ( v91 == 1 )
        {
          v92 = sub_FC37B0(*(a1 + 372), *(a2 + 372));
LABEL_350:
          v4 = v92;
LABEL_351:
          v16 = LOBYTE(gConfig.bDllSortDirection) == 0;
          goto LABEL_419;
        }
      }
LABEL_330:
      v4 = -1;
      v16 = LOBYTE(gConfig.bDllSortDirection) == 0;
      goto LABEL_419;
    }
    if ( v5 != 1040 )
    {
      if ( v5 == 1044 )
      {
        v107 = a3[1];
        switch ( v107 )
        {
          case 0:
            v4 = *(a1 + 44) - *(a2 + 44);
            v16 = byte_10653B4 == 0;
            goto LABEL_419;
          case 1:
            v108 = *(a1 + 576);
            if ( v108 != 0.0 || v108 != *(a2 + 576) )
            {
              v116 = *(a2 + 576);
              if ( v108 <= v116 )
              {
                v4 = (v116 <= v108) - 1;
                v16 = byte_10653B4 == 0;
              }
              else
              {
                v16 = byte_10653B4 == 0;
                v4 = 1;
              }
              goto LABEL_419;
            }
            v109 = *(a1 + 604);
            v110 = *(a2 + 604);
            v111 = *(a1 + 600);
            v112 = *(a2 + 600);
            if ( v109 < v110 )
              goto LABEL_377;
            if ( v109 > v110 )
              goto LABEL_375;
            if ( v111 > v112 )
            {
              v16 = byte_10653B4 == 0;
              v4 = 1;
              goto LABEL_419;
            }
            if ( v109 > v110 )
              goto LABEL_372;
            if ( v109 >= v110 )
            {
              if ( v111 < v112 )
              {
                v4 = -1;
                v16 = byte_10653B4 == 0;
                goto LABEL_419;
              }
LABEL_372:
              v113 = *(a1 + 584);
              v114 = *(a1 + 588);
              v115 = *(a2 + 584);
              if ( v114 >= SHIDWORD(v115) )
              {
                if ( v114 > SHIDWORD(v115) || v113 > v115 )
                {
LABEL_375:
                  v16 = byte_10653B4 == 0;
                  v4 = 1;
                  goto LABEL_419;
                }
                if ( __PAIR__(v114, v113) >= v115 )
                {
                  v4 = 0;
                  v16 = byte_10653B4 == 0;
                  goto LABEL_419;
                }
              }
            }
LABEL_377:
            v4 = -1;
            v16 = byte_10653B4 == 0;
            goto LABEL_419;
          case 2:
            if ( QueryThreadCycleTime && *(a1 + 40) )
            {
              v4 = sub_FC37B0(*(a1 + 600), *(a2 + 600));
              v16 = byte_10653B4 == 0;
            }
            else
            {
              v4 = *(a1 + 584) - *(a2 + 584);
              v16 = byte_10653B4 == 0;
            }
            goto LABEL_419;
          case 3:
          case 4:
            if ( *(a1 + 644) == -1 )
              goto LABEL_389;
            v117 = v107 - 3;
            if ( v117 )
            {
              if ( v117 != 1 )
                goto LABEL_391;
LABEL_389:
              v118 = _wcsicmp((a1 + 52), (a2 + 52));
            }
            else
            {
              v119 = *(a2 + 648);
              if ( !v119 || (v120 = *(a1 + 648)) == 0 )
              {
                v4 = (*(a1 + 648) - v119) >> 1;
                v16 = byte_10653B4 == 0;
                goto LABEL_419;
              }
              v118 = _wcsicmp(v120, *(a2 + 648));
            }
            v4 = v118;
            goto LABEL_391;
          default:
LABEL_391:
            v16 = byte_10653B4 == 0;
            goto LABEL_419;
        }
      }
      if ( v5 != 1192 )
        return v4;
      switch ( a3[1] )
      {
        case 0:
          v4 = *(a1 + 40) - *(a2 + 40);
          if ( *(a1 + 40) == *(a2 + 40) )
          {
            v121 = ntohl(*(a2 + 44));
            v122 = ntohl(*(v140 + 11));
            v4 = v122 - v121;
            if ( v122 == v121 )
            {
              v123 = ntohs(*(a2 + 584));
              v124 = ntohs(v140[292]);
              v4 = v124 - v123;
              if ( v124 == v123 )
              {
                v125 = ntohl(*(a2 + 1108));
                v126 = ntohl(v140[554]);
                v4 = v126 - v125;
                if ( v126 == v125 )
                {
                  v127 = ntohs(*(a2 + 1648));
                  v128 = ntohs(v140[824]);
                  v4 = v128 - v127;
                  if ( v128 == v127 )
                    v4 = *(v140 + 543) - *(a2 + 2172);
                }
              }
            }
          }
          break;
        case 1:
          v129 = *(a1 + 40);
          v130 = *(a2 + 40);
          if ( v129 == v130 )
          {
            if ( *(a2 + 44) == *(a1 + 44) )
            {
              v131 = ntohs(*(a2 + 584));
              v4 = ntohs(v140[292]) - v131;
            }
            else
            {
              v132 = ntohl(*(a2 + 44));
              v4 = ntohl(*(v140 + 11)) - v132;
            }
          }
          else
          {
            v4 = v130 - v129;
          }
          break;
        case 2:
          v133 = *(a1 + 40);
          v134 = *(a2 + 40);
          if ( v133 == v134 )
          {
            if ( *(a2 + 1108) != *(a1 + 1108) )
            {
              v136 = ntohl(*(a2 + 1108));
              goto LABEL_414;
            }
            v135 = ntohs(*(a2 + 1648));
            v4 = ntohs(v140[824]) - v135;
          }
          else
          {
            v4 = v134 - v133;
          }
          break;
        case 3:
          v4 = *(a1 + 2172) - *(a2 + 2172);
          if ( *(a1 + 2172) == *(a2 + 2172) )
          {
            v136 = ntohl(*(a2 + 1108));
LABEL_414:
            v4 = ntohl(*(v140 + 277)) - v136;
          }
          break;
        case 4:
          v4 = _wcsicmp(*(a1 + 2184), *(a2 + 2184));
          break;
        default:
          break;
      }
      v16 = byte_105D225 == 0;
LABEL_419:
      if ( v16 )
        v4 = -v4;
      return v4;
    }
    v105 = a3[1];
    if ( v105 )
    {
      if ( v105 != 1 )
      {
LABEL_358:
        v16 = byte_105D224 == 0;
        goto LABEL_419;
      }
      v106 = _wcsicmp(*(a1 + 48), *(a2 + 48));
    }
    else
    {
      v106 = _wcsicmp(*(a1 + 40), *(a2 + 40));
    }
    v4 = v106;
    goto LABEL_358;
  }
  if ( !gConfig.bShowProcessTree )
  {
    v13 = gConfig.dwProcessColumnMap[a3[1]];
    if ( v13 <= 1032 )
    {
      if ( v13 != 1032 )
      {
        switch ( v13 )
        {
          case 3:
            v4 = lstrcmpiW(*(a1 + 60), *(a2 + 60));
            goto LABEL_253;
          case 4:
            goto LABEL_189;
          case 5:
            v4 = *(a1 + 1368) - *(a2 + 1368);
            goto LABEL_253;
          case 7:
            v14 = *(a1 + 1304);
            v15 = *(a2 + 1304);
            if ( v14 <= v15 )
              goto LABEL_25;
            v16 = gConfig.bProcessSortDirection == 0;
            v4 = 1;
            goto LABEL_419;
          case 9:
            v4 = sub_FC37B0(*(a1 + 920), *(a2 + 920));
            goto LABEL_253;
          case 10:
            v4 = sub_FC37B0(*(a1 + 924), *(a2 + 924));
            goto LABEL_253;
          case 18:
            v4 = *(a1 + 92) - *(a2 + 92);
            goto LABEL_253;
          case 19:
            v4 = lstrcmpiW(*(a1 + 88), *(a2 + 88));
            goto LABEL_253;
          case 25:
            v4 = lstrcmpiW((a1 + 654), (a2 + 654));
            goto LABEL_253;
          case 35:
            v4 = lstrcmpiW((a1 + 104), (a2 + 104));
            goto LABEL_253;
          case 38:
            v4 = lstrcmpiW(*(a1 + 784), *(a2 + 784));
            goto LABEL_253;
          default:
            goto LABEL_26;
        }
        goto LABEL_26;
      }
      v4 = lstrcmpiW(*(a1 + 800), *(a2 + 800));
      goto LABEL_253;
    }
    if ( v13 > 1317 )
    {
      if ( v13 > 1609 )
      {
        if ( v13 > 40757 )
          goto LABEL_26;
        if ( v13 != 40757 )
        {
          switch ( v13 )
          {
            case 1610:
              v4 = *(a1 + 1088) - *(a2 + 1088);
              goto LABEL_253;
            case 1611:
              v4 = *(a1 + 1104) - *(a2 + 1104);
              goto LABEL_253;
            case 1612:
              v4 = *(a1 + 1120) - *(a2 + 1120);
              goto LABEL_253;
            case 1613:
              v4 = *(a1 + 1136) - *(a2 + 1136);
              goto LABEL_253;
            case 1614:
              v4 = *(a1 + 1152) - *(a2 + 1152);
              goto LABEL_253;
            case 1615:
              v4 = sub_FC37B0(*(a1 + 1096) + *(a1 + 1128), *(a2 + 1096) + *(a2 + 1128));
              goto LABEL_253;
            case 1616:
              v4 = sub_FC37B0(*(a1 + 1096), *(a2 + 1096));
              goto LABEL_253;
            case 1617:
              v4 = sub_FC37B0(*(a1 + 1080), *(a2 + 1080));
              goto LABEL_253;
            case 1618:
              v4 = sub_FC37B0(*(a1 + 1112), *(a2 + 1112));
              goto LABEL_253;
            case 1619:
              v4 = sub_FC37B0(*(a1 + 1128), *(a2 + 1128));
              goto LABEL_253;
            case 1620:
              v4 = sub_FC37B0(*(a1 + 1144), *(a2 + 1144));
              goto LABEL_253;
            case 1621:
              v4 = sub_FC37B0(*(a1 + 1160), *(a2 + 1160));
              goto LABEL_253;
            case 1622:
              v4 = sub_FC37B0(*(a1 + 1168), *(a2 + 1168));
              goto LABEL_253;
            case 1623:
              v4 = *(a1 + 1176) - *(a2 + 1176);
              goto LABEL_253;
            case 1624:
              v4 = *(a1 + 1192) - *(a2 + 1192);
              goto LABEL_253;
            case 1625:
              v4 = *(a1 + 1208) - *(a2 + 1208);
              goto LABEL_253;
            case 1626:
              v4 = *(a1 + 1224) - *(a2 + 1224);
              goto LABEL_253;
            case 1627:
              v4 = *(a1 + 1240) - *(a2 + 1240);
              goto LABEL_253;
            case 1628:
              v4 = *(a1 + 1256) - *(a2 + 1256);
              goto LABEL_253;
            case 1629:
              v4 = sub_FC37B0(*(a1 + 1200) + *(a1 + 1232), *(a2 + 1200) + *(a2 + 1232));
              goto LABEL_253;
            case 1630:
              v4 = sub_FC37B0(*(a1 + 1184), *(a2 + 1184));
              goto LABEL_253;
            case 1631:
              v4 = sub_FC37B0(*(a1 + 1200), *(a2 + 1200));
              goto LABEL_253;
            case 1632:
              v4 = sub_FC37B0(*(a1 + 1216), *(a2 + 1216));
              goto LABEL_253;
            case 1633:
              v4 = sub_FC37B0(*(a1 + 1232), *(a2 + 1232));
              goto LABEL_253;
            case 1634:
              v4 = sub_FC37B0(*(a1 + 1248), *(a2 + 1248));
              goto LABEL_253;
            case 1635:
              v4 = sub_FC37B0(*(a1 + 1264), *(a2 + 1264));
              goto LABEL_253;
            case 1636:
              v4 = sub_FC37B0(*(a1 + 1272), *(a2 + 1272));
              goto LABEL_253;
            case 1637:
              v14 = *(a1 + 1312);
              v15 = *(a2 + 1312);
              if ( v14 <= v15 )
                goto LABEL_25;
              v16 = gConfig.bProcessSortDirection == 0;
              v4 = 1;
              goto LABEL_419;
            case 1638:
LABEL_189:
              v49 = *(a1 + 68);
              v50 = *(a2 + 68);
              if ( v49 < 0 )
                v49 = 0;
              if ( v50 < 0 )
                v50 = 0;
              v51 = (v50 & 0xFFFFFFF);
              v52 = (v49 & 0xFFFFFFF);
              goto LABEL_194;
            case 1650:
              v14 = *(a1 + 1384);
              v15 = *(a2 + 1384);
              if ( v14 <= v15 )
                goto LABEL_25;
              v16 = gConfig.bProcessSortDirection == 0;
              v4 = 1;
              goto LABEL_419;
            case 1651:
              v4 = sub_FC37B0(*(a1 + 1408), *(a2 + 1408));
              goto LABEL_253;
            case 1652:
              v4 = sub_FC37B0(*(a1 + 1424), *(a2 + 1424));
              goto LABEL_253;
            case 1653:
              v4 = sub_FC37B0(*(a1 + 1440), *(a2 + 1440));
              goto LABEL_253;
            case 1654:
              v4 = lstrcmpiW(*(a1 + 824), *(a2 + 824));
              goto LABEL_253;
            case 1655:
LABEL_218:
              v4 = sub_FB4EF0((a1 + 624), (a2 + 624));
              goto LABEL_253;
            case 1656:
              v4 = lstrcmpiW(*(a1 + 828), *(a2 + 828));
              goto LABEL_253;
            case 1667:
              v4 = *(a2 + 644) - *(a1 + 644);
              goto LABEL_253;
            case 1670:
              v53 = *(a1 + 844);
              if ( v53 && (v54 = *(a2 + 844)) != 0 )
              {
                v55 = *(v53 + 4);
                if ( v55 != 1 || *(v54 + 4) != 1 )
                {
                  v4 = v55 - *(v54 + 4);
                }
                else
                {
                  lpString1 = *(v53 + 4);
                  v140 = 1;
                  v138 = -1;
                  v137 = -1;
                  v56 = *(v53 + 40);
                  if ( v56 )
                    v57 = *v56;
                  else
                    v57 = 0;
                  scan_fn(v57, L"%d/%d", &lpString1);
                  v58 = *(*(a2 + 844) + 40);
                  if ( v58 )
                    v59 = *v58;
                  else
                    v59 = 0;
                  scan_fn(v59, L"%d/%d", &v140);
                  v52 = lpString1;
                  v51 = v140;
                  if ( lpString1 == v140 )
                    v4 = v138 - v137;
                  else
LABEL_194:
                    v4 = v52 - v51;
                }
              }
              else
              {
                v4 = sub_FC37B0(v53, *(a2 + 844));
              }
              goto LABEL_253;
            case 1673:
              v4 = *(a1 + 649) - *(a2 + 649);
              goto LABEL_253;
            case 1674:
              v4 = ((*(a1 + 40) >> 13) & 1) - ((*(a2 + 40) >> 13) & 1);
              goto LABEL_253;
            default:
              goto LABEL_26;
          }
          goto LABEL_26;
        }
        v42 = *(a1 + 650);
        v43 = *(a2 + 650);
        v44 = *(a1 + 650) & 0x4000;
        v45 = *(a2 + 650) & 0x4000;
LABEL_250:
        v4 = v44 - v45;
        if ( v4 )
          goto LABEL_27;
        if ( !v42 )
          goto LABEL_26;
        LOBYTE(v4) = v43 == 0;
      }
      else
      {
        if ( v13 != 1609 )
        {
          switch ( v13 )
          {
            case 1326:
              v4 = *(a1 + 976) - *(a2 + 976);
              goto LABEL_253;
            case 1327:
              v4 = sub_FC37B0(*(a1 + 984), *(a2 + 984));
              goto LABEL_253;
            case 1328:
              v4 = *(a1 + 1008) - *(a2 + 1008);
              goto LABEL_253;
            case 1329:
              v4 = sub_FC37B0(*(a1 + 1016), *(a2 + 1016));
              goto LABEL_253;
            case 1330:
              v4 = sub_FC37B0(*(a1 + 984) + *(a1 + 1016), *(a2 + 984) + *(a2 + 1016));
              goto LABEL_253;
            case 1332:
              v4 = sub_FC37B0(*(a1 + 1048), *(a2 + 1048));
              goto LABEL_253;
            case 1333:
              v4 = sub_FC37B0(*(a1 + 1056), *(a2 + 1056));
              goto LABEL_253;
            case 1335:
              v4 = *(a1 + 1040) - *(a2 + 1040);
              goto LABEL_253;
            case 1336:
LABEL_151:
              v4 = -1;
              if ( gConfig.dwProcessColumnMap[a3[1]] == 1336 )
              {
                v46 = *(a1 + 816);
                v140 = *(a2 + 816);
              }
              else
              {
                v46 = *(a1 + 820);
                v140 = *(a2 + 820);
              }
              v47 = lstrcmpW;
              lpString1 = v46;
              if ( v46 )
              {
                if ( lstrcmpW(v46, L"Low") )
                {
                  if ( lstrcmpW(lpString1, L"Medium") )
                  {
                    if ( lstrcmpW(lpString1, L"High") )
                    {
                      if ( !lstrcmpW(lpString1, L"System") )
                        v4 = 3;
                    }
                    else
                    {
                      v4 = 2;
                    }
                  }
                  else
                  {
                    v4 = 1;
                  }
                }
                else
                {
                  v4 = 0;
                }
                v47 = lstrcmpW;
              }
              else
              {
                v4 = -2;
              }
              if ( v140 )
              {
                if ( v47(v140, L"Low") )
                {
                  if ( lstrcmpW(v140, L"Medium") )
                  {
                    if ( lstrcmpW(v140, L"High") )
                    {
                      v16 = lstrcmpW(v140, L"System") == 0;
                      v48 = -1;
                      if ( v16 )
                        v48 = 3;
                      v4 -= v48;
                    }
                    else
                    {
                      v4 -= 2;
                    }
                  }
                  else
                  {
                    --v4;
                  }
                }
              }
              else
              {
                v4 += 2;
              }
              goto LABEL_253;
            case 1337:
              v4 = ((*(a1 + 40) >> 9) & 1) - ((*(a2 + 40) >> 9) & 1);
              goto LABEL_253;
            case 1338:
              v42 = *(a1 + 650);
              v43 = *(a2 + 650);
              v44 = *(a1 + 650) & 0x40;
              v45 = *(a2 + 650) & 0x40;
              goto LABEL_250;
            case 1339:
              v4 = *(a1 + 872) - *(a2 + 872);
              goto LABEL_253;
            case 1340:
              v4 = *(a1 + 952) - *(a2 + 952);
              goto LABEL_253;
            case 1341:
              v4 = sub_FC37B0(*(a1 + 912), *(a2 + 912));
              goto LABEL_253;
            case 1342:
              v4 = sub_FC37B0(*(a1 + 916), *(a2 + 916));
              goto LABEL_253;
            default:
              goto LABEL_26;
          }
          goto LABEL_26;
        }
        v4 = *(a1 + 1072) - *(a2 + 1072);
      }
    }
    else
    {
      if ( v13 != 1317 )
      {
        switch ( v13 )
        {
          case 1033:
            v4 = lstrcmpiW(*(a1 + 788), *(a2 + 788));
            goto LABEL_253;
          case 1055:
          case 1191:
            v14 = *(a1 + 1296);
            if ( v14 != 0.0 || v14 != *(a2 + 1296) )
            {
              v15 = *(a2 + 1296);
              if ( v14 > v15 )
              {
                v16 = gConfig.bProcessSortDirection == 0;
                v4 = 1;
                goto LABEL_419;
              }
LABEL_25:
              if ( v15 <= v14 )
                goto LABEL_254;
            }
            else
            {
              v17 = *(a1 + 1356);
              v18 = *(a2 + 1356);
              v19 = *(a1 + 1352);
              v20 = *(a2 + 1352);
              if ( v17 < v18 )
                break;
              if ( v17 > v18 || v19 > v20 )
                goto LABEL_45;
              if ( v17 > v18 || v17 >= v18 && v19 >= v20 )
              {
                v21 = *(a1 + 1340);
                v22 = *(a2 + 1340);
                v23 = *(a1 + 1336);
                v24 = *(a2 + 1336);
                if ( v21 >= v22 )
                {
                  if ( v21 > v22 )
                  {
LABEL_45:
                    v16 = gConfig.bProcessSortDirection == 0;
                    v4 = 1;
                    goto LABEL_419;
                  }
                  if ( v23 > v24 )
                  {
                    v16 = gConfig.bProcessSortDirection == 0;
                    v4 = 1;
                    goto LABEL_419;
                  }
                  if ( v21 > v22 )
                    goto LABEL_254;
                  if ( v21 >= v22 )
                  {
                    if ( v23 < v24 )
                    {
                      v4 = -1;
                      v16 = gConfig.bProcessSortDirection == 0;
                      goto LABEL_419;
                    }
                    goto LABEL_254;
                  }
                }
              }
            }
            break;
          case 1056:
            v4 = *(a1 + 100) - *(a2 + 100);
            goto LABEL_253;
          case 1059:
            v4 = sub_FC37B0(*(a1 + 880), *(a2 + 880));
            goto LABEL_253;
          case 1060:
          case 1193:
            v4 = sub_FC37B0(*(a1 + 888), *(a2 + 888));
            goto LABEL_253;
          case 1061:
            v4 = lstrcmpiW(*(a1 + 792), *(a2 + 792));
            goto LABEL_253;
          case 1062:
            v4 = sub_FC37B0(*(a1 + 896), *(a2 + 896));
            goto LABEL_253;
          case 1063:
            v4 = sub_FC37B0(*(a1 + 900), *(a2 + 900));
            goto LABEL_253;
          case 1064:
            v4 = sub_FC37B0(*(a1 + 904), *(a2 + 904));
            goto LABEL_253;
          case 1065:
            v4 = *(a1 + 96) - *(a2 + 96);
            goto LABEL_253;
          case 1066:
            v4 = *(a1 + 1380) - *(a2 + 1380);
            goto LABEL_253;
          case 1067:
            v4 = *(a1 + 1376) - *(a2 + 1376);
            goto LABEL_253;
          case 1068:
            v4 = *(a1 + 960) - *(a2 + 960);
            goto LABEL_253;
          case 1069:
            v4 = sub_FC37B0(*(a1 + 968), *(a2 + 968));
            goto LABEL_253;
          case 1070:
            v4 = *(a1 + 992) - *(a2 + 992);
            goto LABEL_253;
          case 1071:
            v4 = sub_FC37B0(*(a1 + 1000), *(a2 + 1000));
            goto LABEL_253;
          case 1072:
            v4 = *(a1 + 1024) - *(a2 + 1024);
            goto LABEL_253;
          case 1073:
            v4 = sub_FC37B0(*(a1 + 1032), *(a2 + 1032));
            goto LABEL_253;
          case 1086:
            goto LABEL_218;
          case 1087:
            v4 = sub_FB4EF0((a1 + 1320), (a2 + 1320));
            goto LABEL_253;
          case 1091:
            v4 = sub_FC37B0(*(a1 + 1344), *(a2 + 1344));
            goto LABEL_253;
          case 1092:
            v4 = sub_FC37B0(*(a1 + 1336), *(a2 + 1336));
            goto LABEL_253;
          case 1094:
            v25 = *(a1 + 1284);
            if ( !v25 )
              goto LABEL_97;
            v26 = *(a2 + 1284);
            if ( !v26 )
              goto LABEL_95;
            v4 = *v25 - *v26;
            goto LABEL_253;
          case 1095:
            v25 = *(a1 + 1284);
            if ( !v25 )
              goto LABEL_97;
            v27 = *(a2 + 1284);
            if ( !v27 )
              goto LABEL_95;
            v4 = (*(v25 + 8) - *(v27 + 8));
            goto LABEL_253;
          case 1096:
            v25 = *(a1 + 1284);
            if ( !v25 )
              goto LABEL_97;
            v28 = *(a2 + 1284);
            if ( !v28 )
              goto LABEL_95;
            v4 = *(v25 + 16) - *(v28 + 16);
            goto LABEL_253;
          case 1097:
            v25 = *(a1 + 1284);
            if ( !v25 )
              goto LABEL_97;
            v29 = *(a2 + 1284);
            if ( !v29 )
              goto LABEL_95;
            v4 = *(v25 + 48) - *(v29 + 48);
            goto LABEL_253;
          case 1098:
            v25 = *(a1 + 1284);
            if ( !v25 )
              goto LABEL_97;
            v30 = *(a2 + 1284);
            if ( !v30 )
              goto LABEL_95;
            v4 = *(v25 + 32) - *(v30 + 32);
            goto LABEL_253;
          case 1099:
            v25 = *(a1 + 1284);
            if ( !v25 )
              goto LABEL_97;
            v31 = *(a2 + 1284);
            if ( !v31 )
              goto LABEL_95;
            v4 = *(v25 + 24) - *(v31 + 24);
            goto LABEL_253;
          case 1100:
            v25 = *(a1 + 1284);
            if ( !v25 )
              goto LABEL_97;
            v32 = *(a2 + 1284);
            if ( !v32 )
              goto LABEL_95;
            v4 = *(v25 + 56) - *(v32 + 56);
            goto LABEL_253;
          case 1101:
            v25 = *(a1 + 1284);
            if ( !v25 )
              goto LABEL_97;
            v33 = *(a2 + 1284);
            if ( !v33 )
              goto LABEL_95;
            v4 = *(v25 + 40) - *(v33 + 40);
            goto LABEL_253;
          case 1103:
            v25 = *(a1 + 1284);
            if ( !v25 )
              goto LABEL_97;
            v35 = *(a2 + 1284);
            if ( !v35 )
              goto LABEL_95;
            v4 = *(v25 + 112) - *(v35 + 112);
            goto LABEL_253;
          case 1104:
            v25 = *(a1 + 1284);
            if ( !v25 )
              goto LABEL_97;
            v36 = *(a2 + 1284);
            if ( !v36 )
              goto LABEL_95;
            v4 = *(v25 + 64) - *(v36 + 64);
            goto LABEL_253;
          case 1105:
            v25 = *(a1 + 1284);
            if ( !v25 )
              goto LABEL_97;
            v37 = *(a2 + 1284);
            if ( !v37 )
              goto LABEL_95;
            v4 = *(v25 + 72) - *(v37 + 72);
            goto LABEL_253;
          case 1106:
            v25 = *(a1 + 1284);
            if ( !v25 )
              goto LABEL_97;
            v38 = *(a2 + 1284);
            if ( !v38 )
              goto LABEL_95;
            v4 = *(v25 + 80) - *(v38 + 80);
            goto LABEL_253;
          case 1107:
            v25 = *(a1 + 1284);
            if ( !v25 )
              goto LABEL_97;
            v39 = *(a2 + 1284);
            if ( !v39 )
              goto LABEL_95;
            v4 = (*(v25 + 88) - *(v39 + 88));
            goto LABEL_253;
          case 1108:
            v25 = *(a1 + 1284);
            if ( !v25 )
              goto LABEL_97;
            v40 = *(a2 + 1284);
            if ( !v40 )
              goto LABEL_95;
            v4 = *(v25 + 104) - *(v40 + 104);
            goto LABEL_253;
          case 1109:
            v25 = *(a1 + 1284);
            if ( !v25 )
              goto LABEL_97;
            v41 = *(a2 + 1284);
            if ( !v41 )
              goto LABEL_95;
            v4 = *(v25 + 120) - *(v41 + 120);
            goto LABEL_253;
          case 1110:
            v25 = *(a1 + 1284);
            if ( !v25 )
              goto LABEL_97;
            v34 = *(a2 + 1284);
            if ( v34 )
            {
              v4 = *(v25 + 128) - *(v34 + 128);
            }
            else
            {
LABEL_95:
              if ( v25 )
              {
                v16 = gConfig.bProcessSortDirection == 0;
                v4 = 1;
                goto LABEL_419;
              }
LABEL_97:
              v4 = -(*(a2 + 1284) != 0);
            }
            goto LABEL_253;
          case 1114:
            v4 = sub_FC37B0(*(a1 + 876), *(a2 + 876));
            goto LABEL_253;
          case 1115:
            v4 = sub_FC37B0(*(a1 + 936), *(a2 + 936));
            goto LABEL_253;
          case 1116:
            v4 = sub_FC37B0(*(a1 + 940), *(a2 + 940));
            goto LABEL_253;
          case 1118:
            v4 = sub_FC37B0(*(a1 + 948), *(a2 + 948));
            goto LABEL_253;
          case 1179:
            v4 = sub_FC37B0(*(a1 + 884), *(a2 + 884));
            goto LABEL_253;
          case 1180:
            goto LABEL_151;
          case 1181:
            v4 = lstrcmpiW(*(a1 + 796), *(a2 + 796));
            goto LABEL_253;
          case 1187:
            v4 = lstrcmpiW(*(a1 + 836), *(a2 + 836));
            goto LABEL_253;
          case 1192:
            v4 = *(a1 + 892) - *(a2 + 892);
            goto LABEL_253;
          case 1195:
            v4 = sub_FC37B0(*(a1 + 1360), *(a2 + 1360));
            goto LABEL_253;
          case 1196:
            v4 = *(a1 + 620) - *(a2 + 620);
            if ( *(a1 + 620) != *(a2 + 620) )
              goto LABEL_27;
            v4 = (*(a1 + 616) - *(a2 + 616)) >> 2;
            goto LABEL_253;
          case 1199:
            v4 = *(a1 + 636) - *(a2 + 636);
            goto LABEL_253;
          case 1200:
            v4 = sub_FC37B0(*(a1 + 1352), *(a2 + 1352));
            goto LABEL_253;
          default:
            break;
        }
LABEL_26:
        v4 = -1;
LABEL_27:
        v16 = gConfig.bProcessSortDirection == 0;
        goto LABEL_419;
      }
      v4 = sub_FC37B0(*(a1 + 944), *(a2 + 944));
    }
LABEL_253:
    if ( v4 )
      goto LABEL_27;
LABEL_254:
    v60 = lstrcmpiW(*(a1 + 60), *(a2 + 60));
    v16 = gConfig.bProcessSortDirection == 0;
    v4 = v60;
    goto LABEL_419;
  }
  v7 = *(a2 + 84);
  v8 = *(a1 + 80);
  v9 = *(a2 + 80);
  v10 = *(a1 + 84);
  if ( v7 == a1 )
    return -1;
  while ( 1 )
  {
    if ( v10 == v6 )
      return 1;
    v11 = v8 < v9;
    if ( v8 == v9 )
      break;
LABEL_9:
    if ( v11 )
      goto LABEL_13;
    v3 = v10;
    if ( v8 <= v9 )
    {
      --v8;
LABEL_13:
      v6 = v7;
      --v9;
      goto LABEL_14;
    }
    --v8;
LABEL_14:
    v7 = v6[21];
    v10 = v3[21];
    if ( v7 == v3 )
      return -1;
  }
  if ( v8 && v10 != v7 )
  {
    v11 = v8 < v9;
    goto LABEL_9;
  }
  result = sub_FB4EF0(v3 + 156, v6 + 156);
  if ( !result )
    result = v3[17] - v6[17];
  return result;
}
// 1032BB0: using guessed type wchar_t aDD[6];
// 105D224: using guessed type char byte_105D224;
// 105D225: using guessed type char byte_105D225;
// 10653B4: using guessed type char byte_10653B4;

//----- (00FBCB80) --------------------------------------------------------
int __stdcall CTreeView::InitListHeader(HWND hWnd, UINT *pnIDs, WORD *pnWidths, DWORD dwColumnCount)
{
  HWND (__stdcall *GetParent)(HWND); // ecx
  WPARAM nColumn; // esi
  char v6; // al
  __m128i v7; // xmm1
  UINT *v8; // edx
  unsigned int Index; // ecx
  unsigned int v10; // eax
  __m128i v11; // xmm0
  tagLVCOLUMNW ColumnInfo; // [esp+0h] [ebp-22Ch]
  WORD *pnWidths_1; // [esp+20h] [ebp-20Ch]
  signed int *pnIDs_1; // [esp+24h] [ebp-208h]
  UINT arrIDS[96]; // [esp+28h] [ebp-204h]
  WCHAR szText[64]; // [esp+1A8h] [ebp-84h]

  pnIDs_1 = pnIDs;
  pnWidths_1 = pnWidths;
  ColumnInfo.mask = 0;
  _mm_storeu_si128(&ColumnInfo.fmt, 0i64);
  ColumnInfo.iOrder = 0;
  *&ColumnInfo.iSubItem = 0i64;
  while ( SendMessageW(hWnd, LVM_DELETECOLUMN, 0, 0) )
    ;
  GetParent = ::GetParent;
  nColumn = 0;
  // LVCF_FMT | LVCF_TEXT |  LVCF_WIDTH | LVCF_SUBITEM;
  ColumnInfo.mask = 0xF;
  ColumnInfo.pszText = szText;
  if ( dwColumnCount )
  {
    while ( 1 )
    {
      ColumnInfo.iSubItem = nColumn;
      ColumnInfo.cx = abs(pnWidths_1[nColumn]);
      if ( GetParent(hWnd) != ghMainWnd )
        break;
      if ( (pnWidths_1[nColumn] & 0x8000u) != 0 )
        goto LABEL_9;
      v6 = IsStringID(pnIDs_1[nColumn]);
      ColumnInfo.fmt = 0;
      if ( v6 )
        goto LABEL_9;
LABEL_10:
      LoadStringW(ghInstance, pnIDs_1[nColumn], szText, 64);
      if ( SendMessageW(hWnd, LVM_INSERTCOLUMNW, nColumn, &ColumnInfo) == -1 )
        return 0;
      GetParent = ::GetParent;
      if ( ++nColumn >= dwColumnCount )
        goto __Break;
    }
    if ( (pnWidths_1[nColumn] & 0x8000u) == 0 )
    {
      ColumnInfo.fmt = 0;
      goto LABEL_10;
    }
LABEL_9:
    ColumnInfo.fmt = LVCF_FMT;
    goto LABEL_10;
  }
__Break:
  if ( GetParent(hWnd) == ghMainWnd && IsStringID(*pnIDs_1) )
  {
    ColumnInfo.mask = 1;
    SendMessageW(hWnd, LVM_GETCOLUMNW, 0, &ColumnInfo);
    ColumnInfo.fmt |= 1u;
    ColumnInfo.mask = 1;
    SendMessageW(hWnd, LVM_SETCOLUMNW, 0, &ColumnInfo);
  }
  SetWindowLongW(hWnd, GWLP_USERDATA, dwColumnCount);
  v7 = _mm_load_si128(&gIntArray);
  v8 = &arrIDS[4];
  Index = 0;
  do
  {
    v10 = Index + 4;
    v8 += 8;
    v11 = _mm_add_epi32(_mm_shuffle_epi32(_mm_cvtsi32_si128(Index), 0), v7);
    Index += 8;
    _mm_storeu_si128(v8 - 3, v11);
    _mm_storeu_si128(v8 - 2, _mm_add_epi32(_mm_shuffle_epi32(_mm_cvtsi32_si128(v10), 0), v7));
  }
  while ( Index < 96 );
  SendMessageW(hWnd, LVM_SETCOLUMNORDERARRAY, dwColumnCount, arrIDS);
  InvalidateRect(hWnd, 0, 1);
  return 1;
}
// 103EA50: using guessed type RECT gIntArray;

//----- (00FBCDD0) --------------------------------------------------------
int __cdecl sub_FBCDD0(int a1, int a2)
{
  HWND v2; // edi
  tagTREEVIEWITEMPARAM *v3; // esi
  int v4; // eax
  int v5; // ecx
  int v6; // ecx
  int v7; // eax
  const WCHAR **v9; // eax
  const WCHAR *v10; // eax
  const WCHAR **v11; // eax
  const WCHAR *v12; // eax
  tagTREEVIEWLISTITEMPARAM *v13; // [esp-8h] [ebp-88h]
  LVITEMW item; // [esp+8h] [ebp-78h]
  struct tagPOINT Point; // [esp+3Ch] [ebp-44h]
  LVHITTESTINFO SubHitTestInfo; // [esp+44h] [ebp-3Ch]
  LVHITTESTINFO HitTestInfo; // [esp+58h] [ebp-28h]
  RECT lParam_1; // [esp+6Ch] [ebp-14h]

  HitTestInfo.pt.x = 0;
  _mm_storeu_si128(&HitTestInfo.pt.y, 0i64);
  item.mask = 0;
  memset(&item.iItem, 0, 0x30u);
  Point.x = 0;
  Point.y = 0;
  if ( a1 == 101 )
  {
    v2 = ghWndTreeListView;
  }
  else
  {
    if ( a1 != 104 )
      return 0;
    v2 = ghWndDllsListCtrl;
  }
  GetCursorPos(&Point);
  ScreenToClient(v2, &Point);
  HitTestInfo.pt = Point;
  item.iItem = SendMessageW(v2, LVM_HITTEST, 0, &HitTestInfo);
  item.iSubItem = 0;
  item.mask = 4;
  if ( SendMessageW(v2, LVM_GETITEMW, 0, &item) != 1 )
    return 0;
  sub_FBA880(v2, item.iItem, HitTestInfo.iSubItem, &lParam_1);
  v3 = item.lParam;
  if ( v2 != ghWndTreeListView )
  {
    SubHitTestInfo.pt.x = *(a2 + 32);
    SubHitTestInfo.pt.y = *(a2 + 36);
    SendMessageW(v2, LVM_SUBITEMHITTEST, 0, &SubHitTestInfo);
    if ( gConfig.dwDllColumnMap[SubHitTestInfo.iSubItem] == IDS_VIRUSTOTAL && sub_1001820(v3[4].field_1C) )
    {
      v11 = *(v3[4].field_1C + 36);
      if ( v11 )
        v12 = *v11;
      else
        v12 = 0;
      LaunchWebBrowser(v2, 0, v12);
    }
    return 0;
  }
  v4 = gConfig.dwProcessColumnMap[HitTestInfo.iSubItem];
  if ( v4 != 3 )
  {
    if ( v4 == 1670 && sub_1001820(item.lParam[10].field_4) )
    {
      v9 = *(v3[10].field_4 + 36);
      if ( v9 )
        v10 = *v9;
      else
        v10 = 0;
      LaunchWebBrowser(v2, 0, v10);
    }
    goto LABEL_24;
  }
  if ( !item.lParam->field_30
    || (!gConfig.bShowProcessTree ? (v5 = 0) : (v5 = item.lParam->field_50),
        (v6 = lParam_1.left + 16 * v5, HitTestInfo.pt.x <= v6 + 1) || HitTestInfo.pt.x >= v6 + 17) )
  {
LABEL_24:
    RefreshMenuWithTreeViewItemStatus(v3);
    RefreshVirusTotalMenuItem(v3);
    return 0;
  }
  v7 = item.lParam->field_28;
  if ( v7 & 4 )
  {
    v13 = item.lParam;
    item.lParam->field_28 = v7 & 0xFFFFFFFB;
  }
  else
  {
    v13 = item.lParam;
    item.lParam->field_28 = v7 | 4;
  }
  sub_FB8DA0(v13);
  RefreshMenuWithTreeViewItemStatus(v3);
  RefreshVirusTotalMenuItem(v3);
  return 0;
}

//----- (00FBD040) --------------------------------------------------------
int __cdecl sub_FBD040(WPARAM uTabID, int pThis)
{
  HWND *pThis_1; // ebx
  void (__stdcall *SendMessageW)(HWND, UINT, WPARAM, LPARAM); // esi
  int v4; // eax
  tagTREEVIEWITEMPARAM *v5; // edi
  bool v6; // al
  HMENU v7; // eax
  void *v8; // eax
  signed int v9; // edi
  signed int v10; // ebx
  DWORD v11; // ST04_4
  HMENU v12; // eax
  BOOL v13; // ST0C_4
  HMENU v14; // eax
  int v15; // edi
  HWND v16; // ST00_4
  int v17; // edi
  int v18; // esi
  int v19; // eax
  DWORD v20; // edx
  char v21; // al
  HWND v22; // ecx
  LRESULT v23; // eax
  HWND v24; // ST00_4
  HWND v25; // ST00_4
  LPARAM v27; // [esp+Ch] [ebp-94h]
  tagTREEVIEWITEMPARAM *v28; // [esp+14h] [ebp-8Ch]
  tagLVITEMW item; // [esp+24h] [ebp-7Ch]
  LPARAM v30; // [esp+58h] [ebp-48h]
  int v31; // [esp+5Ch] [ebp-44h]
  int v32; // [esp+60h] [ebp-40h]
  int v33; // [esp+64h] [ebp-3Ch]
  int v34; // [esp+68h] [ebp-38h]
  LPARAM lParam; // [esp+6Ch] [ebp-34h]
  int v36; // [esp+70h] [ebp-30h]
  int v37; // [esp+78h] [ebp-28h]
  WPARAM wParam; // [esp+8Ch] [ebp-14h]
  int v39; // [esp+90h] [ebp-10h]
  tagTREEVIEWITEMPARAM *v40; // [esp+94h] [ebp-Ch]
  void *i; // [esp+98h] [ebp-8h]
  LRESULT pThis_2; // [esp+9Ch] [ebp-4h]

  pThis_1 = pThis;
  SendMessageW = ::SendMessageW;
  v4 = *(pThis + 16);
  v5 = 0;
  pThis_2 = pThis;
  v40 = 0;
  wParam = uTabID;
  v39 = v4;
  if ( uTabID == IDC_TREEVIEW_LIST )
  {
    item.iItem = ::SendMessageW(ghWndTreeListView, LVM_GETNEXTITEM, 0xFFFFFFFF, 2);
    if ( item.iItem != -1 )
    {
      item.iSubItem = 0;
      item.mask = 4;
      ::SendMessageW(ghWndTreeListView, LVM_GETITEMW, 0, &item);
      v40 = item.lParam;
    }
    v6 = gConfig.bProcessSortDirection;
    if ( gConfig.bShowProcessTree || gConfig.dwProcessColumnMap[*(pThis + 16)] != 3 || gConfig.bProcessSortDirection )
    {
      gConfig.bShowProcessTree = 0;
      if ( gConfig.dwProcessSortColumn == *(pThis + 16) )
      {
        v6 = gConfig.bProcessSortDirection == 0;
        gConfig.bProcessSortDirection = gConfig.bProcessSortDirection == 0;
      }
      v11 = gConfig.dwProcessSortColumn;
      gConfig.dwProcessSortColumn = *(pThis + 16);
      CTreeList::InitHeaderColumn(*pThis, v11, gConfig.dwProcessSortColumn, v6);
      v12 = GetMenu(ghMainWnd);
      EnableMenuItem(v12, 0x9C6Cu, 1u);
      ::SendMessageW(ghWndToolbar, 0x401u, IDM_VIEW_SHOW_PROCESS_TREE, gConfig.bShowProcessTree == 0);
      v13 = gConfig.bShowProcessTree != 0;
      v14 = GetMenu(ghMainWnd);
      EnableMenuItem(v14, IDM_VIEW_SHOW_PROCESS_TREE, v13);
      SendMessageW = ::SendMessageW;
    }
    else
    {
      gConfig.dwProcessSortColumn = *(pThis + 16);
      ::SendMessageW(ghWndToolbar, 0x401u, 0x9C67u, 0);
      v7 = GetMenu(ghMainWnd);
      EnableMenuItem(v7, 0x9C67u, 1u);
      v8 = GetWindowLongW(ghWndTreeListView, -21);
      v9 = 0;
      i = v8;
      if ( v8 > 0 )
      {
        v10 = v8;
        do
        {
          lParam = 1;
          ::SendMessageW(ghWndTreeListView, 0x105Fu, v9, &lParam);
          v36 &= 0xFFFFE7FF;
          lParam = 1;
          ::SendMessageW(ghWndTreeListView, 0x1060u, v9++, &lParam);
        }
        while ( v9 < v10 );
        pThis_1 = pThis_2;
      }
      gConfig.bShowProcessTree = 1;
      sub_FF6020(gpTreeViewListItemParam);
    }
    SendMessageW(*pThis_1, 0xBu, 0, 0);
    pThis_2 = (SendMessageW)(*pThis_1, 0x1004u, 0, 0);
    v15 = 0;
    for ( i = operator new[](4 * pThis_2); v15 < pThis_2; ++v15 )
    {
      v31 = v15;
      v16 = *pThis_1;
      v32 = 0;
      v30 = 4;
      SendMessageW(v16, 0x104Bu, 0, &v30);
      *(i + v15) = v37;
    }
    SendMessageW(*pThis_1, 0x1009u, 0, 0);
    v17 = 0;
    if ( pThis_2 > 0 )
    {
      do
      {
        v18 = *(i + v17);
        v19 = sub_FB7F20(*pThis_1, *(i + v17++));
        *(v18 + 1464) = v19;
      }
      while ( v17 < pThis_2 );
      SendMessageW = ::SendMessageW;
    }
    j_j__free(i);
    v5 = v40;
  }
  else
  {
    switch ( uTabID )
    {
      case IDD_PROCEXPLORER_DIALOG:
        v20 = gConfig.dwHandleSortColumn;
        if ( gConfig.dwHandleSortColumn == v4 )
        {
          v21 = LOBYTE(gConfig.bHandleSortDirection) == 0;
          LOBYTE(gConfig.bHandleSortDirection) = LOBYTE(gConfig.bHandleSortDirection) == 0;
          v22 = *(pThis + 16);
        }
        else
        {
          v22 = *(pThis + 16);
          v21 = gConfig.bHandleSortDirection;
        }
        gConfig.dwHandleSortColumn = *(pThis + 16);
        break;
      case IDC_LISTCTRL_DLLS:
        v20 = gConfig.dwDllSortColumn;
        if ( gConfig.dwDllSortColumn == v4 )
        {
          v21 = LOBYTE(gConfig.bDllSortDirection) == 0;
          LOBYTE(gConfig.bDllSortDirection) = LOBYTE(gConfig.bDllSortDirection) == 0;
          v22 = *(pThis + 16);
        }
        else
        {
          v22 = *(pThis + 16);
          v21 = gConfig.bDllSortDirection;
        }
        gConfig.dwDllSortColumn = *(pThis + 16);
        break;
      case IDC_PAGE_PROCTHREADS_LISTCTRL:
        v20 = ::wParam;
        if ( ::wParam == v4 )
        {
          v21 = byte_10653B4 == 0;
          byte_10653B4 = byte_10653B4 == 0;
          v22 = *(pThis + 16);
        }
        else
        {
          v22 = *(pThis + 16);
          v21 = byte_10653B4;
        }
        ::wParam = *(pThis + 16);
        break;
      case IDC_DLG_HANDLE_INFO_STATIC_UNKNOWN1|IDS_REFRESH_PROCESS_LIST:
        v20 = nItem;
        if ( nItem == v4 )
        {
          v21 = byte_105D224 == 0;
          byte_105D224 = byte_105D224 == 0;
          v22 = *(pThis + 16);
        }
        else
        {
          v22 = *(pThis + 16);
          v21 = byte_105D224;
        }
        nItem = *(pThis + 16);
        break;
      case IDS_PRIVATE_DELTA_BYTES:
        v20 = dword_1069B98;
        if ( dword_1069B98 == v4 )
        {
          v21 = byte_105D225 == 0;
          byte_105D225 = byte_105D225 == 0;
        }
        else
        {
          v21 = byte_105D225;
        }
        v22 = *(pThis + 16);
        dword_1069B98 = *(pThis + 16);
        break;
      default:
        goto LABEL_47;
    }
    CTreeList::InitHeaderColumn(*pThis, v20, v22, v21);
  }
LABEL_47:
  SendMessageW(*pThis_1, 0x1030u, &wParam, PropProcThreadsSortCallback);
  v23 = (SendMessageW)(*pThis_1, 0x100Cu, 0xFFFFFFFF, 2);
  SendMessageW(*pThis_1, 0x1013u, v23, 0);
  if ( uTabID == 101 )
  {
    if ( v5 )
    {
      v27 = 1;
      v24 = *pThis_1;
      v28 = v5;
      item.iItem = (SendMessageW)(v24, 0x1053u, 0xFFFFFFFF, &v27);
      v25 = *pThis_1;
      v34 = 3;
      v33 = 3;
      SendMessageW(v25, 0x102Bu, item.iItem, &v30);
      SendMessageW(*pThis_1, 0x1013u, item.iItem, 0);
    }
    SendMessageW(*pThis_1, 0xBu, 1u, 0);
  }
  return 0;
}
// 105D224: using guessed type char byte_105D224;
// 105D225: using guessed type char byte_105D225;
// 10653B4: using guessed type char byte_10653B4;

//----- (00FBD4B0) --------------------------------------------------------
int __cdecl sub_FBD4B0(signed int a1, int a2)
{
  tagTREEVIEWITEMPARAM *v2; // ecx
  int v3; // edi
  tagTREEVIEWITEMPARAM *v4; // esi
  int *v5; // edx
  int v6; // edx
  tagTREEVIEWITEMPARAM *v8; // ecx
  int v9; // edx
  int v10; // edx
  tagTREEVIEWITEMPARAM *v11; // eax
  void *v12; // ecx
  tagTREEVIEWITEMPARAM *v13; // esi
  LVITEMW dllitem; // [esp+4h] [ebp-34h]

  dllitem.mask = 4;
  dllitem.iItem = *(a2 + 12);
  if ( a1 > 104 )
  {
    if ( a1 == 1040 )
    {
      SendMessageW(*a2, LVM_GETITEMW, 0, &dllitem);
      v11 = dllitem.lParam;
      v13 = dllitem.lParam;
      if ( dllitem.lParam->field_30 )
      {
        free(dllitem.lParam->field_30);
        v11 = dllitem.lParam;
      }
      v12 = v13->field_28;
    }
    else
    {
      if ( a1 != 1192 )
        return 0;
      SendMessageW(*a2, LVM_GETITEMW, 0, &dllitem);
      v11 = dllitem.lParam;
      if ( dllitem.lParam[25].field_4C )
      {
        free(dllitem.lParam[25].field_4C);
        v11 = dllitem.lParam;
      }
      v12 = v11[26].field_0;
    }
    if ( v12 )
    {
      free(v12);
      v11 = dllitem.lParam;
    }
    free(v11);
    return 0;
  }
  if ( a1 != 104 )
  {
    if ( a1 == 101 )
    {
      dword_105E0D8 = -1;
      *(*(a2 + 40) + 1464) = 0;
      return 0;
    }
    if ( a1 == 102 )
    {
      SendMessageW(ghWndHandlesListCtrl, LVM_GETITEMW, 0, &dllitem);
      v2 = dllitem.lParam;
      v3 = dllitem.lParam[51].field_0;
      v4 = dllitem.lParam + 51;
      v5 = &dllitem.lParam[50].field_50;
      if ( v3 )
      {
        *(v3 + 4280) = dllitem.lParam[50].field_50;
        v2 = dllitem.lParam;
      }
      else
      {
        dword_106539C = dllitem.lParam[50].field_50;
      }
      v6 = *v5;
      if ( v6 )
      {
        *(v6 + 4284) = v4->field_0;
        v2 = dllitem.lParam;
      }
      free(v2);
      return 0;
    }
    return 0;
  }
  SendMessageW(ghWndDllsListCtrl, LVM_GETITEMW, 0, &dllitem);
  v8 = dllitem.lParam;
  v9 = dllitem.lParam[4].field_34;
  if ( v9 )
    *(v9 + 384) = dllitem.lParam[4].field_30;
  else
    gpDllListItemParamHeader = dllitem.lParam[4].field_30;
  v10 = v8[4].field_30;
  if ( v10 )
    *(v10 + 388) = v8[4].field_34;
  DLLLISTITEMPARAM_Release(v8);
  return 0;
}
// 105E0D8: using guessed type int dword_105E0D8;

//----- (00FBD660) --------------------------------------------------------
int __cdecl FillList(int nID)
{
  HWND hWndList; // edi
  int nItem; // eax
  tagTREEVIEWITEMPARAM *v4; // esi
  tagLVITEMW lvitem; // [esp+8h] [ebp-34h]

  lvitem.mask = 0;
  memset(&lvitem.iItem, 0, 0x30u);
  switch ( nID )
  {
    case 101:
      hWndList = ghWndTreeListView;
      break;
    case 102:
      hWndList = ghWndHandlesListCtrl;
      break;
    case 104:
      hWndList = ghWndDllsListCtrl;
      break;
    default:
      return 0;
  }
  nItem = SendMessageW(hWndList, LVM_GETNEXTITEM, 0xFFFFFFFF, 2);
  if ( nItem != -1 )
  {
    lvitem.iItem = nItem;
    lvitem.iSubItem = 0;
    lvitem.mask = LVIF_PARAM;
    if ( SendMessageW(hWndList, LVM_GETITEMW, 0, &lvitem) == 1 )
    {
      switch ( nID )
      {
        case 101:
          CTreeList::FillTreeViewParam(lvitem.lParam);
          return 0;
        case 102:
          FillHandleListParam(hWndList, lvitem.lParam);
          return 0;
        case 104:
          v4 = lvitem.lParam;
          if ( lvitem.lParam->field_2C & 8 )
          {
            MessageBoxW(
              ghWndTreeListView,
              L"Properties not supported on pagefile-backed sections",
              L"Process Explorer Error",
              MB_ICONERROR);
            return 0;
          }
          if ( !lvitem.lParam->field_38 )
          {
            MessageBoxW(ghMainWnd, L"Not a valid DLL", L"Process Explorer", MB_ICONHAND);
            return 0;
          }
          InterlockedIncrement(&lvitem.lParam->field_0);
          v4->field_28 = gdwProcessIdSelected;
          _beginthread(PropertiesThreadProc, 0, v4);
          break;
      }
    }
  }
  return 0;
}

//----- (00FBD7A0) --------------------------------------------------------
int __cdecl sub_FBD7A0(int a1)
{
  return -(a1 != 101);
}

//----- (00FBD7B0) --------------------------------------------------------
int __cdecl sub_FBD7B0(signed int a1, int a2)
{
  int v2; // eax
  int result; // eax
  _DWORD *v4; // ecx
  signed int v5; // eax
  int v6; // eax
  int v7; // eax
  const wchar_t *v8; // eax
  int v9; // eax
  int v10; // eax
  bool v11; // zf
  int v12; // edx
  signed int v13; // ecx
  signed int v14; // eax
  signed int v15; // eax
  int v16; // eax
  int v17; // ebx
  int v18; // eax
  double v19; // xmm0_8
  int v20; // ebx
  unsigned int v21; // eax
  __int64 v22; // ST18_8
  const wchar_t *v23; // eax
  int v24; // eax
  int v25; // ecx
  int v26; // ecx
  int v27; // eax
  int v28; // eax
  const FILETIME *v29; // ebx
  unsigned int v30; // kr00_4
  unsigned int v31; // edx
  unsigned int v32; // ecx
  int *v33; // eax
  int v34; // edx
  int v35; // ecx
  int v36; // eax
  double v37; // xmm0_8
  int v38; // eax
  int v39; // edx
  int v40; // ecx
  int v41; // eax
  int v42; // edx
  int v43; // ecx
  int v44; // eax
  int v45; // edx
  int v46; // ecx
  int v47; // eax
  int v48; // edx
  int v49; // ecx
  int v50; // eax
  int v51; // edx
  int v52; // ecx
  int v53; // eax
  int v54; // edx
  int v55; // ecx
  int v56; // eax
  int v57; // edx
  int v58; // ecx
  int v59; // eax
  int v60; // edx
  int v61; // ecx
  int v62; // eax
  int v63; // edx
  int v64; // ecx
  int v65; // eax
  int v66; // edx
  int v67; // ecx
  int v68; // eax
  int v69; // edx
  int v70; // ecx
  int v71; // eax
  int v72; // eax
  int v73; // edx
  int v74; // ecx
  int v75; // eax
  int v76; // edx
  int v77; // ecx
  __int16 v78; // ax
  float v79; // xmm0_4
  double v80; // xmm0_8
  unsigned __int8 v81; // cl
  wchar_t *v82; // edx
  wchar_t *v83; // esi
  wchar_t v84; // ax
  unsigned int v85; // edx
  __int16 *v86; // edi
  __int16 v87; // ax
  __int16 *v88; // ecx
  __int16 v89; // ax
  const WCHAR **v90; // eax
  int v91; // esi
  signed int v92; // eax
  int v93; // eax
  int v94; // eax
  const WCHAR *v95; // eax
  int v96; // eax
  int v97; // eax
  int v98; // eax
  int v99; // eax
  const WCHAR **v100; // eax
  int v101; // eax
  int v102; // eax
  const WCHAR **v103; // eax
  int v104; // esi
  char v105; // al
  int v106; // ecx
  unsigned int v107; // kr04_4
  int v108; // ecx
  unsigned int v109; // kr08_4
  int v110; // eax
  int v111; // eax
  int v112; // esi
  int v113; // eax
  int v114; // eax
  void *v115; // ebx
  const wchar_t *v116; // eax
  const wchar_t *v117; // [esp+Ch] [ebp-268h]
  const wchar_t *v118; // [esp+Ch] [ebp-268h]
  const wchar_t *ArgList; // [esp+10h] [ebp-264h]
  int ArgLista; // [esp+10h] [ebp-264h]
  int ArgListb; // [esp+10h] [ebp-264h]
  signed int ArgList_4; // [esp+14h] [ebp-260h]
  int ArgList_4a; // [esp+14h] [ebp-260h]
  int ArgList_4b; // [esp+14h] [ebp-260h]
  int ArgList_4c; // [esp+14h] [ebp-260h]
  SIZE_T NumberOfBytesRead; // [esp+24h] [ebp-250h]
  struct _FILETIME LocalFileTime; // [esp+28h] [ebp-24Ch]
  int Buffer; // [esp+30h] [ebp-244h]
  int v129; // [esp+34h] [ebp-240h]
  struct _SYSTEMTIME SystemTime; // [esp+38h] [ebp-23Ch]
  wchar_t Dst; // [esp+48h] [ebp-22Ch]
  __int16 v132; // [esp+4Ah] [ebp-22Ah]
  __int16 v133; // [esp+66h] [ebp-20Eh]
  __int16 TimeStr[260]; // [esp+68h] [ebp-20Ch]

  v129 = a2;
  v2 = *(a2 + 12);
  if ( v2 & 2 )
  {
    *(a2 + 40) = *(*(a2 + 44) + 64);
    return 0;
  }
  if ( !*(a2 + 32) || !(v2 & 1) )
    return 0;
  wcscpy_s(TimeStr, 0x104u, &gszNullString);
  if ( a1 > 104 )
  {
    if ( a1 == 1044 )
    {
      v111 = *(a2 + 20);
      v112 = *(a2 + 44);
      switch ( v111 )
      {
        case 0:
          ArgList_4a = *(v112 + 44);
LABEL_49:
          swprintf(TimeStr, L"%d", ArgList_4a);
          goto LABEL_50;
        case 1:
          sub_FB5AD0(v112 + 576, *(v112 + 584), *(v112 + 584) >> 32, *(v112 + 600), *(v112 + 604), &Dst, 0x10u);
          goto LABEL_41;
        case 2:
          if ( QueryThreadCycleTime && *(v112 + 40) )
          {
            v8 = TimeStr;
            if ( !*(v112 + 600) )
              goto LABEL_51;
            swprintf(TimeStr, L"%I64u", *(v112 + 600), *(v112 + 604));
LABEL_90:
            sub_FC3290(TimeStr, 0x104u);
          }
          else
          {
            v8 = TimeStr;
            if ( !*(v112 + 584) )
              goto LABEL_51;
            swprintf(TimeStr, L"%d", *(v112 + 584), *(v112 + 588));
          }
          goto LABEL_50;
        case 3:
        case 4:
          if ( *(v112 + 644) == -1 )
            goto LABEL_363;
          v113 = v111 - 3;
          if ( v113 )
          {
            if ( v113 != 1 )
              goto LABEL_50;
LABEL_363:
            v8 = (v112 + 52);
          }
          else
          {
            Buffer = *(v112 + 644);
            ReadProcessMemory(*(v112 + 0x27C), (gdwTebAddressOffset + *(v112 + 0x280)), &Buffer, 4u, &NumberOfBytesRead);
            v114 = Buffer;
            if ( Buffer != *(v112 + 644) )
            {
              v115 = *(v112 + 648);
              if ( Buffer )
              {
                v116 = sub_FFEFB0(Buffer);
                *(v112 + 648) = _wcsdup(v116);
                v114 = Buffer;
              }
              else
              {
                *(v112 + 648) = 0;
              }
              if ( v115 )
              {
                free(v115);
                v114 = Buffer;
              }
              *(v112 + 644) = v114;
            }
            v8 = *(v112 + 648);
          }
          break;
        default:
          goto LABEL_50;
      }
      goto LABEL_364;
    }
    if ( a1 == 1192 )
    {
      v104 = *(a2 + 44);
      v105 = GetPropW(*a2, L"resolve");
      v106 = *(a2 + 20);
      LOBYTE(Buffer) = v105;
      switch ( v106 )
      {
        case 0:
          swprintf(&pszBuffer, L"%S", gszProtocolNames[*(v104 + 40)]);
          *(a2 + 32) = &pszBuffer;
          return 0;
        case 1:
          if ( v105 )
          {
            if ( *(v104 + 64) )
            {
              wcscpy_s(TimeStr, 0x104u, (v104 + 64));
            }
            else if ( sub_FC44B0(*(v104 + 40), Buffer, 1, *(v104 + 44), v104 + 48, TimeStr, 0x104u) )
            {
              wcscpy_s((v104 + 64), 0x104u, TimeStr);
            }
          }
          else
          {
            sub_FC44B0(*(v104 + 40), 0, 1, *(v104 + 44), v104 + 48, TimeStr, 0x104u);
          }
          v107 = wcslen(TimeStr);
          sub_FC4670(Buffer, *(v104 + 584), gszProtocolNames[*(v104 + 40)], &TimeStr[v107], 260 - v107);
          v20 = v129;
          v8 = TimeStr;
          goto LABEL_52;
        case 2:
          v108 = *(v104 + 40);
          if ( v108 && v108 != 2 )
          {
            *(a2 + 32) = L"*:*";
            return 0;
          }
          if ( v105 )
          {
            if ( *(v104 + 1128) )
            {
              wcscpy_s(TimeStr, 0x104u, (v104 + 1128));
            }
            else if ( sub_FC44B0(v108, Buffer, 0, *(v104 + 1108), v104 + 1112, TimeStr, 0x104u) )
            {
              wcscpy_s((v104 + 1128), 0x104u, TimeStr);
            }
          }
          else
          {
            sub_FC44B0(v108, 0, 0, *(v104 + 1108), v104 + 1112, TimeStr, 0x104u);
          }
          v109 = wcslen(TimeStr);
          sub_FC4670(Buffer, *(v104 + 1648), gszProtocolNames[*(v104 + 40)], &TimeStr[v109], 260 - v109);
          v20 = v129;
          v8 = TimeStr;
          break;
        case 3:
          v110 = *(v104 + 40);
          if ( v110 && v110 != 2 )
            goto LABEL_50;
          v8 = gszNetStatus[*(v104 + 2172)];
          goto LABEL_364;
        case 4:
          v8 = *(v104 + 2184);
          goto LABEL_364;
        default:
          goto LABEL_50;
      }
      goto LABEL_52;
    }
    goto LABEL_50;
  }
  if ( a1 != 104 )
  {
    if ( a1 != 101 )
    {
      if ( a1 == 102 )
      {
        v4 = *(a2 + 44);
        v5 = gConfig.dwIdsOfHandleColumnMap[*(a2 + 20)];
        if ( v5 > 39 )
        {
          v9 = v5 - 1185;
          if ( v9 )
          {
            v10 = v9 - 9;
            if ( v10 )
            {
              v11 = v10 == 114;
              v8 = TimeStr;
              if ( !v11 )
              {
LABEL_51:
                v20 = a2;
LABEL_52:
                wcsncpy_s(*(v20 + 32), *(v20 + 32) >> 32, v8, 0xFFFFFFFF);
                return 0;
              }
              sub_FA8CE0(v4[12], (v4 + 14), TimeStr);
            }
            else
            {
              v12 = v4[13];
              if ( v12 )
              {
                v13 = 45;
                v14 = 45;
                if ( v12 & 4 )
                  v14 = 68;
                ArgList_4 = v14;
                v15 = 45;
                if ( v12 & 2 )
                  v15 = 87;
                if ( v12 & 1 )
                  v13 = 82;
                swprintf(TimeStr, L"%C%C%C", v13, v15, ArgList_4);
              }
            }
          }
          else
          {
            swprintf(TimeStr, L"0x%08X", v4[10]);
          }
        }
        else if ( v5 == 39 )
        {
          swprintf(TimeStr, L"0x%08X", v4[12]);
        }
        else
        {
          v6 = v5 - 20;
          if ( v6 )
          {
            v7 = v6 - 1;
            if ( v7 )
            {
              if ( v7 == 1 )
              {
                v8 = (v4 + 558);
                goto LABEL_364;
              }
              goto LABEL_50;
            }
            v8 = (v4 + 14);
LABEL_364:
            if ( !v8 )
            {
LABEL_228:
              *(a2 + 32) = &gszNullString;
              return 0;
            }
            if ( v8 != TimeStr )
            {
              *(a2 + 32) = v8;
              return 0;
            }
            goto LABEL_51;
          }
          swprintf(TimeStr, L"0x%X", v4[11]);
        }
      }
      goto LABEL_50;
    }
    v16 = *(a2 + 20);
    v17 = *(a2 + 44);
    if ( v16 > gConfig.dwProcessColumnCount )
      return 0;
    v18 = gConfig.dwProcessColumnMap[v16];
    if ( v18 <= 1032 )
    {
      if ( v18 == 1032 )
      {
        v8 = *(v17 + 800);
        goto LABEL_364;
      }
      switch ( v18 )
      {
        case 3:
          v8 = *(v17 + 60);
          goto LABEL_364;
        case 4:
          goto LABEL_204;
        case 5:
          ArgList_4a = *(v17 + 1368);
          goto LABEL_49;
        case 6:
          goto LABEL_54;
        case 7:
          v19 = *(v17 + 1304);
          if ( v19 <= 0.005 )
          {
            wcscpy_s(&Dst, 0x10u, &gszNullString);
          }
          else if ( gConfig.bShowCpuFractions )
          {
            sub_FA13E0(&Dst, L"%02.2f", LODWORD(v19), HIDWORD(v19));
          }
          else
          {
            sub_FA13E0(&Dst, L"%0.0f", LODWORD(v19), HIDWORD(v19));
          }
          goto LABEL_41;
        case 9:
          v21 = *(v17 + 920);
          goto LABEL_62;
        case 10:
          swprintf(TimeStr, L"%I64u", *(v17 + 924) >> 10, 0);
          sub_FC3290(TimeStr, 0x104u);
          wcscat_s(TimeStr, 0x104u, L" K");
          goto LABEL_50;
        case 18:
          ArgList_4b = *(v17 + 92);
          goto LABEL_55;
        case 19:
          v8 = *(v17 + 88);
          goto LABEL_364;
        case 25:
          v8 = (v17 + 654);
          goto LABEL_364;
        case 35:
          v8 = (v17 + 104);
          goto LABEL_364;
        case 38:
          v8 = *(v17 + 784);
          goto LABEL_364;
        default:
          goto LABEL_50;
      }
      goto LABEL_50;
    }
    if ( v18 <= 1317 )
    {
      if ( v18 != 1317 )
      {
        switch ( v18 )
        {
          case 1033:
            v8 = *(v17 + 788);
            goto LABEL_364;
          case 1055:
            if ( *(v17 + 40) < 0 )
            {
              *(a2 + 32) = L"Suspended";
              return 0;
            }
            sub_FB5AD0(v17 + 1296, *(v17 + 1336), *(v17 + 1336) >> 32, *(v17 + 1352), *(v17 + 1356), &Dst, 0x10u);
            break;
          case 1056:
            v27 = *(v17 + 100);
            goto LABEL_113;
          case 1059:
            ArgList_4c = 0;
            ArgListb = *(v17 + 880);
            goto LABEL_88;
          case 1060:
            swprintf(TimeStr, L"%I64u", *(v17 + 888) >> 10, 0);
            sub_FC3290(TimeStr, 0x104u);
            wcscat_s(TimeStr, 0x104u, L" K");
            goto LABEL_50;
          case 1061:
            v8 = *(v17 + 792);
            goto LABEL_364;
          case 1062:
            swprintf(TimeStr, L"%I64u", *(v17 + 896) >> 10, 0);
            sub_FC3290(TimeStr, 0x104u);
            wcscat_s(TimeStr, 0x104u, L" K");
            goto LABEL_50;
          case 1063:
            swprintf(TimeStr, L"%I64u", *(v17 + 900) >> 10, 0);
            sub_FC3290(TimeStr, 0x104u);
            wcscat_s(TimeStr, 0x104u, L" K");
            goto LABEL_50;
          case 1064:
            swprintf(TimeStr, L"%I64u", *(v17 + 904) >> 10, 0);
            sub_FC3290(TimeStr, 0x104u);
            wcscat_s(TimeStr, 0x104u, L" K");
            goto LABEL_50;
          case 1065:
LABEL_54:
            ArgList_4b = *(v17 + 96);
            goto LABEL_55;
          case 1066:
            ArgList_4b = *(v17 + 1380);
            goto LABEL_55;
          case 1067:
            ArgList_4b = *(v17 + 1376);
            goto LABEL_55;
          case 1068:
            ArgList_4b = *(v17 + 960);
            ArgList = L"%u";
            goto LABEL_56;
          case 1069:
            v31 = *(v17 + 972);
            v32 = *(v17 + 968);
            goto LABEL_188;
          case 1070:
            ArgList_4b = *(v17 + 992);
            ArgList = L"%u";
            goto LABEL_56;
          case 1071:
            v31 = *(v17 + 1004);
            v32 = *(v17 + 1000);
            goto LABEL_188;
          case 1072:
            ArgList_4b = *(v17 + 1024);
            ArgList = L"%u";
            goto LABEL_56;
          case 1073:
            v31 = *(v17 + 1036);
            v32 = *(v17 + 1032);
            goto LABEL_188;
          case 1086:
            v28 = *(v17 + 624);
            v29 = (v17 + 624);
            if ( !(v29->dwHighDateTime | v28) )
              goto LABEL_184;
            FileTimeToLocalFileTime(v29, &LocalFileTime);
            FileTimeToSystemTime(&LocalFileTime, &SystemTime);
            GetTimeFormatW(0x400u, 0, &SystemTime, 0, TimeStr, 260);
            wcscat_s(TimeStr, 0x104u, L" ");
            v30 = wcslen(TimeStr);
            GetDateFormatW(0x400u, 0, &SystemTime, 0, &TimeStr[v30], 260 - v30);
            goto LABEL_50;
          case 1087:
            v22 = *(v17 + 1320);
            v20 = v129;
            swprintf(
              TimeStr,
              L"%I64d:%02I64d:%02I64d.%03I64d",
              *(*(v129 + 44) + 1320) / 0x861C46800ui64,
              *(*(v129 + 44) + 1320) / 0x23C34600ui64 % 0x3C,
              v22 / 10000000 % 60,
              v22 % 10000000 / 10000);
            v8 = TimeStr;
            goto LABEL_52;
          case 1091:
            ArgList_4c = *(v17 + 1348);
            ArgListb = *(v17 + 1344);
            goto LABEL_88;
          case 1092:
            v26 = *(v17 + 1340);
            if ( v26 < 0 || v26 <= 0 && !*(v17 + 1336) )
              goto LABEL_50;
            ArgList_4c = *(v17 + 1340);
            ArgListb = *(v17 + 1336);
LABEL_88:
            v118 = L"%I64d";
            goto LABEL_89;
          case 1094:
            v33 = *(v17 + 1284);
            if ( !v33 )
              goto LABEL_50;
            v34 = *v33;
            v35 = v33[1];
            v11 = *v33 == 0i64;
            v8 = TimeStr;
            if ( v11 )
              goto LABEL_51;
            swprintf(TimeStr, L"%I64d", v34, v35);
            goto LABEL_90;
          case 1095:
            v36 = *(v17 + 1284);
            if ( !v36 )
              goto LABEL_50;
            v37 = *(v36 + 8);
            goto LABEL_129;
          case 1096:
            v38 = *(v17 + 1284);
            if ( !v38 )
              goto LABEL_50;
            v39 = *(v38 + 16);
            v40 = *(v38 + 20);
            v11 = *(v38 + 16) == 0i64;
            v8 = TimeStr;
            if ( v11 )
              goto LABEL_51;
            swprintf(TimeStr, L"%I64d", v39, v40);
            goto LABEL_90;
          case 1097:
            v41 = *(v17 + 1284);
            if ( !v41 )
              goto LABEL_50;
            v42 = *(v41 + 48);
            v43 = *(v41 + 52);
            v11 = *(v41 + 48) == 0i64;
            v8 = TimeStr;
            if ( v11 )
              goto LABEL_51;
            swprintf(TimeStr, L"%I64d", v42, v43);
            goto LABEL_90;
          case 1098:
            v44 = *(v17 + 1284);
            if ( !v44 )
              goto LABEL_50;
            v45 = *(v44 + 32);
            v46 = *(v44 + 36);
            v11 = *(v44 + 32) == 0i64;
            v8 = TimeStr;
            if ( v11 )
              goto LABEL_51;
            swprintf(TimeStr, L"%I64d", v45, v46);
            goto LABEL_90;
          case 1099:
            v47 = *(v17 + 1284);
            if ( !v47 )
              goto LABEL_50;
            v48 = *(v47 + 24);
            v49 = *(v47 + 28);
            v11 = *(v47 + 24) == 0i64;
            v8 = TimeStr;
            if ( v11 )
              goto LABEL_51;
            swprintf(TimeStr, L"%I64d", v48, v49);
            goto LABEL_90;
          case 1100:
            v50 = *(v17 + 1284);
            if ( !v50 )
              goto LABEL_50;
            v51 = *(v50 + 56);
            v52 = *(v50 + 60);
            v11 = *(v50 + 56) == 0i64;
            v8 = TimeStr;
            if ( v11 )
              goto LABEL_51;
            swprintf(TimeStr, L"%I64d", v51, v52);
            goto LABEL_90;
          case 1101:
            v53 = *(v17 + 1284);
            if ( !v53 )
              goto LABEL_50;
            v54 = *(v53 + 40);
            v55 = *(v53 + 44);
            v11 = *(v53 + 40) == 0i64;
            v8 = TimeStr;
            if ( v11 )
              goto LABEL_51;
            swprintf(TimeStr, L"%I64d", v54, v55);
            goto LABEL_90;
          case 1103:
            v59 = *(v17 + 1284);
            if ( !v59 )
              goto LABEL_50;
            v60 = *(v59 + 112);
            v61 = *(v59 + 116);
            v11 = *(v59 + 112) == 0i64;
            v8 = TimeStr;
            if ( v11 )
              goto LABEL_51;
            swprintf(TimeStr, L"%I64d", v60, v61);
            goto LABEL_90;
          case 1104:
            v62 = *(v17 + 1284);
            if ( !v62 )
              goto LABEL_50;
            v63 = *(v62 + 64);
            v64 = *(v62 + 68);
            v11 = *(v62 + 64) == 0i64;
            v8 = TimeStr;
            if ( v11 )
              goto LABEL_51;
            swprintf(TimeStr, L"%I64d", v63, v64);
            goto LABEL_90;
          case 1105:
            v65 = *(v17 + 1284);
            if ( !v65 )
              goto LABEL_50;
            v66 = *(v65 + 72);
            v67 = *(v65 + 76);
            v11 = *(v65 + 72) == 0i64;
            v8 = TimeStr;
            if ( v11 )
              goto LABEL_51;
            swprintf(TimeStr, L"%I64d", v66, v67);
            goto LABEL_90;
          case 1106:
            v68 = *(v17 + 1284);
            if ( !v68 )
              goto LABEL_50;
            v69 = *(v68 + 80);
            v70 = *(v68 + 84);
            v11 = *(v68 + 80) == 0i64;
            v8 = TimeStr;
            if ( v11 )
              goto LABEL_51;
            swprintf(TimeStr, L"%I64d", v69, v70);
            goto LABEL_90;
          case 1107:
            v71 = *(v17 + 1284);
            if ( !v71 )
              goto LABEL_50;
            v37 = *(v71 + 88);
LABEL_129:
            v8 = TimeStr;
            if ( v37 == 0.0 )
              goto LABEL_51;
            swprintf(TimeStr, L"%02.02f", LODWORD(v37), HIDWORD(v37));
            goto LABEL_50;
          case 1108:
            v72 = *(v17 + 1284);
            if ( !v72 )
              goto LABEL_50;
            v73 = *(v72 + 104);
            v74 = *(v72 + 108);
            v11 = *(v72 + 104) == 0i64;
            v8 = TimeStr;
            if ( v11 )
              goto LABEL_51;
            swprintf(TimeStr, L"%I64d", v73, v74);
            goto LABEL_90;
          case 1109:
            v75 = *(v17 + 1284);
            if ( !v75 )
              goto LABEL_50;
            v76 = *(v75 + 120);
            v77 = *(v75 + 124);
            v11 = *(v75 + 120) == 0i64;
            v8 = TimeStr;
            if ( v11 )
              goto LABEL_51;
            swprintf(TimeStr, L"%I64d", v76, v77);
            goto LABEL_90;
          case 1110:
            v56 = *(v17 + 1284);
            if ( !v56 )
              goto LABEL_50;
            v57 = *(v56 + 128);
            v58 = *(v56 + 132);
            v11 = *(v56 + 128) == 0i64;
            v8 = TimeStr;
            if ( v11 )
              goto LABEL_51;
            swprintf(TimeStr, L"%I64d", v57, v58);
            goto LABEL_90;
          case 1114:
            swprintf(TimeStr, L"%I64u", *(v17 + 876) >> 10, 0);
            sub_FC3290(TimeStr, 0x104u);
            wcscat_s(TimeStr, 0x104u, L" K");
            goto LABEL_50;
          case 1115:
            ArgLista = *(v17 + 936) >> 10;
            v117 = L"%I64d";
            goto LABEL_63;
          case 1116:
            swprintf(TimeStr, L"%I64u", *(v17 + 940) >> 10, 0);
            sub_FC3290(TimeStr, 0x104u);
            wcscat_s(TimeStr, 0x104u, L" K");
            goto LABEL_50;
          case 1118:
            swprintf(TimeStr, L"%I64u", *(v17 + 948) >> 10, 0);
            sub_FC3290(TimeStr, 0x104u);
            wcscat_s(TimeStr, 0x104u, L" K");
            goto LABEL_50;
          case 1179:
            if ( !*(v17 + 884) )
              goto LABEL_50;
            ArgList_4b = *(v17 + 884);
            goto LABEL_55;
          case 1180:
            v8 = *(v17 + 820);
            goto LABEL_364;
          case 1181:
            v8 = *(v17 + 796);
            goto LABEL_364;
          case 1187:
            v8 = *(v17 + 836);
            goto LABEL_364;
          case 1190:
            goto LABEL_79;
          case 1192:
            v24 = *(v17 + 892);
            if ( v24 )
            {
              swprintf(TimeStr, L"%d", v24 / 1024);
              sub_FC3290(TimeStr, 0x104u);
              wcscat_s(TimeStr, 0x104u, L" K");
            }
            goto LABEL_50;
          case 1195:
            ArgList_4c = *(v17 + 1364);
            ArgListb = *(v17 + 1360);
            v118 = L"%I64u";
            goto LABEL_89;
          case 1196:
            if ( !*(v17 + 616) )
              goto LABEL_50;
            v23 = L"Not responding";
            if ( !*(v17 + 620) )
              v23 = L"Running";
            *(a2 + 32) = v23;
            return 0;
          case 1199:
            sub_FF7720(v17, TimeStr, 0x104u);
            goto LABEL_50;
          case 1200:
            v25 = *(v17 + 1356);
            if ( v25 < 0 || v25 <= 0 && !*(v17 + 1352) )
              goto LABEL_50;
            ArgList_4c = *(v17 + 1356);
            ArgListb = *(v17 + 1352);
            v118 = L"%I64u";
LABEL_89:
            swprintf(TimeStr, v118, ArgListb, ArgList_4c);
            goto LABEL_90;
          default:
            goto LABEL_50;
        }
LABEL_41:
        if ( Dst == 48 && (v132 == 48 || !v132) )
        {
          *(a2 + 32) = L"    ";
          return 0;
        }
        wcscpy_s(TimeStr, 0x104u, &Dst);
        goto LABEL_50;
      }
      v21 = *(v17 + 944);
      goto LABEL_62;
    }
    if ( v18 <= 1609 )
    {
      if ( v18 == 1609 )
      {
        if ( *(v17 + 1072) )
        {
          ArgList_4b = *(v17 + 1072);
          ArgList = L"%u";
LABEL_56:
          swprintf(TimeStr, ArgList, ArgList_4b);
LABEL_57:
          sub_FC3290(TimeStr, 0x104u);
        }
      }
      else
      {
        switch ( v18 )
        {
          case 1326:
            if ( !*(v17 + 976) )
              goto LABEL_50;
            ArgList_4b = *(v17 + 976);
            goto LABEL_55;
          case 1327:
            v31 = *(v17 + 988);
            v32 = *(v17 + 984);
            goto LABEL_188;
          case 1328:
            if ( !*(v17 + 1008) )
              goto LABEL_50;
            ArgList_4b = *(v17 + 1008);
            goto LABEL_55;
          case 1329:
            v31 = *(v17 + 1020);
            v32 = *(v17 + 1016);
            goto LABEL_188;
          case 1332:
            v31 = *(v17 + 1052);
            v32 = *(v17 + 1048);
            goto LABEL_188;
          case 1333:
            v31 = *(v17 + 1060);
            v32 = *(v17 + 1056);
            goto LABEL_188;
          case 1335:
            if ( !*(v17 + 1040) )
              goto LABEL_50;
            ArgList_4b = *(v17 + 1040);
            goto LABEL_55;
          case 1336:
            v8 = *(v17 + 816);
            goto LABEL_364;
          case 1337:
            if ( !(*(v17 + 40) & 0x200) )
              goto LABEL_50;
            *(a2 + 32) = L"Virtualized";
            return 0;
          case 1338:
            v78 = *(v17 + 650);
            if ( v78 & 0x40 )
              goto LABEL_182;
            goto LABEL_183;
          case 1339:
            v27 = *(v17 + 872);
LABEL_113:
            if ( v27 == -1 )
              goto LABEL_50;
            ArgList_4a = v27;
            goto LABEL_49;
          case 1340:
            sub_FF7790(*(v17 + 952), TimeStr, 0x104u);
            goto LABEL_50;
          case 1341:
            v21 = *(v17 + 912);
            goto LABEL_62;
          case 1342:
            v21 = *(v17 + 916);
            goto LABEL_62;
          default:
            goto LABEL_50;
        }
      }
      goto LABEL_50;
    }
    if ( v18 <= 40757 )
    {
      if ( v18 != 40757 )
      {
        switch ( v18 )
        {
          case 1610:
            if ( !*(v17 + 1088) )
              goto LABEL_50;
            ArgList_4b = *(v17 + 1088);
            goto LABEL_55;
          case 1611:
            if ( !*(v17 + 1104) )
              goto LABEL_50;
            ArgList_4b = *(v17 + 1104);
            ArgList = L"%u";
            goto LABEL_56;
          case 1612:
            if ( !*(v17 + 1120) )
              goto LABEL_50;
            ArgList_4b = *(v17 + 1120);
            goto LABEL_55;
          case 1613:
            if ( !*(v17 + 1136) )
              goto LABEL_50;
            ArgList_4b = *(v17 + 1136);
            ArgList = L"%u";
            goto LABEL_56;
          case 1614:
            if ( !*(v17 + 1152) )
              goto LABEL_50;
            ArgList_4b = *(v17 + 1152);
            goto LABEL_55;
          case 1616:
            v80 = *(v17 + 1096);
            goto LABEL_189;
          case 1617:
            v31 = *(v17 + 1084);
            v32 = *(v17 + 1080);
            goto LABEL_188;
          case 1618:
            v31 = *(v17 + 1116);
            v32 = *(v17 + 1112);
            goto LABEL_188;
          case 1619:
            v31 = *(v17 + 1132);
            v32 = *(v17 + 1128);
            goto LABEL_188;
          case 1620:
            v80 = *(v17 + 1144);
            goto LABEL_189;
          case 1621:
            if ( *(v17 + 1160) )
              sub_FB2200(0, TimeStr, 0x104u, COERCE__INT64(*(v17 + 1160)), 0i64, 0i64 >> 63);
            goto LABEL_50;
          case 1622:
            v80 = *(v17 + 1168);
            goto LABEL_189;
          case 1623:
            v8 = TimeStr;
            if ( !*(v17 + 1184) )
              goto LABEL_51;
            swprintf(TimeStr, L"%u", *(v17 + 1176));
            goto LABEL_57;
          case 1624:
            if ( !*(v17 + 1192) )
              goto LABEL_50;
            ArgList_4b = *(v17 + 1192);
            goto LABEL_55;
          case 1625:
            if ( !*(v17 + 1208) )
              goto LABEL_50;
            ArgList_4b = *(v17 + 1208);
            ArgList = L"%u";
            goto LABEL_56;
          case 1626:
            if ( !*(v17 + 1224) )
              goto LABEL_50;
            ArgList_4b = *(v17 + 1224);
            goto LABEL_55;
          case 1627:
            if ( !*(v17 + 1240) )
              goto LABEL_50;
            ArgList_4b = *(v17 + 1240);
            ArgList = L"%u";
            goto LABEL_56;
          case 1628:
            if ( !*(v17 + 1256) )
              goto LABEL_50;
            ArgList_4b = *(v17 + 1256);
LABEL_55:
            ArgList = L"%d";
            goto LABEL_56;
          case 1630:
            v31 = *(v17 + 1188);
            v32 = *(v17 + 1184);
            goto LABEL_188;
          case 1631:
            v31 = *(v17 + 1204);
            v32 = *(v17 + 1200);
            goto LABEL_188;
          case 1632:
            v31 = *(v17 + 1220);
            v32 = *(v17 + 1216);
            goto LABEL_188;
          case 1633:
            v31 = *(v17 + 1236);
            v32 = *(v17 + 1232);
            goto LABEL_188;
          case 1634:
            v31 = *(v17 + 1252);
            v32 = *(v17 + 1248);
            goto LABEL_188;
          case 1635:
            v31 = *(v17 + 1268);
            v32 = *(v17 + 1264);
            goto LABEL_188;
          case 1636:
            v31 = *(v17 + 1276);
            v32 = *(v17 + 1272);
LABEL_188:
            v79 = __PAIR__(v31, v32);
            v80 = v79;
LABEL_189:
            sub_FB5BB0(TimeStr, *&v80);
            goto LABEL_50;
          case 1637:
            sub_FB5AD0(v17 + 1312, 0, 0, 0, 0, &Dst, 0x10u);
            goto LABEL_41;
          case 1638:
LABEL_204:
            if ( *(v17 + 68) < 0 )
              goto LABEL_184;
            ArgList_4a = *(v17 + 68);
            goto LABEL_49;
          case 1650:
            sub_FB5AD0(v17 + 1384, 0, 0, 0, 0, &Dst, 0x10u);
            goto LABEL_41;
          case 1651:
            v8 = TimeStr;
            if ( !*(v17 + 1408) )
              goto LABEL_51;
            swprintf(TimeStr, L"%I64u", *(v17 + 1408), *(v17 + 1412));
            goto LABEL_64;
          case 1652:
            v8 = TimeStr;
            if ( !*(v17 + 1424) )
              goto LABEL_51;
            swprintf(TimeStr, L"%I64u", *(v17 + 1424), *(v17 + 1428));
            goto LABEL_64;
          case 1653:
            v8 = TimeStr;
            if ( !*(v17 + 1440) )
              goto LABEL_51;
            swprintf(TimeStr, L"%I64u", *(v17 + 1440), *(v17 + 1444));
            goto LABEL_64;
          case 1654:
            v8 = *(v17 + 824);
            goto LABEL_364;
          case 1656:
            v8 = *(v17 + 828);
            goto LABEL_364;
          case 1667:
            switch ( *(v17 + 644) )
            {
              case 0xFFFFFFFF:
                goto LABEL_228;
              case 0:
                *(a2 + 32) = L"Unaware";
                return 0;
              case 1:
                *(a2 + 32) = L"System Aware";
                return 0;
              case 2:
                *(a2 + 32) = L"Per-Monitor Aware";
                return 0;
              default:
                ArgList_4a = *(v17 + 644);
                break;
            }
            goto LABEL_49;
          case 1670:
            sub_1001A50(*(v17 + 844), TimeStr);
            goto LABEL_50;
          case 1673:
            v81 = *(v17 + 649);
            if ( !v81 )
              goto LABEL_50;
            if ( (v81 & 0xF0u) < 0x70 )
            {
              v82 = &aPsprotectedsig[64 * (v81 >> 4)];
              v83 = &aPsprotectedsig[64 * (v81 >> 4)];
              do
              {
                v84 = *v82;
                ++v82;
              }
              while ( v84 );
              v85 = v82 - v83;
              v86 = &v133;
              do
              {
                v87 = v86[1];
                ++v86;
              }
              while ( v87 );
              qmemcpy(v86, v83, v85);
            }
            if ( (*(v17 + 649) & 7) == 1 )
            {
              v88 = &v133;
              do
              {
                v89 = v88[1];
                ++v88;
              }
              while ( v89 );
              *v88 = *L"-Light";
              *(v88 + 1) = *L"ight";
              *(v88 + 2) = *L"ht";
              v88[6] = aLight[6];
            }
            v20 = v129;
            v8 = TimeStr;
            goto LABEL_52;
          case 1674:
            v90 = L"UI Access";
            if ( !(*(v17 + 40) & 0x2000) )
              v90 = &gszNullString;
            *(a2 + 32) = v90;
            return 0;
          default:
            goto LABEL_50;
        }
        goto LABEL_50;
      }
      v78 = *(v17 + 650);
      if ( !(*(v17 + 650) & 0x4000) )
      {
LABEL_183:
        if ( !v78 )
        {
LABEL_184:
          *(a2 + 32) = L"n/a";
          return 0;
        }
        goto LABEL_50;
      }
LABEL_276:
      *(a2 + 32) = L"CFG";
      return 0;
    }
LABEL_50:
    v8 = TimeStr;
    goto LABEL_51;
  }
  v91 = *(a2 + 44);
  v92 = gConfig.dwDllColumnMap[*(a2 + 20)];
  if ( v92 <= 30 )
  {
    if ( v92 == 30 )
    {
      v8 = (v91 + 76);
      goto LABEL_364;
    }
    switch ( v92 )
    {
      case 23:
        swprintf(TimeStr, L"0x%X", *(v91 + 36));
        goto LABEL_50;
      case 24:
        swprintf(TimeStr, L"0x%X", *(v91 + 56));
        goto LABEL_50;
      case 25:
        v8 = (v91 + 206);
        goto LABEL_364;
      case 26:
        if ( !wcsrchr(*(v91 + 344), 0x5Cu) )
          goto LABEL_304;
        v8 = wcsrchr(*(v91 + 344), 0x5Cu) + 1;
        goto LABEL_364;
      default:
        goto LABEL_50;
    }
    goto LABEL_50;
  }
  if ( v92 <= 1118 )
  {
    if ( v92 == 1118 )
    {
      v21 = *(v91 + 380);
    }
    else
    {
      if ( v92 <= 1074 )
      {
        if ( v92 == 1074 )
        {
          swprintf(TimeStr, L"0x%X", *(v91 + 48));
          goto LABEL_50;
        }
        v93 = v92 - 40;
        if ( v93 )
        {
          v94 = v93 - 2;
          if ( !v94 )
          {
            v8 = *(v91 + 336);
            goto LABEL_364;
          }
          if ( v94 == 991 )
          {
            v8 = *(v91 + 340);
            goto LABEL_364;
          }
          goto LABEL_50;
        }
        v95 = L"Data";
        if ( !(*(v91 + 44) & 2) )
          v95 = L"Image";
        *(a2 + 32) = v95;
        return 0;
      }
      v96 = v92 - 1111;
      if ( !v96 )
      {
LABEL_304:
        v8 = *(v91 + 344);
        goto LABEL_364;
      }
      v97 = v96 - 4;
      if ( v97 )
      {
        if ( v97 != 1 )
          goto LABEL_50;
        v21 = *(v91 + 372);
      }
      else
      {
        v21 = *(v91 + 368);
      }
    }
LABEL_62:
    ArgLista = v21 >> 10;
    v117 = L"%I64u";
LABEL_63:
    swprintf(TimeStr, v117, ArgLista, 0);
LABEL_64:
    sub_FC3290(TimeStr, 0x104u);
    wcscat_s(TimeStr, 0x104u, L" K");
    goto LABEL_50;
  }
  if ( v92 <= 1338 )
  {
    if ( v92 == 1338 )
    {
      if ( *(v91 + 54) & 0x40 )
      {
LABEL_182:
        *(a2 + 32) = L"ASLR";
        result = 0;
      }
      else
      {
        v100 = L"n/a";
        if ( !(*(v91 + 44) & 2) )
          v100 = &gszNullString;
        *(a2 + 32) = v100;
        result = 0;
      }
      return result;
    }
    v98 = v92 - 1187;
    if ( !v98 )
    {
      v8 = *(v91 + 356);
      goto LABEL_364;
    }
    v99 = v98 - 3;
    if ( !v99 )
    {
LABEL_79:
      *(a2 + 32) = L"32-bit";
      return 0;
    }
    if ( v99 != 127 )
      goto LABEL_50;
    v21 = *(v91 + 376);
    goto LABEL_62;
  }
  v101 = v92 - 1656;
  if ( !v101 )
  {
    v8 = *(v91 + 348);
    goto LABEL_364;
  }
  v102 = v101 - 14;
  if ( !v102 )
  {
    sub_1001A50(*(v91 + 364), TimeStr);
    goto LABEL_50;
  }
  if ( v102 != 39087 )
    goto LABEL_50;
  if ( *(v91 + 54) & 0x4000 )
    goto LABEL_276;
  v103 = L"n/a";
  if ( *(v91 + 54) )
    v103 = &gszNullString;
  *(a2 + 32) = v103;
  return 0;
}
// 103E080: using guessed type wchar_t aSuspended[10];
// 103E094: using guessed type wchar_t asc_103E094[5];
// 103E0A0: using guessed type wchar_t aVirtualized[12];
// 103E0C8: using guessed type wchar_t aUiAccess[10];
// 103E0DC: using guessed type wchar_t aUnaware[8];
// 103E0EC: using guessed type wchar_t aSystemAware[13];
// 103E108: using guessed type wchar_t aPerMonitorAwar[18];
// 103E12C: using guessed type wchar_t aAslr[5];
// 103E138: using guessed type wchar_t aCfg[4];
// 103E140: using guessed type wchar_t a32Bit[7];
// 103E18C: using guessed type wchar_t aNotResponding[15];
// 103E200: using guessed type wchar_t a0x08x[7];
// 103E220: using guessed type wchar_t aData_0[5];
// 103E250: using guessed type wchar_t asc_103E250[4];
// 103E9C8: using guessed type double db_zeropointzerozerofive;
// 105D238: using guessed type wchar_t *gszNetStatus[13];
// 106B1CC: using guessed type int gdwTebAddressOffset;
// FBD7B0: using guessed type WCHAR TimeStr[260];

//----- (00FBF490) --------------------------------------------------------
int __cdecl sub_FBF490(int a1, int a2)
{
  WPARAM v2; // eax
  int result; // eax

  if ( a1 != 101 || (v2 = *(a2 + 12), v2 != 9) && v2 != 36 && v2 != 35 && v2 != 13 )
    result = 0;
  else
    result = Proxy_ListCtrlWndProc(*a2, 256u, v2, 0);
  return result;
}

//----- (00FBF4D0) --------------------------------------------------------
int __cdecl sub_FBF4D0(HMENU hMnu)
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
  LPARAM v14; // [esp+8h] [ebp-68h]
  int v15; // [esp+14h] [ebp-5Ch]
  int v16; // [esp+18h] [ebp-58h]
  LPARAM lParam; // [esp+3Ch] [ebp-34h]
  LRESULT v18; // [esp+40h] [ebp-30h]
  int v19; // [esp+44h] [ebp-2Ch]
  char v20; // [esp+48h] [ebp-28h]
  int v21; // [esp+4Ch] [ebp-24h]
  tagTREEVIEWLISTITEMPARAM *pItem; // [esp+5Ch] [ebp-14h]
  HMENU hMnua; // [esp+78h] [ebp+8h]

  lParam = 0;
  memset(&v18, 0, 0x30u);
  if ( hMnu == 101 )
  {
    v1 = ghWndTreeListView;
  }
  else if ( hMnu == 102 )
  {
    v1 = ghWndHandlesListCtrl;
  }
  else
  {
    if ( hMnu != 104 )
      return 0;
    v1 = ghWndDllsListCtrl;
  }
  v18 = SendMessageW(v1, 0x100Cu, 0xFFFFFFFF, 2);
  v19 = 0;
  v21 = 2;
  lParam = 12;
  v2 = SendMessageW(v1, 0x104Bu, 0, &lParam);
  if ( hMnu == 101 )
  {
    if ( v2 == 1 && v20 & 2 )
    {
      v3 = pItem;
      v4 = pItem->dwProcessId;
      if ( gdwProcessIdSelected != v4 )
      {
        gdwProcessIdSelected = pItem->dwProcessId;
        UpdateMenuStatus(1, 3);
        v5 = GetMenu(ghMainWnd);
        v6 = v3->ProcessBasePriority;
        v7 = v5;
        hMnua = v5;
        if ( v6 == 4 && !v3->m_ProcessIoPriority )
          v6 = 0;
        sub_FFEF00(v5, v6);
        v16 = 2;
        v15 = 2;
        SendMessageW(ghWndDllsListCtrl, 0x102Bu, 0, &v14);
        v16 = 2;
        v15 = 2;
        SendMessageW(ghWndHandlesListCtrl, 0x102Bu, 0, &v14);
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
    if ( v2 == 1 && v20 & 2 )
    {
      UpdateMenuStatus(1, 5);
      return 0;
    }
    UpdateMenuStatus(0, 5);
  }
  return 0;
}
// 103E398: using guessed type wchar_t aREsume[8];
// 103E3BC: using guessed type wchar_t aUnHide[8];

//----- (00FBF750) --------------------------------------------------------
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
              if ( sub_1001C10(v9->m_ItemData1) )
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
// 103E374: using guessed type wchar_t aCheckVirustota[18];

//----- (00FBF9E0) --------------------------------------------------------
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
// 106A8F8: using guessed type char gbBitmapOnRight;

//----- (00FBFAA0) --------------------------------------------------------
LRESULT __cdecl sub_FBFAA0(HWND hWnd)
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
  byte_10653B5 = 1;
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
    byte_10653B5 = 0;
    v4 = !gConfig.bShowProcessTree || SendMessageW(v2, 0x100Cu, 0xFFFFFFFF, 2) == -1;
    v5 = v4;
    v6 = GetMenu(ghMainWnd);
    EnableMenuItem(v6, 0x9C6Cu, v5);
  }
  return SendMessageW(v2, 0xBu, 1u, 0);
}
// 10653B5: using guessed type char byte_10653B5;

//----- (00FBFC20) --------------------------------------------------------
BOOL __stdcall DlgColumnSets(HWND hWndIn, UINT msg, WPARAM nID, NMLVDISPINFOW *lParam)
{
  HWND hWndList; // edi
  int nCurItem; // ebx
  tagTREEVIEWITEMPARAM *v6; // ecx
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
  tagTREEVIEWITEMPARAM *Index; // esi
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
// 1069E70: using guessed type char sbEditFlags;
// FBFF58: user specified stroff has not been processed: CRegVar offset 1524

//----- (00FC02A0) --------------------------------------------------------
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
// 103CDC0: using guessed type double db_onehundred;

//----- (00FC0490) --------------------------------------------------------
HCURSOR __cdecl CMainWnd::GetDynamicCursor(int a1, int nIndex)
{
  int v2; // eax
  HCURSOR result; // eax

  if ( gConfig.dwProcessColumnMap[nIndex] == IDS_VIRUSTOTAL
    && (CTreeList::GetTreeList(ghWndTreeListView), v2 = sub_F9E5D0(a1), sub_1001820(*(v2 + 0x34C))) )
  {
    result = LoadCursorW(ghInstance, L"HAND");
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00FC04F0) --------------------------------------------------------
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
// 106A389: using guessed type char gbMainWndMinimized;

//----- (00FC05A0) --------------------------------------------------------
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

//----- (00FC08A0) --------------------------------------------------------
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
// 103EA50: using guessed type RECT gIntArray;
// 105E10C: using guessed type int gdwRefreshMenuIDLast;
// FC08A0: using guessed type LPARAM arrIDs[4];
