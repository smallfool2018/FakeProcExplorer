
//----- (00FE8C20) --------------------------------------------------------
void *__cdecl sub_FE8C20(DWORD dwValue, HKEY hRootKey, LPCWSTR lpszKeyName, HANDLE Handle, bool bFlags, DWORD dwArgs)
{
  LPCWSTR v6; // edi
  int v7; // ebx
  const wchar_t *v8; // eax
  const wchar_t *v9; // eax
  CPEString *pstr1; // esi
  CPEString *pstr2; // eax
  unsigned int v12; // eax
  const WCHAR *v13; // esi
  unsigned int v14; // eax
  const wchar_t **v15; // eax
  WCHAR *v16; // esi
  CPEString *v17; // edi
  WCHAR *v18; // esi
  CPEString *v19; // eax
  CPEString *v20; // eax
  wchar_t *v21; // esi
  const wchar_t **v22; // eax
  wchar_t *v23; // edi
  WCHAR *v24; // edi
  const WCHAR **v25; // ecx
  const WCHAR **v26; // eax
  CPEString *v27; // esi
  CPEString *v28; // eax
  char v29; // bl
  const WCHAR **v30; // eax
  const WCHAR **v31; // eax
  CPEString *v32; // esi
  CPEString *v33; // eax
  const WCHAR **v34; // eax
  CPEString *v35; // eax
  tagPEStringStruct v37; // [esp+10h] [ebp-B0h]
  int v38; // [esp+2Ch] [ebp-94h]
  WCHAR v39[2]; // [esp+30h] [ebp-90h]
  WCHAR v40[2]; // [esp+34h] [ebp-8Ch]
  void *v41; // [esp+38h] [ebp-88h]
  WCHAR v42[2]; // [esp+3Ch] [ebp-84h]
  WCHAR *ppv1; // [esp+40h] [ebp-80h]
  WCHAR v44[2]; // [esp+44h] [ebp-7Ch]
  wchar_t *ppv; // [esp+48h] [ebp-78h]
  LPCWSTR szKeyName; // [esp+4Ch] [ebp-74h]
  void *v47; // [esp+50h] [ebp-70h]
  DWORD v48; // [esp+54h] [ebp-6Ch]
  void *v49; // [esp+58h] [ebp-68h]
  HKEY hKey; // [esp+5Ch] [ebp-64h]
  void *v51; // [esp+60h] [ebp-60h]
  WCHAR *ppv3; // [esp+64h] [ebp-5Ch]
  void *v53; // [esp+68h] [ebp-58h]
  WCHAR *v54; // [esp+6Ch] [ebp-54h]
  std__Vector_val a1; // [esp+70h] [ebp-50h]
  WCHAR szArg[2]; // [esp+7Ch] [ebp-44h]
  std__list_node str1; // [esp+80h] [ebp-40h]
  LPCWSTR pszArgs2; // [esp+8Ch] [ebp-34h]
  LPCWSTR pszNewKeyName2; // [esp+90h] [ebp-30h]
  LPCWSTR pszArgs1; // [esp+94h] [ebp-2Ch]
  std__list_node str2; // [esp+98h] [ebp-28h]
  WCHAR *pszNewKeyName; // [esp+A4h] [ebp-1Ch]
  CPEString str3; // [esp+A8h] [ebp-18h]
  LPCWSTR lpszKeyNamea; // [esp+ACh] [ebp-14h]
  WCHAR szText2[2]; // [esp+B0h] [ebp-10h]
  int v66; // [esp+BCh] [ebp-4h]

  v48 = 0;
  *szText2 = malloc(2u);
  **szText2 = 0;
  v66 = 0;
  str3.m_String = malloc(2u);
  *str3.m_String = 0;
  a1._Mylast = malloc(2u);
  *a1._Mylast = 0;
  v53 = malloc(2u);
  *v53 = 0;
  v54 = malloc(2u);
  *v54 = 0;
  v6 = lpszKeyName;
  v7 = dwValue;
  LOBYTE(v66) = 4;
  if ( Handle == -1 )
  {
    str1._Next = _wcsdup(&gszNullString);
    str1._Next = _wcsdup(&gszNullString);
    str1._Myval = _wcsdup(&gszNullString);
    str2._Next = _wcsdup(&gszNullString);
    str2._Prev = _wcsdup(&gszNullString);
    str2._Myval = _wcsdup(&gszNullString);
    pszArgs1 = _wcsdup(&gszNullString);
    v8 = &gszNullString;
    if ( lpszKeyName )
      v8 = lpszKeyName;
    pszNewKeyName = _wcsdup(v8);
    pszArgs2 = _wcsdup(&gszNullString);
    v9 = &gszNullString;
    if ( lpszKeyName )
      v9 = lpszKeyName;
    pszNewKeyName2 = _wcsdup(v9);
    LOBYTE(v66) = 14;
    pstr1 = MakeRegistryKeyName(&a1, hRootKey, &pszNewKeyName, &pszArgs1);
    LOBYTE(v66) = 15;
    pstr2 = MakeRegistryKeyName(szArg, hRootKey, &pszNewKeyName2, &pszArgs2);
    LOBYTE(v66) = 16;
    Handle = sub_FD3FF0(dwValue, 0, 0xFFFFFFFF, 0, pstr2, pstr1, &str2._Myval);
    free(*szArg);
    free(a1._Myfirst);
    free(pszNewKeyName2);
    free(pszArgs2);
    free(pszNewKeyName);
    free(pszArgs1);
    free(str2._Myval);
    free(str2._Prev);
    free(str2._Next);
    free(str1._Myval);
    free(str1._Next);
    LOBYTE(v66) = 4;
    free(str1._Prev);
  }
  v12 = TlsGetValue(gdwTlsIndex);
  if ( !PE_OpenKey(ghLocalMachineKey, lpszKeyName, 0, v12 | KEY_READ, &a1._Myend) )
  {
    lpszKeyNamea = malloc(2u);
    *lpszKeyNamea = 0;
    LOBYTE(v66) = 17;
    if ( !PE_LoadRegKeys(a1._Myend, 0, &lpszKeyNamea) )
    {
      do
      {
        v13 = lpszKeyNamea;
        v14 = TlsGetValue(gdwTlsIndex);
        if ( !PE_OpenKey(a1._Myend, v13, 0, v14 | 0x20019, &hKey) )
        {
          if ( !PE_ReadRegKey(hKey, L"Driver", 0, 0, szText2) )
          {
            v37.strValue[0] = malloc(2u);
            *v37.strValue[0] = 0;
            v37.strValue[1] = 0;
            v37.strValue[2] = 0;
            v37.strValue[3] = 0;
            LOBYTE(v66) = 18;
            sub_FD7040(*szText2, &v37);
            *szArg = _wcsdup(*szText2);
            LOBYTE(v66) = 19;
            v15 = sub_FD4EE0(&v41, v7, &v37, 0);
            v16 = str3.m_String;
            str3.m_String = _wcsdup(*v15);
            free(v16);
            free(v41);
            if ( !wcschr(*szText2, 0x5Cu) )
            {
              v17 = &gszPrintDirectoryForX86;
              if ( !dwArgs )
                v17 = &gszPrintDirectoryForNTX86;
              v18 = _wcsdup(L"\\");
              ppv3 = v18;
              v19 = operator+(&v37.strValue[4], L"\\SystemRoot\\System32\\Spool\\Prtprocs\\", v17);
              v20 = CPEString::Append(&ppv1, v19, &ppv3);
              CPEString::Append(&ppv, v20, szText2);
              LOBYTE(v66) = 20;
              free(ppv1);
              free(v37.strValue[4]);
              free(v18);
              v21 = ppv;
              v22 = sub_FD4F20(&v37.strValue[6], v7, ppv);
              v23 = *szText2;
              *szText2 = _wcsdup(*v22);
              free(v23);
              free(v37.strValue[6]);
              if ( wcsncmp(*szText2, L"File not found: ", 0x10u) )
              {
                v24 = str3.m_String;
                str3.m_String = _wcsdup(*szText2);
                free(v24);
              }
              LOBYTE(v66) = 19;
              free(v21);
              v6 = lpszKeyName;
            }
            ppv3 = sub_FD4ED0();
            v25 = &gszNullString;
            if ( v6 )
              v25 = v6;
            str1._Myval = _wcsdup(v25);
            str1._Next = _wcsdup(&gszNullString);
            v26 = &gszNullString;
            if ( v6 )
              v26 = v6;
            str1._Prev = _wcsdup(v26);
            LOBYTE(v66) = 23;
            v27 = MakeRegistryKeyName(v44, hRootKey, &str1._Myval, &lpszKeyNamea);
            LOBYTE(v66) = 24;
            v28 = MakeRegistryKeyName(v39, hRootKey, &str1._Prev, &str1);
            LOBYTE(v66) = 25;
            v29 = sub_FD3D40(v7, &lpszKeyNamea, v28, v27, &str3, &a1._Mylast, &v54, &v38);
            free(*v39);
            free(*v44);
            free(str1._Prev);
            free(str1._Next);
            free(str1._Myval);
            if ( v29 )
            {
              if ( Handle == -1 )
              {
                v47 = _wcsdup(&gszNullString);
                v51 = _wcsdup(&gszNullString);
                v49 = _wcsdup(&gszNullString);
                pszNewKeyName2 = _wcsdup(&gszNullString);
                pszArgs2 = _wcsdup(&gszNullString);
                pszNewKeyName = _wcsdup(&gszNullString);
                pszArgs1 = _wcsdup(&gszNullString);
                v30 = &gszNullString;
                if ( v6 )
                  v30 = v6;
                str2._Myval = _wcsdup(v30);
                str2._Prev = _wcsdup(&gszNullString);
                v31 = &gszNullString;
                if ( v6 )
                  v31 = v6;
                str2._Next = _wcsdup(v31);
                LOBYTE(v66) = 35;
                v32 = MakeRegistryKeyName(v40, hRootKey, &str2._Myval, &pszArgs1);
                LOBYTE(v66) = 36;
                v33 = MakeRegistryKeyName(v42, hRootKey, &str2, &str2._Prev);
                LOBYTE(v66) = 37;
                v7 = dwValue;
                Handle = sub_FD3FF0(dwValue, 0, 0xFFFFFFFF, 0, v33, v32, &pszNewKeyName);
                free(*v42);
                free(*v40);
                free(str2._Next);
                free(str2._Prev);
                free(str2._Myval);
                free(pszArgs1);
                free(pszNewKeyName);
                free(pszArgs2);
                free(pszNewKeyName2);
                free(v49);
                free(v51);
                free(v47);
              }
              else
              {
                v7 = dwValue;
              }
              a1._Myfirst = _wcsdup(&gszNullString);
              v34 = &gszNullString;
              if ( v6 )
                v34 = v6;
              szKeyName = _wcsdup(v34);
              LOBYTE(v66) = 39;
              v35 = MakeRegistryKeyName(&v37.strValue[5], hRootKey, &szKeyName, &lpszKeyNamea);
              LOBYTE(v66) = 40;
              sub_FD3FF0(v7, ppv3, Handle, 3u, &lpszKeyNamea, v35, &str3);
              free(v37.strValue[5]);
              free(szKeyName);
              free(a1._Myfirst);
            }
            else
            {
              v7 = dwValue;
            }
            free(*szArg);
            LOBYTE(v66) = 17;
            sub_FD21F0(&v37);
          }
          RegCloseKey(hKey);
        }
        ++v48;
      }
      while ( !PE_LoadRegKeys(a1._Myend, v48, &lpszKeyNamea) );
    }
    RegCloseKey(a1._Myend);
    free(lpszKeyNamea);
  }
  free(v54);
  free(v53);
  free(a1._Mylast);
  free(str3.m_String);
  free(*szText2);
  return Handle;
}

//----- (00FE93C0) --------------------------------------------------------
char __cdecl PE_GetServiceDescription(LPCWSTR lpServiceName, CPEString *strServiceDescription)
{
  char v2; // bl
  SC_HANDLE hSCHandle; // eax
  void *v4; // edi
  SC_HANDLE v5; // esi
  void *QueryServiceConfig2W_0; // eax
  HMODULE v8; // eax
  DWORD v9; // ST0C_4
  _SERVICE_DESCRIPTIONW *ServiceDesriptor; // esi
  LPWSTR lpDescription; // edx
  LPWSTR pstrDesc1; // ecx
  WCHAR v13; // ax
  LPWSTR pstrDesc2; // ecx
  WCHAR v15; // ax
  LPWSTR pstrDesc3; // ecx
  WCHAR v17; // ax
  LPWSTR pstrDesc5; // edx
  LPWSTR pstrDesc4; // ecx
  WCHAR v20; // ax
  LPWSTR pstrDesc6; // ecx
  WCHAR v22; // ax
  SC_HANDLE hService; // [esp+14h] [ebp-14h]
  size_t cbBufSize; // [esp+18h] [ebp-10h]
  int v25; // [esp+24h] [ebp-4h]

  v25 = 0;
  v2 = 0;
  hSCHandle = OpenSCManagerW(0, 0, 0x80000000);
  v4 = hSCHandle;
  if ( !hSCHandle )
    goto LABEL_4;
  v5 = OpenServiceW(hSCHandle, lpServiceName, 1u);
  hService = v5;
  if ( !v5 )
  {
    CloseServiceHandle(v4);
LABEL_4:
    v2 = 0;
    goto LABEL_5;
  }
  QueryServiceConfig2W_0 = ::QueryServiceConfig2W_0;
  cbBufSize = 0;
  if ( ::QueryServiceConfig2W_0
    || (v8 = LoadLibraryW(L"Advapi32.dll"),
        QueryServiceConfig2W_0 = GetProcAddress(v8, "QueryServiceConfig2W"),
        (::QueryServiceConfig2W_0 = QueryServiceConfig2W_0) != 0) )
  {
    if ( !(QueryServiceConfig2W_0)(v5, 1, 0, 0, &cbBufSize) )
    {
      v9 = cbBufSize;
      ServiceDesriptor = malloc(cbBufSize);
      if ( ::QueryServiceConfig2W_0(hService, SERVICE_CONFIG_DESCRIPTION, ServiceDesriptor, v9, &cbBufSize) )
      {
        lpDescription = ServiceDesriptor->lpDescription;
        if ( ServiceDesriptor->lpDescription )
        {
          pstrDesc1 = ServiceDesriptor->lpDescription;
          do
          {
            v13 = *pstrDesc1;
            ++pstrDesc1;
          }
          while ( v13 );
          if ( (pstrDesc1 - (lpDescription + 1)) > 3 )
          {
            pstrDesc2 = ServiceDesriptor->lpDescription;
            do
            {
              v15 = *pstrDesc2;
              ++pstrDesc2;
            }
            while ( v15 );
            if ( lpDescription[pstrDesc2 - (lpDescription + 1) - 1] == '\n' )
            {
              pstrDesc3 = ServiceDesriptor->lpDescription;
              do
              {
                v17 = *pstrDesc3;
                ++pstrDesc3;
              }
              while ( v17 );
              lpDescription[pstrDesc3 - (lpDescription + 1) - 1] = 0;
              pstrDesc5 = ServiceDesriptor->lpDescription;
              pstrDesc4 = ServiceDesriptor->lpDescription;
              do
              {
                v20 = *pstrDesc4;
                ++pstrDesc4;
              }
              while ( v20 );
              if ( pstrDesc5[pstrDesc4 - (ServiceDesriptor->lpDescription + 1) - 1] == '\r' )
              {
                pstrDesc6 = ServiceDesriptor->lpDescription;
                do
                {
                  v22 = *pstrDesc6;
                  ++pstrDesc6;
                }
                while ( v22 );
                pstrDesc5[pstrDesc6 - (pstrDesc5 + 1) - 1] = 0;
              }
            }
          }
        }
        CPEString::Reset(strServiceDescription, ServiceDesriptor->lpDescription);
        v2 = 1;
      }
      free(ServiceDesriptor);
      v5 = hService;
    }
  }
  CloseServiceHandle(v5);
  CloseServiceHandle(v4);
LABEL_5:
  free(lpServiceName);
  return v2;
}

//----- (00FE9580) --------------------------------------------------------
void *__cdecl sub_FE9580(int a1, void *a2, wchar_t *psz)
{
  std__List *v3; // eax
  WCHAR *v4; // eax
  WCHAR *v5; // eax
  WCHAR *v6; // eax
  _WORD *v7; // eax
  _WORD *v8; // eax
  WCHAR *v9; // eax
  _WORD *v10; // eax
  wchar_t *v11; // ebx
  const wchar_t *v12; // eax
  const wchar_t *v13; // eax
  CPEString *v14; // esi
  CPEString *v15; // eax
  void *v16; // esi
  LSTATUS (__stdcall *v17)(HKEY, LPCWSTR, LPDWORD, LPDWORD, LPBYTE, LPDWORD); // esi
  WCHAR *v18; // esi
  void *v19; // esi
  const wchar_t **v20; // eax
  WCHAR *v21; // esi
  void *v22; // esi
  CPEString *v23; // eax
  void *v24; // esi
  CPEString *v25; // eax
  void *v26; // esi
  wchar_t *v27; // eax
  CPEString *v28; // eax
  wchar_t *v29; // eax
  WCHAR *v30; // esi
  const WCHAR **v31; // eax
  const WCHAR **v32; // eax
  CPEString *v33; // esi
  CPEString *v34; // eax
  char v35; // bl
  const wchar_t *v36; // eax
  const wchar_t *v37; // eax
  CPEString *v38; // esi
  CPEString *v39; // eax
  const WCHAR **v40; // eax
  CPEString *v41; // eax
  int a2a; // [esp+10h] [ebp-F4h]
  tagPEStringStruct v44; // [esp+20h] [ebp-E4h]
  int v45; // [esp+3Ch] [ebp-C8h]
  CPEString strResult; // [esp+40h] [ebp-C4h]
  BYTE v47; // [esp+44h] [ebp-C0h]
  unsigned int v48; // [esp+48h] [ebp-BCh]
  void *v49; // [esp+50h] [ebp-B4h]
  WCHAR v50[2]; // [esp+54h] [ebp-B0h]
  WCHAR v51[2]; // [esp+58h] [ebp-ACh]
  void *v52; // [esp+5Ch] [ebp-A8h]
  void *v53; // [esp+60h] [ebp-A4h]
  int v54; // [esp+64h] [ebp-A0h]
  void *v55; // [esp+68h] [ebp-9Ch]
  WCHAR v56[2]; // [esp+6Ch] [ebp-98h]
  WCHAR v57[2]; // [esp+70h] [ebp-94h]
  void *v58; // [esp+74h] [ebp-90h]
  void *v59; // [esp+78h] [ebp-8Ch]
  void *v60; // [esp+7Ch] [ebp-88h]
  void *v61; // [esp+80h] [ebp-84h]
  DWORD dwValue; // [esp+84h] [ebp-80h]
  HKEY KeyHandle; // [esp+88h] [ebp-7Ch]
  BYTE Data[4]; // [esp+8Ch] [ebp-78h]
  WCHAR *v65; // [esp+90h] [ebp-74h]
  DWORD v66; // [esp+94h] [ebp-70h]
  void *a1a; // [esp+98h] [ebp-6Ch]
  HKEY hRootKey; // [esp+9Ch] [ebp-68h]
  void *ppv1; // [esp+A0h] [ebp-64h]
  WCHAR szArg[2]; // [esp+A4h] [ebp-60h]
  void *v71; // [esp+A8h] [ebp-5Ch]
  LPCWSTR v72; // [esp+ACh] [ebp-58h]
  WCHAR *ppv3; // [esp+B0h] [ebp-54h]
  LPCWSTR v74; // [esp+B4h] [ebp-50h]
  WCHAR *pszText; // [esp+B8h] [ebp-4Ch]
  LPCWSTR szKeyName; // [esp+BCh] [ebp-48h]
  LPCWSTR szArg4; // [esp+C0h] [ebp-44h]
  LPCWSTR v78; // [esp+C4h] [ebp-40h]
  LPCWSTR v79; // [esp+C8h] [ebp-3Ch]
  LPCWSTR v80; // [esp+CCh] [ebp-38h]
  LPCWSTR v81; // [esp+D0h] [ebp-34h]
  LPCWSTR szArg3; // [esp+D4h] [ebp-30h]
  DWORD cbData; // [esp+D8h] [ebp-2Ch]
  void *ppv; // [esp+DCh] [ebp-28h]
  LPCWSTR lpszKeyName; // [esp+E0h] [ebp-24h]
  void *v86; // [esp+E4h] [ebp-20h]
  HKEY hKey; // [esp+E8h] [ebp-1Ch]
  CPEString str3; // [esp+ECh] [ebp-18h]
  std__List *v89; // [esp+F0h] [ebp-14h]
  char v90; // [esp+F7h] [ebp-Dh]
  int v91; // [esp+100h] [ebp-4h]

  v66 = 0;
  v3 = malloc(2u);
  v89 = v3;
  LOWORD(v3->_Mypair._Myval2._Myhead) = 0;
  v91 = 0;
  v4 = malloc(2u);
  lpszKeyName = v4;
  *v4 = 0;
  v5 = malloc(2u);
  ppv3 = v5;
  *v5 = 0;
  v6 = malloc(2u);
  str3.m_String = v6;
  *v6 = 0;
  v7 = malloc(2u);
  v71 = v7;
  *v7 = 0;
  v8 = malloc(2u);
  ppv = v8;
  *v8 = 0;
  v9 = malloc(2u);
  v65 = v9;
  *v9 = 0;
  v10 = malloc(2u);
  v86 = v10;
  *v10 = 0;
  v72 = _wcsdup(&gszNullString);
  v74 = _wcsdup(&gszNullString);
  szKeyName = _wcsdup(&gszNullString);
  v78 = _wcsdup(&gszNullString);
  v80 = _wcsdup(&gszNullString);
  v81 = _wcsdup(&gszNullString);
  szArg4 = _wcsdup(&gszNullString);
  v11 = psz;
  v12 = &gszNullString;
  if ( psz )
    v12 = psz;
  pszText = _wcsdup(v12);
  v79 = _wcsdup(&gszNullString);
  v13 = &gszNullString;
  if ( psz )
    v13 = psz;
  szArg3 = _wcsdup(v13);
  LOBYTE(v91) = 17;
  v14 = MakeRegistryKeyName(&a1a, a2, &pszText, &szArg4);
  LOBYTE(v91) = 18;
  v15 = MakeRegistryKeyName(szArg, a2, &szArg3, &v79);
  LOBYTE(v91) = 19;
  v16 = sub_FD3FF0(a1, 0, 0xFFFFFFFF, 0, v15, v14, &v81);
  ppv1 = v16;
  free(*szArg);
  free(a1a);
  free(szArg3);
  free(v79);
  free(pszText);
  free(szArg4);
  free(v81);
  free(v80);
  free(v78);
  free(szKeyName);
  free(v74);
  LOBYTE(v91) = 7;
  free(v72);
  if ( PE_OpenKey(ghLocalMachineKey, psz, 0, 0x20019u, &hRootKey) )
    goto LABEL_64;
  if ( PE_LoadRegKeys(hRootKey, 0, &lpszKeyName) )
    goto LABEL_63;
  v17 = RegQueryValueExW;
  do
  {
    if ( PE_OpenKey(hRootKey, lpszKeyName, 0, 0x20019u, &hKey) )
      goto LABEL_61;
    cbData = 4;
    if ( v17(hKey, L"Start", 0, 0, Data, &cbData) || *Data != 2 && *Data != 4 && *Data != 3 )
      goto LABEL_60;
    cbData = 4;
    if ( *Data == 4 )
    {
      if ( v17(hKey, L"AutorunsDisabled", 0, 0, Data, &cbData) )
        goto LABEL_60;
      v90 = 0;
    }
    else
    {
      v90 = 1;
    }
    if ( v17(hKey, L"Type", 0, 0, &v48, &cbData) || v48 <= 2 )
      goto LABEL_60;
    v18 = str3.m_String;
    str3.m_String = _wcsdup(&gszNullString);
    free(v18);
    if ( PE_ReadRegKey(hKey, L"ServiceDll", 0, 0, &v89) )
    {
      if ( !PE_OpenKey(hKey, L"Parameters", 0, 1u, &KeyHandle) )
      {
        if ( !PE_ReadRegKey(KeyHandle, L"ServiceDll", 0, 0, &v89) )
        {
          v22 = v86;
          v86 = _wcsdup(v89);
          free(v22);
          sub_FD2170(&v44);
          LOBYTE(v91) = 21;
          sub_FD7040(v89, &v44);
          v23 = sub_FD4EE0(&v49, a1, &v44, 0);
          CPEString::Reset2(&str3, v23);
          free(v49);
          LOBYTE(v91) = 7;
          sub_FD21F0(&v44);
        }
        RegCloseKey(KeyHandle);
      }
    }
    else
    {
      v19 = v86;
      v86 = _wcsdup(v89);
      free(v19);
      v44.strValue[4] = malloc(2u);
      *v44.strValue[4] = 0;
      v44.strValue[5] = 0;
      v44.strValue[6] = 0;
      v45 = 0;
      LOBYTE(v91) = 20;
      sub_FD7040(v89, &v44.strValue[4]);
      v20 = sub_FD4EE0(&v52, a1, &v44.strValue[4], 0);
      v21 = str3.m_String;
      str3.m_String = _wcsdup(*v20);
      free(v21);
      free(v52);
      LOBYTE(v91) = 7;
      sub_FD21F0((&v44 + 16));
    }
    if ( *str3.m_String )
    {
LABEL_36:
      dwValue = sub_FD4ED0();
      PE_ReadRegKey(hKey, L"Description", 0, 0, &ppv);
      if ( wcslen(ppv) && *ppv == 64 )
      {
        v29 = _wcsdup(lpszKeyName);
        PE_GetServiceDescription(v29, &ppv);
      }
      else if ( wcslen(ppv) > 3 && *(ppv + wcslen(ppv) - 1) == 10 )
      {
        *(ppv + wcslen(ppv) - 1) = 0;
        if ( *(ppv + wcslen(ppv) - 1) == 13 )
          *(ppv + wcslen(ppv) - 1) = 0;
      }
      v30 = ppv3;
      ppv3 = _wcsdup(lpszKeyName);
      free(v30);
      v31 = &gszNullString;
      if ( v11 )
        v31 = v11;
      szKeyName = _wcsdup(v31);
      v74 = _wcsdup(&gszNullString);
      v32 = &gszNullString;
      if ( v11 )
        v32 = v11;
      v72 = _wcsdup(v32);
      LOBYTE(v91) = 25;
      v33 = MakeRegistryKeyName(&strResult, a2, &szKeyName, &lpszKeyName);
      LOBYTE(v91) = 26;
      v34 = MakeRegistryKeyName(v51, a2, &v72, &v74);
      LOBYTE(v91) = 27;
      v35 = sub_FD3D40(a1, &ppv3, v34, v33, &str3, &v71, &v65, &v54);
      free(*v51);
      free(strResult.m_String);
      free(v72);
      free(v74);
      LOBYTE(v91) = 7;
      free(szKeyName);
      if ( v35 )
      {
        if ( ppv1 == -1 )
        {
          v60 = _wcsdup(&gszNullString);
          v59 = _wcsdup(&gszNullString);
          v61 = _wcsdup(&gszNullString);
          szArg3 = _wcsdup(&gszNullString);
          v79 = _wcsdup(&gszNullString);
          pszText = _wcsdup(&gszNullString);
          szArg4 = _wcsdup(&gszNullString);
          v11 = psz;
          v36 = &gszNullString;
          if ( psz )
            v36 = psz;
          v81 = _wcsdup(v36);
          v80 = _wcsdup(&gszNullString);
          v37 = &gszNullString;
          if ( psz )
            v37 = psz;
          v78 = _wcsdup(v37);
          LOBYTE(v91) = 37;
          v38 = MakeRegistryKeyName(v56, a2, &v81, &szArg4);
          LOBYTE(v91) = 38;
          v39 = MakeRegistryKeyName(v57, a2, &v78, &v80);
          LOBYTE(v91) = 39;
          ppv1 = sub_FD3FF0(a1, 0, 0xFFFFFFFF, 0, v39, v38, &pszText);
          free(*v57);
          free(*v56);
          free(v78);
          free(v80);
          free(v81);
          free(szArg4);
          free(pszText);
          free(v79);
          free(szArg3);
          free(v61);
          free(v59);
          free(v60);
        }
        else
        {
          v11 = psz;
        }
        *szArg = _wcsdup(&gszNullString);
        v40 = &gszNullString;
        if ( v11 )
          v40 = v11;
        a1a = _wcsdup(v40);
        LOBYTE(v91) = 41;
        v41 = MakeRegistryKeyName(v50, a2, &a1a, &lpszKeyName);
        LOBYTE(v91) = 42;
        sub_FD3FF0(a1, dwValue, ppv1, 8u, &ppv3, v41, &str3);
        free(*v50);
        free(a1a);
        LOBYTE(v91) = 7;
        free(*szArg);
      }
      else
      {
        v11 = psz;
      }
      v17 = RegQueryValueExW;
      goto LABEL_60;
    }
    v17 = RegQueryValueExW;
    if ( !PE_ReadRegKey(hKey, L"ImagePath", 0, 0, &v89) )
    {
      cbData = 4;
      if ( RegQueryValueExW(hKey, L"WOW64", 0, 0, &v47, &cbData) )
      {
        v24 = v86;
        v86 = _wcsdup(v89);
        free(v24);
        sub_FD2170(&a2a);
        LOBYTE(v91) = 22;
        sub_FD6CC0(v89, &a2a);
        v25 = sub_FD4EE0(&v55, a1, &a2a, 0);
        CPEString::Reset2(&str3, v25);
        free(v55);
        LOBYTE(v91) = 7;
        sub_FD21F0(&a2a);
      }
      else
      {
        if ( !*&v47 )
          goto LABEL_35;
        if ( Wow64EnableWow64FsRedirection )
        {
          Wow64EnableWow64FsRedirection(1u);
          TlsSetValue(gdwTlsIndex, 0x200);
        }
        v26 = v86;
        v86 = _wcsdup(v89);
        free(v26);
        v27 = _wcsdup(v89);
        PE_GetSystemPathInfo(&v53, v27);
        free(v53);
        v28 = sub_FD4F20(&v58, a1, v89);
        CPEString::Reset2(&str3, v28);
        free(v58);
        if ( Wow64EnableWow64FsRedirection )
        {
          Wow64EnableWow64FsRedirection(0);
          TlsSetValue(gdwTlsIndex, 0x100);
        }
      }
      v17 = RegQueryValueExW;
    }
LABEL_35:
    if ( *str3.m_String )
      goto LABEL_36;
LABEL_60:
    RegCloseKey(hKey);
LABEL_61:
    ++v66;
  }
  while ( !PE_LoadRegKeys(hRootKey, v66, &lpszKeyName) );
  v16 = ppv1;
LABEL_63:
  RegCloseKey(hRootKey);
LABEL_64:
  free(v86);
  free(v65);
  free(ppv);
  free(v71);
  free(str3.m_String);
  free(ppv3);
  free(lpszKeyName);
  free(v89);
  return v16;
}

