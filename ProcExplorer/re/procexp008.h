
//----- (00FFE5E0) --------------------------------------------------------
int __stdcall CTreeList::OnMsg2004(int a1, int a2, int a5)
{
  CTreeList *v3; // ecx
  CTreeList *v4; // edi
  CListViewData *pListViewData; // eax
  int v6; // esi
  tagTreeViewChildItem *v7; // eax
  int v8; // ebx
  int v9; // eax

  v4 = v3;
  pListViewData = operator new(8u);
  if ( pListViewData )
  {
    pListViewData->vtptr = &CListViewData::`vftable';
    pListViewData->m_Value = a2;
  }
  else
  {
    pListViewData = 0;
  }
  v6 = a1;
  if ( !a1 )
    v6 = &v4->field_40;
  v7 = sub_FFD640(v6, v4, pListViewData, pfnCallback, a5);
  v8 = v7;
  if ( *(v6 + 0x20) & 0x10 )
  {
    v9 = CTreeList::FindChild(v4, v7);
    CTreeList::SetVScrollbarPos(v9, 1);
  }
  return v8;
}
// 1094268: using guessed type void *CListViewData::`vftable';

//----- (00FFE650) --------------------------------------------------------
int __thiscall sub_FFE650(_DWORD *this)
{
  int result; // eax
  int v2; // eax

  result = this[5];
  if ( !result || !((this[8] >> 4) & 1) )
  {
    result = this[4];
    if ( !result )
    {
      v2 = this[2];
      if ( v2 )
      {
        while ( !*(v2 + 16) )
        {
          v2 = *(v2 + 8);
          if ( !v2 )
            goto LABEL_7;
        }
        result = *(v2 + 16);
      }
      else
      {
LABEL_7:
        result = 0;
      }
    }
  }
  return result;
}

//----- (00FFE690) --------------------------------------------------------
int __thiscall CTreeList::SendNotifyEx(CTreeList *this, HWND hWndParent, TVNMHDR *pNMHDR)
{
  tagTreeViewChildItem *pSibling; // edi
  CTreeListData *pTreeListData; // ebx
  UINT code; // eax
  UINT v6; // eax
  tagTreeViewChildItem *v7; // edi
  CTreeListData *v8; // eax
  HWND v9; // edi
  int result; // eax
  tagTreeViewChildItem *v11; // eax
  UINT v12; // ST08_4
  UINT v13; // eax
  TVNMHDR lParam; // [esp+Ch] [ebp-34h]
  int v15; // [esp+28h] [ebp-18h]
  int v16; // [esp+2Ch] [ebp-14h]
  __int64 v17; // [esp+34h] [ebp-Ch]
  CTreeList *pThis; // [esp+3Ch] [ebp-4h]

  pThis = this;
  pSibling = pNMHDR->pTo;
  if ( pSibling )
    pTreeListData = pSibling->m_TreeListData;
  else
    pTreeListData = 0;
  code = pNMHDR->nmhdr.code;
  if ( code > 2005 )
  {
    if ( code > -5 )
    {
      if ( code + 3 > 1 )
        return SendMessageW(hWndParent, WM_NOTIFY, pNMHDR->nmhdr.idFrom, pNMHDR);
    }
    else if ( code != -5 )
    {
      if ( code == 2006 )
      {
        _mm_storeu_si128(&lParam.nmhdr.code, 0i64);
        lParam.pFrom = 2006;
        _mm_storeu_si128(&lParam.nItem2, 0i64);
        v17 = 0i64;
        *&lParam.nmhdr.idFrom = *&pNMHDR->nmhdr.hwndFrom;
        lParam.pFrom = LVN_DELETEITEM;
        lParam.pTo = CTreeList::FindChild(this, pSibling);
        HIDWORD(v17) = pTreeListData->m_dwValue;
        SendMessageW(hWndParent, WM_NOTIFY, lParam.nmhdr.code, &lParam.nmhdr.idFrom);
        return 0;
      }
      return SendMessageW(hWndParent, WM_NOTIFY, pNMHDR->nmhdr.idFrom, pNMHDR);
    }
    memset(&lParam.nmhdr.idFrom, 0, 0x2Cu);
    v13 = pNMHDR->nmhdr.code;
    *&lParam.nmhdr.hwndFrom = *&pNMHDR->nmhdr.hwndFrom;
    lParam.nmhdr.code = v13;
    if ( pSibling )
      lParam.pFrom = CTreeList::FindChild(pThis, pSibling);
    else
      lParam.pFrom = -1;
    lParam.pTo = pNMHDR->nItem1;
    if ( pTreeListData )
      LODWORD(v17) = pTreeListData->m_dwValue;
    else
      LODWORD(v17) = 0;
    return SendMessageW(hWndParent, WM_NOTIFY, lParam.nmhdr.idFrom, &lParam);
  }
  if ( code >= 2004 )
    return SendMessageW(hWndParent, WM_NOTIFY, pNMHDR->nmhdr.idFrom, pNMHDR);
  switch ( code )
  {
    case 2000u:
      v6 = pNMHDR->nmhdr.code;
      v7 = pNMHDR->pFrom;
      v17 = 0i64;
      _mm_storeu_si128(&lParam.nmhdr.code, 0i64);
      lParam.pFrom = LVN_ITEMCHANGED;
      _mm_storeu_si128(&lParam.nItem2, 0i64);
      *&lParam.nmhdr.idFrom = *&pNMHDR->nmhdr.hwndFrom;
      if ( v7 )
      {
        lParam.pTo = CTreeList::FindChild(this, v7);
        v8 = v7->m_TreeListData;
        v9 = hWndParent;
        HIDWORD(v17) = v8->m_dwValue;
        v15 = 3;
        lParam.nItem2 = 0;
        v16 = 3;
        SendMessageW(hWndParent, WM_NOTIFY, lParam.nmhdr.code, &lParam.nmhdr.idFrom);
        this = pThis;
      }
      else
      {
        v9 = hWndParent;
      }
      if ( pNMHDR->pTo )
      {
        lParam.pTo = CTreeList::FindChild(this, pNMHDR->pTo);
        HIDWORD(v17) = pTreeListData->m_dwValue;
        lParam.nItem2 = 0;
        v15 = 3;
        v16 = 3;
        SendMessageW(v9, WM_NOTIFY, lParam.nmhdr.code, &lParam.nmhdr.idFrom);
      }
      result = 0;
      break;
    case 2003u:
      v11 = pNMHDR->nmhdr.code;
      _mm_storeu_si128(&lParam.nmhdr.code, 0i64);
      lParam.pFrom = v11;
      lParam.nItem1 = pNMHDR->nItem1;
      v12 = pNMHDR->nmhdr.idFrom;
      _mm_storeu_si128(&lParam.nItem2, 0i64);
      v17 = 0i64;
      *&lParam.nmhdr.idFrom = *&pNMHDR->nmhdr.hwndFrom;
      lParam.pFrom = LVN_COLUMNCLICK;
      lParam.pTo = -1;
      SendMessageW(hWndParent, WM_NOTIFY, v12, &lParam.nmhdr.idFrom);
      result = 0;
      break;
    default:
      return SendMessageW(hWndParent, WM_NOTIFY, pNMHDR->nmhdr.idFrom, pNMHDR);
  }
  return result;
}

//----- (00FFE900) --------------------------------------------------------
BOOL __thiscall sub_FFE900(_DWORD *this, int a2, int a3, int a4, int a5, const __m128i *a6)
{
  _DWORD *v6; // ST20_4
  CTreeList *v7; // ST1C_4
  signed int v8; // edi
  LONG v9; // eax
  __m128i v10; // xmm0
  WPARAM v11; // ST08_4
  HWND v12; // eax
  LPARAM lParam; // [esp+18h] [ebp-34h]
  LONG v15; // [esp+1Ch] [ebp-30h]
  int v16; // [esp+20h] [ebp-2Ch]
  int v17; // [esp+24h] [ebp-28h]
  int v18; // [esp+28h] [ebp-24h]
  HWND v19; // [esp+2Ch] [ebp-20h]
  int v20; // [esp+30h] [ebp-1Ch]
  __int128 v21; // [esp+34h] [ebp-18h]
  int v22; // [esp+44h] [ebp-8h]

  v6 = this;
  v7 = *a2;
  v8 = CTreeList::FindChild(*a2, a2);
  lParam = 0;
  memset(&v15, 0, 0x2Cu);
  v20 = a3;
  v9 = GetWindowLongW(v7->m_hWnd, -12);
  v10 = _mm_loadu_si128(a6);
  lParam = 102;
  v15 = v9;
  v19 = v7->m_hWnd;
  v18 = *(a2 + 32);
  _mm_storeu_si128(&v21, v10);
  v16 = v8;
  v17 = a4;
  v22 = v6[1];
  v11 = v9;
  v12 = GetParent(v7->m_hWnd);
  return SendMessageW(v12, 0x2Bu, v11, &lParam) != 0;
}

//----- (00FFE9C0) --------------------------------------------------------
char __stdcall sub_FFE9C0(int a1, int a2, int a3, int a4, int a5)
{
  return 0;
}

//----- (00FFE9D0) --------------------------------------------------------
int __thiscall sub_FFE9D0(_DWORD *this)
{
  int v1; // edx
  int i; // ecx
  int result; // eax

  v1 = this[3];
  if ( v1 )
  {
    for ( i = *(v1 + 24); i; i = *(i + 24) )
    {
      if ( !((*(v1 + 32) >> 4) & 1) )
        break;
      v1 = i;
    }
    result = v1;
  }
  else
  {
    result = this[2];
    if ( result && !*(result + 4) )
      result = 0;
  }
  return result;
}

//----- (00FFEA10) --------------------------------------------------------
int __thiscall CTreeList::Refresh(CTreeList *this)
{
  CTreeList *v1; // edi

  v1 = this;
  InvalidateRect(this->m_hWnd, 0, 0);
  InvalidateRect(v1->m_hWndHeaderLeft, 0, 0);
  InvalidateRect(v1->m_hWndHeaderRight, 0, 0);
  v1->m_nChildWidthLast = CTreeList::GetChildWidth(v1, 0);
  CTreeList::OnSize(v1);
  CTreeList::RepositionHeaders();
  return CTreeList::RepositionTooltips();
}

//----- (00FFEA60) --------------------------------------------------------
BOOL __thiscall CTreeList::RefreshHeaderItem(CTreeList *this, int nItem)
{
  CTreeList *v2; // esi
  BOOL result; // eax
  RECT lParam; // [esp+4h] [ebp-14h]

  v2 = this;
  if ( nItem )
  {
    SendMessageW(this->m_hWndHeaderRight, HDM_GETITEMRECT, nItem - 1, &lParam);
    result = InvalidateRect(v2->m_hWndHeaderRight, &lParam, 0);
  }
  else
  {
    SendMessageW(this->m_hWndHeaderLeft, HDM_GETITEMRECT, 0, &lParam);
    result = InvalidateRect(v2->m_hWndHeaderLeft, &lParam, 0);
  }
  return result;
}

//----- (00FFEAD0) --------------------------------------------------------
int __thiscall CTreeList::RefreshChildItem(CTreeList *thisIn, tagTreeViewChildItem *pChild)
{
  CTreeList *v2; // esi
  int result; // eax

  v2 = thisIn;
  result = CTreeList::FindChild(thisIn, pChild);
  if ( result >= 0 )
    CTreeList::RedrawZone(v2, result, result);
  return result;
}

//----- (00FFEAF0) --------------------------------------------------------
void __thiscall CTreeList::RedrawZone(CTreeList *thisIn, int nStart, int nEnd)
{
  CTreeList *v3; // ebx
  HWND m_hWndScrollBarRightRight; // ST00_4
  HDC hDC; // esi
  LONG nHeigth; // ebx
  int v7; // eax
  int nTotalHeight; // esi
  CTreeList *this; // [esp+8h] [ebp-80h]
  struct tagTEXTMETRICW tm; // [esp+Ch] [ebp-7Ch]
  struct tagRECT Rect; // [esp+48h] [ebp-40h]
  struct tagSCROLLINFO ScrollInfo; // [esp+58h] [ebp-30h]
  RECT rcClient; // [esp+74h] [ebp-14h]

  v3 = thisIn;
  this = thisIn;
  if ( nEnd >= nStart )
  {
    ScrollInfo.cbSize = sizeof(SCROLLINFO);
    m_hWndScrollBarRightRight = thisIn->m_hWndScrollBarRightRight;
    ScrollInfo.nTrackPos = 0;
    _mm_storeu_si128(&ScrollInfo.nMin, 0i64);
    ScrollInfo.fMask = SIF_POS;
    GetScrollInfo(m_hWndScrollBarRightRight, SB_CTL, &ScrollInfo);
    hDC = GetDC(v3->m_hWnd);
    SelectObject(hDC, v3->m_Font);
    GetTextMetricsW(hDC, &tm);
    nHeigth = tm.tmHeight;
    ReleaseDC(this->m_hWnd, hDC);
    if ( this->m_ImageList )
    {
      v7 = GetSystemMetrics(SM_CYSMICON);
      if ( nHeigth < v7 )
        nHeigth = v7;
    }
    nTotalHeight = nHeigth + this->m_nHeight;
    GetWindowRect(this->m_hWndHeaderLeft, &Rect);
    GetClientRect(this->m_hWnd, &rcClient);
    rcClient.top = Rect.bottom + nTotalHeight * (nStart - ScrollInfo.nPos) - Rect.top;
    rcClient.bottom = Rect.bottom
                    + nTotalHeight * (nStart - ScrollInfo.nPos)
                    - Rect.top
                    + nTotalHeight * (nEnd - nStart + 1);
    InvalidateRect(this->m_hWnd, &rcClient, 0);
  }
}

//----- (00FFEBF0) --------------------------------------------------------
ATOM CTreeList::Register()
{
  WNDCLASSEXW v1; // [esp+0h] [ebp-30h]

  memset(&v1.style, 0, 0x2Cu);
  v1.cbSize = 48;
  v1.lpfnWndProc = CTreeList::WndProc;
  v1.hCursor = LoadCursorW(0, 0x7F00);
  v1.hbrBackground = 0;
  v1.lpszMenuName = 0;
  v1.style = 8;
  v1.lpszClassName = L"TreeListWindowClass";
  return RegisterClassExW(&v1);
}
// 10941A4: using guessed type wchar_t aTreelistwindow[20];

//----- (00FFEC50) --------------------------------------------------------
int __cdecl CTreeList::RepositionTooltips()
{
  CTreeList *v0; // ecx
  CTreeList *this; // esi
  HWND m_hWndScrollBarRightBottom; // ST10_4
  HWND m_hWndScrollBarRightRight; // ST14_4
  int v4; // eax
  LONG right; // edx
  HWND m_hWndHeaderRight; // eax
  tagTOOLINFOW ToolInfo; // [esp+4h] [ebp-70h]
  struct tagRECT rcClient; // [esp+34h] [ebp-40h]
  struct tagSCROLLINFO ScrollInfo; // [esp+44h] [ebp-30h]
  struct tagRECT rcWindow; // [esp+60h] [ebp-14h]

  this = v0;
  GetClientRect(v0->m_hWnd, &rcClient);
  GetWindowRect(this->m_hWndHeaderRight, &rcWindow);
  ScrollInfo.cbSize = sizeof(SCROLLINFO);
  m_hWndScrollBarRightBottom = this->m_hWndScrollBarRightBottom;
  ScrollInfo.nTrackPos = 0;
  _mm_storeu_si128(&ScrollInfo.nMin, 0i64);
  ScrollInfo.fMask = SIF_POS;
  GetScrollInfo(m_hWndScrollBarRightBottom, SB_CTL, &ScrollInfo);
  rcWindow.left = this->m_nBottomScrollBarWidthOrHeight - ScrollInfo.nPos;
  m_hWndScrollBarRightRight = this->m_hWndScrollBarRightRight;
  rcWindow.right = rcClient.right - rcClient.left;
  rcWindow.bottom -= rcWindow.top;
  rcWindow.top = 0;
  if ( (GetWindowLongW(m_hWndScrollBarRightRight, -16) >> 28) & 1 )
  {
    v4 = GetSystemMetrics(SM_CXVSCROLL);
    right = rcWindow.right - v4;
    rcWindow.right -= v4;
  }
  else
  {
    right = rcWindow.right;
  }
  SetWindowPos(
    this->m_hWndHeaderRight,
    0,
    rcWindow.left,
    rcWindow.top,
    right - rcWindow.left,
    rcWindow.bottom - rcWindow.top,
    SWP_NOZORDER);
  m_hWndHeaderRight = this->m_hWndHeaderRight;
  ToolInfo.cbSize = 0x30;
  _mm_storeu_si128(&ToolInfo.hwnd, 0i64);
  ToolInfo.uFlags = 0;
  _mm_storeu_si128(&ToolInfo.rect.right, 0i64);
  ToolInfo.hwnd = m_hWndHeaderRight;
  *&ToolInfo.lParam = 0i64;
  GetClientRect(m_hWndHeaderRight, &ToolInfo.rect);
  // Sets a new bounding rectangle for a tool
  return SendMessageW(this->m_hWndTooltipOfRightHeader, TTM_NEWTOOLRECTW, 0, &ToolInfo);
}

//----- (00FFED70) --------------------------------------------------------
LRESULT __thiscall CTreeList::MoveHeaders(CTreeList *this, int a2)
{
  CTreeList *v2; // ebx
  HWND v3; // ST10_4
  LONG v4; // edx
  HWND v5; // ST00_4
  HWND v6; // eax
  LPARAM lParam; // [esp+8h] [ebp-8Ch]
  int v9; // [esp+Ch] [ebp-88h]
  HWND v10; // [esp+10h] [ebp-84h]
  struct tagRECT v11; // [esp+18h] [ebp-7Ch]
  __int64 v12; // [esp+30h] [ebp-64h]
  struct tagSCROLLINFO v13; // [esp+38h] [ebp-5Ch]
  struct tagSCROLLINFO v14; // [esp+54h] [ebp-40h]
  struct tagRECT Rect; // [esp+70h] [ebp-24h]
  struct tagRECT v16; // [esp+80h] [ebp-14h]

  v2 = this;
  this->m_nBottomScrollBarWidthOrHeight = a2;
  GetWindowRect(this->m_hWndHeaderLeft, &Rect);
  GetWindowRect(v2->m_hWndHeaderRight, &v16);
  MapWindowPoints(0, v2->m_hWnd, &Rect, 2u);
  MapWindowPoints(0, v2->m_hWnd, &v16, 2u);
  v3 = v2->m_hWndScrollBarLeftBottom;
  v13.cbSize = 28;
  _mm_storeu_si128(&v13.nMin, 0i64);
  v13.nTrackPos = 0;
  v14.cbSize = 28;
  _mm_storeu_si128(&v14.nMin, 0i64);
  v14.nTrackPos = 0;
  v13.fMask = 4;
  v14.fMask = 4;
  GetScrollInfo(v3, 2, &v13);
  GetScrollInfo(v2->m_hWndScrollBarRightBottom, 2, &v14);
  v4 = v2->m_nBottomScrollBarWidthOrHeight;
  v16.left = v2->m_nBottomScrollBarWidthOrHeight - v14.nPos;
  Rect.left = 0;
  v5 = v2->m_hWndHeaderLeft;
  Rect.right = v4;
  SetWindowPos(v5, 0, 0, Rect.top, v4, Rect.bottom - Rect.top, SWP_NOZORDER);
  SetWindowPos(v2->m_hWndHeaderRight, 0, v16.left, v16.top, v16.right - v16.left, v16.bottom - v16.top, SWP_NOZORDER);
  lParam = 48;
  v9 = 0;
  v6 = v2->m_hWndHeaderRight;
  _mm_storeu_si128(&v10, 0i64);
  _mm_storeu_si128(&v11.right, 0i64);
  v10 = v6;
  v12 = 0i64;
  GetClientRect(v6, &v11);
  SendMessageW(v2->m_hWndTooltipOfRightHeader, TTM_NEWTOOLRECTW, 0, &lParam);
  v10 = v2->m_hWndHeaderLeft;
  GetClientRect(v10, &v11);
  return SendMessageW(v2->m_hWndTooltipOfLeftHeader, TTM_NEWTOOLRECTW, 0, &lParam);
}

//----- (00FFEF00) --------------------------------------------------------
int __thiscall CTreeList::OnSize(CTreeList *this)
{
  CTreeList *v1; // ebx
  bool v2; // al
  int result; // eax
  char fHide; // [esp+Bh] [ebp-45h]
  char fSBVisible; // [esp+Fh] [ebp-41h]
  bool v6; // [esp+13h] [ebp-3Dh]
  SCROLLINFO ScrollInfoRight; // [esp+14h] [ebp-3Ch]
  SCROLLINFO ScrollInfoBottom; // [esp+30h] [ebp-20h]

  v1 = this;
  CTreeList::GetScrollInfos(this, &ScrollInfoRight, &ScrollInfoBottom);
  fHide = ScrollInfoRight.nPage <= ScrollInfoRight.nMax;
  fSBVisible = ScrollInfoBottom.nPage <= ScrollInfoBottom.nMax;
  v6 = CTreeList::UpdateRightRightSB(
         v1,
         ScrollInfoRight.nPage <= ScrollInfoRight.nMax,
         ScrollInfoBottom.nPage <= ScrollInfoBottom.nMax);
  CTreeList::UpdateLeftBottomSB(v1, v1->m_hWndScrollBarRightBottom, fSBVisible, fHide);
  v2 = fHide && fSBVisible;
  result = CTreeList::ShowCaption(v1, v2);
  if ( fHide )
  {
    SetScrollInfo(v1->m_hWndScrollBarRightRight, 2, &ScrollInfoRight, 1);
    result = CTreeList::UpdateVScrollBars(v1, 0);
  }
  if ( fSBVisible )
  {
    SetScrollInfo(v1->m_hWndScrollBarRightBottom, 2, &ScrollInfoBottom, 1);
    result = CTreeList::UpdateHeaderPos(v1, v1->m_hWndScrollBarRightBottom, 0);
  }
  if ( v6 )
    result = CTreeList::RepositionTooltips();
  return result;
}

//----- (00FFEFD0) --------------------------------------------------------
int __cdecl CTreeList::RepositionHeaders()
{
  CTreeList *v0; // ecx
  CTreeList *v1; // esi
  int v2; // edi
  bool v3; // bl
  int result; // eax
  HWND v5; // ST00_4
  UINT v6; // [esp+8h] [ebp-34h]
  struct tagRECT Rect; // [esp+Ch] [ebp-30h]
  SCROLLINFO v8; // [esp+1Ch] [ebp-20h]

  v1 = v0;
  if ( v0->field_9C )
  {
    GetClientRect(v0->m_hWnd, &Rect);
    v2 = v1->m_nChildWidthLast;
    v3 = v2 > v1->m_nBottomScrollBarWidthOrHeight;
    v6 = v1->m_nBottomScrollBarWidthOrHeight;
    LOBYTE(result) = CTreeList::UpdateLeftBottomSB(v1, v1->m_hWndScrollBarLeftBottom, v3, 0);
    if ( v3 )
    {
      v8.cbSize = 28;
      _mm_storeu_si128(&v8.nMin, 0i64);
      v8.nTrackPos = 0;
      v8.nMax = v2 - 1;
      v8.nPage = v6;
      v5 = v1->m_hWndScrollBarLeftBottom;
      v8.fMask = 3;
      v8.nMin = 0;
      SetScrollInfo(v5, 2, &v8, 1);
      result = CTreeList::UpdateHeaderPos(v1, v1->m_hWndScrollBarLeftBottom, 0);
    }
  }
  return result;
}

//----- (00FFF090) --------------------------------------------------------
void __thiscall CTreeList::RedrawChild(CTreeList *pThis, tagTreeViewChildItem *pItem)
{
  CTreeList *this; // esi
  tagTreeViewChildItem *pChildLast; // ebx
  int nPos; // eax
  int v5; // eax

  this = pThis;
  pChildLast = pThis->m_ChildLast;
  if ( pItem != pChildLast )
  {
    if ( pChildLast )
    {
      pChildLast->m_dwStyle &= -TVIF_IMAGE;
      nPos = CTreeList::FindChild(pThis, pThis->m_ChildLast);
      if ( nPos >= 0 )
        CTreeList::RedrawZone(this, nPos, nPos);
      this->m_ChildLast = 0;
    }
    if ( pItem )
    {
      pItem->m_dwStyle |= TVIF_TEXT;
      v5 = CTreeList::FindChild(this, pItem);
      if ( v5 >= 0 )
        CTreeList::RedrawZone(this, v5, v5);
      this->m_ChildLast = pItem;
    }
    CTreeList::SendNotify(this, this->m_hWnd, 2000, 0, pItem, pChildLast, 0);
  }
}

//----- (00FFF110) --------------------------------------------------------
LRESULT __thiscall sub_FFF110(HWND *this, int a2, int a3)
{
  LRESULT result; // eax
  LPARAM lParam; // [esp+0h] [ebp-2Ch]
  int v5; // [esp+4h] [ebp-28h]

  v5 = a3;
  lParam = 1;
  if ( a2 )
    result = SendMessageW(this[5], 0x120Cu, a2 - 1, &lParam);
  else
    result = SendMessageW(this[3], 0x120Cu, 0, &lParam);
  return result;
}

//----- (00FFF160) --------------------------------------------------------
int __stdcall CTreeList::OnMsg2000(tagTreeViewChildItem *pItem, char a2)
{
  int result; // eax

  result = pItem;
  if ( a2 )
  {
    pItem->m_dwStyle |= 0x40u;
    if ( !pItem->m_nCount )
      pItem->m_dwStyle &= -0x11u;
  }
  else
  {
    pItem->m_dwStyle &= -0x41u;
  }
  return result;
}

//----- (00FFF190) --------------------------------------------------------
LRESULT __thiscall CTreeList::SetSortFlagsImageList(CTreeList *this, LPARAM lParam, int a3, int a4)
{
  CTreeList *v4; // ebx
  HWND v5; // ST00_4

  v4 = this;
  v5 = this->m_hWndHeaderLeft;
  this->field_B4 = a3;
  this->field_B8 = a4;
  SendMessageW(v5, HDM_SETIMAGELIST, 0, lParam);
  return SendMessageW(v4->m_hWndHeaderRight, HDM_SETIMAGELIST, 0, lParam);
}

//----- (00FFF1E0) --------------------------------------------------------
char __thiscall CTreeList::ResetImageList(CTreeList *this, int a2, char a3)
{
  CTreeList *v3; // esi
  char result; // al

  v3 = this;
  if ( this->m_ImageList && !LOBYTE(this->m_NotMyImageList) )
    ImageList_Destroy(this->m_ImageList);
  v3->m_ImageList = a2;
  result = a3;
  LOBYTE(v3->m_NotMyImageList) = a3;
  return result;
}

//----- (00FFF210) --------------------------------------------------------
int __thiscall sub_FFF210(CTreeList *this, int a2)
{
  int result; // eax

  result = a2;
  this->m_nHeight = a2;
  return result;
}

//----- (00FFF230) --------------------------------------------------------
int __thiscall sub_FFF230(CTreeList *this, int a2)
{
  int result; // eax

  result = a2;
  this->field_74 = a2;
  return result;
}

//----- (00FFF240) --------------------------------------------------------
BOOL __thiscall CTreeList::ShowCaption(CTreeList *this, char fVisible)
{
  CTreeList *v2; // edi
  int v3; // eax
  struct tagRECT rcClient; // [esp+4h] [ebp-14h]

  v2 = this;
  if ( !fVisible )
    return ShowWindow(this->m_hWndStatic, SW_HIDE);
  GetClientRect(this->m_hWnd, &rcClient);
  rcClient.left = rcClient.right - GetSystemMetrics(SM_CXVSCROLL);
  v3 = GetSystemMetrics(SM_CYHSCROLL);
  rcClient.top = rcClient.bottom - v3;
  return SetWindowPos(
           v2->m_hWndStatic,
           0,
           rcClient.left,
           rcClient.bottom - v3,
           rcClient.right - rcClient.left,
           v3,
           SWP_SHOWWINDOW|SWP_NOZORDER);
}

//----- (00FFF2D0) --------------------------------------------------------
bool __thiscall CTreeList::UpdateLeftBottomSB(CTreeList *this, HWND hWnd, char a3, char a4)
{
  CTreeList *v4; // esi
  char v5; // al
  bool v6; // bl
  int v7; // eax
  HWND v8; // ecx
  int v9; // esi
  int v10; // ebx
  int v11; // eax
  bool result; // al
  int v13; // [esp+Ch] [ebp-40h]
  int v14; // [esp+10h] [ebp-3Ch]
  int X; // [esp+14h] [ebp-38h]
  bool v16; // [esp+1Bh] [ebp-31h]
  SCROLLINFO v17; // [esp+1Ch] [ebp-30h]
  struct tagRECT rcClient; // [esp+38h] [ebp-14h]

  v4 = this;
  GetClientRect(this->m_hWnd, &rcClient);
  v5 = (GetWindowLongW(hWnd, -16) >> 28) & 1;
  v6 = v5 != a3;
  v16 = v5 != a3;
  if ( a3 )
  {
    v14 = GetSystemMetrics(SM_CYHSCROLL);
    v7 = GetSystemMetrics(SM_CXVSCROLL);
    v8 = v4->m_hWndScrollBarLeftBottom;
    v13 = v7;
    if ( hWnd == v8 )
      X = 0;
    else
      X = v4->m_nBottomScrollBarWidthOrHeight;
    if ( hWnd == v8 )
      v9 = v4->m_nBottomScrollBarWidthOrHeight;
    else
      v9 = rcClient.right - rcClient.left;
    v10 = rcClient.bottom - rcClient.top - v14;
    v11 = v10 + GetSystemMetrics(3);
    if ( a4 )
      v9 -= v13;
    SetWindowPos(hWnd, 0, X, v10, v9 - X, v11 - v10, SWP_SHOWWINDOW|SWP_NOZORDER);
    result = v16;
  }
  else
  {
    if ( v5 )
    {
      v17.cbSize = 28;
      v17.nTrackPos = 0;
      _mm_storeu_si128(&v17.nMin, 0i64);
      v17.fMask = 4;
      v17.nPos = 0;
      SetScrollInfo(hWnd, 2, &v17, 1);
      CTreeList::UpdateHeaderPos(v4, hWnd, 0);
      ShowWindow(hWnd, 0);
    }
    result = v6;
  }
  return result;
}

//----- (00FFF400) --------------------------------------------------------
bool __thiscall CTreeList::UpdateRightRightSB(CTreeList *this, bool fHide, bool fSBVisible)
{
  CTreeList *v3; // edi
  char bWindowVisible; // al
  bool v5; // bl
  int nLeft; // edx
  int nHeight; // eax
  bool result; // al
  HWND v9; // ST0C_4
  int v10; // [esp+8h] [ebp-34h]
  SCROLLINFO v11; // [esp+Ch] [ebp-30h]
  struct tagRECT Rect; // [esp+28h] [ebp-14h]

  v3 = this;
  GetClientRect(this->m_hWnd, &Rect);
  bWindowVisible = (GetWindowLongW(v3->m_hWndScrollBarRightRight, -16) >> 28) & 1;
  v5 = bWindowVisible != fHide;
  if ( fHide )
  {
    v10 = GetSystemMetrics(SM_CYHSCROLL);
    nLeft = Rect.right - Rect.left - GetSystemMetrics(SM_CXVSCROLL);
    nHeight = Rect.bottom - Rect.top;
    if ( fSBVisible )
      nHeight -= v10;
    SetWindowPos(
      v3->m_hWndScrollBarRightRight,
      0,
      nLeft,
      0,
      Rect.right - Rect.left - nLeft,
      nHeight,
      SWP_SHOWWINDOW|SWP_NOZORDER);
    result = v5;
  }
  else
  {
    if ( bWindowVisible )
    {
      v11.cbSize = 28;
      v9 = v3->m_hWndScrollBarRightRight;
      v11.nTrackPos = 0;
      _mm_storeu_si128(&v11.nMin, 0i64);
      v11.fMask = 4;
      v11.nPos = 0;
      SetScrollInfo(v9, 2, &v11, 1);
      CTreeList::UpdateVScrollBars(v3, 0);
      ShowWindow(v3->m_hWndScrollBarRightRight, 0);
    }
    result = v5;
  }
  return result;
}

//----- (00FFF500) --------------------------------------------------------
unsigned int __cdecl sub_FFF500(unsigned int *a1, unsigned int a2, int (__cdecl *a3)(_DWORD, _DWORD, int, int), int a4, int a5, int a6)
{
  unsigned int result; // eax
  unsigned int v7; // edi
  unsigned int v8; // ebx
  unsigned int v9; // eax
  unsigned int *v10; // esi
  unsigned int v11; // edi
  int v12; // eax

  if ( a2 > 1 )
  {
    v7 = a2 >> 1;
    v8 = sub_FFF500(a1, a2 >> 1, a3, a4, a5, a6);
    v9 = sub_FFF500(a1, a2 - v7, a3, a4, a5, a6);
    a2 = 0;
    v10 = &a2;
    v11 = v9;
    if ( !v8 )
      goto LABEL_12;
    while ( v11 )
    {
      v12 = a3(*(v8 + 4), *(v11 + 4), a4, a5);
      if ( a6 )
        v12 = -v12;
      if ( v12 > 0 )
      {
        *v10 = v11;
        v11 = *(v11 + 16);
      }
      else
      {
        *v10 = v8;
        v8 = *(v8 + 16);
      }
      v10 = (*v10 + 16);
      if ( !v8 )
        goto LABEL_12;
    }
    if ( v8 )
    {
      *v10 = v8;
      result = a2;
    }
    else
    {
LABEL_12:
      *v10 = v11;
      result = a2;
    }
  }
  else
  {
    result = *a1;
    if ( *a1 )
    {
      *a1 = *(result + 16);
      *(result + 16) = 0;
    }
  }
  return result;
}

//----- (00FFF5C0) --------------------------------------------------------
LRESULT __stdcall CTreeList::Proxy_HeaderWndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
  CTreeList *v4; // eax
  LRESULT result; // eax

  v4 = GetPropW(hWnd, gAtomTreeListProperty);
  if ( v4 )
    result = CTreeList::HeaderWndProc(v4, hWnd, Msg, wParam, lParam);
  else
    result = CallWindowProcW(MEMORY[0xC8], hWnd, Msg, wParam, lParam);
  return result;
}
// 10C4DA0: using guessed type __int16 gAtomTreeListProperty;

//----- (00FFF610) --------------------------------------------------------
LRESULT __stdcall CTreeList::Proxy_TooltipWndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
  CTreeList *v4; // eax
  LRESULT lResult; // ecx

  v4 = GetPropW(hWnd, gAtomTreeListProperty);
  lResult = 0;
  if ( Msg != WM_TIMER )
    return CallWindowProcW(v4->m_TooltipWndProc, hWnd, Msg, wParam, lParam);
  if ( !v4->m_bSkipTimerForTooltip )
    lResult = CallWindowProcW(v4->m_TooltipWndProc, hWnd, WM_TIMER, wParam, lParam);
  return lResult;
}
// 10C4DA0: using guessed type __int16 gAtomTreeListProperty;

