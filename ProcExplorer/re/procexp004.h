
//----- (00FE0790) --------------------------------------------------------
void *__cdecl sub_FE0790(int a1, HKEY hKey, LPCWSTR lpszKeyName, LPCWSTR lpszValueName, HANDLE Handle)
{
  HANDLE v5; // edi
  const WCHAR *v6; // esi
  int v7; // ebx
  const wchar_t *v8; // eax
  const wchar_t *v9; // eax
  const wchar_t *v10; // eax
  const wchar_t *v11; // eax
  CPEString *str1; // esi
  CPEString *str2; // eax
  WCHAR *v15; // eax
  wchar_t *pszValueNames; // edi
  DWORD v17; // eax
  _WORD *v18; // eax
  WCHAR *v19; // esi
  WCHAR *v20; // eax
  wchar_t *v21; // esi
  const wchar_t **v22; // eax
  WCHAR *v23; // ebx
  const wchar_t *v24; // ecx
  const wchar_t *v25; // eax
  const wchar_t *v26; // eax
  const wchar_t *v27; // eax
  CPEString *v28; // esi
  CPEString *v29; // eax
  char v30; // bl
  LPCWSTR v31; // ebx
  const wchar_t *v32; // eax
  const wchar_t *v33; // eax
  const wchar_t *v34; // eax
  const wchar_t *v35; // eax
  CPEString *v36; // esi
  CPEString *v37; // eax
  CPEString *v38; // ST34_4
  int v39; // esi
  const WCHAR **v40; // eax
  const wchar_t *v41; // eax
  CPEString *v42; // eax
  WCHAR v43[2]; // [esp+10h] [ebp-A4h]
  WCHAR v44[2]; // [esp+14h] [ebp-A0h]
  WCHAR v45[2]; // [esp+18h] [ebp-9Ch]
  WCHAR v46[2]; // [esp+1Ch] [ebp-98h]
  WCHAR v47[2]; // [esp+20h] [ebp-94h]
  int v48; // [esp+24h] [ebp-90h]
  void *v49; // [esp+28h] [ebp-8Ch]
  int a2; // [esp+2Ch] [ebp-88h]
  int v51; // [esp+30h] [ebp-84h]
  int v52; // [esp+34h] [ebp-80h]
  int v53; // [esp+38h] [ebp-7Ch]
  DWORD dwValue; // [esp+3Ch] [ebp-78h]
  void *v55; // [esp+40h] [ebp-74h]
  void *v56; // [esp+44h] [ebp-70h]
  LPCWSTR v57; // [esp+48h] [ebp-6Ch]
  void *v58; // [esp+4Ch] [ebp-68h]
  LPCWSTR v59; // [esp+50h] [ebp-64h]
  void *v60; // [esp+54h] [ebp-60h]
  LPCWSTR v61; // [esp+58h] [ebp-5Ch]
  WCHAR *ppv3; // [esp+5Ch] [ebp-58h]
  CPEString v63; // [esp+60h] [ebp-54h]
  LPCWSTR v64; // [esp+64h] [ebp-50h]
  LPCWSTR v65; // [esp+68h] [ebp-4Ch]
  void *v66; // [esp+6Ch] [ebp-48h]
  CPEString a1a; // [esp+70h] [ebp-44h]
  HKEY hSubKey; // [esp+74h] [ebp-40h]
  WCHAR szArg[2]; // [esp+78h] [ebp-3Ch]
  LPCWSTR szKeyName; // [esp+7Ch] [ebp-38h]
  LPCWSTR v71; // [esp+80h] [ebp-34h]
  void *v72; // [esp+84h] [ebp-30h]
  LPCWSTR v73; // [esp+88h] [ebp-2Ch]
  LPCWSTR v74; // [esp+8Ch] [ebp-28h]
  LPCWSTR pszValueName2; // [esp+90h] [ebp-24h]
  DWORD cbData; // [esp+94h] [ebp-20h]
  LPCWSTR pszKeyName2; // [esp+98h] [ebp-1Ch]
  CPEString strKeyName; // [esp+9Ch] [ebp-18h]
  CPEString strValueName; // [esp+A0h] [ebp-14h]
  CPEString str3; // [esp+A4h] [ebp-10h]
  int v81; // [esp+B0h] [ebp-4h]

  v5 = Handle;
  v6 = lpszValueName;
  v7 = a1;
  if ( Handle == -1 )
  {
    v71 = _wcsdup(&gszNullString);
    v81 = 0;
    v73 = _wcsdup(&gszNullString);
    szKeyName = _wcsdup(&gszNullString);
    v74 = _wcsdup(&gszNullString);
    v72 = _wcsdup(&gszNullString);
    str3.m_String = _wcsdup(&gszNullString);
    v8 = &gszNullString;
    if ( lpszValueName )
      v8 = lpszValueName;
    strValueName.m_String = _wcsdup(v8);
    v9 = &gszNullString;
    if ( lpszKeyName )
      v9 = lpszKeyName;
    strKeyName.m_String = _wcsdup(v9);
    v10 = &gszNullString;
    if ( lpszValueName )
      v10 = lpszValueName;
    pszValueName2 = _wcsdup(v10);
    v11 = &gszNullString;
    if ( lpszKeyName )
      v11 = lpszKeyName;
    pszKeyName2 = _wcsdup(v11);
    LOBYTE(v81) = 9;
    str1 = MakeRegistryKeyName(&a1a, hKey, &strKeyName, &strValueName);
    LOBYTE(v81) = 10;
    str2 = MakeRegistryKeyName(szArg, hKey, &pszKeyName2, &pszValueName2);
    LOBYTE(v81) = 11;
    v5 = sub_FD3FF0(a1, 0, 0xFFFFFFFF, 0, str2, str1, &str3);
    Handle = v5;
    free(*szArg);
    free(a1a.m_String);
    free(pszKeyName2);
    free(pszValueName2);
    free(strKeyName.m_String);
    free(strValueName.m_String);
    free(str3.m_String);
    free(v72);
    free(v74);
    free(szKeyName);
    free(v73);
    v81 = -1;
    free(v71);
    v6 = lpszValueName;
  }
  hSubKey = 0;
  PE_OpenKey(hKey, lpszKeyName, 0, KEY_READ, &hSubKey);
  if ( !hSubKey )
    return v5;
  cbData = 0;
  if ( !RegQueryValueExW(hSubKey, v6, 0, 0, 0, &cbData) )
  {
    v15 = malloc(2u);
    strKeyName.m_String = v15;
    *v15 = 0;
    v81 = 12;
    pszValueNames = operator new[](2 * ((cbData >> 1) + 2));
    RegQueryValueExW(hSubKey, v6, 0, 0, pszValueNames, &cbData);
    v17 = cbData >> 1;
    cbData = v17;
    if ( v17 > 2 )
    {
      pszValueNames[v17 - 1] = 0;
      for ( pszValueNames[cbData] = 0; *pszValueNames; pszValueNames = wcschr(pszValueNames + 1, 0) + 1 )
      {
        v18 = malloc(2u);
        a2 = v18;
        *v18 = 0;
        v51 = 0;
        v52 = 0;
        v53 = 0;
        LOBYTE(v81) = 13;
        sub_FD6CC0(pszValueNames, &a2);
        v19 = strKeyName.m_String;
        strKeyName.m_String = _wcsdup(pszValueNames);
        free(v19);
        sub_FD4EE0(&str3, v7, &a2, 0);
        v20 = str3.m_String;
        if ( str3.m_String )
        {
          if ( !_wcsnicmp(str3.m_String, L"File not found: ", 0x10u) && !_wcsnicmp(pszValueNames, L"autocheck ", 0xAu) )
          {
            v21 = _wcsdup(pszValueNames);
            dwValue = v21;
            LOBYTE(v81) = 15;
            sub_FD6CC0(pszValueNames + 10, &a2);
            v22 = sub_FD4EE0(&v49, v7, &a2, 0);
            v23 = str3.m_String;
            str3.m_String = _wcsdup(*v22);
            free(v23);
            free(v49);
            free(v21);
            v7 = a1;
          }
          v20 = str3.m_String;
        }
        if ( *v20 )
        {
          strValueName.m_String = malloc(2u);
          *strValueName.m_String = 0;
          pszKeyName2 = malloc(2u);
          *pszKeyName2 = 0;
          pszValueName2 = malloc(2u);
          *pszValueName2 = 0;
          LOBYTE(v81) = 18;
          dwValue = sub_FD4ED0();
          v72 = _wcsdup(pszValueNames);
          v24 = &gszNullString;
          if ( lpszValueName )
            v24 = lpszValueName;
          v74 = _wcsdup(v24);
          v25 = &gszNullString;
          if ( lpszKeyName )
            v25 = lpszKeyName;
          szKeyName = _wcsdup(v25);
          v26 = &gszNullString;
          if ( lpszValueName )
            v26 = lpszValueName;
          v73 = _wcsdup(v26);
          v27 = &gszNullString;
          if ( lpszKeyName )
            v27 = lpszKeyName;
          v71 = _wcsdup(v27);
          LOBYTE(v81) = 23;
          v28 = MakeRegistryKeyName(v43, hKey, &szKeyName, &v74);
          LOBYTE(v81) = 24;
          v29 = MakeRegistryKeyName(v47, hKey, &v71, &v73);
          LOBYTE(v81) = 25;
          v30 = sub_FD3D40(v7, v29, v28, &v72, &str3, &strValueName, &pszValueName2, &v48);
          free(*v47);
          free(*v43);
          free(v71);
          free(v73);
          free(szKeyName);
          free(v74);
          free(v72);
          if ( v30 )
          {
            if ( Handle == -1 )
            {
              v58 = _wcsdup(&gszNullString);
              v56 = _wcsdup(&gszNullString);
              v60 = _wcsdup(&gszNullString);
              v55 = _wcsdup(&gszNullString);
              v66 = _wcsdup(&gszNullString);
              v63.m_String = _wcsdup(&gszNullString);
              v31 = lpszValueName;
              v32 = &gszNullString;
              if ( lpszValueName )
                v32 = lpszValueName;
              v59 = _wcsdup(v32);
              v33 = &gszNullString;
              if ( lpszKeyName )
                v33 = lpszKeyName;
              v64 = _wcsdup(v33);
              v34 = &gszNullString;
              if ( lpszValueName )
                v34 = lpszValueName;
              v65 = _wcsdup(v34);
              v35 = &gszNullString;
              if ( lpszKeyName )
                v35 = lpszKeyName;
              v57 = _wcsdup(v35);
              LOBYTE(v81) = 35;
              v36 = MakeRegistryKeyName(v46, hKey, &v64, &v59);
              LOBYTE(v81) = 36;
              v37 = MakeRegistryKeyName(v44, hKey, &v57, &v65);
              LOBYTE(v81) = 37;
              v38 = v36;
              v39 = a1;
              Handle = sub_FD3FF0(a1, 0, 0xFFFFFFFF, 0, v37, v38, &v63);
              free(*v44);
              free(*v46);
              free(v57);
              free(v65);
              free(v64);
              free(v59);
              free(v63.m_String);
              free(v66);
              free(v55);
              free(v60);
              free(v56);
              free(v58);
            }
            else
            {
              v39 = a1;
              v31 = lpszValueName;
            }
            *szArg = _wcsdup(&gszNullString);
            v40 = &gszNullString;
            if ( v31 )
              v40 = v31;
            a1a.m_String = _wcsdup(v40);
            v41 = &gszNullString;
            if ( lpszKeyName )
              v41 = lpszKeyName;
            v61 = _wcsdup(v41);
            ppv3 = _wcsdup(pszValueNames);
            LOBYTE(v81) = 41;
            v42 = MakeRegistryKeyName(v45, hKey, &v61, &a1a);
            LOBYTE(v81) = 42;
            sub_FD3FF0(v39, dwValue, Handle, 5u, &ppv3, v42, &str3);
            free(*v45);
            free(ppv3);
            free(v61);
            free(a1a.m_String);
            free(*szArg);
          }
          free(pszValueName2);
          free(pszKeyName2);
          free(strValueName.m_String);
          v20 = str3.m_String;
        }
        free(v20);
        LOBYTE(v81) = 12;
        sub_FD21F0(&a2);
        v7 = a1;
      }
    }
    free(strKeyName.m_String);
  }
  RegCloseKey(hSubKey);
  return Handle;
}

//----- (00FE0F50) --------------------------------------------------------
int __cdecl RequerySystemEnvironmentString(WCHAR **ppstr, LPCWSTR lpszName)
{
  DWORD nLength; // eax
  DWORD v3; // edi
  WCHAR *pBuffer; // eax
  size_t v5; // edi
  WCHAR *v6; // eax
  DWORD nSize; // [esp+Ch] [ebp-4h]

  nLength = ExpandEnvironmentStringsW(lpszName, 0, 0);
  v3 = nLength;
  nSize = nLength;
  pBuffer = malloc(2u);
  v5 = 2 * v3 + 2;
  *ppstr = pBuffer;
  *pBuffer = 0;
  v6 = realloc(*ppstr, v5);
  *ppstr = v6;
  if ( v6 )
    memset(v6, 0, v5);
  ExpandEnvironmentStringsW(lpszName, *ppstr, nSize);
  return ppstr;
}

//----- (00FE0FC0) --------------------------------------------------------
HANDLE __cdecl sub_FE0FC0(OLECHAR *psz, LPWIN32_FIND_DATAW lpFindFileData)
{
  Data_t_bstr_t *v2; // esi
  const WCHAR *v3; // eax
  HANDLE v4; // edi
  _bstr_t bstrText; // [esp+8h] [ebp-4h]

  sub_FD7AB0(&gKeyNameMap, &bstrText, psz);
  v2 = bstrText.m_Data;
  if ( bstrText.m_Data )
    v3 = bstrText.m_Data->m_wstr;
  else
    v3 = 0;
  v4 = FindFirstFileW(v3, lpFindFileData);
  if ( v2 && !InterlockedDecrement(&v2->m_RefCount) )
  {
    if ( v2->m_wstr )
    {
      SysFreeString(v2->m_wstr);
      v2->m_wstr = 0;
    }
    if ( v2->m_str )
    {
      j_j__free(v2->m_str);
      v2->m_str = 0;
    }
    j__free(v2);
  }
  return v4;
}

//----- (00FE1040) --------------------------------------------------------
DWORD __cdecl sub_FE1040(OLECHAR *psz)
{
  Data_t_bstr_t *v1; // esi
  const WCHAR *v2; // eax
  DWORD v3; // edi
  _bstr_t bstrText; // [esp+8h] [ebp-4h]

  sub_FD7AB0(&gKeyNameMap, &bstrText, psz);
  v1 = bstrText.m_Data;
  if ( bstrText.m_Data )
    v2 = bstrText.m_Data->m_wstr;
  else
    v2 = 0;
  v3 = GetFileAttributesW(v2);
  if ( v1 && !InterlockedDecrement(&v1->m_RefCount) )
  {
    if ( v1->m_wstr )
    {
      SysFreeString(v1->m_wstr);
      v1->m_wstr = 0;
    }
    if ( v1->m_str )
    {
      j_j__free(v1->m_str);
      v1->m_str = 0;
    }
    j__free(v1);
  }
  return v3;
}

//----- (00FE10C0) --------------------------------------------------------
DWORD_PTR __cdecl GetSHFileInfo(OLECHAR *lpszKeyName, DWORD dwFileAttributes, SHFILEINFOW *pFileInfo, UINT cbFileInfo, UINT uFlags)
{
  Data_t_bstr_t *v5; // esi
  const WCHAR *pszPathName; // eax
  DWORD_PTR v7; // edi
  _bstr_t bstrText; // [esp+8h] [ebp-4h]

  sub_FD7AB0(&gKeyNameMap, &bstrText, lpszKeyName);
  v5 = bstrText.m_Data;
  if ( bstrText.m_Data )
    pszPathName = bstrText.m_Data->m_wstr;
  else
    pszPathName = 0;
  v7 = SHGetFileInfoW(pszPathName, dwFileAttributes, pFileInfo, cbFileInfo, uFlags);
  if ( v5 && !InterlockedDecrement(&v5->m_RefCount) )
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
  return v7;
}

//----- (00FE1150) --------------------------------------------------------
bool __cdecl PE_GetPathName(int a1, LPCWSTR lpszSystemPath, LPCWSTR lpszPathName, CPEString *strRet)
{
  int v4; // eax
  Data_t_bstr_t *v5; // esi
  const WCHAR *v6; // eax
  WCHAR *v7; // ebx
  char v8; // bl
  const wchar_t *v9; // ecx
  CPEString strSystemPath; // edi
  bool v11; // zf
  const wchar_t *pszSystemPath; // esi
  wchar_t *pstr; // ebx
  unsigned int v14; // ecx
  LPCWSTR v15; // edx
  WCHAR v16; // ax
  size_t v17; // esi
  const WCHAR **v18; // ecx
  Data_t_bstr_t *v19; // ebx
  Data_t_bstr_t *v20; // esi
  const WCHAR *v21; // eax
  DWORD v22; // eax
  WCHAR *v24; // ebx
  tagKeyName KeyName; // [esp+14h] [ebp-18h]
  int v26; // [esp+28h] [ebp-4h]

  v4 = *lpszPathName;
  if ( v4 && lpszPathName[1] == ':' || v4 == '\\' )
  {
    sub_FD7AB0(&gKeyNameMap, &KeyName, lpszPathName);
    v5 = KeyName.bstrText1.m_Data;
    if ( KeyName.bstrText1.m_Data )
      v6 = KeyName.bstrText1.m_Data->m_wstr;
    else
      v6 = 0;
    KeyName.bstrText1.m_Data = GetFileAttributesW(v6);
    v7 = strRet->m_String;
    strRet->m_String = _wcsdup(lpszPathName);
    free(v7);
    v8 = KeyName.bstrText1.m_Data != INVALID_FILE_ATTRIBUTES && !(KeyName.bstrText1.m_Data & FILE_ATTRIBUTE_DIRECTORY);
    if ( v5 && !InterlockedDecrement(&v5->m_RefCount) )
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
  }
  else
  {
    v9 = &gszNullString;
    if ( lpszSystemPath )
      v9 = lpszSystemPath;
    strSystemPath.m_String = _wcsdup(v9);
    v11 = *strSystemPath.m_String == 0;
    pszSystemPath = strSystemPath.m_String;
    v26 = 0;
    KeyName.dwValue = strSystemPath.m_String;
    if ( v11 )
    {
LABEL_42:
      v8 = 0;
    }
    else
    {
      while ( 1 )
      {
        pstr = wcschr(pszSystemPath, ';');
        if ( pstr )
          *pstr = 0;
        v14 = wcslen(pszSystemPath);
        v15 = lpszPathName;
        do
        {
          v16 = *v15;
          ++v15;
        }
        while ( v16 );
        v17 = v15 - (lpszPathName + 1) + v14 + 2;
        KeyName.bstrText2.m_Data = malloc(2 * v17);
        swprintf_s(KeyName.bstrText2.m_Data, v17, L"%s\\%s", KeyName.dwValue, lpszPathName);
        if ( pstr )
        {
          v18 = (pstr + 1);
          *pstr = ';';
        }
        else
        {
          v18 = &gszNullString;
        }
        v19 = KeyName.bstrText2.m_Data;
        KeyName.dwValue = v18;
        sub_FD7AB0(&gKeyNameMap, &KeyName, KeyName.bstrText2.m_Data);
        v20 = KeyName.bstrText1.m_Data;
        v21 = KeyName.bstrText1.m_Data ? KeyName.bstrText1.m_Data->m_wstr : 0;
        v22 = GetFileAttributesW(v21);
        if ( v22 != -1 && !(v22 & 0x10) )
          break;
        free(v19);
        if ( v20 )
        {
          if ( !InterlockedDecrement(&v20->m_RefCount) )
          {
            if ( v20->m_wstr )
            {
              SysFreeString(v20->m_wstr);
              v20->m_wstr = 0;
            }
            if ( v20->m_str )
            {
              j_j__free(v20->m_str);
              v20->m_str = 0;
            }
            j__free(v20);
          }
          KeyName.bstrText1.m_Data = 0;
        }
        pszSystemPath = KeyName.dwValue;
        if ( !*KeyName.dwValue )
          goto LABEL_42;
      }
      v24 = strRet->m_String;
      strRet->m_String = _wcsdup(KeyName.bstrText2.m_Data);
      free(v24);
      free(KeyName.bstrText2.m_Data);
      _bstr_t::_Free(&KeyName.bstrText1);
      v8 = 1;
    }
    free(strSystemPath.m_String);
  }
  return v8;
}

//----- (00FE13D0) --------------------------------------------------------
LSTATUS __cdecl PE_LoadRegKeys(HKEY hKey, DWORD dwIndex, WCHAR **ppszKey)
{
  LSTATUS result; // eax
  DWORD v4; // eax
  size_t v5; // ebx
  WCHAR *v6; // eax
  DWORD cbMaxSubKeyLen; // [esp+0h] [ebp-4h]

  cbMaxSubKeyLen = 0;
  result = RegQueryInfoKeyW(hKey, 0, 0, 0, 0, &cbMaxSubKeyLen, 0, 0, 0, 0, 0, 0);
  if ( !result )
  {
    v4 = cbMaxSubKeyLen + 1;
    cbMaxSubKeyLen = v4;
    v5 = 2 * v4 + 2;
    v6 = realloc(*ppszKey, v5);
    *ppszKey = v6;
    if ( v6 )
      memset(v6, 0, v5);
    result = RegEnumKeyW(hKey, dwIndex, *ppszKey, cbMaxSubKeyLen);
  }
  return result;
}

