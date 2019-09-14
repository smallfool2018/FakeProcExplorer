//----- (0105F8F0) --------------------------------------------------------
bool __cdecl sub_105F8F0(double a1, double *a2)
{
  bool result; // al

  result = a1 != *a2;
  *a2 = a1;
  return result;
}

//----- (0105F920) --------------------------------------------------------
char __cdecl sub_105F920(int a1, int a2, _DWORD *a3)
{
  char result; // al

  if ( a1 != *a3 || a2 != a3[1] )
  {
    *a3 = a1;
    a3[1] = a2;
    result = 1;
  }
  else
  {
    *a3 = a1;
    a3[1] = a2;
    result = 0;
  }
  return result;
}

//----- (0105F950) --------------------------------------------------------
void __cdecl VerifyImageThreadProc(tagTREEVIEWLISTITEMPARAM *pItemParam)
{
  VerifyImage(pItemParam, 1);
  if ( pItemParam->nListType )
    DLLLISTITEMPARAM_Release(pItemParam);
  else
    TreeViewListItemParam_Release(pItemParam);
}

//----- (0105F980) --------------------------------------------------------
int __thiscall ATL::CComCriticalSection::Init(LPCRITICAL_SECTION lpCriticalSection)
{
  int result; // eax

  if ( InitializeCriticalSectionAndSpinCount(lpCriticalSection, 0) )
    return 0;
  result = GetLastError();
  if ( result > 0 )
    result = result | 0x80070000;
  return result;
}

//----- (0105F9B0) --------------------------------------------------------
int sub_105F9B0(wchar_t *DstBuf, size_t MaxCount, wchar_t *Format, ...)
{
  va_list ArgList; // [esp+14h] [ebp+14h]

  va_start(ArgList, Format);
  return _vsnwprintf_s(DstBuf, 0x100u, MaxCount, Format, ArgList);
}

//----- (0105F9D0) --------------------------------------------------------
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
// 10E5720: using guessed type int gnStatusBarItemCount;
// 105F9D0: using guessed type LPARAM nID[32];

//----- (0105FA90) --------------------------------------------------------
int __cdecl GetStringByMenuID(WPARAM wParam, void *pItem)
{
  unsigned int uMenuID; // eax
  __int16 Buffer[1024]; // [esp+4h] [ebp-804h]

  uMenuID = *(pItem + 1);
  if ( uMenuID <= IDM_VIEW_PROCESS_PROPERTIES )
  {
    if ( uMenuID == IDM_VIEW_PROCESS_PROPERTIES )
    {
      LoadStringW(ghInstance, IDS_PROPERTIES, Buffer, 1024);
    }
    else
    {
      switch ( uMenuID )
      {
        case IDM_VIEW_REFRESH_NOW:
          LoadStringW(ghInstance, IDS_REFRESH_NOW, Buffer, 1024);
          break;
        case IDM_VIEW_SHOW_UNNAMED_HANDLES_AND_MAPPINGS:
          LoadStringW(ghInstance, IDS_SHOW_UNNAMED_OBJECTS, Buffer, 1024);
          break;
        case IDC_DLG_DLLSTRINGS_BUTTON_SAVE:
          LoadStringW(ghInstance, IDS_SAVE, Buffer, 1024);
          break;
        case IDM_PROCESS_KILL_PROCESS:
          LoadStringW(ghInstance, IDS_KILL_PROCESS_CLOSE_HANDLE, Buffer, 1024);
          break;
        case IDM_POPUP_DLL_PROPERTIES:
          if ( gConfig.bShowDllView )
            LoadStringW(ghInstance, IDS_VIEW_HANDLES, Buffer, 1024);
          else
            LoadStringW(ghInstance, IDS_VIEW_DLLS, Buffer, 1024);
          break;
        case IDM_VIEW_SHOW_PROCESS_TREE:
          LoadStringW(ghInstance, IDS_SHOW_PROCESS_TREE, Buffer, 1024);
          break;
        case IDM_VIEW_SHOW_LOWER_PANE:
          if ( gConfig.bShowLowerPane )
            LoadStringW(ghInstance, IDS_HIDE_LOWER_PANE, Buffer, 1024);
          else
            LoadStringW(ghInstance, IDS_SHOW_LOWER_PANE, Buffer, 1024);
          break;
        case IDM_TRAYMENU_CONTEXT_SYSTEM_INFORMATION:
          LoadStringW(ghInstance, IDS_SYSTEM_INFORMATION, Buffer, 1024);
          break;
        case IDM_FIND_HANDLE_OR_DLL:
          LoadStringW(ghInstance, IDS_FIND_HANDLE_, Buffer, 1024);
          break;
        case IDM_SEARCH_IN_PROCESS:
          LoadStringW(ghInstance, IDS_FIND_HANDLE_OR_DLL_, Buffer, 1024);
          break;
        case IDM_FIND_PROCESS_BY_WINDOW:
          LoadStringW(ghInstance, IDS_FIND_WINDOW_PROCESS, Buffer, 1024);
          break;
        default:
          break;
      }
    }
  }
  *(pItem + 3) = Buffer;
  return 0;
}

//----- (0105FCA0) --------------------------------------------------------
void __cdecl sub_105FCA0(CGraphData *pGraphData, __int64 a2)
{
  bool v2; // zf
  HICON v3; // esi
  RECT rc; // [esp+Ch] [ebp-21Ch]
  wchar_t Src; // [esp+1Ch] [ebp-20Ch]

  v2 = dword_10CA3C4 == 0;
  _mm_storeu_si128(&rc, _mm_load_si128(&xmmword_10A7010));
  if ( !v2 )
  {
    sub_1012410(&Src, 0x104u, L"Current Commit: ", a2);
    v3 = GraphData_DrawChart(pGraphData, 0, &rc, gConfig.ColorGraphBk, 0, 0.0);
    sub_1026910(ghMainWnd, dword_10CA3C4, v3, &Src);
    DestroyIcon(v3);
  }
}
// 10A6CEC: using guessed type wchar_t aCurrentCommit[17];
// 10A7010: using guessed type __int128 xmmword_10A7010;

//----- (0105FD50) --------------------------------------------------------
char __cdecl sub_105FD50(CGraphData *pGraphData, double a2, int a3, double a4)
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

  LOBYTE(v4) = dword_10E5738;
  v5 = pGraphData;
  v15 = pGraphData;
  if ( !(dword_10E5738 & 1) )
  {
    dword_10E5728 = 0;
    dword_10E5738 |= 1u;
    dword_10E572C = 0;
    hdc = 0;
    dword_10E5724 = 0;
    LOBYTE(v4) = atexit(sub_108ADC0);
  }
  v6 = byte_10E573C == 0;
  _mm_storeu_si128(&rc, _mm_load_si128(&xmmword_10A7010));
  if ( v6 )
  {
    byte_10E573C = 1;
    LOBYTE(v4) = BitmapItem_Create(&dword_10E5724, 16, 16);
  }
  if ( dword_10CA3BC || dword_10CA3C0 )
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
        v8 = dword_10E5740;
      }
      else if ( v8 == dword_10E5740 )
      {
        return v4;
      }
      v10 = dword_10E5728 * dword_10E572C;
      if ( dword_10E5734 && v10 )
      {
        memset32(
          dword_10E5734,
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
      BitmapItem_SetRectColor(&dword_10E5724, &rc, v11);
      piconinfo.hbmColor = dword_10E5724;
      piconinfo.hbmMask = dword_10E5724;
      piconinfo.fIcon = 1;
      piconinfo.xHotspot = 0;
      piconinfo.yHotspot = 0;
      v9 = CreateIconIndirect(&piconinfo);
    }
    v12 = v9;
    if ( v5->m_nItemID )
      sub_1026910(ghMainWnd, dword_10CA3C0, v9, Dst);
    else
      sub_1026910(ghMainWnd, dword_10CA3BC, v9, Dst);
    LOBYTE(v4) = DestroyIcon(v12);
    dword_10E5740 = v8;
  }
  return v4;
}
// 109CDC0: using guessed type double db_onehundred;
// 10A6C80: using guessed type wchar_t aCpuUsage0f[18];
// 10A7010: using guessed type __int128 xmmword_10A7010;
// 10CA3BC: using guessed type int dword_10CA3BC;
// 10E5728: using guessed type int dword_10E5728;
// 10E572C: using guessed type int dword_10E572C;
// 10E5734: using guessed type int dword_10E5734;
// 10E5738: using guessed type int dword_10E5738;
// 10E573C: using guessed type char byte_10E573C;
// 10E5740: using guessed type int dword_10E5740;
// 105FD50: using guessed type wchar_t Dst[260];