//----- (00FFF680) --------------------------------------------------------
HWND __stdcall CTreeList::WndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
  CTreeList *v4; // eax
  HWND result; // eax

  v4 = GetPropW(hWnd, gAtomTreeListProperty);
  if ( v4 )
    result = CTreeList::TreeWndProc(v4, hWnd, Msg, wParam, lParam);
  else
    result = DefWindowProcW(hWnd, Msg, wParam, lParam);
  return result;
}
// 10C4DA0: using guessed type __int16 gAtomTreeListProperty;

//----- (00FFF6C0) --------------------------------------------------------
tagTreeViewChildItem *__thiscall CTreeList::GetCurScrollChildItem(CTreeList *this)
{
  CTreeList *pThis; // esi
  HWND v2; // ST00_4
  tagTreeViewChildItem *pChildren; // ecx
  int nIndex; // esi
  tagTreeViewChildItem *pCurrent; // eax
  struct tagSCROLLINFO ScrollInfo; // [esp+4h] [ebp-20h]

  ScrollInfo.cbSize = 28;
  pThis = this;
  ScrollInfo.nTrackPos = 0;
  ScrollInfo.fMask = 4;
  v2 = this->m_hWndScrollBarRightRight;
  _mm_storeu_si128(&ScrollInfo.nMin, 0i64);
  GetScrollInfo(v2, 2, &ScrollInfo);
  pChildren = pThis->m_Child;
  nIndex = 0;
  if ( !pChildren )
    return 0;
  do
  {
    if ( nIndex >= ScrollInfo.nPos )
      break;
    if ( pChildren->m_Next && (pChildren->m_dwStyle >> 4) & 1 )
    {
      pChildren = pChildren->m_Next;
    }
    else if ( pChildren->m_Prev )
    {
      pChildren = pChildren->m_Prev;
    }
    else
    {
      pCurrent = pChildren->m_Current;
      if ( pCurrent )
      {
        while ( !pCurrent->m_Prev )
        {
          pCurrent = pCurrent->m_Current;
          if ( !pCurrent )
            goto LABEL_11;
        }
        pChildren = pCurrent->m_Prev;
      }
      else
      {
LABEL_11:
        pChildren = 0;
      }
    }
    ++nIndex;
  }
  while ( pChildren );
  return pChildren;
}

//----- (00FFF780) --------------------------------------------------------
int __thiscall CTreeList::GetRightScrollbarPos(CTreeList *this)
{
  HWND v1; // ST00_4
  struct tagSCROLLINFO v3; // [esp+0h] [ebp-20h]

  v3.cbSize = 28;
  v1 = this->m_hWndScrollBarRightRight;
  v3.nTrackPos = 0;
  _mm_storeu_si128(&v3.nMin, 0i64);
  v3.fMask = 4;
  GetScrollInfo(v1, 2, &v3);
  return v3.nPos;
}

//----- (00FFF7D0) --------------------------------------------------------
bool __thiscall CTreeList::InitHeaderColumn(CTreeList *this, HWND hWnd, char a3)
{
  CTreeList *v3; // ebx
  HWND v4; // eax
  HWND v5; // edi
  WPARAM v6; // esi
  bool v7; // zf
  void (__stdcall *v8)(HWND, UINT, WPARAM, LPARAM); // ecx
  HWND v9; // eax
  HWND v10; // esi
  signed int v11; // ecx
  LPARAM lParam; // [esp+Ch] [ebp-30h]
  unsigned int v14; // [esp+20h] [ebp-1Ch]
  int v15; // [esp+28h] [ebp-14h]
  bool a2; // [esp+3Bh] [ebp-1h]
  HWND hWnda; // [esp+44h] [ebp+8h]
  bool v18; // [esp+4Bh] [ebp+Fh]

  v3 = this;
  v4 = sub_FFC8A0(this, &a2);
  v5 = hWnd;
  v6 = v4;
  if ( hWnd == v4 )
    v7 = a2 == 0;
  else
    v7 = a3 == 0;
  v8 = SendMessageW;
  v18 = v7;
  if ( v4 >= 0 )
  {
    if ( v4 )
    {
      v9 = v3->m_hWndHeaderRight;
      --v6;
    }
    else
    {
      v9 = v3->m_hWndHeaderLeft;
    }
    hWnda = v9;
    lParam = 4;
    SendMessageW(v9, 0x120Bu, v6, &lParam);
    if ( gbBitmapOnRight )
      v14 &= 0xFFFFF9FF;
    else
      v14 &= 0xFFFFE7FF;
    SendMessageW(hWnda, 0x120Cu, v6, &lParam);
    v8 = SendMessageW;
  }
  if ( v5 >= 0 )
  {
    if ( v5 )
    {
      v10 = v3->m_hWndHeaderRight;
      v5 = (v5 - 1);
    }
    else
    {
      v10 = v3->m_hWndHeaderLeft;
    }
    lParam = 36;
    v8(v10, 0x120Bu, v5, &lParam);
    if ( gbBitmapOnRight )
    {
      v11 = 1024;
      lParam = 4;
      if ( v18 )
        v11 = 512;
      v14 = v14 & 0xFFFFF9FF | v11;
    }
    else
    {
      v14 |= 0x1800u;
      if ( v18 )
        v15 = v3->field_B8;
      else
        v15 = v3->field_B4;
    }
    SendMessageW(v10, 0x120Cu, v5, &lParam);
  }
  return v18;
}
// 10CA8F8: using guessed type char gbBitmapOnRight;

//----- (00FFF8F0) --------------------------------------------------------
LRESULT __thiscall CTreeList::PopTooltip(CTreeList *this, HWND hWnd, POINT *pt)
{
  CTreeList *v3; // esi
  tagTreeViewChildItem *v4; // ecx
  LRESULT result; // eax
  int xx; // [esp+4h] [ebp-Ch]
  WPARAM nHeaderItemCount; // [esp+8h] [ebp-8h]
  tagTreeViewChildItem *pChild; // [esp+Ch] [ebp-4h]

  xx = 0;
  nHeaderItemCount = 0;
  pChild = 0;
  v3 = this;
  CTreeList::Query(this, pt->x, pt->y, &xx, &nHeaderItemCount, &pChild);
  v4 = pChild;
  result = nHeaderItemCount;
  if ( v3->m_point.y != pChild || nHeaderItemCount != v3->m_nHeaderItemCount )
  {
    v3->m_nHeaderItemCount = nHeaderItemCount;
    v3->m_point.x = xx;
    v3->m_point.y = v4;
    result = SendMessageW(hWnd, TTM_POP, 0, 0);
  }
  return result;
}

//----- (00FFF970) --------------------------------------------------------
unsigned int __thiscall CTreeList::UpdateVScrollBars(CTreeList *this, int nPos)
{
  CTreeList *v2; // ebx
  unsigned int result; // eax
  int v4; // esi
  int v5; // edi
  int v6; // [esp+4h] [ebp-54h]
  struct tagRECT v7; // [esp+8h] [ebp-50h]
  struct tagRECT Rect; // [esp+18h] [ebp-40h]
  RECT prcScroll; // [esp+28h] [ebp-30h]
  SCROLLINFO ScrollInfo; // [esp+38h] [ebp-20h]

  v2 = this;
  result = GetWindowLongW(this->m_hWndScrollBarRightRight, GWL_STYLE) >> 28;
  if ( result & 1 )
  {
    ScrollInfo.cbSize = 28;
    ScrollInfo.nTrackPos = 0;
    ScrollInfo.fMask = 4;
    _mm_storeu_si128(&ScrollInfo.nMin, 0i64);
    if ( nPos )
    {
      GetScrollInfo(v2->m_hWndScrollBarRightRight, 2, &ScrollInfo);
      ScrollInfo.nPos += nPos;
      SetScrollInfo(v2->m_hWndScrollBarRightRight, 2, &ScrollInfo, 1);
    }
    GetScrollInfo(v2->m_hWndScrollBarRightRight, 2, &ScrollInfo);
    result = ScrollInfo.nPos;
    v6 = ScrollInfo.nPos;
    if ( ScrollInfo.nPos != v2->m_nLastVScrollPos )
    {
      v4 = CTreeList::GetLineHeight(v2);
      GetClientRect(v2->m_hWnd, &Rect);
      v5 = v2->m_nLastVScrollPos - v6;
      v2->m_nLastVScrollPos = v6;
      prcScroll.left = Rect.left;
      GetWindowRect(v2->m_hWndHeaderLeft, &v7);
      prcScroll.top = v7.bottom - v7.top;
      prcScroll.right = Rect.right;
      prcScroll.bottom = Rect.bottom;
      result = ScrollWindowEx(v2->m_hWnd, 0, v4 * v5, &prcScroll, 0, 0, 0, 2u);
    }
  }
  return result;
}

