
//----- (00FE01B0) --------------------------------------------------------
char InitTlhlpApis()
{
  HMODULE v0; // eax
  HMODULE v2; // eax
  HMODULE v3; // eax
  HMODULE v4; // eax
  HMODULE v5; // eax
  HMODULE v6; // eax
  HMODULE v7; // eax
  HMODULE v8; // eax
  HMODULE v9; // eax
  HMODULE v10; // eax

  v0 = GetModuleHandleW(L"kernel32.dll");
  *CreateToolhelp32Snapshot_0 = GetProcAddress(v0, "CreateToolhelp32Snapshot");
  if ( !*CreateToolhelp32Snapshot_0 )
    return 0;
  v2 = GetModuleHandleW(L"kernel32.dll");
  *Process32FirstW_0 = GetProcAddress(v2, "Process32FirstW");
  if ( !*Process32FirstW_0 )
    return 0;
  v3 = GetModuleHandleW(L"kernel32.dll");
  *Process32NextW_0 = GetProcAddress(v3, "Process32NextW");
  if ( !*Process32NextW_0 )
    return 0;
  v4 = GetModuleHandleW(L"kernel32.dll");
  *Thread32First_0 = GetProcAddress(v4, "Thread32First");
  if ( !*Thread32First_0 )
    return 0;
  v5 = GetModuleHandleW(L"kernel32.dll");
  *Thread32Next_0 = GetProcAddress(v5, "Thread32Next");
  if ( !*Thread32Next_0 )
    return 0;
  v6 = GetModuleHandleW(L"kernel32.dll");
  *Module32FirstW_0 = GetProcAddress(v6, "Module32FirstW");
  if ( !*Module32FirstW_0 )
    return 0;
  v7 = GetModuleHandleW(L"kernel32.dll");
  *Module32NextW_0 = GetProcAddress(v7, "Module32NextW");
  if ( !*Module32NextW_0 )
    return 0;
  v8 = LoadLibraryW(L"dbghelp.dll");
  *ImageNtHeader = GetProcAddress(v8, "ImageNtHeader");
  if ( !*ImageNtHeader )
  {
    v9 = LoadLibraryW(L"imagehlp.dll");
    *ImageNtHeader = GetProcAddress(v9, "ImageNtHeader");
  }
  v10 = LoadLibraryW(L"user32.dll");
  IsHungThread = GetProcAddress(v10, "IsHungThread");
  return 1;
}
// 106F320: using guessed type int IsHungThread;

//----- (00FE02C0) --------------------------------------------------------
void __cdecl QueryProcessArguments(HANDLE hProcess, ULONG_PTR dwProcessId, WCHAR **ppszCommandLine, WCHAR **ppszCurrentDirectory, WCHAR **ppszEnvBlock, PDWORD pbFlagsInExtendedProcessBasicInfo)
{
  PDWORD pdwValue6In; // eax
  WCHAR **ppszCommandLineIn; // edi
  WCHAR **ppszCurrentDirectoryIn; // esi
  WCHAR **ppszEnvBlockIn; // ebx
  WCHAR *v10; // eax
  _PROCESS_EXTENDED_BASIC_INFORMATION ProcessInformation; // [esp+0h] [ebp-20h]

  pdwValue6In = pbFlagsInExtendedProcessBasicInfo;
  ProcessInformation.Size = 0;
  *&ProcessInformation.BasicInfo.UniqueProcessId = 0i64;
  ProcessInformation.Flags = 0;
  _mm_storeu_si128(&ProcessInformation.BasicInfo, 0i64);
  if ( pdwValue6In )
    *pdwValue6In = 0;
  ppszCommandLineIn = ppszCommandLine;
  if ( ppszCommandLine )
    *ppszCommandLine = 0;
  ppszCurrentDirectoryIn = ppszCurrentDirectory;
  if ( ppszCurrentDirectory )
    *ppszCurrentDirectory = 0;
  ppszEnvBlockIn = ppszEnvBlock;
  if ( ppszEnvBlock )
    *ppszEnvBlock = 0;
  if ( hProcess )
  {
    ProcessInformation.Size = 0x20;
    if ( !NtQueryInformationProcess(
            hProcess,
            ProcessBasicInformation,
            &ProcessInformation,
            sizeof(_PROCESS_EXTENDED_BASIC_INFORMATION),
            &ppszCommandLine)
      || !NtQueryInformationProcess(
            hProcess,
            ProcessBasicInformation,
            &ProcessInformation.BasicInfo,
            sizeof(PROCESS_BASIC_INFORMATION),
            &ppszCommandLine) )
    {
      if ( pbFlagsInExtendedProcessBasicInfo )
        *pbFlagsInExtendedProcessBasicInfo = ProcessInformation.Flags & 1;
      if ( ProcessInformation.BasicInfo.PebBaseAddress )
        QueryProcessCommandLineArgs(
          hProcess,
          ProcessInformation.BasicInfo.PebBaseAddress,
          ppszCommandLineIn,
          ppszCurrentDirectoryIn,
          ppszEnvBlockIn);
      if ( ppszCurrentDirectoryIn )
      {
        if ( *ppszCurrentDirectoryIn )
          PE_GetFullPathName(ppszCurrentDirectoryIn);
        else
          *ppszCurrentDirectoryIn = _wcsdup(&gszNullString);
      }
      if ( ppszCommandLineIn && !*ppszCommandLineIn )
        *ppszCommandLineIn = _wcsdup(&gszNullString);
      if ( ppszEnvBlockIn )
      {
        if ( !*ppszEnvBlockIn )
        {
          v10 = _wcsdup(L" ");
          *ppszEnvBlockIn = v10;
          *v10 = 0;
        }
      }
    }
  }
}

//----- (00FE03E0) --------------------------------------------------------
char __cdecl QueryProcessImageBase(HANDLE hProcess, DWORD dwPid, LPCWSTR lpszProcessName, LPVOID *ppBufer, PDWORD pdwSize)
{
  HANDLE v5; // ebx
  HANDLE hFound; // ebx
  const wchar_t *v7; // eax
  WCHAR *v8; // edi
  DWORD v9; // eax
  DWORD v10; // ebx
  SIZE_T v12; // edi
  WCHAR *v13; // esi
  void *v14; // edi
  int v15; // ebx
  IAtlStringMgr *v16; // eax
  volatile signed __int32 *v17; // edi
  struct _MEMORY_BASIC_INFORMATION Buffer; // [esp+10h] [ebp-474h]
  WCHAR *v19; // [esp+2Ch] [ebp-458h]
  PDWORD pdwLength; // [esp+30h] [ebp-454h]
  WCHAR *v21; // [esp+34h] [ebp-450h]
  wchar_t *v22; // [esp+38h] [ebp-44Ch]
  LPVOID *ppBuf; // [esp+3Ch] [ebp-448h]
  wchar_t *v24; // [esp+40h] [ebp-444h]
  size_t SizeInWords; // [esp+44h] [ebp-440h]
  HANDLE v26; // [esp+48h] [ebp-43Ch]
  MODULEENTRY32W me; // [esp+4Ch] [ebp-438h]
  int v28; // [esp+480h] [ebp-4h]

  v5 = hProcess;
  v22 = lpszProcessName;
  ppBuf = ppBufer;
  pdwLength = pdwSize;
  v26 = hProcess;
  v24 = dwPid;
  if ( *CreateToolhelp32Snapshot_0 )
  {
    hFound = CreateToolhelp32Snapshot_0(TH32CS_SNAPMODULE, dwPid);
    v26 = hFound;
    if ( hFound != -1 )
    {
      me.dwSize = sizeof(MODULEENTRY32W);
      if ( Module32FirstW_0(hFound, &me) )
      {
        do
        {
          v28 = 0;
          if ( !wcsncmp(me.szExePath, L"\\??\\", 4u) )
          {
            v7 = &me.szExePath[4];
          }
          else
          {
            if ( !_wcsnicmp(me.szExePath, L"\\Systemroot\\", 0xCu) )
            {
              SizeInWords = ExpandEnvironmentStringsW(L"%SystemRoot%", 0, 0) + 1 + wcslen(me.szExePath);
              v8 = malloc(2 * SizeInWords);
              v21 = v8;
              ExpandEnvironmentStringsW(L"%SystemRoot%", v8, SizeInWords);
              wcscat_s(v8, SizeInWords, &me.szExePath[11]);
              goto LABEL_10;
            }
            v7 = me.szExePath;
          }
          v8 = _wcsdup(v7);
          v21 = v8;
LABEL_10:
          if ( *GetLongPathNameW )
          {
            v9 = GetLongPathNameW(v8, 0, 0);
            v10 = v9;
            if ( v9 )
            {
              v19 = malloc(2 * v9 + 2);
              LOBYTE(v28) = 1;
              GetLongPathNameW(v8, v19, v10 + 1);
              free(v8);
              v8 = v19;
              LOBYTE(v28) = 0;
              j__free(0);
            }
            hFound = v26;
          }
          if ( me.th32ProcessID == v24 && !_wcsicmp(v22, v8) )
          {
            *ppBuf = me.modBaseAddr;
            *pdwLength = me.modBaseSize;
            j__free(v8);
            return 1;
          }
          v28 = -1;
          j__free(v8);
        }
        while ( Module32NextW_0(hFound, &me) );
      }
      CloseHandle(hFound);
    }
    return 0;
  }
  Buffer.BaseAddress = 0;
  if ( !VirtualQueryEx(hProcess, 0, &Buffer, 0x1Cu) )
    return 0;
  while ( 1 )
  {
    if ( Buffer.Type != 0x40000
      || NtQueryVirtualMemory(v5, Buffer.BaseAddress, MemoryMappedFilenameInformation, 0, 0, &SizeInWords) != STATUS_INFO_LENGTH_MISMATCH )
    {
      goto LABEL_30;
    }
    v12 = SizeInWords;
    v13 = malloc(SizeInWords);
    v19 = v13;
    v28 = 2;
    if ( !NtQueryVirtualMemory(v5, Buffer.BaseAddress, MemoryMappedFilenameInformation, v13, v12, &SizeInWords) )
      break;
LABEL_29:
    v28 = -1;
    j__free(v13);
LABEL_30:
    Buffer.BaseAddress = Buffer.BaseAddress + Buffer.RegionSize;
    if ( !VirtualQueryEx(v5, Buffer.BaseAddress, &Buffer, 0x1Cu) )
      return 0;
  }
  v14 = *(v13 + 1);
  v15 = *v13 >> 1;
  v16 = ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>::GetDefaultManager();
  sub_FACF80(&v24, v14, v15, v16);
  v17 = (v24 - 8);
  if ( _wcsicmp(v24, v22) )
  {
    if ( _InterlockedDecrement(v17 + 3) <= 0 )
      (*(**v17 + 4))(v17);
    v5 = v26;
    goto LABEL_29;
  }
  *ppBuf = Buffer.BaseAddress;
  *pdwLength = Buffer.RegionSize;
  if ( _InterlockedDecrement(v17 + 3) <= 0 )
    (*(**v17 + 4))(v17);
  j__free(v13);
  return 1;
}

//----- (00FE07B0) --------------------------------------------------------
DWORD __cdecl LoadSystemModulesSymbolAddress(LPCWSTR lpszName)
{
  RTL_PROCESS_MODULES *ProcessModules; // edi
  ULONG v2; // esi
  ULONG Index; // esi
  const CHAR *v4; // ebx
  const wchar_t **v5; // eax
  CStringData *v6; // eax
  int BaseOfDll_1; // ebx
  HANDLE hFile; // edi
  HANDLE v9; // eax
  DWORD result; // eax
  HANDLE hProcess; // eax
  __int64 v12; // rax
  HANDLE v13; // eax
  const CHAR *Name_1; // ST1C_4
  HANDLE hProcess_1; // eax
  int v16; // eax
  HANDLE v17; // eax
  struct _MODLOAD_DATA *Data; // [esp-Ch] [ebp-740h]
  DWORD Flags; // [esp-8h] [ebp-73Ch]
  CStringData *v20; // [esp+0h] [ebp-734h]
  CString strFullPathName; // [esp+4h] [ebp-730h]
  PCSTR Name; // [esp+8h] [ebp-72Ch]
  DWORD64 BaseOfDll; // [esp+Ch] [ebp-728h]
  WCHAR szDir[260]; // [esp+14h] [ebp-720h]
  WCHAR FileName[260]; // [esp+21Ch] [ebp-518h]
  wchar_t ImageName[260]; // [esp+424h] [ebp-310h]
  IMAGEHLP_SYMBOL Symbol; // [esp+62Ch] [ebp-108h]

  Name = lpszName;
  if ( !SymCleanup || !SymInitialize || !SymLoadModuleExW_1 || !SymGetSymFromName )
    return 0;
  HIDWORD(BaseOfDll) = 1000;
  ProcessModules = malloc(0x3E8u);
  if ( NtQuerySystemInformation(SystemModuleInformation, ProcessModules, 0x3E8u, &BaseOfDll + 1) )
  {
    do
    {
      HIDWORD(BaseOfDll) += 1000;
      free(ProcessModules);
      v2 = HIDWORD(BaseOfDll);
      ProcessModules = malloc(HIDWORD(BaseOfDll));
    }
    while ( NtQuerySystemInformation(SystemModuleInformation, ProcessModules, v2, &BaseOfDll + 1) );
  }
  if ( IsPAEEnabled() )
    wcscpy_s(ImageName, MAX_PATH, L"ntkrnlpa.exe");
  else
    wcscpy_s(ImageName, MAX_PATH, L"ntoskrnl.exe");
  Index = 0;
  if ( ProcessModules->NumberOfModules )
  {
    v4 = ProcessModules->Modules[0].FullPathName;
    while ( 1 )
    {
      v5 = ATL::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>(
             &strFullPathName,
             v4);
      LODWORD(BaseOfDll) = wcsstr(*v5, ImageName);
      v6 = (strFullPathName.pszData - 16);
      v20 = (strFullPathName.pszData - 16);
      if ( _InterlockedDecrement(strFullPathName.pszData - 1) <= 0 )
        (v6->pStringMgr->vtptr->Free)(v20);
      if ( BaseOfDll )
        break;
      ++Index;
      v4 += sizeof(RTL_PROCESS_MODULE_INFORMATION);
      if ( Index >= ProcessModules->NumberOfModules )
        goto LABEL_16;
    }
    BaseOfDll_1 = ProcessModules->Modules[Index].ImageBase;
  }
  else
  {
LABEL_16:
    BaseOfDll_1 = BaseOfDll;
  }
  free(ProcessModules);
  GetSystemDirectoryW(szDir, MAX_PATH);
  swprintf(FileName, L"%s\\%s", szDir, ImageName);
  hFile = CreateFileW(FileName, GENERIC_READ, 3u, 0, OPEN_EXISTING, 0, 0);
  EnterCriticalSection(&gProcThreadsLock);
  v9 = GetCurrentThread();
  if ( SymInitialize(v9, 0, 0) )
  {
    hProcess = GetCurrentThread();
    LODWORD(v12) = SymLoadModuleExW_1(hProcess, hFile, ImageName, 0, BaseOfDll_1, 0, Data, Flags);
    if ( v12 )
    {
      Symbol.SizeOfStruct = sizeof(IMAGEHLP_SYMBOL);
      Name_1 = Name;
      Symbol.MaxNameLength = 237;
      hProcess_1 = GetCurrentThread();
      v16 = SymGetSymFromName(hProcess_1, Name_1, &Symbol);
      Symbol.Address &= -(v16 != 0);
      CloseHandle(hFile);
      v17 = GetCurrentThread();
      SymCleanup(v17);
      LeaveCriticalSection(&gProcThreadsLock);
      result = Symbol.Address;
    }
    else
    {
      CloseHandle(hFile);
      v13 = GetCurrentThread();
      SymCleanup(v13);
      LeaveCriticalSection(&gProcThreadsLock);
      result = 0;
    }
  }
  else
  {
    LeaveCriticalSection(&gProcThreadsLock);
    CloseHandle(hFile);
    result = 0;
  }
  return result;
}
// 10456FC: using guessed type wchar_t aNtkrnlpaExe[13];
// FE09BE: user specified stroff has not been processed: RTL_PROCESS_MODULE_INFORMATION offset 284

//----- (00FE0A90) --------------------------------------------------------
char __cdecl sub_FE0A90(HANDLE hProcess, DWORD dwProcessId, LPWSTR *ppszFileName, tagTREEVIEWLISTITEMPARAM *pItem)
{
  DWORD dwIndex; // eax
  WCHAR **v5; // ecx
  SC_HANDLE hService; // ebx
  DWORD v8; // esi
  wchar_t *pstr; // eax
  LPWSTR v10; // eax
  LPWSTR v11; // ecx
  int v12; // edx
  WCHAR v13; // ax
  rsize_t v14; // edi
  wchar_t *v15; // eax
  const wchar_t **v16; // esi
  DWORD v17; // eax
  DWORD v18; // edi
  WCHAR *v19; // eax
  DWORD v20; // eax
  DWORD v21; // esi
  WCHAR *v22; // eax
  LPWSTR v23; // ecx
  WCHAR v24; // ax
  struct _QUERY_SERVICE_CONFIGW *pServiceConfig; // [esp+Ch] [ebp-21Ch]
  LPWSTR *ppszFileNameIn; // [esp+14h] [ebp-214h]
  DWORD dwRet; // [esp+18h] [ebp-210h]
  __int16 Src[260]; // [esp+1Ch] [ebp-20Ch]

  ppszFileNameIn = ppszFileName;
  *ppszFileName = 0;
  if ( !hProcess )
  {
    if ( pItem->dwStyle & TVLS_SHOWSERVICE )
    {
      dwIndex = 0;
      if ( gdwServiceReturned )
      {
        v5 = gpszServiceNames + 9;
        while ( *v5 != dwProcessId )
        {
          ++dwIndex;
          v5 += 11;
          if ( dwIndex >= gdwServiceReturned )
            return 0;
        }
        hService = OpenServiceW(ghSCManagerHandle, gpszServiceNames[11 * dwIndex], 5u);
        QueryServiceConfigW(hService, 0, 0, &dwRet);
        v8 = dwRet;
        pServiceConfig = malloc(dwRet);
        QueryServiceConfigW(hService, pServiceConfig, v8, &dwRet);
        if ( pServiceConfig->lpBinaryPathName )
        {
          if ( !pItem->pszCommandLine )
            pItem->pszCommandLine = _wcsdup(pServiceConfig->lpBinaryPathName);
          pstr = wcsstr(pServiceConfig->lpBinaryPathName, L".exe");
          if ( pstr && pstr[4] )
            pstr[4] = 0;
          v10 = pServiceConfig->lpBinaryPathName;
          if ( *v10 == '"' )
            pServiceConfig->lpBinaryPathName = v10 + 1;
          v11 = pServiceConfig->lpBinaryPathName;
          v12 = (v11 + 1);
          do
          {
            v13 = *v11;
            ++v11;
          }
          while ( v13 );
          v14 = ((v11 - v12) >> 1) + 5;
          v15 = malloc(2 * v14);
          v16 = ppszFileNameIn;
          *ppszFileNameIn = v15;
          wcscpy_s(v15, v14, pServiceConfig->lpBinaryPathName);
          free(pServiceConfig);
          if ( GetFileAttributesW(*v16) == -1 )
          {
            if ( **v16 != 34 && wcschr(*v16, ' ') )
              *wcschr(*v16, ' ') = 0;
            if ( GetFileAttributesW(*v16) == -1 )
              wcscat_s(*v16, v14, L".exe");
          }
          return 1;
        }
        free(pServiceConfig);
      }
    }
    return 0;
  }
  if ( !sub_FDCF30(hProcess, ppszFileName) )
  {
    v17 = GetModuleFileNameExW(hProcess, 0, &ppszFileNameIn, 2u);
    v18 = v17;
    if ( !v17 )
      return 0;
    v19 = malloc(2 * v17 + 2);
    *ppszFileName = v19;
    if ( !GetModuleFileNameExW(hProcess, 0, v19, v18) )
      return 0;
  }
  if ( !_wcsnicmp(*ppszFileName, L"\\SystemRoot\\", 0xCu) )
  {
    swprintf(Src, L"%%SystemRoot%%\\%s", *ppszFileName + 12);
    v20 = ExpandEnvironmentStringsW(Src, 0, 0);
    v21 = v20;
    v22 = malloc(2 * v20);
    *ppszFileName = v22;
    ExpandEnvironmentStringsW(Src, v22, v21);
    return 1;
  }
  if ( !wcsncmp(*ppszFileName, L"\\??\\", 4u) )
  {
    v23 = *ppszFileName;
    do
    {
      v24 = *v23;
      ++v23;
    }
    while ( v24 );
    wcscpy_s(*ppszFileName, v23 - (*ppszFileName + 1), *ppszFileName + 4);
  }
  return 1;
}

//----- (00FE0D70) --------------------------------------------------------
int __cdecl sub_FE0D70(wchar_t *a1)
{
  int v1; // esi
  int result; // eax

  EnterCriticalSection(&gProcThreadsLock);
  v1 = dword_106B1DC;
  if ( dword_106B1DC )
  {
    while ( _wcsicmp(*v1, a1) )
    {
      v1 = *(v1 + 12);
      if ( !v1 )
        goto LABEL_4;
    }
    LeaveCriticalSection(&gProcThreadsLock);
    result = v1;
  }
  else
  {
LABEL_4:
    LeaveCriticalSection(&gProcThreadsLock);
    result = 0;
  }
  return result;
}
// 106B1DC: using guessed type int dword_106B1DC;

//----- (00FE0DD0) --------------------------------------------------------
void __cdecl sub_FE0DD0(wchar_t *a1)
{
  int v1; // edi
  wchar_t *v2; // ebx
  WCHAR *v3; // ecx
  size_t v4; // esi
  int v5; // edx
  unsigned int v6; // ecx
  WCHAR *v7; // esi
  WCHAR v8; // ax
  int v9; // esi
  WCHAR *v10; // edx
  int v11; // esi
  int v12; // edi
  WCHAR v13; // ax

  v1 = 0;
  if ( gszDriverLinkName[0] )
  {
    v2 = a1;
    v3 = gszDriverLinkName;
    while ( 1 )
    {
      v4 = wcslen(v3);
      if ( !_wcsnicmp(v3, v2, v4) && v2[v4] == 92 )
        break;
      v3 = &gszDriverLinkName[257 * ++v1];
      if ( !gszDriverLinkName[257 * v1] )
        return;
    }
    v5 = 257 * v1;
    *v2 = gszDriverName[0][257 * v1];
    v2[1] = 58;
    v6 = wcslen(v2);
    v7 = &gszDriverLinkName[257 * v1 + 1];
    do
    {
      v8 = *v7;
      ++v7;
    }
    while ( v8 );
    v9 = v7 - &gszDriverLinkName[v5 + 2];
    v10 = &gszDriverLinkName[v5];
    v11 = v9 >> 1;
    v12 = (v10 + 1);
    do
    {
      v13 = *v10;
      ++v10;
    }
    while ( v13 );
    memmove_0(v2 + 2, &v2[(v10 - v12) >> 1], 2 * (v6 - v11));
    sub_FDC270(&a1, 0x104u);
  }
}

//----- (00FE0EE0) --------------------------------------------------------
int __cdecl sub_FE0EE0(wchar_t *pszBuffer)
{
  int nIndex; // ebx
  size_t *pszPosition; // esi
  int v3; // ebx
  RegItem *v4; // esi
  int result; // eax
  int ret; // eax
  char found; // cl
  wchar_t *pszText; // esi
  wchar_t i; // ax
  const wchar_t *v10; // esi
  char found_1; // [esp+Ch] [ebp-Ch]

  nIndex = 0;
  pszPosition = &stru_1060320[0].field_240;
  do
  {
    if ( !_wcsnicmp(pszBuffer, pszPosition - 288, *pszPosition)
      && !_wcsnicmp(&pszBuffer[*pszPosition], gpszCurAuthInfo, wcslen(gpszCurAuthInfo)) )
    {
      ret = _wcsnicmp(&pszBuffer[wcslen(gpszCurAuthInfo) + stru_1060320[nIndex].field_240], L"_Classes", 8u);
      found = 0;
      if ( !ret )
        found = 1;
      found_1 = found;
      pszText = &pszBuffer[stru_1060320[nIndex].field_240];
      for ( i = *pszText; i; ++pszText )
      {
        if ( i == '\\' )
          break;
        i = pszText[1];
      }
      wcscpy_s(pszBuffer, pszText - pszBuffer, &stru_1060320[nIndex].gap4[508]);
      if ( found_1 )
        wcscat_s(pszBuffer, pszText - pszBuffer, L"\\Software\\Classes");
      return wcscat_s(pszBuffer, 1024u, pszText);
    }
    pszPosition += 145;
    ++nIndex;
  }
  while ( pszPosition < &stru_1060320[2].field_240 );
  v3 = 0;
  v4 = &stru_1060320[2];
  while ( 1 )
  {
    result = _wcsnicmp(pszBuffer, v4, v4->field_240);
    if ( !result )
      break;
    ++v4;
    ++v3;
    if ( v4 >= gdwValue_4F10B8 )
      return result;
  }
  v10 = &pszBuffer[stru_1060320[v3 + 2].field_240];
  wcscpy_s(pszBuffer, 2 * stru_1060320[v3 + 2].field_240 >> 1, &stru_1060320[v3 + 2].gap4[508]);
  return wcscat_s(pszBuffer, 1024u, v10);
}
// 1060320: using guessed type RegItem stru_1060320[4];
// 10610B8: using guessed type int gdwValue_4F10B8[3];

//----- (00FE1080) --------------------------------------------------------
char __cdecl ReportMsg(int ArgList)
{
  WCHAR Text; // [esp+0h] [ebp-20Ch]

  swprintf(&Text, L"Not able to run on this version of Windows:\nMissing function: %s", ArgList);
  MessageBoxW(0, &Text, L"Process Explorer", 0x10u);
  return 0;
}

