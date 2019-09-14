//----- (01057400) --------------------------------------------------------
void __cdecl sub_1057400(signed __int64 a1, double *a2, double *a3, double *a4)
{
  double v4; // xmm0_8
  double v5; // xmm1_8
  double v6; // xmm3_8
  DWORD v7; // ecx
  double dbMemorySize; // xmm4_8
  double v9; // xmm5_8
  double v10; // xmm1_8
  double v11; // xmm1_8
  struct _FILETIME SystemTimeAsFileTime; // [esp+28h] [ebp-84h]
  double v13; // [esp+30h] [ebp-7Ch]
  double v14; // [esp+38h] [ebp-74h]
  double v15; // [esp+40h] [ebp-6Ch]
  int v16; // [esp+48h] [ebp-64h]
  __int64 v17; // [esp+50h] [ebp-5Ch]
  __int64 v18; // [esp+58h] [ebp-54h]
  __int64 v19; // [esp+60h] [ebp-4Ch]
  __int64 v20; // [esp+68h] [ebp-44h]
  struct _MEMORYSTATUS Buffer; // [esp+88h] [ebp-24h]

  v13 = 0.0;
  Buffer.dwLength = 32;
  GlobalMemoryStatus(&Buffer);
  GetSystemTimeAsFileTime(&SystemTimeAsFileTime);
  if ( GlobalMemoryStatusEx )
  {
    v16 = 64;
    GlobalMemoryStatusEx(&v16);
    if ( a1 )
    {
      v14 = a1;
      v15 = a1 / v19 * 100.0;
      goto LABEL_11;
    }
    gpGraphInfoOfMemory->m_dbMemorySize = v19 * 0.0009765625;
    gpGraphInfoOfPhysicalMemory->m_dbMemorySize = v17 * 0.0009765625;
    v14 = (v17 - v18) * 0.0009765625;
    v13 = (v19 - v20);
    v15 = v13 * 100.0;
    v4 = v19;
    v5 = v13 * 100.0;
    v6 = v13 * 0.0009765625;
    v7 = Buffer.dwTotalPageFile;
    dbMemorySize = (v17 - v18) * 0.0009765625;
    v9 = db_onehundred;
  }
  else
  {
    if ( a1 )
    {
      v15 = a1 / Buffer.dwTotalPageFile * 100.0;
      goto LABEL_11;
    }
    v9 = db_onehundred;
    gpGraphInfoOfMemory->m_dbMemorySize = Buffer.dwTotalPageFile * 0.0009765625;
    gpGraphInfoOfPhysicalMemory->m_dbMemorySize = Buffer.dwTotalPhys * 0.0009765625;
    v7 = Buffer.dwTotalPageFile;
    dbMemorySize = (Buffer.dwTotalPhys - Buffer.dwAvailPhys) * 0.0009765625;
    v14 = (Buffer.dwTotalPhys - Buffer.dwAvailPhys) * 0.0009765625;
    v10 = (Buffer.dwTotalPageFile - Buffer.dwAvailPageFile);
    v6 = v10 * 0.0009765625;
    v4 = Buffer.dwTotalPageFile;
    v5 = v10 * 100.0;
  }
  v13 = v6;
  v15 = v5 / v4;
  if ( v6 < 0.0 )
  {
    v15 = v9;
    v13 = (v7 >> 10);
  }
  CGraphData_Update(gpGraphInfoOfPhysicalMemory, SystemTimeAsFileTime, dbMemorySize, 0.0, 0);
  CGraphData_Update(gpGraphInfoOfMemory, SystemTimeAsFileTime, v13, 0.0, 0);
LABEL_11:
  v11 = v14;
  if ( a2 )
    *a2 = v13;
  if ( a3 )
    *a3 = v11;
  if ( a4 )
    *a4 = gpGraphInfoOfPhysicalMemory->m_dbMemorySize;
}
// 109CDC0: using guessed type double db_onehundred;
// 10CF2E8: using guessed type int (__stdcall *GlobalMemoryStatusEx)(_DWORD);

//----- (01057720) --------------------------------------------------------
int __cdecl sub_1057720(int a1, wchar_t *Dst, rsize_t SizeInWords)
{
  int v3; // eax
  int result; // eax
  int v5; // [esp+8h] [ebp+8h]

  v3 = *(a1 + 636);
  v5 = v3;
  if ( v3 == -1 )
    return wcscpy_s(Dst, SizeInWords, L"n/a");
  if ( v3 & 1 )
    result = wcscpy_s(Dst, SizeInWords, L"Enabled");
  else
    result = wcscpy_s(Dst, SizeInWords, L"Disabled");
  if ( v5 & 8 )
    result = wcscat_s(Dst, SizeInWords, L" (permanent)");
  return result;
}

//----- (01057790) --------------------------------------------------------
int __cdecl sub_1057790(int a1, wchar_t *Dst, size_t SizeInWords)
{
  int result; // eax

  if ( a1 == -1 )
    return swprintf_s(Dst, SizeInWords, &gszNullString);
  switch ( a1 )
  {
    case 0:
      result = swprintf_s(Dst, SizeInWords, L"Very Low");
      break;
    case 1:
      result = swprintf_s(Dst, SizeInWords, L"Low");
      break;
    case 2:
      result = swprintf_s(Dst, SizeInWords, L"Normal");
      break;
    case 3:
      result = swprintf_s(Dst, SizeInWords, L"High");
      break;
    case 4:
      result = swprintf_s(Dst, SizeInWords, L"Critical");
      break;
    default:
      result = swprintf_s(Dst, SizeInWords, L"%d", a1);
      break;
  }
  return result;
}

//----- (01057850) --------------------------------------------------------
void *__cdecl QuerySystemHandleInfo(ULONG ReturnLength)
{
  int v1; // eax
  ULONG v2; // esi
  SYSTEM_HANDLE_INFORMATION *v3; // eax
  _SYSTEM_INFORMATION_CLASS v4; // eax
  void *result; // eax
  ULONG v6; // esi
  SYSTEM_HANDLE_INFORMATION *v7; // eax
  _SYSTEM_INFORMATION_CLASS v8; // eax
  size_t v9; // esi
  ULONG v10; // esi
  SYSTEM_HANDLE_INFORMATION *v11; // eax
  _SYSTEM_INFORMATION_CLASS ClassInfo; // eax
  size_t v13; // esi
  _SYSTEM_INFORMATION_CLASS v14; // eax
  SYSTEM_HANDLE_INFORMATION *v15; // [esp-Ch] [ebp-14h]
  SYSTEM_HANDLE_INFORMATION *v16; // [esp-Ch] [ebp-14h]
  SYSTEM_HANDLE_INFORMATION *v17; // [esp-Ch] [ebp-14h]

  if ( ReturnLength )
  {
    if ( gpSystemHandleInfo )
      free(gpSystemHandleInfo);
    v10 = gdwSystemHandleInfoLength;
    v11 = malloc(gdwSystemHandleInfoLength);
    gpSystemHandleInfo = v11;
    v17 = v11;
    ClassInfo = SystemHandleInformation;
    if ( gbSupportExtendedSystemHandleInformation )
      ClassInfo = SystemExtendedHandleInformation;
    result = NtQuerySystemInformation(ClassInfo, v17, v10, &ReturnLength);
    if ( result )
    {
      while ( result != STATUS_ACCESS_DENIED )
      {
        free(gpSystemHandleInfo);
        gdwSystemHandleInfoLength *= 2;
        v13 = gdwSystemHandleInfoLength;
        gpSystemHandleInfo = malloc(gdwSystemHandleInfoLength);
        memset(gpSystemHandleInfo, 0, v13);
        v14 = 16;
        if ( gbSupportExtendedSystemHandleInformation )
          v14 = SystemExtendedHandleInformation;
        result = NtQuerySystemInformation(v14, gpSystemHandleInfo, v13, &ReturnLength);
        if ( !result )
          return result;
      }
      result = memset(gpSystemHandleInfo, 0, gdwSystemHandleInfoLength);
    }
  }
  else
  {
    if ( gpSystemHandleInfo3 )
      free(gpSystemHandleInfo3);
    v1 = gdwProcessIdSelected;
    gpSystemHandleInfo3 = 0;
    if ( gdwValue_4F10B8[2] == gdwProcessIdSelected )
    {
      gpSystemHandleInfo3 = gpSystemHandleInfo2;
    }
    else
    {
      if ( gpSystemHandleInfo2 )
      {
        free(gpSystemHandleInfo2);
        v1 = gdwProcessIdSelected;
      }
      gdwValue_4F10B8[2] = v1;
    }
    v2 = gdwSystemHandleInfoLength;
    v3 = malloc(gdwSystemHandleInfoLength);
    gpSystemHandleInfo2 = v3;
    v15 = v3;
    v4 = SystemHandleInformation;
    if ( gbSupportExtendedSystemHandleInformation )
      v4 = SystemExtendedHandleInformation;
    result = NtQuerySystemInformation(v4, v15, v2, &ReturnLength);
    if ( result )
    {
      while ( result != STATUS_ACCESS_DENIED )
      {
        if ( result == STATUS_INSUFFICIENT_RESOURCES )
        {
          MessageBoxW(
            NULL,
            L"Insufficient system resources to get handle information.",
            L"Process Explorer",
            MB_ICONERROR);
          v9 = gdwSystemHandleInfoLength;
          memset(gpSystemHandleInfo2, 0, gdwSystemHandleInfoLength);
          return memset(gpSystemHandleInfo2, 0, v9);
        }
        free(gpSystemHandleInfo2);
        gdwSystemHandleInfoLength *= 2;
        v6 = gdwSystemHandleInfoLength;
        v7 = malloc(gdwSystemHandleInfoLength);
        gpSystemHandleInfo2 = v7;
        v16 = v7;
        v8 = 16;
        if ( gbSupportExtendedSystemHandleInformation )
          v8 = SystemExtendedHandleInformation;
        result = NtQuerySystemInformation(v8, v16, v6, &ReturnLength);
        if ( !result )
          return result;
      }
      result = memset(gpSystemHandleInfo2, 0, gdwSystemHandleInfoLength);
    }
  }
  return result;
}
// 10C10B8: using guessed type int gdwValue_4F10B8[3];
// 10CABA5: using guessed type char gbSupportExtendedSystemHandleInformation;

//----- (01057A70) --------------------------------------------------------
signed int OnBeforeInit()
{
  int v0; // eax
  HMODULE v1; // eax
  int dwNumberOfProcessors; // esi
  signed int result; // eax
  int Status; // eax
  HMODULE v5; // eax
  HMODULE v6; // eax
  HMODULE v7; // eax
  char v8; // cl
  HMODULE v9; // eax
  HMODULE v10; // eax
  HMODULE v11; // eax
  HMODULE v12; // eax
  unsigned int nIndex; // edx
  RegItem *pItem; // ecx
  __int16 v15; // ax
  unsigned int nIndex_1; // edx
  RegItem *v17; // ecx
  __int16 v18; // ax
  double dwTotalPageFile; // xmm0_8
  void (__stdcall *GlobalMemoryStatusEx)(LPMEMORYSTATUS); // esi
  CGraphData *v21; // eax
  DWORD dwVersion; // [esp+10h] [ebp-80h]
  _MEMORYSTATUSEX MemoryStatusEx; // [esp+14h] [ebp-7Ch]
  struct _MEMORYSTATUS MemoryStatus; // [esp+54h] [ebp-3Ch]
  CPPEH_RECORD ms_exc; // [esp+78h] [ebp-18h]

  dwVersion = 152;
  ghMainInstance = ghInstance;
  v0 = GetSystemMetrics(SM_CXVIRTUALSCREEN);
  gdwVirtualScreenWidth = v0;
  if ( !v0 )
    v0 = GetSystemMetrics(SM_CXSCREEN);
  gdwVirtualScreenWidth = v0 / 2;
  v1 = GetModuleHandleW(L"kernel32.dll");
  *GetLongPathNameW = GetProcAddress(v1, "GetLongPathNameW");
  dwNumberOfProcessors = gSystemInfo.dwNumberOfProcessors;
  gpSystemPerformanceInfo = malloc(sizeof(SYSTEM_PROCESSOR_PERFORMANCE_INFORMATION) * gSystemInfo.dwNumberOfProcessors);
  gpSystemInterruptInfo = malloc(sizeof(SYSTEM_INTERRUPT_INFORMATION) * dwNumberOfProcessors);
  gpSystemProcessorCycleTimeInfo = malloc(8 * dwNumberOfProcessors);
  TmAdjustPrivilege(L"SeDebugPrivilege");
  TmAdjustPrivilege(L"SeBackupPrivilege");
  TmAdjustPrivilege(L"SeSecurityPrivilege");
  if ( !CDriver::Load() )
    goto LABEL_7;
  dwNumberOfProcessors = VirtualAlloc(NULL, 4u, MEM_COMMIT, PAGE_READWRITE);
  ms_exc.registration.TryLevel = 0;
  if ( !CDriver::Control(0x83350008, &dwVersion, 4u, dwNumberOfProcessors, 4u) || *dwNumberOfProcessors < dwVersion )
  {
    CDriver::Close();
    if ( CDriver::Load() )
    {
      if ( CDriver::Control(0x83350008, &dwVersion, 4u, dwNumberOfProcessors, 4u) && *dwNumberOfProcessors >= dwVersion )
        goto LABEL_16;
      MessageBoxW(
        0,
        L"Driver version mismatch. You must reboot before you can run this version of Process Explorer.",
        L"Process Explorer",
        MB_ICONERROR);
    }
    CDriver::Close();
LABEL_16:
    ms_exc.registration.TryLevel = -2;
    return 0;
  }
  ms_exc.registration.TryLevel = -2;
  VirtualFree(dwNumberOfProcessors, 4u, MEM_DECOMMIT);
LABEL_7:
  if ( LoadSystemApis() )
  {
    Status = NtQuerySystemInformation(SystemExtendedHandleInformation, 0, 0, 0);
    if ( Status == STATUS_INVALID_INFO_CLASS
      || (gbSupportExtendedSystemHandleInformation = 1, Status == STATUS_NOT_IMPLEMENTED) )
    {
      gbSupportExtendedSystemHandleInformation = 0;
    }
    ghSCManagerHandle = OpenSCManagerW(NULL, NULL, SC_MANAGER_ENUMERATE_SERVICE);
    *EnumServicesStatusExW = 0;
    if ( ghSCManagerHandle )
    {
      v5 = GetModuleHandleW(L"advapi32.dll");
      *EnumServicesStatusExW = GetProcAddress(v5, "EnumServicesStatusExW");
      v6 = GetModuleHandleW(L"advapi32.dll");
      *QueryServiceConfig2W = GetProcAddress(v6, "QueryServiceConfig2W");
    }
    if ( IsWinServer(GetModuleHandleW, dwNumberOfProcessors) )
    {
      v7 = GetModuleHandleW(L"kernel32.dll");
      gpfnProcessIdToSessionId = GetProcAddress(v7, "ProcessIdToSessionId");
      v8 = gbProcessIdToSessionIdValid;
      if ( gpfnProcessIdToSessionId )
        v8 = 1;
      gbProcessIdToSessionIdValid = v8;
    }
    v9 = LoadLibraryW(L"winsta.dll");
    WinStationGetProcessSid = GetProcAddress(v9, "WinStationGetProcessSid");
    v10 = GetModuleHandleW(L"kernel32.dll");
    *IsProcessInJob = GetProcAddress(v10, "IsProcessInJob");
    v11 = GetModuleHandleW(L"kernel32.dll");
    *QueryInformationJobObject = GetProcAddress(v11, "QueryInformationJobObject");
    v12 = GetModuleHandleW(L"kernel32.dll");
    *SetProcessAffinityMask = GetProcAddress(v12, "SetProcessAffinityMask");
    InitializeCriticalSection(&gServiceLock);
    GetDriverNameAndLinkInfo();
    nIndex = 0;
    do
    {
      pItem = &stru_10C0320[nIndex + 2];
      do
      {
        v15 = pItem->field_0;
        pItem = (pItem + 2);
      }
      while ( v15 );
      stru_10C0320[nIndex + 2].field_240 = (pItem - (&stru_10C0320[nIndex + 2].field_0 + 2)) >> 1;
      ++nIndex;
    }
    while ( nIndex < 4 );
    nIndex_1 = 0;
    do
    {
      v17 = &stru_10C0320[nIndex_1];
      do
      {
        v18 = v17->field_0;
        v17 = (v17 + 2);
      }
      while ( v18 );
      stru_10C0320[nIndex_1].field_240 = (v17 - (&stru_10C0320[nIndex_1].field_0 + 2)) >> 1;
      ++nIndex_1;
    }
    while ( nIndex_1 < 2 );
    LoadNetClrMemoryPerformanceInfo();
    if ( gdwVersion >= 1 )
      QueryTagInformationEx(&ppv, 0, &pdwValue3, &pdwValue4);
    gpGraphInfoOfCPU = InitGraphData(1, 2, 1);
    gpGraphInfoOfCPU->m_nItemID = 0;
    gpGraphInfoOfCPU->m_Color = 0x3C943C;
    gpGraphInfoOfCPU->m_dbMemorySize = db_onehundred;
    if ( gpGraphInfoOfCPU->m_nChildID == 2 )
    {
      gpGraphInfoOfCPU->m_Item[0].Color = 255;
      gpGraphInfoOfCPU->m_Item[0].dbMemorySize = db_onehundred;
    }
    gpGraphInfoOfMemory = InitGraphData(1, 1, 0);
    gpGraphInfoOfMemory->m_nItemID = 1;
    gpGraphInfoOfMemory->m_Color = 0xAAAA;
    if ( ::GlobalMemoryStatusEx )
    {
      MemoryStatusEx.dwLength = 64;
      ::GlobalMemoryStatusEx(&MemoryStatusEx);
      dwTotalPageFile = MemoryStatusEx.ullTotalPageFile;
      GlobalMemoryStatusEx = GlobalMemoryStatus;
    }
    else
    {
      MemoryStatus.dwLength = sizeof(_MEMORYSTATUS);
      GlobalMemoryStatusEx = GlobalMemoryStatus;
      GlobalMemoryStatus(&MemoryStatus);
      dwTotalPageFile = MemoryStatus.dwTotalPageFile;
    }
    gpGraphInfoOfMemory->m_dbMemorySize = dwTotalPageFile * 0.0009765625;
    MemoryStatus.dwLength = 32;
    GlobalMemoryStatusEx(&MemoryStatus);
    v21 = InitGraphData(2, 1, 0);
    gpGraphInfoOfPhysicalMemory = v21;
    v21->m_nItemID = 3;
    gpGraphInfoOfPhysicalMemory->m_Color = 0x4080FF;
    gpGraphInfoOfPhysicalMemory->m_dbMemorySize = MemoryStatus.dwTotalPhys;
    GraphInfo_Init(&gIOGraphInfo);
    GraphInfo_Init(&gNetworkGraphInfo);
    GraphInfo_Init(&gDiskGraphInfo);
    sub_103E920();
    result = 1;
  }
  else
  {
    if ( ghDriverHandle != -1 )
      CloseHandle(ghDriverHandle);
    result = 0;
  }
  return result;
}
// 109CDC0: using guessed type double db_onehundred;
// 10C0320: using guessed type RegItem stru_10C0320[4];
// 10C4E28: using guessed type int gdwVirtualScreenWidth;
// 10C4E54: using guessed type int gdwVersion;
// 10CA38A: using guessed type char gbProcessIdToSessionIdValid;
// 10CABA5: using guessed type char gbSupportExtendedSystemHandleInformation;
// 10CF280: using guessed type int (__stdcall *gpfnProcessIdToSessionId)(_DWORD, _DWORD);
// 10CF2E8: using guessed type int (__stdcall *GlobalMemoryStatusEx)(_DWORD);

//----- (01057F90) --------------------------------------------------------
LRESULT __cdecl sub_1057F90(HWND hWnd, int a2, int a3)
{
  LRESULT result; // eax
  LPARAM lParam; // [esp+0h] [ebp-34h]
  LRESULT v5; // [esp+4h] [ebp-30h]
  int v6; // [esp+8h] [ebp-2Ch]
  int v7; // [esp+Ch] [ebp-28h]
  int v8; // [esp+10h] [ebp-24h]
  int v9; // [esp+14h] [ebp-20h]
  int v10; // [esp+1Ch] [ebp-18h]
  int v11; // [esp+20h] [ebp-14h]

  memset(&v5, 0, 0x30u);
  v9 = a2;
  lParam = 5;
  v5 = 0x7FFFFFFF;
  v6 = 0;
  v8 = 0;
  v7 = 0;
  v10 = 0;
  v11 = 1;
  result = SendMessageW(hWnd, 0x104Du, 0, &lParam);
  if ( result != -1 )
  {
    v5 = result;
    v9 = a3;
    lParam = 1;
    v6 = 1;
    result = SendMessageW(hWnd, 0x104Cu, 0, &lParam);
  }
  return result;
}

//----- (01058030) --------------------------------------------------------
char __cdecl sub_1058030(int ArgList, DWORD dwProcessId)
{
  char result; // al
  HANDLE v3; // eax
  void *v4; // esi
  WCHAR Text; // [esp+4h] [ebp-804h]

  if ( gConfig.bConfirmKill
    && (wsprintfW(&Text, L"Are you sure you want to kill %s?", ArgList),
        MessageBoxW(ghMainWnd, &Text, L"Process Explorer", 0x31u) == 2) )
  {
    SetFocus(ghWndTreeListView);
    result = 0;
  }
  else
  {
    v3 = OpenProcess(1u, 0, dwProcessId);
    v4 = v3;
    if ( v3 )
    {
      if ( TerminateProcess(v3, 1u) )
      {
        CloseHandle(v4);
        Sleep(0xFAu);
        result = 1;
      }
      else
      {
        ReportMsg(L"Error terminating process", ghMainWnd);
        CloseHandle(v4);
        result = 0;
      }
    }
    else
    {
      ReportMsg(L"Error opening process", ghMainWnd);
      result = 0;
    }
  }
  return result;
}
// 10A2088: using guessed type wchar_t aErrorOpeningPr[22];
// 10A2C34: using guessed type wchar_t aErrorTerminati[26];

//----- (01058140) --------------------------------------------------------
void __cdecl sub_1058140(int ArgList, int a2)
{
  tagTREEVIEWLISTITEMPARAM *i; // esi
  tagTREEVIEWLISTITEMPARAM *v3; // eax
  HANDLE v4; // eax
  void *v5; // edi
  HWND v6; // edi
  DWORD v7; // eax
  WCHAR Buffer[2]; // [esp+0h] [ebp-A08h]
  WCHAR Text; // [esp+4h] [ebp-A04h]
  WCHAR Dst; // [esp+804h] [ebp-204h]

  if ( gConfig.bConfirmKill
    && (wsprintfW(&Text, L"Are you sure you want to kill %s and its descendants?", ArgList),
        MessageBoxW(ghMainWnd, &Text, L"Process Explorer", 0x31u) == 2) )
  {
    SetFocus(ghWndTreeListView);
  }
  else
  {
    for ( i = gpTreeViewListItemParam; i; i = i->m_Prev )
    {
      v3 = i;
      if ( i )
      {
        while ( v3->dwProcessId != a2 )
        {
          v3 = v3->pItemParam;
          if ( !v3 )
            goto LABEL_17;
        }
        v4 = OpenProcess(1u, 0, i->dwProcessId);
        v5 = v4;
        if ( v4 )
        {
          if ( !TerminateProcess(v4, 1u) )
          {
            wsprintfW(&Text, L"Error terminating %s", i->szProcessName2);
            ReportMsg(&Text, ghMainWnd);
          }
          CloseHandle(v5);
        }
        else
        {
          wsprintfW(&Text, L"Error opening %s", i->szProcessName2);
          v6 = ghMainWnd;
          v7 = GetLastError();
          if ( v7 )
          {
            FormatMessageW(0x1100u, 0, v7, 0x400u, Buffer, 0, 0);
            wsprintf(&Dst, L"%s: %s", &Text, *Buffer);
            LocalFree(*Buffer);
          }
          else
          {
            wsprintf(&Dst, L"%s.", &Text);
          }
          MessageBoxW(v6, &Dst, L"Process Explorer", 0x10u);
        }
      }
LABEL_17:
      ;
    }
    Sleep(0xFAu);
  }
}

//----- (01058310) --------------------------------------------------------
int __cdecl SystemProcessInfo_GetSystemProcessName(DWORD dwProcessId, LARGE_INTEGER *FileTime, WCHAR *pszText, DWORD dwSize)
{
  int result; // eax
  SYSTEM_PROCESS_INFORMATION *i; // ecx

  if ( dwProcessId == -10 )
    return wcscpy_s(pszText, dwSize, L"Hardware Interrupts and DPCs");
  for ( i = gpSystemProcessInfo;
        dwProcessId != i->UniqueProcessId || FileTime && i->CreateTime.QuadPart > *FileTime;
        i = (i + i->NextEntryOffset) )
  {
    if ( !i->NextEntryOffset )
      return wcscpy_s(pszText, dwSize, L"<Non-existent Process>");
  }
  if ( i->ImageName.Length )
    result = wcsncpy_s(pszText, dwSize, i->ImageName.Buffer, i->ImageName.Length >> 1);
  else
    result = wcscpy_s(pszText, dwSize, L"System Idle Process");
  return result;
}

//----- (010583C0) --------------------------------------------------------
bool __cdecl QueryProcessUsers(HANDLE ProcessHandle, DWORD dwProcessId, int LowTime, wchar_t *pszUserName, DWORD cbUserName, WCHAR *szDomainName, DWORD cbDomainName, LPWSTR pszText, DWORD cbText, BOOL *pbVirtualizationEnabled, BOOL *pbUIAccess)
{
  BOOL Status; // eax
  BOOL (__stdcall *GetTokenInformation)(HANDLE, TOKEN_INFORMATION_CLASS, LPVOID, DWORD, PDWORD); // eax
  BOOL (__stdcall *GetTokenInformation_1)(HANDLE, TOKEN_INFORMATION_CLASS, LPVOID, DWORD, PDWORD); // ebx
  const wchar_t *v14; // eax
  FILETIME FileTime; // [esp+10h] [ebp-A24h]
  HANDLE ProcessHandle_1; // [esp+18h] [ebp-A1Ch]
  LPWSTR pszDomainName; // [esp+1Ch] [ebp-A18h]
  DWORD dwProcessId_1; // [esp+20h] [ebp-A14h]
  void *TokenHandle; // [esp+24h] [ebp-A10h]
  DWORD cbRet; // [esp+28h] [ebp-A0Ch]
  int fOK; // [esp+2Ch] [ebp-A08h]
  WCHAR ReferencedDomainName[256]; // [esp+30h] [ebp-A04h]
  char SidBuf[2048]; // [esp+230h] [ebp-804h]

  ProcessHandle_1 = ProcessHandle;
  dwProcessId_1 = dwProcessId;
  FileTime.dwLowDateTime = LowTime;
  pszDomainName = szDomainName;
  FileTime.dwHighDateTime = pbVirtualizationEnabled;
  TokenHandle = 0;
  HIBYTE(fOK) = 0;
  wcscpy_s(pszUserName, cbUserName, &gszNullString);
  wcscpy_s(szDomainName, cbDomainName, &gszNullString);
  LOBYTE(Status) = pbVirtualizationEnabled;
  if ( pbVirtualizationEnabled )
    *FileTime.dwHighDateTime = 0;
  if ( !WinStationGetProcessSid
    || (LOBYTE(Status) = FileTime.dwLowDateTime, !FileTime.dwLowDateTime)
    || (cbRet = 2048,
        LOBYTE(Status) = WinStationGetProcessSid(0, dwProcessId_1, *FileTime.dwLowDateTime, SidBuf, &cbRet),
        !Status) )
  {
LABEL_8:
    if ( !pszText )
      goto LABEL_10;
    goto LABEL_9;
  }
  LOBYTE(Status) = UserInfoWithSIDList_Find(SidBuf, pszUserName, cbUserName, pszDomainName, cbDomainName);
  if ( !Status )
  {
    LOBYTE(Status) = wcscpy_s(pszUserName, cbUserName, L"<unknown owner>");
    goto LABEL_8;
  }
  HIBYTE(fOK) = 1;
  if ( gdwVersion < WINDOWS_VISTA || !pszText )
    return Status;
LABEL_9:
  LOBYTE(Status) = wcscpy_s(pszText, cbText, &gszNullString);
LABEL_10:
  if ( ProcessHandle_1 )
  {
    Status = DeviceIoControl(
               ghDriverHandle,
               0x8335000C,
               &ProcessHandle_1,
               4u,
               &TokenHandle,
               4u,
               &FileTime.dwLowDateTime,
               0);
    if ( !Status )
    {
      Status = OpenProcessToken(ProcessHandle_1, TOKEN_QUERY, &TokenHandle);
      if ( !Status )
        LOBYTE(Status) = wcscpy_s(pszUserName, cbUserName, L"<unable to open token>");
    }
    if ( TokenHandle )
    {
      GetTokenInformation = ::GetTokenInformation;
      if ( gdwVersion < WINDOWS_VISTA )
        goto LABEL_37;
      if ( !pszText )
      {
LABEL_29:
        if ( gdwVersion >= WINDOWS_VISTA )
        {
          if ( pbUIAccess && !GetTokenInformation(TokenHandle, TokenUIAccess, pbUIAccess, 4u, &cbRet) )
            *pbUIAccess = 0;
          if ( gdwVersion >= WINDOWS_VISTA )
          {
            GetTokenInformation_1 = ::GetTokenInformation;
            if ( FileTime.dwHighDateTime
              && !::GetTokenInformation(TokenHandle, TokenVirtualizationEnabled, FileTime.dwHighDateTime, 4u, &cbRet) )
            {
              *FileTime.dwHighDateTime = -1;
            }
            goto LABEL_38;
          }
        }
LABEL_37:
        GetTokenInformation_1 = ::GetTokenInformation;
LABEL_38:
        if ( !HIBYTE(fOK) )
        {
          cbRet = 2048;
          if ( GetTokenInformation_1(TokenHandle, TokenUser, SidBuf, 0x800u, &cbRet) )
          {
            if ( !UserInfoWithSIDList_Find(*SidBuf, pszUserName, cbUserName, pszDomainName, cbDomainName) )
              wcscpy_s(pszUserName, cbUserName, L"<unknown owner>");
          }
          else
          {
            wcscpy_s(pszUserName, cbUserName, L"<unable to query owner>");
          }
        }
        LOBYTE(Status) = CloseHandle(TokenHandle);
        return Status;
      }
      dwProcessId_1 = 0;
      cbRet = 4;
      if ( gdwVersion >= WINDOWS_8 )
      {
        if ( ::GetTokenInformation(TokenHandle, MaxTokenInfoClass, &dwProcessId_1, 4u, &cbRet) && dwProcessId_1 )
        {
          wcscat_s(pszText, cbText, L"AppContainer");
LABEL_28:
          GetTokenInformation = ::GetTokenInformation;
          goto LABEL_29;
        }
        GetTokenInformation = ::GetTokenInformation;
      }
      cbRet = 2048;
      if ( GetTokenInformation(TokenHandle, TokenIntegrityLevel, SidBuf, 0x800u, &cbRet) )
      {
        UserInfoWithSIDList_Find(*SidBuf, pszText, cbText, ReferencedDomainName, 0x100u);
        if ( wcsstr(pszText, L" Mandatory Level") )
          *wcsstr(pszText, L" Mandatory Level") = 0;
      }
      goto LABEL_28;
    }
  }
  else if ( !HIBYTE(fOK) )
  {
    v14 = L"NT AUTHORITY\\SYSTEM";
    if ( dwProcessId_1 )
      v14 = L"<access denied>";
    LOBYTE(Status) = wcscpy_s(pszUserName, cbUserName, v14);
  }
  return Status;
}
// 108D238: using guessed type wchar_t aNtAuthoritySys[20];
// 10C4E54: using guessed type int gdwVersion;

