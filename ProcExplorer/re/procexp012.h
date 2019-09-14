
//----- (01017A90) --------------------------------------------------------
int sub_1017A90(HWND hWnd, ...)
{
  int v1; // esi
  int result; // eax
  LVITEMW lParam; // [esp+8h] [ebp-10F8h]
  char v4; // [esp+3Ch] [ebp-10C4h]
  va_list va; // [esp+110Ch] [ebp+Ch]

  va_start(va, hWnd);
  memmove_0(&v4, va, 0x10C0u);
  memset(&lParam.iItem, 0, 0x30u);
  lParam.mask = 13;
  lParam.iItem = 0x7FFFFFFF;
  lParam.iSubItem = 0;
  lParam.state = 0;
  lParam.stateMask = 0;
  lParam.pszText = -1;
  lParam.iImage = 0;
  v1 = malloc(0x10C0u);
  if ( !v1 )
    return 0;
  memmove_0(v1, &v4, 0x10C0u);
  *(v1 + 4) = 2;
  *(v1 + 8) = gdwRefreshCount + 1;
  lParam.lParam = v1;
  if ( SendMessageW(hWnd, LVM_INSERTITEMW, 0, &lParam) == -1 )
    return 0;
  *(v1 + 4284) = 0;
  *(v1 + 4280) = dword_10C539C;
  if ( dword_10C539C )
    *(dword_10C539C + 0x10BC) = v1;
  result = 1;
  dword_10C539C = v1;
  return result;
}
// 10CA11C: using guessed type int gdwRefreshCount;

//----- (01017BC0) --------------------------------------------------------
tagTREEVIEWLISTITEMPARAM *__cdecl CTreeList::FindItem(HWND hWnd, LPARAM lParam)
{
  tagTREEVIEWLISTITEMPARAM *pItemParam; // eax
  tagTREEVIEWLISTITEMPARAM *pItemParam_1; // ebx
  WCHAR *v4; // eax
  tagTREEVIEWLISTITEMPARAM *pItemParam_2; // ecx
  CTreeList *pTreeList; // eax
  HICON v7; // ST0C_4
  struct _IMAGELIST *v8; // eax
  int nImage; // eax
  bool v10; // zf
  LRESULT (__stdcall *SendMessageW)(HWND, UINT, WPARAM, LPARAM); // esi
  tagTREEVIEWLISTITEMPARAM *v12; // eax
  LRESULT v13; // eax
  WPARAM v14; // eax
  LVFINDINFOW FindInfo; // [esp+4h] [ebp-18h]

  ::SendMessageW(hWnd, WM_SETREDRAW, 0, 0);
  pItemParam = malloc(sizeof(tagTREEVIEWLISTITEMPARAM));
  pItemParam_1 = pItemParam;
  if ( pItemParam )
  {
    qmemcpy(pItemParam, lParam, sizeof(tagTREEVIEWLISTITEMPARAM));
    pItemParam->nRefCount = 1;
    pItemParam->nListType = 0;
    pItemParam->field_8 = gdwRefreshCount + 1;
    v4 = pItemParam->szProcessName;
    if ( !v4 )
      v4 = pItemParam_1->szProcessName2;
    pItemParam_1->pszComments = ProcessComment_Find(v4);
    pItemParam_1->field_2C = -1;
    pItemParam_1->m_Next = 0;
    pItemParam_1->m_Prev = gpTreeViewListItemParam;
    if ( gpTreeViewListItemParam )
      gpTreeViewListItemParam->m_Next = pItemParam_1;
    gpTreeViewListItemParam = pItemParam_1;
    if ( pItemParam_1->dwProcessId )
    {
      pItemParam_2 = pItemParam_1;
      while ( pItemParam_1->InheritedFromUniqueProcessId != pItemParam_2->dwProcessId
           || *&pItemParam_2->CreateTime > *&pItemParam_1->CreateTime )
      {
        pItemParam_2 = pItemParam_2->m_Prev;
        if ( !pItemParam_2 )
          goto LABEL_17;
      }
      pItemParam_1->pItemParam = pItemParam_2;
      while ( pItemParam_2->dwStyle & TVIF_PARAM )
      {
        pItemParam_2 = pItemParam_2->pItemParam;
        if ( !pItemParam_2 )
          goto LABEL_17;
      }
      pItemParam_1->dwStyle &= -3u;
    }
LABEL_17:
    pTreeList = CTreeList::GetTreeList(hWnd);
    if ( pItemParam_1->hIcon )
    {
      v7 = pItemParam_1->hIcon;
      v8 = CTreeList::GetImageList(pTreeList);
      nImage = ImageList_ReplaceIcon(v8, -1, v7);
    }
    else
    {
      nImage = 0;
    }
    v10 = (pItemParam_1->dwStyle & TVIF_IMAGE) == 0;
    pItemParam_1->nImage = nImage;
    if ( v10
      || (!sub_10250E0(pItemParam_1->szProcessName2) ? (pItemParam_1->dwStyle &= -2u) : (pItemParam_1->dwStyle |= 1u),
          pItemParam_1->dwStyle & 1 && gConfig.byte_14012ADFE) )
    {
      SendMessageW = ::SendMessageW;
    }
    else
    {
      sub_1017F20(hWnd, pItemParam_1);
      SendMessageW = ::SendMessageW;
      ::SendMessageW(ghWndTreeListView, 0x2000u, pItemParam_1->field_5B8, pItemParam_1->field_30 != 0);
    }
    v12 = pItemParam_1->pItemParam;
    if ( v12 )
    {
      if ( ++v12->field_30 == 1 )
      {
        if ( pItemParam_1->pItemParam->dwStyle & TVIF_IMAGE )
        {
          FindInfo.flags = 1;
          FindInfo.lParam = pItemParam_1->pItemParam;
          v13 = SendMessageW(ghWndTreeListView, LVM_FINDITEMW, 0xFFFFFFFF, &FindInfo);
          SendMessageW(ghWndTreeListView, LVM_REDRAWITEMS, v13, v13);
          v14 = pItemParam_1->pItemParam->field_5B8;
          if ( v14 )
          {
            SendMessageW(ghWndTreeListView, TREELIST_MSG_2000, v14, 1);
            if ( pItemParam_1->dwStyle & TVIF_IMAGE )
              SendMessageW(ghWndTreeListView, TREELIST_MSG_2001, pItemParam_1->pItemParam->field_5B8, 1);
          }
        }
      }
    }
    pItemParam = pItemParam_1;
  }
  return pItemParam;
}
// 10CA11C: using guessed type int gdwRefreshCount;

//----- (01017DD0) --------------------------------------------------------
tagTREEVIEWLISTITEMPARAM *__cdecl sub_1017DD0(HWND hWnd, void *pItem)
{
  tagTREEVIEWLISTITEMPARAM *result; // eax
  tagTREEVIEWLISTITEMPARAM *v3; // ebx
  LVITEMW lParam; // [esp+4h] [ebp-34h]

  memset(&lParam.iItem, 0, 0x30u);
  lParam.mask = 13;
  lParam.iItem = 0x7FFFFFFF;
  lParam.iSubItem = 0;
  lParam.state = 0;
  lParam.stateMask = 0;
  lParam.pszText = -1;
  lParam.iImage = 0;
  lParam.lParam = 0;
  result = malloc(0x890u);
  v3 = result;
  if ( result )
  {
    qmemcpy(result, &pItem, 0x890u);
    lParam.lParam = result;
    if ( SendMessageW(hWnd, LVM_INSERTITEMW, 0, &lParam) == -1 )
      v3 = 0;
    result = v3;
  }
  return result;
}

//----- (01017E70) --------------------------------------------------------
tagItem290_PageProcThreads *__cdecl tagItem290_PageProcThreads_InsertToList(HWND hWnd, char a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, int a19, int a20, int a21, int a22, int a23, int a24, int a25, int a26, int a27, int a28, int a29, int a30, int a31, int a32, int a33, int a34, int a35, int a36, int a37, int a38, int a39, int a40, int a41, int a42, int a43, int a44, int a45, int a46, int a47, int a48, int a49, int a50, int a51, int a52, int a53, int a54, int a55, int a56, int a57, int a58, int a59, int a60, int a61, int a62, int a63)
{
  tagItem290_PageProcThreads *result; // eax
  tagItem290_PageProcThreads **v66; // ecx
  LVITEMW Item; // [esp+0h] [ebp-34h]

  memset(&Item.iItem, 0, 0x30u);
  Item.mask = 0xD;
  Item.iItem = 0x7FFFFFFF;
  Item.iSubItem = 0;
  Item.state = 0;
  Item.stateMask = 0;
  Item.pszText = -1;
  Item.iImage = 0;
  Item.lParam = 0;
  result = malloc(0x290u);
  if ( result )
  {
    qmemcpy(result, &a2, sizeof(tagItem290_PageProcThreads));
    v66 = a65;
    Item.lParam = result;
    result->m_Next = *a65;
    *v66 = result;
    result = (SendMessageW(hWnd, LVM_INSERTITEMW, 0, &Item) != -1);
  }
  return result;
}
// 1017E70: too many input arguments, some ignored

//----- (01017F20) --------------------------------------------------------
int __cdecl sub_1017F20(HWND hWnd, tagTREEVIEWLISTITEMPARAM *pItemParam)
{
  int result; // eax
  tagTREEVIEWLISTITEMPARAM *v3; // ecx
  tagTREEVIEWLISTITEMPARAM *v4; // eax
  LRESULT v5; // eax
  int v6; // eax
  bool v7; // zf
  tagTREEVIEWLISTITEMPARAM *v8; // eax
  LPARAM lParam; // [esp+4h] [ebp-10h]
  tagTREEVIEWLISTITEMPARAM *v10; // [esp+8h] [ebp-Ch]
  int (__cdecl *v11)(_DWORD *, _DWORD *); // [esp+Ch] [ebp-8h]
  bool v12; // [esp+13h] [ebp-1h]

  v12 = gConfig.bShowProcessTree != 0;
  result = pItemParam->field_5B8;
  if ( !result )
  {
    if ( gConfig.bShowProcessTree && (v3 = pItemParam->pItemParam) != 0 && v3->dwStyle & 2 )
    {
      v4 = v3->field_5B8;
      if ( !v4 )
      {
        if ( pItemParam->dwStyle & TVIF_IMAGE )
          v4 = sub_1017F20(hWnd, pItemParam->pItemParam);
        else
          v4 = pItemParam;
      }
    }
    else
    {
      v4 = 0;
    }
    lParam = v4;
    v10 = pItemParam;
    v11 = sub_1021AF0;
    v5 = SendMessageW(hWnd, TREELIST_MSG_2004, 0, &lParam);
    pItemParam->field_5B8 = v5;
    v6 = SendMessageW(hWnd, TREELIST_MSG_2005, v5, 0);
    v7 = v12 == 0;
    pItemParam->field_2C = v6;
    if ( v7 )
    {
      if ( pItemParam->field_30 )
        SendMessageW(hWnd, TREELIST_MSG_2000, pItemParam->field_5B8, 1);
      SendMessageW(hWnd, TREELIST_MSG_2001, pItemParam->field_5B8, (pItemParam->dwStyle >> 2) & 1);
      v8 = pItemParam->pItemParam;
      if ( v8 && !v8->field_30 )
      {
        if ( !v8->field_5B8 )
          sub_1017F20(hWnd, pItemParam->pItemParam);
        SendMessageW(hWnd, TREELIST_MSG_2000, pItemParam->pItemParam->field_5B8, 1);
        SendMessageW(
          hWnd,
          TREELIST_MSG_2001,
          pItemParam->pItemParam->field_5B8,
          (pItemParam->pItemParam->dwStyle >> TVIF_IMAGE) & 1);
      }
    }
    else
    {
      if ( pItemParam->field_30 )
        SendMessageW(hWnd, TREELIST_MSG_2000, pItemParam->field_5B8, 1);
      SendMessageW(hWnd, TREELIST_MSG_2001, pItemParam->field_5B8, (pItemParam->dwStyle >> 2) & 1);
    }
    result = pItemParam->field_5B8;
  }
  return result;
}

