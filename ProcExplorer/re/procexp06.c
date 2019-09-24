//----- (00C29980) --------------------------------------------------------
BOOL __cdecl PE_SelectFont(HWND hWnd)
{
  HDC v1; // ebx
  struct tagCHOOSEFONTW ChooseFont; // [esp+Ch] [ebp-DCh]
  HWND v4; // [esp+48h] [ebp-A0h]
  LOGFONTW lf; // [esp+4Ch] [ebp-9Ch]
  WINDOWPLACEMENT wndpl; // [esp+A8h] [ebp-40h]
  struct tagRECT Rect; // [esp+D4h] [ebp-14h]

  v4 = hWnd;
  v1 = GetDC(hWnd);
  qmemcpy(&lf, &gConfig.UnicodeFont, sizeof(lf));
  ChooseFont.hDC = CreateCompatibleDC(v1);
  ReleaseDC(hWnd, v1);
  ChooseFont.lStructSize = 60;
  ChooseFont.lpLogFont = &lf;
  ChooseFont.hInstance = ghInstance;
  ChooseFont.nFontType = 0x2000;
  ChooseFont.hwndOwner = hWnd;
  ChooseFont.Flags = 0x2051;
  ChooseFont.rgbColors = 0;
  ChooseFont.lCustData = 0;
  ChooseFont.lpszStyle = 0;
  ChooseFont.nSizeMin = 0;
  ChooseFont.nSizeMax = 20;
  ChooseFont.lpfnHook = 0;
  ChooseFont.lpTemplateName = (LPCWSTR)1543;
  if ( ChooseFontW(&ChooseFont) )
  {
    qmemcpy(&gConfig.UnicodeFont, &lf, sizeof(gConfig.UnicodeFont));
    DeleteObject(ghConfigFont);
    ghConfigFont = CreateFontIndirectW(&gConfig.UnicodeFont);
    lf.lfUnderline = 1;
    ghConfigUnderlineFont = CreateFontIndirectW(&lf);
    CTreeList::InitListCtrl(ghWndTreeListView, (WPARAM)ghConfigFont);
    CTreeList::InitListCtrl(ghWndDllsListCtrl, (WPARAM)ghConfigFont);
    CTreeList::InitListCtrl(ghWndHandlesListCtrl, (WPARAM)ghConfigFont);
    GetWindowRect(ghMainWnd, &Rect);
    SetWindowPos(ghMainWnd, 0, Rect.left, Rect.top, Rect.right - Rect.left - 1, Rect.bottom - Rect.top, SWP_NOZORDER);
    SetWindowPos(ghMainWnd, 0, Rect.left, Rect.top, Rect.right - Rect.left, Rect.bottom - Rect.top, SWP_NOZORDER);
    if ( ghFindDlg )
    {
      EndDialog(ghFindDlg, 0);
      ghFindDlg = 0;
    }
    wndpl.flags = 0;
    wndpl.length = 44;
    GetWindowPlacement(hWnd, &wndpl);
    if ( wndpl.showCmd == SW_MAXIMIZE )
    {
      ShowWindow(hWnd, SW_RESTORE);
      ShowWindow(hWnd, SW_SHOWMAXIMIZED);
    }
  }
  return DeleteDC(ChooseFont.hDC);
}

//----- (00C29BB0) --------------------------------------------------------
LRESULT __cdecl ProcPageInitList(HWND hWnd, LONG dwNewLong, UINT *pnIDs, WORD *pnWidths, char fSortable)
{
  LONG v5; // eax
  HWND v6; // eax
  LRESULT result; // eax
  struct _IMAGELIST *v8; // esi
  LONG v9; // eax

  v5 = GetWindowLongW(hWnd, GWL_STYLE);
  SetWindowLongW(hWnd, -16, v5 & 0xFFFFFFFD | 9);
  SetWindowLongW(hWnd, -21, dwNewLong);
  SendMessageW(hWnd, LVM_SETEXTENDEDLISTVIEWSTYLE, 0x4020u, 0x4020);
  v6 = (HWND)SendMessageW(hWnd, LVM_GETTOOLTIPS, 0, 0);
  CTreeList::InitToolTips(v6);
  result = InitListHeader(hWnd, pnIDs, pnWidths, dwNewLong);
  if ( fSortable )
  {
    v8 = InitSortableImageList();
    v9 = GetWindowLongW(hWnd, -16);
    SetWindowLongW(hWnd, -16, v9 | LVS_SHAREIMAGELISTS);
    result = SendMessageW(hWnd, LVM_SETIMAGELIST, 1u, (LPARAM)v8);
  }
  return result;
}

//----- (00C29C50) --------------------------------------------------------
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

//----- (00C29C80) --------------------------------------------------------
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
  struct tagPOINT lParam_1; // [esp+9Ch] [ebp-61C4h]
  int v64; // [esp+A4h] [ebp-61BCh]
  int rcItem; // [esp+ACh] [ebp-61B4h]
  unsigned int v66; // [esp+B0h] [ebp-61B0h]
  LONG v67; // [esp+B4h] [ebp-61ACh]
  LONG v68; // [esp+B8h] [ebp-61A8h]
  struct tagRECT Rect; // [esp+BCh] [ebp-61A4h]
  struct tagRECT rc; // [esp+CCh] [ebp-6194h]
  LPARAM arrIDs[96]; // [esp+DCh] [ebp-6184h]
  WCHAR szText[8192]; // [esp+25Ch] [ebp-6004h]
  WCHAR chText[4096]; // [esp+425Ch] [ebp-2004h]

  hWnd_1 = hWnd;
  v5 = lParamIn;
  wParam_2 = (HDC)wParamIn;
  hWndNewOwner = hWnd;
  lParam_2 = lParamIn;
  item.mask = 0;
  memset(&item.iItem, 0, 0x30u);
  if ( Msg > WM_NOTIFY )
  {
    if ( Msg == WM_KEYDOWN )
    {
      switch ( (unsigned int)wParam_2 )
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
          SendMessageW(hWndList, LVM_SETITEMSTATE, item.iItem, (LPARAM)&Item);
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
            CMainWnd::HandleNmDblClk(nID);
          return 0;
        case VK_END:
          Item.stateMask = 3;
          Item.state = 3;
          nCount = SendMessageW(hWnd, LVM_GETITEMCOUNT, 0, 0);
          SendMessageW(hWnd, LVM_SETITEMSTATE, nCount - 1, (LPARAM)&Item);
          v51 = SendMessageW(hWnd, LVM_GETITEMCOUNT, 0, 0);
          SendMessageW(hWnd, LVM_ENSUREVISIBLE, v51 - 1, 0);
          return 0;
        case VK_HOME:
          Item.stateMask = 3;
          Item.state = 3;
          SendMessageW(hWnd, LVM_SETITEMSTATE, 0, (LPARAM)&Item);
          SendMessageW(hWnd, LVM_ENSUREVISIBLE, 0, 0);
          return 0;
        case VK_CANCEL|0x40:
          if ( hWnd != ghWndTreeListView && GetKeyState(VK_LCONTROL) )
          {
            pUserData = GetWindowLongW(hWnd, GWLP_USERDATA);
            nItemCount = pUserData;
            if ( !SendMessageW(hWnd, LVM_GETCOLUMNORDERARRAY, pUserData, (LPARAM)arrIDs) )
            {
              nIndex = 0;
              if ( pUserData )
              {
                if ( pUserData >= 8 )
                {
                  v36 = _mm_load_si128((const __m128i *)&gIntArray);
                  v37 = &arrIDs[4];
                  do
                  {
                    v38 = nIndex + 4;
                    v37 += 8;
                    v39 = _mm_add_epi32(_mm_shuffle_epi32(_mm_cvtsi32_si128(nIndex), 0), v36);
                    nIndex += 8;
                    _mm_storeu_si128((__m128i *)v37 - 3, v39);
                    _mm_storeu_si128(
                      (__m128i *)v37 - 2,
                      _mm_add_epi32(_mm_shuffle_epi32(_mm_cvtsi32_si128(v38), 0), v36));
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
                  SendMessageW(hWndNewOwner, LVM_GETITEMTEXTW, nItem_1, (LPARAM)&Item);
                  nLength += wcslen(szText) + 2;
                  if ( pBuffer )
                  {
                    GlobalUnlock(hGlobal);
                    hGlobal = GlobalReAlloc(hGlobal, 2 * nLength + 2, 0);
                    pBuffer = (wchar_t *)GlobalLock(hGlobal);
                  }
                  else
                  {
                    hGlobal = GlobalAlloc(0x2002u, 2 * nLength + 2);
                    pBuffer = (wchar_t *)GlobalLock(hGlobal);
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
          SendMessageW(hWndParent, WM_KEYDOWN, (WPARAM)wParam_3, v5);
          break;
      }
    }
    else if ( Msg == WM_MOUSEMOVE )
    {
      if ( gdwVersion < 1 )
      {
        hWndTooltips = (HWND)SendMessageW(hWnd, LVM_GETTOOLTIPS, 0, 0);
        if ( !IsWindowVisible(hWndTooltips)
          || (Point.x = (signed __int16)lParamIn,
              Point.y = SHIWORD(lParamIn),
              SendMessageW(hWnd, LVM_SUBITEMHITTEST, 0, (LPARAM)&Point) >= 0)
          && (v31 = GetPropW(hWnd, L"hitrow"), (HANDLE)wParam_1 != v31) )
        {
          hWndTooltips_1 = (HWND)SendMessageW(hWnd, LVM_GETTOOLTIPS, 0, 0);
          SendMessageW(hWndTooltips_1, TTM_POP, 0, 0);
        }
      }
      if ( hWnd == ghWndDllsListCtrl )
      {
        GetCursorPos(&Point);
        ScreenToClient(hWnd, &Point);
        if ( SendMessageW(hWnd, LVM_SUBITEMHITTEST, 0, (LPARAM)&Point) >= 0
          && gConfig.dwDllColumnMap[wParam_1] == IDS_VIRUSTOTAL )
        {
          item.iItem = uMsg;
          item.mask = LVIF_PARAM;
          SendMessageW(hWnd, LVM_GETITEMW, 0, (LPARAM)&item);
          if ( sub_C71820((ListItemData1 *)item.lParam->field_16C) )
          {
            hCursor = LoadCursorW(ghInstance, L"HAND");
            SetCursor(hCursor);
          }
        }
      }
    }
    return CallWindowProcW(gOldListWndProc, hWnd_1, Msg, (WPARAM)wParam_2, v5);
  }
  if ( Msg != WM_NOTIFY )
  {
    switch ( Msg )
    {
      case WM_SETFOCUS:
      case WM_KILLFOCUS:
        if ( hWnd == ghWndTreeListView && wParam_2 != (HDC)ghWndTreeListView )
          RefreshTreeView();
        return CallWindowProcW(gOldListWndProc, hWnd_1, Msg, (WPARAM)wParam_2, v5);
      case WM_ERASEBKGND:
        if ( !SendMessageW(hWnd, LVM_GETITEMCOUNT, 0, 0) )
          return CallWindowProcW(gOldListWndProc, hWnd_1, Msg, (WPARAM)wParam_2, v5);
        GetClientRect(hWnd, &Rect);
        rcItem = 0;
        nItemCount_1 = SendMessageW(hWnd, LVM_GETITEMCOUNT, 0, 0);
        SendMessageW(hWnd, LVM_GETITEMRECT, nItemCount_1 - 1, (LPARAM)&rcItem);
        rc.left = v67;
        hBrush = GetSysColorBrush(COLOR_WINDOW);
        FillRect(wParam_2, &rc, hBrush);
        rc = Rect;
        *(_QWORD *)&rc.right = *(_QWORD *)&Rect.right;
        rc.top = v68;
        hBrush_1 = GetSysColorBrush(COLOR_WINDOW);
        FillRect(wParam_2, &rc, hBrush_1);
        rcItem = 0;
        nTopIndex = SendMessageW(hWnd, LVM_GETTOPINDEX, 0, 0);
        SendMessageW(hWnd, LVM_GETITEMRECT, nTopIndex, (LPARAM)&rcItem);
        *(_QWORD *)&rc.right = __PAIR__(v66, Rect.right);
        *(_QWORD *)&rc.left = 0i64;
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
            v7 = LoadCursorW(0, (LPCWSTR)IDC_APPSTARTING);
          else
            v7 = LoadCursorW(0, (LPCWSTR)IDC_ARROW);
          SetCursor(v7);
          result = 1;
        }
        return result;
      default:
        return CallWindowProcW(gOldListWndProc, hWnd_1, Msg, (WPARAM)wParam_2, v5);
    }
    return CallWindowProcW(gOldListWndProc, hWnd_1, Msg, (WPARAM)wParam_2, v5);
  }
  // WM_NOTIFY
  if ( *(_DWORD *)lParamIn != SendMessageW(hWnd, LVM_GETTOOLTIPS, 0, 0) )
    return CallWindowProcW(gOldListWndProc, hWnd_1, Msg, (WPARAM)wParam_2, v5);
  code = *(_DWORD *)(lParamIn + 8);
  if ( code != TTN_GETDISPINFOW )
  {
    if ( code == TTN_SHOW )
    {
      v14 = -1;
      if ( gdwVersion >= 1 )
        v14 = -4;
      GetCursorPos(&Point);
      ScreenToClient(hWnd, &Point);
      item.iItem = SendMessageW(hWnd, LVM_SUBITEMHITTEST, 0, (LPARAM)&Point);
      if ( item.iItem != -1 && wParam_1 != -1 )
      {
        sub_C2A880(hWnd, uMsg, wParam_1, (#153 *)&lParam_1);
        Point = lParam_1;
        ClientToScreen(hWnd, &Point);
        v15 = Point.y - 1;
        v16 = v14 + Point.x;
        v17 = (HWND)SendMessageW(hWnd, LVM_GETTOOLTIPS, 0, 0);
        SetWindowPos(v17, 0, v16, v15, 0, 0, SWP_NOACTIVATE|SWP_NOSIZE);
        return 1;
      }
      v18 = Point.y - 1;
      v19 = v14 + Point.x;
      v20 = (HWND)SendMessageW(hWnd, LVM_GETTOOLTIPS, 0, 0);
      SetWindowPos(v20, 0, v19, v18, 0, 0, SWP_NOACTIVATE);
      v5 = lParam_2;
    }
    return CallWindowProcW(gOldListWndProc, hWnd_1, Msg, (WPARAM)wParam_2, v5);
  }
  if ( gdwVersion >= 1 )
    return CallWindowProcW(gOldListWndProc, hWnd_1, Msg, (WPARAM)wParam_2, v5);
  nRet = CallWindowProcW(gOldListWndProc, hWnd, WM_NOTIFY, (WPARAM)wParam_2, lParamIn);
  GetCursorPos(&Point);
  ScreenToClient(hWnd, &Point);
  if ( SendMessageW(hWnd, LVM_SUBITEMHITTEST, 0, (LPARAM)&Point) < 0 || !(v60 & 0xE) || (wParam_1 & 0x80000000) != 0 )
    return nRet;
  item.iSubItem = wParam_1;
  item.iItem = uMsg;
  item.mask = 1;
  item.pszText = chText;
  item.cchTextMax = 4096;
  SendMessageW(hWnd, LVM_GETITEMW, 0, (LPARAM)&item);
  if ( !chText[0] )
  {
    v29 = lParam_2;
    *(_DWORD *)(lParam_2 + 12) = 0;
    *(_WORD *)(v29 + 16) = 0;
    return nRet;
  }
  Item.pszText = (LPWSTR)2;
  SendMessageW(hWnd, LVM_GETCOLUMNW, wParam_1, (LPARAM)&Item.pszText);
  _mm_storeu_si128((__m128i *)&lParam_1, (__m128i)0i64);
  v22 = GetDC(hWnd);
  SelectObject(v22, ghConfigFont);
  DrawTextW(v22, chText, -1, (LPRECT)&lParam_1, 0xD00u);
  v23 = v64 - lParam_1.x + 6;
  v26 = __OFSUB__(v23, Item.iImage);
  v24 = v23 == Item.iImage;
  v25 = v23 - Item.iImage < 0;
  v27 = lParam_2;
  if ( (unsigned __int8)(v25 ^ v26) | v24 )
  {
    *(_DWORD *)(lParam_2 + 12) = 0;
    *(_WORD *)(v27 + 16) = 0;
  }
  else
  {
    v28 = (void *)wParam_1;
    *(_DWORD *)(lParam_2 + 12) = chText;
    SetPropW(hWnd, L"hitrow", v28);
  }
  ReleaseDC(hWnd, v22);
  return nRet;
}
// CAEA50: using guessed type tagRECT gIntArray;
// CD4E54: using guessed type int gdwVersion;

//----- (00C2A880) --------------------------------------------------------
LRESULT __cdecl sub_C2A880(HWND hWnd, WPARAM uMsg, WPARAM wParam_1, #153 *lParam_1)
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
  #153 *rect; // eax
  unsigned int index; // eax
  #153 *v18; // eax
  #153 *v19; // eax
  HWND hWnd_1; // [esp+Ch] [ebp-188h]
  LPARAM arrIDs[96]; // [esp+10h] [ebp-184h]

  hwnd = hWnd;
  SendMessageW = (void (__stdcall *)(HWND, UINT, WPARAM, LPARAM))::SendMessageW;
  hWnd_1 = hWnd;
  bRet = ::SendMessageW(hWnd, LVM_GETCOLUMNORDERARRAY, gConfig.dwProcessColumnCount, (LPARAM)arrIDs);
  dwProcessColumnCount_1 = gConfig.dwProcessColumnCount;
  if ( !bRet )
  {
    dwColumnCount = 0;
    if ( gConfig.dwProcessColumnCount > 0 )
    {
      if ( gConfig.dwProcessColumnCount >= 8u )
      {
        v9 = _mm_load_si128((const __m128i *)&gIntArray);
        v10 = &arrIDs[4];
        dwProcessColumnCount = gConfig.dwProcessColumnCount - gConfig.dwProcessColumnCount % 8;
        do
        {
          v12 = dwColumnCount + 4;
          v10 += 8;
          v13 = _mm_add_epi32(_mm_shuffle_epi32(_mm_cvtsi32_si128(dwColumnCount), 0), v9);
          dwColumnCount += 8;
          _mm_storeu_si128((__m128i *)v10 - 3, v13);
          _mm_storeu_si128((__m128i *)v10 - 2, _mm_add_epi32(_mm_shuffle_epi32(_mm_cvtsi32_si128(v12), 0), v9));
        }
        while ( dwColumnCount < dwProcessColumnCount );
        hwnd = hWnd_1;
        SendMessageW = (void (__stdcall *)(HWND, UINT, WPARAM, LPARAM))::SendMessageW;
      }
      for ( ; dwColumnCount < dwProcessColumnCount_1; ++dwColumnCount )
        arrIDs[dwColumnCount] = dwColumnCount;
    }
  }
  if ( uMsg == -2 )
  {
    v14 = CTreeList::GetTreeList(hwnd);
    CTreeList::HeaderToClient(v14, wParam_1, (RECT *)lParam_1);
    *((_DWORD *)lParam_1 + 3) -= *((_DWORD *)lParam_1 + 1);
    result = *(_DWORD *)lParam_1;
    *((_DWORD *)lParam_1 + 2) -= *(_DWORD *)lParam_1;
  }
  else if ( wParam_1 )
  {
    if ( lParam_1 )
    {
      *((_DWORD *)lParam_1 + 1) = wParam_1;
      rect = lParam_1;
      *(_DWORD *)lParam_1 = 0;
    }
    else
    {
      rect = 0;
    }
    SendMessageW(hwnd, LVM_GETSUBITEMRECT, uMsg, (LPARAM)rect);
    *((_DWORD *)lParam_1 + 3) -= *((_DWORD *)lParam_1 + 1);
    result = *(_DWORD *)lParam_1;
    *((_DWORD *)lParam_1 + 2) -= *(_DWORD *)lParam_1;
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
        *(_DWORD *)lParam_1 = 0;
        result = ((LRESULT (__stdcall *)(HWND, UINT, WPARAM, LPARAM))SendMessageW)(
                   hwnd,
                   LVM_GETITEMRECT,
                   uMsg,
                   (LPARAM)lParam_1);
      }
      else
      {
        result = ((LRESULT (__stdcall *)(HWND, UINT, WPARAM, LPARAM))SendMessageW)(hwnd, LVM_GETITEMRECT, uMsg, 0);
      }
    }
    else if ( index )
    {
      if ( lParam_1 )
      {
        *((_DWORD *)lParam_1 + 1) = *(&hWnd_1 + index);
        v18 = lParam_1;
        *(_DWORD *)lParam_1 = 0;
      }
      else
      {
        v18 = 0;
      }
      SendMessageW(hwnd, LVM_GETSUBITEMRECT, uMsg, (LPARAM)v18);
      *(_DWORD *)lParam_1 = *((_DWORD *)lParam_1 + 2);
      result = ((LRESULT (__stdcall *)(HWND, UINT, WPARAM, LPARAM))SendMessageW)(hwnd, LVM_GETCOLUMNWIDTH, 0, 0);
      *((_DWORD *)lParam_1 + 2) = result;
    }
    else
    {
      if ( lParam_1 )
      {
        *((_DWORD *)lParam_1 + 1) = 1;
        v19 = lParam_1;
        *(_DWORD *)lParam_1 = 0;
      }
      else
      {
        v19 = 0;
      }
      SendMessageW(hwnd, LVM_GETSUBITEMRECT, uMsg, (LPARAM)v19);
      *((_DWORD *)lParam_1 + 3) -= *((_DWORD *)lParam_1 + 1);
      result = ((LRESULT (__stdcall *)(HWND, UINT, WPARAM, LPARAM))SendMessageW)(hwnd, LVM_GETCOLUMNWIDTH, 0, 0);
      *(_DWORD *)lParam_1 = 0;
      *((_DWORD *)lParam_1 + 2) = result;
    }
  }
  return result;
}
// CAEA50: using guessed type tagRECT gIntArray;

//----- (00C2AB00) --------------------------------------------------------
BOOL __cdecl CTreeList::InitListCtrl(HWND hWnd, WPARAM wParam)
{
  HWND v2; // eax
  struct tagRECT Rect; // [esp+Ch] [ebp-14h]

  v2 = (HWND)SendMessageW(hWnd, LVM_GETHEADER, 0, 0);
  SendMessageW(v2, 0x30u, wParam, 0);
  SendMessageW(hWnd, 0x30u, wParam, 0);
  GetClientRect(ghMainWnd, &Rect);
  CMainWnd::HandleSize(
    ghMainWnd,
    0,
    0,
    (unsigned __int16)(LOWORD(Rect.right) - LOWORD(Rect.left)) | ((unsigned __int16)(LOWORD(Rect.bottom)
                                                                                   - LOWORD(Rect.top)) << 16));
  return InvalidateRgn(hWnd, 0, 1);
}

//----- (00C2ABA0) --------------------------------------------------------
int __stdcall BackendSortCallback(int a1, int a2, tagSortParam *pSortParam)
{
  _DWORD *v3; // esi
  signed int v4; // ebx
  int uID; // ecx
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
  signed int dwColumnID; // eax
  int v62; // eax
  int v63; // eax
  int v64; // eax
  unsigned int v65; // eax
  unsigned int v66; // ecx
  __int32 v67; // eax
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

  v3 = (_DWORD *)a1;
  v4 = 0;
  uID = pSortParam->nID;
  v140 = (LPCWSTR)a1;
  v6 = (_DWORD *)a2;
  if ( uID != 101 )
  {
    if ( uID == IDC_LISTCTRL_HANDLES )
    {
      dwColumnID = gConfig.dwIdsOfHandleColumnMap[pSortParam->dwSortColumn];
      if ( dwColumnID > 39 )
      {
        v67 = dwColumnID - IDC_DLG_HANDLE_COLUMNS_CHECKBOX_OBJECT_ADDRESS;
        if ( !v67 )
        {
          v4 = *(_DWORD *)(a1 + 40) - *(_DWORD *)(a2 + 40);
LABEL_274:
          v16 = LOBYTE(gConfig.bHandleSortDirection) == 0;
          goto LABEL_419;
        }
        v68 = v67 - 9;
        if ( !v68 )
        {
          v4 = *(_DWORD *)(a1 + 52) - *(_DWORD *)(a2 + 52);
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
      else if ( dwColumnID != 39 )
      {
        v62 = dwColumnID - 20;
        if ( v62 )
        {
          v63 = v62 - 1;
          if ( v63 )
          {
            if ( v63 == 1 )
            {
              v64 = lstrcmpiW((LPCWSTR)(a1 + 2232), (LPCWSTR)(a2 + 2232));
              v16 = LOBYTE(gConfig.bHandleSortDirection) == 0;
              v4 = v64;
              goto LABEL_419;
            }
            goto LABEL_270;
          }
          v4 = lstrcmpiW((LPCWSTR)(a1 + 56), (LPCWSTR)(a2 + 56));
          if ( !v4 )
          {
            v4 = *(_DWORD *)(a2 + 44) < *(_DWORD *)(a1 + 44) ? 1 : -1;
            v16 = LOBYTE(gConfig.bHandleSortDirection) == 0;
            goto LABEL_419;
          }
          goto LABEL_274;
        }
        v65 = *(_DWORD *)(a1 + 44);
        v66 = *(_DWORD *)(a2 + 44);
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
      v4 = *(_DWORD *)(a1 + 48) - *(_DWORD *)(a2 + 48);
      v16 = LOBYTE(gConfig.bHandleSortDirection) == 0;
      goto LABEL_419;
    }
    if ( uID == IDC_LISTCTRL_DLLS )
    {
      v69 = gConfig.dwDllColumnMap[pSortParam->dwSortColumn];
      if ( v69 <= 30 )
      {
        if ( v69 != 30 )
        {
          switch ( v69 )
          {
            case 23:
              v70 = *(_DWORD *)(a1 + 36);
              v71 = *(_DWORD *)(a2 + 36);
              v72 = v70 < v71;
              if ( v70 <= v71 )
                goto LABEL_281;
              v16 = LOBYTE(gConfig.bDllSortDirection) == 0;
              v4 = 1;
              break;
            case 24:
              v4 = *(_DWORD *)(a1 + 56) - *(_DWORD *)(a2 + 56);
              v16 = LOBYTE(gConfig.bDllSortDirection) == 0;
              break;
            case 25:
              v73 = lstrcmpiW((LPCWSTR)(a1 + 206), (LPCWSTR)(a2 + 206));
              v16 = LOBYTE(gConfig.bDllSortDirection) == 0;
              v4 = v73;
              break;
            case 26:
              if ( wcsrchr(*(const wchar_t **)(a1 + 344), 0x5Cu) )
                v74 = wcsrchr(*(const wchar_t **)(a1 + 344), 0x5Cu) + 1;
              else
                v74 = *(const wchar_t **)(a1 + 344);
              wcscpy_s(&String1, 0x104u, v74);
              if ( wcsrchr(*(const wchar_t **)(a2 + 344), 0x5Cu) )
                v75 = wcsrchr(*(const wchar_t **)(a2 + 344), 0x5Cu) + 1;
              else
                v75 = *(const wchar_t **)(a2 + 344);
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
        v77 = *(_DWORD *)(a1 + 64);
        v78 = *(_DWORD *)(a1 + 68);
        v79 = *(_DWORD *)(a2 + 64);
        v80 = *(_DWORD *)(a2 + 68);
        if ( v77 == v79 && v78 == v80 )
        {
          v4 = 0;
          v16 = LOBYTE(gConfig.bDllSortDirection) == 0;
          goto LABEL_419;
        }
        v81 = __PAIR__(v78, v77) - __PAIR__(v80, v79);
        v137 = (__PAIR__(v78, v77) - __PAIR__(v80, v79)) >> 32;
        if ( v137 >= 0
          && ((signed __int64)__PAIR__(v78, v77) >= (signed __int64)__PAIR__(v80, v79) && HIDWORD(v81) != 0
           || (_DWORD)v81) )
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
            v98 = *(_DWORD *)(a1 + 364);
            if ( v98 )
            {
              v99 = *(_DWORD *)(a2 + 364);
              if ( v99 )
              {
                v100 = *(_DWORD *)(v98 + 4);
                if ( v100 != 1 || *(_DWORD *)(v99 + 4) != 1 )
                {
                  v4 = v100 - *(_DWORD *)(v99 + 4);
                  v16 = LOBYTE(gConfig.bDllSortDirection) == 0;
                  goto LABEL_419;
                }
                v137 = *(_DWORD *)(v98 + 4);
                v138 = 1;
                lpString1 = (LPCWSTR)-1;
                v140 = (LPCWSTR)-1;
                v101 = *(wchar_t ***)(v98 + 40);
                if ( v101 )
                  v102 = *v101;
                else
                  v102 = 0;
                scan_fn(v102, (int)L"%d/%d", (int)&v137);
                v103 = *(wchar_t ***)(*(_DWORD *)(a2 + 364) + 40);
                if ( v103 )
                  v104 = *v103;
                else
                  v104 = 0;
                scan_fn(v104, (int)L"%d/%d", (int)&v138);
                v87 = v137;
                v86 = v138;
                if ( v137 == v138 )
                {
                  v4 = (char *)lpString1 - (char *)v140;
                  v16 = LOBYTE(gConfig.bDllSortDirection) == 0;
                  goto LABEL_419;
                }
                goto LABEL_308;
              }
            }
            v92 = sub_C337B0(v98, *(signed int *)(a2 + 364));
            goto LABEL_350;
          }
          if ( v69 == 40757 )
          {
            v4 = (*(_WORD *)(a1 + 54) & 0x4000) - (*(_WORD *)(a2 + 54) & 0x4000);
            if ( (*(_WORD *)(a1 + 54) & 0x4000) == (*(_WORD *)(a2 + 54) & 0x4000) )
            {
              if ( *(_WORD *)(a1 + 54) )
                v4 = *(_WORD *)(a2 + 54) == 0;
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
            v97 = lstrcmpiW(*(LPCWSTR *)(a1 + 348), *(LPCWSTR *)(a2 + 348));
            v16 = LOBYTE(gConfig.bDllSortDirection) == 0;
            v4 = v97;
            goto LABEL_419;
          }
          v94 = v69 - 1187;
          if ( !v94 )
          {
            v96 = lstrcmpiW(*(LPCWSTR *)(a1 + 356), *(LPCWSTR *)(a2 + 356));
            v16 = LOBYTE(gConfig.bDllSortDirection) == 0;
            v4 = v96;
            goto LABEL_419;
          }
          v95 = v94 - 130;
          if ( !v95 )
          {
            v92 = sub_C337B0(*(unsigned int *)(a1 + 376), *(unsigned int *)(a2 + 376));
            goto LABEL_350;
          }
          if ( v95 == 21 )
          {
            v4 = (*(_WORD *)(a1 + 54) & 0x40) - (*(_WORD *)(a2 + 54) & 0x40);
            if ( (*(_WORD *)(a1 + 54) & 0x40) == (*(_WORD *)(a2 + 54) & 0x40) )
            {
              v4 = ((*(_DWORD *)(a2 + 44) >> 1) & 1) - ((*(_DWORD *)(a1 + 44) >> 1) & 1);
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
          v92 = sub_C337B0(*(unsigned int *)(a1 + 380), *(unsigned int *)(a2 + 380));
          goto LABEL_350;
        }
        if ( v69 <= 1074 )
        {
          if ( v69 == 1074 )
          {
            v88 = *(_DWORD *)(a1 + 48);
            v89 = *(_DWORD *)(a2 + 48);
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
              v85 = lstrcmpiW(*(LPCWSTR *)(a1 + 336), *(LPCWSTR *)(a2 + 336));
              v16 = LOBYTE(gConfig.bDllSortDirection) == 0;
              v4 = v85;
              goto LABEL_419;
            }
            if ( v83 == 991 )
            {
              v84 = lstrcmpiW(*(LPCWSTR *)(a1 + 340), *(LPCWSTR *)(a2 + 340));
              v16 = LOBYTE(gConfig.bDllSortDirection) == 0;
              v4 = v84;
              goto LABEL_419;
            }
            goto LABEL_330;
          }
          v86 = (*(_DWORD *)(a2 + 44) >> 1) & 1;
          v87 = (*(_DWORD *)(a1 + 44) >> 1) & 1;
LABEL_308:
          v4 = v87 - v86;
          v16 = LOBYTE(gConfig.bDllSortDirection) == 0;
          goto LABEL_419;
        }
        v90 = v69 - 1111;
        if ( !v90 )
        {
          v93 = lstrcmpiW(*(LPCWSTR *)(a1 + 344), *(LPCWSTR *)(a2 + 344));
          v16 = LOBYTE(gConfig.bDllSortDirection) == 0;
          v4 = v93;
          goto LABEL_419;
        }
        v91 = v90 - 4;
        if ( !v91 )
        {
          v92 = sub_C337B0(*(unsigned int *)(a1 + 368), *(unsigned int *)(a2 + 368));
          goto LABEL_350;
        }
        if ( v91 == 1 )
        {
          v92 = sub_C337B0(*(unsigned int *)(a1 + 372), *(unsigned int *)(a2 + 372));
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
    if ( uID != 1040 )
    {
      if ( uID == IDC_PAGE_PROCTHREADS_LISTCTRL )
      {
        v107 = pSortParam->dwSortColumn;
        switch ( v107 )
        {
          case 0:
            v4 = *(_DWORD *)(a1 + 44) - *(_DWORD *)(a2 + 44);
            v16 = byte_CD53B4 == 0;
            goto LABEL_419;
          case 1:
            v108 = *(double *)(a1 + 576);
            if ( v108 != 0.0 || v108 != *(double *)(a2 + 576) )
            {
              v116 = *(double *)(a2 + 576);
              if ( v108 <= v116 )
              {
                v4 = (v116 <= v108) - 1;
                v16 = byte_CD53B4 == 0;
              }
              else
              {
                v16 = byte_CD53B4 == 0;
                v4 = 1;
              }
              goto LABEL_419;
            }
            v109 = *(_DWORD *)(a1 + 604);
            v110 = *(_DWORD *)(a2 + 604);
            v111 = *(_DWORD *)(a1 + 600);
            v112 = *(_DWORD *)(a2 + 600);
            if ( v109 < v110 )
              goto LABEL_377;
            if ( v109 > v110 )
              goto LABEL_375;
            if ( v111 > v112 )
            {
              v16 = byte_CD53B4 == 0;
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
                v16 = byte_CD53B4 == 0;
                goto LABEL_419;
              }
LABEL_372:
              v113 = *(_DWORD *)(a1 + 584);
              v114 = *(_DWORD *)(a1 + 588);
              v115 = *(_QWORD *)(a2 + 584);
              if ( v114 >= SHIDWORD(v115) )
              {
                if ( v114 > SHIDWORD(v115) || v113 > (unsigned int)v115 )
                {
LABEL_375:
                  v16 = byte_CD53B4 == 0;
                  v4 = 1;
                  goto LABEL_419;
                }
                if ( __PAIR__(v114, v113) >= v115 )
                {
                  v4 = 0;
                  v16 = byte_CD53B4 == 0;
                  goto LABEL_419;
                }
              }
            }
LABEL_377:
            v4 = -1;
            v16 = byte_CD53B4 == 0;
            goto LABEL_419;
          case 2:
            if ( QueryThreadCycleTime && *(_DWORD *)(a1 + 40) )
            {
              v4 = sub_C337B0(*(_QWORD *)(a1 + 600), *(_QWORD *)(a2 + 600));
              v16 = byte_CD53B4 == 0;
            }
            else
            {
              v4 = *(_DWORD *)(a1 + 584) - *(_DWORD *)(a2 + 584);
              v16 = byte_CD53B4 == 0;
            }
            goto LABEL_419;
          case 3:
          case 4:
            if ( *(_DWORD *)(a1 + 644) == -1 )
              goto LABEL_389;
            v117 = v107 - 3;
            if ( v117 )
            {
              if ( v117 != 1 )
                goto LABEL_391;
LABEL_389:
              v118 = _wcsicmp((const wchar_t *)(a1 + 52), (const wchar_t *)(a2 + 52));
            }
            else
            {
              v119 = *(_DWORD *)(a2 + 648);
              if ( !v119 || (v120 = *(const wchar_t **)(a1 + 648)) == 0 )
              {
                v4 = (*(_DWORD *)(a1 + 648) - v119) >> 1;
                v16 = byte_CD53B4 == 0;
                goto LABEL_419;
              }
              v118 = _wcsicmp(v120, *(const wchar_t **)(a2 + 648));
            }
            v4 = v118;
            goto LABEL_391;
          default:
LABEL_391:
            v16 = byte_CD53B4 == 0;
            goto LABEL_419;
        }
      }
      if ( uID != 1192 )
        return v4;
      switch ( pSortParam->dwSortColumn )
      {
        case 0:
          v4 = *(_DWORD *)(a1 + 40) - *(_DWORD *)(a2 + 40);
          if ( *(_DWORD *)(a1 + 40) == *(_DWORD *)(a2 + 40) )
          {
            v121 = ntohl(*(_DWORD *)(a2 + 44));
            v122 = ntohl(*((_DWORD *)v140 + 11));
            v4 = v122 - v121;
            if ( v122 == v121 )
            {
              v123 = ntohs(*(_WORD *)(a2 + 584));
              v124 = ntohs(v140[292]);
              v4 = v124 - v123;
              if ( v124 == v123 )
              {
                v125 = ntohl(*(unsigned __int16 *)(a2 + 1108));
                v126 = ntohl(v140[554]);
                v4 = v126 - v125;
                if ( v126 == v125 )
                {
                  v127 = ntohs(*(_WORD *)(a2 + 1648));
                  v128 = ntohs(v140[824]);
                  v4 = v128 - v127;
                  if ( v128 == v127 )
                    v4 = *((_DWORD *)v140 + 543) - *(_DWORD *)(a2 + 2172);
                }
              }
            }
          }
          break;
        case 1:
          v129 = *(_DWORD *)(a1 + 40);
          v130 = *(_DWORD *)(a2 + 40);
          if ( v129 == v130 )
          {
            if ( *(_DWORD *)(a2 + 44) == *(_DWORD *)(a1 + 44) )
            {
              v131 = ntohs(*(_WORD *)(a2 + 584));
              v4 = ntohs(v140[292]) - v131;
            }
            else
            {
              v132 = ntohl(*(_DWORD *)(a2 + 44));
              v4 = ntohl(*((_DWORD *)v140 + 11)) - v132;
            }
          }
          else
          {
            v4 = v130 - v129;
          }
          break;
        case 2:
          v133 = *(_DWORD *)(a1 + 40);
          v134 = *(_DWORD *)(a2 + 40);
          if ( v133 == v134 )
          {
            if ( *(_DWORD *)(a2 + 1108) != *(_DWORD *)(a1 + 1108) )
            {
              v136 = ntohl(*(_DWORD *)(a2 + 1108));
              goto LABEL_414;
            }
            v135 = ntohs(*(_WORD *)(a2 + 1648));
            v4 = ntohs(v140[824]) - v135;
          }
          else
          {
            v4 = v134 - v133;
          }
          break;
        case 3:
          v4 = *(_DWORD *)(a1 + 2172) - *(_DWORD *)(a2 + 2172);
          if ( *(_DWORD *)(a1 + 2172) == *(_DWORD *)(a2 + 2172) )
          {
            v136 = ntohl(*(_DWORD *)(a2 + 1108));
LABEL_414:
            v4 = ntohl(*((_DWORD *)v140 + 277)) - v136;
          }
          break;
        case 4:
          v4 = _wcsicmp(*(const wchar_t **)(a1 + 2184), *(const wchar_t **)(a2 + 2184));
          break;
        default:
          break;
      }
      v16 = byte_CCD225 == 0;
LABEL_419:
      if ( v16 )
        v4 = -v4;
      return v4;
    }
    v105 = pSortParam->dwSortColumn;
    if ( v105 )
    {
      if ( v105 != 1 )
      {
LABEL_358:
        v16 = byte_CCD224 == 0;
        goto LABEL_419;
      }
      v106 = _wcsicmp(*(const wchar_t **)(a1 + 48), *(const wchar_t **)(a2 + 48));
    }
    else
    {
      v106 = _wcsicmp(*(const wchar_t **)(a1 + 40), *(const wchar_t **)(a2 + 40));
    }
    v4 = v106;
    goto LABEL_358;
  }
  if ( !gConfig.bShowProcessTree )
  {
    v13 = gConfig.dwProcessColumnMap[pSortParam->dwSortColumn];
    if ( v13 <= 1032 )
    {
      if ( v13 != 1032 )
      {
        switch ( v13 )
        {
          case 3:
            v4 = lstrcmpiW(*(LPCWSTR *)(a1 + 60), *(LPCWSTR *)(a2 + 60));
            goto LABEL_253;
          case 4:
            goto LABEL_189;
          case 5:
            v4 = *(_DWORD *)(a1 + 1368) - *(_DWORD *)(a2 + 1368);
            goto LABEL_253;
          case 7:
            v14 = *(double *)(a1 + 1304);
            v15 = *(double *)(a2 + 1304);
            if ( v14 <= v15 )
              goto LABEL_25;
            v16 = gConfig.bProcessSortDirection == 0;
            v4 = 1;
            goto LABEL_419;
          case 9:
            v4 = sub_C337B0(*(unsigned int *)(a1 + 920), *(unsigned int *)(a2 + 920));
            goto LABEL_253;
          case 10:
            v4 = sub_C337B0(*(unsigned int *)(a1 + 924), *(unsigned int *)(a2 + 924));
            goto LABEL_253;
          case 18:
            v4 = *(_DWORD *)(a1 + 92) - *(_DWORD *)(a2 + 92);
            goto LABEL_253;
          case 19:
            v4 = lstrcmpiW(*(LPCWSTR *)(a1 + 88), *(LPCWSTR *)(a2 + 88));
            goto LABEL_253;
          case 25:
            v4 = lstrcmpiW((LPCWSTR)(a1 + 654), (LPCWSTR)(a2 + 654));
            goto LABEL_253;
          case 35:
            v4 = lstrcmpiW((LPCWSTR)(a1 + 104), (LPCWSTR)(a2 + 104));
            goto LABEL_253;
          case 38:
            v4 = lstrcmpiW(*(LPCWSTR *)(a1 + 784), *(LPCWSTR *)(a2 + 784));
            goto LABEL_253;
          default:
            goto LABEL_26;
        }
        goto LABEL_26;
      }
      v4 = lstrcmpiW(*(LPCWSTR *)(a1 + 800), *(LPCWSTR *)(a2 + 800));
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
              v4 = *(_DWORD *)(a1 + 1088) - *(_DWORD *)(a2 + 1088);
              goto LABEL_253;
            case 1611:
              v4 = *(_DWORD *)(a1 + 1104) - *(_DWORD *)(a2 + 1104);
              goto LABEL_253;
            case 1612:
              v4 = *(_DWORD *)(a1 + 1120) - *(_DWORD *)(a2 + 1120);
              goto LABEL_253;
            case 1613:
              v4 = *(_DWORD *)(a1 + 1136) - *(_DWORD *)(a2 + 1136);
              goto LABEL_253;
            case 1614:
              v4 = *(_DWORD *)(a1 + 1152) - *(_DWORD *)(a2 + 1152);
              goto LABEL_253;
            case 1615:
              v4 = sub_C337B0(
                     *(_QWORD *)(a1 + 1096) + *(_QWORD *)(a1 + 1128),
                     *(_QWORD *)(a2 + 1096) + *(_QWORD *)(a2 + 1128));
              goto LABEL_253;
            case 1616:
              v4 = sub_C337B0(*(_QWORD *)(a1 + 1096), *(_QWORD *)(a2 + 1096));
              goto LABEL_253;
            case 1617:
              v4 = sub_C337B0(*(_QWORD *)(a1 + 1080), *(_QWORD *)(a2 + 1080));
              goto LABEL_253;
            case 1618:
              v4 = sub_C337B0(*(_QWORD *)(a1 + 1112), *(_QWORD *)(a2 + 1112));
              goto LABEL_253;
            case 1619:
              v4 = sub_C337B0(*(_QWORD *)(a1 + 1128), *(_QWORD *)(a2 + 1128));
              goto LABEL_253;
            case 1620:
              v4 = sub_C337B0(*(_QWORD *)(a1 + 1144), *(_QWORD *)(a2 + 1144));
              goto LABEL_253;
            case 1621:
              v4 = sub_C337B0(*(_QWORD *)(a1 + 1160), *(_QWORD *)(a2 + 1160));
              goto LABEL_253;
            case 1622:
              v4 = sub_C337B0(*(_QWORD *)(a1 + 1168), *(_QWORD *)(a2 + 1168));
              goto LABEL_253;
            case 1623:
              v4 = *(_DWORD *)(a1 + 1176) - *(_DWORD *)(a2 + 1176);
              goto LABEL_253;
            case 1624:
              v4 = *(_DWORD *)(a1 + 1192) - *(_DWORD *)(a2 + 1192);
              goto LABEL_253;
            case 1625:
              v4 = *(_DWORD *)(a1 + 1208) - *(_DWORD *)(a2 + 1208);
              goto LABEL_253;
            case 1626:
              v4 = *(_DWORD *)(a1 + 1224) - *(_DWORD *)(a2 + 1224);
              goto LABEL_253;
            case 1627:
              v4 = *(_DWORD *)(a1 + 1240) - *(_DWORD *)(a2 + 1240);
              goto LABEL_253;
            case 1628:
              v4 = *(_DWORD *)(a1 + 1256) - *(_DWORD *)(a2 + 1256);
              goto LABEL_253;
            case 1629:
              v4 = sub_C337B0(
                     *(_QWORD *)(a1 + 1200) + *(_QWORD *)(a1 + 1232),
                     *(_QWORD *)(a2 + 1200) + *(_QWORD *)(a2 + 1232));
              goto LABEL_253;
            case 1630:
              v4 = sub_C337B0(*(_QWORD *)(a1 + 1184), *(_QWORD *)(a2 + 1184));
              goto LABEL_253;
            case 1631:
              v4 = sub_C337B0(*(_QWORD *)(a1 + 1200), *(_QWORD *)(a2 + 1200));
              goto LABEL_253;
            case 1632:
              v4 = sub_C337B0(*(_QWORD *)(a1 + 1216), *(_QWORD *)(a2 + 1216));
              goto LABEL_253;
            case 1633:
              v4 = sub_C337B0(*(_QWORD *)(a1 + 1232), *(_QWORD *)(a2 + 1232));
              goto LABEL_253;
            case 1634:
              v4 = sub_C337B0(*(_QWORD *)(a1 + 1248), *(_QWORD *)(a2 + 1248));
              goto LABEL_253;
            case 1635:
              v4 = sub_C337B0(*(_QWORD *)(a1 + 1264), *(_QWORD *)(a2 + 1264));
              goto LABEL_253;
            case 1636:
              v4 = sub_C337B0(*(_QWORD *)(a1 + 1272), *(_QWORD *)(a2 + 1272));
              goto LABEL_253;
            case 1637:
              v14 = *(double *)(a1 + 1312);
              v15 = *(double *)(a2 + 1312);
              if ( v14 <= v15 )
                goto LABEL_25;
              v16 = gConfig.bProcessSortDirection == 0;
              v4 = 1;
              goto LABEL_419;
            case 1638:
LABEL_189:
              v49 = *(_DWORD *)(a1 + 68);
              v50 = *(_DWORD *)(a2 + 68);
              if ( v49 < 0 )
                v49 = 0;
              if ( v50 < 0 )
                v50 = 0;
              v51 = (LPCWSTR)(v50 & 0xFFFFFFF);
              v52 = (LPCWSTR)(v49 & 0xFFFFFFF);
              goto LABEL_194;
            case 1650:
              v14 = *(double *)(a1 + 1384);
              v15 = *(double *)(a2 + 1384);
              if ( v14 <= v15 )
                goto LABEL_25;
              v16 = gConfig.bProcessSortDirection == 0;
              v4 = 1;
              goto LABEL_419;
            case 1651:
              v4 = sub_C337B0(*(_QWORD *)(a1 + 1408), *(_QWORD *)(a2 + 1408));
              goto LABEL_253;
            case 1652:
              v4 = sub_C337B0(*(_QWORD *)(a1 + 1424), *(_QWORD *)(a2 + 1424));
              goto LABEL_253;
            case 1653:
              v4 = sub_C337B0(*(_QWORD *)(a1 + 1440), *(_QWORD *)(a2 + 1440));
              goto LABEL_253;
            case 1654:
              v4 = lstrcmpiW(*(LPCWSTR *)(a1 + 824), *(LPCWSTR *)(a2 + 824));
              goto LABEL_253;
            case 1655:
LABEL_218:
              v4 = sub_C24EF0((unsigned int *)(a1 + 624), (_DWORD *)(a2 + 624));
              goto LABEL_253;
            case 1656:
              v4 = lstrcmpiW(*(LPCWSTR *)(a1 + 828), *(LPCWSTR *)(a2 + 828));
              goto LABEL_253;
            case 1667:
              v4 = *(_DWORD *)(a2 + 644) - *(_DWORD *)(a1 + 644);
              goto LABEL_253;
            case 1670:
              v53 = *(_DWORD *)(a1 + 844);
              if ( v53 && (v54 = *(_DWORD *)(a2 + 844)) != 0 )
              {
                v55 = *(_DWORD *)(v53 + 4);
                if ( v55 != 1 || *(_DWORD *)(v54 + 4) != 1 )
                {
                  v4 = v55 - *(_DWORD *)(v54 + 4);
                }
                else
                {
                  lpString1 = *(LPCWSTR *)(v53 + 4);
                  v140 = (LPCWSTR)1;
                  v138 = -1;
                  v137 = -1;
                  v56 = *(wchar_t ***)(v53 + 40);
                  if ( v56 )
                    v57 = *v56;
                  else
                    v57 = 0;
                  scan_fn(v57, (int)L"%d/%d", (int)&lpString1);
                  v58 = *(wchar_t ***)(*(_DWORD *)(a2 + 844) + 40);
                  if ( v58 )
                    v59 = *v58;
                  else
                    v59 = 0;
                  scan_fn(v59, (int)L"%d/%d", (int)&v140);
                  v52 = lpString1;
                  v51 = v140;
                  if ( lpString1 == v140 )
                    v4 = v138 - v137;
                  else
LABEL_194:
                    v4 = (char *)v52 - (char *)v51;
                }
              }
              else
              {
                v4 = sub_C337B0(v53, *(signed int *)(a2 + 844));
              }
              goto LABEL_253;
            case 1673:
              v4 = *(unsigned __int8 *)(a1 + 649) - *(unsigned __int8 *)(a2 + 649);
              goto LABEL_253;
            case 1674:
              v4 = ((*(_DWORD *)(a1 + 40) >> 13) & 1) - ((*(_DWORD *)(a2 + 40) >> 13) & 1);
              goto LABEL_253;
            default:
              goto LABEL_26;
          }
          goto LABEL_26;
        }
        v42 = *(_WORD *)(a1 + 650);
        v43 = *(_WORD *)(a2 + 650);
        v44 = *(_WORD *)(a1 + 650) & 0x4000;
        v45 = *(_WORD *)(a2 + 650) & 0x4000;
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
              v4 = *(_DWORD *)(a1 + 976) - *(_DWORD *)(a2 + 976);
              goto LABEL_253;
            case 1327:
              v4 = sub_C337B0(*(_QWORD *)(a1 + 984), *(_QWORD *)(a2 + 984));
              goto LABEL_253;
            case 1328:
              v4 = *(_DWORD *)(a1 + 1008) - *(_DWORD *)(a2 + 1008);
              goto LABEL_253;
            case 1329:
              v4 = sub_C337B0(*(_QWORD *)(a1 + 1016), *(_QWORD *)(a2 + 1016));
              goto LABEL_253;
            case 1330:
              v4 = sub_C337B0(
                     *(_QWORD *)(a1 + 984) + *(_QWORD *)(a1 + 1016),
                     *(_QWORD *)(a2 + 984) + *(_QWORD *)(a2 + 1016));
              goto LABEL_253;
            case 1332:
              v4 = sub_C337B0(*(_QWORD *)(a1 + 1048), *(_QWORD *)(a2 + 1048));
              goto LABEL_253;
            case 1333:
              v4 = sub_C337B0(*(_QWORD *)(a1 + 1056), *(_QWORD *)(a2 + 1056));
              goto LABEL_253;
            case 1335:
              v4 = *(_DWORD *)(a1 + 1040) - *(_DWORD *)(a2 + 1040);
              goto LABEL_253;
            case 1336:
LABEL_151:
              v4 = -1;
              if ( gConfig.dwProcessColumnMap[pSortParam->dwSortColumn] == 1336 )
              {
                v46 = *(const WCHAR **)(a1 + 816);
                v140 = *(LPCWSTR *)(a2 + 816);
              }
              else
              {
                v46 = *(const WCHAR **)(a1 + 820);
                v140 = *(LPCWSTR *)(a2 + 820);
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
              v4 = ((*(_DWORD *)(a1 + 40) >> 9) & 1) - ((*(_DWORD *)(a2 + 40) >> 9) & 1);
              goto LABEL_253;
            case 1338:
              v42 = *(_WORD *)(a1 + 650);
              v43 = *(_WORD *)(a2 + 650);
              v44 = *(_WORD *)(a1 + 650) & 0x40;
              v45 = *(_WORD *)(a2 + 650) & 0x40;
              goto LABEL_250;
            case 1339:
              v4 = *(_DWORD *)(a1 + 872) - *(_DWORD *)(a2 + 872);
              goto LABEL_253;
            case 1340:
              v4 = *(_DWORD *)(a1 + 952) - *(_DWORD *)(a2 + 952);
              goto LABEL_253;
            case 1341:
              v4 = sub_C337B0(*(unsigned int *)(a1 + 912), *(unsigned int *)(a2 + 912));
              goto LABEL_253;
            case 1342:
              v4 = sub_C337B0(*(unsigned int *)(a1 + 916), *(unsigned int *)(a2 + 916));
              goto LABEL_253;
            default:
              goto LABEL_26;
          }
          goto LABEL_26;
        }
        v4 = *(_DWORD *)(a1 + 1072) - *(_DWORD *)(a2 + 1072);
      }
    }
    else
    {
      if ( v13 != 1317 )
      {
        switch ( v13 )
        {
          case 1033:
            v4 = lstrcmpiW(*(LPCWSTR *)(a1 + 788), *(LPCWSTR *)(a2 + 788));
            goto LABEL_253;
          case 1055:
          case 1191:
            v14 = *(double *)(a1 + 1296);
            if ( v14 != 0.0 || v14 != *(double *)(a2 + 1296) )
            {
              v15 = *(double *)(a2 + 1296);
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
              v17 = *(_DWORD *)(a1 + 1356);
              v18 = *(_DWORD *)(a2 + 1356);
              v19 = *(_DWORD *)(a1 + 1352);
              v20 = *(_DWORD *)(a2 + 1352);
              if ( v17 < v18 )
                break;
              if ( v17 > v18 || v19 > v20 )
                goto LABEL_45;
              if ( v17 > v18 || v17 >= v18 && v19 >= v20 )
              {
                v21 = *(_DWORD *)(a1 + 1340);
                v22 = *(_DWORD *)(a2 + 1340);
                v23 = *(_DWORD *)(a1 + 1336);
                v24 = *(_DWORD *)(a2 + 1336);
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
            v4 = *(_DWORD *)(a1 + 100) - *(_DWORD *)(a2 + 100);
            goto LABEL_253;
          case 1059:
            v4 = sub_C337B0(*(unsigned int *)(a1 + 880), *(unsigned int *)(a2 + 880));
            goto LABEL_253;
          case 1060:
          case 1193:
            v4 = sub_C337B0(*(unsigned int *)(a1 + 888), *(unsigned int *)(a2 + 888));
            goto LABEL_253;
          case 1061:
            v4 = lstrcmpiW(*(LPCWSTR *)(a1 + 792), *(LPCWSTR *)(a2 + 792));
            goto LABEL_253;
          case 1062:
            v4 = sub_C337B0(*(unsigned int *)(a1 + 896), *(unsigned int *)(a2 + 896));
            goto LABEL_253;
          case 1063:
            v4 = sub_C337B0(*(unsigned int *)(a1 + 900), *(unsigned int *)(a2 + 900));
            goto LABEL_253;
          case 1064:
            v4 = sub_C337B0(*(unsigned int *)(a1 + 904), *(unsigned int *)(a2 + 904));
            goto LABEL_253;
          case 1065:
            v4 = *(_DWORD *)(a1 + 96) - *(_DWORD *)(a2 + 96);
            goto LABEL_253;
          case 1066:
            v4 = *(_DWORD *)(a1 + 1380) - *(_DWORD *)(a2 + 1380);
            goto LABEL_253;
          case 1067:
            v4 = *(_DWORD *)(a1 + 1376) - *(_DWORD *)(a2 + 1376);
            goto LABEL_253;
          case 1068:
            v4 = *(_DWORD *)(a1 + 960) - *(_DWORD *)(a2 + 960);
            goto LABEL_253;
          case 1069:
            v4 = sub_C337B0(*(_QWORD *)(a1 + 968), *(_QWORD *)(a2 + 968));
            goto LABEL_253;
          case 1070:
            v4 = *(_DWORD *)(a1 + 992) - *(_DWORD *)(a2 + 992);
            goto LABEL_253;
          case 1071:
            v4 = sub_C337B0(*(_QWORD *)(a1 + 1000), *(_QWORD *)(a2 + 1000));
            goto LABEL_253;
          case 1072:
            v4 = *(_DWORD *)(a1 + 1024) - *(_DWORD *)(a2 + 1024);
            goto LABEL_253;
          case 1073:
            v4 = sub_C337B0(*(_QWORD *)(a1 + 1032), *(_QWORD *)(a2 + 1032));
            goto LABEL_253;
          case 1086:
            goto LABEL_218;
          case 1087:
            v4 = sub_C24EF0((unsigned int *)(a1 + 1320), (_DWORD *)(a2 + 1320));
            goto LABEL_253;
          case 1091:
            v4 = sub_C337B0(*(_QWORD *)(a1 + 1344), *(_QWORD *)(a2 + 1344));
            goto LABEL_253;
          case 1092:
            v4 = sub_C337B0(*(_QWORD *)(a1 + 1336), *(_QWORD *)(a2 + 1336));
            goto LABEL_253;
          case 1094:
            v25 = *(_DWORD *)(a1 + 1284);
            if ( !v25 )
              goto LABEL_97;
            v26 = *(_DWORD **)(a2 + 1284);
            if ( !v26 )
              goto LABEL_95;
            v4 = *(_DWORD *)v25 - *v26;
            goto LABEL_253;
          case 1095:
            v25 = *(_DWORD *)(a1 + 1284);
            if ( !v25 )
              goto LABEL_97;
            v27 = *(_DWORD *)(a2 + 1284);
            if ( !v27 )
              goto LABEL_95;
            v4 = (signed int)(*(double *)(v25 + 8) - *(double *)(v27 + 8));
            goto LABEL_253;
          case 1096:
            v25 = *(_DWORD *)(a1 + 1284);
            if ( !v25 )
              goto LABEL_97;
            v28 = *(_DWORD *)(a2 + 1284);
            if ( !v28 )
              goto LABEL_95;
            v4 = *(_DWORD *)(v25 + 16) - *(_DWORD *)(v28 + 16);
            goto LABEL_253;
          case 1097:
            v25 = *(_DWORD *)(a1 + 1284);
            if ( !v25 )
              goto LABEL_97;
            v29 = *(_DWORD *)(a2 + 1284);
            if ( !v29 )
              goto LABEL_95;
            v4 = *(_DWORD *)(v25 + 48) - *(_DWORD *)(v29 + 48);
            goto LABEL_253;
          case 1098:
            v25 = *(_DWORD *)(a1 + 1284);
            if ( !v25 )
              goto LABEL_97;
            v30 = *(_DWORD *)(a2 + 1284);
            if ( !v30 )
              goto LABEL_95;
            v4 = *(_DWORD *)(v25 + 32) - *(_DWORD *)(v30 + 32);
            goto LABEL_253;
          case 1099:
            v25 = *(_DWORD *)(a1 + 1284);
            if ( !v25 )
              goto LABEL_97;
            v31 = *(_DWORD *)(a2 + 1284);
            if ( !v31 )
              goto LABEL_95;
            v4 = *(_DWORD *)(v25 + 24) - *(_DWORD *)(v31 + 24);
            goto LABEL_253;
          case 1100:
            v25 = *(_DWORD *)(a1 + 1284);
            if ( !v25 )
              goto LABEL_97;
            v32 = *(_DWORD *)(a2 + 1284);
            if ( !v32 )
              goto LABEL_95;
            v4 = *(_DWORD *)(v25 + 56) - *(_DWORD *)(v32 + 56);
            goto LABEL_253;
          case 1101:
            v25 = *(_DWORD *)(a1 + 1284);
            if ( !v25 )
              goto LABEL_97;
            v33 = *(_DWORD *)(a2 + 1284);
            if ( !v33 )
              goto LABEL_95;
            v4 = *(_DWORD *)(v25 + 40) - *(_DWORD *)(v33 + 40);
            goto LABEL_253;
          case 1103:
            v25 = *(_DWORD *)(a1 + 1284);
            if ( !v25 )
              goto LABEL_97;
            v35 = *(_DWORD *)(a2 + 1284);
            if ( !v35 )
              goto LABEL_95;
            v4 = *(_DWORD *)(v25 + 112) - *(_DWORD *)(v35 + 112);
            goto LABEL_253;
          case 1104:
            v25 = *(_DWORD *)(a1 + 1284);
            if ( !v25 )
              goto LABEL_97;
            v36 = *(_DWORD *)(a2 + 1284);
            if ( !v36 )
              goto LABEL_95;
            v4 = *(_DWORD *)(v25 + 64) - *(_DWORD *)(v36 + 64);
            goto LABEL_253;
          case 1105:
            v25 = *(_DWORD *)(a1 + 1284);
            if ( !v25 )
              goto LABEL_97;
            v37 = *(_DWORD *)(a2 + 1284);
            if ( !v37 )
              goto LABEL_95;
            v4 = *(_DWORD *)(v25 + 72) - *(_DWORD *)(v37 + 72);
            goto LABEL_253;
          case 1106:
            v25 = *(_DWORD *)(a1 + 1284);
            if ( !v25 )
              goto LABEL_97;
            v38 = *(_DWORD *)(a2 + 1284);
            if ( !v38 )
              goto LABEL_95;
            v4 = *(_DWORD *)(v25 + 80) - *(_DWORD *)(v38 + 80);
            goto LABEL_253;
          case 1107:
            v25 = *(_DWORD *)(a1 + 1284);
            if ( !v25 )
              goto LABEL_97;
            v39 = *(_DWORD *)(a2 + 1284);
            if ( !v39 )
              goto LABEL_95;
            v4 = (signed int)(*(double *)(v25 + 88) - *(double *)(v39 + 88));
            goto LABEL_253;
          case 1108:
            v25 = *(_DWORD *)(a1 + 1284);
            if ( !v25 )
              goto LABEL_97;
            v40 = *(_DWORD *)(a2 + 1284);
            if ( !v40 )
              goto LABEL_95;
            v4 = *(_DWORD *)(v25 + 104) - *(_DWORD *)(v40 + 104);
            goto LABEL_253;
          case 1109:
            v25 = *(_DWORD *)(a1 + 1284);
            if ( !v25 )
              goto LABEL_97;
            v41 = *(_DWORD *)(a2 + 1284);
            if ( !v41 )
              goto LABEL_95;
            v4 = *(_DWORD *)(v25 + 120) - *(_DWORD *)(v41 + 120);
            goto LABEL_253;
          case 1110:
            v25 = *(_DWORD *)(a1 + 1284);
            if ( !v25 )
              goto LABEL_97;
            v34 = *(_DWORD *)(a2 + 1284);
            if ( v34 )
            {
              v4 = *(_DWORD *)(v25 + 128) - *(_DWORD *)(v34 + 128);
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
              v4 = -(*(_DWORD *)(a2 + 1284) != 0);
            }
            goto LABEL_253;
          case 1114:
            v4 = sub_C337B0(*(unsigned int *)(a1 + 876), *(unsigned int *)(a2 + 876));
            goto LABEL_253;
          case 1115:
            v4 = sub_C337B0(*(unsigned int *)(a1 + 936), *(unsigned int *)(a2 + 936));
            goto LABEL_253;
          case 1116:
            v4 = sub_C337B0(*(unsigned int *)(a1 + 940), *(unsigned int *)(a2 + 940));
            goto LABEL_253;
          case 1118:
            v4 = sub_C337B0(*(unsigned int *)(a1 + 948), *(unsigned int *)(a2 + 948));
            goto LABEL_253;
          case 1179:
            v4 = sub_C337B0(*(unsigned int *)(a1 + 884), *(unsigned int *)(a2 + 884));
            goto LABEL_253;
          case 1180:
            goto LABEL_151;
          case 1181:
            v4 = lstrcmpiW(*(LPCWSTR *)(a1 + 796), *(LPCWSTR *)(a2 + 796));
            goto LABEL_253;
          case 1187:
            v4 = lstrcmpiW(*(LPCWSTR *)(a1 + 836), *(LPCWSTR *)(a2 + 836));
            goto LABEL_253;
          case 1192:
            v4 = *(_DWORD *)(a1 + 892) - *(_DWORD *)(a2 + 892);
            goto LABEL_253;
          case 1195:
            v4 = sub_C337B0(*(_QWORD *)(a1 + 1360), *(_QWORD *)(a2 + 1360));
            goto LABEL_253;
          case 1196:
            v4 = *(unsigned __int8 *)(a1 + 620) - *(unsigned __int8 *)(a2 + 620);
            if ( *(unsigned __int8 *)(a1 + 620) != *(unsigned __int8 *)(a2 + 620) )
              goto LABEL_27;
            v4 = (*(_DWORD *)(a1 + 616) - *(_DWORD *)(a2 + 616)) >> 2;
            goto LABEL_253;
          case 1199:
            v4 = *(unsigned __int8 *)(a1 + 636) - *(unsigned __int8 *)(a2 + 636);
            goto LABEL_253;
          case 1200:
            v4 = sub_C337B0(*(_QWORD *)(a1 + 1352), *(_QWORD *)(a2 + 1352));
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
      v4 = sub_C337B0(*(unsigned int *)(a1 + 944), *(unsigned int *)(a2 + 944));
    }
LABEL_253:
    if ( v4 )
      goto LABEL_27;
LABEL_254:
    v60 = lstrcmpiW(*(LPCWSTR *)(a1 + 60), *(LPCWSTR *)(a2 + 60));
    v16 = gConfig.bProcessSortDirection == 0;
    v4 = v60;
    goto LABEL_419;
  }
  v7 = *(_DWORD **)(a2 + 84);
  v8 = *(_DWORD *)(a1 + 80);
  v9 = *(_DWORD *)(a2 + 80);
  v10 = *(_DWORD **)(a1 + 84);
  if ( v7 == (_DWORD *)a1 )
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
    v7 = (_DWORD *)v6[21];
    v10 = (_DWORD *)v3[21];
    if ( v7 == v3 )
      return -1;
  }
  if ( v8 && v10 != v7 )
  {
    v11 = v8 < v9;
    goto LABEL_9;
  }
  result = sub_C24EF0(v3 + 156, v6 + 156);
  if ( !result )
    result = v3[17] - v6[17];
  return result;
}
// CA2BB0: using guessed type wchar_t aDD[6];
// CCD224: using guessed type char byte_CCD224;
// CCD225: using guessed type char byte_CCD225;
// CD53B4: using guessed type char byte_CD53B4;

//----- (00C2CB80) --------------------------------------------------------
int __stdcall InitListHeader(HWND hWnd, UINT *pnIDs, WORD *pnWidths, LONG nColumnCount)
{
  HWND (__stdcall *GetParent)(HWND); // ecx
  WPARAM nColumn; // esi
  char v6; // al
  __m128i v7; // xmm1
  int *v8; // edx
  unsigned int Index; // ecx
  unsigned int v10; // eax
  __m128i v11; // xmm0
  tagLVCOLUMNW ColumnInfo; // [esp+0h] [ebp-22Ch]
  WORD *pnWidths_1; // [esp+20h] [ebp-20Ch]
  signed int *pnIDs_1; // [esp+24h] [ebp-208h]
  int arrIDS[96]; // [esp+28h] [ebp-204h]
  WCHAR Buffer[64]; // [esp+1A8h] [ebp-84h]

  pnIDs_1 = (signed int *)pnIDs;
  pnWidths_1 = pnWidths;
  ColumnInfo.mask = 0;
  _mm_storeu_si128((__m128i *)&ColumnInfo.fmt, (__m128i)0i64);
  ColumnInfo.iOrder = 0;
  *(_QWORD *)&ColumnInfo.iSubItem = 0i64;
  while ( SendMessageW(hWnd, LVM_DELETECOLUMN, 0, 0) )
    ;
  GetParent = ::GetParent;
  nColumn = 0;
  ColumnInfo.mask = 15;
  ColumnInfo.pszText = Buffer;
  if ( nColumnCount )
  {
    while ( 1 )
    {
      ColumnInfo.iSubItem = nColumn;
      ColumnInfo.cx = abs((signed __int16)pnWidths_1[nColumn]);
      if ( GetParent(hWnd) != ghMainWnd )
        break;
      if ( (pnWidths_1[nColumn] & 0x8000u) != 0 )
        goto LABEL_9;
      v6 = IsStringID(pnIDs_1[nColumn]);
      ColumnInfo.fmt = 0;
      if ( v6 )
        goto LABEL_9;
LABEL_10:
      LoadStringW(ghInstance, pnIDs_1[nColumn], Buffer, 64);
      if ( SendMessageW(hWnd, LVM_INSERTCOLUMNW, nColumn, (LPARAM)&ColumnInfo) == -1 )
        return 0;
      GetParent = ::GetParent;
      if ( ++nColumn >= nColumnCount )
        goto LABEL_12;
    }
    if ( (pnWidths_1[nColumn] & 0x8000u) == 0 )
    {
      ColumnInfo.fmt = 0;
      goto LABEL_10;
    }
LABEL_9:
    ColumnInfo.fmt = 1;
    goto LABEL_10;
  }
LABEL_12:
  if ( GetParent(hWnd) == ghMainWnd && IsStringID(*pnIDs_1) )
  {
    ColumnInfo.mask = 1;
    SendMessageW(hWnd, LVM_GETCOLUMNW, 0, (LPARAM)&ColumnInfo);
    ColumnInfo.fmt |= 1u;
    ColumnInfo.mask = 1;
    SendMessageW(hWnd, LVM_SETCOLUMNW, 0, (LPARAM)&ColumnInfo);
  }
  SetWindowLongW(hWnd, GWLP_USERDATA, nColumnCount);
  v7 = _mm_load_si128((const __m128i *)&gIntArray);
  v8 = &arrIDS[4];
  Index = 0;
  do
  {
    v10 = Index + 4;
    v8 += 8;
    v11 = _mm_add_epi32(_mm_shuffle_epi32(_mm_cvtsi32_si128(Index), 0), v7);
    Index += 8;
    _mm_storeu_si128((__m128i *)v8 - 3, v11);
    _mm_storeu_si128((__m128i *)v8 - 2, _mm_add_epi32(_mm_shuffle_epi32(_mm_cvtsi32_si128(v10), 0), v7));
  }
  while ( Index < 96 );
  SendMessageW(hWnd, LVM_SETCOLUMNORDERARRAY, nColumnCount, (LPARAM)arrIDS);
  InvalidateRect(hWnd, 0, 1);
  return 1;
}
// CAEA50: using guessed type tagRECT gIntArray;

//----- (00C2CDD0) --------------------------------------------------------
int __cdecl CMainWnd::HandleNmClick(int uID, LPNMITEMACTIVATE pNMHDR)
{
  HWND hWndList; // edi
  tagTREEVIEWLISTITEMPARAM *v3; // esi
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
  int lParam_1; // [esp+6Ch] [ebp-14h]

  HitTestInfo.pt.x = 0;
  _mm_storeu_si128((__m128i *)&HitTestInfo.pt.y, (__m128i)0i64);
  item.mask = 0;
  memset(&item.iItem, 0, 0x30u);
  Point.x = 0;
  Point.y = 0;
  if ( uID == IDC_TREEVIEW_LIST )
  {
    hWndList = ghWndTreeListView;
  }
  else
  {
    if ( uID != IDC_LISTCTRL_DLLS )
      return 0;
    hWndList = ghWndDllsListCtrl;
  }
  GetCursorPos(&Point);
  ScreenToClient(hWndList, &Point);
  HitTestInfo.pt = Point;
  item.iItem = SendMessageW(hWndList, LVM_HITTEST, 0, (LPARAM)&HitTestInfo);
  item.iSubItem = 0;
  item.mask = 4;
  if ( SendMessageW(hWndList, LVM_GETITEMW, 0, (LPARAM)&item) != 1 )
    return 0;
  sub_C2A880(hWndList, item.iItem, HitTestInfo.iSubItem, (#153 *)&lParam_1);
  v3 = item.lParam;
  if ( hWndList != ghWndTreeListView )
  {
    SubHitTestInfo.pt.x = pNMHDR->ptAction.x;
    SubHitTestInfo.pt.y = pNMHDR->ptAction.y;
    SendMessageW(hWndList, LVM_SUBITEMHITTEST, 0, (LPARAM)&SubHitTestInfo);
    if ( gConfig.dwDllColumnMap[SubHitTestInfo.iSubItem] == IDS_VIRUSTOTAL && sub_C71820((ListItemData1 *)v3->field_16C) )
    {
      v11 = *(const WCHAR ***)(v3->field_16C + 36);
      if ( v11 )
        v12 = *v11;
      else
        v12 = 0;
      LaunchWebBrowser(hWndList, 0, v12);
    }
    return 0;
  }
  v4 = gConfig.dwProcessColumnMap[HitTestInfo.iSubItem];
  if ( v4 != 3 )
  {
    if ( v4 == IDS_VIRUSTOTAL && sub_C71820(item.lParam->m_ItemDataForVirusTotal) )
    {
      v9 = (const WCHAR **)v3->m_ItemDataForVirusTotal[4].field_4;
      if ( v9 )
        v10 = *v9;
      else
        v10 = 0;
      LaunchWebBrowser(hWndList, 0, v10);
    }
    goto LABEL_24;
  }
  if ( !item.lParam->field_30
    || (!gConfig.bShowProcessTree ? (v5 = 0) : (v5 = item.lParam->nSpaceNumber),
        (v6 = lParam_1 + 16 * v5, HitTestInfo.pt.x <= v6 + 1) || HitTestInfo.pt.x >= v6 + 17) )
  {
LABEL_24:
    RefreshMenuWithTreeViewItemStatus(v3);
    RefreshVirusTotalMenuItem(v3);
    return 0;
  }
  v7 = item.lParam->dwStyle;
  if ( v7 & 4 )
  {
    v13 = item.lParam;
    item.lParam->dwStyle = v7 & 0xFFFFFFFB;
  }
  else
  {
    v13 = item.lParam;
    item.lParam->dwStyle = v7 | 4;
  }
  sub_C28DA0(v13);
  RefreshMenuWithTreeViewItemStatus(v3);
  RefreshVirusTotalMenuItem(v3);
  return 0;
}

//----- (00C2D040) --------------------------------------------------------
// PE_ShowProcessTree
int __cdecl CMainWnd::HandleLVNColumnClick(WPARAM uTabID, LPNMLVKEYDOWN pKeyDown)
{
  HWND *hwndFrom; // ebx
  void (__stdcall *SendMessageW)(HWND, UINT, WPARAM, LPARAM); // esi
  int v4; // eax
  LPARAM pItem; // edi
  bool v6; // al
  HMENU v7; // eax
  void *TreeItem; // eax
  signed int v9; // edi
  signed int v10; // ebx
  DWORD v11; // ST04_4
  HMENU v12; // eax
  BOOL v13; // ST0C_4
  HMENU v14; // eax
  int v15; // edi
  HWND v16; // ST00_4
  signed int v17; // edi
  int v18; // esi
  int v19; // eax
  DWORD iSubItem; // edx
  char bSort; // al
  HWND iItem; // ecx
  LRESULT iNewItem; // eax
  HWND v24; // ST00_4
  HWND v25; // ST00_4
  LVFINDINFOW FindInfo; // [esp+Ch] [ebp-94h]
  LVITEMW Item; // [esp+24h] [ebp-7Ch]
  LVITEMW TextItem; // [esp+58h] [ebp-48h]
  WPARAM wParam; // [esp+8Ch] [ebp-14h]
  int v31; // [esp+90h] [ebp-10h]
  tagTREEVIEWLISTITEMPARAM *pTreeItem; // [esp+94h] [ebp-Ch]
  void *i; // [esp+98h] [ebp-8h]
  tagHwndID *v34; // [esp+9Ch] [ebp-4h]

  hwndFrom = &pKeyDown->hdr.hwndFrom;
  SendMessageW = (void (__stdcall *)(HWND, UINT, WPARAM, LPARAM))::SendMessageW;
  v4 = *(UINT *)((char *)&pKeyDown->flags + 2);
  pItem = 0;
  v34 = (tagHwndID *)pKeyDown;
  pTreeItem = 0;
  wParam = uTabID;
  v31 = v4;
  if ( uTabID == IDC_TREEVIEW_LIST )
  {
    Item.iItem = ::SendMessageW(ghWndTreeListView, LVM_GETNEXTITEM, 0xFFFFFFFF, 2);
    if ( Item.iItem != -1 )
    {
      Item.iSubItem = 0;
      Item.mask = 4;
      ::SendMessageW(ghWndTreeListView, LVM_GETITEMW, 0, (LPARAM)&Item);
      pTreeItem = Item.lParam;
    }
    v6 = gConfig.bProcessSortDirection;
    if ( gConfig.bShowProcessTree
      || gConfig.dwProcessColumnMap[*(UINT *)((char *)&pKeyDown->flags + 2)] != 3
      || gConfig.bProcessSortDirection )
    {
      gConfig.bShowProcessTree = 0;
      if ( gConfig.dwProcessSortColumn == *(UINT *)((char *)&pKeyDown->flags + 2) )
      {
        v6 = gConfig.bProcessSortDirection == 0;
        gConfig.bProcessSortDirection = gConfig.bProcessSortDirection == 0;
      }
      v11 = gConfig.dwProcessSortColumn;
      gConfig.dwProcessSortColumn = *(UINT *)((char *)&pKeyDown->flags + 2);
      CTreeList::InitHeaderColumn(pKeyDown->hdr.hwndFrom, v11, (HWND)gConfig.dwProcessSortColumn, v6);
      v12 = GetMenu(ghMainWnd);
      EnableMenuItem(v12, IDM_PROCESS_KILL_PROCESS_TREE, 1u);
      ::SendMessageW(ghWndToolbar, 0x401u, IDM_VIEW_SHOW_PROCESS_TREE, gConfig.bShowProcessTree == 0);
      v13 = gConfig.bShowProcessTree != 0;
      v14 = GetMenu(ghMainWnd);
      EnableMenuItem(v14, IDM_VIEW_SHOW_PROCESS_TREE, v13);
      SendMessageW = (void (__stdcall *)(HWND, UINT, WPARAM, LPARAM))::SendMessageW;
    }
    else
    {
      gConfig.dwProcessSortColumn = *(UINT *)((char *)&pKeyDown->flags + 2);
      ::SendMessageW(ghWndToolbar, 0x401u, IDM_VIEW_SHOW_PROCESS_TREE, 0);
      v7 = GetMenu(ghMainWnd);
      EnableMenuItem(v7, IDM_VIEW_SHOW_PROCESS_TREE, 1u);
      TreeItem = (void *)GetWindowLongW(ghWndTreeListView, GWLP_USERDATA);
      v9 = 0;
      i = TreeItem;
      if ( (signed int)TreeItem > 0 )
      {
        v10 = (signed int)TreeItem;
        do
        {
          TextItem.pszText = (LPWSTR)1;
          ::SendMessageW(ghWndTreeListView, LVM_GETCOLUMNW, v9, (LPARAM)&TextItem.pszText);
          TextItem.cchTextMax &= -0x1801u;
          TextItem.pszText = (LPWSTR)1;
          ::SendMessageW(ghWndTreeListView, LVM_SETCOLUMNW, v9++, (LPARAM)&TextItem.pszText);
        }
        while ( v9 < v10 );
        hwndFrom = &v34->hWnd;
      }
      gConfig.bShowProcessTree = 1;
      sub_C66020(gpTreeViewListItemParam);
    }
    SendMessageW(*hwndFrom, WM_SETREDRAW, 0, 0);
    v34 = (tagHwndID *)((LRESULT (__stdcall *)(HWND, UINT, WPARAM, LPARAM))SendMessageW)(
                         *hwndFrom,
                         LVM_GETITEMCOUNT,
                         0,
                         0);
    v15 = 0;
    for ( i = operator new[](4 * (_DWORD)v34); v15 < (signed int)v34; ++v15 )
    {
      TextItem.iItem = v15;
      v16 = *hwndFrom;
      TextItem.iSubItem = 0;
      TextItem.mask = 4;
      SendMessageW(v16, LVM_GETITEMW, 0, (LPARAM)&TextItem);
      *((_DWORD *)i + v15) = TextItem.lParam;
    }
    SendMessageW(*hwndFrom, LVM_DELETEALLITEMS, 0, 0);
    v17 = 0;
    if ( (signed int)v34 > 0 )
    {
      do
      {
        v18 = *((_DWORD *)i + v17);
        v19 = sub_C27F20(*hwndFrom, *((tagTREEVIEWLISTITEMPARAM **)i + v17++));
        *(_DWORD *)(v18 + 1464) = v19;
      }
      while ( v17 < (signed int)v34 );
      SendMessageW = (void (__stdcall *)(HWND, UINT, WPARAM, LPARAM))::SendMessageW;
    }
    operator delete[](i);
    pItem = (LPARAM)pTreeItem;
  }
  else
  {
    switch ( uTabID )
    {
      case IDC_LISTCTRL_HANDLES:
        iSubItem = gConfig.dwHandleSortColumn;
        if ( gConfig.dwHandleSortColumn == v4 )
        {
          bSort = LOBYTE(gConfig.bHandleSortDirection) == 0;
          LOBYTE(gConfig.bHandleSortDirection) = LOBYTE(gConfig.bHandleSortDirection) == 0;
          iItem = *(HWND *)((char *)&pKeyDown->flags + 2);
        }
        else
        {
          iItem = *(HWND *)((char *)&pKeyDown->flags + 2);
          bSort = gConfig.bHandleSortDirection;
        }
        gConfig.dwHandleSortColumn = *(UINT *)((char *)&pKeyDown->flags + 2);
        break;
      case IDM_ABOUT:
        iSubItem = gConfig.dwDllSortColumn;
        if ( gConfig.dwDllSortColumn == v4 )
        {
          bSort = LOBYTE(gConfig.bDllSortDirection) == 0;
          LOBYTE(gConfig.bDllSortDirection) = LOBYTE(gConfig.bDllSortDirection) == 0;
          iItem = *(HWND *)((char *)&pKeyDown->flags + 2);
        }
        else
        {
          iItem = *(HWND *)((char *)&pKeyDown->flags + 2);
          bSort = gConfig.bDllSortDirection;
        }
        gConfig.dwDllSortColumn = *(UINT *)((char *)&pKeyDown->flags + 2);
        break;
      case IDS_DISPLAY_NAME:
        iSubItem = ::wParam;
        if ( ::wParam == v4 )
        {
          bSort = byte_CD53B4 == 0;
          byte_CD53B4 = byte_CD53B4 == 0;
          iItem = *(HWND *)((char *)&pKeyDown->flags + 2);
        }
        else
        {
          iItem = *(HWND *)((char *)&pKeyDown->flags + 2);
          bSort = byte_CD53B4;
        }
        ::wParam = *(UINT *)((char *)&pKeyDown->flags + 2);
        break;
      case IDC_DLG_HANDLE_INFO_STATIC_UNKNOWN1|IDS_REFRESH_PROCESS_LIST:
        iSubItem = nItem;
        if ( nItem == v4 )
        {
          bSort = byte_CCD224 == 0;
          byte_CCD224 = byte_CCD224 == 0;
          iItem = *(HWND *)((char *)&pKeyDown->flags + 2);
        }
        else
        {
          iItem = *(HWND *)((char *)&pKeyDown->flags + 2);
          bSort = byte_CCD224;
        }
        nItem = *(UINT *)((char *)&pKeyDown->flags + 2);
        break;
      case IDC_SYSINFO_IO_STATIC_WRITE_BYTES_DELTA_VALUE:
        iSubItem = dword_CD9B98;
        if ( dword_CD9B98 == v4 )
        {
          bSort = byte_CCD225 == 0;
          byte_CCD225 = byte_CCD225 == 0;
        }
        else
        {
          bSort = byte_CCD225;
        }
        iItem = *(HWND *)((char *)&pKeyDown->flags + 2);
        dword_CD9B98 = *(UINT *)((char *)&pKeyDown->flags + 2);
        break;
      default:
        goto LABEL_47;
    }
    CTreeList::InitHeaderColumn(pKeyDown->hdr.hwndFrom, iSubItem, iItem, bSort);
  }
LABEL_47:
  SendMessageW(*hwndFrom, LVM_SORTITEMS, (WPARAM)&wParam, (LPARAM)BackendSortCallback);
  iNewItem = ((LRESULT (__stdcall *)(HWND, UINT, WPARAM, LPARAM))SendMessageW)(
               *hwndFrom,
               LVM_GETNEXTITEM,
               0xFFFFFFFF,
               2);
  SendMessageW(*hwndFrom, LVM_ENSUREVISIBLE, iNewItem, 0);
  if ( uTabID == IDC_TREEVIEW_LIST )
  {
    if ( pItem )
    {
      FindInfo.flags = 1;
      v24 = *hwndFrom;
      FindInfo.lParam = pItem;
      Item.iItem = ((LRESULT (__stdcall *)(HWND, UINT, WPARAM, LPARAM))SendMessageW)(
                     v24,
                     LVM_FINDITEMW,
                     0xFFFFFFFF,
                     (LPARAM)&FindInfo);
      v25 = *hwndFrom;
      TextItem.stateMask = 3;
      TextItem.state = 3;
      SendMessageW(v25, LVM_SETITEMSTATE, Item.iItem, (LPARAM)&TextItem);
      SendMessageW(*hwndFrom, LVM_ENSUREVISIBLE, Item.iItem, 0);
    }
    SendMessageW(*hwndFrom, WM_SETREDRAW, 1u, 0);
  }
  return 0;
}
// CCD224: using guessed type char byte_CCD224;
// CCD225: using guessed type char byte_CCD225;
// CD53B4: using guessed type char byte_CD53B4;

//----- (00C2D4B0) --------------------------------------------------------
int __cdecl CMainWnd::HandleLVNDeleteItem(UINT uId, LPNMLISTVIEW pNMListView)
{
  int v2; // ecx
  int v3; // edi
  _DWORD *v4; // esi
  ULONGLONG *v5; // edx
  int v6; // edx
  tagDLLLISTITEMPARAM *pItem1; // ecx
  int v9; // edx
  tagDLLLISTITEMPARAM *v10; // edx
  tagTREEVIEWLISTITEMPARAM *v11; // eax
  void *v12; // ecx
  tagTREEVIEWLISTITEMPARAM *v13; // esi
  LVITEMW dllitem; // [esp+4h] [ebp-34h]

  dllitem.mask = 4;
  dllitem.iItem = pNMListView->iItem;
  if ( (signed int)uId > 104 )
  {
    if ( uId == 1040 )
    {
      SendMessageW(pNMListView->hdr.hwndFrom, LVM_GETITEMW, 0, (LPARAM)&dllitem);
      v11 = dllitem.lParam;
      v13 = dllitem.lParam;
      if ( dllitem.lParam->field_30 )
      {
        free((void *)dllitem.lParam->field_30);
        v11 = dllitem.lParam;
      }
      v12 = (void *)v13->dwStyle;
    }
    else
    {
      if ( uId != 1192 )
        return 0;
      SendMessageW(pNMListView->hdr.hwndFrom, LVM_GETITEMW, 0, (LPARAM)&dllitem);
      v11 = dllitem.lParam;
      if ( *(_DWORD *)&dllitem.lParam[1].field_28E[25] )
      {
        free(*(void **)&dllitem.lParam[1].field_28E[25]);
        v11 = dllitem.lParam;
      }
      v12 = *(void **)&v11[1].field_28E[29];
    }
    if ( v12 )
    {
      free(v12);
      v11 = dllitem.lParam;
    }
    free(v11);
    return 0;
  }
  if ( uId != 104 )
  {
    if ( uId == IDC_TREEVIEW_LIST )
    {
      dword_CCE0D8 = -1;
      pNMListView->lParam->field_5B8 = 0;
      return 0;
    }
    if ( uId == 102 )
    {
      // IDC_LISTCTRL_HANDLES
      SendMessageW(ghWndHandlesListCtrl, LVM_GETITEMW, 0, (LPARAM)&dllitem);
      // tagHANDLELISTITEMPARAM
      v2 = (int)dllitem.lParam;
      v3 = HIDWORD(dllitem.lParam[2].ContextSwtichDelta);
      v4 = (_DWORD *)((char *)&dllitem.lParam[2].ContextSwtichDelta + 4);
      v5 = &dllitem.lParam[2].ContextSwtichDelta;
      if ( v3 )
      {
        *(_DWORD *)(v3 + 4280) = dllitem.lParam[2].ContextSwtichDelta;
        v2 = (int)dllitem.lParam;
      }
      else
      {
        pItemParam = dllitem.lParam[2].ContextSwtichDelta;
      }
      v6 = *(_DWORD *)v5;
      if ( v6 )
      {
        *(_DWORD *)(v6 + 4284) = *v4;
        v2 = (int)dllitem.lParam;
      }
      free((void *)v2);
      return 0;
    }
    return 0;
  }
  // IDC_LISTCTRL_DLLS
  SendMessageW(ghWndDllsListCtrl, LVM_GETITEMW, 0, (LPARAM)&dllitem);
  pItem1 = (tagDLLLISTITEMPARAM *)dllitem.lParam;
  v9 = *(_DWORD *)&dllitem.lParam->gap180[4];
  if ( v9 )
    *(_DWORD *)(v9 + 384) = *(_DWORD *)dllitem.lParam->gap180;
  else
    gpDllListItemParamHeader = *(tagDLLLISTITEMPARAM **)dllitem.lParam->gap180;
  v10 = pItem1->m_Prev;
  if ( v10 )
    v10->m_Next = pItem1->m_Next;
  DLLLISTITEMPARAM_Release((tagTREEVIEWLISTITEMPARAM *)pItem1);
  return 0;
}
// CCE0D8: using guessed type int dword_CCE0D8;

//----- (00C2D660) --------------------------------------------------------
int __cdecl CMainWnd::HandleNmDblClk(int nID)
{
  HWND hWndList; // edi
  int nItem; // eax
  tagTREEVIEWLISTITEMPARAM *v4; // esi
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
    if ( SendMessageW(hWndList, LVM_GETITEMW, 0, (LPARAM)&lvitem) == 1 )
    {
      switch ( nID )
      {
        case 101:
          CTreeList::FillTreeViewParam(lvitem.lParam);
          return 0;
        case 102:
          FillHandleListParam(hWndList, (tagHANDLELISTITEMPARAM *)lvitem.lParam);
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
          if ( !lvitem.lParam->hFileIcon )
          {
            MessageBoxW(ghMainWnd, L"Not a valid DLL", L"Process Explorer", MB_ICONHAND);
            return 0;
          }
          InterlockedIncrement(&lvitem.lParam->field_0);
          v4->dwStyle = gdwProcessIdSelected;
          _beginthread((int)PropertiesThreadProc, 0, (int)v4);
          break;
      }
    }
  }
  return 0;
}

//----- (00C2D7A0) --------------------------------------------------------
int __cdecl CMainWnd::HandleLVNOdFindItemW(int a1)
{
  return -(a1 != 101);
}

//----- (00C2D7B0) --------------------------------------------------------
int __cdecl CMainWnd::HandleLVNGetDispInfoW(signed int a1, int pItem)
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
  __int64 dbValue2; // ST18_8
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
  const wchar_t *dbValue2_4; // [esp+Ch] [ebp-268h]
  const wchar_t *dbValue2_4a; // [esp+Ch] [ebp-268h]
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

  v129 = pItem;
  v2 = *(_DWORD *)(pItem + 12);
  if ( v2 & 2 )
  {
    *(_DWORD *)(pItem + 40) = *(_DWORD *)(*(_DWORD *)(pItem + 44) + 64);
    return 0;
  }
  if ( !*(_DWORD *)(pItem + 32) || !(v2 & 1) )
    return 0;
  wcscpy_s((wchar_t *)TimeStr, 0x104u, (const wchar_t *)&gszNullString);
  if ( a1 > 104 )
  {
    if ( a1 == 1044 )
    {
      v111 = *(_DWORD *)(pItem + 20);
      v112 = *(_DWORD *)(pItem + 44);
      switch ( v111 )
      {
        case 0:
          ArgList_4a = *(_DWORD *)(v112 + 44);
LABEL_49:
          swprintf((wchar_t *)TimeStr, L"%d", ArgList_4a);
          goto LABEL_50;
        case 1:
          sub_C25AD0(
            v112 + 576,
            *(_QWORD *)(v112 + 584),
            *(_QWORD *)(v112 + 584) >> 32,
            *(_DWORD *)(v112 + 600),
            *(_DWORD *)(v112 + 604),
            &Dst,
            0x10u);
          goto LABEL_41;
        case 2:
          if ( QueryThreadCycleTime && *(_DWORD *)(v112 + 40) )
          {
            v8 = (const wchar_t *)TimeStr;
            if ( !*(_QWORD *)(v112 + 600) )
              goto LABEL_51;
            swprintf((wchar_t *)TimeStr, L"%I64u", *(_DWORD *)(v112 + 600), *(_DWORD *)(v112 + 604));
LABEL_90:
            PE_GetNumberFormat((LPCWSTR)TimeStr, 0x104u);
          }
          else
          {
            v8 = (const wchar_t *)TimeStr;
            if ( !*(_QWORD *)(v112 + 584) )
              goto LABEL_51;
            swprintf((wchar_t *)TimeStr, L"%d", *(_DWORD *)(v112 + 584), *(_DWORD *)(v112 + 588));
          }
          goto LABEL_50;
        case 3:
        case 4:
          if ( *(_DWORD *)(v112 + 644) == -1 )
            goto LABEL_363;
          v113 = v111 - 3;
          if ( v113 )
          {
            if ( v113 != 1 )
              goto LABEL_50;
LABEL_363:
            v8 = (const wchar_t *)(v112 + 52);
          }
          else
          {
            Buffer = *(_DWORD *)(v112 + 644);
            ReadProcessMemory(
              *(HANDLE *)(v112 + 0x27C),
              (LPCVOID)(gdwTebAddressOffset + *(_DWORD *)(v112 + 0x280)),
              &Buffer,
              4u,
              &NumberOfBytesRead);
            v114 = Buffer;
            if ( Buffer != *(_DWORD *)(v112 + 644) )
            {
              v115 = *(void **)(v112 + 648);
              if ( Buffer )
              {
                v116 = (const wchar_t *)sub_C6EFB0(Buffer);
                *(_DWORD *)(v112 + 648) = _wcsdup(v116);
                v114 = Buffer;
              }
              else
              {
                *(_DWORD *)(v112 + 648) = 0;
              }
              if ( v115 )
              {
                free(v115);
                v114 = Buffer;
              }
              *(_DWORD *)(v112 + 644) = v114;
            }
            v8 = *(const wchar_t **)(v112 + 648);
          }
          break;
        default:
          goto LABEL_50;
      }
      goto LABEL_364;
    }
    if ( a1 == 1192 )
    {
      v104 = *(_DWORD *)(pItem + 44);
      v105 = (unsigned int)GetPropW(*(HWND *)pItem, L"resolve");
      v106 = *(_DWORD *)(pItem + 20);
      LOBYTE(Buffer) = v105;
      switch ( v106 )
      {
        case 0:
          swprintf(gpszProtocolName, L"%S", gszProtocolNames[*(_DWORD *)(v104 + 40)]);
          *(_DWORD *)(pItem + 32) = gpszProtocolName;
          return 0;
        case 1:
          if ( v105 )
          {
            if ( *(_WORD *)(v104 + 64) )
            {
              wcscpy_s((wchar_t *)TimeStr, 0x104u, (const wchar_t *)(v104 + 64));
            }
            else if ( sub_C344B0(
                        *(_DWORD *)(v104 + 40),
                        Buffer,
                        1,
                        *(_DWORD *)(v104 + 44),
                        (tagItem124_InTcpUdp *)(v104 + 48),
                        (wchar_t *)TimeStr,
                        0x104u) )
            {
              wcscpy_s((wchar_t *)(v104 + 64), 0x104u, (const wchar_t *)TimeStr);
            }
          }
          else
          {
            sub_C344B0(
              *(_DWORD *)(v104 + 40),
              0,
              1,
              *(_DWORD *)(v104 + 44),
              (tagItem124_InTcpUdp *)(v104 + 48),
              (wchar_t *)TimeStr,
              0x104u);
          }
          v107 = wcslen((const unsigned __int16 *)TimeStr);
          sub_C34670(
            Buffer,
            *(_DWORD *)(v104 + 584),
            gszProtocolNames[*(_DWORD *)(v104 + 40)],
            (wchar_t *)&TimeStr[v107],
            260 - v107);
          v20 = v129;
          v8 = (const wchar_t *)TimeStr;
          goto LABEL_52;
        case 2:
          v108 = *(_DWORD *)(v104 + 40);
          if ( v108 && v108 != 2 )
          {
            *(_DWORD *)(pItem + 32) = L"*:*";
            return 0;
          }
          if ( v105 )
          {
            if ( *(_WORD *)(v104 + 1128) )
            {
              wcscpy_s((wchar_t *)TimeStr, 0x104u, (const wchar_t *)(v104 + 1128));
            }
            else if ( sub_C344B0(
                        v108,
                        Buffer,
                        0,
                        *(_DWORD *)(v104 + 1108),
                        (tagItem124_InTcpUdp *)(v104 + 1112),
                        (wchar_t *)TimeStr,
                        0x104u) )
            {
              wcscpy_s((wchar_t *)(v104 + 1128), 0x104u, (const wchar_t *)TimeStr);
            }
          }
          else
          {
            sub_C344B0(
              v108,
              0,
              0,
              *(_DWORD *)(v104 + 1108),
              (tagItem124_InTcpUdp *)(v104 + 1112),
              (wchar_t *)TimeStr,
              0x104u);
          }
          v109 = wcslen((const unsigned __int16 *)TimeStr);
          sub_C34670(
            Buffer,
            *(_DWORD *)(v104 + 1648),
            gszProtocolNames[*(_DWORD *)(v104 + 40)],
            (wchar_t *)&TimeStr[v109],
            260 - v109);
          v20 = v129;
          v8 = (const wchar_t *)TimeStr;
          break;
        case 3:
          v110 = *(_DWORD *)(v104 + 40);
          if ( v110 && v110 != 2 )
            goto LABEL_50;
          v8 = gszNetStatus[*(_DWORD *)(v104 + 2172)];
          goto LABEL_364;
        case 4:
          v8 = *(const wchar_t **)(v104 + 2184);
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
        v4 = *(_DWORD **)(pItem + 44);
        v5 = gConfig.dwIdsOfHandleColumnMap[*(_DWORD *)(pItem + 20)];
        if ( v5 > 39 )
        {
          v9 = v5 - 1185;
          if ( v9 )
          {
            v10 = v9 - 9;
            if ( v10 )
            {
              v11 = v10 == 114;
              v8 = (const wchar_t *)TimeStr;
              if ( !v11 )
              {
LABEL_51:
                v20 = pItem;
LABEL_52:
                wcsncpy_s((wchar_t *)*(_QWORD *)(v20 + 32), *(_QWORD *)(v20 + 32) >> 32, v8, 0xFFFFFFFF);
                return 0;
              }
              sub_C18CE0(v4[12], (int)(v4 + 14), (wchar_t *)TimeStr);
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
                swprintf((wchar_t *)TimeStr, L"%C%C%C", v13, v15, ArgList_4);
              }
            }
          }
          else
          {
            swprintf((wchar_t *)TimeStr, L"0x%08X", v4[10]);
          }
        }
        else if ( v5 == 39 )
        {
          swprintf((wchar_t *)TimeStr, L"0x%08X", v4[12]);
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
                v8 = (const wchar_t *)(v4 + 558);
                goto LABEL_364;
              }
              goto LABEL_50;
            }
            v8 = (const wchar_t *)(v4 + 14);
LABEL_364:
            if ( !v8 )
            {
LABEL_228:
              *(_DWORD *)(pItem + 32) = &gszNullString;
              return 0;
            }
            if ( v8 != (const wchar_t *)TimeStr )
            {
              *(_DWORD *)(pItem + 32) = v8;
              return 0;
            }
            goto LABEL_51;
          }
          swprintf((wchar_t *)TimeStr, L"0x%X", v4[11]);
        }
      }
      goto LABEL_50;
    }
    v16 = *(_DWORD *)(pItem + 20);
    v17 = *(_DWORD *)(pItem + 44);
    if ( v16 > gConfig.dwProcessColumnCount )
      return 0;
    v18 = gConfig.dwProcessColumnMap[v16];
    if ( v18 <= 1032 )
    {
      if ( v18 == 1032 )
      {
        v8 = *(const wchar_t **)(v17 + 800);
        goto LABEL_364;
      }
      switch ( v18 )
      {
        case 3:
          v8 = *(const wchar_t **)(v17 + 60);
          goto LABEL_364;
        case 4:
          goto LABEL_204;
        case 5:
          ArgList_4a = *(_DWORD *)(v17 + 1368);
          goto LABEL_49;
        case 6:
          goto LABEL_54;
        case 7:
          v19 = *(double *)(v17 + 1304);
          if ( v19 <= 0.005 )
          {
            wcscpy_s(&Dst, 0x10u, (const wchar_t *)&gszNullString);
          }
          else if ( gConfig.bShowCpuFractions )
          {
            sub_C113E0(&Dst, L"%02.2f", LODWORD(v19), HIDWORD(v19));
          }
          else
          {
            sub_C113E0(&Dst, L"%0.0f", LODWORD(v19), HIDWORD(v19));
          }
          goto LABEL_41;
        case 9:
          v21 = *(_DWORD *)(v17 + 920);
          goto LABEL_62;
        case 10:
          swprintf((wchar_t *)TimeStr, L"%I64u", *(_DWORD *)(v17 + 924) >> 10, 0);
          PE_GetNumberFormat((LPCWSTR)TimeStr, 0x104u);
          wcscat_s((wchar_t *)TimeStr, 0x104u, L" K");
          goto LABEL_50;
        case 18:
          ArgList_4b = *(_DWORD *)(v17 + 92);
          goto LABEL_55;
        case 19:
          v8 = *(const wchar_t **)(v17 + 88);
          goto LABEL_364;
        case 25:
          v8 = (const wchar_t *)(v17 + 654);
          goto LABEL_364;
        case 35:
          v8 = (const wchar_t *)(v17 + 104);
          goto LABEL_364;
        case 38:
          v8 = *(const wchar_t **)(v17 + 784);
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
            v8 = *(const wchar_t **)(v17 + 788);
            goto LABEL_364;
          case 1055:
            if ( *(_BYTE *)(v17 + 40) < 0 )
            {
              *(_DWORD *)(pItem + 32) = L"Suspended";
              return 0;
            }
            sub_C25AD0(
              v17 + 1296,
              *(_QWORD *)(v17 + 1336),
              *(_QWORD *)(v17 + 1336) >> 32,
              *(_DWORD *)(v17 + 1352),
              *(_DWORD *)(v17 + 1356),
              &Dst,
              0x10u);
            break;
          case 1056:
            v27 = *(_DWORD *)(v17 + 100);
            goto LABEL_113;
          case 1059:
            ArgList_4c = 0;
            ArgListb = *(_DWORD *)(v17 + 880);
            goto LABEL_88;
          case 1060:
            swprintf((wchar_t *)TimeStr, L"%I64u", *(_DWORD *)(v17 + 888) >> 10, 0);
            PE_GetNumberFormat((LPCWSTR)TimeStr, 0x104u);
            wcscat_s((wchar_t *)TimeStr, 0x104u, L" K");
            goto LABEL_50;
          case 1061:
            v8 = *(const wchar_t **)(v17 + 792);
            goto LABEL_364;
          case 1062:
            swprintf((wchar_t *)TimeStr, L"%I64u", *(_DWORD *)(v17 + 896) >> 10, 0);
            PE_GetNumberFormat((LPCWSTR)TimeStr, 0x104u);
            wcscat_s((wchar_t *)TimeStr, 0x104u, L" K");
            goto LABEL_50;
          case 1063:
            swprintf((wchar_t *)TimeStr, L"%I64u", *(_DWORD *)(v17 + 900) >> 10, 0);
            PE_GetNumberFormat((LPCWSTR)TimeStr, 0x104u);
            wcscat_s((wchar_t *)TimeStr, 0x104u, L" K");
            goto LABEL_50;
          case 1064:
            swprintf((wchar_t *)TimeStr, L"%I64u", *(_DWORD *)(v17 + 904) >> 10, 0);
            PE_GetNumberFormat((LPCWSTR)TimeStr, 0x104u);
            wcscat_s((wchar_t *)TimeStr, 0x104u, L" K");
            goto LABEL_50;
          case 1065:
LABEL_54:
            ArgList_4b = *(_DWORD *)(v17 + 96);
            goto LABEL_55;
          case 1066:
            ArgList_4b = *(_DWORD *)(v17 + 1380);
            goto LABEL_55;
          case 1067:
            ArgList_4b = *(_DWORD *)(v17 + 1376);
            goto LABEL_55;
          case 1068:
            ArgList_4b = *(_DWORD *)(v17 + 960);
            ArgList = L"%u";
            goto LABEL_56;
          case 1069:
            v31 = *(_DWORD *)(v17 + 972);
            v32 = *(_DWORD *)(v17 + 968);
            goto LABEL_188;
          case 1070:
            ArgList_4b = *(_DWORD *)(v17 + 992);
            ArgList = L"%u";
            goto LABEL_56;
          case 1071:
            v31 = *(_DWORD *)(v17 + 1004);
            v32 = *(_DWORD *)(v17 + 1000);
            goto LABEL_188;
          case 1072:
            ArgList_4b = *(_DWORD *)(v17 + 1024);
            ArgList = L"%u";
            goto LABEL_56;
          case 1073:
            v31 = *(_DWORD *)(v17 + 1036);
            v32 = *(_DWORD *)(v17 + 1032);
            goto LABEL_188;
          case 1086:
            v28 = *(_DWORD *)(v17 + 624);
            v29 = (const FILETIME *)(v17 + 624);
            if ( !(v29->dwHighDateTime | v28) )
              goto LABEL_184;
            FileTimeToLocalFileTime(v29, &LocalFileTime);
            FileTimeToSystemTime(&LocalFileTime, &SystemTime);
            GetTimeFormatW(0x400u, 0, &SystemTime, 0, (LPWSTR)TimeStr, 260);
            wcscat_s((wchar_t *)TimeStr, 0x104u, L" ");
            v30 = wcslen((const unsigned __int16 *)TimeStr);
            GetDateFormatW(0x400u, 0, &SystemTime, 0, (LPWSTR)&TimeStr[v30], 260 - v30);
            goto LABEL_50;
          case 1087:
            dbValue2 = *(_QWORD *)(v17 + 1320);
            v20 = v129;
            swprintf(
              (wchar_t *)TimeStr,
              L"%I64d:%02I64d:%02I64d.%03I64d",
              *(_QWORD *)(*(_DWORD *)(v129 + 44) + 1320) / 0x861C46800ui64,
              *(_QWORD *)(*(_DWORD *)(v129 + 44) + 1320) / 0x23C34600ui64 % 0x3C,
              dbValue2 / 10000000 % 60,
              dbValue2 % 10000000 / 10000);
            v8 = (const wchar_t *)TimeStr;
            goto LABEL_52;
          case 1091:
            ArgList_4c = *(_DWORD *)(v17 + 1348);
            ArgListb = *(_DWORD *)(v17 + 1344);
            goto LABEL_88;
          case 1092:
            v26 = *(_DWORD *)(v17 + 1340);
            if ( v26 < 0 || v26 <= 0 && !*(_DWORD *)(v17 + 1336) )
              goto LABEL_50;
            ArgList_4c = *(_DWORD *)(v17 + 1340);
            ArgListb = *(_DWORD *)(v17 + 1336);
LABEL_88:
            dbValue2_4a = L"%I64d";
            goto LABEL_89;
          case 1094:
            v33 = *(int **)(v17 + 1284);
            if ( !v33 )
              goto LABEL_50;
            v34 = *v33;
            v35 = v33[1];
            v11 = *(_QWORD *)v33 == 0i64;
            v8 = (const wchar_t *)TimeStr;
            if ( v11 )
              goto LABEL_51;
            swprintf((wchar_t *)TimeStr, L"%I64d", v34, v35);
            goto LABEL_90;
          case 1095:
            v36 = *(_DWORD *)(v17 + 1284);
            if ( !v36 )
              goto LABEL_50;
            v37 = *(double *)(v36 + 8);
            goto LABEL_129;
          case 1096:
            v38 = *(_DWORD *)(v17 + 1284);
            if ( !v38 )
              goto LABEL_50;
            v39 = *(_DWORD *)(v38 + 16);
            v40 = *(_DWORD *)(v38 + 20);
            v11 = *(_QWORD *)(v38 + 16) == 0i64;
            v8 = (const wchar_t *)TimeStr;
            if ( v11 )
              goto LABEL_51;
            swprintf((wchar_t *)TimeStr, L"%I64d", v39, v40);
            goto LABEL_90;
          case 1097:
            v41 = *(_DWORD *)(v17 + 1284);
            if ( !v41 )
              goto LABEL_50;
            v42 = *(_DWORD *)(v41 + 48);
            v43 = *(_DWORD *)(v41 + 52);
            v11 = *(_QWORD *)(v41 + 48) == 0i64;
            v8 = (const wchar_t *)TimeStr;
            if ( v11 )
              goto LABEL_51;
            swprintf((wchar_t *)TimeStr, L"%I64d", v42, v43);
            goto LABEL_90;
          case 1098:
            v44 = *(_DWORD *)(v17 + 1284);
            if ( !v44 )
              goto LABEL_50;
            v45 = *(_DWORD *)(v44 + 32);
            v46 = *(_DWORD *)(v44 + 36);
            v11 = *(_QWORD *)(v44 + 32) == 0i64;
            v8 = (const wchar_t *)TimeStr;
            if ( v11 )
              goto LABEL_51;
            swprintf((wchar_t *)TimeStr, L"%I64d", v45, v46);
            goto LABEL_90;
          case 1099:
            v47 = *(_DWORD *)(v17 + 1284);
            if ( !v47 )
              goto LABEL_50;
            v48 = *(_DWORD *)(v47 + 24);
            v49 = *(_DWORD *)(v47 + 28);
            v11 = *(_QWORD *)(v47 + 24) == 0i64;
            v8 = (const wchar_t *)TimeStr;
            if ( v11 )
              goto LABEL_51;
            swprintf((wchar_t *)TimeStr, L"%I64d", v48, v49);
            goto LABEL_90;
          case 1100:
            v50 = *(_DWORD *)(v17 + 1284);
            if ( !v50 )
              goto LABEL_50;
            v51 = *(_DWORD *)(v50 + 56);
            v52 = *(_DWORD *)(v50 + 60);
            v11 = *(_QWORD *)(v50 + 56) == 0i64;
            v8 = (const wchar_t *)TimeStr;
            if ( v11 )
              goto LABEL_51;
            swprintf((wchar_t *)TimeStr, L"%I64d", v51, v52);
            goto LABEL_90;
          case 1101:
            v53 = *(_DWORD *)(v17 + 1284);
            if ( !v53 )
              goto LABEL_50;
            v54 = *(_DWORD *)(v53 + 40);
            v55 = *(_DWORD *)(v53 + 44);
            v11 = *(_QWORD *)(v53 + 40) == 0i64;
            v8 = (const wchar_t *)TimeStr;
            if ( v11 )
              goto LABEL_51;
            swprintf((wchar_t *)TimeStr, L"%I64d", v54, v55);
            goto LABEL_90;
          case 1103:
            v59 = *(_DWORD *)(v17 + 1284);
            if ( !v59 )
              goto LABEL_50;
            v60 = *(_DWORD *)(v59 + 112);
            v61 = *(_DWORD *)(v59 + 116);
            v11 = *(_QWORD *)(v59 + 112) == 0i64;
            v8 = (const wchar_t *)TimeStr;
            if ( v11 )
              goto LABEL_51;
            swprintf((wchar_t *)TimeStr, L"%I64d", v60, v61);
            goto LABEL_90;
          case 1104:
            v62 = *(_DWORD *)(v17 + 1284);
            if ( !v62 )
              goto LABEL_50;
            v63 = *(_DWORD *)(v62 + 64);
            v64 = *(_DWORD *)(v62 + 68);
            v11 = *(_QWORD *)(v62 + 64) == 0i64;
            v8 = (const wchar_t *)TimeStr;
            if ( v11 )
              goto LABEL_51;
            swprintf((wchar_t *)TimeStr, L"%I64d", v63, v64);
            goto LABEL_90;
          case 1105:
            v65 = *(_DWORD *)(v17 + 1284);
            if ( !v65 )
              goto LABEL_50;
            v66 = *(_DWORD *)(v65 + 72);
            v67 = *(_DWORD *)(v65 + 76);
            v11 = *(_QWORD *)(v65 + 72) == 0i64;
            v8 = (const wchar_t *)TimeStr;
            if ( v11 )
              goto LABEL_51;
            swprintf((wchar_t *)TimeStr, L"%I64d", v66, v67);
            goto LABEL_90;
          case 1106:
            v68 = *(_DWORD *)(v17 + 1284);
            if ( !v68 )
              goto LABEL_50;
            v69 = *(_DWORD *)(v68 + 80);
            v70 = *(_DWORD *)(v68 + 84);
            v11 = *(_QWORD *)(v68 + 80) == 0i64;
            v8 = (const wchar_t *)TimeStr;
            if ( v11 )
              goto LABEL_51;
            swprintf((wchar_t *)TimeStr, L"%I64d", v69, v70);
            goto LABEL_90;
          case 1107:
            v71 = *(_DWORD *)(v17 + 1284);
            if ( !v71 )
              goto LABEL_50;
            v37 = *(double *)(v71 + 88);
LABEL_129:
            v8 = (const wchar_t *)TimeStr;
            if ( v37 == 0.0 )
              goto LABEL_51;
            swprintf((wchar_t *)TimeStr, L"%02.02f", LODWORD(v37), HIDWORD(v37));
            goto LABEL_50;
          case 1108:
            v72 = *(_DWORD *)(v17 + 1284);
            if ( !v72 )
              goto LABEL_50;
            v73 = *(_DWORD *)(v72 + 104);
            v74 = *(_DWORD *)(v72 + 108);
            v11 = *(_QWORD *)(v72 + 104) == 0i64;
            v8 = (const wchar_t *)TimeStr;
            if ( v11 )
              goto LABEL_51;
            swprintf((wchar_t *)TimeStr, L"%I64d", v73, v74);
            goto LABEL_90;
          case 1109:
            v75 = *(_DWORD *)(v17 + 1284);
            if ( !v75 )
              goto LABEL_50;
            v76 = *(_DWORD *)(v75 + 120);
            v77 = *(_DWORD *)(v75 + 124);
            v11 = *(_QWORD *)(v75 + 120) == 0i64;
            v8 = (const wchar_t *)TimeStr;
            if ( v11 )
              goto LABEL_51;
            swprintf((wchar_t *)TimeStr, L"%I64d", v76, v77);
            goto LABEL_90;
          case 1110:
            v56 = *(_DWORD *)(v17 + 1284);
            if ( !v56 )
              goto LABEL_50;
            v57 = *(_DWORD *)(v56 + 128);
            v58 = *(_DWORD *)(v56 + 132);
            v11 = *(_QWORD *)(v56 + 128) == 0i64;
            v8 = (const wchar_t *)TimeStr;
            if ( v11 )
              goto LABEL_51;
            swprintf((wchar_t *)TimeStr, L"%I64d", v57, v58);
            goto LABEL_90;
          case 1114:
            swprintf((wchar_t *)TimeStr, L"%I64u", *(_DWORD *)(v17 + 876) >> 10, 0);
            PE_GetNumberFormat((LPCWSTR)TimeStr, 0x104u);
            wcscat_s((wchar_t *)TimeStr, 0x104u, L" K");
            goto LABEL_50;
          case 1115:
            ArgLista = *(_DWORD *)(v17 + 936) >> 10;
            dbValue2_4 = L"%I64d";
            goto LABEL_63;
          case 1116:
            swprintf((wchar_t *)TimeStr, L"%I64u", *(_DWORD *)(v17 + 940) >> 10, 0);
            PE_GetNumberFormat((LPCWSTR)TimeStr, 0x104u);
            wcscat_s((wchar_t *)TimeStr, 0x104u, L" K");
            goto LABEL_50;
          case 1118:
            swprintf((wchar_t *)TimeStr, L"%I64u", *(_DWORD *)(v17 + 948) >> 10, 0);
            PE_GetNumberFormat((LPCWSTR)TimeStr, 0x104u);
            wcscat_s((wchar_t *)TimeStr, 0x104u, L" K");
            goto LABEL_50;
          case 1179:
            if ( !*(_DWORD *)(v17 + 884) )
              goto LABEL_50;
            ArgList_4b = *(_DWORD *)(v17 + 884);
            goto LABEL_55;
          case 1180:
            v8 = *(const wchar_t **)(v17 + 820);
            goto LABEL_364;
          case 1181:
            v8 = *(const wchar_t **)(v17 + 796);
            goto LABEL_364;
          case 1187:
            v8 = *(const wchar_t **)(v17 + 836);
            goto LABEL_364;
          case 1190:
            goto LABEL_79;
          case 1192:
            v24 = *(_DWORD *)(v17 + 892);
            if ( v24 )
            {
              swprintf((wchar_t *)TimeStr, L"%d", v24 / 1024);
              PE_GetNumberFormat((LPCWSTR)TimeStr, 0x104u);
              wcscat_s((wchar_t *)TimeStr, 0x104u, L" K");
            }
            goto LABEL_50;
          case 1195:
            ArgList_4c = *(_DWORD *)(v17 + 1364);
            ArgListb = *(_DWORD *)(v17 + 1360);
            dbValue2_4a = L"%I64u";
            goto LABEL_89;
          case 1196:
            if ( !*(_DWORD *)(v17 + 616) )
              goto LABEL_50;
            v23 = L"Not responding";
            if ( !*(_BYTE *)(v17 + 620) )
              v23 = L"Running";
            *(_DWORD *)(pItem + 32) = v23;
            return 0;
          case 1199:
            sub_C67720(v17, (wchar_t *)TimeStr, 0x104u);
            goto LABEL_50;
          case 1200:
            v25 = *(_DWORD *)(v17 + 1356);
            if ( v25 < 0 || v25 <= 0 && !*(_DWORD *)(v17 + 1352) )
              goto LABEL_50;
            ArgList_4c = *(_DWORD *)(v17 + 1356);
            ArgListb = *(_DWORD *)(v17 + 1352);
            dbValue2_4a = L"%I64u";
LABEL_89:
            swprintf((wchar_t *)TimeStr, dbValue2_4a, ArgListb, ArgList_4c);
            goto LABEL_90;
          default:
            goto LABEL_50;
        }
LABEL_41:
        if ( Dst == 48 && (v132 == 48 || !v132) )
        {
          *(_DWORD *)(pItem + 32) = L"    ";
          return 0;
        }
        wcscpy_s((wchar_t *)TimeStr, 0x104u, &Dst);
        goto LABEL_50;
      }
      v21 = *(_DWORD *)(v17 + 944);
      goto LABEL_62;
    }
    if ( v18 <= 1609 )
    {
      if ( v18 == 1609 )
      {
        if ( *(_DWORD *)(v17 + 1072) )
        {
          ArgList_4b = *(_DWORD *)(v17 + 1072);
          ArgList = L"%u";
LABEL_56:
          swprintf((wchar_t *)TimeStr, ArgList, ArgList_4b);
LABEL_57:
          PE_GetNumberFormat((LPCWSTR)TimeStr, 0x104u);
        }
      }
      else
      {
        switch ( v18 )
        {
          case 1326:
            if ( !*(_DWORD *)(v17 + 976) )
              goto LABEL_50;
            ArgList_4b = *(_DWORD *)(v17 + 976);
            goto LABEL_55;
          case 1327:
            v31 = *(_DWORD *)(v17 + 988);
            v32 = *(_DWORD *)(v17 + 984);
            goto LABEL_188;
          case 1328:
            if ( !*(_DWORD *)(v17 + 1008) )
              goto LABEL_50;
            ArgList_4b = *(_DWORD *)(v17 + 1008);
            goto LABEL_55;
          case 1329:
            v31 = *(_DWORD *)(v17 + 1020);
            v32 = *(_DWORD *)(v17 + 1016);
            goto LABEL_188;
          case 1332:
            v31 = *(_DWORD *)(v17 + 1052);
            v32 = *(_DWORD *)(v17 + 1048);
            goto LABEL_188;
          case 1333:
            v31 = *(_DWORD *)(v17 + 1060);
            v32 = *(_DWORD *)(v17 + 1056);
            goto LABEL_188;
          case 1335:
            if ( !*(_DWORD *)(v17 + 1040) )
              goto LABEL_50;
            ArgList_4b = *(_DWORD *)(v17 + 1040);
            goto LABEL_55;
          case 1336:
            v8 = *(const wchar_t **)(v17 + 816);
            goto LABEL_364;
          case 1337:
            if ( !(*(_DWORD *)(v17 + 40) & 0x200) )
              goto LABEL_50;
            *(_DWORD *)(pItem + 32) = L"Virtualized";
            return 0;
          case 1338:
            v78 = *(_WORD *)(v17 + 650);
            if ( v78 & 0x40 )
              goto LABEL_182;
            goto LABEL_183;
          case 1339:
            v27 = *(_DWORD *)(v17 + 872);
LABEL_113:
            if ( v27 == -1 )
              goto LABEL_50;
            ArgList_4a = v27;
            goto LABEL_49;
          case 1340:
            sub_C67790(*(_DWORD *)(v17 + 952), (wchar_t *)TimeStr, 0x104u);
            goto LABEL_50;
          case 1341:
            v21 = *(_DWORD *)(v17 + 912);
            goto LABEL_62;
          case 1342:
            v21 = *(_DWORD *)(v17 + 916);
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
            if ( !*(_DWORD *)(v17 + 1088) )
              goto LABEL_50;
            ArgList_4b = *(_DWORD *)(v17 + 1088);
            goto LABEL_55;
          case 1611:
            if ( !*(_DWORD *)(v17 + 1104) )
              goto LABEL_50;
            ArgList_4b = *(_DWORD *)(v17 + 1104);
            ArgList = L"%u";
            goto LABEL_56;
          case 1612:
            if ( !*(_DWORD *)(v17 + 1120) )
              goto LABEL_50;
            ArgList_4b = *(_DWORD *)(v17 + 1120);
            goto LABEL_55;
          case 1613:
            if ( !*(_DWORD *)(v17 + 1136) )
              goto LABEL_50;
            ArgList_4b = *(_DWORD *)(v17 + 1136);
            ArgList = L"%u";
            goto LABEL_56;
          case 1614:
            if ( !*(_DWORD *)(v17 + 1152) )
              goto LABEL_50;
            ArgList_4b = *(_DWORD *)(v17 + 1152);
            goto LABEL_55;
          case 1616:
            v80 = (double)*(signed __int64 *)(v17 + 1096);
            goto LABEL_189;
          case 1617:
            v31 = *(_DWORD *)(v17 + 1084);
            v32 = *(_DWORD *)(v17 + 1080);
            goto LABEL_188;
          case 1618:
            v31 = *(_DWORD *)(v17 + 1116);
            v32 = *(_DWORD *)(v17 + 1112);
            goto LABEL_188;
          case 1619:
            v31 = *(_DWORD *)(v17 + 1132);
            v32 = *(_DWORD *)(v17 + 1128);
            goto LABEL_188;
          case 1620:
            v80 = (double)*(signed __int64 *)(v17 + 1144);
            goto LABEL_189;
          case 1621:
            if ( *(_QWORD *)(v17 + 1160) )
              PE_FormatDouble(
                0,
                (wchar_t *)TimeStr,
                0x104u,
                (double)*(signed __int64 *)(v17 + 1160),
                0.0,
                COERCE_LONG_DOUBLE(0i64 >> 63));
            goto LABEL_50;
          case 1622:
            v80 = (double)*(signed __int64 *)(v17 + 1168);
            goto LABEL_189;
          case 1623:
            v8 = (const wchar_t *)TimeStr;
            if ( !*(_QWORD *)(v17 + 1184) )
              goto LABEL_51;
            swprintf((wchar_t *)TimeStr, L"%u", *(_DWORD *)(v17 + 1176));
            goto LABEL_57;
          case 1624:
            if ( !*(_DWORD *)(v17 + 1192) )
              goto LABEL_50;
            ArgList_4b = *(_DWORD *)(v17 + 1192);
            goto LABEL_55;
          case 1625:
            if ( !*(_DWORD *)(v17 + 1208) )
              goto LABEL_50;
            ArgList_4b = *(_DWORD *)(v17 + 1208);
            ArgList = L"%u";
            goto LABEL_56;
          case 1626:
            if ( !*(_DWORD *)(v17 + 1224) )
              goto LABEL_50;
            ArgList_4b = *(_DWORD *)(v17 + 1224);
            goto LABEL_55;
          case 1627:
            if ( !*(_DWORD *)(v17 + 1240) )
              goto LABEL_50;
            ArgList_4b = *(_DWORD *)(v17 + 1240);
            ArgList = L"%u";
            goto LABEL_56;
          case 1628:
            if ( !*(_DWORD *)(v17 + 1256) )
              goto LABEL_50;
            ArgList_4b = *(_DWORD *)(v17 + 1256);
LABEL_55:
            ArgList = L"%d";
            goto LABEL_56;
          case 1630:
            v31 = *(_DWORD *)(v17 + 1188);
            v32 = *(_DWORD *)(v17 + 1184);
            goto LABEL_188;
          case 1631:
            v31 = *(_DWORD *)(v17 + 1204);
            v32 = *(_DWORD *)(v17 + 1200);
            goto LABEL_188;
          case 1632:
            v31 = *(_DWORD *)(v17 + 1220);
            v32 = *(_DWORD *)(v17 + 1216);
            goto LABEL_188;
          case 1633:
            v31 = *(_DWORD *)(v17 + 1236);
            v32 = *(_DWORD *)(v17 + 1232);
            goto LABEL_188;
          case 1634:
            v31 = *(_DWORD *)(v17 + 1252);
            v32 = *(_DWORD *)(v17 + 1248);
            goto LABEL_188;
          case 1635:
            v31 = *(_DWORD *)(v17 + 1268);
            v32 = *(_DWORD *)(v17 + 1264);
            goto LABEL_188;
          case 1636:
            v31 = *(_DWORD *)(v17 + 1276);
            v32 = *(_DWORD *)(v17 + 1272);
LABEL_188:
            v79 = (double)(signed __int64)__PAIR__(v31, v32);
            v80 = v79;
LABEL_189:
            PE_GetDoubleString((wchar_t *)TimeStr, v80);
            goto LABEL_50;
          case 1637:
            sub_C25AD0(v17 + 1312, 0, 0, 0, 0, &Dst, 0x10u);
            goto LABEL_41;
          case 1638:
LABEL_204:
            if ( *(_DWORD *)(v17 + 68) < 0 )
              goto LABEL_184;
            ArgList_4a = *(_DWORD *)(v17 + 68);
            goto LABEL_49;
          case 1650:
            sub_C25AD0(v17 + 1384, 0, 0, 0, 0, &Dst, 0x10u);
            goto LABEL_41;
          case 1651:
            v8 = (const wchar_t *)TimeStr;
            if ( !*(_QWORD *)(v17 + 1408) )
              goto LABEL_51;
            swprintf((wchar_t *)TimeStr, L"%I64u", *(_DWORD *)(v17 + 1408), *(_DWORD *)(v17 + 1412));
            goto LABEL_64;
          case 1652:
            v8 = (const wchar_t *)TimeStr;
            if ( !*(_QWORD *)(v17 + 1424) )
              goto LABEL_51;
            swprintf((wchar_t *)TimeStr, L"%I64u", *(_DWORD *)(v17 + 1424), *(_DWORD *)(v17 + 1428));
            goto LABEL_64;
          case 1653:
            v8 = (const wchar_t *)TimeStr;
            if ( !*(_QWORD *)(v17 + 1440) )
              goto LABEL_51;
            swprintf((wchar_t *)TimeStr, L"%I64u", *(_DWORD *)(v17 + 1440), *(_DWORD *)(v17 + 1444));
            goto LABEL_64;
          case 1654:
            v8 = *(const wchar_t **)(v17 + 824);
            goto LABEL_364;
          case 1656:
            v8 = *(const wchar_t **)(v17 + 828);
            goto LABEL_364;
          case 1667:
            switch ( *(_DWORD *)(v17 + 644) )
            {
              case 0xFFFFFFFF:
                goto LABEL_228;
              case 0:
                *(_DWORD *)(pItem + 32) = L"Unaware";
                return 0;
              case 1:
                *(_DWORD *)(pItem + 32) = L"System Aware";
                return 0;
              case 2:
                *(_DWORD *)(pItem + 32) = L"Per-Monitor Aware";
                return 0;
              default:
                ArgList_4a = *(_DWORD *)(v17 + 644);
                break;
            }
            goto LABEL_49;
          case 1670:
            sub_C71A50(*(_DWORD *)(v17 + 844), (wchar_t *)TimeStr);
            goto LABEL_50;
          case 1673:
            v81 = *(_BYTE *)(v17 + 649);
            if ( !v81 )
              goto LABEL_50;
            if ( (v81 & 0xF0u) < 0x70 )
            {
              v82 = &aPsprotectedsig[64 * ((unsigned int)v81 >> 4)];
              v83 = &aPsprotectedsig[64 * ((unsigned int)v81 >> 4)];
              do
              {
                v84 = *v82;
                ++v82;
              }
              while ( v84 );
              v85 = (char *)v82 - (char *)v83;
              v86 = &v133;
              do
              {
                v87 = v86[1];
                ++v86;
              }
              while ( v87 );
              qmemcpy(v86, v83, v85);
            }
            if ( (*(_BYTE *)(v17 + 649) & 7) == 1 )
            {
              v88 = &v133;
              do
              {
                v89 = v88[1];
                ++v88;
              }
              while ( v89 );
              *(_DWORD *)v88 = *(_DWORD *)L"-Light";
              *((_DWORD *)v88 + 1) = *(_DWORD *)L"ight";
              *((_DWORD *)v88 + 2) = *(_DWORD *)L"ht";
              v88[6] = aLight[6];
            }
            v20 = v129;
            v8 = (const wchar_t *)TimeStr;
            goto LABEL_52;
          case 1674:
            v90 = (const WCHAR **)L"UI Access";
            if ( !(*(_DWORD *)(v17 + 40) & 0x2000) )
              v90 = &gszNullString;
            *(_DWORD *)(pItem + 32) = v90;
            return 0;
          default:
            goto LABEL_50;
        }
        goto LABEL_50;
      }
      v78 = *(_WORD *)(v17 + 650);
      if ( !(*(_WORD *)(v17 + 650) & 0x4000) )
      {
LABEL_183:
        if ( !v78 )
        {
LABEL_184:
          *(_DWORD *)(pItem + 32) = L"n/a";
          return 0;
        }
        goto LABEL_50;
      }
LABEL_276:
      *(_DWORD *)(pItem + 32) = L"CFG";
      return 0;
    }
LABEL_50:
    v8 = (const wchar_t *)TimeStr;
    goto LABEL_51;
  }
  v91 = *(_DWORD *)(pItem + 44);
  v92 = gConfig.dwDllColumnMap[*(_DWORD *)(pItem + 20)];
  if ( v92 <= 30 )
  {
    if ( v92 == 30 )
    {
      v8 = (const wchar_t *)(v91 + 76);
      goto LABEL_364;
    }
    switch ( v92 )
    {
      case 23:
        swprintf((wchar_t *)TimeStr, L"0x%X", *(_DWORD *)(v91 + 36));
        goto LABEL_50;
      case 24:
        swprintf((wchar_t *)TimeStr, L"0x%X", *(_DWORD *)(v91 + 56));
        goto LABEL_50;
      case 25:
        v8 = (const wchar_t *)(v91 + 206);
        goto LABEL_364;
      case 26:
        if ( !wcsrchr(*(const wchar_t **)(v91 + 344), 0x5Cu) )
          goto LABEL_304;
        v8 = wcsrchr(*(const wchar_t **)(v91 + 344), 0x5Cu) + 1;
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
      v21 = *(_DWORD *)(v91 + 380);
    }
    else
    {
      if ( v92 <= 1074 )
      {
        if ( v92 == 1074 )
        {
          swprintf((wchar_t *)TimeStr, L"0x%X", *(_DWORD *)(v91 + 48));
          goto LABEL_50;
        }
        v93 = v92 - 40;
        if ( v93 )
        {
          v94 = v93 - 2;
          if ( !v94 )
          {
            v8 = *(const wchar_t **)(v91 + 336);
            goto LABEL_364;
          }
          if ( v94 == 991 )
          {
            v8 = *(const wchar_t **)(v91 + 340);
            goto LABEL_364;
          }
          goto LABEL_50;
        }
        v95 = L"Data";
        if ( !(*(_BYTE *)(v91 + 44) & 2) )
          v95 = L"Image";
        *(_DWORD *)(pItem + 32) = v95;
        return 0;
      }
      v96 = v92 - 1111;
      if ( !v96 )
      {
LABEL_304:
        v8 = *(const wchar_t **)(v91 + 344);
        goto LABEL_364;
      }
      v97 = v96 - 4;
      if ( v97 )
      {
        if ( v97 != 1 )
          goto LABEL_50;
        v21 = *(_DWORD *)(v91 + 372);
      }
      else
      {
        v21 = *(_DWORD *)(v91 + 368);
      }
    }
LABEL_62:
    ArgLista = v21 >> 10;
    dbValue2_4 = L"%I64u";
LABEL_63:
    swprintf((wchar_t *)TimeStr, dbValue2_4, ArgLista, 0);
LABEL_64:
    PE_GetNumberFormat((LPCWSTR)TimeStr, 0x104u);
    wcscat_s((wchar_t *)TimeStr, 0x104u, L" K");
    goto LABEL_50;
  }
  if ( v92 <= 1338 )
  {
    if ( v92 == 1338 )
    {
      if ( *(_BYTE *)(v91 + 54) & 0x40 )
      {
LABEL_182:
        *(_DWORD *)(pItem + 32) = L"ASLR";
        result = 0;
      }
      else
      {
        v100 = (const WCHAR **)L"n/a";
        if ( !(*(_BYTE *)(v91 + 44) & 2) )
          v100 = &gszNullString;
        *(_DWORD *)(pItem + 32) = v100;
        result = 0;
      }
      return result;
    }
    v98 = v92 - 1187;
    if ( !v98 )
    {
      v8 = *(const wchar_t **)(v91 + 356);
      goto LABEL_364;
    }
    v99 = v98 - 3;
    if ( !v99 )
    {
LABEL_79:
      *(_DWORD *)(pItem + 32) = L"32-bit";
      return 0;
    }
    if ( v99 != 127 )
      goto LABEL_50;
    v21 = *(_DWORD *)(v91 + 376);
    goto LABEL_62;
  }
  v101 = v92 - 1656;
  if ( !v101 )
  {
    v8 = *(const wchar_t **)(v91 + 348);
    goto LABEL_364;
  }
  v102 = v101 - 14;
  if ( !v102 )
  {
    sub_C71A50(*(_DWORD *)(v91 + 364), (wchar_t *)TimeStr);
    goto LABEL_50;
  }
  if ( v102 != 39087 )
    goto LABEL_50;
  if ( *(_WORD *)(v91 + 54) & 0x4000 )
    goto LABEL_276;
  v103 = (const WCHAR **)L"n/a";
  if ( *(_WORD *)(v91 + 54) )
    v103 = &gszNullString;
  *(_DWORD *)(pItem + 32) = v103;
  return 0;
}
// CAE080: using guessed type wchar_t aSuspended[10];
// CAE094: using guessed type wchar_t asc_CAE094[5];
// CAE0A0: using guessed type wchar_t aVirtualized[12];
// CAE0C8: using guessed type wchar_t aUiAccess[10];
// CAE0DC: using guessed type wchar_t aUnaware[8];
// CAE0EC: using guessed type wchar_t aSystemAware[13];
// CAE108: using guessed type wchar_t aPerMonitorAwar[18];
// CAE12C: using guessed type wchar_t aAslr[5];
// CAE138: using guessed type wchar_t aCfg[4];
// CAE140: using guessed type wchar_t a32Bit[7];
// CAE18C: using guessed type wchar_t aNotResponding[15];
// CAE200: using guessed type wchar_t a0x08x[7];
// CAE220: using guessed type wchar_t aData_0[5];
// CAE250: using guessed type wchar_t asc_CAE250[4];
// CAE9C8: using guessed type double db_zeropointzerozerofive;
// CCD238: using guessed type wchar_t *gszNetStatus[13];
// CDB1CC: using guessed type int gdwTebAddressOffset;
// C2D7B0: using guessed type WCHAR TimeStr[260];

//----- (00C2F490) --------------------------------------------------------
int __cdecl CMainWnd::HandleLVMKeydown(int a1, LPNMLVKEYDOWN a2)
{
  WPARAM vkey; // eax
  int result; // eax

  if ( a1 != IDC_TREEVIEW_LIST
    || (vkey = a2->wVKey, vkey != VK_TAB) && vkey != VK_HOME && vkey != VK_END && vkey != VK_RETURN )
  {
    result = 0;
  }
  else
  {
    result = Proxy_ListCtrlWndProc(a2->hdr.hwndFrom, WM_KEYDOWN, vkey, 0);
  }
  return result;
}

//----- (00C2F4D0) --------------------------------------------------------
int __cdecl CMainWnd::HandleLVNItemChanged(HMENU uId)
{
  HWND hWnd; // edi
  LRESULT bRet; // eax
  tagTREEVIEWLISTITEMPARAM *pItem; // edi
  int dwProcessId; // eax
  HMENU v5; // eax
  int dwProcessIoPriority; // ecx
  HMENU v7; // esi
  const WCHAR *pszText2; // eax
  const WCHAR *pszText; // eax
  BOOL v10; // ST10_4
  HMENU v11; // eax
  HMENU v12; // eax
  LVITEMW ItemText; // [esp+8h] [ebp-68h]
  LVITEMW Item; // [esp+3Ch] [ebp-34h]
  HMENU hMnua; // [esp+78h] [ebp+8h]

  Item.mask = 0;
  memset(&Item.iItem, 0, 0x30u);
  if ( uId == (HMENU)IDC_TREEVIEW_LIST )
  {
    hWnd = ghWndTreeListView;
  }
  else if ( uId == (HMENU)IDC_LISTCTRL_HANDLES )
  {
    hWnd = ghWndHandlesListCtrl;
  }
  else
  {
    if ( uId != (HMENU)104 )
      return 0;
    hWnd = ghWndDllsListCtrl;
  }
  Item.iItem = SendMessageW(hWnd, LVM_GETNEXTITEM, 0xFFFFFFFF, 2);
  Item.iSubItem = 0;
  Item.stateMask = 2;
  Item.mask = 0xC;
  bRet = SendMessageW(hWnd, LVM_GETITEMW, 0, (LPARAM)&Item);
  if ( uId == (HMENU)IDC_TREEVIEW_LIST )
  {
    if ( bRet == 1 && Item.state & LVIS_SELECTED )
    {
      pItem = Item.lParam;
      dwProcessId = Item.lParam->dwProcessId;
      if ( gdwProcessIdSelected != dwProcessId )
      {
        gdwProcessIdSelected = Item.lParam->dwProcessId;
        UpdateMenuStatus(1, 3);
        v5 = GetMenu(ghMainWnd);
        dwProcessIoPriority = pItem->ProcessBasePriority;
        v7 = v5;
        hMnua = v5;
        if ( dwProcessIoPriority == 4 && !pItem->m_ProcessIoPriority )
          dwProcessIoPriority = 0;
        UpateProirtyMenuItem(v5, dwProcessIoPriority);
        ItemText.stateMask = LVIS_SELECTED;
        ItemText.state = LVIS_SELECTED;
        SendMessageW(ghWndDllsListCtrl, LVM_SETITEMSTATE, 0, (LPARAM)&ItemText);
        ItemText.stateMask = LVIS_SELECTED;
        ItemText.state = LVIS_SELECTED;
        SendMessageW(ghWndHandlesListCtrl, LVM_SETITEMSTATE, 0, (LPARAM)&ItemText);
        pszText2 = L"R&esume";
        if ( SLOBYTE(pItem->dwStyle) >= 0 )
          pszText2 = L"S&uspend";
        ModifyMenuW(v7, IDM_PROCESS_SUSPEND, 0, IDM_PROCESS_SUSPEND, pszText2);
        pszText = L"Un&hide";
        if ( !(pItem->dwStyle & 1) )
          pszText = L"&Hide";
        ModifyMenuW(hMnua, IDM_VIEW_SAVE_HIDDEN_PROCESSES, 0, IDM_VIEW_SAVE_HIDDEN_PROCESSES, pszText);
        RefreshMenuWithTreeViewItemStatus(pItem);
        RefreshVirusTotalMenuItem(pItem);
        if ( gConfig.bShowLowerPane )
          UpdateMenuStatus(0, 5);
        v10 = gConfig.bShowProcessTree == 0;
        v11 = GetMenu(ghMainWnd);
        EnableMenuItem(v11, IDM_PROCESS_KILL_PROCESS_TREE, v10);
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
      EnableMenuItem(v12, IDM_PROCESS_KILL_PROCESS_TREE, 1u);
      if ( gConfig.bShowLowerPane )
      {
        UpdateMenuStatus(0, 5);
        goto LABEL_23;
      }
    }
  }
  else if ( gConfig.bShowLowerPane )
  {
    if ( bRet == 1 && Item.state & LVIS_SELECTED )
    {
      UpdateMenuStatus(1, 5);
      return 0;
    }
    UpdateMenuStatus(0, 5);
  }
  return 0;
}
// CAE398: using guessed type wchar_t aREsume[8];
// CAE3BC: using guessed type wchar_t aUnHide[8];

//----- (00C2F750) --------------------------------------------------------
int __cdecl CMainWnd::UpdateListViewContextMenu(UINT nID, HWND hWnd, POINT *pt)
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
        if ( SendMessageW(hWndList, LVM_GETITEMW, 0, (LPARAM)&lParam) == 1 )
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
            v9 = (DLLINFOLISTITEMPARAM *)lParam.lParam;
            v10 = 0;
            v11 = GetMenu(ghMainWnd);
            v12 = GetSubMenu(v11, 5);
            ghSelectColumnPopupMenuHandle = v12;
            v13 = (ListItemData1 *)v9->m_ItemData1;
            if ( !v13 || (v14 = L"&Submit to VirusTotal", v13->field_4 != 6) )
              v14 = L"&Check VirusTotal";
            ModifyMenuW(v12, IDM_CHECK_VIRUSTOTALDOTCOM, 0, IDM_CHECK_VIRUSTOTALDOTCOM, v14);
            v15 = v9->m_strPath.pszData;
            if ( v15 && *(_WORD *)v15 != '[' )
            {
              v10 = 0;
              if ( sub_C71C10((ListItemData1 *)v9->m_ItemData1) )
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
      hWndParent = GetParent(*(HWND *)hWnd);
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
// CAE374: using guessed type wchar_t aCheckVirustota[18];

//----- (00C2F9E0) --------------------------------------------------------
bool __cdecl CTreeList::InitHeaderColumn(HWND hWnd, WPARAM wParam, HWND nItem, char flags)
{
  CTreeList *v4; // eax
  HWND v6; // ebx
  HWND hWndHeader; // eax
  _HD_ITEMW hditem; // [esp+4h] [ebp-2Ch]

  v4 = CTreeList::GetTreeList(hWnd);
  if ( v4 )
    return CTreeList::InitHeaderColumn(v4, nItem, flags != 0);
  v6 = (HWND)SendMessageW(hWnd, LVM_GETHEADER, 0, 0);
  hditem.mask = 4;
  SendMessageW(v6, HDM_GETITEMW, wParam, (LPARAM)&hditem);
  if ( gbBitmapOnRight )
    hditem.fmt &= -0x2601u;                     // -(HDF_BITMAP | HDF_SORTUP | HDF_SORTDOWN | HDF_RIGHT)
  else
    hditem.fmt &= -0x1801u;                     // -(HDF_BITMAP_ON_RIGHT | HDF_SORTDOWN | HDF_SORTDOWN | HDF_RIGHT)
  SendMessageW(v6, HDM_SETITEMW, wParam, (LPARAM)&hditem);
  UpdateWindow(v6);
  hWndHeader = (HWND)SendMessageW(hWnd, LVM_GETHEADER, 0, 0);
  return CTreeList::SetHeaderItem(hWndHeader, (WPARAM)nItem, 2 * (flags != 0) - 1);
}
// CDA8F8: using guessed type char gbBitmapOnRight;

//----- (00C2FAA0) --------------------------------------------------------
LRESULT __cdecl PE_ResortList(UINT nID)
{
  int SortColumn; // ecx
  HWND hWndLV; // ebx
  int nCount; // eax
  BOOL v4; // eax
  UINT v5; // ST0C_4
  HMENU v6; // eax
  LVITEMW lParam; // [esp+Ch] [ebp-3Ch]
  tagSortParam SortParam; // [esp+40h] [ebp-8h]

  SortColumn = -1;
  SortParam.nID = nID;
  switch ( nID )
  {
    case IDC_TREEVIEW_LIST:
      SortColumn = gConfig.dwProcessSortColumn;
      hWndLV = ghWndTreeListView;
      break;
    case IDC_LISTCTRL_HANDLES:
      SortColumn = gConfig.dwHandleSortColumn;
      hWndLV = ghWndHandlesListCtrl;
      break;
    case IDM_ABOUT:
      SortColumn = gConfig.dwDllSortColumn;
      hWndLV = ghWndDllsListCtrl;
      break;
    default:
      hWndLV = (HWND)nID;
      goto LABEL_9;
  }
  if ( SortColumn != -1 )
  {
    if ( nID != IDC_TREEVIEW_LIST )
      goto LABEL_14;
    goto LABEL_13;
  }
LABEL_9:
  if ( nID != IDC_TREEVIEW_LIST || !gConfig.bShowProcessTree )
    return SendMessageW(hWndLV, WM_SETREDRAW, 1u, 0);
LABEL_13:
  gbDllsOrHandlesSorting = 1;
LABEL_14:
  SortParam.dwSortColumn = SortColumn;
  SendMessageW(hWndLV, LVM_SORTITEMS, (WPARAM)&SortParam, (LPARAM)BackendSortCallback);
  if ( nID == IDC_TREEVIEW_LIST )
  {
    if ( gConfig.bShowNewProcesses )
    {
      lParam.mask = 4;
      lParam.iSubItem = 0;
      lParam.iItem = 0;
      if ( SendMessageW(ghWndTreeListView, LVM_GETITEMCOUNT, 0, 0) > 0 )
      {
        while ( 1 )
        {
          SendMessageW(ghWndTreeListView, LVM_GETITEMW, 0, (LPARAM)&lParam);
          if ( lParam.lParam->field_10 == 2 && !lParam.lParam->field_14 )
            break;
          ++lParam.iItem;
          nCount = SendMessageW(ghWndTreeListView, LVM_GETITEMCOUNT, 0, 0);
          if ( lParam.iItem >= nCount )
            goto LABEL_22;
        }
        SendMessageW(ghWndTreeListView, LVM_ENSUREVISIBLE, lParam.iItem, 0);
      }
    }
LABEL_22:
    gbDllsOrHandlesSorting = 0;
    v4 = !gConfig.bShowProcessTree || SendMessageW(hWndLV, LVM_GETNEXTITEM, 0xFFFFFFFF, 2) == -1;
    v5 = v4;
    v6 = GetMenu(ghMainWnd);
    EnableMenuItem(v6, IDM_PROCESS_KILL_PROCESS_TREE, v5);
  }
  return SendMessageW(hWndLV, WM_SETREDRAW, 1u, 0);
}
// CD53B5: using guessed type char gbDllsOrHandlesSorting;

//----- (00C2FC20) --------------------------------------------------------
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
  _mm_storeu_si128((__m128i *)&ColumnInfo.fmt, (__m128i)0i64);
  ColumnInfo.iOrder = 0;
  *(_QWORD *)&ColumnInfo.iSubItem = 0i64;
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
    ::SendMessageW(hWndList, LVM_SETITEMTEXTW, v37, (LPARAM)&ItemState);
    result = 1;
  }
  else
  {
    if ( msg != WM_INITDIALOG )
    {
      if ( msg == 273 )
      {
        if ( (unsigned __int16)nID <= (signed int)IDC_DLG_COLUMN_SETS_BUTTON_DELETE )
        {
          if ( (unsigned __int16)nID == IDC_DLG_COLUMN_SETS_BUTTON_DELETE )
          {
            v8 = ::SendMessageW(hWndList, LVM_GETNEXTITEM, 0xFFFFFFFF, 2);
            ::SendMessageW(hWndList, LVM_DELETEITEM, v8, 0);
            if ( v8 )
              --v8;
            ItemState.stateMask = 3;
            ItemState.state = 3;
            ::SendMessageW(hWndList, LVM_SETITEMSTATE, v8, (LPARAM)&ItemState);
            return 0;
          }
          if ( (unsigned __int16)nID != 2 )
          {
            // if(nID<=IDC_DLG_COLUMN_SETS_BUTTON_MOVEDOWN)
            if ( (unsigned int)(unsigned __int16)nID - 1210 <= 1 )
            {
              nCurItem = ::SendMessageW(hWndList, LVM_GETNEXTITEM, 0xFFFFFFFF, 2);
              Item.mask = 5;
              if ( (_WORD)nID == IDC_DLG_COLUMN_SETS_BUTTON_MOVEUP )
                Item.iItem = nCurItem - 1;
              else
                Item.iItem = nCurItem + 1;
              Item.cchTextMax = 259;
              Item.pszText = szName;
              Item.iSubItem = 0;
              ::SendMessageW(hWndList, LVM_GETITEMW, 0, (LPARAM)&Item);
              Item2.mask = 5;
              Item2.pszText = szText;
              Item2.iItem = nCurItem;
              Item2.cchTextMax = 259;
              Item2.iSubItem = 0;
              ::SendMessageW(hWndList, LVM_GETITEMW, 0, (LPARAM)&Item2);
              v6 = Item.lParam;
              Item.pszText = szText;
              Item2.pszText = szName;
              Item.lParam = Item2.lParam;
              Item2.lParam = v6;
              ::SendMessageW(hWndList, LVM_SETITEMW, 0, (LPARAM)&Item);
              ::SendMessageW(hWndList, LVM_SETITEMW, 0, (LPARAM)&Item2);
              ItemState.stateMask = 3;
              ItemState.state = 3;
              ::SendMessageW(hWndList, LVM_SETITEMSTATE, Item.iItem, (LPARAM)&ItemState);
            }
            return 0;
          }
          goto LABEL_28;
        }
        if ( (unsigned __int16)nID == IDC_DLG_COLUMN_SETS_BUTTON_RENAME )
        {
          SetFocus(hWndList);
          v21 = ::SendMessageW(hWndList, LVM_GETNEXTITEM, 0xFFFFFFFF, 2);
          ::SendMessageW(hWndList, LVM_EDITLABELW, v21, 0);
          return 0;
        }
        if ( (unsigned __int16)nID == IDC_DLG_COLUMN_SETS_BUTTON_OK )
        {
          for ( i = 0; i < (signed int)gConfig.dwNumColumnsets; ++i )
          {
            v10 = gdwMenuItemPosLast;
            v11 = GetMenu(ghMainWnd);
            v12 = GetSubMenu(v11, 2);
            v13 = GetSubMenu(v12, v10);
            DeleteMenu(v13, 0, MF_BYPOSITION);
          }
          memmove_0(tempRegVar, gConfig.strMenuCulumnSet, 15240u);
          SendMessageW_1 = (void (__stdcall *)(HWND, UINT, WPARAM, LPARAM))::SendMessageW;
          nColumn = 0;
          gConfig.dwNumColumnsets = ::SendMessageW(hWndList, LVM_GETITEMCOUNT, 0, 0);
          if ( (signed int)gConfig.dwNumColumnsets > 0 )
          {
            do
            {
              Item.mask = 5;
              Item.pszText = szName;
              Item.iItem = nColumn;
              Item.cchTextMax = 259;
              Item.iSubItem = 0;
              SendMessageW_1(hWndList, LVM_GETITEMW, 0, (LPARAM)&Item);
              qmemcpy(
                &gConfig.strMenuCulumnSet[nColumn],
                &tempRegVar[(_DWORD)Item.lParam],
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
              SendMessageW_1 = (void (__stdcall *)(HWND, UINT, WPARAM, LPARAM))::SendMessageW;
            }
            while ( nColumn < (signed int)gConfig.dwNumColumnsets );
          }
LABEL_28:
          EndDialog(hWnd, 0);
          return 0;
        }
      }
      return 0;
    }
    // WM_INITDIALOG
    SendMessageW = (void (__stdcall *)(HWND, UINT, WPARAM, LPARAM))::SendMessageW;
    sbEditFlags = 0;
    ::SendMessageW(hWndList, LVM_SETEXTENDEDLISTVIEWSTYLE, LVS_EX_FULLROWSELECT, LVS_EX_FULLROWSELECT);
    ::SendMessageW(hWndList, LVM_INSERTCOLUMNW, 0, (LPARAM)&ColumnInfo);
    Index = 0;
    ItemInfo.mask = 0xD;                        // LVIF_TEXT|LVIF_IMAGE|LVIF_PARAM|LVIF_STATE
    ItemInfo.iItem = 0x7FFFFFFF;
    ItemInfo.iSubItem = 0;
    ItemInfo.state = 0;
    ItemInfo.stateMask = 0;
    if ( (signed int)gConfig.dwNumColumnsets > 0 )
    {
      regVar = gConfig.strMenuCulumnSet;
      do
      {
        ItemInfo.pszText = (LPWSTR)regVar;
        nLength = lstrlenW(regVar->ColumnSetName);
        ItemInfo.iImage = 0;
        ItemInfo.cchTextMax = nLength + 1;
        ItemInfo.lParam = Index;
        ::SendMessageW(hWndList, LVM_INSERTITEMW, 0, (LPARAM)&ItemInfo);
        Index = (tagTREEVIEWLISTITEMPARAM *)((char *)Index + 1);
        ++regVar;
      }
      while ( (signed int)Index < (signed int)gConfig.dwNumColumnsets );
      SendMessageW = (void (__stdcall *)(HWND, UINT, WPARAM, LPARAM))::SendMessageW;
    }
    SendMessageW(hWndList, LVM_SETCOLUMNWIDTH, 0, 0xFFFE);// LVSCW_AUTOSIZE
    ItemState.stateMask = 3;                    // LVIS_SELECTED | LVIS_FOCUSED
    ItemState.state = 3;                        // LVIS_SELECTED | LVIS_FOCUSED
    SendMessageW(hWndList, LVM_SETITEMSTATE, 0, (LPARAM)&ItemState);
    SetFocus(hWndList);
    result = 1;
  }
  return result;
}
// CD9E70: using guessed type char sbEditFlags;
// C2FF58: user specified stroff has not been processed: CRegVar offset 1524

//----- (00C302A0) --------------------------------------------------------
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
  *(_DWORD *)pwLuminance = 0;
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
    v7 = 5 * (46 - (unsigned __int16)(signed int)(v12 * 100.0) / 5);
    if ( v12 == 0.0 )
      v7 = 230;
    *(_DWORD *)pwLuminance = v7;
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
// CACDC0: using guessed type double db_onehundred;

//----- (00C30490) --------------------------------------------------------
HCURSOR __cdecl CMainWnd::GetDynamicCursor(int a1, int nIndex)
{
  int v2; // eax
  HCURSOR result; // eax

  if ( gConfig.dwProcessColumnMap[nIndex] == IDS_VIRUSTOTAL
    && (CTreeList::GetTreeList(ghWndTreeListView), v2 = sub_C0E5D0(a1), sub_C71820(*(ListItemData1 **)(v2 + 0x34C))) )
  {
    result = LoadCursorW(ghInstance, L"HAND");
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00C304F0) --------------------------------------------------------
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
// CDA389: using guessed type char gbMainWndMinimized;

//----- (00C305A0) --------------------------------------------------------
BOOL __stdcall DlgColumnSetSave(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
  double v4; // st1
  double v5; // st2
  double v6; // st3
  double v7; // st4
  double v8; // st5
  double v9; // st6
  double v10; // st7
  HWND hWnd_1; // ecx
  HWND hWndCB_1; // eax
  signed int index_1; // ebx
  CRegVar *var_1; // esi
  int v16; // eax
  int v17; // ST08_4
  HMENU v18; // eax
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
      swprintf((wchar_t *)String, L"Column Set %d", index);
      dwNumColumnsets = gConfig.dwNumColumnsets;
      dwColumnIndex = 0;
      if ( (signed int)gConfig.dwNumColumnsets > 0 )
      {
        var = gConfig.strMenuCulumnSet;
        while ( 1 )
        {
          found = _wcsicmp((const wchar_t *)String, var->ColumnSetName) == 0;
          dwNumColumnsets = gConfig.dwNumColumnsets;
          if ( found )
            break;
          ++dwColumnIndex;
          ++var;
          if ( dwColumnIndex >= (signed int)gConfig.dwNumColumnsets )
            goto LABEL_31;
        }
        ++index;
      }
LABEL_31:
      ;
    }
    while ( dwColumnIndex != dwNumColumnsets );
    SendMessageW = (void (__stdcall *)(HWND, UINT, WPARAM, LPARAM))::SendMessageW;
    hWndCB = GetDlgItem(hWnd, IDC_DLG_COLUMN_SET_SAVE_COMBO);
    ::SendMessageW(hWndCB, CB_ADDSTRING, 0, (LPARAM)String);
    dwColumn = 0;
    if ( (signed int)gConfig.dwNumColumnsets > 0 )
    {
      pVar = gConfig.strMenuCulumnSet;
      do
      {
        ::SendMessageW(hWndCB, CB_ADDSTRING, 0, (LPARAM)pVar);
        ++dwColumn;
        ++pVar;
      }
      while ( dwColumn < (signed int)gConfig.dwNumColumnsets );
      SendMessageW = (void (__stdcall *)(HWND, UINT, WPARAM, LPARAM))::SendMessageW;
    }
    SendMessageW(hWndCB, CB_SETCURSEL, 0, 0);
    SendMessageW(hWndCB, CB_SETEDITSEL, 0, 0xFFFF0000);
  }
  else
  {
    if ( uMsg != WM_COMMAND )
      return 0;
    if ( (unsigned __int16)wParam != 1 )
    {
      if ( (unsigned __int16)wParam != 2 )
        return 0;
      goto LABEL_22;
    }
    hWndCB_1 = GetDlgItem(hWnd, IDC_DLG_COLUMN_SET_SAVE_COMBO);
    GetWindowTextW(hWndCB_1, (LPWSTR)String, 260);
    index_1 = 0;
    if ( (signed int)gConfig.dwNumColumnsets <= 0 )
      goto LABEL_13;
    var_1 = gConfig.strMenuCulumnSet;
    do
    {
      if ( !_wcsicmp((const wchar_t *)String, var_1->ColumnSetName) )
        break;
      ++index_1;
      ++var_1;
    }
    while ( index_1 < (signed int)gConfig.dwNumColumnsets );
    if ( index_1 != 10 )
    {
LABEL_13:
      UpdateWindowPlacement(ghMainWnd, 0);
      qmemcpy(&gConfig.strMenuCulumnSet[index_1], gConfig.szColumnSetName, sizeof(gConfig.strMenuCulumnSet[index_1]));
      wcscpy_s(gConfig.strMenuCulumnSet[index_1].ColumnSetName, MAX_PATH, (const wchar_t *)String);
      if ( index_1 == gConfig.dwNumColumnsets )
      {
        if ( index_1 >= 10 )
        {
          wcscpy_s(szNewItem, 0x208u, (const wchar_t *)String);
        }
        else
        {
          if ( index_1 == 9 )
            v16 = 0;
          else
            v16 = index_1 + 1;
          MakeHandlePropSheetCaption(szNewItem, L"%s\tCtrl+%d", String, v16);
        }
        v17 = gdwMenuItemPosLast;
        v18 = GetMenu(ghMainWnd);
        hViewMenu = GetSubMenu(v18, 2);
        hSubMenu = GetSubMenu(hViewMenu, v17);
        AppendMenuW(hSubMenu, 0, index_1 + IDM_PROCESS_PRIORITY_BASE, szNewItem);
        ++gConfig.dwNumColumnsets;
      }
      Command_SetColumn(v10, v9, v8, v4, v5, v6, v7, 0, index_1 - 0x6127);
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
      DialogBoxParamW(ghInstance, L"COLUMNSETS", ghMainWnd, (DLGPROC)DlgColumnSets, 0);
      index_1 = gConfig.dwNumColumnsets;
      if ( gConfig.dwNumColumnsets != 10 )
        goto LABEL_13;
    }
  }
  return 1;
}
// C8C710: using guessed type int (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD);

//----- (00C308A0) --------------------------------------------------------
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
    gConfig.WindowPlacement[1].ptMinPosition.y = 44;
    GetWindowPlacement(ghFindDlg, (WINDOWPLACEMENT *)((char *)&gConfig.WindowPlacement[1] + 16));
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
    SendMessageW(ghWndReBar, RB_GETBANDINFOW, v2, (LPARAM)&BandInfo);
    gConfig.ToolBandInfo[iBand].nWidth = MulDiv(BandInfo.cx, 96, gLogPixelSize.x);
    ++v2;
    gConfig.ToolBandInfo[iBand].nID = BandInfo.wID;
    gConfig.ToolBandInfo[iBand].fBreak = BandInfo.fStyle & RBBS_BREAK;
    ++iBand;
  }
  while ( iBand < 8 );
  gConfig.wProcessImageColumnWidth = SendMessageW(ghWndTreeListView, LVM_GETCOLUMNWIDTH, 0, 0);
  v4 = (HKEY)gConfig.dwProcessColumnMap[gConfig.dwProcessSortColumn];
  pThis.hKey = (HKEY)gConfig.dwProcessColumnMap[gConfig.dwProcessSortColumn];
  v5 = SendMessageW(ghWndTreeListView, LVM_GETCOLUMNORDERARRAY, gConfig.dwProcessColumnCount, (LPARAM)arrIDs);
  v6 = gConfig.dwProcessColumnCount;
  if ( !v5 )
  {
    v7 = 0;
    if ( gConfig.dwProcessColumnCount > 0 )
    {
      if ( gConfig.dwProcessColumnCount >= 8u )
      {
        v8 = _mm_load_si128((const __m128i *)&gIntArray);
        v9 = v52;
        v10 = gConfig.dwProcessColumnCount - gConfig.dwProcessColumnCount % 8;
        do
        {
          v11 = v7 + 4;
          v9 += 32;
          v12 = _mm_add_epi32(_mm_shuffle_epi32(_mm_cvtsi32_si128(v7), 0), v8);
          v7 += 8;
          _mm_storeu_si128((__m128i *)v9 - 3, v12);
          _mm_storeu_si128((__m128i *)v9 - 2, _mm_add_epi32(_mm_shuffle_epi32(_mm_cvtsi32_si128(v11), 0), v8));
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
      if ( (HKEY)v15 == v4 )
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
  v18 = (HKEY)gConfig.dwIdsOfHandleColumnMap[gConfig.dwHandleSortColumn];
  pThis.hKey = (HKEY)gConfig.dwIdsOfHandleColumnMap[gConfig.dwHandleSortColumn];
  v19 = SendMessageW(ghWndHandlesListCtrl, LVM_GETCOLUMNORDERARRAY, gConfig.dwHandleColumnCount, (LPARAM)arrIDs);
  dwHandleColumnCount = gConfig.dwHandleColumnCount;
  if ( !v19 )
  {
    v21 = 0;
    if ( (signed int)gConfig.dwHandleColumnCount > 0 )
    {
      if ( gConfig.dwHandleColumnCount >= 8 )
      {
        v22 = _mm_load_si128((const __m128i *)&gIntArray);
        v23 = v52;
        v24 = gConfig.dwHandleColumnCount - (signed int)gConfig.dwHandleColumnCount % 8;
        do
        {
          v25 = v21 + 4;
          v23 += 32;
          v26 = _mm_add_epi32(_mm_shuffle_epi32(_mm_cvtsi32_si128(v21), 0), v22);
          v21 += 8;
          _mm_storeu_si128((__m128i *)v23 - 3, v26);
          _mm_storeu_si128((__m128i *)v23 - 2, _mm_add_epi32(_mm_shuffle_epi32(_mm_cvtsi32_si128(v25), 0), v22));
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
      if ( (HKEY)v29 == v18 )
        dwHandleSortColumn = dwIndex_1;
      ++dwIndex_1;
      gConfig.dwHandleSortColumn = dwHandleSortColumn;
    }
    while ( dwIndex_1 < (signed int)gConfig.dwHandleColumnCount );
  }
  nColumn = 0;
  if ( dwHandleColumnCount > 0 )
  {
    do
    {
      gConfig.dwHandleColumns[nColumn] = SendMessageW(ghWndHandlesListCtrl, LVM_GETCOLUMNWIDTH, arrIDs[nColumn], 0);
      ++nColumn;
    }
    while ( nColumn < (signed int)gConfig.dwHandleColumnCount );
  }
  v32 = (HKEY)gConfig.dwDllColumnMap[gConfig.dwDllSortColumn];
  pThis.hKey = (HKEY)gConfig.dwDllColumnMap[gConfig.dwDllSortColumn];
  nOrderCount = SendMessageW(ghWndDllsListCtrl, LVM_GETCOLUMNORDERARRAY, gConfig.dwDllColumnCount, (LPARAM)arrIDs);
  dwDllColumnCount_1 = gConfig.dwDllColumnCount;
  if ( !nOrderCount )
  {
    dwIndex = 0;
    if ( (signed int)gConfig.dwDllColumnCount > 0 )
    {
      if ( gConfig.dwDllColumnCount >= 8 )
      {
        v36 = _mm_load_si128((const __m128i *)&gIntArray);
        v37 = v52;
        dwDllColumnCount = gConfig.dwDllColumnCount - (signed int)gConfig.dwDllColumnCount % 8;
        do
        {
          v39 = dwIndex + 4;
          v37 += 32;
          v40 = _mm_add_epi32(_mm_shuffle_epi32(_mm_cvtsi32_si128(dwIndex), 0), v36);
          dwIndex += 8;
          _mm_storeu_si128((__m128i *)v37 - 3, v40);
          _mm_storeu_si128((__m128i *)v37 - 2, _mm_add_epi32(_mm_shuffle_epi32(_mm_cvtsi32_si128(v39), 0), v36));
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
      if ( (HKEY)v43 == v32 )
        v44 = v42;
      ++v42;
      gConfig.dwDllSortColumn = v44;
    }
    while ( v42 < (signed int)gConfig.dwDllColumnCount );
  }
  v45 = 0;
  if ( dwDllColumnCount_1 > 0 )
  {
    do
    {
      gConfig.dwDllColumns[v45] = SendMessageW(ghWndDllsListCtrl, 0x101Du, arrIDs[v45], 0);
      ++v45;
    }
    while ( v45 < (signed int)gConfig.dwDllColumnCount );
  }
  if ( bSave )
  {
    pThis.szKeyName = (int)_wcsdup(L"Software\\Sysinternals\\Process Explorer");
    gConfig.UnicodeFont.lfHeight = -MulDiv(gConfig.UnicodeFont.lfHeight, 72, gLogPixelSize.y);
    SaveConfigItemToRegistry(&pThis, gConfigItems);
    memmove_0(&gConfig, v48, 0x47E0u);
    v46 = 0;
    if ( (signed int)gConfig.dwNumColumnsets > 0 )
    {
      v47 = gConfig.strMenuCulumnSet;
      do
      {
        RegVar_ReadWrite(1, v46++, v47);
        ++v47;
      }
      while ( v46 < (signed int)gConfig.dwNumColumnsets );
    }
    free((void *)pThis.szKeyName);
  }
}
// CAEA50: using guessed type tagRECT gIntArray;
// CCE10C: using guessed type int gdwRefreshMenuIDLast;
// C308A0: using guessed type LPARAM arrIDs[4];

//----- (00C30E90) --------------------------------------------------------
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
    if ( *(_DWORD *)(lParam + 8) == -202 )
    {
      lParama = 7;
      v20 = 64;
      v19 = &v23;
      SendMessageW(ghWndDllsListCtrl, 0xBu, 0, 0);
      v14 = IsDlgButtonChecked;
      for ( i = 0; i < (signed int)gConfig.dwDllColumnCount; ++i )
      {
        if ( v14(v4, gConfig.dwDllColumnMap[i]) != 1 )
        {
          v16 = gConfig.dwDllColumnCount;
          if ( i < (signed int)(gConfig.dwDllColumnCount - 1) )
          {
            do
            {
              SendMessageW(ghWndDllsListCtrl, 0x105Fu, i + 1, (LPARAM)&lParama);
              SendMessageW(ghWndDllsListCtrl, 0x1060u, i, (LPARAM)&lParama);
              gConfig.dwDllColumnMap[i] = gConfig.dwDllColumnMap[i + 1];
              ++i;
              v16 = gConfig.dwDllColumnCount;
            }
            while ( i < (signed int)(gConfig.dwDllColumnCount - 1) );
            v4 = v22;
          }
          gConfig.dwDllColumnCount = v16 - 1;
          SendMessageW(ghWndDllsListCtrl, 0x101Cu, v16 - 1, 0);
          SetWindowLongW(ghWndDllsListCtrl, -21, gConfig.dwDllColumnCount);
          i = -1;
          *(_BYTE *)dword_CD9E60 = 1;
        }
        v14 = IsDlgButtonChecked;
      }
      v17 = 0;
      do
      {
        if ( v14(v4, dword_CCD7F8[v17]) )
          CTreeList_InsertVerifyColumn(
            ghWndDllsListCtrl,
            dword_CCD7F8[v17],
            (int *)gConfig.dwDllColumnMap,
            (int)&gConfig.dwDllColumnCount);
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
  for ( dword_CD9E60 = *(_DWORD *)(v21 + 28); v12 < (signed int)gConfig.dwDllColumnCount; ++v12 )
    CheckDlgButton(v22, gConfig.dwDllColumnMap[v12], 1u);
  return 1;
}
// CCD7F8: using guessed type int dword_CCD7F8[];
// CD4E54: using guessed type int gdwVersion;
// CD9E60: using guessed type int dword_CD9E60;
// CEBA4C: using guessed type int (__stdcall *IsImmersiveProcess)(_DWORD);

//----- (00C31110) --------------------------------------------------------
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
    if ( *(_DWORD *)(lParam + 8) == -202 )
    {
      lParama = 7;
      v15 = 0;
      v18 = 64;
      v17 = &Buffer;
      SendMessageW(ghWndHandlesListCtrl, 0xBu, 0, 0);
      v7 = IsDlgButtonChecked;
      for ( i = 0; i < (signed int)gConfig.dwHandleColumnCount; ++i )
      {
        if ( v7(v4, gConfig.dwIdsOfHandleColumnMap[i]) != 1 )
        {
          v9 = gConfig.dwHandleColumnCount;
          if ( i < (signed int)(gConfig.dwHandleColumnCount - 1) )
          {
            do
            {
              SendMessageW(ghWndHandlesListCtrl, 0x105Fu, i + 1, (LPARAM)&lParama);
              SendMessageW(ghWndHandlesListCtrl, 0x1060u, i, (LPARAM)&lParama);
              gConfig.dwIdsOfHandleColumnMap[i] = gConfig.dwIdsOfHandleColumnMap[i + 1];
              ++i;
              v9 = gConfig.dwHandleColumnCount;
            }
            while ( i < (signed int)(gConfig.dwHandleColumnCount - 1) );
            v4 = v20;
          }
          gConfig.dwHandleColumnCount = v9 - 1;
          SendMessageW(ghWndHandlesListCtrl, 0x101Cu, v9 - 1, 0);
          SetWindowLongW(ghWndHandlesListCtrl, -21, gConfig.dwHandleColumnCount);
          i = -1;
          *(_BYTE *)dword_CD9E64 = 1;
        }
        v7 = IsDlgButtonChecked;
      }
      v10 = 0;
      do
      {
        if ( v7(v4, dword_CCD7DC[v10]) )
        {
          for ( j = 0; j < (signed int)gConfig.dwHandleColumnCount; ++j )
          {
            if ( gConfig.dwIdsOfHandleColumnMap[j] == dword_CCD7DC[v10] )
              break;
          }
          if ( j == gConfig.dwHandleColumnCount )
          {
            v19 = gConfig.dwHandleColumnCount;
            v16 = MulDiv(100, gLogPixelSize.x, 96);
            LoadStringW(ghInstance, dword_CCD7DC[v10], &Buffer, 64);
            v12 = dword_CCD7DC[v10];
            gConfig.dwIdsOfHandleColumnMap[gConfig.dwHandleColumnCount] = v12;
            v15 = IsStringID(v12) != 0;
            v13 = gConfig.dwHandleColumnCount++;
            SendMessageW(ghWndHandlesListCtrl, 0x1061u, v13, (LPARAM)&lParama);
            SetWindowLongW(ghWndHandlesListCtrl, -21, gConfig.dwHandleColumnCount);
            *(_BYTE *)dword_CD9E64 = 1;
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
  for ( dword_CD9E64 = *(_DWORD *)(lParam + 28); v5 < (signed int)gConfig.dwHandleColumnCount; ++v5 )
    CheckDlgButton(hWnd, gConfig.dwIdsOfHandleColumnMap[v5], 1u);
  return 1;
}
// CCD7DC: using guessed type int dword_CCD7DC[];
// CD9E64: using guessed type int dword_CD9E64;

//----- (00C313D0) --------------------------------------------------------
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
    if ( *(_DWORD *)(lParam + 8) == -202 )
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
              SendMessageW(ghWndTreeListView, 0x105Fu, v7 + 1, (LPARAM)&lParama);
              SendMessageW(ghWndTreeListView, 0x1060u, v7, (LPARAM)&lParama);
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
          *(_BYTE *)dword_CD9E6C = 1;
        }
      }
      v9 = 0;
      do
      {
        if ( IsDlgButtonChecked(v4, dword_CCD798[v9]) )
        {
          for ( j = 0; j < gConfig.dwProcessColumnCount; ++j )
          {
            if ( gConfig.dwProcessColumnMap[j] == dword_CCD798[v9] )
              break;
          }
          if ( j == gConfig.dwProcessColumnCount )
          {
            v18 = gConfig.dwProcessColumnCount;
            v15 = MulDiv(100, gLogPixelSize.x, 96);
            LoadStringW(ghInstance, dword_CCD798[v9], &Buffer, 64);
            v11 = dword_CCD798[v9];
            gConfig.dwProcessColumnMap[gConfig.dwProcessColumnCount] = v11;
            v14 = IsStringID(v11) != 0;
            v12 = gConfig.dwProcessColumnCount++;
            SendMessageW(ghWndTreeListView, 0x1061u, v12, (LPARAM)&lParama);
            SetWindowLongW(ghWndTreeListView, -21, gConfig.dwProcessColumnCount);
            *(_BYTE *)dword_CD9E6C = 1;
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
  for ( dword_CD9E6C = *(_DWORD *)(lParam + 28); v5 < gConfig.dwProcessColumnCount; ++v5 )
    CheckDlgButton(hWnd, gConfig.dwProcessColumnMap[v5], 1u);
  return 1;
}
// CCD798: using guessed type int dword_CCD798[];
// CD9E6C: using guessed type int dword_CD9E6C;

//----- (00C31680) --------------------------------------------------------
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
    if ( *(_DWORD *)(lParam + 8) == -202 )
    {
      v47 = (void (__stdcall *)(HWND, UINT, WPARAM, LPARAM))SendMessageW;
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
              SendMessageW(ghWndTreeListView, 0x105Fu, i + 1, (LPARAM)&lParama);
              SendMessageW(ghWndTreeListView, 0x1060u, i, (LPARAM)&lParama);
              gConfig.dwProcessColumnMap[i] = gConfig.dwProcessColumnMap[i + 1];
              ++i;
              v50 = gConfig.dwProcessColumnCount;
            }
            while ( i < gConfig.dwProcessColumnCount - 1 );
            v47 = (void (__stdcall *)(HWND, UINT, WPARAM, LPARAM))SendMessageW;
          }
          gConfig.dwProcessColumnCount = v50 - 1;
          v47(ghWndTreeListView, 0x101Cu, v50 - 1, 0);
          SetWindowLongW(ghWndTreeListView, -21, gConfig.dwProcessColumnCount);
          i = -1;
          *(_BYTE *)dword_CD9E68 = 1;
        }
        v48 = GetDlgItem;
      }
      v51 = 0;
      do
      {
        if ( v48(hWnd, dword_CCD5F0[v51]) && IsDlgButtonChecked(hWnd, dword_CCD5F0[v51]) )
          CTreeList_InsertVerifyColumn(
            ghWndTreeListView,
            dword_CCD5F0[v51],
            gConfig.dwProcessColumnMap,
            (int)&gConfig.dwProcessColumnCount);
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
  dword_CD9E68 = *(_DWORD *)(lParam + 28);
  v4 = GetDlgItem(hWnd, 1190);
  EnableWindow(v4, 0);
  v5 = (unsigned __int8)gbWintrustInited;
  v6 = GetDlgItem(hWnd, 1187);
  EnableWindow(v6, v5);
  v7 = (unsigned __int8)gbIsProcessDEPEnabled;
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
  v33 = (void (__stdcall *)(HWND, int, UINT))CheckDlgButton;
  for ( j = 0; j < gConfig.dwProcessColumnCount; ++j )
  {
    v33(hWnd, gConfig.dwProcessColumnMap[j], 1u);
    v33 = (void (__stdcall *)(HWND, int, UINT))CheckDlgButton;
  }
  v33(hWnd, 3, 1u);
  if ( gbProcessIdToSessionIdValid )
  {
    v36 = (void (__stdcall *)(HWND, BOOL))EnableWindow;
  }
  else
  {
    v35 = GetDlgItem(hWnd, 1056);
    v36 = (void (__stdcall *)(HWND, BOOL))EnableWindow;
    EnableWindow(v35, 0);
  }
  if ( !QueryProcessCycleTime )
  {
    v37 = GetDlgItem(hWnd, 1195);
    v36(v37, 0);
    v38 = GetDlgItem(hWnd, 1200);
    v36(v38, 0);
  }
  if ( !*(_DWORD *)GetGuiResources )
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
  if ( !*(_DWORD *)QueryWorkingSet )
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
// CCD5F0: using guessed type int dword_CCD5F0[];
// CD4E54: using guessed type int gdwVersion;
// CD9E68: using guessed type int dword_CD9E68;
// CDA38A: using guessed type char gbProcessIdToSessionIdValid;
// CDA390: using guessed type char gbIsProcessDEPEnabled;
// CDA391: using guessed type char gbWintrustInited;
// CDF2F4: using guessed type int GetProcessorSystemCycleTime;
// CDF36C: using guessed type int (__stdcall *GetProcessDpiAwareness)(_DWORD, _DWORD);
// CEBA4C: using guessed type int (__stdcall *IsImmersiveProcess)(_DWORD);

//----- (00C31AF0) --------------------------------------------------------
int __cdecl sub_C31AF0(_DWORD *a1, _DWORD *a2)
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
  if ( !*((_QWORD *)a1 + 78) )
  {
    if ( *((_QWORD *)a2 + 78) )
      return -1;
    return a1[17] - a2[17];
  }
  v5 = a2[156];
  v6 = a2[157];
  if ( !*((_QWORD *)a2 + 78) )
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
  if ( !(v8 ^ v9) && (!((unsigned __int8)(v8 ^ v9) | v7) || v3 > v5) )
    return 1;
  return -1;
}

//----- (00C31B70) --------------------------------------------------------
signed int __cdecl CMainWnd::HandleTVSN7D4(int a1, HWND *a2)
{
  HWND *v2; // esi
  int v3; // eax
  _bstr_t *v4; // edi
  Data_t_bstr_t *v5; // eax

  v2 = a2;
  if ( !sub_C22A70(*a2) )
    return 1;
  if ( *v2 == ghWndTreeListView && !v2[5] )
  {
    if ( !(dword_CD9E54 & 1) )
    {
      stru_CD9E50.m_Data = 0;
      dword_CD9E54 |= 1u;
      atexit(sub_C9A970);
    }
    CTreeList::GetTreeList(*v2);
    v3 = sub_C0E5D0((int)v2[4]);
    v4 = (_bstr_t *)sub_C26270((int)&a2, v3);
    if ( v4 != &stru_CD9E50 )
    {
      _bstr_t::_Free(&stru_CD9E50);
      v5 = v4->m_Data;
      stru_CD9E50.m_Data = v5;
      if ( v5 )
        InterlockedIncrement(&v5->m_RefCount);
    }
    _bstr_t::_Free((_bstr_t *)&a2);
    if ( stru_CD9E50.m_Data )
    {
      *(_DWORD *)v2[6] = (HWND__)stru_CD9E50.m_Data->m_wstr;
      return 1;
    }
    *(_DWORD *)v2[6] = 0;
    return 1;
  }
  return 0;
}
// CD9E54: using guessed type int dword_CD9E54;

//----- (00C31C50) --------------------------------------------------------
signed int __cdecl CMainWnd::HandleTVSN7D5(int a1, int a2)
{
  HMONITOR v2; // eax
  struct tagPOINT Point; // [esp+8h] [ebp-54h]
  struct tagMONITORINFO mi; // [esp+10h] [ebp-4Ch]
  __int128 pvParam; // [esp+38h] [ebp-24h]
  struct tagRECT Rect; // [esp+48h] [ebp-14h]

  GetCursorPos(&Point);
  if ( *(_DWORD *)MonitorFromPoint )
  {
    v2 = MonitorFromPoint(Point, 2u);
    if ( v2 )
    {
      mi.cbSize = 40;
      if ( GetMonitorInfoA(v2, &mi) )
        _mm_storeu_si128((__m128i *)&pvParam, _mm_loadu_si128((const __m128i *)&mi.gap4[16]));
    }
  }
  else
  {
    SystemParametersInfoW(0x30u, 0, &pvParam, 0);
  }
  DWORD2(pvParam) -= 10;
  HIDWORD(pvParam) -= 10;
  GetWindowRect(*(HWND *)a2, &Rect);
  if ( !*(_DWORD *)(a2 + 20) )
    OffsetRect(&Rect, Point.x - Rect.left + 17, 34);
  if ( Rect.right > SDWORD2(pvParam) )
    OffsetRect(&Rect, DWORD2(pvParam) - Rect.right, 0);
  if ( Rect.bottom > SHIDWORD(pvParam) )
    OffsetRect(&Rect, 0, HIDWORD(pvParam) - Rect.bottom);
  SetWindowPos(*(HWND *)a2, 0, Rect.left, Rect.top, 0, 0, 0x15u);
  return 1;
}

//----- (00C31D40) --------------------------------------------------------
BOOL RefreshTreeView()
{
  return InvalidateRect(ghWndTreeListView, 0, 0);
}

//----- (00C31D60) --------------------------------------------------------
int MakeAddressInfo(char *DstBuf, char *Format, ...)
{
  va_list ArgList; // [esp+10h] [ebp+10h]

  va_start(ArgList, Format);
  return vsprintf_s(DstBuf, 0x104u, Format, ArgList);
}

//----- (00C31D80) --------------------------------------------------------
int sub_C31D80(wchar_t *Dst, wchar_t *Format, ...)
{
  va_list ArgList; // [esp+10h] [ebp+10h]

  va_start(ArgList, Format);
  return vswprintf_s(Dst, 3u, Format, ArgList);
}

//----- (00C31DA0) --------------------------------------------------------
int *__thiscall sub_C31DA0(int *this, void *a2)
{
  int *v2; // esi

  v2 = this;
  this[5] = 7;
  this[4] = 0;
  *(_WORD *)this = 0;
  if ( *(_WORD *)a2 )
    sub_C19760(this, a2, wcslen((const unsigned __int16 *)a2));
  else
    sub_C19760(this, a2, 0);
  return v2;
}

//----- (00C31E00) --------------------------------------------------------
string *__thiscall sub_C31E00(void *this, void *a2)
{
  string *result; // eax

  if ( *(_WORD *)a2 )
    result = sub_C331B0(this, a2, wcslen((const unsigned __int16 *)a2));
  else
    result = sub_C331B0(this, a2, 0);
  return result;
}

//----- (00C31E50) --------------------------------------------------------
HRESULT __cdecl sub_C31E50(char a1, OLECHAR *a2)
{
  HRESULT v2; // esi
  __m128i v3; // xmm0
  ITaskService *v4; // ecx
  ITaskServiceVtbl *v5; // edx
  OLECHAR **v6; // eax
  OLECHAR *v7; // edx
  HRESULT v8; // eax
  OLECHAR *v9; // eax
  OLECHAR **v10; // edx
  OLECHAR *v11; // edx
  ITaskServiceVtbl *v12; // ecx
  ITriggerCollectionVtbl *v13; // ecx
  ITriggerVtbl *v14; // ecx
  OLECHAR **v15; // eax
  OLECHAR *v16; // edx
  HANDLE v17; // eax
  OLECHAR *v18; // eax
  OLECHAR **v19; // edx
  OLECHAR *v20; // edx
  HRESULT v21; // eax
  IActionCollectionVtbl *v22; // ecx
  IActionVtbl *v23; // ecx
  _DWORD *v24; // eax
  OLECHAR *v25; // edx
  HRESULT v26; // eax
  _DWORD *v27; // edx
  OLECHAR *v28; // edx
  BOOL *v29; // edx
  IPrincipalVtbl *v30; // ecx
  VARIANTARG *v31; // esi
  signed int v32; // ebx
  __m128i v33; // xmm0
  __m128i v34; // xmm0
  void **v35; // eax
  int *v36; // edi
  int v37; // edi
  __m128i v38; // xmm0
  ITaskFolderVtbl *v39; // esi
  char v40; // al
  __m128i v41; // xmm0
  __m128i v42; // xmm0
  ITaskDefinition *v44; // [esp-40h] [ebp-548h]
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
  void *v57; // [esp-Ch] [ebp-514h]
  GUID *v58; // [esp-8h] [ebp-510h]
  BOOL *v59; // [esp-4h] [ebp-50Ch]
  __int128 v60; // [esp+10h] [ebp-4F8h]
  __int128 v61; // [esp+20h] [ebp-4E8h]
  __int128 v62; // [esp+30h] [ebp-4D8h]
  VARIANTARG v63; // [esp+40h] [ebp-4C8h]
  VARIANTARG v64; // [esp+50h] [ebp-4B8h]
  VARIANTARG v65; // [esp+60h] [ebp-4A8h]
  VARIANTARG pvarg; // [esp+70h] [ebp-498h]
  ITriggerCollection *pITriggerCollection; // [esp+80h] [ebp-488h]
  IAction *pIAction; // [esp+84h] [ebp-484h]
  IRegistrationInfo *pIRegistrationInfo; // [esp+88h] [ebp-480h]
  ITrigger *pITrigger; // [esp+8Ch] [ebp-47Ch]
  IActionCollection *pIActionCollection; // [esp+90h] [ebp-478h]
  ILogonTrigger *pILogonTrigger; // [esp+94h] [ebp-474h]
  ITaskSettings *pITaskSettings; // [esp+98h] [ebp-470h]
  IExecAction *pIExecAction; // [esp+9Ch] [ebp-46Ch]
  _bstr_t v75; // [esp+A0h] [ebp-468h]
  _bstr_t v76; // [esp+A4h] [ebp-464h]
  ITaskService *pITaskService; // [esp+A8h] [ebp-460h]
  IPrincipal *pIPrincipal; // [esp+ACh] [ebp-45Ch]
  ITaskFolder *pITaskFolder; // [esp+B0h] [ebp-458h]
  ITaskDefinition *pTaskDefinition; // [esp+B4h] [ebp-454h]
  OLECHAR *pIPrincipal_12; // [esp+B8h] [ebp-450h]
  unsigned int v82; // [esp+CCh] [ebp-43Ch]
  OLECHAR *psz; // [esp+D0h] [ebp-438h]
  unsigned int v84; // [esp+E4h] [ebp-424h]
  WCHAR szDomainName[2]; // [esp+E8h] [ebp-420h]
  wchar_t Dst; // [esp+2F0h] [ebp-218h]
  int v87; // [esp+504h] [ebp-4h]

  v76.m_Data = (Data_t_bstr_t *)a2;
  pIPrincipal = 0;
  sub_C326B0(&pIPrincipal_12);
  v87 = 0;
  pITaskService = 0;
  v2 = CoCreateInstance(&CLSID_ITaskService_1, 0, 1u, &CLSID_ITaskService_0, (LPVOID *)&pITaskService);
  if ( v2 >= 0 )
  {
    VariantInit(&pvarg);
    _mm_storeu_si128((__m128i *)&v60, _mm_loadu_si128((const __m128i *)&pvarg));
    VariantInit(&v65);
    _mm_storeu_si128((__m128i *)&v61, _mm_loadu_si128((const __m128i *)&v65));
    VariantInit(&v64);
    _mm_storeu_si128((__m128i *)&v62, _mm_loadu_si128((const __m128i *)&v64));
    VariantInit(&v63);
    v3 = _mm_loadu_si128((const __m128i *)&v60);
    v4 = pITaskService;
    LOBYTE(v87) = 4;
    v5 = pITaskService->lpVtbl;
    _mm_storeu_si128((__m128i *)&v56, v3);
    _mm_storeu_si128((__m128i *)&v52, _mm_loadu_si128((const __m128i *)&v61));
    _mm_storeu_si128((__m128i *)&v48, _mm_loadu_si128((const __m128i *)&v62));
    _mm_storeu_si128((__m128i *)&v44, _mm_loadu_si128((const __m128i *)&v63));
    v2 = ((int (__stdcall *)(ITaskService *, ITaskDefinition *, signed int, int, int, int, int, DWORD, int, wchar_t *, DWORD, WCHAR *, DWORD, WCHAR *, void *, GUID *, BOOL *))v5->Connect)(
           v4,
           v44,
           v45,
           v46,
           v47,
           v48,
           v49,
           v50,
           v51,
           v52,
           v53,
           v54,
           v55,
           v56,
           v57,
           v58,
           v59);
    VariantClear(&v63);
    VariantClear(&v64);
    VariantClear(&v65);
    LOBYTE(v87) = 0;
    VariantClear(&pvarg);
    if ( v2 < 0 )
    {
      v59 = (BOOL *)pITaskService;
      pITaskService->lpVtbl->Release(pITaskService);
      goto LABEL_64;
    }
    pITaskFolder = 0;
    v6 = *_bstr_t::_bstr_t((tagEventSetItem *)&v75, L"\\");
    LOBYTE(v87) = 5;
    if ( v6 )
      v7 = *v6;
    else
      v7 = 0;
    v59 = (BOOL *)&pITaskFolder;
    v58 = (GUID *)v7;
    v57 = pITaskService;
    v8 = pITaskService->lpVtbl->GetFolder(pITaskService, v7, &pITaskFolder);
    LOBYTE(v87) = 0;
    v2 = v8;
    _bstr_t::_Free(&v75);
    if ( v2 < 0 )
    {
      v59 = (BOOL *)pITaskService;
      pITaskService->lpVtbl->Release(pITaskService);
      goto LABEL_64;
    }
    v9 = (OLECHAR *)&pIPrincipal_12;
    if ( v82 >= 8 )
      v9 = pIPrincipal_12;
    v10 = *_bstr_t::_bstr_t((tagEventSetItem *)&v75, v9);
    LOBYTE(v87) = 6;
    if ( v10 )
      v11 = *v10;
    else
      v11 = 0;
    v59 = 0;
    v58 = (GUID *)v11;
    v57 = pITaskFolder;
    pITaskFolder->lpVtbl->DeleteTask(pITaskFolder, v11, 0);
    LOBYTE(v87) = 0;
    _bstr_t::_Free(&v75);
    if ( a1 )
    {
      v59 = (BOOL *)&pTaskDefinition;
      pTaskDefinition = 0;
      v58 = 0;
      v12 = pITaskService->lpVtbl;
      v57 = pITaskService;
      v2 = v12->NewTask(pITaskService, 0, &pTaskDefinition);
      v59 = (BOOL *)pITaskService;
      pITaskService->lpVtbl->Release(pITaskService);
      if ( v2 < 0 )
      {
        v59 = (BOOL *)pITaskFolder;
        pITaskFolder->lpVtbl->Release(pITaskFolder);
        goto LABEL_64;
      }
      pIRegistrationInfo = 0;
      v59 = (BOOL *)&pIRegistrationInfo;
      v58 = (GUID *)pTaskDefinition;
      v2 = pTaskDefinition->lpVtbl->get_RegistrationInfo(pTaskDefinition, &pIRegistrationInfo);
      if ( v2 < 0 )
        goto LABEL_69;
      v59 = (BOOL *)L"Process Explorer";
      v58 = (GUID *)pIRegistrationInfo;
      v2 = pIRegistrationInfo->lpVtbl->put_Author(pIRegistrationInfo, L"Process Explorer");
      v59 = (BOOL *)pIRegistrationInfo;
      pIRegistrationInfo->lpVtbl->Release(pIRegistrationInfo);
      if ( v2 < 0 )
        goto LABEL_69;
      pITaskSettings = 0;
      v59 = (BOOL *)&pITaskSettings;
      v58 = (GUID *)pTaskDefinition;
      v2 = pTaskDefinition->lpVtbl->get_Settings(pTaskDefinition, &pITaskSettings);
      if ( v2 < 0 )
        goto LABEL_69;
      v59 = (BOOL *)-1;
      v58 = (GUID *)pITaskSettings;
      v2 = pITaskSettings->lpVtbl->put_StartWhenAvailable(pITaskSettings, -1);
      v59 = (BOOL *)pITaskSettings;
      pITaskSettings->lpVtbl->Release(pITaskSettings);
      if ( v2 < 0 )
        goto LABEL_69;
      v59 = 0;
      v58 = (GUID *)pITaskSettings;
      pITaskSettings->lpVtbl->put_DisallowStartIfOnBatteries(pITaskSettings, 0);
      pITriggerCollection = 0;
      v59 = (BOOL *)&pITriggerCollection;
      v58 = (GUID *)pTaskDefinition;
      v2 = pTaskDefinition->lpVtbl->get_Triggers(pTaskDefinition, &pITriggerCollection);
      if ( v2 < 0 )
        goto LABEL_69;
      v59 = (BOOL *)&pITrigger;
      pITrigger = 0;
      v58 = (GUID *)9;
      v13 = pITriggerCollection->lpVtbl;
      v57 = pITriggerCollection;
      v2 = v13->Create(pITriggerCollection, TASK_TRIGGER_LOGON, &pITrigger);
      v59 = (BOOL *)pITriggerCollection;
      pITriggerCollection->lpVtbl->Release(pITriggerCollection);
      if ( v2 < 0 )
        goto LABEL_69;
      v59 = (BOOL *)&pILogonTrigger;
      pILogonTrigger = 0;
      v58 = &CLSID_ILogonTrigger;
      v14 = pITrigger->lpVtbl;
      v57 = pITrigger;
      v2 = v14->QueryInterface(pITrigger, &CLSID_ILogonTrigger, (void **)&pILogonTrigger);
      v59 = (BOOL *)pITrigger;
      pITrigger->lpVtbl->Release(pITrigger);
      if ( v2 < 0 )
      {
LABEL_69:
        v59 = (BOOL *)pITaskFolder;
        pITaskFolder->lpVtbl->Release(pITaskFolder);
        v59 = (BOOL *)pTaskDefinition;
        pTaskDefinition->lpVtbl->Release(pTaskDefinition);
        goto LABEL_64;
      }
      v15 = *_bstr_t::_bstr_t((tagEventSetItem *)&pIPrincipal, L"Logon Trigger");
      LOBYTE(v87) = 7;
      if ( v15 )
        v16 = *v15;
      else
        v16 = 0;
      v59 = (BOOL *)v16;
      v58 = (GUID *)pILogonTrigger;
      pILogonTrigger->lpVtbl->put_Id(pILogonTrigger, v16);
      LOBYTE(v87) = 0;
      _bstr_t::_Free((_bstr_t *)&pIPrincipal);
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
      QueryProcessUsers(v17, v50, v51, v52, v53, v54, v55, v56, (DWORD)v57, (BOOL *)v58, v59);
      sub_C31DA0((int *)&psz, szDomainName);
      LOBYTE(v87) = 8;
      sub_C31E00(&psz, L"\\");
      sub_C31E00(&psz, &Dst);
      v18 = (OLECHAR *)&psz;
      if ( v84 >= 8 )
        v18 = psz;
      v19 = *_bstr_t::_bstr_t((tagEventSetItem *)&pIPrincipal, v18);
      LOBYTE(v87) = 9;
      if ( v19 )
        v20 = *v19;
      else
        v20 = 0;
      v59 = (BOOL *)v20;
      v58 = (GUID *)pILogonTrigger;
      v21 = pILogonTrigger->lpVtbl->put_UserId(pILogonTrigger, v20);
      LOBYTE(v87) = 8;
      v2 = v21;
      _bstr_t::_Free((_bstr_t *)&pIPrincipal);
      v59 = (BOOL *)pILogonTrigger;
      pILogonTrigger->lpVtbl->Release(pILogonTrigger);
      if ( v2 < 0 )
        goto LABEL_70;
      pIActionCollection = 0;
      v59 = (BOOL *)&pIActionCollection;
      v58 = (GUID *)pTaskDefinition;
      v2 = pTaskDefinition->lpVtbl->get_Actions(pTaskDefinition, &pIActionCollection);
      if ( v2 < 0 )
        goto LABEL_70;
      v59 = (BOOL *)&pIAction;
      pIAction = 0;
      v58 = 0;
      v22 = pIActionCollection->lpVtbl;
      v57 = pIActionCollection;
      v2 = v22->Create(pIActionCollection, 0, &pIAction);
      v59 = (BOOL *)pIActionCollection;
      pIActionCollection->lpVtbl->Release(pIActionCollection);
      if ( v2 < 0 )
        goto LABEL_70;
      v59 = (BOOL *)&pIExecAction;
      pIExecAction = 0;
      v58 = &CLSID_IExecAction;
      v23 = pIAction->lpVtbl;
      v57 = pIAction;
      v2 = v23->QueryInterface(pIAction, &CLSID_IExecAction, (void **)&pIExecAction);
      v59 = (BOOL *)pIAction;
      pIAction->lpVtbl->Release(pIAction);
      if ( v2 < 0 )
        goto LABEL_70;
      v24 = *_bstr_t::_bstr_t((tagEventSetItem *)&v76, (OLECHAR *)v76.m_Data);
      LOBYTE(v87) = 10;
      v25 = (OLECHAR *)(v24 ? *v24 : 0);
      v59 = (BOOL *)v25;
      v58 = (GUID *)pIExecAction;
      v26 = pIExecAction->lpVtbl->put_Path(pIExecAction, v25);
      LOBYTE(v87) = 8;
      v2 = v26;
      _bstr_t::_Free(&v76);
      v27 = *_bstr_t::_bstr_t((tagEventSetItem *)&v76, L"/t");
      LOBYTE(v87) = 11;
      v28 = (OLECHAR *)(v27 ? *v27 : 0);
      v59 = (BOOL *)v28;
      v58 = (GUID *)pIExecAction;
      pIExecAction->lpVtbl->put_Arguments(pIExecAction, v28);
      LOBYTE(v87) = 8;
      _bstr_t::_Free(&v76);
      v59 = (BOOL *)pIExecAction;
      pIExecAction->lpVtbl->Release(pIExecAction);
      if ( v2 < 0 )
        goto LABEL_70;
      if ( IsBuiltinAdministrative() )
      {
        pIPrincipal = 0;
        v59 = (BOOL *)&pIPrincipal;
        v58 = (GUID *)pTaskDefinition;
        pTaskDefinition->lpVtbl->get_Principal(pTaskDefinition, &pIPrincipal);
        v29 = (BOOL *)&psz;
        if ( v84 >= 8 )
          v29 = (BOOL *)psz;
        v30 = pIPrincipal->lpVtbl;
        v59 = v29;
        v58 = (GUID *)pIPrincipal;
        v30->put_UserId(pIPrincipal, (BSTR)v29);
        v59 = (BOOL *)1;
        v58 = (GUID *)pIPrincipal;
        pIPrincipal->lpVtbl->put_RunLevel(pIPrincipal, TASK_RUNLEVEL_HIGHEST);
        v59 = (BOOL *)pIPrincipal;
        pIPrincipal->lpVtbl->Release(pIPrincipal);
      }
      v75.m_Data = 0;
      if ( IsBuiltinAdministrative() )
      {
        v31 = (VARIANTARG *)sub_C093D0(&v63, L"Builtin\\Administrators");
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
      pIPrincipal = (IPrincipal *)v32;
      v33 = _mm_loadu_si128((const __m128i *)sub_C093D0(&v64, (OLECHAR *)&gszNullString));
      v87 = 14;
      v59 = (BOOL *)&pvarg;
      _mm_storeu_si128((__m128i *)&v62, v33);
      VariantInit((VARIANTARG *)v59);
      v34 = _mm_loadu_si128((const __m128i *)&pvarg);
      v35 = (void **)&pIPrincipal_12;
      LOBYTE(v87) = 15;
      if ( v82 >= 8 )
        v35 = (void **)pIPrincipal_12;
      _mm_storeu_si128((__m128i *)&v61, v34);
      v59 = (BOOL *)v35;
      _mm_storeu_si128((__m128i *)&v60, _mm_loadu_si128((const __m128i *)v31));
      v36 = (int *)*_bstr_t::_bstr_t((tagEventSetItem *)&v76, (OLECHAR *)v59);
      LOBYTE(v87) = 16;
      if ( v36 )
        v37 = *v36;
      else
        v37 = 0;
      v38 = _mm_loadu_si128((const __m128i *)&v62);
      v39 = pITaskFolder->lpVtbl;
      v59 = (BOOL *)&v75;
      _mm_storeu_si128((__m128i *)&v55, v38);
      v40 = IsBuiltinAdministrative();
      v41 = _mm_loadu_si128((const __m128i *)&v61);
      v54 = (WCHAR *)((v40 != 0) + 3);
      _mm_storeu_si128((__m128i *)&v50, v41);
      v42 = _mm_loadu_si128((const __m128i *)&v60);
      v45 = 6;
      v44 = pTaskDefinition;
      _mm_storeu_si128((__m128i *)&v46, v42);
      v2 = ((int (__stdcall *)(ITaskFolder *, int, ITaskDefinition *, signed int, int, int, int, int, DWORD, int, wchar_t *, DWORD, WCHAR *, DWORD, WCHAR *, void *, GUID *, BOOL *))v39->RegisterTaskDefinition)(
             pITaskFolder,
             v37,
             v44,
             v45,
             v46,
             v47,
             v48,
             v49,
             v50,
             v51,
             v52,
             v53,
             v54,
             v55,
             v56,
             v57,
             v58,
             v59);
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
        v59 = (BOOL *)pITaskFolder;
        pITaskFolder->lpVtbl->Release(pITaskFolder);
        v59 = (BOOL *)pTaskDefinition;
        pTaskDefinition->lpVtbl->Release(pTaskDefinition);
        sub_BE3820((int)&psz);
        goto LABEL_64;
      }
      v59 = (BOOL *)pTaskDefinition;
      pTaskDefinition->lpVtbl->Release(pTaskDefinition);
      v59 = (BOOL *)v75.m_Data;
      (*((void (__stdcall **)(Data_t_bstr_t *))v75.m_Data->m_wstr + 2))(v75.m_Data);
      LOBYTE(v87) = 0;
      sub_BE3820((int)&psz);
    }
    v59 = (BOOL *)pITaskFolder;
    pITaskFolder->lpVtbl->Release(pITaskFolder);
    v2 = 0;
  }
LABEL_64:
  if ( v82 >= 8 )
    operator delete(pIPrincipal_12);
  return v2;
}
// CB776C: using guessed type GUID CLSID_ILogonTrigger;
// CB781C: using guessed type GUID CLSID_IExecAction;

//----- (00C326B0) --------------------------------------------------------
void *__cdecl sub_C326B0(void *a1)
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
  sub_C19760((int *)&v6, szDomainName, v3);
  v11 = 1;
  sub_C331B0(&v6, L"-", 1);
  if ( Dst )
    v4 = wcslen(&Dst);
  else
    v4 = 0;
  sub_C331B0(&v6, &Dst, v4);
  *((_DWORD *)a1 + 5) = 7;
  *((_DWORD *)a1 + 4) = 0;
  *(_WORD *)a1 = 0;
  sub_C19760((int *)a1, L"Process Explorer-", 17);
  sub_C330E0(a1, (int)&v6, 0, -1);
  if ( v8 >= 8 )
    operator delete(v6);
  return a1;
}
// CAF134: using guessed type wchar_t asc_CAF134[2];
// CAF138: using guessed type wchar_t aProcessExplore_3[18];

//----- (00C32850) --------------------------------------------------------
errno_t __cdecl sub_C32850(wchar_t *pszBuffer, rsize_t SizeInWords)
{
  DWORD nLength; // [esp+Ch] [ebp-420h]
  __int16 RemoteName[520]; // [esp+10h] [ebp-41Ch]
  __int16 LocalName[4]; // [esp+420h] [ebp-Ch]

  GetModuleFileNameW(0, pszBuffer + 1, SizeInWords - 2);
  sub_C31D80((wchar_t *)LocalName, L"%c:", pszBuffer[1]);
  nLength = 520;
  if ( !WNetGetConnectionW((LPCWSTR)LocalName, (LPWSTR)RemoteName, &nLength) )
  {
    wcscat_s((wchar_t *)RemoteName, 0x208u, pszBuffer + 2);
    wcscpy_s(pszBuffer + 1, SizeInWords - 1, (const wchar_t *)RemoteName);
  }
  *pszBuffer = '"';
  wcscat_s(pszBuffer, SizeInWords, L"\"");
  return _wcsupr_s(pszBuffer, SizeInWords);
}

//----- (00C32910) --------------------------------------------------------
char __cdecl sub_C32910(int a1, int a2, int a3, wchar_t *Dst, rsize_t SizeInWords)
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
        v6 = (_DWORD *)a3;
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
  v10 = (const wchar_t **)sub_C24BD0((CString *)&v13, v5->szAddress);
  wcscpy_s(Dst, SizeInWords, *v10);
  v11 = v13 - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)(v13 - 16 + 12)) <= 0 )
    (*(void (__stdcall **)(int))(**(_DWORD **)v11 + 4))(v11);
  return 1;
}

//----- (00C329E0) --------------------------------------------------------
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
    v3 = (WCHAR *)malloc(cbData);
    if ( !RegQueryValueExW(hKey, lpValueName, 0, 0, (LPBYTE)v3, &cbData) )
    {
      v4 = ExpandEnvironmentStringsW(v3, 0, 0);
      cbData = v4;
      if ( v4 )
      {
        v2 = (WCHAR *)malloc(2 * v4);
        ExpandEnvironmentStringsW(v3, v2, v4);
      }
    }
    free(v3);
  }
  return v2;
}

//----- (00C32A70) --------------------------------------------------------
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
    v1 = gethostbyaddr((const char *)&a1->field_110, 16, 23);
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
    v3 = (tagItem124_InTcpUdp *)htonl(a1->field_108);
    v12 = gethostbyaddr((const char *)&a1->field_108, 4, 2);
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
      MakeAddressInfo(
        szAddress,
        "%d.%d.%d.%d",
        (unsigned int)v3 >> 24,
        ((unsigned int)v3 >> 16) & 0xFF,
        (unsigned __int16)v3 >> 8,
        (unsigned __int8)v3);
    }
  }
  _strlwr_s(szAddress, 0x104u);
  EnterCriticalSection(&gLock2);
  pItem = (tagItem124_InTcpUdp *)malloc(0x124u);
  strcpy_s(pItem->szAddress, 0x104u, szAddress);
  pItem->field_10C = (int)v3;
  _mm_storeu_si128((__m128i *)&pItem->field_110, _mm_loadu_si128((const __m128i *)&a1->field_110));
  pItem->field_0 = a1->field_0;
  pItem->pNext = gpItem124_InTcpUdp;
  v14 = dword_CD9E7C;
  gpItem124_InTcpUdp = pItem;
  if ( dword_CD9E7C )
  {
    while ( (tagItem124_InTcpUdp *)v14->field_10C != v3 )
    {
      v14 = v14->pNext;
      if ( !v14 )
        goto LABEL_15;
    }
    dword_CD9E7C = v14->pNext;
    free(v14);
  }
LABEL_15:
  SetEvent(ghEvent6);
  v2(&gLock2);
}

//----- (00C32CD0) --------------------------------------------------------
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
  LOBYTE(v5) = (unsigned int)memset(&Item.iItem, 0, 0x30u);
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
        v10 = *(unsigned __int16 *)(v4 + v9);
        v5 = (volatile signed __int32 *)_ismbcprint(v10);
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
                v14 = (WCHAR *)(a4 - a2 + 1);
                v30 = (WCHAR *)(a4 - a2 + 1);
                do
                {
                  if ( v8 >= (unsigned int)v14 )
                    break;
                  v15 = iswalpha(*(char *)(v32 + v8));
                  v12 = v31;
                  if ( v15 )
                    v12 = v31++ + 1;
                  v16 = *(char *)(v32 + v8);
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
                JUMPOUT(*(_DWORD *)algn_C32FF0);
              }
              LOBYTE(v5) = 0;
              v35[v17] = 0;
              if ( v12 >= v11 )
              {
                v34 = 0;
                Item.pszText = (LPWSTR)v35;
                Item.mask = 5;
                Item.iItem = 0x7FFFFFFF;
                Item.lParam = (tagTREEVIEWLISTITEMPARAM *)1;
                LOBYTE(v5) = SendMessageW(hWnd, LVM_INSERTITEMW, 0, (LPARAM)&Item);
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
        LOBYTE(v5) = *(_BYTE *)(v4 + v19);
        if ( ((char)v5 < 32 || (char)v5 >= 126) && (_BYTE)v5 != 126 )
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
                v5 = (volatile signed __int32 *)&MultiByteStr[-v18];
                v28 = &MultiByteStr[-v18];
                do
                {
                  if ( v18 >= v22 )
                    break;
                  v23 = isalpha(*(char *)(v32 + v18));
                  v20 = v31;
                  if ( v23 )
                    v20 = v31++ + 1;
                  ++v21;
                  LOBYTE(v5) = *(_BYTE *)(v32 + v18);
                  v28[v18++] = (char)v5;
                  v22 = v27;
                }
                while ( v18 < v19 );
                if ( v21 >= 0x10000 )
                  goto LABEL_51;
                v7 = a2;
              }
              MultiByteStr[v21] = 0;
              if ( v20 >= (signed int)v7 )
              {
                sub_C24BD0((CString *)&v30, MultiByteStr);
                Item.pszText = v30;
                Item.mask = 5;
                Item.iItem = 0x7FFFFFFF;
                v34 = 0;
                Item.lParam = (tagTREEVIEWLISTITEMPARAM *)1;
                SendMessageW(hWnd, 0x104Du, 0, (LPARAM)&Item);
                v24 = (int)(v30 - 8);
                v5 = (volatile signed __int32 *)(v30 - 2);
                if ( _InterlockedDecrement(v5) <= 0 )
                  LOBYTE(v5) = (*(int (__stdcall **)(int))(**(_DWORD **)v24 + 4))(v24);
                v7 = a2;
              }
              v4 = v32;
              v6 = a4;
            }
            v18 = -1;
          }
        }
        else if ( (_BYTE)v5 != 32 && v18 == -1 )
        {
          v18 = v19;
        }
        ++v19;
      }
      while ( v19 < v6 );
    }
  }
  return (char)v5;
}
// C767E8: using guessed type int __report_rangecheckfailure(void);
// C32CD0: using guessed type __int16 var_20004[65536];
// C32CD0: using guessed type CHAR MultiByteStr[1024];

//----- (00C33000) --------------------------------------------------------
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
      pszSuiteName = (WCHAR *)LocalAlloc(LMEM_ZEROINIT, cbData);
      pszName = pszSuiteName;
      if ( pszSuiteName )
      {
        if ( !RegQueryValueExW(hKey, L"ProductSuite", 0u, &dwType, (LPBYTE)pszSuiteName, &cbData)
          && dwType == REG_MULTI_SZ )
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

//----- (00C330E0) --------------------------------------------------------
string *__thiscall sub_C330E0(void *this, int a2, int a3, int a4)
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

  v4 = (_DWORD *)a2;
  v5 = (string *)this;
  v6 = *(_DWORD *)(a2 + 16);
  if ( v6 < a3 )
    std::_Xout_of_range("invalid string position");
  v7 = a4;
  v8 = v6 - a3;
  v9 = *((_DWORD *)this + 4);
  v14 = v5->_Myval2._Mysize;
  if ( v8 < a4 )
    v7 = v8;
  if ( -1 - v9 <= v7 )
    std::_Xlength_error("string too long");
  if ( v7 && (unsigned __int8)sub_BEFC40(v5, v9 + v7, 0) )
  {
    if ( v4[5] >= 8u )
      v4 = (_DWORD *)*v4;
    if ( v5->_Myval2._Myres < 8 )
      v10 = v5;
    else
      v10 = (string *)v5->_Myval2._Bx._Ptr;
    if ( v7 )
      memmove_0(&v10->_Myval2._Bx._Buf[v5->_Myval2._Mysize], (char *)v4 + 2 * a3, 2 * v7);
    v11 = v7 + v14;
    v12 = v5->_Myval2._Myres < 8;
    v5->_Myval2._Mysize = v7 + v14;
    if ( !v12 )
    {
      *(_WORD *)&v5->_Myval2._Bx._Ptr[2 * v11] = 0;
      return v5;
    }
    v5->_Myval2._Bx._Buf[v11] = 0;
  }
  return v5;
}

//----- (00C331B0) --------------------------------------------------------
string *__thiscall sub_C331B0(void *this, void *a2, int a3)
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
  v4 = (string *)this;
  if ( a2
    && ((v5 = *((_DWORD *)this + 5), v5 < 8) ? (v6 = (unsigned int)v4) : (v6 = (unsigned int)v4->_Myval2._Bx._Ptr),
        (unsigned int)a2 >= v6
     && (v5 < 8 ? (v7 = v4) : (v7 = (string *)v4->_Myval2._Bx._Ptr), (char *)v7 + 2 * v4->_Myval2._Mysize > a2)) )
  {
    if ( v5 < 8 )
      v8 = v4;
    else
      v8 = (string *)v4->_Myval2._Bx._Ptr;
    result = sub_C330E0(v4, (int)v4, ((_BYTE *)a2 - (_BYTE *)v8) >> 1, a3);
  }
  else
  {
    v10 = (char *)v4->_Myval2._Mysize;
    v14 = v10;
    if ( -1 - (signed int)v10 <= (unsigned int)a3 )
      std::_Xlength_error("string too long");
    if ( a3 && (unsigned __int8)sub_BEFC40(v4, (int)&v10[a3], 0) )
    {
      if ( v4->_Myval2._Myres < 8 )
        v11 = v4;
      else
        v11 = (string *)v4->_Myval2._Bx._Ptr;
      if ( a3 )
        memmove_0(&v11->_Myval2._Bx._Buf[v4->_Myval2._Mysize], v3, 2 * a3);
      v12 = (int)&v14[a3];
      v13 = v4->_Myval2._Myres < 8;
      v4->_Myval2._Mysize = (size_t)&v14[a3];
      if ( !v13 )
      {
        *(_WORD *)&v4->_Myval2._Bx._Ptr[2 * v12] = 0;
        return v4;
      }
      v4->_Myval2._Bx._Buf[v12] = 0;
    }
    result = v4;
  }
  return result;
}

//----- (00C33290) --------------------------------------------------------
LPCWSTR __cdecl PE_GetNumberFormat(LPCWSTR lpValue, rsize_t SizeInWords)
{
  wchar_t *v2; // eax
  __int16 NumberStr[1024]; // [esp+4h] [ebp-804h]

  GetNumberFormatW(0x400u, 0, lpValue, 0, (LPWSTR)NumberStr, 1024);
  wcscpy_s((wchar_t *)lpValue, SizeInWords, (const wchar_t *)NumberStr);
  v2 = wcsstr(lpValue, &gszLocaleInfo);
  if ( v2 )
    *v2 = 0;
  return lpValue;
}

//----- (00C33300) --------------------------------------------------------
void __cdecl SaveCmdLineToMRUList(LPCWSTR lpszText)
{
  int v1; // edi
  int v2; // esi
  int v3; // edx
  WCHAR v4; // ax
  WCHAR v5; // cx
  LPCWSTR v6; // esi
  WCHAR v7; // ax
  size_t v8; // esi
  wchar_t *pszBuffer; // edi
  wchar_t *v10; // ecx
  wchar_t v11; // ax
  DWORD cbData; // [esp+8h] [ebp-618h]
  WCHAR ValueName[2]; // [esp+Ch] [ebp-614h]
  HKEY phkResult; // [esp+10h] [ebp-610h]
  wchar_t szText1[260]; // [esp+14h] [ebp-60Ch]
  WCHAR szText2[256]; // [esp+21Ch] [ebp-404h]
  WCHAR szMRUList[256]; // [esp+41Ch] [ebp-204h]

  szMRUList[0] = 0;
  memset(&szMRUList[1], 0, 0x1FEu);
  szText2[0] = 0;
  memset(&szText2[1], 0, 0x1FEu);
  *(_DWORD *)ValueName = 65;
  v1 = 0;
  if ( !RegOpenKeyW(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\RunMRU", &phkResult) )
  {
    cbData = 512;
    RegQueryValueExW(phkResult, L"MRUList", 0, 0, (LPBYTE)szMRUList, &cbData);
    _wcslwr_s(szMRUList, 256u);
    v2 = 0;
    if ( (signed int)wcslen(szMRUList) <= 0 )
    {
LABEL_8:
      wcscpy_s(&szText2[1], 255u, szMRUList);
      szText2[26] = 0;
      v3 = 0;
      while ( (1 << v3) & v1 )
      {
        if ( ++v3 >= 26 )
        {
          v4 = szText2[0];
          goto LABEL_14;
        }
      }
      v4 = v3 + 97;
LABEL_14:
      v5 = v4;
      v6 = lpszText;
      if ( v3 == 26 )
        v5 = szMRUList[25];
      szText2[0] = v5;
      ValueName[0] = v5;
      do
      {
        v7 = *v6;
        ++v6;
      }
      while ( v7 );
      v8 = v6 - (lpszText + 1) + 3;
      pszBuffer = (wchar_t *)malloc(2 * v8);
      swprintf_s(pszBuffer, v8, L"%s\\1", lpszText);
      v10 = pszBuffer;
      do
      {
        v11 = *v10;
        ++v10;
      }
      while ( v11 );
      RegSetValueExW(phkResult, ValueName, 0, 1u, (const BYTE *)pszBuffer, 2 * (v10 - (pszBuffer + 1)) + 2);
      RegSetValueExW(phkResult, L"MRUList", 0, 1u, (const BYTE *)szText2, 2 * wcslen(szText2) + 2);
      RegCloseKey(phkResult);
      free(pszBuffer);
    }
    else
    {
      while ( 1 )
      {
        ValueName[0] = szMRUList[v2];
        cbData = 520;
        v1 |= 122 - ValueName[0] > 1;
        if ( !RegQueryValueExW(phkResult, ValueName, 0, 0, (LPBYTE)szText1, &cbData) )
        {
          if ( wcsrchr(szText1, '\\') )
            *wcsrchr(szText1, '\\') = 0;
          if ( !_wcsicmp(lpszText, szText1) )
            break;
        }
        if ( ++v2 >= (signed int)wcslen(szMRUList) )
          goto LABEL_8;
      }
      RegCloseKey(phkResult);
    }
  }
}

//----- (00C335F0) --------------------------------------------------------
BOOL __cdecl ReplaceMenuIconFromStockIcon(HMENU hmenu, UINT item)
{
  DWORD v2; // esi
  MENUITEMINFOW mii; // [esp+8h] [ebp-24Ch]
  int v5; // [esp+38h] [ebp-21Ch]
  DWORD v6; // [esp+3Ch] [ebp-218h]

  v2 = dword_CD9E80;
  if ( !dword_CD9E80 )
  {
    memset(&v6, dword_CD9E80, 0x214u);
    v5 = 536;
    SHGetStockIconInfo(77, 257, &v5);
    v2 = v6;
    dword_CD9E80 = v6;
  }
  memset(&mii.fMask, 0, 0x2Cu);
  mii.cbSize = 48;
  mii.fMask = 160;
  mii.hbmpItem = (HBITMAP)-1;
  mii.dwItemData = v2;
  return SetMenuItemInfoW(hmenu, item, 0, &mii);
}
// CEBA50: using guessed type int (__stdcall *SHGetStockIconInfo)(_DWORD, _DWORD, _DWORD);

//----- (00C336B0) --------------------------------------------------------
bool __cdecl sub_C336B0(int a1, unsigned int a2, char a3, char a4)
{
  unsigned int v4; // esi
  _DWORD *v5; // edx

  v4 = 0;
  if ( !a2 )
    return 0;
  v5 = (_DWORD *)(a1 + 4);
  while ( *v5 != 1 && *v5 || !((1 << a3) & *(v5 - 1)) )
  {
    ++v4;
    v5 += 6;
    if ( v4 >= a2 )
      return 0;
  }
  return ((1 << a4) & *(_DWORD *)(a1 + 24 * v4)) != 0;
}

//----- (00C33710) --------------------------------------------------------
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
    SendMessageW(v3, TCM_ADJUSTRECT, 0, (LPARAM)&Rect);
    MapWindowPoints(0, hWnd, (LPPOINT)&Rect, 2u);
    SetWindowPos(hWnd, 0, Rect.left, Rect.top, Rect.right - Rect.left, Rect.bottom - Rect.top, SWP_NOACTIVATE);
    hWndTab = (HWND)gpfnEnableThemeDialogTexture;
    if ( gpfnEnableThemeDialogTexture )
      hWndTab = (HWND)gpfnEnableThemeDialogTexture(hWnd, 6);
  }
  return hWndTab;
}
// CD9E88: using guessed type int (__stdcall *gpfnEnableThemeDialogTexture)(_DWORD, _DWORD);

//----- (00C337B0) --------------------------------------------------------
signed int __cdecl sub_C337B0(unsigned __int64 a1, unsigned __int64 a2)
{
  signed int result; // eax

  if ( HIDWORD(a1) < HIDWORD(a2) )
    goto LABEL_10;
  if ( HIDWORD(a1) > HIDWORD(a2) || (unsigned int)a1 > (unsigned int)a2 )
    return 1;
  if ( a1 >= a2 )
    result = 0;
  else
LABEL_10:
    result = -1;
  return result;
}

//----- (00C337F0) --------------------------------------------------------
BOOL __cdecl sub_C337F0(char a1)
{
  DWORD v1; // esi
  HKEY phkResult; // [esp+4h] [ebp-418h]
  __int16 Data[520]; // [esp+8h] [ebp-414h]

  Data[0] = 0;
  memset(&Data[1], 0, 0x40Eu);
  sub_C32850((wchar_t *)Data, 0x208u);
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
      wcscat_s((wchar_t *)Data, 0x208u, L" /t");
      v1 = RegSetValueExW(
             phkResult,
             L"Process Explorer",
             0,
             1u,
             (const BYTE *)Data,
             2 * wcslen((const unsigned __int16 *)Data) + 2);
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
    v1 = sub_C31E50(a1, (OLECHAR *)Data);
  }
  if ( v1 )
    goto LABEL_10;
  return v1 == 0;
}
// CD4E54: using guessed type int gdwVersion;

//----- (00C33940) --------------------------------------------------------
LRESULT __cdecl CTreeList::InitToolTips(HWND hWnd)
{
  SendMessageW(hWnd, TTM_SETDELAYTIME, 3u, 0);
  SendMessageW(hWnd, TTM_SETMAXTIPWIDTH, 0, 4000);
  return SendMessageW(hWnd, TTM_SETDELAYTIME, 2u, 1000000);
}

//----- (00C33980) --------------------------------------------------------
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

//----- (00C33A30) --------------------------------------------------------
char __cdecl MakeApplicationName(LPCWSTR lpFileName, wchar_t *lpszPathName, int dwSize, wchar_t *szFullName)
{
  char result; // al
  rsize_t v5; // ebx
  wchar_t *pszPathName; // edi
  wchar_t *pszText; // esi
  wchar_t *pstr; // eax
  wchar_t *v9; // eax

  if ( GetFileAttributesW(lpFileName) == -1 )
  {
    v5 = wcslen(lpFileName) + dwSize + 2;
    pszPathName = lpszPathName;
    pszText = (wchar_t *)malloc(2 * v5);
    if ( lpszPathName )
    {
      while ( *pszPathName )
      {
        wcscpy_s(pszText, v5, pszPathName);
        pstr = wcschr(pszText, ';');
        if ( pstr )
          *pstr = 0;
        wcscat_s(pszText, v5, L"\\");
        wcscat_s(pszText, v5, lpFileName);
        if ( GetFileAttributesW(pszText) != -1 )
        {
          wcscpy_s(szFullName, 0x104u, pszText);
          operator delete(pszText);
          return 1;
        }
        v9 = wcschr(pszPathName, ';');
        if ( v9 )
        {
          pszPathName = v9 + 1;
          if ( v9 != (wchar_t *)-2 )
            continue;
        }
        break;
      }
    }
    operator delete(pszText);
    result = 0;
  }
  else
  {
    wcscpy_s(szFullName, 0x104u, lpFileName);
    result = 1;
  }
  return result;
}

//----- (00C33B30) --------------------------------------------------------
HWND __cdecl QueryTopMostWindowByProcessID(int dwProcessId_1)
{
  HWND ret; // edi
  HWND hWndFound; // esi
  HWND v3; // eax
  HWND v4; // eax
  DWORD dwPid; // [esp+8h] [ebp-1004h]
  WINDOWPLACEMENT wp; // [esp+Ch] [ebp-1000h]
  int v8; // [esp+28h] [ebp-FE4h]
  int v9; // [esp+30h] [ebp-FDCh]
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
      if ( !IsIconic(hWndFound) || (GetWindowPlacement(hWndFound, &wp), v9 - v8 > 1) )
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

//----- (00C33C40) --------------------------------------------------------
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
  wcscpy_s((wchar_t *)szBuffer, 32u, pszUnit);
LABEL_8:
  if ( szBuffer[0] )
    return swprintf_s(pszText, dwLength, L"%0.1f %s", LODWORD(dbValueNew), HIDWORD(dbValueNew), szBuffer);
  if ( dbValueNew == 0.0 )
    return swprintf_s(pszText, dwLength, L"0");
  return swprintf_s(pszText, dwLength, L"%0.0f B", LODWORD(dbValueNew), HIDWORD(dbValueNew));
}
// CACBE0: using guessed type wchar_t aGb[4];

//----- (00C33D60) --------------------------------------------------------
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
    wcscpy_s(pszName, cbName, (const wchar_t *)v5->szName);
    wcscpy_s(pszDomainName, cbDomainName, (const wchar_t *)v5->szDomainName);
    result = 1;
  }
  else
  {
LABEL_4:
    if ( LookupAccountSidW((LPCWSTR)&gszNullString, pSID, pszName, &cbName, pszDomainName, &cbDomainName, &nUse) )
    {
      v6 = (tagUserInfoWithSID *)malloc(sizeof(tagUserInfoWithSID));
      v7 = GetLengthSid(pSID);
      v8 = malloc(v7);
      v6->pSID = v8;
      v9 = v8;
      v10 = GetLengthSid(pSID);
      CopySid(v10, v9, pSID);
      wcscpy_s((wchar_t *)v6->szName, 0x104u, pszName);
      wcscpy_s((wchar_t *)v6->szDomainName, 0x104u, pszDomainName);
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

//----- (00C33E70) --------------------------------------------------------
int *__cdecl sub_C33E70(PSYSTEM_LOGICAL_PROCESSOR_INFORMATION pSystemLogicalProcessorInfo, int dwCount, signed int dwProcessorID, signed int *pnValue1, int *pnValue2)
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
  pRelationShip = (PUCHAR)&pSystemLogicalProcessorInfo->Relationship;
  do
  {
    if ( (1 << dwProcessorID) & *((_DWORD *)pRelationShip - 1) )
    {
      RelationShip = *(_DWORD *)pRelationShip;
      if ( *(_DWORD *)pRelationShip == RelationNumaNode )
      {
        NodeNumber = *((_DWORD *)pRelationShip + 1);
      }
      else
      {
        if ( RelationShip )
          goto LABEL_10;
        // RelationProcessorCore
        dwProcessorCoreCount_1 = dwProcessorCoreCount;
      }
    }
    RelationShip = *(_DWORD *)pRelationShip;
    if ( !*(_DWORD *)pRelationShip )
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
// C33ECC: CONTAINING_RECORD: no field 'PUCHAR' in struct 'SYSTEM_LOGICAL_PROCESSOR_INFORMATION' at 24

//----- (00C33F20) --------------------------------------------------------
int __cdecl sub_C33F20(_DWORD *a1, unsigned int a2, int a3)
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

//----- (00C33F80) --------------------------------------------------------
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

  bstrResult.m_Data = (Data_t_bstr_t *)strText1;
  v5 = pszFileName_1;
  dwLen = (DWORD)bstrDesc;
  bstrText.m_Data = 0;
  do
  {
    v6 = *v5;
    ++v5;
  }
  while ( v6 );
  _wcsupr_s(pszFileName_1, v5 - (pszFileName_1 + 1) + 1);
  _bstr_t::operator=((EventItem *)&bstrText, pszFileName_1);
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
    bstrPid = (_bstr_t *)_bstr_t::_bstr_t((tagEventSetItem *)&str, v10 + 11);
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
      if ( !RegQueryValueExW(hSubKey, 0, 0, 0, (LPBYTE)szValue, &cbData) )
      {
        v15 = _wcsdup(szValue);
        v16 = hSubKey;
        bstrResult.m_Data->m_wstr = v15;
        RegCloseKey(v16);
      }
      _bstr_t::_bstr_t((tagEventSetItem *)&str, L"\\InProcServer32");
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
          v24 = (int)(pstrEnvKey + 1);
          do
          {
            v25 = *v23;
            ++v23;
          }
          while ( v25 );
          _wcslwr_s(pszFileName, (((signed int)v23 - v24) >> 1) + 1);
          v26 = (Data_t_bstr_t *)_wcsdup(pszFileName);
          v27 = (WCHAR **)dwLen;
          strText2->m_Data = v26;
          PE_GetProductCopyright(pszFileName, (wchar_t *)Dst, 0x40u, v27, (WCHAR **)strCopyright);
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
      operator delete[](v7->m_str);
      v7->m_str = 0;
    }
    operator delete(v7);
  }
}

//----- (00C34280) --------------------------------------------------------
wchar_t *__cdecl sub_C34280(wchar_t *a1)
{
  rsize_t v1; // ebx
  wchar_t *v2; // esi
  wchar_t *v3; // eax
  wchar_t *result; // eax
  WCHAR Buffer; // [esp+Ch] [ebp-20Ch]
  wchar_t v6; // [esp+12h] [ebp-206h]

  GetSystemDirectoryW(&Buffer, 0x104u);
  v1 = wcslen(&Buffer) + wcslen(a1) + 19;
  v2 = (wchar_t *)malloc(2 * v1);
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
// CAEF74: using guessed type wchar_t aCS[6];

//----- (00C343C0) --------------------------------------------------------
DWORD __cdecl PE_GetProductCopyright(LPCWSTR lpszFileName, wchar_t *pszBuffer, rsize_t cbBufLen, WCHAR **ppszDesc, WCHAR **ppszCopyright)
{
  WCHAR **v5; // edi
  DWORD v6; // eax
  int *pBlock; // esi
  const wchar_t *pszFileDesc; // eax
  const wchar_t *pszCompany; // eax
  DWORD dwHandle; // [esp+8h] [ebp-4h]
  WCHAR **dwLena; // [esp+20h] [ebp+14h]

  wcscpy_s(pszBuffer, cbBufLen, (const wchar_t *)&gszNullString);
  v5 = ppszDesc;
  *ppszDesc = 0;
  *ppszCopyright = 0;
  v6 = GetFileVersionInfoSizeW(lpszFileName, &dwHandle);
  dwLena = (WCHAR **)v6;
  if ( !v6 )
    return GetLastError();
  pBlock = (int *)malloc(v6);
  if ( GetFileVersionInfoW(lpszFileName, 0, (DWORD)dwLena, pBlock) )
  {
    PE_MakeFileVersion(pBlock[13], pBlock[12], pszBuffer, cbBufLen);
    pszFileDesc = (const wchar_t *)PE_QueryFileVersionBlock(pBlock, L"FileDescription");
    if ( pszFileDesc || (pszFileDesc = (const wchar_t *)PE_QueryFileVersionBlock(pBlock, L"ProductDescription")) != 0 )
      *v5 = _wcsdup(pszFileDesc);
    pszCompany = (const wchar_t *)PE_QueryFileVersionBlock(pBlock, L"CompanyName");
    if ( pszCompany || (pszCompany = (const wchar_t *)PE_QueryFileVersionBlock(pBlock, L"Copyright")) != 0 )
      *ppszCopyright = _wcsdup(pszCompany);
  }
  free(pBlock);
  return 0;
}

//----- (00C344B0) --------------------------------------------------------
char __cdecl sub_C344B0(int a1, char a2, int a3, u_long hostlong, tagItem124_InTcpUdp *a5, wchar_t *Dst, size_t SizeInWords)
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
    if ( sub_C32910(a1, v7, (int)a5, Dst, SizeInWords) )
    {
      result = 1;
    }
    else
    {
      swprintf_s(
        Dst,
        SizeInWords,
        L"%d.%d.%d.%d",
        v8 >> 24,
        (v8 >> 16) & 0xFF,
        (unsigned __int16)v8 >> 8,
        (unsigned __int8)v8);
      EnterCriticalSection(&gLock2);
      v18 = dword_CD9E7C;
      if ( dword_CD9E7C )
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
        v19 = (tagItem124_InTcpUdp *)malloc(0x124u);
        v19->field_0 = a1;
        v19->field_108 = hostlong;
        v19->field_10C = v8;
        if ( a5 )
          _mm_storeu_si128((__m128i *)&v19->field_110, _mm_loadu_si128((const __m128i *)a5));
        v19->pNext = dword_CD9E7C;
        dword_CD9E7C = v19;
        _beginthread((int)tagItem124_InTcpUdp_Query, 0, (int)v19);
      }
      LeaveCriticalSection(&gLock2);
      result = 0;
    }
  }
  else if ( a1 && a1 != 1 )
  {
    v9 = htons(*(_WORD *)&a5->szAddress[10]);
    v10 = htons(*(_WORD *)&a5->szAddress[8]);
    v11 = htons(*(_WORD *)&a5->szAddress[6]);
    v12 = htons(*(_WORD *)&a5->szAddress[4]);
    v13 = htons(*(_WORD *)&a5->szAddress[2]);
    v14 = htons(*(_WORD *)a5->szAddress);
    v15 = htons(HIWORD(a5->field_0));
    v16 = htons(a5->field_0);
    swprintf_s(Dst, SizeInWords, L"[%x:%x:%x:%x:%x:%x:%x:%x]", v16, v15, v14, v13, v12, v11, v10, v9);
    result = 0;
  }
  else
  {
    swprintf_s(
      Dst,
      SizeInWords,
      L"%d.%d.%d.%d",
      v7 >> 24,
      (v7 >> 16) & 0xFF,
      (unsigned __int16)v7 >> 8,
      (unsigned __int8)v7);
    result = 0;
  }
  return result;
}

//----- (00C34670) --------------------------------------------------------
wchar_t *__cdecl sub_C34670(char a1, int port, char *proto, wchar_t *Dst, size_t SizeInWords)
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

//----- (00C346D0) --------------------------------------------------------
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
  return _wcsdup((const wchar_t *)gpProcessComments[index].pszComment);
}

//----- (00C34730) --------------------------------------------------------
int __cdecl sub_C34730(wchar_t *a1, int a2)
{
  int result; // eax

  *(_DWORD *)a2 = 0;
  result = (int)wcsstr(a1, L"-k");
  if ( result )
  {
    result = (int)(wcsstr(a1, L"-k") + 3);
    if ( result )
    {
      result = (int)_wcsdup((const wchar_t *)result);
      *(_DWORD *)a2 = result;
    }
  }
  return result;
}

//----- (00C34780) --------------------------------------------------------
WCHAR *__cdecl sub_C34780(wchar_t *a1, LPCWSTR lpServiceName)
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
    hService = (SC_HANDLE)(v6 - (lpServiceName + 1) + 46);
    v8 = (wchar_t *)malloc(2 * (_DWORD)hService);
    swprintf_s(v8, (size_t)hService, L"System\\CurrentControlSet\\Services\\%s", lpServiceName);
    if ( !RegOpenKeyExW(HKEY_LOCAL_MACHINE, v8, 0, 0x20019u, &phkResult) )
    {
      v2 = PE_LoadEnvKey(phkResult, L"ServiceDll");
      if ( !v2 )
      {
        RegCloseKey(phkResult);
        swprintf_s(v8, (size_t)hService, L"System\\CurrentControlSet\\Services\\%s\\Parameters", lpServiceName);
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
    result = (WCHAR *)OpenServiceW(ghSCManagerHandle, lpServiceName, 5u);
    hService = result;
    if ( !result )
      return result;
    QueryServiceConfigW(result, 0, 0, &pcbBytesNeeded);
    v10 = pcbBytesNeeded;
    v19 = (struct _QUERY_SERVICE_CONFIGW *)malloc(pcbBytesNeeded);
    v11 = v10;
    v12 = hService;
    QueryServiceConfigW(hService, v19, v11, &pcbBytesNeeded);
    CloseServiceHandle(v12);
    v8 = (wchar_t *)v19;
    v13 = ExpandEnvironmentStringsW(v19->lpBinaryPathName, 0, 0);
    v14 = v13;
    if ( v13 )
    {
      v2 = (WCHAR *)malloc(2 * v13);
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
      v17 = (WCHAR *)malloc(2 * v15);
      SearchPathW(0, v2, 0, v16, v17, &FilePart);
      _wcslwr_s(v17, v16);
      free(v2);
      v2 = v17;
    }
  }
  return v2;
}

//----- (00C34990) --------------------------------------------------------
wchar_t *__cdecl sub_C34990(int a1)
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
  _bstr_t bstrRet; // [esp+84h] [ebp-38h]
  int v45; // [esp+88h] [ebp-34h]
  _bstr_t v46; // [esp+8Ch] [ebp-30h]
  OLECHAR *v47; // [esp+90h] [ebp-2Ch]
  _bstr_t v48; // [esp+94h] [ebp-28h]
  _bstr_t v49; // [esp+98h] [ebp-24h]
  _bstr_t v50; // [esp+9Ch] [ebp-20h]
  _bstr_t v51; // [esp+A0h] [ebp-1Ch]
  int v52; // [esp+A4h] [ebp-18h]
  _bstr_t a3; // [esp+A8h] [ebp-14h]
  _bstr_t *v54; // [esp+ACh] [ebp-10h]
  LPVOID ppv; // [esp+B0h] [ebp-Ch]
  _bstr_t *v56; // [esp+B4h] [ebp-8h]
  _bstr_t v57; // [esp+B8h] [ebp-4h]

  v1 = 0;
  v2 = 0;
  ppv = 0;
  v57.m_Data = 0;
  if ( CoCreateInstance(&rclsid, 0, 1u, &CLSID_ITaskService, &ppv) >= 0 )
  {
    VariantInit(&pvarg);
    _mm_storeu_si128((__m128i *)&v37, _mm_loadu_si128((const __m128i *)&pvarg));
    VariantInit(&v39);
    _mm_storeu_si128((__m128i *)&v36, _mm_loadu_si128((const __m128i *)&v39));
    VariantInit(&v38);
    _mm_storeu_si128((__m128i *)&v35, _mm_loadu_si128((const __m128i *)&v38));
    VariantInit(&v41);
    v3 = ppv;
    v4 = *(_DWORD *)ppv;
    _mm_storeu_si128((__m128i *)&v31, _mm_loadu_si128((const __m128i *)&v37));
    _mm_storeu_si128((__m128i *)&v27, _mm_loadu_si128((const __m128i *)&v36));
    _mm_storeu_si128((__m128i *)&v23, _mm_loadu_si128((const __m128i *)&v35));
    _mm_storeu_si128((__m128i *)&v19, _mm_loadu_si128((const __m128i *)&v41));
    v5 = (*(int (__stdcall **)(LPVOID, int, int, int, int, int, int, int, int, int, int, int, int, int, LPVOID, _bstr_t *, int *))(v4 + 40))(
           v3,
           v19,
           v20,
           v21,
           v22,
           v23,
           v24,
           v25,
           v26,
           v27,
           v28,
           v29,
           v30,
           v31,
           v32,
           v33,
           v34);
    VariantClear(&v41);
    VariantClear(&v38);
    VariantClear(&v39);
    VariantClear(&pvarg);
    if ( v5 >= 0 )
    {
      v34 = (int *)&v56;
      v56 = 0;
      v33 = (_bstr_t *)1;
      v6 = *(_DWORD *)ppv;
      v32 = ppv;
      if ( (*(int (__stdcall **)(LPVOID, signed int, _bstr_t **))(v6 + 32))(ppv, 1, &v56) >= 0 )
      {
        v34 = &v52;
        v33 = v56;
        ((void (__stdcall *)(_bstr_t *, int *))v56->m_Data[2].m_str)(v56, &v52);
        for ( i = 1; i < v52 + 1; ++i )
        {
          v41.vt = 3;
          v34 = (int *)&v54;
          v41.lVal = i;
          v8 = _mm_loadu_si128((const __m128i *)&v41);
          v9.m_Data = v56->m_Data;
          v29 = (int)v56;
          _mm_storeu_si128((__m128i *)&v30, v8);
          v10 = ((int (__stdcall *)(int, int, int, LPVOID, _bstr_t *, int *))v9.m_Data[2].m_RefCount)(
                  v29,
                  v30,
                  v31,
                  v32,
                  v33,
                  v34);
          VariantClear(&v41);
          if ( v10 >= 0 )
          {
            v34 = &v45;
            v33 = v54;
            if ( ((int (__stdcall *)(_bstr_t *, int *))v54->m_Data[4].m_RefCount)(v54, &v45) >= 0 && v45 == a1 )
            {
              v34 = (int *)&psz;
              v33 = v54;
              if ( ((int (__stdcall *)(_bstr_t *, OLECHAR **))v54->m_Data[3].m_RefCount)(v54, &psz) >= 0 )
              {
                if ( v2 )
                {
                  if ( v2->m_wstr )
                  {
                    v34 = (int *)v2->m_wstr;
                    if ( SysStringLen((BSTR)v34) )
                    {
                      v11 = (_bstr_t *)_bstr_t::_bstr_t((tagEventSetItem *)&v48, L"\n");
                      v12 = _bstr_t::operator+(&v57, &bstrRet, v11);
                      _bstr_t::operator=(&v57, v12);
                      _bstr_t::_Free(&bstrRet);
                      _bstr_t::_Free(&v48);
                    }
                  }
                }
                v13 = (_bstr_t *)_bstr_t::_bstr_t((tagEventSetItem *)&v51, psz);
                v14 = _bstr_t::operator+(&a1a, L"   ", v13);
                _bstr_t::operator+=(&v57, v14);
                _bstr_t::_Free(&a1a);
                _bstr_t::_Free(&v51);
                v34 = (int *)&v47;
                v33 = v54;
                if ( ((int (__stdcall *)(_bstr_t *, OLECHAR **))v54->m_Data[3].m_wstr)(v54, &v47) >= 0 )
                {
                  _bstr_t::_bstr_t((tagEventSetItem *)&a3, L"]");
                  v34 = (int *)&a3;
                  v33 = &v46;
                  v15 = (_bstr_t *)_bstr_t::_bstr_t((tagEventSetItem *)&v49, v47);
                  v16 = _bstr_t::operator+(&v50, L" [", v15);
                  v17 = _bstr_t::operator+(v16, v33, (_bstr_t *)v34);
                  _bstr_t::operator+=(&v57, v17);
                  _bstr_t::_Free(&v46);
                  _bstr_t::_Free(&v50);
                  _bstr_t::_Free(&v49);
                  _bstr_t::_Free(&a3);
                }
                v2 = v57.m_Data;
              }
            }
            v34 = (int *)v54;
            ((void (__stdcall *)(_bstr_t *))v54->m_Data->m_RefCount)(v54);
          }
        }
        v34 = (int *)v56;
        ((void (__stdcall *)(_bstr_t *))v56->m_Data->m_RefCount)(v56);
        v1 = 0;
      }
    }
    v34 = (int *)ppv;
    (*(void (__stdcall **)(LPVOID))(*(_DWORD *)ppv + 8))(ppv);
    if ( v2 )
    {
      if ( v2->m_wstr )
      {
        v34 = (int *)v2->m_wstr;
        if ( SysStringLen((BSTR)v34) )
        {
          v34 = (int *)v2->m_wstr;
          v1 = _wcsdup((const wchar_t *)v34);
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
          operator delete[](v2->m_str);
          v2->m_str = 0;
        }
        operator delete(v2);
      }
    }
  }
  return v1;
}

//----- (00C34CC0) --------------------------------------------------------
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

//----- (00C34D80) --------------------------------------------------------
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
  v47 = (unsigned int)&v48 ^ __security_cookie;
  v29 = a2;
  if ( gdwVersion < 1 )
  {
    v11 = RegOpenKeyExW(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Run", 0, 1u, &v41);
    if ( !v11 )
    {
      v38 = 520;
      v11 = RegQueryValueExW(v41, L"Process Explorer", 0, (LPDWORD)&v37, (LPBYTE)&v46, (LPDWORD)&v38);
      RegCloseKey(v41);
    }
    return v11 == 0;
  }
  sub_C326B0(&v44);
  v43 = 0;
  if ( CoCreateInstance(&CLSID_ITaskService_1, 0, 1u, &CLSID_ITaskService_0, (LPVOID *)&v43) >= 0 )
  {
    VariantInit((VARIANTARG *)&v35);
    _mm_store_si128((__m128i *)&v31, _mm_load_si128((const __m128i *)&v35));
    VariantInit((VARIANTARG *)&v34);
    _mm_store_si128((__m128i *)&v32, _mm_load_si128((const __m128i *)&v34));
    VariantInit((VARIANTARG *)&v33);
    _mm_store_si128((__m128i *)&v30, _mm_load_si128((const __m128i *)&v33));
    VariantInit((VARIANTARG *)&v36);
    v2 = v43;
    v3 = *v43;
    _mm_storeu_si128((__m128i *)&v25, _mm_load_si128((const __m128i *)&v31));
    _mm_storeu_si128((__m128i *)&v21, _mm_load_si128((const __m128i *)&v32));
    _mm_storeu_si128((__m128i *)&v17, _mm_load_si128((const __m128i *)&v30));
    _mm_storeu_si128((__m128i *)&v13, _mm_loadu_si128((const __m128i *)&v36));
    v4 = (*(int (__stdcall **)(_DWORD *, int, int, int, int, int, int, int, int, int, int, int, int, int, int, _DWORD *, BSTR, _DWORD *))(v3 + 40))(
           v2,
           v13,
           v14,
           v15,
           v16,
           v17,
           v18,
           v19,
           v20,
           v21,
           v22,
           v23,
           v24,
           v25,
           v26,
           v27,
           v28,
           v29);
    VariantClear((VARIANTARG *)&v36);
    VariantClear((VARIANTARG *)&v33);
    VariantClear((VARIANTARG *)&v34);
    VariantClear((VARIANTARG *)&v35);
    if ( v4 >= 0 )
    {
      v40 = 0;
      v5 = *_bstr_t::_bstr_t((tagEventSetItem *)&v42, L"\\");
      v6 = (OLECHAR *)(v5 ? *v5 : 0);
      v29 = &v40;
      v28 = v6;
      v27 = v43;
      v7 = (*(int (__stdcall **)(_DWORD *, OLECHAR *, _DWORD **))(*v43 + 28))(v43, v6, &v40);
      _bstr_t::_Free((_bstr_t *)&v42);
      if ( v7 >= 0 )
      {
        v8 = (OLECHAR *)&v44;
        if ( v45 >= 8 )
          v8 = v44;
        v9 = _bstr_t::_bstr_t((tagEventSetItem *)&v42, v8);
        if ( *v9 )
          v10 = **v9;
        else
          v10 = 0;
        v29 = &v39;
        v28 = v10;
        v27 = v40;
        v11 = (*(int (__stdcall **)(_DWORD *, BSTR, _DWORD **))(*v40 + 52))(v40, v10, &v39);
        _bstr_t::_Free((_bstr_t *)&v42);
        if ( !v11 )
        {
          v29 = v39;
          (*(void (__stdcall **)(_DWORD *))(*v39 + 8))(v39);
        }
        v29 = v43;
        (*(void (__cdecl **)(_DWORD *))(*v43 + 8))(v43);
        sub_BE3820((int)&v44);
        return v11 == 0;
      }
    }
    v29 = v43;
    (*(void (__cdecl **)(_DWORD *))(*v43 + 8))(v43);
  }
  if ( v45 >= 8 )
    operator delete(v44);
  return 0;
}
// C34D80: could not find valid save-restore pair for ebp
// C34D80: could not find valid save-restore pair for edi
// CD4E54: using guessed type int gdwVersion;

//----- (00C35050) --------------------------------------------------------
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
  *(_QWORD *)&VersionInfo.dwMinorVersion = 0i64;
  VersionInfo.dwPlatformID = 0;
  return ((int (__stdcall *)(DLLVERSIONINFO *))DllGetVersion)(&VersionInfo) >= 0 && VersionInfo.dwMajorVersion >= 6;// Windows XP
}

//----- (00C350E0) --------------------------------------------------------
char __cdecl sub_C350E0(wchar_t *a1)
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

//----- (00C35120) --------------------------------------------------------
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

//----- (00C35150) --------------------------------------------------------
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
    if ( !RegQueryValueExW(phkResult, L"Debugger", 0, 0, (LPBYTE)Data, &cbData) )
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

//----- (00C352B0) --------------------------------------------------------
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
  if ( (unsigned __int8)dwVersion <= 4u )
    return IsServer(L"Terminal Server");
  if ( (unsigned __int8)dwVersion >= 5u && dwVersion >> 16 > 0x893 )
    return 1;
  v4 = GetModuleHandleW(L"ntdll.dll");
  if ( !v4 )
    return 0;
  VerSetConditionMask = (ULONGLONG *)GetProcAddress(v4, "VerSetConditionMask");
  if ( !VerSetConditionMask )
    return 0;
  // NTSYSAPI ULONGLONG VerSetConditionMask(
  //   ULONGLONG ConditionMask,
  //   DWORD     TypeMask,
  //   BYTE      Condition
  // );
  ((void (__stdcall *)(_DWORD, _DWORD, MACRO_VER_EQUAL, MACRO_VER_EQUAL, int, int))VerSetConditionMask)(
    0,
    0,
    VER_SUITENAME,
    VER_AND,
    a1,
    a2);
  v6 = GetModuleHandleW(L"KERNEL32.DLL");
  if ( !v6 )
    return 0;
  VerifyVersionInfoA = (BOOL)GetProcAddress(v6, "VerifyVersionInfoA");
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
  return ((int (__stdcall *)(_OSVERSIONINFOEXA *, MACRO_VER_EQUAL))VerifyVersionInfoA)(&VerInfo, VER_SUITENAME);
}
// C352B0: could not find valid save-restore pair for esi

//----- (00C353F0) --------------------------------------------------------
BOOL __cdecl CMainWnd::Hide(HWND hWnd)
{
  BOOL result; // eax

  result = ShowWindow(hWnd, 0);
  gbMainWndMinimized = 1;
  return result;
}
// CDA389: using guessed type char gbMainWndMinimized;

//----- (00C35420) --------------------------------------------------------
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
  v28 = (char *)malloc(24 * v27);
  v29 = 0;
  v30 = v28;
  if ( v27 )
  {
    v31 = (int)(v28 + 8);
    do
    {
      v32 = dwMaskBuf[2 * v29 + 1];
      v31 += 24;
      ++v29;
      *(_DWORD *)(v31 - 28) = 0;
      *(_BYTE *)(v31 - 24) = 1;
      *(_DWORD *)(v31 - 32) = v32;
    }
    while ( v29 < v27 );
  }
  return v30;
}

//----- (00C35670) --------------------------------------------------------
BOOL __cdecl PE_SetWindowPlacement(HWND hWnd, POINT pt)
{
  LONG left; // esi
  LONG top; // edi
  int v4; // eax
  LONG bottom; // ecx
  int v6; // eax
  int v7; // eax
  WINDOWPLACEMENT wp; // [esp+10h] [ebp-40h]
  LONG v10; // [esp+2Ch] [ebp-24h]
  LONG v11; // [esp+30h] [ebp-20h]
  int v12; // [esp+34h] [ebp-1Ch]
  int v13; // [esp+38h] [ebp-18h]
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
  v12 = left + rcClient.right;
  v13 = bottom + top;
  v10 = left;
  v11 = top;
  return SetWindowPlacement(hWnd, &wp);
}

//----- (00C35750) --------------------------------------------------------
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
      wcscat_s((wchar_t *)Data, 0x104u, L"\\shell\\open\\command");
      if ( RegOpenKeyExW(HKEY_CLASSES_ROOT, (LPCWSTR)Data, 0, 0x20019u, &phkResult) )
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
    SizeInWords = wcslen((const unsigned __int16 *)Data) + wcslen(lpszURL) + 6;
    pszParameters = (wchar_t *)malloc(2 * SizeInWords);
    Dst = pszParameters;
    pszFile = (OLECHAR *)Data;
    if ( *(_WORD *)Data == 34 )
    {
      strcpy((char *)Data, "\"");
      pszFile = &v19;
      v6 = wcschr(&v19, '"');
    }
    else
    {
      v6 = wcschr((const wchar_t *)Data, ' ');
    }
    v7 = v6;
    if ( v6 )
    {
      *v6 = 0;
      v7 = v6 + 1;
    }
    if ( flags )
    {
      v8 = wcsstr((const wchar_t *)Data, L"\"%1\"");
      hWnda = (HWND)v8;
      if ( v8 )
      {
        v9 = v8 - v7;
        wcsncpy_s(Dst, SizeInWords, v7, v9 + 1);
        wcscpy_s(&Dst[v9 + 1], SizeInWords - v9 - 1, L"? ");
        pszParameters = Dst;
        wcscat_s(Dst, SizeInWords, lpszURL);
        wcscat_s(Dst, SizeInWords, (const wchar_t *)hWnda + 3);
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
        *(LPCWSTR)((char *)v3 + (char *)pszParameters - (char *)lpszURL - 2) = v10;
      }
      while ( v10 );
    }
    PE_ShellExecute(pszFile, pszParameters, 0);
    free(pszParameters);
    result = 1;
  }
  return result;
}

//----- (00C35A60) --------------------------------------------------------
int __cdecl sub_C35A60(const void *a1, const void *a2)
{
  return _stricmp(*(const char **)a1, *(const char **)a2);
}

//----- (00C35A80) --------------------------------------------------------
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
  v0 = (WCHAR **)malloc(4u);
  gpHiddenProcesses = v0;
  *v0 = 0;
  result = RegOpenKeyExW(HKEY_CURRENT_USER, L"Software\\Sysinternals\\Process Explorer", 0, KEY_READ, &hKey);
  if ( !result )
  {
    if ( !RegQueryValueExW(hKey, L"HiddenProcs", 0, &Type, 0, &cbData) )
    {
      v2 = (BYTE *)malloc(cbData);
      RegQueryValueExW(hKey, L"HiddenProcs", 0, &Type, v2, &cbData);
      v3 = (const wchar_t *)v2;
      if ( v2 < &v2[2 * cbData] )
      {
        v4 = 0;
        do
        {
          if ( !*v3 )
            break;
          gpHiddenProcesses = (WCHAR **)realloc(gpHiddenProcesses, v4 * 4 + 8);
          gpHiddenProcesses[v4] = _wcsdup(v3);
          v5 = gpHiddenProcesses[v4];
          v7 = (int)(v5 + 1);
          do
          {
            v6 = *v5;
            ++v5;
          }
          while ( v6 );
          gpHiddenProcesses[v4 + 1] = 0;
          ++v4;
          v3 += (((signed int)v5 - v7) >> 1) + 1;
        }
        while ( v3 < (const wchar_t *)&v2[2 * cbData] );
      }
    }
    result = RegCloseKey(hKey);
  }
  return result;
}

//----- (00C35BA0) --------------------------------------------------------
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
        gpProcessComments = (tagProcessComment *)realloc(gpProcessComments, 8 * v0 + 16);
        gpProcessComments[v0].pszName = _wcsdup(&ValueName);
        gpProcessComments[v0].pszComment = (LPBYTE)malloc(cbData);
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

//----- (00C35D10) --------------------------------------------------------
char __cdecl ReplaceTaskManager(HWND a1, char a2)
{
  DWORD v2; // eax
  DWORD v3; // esi
  char result; // al
  HKEY phkResult; // [esp+0h] [ebp-418h]
  BYTE Data[2]; // [esp+4h] [ebp-414h]
  char v7; // [esp+6h] [ebp-412h]

  *(_WORD *)Data = 0;
  memset(&v7, 0, 0x40Eu);
  sub_C32850((wchar_t *)Data, 0x208u);
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
    v3 = RegSetValueExW(phkResult, L"Debugger", 0, 1u, Data, 2 * wcslen((const unsigned __int16 *)Data) + 2);
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

//----- (00C35E40) --------------------------------------------------------
char __thiscall sub_C35E40(HKEY this)
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

//----- (00C35EB0) --------------------------------------------------------
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
  _mm_storeu_si128((__m128i *)&ProcessInformation, (__m128i)0i64);
  result = GetModuleFileNameW(0, &szFileName, 0x103u);
  if ( result )
  {
    if ( !RegCreateKeyW(HKEY_CURRENT_USER, L"Software\\Sysinternals\\Process Explorer", &hSubKey) )
    {
      RegSetValueExW(hSubKey, L"OriginalPath", 0, 1u, (const BYTE *)&szFileName, 2 * wcslen(&szFileName));
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
    if ( !CDriver::SaveDriverFromResource((LPCWSTR)v3, &szFileName) && GetFileAttributesW(&szFileName) == -1 )
      return 0;
    if ( !RegOpenKeyW(HKEY_CURRENT_USER, L"Software\\Sysinternals\\Process Explorer", &hSubKey) )
    {
      RegSetValueExW(hSubKey, L"Path", 0, 1u, (const BYTE *)&szFileName, 2 * wcslen(&szFileName));
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

//----- (00C36180) --------------------------------------------------------
DWORD __cdecl sub_C36180(const WCHAR *a1, int a2, char a3)
{
  SHELLEXECUTEINFOW pExecInfo; // [esp+4h] [ebp-450h]
  wchar_t Dst; // [esp+40h] [ebp-414h]

  sub_C32850(&Dst, 0x208u);
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

//----- (00C36260) --------------------------------------------------------
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
    ((void (__stdcall *)(HANDLE, int *))v1)(v2, &v4);
  }
  return v4;
}

//----- (00C362A0) --------------------------------------------------------
LSTATUS __cdecl sub_C362A0(int a1, wchar_t *a2)
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
  v3 = *(const wchar_t **)(a1 + 792);
  v4 = 0;
  if ( !v3 )
    v3 = *(const wchar_t **)(a1 + 60);
  v5 = gpTreeViewListItemParam;
  if ( gpTreeViewListItemParam )
  {
    do
    {
      if ( *(_DWORD *)(v2 + 792) && (v6 = v5->szProcessName) != 0 && !_wcsicmp(v6, v3)
        || (v7 = v5->szProcessName2) != 0 && !_wcsicmp(v7, v3) )
      {
        free((void *)v5->pszComments);
        v5->pszComments = (int)(*a2 ? _wcsdup(a2) : 0);
        lParam = 1;
        v16 = v5;
        v8 = SendMessageW(ghWndTreeListView, 0x1053u, 0xFFFFFFFF, (LPARAM)&lParam);
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
    gpProcessComments[v4].pszComment = (LPBYTE)_wcsdup(a2);
    v9 = gpProcessComments;
  }
LABEL_23:
  if ( !v9 )
    goto LABEL_33;
  v11 = v4;
  if ( !v9[v4].pszName )
  {
LABEL_33:
    gpProcessComments = (tagProcessComment *)realloc(v9, 8 * v4 + 16);
    v11 = v4;
    gpProcessComments[v11].pszName = _wcsdup(v3);
    gpProcessComments[v11].pszComment = (LPBYTE)_wcsdup(a2);
    gpProcessComments[v11 + 1].pszName = 0;
  }
  result = RegCreateKeyW(HKEY_CURRENT_USER, L"Software\\Sysinternals\\Process Explorer\\ProcessComments", &phkResult);
  if ( !result )
  {
    v13 = &gpProcessComments[v11];
    v14 = gpProcessComments[v11].pszComment;
    if ( *(_WORD *)v14 )
      RegSetValueExW(phkResult, v13->pszName, 0, 1u, v14, 2 * wcslen((const unsigned __int16 *)v14) + 2);
    else
      RegDeleteValueW(phkResult, v13->pszName);
    result = RegCloseKey(phkResult);
  }
  return result;
}

//----- (00C364C0) --------------------------------------------------------
char __cdecl sub_C364C0(HWND hWnd, LPCWSTR lpFileName)
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
  if ( v2 == (HANDLE)-1 )
  {
    lParam = 5;
    v6 = 0x7FFFFFFF;
    v7 = L"<Error opening file>";
    v8 = 1;
    SendMessageW(hWnd, 0x104Du, 0, (LPARAM)&lParam);
    result = 0;
  }
  else
  {
    v4 = (HCURSOR)ghWaitCursor;
    if ( !ghWaitCursor )
    {
      v4 = LoadCursorW(ghWaitCursor, (LPCWSTR)0x7F02);
      ghWaitCursor = (HINSTANCE)v4;
    }
    hCursor = SetCursor(v4);
    while ( ReadFile(v2, &Buffer, 0x10008u, &NumberOfBytesRead, 0) )
    {
      if ( !NumberOfBytesRead )
        break;
      WriteStringToList(hWnd, 3u, (int)&Buffer, NumberOfBytesRead);
      if ( NumberOfBytesRead == 65544 )
        SetFilePointer(v2, -2, 0, 1u);
    }
    CloseHandle(v2);
    SetCursor(hCursor);
    result = 1;
  }
  return result;
}
// CAEBF4: using guessed type wchar_t aErrorOpeningFi[21];

//----- (00C36620) --------------------------------------------------------
HCURSOR __cdecl LoadStringToList(HWND hWnd, HANDLE ProcessHandle, LPCVOID lpBaseAddress, DWORD dwSize)
{
  HCURSOR v4; // eax
  char *pAddress; // edi
  DWORD v6; // esi
  SIZE_T dwLength; // ecx
  HCURSOR hCursor; // [esp+Ch] [ebp-10010h]
  SIZE_T dwRet; // [esp+14h] [ebp-10008h]
  char Buffer[65536]; // [esp+18h] [ebp-10004h]

  v4 = (HCURSOR)ghWaitCursor;
  pAddress = (char *)lpBaseAddress;
  if ( !ghWaitCursor )
  {
    v4 = LoadCursorW(ghWaitCursor, (LPCWSTR)IDC_WAIT);
    ghWaitCursor = (HINSTANCE)v4;
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
    WriteStringToList(hWnd, 3u, (int)Buffer, dwRet);
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

//----- (00C36710) --------------------------------------------------------
int __cdecl PE_FillControl(int a1, HDC hdc)
{
  if ( !ghBlackBrush )
    ghBlackBrush = (int)CreateSolidBrush(0xFFFFFFu);
  SetBkColor(hdc, 0xFFFFFFu);
  return ghBlackBrush;
}
// CD9E8C: using guessed type int ghBlackBrush;

//----- (00C36750) --------------------------------------------------------
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
  QueryIn = (TAG_INFO_NAME_TAG_MAPPING *)pdwValue2;
  pValue = 0;
  result = I_QueryTagInformation(0, ServiceNameTagMappingInformation, (_SC_SERVICE_TAG_QUERY *)&QueryIn);
  if ( !result )
  {
    v5 = pValue;
    *pdwValue3 = *pValue;
    *pdwValue4 = v5[1];
    *ppv = v5;
  }
  return result;
}

//----- (00C367B0) --------------------------------------------------------
BOOL __cdecl TrayIcon_Add(HWND hWnd, UINT nID, CGraphData *pGraphData, LPCWSTR lpszTipText)
{
  HICON v4; // edi
  BOOL v5; // esi
  struct _NOTIFYICONDATAW Data; // [esp+14h] [ebp-3CCh]
  int rc; // [esp+3CCh] [ebp-14h]

  _mm_storeu_si128((__m128i *)&rc, _mm_load_si128((const __m128i *)&xmmword_CAF270));
  memset(&Data, 0, 0x3B8u);
  Data.uID = nID;
  Data.cbSize = 952;
  Data.hWnd = hWnd;
  Data.uFlags = 7;
  Data.uCallbackMessage = WM_NOTIFY_TRAYICON;
  v4 = GraphData_DrawChart(pGraphData, 0, (#153 *)&rc, gConfig.ColorGraphBk, 0, 0.0);
  Data.hIcon = v4;
  if ( lpszTipText )
    wcsncpy_s(Data.szTip, 0x80u, lpszTipText, 0xFFFFFFFF);
  else
    Data.szTip[0] = 0;
  v5 = Shell_NotifyIconW(NIM_ADD, &Data);
  DestroyIcon(v4);
  return v5;
}
// CAF270: using guessed type __int128 xmmword_CAF270;

//----- (00C368A0) --------------------------------------------------------
BOOL __cdecl TrayIcon_Delete(HWND hWnd, UINT nID)
{
  struct _NOTIFYICONDATAW Data; // [esp+4h] [ebp-3BCh]

  memset(&Data, 0, 952u);
  Data.uID = nID;
  Data.cbSize = 952;
  Data.hWnd = hWnd;
  return Shell_NotifyIconW(NIM_DELETE, &Data);
}

//----- (00C36910) --------------------------------------------------------
BOOL __cdecl sub_C36910(int a1, int a2, int a3, wchar_t *Src)
{
  struct _NOTIFYICONDATAW Data; // [esp+Ch] [ebp-3BCh]

  wcscpy_s(&Dst, 0x100u, Src);
  memset(&Data, 0, 0x3B8u);
  Data.cbSize = 952;
  Data.hWnd = (HWND)a1;
  Data.uID = a2;
  Data.uFlags = 6;
  Data.hIcon = (HICON)a3;
  if ( Src )
    wcsncpy_s(Data.szTip, 0x80u, Src, 0xFFFFFFFF);
  else
    Data.szTip[0] = 0;
  return Shell_NotifyIconW(1u, &Data);
}

//----- (00C369D0) --------------------------------------------------------
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
      if ( sub_C71C10(pItemParam->m_ItemDataForVirusTotal) )
        v1 = 1;
    }
  }
  v8 = GetMenu(ghMainWnd);
  return EnableMenuItem(v8, IDM_PROCESS_CHECK_VIRUSTOTALDOTCOM, v1 == 0);
}
// CAE374: using guessed type wchar_t aCheckVirustota[18];

//----- (00C36A70) --------------------------------------------------------
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

//----- (00C36B90) --------------------------------------------------------
bool __cdecl sub_C36B90(HWND hWnd, int a2, int a3)
{
  HWND v3; // esi
  HMODULE v5; // eax
  FARPROC v6; // eax
  HWND v7; // ecx

  v3 = QueryTopMostWindowByProcessID(a3);
  if ( !v3 )
  {
    v7 = ghMainWnd;
    if ( hWnd )
      v7 = hWnd;
    MessageBoxW(v7, L"No visible windows found for this process", L"Process Explorer Warning", 0x30u);
    return v3 != 0;
  }
  if ( (signed int)(unsigned __int16)a2 <= 40638 )
  {
    if ( (unsigned __int16)a2 == 40638 )
    {
      ShowWindowAsync(v3, 6);
      return v3 != 0;
    }
    if ( (unsigned __int16)a2 == 40084 )
    {
      if ( IsIconic(v3) )
        ShowWindowAsync(v3, 9);
      SetForegroundWindow(v3);
      return v3 != 0;
    }
    return v3 != 0;
  }
  if ( (unsigned __int16)a2 == 40639 )
  {
    ShowWindowAsync(v3, 3);
    return v3 != 0;
  }
  if ( (unsigned __int16)a2 != 40640 )
  {
    if ( (unsigned __int16)a2 == 40641 )
    {
      ShowWindowAsync(v3, 9);
      return v3 != 0;
    }
    return v3 != 0;
  }
  v5 = GetModuleHandleW(L"user32.dll");
  v6 = GetProcAddress(v5, "EndTask");
  if ( v6 )
    ((void (__stdcall *)(HWND, _DWORD, _DWORD))v6)(v3, 0, 0);
  else
    PostMessageW(v3, 0x10u, 0, 0);
  return v3 != 0;
}

//----- (00C36C90) --------------------------------------------------------
LSTATUS SaveHiddenProcessesToRegistry()
{
  int v0; // ebx
  int nIndex; // esi
  LSTATUS result; // eax
  WCHAR **ppHiddenProcesses; // edi
  WCHAR **ppHiddenProcesses_1; // eax
  WCHAR *pHiddenProcesses; // eax
  WCHAR *v6; // edx
  WCHAR chText; // cx
  rsize_t nLength; // ebx
  wchar_t *v9; // eax
  int item; // esi
  int nIndex_1; // edx
  WCHAR *pHiddenProcesses_1; // ecx
  int v13; // esi
  WCHAR v14; // ax
  int nLength_1; // ecx
  BYTE *lpData; // [esp+8h] [ebp-14h]
  wchar_t *v17; // [esp+10h] [ebp-Ch]
  int nIndex_2; // [esp+14h] [ebp-8h]
  HKEY hSubKey; // [esp+18h] [ebp-4h]

  v0 = 0;
  nIndex = 0;
  result = RegCreateKeyW(HKEY_CURRENT_USER, L"Software\\Sysinternals\\Process Explorer", &hSubKey);
  if ( !result )
  {
    ppHiddenProcesses = gpHiddenProcesses;
    if ( *gpHiddenProcesses )
    {
      ppHiddenProcesses_1 = gpHiddenProcesses;
      do
      {
        pHiddenProcesses = *ppHiddenProcesses_1;
        ++nIndex;
        v6 = pHiddenProcesses + 1;
        do
        {
          chText = *pHiddenProcesses;
          ++pHiddenProcesses;
        }
        while ( chText );
        v0 += pHiddenProcesses - v6 + 1;
        ppHiddenProcesses_1 = &gpHiddenProcesses[nIndex];
      }
      while ( gpHiddenProcesses[nIndex] );
    }
    nLength = v0 + 1;
    if ( nIndex )
    {
      v9 = (wchar_t *)malloc(2 * nLength);
      lpData = (BYTE *)v9;
      nIndex_2 = 0;
      v17 = v9;
      if ( *ppHiddenProcesses )
      {
        item = 0;
        do
        {
          wcscpy_s(v9, nLength, *ppHiddenProcesses);
          nIndex_1 = nIndex_2++ + 1;
          pHiddenProcesses_1 = gpHiddenProcesses[item];
          v13 = (int)(pHiddenProcesses_1 + 1);
          do
          {
            v14 = *pHiddenProcesses_1;
            ++pHiddenProcesses_1;
          }
          while ( v14 );
          nLength_1 = ((signed int)pHiddenProcesses_1 - v13) >> 1;
          item = nIndex_1;
          ppHiddenProcesses = &gpHiddenProcesses[nIndex_1];
          v9 = &v17[nLength_1 + 1];
          v17 += nLength_1 + 1;
        }
        while ( *ppHiddenProcesses );
      }
      *v9 = 0;
      RegSetValueExW(hSubKey, L"HiddenProcs", 0, REG_MULTI_SZ, lpData, 2 * nLength);
      result = RegCloseKey(hSubKey);
    }
    else
    {
      RegDeleteValueW(hSubKey, L"HiddenProcs");
      result = RegCloseKey(hSubKey);
    }
  }
  return result;
}

//----- (00C36DB0) --------------------------------------------------------
HANDLE __cdecl sub_C36DB0(HANDLE TokenHandle)
{
  DWORD v1; // esi
  unsigned int *v2; // ebx
  int v3; // edi
  unsigned int v4; // esi
  unsigned int *v5; // ecx
  unsigned int v6; // eax
  const __m128i *v7; // esi
  unsigned int v8; // edi
  unsigned int v9; // edx
  _DWORD *v10; // eax
  char *v11; // edx
  void *v12; // ebx
  HMODULE v13; // eax
  FARPROC v14; // eax
  DWORD v15; // eax
  DWORD v16; // esi
  DWORD v17; // eax
  DWORD v18; // esi
  ACL *v19; // edi
  ACL *v20; // ecx
  DWORD v21; // esi
  void *v22; // esi
  struct _SID_AND_ATTRIBUTES v24; // [esp+4h] [ebp-6Ch]
  LPVOID pAce; // [esp+Ch] [ebp-64h]
  PSECURITY_DESCRIPTOR ppSecurityDescriptor; // [esp+10h] [ebp-60h]
  ACL *v27; // [esp+14h] [ebp-5Ch]
  void *v28; // [esp+18h] [ebp-58h]
  PSID TokenInformation; // [esp+1Ch] [ebp-54h]
  int v30; // [esp+20h] [ebp-50h]
  DWORD TokenInformationLength; // [esp+24h] [ebp-4Ch]
  PSID hMem; // [esp+28h] [ebp-48h]
  PSID AccountSid; // [esp+2Ch] [ebp-44h]
  PSID pSid; // [esp+30h] [ebp-40h]
  void *v35; // [esp+34h] [ebp-3Ch]
  PACL ppDacl; // [esp+38h] [ebp-38h]
  unsigned int v37; // [esp+3Ch] [ebp-34h]
  DWORD ReturnLength; // [esp+40h] [ebp-30h]
  void *v39; // [esp+44h] [ebp-2Ch]
  HANDLE handle; // [esp+48h] [ebp-28h]
  struct _SID_IDENTIFIER_AUTHORITY pIdentifierAuthority; // [esp+4Ch] [ebp-24h]
  __int128 v42; // [esp+54h] [ebp-1Ch]
  __int64 v43; // [esp+64h] [ebp-Ch]

  _mm_storeu_si128((__m128i *)&v42, _mm_loadu_si128((const __m128i *)L"S-1-16-4096"));
  v28 = TokenHandle;
  *(_DWORD *)pIdentifierAuthority.Value = 0;
  *(_WORD *)&pIdentifierAuthority.Value[4] = 1280;
  pSid = 0;
  AccountSid = 0;
  handle = 0;
  v43 = *(_QWORD *)L"096";
  hMem = 0;
  TokenInformation = 0;
  v30 = 0;
  AllocateAndInitializeSid(&pIdentifierAuthority, 2u, 0x20u, 0x220u, 0, 0, 0, 0, 0, 0, &pSid);
  v24.Sid = pSid;
  v24.Attributes = 0;
  GetTokenInformation(TokenHandle, TokenPrivileges, 0, 0, &ReturnLength);
  v1 = ReturnLength;
  v35 = malloc(ReturnLength);
  GetTokenInformation(TokenHandle, TokenPrivileges, v35, v1, &ReturnLength);
  v39 = malloc(ReturnLength);
  *(_DWORD *)v39 = 0;
  AllocateAndInitializeSid(&pIdentifierAuthority, 2u, 0x20u, 0x221u, 0, 0, 0, 0, 0, 0, &AccountSid);
  v2 = sub_C37450(AccountSid);
  if ( !v2 )
  {
    v2 = (unsigned int *)malloc(0x4Cu);
    v3 = 0;
    v4 = 0;
    *v2 = 0;
    do
    {
      if ( LookupPrivilegeValueW(0, off_CCE0BC[v4], (PLUID)&v2[v3 + 1]) )
        ++*v2;
      ++v4;
      v3 += 3;
    }
    while ( v4 < 5 );
  }
  v5 = (unsigned int *)v35;
  v6 = 0;
  v37 = 0;
  if ( *(_DWORD *)v35 )
  {
    v7 = (const __m128i *)((char *)v35 + 4);
    do
    {
      v8 = *v2;
      v9 = 0;
      if ( *v2 )
      {
        v10 = v2 + 1;
        do
        {
          if ( v7->m128i_i32[0] == *v10 && v7->m128i_i32[1] == v10[1] )
            break;
          ++v9;
          v10 += 3;
        }
        while ( v9 < v8 );
        v6 = v37;
        v5 = (unsigned int *)v35;
      }
      if ( v9 == v8 )
      {
        v11 = (char *)v39 + 12 * *(_DWORD *)v39;
        v5 = (unsigned int *)v35;
        ++*(_DWORD *)v39;
        _mm_storel_epi64((__m128i *)(v11 + 4), _mm_loadl_epi64(v7));
        *((_DWORD *)v11 + 3) = v7->m128i_i32[2];
        v6 = v37;
      }
      ++v6;
      v7 = (const __m128i *)((char *)v7 + 12);
      v37 = v6;
    }
    while ( v6 < *v5 );
  }
  free(v5);
  free(v2);
  v12 = v39;
  if ( gpfnCreateRestrictedToken(
         v28,
         0,
         1u,
         &v24,
         *(_DWORD *)v39,
         (struct _LUID_AND_ATTRIBUTES *)((char *)v39 + 4),
         0,
         0,
         &handle) )
  {
    v13 = LoadLibraryW(L"Advapi32.dll");
    v14 = GetProcAddress(v13, "ConvertStringSidToSidA");
    *(_DWORD *)ConvertStringSidToSidA = v14;
    if ( v14 && ((int (__stdcall *)(__int128 *, PSID *))v14)(&v42, &hMem) )
    {
      v30 = 32;
      TokenInformation = hMem;
      v15 = GetLengthSid(hMem);
      SetTokenInformation(handle, TokenIntegrityLevel, &TokenInformation, v15 + 8);
      LocalFree(hMem);
    }
  }
  else
  {
    handle = 0;
  }
  GetTokenInformation(handle, TokenUser, 0, 0, &TokenInformationLength);
  v16 = TokenInformationLength;
  v39 = malloc(TokenInformationLength);
  GetTokenInformation(handle, TokenUser, v39, v16, &TokenInformationLength);
  GetSecurityInfo(handle, SE_KERNEL_OBJECT, 4u, 0, 0, &ppDacl, 0, &ppSecurityDescriptor);
  v17 = GetLengthSid(*(PSID *)v39);
  v18 = v17 + ppDacl->AclSize + 8;
  v19 = (ACL *)malloc(v17 + ppDacl->AclSize + 8);
  InitializeAcl(v19, v18, 2u);
  v20 = ppDacl;
  v21 = 0;
  if ( ppDacl->AceCount > 0u )
  {
    do
    {
      GetAce(v20, v21, &pAce);
      AddAce(v19, 2u, v21, pAce, *((unsigned __int16 *)pAce + 1));
      v20 = ppDacl;
      ++v21;
    }
    while ( v21 < ppDacl->AceCount );
  }
  v22 = v39;
  AddAccessAllowedAce(v19, 2u, 0x10000000u, *(PSID *)v39);
  SetSecurityInfo(handle, SE_KERNEL_OBJECT, 4u, 0, 0, v19, 0);
  v27 = v19;
  SetTokenInformation(handle, TokenDefaultDacl, &v27, v19->AclSize);
  free(v19);
  free(v22);
  LocalFree(ppSecurityDescriptor);
  FreeSid(pSid);
  FreeSid(AccountSid);
  free(v12);
  return handle;
}
// CAF37C: using guessed type wchar_t aS1164096[12];
// CCE0BC: using guessed type wchar_t *off_CCE0BC[5];
// CDA118: using guessed type int (__stdcall *gpfnCreateRestrictedToken)(void *, unsigned int, unsigned int, struct _SID_AND_ATTRIBUTES *, unsigned int, struct _LUID_AND_ATTRIBUTES *, unsigned int, struct _SID_AND_ATTRIBUTES *, void **);

//----- (00C37140) --------------------------------------------------------
BOOL __cdecl QueryCurrentAuthorityInfo(wchar_t **a1)
{
  HANDLE v1; // eax
  wchar_t *v2; // eax
  HANDLE TokenHandle; // [esp+4h] [ebp-80Ch]
  DWORD ReturnLength; // [esp+8h] [ebp-808h]
  void *TokenInformation; // [esp+Ch] [ebp-804h]

  v1 = GetCurrentProcess();
  OpenProcessToken(v1, 8u, &TokenHandle);
  ReturnLength = 2048;
  GetTokenInformation(TokenHandle, TokenUser, &TokenInformation, 0x800u, &ReturnLength);
  ReturnLength = 0;
  QueryAuthorityInfoFromSID(TokenInformation, *a1, (int)&ReturnLength);
  v2 = (wchar_t *)malloc(2 * ReturnLength);
  *a1 = v2;
  QueryAuthorityInfoFromSID(TokenInformation, v2, (int)&ReturnLength);
  return CloseHandle(TokenHandle);
}

//----- (00C37200) --------------------------------------------------------
BOOL __cdecl QueryAuthorityInfoFromSID(PSID pSid, wchar_t *Dst, int a3)
{
  BOOL result; // eax
  PSID_IDENTIFIER_AUTHORITY v4; // edi
  unsigned int v5; // ecx
  int v6; // eax
  int v7; // esi
  int v8; // eax
  DWORD v9; // edi
  int v10; // esi
  PDWORD v11; // eax
  DWORD v12; // [esp+4h] [ebp-4h]

  result = IsValidSid(pSid);
  if ( result )
  {
    v4 = GetSidIdentifierAuthority(pSid);
    v12 = *GetSidSubAuthorityCount(pSid);
    v5 = 12 * v12 + 28;
    if ( *(_DWORD *)a3 >= v5 )
    {
      v6 = swprintf_s(Dst, *(_DWORD *)a3, L"S-%lu-", 1);
      v7 = v6;
      if ( v4->Value[0] || v4->Value[1] )
        v8 = swprintf_s(
               &Dst[v6],
               *(_DWORD *)a3 - v6,
               L"0x%02hx%02hx%02hx%02hx%02hx%02hx",
               v4->Value[0],
               v4->Value[1],
               v4->Value[2],
               v4->Value[3],
               v4->Value[4],
               v4->Value[5]);
      else
        v8 = swprintf_s(
               &Dst[v6],
               *(_DWORD *)a3 - v6,
               L"%lu",
               v4->Value[5] + ((v4->Value[4] + ((v4->Value[3] + (v4->Value[2] << 8)) << 8)) << 8));
      v9 = 0;
      v10 = v8 + v7;
      if ( v12 )
      {
        do
        {
          v11 = GetSidSubAuthority(pSid, v9++);
          v10 += swprintf_s(&Dst[v10], *(_DWORD *)a3 - v10, L"-%lu", *v11);
        }
        while ( v9 < v12 );
      }
      result = 1;
    }
    else
    {
      *(_DWORD *)a3 = v5;
      SetLastError(0x7Au);
      result = 0;
    }
  }
  return result;
}

//----- (00C37330) --------------------------------------------------------
char IsBuiltinAdministrative()
{
  HANDLE v0; // eax
  DWORD v1; // esi
  unsigned int *v2; // ebx
  unsigned int v3; // edi
  bool v4; // zf
  _DWORD *v5; // esi
  DWORD ReturnLength; // [esp+0h] [ebp-18h]
  PSID pSid; // [esp+4h] [ebp-14h]
  HANDLE TokenHandle; // [esp+8h] [ebp-10h]
  struct _SID_IDENTIFIER_AUTHORITY pIdentifierAuthority; // [esp+Ch] [ebp-Ch]

  *(_DWORD *)pIdentifierAuthority.Value = 0;
  *(_WORD *)&pIdentifierAuthority.Value[4] = 1280;
  pSid = 0;
  if ( !byte_CDA094 )
  {
    v0 = GetCurrentProcess();
    OpenProcessToken(v0, 8u, &TokenHandle);
    AllocateAndInitializeSid(&pIdentifierAuthority, 2u, 0x20u, 0x220u, 0, 0, 0, 0, 0, 0, &pSid);
    GetTokenInformation(TokenHandle, TokenGroups, 0, 0, &ReturnLength);
    v1 = ReturnLength;
    v2 = (unsigned int *)malloc(ReturnLength);
    if ( GetTokenInformation(TokenHandle, TokenGroups, v2, v1, &ReturnLength) )
    {
      v3 = 0;
      v4 = *v2 == 0;
      if ( *v2 > 0 )
      {
        v5 = v2 + 2;
        do
        {
          if ( EqualSid(pSid, (PSID)*(v5 - 1)) && *v5 & 4 && *v5 & 0xFFFFFFEF )
            break;
          ++v3;
          v5 += 2;
        }
        while ( v3 < *v2 );
        v4 = v3 == *v2;
      }
      byte_CDA095 = !v4;
    }
    free(v2);
    FreeSid(pSid);
    CloseHandle(TokenHandle);
    byte_CDA094 = 1;
  }
  return byte_CDA095;
}
// CDA094: using guessed type char byte_CDA094;
// CDA095: using guessed type char byte_CDA095;

//----- (00C37450) --------------------------------------------------------
_DWORD *__cdecl sub_C37450(PSID AccountSid)
{
  _DWORD *v1; // ebx
  ULONG v2; // esi
  _DWORD *v3; // eax
  ULONG v4; // esi
  struct _LUID *v5; // edi
  struct _LSA_OBJECT_ATTRIBUTES ObjectAttributes; // [esp+4h] [ebp-24h]
  PVOID PolicyHandle; // [esp+1Ch] [ebp-Ch]
  PLSA_UNICODE_STRING UserRights; // [esp+20h] [ebp-8h]
  ULONG CountOfRights; // [esp+24h] [ebp-4h]

  *(_QWORD *)&ObjectAttributes.SecurityDescriptor = 0i64;
  v1 = 0;
  _mm_storeu_si128((__m128i *)&ObjectAttributes, (__m128i)0i64);
  if ( !LsaOpenPolicy(0, &ObjectAttributes, 0x800u, &PolicyHandle) )
  {
    if ( !LsaEnumerateAccountRights(PolicyHandle, AccountSid, &UserRights, &CountOfRights) )
    {
      v2 = CountOfRights;
      if ( CountOfRights )
      {
        v3 = malloc(12 * CountOfRights + 16);
        v1 = v3;
        *v3 = v2;
        v4 = 0;
        if ( CountOfRights )
        {
          v5 = (struct _LUID *)(v3 + 1);
          do
          {
            LookupPrivilegeValueW(0, UserRights[v4++].Buffer, v5);
            v5 = (struct _LUID *)((char *)v5 + 12);
          }
          while ( v4 < CountOfRights );
        }
        LsaFreeMemory(UserRights);
      }
    }
    LsaClose(PolicyHandle);
  }
  return v1;
}

//----- (00C37500) --------------------------------------------------------
int sub_C37500(wchar_t *Dst, wchar_t *Format, ...)
{
  va_list ArgList; // [esp+10h] [ebp+10h]

  va_start(ArgList, Format);
  return vswprintf_s(Dst, 0x80u, Format, ArgList);
}

//----- (00C37520) --------------------------------------------------------
_DWORD *__thiscall sub_C37520(_DWORD *this, int (__stdcall ***a2)(_DWORD, GUID *, _DWORD *))
{
  _DWORD *v2; // esi
  bool v3; // sf
  _DWORD *result; // eax

  v2 = this;
  *this = 0;
  if ( !a2 )
    return this;
  v3 = (**a2)(a2, &IID_ICorDebugInternalFrame2, this) < 0;
  result = v2;
  if ( v3 )
    *v2 = 0;
  return result;
}
// CAFC40: using guessed type GUID IID_ICorDebugInternalFrame2;

//----- (00C37560) --------------------------------------------------------
_DWORD *__thiscall sub_C37560(_DWORD *this, int (__stdcall ***a2)(_DWORD, GUID *, _DWORD *))
{
  _DWORD *v2; // esi
  bool v3; // sf
  _DWORD *result; // eax

  v2 = this;
  *this = 0;
  if ( !a2 )
    return this;
  v3 = (**a2)(a2, &stru_CAFD30, this) < 0;
  result = v2;
  if ( v3 )
    *v2 = 0;
  return result;
}
// CAFD30: using guessed type GUID stru_CAFD30;

//----- (00C375A0) --------------------------------------------------------
MixedModeStackWalker *__thiscall MixedModeStackWalker::MixedModeStackWalker(MixedModeStackWalker *this)
{
  MixedModeStackWalker *result; // eax

  this->vtptr = (IUnknownVtbl *)&MixedModeStackWalker::`vftable';
  result = this;
  this->m_nRefCount = 1;
  this->m_ICLRDebugging = 0;
  this->field_1C = 0;
  this->DebugDataTarget = 0;
  this->DebuggingLibraryProvider = 0;
  this->m_hProcess = 0;
  this->field_10 = 0;
  return result;
}
// CAF470: using guessed type void *MixedModeStackWalker::`vftable';

//----- (00C37600) --------------------------------------------------------
int __thiscall sub_C37600(_DWORD *this, int a2)
{
  _DWORD *v2; // esi
  int v3; // eax

  v2 = this;
  if ( *this == a2 )
    return *v2;
  if ( a2 )
    (*(void (__stdcall **)(int))(*(_DWORD *)a2 + 4))(a2);
  v3 = *v2;
  *v2 = a2;
  if ( v3 )
  {
    (*(void (__stdcall **)(int))(*(_DWORD *)v3 + 8))(v3);
    return *v2;
  }
  return a2;
}

//----- (00C37640) --------------------------------------------------------
_DWORD *__thiscall MixedModeStackWalker::`vector deleting destructor'(void *this, char a2)
{
  _DWORD *v2; // esi
  int v3; // ecx
  int v4; // ecx
  int v5; // ecx
  int v6; // ecx

  v2 = this;
  *(_DWORD *)this = &MixedModeStackWalker::`vftable';
  if ( *((_DWORD *)this + 3) )
    *((_DWORD *)this + 3) = 0;
  v3 = *((_DWORD *)this + 9);
  if ( v3 )
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v3 + 8))(v2[9]);
  v4 = v2[8];
  if ( v4 )
    (*(void (__stdcall **)(int))(*(_DWORD *)v4 + 8))(v4);
  v5 = v2[7];
  if ( v5 )
    (*(void (__stdcall **)(int))(*(_DWORD *)v5 + 8))(v5);
  v6 = v2[6];
  if ( v6 )
    (*(void (__stdcall **)(int))(*(_DWORD *)v6 + 8))(v6);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// CAF470: using guessed type void *MixedModeStackWalker::`vftable';

//----- (00C376F0) --------------------------------------------------------
unsigned int __thiscall sub_C376F0(_DWORD *this, int *a2)
{
  _DWORD *v2; // esi
  unsigned int v3; // edi
  int *v4; // ecx
  int v5; // eax

  v2 = this;
  v3 = this[1];
  if ( v3 >= this[2] && !sub_C388A0((const void **)this, v3 + 1) )
    ATL::AtlThrowImpl(-2147024882);
  v4 = (int *)(*v2 + 4 * v3);
  if ( v4 )
  {
    v5 = *a2;
    *v4 = *a2;
    if ( v5 )
      (*(void (__stdcall **)(int))(*(_DWORD *)v5 + 4))(v5);
  }
  ++v2[1];
  return v3;
}

//----- (00C37740) --------------------------------------------------------
_DWORD *__thiscall sub_C37740(_DWORD *this, int *a2)
{
  _DWORD *v2; // edi
  int v3; // ebx
  _DWORD *v4; // esi
  int v5; // edx
  int v6; // ecx
  _DWORD *v7; // eax
  _DWORD *result; // eax
  int v9; // [esp+18h] [ebp-10h]

  v2 = this;
  v3 = this[1];
  sub_C37F70(this);
  v4 = (_DWORD *)v2[4];
  v5 = *v4;
  v9 = *v4;
  if ( v4 )
  {
    v6 = *a2;
    v4[2] = *a2;
    if ( v6 )
    {
      (*(void (__stdcall **)(int))(*(_DWORD *)v6 + 4))(v6);
      v5 = v9;
    }
  }
  v2[4] = v5;
  v4[1] = v3;
  *v4 = 0;
  ++v2[2];
  v7 = (_DWORD *)v2[1];
  if ( v7 )
    *v7 = v4;
  else
    *v2 = v4;
  result = v4;
  v2[1] = v4;
  return result;
}

//----- (00C377E0) --------------------------------------------------------
void __stdcall sub_C377E0(int *a1)
{
  int *v1; // edx
  unsigned int v2; // edi
  unsigned int v3; // ebx
  unsigned int v4; // ecx
  int v5; // edx
  int v6; // eax
  SymbolInfo *v7; // eax
  SymbolInfo *v8; // esi
  int v9; // eax
  SymbolInfo *v10; // eax
  wchar_t *v11; // ST00_4
  SymbolInfoVtbl *v12; // eax
  const char *v13; // [esp-4h] [ebp-24h]
  void *v14; // [esp+10h] [ebp-10h]
  int v15; // [esp+1Ch] [ebp-4h]

  v1 = a1;
  v2 = a1[1] - 1;
  v3 = a1[1] - 2;
  if ( (v3 & 0x80000000) == 0 )
  {
    while ( 1 )
    {
      v4 = v1[1];
      if ( v2 >= v4 )
LABEL_26:
        ATL::AtlThrowImpl(-2147024809);
      v5 = *v1;
      if ( *(_DWORD *)(*(_DWORD *)(v5 + 4 * v2) + 24) == 3 )
      {
        if ( v3 >= v4 )
          goto LABEL_26;
        v6 = *(_DWORD *)(v5 + 4 * v3);
        if ( *(_DWORD *)(v6 + 24) == 1 || !*(_DWORD *)(v6 + 24) )
          break;
      }
      if ( v3 >= v4 )
        goto LABEL_26;
      if ( *(_DWORD *)(*(_DWORD *)(v5 + 4 * v3) + 24) == 3 )
      {
        v9 = *(_DWORD *)(v5 + 4 * v2);
        if ( *(_DWORD *)(v9 + 24) == 1 || !*(_DWORD *)(v9 + 24) )
        {
          v10 = (SymbolInfo *)operator new(0x20u);
          v8 = v10;
          v14 = v10;
          v15 = 2;
          if ( v10 )
          {
            v10->vtptr = (SymbolInfoVtbl *)&SymbolInfo::`vftable';
            v10->m_nRefCount = 1;
            v10->pszText = (int)operator new[](0x800u);
          }
          else
          {
            v8 = 0;
          }
          v15 = -1;
          v14 = v8;
          if ( v8 )
            ((void (__stdcall *)(SymbolInfo *))v8->vtptr->AddRef)(v8);
          v15 = 3;
          v13 = "[Managed to Unmanaged Transition]";
          goto LABEL_23;
        }
      }
LABEL_24:
      --v2;
      if ( (--v3 & 0x80000000) != 0 )
        return;
      v1 = a1;
    }
    v7 = (SymbolInfo *)operator new(0x20u);
    v8 = v7;
    v14 = v7;
    v15 = 0;
    if ( v7 )
    {
      v7->vtptr = (SymbolInfoVtbl *)&SymbolInfo::`vftable';
      v7->m_nRefCount = 1;
      v7->pszText = (int)operator new[](0x800u);
    }
    else
    {
      v8 = 0;
    }
    v15 = -1;
    v14 = v8;
    if ( v8 )
      ((void (__stdcall *)(SymbolInfo *))v8->vtptr->AddRef)(v8);
    v15 = 1;
    v13 = "[Unmanaged to Managed Transition]";
LABEL_23:
    v11 = (wchar_t *)v8->pszText;
    v8->field_10 = 0;
    v8->field_14 = 0;
    swprintf_s(v11, 0x400u, L"%S", v13);
    v8->field_18 = 1;
    sub_C38AE0(a1, v2, (int *)&v14, 1u);
    v12 = v8->vtptr;
    v15 = -1;
    ((void (__stdcall *)(SymbolInfo *))v12->Release)(v8);
    goto LABEL_24;
  }
}
// CAF420: using guessed type void *SymbolInfo::`vftable';

//----- (00C379A0) --------------------------------------------------------
void __cdecl sub_C379A0(_DWORD *a1, int a2)
{
  int v2; // ecx
  _DWORD *v3; // eax

  v2 = a2;
  if ( a2 )
  {
    v3 = a1;
    do
    {
      if ( v3 )
        *v3 = 0;
      ++v3;
      --v2;
    }
    while ( v2 );
  }
}

//----- (00C379D0) --------------------------------------------------------
int __cdecl sub_C379D0(int a1, unsigned int a2)
{
  unsigned int v2; // esi
  int v3; // ecx
  int result; // eax

  v2 = 0;
  if ( a2 )
  {
    do
    {
      v3 = *(_DWORD *)(a1 + 4 * v2);
      if ( v3 )
        result = (*(int (__stdcall **)(_DWORD))(*(_DWORD *)v3 + 8))(*(_DWORD *)(a1 + 4 * v2));
      ++v2;
    }
    while ( v2 < a2 );
  }
  return result;
}

//----- (00C37A00) --------------------------------------------------------
int __cdecl sub_C37A00(HWND hWnd, int a2, char a3)
{
  void (__stdcall *SendMessageW)(HWND, UINT, WPARAM, LPARAM); // edi
  int v4; // esi
  LRESULT v5; // eax
  char v6; // al
  int v7; // ecx
  unsigned int v8; // eax
  ICorPublishAppDomain *v9; // eax
  int v10; // esi
  int v11; // eax
  char v12; // al
  char v13; // cl
  signed int v14; // eax
  char v16; // [esp-22Ch] [ebp-6D0h]
  const IID *v17; // [esp-14h] [ebp-4B8h]
  ICorPublishAppDomain *v18; // [esp-10h] [ebp-4B4h]
  DWORD v19; // [esp-Ch] [ebp-4B0h]
  const IID *v20; // [esp-8h] [ebp-4ACh]
  ICorPublish **v21; // [esp-4h] [ebp-4A8h]
  LVITEMW Item; // [esp+Ch] [ebp-498h]
  int cbName; // [esp+40h] [ebp-464h]
  ICorPublishProcess *pICorPublishProcess; // [esp+44h] [ebp-460h]
  int v25; // [esp+48h] [ebp-45Ch]
  ICorPublishAppDomain **ppICorPublishAppDomain; // [esp+4Ch] [ebp-458h]
  unsigned int v27; // [esp+50h] [ebp-454h]
  ICorPublish *pICorPublish; // [esp+54h] [ebp-450h]
  int v29; // [esp+58h] [ebp-44Ch]
  ICorPublishAppDomainEnum *pICorPublishAppDomainEnum; // [esp+5Ch] [ebp-448h]
  ULONG v31; // [esp+60h] [ebp-444h]
  int a5; // [esp+67h] [ebp-43Dh]
  char v33; // [esp+6Ch] [ebp-438h]
  int v34; // [esp+70h] [ebp-434h]
  int v35; // [esp+7Ch] [ebp-428h]
  int v36; // [esp+80h] [ebp-424h]
  wchar_t Dst; // [esp+90h] [ebp-414h]
  __int16 szName[260]; // [esp+298h] [ebp-20Ch]

  Item.mask = 0;
  memset(&Item.iItem, 0, 0x30u);
  v21 = &pICorPublish;
  v20 = &IID_ICorPublish;
  v19 = 1;
  v18 = 0;
  if ( byte_CDA09A )
    v17 = &stru_CAF40C;
  else
    v17 = &CLSID_CorpubPublish;
  CoCreateInstance(v17, (LPUNKNOWN)v18, v19, v20, (LPVOID *)v21);
  SendMessageW = (void (__stdcall *)(HWND, UINT, WPARAM, LPARAM))::SendMessageW;
  v4 = 0;
  BYTE1(a5) = 0;
  v29 = 0;
  v25 = 0;
  Item.mask = 4;
  v5 = ::SendMessageW(hWnd, LVM_GETITEMCOUNT, 0, 0);
  Item.iSubItem = 0;
  Item.iItem = v5 - 1;
  if ( ::SendMessageW(hWnd, LVM_GETITEMW, 0, (LPARAM)&Item) )
  {
    do
    {

      v6 = sub_C658D0((signed int)hWnd, hWnd, &Item, (LPARAM)Item.lParam, (int)&a5);
      v7 = BYTE1(a5);
      if ( v6 )
        v7 = 1;
      *(int *)((char *)&a5 + 1) = v7;
      Item.lParam->dwRefreshCount = 0;
      if ( (_BYTE)a5 )
        ++v4;
    }
    while ( ::SendMessageW(hWnd, LVM_GETITEMW, 0, (LPARAM)&Item) );
    v25 = v4;
  }
  if ( !pICorPublish->vtptr->GetProcess(pICorPublish, a2, (void **)&pICorPublishProcess) )
  {
    pICorPublishProcess->vtptr->EnumAppDomains(pICorPublishProcess, (void **)&pICorPublishAppDomainEnum);
    pICorPublishAppDomainEnum->vtptr->GetCount((ICorPublishEnum *)pICorPublishAppDomainEnum, &v31);
    ppICorPublishAppDomain = (ICorPublishAppDomain **)operator new[](4 * v31);
    pICorPublishAppDomainEnum->vtptr->Next(
      (ICorPublishEnum *)pICorPublishAppDomainEnum,
      v31,
      (void **)ppICorPublishAppDomain,
      &v31);
    SendMessageW = (void (__stdcall *)(HWND, UINT, WPARAM, LPARAM))::SendMessageW;
    v8 = 0;
    v27 = 0;
    if ( v31 )
    {
      do
      {
        v21 = (ICorPublish **)szName;
        cbName = 260;
        v20 = (const IID *)&cbName;
        v9 = ppICorPublishAppDomain[v8];
        v19 = 260;
        v18 = v9;
        v9->vtptr->GetName(v9, 260, (ULONG32 *)&cbName, (WCHAR *)szName);
        v10 = 0;
        if ( ((LRESULT (__stdcall *)(HWND, UINT, WPARAM, LPARAM))SendMessageW)(hWnd, LVM_GETITEMCOUNT, 0, 0) > 0 )
        {
          while ( 1 )
          {
            Item.mask = 4;
            Item.iItem = v10;
            Item.iSubItem = 0;
            SendMessageW(hWnd, 0x104Bu, 0, (LPARAM)&Item);
            v11 = Item.lParam->field_10;
            if ( (v11 == 1 || !v11) && !_wcsicmp((const wchar_t *)szName, (const wchar_t *)&Item.lParam->nRefCount) )
              break;
            if ( ++v10 >= ((LRESULT (__stdcall *)(HWND, UINT, WPARAM, LPARAM))SendMessageW)(
                            hWnd,
                            LVM_GETITEMCOUNT,
                            0,
                            0) )
              goto LABEL_22;
          }
          ++v29;
          v12 = sub_C68A20((int)Item.lParam);
          v13 = BYTE1(a5);
          if ( v12 )
            v13 = 1;
          BYTE1(a5) = v13;
        }
LABEL_22:
        if ( v10 == ((LRESULT (__stdcall *)(HWND, UINT, WPARAM, LPARAM))SendMessageW)(hWnd, LVM_GETITEMCOUNT, 0, 0) )
        {
          BYTE1(a5) = 1;
          memset(&v33, 0, 0x22Cu);
          wcscpy_s(&Dst, 0x104u, (const wchar_t *)szName);
          v34 = 4;
          v14 = 2;
          v36 = 0;
          if ( a3 )
            v14 = 0;
          v35 = v14;
          qmemcpy(&v16, &v33, 0x22Cu);
          sub_C273D0(hWnd, v16);
          SendMessageW = (void (__stdcall *)(HWND, UINT, WPARAM, LPARAM))::SendMessageW;
        }
        v8 = v27 + 1;
        v27 = v8;
      }
      while ( v8 < v31 );
      v4 = v25;
    }
    v21 = (ICorPublish **)pICorPublishAppDomainEnum;
    pICorPublishAppDomainEnum->vtptr->Release((ICorPublishEnum *)pICorPublishAppDomainEnum);
    operator delete(ppICorPublishAppDomain);
    if ( v29 != v4 || BYTE1(a5) )
      InvalidateRect(hWnd, 0, 0);
    v21 = (ICorPublish **)pICorPublishProcess;
    pICorPublishProcess->vtptr->Release(pICorPublishProcess);
  }
  if ( BYTE1(a5) )
    SendMessageW(hWnd, 0xBu, 1u, 0);
  v21 = (ICorPublish **)pICorPublish;
  return pICorPublish->vtptr->Release(pICorPublish);
}
// CAF40C: using guessed type GUID stru_CAF40C;
// CDA09A: using guessed type char byte_CDA09A;

//----- (00C37DD0) --------------------------------------------------------
signed int __stdcall sub_C37DD0(int (__stdcall ***a1)(_DWORD, GUID *, int *))
{
  int (__stdcall ***v1)(_DWORD, GUID *, int *); // esi
  int (__stdcall **v2)(_DWORD, GUID *, int *); // eax
  int (__stdcall ***v3)(_DWORD, GUID *, int *); // eax
  signed int v4; // esi
  int (__stdcall **v5)(_DWORD, GUID *, int *); // eax
  int v6; // eax
  int (__stdcall **v7)(_DWORD, GUID *, int *); // eax
  int v8; // ecx
  int *v10; // [esp+8h] [ebp-14h]
  int v11; // [esp+Ch] [ebp-10h]
  int v12; // [esp+18h] [ebp-4h]

  v1 = a1;
  if ( !a1 )
    return 3;
  a1 = 0;
  v2 = *v1;
  v12 = 0;
  if ( (*v2)(v1, &IID_ICorDebugILFrame, (int *)&a1) || (v3 = a1) == 0 )
  {
    v11 = 0;
    v5 = *v1;
    LOBYTE(v12) = 1;
    if ( !(*v5)(v1, &IID_ICorDebugInternalFrame, &v11) )
    {
      v6 = v11;
      if ( v11 )
      {
        v4 = 1;
LABEL_11:
        LOBYTE(v12) = 0;
        if ( v6 )
          (*(void (__stdcall **)(int))(*(_DWORD *)v6 + 8))(v6);
        v3 = a1;
        goto LABEL_14;
      }
    }
    v10 = 0;
    v7 = *v1;
    LOBYTE(v12) = 2;
    if ( !(*v7)(v1, &IID_ICorDebugRuntimeUnwindableFrame, (int *)&v10) && v10 )
    {
      v8 = *v10;
      v4 = 2;
      LOBYTE(v12) = 1;
      (*(void (__stdcall **)(int *))(v8 + 8))(v10);
      v6 = v11;
      goto LABEL_11;
    }
    LOBYTE(v12) = 1;
    if ( v10 )
      (*(void (__stdcall **)(int *))(*v10 + 8))(v10);
    LOBYTE(v12) = 0;
    if ( v11 )
      (*(void (__stdcall **)(int))(*(_DWORD *)v11 + 8))(v11);
    v12 = -1;
    if ( a1 )
      ((void (__stdcall *)(int (__stdcall ***)(_DWORD, GUID *, int *)))(*a1)[2])(a1);
    return 3;
  }
  v4 = 0;
LABEL_14:
  v12 = -1;
  if ( v3 )
    ((void (__stdcall *)(int (__stdcall ***)(_DWORD, GUID *, int *)))(*v3)[2])(v3);
  return v4;
}
// CAFBB8: using guessed type GUID IID_ICorDebugILFrame;
// CAFBC8: using guessed type GUID IID_ICorDebugInternalFrame;
// CAFBD8: using guessed type GUID IID_ICorDebugRuntimeUnwindableFrame;

//----- (00C37F10) --------------------------------------------------------
int __cdecl sub_C37F10(int a1, LPCWSTR lpsz, int a3)
{
  wchar_t **v3; // eax
  void **v4; // edi

  *(_DWORD *)a3 = 0;
  *(_DWORD *)(a3 + 4) = 0;
  v3 = sub_C3E760((PerformanceInfo **)a1, lpsz);
  v4 = (void **)v3;
  if ( v3 && sub_C3ECA0((int)v3, (_DWORD *)a3, 0) )
  {
    sub_C3EC80(v4);
    operator delete(v4);
  }
  return a3;
}

//----- (00C37F60) --------------------------------------------------------
int __thiscall sub_C37F60(_DWORD *this)
{
  return this[7];
}

//----- (00C37F70) --------------------------------------------------------
void __thiscall sub_C37F70(_DWORD *this)
{
  _DWORD *v1; // esi
  unsigned int v2; // edi
  _DWORD *v3; // eax
  int v4; // edx
  _DWORD *v5; // eax
  int i; // edx

  v1 = this;
  if ( !this[4] )
  {
    v2 = 12 * this[5];
    if ( !is_mul_ok(0xCu, this[5]) || v2 > 0xFFFFFFFF || -1 - v2 < 4 || (v3 = malloc(v2 + 4)) == 0 )
      ATL::AtlThrowImpl(-2147024882);
    *v3 = v1[3];
    v1[3] = v3;
    v4 = v1[5];
    v5 = &v3[3 * v4 - 2];
    for ( i = v4 - 1; i >= 0; --i )
    {
      *v5 = v1[4];
      v1[4] = v5;
      v5 -= 3;
    }
  }
}

//----- (00C37FF0) --------------------------------------------------------
signed int __stdcall sub_C37FF0(unsigned int a1, _DWORD *a2, unsigned int *a3)
{
  int *v3; // edi
  unsigned int v5; // edx
  void *v6; // esi
  void *v7; // eax
  int v8; // ecx
  void *v9; // eax
  _DWORD *v10; // edi
  unsigned int v11; // edx
  int v12; // [esp+4h] [ebp-4h]

  v3 = (int *)a1;
  if ( (*(int (__stdcall **)(unsigned int, _DWORD, unsigned int *, _DWORD))(*(_DWORD *)a1 + 16))(a1, 0, &a1, 0) )
    return 0;
  v5 = a1;
  v6 = 0;
  if ( a1 )
  {
    v7 = operator new[](4 * a1);
    v8 = *v3;
    v6 = v7;
    v12 = 0;
    if ( (*(int (__stdcall **)(int *, unsigned int, int *, void *))(v8 + 16))(v3, a1, &v12, v7) )
    {
      operator delete[](v6);
      return 0;
    }
    v5 = a1;
  }
  *a3 = v5;
  if ( v5 )
  {
    v9 = operator new[](4 * v5);
    v10 = a2;
    v11 = 0;
    *a2 = v9;
    if ( a1 )
    {
      do
      {
        *(_DWORD *)(*v10 + 4 * v11) = *((_DWORD *)v6 + v11);
        ++v11;
      }
      while ( v11 < a1 );
    }
  }
  operator delete[](v6);
  return 1;
}

//----- (00C380C0) --------------------------------------------------------
signed int __stdcall sub_C380C0(int (__stdcall ***a1)(_DWORD, GUID *, int *), SymbolInfo *a2)
{
  _DWORD *v2; // ecx
  int v3; // eax
  int v4; // eax
  int v5; // ecx
  signed int v6; // esi
  int (__stdcall **v7)(_DWORD, GUID *, int *); // eax
  _DWORD *v8; // ecx
  int v9; // eax
  int v10; // eax
  int (__stdcall **v11)(_DWORD, GUID *, int *); // eax
  int v12; // ecx
  wchar_t *v13; // ecx
  signed int v14; // edx
  wchar_t v15; // ax
  char v17; // [esp+Ch] [ebp-1B38h]
  char v18; // [esp+10h] [ebp-1B34h]
  char v19; // [esp+14h] [ebp-1B30h]
  char v20; // [esp+18h] [ebp-1B2Ch]
  char v21; // [esp+1Ch] [ebp-1B28h]
  char v22; // [esp+20h] [ebp-1B24h]
  char v23; // [esp+24h] [ebp-1B20h]
  char v24; // [esp+28h] [ebp-1B1Ch]
  char v25; // [esp+2Ch] [ebp-1B18h]
  int v26; // [esp+30h] [ebp-1B14h]
  int v27; // [esp+34h] [ebp-1B10h]
  int v28; // [esp+38h] [ebp-1B0Ch]
  int v29; // [esp+3Ch] [ebp-1B08h]
  int v30; // [esp+40h] [ebp-1B04h]
  int v31; // [esp+44h] [ebp-1B00h]
  int v32; // [esp+48h] [ebp-1AFCh]
  int v33; // [esp+4Ch] [ebp-1AF8h]
  int (__stdcall ***v34)(_DWORD, GUID *, int *); // [esp+50h] [ebp-1AF4h]
  _DWORD *v35; // [esp+54h] [ebp-1AF0h]
  _DWORD *v36; // [esp+58h] [ebp-1AECh]
  int v37; // [esp+5Ch] [ebp-1AE8h]
  int v38; // [esp+60h] [ebp-1AE4h]
  int *v39; // [esp+64h] [ebp-1AE0h]
  int v40; // [esp+68h] [ebp-1ADCh]
  int v41; // [esp+12Ch] [ebp-1A18h]
  wchar_t Dst; // [esp+334h] [ebp-1810h]
  char v43; // [esp+B34h] [ebp-1010h]
  char v44; // [esp+F34h] [ebp-C10h]
  wchar_t Ext; // [esp+1334h] [ebp-810h]
  wchar_t Filename; // [esp+1534h] [ebp-610h]
  wchar_t FullPath; // [esp+1734h] [ebp-410h]
  int v48; // [esp+1B40h] [ebp-4h]

  if ( sub_C37DD0(a1) == 1 )
  {
    v2 = 0;
    v36 = 0;
    if ( a1 )
    {
      v3 = (**a1)(a1, &IID_ICorDebugInternalFrame, (int *)&v36);
      v2 = v36;
      if ( v3 < 0 )
        v2 = 0;
      v36 = v2;
    }
    v4 = *v2;
    v48 = 0;
    if ( (*(int (__stdcall **)(_DWORD *, int *))(v4 + 44))(v2, &v29) )
    {
LABEL_15:
      v5 = (int)v36;
      v6 = 0;
    }
    else
    {
      switch ( v29 )
      {
        case 3:
          sub_C38A30(a2, (int)"[AppDomain Transition]", 0, 0, 1);
          v5 = (int)v36;
          v6 = 1;
          break;
        case 4:
          sub_C38A30(a2, (int)"[Lightweight function]", 0, 0, 1);
          v5 = (int)v36;
          v6 = 1;
          break;
        case 5:
          sub_C38A30(a2, (int)"[Func Eval]", 0, 0, 1);
          v5 = (int)v36;
          v6 = 1;
          break;
        case 7:
          sub_C38A30(a2, (int)"[Class Init]", 0, 0, 1);
          v5 = (int)v36;
          v6 = 1;
          break;
        case 8:
          sub_C38A30(a2, (int)"[Exception]", 0, 0, 1);
          v5 = (int)v36;
          v6 = 1;
          break;
        case 9:
          sub_C38A30(a2, (int)"[Security]", 0, 0, 1);
          v5 = (int)v36;
          v6 = 1;
          break;
        case 10:
          sub_C38A30(a2, (int)"[JIT Compilation]", 0, 0, 1);
          v5 = (int)v36;
          v6 = 1;
          break;
        default:
          goto LABEL_15;
      }
    }
  }
  else
  {
    v34 = 0;
    v7 = *a1;
    v48 = 1;
    if ( (*v7)(a1, &IID_ICorDebugILFrame, (int *)&v34) )
    {
      v6 = 0;
    }
    else
    {
      v8 = 0;
      v35 = 0;
      if ( v34 )
      {
        v9 = (**v34)(v34, &stru_CAFD30, (int *)&v35);
        v8 = v35;
        if ( v9 < 0 )
          v8 = 0;
        v35 = v8;
      }
      v33 = 0;
      v10 = *v8;
      LOBYTE(v48) = 3;
      if ( (*(int (__stdcall **)(_DWORD *, int *))(v10 + 52))(v8, &v33)
        || (memset(&v40, 0, 0x2CCu),
            v40 = 65539,
            (*(int (__stdcall **)(int, signed int, int *))(*(_DWORD *)v33 + 24))(v33, 716, &v40)) )
      {
        v6 = 0;
      }
      else
      {
        v37 = 0;
        v11 = *a1;
        LOBYTE(v48) = 4;
        if ( ((int (__stdcall *)(int (__stdcall ***)(_DWORD, GUID *, int *), int *))v11[5])(a1, &v37)
          || (*(int (__stdcall **)(int, int *))(*(_DWORD *)v37 + 20))(v37, &v30) )
        {
          v6 = 0;
        }
        else
        {
          v39 = 0;
          LOBYTE(v48) = 5;
          if ( (*(int (__stdcall **)(int, int **))(*(_DWORD *)v37 + 12))(v37, &v39) )
          {
            v6 = 0;
          }
          else
          {
            v38 = 0;
            v12 = *v39;
            LOBYTE(v48) = 6;
            if ( (*(int (__stdcall **)(int *, GUID *, int *))(v12 + 56))(v39, &stru_CAF3CC, &v38)
              || (*(int (__stdcall **)(int, int, int *, char *, signed int, char *, char *, char *, char *, char *, char *))(*(_DWORD *)v38 + 120))(
                   v38,
                   v30,
                   &v28,
                   &v44,
                   512,
                   &v21,
                   &v23,
                   &v24,
                   &v18,
                   &v22,
                   &v25)
              || (*(int (__stdcall **)(int, int, char *, signed int, char *, char *, char *))(*(_DWORD *)v38 + 48))(
                   v38,
                   v28,
                   &v43,
                   512,
                   &v20,
                   &v17,
                   &v19) )
            {
              v6 = 0;
            }
            else
            {
              sub_C37560(&v31, a1);
              LOBYTE(v48) = 7;
              if ( (*(int (__stdcall **)(int, int *))(*(_DWORD *)v31 + 44))(v31, &v27) )
              {
                v6 = 0;
              }
              else
              {
                v32 = 0;
                LOBYTE(v48) = 8;
                if ( (*(int (__stdcall **)(int *, int *))(*v39 + 20))(v39, &v32) )
                {
                  v6 = 0;
                }
                else
                {
                  v26 = 512;
                  if ( (*(int (__stdcall **)(int *, signed int, int *, wchar_t *))(*v39 + 24))(
                         v39,
                         512,
                         &v26,
                         &FullPath)
                    || _wsplitpath_s(&FullPath, 0, 0, 0, 0, &Filename, 0x100u, &Ext, 0x100u) )
                  {
                    v13 = &FullPath;
                    v14 = 512;
                    while ( v14 != -2147483134 )
                    {
                      v15 = *(wchar_t *)((char *)v13 + (char *)L"<Unresolved>" - (char *)&FullPath);
                      if ( !v15 )
                        break;
                      *v13 = v15;
                      ++v13;
                      if ( !--v14 )
                        goto LABEL_44;
                    }
                    if ( v14 )
                      goto LABEL_45;
LABEL_44:
                    --v13;
LABEL_45:
                    *v13 = 0;
                  }
                  else
                  {
                    swprintf_s(&FullPath, 0x200u, L"%s%s", &Filename, &Ext);
                  }
                  swprintf_s(&Dst, 0x400u, L"%s!%s.%s+0x%x", &FullPath, &v43, &v44, v27);
                  sub_C38A90(a2, (int)&Dst, v41, 0, 0);
                  v6 = 1;
                }
                LOBYTE(v48) = 7;
                if ( v32 )
                  (*(void (__stdcall **)(int))(*(_DWORD *)v32 + 8))(v32);
              }
              LOBYTE(v48) = 6;
              if ( v31 )
                (*(void (__stdcall **)(int))(*(_DWORD *)v31 + 8))(v31);
            }
            LOBYTE(v48) = 5;
            if ( v38 )
              (*(void (__stdcall **)(int))(*(_DWORD *)v38 + 8))(v38);
          }
          LOBYTE(v48) = 4;
          if ( v39 )
            (*(void (__stdcall **)(int *))(*v39 + 8))(v39);
        }
        LOBYTE(v48) = 3;
        if ( v37 )
          (*(void (__stdcall **)(int))(*(_DWORD *)v37 + 8))(v37);
      }
      LOBYTE(v48) = 2;
      if ( v33 )
        (*(void (__stdcall **)(int))(*(_DWORD *)v33 + 8))(v33);
      LOBYTE(v48) = 1;
      if ( v35 )
        (*(void (__stdcall **)(_DWORD *))(*v35 + 8))(v35);
    }
    v5 = (int)v34;
  }
  v48 = -1;
  if ( v5 )
    (*(void (__stdcall **)(int))(*(_DWORD *)v5 + 8))(v5);
  return v6;
}
// CAF3CC: using guessed type GUID stru_CAF3CC;
// CAFBB8: using guessed type GUID IID_ICorDebugILFrame;
// CAFBC8: using guessed type GUID IID_ICorDebugInternalFrame;
// CAFD30: using guessed type GUID stru_CAFD30;
// CAFD40: using guessed type wchar_t aUnresolved[13];

//----- (00C386C0) --------------------------------------------------------
int __stdcall sub_C386C0(int a1, int a2)
{
  *(_DWORD *)a2 = 0;
  return 0;
}

//----- (00C386E0) --------------------------------------------------------
int *__cdecl sub_C386E0(wchar_t *a1, int a2)
{
  int *result; // eax
  int *v3; // esi
  __int16 Dst[260]; // [esp+Ch] [ebp-20Ch]

  result = sub_C3ED60((_DWORD *)a2);
  v3 = result;
  if ( result )
  {
    do
    {
      if ( sub_C3E850(v3, (wchar_t *)Dst, 0x104u) && !_wcsnicmp(a1, (const wchar_t *)Dst, wcslen(a1)) )
        break;
      if ( v3 )
        operator delete(v3);
      v3 = sub_C3EE00((_DWORD *)a2);
    }
    while ( v3 );
    result = v3;
  }
  return result;
}