//----- (00FE10E0) --------------------------------------------------------
signed int __userpurge PropHandleInfo@<eax>(char a1@<bl>, HWND hWnd, unsigned int a2, unsigned __int16 a3, int a4)
{
  HWND v6; // eax
  POINT v7; // ST18_8
  DWORD v8; // esi
  const WCHAR *v9; // ebx
  bool v10; // cl
  const WCHAR *v11; // esi
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  const wchar_t *v16; // eax
  const wchar_t *v17; // eax
  int v18; // eax
  void (__stdcall *v19)(HANDLE); // ebx
  const wchar_t *v20; // eax
  int v21; // eax
  HWND v22; // eax
  HWND v23; // eax
  HWND v24; // eax
  char v25; // [esp-4h] [ebp-6D4h]
  char v26; // [esp-4h] [ebp-6D4h]
  int ThreadInformation; // [esp+8h] [ebp-6C8h]
  DWORD dwProcessId; // [esp+10h] [ebp-6C0h]
  int InformationBuffer; // [esp+24h] [ebp-6ACh]
  int v30; // [esp+28h] [ebp-6A8h]
  char v31[4]; // [esp+2Ch] [ebp-6A4h]
  ULONG ResultLength; // [esp+34h] [ebp-69Ch]
  struct _FILETIME LocalFileTime; // [esp+38h] [ebp-698h]
  FILETIME FileTime; // [esp+40h] [ebp-690h]
  int v35; // [esp+48h] [ebp-688h]
  int v36; // [esp+4Ch] [ebp-684h]
  int v37; // [esp+50h] [ebp-680h]
  char v38; // [esp+55h] [ebp-67Bh]
  struct tagPOINT Point; // [esp+58h] [ebp-678h]
  char v40[4]; // [esp+60h] [ebp-670h]
  char v41[4]; // [esp+64h] [ebp-66Ch]
  ULONG ReturnLength; // [esp+68h] [ebp-668h]
  struct _UNICODE_STRING LinkTarget; // [esp+6Ch] [ebp-664h]
  void *OutBuffer; // [esp+74h] [ebp-65Ch]
  DWORD BytesReturned; // [esp+78h] [ebp-658h]
  ULONG ReturnedLength; // [esp+7Ch] [ebp-654h]
  void *InBuffer; // [esp+80h] [ebp-650h]
  int ObjectInformation; // [esp+84h] [ebp-64Ch]
  int v49; // [esp+8Ch] [ebp-644h]
  int v50; // [esp+90h] [ebp-640h]
  char ArgList[4]; // [esp+94h] [ebp-63Ch]
  char v52[4]; // [esp+98h] [ebp-638h]
  FILETIME v53; // [esp+B4h] [ebp-61Ch]
  struct _SYSTEMTIME SystemTime; // [esp+BCh] [ebp-614h]
  char v55; // [esp+CCh] [ebp-604h]
  wchar_t Dst; // [esp+2CCh] [ebp-404h]
  WCHAR String; // [esp+4CCh] [ebp-204h]

  if ( a2 == 16 )
    goto LABEL_5;
  if ( a2 == 272 )
  {
    v25 = a1;
    GetCursorPos(&Point);
    v6 = GetParent(hWnd);
    sub_FDBDA0(v6);
    v7.y = Point.y - 430;
    v7.x = Point.x - 375;
    PE_SetWindowPlacement(hWnd, v7);
    PostMessageW(hWnd, 0x46Bu, 0, 0);
    v8 = *(a4 + 28);
    BytesReturned = v8;
    v9 = (v8 + 56);
    v10 = !_wcsicmp((v8 + 56), L"Mutant")
       || !_wcsicmp((v8 + 56), L"Section")
       || !_wcsicmp((v8 + 56), L"Event")
       || !_wcsicmp((v8 + 56), L"Semaphore");
    InBuffer = PE_DuplicateProcessHandle(*(v8 + 36), *(v8 + 44), v10 != 0);
    if ( !InBuffer )
    {
      if ( *(v8 + 16) == 1 )
        MessageBoxW(ghMainWnd, L"Object does not exist.", L"Object Properties Error", 0x10u);
      else
        MessageBoxW(ghMainWnd, L"Unable to query the object", L"Object Properties Error", 0x10u);
      v23 = GetParent(hWnd);
      EndDialog(v23, 0);
      v24 = GetParent(hWnd);
      PostMessageW(v24, 0x471u, 5u, 0);
      return 0;
    }
    v11 = (v8 + 2232);
    wsprintf(&String, L"%s Properties", v11);
    SetWindowTextW(hWnd, &String);
    SetDlgItemTextW(hWnd, 1005, v11);
    SetDlgItemTextW(hWnd, 1006, v9);
    if ( _wcsicmp(v9, L"file") )
    {
      if ( _wcsicmp(v9, L"directory") )
      {
        if ( _wcsicmp(v9, L"symboliclink") )
        {
          if ( _wcsicmp(v9, L"key") )
          {
            if ( _wcsicmp(v9, L"process") )
            {
              v12 = wcscmp(v9, L"thread");
              if ( v12 )
                v12 = -(v12 < 0) | 1;
              if ( v12 )
              {
                if ( _wcsicmp(v9, L"iocompletion") )
                {
                  if ( _wcsicmp(v9, L"mutant") )
                  {
                    if ( _wcsicmp(v9, L"event") && _wcsicmp(v9, L"semaphore") )
                    {
                      if ( _wcsicmp(v9, L"windowstation") )
                      {
                        if ( _wcsicmp(v9, L"desktop") )
                        {
                          if ( _wcsicmp(v9, L"port") && _wcsicmp(v9, L"waitableport") )
                          {
                            if ( _wcsicmp(v9, L"section") )
                            {
                              if ( _wcsicmp(v9, L"token") )
                              {
                                if ( !_wcsicmp(v9, L"timer") )
                                  SetDlgItemTextW(hWnd, 1050, L"A time-based synchronization object.");
                              }
                              else
                              {
                                SetDlgItemTextW(hWnd, 1050, L"Identifies a security context.");
                              }
                            }
                            else
                            {
                              SetDlgItemTextW(hWnd, 1050, L"A memory mapped file or paging-file backed memory region.");
                            }
                          }
                          else
                          {
                            SetDlgItemTextW(hWnd, 1050, L"An interprocess communications endpoint.");
                          }
                        }
                        else
                        {
                          SetDlgItemTextW(hWnd, 1050, L"Contains application windows.");
                        }
                      }
                      else
                      {
                        SetDlgItemTextW(hWnd, 1050, L"Contains one or more desktops with windows.");
                      }
                    }
                    else
                    {
                      SetDlgItemTextW(hWnd, 1050, L"A synchronization object.");
                    }
                  }
                  else
                  {
                    SetDlgItemTextW(hWnd, 1050, L"A synchronization object (a Win32 mutex).");
                  }
                }
                else
                {
                  SetDlgItemTextW(hWnd, 1050, L"An asynchronous I/O notification object.");
                }
              }
              else
              {
                SetDlgItemTextW(hWnd, 1050, L"An object that executes program code.");
              }
            }
            else
            {
              SetDlgItemTextW(hWnd, 1050, L"Contains threads, an address space, and handles.");
            }
          }
          else
          {
            SetDlgItemTextW(hWnd, 1050, L"A Registry key.");
          }
        }
        else
        {
          SetDlgItemTextW(hWnd, 1050, L"An Object Manager namespace link.");
        }
      }
      else
      {
        SetDlgItemTextW(hWnd, 1050, L"An Object Manager namespace directory.");
      }
    }
    else
    {
      SetDlgItemTextW(hWnd, 1050, L"A disk file, communications endpoint, or driver interface.");
    }
    wsprintf(&String, L"0x%X", *(BytesReturned + 40));
    SetDlgItemTextW(hWnd, 1051, &String);
    NtQueryObject(InBuffer, 0, &ObjectInformation, 0x38u, &ReturnLength);
    wsprintf(&String, L"%d", v49 - 1);
    SetDlgItemTextW(hWnd, 1008, &String);
    wsprintf(&String, L"%d", v50 - 2);
    SetDlgItemTextW(hWnd, 1019, &String);
    wsprintf(&String, L"%d", ArgList[0]);
    SetDlgItemTextW(hWnd, 1010, &String);
    wsprintf(&String, L"%d", v52[0]);
    SetDlgItemTextW(hWnd, 1013, &String);
    v13 = wcscmp(v9, L"SymbolicLink");
    if ( v13 )
      v13 = -(v13 < 0) | 1;
    if ( !v13 )
    {
      SetDlgItemTextW(hWnd, 1025, L"Symbolic Link Info");
      SetDlgItemTextW(hWnd, 1024, L"Creation Time:");
      FileTime = v53;
      FileTimeToLocalFileTime(&FileTime, &LocalFileTime);
      FileTimeToSystemTime(&LocalFileTime, &SystemTime);
      wsprintf(&String, L"%d:%02d:%02d, %d/%d/%d", SystemTime.wHour);
      SetDlgItemTextW(hWnd, 1022, &String);
      SetDlgItemTextW(hWnd, 1028, L"Link:");
      LinkTarget.MaximumLength = 256;
      LinkTarget.Buffer = &v55;
      if ( gpfn_NtQuerySymbolicLinkObject(InBuffer, &LinkTarget, &ReturnedLength) )
        wcscpy_s(&String, 0x100u, L"<Error Querying Link>");
      else
        wsprintf(&String, L"%s", LinkTarget.Buffer);
      SetDlgItemTextW(hWnd, 1027, &String);
      goto LABEL_94;
    }
    v14 = wcscmp(v9, L"Semaphore");
    if ( v14 )
      v14 = -(v14 < 0) | 1;
    if ( v14 )
    {
      v15 = wcscmp(v9, L"Event");
      if ( v15 )
        v15 = -(v15 < 0) | 1;
      if ( v15 )
      {
        v18 = wcscmp(v9, L"Mutant");
        if ( v18 )
          v18 = -(v18 < 0) | 1;
        if ( !v18 )
        {
          SetDlgItemTextW(hWnd, 1025, L"Mutant Info");
          SetDlgItemTextW(hWnd, 1024, L"Held:");
          NtQueryMutant(InBuffer, 0, &v37, 8, &ReturnedLength);
          wsprintf(&String, L"FALSE", v25);
          if ( v37 <= 0
            && (wsprintf(&String, L"TRUE", v26),
                DeviceIoControl(ghDriverHandle, 0x8335002C, &InBuffer, 4u, &OutBuffer, 4u, &BytesReturned, 0))
            && OutBuffer )
          {
            if ( !NtQueryInformationThread(OutBuffer, 0, &ThreadInformation, 0x1Cu, &ReturnLength) )
            {
              SystemProcessInfo_GetSystemProcessName(dwProcessId, 0, &Dst, 0x100u);
              wsprintf(&String, L"%s(%d): %d", &Dst);
            }
            v19 = CloseHandle;
            CloseHandle(OutBuffer);
          }
          else
          {
            v19 = CloseHandle;
          }
          SetDlgItemTextW(hWnd, 1022, &String);
          SetDlgItemTextW(hWnd, 1028, L"Abandoned:");
          v20 = L"TRUE";
          if ( !v38 )
            v20 = L"FALSE";
          wsprintf(&String, L"%s", v20);
          SetDlgItemTextW(hWnd, 1027, &String);
          v19(InBuffer);
          return 1;
        }
        v21 = wcscmp(v9, L"Section");
        if ( v21 )
          v21 = -(v21 < 0) | 1;
        if ( v21 )
        {
          v22 = GetDlgItem(hWnd, 1025);
          ShowWindow(v22, 0);
        }
        else
        {
          SetDlgItemTextW(hWnd, 1025, L"Section Info");
          NtQuerySection(InBuffer, 0, &InformationBuffer, 0x10u, &ResultLength);
          if ( v30 & 0x1000000 )
          {
            SetDlgItemTextW(hWnd, 1024, L"Type:");
            wcscpy_s(&String, 0x100u, L"IMAGE");
          }
          else if ( v30 & 0x800000 )
          {
            SetDlgItemTextW(hWnd, 1024, L"Type:");
            wcscpy_s(&String, 0x100u, L"FILE");
          }
          else if ( v30 & 0x4000000 )
          {
            SetDlgItemTextW(hWnd, 1024, L"Type:");
            wcscpy_s(&String, 0x100u, L"RESERVED");
          }
          else if ( v30 & 0x8000000 )
          {
            SetDlgItemTextW(hWnd, 1024, L"Type:");
            wcscpy_s(&String, 0x100u, L"COMMITED");
          }
          SetDlgItemTextW(hWnd, 1022, &String);
          SetDlgItemTextW(hWnd, 1028, L"Size:");
          wsprintf(&String, L"0x%08x", v31[0]);
          SetDlgItemTextW(hWnd, 1027, &String);
        }
LABEL_94:
        CloseHandle(InBuffer);
        return 1;
      }
      SetDlgItemTextW(hWnd, 1025, L"Event Info");
      SetDlgItemTextW(hWnd, 1024, L"Type:");
      NtQueryEvent(InBuffer, 0, &v35, 8, &ReturnedLength);
      v16 = L"Notification";
      if ( v35 )
        v16 = L"Synchronization";
      wsprintf(&String, L"%s", v16);
      SetDlgItemTextW(hWnd, 1022, &String);
      SetDlgItemTextW(hWnd, 1028, L"Signaled:");
      v17 = L"TRUE";
      if ( !v36 )
        v17 = L"FALSE";
      wsprintf(&String, L"%s", v17);
    }
    else
    {
      SetDlgItemTextW(hWnd, 1025, L"Semaphore Info");
      SetDlgItemTextW(hWnd, 1024, L"Count:");
      NtSetInformationProcess_0(InBuffer, 0, v40, 8, &ReturnedLength);
      wsprintf(&String, L"%d", v40[0]);
      SetDlgItemTextW(hWnd, 1022, &String);
      SetDlgItemTextW(hWnd, 1028, L"Limit:");
      wsprintf(&String, L"%d", v41[0]);
    }
    SetDlgItemTextW(hWnd, 1027, &String);
    goto LABEL_94;
  }
  if ( a2 == 273 && a3 - 1 <= 1 )
  {
LABEL_5:
    DestroyWindow(hWnd);
    return 1;
  }
  return 0;
}
// FE10E0: could not find valid save-restore pair for ebx
// 10448C0: using guessed type wchar_t aADiskFileCommu[59];
// 1044950: using guessed type wchar_t aAnObjectManage[39];
// 10449C0: using guessed type wchar_t aAnObjectManage_0[34];
// 1044A0C: using guessed type wchar_t aARegistryKey[16];
// 1044A30: using guessed type wchar_t aContainsThread[49];
// 1044A98: using guessed type wchar_t aAnObjectThatEx[38];
// 1044B00: using guessed type wchar_t aAnAsynchronous[41];
// 1044B68: using guessed type wchar_t aASynchronizati[42];
// 1044C30: using guessed type wchar_t aContainsOneOrM[44];
// 1044C98: using guessed type wchar_t aContainsApplic[30];
// 1044D00: using guessed type wchar_t aAnInterprocess[41];
// 1044D68: using guessed type wchar_t aAMemoryMappedF[58];
// 1044DDC: using guessed type wchar_t aIdentifiesASec[31];
// 1044E28: using guessed type wchar_t aATimeBasedSync[37];
// 1044E74: using guessed type wchar_t aSymboliclink_0[13];
// 1044FA4: using guessed type wchar_t aNotification[13];
// 1044FC0: using guessed type wchar_t aSynchronizatio[16];
// 104504C: using guessed type wchar_t aImage_0[6];
// 1045058: using guessed type wchar_t aFile_2[5];
// 1045064: using guessed type wchar_t aReserved[9];
// 10450D8: using guessed type wchar_t aObjectDoesNotE[23];
// 106F228: using guessed type int (__stdcall *NtSetInformationProcess_0)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 106F230: using guessed type int (__stdcall *NtQueryEvent)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 106F234: using guessed type int (__stdcall *NtQueryMutant)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD);

//----- (00FE1C00) --------------------------------------------------------
int __stdcall PropSecurity(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
  int result; // eax
  HWND v5; // edi
  HWND v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // ecx
  char v11; // al
  void *v12; // esi
  HWND v13; // eax
  unsigned int v14; // edx
  const unsigned __int16 *v15; // ebx
  __int16 *v16; // ecx
  __int16 v17; // ax
  WCHAR *v18; // esi
  WCHAR v19; // ax
  unsigned int v20; // edx
  HWND hWnda; // [esp+8h] [ebp+8h]

  if ( msg == WM_INITDIALOG )
  {
    v5 = hDlg;
    PostMessageW(hDlg, 0x46Bu, 0, 0);
    dword_107C038 = *(lParam + 0x1C);
    hWnda = PE_DuplicateProcessHandle(*(dword_107C038 + 36), *(dword_107C038 + 44), 0x80000000);
    if ( hWnda )
    {
      byte_107C083 = 0;
      byte_107C084 = 0;
      byte_107C085 = 0;
      byte_107C082 = 0;
      v7 = wcscmp((dword_107C038 + 0x38), L"Directory");
      if ( v7 )
        v7 = -(v7 < 0) | 1;
      if ( v7 )
      {
        v8 = wcscmp((dword_107C038 + 0x38), L"Device");
        if ( v8 )
          v8 = -(v8 < 0) | 1;
        if ( v8 )
        {
          v9 = wcscmp((dword_107C038 + 0x38), L"Process");
          if ( v9 )
            v9 = -(v9 < 0) | 1;
          if ( v9 )
          {
            v10 = wcscmp((dword_107C038 + 0x38), L"Key");
            if ( v10 )
              v10 = -(v10 < 0) | 1;
            v11 = byte_107C084;
            if ( !v10 )
              v11 = 1;
            byte_107C084 = v11;
          }
          else
          {
            byte_107C082 = 1;
          }
        }
        else
        {
          byte_107C085 = 1;
        }
      }
      else
      {
        byte_107C083 = 1;
      }
      wParam = 23;
      byte_107C080 = GetUserObjectSecurity(hWnda, &wParam, pSID, 0x2000u, &msg) != 0;
      CloseHandle(hWnda);
    }
    else
    {
      byte_107C080 = 0;
      v6 = GetDlgItem(v5, 127);
      EnableWindow(v6, 0);
    }
    v12 = PE_DuplicateProcessHandle(*(dword_107C038 + 36), *(dword_107C038 + 44), 0x81000000);
    if ( v12 || (v12 = PE_DuplicateProcessHandle(*(dword_107C038 + 36), *(dword_107C038 + 44), 0x1000000u)) != 0 )
    {
      wParam = 9;
      byte_107C081 = GetUserObjectSecurity(v12, &wParam, ObjectSecurity, 0x2000u, &msg) != 0;
      CloseHandle(v12);
    }
    else
    {
      byte_107C081 = 0;
      v13 = GetDlgItem(v5, 128);
      EnableWindow(v13, 0);
    }
    v14 = 0;
    v15 = (dword_107C038 + 184);
    v16 = (dword_107C038 + 184);
    do
    {
      v17 = *v16;
      ++v16;
    }
    while ( v17 );
    if ( (v16 - dword_107C038 - 186) >> 1 )
    {
      v18 = (dword_107C038 + 184);
      do
      {
        v19 = *v18;
        ++v18;
        gObjectName[v14++] = v19;
      }
      while ( v14 < wcslen(v15) );
    }
    v20 = v14;
    if ( v20 >= 1024 )
    {
      __report_rangecheckfailure();
      JUMPOUT(*algn_FE224B);
    }
    gAclDlgControl.Version = 257;
    gObjectName[v20] = 0;
    if ( byte_107C084 )
    {
      gAclDlgControl.GenericAccessMap = RegistryAccessMasks;
      gAclDlgControl.SpecificAccessMap = RegistryAccessMasks;
    }
    else
    {
      gAclDlgControl.GenericAccessMap = AccessMasks;
      gAclDlgControl.SpecificAccessMap = AccessMasks;
    }
    gAclDlgControl.Reserved = 0;
    gAclDlgControl.SubReplaceTitle = 0;
    gAclDlgControl.SubReplaceConfirmation = 0;
    result = 1;
    gAclDlgControl.DialogTitle = aObject_0;
    gAclDlgControl.HelpInfo = &HelpInfo;
    gAclDlgControl.SpecialAccess = aSpecialAccess;
    return result;
  }
  if ( msg != 273 )
    return 0;
  if ( wParam != 127 )
  {
    if ( wParam == 128 )
    {
      if ( !byte_107C081 )
      {
        MessageBoxW(0, L"You do not have permission to view the Audit Information for\nthis object.", L"WinObj", 0x10u);
        return 0;
      }
      gAclEditControl.NumberOfEntries = 7;
      gAclEditControl.Entries = aclEditEntryFile;
      dword_107C040 = *(dword_107C038 + 44);
      dword_107C03C = *(dword_107C038 + 36);
      dword_107C044 = 1;
      dword_107C048 = dword_107BC38;
      dword_107C04C = ObjectSecurity;
      dword_107C050 = &byte_107C081;
      if ( SedSystemAclEditor(
             0,
             0,
             0,
             &gAclDlgControl,
             &gAclEditControl,
             gObjectName,
             pfnAclChangeCallback,
             &dword_107C03C,
             ObjectSecurity,
             0,
             &msg,
             0) )
      {
        MessageBoxW(0, L"The SACL Editor does not understand the Security Information.", L"WinObj", 0x10u);
        return 0;
      }
      return 0;
    }
    if ( wParam == 129 )
    {
      if ( byte_107C080 )
      {
        dword_107C040 = *(dword_107C038 + 44);
        dword_107C03C = *(dword_107C038 + 36);
        dword_107C044 = 2;
        dword_107C048 = dword_107BC38;
        dword_107C04C = pSID;
        dword_107C050 = &byte_107C080;
        wcscpy_s(&gObjectType, 0x400u, L"&Object");
        if ( SedTakeOwnership(
               0,
               0,
               0,
               &gObjectType,
               gObjectName,
               1u,
               pfnAclChangeCallback,
               &dword_107C03C,
               pSID,
               0,
               0,
               &msg,
               &HelpInfo,
               0) )
        {
          if ( IsValidSecurityDescriptor(pSID) )
          {
            MessageBoxW(0, L"The Ownership Editor does not understand the Security Information.", L"WinObj", 0x10u);
            return 0;
          }
          goto LABEL_10;
        }
        return 0;
      }
      goto LABEL_29;
    }
    return 0;
  }
  if ( !byte_107C080 )
  {
LABEL_29:
    MessageBoxW(0, L"You do not have permission to view the Security Information for\nthis object.", L"WinObj", 0x10u);
    return 0;
  }
  if ( !byte_107C083 )
  {
    if ( byte_107C084 )
    {
      gAclEditControl.Entries = stru_10601C0;
    }
    else
    {
      if ( byte_107C085 )
      {
        gAclEditControl.NumberOfEntries = 11;
        gAclEditControl.Entries = stru_1060110;
        goto LABEL_26;
      }
      if ( byte_107C082 )
      {
        gAclEditControl.NumberOfEntries = 14;
        gAclEditControl.Entries = &dword_105FED0;
        goto LABEL_26;
      }
      gAclEditControl.Entries = &HelpInfo.Reserved1;
    }
    gAclEditControl.NumberOfEntries = 12;
    goto LABEL_26;
  }
  gAclEditControl.NumberOfEntries = 22;
  gAclEditControl.Entries = stru_105FFB0;
LABEL_26:
  dword_107C040 = *(dword_107C038 + 44);
  dword_107C03C = *(dword_107C038 + 36);
  dword_107C044 = 0;
  dword_107C048 = dword_107BC38;
  dword_107C04C = pSID;
  dword_107C050 = &byte_107C080;
  if ( !SedDiscretionaryAclEditor(
          0,
          0,
          0,
          &gAclDlgControl,
          &gAclEditControl,
          gObjectName,
          pfnAclChangeCallback,
          &dword_107C03C,
          pSID,
          0,
          0,
          &msg,
          0) )
    return 0;
  if ( !IsValidSecurityDescriptor(pSID) )
  {
LABEL_10:
    MessageBoxW(0, L"The Security Information is invalid.", L"WinObj", 0x10u);
    return 0;
  }
  MessageBoxW(0, L"The ACL Editor does not understand the Security Information.", L"WinObj", 0x10u);
  return 0;
}
// 10067E8: using guessed type int __report_rangecheckfailure(void);
// 105FCB8: using guessed type wchar_t aObject_0[7];
// 105FCE0: using guessed type wchar_t aSpecialAccess[18];
// 105FED0: using guessed type int dword_105FED0;
// 105FFB0: using guessed type _ACLEDITENTRY stru_105FFB0[22];
// 1060110: using guessed type _ACLEDITENTRY stru_1060110[11];
// 10601C0: using guessed type _ACLEDITENTRY stru_10601C0[12];
// 1060280: using guessed type _ACLEDITENTRY aclEditEntryFile[7];
// 10602F0: using guessed type int AccessMasks[4];
// 1060300: using guessed type int RegistryAccessMasks[4];
// 107BC38: using guessed type int dword_107BC38[256];
// 107C038: using guessed type int dword_107C038;
// 107C03C: using guessed type int dword_107C03C;
// 107C040: using guessed type int dword_107C040;
// 107C044: using guessed type int dword_107C044;
// 107C048: using guessed type int dword_107C048;
// 107C04C: using guessed type int dword_107C04C;
// 107C050: using guessed type int dword_107C050;
// 107C080: using guessed type char byte_107C080;
// 107C081: using guessed type char byte_107C081;
// 107C082: using guessed type char byte_107C082;
// 107C083: using guessed type char byte_107C083;
// 107C084: using guessed type char byte_107C084;
// 107C085: using guessed type char byte_107C085;

//----- (00FE2250) --------------------------------------------------------
int __cdecl PE_DuplicateProcessHandle(DWORD dwProcessId, HANDLE hSourceHandle, DWORD dwDesiredAccess)
{
  DWORD dwPid; // edi
  HANDLE ProcessHandle; // esi
  DWORD v5; // ST14_4
  HANDLE v6; // ST0C_4
  HANDLE SourceHandle; // edi
  DWORD DesiredAccess; // ST14_4
  HANDLE TargetHandle; // ST0C_4
  int InBuf[4]; // [esp+8h] [ebp-20h]
  DWORD v12; // [esp+18h] [ebp-10h]
  DWORD BytesReturned; // [esp+1Ch] [ebp-Ch]
  DWORD InBuffer; // [esp+20h] [ebp-8h]
  int pTargetHandle; // [esp+24h] [ebp-4h]

  dwPid = dwProcessId;
  pTargetHandle = 0;
  InBuffer = dwProcessId;
  ProcessHandle = OpenProcess(PROCESS_DUP_HANDLE, 0, dwProcessId);
  dwProcessId = ProcessHandle;
  if ( ProcessHandle )
    goto LABEL_14;
  if ( GetLastError() == ERROR_ACCESS_DENIED )
    DeviceIoControl(ghDriverHandle, CTRLCODE_QUERY_PROCESS_HANDLE, &InBuffer, 4u, &dwProcessId, 4u, &BytesReturned, 0);
  ProcessHandle = dwProcessId;
  if ( dwProcessId )
  {
LABEL_14:
    if ( dwPid <= 8 )
    {
      InBuf[0] = dwPid;
      SourceHandle = hSourceHandle;
      InBuf[3] = hSourceHandle;
      if ( ghDriverHandle == -1
        || !DeviceIoControl(ghDriverHandle, 0x83350014, InBuf, 0x10u, &pTargetHandle, 4u, &v12, 0) )
      {
        DesiredAccess = dwDesiredAccess;
        TargetHandle = GetCurrentProcess();
        DuplicateHandle(ProcessHandle, SourceHandle, TargetHandle, &pTargetHandle, DesiredAccess, 0, 0);
      }
    }
    else
    {
      v5 = dwDesiredAccess;
      v6 = GetCurrentProcess();
      DuplicateHandle(ProcessHandle, hSourceHandle, v6, &pTargetHandle, v5, 0, 0);
    }
    CloseHandle(ProcessHandle);
  }
  return pTargetHandle;
}

//----- (00FE2330) --------------------------------------------------------
int *__thiscall sub_FE2330(int *this, int a2)
{
  int v2; // esi
  int *v3; // edi
  int v4; // ecx
  int *result; // eax
  signed int v6; // ecx
  int v7; // ecx
  int v8; // ecx

  v2 = a2;
  v3 = this;
  v4 = *this;
  if ( *(v4 - 12) > a2 )
    v2 = *(v4 - 12);
  if ( *(v4 - 4) > 1 )
    return sub_FDBDF0(v3, v2);
  v6 = *(v4 - 8);
  if ( v6 < v2 )
  {
    if ( v6 <= 0x40000000 )
    {
      v8 = v6 / 2 + v6;
      if ( v8 < v2 )
        v8 = v2;
      result = sub_FEDE20(v3, v8);
    }
    else
    {
      v7 = v6 + 0x100000;
      if ( v7 < v2 )
        v7 = v2;
      result = sub_FEDE20(v3, v7);
    }
  }
  return result;
}

//----- (00FE23A0) --------------------------------------------------------
int __stdcall PageProcCPU(HWND hWnd, int a2, WPARAM wParam, LONG dwNewLong)
{
  HWND v4; // eax
  int result; // eax
  CResizer *v6; // eax
  LONG v7; // eax
  HWND (__stdcall *v8)(HWND, int); // esi
  HWND v9; // edi
  HWND v10; // esi
  HWND v11; // edi
  HWND v12; // esi
  HWND v13; // edi
  HWND v14; // esi
  CResizer *v15; // edi
  HWND v16; // eax
  HWND v17; // ST2C_4
  HWND v18; // eax
  HWND v19; // ST2C_4
  HWND v20; // eax
  HWND v21; // ST2C_4
  HWND v22; // eax
  HWND v23; // eax
  HWND v24; // eax
  HWND v25; // eax
  HWND v26; // eax
  HWND v27; // eax
  HWND v28; // eax
  HWND v29; // eax
  HWND v30; // eax
  WPARAM v31; // [esp-8h] [ebp-38h]
  CResizer *v32; // [esp+10h] [ebp-20h]
  HWND v33; // [esp+14h] [ebp-1Ch]
  HWND v34; // [esp+18h] [ebp-18h]
  HWND v35; // [esp+1Ch] [ebp-14h]
  int v36; // [esp+2Ch] [ebp-4h]

  GetWindowLongW(hWnd, -21);
  if ( a2 > 0x113 )
  {
    if ( a2 == 307 || a2 == 310 || a2 == 312 )
      return PE_FillControl(hWnd, wParam);
    return 0;
  }
  if ( a2 == 275 || a2 == 5 )
  {
    if ( IsWindowVisible(hWnd) )
    {
      v25 = GetDlgItem(hWnd, 1158);
      SendMessageW(v25, 0x400u, 0, 0);
      v26 = GetDlgItem(hWnd, 2000);
      SendMessageW(v26, 0x400u, 0, 0);
      v27 = GetDlgItem(hWnd, 1161);
      SendMessageW(v27, 0x400u, 0, 0);
      v28 = GetDlgItem(hWnd, 1159);
      SendMessageW(v28, 0x400u, 0, 0);
      v29 = GetDlgItem(hWnd, 1332);
      SendMessageW(v29, 0x400u, 0, 0);
      v30 = GetDlgItem(hWnd, 1330);
      SendMessageW(v30, 0x400u, 0, 0);
      return 0;
    }
    return 0;
  }
  if ( a2 != 272 )
  {
    if ( a2 == 273 )
    {
      switch ( wParam )
      {
        case 0x9C41u:
          v31 = 40014;
          goto LABEL_8;
        case 0x9C42u:
          SetEvent(ghRefreshEventHandle);
          result = 0;
          break;
        case 0x9C9Cu:
        case 0x9C9Du:
          v31 = wParam;
LABEL_8:
          v4 = GetParent(hWnd);
          PostMessageW(v4, 0x111u, v31, 0);
          result = 0;
          break;
        default:
          return 0;
      }
      return result;
    }
    return 0;
  }
  v6 = operator new(0x40u);
  v36 = 0;
  if ( v6 )
    v32 = CResizer::CResizer(v6, hWnd);
  else
    v32 = 0;
  v36 = -1;
  v7 = GetWindowLongW(hWnd, -16);
  SetWindowLongW(hWnd, -16, v7 | 0x2000000);
  SetWindowLongW(hWnd, -21, dwNewLong);
  CreateGraphWindow(hWnd, 1158, *(dwNewLong + 1372));
  CreateGraphWindow(hWnd, 2000, *(dwNewLong + 1372));
  CreateGraphWindow(hWnd, 1161, *(dwNewLong + 908));
  CreateGraphWindow(hWnd, 1159, *(dwNewLong + 908));
  if ( *(dwNewLong + 1064) )
  {
    CreateGraphWindow(hWnd, 1332, *(dwNewLong + 1064));
    CreateGraphWindow(hWnd, 1330, *(dwNewLong + 1064));
  }
  v8 = GetDlgItem;
  if ( *(dwNewLong + 1064) )
  {
    v9 = GetDlgItem(hWnd, 1331);
    v10 = GetDlgItem(hWnd, 1160);
    v33 = GetDlgItem(hWnd, 1157);
    v34 = v10;
    v35 = v9;
    sub_FF0550(v32, 3, &v33);
    v11 = GetDlgItem(hWnd, 1332);
    v12 = GetDlgItem(hWnd, 1161);
    v33 = GetDlgItem(hWnd, 1158);
    v34 = v12;
    v35 = v11;
    sub_FF0550(v32, 3, &v33);
    v13 = GetDlgItem(hWnd, 1330);
    v14 = GetDlgItem(hWnd, 1159);
    v33 = GetDlgItem(hWnd, 2000);
    v35 = v13;
    v15 = v32;
    v34 = v14;
    sub_FF0550(v32, 3, &v33);
    v8 = GetDlgItem;
    v16 = GetDlgItem(hWnd, 1331);
    *&CResizer::AddItem(v32, v16, 1)->m_rect2.right = db_four;
  }
  else
  {
    v17 = GetDlgItem(hWnd, 1160);
    v18 = GetDlgItem(hWnd, 1157);
    v15 = v32;
    sub_FF04E0(v32, v18, v17);
    v19 = GetDlgItem(hWnd, 1161);
    v20 = GetDlgItem(hWnd, 1158);
    sub_FF04E0(v32, v20, v19);
    v21 = GetDlgItem(hWnd, 1159);
    v22 = GetDlgItem(hWnd, 2000);
    sub_FF04E0(v32, v22, v21);
  }
  v23 = v8(hWnd, 1157);
  *&CResizer::AddItem(v15, v23, 1)->m_rect2.right = db_four;
  v24 = v8(hWnd, 1160);
  *&CResizer::AddItem(v15, v24, 1)->m_rect2.right = db_four;
  PropSheet_UpdateTab(hWnd);
  SendMessageW(hWnd, 0x113u, 0, 0);
  return 1;
}
// 103CB38: using guessed type double db_four;