//----- (01018070) --------------------------------------------------------
void __cdecl TreeViewItemParam_InitGraph(tagTREEVIEWLISTITEMPARAM *pItem)
{
  CGraphData *v1; // eax
  CGraphData *v2; // eax
  int v3; // eax
  CGraphData *v4; // eax
  CGraphData *v5; // eax
  CGraphData *v6; // eax
  CGraphData *v7; // eax
  CGraphData *v8; // eax
  CGraphData *v9; // eax

  if ( !pItem->pGraphData1 )
  {
    v1 = InitGraphData(1, 2, 0);
    pItem->pGraphData1 = v1;
    v1->m_nItemID = 0;
    pItem->pGraphData1->m_Color = 0x3C943C;
    pItem->pGraphData1->m_dbMemorySize = db_onehundred;
    v2 = pItem->pGraphData1;
    if ( v2->m_nChildID == 2 )
    {
      v2->m_Item[0].Color = 255;
      pItem->pGraphData1->m_Item[0].dbMemorySize = db_onehundred;
    }
    v3 = pItem->dwProcessId;
    if ( v3 )
    {
      if ( v3 == -10 )
        pItem->pGraphData1->m_Color = 255;
    }
    else
    {
      pItem->pGraphData1->m_Item[0].Color = 0x3C943C;
    }
  }
  if ( !pItem->pGraphData2 )
  {
    v4 = InitGraphData(1, 1, 0);
    pItem->pGraphData2 = v4;
    v4->m_nItemID = 1;
    pItem->pGraphData2->m_Color = 0xAAAA;
    pItem->pGraphData2->m_dbMemorySize = db_onehundred;
  }
  if ( !pItem->pGraphDataPROCCPU )
  {
    v5 = InitGraphData(1, 2, 0);
    pItem->pGraphDataPROCCPU = v5;
    v5->m_nItemID = 2;
    pItem->pGraphDataPROCCPU->m_Color = 0xC83C1E;
    pItem->pGraphDataPROCCPU->m_dbMemorySize = db_one;
    pItem->pGraphDataPROCCPU->m_Item[0].Color = 0xC83CC8;
    pItem->pGraphDataPROCCPU->m_Item[0].dbMemorySize = db_one;
  }
  if ( gdwAdapterRuntingTime )
  {
    v6 = InitGraphData(1, 1, 0);
    pItem->pGraphData4 = v6;
    v6->m_nItemID = 4;
    pItem->pGraphData4->m_Color = 0x8080FF;
    pItem->pGraphData4->m_dbMemorySize = db_onehundred;
    v7 = InitGraphData(1, 1, 0);
    pItem->pGraphData5 = v7;
    v7->m_nItemID = 7;
    pItem->pGraphData5->m_Color = 0xFFC080;
    pItem->pGraphData5->m_dbMemorySize = db_one;
    v8 = InitGraphData(1, 1, 0);
    LODWORD(pItem->pGraphData6) = v8;
    v8->m_nItemID = 5;
    *(LODWORD(pItem->pGraphData6) + 48) = 0xAAAA;
    *(LODWORD(pItem->pGraphData6) + 40) = db_one;
    v9 = InitGraphData(1, 1, 0);
    pItem->pGraphData7 = v9;
    v9->m_nItemID = 6;
    pItem->pGraphData7->m_Color = 0x4080FF;
    pItem->pGraphData7->m_dbMemorySize = db_one;
  }
}
// 109CDC0: using guessed type double db_onehundred;

//----- (010182A0) --------------------------------------------------------
struct _IMAGELIST *InitSortableImageList()
{
  struct _IMAGELIST *himl; // ST20_4
  HICON v1; // edi
  HICON v2; // ebx

  himl = ImageList_Create(16, 16, 1u, 256, 256);
  v1 = LoadIconW(ghInstance, 0xCB);
  v2 = LoadIconW(ghInstance, 0x71);
  ImageList_ReplaceIcon(himl, -1, v1);
  ImageList_ReplaceIcon(himl, -1, v2);
  return himl;
}

//----- (01018300) --------------------------------------------------------
HWND __cdecl CreateListCtrl(HWND hWnd, DWORD dwStyle, int a3, int a4, LONG dwNewLong, HMENU hMenu)
{
  HWND v6; // eax
  HWND v7; // esi
  HFONT v9; // ST28_4
  HWND v10; // eax
  HWND v11; // eax
  struct _IMAGELIST *v12; // esi
  LONG v13; // eax
  HWND v14; // [esp+8h] [ebp-18h]
  struct tagRECT Rect; // [esp+Ch] [ebp-14h]

  _mm_storeu_si128(&Rect, 0i64);
  InitCommonControls();
  GetClientRect(hWnd, &Rect);
  v6 = CreateWindowExW(
         0,
         L"SysListView32",
         &gszNullString,
         dwStyle,
         Rect.left,
         Rect.top,
         Rect.right,
         Rect.bottom,
         hWnd,
         hMenu,
         ghInstance,
         0);
  v7 = v6;
  v14 = v6;
  if ( !v6 )
    return 0;
  if ( !InitListHeader(v6, a3, a4, dwNewLong) )
  {
    DestroyWindow(v7);
    return 0;
  }
  SetClassLongW(v7, -12, 0);
  gOldListWndProc = SetWindowLongW(v7, -4, Proxy_ListCtrlWndProc);
  SendMessageW(v7, 0x1036u, 0x4030u, 16432);
  v9 = ghConfigFont;
  v10 = SendMessageW(v7, 0x101Fu, 0, 0);
  SendMessageW(v10, 0x30u, v9, 0);
  SendMessageW(v7, 0x30u, ghConfigFont, 0);
  v11 = SendMessageW(v7, 0x104Eu, 0, 0);
  CTreeList::InitToolTips(v11);
  v12 = InitSortableImageList();
  v13 = GetWindowLongW(v14, -16);
  SetWindowLongW(v14, -16, v13 | 0x40);
  SendMessageW(v14, 0x1003u, 1u, v12);
  return v14;
}

//----- (01018460) --------------------------------------------------------
void __cdecl sub_1018460(tagTREEVIEWLISTITEMPARAM *a1)
{
  tagTREEVIEWLISTITEMPARAM *v1; // eax
  bool v2; // zf
  LRESULT nItem; // eax
  int v4; // eax
  tagTREEVIEWLISTITEMPARAM *v5; // ecx
  tagTREEVIEWLISTITEMPARAM *v6; // ecx
  tagTREEVIEWLISTITEMPARAM *i; // eax
  LVFINDINFOW FindInfo; // [esp+8h] [ebp-18h]

  SendMessageW(ghWndTreeListView, 0xBu, 0, 0);
  byte_10C53B5 = 1;
  v1 = a1->pItemParam;
  if ( v1 )
  {
    v2 = v1->field_30-- == 1;
    if ( v2 )
    {
      if ( a1->pItemParam->dwStyle & 2 )
      {
        FindInfo.lParam = a1->pItemParam;
        FindInfo.flags = LVFI_PARAM;
        nItem = SendMessageW(ghWndTreeListView, LVM_FINDITEMW, 0xFFFFFFFF, &FindInfo);
        SendMessageW(ghWndTreeListView, LVM_REDRAWITEMS, nItem, nItem);
        v4 = a1->pItemParam->field_5B8;
        if ( v4 )
          SendMessageW(ghWndTreeListView, 0x2000u, v4, 0);
      }
    }
  }
  v5 = a1->m_Next;
  if ( v5 )
    v5->m_Prev = a1->m_Prev;
  else
    gpTreeViewListItemParam = a1->m_Prev;
  v6 = a1->m_Prev;
  if ( v6 )
    v6->m_Next = a1->m_Next;
  for ( i = gpTreeViewListItemParam; i; i = i->m_Prev )
  {
    if ( i->InheritedFromUniqueProcessId == a1->dwProcessId )
    {
      i->pItemParam = 0;
      if ( gConfig.bShowAllUsers || i->dwStyle & 0x40 )
        i->dwStyle |= 2u;
      if ( !(a1->dwStyle & 4) )
        i->dwStyle &= 0xFFFFFFFB;
    }
  }
  TreeViewListItemParam_Release(a1);
}
// 10C53B5: using guessed type char byte_10C53B5;

//----- (01018570) --------------------------------------------------------
tagTREEVIEWLISTITEMPARAM *__cdecl sub_1018570(HWND hWnd, tagTREEVIEWLISTITEMPARAM *a2)
{
  tagTREEVIEWLISTITEMPARAM *result; // eax
  LPARAM lParam; // [esp+Ch] [ebp-18h]
  tagTREEVIEWLISTITEMPARAM *v4; // [esp+14h] [ebp-10h]

  lParam = 1;
  v4 = a2;
  result = SendMessageW(hWnd, LVM_FINDITEMW, 0xFFFFFFFF, &lParam);
  if ( result >= 0 )
  {
    SendMessageW(hWnd, LVM_DELETEITEM, result, 0);
    result = a2->pItemParam;
    if ( result )
    {
      if ( result->field_30 )
      {
        result = result->field_5B8;
        if ( result )
        {
          result = SendMessageW(hWnd, 0x2002u, result, 0);
          if ( !result )
          {
            SendMessageW(hWnd, 0x2000u, a2->pItemParam->field_5B8, 1);
            result = SendMessageW(hWnd, 0x2003u, a2->pItemParam->field_5B8, 0);
          }
        }
      }
    }
  }
  return result;
}

//----- (01018600) --------------------------------------------------------
void __cdecl DLLLISTITEMPARAM_Release(tagTREEVIEWLISTITEMPARAM *lpAddend)
{
  if ( !InterlockedDecrement(&lpAddend->field_0) )
  {
    if ( *lpAddend->gap154 )
      free(*lpAddend->gap154);
    if ( lpAddend->field_150 )
      free(lpAddend->field_150);
    if ( *&lpAddend->gap154[4] )
      free(*&lpAddend->gap154[4]);
    if ( *&lpAddend->gap154[16] )
      free(*&lpAddend->gap154[16]);
    if ( *&lpAddend->gap154[20] )
      free(*&lpAddend->gap154[20]);
    if ( *&lpAddend->gap154[8] )
      free(*&lpAddend->gap154[8]);
    free(lpAddend);
  }
}

//----- (01018690) --------------------------------------------------------
void __cdecl TreeViewListItemParam_Release(tagTREEVIEWLISTITEMPARAM *a1)
{
  CGraphData *v1; // eax
  CGraphData *v2; // eax
  CGraphData *v3; // eax

  if ( !InterlockedDecrement(&a1->nRefCount) )
  {
    if ( a1->hIcon )
      DestroyIcon(a1->hIcon);
    if ( a1->hFileIcon )
      DestroyIcon(a1->hFileIcon);
    if ( a1->field_344 )
      free(a1->field_344);
    if ( a1->pszValue314 )
      free(a1->pszValue314);
    if ( a1->pszTitle )
      free(a1->pszTitle);
    if ( a1->pNetCclrInfo )
      free(a1->pNetCclrInfo);
    if ( a1->szProcessName )
      free(a1->szProcessName);
    if ( a1->szProcessName2 )
      free(a1->szProcessName2);
    if ( a1->pszName )
      free(a1->pszName);
    if ( a1->pszSystemName )
      free(a1->pszSystemName);
    if ( a1->pszComments )
      free(a1->pszComments);
    if ( a1->pszCommandLine )
      free(a1->pszCommandLine);
    if ( a1->pszEnvBlock )
      free(a1->pszEnvBlock);
    if ( a1->pszCurrentDirectory )
      free(a1->pszCurrentDirectory);
    if ( a1->field_350 )
      free(a1->field_350);
    if ( a1->pszCompany )
      free(a1->pszCompany);
    if ( a1->pszFileDesc )
      free(a1->pszFileDesc);
    if ( a1->m_ExtensionName )
      free(a1->m_ExtensionName);
    if ( a1->pszFullUserName )
      free(a1->pszFullUserName);
    if ( a1->field_334 )
      free(a1->field_334);
    if ( a1->pszPackageFullName )
      free(a1->pszPackageFullName);
    if ( a1->field_33C )
      free(a1->field_33C);
    if ( a1->bSupportWMIProviders )
      sub_10639A0(&a1->bSupportWMIProviders);
    if ( a1->field_3A0 )
      free(a1->field_3A0);
    v1 = a1->pGraphData1;
    if ( v1 )
      GraphData_Release(v1, 1);
    v2 = a1->pGraphData2;
    if ( v2 )
      GraphData_Release(v2, 1);
    v3 = a1->pGraphDataPROCCPU;
    if ( v3 )
      GraphData_Release(v3, 1);
    free(a1);
  }
}

