
//----- (00FD7AB0) --------------------------------------------------------
// tagKeyName* ret = gKeyNameMap[LPCWSTR lpszKeyName]
int __thiscall sub_FD7AB0(std__tree *this, tagKeyName *KeyName, LPCWSTR lpszKey)
{
  std::map<wchar_t const *,_bstr_t,std::less<wchar_t const *>,std::allocator<std::pair<wchar_t const * const,tagKeyName>>>::_Try_emplace<wchar_t const * const &,>(
    this,
    KeyName,
    &lpszKey,
    0,
    lpszKey);
  return KeyName;
}

//----- (00FD7AE0) --------------------------------------------------------
int __cdecl PE_OutputErrorMsg(DWORD dwMessageId)
{
  int result; // eax
  DWORD v2; // ebx
  FILE *v3; // edi
  const wchar_t *v4; // esi
  wchar_t v5; // cx
  HLOCAL v6; // ST04_4
  HANDLE v7; // eax
  FILE *v8; // edi
  const wchar_t *v9; // esi
  wchar_t v10; // ax
  DWORD NumberOfBytesWritten; // [esp+4h] [ebp-8h]
  CHAR Buffer[4]; // [esp+8h] [ebp-4h]

  result = FormatMessageA(0x1300u, 0, dwMessageId, 0x400u, Buffer, 0, 0);
  v2 = result;
  if ( result )
  {
    if ( byte_10C31C9 )
    {
      v3 = (sub_1067B15() + 8);
      _fputwc_nolock(0x3Cu, v3);
      v4 = L"error";
      v5 = 101;
      do
      {
        _fputwc_nolock(v5, v3);
        v5 = v4[1];
        ++v4;
      }
      while ( v5 );
      _fputwc_nolock(0x3Eu, v3);
    }
    v6 = *Buffer;
    v7 = GetStdHandle(0xFFFFFFF4);
    WriteFile(v7, v6, v2, &NumberOfBytesWritten, 0);
    if ( byte_10C31C9 )
    {
      v8 = (sub_1067B15() + 8);
      _fputwc_nolock(0x3Cu, v8);
      _fputwc_nolock(0x2Fu, v8);
      v9 = L"error";
      v10 = 101;
      do
      {
        _fputwc_nolock(v10, v8);
        v10 = v9[1];
        ++v9;
      }
      while ( v10 );
      _fputwc_nolock(0x3Eu, v8);
    }
    result = LocalFree(*Buffer);
  }
  return result;
}
// 108D008: using guessed type wchar_t aError[6];
// 10C31C9: using guessed type char byte_10C31C9;

//----- (00FD7BE0) --------------------------------------------------------
CPEString *__cdecl MakeRegistryKeyName(CPEString *strResult, HKEY hKey, CPEString *strKeyName, CPEString *strValueName)
{
  CPEString strTemp; // eax
  CPEString strKeyRoot; // ebx
  const wchar_t *lpszKeyRoot; // eax
  CPEString *v7; // esi
  CPEString *v8; // eax
  CPEString *v9; // eax
  void *v10; // edi
  CPEString *v11; // eax
  CPEString str; // [esp+8h] [ebp-4h]

  strTemp.m_String = malloc(2u);
  strKeyRoot.m_String = strResult;
  strResult->m_String = strTemp.m_String;
  *strTemp.m_String = 0;
  if ( hKey == ghLocalMachineKey )
  {
    lpszKeyRoot = L"HKLM";
  }
  else
  {
    lpszKeyRoot = L"HKCU";
    if ( hKey != ghCurrentUserKey )
      lpszKeyRoot = L"?";
  }
  v7 = _wcsdup(lpszKeyRoot);
  strResult = v7;
  v8 = CPEString::Append(&str, &strResult, L"\\");
  v9 = CPEString::Append(&hKey, v8, strKeyName);
  v10 = *strKeyRoot.m_String;
  *strKeyRoot.m_String = _wcsdup(v9->m_String);
  free(v10);
  free(hKey);
  free(str.m_String);
  free(v7);
  if ( *strValueName->m_String )
  {
    v11 = operator+(&strResult, L"\\", strValueName);
    CPEString::InsertAt(strKeyRoot.m_String, v11->m_String, 0x7FFFFFFFu, 0);
    free(strResult);
  }
  return strKeyRoot.m_String;
}
// 108D5F4: using guessed type wchar_t asc_108D5F4[2];

//----- (00FD7CC0) --------------------------------------------------------
void __cdecl sub_FD7CC0(HWND a1, HWND a2)
{
  HWND v2; // edi
  WCHAR *v3; // ebx
  OLECHAR *v4; // esi
  wchar_t *v5; // eax
  wchar_t *v6; // esi
  CPEString *v7; // eax
  wchar_t *v8; // eax
  unsigned int v9; // eax
  int v10; // eax
  wchar_t *v11; // eax
  wchar_t *v12; // esi
  CPEString *v13; // eax
  wchar_t *v14; // eax
  wchar_t *v15; // eax
  wchar_t *v16; // esi
  CPEString *v17; // eax
  wchar_t *v18; // eax
  HWND v19; // edi
  wchar_t *v20; // eax
  wchar_t *v21; // esi
  CPEString *v22; // eax
  wchar_t *v23; // eax
  wchar_t *v24; // esi
  CPEString *v25; // eax
  HWND v26; // ecx
  WCHAR *v27; // esi
  wchar_t *v28; // eax
  const wchar_t **v29; // eax
  HWND v30; // eax
  HANDLE v31; // eax
  HWND v32; // esi
  HWND v33; // esi
  signed int v34; // ebx
  bool v35; // zf
  HWND v36; // eax
  HWND v37; // esi
  int v38; // eax
  int v39; // eax
  wchar_t v40; // ax
  wchar_t *v41; // esi
  HWND v42; // ebx
  int v43; // eax
  struct _STARTUPINFOW StartupInfo; // [esp+10h] [ebp-164h]
  struct _PROCESS_INFORMATION ProcessInformation; // [esp+54h] [ebp-120h]
  wchar_t *v46; // [esp+64h] [ebp-110h]
  WCHAR *v47; // [esp+68h] [ebp-10Ch]
  HWND hWnd; // [esp+6Ch] [ebp-108h]
  HKEY phkResult; // [esp+70h] [ebp-104h]
  DWORD v50; // [esp+74h] [ebp-100h]
  WCHAR *ppstr; // [esp+78h] [ebp-FCh]
  HWND hWndParent; // [esp+7Ch] [ebp-F8h]
  DWORD dwProcessId; // [esp+80h] [ebp-F4h]
  HWND v54; // [esp+84h] [ebp-F0h]
  DEVMODEW DevMode; // [esp+88h] [ebp-ECh]
  int v56; // [esp+170h] [ebp-4h]

  hWnd = a1;
  hWndParent = a2;
  v46 = 0;
  v2 = malloc(2u);
  v54 = v2;
  *v2 = 0;
  v56 = 0;
  v3 = malloc(2u);
  v47 = v3;
  *v3 = 0;
  v4 = malloc(2u);
  v50 = v4;
  *v4 = 0;
  LOBYTE(v56) = 2;
  DevMode.dmSize = 220;
  EnumDisplaySettingsW(0, 0xFFFFFFFF, &DevMode);
  if ( *hWndParent == 48 )
  {
    MessageBoxW(hWnd, L"The full name of the selected key or value is not available.", L"Process Explorer", 0x30u);
    goto LABEL_47;
  }
  if ( !wcsncmp(hWndParent, L"HKLM", 4u) )
  {
    v5 = _wcsdup(L"\\HKEY_LOCAL_MACHINE");
    v6 = v5;
    v54 = v5;
    v7 = CPEString::Append(&dwProcessId, &v54, hWndParent + 4);
    ppstr = v2;
    v8 = _wcsdup(v7->m_String);
    v2 = v8;
    v54 = v8;
    free(ppstr);
    free(dwProcessId);
    free(v6);
    v9 = TlsGetValue(gdwTlsIndex);
    v10 = PE_OpenKey(ghLocalMachineKey, hWndParent + 5, 0, v9 | 0x20019, &phkResult);
  }
  else if ( !wcsncmp(hWndParent, L"HKCU", 4u) )
  {
    v11 = _wcsdup(L"\\HKEY_CURRENT_USER");
    v12 = v11;
    dwProcessId = v11;
    v13 = CPEString::Append(&ppstr, &dwProcessId, hWndParent + 4);
    dwProcessId = v2;
    v14 = _wcsdup(v13->m_String);
    v2 = v14;
    v54 = v14;
    free(dwProcessId);
    free(ppstr);
    free(v12);
    v10 = RegOpenKeyW(ghCurrentUserKey, hWndParent + 5, &phkResult);
  }
  else if ( !wcsncmp(hWndParent, L"HKCC", 4u) )
  {
    v15 = _wcsdup(L"\\HKEY_CURRENT_CONFIG");
    v16 = v15;
    dwProcessId = v15;
    v17 = CPEString::Append(&ppstr, &dwProcessId, hWndParent + 4);
    dwProcessId = v2;
    v18 = _wcsdup(v17->m_String);
    v2 = v18;
    v54 = v18;
    free(dwProcessId);
    free(ppstr);
    free(v16);
    v10 = RegOpenKeyW(HKEY_CURRENT_CONFIG, hWndParent + 5, &phkResult);
  }
  else
  {
    v19 = hWndParent;
    if ( !wcsncmp(hWndParent, L"HKCR", 4u) )
    {
      v20 = _wcsdup(L"\\HKEY_CLASSES_ROOT");
      v21 = v20;
      dwProcessId = v20;
      v22 = CPEString::Append(&ppstr, &dwProcessId, hWndParent + 4);
      CPEString::Reset2(&v54, v22);
      free(ppstr);
      free(v21);
      v10 = RegOpenKeyW(HKEY_CLASSES_ROOT, v19 + 5, &phkResult);
    }
    else
    {
      if ( wcsncmp(hWndParent, L"HKU", 3u) )
      {
        CPEString::Reset(&v54, hWndParent);
        goto LABEL_17;
      }
      v23 = _wcsdup(L"\\HKEY_USERS");
      v24 = v23;
      dwProcessId = v23;
      v25 = CPEString::Append(&ppstr, &dwProcessId, hWndParent + 3);
      CPEString::Reset2(&v54, v25);
      free(ppstr);
      free(v24);
      v10 = RegOpenKeyW(HKEY_USERS, v19 + 4, &phkResult);
    }
    v2 = v54;
  }
  if ( !v10 )
  {
LABEL_17:
    RegCloseKey(phkResult);
    CPEString::InsertAt(&v54, L"\\", 0x7FFFFFFFu, 0);
    v2 = v54;
    goto LABEL_18;
  }
  v46 = wcsrchr(v2, 0x5Cu) + 1;
  *wcsrchr(v2, 0x5Cu) = 0;
LABEL_18:
  v26 = FindWindowW(L"RegEdit_RegEdit", 0);
  hWndParent = v26;
  if ( v26 )
  {
    GetWindowThreadProcessId(v26, &dwProcessId);
    v31 = OpenProcess(0, 0, dwProcessId);
    v4 = v50;
    ProcessInformation.hProcess = v31;
    v30 = hWndParent;
  }
  else
  {
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    memset(&StartupInfo, 0, 0x44u);
    StartupInfo.cb = 68;
    StartupInfo.dwFlags = 1;
    StartupInfo.wShowWindow = 1;
    v27 = v3;
    if ( (GetVersion() & 0x80000000) == 0 )
      v28 = _wcsdup(L"%systemroot%\\regedit.exe");
    else
      v28 = _wcsdup(L"%windir%\\regedit.exe");
    v3 = v28;
    v47 = v28;
    free(v27);
    v29 = RequerySystemEnvironmentString(&ppstr, v3);
    dwProcessId = v50;
    v4 = _wcsdup(*v29);
    v50 = v4;
    free(dwProcessId);
    free(ppstr);
    sub_FE1040(v4);
    if ( CreateProcessW(v4, v4, 0, 0, 0, 0, 0, 0, &StartupInfo, &ProcessInformation) )
    {
      WaitForInputIdle(ProcessInformation.hProcess, 0xFFFFFFFF);
      CloseHandle(ProcessInformation.hThread);
    }
    GetLastError();
    v30 = FindWindowW(L"RegEdit_RegEdit", 0);
    hWndParent = v30;
  }
  if ( v30 )
  {
    ShowWindow(v30, 5);
    v32 = hWndParent;
    SetForegroundWindow(hWndParent);
    hWnd = FindWindowExW(v32, 0, L"SysTreeView32", 0);
    SetForegroundWindow(hWnd);
    v33 = hWnd;
    SetFocus(hWnd);
    WaitForInputIdle(ProcessInformation.hProcess, 0xFFFFFFFF);
    SendMessageW(hWndParent, 0x111u, 0x10288u, 0);
    WaitForInputIdle(ProcessInformation.hProcess, 0xFFFFFFFF);
    v34 = 30;
    do
    {
      SendMessageW(v33, 0x100u, 0x25u, 0);
      WaitForInputIdle(ProcessInformation.hProcess, 0xFFFFFFFF);
      --v34;
    }
    while ( v34 );
    v35 = *v2 == 0;
    v36 = v2;
    v3 = v47;
    v4 = v50;
    v54 = v2;
    if ( !v35 )
    {
      v37 = hWnd;
      do
      {
        v38 = *v36;
        if ( v38 == 92 )
        {
          SendMessageW(v37, 0x100u, 0x27u, 0);
        }
        else
        {
          v39 = toupper(v38);
          SendMessageW(v37, 0x102u, v39, 0);
        }
        WaitForInputIdle(ProcessInformation.hProcess, 0xFFFFFFFF);
        v36 = (v54 + 2);
        v54 = v36;
      }
      while ( *v36 );
      v4 = v50;
    }
    WaitForInputIdle(ProcessInformation.hProcess, 0xFFFFFFFF);
    if ( v46 )
    {
      v54 = FindWindowExW(hWndParent, 0, L"SysListView32", 0);
      SetForegroundWindow(v54);
      SetFocus(v54);
      if ( DevMode.dmBitsPerPel > 8 )
        Sleep(0x2EEu);
      SendMessageW(v54, 0x100u, 0x24u, 0);
      v40 = *v46;
      if ( *v46 )
      {
        v41 = v46;
        v42 = v54;
        do
        {
          v43 = toupper(v40);
          SendMessageW(v42, 0x102u, v43, 0);
          WaitForInputIdle(ProcessInformation.hProcess, 0xFFFFFFFF);
          v40 = v41[1];
          ++v41;
        }
        while ( v40 );
        v3 = v47;
        v4 = v50;
      }
    }
    SetForegroundWindow(hWndParent);
    SetFocus(hWndParent);
    CloseHandle(ProcessInformation.hProcess);
  }
  else
  {
    MessageBoxW(
      hWnd,
      L"Error launching Regedit. Make sure you are running with Administrative rights.",
      L"Process Explorer",
      0x30u);
  }
LABEL_47:
  free(v4);
  free(v3);
  free(v2);
}
// 108D418: using guessed type wchar_t aWindirRegeditE[21];

//----- (00FD84A0) --------------------------------------------------------
CPEString __cdecl CPEString::AppendPath(CPEString *str, LPCWSTR lpszText)
{
  CPEString v2; // eax
  char Ret; // bl
  unsigned int nIndex; // edi
  WCHAR *v5; // esi
  WCHAR *v6; // esi
  unsigned int i; // edx
  int v8; // eax

  v2.m_String = malloc(2u);
  Ret = 0;
  str->m_String = v2.m_String;
  nIndex = 2;
  *v2.m_String = 0;
  v5 = str->m_String;
  str->m_String = _wcsdup(lpszText);
  free(v5);
  v6 = str->m_String;
  if ( !wcsncmp(lpszText, L"File not found: ", 16u) )
    nIndex = ERROR_NO_MORE_FILES;
  for ( i = nIndex; nIndex < wcslen(lpszText); ++nIndex )
  {
    v8 = lpszText[nIndex];
    if ( v8 == '\\' )
    {
      if ( !Ret )
        v6[i++] = '\\';
      Ret = 1;
    }
    else
    {
      Ret = 0;
      v6[i++] = v8;
    }
  }
  v6[i] = lpszText[nIndex];
  free(lpszText);
  return str;
}

//----- (00FD85A0) --------------------------------------------------------
_bstr_t *__cdecl tagKeyName::Update(_bstr_t *ret, LPCWSTR lpszKeyName, int Off, _bstr_t *pbstr)
{
  _bstr_t *strIn; // edi
  UINT nLength; // ebx
  OLECHAR *v6; // edx
  BOOL fLengthIsZero; // eax
  int nFlags; // ecx
  _bstr_t *v10; // edi
  Data_t_bstr_t *v11; // eax
  Data_t_bstr_t *v12; // eax
  _bstr_t bstr1; // [esp+10h] [ebp-14h]
  int v14; // [esp+14h] [ebp-10h]
  int v15; // [esp+20h] [ebp-4h]

  ret->m_Data = 0;
  strIn = pbstr;
  v15 = 0;
  v14 = 1;
  if ( pbstr->m_Data && pbstr->m_Data->m_wstr )
    nLength = SysStringLen(pbstr->m_Data->m_wstr);
  else
    nLength = 0;
  v6 = lpszKeyName;
  fLengthIsZero = nLength != 0;
  nFlags = (*lpszKeyName != 0) - fLengthIsZero;
  if ( nFlags == -1 )
  {
    if ( ret != strIn )
    {
      _bstr_t::_Free(ret);
      v12 = strIn->m_Data;
      ret->m_Data = strIn->m_Data;
      if ( v12 )
        InterlockedIncrement(&v12->m_RefCount);
    }
    return ret;
  }
  if ( (*lpszKeyName != 0) != fLengthIsZero )
  {
    if ( nFlags == 1 )
    {
      if ( Off )
        v6 = &lpszKeyName[Off + 1];
      _bstr_t::operator=(ret, v6);
      return ret;
    }
    return ret;
  }
  _bstr_t::_bstr_t(&pbstr, &lpszKeyName[Off]);
  v15 = 1;
  v10 = _bstr_t::operator+(strIn, &bstr1, &pbstr);
  if ( ret != v10 )
  {
    _bstr_t::_Free(ret);
    v11 = v10->m_Data;
    ret->m_Data = v10->m_Data;
    if ( v11 )
      InterlockedIncrement(&v11->m_RefCount);
  }
  _bstr_t::_Free(&bstr1);
  _bstr_t::_Free(&pbstr);
  return ret;
}

//----- (00FD86F0) --------------------------------------------------------
void __cdecl sub_FD86F0(int a1, void *a2, void *a3)
{
  _WORD *v3; // ST50_4
  CPEString *v4; // esi
  void *v5; // edi
  CPEString *v6; // eax
  wchar_t *v7; // ST54_4

  v3 = malloc(2u);
  *v3 = 0;
  v4 = a3;
  v5 = sub_FD87A0(a1, a2, *a3, 0xFFFFFFFF);
  v6 = CPEString::Append(&a3, v4, L"\\AutorunsDisabled");
  v7 = _wcsdup(v6->m_String);
  free(v3);
  free(a3);
  sub_FD87A0(a1, a2, v7, v5);
  free(v7);
}