//----- (00FE2810) --------------------------------------------------------
int __stdcall PageProcEnv(HWND hWnd, int a2, WPARAM wParam, int a4)
{
  HWND v4; // ebx
  CResizer *v5; // eax
  LONG v6; // eax
  void (__stdcall *v7)(HWND, UINT, WPARAM, LPARAM); // edi
  HWND v8; // eax
  __int16 *v9; // esi
  __int16 *v10; // ecx
  int v11; // edi
  __int16 i; // ax
  LRESULT v13; // edx
  char *v14; // ecx
  __int16 v15; // ax
  HWND v17; // eax
  LRESULT v18; // esi
  WPARAM v19; // [esp-8h] [ebp-2ACh]
  LPARAM v20; // [esp+10h] [ebp-294h]
  int v21; // [esp+1Ch] [ebp-288h]
  int v22; // [esp+20h] [ebp-284h]
  void *v23; // [esp+44h] [ebp-260h]
  LPARAM lParam; // [esp+48h] [ebp-25Ch]
  LRESULT v25; // [esp+4Ch] [ebp-258h]
  int v26; // [esp+50h] [ebp-254h]
  int v27; // [esp+54h] [ebp-250h]
  int v28; // [esp+58h] [ebp-24Ch]
  __int16 *v29; // [esp+5Ch] [ebp-248h]
  int v30; // [esp+64h] [ebp-240h]
  int v31; // [esp+68h] [ebp-23Ch]
  UINT pnIDs; // [esp+7Ch] [ebp-228h]
  int v33; // [esp+80h] [ebp-224h]
  WORD pnWidths[2]; // [esp+84h] [ebp-220h]
  LPMEASUREITEMSTRUCT lpmis; // [esp+88h] [ebp-21Ch]
  __int16 v36; // [esp+8Ch] [ebp-218h]
  int v37; // [esp+2A0h] [ebp-4h]

  lpmis = a4;
  GetWindowLongW(hWnd, -21);
  lParam = 0;
  memset(&v25, 0, 0x30u);
  v4 = GetDlgItem(hWnd, 1055);
  pnIDs = 1057;
  v33 = 1058;
  pnWidths[0] = MulDiv(100, gLogPixelSize.x, 96);
  pnWidths[1] = MulDiv(100, gLogPixelSize.x, 96);
  if ( a2 > 0x111 )
  {
    if ( a2 == 307 || a2 == 310 || a2 == 312 )
      return PE_FillControl(hWnd, wParam);
    return 0;
  }
  switch ( a2 )
  {
    case 273:
      if ( wParam <= 40093 )
      {
        if ( wParam >= 40092 )
        {
          v19 = wParam;
        }
        else
        {
          if ( wParam != 40001 )
            return 0;
          v19 = 40014;
        }
        v17 = GetParent(hWnd);
        PostMessageW(v17, 0x111u, v19, 0);
        return 0;
      }
      if ( wParam == 40631 )
      {
        v18 = 0;
        if ( SendMessageW(v4, 0x1004u, 0, 0) > 0 )
        {
          do
          {
            v22 = 2;
            v21 = 2;
            SendMessageW(v4, 0x102Bu, v18++, &v20);
          }
          while ( v18 < SendMessageW(v4, 0x1004u, 0, 0) );
          return 0;
        }
      }
      return 0;
    case 43:
      CMainWnd::DrawList(lpmis);
      return 0;
    case 44:
      return CMainWnd::HandleMeasureItem(hWnd, 0x2Cu, wParam, lpmis);
  }
  if ( a2 != 272 )
    return 0;
  v5 = operator new(0x40u);
  v23 = v5;
  v37 = 0;
  if ( v5 )
    CResizer::CResizer(v5, hWnd);
  PropSheet_UpdateTab(hWnd);
  v6 = GetWindowLongW(v4, -16);
  SetWindowLongW(v4, -16, v6 & 0xFFFFFFFD | 1);
  v7 = SendMessageW;
  SendMessageW(v4, 0x1036u, 0x4020u, 16416);
  v8 = SendMessageW(v4, 0x104Eu, 0, 0);
  CTreeList::InitToolTips(v8);
  SetWindowLongW(v4, -4, Proxy_ListCtrlWndProc);
  SendMessageW(v4, 0x30u, ghConfigFont, 0);
  CTreeView::InitListHeader(v4, &pnIDs, pnWidths, 2u);
  v9 = lpmis[33].itemHeight;
  if ( v9 )
  {
    while ( *v9 )
    {
      v10 = &v36;
      v36 = 0;
      v11 = 0;
      for ( i = *v9; i; ++v9 )
      {
        if ( !v11 )
        {
          if ( i == 61 )
          {
            v11 = (v9 + 1);
            *v10 = 0;
          }
          else
          {
            *v10 = i;
            ++v10;
          }
        }
        i = v9[1];
      }
      lParam = 5;
      v29 = &v36;
      v25 = 0x7FFFFFFF;
      v26 = 0;
      v27 = 0;
      v28 = 0;
      v30 = 0;
      v31 = 1;
      v13 = SendMessageW(v4, 0x104Du, 0, &lParam);
      if ( v13 == -1 )
        return 0;
      if ( v11 )
      {
        v14 = v11;
        lpmis = (v11 + 2);
        do
        {
          v15 = *v14;
          v14 += 2;
        }
        while ( v15 );
        if ( ((v14 - lpmis) >> 1) > 0x1FFF )
          *(v11 + 16382) = 0;
        v29 = v11;
        v7 = SendMessageW;
        lParam = 1;
        v25 = v13;
        v26 = 1;
        SendMessageW(v4, 0x104Cu, 0, &lParam);
      }
      else
      {
        v7 = SendMessageW;
      }
      ++v9;
      if ( !v9 )
        break;
    }
  }
  v7(v4, 0x101Eu, 0, 0xFFFF);
  v7(v4, 0x101Eu, 1u, 0xFFFF);
  return 1;
}

//----- (00FE2C20) --------------------------------------------------------
HBRUSH __stdcall PageProcInfo(HWND hWnd, UINT a2, WPARAM a3, TreeViewParamInfo *dwNewLong)
{
  HWND v4; // ebx
  LONG v5; // edx
  Data_t_bstr_t *v6; // esi
  CResizer *v7; // eax
  CResizer *v8; // eax
  HWND v9; // eax
  struct tagResizerItem *v10; // eax
  HWND v11; // eax
  struct tagResizerItem *v12; // eax
  bool v13; // zf
  void *v14; // ST08_4
  void *v15; // ST04_4
  void *v16; // ST00_4
  const WCHAR *v17; // edi
  const WCHAR *v18; // eax
  BOOL v19; // ST2C_4
  HWND v20; // eax
  LPARAM v21; // edi
  BOOL v22; // ST2C_4
  HWND v23; // eax
  HWND v24; // eax
  int v25; // ebx
  HWND v26; // eax
  HWND v27; // eax
  char v28; // al
  HWND v29; // eax
  HWND v30; // eax
  HWND v31; // eax
  OLECHAR *v32; // ST2C_4
  _bstr_t *v33; // edi
  Data_t_bstr_t **v34; // eax
  _bstr_t *v35; // eax
  _bstr_t *v36; // eax
  const WCHAR *v37; // eax
  const WCHAR *v38; // eax
  HWND v39; // eax
  _WORD *v40; // eax
  int v41; // ST2C_4
  HWND v42; // eax
  HWND v43; // eax
  _WORD *v44; // eax
  HWND v45; // eax
  DWORD v46; // edi
  void *v47; // edi
  wchar_t *v48; // eax
  HICON v49; // eax
  LPARAM v50; // ST2C_4
  HWND v51; // eax
  HICON v52; // eax
  LPARAM v53; // ST2C_4
  HWND v54; // eax
  HICON v55; // eax
  LPARAM v56; // ST2C_4
  HWND v57; // eax
  int v58; // eax
  int v59; // ST2C_4
  HWND v60; // eax
  HBRUSH v61; // edi
  const unsigned __int16 *v62; // eax
  int v63; // eax
  HWND v64; // eax
  int v65; // ST2C_4
  HWND v66; // eax
  const WCHAR *v67; // eax
  HWND v68; // eax
  WCHAR *v69; // edi
  char v70; // cl
  int v71; // eax
  int v72; // ST2C_4
  HWND v73; // eax
  HWND v75; // eax
  int v76; // [esp-8h] [ebp-1664h]
  struct _FILETIME LocalFileTime; // [esp+10h] [ebp-164Ch]
  DWORD dwHandle; // [esp+18h] [ebp-1644h]
  _bstr_t v79; // [esp+1Ch] [ebp-1640h]
  _bstr_t v80; // [esp+20h] [ebp-163Ch]
  _bstr_t v81; // [esp+24h] [ebp-1638h]
  _bstr_t v82; // [esp+28h] [ebp-1634h]
  DWORD pdwValue5; // [esp+2Ch] [ebp-1630h]
  char v84[5]; // [esp+33h] [ebp-1629h]
  LPARAM lParam; // [esp+38h] [ebp-1624h]
  HANDLE hObject; // [esp+3Ch] [ebp-1620h]
  LPCWSTR lpString; // [esp+40h] [ebp-161Ch]
  EventItem v88; // [esp+44h] [ebp-1618h]
  WCHAR DateStr; // [esp+860h] [ebp-DFCh]
  WCHAR v90; // [esp+A60h] [ebp-BFCh]
  WCHAR Dest; // [esp+C4Ch] [ebp-A10h]
  WCHAR String; // [esp+E4Ch] [ebp-810h]
  int v93; // [esp+1658h] [ebp-4h]

  v4 = hWnd;
  *&v84[1] = hWnd;
  v88.field_4 = a3;
  lParam = dwNewLong;
  v5 = GetWindowLongW(hWnd, -21);
  v6 = 0;
  lpString = v5;
  v88.strEventTrace.m_Data = 0;
  v93 = 0;
  switch ( a2 )
  {
    case 0x110u:
      v7 = operator new(0x40u);
      pdwValue5 = v7;
      LOBYTE(v93) = 1;
      if ( v7 )
        v8 = CResizer::CResizer(v7, hWnd);
      else
        v8 = 0;
      v88.field_4 = v8;
      LOBYTE(v93) = 0;
      v8->m_nXRatio = 85;
      v8->m_nYRatio = 100;
      v9 = GetDlgItem(hWnd, IDC_DLG_DLLINFO_EDIT_PATH);
      if ( v9 )
      {
        v10 = CResizer::AddItem(v88.field_4, v9, 1);
        *&v10->m_rect1.left = 0i64;
        *&v10->m_rect1.right = db_one;
      }
      v11 = GetDlgItem(hWnd, 1656);
      if ( v11 )
      {
        v12 = CResizer::AddItem(v88.field_4, v11, 1);
        *&v12->m_rect1.left = 0i64;
        *&v12->m_rect1.right = db_one;
      }
      SetWindowLongW(hWnd, -21, dwNewLong);
      wsprintfW(&String, L"%s(%08X) (netsvcs) Properties", dwNewLong[1].field_14, dwNewLong[1].field_1C);
      SetWindowTextW(hWnd, &String);
      v13 = (dwNewLong[1].field_0 & 0x100) == 0;
      lpString = dwNewLong[19].field_20;
      if ( !v13 )
        SetDlgItemTextW(hWnd, 106, L"Path (Image is probably packed):");
      hObject = PE_OpenProcess(0x2000000u, 0, dwNewLong[1].field_1C);
      QueryProcessArguments(hObject, dwNewLong[1].field_1C, &v88.guid, &v88.field_4, &pdwValue5, v84);
      v14 = dwNewLong[20].field_0;
      dwNewLong[20].field_0 = v88.guid.Data1;
      free(v14);
      v15 = dwNewLong[20].field_4;
      dwNewLong[20].field_4 = v88.field_4;
      free(v15);
      v16 = dwNewLong[20].field_8;
      dwNewLong[20].field_8 = pdwValue5;
      free(v16);
      SetDlgItemTextW(hWnd, 1032, dwNewLong[20].field_0);
      SetDlgItemTextW(hWnd, 1035, dwNewLong[20].field_4);
      v17 = L"n/a";
      v18 = L"n/a";
      if ( lpString )
        v18 = lpString;
      SetDlgItemTextW(hWnd, 1015, v18);
      SetDlgItemTextW(hWnd, 1190, *(lParam + 796));
      if ( *(lParam + 828) )
        v17 = *(lParam + 828);
      SetDlgItemTextW(hWnd, 1656, v17);
      v19 = lpString != 0;
      v20 = GetDlgItem(hWnd, 1307);
      EnableWindow(v20, v19);
      v21 = lParam;
      v22 = *(lParam + 828) != 0;
      v23 = GetDlgItem(hWnd, 1306);
      EnableWindow(v23, v22);
      v24 = GetDlgItem(hWnd, 1195);
      ShowWindow(v24, 0);
      if ( gbIsProcessDEPEnabled )
      {
        Fake_GetProcessMitigationPolicy(v21, hObject);
        v25 = *(v21 + 636);
        if ( v25 == -1 )
        {
          wcscpy_s(&String, 0x400u, L"n/a");
        }
        else
        {
          if ( v25 & 1 )
            wcscpy_s(&String, 0x400u, L"Enabled");
          else
            wcscpy_s(&String, 0x400u, L"Disabled");
          if ( v25 & 8 )
            wcscat_s(&String, 0x400u, L" (permanent)");
        }
        v4 = *&v84[1];
        SetDlgItemTextW(*&v84[1], 1202, &String);
      }
      else
      {
        v26 = GetDlgItem(hWnd, 1203);
        ShowWindow(v26, 0);
        v27 = GetDlgItem(hWnd, 1202);
        ShowWindow(v27, 0);
      }
      if ( gdwVersion >= 3 && hObject )
      {
        if ( sub_FDF5C0(hObject, 1, &v88.field_4, 4) )
        {
          _bstr_t::operator=(&v88, &gszNullString);
          v28 = v88.field_4;
          if ( v88.field_4 & 8 )
          {
            _bstr_t::_bstr_t(&v88.guid, L"Disallow-Stripped");
            LOBYTE(v93) = 2;
            _bstr_t::operator+=(&v88.strEventTrace, &v88.guid);
            LOBYTE(v93) = 0;
            _bstr_t::_Free(&v88.guid);
            v28 = v88.field_4;
          }
          if ( v28 & 4 )
          {
            if ( sub_F80440(&v88) )
            {
              _bstr_t::_bstr_t(&v88.guid, L", ");
              LOBYTE(v93) = 3;
              _bstr_t::operator+=(&v88.strEventTrace, &v88.guid);
              LOBYTE(v93) = 0;
              _bstr_t::_Free(&v88.guid);
            }
            _bstr_t::_bstr_t(&v88.guid, L"High-Entropy");
            LOBYTE(v93) = 4;
            _bstr_t::operator+=(&v88.strEventTrace, &v88.guid);
            LOBYTE(v93) = 0;
            _bstr_t::_Free(&v88.guid);
            v28 = v88.field_4;
          }
          if ( v28 & 1 )
          {
            if ( sub_F80440(&v88) )
            {
              _bstr_t::_bstr_t(&v88.guid, L", ");
              LOBYTE(v93) = 5;
              _bstr_t::operator+=(&v88.strEventTrace, &v88.guid);
              LOBYTE(v93) = 0;
              _bstr_t::_Free(&v88.guid);
            }
            _bstr_t::_bstr_t(&v88.guid, L"Bottom-Up");
            LOBYTE(v93) = 6;
            _bstr_t::operator+=(&v88.strEventTrace, &v88.guid);
            LOBYTE(v93) = 0;
            _bstr_t::_Free(&v88.guid);
            v28 = v88.field_4;
          }
          if ( v28 & 2 )
          {
            if ( sub_F80440(&v88) )
            {
              _bstr_t::_bstr_t(&v88.guid, L", ");
              LOBYTE(v93) = 7;
              _bstr_t::operator+=(&v88.strEventTrace, &v88.guid);
              LOBYTE(v93) = 0;
              _bstr_t::_Free(&v88.guid);
            }
            _bstr_t::_bstr_t(&v88.guid, L"Force-Relocate");
            LOBYTE(v93) = 8;
            _bstr_t::operator+=(&v88.strEventTrace, &v88.guid);
            LOBYTE(v93) = 0;
            _bstr_t::_Free(&v88.guid);
          }
          if ( sub_F80440(&v88) )
          {
            v6 = v88.strEventTrace.m_Data;
            if ( v88.strEventTrace.m_Data )
              wcscpy_s(&String, 0x400u, v88.strEventTrace.m_Data->m_wstr);
            else
              wcscpy_s(&String, 0x400u, 0);
          }
          else
          {
            wcscat_s(&String, 0x400u, L"Disabled");
            v6 = v88.strEventTrace.m_Data;
          }
        }
        else
        {
          sub_FDBE70(&String, 0x400u);
        }
      }
      else
      {
        if ( gdwVersion < 1 )
        {
          v29 = GetDlgItem(v4, 1204);
          ShowWindow(v29, 0);
          v30 = GetDlgItem(v4, 1205);
          ShowWindow(v30, 0);
          goto LABEL_56;
        }
        if ( *(v21 + 650) & 0x40 )
        {
          wcscpy_s(&String, 0x400u, L"Enabled");
        }
        else if ( *(v21 + 648) )
        {
          wcscpy_s(&String, 0x400u, L"Disabled");
        }
        else
        {
          wcscpy_s(&String, 0x400u, L"n/a");
        }
      }
      SetDlgItemTextW(v4, 1205, &String);
LABEL_56:
      if ( gdwVersion < 4 )
      {
        v31 = GetDlgItem(v4, 1666);
        ShowWindow(v31, 0);
      }
      else
      {
        if ( *(v21 + 650) & 0x4000 )
        {
          wcscpy_s(&String, 0x400u, L"Enabled");
        }
        else if ( *(v21 + 648) && *(v21 + 650) )
        {
          wcscpy_s(&String, 0x400u, L"Disabled");
        }
        else
        {
          wcscpy_s(&String, 0x400u, L"n/a");
        }
        SetDlgItemTextW(v4, 1666, &String);
      }
      if ( hObject )
        CloseHandle(hObject);
      if ( *(v21 + 784) )
      {
        _bstr_t::_bstr_t(&hObject, *(v21 + 784));
        v13 = *(v21 + 824) == 0;
        LOBYTE(v93) = 9;
        if ( !v13 )
        {
          _bstr_t::_bstr_t(&v88.guid, L")");
          v32 = *(v21 + 824);
          LOBYTE(v93) = 10;
          v33 = _bstr_t::_bstr_t(&v81, v32);
          LOBYTE(v93) = 11;
          v34 = _bstr_t::_bstr_t(&v79, L" (");
          LOBYTE(v93) = 12;
          v35 = _bstr_t::operator+(v34, &v82, v33);
          LOBYTE(v93) = 13;
          v36 = _bstr_t::operator+(&v35->m_Data, &v80, &v88.guid);
          LOBYTE(v93) = 14;
          _bstr_t::operator+=(&hObject, v36);
          _bstr_t::_Free(&v80);
          _bstr_t::_Free(&v82);
          _bstr_t::_Free(&v79);
          _bstr_t::_Free(&v81);
          _bstr_t::_Free(&v88.guid);
          v21 = lParam;
        }
        if ( hObject )
          v37 = *hObject;
        else
          v37 = 0;
        SetDlgItemTextW(v4, 1183, v37);
        LOBYTE(v93) = 0;
        _bstr_t::_Free(&hObject);
      }
      v38 = VerifyImage(v21, gConfig.bVerifySignatures);
      SetDlgItemTextW(v4, 3, v38);
      v39 = GetDlgItem(v4, 1672);
      SetWindowSubclass(v39, EditVTClassCallback, 0, 0);
      sub_1001A50(*(v21 + 844), &String);
      SetDlgItemTextW(v4, 1672, &String);
      v40 = *(v21 + 792);
      if ( v40 && *v40 != 91 )
      {
        v41 = sub_1001C10(*(v21 + 844));
        v42 = GetDlgItem(v4, 1671);
        EnableWindow(v42, v41);
      }
      if ( gbWintrustInited )
      {
        if ( *(v21 + 832) || (v44 = *(v21 + 792)) == 0 || *v44 == 91 )
        {
          v45 = GetDlgItem(v4, 1005);
          EnableWindow(v45, 0);
        }
      }
      else
      {
        v43 = GetDlgItem(v4, 1005);
        ShowWindow(v43, 0);
      }
      wsprintfW(&String, L"n/a");
      if ( lpString )
      {
        v84[1] = unknown_libname_2(255);
        v46 = GetFileVersionInfoSizeW(lpString, &dwHandle);
        v88.guid.Data1 = malloc(v46);
        if ( GetFileVersionInfoW(lpString, 0, v46, v88.guid.Data1) )
        {
          v47 = v88.guid.Data1;
          sub_FD9660(*(v88.guid.Data1 + 52), *(v88.guid.Data1 + 48), &String);
        }
        else
        {
          wsprintfW(&String, L"n/a");
          v47 = v88.guid.Data1;
        }
        free(v47);
        unknown_libname_2(v84[1]);
        v21 = lParam;
      }
      SetDlgItemTextW(v4, 25, &String);
      if ( *(v21 + 640) )
        v48 = _wctime32((v21 + 640));
      else
        v48 = L"n/a";
      SetDlgItemTextW(v4, 30, v48);
      v49 = *(v21 + 56);
      if ( !v49 )
        v49 = LoadIconW(0, 0x7F00);
      v50 = v49;
      v51 = GetDlgItem(v4, 1033);
      SendMessageW(v51, 0x172u, 1u, v50);
      v52 = *(v21 + 56);
      if ( !v52 )
        v52 = LoadIconW(0, 0x7F00);
      v53 = v52;
      v54 = GetParent(v4);
      SendMessageW(v54, 0x80u, 1u, v53);
      if ( *(v21 + 56) )
        v55 = *(v21 + 52);
      else
        v55 = LoadIconW(0, 0x7F00);
      v56 = v55;
      v57 = GetParent(v4);
      SendMessageW(v57, 0x80u, 0, v56);
      SetDlgItemTextW(v4, 35, *(v21 + 72));
      wsprintfW(&String, L"%d K", *(v21 + 900) >> 10);
      SetDlgItemTextW(v4, 1008, &String);
      wsprintfW(&String, L"%d K", *(v21 + 888) >> 10);
      SetDlgItemTextW(v4, 1009, &String);
      if ( *(v21 + 624) )
      {
        FileTimeToLocalFileTime((v21 + 624), &LocalFileTime);
        FileTimeToSystemTime(&LocalFileTime, &v88.guid.Data2);
        GetTimeFormatW(0x400u, 0, &v88.guid.Data2, 0, &String, 512);
        GetDateFormatW(0x400u, 0, &v88.guid.Data2, 0, &DateStr, 128);
        wcscat_s(&String, 0x400u, L"   ");
        wcscat_s(&String, 0x400u, &DateStr);
      }
      else
      {
        wcscpy_s(&String, 0x400u, L"n/a");
      }
      SetDlgItemTextW(v4, 1007, &String);
      SetDlgItemTextW(v4, 19, *(v21 + 88));
      PropSheet_UpdateTab(v4);
      ShowWindow(v4, 1);
      goto LABEL_141;
    case 0x111u:
      if ( LOWORD(v88.field_4) > 1306 )
      {
        if ( LOWORD(v88.field_4) > 40001 )
        {
          if ( LOWORD(v88.field_4) == 40002 )
          {
            SetEvent(ghRefreshEventHandle);
            return 0;
          }
          if ( LOWORD(v88.field_4) - 40092 > 1 )
            return 0;
          v76 = v88.field_4;
        }
        else
        {
          if ( LOWORD(v88.field_4) != 40001 )
          {
            if ( LOWORD(v88.field_4) == 1307 )
            {
              sub_FAB780(hWnd, *(v5 + 792));
              goto LABEL_141;
            }
            if ( LOWORD(v88.field_4) != 1671 )
              return 0;
            if ( SubmitExeToVirusTotalDotCom() )
            {
              v69 = lpString;
              v70 = 0;
              v71 = *(lpString + 211);
              if ( v71 )
              {
                v70 = 1;
                *(v71 + 4) = 6;
              }
              sub_1001C30(v69, 1, v70 != 0);
              v72 = sub_1001C10(*(v69 + 211));
              v73 = GetDlgItem(hWnd, 1671);
              EnableWindow(v73, v72);
              sub_1001A50(*(v69 + 211), &Dest);
              SetDlgItemTextW(hWnd, 1672, &Dest);
              PostMessageW(ghMainWnd, 0x7F9u, 0, *(v69 + 211));
            }
            goto LABEL_141;
          }
          v76 = 40014;
        }
        v75 = GetParent(hWnd);
        PostMessageW(v75, 0x111u, v76, 0);
        return 0;
      }
      if ( LOWORD(v88.field_4) == 1306 )
      {
        sub_FAB780(hWnd, *(v5 + 828));
        goto LABEL_141;
      }
      if ( LOWORD(v88.field_4) > 1004 )
      {
        if ( LOWORD(v88.field_4) == 1005 )
        {
          v67 = VerifyImage(v5, 1);
          SetDlgItemTextW(hWnd, 3, v67);
          v68 = GetDlgItem(hWnd, 1005);
          EnableWindow(v68, 0);
          goto LABEL_141;
        }
        if ( LOWORD(v88.field_4) == 1160 )
        {
          v65 = *(v5 + 68);
          v66 = GetParent(hWnd);
          sub_FC6B90(v66, 40084, v65);
          RefreshMenuWithTreeViewItemStatus(lpString);
          goto LABEL_141;
        }
        return 0;
      }
      switch ( LOWORD(v88.field_4) )
      {
        case 0x3ECu:
          if ( sub_FF8030(*(v5 + 60), *(v5 + 68)) )
          {
            v64 = GetParent(hWnd);
            PostMessageW(v64, 0x471u, 5u, 0);
          }
          break;
        case 1u:
          GetDlgItemTextW(hWnd, 1190, &v88.List._Mysize, 1024);
          v62 = *(lpString + 199);
          if ( !v62 )
            goto LABEL_159;
          v63 = wcscmp(&v88.List._Mysize, v62);
          if ( v63 )
            v63 = -(v63 < 0) | 1;
          if ( v63 )
LABEL_159:
            sub_FC62A0(lpString, &v88.List._Mysize);
          break;
        case 2u:
          break;
        default:
          return 0;
      }
LABEL_141:
      v61 = 1;
LABEL_142:
      if ( v6 && !InterlockedDecrement(&v6->m_RefCount) )
      {
        if ( v6->m_wstr )
        {
          SysFreeString(v6->m_wstr);
          v6->m_wstr = 0;
        }
        if ( v6->m_str )
        {
          j_j__free(v6->m_str);
          v6->m_str = 0;
        }
        j__free(v6);
      }
      return v61;
    case 0x113u:
      GetDlgItemTextW(hWnd, 1672, &v90, 245);
      sub_1001A50(*(lpString + 211), &Dest);
      v58 = wcscmp(&v90, &Dest);
      if ( v58 )
        v58 = -(v58 < 0) | 1;
      if ( v58 )
      {
        SetDlgItemTextW(hWnd, 1672, &Dest);
        v59 = sub_1001C10(*(lpString + 211));
        v60 = GetDlgItem(hWnd, 1671);
        EnableWindow(v60, v59);
      }
      goto LABEL_141;
    case 0x133u:
    case 0x136u:
      goto LABEL_112;
    case 0x138u:
      if ( dwNewLong == GetDlgItem(hWnd, 1672) && sub_1001820(*(lpString + 211)) )
      {
        if ( sub_1002910(*(lpString + 211)) )
          SetTextColor(v88.field_4, 0xFFu);
        else
          SetTextColor(v88.field_4, 0xFF0000u);
        SelectObject(v88.field_4, ghDefaultUnderlineFontHandle);
        v61 = GetSysColorBrush(20);
      }
      else
      {
LABEL_112:
        v61 = PE_FillControl(hWnd, v88.field_4);
      }
      goto LABEL_142;
    default:
      return 0;
  }
}
// FC5410: using guessed type _DWORD __cdecl unknown_libname_2(char);
// 1064E54: using guessed type int gdwVersion;
// 106A390: using guessed type char gbIsProcessDEPEnabled;
// 106A391: using guessed type char gbWintrustInited;