//----- (010188B0) --------------------------------------------------------
char __cdecl CMainWnd::DrawList(LPDRAWITEMSTRUCT pDrawItemStruct)
{
  LONG nColumn; // eax
  int nItem; // ecx
  WPARAM v3; // edi
  char v4; // si
  unsigned int v6; // ecx
  __m128i v7; // xmm1
  char *v8; // edx
  unsigned int v9; // eax
  __m128i v10; // xmm0
  unsigned int v11; // esi
  unsigned int v12; // edi
  LONG v13; // ecx
  unsigned int v14; // edi
  __m128i v15; // xmm1
  char *v16; // ecx
  unsigned int v17; // eax
  __m128i v18; // xmm0
  DWORD v19; // edi
  WPARAM v20; // eax
  HWND v21; // edi
  COLORREF v22; // eax
  COLORREF v23; // eax
  LPARAM v24; // [esp+Ch] [ebp-43B0h]
  WPARAM v25; // [esp+14h] [ebp-43A8h]
  wchar_t *v26; // [esp+20h] [ebp-439Ch]
  int v27; // [esp+24h] [ebp-4398h]
  tagLVITEMW lvitem; // [esp+40h] [ebp-437Ch]
  LVCOLUMNW ColumnInfo; // [esp+74h] [ebp-4348h]
  unsigned int v30; // [esp+94h] [ebp-4328h]
  COLORREF TextColor; // [esp+98h] [ebp-4324h]
  DWORD bFocused; // [esp+9Ch] [ebp-4320h]
  COLORREF BackColor; // [esp+A0h] [ebp-431Ch]
  HWND hWnd; // [esp+A4h] [ebp-4318h]
  RECT rect; // [esp+A8h] [ebp-4314h]
  LPARAM lParam[4]; // [esp+B8h] [ebp-4304h]
  char v37; // [esp+C8h] [ebp-42F4h]
  WPARAM wParam[4]; // [esp+238h] [ebp-4184h]
  char v39; // [esp+248h] [ebp-4174h]
  wchar_t Src; // [esp+3B8h] [ebp-4004h]

  hWnd = pDrawItemStruct->hwndItem;
  nColumn = GetWindowLongW(hWnd, GWLP_USERDATA);
  nItem = pDrawItemStruct->itemID;
  v3 = nColumn;
  v30 = nColumn;
  lvitem.mask = 0xE;
  lvitem.iItem = nItem;
  lvitem.iSubItem = 0;
  SendMessageW(hWnd, LVM_GETITEMW, 0, &lvitem);
  LOBYTE(bFocused) = pDrawItemStruct->itemState & LVIS_FOCUSED;
  v4 = bFocused;
  QueryListItemColor(hWnd, pDrawItemStruct->itemData, bFocused, &TextColor, &BackColor);
  SetTextColor(pDrawItemStruct->hDC, TextColor);
  SetBkMode(pDrawItemStruct->hDC, 2);
  SetBkColor(pDrawItemStruct->hDC, BackColor);
  if ( hWnd == ghWndTreeListView )
    return sub_10156D0(
             v4,
             pDrawItemStruct->itemData,
             gConfig.dwProcessColumnMap[pDrawItemStruct->itemAction],
             pDrawItemStruct->hDC,
             &pDrawItemStruct->rcItem);
  if ( !SendMessageW(hWnd, LVM_GETCOLUMNORDERARRAY, v3, wParam) )
  {
    v6 = 0;
    if ( v3 )
    {
      if ( v3 >= 8 )
      {
        v7 = _mm_load_si128(&gIntArray);
        v8 = &v39;
        do
        {
          v9 = v6 + 4;
          v8 += 32;
          v10 = _mm_add_epi32(_mm_shuffle_epi32(_mm_cvtsi32_si128(v6), 0), v7);
          v6 += 8;
          _mm_storeu_si128(v8 - 3, v10);
          _mm_storeu_si128(v8 - 2, _mm_add_epi32(_mm_shuffle_epi32(_mm_cvtsi32_si128(v9), 0), v7));
        }
        while ( v6 < v3 - (v3 & 7) );
      }
      for ( ; v6 < v3; ++v6 )
        wParam[v6] = v6;
    }
  }
  v11 = 0;
  BackColor = 0;
  if ( v3 )
  {
    do
    {
      ColumnInfo.mask = 3;
      v12 = v11;
      SendMessageW(hWnd, LVM_GETCOLUMNW, wParam[v11], &ColumnInfo);
      v13 = pDrawItemStruct->rcItem.left;
      bFocused = ColumnInfo.cx;
      rect.left = v13 + BackColor;
      rect.top = pDrawItemStruct->rcItem.top;
      rect.bottom = pDrawItemStruct->rcItem.bottom;
      rect.right = BackColor + v13 + ColumnInfo.cx;
      if ( hWnd == ghWndDllsListCtrl )
      {
        v14 = GetWindowLongW(hWnd, -21);
        if ( !SendMessageW(hWnd, LVM_GETCOLUMNORDERARRAY, v14, lParam) )
        {
          v11 = 0;
          if ( v14 )
          {
            if ( v14 >= 8 )
            {
              v15 = _mm_load_si128(&gIntArray);
              v16 = &v37;
              do
              {
                v17 = v11 + 4;
                v16 += 32;
                v18 = _mm_add_epi32(_mm_shuffle_epi32(_mm_cvtsi32_si128(v11), 0), v15);
                v11 += 8;
                _mm_storeu_si128(v16 - 3, v18);
                _mm_storeu_si128(v16 - 2, _mm_add_epi32(_mm_shuffle_epi32(_mm_cvtsi32_si128(v17), 0), v15));
              }
              while ( v11 < v14 - (v14 & 7) );
            }
            for ( ; v11 < v14; ++v11 )
              lParam[v11] = v11;
          }
        }
        if ( gConfig.dwDllColumnMap[lParam[v11]] == 1670 )
        {
          v19 = pDrawItemStruct->itemData;
          if ( sub_1061820(*(v19 + 364)) )
          {
            if ( sub_1062910(*(v19 + 364)) )
              SetTextColor(pDrawItemStruct->hDC, 0xFFu);
            else
              SetTextColor(pDrawItemStruct->hDC, 0xFF0000u);
            SelectObject(pDrawItemStruct->hDC, ghConfigUnderlineFont);
          }
        }
        else
        {
          SetTextColor(pDrawItemStruct->hDC, TextColor);
          SelectObject(pDrawItemStruct->hDC, ghConfigFont);
        }
        v12 = v11;
      }
      v27 = 0x1FFF;
      Src = 0;
      v20 = wParam[v12];
      v21 = hWnd;
      v25 = v20;
      v26 = &Src;
      SendMessageW(hWnd, LVM_GETITEMTEXTW, pDrawItemStruct->itemID, &v24);
      PE_DrawText(pDrawItemStruct->hDC, &Src, &rect, ColumnInfo.fmt & 1);
      ++v11;
      BackColor += bFocused;
    }
    while ( v11 < v30 );
  }
  else
  {
    v21 = hWnd;
  }
  if ( pDrawItemStruct->itemState & 1 )
  {
    v22 = GetSysColor(8);
    SetTextColor(pDrawItemStruct->hDC, v22);
    v23 = GetSysColor(5);
    SetBkColor(pDrawItemStruct->hDC, v23);
  }
  if ( v21 == ghWndTreeListView )
  {
    rect.left = 0;
    SendMessageW(ghWndTreeListView, LVM_GETITEMRECT, 0, &rect);
    if ( rect.top != dword_10CA338 )
    {
      dword_10CA338 = rect.top;
      InvalidateRect(ghWndTreeListView, 0, 0);
    }
  }
  return 1;
}
// 109EA50: using guessed type RECT gIntArray;
// 10CA338: using guessed type int dword_10CA338;

//----- (01018D00) --------------------------------------------------------
int __cdecl UpdateMenuStatus(char bEnabled, int nPos)
{
  HMENU v2; // eax
  HMENU hSubMenu; // eax
  HMENU hSubMenu_1; // ebx
  int nCount; // eax
  UINT nIndex; // edi
  WPARAM uID; // esi
  int nCount_1; // [esp+8h] [ebp-4h]

  v2 = GetMenu(ghMainWnd);
  hSubMenu = GetSubMenu(v2, nPos);
  hSubMenu_1 = hSubMenu;
  nCount = GetMenuItemCount(hSubMenu);
  nIndex = 0;
  nCount_1 = nCount;
  if ( nCount > 0 )
  {
    while ( 1 )
    {
      nCount = GetMenuItemID(hSubMenu_1, nIndex);
      uID = nCount;
      if ( nCount == IDM_VIEW_SHOW_UNNAMED_HANDLES_AND_MAPPINGS || nCount == IDM_OPTIONS_HIGHLIGHT_RELOCATED_DLLS )
        goto LABEL_9;
      nCount = EnableMenuItem(hSubMenu_1, nIndex, (bEnabled == 0) | MF_BYPOSITION);
      if ( uID == IDM_PROCESS_PROPERTIES )
        break;
      if ( uID == IDM_PROCESS_KILL_PROCESS )
        goto LABEL_8;
LABEL_9:
      if ( ++nIndex >= nCount_1 )
        return nCount;
    }
    uID = IDM_VIEW_PROCESS_PROPERTIES;
LABEL_8:
    nCount = SendMessageW(ghWndToolbar, TB_ENABLEBUTTON, uID, bEnabled);
    goto LABEL_9;
  }
  return nCount;
}

//----- (01018DA0) --------------------------------------------------------
BOOL __cdecl sub_1018DA0(tagTREEVIEWLISTITEMPARAM *pItemParam)
{
  tagTREEVIEWLISTITEMPARAM *i; // edx
  tagTREEVIEWLISTITEMPARAM *v2; // eax
  char v3; // bl

  SendMessageW(ghWndTreeListView, WM_SETREDRAW, 0, 0);
  for ( i = gpTreeViewListItemParam; i; i = i->m_Prev )
  {
    v2 = i->pItemParam;
    v3 = 1;
    if ( v2 )
    {
      while ( 1 )
      {
        v3 = (v2->dwStyle & 4) != 0 ? v3 : 0;
        if ( v2 == pItemParam )
          break;
        v2 = v2->pItemParam;
        if ( !v2 )
          goto LABEL_11;
      }
      if ( v3 && (gConfig.bShowAllUsers || i->dwStyle & 0x40) )
        i->dwStyle |= 2u;
      else
        i->dwStyle &= -3u;
    }
LABEL_11:
    ;
  }
  byte_10C53B5 = 1;
  return SetEvent(ghTimerRefreshEvent);
}
// 10C53B5: using guessed type char byte_10C53B5;