//----- (00FEA070) --------------------------------------------------------
void __cdecl sub_FEA070(int a1, void *a2, void *a3)
{
  _WORD *v3; // ST50_4
  CPEString *v4; // esi
  void *v5; // edi
  CPEString *v6; // eax
  wchar_t *v7; // ST54_4

  v3 = malloc(2u);
  *v3 = 0;
  v4 = a3;
  v5 = sub_FEA120(a1, a2, *a3, 0xFFFFFFFF);
  v6 = CPEString::Append(&a3, v4, L"\\AutorunsDisabled");
  v7 = _wcsdup(v6->m_String);
  free(v3);
  free(a3);
  sub_FEA120(a1, a2, v7, v5);
  free(v7);
}

//----- (00FEA120) --------------------------------------------------------
void *__cdecl sub_FEA120(int a1, void *a2, wchar_t *psz, void *a4)
{
  const wchar_t *v4; // eax
  const wchar_t *v5; // eax
  CPEString *v6; // esi
  CPEString *v7; // eax
  unsigned int v8; // eax
  void (__stdcall *RegCloseKey)(HKEY); // ebx
  LPVOID (__stdcall *TlsGetValue)(DWORD); // edi
  CPEString *v11; // eax
  WCHAR *v12; // esi
  const WCHAR *v13; // esi
  unsigned int v14; // eax
  wchar_t *v15; // esi
  wchar_t *v16; // esi
  unsigned int v17; // eax
  wchar_t *v18; // esi
  CPEString *v19; // eax
  CPEString *v20; // eax
  WCHAR *v21; // esi
  const WCHAR *v22; // esi
  unsigned int v23; // eax
  const wchar_t *v24; // ecx
  wchar_t *v25; // eax
  WCHAR *v26; // edi
  wchar_t *v27; // esi
  const wchar_t **v28; // eax
  WCHAR *v29; // esi
  const wchar_t **v30; // eax
  WCHAR *v31; // esi
  WCHAR *v32; // esi
  CPEString *v33; // eax
  WCHAR *v34; // edi
  WCHAR *v35; // esi
  const WCHAR *v36; // esi
  unsigned int v37; // eax
  WCHAR *v38; // esi
  const wchar_t *v39; // eax
  const wchar_t *v40; // eax
  CPEString *v41; // esi
  CPEString *v42; // eax
  char v43; // bl
  const wchar_t *v44; // eax
  const wchar_t *v45; // eax
  CPEString *v46; // esi
  CPEString *v47; // eax
  int v48; // ebx
  const wchar_t *v49; // eax
  WCHAR *v50; // esi
  __int16 *v51; // edx
  __int16 v52; // cx
  const wchar_t *v53; // eax
  CPEString *v54; // eax
  DWORD v55; // esi
  void **v56; // esi
  int v57; // edi
  CPEString v59; // [esp+10h] [ebp-C4h]
  WCHAR *ppv; // [esp+14h] [ebp-C0h]
  WCHAR v61[2]; // [esp+18h] [ebp-BCh]
  WCHAR v62[2]; // [esp+1Ch] [ebp-B8h]
  int a2a; // [esp+20h] [ebp-B4h]
  WCHAR *pszResult; // [esp+24h] [ebp-B0h]
  int v65; // [esp+28h] [ebp-ACh]
  WCHAR *ppv1; // [esp+2Ch] [ebp-A8h]
  WCHAR v67[2]; // [esp+30h] [ebp-A4h]
  void *v68; // [esp+34h] [ebp-A0h]
  WCHAR v69[2]; // [esp+38h] [ebp-9Ch]
  WCHAR v70[2]; // [esp+3Ch] [ebp-98h]
  int v71; // [esp+40h] [ebp-94h]
  void *v72; // [esp+44h] [ebp-90h]
  LPCWSTR v73; // [esp+48h] [ebp-8Ch]
  LPCWSTR v74; // [esp+4Ch] [ebp-88h]
  void *v75; // [esp+50h] [ebp-84h]
  CPEString str3; // [esp+54h] [ebp-80h]
  void *v77; // [esp+58h] [ebp-7Ch]
  LPCWSTR v78; // [esp+5Ch] [ebp-78h]
  void *v79; // [esp+60h] [ebp-74h]
  void *v80; // [esp+64h] [ebp-70h]
  void *v81; // [esp+68h] [ebp-6Ch]
  WCHAR *v82; // [esp+6Ch] [ebp-68h]
  void *v83; // [esp+70h] [ebp-64h]
  WCHAR szArg[2]; // [esp+74h] [ebp-60h]
  HKEY KeyHandle; // [esp+78h] [ebp-5Ch]
  void *a1a; // [esp+7Ch] [ebp-58h]
  void *v87; // [esp+80h] [ebp-54h]
  LPCWSTR v88; // [esp+84h] [ebp-50h]
  tagPEStringStruct v89; // [esp+88h] [ebp-4Ch]
  LPCWSTR szArg3; // [esp+A4h] [ebp-30h]
  WCHAR *ppv2; // [esp+A8h] [ebp-2Ch]
  wchar_t *ppszText2; // [esp+ACh] [ebp-28h]
  CPEString str1; // [esp+B0h] [ebp-24h]
  wchar_t *pszText; // [esp+B4h] [ebp-20h]
  HKEY hKey; // [esp+B8h] [ebp-1Ch]
  LPCWSTR szArg4; // [esp+BCh] [ebp-18h]
  wchar_t *ppv3; // [esp+C0h] [ebp-14h]
  LPCWSTR lpszKeyName; // [esp+C4h] [ebp-10h]
  int v99; // [esp+D0h] [ebp-4h]

  str1.m_String = malloc(2u);
  *str1.m_String = 0;
  v99 = 0;
  ppszText2 = malloc(2u);
  *ppszText2 = 0;
  v87 = malloc(2u);
  *v87 = 0;
  v83 = malloc(2u);
  *v83 = 0;
  v82 = malloc(2u);
  *v82 = 0;
  LOBYTE(v99) = 4;
  if ( a4 == -1 )
  {
    v89.strValue[4] = _wcsdup(&gszNullString);
    v89.strValue[6] = _wcsdup(&gszNullString);
    szArg3 = _wcsdup(&gszNullString);
    v89.strValue[5] = _wcsdup(&gszNullString);
    v88 = _wcsdup(&gszNullString);
    lpszKeyName = _wcsdup(&gszNullString);
    szArg4 = _wcsdup(&gszNullString);
    v4 = &gszNullString;
    if ( psz )
      v4 = psz;
    ppv3 = _wcsdup(v4);
    hKey = _wcsdup(&gszNullString);
    v5 = &gszNullString;
    if ( psz )
      v5 = psz;
    pszText = _wcsdup(v5);
    LOBYTE(v99) = 14;
    v6 = MakeRegistryKeyName(&a1a, a2, &ppv3, &szArg4);
    LOBYTE(v99) = 15;
    v7 = MakeRegistryKeyName(szArg, a2, &pszText, &hKey);
    LOBYTE(v99) = 16;
    a4 = sub_FD3FF0(a1, 0, 0xFFFFFFFF, 0, v7, v6, &lpszKeyName);
    free(*szArg);
    free(a1a);
    free(pszText);
    free(hKey);
    free(ppv3);
    free(szArg4);
    free(lpszKeyName);
    free(v88);
    free(v89.strValue[5]);
    free(szArg3);
    free(v89.strValue[6]);
    LOBYTE(v99) = 4;
    free(v89.strValue[4]);
  }
  v8 = ::TlsGetValue(gdwTlsIndex);
  if ( !PE_OpenKey(a2, psz, 0, v8 | 0x20019, &KeyHandle) )
  {
    *szArg = 0;
    pszText = malloc(2u);
    *pszText = 0;
    lpszKeyName = malloc(2u);
    *lpszKeyName = 0;
    ppv3 = malloc(2u);
    *ppv3 = 0;
    szArg4 = malloc(2u);
    *szArg4 = 0;
    v89.strValue[0] = malloc(2u);
    *v89.strValue[0] = 0;
    v89.strValue[1] = 0;
    v89.strValue[2] = 0;
    v89.strValue[3] = 0;
    LOBYTE(v99) = 21;
    RegCloseKey = ::RegCloseKey;
    if ( !PE_LoadRegKeys(KeyHandle, 0, &ppszText2) )
    {
      TlsGetValue = ::TlsGetValue;
      do
      {
        v11 = operator+(&pszResult, L"CLSID\\", &ppszText2);
        v12 = lpszKeyName;
        lpszKeyName = _wcsdup(v11->m_String);
        free(v12);
        free(pszResult);
        v13 = lpszKeyName;
        v14 = TlsGetValue(gdwTlsIndex);
        if ( PE_OpenKey(HKEY_CLASSES_ROOT, v13, 0, v14 | 0x20019, &hKey) )
        {
          v16 = ppszText2;
          v17 = TlsGetValue(gdwTlsIndex);
          if ( PE_OpenKey(KeyHandle, v16, 0, v17 | 0x20019, &hKey) )
            goto LABEL_52;
          if ( PE_ReadRegKey(hKey, &gszNullString, 0, 0, &ppv3) )
            goto LABEL_51;
          v18 = pszText;
          pszText = _wcsdup(ppszText2);
          free(v18);
        }
        else
        {
          v15 = ppv3;
          ppv3 = _wcsdup(ppszText2);
          free(v15);
          PE_ReadRegKey(hKey, &gszNullString, 0, 0, &pszText);
        }
        RegCloseKey(hKey);
        v19 = operator+(&v59, L"CLSID\\", &ppv3);
        v20 = CPEString::Append(&ppv, v19, L"\\InprocServer32");
        v21 = lpszKeyName;
        lpszKeyName = _wcsdup(v20->m_String);
        free(v21);
        free(ppv);
        free(v59.m_String);
        v22 = lpszKeyName;
        v23 = TlsGetValue(gdwTlsIndex);
        if ( !PE_OpenKey(HKEY_CLASSES_ROOT, v22, 0, v23 | 0x20019, &hKey) )
        {
          if ( !PE_ReadRegKey(hKey, L"CodeBase", 0, 0, &lpszKeyName) )
          {
            if ( !wcscspn(lpszKeyName, L"file:////") )
            {
              v24 = &gszNullString;
              if ( lpszKeyName != -18 )
                v24 = lpszKeyName + 9;
              v25 = _wcsdup(v24);
              v26 = lpszKeyName;
              v27 = v25;
              lpszKeyName = _wcsdup(v25);
              free(v26);
              free(v27);
            }
            sub_FD7040(lpszKeyName, &v89);
            v28 = sub_FD4EE0(&v71, a1, &v89, 0);
            v29 = szArg4;
            szArg4 = _wcsdup(*v28);
            free(v29);
            free(v71);
            goto LABEL_24;
          }
          if ( !PE_ReadRegKey(hKey, &gszNullString, 0, 0, &lpszKeyName) )
          {
            sub_FD7040(lpszKeyName, &v89);
            v30 = sub_FD4EE0(&v68, a1, &v89, 0);
            v31 = szArg4;
            szArg4 = _wcsdup(*v30);
            free(v31);
            free(v68);
LABEL_24:
            RegCloseKey(hKey);
            a2a = sub_FD4ED0();
            v32 = _wcsdup(L"CLSID\\");
            ppv2 = v32;
            v33 = CPEString::Append(&ppv1, &ppv2, &ppv3);
            v34 = lpszKeyName;
            lpszKeyName = _wcsdup(v33->m_String);
            free(v34);
            free(ppv1);
            free(v32);
            operator+(&a1a, L"HKCR\\CLSID\\", &ppv3);
            v35 = str1.m_String;
            LOBYTE(v99) = 22;
            str1.m_String = _wcsdup(ppv3);
            free(v35);
            v36 = lpszKeyName;
            v37 = ::TlsGetValue(gdwTlsIndex);
            if ( !PE_OpenKey(HKEY_CLASSES_ROOT, v36, 0, v37 | 0x20019, &hKey) )
            {
              if ( !PE_ReadRegKey(hKey, &gszNullString, 0, 0, &lpszKeyName) && wcslen(lpszKeyName) )
              {
                v38 = str1.m_String;
                str1.m_String = _wcsdup(lpszKeyName);
                free(v38);
              }
              RegCloseKey(hKey);
            }
            v39 = &gszNullString;
            if ( psz )
              v39 = psz;
            szArg3 = _wcsdup(v39);
            v89.strValue[6] = _wcsdup(&gszNullString);
            v40 = &gszNullString;
            if ( psz )
              v40 = psz;
            v89.strValue[4] = _wcsdup(v40);
            LOBYTE(v99) = 25;
            v41 = MakeRegistryKeyName(v70, a2, &szArg3, &ppszText2);
            LOBYTE(v99) = 26;
            v42 = MakeRegistryKeyName(v62, a2, &v89.strValue[4], &v89.strValue[6]);
            LOBYTE(v99) = 27;
            v43 = sub_FD3D40(a1, &str1, v42, v41, &szArg4, &v87, &v82, &v65);
            free(*v62);
            free(*v70);
            free(v89.strValue[4]);
            free(v89.strValue[6]);
            free(szArg3);
            if ( v43 )
            {
              if ( a4 == -1 )
              {
                v77 = _wcsdup(&gszNullString);
                v75 = _wcsdup(&gszNullString);
                v81 = _wcsdup(&gszNullString);
                v79 = _wcsdup(&gszNullString);
                v72 = _wcsdup(&gszNullString);
                str3.m_String = _wcsdup(&gszNullString);
                v78 = _wcsdup(&gszNullString);
                v44 = &gszNullString;
                if ( psz )
                  v44 = psz;
                v74 = _wcsdup(v44);
                v88 = _wcsdup(&gszNullString);
                v45 = &gszNullString;
                if ( psz )
                  v45 = psz;
                v89.strValue[5] = _wcsdup(v45);
                LOBYTE(v99) = 37;
                v46 = MakeRegistryKeyName(v67, a2, &v74, &v78);
                LOBYTE(v99) = 38;
                v47 = MakeRegistryKeyName(v69, a2, &v89.strValue[5], &v88);
                LOBYTE(v99) = 39;
                v48 = a1;
                a4 = sub_FD3FF0(a1, 0, 0xFFFFFFFF, 0, v47, v46, &str3);
                free(*v69);
                free(*v67);
                free(v89.strValue[5]);
                free(v88);
                free(v74);
                free(v78);
                free(str3.m_String);
                free(v72);
                free(v79);
                free(v81);
                free(v75);
                free(v77);
              }
              else
              {
                v48 = a1;
              }
              v49 = pszText;
              v50 = str1.m_String;
              if ( wcslen(pszText) )
                goto LABEL_63;
              if ( *str1.m_String == 123 )
              {
                v49 = v83;
                v51 = v83;
                ppv2 = (v83 + 2);
                do
                {
                  v52 = *v51;
                  ++v51;
                }
                while ( v52 );
                if ( (v51 - ppv2) >> 1 )
                {
LABEL_63:
                  str1.m_String = _wcsdup(v49);
                  free(v50);
                }
              }
              v80 = _wcsdup(&gszNullString);
              v53 = &gszNullString;
              if ( psz )
                v53 = psz;
              v73 = _wcsdup(v53);
              LOBYTE(v99) = 41;
              v54 = MakeRegistryKeyName(v61, a2, &v73, &ppszText2);
              LOBYTE(v99) = 42;
              sub_FD3FF0(v48, a2a, a4, 3u, &str1, v54, &szArg4);
              free(*v61);
              free(v73);
              free(v80);
            }
            free(a1a);
            sub_FD21F0(&v89);
            free(szArg4);
            free(ppv3);
            free(lpszKeyName);
            free(pszText);
            RegCloseKey = ::RegCloseKey;
            TlsGetValue = ::TlsGetValue;
            goto LABEL_53;
          }
LABEL_51:
          RegCloseKey(hKey);
        }
LABEL_52:
        sub_FD21F0(&v89);
        free(szArg4);
        free(ppv3);
        free(lpszKeyName);
        free(pszText);
LABEL_53:
        v55 = ++*szArg;
        pszText = malloc(2u);
        *pszText = 0;
        lpszKeyName = malloc(2u);
        *lpszKeyName = 0;
        ppv3 = malloc(2u);
        *ppv3 = 0;
        szArg4 = malloc(2u);
        *szArg4 = 0;
        v89.strValue[0] = malloc(2u);
        *v89.strValue[0] = 0;
        v89.strValue[1] = 0;
        v89.strValue[2] = 0;
        v89.strValue[3] = 0;
        LOBYTE(v99) = 21;
      }
      while ( !PE_LoadRegKeys(KeyHandle, v55, &ppszText2) );
    }
    v56 = v89.strValue[1];
    if ( v89.strValue[1] )
    {
      v57 = v89.strValue[2];
      if ( v89.strValue[1] != v89.strValue[2] )
      {
        do
        {
          free(*v56);
          ++v56;
        }
        while ( v56 != v57 );
        v56 = v89.strValue[1];
      }
      j__free(v56);
      v89.strValue[1] = 0;
      v89.strValue[2] = 0;
      v89.strValue[3] = 0;
    }
    free(v89.strValue[0]);
    free(szArg4);
    free(ppv3);
    free(lpszKeyName);
    free(pszText);
    RegCloseKey(KeyHandle);
  }
  free(v82);
  free(v83);
  free(v87);
  free(ppszText2);
  free(str1.m_String);
  return a4;
}

