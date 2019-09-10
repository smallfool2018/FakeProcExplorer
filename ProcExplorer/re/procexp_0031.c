


//----- (00FFF9D0) --------------------------------------------------------
LRESULT __cdecl CMainWnd::InitStatusBar(HWND hWnd)
{
  HWND v1; // edx
  WPARAM wParam; // ecx
  signed int dwMaxCount; // edi
  signed int dwFlags; // esi
  int v5; // eax
  int nID[32]; // [esp+10h] [ebp-84h]

  v1 = hWnd;
  wParam = 0;
  dwMaxCount = 32;
  gnStatusBarItemCount = 0;
  dwFlags = 1;
  do
  {
    if ( dwFlags & gConfig.dwStatusBarColumns )
    {
      nID[wParam] = 10 * (wParam + 1);
      SendMessageW(v1, SB_SETTEXTW, wParam, gszStatusBarText);
      v1 = hWnd;
      wParam = gnStatusBarItemCount++ + 1;
    }
    dwFlags = __ROL4__(dwFlags, 1);
    --dwMaxCount;
  }
  while ( dwMaxCount );
  SendMessageW(v1, SB_SETTEXTW, wParam, gszStatusBarText);
  v5 = gnStatusBarItemCount;
  nID[gnStatusBarItemCount] = -1;
  gnStatusBarItemCount = v5 + 1;
  return SendMessageW(ghWndStatusBar, SB_SETPARTS, v5 + 1, nID);
}
// 1085720: using guessed type int gnStatusBarItemCount;
// FFF9D0: using guessed type LPARAM nID[32];

//----- (00FFFA90) --------------------------------------------------------
int __cdecl sub_FFFA90(int a1, int a2)
{
  unsigned int v2; // eax
  WCHAR Buffer; // [esp+4h] [ebp-804h]

  v2 = *(a2 + 4);
  if ( v2 <= 0x9EC3 )
  {
    if ( v2 == 40643 )
    {
      LoadStringW(ghInstance, 0x25u, &Buffer, 1024);
    }
    else
    {
      switch ( v2 )
      {
        case 0x9C42u:
          LoadStringW(ghInstance, 0x29u, &Buffer, 1024);
          break;
        case 0x9C47u:
          LoadStringW(ghInstance, 0x1Bu, &Buffer, 1024);
          break;
        case 0x9C49u:
          LoadStringW(ghInstance, 0x1Fu, &Buffer, 1024);
          break;
        case 0x9C4Du:
          LoadStringW(ghInstance, 0x24u, &Buffer, 1024);
          break;
        case 0x9C5Eu:
          if ( gConfig.bShowDllView )
            LoadStringW(ghInstance, 0x1Du, &Buffer, 1024);
          else
            LoadStringW(ghInstance, 0x20u, &Buffer, 1024);
          break;
        case 0x9C67u:
          LoadStringW(ghInstance, 0x41Eu, &Buffer, 1024);
          break;
        case 0x9C6Eu:
          if ( gConfig.bShowLowerPane )
            LoadStringW(ghInstance, 0x441u, &Buffer, 1024);
          else
            LoadStringW(ghInstance, 0x440u, &Buffer, 1024);
          break;
        case 0x9C7Cu:
          LoadStringW(ghInstance, 0x4AEu, &Buffer, 1024);
          break;
        case 0x9C7Eu:
          LoadStringW(ghInstance, 0x458u, &Buffer, 1024);
          break;
        case 0x9C7Fu:
          LoadStringW(ghInstance, 0x459u, &Buffer, 1024);
          break;
        case 0x9CADu:
          LoadStringW(ghInstance, 0x4ADu, &Buffer, 1024);
          break;
        default:
          break;
      }
    }
  }
  *(a2 + 12) = &Buffer;
  return 0;
}

//----- (00FFFCA0) --------------------------------------------------------
void __cdecl sub_FFFCA0(CGraphData *pGraphData, __int64 a2)
{
  bool v2; // zf
  HICON v3; // esi
  RECT rc; // [esp+Ch] [ebp-21Ch]
  wchar_t Src; // [esp+1Ch] [ebp-20Ch]

  v2 = dword_106A3C4 == 0;
  _mm_storeu_si128(&rc, _mm_load_si128(&xmmword_1047010));
  if ( !v2 )
  {
    sub_FB2410(&Src, 0x104u, L"Current Commit: ", a2);
    v3 = GraphData_DrawChart(pGraphData, 0, &rc, gConfig.ColorGraphBk, 0, 0.0);
    sub_FC6910(ghMainWnd, dword_106A3C4, v3, &Src);
    DestroyIcon(v3);
  }
}
// 1046CEC: using guessed type wchar_t aCurrentCommit[17];
// 1047010: using guessed type __int128 xmmword_1047010;

//----- (00FFFD50) --------------------------------------------------------
char __cdecl sub_FFFD50(CGraphData *pGraphData, double a2, int a3, double a4)
{
  int v4; // eax
  CGraphData *v5; // edi
  bool v6; // zf
  double v7; // xmm0_8
  signed int v8; // ebx
  HICON v9; // eax
  unsigned int v10; // esi
  unsigned int v11; // eax
  HICON v12; // esi
  ICONINFO piconinfo; // [esp+14h] [ebp-234h]
  CGraphData *v15; // [esp+28h] [ebp-220h]
  RECT rc; // [esp+2Ch] [ebp-21Ch]
  __int16 Dst[260]; // [esp+3Ch] [ebp-20Ch]

  LOBYTE(v4) = dword_1085738;
  v5 = pGraphData;
  v15 = pGraphData;
  if ( !(dword_1085738 & 1) )
  {
    dword_1085728 = 0;
    dword_1085738 |= 1u;
    dword_108572C = 0;
    hdc = 0;
    dword_1085724 = 0;
    LOBYTE(v4) = atexit(sub_102ADC0);
  }
  v6 = byte_108573C == 0;
  _mm_storeu_si128(&rc, _mm_load_si128(&xmmword_1047010));
  if ( v6 )
  {
    byte_108573C = 1;
    LOBYTE(v4) = BitmapItem_Create(&dword_1085724, 16, 16);
  }
  if ( dword_106A3BC || dword_106A3C0 )
  {
    v7 = a2;
    if ( a2 > 100.0 )
    {
      v7 = db_onehundred;
      a2 = db_onehundred;
    }
    if ( pGraphData->m_nItemID )
      v4 = swprintf(Dst, L"GPU Usage: %.0f%%", LODWORD(v7), HIDWORD(v7));
    else
      v4 = swprintf(Dst, L"CPU Usage: %.0f%%", LODWORD(v7), HIDWORD(v7));
    if ( a3 && a4 > 0.5 )
      LOBYTE(v4) = swprintf_s(&Dst[v4], 260 - v4, L"%c%s: %.0f%%", 10, *(a3 + 60), a4);
    v8 = (a2 / 100.0 * 16.0);
    if ( gConfig.bTrayCPUHistory )
    {
      v9 = GraphData_DrawChart(pGraphData, 0, &rc, 0xFFFFFFFF, 0, 0.0);
    }
    else
    {
      if ( a2 == -1.0 )
      {
        v8 = dword_1085740;
      }
      else if ( v8 == dword_1085740 )
      {
        return v4;
      }
      v10 = dword_1085728 * dword_108572C;
      if ( dword_1085734 && v10 )
      {
        memset32(
          dword_1085734,
          (gConfig.ColorGraphBk & 0xFF00) | (LOBYTE(gConfig.ColorGraphBk) << 16) | (gConfig.ColorGraphBk >> 16) & 0xFF,
          v10);
        v5 = v15;
      }
      rc.top = 16 - v8;
      if ( a2 <= 90.0 )
      {
        v11 = 4652870;
        if ( a2 > 70.0 )
          v11 = 10551295;
      }
      else
      {
        v11 = 4605695;
      }
      BitmapItem_SetRectColor(&dword_1085724, &rc, v11);
      piconinfo.hbmColor = dword_1085724;
      piconinfo.hbmMask = dword_1085724;
      piconinfo.fIcon = 1;
      piconinfo.xHotspot = 0;
      piconinfo.yHotspot = 0;
      v9 = CreateIconIndirect(&piconinfo);
    }
    v12 = v9;
    if ( v5->m_nItemID )
      sub_FC6910(ghMainWnd, dword_106A3C0, v9, Dst);
    else
      sub_FC6910(ghMainWnd, dword_106A3BC, v9, Dst);
    LOBYTE(v4) = DestroyIcon(v12);
    dword_1085740 = v8;
  }
  return v4;
}
// 103CDC0: using guessed type double db_onehundred;
// 1046C80: using guessed type wchar_t aCpuUsage0f[18];
// 1047010: using guessed type __int128 xmmword_1047010;
// 106A3BC: using guessed type int dword_106A3BC;
// 1085728: using guessed type int dword_1085728;
// 108572C: using guessed type int dword_108572C;
// 1085734: using guessed type int dword_1085734;
// 1085738: using guessed type int dword_1085738;
// 108573C: using guessed type char byte_108573C;
// 1085740: using guessed type int dword_1085740;
// FFFD50: using guessed type wchar_t Dst[260];

//----- (01000010) --------------------------------------------------------
CGraphData *__cdecl sub_1000010(CGraphData *a1, int a2, __int64 a3, __int64 a4, __int64 a5)
{
  bool v5; // zf
  CGraphData *result; // eax
  int v7; // ebx
  HICON v8; // esi
  RECT rc; // [esp+28h] [ebp-21Ch]
  __int16 Dst[260]; // [esp+38h] [ebp-20Ch]

  v5 = dword_106A3F4 == 0;
  result = a1;
  _mm_storeu_si128(&rc, _mm_load_si128(&xmmword_1047010));
  if ( !v5 )
  {
    v7 = swprintf(Dst, L"Disk\n");
    if ( a2 )
    {
      sub_FB2200(1, &Dst[v7], 260 - v7, a4, a3, a5);
      if ( v7 >= 0 )
        swprintf_s(&Dst[v7], 260 - v7, L"\n%s", *(a2 + 60));
    }
    v8 = GraphData_DrawChart(a1, 0, &rc, gConfig.ColorGraphBk, 0, 0.0);
    sub_FC6910(ghMainWnd, dword_106A3F4, v8, Dst);
    result = DestroyIcon(v8);
  }
  return result;
}
// 1047010: using guessed type __int128 xmmword_1047010;
// 1000010: using guessed type wchar_t Dst[260];

//----- (01000130) --------------------------------------------------------
CGraphData *__cdecl sub_1000130(CGraphData *a1, int a2, __int64 a3, __int64 a4, __int64 a5)
{
  bool v5; // zf
  CGraphData *result; // eax
  int v7; // eax
  int v8; // esi
  HICON v9; // esi
  RECT rc; // [esp+28h] [ebp-21Ch]
  __int16 Dst[260]; // [esp+38h] [ebp-20Ch]

  v5 = dword_106A3C8 == 0;
  result = a1;
  _mm_storeu_si128(&rc, _mm_load_si128(&xmmword_1047010));
  if ( !v5 )
  {
    v7 = swprintf(Dst, L"I/O\n");
    if ( a2 )
    {
      v8 = sub_FB2200(1, &Dst[v7], 260 - v7, a4, a3, a5) + v7;
      if ( v8 >= 0 )
        swprintf_s(&Dst[v8], 260 - v8, L"\n%s", *(a2 + 60));
    }
    v9 = GraphData_DrawChart(a1, 0, &rc, gConfig.ColorGraphBk, 0, 0.0);
    sub_FC6910(ghMainWnd, dword_106A3C8, v9, Dst);
    result = DestroyIcon(v9);
  }
  return result;
}
// 1047010: using guessed type __int128 xmmword_1047010;
// 1000130: using guessed type wchar_t Dst[260];

//----- (01000250) --------------------------------------------------------
CGraphData *__cdecl sub_1000250(CGraphData *a1, int a2, __int64 a3, __int64 a4, __int64 a5)
{
  bool v5; // zf
  CGraphData *result; // eax
  int v7; // eax
  wchar_t *v8; // esi
  size_t v9; // edi
  HICON v10; // esi
  RECT rc; // [esp+28h] [ebp-21Ch]
  __int16 Dst[260]; // [esp+38h] [ebp-20Ch]

  v5 = dword_106A600 == 0;
  result = a1;
  _mm_storeu_si128(&rc, _mm_load_si128(&xmmword_1047010));
  if ( !v5 )
  {
    v7 = swprintf(Dst, L"Network\n");
    if ( a2 )
    {
      v8 = &Dst[v7];
      v9 = 260 - v7;
      sub_FB2200(1, &Dst[v7], 260 - v7, a4, a3, a5);
      swprintf_s(v8, v9, L"\n%s", *(a2 + 60));
    }
    v10 = GraphData_DrawChart(a1, 0, &rc, gConfig.ColorGraphBk, 0, 0.0);
    sub_FC6910(ghMainWnd, dword_106A600, v10, Dst);
    result = DestroyIcon(v10);
  }
  return result;
}
// 1047010: using guessed type __int128 xmmword_1047010;
// 1000250: using guessed type wchar_t Dst[260];

//----- (01000360) --------------------------------------------------------
void __cdecl sub_1000360(CGraphData *pGraphData, __int64 a2)
{
  bool v2; // zf
  HICON v3; // esi
  RECT rc; // [esp+Ch] [ebp-21Ch]
  wchar_t Src; // [esp+1Ch] [ebp-20Ch]

  v2 = dword_106A3F0 == 0;
  _mm_storeu_si128(&rc, _mm_load_si128(&xmmword_1047010));
  if ( !v2 )
  {
    sub_FB2410(&Src, 0x104u, L"Physical Usage: ", a2);
    v3 = GraphData_DrawChart(pGraphData, 0, &rc, gConfig.ColorGraphBk, 0, 0.0);
    sub_FC6910(ghMainWnd, dword_106A3F0, v3, &Src);
    DestroyIcon(v3);
  }
}
// 1046D10: using guessed type wchar_t aPhysicalUsage[17];
// 1047010: using guessed type __int128 xmmword_1047010;

//----- (01000410) --------------------------------------------------------
double *__usercall sub_1000410@<eax>(double a1@<st0>, double st6_0@<st1>, HWND a2, int a3, double *a4, double *a5)
{
  double *result; // eax
  WPARAM v7; // edi
  HDC v8; // esi
  void *v9; // eax
  signed int v10; // esi
  signed int v11; // edx
  DWORD v12; // eax
  __int64 ArgList; // xmm0_8
  char v14; // al
  double v15; // xmm0_8
  int v16; // esi
  HDC v17; // ST04_4
  int v18; // eax
  int v19; // ecx
  HDC v20; // ebx
  char v21; // [esp+8h] [ebp-2D8h]
  struct _FILETIME LocalFileTime; // [esp+14h] [ebp-2CCh]
  double v23; // [esp+1Ch] [ebp-2C4h]
  HGDIOBJ h; // [esp+24h] [ebp-2BCh]
  int v25; // [esp+28h] [ebp-2B8h]
  int v26; // [esp+2Ch] [ebp-2B4h]
  HWND hWnd; // [esp+30h] [ebp-2B0h]
  HDC hdc; // [esp+34h] [ebp-2ACh]
  char v29; // [esp+3Bh] [ebp-2A5h]
  struct _SYSTEMTIME SystemTime; // [esp+3Ch] [ebp-2A4h]
  struct tagRECT rc; // [esp+4Ch] [ebp-294h]
  int lParam[32]; // [esp+5Ch] [ebp-284h]
  __int16 chText[256]; // [esp+DCh] [ebp-204h]

  result = a4;
  v7 = 0;
  hWnd = a2;
  v29 = 0;
  if ( !a2 )
  {
    dword_10610E8 = -1;
    dword_10610EC = -1;
    dword_10610F0 = -1;
    dword_10610F4 = -1;
    dword_10610F8 = -1;
    dword_10610FC = -1;
    dword_1061100 = -1;
    dword_1061104 = -1;
    qword_1061110 = dbl_103CDD8;
    qword_1061108 = dbl_103CDD8;
    qword_1061118 = dbl_103CDD8;
    return result;
  }
  sub_FF7400(0i64, a4, a5, &v23);
  *(a3 + 16) = st6_0;
  *(a3 + 32) = *a5 / v23 * 100.0;
  v8 = GetDC(ghWndStatusBar);
  hdc = v8;
  v9 = SendMessageW(hWnd, 0x31u, 0, 0);
  h = SelectObject(v8, v9);
  SendMessageW(ghWndStatusBar, 0x406u, 0x20u, lParam);
  v10 = 1;
  v11 = 32;
  v25 = 1;
  v26 = 32;
  do
  {
    v12 = gConfig.dwStatusBarColumns & v10;
    if ( gConfig.dwStatusBarColumns & v10 )
    {
      if ( v12 > 0x80 )
      {
        if ( v12 > 0x800 )
        {
          switch ( v12 )
          {
            case 0x1000u:
              v16 = sub_FFF9B0(chText, 0xFFFFFFFF, L"Refresh: ", v21);
              FileTimeToLocalFileTime(&gTimeQuerySystemInfo, &LocalFileTime);
              FileTimeToSystemTime(&LocalFileTime, &SystemTime);
              GetTimeFormatW(0x400u, 0, &SystemTime, 0, &chText[v16], 256 - v16);
              v10 = v25;
              break;
            case 0x2000u:
              if ( *(a3 + 32) == *&qword_1061128 )
              {
                v14 = v29;
                if ( !v29 )
                {
                  ++v7;
                  goto LABEL_86;
                }
              }
              wsprintf(chText, L"Physical Usage: %02.2f%%", *(a3 + 32));
              qword_1061128 = *(a3 + 32);
              break;
            case 0x4000u:
              if ( *(a3 + 40) == *&qword_1061130 )
              {
                v14 = v29;
                if ( !v29 )
                {
                  ++v7;
                  goto LABEL_86;
                }
              }
              wsprintf(chText, L"Own Physical Usage: %02.2f%%", *(a3 + 40));
              qword_1061130 = *(a3 + 40);
              break;
          }
        }
        else
        {
          switch ( v12 )
          {
            case 0x800u:
              if ( *(a3 + 68) == dword_10610FC )
              {
                v14 = v29;
                if ( !v29 )
                {
                  ++v7;
                  goto LABEL_86;
                }
              }
              wsprintf(chText, L"Own Handles: %d", *(a3 + 68));
              dword_10610FC = *(a3 + 68);
              break;
            case 0x100u:
              if ( *(a3 + 56) == dword_10610F0 )
              {
                v14 = v29;
                if ( !v29 )
                {
                  ++v7;
                  goto LABEL_86;
                }
              }
              wsprintf(chText, L"Threads: %d", *(a3 + 56));
              dword_10610F0 = *(a3 + 56);
              break;
            case 0x200u:
              if ( *(a3 + 60) == dword_10610F4 )
              {
                v14 = v29;
                if ( !v29 )
                {
                  ++v7;
                  goto LABEL_86;
                }
              }
              wsprintf(chText, L"Own Threads: %d", *(a3 + 60));
              dword_10610F4 = *(a3 + 60);
              break;
            case 0x400u:
              if ( *(a3 + 64) == dword_10610F8 )
              {
                v14 = v29;
                if ( !v29 )
                {
                  ++v7;
                  goto LABEL_86;
                }
              }
              wsprintf(chText, L"Handles: %d", *(a3 + 64));
              dword_10610F8 = *(a3 + 64);
              break;
          }
        }
      }
      else if ( v12 == 128 )
      {
        if ( *(a3 + 76) == dword_1061104 )
        {
          v14 = v29;
          if ( !v29 )
          {
            ++v7;
            goto LABEL_86;
          }
        }
        wsprintf(chText, L"Own .NET Processes: %d", *(a3 + 76));
        dword_1061104 = *(a3 + 76);
      }
      else
      {
        switch ( v12 )
        {
          case 1u:
            ArgList = *a3;
            if ( *a3 == *&qword_1061110 )
            {
              v14 = v29;
              if ( !v29 )
              {
                ++v7;
                goto LABEL_86;
              }
            }
            if ( gConfig.bShowCpuFractions )
              wsprintf(chText, L"CPU Usage: %02.2f%%", ArgList);
            else
              wsprintf(chText, L"CPU Usage: %0.0f%%", ArgList);
            qword_1061110 = *a3;
            break;
          case 2u:
            v15 = *(a3 + 8);
            if ( v15 == *&qword_1061108 )
            {
              v14 = v29;
              if ( !v29 )
              {
                ++v7;
                goto LABEL_86;
              }
            }
            if ( gConfig.bShowCpuFractions )
              wsprintf(chText, L"Own CPU Usage: %02.2f%%", SLOBYTE(v15));
            else
              wsprintf(chText, L"Own CPU Usage: %0.0f%%", SLOBYTE(v15));
            qword_1061108 = *(a3 + 8);
            break;
          case 4u:
            if ( *(a3 + 16) == *&qword_1061118 )
            {
              v14 = v29;
              if ( !v29 )
              {
                ++v7;
                goto LABEL_86;
              }
            }
            wsprintf(chText, L"Commit Charge: %02.2f%%", *(a3 + 16));
            qword_1061118 = *(a3 + 16);
            break;
          case 8u:
            if ( *(a3 + 24) == *&qword_1061120 )
            {
              v14 = v29;
              if ( !v29 )
              {
                ++v7;
                goto LABEL_86;
              }
            }
            wsprintf(chText, L"Own Commit Charge: %02.2f%%", *(a3 + 24));
            qword_1061120 = *(a3 + 24);
            break;
          case 0x10u:
            if ( *(a3 + 48) == dword_10610E8 )
            {
              v14 = v29;
              if ( !v29 )
              {
                ++v7;
                goto LABEL_86;
              }
            }
            wsprintf(chText, L"Processes: %d", *(a3 + 48));
            dword_10610E8 = *(a3 + 48);
            break;
          case 0x20u:
            if ( *(a3 + 52) == dword_10610EC )
            {
              v14 = v29;
              if ( !v29 )
              {
                ++v7;
                goto LABEL_86;
              }
            }
            wsprintf(chText, L"Own Processes: %d", *(a3 + 52));
            dword_10610EC = *(a3 + 52);
            break;
          case 0x40u:
            if ( *(a3 + 72) == dword_1061100 )
            {
              v14 = v29;
              if ( !v29 )
              {
                ++v7;
                goto LABEL_86;
              }
            }
            wsprintf(chText, &off_1046EFC, *(a3 + 72));
            dword_1061100 = *(a3 + 72);
            break;
          default:
            break;
        }
      }
      v17 = hdc;
      _mm_storeu_si128(&rc, 0i64);
      DrawTextW(v17, chText, -1, &rc, 0xD20u);
      v18 = rc.right + 10;
      rc.right += 10;
      if ( v7 )
        v19 = lParam[v7] - *(&rc.bottom + v7);
      else
        v19 = lParam[0];
      if ( v19 < v18 )
      {
        v29 = 1;
        lParam[v7] += v18 - v19;
      }
      SendMessageW(hWnd, 0x40Bu, v7, chText);
      v11 = v26;
      ++v7;
    }
    v14 = v29;
LABEL_86:
    v10 = __ROL4__(v10, 1);
    --v11;
    v25 = v10;
    v26 = v11;
  }
  while ( v11 );
  if ( v14 )
  {
    lParam[v7] = -1;
    SendMessageW(ghWndStatusBar, 0x404u, v7 + 1, lParam);
  }
  v20 = hdc;
  SelectObject(hdc, h);
  return ReleaseDC(ghWndStatusBar, v20);
}
// 103CDC0: using guessed type double db_onehundred;
// 1046D34: using guessed type wchar_t aCpuUsage022f[20];
// 1046D84: using guessed type wchar_t aOwnCpuUsage022[24];
// 10610E8: using guessed type int dword_10610E8;
// 10610EC: using guessed type int dword_10610EC;
// 10610F0: using guessed type int dword_10610F0;
// 10610F4: using guessed type int dword_10610F4;
// 10610F8: using guessed type int dword_10610F8;
// 10610FC: using guessed type int dword_10610FC;
// 1061100: using guessed type int dword_1061100;
// 1061104: using guessed type int dword_1061104;
// 1061108: using guessed type __int64 qword_1061108;
// 1061110: using guessed type __int64 qword_1061110;
// 1061118: using guessed type __int64 qword_1061118;
// 1061120: using guessed type __int64 qword_1061120;
// 1061128: using guessed type __int64 qword_1061128;
// 1061130: using guessed type __int64 qword_1061130;
// 1000410: using guessed type LPARAM lParam[32];
// 1000410: using guessed type WCHAR chText[256];