//----- (01018E30) --------------------------------------------------------
char __cdecl ProcStrings_FindItem(HWND hDlg, HWND hWndList, tagFINDREPLACEW *pFindReplace, LPCWSTR lpszFindWhat, PBOOL pbFound, wchar_t *pszBuffer)
{
  tagFINDREPLACEW *FindrePlace; // ebx
  char fDownFind; // al
  LRESULT nCount; // esi
  int v9; // eax
  LRESULT nItemCount; // eax
  const wchar_t *lpstrFindWhat; // ST0C_4
  HWND hWndListCtrl; // edi
  int v14; // esi
  unsigned int v15; // kr00_4
  const wchar_t *v16; // edi
  LPWSTR v17; // edx
  int v18; // esi
  WCHAR v19; // ax
  int v20; // esi
  wchar_t *v21; // eax
  int v22; // eax
  LPWSTR v23; // edx
  WCHAR v24; // ax
  wchar_t *v25; // ebx
  tagFINDREPLACEW *v26; // esi
  const wchar_t *v27; // ecx
  int v28; // edx
  wchar_t v29; // ax
  int v30; // eax
  wchar_t v31; // ax
  unsigned int v32; // kr04_4
  LPWSTR v33; // edx
  int v34; // esi
  WCHAR v35; // ax
  signed int v36; // ecx
  HWND hWndListCtrl_1; // ebx
  HWND v38; // ST00_4
  LRESULT i; // eax
  WPARAM v40; // edi
  tagLVCOLUMNW ColumnInfo; // [esp+Ch] [ebp-427Ch]
  LVITEMW Item; // [esp+2Ch] [ebp-425Ch]
  LRESULT nNumberItem; // [esp+60h] [ebp-4228h]
  WPARAM nColumnIndex; // [esp+64h] [ebp-4224h]
  tagFINDREPLACEW *FindReplace; // [esp+68h] [ebp-4220h]
  unsigned int v46; // [esp+6Ch] [ebp-421Ch]
  HWND hWndDlg; // [esp+70h] [ebp-4218h]
  PBOOL pfbFound; // [esp+74h] [ebp-4214h]
  HWND hWndLC; // [esp+78h] [ebp-4210h]
  WPARAM nItem; // [esp+7Ch] [ebp-420Ch]
  char bDownFind; // [esp+83h] [ebp-4205h]
  wchar_t v52[8192]; // [esp+84h] [ebp-4204h]
  __int16 Text[256]; // [esp+4084h] [ebp-204h]

  FindrePlace = pFindReplace;
  hWndDlg = hDlg;
  pfbFound = pbFound;
  fDownFind = pFindReplace->Flags & FR_DOWN;
  hWndLC = hWndList;
  FindReplace = pFindReplace;
  bDownFind = fDownFind;
  nItem = SendMessageW(hWndList, LVM_GETNEXTITEM, 0xFFFFFFFF, 2);
  nCount = SendMessageW(hWndList, LVM_GETITEMCOUNT, 0, 0);
  if ( (nItem & 0x80000000) != 0 )
  {
    if ( bDownFind )
    {
      nItem = 0;
    }
    else
    {
      if ( *pfbFound )
      {
__FoundNothingAndQuit:
        wsprintf(Text, L"Cannot find string \"%s\"", FindrePlace->lpstrFindWhat);
        MessageBoxW(hWndDlg, Text, L"Process Explorer", 0x30u);
        return 0;
      }
      nItem = nCount;
    }
  }
  if ( *pfbFound )
  {
    v9 = wcscmp(lpszFindWhat, pszBuffer);
    if ( v9 )
      v9 = -(v9 < 0) | 1;
    if ( !v9 )
    {
      if ( bDownFind )
      {
        if ( ++nItem >= nCount )
          goto __FoundNothingAndQuit;
      }
      else if ( (--nItem & 0x80000000) != 0 )
      {
        goto __FoundNothingAndQuit;
      }
    }
  }
  nItemCount = SendMessageW(hWndLC, LVM_GETITEMCOUNT, 0, 0);
  lpstrFindWhat = pFindReplace->lpstrFindWhat;
  nNumberItem = nItemCount;
  wcscpy_s(pszBuffer, 0x2000u, lpstrFindWhat);
  hWndListCtrl = hWndLC;
  while ( 1 )
  {
    ColumnInfo.mask = 2;
    v14 = 0;
    nColumnIndex = 0;
    if ( SendMessageW(hWndListCtrl, LVM_GETCOLUMNW, 0, &ColumnInfo) )
      break;
LABEL_46:
    v36 = 2 * (bDownFind != 0) - 1 + nItem;
    nItem = v36;
    if ( v36 <= 0 || v36 == nNumberItem + 1 )
      goto __FoundNothingAndQuit;
  }
  while ( 1 )
  {
    Item.iSubItem = v14;
    v52[0] = 0;
    Item.pszText = v52;
    Item.cchTextMax = 0x2000;
    SendMessageW(hWndListCtrl, LVM_GETITEMTEXTW, nItem, &Item);
    v15 = wcslen(v52);
    v16 = FindrePlace->lpstrFindWhat;
    v17 = FindrePlace->lpstrFindWhat;
    v18 = (v17 + 1);
    do
    {
      v19 = *v17;
      ++v17;
    }
    while ( v19 );
    if ( v15 >= (v17 - v18) >> 1 )
    {
      if ( !(FindrePlace->Flags & 2) )
      {
        v23 = FindrePlace->lpstrFindWhat;
        v46 = 0;
        do
        {
          v24 = *v23;
          ++v23;
        }
        while ( v24 );
        if ( v15 - (v23 - (v16 + 1)) != -1 )
        {
          v25 = v52;
          do
          {
            v26 = FindReplace;
            v27 = v16;
            v28 = (v16 + 1);
            if ( FindReplace->Flags & 4 )
            {
              do
              {
                v29 = *v27;
                ++v27;
              }
              while ( v29 );
              v30 = wcsncmp(v25, v16, (v27 - v28) >> 1);
            }
            else
            {
              do
              {
                v31 = *v27;
                ++v27;
              }
              while ( v31 );
              v30 = _wcsnicmp(v25, v16, (v27 - v28) >> 1);
            }
            if ( v30 == 0 )
              goto LABEL_49;
            ++v46;
            ++v25;
            v32 = wcslen(v52);
            v16 = v26->lpstrFindWhat;
            v33 = v26->lpstrFindWhat;
            v34 = (v33 + 1);
            do
            {
              v35 = *v33;
              ++v33;
            }
            while ( v35 );
          }
          while ( v46 < v32 - ((v33 - v34) >> 1) + 1 );
          FindrePlace = FindReplace;
        }
        goto LABEL_45;
      }
      v20 = 0;
      if ( v52[0] )
        break;
    }
LABEL_45:
    hWndListCtrl = hWndLC;
    v14 = nColumnIndex++ + 1;
    if ( !SendMessageW(hWndLC, LVM_GETCOLUMNW, nColumnIndex, &ColumnInfo) )
      goto LABEL_46;
  }
  v21 = v52;
  if ( !v52[0] )
    goto LABEL_24;
  while ( 1 )
  {
    do
    {
      if ( *v21 == 32 )
        break;
      v21 = &v52[++v20];
    }
    while ( v52[v20] );
LABEL_24:
    if ( FindrePlace->Flags & 4 )
    {
      v22 = wcscmp(v52, FindrePlace->lpstrFindWhat);
      if ( v22 )
        v22 = -(v22 < 0) | 1;
    }
    else
    {
      v22 = _wcsicmp(v52, FindrePlace->lpstrFindWhat);
    }
    if ( v22 == 0 )
      break;
    v21 = &v52[++v20];
    if ( !v52[v20] )
      goto LABEL_45;
  }
LABEL_49:
  hWndListCtrl_1 = hWndLC;
  v38 = hWndLC;
  *pfbFound = 1;
  for ( i = SendMessageW(v38, LVM_GETNEXTITEM, 0xFFFFFFFF, 2);
        i != -1;
        i = SendMessageW(hWndListCtrl_1, LVM_GETNEXTITEM, 0xFFFFFFFF, 2) )
  {
    Item.stateMask = 3;
    Item.state = 0;
    SendMessageW(hWndListCtrl_1, LVM_SETITEMSTATE, i, &Item);
  }
  v40 = nItem;
  Item.stateMask = 3;
  Item.state = 3;
  SendMessageW(hWndListCtrl_1, LVM_SETITEMSTATE, nItem, &Item);
  SendMessageW(hWndListCtrl_1, LVM_ENSUREVISIBLE, v40, 0);
  SetFocus(hWndListCtrl_1);
  return 1;
}