//----- (00FE1450) --------------------------------------------------------
LSTATUS __cdecl PE_LoadRegValues(HKEY hKey, DWORD dwIndex, LPWSTR *ppszValueName, LPDWORD lpReserved, LPDWORD lpType, void **ppv)
{
  LSTATUS result; // eax
  size_t v7; // esi
  WCHAR *v8; // eax
  size_t v9; // esi
  void *v10; // eax
  DWORD cbMaxValueLen; // [esp+0h] [ebp-8h]
  DWORD cbMaxValueNameLen; // [esp+4h] [ebp-4h]

  cbMaxValueNameLen = 0;
  cbMaxValueLen = 0;
  result = RegQueryInfoKeyW(hKey, 0, 0, 0, 0, 0, 0, 0, &cbMaxValueNameLen, &cbMaxValueLen, 0, 0);
  if ( !result )
  {
    v7 = 2 * (cbMaxValueNameLen++ + 1) + 2;
    v8 = realloc(*ppszValueName, v7);
    *ppszValueName = v8;
    if ( v8 )
      memset(v8, 0, v7);
    v9 = 2 * (((cbMaxValueLen + 1) >> 1) + 1);
    v10 = realloc(*ppv, 2 * (((cbMaxValueLen + 1) >> 1) + 1));
    *ppv = v10;
    if ( v10 )
      memset(v10, 0, v9);
    result = RegEnumValueW(hKey, dwIndex, *ppszValueName, &cbMaxValueNameLen, lpReserved, lpType, *ppv, &cbMaxValueLen);
  }
  return result;
}

//----- (00FE1520) --------------------------------------------------------
LSTATUS __cdecl PE_ReadRegKey(HKEY hKey, LPCWSTR lpValueName, LPDWORD lpReserved, LPDWORD lpType, void **ppv)
{
  LSTATUS result; // eax
  void *v6; // eax
  DWORD nLength; // [esp+0h] [ebp-8h]
  DWORD cbData; // [esp+4h] [ebp-4h]

  cbData = 0;
  result = RegQueryValueExW(hKey, lpValueName, lpReserved, 0, 0, &cbData);
  if ( !result )
  {
    nLength = 2 * (((cbData + 1) >> 1) + 1);
    v6 = realloc(*ppv, 2 * (((cbData + 1) >> 1) + 1));
    *ppv = v6;
    if ( v6 )
      memset(v6, 0, nLength);
    result = RegQueryValueExW(hKey, lpValueName, lpReserved, lpType, *ppv, &cbData);
  }
  return result;
}

//----- (00FE15A0) --------------------------------------------------------
LSTATUS __cdecl PE_LoadStrKey(HKEY hKey, LPCWSTR lpSubKey, WCHAR **ppszValues)
{
  LSTATUS result; // eax
  WCHAR *v4; // eax
  unsigned int v5; // [esp+0h] [ebp-8h]
  LONG cbData; // [esp+4h] [ebp-4h]

  cbData = 0;
  result = RegQueryValueW(hKey, lpSubKey, 0, &cbData);
  if ( !result )
  {
    v5 = 2 * (((cbData + 1) >> 1) + 1);
    v4 = realloc(*ppszValues, 2 * (((cbData + 1) >> 1) + 1));
    *ppszValues = v4;
    if ( v4 )
      memset(v4, 0, v5);
    result = RegQueryValueW(hKey, lpSubKey, *ppszValues, &cbData);
  }
  return result;
}

//----- (00FE1610) --------------------------------------------------------
HANDLE __cdecl sub_FE1610(int arg0, void *hKey, wchar_t *psz)
{
  DWORD v3; // ebx
  _WORD *v4; // eax
  WCHAR *v5; // eax
  WCHAR *v6; // eax
  WCHAR *v7; // eax
  _WORD *v8; // eax
  _WORD *v9; // eax
  WCHAR *v10; // eax
  _WORD *v11; // eax
  const wchar_t *v12; // eax
  const wchar_t *v13; // eax
  CPEString *v14; // esi
  CPEString *v15; // eax
  HANDLE v16; // esi
  LSTATUS (__stdcall *RegQueryValueExW)(HKEY, LPCWSTR, LPDWORD, LPDWORD, LPBYTE, LPDWORD); // esi
  LSTATUS v18; // eax
  void *v19; // esi
  CPEString *v20; // eax
  CPEString *v21; // eax
  void *v22; // esi
  const wchar_t **v23; // eax
  WCHAR *v24; // esi
  HMODULE v25; // eax
  int (__stdcall *v26)(HKEY, LPCWSTR, LPWSTR, DWORD, LPDWORD, DWORD, LPCWSTR); // eax
  size_t v27; // esi
  void *v28; // eax
  WCHAR *v29; // esi
  const wchar_t *v30; // eax
  const wchar_t *v31; // eax
  CPEString *v32; // esi
  CPEString *v33; // eax
  char v34; // bl
  const wchar_t *v35; // eax
  const wchar_t *v36; // eax
  CPEString *v37; // esi
  CPEString *v38; // eax
  const wchar_t *v39; // eax
  CPEString *v40; // eax
  BYTE v42; // [esp+10h] [ebp-2C4h]
  void *v43; // [esp+14h] [ebp-2C0h]
  BYTE v44[4]; // [esp+18h] [ebp-2BCh]
  BYTE Data[4]; // [esp+1Ch] [ebp-2B8h]
  CPEString v46; // [esp+20h] [ebp-2B4h]
  CPEString str; // [esp+24h] [ebp-2B0h]
  DWORD dwValue; // [esp+28h] [ebp-2ACh]
  CPEString v49; // [esp+2Ch] [ebp-2A8h]
  int v50; // [esp+30h] [ebp-2A4h]
  CPEString pszResult; // [esp+34h] [ebp-2A0h]
  CPEString v52; // [esp+38h] [ebp-29Ch]
  CPEString v53; // [esp+3Ch] [ebp-298h]
  CPEString v54; // [esp+40h] [ebp-294h]
  void *v55; // [esp+44h] [ebp-290h]
  void *v56; // [esp+48h] [ebp-28Ch]
  void *v57; // [esp+4Ch] [ebp-288h]
  WCHAR *ppv3; // [esp+50h] [ebp-284h]
  CPEString strResult; // [esp+54h] [ebp-280h]
  void *v60; // [esp+58h] [ebp-27Ch]
  HANDLE Handle; // [esp+5Ch] [ebp-278h]
  CPEString v62; // [esp+60h] [ebp-274h]
  HKEY KeyHandle; // [esp+64h] [ebp-270h]
  DWORD v64; // [esp+68h] [ebp-26Ch]
  CPEString v65; // [esp+6Ch] [ebp-268h]
  CPEString strKeyName; // [esp+70h] [ebp-264h]
  CPEString v67; // [esp+74h] [ebp-260h]
  CPEString v68; // [esp+78h] [ebp-25Ch]
  CPEString str1; // [esp+7Ch] [ebp-258h]
  CPEString v70; // [esp+80h] [ebp-254h]
  CPEString v71; // [esp+84h] [ebp-250h]
  CPEString v72; // [esp+88h] [ebp-24Ch]
  CPEString strValueName; // [esp+8Ch] [ebp-248h]
  CPEString str3; // [esp+90h] [ebp-244h]
  CPEString v75; // [esp+94h] [ebp-240h]
  int a1; // [esp+98h] [ebp-23Ch]
  void *v77; // [esp+9Ch] [ebp-238h]
  void *ppv; // [esp+A0h] [ebp-234h]
  CPEString v79; // [esp+A4h] [ebp-230h]
  HKEY v80; // [esp+A8h] [ebp-22Ch]
  DWORD cbData; // [esp+ACh] [ebp-228h]
  void *v82; // [esp+B0h] [ebp-224h]
  HKEY Hkey; // [esp+B4h] [ebp-220h]
  WCHAR *ppszKey; // [esp+B8h] [ebp-21Ch]
  wchar_t pszOutBuf; // [esp+BCh] [ebp-218h]
  int v86; // [esp+2D0h] [ebp-4h]

  v3 = 0;
  a1 = arg0;
  v80 = hKey;
  v64 = 0;
  v4 = malloc(2u);
  ppv = v4;
  *v4 = 0;
  v86 = 0;
  v5 = malloc(2u);
  ppszKey = v5;
  *v5 = 0;
  v6 = malloc(2u);
  str1.m_String = v6;
  *v6 = 0;
  v7 = malloc(2u);
  v79.m_String = v7;
  *v7 = 0;
  v8 = malloc(2u);
  v60 = v8;
  *v8 = 0;
  v9 = malloc(2u);
  v82 = v9;
  *v9 = 0;
  v10 = malloc(2u);
  ppv3 = v10;
  *v10 = 0;
  v11 = malloc(2u);
  v77 = v11;
  *v11 = 0;
  v72.m_String = _wcsdup(&gszNullString);
  v65.m_String = _wcsdup(&gszNullString);
  v67.m_String = _wcsdup(&gszNullString);
  v75.m_String = _wcsdup(&gszNullString);
  v71.m_String = _wcsdup(&gszNullString);
  str3.m_String = _wcsdup(&gszNullString);
  strValueName.m_String = _wcsdup(&gszNullString);
  v12 = &gszNullString;
  if ( psz )
    v12 = psz;
  strKeyName.m_String = _wcsdup(v12);
  v70.m_String = _wcsdup(&gszNullString);
  v13 = &gszNullString;
  if ( psz )
    v13 = psz;
  v68.m_String = _wcsdup(v13);
  LOBYTE(v86) = 17;
  v14 = MakeRegistryKeyName(&strResult, hKey, &strKeyName, &strValueName);
  LOBYTE(v86) = 18;
  v15 = MakeRegistryKeyName(&v62, v80, &v68, &v70);
  LOBYTE(v86) = 19;
  v16 = sub_FD3FF0(a1, 0, 0xFFFFFFFF, 0, v15, v14, &str3);
  Handle = v16;
  free(v62.m_String);
  free(strResult.m_String);
  free(v68.m_String);
  free(v70.m_String);
  free(strKeyName.m_String);
  free(strValueName.m_String);
  free(str3.m_String);
  free(v71.m_String);
  free(v75.m_String);
  free(v67.m_String);
  free(v65.m_String);
  LOBYTE(v86) = 7;
  free(v72.m_String);
  if ( !PE_OpenKey(ghLocalMachineKey, psz, 0, 0x20019u, &KeyHandle) )
  {
    if ( !PE_LoadRegKeys(KeyHandle, 0, &ppszKey) )
    {
      RegQueryValueExW = ::RegQueryValueExW;
      do
      {
        if ( !PE_OpenKey(KeyHandle, ppszKey, 0, 0x20019u, &Hkey) )
        {
          cbData = 4;
          if ( !RegQueryValueExW(Hkey, L"Type", 0, 0, Data, &cbData) && *Data <= 2u )
          {
            cbData = 4;
            if ( !RegQueryValueExW(Hkey, L"Start", 0, 0, v44, &cbData) )
            {
              cbData = 4;
              if ( *v44 != 4 || !RegQueryValueExW(Hkey, L"AutorunsDisabled", 0, 0, &v42, &cbData) )
              {
                v18 = PE_ReadRegKey(Hkey, L"ImagePath", 0, 0, &ppv);
                v19 = v77;
                if ( v18 )
                {
                  v77 = _wcsdup(ppszKey);
                  free(v19);
                  v20 = operator+(&pszResult, L"\\SystemRoot\\System32\\Drivers\\", &ppszKey);
                  v21 = CPEString::Append(&str, v20, L".sys");
                  v22 = ppv;
                  ppv = _wcsdup(v21->m_String);
                  free(v22);
                  free(str.m_String);
                  free(pszResult.m_String);
                }
                else
                {
                  v77 = _wcsdup(ppv);
                  free(v19);
                }
                v23 = sub_FD4F20(&v43, a1, ppv);
                v24 = v79.m_String;
                v79.m_String = _wcsdup(*v23);
                free(v24);
                free(v43);
                dwValue = sub_FD4ED0();
                PE_ReadRegKey(Hkey, L"Description", 0, 0, &v82);
                if ( *v82 == 64 )
                {
                  v25 = LoadLibraryW(L"Advapi32.dll");
                  v26 = GetProcAddress(v25, "RegLoadMUIStringW");
                  RegLoadMUIStringW = v26;
                  if ( v26 )
                  {
                    if ( !(v26)() )
                    {
                      v27 = 2 * cbData + 4;
                      v28 = realloc(v82, v27);
                      v82 = v28;
                      if ( v28 )
                      {
                        memset(v28, 0, v27);
                        v28 = v82;
                      }
                      wcscpy_s(&pszOutBuf, v28, cbData + 1);
                    }
                  }
                }
                v29 = str1.m_String;
                str1.m_String = _wcsdup(ppszKey);
                free(v29);
                v30 = &gszNullString;
                if ( psz )
                  v30 = psz;
                v67.m_String = _wcsdup(v30);
                v65.m_String = _wcsdup(&gszNullString);
                v31 = &gszNullString;
                if ( psz )
                  v31 = psz;
                v72.m_String = _wcsdup(v31);
                LOBYTE(v86) = 22;
                v32 = MakeRegistryKeyName(&v54, v80, &v67, &ppszKey);
                LOBYTE(v86) = 23;
                v33 = MakeRegistryKeyName(&v49, v80, &v72, &v65);
                LOBYTE(v86) = 24;
                v34 = sub_FD3D40(a1, v33, v32, &str1, &v79, &v60, &ppv3, &v50);
                free(v49.m_String);
                free(v54.m_String);
                free(v72.m_String);
                free(v65.m_String);
                LOBYTE(v86) = 7;
                free(v67.m_String);
                if ( v34 )
                {
                  if ( Handle == -1 )
                  {
                    v57 = _wcsdup(&gszNullString);
                    v56 = _wcsdup(&gszNullString);
                    v55 = _wcsdup(&gszNullString);
                    v68.m_String = _wcsdup(&gszNullString);
                    v70.m_String = _wcsdup(&gszNullString);
                    strKeyName.m_String = _wcsdup(&gszNullString);
                    strValueName.m_String = _wcsdup(&gszNullString);
                    v35 = &gszNullString;
                    if ( psz )
                      v35 = psz;
                    str3.m_String = _wcsdup(v35);
                    v71.m_String = _wcsdup(&gszNullString);
                    v36 = &gszNullString;
                    if ( psz )
                      v36 = psz;
                    v75.m_String = _wcsdup(v36);
                    LOBYTE(v86) = 34;
                    v37 = MakeRegistryKeyName(&v52, v80, &str3, &strValueName);
                    LOBYTE(v86) = 35;
                    v38 = MakeRegistryKeyName(&v53, v80, &v75, &v71);
                    LOBYTE(v86) = 36;
                    Handle = sub_FD3FF0(a1, 0, 0xFFFFFFFF, 0, v38, v37, &strKeyName);
                    free(v53.m_String);
                    free(v52.m_String);
                    free(v75.m_String);
                    free(v71.m_String);
                    free(str3.m_String);
                    free(strValueName.m_String);
                    free(strKeyName.m_String);
                    free(v70.m_String);
                    free(v68.m_String);
                    free(v55);
                    free(v56);
                    free(v57);
                  }
                  v62.m_String = _wcsdup(&gszNullString);
                  v39 = &gszNullString;
                  if ( psz )
                    v39 = psz;
                  strResult.m_String = _wcsdup(v39);
                  LOBYTE(v86) = 38;
                  v40 = MakeRegistryKeyName(&v46, v80, &strResult, &ppszKey);
                  LOBYTE(v86) = 39;
                  sub_FD3FF0(a1, dwValue, Handle, 13u, &str1, v40, &v79);
                  free(v46.m_String);
                  free(strResult.m_String);
                  LOBYTE(v86) = 7;
                  free(v62.m_String);
                }
                RegQueryValueExW = ::RegQueryValueExW;
                v3 = v64;
              }
            }
          }
          RegCloseKey(Hkey);
        }
        v64 = ++v3;
      }
      while ( !PE_LoadRegKeys(KeyHandle, v3, &ppszKey) );
      v16 = Handle;
    }
    RegCloseKey(KeyHandle);
  }
  free(v77);
  free(ppv3);
  free(v82);
  free(v60);
  free(v79.m_String);
  free(str1.m_String);
  free(ppszKey);
  free(ppv);
  return v16;
}

//----- (00FE2060) --------------------------------------------------------
void *__cdecl sub_FE2060(int a1, int a2, int *a3)
{
  void *v3; // eax

  v3 = sub_FE2090(a1, a2, *a3, 0xFFFFFFFF, 1);
  return sub_FE2090(a1, a2, *a3, v3, 0);
}