//----- (00FFFA80) --------------------------------------------------------
unsigned int __userpurge CTreeList::SetVScrollPos@<eax>(CTreeList *this@<ecx>, int a2, int a3)
{
  CTreeList *v3; // esi
  HWND v4; // ST00_4
  SCROLLINFO v6; // [esp+0h] [ebp-20h]

  _mm_storeu_si128(&v6.nMin, 0i64);
  v6.nPos = a2;
  v3 = this;
  v6.cbSize = 28;
  v4 = this->m_hWndScrollBarRightRight;
  v6.nTrackPos = 0;
  v6.fMask = 4;
  SetScrollInfo(v4, 2, &v6, 1);
  return CTreeList::UpdateVScrollBars(v3, 0);
}

//----- (00FFFAF0) --------------------------------------------------------
HWND __thiscall CTreeList::TreeWndProc(CTreeList *this, HWND hWndIn, UINT Msg, WPARAM wParamIn, LPARAM lParam)
{
  CTreeList *pThis; // esi
  HWND *lParam_1; // edi
  HWND result; // eax
  HWND v8; // ST18_4
  unsigned int uMsg; // ecx
  LONG dwStyle; // eax
  int dxx; // ecx
  int m_nBottomScrollBarWidthOrHeight; // edx
  int v13; // edi
  int v14; // edi
  HWND hWndHeaderLeft; // ST10_4
  HCURSOR hCursor; // eax
  bool v17; // zf
  HCURSOR v18; // ecx
  int v19; // eax
  HWND hWnd_1; // edx
  HWND v21; // eax
  HCURSOR v22; // ST1C_4
  LRESULT v23; // eax
  HWND v24; // edi
  WPARAM v25; // ecx
  BOOL v26; // edi
  HWND m_hWndHeaderLeft_1; // ST10_4
  HWND m_hWndHeaderLeft; // ST10_4
  HRGN v29; // eax
  HWND v30; // edi
  HWND v31; // eax
  int v32; // eax
  tagTreeViewChildItem *v33; // ST14_4
  LONG v34; // eax
  HWND v35; // ST14_4
  HWND v36; // ST1C_4
  HDC v37; // eax
  HFONT v38; // ST1C_4
  HGDIOBJ v39; // edi
  void *v40; // ST1C_4
  HDC v41; // edi
  Data_t_bstr_t *v42; // ecx
  HWND v43; // ecx
  HWND v44; // edx
  unsigned int v45; // eax
  int v46; // eax
  int v47; // eax
  BOOL v48; // eax
  char *v49; // eax
  int v50; // edi
  HWND v51; // eax
  HWND v52; // edx
  WINDOWPOS *v53; // edi
  int v54; // eax
  int v55; // eax
  WPARAM v56; // ST18_4
  HWND v57; // eax
  int v58; // edi
  int v59; // eax
  _DWORD *v60; // ecx
  tagTreeViewChildItem *v61; // eax
  signed int v62; // edi
  HWND v63; // ST14_4
  tagTreeViewChildItem **v64; // edi
  tagTreeViewChildItem **v65; // eax
  tagTreeViewChildItem **v66; // eax
  signed int v67; // edi
  tagTreeViewChildItem *v68; // ecx
  unsigned int v69; // edx
  unsigned int v70; // eax
  WINDOWPOS *v71; // edx
  signed int v72; // edi
  __int32 v73; // ecx
  int v74; // ecx
  BSTR **v75; // eax
  tagTreeViewChildItem **v76; // eax
  tagTreeViewChildItem **v77; // edx
  WINDOWPOS *v78; // eax
  _DWORD *v79; // eax
  UINT v80; // eax
  signed int v81; // eax
  HWND v82; // ST14_4
  tagTreeViewChildItem *v83; // edi
  LONG v84; // ecx
  int v85; // [esp-14h] [ebp-2E0h]
  Data_t_bstr_t *v86; // [esp-10h] [ebp-2DCh]
  tagTreeViewChildItem *v87; // [esp-Ch] [ebp-2D8h]
  int v88; // [esp+0h] [ebp-2CCh]
  _bstr_t v89; // [esp+Ch] [ebp-2C0h]
  HDLAYOUT Layout; // [esp+10h] [ebp-2BCh]
  LPARAM lParam_2; // [esp+18h] [ebp-2B4h]
  _bstr_t lpchText; // [esp+1Ch] [ebp-2B0h]
  bool v93; // [esp+23h] [ebp-2A9h]
  tagTreeViewChildItem **pChildItem; // [esp+24h] [ebp-2A8h]
  tagTreeViewChildItem *pChild; // [esp+28h] [ebp-2A4h]
  HWND hWnd; // [esp+2Ch] [ebp-2A0h]
  WPARAM wParam; // [esp+30h] [ebp-29Ch]
  HGDIOBJ ho; // [esp+34h] [ebp-298h]
  RECT prcScroll; // [esp+38h] [ebp-294h]
  WINDOWPOS WindowPos; // [esp+48h] [ebp-284h]
  int Paint; // [esp+64h] [ebp-268h]
  int ToolInfo; // [esp+74h] [ebp-258h]
  HDITEMW Item; // [esp+78h] [ebp-254h]
  __int64 v104; // [esp+9Ch] [ebp-230h]
  RECT Rect; // [esp+A4h] [ebp-228h]
  __int16 v106[260]; // [esp+B4h] [ebp-218h]
  int v107; // [esp+2C8h] [ebp-4h]

  pThis = this;
  lParam_1 = lParam;
  hWnd = hWndIn;
  wParam = wParamIn;
  lParam_2 = lParam;
  if ( Msg - LVM_FIRST <= 0xFF )
    return CTreeList::HandleListViewMsg(this, hWnd, Msg, wParamIn, lParam);
  if ( Msg - 512 <= 0xD )
  {
    Rect.right = lParam;
    Rect.bottom = SHIWORD(lParam);
    Item.cchTextMax = hWnd;
    v8 = this->m_hWndTooltipOfTreeList;
    Item.lParam = wParamIn;
    Item.fmt = Msg;
    Item.iImage = lParam;
    *&Item.iOrder = 0i64;
    HIDWORD(v104) = 0;
    CTreeList::PopTooltip(this, v8, &Rect.right);
    SendMessageW(pThis->m_hWndTooltipOfTreeList, TTM_RELAYEVENT, 0, &Item.cchTextMax);
  }
  uMsg = Msg;
  if ( Msg == WM_LBUTTONDOWN )
  {
    if ( LOBYTE(pThis->field_BC) )
    {
      ho = lParam;
      if ( abs(lParam - pThis->m_nBottomScrollBarWidthOrHeight) <= 8 )
      {
        SetCapture(hWnd);
        SetCursor(pThis->m_hCursor);
        pThis->m_ptDownLast.x = ho;
LABEL_9:
        SetFocus(hWnd);
        Rect.bottom = 0;
        pChild = 0;
        dwStyle = CTreeList::Query(pThis, lParam, SHIWORD(lParam), &Rect.bottom, 0, &pChild);
        Rect.bottom = dwStyle;
        if ( dwStyle & (TVIF_INTEGRAL|TVIF_CHILDREN|TVIF_SELECTEDIMAGE) )
        {
          CTreeList::SendNotify(pThis, pThis->m_hWnd, -2, 0, pChild, 0, 0);
          LOWORD(dwStyle) = Rect.bottom;
        }
        if ( dwStyle & TVIF_CHILDREN )
        {
          CTreeList::OnMsg2001(pThis, pChild, ~(pChild->m_dwStyle >> 4) & 1);
        }
        else if ( dwStyle & (TVIF_STATEEX|TVIF_INTEGRAL|TVIF_CHILDREN|TVIF_SELECTEDIMAGE) )
        {
          CTreeList::RedrawChild(pThis, pChild);
        }
        return (pThis->baseclass.vtptr->HandleMessage)(pThis, hWnd, Msg, wParam, lParam_1);
      }
      goto LABEL_40;
    }
LABEL_32:
    hWnd_1 = hWnd;
    goto LABEL_33;
  }
  if ( Msg == WM_MOUSEMOVE )
  {
    if ( LOBYTE(pThis->field_BC) )
    {
      pChild = lParam;
      if ( GetCapture() == hWnd && wParam & 1 )
      {
        dxx = pChild - pThis->m_ptDownLast.x;
        if ( pChild != pThis->m_ptDownLast.x )
        {
          m_nBottomScrollBarWidthOrHeight = pThis->m_nBottomScrollBarWidthOrHeight;
          v13 = pThis->field_94;
          if ( m_nBottomScrollBarWidthOrHeight + dxx < v13 )
            dxx = v13 - m_nBottomScrollBarWidthOrHeight;
          pThis->m_ptDownLast.x += dxx;
          v14 = m_nBottomScrollBarWidthOrHeight + dxx;
          CTreeList::MoveHeaders(pThis, m_nBottomScrollBarWidthOrHeight + dxx);
          Item.mask = 1;
          hWndHeaderLeft = pThis->m_hWndHeaderLeft;
          Item.cxy = v14;
          SendMessageW(hWndHeaderLeft, HDM_SETITEMW, 0, &Item);
          CTreeList::OnSize(pThis);
          lParam_1 = lParam_2;
        }
        SetCursor(pThis->m_hCursor);
        uMsg = WM_MOUSEMOVE;
        goto LABEL_209;
      }
      if ( abs(pChild - pThis->m_nBottomScrollBarWidthOrHeight) <= 8 )
      {
        SetCursor(pThis->m_hCursor);
        uMsg = WM_MOUSEMOVE;
        goto LABEL_209;
      }
      hCursor = GetClassLongW(pThis->m_hWnd, GCL_HCURSOR);
      v17 = pThis->m_pfnGetChildCursor == 0;
      v18 = hCursor;
      ho = hCursor;
      if ( !v17 )
      {
        Layout.pwpos = 0;
        lpchText.m_Data = 0;
        pChildItem = 0;
        CTreeList::Query(pThis, pChild, SHIWORD(lParam), &Layout.pwpos, &lpchText, &pChildItem);
        if ( pChildItem )
        {
          // typedef LRESULT(*LPFN_CALLBACK_D8)(tagTreeViewChildItem* pItem, _bstr_t str);
          v19 = (pThis->m_pfnGetChildCursor)(pChildItem, lpchText.m_Data);
          v18 = ho;
          if ( v19 )
            v18 = v19;
        }
        else
        {
          v18 = ho;
        }
      }
      SetCursor(v18);
      goto LABEL_31;
    }
    goto LABEL_32;
  }
  if ( Msg != WM_LBUTTONUP || !LOBYTE(pThis->field_BC) )
    goto LABEL_32;
  v21 = GetCapture();
  hWnd_1 = hWnd;
  if ( v21 == hWnd )
  {
    ReleaseCapture();
LABEL_40:
    v22 = GetClassLongW(pThis->m_hWnd, GCL_HCURSOR);
    SetCursor(v22);
LABEL_31:
    uMsg = Msg;
    goto LABEL_32;
  }
  uMsg = WM_LBUTTONUP;
LABEL_33:
  if ( uMsg > WM_KEYFIRST )
  {
    if ( uMsg > WM_MOUSEWHEEL )
    {
      switch ( uMsg )
      {
        case TREELIST_MSG_2000:
          CTreeList::OnMsg2000(wParam, lParam != 0);
          return 0;
        case TREELIST_MSG_2001:
          return CTreeList::OnMsg2001(pThis, wParam, lParam != 0);
        case TREELIST_MSG_2002:
          return *(wParam + 0x1C);
        case TREELIST_MSG_2003:
          CTreeList::RefreshChildItem(pThis, wParam);
          return 0;
        case TREELIST_MSG_2004:
          return CTreeList::OnMsg2004(*lParam, *(lParam + 4), *(lParam + 8));
        case TREELIST_MSG_2005:
          return CTreeList::FindChild(pThis, wParam);
        default:
          goto LABEL_82;
      }
      goto LABEL_82;
    }
    if ( uMsg == WM_MOUSEWHEEL )
    {
      Rect.bottom = pThis->m_nLastVScrollPos2 + SHIWORD(wParam);
      v84 = Rect.bottom;
      pThis->m_nLastVScrollPos2 = Rect.bottom;
      if ( abs(v84) >= 40 )
      {
        pThis->m_nLastVScrollPos2 = Rect.bottom - 40 * (v84 / 40);
        CTreeList::UpdateVScrollBars(pThis, Rect.bottom / -40);
      }
      return (pThis->baseclass.vtptr->HandleMessage)(pThis, hWnd, Msg, wParam, lParam_1);
    }
    if ( uMsg <= WM_VSCROLL )
    {
      if ( uMsg == WM_VSCROLL )
      {
        Item.cchTextMax = 28;
        v82 = pThis->m_hWndScrollBarRightRight;
        HIDWORD(v104) = 0;
        _mm_storeu_si128(&Item.lParam, 0i64);
        Item.fmt = 7;
        GetScrollInfo(v82, 2, &Item.cchTextMax);
        switch ( wParam )
        {
          case SB_HORZ:
            LODWORD(v104) = v104 - 1;
            CTreeList::SetVScrollPos(pThis, v104, v88);
            return (pThis->baseclass.vtptr->HandleMessage)(pThis, hWnd, Msg, wParam, lParam_1);
          case SB_VERT:
            LODWORD(v104) = v104 + 1;
            CTreeList::SetVScrollPos(pThis, v104, v88);
            return (pThis->baseclass.vtptr->HandleMessage)(pThis, hWnd, Msg, wParam, lParam_1);
          case SB_CTL:
            LODWORD(v104) = v104 - Item.iOrder;
            CTreeList::SetVScrollPos(pThis, v104, v88);
            return (pThis->baseclass.vtptr->HandleMessage)(pThis, hWnd, Msg, wParam, lParam_1);
          case SB_BOTH:
            LODWORD(v104) = Item.iOrder + v104;
            CTreeList::SetVScrollPos(pThis, v104, v88);
            return (pThis->baseclass.vtptr->HandleMessage)(pThis, hWnd, Msg, wParam, lParam_1);
          case SB_THUMBPOSITION:
          case SB_THUMBTRACK:
            LODWORD(v104) = wParam >> 16;
            CTreeList::SetVScrollPos(pThis, wParam >> 16, v88);
            return (pThis->baseclass.vtptr->HandleMessage)(pThis, hWnd, Msg, wParam, lParam_1);
          case SB_TOP:
            LODWORD(v104) = 0;
            CTreeList::SetVScrollPos(pThis, 0, v88);
            return (pThis->baseclass.vtptr->HandleMessage)(pThis, hWnd, Msg, wParam, lParam_1);
          case SB_BOTTOM:
            LODWORD(v104) = Item.iImage;
            CTreeList::SetVScrollPos(pThis, Item.iImage, v88);
            return (pThis->baseclass.vtptr->HandleMessage)(pThis, hWnd, Msg, wParam, lParam_1);
          case SB_ENDSCROLL:
            return 1;
          default:
            return 0;
        }
        return 0;
      }
      v73 = uMsg - WM_CHAR;
      if ( !v73 )
      {
        if ( pThis->m_nChildCount )
        {
          Layout.pwpos = GetTickCount();
          if ( Layout.pwpos - pThis->m_dwTickCountLast > 0x2EE )
            sub_FFA320(&pThis->field_D0, gszStatusBarText);
          if ( !pThis->m_ChildLast
            || ((v75 = _bstr_t::_bstr_t(&v89, gszStatusBarText),
                 v93 = sub_FFA3E0(&pThis->field_D0, v75),
                 _bstr_t::_Free(&v89),
                 !v93) ? (v76 = pThis->m_ChildLast) : (v76 = sub_FFE650(pThis->m_ChildLast)),
                (pChildItem = v76) == 0) )
          {
            pChildItem = pThis->m_Child;
          }
          pThis->m_dwTickCountLast = Layout.pwpos;
          ho = wParam;
          _bstr_t::_bstr_t(&lpchText, &ho);
          v107 = 0;
          _bstr_t::operator+=(&pThis->field_D0, &lpchText);
          v107 = -1;
          _bstr_t::_Free(&lpchText);
          v77 = pChildItem;
          pChild = pChildItem;
          while ( 1 )
          {
            Rect.bottom = 260;
            v78 = (*(v77[1]->m_TreeList + 8))(v77, 0, v106, &Rect.bottom);
            lParam_1 = lParam_2;
            Layout.pwpos = v78;
            v79 = pThis->field_D0;
            lpchText.m_Data = (v79 ? *v79 : 0);
            v80 = sub_FE0440(&pThis->field_D0);
            if ( !_wcsnicmp(Layout.pwpos, lpchText.m_Data, v80) )
              break;
            v77 = sub_FFE650(pChild);
            pChild = v77;
            if ( !v77 )
            {
              v77 = pThis->m_Child;
              pChild = pThis->m_Child;
            }
            if ( v77 == pChildItem )
              return (pThis->baseclass.vtptr->HandleMessage)(pThis, hWnd, Msg, wParam, lParam_1);
          }
          CTreeList::RedrawChild(pThis, pChild);
          v81 = CTreeList::FindChild(pThis, pChild);
          sub_FFBE30(pThis, v81);
        }
        return (pThis->baseclass.vtptr->HandleMessage)(pThis, hWnd, Msg, wParam, lParam_1);
      }
      v74 = v73 - 17;
      if ( !v74 )
      {
        if ( wParam == 100 )
        {
          GetCursorPos(&Rect.right);
          MapWindowPoints(0, hWnd, &Rect.right, 1u);
          CTreeList::PopTooltip(pThis, pThis->m_hWndTooltipOfTreeList, &Rect.right);
        }
        return (pThis->baseclass.vtptr->HandleMessage)(pThis, hWnd, Msg, wParam, lParam_1);
      }
      if ( v74 == 1 )
      {
        if ( !lParam )
          return (pThis->baseclass.vtptr->HandleMessage)(pThis, hWnd, Msg, wParam, lParam_1);
        Item.cchTextMax = 28;
        HIDWORD(v104) = 0;
        _mm_storeu_si128(&Item.lParam, 0i64);
        Item.fmt = 7;
        GetScrollInfo(lParam, 2, &Item.cchTextMax);
        switch ( wParam )
        {
          case SB_HORZ:
            LODWORD(v104) = v104 - 1;
            CTreeList::SetHScrollPos(pThis, lParam, v104);
            return (pThis->baseclass.vtptr->HandleMessage)(pThis, hWnd, Msg, wParam, lParam_1);
          case SB_VERT:
            LODWORD(v104) = v104 + 1;
            CTreeList::SetHScrollPos(pThis, lParam, v104);
            return (pThis->baseclass.vtptr->HandleMessage)(pThis, hWnd, Msg, wParam, lParam_1);
          case SB_CTL:
            LODWORD(v104) = v104 - Item.iOrder;
            CTreeList::SetHScrollPos(pThis, lParam, v104);
            return (pThis->baseclass.vtptr->HandleMessage)(pThis, hWnd, Msg, wParam, lParam_1);
          case SB_BOTH:
            LODWORD(v104) = Item.iOrder + v104;
            CTreeList::SetHScrollPos(pThis, lParam, v104);
            return (pThis->baseclass.vtptr->HandleMessage)(pThis, hWnd, Msg, wParam, lParam_1);
          case SB_THUMBPOSITION:
          case SB_THUMBTRACK:
            LODWORD(v104) = wParam >> 16;
            CTreeList::SetHScrollPos(pThis, lParam, wParam >> 16);
            return (pThis->baseclass.vtptr->HandleMessage)(pThis, hWnd, Msg, wParam, lParam_1);
          case SB_TOP:
            LODWORD(v104) = 0;
            CTreeList::SetHScrollPos(pThis, lParam, 0);
            return (pThis->baseclass.vtptr->HandleMessage)(pThis, hWnd, Msg, wParam, lParam_1);
          case SB_BOTTOM:
            LODWORD(v104) = Item.iImage;
            CTreeList::SetHScrollPos(pThis, lParam, Item.iImage);
            return (pThis->baseclass.vtptr->HandleMessage)(pThis, hWnd, Msg, wParam, lParam_1);
          case SB_ENDSCROLL:
            return 1;
          default:
            return 0;
        }
        return 0;
      }
LABEL_82:
      if ( Msg == WM_THEMECHANGED )
      {
        if ( pThis->baseclass.m_hThemeHandle )
          gpfnCloseThemeData(pThis->baseclass.m_hThemeHandle);
        pThis->baseclass.m_hThemeHandle = 0;
        if ( gpfnIsThemeActive && gpfnIsThemeActive() )
        {
          v47 = (pThis->baseclass.vtptr->GetName)(pThis);
          pThis->baseclass.m_hThemeHandle = gpfnOpenThemeData(hWnd, v47);
        }
      }
__HandleMessage:
      lParam_1 = lParam_2;
      return (pThis->baseclass.vtptr->HandleMessage)(pThis, hWnd, Msg, wParam, lParam_1);
    }
    if ( uMsg == WM_LBUTTONDOWN )
      goto LABEL_9;
LABEL_209:
    // WM_RBUTTONDOWN
    if ( uMsg - WM_LBUTTONDBLCLK <= 1 )
    {
      Rect.bottom = 0;
      lpchText.m_Data = 0;
      ho = 0;
      if ( CTreeList::Query(pThis, lParam_1, SHIWORD(lParam_1), &Rect.bottom, &lpchText, &ho) & (TVIF_INTEGRAL|TVIF_CHILDREN|TVIF_SELECTEDIMAGE) )
      {
        v83 = ho;
        CTreeList::RedrawChild(pThis, ho);
        v87 = v83;
        v86 = lpchText.m_Data;
        v85 = 2 * (Msg == WM_LBUTTONDBLCLK) - 5;
LABEL_81:
        CTreeList::SendNotify(pThis, pThis->m_hWnd, v85, v86, v87, 0, 0);
      }
    }
    goto LABEL_82;
  }
  if ( uMsg == WM_KEYFIRST )
  {
    v17 = LOBYTE(pThis->m_ptDownLast.y) == 0;
    v54 = 2007;
    Item.lParam = hWnd_1;
    if ( !v17 )
      v54 = -155;
    Item.iOrder = v54;
    v55 = GetWindowLongW(hWnd_1, -12);
    LOWORD(v104) = wParam;
    v56 = v55;
    Item.iImage = v55;
    *(&v104 + 2) = 0;
    v57 = GetParent(hWnd);
    SendMessageW(v57, 0x4Eu, v56, &Item.lParam);
    switch ( wParam )
    {
      case VK_PRIOR:
      case VK_NEXT:
        pChildItem = pThis->m_ChildLast;
        if ( !pChildItem )
          return (pThis->baseclass.vtptr->HandleMessage)(pThis, hWnd, Msg, wParam, lParam_1);
        Item.cchTextMax = 28;
        v63 = pThis->m_hWndScrollBarRightRight;
        HIDWORD(v104) = 0;
        _mm_storeu_si128(&Item.lParam, 0i64);
        Item.fmt = 2;
        GetScrollInfo(v63, 2, &Item.cchTextMax);
        ho = 0;
        if ( !Item.iOrder )
          goto LABEL_149;
        v64 = pChildItem;
        break;
      case VK_LEFT:
      case VK_RIGHT:
        v68 = pThis->m_ChildLast;
        if ( !v68 )
          return (pThis->baseclass.vtptr->HandleMessage)(pThis, hWnd, Msg, wParam, lParam_1);
        v69 = v68->m_dwStyle;
        v70 = v68->m_dwStyle;
        if ( wParam == 39 )
        {
          if ( !((v70 >> 6) & 1) )
            return (pThis->baseclass.vtptr->HandleMessage)(pThis, hWnd, Msg, wParam, lParam_1);
          if ( !((v69 >> 4) & 1) )
          {
            CTreeList::OnMsg2001(pThis, v68, 1);
            return (pThis->baseclass.vtptr->HandleMessage)(pThis, hWnd, Msg, wParam, lParam_1);
          }
          return CTreeList::TreeWndProc(pThis, hWnd, 0x100u, 0x28u, 0);
        }
        if ( (v70 >> 4) & 1 && (v69 >> 6) & 1 )
        {
          CTreeList::OnMsg2001(pThis, v68, 0);
          return (pThis->baseclass.vtptr->HandleMessage)(pThis, hWnd, Msg, wParam, lParam_1);
        }
        v71 = v68->m_Current;
        Layout.pwpos = v71;
        if ( v71 && v71 != &pThis->field_40 )
        {
          v72 = CTreeList::FindChild(pThis, v68);
          CTreeList::RedrawChild(pThis, Layout.pwpos);
          sub_FFBE30(pThis, v72);
          goto __HandleMessage;
        }
        return (pThis->baseclass.vtptr->HandleMessage)(pThis, hWnd, Msg, wParam, lParam_1);
      case VK_UP:
      case VK_DOWN:
        v60 = pThis->m_ChildLast;
        if ( !v60 )
          return (pThis->baseclass.vtptr->HandleMessage)(pThis, hWnd, Msg, wParam, lParam_1);
        v61 = (wParam == 40 ? sub_FFE650(v60) : sub_FFE9D0(v60));
        ho = v61;
        if ( !v61 )
          return (pThis->baseclass.vtptr->HandleMessage)(pThis, hWnd, Msg, wParam, lParam_1);
        v62 = CTreeList::FindChild(pThis, v61);
        CTreeList::RedrawChild(pThis, ho);
        sub_FFBE30(pThis, v62);
        goto __HandleMessage;
      case VK_ADD:
        if ( GetKeyState(VK_LCONTROL) )
        {
          if ( SendMessageW(pThis->m_hWndHeaderRight, HDM_GETITEMCOUNT, 0, 0) + 1 > 0 )
          {
            v58 = 0;
            do
            {
              if ( v58 || !pThis->field_9C )
                v59 = CTreeList::GetChildWidth(pThis, v58);
              else
                v59 = pThis->m_nChildWidthLast;
              sub_FFF110(pThis, v58++, v59);
            }
            while ( v58 < SendMessageW(pThis->m_hWndHeaderRight, 0x1200u, 0, 0) + 1 );
            lParam_1 = lParam_2;
          }
          CTreeList::OnSize(pThis);
        }
        return (pThis->baseclass.vtptr->HandleMessage)(pThis, hWnd, Msg, wParam, lParam_1);
      default:
        return (pThis->baseclass.vtptr->HandleMessage)(pThis, hWnd, Msg, wParam, lParam_1);
    }
    do
    {
      if ( wParam == VK_NEXT )
      {
        v65 = sub_FFE650(v64);
        if ( !v65 )
          break;
        v64 = v65;
        pChildItem = v65;
      }
      else
      {
        v66 = sub_FFE9D0(v64);
        if ( !v66 )
          break;
        v64 = v66;
        pChildItem = v66;
      }
      ho = ho + 1;
    }
    while ( ho < Item.iOrder );
    lParam_1 = lParam_2;
LABEL_149:
    if ( !pChildItem )
      return (pThis->baseclass.vtptr->HandleMessage)(pThis, hWnd, Msg, wParam, lParam_1);
    v67 = CTreeList::FindChild(pThis, pChildItem);
    CTreeList::RedrawChild(pThis, pChildItem);
    sub_FFBE30(pThis, v67);
    goto __HandleMessage;
  }
  switch ( uMsg )
  {
    case WM_DESTROY:
      CTreeList::OnDestroy(pThis);
      goto LABEL_82;
    case WM_SIZE:
      CTreeList::OnSize(pThis);
      CTreeList::RepositionHeaders();
      CTreeList::RepositionTooltips();
      v31 = pThis->m_hWnd;
      ToolInfo = 48;
      _mm_storeu_si128(&Item.cxy, 0i64);
      Item.mask = 0;
      _mm_storeu_si128(&Item.fmt, 0i64);
      Item.cxy = v31;
      v104 = 0i64;
      GetClientRect(v31, &Item.hbm);
      SendMessageW(pThis->m_hWndTooltipOfTreeList, TTM_NEWTOOLRECTW, 0, &ToolInfo);
      goto LABEL_82;
    case WM_ACTIVATE|WM_CREATE:
    case 8u:
      if ( pThis->m_ChildLast )
        CTreeList::RefreshChildItem(pThis, pThis->m_ChildLast);
      goto LABEL_82;
    case WM_SETVISIBLE|WM_DESTROY:
      if ( wParam )
      {
        v23 = DefWindowProcW(hWnd_1, uMsg, wParam, lParam);
        pThis->m_bSkipTimerForTooltip = 0;
        v24 = v23;
        CTreeList::Refresh(pThis);
        result = v24;
      }
      else
      {
        pThis->m_bSkipTimerForTooltip = 1;
        result = DefWindowProcW(hWnd_1, uMsg, 0, lParam);
      }
      return result;
    case WM_SETVISIBLE|WM_ACTIVATE:
      v29 = CreateRectRgn(0, 0, 0, 0);
      v30 = hWnd;
      ho = v29;
      if ( GetUpdateRgn(hWnd, v29, 0) != 1 )
      {
        BeginPaint(v30, &Paint);
        CTreeList::DrawTree(pThis, &Paint, ho);
        EndPaint(v30, &Paint);
      }
      DeleteObject(ho);
      return 0;
    case 0x14u:
      return 1;
    case 0x20u:
      if ( wParam != hWnd_1 )
        goto LABEL_82;
      return 1;
    case 0x30u:
      v25 = wParam;
      pThis->m_Font = wParam;
      v26 = lParam != 0;
      m_hWndHeaderLeft_1 = pThis->m_hWndHeaderLeft;
      v93 = lParam != 0;
      SendMessageW(m_hWndHeaderLeft_1, WM_SETFONT, v25, v26);
      SendMessageW(pThis->m_hWndHeaderRight, WM_SETFONT, pThis->m_Font, v26);
      SendMessageW(pThis->m_hWndTooltipOfTreeList, WM_SETFONT, pThis->m_Font, v26);
      SendMessageW(pThis->m_hWndTooltipOfLeftHeader, WM_SETFONT, pThis->m_Font, v26);
      SendMessageW(pThis->m_hWndTooltipOfRightHeader, WM_SETFONT, pThis->m_Font, v26);
      GetClientRect(pThis->m_hWnd, &Item.iImage);
      WindowPos.hwnd = 0;
      Layout.prc = &Item.iImage;
      *&WindowPos.cy = 0i64;
      Layout.pwpos = &WindowPos;
      m_hWndHeaderLeft = pThis->m_hWndHeaderLeft;
      _mm_storeu_si128(&WindowPos.hwndInsertAfter, 0i64);
      SendMessageW(m_hWndHeaderLeft, HDM_LAYOUT, 0, &Layout);
      SetWindowPos(
        pThis->m_hWndHeaderLeft,
        WindowPos.hwndInsertAfter,
        0,
        0,
        pThis->m_nBottomScrollBarWidthOrHeight,
        WindowPos.cy,
        WindowPos.flags | SWP_SHOWWINDOW);
      SetWindowPos(
        pThis->m_hWndHeaderRight,
        pThis->m_hWndHeaderLeft,
        pThis->m_nBottomScrollBarWidthOrHeight,
        0,
        WindowPos.cx - pThis->m_nBottomScrollBarWidthOrHeight,
        WindowPos.cy,
        WindowPos.flags | SWP_SHOWWINDOW);
      if ( !v93 )
        return 0;
      CTreeList::Refresh(pThis);
      return 0;
    case WM_NOTIFY:
      if ( *lParam != pThis->m_hWndTooltipOfTreeList )
        goto LABEL_69;
      v32 = *(lParam + 8);
      if ( v32 == TTN_GETDISPINFOW )
      {
        if ( pThis->m_point.y )
        {
          pChildItem = (lParam + 12);
          *(lParam + 12) = lParam + 16;
          v33 = pThis->m_point.y;
          ho = (lParam + 16);
          if ( CTreeList::SendNotify(pThis, pThis->m_hWnd, 2004, pThis->m_nHeaderItemCount, v33, 0, lParam + 12) )
            return 0;
          v34 = pThis->m_point.y;
          Layout.pwpos = 80;
          lpchText.m_Data = (*(**(v34 + 4) + 8))(v34, pThis->m_nHeaderItemCount, ho, &Layout.pwpos);
          WindowPos.y = 0;
          WindowPos.cx = 0;
          WindowPos.cy = GetSystemMetrics(78);
          WindowPos.flags = CTreeList::GetLineHeight(pThis);
          sub_FFC210(pThis, pThis->m_point.x, pThis->m_nHeaderItemCount, 1, 1, pThis->m_point.y, &prcScroll);
          Item.cchTextMax = 28;
          v35 = pThis->m_hWndScrollBarRightBottom;
          HIDWORD(v104) = 0;
          _mm_storeu_si128(&Item.lParam, 0i64);
          Item.fmt = 4;
          GetScrollInfo(v35, 2, &Item.cchTextMax);
          if ( prcScroll.left == pThis->m_nBottomScrollBarWidthOrHeight )
          {
            if ( v104 )
              return 0;
          }
          v36 = pThis->m_hWnd;
          pChild = (pThis->m_Format & 0xFFFB3FFF | 0x400);
          v37 = GetDC(v36);
          v38 = pThis->m_Font;
          ho = v37;
          v39 = SelectObject(v37, v38);
          DrawTextW(ho, lpchText.m_Data, -1, &WindowPos.y, pChild);
          v40 = v39;
          v41 = ho;
          SelectObject(ho, v40);
          ReleaseDC(pThis->m_hWnd, v41);
          v42 = &gszNullString;
          lParam_1 = lParam_2;
          if ( WindowPos.cy - WindowPos.y > prcScroll.right - prcScroll.left )
            v42 = lpchText.m_Data;
          *pChildItem = v42;
        }
        else
        {
          *(lParam + 12) = &gszNullString;
        }
      }
      else if ( v32 == TTN_SHOW )
      {
        sub_FFC210(pThis, pThis->m_point.x, pThis->m_nHeaderItemCount, 0, 1, pThis->m_point.y, &WindowPos.y);
        SendMessageW(pThis->m_hWndTooltipOfTreeList, 0x41Fu, 1u, &WindowPos.y);
        MapWindowPoints(pThis->m_hWnd, 0, &WindowPos.y, 2u);
        SetWindowPos(
          pThis->m_hWndTooltipOfTreeList,
          0,
          WindowPos.y,
          WindowPos.cx,
          0,
          0,
          SWP_NOACTIVATE|SWP_NOZORDER|SWP_NOSIZE);
        SendMessageW(pThis->m_hWndTooltipOfTreeList, 0x30u, pThis->m_Font, 0);
        CTreeList::SendNotify(
          pThis,
          pThis->m_hWndTooltipOfTreeList,
          2005,
          pThis->m_nHeaderItemCount,
          pThis->m_point.y,
          0,
          0);
        return 1;
      }
LABEL_69:
      v43 = *lParam_1;
      v44 = pThis->m_hWndHeaderLeft;
      if ( *lParam_1 != v44 && v43 != pThis->m_hWndHeaderRight )
        goto LABEL_82;
      v45 = lParam_1[2];
      if ( v45 > 0xFFFFFEC0 )
      {
        if ( v45 == -311 )
        {
          InvalidateRect(pThis->m_hWnd, 0, 0);
          return 0;
        }
        if ( v45 == -5 )
          CTreeList::SendNotify(pThis, v43, -5, 0, 0, 0, 0);
        goto LABEL_82;
      }
      if ( v45 != -320 )
      {
        switch ( v45 )
        {
          case 0xFFFFFEBB:
            v48 = v43 == pThis->m_hWndHeaderRight;
            v17 = (lParam_1[3] + v48) == 0;
            v49 = lParam_1[3] + v48;
            ho = v49;
            if ( v17 && pThis->field_9C )
            {
              v50 = pThis->m_nChildWidthLast;
            }
            else
            {
              v50 = CTreeList::GetChildWidth(pThis, v49);
              v49 = ho;
            }
            sub_FFF110(pThis, v49, v50);
            if ( !ho )
              CTreeList::MoveHeaders(pThis, v50);
            CTreeList::OnSize(pThis);
            break;
          case 0xFFFFFEBE:
            if ( v43 == v44 )
              v46 = 0;
            else
              v46 = lParam_1[3] + 1;
            v87 = 0;
            v86 = v46;
            v85 = 2003;
            goto LABEL_81;
          case 0xFFFFFEBF:
            CTreeList::OnSize(pThis);
            break;
        }
        goto LABEL_82;
      }
      v51 = lParam_1[5];
      if ( !(*v51 & 1) )
        goto LABEL_82;
      v52 = lParam_1[3];
      if ( !v52 && *(v51 + 1) < pThis->field_94 )
        return 1;
      Layout.pwpos = (v52 + (v43 == pThis->m_hWndHeaderRight));
      CTreeList::MapToHeader(pThis, Layout.pwpos, &WindowPos.y);
      GetClientRect(pThis->m_hWnd, &Item.iImage);
      ho = (WindowPos.y + *(lParam_1[5] + 1) - WindowPos.cy);
      if ( !ho )
        return 0;
      v53 = Layout.pwpos;
      prcScroll.top = WindowPos.flags;
      *&prcScroll.right = v104;
      prcScroll.left = WindowPos.cy;
      if ( !Layout.pwpos )
        prcScroll.left = WindowPos.cy - 1;
      if ( (GetWindowLongW(pThis->m_hWndScrollBarRightRight, -16) >> 28) & 1 )
        prcScroll.right -= GetSystemMetrics(2);
      ScrollWindowEx(pThis->m_hWnd, ho, 0, &prcScroll, 0, 0, 0, SWP_NOMOVE);
      if ( (v53 || !pThis->field_9C)
        && (Rect.left = WindowPos.y,
            Rect.top = WindowPos.flags,
            Rect.right = WindowPos.cy,
            Rect.bottom = HIDWORD(v104),
            InvalidateRect(pThis->m_hWnd, &Rect, 0),
            v53) )
      {
        CTreeList::OnSize(pThis);
        UpdateWindow(pThis->m_hWndScrollBarRightBottom);
        result = 0;
      }
      else
      {
        CTreeList::MoveHeaders(pThis, ho + WindowPos.cy);
        CTreeList::OnSize(pThis);
        CTreeList::RepositionHeaders();
        UpdateWindow(pThis->m_hWndHeaderRight);
        UpdateWindow(pThis->m_hWndScrollBarLeftBottom);
        UpdateWindow(pThis->m_hWndScrollBarRightBottom);
        result = 0;
      }
      break;
    case WM_NCDESTROY:
      if ( pThis->m_ImageList && !LOBYTE(pThis->m_NotMyImageList) )
        ImageList_Destroy(pThis->m_ImageList);
      SetPropW(hWnd, gAtomTreeListProperty, 0);
      CTreeList::~CTreeList(pThis);
      j__free(pThis);
      return DefWindowProcW(hWnd, Msg, wParam, lParam);
    case WM_GETDLGCODE:
      return (DefWindowProcW(hWnd_1, uMsg, wParam, lParam) | 1);
    default:
      goto LABEL_82;
  }
  return result;
}
// 10C4D84: using guessed type int (__stdcall *gpfnIsThemeActive)();
// 10C4DA0: using guessed type __int16 gAtomTreeListProperty;