//----- (01019300) --------------------------------------------------------
void InitDrawEngine()
{
  int index; // esi
  int v1; // eax
  int v2; // ST10_4
  signed int v3; // esi
  int v4; // ST10_4
  signed int v5; // esi
  int v6; // ST10_4
  HGDIOBJ v7; // eax
  int v8; // eax
  int v9; // eax
  unsigned __int16 v10; // cx
  signed int v11; // ecx
  int v12; // eax
  unsigned __int16 v13; // cx
  signed int v14; // ecx
  int nItem; // eax
  unsigned __int16 v16; // cx
  signed int uID_2; // ecx
  int v18; // eax
  unsigned __int16 v19; // cx
  signed int uID_1; // ecx
  DWORD dwOpacity; // eax
  COLORREF v22; // eax
  int index_1; // edi
  SHORT *pwProcessColumns; // ebx
  int *pdwProcessColumnMap; // esi
  int index_2; // esi
  signed int index_3; // edi
  int uID; // eax
  int dwIndex_2; // esi
  CRegVar *var; // edi
  tagRegKeyInfo KeyInfo; // [esp+Ch] [ebp-768h]
  HKEY hSubKey; // [esp+18h] [ebp-75Ch]
  DWORD dwValue[446]; // [esp+1Ch] [ebp-758h]
  tagLOGFONTW LogFont; // [esp+714h] [ebp-60h]

  RegDeleteKeyW(HKEY_CURRENT_USER, L"Software\\Systems Internals\\Process Explorer");
  memset(&gConfig, 0, 0x47E0u);
  gConfig.WindowPlacement[0].showCmd = SW_SHOWNORMAL;
  gConfig.WindowPlacement[0].rcNormalPosition.top = MulDiv(50, gLogPixelSize.y, 96);
  gConfig.WindowPlacement[0].rcNormalPosition.bottom = MulDiv(650, gLogPixelSize.y, 96);
  gConfig.WindowPlacement[0].rcNormalPosition.left = MulDiv(100, gLogPixelSize.x, 96);
  gConfig.WindowPlacement[0].rcNormalPosition.right = MulDiv(900, gLogPixelSize.x, 96);
  gConfig.WindowPlacement[0].length = sizeof(WINDOWPLACEMENT);
  gConfig.WindowPlacement[FindWindowplacement].rcNormalPosition.top = MulDiv(150, gLogPixelSize.y, 96);
  gConfig.WindowPlacement[FindWindowplacement].rcNormalPosition.left = MulDiv(150, gLogPixelSize.x, 96);
  gConfig.WindowPlacement[FindWindowplacement].length = sizeof(WINDOWPLACEMENT);
  gConfig.WindowPlacement[PropWindowplacement].rcNormalPosition.top = MulDiv(40, gLogPixelSize.y, 96);
  gConfig.WindowPlacement[PropWindowplacement].rcNormalPosition.left = MulDiv(40, gLogPixelSize.x, 96);
  gConfig.WindowPlacement[PropWindowplacement].length = sizeof(WINDOWPLACEMENT);
  gConfig.WindowPlacement[DllPropWindowplacement].rcNormalPosition.top = MulDiv(40, gLogPixelSize.y, 96);
  gConfig.WindowPlacement[DllPropWindowplacement].rcNormalPosition.left = MulDiv(40, gLogPixelSize.x, 96);
  gConfig.WindowPlacement[DllPropWindowplacement].length = sizeof(WINDOWPLACEMENT);
  gConfig.WindowPlacement[SysinfoWindowplacement].rcNormalPosition.top = MulDiv(40, gLogPixelSize.y, 96);
  gConfig.WindowPlacement[SysinfoWindowplacement].rcNormalPosition.left = MulDiv(40, gLogPixelSize.x, 96);
  gConfig.WindowPlacement[SysinfoWindowplacement].length = sizeof(WINDOWPLACEMENT);
  gConfig.ToolBandInfo[0].nWidth = -1;
  gConfig.ToolBandInfo[1].nWidth = -1;
  gConfig.ToolBandInfo[2].nWidth = -1;
  gConfig.ToolBandInfo[3].nWidth = -1;
  index = 0;
  gConfig.ToolBandInfo[4].nWidth = -1;
  gConfig.ToolBandInfo[5].nWidth = -1;
  gConfig.ToolBandInfo[6].nWidth = -1;
  gConfig.ToolBandInfo[7].nWidth = -1;
  gConfig.dwProcessColumnCount = 6;
  do
  {
    v1 = gProcessColumns[index].wID;
    v2 = gLogPixelSize.x;
    dwValue[index + 97] = v1;
    gConfig.dwProcessColumnMap[index] = v1;
    gConfig.dwProcessColumns[index] = MulDiv(word_10BD1F2[2 * index], v2, 96);
    ++index;
  }
  while ( index < gConfig.dwProcessColumnCount );
  gConfig.dwHandleColumnCount = 2;
  v3 = 0;
  do
  {
    v4 = gLogPixelSize.x;
    gConfig.dwIdsOfHandleColumnMap[v3] = gHandleColumns[v3].wID;
    gConfig.dwHandleColumns[v3] = MulDiv(gHandleColumns[v3].nWidth, v4, 96);
    ++v3;
  }
  while ( v3 < gConfig.dwHandleColumnCount );
  gConfig.dwDllColumnCount = 4;
  v5 = 0;
  do
  {
    v6 = gLogPixelSize.x;
    gConfig.dwDllColumnMap[v5] = gDllColumns[v5].wID;
    gConfig.dwDllColumns[v5] = MulDiv(gDllColumns[v5].nWidth, v6, 96);
    ++v5;
  }
  while ( v5 < gConfig.dwDllColumnCount );
  v7 = GetStockObject(DEFAULT_GUI_FONT);
  GetObjectW(v7, sizeof(LOGFONTW), &LogFont);
  LogFont.lfWeight = 400;
  v8 = MulDiv(8, gLogPixelSize.y, 72);
  LogFont.lfWidth = 0;
  LogFont.lfHeight = -v8;
  qmemcpy(&gConfig.UnicodeFont, &LogFont, sizeof(gConfig.UnicodeFont));
  KeyInfo.szKeyName = _wcsdup(L"Software\\Sysinternals\\Process Explorer");
  LoadConfigItemFromRegistry(&KeyInfo, gConfigItems);
  if ( gConfig.UnicodeFont.lfHeight > 0 )
    gConfig.UnicodeFont.lfHeight = -MulDiv(gConfig.UnicodeFont.lfHeight, gLogPixelSize.y, 72);
  if ( !RegOpenKeyW(HKEY_CURRENT_USER, L"Software\\Sysinternals\\Process Explorer", &hSubKey) )
  {
    KeyInfo.nLength = 0x6F8;
    if ( !RegQueryValueExW(hSubKey, L"Settings", 0, 0, dwValue, &KeyInfo.nLength) && dwValue[0] - 501 <= 320 )
    {
      v9 = 0;
      if ( dwValue[96] <= 0 )
      {
__Loop:
        nItem = 0;
        if ( dwValue[129] <= 0 )
        {
LABEL_31:
          v18 = 0;
          if ( dwValue[162] <= 0 )
          {
LABEL_37:
            sub_1014F50(&gConfig, dwValue, KeyInfo.nLength);
            RegDeleteValueW(hSubKey, L"Settings");
            CloseHandle(hSubKey);
            dwOpacity = gConfig.dwOpacity;
            if ( !gConfig.dwOpacity )
              dwOpacity = 100;
            gConfig.dwOpacity = dwOpacity;
            v22 = gConfig.ColorOwn;
            if ( !gConfig.ColorOwn )
              v22 = 0xFFD0D0;
            gConfig.ColorOwn = v22;
            if ( !gConfig.dwProcessColumnMap[0] )
              qmemcpy(gConfig.dwProcessColumnMap, &dwValue[97], 0x80u);
          }
          else
          {
            while ( 1 )
            {
              v19 = *(&dwValue[54] + v18);
              if ( !v19 )
                break;
              if ( v19 > 2000u )
                break;
              uID_1 = dwValue[v18 + 163];
              if ( uID_1 <= 0 || uID_1 > 41000 )
                break;
              if ( ++v18 >= dwValue[162] )
                goto LABEL_37;
            }
          }
        }
        else
        {
          while ( 1 )
          {
            v16 = *(&dwValue[70] + nItem);
            if ( !v16 )
              break;
            if ( v16 > 2000u )
              break;
            uID_2 = dwValue[nItem + 130];
            if ( uID_2 <= 0 || uID_2 > 41000 )
              break;
            if ( ++nItem >= dwValue[129] )
              goto LABEL_31;
          }
        }
      }
      else
      {
        while ( 1 )
        {
          v10 = *(&dwValue[38] + v9);
          if ( !v10 )
            break;
          if ( v10 > 2000u )
            break;
          v11 = dwValue[v9 + 374];
          if ( v11 <= 0 || v11 > 41000 )
            break;
          if ( ++v9 >= dwValue[96] )
            goto __Loop;
        }
        v12 = 0;
        while ( 1 )
        {
          v13 = *(&dwValue[38] + v12);
          if ( !v13 )
            break;
          if ( v13 > 2000u )
            break;
          v14 = dwValue[v12 + 97];
          if ( v14 <= 0 || v14 > 41000 )
            break;
          if ( ++v12 >= dwValue[96] )
            goto __Loop;
        }
      }
    }
  }
  index_1 = 0;
  if ( gConfig.dwProcessColumnCount > 0 )
  {
    pwProcessColumns = gConfig.dwProcessColumns;
    pdwProcessColumnMap = gConfig.dwProcessColumnMap;
    do
    {
      if ( *pdwProcessColumnMap == 3 )
      {
        memmove_0(pdwProcessColumnMap, pdwProcessColumnMap + 1, 4 * (--gConfig.dwProcessColumnCount - index_1));
        memmove_0(pwProcessColumns, pwProcessColumns + 1, 2 * (gConfig.dwProcessColumnCount - index_1));
      }
      ++index_1;
      ++pdwProcessColumnMap;
      ++pwProcessColumns;
    }
    while ( index_1 < gConfig.dwProcessColumnCount );
  }
  index_2 = 0;
  index_3 = -1;
  if ( gConfig.dwProcessColumnCount <= 0 )
    goto LABEL_68;
  do
  {
    if ( gConfig.dwProcessColumnMap[index_2] == IDS_PID )
    {
      index_3 = index_2;
      if ( gConfig.bETWStandardUserWarning )
        break;
    }
    else if ( !IsBuiltinAdministrative() && !gConfig.bETWStandardUserWarning )
    {
      uID = gConfig.dwProcessColumnMap[index_2];
      if ( uID >= IDS_NETWORK_RECEIVES && uID <= IDS_DISK_DELTA_TOTAL_BYTES )
      {
        gConfig.bETWStandardUserWarning = 1;
        MessageBoxW(
          0,
          L"Note that Disk and Networking information requires administrative rights",
          L"Process Explorer",
          MB_ICONEXCLAMATION);
        if ( index_3 != -1 )
          goto LABEL_60;
      }
    }
    ++index_2;
  }
  while ( index_2 < gConfig.dwProcessColumnCount );
  if ( index_3 == -1 )
  {
LABEL_68:
    gConfig.dwProcessColumnMap[index_2] = IDS_PID;
    gConfig.dwProcessColumns[index_2] = 200;
    ++gConfig.dwProcessColumnCount;
  }
LABEL_60:
  dwIndex_2 = 0;
  if ( gConfig.dwNumColumnsets > 0 )
  {
    var = gConfig.strMenuCulumnSet;
    do
    {
      RegVar_ReadWrite(0, dwIndex_2++, var);
      ++var;
    }
    while ( dwIndex_2 < gConfig.dwNumColumnsets );
  }
  if ( !gConfig.strNtSymbolPath[0] )
    GetEnvironmentVariableW(L"_NT_SYMBOL_PATH", gConfig.strNtSymbolPath, 0x104u);
  ghConfigFont = CreateFontIndirectW(&gConfig.UnicodeFont);
  qmemcpy(&LogFont, &gConfig.UnicodeFont, sizeof(LogFont));
  LogFont.lfUnderline = 1;
  ghConfigUnderlineFont = CreateFontIndirectW(&LogFont);
  free(KeyInfo.szKeyName);
}

//----- (01019980) --------------------------------------------------------
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
  ChooseFont.lpTemplateName = 1543;
  if ( ChooseFontW(&ChooseFont) )
  {
    qmemcpy(&gConfig.UnicodeFont, &lf, sizeof(gConfig.UnicodeFont));
    DeleteObject(ghConfigFont);
    ghConfigFont = CreateFontIndirectW(&gConfig.UnicodeFont);
    lf.lfUnderline = 1;
    ghConfigUnderlineFont = CreateFontIndirectW(&lf);
    CTreeList::InitListCtrl(ghWndTreeListView, ghConfigFont);
    CTreeList::InitListCtrl(ghWndDllsListCtrl, ghConfigFont);
    CTreeList::InitListCtrl(ghWndHandlesListCtrl, ghConfigFont);
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

//----- (01019BB0) --------------------------------------------------------
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
  v6 = SendMessageW(hWnd, LVM_GETTOOLTIPS, 0, 0);
  CTreeList::InitToolTips(v6);
  result = InitListHeader(hWnd, pnIDs, pnWidths, dwNewLong);
  if ( fSortable )
  {
    v8 = InitSortableImageList();
    v9 = GetWindowLongW(hWnd, -16);
    SetWindowLongW(hWnd, -16, v9 | LVS_SHAREIMAGELISTS);
    result = SendMessageW(hWnd, LVM_SETIMAGELIST, 1u, v8);
  }
  return result;
}

//----- (01019C50) --------------------------------------------------------
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

//----- (01019C80) --------------------------------------------------------
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
          if ( sub_1061820(item.lParam->field_16C) )
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
        sub_101A880(hWnd, uMsg, wParam_1, &lParam_1);
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
// 109EA50: using guessed type RECT gIntArray;
// 10C4E54: using guessed type int gdwVersion;

//----- (0101A880) --------------------------------------------------------
LRESULT __cdecl sub_101A880(HWND hWnd, WPARAM uMsg, WPARAM wParam_1, RECT *lParam_1)
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
// 109EA50: using guessed type RECT gIntArray;

//----- (0101AB00) --------------------------------------------------------
BOOL __cdecl CTreeList::InitListCtrl(HWND hWnd, WPARAM wParam)
{
  HWND v2; // eax
  struct tagRECT Rect; // [esp+Ch] [ebp-14h]

  v2 = SendMessageW(hWnd, LVM_GETHEADER, 0, 0);
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

//----- (0101ABA0) --------------------------------------------------------
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
            v92 = sub_10237B0(v98, *(a2 + 364));
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
            v92 = sub_10237B0(*(a1 + 376), *(a2 + 376));
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
          v92 = sub_10237B0(*(a1 + 380), *(a2 + 380));
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
          v92 = sub_10237B0(*(a1 + 368), *(a2 + 368));
          goto LABEL_350;
        }
        if ( v91 == 1 )
        {
          v92 = sub_10237B0(*(a1 + 372), *(a2 + 372));
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
            v16 = byte_10C53B4 == 0;
            goto LABEL_419;
          case 1:
            v108 = *(a1 + 576);
            if ( v108 != 0.0 || v108 != *(a2 + 576) )
            {
              v116 = *(a2 + 576);
              if ( v108 <= v116 )
              {
                v4 = (v116 <= v108) - 1;
                v16 = byte_10C53B4 == 0;
              }
              else
              {
                v16 = byte_10C53B4 == 0;
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
              v16 = byte_10C53B4 == 0;
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
                v16 = byte_10C53B4 == 0;
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
                  v16 = byte_10C53B4 == 0;
                  v4 = 1;
                  goto LABEL_419;
                }
                if ( __PAIR__(v114, v113) >= v115 )
                {
                  v4 = 0;
                  v16 = byte_10C53B4 == 0;
                  goto LABEL_419;
                }
              }
            }