//----- (01060010) --------------------------------------------------------
CGraphData *__cdecl sub_1060010(CGraphData *a1, int a2, __int64 a3, __int64 a4, __int64 a5)
{
  bool v5; // zf
  CGraphData *result; // eax
  int v7; // ebx
  HICON v8; // esi
  RECT rc; // [esp+28h] [ebp-21Ch]
  __int16 Dst[260]; // [esp+38h] [ebp-20Ch]

  v5 = dword_10CA3F4 == 0;
  result = a1;
  _mm_storeu_si128(&rc, _mm_load_si128(&xmmword_10A7010));
  if ( !v5 )
  {
    v7 = swprintf(Dst, L"Disk\n");
    if ( a2 )
    {
      PE_FormatDouble(1, &Dst[v7], 260 - v7, *&a4, *&a3, *&a5);
      if ( v7 >= 0 )
        swprintf_s(&Dst[v7], 260 - v7, L"\n%s", *(a2 + 60));
    }
    v8 = GraphData_DrawChart(a1, 0, &rc, gConfig.ColorGraphBk, 0, 0.0);
    sub_1026910(ghMainWnd, dword_10CA3F4, v8, Dst);
    result = DestroyIcon(v8);
  }
  return result;
}
// 10A7010: using guessed type __int128 xmmword_10A7010;
// 1060010: using guessed type wchar_t Dst[260];

//----- (01060130) --------------------------------------------------------
CGraphData *__cdecl sub_1060130(CGraphData *a1, int a2, __int64 a3, __int64 a4, __int64 a5)
{
  bool v5; // zf
  CGraphData *result; // eax
  int v7; // eax
  int v8; // esi
  HICON v9; // esi
  RECT rc; // [esp+28h] [ebp-21Ch]
  __int16 Dst[260]; // [esp+38h] [ebp-20Ch]

  v5 = dword_10CA3C8 == 0;
  result = a1;
  _mm_storeu_si128(&rc, _mm_load_si128(&xmmword_10A7010));
  if ( !v5 )
  {
    v7 = swprintf(Dst, L"I/O\n");
    if ( a2 )
    {
      v8 = PE_FormatDouble(1, &Dst[v7], 260 - v7, *&a4, *&a3, *&a5) + v7;
      if ( v8 >= 0 )
        swprintf_s(&Dst[v8], 260 - v8, L"\n%s", *(a2 + 60));
    }
    v9 = GraphData_DrawChart(a1, 0, &rc, gConfig.ColorGraphBk, 0, 0.0);
    sub_1026910(ghMainWnd, dword_10CA3C8, v9, Dst);
    result = DestroyIcon(v9);
  }
  return result;
}
// 10A7010: using guessed type __int128 xmmword_10A7010;
// 1060130: using guessed type wchar_t Dst[260];

//----- (01060250) --------------------------------------------------------
CGraphData *__cdecl sub_1060250(CGraphData *a1, int a2, __int64 a3, __int64 a4, __int64 a5)
{
  bool v5; // zf
  CGraphData *result; // eax
  int v7; // eax
  wchar_t *v8; // esi
  size_t v9; // edi
  HICON v10; // esi
  RECT rc; // [esp+28h] [ebp-21Ch]
  __int16 Dst[260]; // [esp+38h] [ebp-20Ch]

  v5 = dword_10CA600 == 0;
  result = a1;
  _mm_storeu_si128(&rc, _mm_load_si128(&xmmword_10A7010));
  if ( !v5 )
  {
    v7 = swprintf(Dst, L"Network\n");
    if ( a2 )
    {
      v8 = &Dst[v7];
      v9 = 260 - v7;
      PE_FormatDouble(1, &Dst[v7], 260 - v7, *&a4, *&a3, *&a5);
      swprintf_s(v8, v9, L"\n%s", *(a2 + 60));
    }
    v10 = GraphData_DrawChart(a1, 0, &rc, gConfig.ColorGraphBk, 0, 0.0);
    sub_1026910(ghMainWnd, dword_10CA600, v10, Dst);
    result = DestroyIcon(v10);
  }
  return result;
}
// 10A7010: using guessed type __int128 xmmword_10A7010;
// 1060250: using guessed type wchar_t Dst[260];

//----- (01060360) --------------------------------------------------------
void __cdecl sub_1060360(CGraphData *pGraphData, __int64 a2)
{
  bool v2; // zf
  HICON v3; // esi
  RECT rc; // [esp+Ch] [ebp-21Ch]
  wchar_t Src; // [esp+1Ch] [ebp-20Ch]

  v2 = dword_10CA3F0 == 0;
  _mm_storeu_si128(&rc, _mm_load_si128(&xmmword_10A7010));
  if ( !v2 )
  {
    sub_1012410(&Src, 0x104u, L"Physical Usage: ", a2);
    v3 = GraphData_DrawChart(pGraphData, 0, &rc, gConfig.ColorGraphBk, 0, 0.0);
    sub_1026910(ghMainWnd, dword_10CA3F0, v3, &Src);
    DestroyIcon(v3);
  }
}
// 10A6D10: using guessed type wchar_t aPhysicalUsage[17];
// 10A7010: using guessed type __int128 xmmword_10A7010;