//----- (00FE2090) --------------------------------------------------------
void *__cdecl sub_FE2090(int a1, int a2, int a3, void *a4, char a5)
{
  wchar_t *v5; // edi
  const wchar_t *v6; // ecx
  const WCHAR **v7; // eax
  wchar_t *v8; // esi
  CPEString *v9; // eax
  CPEString *v10; // eax
  void *v11; // ebx
  WCHAR *v12; // ebx
  unsigned int v13; // eax
  void (__stdcall *v14)(HKEY); // esi
  WCHAR *v15; // ebx
  _WORD *v16; // eax
  WCHAR *v17; // eax
  WCHAR *v18; // esi
  _WORD *v19; // eax
  WCHAR *v20; // eax
  WCHAR *v21; // edi
  WCHAR *v22; // ebx
  CPEString *v23; // eax
  CPEString *v24; // eax
  CPEString *v25; // eax
  CPEString *v26; // eax
  WCHAR *v27; // ebx
  int v28; // ebx
  CPEString *v29; // eax
  int v30; // ebx
  void **v31; // ebx
  int v32; // esi
  unsigned int v33; // eax
  LSTATUS v34; // eax
  const WCHAR *v35; // esi
  unsigned int v36; // eax
  void *v37; // esi
  wchar_t *v38; // eax
  void *v39; // esi
  WCHAR *v40; // esi
  unsigned int v41; // eax
  LSTATUS v42; // eax
  int v43; // ebx
  const WCHAR *v44; // esi
  unsigned int v45; // eax
  CPEString *v46; // eax
  CPEString *v47; // eax
  CPEString *v48; // eax
  CPEString *v49; // eax
  CPEString *v50; // eax
  wchar_t *v51; // esi
  const wchar_t **v52; // eax
  WCHAR *v53; // esi
  tagPEStringStruct *v54; // ecx
  const wchar_t **v55; // eax
  WCHAR *v56; // esi
  CPEString *v57; // eax
  CPEString *v58; // eax
  CPEString *v59; // eax
  CPEString *v60; // eax
  void *v61; // esi
  int v63; // [esp+10h] [ebp-118h]
  int a2a; // [esp+20h] [ebp-108h]
  HKEY v65; // [esp+24h] [ebp-104h]
  wchar_t *v66; // [esp+28h] [ebp-100h]
  CPEString v67; // [esp+2Ch] [ebp-FCh]
  int v68; // [esp+30h] [ebp-F8h]
  CPEString v69; // [esp+34h] [ebp-F4h]
  WCHAR *ppv1; // [esp+38h] [ebp-F0h]
  HKEY KeyHandle; // [esp+3Ch] [ebp-ECh]
  CPEString v72; // [esp+40h] [ebp-E8h]
  CPEString v73; // [esp+44h] [ebp-E4h]
  wchar_t *psz; // [esp+48h] [ebp-E0h]
  tagPEStringStruct v75; // [esp+4Ch] [ebp-DCh]
  WCHAR *ppv3; // [esp+68h] [ebp-C0h]
  void *v77; // [esp+6Ch] [ebp-BCh]
  DWORD dwValue; // [esp+70h] [ebp-B8h]
  void *v79; // [esp+74h] [ebp-B4h]
  WCHAR v80[2]; // [esp+78h] [ebp-B0h]
  void *v81; // [esp+7Ch] [ebp-ACh]
  void *v82; // [esp+80h] [ebp-A8h]
  int a1a; // [esp+84h] [ebp-A4h]
  WCHAR *v84; // [esp+88h] [ebp-A0h]
  HKEY hRootKey; // [esp+8Ch] [ebp-9Ch]
  void *v86; // [esp+90h] [ebp-98h]
  HKEY__ v87; // [esp+94h] [ebp-94h]
  WCHAR *ppv; // [esp+98h] [ebp-90h]
  CPEString v89; // [esp+9Ch] [ebp-8Ch]
  CPEString v90; // [esp+A0h] [ebp-88h]
  CPEString str; // [esp+A4h] [ebp-84h]
  void *v92; // [esp+A8h] [ebp-80h]
  CPEString v93; // [esp+ACh] [ebp-7Ch]
  HKEY__ v94; // [esp+B0h] [ebp-78h]
  CPEString v95; // [esp+B4h] [ebp-74h]
  CPEString v96; // [esp+B8h] [ebp-70h]
  CPEString v97; // [esp+BCh] [ebp-6Ch]
  HKEY__ v98; // [esp+C0h] [ebp-68h]
  HKEY hKey; // [esp+C4h] [ebp-64h]
  LPCWSTR lpAppName; // [esp+C8h] [ebp-60h]
  HKEY__ v101; // [esp+CCh] [ebp-5Ch]
  LPCWSTR v102; // [esp+D0h] [ebp-58h]
  CPEString str3; // [esp+D4h] [ebp-54h]
  LPCWSTR lpFileName; // [esp+D8h] [ebp-50h]
  WCHAR KeyName; // [esp+DCh] [ebp-4Ch]
  int v106; // [esp+124h] [ebp-4h]

  a1a = a1;
  hRootKey = a2;
  psz = a3;
  hKey = 0;
  v102 = malloc(2u);
  *v102 = 0;
  v106 = 0;
  v5 = malloc(2u);
  v66 = v5;
  *v5 = 0;
  v101.unused = malloc(2u);
  *v101.unused = 0;
  lpAppName = malloc(2u);
  *lpAppName = 0;
  *v80 = malloc(2u);
  **v80 = 0;
  v75.strValue[4] = malloc(2u);
  *v75.strValue[4] = 0;
  v98.unused = malloc(2u);
  *v98.unused = 0;
  v87.unused = malloc(2u);
  *v87.unused = 0;
  v92 = malloc(2u);
  *v92 = 0;
  v82 = malloc(2u);
  *v82 = 0;
  v90.m_String = malloc(2u);
  v97.m_String = v90.m_String;
  *v90.m_String = 0;
  v84 = malloc(2u);
  *v84 = 0;
  v6 = L"HKCU";
  LOBYTE(v106) = 11;
  if ( a2 != ghCurrentUserKey )
    v6 = L"HKLM";
  v7 = &gszNullString;
  if ( v6 )
    v7 = v6;
  v8 = _wcsdup(v7);
  v94.unused = v8;
  v9 = CPEString::Append(&ppv, &v94, L"\\");
  v10 = CPEString::Append(&str, v9, psz);
  v11 = v101.unused;
  v101.unused = _wcsdup(v10->m_String);
  free(v11);
  free(str.m_String);
  free(ppv);
  free(v8);
  if ( a4 == -1 )
  {
    v96.m_String = _wcsdup(&gszNullString);
    v95.m_String = _wcsdup(&gszNullString);
    v89.m_String = _wcsdup(&gszNullString);
    v93.m_String = _wcsdup(&gszNullString);
    lpFileName = _wcsdup(&gszNullString);
    str3.m_String = _wcsdup(&gszNullString);
    LOBYTE(v106) = 17;
    a4 = sub_FD3FF0(a1a, 0, 0xFFFFFFFF, 0, &v101, &v101, &str3);
    free(str3.m_String);
    free(lpFileName);
    free(v93.m_String);
    free(v89.m_String);
    free(v95.m_String);
    LOBYTE(v106) = 11;
    free(v96.m_String);
  }
  v12 = _wcsdup(psz);
  v97.m_String = v12;
  free(v90.m_String);
  if ( !a5 )
  {
    CPEString::InsertAt(&v97, L"\\AutorunsDisabled", 0x7FFFFFFFu, 0);
    v12 = v97.m_String;
  }
  v13 = TlsGetValue(gdwTlsIndex);
  v14 = RegCloseKey;
  if ( !PE_OpenKey(hRootKey, v12, 0, v13 | 0x20019, &hKey) )
  {
    v94.unused = 0;
    if ( !PE_LoadRegValues(hKey, 0, &lpAppName, 0, 0, &v98) )
    {
      do
      {
        CPEString::Append(&lpFileName, &v98, L"\\Scripts.Ini");
        if ( GetFileAttributesW(lpFileName) == -1 )
        {
          LOBYTE(v106) = 11;
          free(lpFileName);
        }
        else
        {
          v15 = 0;
          while ( 1 )
          {
            str.m_String = v15;
            _swprintf(&KeyName, L"%dCmdLine", v15);
            v16 = malloc(2u);
            *v16 = 0;
            v17 = realloc(v16, 0x412u);
            v18 = v17;
            ppv = v17;
            if ( v17 )
              memset(v17, 0, 0x412u);
            dwValue = GetPrivateProfileStringW(lpAppName, &KeyName, &gszNullString, v18, 0x208u, lpFileName);
            if ( !dwValue )
              break;
            _swprintf(&KeyName, L"%dParameters", v15);
            v19 = malloc(2u);
            *v19 = 0;
            v20 = realloc(v19, 0x412u);
            v21 = v20;
            ppv3 = v20;
            if ( v20 )
              memset(v20, 0, 0x412u);
            GetPrivateProfileStringW(lpAppName, &KeyName, &gszNullString, v21, 0x208u, lpFileName);
            if ( dwValue > 2 && (!wcsncmp(v18, L"\\\\", 2u) || v18[1] == 58) )
            {
              v22 = v102;
              v102 = _wcsdup(v18);
              free(v22);
            }
            else
            {
              v23 = CPEString::Append(&v72, &v98, L"\\");
              v24 = CPEString::Append(&ppv1, v23, &lpAppName);
              v25 = CPEString::Append(&v73, v24, L"\\");
              v26 = CPEString::Append(&v67, v25, &ppv);
              v27 = v102;
              v102 = _wcsdup(v26->m_String);
              free(v27);
              free(v67.m_String);
              free(v73.m_String);
              free(ppv1);
              free(v72.m_String);
            }
            if ( GetFileAttributesW(v102) == -1 )
            {
              free(v21);
              free(v18);
              v15 = (str.m_String + 1);
            }
            else
            {
              v75.strValue[0] = malloc(2u);
              *v75.strValue[0] = 0;
              v75.strValue[1] = 0;
              v75.strValue[2] = 0;
              v75.strValue[3] = 0;
              LOBYTE(v106) = 21;
              sub_FD7040(v102, &v75);
              v28 = a1a;
              sub_FD4EE0(&str3, a1a, &v75, 0);
              LOBYTE(v106) = 22;
              dwValue = sub_FD4ED0();
              v29 = CPEString::Append(&v69, &v102, L" ");
              CPEString::Append(&v90, v29, &ppv3);
              free(v69.m_String);
              v96.m_String = _wcsdup(&KeyName);
              LOBYTE(v106) = 24;
              LOBYTE(v28) = sub_FD3D40(v28, &v101, &v96, &v90, &str3, &v92, &v84, &v68);
              free(v96.m_String);
              if ( v28 )
              {
                if ( a4 == -1 )
                {
                  v79 = _wcsdup(&gszNullString);
                  v77 = _wcsdup(&gszNullString);
                  v81 = _wcsdup(&gszNullString);
                  v93.m_String = _wcsdup(&gszNullString);
                  v89.m_String = _wcsdup(&gszNullString);
                  v95.m_String = _wcsdup(&gszNullString);
                  v30 = a1a;
                  LOBYTE(v106) = 30;
                  a4 = sub_FD3FF0(a1a, 0, 0xFFFFFFFF, 0, &v101, &v101, &v95);
                  free(v95.m_String);
                  free(v89.m_String);
                  free(v93.m_String);
                  free(v81);
                  free(v77);
                  free(v79);
                }
                else
                {
                  v30 = a1a;
                }
                v86 = _wcsdup(&gszNullString);
                v75.strValue[6] = _wcsdup(&KeyName);
                LOBYTE(v106) = 32;
                sub_FD3FF0(v30, dwValue, a4, 0xAu, &v75.strValue[6], &v102, &str3);
                free(v75.strValue[6]);
                free(v86);
              }
              free(v90.m_String);
              free(str3.m_String);
              v31 = v75.strValue[1];
              if ( v75.strValue[1] )
              {
                if ( v75.strValue[1] != v75.strValue[2] )
                {
                  v32 = v75.strValue[2];
                  do
                  {
                    free(*v31);
                    ++v31;
                  }
                  while ( v31 != v32 );
                  v31 = v75.strValue[1];
                  v18 = ppv;
                }
                j__free(v31);
                v75.strValue[1] = 0;
                v75.strValue[2] = 0;
                v75.strValue[3] = 0;
              }
              free(v75.strValue[0]);
              free(v21);
              free(v18);
              v15 = (str.m_String + 1);
            }
          }
          free(v18);
          LOBYTE(v106) = 11;
          free(lpFileName);
        }
        ++v94.unused;
      }
      while ( !PE_LoadRegValues(hKey, v94.unused, &lpAppName, 0, 0, &v98) );
      v12 = v97.m_String;
      v5 = v66;
      v14 = RegCloseKey;
    }
    v14(hKey);
  }
  v33 = TlsGetValue(gdwTlsIndex);
  if ( PE_OpenKey(hRootKey, psz, 0, v33 | 0x20019, &hKey) )
    goto LABEL_74;
  v81 = 0;
  v34 = PE_LoadRegKeys(hKey, 0, &lpAppName);
  if ( v34 == 259 )
    goto LABEL_73;
  while ( !v34 )
  {
    v35 = lpAppName;
    v36 = TlsGetValue(gdwTlsIndex);
    if ( !PE_OpenKey(hKey, v35, 0, v36 | 0x20019, &KeyHandle) )
    {
      str3.m_String = malloc(2u);
      *str3.m_String = 0;
      LOBYTE(v106) = 33;
      if ( PE_ReadRegKey(KeyHandle, L"DisplayName", 0, 0, &str3.m_String) )
        goto LABEL_69;
      v37 = v87.unused;
      v87.unused = _wcsdup(&gszNullString);
      free(v37);
      PE_ReadRegKey(KeyHandle, L"FileSysPath", 0, 0, &v87);
      v38 = wcsrchr(psz, 0x5Cu);
      v39 = v75.strValue[4];
      v75.strValue[4] = _wcsdup(v38);
      free(v39);
      v40 = v12;
      v12 = _wcsdup(lpAppName);
      v97.m_String = v12;
      free(v40);
      if ( !a5 )
      {
        CPEString::InsertAt(&v97, L"\\AutorunsDisabled", 0x7FFFFFFFu, 0);
        v12 = v97.m_String;
      }
      v41 = TlsGetValue(gdwTlsIndex);
      if ( !PE_OpenKey(hKey, v12, 0, v41 | 0x20019, &v75.strValue[5]) )
      {
        v77 = 0;
        v42 = PE_LoadRegKeys(v75.strValue[5], 0, v80);
        if ( v42 != 259 )
        {
          v43 = a1a;
          do
          {
            if ( v42 )
              break;
            v44 = *v80;
            v45 = TlsGetValue(gdwTlsIndex);
            if ( !PE_OpenKey(v75.strValue[5], v44, 0, v45 | 0x20019, &v65) )
            {
              if ( !PE_ReadRegKey(v65, L"Script", 0, 0, &v102) )
              {
                lpFileName = malloc(2u);
                *lpFileName = 0;
                if ( *v87.unused && *v102 != 92 && v102[1] != 58 )
                {
                  v46 = CPEString::Append(&v73, &v87, L"\\");
                  v47 = CPEString::Append(&ppv1, v46, L"Scripts");
                  v48 = CPEString::Append(&v72, v47, &v75.strValue[4]);
                  v49 = CPEString::Append(&ppv3, v48, L"\\");
                  v50 = CPEString::Append(&v69, v49, &v102);
                  v51 = v5;
                  v5 = _wcsdup(v50->m_String);
                  v66 = v5;
                  free(v51);
                  free(v69.m_String);
                  free(ppv3);
                  free(v72.m_String);
                  free(ppv1);
                  free(v73.m_String);
                  sub_FD2170(&v63);
                  LOBYTE(v106) = 35;
                  sub_FD7040(v5, &v63);
                  v52 = sub_FD4EE0(&v67, v43, &v63, 0);
                  v53 = lpFileName;
                  lpFileName = _wcsdup(*v52);
                  free(v53);
                  free(v67.m_String);
                  v54 = &v63;
                }
                else
                {
                  v75.strValue[0] = malloc(2u);
                  *v75.strValue[0] = 0;
                  v75.strValue[1] = 0;
                  v75.strValue[2] = 0;
                  v75.strValue[3] = 0;
                  LOBYTE(v106) = 36;
                  sub_FD7040(v102, &v75);
                  v55 = sub_FD4EE0(&dwValue, v43, &v75, 0);
                  v56 = lpFileName;
                  lpFileName = _wcsdup(*v55);
                  free(v56);
                  free(dwValue);
                  v54 = &v75;
                }
                LOBYTE(v106) = 34;
                sub_FD21F0(v54);
                a2a = sub_FD4ED0();
                v57 = CPEString::Append(&v93, &v101, L"\\");
                v58 = CPEString::Append(&v89, v57, &lpAppName);
                v59 = CPEString::Append(&v95, v58, L"\\");
                v60 = CPEString::Append(&v96, v59, v80);
                v61 = v98.unused;
                v98.unused = _wcsdup(v60->m_String);
                free(v61);
                free(v96.m_String);
                free(v95.m_String);
                free(v89.m_String);
                free(v93.m_String);
                if ( sub_FD3D40(v43, &v101, &v98, &str3, &lpFileName, &v92, &v84, &v68) )
                {
                  if ( a4 == -1 )
                  {
                    v86 = _wcsdup(&gszNullString);
                    v90.m_String = _wcsdup(&gszNullString);
                    ppv = _wcsdup(&gszNullString);
                    str.m_String = _wcsdup(&gszNullString);
                    v94.unused = _wcsdup(&gszNullString);
                    hRootKey = _wcsdup(&gszNullString);
                    LOBYTE(v106) = 42;
                    a4 = sub_FD3FF0(v43, 0, 0xFFFFFFFF, 0, &v101, &v101, &hRootKey);
                    free(hRootKey);
                    free(v94.unused);
                    free(str.m_String);
                    free(ppv);
                    free(v90.m_String);
                    free(v86);
                  }
                  v79 = _wcsdup(&gszNullString);
                  v75.strValue[6] = _wcsdup(&gszNullString);
                  LOBYTE(v106) = 44;
                  sub_FD3FF0(v43, a2a, a4, 3u, &str3, &v98, &lpFileName);
                  free(v75.strValue[6]);
                  free(v79);
                }
                LOBYTE(v106) = 33;
                free(lpFileName);
              }
              RegCloseKey(v65);
            }
            v77 = v77 + 1;
            v42 = PE_LoadRegKeys(v75.strValue[5], v77, v80);
          }
          while ( v42 != 259 );
          v12 = v97.m_String;
        }
        RegCloseKey(v75.strValue[5]);
LABEL_69:
        RegCloseKey(KeyHandle);
      }
      LOBYTE(v106) = 11;
      free(str3.m_String);
    }
    v81 = v81 + 1;
    v34 = PE_LoadRegKeys(hKey, v81, &lpAppName);
    if ( v34 == 259 )
      break;
  }
  v14 = RegCloseKey;
LABEL_73:
  v14(hKey);
LABEL_74:
  free(v84);
  free(v12);
  free(v82);
  free(v92);
  free(v87.unused);
  free(v98.unused);
  free(v75.strValue[4]);
  free(*v80);
  free(lpAppName);
  free(v101.unused);
  free(v5);
  free(v102);
  return a4;
}

//----- (00FE3070) --------------------------------------------------------
CPEString *__cdecl CPEString::Append(CPEString *ppv, CPEString *lpszText1, CPEString *lpszText2)
{
  ppv->m_String = _wcsdup(lpszText1->m_String);
  CPEString::InsertAt(ppv, lpszText2->m_String, -0x80000001, 0);
  return ppv;
}

//----- (00FE30B0) --------------------------------------------------------
void __cdecl sub_FE30B0(int a1, void *a2, void *a3)
{
  _WORD *v3; // ST50_4
  CPEString *v4; // esi
  void *v5; // edi
  CPEString *v6; // eax
  wchar_t *v7; // ST54_4

  v3 = malloc(2u);
  *v3 = 0;
  v4 = a3;
  v5 = sub_FE3160(a1, a2, *a3, 0xFFFFFFFF);
  v6 = CPEString::Append(&a3, v4, L"\\AutorunsDisabled");
  v7 = _wcsdup(v6->m_String);
  free(v3);
  free(a3);
  sub_FE3160(a1, a2, v7, v5);
  free(v7);
}

//----- (00FE3160) --------------------------------------------------------
void *__cdecl sub_FE3160(int a1, void *a2, wchar_t *psz, void *a4)
{
  const wchar_t *v4; // eax
  const wchar_t *v5; // eax
  CPEString *v6; // esi
  CPEString *v7; // eax
  unsigned int v8; // eax
  void (__stdcall *v9)(HKEY); // ebx
  const WCHAR *v10; // esi
  unsigned int v11; // eax
  CPEString *v12; // eax
  CPEString *v13; // eax
  WCHAR *v14; // esi
  CPEString *v15; // eax
  WCHAR *v16; // esi
  const WCHAR *v17; // esi
  unsigned int v18; // eax
  WCHAR *v19; // esi
  const wchar_t **v20; // eax
  WCHAR *v21; // esi
  const wchar_t *v22; // ecx
  const wchar_t *v23; // eax
  CPEString *v24; // esi
  CPEString *v25; // eax
  char v26; // bl
  const wchar_t *v27; // eax
  const wchar_t *v28; // eax
  HKEY v29; // ebx
  CPEString *v30; // esi
  CPEString *v31; // eax
  const wchar_t *v32; // eax
  CPEString *v33; // eax
  DWORD v34; // esi
  tagPEStringStruct v36; // [esp+10h] [ebp-B0h]
  WCHAR *ppv; // [esp+2Ch] [ebp-94h]
  WCHAR v38[2]; // [esp+30h] [ebp-90h]
  int v39; // [esp+34h] [ebp-8Ch]
  void *v40; // [esp+38h] [ebp-88h]
  WCHAR v41[2]; // [esp+3Ch] [ebp-84h]
  WCHAR v42[2]; // [esp+40h] [ebp-80h]
  WCHAR *pszResult; // [esp+44h] [ebp-7Ch]
  CPEString str3; // [esp+48h] [ebp-78h]
  int a2a; // [esp+4Ch] [ebp-74h]
  LPCWSTR v46; // [esp+50h] [ebp-70h]
  void *v47; // [esp+54h] [ebp-6Ch]
  LPCWSTR v48; // [esp+58h] [ebp-68h]
  void *v49; // [esp+5Ch] [ebp-64h]
  LPCWSTR v50; // [esp+60h] [ebp-60h]
  LPCWSTR v51; // [esp+64h] [ebp-5Ch]
  void *v52; // [esp+68h] [ebp-58h]
  void *v53; // [esp+6Ch] [ebp-54h]
  void *v54; // [esp+70h] [ebp-50h]
  WCHAR *ppv3; // [esp+74h] [ebp-4Ch]
  void *v56; // [esp+78h] [ebp-48h]
  HKEY KeyHandle; // [esp+7Ch] [ebp-44h]
  void *a1a; // [esp+80h] [ebp-40h]
  WCHAR szArg[2]; // [esp+84h] [ebp-3Ch]
  void *v60; // [esp+88h] [ebp-38h]
  LPCWSTR szKeyName; // [esp+8Ch] [ebp-34h]
  LPCWSTR szArg3; // [esp+90h] [ebp-30h]
  LPCWSTR v63; // [esp+94h] [ebp-2Ch]
  LPCWSTR v64; // [esp+98h] [ebp-28h]
  HKEY hKey; // [esp+9Ch] [ebp-24h]
  WCHAR *pszText; // [esp+A0h] [ebp-20h]
  WCHAR *ppszText2; // [esp+A4h] [ebp-1Ch]
  LPCWSTR szArg4; // [esp+A8h] [ebp-18h]
  LPCWSTR lpszKeyName; // [esp+ACh] [ebp-14h]
  LPCWSTR v70; // [esp+B0h] [ebp-10h]
  int v71; // [esp+BCh] [ebp-4h]

  v60 = malloc(2u);
  *v60 = 0;
  v71 = 0;
  v56 = malloc(2u);
  *v56 = 0;
  ppv3 = malloc(2u);
  *ppv3 = 0;
  LOBYTE(v71) = 2;
  if ( a4 == -1 )
  {
    szKeyName = _wcsdup(&gszNullString);
    v63 = _wcsdup(&gszNullString);
    szArg3 = _wcsdup(&gszNullString);
    v64 = _wcsdup(&gszNullString);
    v70 = _wcsdup(&gszNullString);
    lpszKeyName = _wcsdup(&gszNullString);
    szArg4 = _wcsdup(&gszNullString);
    v4 = &gszNullString;
    if ( psz )
      v4 = psz;
    pszText = _wcsdup(v4);
    ppszText2 = _wcsdup(&gszNullString);
    v5 = &gszNullString;
    if ( psz )
      v5 = psz;
    hKey = _wcsdup(v5);
    LOBYTE(v71) = 12;
    v6 = MakeRegistryKeyName(&a1a, a2, &pszText, &szArg4);
    LOBYTE(v71) = 13;
    v7 = MakeRegistryKeyName(szArg, a2, &hKey, &ppszText2);
    LOBYTE(v71) = 14;
    a4 = sub_FD3FF0(a1, 0, 0xFFFFFFFF, 0, v7, v6, &lpszKeyName);
    free(*szArg);
    free(a1a);
    free(hKey);
    free(ppszText2);
    free(pszText);
    free(szArg4);
    free(lpszKeyName);
    free(v70);
    free(v64);
    free(szArg3);
    free(v63);
    LOBYTE(v71) = 2;
    free(szKeyName);
  }
  v8 = TlsGetValue(gdwTlsIndex);
  if ( !PE_OpenKey(a2, psz, 0, v8 | 0x20019, &KeyHandle) )
  {
    *szArg = 0;
    lpszKeyName = malloc(2u);
    *lpszKeyName = 0;
    ppszText2 = malloc(2u);
    *ppszText2 = 0;
    v70 = malloc(2u);
    *v70 = 0;
    szArg4 = malloc(2u);
    *szArg4 = 0;
    pszText = malloc(2u);
    *pszText = 0;
    LOBYTE(v71) = 19;
    v9 = RegCloseKey;
    if ( !PE_LoadRegKeys(KeyHandle, 0, &lpszKeyName) )
    {
      do
      {
        v10 = lpszKeyName;
        v11 = TlsGetValue(gdwTlsIndex);
        if ( !PE_OpenKey(KeyHandle, v10, 0, v11 | 0x20019, &hKey) )
        {
          if ( PE_ReadRegKey(hKey, L"CLSID", 0, 0, &ppszText2) )
          {
            v9(hKey);
          }
          else
          {
            v9(hKey);
            v12 = operator+(&pszResult, L"CLSID\\", &ppszText2);
            v13 = CPEString::Append(&ppv, v12, L"\\InprocServer32");
            v14 = v70;
            v70 = _wcsdup(v13->m_String);
            free(v14);
            free(ppv);
            free(pszResult);
            v15 = operator+(&v36.strValue[4], L"HKCR\\CLSID\\", &ppszText2);
            v16 = pszText;
            pszText = _wcsdup(v15->m_String);
            free(v16);
            free(v36.strValue[4]);
            v17 = v70;
            v18 = TlsGetValue(gdwTlsIndex);
            if ( !PE_OpenKey(HKEY_CLASSES_ROOT, v17, 0, v18 | KEY_READ, &hKey) )
            {
              v19 = v70;
              v70 = _wcsdup(&gszNullString);
              free(v19);
              PE_ReadRegKey(hKey, &gszNullString, 0, 0, &v70);
              v9(hKey);
              if ( wcslen(v70) )
              {
                v36.strValue[0] = malloc(2u);
                *v36.strValue[0] = 0;
                v36.strValue[1] = 0;
                v36.strValue[2] = 0;
                v36.strValue[3] = 0;
                LOBYTE(v71) = 20;
                sub_FD7040(v70, &v36);
                v20 = sub_FD4EE0(&v40, a1, &v36, 0);
                v21 = szArg4;
                szArg4 = _wcsdup(*v20);
                free(v21);
                free(v40);
                a2a = sub_FD4ED0();
                v22 = &gszNullString;
                if ( psz )
                  v22 = psz;
                szArg3 = _wcsdup(v22);
                v63 = _wcsdup(&gszNullString);
                v23 = &gszNullString;
                if ( psz )
                  v23 = psz;
                szKeyName = _wcsdup(v23);
                LOBYTE(v71) = 23;
                v24 = MakeRegistryKeyName(v38, a2, &szArg3, &lpszKeyName);
                LOBYTE(v71) = 24;
                v25 = MakeRegistryKeyName(&v36.strValue[6], a2, &szKeyName, &v63);
                LOBYTE(v71) = 25;
                v26 = sub_FD3D40(a1, &lpszKeyName, v25, v24, &szArg4, &v60, &ppv3, &v39);
                free(v36.strValue[6]);
                free(*v38);
                free(szKeyName);
                free(v63);
                free(szArg3);
                if ( v26 )
                {
                  if ( a4 == -1 )
                  {
                    v52 = _wcsdup(&gszNullString);
                    v53 = _wcsdup(&gszNullString);
                    v49 = _wcsdup(&gszNullString);
                    v47 = _wcsdup(&gszNullString);
                    v54 = _wcsdup(&gszNullString);
                    str3.m_String = _wcsdup(&gszNullString);
                    v46 = _wcsdup(&gszNullString);
                    v27 = &gszNullString;
                    if ( psz )
                      v27 = psz;
                    v48 = _wcsdup(v27);
                    v51 = _wcsdup(&gszNullString);
                    v28 = &gszNullString;
                    if ( psz )
                      v28 = psz;
                    v64 = _wcsdup(v28);
                    v29 = a2;
                    LOBYTE(v71) = 35;
                    v30 = MakeRegistryKeyName(v41, a2, &v48, &v46);
                    LOBYTE(v71) = 36;
                    v31 = MakeRegistryKeyName(v42, a2, &v64, &v51);
                    LOBYTE(v71) = 37;
                    a4 = sub_FD3FF0(a1, 0, 0xFFFFFFFF, 0, v31, v30, &str3);
                    free(*v42);
                    free(*v41);
                    free(v64);
                    free(v51);
                    free(v48);
                    free(v46);
                    free(str3.m_String);
                    free(v54);
                    free(v47);
                    free(v49);
                    free(v53);
                    free(v52);
                  }
                  else
                  {
                    v29 = a2;
                  }
                  a1a = _wcsdup(&gszNullString);
                  v32 = &gszNullString;
                  if ( psz )
                    v32 = psz;
                  v50 = _wcsdup(v32);
                  LOBYTE(v71) = 39;
                  v33 = MakeRegistryKeyName(&v36.strValue[5], v29, &v50, &lpszKeyName);
                  LOBYTE(v71) = 40;
                  sub_FD3FF0(a1, a2a, a4, 3u, &lpszKeyName, v33, &szArg4);
                  free(v36.strValue[5]);
                  free(v50);
                  free(a1a);
                }
                sub_FD21F0(&v36);
                free(pszText);
                free(szArg4);
                free(v70);
                free(ppszText2);
                free(lpszKeyName);
                v9 = RegCloseKey;
                goto LABEL_31;
              }
            }
          }
        }
        free(pszText);
        free(szArg4);
        free(v70);
        free(ppszText2);
        free(lpszKeyName);
LABEL_31:
        v34 = ++*szArg;
        lpszKeyName = malloc(2u);
        *lpszKeyName = 0;
        ppszText2 = malloc(2u);
        *ppszText2 = 0;
        v70 = malloc(2u);
        *v70 = 0;
        szArg4 = malloc(2u);
        *szArg4 = 0;
        pszText = malloc(2u);
        *pszText = 0;
        LOBYTE(v71) = 19;
      }
      while ( !PE_LoadRegKeys(KeyHandle, v34, &lpszKeyName) );
    }
    free(pszText);
    free(szArg4);
    free(v70);
    free(ppszText2);
    free(lpszKeyName);
    v9(KeyHandle);
  }
  free(ppv3);
  free(v56);
  free(v60);
  return a4;
}