//----- (00FEAC50) --------------------------------------------------------
int __stdcall cbstrList::getInstance(int a1, int a2, int a3)
{
  int result; // eax
  int v4; // esi

  result = cbstrList::cbstrList(a1, a2);
  v4 = result;
  if ( result != -8 )
  {
    tagPEStringStruct::tagPEStringStruct((result + 8), a3);
    result = v4;
  }
  return result;
}

//----- (00FEAC80) --------------------------------------------------------
tagPEStringStruct *__thiscall tagPEStringStruct::tagPEStringStruct(tagPEStringStruct *this, int a2)
{
  tagPEStringStruct *v2; // esi
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax

  v2 = this;
  this->strValue[0] = *a2;
  LOBYTE(this->strValue[1]) = *(a2 + 4);
  v3 = *(a2 + 8);
  this->strValue[2] = v3;
  if ( v3 )
    InterlockedIncrement((v3 + 8));
  v4 = *(a2 + 12);
  v2->strValue[3] = v4;
  if ( v4 )
    InterlockedIncrement((v4 + 8));
  v5 = *(a2 + 16);
  v2->strValue[4] = v5;
  if ( v5 )
    InterlockedIncrement((v5 + 8));
  v6 = *(a2 + 20);
  v2->strValue[5] = v6;
  if ( v6 )
    InterlockedIncrement((v6 + 8));
  v7 = *(a2 + 24);
  v2->strValue[6] = v7;
  if ( v7 )
    InterlockedIncrement((v7 + 8));
  v8 = *(a2 + 28);
  v2[1].strValue[0] = v8;
  if ( v8 )
    InterlockedIncrement((v8 + 8));
  v9 = *(a2 + 32);
  v2[1].strValue[1] = v9;
  if ( v9 )
    InterlockedIncrement((v9 + 8));
  return v2;
}

//----- (00FEAD20) --------------------------------------------------------
// _bstr_t::_bstr_t(const _variant_t &var)
EventItem *__thiscall _bstr_t::_bstr_t(_bstr_t *this, VARIANTARG *pvarSrc)
{
  EventItem *v2; // esi
  int v3; // eax
  VARIANTARG pvarg; // [esp+Ch] [ebp-1Ch]
  int v6; // [esp+24h] [ebp-4h]

  v2 = this;
  this->m_Data = 0;
  if ( pvarSrc->vt == VT_BSTR )
  {
    _bstr_t::operator=(this, pvarSrc->bstrVal);
  }
  else
  {
    VariantInit(&pvarg);
    v6 = 0;
    if ( &pvarg != pvarSrc || pvarg.vt != 8 )
    {
      v3 = VariantChangeType(&pvarg, pvarSrc, 0, 8u);
      if ( v3 < 0 )
        _com_issue_error(v3);
    }
    _bstr_t::operator=(v2, pvarg.bstrVal);
    VariantClear(&pvarg);
  }
  return v2;
}

//----- (00FEADD0) --------------------------------------------------------
_bstr_t *__thiscall _bstr_t::_bstr_t(_bstr_t *this, LPCSTR lpString)
{
  _bstr_t *v2; // edi
  Data_t_bstr_t *v3; // eax
  Data_t_bstr_t *v4; // esi

  v2 = this;
  v3 = operator new(0xCu);
  v4 = v3;
  if ( v3 )
  {
    v3->m_str = 0;
    v3->m_RefCount = 1;
    v3->m_wstr = _com_util::ConvertStringToBSTR(lpString);
  }
  else
  {
    v4 = 0;
  }
  v2->m_Data = v4;
  if ( !v4 )
    _com_issue_error(E_OUTOFMEMORY);
  return v2;
}

//----- (00FEAE80) --------------------------------------------------------
void __thiscall tagPEStringStruct::~tagPEStringStruct(tagPEStringStruct *this)
{
  tagPEStringStruct *v1; // esi
  LONG (__stdcall *v2)(volatile LONG *); // ecx
  int v3; // edi
  int v4; // edi
  int v5; // edi
  int v6; // edi
  int v7; // edi
  int v8; // edi
  int v9; // edi

  v1 = this;
  v2 = InterlockedDecrement;
  v3 = v1[1].strValue[1];
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
    v2 = InterlockedDecrement;
    v1[1].strValue[1] = 0;
  }
  v4 = v1[1].strValue[0];
  if ( v4 )
  {
    if ( !v2((v4 + 8)) && v4 )
    {
      if ( *v4 )
      {
        SysFreeString(*v4);
        *v4 = 0;
      }
      if ( *(v4 + 4) )
      {
        j_j__free(*(v4 + 4));
        *(v4 + 4) = 0;
      }
      j__free(v4);
    }
    v1[1].strValue[0] = 0;
  }
  v5 = v1->strValue[6];
  if ( v5 )
  {
    if ( !InterlockedDecrement((v5 + 8)) && v5 )
    {
      if ( *v5 )
      {
        SysFreeString(*v5);
        *v5 = 0;
      }
      if ( *(v5 + 4) )
      {
        j_j__free(*(v5 + 4));
        *(v5 + 4) = 0;
      }
      j__free(v5);
    }
    v1->strValue[6] = 0;
  }
  v6 = v1->strValue[5];
  if ( v6 )
  {
    if ( !InterlockedDecrement((v6 + 8)) && v6 )
    {
      if ( *v6 )
      {
        SysFreeString(*v6);
        *v6 = 0;
      }
      if ( *(v6 + 4) )
      {
        j_j__free(*(v6 + 4));
        *(v6 + 4) = 0;
      }
      j__free(v6);
    }
    v1->strValue[5] = 0;
  }
  v7 = v1->strValue[4];
  if ( v7 )
  {
    if ( !InterlockedDecrement((v7 + 8)) && v7 )
    {
      if ( *v7 )
      {
        SysFreeString(*v7);
        *v7 = 0;
      }
      if ( *(v7 + 4) )
      {
        j_j__free(*(v7 + 4));
        *(v7 + 4) = 0;
      }
      j__free(v7);
    }
    v1->strValue[4] = 0;
  }
  v8 = v1->strValue[3];
  if ( v8 )
  {
    if ( !InterlockedDecrement((v8 + 8)) && v8 )
    {
      if ( *v8 )
      {
        SysFreeString(*v8);
        *v8 = 0;
      }
      if ( *(v8 + 4) )
      {
        j_j__free(*(v8 + 4));
        *(v8 + 4) = 0;
      }
      j__free(v8);
    }
    v1->strValue[3] = 0;
  }
  v9 = v1->strValue[2];
  if ( v9 )
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
    v1->strValue[2] = 0;
  }
}

//----- (00FEB0D0) --------------------------------------------------------
Data_t_bstr_t *__thiscall bstr_t::Assign(_bstr_t *this, int a2)
{
  _bstr_t *v2; // edi
  Data_t_bstr_t *v3; // esi
  Data_t_bstr_t *result; // eax

  v2 = this;
  v3 = this->m_Data;
  if ( this->m_Data )
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
    v2->m_Data = 0;
  }
  result = operator new(0xCu);
  if ( result )
  {
    result->m_str = 0;
    result->m_RefCount = 1;
    result->m_wstr = a2;
  }
  else
  {
    result = 0;
  }
  v2->m_Data = result;
  if ( !result )
    _com_issue_error(-2147024882);
  return result;
}