//----- (01060410) --------------------------------------------------------
double *__usercall sub_1060410@<eax>(double a1@<st0>, double st6_0@<st1>, HWND a2, int a3, double *a4, double *a5)
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
    dword_10C10E8 = -1;
    dword_10C10EC = -1;
    dword_10C10F0 = -1;
    dword_10C10F4 = -1;
    dword_10C10F8 = -1;
    dword_10C10FC = -1;
    dword_10C1100 = -1;
    dword_10C1104 = -1;
    qword_10C1110 = *&dbValue3;
    qword_10C1108 = *&dbValue3;
    qword_10C1118 = *&dbValue3;
    return result;
  }
  sub_1057400(0i64, a4, a5, &v23);
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
              v16 = sub_105F9B0(chText, 0xFFFFFFFF, L"Refresh: ", v21);
              FileTimeToLocalFileTime(&gTimeQuerySystemInfo, &LocalFileTime);
              FileTimeToSystemTime(&LocalFileTime, &SystemTime);
              GetTimeFormatW(0x400u, 0, &SystemTime, 0, &chText[v16], 256 - v16);
              v10 = v25;
              break;
            case 0x2000u:
              if ( *(a3 + 32) == *&qword_10C1128 )
              {
                v14 = v29;
                if ( !v29 )
                {
                  ++v7;
                  goto LABEL_86;
                }
              }
              wsprintf(chText, L"Physical Usage: %02.2f%%", *(a3 + 32));
              qword_10C1128 = *(a3 + 32);
              break;
            case 0x4000u:
              if ( *(a3 + 40) == *&qword_10C1130 )
              {
                v14 = v29;
                if ( !v29 )
                {
                  ++v7;
                  goto LABEL_86;
                }
              }
              wsprintf(chText, L"Own Physical Usage: %02.2f%%", *(a3 + 40));
              qword_10C1130 = *(a3 + 40);
              break;
          }
        }
        else
        {
          switch ( v12 )
          {
            case 0x800u:
              if ( *(a3 + 68) == dword_10C10FC )
              {
                v14 = v29;
                if ( !v29 )
                {
                  ++v7;
                  goto LABEL_86;
                }
              }
              wsprintf(chText, L"Own Handles: %d", *(a3 + 68));
              dword_10C10FC = *(a3 + 68);
              break;
            case 0x100u:
              if ( *(a3 + 56) == dword_10C10F0 )
              {
                v14 = v29;
                if ( !v29 )
                {
                  ++v7;
                  goto LABEL_86;
                }
              }
              wsprintf(chText, L"Threads: %d", *(a3 + 56));
              dword_10C10F0 = *(a3 + 56);
              break;
            case 0x200u:
              if ( *(a3 + 60) == dword_10C10F4 )
              {
                v14 = v29;
                if ( !v29 )
                {
                  ++v7;
                  goto LABEL_86;
                }
              }
              wsprintf(chText, L"Own Threads: %d", *(a3 + 60));
              dword_10C10F4 = *(a3 + 60);
              break;
            case 0x400u:
              if ( *(a3 + 64) == dword_10C10F8 )
              {
                v14 = v29;
                if ( !v29 )
                {
                  ++v7;
                  goto LABEL_86;
                }
              }
              wsprintf(chText, L"Handles: %d", *(a3 + 64));
              dword_10C10F8 = *(a3 + 64);
              break;
          }
        }
      }
      else if ( v12 == 128 )
      {
        if ( *(a3 + 76) == dword_10C1104 )
        {
          v14 = v29;
          if ( !v29 )
          {
            ++v7;
            goto LABEL_86;
          }
        }
        wsprintf(chText, L"Own .NET Processes: %d", *(a3 + 76));
        dword_10C1104 = *(a3 + 76);
      }
      else
      {
        switch ( v12 )
        {
          case 1u:
            ArgList = *a3;
            if ( *a3 == *&qword_10C1110 )
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
            qword_10C1110 = *a3;
            break;
          case 2u:
            v15 = *(a3 + 8);
            if ( v15 == *&qword_10C1108 )
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
            qword_10C1108 = *(a3 + 8);
            break;
          case 4u:
            if ( *(a3 + 16) == *&qword_10C1118 )
            {
              v14 = v29;
              if ( !v29 )
              {
                ++v7;
                goto LABEL_86;
              }
            }
            wsprintf(chText, L"Commit Charge: %02.2f%%", *(a3 + 16));
            qword_10C1118 = *(a3 + 16);
            break;
          case 8u:
            if ( *(a3 + 24) == *&qword_10C1120 )
            {
              v14 = v29;
              if ( !v29 )
              {
                ++v7;
                goto LABEL_86;
              }
            }
            wsprintf(chText, L"Own Commit Charge: %02.2f%%", *(a3 + 24));
            qword_10C1120 = *(a3 + 24);
            break;
          case 0x10u:
            if ( *(a3 + 48) == dword_10C10E8 )
            {
              v14 = v29;
              if ( !v29 )
              {
                ++v7;
                goto LABEL_86;
              }
            }
            wsprintf(chText, L"Processes: %d", *(a3 + 48));
            dword_10C10E8 = *(a3 + 48);
            break;
          case 0x20u:
            if ( *(a3 + 52) == dword_10C10EC )
            {
              v14 = v29;
              if ( !v29 )
              {
                ++v7;
                goto LABEL_86;
              }
            }
            wsprintf(chText, L"Own Processes: %d", *(a3 + 52));
            dword_10C10EC = *(a3 + 52);
            break;
          case 0x40u:
            if ( *(a3 + 72) == dword_10C1100 )
            {
              v14 = v29;
              if ( !v29 )
              {
                ++v7;
                goto LABEL_86;
              }
            }
            wsprintf(chText, &off_10A6EFC, *(a3 + 72));
            dword_10C1100 = *(a3 + 72);
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
// 109CDC0: using guessed type double db_onehundred;
// 10A6D34: using guessed type wchar_t aCpuUsage022f[20];
// 10A6D84: using guessed type wchar_t aOwnCpuUsage022[24];
// 10C10E8: using guessed type int dword_10C10E8;
// 10C10EC: using guessed type int dword_10C10EC;
// 10C10F0: using guessed type int dword_10C10F0;
// 10C10F4: using guessed type int dword_10C10F4;
// 10C10F8: using guessed type int dword_10C10F8;
// 10C10FC: using guessed type int dword_10C10FC;
// 10C1100: using guessed type int dword_10C1100;
// 10C1104: using guessed type int dword_10C1104;
// 10C1108: using guessed type __int64 qword_10C1108;
// 10C1110: using guessed type __int64 qword_10C1110;
// 10C1118: using guessed type __int64 qword_10C1118;
// 10C1120: using guessed type __int64 qword_10C1120;
// 10C1128: using guessed type __int64 qword_10C1128;
// 10C1130: using guessed type __int64 qword_10C1130;
// 1060410: using guessed type LPARAM lParam[32];
// 1060410: using guessed type WCHAR chText[256];

//----- (01060BB0) --------------------------------------------------------
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

//----- (010613B0) --------------------------------------------------------
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

//----- (01061420) --------------------------------------------------------
_DWORD *__stdcall std::_List_buy<tagEventItem *,std::allocator<tagEventItem *>>::_Buynode<tagEventItem * const &>(EventList *a1, _DWORD *a2, _DWORD *a3)
{
  _DWORD *result; // eax

  result = std::_List_alloc<std::_List_base_types<tagEventItem *,std::allocator<tagEventItem *>>>::_Buynode0(a1, a2);
  if ( result != -8 )
    result[2] = *a3;
  return result;
}

//----- (01061440) --------------------------------------------------------
CSystemProcessInfoMapNode **__thiscall sub_1061440(CSystemProcessInfoMap *this, CSystemProcessInfoMapNode **a2, char a3, CSystemProcessInfoMapNode *a4, int *a5, int a6)
{
  CSystemProcessInfoMap *v6; // edi
  CSystemProcessInfoMapNode *v7; // eax
  CSystemProcessInfoMapNode *v8; // ebx
  std__Tree_node *v9; // eax
  std_Tree_node_for_tagKeyName *v10; // eax
  std_Tree_node_for_tagKeyName *v11; // ecx
  std_Tree_node_for_tagKeyName *v12; // esi
  std_Tree_node_for_tagKeyName *v13; // edx
  std_Tree_node_for_tagKeyName *v14; // edx
  std_Tree_node_for_tagKeyName *v15; // ecx
  std_Tree_node_for_tagKeyName *v16; // edx
  std_Tree_node_for_tagKeyName *v17; // esi
  std_Tree_node_for_tagKeyName *v18; // ecx
  std_Tree_node_for_tagKeyName *v19; // ecx
  std_Tree_node_for_tagKeyName *v20; // edx
  std_Tree_node_for_tagKeyName *v21; // ecx
  std_Tree_node_for_tagKeyName *v22; // ecx
  std_Tree_node_for_tagKeyName *v23; // ecx
  CSystemProcessInfoMapNode **result; // eax

  v6 = this;
  if ( this->_Size >= 0xAAAAAA9u )
    std::_Xlength_error("map/set<T> too long");
  v7 = sub_FF1310(this, a5);
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

//----- (01061650) --------------------------------------------------------
int __thiscall sub_1061650(CSystemProcessInfoMap *this, int a2, CSystemProcessInfoMapNode *a3, int *a4, int a5)
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
        v7 = sub_FF14B0(v17, v20) == 0;
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
        v7 = sub_FF14B0(v18, v21);
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
      v13 = sub_1061440(v5, &a3, 1, v6, v8, a5);
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
  if ( sub_FF14B0(v19, v22) )
  {
    v13 = sub_1061440(v24, &a4, v25, v26, v8, a5);
    goto LABEL_21;
  }
  result = a2;
  *a2 = v12;
  *(a2 + 4) = 0;
  return result;
}
// 10681AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);

//----- (010617E0) --------------------------------------------------------
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
// 10C1138: using guessed type wchar_t aYouMustAgreeTo_2[298];
// 10E5774: using guessed type char gbAgreenmentLicensed;

//----- (01061820) --------------------------------------------------------
char __cdecl sub_1061820(ListItemData1 *a1)
{
  char result; // al

  result = 0;
  if ( a1 && (a1->field_4 == 1 || a1->field_4 == 4) )
    result = 1;
  return result;
}

//----- (01061840) --------------------------------------------------------
BOOL __cdecl sub_1061840(LPCWSTR lpFileName, wchar_t *Dest, int a3)
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

//----- (01061A50) --------------------------------------------------------
int __cdecl sub_1061A50(int pHash, wchar_t *Dest)
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
// 1092BBC: using guessed type wchar_t aHashSubmitted[18];
// 1092BE0: using guessed type wchar_t aScanningFile[17];
// 1092C04: using guessed type wchar_t aFileSubmitted[18];

//----- (01061B40) --------------------------------------------------------
void StartVirusTotalCheck()
{
  if ( !byte_10E57B4 )
  {
    HttpInfo_Open(&gHttpInfo, ghMainWnd, L"Process Explorer", 0, 0, 0);
    InitializeCriticalSection(&stru_10E5744);
    ghEventHandle = CreateEventW(0, 0, 0, 0);
    ghEventHandle2 = CreateEventW(0, 0, 0, 0);
    ghThreadHandle = _beginthreadex(0, 0, BackendThreadProc1, 0, 0, 0);
    ghEventHandle3 = CreateEventW(0, 0, 0, 0);
    ghThreadHandle2 = _beginthreadex(0, 0, BackendThreadProc2, 0, 0, 0);
    ghThreadHandle3 = _beginthreadex(0, 0, BackendThreadProc3, 0, 0, 0);
    byte_10E57B4 = 1;
  }
}
// 10E5760: using guessed type int ghThreadHandle;
// 10E5768: using guessed type int ghThreadHandle2;
// 10E5770: using guessed type int ghThreadHandle3;
// 10E57B4: using guessed type char byte_10E57B4;

//----- (01061C10) --------------------------------------------------------
char __cdecl sub_1061C10(ListItemData1 *a1)
{
  char result; // al
  int v2; // ecx

  result = 0;
  if ( !a1 || (v2 = a1->field_4, v2 == 1) || (v2 - 5) <= 1 )
    result = 1;
  return result;
}

//----- (01061C30) --------------------------------------------------------
void __cdecl sub_1061C30(DLLLISTITEMPARAM *pItemParam, char a2, int a3)
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
    EnterCriticalSection(&stru_10E5744);
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
    v6 = *sub_1062F90(&gHttpInfo.field_1C, &v18, &v23);
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
            v4 = sub_FF1350(v11);
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
          sub_1061650(&gHttpInfo.field_1C, &v19, 0, &v17, byte_10E5775);
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
          sub_FF9380(&off_10E57A4, &v22);
          SetEvent(ghEventHandle3);
        }
        else
        {
          sub_FF17F0(&dword_10E579C, &v22);
          SetEvent(ghEventHandle2);
        }
      }
    }
    LeaveCriticalSection(&stru_10E5744);
    _bstr_t::_Free(&v23);
  }
}
// 10E5774: using guessed type char gbAgreenmentLicensed;
// 10E5775: using guessed type char byte_10E5775;