//----- (00FE3C50) --------------------------------------------------------
int __stdcall PageProcJob(HWND hWnd, int a2, WPARAM wParam, LONG dwNewLong)
{
  CResizer *v4; // eax
  void (__stdcall *v5)(HANDLE); // edi
  HWND v6; // edi
  LONG v7; // eax
  LRESULT (__stdcall *v8)(HWND, UINT, WPARAM, LPARAM); // esi
  DWORD *v9; // edi
  DWORD v10; // esi
  DWORD *v11; // eax
  HWND v12; // eax
  LRESULT v13; // eax
  HWND v14; // eax
  HWND v15; // ebx
  LONG v16; // eax
  HWND v17; // eax
  __int16 v18; // ax
  HANDLE v19; // esi
  char v20; // al
  void *v21; // edi
  DWORD v22; // esi
  int result; // eax
  HWND v24; // eax
  WPARAM v25; // [esp-8h] [ebp-1174h]
  LPARAM v26; // [esp+10h] [ebp-115Ch]
  int v27; // [esp+1Ch] [ebp-1150h]
  int v28; // [esp+20h] [ebp-114Ch]
  LPARAM lParam; // [esp+44h] [ebp-1128h]
  LRESULT v30; // [esp+48h] [ebp-1124h]
  int v31; // [esp+4Ch] [ebp-1120h]
  int v32; // [esp+50h] [ebp-111Ch]
  int v33; // [esp+54h] [ebp-1118h]
  wchar_t *v34; // [esp+58h] [ebp-1114h]
  int v35; // [esp+60h] [ebp-110Ch]
  HWND v36; // [esp+64h] [ebp-1108h]
  UINT v37; // [esp+78h] [ebp-10F4h]
  int v38; // [esp+7Ch] [ebp-10F0h]
  UINT pnIDs; // [esp+80h] [ebp-10ECh]
  int v40; // [esp+84h] [ebp-10E8h]
  DWORD dwValue4; // [esp+88h] [ebp-10E4h]
  HANDLE v42; // [esp+8Ch] [ebp-10E0h]
  WORD pnWidths[2]; // [esp+90h] [ebp-10DCh]
  _DWORD *v44; // [esp+94h] [ebp-10D8h]
  HANDLE hObject; // [esp+98h] [ebp-10D4h]
  HWND v46; // [esp+9Ch] [ebp-10D0h]
  HWND v47; // [esp+A0h] [ebp-10CCh]
  size_t ReturnLength; // [esp+A4h] [ebp-10C8h]
  int v49; // [esp+A8h] [ebp-10C4h]
  __int64 JobObjectInformation; // [esp+ACh] [ebp-10C0h]
  __int64 v51; // [esp+B4h] [ebp-10B8h]
  int v52; // [esp+BCh] [ebp-10B0h]
  unsigned int v53; // [esp+C0h] [ebp-10ACh]
  unsigned int v54; // [esp+C4h] [ebp-10A8h]
  char ArgList[4]; // [esp+C8h] [ebp-10A4h]
  char v56[4]; // [esp+CCh] [ebp-10A0h]
  char v57[4]; // [esp+D0h] [ebp-109Ch]
  char v58[4]; // [esp+D4h] [ebp-1098h]
  unsigned int v59; // [esp+10Ch] [ebp-1060h]
  unsigned int v60; // [esp+110h] [ebp-105Ch]
  wchar_t pszText; // [esp+11Ch] [ebp-1050h]
  wchar_t Dst; // [esp+91Ch] [ebp-850h]
  wchar_t v63; // [esp+111Ch] [ebp-50h]
  int v64; // [esp+1168h] [ebp-4h]

  GetWindowLongW(hWnd, -21);
  lParam = 0;
  memset(&v30, 0, 0x30u);
  pnIDs = 3;
  v40 = 4;
  v37 = 1075;
  v38 = 1058;
  pnWidths[0] = MulDiv(100, gLogPixelSize.x, 96);
  pnWidths[1] = MulDiv(100, gLogPixelSize.x, 96);
  if ( a2 > 0x111 )
  {
    if ( a2 == 307 || a2 == 310 || a2 == 312 )
      return PE_FillControl(hWnd, wParam);
    return 0;
  }
  switch ( a2 )
  {
    case 273:
      switch ( wParam )
      {
        case 0x9C41u:
          v25 = 40014;
          goto LABEL_90;
        case 0x9C42u:
          SetEvent(ghRefreshEventHandle);
          result = 0;
          break;
        case 0x9C9Cu:
        case 0x9C9Du:
          v25 = wParam;
LABEL_90:
          v24 = GetParent(hWnd);
          PostMessageW(v24, 0x111u, v25, 0);
          result = 0;
          break;
        default:
          return 0;
      }
      return result;
    case 43:
      CMainWnd::DrawList(dwNewLong);
      return 0;
    case 44:
      return CMainWnd::HandleMeasureItem(hWnd, 0x2Cu, wParam, dwNewLong);
  }
  if ( a2 != 272 )
    return 0;
  v4 = operator new(0x40u);
  v42 = v4;
  v64 = 0;
  if ( v4 )
    CResizer::CResizer(v4, hWnd);
  v64 = -1;
  PropSheet_UpdateTab(hWnd);
  SetWindowLongW(hWnd, -21, dwNewLong);
  QuerySystemHandleInfo(1u);
  v42 = PE_OpenProcess(0x2000000u, 0, *(dwNewLong + 68));
  v5 = CloseHandle;
  if ( PE_IsProcessInJob(v42, *(dwNewLong + 68), &hObject, &dwValue4) )
  {
    if ( *dwValue4 )
      SetDlgItemTextW(hWnd, 1075, dwValue4);
    else
      SetDlgItemTextW(hWnd, 1075, L"<Unnamed Job>");
    v6 = GetDlgItem(hWnd, 1076);
    v46 = v6;
    v7 = GetWindowLongW(v6, -16);
    SetWindowLongW(v6, -16, v7 & 0xFFFFFFFD | 1);
    v8 = SendMessageW;
    SendMessageW(v6, 0x1036u, 0x4020u, 16416);
    gOldListWndProc = SetWindowLongW(v6, -4, Proxy_ListCtrlWndProc);
    SendMessageW(v6, 0x30u, ghConfigFont, 0);
    CTreeView::InitListHeader(v6, &pnIDs, pnWidths, 2u);
    ReturnLength = 1200;
    v9 = malloc(0x4B0u);
    if ( !QueryInformationJobObject(hObject, JobObjectBasicProcessIdList, v9, 0x4B0u, &ReturnLength) )
    {
      do
      {
        if ( GetLastError() != 24 )
          break;
        free(v9);
        v10 = ReturnLength;
        v9 = malloc(ReturnLength);
      }
      while ( !QueryInformationJobObject(hObject, JobObjectBasicProcessIdList, v9, v10, &ReturnLength) );
      v8 = SendMessageW;
    }
    if ( v9 )
    {
      v47 = 0;
      if ( v9[1] )
      {
        v11 = v9 + 2;
        v44 = v9 + 2;
        do
        {
          SystemProcessInfo_GetSystemProcessName(*v11, 0, &pszText, 0x400u);
          wsprintf_s(&v63, L"%d", *v44);
          lParam = 5;
          v34 = &pszText;
          v12 = (v47 + 1);
          v30 = 0x7FFFFFFF;
          v47 = v12;
          v36 = v12;
          v31 = 0;
          v33 = 0;
          v32 = 0;
          v35 = 0;
          v13 = v8(v46, 0x104Du, 0, &lParam);
          if ( v13 == -1 )
            return 0;
          v30 = v13;
          v34 = &v63;
          lParam = 1;
          v31 = 1;
          v8(v46, 0x104Cu, 0, &lParam);
          v11 = v44 + 1;
          ++v44;
        }
        while ( v47 < v9[1] );
      }
      v8(v46, 0x101Eu, 0, 0xFFFF);
      v8(v46, 0x101Eu, 1u, 65534);
      v28 = 3;
      v27 = 3;
      v8(v46, 0x102Bu, 0, &v26);
      SetFocus(v46);
      free(v9);
    }
    v14 = GetDlgItem(hWnd, 1077);
    v15 = v14;
    v47 = v14;
    v16 = GetWindowLongW(v14, -16);
    SetWindowLongW(v15, -16, v16 & 0xFFFFFFFD | 1);
    v8(v15, 0x1036u, 0x4020u, 16416);
    v17 = v8(v15, 0x104Eu, 0, 0);
    CTreeList::InitToolTips(v17);
    gOldListWndProc = SetWindowLongW(v15, -4, Proxy_ListCtrlWndProc);
    v8(v15, 0x30u, ghConfigFont, 0);
    CTreeView::InitListHeader(v15, &v37, pnWidths, 2u);
    QueryInformationJobObject(
      hObject,
      MaxJobObjectInfoClass|JobObjectBasicAccountingInformation,
      &JobObjectInformation,
      0x70u,
      &ReturnLength);
    v18 = v52;
    if ( v52 & 0x2000 )
    {
      sub_FF7F90(v15, L"Kill on Job Close", L"True");
      v18 = v52;
    }
    if ( v18 & 0x400 )
    {
      sub_FF7F90(v15, L"Die on Unhandled Exception", L"True");
      v18 = v52;
    }
    if ( v18 & 0x800 )
    {
      sub_FF7F90(v15, L"Breakaway OK", L"True");
      v18 = v52;
    }
    if ( v18 & 0x1000 )
    {
      sub_FF7F90(v15, L"Silent Breakaway OK", L"True");
      v18 = v52;
    }
    if ( v18 & 0x40 )
    {
      sub_FF7F90(v15, L"Preserve Job Time", L"True");
      v18 = v52;
    }
    if ( v18 & 0x4000 )
    {
      sub_FF7F90(v15, L"Subset Affinity Allowed", L"True");
      v18 = v52;
    }
    if ( v18 & 2 )
    {
      wsprintfW(&Dst, L"%I64d s", JobObjectInformation / 10000000);
      sub_FF7F90(v15, L"Process CPU Limit", &Dst);
      v18 = v52;
    }
    if ( v18 & 4 )
    {
      wsprintfW(&Dst, L"%I64d s", v51 / 10000000);
      sub_FF7F90(v15, L"User CPU Limit", &Dst);
      v18 = v52;
    }
    if ( v18 & 1 )
    {
      wsprintfW(&Dst, L"%d", v53 >> 10);
      sub_FC3290(&Dst, 0x400u);
      wcscat_s(&Dst, 0x400u, L" KB");
      sub_FF7F90(v15, L"Min Working Set", &Dst);
      v18 = v52;
      if ( v52 & 1 )
      {
        wsprintfW(&Dst, L"%d", v54 >> 10);
        sub_FC3290(&Dst, 0x400u);
        wcscat_s(&Dst, 0x400u, L" KB");
        sub_FF7F90(v15, L"Max Working Set", &Dst);
        v18 = v52;
      }
    }
    if ( v18 & 0x100 )
    {
      wsprintfW(&Dst, L"%d", v59 >> 10);
      sub_FC3290(&Dst, 0x400u);
      wcscat_s(&Dst, 0x400u, L" KB");
      sub_FF7F90(v15, L"Process Memory Limit", &Dst);
      v18 = v52;
    }
    if ( v18 & 0x200 )
    {
      wsprintfW(&Dst, L"%d", v60 >> 10);
      sub_FC3290(&Dst, 0x400u);
      wcscat_s(&Dst, 0x400u, L" KB");
      sub_FF7F90(v15, L"Job Memory Limit", &Dst);
      LOBYTE(v18) = v52;
    }
    if ( v18 & 8 )
    {
      wsprintfW(&Dst, L"%d", *ArgList);
      sub_FF7F90(v15, L"Active Processes", &Dst);
      LOBYTE(v18) = v52;
    }
    if ( v18 & 0x10 )
    {
      wsprintfW(&Dst, L"%x", *v56);
      sub_FF7F90(v15, L"Affinity", &Dst);
      LOBYTE(v18) = v52;
    }
    if ( v18 & 0x20 )
    {
      wsprintfW(&Dst, L"%d", *v57);
      sub_FF7F90(v15, L"Priority Class", &Dst);
      LOBYTE(v18) = v52;
    }
    if ( (v18 & 0x80u) != 0 )
    {
      wsprintfW(&Dst, L"%d", *v58);
      sub_FF7F90(v15, L"Scheduling Class", &Dst);
      LOBYTE(v18) = v52;
    }
    if ( v18 & 4 )
    {
      wsprintfW(
        &Dst,
        L"%I64d:%02I64d:%02I64d.%03I64d",
        v51 / 0x861C46800ui64,
        v51 / 0x23C34600ui64 % 0x3C,
        v51 / 10000000 % 60,
        v51 % 10000000 / 10000);
      v15 = v47;
      sub_FF7F90(v47, L"Job Time", &Dst);
      LOBYTE(v18) = v52;
    }
    if ( v18 & 2 )
    {
      wsprintfW(
        &Dst,
        L"%I64d:%02I64d:%02I64d.%03I64d",
        JobObjectInformation / 0x861C46800ui64,
        JobObjectInformation / 0x23C34600ui64 % 0x3C,
        JobObjectInformation / 10000000 % 60,
        JobObjectInformation % 10000000 / 10000);
      v15 = v47;
      sub_FF7F90(v47, L"Process Time", &Dst);
    }
    v19 = hObject;
    QueryInformationJobObject(hObject, JobObjectBasicUIRestrictions, &v49, 4u, &ReturnLength);
    v20 = v49;
    if ( v49 & 0x40 )
    {
      sub_FF7F90(v15, L"Desktop", L"Limited");
      v20 = v49;
    }
    if ( v20 & 0x10 )
    {
      sub_FF7F90(v15, L"Display Settings", L"Limited");
      v20 = v49;
    }
    if ( v20 < 0 )
    {
      sub_FF7F90(v15, L"Exit Windows", L"Limited");
      v20 = v49;
    }
    if ( v20 & 0x20 )
    {
      sub_FF7F90(v15, L"Global Atoms", L"Limited");
      v20 = v49;
    }
    if ( v20 & 1 )
    {
      sub_FF7F90(v15, L"USER Handles", L"Limited");
      v20 = v49;
    }
    if ( v20 & 2 )
    {
      sub_FF7F90(v15, L"Read Clipboard", L"Limited");
      v20 = v49;
    }
    if ( v20 & 8 )
    {
      sub_FF7F90(v15, L"System Parameters", L"Limited");
      v20 = v49;
    }
    if ( v20 & 4 )
      sub_FF7F90(v15, L"Write Clipboard", L"Limited");
    ReturnLength = 2000;
    v21 = malloc(0x7D0u);
    if ( !QueryInformationJobObject(v19, JobObjectSecurityLimitInformation, v21, 0x7D0u, &ReturnLength) )
    {
      do
      {
        if ( GetLastError() != 24 )
          break;
        free(v21);
        v22 = ReturnLength;
        v21 = malloc(ReturnLength);
      }
      while ( !QueryInformationJobObject(hObject, JobObjectSecurityLimitInformation, v21, v22, &ReturnLength) );
    }
    if ( v49 & 1 )
      sub_FF7F90(v15, L"Administrator Access", L"Limited");
    free(v21);
    if ( SendMessageW(v15, 0x1004u, 0, 0) )
    {
      SendMessageW(v15, 0x101Eu, 0, 0xFFFF);
      SendMessageW(v15, 0x101Eu, 1u, 65534);
      v28 = 3;
      v27 = 3;
      SendMessageW(v15, 0x102Bu, 0, &v26);
    }
    v5 = CloseHandle;
    CloseHandle(hObject);
    free(dwValue4);
  }
  else
  {
    SetDlgItemTextW(hWnd, 1075, L"<Access denied>");
  }
  if ( v42 )
    v5(v42);
  return 1;
}
// 103BDE8: using guessed type wchar_t aDesktop_0[8];
// 1045C9C: using guessed type wchar_t aTrue_1[5];
// 1045CA8: using guessed type wchar_t aKillOnJobClose[18];
// 1045CCC: using guessed type wchar_t aDieOnUnhandled[27];
// 1045D04: using guessed type wchar_t aBreakawayOk[13];
// 1045D20: using guessed type wchar_t aSilentBreakawa[20];
// 1045D48: using guessed type wchar_t aPreserveJobTim[18];
// 1045D6C: using guessed type wchar_t aSubsetAffinity[24];
// 1045DAC: using guessed type wchar_t aProcessCpuLimi[18];
// 1045DD0: using guessed type wchar_t aUserCpuLimit[15];
// 1045DF0: using guessed type wchar_t aMinWorkingSet[16];
// 1045E10: using guessed type wchar_t aMaxWorkingSet[16];
// 1045E30: using guessed type wchar_t aProcessMemoryL[21];
// 1045E5C: using guessed type wchar_t aJobMemoryLimit[17];
// 1045E80: using guessed type wchar_t aActiveProcesse[17];
// 1045EAC: using guessed type wchar_t aAffinity[9];
// 1045EC0: using guessed type wchar_t aPriorityClass[15];
// 1045EE0: using guessed type wchar_t aSchedulingClas[17];
// 1045F04: using guessed type wchar_t aJobTime[9];
// 1045F18: using guessed type wchar_t aProcessTime[13];
// 1045F34: using guessed type wchar_t aLimited[8];
// 1045F44: using guessed type wchar_t aDisplaySetting[17];
// 1045F68: using guessed type wchar_t aExitWindows[13];
// 1045F84: using guessed type wchar_t aGlobalAtoms[13];
// 1045FA0: using guessed type wchar_t aUserHandles[13];
// 1045FBC: using guessed type wchar_t aReadClipboard[15];
// 1045FDC: using guessed type wchar_t aSystemParamete[18];
// 1046000: using guessed type wchar_t aWriteClipboard[16];
// 1046020: using guessed type wchar_t aAdministratorA[21];

//----- (00FE4990) --------------------------------------------------------
int __stdcall PageProcGPU(HWND hWnd, int a2, WPARAM wParam, LONG dwNewLong)
{
  HWND v4; // eax
  int result; // eax
  CResizer *v6; // eax
  LONG v7; // eax
  HWND v8; // ebx
  HWND v9; // edi
  HWND v10; // esi
  HWND v11; // ebx
  HWND v12; // edi
  HWND v13; // esi
  HWND v14; // ebx
  HWND v15; // edi
  HWND v16; // esi
  HWND v17; // eax
  HWND v18; // eax
  HWND v19; // eax
  HWND v20; // eax
  HWND v21; // eax
  HWND v22; // eax
  HWND v23; // eax
  HWND v24; // eax
  HWND v25; // eax
  HWND v26; // eax
  HWND v27; // eax
  HWND v28; // eax
  WPARAM v29; // [esp-8h] [ebp-40h]
  CResizer *v30; // [esp+10h] [ebp-28h]
  HWND v31; // [esp+18h] [ebp-20h]
  HWND v32; // [esp+1Ch] [ebp-1Ch]
  HWND v33; // [esp+20h] [ebp-18h]
  HWND v34; // [esp+24h] [ebp-14h]
  int v35; // [esp+34h] [ebp-4h]

  GetWindowLongW(hWnd, -21);
  if ( a2 > 0x113 )
  {
    if ( a2 == 307 || a2 == 310 || a2 == 312 )
      return PE_FillControl(hWnd, wParam);
    return 0;
  }
  if ( a2 == 275 || a2 == 5 )
  {
    if ( IsWindowVisible(hWnd) )
    {
      v21 = GetDlgItem(hWnd, 1158);
      SendMessageW(v21, 0x400u, 0, 0);
      v22 = GetDlgItem(hWnd, 2000);
      SendMessageW(v22, 0x400u, 0, 0);
      v23 = GetDlgItem(hWnd, 1160);
      SendMessageW(v23, 0x400u, 0, 0);
      v24 = GetDlgItem(hWnd, 2601);
      SendMessageW(v24, 0x400u, 0, 0);
      v25 = GetDlgItem(hWnd, 1162);
      SendMessageW(v25, 0x400u, 0, 0);
      v26 = GetDlgItem(hWnd, 2602);
      SendMessageW(v26, 0x400u, 0, 0);
      v27 = GetDlgItem(hWnd, 1164);
      SendMessageW(v27, 0x400u, 0, 0);
      v28 = GetDlgItem(hWnd, 2603);
      SendMessageW(v28, 0x400u, 0, 0);
      return 0;
    }
    return 0;
  }
  if ( a2 == 272 )
  {
    v6 = operator new(0x40u);
    v35 = 0;
    if ( v6 )
      v30 = CResizer::CResizer(v6, hWnd);
    else
      v30 = 0;
    v35 = -1;
    v7 = GetWindowLongW(hWnd, -16);
    SetWindowLongW(hWnd, -16, v7 | 0x2000000);
    SetWindowLongW(hWnd, -21, dwNewLong);
    CreateGraphWindow(hWnd, 1158, *(dwNewLong + 1392));
    CreateGraphWindow(hWnd, 2000, *(dwNewLong + 1392));
    CreateGraphWindow(hWnd, 1160, *(dwNewLong + 1432));
    CreateGraphWindow(hWnd, 2601, *(dwNewLong + 1432));
    CreateGraphWindow(hWnd, 1162, *(dwNewLong + 1416));
    CreateGraphWindow(hWnd, 2602, *(dwNewLong + 1416));
    CreateGraphWindow(hWnd, 1164, *(dwNewLong + 1448));
    CreateGraphWindow(hWnd, 2603, *(dwNewLong + 1448));
    v8 = GetDlgItem(hWnd, 1659);
    v9 = GetDlgItem(hWnd, 1161);
    v10 = GetDlgItem(hWnd, 1159);
    v31 = GetDlgItem(hWnd, 1157);
    v32 = v10;
    v33 = v9;
    v34 = v8;
    sub_FF0550(v30, 4, &v31);
    v11 = GetDlgItem(hWnd, 1164);
    v12 = GetDlgItem(hWnd, 1162);
    v13 = GetDlgItem(hWnd, 1160);
    v31 = GetDlgItem(hWnd, 1158);
    v32 = v13;
    v33 = v12;
    v34 = v11;
    sub_FF0550(v30, 4, &v31);
    v14 = GetDlgItem(hWnd, 2603);
    v15 = GetDlgItem(hWnd, 2602);
    v16 = GetDlgItem(hWnd, 2601);
    v31 = GetDlgItem(hWnd, 2000);
    v33 = v15;
    v32 = v16;
    v34 = v14;
    sub_FF0550(v30, 4, &v31);
    v17 = GetDlgItem(hWnd, 1157);
    *&CResizer::AddItem(v30, v17, 1)->m_rect2.right = db_four;
    v18 = GetDlgItem(hWnd, 1159);
    *&CResizer::AddItem(v30, v18, 1)->m_rect2.right = db_four;
    v19 = GetDlgItem(hWnd, 1161);
    *&CResizer::AddItem(v30, v19, 1)->m_rect2.right = db_four;
    v20 = GetDlgItem(hWnd, 1659);
    *&CResizer::AddItem(v30, v20, 1)->m_rect2.right = db_four;
    PropSheet_UpdateTab(hWnd);
    SendMessageW(hWnd, 0x113u, 0, 0);
    return 1;
  }
  if ( a2 != 273 )
    return 0;
  switch ( wParam )
  {
    case 0x9C41u:
      v29 = 40014;
      goto LABEL_8;
    case 0x9C42u:
      SetEvent(ghRefreshEventHandle);
      result = 0;
      break;
    case 0x9C9Cu:
    case 0x9C9Du:
      v29 = wParam;
LABEL_8:
      v4 = GetParent(hWnd);
      PostMessageW(v4, 0x111u, v29, 0);
      result = 0;
      break;
    default:
      return 0;
  }
  return result;
}
// 103CB38: using guessed type double db_four;

//----- (00FE4E40) --------------------------------------------------------
signed int __stdcall PageProcPerf(HWND hWnd, unsigned int a2, HDC hdc, int a4)
{
  HWND v4; // ebx
  char *v5; // esi
  HICON v6; // ST50_4
  HWND v7; // eax
  char *v8; // esi
  HANDLE v9; // edi
  HWND v10; // eax
  HWND v11; // eax
  HWND v12; // eax
  signed int result; // eax
  HWND v14; // eax
  HANDLE v15; // edi
  void (__stdcall *v16)(HWND, int, LPCWSTR); // esi
  const WCHAR *v17; // eax
  const WCHAR *v18; // eax
  const WCHAR *v19; // eax
  const WCHAR *v20; // eax
  const WCHAR *v21; // eax
  const WCHAR *v22; // eax
  __m128i *v23; // eax
  const WCHAR *v24; // eax
  int v25; // ecx
  const WCHAR *v26; // ST50_4
  const WCHAR *v27; // eax
  const WCHAR *v28; // ST50_4
  char v29; // al
  const WCHAR *v30; // eax
  char v31; // al
  const WCHAR *v32; // eax
  signed __int64 v33; // [esp+4Ch] [ebp-500h]
  char v34; // [esp+54h] [ebp-4F8h]
  int v35; // [esp+60h] [ebp-4ECh]
  char ArgList[4]; // [esp+6Ch] [ebp-4E0h]
  struct _FILETIME LocalFileTime; // [esp+78h] [ebp-4D4h]
  char v38; // [esp+80h] [ebp-4CCh]
  _DWORD v39[2]; // [esp+84h] [ebp-4C8h]
  char v40[4]; // [esp+8Ch] [ebp-4C0h]
  char ProcessInformation[4]; // [esp+90h] [ebp-4BCh]
  char v42[4]; // [esp+94h] [ebp-4B8h]
  char v43[4]; // [esp+98h] [ebp-4B4h]
  int v44; // [esp+9Ch] [ebp-4B0h]
  unsigned int v45; // [esp+A0h] [ebp-4ACh]
  unsigned int v46; // [esp+A4h] [ebp-4A8h]
  HANDLE v47; // [esp+A8h] [ebp-4A4h]
  void *v48; // [esp+ACh] [ebp-4A0h]
  HWND hDlg; // [esp+B0h] [ebp-49Ch]
  ULONG ReturnLength; // [esp+B4h] [ebp-498h]
  char *v51; // [esp+B8h] [ebp-494h]
  struct _SYSTEMTIME SystemTime; // [esp+BCh] [ebp-490h]
  char v53[16]; // [esp+CCh] [ebp-480h]
  __int128 v54; // [esp+DCh] [ebp-470h]
  int v55; // [esp+ECh] [ebp-460h]
  unsigned int v56; // [esp+F0h] [ebp-45Ch]
  unsigned int v57; // [esp+F4h] [ebp-458h]
  char v58[16]; // [esp+F8h] [ebp-454h]
  char v59[16]; // [esp+108h] [ebp-444h]
  __int128 v60; // [esp+118h] [ebp-434h]
  FILETIME FileTime; // [esp+128h] [ebp-424h]
  unsigned __int64 v62; // [esp+138h] [ebp-414h]
  unsigned __int64 v63; // [esp+140h] [ebp-40Ch]
  WCHAR DateStr; // [esp+148h] [ebp-404h]
  WCHAR String; // [esp+348h] [ebp-204h]

  v4 = hWnd;
  hDlg = hWnd;
  v5 = GetWindowLongW(hWnd, -21);
  v48 = 0;
  v51 = v5;
  if ( a2 <= 0x133 )
  {
    if ( a2 != 307 )
    {
      switch ( a2 )
      {
        case 0x100u:
          if ( hdc != 116 )
            return 0;
          PostMessageW(hWnd, 0x113u, 1u, 0);
          result = 0;
          break;
        case 0x110u:
          PropSheet_UpdateTab(hWnd);
          v6 = LoadIconW(ghInstance, 0x6E);
          v7 = GetDlgItem(hWnd, 1119);
          SendMessageW(v7, 0x172u, 1u, v6);
          v8 = malloc(0x60u);
          v48 = v8;
          *v8 = a4;
          v9 = OpenProcess(0x400u, 0, *(a4 + 68));
          if ( v9 || (v9 = OpenProcess(0x1000u, 0, *(*v8 + 68))) != 0 )
          {
            NtQueryInformationProcess(v9, ProcessVmCounters, v8 + 4, 0x2Cu, &ReturnLength);
            NtQueryInformationProcess(v9, ProcessIoCounters, v8 + 48, 0x30u, &ReturnLength);
            if ( NtQueryInformationProcess(v9, ProcessHandleCount, ProcessInformation, 8u, &ReturnLength) )
            {
              v10 = GetDlgItem(hWnd, 1609);
              EnableWindow(v10, 0);
              v11 = GetDlgItem(hWnd, 1052);
              EnableWindow(v11, 0);
              v8 = v48;
            }
            CloseHandle(v9);
          }
          if ( !QueryProcessCycleTime )
          {
            v12 = GetDlgItem(hWnd, 1324);
            SetWindowTextW(v12, L"Context Switch Delta");
          }
          SetWindowLongW(hWnd, -21, v8);
          SendMessageW(hWnd, 0x113u, 0, 0);
          result = 0;
          break;
        case 0x111u:
          switch ( hdc )
          {
            case 0x9C41u:
              v33 = 40014i64;
              goto LABEL_18;
            case 0x9C42u:
              SetEvent(ghRefreshEventHandle);
              result = 0;
              break;
            case 0x9C9Cu:
            case 0x9C9Du:
              v33 = hdc;
LABEL_18:
              v14 = GetParent(hWnd);
              PostMessageW(v14, 0x111u, v33, SHIDWORD(v33));
              result = 0;
              break;
            default:
              return 0;
          }
          break;
        case 0x113u:
          v15 = OpenProcess(0x400u, 0, *(*v5 + 68));
          v47 = v15;
          if ( v15 || (v15 = OpenProcess(0x1000u, 0, *(*v5 + 68)), (v47 = v15) != 0) )
          {
            v16 = SetDlgItemTextW;
            if ( !NtQueryInformationProcess(v15, 0, &v35, 0x18u, &ReturnLength) )
            {
              wsprintf(&String, L"%d", ArgList[0]);
              SetDlgItemTextW(hWnd, 1042, &String);
            }
            if ( !NtQueryInformationProcess(v15, ProcessTimes, &FileTime, 0x20u, &ReturnLength) )
            {
              if ( FileTime )
              {
                FileTimeToLocalFileTime(&FileTime, &LocalFileTime);
                FileTimeToSystemTime(&LocalFileTime, &SystemTime);
                GetTimeFormatW(0x400u, 0, &SystemTime, 0, &String, 128);
                GetDateFormatW(0x400u, 0, &SystemTime, 0, &DateStr, 128);
                wcscat_s(&String, 0x100u, L"   ");
                wcscat_s(&String, 0x100u, &DateStr);
              }
              else
              {
                wcscpy_s(&String, 0x100u, L"n/a");
              }
              SetDlgItemTextW(hWnd, 1007, &String);
              wsprintf(&String, L"%I64d:%02I64d:%02I64d.%03I64d", v62 / 0x861C46800i64);
              SetDlgItemTextW(hDlg, 1012, &String);
              wsprintf(&String, L"%I64d:%02I64d:%02I64d.%03I64d", v63 / 0x861C46800i64);
              SetDlgItemTextW(hDlg, 1013, &String);
              v46 = v62 + v63;
              wsprintf(&String, L"%I64d:%02I64d:%02I64d.%03I64d", (v62 + v63) / 0x861C46800i64);
              v4 = hDlg;
              v16 = SetDlgItemTextW;
              SetDlgItemTextW(hDlg, 1014, &String);
              v15 = v47;
            }
            if ( NtQueryInformationProcess(v15, ProcessIoCounters, v58, 0x30u, &ReturnLength) )
            {
              v23 = v51;
            }
            else
            {
              wsprintf(&String, L"%I64d", v58[0]);
              v17 = sub_FC3290(&String, 0x100u);
              v16(v4, 1041, v17);
              wsprintf(&String, L"%I64d", v58[0] - v51[48]);
              v18 = sub_FC3290(&String, 0x100u);
              v16(v4, 1044, v18);
              wsprintf(&String, L"%I64d", v58[8]);
              v19 = sub_FC3290(&String, 0x100u);
              v16(v4, 1043, v19);
              wsprintf(&String, L"%I64d", v58[8] - v51[56]);
              v20 = sub_FC3290(&String, 0x100u);
              v16(v4, 1050, v20);
              wsprintf(&String, L"%I64d", v59[0]);
              v21 = sub_FC3290(&String, 0x100u);
              v16(v4, 1045, v21);
              wsprintf(&String, L"%I64d", v59[0] - v51[64]);
              v22 = sub_FC3290(&String, 0x100u);
              v16(v4, 1049, v22);
              sub_FB2200(0, &String, 0x100u, COERCE__INT64((v60 - *(v51 + 10))), 0i64, 0i64 >> 63);
              v16(v4, 1334, &String);
              sub_FB2200(0, &String, 0x100u, COERCE__INT64((*&v59[8] - *(v51 + 9))), 0i64, 0i64 >> 63);
              v16(v4, 1333, &String);
              sub_FB2200(0, &String, 0x100u, COERCE__INT64((*(&v60 + 1) - *(v51 + 11))), 0i64, 0i64 >> 63);
              v16(v4, 1051, &String);
              v23 = v51;
              _mm_storeu_si128(v51 + 3, _mm_loadu_si128(v58));
              _mm_storeu_si128(v23 + 4, _mm_loadu_si128(v59));
              _mm_storeu_si128(v23 + 5, _mm_loadu_si128(&v60));
            }
            if ( QueryProcessCycleTime )
            {
              QueryProcessCycleTime(QueryProcessCycleTime, v15);
              wsprintf(&String, L"%I64u", v39[0]);
            }
            else
            {
              wsprintf(&String, L"%I64d", *(v23->m128i_i32[0] + 1336));
            }
            v24 = sub_FC3290(&String, 0x100u);
            v16(v4, 1195, v24);
            if ( NtQueryInformationProcess(v15, ProcessPagePriority, v43, 4u, &ReturnLength) )
              wsprintf(&String, L"n/a", v34);
            else
              wsprintf(&String, L"%d", v43[0]);
            v16(v4, 1339, &String);
            if ( NtQueryInformationProcess(v15, ProcessIoPriority, &v44, 4u, &ReturnLength) )
              wsprintf(&String, L"n/a", v34);
            else
              sub_FF7790(v44, &String, 0x100u);
            v16(v4, 1340, &String);
            v47 = 0;
            sub_FDEB20(v15, &v48, &v47, &v38, &v46, &v45, &hDlg);
            free(v48);
            wsprintf(&String, L"%ld", v46 >> 10);
            sub_FC3290(&String, 0x100u);
            wcscat_s(&String, 0x100u, L" K");
            v16(v4, 1067, &String);
            wsprintf(&String, L"%ld", hDlg >> 10);
            sub_FC3290(&String, 0x100u);
            wcscat_s(&String, 0x100u, L" K");
            v16(v4, 1069, &String);
            wsprintf(&String, L"%ld", v45 >> 10);
            sub_FC3290(&String, 0x100u);
            wcscat_s(&String, 0x100u, L" K");
            v16(v4, 1068, &String);
            if ( !NtQueryInformationProcess(v15, ProcessVmCounters, v53, 0x2Cu, &ReturnLength) )
            {
              wsprintf(&String, L"%ld", v54 >> 10);
              sub_FC3290(&String, 0x100u);
              wcscat_s(&String, 0x100u, L" K");
              v16(v4, 1008, &String);
              wsprintf(&String, L"%ld", *&v53[12] >> 10);
              sub_FC3290(&String, 0x100u);
              wcscat_s(&String, 0x100u, L" K");
              v16(v4, 1064, &String);
              wsprintf(&String, L"%ld", v56 >> 10);
              sub_FC3290(&String, 0x100u);
              wcscat_s(&String, 0x100u, L" K");
              v16(v4, 1009, &String);
              wsprintf(&String, L"%ld", v57 >> 10);
              sub_FC3290(&String, 0x100u);
              wcscat_s(&String, 0x100u, L" K");
              v16(v4, 1010, &String);
              wsprintf(&String, L"%I64u", *&v53[4] >> 10);
              sub_FC3290(&String, 0x100u);
              wcscat_s(&String, 0x100u, L" K");
              v16(v4, 1060, &String);
              wsprintf(&String, L"%ld", v53[8]);
              sub_FC3290(&String, 0x100u);
              v16(v4, 1065, &String);
              wsprintf(&String, L"%d", v53[8] - v51[12]);
              sub_FC3290(&String, 0x100u);
              v16(v4, 1066, &String);
              v25 = v51;
              _mm_storeu_si128((v51 + 4), _mm_loadu_si128(v53));
              _mm_storeu_si128((v25 + 20), _mm_loadu_si128(&v54));
              _mm_storel_epi64((v25 + 36), _mm_loadl_epi64(&v55));
              *(v25 + 44) = v57;
            }
            if ( NtQueryInformationProcess(v15, ProcessHandleCount, ProcessInformation, 8u, &ReturnLength) )
            {
              if ( !NtQueryInformationProcess(v15, ProcessHandleCount, v40, 4u, &ReturnLength) )
              {
                wsprintf(&String, L"%d", v40[0]);
                v26 = sub_FC3290(&String, 0x100u);
                v16(v4, 1048, v26);
              }
            }
            else
            {
              wsprintf(&String, L"%d", ProcessInformation[0]);
              v27 = sub_FC3290(&String, 0x100u);
              v16(v4, 1048, v27);
              wsprintf(&String, L"%d", v42[0]);
              v28 = sub_FC3290(&String, 0x100u);
              v16(v4, 1052, v28);
            }
            if ( *GetGuiResources )
            {
              v29 = GetGuiResources(v15, 0);
              wsprintf(&String, L"%d", v29);
              v30 = sub_FC3290(&String, 0x100u);
              v16(v4, 1046, v30);
              v31 = GetGuiResources(v15, 1u);
              wsprintf(&String, L"%d", v31);
              v32 = sub_FC3290(&String, 0x100u);
              v16(v4, 1047, v32);
            }
            CloseHandle(v15);
          }
          result = 1;
          break;
        default:
          return 0;
      }
      return result;
    }
    return PE_FillControl(hWnd, hdc);
  }
  if ( a2 == 310 || a2 == 312 )
    return PE_FillControl(hWnd, hdc);
  if ( a2 == 2033 )
  {
    free(v5);
    DestroyWindow(hWnd);
  }
  return 0;
}