//----- (010011F0) --------------------------------------------------------
CSystemProcessInfoMapNode *__thiscall sub_10011F0(std__tree *this, std__List *a2)
{
  CSystemProcessInfoMapNode *result; // eax
  CSystemProcessInfoMapNode *v3; // esi
  _DWORD *v4; // edi
  Data_t_bstr_t *v5; // eax
  Data_t_bstr_t *v6; // eax

  result = std::_Tree_comp_alloc<std::_Tmap_traits<unsigned long,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *>>,0>>::_Buynode0(this);
  v3 = result;
  v4 = &result->_Keyvalue._Key;
  *&result->baseclass._Color = 0;
  if ( result != -16 )
  {
    v5 = a2->_Mypair._Myval2._Myhead;
    *v4 = a2->_Mypair._Myval2._Myhead;
    if ( v5 )
      InterlockedIncrement(&v5->m_RefCount);
    v6 = a2->_Mypair._Myval2._Mysize;
    v4[1] = v6;
    if ( v6 )
      InterlockedIncrement(&v6->m_RefCount);
    result = v3;
  }
  return result;
}

//----- (01001240) --------------------------------------------------------
int __thiscall sub_1001240(int *this, int a2, int a3, int a4, void *a5)
{
  int *v5; // edx
  int v6; // ecx
  bool v7; // al
  int v8; // ebx
  int v9; // esi
  Data_t_bstr_t *v10; // ecx
  Data_t_bstr_t *v11; // ecx
  int v12; // esi
  int *v13; // eax
  int v14; // ecx
  int result; // eax
  Data_t_bstr_t *v16; // ecx
  void *v17; // edi
  Data_t_bstr_t *v18; // [esp-8h] [ebp-34h]
  Data_t_bstr_t *v19; // [esp-8h] [ebp-34h]
  Data_t_bstr_t *v20; // [esp-8h] [ebp-34h]
  Data_t_bstr_t *v21; // [esp-4h] [ebp-30h]
  Data_t_bstr_t *v22; // [esp-4h] [ebp-30h]
  Data_t_bstr_t *v23; // [esp-4h] [ebp-30h]
  int v24; // [esp+0h] [ebp-2Ch]
  int *v25; // [esp+10h] [ebp-1Ch]
  int v26; // [esp+14h] [ebp-18h]
  int v27; // [esp+18h] [ebp-14h]
  int *v28; // [esp+1Ch] [ebp-10h]
  int v29; // [esp+28h] [ebp-4h]

  v28 = &v24;
  v5 = this;
  v25 = this;
  v6 = *this;
  v7 = 1;
  v8 = a4;
  v29 = 0;
  v9 = *(v6 + 4);
  v27 = v6;
  LOBYTE(v26) = 1;
  if ( !*(v9 + 13) )
  {
    do
    {
      v27 = v9;
      if ( a3 )
      {
        v21 = *v8;
        if ( *v8 )
          InterlockedIncrement((*v8 + 8));
        v10 = *(v9 + 16);
        v18 = v10;
        if ( v10 )
          InterlockedIncrement(&v10->m_RefCount);
        v7 = sub_FF14B0(v18, v21) == 0;
      }
      else
      {
        v11 = *(v9 + 16);
        v22 = v11;
        if ( v11 )
          InterlockedIncrement(&v11->m_RefCount);
        v19 = *v8;
        if ( *v8 )
          InterlockedIncrement(&v19->m_RefCount);
        v7 = sub_FF14B0(v19, v22);
      }
      LOBYTE(v26) = v7;
      if ( v7 )
        v9 = *v9;
      else
        v9 = *(v9 + 8);
    }
    while ( !*(v9 + 13) );
    v6 = v27;
    v5 = v25;
  }
  v12 = v6;
  a3 = v6;
  if ( v7 )
  {
    if ( v6 == **v5 )
    {
      v13 = sub_100AEE0(v5, &a3, 1, v6, v8, a5);
LABEL_21:
      v14 = *v13;
      result = a2;
      *a2 = v14;
      *(a2 + 4) = 1;
      return result;
    }
    std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *>>>,std::_Iterator_base0>::operator--(&a3);
    v12 = a3;
  }
  v23 = *v8;
  if ( *v8 )
    InterlockedIncrement(&v23->m_RefCount);
  v16 = *(v12 + 16);
  v20 = v16;
  if ( v16 )
    InterlockedIncrement(&v16->m_RefCount);
  if ( sub_FF14B0(v20, v23) )
  {
    v13 = sub_100AEE0(v25, &a3, v26, v27, v8, a5);
    goto LABEL_21;
  }
  v17 = a5;
  sub_1001430(a5 + 2);
  j__free(v17);
  result = a2;
  *a2 = v12;
  *(a2 + 4) = 0;
  return result;
}
// 10681AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);

//----- (010013E0) --------------------------------------------------------
int sub_10013E0(wchar_t *Dst, wchar_t *Format, ...)
{
  va_list ArgList; // [esp+10h] [ebp+10h]

  va_start(ArgList, Format);
  return vswprintf_s(Dst, 0x10u, Format, ArgList);
}

