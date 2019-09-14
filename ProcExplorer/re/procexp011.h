
//----- (01010CA0) --------------------------------------------------------
char __thiscall BitmapItem_Create(BitmapItem *this, LONG nWidth, signed int nHeight)
{
  BitmapItem *v3; // ST24_4
  HDC hDC; // ebx
  HDC v5; // eax
  void *v6; // ST14_4
  BITMAPINFO bi; // [esp+10h] [ebp-2Ch]

  v3 = this;
  hDC = GetDC(0);
  _mm_storeu_si128(&bi.bmiHeader.biWidth, 0i64);
  bi.bmiHeader.biClrImportant = 0;
  bi.bmiHeader.biSize = offsetof(BITMAPINFO, bmiColors);
  bi.bmiHeader.biHeight = -nHeight;
  bi.bmiHeader.biWidth = nWidth;
  *&bi.bmiHeader.biPlanes = 0x200001;
  _mm_storeu_si128(&bi.bmiHeader.biSizeImage, 0i64);
  bi.bmiHeader.biClrUsed = 0;
  bi.bmiHeader.biCompression = 0;
  bi.bmiHeader.biSizeImage = 0;
  v3->hBitmapHandle = CreateDIBSection(hDC, &bi, 0, &v3->pBits, 0, 0);
  v3->nHeight = nHeight;
  v3->nWidth = nWidth;
  v5 = CreateCompatibleDC(hDC);
  v6 = v3->hBitmapHandle;
  v3->CompatibleDC = v5;
  SelectObject(v5, v6);
  ReleaseDC(0, hDC);
  return 1;
}

//----- (01010D60) --------------------------------------------------------
char __thiscall BitmapItem_SetRectColor(BitmapItem *this, RECT *lprc, unsigned int color)
{
  RECT *v3; // edx
  LONG left; // esi
  BitmapItem *pItem; // ebx
  LONG top; // eax
  int right; // ecx
  LONG y; // edi
  LONG bottom; // eax
  int nHeight; // edx
  LONG x; // eax
  int nBit; // edx
  int i; // [esp+Ch] [ebp-8h]
  LONG left_1; // [esp+10h] [ebp-4h]
  RECT *nWidth; // [esp+1Ch] [ebp+8h]

  v3 = lprc;
  left = 0;
  pItem = this;
  if ( lprc->left > 0 )
    left = lprc->left;
  top = lprc->top;
  right = this->nWidth;
  left_1 = left;
  if ( lprc->right < right )
    right = lprc->right;
  y = 0;
  nWidth = right;
  if ( top > 0 )
    y = top;
  bottom = v3->bottom;
  nHeight = pItem->nHeight;
  if ( bottom < nHeight )
    nHeight = bottom;
  for ( i = nHeight; y < nHeight; ++y )
  {
    x = left;
    if ( left < right )
    {
      do
      {
        nBit = x++ + y * pItem->nWidth;
        pItem->pBits[nBit] = (color & 0xFF00) | (color << 16) | (color >> 16) & 0xFF;
        right = nWidth;
      }
      while ( x < nWidth );
      left = left_1;
      nHeight = i;
    }
  }
  return 1;
}

//----- (01010E00) --------------------------------------------------------
int __cdecl sub_1010E00(wchar_t *Dst, size_t SizeInWords, int a3, __int64 a4)
{
  int result; // eax

  if ( gConfig.bShowCpuFractions )
    result = swprintf_s(Dst, SizeInWords, L"%s%0.2f%%", a3, a4);
  else
    result = swprintf_s(Dst, SizeInWords, L"%s%0.0f%%", a3, a4);
  return result;
}

//----- (01010E50) --------------------------------------------------------
char __thiscall sub_1010E50(BitmapItem *this, int a2, int a3, int a4, int a5, unsigned int a6, int a7)
{
  int v7; // eax
  BitmapItem *v8; // esi
  int v9; // ecx
  int v10; // ecx
  int v11; // edx
  int v12; // edx
  int v13; // edi
  int v14; // edi
  int v15; // ebx

  v7 = a2;
  v8 = this;
  if ( a2 >= 0 )
  {
    v9 = this->nWidth;
    if ( a2 >= v9 )
      v7 = v9 - 1;
  }
  else
  {
    v7 = 0;
  }
  v10 = a4;
  if ( a4 >= 0 )
  {
    v11 = v8->nWidth;
    if ( a4 >= v11 )
      v10 = v11 - 1;
  }
  else
  {
    v10 = 0;
  }
  v12 = a3;
  if ( a3 >= 0 )
  {
    v13 = v8->nHeight;
    if ( a3 >= v13 )
      v12 = v13 - 1;
  }
  else
  {
    v12 = 0;
  }
  v14 = a5;
  if ( a5 >= 0 )
  {
    v15 = v8->nHeight;
    if ( a5 >= v15 )
      v14 = v15 - 1;
  }
  else
  {
    v14 = 0;
  }
  sub_1010A90(v8, v12, v7, v14, v10, a6, a7);
  return 1;
}

//----- (01010ED0) --------------------------------------------------------
char __thiscall sub_1010ED0(_DWORD *this, int a2, int a3, int a4, int a5, unsigned int a6, char a7)
{
  int v7; // esi
  _DWORD *v8; // ebx
  int v9; // eax
  int v10; // eax
  int v11; // ecx
  int v12; // edi
  int v13; // ecx
  int v14; // ecx
  int v15; // edx
  unsigned int v16; // ecx
  int v17; // edx
  int v18; // ecx
  unsigned int v20; // ecx
  int v21; // edx
  int v22; // ecx

  v7 = a2;
  v8 = this;
  if ( a2 >= 0 )
  {
    v9 = this[2];
    if ( a2 >= v9 )
      v7 = v9 - 1;
  }
  else
  {
    v7 = 0;
  }
  v10 = a4;
  if ( a4 >= 0 )
  {
    v11 = this[2];
    if ( a4 < v11 )
      goto LABEL_10;
    v10 = v11 - 1;
  }
  else
  {
    v10 = 0;
  }
  a4 = v10;
LABEL_10:
  v12 = a3;
  if ( a3 >= 0 )
  {
    v13 = v8[1];
    if ( a3 >= v13 )
      v12 = v13 - 1;
  }
  else
  {
    v12 = 0;
  }
  v14 = a5;
  if ( a5 >= 0 )
  {
    v15 = v8[1];
    if ( a5 < v15 )
      goto LABEL_19;
    v14 = v15 - 1;
  }
  else
  {
    v14 = 0;
  }
  a5 = v14;
LABEL_19:
  if ( v7 != v10 )
  {
    if ( v7 < v10 )
    {
      do
      {
        if ( a7 )
          v20 = (a6 >> 1) | (((BYTE1(a6) | ((BYTE2(a6) & 0xFE) << 8)) & 0xFFFE) << 7);
        else
          v20 = a6;
        v21 = (v20 & 0xFF00) | (v20 << 16) | (v20 >> 16) & 0xFF;
        v22 = v7++ + v12 * v8[2];
        *(v8[4] + 4 * v22) = v21;
      }
      while ( v7 < a4 );
    }
    return 1;
  }
  if ( v12 >= v14 )
    return 1;
  do
  {
    if ( a7 )
      v16 = (a6 >> 1) | (((BYTE1(a6) | ((BYTE2(a6) & 0xFE) << 8)) & 0xFFFE) << 7);
    else
      v16 = a6;
    v17 = (v16 & 0xFF00) | (v16 << 16) | (v16 >> 16) & 0xFF;
    v18 = v12++ * v8[2];
    *(v8[4] + 4 * (v7 + v18)) = v17;
  }
  while ( v12 < a5 );
  return 1;
}

//----- (01011020) --------------------------------------------------------
void __cdecl CGraphData_Update(CGraphData *pGraphData, FILETIME time, double dbMemorySize, double a5, wchar_t *a6)
{
  WCHAR *v5; // ebx
  WCHAR **v6; // edx
  int v7; // ecx
  int v8; // ecx
  WCHAR **v9; // eax
  double *v10; // ecx
  double dbMemorySize_1; // [esp+4h] [ebp-8h]

  if ( pGraphData )
  {
    dbMemorySize_1 = dbMemorySize;
    if ( pGraphData->m_nItemID )
    {
      if ( dbMemorySize > pGraphData->m_dbMemorySize )
        pGraphData->m_dbMemorySize = dbMemorySize * 1.200000047683716;
    }
    else if ( dbMemorySize <= pGraphData->m_dbMemorySize )
    {
      if ( dbMemorySize < 0.0 )
        dbMemorySize_1 = 0.0;
    }
    else
    {
      dbMemorySize_1 = pGraphData->m_dbMemorySize;
    }
    if ( a5 <= pGraphData->m_Item[0].dbMemorySize )
    {
      if ( a5 < 0.0 )
        a5 = 0.0;
    }
    else
    {
      a5 = db_onehundred;
    }
    v5 = _wcsdup(a6);
    EnterCriticalSection(&pGraphData->m_Lock.m_Lock);
    v6 = pGraphData->m_pBuffer;
    if ( v6 )
    {
      v7 = pGraphData->m_nWidth;
      if ( v6[v7] )
        free(v6[v7]);
      v8 = pGraphData->m_nWidth;
      v9 = pGraphData->m_pBuffer;
      if ( a6 )
        v9[v8] = v5;
      else
        v9[v8] = 0;
    }
    pGraphData->m_pBuffer1[pGraphData->m_nWidth] = (*&time - *&pGraphData->m_Time) / 10000000;
    pGraphData->m_Item[0].pBuffer[pGraphData->m_nWidth] = dbMemorySize_1;
    v10 = pGraphData->m_Item[1].pBuffer;
    if ( v10 )
      v10[pGraphData->m_nWidth] = a5;
    if ( ++pGraphData->m_nWidth >= gdwVirtualScreenWidth )
      pGraphData->m_nWidth = 0;
    LeaveCriticalSection(&pGraphData->m_Lock.m_Lock);
  }
}
// 109CDC0: using guessed type double db_onehundred;
// 10C4E28: using guessed type int gdwVirtualScreenWidth;

//----- (01011160) --------------------------------------------------------
CGraphData *__cdecl InitGraphData(int nCount, int nChildID, BOOL fFlags)
{
  int nCount_1; // edi
  CGraphData *result; // eax
  UCHAR *pBuffer; // ebx
  void *v6; // eax
  void *v7; // eax
  UCHAR *v8; // esi
  int nChildID_1; // edi
  void *v10; // eax
  struct _FILETIME *lpSystemTimeAsFileTime; // [esp+4h] [ebp-8h]
  CGraphData *pGrahData; // [esp+8h] [ebp-4h]

  nCount_1 = nCount;
  result = malloc(sizeof(CGraphData) * nCount);
  pGrahData = result;
  if ( nCount > 0 )
  {
    lpSystemTimeAsFileTime = &result->m_Time;
    pBuffer = &result->m_pBuffer;
    do
    {
      memset(pBuffer - 2144, 0, sizeof(CGraphData));
      pGrahData->m_nChildID = nChildID;
      InitializeCriticalSection((pBuffer - 2144));
      GetSystemTimeAsFileTime(lpSystemTimeAsFileTime);
      v6 = malloc(4 * gdwVirtualScreenWidth);
      *(pBuffer + 3) = v6;
      memset(v6, 0, 4 * gdwVirtualScreenWidth);
      if ( fFlags )
      {
        v7 = malloc(4 * gdwVirtualScreenWidth);
        *pBuffer = v7;
        memset(v7, 0, 4 * gdwVirtualScreenWidth);
      }
      if ( nChildID > 0 )
      {
        // pItem = &ppGraphDatap[i]->m_Item
        v8 = pBuffer - 2092;
        nChildID_1 = nChildID;
        do
        {
          v10 = malloc(8 * gdwVirtualScreenWidth);
          *v8 = v10;
          memset(v10, 0, 8 * gdwVirtualScreenWidth);
          v8 += 24;
          // for(i = 0; i < nChildID;i++)
          // {
          // pItem[i].pBuffer = malloc(...);
          // ZeroMemory(pItem[i].pBuffer,...);
          // }
          --nChildID_1;
        }
        while ( nChildID_1 );
        nCount_1 = nCount;
      }
      pBuffer += sizeof(CGraphData);
      nCount = --nCount_1;
    }
    while ( nCount_1 );
    result = pGrahData;
  }
  return result;
}
// 101125E: CONTAINING_RECORD: no field 'UCHAR *' in struct 'CGraphData' at 2200
// 10C4E28: using guessed type int gdwVirtualScreenWidth;

//----- (01011280) --------------------------------------------------------
void __cdecl GraphData_Release(CGraphData *pGraphData, int nCount)
{
  CGraphData *v2; // edi
  void **v3; // ebx
  int v4; // ecx
  int i; // esi
  signed int v6; // esi
  void **v7; // edi
  bool v8; // zf
  void **v9; // [esp+4h] [ebp-4h]

  v2 = pGraphData;
  if ( pGraphData )
  {
    if ( nCount > 0 )
    {
      v3 = &pGraphData->m_pBuffer;
      v9 = &pGraphData->m_pBuffer;
      do
      {
        free(v3[3]);
        if ( *v3 )
        {
          v4 = gdwVirtualScreenWidth;
          for ( i = 0; i < v4; ++i )
          {
            if ( *(*v3 + i) )
            {
              free(*(*v3 + i));
              v4 = gdwVirtualScreenWidth;
            }
          }
          free(*v3);
        }
        v6 = 0;
        if ( v2->m_nChildID > 0 )
        {
          v7 = v3 - 523;
          do
          {
            free(*v7);
            ++v6;
            v7 += 6;
          }
          while ( v6 < pGraphData->m_nChildID );
          v3 = v9;
          v2 = pGraphData;
        }
        DeleteCriticalSection((v3 - 536));
        v3 += 550;
        v8 = nCount-- == 1;
        v9 = v3;
      }
      while ( !v8 );
    }
    free(v2);
  }
}
// 10C4E28: using guessed type int gdwVirtualScreenWidth;

//----- (01011340) --------------------------------------------------------
HWND __cdecl CreateGraphWindow(HWND hDlg, int nIDDlgItem, PVOID pParam)
{
  HWND v3; // eax
  HWND v4; // eax
  HWND hWnd; // eax
  struct tagRECT Rect; // [esp+Ch] [ebp-14h]

  v3 = GetDlgItem(hDlg, nIDDlgItem);
  GetWindowRect(v3, &Rect);
  MapWindowPoints(0, hDlg, &Rect, 2u);
  v4 = GetDlgItem(hDlg, nIDDlgItem);
  DestroyWindow(v4);
  if ( nIDDlgItem == IDC_SYSINFO_IO_STATIC_IO_CHART
    || nIDDlgItem == IDC_SYSINFO_SUM_STATIC_SYSTEM_COMMIT_CHART
    || nIDDlgItem == IDC_SYSINFO_SUM_STATIC_PHYSICAL_MEMORY_CHART
    || nIDDlgItem == IDC_SYSINFO_IOETW_STATIC_NETWORK_CHART
    || nIDDlgItem == IDC_SYSINFO_IOETW_STATIC_DISK_CHART
    || nIDDlgItem == IDC_SYSINFO_GPU_STATIC_GPU_DEDICATED_MEMORY_CHART
    || nIDDlgItem == IDC_SYSINFO_GPU_STATIC_GPU_SYSTEM_MEMORY_CHART
    || nIDDlgItem == 2603
    || nIDDlgItem >= IDC_SYSINFO_CPU_STATIC_CPU_CHART && nIDDlgItem < 2500
    || nIDDlgItem >= IDC_SYSINFO_GPU_NODES_STATIC_GRAPH && nIDDlgItem < 2600 )
  {
    hWnd = CreateWindowExW(
             0,
             L"CpuGraphClassGraph",
             &gszNullString,
             0x50000000u,
             Rect.left,
             Rect.top,
             Rect.right - Rect.left,
             Rect.bottom - Rect.top,
             hDlg,
             nIDDlgItem,
             ghInstance,
             pParam);
  }
  else
  {
    hWnd = CreateWindowExW(
             0,
             L"CpuGraphClassChart",
             &gszNullString,
             0x50000000u,
             Rect.left,
             Rect.top,
             Rect.right - Rect.left,
             Rect.bottom - Rect.top,
             hDlg,
             nIDDlgItem,
             ghInstance,
             pParam);
  }
  return hWnd;
}
// 109CB88: using guessed type wchar_t aCpugraphclassc[19];

//----- (01011470) --------------------------------------------------------
HGDIOBJ __cdecl GraphData_DrawGraph(CGraphData *pGraphData, HDC hDC, RECT *lprc)
{
  LONG v3; // edi
  int v4; // esi
  bool v5; // zf
  bool v6; // sf
  unsigned __int8 v7; // of
  double v8; // xmm0_8
  __int64 v9; // xmm0_8
  __int64 v10; // xmm0_8
  double v11; // xmm0_8
  int v12; // eax
  DWORD v13; // eax
  signed int v14; // edi
  signed int v15; // ecx
  LONG v16; // ebx
  double v17; // xmm2_8
  int v18; // edx
  double v19; // xmm3_8
  double v20; // xmm1_8
  CGraphData *v21; // eax
  LONG v22; // ecx
  signed int v23; // edi
  unsigned int v24; // edx
  int *v25; // ecx
  int v26; // eax
  int v27; // esi
  int v28; // edi
  int v29; // eax
  HBRUSH v30; // eax
  HBRUSH v31; // esi
  HGDIOBJ v32; // eax
  COLORREF v33; // eax
  HGDIOBJ result; // eax
  const wchar_t *dbValue_4; // [esp+4h] [ebp-108h]
  double v36; // [esp+14h] [ebp-F8h]
  int v37[2]; // [esp+1Ch] [ebp-F0h]
  unsigned int v38; // [esp+24h] [ebp-E8h]
  LONG v39; // [esp+28h] [ebp-E4h]
  HDC v40; // [esp+2Ch] [ebp-E0h]
  RECT *v41; // [esp+30h] [ebp-DCh]
  int v42; // [esp+34h] [ebp-D8h]
  double v43; // [esp+38h] [ebp-D4h]
  LONG v44; // [esp+40h] [ebp-CCh]
  CGraphData *v45; // [esp+44h] [ebp-C8h]
  HGDIOBJ ho; // [esp+48h] [ebp-C4h]
  int cy; // [esp+4Ch] [ebp-C0h]
  int v48; // [esp+50h] [ebp-BCh]
  HDC hdc; // [esp+54h] [ebp-B8h]
  void *v50; // [esp+58h] [ebp-B4h]
  __int64 v51; // [esp+5Ch] [ebp-B0h]
  int a2a; // [esp+64h] [ebp-A8h]
  struct tagRECT rc; // [esp+68h] [ebp-A4h]
  RECT rect; // [esp+78h] [ebp-94h]
  __int16 Dst[32]; // [esp+88h] [ebp-84h]
  __int16 chText[32]; // [esp+C8h] [ebp-44h]

  v40 = hDC;
  v45 = pGraphData;
  v3 = lprc->right - lprc->left;
  v42 = lprc->bottom - lprc->top;
  v41 = lprc;
  cy = 0;
  v48 = 0;
  hdc = 0;
  ho = 0;
  v39 = v3;
  BitmapItem_Create(&ho, v3, v42);
  EnterCriticalSection(&pGraphData->m_Lock.m_Lock);
  v4 = pGraphData->m_nWidth - 1;
  if ( v4 < 0 )
    v4 = gdwVirtualScreenWidth - 1;
  v7 = __OFSUB__(pGraphData->m_nChildID, 1);
  v5 = pGraphData->m_nChildID == 1;
  v6 = (pGraphData->m_nChildID - 1) < 0;
  v51 = *&pGraphData->m_Item[0].pBuffer[v4];
  if ( (v6 ^ v7) | v5 )
    v8 = v36;
  else
    v8 = pGraphData->m_Item[1].pBuffer[v4];
  v43 = v8;
  LeaveCriticalSection(&pGraphData->m_Lock.m_Lock);
  switch ( pGraphData->m_nItemID )
  {
    case 0u:
    case 4u:
      v9 = v51;
      if ( pGraphData->m_nChildID != 1 && *&v51 <= v43 )
        v9 = *&v43;
      sub_10109A0(chText, &gszNullString, v9);
      goto LABEL_18;
    case 1u:
    case 3u:
    case 5u:
    case 6u:
    case 7u:
      wcscpy_s(Dst, 0x20u, L" KB");
      v10 = v51;
      if ( *&v51 <= 1048576.0 )
      {
        if ( *&v51 <= 1024.0 )
          goto LABEL_16;
        v11 = *&v51 * 0.0009765625;
        dbValue_4 = L" MB";
      }
      else
      {
        v11 = *&v51 * 0.00000095367431640625;
        dbValue_4 = L" GB";
      }
      *&v51 = v11;
      wcscpy_s(Dst, 0x20u, dbValue_4);
      v10 = v51;
LABEL_16:
      swprintf_s(chText, 0x20u, L"%s%0.1f", &gszNullString, v10, HIDWORD(v10));
      wcscat_s(chText, 0x20u, Dst);
LABEL_18:
      SetBkColor(hdc, 0);
      SetTextColor(hdc, 0);
      v12 = DrawTextW(hdc, chText, -1, &rc, DT_CALCRECT);
      rect.top = 0;
      rect.left = (v3 / 3.0 * 0.5);
      rect.right = v3 - rect.left;
      HIDWORD(v51) = v42 - v12;
      rect.bottom = v42 - v12 - 2;
      v13 = GetSysColor(5);
      if ( v50 && cy * v48 )
        memset32(v50, (v13 & 0xFF00) | (v13 << 16) | (v13 >> 16) & 0xFF, cy * v48);
      BitmapItem_SetRectColor(&ho, &rect, gConfig.ColorGraphBk);
      v14 = pGraphData->m_nChildID;
      v15 = 0;
      v16 = rect.top;
      v44 = rect.top;
      if ( v14 > 0 )
      {
        v17 = rect.bottom;
        v18 = &v45->m_dbMemorySize;
        v19 = (rect.bottom - rect.top);
        do
        {
          v20 = *(*(v18 + 12) + 8 * v4) / *v18;
          v18 += 24;
          v37[v15++] = (v17 - v20 * v19);
        }
        while ( v15 < v14 );
      }
      if ( v16 < rect.bottom )
      {
        v21 = v45;
        v22 = rect.bottom;
        while ( 1 )
        {
          v23 = 0;
          v24 = 0x828282;
          if ( v21->m_nChildID > 0 )
            break;
LABEL_52:
          v44 = ++v16;
          if ( v16 >= v22 )
            goto LABEL_53;
        }
        v25 = &v21->m_Color;
        a2a = &v21->m_Color;
        do
        {
          v26 = v37[v23];
          if ( v16 >= v26 )
          {
            v24 = *v25;
            HIDWORD(v43) = *v25;
            if ( v16 > v26 + 1 )
            {
              v38 = v24 >> 8;
              v25 = a2a;
              v16 = v44;
              v24 = (((BYTE1(v24) + (256 - BYTE1(v24)) / 2) | ((BYTE2(v24) + (256 - BYTE2(v24)) / 2) << 8)) << 8) | (BYTE4(v43) + (256 - BYTE4(v43)) / 2);
            }
          }
          v21 = v45;
          ++v23;
          v25 += 6;
          a2a = v25;
        }
        while ( v23 < v45->m_nChildID );
        if ( v24 == 0x828282 )
        {
LABEL_51:
          v22 = rect.bottom;
          goto LABEL_52;
        }
        v27 = rect.left;
        v28 = v16;
        v29 = rect.right;
        a2a = v16;
        if ( rect.left >= 0 )
        {
          if ( rect.left >= v48 )
            v27 = v48 - 1;
        }
        else
        {
          v27 = 0;
        }
        if ( rect.right >= 0 )
        {
          if ( rect.right >= v48 )
            v29 = v48 - 1;
        }
        else
        {
          v29 = 0;
        }
        if ( v16 >= 0 )
        {
          if ( v16 < cy )
          {
LABEL_46:
            if ( v16 >= 0 )
            {
              if ( v16 >= cy )
                v28 = cy - 1;
            }
            else
            {
              v28 = 0;
            }
            sub_1010A90(&ho, a2a, v27, v28, v29, v24, 0);
            v21 = v45;
            goto LABEL_51;
          }
          a2a = cy - 1;
        }
        else
        {
          a2a = 0;
        }
        v16 = v44;
        goto LABEL_46;
      }
LABEL_53:
      v30 = CreateSolidBrush(0x828282u);
      ++rect.right;
      v31 = v30;
      FrameRect(hdc, &rect, v30);
      DeleteObject(v31);
      rc.top = HIDWORD(v51);
      rc.bottom = v42;
      rc.left = 0;
      rc.right = v39;
      v32 = GetStockObject(17);
      SelectObject(hdc, v32);
      v33 = GetSysColor(5);
      SetBkColor(hdc, v33);
      SetTextColor(hdc, 0);
      DrawTextW(hdc, chText, -1, &rc, 5u);
      BitBlt(v40, v41->left, v41->top, v48, cy, hdc, 0, 0, 0xCC0020u);
      if ( hdc )
        DeleteDC(hdc);
      result = ho;
      if ( ho )
        result = DeleteObject(ho);
      return result;
    case 2u:
    case 8u:
    case 9u:
      PE_FormatDoubleFlow(chText, 0x20u, *&v51 - v43 + v43);
      goto LABEL_18;
    default:
      goto LABEL_18;
  }
}
// 109CBE0: using guessed type wchar_t aGb[4];
// 10C4E28: using guessed type int gdwVirtualScreenWidth;
// 1011470: using guessed type int var_F0[2];