//----- (00FE5E50) --------------------------------------------------------
int __stdcall PageProcPerfETW(HWND hWnd, int a2, HDC hdc, int a4)
{
  void *v4; // eax
  void *v5; // ebx
  _DWORD *v6; // eax
  int result; // eax
  HWND v8; // eax
  const WCHAR *v9; // eax
  const WCHAR *v10; // eax
  const WCHAR *v11; // eax
  const WCHAR *v12; // eax
  const WCHAR *v13; // eax
  const WCHAR *v14; // eax
  const WCHAR *v15; // eax
  const WCHAR *v16; // eax
  const WCHAR *v17; // eax
  const WCHAR *v18; // eax
  const WCHAR *v19; // eax
  const WCHAR *v20; // eax
  signed __int64 v21; // [esp+10h] [ebp-218h]
  WCHAR String; // [esp+24h] [ebp-204h]

  v4 = GetWindowLongW(hWnd, -21);
  v5 = v4;
  if ( a2 <= 0x133 )
  {
    if ( a2 != 307 )
    {
      switch ( a2 )
      {
        case 256:
          if ( hdc != 116 )
            return 0;
          PostMessageW(hWnd, 0x113u, 1u, 0);
          result = 0;
          break;
        case 272:
          PropSheet_UpdateTab(hWnd);
          v6 = malloc(0x60u);
          *v6 = a4;
          SetWindowLongW(hWnd, -21, v6);
          SendMessageW(hWnd, 0x113u, 0, 0);
          result = 0;
          break;
        case 273:
          switch ( hdc )
          {
            case 0x9C41u:
              v21 = 40014i64;
              goto LABEL_11;
            case 0x9C42u:
              SetEvent(ghRefreshEventHandle);
              result = 0;
              break;
            case 0x9C9Cu:
            case 0x9C9Du:
              v21 = hdc;
LABEL_11:
              v8 = GetParent(hWnd);
              PostMessageW(v8, 0x111u, v21, SHIDWORD(v21));
              result = 0;
              break;
            default:
              return 0;
          }
          break;
        case 275:
          wsprintf(&String, L"%u", *(*v4 + 1176));
          v9 = sub_FC3290(&String, 0x100u);
          SetDlgItemTextW(hWnd, 1186, v9);
          wsprintf(&String, L"%u", *(*v5 + 1192));
          v10 = sub_FC3290(&String, 0x100u);
          SetDlgItemTextW(hWnd, 1048, v10);
          wsprintf(&String, L"%u", *(*v5 + 1208));
          v11 = sub_FC3290(&String, 0x100u);
          SetDlgItemTextW(hWnd, 1187, v11);
          wsprintf(&String, L"%u", *(*v5 + 1224));
          v12 = sub_FC3290(&String, 0x100u);
          SetDlgItemTextW(hWnd, 1053, v12);
          wsprintf(&String, L"%u", *(*v5 + 1240));
          v13 = sub_FC3290(&String, 0x100u);
          SetDlgItemTextW(hWnd, 1047, v13);
          wsprintf(&String, L"%u", *(*v5 + 1256));
          v14 = sub_FC3290(&String, 0x100u);
          SetDlgItemTextW(hWnd, 1052, v14);
          sub_FB2200(0, &String, 0x100u, COERCE__INT64(*(*v5 + 1232)), 0i64, 0i64 >> 63);
          SetDlgItemTextW(hWnd, 1336, &String);
          sub_FB2200(0, &String, 0x100u, COERCE__INT64(*(*v5 + 1200)), 0i64, 0i64 >> 63);
          SetDlgItemTextW(hWnd, 1335, &String);
          sub_FB2200(0, &String, 0x100u, COERCE__INT64(*(*v5 + 1264)), 0i64, 0i64 >> 63);
          SetDlgItemTextW(hWnd, 1054, &String);
          sub_FB2200(0, &String, 0x100u, COERCE__INT64(*(*v5 + 1216)), 0i64, 0i64 >> 63);
          SetDlgItemTextW(hWnd, 1204, &String);
          sub_FB2200(0, &String, 0x100u, COERCE__INT64(*(*v5 + 1184)), 0i64, 0i64 >> 63);
          SetDlgItemTextW(hWnd, 1202, &String);
          sub_FB2200(0, &String, 0x100u, COERCE__INT64(*(*v5 + 1248)), 0i64, 0i64 >> 63);
          SetDlgItemTextW(hWnd, 1206, &String);
          wsprintf(&String, L"%u", *(*v5 + 1072));
          v15 = sub_FC3290(&String, 0x100u);
          SetDlgItemTextW(hWnd, 1638, v15);
          wsprintf(&String, L"%u", *(*v5 + 1088));
          v16 = sub_FC3290(&String, 0x100u);
          SetDlgItemTextW(hWnd, 1639, v16);
          wsprintf(&String, L"%u", *(*v5 + 1104));
          v17 = sub_FC3290(&String, 0x100u);
          SetDlgItemTextW(hWnd, 1641, v17);
          wsprintf(&String, L"%u", *(*v5 + 1120));
          v18 = sub_FC3290(&String, 0x100u);
          SetDlgItemTextW(hWnd, 1643, v18);
          wsprintf(&String, L"%u", *(*v5 + 1136));
          v19 = sub_FC3290(&String, 0x100u);
          SetDlgItemTextW(hWnd, 1645, v19);
          wsprintf(&String, L"%u", *(*v5 + 1152));
          v20 = sub_FC3290(&String, 0x100u);
          SetDlgItemTextW(hWnd, 1646, v20);
          sub_FB2200(0, &String, 0x100u, COERCE__INT64(*(*v5 + 1128)), 0i64, 0i64 >> 63);
          SetDlgItemTextW(hWnd, 1644, &String);
          sub_FB2200(0, &String, 0x100u, COERCE__INT64(*(*v5 + 1096)), 0i64, 0i64 >> 63);
          SetDlgItemTextW(hWnd, 1640, &String);
          sub_FB2200(0, &String, 0x100u, COERCE__INT64(*(*v5 + 1160)), 0i64, 0i64 >> 63);
          SetDlgItemTextW(hWnd, 1647, &String);
          sub_FB2200(0, &String, 0x100u, COERCE__INT64(*(*v5 + 1112)), 0i64, 0i64 >> 63);
          SetDlgItemTextW(hWnd, 1205, &String);
          sub_FB2200(0, &String, 0x100u, COERCE__INT64(*(*v5 + 1080)), 0i64, 0i64 >> 63);
          SetDlgItemTextW(hWnd, 1203, &String);
          sub_FB2200(0, &String, 0x100u, COERCE__INT64(*(*v5 + 1144)), 0i64, 0i64 >> 63);
          SetDlgItemTextW(hWnd, 1207, &String);
          result = 1;
          break;
        default:
          return 0;
      }
      return result;
    }
    return PE_FillControl(hWnd, hdc);
  }
  if ( a2 == 310 || a2 == 312 )
    return PE_FillControl(hWnd, hdc);
  if ( a2 == 2033 )
  {
    free(v4);
    DestroyWindow(hWnd);
  }
  return 0;
}

//----- (00FE66A0) --------------------------------------------------------
BOOL __stdcall ProcPropSheet(HWND hDlg, UINT uMsg, WPARAM wParam, PROPITEM *PropItem)
{
  HWND hWndTab; // eax
  HWND hWndTab_1; // ebx
  HWND *v6; // eax
  HWND *v8; // edi
  HWND v9; // eax
  LRESULT v10; // eax
  _DWORD *v11; // ebx
  LRESULT v12; // esi
  char *v13; // edi
  BOOL (__stdcall *v14)(HWND, UINT, WPARAM, LPARAM); // ST14_4
  signed int v15; // edi
  HWND *v16; // esi
  WPARAM v17; // eax
  LRESULT v18; // eax
  WPARAM v19; // ecx
  _DWORD *i; // eax
  CResizer *v21; // eax
  LONG v22; // eax
  LONG v23; // eax
  const wchar_t *v24; // ecx
  WPARAM nTabIndex; // ebx
  WPARAM nTabIndex_1; // esi
  WPARAM nTabIndex_2; // esi
  tagTREEVIEWLISTITEMPARAM *pListItem; // eax
  WPARAM nTabIndex_3; // esi
  WPARAM nTabIndex_4; // esi
  HWND hWndTab_3; // esi
  WPARAM nTabIdx; // ebx
  _DWORD *v33; // eax
  int nTabItem; // ebx
  int v35; // esi
  int nTabItem_1; // esi
  int v37; // ebx
  HANDLE ProcessHandle; // eax
  tagTREEVIEWLISTITEMPARAM *pListItem_1; // ecx
  HANDLE v40; // esi
  bool v41; // zf
  tagTREEVIEWLISTITEMPARAM *pListItem_2; // eax
  int v43; // esi
  int v44; // esi
  void *v45; // esi
  int v46; // esi
  int v47; // esi
  WPARAM v48; // ST14_4
  _DWORD *v49; // eax
  HWND hWnd; // esi
  UINT v51; // eax
  WPARAM nTab; // ecx
  POINT v53; // ST14_8
  HCURSOR v54; // eax
  struct tagPOINT Point; // [esp+10h] [ebp-264h]
  NMHDR lParam; // [esp+18h] [ebp-25Ch]
  tagTCITEMW tcitem; // [esp+24h] [ebp-250h]
  HWND hDlg_1; // [esp+40h] [ebp-234h]
  HWND hWndTab_2; // [esp+44h] [ebp-230h]
  HANDLE hObject; // [esp+48h] [ebp-22Ch]
  struct tagRECT Rect; // [esp+4Ch] [ebp-228h]
  WCHAR pszBuffer[260]; // [esp+5Ch] [ebp-218h]
  int v63; // [esp+270h] [ebp-4h]

  hDlg_1 = hDlg;
  hWndTab = GetDlgItem(hDlg, IDS_PROCPROPSHEET_TABCTRL);
  hWndTab_1 = hWndTab;
  hWndTab_2 = hWndTab;
  v6 = GetWindowLongW(hDlg, GWL_USERDATA);
  hObject = v6;
  if ( uMsg > WM_NOTIFY )
  {
    if ( uMsg == WM_INITDIALOG )
    {
      ShowWindow(hDlg, 0);
      v21 = operator new(0x40u);
      hObject = v21;
      v63 = 0;
      if ( v21 )
        CResizer::CResizer(v21, hDlg);
      v63 = -1;
      SetWindowLongW(hDlg, GWL_USERDATA, PropItem);
      tcitem.mask = 3;
      tcitem.iImage = -1;
      v22 = GetWindowLongW(hWndTab_1, GWL_EXSTYLE);
      SetWindowLongW(hWndTab_1, -20, v22 | WS_EX_CONTROLPARENT);
      v23 = GetWindowLongW(hWndTab_1, -16);
      SetWindowLongW(hWndTab_1, GWL_STYLE, v23 | WS_CLIPCHILDREN);
      if ( PropItem->pListItem )
      {
        TreeViewItemParam_InitGraph(PropItem->pListItem);
        tcitem.pszText = L"Image";
        SendMessageW(hWndTab_1, TCM_INSERTITEMW, 0, &tcitem);
        wcscpy_s(PropItem->PageData[1].szTemplateName, 256u, L"PROCPERF");
        PropItem->PageData[1].nTabId = 2;
        PropItem->PageData[1].PageWndProc = PageProcPerf;
        tcitem.pszText = L"Performance";
        SendMessageW(hWndTab_1, TCM_INSERTITEMW, 1u, &tcitem);
        v24 = L"PROCCPUIO";
        if ( !*(PropItem->pListItem + 266) )
          v24 = L"PROCCPU";
        wcscpy_s(PropItem->PageData[2].szTemplateName, 256u, v24);
        PropItem->PageData[2].nTabId = 4;
        PropItem->PageData[2].PageWndProc = PageProcCPU;
        tcitem.pszText = L"Performance Graph";
        SendMessageW(hWndTab_1, TCM_INSERTITEMW, 2u, &tcitem);
        nTabIndex = 3;
        if ( gbFlagsInProcPropSheet )
        {
          wcscpy_s(PropItem->PageData[3].szTemplateName, 256u, L"PROCPERFETW");
          PropItem->PageData[3].nTabId = 14;
          PropItem->PageData[3].PageWndProc = PageProcPerfETW;
          tcitem.pszText = L"Disk and Network";
          SendMessageW(hWndTab_2, TCM_INSERTITEMW, 3u, &tcitem);
          nTabIndex = 4;
        }
        if ( gdwAdapterRuntingTime )
        {
          nTabIndex_1 = nTabIndex;
          wcscpy_s(PropItem->PageData[nTabIndex].szTemplateName, 256u, L"PROCGPU");
          PropItem->PageData[nTabIndex_1].nTabId = 15;
          PropItem->PageData[nTabIndex_1].PageWndProc = PageProcGPU;
          tcitem.pszText = L"GPU Graph";
          SendMessageW(hWndTab_2, TCM_INSERTITEMW, nTabIndex++, &tcitem);
        }
        if ( *(PropItem->pListItem + 40) & 0x20 )
        {
          nTabIndex_2 = nTabIndex;
          wcscpy_s(PropItem->PageData[nTabIndex].szTemplateName, 256u, L"PROCSERVICES");
          PropItem->PageData[nTabIndex_2].nTabId = 5;
          PropItem->PageData[nTabIndex_2].PageWndProc = PageProcServices;
          tcitem.pszText = L"Services";
          SendMessageW(hWndTab_2, TCM_INSERTITEMW, nTabIndex++, &tcitem);
        }
        pListItem = PropItem->pListItem;
        if ( pListItem && pListItem->bSupportWMIProviders )
        {
          nTabIndex_3 = nTabIndex;
          wcscpy_s(PropItem->PageData[nTabIndex].szTemplateName, 256u, L"PROCWMIPROVIDERS");
          PropItem->PageData[nTabIndex_3].nTabId = 16;
          PropItem->PageData[nTabIndex_3].PageWndProc = PageProcWMIProviders;
          tcitem.pszText = L"WMI Providers";
          SendMessageW(hWndTab_2, TCM_INSERTITEMW, nTabIndex++, &tcitem);
        }
        nTabIndex_4 = nTabIndex;
        wcscpy_s(PropItem->PageData[nTabIndex].szTemplateName, 256u, L"PROCTHREADS");
        PropItem->PageData[nTabIndex_4].nTabId = 6;
        PropItem->PageData[nTabIndex_4].PageWndProc = PageProcThreads;
        hWndTab_3 = hWndTab_2;
        tcitem.pszText = L"Threads";
        SendMessageW(hWndTab_2, TCM_INSERTITEMW, nTabIndex, &tcitem);
        nTabIdx = nTabIndex + 1;
        hObject = PropItem + sizeof(PROPPAGEDATA) * nTabIdx;
        if ( AllocateAndGetUdpExTable2FromStack )
          wcscpy_s(hObject + 6, 256u, L"PROCTCPUDPSTACK");
        else
          wcscpy_s(hObject + 6, 256u, L"PROCTCPUDP");
        v33 = hObject;
        tcitem.pszText = L"TCP/IP";
        *(hObject + 131) = 7;
        v33[132] = PageProcTcpUdp;
        SendMessageW(hWndTab_3, TCM_INSERTITEMW, nTabIdx, &tcitem);
        nTabItem = nTabIdx + 1;
        v35 = nTabItem;
        wcscpy_s(PropItem->PageData[nTabItem].szTemplateName, 256u, L"PROCSECURITY");
        PropItem->PageData[v35].nTabId = 8;
        PropItem->PageData[v35].PageWndProc = PageProcSecurity;
        tcitem.pszText = L"Security";
        SendMessageW(hWndTab_2, TCM_INSERTITEMW, nTabItem++, &tcitem);
        nTabItem_1 = nTabItem;
        wcscpy_s(PropItem->PageData[nTabItem].szTemplateName, 256u, L"PROCENV");
        PropItem->PageData[nTabItem_1].nTabId = 9;
        PropItem->PageData[nTabItem_1].PageWndProc = PageProcEnv;
        tcitem.pszText = L"Environment";
        SendMessageW(hWndTab_2, TCM_INSERTITEMW, nTabItem, &tcitem);
        v37 = nTabItem + 1;
        ProcessHandle = PE_OpenProcess(MAXIMUM_ALLOWED, 0, *(PropItem->pListItem + 17));
        pListItem_1 = PropItem->pListItem;
        v40 = ProcessHandle;
        hObject = ProcessHandle;
        v41 = PE_IsProcessInJob(ProcessHandle, pListItem_1->dwProcessId, 0, 0) == 0;
        pListItem_2 = PropItem->pListItem;
        if ( v41 )
        {
          pListItem_2->dwStyle &= -0x801u;
        }
        else
        {
          pListItem_2->dwStyle |= 0x800u;
          v43 = v37;
          wcscpy_s(PropItem->PageData[v37].szTemplateName, 256u, L"PROCJOB");
          PropItem->PageData[v43].nTabId = 10;
          PropItem->PageData[v43].PageWndProc = PageProcJob;
          tcitem.pszText = L"Job";
          SendMessageW(hWndTab_2, TCM_INSERTITEMW, v37, &tcitem);
          v40 = hObject;
          ++v37;
        }
        if ( v40 )
          CloseHandle(v40);
        if ( ProcessIsNetCclr_0(PropItem->pListItem) )
        {
          v44 = v37;
          wcscpy_s(PropItem->PageData[v37].szTemplateName, 0x100u, L"PROCCLR");
          PropItem->PageData[v44].nTabId = 11;
          PropItem->PageData[v44].PageWndProc = PageProcCclr;
          tcitem.pszText = L".NET Assemblies";
          SendMessageW(hWndTab_2, TCM_INSERTITEMW, v37++, &tcitem);
          if ( !*(PropItem->pListItem + 321) )
          {
            v45 = malloc(0x88u);
            memset(v45, 0, 0x88u);
            *(PropItem->pListItem + 321) = v45;
          }
        }
        if ( *(PropItem->pListItem + 321) )
        {
          CoInitialize(0);
          v46 = v37;
          wcscpy_s(PropItem->PageData[v37].szTemplateName, 0x100u, L"PROCNET");
          PropItem->PageData[v46].nTabId = 12;
          PropItem->PageData[v46].PageWndProc = PageProcNet;
          tcitem.pszText = L".NET Performance";
          SendMessageW(hWndTab_2, TCM_INSERTITEMW, v37++, &tcitem);
        }
        v47 = v37;
        wcscpy_s(PropItem->PageData[v37].szTemplateName, 0x100u, L"PROCSTRINGS");
        PropItem->PageData[v47].nTabId = 13;
        PropItem->PageData[v47].PageWndProc = PageProcStrings;
        tcitem.pszText = L"Strings";
        v48 = v37;
        hWndTab_1 = hWndTab_2;
        SendMessageW(hWndTab_2, TCM_INSERTITEMW, v48, &tcitem);
        v49 = PropItem->pListItem;
        if ( v49[216] )
        {
          swprintf(pszBuffer, L"%s:%d (%s) Properties", v49[15], v49[17], v49[216]);
        }
        else if ( v49[17] < 0 )
        {
          swprintf(pszBuffer, L"%s Properties", v49[15]);
        }
        else
        {
          swprintf(pszBuffer, L"%s:%d Properties", v49[15], v49[17]);
        }
        hWnd = hDlg_1;
        SetWindowTextW(hDlg_1, pszBuffer);
        PropItem->PageData[0].hWnd = CreateDialogParamW(
                                       ghMainInstance,
                                       L"PROCINFO",
                                       hWnd,
                                       PageProcInfo,
                                       PropItem->pListItem);
        PropItem->PageData[0].nTabId = 1;
      }
      else
      {
        hWnd = hDlg_1;
      }
      ShowWindow(PropItem->PageData[0].hWnd, SW_SHOW);
      SetForegroundWindow(hWnd);
      v51 = PropItem->PageData[0].nTabId;
      nTab = 0;
      if ( v51 )
      {
        while ( gConfig.dwDefaultProcPropPage != v51 )
        {
          v51 = *(&PropItem->nTabIndex + 131 * (++nTab + 1));
          if ( !v51 )
            goto LABEL_77;
        }
      }
      else
      {
LABEL_77:
        nTab = 0;
      }
      SendMessageW(hWndTab_1, TCM_SETCURSEL, nTab, 0);
      lParam.idFrom = IDS_PROCPROPSHEET_TABCTRL;
      lParam.code = TCN_SELCHANGE;
      SendMessageW(hWnd, WM_NOTIFY, 0, &lParam);
      if ( gConfig.WindowPlacement[PropWindowplacement].rcNormalPosition.right == gConfig.WindowPlacement[PropWindowplacement].rcNormalPosition.left )
      {
        GetCursorPos(&Point);
        v53.y = Point.y - 408;
        v53.x = Point.x - 385;
        PE_SetWindowPlacement(hWnd, v53);
      }
      else
      {
        sub_FEDC50(hWnd, PropItem->pListItem);
      }
      ShowWindow(hWnd, 5);
      InterlockedDecrement(&gnRefCount);
      v54 = LoadCursorW(0, IDC_ARROW);
      SetCursor(v54);
      return 1;
    }
    if ( uMsg == 273 )
    {
      if ( wParam > 40092 )
      {
        if ( wParam == 40093 )
        {
          v18 = SendMessageW(hWndTab_1, TCM_GETCURSEL, 0, 0);
          v19 = v18 - 1;
          if ( !v18 )
          {
            v19 = 0;
            for ( i = hObject + 1052; *i; ++v19 )
              i += 131;
          }
          SendMessageW(hWndTab_1, TCM_SETCURSEL, v19, 0);
          lParam.idFrom = 1110;
          lParam.code = -551;
          SendMessageW(hDlg, WM_NOTIFY, 0, &lParam);
        }
      }
      else
      {
        if ( wParam == 40092 )
        {
          v17 = SendMessageW(hWndTab_1, TCM_GETCURSEL, 0, 0) + 1;
          if ( !*(hObject + 131 * v17 + 132) )
            v17 = 0;
          SendMessageW(hWndTab_1, TCM_SETCURSEL, v17, 0);
          lParam.idFrom = 1110;
          lParam.code = -551;
          SendMessageW(hDlg_1, WM_NOTIFY, 0, &lParam);
          return 0;
        }
        if ( wParam > 0 && (wParam <= 2 || wParam == 40014) )
        {
          ShowWindow(hDlg, 0);
          v15 = 32;
          v16 = (hObject + 8);
          while ( 1 )
          {
            if ( *v16 )
            {
              SendMessageW(*v16, WM_COMMAND, wParam, 0);
              SendMessageW(*v16, WM_MSG_7F1, 0, 0);
            }
            v16 += 131;
            if ( !--v15 )
            {
              PostMessageW(ghMainWnd, WM_MSG_7ED, 0, *(hObject + 1));
              if ( *(*(hObject + 1) + 1284) )
                CoUninitialize();
              free(hObject);
              GetWindowPlacement(hDlg_1, &gConfig.WindowPlacement[2]);
              DestroyWindow(hDlg_1);
              _endthread();
            }
          }
        }
      }
    }
    return 0;
  }
  if ( uMsg == WM_NOTIFY )
  {
    if ( PropItem->pListItem == 1110 && PropItem->PageData[0].hWnd == -551 )
    {
      v10 = SendMessageW(hWndTab_1, TCM_GETCURSEL, 0, 0);
      v11 = hObject;
      v12 = v10;
      v13 = hObject + 524 * v10;
      hObject = v13;
      gConfig.dwDefaultProcPropPage = *(v13 + 131);
      ShowWindow(v11[131 * *v11 + 2], 0);
      *v11 = v12;
      if ( !*(v13 + 2) )
      {
        v14 = *(v13 + 132);
        v13 = hObject;
        *(hObject + 2) = CreateDialogParamW(ghMainInstance, hObject + 6, hDlg_1, v14, v11[1]);
      }
      ShowWindow(*(v13 + 2), 5);
      return 0;
    }
    return 0;
  }
  if ( uMsg != 5 )
  {
    if ( uMsg == 36 )
    {
      PropItem->PageData[0].hWnd = (2 * gdwVirtualScreenWidth);
      return 0;
    }
    return 0;
  }
  v8 = v6 + 2;
  v9 = 32;
  hDlg_1 = 32;
  do
  {
    if ( *v8 )
    {
      GetWindowRect(hWndTab_1, &Rect);
      SendMessageW(hWndTab_1, TCM_ADJUSTRECT, 0, &Rect);
      MapWindowPoints(0, hDlg, &Rect, 2u);
      MoveWindow(*v8, Rect.left, Rect.top, Rect.right - Rect.left, Rect.bottom - Rect.top, 1);
      InvalidateRect(*v8, 0, 1);
      v9 = hDlg_1;
    }
    v8 += 131;
    v9 = (v9 - 1);
    hDlg_1 = v9;
  }
  while ( v9 );
  return 0;
}
// 100A009: using guessed type int _endthread(void);
// 102CFEC: using guessed type wchar_t aEnvironment[12];
// 1045168: using guessed type wchar_t aSecurity_0[9];
// 1046390: using guessed type wchar_t aPerformance[12];
// 10463A8: using guessed type wchar_t aProccpuio[10];
// 10463CC: using guessed type wchar_t aPerformanceGra[18];
// 1046408: using guessed type wchar_t aDiskAndNetwork[17];
// 104643C: using guessed type wchar_t aGpuGraph[10];
// 104646C: using guessed type wchar_t aServices_0[9];
// 10464A4: using guessed type wchar_t aWmiProviders_0[14];
// 10464D8: using guessed type wchar_t aThreads[8];
// 10464E8: using guessed type wchar_t aProctcpudpstac[16];
// 1046520: using guessed type wchar_t aTcpIp[7];
// 104657C: using guessed type wchar_t aNetAssemblies[16];
// 10465AC: using guessed type wchar_t aNetPerformance[17];
// 10465E8: using guessed type wchar_t aStrings[8];
// 1064E28: using guessed type int gdwVirtualScreenWidth;
// 1065390: using guessed type char gbFlagsInProcPropSheet;