//----- (01058790) --------------------------------------------------------
int GetDriverNameAndLinkInfo()
{
  unsigned __int16 iChar; // si
  WCHAR *pszDriverName; // ebx
  signed int chDriver; // edi
  int RtlInitUnicodeString; // eax
  HMODULE v4; // eax
  FARPROC RtlInitUnicodeString_1; // eax
  HMODULE v6; // eax
  int nDriverCount; // eax
  int result; // eax
  struct _UNICODE_STRING DestinationString; // [esp+Ch] [ebp-2E0h]
  struct _UNICODE_STRING strDeviceName; // [esp+14h] [ebp-2D8h]
  PCWSTR SourceString; // [esp+1Ch] [ebp-2D0h]
  ULONG ReturnedLength; // [esp+20h] [ebp-2CCh]
  OBJECT_ATTRIBUTES ObjectAttributes; // [esp+24h] [ebp-2C8h]
  int iDriver; // [esp+3Ch] [ebp-2B0h]
  HANDLE hLinkObject; // [esp+40h] [ebp-2ACh]
  WCHAR szDeviceName[64]; // [esp+44h] [ebp-2A8h]
  UNICODE_STRING strLinkTarget; // [esp+C4h] [ebp-228h]
  WCHAR szLinkNameBuffer[260]; // [esp+CCh] [ebp-220h]
  WCHAR szDriverName[10]; // [esp+2D4h] [ebp-18h]

  iDriver = 0;
  iChar = 0;
  pszDriverName = gszDriverName;
  chDriver = 'A';
  do
  {
    MakeDriverName(szDriverName, L"%c:\\", chDriver);
    if ( GetDriveTypeW(szDriverName) != FILE_TYPE_PIPE && GetDriveTypeW(szDriverName) != FILE_TYPE_CHAR )
      goto LABEL_17;
    MakeDeviceName(szDeviceName, L"\\DosDevices\\%c:", chDriver);
    RtlInitUnicodeString = *gpfnRtlInitUnicodeString;
    ObjectAttributes.Length = sizeof(OBJECT_ATTRIBUTES);
    ObjectAttributes.RootDirectory = 0;
    ObjectAttributes.Attributes = OBJ_CASE_INSENSITIVE;
    if ( !*gpfnRtlInitUnicodeString )
    {
      v4 = GetModuleHandleW(L"ntdll.dll");
      RtlInitUnicodeString = GetProcAddress(v4, "RtlInitUnicodeString");
      *gpfnRtlInitUnicodeString = RtlInitUnicodeString;
    }
    (RtlInitUnicodeString)(&strDeviceName, szDeviceName);
    ObjectAttributes.SecurityDescriptor = 0;
    ObjectAttributes.ObjectName = &strDeviceName;
    ObjectAttributes.SecurityQualityOfService = 0;
    if ( gpfn_NtOpenSymbolicLinkObject(&hLinkObject, 0x20001u, &ObjectAttributes) )
    {
LABEL_17:
      nDriverCount = iDriver;
    }
    else
    {
      strLinkTarget.Length = MAX_PATH;
      strLinkTarget.Buffer = szLinkNameBuffer;
      gpfn_NtQuerySymbolicLinkObject(hLinkObject, &strLinkTarget, &ReturnedLength);
      CloseHandle(hLinkObject);
      SourceString = strLinkTarget.Buffer;
      RtlInitUnicodeString_1 = *gpfnRtlInitUnicodeString;
      ObjectAttributes.Length = sizeof(OBJECT_ATTRIBUTES);
      ObjectAttributes.RootDirectory = 0;
      ObjectAttributes.Attributes = OBJ_CASE_INSENSITIVE;
      if ( !*gpfnRtlInitUnicodeString )
      {
        v6 = GetModuleHandleW(L"ntdll.dll");
        RtlInitUnicodeString_1 = GetProcAddress(v6, "RtlInitUnicodeString");
        *gpfnRtlInitUnicodeString = RtlInitUnicodeString_1;
      }
      (RtlInitUnicodeString_1)(&DestinationString, SourceString);
      ObjectAttributes.SecurityDescriptor = 0;
      ObjectAttributes.ObjectName = &DestinationString;
      ObjectAttributes.SecurityQualityOfService = 0;
      if ( !gpfn_NtOpenSymbolicLinkObject(&hLinkObject, 0x20001u, &ObjectAttributes) )
      {
        strLinkTarget.MaximumLength = MAX_PATH;
        strLinkTarget.Buffer = szLinkNameBuffer;
        gpfn_NtQuerySymbolicLinkObject(hLinkObject, &strLinkTarget, &ReturnedLength);
        CloseHandle(hLinkObject);
      }
      wcscpy_s(pszDriverName - 256, 0x100u, strLinkTarget.Buffer);
      *pszDriverName = iChar + 'A';
      nDriverCount = iDriver + 1;
      pszDriverName += 257;
      ++iDriver;
    }
    ++iChar;
    ++chDriver;
  }
  while ( iChar < 26u );
  result = 257 * nDriverCount;
  gszDriverLinkName[result] = 0;
  return result * 2;
}

//----- (01058A20) --------------------------------------------------------
char __cdecl sub_1058A20(int a1)
{
  char result; // al
  char v2; // dl
  signed int v3; // esi

  result = 0;
  v2 = *(a1 + 24);
  if ( v2 )
  {
    v3 = *(a1 + 28);
    if ( v3 < gConfig.dwHighlightDuration )
    {
      *(a1 + 20) = v3;
      *(a1 + 16) = 2;
      return result;
    }
    if ( v2 )
    {
      result = 1;
      *(a1 + 24) = 0;
    }
  }
  *(a1 + 16) = 0;
  return result;
}

//----- (01058A60) --------------------------------------------------------
int __cdecl ReportMsg(int ArgList, HWND hWnd)
{
  DWORD v2; // eax
  WCHAR Buffer[2]; // [esp+8h] [ebp-208h]
  WCHAR Text; // [esp+Ch] [ebp-204h]

  v2 = GetLastError();
  if ( v2 )
  {
    FormatMessageW(0x1100u, 0, v2, 0x400u, Buffer, 0, 0);
    wsprintf(&Text, L"%s: %s", ArgList, *Buffer);
    LocalFree(*Buffer);
  }
  else
  {
    wsprintf(&Text, L"%s.", ArgList);
  }
  return MessageBoxW(hWnd, &Text, L"Process Explorer", 0x10u);
}

//----- (01058B10) --------------------------------------------------------
int __stdcall PageProcStrings(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
  tagTREEVIEWLISTITEMPARAM *pTreeItem; // esi
  HWND hWndList; // ebx
  CResizer *v7; // eax
  LONG v8; // eax
  HWND v9; // ST14_4
  HWND v10; // eax
  LRESULT v11; // ST14_4
  HWND v12; // eax
  LRESULT v13; // ST14_4
  HWND v14; // eax
  void *dwProcessId; // eax
  WCHAR *pszClassName; // ecx
  HANDLE ProcessHandle; // eax
  char v18; // al
  HANDLE v19; // esi
  void (__stdcall *SendMessageW)(HWND, UINT, WPARAM, LPARAM); // esi
  LRESULT v21; // ST14_4
  HWND v22; // eax
  LRESULT v23; // ST14_4
  HWND v24; // eax
  wchar_t *v25; // eax
  HWND v26; // eax
  HANDLE v27; // esi
  LRESULT v28; // eax
  HGLOBAL v29; // edi
  _WORD *v30; // eax
  HGLOBAL v31; // eax
  int v32; // esi
  rsize_t v33; // ST04_4
  LRESULT i; // esi
  HCURSOR v35; // esi
  int v36; // eax
  HCURSOR v37; // esi
  char v38; // bl
  HWND v39; // esi
  HWND v40; // eax
  HWND hWndFindWindow; // eax
  HWND v42; // eax
  WPARAM v43; // [esp-8h] [ebp-29Ch]
  LVITEMW Item; // [esp+Ch] [ebp-288h]
  tagLVITEMW ItemInfo; // [esp+40h] [ebp-254h]
  LPCVOID lpBaseAddress; // [esp+74h] [ebp-220h]
  DWORD dwSize; // [esp+78h] [ebp-21Ch]
  UINT pnIDs; // [esp+7Ch] [ebp-218h]
  WORD pnWidths[2]; // [esp+80h] [ebp-214h]
  HANDLE dwPid; // [esp+84h] [ebp-210h]
  HANDLE hDlg; // [esp+88h] [ebp-20Ch]
  LONG dwNewLong; // [esp+8Ch] [ebp-208h]
  WCHAR szText[256]; // [esp+90h] [ebp-204h]

  hDlg = hWnd;
  dwNewLong = lParam;
  pTreeItem = GetWindowLongW(hWnd, GWLP_USERDATA);
  ItemInfo.mask = 0;
  memset(&ItemInfo.iItem, 0, 0x30u);
  hWndList = GetDlgItem(hWnd, IDC_PROCSTRINGS_LISTCTRL);
  pnIDs = 1058;
  pnWidths[0] = MulDiv(100, gLogPixelSize.x, 96);
  if ( msg > WM_INITDIALOG )
  {
    switch ( msg )
    {
      case WM_COMMAND:
        if ( wParam > IDC_PROCSTRINGS_BUTTON_SAVE )
        {
          if ( wParam > IDM_LISTCTRL_SELECTALL )
          {
            if ( wParam == IDM_PROCSTRINGS_FINDITEM && sbFound )
            {
              v35 = SetCursor(ghWaitCursor);
              ProcStrings_FindItem(hDlg, hWndList, &gFindReplaceItem, sstrFindWhat, &sbFound, &word_10E10E8);
              SetCursor(v35);
              ReleaseCapture();
            }
          }
          else if ( wParam == IDM_LISTCTRL_SELECTALL )
          {
            for ( i = 0; i < ::SendMessageW(hWndList, LVM_GETITEMCOUNT, 0, 0); ++i )
            {
              Item.stateMask = LVIS_SELECTED;
              Item.state = LVIS_SELECTED;
              ::SendMessageW(hWndList, LVM_SETITEMSTATE, i, &Item);
            }
          }
          else
          {
            if ( wParam != IDM_LISTCTRL_COPY )
            {
              if ( wParam - 40092 > 1 )
                return 0;
              v43 = wParam;
              goto LABEL_50;
            }
            // 执行复制到剪贴板
            v27 = 0;
            dwNewLong = 0;
            v28 = ::SendMessageW(hWndList, LVM_GETNEXTITEM, ItemInfo.iItem, 2);
            ItemInfo.iItem = v28;
            if ( v28 != -1 )
            {
              v29 = 0;
              do
              {
                Item.iSubItem = 0;
                Item.pszText = szText;
                Item.cchTextMax = 256;
                ::SendMessageW(hWndList, LVM_GETITEMTEXTW, v28, &Item);
                dwNewLong += wcslen(szText) + 2;
                if ( v27 )
                {
                  v29 = GlobalReAlloc(v29, 2 * dwNewLong + 2, 0);
                  v30 = GlobalLock(v29);
                }
                else
                {
                  v31 = GlobalAlloc(0x2002u, 2 * dwNewLong + 2);
                  v29 = v31;
                  v30 = GlobalLock(v31);
                  *v30 = 0;
                }
                v32 = dwNewLong + 1;
                dwPid = v30;
                wcscat_s(v30, dwNewLong + 1, szText);
                v33 = v32;
                v27 = dwPid;
                wcscat_s(dwPid, v33, L"\r\n");
                GlobalUnlock(v29);
                v28 = ::SendMessageW(hWndList, LVM_GETNEXTITEM, ItemInfo.iItem, 2);
                ItemInfo.iItem = v28;
              }
              while ( v28 != -1 );
              dwPid = v29;
              if ( v29 )
              {
                if ( OpenClipboard(hDlg) )
                {
                  EmptyClipboard();
                  SetClipboardData(0xDu, dwPid);
                  CloseClipboard();
                }
              }
            }
          }
        }
        else if ( wParam == IDC_PROCSTRINGS_BUTTON_SAVE )
        {
          if ( pTreeItem->nListType )
          {
            v25 = wcsrchr(*&pTreeItem->gap154[4], 0x5Cu);
            SaveProcessStrings(hWndList, v25 + 1);
          }
          else
          {
            SaveProcessStrings(hWndList, pTreeItem->szProcessName2);
          }
        }
        else
        {
          // 内存模式
          if ( wParam <= 1304 )
          {
            switch ( wParam )
            {
              case IDC_DLG_DLLSTRINGS_RADIO_IMAGE:
                ::SendMessageW(hWndList, WM_SETREDRAW, 0, 0);
                ::SendMessageW(hWndList, LVM_DELETEALLITEMS, 0, 0);
                if ( pTreeItem->nListType )
                  sub_10264C0(hWndList, *&pTreeItem->gap154[4]);
                else
                  sub_10264C0(hWndList, pTreeItem->szProcessName);
                ::SendMessageW(hWndList, LVM_SETCOLUMNWIDTH, 0, 0xFFFF);
                ::SendMessageW(hWndList, WM_SETREDRAW, 1u, 0);
                v11 = ::SendMessageW(hWndList, LVM_GETITEMCOUNT, 0, 0);
                v12 = GetDlgItem(hWnd, IDC_PROCSTRINGS_BUTTON_SAVE);
                EnableWindow(v12, v11);
                v13 = ::SendMessageW(hWndList, LVM_GETITEMCOUNT, 0, 0);
                v14 = GetDlgItem(hWnd, IDC_PROCSTRINGS_BUTTON_FIND);
                EnableWindow(v14, v13);
                break;
              case IDC_MYICON:
                EndDialog(hWnd, 0);
                return 1;
              case IDC_THREADSTACK_BUTTON_REFRESH:
                wcscpy_s(sstrFindWhat, 0x2000u, &word_10E10E8);
                gFindReplaceItem.hInstance = ghInstance;
                gFindReplaceItem.lStructSize = 40;
                gFindReplaceItem.hwndOwner = hWnd;
                gFindReplaceItem.lpstrFindWhat = sstrFindWhat;
                gFindReplaceItem.lpstrReplaceWith = 0;
                *&gFindReplaceItem.wFindWhatLen = 0x2000;
                gFindReplaceItem.lCustData = 0;
                gFindReplaceItem.Flags = gdwFindReplaceFlags;
                gFindReplaceItem.lpfnHook = 0;
                gFindReplaceItem.lpTemplateName = 0;
                v9 = FindTextW(&gFindReplaceItem);
                v10 = GetParent(hWnd);
                SetPropW(v10, L"FindWindow", v9);
                break;
            }
            return 0;
          }
          // IDC_PROCSTRINGS_BUTTON_IMAGE，镜像模�?
          if ( wParam != 1305 )
          {
            if ( wParam != 40001 )
              return 0;
            v43 = 40014;
LABEL_50:
            v26 = GetParent(hWnd);
            PostMessageW(v26, WM_COMMAND, v43, 0);
            return 0;
          }
          ::SendMessageW(hWndList, 0xBu, 0, 0);
          ::SendMessageW(hWndList, LVM_DELETEALLITEMS, 0, 0);
          if ( pTreeItem->nListType )
          {
            dwProcessId = pTreeItem->dwStyle;
            pszClassName = *&pTreeItem->gap154[4];
          }
          else
          {
            dwProcessId = pTreeItem->dwProcessId;
            pszClassName = pTreeItem->szProcessName;
          }
          dwNewLong = pszClassName;
          dwPid = dwProcessId;
          ProcessHandle = OpenProcess(0x410u, 0, dwProcessId);
          hDlg = ProcessHandle;
          if ( ProcessHandle )
          {
            if ( pTreeItem->nListType )
            {
              LoadStringToList(hWndList, ProcessHandle, pTreeItem->nRefCount, pTreeItem->hFileIcon);
              v19 = hDlg;
            }
            else
            {
              v18 = sub_10403E0(ProcessHandle, dwPid, dwNewLong, &lpBaseAddress, &dwSize);
              v19 = hDlg;
              if ( v18 )
                LoadStringToList(hWndList, hDlg, lpBaseAddress, dwSize);
            }
            CloseHandle(v19);
            SendMessageW = ::SendMessageW;
          }
          else
          {
            SendMessageW = ::SendMessageW;
            ItemInfo.mask = 5;
            ItemInfo.iItem = 0x7FFFFFFF;
            ItemInfo.pszText = L"<Error opening process>";
            ItemInfo.lParam = 1;
            ::SendMessageW(hWndList, LVM_INSERTITEMW, 0, &ItemInfo);
          }
          SendMessageW(hWndList, LVM_SETCOLUMNWIDTH, 0, 0xFFFF);
          SendMessageW(hWndList, WM_SETREDRAW, 1u, 0);
          v21 = (SendMessageW)(hWndList, LVM_GETITEMCOUNT, 0, 0);
          v22 = GetDlgItem(hWnd, IDC_PROCSTRINGS_BUTTON_SAVE);
          EnableWindow(v22, v21);
          v23 = ::SendMessageW(hWndList, LVM_GETITEMCOUNT, 0, 0);
          v24 = GetDlgItem(hWnd, IDC_PROCSTRINGS_BUTTON_FIND);
          EnableWindow(v24, v23);
        }
        return 0;
      case WM_CTLCOLOREDIT:
      case WM_CTLCOLORDLG:
      case WM_CTLCOLORSTATIC:
        return PE_FillControl(hWnd, wParam);
      default:
        goto LABEL_67;
    }
  }
  if ( msg != WM_INITDIALOG )
  {
    switch ( msg )
    {
      case WM_ALTTABACTIVE|WM_DESTROY:
        CMainWnd::DrawList(dwNewLong);
        return 0;
      case 0x2Cu:
        return CMainWnd::HandleMeasureItem(hWnd, msg, wParam, dwNewLong);
      case WM_KEYUP:
        if ( wParam == VK_F3 )
          ::SendMessageW(hWnd, WM_COMMAND, IDM_PROCSTRINGS_FINDITEM, 0);
        return 0;
      case WM_CHAR:
        if ( wParam == 'F' || wParam == 'f' )
        {
          if ( GetKeyState(VK_CONTROL) )
            ::SendMessageW(hWnd, WM_COMMAND, IDC_PROCSTRINGS_BUTTON_FIND, 0);
        }
        return 0;
      default:
        break;
    }
LABEL_67:
    if ( msg == gdwComdlg_FindReplaceMessageID )
    {
      v36 = *(dwNewLong + 12);
      if ( v36 & 0x40 )
      {
        // FR_DOWN|FR_WHOLEWORD|FR_MATCHCASE
        gdwFindReplaceFlags = gFindReplaceItem.Flags & 7;
      }
      else if ( v36 & 8 )
      {
        v37 = SetCursor(ghWaitCursor);
        v38 = ProcStrings_FindItem(hDlg, hWndList, dwNewLong, sstrFindWhat, &sbFound, &word_10E10E8);
        SetCursor(v37);
        ReleaseCapture();
        v39 = hDlg;
        v40 = GetParent(hDlg);
        hWndFindWindow = GetPropW(v40, L"FindWindow");
        if ( v38 && hWndFindWindow )
        {
          PostMessageW(hWndFindWindow, WM_COMMAND, IDC_DLG_DLLINFO_EDIT_COMPANY, 0);
          v42 = GetParent(v39);
          SetPropW(v42, L"FindWindow", 0);
        }
        else
        {
          SetFocus(hWndFindWindow);
        }
      }
    }
    return 0;
  }
  // WM_INITDIALOG，对话框初始�?
  v7 = operator new(0x40u);
  if ( v7 )
    CResizer::CResizer(v7, hWnd);
  GetWindowTextW(hWnd, szText, 256);
  PropSheet_UpdateTab(hWnd);
  SetWindowLongW(hWnd, GWLP_USERDATA, dwNewLong);
  CheckRadioButton(
    hWnd,
    IDC_DLG_DLLSTRINGS_RADIO_IMAGE,
    IDC_DLG_DLLSTRINGS_RADIO_MEMORY,
    IDC_DLG_DLLSTRINGS_RADIO_IMAGE);
  v8 = GetWindowLongW(hWndList, GWL_STYLE);
  SetWindowLongW(hWndList, -16, v8 & -3u | LVS_REPORT);
  SetWindowLongW(hWndList, -4, Proxy_ListCtrlWndProc);
  ::SendMessageW(hWndList, WM_SETFONT, ghConfigFont, 0);
  InitListHeader(hWndList, &pnIDs, pnWidths, 1);
  PostMessageW(hWnd, WM_COMMAND, IDC_DLG_DLLSTRINGS_RADIO_IMAGE, 0);
  return 1;
}
// 10A606C: using guessed type wchar_t aErrorOpeningPr_1[24];
// 10C10E0: using guessed type int gdwFindReplaceFlags;
// 10CA32C: using guessed type int gdwComdlg_FindReplaceMessageID;