//----- (01000BB0) --------------------------------------------------------
HWND __cdecl InitToolbar(HWND hWnd, unsigned int nIDToolbar)
{
  unsigned int v3; // edi
  WPARAM nBandIndex; // edi
  unsigned int nIndex; // esi
  LRESULT v6; // eax
  bool fBreak; // zf
  LPARAM lParam; // [esp+0h] [ebp-1B0h]
  int v9; // [esp+4h] [ebp-1ACh]
  INITCOMMONCONTROLSEX picce; // [esp+Ch] [ebp-1A4h]
  tagREBARBANDINFOW RebarBandInfo; // [esp+14h] [ebp-19Ch]
  RECT rcItem1; // [esp+64h] [ebp-14Ch]
  RECT rcItem2; // [esp+74h] [ebp-13Ch]
  struct tagRECT rect; // [esp+84h] [ebp-12Ch]
  TBBUTTON buttons[14]; // [esp+94h] [ebp-11Ch]

  buttons[0].iBitmap = BMP_SAVE;
  buttons[0].idCommand = IDM_FILE_SAVE;
  *&buttons[0].fsState = 4;
  *&buttons[0].dwData = 0i64;
  buttons[1].iBitmap = 0;
  buttons[1].idCommand = 0;
  *&buttons[1].fsState = 0x104;
  *&buttons[1].dwData = 0i64;
  buttons[2].iBitmap = BMP_REFRESH;
  buttons[2].idCommand = IDM_VIEW_REFRESH_NOW;
  *&buttons[2].fsState = 4;
  *&buttons[2].dwData = 0i64;
  buttons[3].iBitmap = 0;
  buttons[3].idCommand = 0;
  *&buttons[3].fsState = 0x104;
  *&buttons[3].dwData = 0i64;
  buttons[4].iBitmap = BMP_VIEW_SYSTEM_INFORMATION;
  buttons[4].idCommand = IDM_TRAYMENU_CONTEXT_SYSTEM_INFORMATION;
  *&buttons[4].fsState = 4;
  *&buttons[4].dwData = 0i64;
  buttons[5].iBitmap = BMP_SHOW_PROCESS_TREE;
  buttons[5].idCommand = IDM_VIEW_SHOW_PROCESS_TREE;
  *&buttons[5].fsState = 4;
  *&buttons[5].dwData = 0i64;
  buttons[6].iBitmap = BMP_SHOW_LOWER_PANE;
  buttons[6].idCommand = IDM_VIEW_SHOW_LOWER_PANE;
  *&buttons[6].fsState = 4;
  *&buttons[6].dwData = 0i64;
  buttons[7].iBitmap = BMP_VIEW_HANDLES;
  buttons[7].idCommand = IDM_POPUP_DLL_PROPERTIES;
  *&buttons[7].fsState = 4;
  *&buttons[7].dwData = 0i64;
  buttons[8].iBitmap = 0;
  buttons[8].idCommand = 0;
  *&buttons[8].fsState = 260;
  *&buttons[8].dwData = 0i64;
  buttons[9].iBitmap = BMP_PROPERTIES;
  buttons[9].idCommand = IDM_VIEW_PROCESS_PROPERTIES;
  *&buttons[9].fsState = 4;
  *&buttons[9].dwData = 0i64;
  buttons[10].iBitmap = BMP_KILL_PROCESS;
  buttons[10].idCommand = IDM_PROCESS_KILL_PROCESS;
  *&buttons[10].fsState = 4;
  *&buttons[10].dwData = 0i64;
  buttons[11].iBitmap = 0;
  buttons[11].idCommand = 0;
  *&buttons[11].fsState = 260;
  *&buttons[11].dwData = 0i64;
  buttons[12].iBitmap = 2;
  buttons[12].idCommand = IDM_SEARCH_IN_PROCESS;
  *&buttons[12].fsState = 4;
  *&buttons[12].dwData = 0i64;
  buttons[13].iBitmap = BMP_FIND_PROCESS_BY_WINDOW;
  buttons[13].idCommand = IDM_FIND_PROCESS_BY_WINDOW;
  *&buttons[13].fsState = 4;
  *&buttons[13].dwData = 0i64;
  picce.dwSize = 8;
  picce.dwICC = 1540;
  InitCommonControlsEx(&picce);
  ghWndReBar = CreateWindowExW(
                 WS_EX_TOOLWINDOW,
                 L"ReBarWindow32",
                 0,
                 0x56800448u,
                 0,
                 0,
                 400,
                 275,
                 hWnd,
                 0,
                 ghInstance,
                 0);
  lParam = 12;
  v9 = 0;
  if ( !SendMessageW(ghWndReBar, RB_SETBARINFO, 0, &lParam) )
    return 0;
  ghWndToolbar = CreateToolbarEx(
                   ghWndReBar,
                   0x56000944u,
                   nIDToolbar,
                   12,
                   ghInstance,
                   108u,
                   buttons,
                   14,
                   0,
                   0,
                   0,
                   0,
                   20u);
  if ( !ghWndToolbar )
    return 0;
  v3 = GetButtonSize();
  SendMessageW(ghWndToolbar, TB_GETRECT, 0x9C49u, &rcItem1);
  SendMessageW(ghWndToolbar, TB_GETRECT, 0x9CADu, &rcItem2);
  UnionRect(&rect, &rcItem1, &rcItem2);
  memset(&RebarBandInfo, 0, sizeof(tagREBARBANDINFOW));
  RebarBandInfo.cbSize = sizeof(tagREBARBANDINFOW);
  RebarBandInfo.fMask = 0x173;
  RebarBandInfo.fStyle = 0x80;
  RebarBandInfo.hwndChild = ghWndToolbar;
  RebarBandInfo.cxMinChild = 0;
  RebarBandInfo.clrFore = GetSysColor(COLOR_BTNTEXT);
  RebarBandInfo.clrBack = GetSysColor(COLOR_BTNFACE);
  RebarBandInfo.cx = rect.right - rect.left;
  RebarBandInfo.cxMinChild = rect.right - rect.left;
  RebarBandInfo.cyMinChild = v3 >> 16;
  RebarBandInfo.wID = 0;
  SendMessageW(ghWndReBar, RB_INSERTBANDW, 0xFFFFFFFF, &RebarBandInfo);
  ghWndCPUGraph = CreateWindowExW(
                    0,
                    L"CpuGraphClassGraph",
                    &gszNullString,
                    0x56010004u,
                    0,
                    0,
                    0,
                    0,
                    ghWndReBar,
                    2000,
                    ghInstance,
                    gpGraphInfoOfCPU);
  RebarBandInfo.hwndChild = ghWndCPUGraph;
  RebarBandInfo.cx = MulDiv(75, gLogPixelSize.x, 96);
  RebarBandInfo.cxMinChild = 0;
  RebarBandInfo.wID = 1;
  SendMessageW(ghWndReBar, RB_INSERTBANDW, 0xFFFFFFFF, &RebarBandInfo);
  ghWndMemoryGraph = CreateWindowExW(
                       0,
                       L"CpuGraphClassGraph",
                       &gszNullString,
                       0x56010004u,
                       0,
                       0,
                       0,
                       0,
                       ghWndReBar,
                       2000,
                       ghInstance,
                       gpGraphInfoOfMemory);
  RebarBandInfo.hwndChild = ghWndMemoryGraph;
  RebarBandInfo.cx = MulDiv(75, gLogPixelSize.x, 96);
  RebarBandInfo.cxMinChild = 0;
  RebarBandInfo.wID = 2;
  SendMessageW(ghWndReBar, RB_INSERTBANDW, 0xFFFFFFFF, &RebarBandInfo);
  ghWndPhysicalMemoryGraph = CreateWindowExW(
                               0,
                               L"CpuGraphClassGraph",
                               &gszNullString,
                               0x56010004u,
                               0,
                               0,
                               0,
                               0,
                               ghWndReBar,
                               IDC_GRAPH_IN_REBAR,
                               ghInstance,
                               gpGraphInfoOfPhysicalMemory);
  RebarBandInfo.hwndChild = ghWndPhysicalMemoryGraph;
  RebarBandInfo.cx = MulDiv(75, gLogPixelSize.x, 96);
  RebarBandInfo.cxMinChild = 0;
  RebarBandInfo.wID = 3;
  SendMessageW(ghWndReBar, RB_INSERTBANDW, 0xFFFFFFFF, &RebarBandInfo);
  if ( gIOGraphInfo.pGraphData )
  {
    ghWndIOGraphCtrl = CreateWindowExW(
                         0,
                         L"CpuGraphClassGraph",
                         &gszNullString,
                         0x56010004u,
                         0,
                         0,
                         0,
                         0,
                         ghWndReBar,
                         2000,
                         ghInstance,
                         gIOGraphInfo.pGraphData);
    RebarBandInfo.hwndChild = ghWndIOGraphCtrl;
    RebarBandInfo.cx = MulDiv(75, gLogPixelSize.x, 96);
    RebarBandInfo.cxMinChild = 0;
    RebarBandInfo.wID = 4;
    SendMessageW(ghWndReBar, RB_INSERTBANDW, 0xFFFFFFFF, &RebarBandInfo);
  }
  if ( IsBuiltinAdministrative() && gNetworkGraphInfo.pGraphData )
  {
    ghWndNetworkGraph = CreateWindowExW(
                          0,
                          L"CpuGraphClassGraph",
                          &gszNullString,
                          0x56010004u,
                          0,
                          0,
                          0,
                          0,
                          ghWndReBar,
                          IDC_GRAPH_IN_REBAR,
                          ghInstance,
                          gNetworkGraphInfo.pGraphData);
    RebarBandInfo.hwndChild = ghWndNetworkGraph;
    RebarBandInfo.cx = MulDiv(75, gLogPixelSize.x, 96);
    RebarBandInfo.cxMinChild = 0;
    RebarBandInfo.wID = 5;
    SendMessageW(ghWndReBar, RB_INSERTBANDW, 0xFFFFFFFF, &RebarBandInfo);
  }
  if ( IsBuiltinAdministrative() && gDiskGraphInfo.pGraphData )
  {
    ghWndDiskGraph = CreateWindowExW(
                       0,
                       L"CpuGraphClassGraph",
                       &gszNullString,
                       0x56010004u,
                       0,
                       0,
                       0,
                       0,
                       ghWndReBar,
                       IDC_GRAPH_IN_REBAR,
                       ghInstance,
                       gDiskGraphInfo.pGraphData);
    RebarBandInfo.hwndChild = ghWndDiskGraph;
    RebarBandInfo.cx = MulDiv(75, gLogPixelSize.x, 96);
    RebarBandInfo.cxMinChild = 0;
    RebarBandInfo.wID = 6;
    SendMessageW(ghWndReBar, RB_INSERTBANDW, 0xFFFFFFFF, &RebarBandInfo);
  }
  if ( gdwAdapterRuntingTime )
  {
    ghWndGPUGraph = CreateWindowExW(
                      0,
                      L"CpuGraphClassGraph",
                      &gszNullString,
                      0x56010004u,
                      0,
                      0,
                      0,
                      0,
                      ghWndReBar,
                      IDC_GRAPH_IN_REBAR,
                      ghInstance,
                      gpGraphInfoOfGPU);
    RebarBandInfo.hwndChild = ghWndGPUGraph;
    RebarBandInfo.cx = MulDiv(75, gLogPixelSize.x, 96);
    RebarBandInfo.cxMinChild = 0;
    RebarBandInfo.wID = 7;
    SendMessageW(ghWndReBar, RB_INSERTBANDW, 0xFFFFFFFF, &RebarBandInfo);
  }
  if ( gConfig.ToolBandInfo[0].nWidth != -1 )
  {
    nBandIndex = 0;
    nIndex = 0;
    do
    {
      v6 = SendMessageW(ghWndReBar, RB_IDTOINDEX, gConfig.ToolBandInfo[nIndex].nID, 0);
      SendMessageW(ghWndReBar, RB_MOVEBAND, v6, nBandIndex);
      SendMessageW(ghWndReBar, RB_GETBANDINFOW, nBandIndex, &RebarBandInfo);
      fBreak = gConfig.ToolBandInfo[nIndex].fBreak == 0;
      RebarBandInfo.fMask = 0x141;              // RBBIM_STYLE|RBBIM_SIZE|RBBIM_ID
      if ( fBreak )
        RebarBandInfo.fStyle &= -2u;
      else
        RebarBandInfo.fStyle |= RBBS_BREAK;
      RebarBandInfo.cx = MulDiv(gConfig.ToolBandInfo[nIndex].nWidth, gLogPixelSize.x, 96);
      RebarBandInfo.wID = gConfig.ToolBandInfo[nIndex].nID;
      SendMessageW(ghWndReBar, RB_SETBANDINFOW, nBandIndex, &RebarBandInfo);
      ++nIndex;
      ++nBandIndex;
    }
    while ( nIndex < 8 );
  }
  return ghWndToolbar;
}

//----- (010013B0) --------------------------------------------------------
LPARAM GetButtonSize()
{
  int v0; // edi
  unsigned __int16 v1; // ax
  LPARAM v2; // esi

  v0 = GetSystemMetrics(50) << 16;
  v1 = GetSystemMetrics(49);
  SendMessageW(ghWndToolbar, 0x420u, 0, v0 | v1);
  v2 = SendMessageW(ghWndToolbar, 0x43Au, 0, 0);
  SendMessageW(ghWndToolbar, 0x420u, 0, 983056);
  SendMessageW(ghWndToolbar, 0x41Fu, 0, v2);
  return v2;
}

//----- (01001420) --------------------------------------------------------
_DWORD *__stdcall std::_List_buy<tagEventItem *,std::allocator<tagEventItem *>>::_Buynode<tagEventItem * const &>(EventList *a1, _DWORD *a2, _DWORD *a3)
{
  _DWORD *result; // eax

  result = std::_List_alloc<std::_List_base_types<tagEventItem *,std::allocator<tagEventItem *>>>::_Buynode0(a1, a2);
  if ( result != -8 )
    result[2] = *a3;
  return result;
}

//----- (01001440) --------------------------------------------------------
CSystemProcessInfoMapNode **__thiscall sub_1001440(CSystemProcessInfoMap *this, CSystemProcessInfoMapNode **a2, char a3, CSystemProcessInfoMapNode *a4, int *a5, int a6)
{
  CSystemProcessInfoMap *v6; // edi
  CSystemProcessInfoMapNode *v7; // eax
  CSystemProcessInfoMapNode *v8; // ebx
  std__Tree_node *v9; // eax
  std__Tree_node *v10; // eax
  std__Tree_node *v11; // ecx
  std__Tree_node *v12; // esi
  std__Tree_node *v13; // edx
  std__Tree_node *v14; // edx
  std__Tree_node *v15; // ecx
  std__Tree_node *v16; // edx
  std__Tree_node *v17; // esi
  std__Tree_node_For__bstr_t *v18; // ecx
  std__Tree_node *v19; // ecx
  std__Tree_node *v20; // edx
  std__Tree_node_For__bstr_t *v21; // ecx
  std__Tree_node *v22; // ecx
  std__Tree_node *v23; // ecx
  CSystemProcessInfoMapNode **result; // eax

  v6 = this;
  if ( this->_Size >= 0xAAAAAA9u )
    std::_Xlength_error("map/set<T> too long");
  v7 = sub_F91310(this, a5);
  ++v6->_Size;
  v8 = v7;
  v7->baseclass._Parent = a4;
  if ( a4 == v6->_Header )
  {
    v6->_Header->_Parent = v7;
    v6->_Header->_Left = v7;
    v9 = v6->_Header;
LABEL_8:
    v9->_Right = v8;
    goto LABEL_9;
  }
  if ( !a3 )
  {
    a4->baseclass._Right = v7;
    v9 = v6->_Header;
    if ( a4 != v6->_Header->_Right )
      goto LABEL_9;
    goto LABEL_8;
  }
  a4->baseclass._Left = v7;
  if ( a4 == v6->_Header->_Left )
    v6->_Header->_Left = v7;
LABEL_9:
  v10 = v8;
  if ( !v8->baseclass._Parent->baseclass._Color )
  {
    do
    {
      v11 = v10->_Parent;
      v12 = v11->_Parent;
      v13 = v12->_Left;
      if ( v11 == v12->_Left )
      {
        v13 = v12->_Right;
        if ( v13->_Color )
        {
          if ( v10 == v11->_Right )
          {
            v10 = v10->_Parent;
            v14 = v11->_Right;
            v11->_Right = v14->_Left;
            if ( !v14->_Left->_IsNil )
              v14->_Left->_Parent = v11;
            v14->_Parent = v11->_Parent;
            if ( v11 == v6->_Header->_Parent )
            {
              v6->_Header->_Parent = v14;
            }
            else
            {
              v15 = v11->_Parent;
              if ( v10 == v15->_Left )
                v15->_Left = v14;
              else
                v15->_Right = v14;
            }
            v14->_Left = v10;
            v10->_Parent = v14;
          }
          v10->_Parent->_Color = 1;
          v10->_Parent->_Parent->_Color = 0;
          v16 = v10->_Parent->_Parent;
          v17 = v16->_Left;
          v16->_Left = v16->_Left->_Right;
          v18 = v17->_Right;
          if ( !v18->_IsNil )
            v18->_Parent = v16;
          v17->_Parent = v16->_Parent;
          if ( v16 == v6->_Header->_Parent )
          {
            v6->_Header->_Parent = v17;
            v17->_Right = v16;
          }
          else
          {
            v19 = v16->_Parent;
            if ( v16 == v19->_Right )
              v19->_Right = v17;
            else
              v19->_Left = v17;
            v17->_Right = v16;
          }
LABEL_48:
          v16->_Parent = v17;
          continue;
        }
      }
      else if ( v13->_Color )
      {
        if ( v10 == v11->_Left )
        {
          v10 = v10->_Parent;
          v20 = v11->_Left;
          v11->_Left = v11->_Left->_Right;
          v21 = v20->_Right;
          if ( !v21->_IsNil )
            v21->_Parent = v10;
          v20->_Parent = v10->_Parent;
          if ( v10 == v6->_Header->_Parent )
          {
            v6->_Header->_Parent = v20;
          }
          else
          {
            v22 = v10->_Parent;
            if ( v10 == v22->_Right )
              v22->_Right = v20;
            else
              v22->_Left = v20;
          }
          v20->_Right = v10;
          v10->_Parent = v20;
        }
        v10->_Parent->_Color = 1;
        v10->_Parent->_Parent->_Color = 0;
        v16 = v10->_Parent->_Parent;
        v17 = v16->_Right;
        v16->_Right = v17->_Left;
        if ( !v17->_Left->_IsNil )
          v17->_Left->_Parent = v16;
        v17->_Parent = v16->_Parent;
        if ( v16 == v6->_Header->_Parent )
        {
          v6->_Header->_Parent = v17;
        }
        else
        {
          v23 = v16->_Parent;
          if ( v16 == v23->_Left )
            v23->_Left = v17;
          else
            v23->_Right = v17;
        }
        v17->_Left = v16;
        goto LABEL_48;
      }
      v11->_Color = 1;
      v13->_Color = 1;
      v10->_Parent->_Parent->_Color = 0;
      v10 = v10->_Parent->_Parent;
    }
    while ( !v10->_Parent->_Color );
  }
  v6->_Header->_Parent->_Color = 1;
  result = a2;
  *a2 = v8;
  return result;
}