//----- (00FE39D0) --------------------------------------------------------
void __cdecl sub_FE39D0(int a1, void *a2, void *a3)
{
  _WORD *v3; // ST50_4
  CPEString *v4; // esi
  void *v5; // edi
  CPEString *v6; // eax
  wchar_t *v7; // ST54_4

  v3 = malloc(2u);
  *v3 = 0;
  v4 = a3;
  v5 = sub_FE3A80(a1, a2, *a3, 0xFFFFFFFF);
  v6 = CPEString::Append(&a3, v4, L"\\AutorunsDisabled");
  v7 = _wcsdup(v6->m_String);
  free(v3);
  free(a3);
  sub_FE3A80(a1, a2, v7, v5);
  free(v7);
}

//----- (00FE3A80) --------------------------------------------------------
void *__cdecl sub_FE3A80(int a1, void *a2, wchar_t *psz, void *a4)
{
  DWORD v4; // ebx
  _WORD *v5; // esi
  wchar_t *v6; // edi
  const wchar_t *v7; // eax
  const wchar_t *v8; // eax
  CPEString *v9; // edi
  CPEString *v10; // eax
  unsigned int v11; // eax
  void *v12; // esi
  const WCHAR *v13; // edi
  unsigned int v14; // eax
  const wchar_t **v15; // eax
  WCHAR *v16; // edi
  signed int v17; // eax
  const wchar_t *v18; // ecx
  const wchar_t *v19; // eax
  CPEString *v20; // edi
  CPEString *v21; // eax
  char v22; // bl
  wchar_t *v23; // ebx
  const wchar_t *v24; // eax
  const wchar_t *v25; // eax
  CPEString *v26; // edi
  CPEString *v27; // eax
  const WCHAR **v28; // eax
  CPEString *v29; // eax
  int a2a; // [esp+10h] [ebp-A0h]
  int v32; // [esp+14h] [ebp-9Ch]
  int v33; // [esp+18h] [ebp-98h]
  int v34; // [esp+1Ch] [ebp-94h]
  WCHAR v35[2]; // [esp+20h] [ebp-90h]
  _WORD *v36; // [esp+24h] [ebp-8Ch]
  WCHAR v37[2]; // [esp+28h] [ebp-88h]
  WCHAR v38[2]; // [esp+2Ch] [ebp-84h]
  void *v39; // [esp+30h] [ebp-80h]
  DWORD dwValue; // [esp+34h] [ebp-7Ch]
  WCHAR v41[2]; // [esp+38h] [ebp-78h]
  int v42; // [esp+3Ch] [ebp-74h]
  WCHAR v43[2]; // [esp+40h] [ebp-70h]
  HKEY hKey; // [esp+44h] [ebp-6Ch]
  void *v45; // [esp+48h] [ebp-68h]
  LPCWSTR v46; // [esp+4Ch] [ebp-64h]
  void *v47; // [esp+50h] [ebp-60h]
  std__List *v48; // [esp+54h] [ebp-5Ch]
  WCHAR *ppv3; // [esp+58h] [ebp-58h]
  DWORD v50; // [esp+5Ch] [ebp-54h]
  void *v51; // [esp+60h] [ebp-50h]
  void *v52; // [esp+64h] [ebp-4Ch]
  void *a1a; // [esp+68h] [ebp-48h]
  HKEY KeyHandle; // [esp+6Ch] [ebp-44h]
  WCHAR szArg[2]; // [esp+70h] [ebp-40h]
  LPCWSTR v56; // [esp+74h] [ebp-3Ch]
  LPCWSTR v57; // [esp+78h] [ebp-38h]
  LPCWSTR v58; // [esp+7Ch] [ebp-34h]
  LPCWSTR v59; // [esp+80h] [ebp-30h]
  LPCWSTR v60; // [esp+84h] [ebp-2Ch]
  LPCWSTR szArg3; // [esp+88h] [ebp-28h]
  LPCWSTR v62; // [esp+8Ch] [ebp-24h]
  WCHAR *pszText; // [esp+90h] [ebp-20h]
  LPCWSTR szArg4; // [esp+94h] [ebp-1Ch]
  LPCWSTR szKeyName; // [esp+98h] [ebp-18h]
  CPEString str3; // [esp+9Ch] [ebp-14h]
  LPCWSTR lpszKeyName; // [esp+A0h] [ebp-10h]
  int v68; // [esp+ACh] [ebp-4h]

  v4 = 0;
  v50 = 0;
  v48 = malloc(2u);
  LOWORD(v48->_Mypair._Myval2._Myhead) = 0;
  v68 = 0;
  lpszKeyName = malloc(2u);
  *lpszKeyName = 0;
  v5 = malloc(2u);
  v36 = v5;
  *v5 = 0;
  str3.m_String = malloc(2u);
  *str3.m_String = 0;
  v52 = malloc(2u);
  *v52 = 0;
  v51 = malloc(2u);
  *v51 = 0;
  ppv3 = malloc(2u);
  *ppv3 = 0;
  v6 = psz;
  LOBYTE(v68) = 6;
  if ( a4 == -1 )
  {
    v59 = _wcsdup(&gszNullString);
    szKeyName = _wcsdup(&gszNullString);
    v56 = _wcsdup(&gszNullString);
    v58 = _wcsdup(&gszNullString);
    v60 = _wcsdup(&gszNullString);
    v62 = _wcsdup(&gszNullString);
    szArg4 = _wcsdup(&gszNullString);
    v7 = &gszNullString;
    if ( psz )
      v7 = psz;
    pszText = _wcsdup(v7);
    v57 = _wcsdup(&gszNullString);
    v8 = &gszNullString;
    if ( psz )
      v8 = psz;
    szArg3 = _wcsdup(v8);
    LOBYTE(v68) = 16;
    v9 = MakeRegistryKeyName(&a1a, a2, &pszText, &szArg4);
    LOBYTE(v68) = 17;
    v10 = MakeRegistryKeyName(szArg, a2, &szArg3, &v57);
    LOBYTE(v68) = 18;
    a4 = sub_FD3FF0(a1, 0, 0xFFFFFFFF, 0, v10, v9, &v62);
    free(*szArg);
    free(a1a);
    free(szArg3);
    free(v57);
    free(pszText);
    free(szArg4);
    free(v62);
    free(v60);
    free(v58);
    free(v56);
    free(szKeyName);
    LOBYTE(v68) = 6;
    free(v59);
    v6 = psz;
  }
  v11 = TlsGetValue(gdwTlsIndex);
  if ( !PE_OpenKey(a2, v6, 0, v11 | 0x20019, &KeyHandle) )
  {
    if ( !PE_LoadRegKeys(KeyHandle, 0, &lpszKeyName) )
    {
      v12 = a4;
      do
      {
        v13 = lpszKeyName;
        v14 = TlsGetValue(gdwTlsIndex);
        if ( !PE_OpenKey(KeyHandle, v13, 0, v14 | 0x20019, &hKey) )
        {
          if ( !PE_ReadRegKey(hKey, L"Source", 0, 0, &v48) )
          {
            a2a = malloc(2u);
            *a2a = 0;
            v32 = 0;
            v33 = 0;
            v34 = 0;
            LOBYTE(v68) = 19;
            if ( sub_FD6CC0(v48, &a2a) )
            {
              v15 = sub_FD4EE0(&v39, a1, &a2a, 0);
              v16 = str3.m_String;
              str3.m_String = _wcsdup(*v15);
              free(v16);
              free(v39);
              v17 = sub_FD4ED0();
              v18 = &gszNullString;
              dwValue = v17;
              if ( psz )
                v18 = psz;
              szKeyName = _wcsdup(v18);
              v59 = _wcsdup(&gszNullString);
              v19 = &gszNullString;
              if ( psz )
                v19 = psz;
              a4 = _wcsdup(v19);
              LOBYTE(v68) = 22;
              v20 = MakeRegistryKeyName(v37, a2, &szKeyName, &lpszKeyName);
              LOBYTE(v68) = 23;
              v21 = MakeRegistryKeyName(v41, a2, &a4, &v59);
              LOBYTE(v68) = 24;
              v22 = sub_FD3D40(a1, &lpszKeyName, v21, v20, &str3, &v52, &ppv3, &v42);
              free(*v41);
              free(*v37);
              free(a4);
              free(v59);
              free(szKeyName);
              if ( v22 )
              {
                if ( v12 == -1 )
                {
                  v45 = _wcsdup(&gszNullString);
                  v47 = _wcsdup(&gszNullString);
                  szArg3 = _wcsdup(&gszNullString);
                  v57 = _wcsdup(&gszNullString);
                  pszText = _wcsdup(&gszNullString);
                  szArg4 = _wcsdup(&gszNullString);
                  v62 = _wcsdup(&gszNullString);
                  v23 = psz;
                  v24 = &gszNullString;
                  if ( psz )
                    v24 = psz;
                  v60 = _wcsdup(v24);
                  v58 = _wcsdup(&gszNullString);
                  v25 = &gszNullString;
                  if ( psz )
                    v25 = psz;
                  v56 = _wcsdup(v25);
                  LOBYTE(v68) = 34;
                  v26 = MakeRegistryKeyName(v35, a2, &v60, &v62);
                  LOBYTE(v68) = 35;
                  v27 = MakeRegistryKeyName(v43, a2, &v56, &v58);
                  LOBYTE(v68) = 36;
                  v12 = sub_FD3FF0(a1, 0, 0xFFFFFFFF, 0, v27, v26, &szArg4);
                  free(*v43);
                  free(*v35);
                  free(v56);
                  free(v58);
                  free(v60);
                  free(v62);
                  free(szArg4);
                  free(pszText);
                  free(v57);
                  free(szArg3);
                  free(v47);
                  free(v45);
                }
                else
                {
                  v23 = psz;
                }
                *szArg = _wcsdup(&gszNullString);
                a1a = _wcsdup(&gszNullString);
                v28 = &gszNullString;
                if ( v23 )
                  v28 = v23;
                v46 = _wcsdup(v28);
                LOBYTE(v68) = 39;
                v29 = MakeRegistryKeyName(v38, a2, &v46, &lpszKeyName);
                LOBYTE(v68) = 40;
                sub_FD3FF0(a1, dwValue, v12, 3u, &lpszKeyName, v29, &str3);
                free(*v38);
                free(v46);
                free(a1a);
                free(*szArg);
              }
              v4 = v50;
            }
            LOBYTE(v68) = 6;
            sub_FD21F0(&a2a);
          }
          RegCloseKey(hKey);
        }
        v50 = ++v4;
      }
      while ( !PE_LoadRegKeys(KeyHandle, v4, &lpszKeyName) );
      a4 = v12;
      v5 = v36;
    }
    RegCloseKey(KeyHandle);
  }
  free(ppv3);
  free(v51);
  free(v52);
  free(str3.m_String);
  free(v5);
  free(lpszKeyName);
  free(v48);
  return a4;
}

//----- (00FE4150) --------------------------------------------------------
void __cdecl sub_FE4150(int a1, void *a2, void *a3)
{
  _WORD *v3; // ST50_4
  CPEString *v4; // esi
  void *v5; // edi
  CPEString *v6; // eax
  wchar_t *v7; // ST54_4

  v3 = malloc(2u);
  *v3 = 0;
  v4 = a3;
  v5 = sub_FE4200(a1, a2, *a3, 0xFFFFFFFF);
  v6 = CPEString::Append(&a3, v4, L"\\AutorunsDisabled");
  v7 = _wcsdup(v6->m_String);
  free(v3);
  free(a3);
  sub_FE4200(a1, a2, v7, v5);
  free(v7);
}

//----- (00FE4200) --------------------------------------------------------
void *__cdecl sub_FE4200(int a1, void *a2, wchar_t *psz, void *a4)
{
  wchar_t *v4; // edi
  const wchar_t *v5; // eax
  const wchar_t *v6; // eax
  CPEString *v7; // esi
  CPEString *v8; // eax
  unsigned int v9; // eax
  void (__stdcall *v10)(HKEY); // ebx
  OLECHAR *v11; // esi
  unsigned int v12; // eax
  wchar_t *v13; // ebx
  UINT v14; // edi
  wchar_t *v15; // eax
  const wchar_t **v16; // eax
  wchar_t *v17; // esi
  HMODULE v18; // ebx
  wchar_t *v19; // edi
  LSTATUS v20; // eax
  CPEString *v21; // eax
  CPEString *v22; // eax
  WCHAR *v23; // esi
  const WCHAR *v24; // esi
  unsigned int v25; // eax
  DWORD v26; // esi
  WCHAR *v28; // esi
  const wchar_t *v29; // eax
  void *v30; // esi
  const wchar_t **v31; // eax
  WCHAR *v32; // esi
  const WCHAR **v33; // ecx
  const WCHAR **v34; // eax
  HKEY v35; // ebx
  CPEString *v36; // esi
  CPEString *v37; // eax
  const WCHAR **v38; // eax
  const WCHAR **v39; // eax
  HKEY v40; // ebx
  CPEString *v41; // esi
  CPEString *v42; // eax
  const WCHAR **v43; // eax
  CPEString *v44; // eax
  HKEY v45; // [esp-4h] [ebp-2E0h]
  tagPEStringStruct v46; // [esp+10h] [ebp-2CCh]
  WCHAR v47[2]; // [esp+2Ch] [ebp-2B0h]
  WCHAR v48[2]; // [esp+30h] [ebp-2ACh]
  wchar_t *v49; // [esp+34h] [ebp-2A8h]
  WCHAR v50[2]; // [esp+38h] [ebp-2A4h]
  int v51; // [esp+3Ch] [ebp-2A0h]
  WCHAR *ppstr; // [esp+40h] [ebp-29Ch]
  WCHAR v53[2]; // [esp+44h] [ebp-298h]
  WCHAR *pszResult; // [esp+48h] [ebp-294h]
  int a2a; // [esp+4Ch] [ebp-290h]
  void *v56; // [esp+50h] [ebp-28Ch]
  void *v57; // [esp+54h] [ebp-288h]
  void *v58; // [esp+58h] [ebp-284h]
  CPEString str3; // [esp+5Ch] [ebp-280h]
  void *v60; // [esp+60h] [ebp-27Ch]
  LPCWSTR v61; // [esp+64h] [ebp-278h]
  LPCWSTR v62; // [esp+68h] [ebp-274h]
  LPCWSTR v63; // [esp+6Ch] [ebp-270h]
  void *v64; // [esp+70h] [ebp-26Ch]
  void *v65; // [esp+74h] [ebp-268h]
  WCHAR *v66; // [esp+78h] [ebp-264h]
  HKEY v67; // [esp+7Ch] [ebp-260h]
  void *a1a; // [esp+80h] [ebp-25Ch]
  WCHAR szArg[2]; // [esp+84h] [ebp-258h]
  HKEY KeyHandle; // [esp+88h] [ebp-254h]
  void *v71; // [esp+8Ch] [ebp-250h]
  void *v72; // [esp+90h] [ebp-24Ch]
  LPCWSTR szKeyName; // [esp+94h] [ebp-248h]
  LPCWSTR v74; // [esp+98h] [ebp-244h]
  LPCWSTR v75; // [esp+9Ch] [ebp-240h]
  LPCWSTR v76; // [esp+A0h] [ebp-23Ch]
  LPCWSTR szArg3; // [esp+A4h] [ebp-238h]
  int v78; // [esp+A8h] [ebp-234h]
  wchar_t *ppv3; // [esp+ACh] [ebp-230h]
  WCHAR *ppszText2; // [esp+B0h] [ebp-22Ch]
  HKEY hKey; // [esp+B4h] [ebp-228h]
  OLECHAR *pszText; // [esp+B8h] [ebp-224h]
  LPCWSTR szArg4; // [esp+BCh] [ebp-220h]
  LPCWSTR lpszKeyName; // [esp+C0h] [ebp-21Ch]
  WCHAR Buffer; // [esp+C4h] [ebp-218h]
  int v86; // [esp+2D8h] [ebp-4h]

  v4 = psz;
  v78 = a1;
  v67 = a2;
  v49 = psz;
  ppv3 = malloc(2u);
  *ppv3 = 0;
  v86 = 0;
  v71 = malloc(2u);
  *v71 = 0;
  v65 = malloc(2u);
  *v65 = 0;
  v66 = malloc(2u);
  *v66 = 0;
  v72 = malloc(2u);
  *v72 = 0;
  LOBYTE(v86) = 4;
  if ( a4 == -1 )
  {
    szKeyName = _wcsdup(&gszNullString);
    v75 = _wcsdup(&gszNullString);
    szArg3 = _wcsdup(&gszNullString);
    v74 = _wcsdup(&gszNullString);
    v76 = _wcsdup(&gszNullString);
    lpszKeyName = _wcsdup(&gszNullString);
    szArg4 = _wcsdup(&gszNullString);
    v5 = &gszNullString;
    if ( psz )
      v5 = psz;
    pszText = _wcsdup(v5);
    hKey = _wcsdup(&gszNullString);
    v6 = &gszNullString;
    if ( psz )
      v6 = psz;
    ppszText2 = _wcsdup(v6);
    LOBYTE(v86) = 14;
    v7 = MakeRegistryKeyName(&a1a, a2, &pszText, &szArg4);
    LOBYTE(v86) = 15;
    v8 = MakeRegistryKeyName(szArg, a2, &ppszText2, &hKey);
    LOBYTE(v86) = 16;
    a4 = sub_FD3FF0(v78, 0, 0xFFFFFFFF, 0, v8, v7, &lpszKeyName);
    free(*szArg);
    free(a1a);
    free(ppszText2);
    free(hKey);
    free(pszText);
    free(szArg4);
    free(lpszKeyName);
    free(v76);
    free(v74);
    free(szArg3);
    free(v75);
    LOBYTE(v86) = 4;
    free(szKeyName);
  }
  v9 = TlsGetValue(gdwTlsIndex);
  if ( !PE_OpenKey(a2, psz, 0, v9 | 0x20019, &KeyHandle) )
  {
    *szArg = 0;
    pszText = malloc(2u);
    *pszText = 0;
    ppszText2 = malloc(2u);
    *ppszText2 = 0;
    lpszKeyName = malloc(2u);
    *lpszKeyName = 0;
    szArg4 = malloc(2u);
    *szArg4 = 0;
    LOBYTE(v86) = 20;
    v10 = RegCloseKey;
    if ( !PE_LoadRegKeys(KeyHandle, 0, &pszText) )
    {
      while ( 1 )
      {
        v11 = pszText;
        v12 = TlsGetValue(gdwTlsIndex);
        if ( !PE_OpenKey(KeyHandle, v11, 0, v12 | 0x20019, &hKey) )
        {
          if ( PE_ReadRegKey(hKey, L"MenuText", 0, 0, &ppv3) && PE_ReadRegKey(hKey, L"ButtonText", 0, 0, &ppv3) )
            goto LABEL_25;
          if ( *ppv3 == 64 )
          {
            v13 = _wcsdup(ppv3);
            a2a = v13;
            LOBYTE(v86) = 21;
            v14 = 0;
            if ( wcschr(v13, 0x2Cu) )
            {
              v15 = wcschr(v13, 0x2Cu);
              *v15 = 0;
              v14 = abs(_wtoi(v15 + 1));
            }
            v16 = RequerySystemEnvironmentString(&ppstr, v13 + 1);
            v17 = _wcsdup(*v16);
            free(v13);
            free(ppstr);
            v18 = LoadLibraryExW(v17, 0, 2u);
            if ( v18 )
            {
              if ( LoadStringW(v18, v14, &Buffer, 260) )
              {
                v19 = ppv3;
                ppv3 = _wcsdup(&Buffer);
                free(v19);
              }
              FreeLibrary(v18);
            }
            LOBYTE(v86) = 20;
            free(v17);
            v10 = RegCloseKey;
            v4 = v49;
          }
          if ( !PE_ReadRegKey(hKey, L"Exec", 0, 0, &lpszKeyName) )
            goto LABEL_36;
          if ( !PE_ReadRegKey(hKey, L"Script", 0, 0, &lpszKeyName) )
          {
            if ( !_wcsnicmp(lpszKeyName, L"res://", 6u) )
            {
              v28 = lpszKeyName;
              v29 = lpszKeyName + 6;
              goto LABEL_35;
            }
            if ( !_wcsnicmp(lpszKeyName, L"file://", 7u) )
            {
              v28 = lpszKeyName;
              v29 = lpszKeyName + 7;
LABEL_35:
              lpszKeyName = _wcsdup(v29);
              free(v28);
            }
LABEL_36:
            v10(hKey);
            v46.strValue[0] = malloc(2u);
            *v46.strValue[0] = 0;
            v46.strValue[1] = 0;
            v46.strValue[2] = 0;
            v46.strValue[3] = 0;
            LOBYTE(v86) = 22;
            sub_FD7040(lpszKeyName, &v46);
            v30 = v72;
            v72 = _wcsdup(lpszKeyName);
            free(v30);
            v31 = sub_FD4EE0(&v46.strValue[4], v78, &v46, 0);
            v32 = szArg4;
            szArg4 = _wcsdup(*v31);
            free(v32);
            free(v46.strValue[4]);
            a2a = sub_FD4ED0();
            v33 = &gszNullString;
            if ( v4 )
              v33 = v4;
            szArg3 = _wcsdup(v33);
            v75 = _wcsdup(&gszNullString);
            v34 = &gszNullString;
            if ( v4 )
              v34 = v4;
            szKeyName = _wcsdup(v34);
            v35 = v67;
            LOBYTE(v86) = 25;
            v36 = MakeRegistryKeyName(&v46.strValue[6], v67, &szArg3, &pszText);
            LOBYTE(v86) = 26;
            v37 = MakeRegistryKeyName(v50, v35, &szKeyName, &v75);
            LOBYTE(v86) = 27;
            LOBYTE(v35) = sub_FD3D40(v78, &ppv3, v37, v36, &szArg4, &v71, &v66, &v51);
            free(*v50);
            free(v46.strValue[6]);
            free(szKeyName);
            free(v75);
            free(szArg3);
            if ( v35 )
            {
              if ( a4 == -1 )
              {
                v56 = _wcsdup(&gszNullString);
                v60 = _wcsdup(&gszNullString);
                v58 = _wcsdup(&gszNullString);
                v57 = _wcsdup(&gszNullString);
                v64 = _wcsdup(&gszNullString);
                str3.m_String = _wcsdup(&gszNullString);
                v61 = _wcsdup(&gszNullString);
                v38 = &gszNullString;
                if ( v4 )
                  v38 = v4;
                v62 = _wcsdup(v38);
                v76 = _wcsdup(&gszNullString);
                v39 = &gszNullString;
                if ( v4 )
                  v39 = v4;
                v74 = _wcsdup(v39);
                v40 = v67;
                LOBYTE(v86) = 37;
                v41 = MakeRegistryKeyName(v53, v67, &v62, &v61);
                LOBYTE(v86) = 38;
                v42 = MakeRegistryKeyName(v48, v40, &v74, &v76);
                LOBYTE(v86) = 39;
                a4 = sub_FD3FF0(v78, 0, 0xFFFFFFFF, 0, v42, v41, &str3);
                free(*v48);
                free(*v53);
                free(v74);
                free(v76);
                free(v62);
                free(v61);
                free(str3.m_String);
                free(v64);
                free(v57);
                free(v58);
                free(v60);
                free(v56);
              }
              else
              {
                v40 = v67;
              }
              a1a = _wcsdup(&gszNullString);
              v43 = &gszNullString;
              if ( v4 )
                v43 = v4;
              v63 = _wcsdup(v43);
              LOBYTE(v86) = 41;
              v44 = MakeRegistryKeyName(v47, v40, &v63, &pszText);
              LOBYTE(v86) = 42;
              sub_FD3FF0(v78, a2a, a4, 3u, &ppv3, v44, &szArg4);
              free(*v47);
              free(v63);
              free(a1a);
            }
            sub_FD21F0(&v46);
            free(szArg4);
            free(lpszKeyName);
            free(ppszText2);
            free(pszText);
            v10 = RegCloseKey;
            goto LABEL_28;
          }
          v20 = PE_ReadRegKey(hKey, L"ClsidExtension", 0, 0, &ppszText2);
          v45 = hKey;
          if ( v20 )
            goto LABEL_26;
          v10(hKey);
          v21 = operator+(&pszResult, L"CLSID\\", &ppszText2);
          v22 = CPEString::Append(&v46.strValue[5], v21, L"\\InprocServer32");
          v23 = lpszKeyName;
          lpszKeyName = _wcsdup(v22->m_String);
          free(v23);
          free(v46.strValue[5]);
          free(pszResult);
          v24 = lpszKeyName;
          v25 = TlsGetValue(gdwTlsIndex);
          if ( !PE_OpenKey(HKEY_CLASSES_ROOT, v24, 0, v25 | 0x20019, &hKey) )
            break;
        }
LABEL_27:
        free(szArg4);
        free(lpszKeyName);
        free(ppszText2);
        free(pszText);
LABEL_28:
        v26 = ++*szArg;
        pszText = malloc(2u);
        *pszText = 0;
        ppszText2 = malloc(2u);
        *ppszText2 = 0;
        lpszKeyName = malloc(2u);
        *lpszKeyName = 0;
        szArg4 = malloc(2u);
        *szArg4 = 0;
        LOBYTE(v86) = 20;
        if ( PE_LoadRegKeys(KeyHandle, v26, &pszText) )
          goto LABEL_29;
      }
      if ( !PE_ReadRegKey(hKey, &gszNullString, 0, 0, &lpszKeyName) )
        goto LABEL_36;
LABEL_25:
      v45 = hKey;
LABEL_26:
      v10(v45);
      goto LABEL_27;
    }
LABEL_29:
    free(szArg4);
    free(lpszKeyName);
    free(ppszText2);
    free(pszText);
    v10(KeyHandle);
  }
  free(v72);
  free(v66);
  free(v65);
  free(v71);
  free(ppv3);
  return a4;
}