//----- (01059520) --------------------------------------------------------
char __usercall CMainWnd::RefreshDllsView@<al>(signed int a1@<ebx>, HWND hWnd, DWORD dwProcessId, WPARAM wParam)
{
  DWORD v4; // esi
  HWND v5; // edi
  _BYTE *v6; // eax
  tagTREEVIEWLISTITEMPARAM *v7; // ecx
  DLLLISTITEMPARAM *v8; // eax
  DLLLISTITEMPARAM *v9; // esi
  char v10; // al
  _DWORD *v11; // edi
  ULONG v12; // esi
  bool v13; // zf
  int v14; // ebx
  DLLLISTITEMPARAM *v15; // ecx
  wchar_t *v16; // eax
  CHAR *v17; // edx
  int v18; // ecx
  HANDLE v19; // esi
  char v20; // dl
  char v21; // dh
  signed int v22; // eax
  void *v23; // esi
  DLLLISTITEMPARAM *v25; // eax
  DLLLISTITEMPARAM *v26; // esi
  char v27; // al
  SYSTEM_PROCESS_INFORMATION *v28; // edi
  tagTREEVIEWLISTITEMPARAM *v29; // esi
  CHAR *v30; // eax
  DWORD v31; // ecx
  void *v32; // edi
  unsigned int *v33; // eax
  IAtlStringMgr *v34; // eax
  const WCHAR *v35; // esi
  wchar_t *v36; // edi
  DWORD v37; // eax
  WCHAR *v38; // esi
  signed int v39; // edi
  int v40; // eax
  const wchar_t *v41; // ebx
  int v42; // eax
  DLLLISTITEMPARAM *v43; // edi
  char v44; // cl
  char v45; // dl
  signed int v46; // eax
  char v47; // al
  char v48; // al
  char v49; // cl
  HANDLE v50; // edi
  PIMAGE_NT_HEADERS v51; // eax
  HANDLE v52; // edi
  int v53; // edi
  int v54; // esi
  int v55; // ecx
  DLLLISTITEMPARAM *v56; // eax
  char v57; // dl
  signed int v58; // ecx
  char v59; // al
  char v60; // [esp-188h] [ebp-29A0h]
  DWORD v61; // [esp-20h] [ebp-2838h]
  void *v62; // [esp-1Ch] [ebp-2834h]
  wchar_t *v63; // [esp-18h] [ebp-2830h]
  int *v64; // [esp-14h] [ebp-282Ch]
  const void *v65; // [esp-10h] [ebp-2828h]
  char *v66; // [esp-Ch] [ebp-2824h]
  WCHAR *v67; // [esp-8h] [ebp-2820h]
  wchar_t *v68; // [esp-4h] [ebp-281Ch]
  LPARAM v69; // [esp+Ch] [ebp-280Ch]
  int v70; // [esp+10h] [ebp-2808h]
  DLLLISTITEMPARAM *v71; // [esp+2Ch] [ebp-27ECh]
  struct _FILETIME v72; // [esp+40h] [ebp-27D8h]
  DWORD ThreadId; // [esp+48h] [ebp-27D0h]
  struct _FILETIME LastAccessTime; // [esp+4Ch] [ebp-27CCh]
  unsigned int *v75; // [esp+54h] [ebp-27C4h]
  DWORD ExitCode; // [esp+58h] [ebp-27C0h]
  struct _FILETIME LocalFileTime; // [esp+5Ch] [ebp-27BCh]
  struct _FILETIME CreationTime; // [esp+64h] [ebp-27B4h]
  struct _FILETIME LastWriteTime; // [esp+6Ch] [ebp-27ACh]
  int v80; // [esp+74h] [ebp-27A4h]
  unsigned int v81; // [esp+78h] [ebp-27A0h]
  ULONG ReturnLength; // [esp+7Ch] [ebp-279Ch]
  CString v83; // [esp+80h] [ebp-2798h]
  DWORD v84; // [esp+84h] [ebp-2794h]
  LPCWSTR lptstrFilename; // [esp+88h] [ebp-2790h]
  int v86; // [esp+8Ch] [ebp-278Ch]
  int v87; // [esp+90h] [ebp-2788h]
  _DWORD *v88; // [esp+94h] [ebp-2784h]
  void *v89; // [esp+98h] [ebp-2780h]
  HWND v90; // [esp+9Ch] [ebp-277Ch]
  SYSTEM_PROCESS_INFORMATION *v91; // [esp+A0h] [ebp-2778h]
  DWORD v92; // [esp+A4h] [ebp-2774h]
  int v93; // [esp+A8h] [ebp-2770h]
  DLLLISTITEMPARAM *v94; // [esp+ACh] [ebp-276Ch]
  char v95; // [esp+B2h] [ebp-2766h]
  int v96; // [esp+B3h] [ebp-2765h]
  int v97; // [esp+C4h] [ebp-2754h]
  wchar_t *v98; // [esp+D8h] [ebp-2740h]
  wchar_t v99; // [esp+DCh] [ebp-273Ch]
  int v100; // [esp+15Ch] [ebp-26BCh]
  int v101; // [esp+160h] [ebp-26B8h]
  int v102; // [esp+164h] [ebp-26B4h]
  wchar_t *v103; // [esp+168h] [ebp-26B0h]
  char v104; // [esp+16Ch] [ebp-26ACh]
  int v105; // [esp+17Ch] [ebp-269Ch]
  int v106; // [esp+180h] [ebp-2698h]
  char v107; // [esp+184h] [ebp-2694h]
  int v108; // [esp+190h] [ebp-2688h]
  int v109; // [esp+198h] [ebp-2680h]
  DWORD v110; // [esp+19Ch] [ebp-267Ch]
  char hObject; // [esp+1A0h] [ebp-2678h]
  char BaseAddress; // [esp+1A2h] [ebp-2676h]
  int v113; // [esp+1A4h] [ebp-2674h]
  __int16 v114; // [esp+1A8h] [ebp-2670h]
  struct _FILETIME v115; // [esp+1ACh] [ebp-266Ch]
  int v116; // [esp+1B4h] [ebp-2664h]
  wchar_t Dst; // [esp+1B8h] [ebp-2660h]
  wchar_t v118; // [esp+23Ah] [ebp-25DEh]
  DWORD dwLen; // [esp+2BCh] [ebp-255Ch]
  int v120; // [esp+2C0h] [ebp-2558h]
  LPCWSTR lpFileName; // [esp+2C4h] [ebp-2554h]
  wchar_t *v122; // [esp+2C8h] [ebp-2550h]
  SYSTEMTIME Date; // [esp+2F4h] [ebp-2524h]
  struct _SYSTEMTIME SystemTime; // [esp+304h] [ebp-2514h]
  char Buffer; // [esp+314h] [ebp-2504h]
  wchar_t v126; // [esp+2314h] [ebp-504h]
  LPARAM lParam; // [esp+2514h] [ebp-304h]
  WCHAR TimeStr; // [esp+2714h] [ebp-104h]
  WCHAR DateStr; // [esp+2794h] [ebp-84h]

  v87 = 0;
  v4 = dwProcessId;
  LOBYTE(a1) = 0;
  v5 = hWnd;
  v93 = 0;
  v95 = 0;
  v86 = 0;
  v89 = 0;
  LOWORD(lParam) = 1;
  v90 = hWnd;
  v92 = dwProcessId;
  v94 = a1;
  memset(&lParam + 2, 0, 0x1FEu);
  v6 = wParam;
  if ( !wParam )
  {
    if ( gConfig.dwDllColumnCount == wParam || !gConfig.bShowLowerPane )
      return 0;
    v89 = sub_104DE60(dwProcessId);
    v6 = 0;
  }
  if ( dwProcessId )
  {
    v7 = gpTreeViewListItemParam;
    v86 = gpTreeViewListItemParam;
    if ( gpTreeViewListItemParam )
    {
      do
      {
        if ( v7->dwProcessId == dwProcessId )
          break;
        v7 = v7->m_Prev;
      }
      while ( v7 );
      v86 = v7;
    }
  }
  if ( !*CreateToolhelp32Snapshot_0 )
  {
    if ( !v6 )
    {
      if ( dwProcessId != gdwValue_4F10B8[1] )
      {
        v95 = 1;
        SendMessageW(hWnd, 0xBu, 0, 0);
        SendMessageW(hWnd, 0x1009u, 0, 0);
        SendMessageW(ghWndStatusBar, 0x40Du, gnStatusBarItemCount - 1, &lParam);
        SendMessageW(ghWndStatusBar, 0x40Bu, gnStatusBarItemCount - 1, L"Refreshing DLLs...");
        UpdateMenuStatus(0, 5);
      }
      v25 = gpDllListItemParamHeader;
      if ( gpDllListItemParamHeader )
      {
        do
        {
          v26 = v25->m_Prev;
          v71 = v25;
          v70 = -1;
          v27 = sub_10558D0(a1, hWnd, &v69, v25, &v96);
          a1 = a1;
          if ( v27 )
            a1 = 1;
          if ( v96 )
            ++v87;
          v25 = v26;
        }
        while ( v26 );
        v4 = v92;
        v94 = a1;
      }
      v6 = wParam;
    }
    v28 = gpSystemProcessInfo;
    while ( 1 )
    {
      v91 = v28;
      if ( !v6 && v28->UniqueProcessId != v4 )
      {
        v23 = v89;
        goto LABEL_165;
      }
      v29 = gpTreeViewListItemParam;
      LOBYTE(v80) = 0;
      if ( !gpTreeViewListItemParam )
        goto LABEL_79;
      while ( v29->dwProcessId != v28->UniqueProcessId )
      {
        v29 = v29->m_Prev;
        if ( !v29 )
          goto LABEL_79;
      }
      a1 = v29->dwStyle >> 4;
      LOBYTE(a1) = a1 & 1;
      v80 = a1;
      if ( !a1 )
      {
LABEL_79:
        v30 = RtlCreateQueryDebugBuffer(0, 0);
        v83.pszData = v30;
        if ( !v30 )
          return 0;
        v31 = v28->UniqueProcessId;
        LocalFileTime.dwHighDateTime = v30;
        LocalFileTime.dwLowDateTime = v31;
        v32 = _beginthreadex(0, 0, QueryProcessDebugInforThreadProc, &LocalFileTime, 0, &ThreadId);
        if ( WaitForSingleObject(v32, 0xFA0u) == 258 )
          TerminateThread(v32, 1u);
        GetExitCodeThread(v32, &ExitCode);
        CloseHandle(v32);
        if ( !ExitCode )
        {
          v81 = 0;
          v33 = *(v83.pszData + 12);
          v75 = v33;
          if ( *v33 )
          {
            a1 = (v33 + 8);
            v88 = v33 + 8;
            while ( 1 )
            {
              memset(&v104, 0, 0x188u);
              v110 = 0;
              v108 = *(a1 - 20);
              v113 = *(a1 - 16);
              v114 = *(a1 - 4);
              if ( *a1 == 92 && *(a1 + 1) == 63 )
                strcpy_s(a1, 0x100u, (a1 + 4));
              v34 = ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>::GetDefaultManager();
              if ( !v34 )
                ATL::AtlThrowImpl(-2147467259);
              lptstrFilename = ((v34->vtptr->GetNilData)(v34) + 16);
              ATL::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>::operator=(&lptstrFilename, a1);
              v35 = lptstrFilename;
              v36 = _wcsdup(lptstrFilename);
              if ( *GetLongPathNameW )
              {
                v37 = GetLongPathNameW(v36, 0, 0);
                v84 = v37;
                if ( v37 )
                {
                  v38 = malloc(2 * v37 + 2);
                  GetLongPathNameW(v36, v38, v84 + 1);
                  free(v36);
                  v36 = v38;
                  j__free(0);
                  v35 = lptstrFilename;
                }
              }
              lpFileName = v36;
              wcscpy_s(&v118, 0x41u, &gszNullString);
              if ( !wParam )
                break;
              v39 = wcslen(gszStringToFindLast);
              v40 = *(v35 - 3);
              if ( v40 >= v39 )
              {
                v84 = 0;
                if ( v40 - v39 + 1 > 0 )
                {
                  v41 = v35;
                  while ( _wcsnicmp(v41, gszStringToFindLast, v39) )
                  {
                    ++v41;
                    v42 = *(v35 - 3) - v39 + 1;
                    if ( ++v84 >= v42 )
                    {
                      a1 = v88;
                      goto LABEL_134;
                    }
                  }
                  a1 = v88;
LABEL_117:
                  PE_GetProductCopyright(v35, &v118, 0x41u, &dwLen, &v120);
                  if ( !wParam )
                  {
                    v68 = v91->UniqueProcessId;
                    v50 = OpenProcess(0x410u, 0, v68);
                    if ( v50 )
                    {
                      v68 = &LastWriteTime.dwHighDateTime;
                      v67 = 0x2000;
                      v66 = &Buffer;
                      v65 = *(a1 - 20);
                      if ( ReadProcessMemory(v50, v65, &Buffer, 0x2000u, &LastWriteTime.dwHighDateTime) )
                      {
                        v51 = ImageNtHeader(&Buffer);
                        if ( v51 )
                        {
                          v110 = v51->OptionalHeader.ImageBase;
                          if ( v51->OptionalHeader.ImageBase != *(a1 - 20) )
                            v109 |= 1u;
                        }
                      }
                      CloseHandle(v50);
                    }
                  }
                  wcscpy_s(&Dst, 0x41u, &gszNullString);
                  v115 = 0i64;
                  v52 = CreateFileW(v35, 0x80000000, 7u, 0, 3u, 0, 0);
                  if ( v52 != -1 )
                  {
                    GetFileTime(v52, &SystemTime.wHour, &v72, &CreationTime);
                    CloseHandle(v52);
                    v115 = CreationTime;
                    FileTimeToLocalFileTime(&CreationTime, &LastAccessTime);
                    FileTimeToSystemTime(&LastAccessTime, &Date);
                    GetDateFormatW(0x400u, 1u, &Date, 0, &TimeStr, 64);
                    GetTimeFormatW(0x400u, 2u, &Date, 0, &DateStr, 64);
                    v68 = &DateStr;
                    v67 = &TimeStr;
                    sub_1039DE0(&Dst, L"%s %s", &TimeStr, &DateStr);
                  }
                  if ( wParam )
                  {
                    v53 = v91;
                    wcsncpy_s(&v126, 0x100u, v91->ImageName.Buffer, v91->ImageName.Length >> 1);
                    v102 = 0;
                    v98 = _wcsdup(&v126);
                    v103 = _wcsdup(v35);
                    v100 = *(v53 + 68);
                    v97 = 0;
                    v101 = *(a1 - 20);
                    wcscpy_s(&v99, 0x40u, L"DLL");
                    sub_10178D0(v90, (&v96 + 1));
                  }
                  else
                  {
                    sub_103C400(v89, &v104);
                    v106 = 0;
                    if ( gdwValue_4F10B8[1] == v92 )
                    {
                      v105 = 2;
                    }
                    else
                    {
                      v107 = 0;
                      v105 = 0;
                    }
                    if ( PE_CheckExeFile(lpFileName, &v116, &hObject, &BaseAddress) )
                      v109 |= 4u;
                    qmemcpy(&v60, &v104, 0x188u);
                    sub_1017790(v90, v60);
                    v35 = lptstrFilename;
                    LOBYTE(v94) = 1;
                  }
                  goto LABEL_134;
                }
              }
LABEL_134:
              v54 = (v35 - 8);
              if ( _InterlockedDecrement((v54 + 12)) <= 0 )
              {
                v55 = *v54;
                v68 = v54;
                (*(*v55 + 4))(v54);
              }
              a1 += 284;
              ++v81;
              v88 = a1;
              if ( v81 >= *v75 )
                goto LABEL_160;
            }
            v43 = gpDllListItemParamHeader;
            if ( gpDllListItemParamHeader )
            {
              while ( 1 )
              {
                if ( v43->m_LoadAddress == *(a1 - 20) && v43->m_MappedSize == *(a1 - 16) )
                {
                  v68 = v35;
                  v67 = v43->m_strPath.pszData;
                  if ( !_wcsicmp(v67, v35) )
                    break;
                }
                v43 = v43->m_Prev;
                if ( !v43 )
                  goto LABEL_104;
              }
              v44 = v43->field_18;
              v45 = 0;
              ++v93;
              if ( v44 )
              {
                v46 = v43->field_1C;
                if ( v46 < gConfig.dwHighlightDuration )
                {
                  v43->field_10 = 2;
                  v43->field_14 = v46;
LABEL_113:
                  v48 = sub_103C400(v89, v43);
                  v49 = v94;
                  if ( v48 )
                    v49 = 1;
                  LOBYTE(v94) = v49;
                  goto LABEL_134;
                }
                if ( v44 )
                {
                  v45 = 1;
                  LOBYTE(v43->field_18) = 0;
                }
              }
              v47 = v94;
              if ( v45 )
                v47 = 1;
              v43->field_10 = 0;
              LOBYTE(v94) = v47;
              goto LABEL_113;
            }
LABEL_104:
            sub_103C400(v89, &v104);
            goto LABEL_117;
          }
LABEL_160:
          RtlDestroyQueryDebugBuffer(v83.pszData);
          goto LABEL_161;
        }
      }
      if ( !wParam )
      {
        v29->dwStyle |= 0x10u;
        v56 = gpDllListItemParamHeader;
        if ( !gpDllListItemParamHeader )
        {
LABEL_143:
          memset(&v104, 0, 0x188u);
          v108 = 0;
          v114 = 0;
          v113 = 0;
          if ( PE_CheckExeFile(lpFileName, &v116, &hObject, &BaseAddress) )
            v109 |= 4u;
          lpFileName = _wcsdup(L"<Unable to query process module information>");
          wcscpy_s(&v118, 0x41u, &gszNullString);
          wcscpy_s(&Dst, 0x41u, &gszNullString);
          v106 = 0;
          v115 = 0i64;
          if ( gdwValue_4F10B8[1] == v92 )
          {
            v105 = 2;
          }
          else
          {
            v107 = 0;
            v105 = 0;
          }
          if ( PE_CheckExeFile(lpFileName, &v116, &hObject, &BaseAddress) )
            v109 |= 4u;
          qmemcpy(&v60, &v104, 0x188u);
          sub_1017790(v90, v60);
LABEL_158:
          LOBYTE(v94) = 1;
          goto LABEL_159;
        }
        while ( v56->m_LoadAddress || v56->m_MappedSize )
        {
          v56 = v56->m_Prev;
          if ( !v56 )
            goto LABEL_143;
        }
        LOBYTE(a1) = v56->field_18;
        v57 = 0;
        ++v93;
        if ( a1 )
        {
          v58 = v56->field_1C;
          if ( v58 < gConfig.dwHighlightDuration )
          {
            v56->field_10 = 2;
            v56->field_14 = v58;
            goto LABEL_159;
          }
          if ( a1 )
          {
            v57 = 1;
            LOBYTE(v56->field_18) = 0;
          }
        }
        v56->field_10 = 0;
        if ( v57 )
          goto LABEL_158;
      }
LABEL_159:
      if ( !v80 )
        goto LABEL_160;
LABEL_161:
      v28 = v91;
      wcsncpy_s(&v126, 0x100u, v91->ImageName.Buffer, v91->ImageName.Length >> 1);
      v23 = v89;
      v64 = &v93;
      v63 = &v126;
      v62 = v89;
      v61 = v28->UniqueProcessId;
      v59 = sub_104F870(a1, v90, wParam, v86, v61, v89, &v126, &v93);
      a1 = v94;
      if ( v59 )
        a1 = 1;
      v94 = a1;
LABEL_165:
      if ( !v28->NextEntryOffset )
      {
        v5 = v90;
        goto LABEL_168;
      }
      v4 = v92;
      v28 = (v28 + v28->NextEntryOffset);
      v6 = wParam;
    }
  }
  if ( v6 )
  {
    sub_1055140(a1, hWnd, v6);
    return 0;
  }
  if ( dwProcessId != gdwValue_4F10B8[1] )
  {
    v95 = 1;
    SendMessageW(hWnd, 0xBu, 0, 0);
    SendMessageW(hWnd, 0x1009u, 0, 0);
    SendMessageW(ghWndStatusBar, 0x40Du, gnStatusBarItemCount - 1, &lParam);
    SendMessageW(ghWndStatusBar, 0x40Bu, gnStatusBarItemCount - 1, L"Refreshing DLLs...");
    UpdateMenuStatus(0, 5);
  }
  v8 = gpDllListItemParamHeader;
  if ( gpDllListItemParamHeader )
  {
    do
    {
      v9 = v8->m_Prev;
      v71 = v8;
      v70 = -1;
      v10 = sub_10558D0(a1, hWnd, &v69, v8, &v96);
      a1 = a1;
      if ( v10 )
        a1 = 1;
      if ( v96 )
        ++v87;
      v8 = v9;
    }
    while ( v9 );
    v4 = v92;
    v94 = a1;
  }
  if ( v4 == 8 || v4 == 4 )
  {
    ReturnLength = 1000;
    v88 = malloc(0x3E8u);
    v11 = v88;
    if ( NtQuerySystemInformation(SystemModuleInformation, v88, 0x3E8u, &ReturnLength) )
    {
      do
      {
        free(v11);
        ReturnLength += 1000;
        v12 = ReturnLength;
        v11 = malloc(ReturnLength);
      }
      while ( NtQuerySystemInformation(SystemModuleInformation, v11, v12, &ReturnLength) );
      v88 = v11;
    }
    v13 = *v11 == 0;
    v91 = 0;
    if ( !v13 )
    {
      v14 = (v11 + 4);
      while ( 1 )
      {
        v15 = gpDllListItemParamHeader;
        if ( gpDllListItemParamHeader )
        {
          while ( v15->m_LoadAddress != *(v14 - 4) || v15->m_MappedSize != *v14 )
          {
            v15 = v15->m_Prev;
            if ( !v15 )
              goto LABEL_32;
          }
          v20 = v15->field_18;
          v21 = 0;
          ++v93;
          if ( v20 )
          {
            v22 = v15->field_1C;
            if ( v22 < gConfig.dwHighlightDuration )
            {
              v15->field_10 = 2;
              v15->field_14 = v22;
              goto LABEL_53;
            }
            if ( v20 )
            {
              v21 = 1;
              LOBYTE(v15->field_18) = 0;
            }
          }
          v15->field_10 = 0;
          if ( v21 )
          {
            LOBYTE(v15) = 1;
LABEL_52:
            v94 = v15;
            goto LABEL_53;
          }
        }
        else
        {
LABEL_32:
          if ( *(v14 - 4) > gSystemInfo.lpMaximumApplicationAddress )
          {
            memset(&v104, 0, 0x188u);
            v68 = ATL::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>(
                    &v83,
                    (v14 + 16))->pszData;
            v16 = sub_1024280(v68);
            v17 = v83.pszData - 16;
            lpFileName = v16;
            if ( _InterlockedDecrement(v83.pszData - 1) <= 0 )
            {
              v18 = *v17;
              v68 = v17;
              (*(*v18 + 4))(v17);
            }
            v108 = *(v14 - 4);
            v113 = *v14;
            v110 = *(v14 - 4);
            PE_GetProductCopyright(lpFileName, &v118, 0x41u, &dwLen, &v120);
            wcscpy_s(&Dst, 0x41u, &gszNullString);
            v115 = 0i64;
            v19 = CreateFileW(lpFileName, 0x80000000, 3u, 0, 3u, 0, 0);
            if ( v19 != -1 )
            {
              GetFileTime(v19, &CreationTime, &LastAccessTime, &LastWriteTime);
              CloseHandle(v19);
              v115 = LastWriteTime;
              FileTimeToLocalFileTime(&LastWriteTime, &LocalFileTime);
              FileTimeToSystemTime(&LocalFileTime, &SystemTime);
              GetDateFormatW(0x400u, 1u, &SystemTime, 0, &DateStr, 64);
              GetTimeFormatW(0x400u, 2u, &SystemTime, 0, &TimeStr, 64);
              v68 = &TimeStr;
              v67 = &DateStr;
              sub_1039DE0(&Dst, L"%s %s", &DateStr, &TimeStr);
            }
            v110 = 0;
            v106 = 0;
            if ( gdwValue_4F10B8[1] == v92 )
            {
              v105 = 2;
            }
            else
            {
              v107 = 0;
              v105 = 0;
            }
            if ( PE_CheckExeFile(lpFileName, &v116, &hObject, &BaseAddress) )
              v109 |= 4u;
            if ( v86 )
            {
              v68 = lpFileName;
              v67 = *(v86 + 88);
              v122 = sub_100BB70(v67, lpFileName);
            }
            qmemcpy(&v60, &v104, 0x188u);
            sub_1017790(v90, v60);
            v11 = v88;
            v15 = 1;
            goto LABEL_52;
          }
        }
LABEL_53:
        v14 += 284;
        v91 = (v91 + 1);
        if ( v91 >= *v11 )
        {
          a1 = v94;
          break;
        }
      }
    }
    free(v11);
    v5 = v90;
  }
  v23 = v89;
  if ( !sub_104F870(a1, v5, 0, v86, v92, v89, 0, &v93) )
  {
LABEL_168:
    if ( !a1 && v93 == v87 || wParam )
      goto LABEL_172;
  }
  LOBYTE(a1) = 1;
LABEL_172:
  gdwValue_4F10B8[1] = v92;
  if ( lParam != 1 )
    SendMessageW(ghWndStatusBar, 0x40Bu, gnStatusBarItemCount - 1, &lParam);
  if ( !a1 && v95 == 1 )
    SendMessageW(v5, 0xBu, 1u, 0);
  if ( v23 )
    free(v23);
  return a1;
}
// 10A43D4: using guessed type wchar_t aRefreshingDlls[19];
// 10C10B8: using guessed type int gdwValue_4F10B8[3];
// 10CF264: using guessed type int (__stdcall *RtlDestroyQueryDebugBuffer)(_DWORD);
// 10E5720: using guessed type int gnStatusBarItemCount;

//----- (0105A540) --------------------------------------------------------
char __usercall CMainWnd::RefreshHandlesView@<al>(signed int a1@<ebx>, HWND hWnd_1, DWORD dwProcessId, void *pItem)
{
  HWND hWndIn; // esi
  unsigned int v6; // edi
  _SYSTEM_HANDLE_TABLE_ENTRY_INFO_EX *v7; // ebx
  SYSTEM_HANDLE_INFORMATION *v8; // ecx
  unsigned int i; // esi
  LPARAM v10; // eax
  HWND v11; // edi
  LPARAM v12; // esi
  char v13; // al
  LPARAM v14; // edx
  signed int v15; // eax
  unsigned int j; // esi
  char v17; // bl
  char v18; // cl
  unsigned int v19; // kr00_4
  size_t v20; // ecx
  int v21; // edi
  const wchar_t *v22; // esi
  unsigned int v23; // kr04_4
  int v24; // esi
  wchar_t *v25; // ecx
  int v26; // edx
  wchar_t v27; // ax
  unsigned int v28; // ecx
  unsigned int v29; // edx
  int v30; // edi
  wchar_t *v31; // eax
  int v32; // edx
  wchar_t v33; // cx
  int v34; // eax
  WCHAR *v35; // edx
  int v36; // eax
  WCHAR v37; // cx
  void *v38; // esp
  SYSTEM_HANDLE_INFORMATION *v39; // eax
  DWORD v40; // eax
  char v41; // [esp-10C0h] [ebp-36A4h]
  const wchar_t *v42; // [esp-Ch] [ebp-25F0h]
  WCHAR *v43; // [esp-8h] [ebp-25ECh]
  signed int v44; // [esp-4h] [ebp-25E8h]
  LPARAM v45; // [esp+Ch] [ebp-25D8h]
  int v46; // [esp+10h] [ebp-25D4h]
  int v47; // [esp+14h] [ebp-25D0h]
  LPARAM v48; // [esp+2Ch] [ebp-25B8h]
  int a5; // [esp+40h] [ebp-25A4h]
  void *pEntry; // [esp+44h] [ebp-25A0h]
  unsigned int v51; // [esp+48h] [ebp-259Ch]
  SYSTEM_HANDLE_TABLE_ENTRY_INFO *v52; // [esp+4Fh] [ebp-2595h]
  WCHAR *v53; // [esp+54h] [ebp-2590h]
  int v54; // [esp+58h] [ebp-258Ch]
  SYSTEM_HANDLE_INFORMATION *pSystemHandleInfo; // [esp+5Ch] [ebp-2588h]
  HWND hWnd; // [esp+60h] [ebp-2584h]
  char v57; // [esp+67h] [ebp-257Dh]
  char v58; // [esp+68h] [ebp-257Ch]
  int v59; // [esp+78h] [ebp-256Ch]
  int v60; // [esp+7Ch] [ebp-2568h]
  char v61; // [esp+80h] [ebp-2564h]
  ULONG_PTR v62; // [esp+8Ch] [ebp-2558h]
  PVOID v63; // [esp+90h] [ebp-2554h]
  ULONG_PTR v64; // [esp+94h] [ebp-2550h]
  ULONG v65; // [esp+98h] [ebp-254Ch]
  int v66; // [esp+9Ch] [ebp-2548h]
  wchar_t v67[64]; // [esp+A0h] [ebp-2544h]
  wchar_t v68[1024]; // [esp+120h] [ebp-24C4h]
  wchar_t v69[1028]; // [esp+920h] [ebp-1CC4h]
  char v70; // [esp+1128h] [ebp-14BCh]
  int v71; // [esp+1138h] [ebp-14ACh]
  wchar_t *v72; // [esp+114Ch] [ebp-1498h]
  wchar_t v73[64]; // [esp+1150h] [ebp-1494h]
  ULONG_PTR v74; // [esp+11D0h] [ebp-1414h]
  ULONG_PTR v75; // [esp+11D8h] [ebp-140Ch]
  wchar_t *v76; // [esp+11DCh] [ebp-1408h]
  __int16 Dst[1024]; // [esp+11E0h] [ebp-1404h]
  WCHAR pszText[256]; // [esp+19E0h] [ebp-C04h]
  __int16 Src[1024]; // [esp+1BE0h] [ebp-A04h]
  WCHAR szText[256]; // [esp+23E0h] [ebp-204h]

  hWnd = hWnd_1;
  LOBYTE(a1) = 0;
  v54 = a1;
  szText[0] = 1;
  v57 = 0;
  memset(&szText[1], 0, 0x1FEu);
  if ( !pItem && (!gConfig.dwHandleColumnCount || !gConfig.bShowLowerPane) )
    return 0;
  QuerySystemHandleInfo(pItem != 0);
  if ( pItem )
  {
    pSystemHandleInfo = gpSystemHandleInfo;
LABEL_7:
    hWndIn = hWnd;
    goto LABEL_8;
  }
  pSystemHandleInfo = gpSystemHandleInfo2;
  if ( dwProcessId == gdwValue_4F10B8[0] )
  {
    v10 = dword_10C539C;
    if ( !dword_10C539C )
      goto LABEL_7;
    v11 = hWnd;
    do
    {
      v12 = *(v10 + 0x10B8);
      v48 = v10;
      v46 = -1;
      v13 = sub_10558D0(a1, v11, &v45, v10, &v52);
      a1 = a1;
      if ( v13 )
        a1 = 1;
      v10 = v12;
    }
    while ( v12 );
    v54 = a1;
    hWndIn = v11;
  }
  else
  {
    hWndIn = hWnd;
    v57 = 1;
    SendMessageW(hWnd, WM_SETREDRAW, 0, 0);
    SendMessageW(hWnd, LVM_DELETEALLITEMS, 0, 0);
    SendMessageW(ghWndStatusBar, SB_GETTEXTW, gnStatusBarItemCount - 1, szText);
    SendMessageW(ghWndStatusBar, SB_SETTEXTW, gnStatusBarItemCount - 1, L"Refreshing handles...");
    UpdateMenuStatus(0, 5);
  }
LABEL_8:
  v6 = 0;
  v51 = 0;
  if ( !SystemHandleInfo_GetHandlesNumber(pSystemHandleInfo) )
    goto LABEL_80;
  do
  {
    GetHandleTableEntry(pSystemHandleInfo, v6, &pEntry);
    v7 = pEntry;
    if ( pItem )
      goto LABEL_46;
    if ( *(pEntry + 1) != dwProcessId )
      goto LABEL_78;
    if ( !SendMessageW(hWndIn, LVM_GETITEMCOUNT, 0, 0) )
      goto LABEL_46;
    v8 = gpSystemHandleInfo3;
    if ( gpSystemHandleInfo3 )
    {
      for ( i = 0; v8 && i < v8->NumberOfHandles; ++i )
      {
        GetHandleTableEntry(v8, i, (&v52 + 1));
        if ( *&(*(&v52 + 1))->UniqueProcessId == v7->Object && (*(&v52 + 1))->Object == v7->HandleValue )
          goto LABEL_78;
        v8 = gpSystemHandleInfo3;
      }
    }
    v14 = dword_10C539C;
    v45 = 4;
    v47 = 0;
    if ( !dword_10C539C )
    {
LABEL_31:
      if ( !gConfig.bShowUnnamedHandles && v8 )
      {
        for ( j = 0; v8 && j < v8->NumberOfHandles; ++j )
        {
          GetHandleTableEntry(v8, j, (&v52 + 1));
          if ( (*(&v52 + 1))->Object == v7->HandleValue && *&(*(&v52 + 1))->UniqueProcessId == v7->Object )
            goto LABEL_78;
          v8 = gpSystemHandleInfo3;
        }
      }
LABEL_46:
      Src[0] = 0;
      PE_QueryObject(&gpszObjectTypeNames[64 * v7->ObjectTypeIndex], v7, Src, 0x400u, &a5);
      if ( !gConfig.bShowUnnamedHandles && !Src[0] )
        goto LABEL_78;
      wcscpy_s(Dst, 0x400u, Src);
      if ( _wcsicmp(&gpszObjectTypeNames[64 * v7->ObjectTypeIndex], L"Key") )
      {
        if ( !_wcsicmp(&gpszObjectTypeNames[64 * v7->ObjectTypeIndex], L"File")
          || !_wcsicmp(&gpszObjectTypeNames[64 * v7->ObjectTypeIndex], L"Section") )
        {
          sub_1040DD0(Src);
        }
      }
      else
      {
        sub_1040EE0(Src);
      }
      if ( !pItem )
      {
        v62 = v7->UniqueProcessId;
        v64 = v7->HandleValue;
        v65 = v7->GrantedAccess;
        v63 = v7->Object;
        v66 = a5;
        wcscpy_s(v67, 0x40u, &gpszObjectTypeNames[64 * v7->ObjectTypeIndex]);
        wcscpy_s(v68, 0x400u, Dst);
        wcscpy_s(v69, 0x400u, Src);
        v60 = 0;
        if ( gdwValue_4F10B8[0] == dwProcessId )
        {
          v59 = 2;
        }
        else
        {
          v61 = 0;
          v59 = 0;
        }
        v38 = alloca(0x10C0);
        qmemcpy(&v41, &v58, 0x10C0u);
        sub_1017A90(hWnd);
        v54 = 1;
        goto LABEL_76;
      }
      if ( *pItem == 1 )
        break;
      v19 = wcslen(Src);
      v20 = wcslen(gszStringToFindLast);
      if ( v19 < v20 || (v21 = 0, (v19 - v20 + 1) <= 0) )
      {
LABEL_60:
        v24 = v7->ObjectTypeIndex;
        v25 = &gpszObjectTypeNames[64 * v24];
        v26 = (v25 + 1);
        do
        {
          v27 = *v25;
          ++v25;
        }
        while ( v27 );
        v28 = (v25 - v26) >> 1;
        v29 = wcslen(gszStringToFindLast);
        if ( v28 < v29 )
          goto LABEL_76;
        v30 = 0;
        if ( (v28 - v29 + 1) <= 0 )
          goto LABEL_76;
        while ( 1 )
        {
          v42 = &gpszObjectTypeNames[v30 + (v24 << 6)];
          if ( !_wcsnicmp(v42, gszStringToFindLast, v29) )
            break;
          v24 = v7->ObjectTypeIndex;
          ++v30;
          v31 = &gpszObjectTypeNames[64 * v24];
          v32 = (v31 + 1);
          do
          {
            v33 = *v31;
            ++v31;
          }
          while ( v33 );
          v34 = v31 - v32;
          v35 = gszStringToFindLast;
          v36 = v34 >> 1;
          v53 = &gszStringToFindLast[1];
          do
          {
            v37 = *v35;
            ++v35;
          }
          while ( v37 );
          v29 = v35 - v53;
          if ( v30 >= (v36 - v29 + 1) )
            goto LABEL_76;
        }
      }
      else
      {
        v22 = Src;
        while ( _wcsnicmp(v22, gszStringToFindLast, v20) )
        {
          ++v22;
          v23 = wcslen(Src);
          v20 = wcslen(gszStringToFindLast);
          v53 = ++v21;
          if ( v21 >= (v23 - v20 + 1) )
            goto LABEL_60;
        }
      }
      v44 = 256;
      v43 = pszText;
      v42 = 0;
      SystemProcessInfo_GetSystemProcessName(v7->UniqueProcessId, 0, pszText, 0x100u);
      v72 = _wcsdup(pszText);
      v76 = _wcsdup(Src);
      wcscpy_s(v73, 0x40u, &gpszObjectTypeNames[64 * v7->ObjectTypeIndex]);
      v74 = v7->UniqueProcessId;
      v71 = 0;
      v75 = v7->HandleValue;
      sub_10178D0(hWnd, &v70);
LABEL_76:
      if ( SendMessageW(hWnd, LVM_GETITEMCOUNT, 0, 0) == 10000 )
        break;
      v6 = v51;
      goto LABEL_78;
    }
    while ( 1 )
    {
      if ( *(v14 + 44) == v7->HandleValue )
      {
        v15 = *(v14 + 40);
        if ( v15 == v7->Object )
          break;
      }
      v14 = *(v14 + 4280);
      if ( !v14 )
        goto LABEL_31;
    }
    v17 = *(v14 + 24);
    v18 = 0;
    if ( v17 )
    {
      v15 = *(v14 + 28);
      if ( v15 < gConfig.dwHighlightDuration )
      {
        *(v14 + 16) = 2;
        *(v14 + 20) = v15;
        goto LABEL_78;
      }
      if ( v17 )
      {
        v18 = 1;
        *(v14 + 24) = 0;
      }
    }
    *(v14 + 16) = 0;
    if ( v18 )
    {
      LOBYTE(v15) = 1;
      v54 = v15;
    }
LABEL_78:
    v51 = ++v6;
    v39 = SystemHandleInfo_GetHandlesNumber(pSystemHandleInfo);
    hWndIn = hWnd;
  }
  while ( v6 < v39 );
  LOBYTE(a1) = v54;
LABEL_80:
  v40 = gdwValue_4F10B8[0];
  if ( !pItem )
    v40 = dwProcessId;
  gdwValue_4F10B8[0] = v40;
  if ( szText[0] != 1 )
    SendMessageW(ghWndStatusBar, SB_SETTEXTW, gnStatusBarItemCount - 1, szText);
  if ( !a1 && v57 == 1 )
    SendMessageW(hWnd, WM_SETREDRAW, 1u, 0);
  return a1;
}
// 10A445C: using guessed type wchar_t aRefreshingHand[22];
// 10C10B8: using guessed type int gdwValue_4F10B8[3];
// 10E5720: using guessed type int gnStatusBarItemCount;