//----- (00FD87A0) --------------------------------------------------------
void *__cdecl sub_FD87A0(int a1, void *a2, wchar_t *psz, void *a4)
{
  _WORD *v4; // ebx
  wchar_t *v5; // esi
  const wchar_t *v6; // eax
  wchar_t *v7; // eax
  wchar_t *v8; // ebx
  WCHAR *v9; // eax
  WCHAR *v10; // edi
  const wchar_t *v11; // eax
  wchar_t *v12; // esi
  CPEString *v13; // eax
  unsigned int v14; // eax
  WCHAR *v15; // edi
  _WORD *v16; // esi
  CPEString *v17; // eax
  CPEString *v18; // eax
  WCHAR *v19; // esi
  CPEString *v20; // eax
  void *v21; // esi
  const WCHAR *v22; // esi
  unsigned int v23; // eax
  const wchar_t **v24; // eax
  WCHAR *v25; // esi
  CPEString *v26; // eax
  WCHAR *v27; // edi
  WCHAR *v28; // edi
  const WCHAR *v29; // esi
  unsigned int v30; // eax
  const wchar_t *v31; // eax
  WCHAR *v32; // eax
  WCHAR *v33; // ebx
  wchar_t *v34; // eax
  wchar_t *v35; // edi
  const wchar_t *v36; // eax
  wchar_t *v37; // esi
  CPEString *v38; // eax
  const wchar_t *v39; // eax
  wchar_t *v40; // eax
  wchar_t *v41; // ebx
  wchar_t *v42; // eax
  wchar_t *v43; // edi
  const wchar_t *v44; // eax
  wchar_t *v45; // esi
  CPEString *v46; // eax
  wchar_t *v47; // eax
  wchar_t *v48; // edi
  const wchar_t *v49; // eax
  wchar_t *v50; // esi
  CPEString *v51; // eax
  WCHAR *ppv1; // [esp+10h] [ebp-A0h]
  WCHAR v54[2]; // [esp+14h] [ebp-9Ch]
  WCHAR v55[2]; // [esp+18h] [ebp-98h]
  int a4a; // [esp+1Ch] [ebp-94h]
  int v57; // [esp+20h] [ebp-90h]
  CPEString v58; // [esp+24h] [ebp-8Ch]
  WCHAR v59[2]; // [esp+28h] [ebp-88h]
  WCHAR v60[2]; // [esp+2Ch] [ebp-84h]
  WCHAR v61[2]; // [esp+30h] [ebp-80h]
  void *v62; // [esp+34h] [ebp-7Ch]
  WCHAR *pszResult; // [esp+38h] [ebp-78h]
  void *v64; // [esp+3Ch] [ebp-74h]
  tagPEStringStruct v65; // [esp+40h] [ebp-70h]
  void *a1a; // [esp+5Ch] [ebp-54h]
  HKEY KeyHandle; // [esp+60h] [ebp-50h]
  LPCWSTR v68; // [esp+64h] [ebp-4Ch]
  _WORD *v69; // [esp+68h] [ebp-48h]
  CPEString v70; // [esp+6Ch] [ebp-44h]
  CPEString str1; // [esp+70h] [ebp-40h]
  LPCWSTR szArg4; // [esp+74h] [ebp-3Ch]
  void *v73; // [esp+78h] [ebp-38h]
  DWORD dwIndex; // [esp+7Ch] [ebp-34h]
  LPCWSTR szKeyName; // [esp+80h] [ebp-30h]
  WCHAR szArg[2]; // [esp+84h] [ebp-2Ch]
  LPCWSTR szArg3; // [esp+88h] [ebp-28h]
  char v78; // [esp+8Fh] [ebp-21h]
  WCHAR *ppv2; // [esp+90h] [ebp-20h]
  CPEString str3; // [esp+94h] [ebp-1Ch]
  HKEY hKey; // [esp+98h] [ebp-18h]
  wchar_t *ppv3; // [esp+9Ch] [ebp-14h]
  LPCWSTR lpszKeyName; // [esp+A0h] [ebp-10h]
  int v84; // [esp+ACh] [ebp-4h]

  v73 = malloc(2u);
  str1.m_String = v73;
  *v73 = 0;
  v84 = 0;
  v65.strValue[4] = malloc(2u);
  *v65.strValue[4] = 0;
  v64 = malloc(2u);
  *v64 = 0;
  v65.strValue[6] = malloc(2u);
  *v65.strValue[6] = 0;
  v4 = malloc(2u);
  v69 = v4;
  *v4 = 0;
  v5 = psz;
  LOBYTE(v84) = 4;
  if ( a4 == -1 )
  {
    szArg4 = _wcsdup(&gszNullString);
    v70.m_String = _wcsdup(&gszNullString);
    lpszKeyName = _wcsdup(&gszNullString);
    ppv3 = _wcsdup(&gszNullString);
    hKey = _wcsdup(&gszNullString);
    str3.m_String = _wcsdup(&gszNullString);
    dwIndex = _wcsdup(&gszNullString);
    v6 = &gszNullString;
    if ( psz )
      v6 = psz;
    v7 = _wcsdup(v6);
    v8 = v7;
    a4 = v7;
    v9 = _wcsdup(&gszNullString);
    v10 = v9;
    ppv2 = v9;
    v11 = &gszNullString;
    if ( psz )
      v11 = psz;
    v12 = _wcsdup(v11);
    szArg3 = v12;
    szKeyName = MakeRegistryKeyName(&a1a, a2, &a4, &dwIndex);
    v13 = MakeRegistryKeyName(szArg, a2, &szArg3, &ppv2);
    LOBYTE(v84) = 16;
    a4 = sub_FD3FF0(a1, 0, 0xFFFFFFFF, 0, v13, szKeyName, &str3);
    free(*szArg);
    free(a1a);
    free(v12);
    free(v10);
    free(v8);
    free(dwIndex);
    free(str3.m_String);
    free(hKey);
    free(ppv3);
    free(lpszKeyName);
    free(v70.m_String);
    LOBYTE(v84) = 4;
    free(szArg4);
    v4 = v69;
    v5 = psz;
  }
  v14 = TlsGetValue(gdwTlsIndex);
  if ( !PE_OpenKey(a2, v5, 0, v14 | 0x20019, &KeyHandle) )
  {
    dwIndex = 0;
    lpszKeyName = malloc(2u);
    *lpszKeyName = 0;
    ppv3 = malloc(2u);
    *ppv3 = 0;
    v15 = malloc(2u);
    str3.m_String = v15;
    *v15 = 0;
    v16 = malloc(2u);
    v65.strValue[0] = v16;
    v65.strValue[1] = 0;
    v65.strValue[2] = 0;
    *v16 = 0;
    v65.strValue[3] = 0;
    LOBYTE(v84) = 20;
    if ( !PE_LoadRegKeys(KeyHandle, 0, &ppv3) )
    {
      do
      {
        v17 = operator+(&pszResult, L"CLSID\\", &ppv3);
        v18 = CPEString::Append(&a1a, v17, L"\\InprocServer32");
        v19 = lpszKeyName;
        lpszKeyName = _wcsdup(v18->m_String);
        free(v19);
        free(a1a);
        free(pszResult);
        v20 = operator+(&v58, L"HKCR\\CLSID\\", &ppv3);
        v21 = v4;
        v4 = _wcsdup(v20->m_String);
        v69 = v4;
        free(v21);
        free(v58.m_String);
        v22 = lpszKeyName;
        v23 = TlsGetValue(gdwTlsIndex);
        if ( !PE_OpenKey(HKEY_CLASSES_ROOT, v22, 0, v23 | 0x20019, &hKey) )
        {
          if ( !PE_ReadRegKey(hKey, &gszNullString, 0, 0, &lpszKeyName) )
          {
            sub_FD7040(lpszKeyName, &v65);
            v24 = sub_FD4EE0(&v62, a1, &v65, 0);
            str3.m_String = _wcsdup(*v24);
            free(v15);
            free(v62);
            RegCloseKey(hKey);
            v25 = _wcsdup(L"CLSID\\");
            ppv2 = v25;
            v26 = CPEString::Append(&ppv1, &ppv2, &ppv3);
            v27 = lpszKeyName;
            lpszKeyName = _wcsdup(v26->m_String);
            free(v27);
            free(ppv1);
            free(v25);
            v28 = _wcsdup(ppv3);
            str1.m_String = v28;
            free(v73);
            v29 = lpszKeyName;
            v30 = TlsGetValue(gdwTlsIndex);
            if ( !PE_OpenKey(HKEY_CLASSES_ROOT, v29, 0, v30 | 0x20019, &hKey) )
            {
              if ( !PE_ReadRegKey(hKey, &gszNullString, 0, 0, &lpszKeyName) && wcslen(lpszKeyName) )
              {
                str1.m_String = _wcsdup(lpszKeyName);
                free(v28);
              }
              RegCloseKey(hKey);
            }
            v31 = &gszNullString;
            if ( psz )
              v31 = psz;
            v32 = _wcsdup(v31);
            v33 = v32;
            ppv2 = v32;
            v34 = _wcsdup(&gszNullString);
            v35 = v34;
            szArg3 = v34;
            v36 = &gszNullString;
            if ( psz )
              v36 = psz;
            v37 = _wcsdup(v36);
            szKeyName = v37;
            *szArg = MakeRegistryKeyName(v60, a2, &ppv2, &ppv3);
            v38 = MakeRegistryKeyName(v54, a2, &szKeyName, &szArg3);
            LOBYTE(v84) = 25;
            v78 = sub_FD3D40(a1, &str1, v38, *szArg, &str3, &v65.strValue[4], &v65.strValue[6], &v57);
            free(*v54);
            free(*v60);
            free(v37);
            free(v35);
            free(v33);
            if ( v78 )
            {
              if ( a4 == -1 )
              {
                ppv2 = _wcsdup(&gszNullString);
                szArg3 = _wcsdup(&gszNullString);
                szKeyName = _wcsdup(&gszNullString);
                *szArg = _wcsdup(&gszNullString);
                v73 = _wcsdup(&gszNullString);
                v70.m_String = _wcsdup(&gszNullString);
                szArg4 = _wcsdup(&gszNullString);
                v39 = &gszNullString;
                if ( psz )
                  v39 = psz;
                v40 = _wcsdup(v39);
                v41 = v40;
                a4 = v40;
                v42 = _wcsdup(&gszNullString);
                v43 = v42;
                a4a = v42;
                v44 = &gszNullString;
                if ( psz )
                  v44 = psz;
                v45 = _wcsdup(v44);
                v65.strValue[5] = v45;
                v68 = MakeRegistryKeyName(v59, a2, &a4, &szArg4);
                v46 = MakeRegistryKeyName(v61, a2, &v65.strValue[5], &a4a);
                LOBYTE(v84) = 37;
                a4 = sub_FD3FF0(a1, 0, 0xFFFFFFFF, 0, v46, v68, &v70);
                free(*v61);
                free(*v59);
                free(v45);
                free(v43);
                free(v41);
                free(szArg4);
                free(v70.m_String);
                free(v73);
                free(*szArg);
                free(szKeyName);
                free(szArg3);
                free(ppv2);
              }
              v47 = _wcsdup(&gszNullString);
              v48 = v47;
              v65.strValue[5] = v47;
              v49 = &gszNullString;
              if ( psz )
                v49 = psz;
              v50 = _wcsdup(v49);
              v68 = v50;
              v51 = MakeRegistryKeyName(v55, a2, &v68, &ppv3);
              LOBYTE(v84) = 40;
              sub_FD3FF0(a1, 0xFFFFFFFF, a4, 3u, &str1, v51, &str3);
              free(*v55);
              free(v50);
              free(v48);
            }
            sub_FD21F0(&v65);
            free(str3.m_String);
            free(ppv3);
            free(lpszKeyName);
            v4 = v69;
            v73 = str1.m_String;
            goto LABEL_33;
          }
          RegCloseKey(hKey);
        }
        sub_FD21F0(&v65);
        free(v15);
        free(ppv3);
        free(lpszKeyName);
LABEL_33:
        ++dwIndex;
        lpszKeyName = malloc(2u);
        *lpszKeyName = 0;
        ppv3 = malloc(2u);
        *ppv3 = 0;
        v15 = malloc(2u);
        str3.m_String = v15;
        *v15 = 0;
        v16 = malloc(2u);
        v65.strValue[0] = v16;
        v65.strValue[1] = 0;
        v65.strValue[2] = 0;
        *v16 = 0;
        v65.strValue[3] = 0;
        LOBYTE(v84) = 20;
      }
      while ( !PE_LoadRegKeys(KeyHandle, dwIndex, &ppv3) );
    }
    free(v16);
    free(v15);
    free(ppv3);
    free(lpszKeyName);
    RegCloseKey(KeyHandle);
  }
  free(v4);
  free(v65.strValue[6]);
  free(v64);
  free(v65.strValue[4]);
  free(v73);
  return a4;
}

//----- (00FD9030) --------------------------------------------------------
void __cdecl sub_FD9030(void *a1, int a2, void *a3, wchar_t *a4)
{
  _WORD *v4; // eax
  void *v5; // ebx
  const wchar_t *v6; // eax
  WCHAR *v7; // esi
  CPEString *v8; // eax
  CPEString *v9; // eax
  WCHAR *v10; // edi
  const wchar_t *v11; // ecx
  wchar_t *v12; // esi
  CPEString *v13; // eax
  CPEString *v14; // eax
  WCHAR *v15; // ebx
  WCHAR *pszResult; // [esp+10h] [ebp-18h]
  WCHAR *ppv; // [esp+14h] [ebp-14h]
  WCHAR *ppszText2; // [esp+18h] [ebp-10h]
  int v19; // [esp+24h] [ebp-4h]

  v4 = malloc(2u);
  v5 = v4;
  *v4 = 0;
  v19 = 0;
  v6 = &gszNullString;
  if ( a4 )
    v6 = a4;
  v7 = _wcsdup(v6);
  ppszText2 = v7;
  v8 = operator+(&pszResult, L"Software\\Classes\\CLSID\\", &ppszText2);
  v9 = CPEString::Append(&ppv, v8, L"\\Instance");
  v10 = _wcsdup(v9->m_String);
  ppszText2 = v10;
  free(v5);
  free(ppv);
  free(pszResult);
  free(v7);
  sub_FD86F0(a2, a3, &ppszText2);
  if ( a1 )
  {
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    v11 = &gszNullString;
    if ( a4 )
      v11 = a4;
    v12 = _wcsdup(v11);
    a4 = v12;
    v13 = operator+(&pszResult, L"Software\\Wow6432Node\\Classes\\CLSID\\", &a4);
    v14 = CPEString::Append(&a1, v13, L"\\Instance");
    v15 = v10;
    v10 = _wcsdup(v14->m_String);
    ppszText2 = v10;
    free(v15);
    free(a1);
    free(pszResult);
    free(v12);
    sub_FD86F0(a2, a3, &ppszText2);
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
  }
  free(v10);
}

//----- (00FD91C0) --------------------------------------------------------
void __cdecl PE_RefreshRegistry2(int a1, int a2, void *a3)
{
  _WORD *v3; // ST50_4
  CPEString *v4; // esi
  void *v5; // edi
  CPEString *v6; // eax
  wchar_t *v7; // ST54_4

  v3 = malloc(2u);
  *v3 = 0;
  v4 = a3;
  v5 = sub_FD9270(a1, a2, *a3, 0xFFFFFFFF);
  v6 = CPEString::Append(&a3, v4, L"\\AutorunsDisabled");
  v7 = _wcsdup(v6->m_String);
  free(v3);
  free(a3);
  sub_FD9270(a1, a2, v7, v5);
  free(v7);
}

//----- (00FD9270) --------------------------------------------------------
void *__cdecl sub_FD9270(int a1, int a2, wchar_t *psz, void *a4)
{
  int v4; // edi
  wchar_t *v5; // esi
  const wchar_t *v6; // eax
  wchar_t *v7; // eax
  wchar_t *v8; // ebx
  wchar_t *v9; // eax
  wchar_t *v10; // edi
  const wchar_t *v11; // eax
  wchar_t *v12; // esi
  CPEString *v13; // eax
  unsigned int v14; // eax
  int v15; // eax
  CPEString *v16; // eax
  const WCHAR **v17; // eax
  wchar_t *v18; // eax
  wchar_t *v19; // ebx
  wchar_t *v20; // eax
  wchar_t *v21; // edi
  const WCHAR **v22; // eax
  wchar_t *v23; // eax
  wchar_t *v24; // esi
  const wchar_t *v25; // eax
  CPEString *v26; // eax
  wchar_t *v27; // esi
  const wchar_t *v28; // eax
  wchar_t *v29; // eax
  wchar_t *v30; // ebx
  wchar_t *v31; // eax
  wchar_t *v32; // edi
  const WCHAR **v33; // eax
  wchar_t *v34; // esi
  CPEString *v35; // eax
  wchar_t *v36; // eax
  wchar_t *v37; // ebx
  const wchar_t *v38; // esi
  const wchar_t *v39; // eax
  wchar_t *v40; // edi
  wchar_t *v41; // esi
  CPEString *v42; // eax
  int a2a; // [esp+10h] [ebp-3A4h]
  wchar_t **v45; // [esp+14h] [ebp-3A0h]
  int v46; // [esp+18h] [ebp-39Ch]
  int v47; // [esp+1Ch] [ebp-398h]
  int v48; // [esp+20h] [ebp-394h]
  void *v49; // [esp+24h] [ebp-390h]
  HKEY hKey; // [esp+28h] [ebp-38Ch]
  DWORD cbData; // [esp+2Ch] [ebp-388h]
  WCHAR v52[2]; // [esp+30h] [ebp-384h]
  wchar_t *v53; // [esp+34h] [ebp-380h]
  WCHAR *ppv3; // [esp+38h] [ebp-37Ch]
  void *v55; // [esp+3Ch] [ebp-378h]
  CPEString v56; // [esp+40h] [ebp-374h]
  wchar_t *pszText; // [esp+44h] [ebp-370h]
  CPEString str3; // [esp+48h] [ebp-36Ch]
  void *v59; // [esp+4Ch] [ebp-368h]
  int a3; // [esp+50h] [ebp-364h]
  LPCWSTR szArg4; // [esp+54h] [ebp-360h]
  WCHAR v62[2]; // [esp+58h] [ebp-35Ch]
  void *v63; // [esp+5Ch] [ebp-358h]
  int v64; // [esp+60h] [ebp-354h]
  WCHAR v65[2]; // [esp+64h] [ebp-350h]
  void *szArg; // [esp+68h] [ebp-34Ch]
  char v67; // [esp+6Fh] [ebp-345h]
  WCHAR v68[2]; // [esp+70h] [ebp-344h]
  HKEY hRootKey; // [esp+74h] [ebp-340h]
  void *a1a; // [esp+78h] [ebp-33Ch]
  LPCWSTR v71; // [esp+7Ch] [ebp-338h]
  LPCWSTR v72; // [esp+80h] [ebp-334h]
  wchar_t Data[400]; // [esp+84h] [ebp-330h]
  int v74; // [esp+3B0h] [ebp-4h]

  v4 = a1;
  v5 = psz;
  v64 = a1;
  hRootKey = a2;
  v53 = psz;
  v56.m_String = malloc(2u);
  *v56.m_String = 0;
  v74 = 0;
  v55 = malloc(2u);
  *v55 = 0;
  v49 = malloc(2u);
  *v49 = 0;
  ppv3 = malloc(2u);
  *ppv3 = 0;
  LOBYTE(v74) = 3;
  if ( a4 == -1 )
  {
    v72 = _wcsdup(&gszNullString);
    v71 = _wcsdup(&gszNullString);
    *v68 = _wcsdup(&gszNullString);
    v63 = _wcsdup(&gszNullString);
    v59 = _wcsdup(&gszNullString);
    str3.m_String = _wcsdup(&gszNullString);
    szArg4 = _wcsdup(&gszNullString);
    v6 = &gszNullString;
    if ( psz )
      v6 = psz;
    v7 = _wcsdup(v6);
    v8 = v7;
    pszText = v7;
    v9 = _wcsdup(L"(Default)");
    v10 = v9;
    *v62 = v9;
    v11 = &gszNullString;
    if ( psz )
      v11 = psz;
    v12 = _wcsdup(v11);
    a3 = v12;
    *v65 = MakeRegistryKeyName(&a1a, hRootKey, &pszText, &szArg4);
    v13 = MakeRegistryKeyName(&szArg, hRootKey, &a3, v62);
    LOBYTE(v74) = 15;
    a4 = sub_FD3FF0(v64, 0, 0xFFFFFFFF, 0, v13, *v65, &str3);
    free(szArg);
    free(a1a);
    free(v12);
    free(v10);
    free(v8);
    free(szArg4);
    free(str3.m_String);
    free(v59);
    free(v63);
    free(*v68);
    free(v71);
    LOBYTE(v74) = 3;
    free(v72);
    v5 = v53;
    v4 = v64;
  }
  v14 = TlsGetValue(gdwTlsIndex);
  if ( !PE_OpenKey(hRootKey, v5, 0, v14 | 0x20019, &hKey) )
  {
    cbData = 800;
    if ( !RegQueryValueExW(hKey, &gszNullString, 0, 0, Data, &cbData) && cbData )
    {
      a2a = malloc(2u);
      v45 = 0;
      v46 = 0;
      *a2a = 0;
      v47 = 0;
      LOBYTE(v74) = 16;
      if ( sub_FD6CC0(Data, &a2a) )
      {
        pszText = *v45;
        v15 = wcscmp(pszText, L"%1");
        if ( v15 )
          v15 = -(v15 < 0) | 1;
        if ( v15 )
        {
          v16 = sub_FD4EE0(&a1a, v4, &a2a, 0);
          CPEString::Reset2(&v56, v16);
          free(a1a);
          v71 = _wcsdup(L"(Default)");
          v17 = &gszNullString;
          if ( v5 )
            v17 = v5;
          v18 = _wcsdup(v17);
          v19 = v18;
          a1a = v18;
          v20 = _wcsdup(&gszNullString);
          v21 = v20;
          szArg = v20;
          v22 = &gszNullString;
          if ( v5 )
            v22 = v5;
          v23 = _wcsdup(v22);
          v24 = v23;
          *v65 = v23;
          v25 = &gszNullString;
          if ( pszText )
            v25 = pszText;
          v72 = _wcsdup(v25);
          a3 = MakeRegistryKeyName(v68, hRootKey, &a1a, &v71);
          v26 = MakeRegistryKeyName(v62, hRootKey, v65, &szArg);
          LOBYTE(v74) = 23;
          v67 = sub_FD3D40(v64, &v72, v26, a3, &v56, &v55, &ppv3, &v48);
          free(*v62);
          free(*v68);
          free(v72);
          free(v24);
          free(v21);
          free(v19);
          LOBYTE(v74) = 16;
          free(v71);
          if ( v67 )
          {
            if ( a4 == -1 )
            {
              szArg4 = _wcsdup(&gszNullString);
              str3.m_String = _wcsdup(&gszNullString);
              v59 = _wcsdup(&gszNullString);
              v63 = _wcsdup(&gszNullString);
              *v68 = _wcsdup(&gszNullString);
              v71 = _wcsdup(&gszNullString);
              v72 = _wcsdup(&gszNullString);
              v27 = v53;
              v28 = &gszNullString;
              if ( v53 )
                v28 = v53;
              v29 = _wcsdup(v28);
              v30 = v29;
              a1a = v29;
              v31 = _wcsdup(L"(Default)");
              v32 = v31;
              szArg = v31;
              v33 = &gszNullString;
              if ( v27 )
                v33 = v27;
              v34 = _wcsdup(v33);
              *v65 = v34;
              a3 = MakeRegistryKeyName(v52, hRootKey, &a1a, &v72);
              v35 = MakeRegistryKeyName(v62, hRootKey, v65, &szArg);
              LOBYTE(v74) = 35;
              a4 = sub_FD3FF0(v64, 0, 0xFFFFFFFF, 0, v35, a3, &v71);
              free(*v62);
              free(*v52);
              free(v34);
              free(v32);
              free(v30);
              free(v72);
              free(v71);
              free(*v68);
              free(v63);
              free(v59);
              free(str3.m_String);
              free(szArg4);
            }
            v71 = _wcsdup(&gszNullString);
            v72 = _wcsdup(&gszNullString);
            v36 = _wcsdup(L"(Default)");
            v37 = v36;
            *v52 = v36;
            v38 = &gszNullString;
            v39 = &gszNullString;
            if ( v53 )
              v39 = v53;
            v40 = _wcsdup(v39);
            a1a = v40;
            if ( pszText )
              v38 = pszText;
            v41 = _wcsdup(v38);
            szArg = v41;
            v42 = MakeRegistryKeyName(v65, hRootKey, &a1a, v52);
            LOBYTE(v74) = 41;
            sub_FD3FF0(v64, 0xFFFFFFFF, a4, 0xCu, &szArg, v42, &v56);
            free(*v65);
            free(v41);
            free(v40);
            free(v37);
            free(v72);
            free(v71);
          }
        }
      }
      sub_FD21F0(&a2a);
    }
    RegCloseKey(hKey);
  }
  free(ppv3);
  free(v49);
  free(v55);
  free(v56.m_String);
  return a4;
}

//----- (00FD9AB0) --------------------------------------------------------
void __cdecl PE_LoadAutorunsDisabledFlags(DWORD dwValue, HKEY hKey, LPCWSTR lpszKeyName, bool bFlags1, bool bFlags2)
{
  _WORD *v5; // ST68_4
  CPEString *v6; // esi
  void *Handle; // edi
  CPEString *v8; // eax
  wchar_t *v9; // ST6C_4

  v5 = malloc(2u);
  *v5 = 0;
  v6 = lpszKeyName;
  Handle = sub_FD9B70(dwValue, hKey, *lpszKeyName, bFlags1, bFlags2, 0xFFFFFFFF, 1, 1);
  v8 = CPEString::Append(&lpszKeyName, v6, L"\\AutorunsDisabled");
  v9 = _wcsdup(v8->m_String);
  free(v5);
  free(lpszKeyName);
  sub_FD9B70(dwValue, hKey, v9, bFlags1, bFlags2, Handle, 0, 1);
  free(v9);
}