//----- (00FE4E10) --------------------------------------------------------
void *__cdecl PE_RefreshRegistry_0(int a1, void *a2, OLECHAR *psz)
{
  _bstr_t *v3; // eax
  _bstr_t *v4; // eax
  Data_t_bstr_t *v5; // esi
  Data_t_bstr_t *v6; // esi
  Data_t_bstr_t *v7; // esi
  void *v8; // eax
  void *v9; // eax
  void *v10; // esi
  void *v11; // edi
  void *v13; // [esp+10h] [ebp-1Ch]
  _bstr_t v14; // [esp+14h] [ebp-18h]
  _bstr_t v15; // [esp+18h] [ebp-14h]
  _bstr_t a1a; // [esp+1Ch] [ebp-10h]
  int v17; // [esp+28h] [ebp-4h]

  _bstr_t::_bstr_t(&v14, L"AutorunsDisabled");
  v17 = 0;
  v3 = _bstr_t::_bstr_t(&v15, L"\\");
  LOBYTE(v17) = 1;
  v4 = _bstr_t::operator+(&a1a, psz, v3);
  LOBYTE(v17) = 2;
  _bstr_t::operator+(v4, &v13, &v14);
  v5 = a1a.m_Data;
  if ( a1a.m_Data )
  {
    if ( !InterlockedDecrement(&a1a.m_Data->m_RefCount) && v5 )
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
    a1a.m_Data = 0;
  }
  v6 = v15.m_Data;
  if ( v15.m_Data )
  {
    if ( !InterlockedDecrement(&v15.m_Data->m_RefCount) && v6 )
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
    v15.m_Data = 0;
  }
  v7 = v14.m_Data;
  LOBYTE(v17) = 6;
  if ( v14.m_Data && !InterlockedDecrement(&v14.m_Data->m_RefCount) )
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
  v8 = sub_FE4FF0(a1, a2, psz, 0xFFFFFFFF, 1);
  v9 = sub_FE4FF0(a1, a2, psz, v8, 0);
  v10 = v13;
  v11 = v9;
  if ( v13 && !InterlockedDecrement(v13 + 2) && v10 )
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
  return v11;
}

//----- (00FE4FF0) --------------------------------------------------------
void *__cdecl sub_FE4FF0(int a1, void *a2, wchar_t *psz, void *a4, char a5)
{
  void *v5; // esi
  const wchar_t *v6; // eax
  const wchar_t *v7; // eax
  CPEString *v8; // esi
  CPEString *v9; // eax
  unsigned int v10; // eax
  WCHAR *v12; // ebx
  WCHAR *v13; // edi
  int v14; // esi
  WCHAR *v15; // eax
  wchar_t *v16; // eax
  wchar_t *v17; // esi
  unsigned int v18; // eax
  int v19; // eax
  wchar_t *v20; // esi
  const wchar_t *v21; // ecx
  const WCHAR **v22; // eax
  wchar_t *v23; // esi
  CPEString *v24; // eax
  CPEString *v25; // edi
  CPEString *v26; // eax
  wchar_t *v27; // edi
  const wchar_t *v28; // eax
  const WCHAR **v29; // eax
  CPEString *v30; // esi
  CPEString *v31; // eax
  const WCHAR **v32; // eax
  wchar_t *v33; // esi
  CPEString *v34; // eax
  CPEString *v35; // eax
  unsigned int v36; // eax
  wchar_t *v37; // esi
  const wchar_t *v38; // eax
  const WCHAR **v39; // eax
  HKEY v40; // edi
  CPEString *v41; // esi
  CPEString *v42; // eax
  CPEString *v43; // eax
  const WCHAR *v44; // eax
  wchar_t *v45; // eax
  wchar_t *v46; // edi
  const wchar_t *v47; // eax
  wchar_t *v48; // eax
  wchar_t *v49; // esi
  CPEString *v50; // eax
  CPEString *v51; // eax
  int v52; // eax
  WCHAR *v53; // esi
  tagPEStringStruct v54; // [esp+10h] [ebp-528h]
  BYTE v55[4]; // [esp+2Ch] [ebp-50Ch]
  WCHAR v56[2]; // [esp+30h] [ebp-508h]
  CPEString v57; // [esp+34h] [ebp-504h]
  WCHAR v58[2]; // [esp+38h] [ebp-500h]
  CPEString v59; // [esp+3Ch] [ebp-4FCh]
  CPEString v60; // [esp+40h] [ebp-4F8h]
  CPEString v61; // [esp+44h] [ebp-4F4h]
  WCHAR *pszResult; // [esp+48h] [ebp-4F0h]
  WCHAR *ppv1; // [esp+4Ch] [ebp-4ECh]
  WCHAR v64[2]; // [esp+50h] [ebp-4E8h]
  WCHAR v65[2]; // [esp+54h] [ebp-4E4h]
  CPEString str; // [esp+58h] [ebp-4E0h]
  WCHAR v67[2]; // [esp+5Ch] [ebp-4DCh]
  WCHAR *ppv; // [esp+60h] [ebp-4D8h]
  LPCWSTR v69; // [esp+64h] [ebp-4D4h]
  WCHAR *ppv3; // [esp+68h] [ebp-4D0h]
  LPCWSTR v71; // [esp+6Ch] [ebp-4CCh]
  LPCWSTR v72; // [esp+70h] [ebp-4C8h]
  void *v73; // [esp+74h] [ebp-4C4h]
  void *v74; // [esp+78h] [ebp-4C0h]
  LPCWSTR v75; // [esp+7Ch] [ebp-4BCh]
  void *v76; // [esp+80h] [ebp-4B8h]
  LPCWSTR v77; // [esp+84h] [ebp-4B4h]
  void *v78; // [esp+88h] [ebp-4B0h]
  void *v79; // [esp+8Ch] [ebp-4ACh]
  LPCWSTR v80; // [esp+90h] [ebp-4A8h]
  void *v81; // [esp+94h] [ebp-4A4h]
  void *v82; // [esp+98h] [ebp-4A0h]
  void *v83; // [esp+9Ch] [ebp-49Ch]
  LPCWSTR v84; // [esp+A0h] [ebp-498h]
  void *v85; // [esp+A4h] [ebp-494h]
  void *v86; // [esp+A8h] [ebp-490h]
  CPEString v87; // [esp+ACh] [ebp-48Ch]
  void *v88; // [esp+B0h] [ebp-488h]
  LPCWSTR v89; // [esp+B4h] [ebp-484h]
  CPEString str3; // [esp+B8h] [ebp-480h]
  LPCWSTR v91; // [esp+BCh] [ebp-47Ch]
  void *v92; // [esp+C0h] [ebp-478h]
  DWORD cbData; // [esp+C4h] [ebp-474h]
  HKEY__ v94; // [esp+C8h] [ebp-470h]
  WCHAR szArg[2]; // [esp+CCh] [ebp-46Ch]
  void *a1a; // [esp+D0h] [ebp-468h]
  LPCWSTR szKeyName; // [esp+D4h] [ebp-464h]
  wchar_t *v98; // [esp+D8h] [ebp-460h]
  WCHAR *ppszText2; // [esp+DCh] [ebp-45Ch]
  LPCWSTR szArg3; // [esp+E0h] [ebp-458h]
  LPCWSTR v101; // [esp+E4h] [ebp-454h]
  int v102; // [esp+E8h] [ebp-450h]
  HKEY hKey; // [esp+ECh] [ebp-44Ch]
  LPCWSTR v104; // [esp+F0h] [ebp-448h]
  HKEY v105; // [esp+F4h] [ebp-444h]
  int v106; // [esp+F8h] [ebp-440h]
  LPCWSTR szArg4; // [esp+FCh] [ebp-43Ch]
  WCHAR *pszText; // [esp+100h] [ebp-438h]
  HKEY KeyHandle; // [esp+104h] [ebp-434h]
  HKEY__ v110; // [esp+108h] [ebp-430h]
  int v111; // [esp+10Ch] [ebp-42Ch]
  char v112; // [esp+113h] [ebp-425h]
  LPCWSTR lpszKeyName; // [esp+114h] [ebp-424h]
  wchar_t Data[260]; // [esp+118h] [ebp-420h]
  WCHAR Name; // [esp+320h] [ebp-218h]
  int v116; // [esp+534h] [ebp-4h]

  v5 = a4;
  v106 = a1;
  v105 = a2;
  v98 = psz;
  v111 = 0;
  v102 = 0;
  if ( a4 == -1 )
  {
    ppszText2 = _wcsdup(&gszNullString);
    v116 = 0;
    lpszKeyName = _wcsdup(&gszNullString);
    szKeyName = _wcsdup(&gszNullString);
    v101 = _wcsdup(&gszNullString);
    szArg3 = _wcsdup(&gszNullString);
    KeyHandle = _wcsdup(&gszNullString);
    szArg4 = _wcsdup(&gszNullString);
    v6 = &gszNullString;
    if ( psz )
      v6 = psz;
    pszText = _wcsdup(v6);
    v104 = _wcsdup(&gszNullString);
    v7 = &gszNullString;
    if ( psz )
      v7 = psz;
    v110.unused = _wcsdup(v7);
    LOBYTE(v116) = 9;
    v8 = MakeRegistryKeyName(&a1a, a2, &pszText, &szArg4);
    LOBYTE(v116) = 10;
    v9 = MakeRegistryKeyName(szArg, a2, &v110, &v104);
    LOBYTE(v116) = 11;
    v5 = sub_FD3FF0(v106, 0, 0xFFFFFFFF, 0, v9, v8, &KeyHandle);
    a4 = v5;
    free(*szArg);
    free(a1a);
    free(v110.unused);
    free(v104);
    free(pszText);
    free(szArg4);
    free(KeyHandle);
    free(szArg3);
    free(v101);
    free(szKeyName);
    free(lpszKeyName);
    v116 = -1;
    free(ppszText2);
  }
  hKey = 0;
  v10 = TlsGetValue(gdwTlsIndex);
  if ( PE_OpenKey(a2, psz, 0, v10 | 0x20019, &hKey) )
    return v5;
  *szArg = 0;
  if ( !RegEnumKeyW(hKey, 0, &Name, 0x104u) )
  {
    v12 = lpszKeyName;
    do
    {
      KeyHandle = 0;
      if ( a5 )
      {
        v13 = ppszText2;
        lpszKeyName = &gszNullString;
      }
      else
      {
        v13 = _wcsdup(L"AutorunsDisabled");
        ppszText2 = v13;
        v14 = v111 | 1;
        v15 = operator+(&pszResult, L"\\", &ppszText2)->m_String;
        v111 = v14 | 2;
        v102 = v14 | 2;
        lpszKeyName = v15;
      }
      v16 = _wcsdup(&Name);
      v17 = v16;
      v110.unused = v16;
      v116 = 14;
      lpszKeyName = CPEString::Append(&ppv, &v110, lpszKeyName)->m_String;
      LOBYTE(v116) = 15;
      v18 = TlsGetValue(gdwTlsIndex);
      v112 = PE_OpenKey(hKey, lpszKeyName, 0, v18 | 0x20019, &KeyHandle) == 0;
      free(ppv);
      free(v17);
      v19 = v111;
      if ( v111 & 2 )
      {
        v111 &= 0xFFFFFFFD;
        v102 = v111;
        free(pszResult);
        v19 = v111;
      }
      v116 = -1;
      if ( v19 & 1 )
      {
        v111 = v19 & 0xFFFFFFFE;
        v102 = v19 & 0xFFFFFFFE;
        free(v13);
      }
      if ( v112 )
      {
        cbData = 520;
        if ( !RegQueryValueExW(KeyHandle, L"Debugger", 0, 0, Data, &cbData) )
        {
          pszText = malloc(2u);
          *pszText = 0;
          v116 = 16;
          v110.unused = malloc(2u);
          *v110.unused = 0;
          v104 = malloc(2u);
          *v104 = 0;
          v54.strValue[0] = malloc(2u);
          *v54.strValue[0] = 0;
          v54.strValue[1] = 0;
          v54.strValue[2] = 0;
          v54.strValue[3] = 0;
          LOBYTE(v116) = 19;
          sub_FD7040(Data, &v54);
          sub_FD4EE0(&szArg4, v106, &v54, 0);
          LOBYTE(v116) = 20;
          v94.unused = sub_FD4ED0();
          v82 = _wcsdup(&Name);
          v20 = v98;
          v21 = &gszNullString;
          if ( v98 )
            v21 = v98;
          szArg3 = _wcsdup(v21);
          v101 = _wcsdup(&gszNullString);
          v22 = &gszNullString;
          if ( v20 )
            v22 = v20;
          szKeyName = _wcsdup(v22);
          v23 = _wcsdup(&Name);
          lpszKeyName = v23;
          v24 = CPEString::Append(&str, &lpszKeyName, L"\\Debugger");
          LOBYTE(v116) = 26;
          v25 = MakeRegistryKeyName(&v54.strValue[5], v105, &szArg3, v24);
          LOBYTE(v116) = 27;
          v26 = MakeRegistryKeyName(&v54.strValue[4], v105, &szKeyName, &v101);
          LOBYTE(v116) = 28;
          v112 = sub_FD3D40(v106, v26, v25, &v82, &szArg4, &pszText, &v104, &v54.strValue[6]);
          free(v54.strValue[4]);
          free(v54.strValue[5]);
          free(str.m_String);
          free(v23);
          free(szKeyName);
          free(v101);
          free(szArg3);
          free(v82);
          if ( v112 )
          {
            if ( a4 == -1 )
            {
              v86 = _wcsdup(&gszNullString);
              v78 = _wcsdup(&gszNullString);
              v88 = _wcsdup(&gszNullString);
              v74 = _wcsdup(&gszNullString);
              v73 = _wcsdup(&gszNullString);
              str3.m_String = _wcsdup(&gszNullString);
              v69 = _wcsdup(&gszNullString);
              v27 = v98;
              v28 = &gszNullString;
              if ( v98 )
                v28 = v98;
              v71 = _wcsdup(v28);
              v75 = _wcsdup(&gszNullString);
              v29 = &gszNullString;
              if ( v27 )
                v29 = v27;
              v77 = _wcsdup(v29);
              LOBYTE(v116) = 38;
              v30 = MakeRegistryKeyName(v64, v105, &v71, &v69);
              LOBYTE(v116) = 39;
              v31 = MakeRegistryKeyName(v58, v105, &v77, &v75);
              LOBYTE(v116) = 40;
              a4 = sub_FD3FF0(v106, 0, 0xFFFFFFFF, 0, v31, v30, &str3);
              free(*v58);
              free(*v64);
              free(v77);
              free(v75);
              free(v71);
              free(v69);
              free(str3.m_String);
              free(v73);
              free(v74);
              free(v88);
              free(v78);
              free(v86);
            }
            else
            {
              v27 = v98;
            }
            v92 = _wcsdup(&gszNullString);
            v76 = _wcsdup(Data);
            v32 = &gszNullString;
            if ( v27 )
              v32 = v27;
            v84 = _wcsdup(v32);
            ppv3 = _wcsdup(&Name);
            v33 = _wcsdup(&Name);
            lpszKeyName = v33;
            v34 = CPEString::Append(&v60, &lpszKeyName, L"\\Debugger");
            LOBYTE(v116) = 46;
            v35 = MakeRegistryKeyName(v56, v105, &v84, v34);
            LOBYTE(v116) = 47;
            sub_FD3FF0(v106, v94.unused, a4, 1u, &ppv3, v35, &szArg4);
            free(*v56);
            free(v60.m_String);
            free(v33);
            free(ppv3);
            free(v84);
            free(v76);
            free(v92);
          }
          free(szArg4);
          sub_FD21F0(&v54);
          free(v104);
          free(v110.unused);
          v116 = -1;
          free(pszText);
        }
        RegCloseKey(KeyHandle);
      }
      v36 = TlsGetValue(gdwTlsIndex);
      if ( !PE_OpenKey(hKey, &Name, 0, v36 | 0x20019, &KeyHandle) )
      {
        cbData = 4;
        if ( !RegQueryValueExW(KeyHandle, L"GlobalFlag", 0, 0, v55, &cbData) && *v55 & 0x100 )
        {
          if ( a4 == -1 )
          {
            a1a = _wcsdup(&gszNullString);
            v116 = 48;
            v79 = _wcsdup(&gszNullString);
            v81 = _wcsdup(&gszNullString);
            v83 = _wcsdup(&gszNullString);
            v85 = _wcsdup(&gszNullString);
            v87.m_String = _wcsdup(&gszNullString);
            v89 = _wcsdup(&gszNullString);
            v37 = v98;
            v38 = &gszNullString;
            if ( v98 )
              v38 = v98;
            v91 = _wcsdup(v38);
            v80 = _wcsdup(&gszNullString);
            v39 = &gszNullString;
            if ( v37 )
              v39 = v37;
            v72 = _wcsdup(v39);
            v40 = v105;
            LOBYTE(v116) = 57;
            v41 = MakeRegistryKeyName(v65, v105, &v91, &v89);
            LOBYTE(v116) = 58;
            v42 = MakeRegistryKeyName(v67, v40, &v72, &v80);
            LOBYTE(v116) = 59;
            a4 = sub_FD3FF0(v106, 0, 0xFFFFFFFF, 0, v42, v41, &v87);
            free(*v67);
            free(*v65);
            free(v72);
            free(v80);
            free(v91);
            free(v89);
            free(v87.m_String);
            free(v85);
            free(v83);
            free(v81);
            free(v79);
            free(a1a);
          }
          if ( a5 )
          {
            lpszKeyName = &gszNullString;
          }
          else
          {
            v12 = _wcsdup(L"AutorunsDisabled");
            lpszKeyName = v12;
            v43 = operator+(&v59, L"\\", &lpszKeyName);
            v111 |= 0xCu;
            v44 = v43->m_String;
            v102 = v111;
            lpszKeyName = v44;
          }
          v45 = _wcsdup(&Name);
          v46 = v45;
          v110.unused = v45;
          v47 = &gszNullString;
          if ( v98 )
            v47 = v98;
          v48 = _wcsdup(v47);
          v49 = v48;
          v94.unused = v48;
          v50 = CPEString::Append(&v61, &v94, L"\\");
          v51 = CPEString::Append(&ppv1, v50, &v110);
          CPEString::Append(&v57, v51, lpszKeyName);
          v116 = 60;
          free(ppv1);
          free(v61.m_String);
          free(v49);
          free(v46);
          v52 = v111;
          if ( v111 & 8 )
          {
            v111 &= 0xFFFFFFF7;
            v102 = v111;
            free(v59.m_String);
            v52 = v111;
          }
          if ( v52 & 4 )
          {
            v111 = v52 & 0xFFFFFFFB;
            v102 = v52 & 0xFFFFFFFB;
            free(v12);
          }
          v53 = v57.m_String;
          sub_FE6A10(v106, v105, v57.m_String, L"VerifierDlls", &Name, 32, a4);
          v116 = -1;
          free(v53);
        }
        RegCloseKey(KeyHandle);
      }
      ++*szArg;
    }
    while ( !RegEnumKeyW(hKey, *szArg, &Name, 0x104u) );
  }
  RegCloseKey(hKey);
  return a4;
}