//----- (0105AD00) --------------------------------------------------------
char __usercall CTreeList::InitTreeList@<al>(HWND hWndListCtrl, char flags)
{
  int v2; // ebp
  char v3; // di
  double v4; // st6
  double v5; // st7
  void *v6; // esp
  signed int v7; // ecx
  SYSTEM_PROCESS_INFORMATION *pSystemProcessInfoLast; // ecx
  int nSystemProcessInfoLengthLast; // edx
  std__Tree_node *Tree_node_8; // esi
  int v11; // edi
  FILETIME TimeRet; // rax
  SYSTEM_PROCESS_INFORMATION *pSystemProcessInfo_11; // eax
  unsigned int v14; // ecx
  DWORD dwNumberOfProcessors; // edx
  signed int nProcessorIndex; // esi
  int nIndex; // edi
  DWORD v18; // ecx
  DWORD v19; // edx
  LONG v20; // edx
  unsigned __int64 v21; // kr20_8
  float v22; // xmm0_4
  float v23; // xmm0_4
  double v24; // xmm1_8
  float v25; // xmm0_4
  CGraphData *v26; // eax
  float v27; // xmm0_4
  float v28; // xmm0_4
  double v29; // xmm1_8
  float v30; // xmm0_4
  CGraphData *v31; // eax
  unsigned __int64 v32; // rax
  tagTREEVIEWLISTITEMPARAM *gTreeViewListItemParam; // esi
  tagTREEVIEWLISTITEMPARAM *TreeViewListItemParam_32; // edi
  int v35; // eax
  signed int dwProcessorIdx; // edx
  __m128i v37; // xmm7
  SYSTEM_INTERRUPT_INFORMATION *gpSystemInterruptInf; // ecx
  SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *pSystemProcessorIdleCycleTimeInfo_37; // edi
  LARGE_INTEGER *v40; // eax
  __m128i v41; // xmm6
  __m128i v42; // xmm4
  __m128i v43; // xmm3
  __m128i v44; // xmm5
  int v45; // ecx
  __m128i v46; // xmm0
  __m128i v47; // xmm2
  __m128i v48; // xmm1
  __m128i v49; // xmm2
  __m128i v50; // xmm1
  __m128i v51; // xmm2
  __m128i v52; // xmm0
  __m128i v53; // xmm1
  __m128i v54; // xmm0
  __m128i v55; // xmm2
  __m128i v56; // xmm0
  __m128i v57; // xmm1
  __m128i v58; // xmm5
  __m128i v59; // xmm6
  __m128i v60; // xmm3
  __m128i v61; // xmm4
  __m128i v62; // xmm5
  __m128i v63; // xmm3
  __m128i v64; // xmm4
  __m128i v65; // xmm6
  int v66; // edi
  unsigned int v67; // esi
  LARGE_INTEGER *v68; // edi
  __int64 v69; // kr28_8
  LONGLONG v70; // kr30_8
  signed __int64 v71; // kr38_8
  unsigned __int64 v72; // kr10_8
  unsigned int v73; // eax
  SYSTEM_PROCESS_INFORMATION *pSystemProcessInfo_72; // eax
  int v75; // eax
  int v76; // ecx
  unsigned __int8 v77; // of
  bool v78; // dl
  char v79; // al
  bool v80; // cl
  char v81; // al
  unsigned int v82; // edi
  bool v83; // dl
  char v84; // al
  bool v85; // cl
  char v86; // al
  unsigned int v87; // edi
  float v88; // xmm0_4
  float v89; // xmm0_4
  float v90; // xmm1_4
  float v91; // xmm0_4
  float v92; // xmm0_4
  unsigned int v93; // edx
  tagTREEVIEWLISTITEMPARAM *TreeViewListItemParam_92; // ecx
  int v95; // eax
  float v96; // xmm0_4
  float v97; // xmm0_4
  float v98; // xmm1_4
  double v99; // ST2C_8
  CGraphData *v100; // eax
  bool v101; // cl
  char v102; // al
  char v103; // al
  signed int v104; // ecx
  char v105; // al
  signed int v106; // ecx
  char v107; // al
  char v108; // cl
  char v109; // al
  tagTREEVIEWLISTITEMPARAM *TreeViewListItemParam_108; // eax
  int v111; // esi
  tagTREEVIEWLISTITEMPARAM **TreeViewListItemParam_110; // edi
  char v113; // al
  tagTREEVIEWLISTITEMPARAM *TreeViewListItemParam_112; // edi
  int v115; // eax
  int v116; // eax
  char v117; // al
  char v118; // cl
  int v119; // edi
  SYSTEM_PROCESS_INFORMATION *pSystemProcessInfo_118; // esi
  DWORD UniqueProcessId; // eax
  DWORD v122; // edx
  LONG v123; // esi
  unsigned __int64 v124; // kr60_8
  tagTREEVIEWLISTITEMPARAM *gTreeViewListItemParam_123; // edi
  DWORD v126; // ecx
  LONG v127; // edx
  int nItemFound; // eax
  int v129; // ecx
  char v130; // al
  unsigned int v131; // edx
  DWORD v132; // kr00_4
  DWORD v133; // kr04_4
  unsigned __int64 v134; // kr68_8
  int v135; // ecx
  int v136; // edx
  float v137; // xmm0_4
  float v138; // xmm0_4
  float v139; // xmm1_4
  double v140; // xmm0_8
  float v141; // xmm0_4
  float v142; // xmm0_4
  float v143; // xmm0_4
  float v144; // xmm0_4
  float v145; // xmm1_4
  __int64 v146; // xmm0_8
  double v147; // xmm2_8
  __m128d v148; // xmm1
  __int64 v149; // xmm1_8
  bool v150; // al
  char v151; // al
  double v152; // xmm0_8
  char v153; // al
  tagTREEVIEWLISTITEMPARAM **ppTreeViewListItemParam_152; // esi
  char v155; // al
  tagTREEVIEWLISTITEMPARAM *TreeViewListItemParam_154; // esi
  char v157; // al
  unsigned int v158; // eax
  int v159; // ecx
  LONG v160; // esi
  int v161; // edx
  _DWORD *v162; // eax
  _DWORD *v163; // ecx
  _WORD *v164; // esi
  _WORD *v165; // eax
  char v166; // al
  char v167; // al
  int v168; // eax
  bool v169; // cf
  unsigned __int8 v170; // al
  unsigned __int8 v171; // al
  unsigned __int8 v172; // al
  int v173; // ecx
  char v174; // al
  unsigned __int8 v175; // al
  int v176; // esi
  int v177; // eax
  char v178; // al
  int v179; // eax
  int ArgList_16; // ST3C_4
  HMENU v181; // eax
  wchar_t *v182; // ecx
  bool v183; // al
  char v184; // al
  char v185; // al
  SYSTEM_PROCESS_INFORMATION *pSystemProcessInfo_184; // esi
  int v187; // eax
  char v188; // al
  int v189; // eax
  char v190; // al
  int v191; // eax
  char v192; // al
  int v193; // eax
  char v194; // al
  int v195; // eax
  char v196; // al
  int v197; // eax
  char v198; // al
  int v199; // eax
  char v200; // al
  int v201; // eax
  char v202; // al
  int v203; // eax
  char v204; // al
  unsigned int v205; // ecx
  int v206; // esi
  char v207; // al
  char v208; // al
  CGraphData *pGraphData_207; // edx
  int v210; // eax
  char v211; // al
  LPARAM UniqueProcessId_2; // esi
  HWND hMainWndBackup; // esi
  int v214; // eax
  char v215; // al
  int v216; // esi
  char v217; // al
  char v218; // al
  int v219; // eax
  char v220; // al
  unsigned int v221; // ecx
  int v222; // kr08_4
  unsigned int v223; // kr0C_4
  signed __int64 v224; // rax
  float v225; // xmm0_4
  unsigned int v226; // edx
  unsigned int v227; // ecx
  float v228; // xmm0_4
  double ArgList_8; // ST34_8
  double v230; // xmm0_8
  unsigned int v231; // edx
  unsigned int v232; // ecx
  char v233; // al
  char v234; // al
  unsigned __int64 v235; // kr90_8
  signed __int64 v236; // kr98_8
  signed __int64 v237; // krA0_8
  char v238; // cl
  char v239; // dl
  signed int v240; // eax
  char v241; // al
  const WCHAR **pszText; // eax
  int dwStyle; // eax
  DWORD InheritedFromUniqueProcessId; // eax
  HANDLE UniqueProcessId_1; // eax
  DWORD pGraphData_244; // ecx
  WCHAR **ppszText_245; // eax
  WCHAR *szProcessName; // eax
  HICON hIcon; // ecx
  HICON hIcon_1; // ecx
  DWORD *pGraphData_249; // ecx
  int v252; // ecx
  unsigned int v253; // edx
  unsigned int *v254; // eax
  signed int v255; // ecx
  unsigned __int64 v256; // krA8_8
  int v257; // ecx
  ULONG v258; // eax
  int v259; // edx
  _DWORD *v260; // eax
  _DWORD *v261; // ecx
  int v262; // eax
  signed int v263; // ecx
  float v264; // xmm0_4
  float v265; // xmm0_4
  float v266; // xmm1_4
  float v267; // xmm0_4
  float v268; // xmm0_4
  __int64 v269; // xmm0_8
  wchar_t *v270; // eax
  int dwItemStyle; // eax
  int ItemStyle_270; // eax
  tagNetCclrInfo *NetCclrInfo_271; // eax
  tagTREEVIEWLISTITEMPARAM *TreeViewListItemParam_272; // ecx
  tagTREEVIEWLISTITEMPARAM *TreeViewListItemParam_273; // edx
  wchar_t *v276; // eax
  DLLLISTITEMPARAM *TreeViewListItemParam_275; // ecx
  int v278; // eax
  signed __int64 v279; // krC0_8
  signed __int64 v280; // krC8_8
  signed int dwProcessorIndex; // esi
  LARGE_INTEGER *v282; // edx
  ULONG *v283; // edi
  LONGLONG v284; // krE0_8
  int v285; // eax
  LRESULT (__stdcall *SendMessageW)(HWND, UINT, WPARAM, LPARAM); // esi
  tagTREEVIEWLISTITEMPARAM *TreeViewListItemParam_285; // eax
  __int64 v288; // xmm0_8
  bool v289; // cf
  bool v290; // zf
  __int64 v291; // xmm0_8
  unsigned int v292; // esi
  unsigned int v293; // edi
  float v294; // xmm0_4
  float v295; // xmm0_4
  bool v296; // al
  char v297; // al
  double v298; // xmm0_8
  char v299; // al
  char v300; // al
  LRESULT v301; // edi
  signed int i; // esi
  double v303; // xmm0_8
  int v304; // eax
  signed int ret; // eax
  int v306; // eax
  double ArgList; // [esp+Ch] [ebp-2740h]
  char v309; // [esp+20h] [ebp-272Ch]
  LVITEMW ItemState; // [esp+2Ch] [ebp-2720h]
  LVITEMW item; // [esp+60h] [ebp-26ECh]
  int v312; // [esp+94h] [ebp-26B8h]
  double v313; // [esp+98h] [ebp-26B4h]
  LVFINDINFOW FindInfo; // [esp+A0h] [ebp-26ACh]
  __int64 v315; // [esp+B8h] [ebp-2694h]
  double v316; // [esp+C0h] [ebp-268Ch]
  __int64 v317; // [esp+C8h] [ebp-2684h]
  __int64 v318; // [esp+D0h] [ebp-267Ch]
  int bVirtualizationEnabled; // [esp+DCh] [ebp-2670h]
  int fbUIAccess; // [esp+E0h] [ebp-266Ch]
  unsigned int v321; // [esp+E4h] [ebp-2668h]
  __int64 v322; // [esp+E8h] [ebp-2664h]
  __m128i v323; // [esp+F0h] [ebp-265Ch]
  double v324; // [esp+F8h] [ebp-2654h]
  __m128i v325; // [esp+100h] [ebp-264Ch]
  __int64 v326; // [esp+108h] [ebp-2644h]
  int cbPackageFullNameLength; // [esp+110h] [ebp-263Ch]
  int v328; // [esp+114h] [ebp-2638h]
  tagTREEVIEWLISTITEMPARAM *OutBuffer; // [esp+118h] [ebp-2634h]
  tagTREEVIEWLISTITEMPARAM *TreeViewListItemParam_327; // [esp+11Ch] [ebp-2630h]
  tagTREEVIEWLISTITEMPARAM *TreeViewListItemParam_328; // [esp+120h] [ebp-262Ch]
  tagTREEVIEWLISTITEMPARAM *TreeViewListItemParam_329; // [esp+124h] [ebp-2628h]
  __int64 v333; // [esp+128h] [ebp-2624h]
  float v334; // [esp+134h] [ebp-2618h]
  double v335; // [esp+138h] [ebp-2614h]
  unsigned int v336; // [esp+140h] [ebp-260Ch]
  unsigned int v337; // [esp+144h] [ebp-2608h]
  LVITEMW Item; // [esp+148h] [ebp-2604h]
  tagTREEVIEWLISTITEMPARAM *TreeViewListItemParam_336; // [esp+17Ch] [ebp-25D0h]
  tagTREEVIEWLISTITEMPARAM *TreeViewListItemParam_337; // [esp+180h] [ebp-25CCh]
  tagTREEVIEWLISTITEMPARAM *TreeViewListItemParam_338; // [esp+184h] [ebp-25C8h]
  __int64 v342; // [esp+188h] [ebp-25C4h]
  __int64 v343; // [esp+190h] [ebp-25BCh]
  HWND hWndListCtrl_1; // [esp+198h] [ebp-25B4h]
  unsigned int v345; // [esp+19Ch] [ebp-25B0h]
  int v346; // [esp+1A0h] [ebp-25ACh]
  unsigned int v347; // [esp+1A4h] [ebp-25A8h]
  double v348; // [esp+1A8h] [ebp-25A4h]
  char bFlagsInExtendedProcessBasicInfo; // [esp+1B7h] [ebp-2595h]
  tagTREEVIEWLISTITEMPARAM *TreeViewListItemParam_347; // [esp+1B8h] [ebp-2594h]
  ULONG *v351; // [esp+1BCh] [ebp-2590h]
  unsigned int v352; // [esp+1C0h] [ebp-258Ch]
  unsigned int v353; // [esp+1C4h] [ebp-2588h]
  unsigned int v354; // [esp+1C8h] [ebp-2584h]
  char sbQueryServiceNamesInited; // [esp+1CFh] [ebp-257Dh]
  __m128i v356; // [esp+1D0h] [ebp-257Ch]
  double v357; // [esp+1D8h] [ebp-2574h]
  LARGE_INTEGER liParam; // [esp+1E8h] [ebp-2564h]
  unsigned int v359; // [esp+1F4h] [ebp-2558h]
  tagTREEVIEWLISTITEMPARAM *pItemFound; // [esp+1F8h] [ebp-2554h]
  unsigned int v361; // [esp+1FCh] [ebp-2550h]
  unsigned int v362; // [esp+200h] [ebp-254Ch]
  unsigned int variable_360; // [esp+204h] [ebp-2548h]
  wchar_t *packageFullName; // [esp+208h] [ebp-2544h]
  int v365; // [esp+20Ch] [ebp-2540h]
  unsigned int v366; // [esp+210h] [ebp-253Ch]
  unsigned int v367; // [esp+214h] [ebp-2538h]
  unsigned __int8 v368; // [esp+21Bh] [ebp-2531h]
  SYSTEM_PROCESS_INFORMATION *pSystemProcessInfo_1; // [esp+21Ch] [ebp-2530h]
  char v370; // [esp+223h] [ebp-2529h]
  tagTREEVIEWLISTITEMPARAM *ProcessHandle; // [esp+224h] [ebp-2528h]
  int v372; // [esp+228h] [ebp-2524h]
  unsigned __int8 fHungFlags; // [esp+22Fh] [ebp-251Dh]
  SHFILEINFOW FileInfo; // [esp+230h] [ebp-251Ch]
  tagTREEVIEWLISTITEMPARAM ItemParam; // [esp+4E8h] [ebp-2264h]
  tagItemWithSizeIs50H ItemWithSizeIs50H; // [esp+AA8h] [ebp-1CA4h]
  WCHAR szFullName[1024]; // [esp+AF8h] [ebp-1C54h]
  WCHAR szBuffer[1024]; // [esp+12F8h] [ebp-1454h]
  WCHAR szText[256]; // [esp+1AF8h] [ebp-C54h]
  WCHAR szDomainName[256]; // [esp+1CF8h] [ebp-A54h]
  WCHAR szUserName[256]; // [esp+1EF8h] [ebp-854h]
  WCHAR szText3[256]; // [esp+20F8h] [ebp-654h]
  WCHAR szText4[256]; // [esp+22F8h] [ebp-454h]
  WCHAR szText5[256]; // [esp+24F8h] [ebp-254h]
  WCHAR Buffer_382[34]; // [esp+26F8h] [ebp-54h]
  unsigned int v386; // [esp+273Ch] [ebp-10h]
  int v387; // [esp+2740h] [ebp-Ch]
  int v388; // [esp+2744h] [ebp-8h]
  int v389; // [esp+2748h] [ebp-4h]
  int retaddr; // [esp+274Ch] [ebp+0h]

  v387 = v2;
  v388 = retaddr;
  v6 = alloca(10008);
  v386 = &v387 ^ __security_cookie;
  v309 = v3;
  hWndListCtrl_1 = hWndListCtrl;
  fHungFlags = 0;
  v346 = 0;
  TreeViewListItemParam_327 = 0;
  szText3[0] = 0;
  TreeViewListItemParam_337 = 0;
  v335 = 0.0;
  v348 = 0.0;
  *&v342 = 0.0;
  TreeViewListItemParam_338 = 0;
  v316 = 0.0;
  v333 = 0i64;
  v326 = 0i64;
  v317 = 0i64;
  v343 = 0i64;
  liParam.QuadPart = 0i64;
  memset(&szText3[1], 0, 510u);
  v368 = 0;
  TreeViewListItemParam_336 = 0;
  v370 = 0;
  bVirtualizationEnabled = 0;
  fbUIAccess = 0;
  sbQueryServiceNamesInited = 0;
  v318 = 0i64;
  v357 = 0.0;
  PE_FlushTrace(&gProperties);
  TreeList_Item1::Reset(gTreeList_Item);
  TreeList_Item1::Reset(&gTreeList_Item[1]);
  TreeList_Item1::Reset(&gTreeList_Item[2]);
  v7 = 0;
  if ( gbShowProcessTreeLast != gConfig.bShowProcessTree )
    v7 = 1;
  gbShowProcessTreeLast = gConfig.bShowProcessTree;
  v372 = v7;
  szBuffer[0] = 0;
  memset(&ItemWithSizeIs50H, 0, 0x50u);
  pSystemProcessInfoLast = gpSystemProcessInfoLast;
  nSystemProcessInfoLengthLast = gnSystemProcessInfoLengthLast;
  Tree_node_8 = theSystemProcessInfoMap._Header;
  v11 = theSystemProcessInfoMap._Size;
  gpSystemProcessInfoLast = gpSystemProcessInfo;
  gnSystemProcessInfoLengthLast = gnSystemProcessInfoLength;
  gTimeQuerySystemInfoLast = gTimeQuerySystemInfo;
  gpSystemProcessInfo = pSystemProcessInfoLast;
  gnSystemProcessInfoLength = nSystemProcessInfoLengthLast;
  TimeRet = RequerySystemStatus(
              &gpSystemProcessInfo,
              &gnSystemProcessInfoLength,
              gpSystemPerformanceInfo,
              gpSystemInterruptInfo,
              gpSystemProcessorCycleTimeInfo,
              &theSystemProcessInfoMap,
              &v357);
  gTimeQuerySystemInfo.dwLowDateTime = TimeRet.dwLowDateTime;
  gTimeQuerySystemInfo.dwHighDateTime = TimeRet.dwHighDateTime;
  v14 = (*&TimeRet - *&gTimeQuerySystemInfoLast) >> 32;
  pSystemProcessInfo_11 = (TimeRet.dwLowDateTime - gTimeQuerySystemInfoLast.dwLowDateTime);
  pSystemProcessInfo_1 = pSystemProcessInfo_11;
  v345 = LODWORD(v357) + theSystemProcessInfoMap._Header - Tree_node_8;
  dwNumberOfProcessors = gSystemInfo.dwNumberOfProcessors;
  v367 = v14;
  v347 = (*&v357 + *&theSystemProcessInfoMap - __PAIR__(v11, Tree_node_8)) >> 32;
  if ( gSystemInfo.dwNumberOfProcessors <= 1 || (nProcessorIndex = 0, gSystemInfo.dwNumberOfProcessors <= 0) )
  {
    v357 = v313;
  }
  else
  {
    nIndex = 0;
    do
    {
      v18 = gpSystemPerformanceInfo[nIndex].IdleTime.LowPart;
      v366 = gpSystemPerformanceInfo[nIndex].KernelTime.LowPart;
      v359 = gpSystemPerformanceInfo[nIndex].KernelTime.HighPart;
      v19 = gpSystemPerformanceInfo[nIndex].UserTime.LowPart;
      v169 = v19 < v18;
      v362 = v19 - v18;
      v361 = gpSystemPerformanceInfo[nIndex].UserTime.HighPart;
      v20 = gpSystemPerformanceInfo[nIndex].IdleTime.HighPart;
      v361 -= v169 + v20;
      v169 = __CFADD__(v366, v362);
      v362 += v366;
      v361 += v359 + v169;
      v21 = __PAIR__(v359, v366) - __PAIR__(v20, v18);
      v359 = (__PAIR__(v359, v366) - __PAIR__(v20, v18)) >> 32;
      v366 = v21;
      if ( v367 | pSystemProcessInfo_1 )
      {
        v22 = (__PAIR__(v361, v362) - *&gppGraphInfo[nProcessorIndex]->field_888);
        v357 = v22 * 100.0;
        v23 = __PAIR__(v367, pSystemProcessInfo_1);
        v24 = v357 / v23;
      }
      else
      {
        v24 = 0.0;
      }
      v25 = v24;
      v26 = gppGraphInfo[nProcessorIndex];
      v26->field_888 = v362;
      v26->field_88C = v361;
      v357 = v25;
      if ( v367 | pSystemProcessInfo_1 )
      {
        v27 = (__PAIR__(v359, v366) - *&gppGraphInfo[nProcessorIndex]->field_890);
        v324 = v27 * 100.0;
        v28 = __PAIR__(v367, pSystemProcessInfo_1);
        v29 = v324 / v28;
      }
      else
      {
        v29 = 0.0;
      }
      v30 = v29;
      v31 = gppGraphInfo[nProcessorIndex];
      v31->field_890 = v366;
      v31->field_894 = v359;
      CGraphData_Update(gppGraphInfo[nProcessorIndex], gTimeQuerySystemInfo, v357, v30, 0);
      dwNumberOfProcessors = gSystemInfo.dwNumberOfProcessors;
      ++nProcessorIndex;
      ++nIndex;
    }
    while ( nProcessorIndex < gSystemInfo.dwNumberOfProcessors );
    pSystemProcessInfo_11 = pSystemProcessInfo_1;
    v14 = v367;
  }
  v32 = dwNumberOfProcessors * __PAIR__(v14, pSystemProcessInfo_11);
  gTreeViewListItemParam = gpTreeViewListItemParam;
  variable_360 = v32;
  v361 = HIDWORD(v326);
  v367 = HIDWORD(v32);
  TreeViewListItemParam_347 = gpTreeViewListItemParam;
  v334 = 0.0;
  v359 = v326;
  if ( gpTreeViewListItemParam )
  {
    while ( 1 )
    {
      if ( gTreeViewListItemParam->InheritedFromUniqueProcessId != -1 || !gTreeViewListItemParam->dwProcessId )
        gTreeViewListItemParam->m_CPUUsage = 0i64;
      v290 = gTreeViewListItemParam->dwProcessId == -10;
      TreeViewListItemParam_32 = gTreeViewListItemParam->m_Prev;
      v336 = gTreeViewListItemParam->m_Prev;
      if ( v290 )
        break;
      v116 = gTreeViewListItemParam->dwStyle;
      if ( (!(v116 & 2) || v116 & 1 && gConfig.byte_14012ADFE) && gTreeViewListItemParam->field_2C != -1 )
      {
        sub_1018570(ghWndTreeListView, gTreeViewListItemParam);
        Item.lParam = gTreeViewListItemParam;
        Item.iItem = -1;
        sub_10558D0(&v389, hWndListCtrl_1, &Item, gTreeViewListItemParam, &fHungFlags);
        LOBYTE(v372) = 1;
      }
      else
      {
        Item.lParam = gTreeViewListItemParam;
        Item.iItem = -1;
        v117 = sub_10558D0(&v389, hWndListCtrl_1, &Item, gTreeViewListItemParam, &fHungFlags);
        v118 = v372;
        if ( v117 )
          v118 = 1;
        LOBYTE(v372) = v118;
      }
      if ( !fHungFlags )
        goto LABEL_98;
      v115 = v346;
LABEL_97:
      v346 = v115 + 1;
      gTreeViewListItemParam->m_SelectedItem = TreeViewListItemParam_337;
      TreeViewListItemParam_337 = gTreeViewListItemParam;
LABEL_98:
      TreeViewListItemParam_347 = TreeViewListItemParam_32;
      gTreeViewListItemParam = TreeViewListItemParam_32;
      if ( !TreeViewListItemParam_32 )
        goto LABEL_99;
    }
    v368 = 1;
    FindInfo.flags = 1;
    FindInfo.lParam = gTreeViewListItemParam;
    Item.mask = ::SendMessageW(ghWndTreeListView, LVM_FINDITEMW, 0xFFFFFFFF, &FindInfo);
    if ( Item.iItem == -1 )
    {
      v35 = gTreeViewListItemParam->dwStyle;
      if ( v35 & 2 )
      {
        if ( !(v35 & 1) || !gConfig.byte_14012ADFE )
          sub_1017F20(ghWndTreeListView, gTreeViewListItemParam);
      }
    }
    dwProcessorIdx = 0;
    Item.lParam = gTreeViewListItemParam;
    v326 = 0i64;
    v324 = 0.0;
    v322 = 0i64;
    v357 = 0.0;
    if ( gSystemInfo.dwNumberOfProcessors <= 0 )
    {
      v66 = HIDWORD(v322);
      v353 = HIDWORD(v357);
      ProcessHandle = LODWORD(v357);
      v352 = HIDWORD(v326);
      v366 = v326;
      pItemFound = HIDWORD(v324);
      v354 = LODWORD(v324);
      pSystemProcessInfo_72 = v322;
      pSystemProcessInfo_1 = v322;
    }
    else
    {
      if ( gSystemInfo.dwNumberOfProcessors < 4 )
      {
        v66 = HIDWORD(v322);
        v353 = HIDWORD(v357);
        ProcessHandle = LODWORD(v357);
        v352 = HIDWORD(v326);
        v366 = v326;
        pItemFound = HIDWORD(v324);
        v354 = LODWORD(v324);
        pSystemProcessInfo_1 = v322;
      }
      else
      {
        v37 = 0i64;
        v365 = gSystemInfo.dwNumberOfProcessors - gSystemInfo.dwNumberOfProcessors % 4;
        gpSystemInterruptInf = gpSystemInterruptInfo;
        pSystemProcessorIdleCycleTimeInfo_37 = gpSystemProcessorCycleTimeInfo + 2;
        v40 = &gpSystemPerformanceInfo->DpcTime;
        _mm_store_si128(&v323, 0i64);
        v41 = 0i64;
        _mm_store_si128(&v325, 0i64);
        v42 = 0i64;
        _mm_store_si128(&v356, 0i64);
        v43 = 0i64;
        v44 = 0i64;
        v45 = &gpSystemInterruptInf[1].DpcCount;
        do
        {
          v46 = _mm_cvtsi32_si128(v40[8].LowPart);
          pSystemProcessorIdleCycleTimeInfo_37 += 4;
          v47 = _mm_cvtsi32_si128(v40[2].LowPart);
          v45 += 96;
          v40 += 24;
          dwProcessorIdx += 4;
          *v48.m128i_i8 = v40[-23];
          v48.m128i_i64[1] = v40[-17].QuadPart;
          v49 = _mm_unpacklo_epi32(
                  _mm_add_epi32(
                    _mm_unpacklo_epi32(v47, v46),
                    _mm_unpacklo_epi32(_mm_cvtsi32_si128(*(v45 - 120)), _mm_cvtsi32_si128(*(v45 - 96)))),
                  0i64);
          *v46.m128i_i8 = v40[-24];
          v46.m128i_i64[1] = v40[-18].QuadPart;
          v50 = _mm_add_epi64(v48, v46);
          v51 = _mm_add_epi64(v49, v356);
          v52 = v50;
          v53 = _mm_add_epi64(v50, v325);
          _mm_store_si128(&v323, _mm_add_epi64(v52, v323));
          *v52.m128i_i8 = pSystemProcessorIdleCycleTimeInfo_37[-6];
          v52.m128i_i64[1] = pSystemProcessorIdleCycleTimeInfo_37[-5].CycleTime;
          v37 = _mm_add_epi64(v37, v52);
          v54 = _mm_cvtsi32_si128(v40[-4].LowPart);
          _mm_store_si128(&v356, v51);
          v55 = _mm_unpacklo_epi32(_mm_cvtsi32_si128(v40[-10].LowPart), v54);
          v56 = _mm_cvtsi32_si128(*(v45 - 48));
          _mm_store_si128(&v325, v53);
          *v53.m128i_i8 = v40[-11];
          v53.m128i_i64[1] = v40[-5].QuadPart;
          v44 = _mm_add_epi64(
                  v44,
                  _mm_unpacklo_epi32(_mm_add_epi32(v55, _mm_unpacklo_epi32(_mm_cvtsi32_si128(*(v45 - 72)), v56)), 0i64));
          *v56.m128i_i8 = v40[-12];
          v56.m128i_i64[1] = v40[-6].QuadPart;
          v57 = _mm_add_epi64(v53, v56);
          *v56.m128i_i8 = pSystemProcessorIdleCycleTimeInfo_37[-4];
          v42 = _mm_add_epi64(v42, v57);
          v56.m128i_i64[1] = pSystemProcessorIdleCycleTimeInfo_37[-3].CycleTime;
          v43 = _mm_add_epi64(v43, v57);
          v41 = _mm_add_epi64(v41, v56);
        }
        while ( dwProcessorIdx < v365 );
        v58 = _mm_add_epi64(v44, v356);
        v59 = _mm_add_epi64(v41, v37);
        v60 = _mm_add_epi64(v43, v325);
        v61 = _mm_add_epi64(v42, v323);
        v62 = _mm_add_epi64(v58, _mm_srli_si128(v58, 8));
        v63 = _mm_add_epi64(v60, _mm_srli_si128(v60, 8));
        pSystemProcessInfo_1 = _mm_cvtsi128_si32(v62);
        v354 = _mm_cvtsi128_si32(v63);
        v64 = _mm_add_epi64(v61, _mm_srli_si128(v61, 8));
        v366 = _mm_cvtsi128_si32(v64);
        v65 = _mm_add_epi64(v59, _mm_srli_si128(v59, 8));
        ProcessHandle = _mm_cvtsi128_si32(v65);
        v66 = _mm_cvtsi128_si32(_mm_srli_si128(v62, 4));
        pItemFound = _mm_cvtsi128_si32(_mm_srli_si128(v63, 4));
        v352 = _mm_cvtsi128_si32(_mm_srli_si128(v64, 4));
        v353 = _mm_cvtsi128_si32(_mm_srli_si128(v65, 4));
      }
      v362 = v66;
      if ( dwProcessorIdx < gSystemInfo.dwNumberOfProcessors )
      {
        v67 = v362;
        v68 = &gpSystemPerformanceInfo[dwProcessorIdx].InterruptTime;
        v351 = &gpSystemInterruptInfo[dwProcessorIdx].DpcCount;
        do
        {
          v69 = (pSystemProcessInfo_1 + __PAIR__(v67, *v351 + v68[1].LowPart));
          v67 = (pSystemProcessInfo_1 + __PAIR__(v67, *v351 + v68[1].LowPart)) >> 32;
          pSystemProcessInfo_1 = v69;
          v70 = *v68 + v68[-1].QuadPart;
          v68 += 6;
          v71 = v70 + __PAIR__(v352, v366);
          v352 = (v70 + __PAIR__(v352, v366)) >> 32;
          v366 = v71;
          v72 = v70 + __PAIR__(pItemFound, v354);
          pItemFound = (v72 >> 32);
          v354 = v72;
          v73 = (gpSystemProcessorCycleTimeInfo[dwProcessorIdx].CycleTime + __PAIR__(v353, ProcessHandle)) >> 32;
          ProcessHandle = (ProcessHandle + LODWORD(gpSystemProcessorCycleTimeInfo[dwProcessorIdx++].CycleTime));
          v351 += 6;
          v353 = v73;
        }
        while ( dwProcessorIdx < gSystemInfo.dwNumberOfProcessors );
        v362 = v67;
        gTreeViewListItemParam = TreeViewListItemParam_347;
        v66 = v362;
      }
      pSystemProcessInfo_72 = pSystemProcessInfo_1;
    }
    v77 = __OFSUB__(
            v66,
            (pSystemProcessInfo_72 < LODWORD(gTreeViewListItemParam->ContextSwtiches))
          + HIDWORD(gTreeViewListItemParam->ContextSwtiches));
    v76 = (__PAIR__(v66, pSystemProcessInfo_72) - gTreeViewListItemParam->ContextSwtiches) >> 32;
    v75 = pSystemProcessInfo_72 - LODWORD(gTreeViewListItemParam->ContextSwtiches);
    if ( v76 < 0 || ((v76 < 0) ^ v77) | (v76 == 0) && !v75 )
    {
      v357 = 0.0;
      v76 = 0;
      v75 = 0;
    }
    v78 = v75 != LODWORD(gTreeViewListItemParam->ContextSwtichDelta)
       || v76 != HIDWORD(gTreeViewListItemParam->ContextSwtichDelta);
    LODWORD(gTreeViewListItemParam->ContextSwtichDelta) = v75;
    HIDWORD(gTreeViewListItemParam->ContextSwtichDelta) = v76;
    v79 = RedrawColumn(v78, ghWndTreeListView, 1092, Item.iItem);
    LOBYTE(v372) = v79 | v372;
    v80 = pSystemProcessInfo_1 != LODWORD(gTreeViewListItemParam->ContextSwtiches)
       || v66 != HIDWORD(gTreeViewListItemParam->ContextSwtiches);
    LODWORD(gTreeViewListItemParam->ContextSwtiches) = pSystemProcessInfo_1;
    HIDWORD(gTreeViewListItemParam->ContextSwtiches) = v66;
    v81 = RedrawColumn(v80, ghWndTreeListView, 1091, Item.iItem);
    LOBYTE(v372) = v81 | v372;
    v82 = v353;
    v83 = __PAIR__(v353, ProcessHandle) - gTreeViewListItemParam->Cycles != gTreeViewListItemParam->CyclesDelta;
    gTreeViewListItemParam->CyclesDelta = __PAIR__(v353, ProcessHandle) - gTreeViewListItemParam->Cycles;
    v84 = RedrawColumn(v83, ghWndTreeListView, 1200, Item.iItem);
    LOBYTE(v372) = v84 | v372;
    v85 = ProcessHandle != LODWORD(gTreeViewListItemParam->Cycles) || v82 != HIDWORD(gTreeViewListItemParam->Cycles);
    LODWORD(gTreeViewListItemParam->Cycles) = ProcessHandle;
    HIDWORD(gTreeViewListItemParam->Cycles) = v82;
    v86 = RedrawColumn(v85, ghWndTreeListView, 1195, Item.iItem);
    LOBYTE(v372) = v86 | v372;
    v87 = v352;
    if ( GetProcessorSystemCycleTime )
    {
      if ( v347 | v345 )
      {
        v88 = gTreeViewListItemParam->CyclesDelta;
        *&v365 = v88 * 100.0;
        v89 = __PAIR__(v347, v345);
        v90 = *&v365 / v89;
LABEL_59:
        v357 = v90;
        if ( v90 > 100.0 )
          v357 = db_onehundred;
        TreeViewListItemParam_92 = pItemFound;
        v93 = (__PAIR__(pItemFound, v354) - *&gTreeViewListItemParam->KernelTime) >> 32;
        v365 = v354 - gTreeViewListItemParam->KernelTime.dwLowDateTime;
        v169 = __CFADD__(v354, v359);
        v359 += v354;
        gTreeViewListItemParam->KernelTime.dwLowDateTime = v354;
        v361 += TreeViewListItemParam_92 + v169;
        v95 = v367 | variable_360;
        gTreeViewListItemParam->KernelTime.dwHighDateTime = TreeViewListItemParam_92;
        if ( v95 )
        {
          v96 = __PAIR__(v93, v365);
          *&v365 = v96 * 100.0;
          v97 = __PAIR__(v367, variable_360);
          v98 = *&v365 / v97;
        }
        else
        {
          v98 = 0.0;
        }
        CGraphData_Update(gTreeViewListItemParam->pGraphData1, gTimeQuerySystemInfo, v357, v98, 0);
        CGraphData_Update(gTreeViewListItemParam->pGraphData2, gTimeQuerySystemInfo, v99, COERCE_DOUBLE(0i64 >> 63), 0);
        v100 = gTreeViewListItemParam->pGraphDataPROCCPU;
        if ( v100 )
          CGraphData_Update(v100, gTimeQuerySystemInfo, ArgList, COERCE_DOUBLE(0i64 >> 63), 0);
        if ( gTreeViewListItemParam->dwStyle & 0x40 )
          v348 = v357 + v348;
        if ( gTreeViewListItemParam->dwProcessId )
          v335 = v357 + v335;
        if ( v357 > *&v342 )
        {
          *&v342 = v357;
          TreeViewListItemParam_338 = gTreeViewListItemParam;
        }
        v101 = v366 != LODWORD(gTreeViewListItemParam->m_CPUTime) || v87 != HIDWORD(gTreeViewListItemParam->m_CPUTime);
        LODWORD(gTreeViewListItemParam->m_CPUTime) = v366;
        HIDWORD(gTreeViewListItemParam->m_CPUTime) = v87;
        v102 = RedrawColumn(v101, ghWndTreeListView, 1087, Item.iItem);
        LOBYTE(v372) = v102 | v372;
        Item.lParam->field_10 = 0;
        v103 = RedrawColumn(1, ghWndTreeListView, 1191, Item.iItem);
        v104 = v372;
        if ( v103 )
          v104 = 1;
        v365 = v104;
        v105 = RedrawColumn(1, ghWndTreeListView, 1193, Item.iItem);
        v106 = v365;
        if ( v105 )
          v106 = 1;
        v365 = v106;
        v107 = RedrawColumn(1, ghWndTreeListView, 1330, Item.iItem);
        v108 = v365;
        if ( v107 )
          v108 = 1;
        v290 = v357 == *&gTreeViewListItemParam->m_CPU;
        LOBYTE(v372) = v108;
        *&gTreeViewListItemParam->m_CPU = v357;
        RedrawColumn(v290 == 0, ghWndTreeListView, 1055, Item.iItem);
        *&gTreeViewListItemParam->m_CPUUsage = v357 + *&gTreeViewListItemParam->m_CPUUsage;
        v109 = RedrawColumn(1, ghWndTreeListView, 1637, Item.iItem);
        LOBYTE(v372) = v109 | v372;
        v365 = &gTreeViewListItemParam->pItemParam;
        TreeViewListItemParam_108 = gTreeViewListItemParam->pItemParam;
        if ( TreeViewListItemParam_108 )
        {
          v111 = v365;
          TreeViewListItemParam_110 = v365;
          do
          {
            *&TreeViewListItemParam_108->m_CPUUsage = v357;
            v113 = RedrawColumn(1, ghWndTreeListView, 1637, *(*v111 + 44));
            TreeViewListItemParam_112 = *TreeViewListItemParam_110;
            LOBYTE(v372) = v113 | v372;
            TreeViewListItemParam_110 = &TreeViewListItemParam_112->pItemParam;
            TreeViewListItemParam_108 = *TreeViewListItemParam_110;
          }
          while ( *TreeViewListItemParam_110 );
          gTreeViewListItemParam = TreeViewListItemParam_347;
        }
        TreeViewListItemParam_32 = v336;
        v115 = v346 - 1;
        --Item.iItem;
        fHungFlags = 1;
        goto LABEL_97;
      }
    }
    else if ( v367 | variable_360 )
    {
      v91 = (__PAIR__(v352, v366) - gTreeViewListItemParam->m_CPUTime);
      *&v365 = v91 * 100.0;
      v92 = __PAIR__(v367, variable_360);
      v90 = *&v365 / v92;
      goto LABEL_59;
    }
    v90 = 0.0;
    goto LABEL_59;
  }
LABEL_99:
  v119 = HIDWORD(v333);
  pSystemProcessInfo_118 = gpSystemProcessInfo;
  v321 = v333;
  v365 = HIDWORD(v317);
  v336 = v317;
  v354 = HIDWORD(v343);
  v352 = v343;
  v353 = liParam.HighPart;
  v366 = liParam.LowPart;
  v362 = HIDWORD(v318);
  v328 = HIDWORD(v333);
  v351 = v318;
  while ( 1 )
  {
    ++ItemWithSizeIs50H.nRefCount;
    ItemWithSizeIs50H.NumberOfThreads += pSystemProcessInfo_118->NumberOfThreads;
    ItemWithSizeIs50H.HandleCount += pSystemProcessInfo_118->HandleCount;
    UniqueProcessId = pSystemProcessInfo_118->UniqueProcessId;
    pSystemProcessInfo_1 = pSystemProcessInfo_118;
    packageFullName = UniqueProcessId;
    if ( UniqueProcessId )
    {
      v122 = pSystemProcessInfo_118->KernelTime.LowPart;
      v123 = pSystemProcessInfo_118->KernelTime.HighPart;
      v124 = __PAIR__(v123, v122) + pSystemProcessInfo_1->UserTime.QuadPart + __PAIR__(v119, v321);
      v321 += v122 + pSystemProcessInfo_1->UserTime.LowPart;
      v169 = __CFADD__(v122, v359);
      v359 += v122;
      UniqueProcessId = packageFullName;
      v361 += v123 + v169;
      pSystemProcessInfo_118 = pSystemProcessInfo_1;
      v328 = HIDWORD(v124);
    }
    gTreeViewListItemParam_123 = gpTreeViewListItemParam;
    TreeViewListItemParam_328 = gpTreeViewListItemParam;
    if ( !gpTreeViewListItemParam )
    {
LABEL_108:
      HIDWORD(v343) = UniqueProcessId;
      ProcessHandle = OpenProcess(0x410u, 0, UniqueProcessId);
      OutBuffer = ProcessHandle;
      if ( !ProcessHandle )
      {
        if ( GetLastError() == ERROR_ACCESS_DENIED )
          DeviceIoControl(ghDriverHandle, CTRLCODE_QUERY_PROCESS_HANDLE, &v343 + 4, 4u, &OutBuffer, 4u, &v324 + 1, 0);
        ProcessHandle = OutBuffer;
        if ( !OutBuffer )
        {
          HIDWORD(v333) = pSystemProcessInfo_118->UniqueProcessId;
          ProcessHandle = OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, 0, HIDWORD(v333));
          TreeViewListItemParam_329 = ProcessHandle;
          if ( !ProcessHandle )
          {
            if ( GetLastError() == ERROR_ACCESS_DENIED )
              DeviceIoControl(
                ghDriverHandle,
                CTRLCODE_QUERY_PROCESS_HANDLE,
                &v333 + 4,
                4u,
                &TreeViewListItemParam_329,
                4u,
                &v326 + 1,
                0);
            ProcessHandle = TreeViewListItemParam_329;
          }
        }
      }
      memset(&ItemParam, 0, sizeof(tagTREEVIEWLISTITEMPARAM));
      ItemParam.dwProcessId = pSystemProcessInfo_118->UniqueProcessId;
      if ( pSystemProcessInfo_118->ImageName.Length )
        wcsncpy_s(szText, 256u, pSystemProcessInfo_118->ImageName.Buffer, pSystemProcessInfo_118->ImageName.Length >> 1);
      else
        wcscpy_s(szText, 256u, L"System Idle Process");
      QueryProcessUsers(
        ProcessHandle,
        pSystemProcessInfo_118->UniqueProcessId,
        &pSystemProcessInfo_118->CreateTime,
        szUserName,
        256u,
        szDomainName,
        256u,
        szText3,
        256u,
        &bVirtualizationEnabled,
        &fbUIAccess);
      if ( !szDomainName[0] || (pszText = L"\\", !szUserName[0]) )
        pszText = &gszNullString;
      wsprintfW(szFullName, L"%s%s%s", szDomainName, pszText, szUserName);
      ItemParam.pszFullUserName = _wcsdup(szText3);
      dwStyle = ItemParam.dwStyle;
      if ( bVirtualizationEnabled )
      {
        dwStyle = ItemParam.dwStyle | TVLS_VirtualizationEnabled;
        ItemParam.dwStyle |= TVLS_VirtualizationEnabled;
      }
      if ( fbUIAccess )
        ItemParam.dwStyle = dwStyle | TVLS_UIAccess;
      NtQueryInformationProcess(
        ProcessHandle,
        ProcessProtectionInformation,
        &ItemParam.bProcessProtectionInfo,
        1u,
        &v312);
      if ( IsImmersiveProcess && IsImmersiveProcess(ProcessHandle) )
      {
        if ( GetPackageFullName )
        {
          cbPackageFullNameLength = 0;
          if ( GetPackageFullName(ProcessHandle, &cbPackageFullNameLength, 0) == ERROR_INSUFFICIENT_BUFFER )
          {
            packageFullName = malloc(2 * cbPackageFullNameLength);
            if ( !GetPackageFullName(ProcessHandle, &cbPackageFullNameLength, packageFullName) )
              ItemParam.pszPackageFullName = _wcsdup(packageFullName);
            free(packageFullName);
          }
        }
        ItemParam.dwStyle |= TVLS_ProcessIsImmersive;
      }
      ItemParam.m_ProcessMemoryPriority = -1;
      ItemParam.m_ProcessIoPriority = -1;
      TreeViewListItemParam_GetSystemInfo(
        pSystemProcessInfo_118,
        ProcessHandle,
        variable_360,
        v367,
        gTimeQuerySystemInfo.dwLowDateTime,
        gTimeQuerySystemInfo.dwHighDateTime,
        &ItemParam,
        0xFFFFFFFF);
      InheritedFromUniqueProcessId = pSystemProcessInfo_118->InheritedFromUniqueProcessId;
      if ( InheritedFromUniqueProcessId )
      {
        SystemProcessInfo_GetSystemProcessName(
          InheritedFromUniqueProcessId,
          &pSystemProcessInfo_118->CreateTime,
          szText4,
          0x100u);
        wsprintf_s(Buffer_382, L"(%d)", pSystemProcessInfo_118->InheritedFromUniqueProcessId);
        wcscat_s(szText4, 0x100u, Buffer_382);
      }
      else
      {
        wsprintf(szText4, L"<None>", v309);
      }
      QueryProcessArguments(
        ProcessHandle,
        pSystemProcessInfo_118->UniqueProcessId,
        &ItemParam.pszCommandLine,
        &ItemParam.pszCurrentDirectory,
        &ItemParam.pszEnvBlock,
        &bFlagsInExtendedProcessBasicInfo);
      if ( bFlagsInExtendedProcessBasicInfo )
        ItemParam.dwStyle |= TVLS_SupportExtendedProcessBasicInfo;
      liParam.HighPart = pSystemProcessInfo_118->UniqueProcessId;
      wcscpy_s(szText5, 0x100u, &gszNullString);
      ghMainWndBackup = 0;
      if ( liParam.HighPart == GetCurrentProcessId() )
      {
        ghMainWndBackup = ghMainWnd;
        GetWindowTextW(ghMainWnd, gpszWindowText, 256);
      }
      else
      {
        gbWindowTextFlags = 0;
        gpszWindowText = szText5;
        gdwWindowTextLength = 256;
        EnumWindows(EnumChildrenWindows, liParam.HighPart);
      }
      ItemParam.hMainWndBackup = ghMainWndBackup;
      if ( ghMainWndBackup )
        ItemParam.bMainWndIsHung = IsHungAppWindow(ghMainWndBackup);
      if ( !sbQueryServiceNamesInited )
      {
        QueryServiceNames();
        sbQueryServiceNamesInited = 1;
      }
      UniqueProcessId_1 = pSystemProcessInfo_118->UniqueProcessId;
      liParam.HighPart = pSystemProcessInfo_118->UniqueProcessId;
      if ( *EnumServicesStatusExW && UniqueProcessId_1 && (pGraphData_244 = 0, gdwServiceReturned) )
      {
        ppszText_245 = gpszServiceNames + 9;
        while ( 1 )
        {
          pSystemProcessInfo_118 = pSystemProcessInfo_1;
          if ( *ppszText_245 == liParam.HighPart )
            break;
          ++pGraphData_244;
          ppszText_245 += 11;
          if ( pGraphData_244 >= gdwServiceReturned )
            goto LABEL_297;
        }
        ItemParam.dwStyle |= TVLS_SHOWSERVICE;
      }
      else
      {
LABEL_297:
        ItemParam.dwStyle &= -0x21u;
      }
      wcscpy_s(ItemParam.field_28E, 0x41u, &gszNullString);
      ItemParam.szProcessName2 = _wcsdup(szText);
      if ( !sub_103D0C0(ProcessHandle, &ItemParam) )
      {
        szProcessName = ItemParam.szProcessName;
        hIcon = 0;
        FileInfo.hIcon = 0;
        if ( ItemParam.szProcessName )
        {
          SHGetFileInfoW(ItemParam.szProcessName, 0, &FileInfo, sizeof(SHFILEINFOW), 0x101u);// SHGFI_ICON | SHGFI_SMALLICON 
          szProcessName = ItemParam.szProcessName;
          hIcon = FileInfo.hIcon;
        }
        ItemParam.hIcon = hIcon;
        hIcon_1 = 0;
        FileInfo.hIcon = 0;
        if ( szProcessName )
        {
          SHGetFileInfoW(szProcessName, 0, &FileInfo, sizeof(SHFILEINFOW), SHGFI_ICON);
          hIcon_1 = FileInfo.hIcon;
        }
        ItemParam.hFileIcon = hIcon_1;
      }
      pGraphData_249 = &pSystemProcessInfo_118->CreateTime.LowPart;
      ItemParam.ProcessBasePriority = pSystemProcessInfo_118->BasePriority;
      if ( !pSystemProcessInfo_118->InheritedFromUniqueProcessId && ItemParam.dwProcessId )
      {
        gdwProcessIdLast = ItemParam.dwProcessId;
        gCreateTimeLast.dwLowDateTime = *pGraphData_249;
        gCreateTimeLast.dwHighDateTime = pSystemProcessInfo_118->CreateTime.HighPart;
        pSystemProcessInfo_118->InheritedFromUniqueProcessId = -1;
      }
      ItemParam.InheritedFromUniqueProcessId = pSystemProcessInfo_118->InheritedFromUniqueProcessId;
      ItemParam.pItemParam = 0;
      ItemParam.HandleCount = pSystemProcessInfo_118->HandleCount;
      ItemParam.CreateTime.dwLowDateTime = *pGraphData_249;
      ItemParam.CreateTime.dwHighDateTime = pSystemProcessInfo_118->CreateTime.HighPart;
      v357 = 0.0;
      fHungFlags = 0;
      if ( GetVersion() <= 4u )
      {
        fHungFlags = 1;
        v252 = &pSystemProcessInfo_118->ReadOperationCount;
      }
      else
      {
        v252 = &pSystemProcessInfo_118[1];
      }
      packageFullName = pSystemProcessInfo_118->NumberOfThreads;
      if ( !packageFullName )
        goto LABEL_455;
      v253 = LODWORD(v357);
      v254 = (v252 + 48);
      v255 = HIDWORD(v357);
      do
      {
        v256 = *v254 + __PAIR__(v255, v253);
        v255 = v256 >> 32;
        v253 = v256;
        v254 += 16;
        packageFullName = (packageFullName - 1);
      }
      while ( packageFullName );
      if ( v255 >= 0 && (v255 > 0 || v256) )
        ItemParam.ContextSwtiches = __PAIR__(v255, v256);
      else
LABEL_455:
        ItemParam.ContextSwtiches = 0i64;
      ItemParam.m_SelectedItem = 0;
      fHungFlags = 0;
      if ( GetVersion() <= 4u )
      {
        fHungFlags = 1;
        v257 = &pSystemProcessInfo_118->ReadOperationCount;
      }
      else
      {
        v257 = &pSystemProcessInfo_118[1];
      }
      v258 = pSystemProcessInfo_118->NumberOfThreads;
      v259 = 0;
      if ( v258 )
      {
        v260 = (v257 + 56);
        packageFullName = pSystemProcessInfo_118->NumberOfThreads;
        v261 = (v257 + 52);
        gTreeViewListItemParam_123 = TreeViewListItemParam_328;
        do
        {
          if ( *v261 == 5 && *v260 == 5 )
            ++v259;
          v261 += 16;
          v260 += 16;
          packageFullName = (packageFullName - 1);
        }
        while ( packageFullName );
        v258 = pSystemProcessInfo_118->NumberOfThreads;
      }
      if ( v258 == v259 )
        ItemParam.dwStyle |= 0x80u;
      if ( PE_IsProcessInJob(ProcessHandle, ItemParam.dwProcessId, 0, 0) )
        ItemParam.dwStyle |= 0x800u;
      else
        ItemParam.dwStyle &= 0xFFFFF7FF;
      ItemParam.ProcessMitigationPolicy = Fake_GetProcessMitigationPolicy(&ItemParam, ProcessHandle);
      ItemParam.field_50 = 0;
      ItemParam.m_CPUTime = pSystemProcessInfo_118->KernelTime.QuadPart + pSystemProcessInfo_118->UserTime.QuadPart;
      ItemParam.KernelTime.dwLowDateTime = pSystemProcessInfo_118->KernelTime.LowPart;
      ItemParam.KernelTime.dwHighDateTime = pSystemProcessInfo_118->KernelTime.HighPart;
      ItemParam.field_64 = 0;
      ItemParam.PageFaultCount = pSystemProcessInfo_118->PageFaultCount;
      ItemParam.PagefileUsage = pSystemProcessInfo_118->PagefileUsage;
      ItemParam.VirtualSize = pSystemProcessInfo_118->VirtualSize;
      ItemParam.PeakPagefileUsage = pSystemProcessInfo_118->PeakPagefileUsage;
      ItemParam.WorkingSetSize = pSystemProcessInfo_118->WorkingSetSize;
      ItemParam.PeakWorkingSetSize = pSystemProcessInfo_118->PeakWorkingSetSize;
      if ( !_wcsicmp(ItemParam.szProcessName2, L"wmiprvse.exe") )
        sub_1063A00(ItemParam.dwProcessId, &ItemParam.bSupportWMIProviders);
      ItemParam.m_DPIAwareness = -1;
      if ( GetProcessDpiAwareness )
        GetProcessDpiAwareness(ProcessHandle, &ItemParam.m_DPIAwareness);
      if ( v362 <= 0 && pSystemProcessInfo_118->PagefileUsage > v351 )
      {
        v351 = pSystemProcessInfo_118->PagefileUsage;
        v362 = 0;
      }
      if ( gpfnProcessIdToSessionId )
      {
        v262 = gpfnProcessIdToSessionId(pSystemProcessInfo_118->UniqueProcessId, &ItemParam.field_64);
        v263 = ItemParam.field_64;
        if ( !v262 )
          v263 = -1;
        ItemParam.field_64 = v263;
      }
      if ( sdwValueInInitTreeList )
      {
        ItemParam.m_CPU = 0i64;
        v357 = 0.0;
LABEL_360:
        ItemParam.pszSystemName = _wcsdup(szText4);
        v270 = _wcsdup(szFullName);
        ItemParam.dwStyle |= 4u;
        ItemParam.pszName = v270;
        v290 = _wcsicmp(v270, gszMainTitle) == 0;
        dwItemStyle = ItemParam.dwStyle;
        if ( v290 )
        {
          dwItemStyle = ItemParam.dwStyle | 0x40;
          ItemParam.dwStyle |= 0x40u;
        }
        if ( gConfig.bShowAllUsers || ItemParam.dwStyle & 0x40 )
          ItemStyle_270 = dwItemStyle | 2;
        else
          ItemStyle_270 = dwItemStyle & 0xFFFFFFFD;
        ItemParam.dwStyle = ItemStyle_270;
        wcscpy_s(&ItemParam.field_68, 0x100u, szText5);
        if ( sdwValueInInitTreeList )
        {
          ItemParam.field_10 = 0;
        }
        else
        {
          if ( *&gTimeQuerySystemInfoLast <= *&ItemParam.CreateTime )
          {
            ItemParam.field_10 = 2;
          }
          else
          {
            ItemParam.field_10 = 0;
            ItemParam.m_CPU = 0i64;
          }
          ItemParam.field_14 = 0;
          LOBYTE(ItemParam.field_18) = 0;
        }
        LOBYTE(ItemParam.field_500) = 0;
        ItemParam.pNetCclrInfo = sub_102B9D0(ItemParam.dwProcessId);
        LOBYTE(ItemParam.field_508) = ProcessIsNetCclr_0(&ItemParam);
        NetCclrInfo_271 = ItemParam.pNetCclrInfo;
        if ( ItemParam.pNetCclrInfo )
        {
          if ( !v370 )
          {
            dynamic_initializer_for_gPerformanceInfoInMemory__();
            NetCclrInfo_271 = ItemParam.pNetCclrInfo;
            v370 = 1;
          }
          if ( NetCclrInfo_271 )
            ++ItemWithSizeIs50H.field_48;
        }
        sub_102C540(&ItemParam, 0xFFFFFFFF);
        ItemParam.m_GdiObjects = 0;
        ItemParam.m_UserObjects = 0;
        ItemParam.field_14 = 0;
        pItemFound = ::SendMessageW(
                       ghMainWnd,
                       WM_MSG_7EE,
                       gdwProcessIdSelected == pSystemProcessInfo_118->UniqueProcessId,
                       &ItemParam);
        TreeViewListItemParam_GetSystemInfo(
          pSystemProcessInfo_118,
          ProcessHandle,
          variable_360,
          v367,
          gTimeQuerySystemInfo.dwLowDateTime,
          gTimeQuerySystemInfo.dwHighDateTime,
          pItemFound,
          0xFFFFFFFF);
        TreeViewListItemParam_272 = pItemFound;
        TreeViewListItemParam_273 = TreeViewListItemParam_337;
        TreeViewListItemParam_337 = pItemFound;
        LOBYTE(v372) = 1;
        LODWORD(TreeViewListItemParam_337->ContextSwtichDelta) = TreeViewListItemParam_337->ContextSwtiches;
        HIDWORD(TreeViewListItemParam_272->ContextSwtichDelta) = HIDWORD(TreeViewListItemParam_272->ContextSwtiches);
        LODWORD(TreeViewListItemParam_272->CyclesDelta) = TreeViewListItemParam_272->Cycles;
        HIDWORD(TreeViewListItemParam_272->CyclesDelta) = HIDWORD(TreeViewListItemParam_272->Cycles);
        TreeViewListItemParam_272->m_SelectedItem = TreeViewListItemParam_273;
        if ( ItemParam.szProcessName && *ItemParam.szProcessName != 91 )
        {
          if ( gConfig.bVerifySignatures )
          {
            InterlockedIncrement(&TreeViewListItemParam_272->nRefCount);
            _beginthread(VerifyImageThreadProc, 0, pItemFound);
            TreeViewListItemParam_272 = pItemFound;
          }
          v276 = sub_100BB70(TreeViewListItemParam_272->pszName, TreeViewListItemParam_272->szProcessName);
          TreeViewListItemParam_275 = pItemFound;
          pItemFound->field_33C = v276;
          v278 = 2;
          if ( gConfig.bCheckVirusTotal )
            v278 = 0;
          sub_1061C30(TreeViewListItemParam_275, 1, v278);
          TreeViewListItemParam_272 = pItemFound;
        }
        if ( TreeViewListItemParam_272->dwProcessId && v357 > *&v342 )
        {
          *&v342 = v357;
          TreeViewListItemParam_338 = TreeViewListItemParam_272;
        }
        if ( ItemParam.dwStyle & 0x40 )
        {
          v279 = __PAIR__(v354, pSystemProcessInfo_118->PagefileUsage) + v352;
          v354 = (__PAIR__(v354, pSystemProcessInfo_118->PagefileUsage) + v352) >> 32;
          v352 = v279;
          v280 = __PAIR__(v353, pSystemProcessInfo_118->WorkingSetSize) + v366;
          v353 = (__PAIR__(v353, pSystemProcessInfo_118->WorkingSetSize) + v366) >> 32;
          v366 = v280;
          ++ItemWithSizeIs50H.field_34;
          ItemWithSizeIs50H.field_3C += pSystemProcessInfo_118->NumberOfThreads;
          ItemWithSizeIs50H.field_44 += pSystemProcessInfo_118->HandleCount;
          if ( ItemParam.pNetCclrInfo )
            ++ItemWithSizeIs50H.field_4C;
        }
        goto LABEL_259;
      }
      if ( GetProcessorSystemCycleTime && gdwVersion >= 2 )
      {
        if ( v347 | v345 )
        {
          v264 = pSystemProcessInfo_118->SpareLi3.QuadPart;
          *&liParam.HighPart = v264 * 100.0;
          v265 = __PAIR__(v347, v345);
          v266 = *&liParam.HighPart / v265;
LABEL_354:
          *&v269 = v266;
          v357 = v266;
          if ( v266 > 100.0 )
          {
            *&v269 = db_onehundred;
            v357 = db_onehundred;
          }
          ItemParam.m_CPU = v269;
          if ( ItemParam.dwStyle & 0x40 )
          {
            v348 = *&v269 + v348;
            *&v269 = v357;
          }
          if ( ItemParam.dwProcessId )
            v335 = *&v269 + v335;
          goto LABEL_360;
        }
      }
      else if ( v367 | variable_360 )
      {
        v267 = (pSystemProcessInfo_118->KernelTime.QuadPart + pSystemProcessInfo_118->UserTime.QuadPart);
        *&liParam.HighPart = v267 * 100.0;
        v268 = __PAIR__(v367, variable_360);
        v266 = *&liParam.HighPart / v268;
        goto LABEL_354;
      }
      v266 = 0.0;
      goto LABEL_354;
    }
    v126 = pSystemProcessInfo_118->CreateTime.LowPart;
    v127 = pSystemProcessInfo_118->CreateTime.HighPart;
    while ( gTreeViewListItemParam_123->CreateTime.dwLowDateTime != v126
         || gTreeViewListItemParam_123->CreateTime.dwHighDateTime != v127
         || gTreeViewListItemParam_123->dwProcessId != UniqueProcessId )
    {
      gTreeViewListItemParam_123 = gTreeViewListItemParam_123->m_Prev;
      TreeViewListItemParam_328 = gTreeViewListItemParam_123;
      if ( !gTreeViewListItemParam_123 )
        goto LABEL_108;
    }
    HIDWORD(v318) = UniqueProcessId;
    ProcessHandle = OpenProcess(0x2000000u, 0, UniqueProcessId);
    TreeViewListItemParam_347 = ProcessHandle;
    if ( !ProcessHandle )
    {
      if ( GetLastError() == ERROR_ACCESS_DENIED )
        DeviceIoControl(ghDriverHandle, 0x8335003C, &v318 + 4, 4u, &TreeViewListItemParam_347, 4u, &v322 + 1, 0);
      ProcessHandle = TreeViewListItemParam_347;
    }
    if ( (FindInfo.flags = 1,
          FindInfo.lParam = gTreeViewListItemParam_123,
          nItemFound = ::SendMessageW(hWndListCtrl_1, LVM_FINDITEMW, 0xFFFFFFFF, &FindInfo),
          Item.iItem = nItemFound,
          v129 = gTreeViewListItemParam_123->dwStyle,
          !(v129 & 2))
      || v129 & 1 && gConfig.byte_14012ADFE
      || nItemFound != -1 )
    {
      gTreeViewListItemParam_123->field_2C = nItemFound;
    }
    else
    {
      sub_1017F20(ghWndTreeListView, gTreeViewListItemParam_123);
    }
    v130 = TreeViewListItemParam_GetSystemInfo(
             pSystemProcessInfo_118,
             ProcessHandle,
             variable_360,
             v367,
             gTimeQuerySystemInfo.dwLowDateTime,
             gTimeQuerySystemInfo.dwHighDateTime,
             gTreeViewListItemParam_123,
             Item.iItem);
    LOBYTE(v372) = v130 | v372;
    v132 = pSystemProcessInfo_118->KernelTime.LowPart;
    v133 = pSystemProcessInfo_118->UserTime.LowPart;
    v131 = pSystemProcessInfo_118->UserTime.LowPart + pSystemProcessInfo_118->KernelTime.LowPart;
    v337 = pSystemProcessInfo_118->KernelTime.HighPart;
    v134 = __PAIR__(v337, v133) + __PAIR__(pSystemProcessInfo_118->UserTime.HighPart, v132);
    v169 = v131 < LODWORD(gTreeViewListItemParam_123->m_CPUTime);
    v135 = v131 - LODWORD(gTreeViewListItemParam_123->m_CPUTime);
    HIDWORD(v343) = v133 + v132;
    v136 = HIDWORD(v134) - (v169 + HIDWORD(gTreeViewListItemParam_123->m_CPUTime));
    packageFullName = HIDWORD(v134);
    if ( GetProcessorSystemCycleTime )
    {
      if ( !(v347 | v345) )
        goto LABEL_135;
      v137 = gTreeViewListItemParam_123->CyclesDelta;
      *&liParam.HighPart = v137 * 100.0;
      v138 = __PAIR__(v347, v345);
      v139 = *&liParam.HighPart / v138;
    }
    else
    {
      if ( !gTreeViewListItemParam_123->dwProcessId )
      {
        v140 = v357;
        TreeViewListItemParam_336 = gTreeViewListItemParam_123;
        goto LABEL_137;
      }
      if ( !(v367 | variable_360) )
      {
LABEL_135:
        v139 = 0.0;
        goto LABEL_136;
      }
      v141 = __PAIR__(v136, v135);
      *&liParam.HighPart = v141 * 100.0;
      v142 = __PAIR__(v367, variable_360);
      v139 = *&liParam.HighPart / v142;
    }
LABEL_136:
    v140 = v139;
    v357 = v139;
LABEL_137:
    if ( v140 > 100.0 )
      v357 = db_onehundred;
    if ( v367 | variable_360 )
    {
      v143 = (__PAIR__(v337, pSystemProcessInfo_118->KernelTime.LowPart) - *&gTreeViewListItemParam_123->KernelTime);
      *&liParam.HighPart = v143 * 100.0;
      v144 = __PAIR__(v367, variable_360);
      v145 = *&liParam.HighPart / v144;
    }
    else
    {
      v145 = 0.0;
    }
    v146 = gTreeViewListItemParam_123->m_Gpu2;
    v169 = *&v146 < v316;
    v290 = *&v146 == v316;
    gTreeViewListItemParam_123->KernelTime.dwLowDateTime = pSystemProcessInfo_118->KernelTime.LowPart;
    gTreeViewListItemParam_123->KernelTime.dwHighDateTime = v337;
    v147 = v145;
    if ( !v169 && !v290 )
    {
      TreeViewListItemParam_327 = gTreeViewListItemParam_123;
      v316 = *&v146;
    }
    if ( gTreeViewListItemParam_123->dwStyle & 0x40 )
      v348 = v357 + v348;
    v148 = _mm_unpckl_pd(*&v357, *&v357);
    if ( gTreeViewListItemParam_123->dwProcessId )
    {
      if ( pSystemProcessInfo_118->UserTime.QuadPart )
        CGraphData_Update(gTreeViewListItemParam_123->pGraphData1, gTimeQuerySystemInfo, v148.m128d_f64[0], v147, 0);
      else
        CGraphData_Update(
          gTreeViewListItemParam_123->pGraphData1,
          gTimeQuerySystemInfo,
          v148.m128d_f64[0],
          v148.m128d_f64[1],
          0);
      *&v149 = v357;
      v335 = v357 + v335;
      if ( v357 > *&v342 )
      {
        *&v342 = v357;
        TreeViewListItemParam_338 = gTreeViewListItemParam_123;
      }
    }
    else
    {
      CGraphData_Update(gTreeViewListItemParam_123->pGraphData1, gTimeQuerySystemInfo, 0.0, v148.m128d_f64[0], 0);
      *&v149 = v357;
    }
    v150 = *&v149 != *&gTreeViewListItemParam_123->m_CPU;
    gTreeViewListItemParam_123->m_CPU = v149;
    v151 = RedrawColumn(v150, ghWndTreeListView, IDS_CPU, Item.iItem);
    v152 = *&gTreeViewListItemParam_123->m_CPUUsage + v357;
    LOBYTE(v372) = v151 | v372;
    fHungFlags = 1;
    if ( v152 == *&gTreeViewListItemParam_123->m_CPUUsage )
      fHungFlags = 0;
    *&gTreeViewListItemParam_123->m_CPUUsage = v152;
    v153 = RedrawColumn(1, ghWndTreeListView, IDS_TREE_CPU_USAGE, Item.iItem);
    LOBYTE(v372) = v153 | v372;
    v290 = gTreeViewListItemParam_123->pItemParam == 0;
    liParam.HighPart = &gTreeViewListItemParam_123->pItemParam;
    if ( !v290 )
    {
      ppTreeViewListItemParam_152 = &gTreeViewListItemParam_123->pItemParam;
      do
      {
        *&(*ppTreeViewListItemParam_152)->m_CPUUsage = *&(*ppTreeViewListItemParam_152)->m_CPUUsage + v357;
        v155 = RedrawColumn(1, ghWndTreeListView, IDS_TREE_CPU_USAGE, (*ppTreeViewListItemParam_152)->field_2C);
        TreeViewListItemParam_154 = *ppTreeViewListItemParam_152;
        LOBYTE(v372) = v155 | v372;
        ppTreeViewListItemParam_152 = &TreeViewListItemParam_154->pItemParam;
      }
      while ( *ppTreeViewListItemParam_152 );
      pSystemProcessInfo_118 = pSystemProcessInfo_1;
    }
    v157 = RedrawColumn(fHungFlags, ghWndTreeListView, IDS_CPU_HISTORY, Item.iItem);
    LOBYTE(v372) = v157 | v372;
    --v346;
    if ( sub_103D0C0(ProcessHandle, gTreeViewListItemParam_123) )
    {
      PostMessageW(ghMainWnd, WM_MSG_7EB, Item.iItem, -1);
      RefreshTreeView();
    }
    v158 = (gTreeViewListItemParam_123->dwStyle >> 7) & 0xFFFFFF01;
    fHungFlags = 0;
    v337 = v158;
    if ( GetVersion() <= 4u )
    {
      fHungFlags = 1;
      v159 = &pSystemProcessInfo_118->ReadOperationCount;
    }
    else
    {
      v159 = &pSystemProcessInfo_118[1];
    }
    v160 = pSystemProcessInfo_118->NumberOfThreads;
    v161 = 0;
    liParam.HighPart = v160;
    if ( v160 )
    {
      v162 = (v159 + 56);
      v163 = (v159 + 52);
      do
      {
        if ( *v163 == 5 && *v162 == 5 )
          ++v161;
        v163 += 16;
        v162 += 16;
        --v160;
      }
      while ( v160 );
      v160 = liParam.HighPart;
    }
    if ( v160 == v161 )
      gTreeViewListItemParam_123->dwStyle |= 0x80u;
    else
      gTreeViewListItemParam_123->dwStyle &= -0x81u;
    if ( ((gTreeViewListItemParam_123->dwStyle >> 7) & 1) != v337 )
    {
      PostMessageW(ghMainWnd, WM_MSG_7EB, Item.iItem, -1);
      RefreshTreeView();
    }
    v164 = gTreeViewListItemParam_123->pszCommandLine;
    if ( (!v164 || !*v164) && gTreeViewListItemParam_123->field_28D < 2u )
    {
      QueryProcessArguments(
        ProcessHandle,
        gTreeViewListItemParam_123->dwProcessId,
        &gTreeViewListItemParam_123->pszCommandLine,
        &gTreeViewListItemParam_123->pszCurrentDirectory,
        &gTreeViewListItemParam_123->pszEnvBlock,
        0);
      free(v164);
      ++gTreeViewListItemParam_123->field_28D;
      v165 = gTreeViewListItemParam_123->pszCommandLine;
      if ( v165 )
      {
        if ( *v165 )
        {
          v166 = RedrawColumn(1, ghWndTreeListView, IDS_COMMAND_LINE, Item.iItem);
          LOBYTE(v372) = v166 | v372;
        }
      }
    }
    v167 = gTreeViewListItemParam_123->field_28C;
    if ( v167 < 2u )
    {
      if ( !flags )
        gTreeViewListItemParam_123->field_28C = v167 + 1;
    }
    else if ( !flags )
    {
      goto LABEL_190;
    }
    if ( PE_IsProcessInJob(ProcessHandle, gTreeViewListItemParam_123->dwProcessId, 0, 0) )
      gTreeViewListItemParam_123->dwStyle |= TVLS_ENABLEJOBS;
    else
      gTreeViewListItemParam_123->dwStyle &= -0x801u;
LABEL_190:
    if ( ProcessHandle )
    {
      liParam.HighPart = gTreeViewListItemParam_123->ProcessMitigationPolicy;
      v168 = Fake_GetProcessMitigationPolicy(gTreeViewListItemParam_123, ProcessHandle);
      gTreeViewListItemParam_123->ProcessMitigationPolicy = v168;
      if ( v168 != liParam.HighPart
        && ((v169 = v168 < BYTE4(liParam.QuadPart), v168 != BYTE4(liParam.QuadPart))
         || (v170 = BYTE1(gTreeViewListItemParam_123->ProcessMitigationPolicy),
             v169 = v170 < BYTE5(liParam.QuadPart),
             v170 != BYTE5(liParam.QuadPart))
         || (v171 = BYTE2(gTreeViewListItemParam_123->ProcessMitigationPolicy),
             v169 = v171 < BYTE6(liParam.QuadPart),
             v171 != BYTE6(liParam.QuadPart))
         || (v172 = HIBYTE(gTreeViewListItemParam_123->ProcessMitigationPolicy),
             v169 = v172 < HIBYTE(liParam.QuadPart),
             v172 != HIBYTE(liParam.QuadPart))) )
      {
        v173 = -v169 | 1;
      }
      else
      {
        v173 = 0;
      }
      v174 = RedrawColumn(v173 == 0, ghWndTreeListView, 1199, Item.iItem);
      LOBYTE(v372) = v174 | v372;
    }
    if ( gTreeViewListItemParam_123->pNetCclrInfo )
    {
LABEL_210:
      ++ItemWithSizeIs50H.field_48;
      goto LABEL_211;
    }
    v175 = gTreeViewListItemParam_123->field_500;
    if ( v175 < 2u )
    {
      if ( !flags )
        LOBYTE(gTreeViewListItemParam_123->field_500) = v175 + 1;
    }
    else if ( !flags )
    {
      goto LABEL_209;
    }
    gTreeViewListItemParam_123->pNetCclrInfo = sub_102B9D0(gTreeViewListItemParam_123->dwProcessId);
    LOBYTE(gTreeViewListItemParam_123->field_508) = ProcessIsNetCclr_0(gTreeViewListItemParam_123);
    if ( !gTreeViewListItemParam_123->pNetCclrInfo )
      goto LABEL_211;
    if ( !v370 )
    {
      dynamic_initializer_for_gPerformanceInfoInMemory__();
      v370 = 1;
    }
    PostMessageW(ghMainWnd, WM_MSG_7EB, Item.iItem, -1);
    RefreshTreeView();
LABEL_209:
    if ( gTreeViewListItemParam_123->pNetCclrInfo )
      goto LABEL_210;
LABEL_211:
    v176 = gTreeViewListItemParam_123->ProcessBasePriority;
    v177 = pSystemProcessInfo_1->BasePriority;
    gTreeViewListItemParam_123->ProcessBasePriority = v177;
    v178 = RedrawColumn(v177 != v176, ghWndTreeListView, IDS_PRIORITY, Item.iItem);
    LOBYTE(v372) = v178 | v372;
    if ( gTreeViewListItemParam_123->ProcessBasePriority != v176 )
    {
      v179 = Item.lParam->ProcessBasePriority;
      if ( v179 == 4 && !Item.lParam->m_ProcessIoPriority )
        v179 = 0;
      ArgList_16 = v179;
      v181 = GetMenu(ghMainWnd);
      sub_105EF00(v181, ArgList_16);
    }
    v182 = packageFullName;
    v183 = HIDWORD(v343) != LODWORD(gTreeViewListItemParam_123->m_CPUTime)
        || packageFullName != HIDWORD(gTreeViewListItemParam_123->m_CPUTime);
    LODWORD(gTreeViewListItemParam_123->m_CPUTime) = HIDWORD(v343);
    HIDWORD(gTreeViewListItemParam_123->m_CPUTime) = v182;
    v184 = RedrawColumn(v183, ghWndTreeListView, IDS_CPU_TIME, Item.iItem);
    LOBYTE(v372) = v184 | v372;
    if ( GetProcessDpiAwareness )
    {
      GetProcessDpiAwareness(ProcessHandle, &v317 + 4);
      v290 = HIDWORD(v317) == gTreeViewListItemParam_123->m_DPIAwareness;
      gTreeViewListItemParam_123->m_DPIAwareness = HIDWORD(v317);
      v185 = RedrawColumn(!v290, ghWndTreeListView, IDS_DPI_AWARENESS, Item.iItem);
      LOBYTE(v372) = v185 | v372;
    }
    pSystemProcessInfo_184 = pSystemProcessInfo_1;
    v187 = pSystemProcessInfo_1->HandleCount;
    v290 = v187 == gTreeViewListItemParam_123->HandleCount;
    gTreeViewListItemParam_123->HandleCount = v187;
    v188 = RedrawColumn(!v290, ghWndTreeListView, IDS_HANDLES, Item.iItem);
    LOBYTE(v372) = v188 | v372;
    v189 = pSystemProcessInfo_184->PageFaultCount - gTreeViewListItemParam_123->PageFaultCount;
    v290 = v189 == gTreeViewListItemParam_123->m_PFDelta;
    gTreeViewListItemParam_123->m_PFDelta = v189;
    v190 = RedrawColumn(!v290, ghWndTreeListView, IDS_PF_DELTA, Item.iItem);
    LOBYTE(v372) = v190 | v372;
    v191 = pSystemProcessInfo_184->PageFaultCount;
    v290 = v191 == gTreeViewListItemParam_123->PageFaultCount;
    gTreeViewListItemParam_123->PageFaultCount = v191;
    v192 = RedrawColumn(!v290, ghWndTreeListView, IDS_PAGE_FAULTS, Item.iItem);
    LOBYTE(v372) = v192 | v372;
    v193 = pSystemProcessInfo_184->WorkingSetSize;
    v290 = v193 == gTreeViewListItemParam_123->WorkingSetSize;
    gTreeViewListItemParam_123->WorkingSetSize = v193;
    v194 = RedrawColumn(!v290, ghWndTreeListView, IDS_WORKING_SET, Item.iItem);
    LOBYTE(v372) = v194 | v372;
    v195 = pSystemProcessInfo_184->PeakWorkingSetSize;
    v290 = v195 == gTreeViewListItemParam_123->PeakWorkingSetSize;
    gTreeViewListItemParam_123->PeakWorkingSetSize = v195;
    v196 = RedrawColumn(!v290, ghWndTreeListView, IDS_PEAK_WORKING_SET, Item.iItem);
    LOBYTE(v372) = v196 | v372;
    v197 = pSystemProcessInfo_184->QuotaPagedPoolUsage;
    v290 = v197 == gTreeViewListItemParam_123->m_PagedPool;
    gTreeViewListItemParam_123->m_PagedPool = v197;
    v198 = RedrawColumn(!v290, ghWndTreeListView, IDS_PAGEDPOOL, Item.iItem);
    LOBYTE(v372) = v198 | v372;
    v199 = pSystemProcessInfo_184->QuotaNonPagedPoolUsage;
    v290 = v199 == gTreeViewListItemParam_123->m_NonpagedPool;
    gTreeViewListItemParam_123->m_NonpagedPool = v199;
    v200 = RedrawColumn(!v290, ghWndTreeListView, IDS_NONPAGEDPOOL, Item.iItem);
    LOBYTE(v372) = v200 | v372;
    v201 = pSystemProcessInfo_184->PeakPagefileUsage;
    v290 = v201 == gTreeViewListItemParam_123->PeakPagefileUsage;
    gTreeViewListItemParam_123->PeakPagefileUsage = v201;
    v202 = RedrawColumn(!v290, ghWndTreeListView, IDS_PEAK_PRIVATE_BYTES, Item.iItem);
    LOBYTE(v372) = v202 | v372;
    v203 = pSystemProcessInfo_184->PagefileUsage - gTreeViewListItemParam_123->PagefileUsage;
    v290 = v203 == gTreeViewListItemParam_123->m_PrivatedDeltaBytes;
    gTreeViewListItemParam_123->m_PrivatedDeltaBytes = v203;
    v204 = RedrawColumn(!v290, ghWndTreeListView, IDS_PRIVATE_DELTA_BYTES, Item.iItem);
    LOBYTE(v372) = v204 | v372;
    v205 = pSystemProcessInfo_184->PagefileUsage;
    if ( v362 <= 0 && v205 > v351 )
    {
      v351 = pSystemProcessInfo_184->PagefileUsage;
      v362 = 0;
    }
    v290 = v205 == gTreeViewListItemParam_123->PagefileUsage;
    gTreeViewListItemParam_123->PagefileUsage = v205;
    v206 = !v290;
    v207 = RedrawColumn(v206, ghWndTreeListView, IDS_PRIVATE_BYTES, Item.iItem);
    LOBYTE(v372) = v207 | v372;
    v208 = RedrawColumn(v206, ghWndTreeListView, IDS_PRIVATE_BYTES_HISTORY, Item.iItem);
    LOBYTE(v372) = v208 | v372;
    pGraphData_207 = gTreeViewListItemParam_123->pGraphData2;
    if ( pGraphData_207
      && (gTreeViewListItemParam_123->PeakPagefileUsage >> 10)
       + qword_109D110[gTreeViewListItemParam_123->PeakPagefileUsage >> 41] >= pGraphData_207->m_dbMemorySize )
    {
      pGraphData_207->m_dbMemorySize = (((gTreeViewListItemParam_123->PeakPagefileUsage >> 10)
                                       + qword_109D110[gTreeViewListItemParam_123->PeakPagefileUsage >> 41])
                                      * 1.2);
    }
    CGraphData_Update(
      gTreeViewListItemParam_123->pGraphData2,
      gTimeQuerySystemInfo,
      (gTreeViewListItemParam_123->PagefileUsage * 0.0009765625),
      0.0,
      0);
    pSystemProcessInfo_118 = pSystemProcessInfo_1;
    v210 = pSystemProcessInfo_1->VirtualSize;
    v290 = v210 == gTreeViewListItemParam_123->VirtualSize;
    gTreeViewListItemParam_123->VirtualSize = v210;
    v211 = RedrawColumn(!v290, ghWndTreeListView, IDS_VIRTUAL_SIZE, Item.iItem);
    LOBYTE(v372) = v211 | v372;
    if ( IsColumnIDValid(ghWndTreeListView, IDS_WINDOW_TITLE) || IsColumnIDValid(ghWndTreeListView, IDS_WINDOW_STATUS) )
    {
      UniqueProcessId_2 = pSystemProcessInfo_118->UniqueProcessId;
      wcscpy_s(szText5, 0x100u, &gszNullString);
      ghMainWndBackup = 0;
      if ( UniqueProcessId_2 == GetCurrentProcessId() )
      {
        ghMainWndBackup = ghMainWnd;
        GetWindowTextW(ghMainWnd, gpszWindowText, 256);
      }
      else
      {
        gbWindowTextFlags = 0;
        gpszWindowText = szText5;
        gdwWindowTextLength = 256;
        EnumWindows(EnumChildrenWindows, UniqueProcessId_2);
      }
      hMainWndBackup = ghMainWndBackup;
      fHungFlags = gTreeViewListItemParam_123->bMainWndIsHung;
      if ( IsColumnIDValid(ghWndTreeListView, IDS_WINDOW_STATUS) && hMainWndBackup )
        fHungFlags = IsHungAppWindow(hMainWndBackup);
      v214 = wcscmp(szText5, &gTreeViewListItemParam_123->field_68);
      if ( v214 )
        v214 = -(v214 < 0) | 1;
      v290 = v214 == 0;
      v215 = fHungFlags;
      if ( !v290 || (fHungFlags = 0, v215 != gTreeViewListItemParam_123->bMainWndIsHung) )
        fHungFlags = 1;
      gTreeViewListItemParam_123->bMainWndIsHung = v215;
      wcscpy_s(&gTreeViewListItemParam_123->field_68, 0x100u, szText5);
      gTreeViewListItemParam_123->hMainWndBackup = hMainWndBackup;
      v216 = fHungFlags;
      v217 = RedrawColumn(fHungFlags, ghWndTreeListView, IDS_WINDOW_TITLE, Item.iItem);
      LOBYTE(v372) = v217 | v372;
      v218 = RedrawColumn(v216, ghWndTreeListView, IDS_WINDOW_STATUS, Item.iItem);
      pSystemProcessInfo_118 = pSystemProcessInfo_1;
      LOBYTE(v372) = v218 | v372;
    }
    v219 = pSystemProcessInfo_118->NumberOfThreads;
    v290 = v219 == gTreeViewListItemParam_123->m_NumberOfThreads;
    gTreeViewListItemParam_123->m_NumberOfThreads = v219;
    v220 = RedrawColumn(!v290, ghWndTreeListView, IDS_THREADS2, Item.iItem);
    LOBYTE(v372) = v220 | v372;
    if ( gTreeViewListItemParam_123->pGraphDataPROCCPU )
    {
      v221 = (gTreeViewListItemParam_123->DeltaWriteBytes + gTreeViewListItemParam_123->DeltaOtherBytes) >> 32;
      v222 = LODWORD(gTreeViewListItemParam_123->DeltaWriteBytes) + LODWORD(gTreeViewListItemParam_123->DeltaOtherBytes);
      v223 = gTreeViewListItemParam_123->DeltaReadBytes;
      liParam.HighPart = LODWORD(gTreeViewListItemParam_123->DeltaReadBytes) + v222;
      LODWORD(v224) = v223 + v222;
      HIDWORD(v343) = (__PAIR__(v221, v223) + __PAIR__(HIDWORD(gTreeViewListItemParam_123->DeltaReadBytes), v222)) >> 32;
      HIDWORD(v224) = HIDWORD(v343);
      if ( v224 >= gTreeViewListItemParam_123->pGraphDataPROCCPU->m_dbMemorySize )
      {
        v225 = __PAIR__(HIDWORD(v343), liParam.HighPart);
        gTreeViewListItemParam_123->pGraphDataPROCCPU->m_dbMemorySize = (v225 * 1.2);
        gTreeViewListItemParam_123->pGraphDataPROCCPU->m_Item[0].dbMemorySize = gTreeViewListItemParam_123->pGraphDataPROCCPU->m_dbMemorySize;
      }
    }
    v226 = HIDWORD(gTreeViewListItemParam_123->DeltaReadBytes);
    v227 = gTreeViewListItemParam_123->DeltaReadBytes;
    v228 = gTreeViewListItemParam_123->DeltaWriteBytes;
    *(&v343 + 1) = v228;
    ArgList_8 = v228;
    v230 = __PAIR__(v226, v227);
    v231 = HIDWORD(gTreeViewListItemParam_123->DeltaOtherBytes);
    v232 = gTreeViewListItemParam_123->DeltaOtherBytes;
    *&v230 = v230;
    *(&v343 + 1) = *&v230 + *(&v343 + 1);
    *&v230 = __PAIR__(v231, v232);
    CGraphData_Update(
      gTreeViewListItemParam_123->pGraphDataPROCCPU,
      gTimeQuerySystemInfo,
      (*(&v343 + 1) + *&v230),
      ArgList_8,
      0);
    sub_10147C0(gTreeViewListItemParam_123, &gTreeViewListItemParam_123->ReadOperationCount);
    sub_10147C0(gTreeViewListItemParam_123, &gTreeViewListItemParam_123->field_430);
    sub_10147C0(gTreeViewListItemParam_123, &gTreeViewListItemParam_123->field_498);
    v233 = RedrawColumn(1, ghWndTreeListView, IDS_IO_HISTORY, Item.iItem);
    LOBYTE(v372) = v233 | v372;
    if ( gTreeViewListItemParam_123->pNetCclrInfo && !v370 )
    {
      dynamic_initializer_for_gPerformanceInfoInMemory__();
      v370 = 1;
    }
    v234 = sub_102C540(gTreeViewListItemParam_123, Item.iItem);
    LOBYTE(v372) = v234 | v372;
    if ( gTreeViewListItemParam_123->dwStyle & 0x40 )
    {
      v235 = pSystemProcessInfo_118->KernelTime.QuadPart
           + pSystemProcessInfo_118->UserTime.QuadPart
           + __PAIR__(v365, v336);
      v365 = v235 >> 32;
      v336 = v235;
      v236 = __PAIR__(v354, pSystemProcessInfo_118->PagefileUsage) + v352;
      v354 = (__PAIR__(v354, pSystemProcessInfo_118->PagefileUsage) + v352) >> 32;
      v352 = v236;
      v237 = __PAIR__(v353, pSystemProcessInfo_118->WorkingSetSize) + v366;
      v353 = (__PAIR__(v353, pSystemProcessInfo_118->WorkingSetSize) + v366) >> 32;
      v366 = v237;
      ++ItemWithSizeIs50H.field_34;
      ItemWithSizeIs50H.field_3C += pSystemProcessInfo_118->NumberOfThreads;
      ItemWithSizeIs50H.field_44 += pSystemProcessInfo_118->HandleCount;
      if ( gTreeViewListItemParam_123->pNetCclrInfo )
        ++ItemWithSizeIs50H.field_4C;
    }
    RedrawColumn(1, ghWndTreeListView, IDS_PRIVATE_BYTES_HISTORY, Item.iItem);
    RedrawColumn(1, ghWndTreeListView, IDS_IO_HISTORY, Item.iItem);
    RedrawColumn(1, ghWndTreeListView, IDS_CPU_HISTORY, Item.iItem);
    v238 = gTreeViewListItemParam_123->field_18;
    v239 = 0;
    if ( v238 )
    {
      v240 = gTreeViewListItemParam_123->field_1C;
      if ( v240 < gConfig.dwHighlightDuration )
      {
        gTreeViewListItemParam_123->field_10 = 2;
        gTreeViewListItemParam_123->field_14 = v240;
        goto LABEL_259;
      }
      if ( v238 )
      {
        v239 = 1;
        LOBYTE(gTreeViewListItemParam_123->field_18) = 0;
      }
    }
    v241 = v372;
    if ( v239 )
      v241 = 1;
    gTreeViewListItemParam_123->field_10 = 0;
    LOBYTE(v372) = v241;
LABEL_259:
    if ( ProcessHandle )
      CloseHandle(ProcessHandle);
    if ( !pSystemProcessInfo_118->NextEntryOffset )
      break;
    v119 = v328;
    pSystemProcessInfo_118 = (pSystemProcessInfo_118 + pSystemProcessInfo_118->NextEntryOffset);
  }
  if ( v368 || !gConfig.bShowAllUsers )
  {
    SendMessageW = ::SendMessageW;
  }
  else
  {
    // 初始化tagTREEVIEWLISTITEMPARAM
    memset(&ItemParam, 0, sizeof(tagTREEVIEWLISTITEMPARAM));
    ItemParam.dwStyle |= 6u;
    dwProcessorIndex = 0;
    LOBYTE(ItemParam.ProcessMitigationPolicy) = -1;
    ItemParam.pNetCclrInfo = 0;
    ItemParam.m_ProcessIoPriority = -1;
    ItemParam.m_ProcessMemoryPriority = -1;
    ItemParam.m_SelectedItem = 0;
    ItemParam.field_10 = 0;
    ItemParam.dwProcessId = -10;
    if ( gSystemInfo.dwNumberOfProcessors > 0 )
    {
      v282 = &gpSystemPerformanceInfo->InterruptTime;
      v283 = &gpSystemInterruptInfo->DpcCount;
      do
      {
        v283 += 6;
        ItemParam.ContextSwtiches += *(v283 - 6) + v282[1].LowPart;
        ItemParam.m_CPUTime += *v282 + v282[-1].QuadPart;
        v284 = *v282 + v282[-1].QuadPart;
        v282 += 6;
        *&ItemParam.KernelTime += v284;
        v285 = (gpSystemProcessorCycleTimeInfo[dwProcessorIndex].CycleTime + ItemParam.Cycles) >> 32;
        LODWORD(ItemParam.Cycles) += LODWORD(gpSystemProcessorCycleTimeInfo[dwProcessorIndex++].CycleTime);
        HIDWORD(ItemParam.Cycles) = v285;
      }
      while ( dwProcessorIndex < gSystemInfo.dwNumberOfProcessors );
      gTreeViewListItemParam_123 = TreeViewListItemParam_328;
    }
    ItemParam.pszTitle = _wcsdup(L"Hardware Interrupts and DPCs");
    ItemParam.szProcessName2 = _wcsdup(L"Interrupts");
    ItemParam.CreateTime = gCreateTimeLast;
    ItemParam.InheritedFromUniqueProcessId = gdwProcessIdLast;
    SendMessageW = ::SendMessageW;
    ItemParam.pszSystemName = _wcsdup(L"System");
    TreeViewListItemParam_285 = ::SendMessageW(ghMainWnd, WM_MSG_7EE, gdwProcessIdSelected == 0, &ItemParam);
    TreeViewListItemParam_285->m_SelectedItem = TreeViewListItemParam_337;
  }
  if ( !gbShowProcessTreeLast
    && gConfig.dwProcessSortColumn != 1000
    && !v372
    && gConfig.dwProcessColumnMap[gConfig.dwProcessSortColumn] == 1055 )
  {
    Item.mask = LVIF_PARAM;
    Item.iItem = 1;
    Item.iSubItem = 0;
    if ( SendMessageW(hWndListCtrl_1, LVM_GETITEMW, 0, &Item) )
    {
      while ( 1 )
      {
        if ( gConfig.bProcessSortDirection )
        {
          v288 = gTreeViewListItemParam_123->m_CPU;
          v289 = *&v288 < *&Item.lParam->m_CPU;
          v290 = *&v288 == *&Item.lParam->m_CPU;
        }
        else
        {
          v291 = Item.lParam->m_CPU;
          v289 = *&v291 < *&gTreeViewListItemParam_123->m_CPU;
          v290 = *&v291 == *&gTreeViewListItemParam_123->m_CPU;
        }
        if ( !v289 && !v290 )
          break;
        ++Item.iItem;
        gTreeViewListItemParam_123 = Item.lParam;
        if ( !SendMessageW(hWndListCtrl_1, LVM_GETITEMW, 0, &Item) )
          goto LABEL_410;
      }
      LOBYTE(v372) = 1;
    }
  }