//----- (00FD9B70) --------------------------------------------------------
void *__cdecl sub_FD9B70(DWORD dwValue, HKEY hKey, LPCWSTR lpszKeyName, bool bFlags1, bool bFlags2, HANDLE handle, bool bFags3, bool bFlags4)
{
  wchar_t *v8; // edi
  const WCHAR *v9; // esi
  const wchar_t *v10; // eax
  wchar_t *v11; // eax
  wchar_t *v12; // ebx
  wchar_t *v13; // eax
  wchar_t *v14; // edi
  const wchar_t *v15; // eax
  wchar_t *v16; // esi
  CPEString *v17; // eax
  unsigned int v18; // eax
  WCHAR *v19; // ebx
  _WORD *v20; // esi
  const wchar_t *v21; // edx
  __int16 *v22; // ecx
  __int16 v23; // ax
  WCHAR *v24; // esi
  CPEString *v25; // eax
  CPEString *v26; // eax
  WCHAR *v27; // esi
  CPEString *v28; // eax
  wchar_t *v29; // esi
  const WCHAR *v30; // edi
  unsigned int v31; // eax
  WCHAR *v32; // esi
  void (__stdcall *v33)(HKEY); // edi
  CPEString *v34; // eax
  CPEString *v35; // eax
  WCHAR *v36; // edi
  CPEString *v37; // eax
  const WCHAR *v38; // esi
  unsigned int v39; // eax
  int v40; // eax
  WCHAR *v41; // esi
  WCHAR *v42; // esi
  unsigned int v43; // eax
  int v44; // eax
  WCHAR *v45; // esi
  WCHAR *v46; // ebx
  const wchar_t **v47; // eax
  WCHAR *v48; // esi
  const wchar_t **v49; // eax
  WCHAR *v50; // esi
  CPEString *v51; // eax
  CPEString *v52; // eax
  WCHAR *v53; // esi
  CPEString *v54; // eax
  wchar_t *v55; // esi
  const WCHAR *v56; // esi
  unsigned int v57; // eax
  const wchar_t **v58; // eax
  CPEString *v59; // eax
  CPEString *v60; // eax
  wchar_t *v61; // esi
  const wchar_t **v62; // eax
  const wchar_t **v63; // eax
  void *v64; // esi
  const wchar_t **v65; // eax
  wchar_t *v66; // eax
  const wchar_t *v67; // eax
  wchar_t *v68; // eax
  wchar_t *v69; // ebx
  wchar_t *v70; // eax
  wchar_t *v71; // edi
  const wchar_t *v72; // eax
  wchar_t *v73; // esi
  CPEString *v74; // eax
  const wchar_t *v75; // eax
  wchar_t *v76; // eax
  wchar_t *v77; // ebx
  wchar_t *v78; // eax
  wchar_t *v79; // edi
  const wchar_t *v80; // eax
  wchar_t *v81; // esi
  CPEString *v82; // eax
  const wchar_t *v83; // eax
  wchar_t *v84; // esi
  CPEString *v85; // eax
  WCHAR v87[2]; // [esp+10h] [ebp-108h]
  int v88; // [esp+14h] [ebp-104h]
  int v89; // [esp+18h] [ebp-100h]
  int v90; // [esp+1Ch] [ebp-FCh]
  void *v91; // [esp+20h] [ebp-F8h]
  int a2a; // [esp+24h] [ebp-F4h]
  int v93; // [esp+28h] [ebp-F0h]
  int v94; // [esp+2Ch] [ebp-ECh]
  int v95; // [esp+30h] [ebp-E8h]
  CPEString v96; // [esp+34h] [ebp-E4h]
  WCHAR *ppv; // [esp+38h] [ebp-E0h]
  void *v98; // [esp+3Ch] [ebp-DCh]
  WCHAR v99[2]; // [esp+40h] [ebp-D8h]
  CPEString v100; // [esp+44h] [ebp-D4h]
  int v101; // [esp+48h] [ebp-D0h]
  CPEString v102; // [esp+4Ch] [ebp-CCh]
  WCHAR v103[2]; // [esp+50h] [ebp-C8h]
  CPEString v104; // [esp+54h] [ebp-C4h]
  WCHAR v105[2]; // [esp+58h] [ebp-C0h]
  void *v106; // [esp+5Ch] [ebp-BCh]
  WCHAR *pszResult; // [esp+60h] [ebp-B8h]
  WCHAR *ppv1; // [esp+64h] [ebp-B4h]
  int a3; // [esp+68h] [ebp-B0h]
  CPEString v110; // [esp+6Ch] [ebp-ACh]
  int a4a; // [esp+70h] [ebp-A8h]
  CPEString v112; // [esp+74h] [ebp-A4h]
  WCHAR v113[2]; // [esp+78h] [ebp-A0h]
  void *v114; // [esp+7Ch] [ebp-9Ch]
  WCHAR v115[2]; // [esp+80h] [ebp-98h]
  CPEString v116; // [esp+84h] [ebp-94h]
  void *v117; // [esp+88h] [ebp-90h]
  CPEString str; // [esp+8Ch] [ebp-8Ch]
  void *v119; // [esp+90h] [ebp-88h]
  CPEString v120; // [esp+94h] [ebp-84h]
  WCHAR pszText2[2]; // [esp+98h] [ebp-80h]
  int v122; // [esp+9Ch] [ebp-7Ch]
  int v123; // [esp+A0h] [ebp-78h]
  int v124; // [esp+A4h] [ebp-74h]
  void *v125; // [esp+A8h] [ebp-70h]
  void *v126; // [esp+ACh] [ebp-6Ch]
  WCHAR *v127; // [esp+B0h] [ebp-68h]
  void *v128; // [esp+B4h] [ebp-64h]
  HKEY KeyHandle; // [esp+B8h] [ebp-60h]
  DWORD Type; // [esp+BCh] [ebp-5Ch]
  unsigned int v131; // [esp+C0h] [ebp-58h]
  CPEString *a1a; // [esp+C4h] [ebp-54h]
  DWORD dwIndex; // [esp+C8h] [ebp-50h]
  WCHAR szArg[2]; // [esp+CCh] [ebp-4Ch]
  LPCWSTR szKeyName; // [esp+D0h] [ebp-48h]
  WCHAR *ppv3; // [esp+D4h] [ebp-44h]
  LPCWSTR szArg4; // [esp+D8h] [ebp-40h]
  wchar_t *v138; // [esp+DCh] [ebp-3Ch]
  LPCWSTR szArg3; // [esp+E0h] [ebp-38h]
  CPEString v140; // [esp+E4h] [ebp-34h]
  LPCWSTR v141; // [esp+E8h] [ebp-30h]
  HKEY hKeya; // [esp+ECh] [ebp-2Ch]
  CPEString str1; // [esp+F0h] [ebp-28h]
  CPEString str3; // [esp+F4h] [ebp-24h]
  void *v145; // [esp+F8h] [ebp-20h]
  char v146; // [esp+FFh] [ebp-19h]
  wchar_t *ppszText2; // [esp+100h] [ebp-18h]
  HKEY__ v148; // [esp+104h] [ebp-14h]
  LPCWSTR lpszKeyNamea; // [esp+108h] [ebp-10h]
  int v150; // [esp+114h] [ebp-4h]

  v131 = 0;
  szArg3 = 0;
  v126 = malloc(2u);
  *v126 = 0;
  v150 = 0;
  v128 = malloc(2u);
  *v128 = 0;
  v125 = malloc(2u);
  *v125 = 0;
  v127 = malloc(2u);
  *v127 = 0;
  v8 = malloc(2u);
  v138 = v8;
  *v8 = 0;
  v9 = lpszKeyName;
  LOBYTE(v150) = 4;
  if ( handle == -1 )
  {
    v145 = _wcsdup(&gszNullString);
    str1.m_String = _wcsdup(&gszNullString);
    str3.m_String = _wcsdup(&gszNullString);
    v140.m_String = _wcsdup(&gszNullString);
    v141 = _wcsdup(&gszNullString);
    ppv3 = _wcsdup(&gszNullString);
    dwIndex = _wcsdup(&gszNullString);
    v10 = &gszNullString;
    if ( lpszKeyName )
      v10 = lpszKeyName;
    v11 = _wcsdup(v10);
    v12 = v11;
    handle = v11;
    v13 = _wcsdup(&gszNullString);
    v14 = v13;
    Type = v13;
    v15 = &gszNullString;
    if ( lpszKeyName )
      v15 = lpszKeyName;
    v16 = _wcsdup(v15);
    szArg3 = v16;
    szArg4 = MakeRegistryKeyName(&a1a, hKey, &handle, &dwIndex);
    v17 = MakeRegistryKeyName(szArg, hKey, &szArg3, &Type);
    LOBYTE(v150) = 16;
    handle = sub_FD3FF0(dwValue, 0, 0xFFFFFFFF, 0, v17, szArg4, &ppv3);
    free(*szArg);
    free(a1a);
    free(v16);
    free(v14);
    free(v12);
    free(dwIndex);
    free(ppv3);
    free(v141);
    free(v140.m_String);
    free(str3.m_String);
    free(str1.m_String);
    LOBYTE(v150) = 4;
    free(v145);
    v8 = v138;
    v9 = lpszKeyName;
  }
  v18 = TlsGetValue(gdwTlsIndex);
  if ( !PE_OpenKey(hKey, v9, 0, v18 | 0x20019, &KeyHandle) )
  {
    dwIndex = 0;
    v148.unused = malloc(2u);
    *v148.unused = 0;
    v141 = malloc(2u);
    str1.m_String = v141;
    *v141 = 0;
    ppszText2 = malloc(2u);
    *ppszText2 = 0;
    lpszKeyNamea = malloc(2u);
    *lpszKeyNamea = 0;
    v19 = malloc(2u);
    ppv3 = v19;
    *v19 = 0;
    v20 = malloc(2u);
    v145 = v20;
    v140.m_String = v20;
    *v20 = 0;
    LOBYTE(v150) = 22;
    if ( !PE_LoadRegValues(KeyHandle, 0, &v148, 0, &Type, &ppszText2) )
    {
      while ( Type == 1 || Type == 2 || Type == 7 || Type == 3 )
      {
        v21 = v148.unused;
        v22 = v148.unused;
        szArg4 = v148.unused;
        szArg3 = (v148.unused + 2);
        do
        {
          v23 = *v22;
          ++v22;
        }
        while ( v23 );
        if ( !((v22 - szArg3) >> 1) )
        {
          if ( !bFlags4 )
            break;
          v148.unused = _wcsdup(L"(Default)");
          free(szArg4);
          v21 = v148.unused;
        }
        v24 = _wcsdup(v21);
        str3.m_String = v24;
        str1.m_String = v24;
        free(v141);
        if ( bFlags2 )
        {
          v25 = operator+(&pszResult, L"CLSID\\", &v148);
          v26 = CPEString::Append(&ppv, v25, L"\\InprocServer32");
          v27 = lpszKeyNamea;
          lpszKeyNamea = _wcsdup(v26->m_String);
          free(v27);
          free(ppv);
          free(pszResult);
          v28 = operator+(&v120, L"HKCR\\CLSID\\", &v148);
          v29 = _wcsdup(v28->m_String);
          v138 = v29;
          free(v8);
          free(v120.m_String);
          v30 = lpszKeyNamea;
          v31 = TlsGetValue(gdwTlsIndex);
          if ( PE_OpenKey(HKEY_CLASSES_ROOT, v30, 0, v31 | 0x20019, &hKeya) )
          {
            v34 = operator+(&v96, L"CLSID\\", &v148);
            v35 = CPEString::Append(&str, v34, L"\\Shell\\Open\\Command");
            v36 = lpszKeyNamea;
            lpszKeyNamea = _wcsdup(v35->m_String);
            free(v36);
            free(str.m_String);
            free(v96.m_String);
            v37 = operator+(&v116, L"HKCR\\CLSID\\", &v148);
            v138 = _wcsdup(v37->m_String);
            free(v29);
            free(v116.m_String);
            v38 = lpszKeyNamea;
            v39 = TlsGetValue(gdwTlsIndex);
            v40 = PE_OpenKey(HKEY_CLASSES_ROOT, v38, 0, v39 | 0x20019, &hKeya);
            v41 = lpszKeyNamea;
            if ( v40 )
            {
              lpszKeyNamea = _wcsdup(&gszNullString);
              free(v41);
              v33 = RegCloseKey;
            }
            else
            {
              lpszKeyNamea = _wcsdup(&gszNullString);
              free(v41);
              PE_ReadRegKey(hKeya, &gszNullString, 0, 0, &lpszKeyNamea);
              v33 = RegCloseKey;
              RegCloseKey(hKeya);
            }
          }
          else
          {
            v32 = lpszKeyNamea;
            lpszKeyNamea = _wcsdup(&gszNullString);
            free(v32);
            PE_ReadRegKey(hKeya, &gszNullString, 0, 0, &lpszKeyNamea);
            v33 = RegCloseKey;
            RegCloseKey(hKeya);
          }
          if ( wcslen(ppszText2)
            || (v42 = operator+(&v104, L"CLSID\\", &v148)->m_String,
                LOBYTE(v150) = 23,
                v131 |= 1u,
                szArg3 = v131,
                v43 = TlsGetValue(gdwTlsIndex),
                v44 = PE_OpenKey(HKEY_CLASSES_ROOT, v42, 0, v43 | 0x20019, &hKeya),
                v146 = 1,
                v44) )
          {
            v146 = 0;
          }
          v150 = 22;
          if ( v131 & 1 )
          {
            v131 &= 0xFFFFFFFE;
            free(v104.m_String);
          }
          if ( v146 )
          {
            PE_ReadRegKey(hKeya, &gszNullString, 0, 0, &ppszText2);
            v33(hKeya);
          }
          a2a = malloc(2u);
          v93 = 0;
          v94 = 0;
          *a2a = 0;
          v95 = 0;
          LOBYTE(v150) = 24;
          if ( sub_FD6CC0(lpszKeyNamea, &a2a) )
          {
            v45 = str3.m_String;
            v46 = _wcsdup(ppszText2);
            str1.m_String = v46;
            free(v45);
            v47 = sub_FD4890(&v114, lpszKeyNamea);
            v48 = lpszKeyNamea;
            lpszKeyNamea = _wcsdup(*v47);
            free(v48);
            free(v114);
            v49 = sub_FD4EE0(&v98, dwValue, &a2a, 0);
            v50 = _wcsdup(*v49);
            v140.m_String = v50;
            free(v145);
            free(v98);
            sub_FD21F0(&a2a);
            goto LABEL_46;
          }
          sub_FD21F0(&a2a);
          free(v145);
          free(v19);
          free(lpszKeyNamea);
          free(ppszText2);
          free(str3.m_String);
LABEL_66:
          free(v148.unused);
          v8 = v138;
          goto LABEL_67;
        }
        if ( bFlags1 )
        {
          *v87 = malloc(2u);
          v88 = 0;
          v89 = 0;
          **v87 = 0;
          v90 = 0;
          LOBYTE(v150) = 26;
          if ( sub_FD6CC0(ppszText2, v87) )
          {
            v138 = _wcsdup(ppszText2);
            free(v8);
            v63 = sub_FD4890(&v119, ppszText2);
            v64 = v126;
            v126 = _wcsdup(*v63);
            free(v64);
            free(v119);
            v65 = sub_FD4EE0(&v117, dwValue, v87, 0);
            v50 = _wcsdup(*v65);
            v140.m_String = v50;
            free(v145);
            free(v117);
            sub_FD21F0(v87);
LABEL_45:
            v46 = str3.m_String;
LABEL_46:
            if ( !wcslen(v46) && wcslen(v50) )
            {
              if ( wcsrchr(v50, 0x5Cu) )
              {
                v66 = wcsrchr(v50, 0x5Cu);
                str1.m_String = _wcsdup(v66 + 1);
                free(v46);
              }
              else
              {
                str1.m_String = _wcsdup(v50);
                free(v46);
              }
            }
            v67 = &gszNullString;
            if ( lpszKeyName )
              v67 = lpszKeyName;
            v68 = _wcsdup(v67);
            v69 = v68;
            szArg3 = v68;
            v70 = _wcsdup(&gszNullString);
            v71 = v70;
            szArg4 = v70;
            v72 = &gszNullString;
            if ( lpszKeyName )
              v72 = lpszKeyName;
            v73 = _wcsdup(v72);
            *szArg = v73;
            a1a = MakeRegistryKeyName(v113, hKey, &szArg3, &v148);
            v74 = MakeRegistryKeyName(v115, hKey, szArg, &szArg4);
            LOBYTE(v150) = 31;
            v146 = sub_FD3D40(dwValue, &str1, v74, a1a, &v140, &v128, &v127, &v101);
            free(*v115);
            free(*v113);
            free(v73);
            free(v71);
            free(v69);
            if ( v146 )
            {
              if ( handle == -1 )
              {
                szArg3 = _wcsdup(&gszNullString);
                szArg4 = _wcsdup(&gszNullString);
                *szArg = _wcsdup(&gszNullString);
                a1a = _wcsdup(&gszNullString);
                v145 = _wcsdup(&gszNullString);
                str3.m_String = _wcsdup(&gszNullString);
                v141 = _wcsdup(&gszNullString);
                v75 = &gszNullString;
                if ( lpszKeyName )
                  v75 = lpszKeyName;
                v76 = _wcsdup(v75);
                v77 = v76;
                handle = v76;
                v78 = _wcsdup(&gszNullString);
                v79 = v78;
                a4a = v78;
                v80 = &gszNullString;
                if ( lpszKeyName )
                  v80 = lpszKeyName;
                v81 = _wcsdup(v80);
                a3 = v81;
                szKeyName = MakeRegistryKeyName(v103, hKey, &handle, &v141);
                v82 = MakeRegistryKeyName(v105, hKey, &a3, &a4a);
                LOBYTE(v150) = 43;
                handle = sub_FD3FF0(dwValue, 0, 0xFFFFFFFF, 0, v82, szKeyName, &str3);
                free(*v105);
                free(*v103);
                free(v81);
                free(v79);
                free(v77);
                free(v141);
                free(str3.m_String);
                free(v145);
                free(a1a);
                free(*szArg);
                free(szArg4);
                free(szArg3);
              }
              v83 = &gszNullString;
              if ( lpszKeyName )
                v83 = lpszKeyName;
              v84 = _wcsdup(v83);
              szKeyName = v84;
              v85 = MakeRegistryKeyName(v99, hKey, &szKeyName, &v148);
              LOBYTE(v150) = 45;
              sub_FD3FF0(dwValue, 0xFFFFFFFF, handle, 1u, &str1, v85, &v140);
              free(*v99);
              free(v84);
            }
            free(v140.m_String);
            free(ppv3);
            free(lpszKeyNamea);
            free(ppszText2);
            free(str1.m_String);
            goto LABEL_66;
          }
          sub_FD21F0(v87);
          free(v145);
          free(v19);
          free(lpszKeyNamea);
          free(ppszText2);
          free(v24);
          free(v148.unused);
        }
        else
        {
          v51 = operator+(&v102, L"CLSID\\", &ppszText2);
          v52 = CPEString::Append(&v112, v51, L"\\InprocServer32");
          v53 = lpszKeyNamea;
          lpszKeyNamea = _wcsdup(v52->m_String);
          free(v53);
          free(v112.m_String);
          free(v102.m_String);
          v54 = operator+(&v110, L"HKCR\\CLSID\\", &ppszText2);
          v55 = v8;
          v8 = _wcsdup(v54->m_String);
          v138 = v8;
          free(v55);
          free(v110.m_String);
          v56 = lpszKeyNamea;
          v57 = TlsGetValue(gdwTlsIndex);
          if ( !PE_OpenKey(HKEY_CLASSES_ROOT, v56, 0, v57 | 0x20019, &hKeya)
            && !PE_ReadRegKey(hKeya, &gszNullString, 0, 0, &lpszKeyNamea) )
          {
            *pszText2 = malloc(2u);
            v122 = 0;
            v123 = 0;
            **pszText2 = 0;
            v124 = 0;
            LOBYTE(v150) = 25;
            if ( sub_FD6CC0(lpszKeyNamea, pszText2) )
            {
              v58 = sub_FD4EE0(&v91, dwValue, pszText2, 0);
              ppv3 = _wcsdup(*v58);
              free(v19);
              free(v91);
              v59 = CPEString::Append(&v100, &v148, L" -> ");
              v60 = CPEString::Append(&ppv1, v59, &ppv3);
              v61 = ppszText2;
              ppszText2 = _wcsdup(v60->m_String);
              free(v61);
              free(ppv1);
              free(v100.m_String);
              v62 = sub_FD4EE0(&v106, dwValue, pszText2, 0);
              v50 = _wcsdup(*v62);
              v140.m_String = v50;
              free(v145);
              free(v106);
              sub_FD21F0(pszText2);
              RegCloseKey(hKeya);
              goto LABEL_45;
            }
            sub_FD21F0(pszText2);
          }
          free(v145);
          free(v19);
          free(lpszKeyNamea);
          free(ppszText2);
          free(str3.m_String);
          free(v148.unused);
        }
LABEL_67:
        ++dwIndex;
        v148.unused = malloc(2u);
        *v148.unused = 0;
        v141 = malloc(2u);
        str1.m_String = v141;
        *v141 = 0;
        ppszText2 = malloc(2u);
        *ppszText2 = 0;
        lpszKeyNamea = malloc(2u);
        *lpszKeyNamea = 0;
        v19 = malloc(2u);
        ppv3 = v19;
        *v19 = 0;
        v20 = malloc(2u);
        v145 = v20;
        v140.m_String = v20;
        *v20 = 0;
        LOBYTE(v150) = 22;
        if ( PE_LoadRegValues(KeyHandle, dwIndex, &v148, 0, &Type, &ppszText2) )
          goto LABEL_68;
      }
      free(v20);
      free(v19);
      free(lpszKeyNamea);
      free(ppszText2);
      free(v141);
      free(v148.unused);
      goto LABEL_67;
    }
LABEL_68:
    free(v20);
    free(v19);
    free(lpszKeyNamea);
    free(ppszText2);
    free(v141);
    free(v148.unused);
    RegCloseKey(KeyHandle);
  }
  free(v8);
  free(v127);
  free(v125);
  free(v128);
  free(v126);
  return handle;
}