//----- (00FEB1A0) --------------------------------------------------------
char __cdecl PE_LoadConfigFiles(_bstr_t *bstrConfigFile, std__List *pList)
{
  HMODULE v2; // eax
  HMODULE v3; // eax
  int v4; // esi
  int v5; // edi
  const WCHAR *pszFileName; // eax
  _DWORD *v7; // eax
  _DWORD *v8; // ecx
  const WCHAR *v9; // eax
  Data_t_bstr_t *v10; // eax
  Data_t_bstr_t *v11; // edi
  BSTR v12; // eax
  const WCHAR ***v13; // esi
  _bstr_t *v14; // eax
  const WCHAR *pszConfigFile; // ecx
  const WCHAR **v16; // eax
  const WCHAR *pszSectionName; // eax
  DWORD dwRet; // eax
  Data_t_bstr_t *v19; // esi
  Data_t_bstr_t *v20; // esi
  Data_t_bstr_t *v21; // edi
  std__list_node *v22; // eax
  std__List *v23; // edi
  HANDLE dwSectionID; // esi
  _bstr_t *v25; // eax
  const WCHAR *v26; // esi
  const WCHAR *v27; // eax
  Data_t_bstr_t *v28; // esi
  int v29; // eax
  _bstr_t *v30; // eax
  const WCHAR *v31; // esi
  const WCHAR *v32; // eax
  Data_t_bstr_t *v33; // esi
  IXMLDOMParseError *v34; // eax
  Data_t_bstr_t *v35; // esi
  BSTR v36; // eax
  const WCHAR ***v37; // esi
  _bstr_t *v38; // eax
  const WCHAR *v39; // ecx
  const WCHAR **v40; // eax
  const WCHAR *v41; // eax
  void *v42; // esi
  void *v43; // esi
  IXMLDOMParseError *v44; // esi
  HMODULE v45; // eax
  FARPROC v46; // eax
  HANDLE v47; // eax
  wchar_t *v48; // edx
  OLECHAR *v49; // ST18_4
  Data_t_bstr_t *v50; // esi
  IXMLDOMParseError *v51; // eax
  IXMLDOMParseErrorVtbl *v52; // eax
  IXMLDOMParseError *v53; // ecx
  IXMLDOMParseError *v54; // eax
  Data_t_bstr_t *v55; // eax
  OLECHAR *v56; // eax
  Data_t_bstr_t *v57; // ecx
  Data_t_bstr_t *v58; // eax
  Data_t_bstr_t *v59; // eax
  OLECHAR *v60; // eax
  Data_t_bstr_t *v61; // ecx
  Data_t_bstr_t *v62; // eax
  _bstr_t *v63; // eax
  _bstr_t *v64; // eax
  _bstr_t *v65; // eax
  void **v66; // eax
  void **v67; // eax
  void **v68; // eax
  Data_t_bstr_t *v69; // eax
  Data_t_bstr_t *v70; // eax
  IXMLDOMParseError *v71; // eax
  OLECHAR *v72; // eax
  HANDLE v73; // eax
  Data_t_bstr_t *v74; // eax
  OLECHAR *v75; // eax
  Data_t_bstr_t *v76; // ecx
  Data_t_bstr_t *v77; // eax
  Data_t_bstr_t *v78; // eax
  OLECHAR *v79; // eax
  Data_t_bstr_t *v80; // ecx
  Data_t_bstr_t *v81; // eax
  Data_t_bstr_t *v82; // eax
  IXMLDOMParseErrorVtbl *v83; // eax
  IXMLDOMParseError *v84; // ecx
  IXMLDOMParseError *v85; // eax
  _bstr_t *v86; // eax
  _bstr_t *v87; // eax
  _bstr_t *v88; // eax
  void **v89; // eax
  void **v90; // eax
  void **v91; // eax
  IXMLDOMParseError *v92; // eax
  Data_t_bstr_t *v93; // eax
  Data_t_bstr_t *v94; // eax
  char *v95; // eax
  Data_t_bstr_t *v96; // eax
  OLECHAR *v97; // eax
  Data_t_bstr_t *v98; // eax
  IXMLDOMParseErrorVtbl *v99; // eax
  IXMLDOMParseError *v100; // ecx
  IXMLDOMParseError *v101; // eax
  _bstr_t *v102; // eax
  void **v103; // eax
  IXMLDOMParseError *v104; // eax
  OLECHAR *v105; // eax
  Data_t_bstr_t *v106; // eax
  IXMLDOMParseErrorVtbl *v107; // eax
  IXMLDOMParseError *v108; // ecx
  IXMLDOMParseError *v109; // eax
  _bstr_t *v110; // eax
  void **v111; // eax
  IXMLDOMParseError *v112; // eax
  OLECHAR *v113; // eax
  void **v114; // eax
  volatile LONG *v115; // eax
  int v116; // eax
  unsigned int v117; // ecx
  Data_t_bstr_t *v118; // eax
  Data_t_bstr_t *v119; // edx
  Data_t_bstr_t *v120; // esi
  IXMLDOMParseError *v121; // edi
  __int16 v122; // ax
  void **v123; // eax
  Data_t_bstr_t *v124; // esi
  const wchar_t *v125; // eax
  const wchar_t *v126; // eax
  wchar_t *v127; // eax
  wint_t v128; // cx
  _WORD *v129; // edi
  wint_t v130; // ax
  Data_t_bstr_t *v131; // eax
  const OLECHAR *v132; // ST18_4
  OLECHAR *v133; // eax
  Data_t_bstr_t *v134; // ecx
  Data_t_bstr_t *v135; // eax
  Data_t_bstr_t *v136; // eax
  void *hResult; // eax
  BOOLEAN (__stdcall *Wow64EnableWow64FsRedirection)(BOOLEAN); // ecx
  OLECHAR *v139; // edx
  Data_t_bstr_t *v140; // eax
  IXMLDOMParseErrorVtbl *v141; // eax
  IXMLDOMParseError *v142; // edx
  OLECHAR *bstrQuery; // ST14_4
  HRESULT hresult; // eax
  LONG v145; // eax
  IXMLDOMParseError *v146; // eax
  Data_t_bstr_t *v147; // eax
  IXMLDOMParseErrorVtbl *v148; // eax
  IXMLDOMParseError *v149; // edx
  OLECHAR *bstrQueryText; // ST14_4
  HRESULT v151; // eax
  IXMLDOMParseError *v152; // eax
  Data_t_bstr_t *v153; // eax
  OLECHAR *v154; // edx
  HRESULT v155; // eax
  Data_t_bstr_t *v156; // eax
  OLECHAR *v157; // edx
  HRESULT v158; // eax
  Data_t_bstr_t *v159; // eax
  OLECHAR *bstrName; // edx
  HRESULT v161; // eax
  Data_t_bstr_t *v162; // eax
  OLECHAR *v163; // edx
  HRESULT v164; // eax
  Data_t_bstr_t *v165; // eax
  OLECHAR *v166; // edx
  HRESULT v167; // eax
  char *v168; // edi
  Data_t_bstr_t *v169; // eax
  OLECHAR *v170; // edx
  HRESULT v171; // eax
  Data_t_bstr_t *v172; // eax
  const wchar_t *v173; // eax
  Data_t_bstr_t *v174; // eax
  OLECHAR *v175; // edx
  HRESULT v176; // eax
  signed int v177; // esi
  Data_t_bstr_t *v178; // eax
  const wchar_t *v179; // eax
  Data_t_bstr_t *v180; // eax
  OLECHAR *v181; // edx
  HRESULT v182; // eax
  int v183; // esi
  const wchar_t *v184; // eax
  wchar_t *v185; // eax
  _bstr_t *v186; // eax
  Data_t_bstr_t *v187; // eax
  int v188; // edx
  unsigned int v189; // eax
  std__List *v190; // edi
  std__list_node *v191; // eax
  std__list_node *v192; // esi
  __int128 v194; // [esp+Ch] [ebp-5C4h]
  __int64 v195; // [esp+1Ch] [ebp-5B4h]
  int v196; // [esp+24h] [ebp-5ACh]
  VARIANTARG pvarg; // [esp+28h] [ebp-5A8h]
  DWORD pcchUnescaped; // [esp+38h] [ebp-598h]
  _bstr_t v199; // [esp+3Ch] [ebp-594h]
  _bstr_t v200; // [esp+40h] [ebp-590h]
  _bstr_t v201; // [esp+44h] [ebp-58Ch]
  _bstr_t v202; // [esp+48h] [ebp-588h]
  WCHAR *ppstr; // [esp+4Ch] [ebp-584h]
  _bstr_t v204; // [esp+50h] [ebp-580h]
  _bstr_t v205; // [esp+54h] [ebp-57Ch]
  _bstr_t v206; // [esp+58h] [ebp-578h]
  _bstr_t v207; // [esp+5Ch] [ebp-574h]
  VARIANTARG pvarSrc; // [esp+60h] [ebp-570h]
  _bstr_t v209; // [esp+70h] [ebp-560h]
  _bstr_t v210; // [esp+74h] [ebp-55Ch]
  _bstr_t v211; // [esp+78h] [ebp-558h]
  volatile LONG *v212; // [esp+7Ch] [ebp-554h]
  _bstr_t v213; // [esp+80h] [ebp-550h]
  volatile LONG *v214; // [esp+84h] [ebp-54Ch]
  Data_t_bstr_t *v215; // [esp+88h] [ebp-548h]
  volatile LONG *v216; // [esp+8Ch] [ebp-544h]
  IXMLDOMNode *pIXMLDOMNode3; // [esp+90h] [ebp-540h]
  int v218; // [esp+94h] [ebp-53Ch]
  _bstr_t bstrSectionName_1; // [esp+98h] [ebp-538h]
  _bstr_t bstrDisabled; // [esp+9Ch] [ebp-534h]
  IXMLDOMNamedNodeMap *pIXMLDOMNamedNodeMap; // [esp+A0h] [ebp-530h]
  Data_t_bstr_t *v222; // [esp+A4h] [ebp-52Ch]
  DWORD NumberOfBytesRead; // [esp+A8h] [ebp-528h]
  void *v224; // [esp+ACh] [ebp-524h]
  Data_t_bstr_t *v225; // [esp+B0h] [ebp-520h]
  void *v226; // [esp+B4h] [ebp-51Ch]
  Data_t_bstr_t *v227; // [esp+B8h] [ebp-518h]
  _bstr_t bstrSectionName_2; // [esp+BCh] [ebp-514h]
  Data_t_bstr_t *v229; // [esp+C0h] [ebp-510h]
  int vtFlags; // [esp+C4h] [ebp-50Ch]
  std__List *v231; // [esp+C8h] [ebp-508h]
  tagPEStringStruct StringItem; // [esp+CCh] [ebp-504h]
  _bstr_t v233; // [esp+E8h] [ebp-4E8h]
  _bstr_t v234; // [esp+ECh] [ebp-4E4h]
  int v235; // [esp+F0h] [ebp-4E0h]
  IXMLDOMDocument *pIXMLDOMDocument; // [esp+F4h] [ebp-4DCh]
  tagPEConfigFile *pConfigFile_1; // [esp+F8h] [ebp-4D8h]
  void *nLineNumber; // [esp+FCh] [ebp-4D4h]
  Data_t_bstr_t *bstrSectionName; // [esp+100h] [ebp-4D0h]
  IXMLDOMNode *pIXMLDOMNode; // [esp+104h] [ebp-4CCh]
  Data_t_bstr_t *bstrResult; // [esp+108h] [ebp-4C8h]
  _bstr_t bstrTemp; // [esp+10Ch] [ebp-4C4h]
  std__List *theDwordList; // [esp+110h] [ebp-4C0h]
  int v244; // [esp+114h] [ebp-4BCh]
  std__List *v245; // [esp+118h] [ebp-4B8h]
  int v246; // [esp+11Ch] [ebp-4B4h]
  _bstr_t *bstrDisabled_1; // [esp+120h] [ebp-4B0h]
  IXMLDOMNamedNodeMap *dwIndex; // [esp+124h] [ebp-4ACh]
  Data_t_bstr_t *EventItem; // [esp+128h] [ebp-4A8h]
  Data_t_bstr_t *v250; // [esp+12Ch] [ebp-4A4h]
  IXMLDOMNode *pIXMLDOMNode2; // [esp+130h] [ebp-4A0h]
  Data_t_bstr_t *bstrSourceText; // [esp+134h] [ebp-49Ch]
  void *bstrReason; // [esp+138h] [ebp-498h]
  Data_t_bstr_t *nNumberOfBytesToRead; // [esp+13Ch] [ebp-494h]
  HANDLE nLinePosition; // [esp+140h] [ebp-490h]
  IXMLDOMParseError *pIXMLDOMParseError; // [esp+144h] [ebp-48Ch]
  bool v257; // [esp+14Bh] [ebp-485h]
  __int16 szLocalName[260]; // [esp+14Ch] [ebp-484h]
  __int16 szValue[260]; // [esp+354h] [ebp-27Ch]
  __int16 szSectioName[50]; // [esp+55Ch] [ebp-74h]
  int nStep; // [esp+5CCh] [ebp-4h]

  pConfigFile_1 = bstrConfigFile;
  v231 = pList;
  if ( !GetSystemDefaultLocaleName )
  {
    v2 = LoadLibraryW(L"Kernel32.dll");
    GetSystemDefaultLocaleName = GetProcAddress(v2, "GetSystemDefaultLocaleName");
    v3 = LoadLibraryW(L"Kernel32.dll");
    GetUserDefaultLocaleName = GetProcAddress(v3, "GetUserDefaultLocaleName");
  }
  sub_FEE360(pList);
  v4 = 0;
  v244 = 0;
  theDwordList = std::_List_alloc<std::_List_base_types<tagEventItem *,std::allocator<tagEventItem *>>>::_Buynode0(0, 0);
  v5 = 0;
  nStep = 0;
  _swprintf(szSectioName, L"Section%d", 0);
  szValue[0] = 0;
  memset(&szValue[1], 0, 0x206u);
  pszFileName = tagPEConfigFile::GetFileName(pConfigFile_1);
  if ( GetPrivateProfileStringW(L"Root", szSectioName, &gszNullString, szValue, 0x104u, pszFileName) )
  {
    do
    {
      bstrDisabled_1 = _wtoi(szValue);
      v7 = std::_List_buy<tagEventItem *,std::allocator<tagEventItem *>>::_Buynode<tagEventItem * const &>(
             theDwordList,
             theDwordList->_Mypair._Myval2._Mysize,
             &bstrDisabled_1);
      if ( (357913940 - v4) < 1 )
LABEL_10:
        std::_Xlength_error("list<T> too long");
      ++v5;
      ++v4;
      theDwordList->_Mypair._Myval2._Mysize = v7;
      v8 = v7[1];
      v244 = v4;
      *v8 = v7;
      _swprintf(szSectioName, L"Section%d", v5);
      szValue[0] = 0;
      memset(&szValue[1], 0, 0x206u);
      v9 = tagPEConfigFile::GetFileName(pConfigFile_1);
    }
    while ( GetPrivateProfileStringW(L"Root", szSectioName, &gszNullString, szValue, 0x104u, v9) );
  }
  dwIndex = 0;
  bstrTemp.m_Data = -1;
  while ( 1 )
  {
    szValue[0] = 0;
    memset(&szValue[1], 0, 0x206u);
    v10 = operator new(0xCu);
    v11 = v10;
    bstrDisabled.m_Data = v10;
    LOBYTE(nStep) = 1;
    if ( v10 )
    {
      v10->m_str = 0;
      v10->m_RefCount = 1;
      v12 = SysAllocString(L".disabled");
      v11->m_wstr = v12;
      if ( !v12 )
        goto LABEL_9;
    }
    else
    {
      v11 = 0;
    }
    LOBYTE(nStep) = 0;
    bstrDisabled_1 = v11;
    if ( !v11 )
LABEL_9:
      _com_issue_error(E_OUTOFMEMORY);
    LOBYTE(nStep) = 2;
    // _bstr_t bstrResult = bstrConfigFile + bstrDisabled;
    v13 = _bstr_t::operator+(pConfigFile_1, &bstrResult, &bstrDisabled_1);
    LOBYTE(nStep) = 3;
    v14 = MakeSectionName(&bstrSectionName, dwIndex);
    if ( *v13 )
      pszConfigFile = **v13;
    else
      pszConfigFile = 0;
    v16 = &v14->m_Data->m_wstr;
    if ( v16 )
      pszSectionName = *v16;
    else
      pszSectionName = 0;
    dwRet = GetPrivateProfileStringW(
              pszSectionName,
              L"PrivateSetting_GadgetName",
              &gszNullString,
              szValue,
              0x104u,
              pszConfigFile);
    v19 = bstrSectionName;
    v257 = dwRet == 0;
    if ( bstrSectionName )
    {
      if ( !InterlockedDecrement(&bstrSectionName->m_RefCount) && v19 )
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
      bstrSectionName = 0;
    }
    v20 = bstrResult;
    if ( bstrResult )
    {
      if ( !InterlockedDecrement(&bstrResult->m_RefCount) && v20 )
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
      bstrResult = 0;
    }
    LOBYTE(nStep) = 0;
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
    if ( v257 )
      break;
    v21 = bstrTemp.m_Data;
    bstrDisabled_1 = bstrTemp.m_Data;
    v22 = std::_List_buy<tagEventItem *,std::allocator<tagEventItem *>>::_Buynode<tagEventItem * const &>(
            theDwordList,
            theDwordList->_Mypair._Myval2._Mysize,
            &bstrDisabled_1);
    if ( (357913940 - v244) < 1 )
      goto LABEL_10;
    dwIndex = (dwIndex + 1);
    ++v244;
    bstrTemp.m_Data = (v21 - 1);
    theDwordList->_Mypair._Myval2._Mysize = v22;
    v22->_Prev->_Next = v22;
  }
  v23 = theDwordList->_Mypair._Myval2._Myhead;
  v245 = v23;
  if ( v23 != theDwordList )
  {
    while ( 1 )
    {
      StringItem.strValue[6] = 0;
      _mm_storeu_si128(&StringItem.strValue[2], 0i64);
      v233.m_Data = 0;
      v234.m_Data = 0;
      dwSectionID = v23[1]._Mypair._Myval2._Myhead;
      szValue[0] = 0;
      LOBYTE(nStep) = 4;
      nLinePosition = dwSectionID;
      StringItem.strValue[0] = dwSectionID;
      memset(&szValue[1], 0, 0x206u);
      if ( dwSectionID < 0 )
      {
        LOBYTE(StringItem.strValue[1]) = 0;
      }
      else
      {
        v25 = MakeSectionName(&bstrSectionName_1, dwSectionID);
        if ( v25->m_Data )
          v26 = v25->m_Data->m_wstr;
        else
          v26 = 0;
        v27 = tagPEConfigFile::GetFileName(pConfigFile_1);
        GetPrivateProfileStringW(v26, L"PrivateSetting_Enabled", &gszNullString, szValue, 0x104u, v27);
        v28 = bstrSectionName_1.m_Data;
        if ( bstrSectionName_1.m_Data )
        {
          if ( !InterlockedDecrement(&bstrSectionName_1.m_Data->m_RefCount) && v28 )
          {
            if ( v28->m_wstr )
            {
              SysFreeString(v28->m_wstr);
              v28->m_wstr = 0;
            }
            if ( v28->m_str )
            {
              j_j__free(v28->m_str);
              v28->m_str = 0;
            }
            j__free(v28);
          }
          bstrSectionName_1.m_Data = 0;
        }
        v29 = _wcsicmp(szValue, L"false");
        dwSectionID = nLinePosition;
        LOBYTE(StringItem.strValue[1]) = v29 != 0;
      }
      szValue[0] = 0;
      if ( dwSectionID < 0 )
      {
        v34 = operator new(0xCu);
        v35 = v34;
        pIXMLDOMParseError = v34;
        bstrReason = v34;
        LOBYTE(nStep) = 5;
        if ( v34 )
        {
          v34[1].lpVtbl = 0;
          v34[2].lpVtbl = 1;
          v36 = SysAllocString(L".disabled");
          v35->m_wstr = v36;
          if ( !v36 )
            goto LABEL_9;
        }
        else
        {
          v35 = 0;
          pIXMLDOMParseError = 0;
        }
        LOBYTE(nStep) = 4;
        bstrSourceText = v35;
        if ( !v35 )
          goto LABEL_9;
        LOBYTE(nStep) = 6;
        v37 = _bstr_t::operator+(pConfigFile_1, &v224, &bstrSourceText);
        LOBYTE(nStep) = 7;
        v38 = MakeSectionName(&v226, -1 - nLinePosition);
        if ( *v37 )
          v39 = **v37;
        else
          v39 = 0;
        v40 = &v38->m_Data->m_wstr;
        if ( v40 )
          v41 = *v40;
        else
          v41 = 0;
        GetPrivateProfileStringW(v41, L"PrivateSetting_GadgetName", &gszNullString, szValue, 0x104u, v39);
        v42 = v226;
        if ( v226 )
        {
          if ( !InterlockedDecrement(v226 + 2) && v42 )
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
          v226 = 0;
        }
        v43 = v224;
        if ( v224 )
        {
          if ( !InterlockedDecrement(v224 + 2) && v43 )
          {
            if ( *v43 )
            {
              SysFreeString(*v43);
              *v43 = 0;
            }
            if ( *(v43 + 1) )
            {
              j_j__free(*(v43 + 1));
              *(v43 + 1) = 0;
            }
            j__free(v43);
          }
          v224 = 0;
        }
        v44 = pIXMLDOMParseError;
        LOBYTE(nStep) = 4;
        if ( !InterlockedDecrement(&pIXMLDOMParseError[2]) )
        {
          if ( v44->lpVtbl )
          {
            SysFreeString(v44->lpVtbl);
            v44->lpVtbl = 0;
          }
          if ( v44[1].lpVtbl )
          {
            j_j__free(v44[1].lpVtbl);
            v44[1].lpVtbl = 0;
          }
          j__free(v44);
        }
      }
      else
      {
        v30 = MakeSectionName(&bstrSectionName_2, dwSectionID);
        if ( v30->m_Data )
          v31 = v30->m_Data->m_wstr;
        else
          v31 = 0;
        v32 = tagPEConfigFile::GetFileName(pConfigFile_1);
        GetPrivateProfileStringW(v31, L"PrivateSetting_GadgetName", &gszNullString, szValue, 0x104u, v32);
        v33 = bstrSectionName_2.m_Data;
        if ( bstrSectionName_2.m_Data )
        {
          if ( !InterlockedDecrement(&bstrSectionName_2.m_Data->m_RefCount) && v33 )
          {
            if ( v33->m_wstr )
            {
              SysFreeString(v33->m_wstr);
              v33->m_wstr = 0;
            }
            if ( v33->m_str )
            {
              j_j__free(v33->m_str);
              v33->m_str = 0;
            }
            j__free(v33);
          }
          bstrSectionName_2.m_Data = 0;
        }
      }
      pcchUnescaped = 260;
      UrlUnescapeW(szValue, 0, &pcchUnescaped, 0x100000u);
      if ( dword_10C4C68 & 1 )
      {
        v46 = IsWow64Process;
      }
      else
      {
        dword_10C4C68 |= 1u;
        v45 = GetModuleHandleW(L"kernel32");
        v46 = GetProcAddress(v45, "IsWow64Process");
        IsWow64Process = v46;
      }
      v218 = 0;
      if ( v46 )
      {
        v47 = GetCurrentProcess();
        if ( IsWow64Process(v47, &v218) )
        {
          if ( v218 )
          {
            v48 = wcsstr(szValue, L"%PROGRAMFILES%");
            if ( v48 )
            {
              v196 = *L"2";
              _mm_storeu_si128(&v194, _mm_loadu_si128(L"%ProgramW6432"));
              v195 = *L"W6432";
              memmove_0(v48, &v194, 2 * wcslen(&v194));
            }
          }
        }
      }
      v49 = *RequerySystemEnvironmentString(&ppstr, szValue);
      LOBYTE(nStep) = 8;
      _bstr_t::operator=(&StringItem.strValue[2], v49);
      free(ppstr);
      EventItem = 0;
      v50 = 0;
      v250 = 0;
      LOBYTE(nStep) = 10;
      if ( !GetUserDefaultLocaleName(szLocalName, 260) )
        goto LABEL_532;
      v51 = operator new(0xCu);
      pIXMLDOMParseError = v51;
      bstrReason = v51;
      LOBYTE(nStep) = 11;
      if ( v51 )
      {
        v51[1].lpVtbl = 0;
        v51[2].lpVtbl = 1;
        v52 = SysAllocString(L"\\Gadget.xml");
        v53 = pIXMLDOMParseError;
        pIXMLDOMParseError->lpVtbl = v52;
        if ( !v52 )
          goto LABEL_9;
        v54 = v53;
      }
      else
      {
        v54 = 0;
        pIXMLDOMParseError = 0;
      }
      LOBYTE(nStep) = 10;
      bstrReason = v54;
      if ( !v54 )
        goto LABEL_9;
      LOBYTE(nStep) = 12;
      v55 = operator new(0xCu);
      nNumberOfBytesToRead = v55;
      nLineNumber = v55;
      LOBYTE(nStep) = 13;
      if ( v55 )
      {
        v55->m_str = 0;
        v55->m_RefCount = 1;
        v56 = SysAllocString(szLocalName);
        v57 = nNumberOfBytesToRead;
        nNumberOfBytesToRead->m_wstr = v56;
        if ( !v56 )
          goto LABEL_9;
        v58 = v57;
      }
      else
      {
        v58 = 0;
        nNumberOfBytesToRead = 0;
      }
      LOBYTE(nStep) = 12;
      nLineNumber = v58;
      if ( !v58 )
        goto LABEL_9;
      LOBYTE(nStep) = 14;
      v59 = operator new(0xCu);
      bstrSourceText = v59;
      nLinePosition = v59;
      LOBYTE(nStep) = 15;
      if ( v59 )
      {
        v59->m_str = 0;
        v59->m_RefCount = 1;
        v60 = SysAllocString(L"\\");
        v61 = bstrSourceText;
        bstrSourceText->m_wstr = v60;
        if ( !v60 )
          goto LABEL_9;
        v62 = v61;
      }
      else
      {
        v62 = 0;
        bstrSourceText = 0;
      }
      LOBYTE(nStep) = 14;
      nLinePosition = v62;
      if ( !v62 )
        goto LABEL_9;
      LOBYTE(nStep) = 16;
      v63 = _bstr_t::operator+(&StringItem.strValue[2], &v212, &nLinePosition);
      LOBYTE(nStep) = 17;
      v64 = _bstr_t::operator+(v63, &v214, &nLineNumber);
      LOBYTE(nStep) = 18;
      v65 = _bstr_t::operator+(v64, &v216, &bstrReason);
      if ( &v250 != v65 )
      {
        v50 = v65->m_Data;
        v250 = v50;
        if ( v50 )
          InterlockedIncrement(&v50->m_RefCount);
      }
      nLinePosition = v216;
      if ( v216 )
      {
        if ( !InterlockedDecrement(v216 + 2) )
        {
          v66 = nLinePosition;
          if ( nLinePosition )
          {
            if ( *nLinePosition )
            {
              SysFreeString(*nLinePosition);
              v66 = nLinePosition;
              *nLinePosition = 0;
            }
            if ( v66[1] )
            {
              j_j__free(v66[1]);
              v66 = nLinePosition;
              *(nLinePosition + 1) = 0;
            }
            j__free(v66);
          }
        }
        v216 = 0;
      }
      nLinePosition = v214;
      if ( v214 )
      {
        if ( !InterlockedDecrement(v214 + 2) )
        {
          v67 = nLinePosition;
          if ( nLinePosition )
          {
            if ( *nLinePosition )
            {
              SysFreeString(*nLinePosition);
              v67 = nLinePosition;
              *nLinePosition = 0;
            }
            if ( v67[1] )
            {
              j_j__free(v67[1]);
              v67 = nLinePosition;
              *(nLinePosition + 1) = 0;
            }
            j__free(v67);
          }
        }
        v214 = 0;
      }
      nLinePosition = v212;
      if ( v212 )
      {
        if ( !InterlockedDecrement(v212 + 2) )
        {
          v68 = nLinePosition;
          if ( nLinePosition )
          {
            if ( *nLinePosition )
            {
              SysFreeString(*nLinePosition);
              v68 = nLinePosition;
              *nLinePosition = 0;
            }
            if ( v68[1] )
            {
              j_j__free(v68[1]);
              v68 = nLinePosition;
              *(nLinePosition + 1) = 0;
            }
            j__free(v68);
          }
        }
        v212 = 0;
      }
      if ( !InterlockedDecrement(&bstrSourceText->m_RefCount) )
      {
        v69 = bstrSourceText;
        if ( bstrSourceText->m_wstr )
        {
          SysFreeString(bstrSourceText->m_wstr);
          v69 = bstrSourceText;
          bstrSourceText->m_wstr = 0;
        }
        if ( v69->m_str )
        {
          j_j__free(v69->m_str);
          v69 = bstrSourceText;
          bstrSourceText->m_str = 0;
        }
        j__free(v69);
      }
      if ( !InterlockedDecrement(&nNumberOfBytesToRead->m_RefCount) )
      {
        v70 = nNumberOfBytesToRead;
        if ( nNumberOfBytesToRead->m_wstr )
        {
          SysFreeString(nNumberOfBytesToRead->m_wstr);
          v70 = nNumberOfBytesToRead;
          nNumberOfBytesToRead->m_wstr = 0;
        }
        if ( v70->m_str )
        {
          j_j__free(v70->m_str);
          v70 = nNumberOfBytesToRead;
          nNumberOfBytesToRead->m_str = 0;
        }
        j__free(v70);
      }
      LOBYTE(nStep) = 10;
      if ( !InterlockedDecrement(&pIXMLDOMParseError[2]) )
      {
        v71 = pIXMLDOMParseError;
        if ( pIXMLDOMParseError->lpVtbl )
        {
          SysFreeString(pIXMLDOMParseError->lpVtbl);
          v71 = pIXMLDOMParseError;
          pIXMLDOMParseError->lpVtbl = 0;
        }
        if ( v71[1].lpVtbl )
        {
          j_j__free(v71[1].lpVtbl);
          v71 = pIXMLDOMParseError;
          pIXMLDOMParseError[1].lpVtbl = 0;
        }
        j__free(v71);
      }
      v72 = v50 ? v50->m_wstr : 0;
      v73 = PE_OpenFile(v72, 0x80000000, 1u, 0, 3u, 0, 0);
      nLinePosition = v73;
      if ( v73 == -1 )
      {
LABEL_532:
        if ( !GetSystemDefaultLocaleName(szLocalName, 260) )
          goto LABEL_533;
        v74 = operator new(0xCu);
        nNumberOfBytesToRead = v74;
        bstrReason = v74;
        LOBYTE(nStep) = 19;
        if ( v74 )
        {
          v74->m_str = 0;
          v74->m_RefCount = 1;
          v75 = SysAllocString(L"\\Gadget.xml");
          v76 = nNumberOfBytesToRead;
          nNumberOfBytesToRead->m_wstr = v75;
          if ( !v75 )
            goto LABEL_9;
          v77 = v76;
        }
        else
        {
          v77 = 0;
          nNumberOfBytesToRead = 0;
        }
        LOBYTE(nStep) = 10;
        nLinePosition = v77;
        if ( !v77 )
          goto LABEL_9;
        LOBYTE(nStep) = 20;
        v78 = operator new(0xCu);
        bstrSourceText = v78;
        bstrReason = v78;
        LOBYTE(nStep) = 21;
        if ( v78 )
        {
          v78->m_str = 0;
          v78->m_RefCount = 1;
          v79 = SysAllocString(szLocalName);
          v80 = bstrSourceText;
          bstrSourceText->m_wstr = v79;
          if ( !v79 )
            goto LABEL_9;
          v81 = v80;
        }
        else
        {
          v81 = 0;
          bstrSourceText = 0;
        }
        LOBYTE(nStep) = 20;
        nLineNumber = v81;
        if ( !v81 )
          goto LABEL_9;
        LOBYTE(nStep) = 22;
        v82 = operator new(0xCu);
        pIXMLDOMParseError = v82;
        bstrReason = v82;
        LOBYTE(nStep) = 23;
        if ( v82 )
        {
          v82->m_str = 0;
          v82->m_RefCount = 1;
          v83 = SysAllocString(L"\\");
          v84 = pIXMLDOMParseError;
          pIXMLDOMParseError->lpVtbl = v83;
          if ( !v83 )
            goto LABEL_9;
          v85 = v84;
        }
        else
        {
          v85 = 0;
          pIXMLDOMParseError = 0;
        }
        LOBYTE(nStep) = 22;
        bstrReason = v85;
        if ( !v85 )
          goto LABEL_9;
        LOBYTE(nStep) = 24;
        v86 = _bstr_t::operator+(&StringItem.strValue[2], &v229, &bstrReason);
        LOBYTE(nStep) = 25;
        v87 = _bstr_t::operator+(v86, &v222, &nLineNumber);
        LOBYTE(nStep) = 26;
        v88 = _bstr_t::operator+(v87, &v227, &nLinePosition);
        nLinePosition = v88;
        if ( &v250 != v88 )
        {
          if ( v50 )
          {
            if ( !InterlockedDecrement(&v50->m_RefCount) )
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
            v88 = nLinePosition;
          }
          v50 = v88->m_Data;
          v250 = v50;
          if ( v50 )
            InterlockedIncrement(&v50->m_RefCount);
        }
        nLinePosition = v227;
        if ( v227 )
        {
          if ( !InterlockedDecrement(&v227->m_RefCount) )
          {
            v89 = nLinePosition;
            if ( nLinePosition )
            {
              if ( *nLinePosition )
              {
                SysFreeString(*nLinePosition);
                v89 = nLinePosition;
                *nLinePosition = 0;
              }
              if ( v89[1] )
              {
                j_j__free(v89[1]);
                v89 = nLinePosition;
                *(nLinePosition + 1) = 0;
              }
              j__free(v89);
            }
          }
          v227 = 0;
        }
        nLinePosition = v222;
        if ( v222 )
        {
          if ( !InterlockedDecrement(&v222->m_RefCount) )
          {
            v90 = nLinePosition;
            if ( nLinePosition )
            {
              if ( *nLinePosition )
              {
                SysFreeString(*nLinePosition);
                v90 = nLinePosition;
                *nLinePosition = 0;
              }
              if ( v90[1] )
              {
                j_j__free(v90[1]);
                v90 = nLinePosition;
                *(nLinePosition + 1) = 0;
              }
              j__free(v90);
            }
          }
          v222 = 0;
        }
        nLinePosition = v229;
        if ( v229 )
        {
          if ( !InterlockedDecrement(&v229->m_RefCount) )
          {
            v91 = nLinePosition;
            if ( nLinePosition )
            {
              if ( *nLinePosition )
              {
                SysFreeString(*nLinePosition);
                v91 = nLinePosition;
                *nLinePosition = 0;
              }
              if ( v91[1] )
              {
                j_j__free(v91[1]);
                v91 = nLinePosition;
                *(nLinePosition + 1) = 0;
              }
              j__free(v91);
            }
          }
          v229 = 0;
        }
        if ( !InterlockedDecrement(&pIXMLDOMParseError[2]) )
        {
          v92 = pIXMLDOMParseError;
          if ( pIXMLDOMParseError->lpVtbl )
          {
            SysFreeString(pIXMLDOMParseError->lpVtbl);
            v92 = pIXMLDOMParseError;
            pIXMLDOMParseError->lpVtbl = 0;
          }
          if ( v92[1].lpVtbl )
          {
            j_j__free(v92[1].lpVtbl);
            v92 = pIXMLDOMParseError;
            pIXMLDOMParseError[1].lpVtbl = 0;
          }
          j__free(v92);
        }
        if ( !InterlockedDecrement(&bstrSourceText->m_RefCount) )
        {
          v93 = bstrSourceText;
          if ( bstrSourceText->m_wstr )
          {
            SysFreeString(bstrSourceText->m_wstr);
            v93 = bstrSourceText;
            bstrSourceText->m_wstr = 0;
          }
          if ( v93->m_str )
          {
            j_j__free(v93->m_str);
            v93 = bstrSourceText;
            bstrSourceText->m_str = 0;
          }
          j__free(v93);
        }
        LOBYTE(nStep) = 10;
        if ( !InterlockedDecrement(&nNumberOfBytesToRead->m_RefCount) )
        {
          if ( nNumberOfBytesToRead->m_wstr )
          {
            SysFreeString(nNumberOfBytesToRead->m_wstr);
            v94 = nNumberOfBytesToRead;
            nNumberOfBytesToRead->m_wstr = 0;
          }
          else
          {
            v94 = nNumberOfBytesToRead;
          }
          v95 = v94->m_str;
          if ( v95 )
          {
            j_j__free(v95);
            v96 = nNumberOfBytesToRead;
            nNumberOfBytesToRead->m_str = 0;
          }
          else
          {
            v96 = nNumberOfBytesToRead;
          }
          j__free(v96);
        }
        v97 = v50 ? v50->m_wstr : 0;
        v73 = PE_OpenFile(v97, 0x80000000, 1u, 0, 3u, 0, 0);
        nLinePosition = v73;
        if ( v73 == -1 )
        {
LABEL_533:
          v98 = operator new(0xCu);
          pIXMLDOMParseError = v98;
          bstrReason = v98;
          LOBYTE(nStep) = 27;
          if ( v98 )
          {
            v98->m_str = 0;
            v98->m_RefCount = 1;
            v99 = SysAllocString(L"\\en-us\\Gadget.xml");
            v100 = pIXMLDOMParseError;
            pIXMLDOMParseError->lpVtbl = v99;
            if ( !v99 )
              goto LABEL_9;
            v101 = v100;
          }
          else
          {
            v101 = 0;
            pIXMLDOMParseError = 0;
          }
          LOBYTE(nStep) = 10;
          bstrReason = v101;
          if ( !v101 )
            goto LABEL_9;
          LOBYTE(nStep) = 28;
          v102 = _bstr_t::operator+(&StringItem.strValue[2], &v225, &bstrReason);
          nLinePosition = v102;
          if ( &v250 != v102 )
          {
            if ( v50 )
            {
              if ( !InterlockedDecrement(&v50->m_RefCount) )
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
              v102 = nLinePosition;
            }
            v50 = v102->m_Data;
            v250 = v50;
            if ( v50 )
              InterlockedIncrement(&v50->m_RefCount);
          }
          nLinePosition = v225;
          if ( v225 )
          {
            if ( !InterlockedDecrement(&v225->m_RefCount) )
            {
              v103 = nLinePosition;
              if ( nLinePosition )
              {
                if ( *nLinePosition )
                {
                  SysFreeString(*nLinePosition);
                  v103 = nLinePosition;
                  *nLinePosition = 0;
                }
                if ( v103[1] )
                {
                  j_j__free(v103[1]);
                  v103 = nLinePosition;
                  *(nLinePosition + 1) = 0;
                }
                j__free(v103);
              }
            }
            v225 = 0;
          }
          LOBYTE(nStep) = 10;
          if ( !InterlockedDecrement(&pIXMLDOMParseError[2]) )
          {
            v104 = pIXMLDOMParseError;
            if ( pIXMLDOMParseError->lpVtbl )
            {
              SysFreeString(pIXMLDOMParseError->lpVtbl);
              v104 = pIXMLDOMParseError;
              pIXMLDOMParseError->lpVtbl = 0;
            }
            if ( v104[1].lpVtbl )
            {
              j_j__free(v104[1].lpVtbl);
              v104 = pIXMLDOMParseError;
              pIXMLDOMParseError[1].lpVtbl = 0;
            }
            j__free(v104);
          }
          v105 = v50 ? v50->m_wstr : 0;
          v73 = PE_OpenFile(v105, 0x80000000, 1u, 0, 3u, 0, 0);
          nLinePosition = v73;
          if ( v73 == -1 )
          {
            v106 = operator new(0xCu);
            pIXMLDOMParseError = v106;
            bstrReason = v106;
            LOBYTE(nStep) = 29;
            if ( v106 )
            {
              v106->m_str = 0;
              v106->m_RefCount = 1;
              v107 = SysAllocString(L"\\Gadget.xml");
              v108 = pIXMLDOMParseError;
              pIXMLDOMParseError->lpVtbl = v107;
              if ( !v107 )
                goto LABEL_9;
              v109 = v108;
            }
            else
            {
              v109 = 0;
              pIXMLDOMParseError = 0;
            }
            LOBYTE(nStep) = 10;
            bstrReason = v109;
            if ( !v109 )
              goto LABEL_9;
            LOBYTE(nStep) = 30;
            v110 = _bstr_t::operator+(&StringItem.strValue[2], &v215, &bstrReason);
            nLinePosition = v110;
            if ( &v250 != v110 )
            {
              if ( v50 )
              {
                if ( !InterlockedDecrement(&v50->m_RefCount) )
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
                v110 = nLinePosition;
              }
              v50 = v110->m_Data;
              v250 = v50;
              if ( v50 )
                InterlockedIncrement(&v50->m_RefCount);
            }
            nLinePosition = v215;
            if ( v215 )
            {
              if ( !InterlockedDecrement(&v215->m_RefCount) )
              {
                v111 = nLinePosition;
                if ( nLinePosition )
                {
                  if ( *nLinePosition )
                  {
                    SysFreeString(*nLinePosition);
                    v111 = nLinePosition;
                    *nLinePosition = 0;
                  }
                  if ( v111[1] )
                  {
                    j_j__free(v111[1]);
                    v111 = nLinePosition;
                    *(nLinePosition + 1) = 0;
                  }
                  j__free(v111);
                }
              }
              v215 = 0;
            }
            LOBYTE(nStep) = 10;
            if ( !InterlockedDecrement(&pIXMLDOMParseError[2]) )
            {
              v112 = pIXMLDOMParseError;
              if ( pIXMLDOMParseError->lpVtbl )
              {
                SysFreeString(pIXMLDOMParseError->lpVtbl);
                v112 = pIXMLDOMParseError;
                pIXMLDOMParseError->lpVtbl = 0;
              }
              if ( v112[1].lpVtbl )
              {
                j_j__free(v112[1].lpVtbl);
                v112 = pIXMLDOMParseError;
                pIXMLDOMParseError[1].lpVtbl = 0;
              }
              j__free(v112);
            }
            v113 = v50 ? v50->m_wstr : 0;
            v73 = PE_OpenFile(v113, 0x80000000, 1u, 0, 3u, 0, 0);
            nLinePosition = v73;
            if ( v73 == -1 )
            {
              _bstr_t::operator=(&EventItem, &gszNullString);
              if ( StringItem.strValue[3] && !InterlockedDecrement((StringItem.strValue[3] + 8)) )
              {
                v114 = StringItem.strValue[3];
                if ( *StringItem.strValue[3] )
                {
                  SysFreeString(*StringItem.strValue[3]);
                  v114 = StringItem.strValue[3];
                  *StringItem.strValue[3] = 0;
                }
                if ( v114[1] )
                {
                  j_j__free(v114[1]);
                  v114 = StringItem.strValue[3];
                  *(StringItem.strValue[3] + 4) = 0;
                }
                j__free(v114);
              }
              StringItem.strValue[3] = StringItem.strValue[2];
              if ( StringItem.strValue[2] )
              {
                v115 = (StringItem.strValue[2] + 8);
LABEL_367:
                InterlockedIncrement(v115);
                goto LABEL_368;
              }
              goto LABEL_368;
            }
          }
        }
      }
      nNumberOfBytesToRead = GetFileSize(v73, 0);
      pIXMLDOMParseError = operator new[](nNumberOfBytesToRead);
      bstrSourceText = operator new[](2 * (nNumberOfBytesToRead + 1));
      NumberOfBytesRead = 0;
      ReadFile(nLinePosition, pIXMLDOMParseError, nNumberOfBytesToRead, &NumberOfBytesRead, 0);
      if ( NumberOfBytesRead >= 3
        && LOBYTE(pIXMLDOMParseError->lpVtbl) == 0357u
        && BYTE1(pIXMLDOMParseError->lpVtbl) == 0xBBu
        && BYTE2(pIXMLDOMParseError->lpVtbl) == 0xBFu )
      {
        break;
      }
      if ( NumberOfBytesRead < 2 || LOBYTE(pIXMLDOMParseError->lpVtbl) != -1 || BYTE1(pIXMLDOMParseError->lpVtbl) != -2 )
      {
        v116 = MultiByteToWideChar(0, 0, pIXMLDOMParseError, nNumberOfBytesToRead, bstrSourceText, nNumberOfBytesToRead);
        goto LABEL_357;
      }
      v117 = 1;
      v118 = (nNumberOfBytesToRead >> 1);
      nNumberOfBytesToRead = v118;
      if ( v118 > 1 )
      {
        v119 = bstrSourceText;
        v120 = v118;
        v121 = pIXMLDOMParseError;
        do
        {
          v122 = *(&v121->lpVtbl + v117);
          v119 = (v119 + 2);
          ++v117;
          HIWORD(v119[-1].m_RefCount) = v122;
        }
        while ( v117 < v120 );
        v50 = v250;
        v23 = v245;
        v118 = nNumberOfBytesToRead;
      }
      *(bstrSourceText + v118 - 1) = 0;
LABEL_358:
      _bstr_t::operator=(&EventItem, bstrSourceText);
      j_j__free(bstrSourceText);
      j_j__free(pIXMLDOMParseError);
      CloseHandle(nLinePosition);
      if ( StringItem.strValue[3] && !InterlockedDecrement((StringItem.strValue[3] + 8)) )
      {
        v123 = StringItem.strValue[3];
        if ( *StringItem.strValue[3] )
        {
          SysFreeString(*StringItem.strValue[3]);
          v123 = StringItem.strValue[3];
          *StringItem.strValue[3] = 0;
        }
        if ( v123[1] )
        {
          j_j__free(v123[1]);
          v123 = StringItem.strValue[3];
          *(StringItem.strValue[3] + 4) = 0;
        }
        j__free(v123);
      }
      StringItem.strValue[3] = v50;
      if ( v50 )
      {
        v115 = &v50->m_RefCount;
        goto LABEL_367;
      }
LABEL_368:
      LOBYTE(nStep) = 9;
      if ( v50 && !InterlockedDecrement(&v50->m_RefCount) )
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
      v124 = EventItem;
      while ( 1 )
      {
        v125 = v124 ? v124->m_wstr : 0;
        if ( wcsncmp(v125, L"<!--", 4u) )
          break;
        v126 = v124 ? v124->m_wstr : 0;
        v127 = wcsstr(v126, L"-->");
        if ( !v127 )
          break;
        v128 = v127[3];
        nLinePosition = v127 + 3;
        if ( iswspace(v128) )
        {
          v129 = nLinePosition;
          do
          {
            v130 = v129[1];
            ++v129;
          }
          while ( iswspace(v130) );
          nLinePosition = v129;
          v23 = v245;
        }
        v131 = operator new(0xCu);
        nNumberOfBytesToRead = v131;
        bstrReason = v131;
        LOBYTE(nStep) = 31;
        if ( v131 )
        {
          v132 = nLinePosition;
          v131->m_str = 0;
          v131->m_RefCount = 1;
          v133 = SysAllocString(v132);
          v134 = nNumberOfBytesToRead;
          nNumberOfBytesToRead->m_wstr = v133;
          if ( !v133 )
            goto LABEL_9;
          v135 = v134;
        }
        else
        {
          v135 = 0;
          nNumberOfBytesToRead = 0;
        }
        LOBYTE(nStep) = 9;
        if ( !v135 )
          goto LABEL_9;
        if ( v124 )
        {
          if ( !InterlockedDecrement(&v124->m_RefCount) )
          {
            if ( v124->m_wstr )
            {
              SysFreeString(v124->m_wstr);
              v124->m_wstr = 0;
            }
            if ( v124->m_str )
            {
              j_j__free(v124->m_str);
              v124->m_str = 0;
            }
            j__free(v124);
          }
          v135 = nNumberOfBytesToRead;
        }
        v124 = v135;
        EventItem = v135;
        InterlockedIncrement(&v135->m_RefCount);
        if ( !InterlockedDecrement(&nNumberOfBytesToRead->m_RefCount) )
        {
          v136 = nNumberOfBytesToRead;
          if ( nNumberOfBytesToRead->m_wstr )
          {
            SysFreeString(nNumberOfBytesToRead->m_wstr);
            v136 = nNumberOfBytesToRead;
            nNumberOfBytesToRead->m_wstr = 0;
          }
          if ( v136->m_str )
          {
            j_j__free(v136->m_str);
            v136 = nNumberOfBytesToRead;
            nNumberOfBytesToRead->m_str = 0;
          }
          j__free(v136);
        }
      }
      CoInitializeEx(0, 0);
      pIXMLDOMDocument = 0;
      if ( ::Wow64EnableWow64FsRedirection )
      {
        ::Wow64EnableWow64FsRedirection(1u);
        TlsSetValue(gdwTlsIndex, 0x200);
      }
      hResult = CoCreateInstance(&CLSID_XMLDOMDocument, 0, 1u, &CLSID_IXMLDOMDocument, &pIXMLDOMDocument);
      Wow64EnableWow64FsRedirection = ::Wow64EnableWow64FsRedirection;
      bstrReason = hResult;
      if ( ::Wow64EnableWow64FsRedirection )
      {
        ::Wow64EnableWow64FsRedirection(0);
        TlsSetValue(gdwTlsIndex, 0x100);
        Wow64EnableWow64FsRedirection = ::Wow64EnableWow64FsRedirection;
        hResult = bstrReason;
      }
      if ( !hResult )
      {
        vtFlags = 0;
        if ( Wow64EnableWow64FsRedirection )
        {
          Wow64EnableWow64FsRedirection(1);
          TlsSetValue(gdwTlsIndex, 0x200);
        }
        if ( v124 )
          v139 = v124->m_wstr;
        else
          v139 = 0;
        pIXMLDOMDocument->lpVtbl->loadXML(pIXMLDOMDocument, v139, &vtFlags);
        v23 = v245;
        if ( ::Wow64EnableWow64FsRedirection )
        {
          ::Wow64EnableWow64FsRedirection(0);
          TlsSetValue(gdwTlsIndex, 0x100);
        }
        if ( vtFlags )
          goto LABEL_531;
        pIXMLDOMParseError = 0;
        pIXMLDOMDocument->lpVtbl->get_parseError(pIXMLDOMDocument, &pIXMLDOMParseError);
        if ( pIXMLDOMParseError )
        {
          bstrReason = 0;
          nLineNumber = -1;
          nLinePosition = -1;
          bstrSourceText = 0;
          pIXMLDOMParseError->lpVtbl->get_reason(pIXMLDOMParseError, &bstrReason);
          pIXMLDOMParseError->lpVtbl->get_line(pIXMLDOMParseError, &nLineNumber);
          pIXMLDOMParseError->lpVtbl->get_linepos(pIXMLDOMParseError, &nLinePosition);
          pIXMLDOMParseError->lpVtbl->get_srcText(pIXMLDOMParseError, &bstrSourceText);
          pIXMLDOMParseError->lpVtbl->Release(pIXMLDOMParseError);
        }
        if ( vtFlags )
        {
LABEL_531:
          v140 = operator new(0xCu);
          pIXMLDOMParseError = v140;
          bstrReason = v140;
          LOBYTE(nStep) = 32;
          if ( v140 )
          {
            v140->m_str = 0;
            v140->m_RefCount = 1;
            v141 = _com_util::ConvertStringToBSTR("gadget");
            v142 = pIXMLDOMParseError;
            pIXMLDOMParseError->lpVtbl = v141;
          }
          else
          {
            v142 = 0;
            pIXMLDOMParseError = 0;
          }
          LOBYTE(nStep) = 9;
          bstrReason = v142;
          if ( !v142 )
            goto LABEL_9;
          bstrQuery = v142->lpVtbl;
          LOBYTE(nStep) = 33;
          hresult = pIXMLDOMDocument->lpVtbl->selectSingleNode(pIXMLDOMDocument, bstrQuery, &pIXMLDOMNode);
          LOBYTE(nStep) = 9;
          v257 = hresult == 0;
          v145 = InterlockedDecrement(&pIXMLDOMParseError[2]);
          v124 = EventItem;
          if ( !v145 )
          {
            v146 = pIXMLDOMParseError;
            if ( pIXMLDOMParseError->lpVtbl )
            {
              SysFreeString(pIXMLDOMParseError->lpVtbl);
              v146 = pIXMLDOMParseError;
              pIXMLDOMParseError->lpVtbl = 0;
            }
            if ( v146[1].lpVtbl )
            {
              j_j__free(v146[1].lpVtbl);
              v146 = pIXMLDOMParseError;
              pIXMLDOMParseError[1].lpVtbl = 0;
            }
            j__free(v146);
          }
          if ( v257 )
          {
            v147 = operator new(0xCu);
            pIXMLDOMParseError = v147;
            bstrReason = v147;
            LOBYTE(nStep) = 34;
            if ( v147 )
            {
              v147->m_str = 0;
              v147->m_RefCount = 1;
              v148 = _com_util::ConvertStringToBSTR("name");
              v149 = pIXMLDOMParseError;
              pIXMLDOMParseError->lpVtbl = v148;
            }
            else
            {
              v149 = 0;
              pIXMLDOMParseError = 0;
            }
            LOBYTE(nStep) = 9;
            bstrReason = v149;
            if ( !v149 )
              goto LABEL_9;
            bstrQueryText = v149->lpVtbl;
            LOBYTE(nStep) = 35;
            v151 = pIXMLDOMNode->lpVtbl->selectSingleNode(pIXMLDOMNode, bstrQueryText, &pIXMLDOMNode2);
            LOBYTE(nStep) = 9;
            v257 = v151 == 0;
            if ( !InterlockedDecrement(&pIXMLDOMParseError[2]) )
            {
              v152 = pIXMLDOMParseError;
              if ( pIXMLDOMParseError->lpVtbl )
              {
                SysFreeString(pIXMLDOMParseError->lpVtbl);
                v152 = pIXMLDOMParseError;
                pIXMLDOMParseError->lpVtbl = 0;
              }
              if ( v152[1].lpVtbl )
              {
                j_j__free(v152[1].lpVtbl);
                v152 = pIXMLDOMParseError;
                pIXMLDOMParseError[1].lpVtbl = 0;
              }
              j__free(v152);
            }
            if ( v257 )
            {
              bstr_t::Assign(&StringItem.strValue[4], 0);
              pIXMLDOMNode2->lpVtbl->get_text(pIXMLDOMNode2, StringItem.strValue[4]);
              pIXMLDOMNode2->lpVtbl->Release(pIXMLDOMNode2);
            }
            v153 = _bstr_t::_bstr_t(&v210, "description")->m_Data;
            LOBYTE(nStep) = 36;
            if ( v153 )
              v154 = v153->m_wstr;
            else
              v154 = 0;
            v155 = pIXMLDOMNode->lpVtbl->selectSingleNode(pIXMLDOMNode, v154, &pIXMLDOMNode2);
            LOBYTE(nStep) = 9;
            v257 = v155 == 0;
            _bstr_t::_Free(&v210);
            if ( v257 )
            {
              VariantInit(&pvarg);
              LOBYTE(nStep) = 37;
              pIXMLDOMNode2->lpVtbl->get_nodeValue(pIXMLDOMNode2, &pvarg);
              bstr_t::Assign(&StringItem.strValue[6], 0);
              pIXMLDOMNode2->lpVtbl->get_text(pIXMLDOMNode2, StringItem.strValue[6]);
              pIXMLDOMNode2->lpVtbl->Release(pIXMLDOMNode2);
              LOBYTE(nStep) = 9;
              VariantClear(&pvarg);
            }
            v156 = _bstr_t::_bstr_t(&v202, "author")->m_Data;
            LOBYTE(nStep) = 38;
            if ( v156 )
              v157 = v156->m_wstr;
            else
              v157 = 0;
            v158 = pIXMLDOMNode->lpVtbl->selectSingleNode(pIXMLDOMNode, v157, &pIXMLDOMNode2);
            LOBYTE(nStep) = 9;
            v257 = v158 == 0;
            _bstr_t::_Free(&v202);
            if ( v257 )
            {
              if ( !pIXMLDOMNode2->lpVtbl->get_attributes(pIXMLDOMNode2, &pIXMLDOMNamedNodeMap) )
              {
                v159 = _bstr_t::_bstr_t(&v200, "name")->m_Data;
                LOBYTE(nStep) = 39;
                if ( v159 )
                  bstrName = v159->m_wstr;
                else
                  bstrName = 0;
                v161 = pIXMLDOMNamedNodeMap->lpVtbl->getNamedItem(pIXMLDOMNamedNodeMap, bstrName, &pIXMLDOMNode3);
                LOBYTE(nStep) = 9;
                v257 = v161 == 0;
                _bstr_t::_Free(&v200);
                if ( v257 )
                {
                  bstr_t::Assign(&StringItem.strValue[5], 0);
                  pIXMLDOMNode3->lpVtbl->get_text(pIXMLDOMNode3, StringItem.strValue[5]);
                  pIXMLDOMNode3->lpVtbl->Release(pIXMLDOMNode3);
                }
                pIXMLDOMNamedNodeMap->lpVtbl->Release(pIXMLDOMNamedNodeMap);
              }
              pIXMLDOMNode2->lpVtbl->Release(pIXMLDOMNode2);
            }
            v162 = _bstr_t::_bstr_t(&v211, "version")->m_Data;
            LOBYTE(nStep) = 40;
            if ( v162 )
              v163 = v162->m_wstr;
            else
              v163 = 0;
            v164 = pIXMLDOMNode->lpVtbl->selectSingleNode(pIXMLDOMNode, v163, &pIXMLDOMNode2);
            LOBYTE(nStep) = 9;
            v257 = v164 == 0;
            _bstr_t::_Free(&v211);
            v23 = v245;
            if ( v257 )
            {
              bstr_t::Assign(&v233, 0);
              pIXMLDOMNode2->lpVtbl->get_text(pIXMLDOMNode2, v233.m_Data);
              pIXMLDOMNode2->lpVtbl->Release(pIXMLDOMNode2);
            }
            v165 = _bstr_t::_bstr_t(&v205, "icons")->m_Data;
            LOBYTE(nStep) = 41;
            if ( v165 )
              v166 = v165->m_wstr;
            else
              v166 = 0;
            v167 = pIXMLDOMNode->lpVtbl->selectSingleNode(pIXMLDOMNode, v166, &pIXMLDOMNode2);
            LOBYTE(nStep) = 9;
            v257 = v167 == 0;
            _bstr_t::_Free(&v205);
            v124 = EventItem;
            if ( v257 )
            {
              if ( !pIXMLDOMNode2->lpVtbl->get_childNodes(pIXMLDOMNode2, &bstrSectionName) )
              {
                bstrReason = 4096;
                if ( !(*(bstrSectionName->m_wstr + 9))(bstrSectionName, &bstrResult) )
                {
                  v168 = bstrReason;
                  do
                  {
                    if ( !(*(bstrResult->m_wstr + 17))(bstrResult, &dwIndex) )
                    {
                      VariantInit(&pvarSrc);
                      LOBYTE(nStep) = 42;
                      v169 = _bstr_t::_bstr_t(&v209, "height")->m_Data;
                      LOBYTE(nStep) = 43;
                      if ( v169 )
                        v170 = v169->m_wstr;
                      else
                        v170 = 0;
                      v171 = dwIndex->lpVtbl->getNamedItem(dwIndex, v170, &v246);
                      LOBYTE(nStep) = 42;
                      v257 = v171 == 0;
                      _bstr_t::_Free(&v209);
                      if ( v257 )
                      {
                        (*(*v246 + 32))(v246, &pvarSrc);
                        v172 = _bstr_t::_bstr_t(&v199, &pvarSrc)->strEventTrace.m_Data;
                        if ( v172 )
                          v173 = v172->m_wstr;
                        else
                          v173 = 0;
                        v235 = _wtoi(v173);
                        _bstr_t::_Free(&v199);
                        (*(*v246 + 8))(v246);
                      }
                      v174 = _bstr_t::_bstr_t(&v207, "width")->m_Data;
                      LOBYTE(nStep) = 44;
                      if ( v174 )
                        v175 = v174->m_wstr;
                      else
                        v175 = 0;
                      v176 = dwIndex->lpVtbl->getNamedItem(dwIndex, v175, &v246);
                      LOBYTE(nStep) = 42;
                      v257 = v176 == 0;
                      _bstr_t::_Free(&v207);
                      v177 = v235;
                      if ( v257 )
                      {
                        (*(*v246 + 32))(v246, &pvarSrc);
                        v178 = _bstr_t::_bstr_t(&v206, &pvarSrc)->strEventTrace.m_Data;
                        if ( v178 )
                          v179 = v178->m_wstr;
                        else
                          v179 = 0;
                        bstrDisabled_1 = _wtoi(v179);
                        _bstr_t::_Free(&v206);
                        (*(*v246 + 8))(v246);
                      }
                      if ( v177 >= 16 && bstrDisabled_1 >= 16 && bstrDisabled_1 + v177 < v168 )
                      {
                        v180 = _bstr_t::_bstr_t(&v204, "src")->m_Data;
                        LOBYTE(nStep) = 45;
                        v181 = v180 ? v180->m_wstr : 0;
                        v182 = dwIndex->lpVtbl->getNamedItem(dwIndex, v181, &v246);
                        LOBYTE(nStep) = 42;
                        v257 = v182 == 0;
                        _bstr_t::_Free(&v204);
                        v183 = v235;
                        if ( v257 )
                        {
                          (*(*v246 + 32))(v246, &pvarSrc);
                          _bstr_t::_bstr_t(&bstrTemp, &pvarSrc);
                          LOBYTE(nStep) = 46;
                          if ( bstrTemp.m_Data )
                            v184 = bstrTemp.m_Data->m_wstr;
                          else
                            v184 = 0;
                          v185 = wcschr(v184, 0x2Fu);
                          if ( v185 )
                          {
                            do
                            {
                              *v185 = 92;
                              v185 = wcschr(v185 + 1, 0x2Fu);
                            }
                            while ( v185 );
                            v183 = v235;
                          }
                          _bstr_t::_bstr_t(&v213, L"\\");
                          LOBYTE(nStep) = 47;
                          v186 = _bstr_t::operator+(&StringItem.strValue[2], &bstrDisabled, &v213);
                          LOBYTE(nStep) = 48;
                          bstrReason = _bstr_t::operator+(v186, &v201, &bstrTemp);
                          if ( &v234 != bstrReason )
                          {
                            _bstr_t::_Free(&v234);
                            v187 = *bstrReason;
                            v234.m_Data = v187;
                            if ( v187 )
                              InterlockedIncrement(&v187->m_RefCount);
                          }
                          _bstr_t::_Free(&v201);
                          _bstr_t::_Free(&bstrDisabled);
                          LOBYTE(nStep) = 46;
                          _bstr_t::_Free(&v213);
                          v168 = bstrDisabled_1 + v183;
                          (*(*v246 + 8))(v246);
                          LOBYTE(nStep) = 42;
                          _bstr_t::_Free(&bstrTemp);
                        }
                      }
                      dwIndex->lpVtbl->Release(dwIndex);
                      LOBYTE(nStep) = 9;
                      VariantClear(&pvarSrc);
                    }
                    (*(bstrResult->m_wstr + 2))(bstrResult);
                  }
                  while ( !(*(bstrSectionName->m_wstr + 9))(bstrSectionName, &bstrResult) );
                  v124 = EventItem;
                  v23 = v245;
                }
                (*(bstrSectionName->m_wstr + 2))(bstrSectionName);
              }
              pIXMLDOMNode2->lpVtbl->Release(pIXMLDOMNode2);
            }
            pIXMLDOMNode->lpVtbl->Release(pIXMLDOMNode);
          }
        }
      }
      bstrReason = v231->_Mypair._Myval2._Myhead;
      v188 = cbstrList::getInstance(bstrReason, *(bstrReason + 1), &StringItem);
      v189 = v231->_Mypair._Myval2._Mysize;
      if ( 97612892 - v189 < 1 )
        goto LABEL_10;
      v231->_Mypair._Myval2._Mysize = v189 + 1;
      *(bstrReason + 1) = v188;
      **(v188 + 4) = v188;
      if ( pIXMLDOMDocument )
        pIXMLDOMDocument->lpVtbl->Release(pIXMLDOMDocument);
      if ( v124 && !InterlockedDecrement(&v124->m_RefCount) )
      {
        if ( v124->m_wstr )
        {
          SysFreeString(v124->m_wstr);
          v124->m_wstr = 0;
        }
        if ( v124->m_str )
        {
          j_j__free(v124->m_str);
          v124->m_str = 0;
        }
        j__free(v124);
      }
      LOBYTE(nStep) = 0;
      tagPEStringStruct::~tagPEStringStruct(&StringItem);
      v23 = v23->_Mypair._Myval2._Myhead;
      v245 = v23;
      if ( v23 == theDwordList )
        goto LABEL_526;
    }
    v116 = MultiByteToWideChar(
             CP_UTF8,
             0,
             &pIXMLDOMParseError->lpVtbl + 3,
             &nNumberOfBytesToRead[-1].m_RefCount + 1,
             bstrSourceText,
             nNumberOfBytesToRead);
LABEL_357:
    *(&bstrSourceText->m_wstr + v116) = 0;
    goto LABEL_358;
  }
LABEL_526:
  v190 = theDwordList;
  v191 = theDwordList->_Mypair._Myval2._Myhead;
  v190->_Mypair._Myval2._Myhead = v190;
  v190->_Mypair._Myval2._Mysize = v190;
  if ( v191 != v190 )
  {
    do
    {
      v192 = v191->_Next;
      j__free(v191);
      v191 = v192;
    }
    while ( v192 != v190 );
  }
  j__free(v190);
  return 1;
}
// 10928CC: using guessed type wchar_t aProgramw6432[14];
// 10C4C64: using guessed type int (__stdcall *IsWow64Process)(_DWORD, _DWORD);
// 10C4C68: using guessed type int dword_10C4C68;
// 10C4C6C: using guessed type int (__stdcall *GetSystemDefaultLocaleName)(_DWORD, _DWORD);
// 10C4C70: using guessed type int (__stdcall *GetUserDefaultLocaleName)(_DWORD, _DWORD);