//----- (00FE5E10) --------------------------------------------------------
void *__cdecl PE_UpdateRegistry2(int a1, void *a2, OLECHAR *psz)
{
  _bstr_t *v3; // eax
  _bstr_t *v4; // eax
  Data_t_bstr_t *v5; // esi
  Data_t_bstr_t *v6; // esi
  Data_t_bstr_t *v7; // esi
  void *v8; // eax
  void *v9; // eax
  void *v10; // esi
  void *v11; // edi
  void *v13; // [esp+10h] [ebp-1Ch]
  _bstr_t v14; // [esp+14h] [ebp-18h]
  _bstr_t v15; // [esp+18h] [ebp-14h]
  _bstr_t a1a; // [esp+1Ch] [ebp-10h]
  int v17; // [esp+28h] [ebp-4h]

  _bstr_t::_bstr_t(&v14, L"AutorunsDisabled");
  v17 = 0;
  v3 = _bstr_t::_bstr_t(&v15, L"\\");
  LOBYTE(v17) = 1;
  v4 = _bstr_t::operator+(&a1a, psz, v3);
  LOBYTE(v17) = 2;
  _bstr_t::operator+(v4, &v13, &v14);
  v5 = a1a.m_Data;
  if ( a1a.m_Data )
  {
    if ( !InterlockedDecrement(&a1a.m_Data->m_RefCount) && v5 )
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
    a1a.m_Data = 0;
  }
  v6 = v15.m_Data;
  if ( v15.m_Data )
  {
    if ( !InterlockedDecrement(&v15.m_Data->m_RefCount) && v6 )
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
    v15.m_Data = 0;
  }
  v7 = v14.m_Data;
  LOBYTE(v17) = 6;
  if ( v14.m_Data && !InterlockedDecrement(&v14.m_Data->m_RefCount) )
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
  v8 = sub_FE5FF0(a1, a2, psz, 0xFFFFFFFF, 1);
  v9 = sub_FE5FF0(a1, a2, psz, v8, 0);
  v10 = v13;
  v11 = v9;
  if ( v13 && !InterlockedDecrement(v13 + 2) && v10 )
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
  return v11;
}

//----- (00FE5FF0) --------------------------------------------------------
void *__cdecl sub_FE5FF0(int a1, void *a2, wchar_t *a3, void *a4, char a5)
{
  const wchar_t *v5; // eax
  const wchar_t *v6; // eax
  CPEString *v7; // esi
  CPEString *v8; // eax
  wchar_t *v9; // eax
  wchar_t *v10; // eax
  int v11; // ecx
  void *v12; // ebx
  const WCHAR **v13; // eax
  WCHAR *v14; // eax
  WCHAR *v15; // ebx
  wchar_t *v16; // eax
  wchar_t *v17; // edi
  const wchar_t *v18; // eax
  wchar_t *v19; // esi
  CPEString *v20; // eax
  CPEString *v21; // eax
  CPEString *v22; // eax
  CPEString *v23; // eax
  unsigned int v24; // eax
  wchar_t *v25; // esi
  CPEString *v26; // eax
  WCHAR *v27; // edi
  unsigned int v28; // eax
  int v29; // eax
  const WCHAR **v30; // edi
  const WCHAR **v31; // ecx
  const WCHAR **v32; // eax
  const WCHAR **v33; // eax
  CPEString *v34; // esi
  CPEString *v35; // eax
  const WCHAR **v36; // esi
  const WCHAR **v37; // eax
  const WCHAR **v38; // eax
  CPEString *v39; // eax
  const WCHAR **v40; // eax
  CPEString *v41; // eax
  tagPEStringStruct v43; // [esp+10h] [ebp-494h]
  HKEY KeyHandle; // [esp+2Ch] [ebp-478h]
  HKEY hKey; // [esp+30h] [ebp-474h]
  WCHAR v46[2]; // [esp+34h] [ebp-470h]
  WCHAR szArg[2]; // [esp+38h] [ebp-46Ch]
  int v48; // [esp+3Ch] [ebp-468h]
  void *v49; // [esp+40h] [ebp-464h]
  LPCWSTR szArg3; // [esp+44h] [ebp-460h]
  WCHAR *pszText; // [esp+48h] [ebp-45Ch]
  LPCWSTR v52; // [esp+4Ch] [ebp-458h]
  HKEY hRootKey; // [esp+50h] [ebp-454h]
  LPCWSTR szArg4; // [esp+54h] [ebp-450h]
  CPEString str3; // [esp+58h] [ebp-44Ch]
  CPEString v56; // [esp+5Ch] [ebp-448h]
  LPCWSTR szKeyName; // [esp+60h] [ebp-444h]
  WCHAR *ppv3; // [esp+64h] [ebp-440h]
  LPCWSTR v59; // [esp+68h] [ebp-43Ch]
  WCHAR *ppv; // [esp+6Ch] [ebp-438h]
  WCHAR *ppv1; // [esp+70h] [ebp-434h]
  LPCWSTR v62; // [esp+74h] [ebp-430h]
  HKEY__ v63; // [esp+78h] [ebp-42Ch]
  void *a1a; // [esp+7Ch] [ebp-428h]
  char v65; // [esp+83h] [ebp-421h]
  wchar_t Data[260]; // [esp+84h] [ebp-420h]
  wchar_t v67[260]; // [esp+28Ch] [ebp-218h]
  int v68; // [esp+4A0h] [ebp-4h]

  v48 = a1;
  hRootKey = a2;
  *szArg = a3;
  if ( a4 == -1 )
  {
    v62 = _wcsdup(&gszNullString);
    v68 = 0;
    v49 = _wcsdup(&gszNullString);
    ppv1 = _wcsdup(&gszNullString);
    ppv = _wcsdup(&gszNullString);
    szKeyName = _wcsdup(&gszNullString);
    str3.m_String = _wcsdup(&gszNullString);
    szArg4 = _wcsdup(&gszNullString);
    v5 = &gszNullString;
    if ( a3 )
      v5 = a3;
    pszText = _wcsdup(v5);
    v52 = _wcsdup(&gszNullString);
    v6 = &gszNullString;
    if ( a3 )
      v6 = a3;
    szArg3 = _wcsdup(v6);
    LOBYTE(v68) = 9;
    v7 = MakeRegistryKeyName(&a1a, a2, &pszText, &szArg4);
    LOBYTE(v68) = 10;
    v8 = MakeRegistryKeyName(&v63, a2, &szArg3, &v52);
    LOBYTE(v68) = 11;
    a4 = sub_FD3FF0(v48, 0, 0xFFFFFFFF, 0, v8, v7, &str3);
    free(v63.unused);
    free(a1a);
    free(szArg3);
    free(v52);
    free(pszText);
    free(szArg4);
    free(str3.m_String);
    free(szKeyName);
    free(ppv);
    free(ppv1);
    free(v49);
    free(v62);
  }
  v62 = malloc(2u);
  *v62 = 0;
  v68 = 12;
  hKey = 0;
  v9 = _wcsdup(a3);
  szArg3 = v9;
  v10 = wcsrchr(v9, 0x5Cu);
  *v10 = 0;
  v11 = (v10 + 1);
  *v46 = v10 + 1;
  if ( a5 )
  {
    v12 = _wcsdup(a3);
    v49 = v12;
    free(v62);
  }
  else
  {
    v13 = &gszNullString;
    if ( v11 )
      v13 = v11;
    v14 = _wcsdup(v13);
    v15 = v14;
    ppv3 = v14;
    v16 = _wcsdup(L"AutorunsDisabled");
    v17 = v16;
    a1a = v16;
    v18 = &gszNullString;
    if ( szArg3 )
      v18 = szArg3;
    v19 = _wcsdup(v18);
    v63.unused = v19;
    v20 = CPEString::Append(&ppv, &v63, L"\\");
    v21 = CPEString::Append(&ppv1, v20, &a1a);
    v22 = CPEString::Append(&v59, v21, L"\\");
    v23 = CPEString::Append(&v56, v22, &ppv3);
    v49 = _wcsdup(v23->m_String);
    free(v62);
    free(v56.m_String);
    free(v59);
    free(ppv1);
    free(ppv);
    free(v19);
    free(v17);
    free(v15);
    v12 = v49;
  }
  v24 = TlsGetValue(gdwTlsIndex);
  if ( !PE_OpenKey(hRootKey, v12, 0, v24 | 0x20019, &hKey) )
  {
    KeyHandle = 0;
    v43.strValue[6] = 520;
    if ( !RegQueryValueExW(hKey, 0, 0, 0, Data, &v43.strValue[6]) )
    {
      v25 = _wcsdup(Data);
      v63.unused = v25;
      v26 = operator+(&ppv3, L"Software\\Classes\\", &v63);
      v27 = CPEString::Append(&a1a, v26, L"\\shell\\open\\command")->m_String;
      LOBYTE(v68) = 15;
      v28 = TlsGetValue(gdwTlsIndex);
      v65 = PE_OpenKey(hRootKey, v27, 0, v28 | 0x20019, &KeyHandle) == 0;
      free(a1a);
      free(ppv3);
      LOBYTE(v68) = 12;
      free(v25);
      if ( v65 )
      {
        v43.strValue[6] = 520;
        if ( !RegQueryValueExW(KeyHandle, 0, 0, 0, v67, &v43.strValue[6]) )
        {
          v29 = wcscmp(v67, L"\"%1\" %*");
          if ( v29 )
            v29 = -(v29 < 0) | 1;
          if ( v29 )
          {
            szArg4 = malloc(2u);
            *szArg4 = 0;
            v52 = malloc(2u);
            *v52 = 0;
            pszText = malloc(2u);
            *pszText = 0;
            sub_FD2170(&v43);
            LOBYTE(v68) = 19;
            sub_FD7040(v67, &v43);
            sub_FD4EE0(&str3, v48, &v43, 0);
            LOBYTE(v68) = 20;
            v43.strValue[5] = sub_FD4ED0();
            v59 = _wcsdup(&gszNullString);
            v30 = *szArg;
            v31 = &gszNullString;
            if ( *szArg )
              v31 = *szArg;
            szKeyName = _wcsdup(v31);
            ppv = _wcsdup(&gszNullString);
            v32 = &gszNullString;
            if ( v30 )
              v32 = v30;
            ppv1 = _wcsdup(v32);
            v33 = &gszNullString;
            if ( v30 )
              v33 = v30;
            v62 = _wcsdup(v33);
            LOBYTE(v68) = 25;
            v34 = MakeRegistryKeyName(&a1a, hRootKey, &szKeyName, &v59);
            LOBYTE(v68) = 26;
            v35 = MakeRegistryKeyName(&v63, hRootKey, &ppv1, &ppv);
            LOBYTE(v68) = 27;
            v65 = sub_FD3D40(v48, &v62, v35, v34, &str3, &szArg4, &pszText, &v43.strValue[4]);
            free(v63.unused);
            free(a1a);
            free(v62);
            free(ppv1);
            free(ppv);
            free(szKeyName);
            LOBYTE(v68) = 20;
            free(v59);
            if ( v65 )
            {
              if ( a4 == -1 )
              {
                v63.unused = _wcsdup(&gszNullString);
                a1a = _wcsdup(&gszNullString);
                ppv3 = _wcsdup(&gszNullString);
                v56.m_String = _wcsdup(&gszNullString);
                szKeyName = _wcsdup(&gszNullString);
                ppv = _wcsdup(&gszNullString);
                ppv1 = _wcsdup(&gszNullString);
                v36 = &gszNullString;
                v37 = &gszNullString;
                if ( v30 )
                  v37 = v30;
                v62 = _wcsdup(v37);
                v38 = &gszNullString;
                if ( *v46 )
                  v38 = *v46;
                v59 = _wcsdup(v38);
                LOBYTE(v68) = 36;
                v39 = MakeRegistryKeyName(szArg, hRootKey, &v62, &ppv1);
                LOBYTE(v68) = 37;
                a4 = sub_FD3FF0(v48, 0, 0xFFFFFFFF, 0, &v59, v39, &ppv);
                free(*szArg);
                free(v59);
                free(v62);
                free(ppv1);
                free(ppv);
                free(szKeyName);
                free(v56.m_String);
                free(ppv3);
                free(a1a);
                free(v63.unused);
              }
              else
              {
                v36 = &gszNullString;
              }
              v59 = _wcsdup(&gszNullString);
              v56.m_String = _wcsdup(v67);
              ppv3 = _wcsdup(&gszNullString);
              v40 = &gszNullString;
              if ( v30 )
                v40 = v30;
              a1a = _wcsdup(v40);
              if ( v30 )
                v36 = v30;
              v63.unused = _wcsdup(v36);
              LOBYTE(v68) = 42;
              v41 = MakeRegistryKeyName(v46, hRootKey, &a1a, &ppv3);
              LOBYTE(v68) = 43;
              sub_FD3FF0(v48, v43.strValue[5], a4, 3u, &v63, v41, &str3);
              free(*v46);
              free(v63.unused);
              free(a1a);
              free(ppv3);
              free(v56.m_String);
              free(v59);
            }
            free(str3.m_String);
            sub_FD21F0(&v43);
            free(pszText);
            free(v52);
            free(szArg4);
          }
        }
        RegCloseKey(KeyHandle);
      }
    }
    RegCloseKey(hKey);
  }
  free(szArg3);
  free(v12);
  return a4;
}
// 109244C: using guessed type wchar_t a1_0[8];

//----- (00FE6A10) --------------------------------------------------------
void *__cdecl sub_FE6A10(int a1, void *a2, wchar_t *psz, LPCWSTR lpValueName, wchar_t *a5, int a6, void *a7)
{
  unsigned int v7; // eax
  int v8; // esi
  char *v9; // ecx
  int v10; // ebx
  int v11; // edi
  void *v12; // esi
  const wchar_t **v13; // eax
  WCHAR *v14; // esi
  const wchar_t *v15; // ecx
  const wchar_t *v16; // eax
  const wchar_t *v17; // eax
  CPEString *v18; // esi
  CPEString *v19; // eax
  char v20; // bl
  const wchar_t *v21; // eax
  const wchar_t *v22; // eax
  const wchar_t *v23; // eax
  const wchar_t *v24; // eax
  CPEString *v25; // eax
  void *v27; // [esp+10h] [ebp-78h]
  int v28; // [esp+14h] [ebp-74h]
  int v29; // [esp+18h] [ebp-70h]
  WCHAR v30[2]; // [esp+1Ch] [ebp-6Ch]
  int a2a; // [esp+20h] [ebp-68h]
  int v32; // [esp+24h] [ebp-64h]
  void *a1a; // [esp+28h] [ebp-60h]
  WCHAR szArg[2]; // [esp+2Ch] [ebp-5Ch]
  void *v35; // [esp+30h] [ebp-58h]
  HKEY hKey; // [esp+34h] [ebp-54h]
  int v37; // [esp+38h] [ebp-50h]
  unsigned int v38; // [esp+3Ch] [ebp-4Ch]
  void *v39; // [esp+40h] [ebp-48h]
  LPCWSTR v40; // [esp+44h] [ebp-44h]
  LPCWSTR szKeyName; // [esp+48h] [ebp-40h]
  WCHAR *ppv3; // [esp+4Ch] [ebp-3Ch]
  LPCWSTR szArg4; // [esp+50h] [ebp-38h]
  WCHAR *pszText; // [esp+54h] [ebp-34h]
  LPCWSTR v45; // [esp+58h] [ebp-30h]
  LPCWSTR szArg3; // [esp+5Ch] [ebp-2Ch]
  void *v47; // [esp+60h] [ebp-28h]
  WCHAR *v48; // [esp+64h] [ebp-24h]
  wchar_t *v49; // [esp+68h] [ebp-20h]
  void *v50; // [esp+6Ch] [ebp-1Ch]
  void *v51; // [esp+70h] [ebp-18h]
  CPEString str3; // [esp+74h] [ebp-14h]
  int v53; // [esp+84h] [ebp-4h]

  str3.m_String = malloc(2u);
  *str3.m_String = 0;
  v53 = 0;
  v50 = malloc(2u);
  *v50 = 0;
  v47 = malloc(2u);
  *v47 = 0;
  v48 = malloc(2u);
  *v48 = 0;
  v51 = malloc(2u);
  *v51 = 0;
  LOBYTE(v53) = 4;
  v7 = TlsGetValue(gdwTlsIndex);
  if ( !PE_OpenKey(a2, psz, 0, v7 | 0x20019, &hKey) )
  {
    v49 = malloc(2u);
    *v49 = 0;
    LOBYTE(v53) = 5;
    if ( !PE_ReadRegKey(hKey, lpValueName, 0, 0, &v49) && wcslen(v49) )
    {
      v27 = 0;
      v28 = 0;
      v29 = 0;
      LOBYTE(v53) = 6;
      sub_FD6DD0(v49, 44, &v27, 0);
      v8 = v28;
      v9 = v27;
      v38 = 0;
      if ( (v28 - v27) >> 4 )
      {
        v10 = 0;
        v37 = 0;
        do
        {
          v11 = &v9[v10];
          v12 = v51;
          v51 = _wcsdup(**&v9[v10 + 4]);
          free(v12);
          v13 = sub_FD4EE0(&v35, a1, v11, 0);
          v14 = str3.m_String;
          str3.m_String = _wcsdup(*v13);
          free(v14);
          free(v35);
          a2a = sub_FD4ED0();
          v15 = &gszNullString;
          if ( lpValueName )
            v15 = lpValueName;
          szArg4 = _wcsdup(v15);
          v16 = &gszNullString;
          if ( psz )
            v16 = psz;
          pszText = _wcsdup(v16);
          v45 = _wcsdup(&gszNullString);
          v17 = &gszNullString;
          if ( psz )
            v17 = psz;
          szArg3 = _wcsdup(v17);
          LOBYTE(v53) = 10;
          v18 = MakeRegistryKeyName(&a1a, a2, &pszText, &szArg4);
          LOBYTE(v53) = 11;
          v19 = MakeRegistryKeyName(szArg, a2, &szArg3, &v45);
          LOBYTE(v53) = 12;
          v20 = sub_FD3D40(a1, v19, v18, v11, &str3, &v50, &v48, &v32);
          free(*szArg);
          free(a1a);
          free(szArg3);
          free(v45);
          free(pszText);
          LOBYTE(v53) = 6;
          free(szArg4);
          if ( v20 )
          {
            v21 = &gszNullString;
            if ( lpValueName )
              v21 = lpValueName;
            v39 = _wcsdup(v21);
            v22 = &gszNullString;
            if ( lpValueName )
              v22 = lpValueName;
            v40 = _wcsdup(v22);
            v23 = &gszNullString;
            if ( psz )
              v23 = psz;
            szKeyName = _wcsdup(v23);
            v24 = &gszNullString;
            if ( a5 )
              v24 = a5;
            ppv3 = _wcsdup(v24);
            LOBYTE(v53) = 16;
            v25 = MakeRegistryKeyName(v30, a2, &szKeyName, &v40);
            LOBYTE(v53) = 17;
            sub_FD3FF0(a1, a2a, a7, 1u, &ppv3, v25, &str3);
            free(*v30);
            free(ppv3);
            free(szKeyName);
            free(v40);
            LOBYTE(v53) = 6;
            free(v39);
          }
          v8 = v28;
          v9 = v27;
          v10 = v37 + 16;
          ++v38;
          v37 += 16;
        }
        while ( v38 < (v28 - v27) >> 4 );
      }
      if ( v9 )
      {
        sub_FD2BF0(v9, v8);
        j__free(v27);
      }
    }
    RegCloseKey(hKey);
    free(v49);
  }
  free(v51);
  free(v48);
  free(v47);
  free(v50);
  free(str3.m_String);
  return a7;
}