//----- (01001650) --------------------------------------------------------
int __thiscall sub_1001650(CSystemProcessInfoMap *this, int a2, CSystemProcessInfoMapNode *a3, int *a4, int a5)
{
  CSystemProcessInfoMap *v5; // edx
  CSystemProcessInfoMapNode *v6; // ecx
  bool v7; // al
  int *v8; // ebx
  CSystemProcessInfoMapNode *v9; // esi
  Data_t_bstr_t *v10; // ecx
  Data_t_bstr_t *v11; // ecx
  CSystemProcessInfoMapNode *v12; // esi
  CSystemProcessInfoMapNode **v13; // eax
  CSystemProcessInfoMapNode *v14; // ecx
  int result; // eax
  Data_t_bstr_t *v16; // ecx
  Data_t_bstr_t *v17; // [esp-8h] [ebp-34h]
  Data_t_bstr_t *v18; // [esp-8h] [ebp-34h]
  Data_t_bstr_t *v19; // [esp-8h] [ebp-34h]
  Data_t_bstr_t *v20; // [esp-4h] [ebp-30h]
  Data_t_bstr_t *v21; // [esp-4h] [ebp-30h]
  Data_t_bstr_t *v22; // [esp-4h] [ebp-30h]
  int v23; // [esp+0h] [ebp-2Ch]
  CSystemProcessInfoMap *v24; // [esp+10h] [ebp-1Ch]
  int v25; // [esp+14h] [ebp-18h]
  CSystemProcessInfoMapNode *v26; // [esp+18h] [ebp-14h]
  int *v27; // [esp+1Ch] [ebp-10h]
  int v28; // [esp+28h] [ebp-4h]

  v27 = &v23;
  v5 = this;
  v24 = this;
  v6 = this->_Header;
  v7 = 1;
  v8 = a4;
  v28 = 0;
  v9 = v6->baseclass._Parent;
  v26 = v6;
  LOBYTE(v25) = 1;
  if ( !v9->baseclass._isnil )
  {
    do
    {
      v26 = v9;
      if ( a3 )
      {
        v20 = *v8;
        if ( *v8 )
          InterlockedIncrement((*v8 + 8));
        v10 = v9->_Keyvalue._Key;
        v17 = v10;
        if ( v10 )
          InterlockedIncrement(&v10->m_RefCount);
        v7 = sub_F914B0(v17, v20) == 0;
      }
      else
      {
        v11 = v9->_Keyvalue._Key;
        v21 = v11;
        if ( v11 )
          InterlockedIncrement(&v11->m_RefCount);
        v18 = *v8;
        if ( *v8 )
          InterlockedIncrement(&v18->m_RefCount);
        v7 = sub_F914B0(v18, v21);
      }
      LOBYTE(v25) = v7;
      if ( v7 )
        v9 = v9->baseclass._Left;
      else
        v9 = v9->baseclass._Right;
    }
    while ( !v9->baseclass._isnil );
    v6 = v26;
    v5 = v24;
  }
  v12 = v6;
  a3 = v6;
  if ( v7 )
  {
    if ( v6 == v5->_Header->_Left )
    {
      v13 = sub_1001440(v5, &a3, 1, v6, v8, a5);
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
  v22 = *v8;
  if ( *v8 )
    InterlockedIncrement(&v22->m_RefCount);
  v16 = v12->_Keyvalue._Key;
  v19 = v16;
  if ( v16 )
    InterlockedIncrement(&v16->m_RefCount);
  if ( sub_F914B0(v19, v22) )
  {
    v13 = sub_1001440(v24, &a4, v25, v26, v8, a5);
    goto LABEL_21;
  }
  result = a2;
  *a2 = v12;
  *(a2 + 4) = 0;
  return result;
}
// 10081AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);

//----- (010017E0) --------------------------------------------------------
char SubmitExeToVirusTotalDotCom()
{
  char result; // al

  result = AskForAgreementLicense(ghMainWnd, L"Process Explorer", 0, 0, aYouMustAgreeTo_2);
  gbAgreenmentLicensed = result;
  if ( result )
  {
    StartVirusTotalCheck();
    result = gbAgreenmentLicensed;
  }
  return result;
}
// 1061138: using guessed type wchar_t aYouMustAgreeTo_2[298];
// 1085774: using guessed type char gbAgreenmentLicensed;

//----- (01001820) --------------------------------------------------------
char __cdecl sub_1001820(ListItemData1 *a1)
{
  char result; // al

  result = 0;
  if ( a1 && (a1->field_4 == 1 || a1->field_4 == 4) )
    result = 1;
  return result;
}

//----- (01001840) --------------------------------------------------------
BOOL __cdecl sub_1001840(LPCWSTR lpFileName, wchar_t *Dest, int a3)
{
  wchar_t *v3; // edi
  BOOL v4; // ebx
  HANDLE v5; // eax
  void *v6; // esi
  DWORD v7; // eax
  DWORD v8; // ecx
  DWORD v9; // edx
  SIZE_T v10; // esi
  const BYTE *v11; // eax
  bool v12; // zf
  HCRYPTHASH v13; // ST08_4
  DWORD v14; // esi
  HANDLE v16; // [esp+Ch] [ebp-48h]
  const BYTE *dwFileOffsetHigh_4; // [esp+14h] [ebp-40h]
  DWORD v18; // [esp+18h] [ebp-3Ch]
  DWORD v19; // [esp+1Ch] [ebp-38h]
  LPFILETIME lpCreationTime; // [esp+20h] [ebp-34h]
  HCRYPTPROV phProv; // [esp+24h] [ebp-30h]
  HCRYPTHASH phHash; // [esp+28h] [ebp-2Ch]
  DWORD pdwDataLen; // [esp+2Ch] [ebp-28h]
  BYTE pbData; // [esp+30h] [ebp-24h]
  __int128 v25; // [esp+31h] [ebp-23h]
  __int64 v26; // [esp+41h] [ebp-13h]
  int v27; // [esp+49h] [ebp-Bh]
  __int16 v28; // [esp+4Dh] [ebp-7h]
  char v29; // [esp+4Fh] [ebp-5h]

  v3 = Dest;
  v4 = 0;
  phProv = 0;
  phHash = 0;
  v5 = CreateFileW(lpFileName, 0x80000000, 7u, 0, 3u, 0, 0);
  v6 = v5;
  v16 = v5;
  if ( v5 == -1 )
    return v4 != 0;
  GetFileTime(v5, a3, 0, 0);
  v4 = CryptAcquireContextW(&phProv, 0, 0, 0x18u, 0xF0000000);
  if ( !v4 )
  {
    v4 = CryptAcquireContextW(&phProv, 0, 0, 1u, 0xF0000000);
    if ( !v4 )
      goto LABEL_24;
  }
  if ( !CryptCreateHash(phProv, 0x8004u, 0, 0, &phHash) )
    goto LABEL_23;
  lpCreationTime = CreateFileMappingW(v6, 0, 2u, 0, 0, 0);
  if ( !lpCreationTime )
  {
    v4 = 0;
    goto LABEL_22;
  }
  v7 = GetFileSize(v6, 0);
  v19 = v7;
  v4 = 1;
  if ( !v7 )
    goto LABEL_16;
  v8 = 0;
  v9 = 0;
  v18 = 0;
  pdwDataLen = 0;
  while ( 1 )
  {
    v10 = v7;
    if ( v7 > 0x100000 )
      v10 = 0x100000;
    v11 = MapViewOfFile(lpCreationTime, 4u, v8, v9, v10);
    dwFileOffsetHigh_4 = v11;
    if ( !v11 )
      goto LABEL_13;
    if ( !CryptHashData(phHash, v11, v10, 0) )
      break;
    v11 = dwFileOffsetHigh_4;
LABEL_13:
    UnmapViewOfFile(v11);
    v8 = (v10 + __PAIR__(v18, pdwDataLen)) >> 32;
    v9 = v10 + pdwDataLen;
    pdwDataLen += v10;
    v7 = v19 - v10;
    v12 = v19 == v10;
    v18 = v8;
    v19 -= v10;
    if ( v12 )
      goto LABEL_16;
  }
  v4 = 0;
LABEL_16:
  CloseHandle(lpCreationTime);
  if ( v4 )
  {
    pbData = 0;
    v27 = 0;
    v13 = phHash;
    v28 = 0;
    _mm_storeu_si128(&v25, 0i64);
    v29 = 0;
    v26 = 0i64;
    pdwDataLen = 32;
    if ( CryptGetHashParam(v13, 2u, &pbData, &pdwDataLen, 0) )
    {
      v14 = 0;
      if ( pdwDataLen )
      {
        do
        {
          _swprintf(v3, L"%02X", *(&pbData + v14++));
          v3 += 2;
        }
        while ( v14 < pdwDataLen );
      }
    }
  }
LABEL_22:
  CryptDestroyHash(phHash);
  v6 = v16;
LABEL_23:
  CryptReleaseContext(phProv, 0);
LABEL_24:
  CloseHandle(v6);
  return v4 != 0;
}

//----- (01001A50) --------------------------------------------------------
int __cdecl sub_1001A50(int pHash, wchar_t *Dest)
{
  int result; // eax
  const wchar_t *v3; // edx
  const wchar_t *v4; // edx
  const wchar_t *v5; // edx
  char **v6; // edx
  char *v7; // edx
  char *v8; // ecx
  _DWORD *v9; // eax

  result = 0;
  *Dest = 0;
  if ( pHash )
  {
    result = *(pHash + 4) - 1;
    switch ( *(pHash + 4) )
    {
      case 1:
      case 6:
        v9 = *(pHash + 40);
        if ( v9 )
          result = _swprintf(Dest, L"%s", *v9);
        else
          result = _swprintf(Dest, L"%s", 0);
        break;
      case 2:
        v3 = L"Hash submitted...";
        do
        {
          result = *v3;
          ++v3;
          *(v3 + Dest - L"Hash submitted..." - 2) = result;
        }
        while ( result );
        break;
      case 3:
        v5 = L"File submitted...";
        do
        {
          result = *v5;
          ++v5;
          *(v5 + Dest - L"File submitted..." - 2) = result;
        }
        while ( result );
        break;
      case 4:
        v4 = L"Scanning file...";
        do
        {
          result = *v4;
          ++v4;
          *(v4 + Dest - L"Scanning file..." - 2) = result;
        }
        while ( result );
        break;
      case 5:
        v6 = *(pHash + 32);
        if ( v6 )
          v7 = *v6;
        else
          v7 = 0;
        v8 = (Dest - v7);
        do
        {
          result = *v7;
          v7 += 2;
          *&v7[v8 - 2] = result;
        }
        while ( result );
        break;
      default:
        return result;
    }
  }
  return result;
}
// 1032BBC: using guessed type wchar_t aHashSubmitted[18];
// 1032BE0: using guessed type wchar_t aScanningFile[17];
// 1032C04: using guessed type wchar_t aFileSubmitted[18];

//----- (01001B40) --------------------------------------------------------
void StartVirusTotalCheck()
{
  if ( !byte_10857B4 )
  {
    HttpInfo_Open(&gHttpInfo, ghMainWnd, L"Process Explorer", 0, 0, 0);
    InitializeCriticalSection(&stru_1085744);
    ghEventHandle = CreateEventW(0, 0, 0, 0);
    ghEventHandle2 = CreateEventW(0, 0, 0, 0);
    ghThreadHandle = _beginthreadex(0, 0, BackendThreadProc1, 0, 0, 0);
    ghEventHandle3 = CreateEventW(0, 0, 0, 0);
    ghThreadHandle2 = _beginthreadex(0, 0, BackendThreadProc2, 0, 0, 0);
    ghThreadHandle3 = _beginthreadex(0, 0, BackendThreadProc3, 0, 0, 0);
    byte_10857B4 = 1;
  }
}
// 1085760: using guessed type int ghThreadHandle;
// 1085768: using guessed type int ghThreadHandle2;
// 1085770: using guessed type int ghThreadHandle3;
// 10857B4: using guessed type char byte_10857B4;

//----- (01001C10) --------------------------------------------------------
char __cdecl sub_1001C10(ListItemData1 *a1)
{
  char result; // al
  int v2; // ecx

  result = 0;
  if ( !a1 || (v2 = a1->field_4, v2 == 1) || (v2 - 5) <= 1 )
    result = 1;
  return result;
}

//----- (01001C30) --------------------------------------------------------
void __cdecl sub_1001C30(DLLLISTITEMPARAM *pItemParam, char a2, int a3)
{
  DLLLISTITEMPARAM *pItemParam_1; // ebx
  _bstr_t *v4; // edi
  CHAR *v5; // ST0C_4
  int v6; // eax
  int v7; // ecx
  Data_t_bstr_t *v8; // eax
  int v9; // esi
  LONG (__stdcall *v10)(volatile LONG *); // ecx
  _DWORD *v11; // eax
  Data_t_bstr_t *v12; // esi
  OLECHAR *v13; // eax
  Data_t_bstr_t *v14; // eax
  BSTR v15; // eax
  DLLLISTITEMPARAM *v16; // eax
  _bstr_t v17; // [esp+10h] [ebp-28h]
  _bstr_t v18; // [esp+14h] [ebp-24h]
  char v19; // [esp+18h] [ebp-20h]
  OLECHAR *psz; // [esp+1Ch] [ebp-1Ch]
  DLLLISTITEMPARAM *pItemParam_2; // [esp+20h] [ebp-18h]
  _bstr_t *v22; // [esp+24h] [ebp-14h]
  _bstr_t v23; // [esp+28h] [ebp-10h]
  int v24; // [esp+34h] [ebp-4h]

  if ( gbAgreenmentLicensed )
  {
    EnterCriticalSection(&stru_1085744);
    pItemParam_1 = 0;
    v4 = 0;
    pItemParam_2 = 0;
    v22 = 0;
    v23.m_Data = 0;
    v24 = 0;
    if ( pItemParam->m_Type )
    {
      v5 = pItemParam->m_strPath.pszData;
      pItemParam_2 = pItemParam;
      _bstr_t::operator=(&v23, v5);
      psz = pItemParam->m_strLocation;
    }
    else
    {
      pItemParam_1 = pItemParam;
      _bstr_t::operator=(&v23, pItemParam[2].field_8);
      psz = pItemParam[2].field_2C;
    }
    v6 = *sub_1002F90(&gHttpInfo.field_1C, &v18, &v23);
    if ( v6 == gHttpInfo.field_1C
      || ((v7 = *(v6 + 20), !pItemParam_1) ? (pItemParam_2->m_HashData = v7) : (pItemParam_1[2].field_3C = v7),
          (v4 = *(v6 + 20), v22 = v4, v8 = v4[1].m_Data, v8 == 6) || v8 == 5) )
    {
      v9 = a3;
      if ( a3 != 2 )
      {
        v10 = InterlockedIncrement;
        if ( !v4 )
        {
          v11 = operator new(0x2Cu);
          if ( v11 )
            v4 = sub_F91350(v11);
          else
            v4 = 0;
          v12 = v23.m_Data;
          LOBYTE(v4->m_Data) = a2;
          v22 = v4;
          if ( &v4[5] != &v23 )
          {
            _bstr_t::_Free(v4 + 5);
            v4[5].m_Data = v12;
            if ( v12 )
              InterlockedIncrement(&v12->m_RefCount);
          }
          v13 = &gszNullString;
          if ( psz )
            v13 = psz;
          psz = _bstr_t::_bstr_t(&v18, v13);
          if ( &v4[2] != psz )
          {
            _bstr_t::_Free(v4 + 2);
            v14 = *psz;
            v4[2].m_Data = *psz;
            if ( v14 )
              InterlockedIncrement(&v14->m_RefCount);
          }
          _bstr_t::_Free(&v18);
          v18.m_Data = _bstr_t::_bstr_t(&psz, &gszNullString);
          if ( &v4[3] != v18.m_Data )
          {
            _bstr_t::_Free(v4 + 3);
            v15 = v18.m_Data->m_wstr;
            v4[3].m_Data = v18.m_Data->m_wstr;
            if ( v15 )
              InterlockedIncrement(v15 + 2);
          }
          _bstr_t::_Free(&psz);
          v17.m_Data = v12;
          if ( v12 )
            InterlockedIncrement(&v12->m_RefCount);
          v18.m_Data = v4;
          LOBYTE(v24) = 1;
          sub_1001650(&gHttpInfo.field_1C, &v19, 0, &v17, byte_1085775);
          LOBYTE(v24) = 0;
          _bstr_t::_Free(&v17);
          v10 = InterlockedIncrement;
          v9 = a3;
        }
        v4[1].m_Data = (3 - (v9 != 1));
        if ( pItemParam_1 )
        {
          pItemParam_1[2].field_3C = v4;
          v16 = (pItemParam_1 + 36);
        }
        else
        {
          v16 = pItemParam_2;
          pItemParam_2->m_HashData = v4;
        }
        v10(&v16->m_nRefCount);
        if ( v9 == 1 )
        {
          sub_F99380(&off_10857A4, &v22);
          SetEvent(ghEventHandle3);
        }
        else
        {
          sub_F917F0(&dword_108579C, &v22);
          SetEvent(ghEventHandle2);
        }
      }
    }
    LeaveCriticalSection(&stru_1085744);
    _bstr_t::_Free(&v23);
  }
}
// 1085774: using guessed type char gbAgreenmentLicensed;
// 1085775: using guessed type char byte_1085775;

//----- (01001EC0) --------------------------------------------------------
int __stdcall BackendThreadProc2(void *a1)
{
  void (__stdcall *v1)(LPCRITICAL_SECTION); // ebx
  void (__stdcall *v2)(LPCRITICAL_SECTION); // esi
  EventListNode *v3; // ST0C_4
  int *v4; // ecx
  _DWORD *v5; // edi
  int v6; // eax
  Data_t_bstr_t *v7; // eax
  Data_t_bstr_t *v8; // esi
  BSTR v9; // eax
  Data_t_bstr_t *v10; // ecx
  int v11; // eax
  bool v12; // bl
  const wchar_t **v13; // eax
  const wchar_t *v14; // eax
  EventListNode *v15; // ebx
  _DWORD *v16; // eax
  void (__stdcall *v17)(HWND, UINT, WPARAM, LPARAM); // ebx
  const wchar_t **v18; // eax
  const wchar_t *v19; // eax
  EventList *v20; // ebx
  _DWORD *v21; // eax
  int v22; // esi
  HANDLE Handles; // [esp+10h] [ebp-24h]
  HANDLE v25; // [esp+14h] [ebp-20h]
  void *v26; // [esp+18h] [ebp-1Ch]
  OLECHAR psz[2]; // [esp+1Ch] [ebp-18h]
  int a3; // [esp+20h] [ebp-14h]
  char v29; // [esp+27h] [ebp-Dh]
  int v30; // [esp+30h] [ebp-4h]

  Handles = ghEventHandle3;
  v25 = ghEventHandle;
  *psz = 0;
  v30 = 0;
  if ( WaitForMultipleObjects(2u, &Handles, 0, 0xFFFFFFFF) != 1 )
  {
    v1 = EnterCriticalSection;
    v2 = LeaveCriticalSection;
    while ( 1 )
    {
      v1(&stru_1085744);
      if ( dword_10857A8 )
        break;
LABEL_42:
      v2(&stru_1085744);
      if ( WaitForMultipleObjects(2u, &Handles, 0, 0xFFFFFFFF) == 1 )
        goto LABEL_43;
    }
    while ( 1 )
    {
      v3 = off_10857A4->_Myheader;
      v4 = off_10857A4->_Myheader->field_4;
      v6 = off_10857A4->_Myheader->field_0;
      a3 = off_10857A4->_Myheader[1].field_0;
      v5 = a3;
      *v4 = v6;
      *(v3->field_0 + 4) = v3->field_4;
      --dword_10857A8;
      j__free(v3);
      v2(&stru_1085744);
      sub_FA55A0(&gHttpInfo, (v5 + 2), psz);
      v1(&stru_1085744);
      v29 = 0;
      v7 = operator new(0xCu);
      v8 = v7;
      v26 = v7;
      LOBYTE(v30) = 1;
      if ( v7 )
      {
        v7->m_str = 0;
        v7->m_RefCount = 1;
        v9 = SysAllocString(&gszNullString);
        v8->m_wstr = v9;
        if ( !v9 )
          goto LABEL_6;
      }
      else
      {
        v8 = 0;
      }
      LOBYTE(v30) = 0;
      if ( !v8 )
LABEL_6:
        _com_issue_error(-2147024882);
      v10 = v5[8];
      if ( v10 == v8 )
        break;
      if ( v10 )
      {
        v11 = bstr_t::Data_t::Compare(v10, v8);
      }
      else
      {
        if ( !v8->m_wstr || !SysStringLen(v8->m_wstr) )
          break;
        v11 = -1;
      }
LABEL_16:
      v12 = v11 != 0;
      if ( !InterlockedDecrement(&v8->m_RefCount) )
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
      if ( !v12 )
      {
        v18 = v5[10];
        if ( v18 )
          v19 = *v18;
        else
          v19 = 0;
        if ( _wcsicmp(v19, L"Submitted") )
        {
          v5[1] = 1;
        }
        else
        {
          v20 = off_10857AC;
          v21 = std::_List_buy<tagEventItem *,std::allocator<tagEventItem *>>::_Buynode<tagEventItem * const &>(
                  off_10857AC,
                  off_10857AC->_Mysize,
                  &a3);
          if ( (357913940 - dword_10857B0) < 1 )
LABEL_52:
            std::_Xlength_error("list<T> too long");
          ++dword_10857B0;
          v20->_Mysize = v21;
          *v21[1] = v21;
          v5[1] = 4;
        }
        v29 = 1;
        goto LABEL_38;
      }
      v13 = v5[8];
      if ( v13 )
        v14 = *v13;
      else
        v14 = 0;
      if ( wcsstr(v14, L"throttle") )
      {
        v15 = off_10857A4->_Myheader;
        v16 = std::_List_buy<tagEventItem *,std::allocator<tagEventItem *>>::_Buynode<tagEventItem * const &>(
                off_10857A4->_Myheader,
                off_10857A4->_Myheader->field_4,
                &a3);
        if ( (357913940 - dword_10857A8) < 1 )
          goto LABEL_52;
        ++dword_10857A8;
        v15->field_4 = v16;
        *v16[1] = v16;
        SetEvent(ghEventHandle3);
LABEL_38:
        v17 = PostMessageW;
        goto LABEL_39;
      }
      v17 = PostMessageW;
      v5[1] = 5;
      v29 = 1;
      PostMessageW(ghMainWnd, 0x7F9u, 0, v5);
LABEL_39:
      v2 = LeaveCriticalSection;
      LeaveCriticalSection(&stru_1085744);
      if ( v29 )
        v17(ghMainWnd, 0x7F9u, 0, v5);
      v1 = EnterCriticalSection;
      EnterCriticalSection(&stru_1085744);
      if ( !dword_10857A8 )
        goto LABEL_42;
    }
    v11 = 0;
    goto LABEL_16;
  }
LABEL_43:
  v22 = *psz;
  if ( *psz && !InterlockedDecrement((*psz + 8)) && v22 )
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
  return 0;
}
// F9C3D4: using guessed type int (__stdcall *)(_DWORD);
// 10857A8: using guessed type int dword_10857A8;
// 10857B0: using guessed type int dword_10857B0;

//----- (01002230) --------------------------------------------------------
int __stdcall BackendThreadProc1(int a1)
{
  int v1; // edi
  EventList *v2; // ebx
  void (__stdcall *v3)(LPCRITICAL_SECTION); // esi
  _DWORD *v4; // ST514_4
  _DWORD *v5; // ecx
  int v6; // ebx
  int v7; // eax
  OLECHAR **v8; // eax
  OLECHAR *v9; // eax
  _DWORD *v10; // ecx
  const WCHAR *v11; // ecx
  OLECHAR **v12; // eax
  OLECHAR *v13; // eax
  EventList *v14; // esi
  _DWORD *v15; // eax
  _DWORD *v16; // ecx
  DWORD v17; // eax
  void **v18; // edi
  void *v19; // esi
  void *v20; // esi
  EventList *v21; // esi
  EventListNode *v22; // ebx
  Data_t_bstr_t *v23; // eax
  Data_t_bstr_t *v24; // edi
  BSTR v25; // eax
  Data_t_bstr_t *v26; // ecx
  int v27; // eax
  const wchar_t **v28; // eax
  const wchar_t *v29; // eax
  _DWORD *v30; // eax
  OLECHAR **v31; // eax
  OLECHAR *v32; // eax
  const wchar_t **v33; // eax
  const wchar_t *v34; // eax
  _DWORD *v35; // eax
  _DWORD *v36; // eax
  EventList *v37; // eax
  EventListNode *v38; // esi
  EventList *v39; // eax
  EventListNode *v40; // esi
  HANDLE Handles; // [esp+10h] [ebp-B4h]
  HANDLE v43; // [esp+14h] [ebp-B0h]
  int v44; // [esp+18h] [ebp-ACh]
  EventList **v45; // [esp+1Ch] [ebp-A8h]
  int v46; // [esp+20h] [ebp-A4h]
  void *v47; // [esp+24h] [ebp-A0h]
  int a3; // [esp+28h] [ebp-9Ch]
  void *v49; // [esp+2Ch] [ebp-98h]
  bool v50; // [esp+32h] [ebp-92h]
  char v51; // [esp+33h] [ebp-91h]
  OLECHAR psz; // [esp+34h] [ebp-90h]
  int v53; // [esp+C0h] [ebp-4h]

  v1 = 0;
  Handles = ghEventHandle2;
  v43 = ghEventHandle;
  v46 = 0;
  v2 = std::_List_alloc<std::_List_base_types<tagEventItem *,std::allocator<tagEventItem *>>>::_Buynode0(0, 0);
  v45 = v2;
  v53 = 0;
  v44 = 0;
  while ( WaitForMultipleObjects(2u, &Handles, 0, 0xFFFFFFFF) != 1 )
  {
    v3 = LeaveCriticalSection;
    Sleep(0x1388u);
    EnterCriticalSection(&stru_1085744);
    if ( dword_10857A0 )
    {
      do
      {
        v4 = *dword_108579C;
        v5 = *(*dword_108579C + 4);
        v7 = **dword_108579C;
        a3 = *(*dword_108579C + 8);
        v6 = a3;
        *v5 = v7;
        *(*v4 + 4) = v4[1];
        --dword_10857A0;
        j__free(v4);
        v3(&stru_1085744);
        v8 = *(v6 + 16);
        if ( !v8 || (v9 = *v8) == 0 || !SysStringLen(v9) )
        {
          v10 = *(v6 + 20);
          v11 = (v10 ? *v10 : 0);
          if ( sub_1001840(v11, &psz, v6 + 24) )
            _bstr_t::operator=((v6 + 16), &psz);
        }
        v12 = *(v6 + 16);
        if ( v12 && (v13 = *v12) != 0 && SysStringLen(v13) )
        {
          ++v44;
          v14 = *v45;
          v15 = std::_List_buy<tagEventItem *,std::allocator<tagEventItem *>>::_Buynode<tagEventItem * const &>(
                  *v45,
                  (*v45)->_Mysize,
                  &a3);
          if ( (357913940 - v1) < 1 )
LABEL_89:
            std::_Xlength_error("list<T> too long");
          v14->_Mysize = v15;
          ++v1;
          v16 = v15[1];
          v46 = v1;
          *v16 = v15;
          sub_FA5160(&gHttpInfo, v6 + 8);
        }
        else
        {
          v17 = GetLastError();
          sub_FA4320(&v47, v17);
          v18 = (v6 + 32);
          if ( (v6 + 32) != &v47 )
          {
            v19 = *v18;
            if ( *v18 )
            {
              if ( !InterlockedDecrement(v19 + 2) && v19 )
              {
                if ( *v19 )
                {
                  SysFreeString(*v19);
                  *v19 = 0;
                }
                if ( *(v19 + 1) )
                {
                  j_j__free(*(v19 + 1));
                  *(v19 + 1) = 0;
                }
                j__free(v19);
              }
              *v18 = 0;
            }
            *v18 = v47;
            if ( v47 )
              InterlockedIncrement(v47 + 2);
          }
          *(v6 + 4) = 5;
          v20 = v47;
          if ( v47 )
          {
            if ( !InterlockedDecrement(v47 + 2) && v20 )
            {
              if ( *v20 )
              {
                SysFreeString(*v20);
                *v20 = 0;
              }
              if ( *(v20 + 1) )
              {
                j_j__free(*(v20 + 1));
                *(v20 + 1) = 0;
              }
              j__free(v20);
            }
            v47 = 0;
          }
          v1 = v46;
        }
        EnterCriticalSection(&stru_1085744);
        v3 = LeaveCriticalSection;
      }
      while ( dword_10857A0 );
      v2 = v45;
    }
    v3(&stru_1085744);
    sub_FA1FC0(&gHttpInfo);
    v21 = v2->_Myheader;
    if ( v2->_Myheader != v2 )
    {
      while ( 1 )
      {
        EnterCriticalSection(&stru_1085744);
        v22 = v21[1]._Myheader;
        v51 = 0;
        a3 = v22;
        v23 = operator new(0xCu);
        v24 = v23;
        v49 = v23;
        LOBYTE(v53) = 1;
        if ( v23 )
        {
          v23->m_str = 0;
          v23->m_RefCount = 1;
          v25 = SysAllocString(&gszNullString);
          v24->m_wstr = v25;
          if ( !v25 )
            goto LABEL_44;
        }
        else
        {
          v24 = 0;
        }
        LOBYTE(v53) = 0;
        if ( !v24 )
LABEL_44:
          _com_issue_error(-2147024882);
        v26 = v22[4].field_0;
        if ( v26 == v24 )
          break;
        if ( v26 )
        {
          v27 = bstr_t::Data_t::Compare(v26, v24);
        }
        else
        {
          if ( !v24->m_wstr || !SysStringLen(v24->m_wstr) )
            break;
          v27 = -1;
        }
LABEL_54:
        v50 = v27 != 0;
        if ( !InterlockedDecrement(&v24->m_RefCount) )
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
        if ( v50 )
        {
          v28 = v22[4].field_0;
          if ( v28 )
            v29 = *v28;
          else
            v29 = 0;
          if ( wcsstr(v29, L"Throttle") )
          {
            v49 = *dword_108579C;
            v30 = std::_List_buy<tagEventItem *,std::allocator<tagEventItem *>>::_Buynode<tagEventItem * const &>(
                    v49,
                    *(v49 + 1),
                    &a3);
            if ( (357913940 - dword_10857A0) < 1 )
              goto LABEL_89;
            ++dword_10857A0;
            *(v49 + 1) = v30;
            *v30[1] = v30;
            SetEvent(ghEventHandle2);
            goto LABEL_83;
          }
          v22->field_4 = 5;
        }
        else
        {
          v31 = v22[4].field_4;
          if ( v31 && (v32 = *v31) != 0 && SysStringLen(v32) )
          {
            v33 = v22[5].field_0;
            if ( v33 )
              v34 = *v33;
            else
              v34 = 0;
            if ( _wcsicmp(v34, L"Submitted") )
            {
              v22->field_4 = 1;
            }
            else
            {
              v49 = *dword_108579C;
              v35 = std::_List_buy<tagEventItem *,std::allocator<tagEventItem *>>::_Buynode<tagEventItem * const &>(
                      v49,
                      *(v49 + 1),
                      &a3);
              if ( (357913940 - dword_10857A0) < 1 )
                goto LABEL_89;
              ++dword_10857A0;
              *(v49 + 1) = v35;
              *v35[1] = v35;
              SetEvent(ghEventHandle2);
            }
          }
          else
          {
            v22->field_4 = 6;
            if ( gConfig.bVirusTotalSubmitUnknown && LOBYTE(v22->field_0) )
            {
              v22->field_4 = 3;
              v49 = off_10857A4;
              v36 = std::_List_buy<tagEventItem *,std::allocator<tagEventItem *>>::_Buynode<tagEventItem * const &>(
                      off_10857A4,
                      off_10857A4->_Mysize,
                      &a3);
              if ( (357913940 - dword_10857A8) < 1 )
                goto LABEL_89;
              ++dword_10857A8;
              *(v49 + 1) = v36;
              *v36[1] = v36;
              SetEvent(ghEventHandle3);
            }
          }
        }
        v51 = 1;
LABEL_83:
        LeaveCriticalSection(&stru_1085744);
        if ( v51 )
          PostMessageW(ghMainWnd, 0x7F9u, 0, v22);
        v21 = v21->_Myheader;
        v2 = v45;
        if ( v21 == v45 )
          goto LABEL_86;
      }
      v27 = 0;
      goto LABEL_54;
    }
LABEL_86:
    v37 = v2->_Myheader;
    v1 = 0;
    v2->_Myheader = v2;
    v2->_Mysize = v2;
    v46 = 0;
    if ( v37 != v2 )
    {
      do
      {
        v38 = v37->_Myheader;
        j__free(v37);
        v37 = v38;
      }
      while ( v38 != v2 );
    }
  }
  v39 = v2->_Myheader;
  v2->_Myheader = v2;
  v2->_Mysize = v2;
  if ( v39 != v2 )
  {
    do
    {
      v40 = v39->_Myheader;
      j__free(v39);
      v39 = v40;
    }
    while ( v40 != v2 );
  }
  j__free(v2);
  return 0;
}
// 10857A0: using guessed type int dword_10857A0;
// 10857A8: using guessed type int dword_10857A8;

//----- (01002860) --------------------------------------------------------
LRESULT __stdcall EditVTClassCallback(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, UINT_PTR uIdSubclass, DWORD_PTR dwRefData)
{
  HWND v6; // eax
  DLLINFOLISTITEMPARAM *v7; // eax
  int v8; // eax
  const WCHAR **v9; // eax
  const WCHAR *v10; // eax
  int v12; // eax
  HCURSOR v13; // eax

  v6 = GetParent(hWnd);
  v7 = GetWindowLongW(v6, GWLP_USERDATA);
  if ( v7->m_dwType )
    v8 = v7->m_ItemData1;
  else
    v8 = v7[2].field_3C;
  if ( uMsg != WM_MOUSEMOVE )
  {
    if ( uMsg == 514 && v8 && (*(v8 + 4) == 1 || *(v8 + 4) == 4) )
    {
      v9 = *(v8 + 36);
      if ( v9 )
        v10 = *v9;
      else
        v10 = 0;
      LaunchWebBrowser(hWnd, 0, v10);
    }
    return DefSubclassProc(hWnd, uMsg, wParam, lParam);
  }
  if ( !v8 )
    return DefSubclassProc(hWnd, uMsg, wParam, lParam);
  v12 = *(v8 + 4) - 1;
  if ( v12 )
  {
    if ( v12 != 3 )
      return DefSubclassProc(hWnd, uMsg, wParam, lParam);
  }
  v13 = LoadCursorW(ghInstance, L"HAND");
  SetCursor(v13);
  return 1;
}

//----- (01002910) --------------------------------------------------------
char __cdecl sub_1002910(ListItemData1 *a1)
{
  wchar_t **v1; // eax
  wchar_t *v2; // eax
  char result; // al
  int v4; // [esp+4h] [ebp-8h]
  int v5; // [esp+8h] [ebp-4h]

  v5 = 0;
  v4 = 0;
  if ( a1->field_4 != 1 )
    return 0;
  v1 = a1[5].field_0;
  if ( v1 )
    v2 = *v1;
  else
    v2 = 0;
  scan_fn(v2, L"%d/%d", &v5);
  result = 0;
  if ( v5 )
    result = 1;
  return result;
}
// 1032BB0: using guessed type wchar_t aDD[6];

//----- (01002970) --------------------------------------------------------
int __stdcall BackendThreadProc3(void *a1)
{
  DWORD (__stdcall *v1)(HANDLE, DWORD); // edi
  EventList *v2; // esi
  EventListNode *v3; // edi
  const wchar_t **v4; // eax
  const wchar_t *v5; // eax
  EventList *v6; // eax

  v1 = WaitForSingleObject;
  while ( v1(ghEventHandle, 0x2710u) == 258 )
  {
    if ( !sub_FA37E0(&gHttpInfo) )
    {
      v2 = off_10857AC->_Myheader;
      if ( off_10857AC->_Myheader != off_10857AC )
      {
        do
        {
          EnterCriticalSection(&stru_1085744);
          v3 = v2[1]._Myheader;
          v4 = v3[5].field_0;
          if ( v4 )
            v5 = *v4;
          else
            v5 = 0;
          if ( _wcsicmp(v5, L"Submitted") )
          {
            v6 = v2;
            v3->field_4 = 1;
            v2 = v2->_Myheader;
            *v6->_Mysize = v6->_Myheader;
            v6->_Myheader->field_4 = v6->_Mysize;
            --dword_10857B0;
            j__free(v6);
          }
          else
          {
            v2 = v2->_Myheader;
          }
          LeaveCriticalSection(&stru_1085744);
        }
        while ( v2 != off_10857AC );
        v1 = WaitForSingleObject;
      }
      PostMessageW(ghMainWnd, 0x7F9u, 0, 0);
    }
  }
  return 0;
}
// 10857B0: using guessed type int dword_10857B0;

//----- (01002A70) --------------------------------------------------------
_DWORD *__stdcall std::_List_alloc<std::_List_base_types<tagEventItem *,std::allocator<tagEventItem *>>>::_Buynode0(_DWORD *a1, _DWORD *a2)
{
  _DWORD *result; // eax
  _DWORD *v3; // ecx
  _DWORD *v4; // edx

  result = operator new(0xCu);
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

//----- (01002AB0) --------------------------------------------------------
void __stdcall sub_1002AB0(void *a1)
{
  _DWORD *v1; // edi
  void *i; // ebx
  int v3; // esi

  v1 = a1;
  for ( i = a1; !*(i + 13); v1 = i )
  {
    sub_1002AB0(*(i + 2));
    v3 = v1[4];
    i = *i;
    if ( v3 )
    {
      if ( !InterlockedDecrement((v3 + 8)) && v3 )
      {
        if ( *v3 )
        {
          SysFreeString(*v3);
          *v3 = 0;
        }
        if ( *(v3 + 4) )
        {
          j_j__free(*(v3 + 4));
          *(v3 + 4) = 0;
        }
        j__free(v3);
      }
      v1[4] = 0;
    }
    j__free(v1);
  }
}

//----- (01002B40) --------------------------------------------------------
_bstr_t *__thiscall sub_1002B40(void *this, _bstr_t *a2)
{
  _bstr_t *v2; // edi
  _bstr_t *v3; // esi
  Data_t_bstr_t *v4; // ecx
  Data_t_bstr_t *v6; // [esp-8h] [ebp-1Ch]
  Data_t_bstr_t *v7; // [esp-4h] [ebp-18h]

  v2 = *this;
  v3 = *(*this + 4);
  while ( !BYTE1(v3[3].m_Data) )
  {
    v7 = a2->m_Data;
    if ( a2->m_Data )
      InterlockedIncrement(&v7->m_RefCount);
    v4 = v3[4].m_Data;
    v6 = v4;
    if ( v4 )
      InterlockedIncrement(&v4->m_RefCount);
    if ( sub_F914B0(v6, v7) )
    {
      v3 = v3[2].m_Data;
    }
    else
    {
      v2 = v3;
      v3 = v3->m_Data;
    }
  }
  return v2;
}

//----- (01002BB0) --------------------------------------------------------
std__Tree_node *__thiscall sub_1002BB0(std__tree *this, std__Tree_node *a2)
{
  std__Tree_node *v2; // esi
  std__Tree_node *v3; // eax
  std__Tree_node *result; // eax

  v2 = a2->_Left;
  a2->_Left = a2->_Left->_Right;
  v3 = v2->_Right;
  if ( !v3->_IsNil )
    v3->_Parent = a2;
  v2->_Parent = a2->_Parent;
  result = this->_Mypair._Myval2._Myhead;
  if ( a2 == this->_Mypair._Myval2._Myhead->_Parent )
  {
    result->_Parent = v2;
    v2->_Right = a2;
    a2->_Parent = v2;
  }
  else
  {
    result = a2->_Parent;
    if ( a2 == result->_Right )
      result->_Right = v2;
    else
      result->_Left = v2;
    v2->_Right = a2;
    a2->_Parent = v2;
  }
  return result;
}

//----- (01002C10) --------------------------------------------------------
int **__thiscall sub_1002C10(int **this, int **a2, int **a3, int **a4)
{
  int **v4; // eax
  int **v5; // esi
  int *v6; // ecx
  int **v7; // eax
  int *v8; // ecx
  int **result; // eax
  int **v10; // ecx
  int *i; // edx
  int *v12; // eax
  char v13; // [esp+4h] [ebp-4h]

  v4 = a3;
  v5 = this;
  v6 = *this;
  if ( a3 != *v6 || a4 != v6 )
  {
    for ( ; a3 != a4; v4 = a3 )
    {
      v10 = v4;
      if ( !*(v4 + 13) )
      {
        i = v4[2];
        if ( *(i + 13) )
        {
          for ( i = v4[1]; !*(i + 13); i = i[1] )
          {
            if ( v4 != i[2] )
              break;
            v4 = i;
          }
        }
        else
        {
          v12 = *i;
          if ( !*(*i + 13) )
          {
            do
            {
              i = v12;
              v12 = *v12;
            }
            while ( !*(v12 + 13) );
          }
        }
        a3 = i;
      }
      sub_1002CD0(v5, &v13, v10);
    }
    *a2 = v4;
    result = a2;
  }
  else
  {
    sub_1002AB0(v6[1]);
    (*v5)[1] = *v5;
    **v5 = *v5;
    (*v5)[2] = *v5;
    v7 = *v5;
    v5[1] = 0;
    v8 = *v7;
    result = a2;
    *a2 = v8;
  }
  return result;
}

//----- (01002CD0) --------------------------------------------------------
_DWORD *__thiscall sub_1002CD0(_DWORD *this, _DWORD *a2, _DWORD *a3)
{
  std__tree *v3; // ebx
  _DWORD *v4; // edx
  std__Tree_node *v5; // edi
  std__Tree_node *v6; // ecx
  std__Tree_node *v7; // esi
  std__Tree_node *v8; // eax
  std__Tree_node *v9; // ecx
  std__Tree_node *v10; // eax
  std__Tree_node_For__bstr_t *v11; // eax
  std__Tree_node_For__bstr_t *i; // ecx
  std__Tree_node **v13; // eax
  bool v14; // cl
  std__Tree_node *v15; // ecx
  int v16; // esi
  unsigned int v17; // eax
  _DWORD *v18; // ecx
  _DWORD *result; // eax
  _DWORD *v20; // [esp+Ch] [ebp-8h]
  _DWORD *v21; // [esp+10h] [ebp-4h]

  v3 = this;
  v21 = a3;
  sub_F94CE0(&a3);
  v4 = v21;
  if ( *(*v21 + 13) )
  {
    v5 = v21[2];
  }
  else if ( *(v21[2] + 13) )
  {
    v5 = *v21;
  }
  else
  {
    v6 = a3;
    v20 = a3;
    v5 = a3[2];
    if ( a3 != v21 )
    {
      *(*v21 + 4) = a3;
      v6->_Left = *v21;
      if ( v6 == v21[2] )
      {
        v7 = v6;
      }
      else
      {
        v7 = v6->_Parent;
        if ( !v5->_IsNil )
          v5->_Parent = v7;
        v7->_Left = v5;
        v6->_Right = v21[2];
        *(v21[2] + 4) = v6;
      }
      if ( v3->_Mypair._Myval2._Myhead->_Parent == v21 )
      {
        v3->_Mypair._Myval2._Myhead->_Parent = v6;
      }
      else
      {
        v13 = v21[1];
        if ( *v13 == v21 )
          *v13 = v6;
        else
          v13[2] = v6;
      }
      v6->_Parent = v21[1];
      v14 = v6->_Color;
      *(v20 + 12) = *(v21 + 12);
      v4 = v21;
      *(v21 + 12) = v14;
      goto LABEL_37;
    }
  }
  v7 = v21[1];
  if ( !v5->_IsNil )
    v5->_Parent = v7;
  if ( v3->_Mypair._Myval2._Myhead->_Parent == v21 )
  {
    v3->_Mypair._Myval2._Myhead->_Parent = v5;
  }
  else if ( v7->_Left == v21 )
  {
    v7->_Left = v5;
  }
  else
  {
    v7->_Right = v5;
  }
  v8 = v3->_Mypair._Myval2._Myhead;
  if ( &v3->_Mypair._Myval2._Myhead->_Left->_Left == v21 )
  {
    if ( v5->_IsNil )
    {
      v9 = v7;
    }
    else
    {
      v10 = v5->_Left;
      v9 = v5;
      if ( !v5->_Left->_IsNil )
      {
        do
        {
          v9 = v10;
          v10 = v10->_Left;
        }
        while ( !v10->_IsNil );
      }
      v8 = v3->_Mypair._Myval2._Myhead;
    }
    v8->_Left = v9;
  }
  if ( v3->_Mypair._Myval2._Myhead->_Right == v21 )
  {
    if ( v5->_IsNil )
    {
      v3->_Mypair._Myval2._Myhead->_Right = v7;
    }
    else
    {
      v11 = v5->_Right;
      for ( i = v5; !v11->_IsNil; v11 = v11->_Right )
        i = v11;
      v3->_Mypair._Myval2._Myhead->_Right = i;
    }
  }
LABEL_37:
  if ( *(v4 + 12) != 1 )
    goto LABEL_62;
  if ( v5 == v3->_Mypair._Myval2._Myhead->_Parent )
    goto LABEL_61;
  while ( v5->_Color == 1 )
  {
    v15 = v7->_Left;
    if ( v5 == v7->_Left )
    {
      v15 = v7->_Right;
      if ( !v15->_Color )
      {
        v15->_Color = 1;
        v7->_Color = 0;
        sub_FF54B0(v3, v7);
        v15 = v7->_Right;
      }
      if ( v15->_IsNil )
        goto LABEL_55;
      if ( v15->_Left->_Color != 1 || v15->_Right->_Color != 1 )
      {
        if ( v15->_Right->_Color == 1 )
        {
          v15->_Left->_Color = 1;
          v15->_Color = 0;
          sub_1002BB0(v3, v15);
          v15 = v7->_Right;
        }
        v15->_Color = v7->_Color;
        v7->_Color = 1;
        v15->_Right->_Color = 1;
        sub_FF54B0(v3, v7);
        break;
      }
    }
    else
    {
      if ( !v15->_Color )
      {
        v15->_Color = 1;
        v7->_Color = 0;
        sub_1002BB0(v3, v7);
        v15 = v7->_Left;
      }
      if ( v15->_IsNil )
        goto LABEL_55;
      if ( v15->_Right->_Color != 1 || v15->_Left->_Color != 1 )
      {
        if ( v15->_Left->_Color == 1 )
        {
          v15->_Right->_Color = 1;
          v15->_Color = 0;
          sub_FF54B0(v3, v15);
          v15 = v7->_Left;
        }
        v15->_Color = v7->_Color;
        v7->_Color = 1;
        v15->_Left->_Color = 1;
        sub_1002BB0(v3, v7);
        break;
      }
    }
    v15->_Color = 0;
LABEL_55:
    v5 = v7;
    v7 = v7->_Parent;
    if ( v5 == v3->_Mypair._Myval2._Myhead->_Parent )
      break;
  }
  v4 = v21;
LABEL_61:
  v5->_Color = 1;
LABEL_62:
  v16 = v4[4];
  if ( v16 )
  {
    if ( !InterlockedDecrement((v16 + 8)) && v16 )
    {
      if ( *v16 )
      {
        SysFreeString(*v16);
        *v16 = 0;
      }
      if ( *(v16 + 4) )
      {
        j_j__free(*(v16 + 4));
        *(v16 + 4) = 0;
      }
      j__free(v16);
    }
    v4 = v21;
    v21[4] = 0;
  }
  j__free(v4);
  v17 = v3->_Mypair._Myval2._Mysize;
  v18 = a3;
  if ( v17 )
    v3->_Mypair._Myval2._Mysize = v17 - 1;
  result = a2;
  *a2 = v18;
  return result;
}

//----- (01002F90) --------------------------------------------------------
int *__thiscall sub_1002F90(int *this, int *a2, volatile LONG **a3)
{
  int *v3; // edi
  _bstr_t *v4; // eax
  int v5; // esi
  Data_t_bstr_t *v6; // ecx
  int *result; // eax
  Data_t_bstr_t *v8; // [esp-8h] [ebp-14h]
  Data_t_bstr_t *v9; // [esp-4h] [ebp-10h]

  v3 = this;
  v4 = sub_1002B40(this, a3);
  v5 = v4;
  if ( v4 == *v3 )
    goto LABEL_11;
  v6 = v4[4].m_Data;
  v9 = v6;
  if ( v6 )
    InterlockedIncrement(&v6->m_RefCount);
  v8 = *a3;
  if ( *a3 )
    InterlockedIncrement(&v8->m_RefCount);
  if ( sub_F914B0(v8, v9) )
  {
LABEL_11:
    result = a2;
    *a2 = *v3;
  }
  else
  {
    result = a2;
    *a2 = v5;
  }
  return result;
}

//----- (01003010) --------------------------------------------------------
HANDLE LoadSharedMemory()
{
  HANDLE v0; // eax
  void *v1; // ebx
  HANDLE result; // eax
  HANDLE v3; // eax
  char *v4; // esi
  DWORD (__stdcall *v5)(); // ebx
  const WCHAR *v6; // ecx
  HANDLE v7; // edi
  HANDLE v8; // ebx
  HANDLE hHandle; // [esp+8h] [ebp-8h]
  HANDLE hEvent; // [esp+Ch] [ebp-4h]

  LoadDbgHelp(L"Dbghelp.dll");
  v0 = CreateEventW(0, 0, 0, L"Procexp32bitServerEvent");
  v1 = v0;
  hHandle = v0;
  result = CreateEventW(0, 0, 0, L"Procexp32bitClientEvent");
  hEvent = result;
  if ( result )
  {
    if ( v1 )
    {
      v3 = CreateFileMappingW(0xFFFFFFFF, 0, 0x8000004u, 0, gSystemInfo.dwPageSize, L"Procexp32bitSection");
      v4 = MapViewOfFile(v3, 6u, 0, 0, gSystemInfo.dwPageSize);
      result = WaitForSingleObject(v1, 0xFFFFFFFF);
      if ( !result )
      {
        v5 = GetLastError;
        v6 = (v4 + 12);
        do
        {
          v7 = CreateFileW(v6, GENERIC_WRITE, 7u, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
          if ( v7 == -1 )
          {
            *(v4 + 2) = v5();
          }
          else
          {
            v8 = OpenProcess(PROCESS_TRACE_MODE_EVENT_RECORD, 0, *v4);
            if ( v8 )
            {
              if ( !DumpFileProcess(v7, v8, v4[4]) )
                *(v4 + 2) = GetLastError();
              CloseHandle(v8);
              v5 = GetLastError;
            }
            else
            {
              v5 = GetLastError;
              *(v4 + 2) = GetLastError();
            }
            CloseHandle(v7);
          }
          SetEvent(hEvent);
          result = WaitForSingleObject(hHandle, 0xFFFFFFFF);
          v6 = (v4 + 12);
        }
        while ( !result );
      }
    }
  }
  return result;
}

//----- (01003150) --------------------------------------------------------
signed int sub_1003150()
{
  if ( GetVersion() < 6u )
    MessageBoxW(
      0,
      L"Usage: Process Explorer [/t] [/p:[r|h|l]] [/s:<PID>]\n"
       "\n"
       "/t\tStart minimized in the tray\n"
       "/p\tRun at priority: realtime (r), high (h), normal (n) or low (l)\n"
       "/s\tSelect the specified process\n",
      L"Process Explorer",
      0x40u);
  else
    MessageBoxW(
      0,
      L"Usage: Process Explorer [/e] [/t] [/p:[r|h|l]] [/s:<PID>]\n"
       "\n"
       "/e\tRequest UAC elevation\n"
       "/t\tStart minimized in the tray\n"
       "/p\tRun at priority: realtime (r), high (h), normal (n) or low (l)\n"
       "/s\tSelect the specified process\n",
      L"Process Explorer",
      0x40u);
  return -1;
}

//----- (01003190) --------------------------------------------------------
int __stdcall wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nShowCmd)
{
  HMODULE v4; // eax
  void (__stdcall *GetNativeSystemInfo)(); // eax
  int result; // eax
  __int16 dwVersion; // ax
  int dwPlatform; // eax
  HANDLE v9; // eax
  int nIndex_1; // esi
  wchar_t *pszArgs; // edx
  int nArgLength; // eax
  int nChar; // ecx
  int v14; // ecx
  int v15; // eax
  wchar_t *v16; // eax
  int v17; // esi
  wchar_t *v18; // ecx
  int v19; // edi
  wchar_t v20; // ax
  wchar_t *v21; // ecx
  int v22; // eax
  HANDLE v23; // eax
  DWORD v24; // eax
  HACCEL v25; // ebx
  HWND v26; // eax
  DWORD v27; // [esp-8h] [ebp-C0h]
  struct tagMSG Msg; // [esp+8h] [ebp-B0h]
  HINSTANCE hInst; // [esp+24h] [ebp-94h]
  const WCHAR *lpCmdLine_1; // [esp+28h] [ebp-90h]
  int nIndex; // [esp+2Ch] [ebp-8Ch]
  int v32; // [esp+30h] [ebp-88h]
  char v33; // [esp+33h] [ebp-85h]
  wchar_t *ppszArgs[32]; // [esp+34h] [ebp-84h]

  hInst = hInstance;
  lpCmdLine_1 = lpCmdLine;
  v33 = 0;
  v4 = LoadLibraryW(L"kernel32.dll");
  GetNativeSystemInfo = GetProcAddress(v4, "GetNativeSystemInfo");
  if ( GetNativeSystemInfo )
    GetNativeSystemInfo();
  else
    GetSystemInfo(&gSystemInfo);
  if ( Fake_IsWow64Process() )
  {
    _beginthread(LoadSharedMemory, 0, hInstance);
    if ( LaunchProcExplorer64(1, nShowCmd) )
      return 0;
    MessageBoxW(
      0,
      L"Unable to extract 64-bit image. Run Process Explorer from a writeable directory.",
      L"Process Explorer",
      0x10u);
    return 1;
  }
  gdwTebAddressOffset = 0xF60;
  dwVersion = GetVersion();
  if ( dwVersion >= 5u )
  {
    gdwVersion = 0;
    if ( dwVersion < 0xAu )
    {
      if ( dwVersion >= 6u )
      {
        dwPlatform = HIBYTE(dwVersion);
        if ( dwPlatform )
        {
          if ( dwPlatform == 1 )
            gdwVersion = WINDOWS_7;
          else
            gdwVersion = WINDOWS_8;
        }
        else
        {
          gdwVersion = WINDOWS_VISTA;
        }
      }
    }
    else
    {
      gdwVersion = WINDOWS_10;
    }
  }
  v9 = GetCurrentProcess();
  SetPriorityClass(v9, HIGH_PRIORITY_CLASS);
  nIndex_1 = 0;
  gszCmdLine = lpCmdLine;
  nIndex = 0;
  ppszArgs[0] = lpCmdLine;
  if ( *lpCmdLine )
  {
    do
    {
      pszArgs = ppszArgs[nIndex_1];
      nArgLength = 0;
      if ( *pszArgs )
      {
        nChar = 0;
        do
        {
          if ( pszArgs[nChar] == ' ' )
            break;
          nChar = ++nArgLength;
        }
        while ( pszArgs[nArgLength] );
        if ( nArgLength )
          nIndex = ++nIndex_1;
      }
      v14 = 2 * nArgLength;
      v15 = *(&v32 + nIndex_1);
      if ( !*(v15 + v14) )
        break;
      *(v15 + v14) = 0;
      nIndex_1 = nIndex;
      v16 = (v14 + *(&v32 + nIndex) + 2);
      ppszArgs[nIndex] = v16;
      if ( nIndex_1 == ' ' )
        break;
    }
    while ( *v16 );
  }
  if ( !LicenseCheck(L"Process Explorer", &nIndex, ppszArgs) )
    return 1;
  v17 = 0;
  if ( nIndex <= 0 )
  {
LABEL_61:
    if ( !CMainWnd::Create(hInst, nShowCmd) )
      return 0;
    v25 = LoadAcceleratorsW(hInst, L"PROCEXPLORER");
    if ( !GetMessageW(&Msg, 0, 0, 0) )
      return 0;
    while ( 1 )
    {
      v26 = ghWndThreadStack;
      if ( ghWndThreadStack )
      {
        if ( TranslateAcceleratorW(ghWndThreadStack, v25, &Msg) )
          goto LABEL_73;
        v26 = ghWndThreadStack;
      }
      if ( !ghFindDlg )
        goto LABEL_69;
      if ( !IsDialogMessageW(ghFindDlg, &Msg) )
      {
        v26 = ghWndThreadStack;
LABEL_69:
        if ( (!v26 || !IsDialogMessageW(v26, &Msg)) && !TranslateAcceleratorW(ghMainWnd, v25, &Msg) )
        {
          TranslateMessage(&Msg);
          DispatchMessageW(&Msg);
        }
      }
LABEL_73:
      if ( !GetMessageW(&Msg, 0, 0, 0) )
        return 0;
    }
  }
  while ( 2 )
  {
    v18 = ppszArgs[v17];
    v19 = (v18 + 1);
    do
    {
      v20 = *v18;
      ++v18;
    }
    while ( v20 );
    _wcsupr_s(ppszArgs[v17], ((v18 - v19) >> 1) + 1);
    v21 = ppszArgs[v17];
    v22 = *v21;
    if ( v22 != 47 && v22 != 45 )
    {
      if ( !wcsstr(v21, L"TASKMGR") )
        return sub_1003150();
LABEL_48:
      if ( v33 && !IsBuiltinAdministrative() )
      {
        v24 = sub_FC6180(lpCmdLine_1, nShowCmd, 0);
        if ( v24 )
        {
          if ( v24 != 1223 )
            ReportMsg(L"Error elevating", ghMainWnd);
          return 1;
        }
        return 0;
      }
      goto LABEL_61;
    }
    switch ( v21[1] )
    {
      case 0x45u:
        if ( GetVersion() < 6u )
          return sub_1003150();
        v33 = 1;
        goto LABEL_45;
      case 0x50u:
        if ( v21[2] == 58 )
        {
          switch ( v21[3] )
          {
            case 0x48u:
              goto LABEL_45;
            case 0x4Cu:
              v27 = 64;
              goto LABEL_44;
            case 0x4Eu:
              v27 = 32;
              goto LABEL_44;
            case 0x52u:
              v27 = 256;
LABEL_44:
              v23 = GetCurrentProcess();
              SetPriorityClass(v23, v27);
              goto LABEL_45;
            default:
              return sub_1003150();
          }
        }
        return sub_1003150();
      case 0x52u:
        if ( v21[2] != 84 )
          return sub_1003150();
        Command_ReplaceTaskManager(0);
        return 0;
      case 0x53u:
        if ( v21[2] != 58 )
          return sub_1003150();
        gdwProcessId_0 = _wtoi(v21 + 3);
        goto LABEL_45;
      case 0x54u:
        gbHide = 1;
LABEL_45:
        if ( ++v17 >= nIndex )
          goto LABEL_48;
        continue;
      default:
        if ( GetVersion() < 6u )
          MessageBoxW(
            0,
            L"Usage: Process Explorer [/t] [/p:[r|h|l]] [/s:<PID>]\n"
             "\n"
             "/t\tStart minimized in the tray\n"
             "/p\tRun at priority: realtime (r), high (h), normal (n) or low (l)\n"
             "/s\tSelect the specified process\n",
            L"Process Explorer",
            0x40u);
        else
          MessageBoxW(
            0,
            L"Usage: Process Explorer [/e] [/t] [/p:[r|h|l]] [/s:<PID>]\n"
             "\n"
             "/e\tRequest UAC elevation\n"
             "/t\tStart minimized in the tray\n"
             "/p\tRun at priority: realtime (r), high (h), normal (n) or low (l)\n"
             "/s\tSelect the specified process\n",
            L"Process Explorer",
            0x40u);
        result = -1;
        break;
    }
    return result;
  }
}
// 1041D84: using guessed type wchar_t aErrorElevating[16];
// 105E100: using guessed type int gdwProcessId_0;
// 1064E54: using guessed type int gdwVersion;
// 106A388: using guessed type char gbHide;
// 106A38C: using guessed type int gszCmdLine;
// 106B1CC: using guessed type int gdwTebAddressOffset;

//----- (010036C0) --------------------------------------------------------
wchar_t *__cdecl sub_10036C0(wchar_t *Src)
{
  size_t v2; // eax
  rsize_t v3; // ebx
  wchar_t *v4; // eax
  wchar_t *v5; // esi

  if ( !Src )
    return 0;
  v2 = wcsnlen(Src, 0xFFu);
  v3 = v2 + 1;
  v4 = malloc(2 * (v2 + 1));
  v5 = v4;
  if ( !v4 || !wcscpy_s(v4, v3, Src) )
    return v5;
  free(v5);
  return 0;
}

//----- (01003720) --------------------------------------------------------
int __cdecl sub_1003720(int a1, int a2, wchar_t *a3, int a4, int a5)
{
  int *v5; // edi
  void *v6; // esi
  int v8; // edi

  v5 = a1;
  if ( !a1 || !a2 || !a3 || !a4 || !a5 )
    return -2147024809;
  v6 = malloc(0x190u);
  if ( !v6 )
    return -2147024882;
  a1 = 0;
  v8 = sub_10037B0(v5, a2, v6, &a1);
  if ( !v8 )
    v8 = sub_10038A0(a3, v6, a1, a4, a5);
  free(v6);
  return v8;
}

//----- (010037B0) --------------------------------------------------------
int __cdecl sub_10037B0(int *a1, int a2, int a3, _DWORD *a4)
{
  int *v4; // ecx
  int v5; // edi
  _DWORD *v6; // esi
  int v7; // eax
  int result; // eax
  int *v9; // ecx
  int v10; // ebx
  int v11; // [esp+8h] [ebp-8h]
  int v12; // [esp+Ch] [ebp-4h]

  v4 = a1;
  if ( !a1 )
    return -2147024809;
  if ( !a2 )
    return -2147024809;
  v5 = a3;
  if ( !a3 )
    return -2147024809;
  v6 = a4;
  if ( !a4 )
    return -2147024809;
  v7 = *a1;
  a1 = 0;
  v12 = 0;
  v11 = 0;
  result = (*(v7 + 80))(v4, L"WQL", a2, 48, 0, &a1);
  if ( result >= 0 )
  {
    v9 = a1;
    if ( a1 )
    {
      while ( 1 )
      {
        v10 = (*(*v9 + 16))(v9, -1, 1, &v12, &v11);
        if ( v10 < 0 )
        {
          if ( a1 )
            (*(*a1 + 8))(a1);
          return v10;
        }
        if ( !v11 )
          break;
        *(v5 + 4 * (*v6)++) = v12;
        if ( *v6 >= 0x64u )
        {
          (*(*v12 + 8))(v12);
          break;
        }
        v9 = a1;
        if ( !a1 )
          goto LABEL_11;
      }
      if ( !a1 )
        goto LABEL_11;
      (*(*a1 + 8))(a1);
      result = 0;
    }
    else
    {
LABEL_11:
      result = 0;
    }
  }
  return result;
}

//----- (010038A0) --------------------------------------------------------
int __cdecl sub_10038A0(wchar_t *a1, int a2, int a3, int a4, int a5)
{
  unsigned int v5; // edi
  int v6; // esi
  VARIANTARG pvarg; // [esp+4h] [ebp-18h]
  unsigned int v9; // [esp+14h] [ebp-8h]
  int Value; // [esp+18h] [ebp-4h]

  if ( !a1 || !a2 || !a4 || !a5 )
    return -2147024809;
  VariantInit(&pvarg);
  v5 = 0;
  if ( !a3 )
    return 0;
  do
  {
    v6 = *(a2 + 4 * v5);
    *(a2 + 4 * v5) = 0;
    if ( (*(*v6 + 16))(v6, L"hostprocessidentifier", 0, &pvarg, 0, 0)
      || pvarg.vt != 3
      || !pvarg.lVal
      || (Value = 0, _set_errno(0), v9 = wcstoul(a1, 0, 10), _get_errno(&Value), v9 == -1)
      || Value
      || pvarg.lVal != v9 )
    {
      (*(*v6 + 8))(v6);
    }
    else
    {
      *(a4 + 4 * (*a5)++) = v6;
      if ( *a5 >= 0x64u )
      {
        (*(*v6 + 8))(v6);
        return 0;
      }
    }
    ++v5;
  }
  while ( v5 < a3 );
  return 0;
}
// 1047564: using guessed type wchar_t aHostprocesside[22];

//----- (010039A0) --------------------------------------------------------
MACRO_HRESULT __cdecl sub_10039A0(int *a1)
{
  int v2; // edi
  void **v3; // esi

  if ( !a1 )
    return E_INVALIDARG;
  v2 = *a1;
  while ( v2 )
  {
    v3 = v2;
    v2 = *(v2 + 12);
    free(*v3);
    free(v3[1]);
    free(v3[2]);
    free(v3);
  }
  *a1 = 0;
  return 0;
}

//----- (01003A00) --------------------------------------------------------
int __cdecl sub_1003A00(int ArgList, int a2)
{
  signed int v2; // ebx
  _DWORD *v3; // esi
  HRESULT v4; // eax
  int v5; // eax
  HRESULT v6; // eax
  _DWORD *v7; // eax
  int v8; // eax
  int v9; // edi
  int v10; // esi
  int v11; // ebx
  __m128i *v12; // eax
  __int64 v14; // [esp+8h] [ebp-2A0h]
  int v15; // [esp+10h] [ebp-298h]
  _DWORD *v16; // [esp+14h] [ebp-294h]
  int v17; // [esp+18h] [ebp-290h]
  LPVOID ppv; // [esp+1Ch] [ebp-28Ch]
  IUnknown *pProxy; // [esp+20h] [ebp-288h]
  wchar_t Dst; // [esp+24h] [ebp-284h]
  char v21; // [esp+9Ch] [ebp-20Ch]
  wchar_t Src; // [esp+224h] [ebp-84h]

  MakeDeviceName(&Src, L"%d", ArgList);
  if ( !a2 )
    return -2147024809;
  ppv = 0;
  v2 = 0;
  pProxy = 0;
  v3 = 0;
  v4 = CoCreateInstance(&CLSID_WbemLocator, 0, 1u, &IID_IWbemLocator, &ppv);
  if ( v4 < 0 )
  {
    v2 = v4;
    goto LABEL_24;
  }
  v5 = (*(*ppv + 12))(ppv, L"root/cimv2", 0, 0, 0, 0, 0, 0, &pProxy);
  if ( v5 < 0 )
  {
    v2 = v5;
    goto LABEL_24;
  }
  v6 = CoSetProxyBlanket(pProxy, 0xAu, 0, 0, 3u, 3u, 0, 0);
  if ( v6 < 0 )
  {
    v2 = v6;
    goto LABEL_24;
  }
  qmemcpy(&Dst, L"select * from msft_providers where HostProcessIdentifier = ", 0x78u);
  memset(&v21, 0, 0x186u);
  if ( wcscat_s(&Dst, 0xFFu, &Src) )
  {
    v2 = -2147418113;
    v3 = 0;
    goto LABEL_24;
  }
  v7 = malloc(0x190u);
  v3 = v7;
  v16 = v7;
  if ( !v7 )
  {
    v2 = -2147024882;
    goto LABEL_24;
  }
  v17 = 0;
  if ( sub_10037B0(pProxy, &Dst, v7, &v17) )
  {
    v8 = sub_1003720(pProxy, L"select * from msft_providers", &Src, v3, &v17);
    if ( v8 )
    {
      v2 = v8;
      goto LABEL_24;
    }
  }
  v9 = 0;
  if ( v17 > 0 )
  {
    while ( 1 )
    {
      v10 = v3[v9];
      v14 = 0i64;
      v15 = 0;
      if ( !sub_1003CB0(v10, ppv, &v14) )
      {
        v11 = v15;
        if ( v15 )
        {
          if ( v14 && HIDWORD(v14) )
          {
            v12 = malloc(0x10u);
            if ( !v12 )
            {
              (*(*v10 + 8))(v10);
              v3 = v16;
              v2 = -2147024882;
              break;
            }
            _mm_storel_epi64(v12, _mm_loadl_epi64(&v14));
            v12->m128i_i32[2] = v11;
            v12->m128i_i32[3] = *a2;
            *a2 = v12;
          }
        }
      }
      (*(*v10 + 8))(v10);
      v3 = v16;
      if ( ++v9 >= v17 )
      {
        v2 = 0;
        break;
      }
    }
  }
LABEL_24:
  if ( pProxy )
    pProxy->lpVtbl->Release(pProxy);
  if ( ppv )
    (*(*ppv + 8))(ppv);
  if ( v3 )
    free(v3);
  return v2;
}
// 1047494: using guessed type wchar_t aRootCimv2[11];
// 10474B0: using guessed type wchar_t aSelectFromMsft[60];
// 1047528: using guessed type wchar_t aSelectFromMsft_0[29];

//----- (01003CB0) --------------------------------------------------------
signed int __cdecl sub_1003CB0(int a1, int a2, void **a3)
{
  void **v3; // edi
  signed int v4; // ebx
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  const wchar_t *v11; // esi
  wchar_t *v12; // eax
  wchar_t *v13; // eax
  wchar_t *v14; // eax
  VARIANTARG v16; // [esp+8h] [ebp-654h]
  VARIANTARG pvarg; // [esp+18h] [ebp-644h]
  VARIANTARG v18; // [esp+28h] [ebp-634h]
  DWORD cbData; // [esp+38h] [ebp-624h]
  int v20; // [esp+3Ch] [ebp-620h]
  int v21; // [esp+40h] [ebp-61Ch]
  HKEY phkResult; // [esp+44h] [ebp-618h]
  int v23; // [esp+48h] [ebp-614h]
  int v24; // [esp+4Ch] [ebp-610h]
  int v25; // [esp+50h] [ebp-60Ch]
  void **v26; // [esp+54h] [ebp-608h]
  wchar_t Data[256]; // [esp+58h] [ebp-604h]
  wchar_t Dst; // [esp+258h] [ebp-404h]
  char v29; // [esp+2B2h] [ebp-3AAh]
  WCHAR SubKey[8]; // [esp+458h] [ebp-204h]
  __int128 v31; // [esp+468h] [ebp-1F4h]
  __int128 v32; // [esp+478h] [ebp-1E4h]
  char v33; // [esp+488h] [ebp-1D4h]

  v20 = a2;
  v3 = a3;
  v26 = a3;
  if ( !a1 || !a2 || !a3 )
    return -2147024809;
  v23 = 0;
  v24 = 0;
  v4 = 0;
  v21 = 0;
  v25 = 0;
  VariantInit(&pvarg);
  VariantInit(&v18);
  v5 = (*(*a1 + 16))(a1, L"namespace", 0, &pvarg, 0, 0);
  if ( !v5 )
  {
    v6 = (*(*a1 + 16))(a1, L"provider", 0, &v18, 0, 0);
    if ( v6 )
    {
      v4 = v6;
      goto LABEL_38;
    }
    if ( v18.vt != 8 || pvarg.vt != 8 || !v18.lVal || !pvarg.lVal )
    {
      v4 = -2147418113;
      goto LABEL_38;
    }
    v7 = (*(*v20 + 12))(v20, pvarg.lVal, 0, 0, 0, 0, 0, 0, &v25);
    if ( v7 < 0 )
    {
      v4 = v7;
      goto LABEL_38;
    }
    qmemcpy(&Dst, L"select * from __win32provider where Name = '", 0x5Au);
    memset(&v29, 0, 0x1A4u);
    if ( !wcscat_s(&Dst, 0xFFu, v18.bstrVal) && !wcscat_s(&Dst, 0xFFu, L"'") )
    {
      v8 = (*(*v25 + 80))(v25, L"WQL", &Dst, 48, 0, &v23);
      if ( v8 )
      {
        v4 = v8;
LABEL_37:
        v3 = v26;
        goto LABEL_38;
      }
      v9 = (*(*v23 + 16))(v23, -1, 1, &v24, &v21);
      if ( v9 )
      {
        v4 = v9;
        goto LABEL_37;
      }
      VariantInit(&v16);
      v10 = (*(*v24 + 16))(v24, L"clsid", 0, &v16, 0, 0);
      if ( v10 )
      {
        v4 = v10;
        goto LABEL_37;
      }
      if ( v16.vt != 8 )
        goto LABEL_37;
      v11 = v16.bstrVal;
      if ( !v16.lVal )
        goto LABEL_37;
      _mm_storeu_si128(SubKey, _mm_loadu_si128(&xmmword_1047624));
      _mm_storeu_si128(&v31, _mm_loadu_si128(&xmmword_1047634));
      _mm_storeu_si128(&v32, _mm_loadu_si128(&xmmword_1047644));
      memset(&v33, 0, 0x1CEu);
      if ( !wcscat_s(SubKey, 0xFFu, v11)
        && !wcscat_s(SubKey, 0xFFu, L"\\InprocServer32")
        && !RegOpenKeyExW(HKEY_LOCAL_MACHINE, SubKey, 0, 0x20119u, &phkResult) )
      {
        memset(Data, 0, 0x1FEu);
        cbData = 510;
        if ( !RegQueryValueExW(phkResult, &gszNullString, 0, 0, Data, &cbData) )
        {
          v12 = sub_10036C0(v18.bstrVal);
          v3 = v26;
          *v26 = v12;
          if ( v12 )
          {
            v13 = sub_10036C0(pvarg.bstrVal);
            v3[1] = v13;
            if ( v13 )
            {
              v14 = sub_10036C0(Data);
              v3[2] = v14;
              if ( v14 )
                RegCloseKey(phkResult);
              else
                v4 = -2147024882;
            }
            else
            {
              v4 = -2147024882;
            }
          }
          else
          {
            v4 = -2147024882;
          }
          goto LABEL_38;
        }
      }
    }
    v4 = -2147418113;
    goto LABEL_37;
  }
  v4 = v5;
LABEL_38:
  if ( v24 )
    (*(*v24 + 8))(v24);
  if ( v23 )
    (*(*v23 + 8))(v23);
  if ( v25 )
    (*(*v25 + 8))(v25);
  VariantClear(&pvarg);
  VariantClear(&v18);
  if ( v4 )
  {
    if ( *v3 )
      free(*v3);
    if ( v3[1] )
      free(v3[1]);
    if ( v3[2] )
      free(v3[2]);
  }
  return v4;
}
// 1047590: using guessed type wchar_t aNamespace_0[10];
// 10475A4: using guessed type wchar_t aProvider[9];
// 10475B8: using guessed type wchar_t aSelectFromWin3[45];
// 1047618: using guessed type wchar_t aClsid_0[6];
// 1047624: using guessed type __int128 xmmword_1047624;
// 1047634: using guessed type __int128 xmmword_1047634;
// 1047644: using guessed type __int128 xmmword_1047644;

//----- (01004170) --------------------------------------------------------
void __stdcall __noreturn _com_issue_error(int a1)
{
  ATL::_com_error::_com_error(a1, 0);
}
// 106138C: using guessed type int (__cdecl *ATL::_com_error::_com_error)(_DWORD, _DWORD);

//----- (01004190) --------------------------------------------------------
_DWORD *__thiscall sub_1004190(_DWORD *this, int a2)
{
  _DWORD *v2; // esi
  int v3; // ecx

  v2 = this;
  *this = &ATL::_com_error::`vftable';
  this[1] = *(a2 + 4);
  v3 = *(a2 + 8);
  v2[2] = v3;
  v2[3] = 0;
  if ( v3 )
    (*(*v3 + 4))(v3);
  return v2;
}
// 1047BCC: using guessed type int (__thiscall *ATL::_com_error::`vftable')(void *, char);

//----- (010041D0) --------------------------------------------------------
HLOCAL __thiscall ATL::_com_error::~_com_error(ATL::_com_error *this)
{
  ATL::_com_error *v1; // esi
  int v2; // ecx
  HLOCAL result; // eax

  v1 = this;
  v2 = *(this + 2);
  *v1 = &ATL::_com_error::`vftable';
  if ( v2 )
    (*(*v2 + 8))(v2);
  result = *(v1 + 3);
  if ( result )
    result = LocalFree(*(v1 + 3));
  return result;
}
// 1047BCC: using guessed type int (__thiscall *ATL::_com_error::`vftable')(void *, char);

//----- (01004200) --------------------------------------------------------
HLOCAL *__thiscall ATL::_com_error::`scalar deleting destructor'(void *this, char a2)
{
  HLOCAL *v2; // esi
  int v3; // ecx

  v2 = this;
  v3 = *(this + 2);
  *v2 = &ATL::_com_error::`vftable';
  if ( v3 )
    (*(*v3 + 8))(v3);
  if ( v2[3] )
    LocalFree(v2[3]);
  if ( a2 & 1 )
    j__free(v2);
  return v2;
}
// 1047BCC: using guessed type int (__thiscall *ATL::_com_error::`vftable')(void *, char);

//----- (01004240) --------------------------------------------------------
void __cdecl __noreturn sub_1004240(int a1, int a2)
{
  int (__thiscall **v2)(void *, char); // [esp+0h] [ebp-10h]
  int v3; // [esp+4h] [ebp-Ch]
  int v4; // [esp+8h] [ebp-8h]
  int v5; // [esp+Ch] [ebp-4h]

  v3 = a1;
  v4 = a2;
  v2 = &ATL::_com_error::`vftable';
  v5 = 0;
  _CxxThrowException(&v2, &_TI1_AV_com_error__);
}
// 10081AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);
// 1047BCC: using guessed type int (__thiscall *ATL::_com_error::`vftable')(void *, char);
// 1055BFC: using guessed type int _TI1_AV_com_error__;

//----- (01004270) --------------------------------------------------------
CHAR *__stdcall sub_1004270(LPCWSTR lpWideCharStr)
{
  unsigned int v2; // kr00_4
  int v3; // eax
  int v4; // ebx
  int v5; // eax
  CHAR *v6; // eax
  CHAR *v7; // esi
  int v8; // eax
  int v9; // [esp+0h] [ebp-20h]
  int *v10; // [esp+10h] [ebp-10h]
  int v11; // [esp+1Ch] [ebp-4h]

  v10 = &v9;
  if ( !lpWideCharStr )
    return 0;
  v2 = wcslen(lpWideCharStr);
  v3 = WideCharToMultiByte(0, 0, lpWideCharStr, v2 + 1, 0, 0, 0, 0);
  v4 = v3;
  if ( !v3 )
  {
    v5 = GetLastError();
    if ( v5 > 0 )
      v5 = v5 | 0x80070000;
    _com_issue_error(v5);
  }
  v11 = 0;
  v6 = operator new(v3);
  v7 = v6;
  v11 = -1;
  if ( !v6 )
    _com_issue_error(-2147024882);
  if ( !WideCharToMultiByte(0, 0, lpWideCharStr, v2 + 1, v6, v4, 0, 0) )
  {
    j__free(v7);
    v8 = GetLastError();
    if ( v8 > 0 )
      v8 = v8 | 0x80070000;
    _com_issue_error(v8);
  }
  return v7;
}

//----- (01004390) --------------------------------------------------------
BSTR __stdcall _com_util::ConvertBSTRToString(LPCSTR lpszText)
{
  int nLength; // eax
  int ret; // eax
  int ret_1; // edi
  int v5; // eax
  int v6; // eax
  void *v7; // esp
  WCHAR *pBuf; // esi
  int v9; // eax
  BSTR v10; // ebx
  WCHAR v11[8]; // [esp+0h] [ebp-38h]
  int v12; // [esp+10h] [ebp-28h]
  WCHAR *pWideString; // [esp+14h] [ebp-24h]
  int cbMultiByte; // [esp+18h] [ebp-20h]
  CPPEH_RECORD ms_exc; // [esp+20h] [ebp-18h]

  if ( !lpszText )
    return 0;
  nLength = lstrlenA(lpszText);
  cbMultiByte = nLength + 1;
  ret = MultiByteToWideChar(CP_ACP, 0, lpszText, nLength + 1, 0, 0);
  ret_1 = ret;
  v12 = ret;
  if ( !ret )
  {
    v5 = GetLastError();
    if ( v5 > 0 )
      v5 = v5 | 0x80070000;
    _com_issue_error(v5);
  }
  ms_exc.registration.TryLevel = 0;
  v6 = 2 * ret;
  if ( ret_1 >= 4096 )
  {
    pBuf = malloc(2 * ret_1);
    pWideString = pBuf;
  }
  else
  {
    v7 = alloca(v6);
    ms_exc.old_esp = v11;
    pBuf = v11;
    pWideString = v11;
  }
  ms_exc.registration.TryLevel = -2;
  if ( !pBuf )
    _com_issue_error(E_OUTOFMEMORY);
  if ( !MultiByteToWideChar(0, 0, lpszText, cbMultiByte, pBuf, ret_1) )
  {
    if ( ret_1 >= 4096 )
      free(pBuf);
    v9 = GetLastError();
    if ( v9 > 0 )
      v9 = v9 | 0x80070000;
    _com_issue_error(v9);
  }
  v10 = SysAllocString(pBuf);
  if ( ret_1 >= 4096 )
    free(pBuf);
  if ( !v10 )
    _com_issue_error(E_OUTOFMEMORY);
  return v10;
}

//----- (01004501) --------------------------------------------------------
std::exception *__thiscall sub_1004501(std::exception *this, struct exception *a2)
{
  std::exception *v2; // esi

  v2 = this;
  std::exception::exception(this, a2);
  *v2 = &std::bad_alloc::`vftable';
  return v2;
}
// 1047BD4: using guessed type void *std::bad_alloc::`vftable';

//----- (0100451C) --------------------------------------------------------
std::exception *__thiscall sub_100451C(std::exception *this, struct exception *a2)
{
  std::exception *v2; // esi

  v2 = this;
  std::exception::exception(this, a2);
  *v2 = &std::length_error::`vftable';
  return v2;
}
// 1047BFC: using guessed type void *std::length_error::`vftable';

//----- (01004537) --------------------------------------------------------
std::exception *__thiscall sub_1004537(std::exception *this, struct exception *a2)
{
  std::exception *v2; // esi

  v2 = this;
  std::exception::exception(this, a2);
  *v2 = &std::logic_error::`vftable';
  return v2;
}
// 1047BF0: using guessed type void *std::logic_error::`vftable';

//----- (01004552) --------------------------------------------------------
std::exception *__thiscall sub_1004552(std::exception *this, struct exception *a2)
{
  std::exception *v2; // esi

  v2 = this;
  std::exception::exception(this, a2);
  *v2 = &std::out_of_range::`vftable';
  return v2;
}
// 1047C08: using guessed type void *std::out_of_range::`vftable';

//----- (0100456D) --------------------------------------------------------
void __thiscall sub_100456D(std::exception *this)
{
  *this = &std::bad_alloc::`vftable';
  sub_1009D91(this);
}
// 1047BD4: using guessed type void *std::bad_alloc::`vftable';

//----- (01004585) --------------------------------------------------------
void *__thiscall sub_1004585(void *this, char a2)
{
  void *v2; // esi

  v2 = this;
  *this = &std::bad_alloc::`vftable';
  sub_1009D91(this);
  if ( a2 & 1 )
    j__free(v2);
  return v2;
}
// 1047BD4: using guessed type void *std::bad_alloc::`vftable';

//----- (010045AA) --------------------------------------------------------
void *__thiscall sub_10045AA(void *this, char a2)
{
  void *v2; // esi

  v2 = this;
  sub_1009D91(this);
  if ( a2 & 1 )
    j__free(v2);
  return v2;
}

//----- (0100465F) --------------------------------------------------------
int __cdecl sub_100465F(int a1)
{
  _DWORD *v1; // eax

  v1 = &unk_1047E68;
  if ( !"address family not supported" )
    return 0;
  while ( *v1 != a1 )
  {
    v1 += 2;
    if ( !v1[1] )
      return 0;
  }
  return v1[1];
}

//----- (01004689) --------------------------------------------------------
int __cdecl sub_1004689(int a1)
{
  int *v1; // eax

  v1 = &dword_1047C10;
  if ( !"permission denied" )
    return 0;
  while ( *v1 != a1 )
  {
    v1 += 2;
    if ( !v1[1] )
      return 0;
  }
  return v1[1];
}
// 1047C10: using guessed type int dword_1047C10;

//----- (01004C4A) --------------------------------------------------------
int sub_1004C4A()
{
  return *&dword_1085844;
}

//----- (01004F3E) --------------------------------------------------------
void __cdecl sub_1004F3E(LPCRITICAL_SECTION lpCriticalSection)
{
  EnterCriticalSection(lpCriticalSection);
}

//----- (01004F4C) --------------------------------------------------------
void __cdecl sub_1004F4C(LPCRITICAL_SECTION lpCriticalSection)
{
  LeaveCriticalSection(lpCriticalSection);
}

//----- (01004FDB) --------------------------------------------------------
CAtlBaseModule *__thiscall ATL::CAtlWinModule::CAtlWinModule(char *this)
{
  CAtlBaseModule *v1; // esi

  v1 = this;
  ATL::_ATL_WIN_MODULE70::_ATL_WIN_MODULE70(this);
  v1->baseclass.cbSize = 56;
  v1->baseclass.m_hInstResource = 16187392;
  v1->baseclass.m_hInst = 16187392;
  v1->baseclass.dwAtlBuildVer = 0xC00;
  v1->baseclass.pguidVer = &GUID_ATLVer110;
  if ( ATL::CComCriticalSection::Init(&v1->baseclass.m_csResource.m_Lock) < 0 )
  {
    if ( IsDebuggerPresent() )
      OutputDebugStringW(L"ERROR : Unable to initialize critical section in CAtlBaseModule\n");
    ATL::CAtlBaseModule::m_bInitFailed = 1;
  }
  return v1;
}
// 1048AF0: using guessed type GUID GUID_ATLVer110;
// 1085714: using guessed type char ATL::CAtlBaseModule::m_bInitFailed;

//----- (0100502E) --------------------------------------------------------
_DWORD *__thiscall ATL::_ATL_WIN_MODULE70::_ATL_WIN_MODULE70(_DWORD *this)
{
  _DWORD *v1; // esi
  _DWORD *result; // eax

  v1 = this;
  memset(this + 5, 0, 0x18u);
  v1[11] = 0;
  v1[12] = 0;
  result = v1;
  v1[13] = 0;
  return result;
}

//----- (01005051) --------------------------------------------------------
void __thiscall ATL::CAtlBaseModule::~CAtlBaseModule(int this)
{
  int v1; // esi
  void **v2; // ecx
  void **v3; // esi

  v1 = this;
  DeleteCriticalSection((this + 20));
  v2 = (v1 + 44);
  v3 = v2;
  if ( *v2 )
  {
    free(*v2);
    *v3 = 0;
  }
  v3[1] = 0;
  v3[2] = 0;
}

//----- (01005067) --------------------------------------------------------
int __thiscall ATL::CSimpleArray<HINSTANCE__ *,ATL::CSimpleArrayEqualHelper<HINSTANCE__ *>>::operator[](_DWORD *this, int a2)
{
  if ( a2 < 0 || a2 >= this[1] )
  {
    RaiseException(STATUS_ARRAY_BOUNDS_EXCEEDED, 1u, 0, 0);
    JUMPOUT(loc_1005090);
  }
  return *this + 4 * a2;
}

//----- (01005091) --------------------------------------------------------
CHAR *__thiscall ATL::CAtlBaseModule::GetHInstanceAt(CAtlBaseModule *this, int a2)
{
  CAtlBaseModule *v2; // esi
  struct _RTL_CRITICAL_SECTION *v3; // edi
  HINSTANCE v4; // esi

  v2 = this;
  v3 = &this->baseclass.m_csResource.m_Lock;
  EnterCriticalSection(&this->baseclass.m_csResource.m_Lock);
  if ( a2 > v2->baseclass.m_rgResourceInstance.m_nSize || a2 < 0 )
  {
    v4 = 0;
  }
  else if ( a2 == v2->baseclass.m_rgResourceInstance.m_nSize )
  {
    v4 = v2->baseclass.m_hInstResource;
  }
  else
  {
    v4 = *ATL::CSimpleArray<HINSTANCE__ *,ATL::CSimpleArrayEqualHelper<HINSTANCE__ *>>::operator[](
            &v2->baseclass.m_rgResourceInstance.m_aT,
            a2);
  }
  LeaveCriticalSection(v3);
  return v4;
}

//----- (01007B15) --------------------------------------------------------
void **sub_1007B15()
{
  return &off_1061568;
}
// 1061568: using guessed type void *off_1061568;

//----- (010089CE) --------------------------------------------------------
int __thiscall sub_10089CE(_DWORD *this)
{
  *this = &type_info::`vftable';
  return unknown_libname_8(this);
}
// 1015348: using guessed type _DWORD __cdecl unknown_libname_8(_DWORD);
// 1048BE8: using guessed type void *type_info::`vftable';

//----- (010089FA) --------------------------------------------------------
void *__thiscall sub_10089FA(void *this, char a2)
{
  void *v2; // esi

  v2 = this;
  sub_10089CE(this);
  if ( a2 & 1 )
    j__free(v2);
  return v2;
}

//----- (0100918B) --------------------------------------------------------
int sub_100918B()
{
  return flsall(1);
}
// 10091ED: using guessed type _DWORD __cdecl flsall(_DWORD);

//----- (01009CF7) --------------------------------------------------------
std::exception *__thiscall sub_1009CF7(std::exception *this, struct exception *a2)
{
  std::exception *v2; // esi

  v2 = this;
  std::exception::exception(this, a2);
  *v2 = &std::bad_cast::`vftable';
  return v2;
}
// 1048FEC: using guessed type void *std::bad_cast::`vftable';

//----- (01009D12) --------------------------------------------------------
std::exception *__thiscall sub_1009D12(std::exception *this, char *a2)
{
  std::exception *v2; // esi

  v2 = this;
  std::exception::exception(this, &a2);
  *v2 = &std::bad_cast::`vftable';
  return v2;
}
// 1048FEC: using guessed type void *std::bad_cast::`vftable';

//----- (01009D91) --------------------------------------------------------
void __thiscall sub_1009D91(std::exception *this)
{
  *this = &std::exception::`vftable';
  std::exception::_Tidy(this);
}
// 1048FCC: using guessed type void *std::exception::`vftable';

//----- (01009DCF) --------------------------------------------------------
void *__thiscall sub_1009DCF(void *this, char a2)
{
  void *v2; // esi

  v2 = this;
  *this = &std::exception::`vftable';
  std::exception::_Tidy(this);
  if ( a2 & 1 )
    j__free(v2);
  return v2;
}
// 1048FCC: using guessed type void *std::exception::`vftable';

//----- (0100B822) --------------------------------------------------------
std::exception *__thiscall sub_100B822(std::exception *this, struct exception *a2)
{
  std::exception *v2; // esi

  v2 = this;
  std::exception::exception(this, a2);
  *v2 = &std::bad_exception::`vftable';
  return v2;
}
// 1048FFC: using guessed type void *std::bad_exception::`vftable';

//----- (0100B83D) --------------------------------------------------------
void __thiscall sub_100B83D(std::exception *this)
{
  *this = &std::bad_exception::`vftable';
  sub_1009D91(this);
}
// 1048FFC: using guessed type void *std::bad_exception::`vftable';

//----- (0100B848) --------------------------------------------------------
void *__thiscall sub_100B848(void *this, char a2)
{
  void *v2; // esi

  v2 = this;
  *this = &std::bad_exception::`vftable';
  sub_1009D91(this);
  if ( a2 & 1 )
    j__free(v2);
  return v2;
}
// 1048FFC: using guessed type void *std::bad_exception::`vftable';

//----- (0100D342) --------------------------------------------------------
void __cdecl sub_100D342(DWORD dwMilliseconds)
{
  Sleep(dwMilliseconds);
}

//----- (0100F821) --------------------------------------------------------
void *__cdecl sub_100F821(void *a1)
{
  void *result; // eax

  result = a1;
  dword_1085EBC = a1;
  return result;
}

//----- (0100F8CF) --------------------------------------------------------
void *__cdecl sub_100F8CF(void *a1)
{
  void *result; // eax

  result = a1;
  dword_1085EC4 = a1;
  return result;
}

//----- (0100FAF6) --------------------------------------------------------
DWORD sub_100FAF6()
{
  return dwTlsIndex;
}

//----- (0101007A) --------------------------------------------------------
void sub_101007A()
{
  dword_10869AC = 0;
}
// 10869AC: using guessed type int dword_10869AC;

//----- (0101533B) --------------------------------------------------------
void *__cdecl sub_101533B(void *a1)
{
  void *result; // eax

  result = a1;
  dword_1086628 = a1;
  return result;
}

//----- (01017C9C) --------------------------------------------------------
void sub_1017C9C()
{
  void (**i)(void); // esi

  for ( i = &unk_104F88C; i < &unk_104F88C; ++i )
  {
    if ( *i )
      (*i)();
  }
}

//----- (01017CBC) --------------------------------------------------------
void __cdecl sub_1017CBC()
{
  void (**i)(void); // esi

  for ( i = &unk_104F894; i < &unk_104F894; ++i )
  {
    if ( *i )
      (*i)();
  }
}

//----- (01017CDC) --------------------------------------------------------
PVOID sub_1017CDC()
{
  return DecodePointer(dword_108663C);
}

//----- (01017EFA) --------------------------------------------------------
int __cdecl sub_1017EFA(int a1)
{
  int result; // eax

  result = a1;
  dword_1086648 = a1;
  return result;
}
// 1086648: using guessed type int dword_1086648;

//----- (01018B73) --------------------------------------------------------
HANDLE sub_1018B73()
{
  HANDLE result; // eax

  result = hObject;
  if ( hObject != -1 && hObject != -2 )
    result = CloseHandle(hObject);
  return result;
}

//----- (01019F90) --------------------------------------------------------
int sub_1019F90()
{
  __crtSetUnhandledExceptionFilter(__CxxUnhandledExceptionFilter);
  return 0;
}

//----- (0101A2BD) --------------------------------------------------------
int __cdecl sub_101A2BD(int a1)
{
  int result; // eax

  result = a1;
  dword_1085EC8 = a1;
  return result;
}
// 1085EC8: using guessed type int dword_1085EC8;

//----- (0101B1A0) --------------------------------------------------------
int *sub_101B1A0()
{
  return &dword_1062434;
}
// 1062434: using guessed type int dword_1062434;

//----- (0101B1A6) --------------------------------------------------------
int *sub_101B1A6()
{
  return &dword_1062438;
}
// 1062438: using guessed type int dword_1062438;

//----- (0101B1AC) --------------------------------------------------------
int *sub_101B1AC()
{
  return &dword_1062430;
}
// 1062430: using guessed type int dword_1062430;

//----- (0101B1B2) --------------------------------------------------------
void **sub_101B1B2()
{
  return &off_10624C0;
}
// 10624C0: using guessed type void *off_10624C0;

//----- (0101B1B8) --------------------------------------------------------
signed int __cdecl sub_101B1B8(_DWORD *a1)
{
  signed int result; // eax

  if ( a1 )
  {
    *a1 = dword_1062434;
    result = 0;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    result = 22;
  }
  return result;
}
// 100F859: using guessed type int _invalid_parameter_noinfo(void);
// 1062434: using guessed type int dword_1062434;

//----- (0101B1E2) --------------------------------------------------------
signed int __cdecl sub_101B1E2(_DWORD *a1)
{
  signed int result; // eax

  if ( a1 )
  {
    *a1 = dword_1062438;
    result = 0;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    result = 22;
  }
  return result;
}
// 100F859: using guessed type int _invalid_parameter_noinfo(void);
// 1062438: using guessed type int dword_1062438;

//----- (0101B20C) --------------------------------------------------------
signed int __cdecl sub_101B20C(_DWORD *a1)
{
  signed int result; // eax

  if ( a1 )
  {
    *a1 = dword_1062430;
    result = 0;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    result = 22;
  }
  return result;
}
// 100F859: using guessed type int _invalid_parameter_noinfo(void);
// 1062430: using guessed type int dword_1062430;

//----- (0101B5FC) --------------------------------------------------------
int __cdecl sub_101B5FC(const WCHAR *a1, int a2, int a3)
{
  int v3; // esi
  PVOID v4; // edi
  HMODULE v5; // edi
  FARPROC v6; // eax
  FARPROC v7; // eax
  FARPROC v8; // eax
  FARPROC v9; // eax
  FARPROC v10; // eax
  PVOID v12; // eax
  int v13; // eax
  int v14; // edi
  int (*v15)(void); // eax
  int (__stdcall *v16)(int); // eax
  int (__stdcall *v17)(int, LPCWSTR, int, int); // eax
  char v19; // [esp+Ch] [ebp-24h]
  int v20; // [esp+10h] [ebp-20h]
  LPCWSTR lpOutputString; // [esp+14h] [ebp-1Ch]
  int (__stdcall *v22)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD); // [esp+18h] [ebp-18h]
  int (*v23)(void); // [esp+1Ch] [ebp-14h]
  char v24; // [esp+20h] [ebp-10h]
  char v25; // [esp+28h] [ebp-8h]

  lpOutputString = a1;
  v3 = 0;
  v20 = a2;
  v4 = EncodePointer(0);
  v22 = v4;
  v23 = __crtIsPackagedApp();
  if ( !dword_108694C )
  {
    v5 = LoadLibraryExW(L"USER32.DLL", 0, 0x800u);
    if ( !v5 )
    {
      if ( GetLastError() != 87 )
        return 0;
      v5 = LoadLibraryExW(L"USER32.DLL", 0, 0);
      if ( !v5 )
        return 0;
    }
    v6 = GetProcAddress(v5, "MessageBoxW");
    if ( !v6 )
      return 0;
    dword_108694C = EncodePointer(v6);
    v7 = GetProcAddress(v5, "GetActiveWindow");
    dword_1086950 = EncodePointer(v7);
    v8 = GetProcAddress(v5, "GetLastActivePopup");
    dword_1086954 = EncodePointer(v8);
    v9 = GetProcAddress(v5, "GetUserObjectInformationW");
    dword_108695C = EncodePointer(v9);
    if ( dword_108695C )
    {
      v10 = GetProcAddress(v5, "GetProcessWindowStation");
      dword_1086958 = EncodePointer(v10);
    }
    v4 = v22;
  }
  if ( IsDebuggerPresent() )
  {
    if ( lpOutputString )
      OutputDebugStringW(lpOutputString);
    if ( v23 )
      return 4;
  }
  else if ( v23 )
  {
    DecodePointer(dword_108694C);
    return 3;
  }
  if ( dword_1086958 == v4
    || dword_108695C == v4
    || (v23 = DecodePointer(dword_1086958), v12 = DecodePointer(dword_108695C), v22 = v12, !v23)
    || !v12
    || (v13 = v23()) != 0 && v22(v13, 1, &v24, 12, &v19) && v25 & 1 )
  {
    if ( dword_1086950 != v4 )
    {
      v15 = DecodePointer(dword_1086950);
      if ( v15 )
      {
        v3 = v15();
        if ( v3 )
        {
          if ( dword_1086954 != v4 )
          {
            v16 = DecodePointer(dword_1086954);
            if ( v16 )
              v3 = v16(v3);
          }
        }
      }
    }
    v14 = a3;
  }
  else
  {
    v14 = a3 | 0x200000;
  }
  v17 = DecodePointer(dword_108694C);
  if ( v17 )
    return v17(v3, lpOutputString, v20, v14);
  return 0;
}
// 100D069: using guessed type int __crtIsPackagedApp(void);

//----- (0101F550) --------------------------------------------------------
int sub_101F550()
{
  return 0;
}

//----- (0101FE30) --------------------------------------------------------
signed int __cdecl sub_101FE30(unsigned __int16 *a1, int *a2)
{
  signed int v2; // ebx
  int *v3; // edi
  int v4; // edx
  int v5; // esi
  int v6; // eax
  int v7; // edx
  char v8; // cl
  bool i; // zf
  int v10; // edx
  unsigned int v11; // eax
  bool v12; // cf
  unsigned int v13; // eax
  signed int v14; // ecx
  int j; // edx
  unsigned int v16; // eax
  unsigned int v17; // eax
  int v18; // ecx
  int v19; // eax
  unsigned int v20; // edx
  int *v21; // edx
  int v22; // eax
  signed int v23; // ecx
  int v24; // edx
  int v25; // ecx
  char v26; // cl
  bool k; // zf
  int v28; // edx
  unsigned int v29; // eax
  signed int v30; // ecx
  unsigned int v31; // eax
  int l; // edx
  unsigned int v33; // eax
  unsigned int v34; // eax
  int v35; // edx
  int v36; // ecx
  int v37; // eax
  unsigned int v38; // edx
  int *v39; // edx
  signed int v40; // ecx
  int v41; // ecx
  int v42; // edi
  unsigned int v43; // edx
  unsigned int v44; // eax
  int v45; // edx
  int *v46; // edx
  signed int v47; // ecx
  int v48; // ecx
  signed int v49; // esi
  unsigned int v50; // edx
  int *v51; // edx
  signed int v52; // ecx
  int v53; // esi
  int v54; // eax
  int v56; // [esp+Ch] [ebp-44h]
  int v57; // [esp+14h] [ebp-3Ch]
  int v58; // [esp+14h] [ebp-3Ch]
  unsigned int v59; // [esp+18h] [ebp-38h]
  int v60; // [esp+18h] [ebp-38h]
  int v61; // [esp+18h] [ebp-38h]
  int v62; // [esp+1Ch] [ebp-34h]
  int v63; // [esp+1Ch] [ebp-34h]
  int v64; // [esp+1Ch] [ebp-34h]
  int v65; // [esp+20h] [ebp-30h]
  char v66; // [esp+20h] [ebp-30h]
  signed int v67; // [esp+24h] [ebp-2Ch]
  int v68; // [esp+28h] [ebp-28h]
  char v69; // [esp+28h] [ebp-28h]
  int v70; // [esp+28h] [ebp-28h]
  int v71; // [esp+2Ch] [ebp-24h]
  unsigned int v72; // [esp+2Ch] [ebp-24h]
  int v73; // [esp+30h] [ebp-20h]
  int v74; // [esp+30h] [ebp-20h]
  int v75; // [esp+30h] [ebp-20h]
  int v76; // [esp+30h] [ebp-20h]
  int v77; // [esp+30h] [ebp-20h]
  int v78; // [esp+34h] [ebp-1Ch]
  int v79; // [esp+38h] [ebp-18h]
  int v80; // [esp+3Ch] [ebp-14h]
  int v81; // [esp+40h] [ebp-10h]
  int v82; // [esp+44h] [ebp-Ch]
  int v83; // [esp+48h] [ebp-8h]

  v2 = 0;
  v3 = a2;
  v56 = a1[5] & 0x8000;
  v4 = (a1[5] & 0x7FFF) - 0x3FFF;
  v81 = *(a1 + 3);
  v82 = *(a1 + 1);
  v73 = v4;
  v83 = *a1 << 16;
  if ( v4 == -16383 )
  {
    v5 = 0;
    v6 = 0;
    while ( !*(&v81 + v6) )
    {
      if ( ++v6 >= 3 )
        goto LABEL_84;
    }
    v81 = 0;
    v82 = 0;
    v83 = 0;
  }
  else
  {
    v71 = v4;
    v78 = v81;
    v62 = dword_1062570 - 1;
    v67 = 0;
    v79 = v82;
    v80 = v83;
    v7 = dword_1062570 / 32;
    v57 = dword_1062570 / 32;
    v65 = 31 - dword_1062570 % 32;
    v8 = v65;
    if ( (1 << v65) & *(&v81 + dword_1062570 / 32) )
    {
      for ( i = (~(-1 << v65) & *(&v81 + v7)) == 0; i; i = *(&v81 + v7) == 0 )
      {
        if ( ++v7 >= 3 )
          goto LABEL_24;
      }
      v10 = v62 / 32;
      v67 = 0;
      v59 = 1 << (31 - v62 % 32);
      v11 = *(&v81 + v62 / 32);
      v12 = v11 + v59 < v11;
      v13 = v11 + v59;
      v14 = 0;
      if ( v12 || v13 < v59 )
      {
        v14 = 1;
        v67 = 1;
      }
      *(&v81 + v10) = v13;
      for ( j = v10 - 1; j >= 0; *(&v81 + j--) = v17 )
      {
        if ( !v14 )
          break;
        v16 = *(&v81 + j);
        v14 = 0;
        v67 = 0;
        v12 = v16 + 1 < v16;
        v17 = v16 + 1;
        if ( v12 || v17 < 1 )
        {
          v14 = 1;
          v67 = 1;
        }
      }
      v8 = v65;
LABEL_24:
      v7 = v57;
    }
    *(&v81 + v7) &= -1 << v8;
    if ( v7 + 1 < 3 )
      memset(&v81 + v7 + 1, 0, 4 * (3 - (v7 + 1)));
    v18 = v73;
    if ( v67 )
      v18 = v73 + 1;
    if ( v18 >= dword_106256C - dword_1062570 )
    {
      if ( v18 > dword_106256C )
      {
        if ( v18 < dword_1062568 )
        {
          v81 &= 0x7FFFFFFFu;
          v61 = v18 + dword_106257C;
          v70 = dword_1062574 / 32;
          v48 = dword_1062574 % 32;
          v77 = 0;
          v49 = 0;
          do
          {
            v50 = *(&v81 + v49);
            *(&v81 + v49++) = v77 | (v50 >> v48);
            v77 = (~(-1 << v48) & v50) << (32 - v48);
          }
          while ( v49 < 3 );
          v5 = v61;
          v51 = &v83 - v70;
          v2 = 0;
          v52 = 2;
          do
          {
            if ( v52 < v70 )
              *(&v81 + v52) = 0;
            else
              *(&v81 + v52) = *v51;
            --v51;
            --v52;
          }
          while ( v52 >= 0 );
        }
        else
        {
          v82 = 0;
          v83 = 0;
          v81 = 2147483648;
          v64 = dword_1062574 / 32;
          v41 = dword_1062574 % 32;
          v60 = dword_1062574 % 32;
          v76 = 0;
          v42 = ~(-1 << dword_1062574 % 32);
          v69 = 32 - dword_1062574 % 32;
          do
          {
            v43 = *(&v81 + v2);
            v44 = v43;
            v45 = v76 | (v43 >> v41);
            LOBYTE(v41) = v60;
            *(&v81 + v2++) = v45;
            v76 = (v42 & v44) << v69;
          }
          while ( v2 < 3 );
          v46 = &v83 - v64;
          v47 = 2;
          do
          {
            if ( v47 < v64 )
              *(&v81 + v47) = 0;
            else
              *(&v81 + v47) = *v46;
            --v46;
            --v47;
          }
          while ( v47 >= 0 );
          v5 = dword_1062568 + dword_106257C;
          v2 = 1;
        }
        goto LABEL_83;
      }
      v81 = v78;
      v82 = v79;
      v58 = (dword_106256C - v71) / 32;
      v83 = v80;
      v19 = (dword_106256C - v71) % 32;
      v74 = 0;
      do
      {
        v20 = *(&v81 + v2);
        *(&v81 + v2++) = v74 | (v20 >> v19);
        v74 = (~(-1 << v19) & v20) << (32 - v19);
      }
      while ( v2 < 3 );
      v21 = &v83 - v58;
      v22 = v58;
      v23 = 2;
      do
      {
        if ( v23 < v22 )
        {
          *(&v81 + v23) = 0;
        }
        else
        {
          *(&v81 + v23) = *v21;
          v22 = v58;
        }
        --v21;
        --v23;
      }
      while ( v23 >= 0 );
      v24 = (v62 + 1) / 32;
      v25 = (v62 + 1) % 32;
      v66 = 31 - v25;
      v26 = 31 - v25;
      if ( (1 << v26) & *(&v81 + v24) )
      {
        for ( k = (~(-1 << v26) & *(&v81 + v24)) == 0; k; k = *(&v81 + v24) == 0 )
        {
          if ( ++v24 >= 3 )
            goto LABEL_56;
        }
        v28 = v62 / 32;
        v29 = *(&v81 + v62 / 32);
        v30 = 0;
        v72 = 1 << (31 - v62 % 32);
        v12 = v29 + v72 < v29;
        v31 = v29 + v72;
        if ( v12 || v31 < v72 )
          v30 = 1;
        *(&v81 + v28) = v31;
        for ( l = v28 - 1; l >= 0; *(&v81 + l--) = v34 )
        {
          if ( !v30 )
            break;
          v33 = *(&v81 + l);
          v30 = 0;
          v12 = v33 + 1 < v33;
          v34 = v33 + 1;
          if ( v12 || v34 < 1 )
            v30 = 1;
        }
        v26 = v66;
LABEL_56:
        v24 = (v62 + 1) / 32;
      }
      *(&v81 + v24) &= -1 << v26;
      v35 = v24 + 1;
      if ( v35 < 3 )
        memset(&v81 + v35, 0, 4 * (3 - v35));
      v68 = (dword_1062574 + 1) / 32;
      v36 = (dword_1062574 + 1) % 32;
      v37 = 0;
      v75 = 0;
      v63 = 0;
      do
      {
        v38 = *(&v81 + v37);
        *(&v81 + v63) = v75 | (v38 >> v36);
        v75 = (~(-1 << v36) & v38) << (32 - v36);
        v37 = v63 + 1;
        v63 = v37;
      }
      while ( v37 < 3 );
      v39 = &v83 - v68;
      v40 = 2;
      do
      {
        if ( v40 < v68 )
          *(&v81 + v40) = 0;
        else
          *(&v81 + v40) = *v39;
        --v39;
        --v40;
      }
      while ( v40 >= 0 );
    }
    else
    {
      v81 = 0;
      v82 = 0;
      v83 = 0;
    }
    v5 = 0;
  }
  v2 = 2;
LABEL_83:
  v3 = a2;
LABEL_84:
  v53 = v81 | (v56 != 0 ? 0x80000000 : 0) | (v5 << (31 - dword_1062574));
  if ( dword_1062578 == 64 )
  {
    v54 = v82;
    v3[1] = v53;
    *v3 = v54;
  }
  else if ( dword_1062578 == 32 )
  {
    *v3 = v53;
  }
  return v2;
}
// 1062568: using guessed type int dword_1062568;
// 106256C: using guessed type int dword_106256C;
// 1062570: using guessed type int dword_1062570;
// 1062574: using guessed type int dword_1062574;
// 1062578: using guessed type int dword_1062578;
// 106257C: using guessed type int dword_106257C;

//----- (010203A2) --------------------------------------------------------
signed int __cdecl sub_10203A2(unsigned __int16 *a1, int *a2)
{
  signed int v2; // ebx
  int *v3; // edi
  int v4; // edx
  int v5; // esi
  int v6; // eax
  int v7; // edx
  char v8; // cl
  bool i; // zf
  int v10; // edx
  unsigned int v11; // eax
  bool v12; // cf
  unsigned int v13; // eax
  signed int v14; // ecx
  int j; // edx
  unsigned int v16; // eax
  unsigned int v17; // eax
  int v18; // ecx
  int v19; // eax
  unsigned int v20; // edx
  int *v21; // edx
  int v22; // eax
  signed int v23; // ecx
  int v24; // edx
  int v25; // ecx
  char v26; // cl
  bool k; // zf
  int v28; // edx
  unsigned int v29; // eax
  signed int v30; // ecx
  unsigned int v31; // eax
  int l; // edx
  unsigned int v33; // eax
  unsigned int v34; // eax
  int v35; // edx
  int v36; // ecx
  int v37; // eax
  unsigned int v38; // edx
  int *v39; // edx
  signed int v40; // ecx
  int v41; // ecx
  int v42; // edi
  unsigned int v43; // edx
  unsigned int v44; // eax
  int v45; // edx
  int *v46; // edx
  signed int v47; // ecx
  int v48; // ecx
  signed int v49; // esi
  unsigned int v50; // edx
  int *v51; // edx
  signed int v52; // ecx
  int v53; // esi
  int v54; // eax
  int v56; // [esp+Ch] [ebp-44h]
  int v57; // [esp+14h] [ebp-3Ch]
  int v58; // [esp+14h] [ebp-3Ch]
  unsigned int v59; // [esp+18h] [ebp-38h]
  int v60; // [esp+18h] [ebp-38h]
  int v61; // [esp+18h] [ebp-38h]
  int v62; // [esp+1Ch] [ebp-34h]
  int v63; // [esp+1Ch] [ebp-34h]
  int v64; // [esp+1Ch] [ebp-34h]
  int v65; // [esp+20h] [ebp-30h]
  char v66; // [esp+20h] [ebp-30h]
  signed int v67; // [esp+24h] [ebp-2Ch]
  int v68; // [esp+28h] [ebp-28h]
  char v69; // [esp+28h] [ebp-28h]
  int v70; // [esp+28h] [ebp-28h]
  int v71; // [esp+2Ch] [ebp-24h]
  unsigned int v72; // [esp+2Ch] [ebp-24h]
  int v73; // [esp+30h] [ebp-20h]
  int v74; // [esp+30h] [ebp-20h]
  int v75; // [esp+30h] [ebp-20h]
  int v76; // [esp+30h] [ebp-20h]
  int v77; // [esp+30h] [ebp-20h]
  int v78; // [esp+34h] [ebp-1Ch]
  int v79; // [esp+38h] [ebp-18h]
  int v80; // [esp+3Ch] [ebp-14h]
  int v81; // [esp+40h] [ebp-10h]
  int v82; // [esp+44h] [ebp-Ch]
  int v83; // [esp+48h] [ebp-8h]

  v2 = 0;
  v3 = a2;
  v56 = a1[5] & 0x8000;
  v4 = (a1[5] & 0x7FFF) - 0x3FFF;
  v81 = *(a1 + 3);
  v82 = *(a1 + 1);
  v73 = v4;
  v83 = *a1 << 16;
  if ( v4 == -16383 )
  {
    v5 = 0;
    v6 = 0;
    while ( !*(&v81 + v6) )
    {
      if ( ++v6 >= 3 )
        goto LABEL_84;
    }
    v81 = 0;
    v82 = 0;
    v83 = 0;
  }
  else
  {
    v71 = v4;
    v78 = v81;
    v62 = dword_1062588 - 1;
    v67 = 0;
    v79 = v82;
    v80 = v83;
    v7 = dword_1062588 / 32;
    v57 = dword_1062588 / 32;
    v65 = 31 - dword_1062588 % 32;
    v8 = v65;
    if ( (1 << v65) & *(&v81 + dword_1062588 / 32) )
    {
      for ( i = (~(-1 << v65) & *(&v81 + v7)) == 0; i; i = *(&v81 + v7) == 0 )
      {
        if ( ++v7 >= 3 )
          goto LABEL_24;
      }
      v10 = v62 / 32;
      v67 = 0;
      v59 = 1 << (31 - v62 % 32);
      v11 = *(&v81 + v62 / 32);
      v12 = v11 + v59 < v11;
      v13 = v11 + v59;
      v14 = 0;
      if ( v12 || v13 < v59 )
      {
        v14 = 1;
        v67 = 1;
      }
      *(&v81 + v10) = v13;
      for ( j = v10 - 1; j >= 0; *(&v81 + j--) = v17 )
      {
        if ( !v14 )
          break;
        v16 = *(&v81 + j);
        v14 = 0;
        v67 = 0;
        v12 = v16 + 1 < v16;
        v17 = v16 + 1;
        if ( v12 || v17 < 1 )
        {
          v14 = 1;
          v67 = 1;
        }
      }
      v8 = v65;
LABEL_24:
      v7 = v57;
    }
    *(&v81 + v7) &= -1 << v8;
    if ( v7 + 1 < 3 )
      memset(&v81 + v7 + 1, 0, 4 * (3 - (v7 + 1)));
    v18 = v73;
    if ( v67 )
      v18 = v73 + 1;
    if ( v18 >= dword_1062584 - dword_1062588 )
    {
      if ( v18 > dword_1062584 )
      {
        if ( v18 < dword_1062580 )
        {
          v81 &= 0x7FFFFFFFu;
          v61 = v18 + dword_1062594;
          v70 = dword_106258C / 32;
          v48 = dword_106258C % 32;
          v77 = 0;
          v49 = 0;
          do
          {
            v50 = *(&v81 + v49);
            *(&v81 + v49++) = v77 | (v50 >> v48);
            v77 = (~(-1 << v48) & v50) << (32 - v48);
          }
          while ( v49 < 3 );
          v5 = v61;
          v51 = &v83 - v70;
          v2 = 0;
          v52 = 2;
          do
          {
            if ( v52 < v70 )
              *(&v81 + v52) = 0;
            else
              *(&v81 + v52) = *v51;
            --v51;
            --v52;
          }
          while ( v52 >= 0 );
        }
        else
        {
          v82 = 0;
          v83 = 0;
          v81 = 2147483648;
          v64 = dword_106258C / 32;
          v41 = dword_106258C % 32;
          v60 = dword_106258C % 32;
          v76 = 0;
          v42 = ~(-1 << dword_106258C % 32);
          v69 = 32 - dword_106258C % 32;
          do
          {
            v43 = *(&v81 + v2);
            v44 = v43;
            v45 = v76 | (v43 >> v41);
            LOBYTE(v41) = v60;
            *(&v81 + v2++) = v45;
            v76 = (v42 & v44) << v69;
          }
          while ( v2 < 3 );
          v46 = &v83 - v64;
          v47 = 2;
          do
          {
            if ( v47 < v64 )
              *(&v81 + v47) = 0;
            else
              *(&v81 + v47) = *v46;
            --v46;
            --v47;
          }
          while ( v47 >= 0 );
          v5 = dword_1062580 + dword_1062594;
          v2 = 1;
        }
        goto LABEL_83;
      }
      v81 = v78;
      v82 = v79;
      v58 = (dword_1062584 - v71) / 32;
      v83 = v80;
      v19 = (dword_1062584 - v71) % 32;
      v74 = 0;
      do
      {
        v20 = *(&v81 + v2);
        *(&v81 + v2++) = v74 | (v20 >> v19);
        v74 = (~(-1 << v19) & v20) << (32 - v19);
      }
      while ( v2 < 3 );
      v21 = &v83 - v58;
      v22 = v58;
      v23 = 2;
      do
      {
        if ( v23 < v22 )
        {
          *(&v81 + v23) = 0;
        }
        else
        {
          *(&v81 + v23) = *v21;
          v22 = v58;
        }
        --v21;
        --v23;
      }
      while ( v23 >= 0 );
      v24 = (v62 + 1) / 32;
      v25 = (v62 + 1) % 32;
      v66 = 31 - v25;
      v26 = 31 - v25;
      if ( (1 << v26) & *(&v81 + v24) )
      {
        for ( k = (~(-1 << v26) & *(&v81 + v24)) == 0; k; k = *(&v81 + v24) == 0 )
        {
          if ( ++v24 >= 3 )
            goto LABEL_56;
        }
        v28 = v62 / 32;
        v29 = *(&v81 + v62 / 32);
        v30 = 0;
        v72 = 1 << (31 - v62 % 32);
        v12 = v29 + v72 < v29;
        v31 = v29 + v72;
        if ( v12 || v31 < v72 )
          v30 = 1;
        *(&v81 + v28) = v31;
        for ( l = v28 - 1; l >= 0; *(&v81 + l--) = v34 )
        {
          if ( !v30 )
            break;
          v33 = *(&v81 + l);
          v30 = 0;
          v12 = v33 + 1 < v33;
          v34 = v33 + 1;
          if ( v12 || v34 < 1 )
            v30 = 1;
        }
        v26 = v66;
LABEL_56:
        v24 = (v62 + 1) / 32;
      }
      *(&v81 + v24) &= -1 << v26;
      v35 = v24 + 1;
      if ( v35 < 3 )
        memset(&v81 + v35, 0, 4 * (3 - v35));
      v68 = (dword_106258C + 1) / 32;
      v36 = (dword_106258C + 1) % 32;
      v37 = 0;
      v75 = 0;
      v63 = 0;
      do
      {
        v38 = *(&v81 + v37);
        *(&v81 + v63) = v75 | (v38 >> v36);
        v75 = (~(-1 << v36) & v38) << (32 - v36);
        v37 = v63 + 1;
        v63 = v37;
      }
      while ( v37 < 3 );
      v39 = &v83 - v68;
      v40 = 2;
      do
      {
        if ( v40 < v68 )
          *(&v81 + v40) = 0;
        else
          *(&v81 + v40) = *v39;
        --v39;
        --v40;
      }
      while ( v40 >= 0 );
    }
    else
    {
      v81 = 0;
      v82 = 0;
      v83 = 0;
    }
    v5 = 0;
  }
  v2 = 2;
LABEL_83:
  v3 = a2;
LABEL_84:
  v53 = v81 | (v56 != 0 ? 0x80000000 : 0) | (v5 << (31 - dword_106258C));
  if ( dword_1062590 == 64 )
  {
    v54 = v82;
    v3[1] = v53;
    *v3 = v54;
  }
  else if ( dword_1062590 == 32 )
  {
    *v3 = v53;
  }
  return v2;
}
// 1062580: using guessed type int dword_1062580;
// 1062584: using guessed type int dword_1062584;
// 1062588: using guessed type int dword_1062588;
// 106258C: using guessed type int dword_106258C;
// 1062590: using guessed type int dword_1062590;
// 1062594: using guessed type int dword_1062594;

//----- (01021B17) --------------------------------------------------------
signed int __cdecl sub_1021B17(_DWORD *a1)
{
  signed int result; // eax

  if ( a1 )
  {
    *a1 = dword_10869A4;
    result = 0;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    result = 22;
  }
  return result;
}
// 100F859: using guessed type int _invalid_parameter_noinfo(void);
// 10869A4: using guessed type int dword_10869A4;

//----- (01021C0E) --------------------------------------------------------
HANDLE sub_1021C0E()
{
  HANDLE result; // eax

  result = hConsoleOutput;
  if ( hConsoleOutput != -1 && hConsoleOutput != -2 )
    result = CloseHandle(hConsoleOutput);
  return result;
}

//----- (01023624) --------------------------------------------------------
int __cdecl SEH_402480(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (010237AA) --------------------------------------------------------
int __cdecl SEH_402D60(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (010237E9) --------------------------------------------------------
int __cdecl SEH_403440(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01023810) --------------------------------------------------------
int __cdecl SEH_4035A0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01023830) --------------------------------------------------------
int __cdecl SEH_4038F0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01023869) --------------------------------------------------------
int __cdecl SEH_4314F0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01023898) --------------------------------------------------------
int __cdecl SEH_403D40(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (010238CB) --------------------------------------------------------
int __cdecl SEH_404130(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01023910) --------------------------------------------------------
int __cdecl SEH_404890(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01023950) --------------------------------------------------------
int __cdecl SEH_404AC0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01023978) --------------------------------------------------------
int __cdecl SEH_404F20(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (010239C1) --------------------------------------------------------
int __cdecl SEH_404FB0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01023A00) --------------------------------------------------------
int __cdecl SEH_4052B0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01023A30) --------------------------------------------------------
int __cdecl SEH_405520(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01023A79) --------------------------------------------------------
int __cdecl SEH_405C70(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01023AAB) --------------------------------------------------------
int __cdecl SEH_406440(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01023AF0) --------------------------------------------------------
int __cdecl SEH_406090(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01023B50) --------------------------------------------------------
int __cdecl SEH_4067A0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01023B78) --------------------------------------------------------
int __cdecl SEH_406CC0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01023BB8) --------------------------------------------------------
int __cdecl SEH_406DD0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01023C38) --------------------------------------------------------
int __cdecl SEH_4070E0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01023C81) --------------------------------------------------------
int __cdecl SEH_407CC0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01023CD1) --------------------------------------------------------
int __cdecl SEH_4085A0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01023E47) --------------------------------------------------------
int __cdecl SEH_4087A0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (0102403E) --------------------------------------------------------
int __cdecl SEH_409270(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (0102420F) --------------------------------------------------------
int __cdecl SEH_409B70(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01024238) --------------------------------------------------------
int __cdecl SEH_425730(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (010243B3) --------------------------------------------------------
int __cdecl SEH_40AB10(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01024910) --------------------------------------------------------
int __cdecl SEH_40B220(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (010249A0) --------------------------------------------------------
int __cdecl SEH_40F2D0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (010249D8) --------------------------------------------------------
int __cdecl SEH_40F610(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01024A00) --------------------------------------------------------
int __cdecl SEH_40F9D0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01024A20) --------------------------------------------------------
int __cdecl SEH_40FD00(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01024A40) --------------------------------------------------------
int __cdecl SEH_40FDF0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01024A92) --------------------------------------------------------
int __cdecl SEH_410460(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01024C1A) --------------------------------------------------------
int __cdecl SEH_410790(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01024C48) --------------------------------------------------------
int __cdecl SEH_411150(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01024E28) --------------------------------------------------------
int __cdecl SEH_411610(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01025006) --------------------------------------------------------
int __cdecl SEH_412090(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01025187) --------------------------------------------------------
int __cdecl SEH_413160(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01025307) --------------------------------------------------------
int __cdecl SEH_413A80(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01025509) --------------------------------------------------------
int __cdecl SEH_414200(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (0102580D) --------------------------------------------------------
int __cdecl SEH_414FF0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01025A24) --------------------------------------------------------
int __cdecl SEH_415FF0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01025AE0) --------------------------------------------------------
int __cdecl SEH_416A10(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01025B20) --------------------------------------------------------
int __cdecl SEH_416E10(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01025C9F) --------------------------------------------------------
int __cdecl SEH_417000(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01025E4B) --------------------------------------------------------
int __cdecl SEH_4177C0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01025E78) --------------------------------------------------------
int __cdecl SEH_417FE0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01026013) --------------------------------------------------------
int __cdecl SEH_418050(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01026048) --------------------------------------------------------
int __cdecl SEH_418A90(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (010261C7) --------------------------------------------------------
int __cdecl SEH_418C20(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (010261F8) --------------------------------------------------------
int __cdecl SEH_4193C0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01026399) --------------------------------------------------------
int __cdecl SEH_419580(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01026533) --------------------------------------------------------
int __cdecl SEH_41A120(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01026568) --------------------------------------------------------
int __cdecl SEH_41AD20(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (0102659B) --------------------------------------------------------
int __cdecl SEH_45ED60(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01026802) --------------------------------------------------------
int __cdecl SEH_41B1A0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (0102699B) --------------------------------------------------------
int __cdecl SEH_41D790(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01026BBC) --------------------------------------------------------
int __cdecl SEH_41E3A0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01026BF8) --------------------------------------------------------
int __cdecl SEH_41EFE0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01026C38) --------------------------------------------------------
int __cdecl SEH_41F0E0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01026F3B) --------------------------------------------------------
int __cdecl SEH_41F260(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (0102704E) --------------------------------------------------------
int __cdecl SEH_420760(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (010270E8) --------------------------------------------------------
int __cdecl SEH_420EA0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01027120) --------------------------------------------------------
int __cdecl SEH_4211B0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (0102714A) --------------------------------------------------------
int __cdecl SEH_4013A0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01027178) --------------------------------------------------------
int __cdecl SEH_421590(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (010272D4) --------------------------------------------------------
int __cdecl SEH_421860(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01027308) --------------------------------------------------------
int __cdecl SEH_422060(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (0102747C) --------------------------------------------------------
int __cdecl SEH_422110(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (0102764A) --------------------------------------------------------
int __cdecl SEH_4227D0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (0102782A) --------------------------------------------------------
int __cdecl SEH_423190(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01027860) --------------------------------------------------------
int __cdecl SEH_424040(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01027880) --------------------------------------------------------
int __cdecl SEH_424270(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (010278A0) --------------------------------------------------------
int __cdecl SEH_4244A0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (010278C0) --------------------------------------------------------
int __cdecl SEH_4245C0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (010278FE) --------------------------------------------------------
int __cdecl SEH_424740(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01027938) --------------------------------------------------------
int __cdecl SEH_424920(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01027998) --------------------------------------------------------
int __cdecl SEH_424FE0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (010279D0) --------------------------------------------------------
int __cdecl SEH_425120(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (010279F8) --------------------------------------------------------
int __cdecl SEH_425350(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01027A28) --------------------------------------------------------
int __cdecl SEH_425440(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01027A58) --------------------------------------------------------
int __cdecl SEH_425850(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01027A99) --------------------------------------------------------
int __cdecl SEH_425940(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01027AC8) --------------------------------------------------------
int __cdecl SEH_425AB0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01027BBA) --------------------------------------------------------
int __cdecl SEH_425D10(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01027BF8) --------------------------------------------------------
int __cdecl SEH_426830(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01027C28) --------------------------------------------------------
int __cdecl SEH_4269A0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01027C50) --------------------------------------------------------
int __cdecl SEH_426BB0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01027C78) --------------------------------------------------------
int __cdecl SEH_427AC0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01027CAB) --------------------------------------------------------
int __cdecl SEH_45E760(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01027CE6) --------------------------------------------------------
int __cdecl SEH_428730(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01027D45) --------------------------------------------------------
int __cdecl SEH_428970(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01027D80) --------------------------------------------------------
int __cdecl SEH_429580(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01027DA8) --------------------------------------------------------
int __cdecl SEH_42A1F0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01027DDB) --------------------------------------------------------
int __cdecl SEH_42FAF0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01027E10) --------------------------------------------------------
int __cdecl SEH_431240(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01027E60) --------------------------------------------------------
int __cdecl SEH_431560(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01027EDE) --------------------------------------------------------
int __cdecl SEH_4318A0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01027F83) --------------------------------------------------------
int __cdecl SEH_431BC0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01028191) --------------------------------------------------------
int __cdecl SEH_431FC0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (0102825C) --------------------------------------------------------
int __cdecl SEH_4337E0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (010282B1) --------------------------------------------------------
int __cdecl SEH_434530(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (010282E9) --------------------------------------------------------
int __cdecl SEH_434810(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01028320) --------------------------------------------------------
int __cdecl SEH_434AA0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01028358) --------------------------------------------------------
int __cdecl SEH_434F00(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (010285A0) --------------------------------------------------------
int __cdecl SEH_4355A0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (010285D0) --------------------------------------------------------
int __cdecl SEH_437DF0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (010285F8) --------------------------------------------------------
int __cdecl SEH_438150(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (0102866A) --------------------------------------------------------
int __cdecl SEH_438360(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01028698) --------------------------------------------------------
int __cdecl SEH_438570(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (010286C8) --------------------------------------------------------
int __cdecl SEH_438630(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01028735) --------------------------------------------------------
int __cdecl SEH_438CE0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (0102876B) --------------------------------------------------------
int __cdecl SEH_439090(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (010287A0) --------------------------------------------------------
int __cdecl SEH_4391F0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (010287D0) --------------------------------------------------------
int __cdecl SEH_4392D0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (010287F8) --------------------------------------------------------
int __cdecl SEH_439D10(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01028828) --------------------------------------------------------
int __cdecl SEH_439E70(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01028850) --------------------------------------------------------
int __cdecl SEH_43B100(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01028889) --------------------------------------------------------
int __cdecl SEH_43B460(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (010288D0) --------------------------------------------------------
int __cdecl SEH_43B780(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (0102894F) --------------------------------------------------------
int __cdecl SEH_43BF00(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (010289A4) --------------------------------------------------------
int __cdecl SEH_43D080(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (010289C8) --------------------------------------------------------
int __cdecl SEH_43D1D0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01028A19) --------------------------------------------------------
int __cdecl SEH_43D3B0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01028A5E) --------------------------------------------------------
int __cdecl SEH_43D590(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01028AD5) --------------------------------------------------------
int __cdecl SEH_43D670(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01028B03) --------------------------------------------------------
int __cdecl SEH_43DF10(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01028B3E) --------------------------------------------------------
int __cdecl SEH_43E1A0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01028B7B) --------------------------------------------------------
int __cdecl SEH_43EAD0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01028BAB) --------------------------------------------------------
int __cdecl SEH_43EBA0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01028BE0) --------------------------------------------------------
int __cdecl SEH_43EEA0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01028C75) --------------------------------------------------------
int __cdecl SEH_43F0A0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01028CA8) --------------------------------------------------------
int __cdecl SEH_43FFF0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01028CD8) --------------------------------------------------------
int __cdecl SEH_469E00(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01028D16) --------------------------------------------------------
int __cdecl SEH_445F60(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01028EBE) --------------------------------------------------------
int __cdecl SEH_446270(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01028FC9) --------------------------------------------------------
int __cdecl SEH_451E50(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (0102902D) --------------------------------------------------------
int __cdecl SEH_4526B0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01029081) --------------------------------------------------------
int __cdecl SEH_457640(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (010290B1) --------------------------------------------------------
int __cdecl SEH_457740(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (010290F6) --------------------------------------------------------
int __cdecl SEH_4577E0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01029138) --------------------------------------------------------
int __cdecl SEH_457DD0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (010291C3) --------------------------------------------------------
int __cdecl SEH_4580C0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (010291F0) --------------------------------------------------------
int __cdecl SEH_458AE0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01029218) --------------------------------------------------------
int __cdecl SEH_458C80(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01029248) --------------------------------------------------------
int __cdecl SEH_458D10(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (010292D3) --------------------------------------------------------
int __cdecl SEH_458E20(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (0102930B) --------------------------------------------------------
int __cdecl SEH_459500(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (010293FF) --------------------------------------------------------
int __cdecl SEH_459C50(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01029452) --------------------------------------------------------
int __cdecl SEH_45A570(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01029504) --------------------------------------------------------
int __cdecl SEH_45B0A0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (0102954B) --------------------------------------------------------
int __cdecl SEH_45B680(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01029580) --------------------------------------------------------
int __cdecl SEH_45B8A0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (010295A0) --------------------------------------------------------
int __cdecl SEH_45C840(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (010295CB) --------------------------------------------------------
int __cdecl SEH_45EE00(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (0102964C) --------------------------------------------------------
int __cdecl SEH_45D510(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (010296B2) --------------------------------------------------------
int __cdecl SEH_45DCE0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (010296F9) --------------------------------------------------------
int __cdecl SEH_45E4E0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (0102972B) --------------------------------------------------------
int __cdecl SEH_45E8B0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01029758) --------------------------------------------------------
int __cdecl SEH_466900(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01029780) --------------------------------------------------------
int __cdecl SEH_469AF0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (010297A0) --------------------------------------------------------
int __cdecl SEH_469C10(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (010297C8) --------------------------------------------------------
int __cdecl SEH_469EA0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (010297FE) --------------------------------------------------------
int __cdecl SEH_46A670(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (0102983E) --------------------------------------------------------
int __cdecl SEH_46ADD0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (0102987B) --------------------------------------------------------
int __cdecl SEH_46B930(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (010298D1) --------------------------------------------------------
int __cdecl SEH_46BC50(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01029908) --------------------------------------------------------
int __cdecl SEH_46C350(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01029938) --------------------------------------------------------
int __cdecl SEH_46DAF0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01029976) --------------------------------------------------------
int __cdecl SEH_46DD60(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (010299B3) --------------------------------------------------------
int __cdecl SEH_46EC30(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01029A01) --------------------------------------------------------
int __cdecl SEH_4703E0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01029A3B) --------------------------------------------------------
int __cdecl SEH_4723A0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01029A6E) --------------------------------------------------------
int __cdecl SEH_472810(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01029B48) --------------------------------------------------------
int __cdecl SEH_472C20(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01029B7E) --------------------------------------------------------
int __cdecl SEH_473C50(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01029BBB) --------------------------------------------------------
int __cdecl SEH_474990(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01029BEE) --------------------------------------------------------
int __cdecl SEH_4766A0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01029C2E) --------------------------------------------------------
int __cdecl SEH_477710(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01029C6E) --------------------------------------------------------
int __cdecl SEH_478E00(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01029CAB) --------------------------------------------------------
int __cdecl SEH_479A30(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01029CEE) --------------------------------------------------------
int __cdecl SEH_47ACF0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01029D2B) --------------------------------------------------------
int __cdecl SEH_47D5B0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01029D70) --------------------------------------------------------
int __cdecl SEH_4808E0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01029D9E) --------------------------------------------------------
int __cdecl SEH_4809B0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01029DDE) --------------------------------------------------------
int __cdecl SEH_4818B0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01029E1E) --------------------------------------------------------
int __cdecl SEH_482010(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01029E5E) --------------------------------------------------------
int __cdecl SEH_4825E0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01029E9B) --------------------------------------------------------
int __cdecl SEH_483260(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01029ECE) --------------------------------------------------------
int __cdecl SEH_483AF0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01029F3D) --------------------------------------------------------
int __cdecl SEH_483FC0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01029F70) --------------------------------------------------------
int __cdecl SEH_491650(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01029F9A) --------------------------------------------------------
int __cdecl SEH_401FF0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (01029FD0) --------------------------------------------------------
int __cdecl SEH_491C30(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (0102A003) --------------------------------------------------------
int __cdecl SEH_491EC0(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (0102A039) --------------------------------------------------------
int __cdecl SEH_492230(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (0102A070) --------------------------------------------------------
int __cdecl SEH_494270(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (0102A093) --------------------------------------------------------
int __cdecl sub_102A093(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (0102A0AE) --------------------------------------------------------
int __cdecl sub_102A0AE(EXCEPTION_RECORD *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler3(a1, a2, a3, a4);
}
// 1005CD1: using guessed type _DWORD __cdecl __CxxFrameHandler3(PEXCEPTION_RECORD ExceptionRecord, struct EHRegistrationNode *, struct _CONTEXT *, void *);

//----- (0102A0D0) --------------------------------------------------------
void __cdecl sub_102A0D0()
{
  `eh vector destructor iterator'(word_1064900, 0x28u, 20, sub_F73850);
}
// 1064900: using guessed type __int16 word_1064900[400];

//----- (0102A0F0) --------------------------------------------------------
void __thiscall sub_102A0F0(void *this)
{
  void *v1; // [esp-2h] [ebp-4h]

  v1 = this;
  if ( garrAccountInfo.baseclass_0._Mypair._Myval2._Myfirst )
  {
    nullsub_1(garrAccountInfo.baseclass_0._Mypair._Myval2._Myfirst, garrAccountInfo.baseclass_0._Mypair._Myval2._Mylast);
    ATL::CAtlStringMgr::Clone((&v1 + 3));
    j__free(garrAccountInfo.baseclass_0._Mypair._Myval2._Myfirst);
    garrAccountInfo.baseclass_0._Mypair._Myval2._Myfirst = 0;
    garrAccountInfo.baseclass_0._Mypair._Myval2._Mylast = 0;
    garrAccountInfo.baseclass_0._Mypair._Myval2._Myend = 0;
  }
}
// F7FB30: using guessed type _DWORD __stdcall nullsub_1(_DWORD, _DWORD);

//----- (0102A150) --------------------------------------------------------
void __cdecl sub_102A150()
{
  free(gpszTipText);
}

//----- (0102A160) --------------------------------------------------------
void __cdecl sub_102A160()
{
  void *v0; // esi

  v0 = dword_10648F8;
  if ( dword_10648F8 )
  {
    if ( !InterlockedDecrement(dword_10648F8 + 2) && v0 )
    {
      if ( *v0 )
      {
        SysFreeString(*v0);
        *v0 = 0;
      }
      if ( *(v0 + 1) )
      {
        j_j__free(*(v0 + 1));
        *(v0 + 1) = 0;
      }
      j__free(v0);
    }
    dword_10648F8 = 0;
  }
}

//----- (0102A1C0) --------------------------------------------------------
void __cdecl sub_102A1C0()
{
  void *v0; // esi

  v0 = dword_10648F4;
  if ( dword_10648F4 )
  {
    if ( !InterlockedDecrement(dword_10648F4 + 2) && v0 )
    {
      if ( *v0 )
      {
        SysFreeString(*v0);
        *v0 = 0;
      }
      if ( *(v0 + 1) )
      {
        j_j__free(*(v0 + 1));
        *(v0 + 1) = 0;
      }
      j__free(v0);
    }
    dword_10648F4 = 0;
  }
}

//----- (0102A220) --------------------------------------------------------
void __cdecl sub_102A220()
{
  free(dword_4F48E4);
}

//----- (0102A230) --------------------------------------------------------
void __cdecl sub_102A230()
{
  free(gpszSystemPathInfo);
}

//----- (0102A240) --------------------------------------------------------
void __cdecl sub_102A240()
{
  free(dword_4F48FC);
}

//----- (0102A250) --------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__gKeyNameMap__()
{
  std__Tree_node *v0; // esi
  int a2; // [esp+4h] [ebp-8h]
  char v2; // [esp+Bh] [ebp-1h]

  std::_Tree<std::_Tmap_traits<wchar_t const *,tagKeyName,std::less<wchar_t const *>,std::allocator<std::pair<wchar_t const * const,tagKeyName>>,0>>::erase(
    &gKeyNameMap,
    &a2,
    gKeyNameMap._Mypair._Myval2._Myhead->_Left,
    gKeyNameMap._Mypair._Myval2._Myhead);
  v0 = gKeyNameMap._Mypair._Myval2._Myhead;
  ATL::CAtlStringMgr::Clone(&v2);
  nullsub_2(v0);
  ATL::CAtlStringMgr::Clone(&v2);
  nullsub_2(&v0->_Parent);
  ATL::CAtlStringMgr::Clone(&v2);
  nullsub_2(&v0->_Right);
  ATL::CAtlStringMgr::Clone(&v2);
  j__free(v0);
}
// F97A90: using guessed type _DWORD __stdcall nullsub_2(_DWORD);

//----- (0102A2D0) --------------------------------------------------------
void __cdecl sub_102A2D0()
{
  free(dword_4F48F0);
}

//----- (0102A2E0) --------------------------------------------------------
void __cdecl sub_102A2E0()
{
  free(*&gpszText1);
}

//----- (0102A2F0) --------------------------------------------------------
void __cdecl sub_102A2F0()
{
  free(dword_4F4C54);
}

//----- (0102A300) --------------------------------------------------------
void __cdecl sub_102A300()
{
  free(dword_4F4C50);
}

//----- (0102A310) --------------------------------------------------------
void __cdecl sub_102A310()
{
  _DWORD **v0; // eax
  _DWORD *v1; // ecx
  _DWORD *v2; // esi
  _DWORD **v3; // eax
  _DWORD *v4; // ecx
  _DWORD *v5; // esi

  v0 = *(&dword_1064CD0 + 4);
  v1 = *v0;
  *v0 = v0;
  *(*(&dword_1064CD0 + 4) + 4) = *(&dword_1064CD0 + 4);
  *(&dword_1064CD0 + 5) = 0;
  if ( v1 != *(&dword_1064CD0 + 4) )
  {
    do
    {
      v2 = *v1;
      j__free(v1);
      v1 = v2;
    }
    while ( v2 != *(&dword_1064CD0 + 4) );
  }
  j__free(*(&dword_1064CD0 + 4));
  v3 = *(&dword_1064CD0 + 2);
  v4 = *v3;
  *v3 = v3;
  *(*(&dword_1064CD0 + 2) + 4) = *(&dword_1064CD0 + 2);
  *(&dword_1064CD0 + 3) = 0;
  if ( v4 != *(&dword_1064CD0 + 2) )
  {
    do
    {
      v5 = *v4;
      j__free(v4);
      v4 = v5;
    }
    while ( v5 != *(&dword_1064CD0 + 2) );
  }
  j__free(*(&dword_1064CD0 + 2));
}
// 1064CD0: using guessed type int dword_1064CD0;

//----- (0102A320) --------------------------------------------------------
void __cdecl sub_102A320()
{
  void **v0; // edi
  char *v1; // ebx
  void **v2; // esi
  char v3; // [esp+8h] [ebp-4h]
  char v4; // [esp+9h] [ebp-3h]
  char v5; // [esp+Ah] [ebp-2h]
  char v6; // [esp+Bh] [ebp-1h]

  v0 = *gList1;
  *gList1 = gList1;
  *(gList1 + 1) = gList1;
  v1 = gList1;
  *(&gList1 + 1) = 0;
  if ( v0 != gList1 )
  {
    do
    {
      v2 = *v0;
      ATL::CAtlStringMgr::Clone(&v6);
      nullsub_2(v0);
      ATL::CAtlStringMgr::Clone(&v5);
      nullsub_2(v0 + 1);
      ATL::CAtlStringMgr::Clone(&v4);
      nullsub_2(v0 + 2);
      ATL::CAtlStringMgr::Clone(&v3);
      j__free(v0);
      v1 = gList1;
      v0 = v2;
    }
    while ( v2 != gList1 );
  }
  ATL::CAtlStringMgr::Clone(&v4);
  nullsub_2(v1);
  ATL::CAtlStringMgr::Clone(&v4);
  nullsub_2(v1 + 4);
  ATL::CAtlStringMgr::Clone(&v3);
  j__free(v1);
}
// F97A90: using guessed type _DWORD __stdcall nullsub_2(_DWORD);

//----- (0102A3F0) --------------------------------------------------------
void __cdecl sub_102A3F0()
{
  void **v0; // edi
  char *v1; // ebx
  void **v2; // esi
  char v3; // [esp+8h] [ebp-4h]
  char v4; // [esp+9h] [ebp-3h]
  char v5; // [esp+Ah] [ebp-2h]
  char v6; // [esp+Bh] [ebp-1h]

  v0 = *gList2;
  *gList2 = gList2;
  *(gList2 + 1) = gList2;
  v1 = gList2;
  *(&gList2 + 1) = 0;
  if ( v0 != gList2 )
  {
    do
    {
      v2 = *v0;
      ATL::CAtlStringMgr::Clone(&v6);
      nullsub_2(v0);
      ATL::CAtlStringMgr::Clone(&v5);
      nullsub_2(v0 + 1);
      ATL::CAtlStringMgr::Clone(&v4);
      nullsub_2(v0 + 2);
      ATL::CAtlStringMgr::Clone(&v3);
      j__free(v0);
      v1 = gList2;
      v0 = v2;
    }
    while ( v2 != gList2 );
  }
  ATL::CAtlStringMgr::Clone(&v4);
  nullsub_2(v1);
  ATL::CAtlStringMgr::Clone(&v4);
  nullsub_2(v1 + 4);
  ATL::CAtlStringMgr::Clone(&v3);
  j__free(v1);
}
// F97A90: using guessed type _DWORD __stdcall nullsub_2(_DWORD);

//----- (0102A4C0) --------------------------------------------------------
void __cdecl sub_102A4C0()
{
  void **v0; // edi
  char *v1; // ebx
  void **v2; // esi
  char v3; // [esp+8h] [ebp-4h]
  char v4; // [esp+9h] [ebp-3h]
  char v5; // [esp+Ah] [ebp-2h]
  char v6; // [esp+Bh] [ebp-1h]

  v0 = *gList3;
  *gList3 = gList3;
  *(gList3 + 1) = gList3;
  v1 = gList3;
  *(&gList3 + 1) = 0;
  if ( v0 != gList3 )
  {
    do
    {
      v2 = *v0;
      ATL::CAtlStringMgr::Clone(&v6);
      nullsub_2(v0);
      ATL::CAtlStringMgr::Clone(&v5);
      nullsub_2(v0 + 1);
      ATL::CAtlStringMgr::Clone(&v4);
      nullsub_2(v0 + 2);
      ATL::CAtlStringMgr::Clone(&v3);
      j__free(v0);
      v1 = gList3;
      v0 = v2;
    }
    while ( v2 != gList3 );
  }
  ATL::CAtlStringMgr::Clone(&v4);
  nullsub_2(v1);
  ATL::CAtlStringMgr::Clone(&v4);
  nullsub_2(v1 + 4);
  ATL::CAtlStringMgr::Clone(&v3);
  j__free(v1);
}
// F97A90: using guessed type _DWORD __stdcall nullsub_2(_DWORD);

//----- (0102A590) --------------------------------------------------------
void __cdecl sub_102A590()
{
  char *v0; // esi
  char v1; // [esp+4h] [ebp-8h]
  char v2; // [esp+Bh] [ebp-1h]

  sub_1002C10(&gMap5, &v1, *gMap5, gMap5);
  v0 = gMap5;
  ATL::CAtlStringMgr::Clone(&v2);
  nullsub_2(v0);
  ATL::CAtlStringMgr::Clone(&v2);
  nullsub_2(v0 + 4);
  ATL::CAtlStringMgr::Clone(&v2);
  nullsub_2(v0 + 8);
  ATL::CAtlStringMgr::Clone(&v2);
  j__free(v0);
}
// F97A90: using guessed type _DWORD __stdcall nullsub_2(_DWORD);

//----- (0102A610) --------------------------------------------------------
void __cdecl sub_102A610()
{
  off_105AA3C[0] = &std::error_category::`vftable';
}
// 1032D74: using guessed type void *std::error_category::`vftable';
// 105AA3C: using guessed type int (__thiscall **off_105AA3C[3])(void *, char);

//----- (0102A620) --------------------------------------------------------
void __cdecl sub_102A620()
{
  off_105AA40[0] = &std::error_category::`vftable';
}
// 1032D74: using guessed type void *std::error_category::`vftable';
// 105AA40: using guessed type int (__thiscall **off_105AA40[2])(void *, char);

//----- (0102A630) --------------------------------------------------------
void __cdecl sub_102A630()
{
  off_105AA44 = &std::error_category::`vftable';
}
// 1032D74: using guessed type void *std::error_category::`vftable';
// 105AA44: using guessed type int (__thiscall **off_105AA44)(void *, char);

//----- (0102A640) --------------------------------------------------------
void __cdecl sub_102A640()
{
  free(gActiveScriptEventConsumer.baseclass.m_pszURL);
  free(gActiveScriptEventConsumer.baseclass.m_pszDescription);
}
// 1064D28: using guessed type struct ActiveScriptEventConsumer gActiveScriptEventConsumer;

//----- (0102A660) --------------------------------------------------------
void __cdecl sub_102A660()
{
  free(gCommandLineEventConsumer.baseclass.m_pszURL);
  free(gCommandLineEventConsumer.baseclass.m_pszDescription);
}
// 1064D1C: using guessed type struct CommandLineEventConsumer gCommandLineEventConsumer;

//----- (0102A680) --------------------------------------------------------
void __cdecl sub_102A680()
{
  char *v0; // esi
  char v1; // [esp+4h] [ebp-8h]
  char v2; // [esp+Bh] [ebp-1h]

  sub_F97560(&gMap6, &v1, *gMap6, gMap6);
  v0 = gMap6;
  ATL::CAtlStringMgr::Clone(&v2);
  nullsub_2(v0);
  ATL::CAtlStringMgr::Clone(&v2);
  nullsub_2(v0 + 4);
  ATL::CAtlStringMgr::Clone(&v2);
  nullsub_2(v0 + 8);
  ATL::CAtlStringMgr::Clone(&v2);
  j__free(v0);
}
// F97A90: using guessed type _DWORD __stdcall nullsub_2(_DWORD);

//----- (0102A700) --------------------------------------------------------
void __cdecl sub_102A700()
{
  if ( ghUxthemeModule )
    FreeLibrary(ghUxthemeModule);
}

//----- (0102A720) --------------------------------------------------------
void __cdecl sub_102A720()
{
  int *v0; // edi
  int *v1; // ebx
  int *v2; // esi
  char v3; // [esp+8h] [ebp-4h]
  char v4; // [esp+9h] [ebp-3h]
  char v5; // [esp+Ah] [ebp-2h]
  char v6; // [esp+Bh] [ebp-1h]

  v0 = *gBstrList;
  *gBstrList = gBstrList;
  gBstrList[1] = gBstrList;
  v1 = gBstrList;
  *(&gBstrList + 1) = 0;
  if ( v0 != gBstrList )
  {
    do
    {
      v2 = *v0;
      ATL::CAtlStringMgr::Clone(&v6);
      nullsub_2(v0);
      ATL::CAtlStringMgr::Clone(&v5);
      nullsub_2(v0 + 1);
      ATL::CAtlStringMgr::Clone(&v4);
      nullsub_2(v0 + 2);
      ATL::CAtlStringMgr::Clone(&v3);
      j__free(v0);
      v1 = gBstrList;
      v0 = v2;
    }
    while ( v2 != gBstrList );
  }
  ATL::CAtlStringMgr::Clone(&v4);
  nullsub_2(v1);
  ATL::CAtlStringMgr::Clone(&v4);
  nullsub_2(v1 + 1);
  ATL::CAtlStringMgr::Clone(&v3);
  j__free(v1);
}
// F97A90: using guessed type _DWORD __stdcall nullsub_2(_DWORD);

//----- (0102A7F0) --------------------------------------------------------
void __cdecl sub_102A7F0()
{
  strHeap.baseclass.vtptr = &ATL::CWin32Heap::`vftable';
  if ( strHeap.m_bOwnHeap )
  {
    if ( strHeap.m_hHeap )
      HeapDestroy(strHeap.m_hHeap);
  }
}
// 103C4F8: using guessed type void *ATL::CWin32Heap::`vftable';

//----- (0102A820) --------------------------------------------------------
void __cdecl sub_102A820()
{
  strMgr.baseclass.vtptr = &ATL::CAtlStringMgr::`vftable';
  byte_1064DF4 = 0;
}
// 103C510: using guessed type void *ATL::CAtlStringMgr::`vftable';
// 1064DF4: using guessed type char byte_1064DF4;

//----- (0102A840) --------------------------------------------------------
void __cdecl sub_102A840()
{
  std__list_node *v0; // edi
  std__list_node *v1; // ebx
  std__list_node *v2; // esi
  char v3; // [esp+8h] [ebp-4h]
  char v4; // [esp+9h] [ebp-3h]
  char v5; // [esp+Ah] [ebp-2h]
  char v6; // [esp+Bh] [ebp-1h]

  v0 = gAdapterLuidList._Mypair._Myval2._Myhead->_Next;
  gAdapterLuidList._Mypair._Myval2._Myhead->_Next = gAdapterLuidList._Mypair._Myval2._Myhead;
  gAdapterLuidList._Mypair._Myval2._Myhead->_Prev = gAdapterLuidList._Mypair._Myval2._Myhead;
  v1 = gAdapterLuidList._Mypair._Myval2._Myhead;
  gAdapterLuidList._Mypair._Myval2._Mysize = 0;
  if ( v0 != gAdapterLuidList._Mypair._Myval2._Myhead )
  {
    do
    {
      v2 = v0->_Next;
      ATL::CAtlStringMgr::Clone(&v6);
      nullsub_2(v0);
      ATL::CAtlStringMgr::Clone(&v5);
      nullsub_2(&v0->_Prev);
      ATL::CAtlStringMgr::Clone(&v4);
      nullsub_2(&v0->_Myval);
      ATL::CAtlStringMgr::Clone(&v3);
      j__free(v0);
      v1 = gAdapterLuidList._Mypair._Myval2._Myhead;
      v0 = v2;
    }
    while ( v2 != gAdapterLuidList._Mypair._Myval2._Myhead );
  }
  ATL::CAtlStringMgr::Clone(&v4);
  nullsub_2(v1);
  ATL::CAtlStringMgr::Clone(&v4);
  nullsub_2(&v1->_Prev);
  ATL::CAtlStringMgr::Clone(&v3);
  j__free(v1);
}
// F97A90: using guessed type _DWORD __stdcall nullsub_2(_DWORD);

//----- (0102A910) --------------------------------------------------------
void __cdecl sub_102A910()
{
  Data_t_bstr_t *v0; // esi

  v0 = a2.m_Data;
  if ( a2.m_Data )
  {
    if ( !InterlockedDecrement(&a2.m_Data->m_RefCount) && v0 )
    {
      if ( v0->m_wstr )
      {
        SysFreeString(v0->m_wstr);
        v0->m_wstr = 0;
      }
      if ( v0->m_str )
      {
        j_j__free(v0->m_str);
        v0->m_str = 0;
      }
      j__free(v0);
    }
    a2.m_Data = 0;
  }
}

//----- (0102A970) --------------------------------------------------------
void __cdecl sub_102A970()
{
  Data_t_bstr_t *v0; // esi

  v0 = stru_1069E50.m_Data;
  if ( stru_1069E50.m_Data )
  {
    if ( !InterlockedDecrement(&stru_1069E50.m_Data->m_RefCount) && v0 )
    {
      if ( v0->m_wstr )
      {
        SysFreeString(v0->m_wstr);
        v0->m_wstr = 0;
      }
      if ( v0->m_str )
      {
        j_j__free(v0->m_str);
        v0->m_str = 0;
      }
      j__free(v0);
    }
    stru_1069E50.m_Data = 0;
  }
}

//----- (0102A9D0) --------------------------------------------------------
void __cdecl sub_102A9D0()
{
  PerformanceInfoInMemory::~PerformanceInfoInMemory(&gPerformanceInfoInMemory);
}

//----- (0102A9E0) --------------------------------------------------------
void __cdecl sub_102A9E0()
{
  PerformanceInfo::~PerformanceInfo(&gPerformanceInfo.m_pBuffer);
}

//----- (0102A9F0) --------------------------------------------------------
void __cdecl sub_102A9F0()
{
  Data_t_bstr_t *v0; // esi

  v0 = gNullString.m_Data;
  if ( gNullString.m_Data )
  {
    if ( !InterlockedDecrement(&gNullString.m_Data->m_RefCount) && v0 )
    {
      if ( v0->m_wstr )
      {
        SysFreeString(v0->m_wstr);
        v0->m_wstr = 0;
      }
      if ( v0->m_str )
      {
        j_j__free(v0->m_str);
        v0->m_str = 0;
      }
      j__free(v0);
    }
    gNullString.m_Data = 0;
  }
}

//----- (0102AA50) --------------------------------------------------------
void __cdecl sub_102AA50()
{
  IWbemServices *v0; // edi
  char *v1; // ebx
  IWbemServices *v2; // esi
  char v3; // [esp+8h] [ebp-4h]
  char v4; // [esp+9h] [ebp-3h]
  char v5; // [esp+Ah] [ebp-2h]
  char v6; // [esp+Bh] [ebp-1h]

  v0 = (*(&gWbemServiceList + 1))->lpVtbl;
  (*(&gWbemServiceList + 1))->lpVtbl = *(&gWbemServiceList + 1);
  (*(&gWbemServiceList + 1))[1].lpVtbl = *(&gWbemServiceList + 1);
  v1 = *(&gWbemServiceList + 1);
  *(&gWbemServiceList + 2) = 0;
  if ( v0 != *(&gWbemServiceList + 1) )
  {
    do
    {
      v2 = v0->lpVtbl;
      ATL::CAtlStringMgr::Clone(&v6);
      nullsub_2(v0);
      ATL::CAtlStringMgr::Clone(&v5);
      nullsub_2(&v0[1]);
      ATL::CAtlStringMgr::Clone(&v4);
      nullsub_2(&v0[2]);
      ATL::CAtlStringMgr::Clone(&v3);
      j__free(v0);
      v1 = *(&gWbemServiceList + 1);
      v0 = v2;
    }
    while ( v2 != *(&gWbemServiceList + 1) );
  }
  ATL::CAtlStringMgr::Clone(&v4);
  nullsub_2(v1);
  ATL::CAtlStringMgr::Clone(&v4);
  nullsub_2(v1 + 4);
  ATL::CAtlStringMgr::Clone(&v3);
  j__free(v1);
}
// F97A90: using guessed type _DWORD __stdcall nullsub_2(_DWORD);

//----- (0102AB20) --------------------------------------------------------
void __cdecl sub_102AB20()
{
  std__Tree_node *v0; // esi
  int *a2; // [esp+4h] [ebp-8h]
  char v2; // [esp+Bh] [ebp-1h]

  sub_FF5510(&gThreadProcessMap, &a2, gThreadProcessMap._Header->_Left, gThreadProcessMap._Header);
  v0 = gThreadProcessMap._Header;
  ATL::CAtlStringMgr::Clone(&v2);
  nullsub_2(v0);
  ATL::CAtlStringMgr::Clone(&v2);
  nullsub_2(&v0->_Parent);
  ATL::CAtlStringMgr::Clone(&v2);
  nullsub_2(&v0->_Right);
  ATL::CAtlStringMgr::Clone(&v2);
  j__free(v0);
}
// F97A90: using guessed type _DWORD __stdcall nullsub_2(_DWORD);

//----- (0102ABA0) --------------------------------------------------------
void __cdecl sub_102ABA0()
{
  Data_t_bstr_t *v0; // esi

  v0 = gDiskGraphInfo.strName.m_Data;
  if ( gDiskGraphInfo.strName.m_Data )
  {
    if ( !InterlockedDecrement(&gDiskGraphInfo.strName.m_Data->m_RefCount) && v0 )
    {
      if ( v0->m_wstr )
      {
        SysFreeString(v0->m_wstr);
        v0->m_wstr = 0;
      }
      if ( v0->m_str )
      {
        j_j__free(v0->m_str);
        v0->m_str = 0;
      }
      j__free(v0);
    }
    gDiskGraphInfo.strName.m_Data = 0;
  }
}

//----- (0102AC00) --------------------------------------------------------
void __cdecl sub_102AC00()
{
  Data_t_bstr_t *v0; // esi

  v0 = gIOGraphInfo.strName.m_Data;
  if ( gIOGraphInfo.strName.m_Data )
  {
    if ( !InterlockedDecrement(&gIOGraphInfo.strName.m_Data->m_RefCount) && v0 )
    {
      if ( v0->m_wstr )
      {
        SysFreeString(v0->m_wstr);
        v0->m_wstr = 0;
      }
      if ( v0->m_str )
      {
        j_j__free(v0->m_str);
        v0->m_str = 0;
      }
      j__free(v0);
    }
    gIOGraphInfo.strName.m_Data = 0;
  }
}

//----- (0102AC60) --------------------------------------------------------
void __cdecl sub_102AC60()
{
  Data_t_bstr_t *v0; // esi

  v0 = gNetworkGraphInfo.strName.m_Data;
  if ( gNetworkGraphInfo.strName.m_Data )
  {
    if ( !InterlockedDecrement(&gNetworkGraphInfo.strName.m_Data->m_RefCount) && v0 )
    {
      if ( v0->m_wstr )
      {
        SysFreeString(v0->m_wstr);
        v0->m_wstr = 0;
      }
      if ( v0->m_str )
      {
        j_j__free(v0->m_str);
        v0->m_str = 0;
      }
      j__free(v0);
    }
    gNetworkGraphInfo.strName.m_Data = 0;
  }
}

//----- (0102ACC0) --------------------------------------------------------
void __cdecl sub_102ACC0()
{
  std__Tree_node *v0; // esi
  int *a2; // [esp+4h] [ebp-8h]
  char v2; // [esp+Bh] [ebp-1h]

  sub_FF5510(&gMap2, &a2, gMap2._Header->_Left, gMap2._Header);
  v0 = gMap2._Header;
  ATL::CAtlStringMgr::Clone(&v2);
  nullsub_2(v0);
  ATL::CAtlStringMgr::Clone(&v2);
  nullsub_2(&v0->_Parent);
  ATL::CAtlStringMgr::Clone(&v2);
  nullsub_2(&v0->_Right);
  ATL::CAtlStringMgr::Clone(&v2);
  j__free(v0);
}
// F97A90: using guessed type _DWORD __stdcall nullsub_2(_DWORD);

//----- (0102AD40) --------------------------------------------------------
void __cdecl sub_102AD40()
{
  std__Tree_node *v0; // esi
  int *a2; // [esp+4h] [ebp-8h]
  char v2; // [esp+Bh] [ebp-1h]

  sub_FF5510(&gMap3, &a2, gMap3._Header->_Left, gMap3._Header);
  v0 = gMap3._Header;
  ATL::CAtlStringMgr::Clone(&v2);
  nullsub_2(v0);
  ATL::CAtlStringMgr::Clone(&v2);
  nullsub_2(&v0->_Parent);
  ATL::CAtlStringMgr::Clone(&v2);
  nullsub_2(&v0->_Right);
  ATL::CAtlStringMgr::Clone(&v2);
  j__free(v0);
}
// F97A90: using guessed type _DWORD __stdcall nullsub_2(_DWORD);

//----- (0102ADC0) --------------------------------------------------------
void __cdecl sub_102ADC0()
{
  if ( hdc )
    DeleteDC(hdc);
  if ( dword_1085724 )
    DeleteObject(dword_1085724);
}

//----- (0102ADF0) --------------------------------------------------------
void __cdecl HttpInfo_Release()
{
  std__list_node *v0; // eax
  std__list_node *v1; // ecx
  std__list_node *v2; // esi
  std__list_node *v3; // eax
  std__list_node *v4; // ecx
  std__list_node *v5; // esi

  v0 = gHttpInfo.m_List2._Mypair._Myval2._Myhead;
  v1 = v0->_Next;
  v0->_Next = v0;
  gHttpInfo.m_List2._Mypair._Myval2._Myhead->_Prev = gHttpInfo.m_List2._Mypair._Myval2._Myhead;
  gHttpInfo.m_List2._Mypair._Myval2._Mysize = 0;
  if ( v1 != gHttpInfo.m_List2._Mypair._Myval2._Myhead )
  {
    do
    {
      v2 = v1->_Next;
      j__free(v1);
      v1 = v2;
    }
    while ( v2 != gHttpInfo.m_List2._Mypair._Myval2._Myhead );
  }
  j__free(gHttpInfo.m_List2._Mypair._Myval2._Myhead);
  v3 = gHttpInfo.m_List._Mypair._Myval2._Myhead;
  v4 = v3->_Next;
  v3->_Next = v3;
  gHttpInfo.m_List._Mypair._Myval2._Myhead->_Prev = gHttpInfo.m_List._Mypair._Myval2._Myhead;
  gHttpInfo.m_List._Mypair._Myval2._Mysize = 0;
  if ( v4 != gHttpInfo.m_List._Mypair._Myval2._Myhead )
  {
    do
    {
      v5 = v4->_Next;
      j__free(v4);
      v4 = v5;
    }
    while ( v5 != gHttpInfo.m_List._Mypair._Myval2._Myhead );
  }
  j__free(gHttpInfo.m_List._Mypair._Myval2._Myhead);
}

//----- (0102AE00) --------------------------------------------------------
void __cdecl sub_102AE00()
{
  EventList *v0; // edi
  EventList *v1; // ebx
  EventList *v2; // esi
  char v3; // [esp+8h] [ebp-4h]
  char v4; // [esp+9h] [ebp-3h]
  char v5; // [esp+Ah] [ebp-2h]
  char v6; // [esp+Bh] [ebp-1h]

  v0 = off_10857A4->_Myheader;
  off_10857A4->_Myheader = off_10857A4;
  off_10857A4->_Mysize = off_10857A4;
  v1 = off_10857A4;
  dword_10857A8 = 0;
  if ( v0 != off_10857A4 )
  {
    do
    {
      v2 = v0->_Myheader;
      ATL::CAtlStringMgr::Clone(&v6);
      nullsub_2(v0);
      ATL::CAtlStringMgr::Clone(&v5);
      nullsub_2(&v0->_Mysize);
      ATL::CAtlStringMgr::Clone(&v4);
      nullsub_2(&v0[1]);
      ATL::CAtlStringMgr::Clone(&v3);
      j__free(v0);
      v1 = off_10857A4;
      v0 = v2;
    }
    while ( v2 != off_10857A4 );
  }
  ATL::CAtlStringMgr::Clone(&v4);
  nullsub_2(v1);
  ATL::CAtlStringMgr::Clone(&v4);
  nullsub_2(&v1->_Mysize);
  ATL::CAtlStringMgr::Clone(&v3);
  j__free(v1);
}
// F97A90: using guessed type _DWORD __stdcall nullsub_2(_DWORD);
// 10857A8: using guessed type int dword_10857A8;

//----- (0102AED0) --------------------------------------------------------
void __cdecl sub_102AED0()
{
  void **v0; // edi
  char *v1; // ebx
  void **v2; // esi
  char v3; // [esp+8h] [ebp-4h]
  char v4; // [esp+9h] [ebp-3h]
  char v5; // [esp+Ah] [ebp-2h]
  char v6; // [esp+Bh] [ebp-1h]

  v0 = *dword_108579C;
  *dword_108579C = dword_108579C;
  *(dword_108579C + 1) = dword_108579C;
  v1 = dword_108579C;
  dword_10857A0 = 0;
  if ( v0 != dword_108579C )
  {
    do
    {
      v2 = *v0;
      ATL::CAtlStringMgr::Clone(&v6);
      nullsub_2(v0);
      ATL::CAtlStringMgr::Clone(&v5);
      nullsub_2(v0 + 1);
      ATL::CAtlStringMgr::Clone(&v4);
      nullsub_2(v0 + 2);
      ATL::CAtlStringMgr::Clone(&v3);
      j__free(v0);
      v1 = dword_108579C;
      v0 = v2;
    }
    while ( v2 != dword_108579C );
  }
  ATL::CAtlStringMgr::Clone(&v4);
  nullsub_2(v1);
  ATL::CAtlStringMgr::Clone(&v4);
  nullsub_2(v1 + 4);
  ATL::CAtlStringMgr::Clone(&v3);
  j__free(v1);
}
// F97A90: using guessed type _DWORD __stdcall nullsub_2(_DWORD);
// 10857A0: using guessed type int dword_10857A0;

//----- (0102AFA0) --------------------------------------------------------
void __cdecl sub_102AFA0()
{
  EventList *v0; // edi
  EventList *v1; // ebx
  EventList *v2; // esi
  char v3; // [esp+8h] [ebp-4h]
  char v4; // [esp+9h] [ebp-3h]
  char v5; // [esp+Ah] [ebp-2h]
  char v6; // [esp+Bh] [ebp-1h]

  v0 = off_10857AC->_Myheader;
  off_10857AC->_Myheader = off_10857AC;
  off_10857AC->_Mysize = off_10857AC;
  v1 = off_10857AC;
  dword_10857B0 = 0;
  if ( v0 != off_10857AC )
  {
    do
    {
      v2 = v0->_Myheader;
      ATL::CAtlStringMgr::Clone(&v6);
      nullsub_2(v0);
      ATL::CAtlStringMgr::Clone(&v5);
      nullsub_2(&v0->_Mysize);
      ATL::CAtlStringMgr::Clone(&v4);
      nullsub_2(&v0[1]);
      ATL::CAtlStringMgr::Clone(&v3);
      j__free(v0);
      v1 = off_10857AC;
      v0 = v2;
    }
    while ( v2 != off_10857AC );
  }
  ATL::CAtlStringMgr::Clone(&v4);
  nullsub_2(v1);
  ATL::CAtlStringMgr::Clone(&v4);
  nullsub_2(&v1->_Mysize);
  ATL::CAtlStringMgr::Clone(&v3);
  j__free(v1);
}
// F97A90: using guessed type _DWORD __stdcall nullsub_2(_DWORD);
// 10857B0: using guessed type int dword_10857B0;

//----- (0102B070) --------------------------------------------------------
void __cdecl sub_102B070()
{
  char *v0; // esi
  char v1; // [esp+4h] [ebp-8h]
  char v2; // [esp+Bh] [ebp-1h]

  sub_1002C10(&gHttpInfo.field_1C, &v1, *gHttpInfo.field_1C, gHttpInfo.field_1C);
  v0 = gHttpInfo.field_1C;
  ATL::CAtlStringMgr::Clone(&v2);
  nullsub_2(v0);
  ATL::CAtlStringMgr::Clone(&v2);
  nullsub_2(v0 + 4);
  ATL::CAtlStringMgr::Clone(&v2);
  nullsub_2(v0 + 8);
  ATL::CAtlStringMgr::Clone(&v2);
  j__free(v0);
}
// F97A90: using guessed type _DWORD __stdcall nullsub_2(_DWORD);

//----- (0102B0F0) --------------------------------------------------------
void __cdecl sub_102B0F0()
{
  VariantClear(&pvarg);
}

//----- (0102B0FC) --------------------------------------------------------
void __cdecl sub_102B0FC()
{
  struct _RTL_CRITICAL_SECTION *v0; // esi

  if ( _InterlockedExchangeAdd(&unk_10613A0, 0xFFFFFFFF) < 0 )
  {
    v0 = &stru_10857E0;
    do
    {
      _Mtxdst(v0);
      ++v0;
    }
    while ( v0 < &dword_1085840 );
  }
}
// 1085840: using guessed type int dword_1085840;

//----- (0102B106) --------------------------------------------------------
void __cdecl sub_102B106()
{
  std::_Fac_tidy_reg_t::~_Fac_tidy_reg_t(&unk_108585A);
}

//----- (0102B110) --------------------------------------------------------
void __cdecl sub_102B110()
{
  std::locale::~locale(&dword_1085864);
}
// 1085864: using guessed type int dword_1085864;

//----- (0102B11A) --------------------------------------------------------
void __cdecl sub_102B11A()
{
  _Init_atexit::~_Init_atexit(&unk_10858F3);
}

//----- (0102B124) --------------------------------------------------------
void __cdecl sub_102B124()
{
  struct _RTL_CRITICAL_SECTION *v0; // esi

  if ( _InterlockedExchangeAdd(&unk_10613A0, 0xFFFFFFFF) < 0 )
  {
    v0 = &stru_10857E0;
    do
    {
      _Mtxdst(v0);
      ++v0;
    }
    while ( v0 < &dword_1085840 );
  }
}
// 1085840: using guessed type int dword_1085840;

//----- (0102B12E) --------------------------------------------------------
void __cdecl ATL::_dynamic_atexit_destructor_for___AtlBaseModule__()
{
  ATL::CAtlBaseModule::~CAtlBaseModule(&ATL::_AtlBaseModule);
}

// ALL OK, 1648 function(s) have been successfully decompiled