//----- (01001400) --------------------------------------------------------
void __thiscall sub_1001400(CSystemProcessInfoMap *this)
{
  CSystemProcessInfoMap *v1; // esi
  char v2; // [esp+4h] [ebp-4h]

  v1 = this;
  sub_1006540(this, &v2, this->_Header->_Left, this->_Header);
  j__free(v1->_Header);
}

//----- (01001430) --------------------------------------------------------
void __thiscall sub_1001430(std__List *this)
{
  std__List *v1; // edi
  LONG (__stdcall *v2)(volatile LONG *); // ecx
  Data_t_bstr_t *v3; // esi
  Data_t_bstr_t *v4; // esi

  v1 = this;
  v2 = InterlockedDecrement;
  v3 = v1->_Mypair._Myval2._Mysize;
  if ( v3 )
  {
    if ( !InterlockedDecrement(&v3->m_RefCount) && v3 )
    {
      if ( v3->m_wstr )
      {
        SysFreeString(v3->m_wstr);
        v3->m_wstr = 0;
      }
      if ( v3->m_str )
      {
        j_j__free(v3->m_str);
        v3->m_str = 0;
      }
      j__free(v3);
    }
    v2 = InterlockedDecrement;
    v1->_Mypair._Myval2._Mysize = 0;
  }
  v4 = v1->_Mypair._Myval2._Myhead;
  if ( v1->_Mypair._Myval2._Myhead )
  {
    if ( !v2(&v4->m_RefCount) && v4 )
    {
      if ( v4->m_wstr )
      {
        SysFreeString(v4->m_wstr);
        v4->m_wstr = 0;
      }
      if ( v4->m_str )
      {
        j_j__free(v4->m_str);
        v4->m_str = 0;
      }
      j__free(v4);
    }
    v1->_Mypair._Myval2._Myhead = 0;
  }
}

//----- (010014F0) --------------------------------------------------------
_bstr_t *__cdecl sub_10014F0(_bstr_t *a1, LPCSTR lpString, _bstr_t *a3)
{
  _bstr_t::_bstr_t(a1, lpString);
  _bstr_t::operator+=(a1, a3);
  return a1;
}

//----- (01001560) --------------------------------------------------------
bool __stdcall AskForAgreementLicense(HWND hWnd, OLECHAR *psz, char a3, char a4, int a5)
{
  _bstr_t *v5; // esi
  _bstr_t *v6; // eax
  _bstr_t *v7; // eax
  Data_t_bstr_t *v8; // esi
  Data_t_bstr_t *v9; // esi
  Data_t_bstr_t *v10; // esi
  Data_t_bstr_t *v11; // esi
  const wchar_t *v12; // eax
  char v13; // al
  HWND v14; // ebx
  FILE *v15; // eax
  int v16; // eax
  bool v17; // bl
  Data_t_bstr_t *v18; // esi
  tagRegKeyInfo pThis; // [esp+14h] [ebp-58h]
  _bstr_t v21; // [esp+20h] [ebp-4Ch]
  _bstr_t v22; // [esp+24h] [ebp-48h]
  Data_t_bstr_t *v23; // [esp+28h] [ebp-44h]
  _bstr_t v24; // [esp+2Ch] [ebp-40h]
  _bstr_t v25; // [esp+30h] [ebp-3Ch]
  wchar_t Str; // [esp+34h] [ebp-38h]
  int v27; // [esp+68h] [ebp-4h]

  pThis.nLength = hWnd;
  _bstr_t::_bstr_t(&v24, L"\\VirusTotal");
  v27 = 0;
  v5 = _bstr_t::_bstr_t(&v21, psz);
  LOBYTE(v27) = 1;
  v6 = _bstr_t::_bstr_t(&v22, L"Software\\Sysinternals\\");
  LOBYTE(v27) = 2;
  v7 = _bstr_t::operator+(v6, &v23, v5);
  LOBYTE(v27) = 3;
  _bstr_t::operator+(v7, &v25, &v24);
  v8 = v23;
  if ( v23 )
  {
    if ( !InterlockedDecrement(&v23->m_RefCount) && v8 )
    {
      if ( v8->m_wstr )
      {
        SysFreeString(v8->m_wstr);
        v8->m_wstr = 0;
      }
      if ( v8->m_str )
      {
        j_j__free(v8->m_str);
        v8->m_str = 0;
      }
      j__free(v8);
    }
    v23 = 0;
  }
  v9 = v22.m_Data;
  if ( v22.m_Data )
  {
    if ( !InterlockedDecrement(&v22.m_Data->m_RefCount) && v9 )
    {
      if ( v9->m_wstr )
      {
        SysFreeString(v9->m_wstr);
        v9->m_wstr = 0;
      }
      if ( v9->m_str )
      {
        j_j__free(v9->m_str);
        v9->m_str = 0;
      }
      j__free(v9);
    }
    v22.m_Data = 0;
  }
  v10 = v21.m_Data;
  if ( v21.m_Data )
  {
    if ( !InterlockedDecrement(&v21.m_Data->m_RefCount) && v10 )
    {
      if ( v10->m_wstr )
      {
        SysFreeString(v10->m_wstr);
        v10->m_wstr = 0;
      }
      if ( v10->m_str )
      {
        j_j__free(v10->m_str);
        v10->m_str = 0;
      }
      j__free(v10);
    }
    v21.m_Data = 0;
  }
  v11 = v24.m_Data;
  if ( v24.m_Data && !InterlockedDecrement(&v24.m_Data->m_RefCount) )
  {
    if ( v11->m_wstr )
    {
      SysFreeString(v11->m_wstr);
      v11->m_wstr = 0;
    }
    if ( v11->m_str )
    {
      j_j__free(v11->m_str);
      v11->m_str = 0;
    }
    j__free(v11);
  }
  if ( v25.m_Data )
    v12 = v25.m_Data->m_wstr;
  else
    v12 = 0;
  pThis.szKeyName = _wcsdup(v12);
  LOBYTE(v27) = 9;
  LoadConfigItemFromRegistry(&pThis, &pConfigItem);
  v13 = byte_10C4DB0;
  if ( byte_10C4DB0 )
    goto LABEL_52;
  if ( a4 != byte_10C4DB0 )
    goto LABEL_63;
  v14 = pThis.nLength;
  LaunchWebBrowser(pThis.nLength, 0, L"https://www.virustotal.com/about/terms-of-service");
  if ( a3 )
  {
    wprintf(L"%s\n\n", aYouMustAgreeTo);
    wprintf(L"Enter 'y' to agree: ");
    v15 = sub_1067B15();
    fflush(v15 + 1);
    _getws_s(&Str, 0x14u);
    if ( wcschr(&Str, 0x79u) )
    {
      byte_10C4DB0 = 1;
      wprintf(L"\n");
    }
    else
    {
      wprintf(L"\nYou must agree to VirusTotal's terms of service to use VirusTotal features.\n\n");
    }
    goto LABEL_48;
  }
  v16 = a5 ? MessageBoxW(v14, a5, L"VirusTotal Terms of Service", 0x24u) : MessageBoxW(
                                                                             v14,
                                                                             L"You must agree to VirusTotal's terms of ser"
                                                                              "vice to use VirusTotal features.\n"
                                                                              "\n",
                                                                             L"VirusTotal Terms of Service",
                                                                             0x24u);
  if ( v16 == 6 )
  {
LABEL_63:
    byte_10C4DB0 = 1;
LABEL_51:
    SaveConfigItemToRegistry(&pThis, &pConfigItem);
    v13 = byte_10C4DB0;
    goto LABEL_52;
  }
LABEL_48:
  v13 = byte_10C4DB0;
  if ( byte_10C4DB0 )
    goto LABEL_51;
LABEL_52:
  v17 = v13 == 1;
  free(pThis.szKeyName);
  v18 = v25.m_Data;
  if ( v25.m_Data && !InterlockedDecrement(&v25.m_Data->m_RefCount) && v18 )
  {
    if ( v18->m_wstr )
    {
      SysFreeString(v18->m_wstr);
      v18->m_wstr = 0;
    }
    if ( v18->m_str )
    {
      j_j__free(v18->m_str);
      v18->m_str = 0;
    }
    j__free(v18);
  }
  return v17;
}
// 1094500: using guessed type wchar_t aYouMustAgreeTo_1[78];
// 10BC338: using guessed type wchar_t aYouMustAgreeTo[175];
// 10C4DB0: using guessed type char byte_10C4DB0;

//----- (010018A0) --------------------------------------------------------
int __stdcall sub_10018A0(int a1, FILETIME *lpFileTime)
{
  _bstr_t *v2; // esi
  _bstr_t *v3; // eax
  _bstr_t *v4; // eax
  _bstr_t *v5; // esi
  Data_t_bstr_t *v6; // eax
  void *v7; // esi
  LONG (__stdcall *v8)(volatile LONG *); // ecx
  void *v9; // esi
  Data_t_bstr_t *v10; // esi
  Data_t_bstr_t *v11; // esi
  Data_t_bstr_t *v12; // esi
  struct _FILETIME LocalFileTime; // [esp+14h] [ebp-140h]
  int v15; // [esp+1Ch] [ebp-138h]
  void *v16; // [esp+20h] [ebp-134h]
  _bstr_t v17; // [esp+24h] [ebp-130h]
  _bstr_t v18; // [esp+28h] [ebp-12Ch]
  void *v19; // [esp+2Ch] [ebp-128h]
  _bstr_t v20; // [esp+30h] [ebp-124h]
  struct _SYSTEMTIME SystemTime; // [esp+34h] [ebp-120h]
  WCHAR TimeStr; // [esp+44h] [ebp-110h]
  WCHAR DateStr; // [esp+C4h] [ebp-90h]
  int v24; // [esp+150h] [ebp-4h]

  *a1 = 0;
  v24 = 0;
  v15 = 1;
  FileTimeToLocalFileTime(lpFileTime, &LocalFileTime);
  FileTimeToSystemTime(&LocalFileTime, &SystemTime);
  GetDateFormatW(0x400u, 0, &SystemTime, L"yyyy-MM-dd", &DateStr, 64);
  GetTimeFormatW(0x400u, 8u, &SystemTime, L"hh:mm:ss", &TimeStr, 64);
  _bstr_t::_bstr_t(&v17, L" ");
  v24 = 1;
  v2 = _bstr_t::_bstr_t(&v20, &TimeStr);
  LOBYTE(v24) = 2;
  v3 = _bstr_t::_bstr_t(&v18, &DateStr);
  LOBYTE(v24) = 3;
  v4 = _bstr_t::operator+(v3, &v16, &v17);
  LOBYTE(v24) = 4;
  v5 = _bstr_t::operator+(v4, &v19, v2);
  if ( a1 != v5 )
  {
    _bstr_t::_Free(a1);
    v6 = v5->m_Data;
    *a1 = v5->m_Data;
    if ( v6 )
      InterlockedIncrement(&v6->m_RefCount);
  }
  v7 = v19;
  v8 = InterlockedDecrement;
  if ( v19 )
  {
    if ( !InterlockedDecrement(v19 + 2) && v7 )
    {
      if ( *v7 )
      {
        SysFreeString(*v7);
        *v7 = 0;
      }
      if ( *(v7 + 1) )
      {
        j_j__free(*(v7 + 1));
        *(v7 + 1) = 0;
      }
      j__free(v7);
    }
    v8 = InterlockedDecrement;
    v19 = 0;
  }
  v9 = v16;
  if ( v16 )
  {
    if ( !v8(v16 + 2) && v9 )
    {
      if ( *v9 )
      {
        SysFreeString(*v9);
        *v9 = 0;
      }
      if ( *(v9 + 1) )
      {
        j_j__free(*(v9 + 1));
        *(v9 + 1) = 0;
      }
      j__free(v9);
    }
    v16 = 0;
  }
  v10 = v18.m_Data;
  if ( v18.m_Data )
  {
    if ( !InterlockedDecrement(&v18.m_Data->m_RefCount) && v10 )
    {
      if ( v10->m_wstr )
      {
        SysFreeString(v10->m_wstr);
        v10->m_wstr = 0;
      }
      if ( v10->m_str )
      {
        j_j__free(v10->m_str);
        v10->m_str = 0;
      }
      j__free(v10);
    }
    v18.m_Data = 0;
  }
  v11 = v20.m_Data;
  if ( v20.m_Data )
  {
    if ( !InterlockedDecrement(&v20.m_Data->m_RefCount) && v11 )
    {
      if ( v11->m_wstr )
      {
        SysFreeString(v11->m_wstr);
        v11->m_wstr = 0;
      }
      if ( v11->m_str )
      {
        j_j__free(v11->m_str);
        v11->m_str = 0;
      }
      j__free(v11);
    }
    v20.m_Data = 0;
  }
  v12 = v17.m_Data;
  if ( v17.m_Data && !InterlockedDecrement(&v17.m_Data->m_RefCount) )
  {
    if ( v12->m_wstr )
    {
      SysFreeString(v12->m_wstr);
      v12->m_wstr = 0;
    }
    if ( v12->m_str )
    {
      j_j__free(v12->m_str);
      v12->m_str = 0;
    }
    j__free(v12);
  }
  return a1;
}

//----- (01001BC0) --------------------------------------------------------
int __stdcall sub_1001BC0(int a2, OLECHAR *psz)
{
  OLECHAR *v2; // edi
  Data_t_bstr_t *v3; // eax
  Data_t_bstr_t *v4; // eax
  Data_t_bstr_t *v5; // esi
  BSTR v6; // eax
  Data_t_bstr_t *v7; // eax
  BSTR *v8; // eax
  int v9; // edi
  Data_t_bstr_t *v10; // eax
  Data_t_bstr_t *v11; // esi
  BSTR v12; // eax
  Data_t_bstr_t *v13; // eax
  BSTR *v14; // eax
  int v15; // edi
  Data_t_bstr_t *v16; // edi
  Data_t_bstr_t *v17; // eax
  Data_t_bstr_t *v18; // esi
  BSTR v19; // eax
  Data_t_bstr_t *v20; // eax
  BSTR *v21; // eax
  int v22; // edi
  _bstr_t v24; // [esp+10h] [ebp-18h]
  _bstr_t a3; // [esp+14h] [ebp-14h]
  int v26; // [esp+18h] [ebp-10h]
  int v27; // [esp+24h] [ebp-4h]
  OLECHAR *psza; // [esp+34h] [ebp+Ch]
  OLECHAR *pszb; // [esp+34h] [ebp+Ch]
  OLECHAR *pszc; // [esp+34h] [ebp+Ch]

  *a2 = 0;
  v2 = psz;
  v27 = 0;
  v26 = 1;
  if ( psz )
  {
    while ( 1 )
    {
      v3 = wcschr(v2, 0x5Cu);
      v24.m_Data = v3;
      if ( !v3 )
        break;
      LOWORD(v3->m_wstr) = 0;
      v4 = operator new(0xCu);
      v5 = v4;
      v27 = 1;
      if ( v4 )
      {
        v4->m_str = 0;
        v4->m_RefCount = 1;
        v6 = SysAllocString(v2);
        v5->m_wstr = v6;
        if ( !v6 && v2 )
          goto LABEL_56;
      }
      else
      {
        v5 = 0;
      }
      LOBYTE(v27) = 0;
      a3.m_Data = v5;
      if ( !v5 )
        goto LABEL_56;
      v27 = 2;
      v7 = operator new(0xCu);
      LOBYTE(v27) = 3;
      v8 = v7 ? _bstr_t::Data_t::Data_t(v7, a2, &a3) : 0;
      psza = v8;
      LOBYTE(v27) = 2;
      if ( !v8 )
        goto LABEL_56;
      v9 = *a2;
      if ( *a2 )
      {
        if ( !InterlockedDecrement((v9 + 8)) && v9 )
        {
          if ( *v9 )
          {
            SysFreeString(*v9);
            *v9 = 0;
          }
          if ( *(v9 + 4) )
          {
            j_j__free(*(v9 + 4));
            *(v9 + 4) = 0;
          }
          j__free(v9);
        }
        v8 = psza;
        *a2 = 0;
      }
      *a2 = v8;
      LOBYTE(v27) = 0;
      if ( !InterlockedDecrement(&v5->m_RefCount) )
      {
        if ( v5->m_wstr )
        {
          SysFreeString(v5->m_wstr);
          v5->m_wstr = 0;
        }
        if ( v5->m_str )
        {
          j_j__free(v5->m_str);
          v5->m_str = 0;
        }
        j__free(v5);
      }
      v10 = operator new(0xCu);
      v11 = v10;
      v27 = 4;
      if ( v10 )
      {
        v10->m_str = 0;
        v10->m_RefCount = 1;
        v12 = SysAllocString(L"\\\\");
        v11->m_wstr = v12;
        if ( !v12 )
          goto LABEL_56;
      }
      else
      {
        v11 = 0;
      }
      LOBYTE(v27) = 0;
      a3.m_Data = v11;
      if ( !v11 )
        goto LABEL_56;
      v27 = 5;
      v13 = operator new(0xCu);
      LOBYTE(v27) = 6;
      v14 = v13 ? _bstr_t::Data_t::Data_t(v13, a2, &a3) : 0;
      pszb = v14;
      LOBYTE(v27) = 5;
      if ( !v14 )
        goto LABEL_56;
      v15 = *a2;
      if ( *a2 )
      {
        if ( !InterlockedDecrement((v15 + 8)) && v15 )
        {
          if ( *v15 )
          {
            SysFreeString(*v15);
            *v15 = 0;
          }
          if ( *(v15 + 4) )
          {
            j_j__free(*(v15 + 4));
            *(v15 + 4) = 0;
          }
          j__free(v15);
        }
        v14 = pszb;
        *a2 = 0;
      }
      *a2 = v14;
      LOBYTE(v27) = 0;
      if ( !InterlockedDecrement(&v11->m_RefCount) )
      {
        if ( v11->m_wstr )
        {
          SysFreeString(v11->m_wstr);
          v11->m_wstr = 0;
        }
        if ( v11->m_str )
        {
          j_j__free(v11->m_str);
          v11->m_str = 0;
        }
        j__free(v11);
      }
      v16 = v24.m_Data;
      LOWORD(v24.m_Data->m_wstr) = 92;
      v2 = (&v16->m_wstr + 2);
    }
    v17 = operator new(0xCu);
    v18 = v17;
    v27 = 7;
    if ( v17 )
    {
      v17->m_str = 0;
      v17->m_RefCount = 1;
      v19 = SysAllocString(v2);
      v18->m_wstr = v19;
      if ( !v19 && v2 )
        goto LABEL_56;
    }
    else
    {
      v18 = 0;
    }
    LOBYTE(v27) = 0;
    v24.m_Data = v18;
    if ( !v18
      || ((v27 = 8, v20 = operator new(0xCu), LOBYTE(v27) = 9, !v20) ? (v21 = 0) : (v21 = _bstr_t::Data_t::Data_t(
                                                                                            v20,
                                                                                            a2,
                                                                                            &v24)),
          pszc = v21,
          LOBYTE(v27) = 8,
          !v21) )
    {
LABEL_56:
      _com_issue_error(-2147024882);
    }
    v22 = *a2;
    if ( *a2 )
    {
      if ( !InterlockedDecrement((v22 + 8)) && v22 )
      {
        if ( *v22 )
        {
          SysFreeString(*v22);
          *v22 = 0;
        }
        if ( *(v22 + 4) )
        {
          j_j__free(*(v22 + 4));
          *(v22 + 4) = 0;
        }
        j__free(v22);
      }
      v21 = pszc;
      *a2 = 0;
    }
    *a2 = v21;
    if ( !InterlockedDecrement(&v18->m_RefCount) )
    {
      if ( v18->m_wstr )
      {
        SysFreeString(v18->m_wstr);
        v18->m_wstr = 0;
      }
      if ( v18->m_str )
      {
        j_j__free(v18->m_str);
        v18->m_str = 0;
      }
      j__free(v18);
    }
  }
  return a2;
}

