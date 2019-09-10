//----- (00FB2E00) --------------------------------------------------------
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

//----- (00FB2EC0) --------------------------------------------------------
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

//----- (00FB2F50) --------------------------------------------------------
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

//----- (00FB3260) --------------------------------------------------------
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

//----- (00FB3310) --------------------------------------------------------
_DWORD *__stdcall sub_FB3310(_DWORD *a1, _DWORD *a2, _DWORD *a3)
{
  _DWORD *result; // eax

  result = sub_FB4360(a1, a2);
  if ( result != -8 )
  {
    result[2] = *a3;
    result[3] = a3[1];
  }
  return result;
}

//----- (00FB3340) --------------------------------------------------------
char __cdecl sub_FB3340(HANDLE ProcessHandle, int a2, int a3, int time, int time_4, tagTREEVIEWLISTITEMPARAM *pItemParam, WPARAM wParam)
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
  v26 = sub_FFF8F0(v20, &pItemParam->field_568);
  v27 = RedrawColumn(v26, hWndTreeListView, 1650, wParam);
  CGraphData_Update(pItemParam->pGraphData4, __PAIR__(time_4, time), *&pItemParam->field_568, 0.0, 0);
  v28 = ghWndTreeListView;
  v29 = sub_FFF920(v41, 0, &pItemParam->field_5A0);
  v30 = RedrawColumn(v29, v28, 1653, wParam) | v27;
  v31 = *&pItemParam->field_5A0;
  CGraphData_Update(pItemParam->pGraphData5, __PAIR__(time_4, time), v31, 0.0, 0);
  v32 = ghWndTreeListView;
  v33 = sub_FFF920(v45, 0, &pItemParam->field_580);
  v34 = RedrawColumn(v33, v32, 1651, wParam) | v30;
  v35 = *&pItemParam->field_580;
  CGraphData_Update(pItemParam->pGraphData6, __PAIR__(time_4, time), v35, 0.0, 0);
  v36 = ghWndTreeListView;
  v37 = sub_FFF920(v46, 0, &pItemParam->field_590);
  v38 = RedrawColumn(v37, v36, 1652, wParam) | v34;
  v39 = *&pItemParam->field_590;
  CGraphData_Update(pItemParam->pGraphData7, __PAIR__(time_4, time), v39, 0.0, 0);
  return v38;
}
// 103CDC0: using guessed type double db_onehundred;
// 1064E54: using guessed type int gdwVersion;