//----- (00FDAA30) --------------------------------------------------------
void __cdecl PE_UpdateRegistryEx(int a1, void *a2, wchar_t *psz, LPCWSTR lpValueName, int a5)
{
  wchar_t *v5; // esi
  void *v6; // eax
  const WCHAR **v7; // ecx
  void *v8; // ebx
  wchar_t *v9; // edi
  CPEString *v10; // eax
  wchar_t *v11; // esi
  WCHAR *ppv; // [esp+10h] [ebp-18h]
  void *v13; // [esp+14h] [ebp-14h]
  void *v14; // [esp+18h] [ebp-10h]
  int v15; // [esp+24h] [ebp-4h]

  v13 = malloc(2u);
  v14 = v13;
  *v13 = 0;
  v5 = psz;
  v15 = 0;
  v6 = sub_FDAB10(a1, a2, psz, lpValueName, a5, 0xFFFFFFFF);
  v7 = &gszNullString;
  v8 = v6;
  if ( v5 )
    v7 = v5;
  v9 = _wcsdup(v7);
  psz = v9;
  v10 = CPEString::Append(&ppv, &psz, L"\\AutorunsDisabled");
  v11 = _wcsdup(v10->m_String);
  v14 = v11;
  free(v13);
  free(ppv);
  free(v9);
  sub_FDAB10(a1, a2, v11, lpValueName, a5, v8);
  free(v11);
}

//----- (00FDAB10) --------------------------------------------------------
void *__cdecl sub_FDAB10(int a1, void *a2, wchar_t *psz, LPCWSTR lpValueName, int a5, void *a6)
{
  _WORD *v6; // edi
  const WCHAR *v7; // esi
  wchar_t *v8; // ebx
  const wchar_t *v9; // eax
  wchar_t *v10; // eax
  wchar_t *v11; // ebx
  const wchar_t *v12; // eax
  wchar_t *v13; // eax
  wchar_t *v14; // edi
  const wchar_t *v15; // eax
  wchar_t *v16; // esi
  CPEString *v17; // eax
  unsigned int v18; // eax
  LPCWSTR v19; // edx
  WCHAR v20; // cx
  int v21; // edx
  void *v22; // ecx
  const wchar_t ***v23; // edi
  _WORD *v24; // eax
  const wchar_t **v25; // eax
  const wchar_t **v26; // eax
  const WCHAR **v27; // eax
  const WCHAR **v28; // eax
  wchar_t *v29; // eax
  wchar_t *v30; // ebx
  const WCHAR **v31; // eax
  wchar_t *v32; // eax
  wchar_t *v33; // edi
  const wchar_t *v34; // eax
  wchar_t *v35; // esi
  CPEString *v36; // eax
  const wchar_t *v37; // eax
  wchar_t *v38; // eax
  wchar_t *v39; // ebx
  const wchar_t *v40; // eax
  wchar_t *v41; // eax
  wchar_t *v42; // edi
  const wchar_t *v43; // eax
  wchar_t *v44; // esi
  CPEString *v45; // eax
  const wchar_t *v46; // eax
  wchar_t *v47; // eax
  wchar_t *v48; // ebx
  const wchar_t *v49; // eax
  wchar_t *v50; // eax
  wchar_t *v51; // edi
  const wchar_t *v52; // eax
  wchar_t *v53; // esi
  CPEString *v54; // eax
  bool v55; // zf
  int a2a; // [esp+10h] [ebp-94h]
  int v58; // [esp+14h] [ebp-90h]
  int v59; // [esp+18h] [ebp-8Ch]
  int v60; // [esp+1Ch] [ebp-88h]
  int v61; // [esp+20h] [ebp-84h]
  WCHAR v62[2]; // [esp+24h] [ebp-80h]
  WCHAR v63[2]; // [esp+28h] [ebp-7Ch]
  WCHAR v64[2]; // [esp+2Ch] [ebp-78h]
  WCHAR v65[2]; // [esp+30h] [ebp-74h]
  WCHAR v66[2]; // [esp+34h] [ebp-70h]
  void *v67; // [esp+38h] [ebp-6Ch]
  int v68; // [esp+3Ch] [ebp-68h]
  int v69; // [esp+40h] [ebp-64h]
  HKEY hKey; // [esp+44h] [ebp-60h]
  void *v71; // [esp+48h] [ebp-5Ch]
  void *v72; // [esp+4Ch] [ebp-58h]
  WCHAR *v73; // [esp+50h] [ebp-54h]
  int a4; // [esp+54h] [ebp-50h]
  int a3; // [esp+58h] [ebp-4Ch]
  CPEString str3; // [esp+5Ch] [ebp-48h]
  void *a1a; // [esp+60h] [ebp-44h]
  int a7; // [esp+64h] [ebp-40h]
  void *v79; // [esp+68h] [ebp-3Ch]
  void *v80; // [esp+6Ch] [ebp-38h]
  void *v81; // [esp+70h] [ebp-34h]
  WCHAR *ppv3; // [esp+74h] [ebp-30h]
  CPEString *str2; // [esp+78h] [ebp-2Ch]
  LPCWSTR pszValue; // [esp+7Ch] [ebp-28h]
  LPCWSTR szKeyName; // [esp+80h] [ebp-24h]
  LPCWSTR szArg3; // [esp+84h] [ebp-20h]
  WCHAR szArg[2]; // [esp+88h] [ebp-1Ch]
  void *v88; // [esp+8Ch] [ebp-18h]
  LPCWSTR szArg4; // [esp+90h] [ebp-14h]
  char v90; // [esp+97h] [ebp-Dh]
  int v91; // [esp+A0h] [ebp-4h]

  str2 = malloc(2u);
  a7 = str2;
  LOWORD(str2->m_String) = 0;
  v91 = 0;
  v6 = malloc(2u);
  v81 = v6;
  ppv3 = v6;
  *v6 = 0;
  v72 = malloc(2u);
  *v72 = 0;
  v71 = malloc(2u);
  *v71 = 0;
  v73 = malloc(2u);
  *v73 = 0;
  v7 = lpValueName;
  v8 = psz;
  LOBYTE(v91) = 4;
  if ( a6 == -1 )
  {
    szArg4 = _wcsdup(&gszNullString);
    szArg3 = _wcsdup(&gszNullString);
    v88 = _wcsdup(&gszNullString);
    v79 = _wcsdup(&gszNullString);
    v80 = _wcsdup(&gszNullString);
    str3.m_String = _wcsdup(&gszNullString);
    pszValue = _wcsdup(&gszNullString);
    v9 = &gszNullString;
    if ( psz )
      v9 = psz;
    v10 = _wcsdup(v9);
    v11 = v10;
    a6 = v10;
    v12 = &gszNullString;
    if ( lpValueName )
      v12 = lpValueName;
    v13 = _wcsdup(v12);
    v14 = v13;
    a4 = v13;
    v15 = &gszNullString;
    if ( psz )
      v15 = psz;
    v16 = _wcsdup(v15);
    a3 = v16;
    szKeyName = MakeRegistryKeyName(&a1a, a2, &a6, &pszValue);
    v17 = MakeRegistryKeyName(szArg, a2, &a3, &a4);
    LOBYTE(v91) = 16;
    a6 = sub_FD3FF0(a1, 0, 0xFFFFFFFF, 0, v17, szKeyName, &str3);
    free(*szArg);
    free(a1a);
    free(v16);
    free(v14);
    free(v11);
    free(pszValue);
    free(str3.m_String);
    free(v80);
    free(v79);
    free(v88);
    free(szArg3);
    LOBYTE(v91) = 4;
    free(szArg4);
    v7 = lpValueName;
    v8 = psz;
    v6 = v81;
  }
  v18 = TlsGetValue(gdwTlsIndex);
  if ( !PE_OpenKey(a2, v8, 0, v18 | 0x20019, &hKey) )
  {
    pszValue = malloc(2u);
    *pszValue = 0;
    LOBYTE(v91) = 17;
    if ( !PE_ReadRegKey(hKey, v7, 0, 0, &pszValue) )
    {
      v19 = pszValue;
      a1a = (pszValue + 1);
      do
      {
        v20 = *v19;
        ++v19;
      }
      while ( v20 );
      if ( (v19 - a1a) >> 1 )
      {
        v67 = 0;
        v68 = 0;
        v69 = 0;
        LOBYTE(v91) = 18;
        sub_FD6DD0(pszValue, a5, &v67, 0);
        v21 = v68;
        v22 = v67;
        a4 = (v68 - v67) >> 4;
        if ( a4 )
        {
          v23 = (v67 + 4);
          a3 = v67 + 4;
          while ( 1 )
          {
            ppv3 = _wcsdup(**v23);
            free(v81);
            v24 = malloc(2u);
            a2a = v24;
            v58 = 0;
            v59 = 0;
            *v24 = 0;
            v60 = 0;
            v25 = *v23;
            LOBYTE(v91) = 19;
            sub_FD6CC0(*v25, &a2a);
            v26 = sub_FD4EE0(&a1a, a1, &a2a, 0);
            a7 = _wcsdup(*v26);
            free(str2);
            free(a1a);
            v27 = &gszNullString;
            if ( v7 )
              v27 = v7;
            szArg4 = _wcsdup(v27);
            v28 = &gszNullString;
            if ( v8 )
              v28 = v8;
            v29 = _wcsdup(v28);
            v30 = v29;
            *szArg = v29;
            v31 = &gszNullString;
            if ( v7 )
              v31 = v7;
            v32 = _wcsdup(v31);
            v33 = v32;
            szKeyName = v32;
            v34 = &gszNullString;
            if ( psz )
              v34 = psz;
            v35 = _wcsdup(v34);
            szArg3 = v35;
            v88 = MakeRegistryKeyName(v65, a2, szArg, &szArg4);
            v36 = MakeRegistryKeyName(v64, a2, &szArg3, &szKeyName);
            LOBYTE(v91) = 25;
            v90 = sub_FD3D40(a1, v36, v88, &ppv3, &a7, &v72, &v73, &v61);
            free(*v64);
            free(*v65);
            free(v35);
            free(v33);
            free(v30);
            free(szArg4);
            if ( v90 )
            {
              if ( a6 == -1 )
              {
                v81 = _wcsdup(&gszNullString);
                str3.m_String = _wcsdup(&gszNullString);
                v80 = _wcsdup(&gszNullString);
                v79 = _wcsdup(&gszNullString);
                v88 = _wcsdup(&gszNullString);
                szArg3 = _wcsdup(&gszNullString);
                szArg4 = _wcsdup(&gszNullString);
                v37 = &gszNullString;
                if ( psz )
                  v37 = psz;
                v38 = _wcsdup(v37);
                v39 = v38;
                a6 = v38;
                v40 = &gszNullString;
                if ( lpValueName )
                  v40 = lpValueName;
                v41 = _wcsdup(v40);
                v42 = v41;
                *szArg = v41;
                v43 = &gszNullString;
                if ( psz )
                  v43 = psz;
                v44 = _wcsdup(v43);
                szKeyName = v44;
                str2 = MakeRegistryKeyName(v63, a2, &a6, &szArg4);
                v45 = MakeRegistryKeyName(v62, a2, &szKeyName, szArg);
                LOBYTE(v91) = 37;
                a6 = sub_FD3FF0(a1, 0, 0xFFFFFFFF, 0, v45, str2, &szArg3);
                free(*v62);
                free(*v63);
                free(v44);
                free(v42);
                free(v39);
                free(szArg4);
                free(szArg3);
                free(v88);
                free(v79);
                free(v80);
                free(str3.m_String);
                free(v81);
              }
              v46 = &gszNullString;
              if ( lpValueName )
                v46 = lpValueName;
              v47 = _wcsdup(v46);
              v48 = v47;
              szArg4 = v47;
              v49 = &gszNullString;
              if ( lpValueName )
                v49 = lpValueName;
              v50 = _wcsdup(v49);
              v51 = v50;
              *szArg = v50;
              v52 = &gszNullString;
              if ( psz )
                v52 = psz;
              v53 = _wcsdup(v52);
              szKeyName = v53;
              v54 = MakeRegistryKeyName(v66, a2, &szKeyName, szArg);
              LOBYTE(v91) = 41;
              sub_FD3FF0(a1, 0xFFFFFFFF, a6, 1u, &ppv3, v54, &a7);
              free(*v66);
              free(v53);
              free(v51);
              free(v48);
            }
            LOBYTE(v91) = 18;
            sub_FD21F0(&a2a);
            v23 = (a3 + 16);
            v55 = a4-- == 1;
            a3 += 16;
            str2 = a7;
            if ( v55 )
              break;
            v7 = lpValueName;
            v8 = psz;
            v81 = ppv3;
          }
          v6 = ppv3;
          v22 = v67;
          v21 = v68;
        }
        if ( v22 )
        {
          sub_FD2BF0(v22, v21);
          j__free(v67);
        }
      }
    }
    RegCloseKey(hKey);
    free(pszValue);
  }
  free(v73);
  free(v71);
  free(v72);
  free(v6);
  free(str2);
  return a6;
}