//----- (01061EC0) --------------------------------------------------------
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
      v1(&stru_10E5744);
      if ( dword_10E57A8 )
        break;
LABEL_42:
      v2(&stru_10E5744);
      if ( WaitForMultipleObjects(2u, &Handles, 0, 0xFFFFFFFF) == 1 )
        goto LABEL_43;
    }
    while ( 1 )
    {
      v3 = off_10E57A4->_Myheader;
      v4 = off_10E57A4->_Myheader->field_4;
      v6 = off_10E57A4->_Myheader->field_0;
      a3 = off_10E57A4->_Myheader[1].field_0;
      v5 = a3;
      *v4 = v6;
      *(v3->field_0 + 4) = v3->field_4;
      --dword_10E57A8;
      j__free(v3);
      v2(&stru_10E5744);
      sub_10055A0(&gHttpInfo, (v5 + 2), psz);
      v1(&stru_10E5744);
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
          v20 = off_10E57AC;
          v21 = std::_List_buy<tagEventItem *,std::allocator<tagEventItem *>>::_Buynode<tagEventItem * const &>(
                  off_10E57AC,
                  off_10E57AC->_Mysize,
                  &a3);
          if ( (357913940 - dword_10E57B0) < 1 )
LABEL_52:
            std::_Xlength_error("list<T> too long");
          ++dword_10E57B0;
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
        v15 = off_10E57A4->_Myheader;
        v16 = std::_List_buy<tagEventItem *,std::allocator<tagEventItem *>>::_Buynode<tagEventItem * const &>(
                off_10E57A4->_Myheader,
                off_10E57A4->_Myheader->field_4,
                &a3);
        if ( (357913940 - dword_10E57A8) < 1 )
          goto LABEL_52;
        ++dword_10E57A8;
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
      LeaveCriticalSection(&stru_10E5744);
      if ( v29 )
        v17(ghMainWnd, 0x7F9u, 0, v5);
      v1 = EnterCriticalSection;
      EnterCriticalSection(&stru_10E5744);
      if ( !dword_10E57A8 )
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
// FFC3D4: using guessed type int (__stdcall *)(_DWORD);
// 10E57A8: using guessed type int dword_10E57A8;
// 10E57B0: using guessed type int dword_10E57B0;

//----- (01062230) --------------------------------------------------------
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
    EnterCriticalSection(&stru_10E5744);
    if ( dword_10E57A0 )
    {
      do
      {
        v4 = *dword_10E579C;
        v5 = *(*dword_10E579C + 4);
        v7 = **dword_10E579C;
        a3 = *(*dword_10E579C + 8);
        v6 = a3;
        *v5 = v7;
        *(*v4 + 4) = v4[1];
        --dword_10E57A0;
        j__free(v4);
        v3(&stru_10E5744);
        v8 = *(v6 + 16);
        if ( !v8 || (v9 = *v8) == 0 || !SysStringLen(v9) )
        {
          v10 = *(v6 + 20);
          v11 = (v10 ? *v10 : 0);
          if ( sub_1061840(v11, &psz, v6 + 24) )
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
          sub_1005160(&gHttpInfo, v6 + 8);
        }
        else
        {
          v17 = GetLastError();
          sub_1004320(&v47, v17);
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
        EnterCriticalSection(&stru_10E5744);
        v3 = LeaveCriticalSection;
      }
      while ( dword_10E57A0 );
      v2 = v45;
    }
    v3(&stru_10E5744);
    sub_1001FC0(&gHttpInfo);
    v21 = v2->_Myheader;
    if ( v2->_Myheader != v2 )
    {
      while ( 1 )
      {
        EnterCriticalSection(&stru_10E5744);
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
            v49 = *dword_10E579C;
            v30 = std::_List_buy<tagEventItem *,std::allocator<tagEventItem *>>::_Buynode<tagEventItem * const &>(
                    v49,
                    *(v49 + 1),
                    &a3);
            if ( (357913940 - dword_10E57A0) < 1 )
              goto LABEL_89;
            ++dword_10E57A0;
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
              v49 = *dword_10E579C;
              v35 = std::_List_buy<tagEventItem *,std::allocator<tagEventItem *>>::_Buynode<tagEventItem * const &>(
                      v49,
                      *(v49 + 1),
                      &a3);
              if ( (357913940 - dword_10E57A0) < 1 )
                goto LABEL_89;
              ++dword_10E57A0;
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
              v49 = off_10E57A4;
              v36 = std::_List_buy<tagEventItem *,std::allocator<tagEventItem *>>::_Buynode<tagEventItem * const &>(
                      off_10E57A4,
                      off_10E57A4->_Mysize,
                      &a3);
              if ( (357913940 - dword_10E57A8) < 1 )
                goto LABEL_89;
              ++dword_10E57A8;
              *(v49 + 1) = v36;
              *v36[1] = v36;
              SetEvent(ghEventHandle3);
            }
          }
        }
        v51 = 1;
LABEL_83:
        LeaveCriticalSection(&stru_10E5744);
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
// 10E57A0: using guessed type int dword_10E57A0;
// 10E57A8: using guessed type int dword_10E57A8;

//----- (01062860) --------------------------------------------------------
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

//----- (01062910) --------------------------------------------------------
char __cdecl sub_1062910(ListItemData1 *a1)
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
// 1092BB0: using guessed type wchar_t aDD[6];

//----- (01062970) --------------------------------------------------------
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
    if ( !sub_10037E0(&gHttpInfo) )
    {
      v2 = off_10E57AC->_Myheader;
      if ( off_10E57AC->_Myheader != off_10E57AC )
      {
        do
        {
          EnterCriticalSection(&stru_10E5744);
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
            --dword_10E57B0;
            j__free(v6);
          }
          else
          {
            v2 = v2->_Myheader;
          }
          LeaveCriticalSection(&stru_10E5744);
        }
        while ( v2 != off_10E57AC );
        v1 = WaitForSingleObject;
      }
      PostMessageW(ghMainWnd, 0x7F9u, 0, 0);
    }
  }
  return 0;
}
// 10E57B0: using guessed type int dword_10E57B0;