//----- (00FED790) --------------------------------------------------------
void *__cdecl sub_FED790(HWND hWndIn)
{
  HWND v1; // ebx
  HMODULE v2; // eax
  Data_t_bstr_t *v3; // esi
  const wchar_t *v4; // eax
  const WCHAR **v5; // eax
  char **v6; // eax
  Data_t_bstr_t *v7; // edi
  unsigned __int8 *i; // esi
  OLECHAR **v9; // eax
  OLECHAR *v10; // eax
  WCHAR *v11; // eax
  const WCHAR ***v12; // eax
  const WCHAR **v13; // eax
  const WCHAR ***v14; // eax
  const WCHAR **v15; // eax
  const wchar_t *v16; // eax
  const WCHAR **v17; // eax
  const WCHAR ***v18; // eax
  const WCHAR **v19; // eax
  char v20; // bl
  const WCHAR **v21; // eax
  const WCHAR **v22; // eax
  int *v23; // eax
  int v24; // ebx
  int pszPath; // eax
  HBITMAP v26; // ST40_4
  struct _IMAGELIST *hImgList; // eax
  HBITMAP v28; // ST40_4
  struct _IMAGELIST *v29; // eax
  _DWORD *v30; // eax
  OLECHAR *v31; // eax
  HICON v32; // ST44_4
  struct _IMAGELIST *v33; // eax
  _DWORD *v34; // eax
  OLECHAR *pszPathName; // eax
  HICON v36; // ST44_4
  struct _IMAGELIST *v37; // eax
  OLECHAR **v38; // eax
  OLECHAR *v39; // eax
  HBITMAP v40; // eax
  HBITMAP v41; // eax
  int *v42; // eax
  int v43; // eax
  const WCHAR ***v44; // eax
  const WCHAR **v45; // eax
  const WCHAR ***v46; // eax
  const WCHAR **v47; // eax
  const WCHAR ***v48; // eax
  const WCHAR **v49; // eax
  const WCHAR ***v50; // eax
  const WCHAR **v51; // eax
  const WCHAR ***v52; // eax
  const WCHAR **v53; // eax
  const WCHAR ***v54; // eax
  const WCHAR **v55; // eax
  int *v56; // eax
  int v57; // eax
  int v58; // ST40_4
  int v59; // ST34_4
  DWORD v60; // ST08_4
  char **v61; // ebx
  char *v62; // esi
  int v64; // [esp+10h] [ebp-344h]
  void *v65; // [esp+14h] [ebp-340h]
  CPEString str1; // [esp+18h] [ebp-33Ch]
  void *v67; // [esp+1Ch] [ebp-338h]
  CPEString str2; // [esp+20h] [ebp-334h]
  void *v69; // [esp+24h] [ebp-330h]
  void *v70; // [esp+28h] [ebp-32Ch]
  void *v71; // [esp+2Ch] [ebp-328h]
  void *v72; // [esp+30h] [ebp-324h]
  IShellItem2 *pShellItem2; // [esp+34h] [ebp-320h]
  void *v74; // [esp+38h] [ebp-31Ch]
  void *v75; // [esp+3Ch] [ebp-318h]
  void *v76; // [esp+40h] [ebp-314h]
  void *v77; // [esp+44h] [ebp-310h]
  CPEString v78; // [esp+48h] [ebp-30Ch]
  void *v79; // [esp+4Ch] [ebp-308h]
  CPEString v80; // [esp+50h] [ebp-304h]
  CPEString v81; // [esp+54h] [ebp-300h]
  CPEString str3; // [esp+58h] [ebp-2FCh]
  void *v83; // [esp+5Ch] [ebp-2F8h]
  int v84; // [esp+60h] [ebp-2F4h]
  _bstr_t bstrText; // [esp+64h] [ebp-2F0h]
  void *v86; // [esp+68h] [ebp-2ECh]
  void *v87; // [esp+6Ch] [ebp-2E8h]
  void *v88; // [esp+70h] [ebp-2E4h]
  void *ppv1; // [esp+74h] [ebp-2E0h]
  WCHAR *ppv3; // [esp+78h] [ebp-2DCh]
  IShellItemImageFactory *pIShellItemImageFactory; // [esp+7Ch] [ebp-2D8h]
  void *v92; // [esp+80h] [ebp-2D4h]
  HWND hWnd; // [esp+84h] [ebp-2D0h]
  HBITMAP hSmallImage; // [esp+88h] [ebp-2CCh]
  HBITMAP hLargeImage; // [esp+8Ch] [ebp-2C8h]
  SHFILEINFOW FileInfo; // [esp+90h] [ebp-2C4h]
  int v97; // [esp+350h] [ebp-4h]

  v1 = hWndIn;
  hWnd = hWndIn;
  QuerySideBarConfigPath(&bstrText);
  v97 = 0;
  if ( !SHCreateItemFromParsingName )
  {
    v2 = LoadLibraryW(L"Shell32.dll");
    SHCreateItemFromParsingName = GetProcAddress(v2, "SHCreateItemFromParsingName");
  }
  v87 = _wcsdup(&gszNullString);
  v88 = _wcsdup(&gszNullString);
  v86 = _wcsdup(&gszNullString);
  pIShellItemImageFactory = _wcsdup(&gszNullString);
  v92 = _wcsdup(&gszNullString);
  hSmallImage = _wcsdup(&gszNullString);
  v3 = bstrText.m_Data;
  if ( !bstrText.m_Data || (v4 = bstrText.m_Data->m_wstr) == 0 )
    v4 = &gszNullString;
  hLargeImage = _wcsdup(v4);
  if ( !v3 || (v5 = v3->m_wstr) == 0 )
    v5 = &gszNullString;
  ppv3 = _wcsdup(v5);
  LOBYTE(v97) = 8;
  ppv1 = sub_FD3FF0(hWndIn, 7u, 0xFFFFFFFF, 7u, &ppv3, &hLargeImage, &hSmallImage);
  free(ppv3);
  free(hLargeImage);
  free(hSmallImage);
  free(v92);
  free(pIShellItemImageFactory);
  free(v86);
  free(v88);
  LOBYTE(v97) = 0;
  free(v87);
  v84 = 0;
  v83 = cbstrList::cbstrList(0, 0);
  LOBYTE(v97) = 9;
  PE_LoadConfigFiles(&bstrText, &v83);
  v6 = v83;
  v7 = bstrText.m_Data;
  for ( i = *v83; i != v83; v6 = v83 )
  {
    v9 = *(i + 4);
    if ( v9 )
    {
      v10 = *v9;
      if ( v10 )
      {
        if ( SysStringLen(v10) )
        {
          v11 = malloc(2u);
          ppv3 = v11;
          *v11 = 0;
          v12 = *(i + 7);
          if ( !v12 || (v13 = *v12) == 0 )
            v13 = &gszNullString;
          v65 = _wcsdup(v13);
          v14 = *(i + 5);
          if ( !v14 || (v15 = *v14) == 0 )
            v15 = &gszNullString;
          v79 = _wcsdup(v15);
          if ( !v7 || (v16 = v7->m_wstr) == 0 )
            v16 = &gszNullString;
          v86 = _wcsdup(v16);
          if ( !v7 || (v17 = v7->m_wstr) == 0 )
            v17 = &gszNullString;
          v88 = _wcsdup(v17);
          v18 = *(i + 6);
          if ( !v18 || (v19 = *v18) == 0 )
            v19 = &gszNullString;
          v87 = _wcsdup(v19);
          LOBYTE(v97) = 15;
          v20 = sub_FD3D40(v1, &v87, &v88, &v86, &v79, &v65, &ppv3, &v64);
          free(v87);
          free(v88);
          free(v86);
          free(v79);
          LOBYTE(v97) = 10;
          free(v65);
          if ( v20 )
          {
            if ( ppv1 == -1 )
            {
              v69 = _wcsdup(&gszNullString);
              v75 = _wcsdup(&gszNullString);
              v67 = _wcsdup(&gszNullString);
              v77 = _wcsdup(&gszNullString);
              v71 = _wcsdup(&gszNullString);
              str3.m_String = _wcsdup(&gszNullString);
              if ( !v7 || (v21 = v7->m_wstr) == 0 )
                v21 = &gszNullString;
              str2.m_String = _wcsdup(v21);
              if ( !v7 || (v22 = v7->m_wstr) == 0 )
                v22 = &gszNullString;
              str1.m_String = _wcsdup(v22);
              LOBYTE(v97) = 23;
              ppv1 = sub_FD3FF0(hWnd, 7u, 0xFFFFFFFF, 7u, &str1, &str2, &str3);
              free(str1.m_String);
              free(str2.m_String);
              free(str3.m_String);
              free(v71);
              free(v77);
              free(v67);
              free(v75);
              LOBYTE(v97) = 10;
              free(v69);
            }
            v23 = *(i + 10);
            v24 = -1;
            v92 = -1;
            if ( v23 )
              pszPath = *v23;
            else
              pszPath = 0;
            // Creates and initializes a Shell item object from a parsing name.
            if ( SHCreateItemFromParsingName(pszPath, 0, &CLSID_IShellItem2, &pShellItem2) >= 0 )
            {
              pIShellItemImageFactory = 0;
              if ( pShellItem2->lpVtbl->QueryInterface(
                     pShellItem2,
                     &CLSID_IShellItemImageFactory,
                     &pIShellItemImageFactory) >= 0 )
              {
                hSmallImage = 0;
                hLargeImage = 0;
                (pIShellItemImageFactory->lpVtbl->GetImage)(pIShellItemImageFactory, 16, 16, 0, &hSmallImage);
                (pIShellItemImageFactory->lpVtbl->GetImage)(pIShellItemImageFactory, 32, 32, 0, &hLargeImage);
                if ( hSmallImage )
                {
                  v26 = hSmallImage;
                  hImgList = SendMessageW(hWnd, LVM_GETIMAGELIST, 1u, 0);
                  v24 = ImageList_Add(hImgList, v26, 0);
                  DeleteObject(hSmallImage);
                }
                if ( hLargeImage )
                {
                  v28 = hLargeImage;
                  v29 = SendMessageW(hWnd, LVM_GETIMAGELIST, 0, 0);
                  v92 = ImageList_Add(v29, v28, 0);
                  DeleteObject(hLargeImage);
                }
                pIShellItemImageFactory->lpVtbl->Release(pIShellItemImageFactory);
              }
              pShellItem2->lpVtbl->Release(pShellItem2);
            }
            if ( v24 < 0 )
            {
              FileInfo.hIcon = 0;
              memset(&FileInfo.iIcon, 0, 0x2B0u);
              v30 = *(i + 10);
              v31 = (v30 ? *v30 : 0);
              if ( GetSHFileInfo(v31, 0, &FileInfo, sizeof(SHFILEINFOW), 0x101u) )
              {
                v32 = FileInfo.hIcon;
                v33 = SendMessageW(hWnd, LVM_GETIMAGELIST, 1u, 0);
                v24 = ImageList_ReplaceIcon(v33, -1, v32);
                DestroyIcon(FileInfo.hIcon);
              }
            }
            if ( v92 < 0 )
            {
              FileInfo.hIcon = 0;
              memset(&FileInfo.iIcon, 0, 0x2B0u);
              v34 = *(i + 10);
              pszPathName = (v34 ? *v34 : 0);
              if ( GetSHFileInfo(pszPathName, 0, &FileInfo, sizeof(SHFILEINFOW), 0x100u) )
              {
                v36 = FileInfo.hIcon;
                v37 = SendMessageW(hWnd, LVM_GETIMAGELIST, 0, 0);
                v92 = ImageList_ReplaceIcon(v37, -1, v36);
                DestroyIcon(FileInfo.hIcon);
              }
            }
            v38 = *(i + 10);
            if ( v38 )
            {
              v39 = *v38;
              if ( v39 )
              {
                if ( SysStringLen(v39) && v24 < 0 )
                {
                  v40 = malloc(2u);
                  hSmallImage = v40;
                  *v40 = 0;
                  v41 = malloc(2u);
                  hLargeImage = v41;
                  *v41 = 0;
                  v42 = *(i + 10);
                  LOBYTE(v97) = 25;
                  if ( v42 )
                    v43 = *v42;
                  v24 = sub_FD4ED0();
                  free(hLargeImage);
                  free(hSmallImage);
                }
              }
            }
            v70 = _wcsdup(&gszNullString);
            v44 = *(i + 4);
            if ( !v44 || (v45 = *v44) == 0 )
              v45 = &gszNullString;
            v72 = _wcsdup(v45);
            v46 = *(i + 8);
            if ( !v46 || (v47 = *v46) == 0 )
              v47 = &gszNullString;
            v74 = _wcsdup(v47);
            v48 = *(i + 7);
            if ( !v48 || (v49 = *v48) == 0 )
              v49 = &gszNullString;
            v76 = _wcsdup(v49);
            v50 = *(i + 5);
            if ( !v50 || (v51 = *v50) == 0 )
              v51 = &gszNullString;
            v78.m_String = _wcsdup(v51);
            v52 = *(i + 4);
            if ( !v52 || (v53 = *v52) == 0 )
              v53 = &gszNullString;
            v80.m_String = _wcsdup(v53);
            v54 = *(i + 6);
            if ( !v54 || (v55 = *v54) == 0 )
              v55 = &gszNullString;
            v81.m_String = _wcsdup(v55);
            v56 = *(i + 9);
            LOBYTE(v97) = 32;
            if ( v56 )
              v57 = *v56;
            v58 = *(i + 2);
            v59 = i[12];
            v60 = v24;
            v1 = hWnd;
            sub_FD3FF0(hWnd, v60, ppv1, 0xFu, &v81, &v80, &v78);
            free(v81.m_String);
            free(v80.m_String);
            free(v78.m_String);
            free(v76);
            free(v74);
            free(v72);
            free(v70);
          }
          else
          {
            v1 = hWnd;
          }
          LOBYTE(v97) = 9;
          free(ppv3);
        }
      }
    }
    i = *i;
  }
  v61 = *v6;
  *v6 = v6;
  v6[1] = v6;
  if ( v61 != v6 )
  {
    do
    {
      v62 = *v61;
      tagPEStringStruct::~tagPEStringStruct((v61 + 2));
      j__free(v61);
      v6 = v83;
      v61 = v62;
    }
    while ( v62 != v83 );
  }
  j__free(v6);
  if ( v7 && !InterlockedDecrement(&v7->m_RefCount) )
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
  return ppv1;
}
// 1092A90: using guessed type GUID CLSID_IShellItem2;
// 10A7B6C: using guessed type GUID CLSID_IShellItemImageFactory;
// 10C4C74: using guessed type int (__stdcall *SHCreateItemFromParsingName)(_DWORD, _DWORD, _DWORD, _DWORD);