//----- (01011A60) --------------------------------------------------------
HICON __cdecl GraphData_DrawChart(CGraphData *pGraphData, HDC hDC, RECT *lprc, COLORREF Color, DWORD dwValue, double dbValue)
{
  HDC hCompatibleDC; // eax
  LONG nWidth; // ebx
  signed int nHeight; // edx
  COLORREF Color_1; // ecx
  void (__stdcall *DeleteObject)(HGDIOBJ); // edi
  unsigned int nSize; // ecx
  CGraphData *pGraphData_1; // edi
  int gdwVirtualScreenWidth; // ecx
  int v14; // edx
  tagGraphItem *pItem; // esi
  bool v16; // sf
  unsigned __int8 v17; // of
  unsigned int v18; // edx
  unsigned int v19; // eax
  unsigned int v20; // edx
  unsigned int v21; // eax
  int v22; // edx
  int v23; // edi
  int v24; // esi
  double v25; // xmm2_8
  double v26; // xmm1_8
  double v27; // xmm1_8
  int v28; // esi
  int v29; // edx
  int v30; // ecx
  int v31; // eax
  LONG bottom_1; // eax
  LONG index; // edi
  int y; // esi
  int nChildID; // edx
  int v36; // edx
  int v37; // edi
  int v38; // edx
  int v39; // esi
  double v40; // xmm1_8
  double v41; // xmm1_8
  double v42; // xmm1_8
  int v43; // edi
  int v44; // eax
  signed int v45; // esi
  int v46; // edx
  int v47; // ecx
  int v48; // ebx
  int v49; // ecx
  int v50; // edx
  tagGraphItem *v51; // edi
  HBRUSH hBrush; // esi
  HICON v53; // esi
  ICONINFO piconinfo; // [esp+Ch] [ebp-80h]
  HDC hdc; // [esp+20h] [ebp-6Ch]
  unsigned int v57; // [esp+24h] [ebp-68h]
  unsigned int v58; // [esp+28h] [ebp-64h]
  double v59; // [esp+2Ch] [ebp-60h]
  int v60; // [esp+34h] [ebp-58h]
  int v61; // [esp+38h] [ebp-54h]
  int nGraphWidth; // [esp+3Ch] [ebp-50h]
  RECT *lprc_1; // [esp+40h] [ebp-4Ch]
  int v64; // [esp+44h] [ebp-48h]
  int v65; // [esp+48h] [ebp-44h]
  int v66; // [esp+4Ch] [ebp-40h]
  BitmapItem BitmapItem; // [esp+50h] [ebp-3Ch]
  LONG bottom; // [esp+64h] [ebp-28h]
  int right; // [esp+68h] [ebp-24h]
  unsigned int a6; // [esp+6Ch] [ebp-20h]
  tagGraphItem *pItem_1; // [esp+70h] [ebp-1Ch]
  int v72; // [esp+74h] [ebp-18h]
  RECT rc; // [esp+78h] [ebp-14h]
  COLORREF Colora; // [esp+A0h] [ebp+14h]

  hCompatibleDC = 0;
  lprc_1 = lprc;
  nWidth = lprc->right - lprc->left;
  nHeight = lprc->bottom - lprc->top;
  Color_1 = Color;
  if ( Color == -1 )
    Color_1 = gConfig.ColorGraphBk;
  hdc = hDC;
  BitmapItem.nHeight = 0;
  BitmapItem.nWidth = 0;
  BitmapItem.CompatibleDC = 0;
  BitmapItem.hBitmapHandle = 0;
  right = nWidth;
  bottom = nHeight;
  v59 = 0.0;
  Colora = Color_1;
  DeleteObject = ::DeleteObject;
  if ( hDC && (!nWidth || !nHeight) )
    goto LABEL_111;
  BitmapItem_Create(&BitmapItem, nWidth, nHeight);
  nSize = BitmapItem.nHeight * BitmapItem.nWidth;
  if ( BitmapItem.pBits && nSize )
    memset32(BitmapItem.pBits, (Colora & 0xFF00) | (Colora << 16) | (Colora >> 16) & 0xFF, nSize);
  pGraphData_1 = pGraphData;
  gdwVirtualScreenWidth = ::gdwVirtualScreenWidth;
  nGraphWidth = pGraphData->m_nWidth - 1;
  if ( nGraphWidth < 0 )
    nGraphWidth = ::gdwVirtualScreenWidth - 1;
  v14 = 0;
  for ( pItem = pGraphData->m_Item; ; ++pItem )
  {
    pItem_1 = pItem;
    v17 = __OFSUB__(v14, pGraphData_1->m_nChildID);
    v16 = (v14 - pGraphData_1->m_nChildID) < 0;
    v65 = v14;
    if ( !(v16 ^ v17) )
      break;
    v18 = pItem[-1].Color;
    a6 = pItem[-1].Color;
    if ( Colora && right <= 20 && bottom <= 20 )
    {
      v19 = v18;
      v20 = v18 >> 16;
      v21 = v19 >> 8;
      if ( v21 <= v20 )
        a6 = a6 < v20 ? 0xFF0000 : 255;
      else
        a6 = a6 < v21 ? 0xFF00 : 255;
    }
    v22 = 0;
    v23 = -1;
    v66 = 0;
    if ( gdwVirtualScreenWidth > 0 )
    {
      v24 = 0;
      v64 = 0;
      v72 = right - 1;
      do
      {
        if ( v24 >= right + 1 )
          break;
        v25 = pItem_1->pBuffer[(nGraphWidth + gdwVirtualScreenWidth - v22) % gdwVirtualScreenWidth];
        if ( v25 > v59 )
          v59 = pItem_1->pBuffer[(nGraphWidth + gdwVirtualScreenWidth - v22) % gdwVirtualScreenWidth];
        if ( dbValue == 0.0 )
          v26 = v25 / pItem_1[-1].dbMemorySize;
        else
          v26 = v25 / dbValue;
        v27 = v26 * bottom;
        v28 = bottom - v27;
        if ( v23 != -1 && v25 != 0.0 )
        {
          v29 = v72;
          v30 = bottom - v27;
          v31 = v72 + 2;
          if ( v72 >= 0 )
          {
            if ( v72 >= BitmapItem.nWidth )
              v29 = BitmapItem.nWidth - 1;
          }
          else
          {
            v29 = 0;
          }
          if ( v31 >= 0 )
          {
            if ( v31 >= BitmapItem.nWidth )
              v31 = BitmapItem.nWidth - 1;
          }
          else
          {
            v31 = 0;
          }
          if ( v28 >= 0 )
          {
            if ( v28 >= BitmapItem.nHeight )
              v30 = BitmapItem.nHeight - 1;
          }
          else
          {
            v30 = 0;
          }
          if ( v23 >= 0 )
          {
            if ( v23 >= BitmapItem.nHeight )
              v23 = BitmapItem.nHeight - 1;
          }
          else
          {
            v23 = 0;
          }
          sub_1010A90(&BitmapItem, v30, v29, v23, v31, a6, 1);
          gdwVirtualScreenWidth = ::gdwVirtualScreenWidth;
        }
        v23 = v28;
        v22 = v66 + 1;
        v72 -= 2;
        v24 = v64 + 2;
        v66 = v22;
        v64 += 2;
      }
      while ( v22 < gdwVirtualScreenWidth );
      pItem = pItem_1;
    }
    pGraphData_1 = pGraphData;
    v14 = v65 + 1;
  }
  bottom_1 = bottom;
  if ( bottom > 60 )
  {
    index = 0;
    if ( lprc_1->bottom > 0 )
    {
      y = 0;
      do
      {
        if ( y >= bottom_1 )
          break;
        if ( !(index % 15) )
          sub_1010ED0(&BitmapItem, 0, y, right, y, 0x828282u, 0);
        ++index;
        y += 2;
        bottom_1 = bottom;
      }
      while ( index < lprc_1->bottom );
      gdwVirtualScreenWidth = ::gdwVirtualScreenWidth;
    }
    pGraphData_1 = pGraphData;
  }
  nChildID = pGraphData_1->m_nChildID;
  while ( 1 )
  {
    v36 = nChildID - 1;
    v61 = v36;
    if ( v36 < 0 )
      break;
    v37 = pGraphData_1->m_nChildID - v36 - 1;
    v72 = -1;
    v38 = 0;
    v66 = v37;
    v64 = 0;
    if ( gdwVirtualScreenWidth > 0 )
    {
      v39 = 0;
      v60 = 0;
      a6 = right - 1;
      while ( 1 )
      {
        if ( v39 >= right + 1 )
          goto LABEL_108;
        v40 = pGraphData->m_Item[v37].pBuffer[(nGraphWidth + gdwVirtualScreenWidth - v38) % gdwVirtualScreenWidth];
        if ( v40 > v59 )
          v59 = pGraphData->m_Item[v37].pBuffer[(nGraphWidth + gdwVirtualScreenWidth - v38) % gdwVirtualScreenWidth];
        v41 = dbValue == 0.0 ? v40 / *(&pGraphData->m_dbMemorySize + 3 * v37) : v40 / dbValue;
        v42 = v41 * bottom;
        v43 = bottom - v42;
        v44 = v72;
        v65 = bottom - v42;
        if ( v72 != -1 )
          break;
LABEL_107:
        a6 -= 2;
        v39 = v60 + 2;
        v37 = v66;
        v72 = v65;
        v38 = v64 + 1;
        v60 += 2;
        v64 = v38;
        if ( v38 >= gdwVirtualScreenWidth )
          goto LABEL_108;
      }
      pItem_1 = a6;
      v45 = a6 + 2;
      v57 = a6 + 2;
      v46 = bottom - v42;
      v58 = *(&pGraphData->m_Color + 6 * v66);
      v47 = v72;
      if ( (a6 & 0x80000000) != 0 )
      {
        pItem_1 = 0;
        goto LABEL_73;
      }
      if ( a6 >= BitmapItem.nWidth )
      {
        pItem_1 = (BitmapItem.nWidth - 1);
LABEL_73:
        v44 = v72;
      }
      if ( v45 >= 0 )
      {
        if ( v45 < BitmapItem.nWidth )
          v48 = v57;
        else
          v48 = BitmapItem.nWidth - 1;
      }
      else
      {
        v48 = 0;
      }
      if ( v43 >= 0 )
      {
        if ( v43 >= BitmapItem.nHeight )
          v46 = BitmapItem.nHeight - 1;
      }
      else
      {
        v46 = 0;
      }
      if ( v44 >= 0 )
      {
        if ( v44 >= BitmapItem.nHeight )
          v47 = BitmapItem.nHeight - 1;
      }
      else
      {
        v47 = 0;
      }
      sub_1010A90(&BitmapItem, v46, pItem_1, v47, v48, v58, 0);
      v49 = v43 + 1;
      if ( v43 + 1 < bottom )
      {
        v50 = v72 + 1;
        pItem_1 = a6;
        if ( (a6 & 0x80000000) != 0 )
        {
          v51 = 0;
          goto LABEL_92;
        }
        if ( a6 >= BitmapItem.nWidth )
        {
          v51 = (BitmapItem.nWidth - 1);
LABEL_92:
          pItem_1 = v51;
        }
        if ( v45 >= 0 )
        {
          if ( v45 >= BitmapItem.nWidth )
            v45 = BitmapItem.nWidth - 1;
        }
        else
        {
          v45 = 0;
        }
        if ( v49 >= 0 )
        {
          if ( v49 >= BitmapItem.nHeight )
            v49 = BitmapItem.nHeight - 1;
        }
        else
        {
          v49 = 0;
        }
        if ( v50 >= 0 )
        {
          if ( v50 >= BitmapItem.nHeight )
            v50 = BitmapItem.nHeight - 1;
        }
        else
        {
          v50 = 0;
        }
        sub_1010A90(&BitmapItem, v49, pItem_1, v50, v45, *(&pGraphData->m_Color + 6 * v66), 0);
      }
      gdwVirtualScreenWidth = ::gdwVirtualScreenWidth;
      goto LABEL_107;
    }
LABEL_108:
    nChildID = v61;
    pGraphData_1 = pGraphData;
  }
  hBrush = CreateSolidBrush(0x828282u);
  rc.left = 0;
  rc.right = right;
  rc.bottom = bottom;
  rc.top = 0;
  FrameRect(BitmapItem.CompatibleDC, &rc, hBrush);
  DeleteObject = ::DeleteObject;
  ::DeleteObject(hBrush);
  if ( hdc )
  {
    BitBlt(
      hdc,
      lprc_1->left,
      lprc_1->top,
      BitmapItem.nWidth,
      BitmapItem.nHeight,
      BitmapItem.CompatibleDC,
      0,
      0,
      0xCC0020u);
    hCompatibleDC = BitmapItem.CompatibleDC;
LABEL_111:
    v53 = 0;
    goto __quit;
  }
  piconinfo.hbmColor = BitmapItem.hBitmapHandle;
  piconinfo.hbmMask = BitmapItem.hBitmapHandle;
  piconinfo.fIcon = 1;
  piconinfo.xHotspot = 0;
  piconinfo.yHotspot = 0;
  v53 = CreateIconIndirect(&piconinfo);
  hCompatibleDC = BitmapItem.CompatibleDC;
__quit:
  if ( hCompatibleDC )
    DeleteDC(hCompatibleDC);
  if ( BitmapItem.hBitmapHandle )
    DeleteObject(BitmapItem.hBitmapHandle);
  return v53;
}
// 10C4E28: using guessed type int gdwVirtualScreenWidth;

//----- (01011FD0) --------------------------------------------------------
char *__cdecl sub_1011FD0(FILETIME *a1, HDC hDC, RECT *lprc, COLORREF ColorBack)
{
  char *nWidth; // eax
  signed int nHeight; // ecx
  COLORREF Color; // ebx
  unsigned int nSize; // ecx
  float v8; // xmm0_4
  char *v9; // edi
  float v10; // xmm0_4
  LONG v11; // ebx
  HBRUSH hBrush; // esi
  RECT rect; // [esp+8h] [ebp-64h]
  struct _FILETIME FileTime; // [esp+18h] [ebp-54h]
  RECT *v15; // [esp+20h] [ebp-4Ch]
  char *nWidth_1; // [esp+24h] [ebp-48h]
  LONG nHeight_1; // [esp+28h] [ebp-44h]
  HDC hdc; // [esp+2Ch] [ebp-40h]
  BitmapItem BitmapItem; // [esp+30h] [ebp-3Ch]
  float v20; // [esp+44h] [ebp-28h]
  struct _SYSTEMTIME SystemTime; // [esp+48h] [ebp-24h]
  RECT rc; // [esp+58h] [ebp-14h]

  v20 = *&a1;
  nWidth = (lprc->right - lprc->left);
  nHeight = lprc->bottom - lprc->top;
  Color = ColorBack;
  if ( ColorBack == -1 )
    Color = gConfig.ColorGraphBk;
  hdc = hDC;
  v15 = lprc;
  BitmapItem.nHeight = 0;
  BitmapItem.nWidth = 0;
  BitmapItem.CompatibleDC = 0;
  BitmapItem.hBitmapHandle = 0;
  nWidth_1 = nWidth;
  nHeight_1 = nHeight;
  if ( !hDC || nWidth && nHeight )
  {
    BitmapItem_Create(&BitmapItem, nWidth, nHeight);
    nSize = BitmapItem.nHeight * BitmapItem.nWidth;
    if ( BitmapItem.pBits && nSize )
      memset32(BitmapItem.pBits, (Color & 0xFF00) | (Color << 16) | (Color >> 16) & 0xFF, nSize);
    GetSystemTime(&SystemTime);
    SystemTimeToFileTime(&SystemTime, &FileTime);
    rect.top = 0;
    v8 = (*&FileTime - *LODWORD(v20));
    v20 = v8;
    v9 = nWidth_1;
    v10 = (*&FileTime - *&gCreateTimeLast);
    v11 = nHeight_1;
    rect.right = nWidth_1;
    rect.bottom = nHeight_1;
    rect.left = &nWidth_1[-((v20 / v10) * nWidth_1)];
    BitmapItem_SetRectColor(&BitmapItem, &rect, 0x9ECA9Eu);
    hBrush = CreateSolidBrush(0x828282u);
    rc.left = 0;
    rc.top = 0;
    rc.right = v9;
    rc.bottom = v11;
    FrameRect(BitmapItem.CompatibleDC, &rc, hBrush);
    DeleteObject(hBrush);
    BitBlt(hdc, v15->left, v15->top, BitmapItem.nWidth, BitmapItem.nHeight, BitmapItem.CompatibleDC, 0, 0, 0xCC0020u);
    if ( BitmapItem.CompatibleDC )
      DeleteDC(BitmapItem.CompatibleDC);
    nWidth = BitmapItem.hBitmapHandle;
    if ( BitmapItem.hBitmapHandle )
      nWidth = DeleteObject(BitmapItem.hBitmapHandle);
  }
  return nWidth;
}

//----- (010121A0) --------------------------------------------------------
int __cdecl GraphData_QueryData(CGraphData *pGraphData, double *pArg1, double *pArg2)
{
  int nWidth; // edi

  EnterCriticalSection(&pGraphData->m_Lock.m_Lock);
  nWidth = pGraphData->m_nWidth - 1;
  if ( nWidth < 0 )
    nWidth = gdwVirtualScreenWidth - 1;
  *pArg1 = pGraphData->m_Item[0].pBuffer[nWidth];
  if ( pArg2 && pGraphData->m_nChildID > 1 )
    *pArg2 = pGraphData->m_Item[1].pBuffer[nWidth];
  LeaveCriticalSection(&pGraphData->m_Lock.m_Lock);
  return nWidth;
}
// 10C4E28: using guessed type int gdwVirtualScreenWidth;

//----- (01012200) --------------------------------------------------------
int __cdecl PE_FormatDouble(char bFlags, wchar_t *pszText, size_t dwLength, double dbValue1, double dbValue2, double dbValue3)
{
  char v6; // al
  char v7; // dl
  int offset; // esi
  double dbValue9; // xmm3_8
  double dbValue10; // xmm0_8
  double dbValue11; // xmm1_8
  double dbValue12; // xmm4_8
  double dbValue13; // xmm2_8
  double dbValue14; // xmm0_8
  double v15; // xmm1_8
  signed int index; // edi
  size_t dwLength_1; // ecx
  double dbValue18; // xmm0_8
  int nLength; // eax
  const wchar_t *v20; // eax
  char bRet1; // [esp+1Eh] [ebp-1Eh]
  char bRet2; // [esp+1Fh] [ebp-1Dh]
  double dbValue[3]; // [esp+20h] [ebp-1Ch]

  v6 = 0;
  v7 = 0;
  bRet1 = 0;
  offset = 0;
  bRet2 = 0;
  if ( !bFlags )
    return PE_FormatDoubleFlow(pszText, dwLength, dbValue1 + dbValue2);
  dbValue9 = dbValue3;
  dbValue10 = dbValue2;
  if ( dbValue3 <= dbValue2 )
    dbValue11 = dbValue3;
  else
    dbValue11 = dbValue2;
  if ( dbValue2 <= dbValue3 )
    dbValue10 = dbValue3;
  dbValue12 = dbValue1;
  if ( dbValue10 <= dbValue1 )
    dbValue13 = dbValue10;
  else
    dbValue13 = dbValue1;
  if ( dbValue1 > dbValue10 )
    dbValue10 = dbValue1;
  dbValue[0] = dbValue10;
  dbValue14 = dbValue13;
  if ( dbValue11 <= dbValue13 )
    dbValue13 = dbValue11;
  if ( dbValue14 <= dbValue11 )
    dbValue14 = dbValue11;
  v15 = ::dbValue3;
  *pszText = 0;
  index = 0;
  dwLength_1 = dwLength;
  dbValue[1] = dbValue14;
  dbValue[2] = dbValue13;
  do
  {
    dbValue18 = dbValue[index];
    if ( dbValue18 != v15 )
    {
      if ( offset > 0 )
      {
        dbValue18 = dbValue[index];
        dbValue9 = dbValue3;
        offset += swprintf_s(&pszText[offset], dwLength_1 - offset, L"\n");
        v15 = ::dbValue3;
        dbValue12 = dbValue1;
        dwLength_1 = dwLength;
        v6 = bRet1;
        v7 = bRet2;
      }
      if ( dbValue18 != dbValue2 || v7 )
      {
        if ( dbValue18 != dbValue12 || v6 )
        {
          nLength = swprintf_s(&pszText[offset], dwLength_1 - offset, L"O: ");
        }
        else
        {
          v20 = L"R";
          if ( dbValue9 == v15 )
            v20 = L"R+O";
          nLength = swprintf_s(&pszText[offset], dwLength_1 - offset, L"%s: ", v20);
          bRet1 = 1;
        }
      }
      else
      {
        nLength = swprintf_s(&pszText[offset], dwLength_1 - offset, L"W: ");
        bRet2 = 1;
      }
      dbValue9 = dbValue3;
      v15 = ::dbValue3;
      offset += PE_FormatDoubleFlow(&pszText[nLength + offset], dwLength - (nLength + offset), dbValue[index]) + nLength;
      dbValue12 = dbValue1;
      dwLength_1 = dwLength;
      v6 = bRet1;
      v7 = bRet2;
    }
    ++index;
  }
  while ( index < 3 );
  return offset;
}
// 109CBB8: using guessed type wchar_t aR[2];
// 109CBBC: using guessed type wchar_t aRO[4];

//----- (01012410) --------------------------------------------------------
errno_t __cdecl sub_1012410(wchar_t *a1, rsize_t SizeInWords, int a3, __int64 a4)
{
  double v4; // xmm0_8
  const wchar_t *v6; // [esp+4h] [ebp-50h]
  wchar_t Dst; // [esp+10h] [ebp-44h]

  wcscpy_s(&Dst, 0x20u, L" KB");
  v4 = *&a4;
  if ( *&a4 > 1048576.0 )
  {
    v4 = *&a4 * 0.00000095367431640625;
    v6 = L" GB";
LABEL_5:
    wcscpy_s(&Dst, 0x20u, v6);
    goto LABEL_6;
  }
  if ( *&a4 > 1024.0 )
  {
    v4 = *&a4 * 0.0009765625;
    v6 = L" MB";
    goto LABEL_5;
  }
LABEL_6:
  swprintf_s(a1, SizeInWords, L"%s%0.1f", a3, LODWORD(v4), HIDWORD(v4));
  return wcscat_s(a1, SizeInWords, &Dst);
}
// 109CBE0: using guessed type wchar_t aGb[4];