//----- (01062A70) --------------------------------------------------------
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

//----- (01062AB0) --------------------------------------------------------
void __stdcall sub_1062AB0(void *a1)
{
  _DWORD *v1; // edi
  void *i; // ebx
  int v3; // esi

  v1 = a1;
  for ( i = a1; !*(i + 13); v1 = i )
  {
    sub_1062AB0(*(i + 2));
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

//----- (01062B40) --------------------------------------------------------
_bstr_t *__thiscall sub_1062B40(void *this, _bstr_t *a2)
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
    if ( sub_FF14B0(v6, v7) )
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

//----- (01062BB0) --------------------------------------------------------
std_Tree_node_for_tagKeyName *__thiscall sub_1062BB0(std__tree *this, std__Tree_node *a2)
{
  std__Tree_node *v2; // esi
  std__Tree_node *v3; // eax
  std_Tree_node_for_tagKeyName *result; // eax

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

//----- (01062C10) --------------------------------------------------------
int **__thiscall sub_1062C10(int **this, int **a2, int **a3, int **a4)
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
      sub_1062CD0(v5, &v13, v10);
    }
    *a2 = v4;
    result = a2;
  }
  else
  {
    sub_1062AB0(v6[1]);
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

//----- (01062CD0) --------------------------------------------------------
_DWORD *__thiscall sub_1062CD0(_DWORD *this, _DWORD *a2, _DWORD *a3)
{
  std__tree *v3; // ebx
  std_Tree_node_for_tagKeyName *v4; // edx
  std_Tree_node_for_tagKeyName *v5; // edi
  std__Tree_node *v6; // ecx
  std__Tree_node *v7; // esi
  std_Tree_node_for_tagKeyName *v8; // eax
  std__Tree_node *v9; // ecx
  std__Tree_node *v10; // eax
  std_Tree_node_for_tagKeyName *v11; // eax
  std_Tree_node_for_tagKeyName *i; // ecx
  std_Tree_node_for_tagKeyName **v13; // eax
  bool v14; // cl
  std__Tree_node *v15; // ecx
  int v16; // esi
  unsigned int v17; // eax
  _DWORD *v18; // ecx
  _DWORD *result; // eax
  _DWORD *v20; // [esp+Ch] [ebp-8h]
  std_Tree_node_for_tagKeyName *v21; // [esp+10h] [ebp-4h]

  v3 = this;
  v21 = a3;
  sub_FF4CE0(&a3);
  v4 = v21;
  if ( v21->_Left->_IsNil )
  {
    v5 = v21->_Right;
  }
  else if ( v21->_Right->_IsNil )
  {
    v5 = v21->_Left;
  }
  else
  {
    v6 = a3;
    v20 = a3;
    v5 = a3[2];
    if ( a3 != v21 )
    {
      v21->_Left->_Parent = a3;
      v6->_Left = v21->_Left;
      if ( v6 == v21->_Right )
      {
        v7 = v6;
      }
      else
      {
        v7 = v6->_Parent;
        if ( !v5->_IsNil )
          v5->_Parent = v7;
        v7->_Left = v5;
        v6->_Right = v21->_Right;
        v21->_Right->_Parent = v6;
      }
      if ( v3->_Mypair._Myval2._Myhead->_Parent == v21 )
      {
        v3->_Mypair._Myval2._Myhead->_Parent = v6;
      }
      else
      {
        v13 = &v21->_Parent->_Left;
        if ( *v13 == v21 )
          *v13 = v6;
        else
          v13[2] = v6;
      }
      v6->_Parent = v21->_Parent;
      v14 = v6->_Color;
      *(v20 + 12) = v21->_Color;
      v4 = v21;
      v21->_Color = v14;
      goto LABEL_37;
    }
  }
  v7 = v21->_Parent;
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
  if ( v3->_Mypair._Myval2._Myhead->_Left == v21 )
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
  if ( v4->_Color != 1 )
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
        sub_10554B0(v3, v7);
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
          sub_1062BB0(v3, v15);
          v15 = v7->_Right;
        }
        v15->_Color = v7->_Color;
        v7->_Color = 1;
        v15->_Right->_Color = 1;
        sub_10554B0(v3, v7);
        break;
      }
    }
    else
    {
      if ( !v15->_Color )
      {
        v15->_Color = 1;
        v7->_Color = 0;
        sub_1062BB0(v3, v7);
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
          sub_10554B0(v3, v15);
          v15 = v7->_Left;
        }
        v15->_Color = v7->_Color;
        v7->_Color = 1;
        v15->_Left->_Color = 1;
        sub_1062BB0(v3, v7);
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
  v16 = v4->_Myval.first;
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
    v21->_Myval.first = 0;
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

//----- (01062F90) --------------------------------------------------------
int *__thiscall sub_1062F90(int *this, int *a2, volatile LONG **a3)
{
  int *v3; // edi
  _bstr_t *v4; // eax
  int v5; // esi
  Data_t_bstr_t *v6; // ecx
  int *result; // eax
  Data_t_bstr_t *v8; // [esp-8h] [ebp-14h]
  Data_t_bstr_t *v9; // [esp-4h] [ebp-10h]

  v3 = this;
  v4 = sub_1062B40(this, a3);
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
  if ( sub_FF14B0(v8, v9) )
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

//----- (01063010) --------------------------------------------------------
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

//----- (01063150) --------------------------------------------------------
signed int sub_1063150()
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

//----- (01063190) --------------------------------------------------------
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
        return sub_1063150();
LABEL_48:
      if ( v33 && !IsBuiltinAdministrative() )
      {
        v24 = sub_1026180(lpCmdLine_1, nShowCmd, 0);
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
          return sub_1063150();
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
              return sub_1063150();
          }
        }
        return sub_1063150();
      case 0x52u:
        if ( v21[2] != 84 )
          return sub_1063150();
        Command_ReplaceTaskManager(0);
        return 0;
      case 0x53u:
        if ( v21[2] != 58 )
          return sub_1063150();
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
// 10A1D84: using guessed type wchar_t aErrorElevating[16];
// 10BE100: using guessed type int gdwProcessId_0;
// 10C4E54: using guessed type int gdwVersion;
// 10CA388: using guessed type char gbHide;
// 10CA38C: using guessed type int gszCmdLine;
// 10CB1CC: using guessed type int gdwTebAddressOffset;

//----- (010636C0) --------------------------------------------------------
wchar_t *__cdecl sub_10636C0(wchar_t *Src)
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

//----- (01063720) --------------------------------------------------------
int __cdecl sub_1063720(int a1, int a2, wchar_t *a3, int a4, int a5)
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
  v8 = sub_10637B0(v5, a2, v6, &a1);
  if ( !v8 )
    v8 = sub_10638A0(a3, v6, a1, a4, a5);
  free(v6);
  return v8;
}