//----- (00FEE1B0) --------------------------------------------------------
_bstr_t *__cdecl MakeSectionName(_bstr_t *a1, int a2)
{
  __int16 Dest[260]; // [esp+8h] [ebp-20Ch]

  _swprintf(Dest, L"Section %d", a2);
  _bstr_t::_bstr_t(a1, Dest);
  return a1;
}

//----- (00FEE210) --------------------------------------------------------
_bstr_t *__cdecl QuerySideBarConfigPath(_bstr_t *bstrText)
{
  FARPROC SHGetFolderPathW; // eax
  HMODULE v2; // eax
  WCHAR *szProfileImgPath; // ecx
  int v4; // edx
  WCHAR v5; // ax
  _WORD *v6; // edi
  __int16 v7; // ax
  _WORD *v8; // edi
  __int16 v9; // ax
  int v11; // [esp+Ch] [ebp-210h]
  WCHAR szAppPath[260]; // [esp+10h] [ebp-20Ch]

  szAppPath[0] = 0;
  v11 = 0;
  memset(&szAppPath[1], 0, 0x206u);
  if ( gpAccountInfo )
  {
    szProfileImgPath = gpAccountInfo->szProfileImgPath;
    v4 = szAppPath - gpAccountInfo->szProfileImgPath;
    do
    {
      v5 = *szProfileImgPath;
      ++szProfileImgPath;
      *(szProfileImgPath + v4 - 2) = v5;
    }
    while ( v5 );
    v6 = (&v11 + 2);
    do
    {
      v7 = v6[1];
      ++v6;
    }
    while ( v7 );
    qmemcpy(v6, L"\\AppData\\Local", 30u);
  }
  else
  {
    SHGetFolderPathW = *::SHGetFolderPathW;
    if ( !*::SHGetFolderPathW )
    {
      v2 = LoadLibraryW(L"shell32.dll");
      SHGetFolderPathW = GetProcAddress(v2, "SHGetFolderPathW");
      *::SHGetFolderPathW = SHGetFolderPathW;
    }
    (SHGetFolderPathW)(0, CSIDL_LOCAL_APPDATA, 0, 0, szAppPath);
  }
  v8 = (&v11 + 2);
  do
  {
    v9 = v8[1];
    ++v8;
  }
  while ( v9 );
  qmemcpy(v8, L"\\Microsoft\\Windows Sidebar\\Settings.ini", 80u);
  _bstr_t::_bstr_t(bstrText, szAppPath);
  return bstrText;
}
// 1092848: using guessed type wchar_t aAppdataLocal[15];
// 1092868: using guessed type wchar_t aMicrosoftWindo[40];