//----- (00FE7240) --------------------------------------------------------
void __cdecl __noreturn CTreeList::BackendFillTreeViewParamThreadProc(tagTREEVIEWLISTITEMPARAM *pItem)
{
  HCURSOR v1; // eax
  PROPITEM *PropItem; // esi
  HWND hDlgSheet; // ebx
  char *v4; // edi
  HWND v5; // eax
  HWND hWndFind; // esi
  DWORD dwRet; // ebx
  PROPPAGEDATA *PageData; // esi
  signed int nPageIndex; // edi
  UINT uMsg; // eax
  struct tagMSG msg; // [esp+Ch] [ebp-2Ch]
  HANDLE Handles[2]; // [esp+28h] [ebp-10h]
  HACCEL hAccel; // [esp+30h] [ebp-8h]
  PROPITEM *v14; // [esp+34h] [ebp-4h]
  tagTREEVIEWLISTITEMPARAM *pInfoa; // [esp+40h] [ebp+8h]

  InterlockedIncrement(&gnRefCount);
  v1 = LoadCursorW(0, IDC_APPSTARTING);
  SetCursor(v1);
  PropItem = malloc(sizeof(PROPITEM));
  v14 = PropItem;
  memset(PropItem, 0, sizeof(PROPITEM));
  PropItem->pListItem = pItem;
  hDlgSheet = CreateDialogParamW(ghMainInstance, L"PROCPROPSHEET", ghMainWnd, ProcPropSheet, PropItem);
  pInfoa = hDlgSheet;
  hAccel = LoadAcceleratorsW(ghMainInstance, L"PROCPROPERTIES");
  while ( !PeekMessageW(&msg, 0, 0, 0, PM_REMOVE) )
  {
LABEL_15:
    Handles[0] = ghTimerRefreshProcPageEventHandle;
    Handles[1] = ghEvent6;
    dwRet = MsgWaitForMultipleObjects(2u, Handles, 0, 0xFFFFFFFF, QS_ALLINPUT);
    if ( dwRet != 2 )
    {
      PageData = PropItem->PageData;
      nPageIndex = 32;
      do
      {
        if ( PageData->hWnd )
        {
          uMsg = WM_USER;
          if ( !dwRet )
            uMsg = WM_TIMER;
          PostMessageW(PageData->hWnd, uMsg, 1u, 0);
        }
        ++PageData;
        --nPageIndex;
      }
      while ( nPageIndex );
      PropItem = v14;
    }
    hDlgSheet = pInfoa;
  }
  while ( 1 )
  {
    v4 = PropItem + sizeof(PROPPAGEDATA) * PropItem->nTabIndex;
    v5 = *(v4 + 2);
    if ( v5 && TranslateAcceleratorW(v5, hAccel, &msg) )
      goto LABEL_14;
    hWndFind = GetPropW(hDlgSheet, L"FindWindow");
    if ( !hWndFind )
    {
LABEL_10:
      if ( !IsDialogMessageW(*(v4 + 2), &msg) && !IsDialogMessageW(hDlgSheet, &msg) )
      {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
      }
      goto LABEL_13;
    }
    if ( IsDialogMessageW(hWndFind, &msg) )
    {
      if ( msg.message != WM_COMMAND || LOWORD(msg.wParam) != 40014 )
        goto LABEL_13;
    }
    else if ( msg.message != WM_COMMAND || LOWORD(msg.wParam) != 40014 )
    {
      goto LABEL_10;
    }
    PostMessageW(hWndFind, WM_COMMAND, IDABORT, 0);
    SetPropW(hDlgSheet, L"FindWindow", 0);
LABEL_13:
    PropItem = v14;
LABEL_14:
    if ( !PeekMessageW(&msg, 0, 0, 0, 1u) )
      goto LABEL_15;
  }
}

//----- (00FE7440) --------------------------------------------------------
int __stdcall sub_FE7440(volatile LONG *lpAddend)
{
  signed int v1; // edi
  HWND v2; // ST0C_4
  DWORD v3; // eax
  void *v4; // ST18_4
  PSID v5; // ST14_4
  DWORD v6; // eax
  HWND v7; // eax
  wchar_t *v8; // eax
  LPARAM v9; // ST18_4
  HWND v10; // eax
  HWND v11; // ST0C_4
  LPARAM lParam; // [esp+Ch] [ebp-46Ch]
  int v14; // [esp+10h] [ebp-468h]
  int v15; // [esp+14h] [ebp-464h]
  int v16; // [esp+2Ch] [ebp-44Ch]
  enum _SID_NAME_USE peUse; // [esp+40h] [ebp-438h]
  WPARAM wParam; // [esp+44h] [ebp-434h]
  WPARAM v19; // [esp+48h] [ebp-430h]
  DWORD cchName; // [esp+4Ch] [ebp-42Ch]
  void *v21; // [esp+50h] [ebp-428h]
  DWORD cchReferencedDomainName; // [esp+54h] [ebp-424h]
  LRESULT v23; // [esp+58h] [ebp-420h]
  PSID Sid; // [esp+5Ch] [ebp-41Ch]
  int v25; // [esp+60h] [ebp-418h]
  WCHAR Name; // [esp+64h] [ebp-414h]
  WCHAR ReferencedDomainName; // [esp+26Ch] [ebp-20Ch]

  lParam = 0;
  memset(&v14, 0, 0x30u);
  EnterCriticalSection((lpAddend + 3));
  v1 = 0;
  v23 = SendMessageW(*(lpAddend + 9), 0x1004u, 0, 0);
  if ( v23 > 0 )
  {
    do
    {
      if ( *(lpAddend + 40) == 1 )
        break;
      lParam = 4;
      v2 = *(lpAddend + 9);
      v14 = v1;
      v15 = 0;
      if ( !SendMessageW(v2, 0x104Bu, 0, &lParam) )
        break;
      v25 = v16;
      v3 = GetLengthSid(*(v16 + 36));
      Sid = malloc(v3);
      v4 = *(v25 + 36);
      v5 = Sid;
      v6 = GetLengthSid(*(v25 + 36));
      CopySid(v6, v5, v4);
      LeaveCriticalSection((lpAddend + 3));
      cchName = 260;
      cchReferencedDomainName = 260;
      if ( LookupAccountSidW(
             &gszNullString,
             Sid,
             &Name,
             &cchName,
             &ReferencedDomainName,
             &cchReferencedDomainName,
             &peUse) )
      {
        if ( ReferencedDomainName )
        {
          wcscat_s(&ReferencedDomainName, 0x104u, L"\\");
          wcscat_s(&ReferencedDomainName, 0x104u, &Name);
        }
        else
        {
          wcscpy_s(&ReferencedDomainName, 0x104u, &Name);
        }
        EnterCriticalSection((lpAddend + 3));
        if ( *(lpAddend + 40) )
          break;
        LeaveCriticalSection((lpAddend + 3));
        v7 = GetParent(*(lpAddend + 9));
        SendMessageW(v7, 0x7F7u, v1, &ReferencedDomainName);
        v21 = *(v25 + 40);
        v8 = _wcsdup(&ReferencedDomainName);
        *(v25 + 40) = v8;
        if ( v21 )
          free(v21);
      }
      EnterCriticalSection((lpAddend + 3));
      free(Sid);
      ++v1;
    }
    while ( v1 < v23 );
  }
  v9 = *(lpAddend + 9);
  v10 = GetParent(*(lpAddend + 9));
  SendMessageW(v10, 0x7F6u, 0, v9);
  LeaveCriticalSection((lpAddend + 3));
  SendMessageW(*(lpAddend + 9), 0x101Eu, 0, 0xFFFF);
  if ( !InterlockedDecrement(lpAddend) )
  {
    DeleteCriticalSection((lpAddend + 3));
    free(lpAddend);
  }
  InvalidateRect(*(lpAddend + 9), 0, 0);
  v19 = nItem;
  v11 = *(lpAddend + 9);
  wParam = 1040;
  SendMessageW(v11, 0x1030u, &wParam, PropProcThreadsSortCallback);
  return 0;
}

//----- (00FE7710) --------------------------------------------------------
int __stdcall PageProcSecurity(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
  LONG v4; // ebx
  CResizer *v5; // eax
  CResizer *v6; // esi
  HWND v7; // eax
  HWND v8; // eax
  HWND v9; // eax
  HWND v10; // eax
  HWND v11; // eax
  struct tagResizerItem *v12; // eax
  HWND v13; // eax
  HWND v14; // eax
  HWND v15; // eax
  HWND v16; // eax
  HWND v17; // eax
  HICON v18; // ST24_4
  HWND v19; // eax
  HICON v20; // ST24_4
  HWND v21; // eax
  HWND v22; // edi
  LONG v23; // eax
  HWND v24; // eax
  struct _IMAGELIST *v25; // edi
  HICON v26; // eax
  HICON v27; // eax
  HWND v28; // esi
  LONG v29; // eax
  LRESULT (__stdcall *SendMessageW)(HWND, UINT, WPARAM, LPARAM); // ebx
  HWND v31; // esi
  HWND v32; // edi
  LONG v33; // eax
  HWND v34; // eax
  void *v35; // esi
  HWND v36; // eax
  HWND v37; // eax
  HWND v38; // eax
  HWND v39; // eax
  HWND v40; // esi
  const WCHAR *v41; // esi
  const WCHAR *v42; // eax
  unsigned __int8 v43; // cl
  void (__stdcall *GetTokenInformatio)(HANDLE, TOKEN_INFORMATION_CLASS, LPVOID, DWORD, PDWORD); // ebx
  DWORD (__stdcall *GetLastError)(); // esi
  unsigned int v46; // eax
  TOKEN_INFORMATION_CLASS TokenClassInfo; // edi
  DWORD v48; // esi
  int *v49; // ebx
  bool v50; // zf
  int *v51; // esi
  void *v52; // edi
  tagTREEVIEWITEMPARAM *v53; // ebx
  DWORD v54; // eax
  void *v55; // eax
  void *v56; // ST20_4
  DWORD v57; // eax
  DWORD v58; // esi
  PSID *v59; // edi
  tagTREEVIEWITEMPARAM *v60; // eax
  tagTREEVIEWITEMPARAM *v61; // ebx
  DWORD v62; // eax
  void *v63; // eax
  PSID v64; // ST24_4
  void *v65; // ST20_4
  DWORD v66; // eax
  HWND v67; // esi
  int v68; // eax
  wchar_t *v69; // eax
  DWORD v70; // esi
  DWORD v71; // esi
  void **v72; // edi
  void **v73; // ecx
  void *v74; // esi
  tagTREEVIEWITEMPARAM *v75; // edi
  DWORD v76; // eax
  void *v77; // eax
  void *v78; // ST20_4
  DWORD v79; // eax
  HWND v80; // esi
  int v81; // eax
  wchar_t *v82; // eax
  unsigned int v83; // ecx
  char *v84; // eax
  int v85; // edi
  DWORD v86; // esi
  TOKEN_PRIVILEGES *v87; // eax
  struct _LUID *v88; // esi
  HWND v89; // esi
  HWND v90; // eax
  HWND v91; // edi
  HWND v93; // eax
  TOKEN_PRIVILEGES *v94; // ebx
  LONG v95; // eax
  HWND v96; // ST18_4
  HWND v97; // ST18_4
  WPARAM v98; // [esp-8h] [ebp-1C10h]
  WCHAR *v99; // [esp-4h] [ebp-1C0Ch]
  LVITEMW Item; // [esp+10h] [ebp-1BF8h]
  UINT v101; // [esp+44h] [ebp-1BC4h]
  int v102; // [esp+48h] [ebp-1BC0h]
  UINT pnIDs; // [esp+4Ch] [ebp-1BBCh]
  int v104; // [esp+50h] [ebp-1BB8h]
  WPARAM wParama; // [esp+54h] [ebp-1BB4h]
  WPARAM v106; // [esp+58h] [ebp-1BB0h]
  DWORD ReturnLength; // [esp+5Ch] [ebp-1BACh]
  DWORD cchName; // [esp+60h] [ebp-1BA8h]
  enum _SID_NAME_USE peUse; // [esp+64h] [ebp-1BA4h]
  WORD v110[2]; // [esp+68h] [ebp-1BA0h]
  WORD pnWidths[2]; // [esp+6Ch] [ebp-1B9Ch]
  DWORD cchReferencedDomainName; // [esp+70h] [ebp-1B98h]
  HWND v113; // [esp+74h] [ebp-1B94h]
  LVITEMW lParama; // [esp+78h] [ebp-1B90h]
  unsigned int v115; // [esp+ACh] [ebp-1B5Ch]
  HANDLE InBuffer; // [esp+B0h] [ebp-1B58h]
  int v117; // [esp+B4h] [ebp-1B54h]
  LPVOID TokenInformation; // [esp+B8h] [ebp-1B50h]
  HWND v119; // [esp+BCh] [ebp-1B4Ch]
  DWORD BytesReturned; // [esp+C0h] [ebp-1B48h]
  DWORD cbSid; // [esp+C4h] [ebp-1B44h]
  DWORD TokenInformationLength; // [esp+C8h] [ebp-1B40h]
  HANDLE OutBuffer; // [esp+CCh] [ebp-1B3Ch]
  HWND hDlg; // [esp+D0h] [ebp-1B38h]
  TOKEN_PRIVILEGES *pTokenPrivileges; // [esp+D4h] [ebp-1B34h]
  tagHANDLELISTITEMPARAM pListParam[1034]; // [esp+D8h] [ebp-1B30h]
  TOKEN_STATISTICS TokenStatisticsInfo; // [esp+1198h] [ebp-A70h]
  WCHAR Name[260]; // [esp+11D0h] [ebp-A38h]
  WCHAR ReferencedDomainName[260]; // [esp+13D8h] [ebp-830h]
  WCHAR Dst[260]; // [esp+15E0h] [ebp-628h]
  WCHAR String[260]; // [esp+17E8h] [ebp-420h]
  WCHAR szBuffer[260]; // [esp+19F0h] [ebp-218h]
  int v133; // [esp+1C04h] [ebp-4h]

  hDlg = hWnd;
  pTokenPrivileges = lParam;
  OutBuffer = 0;
  v4 = GetWindowLongW(hWnd, -21);
  lParama.mask = 0;
  v117 = v4;
  memset(&lParama.iItem, 0, 0x30u);
  pnIDs = 1046;
  v104 = 1049;
  pnWidths[0] = MulDiv(100, gLogPixelSize.x, 96);
  pnWidths[1] = MulDiv(100, gLogPixelSize.x, 96);
  v101 = 1047;
  v102 = 1051;
  v110[0] = MulDiv(100, gLogPixelSize.x, 96);
  v110[1] = MulDiv(100, gLogPixelSize.x, 96);
  if ( msg <= WM_CTLCOLOREDIT )
  {
    if ( msg != WM_CTLCOLOREDIT )
    {
      switch ( msg )
      {
        case WM_ALTTABACTIVE|WM_DESTROY:
          CMainWnd::DrawList(pTokenPrivileges);
          return 0;
        case 0x2Cu:
          return CMainWnd::HandleMeasureItem(hWnd, msg, wParam, pTokenPrivileges);
        case WM_NOTIFY:
          v94 = pTokenPrivileges;
          v95 = pTokenPrivileges->Privileges[0].Luid.HighPart;
          if ( v95 == -108 )
            return sub_FBD040(wParam, pTokenPrivileges);
          if ( v95 == -101 || v95 == -2 )
          {
            v96 = pTokenPrivileges->PrivilegeCount;
            lParama.mask = 4;
            lParama.iItem = ::SendMessageW(v96, 0x100Cu, 0xFFFFFFFF, 2);
            v97 = v94->PrivilegeCount;
            lParama.iSubItem = 0;
            if ( ::SendMessageW(v97, LVM_GETITEMW, 0, &lParama) && lParama.lParam > 1 )
            {
              if ( v94->PrivilegeCount == GetDlgItem(hWnd, 1040) )
              {
                cbSid = 260;
                QueryAuthorityInfoFromSID(lParama.lParam->field_24, String, &cbSid);
                SetDlgItemTextW(hWnd, 1342, String);
              }
              else
              {
                GetDlgItem(hWnd, 1038);
              }
            }
          }
          return 0;
        case WM_INITDIALOG:
          v5 = operator new(0x40u);
          BytesReturned = v5;
          v133 = 0;
          if ( v5 )
            v6 = CResizer::CResizer(v5, hWnd);
          else
            v6 = 0;
          v133 = -1;
          v7 = GetDlgItem(hWnd, 1337);
          if ( v7 )
            CResizer::AddItem(v6, v7, 1)->m_rect1 = 0i64;
          v8 = GetDlgItem(hWnd, 1669);
          if ( v8 )
            CResizer::AddItem(v6, v8, 1)->m_rect1 = 0i64;
          v9 = GetDlgItem(hWnd, 1668);
          if ( v9 )
            CResizer::AddItem(v6, v9, 1)->m_rect1 = 0i64;
          v10 = GetDlgItem(hWnd, 1057);
          if ( v10 )
            CResizer::AddItem(v6, v10, 1)->m_rect1 = 0i64;
          v11 = GetDlgItem(hWnd, 1040);
          if ( v11 )
          {
            v12 = CResizer::AddItem(v6, v11, 1);
            *&v12->m_rect2.left = 0i64;
            *&v12->m_rect2.right = db_one;
          }
          v13 = GetDlgItem(hWnd, 1342);
          if ( v13 )
            CResizer::AddItem(v6, v13, 1)->m_rect2 = stru_1046C70;
          v14 = GetDlgItem(hWnd, 1346);
          if ( v14 )
            CResizer::AddItem(v6, v14, 1)->m_rect2 = stru_1046C70;
          v15 = GetDlgItem(hWnd, 1128);
          if ( v15 )
            CResizer::AddItem(v6, v15, 1)->m_rect2 = stru_1046C70;
          v16 = GetDlgItem(hWnd, 1038);
          if ( v16 )
            CResizer::AddItem(v6, v16, 1)->m_rect2 = stru_1046C70;
          v17 = GetDlgItem(hWnd, 1038);
          if ( v17 )
            CResizer::AddItem(v6, v17, 1)->m_rect2 = stru_1046C70;
          PropSheet_UpdateTab(hWnd);
          v18 = LoadIconW(ghInstance, 0x70);
          v19 = GetDlgItem(hWnd, 1127);
          ::SendMessageW(v19, STM_SETIMAGE, 1u, v18);
          v20 = LoadIconW(ghInstance, 0x6F);
          v21 = GetDlgItem(hWnd, 1128);
          ::SendMessageW(v21, STM_SETIMAGE, 1u, v20);
          SetDlgItemTextW(hWnd, 1342, L"n/a");
          SetDlgItemTextW(hDlg, 1057, L"n/a");
          v22 = GetDlgItem(hDlg, 1040);
          v119 = v22;
          v23 = GetWindowLongW(v22, -16);
          SetWindowLongW(v22, -16, v23 & 0xFFFFFFFD | 1);
          ::SendMessageW(v22, LVM_SETEXTENDEDLISTVIEWSTYLE, 0x4020u, 16416);
          v24 = ::SendMessageW(v22, LVM_GETTOOLTIPS, 0, 0);
          CTreeList::InitToolTips(v24);
          gOldListWndProc = SetWindowLongW(v22, -4, Proxy_ListCtrlWndProc);
          ::SendMessageW(v22, 0x30u, ghConfigFont, 0);
          CTreeView::InitListHeader(v22, &pnIDs, pnWidths, 2u);
          v25 = ImageList_Create(16, 16, 1u, 256, 256);
          v26 = LoadIconW(ghInstance, 0xCB);
          ImageList_ReplaceIcon(v25, -1, v26);
          v27 = LoadIconW(ghInstance, 0x71);
          ImageList_ReplaceIcon(v25, -1, v27);
          v28 = v119;
          v29 = GetWindowLongW(v119, -16);
          SetWindowLongW(v28, -16, v29 | LVS_SHAREIMAGELISTS);
          SendMessageW = ::SendMessageW;
          ::SendMessageW(v28, LVM_SETIMAGELIST, 1u, v25);
          CTreeList::InitHeaderColumn(v28, nItem, nItem, byte_105D224);
          v31 = hDlg;
          v32 = GetDlgItem(hDlg, 1038);
          v113 = v32;
          v33 = GetWindowLongW(v32, -16);
          SetWindowLongW(v32, -16, v33 & 0xFFFFFFFD | 1);
          ::SendMessageW(v32, LVM_SETEXTENDEDLISTVIEWSTYLE, 0x4020u, 16416);
          v34 = ::SendMessageW(v32, LVM_GETTOOLTIPS, 0, 0);
          CTreeList::InitToolTips(v34);
          gOldListWndProc = SetWindowLongW(v32, -4, Proxy_ListCtrlWndProc);
          ::SendMessageW(v32, WM_SETFONT, ghConfigFont, 0);
          CTreeView::InitListHeader(v32, &v101, v110, 2u);
          SetDlgItemTextW(v31, 19, pTokenPrivileges[5].Privileges[0].Luid.HighPart);
          cbSid = 0;
          cchReferencedDomainName = 0;
          LookupAccountNameW(
            0,
            pTokenPrivileges[5].Privileges[0].Luid.HighPart,
            0,
            &cbSid,
            ReferencedDomainName,
            &cchReferencedDomainName,
            &peUse);
          if ( cbSid )
          {
            v35 = malloc(cbSid);
            LookupAccountNameW(
              0,
              pTokenPrivileges[5].Privileges[0].Luid.HighPart,
              v35,
              &cbSid,
              ReferencedDomainName,
              &cchReferencedDomainName,
              &peUse);
            cbSid = 260;
            QueryAuthorityInfoFromSID(v35, String, &cbSid);
            free(v35);
            v31 = hDlg;
          }
          else
          {
            swprintf(String, L"n/a");
          }
          SetDlgItemTextW(v31, 20, String);
          if ( pTokenPrivileges[6].Privileges[0].Luid.LowPart == -1 )
            swprintf(String, L"n/a");
          else
            swprintf(String, L"%d", pTokenPrivileges[6].Privileges[0].Luid.LowPart);
          SetDlgItemTextW(v31, 1056, String);
          if ( gdwVersion >= 1 )
          {
            v41 = L"Yes";
            v42 = L"Yes";
            if ( !(pTokenPrivileges[2].Privileges[0].Luid.HighPart & 0x200) )
              v42 = L"No";
            SetDlgItemTextW(hDlg, 1337, v42);
            if ( pTokenPrivileges[2].Privileges[0].Luid.HighPart & 0x400 && gdwVersion >= 3 )
            {
              v43 = BYTE1(pTokenPrivileges[40].Privileges[0].Luid.HighPart);
              Name[0] = 0;
              if ( (v43 & 0xF0u) < 0x70 )
                wcscat_s(Name, 0x104u, &aPsprotectedsig[64 * (v43 >> 4)]);
              if ( (BYTE1(pTokenPrivileges[40].Privileges[0].Luid.HighPart) & 7) == 1 )
                wcscat_s(Name, 0x104u, L"-Light");
              v99 = Name;
            }
            else
            {
              if ( !(pTokenPrivileges[2].Privileges[0].Luid.HighPart & 0x400) )
                v41 = L"No";
              v99 = v41;
            }
            v40 = hDlg;
            SetDlgItemTextW(hDlg, 1668, v99);
          }
          else
          {
            v36 = GetDlgItem(v31, 1335);
            ShowWindow(v36, 0);
            v37 = GetDlgItem(hDlg, 1337);
            ShowWindow(v37, 0);
            v38 = GetDlgItem(hDlg, 1669);
            ShowWindow(v38, 0);
            v39 = GetDlgItem(hDlg, 1668);
            ShowWindow(v39, 0);
            v40 = hDlg;
          }
          InBuffer = PE_OpenProcess(0x400u, 0, pTokenPrivileges[4].Privileges[0].Luid.LowPart);
          if ( InBuffer )
          {
            if ( !DeviceIoControl(ghDriverHandle, 0x8335000C, &InBuffer, 4u, &OutBuffer, 4u, &BytesReturned, 0) )
              OpenProcessToken(InBuffer, 8u, &OutBuffer);
            if ( OutBuffer )
            {
              GetTokenInformatio = GetTokenInformation;
              TokenStatisticsInfo.AuthenticationId.HighPart = 0;
              TokenStatisticsInfo.AuthenticationId.LowPart = 0;
              ReturnLength = 56;
              GetTokenInformation(OutBuffer, TokenStatistics, &TokenStatisticsInfo, 0x38u, &ReturnLength);
              swprintf_s(
                String,
                0x104u,
                L"%x",
                TokenStatisticsInfo.AuthenticationId.LowPart,
                TokenStatisticsInfo.AuthenticationId.HighPart);
              SetDlgItemTextW(v40, 1057, String);
              GetLastError = ::GetLastError;
              v46 = 0;
              v117 = 0;
              do
              {
                TokenClassInfo = TokenRestrictedSids;
                if ( !v46 )
                  TokenClassInfo = TokenGroups;
                GetTokenInformatio(OutBuffer, TokenClassInfo, 0, 0, &TokenInformationLength);
                if ( GetLastError() == ERROR_INSUFFICIENT_BUFFER )
                {
                  v48 = TokenInformationLength;
                  v49 = malloc(TokenInformationLength);
                  TokenInformation = v49;
                  if ( GetTokenInformation(OutBuffer, TokenClassInfo, v49, v48, &TokenInformationLength) )
                  {
                    v50 = *v49 == 0;
                    v115 = 0;
                    if ( !v50 )
                    {
                      v51 = v49 + 2;
                      do
                      {
                        v52 = *(v51 - 1);
                        v53 = malloc(0x34u);
                        memset(v53, 0, 0x34u);
                        v53->field_2C = *v51;
                        v54 = GetLengthSid(v52);
                        v55 = malloc(v54);
                        v53->field_24 = v55;
                        v56 = v55;
                        v57 = GetLengthSid(v52);
                        CopySid(v57, v56, v52);
                        QueryAuthorityInfoFromSID(v52, String, &cbSid);
                        if ( *GetSidSubAuthority(v52, 0) != 5 || *GetSidSubAuthority(v52, 1u) )
                          swprintf(ReferencedDomainName, L"%s", String);
                        else
                          swprintf(ReferencedDomainName, L"Logon SID (%s)", String);
                        lParama.pszText = ReferencedDomainName;
                        lParama.mask = 5;
                        lParama.iItem = 0x7FFFFFFF;
                        lParama.iSubItem = 0;
                        lParama.state = 0;
                        lParama.stateMask = 0;
                        lParama.iImage = 0;
                        lParama.lParam = v53;
                        BytesReturned = ::SendMessageW(v119, LVM_INSERTITEMW, 0, &lParama);
                        if ( BytesReturned == -1 )
                          return 0;
                        szBuffer[0] = 0;
                        if ( *v51 & 0x10 )
                          wcscpy_s(szBuffer, 0x104u, L"Deny");
                        if ( *v51 & 0x20000000 )
                        {
                          if ( szBuffer[0] )
                            wcscat_s(szBuffer, 0x104u, L", ");
                          wcscat_s(szBuffer, 0x104u, L"Domain-Local");
                        }
                        if ( *v51 & 1 && !(*v51 & 8) )
                        {
                          if ( szBuffer[0] )
                            wcscat_s(szBuffer, 0x104u, L", ");
                          wcscat_s(szBuffer, 0x104u, L"Mandatory");
                        }
                        if ( *v51 & 8 )
                        {
                          if ( szBuffer[0] )
                            wcscat_s(szBuffer, 0x104u, L", ");
                          wcscat_s(szBuffer, 0x104u, L"Owner");
                        }
                        if ( *v51 & 0x20 )
                        {
                          if ( szBuffer[0] )
                            wcscat_s(szBuffer, 0x104u, L", ");
                          if ( *v51 & 0x40 )
                            wcscat_s(szBuffer, 0x104u, L"Integrity");
                          else
                            wcscat_s(szBuffer, 0x104u, L"DesktopIntegrity");
                        }
                        if ( v117 == 1 )
                        {
                          if ( szBuffer[0] )
                            wcscat_s(szBuffer, 0x104u, L", ");
                          wcscat_s(szBuffer, 0x104u, L"Restricted");
                        }
                        lParama.iItem = BytesReturned;
                        lParama.pszText = szBuffer;
                        lParama.mask = 1;
                        lParama.iSubItem = 1;
                        ::SendMessageW(v119, LVM_SETITEMW, 0, &lParama);
                        v53->field_28 = _wcsdup(ReferencedDomainName);
                        v53->field_30 = _wcsdup(szBuffer);
                        v51 += 2;
                        v49 = TokenInformation;
                        ++v115;
                      }
                      while ( v115 < *TokenInformation );
                    }
                  }
                  free(v49);
                  GetTokenInformatio = GetTokenInformation;
                  GetLastError = ::GetLastError;
                }
                v46 = v117 + 1;
                v117 = v46;
              }
              while ( v46 < 2 );
              GetTokenInformatio(OutBuffer, MaxTokenInfoClass|TokenGroups, 0, 0, &TokenInformationLength);
              if ( GetLastError() == 122 )
              {
                v58 = TokenInformationLength;
                v59 = malloc(TokenInformationLength);
                if ( (GetTokenInformatio)(OutBuffer, MaxTokenInfoClass|TokenGroups, v59, v58, &TokenInformationLength)
                  && *v59 )
                {
                  v60 = malloc(0x34u);
                  v61 = v60;
                  BytesReturned = v60;
                  memset(v60, 0, 0x34u);
                  v62 = GetLengthSid(*v59);
                  v63 = malloc(v62);
                  v61->field_24 = v63;
                  v64 = *v59;
                  v65 = v63;
                  v66 = GetLengthSid(*v59);
                  CopySid(v66, v65, v64);
                  QueryAuthorityInfoFromSID(*v59, String, &cbSid);
                  v67 = v119;
                  lParama.pszText = String;
                  lParama.lParam = v61;
                  SendMessageW = ::SendMessageW;
                  lParama.mask = 5;
                  lParama.iItem = 0x7FFFFFFF;
                  lParama.iSubItem = 0;
                  lParama.state = 0;
                  lParama.stateMask = 0;
                  lParama.iImage = 0;
                  v68 = ::SendMessageW(v119, LVM_INSERTITEMW, 0, &lParama);
                  if ( v68 == -1 )
                    return 0;
                  lParama.iItem = v68;
                  lParama.mask = 1;
                  lParama.iSubItem = 1;
                  lParama.pszText = L"AppContainer";
                  ::SendMessageW(v67, LVM_SETITEMW, 0, &lParama);
                  v69 = _wcsdup(String);
                  v70 = BytesReturned;
                  *(BytesReturned + 40) = v69;
                  *(v70 + 48) = _wcsdup(lParama.pszText);
                  free(v59);
                  GetLastError = ::GetLastError;
                }
                else
                {
                  SendMessageW = ::SendMessageW;
                  free(v59);
                  GetLastError = ::GetLastError;
                }
              }
              else
              {
                SendMessageW = ::SendMessageW;
              }
              GetTokenInformation(OutBuffer, TokenLogonSid|TokenGroups, TokenInformation, 0, &TokenInformationLength);
              if ( GetLastError() == 122 )
              {
                v71 = TokenInformationLength;
                v72 = malloc(TokenInformationLength);
                BytesReturned = v72;
                if ( GetTokenInformation(OutBuffer, TokenLogonSid|TokenGroups, v72, v71, &TokenInformationLength) )
                {
                  v50 = *v72 == 0;
                  TokenInformation = 0;
                  if ( !v50 )
                  {
                    v73 = v72 + 1;
                    v115 = (v72 + 1);
                    do
                    {
                      v74 = *v73;
                      v75 = malloc(0x34u);
                      memset(v75, 0, 0x34u);
                      v76 = GetLengthSid(v74);
                      v77 = malloc(v76);
                      v75->field_24 = v77;
                      v78 = v77;
                      v79 = GetLengthSid(v74);
                      CopySid(v79, v78, v74);
                      QueryAuthorityInfoFromSID(v74, String, &cbSid);
                      v80 = v119;
                      lParama.pszText = String;
                      lParama.mask = 5;
                      lParama.iItem = 0x7FFFFFFF;
                      lParama.iSubItem = 0;
                      lParama.state = 0;
                      lParama.stateMask = 0;
                      lParama.iImage = 0;
                      lParama.lParam = v75;
                      v81 = SendMessageW(v119, LVM_INSERTITEMW, 0, &lParama);
                      if ( v81 == -1 )
                        return 0;
                      lParama.iItem = v81;
                      lParama.mask = 1;
                      lParama.iSubItem = 1;
                      lParama.pszText = L"Capability";
                      SendMessageW(v80, LVM_SETITEMW, 0, &lParama);
                      v75->field_28 = _wcsdup(String);
                      v82 = _wcsdup(lParama.pszText);
                      v83 = v115;
                      v75->field_30 = v82;
                      v73 = (v83 + 8);
                      v72 = BytesReturned;
                      TokenInformation = TokenInformation + 1;
                      v115 = v73;
                    }
                    while ( TokenInformation < *BytesReturned );
                  }
                }
                free(v72);
              }
              v84 = malloc(0x2Cu);
              v85 = v84;
              *(v84 + 1) = pTokenPrivileges;
              *(v84 + 9) = v119;
              *v84 = 2;
              v84[40] = 0;
              InitializeCriticalSection((v84 + 12));
              *(v85 + 8) = _beginthreadex(0, 0, sub_FE7440, v85, 0, 0);
              SetWindowLongW(hDlg, GWLP_USERDATA, v85);
              GetTokenInformation(OutBuffer, TokenPrivileges, 0, 0, &TokenInformationLength);
              v86 = TokenInformationLength;
              pTokenPrivileges = malloc(TokenInformationLength);
              v50 = GetTokenInformation(OutBuffer, TokenPrivileges, pTokenPrivileges, v86, &TokenInformationLength) == 0;
              v87 = pTokenPrivileges;
              if ( !v50 )
              {
                v50 = pTokenPrivileges->PrivilegeCount == 0;
                TokenInformation = 0;
                if ( !v50 )
                {
                  v88 = &pTokenPrivileges->Privileges[0].Attributes;
                  do
                  {
                    cchName = 260;
                    if ( LookupPrivilegeNameW(0, v88 - 1, Name, &cchName) )
                    {
                      lParama.mask = 5;
                      lParama.pszText = Name;
                      lParama.iItem = 0x7FFFFFFF;
                      lParama.iSubItem = 0;
                      lParama.state = 0;
                      lParama.stateMask = 0;
                      lParama.iImage = 0;
                      lParama.lParam = 1;
                      BytesReturned = SendMessageW(v113, 0x104Du, 0, &lParama);
                      if ( BytesReturned == -1 )
                        return 0;
                      Dst[0] = 0;
                      if ( v88->LowPart & 2 )
                        wcscpy_s(Dst, 0x104u, L"Enabled");
                      else
                        wcscpy_s(Dst, 0x104u, L"Disabled");
                      if ( v88->LowPart & 1 )
                      {
                        if ( Dst[0] )
                          wcscat_s(Dst, 0x104u, L", ");
                        wcscpy_s(Dst, 0x104u, L"Default Enabled");
                      }
                      lParama.iItem = BytesReturned;
                      lParama.pszText = Dst;
                      lParama.mask = 1;
                      lParama.iSubItem = 1;
                      SendMessageW(v113, 0x104Cu, 0, &lParama);
                    }
                    v88 = (v88 + 12);
                    TokenInformation = TokenInformation + 1;
                  }
                  while ( TokenInformation < pTokenPrivileges->PrivilegeCount );
                  v87 = pTokenPrivileges;
                }
              }
              free(v87);
              CloseHandle(OutBuffer);
              CloseHandle(InBuffer);
              v89 = v119;
            }
            else
            {
              v85 = v117;
              CloseHandle(InBuffer);
              v89 = v119;
            }
          }
          else
          {
            v89 = v119;
            if ( pTokenPrivileges[2].Privileges[0].Luid.HighPart & 0x400 )
            {
              lParama.mask = 5;
              lParama.iItem = 0x7FFFFFFF;
              lParama.iSubItem = 0;
              lParama.state = 0;
              lParama.stateMask = 0;
              lParama.pszText = L"Error: Process is Protected";
              lParama.iImage = 0;
              lParama.lParam = 1;
              if ( ::SendMessageW(v119, 0x104Du, 0, &lParama) == -1 )
                return 0;
            }
            v85 = v117;
          }
          if ( !v85 )
          {
            v90 = GetDlgItem(hDlg, 1210);
            EnableWindow(v90, 0);
          }
          InvalidateRect(v89, 0, 0);
          v106 = nItem;
          wParama = 1040;
          SendMessageW(v89, 0x1030u, &wParama, PropProcThreadsSortCallback);
          v91 = v113;
          SendMessageW(v113, 0x101Eu, 0, 0xFFFF);
          SendMessageW(v91, 0x101Eu, 1u, 65534);
          SendMessageW(v89, 0x101Eu, 0, 0xFFFF);
          SendMessageW(v89, 0x101Eu, 1u, 65534);
          return 1;
        case WM_COMMAND:
          if ( wParam > 40001 )
          {
            if ( wParam - 40092 > 1 )
              return 0;
            v98 = wParam;
          }
          else
          {
            if ( wParam != 40001 )
            {
              if ( wParam == 1210 )
              {
                InBuffer = OpenProcess(0xE0000u, 0, *(*(v4 + 4) + 68));
                if ( InBuffer || (InBuffer = OpenProcess(0x20000u, 0, *(*(v4 + 4) + 68))) != 0 )
                {
                  memset(pListParam, 0, 0x10C0u);
                  wsprintfW(&pListParam[46], L"%s: %d", *(*(v4 + 4) + 60), *(*(v4 + 4) + 68));
                  pListParam[10].dwValue = 0;
                  wcscpy_s(&pListParam[14], 0x40u, L"Process");
                  pListParam[11].dwValue = InBuffer;
                  pListParam[9].dwValue = GetCurrentProcessId();
                  FillHandleListParam(hWnd, pListParam);
                  CloseHandle(InBuffer);
                }
                else
                {
                  ReportMsg(L"Error opening process", hWnd);
                }
              }
              return 0;
            }
            v98 = 40014;
          }
          v93 = GetParent(hWnd);
          PostMessageW(v93, WM_COMMAND, v98, 0);
          return 0;
        default:
          return 0;
      }
    }
    return PE_FillControl(hWnd, wParam);
  }
  if ( msg > 0x7F1 )
  {
    if ( msg == 2038 )
    {
      InvalidateRect(pTokenPrivileges, 0, 0);
    }
    else if ( msg == 2039 )
    {
      Item.pszText = pTokenPrivileges;
      Item.iSubItem = 0;
      ::SendMessageW(*(v4 + 36), LVM_SETITEMTEXTW, wParam, &Item);
    }
    return 0;
  }
  if ( msg == 2033 )
  {
    if ( v4 )
    {
      EnterCriticalSection((v4 + 12));
      *(v4 + 40) = 1;
      LeaveCriticalSection((v4 + 12));
      if ( !InterlockedDecrement(v4) )
      {
        DeleteCriticalSection((v4 + 12));
        free(v4);
      }
    }
    return 0;
  }
  if ( msg == 310 || msg == 312 )
    return PE_FillControl(hWnd, wParam);
  return 0;
}
// 1042088: using guessed type wchar_t aErrorOpeningPr[22];
// 10460B4: using guessed type wchar_t aYes[4];
// 10460C4: using guessed type wchar_t aLogonSidS[15];
// 104612C: using guessed type wchar_t aIntegrity[10];
// 104617C: using guessed type wchar_t aCapability[11];
// 10461B4: using guessed type wchar_t aErrorProcessIs[28];
// 1046C70: using guessed type RECT stru_1046C70;
// 105D224: using guessed type char byte_105D224;
// 1064E54: using guessed type int gdwVersion;