//----- (00FE6E10) --------------------------------------------------------
void *__cdecl sub_FE6E10(int a1, void *a2, OLECHAR *psz, LPCWSTR lpValueName)
{
  _bstr_t *v4; // eax
  _bstr_t *v5; // eax
  Data_t_bstr_t *v6; // esi
  Data_t_bstr_t *v7; // esi
  Data_t_bstr_t *v8; // esi
  void *v9; // eax
  wchar_t *v10; // ecx
  void *v11; // eax
  void *v12; // esi
  void *v13; // edi
  void *v15; // [esp+10h] [ebp-1Ch]
  _bstr_t v16; // [esp+14h] [ebp-18h]
  _bstr_t v17; // [esp+18h] [ebp-14h]
  _bstr_t a1a; // [esp+1Ch] [ebp-10h]
  int v19; // [esp+28h] [ebp-4h]

  _bstr_t::_bstr_t(&v16, L"AutorunsDisabled");
  v19 = 0;
  v4 = _bstr_t::_bstr_t(&v17, L"\\");
  LOBYTE(v19) = 1;
  v5 = _bstr_t::operator+(&a1a, psz, v4);
  LOBYTE(v19) = 2;
  _bstr_t::operator+(v5, &v15, &v16);
  v6 = a1a.m_Data;
  if ( a1a.m_Data )
  {
    if ( !InterlockedDecrement(&a1a.m_Data->m_RefCount) && v6 )
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
    a1a.m_Data = 0;
  }
  v7 = v17.m_Data;
  if ( v17.m_Data )
  {
    if ( !InterlockedDecrement(&v17.m_Data->m_RefCount) && v7 )
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
    v17.m_Data = 0;
  }
  v8 = v16.m_Data;
  LOBYTE(v19) = 6;
  if ( v16.m_Data && !InterlockedDecrement(&v16.m_Data->m_RefCount) )
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
  v9 = sub_FE7000(a1, a2, psz, lpValueName, -1);
  if ( v15 )
    v10 = *v15;
  else
    v10 = 0;
  v11 = sub_FE7000(a1, a2, v10, lpValueName, v9);
  v12 = v15;
  v13 = v11;
  if ( v15 && !InterlockedDecrement(v15 + 2) && v12 )
  {
    if ( *v12 )
    {
      SysFreeString(*v12);
      *v12 = 0;
    }
    if ( *(v12 + 1) )
    {
      j_j__free(*(v12 + 1));
      *(v12 + 1) = 0;
    }
    j__free(v12);
  }
  return v13;
}

//----- (00FE7000) --------------------------------------------------------
void *__cdecl sub_FE7000(int a1, void *a2, wchar_t *psz, LPCWSTR lpValueName, int a5)
{
  void *v5; // ebx
  const wchar_t *v6; // eax
  const wchar_t *v7; // eax
  const wchar_t *v8; // eax
  const wchar_t *v9; // eax
  CPEString *v10; // esi
  CPEString *v11; // eax
  LPCWSTR v13; // ebx
  wchar_t *v14; // esi
  DWORD v15; // eax
  int v16; // edi
  _WORD *v17; // eax
  WCHAR *v18; // eax
  const WCHAR **v19; // ecx
  const wchar_t *v20; // eax
  const WCHAR **v21; // eax
  const wchar_t *v22; // eax
  CPEString *v23; // edi
  CPEString *v24; // eax
  int v25; // ST40_4
  char v26; // bl
  const wchar_t *v27; // eax
  const wchar_t *v28; // eax
  const wchar_t *v29; // eax
  const wchar_t *v30; // eax
  CPEString *v31; // edi
  CPEString *v32; // eax
  const WCHAR **v33; // eax
  const wchar_t *v34; // eax
  CPEString *v35; // eax
  int a2a; // [esp+10h] [ebp-A4h]
  int v37; // [esp+14h] [ebp-A0h]
  int v38; // [esp+18h] [ebp-9Ch]
  int v39; // [esp+1Ch] [ebp-98h]
  WCHAR v40[2]; // [esp+20h] [ebp-94h]
  WCHAR v41[2]; // [esp+24h] [ebp-90h]
  WCHAR v42[2]; // [esp+28h] [ebp-8Ch]
  DWORD dwValue; // [esp+2Ch] [ebp-88h]
  WCHAR v44[2]; // [esp+30h] [ebp-84h]
  int v45; // [esp+34h] [ebp-80h]
  WCHAR v46[2]; // [esp+38h] [ebp-7Ch]
  void *v47; // [esp+3Ch] [ebp-78h]
  void *v48; // [esp+40h] [ebp-74h]
  LPCWSTR v49; // [esp+44h] [ebp-70h]
  WCHAR *ppv3; // [esp+48h] [ebp-6Ch]
  LPCWSTR v51; // [esp+4Ch] [ebp-68h]
  void *v52; // [esp+50h] [ebp-64h]
  LPCWSTR v53; // [esp+54h] [ebp-60h]
  void *v54; // [esp+58h] [ebp-5Ch]
  LPCWSTR v55; // [esp+5Ch] [ebp-58h]
  CPEString str3; // [esp+60h] [ebp-54h]
  LPCWSTR v57; // [esp+64h] [ebp-50h]
  void *v58; // [esp+68h] [ebp-4Ch]
  void *a1a; // [esp+6Ch] [ebp-48h]
  HKEY hKey; // [esp+70h] [ebp-44h]
  WCHAR szArg[2]; // [esp+74h] [ebp-40h]
  LPCWSTR szKeyName; // [esp+78h] [ebp-3Ch]
  void *v63; // [esp+7Ch] [ebp-38h]
  LPCWSTR v64; // [esp+80h] [ebp-34h]
  LPCWSTR v65; // [esp+84h] [ebp-30h]
  LPCWSTR v66; // [esp+88h] [ebp-2Ch]
  LPCWSTR v67; // [esp+8Ch] [ebp-28h]
  LPCWSTR szArg3; // [esp+90h] [ebp-24h]
  DWORD cbData; // [esp+94h] [ebp-20h]
  LPCWSTR v70; // [esp+98h] [ebp-1Ch]
  void *ppv1; // [esp+9Ch] [ebp-18h]
  WCHAR *pszText; // [esp+A0h] [ebp-14h]
  LPCWSTR szArg4; // [esp+A4h] [ebp-10h]
  int v74; // [esp+B0h] [ebp-4h]

  v5 = a5;
  ppv1 = a5;
  if ( dword_10C31D8 && a5 == -1 )
  {
    v63 = _wcsdup(&gszNullString);
    v74 = 0;
    v65 = _wcsdup(&gszNullString);
    v66 = _wcsdup(&gszNullString);
    szKeyName = _wcsdup(&gszNullString);
    v64 = _wcsdup(&gszNullString);
    v67 = _wcsdup(&gszNullString);
    v6 = &gszNullString;
    if ( lpValueName )
      v6 = lpValueName;
    szArg4 = _wcsdup(v6);
    v7 = &gszNullString;
    if ( psz )
      v7 = psz;
    pszText = _wcsdup(v7);
    v8 = &gszNullString;
    if ( lpValueName )
      v8 = lpValueName;
    v70 = _wcsdup(v8);
    v9 = &gszNullString;
    if ( psz )
      v9 = psz;
    szArg3 = _wcsdup(v9);
    LOBYTE(v74) = 9;
    v10 = MakeRegistryKeyName(&a1a, a2, &pszText, &szArg4);
    LOBYTE(v74) = 10;
    v11 = MakeRegistryKeyName(szArg, a2, &szArg3, &v70);
    LOBYTE(v74) = 11;
    v5 = sub_FD3FF0(a1, 0, 0xFFFFFFFF, 0, v11, v10, &v67);
    ppv1 = v5;
    free(*szArg);
    free(a1a);
    free(szArg3);
    free(v70);
    free(pszText);
    free(szArg4);
    free(v67);
    free(v64);
    free(szKeyName);
    free(v66);
    free(v65);
    v74 = -1;
    free(v63);
  }
  hKey = 0;
  PE_OpenKey(a2, psz, 0, 0x20019u, &hKey);
  if ( !hKey )
    return v5;
  v13 = lpValueName;
  cbData = 0;
  RegQueryValueExW(hKey, lpValueName, 0, 0, 0, &cbData);
  v14 = operator new[](2 * ((cbData >> 1) + 2));
  RegQueryValueExW(hKey, lpValueName, 0, 0, v14, &cbData);
  v15 = cbData >> 1;
  cbData = v15;
  if ( v15 > 2 )
  {
    v14[v15 - 1] = 0;
    v14[cbData] = 0;
    if ( *v14 )
    {
      v16 = a1;
      do
      {
        v17 = malloc(2u);
        a2a = v17;
        *v17 = 0;
        v37 = 0;
        v38 = 0;
        v39 = 0;
        v74 = 12;
        sub_FD6CC0(v14, &a2a);
        *szArg = _wcsdup(v14);
        LOBYTE(v74) = 13;
        sub_FD4EE0(&szArg4, v16, &a2a, 0);
        v18 = szArg4;
        if ( *szArg4 )
        {
          pszText = malloc(2u);
          *pszText = 0;
          szArg3 = malloc(2u);
          *szArg3 = 0;
          v70 = malloc(2u);
          *v70 = 0;
          LOBYTE(v74) = 17;
          dwValue = sub_FD4ED0();
          v19 = &gszNullString;
          if ( v13 )
            v19 = v13;
          v64 = _wcsdup(v19);
          v20 = &gszNullString;
          if ( psz )
            v20 = psz;
          szKeyName = _wcsdup(v20);
          v21 = &gszNullString;
          if ( v13 )
            v21 = v13;
          v66 = _wcsdup(v21);
          v22 = &gszNullString;
          if ( psz )
            v22 = psz;
          v65 = _wcsdup(v22);
          v63 = _wcsdup(v14);
          LOBYTE(v74) = 22;
          v23 = MakeRegistryKeyName(v44, a2, &szKeyName, &v64);
          LOBYTE(v74) = 23;
          v24 = MakeRegistryKeyName(v46, a2, &v65, &v66);
          LOBYTE(v74) = 24;
          v25 = v23;
          v16 = a1;
          v26 = sub_FD3D40(a1, &v63, v24, v25, &szArg4, &pszText, &v70, &v45);
          free(*v46);
          free(*v44);
          free(v63);
          free(v65);
          free(v66);
          free(szKeyName);
          free(v64);
          if ( v26 )
          {
            if ( ppv1 == -1 )
            {
              v48 = _wcsdup(&gszNullString);
              v52 = _wcsdup(&gszNullString);
              v47 = _wcsdup(&gszNullString);
              v54 = _wcsdup(&gszNullString);
              v58 = _wcsdup(&gszNullString);
              str3.m_String = _wcsdup(&gszNullString);
              v13 = lpValueName;
              v27 = &gszNullString;
              if ( lpValueName )
                v27 = lpValueName;
              v55 = _wcsdup(v27);
              v28 = &gszNullString;
              if ( psz )
                v28 = psz;
              v57 = _wcsdup(v28);
              v29 = &gszNullString;
              if ( lpValueName )
                v29 = lpValueName;
              v49 = _wcsdup(v29);
              v30 = &gszNullString;
              if ( psz )
                v30 = psz;
              v67 = _wcsdup(v30);
              LOBYTE(v74) = 34;
              v31 = MakeRegistryKeyName(v42, a2, &v57, &v55);
              LOBYTE(v74) = 35;
              v32 = MakeRegistryKeyName(v40, a2, &v67, &v49);
              LOBYTE(v74) = 36;
              ppv1 = sub_FD3FF0(a1, 0, 0xFFFFFFFF, 0, v32, v31, &str3);
              free(*v40);
              free(*v42);
              free(v67);
              free(v49);
              free(v57);
              free(v55);
              free(str3.m_String);
              free(v58);
              free(v54);
              free(v47);
              free(v52);
              free(v48);
            }
            else
            {
              v13 = lpValueName;
            }
            a1a = _wcsdup(&gszNullString);
            v33 = &gszNullString;
            if ( v13 )
              v33 = v13;
            v51 = _wcsdup(v33);
            v34 = &gszNullString;
            if ( psz )
              v34 = psz;
            v53 = _wcsdup(v34);
            ppv3 = _wcsdup(v14);
            LOBYTE(v74) = 40;
            v35 = MakeRegistryKeyName(v41, a2, &v53, &v51);
            v16 = a1;
            LOBYTE(v74) = 41;
            sub_FD3FF0(a1, dwValue, ppv1, 5u, &ppv3, v35, &szArg4);
            free(*v41);
            free(ppv3);
            free(v53);
            free(v51);
            free(a1a);
          }
          else
          {
            v13 = lpValueName;
          }
          free(v70);
          free(szArg3);
          free(pszText);
          v18 = szArg4;
        }
        free(v18);
        free(*szArg);
        v74 = -1;
        sub_FD21F0(&a2a);
        v14 = wcschr(v14 + 1, 0) + 1;
      }
      while ( *v14 );
    }
  }
  RegCloseKey(hKey);
  return ppv1;
}
// 10C31D8: using guessed type int dword_10C31D8;

//----- (00FE7710) --------------------------------------------------------
void __cdecl sub_FE7710(int a1, void *a2, void *a3)
{
  _WORD *v3; // ST50_4
  CPEString *v4; // esi
  void *v5; // edi
  CPEString *v6; // eax
  wchar_t *v7; // ST54_4

  v3 = malloc(2u);
  *v3 = 0;
  v4 = a3;
  v5 = sub_FE77C0(a1, a2, *a3, 0xFFFFFFFF);
  v6 = CPEString::Append(&a3, v4, L"\\AutorunsDisabled");
  v7 = _wcsdup(v6->m_String);
  free(v3);
  free(a3);
  sub_FE77C0(a1, a2, v7, v5);
  free(v7);
}

//----- (00FE77C0) --------------------------------------------------------
void *__cdecl sub_FE77C0(int a1, void *a2, wchar_t *psz, void *a4)
{
  WCHAR *v4; // edi
  _WORD *v5; // ebx
  wchar_t *v6; // esi
  const wchar_t *v7; // eax
  const wchar_t *v8; // eax
  CPEString *v9; // esi
  CPEString *v10; // eax
  CPEString *v11; // ebx
  WCHAR *v12; // eax
  WCHAR *v13; // edx
  WCHAR v14; // cx
  WCHAR *v15; // esi
  CPEString *v16; // eax
  WCHAR *v17; // esi
  CPEString *v18; // eax
  _WORD *v19; // eax
  const wchar_t **v20; // eax
  WCHAR *v21; // esi
  const wchar_t *v22; // eax
  const wchar_t *v23; // eax
  CPEString *v24; // esi
  CPEString *v25; // eax
  const wchar_t *v26; // eax
  const wchar_t *v27; // eax
  CPEString *v28; // esi
  CPEString *v29; // eax
  const wchar_t *v30; // eax
  CPEString *v31; // eax
  WCHAR v32; // cx
  tagPEStringStruct v34; // [esp+10h] [ebp-BCh]
  WCHAR v35[2]; // [esp+2Ch] [ebp-A0h]
  WCHAR v36[2]; // [esp+30h] [ebp-9Ch]
  int v37; // [esp+34h] [ebp-98h]
  void *v38; // [esp+38h] [ebp-94h]
  WCHAR v39[2]; // [esp+3Ch] [ebp-90h]
  WCHAR v40[2]; // [esp+40h] [ebp-8Ch]
  WCHAR *ppv; // [esp+44h] [ebp-88h]
  void *v42; // [esp+48h] [ebp-84h]
  LPCWSTR v43; // [esp+4Ch] [ebp-80h]
  HKEY KeyHandle; // [esp+50h] [ebp-7Ch]
  LPCWSTR v45; // [esp+54h] [ebp-78h]
  void *v46; // [esp+58h] [ebp-74h]
  void *v47; // [esp+5Ch] [ebp-70h]
  void *v48; // [esp+60h] [ebp-6Ch]
  void *v49; // [esp+64h] [ebp-68h]
  WCHAR *v50; // [esp+68h] [ebp-64h]
  HKEY hKey; // [esp+6Ch] [ebp-60h]
  void *a1a; // [esp+70h] [ebp-5Ch]
  WCHAR szArg[2]; // [esp+74h] [ebp-58h]
  void *v54; // [esp+78h] [ebp-54h]
  void *v55; // [esp+7Ch] [ebp-50h]
  WCHAR *ppv2; // [esp+80h] [ebp-4Ch]
  wchar_t *v57; // [esp+84h] [ebp-48h]
  wchar_t *v58; // [esp+88h] [ebp-44h]
  LPCWSTR v59; // [esp+8Ch] [ebp-40h]
  LPCWSTR v60; // [esp+90h] [ebp-3Ch]
  LPCWSTR szKeyName; // [esp+94h] [ebp-38h]
  WCHAR *ppv3; // [esp+98h] [ebp-34h]
  LPCWSTR v63; // [esp+9Ch] [ebp-30h]
  LPCWSTR v64; // [esp+A0h] [ebp-2Ch]
  LPCWSTR szArg4; // [esp+A4h] [ebp-28h]
  LPCWSTR v66; // [esp+A8h] [ebp-24h]
  LPCWSTR v67; // [esp+ACh] [ebp-20h]
  WCHAR *pszText; // [esp+B0h] [ebp-1Ch]
  LPCWSTR szArg3; // [esp+B4h] [ebp-18h]
  CPEString str3; // [esp+B8h] [ebp-14h]
  char v71; // [esp+BFh] [ebp-Dh]
  int v72; // [esp+C8h] [ebp-4h]

  v58 = malloc(2u);
  *v58 = 0;
  v72 = 0;
  v4 = malloc(2u);
  ppv2 = v4;
  *v4 = 0;
  v57 = malloc(2u);
  *v57 = 0;
  v5 = malloc(2u);
  v34.strValue[5] = v5;
  *v5 = 0;
  str3.m_String = malloc(2u);
  *str3.m_String = 0;
  v54 = malloc(2u);
  *v54 = 0;
  v55 = malloc(2u);
  *v55 = 0;
  v50 = malloc(2u);
  *v50 = 0;
  v6 = psz;
  LOBYTE(v72) = 7;
  if ( a4 == -1 )
  {
    v64 = _wcsdup(&gszNullString);
    v59 = _wcsdup(&gszNullString);
    szKeyName = _wcsdup(&gszNullString);
    v63 = _wcsdup(&gszNullString);
    v66 = _wcsdup(&gszNullString);
    v67 = _wcsdup(&gszNullString);
    szArg4 = _wcsdup(&gszNullString);
    v7 = &gszNullString;
    if ( psz )
      v7 = psz;
    pszText = _wcsdup(v7);
    v60 = _wcsdup(&gszNullString);
    v8 = &gszNullString;
    if ( psz )
      v8 = psz;
    szArg3 = _wcsdup(v8);
    LOBYTE(v72) = 17;
    v9 = MakeRegistryKeyName(&a1a, a2, &pszText, &szArg4);
    LOBYTE(v72) = 18;
    v10 = MakeRegistryKeyName(szArg, a2, &szArg3, &v60);
    LOBYTE(v72) = 19;
    a4 = sub_FD3FF0(a1, 0, 0xFFFFFFFF, 0, v10, v9, &v67);
    free(*szArg);
    free(a1a);
    free(szArg3);
    free(v60);
    free(pszText);
    free(szArg4);
    free(v67);
    free(v66);
    free(v63);
    free(szKeyName);
    free(v59);
    LOBYTE(v72) = 7;
    free(v64);
    v6 = psz;
  }
  if ( !PE_OpenKey(ghLocalMachineKey, v6, 0, 1u, &KeyHandle) )
  {
    if ( !PE_ReadRegKey(KeyHandle, L"ProviderOrder", 0, 0, &v58) )
    {
      v11 = operator new(4u);
      if ( v11 )
        v11->m_String = _wcsdup(v58);
      else
        v11 = 0;
      v12 = v58;
      szArg3 = v58;
      do
      {
        v13 = v11->m_String;
        *v11->m_String = 0;
        v14 = *v12;
        if ( *v12 )
        {
          do
          {
            if ( v14 == 44 )
              break;
            if ( v14 == 32 )
              break;
            ++v12;
            *v13 = v14;
            ++v13;
            v14 = *v12;
          }
          while ( *v12 );
          szArg3 = v12;
        }
        *v13 = 0;
        v15 = _wcsdup(L"System\\CurrentControlSet\\Services\\");
        ppv2 = v15;
        v16 = CPEString::Append(&v34.strValue[4], &ppv2, v11);
        ppv3 = v4;
        v4 = _wcsdup(v16->m_String);
        ppv2 = v4;
        free(ppv3);
        free(v34.strValue[4]);
        free(v15);
        v17 = _wcsdup(L"\\NetworkProvider");
        ppv3 = v17;
        v18 = CPEString::Append(&ppv, &ppv2, &ppv3);
        LOBYTE(v72) = 21;
        v71 = PE_OpenKey(a2, v18->m_String, 0, 1u, &hKey) == 0;
        free(ppv);
        LOBYTE(v72) = 7;
        free(v17);
        if ( v71 )
        {
          if ( !PE_ReadRegKey(hKey, L"ProviderPath", 0, 0, &v57) )
          {
            v19 = malloc(2u);
            v34.strValue[0] = v19;
            *v19 = 0;
            v34.strValue[1] = 0;
            v34.strValue[2] = 0;
            v34.strValue[3] = 0;
            LOBYTE(v72) = 22;
            sub_FD7040(v57, &v34);
            *szArg = _wcsdup(v57);
            LOBYTE(v72) = 23;
            v20 = sub_FD4EE0(&v38, a1, &v34, 0);
            v21 = str3.m_String;
            str3.m_String = _wcsdup(*v20);
            free(v21);
            free(v38);
            ppv3 = sub_FD4ED0();
            PE_ReadRegKey(hKey, L"Name", 0, 0, &v55);
            v63 = _wcsdup(L"ProviderOrder");
            v22 = &gszNullString;
            if ( psz )
              v22 = psz;
            szKeyName = _wcsdup(v22);
            v59 = _wcsdup(&gszNullString);
            v23 = &gszNullString;
            if ( psz )
              v23 = psz;
            v64 = _wcsdup(v23);
            LOBYTE(v72) = 27;
            v24 = MakeRegistryKeyName(v36, a2, &szKeyName, &v63);
            LOBYTE(v72) = 28;
            v25 = MakeRegistryKeyName(&v34.strValue[6], a2, &v64, &v59);
            LOBYTE(v72) = 29;
            v71 = sub_FD3D40(a1, v11, v25, v24, &str3, &v54, &v50, &v37);
            free(v34.strValue[6]);
            free(*v36);
            free(v64);
            free(v59);
            free(szKeyName);
            free(v63);
            if ( v71 )
            {
              if ( a4 == -1 )
              {
                v47 = _wcsdup(&gszNullString);
                v42 = _wcsdup(&gszNullString);
                v46 = _wcsdup(&gszNullString);
                v49 = _wcsdup(&gszNullString);
                v48 = _wcsdup(&gszNullString);
                v60 = _wcsdup(&gszNullString);
                pszText = _wcsdup(&gszNullString);
                v26 = &gszNullString;
                if ( psz )
                  v26 = psz;
                szArg4 = _wcsdup(v26);
                v67 = _wcsdup(&gszNullString);
                v27 = &gszNullString;
                if ( psz )
                  v27 = psz;
                v66 = _wcsdup(v27);
                LOBYTE(v72) = 39;
                v28 = MakeRegistryKeyName(v39, a2, &szArg4, &pszText);
                LOBYTE(v72) = 40;
                v29 = MakeRegistryKeyName(v40, a2, &v66, &v67);
                LOBYTE(v72) = 41;
                a4 = sub_FD3FF0(a1, 0, 0xFFFFFFFF, 0, v29, v28, &v60);
                free(*v40);
                free(*v39);
                free(v66);
                free(v67);
                free(szArg4);
                free(pszText);
                free(v60);
                free(v48);
                free(v49);
                free(v46);
                free(v42);
                free(v47);
              }
              a1a = _wcsdup(&gszNullString);
              v45 = _wcsdup(L"ProviderOrder");
              v30 = &gszNullString;
              if ( psz )
                v30 = psz;
              v43 = _wcsdup(v30);
              LOBYTE(v72) = 44;
              v31 = MakeRegistryKeyName(v35, a2, &v43, &v45);
              LOBYTE(v72) = 45;
              sub_FD3FF0(a1, ppv3, a4, 5u, v11, v31, &str3);
              free(*v35);
              free(v43);
              free(v45);
              free(a1a);
            }
            free(*szArg);
            LOBYTE(v72) = 7;
            sub_FD21F0(&v34);
          }
          RegCloseKey(hKey);
        }
        v12 = szArg3;
        v32 = *szArg3;
        if ( !*szArg3 )
          break;
        while ( v32 == 44 || v32 == 32 )
        {
          v32 = v12[1];
          ++v12;
          szArg3 = v12;
          if ( !v32 )
            goto LABEL_42;
        }
      }
      while ( *v12 );
LABEL_42:
      v5 = v34.strValue[5];
    }
    RegCloseKey(KeyHandle);
  }
  free(v50);
  free(v55);
  free(v54);
  free(str3.m_String);
  free(v5);
  free(v57);
  free(v4);
  free(v58);
  return a4;
}