//----- (010124C0) --------------------------------------------------------
void __cdecl sub_10124C0(int a1)
{
  wchar_t *v1; // edi
  __int16 v2; // si
  int v3; // esi
  int v4; // edx
  _DWORD *v5; // edx
  int v6; // eax
  __int16 *v7; // ecx
  __int16 v8; // ax
  wchar_t *v9; // eax
  int v10; // ecx
  int v11; // eax
  int v12; // edx
  __int16 *v13; // ecx
  __int16 v14; // ax
  int v15; // ecx
  const wchar_t *v16; // eax
  int v17; // ecx
  double dbValue2; // ST14_8
  __int64 dbValue3; // [esp+10h] [ebp-2D4h]
  int dbValue3_4; // [esp+14h] [ebp-2D0h]
  int dbValue3_4a; // [esp+14h] [ebp-2D0h]
  struct _FILETIME LocalFileTime; // [esp+24h] [ebp-2C0h]
  FILETIME FileTime; // [esp+2Ch] [ebp-2B8h]
  int v24; // [esp+34h] [ebp-2B0h]
  struct _SYSTEMTIME SystemTime; // [esp+38h] [ebp-2ACh]
  struct tagRECT Rect; // [esp+48h] [ebp-29Ch]
  wchar_t Dst; // [esp+58h] [ebp-28Ch]
  WCHAR TimeStr; // [esp+260h] [ebp-84h]

  v1 = (a1 + 4);
  *(a1 + 4) = 0;
  GetClientRect(*a1, &Rect);
  v2 = *(a1 + 2052);
  if ( (Rect.right - v2 - 1) / 2 <= gdwVirtualScreenWidth )
  {
    EnterCriticalSection(*(a1 + 2056));
    v3 = (*(*(a1 + 2056) + 24) - (Rect.right - *(a1 + 2052)) / 2 + gdwVirtualScreenWidth - 1) % gdwVirtualScreenWidth;
    v4 = *(a1 + 2056);
    if ( !*(*(v4 + 2156) + 4 * v3) )
    {
LABEL_52:
      LeaveCriticalSection(*(a1 + 2056));
      *(a1 + 2052) += 20;
      *(a1 + 2054) += 20;
      goto LABEL_53;
    }
    switch ( *(v4 + 32) )
    {
      case 0:
        wsprintfW(v1, L"CPU\n");
        break;
      case 2:
        wsprintfW(v1, L"I/O\n");
        break;
      case 4:
        wsprintfW(v1, L"GPU\n");
        break;
      case 8:
        wsprintfW(v1, L"Disk\n");
        break;
      case 9:
        wsprintfW(v1, L"Network\n");
        break;
      default:
        break;
    }
    v5 = *(a1 + 2056);
    if ( v5[536] )
    {
      v6 = v5[8];
      if ( !v6 || v6 == 4 )
      {
        v7 = (a1 + 4);
        v24 = a1 + 6;
        do
        {
          v8 = *v7;
          ++v7;
        }
        while ( v8 );
        sub_1010E00((a1 + 4 + 2 * ((v7 - v24) >> 1)), 1024 - ((v7 - v24) >> 1), &gszNullString, *(v5[13] + 8 * v3));
        wcscat_s(v1, 0x400u, L"\n");
      }
      v9 = *(*(*(a1 + 2056) + 2144) + 4 * v3);
      if ( !v9 || !*v9 )
        goto LABEL_51;
    }
    else
    {
      if ( !v5[543] )
      {
        *v1 = 0;
        if ( *(v5[539] + 4 * v3) )
        {
          v15 = v5[8];
          switch ( v15 )
          {
            case 0:
            case 4:
              v16 = L"GPU\n";
              dbValue3 = *(v5[13] + 8 * v3);
              if ( v15 != 4 )
                v16 = L"CPU\n";
              sub_10109F0(v1, v16, dbValue3);
              break;
            case 1:
              sub_1010A40(v1, L"System Commit\n", *(v5[13] + 8 * v3));
              break;
            case 2:
              wsprintfW(v1, L"I/O\n");
              goto LABEL_48;
            case 3:
              sub_1010A40(v1, L"Physical Memory\n", *(v5[13] + 8 * v3));
              break;
            case 5:
              sub_1010A40(v1, L"GPU System Memory\n", *(v5[13] + 8 * v3));
              break;
            case 6:
              sub_1010A40(v1, L"GPU Dedicated Memory\n", *(v5[13] + 8 * v3));
              break;
            case 7:
              sub_1010A40(v1, L"GPU Committed Memory\n", *(v5[13] + 8 * v3));
              break;
            case 8:
              wsprintfW(v1, L"Disk\n");
              goto LABEL_48;
            case 9:
              wsprintfW(v1, L"Network\n");
LABEL_48:
              v17 = *(a1 + 2056);
              dbValue2 = *(*(v17 + 76) + 8 * v3);
              PE_FormatDouble(1, v1, 0x400u, *(*(v17 + 52) + 8 * v3) - dbValue2, dbValue2, -1.0);
              break;
            default:
              break;
          }
          if ( *v1 )
            wcscat_s(v1, 0x400u, L"\n");
        }
        goto LABEL_51;
      }
      dbValue3_4 = v5[542];
      if ( v5[8] == 4 )
      {
        wsprintfW(v1, L"GPU Engine %d: ", dbValue3_4);
      }
      else
      {
        v10 = wsprintfW(v1, L"CPU %d", dbValue3_4);
        v11 = *(a1 + 2056);
        v12 = *(v11 + 2160);
        if ( v12 != -1 )
        {
          dbValue3_4a = *(v11 + 2164);
          if ( v12 == 1 )
            swprintf_s((a1 + 4 + 2 * v10), 1024 - v10, L" (Node %d)", dbValue3_4a);
          else
            swprintf_s((a1 + 4 + 2 * v10), 1024 - v10, L" (Core %d)", dbValue3_4a);
        }
      }
      wcscat_s(v1, 0x400u, L" ");
      v13 = (a1 + 4);
      do
      {
        v14 = *v13;
        ++v13;
      }
      while ( v14 );
      sub_1010E00(
        (a1 + 4 + 2 * ((v13 - a1 - 6) >> 1)),
        1024 - ((v13 - a1 - 6) >> 1),
        &gszNullString,
        *(*(*(a1 + 2056) + 52) + 8 * v3));
      if ( !*(*(*(*(a1 + 2056) + 2172) + 2144) + 4 * v3) )
      {
LABEL_51:
        FileTime = (*(*(a1 + 2056) + 2148) + 10000000i64 * *(*(*(a1 + 2056) + 2156) + 4 * v3));
        FileTimeToLocalFileTime(&FileTime, &LocalFileTime);
        FileTimeToSystemTime(&LocalFileTime, &SystemTime);
        GetTimeFormatW(0x400u, 0, &SystemTime, 0, &TimeStr, 64);
        wcscat_s(v1, 0x400u, &TimeStr);
        goto LABEL_52;
      }
      if ( *v1 )
        wcscat_s(v1, 0x400u, L"\n");
      wcscpy_s(&Dst, 0x104u, *(*(*(*(a1 + 2056) + 2172) + 2144) + 4 * v3));
      if ( wcschr(&Dst, 0xAu) )
        *wcschr(&Dst, 0xAu) = 32;
      v9 = &Dst;
    }
    wcscat_s(v1, 0x400u, v9);
    wcscat_s(v1, 0x400u, L"\n");
    goto LABEL_51;
  }
  *(a1 + 2054) += 10;
  *(a1 + 2052) = v2 + 10;
LABEL_53:
  *(a1 + 2060) = 1;
}
// 109CC54: using guessed type wchar_t aCpu[5];
// 109CC9C: using guessed type wchar_t aNodeD[11];
// 109CCCC: using guessed type wchar_t aPhysicalMemory[17];
// 109CCF0: using guessed type wchar_t aSystemCommit[15];
// 109CD10: using guessed type wchar_t aGpuDedicatedMe[22];
// 109CD3C: using guessed type wchar_t aGpuSystemMemor[19];
// 109CD64: using guessed type wchar_t aGpuCommittedMe[22];
// 10C4E28: using guessed type int gdwVirtualScreenWidth;

//----- (01012A70) --------------------------------------------------------
int __cdecl sub_1012A70(HWND hWnd)
{
  HWND v1; // esi
  HWND v2; // edi
  HWND i; // eax
  int result; // eax
  HWND v5; // [esp+Ch] [ebp-4h]

  v1 = hWnd;
  if ( GetParent(hWnd) )
  {
    v1 = GetParent(hWnd);
    v2 = GetParent(v1);
  }
  else
  {
    v2 = v5;
  }
  if ( !IsWindowVisible(v1) )
    goto LABEL_13;
  for ( i = GetFocus(); v1 != i; i = GetParent(i) )
  {
    if ( v2 == i )
      break;
    if ( !i )
      goto LABEL_13;
  }
  if ( i && (v1 == i || v2 == i) )
    result = 1;
  else
LABEL_13:
    result = 0;
  return result;
}

//----- (01012AE0) --------------------------------------------------------
PerformanceInfo *__thiscall PerformanceInfo::PerformanceInfo(PerformanceInfo *this, HKEY hSubKey)
{
  HKEY Flags; // eax
  PerformanceInfo *pThis; // edi
  const WCHAR *szPerfValueName; // esi
  const WCHAR *szValueName; // ebx
  BYTE *v7; // eax
  WCHAR **v8; // ecx
  const WCHAR *psz; // esi
  int i; // ebx
  unsigned int dwCounter; // eax
  const WCHAR *psz1; // esi
  DWORD cbData; // [esp+Ch] [ebp-8h]
  DWORD cbData_1; // [esp+10h] [ebp-4h]

  Flags = hSubKey;
  pThis = this;
  this->m_dwLastCounterOfLastHelp = 0;
  this->m_LastCounterOfLastHelp = 0;
  this->m_PerfValue = 0;
  if ( Flags )
  {
    if ( Flags != 1 )
      return pThis;
    szPerfValueName = L"Explain 009";
    szValueName = L"Last Help";
  }
  else
  {
    szPerfValueName = L"Counter 009";
    szValueName = L"Last Counter";
  }
  hSubKey = 0;
  cbData = 4;
  if ( !RegOpenKeyExW(
          HKEY_LOCAL_MACHINE,
          L"software\\microsoft\\windows nt\\currentversion\\perflib",
          0,
          KEY_READ,
          &hSubKey) )
  {
    if ( RegQueryValueExW(hSubKey, szValueName, 0, 0, pThis, &cbData) )
    {
      RegCloseKey(hSubKey);
      return pThis;
    }
    RegCloseKey(hSubKey);
    if ( !RegQueryValueExW(HKEY_PERFORMANCE_DATA, szPerfValueName, 0, 0, 0, &cbData_1) )
    {
      v7 = operator new[](2 * cbData_1);
      pThis->m_PerfValue = v7;
      if ( RegQueryValueExW(HKEY_PERFORMANCE_DATA, szPerfValueName, 0, 0, v7, &cbData_1)
        || (v8 = operator new[](4 * (pThis->m_dwLastCounterOfLastHelp + 1)), (pThis->m_LastCounterOfLastHelp = v8) == 0) )
      {
        j_j__free(pThis->m_PerfValue);
        return pThis;
      }
      memset(v8, 0, 4 * pThis->m_dwLastCounterOfLastHelp + 4);
      psz = pThis->m_PerfValue;
      for ( i = lstrlenW(pThis->m_PerfValue); i; i = lstrlenW(psz) )
      {
        dwCounter = _wtoi(psz);
        if ( dwCounter > pThis->m_dwLastCounterOfLastHelp )
          break;
        psz1 = &psz[i + 1];
        pThis->m_LastCounterOfLastHelp[dwCounter] = psz1;
        psz = &psz1[lstrlenW(psz1) + 1];
      }
    }
  }
  return pThis;
}
// 109CE14: using guessed type wchar_t aExplain009[12];
// 109CE2C: using guessed type wchar_t aLastHelp[10];

//----- (01012C80) --------------------------------------------------------
void __thiscall PerformanceInfo::~PerformanceInfo(void **this)
{
  void **v1; // esi
  void *v2; // ST00_4

  v1 = this;
  j_j__free(this[1]);
  v2 = v1[2];
  v1[1] = 0;
  j_j__free(v2);
  v1[2] = 0;
  *v1 = 0;
}

//----- (01012CB0) --------------------------------------------------------
int __thiscall PerformanceInfo::FindPerf(PerformanceInfo *pThis, LPCWSTR lpszName)
{
  PerformanceInfo *this; // edi
  signed int index; // esi

  this = pThis;
  if ( IsBadStringPtrW(lpszName, 0xFFFFFFFF) || !this->m_dwLastCounterOfLastHelp || !this->m_LastCounterOfLastHelp )
    return 0;
  index = 1;
  if ( this->m_dwLastCounterOfLastHelp < 1u )
    return 0;
  while ( !this->m_LastCounterOfLastHelp[index] || _wcsicmp(lpszName, this->m_LastCounterOfLastHelp[index]) )
  {
    if ( ++index > this->m_dwLastCounterOfLastHelp )
      return 0;
  }
  return index;
}

//----- (01012D20) --------------------------------------------------------
int __thiscall sub_1012D20(unsigned int *this, unsigned int a2)
{
  int result; // eax

  if ( a2 <= *this )
    result = *(this[1] + 4 * a2);
  else
    result = 0;
  return result;
}

//----- (01012D40) --------------------------------------------------------
LRESULT __cdecl HandleCmdHandler(int a1, HWND hWnd, WPARAM wParam, LPARAM lParam)
{
  int v4; // ecx
  int v5; // esi
  LRESULT result; // eax

  v4 = 0;
  v5 = *(a1 + 4);
  if ( *a1 <= 0 )
  {
LABEL_4:
    switch ( *(a1 + 8) )
    {
      case 1:
        result = DefWindowProcW(hWnd, 0x111u, wParam, lParam);
        break;
      case 2:
        result = DefDlgProcW(hWnd, 0x111u, wParam, lParam);
        break;
      case 3:
        result = DefMDIChildProcW(hWnd, 0x111u, wParam, lParam);
        break;
      case 4:
        result = DefFrameProcW(hWnd, 0, 0x111u, wParam, lParam);
        break;
      default:
        result = 0;
        break;
    }
  }
  else
  {
    while ( *(v5 + 8 * v4) != wParam )
    {
      if ( ++v4 >= *a1 )
        goto LABEL_4;
    }
    result = (*(v5 + 8 * v4 + 4))(hWnd, wParam, wParam >> 16, lParam);
  }
  return result;
}

//----- (01012E00) --------------------------------------------------------
LRESULT __cdecl HandleMsgHandler(tagMSGHANDLER *pMsgHander, HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
  int nIndex; // eax
  PMSGFUNC WindowMsgFunc; // esi
  LRESULT result; // eax

  nIndex = 0;
  WindowMsgFunc = pMsgHander->WindowMsgFunc;
  if ( pMsgHander->nLength <= 0 )
  {
LABEL_4:
    switch ( pMsgHander->Flags )
    {
      case 1:
        result = DefWindowProcW(hWnd, Msg, wParam, lParam);
        break;
      case 2:
        result = DefDlgProcW(hWnd, Msg, wParam, lParam);
        break;
      case 3:
        result = DefMDIChildProcW(hWnd, Msg, wParam, lParam);
        break;
      case 4:
        result = DefFrameProcW(hWnd, 0, Msg, wParam, lParam);
        break;
      default:
        result = 0;
        break;
    }
  }
  else
  {
    while ( WindowMsgFunc[nIndex].msg != Msg )
    {
      if ( ++nIndex >= pMsgHander->nLength )
        goto LABEL_4;
    }
    result = (WindowMsgFunc[nIndex].pfn)(hWnd, Msg, wParam, lParam);
  }
  return result;
}

//----- (01012EC0) --------------------------------------------------------
bool __cdecl CDriver::SaveDriverFromResource(LPCWSTR lpName, const wchar_t *lpszFileName)
{
  HRSRC hRsrc; // eax
  HRSRC hRsrc_1; // edi
  HGLOBAL hGlobal; // esi
  DWORD dwSize; // edi
  const void *pBuffer; // esi
  FILE *pFile; // [esp+4h] [ebp-4h]

  hRsrc = FindResourceW(0, lpName, L"BINRES");
  hRsrc_1 = hRsrc;
  if ( !hRsrc )
    return 0;
  hGlobal = LoadResource(0, hRsrc);
  dwSize = SizeofResource(0, hRsrc_1);
  pBuffer = LockResource(hGlobal);
  if ( _wfopen_s(&pFile, lpszFileName, L"wb") )
    return 0;
  fwrite(pBuffer, 1u, dwSize, pFile);
  fclose(pFile);
  return 1;
}