//----- (00FDB220) --------------------------------------------------------
void __cdecl LoadServiceRegistry(DWORD dwType, DWORD dwFlags)
{
  DWORD dwFlagsIn; // edi
  unsigned __int8 (__stdcall *v3)(); // esi
  DWORD v4; // eax
  DWORD v5; // eax
  wchar_t *v6; // esi
  wchar_t *v7; // esi
  wchar_t *v8; // esi
  wchar_t *v9; // esi
  char v10; // al
  wchar_t *v11; // esi
  wchar_t *v12; // esi
  wchar_t *v13; // esi
  wchar_t *v14; // esi
  DWORD v15; // esi
  OLECHAR *v16; // eax
  OLECHAR *v17; // eax
  OLECHAR *v18; // eax
  OLECHAR *v19; // eax
  void *v20; // esi
  wchar_t *v21; // esi
  wchar_t *v22; // esi
  wchar_t *v23; // esi
  wchar_t *v24; // esi
  wchar_t *v25; // esi
  wchar_t *v26; // esi
  wchar_t *v27; // esi
  wchar_t *v28; // esi
  wchar_t *v29; // esi
  wchar_t *v30; // esi
  wchar_t *v31; // esi
  wchar_t *v32; // esi
  wchar_t *v33; // esi
  wchar_t *v34; // esi
  wchar_t *v35; // esi
  wchar_t *v36; // esi
  wchar_t *v37; // esi
  wchar_t *v38; // esi
  wchar_t *v39; // esi
  wchar_t *v40; // esi
  wchar_t *v41; // esi
  wchar_t *v42; // esi
  wchar_t *v43; // esi
  char v44; // al
  wchar_t *v45; // esi
  wchar_t *v46; // esi
  wchar_t *v47; // esi
  wchar_t *v48; // esi
  wchar_t *v49; // esi
  wchar_t *v50; // esi
  wchar_t *v51; // esi
  wchar_t *v52; // esi
  wchar_t *v53; // esi
  wchar_t *v54; // esi
  wchar_t *v55; // esi
  wchar_t *v56; // esi
  wchar_t *v57; // esi
  wchar_t *v58; // esi
  wchar_t *v59; // esi
  wchar_t *v60; // esi
  wchar_t *v61; // esi
  wchar_t *v62; // esi
  wchar_t *v63; // esi
  wchar_t *v64; // esi
  BYTE Data[4]; // [esp+10h] [ebp-1Ch]
  DWORD cbData; // [esp+14h] [ebp-18h]
  HKEY hKey; // [esp+18h] [ebp-14h]
  DWORD Type; // [esp+1Ch] [ebp-10h]
  int ret; // [esp+28h] [ebp-4h]

  dwFlagsIn = dwFlags;
  gdwFlagsInLoadServiceRegistry = dwFlags;
  SetErrorMode(1u);
  if ( Wow64EnableWow64FsRedirection )
  {
    Wow64EnableWow64FsRedirection(0);
    TlsSetValue(gdwTlsIndex, 0x100);
  }
  v3 = GetVersion;
  if ( dwType & 0x100 )
  {
    sdwFlagsInLoadServiceRegistry = 0x100;
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      PE_UpdateRegistry(0, ghLocalMachineKey, L"System\\CurrentControlSet\\Control\\Session Manager", L"BootExecute");
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      PE_UpdateRegistry(0, ghLocalMachineKey, L"System\\CurrentControlSet\\Control\\Session Manager", L"SetupExecute");
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      PE_UpdateRegistry(0, ghLocalMachineKey, L"System\\CurrentControlSet\\Control\\Session Manager", L"Execute");
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      PE_UpdateRegistry(
        0,
        ghLocalMachineKey,
        L"System\\CurrentControlSet\\Control\\Session Manager",
        L"S0InitialCommand");
    if ( GetVersion() >= 6u )
    {
      v4 = GetVersion();
      if ( BYTE1(v4) >= 1u && (dwFlagsIn == 2 || dwFlagsIn == 1) )
        PE_UpdateRegistryEx(
          0,
          ghLocalMachineKey,
          L"System\\CurrentControlSet\\Control",
          L"ServiceControlManagerExtension",
          32);
    }
  }
  v5 = dwType;
  if ( dwType & 0x40000 )
  {
    sdwFlagsInLoadServiceRegistry = 0x40000;
    sub_FED790(0);
    v5 = dwType;
  }
  if ( v5 & 0x80000 )
  {
    sdwFlagsInLoadServiceRegistry = 0x80000;
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      dwFlags = _wcsdup(L"Software\\Microsoft\\Office\\Outlook\\Addins");
      PE_RefreshRegistry(0, ghLocalMachineKey, &dwFlags);
      ret = -1;
      free(dwFlags);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      dwFlags = _wcsdup(L"Software\\Microsoft\\Office\\Outlook\\Addins");
      PE_RefreshRegistry(0, ghCurrentUserKey, &dwFlags);
      ret = -1;
      free(dwFlags);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      dwFlags = _wcsdup(L"Software\\Wow6432Node\\Microsoft\\Office\\Outlook\\Addins");
      PE_RefreshRegistry(0, ghLocalMachineKey, &dwFlags);
      ret = -1;
      free(dwFlags);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      dwFlags = _wcsdup(L"Software\\Wow6432Node\\Microsoft\\Office\\Outlook\\Addins");
      PE_RefreshRegistry(0, ghCurrentUserKey, &dwFlags);
      ret = -1;
      free(dwFlags);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      dwFlags = _wcsdup(L"Software\\Microsoft\\Office\\Excel\\Addins");
      PE_RefreshRegistry(0, ghLocalMachineKey, &dwFlags);
      ret = -1;
      free(dwFlags);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      dwFlags = _wcsdup(L"Software\\Microsoft\\Office\\Excel\\Addins");
      PE_RefreshRegistry(0, ghCurrentUserKey, &dwFlags);
      ret = -1;
      free(dwFlags);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      dwFlags = _wcsdup(L"Software\\Wow6432Node\\Microsoft\\Office\\Excel\\Addins");
      PE_RefreshRegistry(0, ghLocalMachineKey, &dwFlags);
      ret = -1;
      free(dwFlags);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      dwFlags = _wcsdup(L"Software\\Wow6432Node\\Microsoft\\Office\\Excel\\Addins");
      PE_RefreshRegistry(0, ghCurrentUserKey, &dwFlags);
      ret = -1;
      free(dwFlags);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      dwFlags = _wcsdup(L"Software\\Microsoft\\Office\\PowerPoint\\Addins");
      PE_RefreshRegistry(0, ghLocalMachineKey, &dwFlags);
      ret = -1;
      free(dwFlags);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      dwFlags = _wcsdup(L"Software\\Microsoft\\Office\\PowerPoint\\Addins");
      PE_RefreshRegistry(0, ghCurrentUserKey, &dwFlags);
      ret = -1;
      free(dwFlags);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      dwFlags = _wcsdup(L"Software\\Wow6432Node\\Microsoft\\Office\\PowerPoint\\Addins");
      PE_RefreshRegistry(0, ghLocalMachineKey, &dwFlags);
      ret = -1;
      free(dwFlags);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      dwFlags = _wcsdup(L"Software\\Wow6432Node\\Microsoft\\Office\\PowerPoint\\Addins");
      PE_RefreshRegistry(0, ghCurrentUserKey, &dwFlags);
      ret = -1;
      free(dwFlags);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      dwFlags = _wcsdup(L"Software\\Microsoft\\Office\\Word\\Addins");
      PE_RefreshRegistry(0, ghLocalMachineKey, &dwFlags);
      ret = -1;
      free(dwFlags);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      dwFlags = _wcsdup(L"Software\\Microsoft\\Office\\Word\\Addins");
      PE_RefreshRegistry(0, ghCurrentUserKey, &dwFlags);
      ret = -1;
      free(dwFlags);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      dwFlags = _wcsdup(L"Software\\Wow6432Node\\Microsoft\\Office\\Word\\Addins");
      PE_RefreshRegistry(0, ghLocalMachineKey, &dwFlags);
      ret = -1;
      free(dwFlags);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      dwFlags = _wcsdup(L"Software\\Wow6432Node\\Microsoft\\Office\\Word\\Addins");
      PE_RefreshRegistry(0, ghCurrentUserKey, &dwFlags);
      ret = -1;
      free(dwFlags);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      dwFlags = _wcsdup(L"Software\\Microsoft\\Office\\Access\\Addins");
      PE_RefreshRegistry(0, ghLocalMachineKey, &dwFlags);
      ret = -1;
      free(dwFlags);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      dwFlags = _wcsdup(L"Software\\Microsoft\\Office\\Access\\Addins");
      PE_RefreshRegistry(0, ghCurrentUserKey, &dwFlags);
      ret = -1;
      free(dwFlags);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      dwFlags = _wcsdup(L"Software\\Wow6432Node\\Microsoft\\Office\\Access\\Addins");
      PE_RefreshRegistry(0, ghLocalMachineKey, &dwFlags);
      ret = -1;
      free(dwFlags);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      dwFlags = _wcsdup(L"Software\\Wow6432Node\\Microsoft\\Office\\Access\\Addins");
      PE_RefreshRegistry(0, ghCurrentUserKey, &dwFlags);
      ret = -1;
      free(dwFlags);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    LOWORD(v5) = dwType;
  }
  if ( v5 & 0x200 )
  {
    sdwFlagsInLoadServiceRegistry = 512;
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      PE_RefreshRegistry_0(
        0,
        ghLocalMachineKey,
        L"Software\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options");
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      PE_RefreshRegistry_0(
        0,
        ghLocalMachineKey,
        L"Software\\Wow6432Node\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options");
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      PE_UpdateRegistryEx(0, ghLocalMachineKey, L"Software\\Microsoft\\Command Processor", L"Autorun", 44);
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      PE_UpdateRegistryEx(0, ghLocalMachineKey, L"Software\\Wow6432Node\\Microsoft\\Command Processor", L"Autorun", 44);
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
      PE_UpdateRegistryEx(0, ghCurrentUserKey, L"Software\\Microsoft\\Command Processor", L"Autorun", 44);
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      v6 = _wcsdup(L"SOFTWARE\\Classes\\Exefile\\Shell\\Open\\Command");
      dwFlags = v6;
      PE_RefreshRegistry2(0, ghCurrentUserKey, &dwFlags);
      ret = -1;
      free(v6);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      v7 = _wcsdup(L"SOFTWARE\\Classes\\Exefile\\Shell\\Open\\Command");
      dwFlags = v7;
      PE_RefreshRegistry2(0, ghLocalMachineKey, &dwFlags);
      ret = -1;
      free(v7);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      PE_UpdateRegistry2(0, ghLocalMachineKey, L"Software\\Classes\\.exe");
    if ( dwFlagsIn == 2 || !dwFlagsIn )
      PE_UpdateRegistry2(0, ghCurrentUserKey, L"Software\\Classes\\.exe");
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      PE_UpdateRegistry2(0, ghLocalMachineKey, L"Software\\Classes\\.cmd");
    if ( dwFlagsIn == 2 || !dwFlagsIn )
      PE_UpdateRegistry2(0, ghCurrentUserKey, L"Software\\Classes\\.cmd");
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      v8 = _wcsdup(L"SOFTWARE\\Classes\\Htmlfile\\Shell\\Open\\Command");
      dwFlags = v8;
      PE_RefreshRegistry2(0, ghCurrentUserKey, &dwFlags);
      ret = -1;
      free(v8);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      v9 = _wcsdup(L"SOFTWARE\\Classes\\Htmlfile\\Shell\\Open\\Command");
      dwFlags = v9;
      PE_RefreshRegistry2(0, ghLocalMachineKey, &dwFlags);
      ret = -1;
      free(v9);
    }
    LOWORD(v5) = dwType;
    v3 = GetVersion;
  }
  cbData = v5 & 0x1000;
  if ( v5 & 0x1000 )
  {
    sdwFlagsInLoadServiceRegistry = 4096;
    if ( v3() < 6u )
    {
      if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
        PE_UpdateRegistryEx(
          0,
          ghLocalMachineKey,
          L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon",
          L"ServiceControllerStart",
          32);
      if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
        PE_UpdateRegistryEx(
          0,
          ghLocalMachineKey,
          L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon",
          L"LsaStart",
          32);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      PE_UpdateRegistryEx(0, ghLocalMachineKey, L"SYSTEM\\Setup", L"CmdLine", 44);
  }
  v10 = dwType;
  if ( dwType & 0x20000 )
  {
    sdwFlagsInLoadServiceRegistry = 0x20000;
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      sub_FF5D10(0);
      v10 = dwType;
    }
  }
  if ( v10 & 0x20 )
  {
    sdwFlagsInLoadServiceRegistry = 32;
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      sub_FE9580(0, ghLocalMachineKey, L"System\\CurrentControlSet\\Services");
      v10 = dwType;
    }
  }
  if ( v10 & 0x40 )
  {
    sdwFlagsInLoadServiceRegistry = 64;
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      sub_FE1610(0, ghLocalMachineKey, L"System\\CurrentControlSet\\Services");
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      v11 = _wcsdup(L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Font Drivers");
      dwFlags = v11;
      PE_LoadAutorunsDisabledFlags(0, ghLocalMachineKey, &dwFlags, 1, 0);
      ret = -1;
      free(v11);
    }
  }
  if ( cbData )
  {
    sdwFlagsInLoadServiceRegistry = 4096;
    if ( GetVersion() < 6u )
    {
      if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
        PE_UpdateRegistryEx(
          0,
          ghLocalMachineKey,
          L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon",
          L"GinaDLL",
          44);
      if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
        PE_UpdateRegistryEx(
          0,
          ghLocalMachineKey,
          L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon",
          L"UIHost",
          44);
      if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
        PE_UpdateRegistryEx(
          0,
          ghLocalMachineKey,
          L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon",
          L"System",
          44);
      if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      {
        dwFlags = _wcsdup(L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon\\Notify");
        sub_FF2060(0, ghLocalMachineKey, &dwFlags);
        ret = -1;
        free(dwFlags);
      }
      if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
        PE_UpdateRegistryEx(
          0,
          ghLocalMachineKey,
          L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon",
          L"SaveDumpStart",
          32);
    }
    else
    {
      if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      {
        v12 = _wcsdup(L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Authentication\\Credential Providers");
        dwFlags = v12;
        sub_FD86F0(0, ghLocalMachineKey, &dwFlags);
        ret = -1;
        free(v12);
      }
      if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      {
        v13 = _wcsdup(L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Authentication\\Credential Provider Filters");
        dwFlags = v13;
        sub_FD86F0(0, ghLocalMachineKey, &dwFlags);
        ret = -1;
        free(v13);
      }
      if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      {
        v14 = _wcsdup(L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Authentication\\PLAP Providers");
        dwFlags = v14;
        sub_FD86F0(0, ghLocalMachineKey, &dwFlags);
        ret = -1;
        free(v14);
      }
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      PE_UpdateRegistryEx(
        0,
        ghLocalMachineKey,
        L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon",
        L"Taskman",
        32);
    if ( dwFlagsIn == 2 || !dwFlagsIn )
      PE_UpdateRegistryEx(
        0,
        ghCurrentUserKey,
        L"SOFTWARE\\Policies\\Microsoft\\Windows\\Control Panel\\Desktop",
        L"Scrnsave.exe",
        44);
    if ( dwFlagsIn == 2 || !dwFlagsIn )
      PE_UpdateRegistryEx(0, ghCurrentUserKey, L"Control Panel\\Desktop", L"Scrnsave.exe", 44);
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      PE_UpdateRegistryEx(
        0,
        ghLocalMachineKey,
        L"System\\CurrentControlSet\\Control\\BootVerificationProgram",
        L"ImagePath",
        44);
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      dwFlags = _wcsdup(L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon\\GpExtensions");
      sub_FF2060(0, ghLocalMachineKey, &dwFlags);
      ret = -1;
      free(dwFlags);
    }
  }
  v15 = dwType;
  if ( dwType & 0x4000 )
  {
    sdwFlagsInLoadServiceRegistry = 0x4000;
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      dwFlags = _wcsdup(L"SYSTEM\\CurrentControlSet\\Control\\Print\\Monitors");
      LoadPrintServiceDirectory(0, ghLocalMachineKey, &dwFlags, 1u);
      ret = -1;
      free(dwFlags);
    }
  }
  if ( v15 & 0x8000 )
  {
    sdwFlagsInLoadServiceRegistry = 0x8000;
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      PE_UpdateRegistryEx(
        0,
        ghLocalMachineKey,
        L"SYSTEM\\CurrentControlSet\\Control\\SecurityProviders",
        L"SecurityProviders",
        44);
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      sub_FE6E10(0, ghLocalMachineKey, L"SYSTEM\\CurrentControlSet\\Control\\Lsa", L"Authentication Packages");
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      sub_FE6E10(0, ghLocalMachineKey, L"SYSTEM\\CurrentControlSet\\Control\\Lsa", L"Notification Packages");
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      sub_FE6E10(0, ghLocalMachineKey, L"SYSTEM\\CurrentControlSet\\Control\\Lsa", L"Security Packages");
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      sub_FE6E10(0, ghLocalMachineKey, L"SYSTEM\\CurrentControlSet\\Control\\Lsa\\OSConfig", L"Security Packages");
  }
  if ( v15 & 0x10000 )
  {
    sdwFlagsInLoadServiceRegistry = 0x10000;
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      dwFlags = _wcsdup(L"SYSTEM\\CurrentControlSet\\Control\\NetworkProvider\\Order");
      sub_FE7710(0, ghLocalMachineKey, &dwFlags);
      ret = -1;
      free(dwFlags);
    }
  }
  if ( v15 & 0x2000 )
  {
    sdwFlagsInLoadServiceRegistry = 0x10000;
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      v16 = _wcsdup(L"System\\CurrentControlSet\\Services\\WinSock2\\Parameters\\Protocol_Catalog9\\Catalog_Entries");
      sub_FF3190(0, v16);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      v17 = _wcsdup(L"System\\CurrentControlSet\\Services\\WinSock2\\Parameters\\NameSpace_Catalog5\\Catalog_Entries");
      sub_FF27D0(0, v17);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      v18 = _wcsdup(L"System\\CurrentControlSet\\Services\\WinSock2\\Parameters\\Protocol_Catalog9\\Catalog_Entries64");
      sub_FF3190(0, v18);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      v19 = _wcsdup(L"System\\CurrentControlSet\\Services\\WinSock2\\Parameters\\NameSpace_Catalog5\\Catalog_Entries64");
      sub_FF27D0(0, v19);
    }
    LOBYTE(v15) = dwType;
  }
  v20 = (v15 & 2);
  dwFlags = v20;
  if ( v20 && IsWinServer(TlsSetValue, v20) )
  {
    sdwFlagsInLoadServiceRegistry = 2;
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      PE_UpdateRegistryEx(
        0,
        ghLocalMachineKey,
        L"System\\CurrentControlSet\\Control\\Terminal Server\\Wds\\rdpwd",
        L"StartupPrograms",
        44);
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      PE_UpdateRegistryEx(
        0,
        ghLocalMachineKey,
        L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon",
        L"AppSetup",
        44);
  }
  if ( v20 )
  {
    sdwFlagsInLoadServiceRegistry = 2;
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      Type = _wcsdup(L"Software\\Policies\\Microsoft\\Windows\\System\\Scripts\\Startup");
      ret = 32;
      sub_FE2060(0, ghLocalMachineKey, &Type);
      ret = -1;
      free(Type);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      Type = _wcsdup(L"Software\\Policies\\Microsoft\\Windows\\System\\Scripts\\Logon");
      ret = 33;
      sub_FE2060(0, ghCurrentUserKey, &Type);
      ret = -1;
      free(Type);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      Type = _wcsdup(L"Software\\Policies\\Microsoft\\Windows\\System\\Scripts\\Logon");
      ret = 34;
      sub_FE2060(0, ghLocalMachineKey, &Type);
      ret = -1;
      free(Type);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      PE_UpdateRegistryEx(
        0,
        ghLocalMachineKey,
        L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon",
        L"Userinit",
        44);
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      PE_UpdateRegistryEx(
        0,
        ghLocalMachineKey,
        L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon",
        L"VmApplet",
        0);
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      Type = _wcsdup(L"Software\\Policies\\Microsoft\\Windows\\System\\Scripts\\Shutdown");
      ret = 35;
      sub_FE2060(0, ghLocalMachineKey, &Type);
      ret = -1;
      free(Type);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      Type = _wcsdup(L"Software\\Policies\\Microsoft\\Windows\\System\\Scripts\\Logoff");
      ret = 36;
      sub_FE2060(0, ghCurrentUserKey, &Type);
      ret = -1;
      free(Type);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      Type = _wcsdup(L"Software\\Policies\\Microsoft\\Windows\\System\\Scripts\\Logoff");
      ret = 37;
      sub_FE2060(0, ghLocalMachineKey, &Type);
      ret = -1;
      free(Type);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      Type = _wcsdup(L"Software\\Microsoft\\Windows\\CurrentVersion\\Group Policy\\Scripts\\Startup");
      ret = 38;
      sub_FE2060(0, ghLocalMachineKey, &Type);
      ret = -1;
      free(Type);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      Type = _wcsdup(L"Software\\Microsoft\\Windows\\CurrentVersion\\Group Policy\\Scripts\\Shutdown");
      ret = 39;
      sub_FE2060(0, ghLocalMachineKey, &Type);
      ret = -1;
      free(Type);
    }
  }
  if ( dwType & 0x400 )
  {
    sdwFlagsInLoadServiceRegistry = 1024;
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      Type = _wcsdup(L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Windows");
      ret = 40;
      sub_FD2CB0(0, ghLocalMachineKey, &Type, L"Appinit_Dlls");
      ret = -1;
      free(Type);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      Type = _wcsdup(L"SOFTWARE\\Wow6432Node\\Microsoft\\Windows NT\\CurrentVersion\\Windows");
      ret = 41;
      sub_FD2CB0(0, ghLocalMachineKey, &Type, L"Appinit_Dlls");
      ret = -1;
      free(Type);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      v21 = _wcsdup(L"System\\CurrentControlSet\\Control\\Session Manager\\AppCertDlls");
      cbData = v21;
      ret = 42;
      PE_LoadAutorunsDisabledFlags(0, ghLocalMachineKey, &cbData, 1, 0);
      ret = -1;
      free(v21);
      v20 = dwFlags;
    }
  }
  if ( v20 )
  {
    sdwFlagsInLoadServiceRegistry = 2;
    if ( (GetVersion() & 0x80000000) != 0 )
    {
      if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      {
        v20 = _wcsdup(L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\RunServices");
        cbData = v20;
        ret = 43;
        PE_LoadAutorunsDisabledFlags(0, ghLocalMachineKey, &cbData, 1, 0);
        ret = -1;
        free(v20);
      }
      if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      {
        v20 = _wcsdup(L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\RunServicesOnce");
        cbData = v20;
        ret = 44;
        PE_LoadAutorunsDisabledFlags(0, ghLocalMachineKey, &cbData, 1, 0);
        ret = -1;
        free(v20);
      }
      if ( dwFlagsIn == 2 || !dwFlagsIn )
      {
        v20 = _wcsdup(L"Software\\Microsoft\\Windows\\CurrentVersion\\RunServices");
        cbData = v20;
        ret = 45;
        PE_LoadAutorunsDisabledFlags(0, ghCurrentUserKey, &cbData, 1, 0);
        ret = -1;
        free(v20);
      }
      if ( dwFlagsIn == 2 || !dwFlagsIn )
      {
        v20 = _wcsdup(L"Software\\Microsoft\\Windows\\CurrentVersion\\RunServicesOnce");
        cbData = v20;
        ret = 46;
        PE_LoadAutorunsDisabledFlags(0, ghCurrentUserKey, &cbData, 1, 0);
        ret = -1;
        free(v20);
      }
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
      PE_UpdateRegistryEx(
        0,
        ghCurrentUserKey,
        L"Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System",
        L"Shell",
        44);
    if ( dwFlagsIn == 2 || !dwFlagsIn )
      PE_UpdateRegistryEx(
        0,
        ghCurrentUserKey,
        L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon",
        L"Shell",
        44);
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      PE_UpdateRegistryEx(
        0,
        ghLocalMachineKey,
        L"Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System",
        L"Shell",
        44);
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      PE_UpdateRegistryEx(
        0,
        ghLocalMachineKey,
        L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon",
        L"Shell",
        44);
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      PE_UpdateRegistryEx(
        0,
        ghLocalMachineKey,
        L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon",
        L"Taskman",
        32);
    if ( !PE_OpenKey(ghLocalMachineKey, L"System\\CurrentControlSet\\Control\\SafeBoot\\Option", 0, 0x20019u, &hKey) )
    {
      cbData = 4;
      Type = 4;
      if ( !RegQueryValueExW(hKey, L"UseAlternateShell", 0, &Type, Data, &cbData) && (dwFlagsIn == 2 || dwFlagsIn == 1) )
        PE_UpdateRegistryEx(
          0,
          ghLocalMachineKey,
          L"System\\CurrentControlSet\\Control\\SafeBoot",
          L"AlternateShell",
          44);
      RegCloseKey(hKey);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      v20 = _wcsdup(L"Software\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon\\AlternateShells\\AvailableShells");
      cbData = v20;
      ret = 47;
      PE_LoadAutorunsDisabledFlags(0, ghLocalMachineKey, &cbData, 1, 0);
      ret = -1;
      free(v20);
    }
    if ( IsWinServer(TlsSetValue, v20) )
    {
      if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      {
        v22 = _wcsdup(
                L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Terminal Server\\Install\\Software\\Microsoft\\Windows\\"
                 "CurrentVersion\\Runonce");
        cbData = v22;
        ret = 48;
        PE_LoadAutorunsDisabledFlags(0, ghLocalMachineKey, &cbData, 1, 0);
        ret = -1;
        free(v22);
      }
      if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      {
        v23 = _wcsdup(
                L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Terminal Server\\Install\\Software\\Microsoft\\Windows\\"
                 "CurrentVersion\\RunonceEx");
        cbData = v23;
        ret = 49;
        sub_FDF2D0(0, ghLocalMachineKey, &cbData, 1, 0);
        ret = -1;
        free(v23);
      }
      if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      {
        v24 = _wcsdup(
                L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Terminal Server\\Install\\Software\\Microsoft\\Windows\\"
                 "CurrentVersion\\Run");
        cbData = v24;
        ret = 50;
        PE_LoadAutorunsDisabledFlags(0, ghLocalMachineKey, &cbData, 1, 0);
        ret = -1;
        free(v24);
      }
      if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
        PE_UpdateRegistryEx(
          0,
          ghLocalMachineKey,
          L"SYSTEM\\CurrentControlSet\\Control\\Terminal Server\\WinStations\\RDP-Tcp",
          L"InitialProgram",
          44);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      v25 = _wcsdup(L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run");
      cbData = v25;
      ret = 51;
      PE_LoadAutorunsDisabledFlags(0, ghLocalMachineKey, &cbData, 1, 0);
      ret = -1;
      free(v25);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      v26 = _wcsdup(L"SOFTWARE\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\Run");
      cbData = v26;
      ret = 52;
      PE_LoadAutorunsDisabledFlags(0, ghLocalMachineKey, &cbData, 1, 0);
      ret = -1;
      free(v26);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      v27 = _wcsdup(L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run");
      cbData = v27;
      ret = 53;
      PE_LoadAutorunsDisabledFlags(0, ghCurrentUserKey, &cbData, 1, 0);
      ret = -1;
      free(v27);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      v28 = _wcsdup(L"SOFTWARE\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\Run");
      cbData = v28;
      ret = 54;
      PE_LoadAutorunsDisabledFlags(0, ghCurrentUserKey, &cbData, 1, 0);
      ret = -1;
      free(v28);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      v29 = _wcsdup(L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\RunOnceEx");
      cbData = v29;
      ret = 55;
      sub_FDF2D0(0, ghLocalMachineKey, &cbData, 1, 0);
      ret = -1;
      free(v29);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      v30 = _wcsdup(L"SOFTWARE\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\RunOnceEx");
      cbData = v30;
      ret = 56;
      sub_FDF2D0(0, ghLocalMachineKey, &cbData, 1, 0);
      ret = -1;
      free(v30);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      v31 = _wcsdup(L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\RunOnceEx");
      cbData = v31;
      ret = 57;
      sub_FDF2D0(0, ghCurrentUserKey, &cbData, 1, 0);
      ret = -1;
      free(v31);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      v32 = _wcsdup(L"SOFTWARE\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\RunOnceEx");
      cbData = v32;
      ret = 58;
      sub_FDF2D0(0, ghCurrentUserKey, &cbData, 1, 0);
      ret = -1;
      free(v32);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      v33 = _wcsdup(L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\RunOnce");
      cbData = v33;
      ret = 59;
      PE_LoadAutorunsDisabledFlags(0, ghLocalMachineKey, &cbData, 1, 0);
      ret = -1;
      free(v33);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      v34 = _wcsdup(L"SOFTWARE\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\RunOnce");
      cbData = v34;
      ret = 60;
      PE_LoadAutorunsDisabledFlags(0, ghLocalMachineKey, &cbData, 1, 0);
      ret = -1;
      free(v34);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      v35 = _wcsdup(L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\RunOnce");
      cbData = v35;
      ret = 61;
      PE_LoadAutorunsDisabledFlags(0, ghCurrentUserKey, &cbData, 1, 0);
      ret = -1;
      free(v35);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      v36 = _wcsdup(L"SOFTWARE\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\RunOnce");
      cbData = v36;
      ret = 62;
      PE_LoadAutorunsDisabledFlags(0, ghCurrentUserKey, &cbData, 1, 0);
      ret = -1;
      free(v36);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    v20 = dwFlags;
  }
  cbData = dwType & 4;
  if ( dwType & 4 )
  {
    sdwFlagsInLoadServiceRegistry = 4;
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      Type = _wcsdup(L"SOFTWARE\\Classes\\Protocols\\Filter");
      ret = 63;
      sub_FE30B0(0, ghCurrentUserKey, &Type);
      ret = -1;
      free(Type);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      Type = _wcsdup(L"SOFTWARE\\Classes\\Protocols\\Filter");
      ret = 64;
      sub_FE30B0(0, ghLocalMachineKey, &Type);
      ret = -1;
      free(Type);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      Type = _wcsdup(L"SOFTWARE\\Classes\\Protocols\\Handler");
      ret = 65;
      sub_FE30B0(0, ghCurrentUserKey, &Type);
      ret = -1;
      free(Type);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      Type = _wcsdup(L"SOFTWARE\\Classes\\Protocols\\Handler");
      ret = 66;
      sub_FE30B0(0, ghLocalMachineKey, &Type);
      ret = -1;
      free(Type);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      Type = _wcsdup(L"SOFTWARE\\Microsoft\\Internet Explorer\\Desktop\\Components");
      ret = 67;
      sub_FE39D0(0, ghCurrentUserKey, &Type);
      ret = -1;
      free(Type);
    }
  }
  if ( v20 )
  {
    sdwFlagsInLoadServiceRegistry = 2;
    if ( dwFlagsIn == 2 || !dwFlagsIn )
      sub_FEEFA0(
        0,
        ghCurrentUserKey,
        L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Shell Folders",
        L"AltStartup");
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      sub_FEEFA0(
        0,
        ghLocalMachineKey,
        L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Shell Folders",
        L"Common AltStartup");
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      sub_FEEFA0(
        0,
        ghLocalMachineKey,
        L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Shell Folders",
        L"Common Startup");
    if ( dwFlagsIn == 2 || !dwFlagsIn )
      sub_FEEFA0(
        0,
        ghCurrentUserKey,
        L"Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Shell Folders",
        L"Startup");
    if ( dwFlagsIn == 2 || !dwFlagsIn )
      PE_UpdateRegistryEx(0, ghCurrentUserKey, L"Software\\Microsoft\\Windows NT\\CurrentVersion\\Windows", L"Load", 32);
    if ( dwFlagsIn == 2 || !dwFlagsIn )
      PE_UpdateRegistryEx(0, ghCurrentUserKey, L"Software\\Microsoft\\Windows NT\\CurrentVersion\\Windows", L"Run", 32);
    if ( (GetVersion() & 0x80000000) != 0 )
      sub_FF1840(0);
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      v20 = _wcsdup(L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer\\Run");
      Type = v20;
      ret = 68;
      PE_LoadAutorunsDisabledFlags(0, ghLocalMachineKey, &Type, 1, 0);
      ret = -1;
      free(v20);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      v20 = _wcsdup(L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer\\Run");
      Type = v20;
      ret = 69;
      PE_LoadAutorunsDisabledFlags(0, ghCurrentUserKey, &Type, 1, 0);
      ret = -1;
      free(v20);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      Type = _wcsdup(L"SOFTWARE\\Microsoft\\Active Setup\\Installed Components");
      ret = 70;
      sub_FD23D0(0, ghLocalMachineKey, &Type);
      ret = -1;
      free(Type);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      Type = _wcsdup(L"SOFTWARE\\Wow6432Node\\Microsoft\\Active Setup\\Installed Components");
      ret = 71;
      sub_FD23D0(0, ghLocalMachineKey, &Type);
      ret = -1;
      free(Type);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      PE_UpdateRegistryEx(
        0,
        ghLocalMachineKey,
        L"Software\\Microsoft\\Windows NT\\CurrentVersion\\Windows",
        L"IconServiceLib",
        44);
  }
  if ( cbData )
  {
    sdwFlagsInLoadServiceRegistry = 4;
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      v20 = _wcsdup(L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\SharedTaskScheduler");
      Type = v20;
      ret = 72;
      PE_LoadAutorunsDisabledFlags(0, ghLocalMachineKey, &Type, 0, 1);
      ret = -1;
      free(v20);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      v20 = _wcsdup(L"SOFTWARE\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\Explorer\\SharedTaskScheduler");
      Type = v20;
      ret = 73;
      PE_LoadAutorunsDisabledFlags(0, ghLocalMachineKey, &Type, 0, 1);
      ret = -1;
      free(v20);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      v20 = _wcsdup(L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\ShellServiceObjects");
      Type = v20;
      ret = 74;
      sub_FD86F0(0, ghLocalMachineKey, &Type);
      ret = -1;
      free(v20);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      v20 = _wcsdup(L"SOFTWARE\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\Explorer\\ShellServiceObjects");
      Type = v20;
      ret = 75;
      sub_FD86F0(0, ghLocalMachineKey, &Type);
      ret = -1;
      free(v20);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      v20 = _wcsdup(L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\ShellServiceObjects");
      Type = v20;
      ret = 76;
      sub_FD86F0(0, ghCurrentUserKey, &Type);
      ret = -1;
      free(v20);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      v20 = _wcsdup(L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\ShellServiceObjectDelayLoad");
      Type = v20;
      ret = 77;
      PE_LoadAutorunsDisabledFlags(0, ghLocalMachineKey, &Type, 0, 0);
      ret = -1;
      free(v20);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      v20 = _wcsdup(L"SOFTWARE\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\ShellServiceObjectDelayLoad");
      Type = v20;
      ret = 78;
      PE_LoadAutorunsDisabledFlags(0, ghLocalMachineKey, &Type, 0, 0);
      ret = -1;
      free(v20);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      v20 = _wcsdup(L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\ShellServiceObjectDelayLoad");
      Type = v20;
      ret = 79;
      PE_LoadAutorunsDisabledFlags(0, ghCurrentUserKey, &Type, 0, 0);
      ret = -1;
      free(v20);
    }
  }
  if ( dwFlags )
  {
    sdwFlagsInLoadServiceRegistry = 2;
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      v20 = _wcsdup(L"Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer\\Run");
      Type = v20;
      ret = 80;
      PE_LoadAutorunsDisabledFlags(0, ghCurrentUserKey, &Type, 1, 0);
      ret = -1;
      free(v20);
    }
    if ( IsWinServer(TlsSetValue, v20) )
    {
      if ( dwFlagsIn == 2 || !dwFlagsIn )
      {
        v37 = _wcsdup(
                L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Terminal Server\\Install\\Software\\Microsoft\\Windows\\"
                 "CurrentVersion\\Runonce");
        Type = v37;
        ret = 81;
        PE_LoadAutorunsDisabledFlags(0, ghCurrentUserKey, &Type, 1, 0);
        ret = -1;
        free(v37);
      }
      if ( dwFlagsIn == 2 || !dwFlagsIn )
      {
        v38 = _wcsdup(
                L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Terminal Server\\Install\\Software\\Microsoft\\Windows\\"
                 "CurrentVersion\\RunonceEx");
        Type = v38;
        ret = 82;
        sub_FDF2D0(0, ghCurrentUserKey, &Type, 1, 0);
        ret = -1;
        free(v38);
      }
      if ( dwFlagsIn == 2 || !dwFlagsIn )
      {
        v39 = _wcsdup(
                L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Terminal Server\\Install\\Software\\Microsoft\\Windows\\"
                 "CurrentVersion\\Run");
        Type = v39;
        ret = 83;
        PE_LoadAutorunsDisabledFlags(0, ghCurrentUserKey, &Type, 1, 0);
        ret = -1;
        free(v39);
      }
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      v40 = _wcsdup(L"SOFTWARE\\Microsoft\\Windows CE Services\\AutoStartOnConnect");
      Type = v40;
      ret = 84;
      PE_LoadAutorunsDisabledFlags(0, ghLocalMachineKey, &Type, 1, 0);
      ret = -1;
      free(v40);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      v41 = _wcsdup(L"SOFTWARE\\Wow6432Node\\Microsoft\\Windows CE Services\\AutoStartOnConnect");
      Type = v41;
      ret = 85;
      PE_LoadAutorunsDisabledFlags(0, ghLocalMachineKey, &Type, 1, 0);
      ret = -1;
      free(v41);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      v42 = _wcsdup(L"SOFTWARE\\Microsoft\\Windows CE Services\\AutoStartOnDisconnect");
      Type = v42;
      ret = 86;
      PE_LoadAutorunsDisabledFlags(0, ghLocalMachineKey, &Type, 1, 0);
      ret = -1;
      free(v42);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      v43 = _wcsdup(L"SOFTWARE\\Wow6432Node\\Microsoft\\Windows CE Services\\AutoStartOnDisconnect");
      Type = v43;
      ret = 87;
      PE_LoadAutorunsDisabledFlags(0, ghLocalMachineKey, &Type, 1, 0);
      ret = -1;
      free(v43);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
  }
  v44 = dwType;
  if ( dwType & 0x10 )
  {
    sdwFlagsInLoadServiceRegistry = 16;
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      sub_FF0760(0);
      v44 = dwType;
    }
  }
  *Data = v44 & 8;
  if ( v44 & 8 )
  {
    sdwFlagsInLoadServiceRegistry = 8;
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      v45 = _wcsdup(L"Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Browser Helper Objects");
      Type = v45;
      ret = 88;
      sub_FD86F0(0, ghLocalMachineKey, &Type);
      ret = -1;
      free(v45);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      v46 = _wcsdup(L"Software\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Browser Helper Objects");
      Type = v46;
      ret = 89;
      sub_FD86F0(0, ghLocalMachineKey, &Type);
      ret = -1;
      free(v46);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
  }
  if ( cbData )
  {
    sdwFlagsInLoadServiceRegistry = 4;
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      v47 = _wcsdup(L"Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\ShellExecuteHooks");
      cbData = v47;
      ret = 90;
      PE_LoadAutorunsDisabledFlags(0, ghLocalMachineKey, &cbData, 0, 1);
      ret = -1;
      free(v47);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      v48 = _wcsdup(L"Software\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\Explorer\\ShellExecuteHooks");
      cbData = v48;
      ret = 91;
      PE_LoadAutorunsDisabledFlags(0, ghLocalMachineKey, &cbData, 0, 1);
      ret = -1;
      free(v48);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      cbData = _wcsdup(L"Software\\Classes\\*\\ShellEx\\ContextMenuHandlers");
      ret = 92;
      sub_FEA070(0, ghCurrentUserKey, &cbData);
      ret = -1;
      free(cbData);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      cbData = _wcsdup(L"Software\\Classes\\*\\ShellEx\\ContextMenuHandlers");
      ret = 93;
      sub_FEA070(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free(cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      cbData = _wcsdup(L"Software\\Wow6432Node\\Classes\\*\\ShellEx\\ContextMenuHandlers");
      ret = 94;
      sub_FEA070(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free(cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      cbData = _wcsdup(L"Software\\Classes\\Drive\\ShellEx\\ContextMenuHandlers");
      ret = 95;
      sub_FEA070(0, ghCurrentUserKey, &cbData);
      ret = -1;
      free(cbData);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      cbData = _wcsdup(L"Software\\Classes\\Drive\\ShellEx\\ContextMenuHandlers");
      ret = 96;
      sub_FEA070(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free(cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      cbData = _wcsdup(L"Software\\Wow6432Node\\Classes\\Drive\\ShellEx\\ContextMenuHandlers");
      ret = 97;
      sub_FEA070(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free(cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      cbData = _wcsdup(L"Software\\Classes\\*\\ShellEx\\PropertySheetHandlers");
      ret = 98;
      sub_FEA070(0, ghCurrentUserKey, &cbData);
      ret = -1;
      free(cbData);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      cbData = _wcsdup(L"Software\\Classes\\*\\ShellEx\\PropertySheetHandlers");
      ret = 99;
      sub_FEA070(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free(cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      cbData = _wcsdup(L"Software\\Wow6432Node\\Classes\\*\\ShellEx\\PropertySheetHandlers");
      ret = 100;
      sub_FEA070(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free(cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      cbData = _wcsdup(L"Software\\Classes\\AllFileSystemObjects\\ShellEx\\ContextMenuHandlers");
      ret = 101;
      sub_FEA070(0, ghCurrentUserKey, &cbData);
      ret = -1;
      free(cbData);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      cbData = _wcsdup(L"Software\\Classes\\AllFileSystemObjects\\ShellEx\\ContextMenuHandlers");
      ret = 102;
      sub_FEA070(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free(cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      cbData = _wcsdup(L"Software\\Wow6432Node\\Classes\\AllFileSystemObjects\\ShellEx\\ContextMenuHandlers");
      ret = 103;
      sub_FEA070(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free(cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      cbData = _wcsdup(L"Software\\Classes\\AllFileSystemObjects\\ShellEx\\DragDropHandlers");
      ret = 104;
      sub_FEA070(0, ghCurrentUserKey, &cbData);
      ret = -1;
      free(cbData);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      cbData = _wcsdup(L"Software\\Classes\\AllFileSystemObjects\\ShellEx\\DragDropHandlers");
      ret = 105;
      sub_FEA070(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free(cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      cbData = _wcsdup(L"Software\\Wow6432Node\\Classes\\AllFileSystemObjects\\ShellEx\\DragDropHandlers");
      ret = 106;
      sub_FEA070(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free(cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      cbData = _wcsdup(L"Software\\Classes\\AllFileSystemObjects\\ShellEx\\PropertySheetHandlers");
      ret = 107;
      sub_FEA070(0, ghCurrentUserKey, &cbData);
      ret = -1;
      free(cbData);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      cbData = _wcsdup(L"Software\\Classes\\AllFileSystemObjects\\ShellEx\\PropertySheetHandlers");
      ret = 108;
      sub_FEA070(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free(cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      cbData = _wcsdup(L"Software\\Wow6432Node\\Classes\\AllFileSystemObjects\\ShellEx\\PropertySheetHandlers");
      ret = 109;
      sub_FEA070(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free(cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      cbData = _wcsdup(L"Software\\Classes\\Directory\\ShellEx\\ContextMenuHandlers");
      ret = 110;
      sub_FEA070(0, ghCurrentUserKey, &cbData);
      ret = -1;
      free(cbData);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      cbData = _wcsdup(L"Software\\Classes\\Directory\\ShellEx\\ContextMenuHandlers");
      ret = 111;
      sub_FEA070(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free(cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      cbData = _wcsdup(L"Software\\Wow6432Node\\Classes\\Directory\\ShellEx\\ContextMenuHandlers");
      ret = 112;
      sub_FEA070(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free(cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      cbData = _wcsdup(L"Software\\Classes\\Directory\\Shellex\\DragDropHandlers");
      ret = 113;
      sub_FEA070(0, ghCurrentUserKey, &cbData);
      ret = -1;
      free(cbData);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      cbData = _wcsdup(L"Software\\Classes\\Directory\\Shellex\\DragDropHandlers");
      ret = 114;
      sub_FEA070(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free(cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      cbData = _wcsdup(L"Software\\Wow6432Node\\Classes\\Directory\\Shellex\\DragDropHandlers");
      ret = 115;
      sub_FEA070(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free(cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      cbData = _wcsdup(L"Software\\Classes\\Directory\\Shellex\\PropertySheetHandlers");
      ret = 116;
      sub_FEA070(0, ghCurrentUserKey, &cbData);
      ret = -1;
      free(cbData);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      cbData = _wcsdup(L"Software\\Classes\\Directory\\Shellex\\PropertySheetHandlers");
      ret = 117;
      sub_FEA070(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free(cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      cbData = _wcsdup(L"Software\\Wow6432Node\\Classes\\Directory\\Shellex\\PropertySheetHandlers");
      ret = 118;
      sub_FEA070(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free(cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      cbData = _wcsdup(L"Software\\Classes\\Directory\\Shellex\\CopyHookHandlers");
      ret = 119;
      sub_FEA070(0, ghCurrentUserKey, &cbData);
      ret = -1;
      free(cbData);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      cbData = _wcsdup(L"Software\\Classes\\Directory\\Shellex\\CopyHookHandlers");
      ret = 120;
      sub_FEA070(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free(cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      cbData = _wcsdup(L"Software\\Wow6432Node\\Classes\\Directory\\Shellex\\CopyHookHandlers");
      ret = 121;
      sub_FEA070(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free(cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      cbData = _wcsdup(L"Software\\Classes\\Directory\\Background\\ShellEx\\ContextMenuHandlers");
      ret = 122;
      sub_FEA070(0, ghCurrentUserKey, &cbData);
      ret = -1;
      free(cbData);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      cbData = _wcsdup(L"Software\\Classes\\Directory\\Background\\ShellEx\\ContextMenuHandlers");
      ret = 123;
      sub_FEA070(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free(cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      cbData = _wcsdup(L"Software\\Wow6432Node\\Classes\\Directory\\Background\\ShellEx\\ContextMenuHandlers");
      ret = 124;
      sub_FEA070(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free(cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      v49 = _wcsdup(L"Software\\Classes\\Folder\\Shellex\\ColumnHandlers");
      cbData = v49;
      ret = 125;
      sub_FD86F0(0, ghCurrentUserKey, &cbData);
      ret = -1;
      free(v49);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      v50 = _wcsdup(L"Software\\Classes\\Folder\\Shellex\\ColumnHandlers");
      cbData = v50;
      ret = 126;
      sub_FD86F0(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free(v50);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      v51 = _wcsdup(L"Software\\Wow6432Node\\Classes\\Folder\\Shellex\\ColumnHandlers");
      cbData = v51;
      ret = 127;
      sub_FD86F0(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free(v51);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      cbData = _wcsdup(L"Software\\Classes\\Folder\\ShellEx\\ContextMenuHandlers");
      ret = 128;
      sub_FEA070(0, ghCurrentUserKey, &cbData);
      ret = -1;
      free(cbData);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      cbData = _wcsdup(L"Software\\Classes\\Folder\\ShellEx\\ContextMenuHandlers");
      ret = 129;
      sub_FEA070(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free(cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      cbData = _wcsdup(L"Software\\Wow6432Node\\Classes\\Folder\\ShellEx\\ContextMenuHandlers");
      ret = 130;
      sub_FEA070(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free(cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      cbData = _wcsdup(L"Software\\Classes\\Folder\\ShellEx\\DragDropHandlers");
      ret = 131;
      sub_FEA070(0, ghCurrentUserKey, &cbData);
      ret = -1;
      free(cbData);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      cbData = _wcsdup(L"Software\\Classes\\Folder\\ShellEx\\DragDropHandlers");
      ret = 132;
      sub_FEA070(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free(cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      cbData = _wcsdup(L"Software\\Wow6432Node\\Classes\\Folder\\ShellEx\\DragDropHandlers");
      ret = 133;
      sub_FEA070(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free(cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      cbData = _wcsdup(L"Software\\Classes\\Folder\\ShellEx\\ExtShellFolderViews");
      ret = 134;
      sub_FEA070(0, ghCurrentUserKey, &cbData);
      ret = -1;
      free(cbData);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      cbData = _wcsdup(L"Software\\Classes\\Folder\\ShellEx\\ExtShellFolderViews");
      ret = 135;
      sub_FEA070(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free(cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      cbData = _wcsdup(L"Software\\Wow6432Node\\Classes\\Folder\\ShellEx\\ExtShellFolderViews");
      ret = 136;
      sub_FEA070(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free(cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      cbData = _wcsdup(L"Software\\Classes\\Folder\\ShellEx\\PropertySheetHandlers");
      ret = 137;
      sub_FEA070(0, ghCurrentUserKey, &cbData);
      ret = -1;
      free(cbData);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      cbData = _wcsdup(L"Software\\Classes\\Folder\\ShellEx\\PropertySheetHandlers");
      ret = 138;
      sub_FEA070(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free(cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      cbData = _wcsdup(L"Software\\Wow6432Node\\Classes\\Folder\\ShellEx\\PropertySheetHandlers");
      ret = 139;
      sub_FEA070(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free(cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      cbData = _wcsdup(L"Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\ShellIconOverlayIdentifiers");
      ret = 140;
      sub_FEA070(0, ghCurrentUserKey, &cbData);
      ret = -1;
      free(cbData);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      cbData = _wcsdup(L"Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\ShellIconOverlayIdentifiers");
      ret = 141;
      sub_FEA070(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free(cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      cbData = _wcsdup(L"Software\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\Explorer\\ShellIconOverlayIdentifiers");
      ret = 142;
      sub_FEA070(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free(cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
      PE_UpdateRegistryEx(
        0,
        ghCurrentUserKey,
        L"Software\\Classes\\Clsid\\{AB8902B4-09CA-4bb6-B78D-A8F59079A8D5}",
        L"Inprocserver32",
        32);
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      v52 = _wcsdup(L"Software\\Microsoft\\Ctf\\LangBarAddin");
      cbData = v52;
      ret = 143;
      sub_FD86F0(0, ghCurrentUserKey, &cbData);
      ret = -1;
      free(v52);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      v53 = _wcsdup(L"Software\\Microsoft\\Ctf\\LangBarAddin");
      cbData = v53;
      ret = 144;
      sub_FD86F0(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free(v53);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      v54 = _wcsdup(L"Software\\Microsoft\\Ctf\\LangBarAddin");
      cbData = v54;
      ret = 145;
      sub_FD86F0(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free(v54);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
  }
  if ( *Data )
  {
    sdwFlagsInLoadServiceRegistry = 8;
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      v55 = _wcsdup(L"Software\\Microsoft\\Internet Explorer\\UrlSearchHooks");
      *Data = v55;
      ret = 146;
      PE_LoadAutorunsDisabledFlags(0, ghCurrentUserKey, Data, 0, 1);
      ret = -1;
      free(v55);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      v56 = _wcsdup(L"Software\\Microsoft\\Internet Explorer\\Toolbar");
      *Data = v56;
      ret = 147;
      PE_LoadAutorunsDisabledFlags(0, ghLocalMachineKey, Data, 0, 1);
      ret = -1;
      free(v56);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      v57 = _wcsdup(L"Software\\Wow6432Node\\Microsoft\\Internet Explorer\\Toolbar");
      *Data = v57;
      ret = 148;
      PE_LoadAutorunsDisabledFlags(0, ghLocalMachineKey, Data, 0, 1);
      ret = -1;
      free(v57);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      cbData = _wcsdup(L"Software\\Microsoft\\Internet Explorer\\Explorer Bars");
      ret = 149;
      sub_FE4150(0, ghCurrentUserKey, &cbData);
      ret = -1;
      free(cbData);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      cbData = _wcsdup(L"Software\\Microsoft\\Internet Explorer\\Explorer Bars");
      ret = 150;
      sub_FE4150(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free(cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      cbData = _wcsdup(L"Software\\Wow6432Node\\Microsoft\\Internet Explorer\\Explorer Bars");
      ret = 151;
      sub_FE4150(0, ghCurrentUserKey, &cbData);
      ret = -1;
      free(cbData);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      cbData = _wcsdup(L"Software\\Wow6432Node\\Microsoft\\Internet Explorer\\Explorer Bars");
      ret = 152;
      sub_FE4150(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free(cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      cbData = _wcsdup(L"Software\\Microsoft\\Internet Explorer\\Extensions");
      ret = 153;
      sub_FE4150(0, ghCurrentUserKey, &cbData);
      ret = -1;
      free(cbData);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      cbData = _wcsdup(L"Software\\Microsoft\\Internet Explorer\\Extensions");
      ret = 154;
      sub_FE4150(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free(cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(1u);
      TlsSetValue(gdwTlsIndex, 0x200);
    }
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      cbData = _wcsdup(L"Software\\Wow6432Node\\Microsoft\\Internet Explorer\\Extensions");
      ret = 155;
      sub_FE4150(0, ghCurrentUserKey, &cbData);
      ret = -1;
      free(cbData);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      cbData = _wcsdup(L"Software\\Wow6432Node\\Microsoft\\Internet Explorer\\Extensions");
      ret = 156;
      sub_FE4150(0, ghLocalMachineKey, &cbData);
      ret = -1;
      free(cbData);
    }
    if ( Wow64EnableWow64FsRedirection )
    {
      Wow64EnableWow64FsRedirection(0);
      TlsSetValue(gdwTlsIndex, 0x100);
    }
  }
  if ( (dwType & 0x80u) != 0 )
  {
    sdwFlagsInLoadServiceRegistry = 128;
    if ( PE_OpenKey(ghLocalMachineKey, L"Software\\Microsoft\\Windows NT\\CurrentVersion\\Drivers32", 0, 0x20019u, Data) )
    {
      if ( dword_10C3628[0] && (dwFlagsIn == 2 || dwFlagsIn == 1) )
        wprintf(L"\nNo entry to display for codecs. Codecs are not supported on Nano Server.\n");
    }
    else
    {
      if ( dwFlagsIn == 2 || !dwFlagsIn )
      {
        v58 = _wcsdup(L"Software\\Microsoft\\Windows NT\\CurrentVersion\\Drivers32");
        dwType = v58;
        ret = 157;
        PE_LoadAutorunsDisabledFlags(0, ghCurrentUserKey, &dwType, 1, 0);
        ret = -1;
        free(v58);
      }
      if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      {
        v59 = _wcsdup(L"Software\\Microsoft\\Windows NT\\CurrentVersion\\Drivers32");
        dwType = v59;
        ret = 158;
        PE_LoadAutorunsDisabledFlags(0, ghLocalMachineKey, &dwType, 1, 0);
        ret = -1;
        free(v59);
      }
      if ( Wow64EnableWow64FsRedirection )
      {
        Wow64EnableWow64FsRedirection(1u);
        TlsSetValue(gdwTlsIndex, 0x200);
      }
      if ( dwFlagsIn == 2 || !dwFlagsIn )
      {
        v60 = _wcsdup(L"Software\\Wow6432Node\\Microsoft\\Windows NT\\CurrentVersion\\Drivers32");
        dwType = v60;
        ret = 159;
        PE_LoadAutorunsDisabledFlags(0, ghCurrentUserKey, &dwType, 1, 0);
        ret = -1;
        free(v60);
      }
      if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      {
        v61 = _wcsdup(L"Software\\Wow6432Node\\Microsoft\\Windows NT\\CurrentVersion\\Drivers32");
        dwType = v61;
        ret = 160;
        PE_LoadAutorunsDisabledFlags(0, ghLocalMachineKey, &dwType, 1, 0);
        ret = -1;
        free(v61);
      }
      if ( Wow64EnableWow64FsRedirection )
      {
        Wow64EnableWow64FsRedirection(0);
        TlsSetValue(gdwTlsIndex, 0x100);
      }
      if ( dwFlagsIn == 2 || !dwFlagsIn )
      {
        v62 = _wcsdup(L"Software\\Classes\\Filter");
        dwType = v62;
        ret = 161;
        sub_FD86F0(0, ghCurrentUserKey, &dwType);
        ret = -1;
        free(v62);
      }
      if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      {
        v63 = _wcsdup(L"Software\\Classes\\Filter");
        dwType = v63;
        ret = 162;
        sub_FD86F0(0, ghLocalMachineKey, &dwType);
        ret = -1;
        free(v63);
      }
      if ( Wow64EnableWow64FsRedirection )
      {
        Wow64EnableWow64FsRedirection(1u);
        TlsSetValue(gdwTlsIndex, 0x200);
      }
      if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
      {
        v64 = _wcsdup(L"Software\\Classes\\Filter");
        dwType = v64;
        ret = 163;
        sub_FD86F0(0, ghLocalMachineKey, &dwType);
        ret = -1;
        free(v64);
      }
      if ( Wow64EnableWow64FsRedirection )
      {
        Wow64EnableWow64FsRedirection(0);
        TlsSetValue(gdwTlsIndex, 0x100);
      }
      if ( dwFlagsIn == 2 || !dwFlagsIn )
        sub_FD9030(1, 0, ghCurrentUserKey, L"{083863F1-70DE-11d0-BD40-00A0C911CE86}");
      if ( dwFlagsIn == 2 || !dwFlagsIn )
        sub_FD9030(1, 0, ghCurrentUserKey, L"{AC757296-3522-4E11-9862-C17BE5A1767E}");
      if ( dwFlagsIn == 2 || !dwFlagsIn )
        sub_FD9030(1, 0, ghCurrentUserKey, L"{7ED96837-96F0-4812-B211-F13C24117ED3}");
      if ( dwFlagsIn == 2 || !dwFlagsIn )
        sub_FD9030(1, 0, ghCurrentUserKey, L"{ABE3B9A4-257D-4B97-BD1A-294AF496222E}");
      if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
        sub_FD9030(1, 0, ghLocalMachineKey, L"{083863F1-70DE-11d0-BD40-00A0C911CE86}");
      if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
        sub_FD9030(1, 0, ghLocalMachineKey, L"{AC757296-3522-4E11-9862-C17BE5A1767E}");
      if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
        sub_FD9030(1, 0, ghLocalMachineKey, L"{7ED96837-96F0-4812-B211-F13C24117ED3}");
      if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
        sub_FD9030(1, 0, ghLocalMachineKey, L"{ABE3B9A4-257D-4B97-BD1A-294AF496222E}");
    }
  }
  if ( dwFlags )
  {
    sdwFlagsInLoadServiceRegistry = 2;
    if ( dwFlagsIn == 2 || !dwFlagsIn )
    {
      dwType = _wcsdup(L"Software\\Policies\\Microsoft\\Windows\\System\\Scripts\\Logoff");
      ret = 164;
      sub_FE2060(0, ghCurrentUserKey, &dwType);
      ret = -1;
      free(dwType);
    }
    if ( dwFlagsIn == 2 || dwFlagsIn == 1 )
    {
      dwType = _wcsdup(L"Software\\Policies\\Microsoft\\Windows\\System\\Scripts\\Shutdown");
      ret = 165;
      sub_FE2060(0, ghLocalMachineKey, &dwType);
      free(dwType);
    }
  }
}
// 10C31C0: using guessed type int gdwFlagsInLoadServiceRegistry;
// 10C3628: using guessed type int dword_10C3628[140];
// 10C48D8: using guessed type int sdwFlagsInLoadServiceRegistry;

//----- (00FDF2D0) --------------------------------------------------------
void __cdecl sub_FDF2D0(int a1, void *a2, int a3, char a4, char a5)
{
  CPEString *v5; // edi
  const WCHAR *v6; // esi
  unsigned int v7; // eax
  _WORD *v8; // esi
  _WORD *v9; // ebx
  CPEString *v10; // eax
  CPEString *v11; // eax
  wchar_t *v12; // edi
  void *v13; // ebx
  CPEString *v14; // eax
  wchar_t *v15; // esi
  void *v16; // edi
  LSTATUS v17; // eax
  WCHAR *v18; // ebx
  wchar_t *v19; // edi
  WCHAR *v20; // esi
  CPEString *v21; // eax
  _WORD *v22; // [esp+10h] [ebp-40h]
  void *a1a; // [esp+14h] [ebp-3Ch]
  WCHAR szArg[2]; // [esp+18h] [ebp-38h]
  int a6; // [esp+1Ch] [ebp-34h]
  LPCWSTR szArg4; // [esp+20h] [ebp-30h]
  WCHAR *ppv; // [esp+24h] [ebp-2Ch]
  WCHAR *ppv1; // [esp+28h] [ebp-28h]
  void *v29; // [esp+2Ch] [ebp-24h]
  void *v30; // [esp+30h] [ebp-20h]
  void *v31; // [esp+34h] [ebp-1Ch]
  HKEY hKey; // [esp+38h] [ebp-18h]
  HKEY__ v33; // [esp+3Ch] [ebp-14h]
  WCHAR *ppv3; // [esp+40h] [ebp-10h]
  int v35; // [esp+4Ch] [ebp-4h]

  v22 = malloc(2u);
  *v22 = 0;
  v5 = a3;
  v35 = 0;
  v6 = *a3;
  v7 = TlsGetValue(gdwTlsIndex);
  if ( PE_OpenKey(a2, v6, 0, v7 | 0x20019, &hKey) )
  {
    ppv3 = _wcsdup(&gszNullString);
    v33.unused = _wcsdup(&gszNullString);
    v31 = _wcsdup(&gszNullString);
    v30 = _wcsdup(&gszNullString);
    v29 = _wcsdup(&gszNullString);
    v18 = _wcsdup(&gszNullString);
    ppv1 = v18;
    v19 = _wcsdup(&gszNullString);
    szArg4 = v19;
    v20 = _wcsdup(&gszNullString);
    ppv = v20;
    a6 = MakeRegistryKeyName(&a1a, a2, a3, &szArg4);
    v21 = MakeRegistryKeyName(szArg, a2, a3, &ppv);
    LOBYTE(v35) = 13;
    sub_FD3FF0(a1, 0, 0xFFFFFFFF, 0, v21, a6, &ppv1);
    free(*szArg);
    free(a1a);
    free(v20);
    free(v19);
    free(v18);
    free(v29);
    free(v30);
    free(v31);
    free(v33.unused);
    free(ppv3);
  }
  else
  {
    v31 = 0;
    v8 = malloc(2u);
    v33.unused = v8;
    *v8 = 0;
    v9 = malloc(2u);
    v30 = v9;
    v29 = v9;
    *v9 = 0;
    ppv3 = malloc(2u);
    *ppv3 = 0;
    LOBYTE(v35) = 3;
    if ( !PE_LoadRegKeys(hKey, 0, &ppv3) )
    {
      do
      {
        v10 = CPEString::Append(&ppv, v5, L"\\");
        v11 = CPEString::Append(&ppv1, v10, &ppv3);
        v12 = _wcsdup(v11->m_String);
        v33.unused = v12;
        free(v8);
        free(ppv1);
        free(ppv);
        v13 = sub_FD9B70(a1, a2, v12, a4, a5, 0xFFFFFFFF, 1, 0);
        v14 = CPEString::Append(&szArg4, &v33, L"\\AutorunsDisabled");
        v15 = _wcsdup(v14->m_String);
        v29 = v15;
        free(v30);
        free(szArg4);
        sub_FD9B70(a1, a2, v15, a4, a5, v13, 0, 0);
        free(ppv3);
        free(v15);
        free(v12);
        v31 = v31 + 1;
        v16 = v31;
        v8 = malloc(2u);
        v33.unused = v8;
        *v8 = 0;
        v9 = malloc(2u);
        v30 = v9;
        v29 = v9;
        *v9 = 0;
        ppv3 = malloc(2u);
        *ppv3 = 0;
        LOBYTE(v35) = 3;
        v17 = PE_LoadRegKeys(hKey, v16, &ppv3);
        v5 = a3;
      }
      while ( !v17 );
    }
    free(ppv3);
    free(v9);
    free(v8);
    RegCloseKey(hKey);
  }
  free(v22);
}

//----- (00FDF610) --------------------------------------------------------
char __cdecl UpdateMenuItemWithAccountInfo(HWND hWnd, tagAccountInfo *pInfo, DWORD dwMenuId)
{
  WCHAR *v3; // edi
  WCHAR *lpszFile; // ebx
  _WORD *v5; // eax
  int index; // ecx
  tagAccountInfo **v7; // esi
  unsigned int nCount; // edx
  tagAccountInfo *v9; // eax
  tagAccountInfo *pInfoTemp; // esi
  bool bNotSystemUser; // zf
  int v12; // eax
  const WCHAR **v13; // ecx
  wchar_t *v14; // esi
  CPEString *v15; // eax
  const wchar_t **v16; // eax
  WCHAR *v17; // esi
  const WCHAR *v18; // esi
  int v19; // eax
  wchar_t *v20; // esi
  CPEString *v21; // eax
  WCHAR *v22; // ST48_4
  FILE *v23; // eax
  UINT v24; // ST2C_4
  HMENU v25; // eax
  UINT v26; // ST2C_4
  HMENU v27; // eax
  void *v29; // [esp+10h] [ebp-30h]
  const WCHAR *lpszKeyName; // [esp+14h] [ebp-2Ch]
  HKEY__ v31; // [esp+18h] [ebp-28h]
  WCHAR *ppstr; // [esp+1Ch] [ebp-24h]
  DWORD dwMessageId; // [esp+20h] [ebp-20h]
  HKEY__ hKey; // [esp+24h] [ebp-1Ch]
  HKEY KeyHandle; // [esp+28h] [ebp-18h]
  tagAccountInfo *pInfoTemp_1; // [esp+2Ch] [ebp-14h]
  char ret; // [esp+33h] [ebp-Dh]
  int v38; // [esp+3Ch] [ebp-4h]

  v3 = malloc(2u);
  hKey.unused = v3;
  *v3 = 0;
  v38 = 0;
  lpszFile = malloc(2u);
  v31.unused = lpszFile;
  *lpszFile = 0;
  ret = 0;
  v5 = malloc(2u);
  index = 0;
  v29 = v5;
  *v5 = 0;
  v7 = garrAccountInfo.baseclass_0._Mypair._Myval2._Myfirst;
  nCount = (garrAccountInfo.baseclass_0._Mypair._Myval2._Mylast - garrAccountInfo.baseclass_0._Mypair._Myval2._Myfirst) >> 2;
  LOBYTE(v38) = 2;
  if ( nCount )
  {
    while ( 1 )
    {
      v9 = v7[index];
      v7 = garrAccountInfo.baseclass_0._Mypair._Myval2._Myfirst;
      if ( v9->nMenuID == dwMenuId )
        break;
      if ( ++index >= nCount )
        goto LABEL_4;
    }
    pInfoTemp = *(garrAccountInfo.baseclass_0._Mypair._Myval2._Myfirst + index);
  }
  else
  {
LABEL_4:
    pInfoTemp = KeyHandle;
  }
  bNotSystemUser = LOBYTE(pInfoTemp->bIsSystemUser) == 0;
  pInfoTemp_1 = pInfoTemp;
  if ( !bNotSystemUser )
  {
    KeyHandle = HKEY_CURRENT_USER;
LABEL_20:
    ret = 1;
    if ( hWnd )
    {
      v24 = pInfo->nMenuID;
      v25 = GetMenu(hWnd);
      CheckMenuItem(v25, v24, 0);
      v26 = pInfoTemp_1->nMenuID;
      v27 = GetMenu(hWnd);
      CheckMenuItem(v27, v26, MF_CHECKED);
    }
    if ( pInfo && !LOBYTE(pInfo->bIsSystemUser) )
    {
      RegCloseKey(ghCurrentUserKey);
      RegUnLoadKeyW(HKEY_USERS, pInfo->szUserName);
    }
    gpAccountInfo = pInfoTemp_1;
    ghCurrentUserKey = KeyHandle;
    goto LABEL_26;
  }
  lpszKeyName = pInfoTemp->szReferenceName;
  v12 = wcscmp(pInfoTemp->szReferenceName, L"NT AUTHORITY\\SYSTEM");
  if ( v12 )
    v12 = -(v12 < 0) | 1;
  if ( v12 )
  {
    v13 = &gszNullString;
    if ( pInfoTemp != -1048 )
      v13 = pInfoTemp->szProfileImgPath;
    v14 = _wcsdup(v13);
    hKey.unused = v14;
    v15 = CPEString::Append(&ppstr, &hKey, L"\\ntuser.dat");
    dwMessageId = v3;
    v3 = _wcsdup(v15->m_String);
    hKey.unused = v3;
    free(dwMessageId);
    free(ppstr);
    free(v14);
    v16 = RequerySystemEnvironmentString(&ppstr, v3);
    v17 = lpszFile;
    lpszFile = _wcsdup(*v16);
    v31.unused = lpszFile;
    free(v17);
    free(ppstr);
    v18 = pInfoTemp_1->szUserName;
    dwMessageId = RegLoadKeyW(HKEY_USERS, pInfoTemp_1->szUserName, lpszFile);
    if ( dwMessageId )
    {
      v20 = _wcsdup(L"Error loading profile for ");
      v31.unused = v20;
      v21 = CPEString::Append(&ppstr, &v31, lpszKeyName);
      v22 = v3;
      v3 = _wcsdup(v21->m_String);
      free(v22);
      free(ppstr);
      free(v20);
      v23 = sub_1067B15();
      fputws(v3, v23 + 2);
      sub_FD7AE0(dwMessageId);
      goto LABEL_26;
    }
    v19 = PE_OpenKey(HKEY_USERS, v18, 0, 0x2001Fu, &KeyHandle);
  }
  else
  {
    v19 = PE_OpenKey(HKEY_USERS, pInfoTemp->szUserName, 0, 0x2001Fu, &KeyHandle);
  }
  if ( !v19 )
    goto LABEL_20;
LABEL_26:
  free(v29);
  free(lpszFile);
  free(v3);
  return ret;
}
// 108D238: using guessed type wchar_t aNtAuthoritySys[20];

//----- (00FDF8D0) --------------------------------------------------------
int __cdecl sub_FDF8D0(int a1, wchar_t *a2)
{
  const wchar_t *v2; // ecx
  wchar_t *v3; // eax
  wchar_t *v4; // ecx
  wchar_t *v5; // edx
  wchar_t i; // ax

  v2 = &gszNullString;
  if ( a2 )
    v2 = a2;
  v3 = _wcsdup(v2);
  v4 = v3;
  v5 = v3;
  *a1 = v3;
  for ( i = *v3; i; ++v4 )
  {
    if ( i != '"' )
    {
      *v5 = i;
      ++v5;
    }
    i = v4[1];
  }
  *v5 = 0;
  return a1;
}

//----- (00FDF930) --------------------------------------------------------
char __thiscall sub_FDF930(_DWORD *this, unsigned int a2)
{
  _DWORD *v2; // esi
  char *v4; // eax

  v2 = this;
  *this = 0;
  this[1] = 0;
  this[2] = 0;
  if ( !a2 )
    return 0;
  if ( a2 > 0x3FFFFFFF )
    std::_Xlength_error("vector<T> too long");
  v4 = operator new(4 * a2);
  if ( !v4 )
    std::_Xbad_alloc();
  *v2 = v4;
  v2[1] = v4;
  v2[2] = &v4[4 * a2];
  return 1;
}

//----- (00FDF9A0) --------------------------------------------------------
_DWORD *std::_Tree_comp_alloc<std::_Tmap_traits<wchar_t const *,tagKeyName,std::less<wchar_t const *>,std::allocator<std::pair<wchar_t const * const,tagKeyName>>,0>>::_Buyheadnode()
{
  _DWORD *result; // eax

  result = operator new(0x20u);
  JUMPOUT(result, 0, std::_Xbad_alloc);
  *result = result;
  if ( result != -4 )
    result[1] = result;
  if ( result != -8 )
    result[2] = result;
  *(result + 6) = 257;
  return result;
}

//----- (00FDF9D0) --------------------------------------------------------
int __thiscall sub_FDF9D0(string *this, unsigned int a2, int a3)
{
  string *v3; // esi
  unsigned int v4; // edi
  size_t v5; // ebx
  unsigned int v6; // ecx
  unsigned int v7; // eax
  CHAR *v8; // ecx
  string *v9; // edx
  int v10; // eax
  int result; // eax
  int v12; // [esp+0h] [ebp-28h]
  string *v13; // [esp+10h] [ebp-18h]
  CHAR *v14; // [esp+14h] [ebp-14h]
  int *v15; // [esp+18h] [ebp-10h]
  int v16; // [esp+24h] [ebp-4h]

  v15 = &v12;
  v3 = this;
  v13 = this;
  v4 = a2 | 7;
  if ( (a2 | 7) <= 0x7FFFFFFE )
  {
    v5 = this->_Myval2._Myres;
    v6 = this->_Myval2._Myres >> 1;
    if ( v6 > v4 / 3 )
    {
      v4 = v6 + v5;
      if ( v5 > 0x7FFFFFFE - v6 )
        v4 = 0x7FFFFFFE;
    }
  }
  else
  {
    v4 = a2;
  }
  v7 = v4 + 1;
  v16 = 0;
  v8 = 0;
  v14 = 0;
  if ( v4 != -1 )
  {
    if ( v7 > 0x7FFFFFFF || (v8 = operator new(2 * v7), (v14 = v8) == 0) )
      std::_Xbad_alloc();
  }
  if ( a3 )
  {
    v9 = v3->_Myval2._Myres < 8 ? v3 : v3->_Myval2._Bx._Ptr;
    if ( a3 )
      memmove_0(v8, v9, 2 * a3);
  }
  if ( v3->_Myval2._Myres >= 8 )
    j__free(v3->_Myval2._Bx._Ptr);
  v10 = v14;
  v3->_Myval2._Bx._Ptr = v14;
  v3->_Myval2._Myres = v4;
  v3->_Myval2._Mysize = a3;
  if ( v4 >= 8 )
    v3 = v10;
  result = 0;
  v3->_Myval2._Bx._Buf[a3] = 0;
  return result;
}
// 10681AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);

//----- (00FDFB40) --------------------------------------------------------
void __stdcall std::_Tree<std::_Tmap_traits<wchar_t const *,tagKeyName,std::less<wchar_t const *>,std::allocator<std::pair<wchar_t const * const,tagKeyName>>,0>>::clear(std__Tree_node *a1)
{
  std__Tree_node_For__bstr_t *v1; // edi
  std__Tree_node_For__bstr_t *v2; // ebx
  Data_t_bstr_t *v3; // esi
  Data_t_bstr_t *v4; // esi

  v1 = a1;
  v2 = a1;
  if ( !a1->_IsNil )
  {
    do
    {
      std::_Tree<std::_Tmap_traits<wchar_t const *,tagKeyName,std::less<wchar_t const *>,std::allocator<std::pair<wchar_t const * const,tagKeyName>>,0>>::clear(v2->_Right);
      v3 = v1->_bstrText2.m_Data;
      v2 = v2->_Left;
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
        v1->_bstrText2.m_Data = 0;
      }
      v4 = v1->_bstrText1.m_Data;
      if ( v4 )
      {
        if ( !InterlockedDecrement(&v4->m_RefCount) && v4 )
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
        v1->_bstrText1.m_Data = 0;
      }
      j__free(v1);
      v1 = v2;
    }
    while ( !v2->_IsNil );
  }
}

//----- (00FDFC40) --------------------------------------------------------
BOOL __thiscall sub_FDFC40(string *this, int a2, int a3)
{
  string *v3; // esi
  size_t v4; // eax
  BOOL result; // eax
  unsigned int v6; // ebx
  CHAR *v7; // ecx
  int v8; // [esp+14h] [ebp+Ch]

  v3 = this;
  if ( a2 > 0x7FFFFFFE )
    std::_Xlength_error("string too long");
  v4 = this->_Myval2._Myres;
  if ( v4 >= a2 )
  {
    if ( a3 && a2 < 8 )
    {
      v6 = this->_Myval2._Mysize;
      if ( a2 < v6 )
        v6 = a2;
      if ( v4 >= 8 )
      {
        v7 = this->_Myval2._Bx._Ptr;
        v8 = v3->_Myval2._Bx._Ptr;
        if ( v6 )
        {
          memmove_0(v3, v7, 2 * v6);
          v7 = v8;
        }
        j__free(v7);
      }
      v3->_Myval2._Mysize = v6;
      v3->_Myval2._Myres = 7;
      v3->_Myval2._Bx._Buf[v6] = 0;
      result = a2 > 0;
    }
    else
    {
      if ( !a2 )
      {
        this->_Myval2._Mysize = 0;
        if ( v4 >= 8 )
          v3 = this->_Myval2._Bx._Ptr;
        v3->_Myval2._Bx._Buf[0] = 0;
      }
      result = a2 > 0;
    }
  }
  else
  {
    sub_FDF9D0(this, a2, this->_Myval2._Mysize);
    result = a2 > 0;
  }
  return result;
}

//----- (00FDFD00) --------------------------------------------------------
int *__thiscall sub_FDFD00(int *this, unsigned int a2)
{
  int *v2; // ebx
  unsigned int v3; // esi
  char *v4; // edi
  int v5; // eax
  int v6; // ecx
  int v7; // ebx
  int *result; // eax
  int v9; // [esp+0h] [ebp-28h]
  void *v10; // [esp+10h] [ebp-18h]
  int *v11; // [esp+14h] [ebp-14h]
  int *v12; // [esp+18h] [ebp-10h]
  int v13; // [esp+24h] [ebp-4h]

  v12 = &v9;
  v2 = this;
  v11 = this;
  v3 = a2;
  v4 = 0;
  v10 = 0;
  if ( a2 )
  {
    if ( a2 > 0xFFFFFFF || (v4 = operator new(16 * a2), (v10 = v4) == 0) )
      std::_Xbad_alloc();
  }
  v13 = 0;
  sub_FD3440(*v2, v2[1], v4);
  v5 = *v2;
  v6 = v2[1];
  v7 = v2[1] - *v2;
  if ( v5 )
  {
    sub_FD2BF0(v5, v6);
    j__free(*v11);
  }
  result = v11;
  v11[2] = &v4[16 * v3];
  result[1] = &v4[v7 & 0xFFFFFFF0];
  *result = v4;
  return result;
}
// 10681AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);

//----- (00FDFDF0) --------------------------------------------------------
const wchar_t **__thiscall sub_FDFDF0(std__vector *this, unsigned int a2)
{
  std__vector *v2; // ebx
  char *v3; // edi
  std__vector *v4; // eax
  std__vector *v5; // esi
  int v6; // ecx
  int v7; // ecx
  const wchar_t **result; // eax
  int v9; // [esp+0h] [ebp-2Ch]
  int v10; // [esp+10h] [ebp-1Ch]
  void *v11; // [esp+14h] [ebp-18h]
  int *v12; // [esp+1Ch] [ebp-10h]
  int v13; // [esp+28h] [ebp-4h]

  v12 = &v9;
  v2 = this;
  v3 = 0;
  v11 = 0;
  if ( a2 )
  {
    if ( a2 > 0x3FFFFFFF || (v3 = operator new(4 * a2), (v11 = v3) == 0) )
      std::_Xbad_alloc();
  }
  v13 = 0;
  sub_FD34F0(v2->baseclass_0._Mypair._Myval2._Myfirst, v2->baseclass_0._Mypair._Myval2._Mylast, v3);
  v4 = v2->baseclass_0._Mypair._Myval2._Mylast;
  v5 = v2->baseclass_0._Mypair._Myval2._Myfirst;
  v6 = v2->baseclass_0._Mypair._Myval2._Mylast - v2->baseclass_0._Mypair._Myval2._Myfirst;
  v11 = v2->baseclass_0._Mypair._Myval2._Mylast;
  v7 = v6 >> 2;
  v10 = v7;
  if ( v5 )
  {
    if ( v5 != v4 )
    {
      do
      {
        free(v5->baseclass_0._Mypair._Myval2._Myfirst);
        v5 = (v5 + 4);
      }
      while ( v5 != v11 );
    }
    j__free(v2->baseclass_0._Mypair._Myval2._Myfirst);
    v7 = v10;
  }
  v2->baseclass_0._Mypair._Myval2._Myfirst = v3;
  v2->baseclass_0._Mypair._Myval2._Myend = &v3[4 * a2];
  result = &v3[4 * v7];
  v2->baseclass_0._Mypair._Myval2._Mylast = result;
  return result;
}
// 10681AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);

//----- (00FDFEE0) --------------------------------------------------------
int *__thiscall sub_FDFEE0(int *this, unsigned int a2)
{
  int v2; // esi
  int *result; // eax
  int v4; // esi
  unsigned int v5; // esi
  unsigned int v6; // edx
  unsigned int v7; // edx
  unsigned int v8; // edx

  v2 = this[1];
  result = ((this[2] - v2) >> 4);
  if ( result < a2 )
  {
    v4 = (v2 - *this) >> 4;
    if ( 0xFFFFFFF - v4 < a2 )
      std::_Xlength_error("vector<T> too long");
    v5 = a2 + v4;
    v6 = (this[2] - *this) >> 4;
    if ( 0xFFFFFFF - (v6 >> 1) >= v6 )
    {
      v8 = (v6 >> 1) + v6;
      if ( v8 < v5 )
        v8 = v5;
      result = sub_FDFD00(this, v8);
    }
    else
    {
      v7 = 0;
      if ( v5 > 0 )
        v7 = v5;
      result = sub_FDFD00(this, v7);
    }
  }
  return result;
}

//----- (00FDFF60) --------------------------------------------------------
unsigned int __thiscall std::vector<wchar_t const *,std::allocator<wchar_t const *>>::_Reserve(std__vector *this, unsigned int a2)
{
  void *v2; // esi
  unsigned int result; // eax
  signed int v4; // esi
  unsigned int v5; // esi
  unsigned int v6; // edx
  unsigned int v7; // edx
  unsigned int v8; // edx

  v2 = this->baseclass_0._Mypair._Myval2._Mylast;
  result = (this->baseclass_0._Mypair._Myval2._Myend - v2) >> 2;
  if ( result < a2 )
  {
    v4 = (v2 - this->baseclass_0._Mypair._Myval2._Myfirst) >> 2;
    if ( 0x3FFFFFFF - v4 < a2 )
      std::_Xlength_error("vector<T> too long");
    v5 = a2 + v4;
    v6 = (this->baseclass_0._Mypair._Myval2._Myend - this->baseclass_0._Mypair._Myval2._Myfirst) >> 2;
    if ( 0x3FFFFFFF - (v6 >> 1) >= v6 )
    {
      v8 = (v6 >> 1) + v6;
      if ( v8 < v5 )
        v8 = v5;
      result = sub_FDFDF0(this, v8);
    }
    else
    {
      v7 = 0;
      if ( v5 > 0 )
        v7 = v5;
      result = sub_FDFDF0(this, v7);
    }
  }
  return result;
}

//----- (00FDFFE0) --------------------------------------------------------
void *__stdcall sub_FDFFE0(unsigned int a1)
{
  void *v1; // ecx

  v1 = 0;
  if ( a1 )
  {
    if ( a1 > 0x7FFFFFFF || (v1 = operator new(2 * a1)) == 0 )
      std::_Xbad_alloc();
  }
  return v1;
}

//----- (00FE0010) --------------------------------------------------------
int __thiscall sub_FE0010(int *this)
{
  int *v1; // edi
  int v2; // ebx
  void **v3; // esi
  int result; // eax

  v1 = this;
  v2 = this[1];
  v3 = *this;
  if ( *this == v2 )
  {
    result = *this;
    this[1] = v3;
  }
  else
  {
    do
    {
      free(*v3);
      ++v3;
    }
    while ( v3 != v2 );
    result = *v1;
    v1[1] = *v1;
  }
  return result;
}

//----- (00FE0050) --------------------------------------------------------
int __thiscall std::_Tree<std::_Tmap_traits<wchar_t const *,tagKeyName,std::less<wchar_t const *>,std::allocator<std::pair<wchar_t const * const,tagKeyName>>,0>>::erase(std__tree *this, std__Tree_node **a2, std__Tree_node *a3, std__Tree_node *Node)
{
  std__Tree_node *v4; // eax
  std__tree *v5; // esi
  std_Tree_node_for_tagKeyName *_Myhead; // ecx
  std__Tree_node **v7; // eax
  std__Tree_node *v8; // ecx
  int result; // eax
  std__Tree_node *v10; // ecx
  std__Tree_node *i; // edx
  std__Tree_node *v12; // eax
  int v13; // [esp+4h] [ebp-4h]

  v4 = a3;
  v5 = this;
  _Myhead = this->_Mypair._Myval2._Myhead;
  if ( a3 != _Myhead->_Left || Node != _Myhead )
  {
    for ( ; a3 != Node; v4 = a3 )
    {
      v10 = v4;
      if ( !v4->_IsNil )
      {
        i = v4->_Right;
        if ( i->_IsNil )
        {
          for ( i = v4->_Parent; !i->_IsNil; i = i->_Parent )
          {
            if ( v4 != i->_Right )
              break;
            v4 = i;
          }
        }
        else
        {
          v12 = i->_Left;
          if ( !i->_Left->_IsNil )
          {
            do
            {
              i = v12;
              v12 = v12->_Left;
            }
            while ( !v12->_IsNil );
          }
        }
        a3 = i;
      }
      std::_Tree<std::_Tmap_traits<wchar_t const *,tagKeyName,std::less<wchar_t const *>,std::allocator<std::pair<wchar_t const * const,tagKeyName>>,0>>::erase(
        v5,
        &v13,
        v10);
    }
    *a2 = v4;
    result = a2;
  }
  else
  {
    std::_Tree<std::_Tmap_traits<wchar_t const *,tagKeyName,std::less<wchar_t const *>,std::allocator<std::pair<wchar_t const * const,tagKeyName>>,0>>::clear(_Myhead->_Parent);
    v5->_Mypair._Myval2._Myhead->_Parent = v5->_Mypair._Myval2._Myhead;
    v5->_Mypair._Myval2._Myhead->_Left = v5->_Mypair._Myval2._Myhead;
    v5->_Mypair._Myval2._Myhead->_Right = v5->_Mypair._Myval2._Myhead;
    v7 = v5->_Mypair._Myval2._Myhead;
    v5->_Mypair._Myval2._Mysize = 0;
    v8 = *v7;
    result = a2;
    *a2 = v8;
  }
  return result;
}

//----- (00FE0110) --------------------------------------------------------
int __thiscall std::_Tree<std::_Tmap_traits<wchar_t const *,tagKeyName,std::less<wchar_t const *>,std::allocator<std::pair<wchar_t const * const,tagKeyName>>,0>>::erase(std__tree *this, int a2, std__Tree_node *a3)
{
  std__Tree_node_For__bstr_t *v3; // ebx
  std_Tree_node_for_tagKeyName *v4; // edi
  std__Tree_node *v5; // ecx
  std__Tree_node *v6; // esi
  std__tree *pThis; // edx
  std__Tree_node *v8; // eax
  std__Tree_node *v9; // ecx
  std__Tree_node *v10; // eax
  std__Tree_node *v11; // eax
  std__Tree_node *i; // ecx
  std__Tree_node *v13; // eax
  bool v14; // cl
  std__Tree_node *v15; // ecx
  std__Tree_node *v16; // ST00_4
  std__Tree_node *v17; // esi
  std__Tree_node *v18; // ST00_4
  Data_t_bstr_t *v19; // edi
  LONG (__stdcall *v20)(volatile LONG *); // ecx
  Data_t_bstr_t *v21; // edi
  std_Tree_node_for_tagKeyName *v22; // eax
  std__Tree_node *v23; // ecx
  int result; // eax
  std__Tree_node *v25; // [esp+Ch] [ebp-8h]
  std__tree *This; // [esp+10h] [ebp-4h]

  v3 = a3;
  This = this;
  sub_FF4CE0(&a3);
  if ( v3->_Left->_IsNil )
  {
    v4 = v3->_Right;
LABEL_6:
    v6 = v3->_Parent;
    if ( !v4->_IsNil )
      v4->_Parent = v6;
    pThis = This;
    if ( This->_Mypair._Myval2._Myhead->_Parent == v3 )
    {
      This->_Mypair._Myval2._Myhead->_Parent = v4;
    }
    else if ( v6->_Left == v3 )
    {
      v6->_Left = v4;
    }
    else
    {
      v6->_Right = v4;
    }
    v8 = This->_Mypair._Myval2._Myhead;
    if ( This->_Mypair._Myval2._Myhead->_Left == v3 )
    {
      if ( v4->_IsNil )
      {
        v9 = v6;
      }
      else
      {
        v10 = v4->_Left;
        v9 = v4;
        if ( !v4->_Left->_IsNil )
        {
          do
          {
            v9 = v10;
            v10 = v10->_Left;
          }
          while ( !v10->_IsNil );
        }
        v8 = This->_Mypair._Myval2._Myhead;
      }
      v8->_Left = v9;
    }
    if ( This->_Mypair._Myval2._Myhead->_Right == v3 )
    {
      if ( v4->_IsNil )
      {
        This->_Mypair._Myval2._Myhead->_Right = v6;
      }
      else
      {
        v11 = v4->_Right;
        for ( i = v4; !v11->_IsNil; v11 = v11->_Right )
          i = v11;
        This->_Mypair._Myval2._Myhead->_Right = i;
      }
    }
    goto LABEL_37;
  }
  if ( v3->_Right->_IsNil )
  {
    v4 = v3->_Left;
    goto LABEL_6;
  }
  v5 = a3;
  v25 = a3;
  v4 = a3->_Right;
  if ( a3 == v3 )
    goto LABEL_6;
  v3->_Left->_Parent = a3;
  v5->_Left = v3->_Left;
  if ( v5 == v3->_Right )
  {
    v6 = v5;
  }
  else
  {
    v6 = v5->_Parent;
    if ( !v4->_IsNil )
      v4->_Parent = v6;
    v6->_Left = v4;
    v5->_Right = v3->_Right;
    v3->_Right->_Parent = v5;
  }
  if ( This->_Mypair._Myval2._Myhead->_Parent == v3 )
  {
    This->_Mypair._Myval2._Myhead->_Parent = v5;
  }
  else
  {
    v13 = v3->_Parent;
    if ( v13->_Left == v3 )
      v13->_Left = v5;
    else
      v13->_Right = v5;
  }
  v5->_Parent = v3->_Parent;
  v14 = v5->_Color;
  v25->_Color = v3->_Color;
  pThis = This;
  v3->_Color = v14;
LABEL_37:
  if ( v3->_Color == 1 )
  {
    for ( ; v4 != pThis->_Mypair._Myval2._Myhead->_Parent; v6 = v6->_Parent )
    {
      if ( v4->_Color != 1 )
        break;
      v15 = v6->_Left;
      if ( v4 == v6->_Left )
      {
        v15 = v6->_Right;
        if ( !v15->_Color )
        {
          v15->_Color = 1;
          v6->_Color = 0;
          sub_10554B0(pThis, v6);
          v15 = v6->_Right;
          pThis = This;
        }
        if ( v15->_IsNil )
          goto LABEL_55;
        if ( v15->_Left->_Color != 1 || v15->_Right->_Color != 1 )
        {
          if ( v15->_Right->_Color == 1 )
          {
            v15->_Left->_Color = 1;
            v15->_Color = 0;
            sub_1062BB0(pThis, v15);
            v15 = v6->_Right;
          }
          v15->_Color = v6->_Color;
          v6->_Color = 1;
          v16 = v6;
          v17 = This;
          v15->_Right->_Color = 1;
          sub_10554B0(This, v16);
          v4->_Color = 1;
          goto LABEL_61;
        }
      }
      else
      {
        if ( !v15->_Color )
        {
          v15->_Color = 1;
          v6->_Color = 0;
          sub_1062BB0(pThis, v6);
          v15 = v6->_Left;
          pThis = This;
        }
        if ( v15->_IsNil )
          goto LABEL_55;
        if ( v15->_Right->_Color != 1 || v15->_Left->_Color != 1 )
        {
          if ( v15->_Left->_Color == 1 )
          {
            v15->_Right->_Color = 1;
            v15->_Color = 0;
            sub_10554B0(pThis, v15);
            v15 = v6->_Left;
          }
          v15->_Color = v6->_Color;
          v6->_Color = 1;
          v18 = v6;
          v17 = This;
          v15->_Left->_Color = 1;
          sub_1062BB0(This, v18);
          v4->_Color = 1;
          goto LABEL_61;
        }
      }
      v15->_Color = 0;
LABEL_55:
      v4 = v6;
    }
    v17 = This;
    v4->_Color = 1;
  }
  else
  {
    v17 = This;
  }
LABEL_61:
  v19 = v3->_bstrText2.m_Data;
  // void __thiscall tagKeyName___tagKeyName(tagKeyName *this)
  v20 = InterlockedDecrement;
  if ( v19 )
  {
    if ( !InterlockedDecrement(&v19->m_RefCount) && v19 )
    {
      if ( v19->m_wstr )
      {
        SysFreeString(v19->m_wstr);
        v19->m_wstr = 0;
      }
      if ( v19->m_str )
      {
        j_j__free(v19->m_str);
        v19->m_str = 0;
      }
      j__free(v19);
    }
    v20 = InterlockedDecrement;
    v3->_bstrText2.m_Data = 0;
  }
  v21 = v3->_bstrText1.m_Data;
  if ( v21 )
  {
    if ( !v20(&v21->m_RefCount) && v21 )
    {
      if ( v21->m_wstr )
      {
        SysFreeString(v21->m_wstr);
        v21->m_wstr = 0;
      }
      if ( v21->m_str )
      {
        j_j__free(v21->m_str);
        v21->m_str = 0;
      }
      j__free(v21);
    }
    v3->_bstrText1.m_Data = 0;
  }
  j__free(v3);
  v22 = v17->_Parent;
  v23 = a3;
  if ( v22 )
    v17->_Parent = (v22 - 1);
  result = a2;
  *a2 = v23;
  return result;
}

//----- (00FE0440) --------------------------------------------------------
UINT __thiscall sub_FE0440(BSTR **this)
{
  UINT result; // eax

  if ( *this && **this )
    result = SysStringLen(**this);
  else
    result = 0;
  return result;
}

//----- (00FE0460) --------------------------------------------------------
const wchar_t **__thiscall sub_FE0460(int *this, const wchar_t **a2)
{
  int *v2; // esi
  const wchar_t **result; // eax
  const wchar_t **v4; // edi
  int v5; // ecx
  unsigned int v6; // edi
  int v7; // ebx

  v2 = this;
  result = this[1];
  v4 = a2;
  if ( a2 >= result || (v5 = *this, *v2 > a2) )
  {
    if ( result == v2[2] )
      result = sub_FDFEE0(v2, 1u);
    v7 = v2[1];
    if ( v7 )
    {
      *v7 = _wcsdup(*a2);
      goto LABEL_11;
    }
  }
  else
  {
    v6 = a2 - v5;
    if ( result == v2[2] )
      result = sub_FDFEE0(v2, 1u);
    v7 = v2[1];
    v4 = (*v2 + (v6 & 0xFFFFFFF0));
    if ( v7 )
    {
      *v7 = _wcsdup(*v4);
LABEL_11:
      result = sub_FD35A0((v7 + 4), v4 + 1);
      goto LABEL_12;
    }
  }
LABEL_12:
  v2[1] += 16;
  return result;
}

//----- (00FE0530) --------------------------------------------------------
const wchar_t **__thiscall sub_FE0530(std__vector *this, const wchar_t **a2)
{
  std__vector *v2; // esi
  const wchar_t **result; // eax
  _BYTE *v4; // ecx
  int v5; // edi
  _DWORD *v6; // ebx

  v2 = this;
  result = this->baseclass_0._Mypair._Myval2._Mylast;
  if ( a2 >= result || (v4 = this->baseclass_0._Mypair._Myval2._Myfirst, v2->baseclass_0._Mypair._Myval2._Myfirst > a2) )
  {
    if ( result == v2->baseclass_0._Mypair._Myval2._Myend )
      result = std::vector<wchar_t const *,std::allocator<wchar_t const *>>::_Reserve(v2, 1u);
    v6 = v2->baseclass_0._Mypair._Myval2._Mylast;
    if ( v6 )
    {
      result = _wcsdup(*a2);
      goto LABEL_11;
    }
  }
  else
  {
    v5 = (a2 - v4) >> 2;
    if ( result == v2->baseclass_0._Mypair._Myval2._Myend )
      result = std::vector<wchar_t const *,std::allocator<wchar_t const *>>::_Reserve(v2, 1u);
    v6 = v2->baseclass_0._Mypair._Myval2._Mylast;
    if ( v6 )
    {
      result = _wcsdup(*(v2->baseclass_0._Mypair._Myval2._Myfirst + v5));
LABEL_11:
      *v6 = result;
      goto LABEL_12;
    }
  }
LABEL_12:
  v2->baseclass_0._Mypair._Myval2._Mylast = v2->baseclass_0._Mypair._Myval2._Mylast + 4;
  return result;
}

//----- (00FE05A0) --------------------------------------------------------
void *__cdecl PE_UpdateRegistry(int a1, HKEY hKey, LPCWSTR lpszKeyName, LPCWSTR lpValueName)
{
  _bstr_t *v4; // eax
  _bstr_t *bstrKeyName; // eax
  Data_t_bstr_t *v6; // esi
  Data_t_bstr_t *v7; // esi
  Data_t_bstr_t *v8; // esi
  void *Handle; // eax
  const WCHAR *v10; // ecx
  void *v11; // eax
  Data_t_bstr_t *v12; // esi
  void *v13; // edi
  _bstr_t bstrKeyName_1; // [esp+10h] [ebp-1Ch]
  _bstr_t bstrAutorunsDisabled; // [esp+14h] [ebp-18h]
  _bstr_t bstrSlash; // [esp+18h] [ebp-14h]
  _bstr_t bstrKeyNameTemp; // [esp+1Ch] [ebp-10h]
  int v19; // [esp+28h] [ebp-4h]

  _bstr_t::_bstr_t(&bstrAutorunsDisabled, L"AutorunsDisabled");
  v19 = 0;
  v4 = _bstr_t::_bstr_t(&bstrSlash, L"\\");
  LOBYTE(v19) = 1;
  bstrKeyName = _bstr_t::operator+(&bstrKeyNameTemp, lpszKeyName, v4);
  LOBYTE(v19) = 2;
  _bstr_t::operator+(bstrKeyName, &bstrKeyName_1, &bstrAutorunsDisabled);
  v6 = bstrKeyNameTemp.m_Data;
  if ( bstrKeyNameTemp.m_Data )
  {
    if ( !InterlockedDecrement(&bstrKeyNameTemp.m_Data->m_RefCount) && v6 )
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
    bstrKeyNameTemp.m_Data = 0;
  }
  v7 = bstrSlash.m_Data;
  if ( bstrSlash.m_Data )
  {
    if ( !InterlockedDecrement(&bstrSlash.m_Data->m_RefCount) && v7 )
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
    bstrSlash.m_Data = 0;
  }
  v8 = bstrAutorunsDisabled.m_Data;
  LOBYTE(v19) = 6;
  if ( bstrAutorunsDisabled.m_Data && !InterlockedDecrement(&bstrAutorunsDisabled.m_Data->m_RefCount) )
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
  Handle = sub_FE0790(a1, hKey, lpszKeyName, lpValueName, 0xFFFFFFFF);
  if ( bstrKeyName_1.m_Data )
    v10 = bstrKeyName_1.m_Data->m_wstr;
  else
    v10 = 0;
  v11 = sub_FE0790(a1, hKey, v10, lpValueName, Handle);
  v12 = bstrKeyName_1.m_Data;
  v13 = v11;
  if ( bstrKeyName_1.m_Data && !InterlockedDecrement(&bstrKeyName_1.m_Data->m_RefCount) && v12 )
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
  return v13;
}