LABEL_377:
            v4 = -1;
            v16 = byte_10C53B4 == 0;
            goto LABEL_419;
          case 2:
            if ( QueryThreadCycleTime && *(a1 + 40) )
            {
              v4 = sub_10237B0(*(a1 + 600), *(a2 + 600));
              v16 = byte_10C53B4 == 0;
            }
            else
            {
              v4 = *(a1 + 584) - *(a2 + 584);
              v16 = byte_10C53B4 == 0;
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
                v16 = byte_10C53B4 == 0;
                goto LABEL_419;
              }
              v118 = _wcsicmp(v120, *(a2 + 648));
            }
            v4 = v118;
            goto LABEL_391;
          default:
LABEL_391:
            v16 = byte_10C53B4 == 0;
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
      v16 = byte_10BD225 == 0;
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
        v16 = byte_10BD224 == 0;
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
            v4 = sub_10237B0(*(a1 + 920), *(a2 + 920));
            goto LABEL_253;
          case 10:
            v4 = sub_10237B0(*(a1 + 924), *(a2 + 924));
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
              v4 = sub_10237B0(*(a1 + 1096) + *(a1 + 1128), *(a2 + 1096) + *(a2 + 1128));
              goto LABEL_253;
            case 1616:
              v4 = sub_10237B0(*(a1 + 1096), *(a2 + 1096));
              goto LABEL_253;
            case 1617:
              v4 = sub_10237B0(*(a1 + 1080), *(a2 + 1080));
              goto LABEL_253;
            case 1618:
              v4 = sub_10237B0(*(a1 + 1112), *(a2 + 1112));
              goto LABEL_253;
            case 1619:
              v4 = sub_10237B0(*(a1 + 1128), *(a2 + 1128));
              goto LABEL_253;
            case 1620:
              v4 = sub_10237B0(*(a1 + 1144), *(a2 + 1144));
              goto LABEL_253;
            case 1621:
              v4 = sub_10237B0(*(a1 + 1160), *(a2 + 1160));
              goto LABEL_253;
            case 1622:
              v4 = sub_10237B0(*(a1 + 1168), *(a2 + 1168));
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
              v4 = sub_10237B0(*(a1 + 1200) + *(a1 + 1232), *(a2 + 1200) + *(a2 + 1232));
              goto LABEL_253;
            case 1630:
              v4 = sub_10237B0(*(a1 + 1184), *(a2 + 1184));
              goto LABEL_253;
            case 1631:
              v4 = sub_10237B0(*(a1 + 1200), *(a2 + 1200));
              goto LABEL_253;
            case 1632:
              v4 = sub_10237B0(*(a1 + 1216), *(a2 + 1216));
              goto LABEL_253;
            case 1633:
              v4 = sub_10237B0(*(a1 + 1232), *(a2 + 1232));
              goto LABEL_253;
            case 1634:
              v4 = sub_10237B0(*(a1 + 1248), *(a2 + 1248));
              goto LABEL_253;
            case 1635:
              v4 = sub_10237B0(*(a1 + 1264), *(a2 + 1264));
              goto LABEL_253;
            case 1636:
              v4 = sub_10237B0(*(a1 + 1272), *(a2 + 1272));
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
              v4 = sub_10237B0(*(a1 + 1408), *(a2 + 1408));
              goto LABEL_253;
            case 1652:
              v4 = sub_10237B0(*(a1 + 1424), *(a2 + 1424));
              goto LABEL_253;
            case 1653:
              v4 = sub_10237B0(*(a1 + 1440), *(a2 + 1440));
              goto LABEL_253;
            case 1654:
              v4 = lstrcmpiW(*(a1 + 824), *(a2 + 824));
              goto LABEL_253;
            case 1655:
LABEL_218:
              v4 = sub_1014EF0((a1 + 624), (a2 + 624));
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
                v4 = sub_10237B0(v53, *(a2 + 844));
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
              v4 = sub_10237B0(*(a1 + 984), *(a2 + 984));
              goto LABEL_253;
            case 1328:
              v4 = *(a1 + 1008) - *(a2 + 1008);
              goto LABEL_253;
            case 1329:
              v4 = sub_10237B0(*(a1 + 1016), *(a2 + 1016));
              goto LABEL_253;
            case 1330:
              v4 = sub_10237B0(*(a1 + 984) + *(a1 + 1016), *(a2 + 984) + *(a2 + 1016));
              goto LABEL_253;
            case 1332:
              v4 = sub_10237B0(*(a1 + 1048), *(a2 + 1048));
              goto LABEL_253;
            case 1333:
              v4 = sub_10237B0(*(a1 + 1056), *(a2 + 1056));
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
              v4 = sub_10237B0(*(a1 + 912), *(a2 + 912));
              goto LABEL_253;
            case 1342:
              v4 = sub_10237B0(*(a1 + 916), *(a2 + 916));
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
            v4 = sub_10237B0(*(a1 + 880), *(a2 + 880));
            goto LABEL_253;
          case 1060:
          case 1193:
            v4 = sub_10237B0(*(a1 + 888), *(a2 + 888));
            goto LABEL_253;
          case 1061:
            v4 = lstrcmpiW(*(a1 + 792), *(a2 + 792));
            goto LABEL_253;
          case 1062:
            v4 = sub_10237B0(*(a1 + 896), *(a2 + 896));
            goto LABEL_253;
          case 1063:
            v4 = sub_10237B0(*(a1 + 900), *(a2 + 900));
            goto LABEL_253;
          case 1064:
            v4 = sub_10237B0(*(a1 + 904), *(a2 + 904));
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
            v4 = sub_10237B0(*(a1 + 968), *(a2 + 968));
            goto LABEL_253;
          case 1070:
            v4 = *(a1 + 992) - *(a2 + 992);
            goto LABEL_253;
          case 1071:
            v4 = sub_10237B0(*(a1 + 1000), *(a2 + 1000));
            goto LABEL_253;
          case 1072:
            v4 = *(a1 + 1024) - *(a2 + 1024);
            goto LABEL_253;
          case 1073:
            v4 = sub_10237B0(*(a1 + 1032), *(a2 + 1032));
            goto LABEL_253;
          case 1086:
            goto LABEL_218;
          case 1087:
            v4 = sub_1014EF0((a1 + 1320), (a2 + 1320));
            goto LABEL_253;
          case 1091:
            v4 = sub_10237B0(*(a1 + 1344), *(a2 + 1344));
            goto LABEL_253;
          case 1092:
            v4 = sub_10237B0(*(a1 + 1336), *(a2 + 1336));
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
            v4 = sub_10237B0(*(a1 + 876), *(a2 + 876));
            goto LABEL_253;
          case 1115:
            v4 = sub_10237B0(*(a1 + 936), *(a2 + 936));
            goto LABEL_253;
          case 1116:
            v4 = sub_10237B0(*(a1 + 940), *(a2 + 940));
            goto LABEL_253;
          case 1118:
            v4 = sub_10237B0(*(a1 + 948), *(a2 + 948));
            goto LABEL_253;
          case 1179:
            v4 = sub_10237B0(*(a1 + 884), *(a2 + 884));
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
            v4 = sub_10237B0(*(a1 + 1360), *(a2 + 1360));
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
            v4 = sub_10237B0(*(a1 + 1352), *(a2 + 1352));
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
      v4 = sub_10237B0(*(a1 + 944), *(a2 + 944));
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
  result = sub_1014EF0(v3 + 156, v6 + 156);
  if ( !result )
    result = v3[17] - v6[17];
  return result;
}
// 1092BB0: using guessed type wchar_t aDD[6];
// 10BD224: using guessed type char byte_10BD224;
// 10BD225: using guessed type char byte_10BD225;
// 10C53B4: using guessed type char byte_10C53B4;

//----- (0101CB80) --------------------------------------------------------
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
  ColumnInfo.mask = 15;
  ColumnInfo.pszText = Buffer;
  if ( nColumnCount )
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
      LoadStringW(ghInstance, pnIDs_1[nColumn], Buffer, 64);
      if ( SendMessageW(hWnd, LVM_INSERTCOLUMNW, nColumn, &ColumnInfo) == -1 )
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
    SendMessageW(hWnd, LVM_GETCOLUMNW, 0, &ColumnInfo);
    ColumnInfo.fmt |= 1u;
    ColumnInfo.mask = 1;
    SendMessageW(hWnd, LVM_SETCOLUMNW, 0, &ColumnInfo);
  }
  SetWindowLongW(hWnd, GWLP_USERDATA, nColumnCount);
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
  SendMessageW(hWnd, LVM_SETCOLUMNORDERARRAY, nColumnCount, arrIDS);
  InvalidateRect(hWnd, 0, 1);
  return 1;
}
// 109EA50: using guessed type RECT gIntArray;