LABEL_410:
  v292 = variable_360;
  v293 = v367;
  if ( v367 | variable_360 )
  {
    v294 = (__PAIR__(v361, v359) - qword_10DBC30);
    v334 = v294 * 100.0;
    v295 = __PAIR__(v367, variable_360);
    v334 = v334 / v295;
  }
  LODWORD(qword_10DBC30) = v359;
  HIDWORD(qword_10DBC30) = v361;
  *&ItemWithSizeIs50H.field_8 = v348;
  sub_1057400(__PAIR__(v354, v352), 0, &v315, &v348);
  *&ItemWithSizeIs50H.field_18 = v5;
  LODWORD(qword_10DBA40) = v351;
  HIDWORD(qword_10DBA40) = v362;
  *&ItemWithSizeIs50H.field_28 = (__PAIR__(v353, v366) / 1024) / v348 * 100.0;
  if ( TreeViewListItemParam_336 )
  {
    v348 = 100.0 - v335;
    if ( 100.0 - v335 < 0.0 )
      v348 = 0.0;
    FindInfo.lParam = TreeViewListItemParam_336;
    FindInfo.flags = 1;
    Item.iItem = ::SendMessageW(hWndListCtrl_1, LVM_FINDITEMW, 0xFFFFFFFF, &FindInfo);
    v296 = v348 != *&TreeViewListItemParam_336->m_CPU;
    *&TreeViewListItemParam_336->m_CPU = v348;
    v297 = RedrawColumn(v296, ghWndTreeListView, IDS_CPU, Item.iItem);
    LOBYTE(v372) = v297 | v372;
    v368 = 1;
    v298 = *&TreeViewListItemParam_336->m_CPUUsage + v348;
    if ( v298 == *&TreeViewListItemParam_336->m_CPUUsage )
      v368 = 0;
    *&TreeViewListItemParam_336->m_CPUUsage = v298;
    v299 = RedrawColumn(1, ghWndTreeListView, IDS_TREE_CPU_USAGE, Item.iItem);
    LOBYTE(v372) = v299 | v372;
    v300 = RedrawColumn(v368, ghWndTreeListView, IDS_CPU_HISTORY, Item.iItem);
    LOBYTE(v372) = v300 | v372;
    CGraphData_Update(TreeViewListItemParam_336->pGraphData1, gTimeQuerySystemInfo, 0.0, v348, 0);
  }
  if ( !v372 && v346 )
  {
    v301 = ::SendMessageW(ghWndTreeListView, LVM_GETITEMCOUNT, 0, 0);
    for ( i = 0; i < v301; ++i )
      PostMessageW(ghMainWnd, WM_MSG_7EB, i, -1);
    v293 = v367;
    v292 = variable_360;
  }
  v303 = db_onehundred;
  if ( v335 <= 100.0 )
    v303 = v335;
  *&ItemWithSizeIs50H.field_0 = v303;
  sub_1060410(v5, v4, ghWndStatusBar, &ItemWithSizeIs50H, &v313, &v315);
  if ( TreeViewListItemParam_338 )
  {
    v304 = TreeViewListItemParam_338->dwProcessId;
    if ( gConfig.bShowCpuFractions )
    {
      if ( v304 <= 0 )
        wsprintfW(szBuffer, L"%02.02f%% %s", v342, TreeViewListItemParam_338->szProcessName2);
      else
        wsprintfW(
          szBuffer,
          L"%02.02f%% %s:%d",
          v342,
          TreeViewListItemParam_338->szProcessName2,
          TreeViewListItemParam_338->dwProcessId);
    }
    else if ( v304 <= 0 )
    {
      wsprintfW(szBuffer, L"%02.0f%% %s", v342, TreeViewListItemParam_338->szProcessName2);
    }
    else
    {
      wsprintfW(
        szBuffer,
        L"%02.0f%% %s:%d",
        v342,
        TreeViewListItemParam_338->szProcessName2,
        TreeViewListItemParam_338->dwProcessId);
    }
  }
  CGraphData_Update(gpGraphInfoOfCPU, gTimeQuerySystemInfo, *&ItemWithSizeIs50H.field_0, v334, szBuffer);
  if ( gdwAdapterRuntingTime )
  {
    sub_10138F0(
      gTimeQuerySystemInfo,
      __PAIR__(v293, v292) / gSystemInfo.dwNumberOfProcessors,
      gpGraphInfoOfGPU,
      TreeViewListItemParam_327,
      dword_10DBA1C,
      gpGraphInfoOfSystemMemory,
      gpGraphInfoOfDedicatedMemory);
    *(&v333 + 1) = v5;
    sub_105FD50(gpGraphInfoOfGPU, *(&v333 + 1), TreeViewListItemParam_327, v316);
  }
  if ( gIOGraphInfo.pGraphData )
    sub_10144A0(&gIOGraphInfo, gTreeList_Item);
  if ( gNetworkGraphInfo.pGraphData )
    sub_10144A0(&gNetworkGraphInfo, &gTreeList_Item[1]);
  if ( gDiskGraphInfo.pGraphData )
    sub_10144A0(&gDiskGraphInfo, &gTreeList_Item[2]);
  RedrawColumn(1, ghWndTreeListView, IDS_CPU, 0xFFFFFFFE);
  RedrawColumn(1, ghWndTreeListView, IDS_PRIVATE_BYTES, 0xFFFFFFFE);
  RedrawColumn(1, ghWndTreeListView, IDS_WORKING_SET, 0xFFFFFFFE);
  RedrawColumn(1, ghWndTreeListView, IDS_GPU2, 0xFFFFFFFE);
  sub_105FD50(gpGraphInfoOfCPU, *&ItemWithSizeIs50H.field_0, TreeViewListItemParam_338, *&v342);
  sub_105FCA0(gpGraphInfoOfMemory, *&v313);
  sub_1060360(gpGraphInfoOfPhysicalMemory, v315);
  ret = v372;
  if ( flags )
    ret = 1;
  HIDWORD(v333) = ret;
  if ( sdwValueInInitTreeList )
  {
    if ( gdwProcessId_0 == -1 )
    {
      ItemState.stateMask = 3;
      ItemState.state = 3;
      ::SendMessageW(ghWndTreeListView, LVM_SETITEMSTATE, 0, &ItemState);
    }
    else
    {
      item.iItem = 0;
      item.mask = LVIF_PARAM;
      item.iSubItem = 0;
      if ( ::SendMessageW(ghWndTreeListView, LVM_GETITEMCOUNT, 0, 0) > 0 )
      {
        while ( 1 )
        {
          ::SendMessageW(ghWndTreeListView, LVM_GETITEMW, 0, &item);
          if ( item.lParam->dwProcessId == gdwProcessId_0 )
            break;
          ++item.iItem;
          item.mask = 4;
          item.iSubItem = 0;
          v306 = ::SendMessageW(ghWndTreeListView, LVM_GETITEMCOUNT, 0, 0);
          if ( item.iItem >= v306 )
            goto LABEL_451;
        }
        ItemState.mask = 3;
        ItemState.state = 3;
        ::SendMessageW(ghWndTreeListView, LVM_SETITEMSTATE, item.iItem, &ItemState);
      }
    }
LABEL_451:
    LOBYTE(ret) = BYTE4(v333);
    sdwValueInInitTreeList = 0;
  }
  return ret;
}
// 105AD00: could not find valid save-restore pair for ebp
// 105AD00: could not find valid save-restore pair for edi
// 109CDC0: using guessed type double db_onehundred;
// 10A44C8: using guessed type wchar_t a0202fS[13];
// 10BE100: using guessed type int gdwProcessId_0;
// 10C10C8: using guessed type int sdwValueInInitTreeList;
// 10C4E54: using guessed type int gdwVersion;
// 10CB1BC: using guessed type int gdwProcessIdLast;
// 10CF280: using guessed type int (__stdcall *gpfnProcessIdToSessionId)(_DWORD, _DWORD);
// 10CF2F4: using guessed type int GetProcessorSystemCycleTime;
// 10CF36C: using guessed type int (__stdcall *GetProcessDpiAwareness)(_DWORD, _DWORD);
// 10CF374: using guessed type int gnSystemProcessInfoLengthLast;
// 10CF378: using guessed type FILETIME gTimeQuerySystemInfoLast;
// 10DBA1C: using guessed type int dword_10DBA1C;
// 10DBA40: using guessed type __int64 qword_10DBA40;
// 10DBA4C: using guessed type int (__stdcall *IsImmersiveProcess)(_DWORD);
// 10DBA5C: using guessed type char gbWindowTextFlags;
// 10DBC28: using guessed type int gbShowProcessTreeLast;
// 10DBC30: using guessed type __int64 qword_10DBC30;