//----- (00FB38F0) --------------------------------------------------------
void __cdecl sub_FB38F0(FILETIME time, signed __int64 a2, int a3, int a4, int a5, CGraphData *a6, CGraphData *a7)
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
  wchar_t *v31; // eax
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
  _D3DKMT_QUERYSTATISTICS v50; // [esp+80h] [ebp-1164h]
  _D3DKMT_QUERYSTATISTICS v51; // [esp+3A0h] [ebp-E44h]
  _D3DKMT_QUERYSTATISTICS v52; // [esp+6C0h] [ebp-B24h]
  wchar_t Dst; // [esp+9E0h] [ebp-804h]
  char v54; // [esp+9E2h] [ebp-802h]

  v40 = 0;
  Dst = 0;
  v46 = 0;
  memset(&v54, 0, 0x7FEu);
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
      memset(&v51, 0, 0x320u);
      v51.Type = 0;
      v51.AdapterLuid.LowPart = v9->_Myval;
      v51.AdapterLuid.HighPart = v9[1]._Next;
      if ( !D3DKMTQueryStatistics(&v51) )
      {
        v11 = 0;
        v41 = v51.QueryResult.AdapterInformation.NodeCount;
        v37 = 0;
        if ( v51.QueryResult.AdapterInformation.NodeCount )
        {
          v12 = 1;
          v39 = 1;
          v13 = a5 + 2184 + 2200 * v46;
          v46 += v51.QueryResult.NodeInformation.GlobalInformation.RunningTime.HighPart;
          v48 = v13;
          do
          {
            memset(&v50, 0, 0x320u);
            v50.Type = 5;
            v50.AdapterLuid.LowPart = v9->_Myval;
            v50.AdapterLuid.HighPart = v9[1]._Next;
            v50.QuerySegment.SegmentId = v11;
            if ( D3DKMTQueryStatistics(&v50) )
            {
              v15 = 0;
              v16 = 0;
            }
            else
            {
              v14 = (v12 & gConfig.dwGpuNodeUsageMask) == 0;
              v15 = v50.QueryResult.AdapterInformation.NodeCount;
              v16 = v50.QueryResult.AdapterInformation.NbSegments;
              if ( !v14 )
              {
                ++v40;
                v42 = (v50.QueryResult.SegmentInformation.CommitLimit + __PAIR__(v42, v45)) >> 32;
                v45 += v50.QueryResult.AdapterInformation.NbSegments;
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
              CGraphData_Update((v48 - 2184), time, v20, 0.0, 0);
            }
            else
            {
              v21 = v48;
            }
            v48 = v21 + 2200;
            v11 = v37 + 1;
            v12 = __ROL4__(v39, 1);
            v37 = v11;
            v39 = __ROL4__(v39, 1);
          }
          while ( v11 < v41 );
          v8 = v38;
        }
        v22 = 0;
        if ( v51.QueryResult.AdapterInformation.NbSegments )
        {
          do
          {
            memset(&v52, 0, 0x320u);
            v52.Type = 3;
            v52.AdapterLuid.LowPart = v9->_Myval;
            v52.AdapterLuid.HighPart = v9[1]._Next;
            v52.QuerySegment.SegmentId = v22;
            if ( !D3DKMTQueryStatistics(&v52) )
            {
              if ( gdwVersion < 3 )
              {
                v25 = v52.QueryResult.AdapterInformation.VidPnSourceCount >> 10;
                if ( v52.QueryResult.SegmentInformationV1.Aperture )
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
                v23 = v52.QueryResult.SegmentInformationV1.Memory.TotalBytesEvicted >> 10;
                v24 = v52.QueryResult.NodeInformation.GlobalInformation.PreemptionStatistics.PreemptionCounter[2] >> 10;
                if ( v52.QueryResult.AdapterInformation.ReferenceDmaBuffer.NbCall )
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
          while ( v22 < v51.QueryResult.AdapterInformation.NbSegments );
          v38 = v8;
        }
      }
      v9 = v9->_Next;
    }
    while ( v9 != gAdapterLuidList._Mypair._Myval2._Myhead );
    if ( v42 | v45 && *(a3 + 2184) )
    {
      v26 = (__PAIR__(v42, v45) - *(a3 + 2184));
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
  *(a3 + 2184) = v7;
  *(a3 + 2188) = v42;
  if ( a4 )
  {
    v36 = *(a4 + 68);
    a5_4 = *(a4 + 60);
    ArgList_4 = *(a4 + 1384);
    if ( gConfig.bShowCpuFractions )
      wsprintfW(&Dst, L"%02.02f%% %s:%d", ArgList_4, a5_4, v36);
    else
      wsprintfW(&Dst, L"%02.0f%% %s:%d", ArgList_4, a5_4, v36);
  }
  v31 = &Dst;
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
// 103CDC0: using guessed type double db_onehundred;
// 1064E54: using guessed type int gdwVersion;

//----- (00FB3FB0) --------------------------------------------------------
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
            v9 = sub_FB3310(
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
// 1064E38: using guessed type int D3DKMTCloseAdapter;
// 1064E54: using guessed type int gdwVersion;

//----- (00FB4360) --------------------------------------------------------
_DWORD *__stdcall sub_FB4360(_DWORD *a1, _DWORD *a2)
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

//----- (00FB43A0) --------------------------------------------------------
CGraphData *__thiscall sub_FB43A0(tagGraphInfo *pThis)
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
// 103CDC0: using guessed type double db_onehundred;

//----- (00FB4400) --------------------------------------------------------
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
// 1064E28: using guessed type int gdwVirtualScreenWidth;

//----- (00FB44A0) --------------------------------------------------------
void __thiscall sub_FB44A0(tagGraphInfo *this, TreeList_Item1 *pItem)
{
  tagGraphInfo *pGraphInfo; // edi
  int v3; // esi
  __int64 v4; // kr10_8
  signed __int64 v5; // kr20_8
  float v6; // xmm0_4
  int v7; // eax
  float v8; // xmm0_4
  float v9; // xmm0_4
  __int64 v10; // ST1C_8
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
    sub_FB2200(
      1,
      &szBuffer[v3],
      1024 - v3,
      COERCE__INT64(*&pItem->field_50),
      COERCE__INT64(*&pItem->field_48),
      COERCE__INT64(*&pItem->field_58));
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
    *&v10 = v9;
    v11 = *&pItem->field_20;
    sub_1000130(pGraphInfo->pGraphData, pItem->field_60, COERCE__INT64(*&pItem->field_18), *&v11, v10);
  }
  else if ( pGraphInfo == &gDiskGraphInfo )
  {
    v12 = *&pItem->field_28;
    *&v13 = v12;
    v14 = *&pItem->field_20;
    *&a5 = v14;
    v16 = *&pItem->field_18;
    sub_1000010(pGraphInfo->pGraphData, pItem->field_60, *&v16, a5, v13);
  }
  else if ( pGraphInfo == &gNetworkGraphInfo )
  {
    v17 = *&pItem->field_28;
    *&v18 = v17;
    v19 = *&pItem->field_20;
    *&v20 = v19;
    v21 = *&pItem->field_18;
    sub_1000250(pGraphInfo->pGraphData, pItem->field_60, *&v21, v20, v18);
  }
}

//----- (00FB47C0) --------------------------------------------------------
int __thiscall sub_FB47C0(_DWORD *this, int a2, _DWORD *a3)
{
  _DWORD *v3; // edx
  int v4; // eax
  unsigned __int8 v5; // cf
  int v6; // eax
  int v7; // eax
  int result; // eax
  int v9; // [esp+Ch] [ebp-4h]

  v3 = this;
  v3[1] += a3[4];
  *v3 += a3[12];
  v3[2] += a3[20];
  v4 = a3[14];
  v5 = __CFADD__(v4, this[6]);
  v3[6] += v4;
  v3[7] += a3[15] + v5;
  v6 = a3[6];
  v5 = __CFADD__(v6, this[8]);
  v3[8] += v6;
  v3[9] += a3[7] + v5;
  v7 = a3[22];
  v5 = __CFADD__(v7, this[10]);
  v3[10] += v7;
  v3[11] += a3[23] + v5;
  v9 = a3[15];
  result = (*(v3 + 9) + *(v3 + 11) + *(v3 + 10)) >> 32;
  if ( *(a3 + 7) + *(a3 + 11) + *(a3 + 3) > *(v3 + 9) + *(v3 + 11) + *(v3 + 10) )
  {
    this[18] = a3[14];
    this[19] = v9;
    this[20] = a3[6];
    this[21] = a3[7];
    this[22] = a3[22];
    this[23] = a3[23];
    result = a2;
    this[24] = a2;
  }
  return result;
}

//----- (00FB4870) --------------------------------------------------------
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
// 103CB88: using guessed type wchar_t aCpugraphclassc[19];
// 106A388: using guessed type char gbHide;
// 106A389: using guessed type char gbMainWndMinimized;

//----- (00FB4B90) --------------------------------------------------------
int wsprintf(wchar_t *Dst, wchar_t *Format, ...)
{
  va_list ArgList; // [esp+10h] [ebp+10h]

  va_start(ArgList, Format);
  return vswprintf_s(Dst, 0x100u, Format, ArgList);
}

//----- (00FB4BB0) --------------------------------------------------------
int MakeHandlePropSheetCaption(wchar_t *Dst, wchar_t *Format, ...)
{
  va_list ArgList; // [esp+10h] [ebp+10h]

  va_start(ArgList, Format);
  return vswprintf_s(Dst, 0x208u, Format, ArgList);
}

//----- (00FB4BD0) --------------------------------------------------------
CString *__thiscall ATL::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>(CString *this, LPCSTR lpMultiByteStr)
{
  CString *v2; // esi
  IAtlStringMgr *v3; // ecx
  CHAR *v4; // eax

  v2 = this;
  v3 = ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>::GetDefaultManager();
  if ( !v3 )
    ATL::AtlThrowImpl(-2147467259);
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

//----- (00FB4C70) --------------------------------------------------------
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

//----- (00FB4D00) --------------------------------------------------------
int __stdcall sub_FB4D00(HDC hdc, wchar_t *Src, rsize_t SizeInWords, int a4)
{
  HANDLE v4; // eax
  wchar_t *v5; // eax
  unsigned __int16 *v6; // edi
  int v7; // esi
  HANDLE v8; // eax
  unsigned int v10; // ecx
  rsize_t v11; // esi
  HANDLE v12; // eax
  struct tagSIZE v13; // [esp+Ch] [ebp-20h]
  struct tagSIZE v14; // [esp+14h] [ebp-18h]
  struct tagSIZE v15; // [esp+1Ch] [ebp-10h]
  struct tagSIZE psizl; // [esp+24h] [ebp-8h]
  unsigned int v17; // [esp+40h] [ebp+14h]

  v17 = a4 - 4;
  v4 = GetProcessHeap();
  v5 = HeapAlloc(v4, 8u, 2 * SizeInWords);
  v6 = v5;
  if ( !v5 )
    return 0;
  wcscpy_s(v5, SizeInWords, Src);
  v7 = wcslen(v6);
  if ( !GetTextExtentPoint32W(hdc, v6, v7, &psizl) )
  {
LABEL_3:
    v8 = GetProcessHeap();
    HeapFree(v8, 0, v6);
    return 0;
  }
  if ( psizl.cx > v17 )
  {
    if ( !GetTextExtentPoint32W(hdc, L"...", wcslen(L"..."), &v15)
      || !GetTextExtentPoint32W(hdc, L"..", wcslen(L".."), &v14)
      || !GetTextExtentPoint32W(hdc, L".", wcslen(L"."), &v13) )
    {
      goto LABEL_3;
    }
    if ( v7 > 0 )
    {
      while ( 1 )
      {
        v6[--v7] = 0;
        if ( !GetTextExtentPoint32W(hdc, v6, v7, &psizl) )
          goto LABEL_3;
        v10 = v17;
        if ( psizl.cx + v15.cx <= v17 || v7 <= 0 )
          goto LABEL_15;
      }
    }
    v10 = v17;
LABEL_15:
    *v6 = *Src;
    if ( psizl.cx + v15.cx > v10 )
    {
      if ( psizl.cx + v14.cx > v10 )
      {
        if ( psizl.cx + v13.cx > v10 )
        {
          v11 = SizeInWords;
          *v6 = *Src;
        }
        else
        {
          v11 = SizeInWords;
          wcscat_s(v6, SizeInWords, L".");
        }
      }
      else
      {
        v11 = SizeInWords;
        wcscat_s(v6, SizeInWords, L"..");
      }
    }
    else
    {
      v11 = SizeInWords;
      wcscat_s(v6, SizeInWords, L"...");
    }
    wcscpy_s(Src, v11, v6);
  }
  v12 = GetProcessHeap();
  HeapFree(v12, 0, v6);
  return 1;
}

//----- (00FB4EF0) --------------------------------------------------------
signed int __cdecl sub_FB4EF0(unsigned int *a1, _DWORD *a2)
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

//----- (00FB4F50) --------------------------------------------------------
char __cdecl sub_FB4F50(CRegSettings *pConfig, DWORD *pdwValue, unsigned int a3)
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
    v11 = ATL::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>(
            &pConfig,
            pdwValue_1 + 794);
    wcscpy_s(v4->strDbgHelpModuleName, 0x104u, *v11);
    v12 = &pConfig[-1].ToolBandInfo[6].fBreak;
    v7 = &pConfig[-1].ToolBandInfo[7].fBreak;
    if ( _InterlockedDecrement(v7) <= 0 )
      LOBYTE(v7) = (*(**v12 + 4))(v12);
    pdwValue_1 = pdwValue;
  }
  if ( v10 > 0x41F )
  {
    v13 = ATL::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>(
            &pConfig,
            pdwValue_1 + 0x41F);
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

//----- (00FB55D0) --------------------------------------------------------
BOOL __stdcall sub_FB55D0(HDC hdc, wchar_t *Src, RECT *lprect, int a4)
{
  signed int v4; // ecx
  int v5; // esi
  int v6; // eax
  WCHAR String; // [esp+Ch] [ebp-4004h]

  if ( wcslen(Src) > 0x1FFF )
  {
    wcsncpy_s(&String, 0x2000u, Src, 0xFFFFFFFF);
    __report_rangecheckfailure();
    __debugbreak();
    JUMPOUT(*sub_FB56D0);
  }
  wcscpy_s(&String, 0x2000u, Src);
  v4 = 2;
  if ( a4 )
    v4 = 8;
  sub_FB4D00(hdc, &String, 0x2000u, lprect->right - v4 - lprect->left);
  if ( a4 )
  {
    SetTextAlign(hdc, 2u);
    v5 = lprect->right - 10;
  }
  else
  {
    SetTextAlign(hdc, 0);
    v5 = lprect->left + 2;
  }
  v6 = lstrlenW(&String);
  return ExtTextOutW(hdc, v5, lprect->top + 1, 6u, lprect, &String, v6, 0);
}
// 10067E8: using guessed type int __report_rangecheckfailure(void);

//----- (00FB56D0) --------------------------------------------------------
char __cdecl sub_FB56D0(char a1, tagTREEVIEWLISTITEMPARAM *pTreeItem, WORD uID, HDC hDC, RECT *lprc)
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
      sub_FB1FD0(&pTreeItem->CreateTime, v12, v11, gConfig.ColorGraphBk);
      return 1;
    case IDS_PRIVATE_BYTES_HISTORY:
      v13 = GetSysColorBrush(5);
      v14 = lprc;
      FrameRect(hDC, lprc, v13);
      ++v14->top;
      --v14->right;
      if ( !pTreeItem->pGraphData2 )
        TreeViewItemParam_InitGraph(pTreeItem);
      v15 = qword_107BA40;
      GraphData_DrawChart(
        pTreeItem->pGraphData2,
        hDC,
        v14,
        gConfig.ColorGraphBk,
        1u,
        ((v15 * 0.2 + qword_107BA40) * 0.0009765625));
      return 1;
  }
  if ( uID != 1330 )
  {
    v20 = hDC;
    if ( uID == IDS_VIRUSTOTAL && sub_1001820(pTreeItem->m_ItemDataForVirusTotal) )
    {
      if ( sub_1002910(pTreeItem->m_ItemDataForVirusTotal) )
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
        v21 = *&pTreeItem->field_568 / 100.0;
        break;
      default:
        return 0;
    }
    if ( uID )
    {
      *&uID = sub_FB6210(v21, 130u, 230u);
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
// 103CDC0: using guessed type double db_onehundred;
// 107BA40: using guessed type __int64 qword_107BA40;

//----- (00FB5AD0) --------------------------------------------------------
errno_t __cdecl sub_FB5AD0(int a1, int a2, int a3, int a4, int a5, wchar_t *Dst, rsize_t SizeInWords)
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
// 103E04C: using guessed type wchar_t a001[7];
// 103E9C8: using guessed type double db_zeropointzerozerofive;

//----- (00FB5BB0) --------------------------------------------------------
LPCWSTR __cdecl sub_FB5BB0(wchar_t *Dst, __int64 a2)
{
  if ( *&a2 == 0.0 )
    return wcscpy_s(Dst, 0x104u, &gszNullString);
  if ( gConfig.bFormatIoBytes )
    return sub_FB2200(0, Dst, 0x104u, a2, 0i64, 0i64 >> 63);
  swprintf(Dst, L"%f", a2);
  return sub_FC3290(Dst, 0x104u);
}

//----- (00FB5C30) --------------------------------------------------------
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
// 106A11C: using guessed type int gdwRefreshCount;

//----- (00FB5E60) --------------------------------------------------------
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
// 106A8F8: using guessed type char gbBitmapOnRight;

//----- (00FB5F60) --------------------------------------------------------
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

//----- (00FB6090) --------------------------------------------------------
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

//----- (00FB6210) --------------------------------------------------------
unsigned __int16 __cdecl sub_FB6210(double a1, unsigned __int16 a2, unsigned __int16 a3)
{
  unsigned __int16 result; // ax

  if ( a1 == 0.0 )
    result = a3;
  else
    result = a3 - 5 * (((a3 - a2) * a1) / 5);
  return result;
}

//----- (00FB6270) --------------------------------------------------------
int __cdecl sub_FB6270(int a1, int a2)
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

  if ( !(dword_1069E5C & 1) )
  {
    dword_1069E5C |= 1u;
    v68 = 0;
    _bstr_t::_bstr_t(&::a2, L"\r\n");
    atexit(sub_102A910);
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
              v38 = _bstr_t::operator+(&v37->m_Data, &v59, &v62);
              LOBYTE(v68) = 43;
              v39 = _bstr_t::operator+(&v38->m_Data, &v60, v35);
              sub_F73A50(&v65, v39);
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
        qsort(v32, v31, 4u, sub_FC5A60);
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
    v45 = sub_FC4990(*(v2 + 68));
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
// 1069E5C: using guessed type int dword_1069E5C;

//----- (00FB6F30) --------------------------------------------------------
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
  ConfigItems[15].llValue = qword_103EA40;
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
// 103CB38: using guessed type double db_four;
// 103D414: using guessed type wchar_t aProcesscolumns[15];
// 103D434: using guessed type wchar_t aProcessimageco[24];
// 103D464: using guessed type wchar_t aHandlecolumns[14];
// 103D480: using guessed type wchar_t aDllcolumns[11];
// 103D4D8: using guessed type wchar_t aHandlesortcolu[17];
// 103D4FC: using guessed type wchar_t aHandlesortdire[20];
// 103D524: using guessed type wchar_t aDllsortcolumn[14];
// 103D540: using guessed type wchar_t aDllsortdirecti[17];
// 103D564: using guessed type wchar_t aProcesssortcol[18];
// 103D588: using guessed type wchar_t aProcesssortdir[21];
// 103D7D4: using guessed type wchar_t aShowprocesstre[16];
// 103D8BC: using guessed type wchar_t aPrcesscolumnco[18];
// 103D8E0: using guessed type wchar_t aProcesscolumnm[17];
// 103D904: using guessed type wchar_t aDllcolumncount[15];
// 103D924: using guessed type wchar_t aDllcolumnmap[13];
// 103D940: using guessed type wchar_t aHandlecolumnco[18];
// 103D964: using guessed type wchar_t aHandlecolumnma[16];
// 103DB90: using guessed type wchar_t aStatusbarcolum[17];
// 103DE18: using guessed type wchar_t aColumnsetname[14];
// 103E9E8: using guessed type double db_two;
// 103E9F0: using guessed type double db_six;
// 103E9F8: using guessed type double db_twenty21;
// 103EA00: using guessed type double db_twohundred;
// 103EA40: using guessed type __int64 qword_103EA40;

//----- (00FB73D0) --------------------------------------------------------
int __cdecl sub_FB73D0(HWND hWnd, char a2)
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

//----- (00FB74F0) --------------------------------------------------------
char __cdecl TreeView_InsertVerifyColumn(HWND hWnd, UINT uID, int *pnIDs, int pnLength)
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

//----- (00FB7790) --------------------------------------------------------
int __cdecl sub_FB7790(HWND hWnd, char a2)
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
  sub_1001C30(pItemParam_1, ~(pItemParam_1->field_2C >> 1) & 1, v5);
  return 1;
}
// 106A11C: using guessed type int gdwRefreshCount;

//----- (00FB78D0) --------------------------------------------------------
wchar_t *__cdecl sub_FB78D0(HWND a1, wchar_t *a2)
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

//----- (00FB7A90) --------------------------------------------------------
int sub_FB7A90(HWND hWnd, ...)
{
  _DWORD *v1; // esi
  int result; // eax
  LPARAM lParam; // [esp+8h] [ebp-10F8h]
  int v4; // [esp+Ch] [ebp-10F4h]
  int v5; // [esp+10h] [ebp-10F0h]
  int v6; // [esp+14h] [ebp-10ECh]
  int v7; // [esp+18h] [ebp-10E8h]
  int v8; // [esp+1Ch] [ebp-10E4h]
  int v9; // [esp+24h] [ebp-10DCh]
  _DWORD *v10; // [esp+28h] [ebp-10D8h]
  char v11; // [esp+3Ch] [ebp-10C4h]
  va_list va; // [esp+110Ch] [ebp+Ch]

  va_start(va, hWnd);
  memmove_0(&v11, va, 0x10C0u);
  memset(&v4, 0, 0x30u);
  lParam = 13;
  v4 = 0x7FFFFFFF;
  v5 = 0;
  v6 = 0;
  v7 = 0;
  v8 = -1;
  v9 = 0;
  v1 = malloc(0x10C0u);
  if ( !v1 )
    return 0;
  memmove_0(v1, &v11, 0x10C0u);
  v1[1] = 2;
  v1[2] = gdwRefreshCount + 1;
  v10 = v1;
  if ( SendMessageW(hWnd, 0x104Du, 0, &lParam) == -1 )
    return 0;
  v1[1071] = 0;
  v1[1070] = dword_106539C;
  if ( dword_106539C )
    *(dword_106539C + 4284) = v1;
  result = 1;
  dword_106539C = v1;
  return result;
}
// 106A11C: using guessed type int gdwRefreshCount;

//----- (00FB7BC0) --------------------------------------------------------
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
      || (!sub_FC50E0(pItemParam_1->szProcessName2) ? (pItemParam_1->dwStyle &= -2u) : (pItemParam_1->dwStyle |= 1u),
          pItemParam_1->dwStyle & 1 && gConfig.byte_14012ADFE) )
    {
      SendMessageW = ::SendMessageW;
    }
    else
    {
      sub_FB7F20(hWnd, pItemParam_1);
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
// 106A11C: using guessed type int gdwRefreshCount;

//----- (00FB7DD0) --------------------------------------------------------
char *__cdecl sub_FB7DD0(HWND hWnd, char a2)
{
  char *result; // eax
  char *v3; // ebx
  LPARAM lParam; // [esp+4h] [ebp-34h]
  int v5; // [esp+8h] [ebp-30h]
  int v6; // [esp+Ch] [ebp-2Ch]
  int v7; // [esp+10h] [ebp-28h]
  int v8; // [esp+14h] [ebp-24h]
  int v9; // [esp+18h] [ebp-20h]
  int v10; // [esp+20h] [ebp-18h]
  char *v11; // [esp+24h] [ebp-14h]

  memset(&v5, 0, 0x30u);
  lParam = 13;
  v5 = 0x7FFFFFFF;
  v6 = 0;
  v7 = 0;
  v8 = 0;
  v9 = -1;
  v10 = 0;
  v11 = 0;
  result = malloc(0x890u);
  v3 = result;
  if ( result )
  {
    qmemcpy(result, &a2, 0x890u);
    v11 = result;
    if ( SendMessageW(hWnd, 0x104Du, 0, &lParam) == -1 )
      v3 = 0;
    result = v3;
  }
  return result;
}

//----- (00FB7E70) --------------------------------------------------------
int __cdecl sub_FB7E70(HWND hWnd, char a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, int a19, int a20, int a21, int a22, int a23, int a24, int a25, int a26, int a27, int a28, int a29, int a30, int a31, int a32, int a33, int a34, int a35, int a36, int a37, int a38, int a39, int a40, int a41, int a42, int a43, int a44, int a45, int a46, int a47, int a48, int a49, int a50, int a51, int a52, int a53, int a54, int a55, int a56, int a57, int a58, int a59, int a60, int a61, int a62, int a63)
{
  int result; // eax
  _DWORD *v66; // ecx
  LPARAM lParam; // [esp+0h] [ebp-34h]
  int v68; // [esp+4h] [ebp-30h]
  int v69; // [esp+8h] [ebp-2Ch]
  int v70; // [esp+Ch] [ebp-28h]
  int v71; // [esp+10h] [ebp-24h]
  int v72; // [esp+14h] [ebp-20h]
  int v73; // [esp+1Ch] [ebp-18h]
  int v74; // [esp+20h] [ebp-14h]

  memset(&v68, 0, 0x30u);
  lParam = 13;
  v68 = 0x7FFFFFFF;
  v69 = 0;
  v70 = 0;
  v71 = 0;
  v72 = -1;
  v73 = 0;
  v74 = 0;
  result = malloc(0x290u);
  if ( result )
  {
    qmemcpy(result, &a2, 0x290u);
    v66 = a65;
    v74 = result;
    *(result + 652) = *a65;
    *v66 = result;
    result = SendMessageW(hWnd, 0x104Du, 0, &lParam) != -1;
  }
  return result;
}
// FB7E70: too many input arguments, some ignored

//----- (00FB7F20) --------------------------------------------------------
int __cdecl sub_FB7F20(HWND hWnd, tagTREEVIEWLISTITEMPARAM *pItemParam)
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
          v4 = sub_FB7F20(hWnd, pItemParam->pItemParam);
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
    v11 = sub_FC1AF0;
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
          sub_FB7F20(hWnd, pItemParam->pItemParam);
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

//----- (00FB8070) --------------------------------------------------------
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
    pItem->pGraphData6 = v8;
    v8->m_nItemID = 5;
    pItem->pGraphData6->m_Color = 0xAAAA;
    pItem->pGraphData6->m_dbMemorySize = db_one;
    v9 = InitGraphData(1, 1, 0);
    pItem->pGraphData7 = v9;
    v9->m_nItemID = 6;
    pItem->pGraphData7->m_Color = 0x4080FF;
    pItem->pGraphData7->m_dbMemorySize = db_one;
  }
}
// 103CDC0: using guessed type double db_onehundred;

//----- (00FB82A0) --------------------------------------------------------
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

//----- (00FB8300) --------------------------------------------------------
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
  if ( !CTreeView::InitListHeader(v6, a3, a4, dwNewLong) )
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

//----- (00FB8460) --------------------------------------------------------
void __cdecl sub_FB8460(tagTREEVIEWLISTITEMPARAM *a1)
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
  byte_10653B5 = 1;
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
// 10653B5: using guessed type char byte_10653B5;

//----- (00FB8570) --------------------------------------------------------
LRESULT __cdecl sub_FB8570(HWND hWnd, int a2)
{
  LRESULT result; // eax
  LPARAM lParam; // [esp+Ch] [ebp-18h]
  int v4; // [esp+14h] [ebp-10h]

  lParam = 1;
  v4 = a2;
  result = SendMessageW(hWnd, 0x1053u, 0xFFFFFFFF, &lParam);
  if ( result >= 0 )
  {
    SendMessageW(hWnd, 0x1008u, result, 0);
    result = *(a2 + 84);
    if ( result )
    {
      if ( *(result + 48) )
      {
        result = *(result + 1464);
        if ( result )
        {
          result = SendMessageW(hWnd, 0x2002u, result, 0);
          if ( !result )
          {
            SendMessageW(hWnd, 0x2000u, *(*(a2 + 84) + 1464), 1);
            result = SendMessageW(hWnd, 0x2003u, *(*(a2 + 84) + 1464), 0);
          }
        }
      }
    }
  }
  return result;
}

//----- (00FB8600) --------------------------------------------------------
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

//----- (00FB8690) --------------------------------------------------------
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
    if ( a1->field_314 )
      free(a1->field_314);
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
    if ( a1->field_354 )
      free(a1->field_354);
    if ( a1->field_358 )
      free(a1->field_358);
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
      sub_10039A0(&a1->bSupportWMIProviders);
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

//----- (00FB88B0) --------------------------------------------------------
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
    return sub_FB56D0(
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
          if ( sub_1001820(*(v19 + 364)) )
          {
            if ( sub_1002910(*(v19 + 364)) )
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
      sub_FB55D0(pDrawItemStruct->hDC, &Src, &rect, ColumnInfo.fmt & 1);
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
    if ( rect.top != dword_106A338 )
    {
      dword_106A338 = rect.top;
      InvalidateRect(ghWndTreeListView, 0, 0);
    }
  }
  return 1;
}
// 103EA50: using guessed type RECT gIntArray;
// 106A338: using guessed type int dword_106A338;

//----- (00FB8D00) --------------------------------------------------------
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

//----- (00FB8DA0) --------------------------------------------------------
BOOL __cdecl sub_FB8DA0(tagTREEVIEWLISTITEMPARAM *pItemParam)
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
  byte_10653B5 = 1;
  return SetEvent(ghTimerRefreshEvent);
}
// 10653B5: using guessed type char byte_10653B5;

//----- (00FB8E30) --------------------------------------------------------
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

//----- (00FB9300) --------------------------------------------------------
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
    gConfig.dwProcessColumns[index] = MulDiv(word_105D1F2[2 * index], v2, 96);
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
            sub_FB4F50(&gConfig, dwValue, KeyInfo.nLength);
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