//----- (01001FC0) --------------------------------------------------------
DWORD __thiscall sub_1001FC0(_DWORD *this)
{
  _DWORD *v1; // ebx
  CSystemProcessInfoMapNode *v2; // eax
  bool v3; // zf
  DWORD v4; // edi
  _DWORD *v5; // eax
  void (__stdcall *v6)(BSTR); // ebx
  Data_t_bstr_t *v7; // esi
  _DWORD *v8; // edi
  volatile LONG *v9; // eax
  volatile LONG *v10; // ebx
  Data_t_bstr_t *v11; // eax
  _DWORD *v12; // eax
  DWORD v13; // ebx
  Data_t_bstr_t *v14; // eax
  Data_t_bstr_t *v15; // eax
  Data_t_bstr_t *v16; // eax
  Data_t_bstr_t *v17; // esi
  OLECHAR *v18; // eax
  _bstr_t *v19; // eax
  _bstr_t *v20; // eax
  _bstr_t *v21; // ebx
  Data_t_bstr_t *v22; // eax
  BSTR *v23; // eax
  Data_t_bstr_t *v24; // ebx
  void *v25; // ebx
  Data_t_bstr_t *v26; // ebx
  void *v27; // ebx
  Data_t_bstr_t *v28; // eax
  Data_t_bstr_t *v29; // esi
  char *v30; // eax
  OLECHAR *v31; // eax
  _bstr_t *v32; // eax
  _bstr_t *v33; // eax
  _bstr_t *v34; // ebx
  Data_t_bstr_t *v35; // eax
  BSTR *v36; // eax
  DWORD v37; // ebx
  void *v38; // ebx
  Data_t_bstr_t *v39; // ebx
  void *v40; // ebx
  volatile LONG *v41; // eax
  volatile LONG *v42; // ebx
  Data_t_bstr_t *v43; // esi
  _bstr_t *v44; // eax
  Data_t_bstr_t *v45; // eax
  BSTR *v46; // eax
  Data_t_bstr_t *v47; // eax
  Data_t_bstr_t *v48; // eax
  Data_t_bstr_t *v49; // eax
  volatile LONG *v50; // eax
  volatile LONG *v51; // esi
  BSTR v52; // eax
  OLECHAR *v53; // eax
  _bstr_t *v54; // eax
  _bstr_t *v55; // eax
  _bstr_t *v56; // ebx
  Data_t_bstr_t *v57; // eax
  Data_t_bstr_t *v58; // ebx
  void **v59; // eax
  void *v60; // ebx
  Data_t_bstr_t *v61; // ebx
  Data_t_bstr_t *v62; // ebx
  volatile LONG *v63; // eax
  volatile LONG *v64; // esi
  _bstr_t *v65; // eax
  _bstr_t *v66; // eax
  _bstr_t *v67; // ebx
  Data_t_bstr_t *v68; // eax
  Data_t_bstr_t *v69; // ebx
  Data_t_bstr_t *v70; // eax
  Data_t_bstr_t *v71; // ebx
  Data_t_bstr_t *v72; // ebx
  Data_t_bstr_t *v73; // ebx
  volatile LONG *v74; // eax
  volatile LONG *v75; // ebx
  Data_t_bstr_t *v76; // eax
  Data_t_bstr_t *v77; // eax
  volatile LONG *v78; // eax
  volatile LONG *v79; // edi
  Data_t_bstr_t *v80; // eax
  Data_t_bstr_t *v81; // eax
  Data_t_bstr_t *v82; // esi
  void *v83; // ecx
  volatile LONG *v84; // eax
  volatile LONG *v85; // esi
  _bstr_t *v86; // eax
  CHAR *v87; // ecx
  DWORD v88; // eax
  Data_t_bstr_t *v89; // edi
  DWORD v90; // edi
  Data_t_bstr_t *v91; // ebx
  HINTERNET *v92; // edi
  CHAR *v93; // ecx
  const wchar_t *v94; // eax
  CHAR *v95; // ecx
  const wchar_t *v96; // eax
  const wchar_t *v97; // eax
  _DWORD *v98; // eax
  _DWORD *v99; // esi
  HINTERNET *v100; // ebx
  BSTR **v101; // edi
  Data_t_bstr_t *v102; // eax
  Data_t_bstr_t *v103; // edi
  OLECHAR *v104; // eax
  CSystemProcessInfoMapNode *v105; // ecx
  Data_t_bstr_t *v106; // eax
  const wchar_t *v107; // eax
  CHAR *v108; // ecx
  Data_t_bstr_t *v109; // eax
  BSTR *v110; // edi
  BSTR v111; // eax
  CHAR *v112; // ecx
  Data_t_bstr_t *v113; // eax
  BSTR *v114; // edi
  BSTR v115; // eax
  int v116; // edi
  _DWORD *v117; // eax
  _DWORD *v118; // esi
  int v119; // edi
  OLECHAR **v120; // eax
  OLECHAR *v121; // eax
  Data_t_bstr_t *v122; // esi
  _bstr_t *v123; // ecx
  _DWORD *v124; // eax
  _DWORD *v125; // edi
  HINTERNET *v126; // ebx
  volatile LONG **v127; // eax
  int v128; // esi
  Data_t_bstr_t *v129; // esi
  Data_t_bstr_t *v130; // esi
  _bstr_t *v131; // edi
  _DWORD *v132; // eax
  _DWORD *v133; // edi
  HINTERNET *v134; // ebx
  _bstr_t *v135; // eax
  HINTERNET *v136; // edx
  _DWORD **v137; // eax
  _DWORD *v138; // ecx
  HINTERNET *v139; // ebx
  _DWORD *v140; // esi
  CHAR *v142; // [esp-10h] [ebp-9Ch]
  void *v143; // [esp-Ch] [ebp-98h]
  CSystemProcessInfoMapNode *v144; // [esp-8h] [ebp-94h]
  CHAR *v145; // [esp-4h] [ebp-90h]
  void *v146; // [esp+10h] [ebp-7Ch]
  int v147; // [esp+14h] [ebp-78h]
  void *v148; // [esp+18h] [ebp-74h]
  OLECHAR psz[2]; // [esp+1Ch] [ebp-70h]
  _bstr_t a3; // [esp+20h] [ebp-6Ch]
  _bstr_t v151; // [esp+24h] [ebp-68h]
  _bstr_t v152; // [esp+28h] [ebp-64h]
  _bstr_t v153; // [esp+2Ch] [ebp-60h]
  _bstr_t v154; // [esp+30h] [ebp-5Ch]
  _bstr_t v155; // [esp+34h] [ebp-58h]
  void *v156; // [esp+38h] [ebp-54h]
  _bstr_t v157; // [esp+3Ch] [ebp-50h]
  int v158; // [esp+40h] [ebp-4Ch]
  void *v159; // [esp+44h] [ebp-48h]
  _bstr_t v160; // [esp+48h] [ebp-44h]
  void *v161; // [esp+4Ch] [ebp-40h]
  void *v162; // [esp+50h] [ebp-3Ch]
  _bstr_t a1; // [esp+54h] [ebp-38h]
  void *v164; // [esp+58h] [ebp-34h]
  int v165; // [esp+5Ch] [ebp-30h]
  _bstr_t v166; // [esp+60h] [ebp-2Ch]
  _bstr_t v167; // [esp+64h] [ebp-28h]
  OLECHAR v168[2]; // [esp+68h] [ebp-24h]
  DWORD dwMessageId; // [esp+6Ch] [ebp-20h]
  _bstr_t v170; // [esp+70h] [ebp-1Ch]
  HINTERNET *v171; // [esp+74h] [ebp-18h]
  _bstr_t a2; // [esp+78h] [ebp-14h]
  bool v173; // [esp+7Fh] [ebp-Dh]
  int v174; // [esp+88h] [ebp-4h]

  v1 = this;
  v171 = this;
  v147 = 0;
  v2 = std::_Tree_comp_alloc<std::_Tmap_traits<unsigned long,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *>>,0>>::_Buyheadnode();
  v146 = v2;
  v3 = v1[3] == 0;
  v174 = 0;
  v165 = 0;
  if ( v3 )
  {
    v4 = 0;
    goto LABEL_475;
  }
  _bstr_t::_bstr_t(&a2, L"[");
  v5 = v1[2];
  v6 = SysFreeString;
  v7 = a2.m_Data;
  LOBYTE(v174) = 1;
  v8 = *v5;
  if ( *v5 != v5 )
  {
    do
    {
      v166.m_Data = v8[2];
      _bstr_t::operator=(&v166.m_Data[2], &gszNullString);
      if ( v165 )
      {
        v9 = operator new(0xCu);
        v10 = v9;
        *psz = v9;
        LOBYTE(v174) = 2;
        if ( v9 )
        {
          v145 = ",";
          *(v9 + 1) = 0;
          *(v9 + 2) = 1;
          *v9 = _com_util::ConvertStringToBSTR(v145);
        }
        else
        {
          v10 = 0;
        }
        LOBYTE(v174) = 1;
        *v168 = v10;
        if ( !v10 )
          goto LABEL_311;
        LOBYTE(v174) = 3;
        v11 = operator new(0xCu);
        *psz = v11;
        LOBYTE(v174) = 4;
        v7 = (v11 ? _bstr_t::Data_t::Data_t(v11, &a2, v168) : 0);
        LOBYTE(v174) = 3;
        if ( !v7 )
          goto LABEL_311;
        _bstr_t::_Free(&a2);
        a2.m_Data = v7;
        LOBYTE(v174) = 1;
        if ( !InterlockedDecrement(v10 + 2) )
        {
          if ( *v10 )
          {
            SysFreeString(*v10);
            *v10 = 0;
          }
          if ( *(v10 + 1) )
          {
            j_j__free(*(v10 + 1));
            *(v10 + 1) = 0;
          }
          j__free(v10);
        }
      }
      v12 = operator new(0xCu);
      v13 = v12;
      *psz = v12;
      LOBYTE(v174) = 5;
      if ( v12 )
      {
        v145 = L"{";
        v12[1] = 0;
        v12[2] = 1;
        *v12 = _com_util::ConvertStringToBSTR(v145);
      }
      else
      {
        v13 = 0;
      }
      LOBYTE(v174) = 1;
      dwMessageId = v13;
      if ( !v13 )
        goto LABEL_311;
      LOBYTE(v174) = 6;
      v14 = operator new(0xCu);
      *psz = v14;
      LOBYTE(v174) = 7;
      v15 = (v14 ? _bstr_t::Data_t::Data_t(v14, &a2, &dwMessageId) : 0);
      *v168 = v15;
      LOBYTE(v174) = 6;
      if ( !v15 )
        goto LABEL_311;
      if ( v7 )
      {
        if ( !InterlockedDecrement(&v7->m_RefCount) )
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
        v15 = *v168;
      }
      a2.m_Data = v15;
      LOBYTE(v174) = 1;
      if ( !InterlockedDecrement((v13 + 8)) )
      {
        if ( *v13 )
        {
          SysFreeString(*v13);
          *v13 = 0;
        }
        if ( *(v13 + 4) )
        {
          j_j__free(*(v13 + 4));
          *(v13 + 4) = 0;
        }
        j__free(v13);
      }
      v16 = operator new(0xCu);
      v17 = v16;
      *psz = v16;
      LOBYTE(v174) = 8;
      if ( v16 )
      {
        v145 = "\", ";
        v16->m_str = 0;
        v16->m_RefCount = 1;
        v16->m_wstr = _com_util::ConvertStringToBSTR(v145);
      }
      else
      {
        v17 = 0;
      }
      LOBYTE(v174) = 1;
      a3.m_Data = v17;
      if ( !v17 )
        goto LABEL_311;
      LOBYTE(v174) = 9;
      v18 = (v166.m_Data->m_wstr ? *v166.m_Data->m_wstr : 0);
      v19 = sub_1001BC0(&v162, v18);
      LOBYTE(v174) = 10;
      v20 = sub_10014F0(&a1, "\"autostart_location\": \"", v19);
      LOBYTE(v174) = 11;
      v21 = _bstr_t::operator+(v20, &v164, &a3);
      LOBYTE(v174) = 12;
      v22 = operator new(0xCu);
      *psz = v22;
      LOBYTE(v174) = 13;
      v23 = v22 ? _bstr_t::Data_t::Data_t(v22, &a2, v21) : 0;
      dwMessageId = v23;
      LOBYTE(v174) = 12;
      if ( !v23 )
        goto LABEL_311;
      v24 = *v168;
      if ( !InterlockedDecrement((*v168 + 8)) )
      {
        if ( v24->m_wstr )
        {
          SysFreeString(v24->m_wstr);
          v24->m_wstr = 0;
        }
        if ( v24->m_str )
        {
          j_j__free(v24->m_str);
          v24->m_str = 0;
        }
        j__free(v24);
      }
      v25 = v164;
      a2.m_Data = dwMessageId;
      if ( v164 )
      {
        if ( !InterlockedDecrement(v164 + 2) && v25 )
        {
          if ( *v25 )
          {
            SysFreeString(*v25);
            *v25 = 0;
          }
          if ( *(v25 + 1) )
          {
            j_j__free(*(v25 + 1));
            *(v25 + 1) = 0;
          }
          j__free(v25);
        }
        v164 = 0;
      }
      v26 = a1.m_Data;
      if ( a1.m_Data )
      {
        if ( !InterlockedDecrement(&a1.m_Data->m_RefCount) && v26 )
        {
          if ( v26->m_wstr )
          {
            SysFreeString(v26->m_wstr);
            v26->m_wstr = 0;
          }
          if ( v26->m_str )
          {
            j_j__free(v26->m_str);
            v26->m_str = 0;
          }
          j__free(v26);
        }
        a1.m_Data = 0;
      }
      v27 = v162;
      if ( v162 )
      {
        if ( !InterlockedDecrement(v162 + 2) && v27 )
        {
          if ( *v27 )
          {
            SysFreeString(*v27);
            *v27 = 0;
          }
          if ( *(v27 + 1) )
          {
            j_j__free(*(v27 + 1));
            *(v27 + 1) = 0;
          }
          j__free(v27);
        }
        v162 = 0;
      }
      LOBYTE(v174) = 1;
      if ( !InterlockedDecrement(&v17->m_RefCount) )
      {
        if ( v17->m_wstr )
        {
          SysFreeString(v17->m_wstr);
          v17->m_wstr = 0;
        }
        if ( v17->m_str )
        {
          j_j__free(v17->m_str);
          v17->m_str = 0;
        }
        j__free(v17);
      }
      v28 = operator new(0xCu);
      v29 = v28;
      *psz = v28;
      LOBYTE(v174) = 14;
      if ( v28 )
      {
        v145 = "\", ";
        v28->m_str = 0;
        v28->m_RefCount = 1;
        v28->m_wstr = _com_util::ConvertStringToBSTR(v145);
      }
      else
      {
        v29 = 0;
      }
      LOBYTE(v174) = 1;
      a3.m_Data = v29;
      if ( !v29 )
        goto LABEL_311;
      LOBYTE(v174) = 15;
      v30 = v166.m_Data->m_str;
      v31 = (v30 ? *v30 : 0);
      v32 = sub_1001BC0(&v159, v31);
      LOBYTE(v174) = 16;
      v33 = sub_10014F0(&v160, "\"autostart_entry\": \"", v32);
      LOBYTE(v174) = 17;
      v34 = _bstr_t::operator+(v33, &v161, &a3);
      LOBYTE(v174) = 18;
      v35 = operator new(0xCu);
      *psz = v35;
      LOBYTE(v174) = 19;
      v36 = v35 ? _bstr_t::Data_t::Data_t(v35, &a2, v34) : 0;
      *v168 = v36;
      LOBYTE(v174) = 18;
      if ( !v36 )
        goto LABEL_311;
      v37 = dwMessageId;
      if ( !InterlockedDecrement((dwMessageId + 8)) )
      {
        if ( *v37 )
        {
          SysFreeString(*v37);
          *v37 = 0;
        }
        if ( *(v37 + 4) )
        {
          j_j__free(*(v37 + 4));
          *(v37 + 4) = 0;
        }
        j__free(v37);
      }
      v38 = v161;
      a2.m_Data = *v168;
      if ( v161 )
      {
        if ( !InterlockedDecrement(v161 + 2) && v38 )
        {
          if ( *v38 )
          {
            SysFreeString(*v38);
            *v38 = 0;
          }
          if ( *(v38 + 1) )
          {
            j_j__free(*(v38 + 1));
            *(v38 + 1) = 0;
          }
          j__free(v38);
        }
        v161 = 0;
      }
      v39 = v160.m_Data;
      if ( v160.m_Data )
      {
        if ( !InterlockedDecrement(&v160.m_Data->m_RefCount) && v39 )
        {
          if ( v39->m_wstr )
          {
            SysFreeString(v39->m_wstr);
            v39->m_wstr = 0;
          }
          if ( v39->m_str )
          {
            j_j__free(v39->m_str);
            v39->m_str = 0;
          }
          j__free(v39);
        }
        v160.m_Data = 0;
      }
      v40 = v159;
      if ( v159 )
      {
        if ( !InterlockedDecrement(v159 + 2) && v40 )
        {
          if ( *v40 )
          {
            SysFreeString(*v40);
            *v40 = 0;
          }
          if ( *(v40 + 1) )
          {
            j_j__free(*(v40 + 1));
            *(v40 + 1) = 0;
          }
          j__free(v40);
        }
        v159 = 0;
      }
      LOBYTE(v174) = 1;
      if ( !InterlockedDecrement(&v29->m_RefCount) )
      {
        if ( v29->m_wstr )
        {
          SysFreeString(v29->m_wstr);
          v29->m_wstr = 0;
        }
        if ( v29->m_str )
        {
          j_j__free(v29->m_str);
          v29->m_str = 0;
        }
        j__free(v29);
      }
      v41 = operator new(0xCu);
      v42 = v41;
      *psz = v41;
      LOBYTE(v174) = 20;
      if ( v41 )
      {
        v145 = "\", ";
        *(v41 + 1) = 0;
        *(v41 + 2) = 1;
        *v41 = _com_util::ConvertStringToBSTR(v145);
      }
      else
      {
        v42 = 0;
      }
      LOBYTE(v174) = 1;
      *psz = v42;
      if ( !v42 )
        goto LABEL_311;
      v43 = v166.m_Data->m_RefCount;
      a3.m_Data = v43;
      if ( v43 )
        InterlockedIncrement(&v43->m_RefCount);
      LOBYTE(v174) = 22;
      v44 = sub_10014F0(&v157, "\"hash\": \"", &a3);
      LOBYTE(v174) = 23;
      dwMessageId = _bstr_t::operator+(v44, &v158, psz);
      LOBYTE(v174) = 24;
      v45 = operator new(0xCu);
      v148 = v45;
      LOBYTE(v174) = 25;
      v46 = v45 ? _bstr_t::Data_t::Data_t(v45, &a2, dwMessageId) : 0;
      dwMessageId = v46;
      LOBYTE(v174) = 24;
      if ( !v46 )
        goto LABEL_311;
      if ( !InterlockedDecrement((*v168 + 8)) )
      {
        v47 = *v168;
        if ( **v168 )
        {
          SysFreeString(**v168);
          v47 = *v168;
          **v168 = 0;
        }
        if ( v47->m_str )
        {
          j_j__free(v47->m_str);
          v47 = *v168;
          *(*v168 + 4) = 0;
        }
        j__free(v47);
      }
      a2.m_Data = dwMessageId;
      *v168 = v158;
      if ( v158 )
      {
        if ( !InterlockedDecrement((v158 + 8)) )
        {
          v48 = *v168;
          if ( *v168 )
          {
            if ( **v168 )
            {
              SysFreeString(**v168);
              v48 = *v168;
              **v168 = 0;
            }
            if ( v48->m_str )
            {
              j_j__free(v48->m_str);
              v48 = *v168;
              *(*v168 + 4) = 0;
            }
            j__free(v48);
          }
        }
        v158 = 0;
      }
      *v168 = v157;
      if ( v157.m_Data )
      {
        if ( !InterlockedDecrement(&v157.m_Data->m_RefCount) )
        {
          v49 = *v168;
          if ( *v168 )
          {
            if ( **v168 )
            {
              SysFreeString(**v168);
              v49 = *v168;
              **v168 = 0;
            }
            if ( v49->m_str )
            {
              j_j__free(v49->m_str);
              v49 = *v168;
              *(*v168 + 4) = 0;
            }
            j__free(v49);
          }
        }
        v157.m_Data = 0;
      }
      if ( v43 && !InterlockedDecrement(&v43->m_RefCount) )
      {
        if ( v43->m_wstr )
        {
          SysFreeString(v43->m_wstr);
          v43->m_wstr = 0;
        }
        if ( v43->m_str )
        {
          j_j__free(v43->m_str);
          v43->m_str = 0;
        }
        j__free(v43);
      }
      LOBYTE(v174) = 1;
      if ( !InterlockedDecrement(v42 + 2) )
      {
        if ( *v42 )
        {
          SysFreeString(*v42);
          *v42 = 0;
        }
        if ( *(v42 + 1) )
        {
          j_j__free(*(v42 + 1));
          *(v42 + 1) = 0;
        }
        j__free(v42);
      }
      v50 = operator new(0xCu);
      v51 = v50;
      v148 = v50;
      LOBYTE(v174) = 26;
      if ( v50 )
      {
        v145 = "\", ";
        *(v50 + 1) = 0;
        *(v50 + 2) = 1;
        *v50 = _com_util::ConvertStringToBSTR(v145);
      }
      else
      {
        v51 = 0;
      }
      LOBYTE(v174) = 1;
      *psz = v51;
      if ( !v51 )
        goto LABEL_311;
      LOBYTE(v174) = 27;
      v52 = v166.m_Data[1].m_wstr;
      v53 = (v52 ? *v52 : 0);
      v54 = sub_1001BC0(&v154, v53);
      LOBYTE(v174) = 28;
      v55 = sub_10014F0(&v155, "\"image_path\": \"", v54);
      LOBYTE(v174) = 29;
      v56 = _bstr_t::operator+(v55, &v156, psz);
      LOBYTE(v174) = 30;
      v57 = operator new(0xCu);
      v148 = v57;
      LOBYTE(v174) = 31;
      if ( v57 )
      {
        v58 = _bstr_t::Data_t::Data_t(v57, &a2, v56);
        *v168 = v58;
      }
      else
      {
        v58 = 0;
        *v168 = 0;
      }
      LOBYTE(v174) = 30;
      if ( !v58 )
        goto LABEL_311;
      if ( !InterlockedDecrement((dwMessageId + 8)) )
      {
        v59 = dwMessageId;
        if ( *dwMessageId )
        {
          SysFreeString(*dwMessageId);
          v59 = dwMessageId;
          *dwMessageId = 0;
        }
        if ( v59[1] )
        {
          j_j__free(v59[1]);
          v59 = dwMessageId;
          *(dwMessageId + 4) = 0;
        }
        j__free(v59);
      }
      a2.m_Data = v58;
      v60 = v156;
      if ( v156 )
      {
        if ( !InterlockedDecrement(v156 + 2) && v60 )
        {
          if ( *v60 )
          {
            SysFreeString(*v60);
            *v60 = 0;
          }
          if ( *(v60 + 1) )
          {
            j_j__free(*(v60 + 1));
            *(v60 + 1) = 0;
          }
          j__free(v60);
        }
        v156 = 0;
      }
      v61 = v155.m_Data;
      if ( v155.m_Data )
      {
        if ( !InterlockedDecrement(&v155.m_Data->m_RefCount) && v61 )
        {
          if ( v61->m_wstr )
          {
            SysFreeString(v61->m_wstr);
            v61->m_wstr = 0;
          }
          if ( v61->m_str )
          {
            j_j__free(v61->m_str);
            v61->m_str = 0;
          }
          j__free(v61);
        }
        v155.m_Data = 0;
      }
      v62 = v154.m_Data;
      if ( v154.m_Data )
      {
        if ( !InterlockedDecrement(&v154.m_Data->m_RefCount) && v62 )
        {
          if ( v62->m_wstr )
          {
            SysFreeString(v62->m_wstr);
            v62->m_wstr = 0;
          }
          if ( v62->m_str )
          {
            j_j__free(v62->m_str);
            v62->m_str = 0;
          }
          j__free(v62);
        }
        v154.m_Data = 0;
      }
      LOBYTE(v174) = 1;
      if ( !InterlockedDecrement(v51 + 2) )
      {
        if ( *v51 )
        {
          SysFreeString(*v51);
          *v51 = 0;
        }
        if ( *(v51 + 1) )
        {
          j_j__free(*(v51 + 1));
          *(v51 + 1) = 0;
        }
        j__free(v51);
      }
      v63 = operator new(0xCu);
      v64 = v63;
      v148 = v63;
      LOBYTE(v174) = 32;
      if ( v63 )
      {
        v145 = "\"";
        *(v63 + 1) = 0;
        *(v63 + 2) = 1;
        *v63 = _com_util::ConvertStringToBSTR(v145);
      }
      else
      {
        v64 = 0;
      }
      LOBYTE(v174) = 1;
      *psz = v64;
      if ( !v64 )
        goto LABEL_311;
      LOBYTE(v174) = 33;
      v65 = sub_10018A0(&v151, &v166.m_Data[1].m_str);
      LOBYTE(v174) = 34;
      v66 = sub_10014F0(&v152, "\"creation_datetime\": \"", v65);
      LOBYTE(v174) = 35;
      v67 = _bstr_t::operator+(v66, &v153, psz);
      LOBYTE(v174) = 36;
      v68 = operator new(0xCu);
      v148 = v68;
      LOBYTE(v174) = 37;
      if ( v68 )
      {
        v69 = _bstr_t::Data_t::Data_t(v68, &a2, v67);
        v166.m_Data = v69;
      }
      else
      {
        v69 = 0;
        v166.m_Data = 0;
      }
      LOBYTE(v174) = 36;
      if ( !v69 )
        goto LABEL_311;
      if ( !InterlockedDecrement((*v168 + 8)) )
      {
        v70 = *v168;
        if ( **v168 )
        {
          SysFreeString(**v168);
          v70 = *v168;
          **v168 = 0;
        }
        if ( v70->m_str )
        {
          j_j__free(v70->m_str);
          v70 = *v168;
          *(*v168 + 4) = 0;
        }
        j__free(v70);
      }
      a2.m_Data = v69;
      v71 = v153.m_Data;
      if ( v153.m_Data )
      {
        if ( !InterlockedDecrement(&v153.m_Data->m_RefCount) && v71 )
        {
          if ( v71->m_wstr )
          {
            SysFreeString(v71->m_wstr);
            v71->m_wstr = 0;
          }
          if ( v71->m_str )
          {
            j_j__free(v71->m_str);
            v71->m_str = 0;
          }
          j__free(v71);
        }
        v153.m_Data = 0;
      }
      v72 = v152.m_Data;
      if ( v152.m_Data )
      {
        if ( !InterlockedDecrement(&v152.m_Data->m_RefCount) && v72 )
        {
          if ( v72->m_wstr )
          {
            SysFreeString(v72->m_wstr);
            v72->m_wstr = 0;
          }
          if ( v72->m_str )
          {
            j_j__free(v72->m_str);
            v72->m_str = 0;
          }
          j__free(v72);
        }
        v152.m_Data = 0;
      }
      v73 = v151.m_Data;
      if ( v151.m_Data )
      {
        if ( !InterlockedDecrement(&v151.m_Data->m_RefCount) && v73 )
        {
          if ( v73->m_wstr )
          {
            SysFreeString(v73->m_wstr);
            v73->m_wstr = 0;
          }
          if ( v73->m_str )
          {
            j_j__free(v73->m_str);
            v73->m_str = 0;
          }
          j__free(v73);
        }
        v151.m_Data = 0;
      }
      LOBYTE(v174) = 1;
      if ( !InterlockedDecrement(v64 + 2) )
      {
        if ( *v64 )
        {
          SysFreeString(*v64);
          *v64 = 0;
        }
        if ( *(v64 + 1) )
        {
          j_j__free(*(v64 + 1));
          *(v64 + 1) = 0;
        }
        j__free(v64);
      }
      v74 = operator new(0xCu);
      v75 = v74;
      v148 = v74;
      LOBYTE(v174) = 38;
      if ( v74 )
      {
        v145 = "}";
        *(v74 + 1) = 0;
        *(v74 + 2) = 1;
        *v74 = _com_util::ConvertStringToBSTR(v145);
      }
      else
      {
        v75 = 0;
      }
      LOBYTE(v174) = 1;
      *psz = v75;
      if ( !v75 )
        goto LABEL_311;
      LOBYTE(v174) = 39;
      v76 = operator new(0xCu);
      v148 = v76;
      LOBYTE(v174) = 40;
      v7 = (v76 ? _bstr_t::Data_t::Data_t(v76, &a2, psz) : 0);
      LOBYTE(v174) = 39;
      if ( !v7 )
        goto LABEL_311;
      if ( !InterlockedDecrement(&v166.m_Data->m_RefCount) )
      {
        v77 = v166.m_Data;
        if ( v166.m_Data->m_wstr )
        {
          SysFreeString(v166.m_Data->m_wstr);
          v77 = v166.m_Data;
          v166.m_Data->m_wstr = 0;
        }
        if ( v77->m_str )
        {
          j_j__free(v77->m_str);
          v77 = v166.m_Data;
          v166.m_Data->m_str = 0;
        }
        j__free(v77);
      }
      a2.m_Data = v7;
      LOBYTE(v174) = 1;
      if ( !InterlockedDecrement(v75 + 2) )
      {
        if ( *v75 )
        {
          SysFreeString(*v75);
          *v75 = 0;
        }
        if ( *(v75 + 1) )
        {
          j_j__free(*(v75 + 1));
          *(v75 + 1) = 0;
        }
        j__free(v75);
      }
      ++v165;
      v8 = *v8;
    }
    while ( v8 != v171[2] );
    v6 = SysFreeString;
  }
  v78 = operator new(0xCu);
  v79 = v78;
  v148 = v78;
  LOBYTE(v174) = 41;
  if ( v78 )
  {
    v145 = "]";
    *(v78 + 1) = 0;
    *(v78 + 2) = 1;
    *v78 = _com_util::ConvertStringToBSTR(v145);
  }
  else
  {
    v79 = 0;
  }
  LOBYTE(v174) = 1;
  *psz = v79;
  if ( !v79 )
LABEL_311:
    _com_issue_error(-2147024882);
  LOBYTE(v174) = 42;
  v80 = operator new(0xCu);
  v148 = v80;
  LOBYTE(v174) = 43;
  if ( v80 )
    v81 = _bstr_t::Data_t::Data_t(v80, &a2, psz);
  else
    v81 = 0;
  v151.m_Data = v81;
  LOBYTE(v174) = 42;
  if ( !v81 )
    _com_issue_error(-2147024882);
  if ( v7 && !InterlockedDecrement(&v7->m_RefCount) )
  {
    if ( v7->m_wstr )
    {
      v6(v7->m_wstr);
      v7->m_wstr = 0;
    }
    if ( v7->m_str )
    {
      j_j__free(v7->m_str);
      v7->m_str = 0;
    }
    j__free(v7);
  }
  v82 = v151.m_Data;
  a2.m_Data = v151.m_Data;
  if ( !InterlockedDecrement(v79 + 2) )
  {
    if ( *v79 )
    {
      v6(*v79);
      *v79 = 0;
    }
    if ( *(v79 + 1) )
    {
      j_j__free(*(v79 + 1));
      *(v79 + 1) = 0;
    }
    j__free(v79);
  }
  *v168 = 0;
  v145 = v168;
  v148 = &v144;
  v144 = v82;
  InterlockedIncrement(&v82->m_RefCount);
  v143 = v83;
  a3.m_Data = &v143;
  LOBYTE(v174) = 45;
  _bstr_t::_bstr_t(&v143, L"Content-Type: application/json\r\n");
  LOBYTE(v174) = 46;
  v84 = operator new(0xCu);
  v85 = v84;
  *psz = v84;
  LOBYTE(v174) = 47;
  if ( v84 )
  {
    v142 = "4e3202fdbe953d628f650229af5b3eb49cd46b2d3bfe5546ae3c5fa48b554e0c";
    *(v84 + 1) = 0;
    *(v84 + 2) = 1;
    *v84 = _com_util::ConvertStringToBSTR(v142);
  }
  else
  {
    v85 = 0;
  }
  LOBYTE(v174) = 46;
  *psz = v85;
  if ( !v85 )
    _com_issue_error(-2147024882);
  LOBYTE(v174) = 48;
  v86 = _bstr_t::_bstr_t(&v151, L"/partners/sysinternals/file-reports?apikey=");
  v142 = v87;
  LOBYTE(v174) = 49;
  _bstr_t::operator+(v86, &v142, psz);
  LOBYTE(v174) = 51;
  v88 = sub_1004F00(v171, v142, v143, v144, v145);
  v89 = v151.m_Data;
  dwMessageId = v88;
  if ( v151.m_Data )
  {
    if ( !InterlockedDecrement(&v151.m_Data->m_RefCount) && v89 )
    {
      if ( v89->m_wstr )
      {
        v6(v89->m_wstr);
        v89->m_wstr = 0;
      }
      if ( v89->m_str )
      {
        j_j__free(v89->m_str);
        v89->m_str = 0;
      }
      j__free(v89);
    }
    v151.m_Data = 0;
  }
  LOBYTE(v174) = 44;
  if ( !InterlockedDecrement(v85 + 2) )
  {
    if ( *v85 )
    {
      v6(*v85);
      *v85 = 0;
    }
    if ( *(v85 + 1) )
    {
      j_j__free(*(v85 + 1));
      *(v85 + 1) = 0;
    }
    j__free(v85);
  }
  v90 = dwMessageId;
  v91 = *v168;
  if ( dwMessageId || !*v168 || !**v168 || (v145 = **v168, !SysStringLen(v145)) )
  {
    v130 = 0;
    v170.m_Data = 0;
    LOBYTE(v174) = 56;
    if ( v90 )
    {
      if ( v90 != 232 )
      {
        v131 = sub_1004320(psz, v90);
        if ( &v170 != v131 )
        {
          _bstr_t::_Free(&v170);
          v130 = v131->m_Data;
          v170.m_Data = v130;
          if ( v130 )
            InterlockedIncrement(&v130->m_RefCount);
        }
        _bstr_t::_Free(psz);
        goto LABEL_455;
      }
      v145 = L"Throttled request. Try again later.";
    }
    else
    {
      v145 = L"Unable to connect to VT";
    }
    _bstr_t::operator=(&v170, v145);
    v130 = v170.m_Data;
LABEL_455:
    v132 = v171[2];
    v133 = *v132;
    if ( *v132 != v132 )
    {
      v134 = v171;
      do
      {
        v135 = (v133[2] + 24);
        *psz = v135;
        if ( v135 != &v170 )
        {
          _bstr_t::_Free(v135);
          **psz = v130;
          if ( v130 )
            InterlockedIncrement(&v130->m_RefCount);
        }
        v133 = *v133;
      }
      while ( v133 != v134[2] );
      v91 = *v168;
    }
    v4 = 13;
    v123 = &v170;
    goto LABEL_463;
  }
  v92 = v171;
  *psz = v91->m_wstr;
  sub_1004530(v171, &v167, psz, &v146);
  v145 = v93;
  LOBYTE(v174) = 52;
  _bstr_t::_bstr_t(&v145, "result");
  sub_1004950(&v166, &v146, v145);
  LOBYTE(v174) = 53;
  if ( v166.m_Data )
    v94 = v166.m_Data->m_wstr;
  else
    v94 = 0;
  if ( _wcsicmp(v94, L"-1") )
  {
    v96 = v166.m_Data ? v166.m_Data->m_wstr : 0;
    if ( _wcsicmp(v96, L"0") )
    {
      v145 = v95;
      _bstr_t::_bstr_t(&v145, "data");
      sub_1004950(&v152, &v146, v145);
      LOBYTE(v174) = 54;
      if ( v152.m_Data )
        v97 = v152.m_Data->m_wstr;
      else
        v97 = 0;
      *psz = wcschr(v97, 0x5Bu) + 1;
      v98 = v92[2];
      v99 = *v98;
      if ( *v98 == v98 )
      {
LABEL_397:
        v117 = v92[2];
        v118 = *v117;
        if ( *v117 != v117 )
        {
          do
          {
            v119 = v118[2];
            v120 = *(v119 + 28);
            if ( !v120 || (v121 = *v120) == 0 || !SysStringLen(v121) )
            {
              if ( *(v171 + 24) )
                dwMessageId = sub_10055A0(v171, v119, v168);
              else
                _bstr_t::operator=((v119 + 32), L"Unknown");
            }
            v118 = *v118;
          }
          while ( v118 != v171[2] );
          v91 = *v168;
        }
        v122 = v152.m_Data;
        if ( v152.m_Data && !InterlockedDecrement(&v152.m_Data->m_RefCount) && v122 )
        {
          if ( v122->m_wstr )
          {
            SysFreeString(v122->m_wstr);
            v122->m_wstr = 0;
          }
          if ( v122->m_str )
          {
            j_j__free(v122->m_str);
            v122->m_str = 0;
          }
          j__free(v122);
        }
        v4 = dwMessageId;
        _bstr_t::_Free(&v166);
        v123 = &v167;
        goto LABEL_463;
      }
      v100 = v171;
      while ( 1 )
      {
        v165 = v99[2];
        v101 = sub_1004530(v100, &v151, psz, &v146);
        if ( &v167 == v101 )
          goto LABEL_370;
        _bstr_t::_Free(&v167);
        v102 = *v101;
        v167.m_Data = v102;
        if ( v102 )
          break;
LABEL_371:
        v103 = v151.m_Data;
        if ( v151.m_Data )
        {
          if ( !InterlockedDecrement(&v151.m_Data->m_RefCount) && v103 )
          {
            if ( v103->m_wstr )
            {
              SysFreeString(v103->m_wstr);
              v103->m_wstr = 0;
            }
            if ( v103->m_str )
            {
              j_j__free(v103->m_str);
              v103->m_str = 0;
            }
            j__free(v103);
          }
          v102 = v167.m_Data;
          v151.m_Data = 0;
        }
        if ( v102 )
        {
          v104 = v102->m_wstr;
          if ( v104 )
          {
            if ( SysStringLen(v104) )
            {
              v145 = L"true";
              v144 = v105;
              _bstr_t::_bstr_t(&v144, L"found");
              v106 = sub_1004950(&a3, &v146, v144)->m_Data;
              v107 = v106 ? v106->m_wstr : 0;
              v173 = _wcsicmp(v107, v145) == 0;
              _bstr_t::_Free(&a3);
              if ( v173 )
              {
                v145 = v108;
                _bstr_t::_bstr_t(&v145, L"detection_ratio");
                v109 = sub_1004950(&v154, &v146, v145);
                v110 = (v165 + 32);
                v153.m_Data = v109;
                if ( (v165 + 32) != v109 )
                {
                  _bstr_t::_Free((v165 + 32));
                  v111 = v153.m_Data->m_wstr;
                  *v110 = v153.m_Data->m_wstr;
                  if ( v111 )
                    InterlockedIncrement(v111 + 2);
                }
                _bstr_t::_Free(&v154);
                v145 = v112;
                _bstr_t::_bstr_t(&v145, L"Permalink");
                v113 = sub_1004950(&v155, &v146, v145);
                v114 = (v165 + 28);
                v153.m_Data = v113;
                if ( (v165 + 28) != v113 )
                {
                  _bstr_t::_Free((v165 + 28));
                  v115 = v153.m_Data->m_wstr;
                  *v114 = v153.m_Data->m_wstr;
                  if ( v115 )
                    InterlockedIncrement(v115 + 2);
                }
                _bstr_t::_Free(&v155);
              }
              else
              {
                v116 = v165;
                _bstr_t::operator=((v165 + 32), &gszNullString);
                _bstr_t::operator=((v116 + 28), &gszNullString);
              }
              v99 = *v99;
              if ( v99 != v100[2] )
                continue;
            }
          }
        }
        v91 = *v168;
        v92 = v171;
        goto LABEL_397;
      }
      InterlockedIncrement(&v102->m_RefCount);
LABEL_370:
      v102 = v167.m_Data;
      goto LABEL_371;
    }
  }
  v145 = v95;
  _bstr_t::_bstr_t(&v145, L"message");
  sub_1004950(&v153, &v146, v145);
  LOBYTE(v174) = 55;
  if ( !v153.m_Data || !v153.m_Data->m_wstr || (v145 = v153.m_Data->m_wstr, !SysStringLen(v145)) )
  {
    v4 = 0;
    goto LABEL_444;
  }
  v124 = v92[2];
  v125 = *v124;
  if ( *v124 == v124 )
    goto LABEL_443;
  v126 = v171;
  do
  {
    v151.m_Data = v125[2];
    v127 = _bstr_t::_bstr_t(&v152, "message");
    v128 = *(*sub_1062F90(&v146, &v148, v127) + 20);
    if ( v128 )
      InterlockedIncrement((v128 + 8));
    if ( &v151.m_Data[2] != psz )
    {
      _bstr_t::_Free(&v151.m_Data[2]);
      v151.m_Data[2].m_wstr = v128;
      if ( !v128 )
        goto LABEL_432;
      InterlockedIncrement((v128 + 8));
    }
    if ( v128 && !InterlockedDecrement((v128 + 8)) )
    {
      if ( *v128 )
      {
        SysFreeString(*v128);
        *v128 = 0;
      }
      if ( *(v128 + 4) )
      {
        j_j__free(*(v128 + 4));
        *(v128 + 4) = 0;
      }
      j__free(v128);
    }
LABEL_432:
    v129 = v152.m_Data;
    if ( v152.m_Data )
    {
      if ( !InterlockedDecrement(&v152.m_Data->m_RefCount) && v129 )
      {
        if ( v129->m_wstr )
        {
          SysFreeString(v129->m_wstr);
          v129->m_wstr = 0;
        }
        if ( v129->m_str )
        {
          j_j__free(v129->m_str);
          v129->m_str = 0;
        }
        j__free(v129);
      }
      v152.m_Data = 0;
    }
    v125 = *v125;
  }
  while ( v125 != v126[2] );
  v91 = *v168;
LABEL_443:
  v4 = dwMessageId;
LABEL_444:
  _bstr_t::_Free(&v153);
  _bstr_t::_Free(&v166);
  v123 = &v167;
LABEL_463:
  _bstr_t::_Free(v123);
  v136 = v171;
  v137 = v171[2];
  v138 = *v137;
  *v137 = v137;
  *(v136[2] + 1) = v136[2];
  v136[3] = 0;
  if ( v138 != v136[2] )
  {
    v139 = v136;
    do
    {
      v140 = *v138;
      j__free(v138);
      v138 = v140;
    }
    while ( v140 != v139[2] );
    v91 = *v168;
  }
  if ( v91 && !InterlockedDecrement(&v91->m_RefCount) )
  {
    if ( v91->m_wstr )
    {
      SysFreeString(v91->m_wstr);
      v91->m_wstr = 0;
    }
    if ( v91->m_str )
    {
      j_j__free(v91->m_str);
      v91->m_str = 0;
    }
    j__free(v91);
  }
  _bstr_t::_Free(&a2);
  v2 = v146;
LABEL_475:
  v145 = v2;
  v144 = v2->baseclass._Left;
  v174 = -1;
  sub_1006540(&v146, &v148, v144, v2);
  j__free(v146);
  return v4;
}
// 1094790: using guessed type wchar_t aThrottledReque[36];