//----- (0101CDD0) --------------------------------------------------------
int __cdecl sub_101CDD0(int a1, int a2)
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
  RECT lParam_1; // [esp+6Ch] [ebp-14h]

  HitTestInfo.pt.x = 0;
  _mm_storeu_si128(&HitTestInfo.pt.y, 0i64);
  item.mask = 0;
  memset(&item.iItem, 0, 0x30u);
  Point.x = 0;
  Point.y = 0;
  if ( a1 == IDC_TREEVIEW_LIST )
  {
    hWndList = ghWndTreeListView;
  }
  else
  {
    if ( a1 != IDC_LISTCTRL_DLLS )
      return 0;
    hWndList = ghWndDllsListCtrl;
  }
  GetCursorPos(&Point);
  ScreenToClient(hWndList, &Point);
  HitTestInfo.pt = Point;
  item.iItem = SendMessageW(hWndList, LVM_HITTEST, 0, &HitTestInfo);
  item.iSubItem = 0;
  item.mask = 4;
  if ( SendMessageW(hWndList, LVM_GETITEMW, 0, &item) != 1 )
    return 0;
  sub_101A880(hWndList, item.iItem, HitTestInfo.iSubItem, &lParam_1);
  v3 = item.lParam;
  if ( hWndList != ghWndTreeListView )
  {
    SubHitTestInfo.pt.x = *(a2 + 32);
    SubHitTestInfo.pt.y = *(a2 + 36);
    SendMessageW(hWndList, LVM_SUBITEMHITTEST, 0, &SubHitTestInfo);
    if ( gConfig.dwDllColumnMap[SubHitTestInfo.iSubItem] == IDS_VIRUSTOTAL && sub_1061820(v3->field_16C) )
    {
      v11 = *(v3->field_16C + 36);
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
    if ( v4 == IDS_VIRUSTOTAL && sub_1061820(item.lParam->m_ItemDataForVirusTotal) )
    {
      v9 = v3->m_ItemDataForVirusTotal[4].field_4;
      if ( v9 )
        v10 = *v9;
      else
        v10 = 0;
      LaunchWebBrowser(hWndList, 0, v10);
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
  sub_1018DA0(v13);
  RefreshMenuWithTreeViewItemStatus(v3);
  RefreshVirusTotalMenuItem(v3);
  return 0;
}

//----- (0101D040) --------------------------------------------------------
int __cdecl PE_ShowProcessTree(WPARAM uTabID, tagHwndID *pThis)
{
  tagHwndID *v2; // ebx
  void (__stdcall *SendMessageW)(HWND, UINT, WPARAM, LPARAM); // esi
  HWND v4; // eax
  tagTREEVIEWLISTITEMPARAM *v5; // edi
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
  signed int v17; // edi
  int v18; // esi
  int v19; // eax
  DWORD v20; // edx
  char v21; // al
  HWND v22; // ecx
  LRESULT v23; // eax
  HWND v24; // ST00_4
  HWND v25; // ST00_4
  LPARAM lParam; // [esp+Ch] [ebp-94h]
  tagTREEVIEWLISTITEMPARAM *v28; // [esp+14h] [ebp-8Ch]
  LVITEMW Item; // [esp+24h] [ebp-7Ch]
  LVITEMW v30; // [esp+58h] [ebp-48h]
  WPARAM wParam; // [esp+8Ch] [ebp-14h]
  HWND v32; // [esp+90h] [ebp-10h]
  tagTREEVIEWLISTITEMPARAM *v33; // [esp+94h] [ebp-Ch]
  void *i; // [esp+98h] [ebp-8h]
  tagHwndID *v35; // [esp+9Ch] [ebp-4h]

  v2 = pThis;
  SendMessageW = ::SendMessageW;
  v4 = pThis[2].hWnd;
  v5 = 0;
  v35 = pThis;
  v33 = 0;
  wParam = uTabID;
  v32 = v4;
  if ( uTabID == 101 )
  {
    Item.iItem = ::SendMessageW(ghWndTreeListView, LVM_GETNEXTITEM, 0xFFFFFFFF, 2);
    if ( Item.iItem != -1 )
    {
      Item.iSubItem = 0;
      Item.mask = 4;
      ::SendMessageW(ghWndTreeListView, LVM_GETITEMW, 0, &Item);
      v33 = Item.lParam;
    }
    v6 = gConfig.bProcessSortDirection;
    if ( gConfig.bShowProcessTree || gConfig.dwProcessColumnMap[pThis[2].hWnd] != 3 || gConfig.bProcessSortDirection )
    {
      gConfig.bShowProcessTree = 0;
      if ( gConfig.dwProcessSortColumn == pThis[2].hWnd )
      {
        v6 = gConfig.bProcessSortDirection == 0;
        gConfig.bProcessSortDirection = gConfig.bProcessSortDirection == 0;
      }
      v11 = gConfig.dwProcessSortColumn;
      gConfig.dwProcessSortColumn = pThis[2].hWnd;
      CTreeList::InitHeaderColumn(pThis->hWnd, v11, gConfig.dwProcessSortColumn, v6);
      v12 = GetMenu(ghMainWnd);
      EnableMenuItem(v12, 0x9C6Cu, 1u);
      ::SendMessageW(ghWndToolbar, 0x401u, 0x9C67u, gConfig.bShowProcessTree == 0);
      v13 = gConfig.bShowProcessTree != 0;
      v14 = GetMenu(ghMainWnd);
      EnableMenuItem(v14, 0x9C67u, v13);
      SendMessageW = ::SendMessageW;
    }
    else
    {
      gConfig.dwProcessSortColumn = pThis[2].hWnd;
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
          v30.pszText = 1;
          ::SendMessageW(ghWndTreeListView, LVM_GETCOLUMNW, v9, &v30.pszText);
          v30.cchTextMax &= 0xFFFFE7FF;
          v30.pszText = 1;
          ::SendMessageW(ghWndTreeListView, LVM_SETCOLUMNW, v9++, &v30.pszText);
        }
        while ( v9 < v10 );
        v2 = v35;
      }
      gConfig.bShowProcessTree = 1;
      sub_1056020(gpTreeViewListItemParam);
    }
    SendMessageW(v2->hWnd, 0xBu, 0, 0);
    v35 = (SendMessageW)(v2->hWnd, 0x1004u, 0, 0);
    v15 = 0;
    for ( i = operator new[](4 * v35); v15 < v35; ++v15 )
    {
      v30.iItem = v15;
      v16 = v2->hWnd;
      v30.iSubItem = 0;
      v30.mask = 4;
      SendMessageW(v16, 0x104Bu, 0, &v30);
      *(i + v15) = v30.lParam;
    }
    SendMessageW(v2->hWnd, 0x1009u, 0, 0);
    v17 = 0;
    if ( v35 > 0 )
    {
      do
      {
        v18 = *(i + v17);
        v19 = sub_1017F20(v2->hWnd, *(i + v17++));
        *(v18 + 1464) = v19;
      }
      while ( v17 < v35 );
      SendMessageW = ::SendMessageW;
    }
    j_j__free(i);
    v5 = v33;
  }
  else
  {
    switch ( uTabID )
    {
      case 0x66u:
        v20 = gConfig.dwHandleSortColumn;
        if ( gConfig.dwHandleSortColumn == v4 )
        {
          v21 = LOBYTE(gConfig.bHandleSortDirection) == 0;
          LOBYTE(gConfig.bHandleSortDirection) = LOBYTE(gConfig.bHandleSortDirection) == 0;
          v22 = pThis[2].hWnd;
        }
        else
        {
          v22 = pThis[2].hWnd;
          v21 = gConfig.bHandleSortDirection;
        }
        gConfig.dwHandleSortColumn = pThis[2].hWnd;
        break;
      case 0x68u:
        v20 = gConfig.dwDllSortColumn;
        if ( gConfig.dwDllSortColumn == v4 )
        {
          v21 = LOBYTE(gConfig.bDllSortDirection) == 0;
          LOBYTE(gConfig.bDllSortDirection) = LOBYTE(gConfig.bDllSortDirection) == 0;
          v22 = pThis[2].hWnd;
        }
        else
        {
          v22 = pThis[2].hWnd;
          v21 = gConfig.bDllSortDirection;
        }
        gConfig.dwDllSortColumn = pThis[2].hWnd;
        break;
      case 0x414u:
        v20 = ::wParam;
        if ( ::wParam == v4 )
        {
          v21 = byte_10C53B4 == 0;
          byte_10C53B4 = byte_10C53B4 == 0;
          v22 = pThis[2].hWnd;
        }
        else
        {
          v22 = pThis[2].hWnd;
          v21 = byte_10C53B4;
        }
        ::wParam = pThis[2].hWnd;
        break;
      case 0x410u:
        v20 = nItem;
        if ( nItem == v4 )
        {
          v21 = byte_10BD224 == 0;
          byte_10BD224 = byte_10BD224 == 0;
          v22 = pThis[2].hWnd;
        }
        else
        {
          v22 = pThis[2].hWnd;
          v21 = byte_10BD224;
        }
        nItem = pThis[2].hWnd;
        break;
      case 0x4A8u:
        v20 = dword_10C9B98;
        if ( dword_10C9B98 == v4 )
        {
          v21 = byte_10BD225 == 0;
          byte_10BD225 = byte_10BD225 == 0;
        }
        else
        {
          v21 = byte_10BD225;
        }
        v22 = pThis[2].hWnd;
        dword_10C9B98 = pThis[2].hWnd;
        break;
      default:
        goto LABEL_47;
    }
    CTreeList::InitHeaderColumn(pThis->hWnd, v20, v22, v21);
  }
LABEL_47:
  SendMessageW(v2->hWnd, 0x1030u, &wParam, PropProcThreadsSortCallback);
  v23 = (SendMessageW)(v2->hWnd, 0x100Cu, 0xFFFFFFFF, 2);
  SendMessageW(v2->hWnd, 0x1013u, v23, 0);
  if ( uTabID == 101 )
  {
    if ( v5 )
    {
      lParam = 1;
      v24 = v2->hWnd;
      v28 = v5;
      Item.iItem = (SendMessageW)(v24, 0x1053u, 0xFFFFFFFF, &lParam);
      v25 = v2->hWnd;
      v30.stateMask = 3;
      v30.state = 3;
      SendMessageW(v25, 0x102Bu, Item.iItem, &v30);
      SendMessageW(v2->hWnd, 0x1013u, Item.iItem, 0);
    }
    SendMessageW(v2->hWnd, 0xBu, 1u, 0);
  }
  return 0;
}
// 10BD224: using guessed type char byte_10BD224;
// 10BD225: using guessed type char byte_10BD225;
// 10C53B4: using guessed type char byte_10C53B4;

//----- (0101D4B0) --------------------------------------------------------
int __cdecl sub_101D4B0(signed int a1, int a2)
{
  tagTREEVIEWLISTITEMPARAM *v2; // ecx
  int v3; // edi
  _DWORD *v4; // esi
  ULONGLONG *v5; // edx
  int v6; // edx
  tagTREEVIEWLISTITEMPARAM *v8; // ecx
  int v9; // edx
  int v10; // edx
  tagTREEVIEWLISTITEMPARAM *v11; // eax
  void *v12; // ecx
  tagTREEVIEWLISTITEMPARAM *v13; // esi
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
      v12 = v13->dwStyle;
    }
    else
    {
      if ( a1 != 1192 )
        return 0;
      SendMessageW(*a2, LVM_GETITEMW, 0, &dllitem);
      v11 = dllitem.lParam;
      if ( *&dllitem.lParam[1].field_28E[25] )
      {
        free(*&dllitem.lParam[1].field_28E[25]);
        v11 = dllitem.lParam;
      }
      v12 = *&v11[1].field_28E[29];
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
      dword_10BE0D8 = -1;
      *(*(a2 + 40) + 1464) = 0;
      return 0;
    }
    if ( a1 == 102 )
    {
      SendMessageW(ghWndHandlesListCtrl, LVM_GETITEMW, 0, &dllitem);
      v2 = dllitem.lParam;
      v3 = HIDWORD(dllitem.lParam[2].ContextSwtichDelta);
      v4 = (&dllitem.lParam[2].ContextSwtichDelta + 4);
      v5 = &dllitem.lParam[2].ContextSwtichDelta;
      if ( v3 )
      {
        *(v3 + 4280) = dllitem.lParam[2].ContextSwtichDelta;
        v2 = dllitem.lParam;
      }
      else
      {
        dword_10C539C = dllitem.lParam[2].ContextSwtichDelta;
      }
      v6 = *v5;
      if ( v6 )
      {
        *(v6 + 4284) = *v4;
        v2 = dllitem.lParam;
      }
      free(v2);
      return 0;
    }
    return 0;
  }
  SendMessageW(ghWndDllsListCtrl, LVM_GETITEMW, 0, &dllitem);
  v8 = dllitem.lParam;
  v9 = *&dllitem.lParam->gap180[4];
  if ( v9 )
    *(v9 + 384) = *dllitem.lParam->gap180;
  else
    gpDllListItemParamHeader = *dllitem.lParam->gap180;
  v10 = *v8->gap180;
  if ( v10 )
    *(v10 + 388) = *&v8->gap180[4];
  DLLLISTITEMPARAM_Release(v8);
  return 0;
}
// 10BE0D8: using guessed type int dword_10BE0D8;

//----- (0101D660) --------------------------------------------------------
int __cdecl FillList(int nID)
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
          if ( !lvitem.lParam->hFileIcon )
          {
            MessageBoxW(ghMainWnd, L"Not a valid DLL", L"Process Explorer", MB_ICONHAND);
            return 0;
          }
          InterlockedIncrement(&lvitem.lParam->field_0);
          v4->dwStyle = gdwProcessIdSelected;
          _beginthread(PropertiesThreadProc, 0, v4);
          break;
      }
    }
  }
  return 0;
}

//----- (0101D7A0) --------------------------------------------------------
int __cdecl sub_101D7A0(int a1)
{
  return -(a1 != 101);
}