//----- (0105E3B0) --------------------------------------------------------
HCURSOR __cdecl sub_105E3B0(int a1)
{
  DWORD v1; // ebx
  HWND v2; // eax
  HCURSOR result; // eax
  HCURSOR v4; // eax
  HCURSOR v5; // eax
  int v6; // ebx
  LRESULT (__stdcall *v7)(HWND, UINT, WPARAM, LPARAM); // edi
  signed int v8; // ecx
  __m128i v9; // xmm1
  char *v10; // edx
  unsigned int v11; // eax
  __m128i v12; // xmm0
  int v13; // esi
  const wchar_t *v14; // eax
  signed int v15; // esi
  int i; // edi
  int j; // esi
  const wchar_t *v18; // eax
  signed int v19; // esi
  signed int v20; // ecx
  __m128i v21; // xmm1
  char *v22; // edx
  unsigned int v23; // eax
  __m128i v24; // xmm0
  signed int k; // edi
  const wchar_t *v26; // eax
  void (__stdcall *v27)(HWND, UINT, WPARAM, LPARAM); // edi
  signed int v28; // ebx
  signed int l; // edi
  const wchar_t *v30; // eax
  LPARAM v31; // [esp+4h] [ebp-2684h]
  int v32; // [esp+Ch] [ebp-267Ch]
  wchar_t *v33; // [esp+18h] [ebp-2670h]
  int v34; // [esp+1Ch] [ebp-266Ch]
  LPARAM v35; // [esp+38h] [ebp-2650h]
  int v36; // [esp+3Ch] [ebp-264Ch]
  int v37; // [esp+40h] [ebp-2648h]
  int v38; // [esp+58h] [ebp-2630h]
  struct tagOFNW v39; // [esp+6Ch] [ebp-261Ch]
  LPARAM v40; // [esp+C4h] [ebp-25C4h]
  wchar_t *v41; // [esp+D0h] [ebp-25B8h]
  int v42; // [esp+D4h] [ebp-25B4h]
  LRESULT v43; // [esp+E4h] [ebp-25A4h]
  HCURSOR hCursor; // [esp+E8h] [ebp-25A0h]
  int v45; // [esp+ECh] [ebp-259Ch]
  LRESULT v46; // [esp+F0h] [ebp-2598h]
  HWND hWnd; // [esp+F4h] [ebp-2594h]
  FILE *File; // [esp+F8h] [ebp-2590h]
  int lParam[4]; // [esp+FCh] [ebp-258Ch]
  char v50; // [esp+10Ch] [ebp-257Ch]
  wchar_t v51; // [esp+27Ch] [ebp-240Ch]
  __int16 v52; // [esp+227Ah] [ebp-40Eh]
  wchar_t pszText; // [esp+227Ch] [ebp-40Ch]
  wchar_t Dst; // [esp+247Ch] [ebp-20Ch]
  char v55; // [esp+247Eh] [ebp-20Ah]

  Dst = 0;
  memset(&v55, 0, 0x206u);
  v1 = gdwProcessIdSelected;
  v46 = gdwProcessIdSelected;
  SystemProcessInfo_GetSystemProcessName(gdwProcessIdSelected, 0, &pszText, 0x100u);
  v2 = ghWndHandlesListCtrl;
  if ( gConfig.bShowDllView )
    v2 = ghWndDllsListCtrl;
  hWnd = v2;
  if ( !a1 && dword_10E54FC )
  {
    wcscpy_s(&Dst, 0x104u, &word_10E5500);
LABEL_12:
    if ( v1 != gdwProcessIdSelected )
      return MessageBoxW(ghMainWnd, L"The process has exited", L"Process Explorer", 0x10u);
    if ( _wfopen_s(&File, &Dst, L"w, ccs=UTF-8") )
    {
      wsprintfW(&v51, L"Error saving %s", &Dst);
      result = ReportMsg(&v51, ghMainWnd);
    }
    else
    {
      v4 = hInstance;
      if ( !hInstance )
      {
        v4 = LoadCursorW(hInstance, 0x7F02);
        hInstance = v4;
      }
      v5 = SetCursor(v4);
      v6 = gConfig.dwProcessColumnCount;
      v7 = SendMessageW;
      hCursor = v5;
      v41 = &v51;
      v40 = 4;
      v42 = 4096;
      if ( !SendMessageW(ghWndTreeListView, 0x103Bu, gConfig.dwProcessColumnCount, lParam) )
      {
        v8 = 0;
        if ( v6 > 0 )
        {
          if ( v6 >= 8 )
          {
            v9 = _mm_load_si128(&gIntArray);
            v10 = &v50;
            do
            {
              v11 = v8 + 4;
              v10 += 32;
              v12 = _mm_add_epi32(_mm_shuffle_epi32(_mm_cvtsi32_si128(v8), 0), v9);
              v8 += 8;
              _mm_storeu_si128(v10 - 3, v12);
              _mm_storeu_si128(v10 - 2, _mm_add_epi32(_mm_shuffle_epi32(_mm_cvtsi32_si128(v11), 0), v9));
            }
            while ( v8 < v6 - v6 % 8 );
          }
          for ( ; v8 < v6; ++v8 )
            lParam[v8] = v8;
        }
      }
      v13 = 0;
      if ( v6 > 0 )
      {
        do
        {
          SendMessageW(ghWndTreeListView, 0x105Fu, lParam[v13], &v40);
          v14 = L"\t";
          if ( v13 == v6 - 1 )
            v14 = L"\n";
          fwprintf(File, L"%s%s", v41, v14);
          ++v13;
        }
        while ( v13 < v6 );
        v7 = SendMessageW;
      }
      v15 = 0;
      v43 = v7(ghWndTreeListView, 0x1004u, 0, 0);
      v45 = 0;
      if ( v43 > 0 )
      {
        do
        {
          v35 = 4;
          v51 = 0;
          v37 = 0;
          v36 = v15;
          v7(ghWndTreeListView, 0x104Bu, 0, &v35);
          for ( i = 0; i < v6; ++i )
          {
            v34 = 4096;
            v51 = 0;
            v32 = lParam[i];
            v33 = &v51;
            SendMessageW(ghWndTreeListView, 0x1073u, v15, &v31);
            v52 = 0;
            if ( !i && gConfig.bShowProcessTree )
            {
              for ( j = 0; j < *(v38 + 80); ++j )
                fwprintf(File, L" ");
              v15 = v45;
            }
            v18 = L"\t";
            if ( i == v6 - 1 )
              v18 = L"\n";
            fwprintf(File, L"%s%s", &v51, v18);
          }
          v7 = SendMessageW;
          v45 = ++v15;
        }
        while ( v15 < v43 );
      }
      fwprintf(File, L"\n");
      if ( v46 == gdwProcessIdSelected )
      {
        if ( gConfig.bShowLowerPane && (gdwProcessIdSelected & 0x80000000) == 0 )
        {
          fwprintf(File, L"Process: %s Pid: %d\n\n", &pszText, gdwProcessIdSelected);
          v19 = gConfig.dwHandleColumnCount;
          if ( gConfig.bShowDllView )
            v19 = gConfig.dwDllColumnCount;
          if ( !v7(hWnd, 0x103Bu, v19, lParam) )
          {
            v20 = 0;
            if ( v19 > 0 )
            {
              if ( v19 >= 8 )
              {
                v21 = _mm_load_si128(&gIntArray);
                v22 = &v50;
                do
                {
                  v23 = v20 + 4;
                  v22 += 32;
                  v24 = _mm_add_epi32(_mm_shuffle_epi32(_mm_cvtsi32_si128(v20), 0), v21);
                  v20 += 8;
                  _mm_storeu_si128(v22 - 3, v24);
                  _mm_storeu_si128(v22 - 2, _mm_add_epi32(_mm_shuffle_epi32(_mm_cvtsi32_si128(v23), 0), v21));
                }
                while ( v20 < v19 - v19 % 8 );
              }
              for ( ; v20 < v19; ++v20 )
                lParam[v20] = v20;
            }
          }
          for ( k = 0; k < v19; ++k )
          {
            SendMessageW(hWnd, 0x105Fu, lParam[k], &v40);
            v26 = L"\t";
            if ( k == v19 - 1 )
              v26 = L"\n";
            fwprintf(File, L"%s%s", v41, v26);
          }
          v27 = SendMessageW;
          v28 = 0;
          v46 = SendMessageW(hWnd, 0x1004u, 0, 0);
          if ( v46 > 0 )
          {
            do
            {
              v35 = 4;
              v51 = 0;
              v37 = 0;
              v36 = v28;
              v27(hWnd, 0x104Bu, 0, &v35);
              for ( l = 0; l < v19; ++l )
              {
                v34 = 4096;
                v51 = 0;
                v32 = lParam[l];
                v33 = &v51;
                SendMessageW(hWnd, 0x1073u, v28, &v31);
                v52 = 0;
                v30 = L"\t";
                if ( l == v19 - 1 )
                  v30 = L"\n";
                fwprintf(File, L"%s%s", &v51, v30);
              }
              v27 = SendMessageW;
              ++v28;
            }
            while ( v28 < v46 );
          }
        }
      }
      else
      {
        MessageBoxW(ghMainWnd, L"The process has exited", L"Process Explorer", 0x10u);
      }
      fclose(File);
      wcscpy_s(&word_10E5500, 0x104u, &Dst);
      dword_10E54FC = 1;
      result = SetCursor(hCursor);
    }
    return result;
  }
  if ( pszText == 60 )
    wcscpy_s(&pszText, 0x100u, L"Procexp");
  if ( word_10E5500 )
    wcscpy_s(&Dst, 0x104u, &word_10E5500);
  else
    swprintf(&Dst, L"%s.txt", &pszText);
  v39.hwndOwner = ghMainWnd;
  v39.hInstance = ghInstance;
  v39.lpstrFile = &Dst;
  *&v39.nFileOffset = 0;
  v39.lpfnHook = 0;
  v39.lStructSize = 76;
  v39.lpstrCustomFilter = 0;
  v39.nMaxCustFilter = 0;
  v39.nFilterIndex = 1;
  v39.nMaxFile = 256;
  v39.lpstrFileTitle = 0;
  v39.nMaxFileTitle = 0;
  v39.lpstrInitialDir = 0;
  v39.Flags = 2097156;
  v39.lpstrTitle = L"Save Process Explorer Data...";
  v39.lpstrDefExt = L"*.txt";
  v39.lpstrFilter = L"Process Explorer Data (*.TXT)";
  result = GetSaveFileNameW(&v39);
  if ( result )
    goto LABEL_12;
  return result;
}
// 109EA50: using guessed type RECT gIntArray;
// 10A6A18: using guessed type wchar_t aSaveProcessExp[30];
// 10A6A54: using guessed type wchar_t aTxt[6];
// 10A6A60: using guessed type wchar_t aProcessExplore_11[30];
// 10E54FC: using guessed type int dword_10E54FC;
// 105E3B0: using guessed type LPARAM lParam[4];