//----- (010037E0) --------------------------------------------------------
Data_t_bstr_t *__thiscall sub_10037E0(_DWORD *this)
{
  _DWORD *v1; // ebx
  CSystemProcessInfoMapNode *v2; // eax
  char *v3; // esi
  Data_t_bstr_t *v4; // esi
  _bstr_t *v5; // eax
  _bstr_t *v6; // eax
  _DWORD *v7; // eax
  LONG (__stdcall *v8)(volatile LONG *); // ebx
  _DWORD *v9; // edi
  Data_t_bstr_t *v10; // eax
  Data_t_bstr_t *v11; // esi
  Data_t_bstr_t *v12; // eax
  Data_t_bstr_t *v13; // eax
  Data_t_bstr_t *v14; // esi
  Data_t_bstr_t *v15; // eax
  Data_t_bstr_t *v16; // ebx
  Data_t_bstr_t *v17; // ebx
  CSystemProcessInfoMapNode **v18; // ecx
  void *v19; // ecx
  _DWORD *v20; // edi
  Data_t_bstr_t *v21; // ebx
  const wchar_t **v22; // esi
  const wchar_t *v23; // esi
  Data_t_bstr_t *v24; // edi
  void *v25; // ecx
  wchar_t **v26; // eax
  wchar_t *v27; // ebx
  _bstr_t *v28; // esi
  void *v29; // esi
  CSystemProcessInfoMapNode *v30; // ecx
  OLECHAR *v31; // eax
  OLECHAR *v32; // esi
  BSTR v33; // eax
  Data_t_bstr_t *v34; // eax
  const wchar_t *v35; // eax
  int v36; // eax
  wchar_t *v37; // ecx
  void *v38; // esi
  char v39; // al
  wchar_t *v40; // ecx
  _bstr_t *v41; // eax
  Data_t_bstr_t *v42; // eax
  int v43; // edx
  Data_t_bstr_t *v44; // ecx
  int *v45; // eax
  int v46; // esi
  BSTR v47; // eax
  Data_t_bstr_t *v48; // esi
  Data_t_bstr_t *v49; // esi
  Data_t_bstr_t *v50; // esi
  Data_t_bstr_t *v51; // ecx
  int *v52; // eax
  int v53; // esi
  BSTR v54; // eax
  Data_t_bstr_t *v55; // esi
  wchar_t *v56; // eax
  void *v57; // esi
  void *v58; // esi
  LONG (__stdcall *v59)(volatile LONG *); // edi
  void *v60; // ebx
  Data_t_bstr_t *v61; // esi
  Data_t_bstr_t *v63; // esi
  _bstr_t *v64; // edi
  _DWORD *v65; // eax
  _DWORD *v66; // edi
  Data_t_bstr_t *v67; // eax
  BSTR v68; // ebx
  void *v69; // [esp-10h] [ebp-80h]
  OLECHAR *v70; // [esp-Ch] [ebp-7Ch]
  CSystemProcessInfoMapNode *v71; // [esp-8h] [ebp-78h]
  wchar_t *v72; // [esp-4h] [ebp-74h]
  void *v73; // [esp+10h] [ebp-60h]
  int v74; // [esp+14h] [ebp-5Ch]
  void *v75; // [esp+18h] [ebp-58h]
  _bstr_t v76; // [esp+1Ch] [ebp-54h]
  _bstr_t a1; // [esp+20h] [ebp-50h]
  _bstr_t bstr; // [esp+24h] [ebp-4Ch]
  _bstr_t a3; // [esp+28h] [ebp-48h]
  void *v80; // [esp+2Ch] [ebp-44h]
  void *v81; // [esp+30h] [ebp-40h]
  OLECHAR psz[2]; // [esp+34h] [ebp-3Ch]
  _bstr_t bstrResource; // [esp+38h] [ebp-38h]
  void *v84; // [esp+3Ch] [ebp-34h]
  _bstr_t v85; // [esp+40h] [ebp-30h]
  void *v86; // [esp+44h] [ebp-2Ch]
  void *v87; // [esp+48h] [ebp-28h]
  _bstr_t v88; // [esp+4Ch] [ebp-24h]
  int v89; // [esp+50h] [ebp-20h]
  _bstr_t v90; // [esp+54h] [ebp-1Ch]
  _bstr_t a2; // [esp+58h] [ebp-18h]
  _DWORD *v92; // [esp+5Ch] [ebp-14h]
  char v93; // [esp+63h] [ebp-Dh]
  int v94; // [esp+6Ch] [ebp-4h]

  v1 = this;
  v92 = this;
  v74 = 0;
  v2 = std::_Tree_comp_alloc<std::_Tmap_traits<unsigned long,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *>>,0>>::_Buyheadnode();
  v73 = v2;
  v3 = 0;
  v94 = 0;
  v84 = 0;
  if ( !v1[5] )
  {
    v4 = 232;
    goto LABEL_188;
  }
  _bstr_t::_bstr_t(&bstrResource, "&resource=");
  LOBYTE(v94) = 1;
  v5 = _bstr_t::_bstr_t(&bstr, "4e3202fdbe953d628f650229af5b3eb49cd46b2d3bfe5546ae3c5fa48b554e0c");
  LOBYTE(v94) = 2;
  v6 = sub_10014F0(&a1, "apikey=", v5);
  LOBYTE(v94) = 3;
  _bstr_t::operator+(v6, &a2, &bstrResource);
  _bstr_t::_Free(&a1);
  _bstr_t::_Free(&bstr);
  LOBYTE(v94) = 7;
  _bstr_t::_Free(&bstrResource);
  v7 = v1[4];
  v8 = InterlockedDecrement;
  v9 = *v7;
  if ( *v7 != v7 )
  {
    do
    {
      v80 = v9[2];
      _bstr_t::operator=((v80 + 24), &gszNullString);
      if ( v3 )
      {
        v10 = operator new(0xCu);
        v11 = v10;
        v76.m_Data = v10;
        LOBYTE(v94) = 8;
        if ( v10 )
        {
          v72 = ",";
          v10->m_str = 0;
          v10->m_RefCount = 1;
          v10->m_wstr = _com_util::ConvertStringToBSTR(v72);
        }
        else
        {
          v11 = 0;
        }
        LOBYTE(v94) = 7;
        a3.m_Data = v11;
        if ( !v11 )
          goto LABEL_74;
        LOBYTE(v94) = 9;
        v12 = operator new(0xCu);
        v76.m_Data = v12;
        LOBYTE(v94) = 10;
        v13 = (v12 ? _bstr_t::Data_t::Data_t(v12, &a2, &a3) : 0);
        bstrResource.m_Data = v13;
        LOBYTE(v94) = 9;
        if ( !v13 )
          goto LABEL_74;
        _bstr_t::_Free(&a2);
        a2.m_Data = bstrResource.m_Data;
        if ( !v8(&v11->m_RefCount) )
        {
          if ( v11->m_wstr )
          {
            SysFreeString(v11->m_wstr);
            v11->m_wstr = 0;
          }
          if ( v11->m_str )
          {
            j_j__free(v11->m_str);
            v11->m_str = 0;
          }
          j__free(v11);
        }
      }
      v14 = *(v80 + 2);
      a3.m_Data = v14;
      if ( v14 )
        InterlockedIncrement(&v14->m_RefCount);
      LOBYTE(v94) = 11;
      v15 = operator new(0xCu);
      v76.m_Data = v15;
      LOBYTE(v94) = 12;
      if ( v15 )
      {
        v16 = _bstr_t::Data_t::Data_t(v15, &a2, &a3);
        bstrResource.m_Data = v16;
      }
      else
      {
        v16 = 0;
        bstrResource.m_Data = 0;
      }
      LOBYTE(v94) = 11;
      if ( !v16 )
LABEL_74:
        _com_issue_error(-2147024882);
      v17 = a2.m_Data;
      if ( a2.m_Data && !InterlockedDecrement(&a2.m_Data->m_RefCount) && v17 )
      {
        if ( v17->m_wstr )
        {
          SysFreeString(v17->m_wstr);
          v17->m_wstr = 0;
        }
        if ( v17->m_str )
        {
          j_j__free(v17->m_str);
          v17->m_str = 0;
        }
        j__free(v17);
      }
      v8 = InterlockedDecrement;
      a2.m_Data = bstrResource.m_Data;
      LOBYTE(v94) = 7;
      if ( v14 && !InterlockedDecrement(&v14->m_RefCount) )
      {
        if ( v14->m_wstr )
        {
          SysFreeString(v14->m_wstr);
          v14->m_wstr = 0;
        }
        if ( v14->m_str )
        {
          j_j__free(v14->m_str);
          v14->m_str = 0;
        }
        j__free(v14);
      }
      v9 = *v9;
      v3 = v84 + 1;
      v84 = v84 + 1;
    }
    while ( v9 != v92[4] );
  }
  v84 = 0;
  v72 = &v84;
  v76.m_Data = &v71;
  v18 = &v71;
  v71 = a2.m_Data;
  if ( a2.m_Data )
    InterlockedIncrement(&a2.m_Data->m_RefCount);
  v70 = v18;
  a1.m_Data = &v70;
  LOBYTE(v94) = 14;
  _bstr_t::_bstr_t(&v70, L"Content-Type: application/x-www-form-urlencoded\r\n");
  v69 = v19;
  LOBYTE(v94) = 15;
  _bstr_t::_bstr_t(&v69, L"vtapi/v2/file/report");
  v20 = v92;
  LOBYTE(v94) = 13;
  v21 = sub_1004F00(v92, v69, v70, v71, v72);
  bstrResource.m_Data = v21;
  if ( !v21 )
  {
    v22 = v84;
    if ( v84 )
    {
      if ( *v84 )
      {
        v72 = *v84;
        if ( SysStringLen(v72) )
        {
          v23 = *v22;
          *psz = v23;
          if ( wcschr(v23, 0x5Bu) )
            *psz = wcschr(v23, 0x5Bu) + 1;
          v24 = 0;
          v85.m_Data = 0;
          v25 = v92;
          LOBYTE(v94) = 16;
          v26 = v92[4];
          v27 = *v26;
          if ( *v26 != v26 )
          {
            do
            {
              v89 = *(v27 + 2);
              v28 = sub_1004530(v25, &v81, psz, &v73);
              if ( &v85 != v28 )
              {
                if ( v24 && !InterlockedDecrement(&v24->m_RefCount) )
                {
                  if ( v24->m_wstr )
                  {
                    SysFreeString(v24->m_wstr);
                    v24->m_wstr = 0;
                  }
                  if ( v24->m_str )
                  {
                    j_j__free(v24->m_str);
                    v24->m_str = 0;
                  }
                  j__free(v24);
                }
                v24 = v28->m_Data;
                v85.m_Data = v24;
                if ( v24 )
                  InterlockedIncrement(&v24->m_RefCount);
              }
              v29 = v81;
              if ( v81 )
              {
                if ( !InterlockedDecrement(v81 + 2) && v29 )
                {
                  if ( *v29 )
                  {
                    SysFreeString(*v29);
                    *v29 = 0;
                  }
                  if ( *(v29 + 1) )
                  {
                    j_j__free(*(v29 + 1));
                    *(v29 + 1) = 0;
                  }
                  j__free(v29);
                }
                v81 = 0;
              }
              if ( !v24 )
                break;
              if ( !v24->m_wstr )
                break;
              v72 = v24->m_wstr;
              if ( !SysStringLen(v72) )
                break;
              v72 = L"1";
              v71 = v30;
              v76.m_Data = &v71;
              v31 = operator new(0xCu);
              v32 = v31;
              v75 = v31;
              LOBYTE(v94) = 17;
              if ( v31 )
              {
                v70 = L"response_code";
                *(v31 + 1) = 0;
                *(v31 + 2) = 1;
                v33 = SysAllocString(v70);
                *v32 = v33;
                if ( !v33 )
                  goto LABEL_74;
              }
              else
              {
                v32 = 0;
              }
              LOBYTE(v94) = 16;
              v76.m_Data->m_wstr = v32;
              if ( !v32 )
                goto LABEL_74;
              v34 = sub_1004950(&v80, &v73, v71)->m_Data;
              if ( v34 )
                v35 = v34->m_wstr;
              else
                v35 = 0;
              v36 = _wcsicmp(v35, v72);
              v38 = v80;
              v39 = v36 == 0;
              v93 = v39;
              if ( v80 )
              {
                if ( !InterlockedDecrement(v80 + 2) && v38 )
                {
                  if ( *v38 )
                  {
                    SysFreeString(*v38);
                    *v38 = 0;
                  }
                  if ( *(v38 + 1) )
                  {
                    j_j__free(*(v38 + 1));
                    *(v38 + 1) = 0;
                  }
                  j__free(v38);
                }
                v39 = v93;
                v80 = 0;
              }
              if ( v39 )
              {
                v72 = v37;
                _bstr_t::_bstr_t(&v72, L"positives");
                sub_1004950(&v86, &v73, v72);
                v72 = v40;
                LOBYTE(v94) = 18;
                _bstr_t::_bstr_t(&v72, L"total");
                sub_1004950(&v87, &v73, v72);
                LOBYTE(v94) = 19;
                _bstr_t::_bstr_t(&v88, L"/");
                LOBYTE(v94) = 20;
                v41 = _bstr_t::operator+(&v86, &bstr, &v88);
                LOBYTE(v94) = 21;
                v42 = _bstr_t::operator+(v41, &a3, &v87);
                v43 = v89;
                v44 = v42;
                v76.m_Data = v42;
                v45 = (v89 + 32);
                if ( (v89 + 32) != v76.m_Data )
                {
                  v46 = *v45;
                  if ( *v45 )
                  {
                    if ( !InterlockedDecrement((v46 + 8)) && v46 )
                    {
                      if ( *v46 )
                      {
                        SysFreeString(*v46);
                        *v46 = 0;
                      }
                      if ( *(v46 + 4) )
                      {
                        j_j__free(*(v46 + 4));
                        *(v46 + 4) = 0;
                      }
                      j__free(v46);
                    }
                    v43 = v89;
                    v44 = v76.m_Data;
                    *(v89 + 32) = 0;
                  }
                  v47 = v44->m_wstr;
                  *(v43 + 32) = v44->m_wstr;
                  if ( v47 )
                    InterlockedIncrement(v47 + 2);
                }
                v48 = a3.m_Data;
                if ( a3.m_Data )
                {
                  if ( !InterlockedDecrement(&a3.m_Data->m_RefCount) && v48 )
                  {
                    if ( v48->m_wstr )
                    {
                      SysFreeString(v48->m_wstr);
                      v48->m_wstr = 0;
                    }
                    if ( v48->m_str )
                    {
                      j_j__free(v48->m_str);
                      v48->m_str = 0;
                    }
                    j__free(v48);
                  }
                  a3.m_Data = 0;
                }
                v49 = bstr.m_Data;
                if ( bstr.m_Data )
                {
                  if ( !InterlockedDecrement(&bstr.m_Data->m_RefCount) && v49 )
                  {
                    if ( v49->m_wstr )
                    {
                      SysFreeString(v49->m_wstr);
                      v49->m_wstr = 0;
                    }
                    if ( v49->m_str )
                    {
                      j_j__free(v49->m_str);
                      v49->m_str = 0;
                    }
                    j__free(v49);
                  }
                  bstr.m_Data = 0;
                }
                v50 = v88.m_Data;
                LOBYTE(v94) = 19;
                if ( v88.m_Data )
                {
                  if ( !InterlockedDecrement(&v88.m_Data->m_RefCount) )
                  {
                    if ( v50->m_wstr )
                    {
                      SysFreeString(v50->m_wstr);
                      v50->m_wstr = 0;
                    }
                    if ( v50->m_str )
                    {
                      j_j__free(v50->m_str);
                      v50->m_str = 0;
                    }
                    j__free(v50);
                  }
                  v88.m_Data = 0;
                }
                v72 = v44;
                _bstr_t::_bstr_t(&v72, L"Permalink");
                v51 = sub_1004950(&a1, &v73, v72);
                v52 = (v89 + 28);
                v76.m_Data = v51;
                if ( (v89 + 28) != v51 )
                {
                  v53 = *v52;
                  if ( *v52 )
                  {
                    if ( !InterlockedDecrement((v53 + 8)) && v53 )
                    {
                      if ( *v53 )
                      {
                        SysFreeString(*v53);
                        *v53 = 0;
                      }
                      if ( *(v53 + 4) )
                      {
                        j_j__free(*(v53 + 4));
                        *(v53 + 4) = 0;
                      }
                      j__free(v53);
                    }
                    v51 = v76.m_Data;
                    *(v89 + 28) = 0;
                  }
                  v54 = v51->m_wstr;
                  *(v89 + 28) = v51->m_wstr;
                  if ( v54 )
                    InterlockedIncrement(v54 + 2);
                }
                v55 = a1.m_Data;
                if ( a1.m_Data )
                {
                  if ( !InterlockedDecrement(&a1.m_Data->m_RefCount) && v55 )
                  {
                    if ( v55->m_wstr )
                    {
                      SysFreeString(v55->m_wstr);
                      v55->m_wstr = 0;
                    }
                    if ( v55->m_str )
                    {
                      j_j__free(v55->m_str);
                      v55->m_str = 0;
                    }
                    j__free(v55);
                  }
                  a1.m_Data = 0;
                }
                v56 = v27;
                v27 = *v27;
                v72 = v56;
                **(v56 + 1) = *v56;
                *(*v56 + 4) = *(v56 + 1);
                --v92[5];
                j__free(v72);
                v57 = v87;
                if ( v87 )
                {
                  if ( !InterlockedDecrement(v87 + 2) && v57 )
                  {
                    if ( *v57 )
                    {
                      SysFreeString(*v57);
                      *v57 = 0;
                    }
                    if ( *(v57 + 1) )
                    {
                      j_j__free(*(v57 + 1));
                      *(v57 + 1) = 0;
                    }
                    j__free(v57);
                  }
                  v87 = 0;
                }
                v58 = v86;
                LOBYTE(v94) = 16;
                if ( v86 )
                {
                  if ( !InterlockedDecrement(v86 + 2) && v58 )
                  {
                    if ( *v58 )
                    {
                      SysFreeString(*v58);
                      *v58 = 0;
                    }
                    if ( *(v58 + 1) )
                    {
                      j_j__free(*(v58 + 1));
                      *(v58 + 1) = 0;
                    }
                    j__free(v58);
                  }
                  v86 = 0;
                }
              }
              else
              {
                v27 = *v27;
              }
              v25 = v92;
            }
            while ( v27 != v92[4] );
          }
          _bstr_t::_Free(&v85);
          goto LABEL_170;
        }
      }
    }
  }
  v63 = 0;
  v90.m_Data = 0;
  LOBYTE(v94) = 22;
  if ( !v21 )
  {
    v72 = L"Unable to connect to VT";
    goto LABEL_197;
  }
  if ( v21 == 232 )
  {
    v72 = L"Throttled request. Try again later.";
LABEL_197:
    _bstr_t::operator=(&v90, v72);
    v63 = v90.m_Data;
    goto LABEL_198;
  }
  v64 = sub_1004320(&v76, v21);
  if ( &v90 != v64 )
  {
    _bstr_t::_Free(&v90);
    v63 = v64->m_Data;
    if ( v64->m_Data )
      InterlockedIncrement(&v63->m_RefCount);
  }
  _bstr_t::_Free(&v76);
  v20 = v92;
LABEL_198:
  v65 = v20[4];
  v66 = *v65;
  if ( *v65 != v65 )
  {
    do
    {
      v67 = (v66[2] + 24);
      v76.m_Data = v67;
      if ( v67 != &v90 )
      {
        v68 = v67->m_wstr;
        if ( v67->m_wstr )
        {
          if ( !InterlockedDecrement(v68 + 2) && v68 )
          {
            if ( *v68 )
            {
              SysFreeString(*v68);
              *v68 = 0;
            }
            if ( *(v68 + 1) )
            {
              j_j__free(*(v68 + 1));
              *(v68 + 1) = 0;
            }
            j__free(v68);
          }
          v67 = v76.m_Data;
          v76.m_Data->m_wstr = 0;
        }
        v67->m_wstr = v63;
        if ( v63 )
          InterlockedIncrement(&v63->m_RefCount);
      }
      v66 = *v66;
    }
    while ( v66 != v92[4] );
  }
  bstrResource.m_Data = 13;
  if ( v63 )
  {
    v59 = InterlockedDecrement;
    if ( !InterlockedDecrement(&v63->m_RefCount) )
    {
      if ( v63->m_wstr )
      {
        SysFreeString(v63->m_wstr);
        v63->m_wstr = 0;
      }
      if ( v63->m_str )
      {
        j_j__free(v63->m_str);
        v63->m_str = 0;
      }
      j__free(v63);
    }
    goto LABEL_171;
  }
LABEL_170:
  v59 = InterlockedDecrement;
LABEL_171:
  v60 = v84;
  if ( v84 && !v59(v84 + 2) )
  {
    if ( *v60 )
    {
      SysFreeString(*v60);
      *v60 = 0;
    }
    if ( *(v60 + 1) )
    {
      j_j__free(*(v60 + 1));
      *(v60 + 1) = 0;
    }
    j__free(v60);
  }
  v61 = a2.m_Data;
  if ( a2.m_Data )
  {
    if ( !v59(&a2.m_Data->m_RefCount) && v61 )
    {
      if ( v61->m_wstr )
      {
        SysFreeString(v61->m_wstr);
        v61->m_wstr = 0;
      }
      if ( v61->m_str )
      {
        j_j__free(v61->m_str);
        v61->m_str = 0;
      }
      j__free(v61);
    }
    a2.m_Data = 0;
  }
  v4 = bstrResource.m_Data;
  v2 = v73;
LABEL_188:
  v72 = v2;
  v71 = v2->baseclass._Left;
  v94 = -1;
  sub_1006540(&v73, &v75, v71, v2);
  j__free(v73);
  return v4;
}
// 1094790: using guessed type wchar_t aThrottledReque[36];