//----- (00FE8E00) --------------------------------------------------------
int __stdcall PageProcServices(HWND hDlg, int a2, WPARAM wParam, int a4)
{
  HWND v4; // edi
  CResizer *v5; // eax
  HWND v6; // eax
  struct tagResizerItem *v7; // eax
  HWND v8; // eax
  HICON v9; // ST20_4
  HWND v10; // eax
  LONG v11; // eax
  HWND v12; // eax
  void *v13; // ecx
  wchar_t *v14; // eax
  wchar_t *v15; // esi
  int v16; // edx
  wchar_t v17; // cx
  HWND v18; // eax
  DWORD v19; // ebx
  LONG v20; // edx
  int v21; // esi
  int v22; // eax
  WCHAR *v23; // eax
  int result; // eax
  LONG v25; // edi
  int v26; // eax
  int v27; // eax
  HWND v28; // eax
  HWND v29; // eax
  HWND v30; // eax
  HWND v31; // eax
  HWND v32; // eax
  HWND v33; // eax
  HWND v34; // ST14_4
  SC_HANDLE v35; // esi
  size_t v36; // esi
  BYTE *v37; // edi
  DWORD v38; // ST1C_4
  HWND v39; // eax
  BOOL v40; // ST20_4
  HWND v41; // eax
  BOOL v42; // eax
  BOOL v43; // ST20_4
  HWND v44; // eax
  BOOL v45; // ST20_4
  HWND v46; // eax
  BOOL v47; // eax
  BOOL v48; // ST20_4
  HWND v49; // eax
  BOOL v50; // eax
  BOOL v51; // ST20_4
  HWND v52; // eax
  HWND v53; // eax
  HWND v54; // eax
  HWND v55; // eax
  HWND v56; // eax
  HWND v57; // eax
  HWND v58; // eax
  SC_HANDLE v59; // esi
  INT_PTR v60; // eax
  HWND v61; // eax
  WPARAM v62; // [esp-8h] [ebp-13ACh]
  LPARAM lParam; // [esp+10h] [ebp-1394h]
  int v64; // [esp+1Ch] [ebp-1388h]
  int v65; // [esp+20h] [ebp-1384h]
  LPARAM v66; // [esp+44h] [ebp-1360h]
  int v67; // [esp+4Ch] [ebp-1358h]
  int v68; // [esp+50h] [ebp-1354h]
  size_t pcbBytesNeeded; // [esp+54h] [ebp-1350h]
  LVITEMW Item; // [esp+58h] [ebp-134Ch]
  void *v71; // [esp+8Ch] [ebp-1318h]
  SC_HANDLE hSCObject; // [esp+90h] [ebp-1314h]
  LONG dwNewLong; // [esp+94h] [ebp-1310h]
  char v74; // [esp+9Bh] [ebp-1309h]
  LPARAM pListParam; // [esp+9Ch] [ebp-1308h]
  DWORD v76; // [esp+C0h] [ebp-12E4h]
  int v77; // [esp+C4h] [ebp-12E0h]
  SC_HANDLE v78; // [esp+C8h] [ebp-12DCh]
  wchar_t v79; // [esp+D4h] [ebp-12D0h]
  wchar_t Dst; // [esp+154h] [ebp-1250h]
  struct _SERVICE_STATUS ServiceStatus; // [esp+115Ch] [ebp-248h]
  UINT pnIDs; // [esp+1178h] [ebp-22Ch]
  int v83; // [esp+117Ch] [ebp-228h]
  int v84; // [esp+1180h] [ebp-224h]
  WCHAR ServiceName; // [esp+1184h] [ebp-220h]
  WORD pnWidths[2]; // [esp+138Ch] [ebp-18h]
  __int16 v87; // [esp+1390h] [ebp-14h]
  int v88; // [esp+13A0h] [ebp-4h]

  dwNewLong = a4;
  v4 = GetDlgItem(hDlg, 1036);
  GetWindowLongW(hDlg, -21);
  Item.mask = 0;
  memset(&Item.iItem, 0, 0x30u);
  v74 = 0;
  pnIDs = 1039;
  v83 = 1044;
  v84 = 1061;
  pnWidths[0] = MulDiv(100, gLogPixelSize.x, 96);
  pnWidths[1] = MulDiv(100, gLogPixelSize.x, 96);
  v87 = MulDiv(100, gLogPixelSize.x, 96);
  if ( a2 > 0x111 )
  {
    if ( a2 == 307 || a2 == 310 || a2 == 312 )
      return PE_FillControl(hDlg, wParam);
    return 0;
  }
  if ( a2 == 273 )
  {
    v71 = wParam;
    if ( wParam <= 40001 )
    {
      if ( wParam != 40001 )
      {
        switch ( wParam )
        {
          case 0x4BAu:
          case 0x4BBu:
          case 0x4BCu:
          case 0x4BDu:
          case 0x4BFu:
            Item.iItem = SendMessageW(v4, 0x100Cu, 0xFFFFFFFF, 2);
            Item.pszText = &ServiceName;
            Item.iSubItem = 0;
            Item.cchTextMax = 260;
            Item.mask = 1;
            SendMessageW(v4, 0x104Bu, 0, &Item);
            Item.iSubItem = v71;
            v60 = DialogBoxParamW(ghInstance, L"SERVICECONTROL", hDlg, DlgServiceControl, &Item);
            if ( v60 == 1 )
            {
              MessageBoxW(
                hDlg,
                L"The service didn't respond to the control request in a timely manner",
                L"Process Explorer",
                0x10u);
            }
            else if ( v60 == 2 && wParam == 1210 )
            {
              SendMessageW(v4, 0x1008u, Item.iItem, 0);
            }
            v66 = v4;
            v67 = -101;
            SendMessageW(hDlg, 0x4Eu, 0, &v66);
            QueryServiceNames();
            SetFocus(v4);
            result = 0;
            break;
          case 0x51Au:
            Item.iItem = SendMessageW(v4, 0x100Cu, 0xFFFFFFFF, 2);
            Item.pszText = &ServiceName;
            Item.iSubItem = 0;
            Item.cchTextMax = 260;
            Item.mask = 1;
            SendMessageW(v4, 0x104Bu, 0, &Item);
            v59 = OpenServiceW(ghSCManagerHandle, &ServiceName, 0x60000u);
            if ( v59 )
            {
              memset(&pListParam, 0, 0x10C0u);
              wcscpy_s(&Dst, 0x400u, &ServiceName);
              v77 = 0;
              wcscpy_s(&v79, 0x40u, L"Service");
              v78 = v59;
              v76 = GetCurrentProcessId();
              FillHandleListParam(hDlg, &pListParam);
              CloseServiceHandle(v59);
            }
            else
            {
              ReportMsg(L"Error opening service", hDlg);
            }
            result = 0;
            break;
          default:
            return 0;
        }
        return result;
      }
      v62 = 40014;
LABEL_78:
      v61 = GetParent(hDlg);
      PostMessageW(v61, 0x111u, v62, 0);
      return 0;
    }
    if ( wParam == 40002 )
    {
      SetEvent(ghRefreshEventHandle);
      return 0;
    }
    if ( wParam - 40092 <= 1 )
    {
      v62 = wParam;
      goto LABEL_78;
    }
    return 0;
  }
  switch ( a2 )
  {
    case 43:
      CMainWnd::DrawList(dwNewLong);
      return 0;
    case 44:
      return CMainWnd::HandleMeasureItem(hDlg, a2, wParam, dwNewLong);
    case 78:
      v25 = dwNewLong;
      v26 = *(dwNewLong + 8);
      if ( v26 != -101 && (v26 + 3) > 1 )
        return 0;
      SetDlgItemTextW(hDlg, 1059, &gszNullString);
      v27 = SendMessageW(*v25, 0x100Cu, 0xFFFFFFFF, 2);
      if ( v27 == -1 )
      {
        v28 = GetDlgItem(hDlg, 1306);
        EnableWindow(v28, 0);
        v29 = GetDlgItem(hDlg, 1213);
        EnableWindow(v29, 0);
        v30 = GetDlgItem(hDlg, 1210);
        EnableWindow(v30, 0);
        v31 = GetDlgItem(hDlg, 1211);
        EnableWindow(v31, 0);
        v32 = GetDlgItem(hDlg, 1212);
        EnableWindow(v32, 0);
        v33 = GetDlgItem(hDlg, 1215);
        EnableWindow(v33, 0);
        return 0;
      }
      Item.iItem = v27;
      Item.pszText = &ServiceName;
      v34 = *v25;
      Item.iSubItem = 0;
      Item.cchTextMax = 260;
      Item.mask = 1;
      if ( SendMessageW(v34, 0x104Bu, 0, &Item) != 1 )
        return 0;
      v35 = OpenServiceW(ghSCManagerHandle, &ServiceName, 5u);
      hSCObject = v35;
      if ( !v35 )
      {
        v53 = GetDlgItem(hDlg, 1306);
        EnableWindow(v53, 0);
        v54 = GetDlgItem(hDlg, 1213);
        EnableWindow(v54, 0);
        v55 = GetDlgItem(hDlg, 1215);
        EnableWindow(v55, 0);
        v56 = GetDlgItem(hDlg, 1210);
        EnableWindow(v56, 0);
        v57 = GetDlgItem(hDlg, 1211);
        EnableWindow(v57, 0);
        v58 = GetDlgItem(hDlg, 1212);
        EnableWindow(v58, 0);
        return 0;
      }
      if ( *QueryServiceConfig2W )
      {
        QueryServiceConfig2W(v35, 1u, 0, 0, &pcbBytesNeeded);
        if ( GetLastError() == 122 )
        {
          v36 = pcbBytesNeeded;
          v37 = malloc(pcbBytesNeeded);
          v38 = v36;
          v35 = hSCObject;
          QueryServiceConfig2W(hSCObject, 1u, v37, v38, &pcbBytesNeeded);
          SetDlgItemTextW(hDlg, 1059, *v37);
          free(v37);
          v25 = dwNewLong;
        }
      }
      QueryServiceStatus(v35, &ServiceStatus);
      v39 = GetDlgItem(hDlg, 1306);
      EnableWindow(v39, 1);
      v40 = ServiceStatus.dwCurrentState == 1;
      v41 = GetDlgItem(hDlg, 1213);
      EnableWindow(v41, v40);
      v42 = ServiceStatus.dwCurrentState == 4 && ServiceStatus.dwControlsAccepted & 2;
      v43 = v42;
      v44 = GetDlgItem(hDlg, 1212);
      EnableWindow(v44, v43);
      v45 = ServiceStatus.dwCurrentState == 7;
      v46 = GetDlgItem(hDlg, 1211);
      EnableWindow(v46, v45);
      v47 = (ServiceStatus.dwCurrentState == 4 || ServiceStatus.dwCurrentState == 7)
         && ServiceStatus.dwControlsAccepted & 1;
      v48 = v47;
      v49 = GetDlgItem(hDlg, 1210);
      EnableWindow(v49, v48);
      v50 = (ServiceStatus.dwCurrentState == 4 || ServiceStatus.dwCurrentState == 7)
         && ServiceStatus.dwControlsAccepted & 1;
      v51 = v50;
      v52 = GetDlgItem(hDlg, 1215);
      EnableWindow(v52, v51);
      CloseServiceHandle(hSCObject);
      if ( *(v25 + 8) == -3 )
      {
        SendMessageW(hDlg, 0x111u, 0x51Au, 0);
        return 0;
      }
      return 0;
    case 272:
      v5 = operator new(0x40u);
      v71 = v5;
      v88 = 0;
      if ( v5 )
        hSCObject = CResizer::CResizer(v5, hDlg);
      else
        hSCObject = 0;
      v88 = -1;
      v6 = GetDlgItem(hDlg, 1036);
      if ( v6 )
      {
        v7 = CResizer::AddItem(hSCObject, v6, 1);
        *&v7->m_rect2.left = 0i64;
        *&v7->m_rect2.right = db_one;
      }
      v8 = GetDlgItem(hDlg, 1210);
      if ( v8 )
        CResizer::AddItem(hSCObject, v8, 1)->m_rect1 = stru_1046C70;
      PropSheet_UpdateTab(hDlg);
      v9 = LoadIconW(ghInstance, 0xEB);
      v10 = GetDlgItem(hDlg, 1129);
      SendMessageW(v10, 0x172u, 1u, v9);
      SetWindowLongW(hDlg, -21, dwNewLong);
      v11 = GetWindowLongW(v4, -16);
      SetWindowLongW(v4, -16, v11 & 0xFFFFFFFD | 1);
      SendMessageW(v4, 0x1036u, 0x4020u, 16416);
      v12 = SendMessageW(v4, 0x104Eu, 0, 0);
      CTreeList::InitToolTips(v12);
      gOldListWndProc = SetWindowLongW(v4, -4, Proxy_ListCtrlWndProc);
      SendMessageW(v4, 0x30u, ghConfigFont, 0);
      v13 = *(dwNewLong + 792);
      hSCObject = v13;
      if ( !v13 )
      {
        v13 = *(dwNewLong + 60);
        hSCObject = *(dwNewLong + 60);
      }
      v14 = _wcsdup(v13);
      v15 = v14;
      v16 = (v14 + 1);
      do
      {
        v17 = *v14;
        ++v14;
      }
      while ( v17 );
      _wcsupr_s(v15, ((v14 - v16) >> 1) + 1);
      if ( wcsstr(v15, L"SVCHOST.EXE") )
      {
        CTreeView::InitListHeader(v4, &pnIDs, pnWidths, 3u);
        v74 = 1;
      }
      else
      {
        CTreeView::InitListHeader(v4, &pnIDs, pnWidths, 2u);
      }
      free(v15);
      if ( !*CreateSecurityPage )
      {
        v18 = GetDlgItem(hDlg, 1306);
        ShowWindow(v18, 0);
      }
      QueryServiceNames();
      EnterCriticalSection(&gServiceLock);
      v19 = 0;
      if ( !gdwServiceReturned )
        goto LABEL_29;
      v20 = dwNewLong;
      v21 = 0;
      break;
    default:
      return 0;
  }
  do
  {
    if ( gpszServiceNames[v21 + 9] == *(v20 + 68) )
    {
      Item.mask = 5;
      Item.iItem = 0x7FFFFFFF;
      Item.iSubItem = 0;
      Item.stateMask = 0;
      Item.state = 0;
      Item.pszText = gpszServiceNames[v21];
      Item.lParam = (v19 + 1);
      Item.iImage = 0;
      v22 = SendMessageW(v4, LVM_INSERTITEMW, 0, &Item);
      v68 = v22;
      if ( v22 == -1 )
        return 0;
      Item.iItem = v22;
      Item.mask = 1;
      Item.iSubItem = 1;
      Item.pszText = gpszServiceNames[v21 + 1];
      SendMessageW(v4, 0x104Cu, 0, &Item);
      if ( v74 )
      {
        v23 = sub_FC4780(hSCObject, gpszServiceNames[v21]);
        v71 = v23;
        if ( v23 )
        {
          Item.pszText = v23;
          Item.mask = 1;
          Item.iItem = v68;
          Item.iSubItem = 2;
          SendMessageW(v4, 0x104Cu, 0, &Item);
          free(v71);
        }
      }
      v20 = dwNewLong;
    }
    ++v19;
    v21 += 11;
  }
  while ( v19 < gdwServiceReturned );
LABEL_29:
  LeaveCriticalSection(&gServiceLock);
  SendMessageW(v4, 0x101Eu, 0, 0xFFFF);
  SendMessageW(v4, 0x101Eu, 1u, (v74 != 0) + 65534);
  if ( v74 )
    SendMessageW(v4, 0x101Eu, 2u, 65534);
  v65 = 3;
  v64 = 3;
  SendMessageW(v4, 0x102Bu, 0, &lParam);
  SetFocus(v4);
  return 1;
}
// 1045620: using guessed type wchar_t aErrorOpeningSe[22];
// 1046C70: using guessed type RECT stru_1046C70;