//----- (00FE7FE0) --------------------------------------------------------
void __cdecl PE_RefreshRegistry(int a1, HKEY hKey, CPEString *strKeyName)
{
  WCHAR *v3; // ST20_4

  v3 = malloc(2u);
  *v3 = 0;
  sub_FE8050(a1, hKey, strKeyName->m_String, 0xFFFFFFFF);
  free(v3);
}

//----- (00FE8050) --------------------------------------------------------
void *__cdecl sub_FE8050(int a1, HKEY hKey, LPCWSTR lpszKeyName, HANDLE Handle)
{
  const wchar_t *v4; // eax
  const wchar_t *v5; // eax
  CPEString *v6; // esi
  CPEString *v7; // eax
  LPVOID (__stdcall *TlsGetValue)(DWORD); // ebx
  unsigned __int32 DesiredAccess; // ST54_4
  void (__stdcall *v10)(HKEY); // edi
  WCHAR *v11; // esi
  const WCHAR *v12; // esi
  unsigned int v13; // eax
  WCHAR *v14; // esi
  unsigned int v15; // eax
  int v16; // eax
  bool v17; // bl
  CPEString *v18; // eax
  CPEString *v19; // eax
  wchar_t *v20; // esi
  CPEString *v21; // eax
  void *v22; // esi
  wchar_t *v23; // esi
  unsigned int v24; // eax
  const wchar_t **v25; // eax
  WCHAR *v26; // esi
  WCHAR *v27; // esi
  CPEString *v28; // eax
  wchar_t *v29; // edi
  WCHAR *v30; // esi
  wchar_t *v31; // esi
  unsigned int v32; // eax
  WCHAR *v33; // esi
  const wchar_t *v34; // eax
  const wchar_t *v35; // eax
  CPEString *v36; // esi
  CPEString *v37; // eax
  char v38; // bl
  LPCWSTR v39; // ebx
  const wchar_t *v40; // eax
  const wchar_t *v41; // eax
  CPEString *v42; // esi
  CPEString *v43; // eax
  const WCHAR **v44; // eax
  CPEString *v45; // eax
  WCHAR *v46; // esi
  void **v47; // esi
  int v48; // ebx
  DWORD cbData; // [esp+10h] [ebp-CCh]
  WCHAR *ppv1; // [esp+14h] [ebp-C8h]
  WCHAR *pszResult; // [esp+18h] [ebp-C4h]
  WCHAR v53[2]; // [esp+1Ch] [ebp-C0h]
  WCHAR v54[2]; // [esp+20h] [ebp-BCh]
  WCHAR *ppv; // [esp+24h] [ebp-B8h]
  int a2; // [esp+28h] [ebp-B4h]
  WCHAR v57[2]; // [esp+2Ch] [ebp-B0h]
  int v58; // [esp+30h] [ebp-ACh]
  CPEString str; // [esp+34h] [ebp-A8h]
  WCHAR v60[2]; // [esp+38h] [ebp-A4h]
  CPEString v61; // [esp+3Ch] [ebp-A0h]
  WCHAR v62[2]; // [esp+40h] [ebp-9Ch]
  void *v63; // [esp+44h] [ebp-98h]
  WCHAR *ppv2; // [esp+48h] [ebp-94h]
  void *v65; // [esp+4Ch] [ebp-90h]
  BYTE Data[4]; // [esp+50h] [ebp-8Ch]
  void *v67; // [esp+54h] [ebp-88h]
  CPEString str3; // [esp+58h] [ebp-84h]
  void *v69; // [esp+5Ch] [ebp-80h]
  LPCWSTR v70; // [esp+60h] [ebp-7Ch]
  void *v71; // [esp+64h] [ebp-78h]
  LPCWSTR v72; // [esp+68h] [ebp-74h]
  void *v73; // [esp+6Ch] [ebp-70h]
  void *v74; // [esp+70h] [ebp-6Ch]
  WCHAR *v75; // [esp+74h] [ebp-68h]
  WCHAR *a1a; // [esp+78h] [ebp-64h]
  LPCWSTR v77; // [esp+7Ch] [ebp-60h]
  WCHAR *szArg; // [esp+80h] [ebp-5Ch]
  HKEY KeyHandle; // [esp+84h] [ebp-58h]
  void *v80; // [esp+88h] [ebp-54h]
  void *v81; // [esp+8Ch] [ebp-50h]
  tagPEStringStruct v82; // [esp+90h] [ebp-4Ch]
  LPCWSTR v83; // [esp+ACh] [ebp-30h]
  LPCWSTR v84; // [esp+B0h] [ebp-2Ch]
  LPCWSTR v85; // [esp+B4h] [ebp-28h]
  WCHAR *ppv3; // [esp+B8h] [ebp-24h]
  bool v87; // [esp+BFh] [ebp-1Dh]
  LPCWSTR szArg3; // [esp+C0h] [ebp-1Ch]
  HKEY hKeya; // [esp+C4h] [ebp-18h]
  wchar_t *pszText; // [esp+C8h] [ebp-14h]
  HKEY__ v91; // [esp+CCh] [ebp-10h]
  int v92; // [esp+D8h] [ebp-4h]

  ppv3 = malloc(2u);
  *ppv3 = 0;
  v92 = 0;
  v81 = malloc(2u);
  *v81 = 0;
  v74 = malloc(2u);
  *v74 = 0;
  v75 = malloc(2u);
  *v75 = 0;
  v80 = malloc(2u);
  *v80 = 0;
  v77 = malloc(2u);
  *v77 = 0;
  LOBYTE(v92) = 5;
  *Data = 0;
  if ( Handle == -1 )
  {
    v82.strValue[5] = _wcsdup(&gszNullString);
    v82.strValue[4] = _wcsdup(&gszNullString);
    v82.strValue[6] = _wcsdup(&gszNullString);
    v84 = _wcsdup(&gszNullString);
    v85 = _wcsdup(&gszNullString);
    v83 = _wcsdup(&gszNullString);
    v91.unused = _wcsdup(&gszNullString);
    v4 = &gszNullString;
    if ( lpszKeyName )
      v4 = lpszKeyName;
    pszText = _wcsdup(v4);
    hKeya = _wcsdup(&gszNullString);
    v5 = &gszNullString;
    if ( lpszKeyName )
      v5 = lpszKeyName;
    szArg3 = _wcsdup(v5);
    LOBYTE(v92) = 15;
    v6 = MakeRegistryKeyName(&a1a, hKey, &pszText, &v91);
    LOBYTE(v92) = 16;
    v7 = MakeRegistryKeyName(&szArg, hKey, &szArg3, &hKeya);
    LOBYTE(v92) = 17;
    Handle = sub_FD3FF0(a1, 0, 0xFFFFFFFF, 0, v7, v6, &v83);
    free(szArg);
    free(a1a);
    free(szArg3);
    free(hKeya);
    free(pszText);
    free(v91.unused);
    free(v83);
    free(v85);
    free(v84);
    free(v82.strValue[6]);
    free(v82.strValue[4]);
    LOBYTE(v92) = 5;
    free(v82.strValue[5]);
  }
  TlsGetValue = ::TlsGetValue;
  DesiredAccess = ::TlsGetValue(gdwTlsIndex) | KEY_READ;
  if ( !PE_OpenKey(hKey, lpszKeyName, 0, DesiredAccess, &KeyHandle) )
  {
    szArg = 0;
    pszText = malloc(2u);
    *pszText = 0;
    v91.unused = malloc(2u);
    *v91.unused = 0;
    szArg3 = malloc(2u);
    *szArg3 = 0;
    v82.strValue[0] = malloc(2u);
    *v82.strValue[0] = 0;
    v82.strValue[1] = 0;
    v82.strValue[2] = 0;
    v82.strValue[3] = 0;
    LOBYTE(v92) = 21;
    v10 = RegCloseKey;
    if ( !PE_LoadRegKeys(KeyHandle, 0, &v91) )
    {
      while ( 1 )
      {
        v11 = v77;
        v77 = _wcsdup(v91.unused);
        free(v11);
        v12 = v91.unused;
        v13 = TlsGetValue(gdwTlsIndex);
        if ( !PE_OpenKey(KeyHandle, v12, 0, v13 | KEY_READ, &hKeya) )
        {
          RegQueryValueExW(hKeya, L"LoadBehavior", 0, 0, Data, &cbData);
          v10(hKeya);
        }
        v87 = *Data > 1u;
        v14 = CPEString::Append(&ppv, &v91, L"\\CLSID")->m_String;
        LOBYTE(v92) = 22;
        v15 = TlsGetValue(gdwTlsIndex);
        v16 = PE_OpenKey(HKEY_CLASSES_ROOT, v14, 0, v15 | KEY_READ, &hKeya);
        LOBYTE(v92) = 21;
        v17 = v16 == 0;
        free(ppv);
        if ( !v17 )
          goto LABEL_39;
        if ( PE_ReadRegKey(hKeya, &gszNullString, 0, 0, &v91) )
          break;
        v10(hKeya);
        v18 = operator+(&pszResult, L"CLSID\\", &v91);
        v19 = CPEString::Append(&str, v18, L"\\InprocServer32");
        v20 = pszText;
        pszText = _wcsdup(v19->m_String);
        free(v20);
        free(str.m_String);
        free(pszResult);
        v21 = operator+(&v61, L"HKCR\\CLSID\\", &v91);
        v22 = v80;
        v80 = _wcsdup(v21->m_String);
        free(v22);
        free(v61.m_String);
        v23 = pszText;
        TlsGetValue = ::TlsGetValue;
        v24 = ::TlsGetValue(gdwTlsIndex);
        if ( PE_OpenKey(HKEY_CLASSES_ROOT, v23, 0, v24 | 0x20019, &hKeya) )
          goto LABEL_16;
        if ( !PE_ReadRegKey(hKeya, &gszNullString, 0, 0, &pszText) )
        {
          sub_FD7040(pszText, &v82);
          v25 = sub_FD4EE0(&v63, a1, &v82, 0);
          v26 = szArg3;
          szArg3 = _wcsdup(*v25);
          free(v26);
          free(v63);
          v10(hKeya);
LABEL_16:
          a2 = sub_FD4ED0();
          v27 = _wcsdup(L"CLSID\\");
          ppv2 = v27;
          v28 = CPEString::Append(&ppv1, &ppv2, &v91);
          v29 = pszText;
          pszText = _wcsdup(v28->m_String);
          free(v29);
          free(ppv1);
          free(v27);
          v30 = ppv3;
          ppv3 = _wcsdup(v91.unused);
          free(v30);
          v31 = pszText;
          v32 = ::TlsGetValue(gdwTlsIndex);
          if ( PE_OpenKey(HKEY_CLASSES_ROOT, v31, 0, v32 | 0x20019, &hKeya) )
          {
            v10 = RegCloseKey;
          }
          else
          {
            if ( !PE_ReadRegKey(hKeya, &gszNullString, 0, 0, &pszText) && wcslen(pszText) )
            {
              v33 = ppv3;
              ppv3 = _wcsdup(pszText);
              free(v33);
            }
            v10 = RegCloseKey;
            RegCloseKey(hKeya);
          }
          v34 = &gszNullString;
          if ( lpszKeyName )
            v34 = lpszKeyName;
          v82.strValue[6] = _wcsdup(v34);
          v82.strValue[4] = _wcsdup(&gszNullString);
          v35 = &gszNullString;
          if ( lpszKeyName )
            v35 = lpszKeyName;
          v82.strValue[5] = _wcsdup(v35);
          LOBYTE(v92) = 25;
          v36 = MakeRegistryKeyName(v53, hKey, &v82.strValue[6], &v91);
          LOBYTE(v92) = 26;
          v37 = MakeRegistryKeyName(v57, hKey, &v82.strValue[5], &v82.strValue[4]);
          LOBYTE(v92) = 27;
          v38 = sub_FD3D40(a1, &ppv3, v37, v36, &szArg3, &v81, &v75, &v58);
          free(*v57);
          free(*v53);
          free(v82.strValue[5]);
          free(v82.strValue[4]);
          free(v82.strValue[6]);
          if ( v38 )
          {
            if ( Handle == -1 )
            {
              v65 = _wcsdup(&gszNullString);
              v69 = _wcsdup(&gszNullString);
              v67 = _wcsdup(&gszNullString);
              v73 = _wcsdup(&gszNullString);
              v71 = _wcsdup(&gszNullString);
              str3.m_String = _wcsdup(&gszNullString);
              v70 = _wcsdup(&gszNullString);
              v39 = lpszKeyName;
              v40 = &gszNullString;
              if ( lpszKeyName )
                v40 = lpszKeyName;
              v83 = _wcsdup(v40);
              v85 = _wcsdup(&gszNullString);
              v41 = &gszNullString;
              if ( lpszKeyName )
                v41 = lpszKeyName;
              v84 = _wcsdup(v41);
              LOBYTE(v92) = 37;
              v42 = MakeRegistryKeyName(v60, hKey, &v83, &v70);
              LOBYTE(v92) = 38;
              v43 = MakeRegistryKeyName(v62, hKey, &v84, &v85);
              LOBYTE(v92) = 39;
              Handle = sub_FD3FF0(a1, 0, 0xFFFFFFFF, 0, v43, v42, &str3);
              free(*v62);
              free(*v60);
              free(v84);
              free(v85);
              free(v83);
              free(v70);
              free(str3.m_String);
              free(v71);
              free(v73);
              free(v67);
              free(v69);
              free(v65);
            }
            else
            {
              v39 = lpszKeyName;
            }
            a1a = _wcsdup(&gszNullString);
            v44 = &gszNullString;
            if ( v39 )
              v44 = v39;
            v72 = _wcsdup(v44);
            LOBYTE(v92) = 41;
            v45 = MakeRegistryKeyName(v54, hKey, &v72, &v77);
            LOBYTE(v92) = 42;
            sub_FD3FF0(a1, a2, Handle, 0x12u, &ppv3, v45, &szArg3);
            free(*v54);
            free(v72);
            free(a1a);
          }
LABEL_39:
          sub_FD21F0(&v82);
          free(szArg3);
          free(v91.unused);
          free(pszText);
          TlsGetValue = ::TlsGetValue;
          goto LABEL_40;
        }
        v10(hKeya);
        sub_FD21F0(&v82);
        free(szArg3);
        free(v91.unused);
        free(pszText);
LABEL_40:
        szArg = (szArg + 1);
        v46 = szArg;
        pszText = malloc(2u);
        *pszText = 0;
        v91.unused = malloc(2u);
        *v91.unused = 0;
        szArg3 = malloc(2u);
        *szArg3 = 0;
        v82.strValue[0] = malloc(2u);
        *v82.strValue[0] = 0;
        v82.strValue[1] = 0;
        v82.strValue[2] = 0;
        v82.strValue[3] = 0;
        LOBYTE(v92) = 21;
        if ( PE_LoadRegKeys(KeyHandle, v46, &v91) )
          goto LABEL_41;
      }
      v10(hKeya);
      goto LABEL_39;
    }
LABEL_41:
    v47 = v82.strValue[1];
    if ( v82.strValue[1] )
    {
      v48 = v82.strValue[2];
      if ( v82.strValue[1] != v82.strValue[2] )
      {
        do
        {
          free(*v47);
          ++v47;
        }
        while ( v47 != v48 );
        v47 = v82.strValue[1];
      }
      j__free(v47);
      v82.strValue[1] = 0;
      v82.strValue[2] = 0;
      v82.strValue[3] = 0;
    }
    free(v82.strValue[0]);
    free(szArg3);
    free(v91.unused);
    free(pszText);
    v10(KeyHandle);
  }
  free(v77);
  free(v80);
  free(v75);
  free(v74);
  free(v81);
  free(ppv3);
  return Handle;
}

//----- (00FE8A90) --------------------------------------------------------
void __cdecl LoadPrintServiceDirectory(DWORD dwValue, HKEY hRootKey, LPCWSTR lpszKeyName, DWORD dwArgs)
{
  WCHAR *pszNewKeyName; // esi
  void *v5; // ebx
  CPEString *v6; // eax
  WCHAR *v7; // edi
  HKEY hKey; // [esp+14h] [ebp-10h]
  int v9; // [esp+20h] [ebp-4h]

  pszNewKeyName = malloc(2u);
  *pszNewKeyName = 0;
  v9 = 0;
  if ( gbPrintDirectoryInited )
  {
LABEL_10:
    v5 = sub_FE8C20(dwValue, hRootKey, *lpszKeyName, 0xFFFFFFFF, 1, dwArgs);
    v6 = CPEString::Append(&hKey, lpszKeyName, L"\\AutorunsDisabled");
    v7 = pszNewKeyName;
    pszNewKeyName = _wcsdup(v6->m_String);
    free(v7);
    free(hKey);
    sub_FE8C20(dwValue, hRootKey, pszNewKeyName, v5, 0, dwArgs);
    goto LABEL_11;
  }
  if ( !PE_OpenKey(ghLocalMachineKey, L"SYSTEM\\CurrentControlSet\\Control\\Print", 0, KEY_READ, &hKey)
    || !dword_10C3628[0] )
  {
    if ( !PE_OpenKey(
            ghLocalMachineKey,
            L"SYSTEM\\CurrentControlSet\\Control\\Print\\Environments\\Windows NT x86",
            0,
            0x20019u,
            &hKey) )
    {
      PE_ReadRegKey(hKey, L"Directory", 0, 0, &gszPrintDirectoryForNTX86.m_String);
      RegCloseKey(hKey);
    }
    if ( !PE_OpenKey(
            ghLocalMachineKey,
            L"SYSTEM\\CurrentControlSet\\Control\\Print\\Environments\\Windows x64",
            0,
            0x20019u,
            &hKey) )
    {
      PE_ReadRegKey(hKey, L"Directory", 0, 0, &gszPrintDirectoryForX86);
      RegCloseKey(hKey);
    }
    gbPrintDirectoryInited = 1;
    goto LABEL_10;
  }
  wprintf(L"\nNo entry to display for printer. Printer is not supported on Nano Server.\n");
LABEL_11:
  free(pszNewKeyName);
}
// 10C3628: using guessed type int dword_10C3628[140];
// 10C4C58: using guessed type char gbPrintDirectoryInited;