//----- (010637B0) --------------------------------------------------------
int __cdecl sub_10637B0(int *a1, int a2, int a3, _DWORD *a4)
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

//----- (010638A0) --------------------------------------------------------
int __cdecl sub_10638A0(wchar_t *a1, int a2, int a3, int a4, int a5)
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
// 10A7564: using guessed type wchar_t aHostprocesside[22];

//----- (010639A0) --------------------------------------------------------
MACRO_HRESULT __cdecl sub_10639A0(int *a1)
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

//----- (01063A00) --------------------------------------------------------
int __cdecl sub_1063A00(int ArgList, int a2)
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
  if ( sub_10637B0(pProxy, &Dst, v7, &v17) )
  {
    v8 = sub_1063720(pProxy, L"select * from msft_providers", &Src, v3, &v17);
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
      if ( !sub_1063CB0(v10, ppv, &v14) )
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
// 10A7494: using guessed type wchar_t aRootCimv2[11];
// 10A74B0: using guessed type wchar_t aSelectFromMsft[60];
// 10A7528: using guessed type wchar_t aSelectFromMsft_0[29];

//----- (01063CB0) --------------------------------------------------------
signed int __cdecl sub_1063CB0(int a1, int a2, void **a3)
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
      _mm_storeu_si128(SubKey, _mm_loadu_si128(&xmmword_10A7624));
      _mm_storeu_si128(&v31, _mm_loadu_si128(&xmmword_10A7634));
      _mm_storeu_si128(&v32, _mm_loadu_si128(&xmmword_10A7644));
      memset(&v33, 0, 0x1CEu);
      if ( !wcscat_s(SubKey, 0xFFu, v11)
        && !wcscat_s(SubKey, 0xFFu, L"\\InprocServer32")
        && !RegOpenKeyExW(HKEY_LOCAL_MACHINE, SubKey, 0, 0x20119u, &phkResult) )
      {
        memset(Data, 0, 0x1FEu);
        cbData = 510;
        if ( !RegQueryValueExW(phkResult, &gszNullString, 0, 0, Data, &cbData) )
        {
          v12 = sub_10636C0(v18.bstrVal);
          v3 = v26;
          *v26 = v12;
          if ( v12 )
          {
            v13 = sub_10636C0(pvarg.bstrVal);
            v3[1] = v13;
            if ( v13 )
            {
              v14 = sub_10636C0(Data);
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
// 10A7590: using guessed type wchar_t aNamespace_0[10];
// 10A75A4: using guessed type wchar_t aProvider[9];
// 10A75B8: using guessed type wchar_t aSelectFromWin3[45];
// 10A7618: using guessed type wchar_t aClsid_0[6];
// 10A7624: using guessed type __int128 xmmword_10A7624;
// 10A7634: using guessed type __int128 xmmword_10A7634;
// 10A7644: using guessed type __int128 xmmword_10A7644;

//----- (01064170) --------------------------------------------------------
void __stdcall __noreturn _com_issue_error(int a1)
{
  ATL::_com_error::_com_error(a1, 0);
}
// 10C138C: using guessed type int (__cdecl *ATL::_com_error::_com_error)(_DWORD, _DWORD);

//----- (01064190) --------------------------------------------------------
_DWORD *__thiscall sub_1064190(_DWORD *this, int a2)
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
// 10A7BCC: using guessed type int (__thiscall *ATL::_com_error::`vftable')(void *, char);

//----- (010641D0) --------------------------------------------------------
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
// 10A7BCC: using guessed type int (__thiscall *ATL::_com_error::`vftable')(void *, char);

//----- (01064200) --------------------------------------------------------
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
// 10A7BCC: using guessed type int (__thiscall *ATL::_com_error::`vftable')(void *, char);

//----- (01064240) --------------------------------------------------------
void __cdecl __noreturn sub_1064240(int a1, int a2)
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
// 10681AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);
// 10A7BCC: using guessed type int (__thiscall *ATL::_com_error::`vftable')(void *, char);
// 10B5BFC: using guessed type int _TI1_AV_com_error__;

//----- (01064270) --------------------------------------------------------
CHAR *__stdcall sub_1064270(LPCWSTR lpWideCharStr)
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

//----- (01064390) --------------------------------------------------------
BSTR __stdcall _com_util::ConvertStringToBSTR(LPCSTR lpszText)
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

//----- (01064501) --------------------------------------------------------
std::exception *__thiscall sub_1064501(std::exception *this, struct exception *a2)
{
  std::exception *v2; // esi

  v2 = this;
  std::exception::exception(this, a2);
  *v2 = &std::bad_alloc::`vftable';
  return v2;
}
// 10A7BD4: using guessed type void *std::bad_alloc::`vftable';

//----- (0106451C) --------------------------------------------------------
std::exception *__thiscall sub_106451C(std::exception *this, struct exception *a2)
{
  std::exception *v2; // esi

  v2 = this;
  std::exception::exception(this, a2);
  *v2 = &std::length_error::`vftable';
  return v2;
}
// 10A7BFC: using guessed type void *std::length_error::`vftable';

//----- (01064537) --------------------------------------------------------
std::exception *__thiscall sub_1064537(std::exception *this, struct exception *a2)
{
  std::exception *v2; // esi

  v2 = this;
  std::exception::exception(this, a2);
  *v2 = &std::logic_error::`vftable';
  return v2;
}
// 10A7BF0: using guessed type void *std::logic_error::`vftable';

//----- (01064552) --------------------------------------------------------
std::exception *__thiscall sub_1064552(std::exception *this, struct exception *a2)
{
  std::exception *v2; // esi

  v2 = this;
  std::exception::exception(this, a2);
  *v2 = &std::out_of_range::`vftable';
  return v2;
}
// 10A7C08: using guessed type void *std::out_of_range::`vftable';

//----- (0106456D) --------------------------------------------------------
void __thiscall sub_106456D(std::exception *this)
{
  *this = &std::bad_alloc::`vftable';
  std::_system_error::~_system_error(this);
}
// 10A7BD4: using guessed type void *std::bad_alloc::`vftable';

//----- (01064585) --------------------------------------------------------
void *__thiscall sub_1064585(void *this, char a2)
{
  void *v2; // esi

  v2 = this;
  *this = &std::bad_alloc::`vftable';
  std::_system_error::~_system_error(this);
  if ( a2 & 1 )
    j__free(v2);
  return v2;
}
// 10A7BD4: using guessed type void *std::bad_alloc::`vftable';

//----- (010645AA) --------------------------------------------------------
void *__thiscall sub_10645AA(void *this, char a2)
{
  void *v2; // esi

  v2 = this;
  std::_system_error::~_system_error(this);
  if ( a2 & 1 )
    j__free(v2);
  return v2;
}

//----- (0106465F) --------------------------------------------------------
int __cdecl sub_106465F(int a1)
{
  _DWORD *v1; // eax

  v1 = &unk_10A7E68;
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

//----- (01064689) --------------------------------------------------------
int __cdecl sub_1064689(int a1)
{
  int *v1; // eax

  v1 = &dword_10A7C10;
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
// 10A7C10: using guessed type int dword_10A7C10;

//----- (01064C4A) --------------------------------------------------------
int sub_1064C4A()
{
  return *&dword_10E5844;
}

//----- (01064F3E) --------------------------------------------------------
void __cdecl sub_1064F3E(LPCRITICAL_SECTION lpCriticalSection)
{
  EnterCriticalSection(lpCriticalSection);
}

//----- (01064F4C) --------------------------------------------------------
void __cdecl sub_1064F4C(LPCRITICAL_SECTION lpCriticalSection)
{
  LeaveCriticalSection(lpCriticalSection);
}

//----- (01064FDB) --------------------------------------------------------
CAtlBaseModule *__thiscall ATL::CAtlWinModule::CAtlWinModule(char *this)
{
  CAtlBaseModule *v1; // esi

  v1 = this;
  ATL::_ATL_WIN_MODULE70::_ATL_WIN_MODULE70(this);
  v1->baseclass.cbSize = 56;
  v1->baseclass.m_hInstResource = 16580608;
  v1->baseclass.m_hInst = 16580608;
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
// 10A8AF0: using guessed type GUID GUID_ATLVer110;
// 10E5714: using guessed type char ATL::CAtlBaseModule::m_bInitFailed;

//----- (0106502E) --------------------------------------------------------
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

//----- (01065051) --------------------------------------------------------
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

//----- (01065067) --------------------------------------------------------
int __thiscall ATL::CSimpleArray<HINSTANCE__ *,ATL::CSimpleArrayEqualHelper<HINSTANCE__ *>>::operator[](_DWORD *this, int a2)
{
  if ( a2 < 0 || a2 >= this[1] )
  {
    RaiseException(STATUS_ARRAY_BOUNDS_EXCEEDED, 1u, 0, 0);
    JUMPOUT(loc_1065090);
  }
  return *this + 4 * a2;
}

//----- (01065091) --------------------------------------------------------
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

//----- (01067B15) --------------------------------------------------------
void **sub_1067B15()
{
  return &off_10C1568;
}
// 10C1568: using guessed type void *off_10C1568;

//----- (010689CE) --------------------------------------------------------
int __thiscall sub_10689CE(_DWORD *this)
{
  *this = &type_info::`vftable';
  return unknown_libname_8(this);
}
// 1075348: using guessed type _DWORD __cdecl unknown_libname_8(_DWORD);
// 10A8BE8: using guessed type void *type_info::`vftable';

//----- (010689FA) --------------------------------------------------------
void *__thiscall sub_10689FA(void *this, char a2)
{
  void *v2; // esi

  v2 = this;
  sub_10689CE(this);
  if ( a2 & 1 )
    j__free(v2);
  return v2;
}

//----- (0106918B) --------------------------------------------------------
int sub_106918B()
{
  return flsall(1);
}
// 10691ED: using guessed type _DWORD __cdecl flsall(_DWORD);

//----- (01069CF7) --------------------------------------------------------
std::exception *__thiscall sub_1069CF7(std::exception *this, struct exception *a2)
{
  std::exception *v2; // esi

  v2 = this;
  std::exception::exception(this, a2);
  *v2 = &std::bad_cast::`vftable';
  return v2;
}
// 10A8FEC: using guessed type void *std::bad_cast::`vftable';

//----- (01069D12) --------------------------------------------------------
std::exception *__thiscall sub_1069D12(std::exception *this, char *a2)
{
  std::exception *v2; // esi

  v2 = this;
  std::exception::exception(this, &a2);
  *v2 = &std::bad_cast::`vftable';
  return v2;
}
// 10A8FEC: using guessed type void *std::bad_cast::`vftable';

//----- (01069D91) --------------------------------------------------------
void __thiscall std::_system_error::~_system_error(std::exception *this)
{
  *this = &std::exception::`vftable';
  std::exception::_Tidy(this);
}
// 10A8FCC: using guessed type void *std::exception::`vftable';

//----- (01069DCF) --------------------------------------------------------
void *__thiscall sub_1069DCF(void *this, char a2)
{
  void *v2; // esi

  v2 = this;
  *this = &std::exception::`vftable';
  std::exception::_Tidy(this);
  if ( a2 & 1 )
    j__free(v2);
  return v2;
}
// 10A8FCC: using guessed type void *std::exception::`vftable';

//----- (0106B822) --------------------------------------------------------
std::exception *__thiscall sub_106B822(std::exception *this, struct exception *a2)
{
  std::exception *v2; // esi

  v2 = this;
  std::exception::exception(this, a2);
  *v2 = &std::bad_exception::`vftable';
  return v2;
}
// 10A8FFC: using guessed type void *std::bad_exception::`vftable';

//----- (0106B83D) --------------------------------------------------------
void __thiscall sub_106B83D(std::exception *this)
{
  *this = &std::bad_exception::`vftable';
  std::_system_error::~_system_error(this);
}
// 10A8FFC: using guessed type void *std::bad_exception::`vftable';

//----- (0106B848) --------------------------------------------------------
void *__thiscall sub_106B848(void *this, char a2)
{
  void *v2; // esi

  v2 = this;
  *this = &std::bad_exception::`vftable';
  std::_system_error::~_system_error(this);
  if ( a2 & 1 )
    j__free(v2);
  return v2;
}
// 10A8FFC: using guessed type void *std::bad_exception::`vftable';

//----- (0106D342) --------------------------------------------------------
void __cdecl sub_106D342(DWORD dwMilliseconds)
{
  Sleep(dwMilliseconds);
}

//----- (0106F821) --------------------------------------------------------
void *__cdecl sub_106F821(void *a1)
{
  void *result; // eax

  result = a1;
  dword_10E5EBC = a1;
  return result;
}

//----- (0106F8CF) --------------------------------------------------------
void *__cdecl sub_106F8CF(void *a1)
{
  void *result; // eax

  result = a1;
  dword_10E5EC4 = a1;
  return result;
}

//----- (0106FAF6) --------------------------------------------------------
DWORD sub_106FAF6()
{
  return dwTlsIndex;
}

//----- (0107007A) --------------------------------------------------------
void sub_107007A()
{
  dword_10E69AC = 0;
}
// 10E69AC: using guessed type int dword_10E69AC;

//----- (0107533B) --------------------------------------------------------
void *__cdecl sub_107533B(void *a1)
{
  void *result; // eax

  result = a1;
  dword_10E6628 = a1;
  return result;
}

//----- (01077C9C) --------------------------------------------------------
void sub_1077C9C()
{
  void (**i)(void); // esi

  for ( i = &unk_10AF88C; i < &unk_10AF88C; ++i )
  {
    if ( *i )
      (*i)();
  }
}

//----- (01077CBC) --------------------------------------------------------
void __cdecl sub_1077CBC()
{
  void (**i)(void); // esi

  for ( i = &unk_10AF894; i < &unk_10AF894; ++i )
  {
    if ( *i )
      (*i)();
  }
}

//----- (01077CDC) --------------------------------------------------------
PVOID sub_1077CDC()
{
  return DecodePointer(dword_10E663C);
}

//----- (01077EFA) --------------------------------------------------------
int __cdecl sub_1077EFA(int a1)
{
  int result; // eax

  result = a1;
  dword_10E6648 = a1;
  return result;
}
// 10E6648: using guessed type int dword_10E6648;

//----- (01078B73) --------------------------------------------------------
HANDLE sub_1078B73()
{
  HANDLE result; // eax

  result = hObject;
  if ( hObject != -1 && hObject != -2 )
    result = CloseHandle(hObject);
  return result;
}

//----- (01079F90) --------------------------------------------------------
int sub_1079F90()
{
  __crtSetUnhandledExceptionFilter(__CxxUnhandledExceptionFilter);
  return 0;
}

//----- (0107A2BD) --------------------------------------------------------
int __cdecl sub_107A2BD(int a1)
{
  int result; // eax

  result = a1;
  dword_10E5EC8 = a1;
  return result;
}
// 10E5EC8: using guessed type int dword_10E5EC8;

//----- (0107B1A0) --------------------------------------------------------
int *sub_107B1A0()
{
  return &dword_10C2434;
}
// 10C2434: using guessed type int dword_10C2434;

//----- (0107B1A6) --------------------------------------------------------
int *sub_107B1A6()
{
  return &dword_10C2438;
}
// 10C2438: using guessed type int dword_10C2438;

//----- (0107B1AC) --------------------------------------------------------
int *sub_107B1AC()
{
  return &dword_10C2430;
}
// 10C2430: using guessed type int dword_10C2430;

//----- (0107B1B2) --------------------------------------------------------
void **sub_107B1B2()
{
  return &off_10C24C0;
}
// 10C24C0: using guessed type void *off_10C24C0;

//----- (0107B1B8) --------------------------------------------------------
signed int __cdecl sub_107B1B8(_DWORD *a1)
{
  signed int result; // eax

  if ( a1 )
  {
    *a1 = dword_10C2434;
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
// 106F859: using guessed type int _invalid_parameter_noinfo(void);
// 10C2434: using guessed type int dword_10C2434;

//----- (0107B1E2) --------------------------------------------------------
signed int __cdecl sub_107B1E2(_DWORD *a1)
{
  signed int result; // eax

  if ( a1 )
  {
    *a1 = dword_10C2438;
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
// 106F859: using guessed type int _invalid_parameter_noinfo(void);
// 10C2438: using guessed type int dword_10C2438;

//----- (0107B20C) --------------------------------------------------------
signed int __cdecl sub_107B20C(_DWORD *a1)
{
  signed int result; // eax

  if ( a1 )
  {
    *a1 = dword_10C2430;
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
// 106F859: using guessed type int _invalid_parameter_noinfo(void);
// 10C2430: using guessed type int dword_10C2430;

//----- (0107B5FC) --------------------------------------------------------
int __cdecl sub_107B5FC(const WCHAR *a1, int a2, int a3)
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
  if ( !dword_10E694C )
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
    dword_10E694C = EncodePointer(v6);
    v7 = GetProcAddress(v5, "GetActiveWindow");
    dword_10E6950 = EncodePointer(v7);
    v8 = GetProcAddress(v5, "GetLastActivePopup");
    dword_10E6954 = EncodePointer(v8);
    v9 = GetProcAddress(v5, "GetUserObjectInformationW");
    dword_10E695C = EncodePointer(v9);
    if ( dword_10E695C )
    {
      v10 = GetProcAddress(v5, "GetProcessWindowStation");
      dword_10E6958 = EncodePointer(v10);
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
    DecodePointer(dword_10E694C);
    return 3;
  }
  if ( dword_10E6958 == v4
    || dword_10E695C == v4
    || (v23 = DecodePointer(dword_10E6958), v12 = DecodePointer(dword_10E695C), v22 = v12, !v23)
    || !v12
    || (v13 = v23()) != 0 && v22(v13, 1, &v24, 12, &v19) && v25 & 1 )
  {
    if ( dword_10E6950 != v4 )
    {
      v15 = DecodePointer(dword_10E6950);
      if ( v15 )
      {
        v3 = v15();
        if ( v3 )
        {
          if ( dword_10E6954 != v4 )
          {
            v16 = DecodePointer(dword_10E6954);
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
  v17 = DecodePointer(dword_10E694C);
  if ( v17 )
    return v17(v3, lpOutputString, v20, v14);
  return 0;
}
// 106D069: using guessed type int __crtIsPackagedApp(void);

//----- (0107F550) --------------------------------------------------------
int sub_107F550()
{
  return 0;
}

//----- (0107FE30) --------------------------------------------------------
signed int __cdecl sub_107FE30(unsigned __int16 *a1, int *a2)
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
    v62 = dword_10C2570 - 1;
    v67 = 0;
    v79 = v82;
    v80 = v83;
    v7 = dword_10C2570 / 32;
    v57 = dword_10C2570 / 32;
    v65 = 31 - dword_10C2570 % 32;
    v8 = v65;
    if ( (1 << v65) & *(&v81 + dword_10C2570 / 32) )
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
    if ( v18 >= dword_10C256C - dword_10C2570 )
    {
      if ( v18 > dword_10C256C )
      {
        if ( v18 < dword_10C2568 )
        {
          v81 &= 0x7FFFFFFFu;
          v61 = v18 + dword_10C257C;
          v70 = dword_10C2574 / 32;
          v48 = dword_10C2574 % 32;
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
          v64 = dword_10C2574 / 32;
          v41 = dword_10C2574 % 32;
          v60 = dword_10C2574 % 32;
          v76 = 0;
          v42 = ~(-1 << dword_10C2574 % 32);
          v69 = 32 - dword_10C2574 % 32;
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
          v5 = dword_10C2568 + dword_10C257C;
          v2 = 1;
        }
        goto LABEL_83;
      }
      v81 = v78;
      v82 = v79;
      v58 = (dword_10C256C - v71) / 32;
      v83 = v80;
      v19 = (dword_10C256C - v71) % 32;
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
      v68 = (dword_10C2574 + 1) / 32;
      v36 = (dword_10C2574 + 1) % 32;
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
  v53 = v81 | (v56 != 0 ? 0x80000000 : 0) | (v5 << (31 - dword_10C2574));
  if ( dword_10C2578 == 64 )
  {
    v54 = v82;
    v3[1] = v53;
    *v3 = v54;
  }
  else if ( dword_10C2578 == 32 )
  {
    *v3 = v53;
  }
  return v2;
}
// 10C2568: using guessed type int dword_10C2568;
// 10C256C: using guessed type int dword_10C256C;
// 10C2570: using guessed type int dword_10C2570;
// 10C2574: using guessed type int dword_10C2574;
// 10C2578: using guessed type int dword_10C2578;
// 10C257C: using guessed type int dword_10C257C;

//----- (010803A2) --------------------------------------------------------
signed int __cdecl sub_10803A2(unsigned __int16 *a1, int *a2)
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
    v62 = dword_10C2588 - 1;
    v67 = 0;
    v79 = v82;
    v80 = v83;
    v7 = dword_10C2588 / 32;
    v57 = dword_10C2588 / 32;
    v65 = 31 - dword_10C2588 % 32;
    v8 = v65;
    if ( (1 << v65) & *(&v81 + dword_10C2588 / 32) )
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
    if ( v18 >= dword_10C2584 - dword_10C2588 )
    {
      if ( v18 > dword_10C2584 )
      {
        if ( v18 < dword_10C2580 )
        {
          v81 &= 0x7FFFFFFFu;
          v61 = v18 + dword_10C2594;
          v70 = dword_10C258C / 32;
          v48 = dword_10C258C % 32;
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
          v64 = dword_10C258C / 32;
          v41 = dword_10C258C % 32;
          v60 = dword_10C258C % 32;
          v76 = 0;
          v42 = ~(-1 << dword_10C258C % 32);
          v69 = 32 - dword_10C258C % 32;
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
          v5 = dword_10C2580 + dword_10C2594;
          v2 = 1;
        }
        goto LABEL_83;
      }
      v81 = v78;
      v82 = v79;
      v58 = (dword_10C2584 - v71) / 32;
      v83 = v80;
      v19 = (dword_10C2584 - v71) % 32;
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
      v68 = (dword_10C258C + 1) / 32;
      v36 = (dword_10C258C + 1) % 32;
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
  v53 = v81 | (v56 != 0 ? 0x80000000 : 0) | (v5 << (31 - dword_10C258C));
  if ( dword_10C2590 == 64 )
  {
    v54 = v82;
    v3[1] = v53;
    *v3 = v54;
  }
  else if ( dword_10C2590 == 32 )
  {
    *v3 = v53;
  }
  return v2;
}
// 10C2580: using guessed type int dword_10C2580;
// 10C2584: using guessed type int dword_10C2584;
// 10C2588: using guessed type int dword_10C2588;
// 10C258C: using guessed type int dword_10C258C;
// 10C2590: using guessed type int dword_10C2590;
// 10C2594: using guessed type int dword_10C2594;