//----- (00FE9A30) --------------------------------------------------------
int __userpurge PageProcTcpUdp@<eax>(signed int a1@<ebx>, HWND hWnd, int a3, WPARAM wParam, int a5)
{
  HWND v5; // esi
  int v6; // eax
  HWND v7; // eax
  HWND v8; // edi
  CResizer *v9; // eax
  HWND v10; // eax
  void *v11; // eax
  __m128i *v12; // eax
  LONG v13; // ecx
  WPARAM v14; // esi
  UINT v15; // eax
  BOOL v16; // ST44_4
  HWND v17; // eax
  UINT v19; // eax
  HWND v20; // eax
  u_long *v21; // esi
  LRESULT v22; // eax
  char v23; // al
  char v24; // cl
  HANDLE v25; // eax
  HANDLE v26; // eax
  int v27; // eax
  PVOID v28; // ecx
  HANDLE v29; // eax
  HANDLE v30; // eax
  int v31; // eax
  int v32; // ecx
  bool v33; // zf
  SYSTEM_HANDLE_INFORMATION *v34; // ecx
  int v35; // eax
  char *v36; // eax
  _DWORD *v37; // edi
  u_long v38; // ecx
  int v39; // eax
  SYSTEM_HANDLE_INFORMATION *v40; // ecx
  char *v41; // eax
  _DWORD *v42; // edx
  size_t v43; // edi
  void *v44; // esi
  int v45; // ST30_4
  char *v46; // eax
  void *v47; // ST44_4
  HANDLE v48; // eax
  void *v49; // ST44_4
  HANDLE v50; // eax
  PVOID v51; // ST44_4
  HANDLE v52; // eax
  PVOID v53; // ST44_4
  HANDLE v54; // eax
  void *v55; // esi
  void *v56; // eax
  SYSTEM_HANDLE_INFORMATION *v57; // ecx
  int *v58; // edi
  u_long v59; // edx
  int v60; // ecx
  char *v61; // eax
  int *v62; // edi
  int *v63; // eax
  SYSTEM_HANDLE_INFORMATION *v64; // edx
  int *v65; // ecx
  char *v66; // eax
  int *v67; // edi
  SYSTEM_HANDLE_INFORMATION *v68; // ecx
  int *v69; // edi
  int v70; // ecx
  char *v71; // eax
  size_t *v72; // edi
  SYSTEM_HANDLE_INFORMATION *v73; // ecx
  char *v74; // eax
  _SYSTEM_INFORMATION_CLASS SystemInfoClass_1; // ecx
  SYSTEM_HANDLE_INFORMATION *pSystemHandleInfo_1; // edi
  ULONG v77; // esi
  _SYSTEM_INFORMATION_CLASS SystemInfoClass; // eax
  struct _MIB_TCPTABLE *v79; // eax
  struct _MIB_TCPTABLE *v80; // esi
  int v81; // eax
  struct _MIB_UDPTABLE *v82; // eax
  struct _MIB_UDPTABLE *v83; // edi
  int v84; // eax
  int v85; // eax
  int v86; // ecx
  char *v87; // ecx
  void *v88; // ST40_4
  LPARAM v89; // ecx
  int v90; // eax
  WPARAM v91; // esi
  int v92; // ST44_4
  int v93; // eax
  WPARAM v94; // [esp-8h] [ebp-B4h]
  LPARAM lParam; // [esp+Ch] [ebp-A0h]
  tagLVITEMW ItemInfo; // [esp+10h] [ebp-9Ch]
  WPARAM v97; // [esp+40h] [ebp-6Ch]
  WPARAM v98; // [esp+44h] [ebp-68h]
  void *v99; // [esp+48h] [ebp-64h]
  PVOID ppTcpTable; // [esp+4Ch] [ebp-60h]
  LPVOID lpMem; // [esp+50h] [ebp-5Ch]
  char v102[5]; // [esp+57h] [ebp-55h]
  PVOID pTcpTable; // [esp+5Ch] [ebp-50h]
  int v104; // [esp+60h] [ebp-4Ch]
  u_long *v105; // [esp+64h] [ebp-48h]
  void *v106; // [esp+68h] [ebp-44h]
  HWND v107; // [esp+6Ch] [ebp-40h]
  LONG dwNewLong; // [esp+70h] [ebp-3Ch]
  LPARAM dwInitParam; // [esp+74h] [ebp-38h]
  size_t ReturnLength; // [esp+78h] [ebp-34h]
  size_t v111; // [esp+7Ch] [ebp-30h]
  SYSTEM_HANDLE_INFORMATION *pSystemHandleInfo; // [esp+80h] [ebp-2Ch]
  UINT pnIDs; // [esp+87h] [ebp-25h]
  int v114; // [esp+98h] [ebp-14h]
  int v115; // [esp+A8h] [ebp-4h]

  v5 = hWnd;
  pSystemHandleInfo = hWnd;
  dwNewLong = a5;
  dwInitParam = GetWindowLongW(hWnd, -21);
  lParam = 0;
  memset(&ItemInfo, 0, 0x30u);
  v6 = dword_107D0B0;
  pTcpTable = 0;
  *&v102[1] = 0;
  ppTcpTable = 0;
  lpMem = 0;
  v114 = 1343;
  _mm_storeu_si128((&pnIDs + 1), _mm_load_si128(&xmmword_1046C50));
  if ( !(v6 & 1) )
  {
    dword_107D0B0 = v6 | 1;
    pnWidths = MulDiv(50, gLogPixelSize.x, 96);
    word_107D0A6 = MulDiv(100, gLogPixelSize.x, 96);
    word_107D0A8 = MulDiv(100, gLogPixelSize.x, 96);
    word_107D0AA = MulDiv(100, gLogPixelSize.x, 96);
    word_107D0AC = MulDiv(100, gLogPixelSize.x, 96);
  }
  v7 = GetDlgItem(hWnd, 1192);
  v8 = v7;
  v107 = v7;
  if ( a3 <= WM_TIMER )
  {
    if ( a3 != WM_TIMER )
    {
      switch ( a3 )
      {
        case WM_ALTTABACTIVE|WM_DESTROY:
          CMainWnd::DrawList(dwNewLong);
          return 0;
        case 0x2C:
          return CMainWnd::HandleMeasureItem(hWnd, a3, wParam, dwNewLong);
        case WM_NOTIFY:
          switch ( *(dwNewLong + 8) )
          {
            case LVN_GETDISPINFOW:
              return sub_FBD7B0(wParam, dwNewLong);
            case LVN_COLUMNCLICK:
              return sub_FBD040(wParam, dwNewLong);
            case LVN_ITEMCHANGED:
            case LVN_GETDISPINFO|0x94:
              v16 = SendMessageW(*(dwInitParam + 4), LVM_GETNEXTITEM, 0xFFFFFFFF, 2) != -1;
              v17 = GetDlgItem(hWnd, IDC_PAGE_PROCTHREADS_BUTTON_STACK);
              EnableWindow(v17, v16);
              return 0;
            case LVN_SETDISPINFO|0x94:
              SendMessageW(hWnd, WM_COMMAND, 0x43Du, 0);
              break;
            default:
              return 0;
          }
          return 0;
        case WM_INITDIALOG:
          v9 = operator new(0x40u);
          v99 = v9;
          v115 = 0;
          if ( v9 )
            v111 = CResizer::CResizer(v9, hWnd);
          else
            v111 = 0;
          v115 = -1;
          v10 = GetDlgItem(hWnd, 1209);
          if ( v10 )
            CResizer::AddItem(v111, v10, 1)->m_rect1 = stru_1046C70;
          PropSheet_UpdateTab(hWnd);
          SetWindowLongW(hWnd, GWLP_USERDATA, dwNewLong);
          if ( gdwVersion < 1 || (v11 = 5, !(*(dwNewLong + 40) & 0x20)) )
            v11 = 4;
          v106 = v11;
          sub_FB9BB0(v8, v11, (&pnIDs + 1), &pnWidths, 1);
          SetWindowLongW(v8, -4, Proxy_ListCtrlWndProc);
          SendMessageW(v8, 0x30u, ghConfigFont, 0);
          v12 = malloc(0x1Cu);
          v13 = dwNewLong;
          _mm_storeu_si128(v12, 0i64);
          _mm_storel_epi64(v12 + 1, 0i64);
          v12[1].m128i_i32[2] = 0;
          v12->m128i_i32[3] = 0;
          v12->m128i_i32[0] = v13;
          v12->m128i_i32[1] = v8;
          v12[1].m128i_i32[2] = -1;
          SetWindowLongW(hWnd, -21, v12);
          SendMessageW(hWnd, 0x113u, 0, 1);
          if ( SendMessageW(v8, 0x1004u, 0, 0) )
          {
            v14 = 0;
            if ( v106 )
            {
              do
              {
                if ( v14 == 3 )
                  SendMessageW(v8, 0x101Eu, 3u, word_107D0AA);
                else
                  SendMessageW(v8, 0x101Eu, v14, 0xFFFF);
                ++v14;
              }
              while ( v14 < v106 );
            }
            v5 = pSystemHandleInfo;
          }
          CheckDlgButton(v5, 1194, byte_10610D8 != 0);
          v15 = IsDlgButtonChecked(v5, 1194);
          SetPropW(v8, L"resolve", (v15 == 1));
          SetFocus(v8);
          ReleaseCapture();
          return 0;
        case WM_COMMAND:
          if ( wParam <= 40001 )
          {
            if ( wParam != 40001 )
            {
              if ( wParam == 1085 )
              {
                if ( AllocateAndGetTcpExTableFromStack )
                  DialogBoxParamW(ghMainInstance, L"THREADSTACK", hWnd, DlgThreadStack, dwInitParam);
                else
                  MessageBoxW(hWnd, L"Stacks not available on this version of Windows", L"Process Explorer", 0x30u);
              }
              else if ( wParam == 1194 && !(wParam >> 16) )
              {
                v19 = IsDlgButtonChecked(hWnd, 1194);
                SetPropW(v8, L"resolve", (v19 == 1));
                byte_10610D8 = IsDlgButtonChecked(pSystemHandleInfo, 1194) == 1;
                goto LABEL_33;
              }
              return 0;
            }
            v94 = 40014;
LABEL_43:
            v20 = GetParent(hWnd);
            PostMessageW(v20, 0x111u, v94, 0);
            return 0;
          }
          if ( wParam != 40002 )
          {
            if ( wParam - 40092 > 1 )
              return 0;
            v94 = wParam;
            goto LABEL_43;
          }
          SetEvent(ghRefreshEventHandle);
          break;
        default:
          return 0;
      }
      return 0;
    }
    v21 = 0;
    LOBYTE(pnIDs) = 0;
    v105 = 0;
    if ( !dwNewLong )
    {
      lParam = 4;
      v22 = SendMessageW(v7, 0x1004u, 0, 0);
      ItemInfo.iItem = 0;
      ItemInfo.mask = v22 - 1;
      if ( SendMessageW(v8, 0x104Bu, 0, &lParam) )
      {
        do
        {
          *(ItemInfo.iImage + 36) = 0;
          v23 = sub_FF58D0(a1, v8, &lParam, ItemInfo.iImage, v102);
          v24 = pnIDs;
          if ( v23 )
            v24 = 1;
          LOBYTE(pnIDs) = v24;
          if ( v102[0] )
          {
            v21 = (v21 + 1);
            *(ItemInfo.iImage + 8) = 0;
          }
          lParam = 4;
          ItemInfo.iItem = 0;
        }
        while ( SendMessageW(v8, 0x104Bu, 0, &lParam) );
        v105 = v21;
      }
    }
    if ( !AllocateAndGetTcpExTableFromStack )
    {
      if ( *GetExtendedTcpTable )
      {
        ReturnLength = 0;
        if ( GetExtendedTcpTable(0, &ReturnLength, 0, 2u, TCP_TABLE_OWNER_MODULE_ALL, 0) == 122 )
        {
          v55 = 0;
          do
          {
            if ( v55 )
              free(v55);
            v55 = malloc(ReturnLength);
          }
          while ( GetExtendedTcpTable(v55, &ReturnLength, 0, 2u, TCP_TABLE_OWNER_MODULE_ALL, 0) == 122 );
          v111 = v55;
          v33 = v55 == 0;
          v21 = v105;
          if ( !v33 )
          {
            v56 = v111;
            v57 = 0;
            pSystemHandleInfo = 0;
            if ( *v111 )
            {
              v58 = (v111 + 28);
              do
              {
                if ( *v58 == *(*dwInitParam + 68) )
                {
                  v59 = *(v58 - 2);
                  if ( v59 )
                    v60 = *(v58 - 1);
                  else
                    v60 = 0;
                  v61 = sub_FDA070(
                          v107,
                          dwNewLong,
                          0,
                          *(v58 - 5),
                          *(v58 - 4),
                          0,
                          *(v58 - 3),
                          v59,
                          0,
                          v60,
                          *v58,
                          (v58 + 3),
                          0,
                          &pnIDs);
                  v57 = pSystemHandleInfo;
                  if ( v61 )
                    LOBYTE(pnIDs) = 1;
                  else
                    v21 = (v21 - 1);
                }
                v56 = v111;
                v57 = (v57 + 1);
                v58 += 40;
                pSystemHandleInfo = v57;
              }
              while ( v57 < *v111 );
            }
            free(v56);
          }
        }
        ReturnLength = 0;
        if ( GetExtendedUdpTable(0, &ReturnLength, 0, 2u, UDP_TABLE_OWNER_MODULE, 0) == 122 )
        {
          v62 = 0;
          do
          {
            if ( v62 )
              free(v62);
            v62 = malloc(ReturnLength);
          }
          while ( GetExtendedUdpTable(v62, &ReturnLength, 0, 2u, UDP_TABLE_OWNER_MODULE, 0) == 122 );
          v111 = v62;
          if ( v62 )
          {
            v63 = v62;
            v64 = 0;
            pSystemHandleInfo = 0;
            if ( *v62 )
            {
              v65 = v62 + 4;
              v106 = v62 + 4;
              do
              {
                if ( *v65 == *(*dwInitParam + 68) )
                {
                  v66 = sub_FDA070(
                          v107,
                          dwNewLong,
                          1,
                          2,
                          *(v65 - 2),
                          0,
                          *(v65 - 1),
                          0xFFFFFFFF,
                          0,
                          -1,
                          *v65,
                          (v65 + 6),
                          0,
                          &pnIDs);
                  if ( v66 )
                  {
                    if ( dwNewLong )
                      *(v66 + 4) = 0;
                    LOBYTE(pnIDs) = 1;
                  }
                  else
                  {
                    v21 = (v21 - 1);
                  }
                  v64 = pSystemHandleInfo;
                  v65 = v106;
                }
                v63 = v111;
                v64 = (v64 + 1);
                v65 += 40;
                pSystemHandleInfo = v64;
                v106 = v65;
              }
              while ( v64 < *v111 );
            }
            free(v63);
          }
        }
        v67 = 0;
        ReturnLength = 0;
        if ( GetExtendedTcpTable(0, &ReturnLength, 0, 0x17u, TCP_TABLE_OWNER_MODULE_ALL, 0) == 122 )
        {
          do
          {
            if ( v67 )
              free(v67);
            v67 = malloc(ReturnLength);
          }
          while ( GetExtendedTcpTable(v67, &ReturnLength, 0, 0x17u, TCP_TABLE_OWNER_MODULE_ALL, 0) == 122 );
          v111 = v67;
          if ( v67 )
          {
            v68 = 0;
            pSystemHandleInfo = 0;
            if ( *v67 )
            {
              v69 = v67 + 15;
              do
              {
                if ( *v69 == *(*dwInitParam + 68) )
                {
                  if ( v69 == 28 )
                    v70 = 0;
                  else
                    v70 = *(v69 - 2);
                  v71 = sub_FDA070(
                          v107,
                          dwNewLong,
                          2,
                          *(v69 - 1),
                          0,
                          (v69 - 13),
                          *(v69 - 8),
                          0,
                          (v69 - 7),
                          v70,
                          *v69,
                          (v69 + 3),
                          0,
                          &pnIDs);
                  v68 = pSystemHandleInfo;
                  if ( v71 )
                    LOBYTE(pnIDs) = 1;
                  else
                    v21 = (v21 - 1);
                }
                v68 = (v68 + 1);
                v69 += 48;
                pSystemHandleInfo = v68;
              }
              while ( v68 < *v111 );
              v67 = v111;
            }
            free(v67);
          }
        }
        v72 = 0;
        ReturnLength = 0;
        if ( GetExtendedUdpTable(0, &ReturnLength, 0, 0x17u, UDP_TABLE_OWNER_MODULE, 0) == 122 )
        {
          do
          {
            if ( v72 )
              free(v72);
            v72 = malloc(ReturnLength);
          }
          while ( GetExtendedUdpTable(v72, &ReturnLength, 0, 0x17u, UDP_TABLE_OWNER_MODULE, 0) == 122 );
          if ( v72 )
          {
            v33 = *v72 == 0;
            v111 = 0;
            if ( !v33 )
            {
              v73 = (v72 + 8);
              pSystemHandleInfo = (v72 + 8);
              do
              {
                if ( v73->NumberOfHandles == *(*dwInitParam + 68) )
                {
                  v74 = sub_FDA070(
                          v107,
                          dwNewLong,
                          3,
                          2,
                          0,
                          &v73[-2].Handles[0].GrantedAccess,
                          v73[-1].Handles[0].GrantedAccess,
                          0xFFFFFFFF,
                          0,
                          -1,
                          v73->NumberOfHandles,
                          v73[1].Handles,
                          0,
                          &pnIDs);
                  if ( v74 )
                  {
                    if ( dwNewLong )
                      *(v74 + 4) = 0;
                    LOBYTE(pnIDs) = 1;
                  }
                  else
                  {
                    v21 = (v21 - 1);
                  }
                  v73 = pSystemHandleInfo;
                }
                v73 = (v73 + 176);
                pSystemHandleInfo = v73;
                ++v111;
              }
              while ( v111 < *v72 );
            }
            free(v72);
          }
        }
        v8 = v107;
      }
      else
      {
        ReturnLength = 64000;
        pSystemHandleInfo = malloc(64000u);
        SystemInfoClass_1 = SystemHandleInformation;
        if ( gbSupportExtendedSystemHandleInformation )
          SystemInfoClass_1 = SystemExtendedHandleInformation;
        if ( NtQuerySystemInformation(SystemInfoClass_1, pSystemHandleInfo, 0xFA00u, &ReturnLength) )
        {
          pSystemHandleInfo_1 = pSystemHandleInfo;
          do
          {
            free(pSystemHandleInfo_1);
            ReturnLength *= 2;
            v77 = ReturnLength;
            pSystemHandleInfo_1 = malloc(ReturnLength);
            SystemInfoClass = SystemHandleInformation;
            if ( gbSupportExtendedSystemHandleInformation )
              SystemInfoClass = SystemExtendedHandleInformation;
          }
          while ( NtQuerySystemInformation(SystemInfoClass, pSystemHandleInfo_1, v77, &ReturnLength) );
          v21 = v105;
          pSystemHandleInfo = pSystemHandleInfo_1;
          v8 = v107;
        }
        v111 = sub_FF39C0(pSystemHandleInfo, *(*dwInitParam + 68));
        ReturnLength = 0;
        dwInitParam = 0;
        if ( GetTcpTable(0, &ReturnLength, 1) == 122 )
        {
          do
          {
            v79 = malloc(ReturnLength);
            v80 = v79;
            dwInitParam = v79;
            v81 = GetTcpTable(v79, &ReturnLength, 1);
            v104 = v81;
            if ( v81 )
            {
              free(v80);
              v81 = v104;
              dwInitParam = 0;
            }
          }
          while ( v81 == 122 );
          v21 = v105;
        }
        ReturnLength = 0;
        v106 = 0;
        if ( GetUdpTable(0, &ReturnLength, 1) == 122 )
        {
          do
          {
            v82 = malloc(ReturnLength);
            v83 = v82;
            v106 = v82;
            v84 = GetUdpTable(v82, &ReturnLength, 1);
            v104 = v84;
            if ( v84 )
            {
              free(v83);
              v84 = v104;
              v106 = 0;
            }
          }
          while ( v84 == 122 );
          v8 = v107;
        }
        if ( dwInitParam )
        {
          v33 = *dwInitParam == 0;
          v104 = 0;
          if ( !v33 )
          {
            v85 = dwInitParam + 16;
            v105 = (dwInitParam + 16);
            do
            {
              if ( sub_FDF600(v111, 0, *(v85 - 8), *(v85 - 4)) )
              {
                if ( *v105 )
                  v86 = v105[1];
                else
                  v86 = 0;
                v8 = v107;
                if ( sub_FDA070(
                       v107,
                       dwNewLong,
                       0,
                       *(v105 - 3),
                       *(v105 - 2),
                       0,
                       *(v105 - 1),
                       *v105,
                       0,
                       v86,
                       0,
                       0,
                       0,
                       &pnIDs) )
                {
                  LOBYTE(pnIDs) = 1;
                }
                else
                {
                  v21 = (v21 - 1);
                }
              }
              v85 = (v105 + 5);
              ++v104;
              v105 += 5;
            }
            while ( v104 < *dwInitParam );
          }
        }
        if ( v106 )
        {
          v33 = *v106 == 0;
          v104 = 0;
          if ( !v33 )
          {
            v87 = v106 + 4;
            v105 = (v106 + 4);
            do
            {
              v88 = *v87;
              v107 = *(v87 + 1);
              v99 = v88;
              if ( sub_FDF600(v111, 1, v88, v107) )
              {
                if ( sub_FDA070(v8, dwNewLong, 1, 2, v99, 0, v107, 0xFFFFFFFF, 0, -1, 0, 0, 0, &pnIDs) )
                  LOBYTE(pnIDs) = 1;
                else
                  v21 = (v21 - 1);
              }
              v87 = (v105 + 2);
              ++v104;
              v105 += 2;
            }
            while ( v104 < *v106 );
          }
        }
        free(pSystemHandleInfo);
        if ( v106 )
          free(v106);
        if ( dwInitParam )
          free(dwInitParam);
        if ( v111 )
          free(v111);
      }
      goto LABEL_191;
    }
    pTcpTable = 0;
    ppTcpTable = 0;
    if ( AllocateAndGetTcpExTable2FromStack )
    {
      v25 = GetProcessHeap();
      if ( AllocateAndGetTcpExTable2FromStack(&ppTcpTable, 1, v25, 0, 2u, TCP_TABLE_OWNER_MODULE_ALL) )
        ppTcpTable = 0;
    }
    else
    {
      v26 = GetProcessHeap();
      v27 = AllocateAndGetTcpExTableFromStack(&pTcpTable, 1, v26, 2u, 2u);
      v28 = pTcpTable;
      if ( v27 )
        v28 = 0;
      pTcpTable = v28;
    }
    *&v102[1] = 0;
    lpMem = 0;
    if ( AllocateAndGetUdpExTable2FromStack )
    {
      v29 = GetProcessHeap();
      if ( AllocateAndGetUdpExTable2FromStack(&lpMem, 1, v29, 2u, 2u, UDP_TABLE_OWNER_MODULE) )
        lpMem = 0;
    }
    else
    {
      v30 = GetProcessHeap();
      v31 = AllocateAndGetUdpExTableFromStack(&v102[1], 1, v30, 2u, 2u);
      v32 = *&v102[1];
      if ( v31 )
        v32 = 0;
      *&v102[1] = v32;
    }
    if ( pTcpTable )
    {
      v33 = *pTcpTable == 0;
      v111 = 0;
      if ( !v33 )
      {
        v34 = 0;
        pSystemHandleInfo = 0;
        do
        {
          v21 = v105;
          if ( *(pTcpTable + v34 + 24) == *(*dwInitParam + 68) )
          {
            if ( *(pTcpTable + v34 + 16) )
              v35 = *(pTcpTable + v34 + 20);
            else
              v35 = 0;
            v8 = v107;
            v36 = sub_FDA070(
                    v107,
                    dwNewLong,
                    0,
                    *(pTcpTable + v34 + 4),
                    *(pTcpTable + v34 + 8),
                    0,
                    *(pTcpTable + v34 + 12),
                    *(pTcpTable + v34 + 16),
                    0,
                    v35,
                    *(pTcpTable + v34 + 24),
                    0,
                    0,
                    &pnIDs);
            v34 = pSystemHandleInfo;
            if ( v36 )
            {
              LOBYTE(pnIDs) = 1;
            }
            else
            {
              v21 = (v21 - 1);
              v105 = v21;
            }
          }
          v34 = (v34 + 24);
          ++v111;
          pSystemHandleInfo = v34;
        }
        while ( v111 < *pTcpTable );
      }
    }
    else if ( ppTcpTable )
    {
      v33 = *ppTcpTable == 0;
      v37 = ppTcpTable + 8;
      pSystemHandleInfo = 0;
      if ( !v33 )
      {
        do
        {
          if ( v37[6] == *(*dwInitParam + 68) )
          {
            v111 = *v37 - 28;
            v104 = malloc(v111);
            memmove_0(v104, v37 + 7, v111);
            v38 = v37[4];
            if ( v38 )
              v39 = v37[5];
            else
              v39 = 0;
            if ( sub_FDA070(v107, dwNewLong, 0, v37[1], v37[2], 0, v37[3], v38, 0, v39, v37[6], v104, v111, &pnIDs) )
              LOBYTE(pnIDs) = 1;
            else
              v21 = (v21 - 1);
          }
          v37 = (v37 + *v37);
          pSystemHandleInfo = (pSystemHandleInfo + 1);
        }
        while ( pSystemHandleInfo < *ppTcpTable );
        v105 = v21;
      }
      v8 = v107;
    }
    if ( *&v102[1] )
    {
      v33 = **&v102[1] == 0;
      v111 = 0;
      if ( !v33 )
      {
        v40 = 0;
        pSystemHandleInfo = 0;
        do
        {
          v8 = v107;
          if ( *(&v40->Handles[0].Object + *&v102[1]) == *(*dwInitParam + 68) )
          {
            v41 = sub_FDA070(
                    v107,
                    dwNewLong,
                    1,
                    2,
                    *(&v40->Handles[0].UniqueProcessId + *&v102[1]),
                    0,
                    *(&v40->Handles[0].ObjectTypeIndex + *&v102[1]),
                    0xFFFFFFFF,
                    0,
                    -1,
                    *(&v40->Handles[0].Object + *&v102[1]),
                    0,
                    0,
                    &pnIDs);
            if ( v41 )
            {
              if ( dwNewLong )
                *(v41 + 4) = 0;
              LOBYTE(pnIDs) = 1;
            }
            else
            {
              v21 = (v21 - 1);
            }
            v40 = pSystemHandleInfo;
          }
          v40 = (v40 + 12);
          ++v111;
          pSystemHandleInfo = v40;
        }
        while ( v111 < **&v102[1] );
      }
    }
    else
    {
      if ( !lpMem )
      {
LABEL_118:
        if ( pTcpTable )
        {
          v51 = pTcpTable;
          v52 = GetProcessHeap();
          HeapFree(v52, 0, v51);
        }
        if ( ppTcpTable )
        {
          v53 = ppTcpTable;
          v54 = GetProcessHeap();
          HeapFree(v54, 0, v53);
        }
LABEL_191:
        if ( pnIDs || v21 )
        {
          InvalidateRect(v8, 0, 0);
          CTreeList::InitHeaderColumn(v8, dword_1069B98, dword_1069B98, byte_105D225);
          v98 = dword_1069B98;
          v97 = 1192;
          SendMessageW(v8, 0x1030u, &v97, PropProcThreadsSortCallback);
          SendMessageW(v8, 0xBu, 1u, 0);
        }
        return 0;
      }
      v33 = *lpMem == 0;
      v42 = lpMem + 8;
      v106 = lpMem + 8;
      v111 = 0;
      if ( v33 )
      {
LABEL_116:
        if ( lpMem )
        {
          v49 = lpMem;
          v50 = GetProcessHeap();
          HeapFree(v50, 0, v49);
        }
        goto LABEL_118;
      }
      do
      {
        if ( v42[3] == *(*dwInitParam + 68) )
        {
          v43 = *v42 - 16;
          v44 = malloc(v43);
          memmove_0(v44, v106 + 16, v43);
          v45 = v43;
          v8 = v107;
          v46 = sub_FDA070(
                  v107,
                  dwNewLong,
                  1,
                  2,
                  *(v106 + 1),
                  0,
                  *(v106 + 2),
                  0xFFFFFFFF,
                  0,
                  -1,
                  *(v106 + 3),
                  v44,
                  v45,
                  &pnIDs);
          if ( v46 )
          {
            if ( dwNewLong )
              *(v46 + 4) = 0;
            v21 = v105;
            LOBYTE(pnIDs) = 1;
          }
          else
          {
            v21 = (v105 - 1);
            v105 = (v105 - 1);
          }
          v42 = v106;
        }
        v42 = (v42 + *v42);
        v106 = v42;
        ++v111;
      }
      while ( v111 < *lpMem );
    }
    if ( *&v102[1] )
    {
      v47 = *&v102[1];
      v48 = GetProcessHeap();
      HeapFree(v48, 0, v47);
    }
    goto LABEL_116;
  }
  if ( a3 > 0x138 )
  {
    if ( a3 == 1024 )
    {
LABEL_33:
      InvalidateRect(v8, 0, 0);
    }
    else if ( a3 == 2033 )
    {
      v89 = dwInitParam;
      if ( gdwVersion < 1 || (v90 = *dwInitParam, v111 = 5, !(*(v90 + 40) & 0x20)) )
        v111 = 4;
      if ( *(dwInitParam + 12) )
      {
        CloseHandle(*(dwInitParam + 12));
        v89 = dwInitParam;
      }
      if ( *(v89 + 16) )
      {
        RtlDestroyQueryDebugBuffer(*(v89 + 16));
        v89 = dwInitParam;
      }
      if ( *(v89 + 8) )
      {
        free(*(v89 + 8));
        v89 = dwInitParam;
      }
      free(v89);
      if ( SendMessageW(v8, 0x1004u, 0, 0) && v111 )
      {
        v91 = 0;
        do
        {
          v92 = gLogPixelSize.x;
          v93 = SendMessageW(v8, 0x101Du, v91, 0);
          *(&pnWidths + v91++) = MulDiv(v93, 96, v92);
        }
        while ( v91 < v111 );
        v5 = pSystemHandleInfo;
      }
      DestroyWindow(v5);
    }
    return 0;
  }
  if ( a3 != 312 && a3 != 307 && a3 != 310 )
    return 0;
  return PE_FillControl(hWnd, wParam);
}
// 1046C50: using guessed type __int128 xmmword_1046C50;
// 1046C70: using guessed type RECT stru_1046C70;
// 105D225: using guessed type char byte_105D225;
// 10610D8: using guessed type char byte_10610D8;
// 1064E54: using guessed type int gdwVersion;
// 106ABA5: using guessed type char gbSupportExtendedSystemHandleInformation;
// 106F264: using guessed type int (__stdcall *RtlDestroyQueryDebugBuffer)(_DWORD);
// 107D0A6: using guessed type __int16 word_107D0A6;
// 107D0A8: using guessed type __int16 word_107D0A8;
// 107D0AA: using guessed type __int16 word_107D0AA;
// 107D0AC: using guessed type __int16 word_107D0AC;
// 107D0B0: using guessed type int dword_107D0B0;