//----- (0105EB40) --------------------------------------------------------
HCURSOR __cdecl SaveProcessStrings(HWND hWnd, LPCWSTR lpszFileName)
{
  HCURSOR result; // eax
  HCURSOR v3; // eax
  LRESULT nCount; // ebx
  signed int i; // esi
  LVITEMW ItemText; // [esp+8h] [ebp-22D8h]
  LVITEMW Item; // [esp+3Ch] [ebp-22A4h]
  struct tagOFNW OpenFileName; // [esp+70h] [ebp-2270h]
  HWND hWndIn; // [esp+C8h] [ebp-2218h]
  HCURSOR hCursor; // [esp+CCh] [ebp-2214h]
  FILE *pFile; // [esp+D0h] [ebp-2210h]
  WCHAR szBuffer[4096]; // [esp+D4h] [ebp-220Ch]
  WCHAR szFileName[260]; // [esp+20D4h] [ebp-20Ch]

  szFileName[0] = 0;
  hWndIn = hWnd;
  memset(&szFileName[1], 0, 0x206u);
  swprintf(szFileName, L"%s.txt", lpszFileName);
  OpenFileName.hwndOwner = ghMainWnd;
  OpenFileName.hInstance = ghInstance;
  OpenFileName.lpstrFile = szFileName;
  *&OpenFileName.nFileOffset = 0;
  OpenFileName.lpfnHook = 0;
  OpenFileName.lStructSize = 76;
  OpenFileName.lpstrCustomFilter = 0;
  OpenFileName.nMaxCustFilter = 0;
  OpenFileName.nFilterIndex = 1;
  OpenFileName.nMaxFile = 256;
  OpenFileName.lpstrFileTitle = 0;
  OpenFileName.nMaxFileTitle = 0;
  OpenFileName.lpstrInitialDir = 0;
  OpenFileName.Flags = 2097156;
  OpenFileName.lpstrTitle = L"Save Process Explorer Strings...";
  OpenFileName.lpstrDefExt = L"*.txt";
  OpenFileName.lpstrFilter = L"Process Explorer Strings (*.TXT)";
  result = GetSaveFileNameW(&OpenFileName);
  if ( result )
  {
    if ( _wfopen_s(&pFile, szFileName, L"w, ccs=UTF-8") )
    {
      wsprintfW(szBuffer, L"Error saving %s", szFileName);
      result = ReportMsg(szBuffer, ghMainWnd);
    }
    else
    {
      v3 = shWaitCursor;
      if ( !shWaitCursor )
      {
        v3 = LoadCursorW(shWaitCursor, IDC_WAIT);
        shWaitCursor = v3;
      }
      hCursor = SetCursor(v3);
      nCount = SendMessageW(hWnd, LVM_GETITEMCOUNT, 0, 0);
      for ( i = 0; i < nCount; ++i )
      {
        Item.mask = 4;
        szBuffer[0] = 0;
        Item.iSubItem = 0;
        Item.iItem = i;
        SendMessageW(ghWndTreeListView, LVM_GETITEMW, 0, &Item);
        ItemText.cchTextMax = 4096;
        szBuffer[0] = 0;
        ItemText.iSubItem = 0;
        ItemText.pszText = szBuffer;
        SendMessageW(hWndIn, LVM_GETITEMTEXTW, i, &ItemText);
        szBuffer[4095] = 0;
        fwprintf(pFile, L"%s\n", szBuffer);
      }
      fclose(pFile);
      result = SetCursor(hCursor);
    }
  }
  return result;
}
// 10A6A54: using guessed type wchar_t aTxt[6];
// 10A6B60: using guessed type wchar_t aSaveProcessExp_0[33];
// 10A6BA8: using guessed type wchar_t aProcessExplore_12[33];