//----- (00FEE320) --------------------------------------------------------
_DWORD *__stdcall cbstrList::cbstrList(_DWORD *a1, _DWORD *a2)
{
  _DWORD *result; // eax
  _DWORD *v3; // ecx
  _DWORD *v4; // edx

  result = operator new(0x2Cu);
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

//----- (00FEE360) --------------------------------------------------------
void __thiscall sub_FEE360(std__List *this)
{
  std__List *v1; // ebx
  std__list_node *v2; // esi
  std__list_node *v3; // edi

  v1 = this;
  v2 = this->_Mypair._Myval2._Myhead->_Next;
  this->_Mypair._Myval2._Myhead->_Next = this->_Mypair._Myval2._Myhead;
  this->_Mypair._Myval2._Myhead->_Prev = this->_Mypair._Myval2._Myhead;
  this->_Mypair._Myval2._Mysize = 0;
  if ( v2 != this->_Mypair._Myval2._Myhead )
  {
    do
    {
      v3 = v2->_Next;
      tagPEStringStruct::~tagPEStringStruct(&v2->_Myval);
      j__free(v2);
      v2 = v3;
    }
    while ( v3 != v1->_Mypair._Myval2._Myhead );
  }
}

//----- (00FEE3A0) --------------------------------------------------------
void *__cdecl sub_FEE3A0(int a1, void *a2, wchar_t *a3, void *a4, char a5)
{
  HWND v5; // edi
  wchar_t *v6; // ebx
  const wchar_t *v7; // eax
  const wchar_t *v8; // eax
  CPEString *v9; // eax
  HANDLE v10; // esi
  unsigned __int16 *v11; // esi
  LPCWSTR v12; // edx
  WCHAR v13; // cx
  wchar_t *v14; // eax
  wchar_t **v15; // eax
  unsigned __int16 *v16; // edi
  _WORD *v17; // eax
  void *v18; // edi
  const wchar_t **v19; // eax
  wchar_t *v20; // edi
  wchar_t *v21; // eax
  wchar_t *v22; // edi
  const wchar_t **v23; // eax
  const wchar_t *v24; // ecx
  const wchar_t *v25; // eax
  const wchar_t *v26; // eax
  void *v27; // edi
  const wchar_t **v28; // eax
  WCHAR *v29; // edi
  const wchar_t *v30; // ecx
  const wchar_t *v31; // eax
  const wchar_t *v32; // eax
  HANDLE v33; // esi
  tagPEStringStruct v35; // [esp+10h] [ebp-334h]
  int a2a; // [esp+2Ch] [ebp-318h]
  int v37; // [esp+30h] [ebp-314h]
  int v38; // [esp+34h] [ebp-310h]
  int v39; // [esp+38h] [ebp-30Ch]
  void *v40; // [esp+3Ch] [ebp-308h]
  HANDLE hFindFile; // [esp+40h] [ebp-304h]
  WCHAR *ppszArgs; // [esp+44h] [ebp-300h]
  void *v43; // [esp+48h] [ebp-2FCh]
  WCHAR *ppv; // [esp+4Ch] [ebp-2F8h]
  CPEString v45; // [esp+50h] [ebp-2F4h]
  CPEString v46; // [esp+54h] [ebp-2F0h]
  void *v47; // [esp+58h] [ebp-2ECh]
  void *v48; // [esp+5Ch] [ebp-2E8h]
  void *v49; // [esp+60h] [ebp-2E4h]
  void *v50; // [esp+64h] [ebp-2E0h]
  void *v51; // [esp+68h] [ebp-2DCh]
  CPEString v52; // [esp+6Ch] [ebp-2D8h]
  void *v53; // [esp+70h] [ebp-2D4h]
  void *v54; // [esp+74h] [ebp-2D0h]
  void *v55; // [esp+78h] [ebp-2CCh]
  void *v56; // [esp+7Ch] [ebp-2C8h]
  void *v57; // [esp+80h] [ebp-2C4h]
  void *v58; // [esp+84h] [ebp-2C0h]
  CPEString v59; // [esp+88h] [ebp-2BCh]
  void *v60; // [esp+8Ch] [ebp-2B8h]
  void *v61; // [esp+90h] [ebp-2B4h]
  void *v62; // [esp+94h] [ebp-2B0h]
  CPEString str1; // [esp+98h] [ebp-2ACh]
  int v64; // [esp+9Ch] [ebp-2A8h]
  int v65; // [esp+A0h] [ebp-2A4h]
  CPEString str2; // [esp+A4h] [ebp-2A0h]
  CPEString str3; // [esp+A8h] [ebp-29Ch]
  WCHAR *v68; // [esp+ACh] [ebp-298h]
  WCHAR *ppv3; // [esp+B0h] [ebp-294h]
  void *v70; // [esp+B4h] [ebp-290h]
  void *v71; // [esp+B8h] [ebp-28Ch]
  void *v72; // [esp+BCh] [ebp-288h]
  wchar_t *v73; // [esp+C0h] [ebp-284h]
  void *v74; // [esp+C4h] [ebp-280h]
  void *v75; // [esp+C8h] [ebp-27Ch]
  DWORD dwValue; // [esp+CCh] [ebp-278h]
  int a1a; // [esp+D0h] [ebp-274h]
  DWORD v78; // [esp+D4h] [ebp-270h]
  CPEString v79; // [esp+D8h] [ebp-26Ch]
  LPCWSTR lpszFileName; // [esp+DCh] [ebp-268h]
  char v81; // [esp+E3h] [ebp-261h]
  struct _WIN32_FIND_DATAW FindFileData; // [esp+E4h] [ebp-260h]
  int v83; // [esp+340h] [ebp-4h]

  v5 = a1;
  a1a = a1;
  v73 = a3;
  v65 = 0;
  v83 = 0;
  v74 = malloc(2u);
  *v74 = 0;
  v72 = malloc(2u);
  *v72 = 0;
  v6 = malloc(2u);
  v35.strValue[6] = v6;
  *v6 = 0;
  v79.m_String = malloc(2u);
  *v79.m_String = 0;
  v75 = malloc(2u);
  *v75 = 0;
  v68 = malloc(2u);
  *v68 = 0;
  if ( a2 == -1 && a5 )
  {
    v78 = _wcsdup(&gszNullString);
    dwValue = _wcsdup(&gszNullString);
    v70 = _wcsdup(&gszNullString);
    v71 = _wcsdup(&gszNullString);
    ppv3 = _wcsdup(&gszNullString);
    str3.m_String = _wcsdup(&gszNullString);
    v7 = &gszNullString;
    if ( a3 )
      v7 = a3;
    str2.m_String = _wcsdup(v7);
    v8 = &gszNullString;
    if ( a3 )
      v8 = a3;
    lpszFileName = _wcsdup(v8);
    LOBYTE(v83) = 14;
    sub_FD3FF0(a1, 2u, 0xFFFFFFFF, 0, &lpszFileName, &str2, &str3);
    free(lpszFileName);
    free(str2.m_String);
    free(str3.m_String);
    free(ppv3);
    free(v71);
    free(v70);
    free(dwValue);
    free(v78);
  }
  CPEString::InsertAt(&a4, L"\\", 0x7FFFFFFFu, 0);
  v9 = CPEString::Append(&ppv, &a4, "*");
  LOBYTE(v83) = 15;
  v10 = sub_FE0FC0(v9->m_String, &FindFileData);
  LOBYTE(v83) = 6;
  hFindFile = v10;
  free(ppv);
  if ( v10 != -1 )
  {
    do
    {
      v11 = malloc(2u);
      v35.strValue[5] = v11;
      *v11 = 0;
      if ( FindFileData.cFileName[0] != 46 && _wcsicmp(FindFileData.cFileName, L"AutorunsDisabled") )
      {
        CPEString::Append(&lpszFileName, &a4, FindFileData.cFileName);
        v12 = lpszFileName;
        LOBYTE(v83) = 17;
        v78 = (lpszFileName + 1);
        do
        {
          v13 = *v12;
          ++v12;
        }
        while ( v13 );
        if ( ((v12 - v78) >> 1) < 4 )
          goto LABEL_54;
        v14 = wcschr(lpszFileName, 0);
        if ( _wcsicmp(v14 - 4, L".lnk")
          || (v15 = sub_FD4FB0(&ppszArgs, v5, lpszFileName),
              v65 |= 1u,
              v16 = v11,
              v11 = _wcsdup(*v15),
              v35.strValue[5] = v11,
              free(v16),
              v81 = 1,
              !wcslen(v11)) )
        {
LABEL_54:
          v81 = 0;
        }
        if ( v65 & 1 )
        {
          v65 &= 0xFFFFFFFE;
          free(ppszArgs);
        }
        v17 = malloc(2u);
        if ( v81 )
        {
          dwValue = v17;
          v78 = v17;
          *v17 = 0;
          a2a = malloc(2u);
          *a2a = 0;
          v37 = 0;
          v38 = 0;
          v39 = 0;
          LOBYTE(v83) = 19;
          sub_FD6CC0(v11, &a2a);
          v18 = v75;
          v75 = _wcsdup(lpszFileName);
          free(v18);
          v19 = sub_FD4EE0(&v40, a1a, &a2a, 0);
          v20 = v6;
          v6 = _wcsdup(*v19);
          v35.strValue[6] = v6;
          free(v20);
          free(v40);
          if ( wcsrchr(v6, 0x5Cu) )
          {
            v21 = wcsrchr(v6, 0x5Cu);
            v22 = _wcsdup(v21 + 1);
            v78 = v22;
            free(dwValue);
          }
          else
          {
            v22 = _wcsdup(v6);
            v78 = v22;
            free(dwValue);
          }
          v23 = sub_FD4EE0(&v35.strValue[4], a1a, &a2a, 0);
          dwValue = v79.m_String;
          v79.m_String = _wcsdup(*v23);
          free(dwValue);
          free(v35.strValue[4]);
          dwValue = sub_FD4ED0();
          v24 = &gszNullString;
          if ( v73 )
            v24 = v73;
          v71 = _wcsdup(v24);
          v70 = _wcsdup(FindFileData.cFileName);
          LOBYTE(v83) = 21;
          v81 = sub_FD3D40(a1a, &v70, &v71, &lpszFileName, &v79, &v74, &v68, &v64);
          free(v70);
          LOBYTE(v83) = 19;
          free(v71);
          if ( v81 )
          {
            if ( a2 != -1 )
              goto LABEL_55;
            if ( sub_FD63B0(v22) )
            {
              v51 = _wcsdup(&gszNullString);
              v60 = _wcsdup(&gszNullString);
              v53 = _wcsdup(&gszNullString);
              v54 = _wcsdup(&gszNullString);
              v58 = _wcsdup(&gszNullString);
              str2.m_String = _wcsdup(&gszNullString);
              v25 = &gszNullString;
              if ( v73 )
                v25 = v73;
              str3.m_String = _wcsdup(v25);
              v26 = &gszNullString;
              if ( v73 )
                v26 = v73;
              ppv3 = _wcsdup(v26);
              LOBYTE(v83) = 29;
              a2 = sub_FD3FF0(a1a, 2u, 0xFFFFFFFF, 0, &ppv3, &str3, &str2);
              free(ppv3);
              free(str3.m_String);
              free(str2.m_String);
              free(v58);
              free(v54);
              free(v53);
              free(v60);
              free(v51);
              if ( a2 != -1 )
              {
LABEL_55:
                v49 = _wcsdup(&gszNullString);
                str1.m_String = _wcsdup(FindFileData.cFileName);
                LOBYTE(v83) = 31;
                sub_FD3FF0(a1a, dwValue, a2, 7u, &str1, &lpszFileName, &v79);
                free(str1.m_String);
                free(v49);
              }
            }
          }
          sub_FD21F0(&a2a);
          free(v22);
          v5 = a1a;
        }
        else
        {
          v35.strValue[0] = v17;
          *v17 = 0;
          v35.strValue[1] = 0;
          v35.strValue[2] = 0;
          v35.strValue[3] = 0;
          LOBYTE(v83) = 32;
          sub_FD7040(lpszFileName, &v35);
          v27 = v75;
          v75 = _wcsdup(lpszFileName);
          free(v27);
          v28 = sub_FD4EE0(&v43, a1a, &v35, 0);
          v29 = v79.m_String;
          v79.m_String = _wcsdup(*v28);
          free(v29);
          free(v43);
          v5 = a1a;
          v78 = sub_FD4ED0();
          v30 = &gszNullString;
          if ( v73 )
            v30 = v73;
          v47 = _wcsdup(v30);
          v56 = _wcsdup(FindFileData.cFileName);
          LOBYTE(v83) = 34;
          v81 = sub_FD3D40(v5, &v56, &v47, &lpszFileName, &v79, &v74, &v68, &v64);
          free(v56);
          LOBYTE(v83) = 32;
          free(v47);
          if ( v81 )
          {
            if ( a2 != -1 )
              goto LABEL_56;
            if ( sub_FD63B0(FindFileData.cFileName) )
            {
              v61 = _wcsdup(&gszNullString);
              v62 = _wcsdup(&gszNullString);
              v55 = _wcsdup(&gszNullString);
              v50 = _wcsdup(&gszNullString);
              v48 = _wcsdup(&gszNullString);
              v52.m_String = _wcsdup(&gszNullString);
              v31 = &gszNullString;
              if ( v73 )
                v31 = v73;
              v46.m_String = _wcsdup(v31);
              v32 = &gszNullString;
              if ( v73 )
                v32 = v73;
              v45.m_String = _wcsdup(v32);
              LOBYTE(v83) = 42;
              a2 = sub_FD3FF0(v5, 2u, 0xFFFFFFFF, 0, &v45, &v46, &v52);
              free(v45.m_String);
              free(v46.m_String);
              free(v52.m_String);
              free(v48);
              free(v50);
              free(v55);
              free(v62);
              free(v61);
              if ( a2 != -1 )
              {
LABEL_56:
                v57 = _wcsdup(&gszNullString);
                v59.m_String = _wcsdup(FindFileData.cFileName);
                LOBYTE(v83) = 44;
                sub_FD3FF0(v5, v78, a2, 6u, &v59, &lpszFileName, &v79);
                free(v59.m_String);
                free(v57);
              }
            }
          }
          sub_FD21F0(&v35);
        }
        free(lpszFileName);
        LOBYTE(v83) = 6;
        free(v11);
      }
      else
      {
        LOBYTE(v83) = 6;
        free(v11);
      }
      v33 = hFindFile;
    }
    while ( FindNextFileW(hFindFile, &FindFileData) );
    FindClose(v33);
  }
  free(v68);
  free(v75);
  free(v79.m_String);
  free(v6);
  free(v72);
  free(v74);
  free(a4);
  return a2;
}

//----- (00FEEFA0) --------------------------------------------------------
void *__cdecl sub_FEEFA0(int a1, int a2, OLECHAR *psz, LPCWSTR lpValueName)
{
  void *v4; // eax

  v4 = sub_FEEFE0(a1, a2, psz, lpValueName, 0xFFFFFFFF, 1);
  return sub_FEEFE0(a1, a2, psz, lpValueName, v4, 0);
}

//----- (00FEEFE0) --------------------------------------------------------
void *__cdecl sub_FEEFE0(int a1, int a2, OLECHAR *psz, LPCWSTR lpValueName, void *a5, char a6)
{
  unsigned int v6; // eax
  void *v7; // esi
  HKEY hKey; // [esp+8h] [ebp-14h]
  wchar_t *ppv; // [esp+Ch] [ebp-10h]
  int v11; // [esp+18h] [ebp-4h]

  ppv = malloc(2u);
  *ppv = 0;
  v11 = 0;
  v6 = TlsGetValue(gdwTlsIndex);
  if ( PE_OpenKey(a2, psz, 0, v6 | 0x20019, &hKey) )
  {
    v7 = a5;
  }
  else if ( PE_ReadRegKey(hKey, lpValueName, 0, 0, &ppv) )
  {
    v7 = a5;
    RegCloseKey(hKey);
  }
  else
  {
    if ( !a6 )
    {
      CPEString::InsertAt(&ppv, L"\\", 0x7FFFFFFFu, 0);
      CPEString::InsertAt(&ppv, L"AutorunsDisabled", 0x7FFFFFFFu, 0);
    }
    v7 = sub_FEF0E0(a1, ppv, ppv, a5, a6);
    RegCloseKey(hKey);
  }
  free(ppv);
  return v7;
}

//----- (00FEF0E0) --------------------------------------------------------
void *__cdecl sub_FEF0E0(int a1, wchar_t *a2, wchar_t *a3, void *a4, char a5)
{
  wchar_t *v5; // esi
  _WORD *v6; // ebx
  wchar_t *v7; // edi
  const wchar_t **v8; // eax
  wchar_t *v9; // edi
  wchar_t *v10; // ebx
  wchar_t *v11; // eax
  void *v12; // ebx
  tagPEStringStruct v14; // [esp+10h] [ebp-28h]
  int v15; // [esp+34h] [ebp-4h]
  wchar_t *v16; // [esp+48h] [ebp+10h]

  v5 = malloc(2u);
  v14.strValue[4] = v5;
  *v5 = 0;
  v15 = 0;
  v6 = malloc(2u);
  v14.strValue[6] = v6;
  *v6 = 0;
  v7 = a3;
  if ( !a3 )
    v7 = a2;
  v16 = v7;
  v14.strValue[0] = malloc(2u);
  *v14.strValue[0] = 0;
  v14.strValue[1] = 0;
  v14.strValue[2] = 0;
  v14.strValue[3] = 0;
  LOBYTE(v15) = 2;
  sub_FD7040(v7, &v14);
  v8 = sub_FD4EE0(&v14.strValue[5], a1, &v14, 1);
  v9 = _wcsdup(*v8);
  v14.strValue[6] = v9;
  free(v6);
  free(v14.strValue[5]);
  if ( wcslen(v9) )
  {
    v10 = v5;
    v5 = _wcsdup(v16);
    v14.strValue[4] = v5;
    free(v10);
    v11 = _wcsdup(v5);
    v12 = sub_FEE3A0(a1, a4, v16, v11, a5);
  }
  else
  {
    v12 = a4;
  }
  sub_FD21F0(&v14);
  free(v9);
  free(v5);
  return v12;
}

//----- (00FEF210) --------------------------------------------------------
CPEString *__cdecl operator+(CPEString *pszResult, LPCWSTR ppszText1, CPEString *ppszText2)
{
  const wchar_t *v3; // ecx
  WCHAR *v4; // eax
  WCHAR *pszText1; // esi

  v3 = &gszNullString;
  if ( ppszText1 )
    v3 = ppszText1;
  v4 = _wcsdup(v3);
  pszText1 = v4;
  ppszText1 = v4;
  CPEString::Append(pszResult, &ppszText1, ppszText2);
  free(pszText1);
  return pszResult;
}

//----- (00FEF260) --------------------------------------------------------
void __cdecl sub_FEF260(int a1, int a2, wchar_t *a3, void *a4, int a5)
{
  int *v5; // esi
  void (__stdcall *v6)(BSTR); // ebx
  LONG (__stdcall *v7)(volatile LONG *); // edi
  char *v8; // ecx
  __m128i v9; // xmm0
  int v10; // edx
  int v11; // ST4C_4
  int v12; // esi
  _bstr_t *v13; // eax
  int v14; // ecx
  int v15; // esi
  int v16; // ecx
  int (__stdcall **v17)(int, void *, LPCWSTR *); // ecx
  int v18; // ecx
  OLECHAR *v19; // ebx
  bool v20; // al
  Data_t_bstr_t *v21; // esi
  _bstr_t *v22; // eax
  _bstr_t *v23; // eax
  Data_t_bstr_t *v24; // eax
  wchar_t *v25; // eax
  OLECHAR *v26; // edi
  const wchar_t *v27; // eax
  CPEString *v28; // eax
  CPEString *v29; // eax
  const WCHAR **v30; // eax
  const wchar_t *v31; // eax
  const WCHAR **v32; // eax
  char v33; // bl
  const wchar_t *v34; // eax
  const wchar_t *v35; // eax
  int v36; // ebx
  int v37; // eax
  const WCHAR **v38; // eax
  const WCHAR **v39; // eax
  int (__stdcall **v40)(int, void *, LPCWSTR *); // ecx
  int v41; // ecx
  _WORD *v42; // eax
  Data_t_bstr_t *v43; // edi
  OLECHAR *v44; // eax
  _bstr_t *v45; // eax
  _bstr_t *v46; // eax
  _bstr_t *v47; // eax
  _bstr_t *v48; // esi
  void *v49; // esi
  void *v50; // esi
  void *v51; // esi
  Data_t_bstr_t *v52; // esi
  Data_t_bstr_t *v53; // esi
  Data_t_bstr_t *v54; // esi
  Data_t_bstr_t *v55; // esi
  wchar_t *v56; // esi
  CPEString *v57; // eax
  void *v58; // ebx
  const WCHAR *v59; // esi
  unsigned int v60; // eax
  const WCHAR *v61; // eax
  LSTATUS v62; // esi
  signed int v63; // esi
  wchar_t *v64; // eax
  const wchar_t **v65; // eax
  WCHAR *v66; // esi
  wchar_t *v67; // eax
  const WCHAR **v68; // eax
  const wchar_t *v69; // eax
  int v70; // ebx
  int v71; // ebx
  const WCHAR **v72; // eax
  char v73; // bl
  unsigned int v74; // eax
  const wchar_t *v75; // eax
  const wchar_t *v76; // eax
  int v77; // ebx
  int v78; // eax
  const WCHAR **v79; // eax
  const WCHAR **v80; // eax
  int v81; // edx
  void *v82; // esi
  int v83; // eax
  WCHAR *i; // eax
  __m128i v85; // xmm0
  int v86; // edx
  int v87; // ST4C_4
  int v88; // esi
  OLECHAR *v89; // esi
  volatile LONG *v90; // eax
  volatile LONG *v91; // edi
  BSTR v92; // eax
  BSTR *v93; // eax
  BSTR *v94; // esi
  BSTR v95; // eax
  _bstr_t *v96; // eax
  WCHAR *v97; // ecx
  void **v98; // eax
  void *v99; // esi
  const wchar_t *v100; // [esp-14h] [ebp-1B0h]
  int v101; // [esp-10h] [ebp-1ACh]
  int v102; // [esp-Ch] [ebp-1A8h]
  WCHAR *v103; // [esp-8h] [ebp-1A4h]
  int *v104; // [esp-4h] [ebp-1A0h]
  int a2a; // [esp+10h] [ebp-18Ch]
  int v106; // [esp+14h] [ebp-188h]
  int v107; // [esp+18h] [ebp-184h]
  int v108; // [esp+1Ch] [ebp-180h]
  WCHAR *pszResult; // [esp+20h] [ebp-17Ch]
  VARIANTARG pvarg; // [esp+24h] [ebp-178h]
  void *v111; // [esp+34h] [ebp-168h]
  tagPEStringStruct v112; // [esp+38h] [ebp-164h]
  _bstr_t v113; // [esp+54h] [ebp-148h]
  WCHAR *ppv; // [esp+58h] [ebp-144h]
  _bstr_t v115; // [esp+5Ch] [ebp-140h]
  _bstr_t v116; // [esp+60h] [ebp-13Ch]
  void *v117; // [esp+64h] [ebp-138h]
  void *v118; // [esp+68h] [ebp-134h]
  void *v119; // [esp+6Ch] [ebp-130h]
  CPEString v120; // [esp+70h] [ebp-12Ch]
  void *v121; // [esp+74h] [ebp-128h]
  WCHAR *ppv3; // [esp+78h] [ebp-124h]
  _bstr_t v123; // [esp+7Ch] [ebp-120h]
  void *v124; // [esp+80h] [ebp-11Ch]
  void *v125; // [esp+84h] [ebp-118h]
  _bstr_t v126; // [esp+88h] [ebp-114h]
  void *v127; // [esp+8Ch] [ebp-110h]
  CPEString v128; // [esp+90h] [ebp-10Ch]
  void *v129; // [esp+94h] [ebp-108h]
  CPEString v130; // [esp+98h] [ebp-104h]
  CPEString str1; // [esp+9Ch] [ebp-100h]
  void *v132; // [esp+A0h] [ebp-FCh]
  void *v133; // [esp+A4h] [ebp-F8h]
  void *v134; // [esp+A8h] [ebp-F4h]
  void *v135; // [esp+ACh] [ebp-F0h]
  void *v136; // [esp+B0h] [ebp-ECh]
  _bstr_t v137; // [esp+B4h] [ebp-E8h]
  WCHAR *a4a; // [esp+B8h] [ebp-E4h]
  _bstr_t v139; // [esp+BCh] [ebp-E0h]
  CPEString v140; // [esp+C0h] [ebp-DCh]
  int v141; // [esp+C4h] [ebp-D8h]
  void *v142; // [esp+C8h] [ebp-D4h]
  void *v143; // [esp+CCh] [ebp-D0h]
  void *v144; // [esp+D0h] [ebp-CCh]
  void *v145; // [esp+D4h] [ebp-C8h]
  void *v146; // [esp+D8h] [ebp-C4h]
  void *v147; // [esp+DCh] [ebp-C0h]
  CPEString str2; // [esp+E0h] [ebp-BCh]
  void *v149; // [esp+E4h] [ebp-B8h]
  void *v150; // [esp+E8h] [ebp-B4h]
  CPEString str3; // [esp+ECh] [ebp-B0h]
  int v152; // [esp+F0h] [ebp-ACh]
  BSTR bstrString; // [esp+F4h] [ebp-A8h]
  DWORD dwValue; // [esp+F8h] [ebp-A4h]
  WCHAR *v155; // [esp+FCh] [ebp-A0h]
  _bstr_t v156; // [esp+100h] [ebp-9Ch]
  int v157; // [esp+104h] [ebp-98h]
  _bstr_t v158; // [esp+108h] [ebp-94h]
  _bstr_t v159; // [esp+10Ch] [ebp-90h]
  int v160; // [esp+110h] [ebp-8Ch]
  WCHAR *v161; // [esp+114h] [ebp-88h]
  _bstr_t v162; // [esp+118h] [ebp-84h]
  void *v163; // [esp+11Ch] [ebp-80h]
  WCHAR *v164; // [esp+120h] [ebp-7Ch]
  HKEY hKey; // [esp+124h] [ebp-78h]
  int *v166; // [esp+128h] [ebp-74h]
  CPEString str; // [esp+12Ch] [ebp-70h]
  void *v168; // [esp+130h] [ebp-6Ch]
  void *v169; // [esp+134h] [ebp-68h]
  CPEString v170; // [esp+138h] [ebp-64h]
  int *v171; // [esp+13Ch] [ebp-60h]
  void *v172; // [esp+140h] [ebp-5Ch]
  void *v173; // [esp+144h] [ebp-58h]
  int *v174; // [esp+148h] [ebp-54h]
  void *v175; // [esp+14Ch] [ebp-50h]
  CPEString v176; // [esp+150h] [ebp-4Ch]
  OLECHAR *psz; // [esp+154h] [ebp-48h]
  void *v178; // [esp+158h] [ebp-44h]
  CPEString v179; // [esp+15Ch] [ebp-40h]
  WCHAR *v180; // [esp+160h] [ebp-3Ch]
  LPCWSTR lpszKeyName; // [esp+164h] [ebp-38h]
  WCHAR *v182; // [esp+168h] [ebp-34h]
  void *v183; // [esp+16Ch] [ebp-30h]
  CPEString v184; // [esp+170h] [ebp-2Ch]
  OLECHAR *v185; // [esp+174h] [ebp-28h]
  _bstr_t v186; // [esp+178h] [ebp-24h]
  unsigned int v187; // [esp+17Ch] [ebp-20h]
  OLECHAR *ppszText2; // [esp+180h] [ebp-1Ch]
  LPCWSTR lpszText2; // [esp+184h] [ebp-18h]
  LPCWSTR lpszPathName; // [esp+188h] [ebp-14h]
  bool v191; // [esp+18Fh] [ebp-Dh]
  int v192; // [esp+198h] [ebp-4h]

  v187 = 0;
  lpszKeyName = 0;
  v5 = a5;
  v192 = 0;
  v171 = 0;
  v6 = SysFreeString;
  v7 = InterlockedDecrement;
  if ( (*(*a5 + 56))(a5, 1, &v171) < 0 )
    goto LABEL_196;
  v183 = 0;
  (*(*v171 + 28))(v171, &v183);
  v8 = 0;
  if ( v183 <= 0 )
    goto LABEL_195;
  do
  {
    v180 = 0;
    v178 = v8 + 1;
    pvarg.vt = 3;
    pvarg.lVal = (v8 + 1);
    v9 = _mm_loadu_si128(&pvarg);
    v104 = &v180;
    LOBYTE(v192) = 1;
    v10 = *v171;
    v11 = v171;
    _mm_storeu_si128(&v100, v9);
    v12 = (*(v10 + 32))(v11, v100, v101, v102, v103, v104);
    LOBYTE(v192) = 0;
    VariantClear(&pvarg);
    if ( v12 < 0 )
      goto LABEL_193;
    bstrString = 0;
    v104 = &bstrString;
    v103 = v180;
    if ( (*(*v180 + 28))(v180, &bstrString) < 0 )
      goto LABEL_192;
    _bstr_t::_bstr_t(&v126, bstrString);
    LOBYTE(v192) = 2;
    _bstr_t::_bstr_t(&v137, L"\\");
    LOBYTE(v192) = 3;
    v13 = _bstr_t::operator+(&a4, &v116, &v137);
    LOBYTE(v192) = 4;
    _bstr_t::operator+(v13, &v173, &v126);
    _bstr_t::_Free(&v116);
    _bstr_t::_Free(&v137);
    LOBYTE(v192) = 8;
    _bstr_t::_Free(&v126);
    v141 = 1;
    v104 = &v141;
    v103 = v180;
    (*(*v180 + 40))(v180, &v141);
    v161 = 0;
    v104 = &v161;
    v14 = *v180;
    v191 = v141 != 0;
    v103 = v180;
    if ( (*(v14 + 76))(v180, &v161) < 0 )
      goto LABEL_183;
    v174 = 0;
    v104 = &v174;
    v103 = v161;
    if ( (*(*v161 + 68))(v161, &v174) < 0 )
      goto LABEL_182;
    v15 = 0;
    v104 = &v182;
    v182 = 0;
    v16 = *v174;
    v103 = 1;
    v102 = v174;
    v157 = 0;
    if ( (*(v16 + 32))(v174, 1, &v182) < 0 )
      goto LABEL_181;
    do
    {
      v160 = -1;
      v104 = &v160;
      v103 = v182;
      (*(*v182 + 36))(v182, &v160);
      if ( !v160 )
      {
        v104 = &lpszText2;
        lpszText2 = 0;
        v103 = &unk_10A781C;
        v17 = *v182;
        v102 = v182;
        if ( (*v17)(v182, &unk_10A781C, &lpszText2) >= 0 )
        {
          lpszPathName = 0;
          lpszKeyName = 0;
          v185 = 0;
          v18 = *lpszText2;
          v104 = &lpszPathName;
          v103 = lpszText2;
          if ( (*(v18 + 40))(lpszText2, &lpszPathName) >= 0 && lpszPathName )
          {
            v104 = &lpszKeyName;
            v103 = lpszText2;
            (*(*lpszText2 + 48))(lpszText2, &lpszKeyName);
            v104 = &v185;
            v103 = lpszText2;
            (*(*lpszText2 + 56))(lpszText2, &v185);
            v104 = *sub_FDF8D0(&v111, lpszPathName);
            LOBYTE(v192) = 9;
            _bstr_t::_bstr_t(&v162, v104);
            free(v111);
            v19 = malloc(2u);
            ppszText2 = v19;
            *v19 = 0;
            a4a = malloc(2u);
            *a4a = 0;
            LOBYTE(v192) = 13;
            v20 = PE_GetPathName(a1, gpszSystemPathInfo, lpszPathName, &a4a);
            v21 = v162.m_Data;
            if ( v20 || wcschr(lpszPathName, 0x5Cu) || !v185 )
            {
              if ( v21 )
                v27 = v21->m_wstr;
              else
                v27 = 0;
              v26 = _wcsdup(v27);
              ppszText2 = v26;
              free(v19);
            }
            else
            {
              _bstr_t::_bstr_t(&v139, L"\\");
              LOBYTE(v192) = 14;
              v22 = _bstr_t::_bstr_t(&v112.strValue[5], v185);
              LOBYTE(v192) = 15;
              v23 = _bstr_t::operator+(v22, &v113, &v139);
              LOBYTE(v192) = 16;
              v24 = _bstr_t::operator+(v23, &v115, &v162)->m_Data;
              if ( v24 )
                v25 = v24->m_wstr;
              else
                v25 = 0;
              CPEString::Reset(&ppszText2, v25);
              _bstr_t::_Free(&v115);
              _bstr_t::_Free(&v113);
              _bstr_t::_Free(&v112.strValue[5]);
              _bstr_t::_Free(&v139);
              v26 = ppszText2;
            }
            v169 = malloc(2u);
            *v169 = 0;
            v168 = malloc(2u);
            *v168 = 0;
            v28 = operator+(&pszResult, L"\"", &ppszText2);
            v29 = CPEString::Append(&ppv, v28, L"\" ");
            CPEString::Append(&str, v29, lpszKeyName);
            free(ppv);
            free(pszResult);
            a2a = malloc(2u);
            *a2a = 0;
            v106 = 0;
            v107 = 0;
            v108 = 0;
            LOBYTE(v192) = 20;
            sub_FD6CC0(str.m_String, &a2a);
            sub_FD4EE0(&v170, a1, &a2a, 0);
            LOBYTE(v192) = 21;
            v100 = &v168;
            dwValue = sub_FD4ED0();
            v164 = malloc(2u);
            *v164 = 0;
            if ( !v21 || (v30 = v21->m_wstr) == 0 )
              v30 = &gszNullString;
            v134 = _wcsdup(v30);
            v31 = &gszNullString;
            if ( a3 )
              v31 = a3;
            v117 = _wcsdup(v31);
            if ( !v21 || (v32 = v21->m_wstr) == 0 )
              v32 = &gszNullString;
            v121 = _wcsdup(v32);
            LOBYTE(v192) = 25;
            v33 = sub_FD3D40(a1, &v121, &v117, &v134, &v170, &v169, &v164, &v112.strValue[6]);
            free(v121);
            free(v117);
            free(v134);
            if ( v33 )
            {
              if ( *a2 == -1 )
              {
                v142 = _wcsdup(&gszNullString);
                v133 = _wcsdup(&gszNullString);
                v144 = _wcsdup(&gszNullString);
                v135 = _wcsdup(&gszNullString);
                v146 = _wcsdup(&gszNullString);
                str3.m_String = _wcsdup(&gszNullString);
                v34 = &gszNullString;
                if ( a3 )
                  v34 = a3;
                str2.m_String = _wcsdup(v34);
                v35 = &gszNullString;
                if ( a3 )
                  v35 = a3;
                ppv3 = _wcsdup(v35);
                v36 = a1;
                LOBYTE(v192) = 33;
                v37 = sub_FD3FF0(a1, 2u, *a2, 0, &ppv3, &str2, &str3);
                v104 = ppv3;
                *a2 = v37;
                free(v104);
                free(str2.m_String);
                free(str3.m_String);
                free(v146);
                free(v135);
                free(v144);
                free(v133);
                free(v142);
              }
              else
              {
                v36 = a1;
              }
              v129 = _wcsdup(&gszNullString);
              if ( !v21 || (v38 = v21->m_wstr) == 0 )
                v38 = &gszNullString;
              v140.m_String = _wcsdup(v38);
              if ( !v173 || (v39 = *v173) == 0 )
                v39 = &gszNullString;
              str1.m_String = _wcsdup(v39);
              v103 = -1;
              v102 = 0;
              v101 = 0;
              LOBYTE(v192) = 36;
              v100 = &v129;
              sub_FD3FF0(v36, dwValue, *a2, 9u, &str1, &v140, &v170);
              free(str1.m_String);
              free(v140.m_String);
              free(v129);
            }
            free(v164);
            free(v170.m_String);
            sub_FD21F0(&a2a);
            free(str.m_String);
            free(v168);
            free(v169);
            free(a4a);
            free(v26);
            LOBYTE(v192) = 8;
            _bstr_t::_Free(&v162);
            v6 = SysFreeString;
            v15 = v157;
          }
          v104 = lpszText2;
          (*(*lpszText2 + 8))(lpszText2);
        }
      }
      if ( v160 != 5 )
        goto LABEL_179;
      v104 = &lpszPathName;
      lpszPathName = 0;
      v103 = &unk_10A783C;
      v40 = *v182;
      v102 = v182;
      if ( (*v40)(v182, &unk_10A783C, &lpszPathName) < 0 )
        goto LABEL_179;
      lpszText2 = 0;
      dwValue = 0;
      v104 = &lpszText2;
      v41 = *lpszPathName;
      v103 = lpszPathName;
      (*(v41 + 40))(lpszPathName, &lpszText2);
      v104 = &dwValue;
      v103 = lpszPathName;
      (*(*lpszPathName + 48))(lpszPathName, &dwValue);
      v42 = malloc(2u);
      v172 = v42;
      *v42 = 0;
      v43 = 0;
      v186.m_Data = 0;
      v44 = 0;
      LOBYTE(v192) = 38;
      v185 = 0;
      while ( 1 )
      {
        _bstr_t::_bstr_t(&v159, (&off_10BAA1C)[v44]);
        LOBYTE(v192) = 39;
        _bstr_t::_bstr_t(&v156, L"\\");
        LOBYTE(v192) = 40;
        _bstr_t::_bstr_t(&v158, lpszText2);
        LOBYTE(v192) = 41;
        v45 = _bstr_t::_bstr_t(&v123, L"CLSID\\");
        LOBYTE(v192) = 42;
        v46 = _bstr_t::operator+(v45, &v125, &v158);
        LOBYTE(v192) = 43;
        v47 = _bstr_t::operator+(v46, &v136, &v156);
        LOBYTE(v192) = 44;
        v48 = _bstr_t::operator+(v47, &v127, &v159);
        if ( &v186 != v48 )
        {
          _bstr_t::_Free(&v186);
          v43 = v48->m_Data;
          v186.m_Data = v43;
          if ( v43 )
            InterlockedIncrement(&v43->m_RefCount);
        }
        v49 = v127;
        if ( v127 )
        {
          if ( !InterlockedDecrement(v127 + 2) && v49 )
          {
            if ( *v49 )
            {
              v6(*v49);
              *v49 = 0;
            }
            if ( *(v49 + 1) )
            {
              j_j__free(*(v49 + 1));
              *(v49 + 1) = 0;
            }
            j__free(v49);
          }
          v127 = 0;
        }
        v50 = v136;
        if ( v136 )
        {
          if ( !InterlockedDecrement(v136 + 2) && v50 )
          {
            if ( *v50 )
            {
              v6(*v50);
              *v50 = 0;
            }
            if ( *(v50 + 1) )
            {
              j_j__free(*(v50 + 1));
              *(v50 + 1) = 0;
            }
            j__free(v50);
          }
          v136 = 0;
        }
        v51 = v125;
        if ( v125 )
        {
          if ( !InterlockedDecrement(v125 + 2) && v51 )
          {
            if ( *v51 )
            {
              v6(*v51);
              *v51 = 0;
            }
            if ( *(v51 + 1) )
            {
              j_j__free(*(v51 + 1));
              *(v51 + 1) = 0;
            }
            j__free(v51);
          }
          v125 = 0;
        }
        v52 = v123.m_Data;
        if ( v123.m_Data )
        {
          if ( !InterlockedDecrement(&v123.m_Data->m_RefCount) && v52 )
          {
            if ( v52->m_wstr )
            {
              v6(v52->m_wstr);
              v52->m_wstr = 0;
            }
            if ( v52->m_str )
            {
              j_j__free(v52->m_str);
              v52->m_str = 0;
            }
            j__free(v52);
          }
          v123.m_Data = 0;
        }
        v53 = v158.m_Data;
        if ( v158.m_Data )
        {
          if ( !InterlockedDecrement(&v158.m_Data->m_RefCount) )
          {
            if ( v53->m_wstr )
            {
              v6(v53->m_wstr);
              v53->m_wstr = 0;
            }
            if ( v53->m_str )
            {
              j_j__free(v53->m_str);
              v53->m_str = 0;
            }
            j__free(v53);
          }
          v158.m_Data = 0;
        }
        v54 = v156.m_Data;
        if ( v156.m_Data )
        {
          if ( !InterlockedDecrement(&v156.m_Data->m_RefCount) )
          {
            if ( v54->m_wstr )
            {
              v6(v54->m_wstr);
              v54->m_wstr = 0;
            }
            if ( v54->m_str )
            {
              j_j__free(v54->m_str);
              v54->m_str = 0;
            }
            j__free(v54);
          }
          v156.m_Data = 0;
        }
        v55 = v159.m_Data;
        LOBYTE(v192) = 38;
        if ( v159.m_Data )
        {
          if ( !InterlockedDecrement(&v159.m_Data->m_RefCount) )
          {
            if ( v55->m_wstr )
            {
              v6(v55->m_wstr);
              v55->m_wstr = 0;
            }
            if ( v55->m_str )
            {
              j_j__free(v55->m_str);
              v55->m_str = 0;
            }
            j__free(v55);
          }
          v159.m_Data = 0;
        }
        v56 = _wcsdup(L"HKCR\\CLSID\\");
        lpszKeyName = v56;
        v57 = CPEString::Append(&v112.strValue[4], &lpszKeyName, lpszText2);
        v58 = v172;
        v100 = v57->m_String;
        v172 = _wcsdup(v100);
        free(v58);
        free(v112.strValue[4]);
        free(v56);
        if ( v43 )
          v59 = v43->m_wstr;
        else
          v59 = 0;
        v104 = &hKey;
        v60 = TlsGetValue(gdwTlsIndex);
        if ( PE_OpenKey(HKEY_CLASSES_ROOT, v59, 0, v60 | 1, v104) )
        {
          v61 = v43 ? v43->m_wstr : 0;
          if ( PE_OpenKey(HKEY_CLASSES_ROOT, v61, 0, 1u, &hKey) )
            goto LABEL_126;
        }
        ppszText2 = malloc(2u);
        *ppszText2 = 0;
        LOBYTE(v192) = 45;
        v62 = PE_ReadRegKey(hKey, &gszNullString, 0, 0, &ppszText2);
        if ( !v62 )
        {
          _bstr_t::operator=(&v186, ppszText2);
          v43 = v186.m_Data;
        }
        RegCloseKey(hKey);
        v104 = ppszText2;
        if ( !v62 )
          break;
        LOBYTE(v192) = 38;
        free(v104);
LABEL_126:
        v6 = SysFreeString;
        v44 = (v185 + 1);
        v185 = v44;
        if ( v44 >= 4 )
          goto LABEL_129;
      }
      free(v104);
LABEL_129:
      v112.strValue[0] = malloc(2u);
      *v112.strValue[0] = 0;
      v112.strValue[1] = 0;
      v112.strValue[2] = 0;
      v112.strValue[3] = 0;
      v175 = malloc(2u);
      *v175 = 0;
      v163 = malloc(2u);
      *v163 = 0;
      v184.m_String = malloc(2u);
      *v184.m_String = 0;
      v63 = -1;
      LOBYTE(v192) = 49;
      if ( v185 >= 4 )
      {
        _bstr_t::operator=(&v186, lpszText2);
        v43 = v186.m_Data;
        if ( v186.m_Data )
          v67 = v186.m_Data->m_wstr;
        else
          v67 = 0;
        sub_FD7040(v67, &v112);
      }
      else
      {
        if ( v43 )
          v64 = v43->m_wstr;
        else
          v64 = 0;
        sub_FD7040(v64, &v112);
        v65 = sub_FD4EE0(&v119, a1, &v112, 0);
        v66 = v184.m_String;
        v184.m_String = _wcsdup(*v65);
        free(v66);
        free(v119);
        v63 = sub_FD4ED0();
      }
      v155 = malloc(2u);
      *v155 = 0;
      if ( !wcslen(v184.m_String) )
        goto LABEL_243;
      if ( !v43 || (v68 = v43->m_wstr) == 0 )
        v68 = &gszNullString;
      v124 = _wcsdup(v68);
      v69 = &gszNullString;
      v70 = v187 | 1;
      if ( a3 )
        v69 = a3;
      v132 = _wcsdup(v69);
      v71 = v70 | 2;
      if ( !v43 || (v72 = v43->m_wstr) == 0 )
        v72 = &gszNullString;
      v118 = _wcsdup(v72);
      v192 = 53;
      v187 = v71 | 4;
      lpszKeyName = (v71 | 4);
      if ( sub_FD3D40(a1, &v118, &v132, &v124, &v184, &v175, &v155, &v152) )
        v73 = 1;
      else
LABEL_243:
        v73 = 0;
      v74 = v187;
      if ( v187 & 4 )
      {
        v187 &= 0xFFFFFFFB;
        free(v118);
        v74 = v187;
      }
      if ( v74 & 2 )
      {
        v187 = v74 & 0xFFFFFFFD;
        free(v132);
        v74 = v187;
      }
      v192 = 50;
      if ( v74 & 1 )
      {
        v187 = v74 & 0xFFFFFFFE;
        free(v124);
      }
      if ( v73 )
      {
        if ( *a2 == -1 )
        {
          v143 = _wcsdup(&gszNullString);
          v145 = _wcsdup(&gszNullString);
          v147 = _wcsdup(&gszNullString);
          v149 = _wcsdup(&gszNullString);
          v150 = _wcsdup(&gszNullString);
          v128.m_String = _wcsdup(&gszNullString);
          v75 = &gszNullString;
          if ( a3 )
            v75 = a3;
          v120.m_String = _wcsdup(v75);
          v76 = &gszNullString;
          if ( a3 )
            v76 = a3;
          v130.m_String = _wcsdup(v76);
          v77 = a1;
          LOBYTE(v192) = 61;
          v78 = sub_FD3FF0(a1, 2u, *a2, 0, &v130, &v120, &v128);
          v104 = v130.m_String;
          *a2 = v78;
          free(v104);
          free(v120.m_String);
          free(v128.m_String);
          free(v150);
          free(v149);
          free(v147);
          free(v145);
          free(v143);
        }
        else
        {
          v77 = a1;
        }
        psz = _wcsdup(&gszNullString);
        if ( !v43 || (v79 = v43->m_wstr) == 0 )
          v79 = &gszNullString;
        v179.m_String = _wcsdup(v79);
        if ( !v173 || (v80 = *v173) == 0 )
          v80 = &gszNullString;
        v176.m_String = _wcsdup(v80);
        v103 = -1;
        v102 = 0;
        v101 = 0;
        LOBYTE(v192) = 64;
        v100 = &psz;
        sub_FD3FF0(v77, v63, *a2, 9u, &v176, &v179, &v184);
        free(v176.m_String);
        free(v179.m_String);
        LOBYTE(v192) = 50;
        free(psz);
      }
      v104 = lpszPathName;
      (*(*lpszPathName + 8))(lpszPathName);
      free(v155);
      free(v184.m_String);
      free(v163);
      free(v175);
      sub_FD21F0(&v112);
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
      LOBYTE(v192) = 8;
      free(v172);
      v15 = v157;
LABEL_179:
      v104 = v182;
      (*(*v182 + 8))(v182);
      ++v15;
      v182 = 0;
      v104 = &v182;
      v157 = v15;
      v81 = *v174;
      v103 = (v15 + 1);
      v102 = v174;
      v6 = SysFreeString;
    }
    while ( (*(v81 + 32))(v174, v15 + 1, &v182) >= 0 );
    v7 = InterlockedDecrement;
LABEL_181:
    v104 = v174;
    (*(*v174 + 8))(v174);
LABEL_182:
    v104 = v161;
    (*(*v161 + 8))(v161);
LABEL_183:
    v6(bstrString);
    v82 = v173;
    LOBYTE(v192) = 0;
    if ( v173 )
    {
      if ( !v7(v173 + 2) && v82 )
      {
        if ( *v82 )
        {
          v6(*v82);
          *v82 = 0;
        }
        if ( *(v82 + 1) )
        {
          j_j__free(*(v82 + 1));
          *(v82 + 1) = 0;
        }
        j__free(v82);
      }
      v173 = 0;
    }
LABEL_192:
    v104 = v180;
    (*(*v180 + 8))(v180);
LABEL_193:
    v8 = v178;
  }
  while ( v178 < v183 );
  v5 = a5;
LABEL_195:
  v104 = v171;
  (*(*v171 + 8))(v171);
LABEL_196:
  v83 = *v5;
  v104 = &v166;
  v103 = 0;
  v102 = v5;
  v166 = 0;
  if ( (*(v83 + 40))(v5, 0, &v166) >= 0 )
  {
    for ( i = 1; ; i = (v176.m_String + 1) )
    {
      v176.m_String = i;
      a5 = 0;
      pvarg.vt = 3;
      pvarg.lVal = i;
      v85 = _mm_loadu_si128(&pvarg);
      v104 = &a5;
      LOBYTE(v192) = 65;
      v86 = *v166;
      v87 = v166;
      _mm_storeu_si128(&v100, v85);
      v88 = (*(v86 + 32))(v87, v100, v101, v102, v103, v104);
      LOBYTE(v192) = 0;
      VariantClear(&pvarg);
      if ( v88 < 0 )
        break;
      psz = 0;
      v104 = &psz;
      v103 = a5;
      (*(*a5 + 28))(a5, &psz);
      v89 = psz;
      v90 = operator new(0xCu);
      v91 = v90;
      v178 = v90;
      LOBYTE(v192) = 66;
      if ( v90 )
      {
        v104 = v89;
        *(v90 + 1) = 0;
        *(v90 + 2) = 1;
        v92 = SysAllocString(v104);
        *v91 = v92;
        if ( !v92 && v89 )
          goto LABEL_202;
      }
      else
      {
        v91 = 0;
      }
      LOBYTE(v192) = 0;
      v152 = v91;
      if ( !v91 )
        goto LABEL_202;
      LOBYTE(v192) = 67;
      v93 = operator new(0xCu);
      v94 = v93;
      v178 = v93;
      LOBYTE(v192) = 68;
      if ( v93 )
      {
        v104 = L"\\";
        v93[1] = 0;
        v93[2] = 1;
        v95 = SysAllocString(v104);
        *v94 = v95;
        if ( !v95 )
          goto LABEL_202;
      }
      else
      {
        v94 = 0;
      }
      LOBYTE(v192) = 67;
      v178 = v94;
      if ( !v94 )
LABEL_202:
        _com_issue_error(-2147024882);
      v104 = a5;
      LOBYTE(v192) = 69;
      v96 = _bstr_t::operator+(&a4, &v179, &v178);
      v103 = v97;
      LOBYTE(v192) = 70;
      _bstr_t::operator+(v96, &v103, &v152);
      sub_FEF260(a1, a2, a3, v103, v104);
      v183 = v179.m_String;
      if ( v179.m_String )
      {
        if ( !InterlockedDecrement(v179.m_String + 2) )
        {
          v98 = v183;
          if ( v183 )
          {
            if ( *v183 )
            {
              v6(*v183);
              v98 = v183;
              *v183 = 0;
            }
            if ( v98[1] )
            {
              j_j__free(v98[1]);
              v98 = v183;
              *(v183 + 1) = 0;
            }
            j__free(v98);
          }
        }
        v179.m_String = 0;
      }
      if ( !InterlockedDecrement(v94 + 2) )
      {
        if ( *v94 )
        {
          v6(*v94);
          *v94 = 0;
        }
        if ( v94[1] )
        {
          j_j__free(v94[1]);
          v94[1] = 0;
        }
        j__free(v94);
      }
      LOBYTE(v192) = 0;
      if ( !InterlockedDecrement(v91 + 2) )
      {
        if ( *v91 )
        {
          v6(*v91);
          *v91 = 0;
        }
        if ( *(v91 + 1) )
        {
          j_j__free(*(v91 + 1));
          *(v91 + 1) = 0;
        }
        j__free(v91);
      }
      v104 = a5;
      (*(*a5 + 8))(a5);
    }
    v104 = v166;
    (*(*v166 + 8))(v166);
    v7 = InterlockedDecrement;
  }
  v99 = a4;
  if ( a4 && !v7(a4 + 2) && v99 )
  {
    if ( *v99 )
    {
      v6(*v99);
      *v99 = 0;
    }
    if ( *(v99 + 1) )
    {
      j_j__free(*(v99 + 1));
      *(v99 + 1) = 0;
    }
    j__free(v99);
  }
}