//----- (0101D7B0) --------------------------------------------------------
int __cdecl sub_101D7B0(signed int a1, int pItem)
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
  v2 = *(pItem + 12);
  if ( v2 & 2 )
  {
    *(pItem + 40) = *(*(pItem + 44) + 64);
    return 0;
  }
  if ( !*(pItem + 32) || !(v2 & 1) )
    return 0;
  wcscpy_s(TimeStr, 0x104u, &gszNullString);
  if ( a1 > 104 )
  {
    if ( a1 == 1044 )
    {
      v111 = *(pItem + 20);
      v112 = *(pItem + 44);
      switch ( v111 )
      {
        case 0:
          ArgList_4a = *(v112 + 44);
LABEL_49:
          swprintf(TimeStr, L"%d", ArgList_4a);
          goto LABEL_50;
        case 1:
          sub_1015AD0(v112 + 576, *(v112 + 584), *(v112 + 584) >> 32, *(v112 + 600), *(v112 + 604), &Dst, 0x10u);
          goto LABEL_41;
        case 2:
          if ( QueryThreadCycleTime && *(v112 + 40) )
          {
            v8 = TimeStr;
            if ( !*(v112 + 600) )
              goto LABEL_51;
            swprintf(TimeStr, L"%I64u", *(v112 + 600), *(v112 + 604));
LABEL_90:
            PE_GetNumberFormat(TimeStr, 0x104u);
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
                v116 = sub_105EFB0(Buffer);
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
      v104 = *(pItem + 44);
      v105 = GetPropW(*pItem, L"resolve");
      v106 = *(pItem + 20);
      LOBYTE(Buffer) = v105;
      switch ( v106 )
      {
        case 0:
          swprintf(gpszProtocolName, L"%S", gszProtocolNames[*(v104 + 40)]);
          *(pItem + 32) = gpszProtocolName;
          return 0;
        case 1:
          if ( v105 )
          {
            if ( *(v104 + 64) )
            {
              wcscpy_s(TimeStr, 0x104u, (v104 + 64));
            }
            else if ( sub_10244B0(*(v104 + 40), Buffer, 1, *(v104 + 44), (v104 + 48), TimeStr, 0x104u) )
            {
              wcscpy_s((v104 + 64), 0x104u, TimeStr);
            }
          }
          else
          {
            sub_10244B0(*(v104 + 40), 0, 1, *(v104 + 44), (v104 + 48), TimeStr, 0x104u);
          }
          v107 = wcslen(TimeStr);
          sub_1024670(Buffer, *(v104 + 584), gszProtocolNames[*(v104 + 40)], &TimeStr[v107], 260 - v107);
          v20 = v129;
          v8 = TimeStr;
          goto LABEL_52;
        case 2:
          v108 = *(v104 + 40);
          if ( v108 && v108 != 2 )
          {
            *(pItem + 32) = L"*:*";
            return 0;
          }
          if ( v105 )
          {
            if ( *(v104 + 1128) )
            {
              wcscpy_s(TimeStr, 0x104u, (v104 + 1128));
            }
            else if ( sub_10244B0(v108, Buffer, 0, *(v104 + 1108), (v104 + 1112), TimeStr, 0x104u) )
            {
              wcscpy_s((v104 + 1128), 0x104u, TimeStr);
            }
          }
          else
          {
            sub_10244B0(v108, 0, 0, *(v104 + 1108), (v104 + 1112), TimeStr, 0x104u);
          }
          v109 = wcslen(TimeStr);
          sub_1024670(Buffer, *(v104 + 1648), gszProtocolNames[*(v104 + 40)], &TimeStr[v109], 260 - v109);
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
        v4 = *(pItem + 44);
        v5 = gConfig.dwIdsOfHandleColumnMap[*(pItem + 20)];
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
                v20 = pItem;
LABEL_52:
                wcsncpy_s(*(v20 + 32), *(v20 + 32) >> 32, v8, 0xFFFFFFFF);
                return 0;
              }
              sub_1008CE0(v4[12], (v4 + 14), TimeStr);
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
              *(pItem + 32) = &gszNullString;
              return 0;
            }
            if ( v8 != TimeStr )
            {
              *(pItem + 32) = v8;
              return 0;
            }
            goto LABEL_51;
          }
          swprintf(TimeStr, L"0x%X", v4[11]);
        }
      }
      goto LABEL_50;
    }
    v16 = *(pItem + 20);
    v17 = *(pItem + 44);
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
            sub_10013E0(&Dst, L"%02.2f", LODWORD(v19), HIDWORD(v19));
          }
          else
          {
            sub_10013E0(&Dst, L"%0.0f", LODWORD(v19), HIDWORD(v19));
          }
          goto LABEL_41;
        case 9:
          v21 = *(v17 + 920);
          goto LABEL_62;
        case 10:
          swprintf(TimeStr, L"%I64u", *(v17 + 924) >> 10, 0);
          PE_GetNumberFormat(TimeStr, 0x104u);
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
              *(pItem + 32) = L"Suspended";
              return 0;
            }
            sub_1015AD0(v17 + 1296, *(v17 + 1336), *(v17 + 1336) >> 32, *(v17 + 1352), *(v17 + 1356), &Dst, 0x10u);
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
            PE_GetNumberFormat(TimeStr, 0x104u);
            wcscat_s(TimeStr, 0x104u, L" K");
            goto LABEL_50;
          case 1061:
            v8 = *(v17 + 792);
            goto LABEL_364;
          case 1062:
            swprintf(TimeStr, L"%I64u", *(v17 + 896) >> 10, 0);
            PE_GetNumberFormat(TimeStr, 0x104u);
            wcscat_s(TimeStr, 0x104u, L" K");
            goto LABEL_50;
          case 1063:
            swprintf(TimeStr, L"%I64u", *(v17 + 900) >> 10, 0);
            PE_GetNumberFormat(TimeStr, 0x104u);
            wcscat_s(TimeStr, 0x104u, L" K");
            goto LABEL_50;
          case 1064:
            swprintf(TimeStr, L"%I64u", *(v17 + 904) >> 10, 0);
            PE_GetNumberFormat(TimeStr, 0x104u);
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
            dbValue2 = *(v17 + 1320);
            v20 = v129;
            swprintf(
              TimeStr,
              L"%I64d:%02I64d:%02I64d.%03I64d",
              *(*(v129 + 44) + 1320) / 0x861C46800ui64,
              *(*(v129 + 44) + 1320) / 0x23C34600ui64 % 0x3C,
              dbValue2 / 10000000 % 60,
              dbValue2 % 10000000 / 10000);
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
            dbValue2_4a = L"%I64d";
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
            PE_GetNumberFormat(TimeStr, 0x104u);
            wcscat_s(TimeStr, 0x104u, L" K");
            goto LABEL_50;
          case 1115:
            ArgLista = *(v17 + 936) >> 10;
            dbValue2_4 = L"%I64d";
            goto LABEL_63;
          case 1116:
            swprintf(TimeStr, L"%I64u", *(v17 + 940) >> 10, 0);
            PE_GetNumberFormat(TimeStr, 0x104u);
            wcscat_s(TimeStr, 0x104u, L" K");
            goto LABEL_50;
          case 1118:
            swprintf(TimeStr, L"%I64u", *(v17 + 948) >> 10, 0);
            PE_GetNumberFormat(TimeStr, 0x104u);
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
              PE_GetNumberFormat(TimeStr, 0x104u);
              wcscat_s(TimeStr, 0x104u, L" K");
            }
            goto LABEL_50;
          case 1195:
            ArgList_4c = *(v17 + 1364);
            ArgListb = *(v17 + 1360);
            dbValue2_4a = L"%I64u";
            goto LABEL_89;
          case 1196:
            if ( !*(v17 + 616) )
              goto LABEL_50;
            v23 = L"Not responding";
            if ( !*(v17 + 620) )
              v23 = L"Running";
            *(pItem + 32) = v23;
            return 0;
          case 1199:
            sub_1057720(v17, TimeStr, 0x104u);
            goto LABEL_50;
          case 1200:
            v25 = *(v17 + 1356);
            if ( v25 < 0 || v25 <= 0 && !*(v17 + 1352) )
              goto LABEL_50;
            ArgList_4c = *(v17 + 1356);
            ArgListb = *(v17 + 1352);
            dbValue2_4a = L"%I64u";
LABEL_89:
            swprintf(TimeStr, dbValue2_4a, ArgListb, ArgList_4c);
            goto LABEL_90;
          default:
            goto LABEL_50;
        }
LABEL_41:
        if ( Dst == 48 && (v132 == 48 || !v132) )
        {
          *(pItem + 32) = L"    ";
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
          PE_GetNumberFormat(TimeStr, 0x104u);
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
            *(pItem + 32) = L"Virtualized";
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
            sub_1057790(*(v17 + 952), TimeStr, 0x104u);
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
              PE_FormatDouble(0, TimeStr, 0x104u, *(v17 + 1160), 0.0, COERCE_DOUBLE(0i64 >> 63));
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
            PE_GetDoubleString(TimeStr, v80);
            goto LABEL_50;
          case 1637:
            sub_1015AD0(v17 + 1312, 0, 0, 0, 0, &Dst, 0x10u);
            goto LABEL_41;
          case 1638:
LABEL_204:
            if ( *(v17 + 68) < 0 )
              goto LABEL_184;
            ArgList_4a = *(v17 + 68);
            goto LABEL_49;
          case 1650:
            sub_1015AD0(v17 + 1384, 0, 0, 0, 0, &Dst, 0x10u);
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
                *(pItem + 32) = L"Unaware";
                return 0;
              case 1:
                *(pItem + 32) = L"System Aware";
                return 0;
              case 2:
                *(pItem + 32) = L"Per-Monitor Aware";
                return 0;
              default:
                ArgList_4a = *(v17 + 644);
                break;
            }
            goto LABEL_49;
          case 1670:
            sub_1061A50(*(v17 + 844), TimeStr);
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
            *(pItem + 32) = v90;
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
          *(pItem + 32) = L"n/a";
          return 0;
        }
        goto LABEL_50;
      }
LABEL_276:
      *(pItem + 32) = L"CFG";
      return 0;
    }
LABEL_50:
    v8 = TimeStr;
    goto LABEL_51;
  }
  v91 = *(pItem + 44);
  v92 = gConfig.dwDllColumnMap[*(pItem + 20)];
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
        *(pItem + 32) = v95;
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
    dbValue2_4 = L"%I64u";
LABEL_63:
    swprintf(TimeStr, dbValue2_4, ArgLista, 0);
LABEL_64:
    PE_GetNumberFormat(TimeStr, 0x104u);
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
        *(pItem + 32) = L"ASLR";
        result = 0;
      }
      else
      {
        v100 = L"n/a";
        if ( !(*(v91 + 44) & 2) )
          v100 = &gszNullString;
        *(pItem + 32) = v100;
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
      *(pItem + 32) = L"32-bit";
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
    sub_1061A50(*(v91 + 364), TimeStr);
    goto LABEL_50;
  }
  if ( v102 != 39087 )
    goto LABEL_50;
  if ( *(v91 + 54) & 0x4000 )
    goto LABEL_276;
  v103 = L"n/a";
  if ( *(v91 + 54) )
    v103 = &gszNullString;
  *(pItem + 32) = v103;
  return 0;
}
// 109E080: using guessed type wchar_t aSuspended[10];
// 109E094: using guessed type wchar_t asc_109E094[5];
// 109E0A0: using guessed type wchar_t aVirtualized[12];
// 109E0C8: using guessed type wchar_t aUiAccess[10];
// 109E0DC: using guessed type wchar_t aUnaware[8];
// 109E0EC: using guessed type wchar_t aSystemAware[13];
// 109E108: using guessed type wchar_t aPerMonitorAwar[18];
// 109E12C: using guessed type wchar_t aAslr[5];
// 109E138: using guessed type wchar_t aCfg[4];
// 109E140: using guessed type wchar_t a32Bit[7];
// 109E18C: using guessed type wchar_t aNotResponding[15];
// 109E200: using guessed type wchar_t a0x08x[7];
// 109E220: using guessed type wchar_t aData_0[5];
// 109E250: using guessed type wchar_t asc_109E250[4];
// 109E9C8: using guessed type double db_zeropointzerozerofive;
// 10BD238: using guessed type wchar_t *gszNetStatus[13];
// 10CB1CC: using guessed type int gdwTebAddressOffset;
// 101D7B0: using guessed type WCHAR TimeStr[260];