//----- (0105EDC0) --------------------------------------------------------
BOOL __stdcall sub_105EDC0(HWND hDlg, UINT ProcessAffinityMask, WPARAM SystemAffinityMask, LPARAM hProcess)
{
  unsigned int v5; // edi
  signed int v6; // esi
  unsigned int v7; // edi
  signed int v8; // esi
  DWORD v9; // esi
  HWND v10; // eax

  if ( ProcessAffinityMask == 272 )
  {
    ghProcess = hProcess;
    if ( GetProcessAffinityMask(hProcess, &ProcessAffinityMask, &SystemAffinityMask) )
    {
      v7 = 0;
      v8 = 1;
      do
      {
        if ( v8 & ProcessAffinityMask )
          CheckDlgButton(hDlg, v7 + 2000, 1u);
        ++v7;
        v8 = __ROL4__(v8, 1);
      }
      while ( v7 < 0x3F );
      v9 = 63;
      if ( gSystemInfo.dwNumberOfProcessors <= 0x3F )
      {
        do
        {
          v10 = GetDlgItem(hDlg, v9 + 2000);
          EnableWindow(v10, 0);
          --v9;
        }
        while ( v9 >= gSystemInfo.dwNumberOfProcessors );
      }
      return 1;
    }
    ReportMsg(L"Error retrieving process affinity", hDlg);
    EndDialog(hDlg, 0);
    return 0;
  }
  if ( ProcessAffinityMask != 273 )
    return 0;
  if ( SystemAffinityMask == 1 )
  {
    v5 = 0;
    ProcessAffinityMask = 0;
    v6 = 1;
    do
    {
      if ( IsDlgButtonChecked(hDlg, v5 + 2000) == 1 )
        ProcessAffinityMask |= v6;
      ++v5;
      v6 = __ROL4__(v6, 1);
    }
    while ( v5 < 0x1F );
    if ( !SetProcessAffinityMask(ghProcess, ProcessAffinityMask) )
      ReportMsg(L"Error setting affinity", hDlg);
  }
  else if ( SystemAffinityMask != 2 )
  {
    return 0;
  }
  EndDialog(hDlg, 0);
  return 1;
}
// 10A6708: using guessed type wchar_t aErrorRetrievin[34];
// 10A674C: using guessed type wchar_t aErrorSettingAf[23];

//----- (0105EF00) --------------------------------------------------------
int __cdecl sub_105EF00(HMENU hmenu, int a2)
{
  int result; // eax

  result = a2;
  switch ( a2 )
  {
    case 0:
      result = CheckMenuRadioItem(hmenu, 0x9CBBu, 0x9CC1u, 0x9CBCu, 0);
      break;
    case 1:
    case 2:
    case 3:
    case 4:
      result = CheckMenuRadioItem(hmenu, 0x9CBBu, 0x9CC1u, 0x9CBBu, 0);
      break;
    case 5:
    case 6:
      result = CheckMenuRadioItem(hmenu, 0x9CBBu, 0x9CC1u, 0x9CBDu, 0);
      break;
    case 7:
    case 8:
    case 9:
      result = CheckMenuRadioItem(hmenu, 0x9CBBu, 0x9CC1u, 0x9CBEu, 0);
      break;
    case 10:
    case 11:
      result = CheckMenuRadioItem(hmenu, 0x9CBBu, 0x9CC1u, 0x9CBFu, 0);
      break;
    case 12:
    case 13:
    case 14:
    case 15:
      result = CheckMenuRadioItem(hmenu, 0x9CBBu, 0x9CC1u, 0x9CC0u, 0);
      break;
    case 24:
      result = CheckMenuRadioItem(hmenu, 0x9CBBu, 0x9CC1u, 0x9CC1u, 0);
      break;
    default:
      return result;
  }
  return result;
}

//----- (0105EFB0) --------------------------------------------------------
int __cdecl sub_105EFB0(int a1)
{
  int v1; // ebx
  DWORD v3; // eax
  unsigned int v4; // ecx
  int v5; // ecx
  DWORD v6; // edi
  DWORD v7; // edx
  int v8; // ecx
  DWORD v9; // edi
  DWORD v10; // edx

  v1 = pdwValue3;
  if ( a1 > pdwValue3 )
  {
    QueryTagInformationEx(&ppv, 0, &pdwValue3, &pdwValue4);
    v1 = pdwValue3;
    if ( a1 > pdwValue3 )
      return 0;
  }
  if ( gdwVersion < 2 )
    v3 = pdwValue4 + 12 * (a1 - 1);
  else
    v3 = pdwValue4 + 16 * a1 - 16;
  v4 = *(v3 + 4);
  if ( v4 <= a1 )
  {
    if ( v4 < a1 )
    {
      v8 = a1 - 1;
      if ( a1 - 1 < v1 )
      {
        v9 = pdwValue4 + 12 * v8;
        v10 = pdwValue4 + 16 * v8;
        do
        {
          v3 = v9;
          if ( gdwVersion >= 2 )
            v3 = v10;
          if ( *(v3 + 4) == a1 )
            break;
          ++v8;
          v10 += 16;
          v9 += 12;
        }
        while ( v8 < v1 );
      }
    }
  }
  else
  {
    v5 = a1 - 1;
    if ( a1 - 1 > 0 )
    {
      v6 = pdwValue4 + 12 * v5;
      v7 = pdwValue4 + 16 * v5;
      while ( 1 )
      {
        v3 = v6;
        if ( gdwVersion >= 2 )
          v3 = v7;
        if ( *(v3 + 4) == a1 )
          break;
        --v5;
        v7 -= 16;
        v6 -= 12;
        if ( v5 <= 0 )
          return *(v3 + 8);
      }
    }
  }
  return *(v3 + 8);
}
// 10C4E54: using guessed type int gdwVersion;

//----- (0105F0A0) --------------------------------------------------------
PBOOL __cdecl PE_SuspendProcess(unsigned __int8 bFlags, DWORD dwProcessId, PBOOL pbRet)
{
  PBOOL dwError; // edi
  int i; // esi
  signed int nTry; // eax
  SYSTEM_PROCESS_INFORMATION *v6; // eax
  int v7; // eax
  SYSTEM_PROCESS_INFORMATION *pSystemProcessInfo; // [esp+Ch] [ebp-4h]

  *pbRet = 0;
  pSystemProcessInfo = 0;
  GetSystemProcessInfo(&pSystemProcessInfo, 0);
  dwError = pbRet;
  for ( i = 0; ; ++i )
  {
    nTry = NtSuspendProcess ? 1 : bFlags + 1;
    if ( i >= nTry )
      break;
    dwError = ERROR_INVALID_PARAMETER;
    v6 = pSystemProcessInfo;
    if ( pSystemProcessInfo->UniqueProcessId == dwProcessId )
    {
LABEL_9:
      v7 = PE_SuspendOneProcess(bFlags, v6, i);
      dwError = v7;
      if ( !v7 || !i && v7 == ERROR_ALREADY_WAITING )
      {
        *pbRet = 1;
        goto LABEL_17;
      }
    }
    else
    {
      while ( v6->NextEntryOffset )
      {
        v6 = (v6 + v6->NextEntryOffset);
        if ( v6->UniqueProcessId == dwProcessId )
          goto LABEL_9;
      }
    }
    if ( !*pbRet )
      break;
LABEL_17:
    if ( bFlags )
      Sleep(100u);
  }
  free(pSystemProcessInfo);
  if ( *pbRet )
    dwError = 0;
  return dwError;
}

//----- (0105F170) --------------------------------------------------------
bool __cdecl LoadDbgHelp(LPCWSTR lpLibFileName)
{
  HMODULE v1; // esi
  FARPROC v2; // eax
  int (__stdcall *v3)(HANDLE, HANDLE, PCWSTR, PCWSTR, DWORD64, DWORD, PMODLOAD_DATA, DWORD); // ecx
  int (__stdcall *v4)(HANDLE, PCSTR, BOOL); // eax
  bool v5; // zf

  v1 = LoadLibraryW(lpLibFileName);
  SymInitialize = GetProcAddress(v1, "SymInitialize");
  *EnumerateLoadedModulesW64 = GetProcAddress(v1, "EnumerateLoadedModulesW64");
  *SymRegisterCallback64 = GetProcAddress(v1, "SymRegisterCallback64");
  *SymGetModuleInfoW64 = GetProcAddress(v1, "SymGetModuleInfoW64");
  SymCleanup = GetProcAddress(v1, "SymCleanup");
  *SymFromAddrW = GetProcAddress(v1, "SymFromAddrW");
  SymGetSymFromName = GetProcAddress(v1, "SymGetSymFromName");
  MiniDumpWriteDump = GetProcAddress(v1, "MiniDumpWriteDump");
  SymSetOptions = GetProcAddress(v1, "SymSetOptions");
  *SymGetOptions = GetProcAddress(v1, "SymGetOptions");
  *SymLoadModuleExW = GetProcAddress(v1, "SymLoadModuleExW");
  if ( *SymLoadModuleExW )
  {
    SymLoadModuleExW_1 = SymLoadModuleExW_0;
  }
  else
  {
    v2 = GetProcAddress(v1, "SymLoadModule64");
    v3 = 0;
    *SymLoadModule64 = v2;
    if ( v2 )
      v3 = sub_10508E0;
    SymLoadModuleExW_1 = v3;
  }
  *SymUnloadModule64 = GetProcAddress(v1, "SymUnloadModule64");
  *ImageNtHeader = GetProcAddress(v1, "ImageNtHeader");
  *StackWalk64 = GetProcAddress(v1, "StackWalk64");
  *SymGetModuleBase64 = GetProcAddress(v1, "SymGetModuleBase64");
  *SymFunctionTableAccess64 = GetProcAddress(v1, "SymFunctionTableAccess64");
  if ( LOBYTE(gConfig.bSymbolWarningShown) )
    goto LABEL_9;
  v4 = SymInitialize;
  v5 = SymInitialize == 0;
  if ( SymInitialize )
  {
    if ( !gConfig.strNtSymbolPath[0] )
    {
LABEL_10:
      v5 = v4 == 0;
      return !v5;
    }
LABEL_9:
    SetEnvironmentVariableW(L"_NT_SYMBOL_PATH", gConfig.strNtSymbolPath);
    v4 = SymInitialize;
    goto LABEL_10;
  }
  return !v5;
}

//----- (0105F2C0) --------------------------------------------------------
BOOL __stdcall SysinfoPropSheet(HWND hDlg, UINT uMsg, WPARAM wParamIn, LPARAM lParamIn)
{
  HWND v4; // eax
  LRESULT v5; // ST14_4
  HWND v6; // eax
  int v7; // eax
  HWND v8; // eax
  CResizer *v9; // eax
  CResizer *v10; // esi
  HWND v11; // eax
  char v12; // al
  const wchar_t *TemplateName1; // ecx
  const wchar_t *v14; // eax
  bool v15; // zf
  const wchar_t *v16; // ecx
  const wchar_t *v17; // eax
  HWND v18; // eax
  HWND v19; // ebx
  LONG v20; // eax
  LONG v21; // eax
  HWND hWndTab_1; // edi
  void (__stdcall *SendMessageW)(HWND, UINT, WPARAM, LPARAM); // ecx
  const WCHAR **v24; // ebx
  WPARAM nTab; // edx
  LPARAM v26; // eax
  const WCHAR *v27; // esi
  WCHAR *v28; // eax
  HWND v29; // edi
  HWND v30; // ebx
  HWND v32; // eax
  signed int v33; // esi
  HWND v34; // eax
  HWND v35; // eax
  LRESULT nTabCount; // esi
  HWND v37; // eax
  LRESULT nCurTab; // edi
  HWND hWndTab; // eax
  HWND v40; // eax
  HWND v41; // eax
  NMHDR nmhdr; // [esp+Ch] [ebp-98h]
  HWND hWnd; // [esp+18h] [ebp-8Ch]
  TCITEMW Item; // [esp+1Ch] [ebp-88h]
  WPARAM wParam; // [esp+38h] [ebp-6Ch]
  HWND hDlg_1; // [esp+3Ch] [ebp-68h]
  LPARAM lParam_1; // [esp+40h] [ebp-64h]
  struct tagRECT Rect; // [esp+44h] [ebp-60h]
  struct tagRECT rcTab; // [esp+54h] [ebp-50h]
  SYSINFOPAGEITEM Pages[5]; // [esp+64h] [ebp-40h]

  lParam_1 = lParamIn;
  hDlg_1 = hDlg;
  if ( uMsg > WM_INITDIALOG )
  {
    if ( uMsg == WM_COMMAND )
    {
      if ( wParamIn > IDM_VIEW_REFRESH_NOW )
      {
        switch ( wParamIn )
        {
          case 40018u:
          case 40019u:
          case 40020u:
          case 40021u:
          case 40022u:
          case 40023u:
            PostMessageW(ghMainWnd, WM_COMMAND, wParamIn, lParamIn);
            break;
          case 40092u:
          case 40093u:
            v35 = GetDlgItem(hDlg, IDC_SYSINFO_PROPSHEET_TAB);
            nTabCount = ::SendMessageW(v35, TCM_GETITEMCOUNT, 0, 0);
            v37 = GetDlgItem(hDlg_1, IDC_SYSINFO_PROPSHEET_TAB);
            nCurTab = ::SendMessageW(v37, TCM_GETCURSEL, 0, 0);
            hWndTab = GetDlgItem(hDlg_1, IDC_SYSINFO_PROPSHEET_TAB);
            ::SendMessageW(hWndTab, TCM_SETCURSEL, (nTabCount + nCurTab + 2 * (wParamIn == 40092) - 1) % nTabCount, 0);
            Item.mask = TCIF_PARAM;
            Item.lParam = 0;
            v40 = GetDlgItem(hDlg_1, IDC_SYSINFO_PROPSHEET_TAB);
            ::SendMessageW(v40, TCM_GETITEMW, nCurTab, &Item);
            ShowWindow(Item.lParam, 0);
            v41 = GetDlgItem(hDlg_1, IDC_SYSINFO_PROPSHEET_TAB);
            ::SendMessageW(v41, TCM_GETITEMW, (nTabCount + nCurTab + 2 * (wParamIn == 40092) - 1) % nTabCount, &Item);
            ShowWindow(Item.lParam, SW_SHOW);
            break;
          default:
            return 0;
        }
      }
      else if ( wParamIn == IDM_VIEW_REFRESH_NOW )
      {
        SetEvent(ghRefreshEventHandle);
      }
      else if ( wParamIn > 0 && (wParamIn <= 2 || wParamIn == IDM_FILE_EXIT) )
      {
        ::SendMessageW(hDlg, WM_CLOSE, 0, 0);
      }
    }
    else if ( uMsg == WM_TIMER )
    {
      v32 = GetDlgItem(hDlg, IDC_SYSINFO_PROPSHEET_TAB);
      v33 = 0;
      lParam_1 = ::SendMessageW(v32, TCM_GETITEMCOUNT, 0, 0);
      if ( lParam_1 > 0 )
      {
        do
        {
          Item.mask = TCIF_PARAM;
          Item.lParam = 0;
          v34 = GetDlgItem(hDlg, IDC_SYSINFO_PROPSHEET_TAB);
          ::SendMessageW(v34, TCM_GETITEMW, v33, &Item);
          ::SendMessageW(Item.lParam, WM_TIMER, 0, 0);
          ++v33;
        }
        while ( v33 < lParam_1 );
      }
    }
    return 0;
  }
  if ( uMsg != WM_INITDIALOG )
  {
    if ( uMsg == WM_DESTROY )
    {
      GetWindowPlacement(hDlg, &gConfig.WindowPlacement[4]);
      v8 = GetDlgItem(hDlg, IDC_SYSINFO_PROPSHEET_TAB);
      gConfig.dwDefaultSysInfoPage = ::SendMessageW(v8, TCM_GETCURSEL, 0, 0);
      EnterCriticalSection(&gSysInfoPropSheetLock);
      ghWndSysinfoPropSheet = 0;
      LeaveCriticalSection(&gSysInfoPropSheetLock);
      _endthread();
    }
    if ( uMsg == WM_CLOSE )
    {
      DestroyWindow(hDlg);
    }
    else if ( uMsg == WM_NOTIFY && (*(lParamIn + 8) + 552) <= 1 )
    {
      v4 = GetDlgItem(hDlg, IDC_SYSINFO_PROPSHEET_TAB);
      Item.mask = 8;
      v5 = ::SendMessageW(v4, TCM_GETCURSEL, 0, 0);
      Item.lParam = 0;
      v6 = GetDlgItem(hDlg, IDC_SYSINFO_PROPSHEET_TAB);
      ::SendMessageW(v6, TCM_GETITEMW, v5, &Item);
      v7 = 0;
      if ( *(lParam_1 + 8) == -551 )
        v7 = 5;
      ShowWindow(Item.lParam, v7);
    }
    return 0;
  }
  v9 = operator new(0x40u);
  if ( v9 )
    CResizer::CResizer(v9, hDlg);
  v10 = operator new(0x40u);
  if ( v10 )
  {
    v11 = GetDlgItem(hDlg, IDC_SYSINFO_PROPSHEET_TAB);
    CResizer::CResizer(v10, v11);
  }
  Pages[0].szText = L"Summary";
  Pages[0].DlgProc = PropSummary;
  v12 = IsBuiltinAdministrative();
  Pages[1].szText = L"CPU";
  Pages[1].DlgProc = PropSystemInfoSumETW;
  TemplateName1 = L"SYSTEMINFOSUMETW";
  Pages[1].szTemplateName = L"SYSTEMINFOCPU";
  if ( !v12 )
    TemplateName1 = L"SYSTEMINFOSUM";
  Pages[2].szText = L"Memory";
  v14 = L"SYSTEMINFOMEM";
  Pages[0].szTemplateName = TemplateName1;
  if ( gdwVersion < 1 )
    v14 = L"SYSTEMINFOMEMXP";
  Pages[2].DlgProc = PropSystemInfoMem;
  Pages[2].szTemplateName = v14;
  Pages[3].szText = L"I/O";
  Pages[3].DlgProc = PropSystemInfoIO;
  v15 = IsBuiltinAdministrative() == 0;
  Pages[4].szText = L"GPU";
  Pages[4].DlgProc = PropSystemInfoGPU;
  v16 = L"SYSTEMINFOIOETW";
  v17 = L"SYSTEMINFOGPU";
  if ( v15 )
    v16 = L"SYSTEMINFOIO";
  Pages[3].szTemplateName = v16;
  if ( gdwAdapterRuntingTime <= 0 )
    v17 = 0;
  Pages[4].szTemplateName = v17;
  v18 = GetDlgItem(hDlg, IDC_SYSINFO_PROPSHEET_TAB);
  v19 = v18;
  hWnd = v18;
  v20 = GetWindowLongW(v18, -20);
  SetWindowLongW(v19, -20, v20 | 0x10000);
  v21 = GetWindowLongW(v19, -16);
  hWndTab_1 = v19;
  SetWindowLongW(v19, -16, v21 | 0x2000000);
  SendMessageW = ::SendMessageW;
  v24 = &Pages[0].szTemplateName;
  nTab = 0;
  v26 = 5;
  wParam = 0;
  lParam_1 = 5;
  do
  {
    v27 = *v24;
    if ( *v24 )
    {
      v28 = *(v24 - 2);
      _mm_storeu_si128(&Item.dwState, 0i64);
      Item.pszText = v28;
      *&Item.iImage = 0i64;
      Item.mask = 1;
      SendMessageW(hWndTab_1, TCM_INSERTITEMW, nTab, &Item);
      GetClientRect(hWndTab_1, &rcTab);
      ::SendMessageW(hWndTab_1, TCM_ADJUSTRECT, 0, &rcTab);
      v29 = CreateDialogParamW(ghInstance, v27, hWndTab_1, *(v24 - 1), 0);
      MoveWindow(v29, rcTab.left, rcTab.top, rcTab.right - rcTab.left, rcTab.bottom - rcTab.top, 1);
      ShowWindow(v29, 0);
      Item.lParam = v29;
      hWndTab_1 = hWnd;
      Item.mask = TCIF_PARAM;
      ::SendMessageW(hWnd, TCM_SETITEMW, wParam, &Item);
      v26 = lParam_1;
      nTab = wParam + 1;
      SendMessageW = ::SendMessageW;
      ++wParam;
    }
    v24 += 3;
    lParam_1 = --v26;
  }
  while ( v26 );
  SendMessageW(hWndTab_1, TCM_SETCURSEL, gConfig.dwDefaultSysInfoPage, 0);
  v30 = hDlg_1;
  nmhdr.idFrom = IDC_SYSINFO_PROPSHEET_TAB;
  nmhdr.code = TCN_SELCHANGE;
  ::SendMessageW(hDlg_1, WM_NOTIFY, 0, &nmhdr);
  if ( gConfig.WindowPlacement[4].rcNormalPosition.right )
    _mm_storeu_si128(&Rect, _mm_loadu_si128(&gConfig.WindowPlacement[4].rcNormalPosition));
  else
    GetWindowRect(v30, &Rect);
  gConfig.WindowPlacement[4].showCmd = 5;
  SetWindowPlacement(v30, &gConfig.WindowPlacement[4]);
  if ( gConfig.bAlwaysOntop )
    SetWindowPos(v30, HWND_MESSAGE|0x2, 0, 0, 0, 0, SWP_NOMOVE|SWP_NOSIZE);
  return 1;
}
// 106A009: using guessed type int _endthread(void);
// 10A67DC: using guessed type wchar_t aSummary[8];
// 10A67EC: using guessed type wchar_t aSysteminfosume[17];
// 10A6810: using guessed type wchar_t aSysteminfosum[14];
// 10A682C: using guessed type wchar_t aCpu_0[4];
// 10A6834: using guessed type wchar_t aSysteminfocpu[14];
// 10A6850: using guessed type wchar_t aMemory[7];
// 10A6860: using guessed type wchar_t aSysteminfomem[14];
// 10A687C: using guessed type wchar_t aSysteminfomemx[16];
// 10A689C: using guessed type wchar_t aIO_0[4];
// 10A68A4: using guessed type wchar_t aSysteminfoioet[16];
// 10A68C4: using guessed type wchar_t aSysteminfoio[13];
// 10A68E0: using guessed type wchar_t aGpu_0[4];
// 10A68E8: using guessed type wchar_t aSysteminfogpu[14];
// 10C4E54: using guessed type int gdwVersion;