//----- (01012F50) --------------------------------------------------------
BOOL __cdecl CDriver::OpenEx(const WCHAR *lpszDriverName, WCHAR *lpszPathName, PHANDLE DriverHandle)
{
  BOOL result; // eax
  HMODULE v4; // eax
  FARPROC RtlInitUnicodeString; // eax
  HMODULE v6; // eax
  WCHAR *v7; // esi
  DWORD (__stdcall *v8)(LONG); // eax
  HMODULE v9; // eax
  DWORD v10; // eax
  HANDLE v11; // eax
  UNICODE_STRING strKeyName; // [esp+8h] [ebp-A40h]
  WCHAR *lpszPathName_1; // [esp+10h] [ebp-A38h]
  HKEY hKey; // [esp+14h] [ebp-A34h]
  DWORD dwValue; // [esp+18h] [ebp-A30h]
  WCHAR szSubKeyName[260]; // [esp+1Ch] [ebp-A2Ch]
  WCHAR szBuffer[260]; // [esp+224h] [ebp-824h]
  WCHAR FileName[260]; // [esp+42Ch] [ebp-61Ch]
  WCHAR pszBuffer[260]; // [esp+634h] [ebp-414h]
  WCHAR szKeyName[260]; // [esp+83Ch] [ebp-20Ch]

  lpszPathName_1 = lpszPathName;
  TmAdjustPrivilege(L"SeLoadDriverPrivilege");
  swprintf(szKeyName, L"System\\CurrentControlSet\\Services\\%s", lpszDriverName);
  if ( RegCreateKeyW(HKEY_LOCAL_MACHINE, szKeyName, &hKey) )
    return 0;
  dwValue = 1;
  RegSetValueExW(hKey, L"Type", 0, REG_DWORD, &dwValue, 4u);
  dwValue = 1;
  RegSetValueExW(hKey, L"ErrorControl", 0, REG_DWORD, &dwValue, 4u);
  dwValue = 3;
  RegSetValueExW(hKey, L"Start", 0, REG_DWORD, &dwValue, 4u);
  swprintf(szBuffer, L"\\??\\%s", lpszPathName_1);
  RegSetValueExW(hKey, L"ImagePath", 0, REG_SZ, szBuffer, 2 * wcslen(szBuffer));
  RegCloseKey(hKey);
  v4 = GetModuleHandleW(L"ntdll.dll");
  lpszPathName_1 = GetProcAddress(v4, "NtLoadDriver");
  swprintf(szSubKeyName, L"\\Registry\\Machine\\System\\CurrentControlSet\\Services\\%s", lpszDriverName);
  RtlInitUnicodeString = *gpfnRtlInitUnicodeString;
  if ( !*gpfnRtlInitUnicodeString )
  {
    v6 = GetModuleHandleW(L"ntdll.dll");
    RtlInitUnicodeString = GetProcAddress(v6, "RtlInitUnicodeString");
    *gpfnRtlInitUnicodeString = RtlInitUnicodeString;
  }
  (RtlInitUnicodeString)(&strKeyName, szSubKeyName);
  lpszPathName_1 = (lpszPathName_1)(&strKeyName);
  swprintf(pszBuffer, L"%s\\Enum", szKeyName);
  RegDeleteKeyW(HKEY_LOCAL_MACHINE, pszBuffer);
  swprintf(pszBuffer, L"%s\\Security", szKeyName);
  RegDeleteKeyW(HKEY_LOCAL_MACHINE, pszBuffer);
  RegDeleteKeyW(HKEY_LOCAL_MACHINE, szKeyName);
  v7 = lpszPathName_1;
  if ( lpszPathName_1 && lpszPathName_1 != STATUS_IMAGE_ALREADY_LOADED )
  {
    v8 = gpfnRtlNtStatusToDosError;
    if ( !gpfnRtlNtStatusToDosError )
    {
      v9 = GetModuleHandleW(L"ntdll.dll");
      v8 = GetProcAddress(v9, "RtlNtStatusToDosError");
      gpfnRtlNtStatusToDosError = v8;
    }
    v10 = v8(v7);
    SetLastError(v10);
    result = 0;
  }
  else
  {
    swprintf(FileName, L"\\\\.\\%s", lpszDriverName);
    v11 = CreateFileW(FileName, GENERIC_WRITE|GENERIC_READ, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
    *DriverHandle = v11;
    if ( v11 == -1 )
    {
      swprintf(FileName, L"\\\\.\\Global\\%s", lpszDriverName);
      *DriverHandle = CreateFileW(FileName, GENERIC_WRITE|GENERIC_READ, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
    }
    result = *DriverHandle + 1 != 0;
  }
  return result;
}

//----- (01013260) --------------------------------------------------------
BOOL __cdecl CDriver::Open(const WCHAR *lpszDriverName, PHANDLE DriverHandle)
{
  HANDLE Handle; // eax
  WCHAR szFileName[260]; // [esp+8h] [ebp-20Ch]

  swprintf(szFileName, L"\\\\.\\%s", lpszDriverName);
  Handle = CreateFileW(szFileName, GENERIC_WRITE|GENERIC_READ, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
  *DriverHandle = Handle;
  if ( Handle == INVALID_HANDLE_VALUE )
  {
    swprintf(szFileName, L"\\\\.\\Global\\%s", lpszDriverName);
    *DriverHandle = CreateFileW(szFileName, GENERIC_WRITE|GENERIC_READ, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
  }
  return *DriverHandle + 1 != 0;
}

//----- (01013310) --------------------------------------------------------
_DWORD *__stdcall sub_1013310(_DWORD *a1, _DWORD *a2, _DWORD *a3)
{
  _DWORD *result; // eax

  result = sub_1014360(a1, a2);
  if ( result != -8 )
  {
    result[2] = *a3;
    result[3] = a3[1];
  }
  return result;
}

//----- (01013340) --------------------------------------------------------
char __cdecl sub_1013340(HANDLE ProcessHandle, int a2, int a3, int time, int time_4, tagTREEVIEWLISTITEMPARAM *pItemParam, WPARAM wParam)
{
  tagTREEVIEWLISTITEMPARAM *pItemParam_1; // ecx
  unsigned int v8; // edi
  std__list_node_for_AdapterLuid *_Node; // esi
  int v10; // ebx
  ULONG NodeIndex; // ebx
  signed int fDone; // edi
  int v13; // eax
  HANDLE ProcessHandle_1; // ebx
  ULONG NbSegmentIndex; // edi
  ULONG v16; // eax
  int v17; // esi
  int v18; // edx
  int v19; // eax
  float v20; // xmm2_4
  float v21; // xmm0_4
  float v22; // ST4C_4
  float v23; // ST40_4
  float v24; // xmm0_4
  HWND hWndTreeListView; // ST14_4
  bool v26; // al
  char v27; // ST57_1
  HWND v28; // ST14_4
  unsigned __int8 v29; // al
  char v30; // ST57_1
  float v31; // xmm0_4
  HWND v32; // ST14_4
  unsigned __int8 v33; // al
  char v34; // ST57_1
  float v35; // xmm0_4
  HWND v36; // ST14_4
  unsigned __int8 v37; // al
  char v38; // ST57_1
  float v39; // xmm0_4
  int v41; // [esp+24h] [ebp-FD0h]
  unsigned int NodeSum; // [esp+28h] [ebp-FCCh]
  int CommitLimitSum; // [esp+2Ch] [ebp-FC8h]
  ULONG NodeCount; // [esp+38h] [ebp-FBCh]
  int v45; // [esp+3Ch] [ebp-FB8h]
  int v46; // [esp+40h] [ebp-FB4h]
  int NbSegmentsSum; // [esp+44h] [ebp-FB0h]
  char v48; // [esp+4Fh] [ebp-FA5h]
  _D3DKMT_QUERYSTATISTICS Statistics3; // [esp+50h] [ebp-FA4h]
  _D3DKMT_QUERYSTATISTICS Statistics2; // [esp+370h] [ebp-C84h]
  _D3DKMT_QUERYSTATISTICS Statistics4; // [esp+690h] [ebp-964h]
  _D3DKMT_QUERYSTATISTICS Statistics5; // [esp+9B0h] [ebp-644h]
  _D3DKMT_QUERYSTATISTICS Statistics1; // [esp+CD0h] [ebp-324h]

  pItemParam_1 = pItemParam;
  v48 = 0;
  v8 = 0;
  _Node = gAdapterLuidList._Mypair._Myval2._Myhead->_Next;
  v10 = 0;
  NodeSum = 0;
  v46 = 0;
  v45 = 0;
  v41 = 0;
  if ( gAdapterLuidList._Mypair._Myval2._Myhead->_Next == gAdapterLuidList._Mypair._Myval2._Myhead )
  {
    v17 = 0;
  }
  else
  {
    CommitLimitSum = 0;
    NbSegmentsSum = 0;
    do
    {
      memset(&Statistics1, 0, sizeof(_D3DKMT_QUERYSTATISTICS));
      Statistics1.Type = 0;
      Statistics1.AdapterLuid.LowPart = _Node->_Myval.LowPart;
      Statistics1.AdapterLuid.HighPart = _Node->_Myval.HighPart;
      if ( !D3DKMTQueryStatistics(&Statistics1) )
      {
        NodeIndex = 0;
        NodeCount = Statistics1.QueryResult.AdapterInformation.NodeCount;
        if ( Statistics1.QueryResult.AdapterInformation.NodeCount )
        {
          fDone = 1;
          do
          {
            memset(&Statistics2, 0, sizeof(_D3DKMT_QUERYSTATISTICS));
            Statistics2.Type = D3DKMT_QUERYSTATISTICS_PROCESS_NODE;
            Statistics2.AdapterLuid.LowPart = _Node->_Myval.LowPart;
            Statistics2.AdapterLuid.HighPart = _Node->_Myval.HighPart;
            Statistics2.hProcess = ProcessHandle;
            Statistics2.QuerySegment.SegmentId = NodeIndex;
            if ( !D3DKMTQueryStatistics(&Statistics2) && fDone & gConfig.dwGpuNodeUsageMask )
            {
              ++NodeSum;
              v13 = (Statistics2.QueryResult.SegmentInformation.CommitLimit + __PAIR__(CommitLimitSum, NbSegmentsSum)) >> 32;
              NbSegmentsSum += Statistics2.QueryResult.AdapterInformation.NbSegments;
              CommitLimitSum = v13;
            }
            ++NodeIndex;
            fDone = __ROL4__(fDone, 1);
          }
          while ( NodeIndex < NodeCount );
        }
        if ( v48 )
        {
          ProcessHandle_1 = ProcessHandle;
        }
        else
        {
          memset(&Statistics3, 0, sizeof(_D3DKMT_QUERYSTATISTICS));
          ProcessHandle_1 = ProcessHandle;
          Statistics3.Type = D3DKMT_QUERYSTATISTICS_PROCESS;
          Statistics3.hProcess = ProcessHandle;
          Statistics3.AdapterLuid.LowPart = _Node->_Myval.LowPart;
          Statistics3.AdapterLuid.HighPart = _Node->_Myval.HighPart;
          if ( !D3DKMTQueryStatistics(&Statistics3) )
          {
            v41 = Statistics3.QueryResult.AdapterInformation.VidPnSourceCount >> 10;
            v48 = 1;
          }
        }
        NbSegmentIndex = 0;
        if ( Statistics1.QueryResult.AdapterInformation.NbSegments )
        {
          do
          {
            memset(&Statistics4, 0, sizeof(_D3DKMT_QUERYSTATISTICS));
            Statistics4.Type = D3DKMT_QUERYSTATISTICS_PROCESS_SEGMENT;
            Statistics4.hProcess = ProcessHandle_1;
            Statistics4.AdapterLuid.LowPart = _Node->_Myval.LowPart;
            Statistics4.AdapterLuid.HighPart = _Node->_Myval.HighPart;
            Statistics4.QuerySegment.SegmentId = NbSegmentIndex;
            if ( D3DKMTQueryStatistics(&Statistics4) )
              goto __Next;
            memset(&Statistics5, 0, sizeof(_D3DKMT_QUERYSTATISTICS));
            Statistics5.Type = D3DKMT_QUERYSTATISTICS_SEGMENT;
            Statistics5.AdapterLuid.LowPart = _Node->_Myval.LowPart;
            Statistics5.AdapterLuid.HighPart = _Node->_Myval.HighPart;
            Statistics5.QuerySegment.SegmentId = NbSegmentIndex;
            if ( D3DKMTQueryStatistics(&Statistics5) )
              goto __Next;
            v16 = Statistics4.QueryResult.AdapterInformation.NbSegments >> 10;
            if ( gdwVersion < 3 )
            {
              if ( Statistics5.QueryResult.SegmentInformationV1.Aperture )
              {
LABEL_22:
                v45 += v16;
                goto __Next;
              }
              v46 += v16;
            }
            else
            {
              if ( Statistics5.QueryResult.AdapterInformation.ReferenceDmaBuffer.NbCall )
                goto LABEL_22;
              v46 += v16;
            }
__Next:
            ++NbSegmentIndex;
          }
          while ( NbSegmentIndex < Statistics1.QueryResult.AdapterInformation.NbSegments );
        }
      }
      _Node = _Node->_Next;
    }
    while ( _Node != gAdapterLuidList._Mypair._Myval2._Myhead );
    v8 = NodeSum;
    v10 = CommitLimitSum;
    v17 = NbSegmentsSum;
    pItemParam_1 = pItemParam;
  }
  v18 = pItemParam_1->field_578;
  v19 = pItemParam_1->field_57C;
  if ( v17 != v18 || v10 != v19 )
  {
    v21 = (__PAIR__(v10, v17) - __PAIR__(v19, v18));
    v22 = v21;
    v23 = v8;
    v24 = __PAIR__(a3, a2);
    v20 = (v22 / (v23 * v24)) * 100.0;
    if ( v20 >= 0.0 )
    {
      if ( v20 > 100.0 )
        v20 = 100.0;
    }
    else
    {
      v20 = 0.0;
    }
  }
  else
  {
    v20 = 0.0;
  }
  pItemParam->field_578 = v17;
  pItemParam->field_57C = v10;
  hWndTreeListView = ghWndTreeListView;
  v26 = sub_105F8F0(v20, &pItemParam->m_Gpu2);
  v27 = RedrawColumn(v26, hWndTreeListView, IDS_GPU2, wParam);
  CGraphData_Update(pItemParam->pGraphData4, __PAIR__(time_4, time), *&pItemParam->m_Gpu2, 0.0, 0);
  v28 = ghWndTreeListView;
  v29 = sub_105F920(v41, 0, &pItemParam->m_GpuCommitedByes);
  v30 = RedrawColumn(v29, v28, IDS_GPU_COMMITTED_BYTES, wParam) | v27;
  v31 = pItemParam->m_GpuCommitedByes;
  CGraphData_Update(pItemParam->pGraphData5, __PAIR__(time_4, time), v31, 0.0, 0);
  v32 = ghWndTreeListView;
  v33 = sub_105F920(v45, 0, &pItemParam->m_GpuSystemBytes);
  v34 = RedrawColumn(v33, v32, IDS_GPU_SYSTEM_BYTES, wParam) | v30;
  v35 = pItemParam->m_GpuSystemBytes;
  CGraphData_Update(pItemParam->pGraphData6, __PAIR__(time_4, time), v35, 0.0, 0);
  v36 = ghWndTreeListView;
  v37 = sub_105F920(v46, 0, &pItemParam->m_GpuDedicatedBytes);
  v38 = RedrawColumn(v37, v36, IDS_GPU_DEDICATED_BYTES, wParam) | v34;
  v39 = pItemParam->m_GpuDedicatedBytes;
  CGraphData_Update(pItemParam->pGraphData7, __PAIR__(time_4, time), v39, 0.0, 0);
  return v38;
}
// 109CDC0: using guessed type double db_onehundred;
// 10C4E54: using guessed type int gdwVersion;

//----- (010138F0) --------------------------------------------------------
void __cdecl sub_10138F0(FILETIME time, signed __int64 a2, int a3, int a4, int a5, CGraphData *a6, CGraphData *a7)
{
  unsigned int v7; // ecx
  unsigned int v8; // ebx
  std__list_node *v9; // esi
  unsigned int v10; // edi
  ULONG v11; // edi
  signed int v12; // ebx
  int v13; // eax
  bool v14; // zf
  ULONG v15; // ebx
  ULONG v16; // edi
  float v17; // xmm0_4
  float v18; // ST64_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  int v21; // edi
  ULONG v22; // edi
  unsigned int v23; // eax
  ULONG v24; // ecx
  ULONG v25; // eax
  float v26; // xmm0_4
  float v27; // ST7C_4
  float v28; // ST58_4
  float v29; // xmm0_4
  float v30; // xmm0_4
  WCHAR *v31; // eax
  float v32; // xmm1_4
  float v33; // xmm1_4
  __int64 ArgList_4; // [esp+10h] [ebp-11D4h]
  int a5_4; // [esp+18h] [ebp-11CCh]
  int v36; // [esp+1Ch] [ebp-11C8h]
  ULONG v37; // [esp+38h] [ebp-11ACh]
  unsigned int v38; // [esp+40h] [ebp-11A4h]
  signed int v39; // [esp+48h] [ebp-119Ch]
  unsigned int v40; // [esp+50h] [ebp-1194h]
  ULONG v41; // [esp+58h] [ebp-118Ch]
  unsigned int v42; // [esp+5Ch] [ebp-1188h]
  unsigned int v43; // [esp+68h] [ebp-117Ch]
  unsigned int v44; // [esp+6Ch] [ebp-1178h]
  unsigned int v45; // [esp+70h] [ebp-1174h]
  int v46; // [esp+74h] [ebp-1170h]
  unsigned int v47; // [esp+78h] [ebp-116Ch]
  int v48; // [esp+7Ch] [ebp-1168h]
  float v49; // [esp+7Ch] [ebp-1168h]
  _D3DKMT_QUERYSTATISTICS Statitcs2; // [esp+80h] [ebp-1164h]
  _D3DKMT_QUERYSTATISTICS Statitcs; // [esp+3A0h] [ebp-E44h]
  _D3DKMT_QUERYSTATISTICS Statitcs3; // [esp+6C0h] [ebp-B24h]
  WCHAR szBuffer[1024]; // [esp+9E0h] [ebp-804h]

  v40 = 0;
  szBuffer[0] = 0;
  v46 = 0;
  memset(&szBuffer[1], 0, 2046u);
  v7 = 0;
  v8 = 0;
  v9 = gAdapterLuidList._Mypair._Myval2._Myhead->_Next;
  v10 = 0;
  v42 = 0;
  if ( gAdapterLuidList._Mypair._Myval2._Myhead->_Next == gAdapterLuidList._Mypair._Myval2._Myhead )
  {
    v43 = 0;
    v44 = 0;
    v49 = 0.0;
  }
  else
  {
    v45 = 0;
    v43 = 0;
    v44 = 0;
    v38 = 0;
    v47 = 0;
    do
    {
      memset(&Statitcs, 0, sizeof(_D3DKMT_QUERYSTATISTICS));
      Statitcs.Type = D3DKMT_QUERYSTATISTICS_ADAPTER;
      Statitcs.AdapterLuid.LowPart = v9->_Myval;
      Statitcs.AdapterLuid.HighPart = v9[1]._Next;
      if ( !D3DKMTQueryStatistics(&Statitcs) )
      {
        v11 = 0;
        v41 = Statitcs.QueryResult.AdapterInformation.NodeCount;
        v37 = 0;
        if ( Statitcs.QueryResult.AdapterInformation.NodeCount )
        {
          v12 = 1;
          v39 = 1;
          v13 = a5 + 0x888 + 0x898 * v46;
          v46 += Statitcs.QueryResult.NodeInformation.GlobalInformation.RunningTime.HighPart;
          v48 = v13;
          do
          {
            memset(&Statitcs2, 0, sizeof(_D3DKMT_QUERYSTATISTICS));
            Statitcs2.Type = D3DKMT_QUERYSTATISTICS_NODE;
            Statitcs2.AdapterLuid.LowPart = v9->_Myval;
            Statitcs2.AdapterLuid.HighPart = v9[1]._Next;
            Statitcs2.QuerySegment.SegmentId = v11;
            if ( D3DKMTQueryStatistics(&Statitcs2) )
            {
              v15 = 0;
              v16 = 0;
            }
            else
            {
              v14 = (v12 & gConfig.dwGpuNodeUsageMask) == 0;
              v15 = Statitcs2.QueryResult.AdapterInformation.NodeCount;
              v16 = Statitcs2.QueryResult.AdapterInformation.NbSegments;
              if ( !v14 )
              {
                ++v40;
                v42 = (Statitcs2.QueryResult.SegmentInformation.CommitLimit + __PAIR__(v42, v45)) >> 32;
                v45 += Statitcs2.QueryResult.AdapterInformation.NbSegments;
              }
            }
            if ( a5 )
            {
              if ( v15 | v16 && *v48 )
              {
                v17 = (__PAIR__(v15, v16) - *v48);
                v18 = v17;
                v19 = a2;
                v20 = (v18 / v19) * 100.0;
              }
              else
              {
                v20 = 0.0;
              }
              if ( v20 > 100.0 )
                v20 = 100.0;
              *v48 = v16;
              v21 = v48;
              *(v48 + 4) = v15;
              CGraphData_Update((v48 - 0x888), time, v20, 0.0, 0);
            }
            else
            {
              v21 = v48;
            }
            v48 = v21 + 0x898;
            v11 = v37 + 1;
            v12 = __ROL4__(v39, 1);
            v37 = v11;
            v39 = __ROL4__(v39, 1);
          }
          while ( v11 < v41 );
          v8 = v38;
        }
        v22 = 0;
        if ( Statitcs.QueryResult.AdapterInformation.NbSegments )
        {
          do
          {
            memset(&Statitcs3, 0, sizeof(_D3DKMT_QUERYSTATISTICS));
            Statitcs3.Type = D3DKMT_QUERYSTATISTICS_SEGMENT;
            Statitcs3.AdapterLuid.LowPart = v9->_Myval;
            Statitcs3.AdapterLuid.HighPart = v9[1]._Next;
            Statitcs3.QuerySegment.SegmentId = v22;
            if ( !D3DKMTQueryStatistics(&Statitcs3) )
            {
              if ( gdwVersion < 3 )
              {
                v25 = Statitcs3.QueryResult.AdapterInformation.VidPnSourceCount >> 10;
                if ( Statitcs3.QueryResult.SegmentInformationV1.Aperture )
                {
                  v43 = (v25 + __PAIR__(v43, v44)) >> 32;
                  v44 += v25;
                }
                else
                {
                  v8 = (v25 + __PAIR__(v8, v47)) >> 32;
                  v47 += v25;
                }
              }
              else
              {
                v23 = Statitcs3.QueryResult.SegmentInformationV1.Memory.TotalBytesEvicted >> 10;
                v24 = Statitcs3.QueryResult.NodeInformation.GlobalInformation.PreemptionStatistics.PreemptionCounter[2] >> 10;
                if ( Statitcs3.QueryResult.AdapterInformation.ReferenceDmaBuffer.NbCall )
                {
                  v43 = (__PAIR__(v24, v23) + __PAIR__(v43, v44)) >> 32;
                  v44 += v23;
                }
                else
                {
                  v8 = (__PAIR__(v24, v23) + __PAIR__(v8, v47)) >> 32;
                  v47 += v23;
                }
              }
            }
            ++v22;
          }
          while ( v22 < Statitcs.QueryResult.AdapterInformation.NbSegments );
          v38 = v8;
        }
      }
      v9 = v9->_Next;
    }
    while ( v9 != gAdapterLuidList._Mypair._Myval2._Myhead );
    if ( v42 | v45 && *(a3 + 0x888) )
    {
      v26 = (__PAIR__(v42, v45) - *(a3 + 0x888));
      v27 = v26;
      v28 = v40;
      v29 = a2;
      v30 = (v27 / (v28 * v29)) * 100.0;
      v49 = v30;
      if ( v30 <= 100.0 )
      {
        if ( v30 < 0.0 )
          v49 = 0.0;
      }
      else
      {
        v49 = 100.0;
      }
      v10 = v47;
      v7 = v45;
    }
    else
    {
      v7 = v45;
      v10 = v47;
      v49 = 0.0;
    }
  }
  *(a3 + 0x888) = v7;
  *(a3 + 0x88C) = v42;
  if ( a4 )
  {
    v36 = *(a4 + 0x44);
    a5_4 = *(a4 + 0x3C);
    ArgList_4 = *(a4 + 0x568);
    if ( gConfig.bShowCpuFractions )
      wsprintfW(szBuffer, L"%02.02f%% %s:%d", ArgList_4, a5_4, v36);
    else
      wsprintfW(szBuffer, L"%02.0f%% %s:%d", ArgList_4, a5_4, v36);
  }
  v31 = szBuffer;
  if ( !a4 )
    v31 = 0;
  CGraphData_Update(a3, time, v49, 0.0, v31);
  v32 = __PAIR__(v43, v44);
  if ( v32 > a6->m_dbMemorySize )
    a6->m_dbMemorySize = (v32 * 1.2);
  CGraphData_Update(a6, time, v32, 0.0, 0);
  v33 = __PAIR__(v8, v10);
  if ( v33 > a6->m_dbMemorySize )
    a7->m_dbMemorySize = (v33 * 1.2);
  CGraphData_Update(a7, time, v33, 0.0, 0);
}
// 109CDC0: using guessed type double db_onehundred;
// 10C4E54: using guessed type int gdwVersion;

//----- (01013FB0) --------------------------------------------------------
BOOL __cdecl Init3DStatistics(unsigned __int64 *a1, unsigned __int64 *a2)
{
  HMODULE v2; // eax
  HMODULE v3; // eax
  HMODULE v4; // eax
  HDEVINFO v5; // edi
  DWORD v6; // ebx
  struct _SP_DEVICE_INTERFACE_DETAIL_DATA_W *pData; // edi
  std__list_node *v8; // ebx
  std__list_node *v9; // eax
  unsigned int v10; // edi
  _DWORD *v11; // ebx
  signed int v12; // edi
  unsigned int v13; // edx
  ULONG v14; // eax
  unsigned __int64 *v15; // ebx
  int v16; // edx
  ULONG v17; // ecx
  char v18; // al
  D3DKMT_OPENADAPTERFROMDEVICENAME DeviceName; // [esp+Ch] [ebp-68Ch]
  HDEVINFO DeviceInfoSet; // [esp+1Ch] [ebp-67Ch]
  unsigned __int64 *v22; // [esp+20h] [ebp-678h]
  unsigned int v23; // [esp+24h] [ebp-674h]
  struct _SP_DEVICE_INTERFACE_DETAIL_DATA_W *v24; // [esp+28h] [ebp-670h]
  DWORD v25; // [esp+2Ch] [ebp-66Ch]
  DWORD RequiredSize; // [esp+30h] [ebp-668h]
  char v27; // [esp+37h] [ebp-661h]
  _D3DKMT_QUERYSTATISTICS StatisticsAdapter; // [esp+38h] [ebp-660h]
  _D3DKMT_QUERYSTATISTICS StatisticsSegment; // [esp+358h] [ebp-340h]
  struct _SP_DEVICE_INTERFACE_DATA DeviceInterfaceData; // [esp+678h] [ebp-20h]

  *a2 = 0i64;
  v22 = a1;
  *a1 = 0i64;
  v2 = LoadLibraryW(L"gdi32.dll");
  D3DKMTOpenAdapterFromDeviceName = GetProcAddress(v2, "D3DKMTOpenAdapterFromDeviceName");
  v3 = LoadLibraryW(L"gdi32.dll");
  D3DKMTCloseAdapter = GetProcAddress(v3, "D3DKMTCloseAdapter");
  v4 = LoadLibraryW(L"gdi32.dll");
  D3DKMTQueryStatistics = GetProcAddress(v4, "D3DKMTQueryStatistics");
  if ( D3DKMTOpenAdapterFromDeviceName )
  {
    DeviceInterfaceData.Reserved = 0;
    v5 = SetupDiGetClassDevsW(&CLSID_GUID_DISPLAY_DEVICE_ARRIVAL, 0, 0, 0x12u);
    *&DeviceInterfaceData.InterfaceClassGuid.Data4[4] = 0i64;
    v6 = 0;
    DeviceInfoSet = v5;
    _mm_storeu_si128(&DeviceInterfaceData, 0i64);
    DeviceInterfaceData.cbSize = 28;
    v27 = 0;
    v25 = 0;
    do
    {
      if ( SetupDiEnumDeviceInterfaces(v5, 0, &CLSID_GUID_DISPLAY_DEVICE_ARRIVAL, v6, &DeviceInterfaceData) )
      {
        RequiredSize = 0;
        if ( SetupDiGetDeviceInterfaceDetailW(v5, &DeviceInterfaceData, 0, 0, &RequiredSize, 0) || GetLastError() == 122 )
        {
          pData = operator new[](RequiredSize);
          v24 = pData;
          memset(pData, 0, RequiredSize);
          pData->cbSize = 6;
          SetupDiGetDeviceInterfaceDetailW(DeviceInfoSet, &DeviceInterfaceData, pData, RequiredSize, 0, 0);
          _mm_storeu_si128(&DeviceName, 0i64);
          DeviceName.pDeviceName = pData->DevicePath;
          if ( !D3DKMTOpenAdapterFromDeviceName(&DeviceName) )
          {
            memset(&StatisticsAdapter, 0, sizeof(_D3DKMT_QUERYSTATISTICS));
            StatisticsAdapter.AdapterLuid.LowPart = DeviceName.AdapterLuid.LowPart;
            StatisticsAdapter.AdapterLuid.HighPart = DeviceName.AdapterLuid.HighPart;
            StatisticsAdapter.Type = 0;
            if ( !D3DKMTQueryStatistics(&StatisticsAdapter) )
              gdwAdapterRuntingTime += StatisticsAdapter.QueryResult.NodeInformation.GlobalInformation.RunningTime.HighPart;
            v8 = gAdapterLuidList._Mypair._Myval2._Myhead;
            v9 = sub_1013310(
                   &gAdapterLuidList._Mypair._Myval2._Myhead->_Next,
                   &gAdapterLuidList._Mypair._Myval2._Myhead->_Prev->_Next,
                   &DeviceName.AdapterLuid.LowPart);
            if ( 0xFFFFFFE - gAdapterLuidList._Mypair._Myval2._Mysize < 1 )
              std::_Xlength_error("list<T> too long");
            ++gAdapterLuidList._Mypair._Myval2._Mysize;
            v8->_Prev = v9;
            v9->_Prev->_Next = v9;
            v10 = 0;
            v23 = 0;
            if ( StatisticsAdapter.QueryResult.AdapterInformation.NbSegments )
            {
              do
              {
                memset(&StatisticsSegment, 0, sizeof(_D3DKMT_QUERYSTATISTICS));
                StatisticsSegment.AdapterLuid.LowPart = DeviceName.AdapterLuid.LowPart;
                StatisticsSegment.AdapterLuid.HighPart = DeviceName.AdapterLuid.HighPart;
                StatisticsSegment.Type = D3DKMT_QUERYSTATISTICS_SEGMENT;
                StatisticsSegment.QuerySegment.SegmentId = v10;
                if ( !D3DKMTQueryStatistics(&StatisticsSegment) )
                {
                  if ( gdwVersion < 3 )
                  {
                    v14 = StatisticsSegment.QueryResult.AdapterInformation.NbSegments >> 10;
                    if ( StatisticsSegment.QueryResult.SegmentInformationV1.Aperture )
                    {
                      v15 = v22;
                      v16 = *(v22 + 1);
                      v17 = *v22;
                      if ( v16 < 0 || v16 <= 0 && v17 <= v14 )
                      {
                        v17 = StatisticsSegment.QueryResult.AdapterInformation.NbSegments >> 10;
                        v16 = 0;
                      }
                      *v22 = v17;
                      *(v15 + 1) = v16;
                    }
                    else
                    {
                      *a2 += v14;
                    }
                  }
                  else if ( StatisticsSegment.QueryResult.AdapterInformation.ReferenceDmaBuffer.NbCall )
                  {
                    v11 = v22;
                    v12 = *(v22 + 1);
                    v13 = *v22;
                    if ( v12 < (StatisticsSegment.QueryResult.AdapterInformation.NodeCount >> 10)
                      || v12 <= (StatisticsSegment.QueryResult.AdapterInformation.NodeCount >> 10)
                      && v13 <= (StatisticsSegment.QueryResult.SegmentInformation.CommitLimit >> 10) )
                    {
                      v13 = StatisticsSegment.QueryResult.SegmentInformation.CommitLimit >> 10;
                      v12 = StatisticsSegment.QueryResult.AdapterInformation.NodeCount >> 10;
                    }
                    *(v22 + 1) = v12;
                    v10 = v23;
                    *v11 = v13;
                  }
                  else
                  {
                    *a2 += StatisticsSegment.QueryResult.SegmentInformation.CommitLimit >> 10;
                  }
                }
                v23 = ++v10;
              }
              while ( v10 < StatisticsAdapter.QueryResult.AdapterInformation.NbSegments );
            }
            pData = v24;
            v6 = v25;
          }
          j_j__free(pData);
          v5 = DeviceInfoSet;
        }
        v18 = v27;
      }
      else
      {
        v18 = 1;
        v27 = 1;
      }
      v25 = ++v6;
    }
    while ( !v18 );
    SetupDiDestroyDeviceInfoList(v5);
  }
  return gdwAdapterRuntingTime != 0;
}
// 10C4E38: using guessed type int D3DKMTCloseAdapter;
// 10C4E54: using guessed type int gdwVersion;

//----- (01014360) --------------------------------------------------------
_DWORD *__stdcall sub_1014360(_DWORD *a1, _DWORD *a2)
{
  _DWORD *result; // eax
  _DWORD *v3; // ecx
  _DWORD *v4; // edx

  result = operator new(0x10u);
  if ( !result )
    std::_Xbad_alloc();
  v3 = a1;
  if ( a1 )
  {
    v4 = a2;
  }
  else
  {
    v3 = result;
    v4 = result;
  }
  *result = v3;
  if ( result != -4 )
    result[1] = v4;
  return result;
}

//----- (010143A0) --------------------------------------------------------
CGraphData *__thiscall GraphInfo_Init(tagGraphInfo *pThis)
{
  tagGraphInfo *this; // esi
  CGraphData *pGraphData; // eax
  UINT v3; // ecx
  CGraphData *result; // eax

  this = pThis;
  pGraphData = InitGraphData(1, 2, 1);
  v3 = this->nItemID;
  this->pGraphData = pGraphData;
  pGraphData->m_nItemID = v3;
  this->pGraphData->m_dbMemorySize = db_onehundred;
  this->pGraphData->m_Buffer2 = 1;
  this->pGraphData->m_Color = 0xC83C1E;
  this->pGraphData->m_Item[0].nItemID = this->nItemID;
  this->pGraphData->m_Item[0].dbMemorySize = db_onehundred;
  result = this->pGraphData;
  result->m_Item[0].Color = 0xC83CC8;
  return result;
}
// 109CDC0: using guessed type double db_onehundred;

//----- (01014400) --------------------------------------------------------
signed __int64 __thiscall GraphInfo_Refresh(tagGraphInfo *pGrahInfo_1)
{
  int nIndex; // edx
  tagGraphInfo *pGrahInfo; // esi
  int i; // ecx
  CGraphData *pGraphData; // edi
  double v5; // xmm0_8
  signed int nChild; // edx
  signed int v7; // ecx
  signed __int64 result; // rax

  nIndex = 0;
  pGrahInfo = pGrahInfo_1;
  pGrahInfo_1->pGraphData->m_dbMemorySize = db_one;
  for ( i = gdwVirtualScreenWidth; nIndex < i; ++nIndex )
  {
    pGraphData = pGrahInfo->pGraphData;
    v5 = pGraphData->m_Item[0].pBuffer[nIndex];
    if ( v5 > pGraphData->m_dbMemorySize )
    {
      pGraphData->m_dbMemorySize = v5 * 1.200000047683716;
      i = gdwVirtualScreenWidth;
    }
  }
  nChild = 1;
  if ( pGrahInfo->pGraphData->m_nChildID > 1 )
  {
    v7 = 0x18;
    do
    {
      v7 += sizeof(tagGraphItem);
      ++nChild;
      *(&pGrahInfo->pGraphData->m_Lock.m_Lock.LockSemaphore + v7) = pGrahInfo->pGraphData->m_dbMemorySize;
    }
    while ( nChild < pGrahInfo->pGraphData->m_nChildID );
  }
  result = pGrahInfo->pGraphData->m_dbMemorySize;
  pGrahInfo->dbMemorySize = result;
  return result;
}
// 10C4E28: using guessed type int gdwVirtualScreenWidth;

//----- (010144A0) --------------------------------------------------------
void __thiscall sub_10144A0(tagGraphInfo *this, TreeList_Item1 *pItem)
{
  tagGraphInfo *pGraphInfo; // edi
  int v3; // esi
  __int64 v4; // kr10_8
  signed __int64 v5; // kr20_8
  float v6; // xmm0_4
  int v7; // eax
  float v8; // xmm0_4
  float v9; // xmm0_4
  __int64 dbValue3; // ST1C_8
  float v11; // xmm0_4
  float v12; // xmm0_4
  __int64 v13; // ST1C_8
  float v14; // xmm0_4
  __int64 a5; // ST14_8
  float v16; // xmm0_4
  float v17; // xmm0_4
  __int64 v18; // ST1C_8
  float v19; // xmm0_4
  __int64 v20; // ST14_8
  float v21; // xmm0_4
  WCHAR szBuffer[1024]; // [esp+30h] [ebp-804h]

  szBuffer[0] = 0;
  pGraphInfo = this;
  memset(&szBuffer[1], 0, 2046u);
  if ( *&pItem->field_58 + *&pItem->field_50 + *&pItem->field_48 )
  {
    v3 = wsprintfW(szBuffer, L"%s:%d\n", *(pItem->field_60 + 60), *(pItem->field_60 + 68));
    PE_FormatDouble(1, &szBuffer[v3], 1024 - v3, *&pItem->field_50, *&pItem->field_48, *&pItem->field_58);
    v4 = *&pItem->field_58 + *&pItem->field_50 + *&pItem->field_48;
    if ( v4 > pGraphInfo->dbMemorySize )
      pGraphInfo->dbMemorySize = v4;
  }
  v5 = *&pItem->field_20 + *&pItem->field_18 + *&pItem->field_28;
  if ( v5 >= pGraphInfo->pGraphData->m_dbMemorySize )
  {
    v6 = v5;
    pGraphInfo->pGraphData->m_dbMemorySize = (v6 * 1.2);
    pGraphInfo->pGraphData->m_Item[0].dbMemorySize = pGraphInfo->pGraphData->m_dbMemorySize;
  }
  v7 = HIDWORD(pGraphInfo->dbMemorySize) | LODWORD(pGraphInfo->dbMemorySize);
  if ( !pGraphInfo->dbMemorySize )
  {
    LODWORD(pGraphInfo->dbMemorySize) = 1;
    HIDWORD(pGraphInfo->dbMemorySize) = v7;
  }
  v8 = pGraphInfo->dbMemorySize;
  pGraphInfo->pGraphData->m_dbMemorySize = v8;
  pGraphInfo->pGraphData->m_Item[0].dbMemorySize = pGraphInfo->pGraphData->m_dbMemorySize;
  CGraphData_Update(
    pGraphInfo->pGraphData,
    gTimeQuerySystemInfo,
    (*&pItem->field_20 + *&pItem->field_18 + *&pItem->field_28),
    *&pItem->field_18,
    szBuffer);
  if ( pGraphInfo == &gIOGraphInfo )
  {
    v9 = *&pItem->field_28;
    *&dbValue3 = v9;
    v11 = *&pItem->field_20;
    sub_1060130(pGraphInfo->pGraphData, pItem->field_60, COERCE__INT64(*&pItem->field_18), *&v11, dbValue3);
  }
  else if ( pGraphInfo == &gDiskGraphInfo )
  {
    v12 = *&pItem->field_28;
    *&v13 = v12;
    v14 = *&pItem->field_20;
    *&a5 = v14;
    v16 = *&pItem->field_18;
    sub_1060010(pGraphInfo->pGraphData, pItem->field_60, *&v16, a5, v13);
  }
  else if ( pGraphInfo == &gNetworkGraphInfo )
  {
    v17 = *&pItem->field_28;
    *&v18 = v17;
    v19 = *&pItem->field_20;
    *&v20 = v19;
    v21 = *&pItem->field_18;
    sub_1060250(pGraphInfo->pGraphData, pItem->field_60, *&v21, v20, v18);
  }
}

//----- (010147C0) --------------------------------------------------------
int __stdcall sub_10147C0(int a1, TreeList_Item1 *a2)
{
  TreeList_Item1 *v2; // ecx
  TreeList_Item1 *v3; // edx
  int v4; // eax
  unsigned __int8 v5; // cf
  int v6; // eax
  int v7; // eax
  int result; // eax
  int v9; // [esp+Ch] [ebp-4h]

  v3 = v2;
  v3->field_4 += a2->field_10;
  v3->field_0 += a2->field_30;
  v3->field_8 += a2->field_50;
  v4 = a2->field_38;
  v5 = __CFADD__(v4, v2->field_18);
  v3->field_18 += v4;
  v3->field_1C += a2->field_3C + v5;
  v6 = a2->field_18;
  v5 = __CFADD__(v6, v2->field_20);
  v3->field_20 += v6;
  v3->field_24 += a2->field_1C + v5;
  v7 = *&a2->field_58;
  v5 = __CFADD__(v7, v2->field_28);
  v3->field_28 += v7;
  v3->field_2C += *(&a2->field_59 + 3) + v5;
  v9 = a2->field_3C;
  result = (*&v3->field_48 + *&v3->field_58 + *&v3->field_50) >> 32;
  if ( *&a2->field_38 + *&a2->field_58 + *&a2->field_18 > *&v3->field_48 + *&v3->field_58 + *&v3->field_50 )
  {
    v2->field_48 = a2->field_38;
    v2->field_4C = v9;
    v2->field_50 = a2->field_18;
    v2->field_54 = a2->field_1C;
    *&v2->field_58 = *&a2->field_58;
    *(&v2->field_59 + 3) = *(&a2->field_59 + 3);
    result = a1;
    v2->field_60 = a1;
  }
  return result;
}

//----- (01014870) --------------------------------------------------------
int __cdecl CMainWnd::Create(HINSTANCE hInstance, int nCmdShow)
{
  HANDLE v2; // eax
  int v3; // ST28_4
  int v4; // eax
  HWND hMainWnd; // esi
  HWND v7; // eax
  UINT showCmd; // eax
  int v9; // edi
  int v10; // edx
  LONG v11; // ecx
  LONG v12; // eax
  LONG v13; // ecx
  UINT v14; // eax
  int v15; // eax
  char v16; // cl
  WNDCLASSEXW wc; // [esp+8h] [ebp-30h]

  LoadStringW(hInstance, IDS_MAINCLASSNAME, &gszMainClassName, 9);
  LoadStringW(hInstance, IDS_MAINWINDOWNAME, &gszMainWindowName, 40);
  ghInstance = hInstance;
  InitDrawEngine();
  if ( gConfig.bAllOneInstance )
  {
    v2 = OpenEventW(SYNCHRONIZE, 0, L"ProcessExplorerElevating");
    if ( v2 )
    {
      CloseHandle(v2);
    }
    else
    {
      v7 = FindWindowW(&gszMainClassName, 0);
      if ( v7 )
      {
        PostMessageW(v7, WM_MSG_7F2, 0, 0);
        return 0;
      }
    }
  }
  if ( !OnBeforeInit() )
    return 0;
  ghWaitCursor = LoadCursorW(0, IDC_WAIT);
  wc.cbSize = 48;
  wc.style = 0;
  wc.lpfnWndProc = CMainWnd::MainWndProc;
  wc.cbClsExtra = 0;
  wc.cbWndExtra = 0;
  wc.hInstance = hInstance;
  wc.hIcon = LoadIconW(hInstance, 0x65);
  wc.hCursor = 0;
  wc.hbrBackground = 0;
  wc.lpszMenuName = L"PROCEXPLORER";
  wc.lpszClassName = &gszMainClassName;
  v3 = GetSystemMetrics(50);
  v4 = GetSystemMetrics(49);
  wc.hIconSm = LoadImageW(hInstance, 0x65, 1u, v4, v3, 0);
  if ( !RegisterClassExW(&wc) && !RegisterClassW(&wc.style) )
    return 0;
  memset(&wc, 0, sizeof(WNDCLASSEXW));
  wc.cbSize = sizeof(WNDCLASSEXW);
  wc.lpfnWndProc = CGraphWnd::ChartWndProc;
  wc.hInstance = ghInstance;
  wc.hbrBackground = CreateSolidBrush(0xFFFFFFu);
  wc.lpszClassName = L"CpuGraphClassChart";
  wc.hCursor = LoadCursorW(0, IDC_ARROW);
  RegisterClassExW(&wc);
  memset(&wc, 0, sizeof(WNDCLASSEXW));
  wc.cbSize = sizeof(WNDCLASSEXW);
  wc.lpfnWndProc = CGraphWnd::ChartWndProc;
  wc.hInstance = ghInstance;
  wc.hbrBackground = CreateSolidBrush(gConfig.ColorGraphBk);
  wc.lpszClassName = L"CpuGraphClassGraph";
  wc.hCursor = LoadCursorW(0, IDC_ARROW);
  RegisterClassExW(&wc);
  hMainWnd = CreateWindowExW(
               0,
               &gszMainClassName,
               L"Process Explorer - Sysinternals: www.sysinternals.com",
               0xCF0000u,
               0,
               0,
               780,
               550,
               0,
               0,
               hInstance,
               0);
  if ( !hMainWnd )
    return 0;
  if ( gConfig.WindowPlacement[0].length )
  {
    showCmd = gConfig.WindowPlacement[0].showCmd;
    if ( gConfig.WindowPlacement[0].showCmd == SW_MINIMIZE )
      showCmd = 1;
    if ( gbHide )
      showCmd = 0;
    gConfig.WindowPlacement[0].showCmd = showCmd;
    v9 = GetSystemMetrics(SM_CXVIRTUALSCREEN);
    if ( !v9 )
      v9 = GetSystemMetrics(SM_CXFULLSCREEN);
    v10 = GetSystemMetrics(SM_CYVIRTUALSCREEN);
    if ( !v10 )
      v10 = GetSystemMetrics(SM_CYFULLSCREEN);
    v11 = gConfig.WindowPlacement[0].rcNormalPosition.left;
    v12 = gConfig.WindowPlacement[0].rcNormalPosition.right;
    if ( gConfig.WindowPlacement[0].rcNormalPosition.left >= v9 - 10 )
      v11 = 100;
    gConfig.WindowPlacement[0].rcNormalPosition.left = v11;
    v13 = gConfig.WindowPlacement[0].rcNormalPosition.top;
    if ( gConfig.WindowPlacement[0].rcNormalPosition.right > v9 )
      v12 = v9;
    gConfig.WindowPlacement[0].rcNormalPosition.right = v12;
    if ( gConfig.WindowPlacement[0].rcNormalPosition.top >= v10 - 10 )
      v13 = 100;
    gConfig.WindowPlacement[0].rcNormalPosition.top = v13;
    if ( nCmdShow == SW_SHOWMINNOACTIVE )
    {
      v14 = gConfig.WindowPlacement[0].showCmd;
      if ( gConfig.bHideWhenMinimized )
        v14 = 0;
      gConfig.WindowPlacement[0].showCmd = v14;
    }
    SetWindowPlacement(hMainWnd, gConfig.WindowPlacement);
  }
  else
  {
    v15 = 5;
    if ( gbHide )
      v15 = 0;
    ShowWindow(hMainWnd, v15);
  }
  v16 = gbMainWndMinimized;
  if ( gbHide )
    v16 = 1;
  gbMainWndMinimized = v16;
  UpdateWindow(hMainWnd);
  return 1;
}
// 109CB88: using guessed type wchar_t aCpugraphclassc[19];
// 10CA388: using guessed type char gbHide;
// 10CA389: using guessed type char gbMainWndMinimized;

//----- (01014B90) --------------------------------------------------------
int wsprintf(wchar_t *Dst, wchar_t *Format, ...)
{
  va_list ArgList; // [esp+10h] [ebp+10h]

  va_start(ArgList, Format);
  return vswprintf_s(Dst, 0x100u, Format, ArgList);
}

//----- (01014BB0) --------------------------------------------------------
int MakeHandlePropSheetCaption(wchar_t *Dst, wchar_t *Format, ...)
{
  va_list ArgList; // [esp+10h] [ebp+10h]

  va_start(ArgList, Format);
  return vswprintf_s(Dst, 0x208u, Format, ArgList);
}

//----- (01014BD0) --------------------------------------------------------
CString *__thiscall sub_1014BD0(CString *this, LPCSTR lpMultiByteStr)
{
  CString *v2; // esi
  IAtlStringMgr *v3; // ecx
  CHAR *v4; // eax

  v2 = this;
  v3 = ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>::GetDefaultManager();
  if ( !v3 )
    ATL::AtlThrowImpl(E_FAIL);
  v2->pszData = ((v3->vtptr->GetNilData)() + 16);
  if ( !lpMultiByteStr || lpMultiByteStr & 0xFFFF0000 )
  {
    ATL::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>::operator=(v2, lpMultiByteStr);
  }
  else
  {
    v4 = ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>::FindStringResourceInstance(lpMultiByteStr, 0);
    if ( v4 )
      ATL::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>::LoadStringW(v2, v4, lpMultiByteStr);
  }
  return v2;
}

//----- (01014C70) --------------------------------------------------------
CString *__thiscall ATL::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>::operator=(CString *this, LPCSTR lpMultiByteStr)
{
  CString *v2; // edi
  int v3; // esi
  CString *result; // eax

  v2 = this;
  if ( lpMultiByteStr && (v3 = MultiByteToWideChar(3u, 0, lpMultiByteStr, -1, 0, 0) - 1, v3 > 0) )
  {
    if ( ((*(v2->pszData - 2) - v3) | (1 - *(v2->pszData - 1))) < 0 )
      ATL::CSimpleStringT<wchar_t,0>::PrepareWrite2(v2, v3);
    MultiByteToWideChar(3u, 0, lpMultiByteStr, -1, v2->pszData, v3);
    if ( v3 > *(v2->pszData - 2) )
      ATL::AtlThrowImpl(E_INVALIDARG);
    *(v2->pszData - 3) = v3;
    *&v2->pszData[2 * v3] = 0;
    result = v2;
  }
  else
  {
    ATL::CSimpleStringT<wchar_t,0>::Empty(v2);
    result = v2;
  }
  return result;
}

//----- (01014D00) --------------------------------------------------------
int __stdcall PE_AutoAppendPostfix(HDC hDC, WCHAR *pszText, DWORD dwLength, LONG nWidth)
{
  HANDLE v4; // eax
  wchar_t *pBuffer; // eax
  unsigned __int16 *pszBuffer; // edi
  int nLen; // esi
  HANDLE v8; // eax
  unsigned int v10; // ecx
  DWORD nBytesToCopy; // esi
  HANDLE v12; // eax
  struct tagSIZE size3; // [esp+Ch] [ebp-20h]
  struct tagSIZE size2; // [esp+14h] [ebp-18h]
  struct tagSIZE size1; // [esp+1Ch] [ebp-10h]
  struct tagSIZE size; // [esp+24h] [ebp-8h]
  unsigned int nWidtha; // [esp+40h] [ebp+14h]

  nWidtha = nWidth - 4;
  v4 = GetProcessHeap();
  pBuffer = HeapAlloc(v4, 8u, 2 * dwLength);
  pszBuffer = pBuffer;
  if ( !pBuffer )
    return 0;
  wcscpy_s(pBuffer, dwLength, pszText);
  nLen = wcslen(pszBuffer);
  if ( !GetTextExtentPoint32W(hDC, pszBuffer, nLen, &size) )
  {
LABEL_3:
    v8 = GetProcessHeap();
    HeapFree(v8, 0, pszBuffer);
    return 0;
  }
  if ( size.cx > nWidtha )
  {
    if ( !GetTextExtentPoint32W(hDC, L"...", wcslen(L"..."), &size1)
      || !GetTextExtentPoint32W(hDC, L"..", wcslen(L".."), &size2)
      || !GetTextExtentPoint32W(hDC, L".", wcslen(L"."), &size3) )
    {
      goto LABEL_3;
    }
    if ( nLen > 0 )
    {
      while ( 1 )
      {
        pszBuffer[--nLen] = 0;
        if ( !GetTextExtentPoint32W(hDC, pszBuffer, nLen, &size) )
          goto LABEL_3;
        v10 = nWidtha;
        if ( size.cx + size1.cx <= nWidtha || nLen <= 0 )
          goto LABEL_15;
      }
    }
    v10 = nWidtha;
LABEL_15:
    *pszBuffer = *pszText;
    if ( size.cx + size1.cx > v10 )
    {
      if ( size.cx + size2.cx > v10 )
      {
        if ( size.cx + size3.cx > v10 )
        {
          nBytesToCopy = dwLength;
          *pszBuffer = *pszText;
        }
        else
        {
          nBytesToCopy = dwLength;
          wcscat_s(pszBuffer, dwLength, L".");
        }
      }
      else
      {
        nBytesToCopy = dwLength;
        wcscat_s(pszBuffer, dwLength, L"..");
      }
    }
    else
    {
      nBytesToCopy = dwLength;
      wcscat_s(pszBuffer, dwLength, L"...");
    }
    wcscpy_s(pszText, nBytesToCopy, pszBuffer);
  }
  v12 = GetProcessHeap();
  HeapFree(v12, 0, pszBuffer);
  return 1;
}

//----- (01014EF0) --------------------------------------------------------
signed int __cdecl sub_1014EF0(unsigned int *a1, _DWORD *a2)
{
  unsigned int v2; // ecx
  unsigned int v3; // edx
  signed int result; // eax
  __int64 v5; // rdi
  bool v6; // zf
  bool v7; // sf
  unsigned __int8 v8; // of

  v2 = *a1;
  v3 = a1[1];
  if ( *a1 )
  {
    HIDWORD(v5) = *a2;
    LODWORD(v5) = a2[1];
    if ( !v5 )
      return 1;
    if ( HIDWORD(v5) == v2 )
    {
      v8 = __OFSUB__(v3, v5);
      v6 = v3 == v5;
      v7 = (v3 - v5) < 0;
      if ( v3 == v5 )
        return 0;
    }
    else
    {
      v8 = __OFSUB__(v3, v5);
      v6 = v3 == v5;
      v7 = (v3 - v5) < 0;
    }
    if ( !(v7 ^ v8) && (!((v7 ^ v8) | v6) || v2 > HIDWORD(v5)) )
      return 1;
    result = -1;
  }
  else if ( *a2 )
  {
    result = -1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (01014F50) --------------------------------------------------------
char __cdecl sub_1014F50(CRegSettings *pConfig, DWORD *pdwValue, unsigned int a3)
{
  DWORD *pdwValue_1; // edx
  CRegSettings *v4; // ebx
  DWORD *v5; // esi
  CRegSettings *v6; // eoff
  volatile signed __int32 *v7; // eax
  const void *v8; // esi
  signed int v9; // ecx
  unsigned int v10; // esi
  const wchar_t **v11; // eax
  bool *v12; // edx
  const wchar_t **v13; // eax
  bool *v14; // edx
  DWORD *v15; // ecx

  pdwValue_1 = pdwValue;
  v4 = pConfig;
  v5 = pdwValue + 12;
  v6 = pConfig;
  _mm_storeu_si128(pConfig, _mm_loadu_si128((pdwValue + 1)));
  _mm_storeu_si128(&v4->WindowPlacement[0].ptMinPosition.y, _mm_loadu_si128((pdwValue_1 + 5)));
  _mm_storel_epi64(&v4->WindowPlacement[0].rcNormalPosition.top, _mm_loadl_epi64((pdwValue_1 + 9)));
  v7 = pdwValue_1[11];
  v4->WindowPlacement[0].rcNormalPosition.bottom = v7;
  qmemcpy(&v6->UnicodeFont, v5, sizeof(v6->UnicodeFont));
  v8 = pdwValue_1 + 97;
  v4->dbDivider = *(pdwValue_1 + 18);
  _mm_storeu_si128(v4->dwProcessColumns, _mm_loadu_si128((pdwValue_1 + 38)));
  _mm_storeu_si128(&v4->dwProcessColumns[8], _mm_loadu_si128((pdwValue_1 + 42)));
  _mm_storeu_si128(&v4->dwProcessColumns[16], _mm_loadu_si128((pdwValue_1 + 46)));
  _mm_storeu_si128(&v4->dwProcessColumns[24], _mm_loadu_si128((pdwValue_1 + 50)));
  _mm_storeu_si128(v4->dwHandleColumns, _mm_loadu_si128((pdwValue_1 + 54)));
  _mm_storeu_si128(&v4->dwHandleColumns[8], _mm_loadu_si128((pdwValue_1 + 58)));
  _mm_storeu_si128(&v4->dwHandleColumns[16], _mm_loadu_si128((pdwValue_1 + 62)));
  _mm_storeu_si128(&v4->dwHandleColumns[24], _mm_loadu_si128((pdwValue_1 + 66)));
  _mm_storeu_si128(v4->dwDllColumns, _mm_loadu_si128((pdwValue_1 + 70)));
  _mm_storeu_si128(&v4->dwDllColumns[8], _mm_loadu_si128((pdwValue_1 + 74)));
  _mm_storeu_si128(&v4->dwDllColumns[16], _mm_loadu_si128((pdwValue_1 + 78)));
  _mm_storeu_si128(&v4->dwDllColumns[24], _mm_loadu_si128((pdwValue_1 + 82)));
  if ( pdwValue_1[97] )
  {
    v9 = 32;
  }
  else
  {
    v8 = pdwValue_1 + 0x176;
    v9 = 64;
  }
  qmemcpy(v4->dwProcessColumnMap, v8, 4 * v9);
  qmemcpy(v4->dwDllColumnMap, pdwValue_1 + 130, sizeof(v4->dwDllColumnMap));
  qmemcpy(v4->dwIdsOfHandleColumnMap, pdwValue_1 + 163, sizeof(v4->dwIdsOfHandleColumnMap));
  v10 = a3;
  if ( a3 > 0x158 )
  {
    LOBYTE(v7) = *(pdwValue_1 + 344);
    v4->bShowUnnamedHandles = v7;
  }
  if ( v10 > 0x15C )
  {
    LOBYTE(v7) = *(pdwValue_1 + 348);
    v4->bShowDllView = v7;
  }
  if ( v10 > 0x160 )
  {
    v7 = pdwValue_1[88];
    v4->dwHandleSortColumn = v7;
  }
  if ( v10 > 0x164 )
  {
    LOBYTE(v7) = *(pdwValue_1 + 356);
    LOBYTE(v4->bHandleSortDirection) = v7;
  }
  if ( v10 > 0x168 )
  {
    v7 = pdwValue_1[90];
    v4->dwDllSortColumn = v7;
  }
  if ( v10 > 0x16C )
  {
    LOBYTE(v7) = *(pdwValue_1 + 364);
    LOBYTE(v4->bDllSortDirection) = v7;
  }
  if ( v10 > 0x170 )
  {
    v7 = pdwValue_1[92];
    v4->dwProcessSortColumn = v7;
  }
  if ( v10 > 0x174 )
  {
    LOBYTE(v7) = *(pdwValue_1 + 372);
    v4->bProcessSortDirection = v7;
  }
  if ( v10 > 0x175 )
  {
    LOBYTE(v7) = *(pdwValue_1 + 373);
    v4->bHighlightServices = v7;
  }
  if ( v10 > 0x176 )
  {
    LOBYTE(v7) = *(pdwValue_1 + 374);
    v4->bHighlightOwnProcesses = v7;
  }
  if ( v10 > 0x178 )
  {
    LOBYTE(v7) = *(pdwValue_1 + 376);
    v4->bHighlightRelocatedDlls = v7;
  }
  if ( v10 > 0x17C )
  {
    v7 = pdwValue_1[95];
    v4->dwRefreshRate = v7;
  }
  if ( v10 > 0x180 )
  {
    v7 = pdwValue_1[96];
    v4->dwProcessColumnCount = v7;
  }
  if ( v10 > 0x204 )
  {
    v7 = pdwValue_1[129];
    v4->dwDllColumnCount = v7;
  }
  if ( v10 > 0x288 )
  {
    v7 = pdwValue_1[162];
    v4->dwHandleColumnCount = v7;
  }
  if ( v10 > 0x30C )
  {
    LOBYTE(v7) = *(pdwValue_1 + 780);
    v4->bHighlightJobs = v7;
  }
  if ( v10 > 0x30D )
  {
    LOBYTE(v7) = *(pdwValue_1 + 781);
    v4->bShowCpuFractions = v7;
  }
  if ( v10 > 0x310 )
    v4->dbSavedDivider = *(pdwValue_1 + 98);
  if ( v10 > 0x318 )
  {
    LOBYTE(v7) = *(pdwValue_1 + 792);
    v4->bShowLowerPane = v7;
  }
  if ( v10 > 0x319 )
  {
    LOBYTE(v7) = *(pdwValue_1 + 793);
    v4->bShowAllUsers = v7;
  }
  if ( v10 > 0x41E )
  {
    LOBYTE(v7) = *(pdwValue_1 + 1054);
    LOBYTE(v4->bSymbolWarningShown) = v7;
  }
  if ( v10 > 0x523 )
  {
    LOBYTE(v7) = *(pdwValue_1 + 1315);
    v4->bHighliteNetProcess = v7;
  }
  if ( v10 > 0x524 )
  {
    LOBYTE(v7) = *(pdwValue_1 + 1316);
    v4->byReserved_00 = v7;
  }
  if ( v10 > 0x525 )
  {
    LOBYTE(v7) = *(pdwValue_1 + 1317);
    v4->bHideWhenMinimized = v7;
  }
  if ( v10 > 0x554 )
  {
    v7 = pdwValue_1[341];
    v4->ColorOwn = v7;
  }
  if ( v10 > 0x568 )
  {
    v7 = pdwValue_1[346];
    v4->ColorProtected = v7;
  }
  if ( v10 > 0x558 )
  {
    v7 = pdwValue_1[342];
    v4->ColorService = v7;
  }
  if ( v10 > 0x55C )
  {
    v7 = pdwValue_1[343];
    v4->ColorRelocatedDlls = v7;
  }
  if ( v10 > 0x560 )
  {
    v7 = pdwValue_1[344];
    v4->ColorJobs = v7;
  }
  if ( v10 > 0x564 )
  {
    v7 = pdwValue_1[345];
    v4->ColorNet = v7;
  }
  if ( v10 > 0x56C )
  {
    v7 = pdwValue_1[347];
    v4->dwHighlightDuration = v7;
  }
  if ( v10 > 0x570 )
  {
    LOBYTE(v7) = *(pdwValue_1 + 1392);
    v4->bAlwaysOntop = v7;
  }
  if ( v10 > 0x571 )
  {
    LOBYTE(v7) = *(pdwValue_1 + 1393);
    v4->bShowProcessTree = v7;
  }
  if ( v10 > 0x574 )
  {
    v7 = pdwValue_1[349];
    v4->dwStatusBarColumns = v7;
  }
  if ( v10 > 0x578 )
  {
    v7 = pdwValue_1[350];
    v4->dwOpacity = v7;
  }
  if ( v10 > 0x5D4 )
  {
    LOBYTE(v7) = *(pdwValue_1 + 1492);
    v4->bConfirmKill = v7;
  }
  if ( v10 > 0x6D8 )
  {
    v7 = pdwValue_1[438];
    v4->dwDefaultProcPropPage = v7;
  }
  if ( v10 > 0x6F4 )
  {
    LOBYTE(v7) = *(pdwValue_1 + 1780);
    v4->bVerifySignatures = v7;
  }
  if ( v10 > 0x6F5 )
  {
    LOBYTE(v7) = *(pdwValue_1 + 1781);
    v4->bShowAllCpus = v7;
  }
  if ( v10 > 0x31A )
  {
    v11 = sub_1014BD0(&pConfig, pdwValue_1 + 794);
    wcscpy_s(v4->strDbgHelpModuleName, 0x104u, *v11);
    v12 = &pConfig[-1].ToolBandInfo[6].fBreak;
    v7 = &pConfig[-1].ToolBandInfo[7].fBreak;
    if ( _InterlockedDecrement(v7) <= 0 )
      LOBYTE(v7) = (*(**v12 + 4))(v12);
    pdwValue_1 = pdwValue;
  }
  if ( v10 > 0x41F )
  {
    v13 = sub_1014BD0(&pConfig, pdwValue_1 + 0x41F);
    wcscpy_s(v4->strNtSymbolPath, 0x104u, *v13);
    v14 = &pConfig[-1].ToolBandInfo[6].fBreak;
    v7 = &pConfig[-1].ToolBandInfo[7].fBreak;
    if ( _InterlockedDecrement(v7) <= 0 )
      LOBYTE(v7) = (*(**v14 + 4))(v14);
  }
  v15 = pdwValue;
  if ( v10 > 0x528 )
  {
    _mm_storeu_si128(&v4->WindowPlacement[1], _mm_loadu_si128((pdwValue + 330)));
    _mm_storeu_si128(&v4->WindowPlacement[1].ptMinPosition.y, _mm_loadu_si128((v15 + 334)));
    _mm_storel_epi64(&v4->WindowPlacement[1].rcNormalPosition.top, _mm_loadl_epi64((v15 + 338)));
    v7 = v15[340];
    v4->WindowPlacement[1].rcNormalPosition.bottom = v7;
  }
  if ( v10 > 0x57C )
  {
    _mm_storeu_si128(&v4->WindowPlacement[2], _mm_loadu_si128((v15 + 351)));
    _mm_storeu_si128(&v4->WindowPlacement[2].ptMinPosition.y, _mm_loadu_si128((v15 + 355)));
    _mm_storel_epi64(&v4->WindowPlacement[2].rcNormalPosition.top, _mm_loadl_epi64((v15 + 359)));
    v7 = v15[361];
    v4->WindowPlacement[2].rcNormalPosition.bottom = v7;
  }
  if ( v10 > 0x5A8 )
  {
    _mm_storeu_si128(&v4->WindowPlacement[4], _mm_loadu_si128((v15 + 362)));
    _mm_storeu_si128(&v4->WindowPlacement[4].ptMinPosition.y, _mm_loadu_si128((v15 + 366)));
    _mm_storel_epi64(&v4->WindowPlacement[4].rcNormalPosition.top, _mm_loadl_epi64((v15 + 370)));
    v7 = v15[372];
    v4->WindowPlacement[4].rcNormalPosition.bottom = v7;
  }
  if ( v10 > 0x6DC )
  {
    _mm_storel_epi64(v4->ToolBandInfo, _mm_loadl_epi64((v15 + 439)));
    v7 = v15[441];
    *&v4->ToolBandInfo[0].fBreak = v7;
  }
  if ( v10 > 0x6E8 )
  {
    _mm_storel_epi64(&v4->ToolBandInfo[1], _mm_loadl_epi64((v15 + 442)));
    v7 = v15[444];
    *&v4->ToolBandInfo[1].fBreak = v7;
  }
  if ( v10 > 0x6F4 )
  {
    _mm_storel_epi64(&v4->ToolBandInfo[1], _mm_loadl_epi64((v15 + 445)));
    v7 = v15[447];
    *&v4->ToolBandInfo[1].fBreak = v7;
  }
  if ( v10 > 0x700 )
  {
    _mm_storel_epi64(&v4->ToolBandInfo[1], _mm_loadl_epi64(v15 + 112));
    v7 = v15[450];
    *&v4->ToolBandInfo[1].fBreak = v7;
  }
  if ( v10 > 0x70C )
  {
    _mm_storel_epi64(&v4->ToolBandInfo[1], _mm_loadl_epi64((v15 + 451)));
    v7 = v15[453];
    *&v4->ToolBandInfo[1].fBreak = v7;
  }
  return v7;
}

//----- (010155D0) --------------------------------------------------------
BOOL __stdcall PE_DrawText(HDC hDC, LPCWSTR lpszText, RECT *lprc, BOOL fAlignRight)
{
  signed int v4; // ecx
  int v5; // esi
  int v6; // eax
  __int16 String[8192]; // [esp+Ch] [ebp-4004h]

  if ( wcslen(lpszText) > 8191 )
  {
    wcsncpy_s(String, 0x2000u, lpszText, 0xFFFFFFFF);
    __report_rangecheckfailure();
    __debugbreak();
    JUMPOUT(*sub_10156D0);
  }
  wcscpy_s(String, 0x2000u, lpszText);
  v4 = 2;
  if ( fAlignRight )
    v4 = 8;
  PE_AutoAppendPostfix(hDC, String, 0x2000u, lprc->right - v4 - lprc->left);
  if ( fAlignRight )
  {
    SetTextAlign(hDC, TA_RIGHT);
    v5 = lprc->right - 10;
  }
  else
  {
    SetTextAlign(hDC, 0);
    v5 = lprc->left + 2;
  }
  v6 = lstrlenW(String);
  return ExtTextOutW(hDC, v5, lprc->top + 1, 6u, lprc, String, v6, 0);
}
// 10667E8: using guessed type int __report_rangecheckfailure(void);

//----- (010156D0) --------------------------------------------------------
char __cdecl sub_10156D0(char a1, tagTREEVIEWLISTITEMPARAM *pTreeItem, WORD uID, HDC hDC, RECT *lprc)
{
  int nID; // esi
  HBRUSH v6; // eax
  RECT *rc; // esi
  HDC hdc; // ebx
  HBRUSH v10; // eax
  RECT *v11; // esi
  HDC v12; // ebx
  HBRUSH v13; // eax
  RECT *v14; // ebx
  float v15; // xmm0_4
  HBRUSH v16; // eax
  RECT *v17; // esi
  HDC v18; // ebx
  float v19; // xmm0_4
  HDC v20; // edi
  double v21; // xmm0_8
  COLORREF v22; // eax
  WORD pwHue[4]; // [esp+1Ch] [ebp-Ch]
  WORD pwSaturation[2]; // [esp+24h] [ebp-4h]

  nID = uID;
  switch ( uID )
  {
    case IDS_CPU_HISTORY:
      v6 = GetSysColorBrush(5);
      rc = lprc;
      hdc = hDC;
      FrameRect(hDC, lprc, v6);
      ++rc->top;
      --rc->right;
      if ( !pTreeItem->pGraphData1 )
        TreeViewItemParam_InitGraph(pTreeItem);
      GraphData_DrawChart(pTreeItem->pGraphData1, hdc, rc, gConfig.ColorGraphBk, 1u, 0.0);
      return 1;
    case IDS_PROCESS_TIMELINE:
      v10 = GetSysColorBrush(5);
      v11 = lprc;
      v12 = hDC;
      FrameRect(hDC, lprc, v10);
      ++v11->top;
      --v11->right;
      if ( !pTreeItem->pGraphData1 )
        TreeViewItemParam_InitGraph(pTreeItem);
      sub_1011FD0(&pTreeItem->CreateTime, v12, v11, gConfig.ColorGraphBk);
      return 1;
    case IDS_PRIVATE_BYTES_HISTORY:
      v13 = GetSysColorBrush(5);
      v14 = lprc;
      FrameRect(hDC, lprc, v13);
      ++v14->top;
      --v14->right;
      if ( !pTreeItem->pGraphData2 )
        TreeViewItemParam_InitGraph(pTreeItem);
      v15 = qword_10DBA40;
      GraphData_DrawChart(
        pTreeItem->pGraphData2,
        hDC,
        v14,
        gConfig.ColorGraphBk,
        1u,
        ((v15 * 0.2 + qword_10DBA40) * 0.0009765625));
      return 1;
  }
  if ( uID != 1330 )
  {
    v20 = hDC;
    if ( uID == IDS_VIRUSTOTAL && sub_1061820(pTreeItem->m_ItemDataForVirusTotal) )
    {
      if ( sub_1062910(pTreeItem->m_ItemDataForVirusTotal) )
        SetTextColor(v20, 0xFFu);
      else
        SetTextColor(v20, 0xFF0000u);
      SelectObject(v20, ghConfigUnderlineFont);
    }
    if ( a1 || !gConfig.bShowColumnHeatmaps )
      return 0;
    *&uID = 0;
    switch ( nID )
    {
      case IDS_CPU:
        ColorRGBToHLS(0x3C943Cu, &pwHue[2], &uID, pwSaturation);
        if ( pTreeItem->dwProcessId )
        {
          v21 = *&pTreeItem->m_CPU / 100.0;
          if ( v21 > 1.0 )
            v21 = db_one;
        }
        else
        {
          v21 = 0.0;
        }
        break;
      case IDS_PRIVATE_BYTES:
        ColorRGBToHLS(0x82A0u, &pwHue[2], &uID, pwSaturation);
        v21 = pTreeItem->PagefileUsage * 0.0009765625 / gpGraphInfoOfMemory->m_dbMemorySize;
        break;
      case IDS_WORKING_SET:
        ColorRGBToHLS(0x4080FFu, &pwHue[2], &uID, pwSaturation);
        v21 = pTreeItem->WorkingSetSize * 0.0009765625 / gpGraphInfoOfPhysicalMemory->m_dbMemorySize;
        break;
      case IDS_GPU2:
        ColorRGBToHLS(0x8080FFu, &pwHue[2], &uID, pwSaturation);
        v21 = *&pTreeItem->m_Gpu2 / 100.0;
        break;
      default:
        return 0;
    }
    if ( uID )
    {
      *&uID = sub_1016210(v21, 130u, 230u);
      if ( uID >= 110u )
        SetTextColor(v20, 0);
      else
        SetTextColor(v20, 0xFFFFFFu);
      v22 = ColorHLSToRGB(pwHue[2], uID, pwSaturation[0]);
      SetBkColor(v20, v22);
    }
    return 0;
  }
  v16 = GetSysColorBrush(5);
  v17 = lprc;
  v18 = hDC;
  FrameRect(hDC, lprc, v16);
  ++v17->top;
  --v17->right;
  if ( !pTreeItem->pGraphDataPROCCPU )
    TreeViewItemParam_InitGraph(pTreeItem);
  v19 = gIOGraphInfo.dbMemorySize;
  GraphData_DrawChart(pTreeItem->pGraphDataPROCCPU, v18, v17, gConfig.ColorGraphBk, 1u, (v19 * 1.2));
  return 1;
}
// 109CDC0: using guessed type double db_onehundred;
// 10DBA40: using guessed type __int64 qword_10DBA40;

//----- (01015AD0) --------------------------------------------------------
errno_t __cdecl sub_1015AD0(int a1, int a2, int a3, int a4, int a5, wchar_t *Dst, rsize_t SizeInWords)
{
  double v7; // xmm1_8
  errno_t result; // eax
  char v9; // fl
  bool v10; // cf
  bool v11; // zf
  char v12; // sf
  char v13; // of
  char v14; // pf

  v7 = *a1;
  if ( *a1 == 0.0 && !__PAIR__(a3, a2) && !__PAIR__(a5, a4) )
    return wcscpy_s(Dst, SizeInWords, &gszNullString);
  if ( gConfig.bShowCpuFractions )
  {
    if ( v7 >= 0.006 )
      return swprintf_s(Dst, SizeInWords, L"%02.2f", LODWORD(v7), HIDWORD(v7));
    result = swprintf_s(Dst, SizeInWords, L"< 0.01", LODWORD(v7), HIDWORD(v7));
  }
  else
  {
    if ( v7 >= 0.6 )
      return swprintf_s(Dst, SizeInWords, L"%0.0f", LODWORD(v7), HIDWORD(v7));
    result = swprintf_s(Dst, SizeInWords, L"< 1", LODWORD(v7), HIDWORD(v7));
  }
  v10 = *a1 < 0.0;
  v14 = 0;
  v11 = *a1 == 0.0;
  v12 = 0;
  v13 = 0;
  BYTE1(result) = v9;
  if ( *a1 == 0.0 )
    *a1 = db_zeropointzerozerofive;
  return result;
}
// 109E04C: using guessed type wchar_t a001[7];
// 109E9C8: using guessed type double db_zeropointzerozerofive;

//----- (01015BB0) --------------------------------------------------------
LPCWSTR __cdecl PE_GetDoubleString(wchar_t *pszText, double dbValue)
{
  if ( dbValue == 0.0 )
    return wcscpy_s(pszText, MAX_PATH, &gszNullString);
  if ( gConfig.bFormatIoBytes )
    return PE_FormatDouble(0, pszText, 0x104u, dbValue, 0.0, COERCE_DOUBLE(0i64 >> 63));
  swprintf(pszText, L"%f", dbValue);
  return PE_GetNumberFormat(pszText, 0x104u);
}

//----- (01015C30) --------------------------------------------------------
char __cdecl QueryListItemColor(HWND hWnd, int nItem, BOOL bFocused, COLORREF *pTextColor, COLORREF *pBackColor)
{
  bool v5; // cl
  int v6; // ebx
  DWORD (__stdcall *v7)(int); // esi
  char result; // al
  DWORD (__stdcall *v9)(int); // ecx
  COLORREF v10; // eax
  bool v11; // [esp+Ah] [ebp-2h]
  char v12; // [esp+Bh] [ebp-1h]

  v5 = GetFocus() == hWnd;
  v12 = 0;
  v11 = hWnd == ghWndTreeListView;
  if ( nItem <= 1000 )
  {
    v6 = bFocused;
  }
  else
  {
    v6 = *(nItem + 16);
    if ( *(nItem + 8) == gdwRefreshCount && v6 == 1 )
      v6 = *(nItem + 12);
  }
  if ( bFocused )
  {
    v7 = GetSysColor;
    if ( v5 )
    {
      *pTextColor = GetSysColor(14);
      *pBackColor = GetSysColor(13);
      return 0;
    }
    goto LABEL_9;
  }
  if ( nItem >= 1000 )
  {
    v9 = GetSysColor;
    switch ( v6 )
    {
      case 0:
        v10 = GetSysColor(5);
        v9 = GetSysColor;
        goto LABEL_18;
      case 1:
        v10 = gConfig.ColorDelProc;
        goto LABEL_17;
      case 2:
      case 3:
        v10 = gConfig.ColorNewProc;
LABEL_17:
        v12 = 1;
LABEL_18:
        *pBackColor = v10;
        break;
      default:
        break;
    }
    *pTextColor = v9(8);
    if ( !v6 )
    {
      if ( hWnd == ghWndDllsListCtrl && gConfig.bHighlightRelocatedDlls && *(nItem + 44) & 1 )
        *pBackColor = gConfig.ColorRelocatedDlls;
      if ( v11 )
      {
        if ( gConfig.bHighlightOwnProcesses && gConfig.bShowAllUsers && *(nItem + 40) & 0x40 )
          *pBackColor = gConfig.ColorOwn;
        if ( gConfig.bHighlightServices && *(nItem + 40) & 0x20 )
          *pBackColor = gConfig.ColorService;
        if ( *(nItem + 40) & 0x800 && gConfig.bHighlightJobs )
          *pBackColor = gConfig.ColorJobs;
        if ( (*(nItem + 1288) || *(nItem + 1284)) && gConfig.bHighliteNetProcess )
          *pBackColor = gConfig.ColorNet;
      }
      if ( gConfig.bHighlightPacked && (v11 && *(nItem + 40) & 0x100 || hWnd == ghWndDllsListCtrl && *(nItem + 44) & 4) )
        *pBackColor = gConfig.ColorPacked;
      if ( v11 )
      {
        if ( gConfig.bHighlightProtected && *(nItem + 40) & 0x400 )
          *pBackColor = gConfig.ColorProtected;
        if ( gConfig.bHighlightImmersive && *(nItem + 40) & 0x1000 )
          *pBackColor = gConfig.ColorImmersive;
        if ( gConfig.bHighlightSuspend )
        {
          if ( *(nItem + 40) < 0 )
            *pBackColor = gConfig.ColorSuspend;
        }
      }
    }
    result = v12;
  }
  else
  {
    v7 = GetSysColor;
    if ( !nItem )
    {
LABEL_9:
      *pTextColor = v7(8);
      *pBackColor = v7(10);
      return 0;
    }
    *pTextColor = GetSysColor(8);
    *pBackColor = GetSysColor(5);
    result = 0;
  }
  return result;
}
// 10CA11C: using guessed type int gdwRefreshCount;

//----- (01015E60) --------------------------------------------------------
BOOL __cdecl CTreeList::SetHeaderItem(HWND hWndHeader, WPARAM wParam, int fImage)
{
  BOOL result; // eax
  MACRO_HDF Format; // ecx
  HDITEMW Item; // [esp+Ch] [ebp-2Ch]

  if ( fImage )
  {
    if ( gbBitmapOnRight )
    {
      Item.mask = HDI_FORMAT;
      SendMessageW(hWndHeader, HDM_GETITEMW, wParam, &Item);
      Format = HDF_SORTDOWN;
      if ( fImage >= 0 )
        Format = HDF_SORTUP;
      Item.fmt = Item.fmt & -0x2601u | Format;
    }
    else
    {
      Item.mask = HDI_IMAGE|HDI_FORMAT;
      SendMessageW(hWndHeader, HDM_GETITEMW, wParam, &Item);
      Item.fmt |= 0x1800u;
      Item.iImage = fImage < 0;
    }
    SendMessageW(hWndHeader, HDM_SETITEMW, wParam, &Item);
    result = UpdateWindow(hWndHeader);
  }
  else
  {
    Item.mask = 4;
    SendMessageW(hWndHeader, HDM_GETITEMW, wParam, &Item);
    if ( gbBitmapOnRight )
      Item.fmt &= -0x2601u;
    else
      Item.fmt &= -0x1801u;
    SendMessageW(hWndHeader, HDM_SETITEMW, wParam, &Item);
    result = UpdateWindow(hWndHeader);
  }
  return result;
}
// 10CA8F8: using guessed type char gbBitmapOnRight;

//----- (01015F60) --------------------------------------------------------
BOOL __stdcall EnumFunc(HWND hWnd, LPARAM arg4)
{
  _bstr_t *v2; // ecx
  _bstr_t *v3; // ecx
  DWORD dwProcessId; // [esp+Ch] [ebp-220h]
  _bstr_t a2; // [esp+10h] [ebp-21Ch]
  WCHAR ClassName; // [esp+14h] [ebp-218h]
  int v8; // [esp+228h] [ebp-4h]

  GetWindowThreadProcessId(hWnd, &dwProcessId);
  if ( dwProcessId == *(*arg4 + 68)
    && GetClassNameW(hWnd, &ClassName, 260)
    && !_wcsicmp(&ClassName, L"TabThumbnailWindow")
    && GetWindowTextW(hWnd, &ClassName, 260) )
  {
    _bstr_t::_bstr_t(&a2, L"\n   ");
    v2 = *(arg4 + 4);
    v8 = 0;
    _bstr_t::operator+=(v2, &a2);
    v8 = -1;
    _bstr_t::_Free(&a2);
    _bstr_t::_bstr_t(&a2, &ClassName);
    v3 = *(arg4 + 4);
    v8 = 1;
    _bstr_t::operator+=(v3, &a2);
    _bstr_t::_Free(&a2);
  }
  return 1;
}

//----- (01016090) --------------------------------------------------------
char __cdecl IsStringID(signed int uID)
{
  bool v1; // zf

  if ( uID > 1111 )
  {
    if ( uID <= 1656 )
    {
      if ( uID < 1654 )
      {
        switch ( uID )
        {
          case 1180:
          case 1181:
          case 1187:
          case 1191:
          case 1193:
          case 1196:
          case 1199:
          case 1308:
          case 1330:
          case 1336:
          case 1337:
          case 1338:
          case 1340:
            return 0;
          default:
            return 1;
        }
        return 1;
      }
      return 0;
    }
    if ( uID > 1674 )
    {
      v1 = uID == IDS_CONTROL_FLOW_GUARD;
    }
    else
    {
      if ( uID >= 1673 || uID == 1667 )
        return 0;
      v1 = uID == 1670;
    }
  }
  else
  {
    if ( uID == 1111 )
      return 0;
    if ( uID <= 35 )
    {
      if ( uID != 35 )
      {
        switch ( uID )
        {
          case 3:
          case 19:
          case 21:
          case 22:
          case 25:
          case 26:
          case 30:
            return 0;
          default:
            return 1;
        }
        return 1;
      }
      return 0;
    }
    if ( uID > 1033 )
    {
      v1 = uID == 1061;
    }
    else
    {
      if ( uID >= 1032 || uID == 38 )
        return 0;
      v1 = uID == 42;
    }
  }
  if ( !v1 )
    return 1;
  return 0;
}

//----- (01016210) --------------------------------------------------------
unsigned __int16 __cdecl sub_1016210(double a1, unsigned __int16 a2, unsigned __int16 a3)
{
  unsigned __int16 result; // ax

  if ( a1 == 0.0 )
    result = a3;
  else
    result = a3 - 5 * (((a3 - a2) * a1) / 5);
  return result;
}

//----- (01016270) --------------------------------------------------------
int __cdecl sub_1016270(int a1, int a2)
{
  int v2; // edi
  _WORD *v3; // eax
  int v4; // eax
  _WORD *v5; // eax
  int v6; // eax
  _WORD *v7; // eax
  int v8; // eax
  Data_t_bstr_t *v9; // eax
  Data_t_bstr_t *v10; // ebx
  Data_t_bstr_t *v11; // edx
  int v12; // eax
  __int16 v13; // cx
  Data_t_bstr_t *v14; // edx
  OLECHAR *v15; // edx
  int *v16; // ebx
  Data_t_bstr_t *v17; // edi
  __int16 v18; // si
  Data_t_bstr_t *v19; // eax
  __int16 *v20; // ecx
  int v21; // esi
  __int16 v22; // ax
  _WORD *v23; // eax
  int v24; // eax
  _WORD *v25; // eax
  int v26; // eax
  _WORD *v27; // eax
  int v28; // eax
  int i; // esi
  signed int v30; // esi
  signed int v31; // ebx
  Data_t_bstr_t *v32; // eax
  Data_t_bstr_t *v33; // edx
  Data_t_bstr_t *v34; // ecx
  _bstr_t *v35; // esi
  _bstr_t *v36; // eax
  _bstr_t *v37; // eax
  _bstr_t *v38; // eax
  _bstr_t *v39; // eax
  const wchar_t *v40; // eax
  wchar_t *v41; // eax
  signed int v42; // esi
  Data_t_bstr_t *v43; // edi
  int v44; // eax
  OLECHAR *v45; // esi
  _bstr_t *v46; // eax
  _bstr_t *v47; // eax
  BSTR v48; // ecx
  int v49; // edx
  OLECHAR v50; // ax
  int v51; // ecx
  BSTR v52; // eax
  Data_t_bstr_t *v53; // esi
  LPARAM lParam; // [esp+14h] [ebp-40h]
  _bstr_t v56; // [esp+18h] [ebp-3Ch]
  _bstr_t v57; // [esp+1Ch] [ebp-38h]
  _bstr_t a1a; // [esp+20h] [ebp-34h]
  _bstr_t v59; // [esp+24h] [ebp-30h]
  _bstr_t v60; // [esp+28h] [ebp-2Ch]
  OLECHAR **v61; // [esp+2Ch] [ebp-28h]
  _bstr_t v62; // [esp+30h] [ebp-24h]
  _bstr_t v63; // [esp+34h] [ebp-20h]
  _bstr_t a2a; // [esp+38h] [ebp-1Ch]
  _bstr_t v65; // [esp+3Ch] [ebp-18h]
  _bstr_t v66; // [esp+40h] [ebp-14h]
  _bstr_t v67; // [esp+44h] [ebp-10h]
  int v68; // [esp+50h] [ebp-4h]

  if ( !(dword_10C9E5C & 1) )
  {
    dword_10C9E5C |= 1u;
    v68 = 0;
    _bstr_t::_bstr_t(&::a2, L"\r\n");
    atexit(sub_108A910);
  }
  v67.m_Data = 0;
  v2 = a2;
  v68 = 1;
  v3 = *(a2 + 784);
  if ( v3 && *v3 )
  {
    v4 = 0;
    if ( gConfig.dwProcessColumnCount <= 0 )
    {
LABEL_8:
      _bstr_t::operator+=(&v67, &::a2);
      _bstr_t::_bstr_t(&a2a, *(v2 + 784));
      LOBYTE(v68) = 2;
      _bstr_t::operator+=(&v67, &a2a);
      LOBYTE(v68) = 1;
      _bstr_t::_Free(&a2a);
    }
    else
    {
      while ( gConfig.dwProcessColumnMap[v4] != 38 )
      {
        if ( ++v4 >= gConfig.dwProcessColumnCount )
          goto LABEL_8;
      }
    }
  }
  v5 = *(v2 + 788);
  if ( v5 && *v5 )
  {
    v6 = 0;
    if ( gConfig.dwProcessColumnCount <= 0 )
    {
LABEL_14:
      _bstr_t::operator+=(&v67, &::a2);
      _bstr_t::_bstr_t(&a2a, *(v2 + 788));
      LOBYTE(v68) = 3;
      _bstr_t::operator+=(&v67, &a2a);
      LOBYTE(v68) = 1;
      _bstr_t::_Free(&a2a);
    }
    else
    {
      while ( gConfig.dwProcessColumnMap[v6] != 1033 )
      {
        if ( ++v6 >= gConfig.dwProcessColumnCount )
          goto LABEL_14;
      }
    }
  }
  v7 = *(v2 + 800);
  if ( v7 && *v7 )
  {
    v8 = 0;
    if ( gConfig.dwProcessColumnCount <= 0 )
    {
LABEL_20:
      _bstr_t::operator+=(&v67, &::a2);
      _bstr_t::_bstr_t(&a2a, L"Command Line:\n   ");
      LOBYTE(v68) = 4;
      _bstr_t::operator+=(&v67, &a2a);
      LOBYTE(v68) = 1;
      _bstr_t::_Free(&a2a);
      v9 = _wcsdup(*(v2 + 800));
      v10 = v9;
      v11 = v9;
      v66.m_Data = v9;
      v12 = &v9->m_wstr + 2;
      do
      {
        v13 = v11->m_wstr;
        v11 = (v11 + 2);
      }
      while ( v13 );
      if ( ((v11 - v12) >> 1) <= 0x64 )
      {
        _bstr_t::_bstr_t(&a2a, *(v2 + 800));
        LOBYTE(v68) = 8;
      }
      else
      {
        v14 = 0;
        if ( wcslen(v10) > 0x64 )
        {
          v15 = v10;
          v16 = &v10[16].m_RefCount;
          v17 = 0;
          do
          {
            v18 = *v16;
            *v16 = 0;
            _bstr_t::_bstr_t(&a2a, v15);
            LOBYTE(v68) = 5;
            _bstr_t::operator+=(&v67, &a2a);
            LOBYTE(v68) = 1;
            _bstr_t::_Free(&a2a);
            _bstr_t::_bstr_t(&v65, L"\n     ");
            LOBYTE(v68) = 6;
            _bstr_t::operator+=(&v67, &v65);
            LOBYTE(v68) = 1;
            _bstr_t::_Free(&v65);
            v19 = v66.m_Data;
            v16 += 50;
            v17 = (v17 + 100);
            *(v16 - 100) = v18;
            v15 = (v19 + 2 * v17);
            v20 = (v19 + 2 * v17);
            v21 = (v20 + 1);
            do
            {
              v22 = *v20;
              ++v20;
            }
            while ( v22 );
          }
          while ( ((v20 - v21) >> 1) > 0x64 );
          v10 = v66.m_Data;
          v62.m_Data = v17;
          v2 = a2;
          v14 = v62.m_Data;
        }
        _bstr_t::_bstr_t(&a2a, v10 + v14);
        LOBYTE(v68) = 7;
      }
      _bstr_t::operator+=(&v67, &a2a);
      LOBYTE(v68) = 1;
      _bstr_t::_Free(&a2a);
    }
    else
    {
      while ( gConfig.dwProcessColumnMap[v8] != 1032 )
      {
        if ( ++v8 >= gConfig.dwProcessColumnCount )
          goto LABEL_20;
      }
    }
  }
  v23 = *(v2 + 792);
  if ( v23 && *v23 )
  {
    v24 = 0;
    if ( gConfig.dwProcessColumnCount <= 0 )
    {
LABEL_37:
      _bstr_t::operator+=(&v67, &::a2);
      _bstr_t::_bstr_t(&a2a, L"Path:\n   ");
      LOBYTE(v68) = 9;
      _bstr_t::operator+=(&v67, &a2a);
      LOBYTE(v68) = 1;
      _bstr_t::_Free(&a2a);
      _bstr_t::_bstr_t(&a2a, *(v2 + 792));
      LOBYTE(v68) = 10;
      _bstr_t::operator+=(&v67, &a2a);
      LOBYTE(v68) = 1;
      _bstr_t::_Free(&a2a);
    }
    else
    {
      while ( gConfig.dwProcessColumnMap[v24] != 1061 )
      {
        if ( ++v24 >= gConfig.dwProcessColumnCount )
          goto LABEL_37;
      }
    }
  }
  v25 = *(v2 + 824);
  if ( v25 && *v25 )
  {
    v26 = 0;
    if ( gConfig.dwProcessColumnCount <= 0 )
    {
LABEL_43:
      _bstr_t::operator+=(&v67, &::a2);
      _bstr_t::_bstr_t(&a2a, "Package:\n   ");
      LOBYTE(v68) = 11;
      _bstr_t::operator+=(&v67, &a2a);
      LOBYTE(v68) = 1;
      _bstr_t::_Free(&a2a);
      _bstr_t::_bstr_t(&a2a, *(v2 + 824));
      LOBYTE(v68) = 12;
      _bstr_t::operator+=(&v67, &a2a);
      LOBYTE(v68) = 1;
      _bstr_t::_Free(&a2a);
    }
    else
    {
      while ( gConfig.dwProcessColumnMap[v26] != 1654 )
      {
        if ( ++v26 >= gConfig.dwProcessColumnCount )
          goto LABEL_43;
      }
    }
  }
  v27 = *(v2 + 796);
  if ( v27 && *v27 )
  {
    v28 = 0;
    if ( gConfig.dwProcessColumnCount <= 0 )
    {
LABEL_49:
      _bstr_t::operator+=(&v67, &::a2);
      _bstr_t::_bstr_t(&a2a, L"Comment:\n   ");
      LOBYTE(v68) = 13;
      _bstr_t::operator+=(&v67, &a2a);
      LOBYTE(v68) = 1;
      _bstr_t::_Free(&a2a);
      _bstr_t::_bstr_t(&a2a, *(v2 + 796));
      LOBYTE(v68) = 14;
      _bstr_t::operator+=(&v67, &a2a);
      LOBYTE(v68) = 1;
      _bstr_t::_Free(&a2a);
    }
    else
    {
      while ( gConfig.dwProcessColumnMap[v28] != 1181 )
      {
        if ( ++v28 >= gConfig.dwProcessColumnCount )
          goto LABEL_49;
      }
    }
  }
  if ( *(v2 + 860) )
  {
    _bstr_t::operator+=(&v67, &::a2);
    if ( _wcsicmp(*(v2 + 60), L"rundll32.exe") )
    {
      _bstr_t::_bstr_t(&a2, L"COM Class:\n   ");
      LOBYTE(v68) = 16;
      _bstr_t::operator+=(&v67, &a2);
      LOBYTE(v68) = 1;
      _bstr_t::_Free(&a2);
      if ( !*(v2 + 848) )
      {
LABEL_56:
        _bstr_t::_bstr_t(&a2, *(v2 + 860));
        LOBYTE(v68) = 19;
        _bstr_t::operator+=(&v67, &a2);
        LOBYTE(v68) = 1;
        _bstr_t::_Free(&a2);
        if ( *(v2 + 856) )
        {
          _bstr_t::_bstr_t(&a2, L"\n   ");
          LOBYTE(v68) = 20;
          _bstr_t::operator+=(&v67, &a2);
          LOBYTE(v68) = 1;
          _bstr_t::_Free(&a2);
          _bstr_t::_bstr_t(&a2, *(v2 + 856));
          LOBYTE(v68) = 21;
          _bstr_t::operator+=(&v67, &a2);
          LOBYTE(v68) = 1;
          _bstr_t::_Free(&a2);
        }
        if ( *(v2 + 852) )
        {
          _bstr_t::_bstr_t(&a2, L"\n   ");
          LOBYTE(v68) = 22;
          _bstr_t::operator+=(&v67, &a2);
          LOBYTE(v68) = 1;
          _bstr_t::_Free(&a2);
          _bstr_t::_bstr_t(&a2, *(v2 + 852));
          LOBYTE(v68) = 23;
          _bstr_t::operator+=(&v67, &a2);
          LOBYTE(v68) = 1;
          _bstr_t::_Free(&a2);
        }
        goto LABEL_93;
      }
      _bstr_t::_bstr_t(&a2, *(v2 + 848));
      LOBYTE(v68) = 17;
      _bstr_t::operator+=(&v67, &a2);
      LOBYTE(v68) = 1;
      _bstr_t::_Free(&a2);
      _bstr_t::_bstr_t(&a2, L"\n   ");
      LOBYTE(v68) = 18;
    }
    else
    {
      _bstr_t::_bstr_t(&a2, L"Rundll Target:\n   ");
      LOBYTE(v68) = 15;
    }
    _bstr_t::operator+=(&v67, &a2);
    LOBYTE(v68) = 1;
    _bstr_t::_Free(&a2);
    goto LABEL_56;
  }
  if ( _wcsicmp(*(v2 + 60), L"taskeng.exe")
    && _wcsicmp(*(v2 + 60), L"taskhost.exe")
    && _wcsicmp(*(v2 + 60), L"taskhostex.exe")
    && _wcsicmp(*(v2 + 60), L"taskhostw.exe") )
  {
    if ( _wcsicmp(*(v2 + 60), L"iexplore.exe") && _wcsicmp(*(v2 + 60), L"iexplore.exe") )
    {
      if ( *(v2 + 868) )
      {
        _bstr_t::operator+=(&v67, &::a2);
        _bstr_t::_bstr_t(&a2, L"WMI Providers:");
        LOBYTE(v68) = 27;
        _bstr_t::operator+=(&v67, &a2);
        LOBYTE(v68) = 1;
        _bstr_t::_Free(&a2);
        for ( i = *(v2 + 868); i; i = *(i + 12) )
        {
          _bstr_t::_bstr_t(&a2, L"\n   [");
          LOBYTE(v68) = 28;
          _bstr_t::operator+=(&v67, &a2);
          LOBYTE(v68) = 1;
          _bstr_t::_Free(&a2);
          _bstr_t::_bstr_t(&a2a, *i);
          LOBYTE(v68) = 29;
          _bstr_t::operator+=(&v67, &a2a);
          LOBYTE(v68) = 1;
          _bstr_t::_Free(&a2a);
          _bstr_t::_bstr_t(&v65, L"]\n       Namespace: ");
          LOBYTE(v68) = 30;
          _bstr_t::operator+=(&v67, &v65);
          LOBYTE(v68) = 1;
          _bstr_t::_Free(&v65);
          _bstr_t::_bstr_t(&v66, *(i + 4));
          LOBYTE(v68) = 31;
          _bstr_t::operator+=(&v67, &v66);
          LOBYTE(v68) = 1;
          _bstr_t::_Free(&v66);
          _bstr_t::_bstr_t(&v63, L"\n       DLL: ");
          LOBYTE(v68) = 32;
          _bstr_t::operator+=(&v67, &v63);
          LOBYTE(v68) = 1;
          _bstr_t::_Free(&v63);
          _bstr_t::_bstr_t(&v62, *(i + 8));
          LOBYTE(v68) = 33;
          _bstr_t::operator+=(&v67, &v62);
          LOBYTE(v68) = 1;
          _bstr_t::_Free(&v62);
        }
      }
      else if ( *(v2 + 40) & 0x20 )
      {
        if ( *(v2 + 864) )
        {
          _bstr_t::_bstr_t(&v62, L" (");
          LOBYTE(v68) = 34;
          _bstr_t::operator+=(&v67, &v62);
          LOBYTE(v68) = 1;
          _bstr_t::_Free(&v62);
          _bstr_t::_bstr_t(&v62, *(v2 + 864));
          LOBYTE(v68) = 35;
          _bstr_t::operator+=(&v67, &v62);
          LOBYTE(v68) = 1;
          _bstr_t::_Free(&v62);
          _bstr_t::_bstr_t(&v62, L")");
          LOBYTE(v68) = 36;
          _bstr_t::operator+=(&v67, &v62);
          LOBYTE(v68) = 1;
          _bstr_t::_Free(&v62);
        }
        _bstr_t::operator+=(&v67, &::a2);
        _bstr_t::_bstr_t(&v62, L"Services:");
        LOBYTE(v68) = 37;
        _bstr_t::operator+=(&v67, &v62);
        LOBYTE(v68) = 1;
        _bstr_t::_Free(&v62);
        EnterCriticalSection(&gServiceLock);
        v30 = gdwServiceReturned;
        v31 = 0;
        v32 = malloc(4 * gdwServiceReturned);
        v33 = 0;
        v66.m_Data = v32;
        v63.m_Data = 0;
        if ( v30 > 0 )
        {
          v34 = 0;
          a2a.m_Data = 0;
          do
          {
            v61 = (gpszServiceNames + v34);
            if ( *(gpszServiceNames + v34 + 36) == *(v2 + 68) )
            {
              v65.m_Data = 0;
              LOBYTE(v68) = 38;
              _bstr_t::_bstr_t(&v62, *v61);
              LOBYTE(v68) = 39;
              v35 = _bstr_t::_bstr_t(&v56, "]");
              LOBYTE(v68) = 40;
              v36 = _bstr_t::_bstr_t(&v57, " [");
              LOBYTE(v68) = 41;
              v37 = _bstr_t::operator+(&a1a, *(&a2a.m_Data->m_str + gpszServiceNames), v36);
              LOBYTE(v68) = 42;
              v38 = _bstr_t::operator+(v37, &v59, &v62);
              LOBYTE(v68) = 43;
              v39 = _bstr_t::operator+(v38, &v60, v35);
              sub_FD3A50(&v65, v39);
              _bstr_t::_Free(&v60);
              _bstr_t::_Free(&v59);
              _bstr_t::_Free(&a1a);
              _bstr_t::_Free(&v57);
              _bstr_t::_Free(&v56);
              _bstr_t::_Free(&v62);
              if ( v65.m_Data )
                v40 = v65.m_Data->m_wstr;
              else
                v40 = 0;
              v41 = _wcsdup(v40);
              LOBYTE(v68) = 1;
              *(&v66.m_Data->m_wstr + v31++) = v41;
              _bstr_t::_Free(&v65);
              v30 = gdwServiceReturned;
              v34 = a2a.m_Data;
              v33 = v63.m_Data;
            }
            v33 = (v33 + 1);
            v34 = (v34 + 44);
            v63.m_Data = v33;
            a2a.m_Data = v34;
          }
          while ( v33 < v30 );
          v32 = v66.m_Data;
        }
        qsort(v32, v31, 4u, sub_1025A60);
        v42 = 0;
        if ( v31 > 0 )
        {
          v43 = v66.m_Data;
          do
          {
            _bstr_t::_bstr_t(&v62, L"\n   ");
            LOBYTE(v68) = 44;
            _bstr_t::operator+=(&v67, &v62);
            LOBYTE(v68) = 1;
            _bstr_t::_Free(&v62);
            _bstr_t::_bstr_t(&v63, *(&v43->m_wstr + v42));
            LOBYTE(v68) = 45;
            _bstr_t::operator+=(&v67, &v63);
            LOBYTE(v68) = 1;
            _bstr_t::_Free(&v63);
            free(*(&v43->m_wstr + v42++));
          }
          while ( v42 < v31 );
          v2 = a2;
        }
        LeaveCriticalSection(&gServiceLock);
        free(v66.m_Data);
      }
    }
    else if ( *(v2 + 654) >= 0x37u )
    {
      v44 = *(v2 + 84);
      if ( v44 )
      {
        if ( !_wcsicmp(*(v44 + 60), L"iexplore.exe") )
        {
          _bstr_t::operator+=(&v67, &::a2);
          _bstr_t::_bstr_t(&a2, L"Tabs:");
          LOBYTE(v68) = 26;
          _bstr_t::operator+=(&v67, &a2);
          LOBYTE(v68) = 1;
          _bstr_t::_Free(&a2);
          lParam = v2;
          v56.m_Data = &v67;
          EnumWindows(EnumFunc, &lParam);
        }
      }
    }
  }
  else
  {
    v45 = sub_1024990(*(v2 + 68));
    if ( v45 )
    {
      _bstr_t::operator+=(&v67, &::a2);
      v46 = _bstr_t::_bstr_t(&v56, v45);
      LOBYTE(v68) = 24;
      v47 = _bstr_t::operator+(&a2, L"Tasks:\n", v46);
      LOBYTE(v68) = 25;
      _bstr_t::operator+=(&v67, v47);
      _bstr_t::_Free(&a2);
      LOBYTE(v68) = 1;
      _bstr_t::_Free(&v56);
      free(v45);
    }
  }
LABEL_93:
  if ( !v67.m_Data || !v67.m_Data->m_wstr || !SysStringLen(v67.m_Data->m_wstr) )
  {
    _bstr_t::operator+=(&v67, &::a2);
    _bstr_t::_bstr_t(&a2, *(v2 + 60));
    LOBYTE(v68) = 46;
    _bstr_t::operator+=(&v67, &a2);
    LOBYTE(v68) = 1;
    _bstr_t::_Free(&a2);
  }
  if ( ::a2.m_Data )
    v48 = ::a2.m_Data->m_wstr;
  else
    v48 = 0;
  v49 = (v48 + 1);
  do
  {
    v50 = *v48;
    ++v48;
  }
  while ( v50 );
  v51 = (v48 - v49) >> 1;
  if ( v67.m_Data )
    v52 = v67.m_Data->m_wstr;
  else
    v52 = 0;
  _bstr_t::_bstr_t(a1, &v52[v51]);
  v53 = v67.m_Data;
  if ( v67.m_Data && !InterlockedDecrement(&v67.m_Data->m_RefCount) && v53 )
  {
    if ( v53->m_wstr )
    {
      SysFreeString(v53->m_wstr);
      v53->m_wstr = 0;
    }
    if ( v53->m_str )
    {
      j_j__free(v53->m_str);
      v53->m_str = 0;
    }
    j__free(v53);
  }
  return a1;
}
// 10C9E5C: using guessed type int dword_10C9E5C;

//----- (01016F30) --------------------------------------------------------
void __cdecl RegVar_ReadWrite(int fSave, int nCount, CRegVar *pVariable)
{
  wchar_t *pConfigItem; // [esp+0h] [ebp-3F4h]
  tagConfigItem ConfigItems[20]; // [esp+8h] [ebp-3ECh]
  WCHAR pszBuffer[260]; // [esp+1E8h] [ebp-20Ch]

  ConfigItems[1].dbValue = db_twohundred;
  ConfigItems[3].dbValue = db_six;
  ConfigItems[1].Address = &pVariable->ProcessImageColumnWidth;
  ConfigItems[4].llValue = 0i64;
  ConfigItems[2].Address = pVariable->ProcessColumns;
  ConfigItems[3].Address = &pVariable->PrcessColumnCount;
  *&ConfigItems[4].Address = pVariable->ProcessColumnMap;
  ConfigItems[5].Address = &pVariable->DllColumnCount;
  ConfigItems[6].Address = pVariable->DllColumns;
  ConfigItems[7].Address = pVariable->DllColumnMap;
  ConfigItems[5].dbValue = db_four;
  ConfigItems[8].Address = &pVariable->HandleColumnCount;
  ConfigItems[7].llValue = 0i64;
  ConfigItems[9].Address = pVariable->HandleColumnMap;
  ConfigItems[8].dbValue = db_two;
  ConfigItems[10].Address = pVariable->HandleColumns;
  ConfigItems[0].Name = L"ColumnSetName";
  ConfigItems[0].KeyType = KT_String;
  ConfigItems[0].StructSize = 520;
  ConfigItems[0].Address = pVariable;
  ConfigItems[0].llValue = 0i64;
  ConfigItems[1].Name = L"ProcessImageColumnWidth";
  ConfigItems[1].KeyType = 3;
  ConfigItems[1].StructSize = 2;
  ConfigItems[2].Name = L"ProcessColumns";
  ConfigItems[2].KeyType = 6;
  ConfigItems[2].StructSize = 192;
  ConfigItems[2].llValue = 0i64;
  ConfigItems[3].Name = L"PrcessColumnCount";
  ConfigItems[3].KeyType = 0;
  ConfigItems[3].StructSize = 0;
  ConfigItems[4].Name = L"ProcessColumnMap";
  ConfigItems[4].KeyType = 5;
  ConfigItems[4].StructSize = 384;
  ConfigItems[5].Name = L"DllColumnCount";
  ConfigItems[5].KeyType = 0;
  ConfigItems[5].StructSize = 0;
  ConfigItems[6].Name = L"DllColumns";
  ConfigItems[6].KeyType = 6;
  ConfigItems[6].StructSize = 64;
  ConfigItems[6].llValue = 0i64;
  ConfigItems[7].Name = L"DllColumnMap";
  ConfigItems[7].KeyType = 5;
  ConfigItems[7].StructSize = 128;
  ConfigItems[8].Name = L"HandleColumnCount";
  ConfigItems[8].KeyType = 0;
  ConfigItems[8].StructSize = 0;
  ConfigItems[9].Name = L"HandleColumnMap";
  ConfigItems[9].KeyType = 5;
  ConfigItems[9].StructSize = 128;
  ConfigItems[9].llValue = 0i64;
  ConfigItems[10].Name = L"HandleColumns";
  ConfigItems[10].KeyType = 6;
  ConfigItems[10].StructSize = 64;
  ConfigItems[10].llValue = 0i64;
  ConfigItems[11].Name = L"HandleSortColumn";
  ConfigItems[11].KeyType = 0;
  ConfigItems[11].StructSize = 0;
  ConfigItems[11].Address = &pVariable->HandleSortColumn;
  ConfigItems[11].llValue = 0i64;
  ConfigItems[12].Name = L"HandleSortDirection";
  ConfigItems[12].Address = &pVariable->HandleSortDirection;
  ConfigItems[13].Address = &pVariable->DllSortColumn;
  ConfigItems[14].Address = &pVariable->DllSortDirection;
  ConfigItems[15].Address = &pVariable->ProcessSortColumn;
  ConfigItems[16].Address = &pVariable->ProcessSortDirection;
  ConfigItems[17].Address = &pVariable->ShowProcessTree;
  ConfigItems[18].Address = &pVariable->StatusBarColumns;
  ConfigItems[15].llValue = qword_109EA40;
  ConfigItems[12].KeyType = KT_Bool;
  ConfigItems[12].StructSize = 0;
  ConfigItems[12].dbValue = db_one;
  ConfigItems[13].Name = L"DllSortColumn";
  ConfigItems[13].KeyType = 0;
  ConfigItems[13].StructSize = 0;
  ConfigItems[13].llValue = 0i64;
  ConfigItems[14].Name = L"DllSortDirection";
  ConfigItems[14].KeyType = 1;
  ConfigItems[14].StructSize = 0;
  ConfigItems[14].dbValue = db_one;
  ConfigItems[15].Name = L"ProcessSortColumn";
  ConfigItems[15].KeyType = 0;
  ConfigItems[15].StructSize = 0;
  ConfigItems[16].Name = L"ProcessSortDirection";
  ConfigItems[16].KeyType = 1;
  ConfigItems[16].StructSize = 0;
  ConfigItems[16].dbValue = db_one;
  ConfigItems[17].Name = L"ShowProcessTree";
  ConfigItems[17].KeyType = 1;
  ConfigItems[17].StructSize = 0;
  ConfigItems[17].dbValue = db_one;
  ConfigItems[18].Name = L"StatusBarColumns";
  ConfigItems[18].KeyType = 0;
  ConfigItems[18].StructSize = 0;
  ConfigItems[18].dbValue = db_twenty21;
  ConfigItems[19].Name = 0;
  ConfigItems[19].KeyType = 0;
  ConfigItems[19].StructSize = 0;
  ConfigItems[19].Address = 0;
  ConfigItems[19].llValue = 0i64;
  swprintf(pszBuffer, L"Software\\Sysinternals\\Process Explorer\\ColumnSet%d", nCount);
  pConfigItem = _wcsdup(pszBuffer);
  if ( fSave )
    SaveConfigItemToRegistry(&pConfigItem, ConfigItems);
  else
    LoadConfigItemFromRegistry(&pConfigItem, ConfigItems);
  free(pConfigItem);
}
// 109CB38: using guessed type double db_four;
// 109D414: using guessed type wchar_t aProcesscolumns[15];
// 109D434: using guessed type wchar_t aProcessimageco[24];
// 109D464: using guessed type wchar_t aHandlecolumns[14];
// 109D480: using guessed type wchar_t aDllcolumns[11];
// 109D4D8: using guessed type wchar_t aHandlesortcolu[17];
// 109D4FC: using guessed type wchar_t aHandlesortdire[20];
// 109D524: using guessed type wchar_t aDllsortcolumn[14];
// 109D540: using guessed type wchar_t aDllsortdirecti[17];
// 109D564: using guessed type wchar_t aProcesssortcol[18];
// 109D588: using guessed type wchar_t aProcesssortdir[21];
// 109D7D4: using guessed type wchar_t aShowprocesstre[16];
// 109D8BC: using guessed type wchar_t aPrcesscolumnco[18];
// 109D8E0: using guessed type wchar_t aProcesscolumnm[17];
// 109D904: using guessed type wchar_t aDllcolumncount[15];
// 109D924: using guessed type wchar_t aDllcolumnmap[13];
// 109D940: using guessed type wchar_t aHandlecolumnco[18];
// 109D964: using guessed type wchar_t aHandlecolumnma[16];
// 109DB90: using guessed type wchar_t aStatusbarcolum[17];
// 109DE18: using guessed type wchar_t aColumnsetname[14];
// 109E9E8: using guessed type double db_two;
// 109E9F0: using guessed type double db_six;
// 109E9F8: using guessed type double db_twenty21;
// 109EA00: using guessed type double db_twohundred;
// 109EA40: using guessed type __int64 qword_109EA40;

//----- (010173D0) --------------------------------------------------------
int __cdecl sub_10173D0(HWND hWnd, char a2)
{
  int v2; // eax
  int result; // eax
  LPARAM lParam; // [esp+Ch] [ebp-464h]
  int v5; // [esp+10h] [ebp-460h]
  int v6; // [esp+14h] [ebp-45Ch]
  int v7; // [esp+18h] [ebp-458h]
  int v8; // [esp+1Ch] [ebp-454h]
  WCHAR *v9; // [esp+20h] [ebp-450h]
  int v10; // [esp+24h] [ebp-44Ch]
  int v11; // [esp+28h] [ebp-448h]
  int v12; // [esp+2Ch] [ebp-444h]
  char v13; // [esp+40h] [ebp-430h]
  wchar_t Src; // [esp+64h] [ebp-40Ch]
  WCHAR String; // [esp+26Ch] [ebp-204h]

  qmemcpy(&v13, &a2, 0x22Cu);
  memset(&v5, 0, 0x30u);
  wcscpy_s(&String, 0x100u, &Src);
  lParam = 13;
  v5 = 0x7FFFFFFF;
  v6 = 0;
  v7 = 0;
  v8 = 0;
  v9 = &String;
  v2 = lstrlenW(&String);
  v11 = 0;
  v10 = v2 + 1;
  result = malloc(0x22Cu);
  if ( result )
  {
    qmemcpy(result, &v13, 0x22Cu);
    v12 = result;
    result = SendMessageW(hWnd, 0x104Du, 0, &lParam) != -1;
  }
  return result;
}

//----- (010174F0) --------------------------------------------------------
char __cdecl CTreeList_InsertVerifyColumn(HWND hWnd, UINT uID, int *pnIDs, int pnLength)
{
  int idx; // eax
  int i; // ecx
  bool v6; // zf
  char v7; // cl
  HWND hWnd_1; // edi
  WPARAM nItem; // ecx
  tagLVCOLUMNW ColumnInfo; // [esp+Ch] [ebp-A8h]
  HWND hWndIn; // [esp+2Ch] [ebp-88h]
  WCHAR Buffer[64]; // [esp+30h] [ebp-84h]

  hWndIn = hWnd;
  idx = 0;
  for ( i = *pnLength; idx < i; ++idx )
  {
    if ( pnIDs[idx] == uID )
      break;
  }
  if ( idx != i )
    return 0;
  ColumnInfo.iSubItem = *pnLength;
  ColumnInfo.cx = MulDiv(100, gLogPixelSize.x, 96);
  LoadStringW(ghInstance, uID, Buffer, 64);
  pnIDs[*pnLength] = uID;
  ColumnInfo.mask = 7;
  ColumnInfo.cchTextMax = 64;
  ColumnInfo.pszText = Buffer;
  if ( uID > IDS_PATH2 )
  {
    if ( uID <= IDS_AUTOSTART_LOCATION )
    {
      if ( uID < IDS_PACKAGE_NAME )
      {
        switch ( uID )
        {
          case IDS_DESKTOP_INTEGRITY_LEVEL:
          case IDS_COMMENT:
          case IDS_VERIFIED_SIGNER:
          case IDS_CPU_HISTORY:
          case IDS_PRIVATE_BYTES_HISTORY:
          case IDS_WINDOW_STATUS:
          case IDS_DEP:
          case IDS_DECODED_ACCESS:
          case IDS_IO_HISTORY:
          case IDC_SYSINFO_IOETW_STATIC_DISK:
          case IDC_PAGE_PROCTHREADS_STATIC_IO_PRIORITY:
          case IDC_PAGE_PROCTHREADS_STATIC_MEMORY_PRIORITY:
          case IDC_PAGE_PROCTHREADS_STATIC_IO_PRIORITY_VALUE:
            goto LABEL_25;
          default:
            goto LABEL_24;
        }
        goto LABEL_24;
      }
      goto LABEL_25;
    }
    if ( uID > IDS_UI_ACCESS )
    {
      v6 = uID == IDS_CONTROL_FLOW_GUARD;
    }
    else
    {
      if ( uID >= IDS_PROTECTION || uID == IDS_DPI_AWARENESS )
        goto LABEL_25;
      v6 = uID == IDS_VIRUSTOTAL;
    }
  }
  else
  {
    if ( uID == IDS_PATH2 )
      goto LABEL_25;
    if ( uID <= IDS_WINDOW_TITLE )
    {
      if ( uID != IDS_WINDOW_TITLE )
      {
        switch ( uID )
        {
          case IDS_PROCESS:
          case IDS_USER_NAME:
          case IDS_TYPE:
          case IDS_NAME1:
          case IDS_VERSION:
          case IDS_NAME2:
          case IDS_TIME:
            goto LABEL_25;
          default:
            goto LABEL_24;
        }
        goto LABEL_24;
      }
LABEL_25:
      v7 = 0;
      goto LABEL_26;
    }
    if ( uID > IDS_COMPANY_NAME )
    {
      v6 = uID == IDS_PATH;
    }
    else
    {
      if ( uID >= IDS_COMMAND_LINE || uID == IDS_DESCRIPTION )
        goto LABEL_25;
      v6 = uID == IDS_DESCRIPTION2;
    }
  }
  if ( v6 )
    goto LABEL_25;
LABEL_24:
  v7 = 1;
LABEL_26:
  hWnd_1 = hWndIn;
  v6 = v7 == 0;
  nItem = *pnLength;
  ColumnInfo.fmt = !v6;
  *pnLength = nItem + 1;
  SendMessageW(hWnd_1, LVM_INSERTCOLUMNW, nItem, &ColumnInfo);
  SetWindowLongW(hWnd_1, GWLP_USERDATA, *pnLength);
  if ( uID == IDS_VIRUSTOTAL && !gConfig.bCheckVirusTotal )
    MessageBoxW(
      hWnd_1,
      L"You can enable lookup of VirusTotal results for all files displayed in the process and DLL views by selecting the "
       "Check VirusTotal entry in the Options menu or check individual  files on-demand using the process and DLL properties dialogs.",
      L"VirusTotal",
      0x40u);
  return 1;
}

//----- (01017790) --------------------------------------------------------
int __cdecl sub_1017790(HWND hWnd, char a2)
{
  DLLLISTITEMPARAM *pItemParam; // eax
  DLLLISTITEMPARAM *pItemParam_1; // ebx
  int v5; // eax
  tagLVITEMW ItemInfo; // [esp+4h] [ebp-34h]

  memset(&ItemInfo.iItem, 0, 0x30u);
  ItemInfo.mask = 13;
  ItemInfo.iItem = 0x7FFFFFFF;
  ItemInfo.iSubItem = 0;
  ItemInfo.state = 0;
  ItemInfo.stateMask = 0;
  ItemInfo.pszText = -1;
  ItemInfo.iImage = 0;
  pItemParam = malloc(sizeof(DLLLISTITEMPARAM));
  pItemParam_1 = pItemParam;
  if ( !pItemParam )
    return 0;
  qmemcpy(pItemParam, &a2, sizeof(DLLLISTITEMPARAM));
  pItemParam->m_nRefCount = 1;
  pItemParam->field_164 = 0;
  pItemParam->field_168 = 0;
  pItemParam->field_160 = 0;
  pItemParam->m_Type = 1;
  pItemParam->field_8 = gdwRefreshCount + 1;
  ItemInfo.lParam = pItemParam;
  if ( SendMessageW(hWnd, LVM_INSERTITEMW, 0, &ItemInfo) == -1 )
    return 0;
  pItemParam_1->m_Next = 0;
  pItemParam_1->m_Prev = gpDllListItemParamHeader;
  if ( gpDllListItemParamHeader )
    gpDllListItemParamHeader->m_Next = pItemParam_1;
  gpDllListItemParamHeader = pItemParam_1;
  if ( gConfig.bVerifySignatures )
  {
    InterlockedIncrement(&pItemParam_1->m_nRefCount);
    _beginthread(VerifyImageThreadProc, 0, pItemParam_1);
  }
  v5 = 2;
  if ( gConfig.bCheckVirusTotal )
    v5 = 0;
  sub_1061C30(pItemParam_1, ~(pItemParam_1->field_2C >> 1) & 1, v5);
  return 1;
}
// 10CA11C: using guessed type int gdwRefreshCount;

//----- (010178D0) --------------------------------------------------------
wchar_t *__cdecl sub_10178D0(HWND a1, wchar_t *a2)
{
  const WCHAR *v2; // eax
  int v3; // eax
  wchar_t *result; // eax
  HWND v5; // esi
  HWND v6; // eax
  LPARAM v7; // [esp+4h] [ebp-270h]
  int v8; // [esp+Ch] [ebp-268h]
  wchar_t *v9; // [esp+18h] [ebp-25Ch]
  LPARAM lParam; // [esp+38h] [ebp-23Ch]
  int v11; // [esp+3Ch] [ebp-238h]
  int v12; // [esp+40h] [ebp-234h]
  int v13; // [esp+44h] [ebp-230h]
  int v14; // [esp+48h] [ebp-22Ch]
  const WCHAR *v15; // [esp+4Ch] [ebp-228h]
  int v16; // [esp+50h] [ebp-224h]
  int v17; // [esp+54h] [ebp-220h]
  wchar_t *v18; // [esp+58h] [ebp-21Ch]
  HWND hWnd; // [esp+6Ch] [ebp-208h]
  wchar_t Dst; // [esp+70h] [ebp-204h]

  hWnd = a1;
  memset(&v11, 0, 0x30u);
  v2 = *(a2 + 9);
  lParam = 13;
  v11 = 0x7FFFFFFF;
  v12 = 0;
  v13 = 0;
  v14 = 0;
  v15 = v2;
  v3 = lstrlenW(v2);
  v17 = 0;
  v16 = v3 + 1;
  result = malloc(0xB8u);
  if ( result )
  {
    qmemcpy(result, a2, 0xB8u);
    v5 = hWnd;
    v18 = result;
    hWnd = SendMessageW(hWnd, 0x104Du, 0, &lParam);
    if ( hWnd == HWND_MESSAGE|0x2 )
    {
      result = 0;
    }
    else
    {
      wsprintf(&Dst, L"%d", *(a2 + 42));
      v8 = 1;
      v9 = &Dst;
      SendMessageW(v5, 0x1074u, hWnd, &v7);
      v8 = 2;
      v9 = a2 + 20;
      SendMessageW(v5, 0x1074u, hWnd, &v7);
      v9 = *(a2 + 45);
      v8 = 3;
      SendMessageW(v5, 0x1074u, hWnd, &v7);
      v6 = GetParent(v5);
      SendMessageW(v6, 0x465u, 0, 0);
      result = 1;
    }
  }
  return result;
}