//----- (01004320) --------------------------------------------------------
int __stdcall sub_1004320(int a1, DWORD dwMessageId)
{
  HMODULE v2; // eax
  wchar_t *i; // esi
  int v4; // eax
  WCHAR Buffer; // [esp+Ch] [ebp-804h]

  Buffer = 0;
  if ( !FormatMessageW(0x1200u, 0, dwMessageId, 0, &Buffer, 0x400u, 0) )
  {
    v2 = GetModuleHandleW(L"winhttp.dll");
    FormatMessageW(0xA00u, v2, dwMessageId, 0, &Buffer, 0x400u, 0);
  }
  if ( Buffer )
  {
    for ( i = wcschr(&Buffer, 0); i > &Buffer; *i = 0 )
    {
      v4 = *(i - 1);
      --i;
      if ( !isspace(v4) )
        break;
    }
  }
  else
  {
    _swprintf(&Buffer, L"Error %d (0x%0x)", dwMessageId, dwMessageId);
  }
  _bstr_t::_bstr_t(a1, &Buffer);
  return a1;
}

//----- (01004420) --------------------------------------------------------
DWORD __stdcall sub_1004420(void *a1, int a2, int a3)
{
  const WCHAR *v3; // eax
  HANDLE v4; // esi
  DWORD v5; // edi
  DWORD v6; // edi
  void *v7; // ebx
  LARGE_INTEGER FileSize; // [esp+0h] [ebp-Ch]
  DWORD NumberOfBytesRead; // [esp+8h] [ebp-4h]

  if ( a1 )
    v3 = *a1;
  else
    v3 = 0;
  v4 = CreateFileW(v3, 0x80000000, 7u, 0, 3u, 0, 0);
  if ( v4 == -1 )
  {
    v5 = GetLastError();
  }
  else
  {
    GetFileSizeEx(v4, &FileSize);
    v6 = FileSize.LowPart;
    if ( FileSize.QuadPart <= 0x2000000 )
    {
      v7 = malloc(FileSize.LowPart);
      if ( ReadFile(v4, v7, v6, &NumberOfBytesRead, 0) )
      {
        CloseHandle(v4);
        v5 = 0;
        *a2 = v7;
        *a3 = FileSize.LowPart;
      }
      else
      {
        free(v7);
        CloseHandle(v4);
        v5 = GetLastError();
      }
    }
    else
    {
      v5 = 223;
    }
  }
  if ( a1 && !InterlockedDecrement(a1 + 2) && a1 )
  {
    if ( *a1 )
    {
      SysFreeString(*a1);
      *a1 = 0;
    }
    if ( *(a1 + 1) )
    {
      j_j__free(*(a1 + 1));
      *(a1 + 1) = 0;
    }
    j__free(a1);
  }
  return v5;
}
