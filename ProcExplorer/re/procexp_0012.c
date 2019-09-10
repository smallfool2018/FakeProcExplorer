
//----- (00F88050) --------------------------------------------------------
void *__cdecl sub_F88050(int a1, HKEY hKey, LPCWSTR lpszKeyName, HANDLE Handle)
{
  const wchar_t *v4; // eax
  const wchar_t *v5; // eax
  unsigned __int16 **v6; // esi
  unsigned __int16 **v7; // eax
  LPVOID (__stdcall *TlsGetValue)(DWORD); // ebx
  unsigned __int32 v9; // ST54_4
  void (__stdcall *v10)(HKEY); // edi
  WCHAR *v11; // esi
  tagKeyName *v12; // esi
  unsigned int v13; // eax
  tagKeyName *v14; // esi
  unsigned int v15; // eax
  int v16; // eax
  bool v17; // bl
  WCHAR *v18; // eax
  const wchar_t **v19; // eax
  wchar_t *v20; // esi
  const wchar_t **v21; // eax
  void *v22; // esi
  tagKeyName *v23; // esi
  unsigned int v24; // eax
  const wchar_t **v25; // eax
  WCHAR *v26; // esi
  WCHAR *v27; // esi
  unsigned __int16 **v28; // eax
  wchar_t *v29; // edi
  WCHAR *v30; // esi
  tagKeyName *v31; // esi
  unsigned int v32; // eax
  WCHAR *v33; // esi
  const wchar_t *v34; // eax
  const wchar_t *v35; // eax
  unsigned __int16 **v36; // esi
  unsigned __int16 **v37; // eax
  char v38; // bl
  LPCWSTR v39; // ebx
  const wchar_t *v40; // eax
  const wchar_t *v41; // eax
  unsigned __int16 **v42; // esi
  unsigned __int16 **v43; // eax
  const WCHAR **v44; // eax
  unsigned __int16 **v45; // eax
  WCHAR *v46; // esi
  void **v47; // esi
  void **v48; // ebx
  DWORD cbData; // [esp+10h] [ebp-CCh]
  WCHAR *ppv1; // [esp+14h] [ebp-C8h]
  WCHAR *pszResult; // [esp+18h] [ebp-C4h]
  WCHAR v53[2]; // [esp+1Ch] [ebp-C0h]
  WCHAR v54[2]; // [esp+20h] [ebp-BCh]
  WCHAR *ppv; // [esp+24h] [ebp-B8h]
  int a2; // [esp+28h] [ebp-B4h]
  WCHAR v57[2]; // [esp+2Ch] [ebp-B0h]
  int v58; // [esp+30h] [ebp-ACh]
  WCHAR *v59; // [esp+34h] [ebp-A8h]
  WCHAR v60[2]; // [esp+38h] [ebp-A4h]
  WCHAR *v61; // [esp+3Ch] [ebp-A0h]
  WCHAR v62[2]; // [esp+40h] [ebp-9Ch]
  void *v63; // [esp+44h] [ebp-98h]
  WCHAR *ppv2; // [esp+48h] [ebp-94h]
  void *v65; // [esp+4Ch] [ebp-90h]
  BYTE Data[4]; // [esp+50h] [ebp-8Ch]
  void *v67; // [esp+54h] [ebp-88h]
  void *v68; // [esp+58h] [ebp-84h]
  void *v69; // [esp+5Ch] [ebp-80h]
  LPCWSTR v70; // [esp+60h] [ebp-7Ch]
  void *v71; // [esp+64h] [ebp-78h]
  LPCWSTR v72; // [esp+68h] [ebp-74h]
  void *v73; // [esp+6Ch] [ebp-70h]
  void *v74; // [esp+70h] [ebp-6Ch]
  void *v75; // [esp+74h] [ebp-68h]
  WCHAR *a1a; // [esp+78h] [ebp-64h]
  LPCWSTR v77; // [esp+7Ch] [ebp-60h]
  WCHAR *szArg; // [esp+80h] [ebp-5Ch]
  HKEY KeyHandle; // [esp+84h] [ebp-58h]
  void *v80; // [esp+88h] [ebp-54h]
  void *v81; // [esp+8Ch] [ebp-50h]
  void *v82; // [esp+90h] [ebp-4Ch]
  void *v83; // [esp+94h] [ebp-48h]
  void **v84; // [esp+98h] [ebp-44h]
  int v85; // [esp+9Ch] [ebp-40h]
  LPCWSTR szArg4; // [esp+A0h] [ebp-3Ch]
  LPCWSTR v87; // [esp+A4h] [ebp-38h]
  LPCWSTR v88; // [esp+A8h] [ebp-34h]
  LPCWSTR v89; // [esp+ACh] [ebp-30h]
  LPCWSTR v90; // [esp+B0h] [ebp-2Ch]
  LPCWSTR v91; // [esp+B4h] [ebp-28h]
  WCHAR *ppv3; // [esp+B8h] [ebp-24h]
  bool v93; // [esp+BFh] [ebp-1Dh]
  LPCWSTR szArg3; // [esp+C0h] [ebp-1Ch]
  HKEY hKeya; // [esp+C4h] [ebp-18h]
  wchar_t *pszText; // [esp+C8h] [ebp-14h]
  HKEY__ v97; // [esp+CCh] [ebp-10h]
  int v98; // [esp+D8h] [ebp-4h]

  ppv3 = malloc(2u);
  *ppv3 = 0;
  v98 = 0;
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
  LOBYTE(v98) = 5;
  *Data = 0;
  if ( Handle == -1 )
  {
    v87 = _wcsdup(&gszNullString);
    szArg4 = _wcsdup(&gszNullString);
    v88 = _wcsdup(&gszNullString);
    v90 = _wcsdup(&gszNullString);
    v91 = _wcsdup(&gszNullString);
    v89 = _wcsdup(&gszNullString);
    v97.unused = _wcsdup(&gszNullString);
    v4 = &gszNullString;
    if ( lpszKeyName )
      v4 = lpszKeyName;
    pszText = _wcsdup(v4);
    hKeya = _wcsdup(&gszNullString);
    v5 = &gszNullString;
    if ( lpszKeyName )
      v5 = lpszKeyName;
    szArg3 = _wcsdup(v5);
    LOBYTE(v98) = 15;
    v6 = sub_F77BE0(&a1a, hKey, &pszText, &v97);
    LOBYTE(v98) = 16;
    v7 = sub_F77BE0(&szArg, hKey, &szArg3, &hKeya);
    LOBYTE(v98) = 17;
    Handle = sub_F73FF0(a1, 0, 0xFFFFFFFF, 0, v7, v6, &v89);
    free(szArg);
    free(a1a);
    free(szArg3);
    free(hKeya);
    free(pszText);
    free(v97.unused);
    free(v89);
    free(v91);
    free(v90);
    free(v88);
    free(szArg4);
    LOBYTE(v98) = 5;
    free(v87);
  }
  TlsGetValue = ::TlsGetValue;
  v9 = ::TlsGetValue(gdwTlsIndex) | KEY_READ;
  if ( !PE_OpenKey(hKey, lpszKeyName, 0, v9, &KeyHandle) )
  {
    szArg = 0;
    pszText = malloc(2u);
    *pszText = 0;
    v97.unused = malloc(2u);
    *v97.unused = 0;
    szArg3 = malloc(2u);
    *szArg3 = 0;
    v82 = malloc(2u);
    *v82 = 0;
    v83 = 0;
    v84 = 0;
    v85 = 0;
    LOBYTE(v98) = 21;
    v10 = RegCloseKey;
    if ( !PE_LoadKey(KeyHandle, 0, &v97) )
    {
      while ( 1 )
      {
        v11 = v77;
        v77 = _wcsdup(v97.unused);
        free(v11);
        v12 = v97.unused;
        v13 = TlsGetValue(gdwTlsIndex);
        if ( !PE_OpenKey(KeyHandle, v12, 0, v13 | KEY_READ, &hKeya) )
        {
          RegQueryValueExW(hKeya, L"LoadBehavior", 0, 0, Data, &cbData);
          v10(hKeya);
        }
        v93 = *Data > 1u;
        v14 = *PE_CopyString(&ppv, &v97, L"\\CLSID");
        LOBYTE(v98) = 22;
        v15 = TlsGetValue(gdwTlsIndex);
        v16 = PE_OpenKey(HKEY_CLASSES_ROOT, v14, 0, v15 | KEY_READ, &hKeya);
        LOBYTE(v98) = 21;
        v17 = v16 == 0;
        free(ppv);
        if ( !v17 )
          goto LABEL_39;
        if ( sub_F81520(hKeya, &gszNullString, 0, 0, &v97) )
          break;
        v10(hKeya);
        v18 = PE_CopyString2(&pszResult, L"CLSID\\", &v97);
        v19 = PE_CopyString(&v59, v18, L"\\InprocServer32");
        v20 = pszText;
        pszText = _wcsdup(*v19);
        free(v20);
        free(v59);
        free(pszResult);
        v21 = PE_CopyString2(&v61, L"HKCR\\CLSID\\", &v97);
        v22 = v80;
        v80 = _wcsdup(*v21);
        free(v22);
        free(v61);
        v23 = pszText;
        TlsGetValue = ::TlsGetValue;
        v24 = ::TlsGetValue(gdwTlsIndex);
        if ( PE_OpenKey(HKEY_CLASSES_ROOT, v23, 0, v24 | 0x20019, &hKeya) )
          goto LABEL_16;
        if ( !sub_F81520(hKeya, &gszNullString, 0, 0, &pszText) )
        {
          sub_F77040(pszText, &v82);
          v25 = sub_F74EE0(&v63, a1, &v82, 0);
          v26 = szArg3;
          szArg3 = _wcsdup(*v25);
          free(v26);
          free(v63);
          v10(hKeya);
LABEL_16:
          a2 = sub_F74ED0();
          v27 = _wcsdup(L"CLSID\\");
          ppv2 = v27;
          v28 = PE_CopyStringEx(&ppv1, &ppv2, &v97);
          v29 = pszText;
          pszText = _wcsdup(*v28);
          free(v29);
          free(ppv1);
          free(v27);
          v30 = ppv3;
          ppv3 = _wcsdup(v97.unused);
          free(v30);
          v31 = pszText;
          v32 = ::TlsGetValue(gdwTlsIndex);
          if ( PE_OpenKey(HKEY_CLASSES_ROOT, v31, 0, v32 | 0x20019, &hKeya) )
          {
            v10 = RegCloseKey;
          }
          else
          {
            if ( !sub_F81520(hKeya, &gszNullString, 0, 0, &pszText) && wcslen(pszText) )
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
          v88 = _wcsdup(v34);
          szArg4 = _wcsdup(&gszNullString);
          v35 = &gszNullString;
          if ( lpszKeyName )
            v35 = lpszKeyName;
          v87 = _wcsdup(v35);
          LOBYTE(v98) = 25;
          v36 = sub_F77BE0(v53, hKey, &v88, &v97);
          LOBYTE(v98) = 26;
          v37 = sub_F77BE0(v57, hKey, &v87, &szArg4);
          LOBYTE(v98) = 27;
          v38 = sub_F73D40(a1, &ppv3, v37, v36, &szArg3, &v81, &v75, &v58);
          free(*v57);
          free(*v53);
          free(v87);
          free(szArg4);
          free(v88);
          if ( v38 )
          {
            if ( Handle == -1 )
            {
              v65 = _wcsdup(&gszNullString);
              v69 = _wcsdup(&gszNullString);
              v67 = _wcsdup(&gszNullString);
              v73 = _wcsdup(&gszNullString);
              v71 = _wcsdup(&gszNullString);
              v68 = _wcsdup(&gszNullString);
              v70 = _wcsdup(&gszNullString);
              v39 = lpszKeyName;
              v40 = &gszNullString;
              if ( lpszKeyName )
                v40 = lpszKeyName;
              v89 = _wcsdup(v40);
              v91 = _wcsdup(&gszNullString);
              v41 = &gszNullString;
              if ( lpszKeyName )
                v41 = lpszKeyName;
              v90 = _wcsdup(v41);
              LOBYTE(v98) = 37;
              v42 = sub_F77BE0(v60, hKey, &v89, &v70);
              LOBYTE(v98) = 38;
              v43 = sub_F77BE0(v62, hKey, &v90, &v91);
              LOBYTE(v98) = 39;
              Handle = sub_F73FF0(a1, 0, 0xFFFFFFFF, 0, v43, v42, &v68);
              free(*v62);
              free(*v60);
              free(v90);
              free(v91);
              free(v89);
              free(v70);
              free(v68);
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
            LOBYTE(v98) = 41;
            v45 = sub_F77BE0(v54, hKey, &v72, &v77);
            LOBYTE(v98) = 42;
            sub_F73FF0(a1, a2, Handle, 18, &ppv3, v45, &szArg3);
            free(*v54);
            free(v72);
            free(a1a);
          }
LABEL_39:
          sub_F721F0(&v82);
          free(szArg3);
          free(v97.unused);
          free(pszText);
          TlsGetValue = ::TlsGetValue;
          goto LABEL_40;
        }
        v10(hKeya);
        sub_F721F0(&v82);
        free(szArg3);
        free(v97.unused);
        free(pszText);
LABEL_40:
        szArg = (szArg + 1);
        v46 = szArg;
        pszText = malloc(2u);
        *pszText = 0;
        v97.unused = malloc(2u);
        *v97.unused = 0;
        szArg3 = malloc(2u);
        *szArg3 = 0;
        v82 = malloc(2u);
        *v82 = 0;
        v83 = 0;
        v84 = 0;
        v85 = 0;
        LOBYTE(v98) = 21;
        if ( PE_LoadKey(KeyHandle, v46, &v97) )
          goto LABEL_41;
      }
      v10(hKeya);
      goto LABEL_39;
    }
LABEL_41:
    v47 = v83;
    if ( v83 )
    {
      v48 = v84;
      if ( v83 != v84 )
      {
        do
        {
          free(*v47);
          ++v47;
        }
        while ( v47 != v48 );
        v47 = v83;
      }
      j__free(v47);
      v83 = 0;
      v84 = 0;
      v85 = 0;
    }
    free(v82);
    free(szArg3);
    free(v97.unused);
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

//----- (00F88A90) --------------------------------------------------------
void __cdecl sub_F88A90(int a1, void *a2, int a3, int a4)
{
  wchar_t *v4; // esi
  void *v5; // ebx
  const wchar_t **v6; // eax
  wchar_t *v7; // edi
  HKEY hKey; // [esp+14h] [ebp-10h]
  int v9; // [esp+20h] [ebp-4h]

  v4 = malloc(2u);
  *v4 = 0;
  v9 = 0;
  if ( byte_1064C58 )
  {
LABEL_10:
    v5 = sub_F88C20(a1, a2, *a3, 0xFFFFFFFF, 1, a4);
    v6 = PE_CopyString(&hKey, a3, L"\\AutorunsDisabled");
    v7 = v4;
    v4 = _wcsdup(*v6);
    free(v7);
    free(hKey);
    sub_F88C20(a1, a2, v4, v5, 0, a4);
    goto LABEL_11;
  }
  if ( !PE_OpenKey(ghLocalMachineKey, L"SYSTEM\\CurrentControlSet\\Control\\Print", 0, 0x20019u, &hKey)
    || !dword_1063628[0] )
  {
    if ( !PE_OpenKey(
            ghLocalMachineKey,
            L"SYSTEM\\CurrentControlSet\\Control\\Print\\Environments\\Windows NT x86",
            0,
            0x20019u,
            &hKey) )
    {
      sub_F81520(hKey, L"Directory", 0, 0, &dword_4F4C50);
      RegCloseKey(hKey);
    }
    if ( !PE_OpenKey(
            ghLocalMachineKey,
            L"SYSTEM\\CurrentControlSet\\Control\\Print\\Environments\\Windows x64",
            0,
            0x20019u,
            &hKey) )
    {
      sub_F81520(hKey, L"Directory", 0, 0, &dword_4F4C54);
      RegCloseKey(hKey);
    }
    byte_1064C58 = 1;
    goto LABEL_10;
  }
  wprintf(L"\nNo entry to display for printer. Printer is not supported on Nano Server.\n");
LABEL_11:
  free(v4);
}
// 1063628: using guessed type int dword_1063628[140];
// 1064C58: using guessed type char byte_1064C58;

//----- (00F88C20) --------------------------------------------------------
void *__cdecl sub_F88C20(int a1, void *a2, wchar_t *psz, void *a4, char a5, int a6)
{
  wchar_t *v6; // edi
  int v7; // ebx
  const wchar_t *v8; // eax
  const wchar_t *v9; // eax
  unsigned __int16 **v10; // esi
  unsigned __int16 **v11; // eax
  unsigned int v12; // eax
  tagKeyName *v13; // esi
  unsigned int v14; // eax
  const wchar_t **v15; // eax
  void *v16; // esi
  WCHAR **v17; // edi
  WCHAR *v18; // esi
  LPCWSTR *v19; // eax
  unsigned __int16 **v20; // eax
  wchar_t *v21; // esi
  const wchar_t **v22; // eax
  wchar_t *v23; // edi
  void *v24; // edi
  const WCHAR **v25; // ecx
  const WCHAR **v26; // eax
  unsigned __int16 **v27; // esi
  unsigned __int16 **v28; // eax
  char v29; // bl
  const WCHAR **v30; // eax
  const WCHAR **v31; // eax
  unsigned __int16 **v32; // esi
  unsigned __int16 **v33; // eax
  const WCHAR **v34; // eax
  unsigned __int16 **v35; // eax
  int v37; // [esp+10h] [ebp-B0h]
  int v38; // [esp+14h] [ebp-ACh]
  int v39; // [esp+18h] [ebp-A8h]
  int v40; // [esp+1Ch] [ebp-A4h]
  WCHAR *pszResult; // [esp+20h] [ebp-A0h]
  WCHAR v42[2]; // [esp+24h] [ebp-9Ch]
  void *v43; // [esp+28h] [ebp-98h]
  int v44; // [esp+2Ch] [ebp-94h]
  WCHAR v45[2]; // [esp+30h] [ebp-90h]
  WCHAR v46[2]; // [esp+34h] [ebp-8Ch]
  void *v47; // [esp+38h] [ebp-88h]
  WCHAR v48[2]; // [esp+3Ch] [ebp-84h]
  WCHAR *ppv1; // [esp+40h] [ebp-80h]
  WCHAR v50[2]; // [esp+44h] [ebp-7Ch]
  wchar_t *ppv; // [esp+48h] [ebp-78h]
  LPCWSTR v52; // [esp+4Ch] [ebp-74h]
  void *v53; // [esp+50h] [ebp-70h]
  DWORD v54; // [esp+54h] [ebp-6Ch]
  void *v55; // [esp+58h] [ebp-68h]
  HKEY hKey; // [esp+5Ch] [ebp-64h]
  void *v57; // [esp+60h] [ebp-60h]
  WCHAR *ppv3; // [esp+64h] [ebp-5Ch]
  void *v59; // [esp+68h] [ebp-58h]
  void *v60; // [esp+6Ch] [ebp-54h]
  void *a1a; // [esp+70h] [ebp-50h]
  void *v62; // [esp+74h] [ebp-4Ch]
  HKEY hRootKey; // [esp+78h] [ebp-48h]
  WCHAR szArg[2]; // [esp+7Ch] [ebp-44h]
  LPCWSTR v65; // [esp+80h] [ebp-40h]
  LPCWSTR v66; // [esp+84h] [ebp-3Ch]
  LPCWSTR v67; // [esp+88h] [ebp-38h]
  LPCWSTR v68; // [esp+8Ch] [ebp-34h]
  LPCWSTR szArg3; // [esp+90h] [ebp-30h]
  LPCWSTR szArg4; // [esp+94h] [ebp-2Ch]
  LPCWSTR v71; // [esp+98h] [ebp-28h]
  LPCWSTR v72; // [esp+9Ch] [ebp-24h]
  LPCWSTR v73; // [esp+A0h] [ebp-20h]
  WCHAR *pszText; // [esp+A4h] [ebp-1Ch]
  void *v75; // [esp+A8h] [ebp-18h]
  LPCWSTR lpszKeyName; // [esp+ACh] [ebp-14h]
  WCHAR szText2[2]; // [esp+B0h] [ebp-10h]
  int v78; // [esp+BCh] [ebp-4h]

  v54 = 0;
  *szText2 = malloc(2u);
  **szText2 = 0;
  v78 = 0;
  v75 = malloc(2u);
  *v75 = 0;
  v62 = malloc(2u);
  *v62 = 0;
  v59 = malloc(2u);
  *v59 = 0;
  v60 = malloc(2u);
  *v60 = 0;
  v6 = psz;
  v7 = a1;
  LOBYTE(v78) = 4;
  if ( a4 == -1 )
  {
    v66 = _wcsdup(&gszNullString);
    v65 = _wcsdup(&gszNullString);
    v67 = _wcsdup(&gszNullString);
    v71 = _wcsdup(&gszNullString);
    v72 = _wcsdup(&gszNullString);
    v73 = _wcsdup(&gszNullString);
    szArg4 = _wcsdup(&gszNullString);
    v8 = &gszNullString;
    if ( psz )
      v8 = psz;
    pszText = _wcsdup(v8);
    v68 = _wcsdup(&gszNullString);
    v9 = &gszNullString;
    if ( psz )
      v9 = psz;
    szArg3 = _wcsdup(v9);
    LOBYTE(v78) = 14;
    v10 = sub_F77BE0(&a1a, a2, &pszText, &szArg4);
    LOBYTE(v78) = 15;
    v11 = sub_F77BE0(szArg, a2, &szArg3, &v68);
    LOBYTE(v78) = 16;
    a4 = sub_F73FF0(a1, 0, 0xFFFFFFFF, 0, v11, v10, &v73);
    free(*szArg);
    free(a1a);
    free(szArg3);
    free(v68);
    free(pszText);
    free(szArg4);
    free(v73);
    free(v72);
    free(v71);
    free(v67);
    free(v65);
    LOBYTE(v78) = 4;
    free(v66);
  }
  v12 = TlsGetValue(gdwTlsIndex);
  if ( !PE_OpenKey(ghLocalMachineKey, psz, 0, v12 | 0x20019, &hRootKey) )
  {
    lpszKeyName = malloc(2u);
    *lpszKeyName = 0;
    LOBYTE(v78) = 17;
    if ( !PE_LoadKey(hRootKey, 0, &lpszKeyName) )
    {
      do
      {
        v13 = lpszKeyName;
        v14 = TlsGetValue(gdwTlsIndex);
        if ( !PE_OpenKey(hRootKey, v13, 0, v14 | 0x20019, &hKey) )
        {
          if ( !sub_F81520(hKey, L"Driver", 0, 0, szText2) )
          {
            v37 = malloc(2u);
            *v37 = 0;
            v38 = 0;
            v39 = 0;
            v40 = 0;
            LOBYTE(v78) = 18;
            sub_F77040(*szText2, &v37);
            *szArg = _wcsdup(*szText2);
            LOBYTE(v78) = 19;
            v15 = sub_F74EE0(&v47, v7, &v37, 0);
            v16 = v75;
            v75 = _wcsdup(*v15);
            free(v16);
            free(v47);
            if ( !wcschr(*szText2, 0x5Cu) )
            {
              v17 = &dword_4F4C54;
              if ( !a6 )
                v17 = &dword_4F4C50;
              v18 = _wcsdup(L"\\");
              ppv3 = v18;
              v19 = PE_CopyString2(&pszResult, L"\\SystemRoot\\System32\\Spool\\Prtprocs\\", v17);
              v20 = PE_CopyStringEx(&ppv1, v19, &ppv3);
              PE_CopyStringEx(&ppv, v20, szText2);
              LOBYTE(v78) = 20;
              free(ppv1);
              free(pszResult);
              free(v18);
              v21 = ppv;
              v22 = sub_F74F20(&v43, v7, ppv);
              v23 = *szText2;
              *szText2 = _wcsdup(*v22);
              free(v23);
              free(v43);
              if ( wcsncmp(*szText2, L"File not found: ", 0x10u) )
              {
                v24 = v75;
                v75 = _wcsdup(*szText2);
                free(v24);
              }
              LOBYTE(v78) = 19;
              free(v21);
              v6 = psz;
            }
            ppv3 = sub_F74ED0();
            v25 = &gszNullString;
            if ( v6 )
              v25 = v6;
            v67 = _wcsdup(v25);
            v65 = _wcsdup(&gszNullString);
            v26 = &gszNullString;
            if ( v6 )
              v26 = v6;
            v66 = _wcsdup(v26);
            LOBYTE(v78) = 23;
            v27 = sub_F77BE0(v50, a2, &v67, &lpszKeyName);
            LOBYTE(v78) = 24;
            v28 = sub_F77BE0(v45, a2, &v66, &v65);
            LOBYTE(v78) = 25;
            v29 = sub_F73D40(v7, &lpszKeyName, v28, v27, &v75, &v62, &v60, &v44);
            free(*v45);
            free(*v50);
            free(v66);
            free(v65);
            free(v67);
            if ( v29 )
            {
              if ( a4 == -1 )
              {
                v53 = _wcsdup(&gszNullString);
                v57 = _wcsdup(&gszNullString);
                v55 = _wcsdup(&gszNullString);
                szArg3 = _wcsdup(&gszNullString);
                v68 = _wcsdup(&gszNullString);
                pszText = _wcsdup(&gszNullString);
                szArg4 = _wcsdup(&gszNullString);
                v30 = &gszNullString;
                if ( v6 )
                  v30 = v6;
                v73 = _wcsdup(v30);
                v72 = _wcsdup(&gszNullString);
                v31 = &gszNullString;
                if ( v6 )
                  v31 = v6;
                v71 = _wcsdup(v31);
                LOBYTE(v78) = 35;
                v32 = sub_F77BE0(v46, a2, &v73, &szArg4);
                LOBYTE(v78) = 36;
                v33 = sub_F77BE0(v48, a2, &v71, &v72);
                LOBYTE(v78) = 37;
                v7 = a1;
                a4 = sub_F73FF0(a1, 0, 0xFFFFFFFF, 0, v33, v32, &pszText);
                free(*v48);
                free(*v46);
                free(v71);
                free(v72);
                free(v73);
                free(szArg4);
                free(pszText);
                free(v68);
                free(szArg3);
                free(v55);
                free(v57);
                free(v53);
              }
              else
              {
                v7 = a1;
              }
              a1a = _wcsdup(&gszNullString);
              v34 = &gszNullString;
              if ( v6 )
                v34 = v6;
              v52 = _wcsdup(v34);
              LOBYTE(v78) = 39;
              v35 = sub_F77BE0(v42, a2, &v52, &lpszKeyName);
              LOBYTE(v78) = 40;
              sub_F73FF0(v7, ppv3, a4, 3, &lpszKeyName, v35, &v75);
              free(*v42);
              free(v52);
              free(a1a);
            }
            else
            {
              v7 = a1;
            }
            free(*szArg);
            LOBYTE(v78) = 17;
            sub_F721F0(&v37);
          }
          RegCloseKey(hKey);
        }
        ++v54;
      }
      while ( !PE_LoadKey(hRootKey, v54, &lpszKeyName) );
    }
    RegCloseKey(hRootKey);
    free(lpszKeyName);
  }
  free(v60);
  free(v59);
  free(v62);
  free(v75);
  free(*szText2);
  return a4;
}

//----- (00F893C0) --------------------------------------------------------
char __cdecl sub_F893C0(LPCWSTR lpServiceName, int a2)
{
  char v2; // bl
  SC_HANDLE v3; // eax
  void *v4; // edi
  SC_HANDLE v5; // esi
  FARPROC v7; // eax
  HMODULE v8; // eax
  size_t v9; // ST0C_4
  wchar_t **v10; // esi
  wchar_t *v11; // edx
  wchar_t *v12; // ecx
  wchar_t v13; // ax
  wchar_t *v14; // ecx
  wchar_t v15; // ax
  wchar_t *v16; // ecx
  wchar_t v17; // ax
  wchar_t *v18; // edx
  wchar_t *v19; // ecx
  wchar_t v20; // ax
  wchar_t *v21; // ecx
  wchar_t v22; // ax
  SC_HANDLE v23; // [esp+14h] [ebp-14h]
  size_t v24; // [esp+18h] [ebp-10h]
  int v25; // [esp+24h] [ebp-4h]

  v25 = 0;
  v2 = 0;
  v3 = OpenSCManagerW(0, 0, 0x80000000);
  v4 = v3;
  if ( !v3 )
    goto LABEL_4;
  v5 = OpenServiceW(v3, lpServiceName, 1u);
  v23 = v5;
  if ( !v5 )
  {
    CloseServiceHandle(v4);
LABEL_4:
    v2 = 0;
    goto LABEL_5;
  }
  v7 = QueryServiceConfig2W_0;
  v24 = 0;
  if ( QueryServiceConfig2W_0
    || (v8 = LoadLibraryW(L"Advapi32.dll"),
        v7 = GetProcAddress(v8, "QueryServiceConfig2W"),
        (QueryServiceConfig2W_0 = v7) != 0) )
  {
    if ( !(v7)(v5, 1, 0, 0, &v24) )
    {
      v9 = v24;
      v10 = malloc(v24);
      if ( QueryServiceConfig2W_0(v23, 1, v10, v9, &v24) )
      {
        v11 = *v10;
        if ( *v10 )
        {
          v12 = *v10;
          do
          {
            v13 = *v12;
            ++v12;
          }
          while ( v13 );
          if ( (v12 - (v11 + 1)) > 3 )
          {
            v14 = *v10;
            do
            {
              v15 = *v14;
              ++v14;
            }
            while ( v15 );
            if ( v11[v14 - (v11 + 1) - 1] == 10 )
            {
              v16 = *v10;
              do
              {
                v17 = *v16;
                ++v16;
              }
              while ( v17 );
              v11[v16 - (v11 + 1) - 1] = 0;
              v18 = *v10;
              v19 = *v10;
              do
              {
                v20 = *v19;
                ++v19;
              }
              while ( v20 );
              if ( v18[v19 - (*v10 + 1) - 1] == 13 )
              {
                v21 = *v10;
                do
                {
                  v22 = *v21;
                  ++v21;
                }
                while ( v22 );
                v18[v21 - (v18 + 1) - 1] = 0;
              }
            }
          }
        }
        sub_F72280(a2, *v10);
        v2 = 1;
      }
      free(v10);
      v5 = v23;
    }
  }
  CloseServiceHandle(v5);
  CloseServiceHandle(v4);
LABEL_5:
  free(lpServiceName);
  return v2;
}
// 1064C5C: using guessed type int (__stdcall *QueryServiceConfig2W_0)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD);

//----- (00F89580) --------------------------------------------------------
void *__cdecl sub_F89580(int a1, void *a2, wchar_t *psz)
{
  std__List *v3; // eax
  WCHAR *v4; // eax
  WCHAR *v5; // eax
  _WORD *v6; // eax
  _WORD *v7; // eax
  _WORD *v8; // eax
  _WORD *v9; // eax
  _WORD *v10; // eax
  wchar_t *v11; // ebx
  const wchar_t *v12; // eax
  const wchar_t *v13; // eax
  unsigned __int16 **v14; // esi
  unsigned __int16 **v15; // eax
  void *v16; // esi
  LSTATUS (__stdcall *v17)(HKEY, LPCWSTR, LPDWORD, LPDWORD, LPBYTE, LPDWORD); // esi
  void *v18; // esi
  void *v19; // esi
  const wchar_t **v20; // eax
  void *v21; // esi
  void *v22; // esi
  const wchar_t **v23; // eax
  void *v24; // esi
  const wchar_t **v25; // eax
  void *v26; // esi
  wchar_t *v27; // eax
  const wchar_t **v28; // eax
  wchar_t *v29; // eax
  WCHAR *v30; // esi
  const WCHAR **v31; // eax
  const WCHAR **v32; // eax
  unsigned __int16 **v33; // esi
  unsigned __int16 **v34; // eax
  char v35; // bl
  const wchar_t *v36; // eax
  const wchar_t *v37; // eax
  unsigned __int16 **v38; // esi
  unsigned __int16 **v39; // eax
  const WCHAR **v40; // eax
  unsigned __int16 **v41; // eax
  int a2a; // [esp+10h] [ebp-F4h]
  int v44; // [esp+20h] [ebp-E4h]
  int v45; // [esp+30h] [ebp-D4h]
  int v46; // [esp+34h] [ebp-D0h]
  int v47; // [esp+38h] [ebp-CCh]
  int v48; // [esp+3Ch] [ebp-C8h]
  WCHAR v49[2]; // [esp+40h] [ebp-C4h]
  BYTE v50[4]; // [esp+44h] [ebp-C0h]
  BYTE v51[4]; // [esp+48h] [ebp-BCh]
  void *v52; // [esp+50h] [ebp-B4h]
  WCHAR v53[2]; // [esp+54h] [ebp-B0h]
  WCHAR v54[2]; // [esp+58h] [ebp-ACh]
  void *v55; // [esp+5Ch] [ebp-A8h]
  void *v56; // [esp+60h] [ebp-A4h]
  int v57; // [esp+64h] [ebp-A0h]
  void *v58; // [esp+68h] [ebp-9Ch]
  WCHAR v59[2]; // [esp+6Ch] [ebp-98h]
  WCHAR v60[2]; // [esp+70h] [ebp-94h]
  void *v61; // [esp+74h] [ebp-90h]
  void *v62; // [esp+78h] [ebp-8Ch]
  void *v63; // [esp+7Ch] [ebp-88h]
  void *v64; // [esp+80h] [ebp-84h]
  int v65; // [esp+84h] [ebp-80h]
  HKEY KeyHandle; // [esp+88h] [ebp-7Ch]
  BYTE Data[4]; // [esp+8Ch] [ebp-78h]
  void *v68; // [esp+90h] [ebp-74h]
  DWORD v69; // [esp+94h] [ebp-70h]
  void *a1a; // [esp+98h] [ebp-6Ch]
  HKEY hRootKey; // [esp+9Ch] [ebp-68h]
  void *ppv1; // [esp+A0h] [ebp-64h]
  WCHAR szArg[2]; // [esp+A4h] [ebp-60h]
  void *v74; // [esp+A8h] [ebp-5Ch]
  LPCWSTR v75; // [esp+ACh] [ebp-58h]
  WCHAR *ppv3; // [esp+B0h] [ebp-54h]
  LPCWSTR v77; // [esp+B4h] [ebp-50h]
  WCHAR *pszText; // [esp+B8h] [ebp-4Ch]
  LPCWSTR v79; // [esp+BCh] [ebp-48h]
  LPCWSTR szArg4; // [esp+C0h] [ebp-44h]
  LPCWSTR v81; // [esp+C4h] [ebp-40h]
  LPCWSTR v82; // [esp+C8h] [ebp-3Ch]
  LPCWSTR v83; // [esp+CCh] [ebp-38h]
  LPCWSTR v84; // [esp+D0h] [ebp-34h]
  LPCWSTR szArg3; // [esp+D4h] [ebp-30h]
  DWORD cbData; // [esp+D8h] [ebp-2Ch]
  void *v87; // [esp+DCh] [ebp-28h]
  LPCWSTR lpszKeyName; // [esp+E0h] [ebp-24h]
  void *v89; // [esp+E4h] [ebp-20h]
  HKEY hKey; // [esp+E8h] [ebp-1Ch]
  void *v91; // [esp+ECh] [ebp-18h]
  std__List *v92; // [esp+F0h] [ebp-14h]
  char v93; // [esp+F7h] [ebp-Dh]
  int v94; // [esp+100h] [ebp-4h]

  v69 = 0;
  v3 = malloc(2u);
  v92 = v3;
  LOWORD(v3->_Mypair._Myval2._Myhead) = 0;
  v94 = 0;
  v4 = malloc(2u);
  lpszKeyName = v4;
  *v4 = 0;
  v5 = malloc(2u);
  ppv3 = v5;
  *v5 = 0;
  v6 = malloc(2u);
  v91 = v6;
  *v6 = 0;
  v7 = malloc(2u);
  v74 = v7;
  *v7 = 0;
  v8 = malloc(2u);
  v87 = v8;
  *v8 = 0;
  v9 = malloc(2u);
  v68 = v9;
  *v9 = 0;
  v10 = malloc(2u);
  v89 = v10;
  *v10 = 0;
  v75 = _wcsdup(&gszNullString);
  v77 = _wcsdup(&gszNullString);
  v79 = _wcsdup(&gszNullString);
  v81 = _wcsdup(&gszNullString);
  v83 = _wcsdup(&gszNullString);
  v84 = _wcsdup(&gszNullString);
  szArg4 = _wcsdup(&gszNullString);
  v11 = psz;
  v12 = &gszNullString;
  if ( psz )
    v12 = psz;
  pszText = _wcsdup(v12);
  v82 = _wcsdup(&gszNullString);
  v13 = &gszNullString;
  if ( psz )
    v13 = psz;
  szArg3 = _wcsdup(v13);
  LOBYTE(v94) = 17;
  v14 = sub_F77BE0(&a1a, a2, &pszText, &szArg4);
  LOBYTE(v94) = 18;
  v15 = sub_F77BE0(szArg, a2, &szArg3, &v82);
  LOBYTE(v94) = 19;
  v16 = sub_F73FF0(a1, 0, 0xFFFFFFFF, 0, v15, v14, &v84);
  ppv1 = v16;
  free(*szArg);
  free(a1a);
  free(szArg3);
  free(v82);
  free(pszText);
  free(szArg4);
  free(v84);
  free(v83);
  free(v81);
  free(v79);
  free(v77);
  LOBYTE(v94) = 7;
  free(v75);
  if ( PE_OpenKey(ghLocalMachineKey, psz, 0, 0x20019u, &hRootKey) )
    goto LABEL_64;
  if ( PE_LoadKey(hRootKey, 0, &lpszKeyName) )
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
      v93 = 0;
    }
    else
    {
      v93 = 1;
    }
    if ( v17(hKey, L"Type", 0, 0, v51, &cbData) || *v51 <= 2u )
      goto LABEL_60;
    v18 = v91;
    v91 = _wcsdup(&gszNullString);
    free(v18);
    if ( sub_F81520(hKey, L"ServiceDll", 0, 0, &v92) )
    {
      if ( !PE_OpenKey(hKey, L"Parameters", 0, 1u, &KeyHandle) )
      {
        if ( !sub_F81520(KeyHandle, L"ServiceDll", 0, 0, &v92) )
        {
          v22 = v89;
          v89 = _wcsdup(v92);
          free(v22);
          sub_F72170(&v44);
          LOBYTE(v94) = 21;
          sub_F77040(v92, &v44);
          v23 = sub_F74EE0(&v52, a1, &v44, 0);
          sub_F72250(&v91, v23);
          free(v52);
          LOBYTE(v94) = 7;
          sub_F721F0(&v44);
        }
        RegCloseKey(KeyHandle);
      }
    }
    else
    {
      v19 = v89;
      v89 = _wcsdup(v92);
      free(v19);
      v45 = malloc(2u);
      *v45 = 0;
      v46 = 0;
      v47 = 0;
      v48 = 0;
      LOBYTE(v94) = 20;
      sub_F77040(v92, &v45);
      v20 = sub_F74EE0(&v55, a1, &v45, 0);
      v21 = v91;
      v91 = _wcsdup(*v20);
      free(v21);
      free(v55);
      LOBYTE(v94) = 7;
      sub_F721F0(&v45);
    }
    if ( *v91 )
    {
LABEL_36:
      v65 = sub_F74ED0();
      sub_F81520(hKey, L"Description", 0, 0, &v87);
      if ( wcslen(v87) && *v87 == 64 )
      {
        v29 = _wcsdup(lpszKeyName);
        sub_F893C0(v29, &v87);
      }
      else if ( wcslen(v87) > 3 && *(v87 + wcslen(v87) - 1) == 10 )
      {
        *(v87 + wcslen(v87) - 1) = 0;
        if ( *(v87 + wcslen(v87) - 1) == 13 )
          *(v87 + wcslen(v87) - 1) = 0;
      }
      v30 = ppv3;
      ppv3 = _wcsdup(lpszKeyName);
      free(v30);
      v31 = &gszNullString;
      if ( v11 )
        v31 = v11;
      v79 = _wcsdup(v31);
      v77 = _wcsdup(&gszNullString);
      v32 = &gszNullString;
      if ( v11 )
        v32 = v11;
      v75 = _wcsdup(v32);
      LOBYTE(v94) = 25;
      v33 = sub_F77BE0(v49, a2, &v79, &lpszKeyName);
      LOBYTE(v94) = 26;
      v34 = sub_F77BE0(v54, a2, &v75, &v77);
      LOBYTE(v94) = 27;
      v35 = sub_F73D40(a1, &ppv3, v34, v33, &v91, &v74, &v68, &v57);
      free(*v54);
      free(*v49);
      free(v75);
      free(v77);
      LOBYTE(v94) = 7;
      free(v79);
      if ( v35 )
      {
        if ( ppv1 == -1 )
        {
          v63 = _wcsdup(&gszNullString);
          v62 = _wcsdup(&gszNullString);
          v64 = _wcsdup(&gszNullString);
          szArg3 = _wcsdup(&gszNullString);
          v82 = _wcsdup(&gszNullString);
          pszText = _wcsdup(&gszNullString);
          szArg4 = _wcsdup(&gszNullString);
          v11 = psz;
          v36 = &gszNullString;
          if ( psz )
            v36 = psz;
          v84 = _wcsdup(v36);
          v83 = _wcsdup(&gszNullString);
          v37 = &gszNullString;
          if ( psz )
            v37 = psz;
          v81 = _wcsdup(v37);
          LOBYTE(v94) = 37;
          v38 = sub_F77BE0(v59, a2, &v84, &szArg4);
          LOBYTE(v94) = 38;
          v39 = sub_F77BE0(v60, a2, &v81, &v83);
          LOBYTE(v94) = 39;
          ppv1 = sub_F73FF0(a1, 0, 0xFFFFFFFF, 0, v39, v38, &pszText);
          free(*v60);
          free(*v59);
          free(v81);
          free(v83);
          free(v84);
          free(szArg4);
          free(pszText);
          free(v82);
          free(szArg3);
          free(v64);
          free(v62);
          free(v63);
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
        LOBYTE(v94) = 41;
        v41 = sub_F77BE0(v53, a2, &a1a, &lpszKeyName);
        LOBYTE(v94) = 42;
        sub_F73FF0(a1, v65, ppv1, 8, &ppv3, v41, &v91);
        free(*v53);
        free(a1a);
        LOBYTE(v94) = 7;
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
    if ( !sub_F81520(hKey, L"ImagePath", 0, 0, &v92) )
    {
      cbData = 4;
      if ( RegQueryValueExW(hKey, L"WOW64", 0, 0, v50, &cbData) )
      {
        v24 = v89;
        v89 = _wcsdup(v92);
        free(v24);
        sub_F72170(&a2a);
        LOBYTE(v94) = 22;
        sub_F76CC0(v92, &a2a);
        v25 = sub_F74EE0(&v58, a1, &a2a, 0);
        sub_F72250(&v91, v25);
        free(v58);
        LOBYTE(v94) = 7;
        sub_F721F0(&a2a);
      }
      else
      {
        if ( !*v50 )
          goto LABEL_35;
        if ( Wow64EnableWow64FsRedirection )
        {
          Wow64EnableWow64FsRedirection(1u);
          TlsSetValue(gdwTlsIndex, 0x200);
        }
        v26 = v89;
        v89 = _wcsdup(v92);
        free(v26);
        v27 = _wcsdup(v92);
        sub_F75C70(&v56, v27);
        free(v56);
        v28 = sub_F74F20(&v61, a1, v92);
        sub_F72250(&v91, v28);
        free(v61);
        if ( Wow64EnableWow64FsRedirection )
        {
          Wow64EnableWow64FsRedirection(0);
          TlsSetValue(gdwTlsIndex, 0x100);
        }
      }
      v17 = RegQueryValueExW;
    }
LABEL_35:
    if ( *v91 )
      goto LABEL_36;
LABEL_60:
    RegCloseKey(hKey);
LABEL_61:
    ++v69;
  }
  while ( !PE_LoadKey(hRootKey, v69, &lpszKeyName) );
  v16 = ppv1;
LABEL_63:
  RegCloseKey(hRootKey);
LABEL_64:
  free(v89);
  free(v68);
  free(v87);
  free(v74);
  free(v91);
  free(ppv3);
  free(lpszKeyName);
  free(v92);
  return v16;
}

//----- (00F8A070) --------------------------------------------------------
void __cdecl sub_F8A070(int a1, void *a2, void *a3)
{
  _WORD *v3; // ST50_4
  WCHAR *v4; // esi
  void *v5; // edi
  const wchar_t **v6; // eax
  wchar_t *v7; // ST54_4

  v3 = malloc(2u);
  *v3 = 0;
  v4 = a3;
  v5 = sub_F8A120(a1, a2, *a3, 0xFFFFFFFF);
  v6 = PE_CopyString(&a3, v4, L"\\AutorunsDisabled");
  v7 = _wcsdup(*v6);
  free(v3);
  free(a3);
  sub_F8A120(a1, a2, v7, v5);
  free(v7);
}

//----- (00F8A120) --------------------------------------------------------
void *__cdecl sub_F8A120(int a1, void *a2, wchar_t *psz, void *a4)
{
  const wchar_t *v4; // eax
  const wchar_t *v5; // eax
  unsigned __int16 **v6; // esi
  unsigned __int16 **v7; // eax
  unsigned int v8; // eax
  void (__stdcall *v9)(HKEY); // ebx
  LPVOID (__stdcall *v10)(DWORD); // edi
  const wchar_t **v11; // eax
  WCHAR *v12; // esi
  tagKeyName *v13; // esi
  unsigned int v14; // eax
  wchar_t *v15; // esi
  tagKeyName *v16; // esi
  unsigned int v17; // eax
  wchar_t *v18; // esi
  WCHAR *v19; // eax
  const wchar_t **v20; // eax
  WCHAR *v21; // esi
  tagKeyName *v22; // esi
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
  unsigned __int16 **v33; // eax
  WCHAR *v34; // edi
  WCHAR *v35; // esi
  tagKeyName *v36; // esi
  unsigned int v37; // eax
  WCHAR *v38; // esi
  const wchar_t *v39; // eax
  const wchar_t *v40; // eax
  unsigned __int16 **v41; // esi
  unsigned __int16 **v42; // eax
  char v43; // bl
  const wchar_t *v44; // eax
  const wchar_t *v45; // eax
  unsigned __int16 **v46; // esi
  unsigned __int16 **v47; // eax
  int v48; // ebx
  const wchar_t *v49; // eax
  WCHAR *v50; // esi
  __int16 *v51; // edx
  __int16 v52; // cx
  const wchar_t *v53; // eax
  unsigned __int16 **v54; // eax
  DWORD v55; // esi
  void **v56; // esi
  void **v57; // edi
  WCHAR *v59; // [esp+10h] [ebp-C4h]
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
  void *v76; // [esp+54h] [ebp-80h]
  void *v77; // [esp+58h] [ebp-7Ch]
  LPCWSTR v78; // [esp+5Ch] [ebp-78h]
  void *v79; // [esp+60h] [ebp-74h]
  void *v80; // [esp+64h] [ebp-70h]
  void *v81; // [esp+68h] [ebp-6Ch]
  void *v82; // [esp+6Ch] [ebp-68h]
  void *v83; // [esp+70h] [ebp-64h]
  WCHAR szArg[2]; // [esp+74h] [ebp-60h]
  HKEY KeyHandle; // [esp+78h] [ebp-5Ch]
  void *a1a; // [esp+7Ch] [ebp-58h]
  void *v87; // [esp+80h] [ebp-54h]
  LPCWSTR v88; // [esp+84h] [ebp-50h]
  void *v89; // [esp+88h] [ebp-4Ch]
  void *v90; // [esp+8Ch] [ebp-48h]
  void **v91; // [esp+90h] [ebp-44h]
  int v92; // [esp+94h] [ebp-40h]
  LPCWSTR v93; // [esp+98h] [ebp-3Ch]
  LPCWSTR v94; // [esp+9Ch] [ebp-38h]
  LPCWSTR v95; // [esp+A0h] [ebp-34h]
  LPCWSTR szArg3; // [esp+A4h] [ebp-30h]
  WCHAR *ppv2; // [esp+A8h] [ebp-2Ch]
  wchar_t *ppszText2; // [esp+ACh] [ebp-28h]
  WCHAR *v99; // [esp+B0h] [ebp-24h]
  wchar_t *pszText; // [esp+B4h] [ebp-20h]
  HKEY hKey; // [esp+B8h] [ebp-1Ch]
  LPCWSTR szArg4; // [esp+BCh] [ebp-18h]
  wchar_t *ppv3; // [esp+C0h] [ebp-14h]
  LPCWSTR lpszKeyName; // [esp+C4h] [ebp-10h]
  int v105; // [esp+D0h] [ebp-4h]

  v99 = malloc(2u);
  *v99 = 0;
  v105 = 0;
  ppszText2 = malloc(2u);
  *ppszText2 = 0;
  v87 = malloc(2u);
  *v87 = 0;
  v83 = malloc(2u);
  *v83 = 0;
  v82 = malloc(2u);
  *v82 = 0;
  LOBYTE(v105) = 4;
  if ( a4 == -1 )
  {
    v93 = _wcsdup(&gszNullString);
    v95 = _wcsdup(&gszNullString);
    szArg3 = _wcsdup(&gszNullString);
    v94 = _wcsdup(&gszNullString);
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
    LOBYTE(v105) = 14;
    v6 = sub_F77BE0(&a1a, a2, &ppv3, &szArg4);
    LOBYTE(v105) = 15;
    v7 = sub_F77BE0(szArg, a2, &pszText, &hKey);
    LOBYTE(v105) = 16;
    a4 = sub_F73FF0(a1, 0, 0xFFFFFFFF, 0, v7, v6, &lpszKeyName);
    free(*szArg);
    free(a1a);
    free(pszText);
    free(hKey);
    free(ppv3);
    free(szArg4);
    free(lpszKeyName);
    free(v88);
    free(v94);
    free(szArg3);
    free(v95);
    LOBYTE(v105) = 4;
    free(v93);
  }
  v8 = TlsGetValue(gdwTlsIndex);
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
    v89 = malloc(2u);
    *v89 = 0;
    v90 = 0;
    v91 = 0;
    v92 = 0;
    LOBYTE(v105) = 21;
    v9 = RegCloseKey;
    if ( !PE_LoadKey(KeyHandle, 0, &ppszText2) )
    {
      v10 = TlsGetValue;
      do
      {
        v11 = PE_CopyString2(&pszResult, L"CLSID\\", &ppszText2);
        v12 = lpszKeyName;
        lpszKeyName = _wcsdup(*v11);
        free(v12);
        free(pszResult);
        v13 = lpszKeyName;
        v14 = v10(gdwTlsIndex);
        if ( PE_OpenKey(HKEY_CLASSES_ROOT, v13, 0, v14 | 0x20019, &hKey) )
        {
          v16 = ppszText2;
          v17 = v10(gdwTlsIndex);
          if ( PE_OpenKey(KeyHandle, v16, 0, v17 | 0x20019, &hKey) )
            goto LABEL_52;
          if ( sub_F81520(hKey, &gszNullString, 0, 0, &ppv3) )
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
          sub_F81520(hKey, &gszNullString, 0, 0, &pszText);
        }
        v9(hKey);
        v19 = PE_CopyString2(&v59, L"CLSID\\", &ppv3);
        v20 = PE_CopyString(&ppv, v19, L"\\InprocServer32");
        v21 = lpszKeyName;
        lpszKeyName = _wcsdup(*v20);
        free(v21);
        free(ppv);
        free(v59);
        v22 = lpszKeyName;
        v23 = v10(gdwTlsIndex);
        if ( !PE_OpenKey(HKEY_CLASSES_ROOT, v22, 0, v23 | 0x20019, &hKey) )
        {
          if ( !sub_F81520(hKey, L"CodeBase", 0, 0, &lpszKeyName) )
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
            sub_F77040(lpszKeyName, &v89);
            v28 = sub_F74EE0(&v71, a1, &v89, 0);
            v29 = szArg4;
            szArg4 = _wcsdup(*v28);
            free(v29);
            free(v71);
            goto LABEL_24;
          }
          if ( !sub_F81520(hKey, &gszNullString, 0, 0, &lpszKeyName) )
          {
            sub_F77040(lpszKeyName, &v89);
            v30 = sub_F74EE0(&v68, a1, &v89, 0);
            v31 = szArg4;
            szArg4 = _wcsdup(*v30);
            free(v31);
            free(v68);
LABEL_24:
            v9(hKey);
            a2a = sub_F74ED0();
            v32 = _wcsdup(L"CLSID\\");
            ppv2 = v32;
            v33 = PE_CopyStringEx(&ppv1, &ppv2, &ppv3);
            v34 = lpszKeyName;
            lpszKeyName = _wcsdup(*v33);
            free(v34);
            free(ppv1);
            free(v32);
            PE_CopyString2(&a1a, L"HKCR\\CLSID\\", &ppv3);
            v35 = v99;
            LOBYTE(v105) = 22;
            v99 = _wcsdup(ppv3);
            free(v35);
            v36 = lpszKeyName;
            v37 = TlsGetValue(gdwTlsIndex);
            if ( !PE_OpenKey(HKEY_CLASSES_ROOT, v36, 0, v37 | 0x20019, &hKey) )
            {
              if ( !sub_F81520(hKey, &gszNullString, 0, 0, &lpszKeyName) && wcslen(lpszKeyName) )
              {
                v38 = v99;
                v99 = _wcsdup(lpszKeyName);
                free(v38);
              }
              v9(hKey);
            }
            v39 = &gszNullString;
            if ( psz )
              v39 = psz;
            szArg3 = _wcsdup(v39);
            v95 = _wcsdup(&gszNullString);
            v40 = &gszNullString;
            if ( psz )
              v40 = psz;
            v93 = _wcsdup(v40);
            LOBYTE(v105) = 25;
            v41 = sub_F77BE0(v70, a2, &szArg3, &ppszText2);
            LOBYTE(v105) = 26;
            v42 = sub_F77BE0(v62, a2, &v93, &v95);
            LOBYTE(v105) = 27;
            v43 = sub_F73D40(a1, &v99, v42, v41, &szArg4, &v87, &v82, &v65);
            free(*v62);
            free(*v70);
            free(v93);
            free(v95);
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
                v76 = _wcsdup(&gszNullString);
                v78 = _wcsdup(&gszNullString);
                v44 = &gszNullString;
                if ( psz )
                  v44 = psz;
                v74 = _wcsdup(v44);
                v88 = _wcsdup(&gszNullString);
                v45 = &gszNullString;
                if ( psz )
                  v45 = psz;
                v94 = _wcsdup(v45);
                LOBYTE(v105) = 37;
                v46 = sub_F77BE0(v67, a2, &v74, &v78);
                LOBYTE(v105) = 38;
                v47 = sub_F77BE0(v69, a2, &v94, &v88);
                LOBYTE(v105) = 39;
                v48 = a1;
                a4 = sub_F73FF0(a1, 0, 0xFFFFFFFF, 0, v47, v46, &v76);
                free(*v69);
                free(*v67);
                free(v94);
                free(v88);
                free(v74);
                free(v78);
                free(v76);
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
              v50 = v99;
              if ( wcslen(pszText) )
                goto LABEL_63;
              if ( *v99 == 123 )
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
                  v99 = _wcsdup(v49);
                  free(v50);
                }
              }
              v80 = _wcsdup(&gszNullString);
              v53 = &gszNullString;
              if ( psz )
                v53 = psz;
              v73 = _wcsdup(v53);
              LOBYTE(v105) = 41;
              v54 = sub_F77BE0(v61, a2, &v73, &ppszText2);
              LOBYTE(v105) = 42;
              sub_F73FF0(v48, a2a, a4, 3, &v99, v54, &szArg4);
              free(*v61);
              free(v73);
              free(v80);
            }
            free(a1a);
            sub_F721F0(&v89);
            free(szArg4);
            free(ppv3);
            free(lpszKeyName);
            free(pszText);
            v9 = RegCloseKey;
            v10 = TlsGetValue;
            goto LABEL_53;
          }
LABEL_51:
          v9(hKey);
        }
LABEL_52:
        sub_F721F0(&v89);
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
        v89 = malloc(2u);
        *v89 = 0;
        v90 = 0;
        v91 = 0;
        v92 = 0;
        LOBYTE(v105) = 21;
      }
      while ( !PE_LoadKey(KeyHandle, v55, &ppszText2) );
    }
    v56 = v90;
    if ( v90 )
    {
      v57 = v91;
      if ( v90 != v91 )
      {
        do
        {
          free(*v56);
          ++v56;
        }
        while ( v56 != v57 );
        v56 = v90;
      }
      j__free(v56);
      v90 = 0;
      v91 = 0;
      v92 = 0;
    }
    free(v89);
    free(szArg4);
    free(ppv3);
    free(lpszKeyName);
    free(pszText);
    v9(KeyHandle);
  }
  free(v82);
  free(v83);
  free(v87);
  free(ppszText2);
  free(v99);
  return a4;
}

//----- (00F8AC50) --------------------------------------------------------
_DWORD *__stdcall sub_F8AC50(_DWORD *a1, _DWORD *a2, int a3)
{
  _DWORD *result; // eax
  _DWORD *v4; // esi

  result = sub_F8E320(a1, a2);
  v4 = result;
  if ( result != -8 )
  {
    sub_F8AC80(result + 2, a3);
    result = v4;
  }
  return result;
}

//----- (00F8AC80) --------------------------------------------------------
_DWORD *__thiscall sub_F8AC80(_DWORD *this, int a2)
{
  _DWORD *v2; // esi
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax

  v2 = this;
  *this = *a2;
  *(this + 4) = *(a2 + 4);
  v3 = *(a2 + 8);
  this[2] = v3;
  if ( v3 )
    InterlockedIncrement((v3 + 8));
  v4 = *(a2 + 12);
  v2[3] = v4;
  if ( v4 )
    InterlockedIncrement((v4 + 8));
  v5 = *(a2 + 16);
  v2[4] = v5;
  if ( v5 )
    InterlockedIncrement((v5 + 8));
  v6 = *(a2 + 20);
  v2[5] = v6;
  if ( v6 )
    InterlockedIncrement((v6 + 8));
  v7 = *(a2 + 24);
  v2[6] = v7;
  if ( v7 )
    InterlockedIncrement((v7 + 8));
  v8 = *(a2 + 28);
  v2[7] = v8;
  if ( v8 )
    InterlockedIncrement((v8 + 8));
  v9 = *(a2 + 32);
  v2[8] = v9;
  if ( v9 )
    InterlockedIncrement((v9 + 8));
  return v2;
}

//----- (00F8AD20) --------------------------------------------------------
EventItem *__thiscall sub_F8AD20(EventItem *this, VARIANTARG *pvarSrc)
{
  EventItem *v2; // esi
  int v3; // eax
  VARIANTARG pvarg; // [esp+Ch] [ebp-1Ch]
  int v6; // [esp+24h] [ebp-4h]

  v2 = this;
  this->strEventTrace.m_Data = 0;
  if ( pvarSrc->vt == 8 )
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

//----- (00F8ADD0) --------------------------------------------------------
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
    v3->m_wstr = _com_util::ConvertBSTRToString(lpString);
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

//----- (00F8AE80) --------------------------------------------------------
void __thiscall sub_F8AE80(_DWORD *this)
{
  _DWORD *v1; // esi
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
  v3 = v1[8];
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
    v1[8] = 0;
  }
  v4 = v1[7];
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
    v1[7] = 0;
  }
  v5 = v1[6];
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
    v1[6] = 0;
  }
  v6 = v1[5];
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
    v1[5] = 0;
  }
  v7 = v1[4];
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
    v1[4] = 0;
  }
  v8 = v1[3];
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
    v1[3] = 0;
  }
  v9 = v1[2];
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
    v1[2] = 0;
  }
}

//----- (00F8B0D0) --------------------------------------------------------
int *__thiscall sub_F8B0D0(_DWORD *this, int a2)
{
  _DWORD *v2; // edi
  int v3; // esi
  int *result; // eax

  v2 = this;
  v3 = *this;
  if ( *this )
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
    *v2 = 0;
  }
  result = operator new(0xCu);
  if ( result )
  {
    result[1] = 0;
    result[2] = 1;
    *result = a2;
  }
  else
  {
    result = 0;
  }
  *v2 = result;
  if ( !result )
    _com_issue_error(-2147024882);
  return result;
}

//----- (00F8B1A0) --------------------------------------------------------
char __cdecl sub_F8B1A0(int **a1, void **a2)
{
  HMODULE v2; // eax
  HMODULE v3; // eax
  int v4; // esi
  int v5; // edi
  const WCHAR *v6; // eax
  _DWORD *v7; // eax
  _DWORD *v8; // ecx
  const WCHAR *v9; // eax
  Data_t_bstr_t *v10; // eax
  Data_t_bstr_t *v11; // edi
  BSTR v12; // eax
  _bstr_t *v13; // esi
  _bstr_t *v14; // eax
  const WCHAR *v15; // ecx
  const WCHAR **v16; // eax
  const WCHAR *v17; // eax
  DWORD v18; // eax
  void *v19; // esi
  void *v20; // esi
  Data_t_bstr_t *v21; // edi
  _DWORD *v22; // eax
  EventList *v23; // edi
  EventListNode *v24; // esi
  _bstr_t *v25; // eax
  const WCHAR *v26; // esi
  const WCHAR *v27; // eax
  void *v28; // esi
  int v29; // eax
  _bstr_t *v30; // eax
  const WCHAR *v31; // esi
  const WCHAR *v32; // eax
  void *v33; // esi
  BSTR *v34; // eax
  BSTR *v35; // esi
  BSTR v36; // eax
  _bstr_t *v37; // esi
  _bstr_t *v38; // eax
  const WCHAR *v39; // ecx
  const WCHAR **v40; // eax
  const WCHAR *v41; // eax
  void *v42; // esi
  void *v43; // esi
  int v44; // esi
  HMODULE v45; // eax
  FARPROC v46; // eax
  HANDLE v47; // eax
  wchar_t *v48; // edx
  OLECHAR *v49; // ST18_4
  int v50; // esi
  _DWORD *v51; // eax
  BSTR v52; // eax
  int v53; // ecx
  int v54; // eax
  _DWORD *v55; // eax
  BSTR v56; // eax
  int v57; // ecx
  int v58; // eax
  EventListNode *v59; // eax
  BSTR v60; // eax
  EventListNode *v61; // ecx
  EventListNode *v62; // eax
  _bstr_t *v63; // eax
  _bstr_t *v64; // eax
  EventItem *v65; // eax
  void **v66; // eax
  void **v67; // eax
  void **v68; // eax
  void **v69; // eax
  void **v70; // eax
  void **v71; // eax
  OLECHAR *v72; // eax
  EventListNode *v73; // eax
  _DWORD *v74; // eax
  BSTR v75; // eax
  EventListNode *v76; // ecx
  EventListNode *v77; // eax
  _DWORD *v78; // eax
  BSTR v79; // eax
  int v80; // ecx
  int v81; // eax
  _DWORD *v82; // eax
  BSTR v83; // eax
  int v84; // ecx
  int v85; // eax
  _bstr_t *v86; // eax
  _bstr_t *v87; // eax
  EventListNode *v88; // eax
  void **v89; // eax
  void **v90; // eax
  void **v91; // eax
  void **v92; // eax
  void **v93; // eax
  int v94; // eax
  void *v95; // eax
  void *v96; // eax
  OLECHAR *v97; // eax
  _DWORD *v98; // eax
  BSTR v99; // eax
  int v100; // ecx
  int v101; // eax
  EventListNode *v102; // eax
  void **v103; // eax
  void **v104; // eax
  OLECHAR *v105; // eax
  _DWORD *v106; // eax
  BSTR v107; // eax
  int v108; // ecx
  int v109; // eax
  EventListNode *v110; // eax
  void **v111; // eax
  void **v112; // eax
  OLECHAR *v113; // eax
  void **v114; // eax
  volatile LONG *v115; // eax
  int v116; // eax
  unsigned int v117; // ecx
  unsigned int v118; // eax
  int v119; // edx
  unsigned int v120; // esi
  int v121; // edi
  __int16 v122; // ax
  void **v123; // eax
  Data_t_bstr_t *v124; // esi
  const wchar_t *v125; // eax
  const wchar_t *v126; // eax
  wchar_t *v127; // eax
  wint_t v128; // cx
  EventListNode *v129; // edi
  wint_t v130; // ax
  _DWORD *v131; // eax
  EventListNode *v132; // ST18_4
  BSTR v133; // eax
  Data_t_bstr_t *v134; // ecx
  Data_t_bstr_t *v135; // eax
  void **v136; // eax
  HRESULT v137; // eax
  BOOLEAN (__stdcall *v138)(BOOLEAN); // ecx
  BSTR v139; // edx
  _DWORD *v140; // eax
  BSTR v141; // eax
  int *v142; // edx
  int v143; // ST14_4
  int v144; // eax
  LONG v145; // eax
  void **v146; // eax
  _DWORD *v147; // eax
  BSTR v148; // eax
  int *v149; // edx
  int v150; // ST14_4
  int v151; // eax
  void **v152; // eax
  Data_t_bstr_t *v153; // eax
  BSTR v154; // edx
  int v155; // eax
  Data_t_bstr_t *v156; // eax
  BSTR v157; // edx
  int v158; // eax
  Data_t_bstr_t *v159; // eax
  BSTR v160; // edx
  int v161; // eax
  Data_t_bstr_t *v162; // eax
  BSTR v163; // edx
  int v164; // eax
  Data_t_bstr_t *v165; // eax
  BSTR v166; // edx
  int v167; // eax
  int v168; // edi
  Data_t_bstr_t *v169; // eax
  BSTR v170; // edx
  int v171; // eax
  Data_t_bstr_t *v172; // eax
  const wchar_t *v173; // eax
  Data_t_bstr_t *v174; // eax
  BSTR v175; // edx
  int v176; // eax
  int v177; // esi
  Data_t_bstr_t *v178; // eax
  const wchar_t *v179; // eax
  Data_t_bstr_t *v180; // eax
  BSTR v181; // edx
  int v182; // eax
  int v183; // esi
  const wchar_t *v184; // eax
  wchar_t *v185; // eax
  _bstr_t *v186; // eax
  EventListNode *v187; // eax
  _DWORD *v188; // edx
  char *v189; // eax
  EventList *v190; // edi
  EventListNode *v191; // eax
  EventListNode *v192; // esi
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
  EventListNode *v212; // [esp+7Ch] [ebp-554h]
  _bstr_t v213; // [esp+80h] [ebp-550h]
  EventListNode *v214; // [esp+84h] [ebp-54Ch]
  EventListNode *v215; // [esp+88h] [ebp-548h]
  EventListNode *v216; // [esp+8Ch] [ebp-544h]
  int v217; // [esp+90h] [ebp-540h]
  int v218; // [esp+94h] [ebp-53Ch]
  void *v219; // [esp+98h] [ebp-538h]
  _bstr_t v220; // [esp+9Ch] [ebp-534h]
  int v221; // [esp+A0h] [ebp-530h]
  EventListNode *v222; // [esp+A4h] [ebp-52Ch]
  DWORD NumberOfBytesRead; // [esp+A8h] [ebp-528h]
  void *v224; // [esp+ACh] [ebp-524h]
  EventListNode *v225; // [esp+B0h] [ebp-520h]
  void *v226; // [esp+B4h] [ebp-51Ch]
  EventListNode *v227; // [esp+B8h] [ebp-518h]
  void *v228; // [esp+BCh] [ebp-514h]
  EventListNode *v229; // [esp+C0h] [ebp-510h]
  int v230; // [esp+C4h] [ebp-50Ch]
  void **v231; // [esp+C8h] [ebp-508h]
  EventListNode *v232; // [esp+CCh] [ebp-504h]
  bool v233; // [esp+D0h] [ebp-500h]
  EventItem v234; // [esp+D4h] [ebp-4FCh]
  void *v235; // [esp+100h] [ebp-4D0h]
  int v236; // [esp+104h] [ebp-4CCh]
  void *v237; // [esp+108h] [ebp-4C8h]
  _bstr_t v238; // [esp+10Ch] [ebp-4C4h]
  EventList *a1a; // [esp+110h] [ebp-4C0h]
  int v240; // [esp+114h] [ebp-4BCh]
  EventList *v241; // [esp+118h] [ebp-4B8h]
  int v242; // [esp+11Ch] [ebp-4B4h]
  int a3; // [esp+120h] [ebp-4B0h]
  int v244; // [esp+124h] [ebp-4ACh]
  EventItem v245; // [esp+128h] [ebp-4A8h]
  WCHAR ReturnedString; // [esp+354h] [ebp-27Ch]
  char v247; // [esp+356h] [ebp-27Ah]
  WCHAR KeyName; // [esp+55Ch] [ebp-74h]
  int v249; // [esp+5CCh] [ebp-4h]

  *&v234.Type = a1;
  v231 = a2;
  if ( !GetSystemDefaultLocaleName )
  {
    v2 = LoadLibraryW(L"Kernel32.dll");
    GetSystemDefaultLocaleName = GetProcAddress(v2, "GetSystemDefaultLocaleName");
    v3 = LoadLibraryW(L"Kernel32.dll");
    GetUserDefaultLocaleName = GetProcAddress(v3, "GetUserDefaultLocaleName");
  }
  sub_F8E360(a2);
  v4 = 0;
  v240 = 0;
  a1a = std::_List_alloc<std::_List_base_types<tagEventItem *,std::allocator<tagEventItem *>>>::_Buynode0(0, 0);
  v5 = 0;
  v249 = 0;
  _swprintf(&KeyName, L"Section%d", 0);
  ReturnedString = 0;
  memset(&v247, 0, 0x206u);
  v6 = sub_F73B40(*&v234.Type);
  if ( GetPrivateProfileStringW(L"Root", &KeyName, &gszNullString, &ReturnedString, 0x104u, v6) )
  {
    do
    {
      a3 = _wtoi(&ReturnedString);
      v7 = std::_List_buy<tagEventItem *,std::allocator<tagEventItem *>>::_Buynode<tagEventItem * const &>(
             a1a,
             a1a->_Mysize,
             &a3);
      if ( (357913940 - v4) < 1 )
LABEL_10:
        std::_Xlength_error("list<T> too long");
      ++v5;
      ++v4;
      a1a->_Mysize = v7;
      v8 = v7[1];
      v240 = v4;
      *v8 = v7;
      _swprintf(&KeyName, L"Section%d", v5);
      ReturnedString = 0;
      memset(&v247, 0, 0x206u);
      v9 = sub_F73B40(*&v234.Type);
    }
    while ( GetPrivateProfileStringW(L"Root", &KeyName, &gszNullString, &ReturnedString, 0x104u, v9) );
  }
  v244 = 0;
  v238.m_Data = -1;
  while ( 1 )
  {
    ReturnedString = 0;
    memset(&v247, 0, 0x206u);
    v10 = operator new(0xCu);
    v11 = v10;
    v220.m_Data = v10;
    LOBYTE(v249) = 1;
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
    LOBYTE(v249) = 0;
    a3 = v11;
    if ( !v11 )
LABEL_9:
      _com_issue_error(-2147024882);
    LOBYTE(v249) = 2;
    v13 = _bstr_t::operator+(*&v234.Type, &v237, &a3);
    LOBYTE(v249) = 3;
    v14 = sub_F8E1B0(&v235, v244);
    if ( v13->m_Data )
      v15 = v13->m_Data->m_wstr;
    else
      v15 = 0;
    v16 = &v14->m_Data->m_wstr;
    if ( v16 )
      v17 = *v16;
    else
      v17 = 0;
    v18 = GetPrivateProfileStringW(v17, L"PrivateSetting_GadgetName", &gszNullString, &ReturnedString, 0x104u, v15);
    v19 = v235;
    HIBYTE(v245.strHeader.m_Data) = v18 == 0;
    if ( v235 )
    {
      if ( !InterlockedDecrement(v235 + 2) && v19 )
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
      v235 = 0;
    }
    v20 = v237;
    if ( v237 )
    {
      if ( !InterlockedDecrement(v237 + 2) && v20 )
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
      v237 = 0;
    }
    LOBYTE(v249) = 0;
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
    if ( HIBYTE(v245.strHeader.m_Data) )
      break;
    v21 = v238.m_Data;
    a3 = v238.m_Data;
    v22 = std::_List_buy<tagEventItem *,std::allocator<tagEventItem *>>::_Buynode<tagEventItem * const &>(
            a1a,
            a1a->_Mysize,
            &a3);
    if ( (357913940 - v240) < 1 )
      goto LABEL_10;
    ++v244;
    ++v240;
    v238.m_Data = (v21 - 1);
    a1a->_Mysize = v22;
    *v22[1] = v22;
  }
  v23 = a1a->_Myheader;
  v241 = v23;
  if ( v23 != a1a )
  {
    while ( 1 )
    {
      *v234.guid.Data4 = 0;
      _mm_storeu_si128(&v234, 0i64);
      *&v234.guid.Data4[4] = 0;
      v234.List._Myheader = 0;
      v24 = v23[1]._Myheader;
      ReturnedString = 0;
      LOBYTE(v249) = 4;
      v245.List._Myheader = v24;
      v232 = v24;
      memset(&v247, 0, 0x206u);
      if ( v24 < 0 )
      {
        v233 = 0;
      }
      else
      {
        v25 = sub_F8E1B0(&v219, v24);
        if ( v25->m_Data )
          v26 = v25->m_Data->m_wstr;
        else
          v26 = 0;
        v27 = sub_F73B40(*&v234.Type);
        GetPrivateProfileStringW(v26, L"PrivateSetting_Enabled", &gszNullString, &ReturnedString, 0x104u, v27);
        v28 = v219;
        if ( v219 )
        {
          if ( !InterlockedDecrement(v219 + 2) && v28 )
          {
            if ( *v28 )
            {
              SysFreeString(*v28);
              *v28 = 0;
            }
            if ( *(v28 + 1) )
            {
              j_j__free(*(v28 + 1));
              *(v28 + 1) = 0;
            }
            j__free(v28);
          }
          v219 = 0;
        }
        v29 = _wcsicmp(&ReturnedString, L"false");
        v24 = v245.List._Myheader;
        v233 = v29 != 0;
      }
      ReturnedString = 0;
      if ( v24 < 0 )
      {
        v34 = operator new(0xCu);
        v35 = v34;
        v245.List._Mysize = v34;
        *v245.guid.Data4 = v34;
        LOBYTE(v249) = 5;
        if ( v34 )
        {
          v34[1] = 0;
          v34[2] = 1;
          v36 = SysAllocString(L".disabled");
          *v35 = v36;
          if ( !v36 )
            goto LABEL_9;
        }
        else
        {
          v35 = 0;
          v245.List._Mysize = 0;
        }
        LOBYTE(v249) = 4;
        *&v245.guid.Data2 = v35;
        if ( !v35 )
          goto LABEL_9;
        LOBYTE(v249) = 6;
        v37 = _bstr_t::operator+(*&v234.Type, &v224, &v245.guid.Data2);
        LOBYTE(v249) = 7;
        v38 = sub_F8E1B0(&v226, -1 - v245.List._Myheader);
        if ( v37->m_Data )
          v39 = v37->m_Data->m_wstr;
        else
          v39 = 0;
        v40 = &v38->m_Data->m_wstr;
        if ( v40 )
          v41 = *v40;
        else
          v41 = 0;
        GetPrivateProfileStringW(v41, L"PrivateSetting_GadgetName", &gszNullString, &ReturnedString, 0x104u, v39);
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
        v44 = v245.List._Mysize;
        LOBYTE(v249) = 4;
        if ( !InterlockedDecrement((v245.List._Mysize + 8)) )
        {
          if ( *v44 )
          {
            SysFreeString(*v44);
            *v44 = 0;
          }
          if ( *(v44 + 4) )
          {
            j_j__free(*(v44 + 4));
            *(v44 + 4) = 0;
          }
          j__free(v44);
        }
      }
      else
      {
        v30 = sub_F8E1B0(&v228, v24);
        if ( v30->m_Data )
          v31 = v30->m_Data->m_wstr;
        else
          v31 = 0;
        v32 = sub_F73B40(*&v234.Type);
        GetPrivateProfileStringW(v31, L"PrivateSetting_GadgetName", &gszNullString, &ReturnedString, 0x104u, v32);
        v33 = v228;
        if ( v228 )
        {
          if ( !InterlockedDecrement(v228 + 2) && v33 )
          {
            if ( *v33 )
            {
              SysFreeString(*v33);
              *v33 = 0;
            }
            if ( *(v33 + 1) )
            {
              j_j__free(*(v33 + 1));
              *(v33 + 1) = 0;
            }
            j__free(v33);
          }
          v228 = 0;
        }
      }
      pcchUnescaped = 260;
      UrlUnescapeW(&ReturnedString, 0, &pcchUnescaped, 0x100000u);
      if ( dword_1064C68 & 1 )
      {
        v46 = IsWow64Process;
      }
      else
      {
        dword_1064C68 |= 1u;
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
            v48 = wcsstr(&ReturnedString, L"%PROGRAMFILES%");
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
      v49 = *RequerySystemEnvironmentString(&ppstr, &ReturnedString);
      LOBYTE(v249) = 8;
      _bstr_t::operator=(&v234, v49);
      free(ppstr);
      v245.strEventTrace.m_Data = 0;
      v50 = 0;
      v245.field_4 = 0;
      LOBYTE(v249) = 10;
      if ( !GetUserDefaultLocaleName(&v245.Type, 260) )
        goto LABEL_532;
      v51 = operator new(0xCu);
      v245.List._Mysize = v51;
      *v245.guid.Data4 = v51;
      LOBYTE(v249) = 11;
      if ( v51 )
      {
        v51[1] = 0;
        v51[2] = 1;
        v52 = SysAllocString(L"\\Gadget.xml");
        v53 = v245.List._Mysize;
        *v245.List._Mysize = v52;
        if ( !v52 )
          goto LABEL_9;
        v54 = v53;
      }
      else
      {
        v54 = 0;
        v245.List._Mysize = 0;
      }
      LOBYTE(v249) = 10;
      *v245.guid.Data4 = v54;
      if ( !v54 )
        goto LABEL_9;
      LOBYTE(v249) = 12;
      v55 = operator new(0xCu);
      *&v245.guid.Data4[4] = v55;
      *&v234.Level = v55;
      LOBYTE(v249) = 13;
      if ( v55 )
      {
        v55[1] = 0;
        v55[2] = 1;
        v56 = SysAllocString(&v245.Type);
        v57 = *&v245.guid.Data4[4];
        **&v245.guid.Data4[4] = v56;
        if ( !v56 )
          goto LABEL_9;
        v58 = v57;
      }
      else
      {
        v58 = 0;
        *&v245.guid.Data4[4] = 0;
      }
      LOBYTE(v249) = 12;
      *&v234.Level = v58;
      if ( !v58 )
        goto LABEL_9;
      LOBYTE(v249) = 14;
      v59 = operator new(0xCu);
      *&v245.guid.Data2 = v59;
      v245.List._Myheader = v59;
      LOBYTE(v249) = 15;
      if ( v59 )
      {
        v59->field_4 = 0;
        v59[1].field_0 = 1;
        v60 = SysAllocString(L"\\");
        v61 = *&v245.guid.Data2;
        **&v245.guid.Data2 = v60;
        if ( !v60 )
          goto LABEL_9;
        v62 = v61;
      }
      else
      {
        v62 = 0;
        *&v245.guid.Data2 = 0;
      }
      LOBYTE(v249) = 14;
      v245.List._Myheader = v62;
      if ( !v62 )
        goto LABEL_9;
      LOBYTE(v249) = 16;
      v63 = _bstr_t::operator+(&v234.strEventTrace.m_Data, &v212, &v245.List);
      LOBYTE(v249) = 17;
      v64 = _bstr_t::operator+(&v63->m_Data, &v214, &v234.Level);
      LOBYTE(v249) = 18;
      v65 = _bstr_t::operator+(&v64->m_Data, &v216, v245.guid.Data4);
      if ( &v245.field_4 != v65 )
      {
        v50 = v65->strEventTrace.m_Data;
        v245.field_4 = v50;
        if ( v50 )
          InterlockedIncrement((v50 + 8));
      }
      v245.List._Myheader = v216;
      if ( v216 )
      {
        if ( !InterlockedDecrement(&v216[1].field_0) )
        {
          v66 = v245.List._Myheader;
          if ( v245.List._Myheader )
          {
            if ( v245.List._Myheader->field_0 )
            {
              SysFreeString(v245.List._Myheader->field_0);
              v66 = v245.List._Myheader;
              v245.List._Myheader->field_0 = 0;
            }
            if ( v66[1] )
            {
              j_j__free(v66[1]);
              v66 = v245.List._Myheader;
              v245.List._Myheader->field_4 = 0;
            }
            j__free(v66);
          }
        }
        v216 = 0;
      }
      v245.List._Myheader = v214;
      if ( v214 )
      {
        if ( !InterlockedDecrement(&v214[1].field_0) )
        {
          v67 = v245.List._Myheader;
          if ( v245.List._Myheader )
          {
            if ( v245.List._Myheader->field_0 )
            {
              SysFreeString(v245.List._Myheader->field_0);
              v67 = v245.List._Myheader;
              v245.List._Myheader->field_0 = 0;
            }
            if ( v67[1] )
            {
              j_j__free(v67[1]);
              v67 = v245.List._Myheader;
              v245.List._Myheader->field_4 = 0;
            }
            j__free(v67);
          }
        }
        v214 = 0;
      }
      v245.List._Myheader = v212;
      if ( v212 )
      {
        if ( !InterlockedDecrement(&v212[1].field_0) )
        {
          v68 = v245.List._Myheader;
          if ( v245.List._Myheader )
          {
            if ( v245.List._Myheader->field_0 )
            {
              SysFreeString(v245.List._Myheader->field_0);
              v68 = v245.List._Myheader;
              v245.List._Myheader->field_0 = 0;
            }
            if ( v68[1] )
            {
              j_j__free(v68[1]);
              v68 = v245.List._Myheader;
              v245.List._Myheader->field_4 = 0;
            }
            j__free(v68);
          }
        }
        v212 = 0;
      }
      if ( !InterlockedDecrement((*&v245.guid.Data2 + 8)) )
      {
        v69 = *&v245.guid.Data2;
        if ( **&v245.guid.Data2 )
        {
          SysFreeString(**&v245.guid.Data2);
          v69 = *&v245.guid.Data2;
          **&v245.guid.Data2 = 0;
        }
        if ( v69[1] )
        {
          j_j__free(v69[1]);
          v69 = *&v245.guid.Data2;
          *(*&v245.guid.Data2 + 4) = 0;
        }
        j__free(v69);
      }
      if ( !InterlockedDecrement((*&v245.guid.Data4[4] + 8)) )
      {
        v70 = *&v245.guid.Data4[4];
        if ( **&v245.guid.Data4[4] )
        {
          SysFreeString(**&v245.guid.Data4[4]);
          v70 = *&v245.guid.Data4[4];
          **&v245.guid.Data4[4] = 0;
        }
        if ( v70[1] )
        {
          j_j__free(v70[1]);
          v70 = *&v245.guid.Data4[4];
          *(*&v245.guid.Data4[4] + 4) = 0;
        }
        j__free(v70);
      }
      LOBYTE(v249) = 10;
      if ( !InterlockedDecrement((v245.List._Mysize + 8)) )
      {
        v71 = v245.List._Mysize;
        if ( *v245.List._Mysize )
        {
          SysFreeString(*v245.List._Mysize);
          v71 = v245.List._Mysize;
          *v245.List._Mysize = 0;
        }
        if ( v71[1] )
        {
          j_j__free(v71[1]);
          v71 = v245.List._Mysize;
          *(v245.List._Mysize + 4) = 0;
        }
        j__free(v71);
      }
      v72 = (v50 ? *v50 : 0);
      v73 = sub_F76640(v72, 0x80000000, 1u, 0, 3u, 0, 0);
      v245.List._Myheader = v73;
      if ( v73 == -1 )
      {
LABEL_532:
        if ( !GetSystemDefaultLocaleName(&v245.Type, 260) )
          goto LABEL_533;
        v74 = operator new(0xCu);
        *&v245.guid.Data4[4] = v74;
        *v245.guid.Data4 = v74;
        LOBYTE(v249) = 19;
        if ( v74 )
        {
          v74[1] = 0;
          v74[2] = 1;
          v75 = SysAllocString(L"\\Gadget.xml");
          v76 = *&v245.guid.Data4[4];
          **&v245.guid.Data4[4] = v75;
          if ( !v75 )
            goto LABEL_9;
          v77 = v76;
        }
        else
        {
          v77 = 0;
          *&v245.guid.Data4[4] = 0;
        }
        LOBYTE(v249) = 10;
        v245.List._Myheader = v77;
        if ( !v77 )
          goto LABEL_9;
        LOBYTE(v249) = 20;
        v78 = operator new(0xCu);
        *&v245.guid.Data2 = v78;
        *v245.guid.Data4 = v78;
        LOBYTE(v249) = 21;
        if ( v78 )
        {
          v78[1] = 0;
          v78[2] = 1;
          v79 = SysAllocString(&v245.Type);
          v80 = *&v245.guid.Data2;
          **&v245.guid.Data2 = v79;
          if ( !v79 )
            goto LABEL_9;
          v81 = v80;
        }
        else
        {
          v81 = 0;
          *&v245.guid.Data2 = 0;
        }
        LOBYTE(v249) = 20;
        *&v234.Level = v81;
        if ( !v81 )
          goto LABEL_9;
        LOBYTE(v249) = 22;
        v82 = operator new(0xCu);
        v245.List._Mysize = v82;
        *v245.guid.Data4 = v82;
        LOBYTE(v249) = 23;
        if ( v82 )
        {
          v82[1] = 0;
          v82[2] = 1;
          v83 = SysAllocString(L"\\");
          v84 = v245.List._Mysize;
          *v245.List._Mysize = v83;
          if ( !v83 )
            goto LABEL_9;
          v85 = v84;
        }
        else
        {
          v85 = 0;
          v245.List._Mysize = 0;
        }
        LOBYTE(v249) = 22;
        *v245.guid.Data4 = v85;
        if ( !v85 )
          goto LABEL_9;
        LOBYTE(v249) = 24;
        v86 = _bstr_t::operator+(&v234.strEventTrace.m_Data, &v229, v245.guid.Data4);
        LOBYTE(v249) = 25;
        v87 = _bstr_t::operator+(&v86->m_Data, &v222, &v234.Level);
        LOBYTE(v249) = 26;
        v88 = _bstr_t::operator+(&v87->m_Data, &v227, &v245.List);
        v245.List._Myheader = v88;
        if ( &v245.field_4 != v88 )
        {
          if ( v50 )
          {
            if ( !InterlockedDecrement((v50 + 8)) )
            {
              if ( *v50 )
              {
                SysFreeString(*v50);
                *v50 = 0;
              }
              if ( *(v50 + 4) )
              {
                j_j__free(*(v50 + 4));
                *(v50 + 4) = 0;
              }
              j__free(v50);
            }
            v88 = v245.List._Myheader;
          }
          v50 = v88->field_0;
          v245.field_4 = v50;
          if ( v50 )
            InterlockedIncrement((v50 + 8));
        }
        v245.List._Myheader = v227;
        if ( v227 )
        {
          if ( !InterlockedDecrement(&v227[1].field_0) )
          {
            v89 = v245.List._Myheader;
            if ( v245.List._Myheader )
            {
              if ( v245.List._Myheader->field_0 )
              {
                SysFreeString(v245.List._Myheader->field_0);
                v89 = v245.List._Myheader;
                v245.List._Myheader->field_0 = 0;
              }
              if ( v89[1] )
              {
                j_j__free(v89[1]);
                v89 = v245.List._Myheader;
                v245.List._Myheader->field_4 = 0;
              }
              j__free(v89);
            }
          }
          v227 = 0;
        }
        v245.List._Myheader = v222;
        if ( v222 )
        {
          if ( !InterlockedDecrement(&v222[1].field_0) )
          {
            v90 = v245.List._Myheader;
            if ( v245.List._Myheader )
            {
              if ( v245.List._Myheader->field_0 )
              {
                SysFreeString(v245.List._Myheader->field_0);
                v90 = v245.List._Myheader;
                v245.List._Myheader->field_0 = 0;
              }
              if ( v90[1] )
              {
                j_j__free(v90[1]);
                v90 = v245.List._Myheader;
                v245.List._Myheader->field_4 = 0;
              }
              j__free(v90);
            }
          }
          v222 = 0;
        }
        v245.List._Myheader = v229;
        if ( v229 )
        {
          if ( !InterlockedDecrement(&v229[1].field_0) )
          {
            v91 = v245.List._Myheader;
            if ( v245.List._Myheader )
            {
              if ( v245.List._Myheader->field_0 )
              {
                SysFreeString(v245.List._Myheader->field_0);
                v91 = v245.List._Myheader;
                v245.List._Myheader->field_0 = 0;
              }
              if ( v91[1] )
              {
                j_j__free(v91[1]);
                v91 = v245.List._Myheader;
                v245.List._Myheader->field_4 = 0;
              }
              j__free(v91);
            }
          }
          v229 = 0;
        }
        if ( !InterlockedDecrement((v245.List._Mysize + 8)) )
        {
          v92 = v245.List._Mysize;
          if ( *v245.List._Mysize )
          {
            SysFreeString(*v245.List._Mysize);
            v92 = v245.List._Mysize;
            *v245.List._Mysize = 0;
          }
          if ( v92[1] )
          {
            j_j__free(v92[1]);
            v92 = v245.List._Mysize;
            *(v245.List._Mysize + 4) = 0;
          }
          j__free(v92);
        }
        if ( !InterlockedDecrement((*&v245.guid.Data2 + 8)) )
        {
          v93 = *&v245.guid.Data2;
          if ( **&v245.guid.Data2 )
          {
            SysFreeString(**&v245.guid.Data2);
            v93 = *&v245.guid.Data2;
            **&v245.guid.Data2 = 0;
          }
          if ( v93[1] )
          {
            j_j__free(v93[1]);
            v93 = *&v245.guid.Data2;
            *(*&v245.guid.Data2 + 4) = 0;
          }
          j__free(v93);
        }
        LOBYTE(v249) = 10;
        if ( !InterlockedDecrement((*&v245.guid.Data4[4] + 8)) )
        {
          if ( **&v245.guid.Data4[4] )
          {
            SysFreeString(**&v245.guid.Data4[4]);
            v94 = *&v245.guid.Data4[4];
            **&v245.guid.Data4[4] = 0;
          }
          else
          {
            v94 = *&v245.guid.Data4[4];
          }
          v95 = *(v94 + 4);
          if ( v95 )
          {
            j_j__free(v95);
            v96 = *&v245.guid.Data4[4];
            *(*&v245.guid.Data4[4] + 4) = 0;
          }
          else
          {
            v96 = *&v245.guid.Data4[4];
          }
          j__free(v96);
        }
        v97 = (v50 ? *v50 : 0);
        v73 = sub_F76640(v97, 0x80000000, 1u, 0, 3u, 0, 0);
        v245.List._Myheader = v73;
        if ( v73 == -1 )
        {
LABEL_533:
          v98 = operator new(0xCu);
          v245.List._Mysize = v98;
          *v245.guid.Data4 = v98;
          LOBYTE(v249) = 27;
          if ( v98 )
          {
            v98[1] = 0;
            v98[2] = 1;
            v99 = SysAllocString(L"\\en-us\\Gadget.xml");
            v100 = v245.List._Mysize;
            *v245.List._Mysize = v99;
            if ( !v99 )
              goto LABEL_9;
            v101 = v100;
          }
          else
          {
            v101 = 0;
            v245.List._Mysize = 0;
          }
          LOBYTE(v249) = 10;
          *v245.guid.Data4 = v101;
          if ( !v101 )
            goto LABEL_9;
          LOBYTE(v249) = 28;
          v102 = _bstr_t::operator+(&v234.strEventTrace.m_Data, &v225, v245.guid.Data4);
          v245.List._Myheader = v102;
          if ( &v245.field_4 != v102 )
          {
            if ( v50 )
            {
              if ( !InterlockedDecrement((v50 + 8)) )
              {
                if ( *v50 )
                {
                  SysFreeString(*v50);
                  *v50 = 0;
                }
                if ( *(v50 + 4) )
                {
                  j_j__free(*(v50 + 4));
                  *(v50 + 4) = 0;
                }
                j__free(v50);
              }
              v102 = v245.List._Myheader;
            }
            v50 = v102->field_0;
            v245.field_4 = v50;
            if ( v50 )
              InterlockedIncrement((v50 + 8));
          }
          v245.List._Myheader = v225;
          if ( v225 )
          {
            if ( !InterlockedDecrement(&v225[1].field_0) )
            {
              v103 = v245.List._Myheader;
              if ( v245.List._Myheader )
              {
                if ( v245.List._Myheader->field_0 )
                {
                  SysFreeString(v245.List._Myheader->field_0);
                  v103 = v245.List._Myheader;
                  v245.List._Myheader->field_0 = 0;
                }
                if ( v103[1] )
                {
                  j_j__free(v103[1]);
                  v103 = v245.List._Myheader;
                  v245.List._Myheader->field_4 = 0;
                }
                j__free(v103);
              }
            }
            v225 = 0;
          }
          LOBYTE(v249) = 10;
          if ( !InterlockedDecrement((v245.List._Mysize + 8)) )
          {
            v104 = v245.List._Mysize;
            if ( *v245.List._Mysize )
            {
              SysFreeString(*v245.List._Mysize);
              v104 = v245.List._Mysize;
              *v245.List._Mysize = 0;
            }
            if ( v104[1] )
            {
              j_j__free(v104[1]);
              v104 = v245.List._Mysize;
              *(v245.List._Mysize + 4) = 0;
            }
            j__free(v104);
          }
          v105 = (v50 ? *v50 : 0);
          v73 = sub_F76640(v105, 0x80000000, 1u, 0, 3u, 0, 0);
          v245.List._Myheader = v73;
          if ( v73 == -1 )
          {
            v106 = operator new(0xCu);
            v245.List._Mysize = v106;
            *v245.guid.Data4 = v106;
            LOBYTE(v249) = 29;
            if ( v106 )
            {
              v106[1] = 0;
              v106[2] = 1;
              v107 = SysAllocString(L"\\Gadget.xml");
              v108 = v245.List._Mysize;
              *v245.List._Mysize = v107;
              if ( !v107 )
                goto LABEL_9;
              v109 = v108;
            }
            else
            {
              v109 = 0;
              v245.List._Mysize = 0;
            }
            LOBYTE(v249) = 10;
            *v245.guid.Data4 = v109;
            if ( !v109 )
              goto LABEL_9;
            LOBYTE(v249) = 30;
            v110 = _bstr_t::operator+(&v234.strEventTrace.m_Data, &v215, v245.guid.Data4);
            v245.List._Myheader = v110;
            if ( &v245.field_4 != v110 )
            {
              if ( v50 )
              {
                if ( !InterlockedDecrement((v50 + 8)) )
                {
                  if ( *v50 )
                  {
                    SysFreeString(*v50);
                    *v50 = 0;
                  }
                  if ( *(v50 + 4) )
                  {
                    j_j__free(*(v50 + 4));
                    *(v50 + 4) = 0;
                  }
                  j__free(v50);
                }
                v110 = v245.List._Myheader;
              }
              v50 = v110->field_0;
              v245.field_4 = v50;
              if ( v50 )
                InterlockedIncrement((v50 + 8));
            }
            v245.List._Myheader = v215;
            if ( v215 )
            {
              if ( !InterlockedDecrement(&v215[1].field_0) )
              {
                v111 = v245.List._Myheader;
                if ( v245.List._Myheader )
                {
                  if ( v245.List._Myheader->field_0 )
                  {
                    SysFreeString(v245.List._Myheader->field_0);
                    v111 = v245.List._Myheader;
                    v245.List._Myheader->field_0 = 0;
                  }
                  if ( v111[1] )
                  {
                    j_j__free(v111[1]);
                    v111 = v245.List._Myheader;
                    v245.List._Myheader->field_4 = 0;
                  }
                  j__free(v111);
                }
              }
              v215 = 0;
            }
            LOBYTE(v249) = 10;
            if ( !InterlockedDecrement((v245.List._Mysize + 8)) )
            {
              v112 = v245.List._Mysize;
              if ( *v245.List._Mysize )
              {
                SysFreeString(*v245.List._Mysize);
                v112 = v245.List._Mysize;
                *v245.List._Mysize = 0;
              }
              if ( v112[1] )
              {
                j_j__free(v112[1]);
                v112 = v245.List._Mysize;
                *(v245.List._Mysize + 4) = 0;
              }
              j__free(v112);
            }
            v113 = (v50 ? *v50 : 0);
            v73 = sub_F76640(v113, 0x80000000, 1u, 0, 3u, 0, 0);
            v245.List._Myheader = v73;
            if ( v73 == -1 )
            {
              _bstr_t::operator=(&v245, &gszNullString);
              if ( v234.field_4 && !InterlockedDecrement((v234.field_4 + 8)) )
              {
                v114 = v234.field_4;
                if ( *v234.field_4 )
                {
                  SysFreeString(*v234.field_4);
                  v114 = v234.field_4;
                  *v234.field_4 = 0;
                }
                if ( v114[1] )
                {
                  j_j__free(v114[1]);
                  v114 = v234.field_4;
                  *(v234.field_4 + 4) = 0;
                }
                j__free(v114);
              }
              v234.field_4 = v234.strEventTrace.m_Data;
              if ( v234.strEventTrace.m_Data )
              {
                v115 = &v234.strEventTrace.m_Data->m_RefCount;
LABEL_367:
                InterlockedIncrement(v115);
                goto LABEL_368;
              }
              goto LABEL_368;
            }
          }
        }
      }
      *&v245.guid.Data4[4] = GetFileSize(v73, 0);
      v245.List._Mysize = operator new[](*&v245.guid.Data4[4]);
      *&v245.guid.Data2 = operator new[](2 * (*&v245.guid.Data4[4] + 1));
      NumberOfBytesRead = 0;
      ReadFile(v245.List._Myheader, v245.List._Mysize, *&v245.guid.Data4[4], &NumberOfBytesRead, 0);
      if ( NumberOfBytesRead >= 3
        && *v245.List._Mysize == -17
        && *(v245.List._Mysize + 1) == -69
        && *(v245.List._Mysize + 2) == -65 )
      {
        break;
      }
      if ( NumberOfBytesRead < 2 || *v245.List._Mysize != -1 || *(v245.List._Mysize + 1) != -2 )
      {
        v116 = MultiByteToWideChar(
                 0,
                 0,
                 v245.List._Mysize,
                 *&v245.guid.Data4[4],
                 *&v245.guid.Data2,
                 *&v245.guid.Data4[4]);
        goto LABEL_357;
      }
      v117 = 1;
      v118 = *&v245.guid.Data4[4] >> 1;
      *&v245.guid.Data4[4] = v118;
      if ( v118 > 1 )
      {
        v119 = *&v245.guid.Data2;
        v120 = v118;
        v121 = v245.List._Mysize;
        do
        {
          v122 = *(v121 + 2 * v117);
          v119 += 2;
          ++v117;
          *(v119 - 2) = v122;
        }
        while ( v117 < v120 );
        v50 = v245.field_4;
        v23 = v241;
        v118 = *&v245.guid.Data4[4];
      }
      *(*&v245.guid.Data2 + 2 * v118 - 2) = 0;
LABEL_358:
      _bstr_t::operator=(&v245, *&v245.guid.Data2);
      j_j__free(*&v245.guid.Data2);
      j_j__free(v245.List._Mysize);
      CloseHandle(v245.List._Myheader);
      if ( v234.field_4 && !InterlockedDecrement((v234.field_4 + 8)) )
      {
        v123 = v234.field_4;
        if ( *v234.field_4 )
        {
          SysFreeString(*v234.field_4);
          v123 = v234.field_4;
          *v234.field_4 = 0;
        }
        if ( v123[1] )
        {
          j_j__free(v123[1]);
          v123 = v234.field_4;
          *(v234.field_4 + 4) = 0;
        }
        j__free(v123);
      }
      v234.field_4 = v50;
      if ( v50 )
      {
        v115 = (v50 + 8);
        goto LABEL_367;
      }
LABEL_368:
      LOBYTE(v249) = 9;
      if ( v50 && !InterlockedDecrement((v50 + 8)) )
      {
        if ( *v50 )
        {
          SysFreeString(*v50);
          *v50 = 0;
        }
        if ( *(v50 + 4) )
        {
          j_j__free(*(v50 + 4));
          *(v50 + 4) = 0;
        }
        j__free(v50);
      }
      v124 = v245.strEventTrace.m_Data;
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
        v245.List._Myheader = (v127 + 3);
        if ( iswspace(v128) )
        {
          v129 = v245.List._Myheader;
          do
          {
            v130 = HIWORD(v129->field_0);
            v129 = (v129 + 2);
          }
          while ( iswspace(v130) );
          v245.List._Myheader = v129;
          v23 = v241;
        }
        v131 = operator new(0xCu);
        *&v245.guid.Data4[4] = v131;
        *v245.guid.Data4 = v131;
        LOBYTE(v249) = 31;
        if ( v131 )
        {
          v132 = v245.List._Myheader;
          v131[1] = 0;
          v131[2] = 1;
          v133 = SysAllocString(v132);
          v134 = *&v245.guid.Data4[4];
          **&v245.guid.Data4[4] = v133;
          if ( !v133 )
            goto LABEL_9;
          v135 = v134;
        }
        else
        {
          v135 = 0;
          *&v245.guid.Data4[4] = 0;
        }
        LOBYTE(v249) = 9;
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
          v135 = *&v245.guid.Data4[4];
        }
        v124 = v135;
        v245.strEventTrace.m_Data = v135;
        InterlockedIncrement(&v135->m_RefCount);
        if ( !InterlockedDecrement((*&v245.guid.Data4[4] + 8)) )
        {
          v136 = *&v245.guid.Data4[4];
          if ( **&v245.guid.Data4[4] )
          {
            SysFreeString(**&v245.guid.Data4[4]);
            v136 = *&v245.guid.Data4[4];
            **&v245.guid.Data4[4] = 0;
          }
          if ( v136[1] )
          {
            j_j__free(v136[1]);
            v136 = *&v245.guid.Data4[4];
            *(*&v245.guid.Data4[4] + 4) = 0;
          }
          j__free(v136);
        }
      }
      CoInitializeEx(0, 0);
      v234.strHeader.m_Data = 0;
      if ( Wow64EnableWow64FsRedirection )
      {
        Wow64EnableWow64FsRedirection(1u);
        TlsSetValue(gdwTlsIndex, 0x200);
      }
      v137 = CoCreateInstance(&rclsid, 0, 1u, &CLSID_IXMLDOMDocument, &v234.strHeader.m_Data);
      v138 = Wow64EnableWow64FsRedirection;
      *v245.guid.Data4 = v137;
      if ( Wow64EnableWow64FsRedirection )
      {
        Wow64EnableWow64FsRedirection(0);
        TlsSetValue(gdwTlsIndex, 0x100);
        v138 = Wow64EnableWow64FsRedirection;
        v137 = *v245.guid.Data4;
      }
      if ( !v137 )
      {
        v230 = 0;
        if ( v138 )
        {
          v138(1);
          TlsSetValue(gdwTlsIndex, 0x200);
        }
        if ( v124 )
          v139 = v124->m_wstr;
        else
          v139 = 0;
        (*(v234.strHeader.m_Data->m_wstr + 65))(v234.strHeader.m_Data, v139, &v230);
        v23 = v241;
        if ( Wow64EnableWow64FsRedirection )
        {
          Wow64EnableWow64FsRedirection(0);
          TlsSetValue(gdwTlsIndex, 0x100);
        }
        if ( v230 )
          goto LABEL_531;
        v245.List._Mysize = 0;
        (*(v234.strHeader.m_Data->m_wstr + 60))(v234.strHeader.m_Data, &v245.List._Mysize);
        if ( v245.List._Mysize )
        {
          *v245.guid.Data4 = 0;
          *&v234.Level = -1;
          v245.List._Myheader = -1;
          *&v245.guid.Data2 = 0;
          (*(*v245.List._Mysize + 36))(v245.List._Mysize, v245.guid.Data4);
          (*(*v245.List._Mysize + 44))(v245.List._Mysize, &v234.Level);
          (*(*v245.List._Mysize + 48))(v245.List._Mysize, &v245.List);
          (*(*v245.List._Mysize + 40))(v245.List._Mysize, &v245.guid.Data2);
          (*(*v245.List._Mysize + 8))(v245.List._Mysize);
        }
        if ( v230 )
        {
LABEL_531:
          v140 = operator new(0xCu);
          v245.List._Mysize = v140;
          *v245.guid.Data4 = v140;
          LOBYTE(v249) = 32;
          if ( v140 )
          {
            v140[1] = 0;
            v140[2] = 1;
            v141 = _com_util::ConvertBSTRToString("gadget");
            v142 = v245.List._Mysize;
            *v245.List._Mysize = v141;
          }
          else
          {
            v142 = 0;
            v245.List._Mysize = 0;
          }
          LOBYTE(v249) = 9;
          *v245.guid.Data4 = v142;
          if ( !v142 )
            goto LABEL_9;
          v143 = *v142;
          LOBYTE(v249) = 33;
          v144 = (*(v234.strHeader.m_Data->m_wstr + 37))(v234.strHeader.m_Data, v143, &v236);
          LOBYTE(v249) = 9;
          HIBYTE(v245.strHeader.m_Data) = v144 == 0;
          v145 = InterlockedDecrement((v245.List._Mysize + 8));
          v124 = v245.strEventTrace.m_Data;
          if ( !v145 )
          {
            v146 = v245.List._Mysize;
            if ( *v245.List._Mysize )
            {
              SysFreeString(*v245.List._Mysize);
              v146 = v245.List._Mysize;
              *v245.List._Mysize = 0;
            }
            if ( v146[1] )
            {
              j_j__free(v146[1]);
              v146 = v245.List._Mysize;
              *(v245.List._Mysize + 4) = 0;
            }
            j__free(v146);
          }
          if ( HIBYTE(v245.strHeader.m_Data) )
          {
            v147 = operator new(0xCu);
            v245.List._Mysize = v147;
            *v245.guid.Data4 = v147;
            LOBYTE(v249) = 34;
            if ( v147 )
            {
              v147[1] = 0;
              v147[2] = 1;
              v148 = _com_util::ConvertBSTRToString("name");
              v149 = v245.List._Mysize;
              *v245.List._Mysize = v148;
            }
            else
            {
              v149 = 0;
              v245.List._Mysize = 0;
            }
            LOBYTE(v249) = 9;
            *v245.guid.Data4 = v149;
            if ( !v149 )
              goto LABEL_9;
            v150 = *v149;
            LOBYTE(v249) = 35;
            v151 = (*(*v236 + 148))(v236, v150, &v245.guid);
            LOBYTE(v249) = 9;
            HIBYTE(v245.strHeader.m_Data) = v151 == 0;
            if ( !InterlockedDecrement((v245.List._Mysize + 8)) )
            {
              v152 = v245.List._Mysize;
              if ( *v245.List._Mysize )
              {
                SysFreeString(*v245.List._Mysize);
                v152 = v245.List._Mysize;
                *v245.List._Mysize = 0;
              }
              if ( v152[1] )
              {
                j_j__free(v152[1]);
                v152 = v245.List._Mysize;
                *(v245.List._Mysize + 4) = 0;
              }
              j__free(v152);
            }
            if ( HIBYTE(v245.strHeader.m_Data) )
            {
              sub_F8B0D0(&v234.guid.Data1, 0);
              (*(*v245.guid.Data1 + 104))(v245.guid.Data1, v234.guid.Data1);
              (*(*v245.guid.Data1 + 8))(v245.guid.Data1);
            }
            v153 = _bstr_t::_bstr_t(&v210, "description")->m_Data;
            LOBYTE(v249) = 36;
            if ( v153 )
              v154 = v153->m_wstr;
            else
              v154 = 0;
            v155 = (*(*v236 + 148))(v236, v154, &v245.guid);
            LOBYTE(v249) = 9;
            HIBYTE(v245.strHeader.m_Data) = v155 == 0;
            _bstr_t::_Free(&v210);
            if ( HIBYTE(v245.strHeader.m_Data) )
            {
              VariantInit(&pvarg);
              LOBYTE(v249) = 37;
              (*(*v245.guid.Data1 + 32))(v245.guid.Data1, &pvarg);
              sub_F8B0D0(v234.guid.Data4, 0);
              (*(*v245.guid.Data1 + 104))(v245.guid.Data1, *v234.guid.Data4);
              (*(*v245.guid.Data1 + 8))(v245.guid.Data1);
              LOBYTE(v249) = 9;
              VariantClear(&pvarg);
            }
            v156 = _bstr_t::_bstr_t(&v202, "author")->m_Data;
            LOBYTE(v249) = 38;
            if ( v156 )
              v157 = v156->m_wstr;
            else
              v157 = 0;
            v158 = (*(*v236 + 148))(v236, v157, &v245.guid);
            LOBYTE(v249) = 9;
            HIBYTE(v245.strHeader.m_Data) = v158 == 0;
            _bstr_t::_Free(&v202);
            if ( HIBYTE(v245.strHeader.m_Data) )
            {
              if ( !(*(*v245.guid.Data1 + 68))(v245.guid.Data1, &v221) )
              {
                v159 = _bstr_t::_bstr_t(&v200, "name")->m_Data;
                LOBYTE(v249) = 39;
                if ( v159 )
                  v160 = v159->m_wstr;
                else
                  v160 = 0;
                v161 = (*(*v221 + 28))(v221, v160, &v217);
                LOBYTE(v249) = 9;
                HIBYTE(v245.strHeader.m_Data) = v161 == 0;
                _bstr_t::_Free(&v200);
                if ( HIBYTE(v245.strHeader.m_Data) )
                {
                  sub_F8B0D0(&v234.guid.Data2, 0);
                  (*(*v217 + 104))(v217, *&v234.guid.Data2);
                  (*(*v217 + 8))(v217);
                }
                (*(*v221 + 8))(v221);
              }
              (*(*v245.guid.Data1 + 8))(v245.guid.Data1);
            }
            v162 = _bstr_t::_bstr_t(&v211, "version")->m_Data;
            LOBYTE(v249) = 40;
            if ( v162 )
              v163 = v162->m_wstr;
            else
              v163 = 0;
            v164 = (*(*v236 + 148))(v236, v163, &v245.guid);
            LOBYTE(v249) = 9;
            HIBYTE(v245.strHeader.m_Data) = v164 == 0;
            _bstr_t::_Free(&v211);
            v23 = v241;
            if ( HIBYTE(v245.strHeader.m_Data) )
            {
              sub_F8B0D0(&v234.guid.Data4[4], 0);
              (*(*v245.guid.Data1 + 104))(v245.guid.Data1, *&v234.guid.Data4[4]);
              (*(*v245.guid.Data1 + 8))(v245.guid.Data1);
            }
            v165 = _bstr_t::_bstr_t(&v205, "icons")->m_Data;
            LOBYTE(v249) = 41;
            if ( v165 )
              v166 = v165->m_wstr;
            else
              v166 = 0;
            v167 = (*(*v236 + 148))(v236, v166, &v245.guid);
            LOBYTE(v249) = 9;
            HIBYTE(v245.strHeader.m_Data) = v167 == 0;
            _bstr_t::_Free(&v205);
            v124 = v245.strEventTrace.m_Data;
            if ( HIBYTE(v245.strHeader.m_Data) )
            {
              if ( !(*(*v245.guid.Data1 + 48))(v245.guid.Data1, &v235) )
              {
                *v245.guid.Data4 = 4096;
                if ( !(*(*v235 + 36))(v235, &v237) )
                {
                  v168 = *v245.guid.Data4;
                  do
                  {
                    if ( !(*(*v237 + 68))(v237, &v244) )
                    {
                      VariantInit(&pvarSrc);
                      LOBYTE(v249) = 42;
                      v169 = _bstr_t::_bstr_t(&v209, "height")->m_Data;
                      LOBYTE(v249) = 43;
                      if ( v169 )
                        v170 = v169->m_wstr;
                      else
                        v170 = 0;
                      v171 = (*(*v244 + 28))(v244, v170, &v242);
                      LOBYTE(v249) = 42;
                      HIBYTE(v245.strHeader.m_Data) = v171 == 0;
                      _bstr_t::_Free(&v209);
                      if ( HIBYTE(v245.strHeader.m_Data) )
                      {
                        (*(*v242 + 32))(v242, &pvarSrc);
                        v172 = sub_F8AD20(&v199, &pvarSrc)->strEventTrace.m_Data;
                        if ( v172 )
                          v173 = v172->m_wstr;
                        else
                          v173 = 0;
                        v234.List._Mysize = _wtoi(v173);
                        _bstr_t::_Free(&v199);
                        (*(*v242 + 8))(v242);
                      }
                      v174 = _bstr_t::_bstr_t(&v207, "width")->m_Data;
                      LOBYTE(v249) = 44;
                      if ( v174 )
                        v175 = v174->m_wstr;
                      else
                        v175 = 0;
                      v176 = (*(*v244 + 28))(v244, v175, &v242);
                      LOBYTE(v249) = 42;
                      HIBYTE(v245.strHeader.m_Data) = v176 == 0;
                      _bstr_t::_Free(&v207);
                      v177 = v234.List._Mysize;
                      if ( HIBYTE(v245.strHeader.m_Data) )
                      {
                        (*(*v242 + 32))(v242, &pvarSrc);
                        v178 = sub_F8AD20(&v206, &pvarSrc)->strEventTrace.m_Data;
                        if ( v178 )
                          v179 = v178->m_wstr;
                        else
                          v179 = 0;
                        a3 = _wtoi(v179);
                        _bstr_t::_Free(&v206);
                        (*(*v242 + 8))(v242);
                      }
                      if ( v177 >= 16 && a3 >= 16 && v177 + a3 < v168 )
                      {
                        v180 = _bstr_t::_bstr_t(&v204, "src")->m_Data;
                        LOBYTE(v249) = 45;
                        v181 = v180 ? v180->m_wstr : 0;
                        v182 = (*(*v244 + 28))(v244, v181, &v242);
                        LOBYTE(v249) = 42;
                        HIBYTE(v245.strHeader.m_Data) = v182 == 0;
                        _bstr_t::_Free(&v204);
                        v183 = v234.List._Mysize;
                        if ( HIBYTE(v245.strHeader.m_Data) )
                        {
                          (*(*v242 + 32))(v242, &pvarSrc);
                          sub_F8AD20(&v238, &pvarSrc);
                          LOBYTE(v249) = 46;
                          if ( v238.m_Data )
                            v184 = v238.m_Data->m_wstr;
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
                            v183 = v234.List._Mysize;
                          }
                          _bstr_t::_bstr_t(&v213, L"\\");
                          LOBYTE(v249) = 47;
                          v186 = _bstr_t::operator+(&v234.strEventTrace.m_Data, &v220, &v213);
                          LOBYTE(v249) = 48;
                          *v245.guid.Data4 = _bstr_t::operator+(&v186->m_Data, &v201, &v238);
                          if ( &v234.List != *v245.guid.Data4 )
                          {
                            _bstr_t::_Free(&v234.List);
                            v187 = **v245.guid.Data4;
                            v234.List._Myheader = v187;
                            if ( v187 )
                              InterlockedIncrement(&v187[1].field_0);
                          }
                          _bstr_t::_Free(&v201);
                          _bstr_t::_Free(&v220);
                          LOBYTE(v249) = 46;
                          _bstr_t::_Free(&v213);
                          v168 = v183 + a3;
                          (*(*v242 + 8))(v242);
                          LOBYTE(v249) = 42;
                          _bstr_t::_Free(&v238);
                        }
                      }
                      (*(*v244 + 8))(v244);
                      LOBYTE(v249) = 9;
                      VariantClear(&pvarSrc);
                    }
                    (*(*v237 + 8))(v237);
                  }
                  while ( !(*(*v235 + 36))(v235, &v237) );
                  v124 = v245.strEventTrace.m_Data;
                  v23 = v241;
                }
                (*(*v235 + 8))(v235);
              }
              (*(*v245.guid.Data1 + 8))(v245.guid.Data1);
            }
            (*(*v236 + 8))(v236);
          }
        }
      }
      *v245.guid.Data4 = *v231;
      v188 = sub_F8AC50(*v245.guid.Data4, *(*v245.guid.Data4 + 4), &v232);
      v189 = v231[1];
      if ( (97612892 - v189) < 1 )
        goto LABEL_10;
      v231[1] = v189 + 1;
      *(*v245.guid.Data4 + 4) = v188;
      *v188[1] = v188;
      if ( v234.strHeader.m_Data )
        (*(v234.strHeader.m_Data->m_wstr + 2))(v234.strHeader.m_Data);
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
      LOBYTE(v249) = 0;
      sub_F8AE80(&v232);
      v23 = v23->_Myheader;
      v241 = v23;
      if ( v23 == a1a )
        goto LABEL_526;
    }
    v116 = MultiByteToWideChar(
             0xFDE9u,
             0,
             (v245.List._Mysize + 3),
             *&v245.guid.Data4[4] - 3,
             *&v245.guid.Data2,
             *&v245.guid.Data4[4]);
LABEL_357:
    *(*&v245.guid.Data2 + 2 * v116) = 0;
    goto LABEL_358;
  }
LABEL_526:
  v190 = a1a;
  v191 = a1a->_Myheader;
  v190->_Myheader = v190;
  v190->_Mysize = v190;
  if ( v191 != v190 )
  {
    do
    {
      v192 = v191->field_0;
      j__free(v191);
      v191 = v192;
    }
    while ( v192 != v190 );
  }
  j__free(v190);
  return 1;
}
// 10328CC: using guessed type wchar_t aProgramw6432[14];
// 1064C64: using guessed type int (__stdcall *IsWow64Process)(_DWORD, _DWORD);
// 1064C68: using guessed type int dword_1064C68;
// 1064C6C: using guessed type int (__stdcall *GetSystemDefaultLocaleName)(_DWORD, _DWORD);
// 1064C70: using guessed type int (__stdcall *GetUserDefaultLocaleName)(_DWORD, _DWORD);

//----- (00F8D790) --------------------------------------------------------
void *__cdecl sub_F8D790(HWND hWndIn)
{
  HWND v1; // ebx
  HMODULE v2; // eax
  const WCHAR ***v3; // esi
  const WCHAR **v4; // eax
  const WCHAR **v5; // eax
  void ***v6; // eax
  void *v7; // edi
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
  int v25; // eax
  HBITMAP v26; // ST40_4
  struct _IMAGELIST *v27; // eax
  HBITMAP v28; // ST40_4
  struct _IMAGELIST *v29; // eax
  _DWORD *v30; // eax
  OLECHAR *v31; // eax
  HICON v32; // ST44_4
  struct _IMAGELIST *v33; // eax
  _DWORD *v34; // eax
  OLECHAR *v35; // eax
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
  int v60; // ST08_4
  void **v61; // ebx
  void **v62; // esi
  int v64; // [esp+10h] [ebp-344h]
  void *v65; // [esp+14h] [ebp-340h]
  WCHAR *v66; // [esp+18h] [ebp-33Ch]
  void *v67; // [esp+1Ch] [ebp-338h]
  void *v68; // [esp+20h] [ebp-334h]
  void *v69; // [esp+24h] [ebp-330h]
  void *v70; // [esp+28h] [ebp-32Ch]
  void *v71; // [esp+2Ch] [ebp-328h]
  void *v72; // [esp+30h] [ebp-324h]
  int v73; // [esp+34h] [ebp-320h]
  void *v74; // [esp+38h] [ebp-31Ch]
  void *v75; // [esp+3Ch] [ebp-318h]
  void *v76; // [esp+40h] [ebp-314h]
  void *v77; // [esp+44h] [ebp-310h]
  void *v78; // [esp+48h] [ebp-30Ch]
  void *v79; // [esp+4Ch] [ebp-308h]
  void *v80; // [esp+50h] [ebp-304h]
  WCHAR *v81; // [esp+54h] [ebp-300h]
  void *v82; // [esp+58h] [ebp-2FCh]
  void *v83; // [esp+5Ch] [ebp-2F8h]
  int v84; // [esp+60h] [ebp-2F4h]
  void *v85; // [esp+64h] [ebp-2F0h]
  void *v86; // [esp+68h] [ebp-2ECh]
  void *v87; // [esp+6Ch] [ebp-2E8h]
  void *v88; // [esp+70h] [ebp-2E4h]
  void *ppv1; // [esp+74h] [ebp-2E0h]
  WCHAR *ppv3; // [esp+78h] [ebp-2DCh]
  void *v91; // [esp+7Ch] [ebp-2D8h]
  void *v92; // [esp+80h] [ebp-2D4h]
  HWND hWnd; // [esp+84h] [ebp-2D0h]
  HBITMAP hbmImage; // [esp+88h] [ebp-2CCh]
  HBITMAP v95; // [esp+8Ch] [ebp-2C8h]
  HICON hicon; // [esp+90h] [ebp-2C4h]
  char v97; // [esp+94h] [ebp-2C0h]
  int v98; // [esp+350h] [ebp-4h]

  v1 = hWndIn;
  hWnd = hWndIn;
  sub_F8E210(&v85);
  v98 = 0;
  if ( !SHCreateItemFromParsingName )
  {
    v2 = LoadLibraryW(L"Shell32.dll");
    SHCreateItemFromParsingName = GetProcAddress(v2, "SHCreateItemFromParsingName");
  }
  v87 = _wcsdup(&gszNullString);
  v88 = _wcsdup(&gszNullString);
  v86 = _wcsdup(&gszNullString);
  v91 = _wcsdup(&gszNullString);
  v92 = _wcsdup(&gszNullString);
  hbmImage = _wcsdup(&gszNullString);
  v3 = v85;
  if ( !v85 || (v4 = *v85) == 0 )
    v4 = &gszNullString;
  v95 = _wcsdup(v4);
  if ( !v3 || (v5 = *v3) == 0 )
    v5 = &gszNullString;
  ppv3 = _wcsdup(v5);
  LOBYTE(v98) = 8;
  ppv1 = sub_F73FF0(hWndIn, 7, 0xFFFFFFFF, 7, &ppv3, &v95, &hbmImage);
  free(ppv3);
  free(v95);
  free(hbmImage);
  free(v92);
  free(v91);
  free(v86);
  free(v88);
  LOBYTE(v98) = 0;
  free(v87);
  v84 = 0;
  v83 = sub_F8E320(0, 0);
  LOBYTE(v98) = 9;
  sub_F8B1A0(&v85, &v83);
  v6 = v83;
  v7 = v85;
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
          if ( !v7 || (v16 = *v7) == 0 )
            v16 = &gszNullString;
          v86 = _wcsdup(v16);
          if ( !v7 || (v17 = *v7) == 0 )
            v17 = &gszNullString;
          v88 = _wcsdup(v17);
          v18 = *(i + 6);
          if ( !v18 || (v19 = *v18) == 0 )
            v19 = &gszNullString;
          v87 = _wcsdup(v19);
          LOBYTE(v98) = 15;
          v20 = sub_F73D40(v1, &v87, &v88, &v86, &v79, &v65, &ppv3, &v64);
          free(v87);
          free(v88);
          free(v86);
          free(v79);
          LOBYTE(v98) = 10;
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
              v82 = _wcsdup(&gszNullString);
              if ( !v7 || (v21 = *v7) == 0 )
                v21 = &gszNullString;
              v68 = _wcsdup(v21);
              if ( !v7 || (v22 = *v7) == 0 )
                v22 = &gszNullString;
              v66 = _wcsdup(v22);
              LOBYTE(v98) = 23;
              ppv1 = sub_F73FF0(hWnd, 7, 0xFFFFFFFF, 7, &v66, &v68, &v82);
              free(v66);
              free(v68);
              free(v82);
              free(v71);
              free(v77);
              free(v67);
              free(v75);
              LOBYTE(v98) = 10;
              free(v69);
            }
            v23 = *(i + 10);
            v24 = -1;
            v92 = -1;
            if ( v23 )
              v25 = *v23;
            else
              v25 = 0;
            if ( SHCreateItemFromParsingName(v25, 0, &CLSID_IShellItem2, &v73) >= 0 )
            {
              v91 = 0;
              if ( (**v73)(v73, &CLSID_IShellItemImageFactory, &v91) >= 0 )
              {
                hbmImage = 0;
                v95 = 0;
                (*(*v91 + 12))(v91, 16, 16, 0, &hbmImage);
                (*(*v91 + 12))(v91, 32, 32, 0, &v95);
                if ( hbmImage )
                {
                  v26 = hbmImage;
                  v27 = SendMessageW(hWnd, 0x1002u, 1u, 0);
                  v24 = ImageList_Add(v27, v26, 0);
                  DeleteObject(hbmImage);
                }
                if ( v95 )
                {
                  v28 = v95;
                  v29 = SendMessageW(hWnd, 0x1002u, 0, 0);
                  v92 = ImageList_Add(v29, v28, 0);
                  DeleteObject(v95);
                }
                (*(*v91 + 8))(v91);
              }
              (*(*v73 + 8))(v73);
            }
            if ( v24 < 0 )
            {
              hicon = 0;
              memset(&v97, 0, 0x2B0u);
              v30 = *(i + 10);
              v31 = (v30 ? *v30 : 0);
              if ( sub_F810C0(v31, 0, &hicon, 0x2B4u, 0x101u) )
              {
                v32 = hicon;
                v33 = SendMessageW(hWnd, 0x1002u, 1u, 0);
                v24 = ImageList_ReplaceIcon(v33, -1, v32);
                DestroyIcon(hicon);
              }
            }
            if ( v92 < 0 )
            {
              hicon = 0;
              memset(&v97, 0, 0x2B0u);
              v34 = *(i + 10);
              v35 = (v34 ? *v34 : 0);
              if ( sub_F810C0(v35, 0, &hicon, 0x2B4u, 0x100u) )
              {
                v36 = hicon;
                v37 = SendMessageW(hWnd, 0x1002u, 0, 0);
                v92 = ImageList_ReplaceIcon(v37, -1, v36);
                DestroyIcon(hicon);
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
                  hbmImage = v40;
                  *v40 = 0;
                  v41 = malloc(2u);
                  v95 = v41;
                  *v41 = 0;
                  v42 = *(i + 10);
                  LOBYTE(v98) = 25;
                  if ( v42 )
                    v43 = *v42;
                  v24 = sub_F74ED0();
                  free(v95);
                  free(hbmImage);
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
            v78 = _wcsdup(v51);
            v52 = *(i + 4);
            if ( !v52 || (v53 = *v52) == 0 )
              v53 = &gszNullString;
            v80 = _wcsdup(v53);
            v54 = *(i + 6);
            if ( !v54 || (v55 = *v54) == 0 )
              v55 = &gszNullString;
            v81 = _wcsdup(v55);
            v56 = *(i + 9);
            LOBYTE(v98) = 32;
            if ( v56 )
              v57 = *v56;
            v58 = *(i + 2);
            v59 = i[12];
            v60 = v24;
            v1 = hWnd;
            sub_F73FF0(hWnd, v60, ppv1, 15, &v81, &v80, &v78);
            free(v81);
            free(v80);
            free(v78);
            free(v76);
            free(v74);
            free(v72);
            free(v70);
          }
          else
          {
            v1 = hWnd;
          }
          LOBYTE(v98) = 9;
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
      sub_F8AE80(v61 + 2);
      j__free(v61);
      v6 = v83;
      v61 = v62;
    }
    while ( v62 != v83 );
  }
  j__free(v6);
  if ( v7 && !InterlockedDecrement(v7 + 2) )
  {
    if ( *v7 )
    {
      SysFreeString(*v7);
      *v7 = 0;
    }
    if ( *(v7 + 1) )
    {
      j_j__free(*(v7 + 1));
      *(v7 + 1) = 0;
    }
    j__free(v7);
  }
  return ppv1;
}
// 1032A90: using guessed type GUID CLSID_IShellItem2;
// 1047B6C: using guessed type GUID CLSID_IShellItemImageFactory;
// 1064C74: using guessed type int (__stdcall *SHCreateItemFromParsingName)(_DWORD, _DWORD, _DWORD, _DWORD);

//----- (00F8E1B0) --------------------------------------------------------
_bstr_t *__cdecl sub_F8E1B0(_bstr_t *a1, int a2)
{
  wchar_t Dest; // [esp+8h] [ebp-20Ch]

  _swprintf(&Dest, L"Section %d", a2);
  _bstr_t::_bstr_t(a1, &Dest);
  return a1;
}

//----- (00F8E210) --------------------------------------------------------
_bstr_t *__cdecl sub_F8E210(_bstr_t *a1)
{
  FARPROC SHGetFolderPathW; // eax
  HMODULE v2; // eax
  WCHAR *v3; // ecx
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
    v3 = gpAccountInfo->szProfileImgPath;
    v4 = szAppPath - gpAccountInfo->szProfileImgPath;
    do
    {
      v5 = *v3;
      ++v3;
      *(v3 + v4 - 2) = v5;
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
  _bstr_t::_bstr_t(a1, szAppPath);
  return a1;
}
// 1032848: using guessed type wchar_t aAppdataLocal[15];
// 1032868: using guessed type wchar_t aMicrosoftWindo[40];

//----- (00F8E320) --------------------------------------------------------
_DWORD *__stdcall sub_F8E320(_DWORD *a1, _DWORD *a2)
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

//----- (00F8E360) --------------------------------------------------------
void __thiscall sub_F8E360(_DWORD *this)
{
  _DWORD *v1; // ebx
  _DWORD *v2; // esi
  _DWORD *v3; // edi

  v1 = this;
  v2 = **this;
  **this = *this;
  *(*this + 4) = *this;
  this[1] = 0;
  if ( v2 != *this )
  {
    do
    {
      v3 = *v2;
      sub_F8AE80(v2 + 2);
      j__free(v2);
      v2 = v3;
    }
    while ( v3 != *v1 );
  }
}

//----- (00F8E3A0) --------------------------------------------------------
void *__cdecl sub_F8E3A0(int a1, void *a2, wchar_t *a3, void *a4, char a5)
{
  HWND v5; // edi
  wchar_t *v6; // ebx
  const wchar_t *v7; // eax
  const wchar_t *v8; // eax
  OLECHAR **v9; // eax
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
  void *v29; // edi
  const wchar_t *v30; // ecx
  const wchar_t *v31; // eax
  const wchar_t *v32; // eax
  HANDLE v33; // esi
  int v35; // [esp+10h] [ebp-334h]
  int v36; // [esp+14h] [ebp-330h]
  int v37; // [esp+18h] [ebp-32Ch]
  int v38; // [esp+1Ch] [ebp-328h]
  void *v39; // [esp+20h] [ebp-324h]
  unsigned __int16 *v40; // [esp+24h] [ebp-320h]
  wchar_t *v41; // [esp+28h] [ebp-31Ch]
  int a2a; // [esp+2Ch] [ebp-318h]
  int v43; // [esp+30h] [ebp-314h]
  int v44; // [esp+34h] [ebp-310h]
  int v45; // [esp+38h] [ebp-30Ch]
  void *v46; // [esp+3Ch] [ebp-308h]
  HANDLE hFindFile; // [esp+40h] [ebp-304h]
  WCHAR *ppszArgs; // [esp+44h] [ebp-300h]
  void *v49; // [esp+48h] [ebp-2FCh]
  WCHAR *ppv; // [esp+4Ch] [ebp-2F8h]
  WCHAR *v51; // [esp+50h] [ebp-2F4h]
  void *v52; // [esp+54h] [ebp-2F0h]
  void *v53; // [esp+58h] [ebp-2ECh]
  void *v54; // [esp+5Ch] [ebp-2E8h]
  void *v55; // [esp+60h] [ebp-2E4h]
  void *v56; // [esp+64h] [ebp-2E0h]
  void *v57; // [esp+68h] [ebp-2DCh]
  void *v58; // [esp+6Ch] [ebp-2D8h]
  void *v59; // [esp+70h] [ebp-2D4h]
  void *v60; // [esp+74h] [ebp-2D0h]
  void *v61; // [esp+78h] [ebp-2CCh]
  void *v62; // [esp+7Ch] [ebp-2C8h]
  void *v63; // [esp+80h] [ebp-2C4h]
  void *v64; // [esp+84h] [ebp-2C0h]
  WCHAR *v65; // [esp+88h] [ebp-2BCh]
  void *v66; // [esp+8Ch] [ebp-2B8h]
  void *v67; // [esp+90h] [ebp-2B4h]
  void *v68; // [esp+94h] [ebp-2B0h]
  WCHAR *v69; // [esp+98h] [ebp-2ACh]
  int v70; // [esp+9Ch] [ebp-2A8h]
  int v71; // [esp+A0h] [ebp-2A4h]
  void *v72; // [esp+A4h] [ebp-2A0h]
  void *v73; // [esp+A8h] [ebp-29Ch]
  void *v74; // [esp+ACh] [ebp-298h]
  WCHAR *ppv3; // [esp+B0h] [ebp-294h]
  void *v76; // [esp+B4h] [ebp-290h]
  void *v77; // [esp+B8h] [ebp-28Ch]
  void *v78; // [esp+BCh] [ebp-288h]
  wchar_t *v79; // [esp+C0h] [ebp-284h]
  void *v80; // [esp+C4h] [ebp-280h]
  void *v81; // [esp+C8h] [ebp-27Ch]
  void *v82; // [esp+CCh] [ebp-278h]
  int a1a; // [esp+D0h] [ebp-274h]
  void *v84; // [esp+D4h] [ebp-270h]
  void *v85; // [esp+D8h] [ebp-26Ch]
  LPCWSTR lpszFileName; // [esp+DCh] [ebp-268h]
  char v87; // [esp+E3h] [ebp-261h]
  struct _WIN32_FIND_DATAW FindFileData; // [esp+E4h] [ebp-260h]
  int v89; // [esp+340h] [ebp-4h]

  v5 = a1;
  a1a = a1;
  v79 = a3;
  v71 = 0;
  v89 = 0;
  v80 = malloc(2u);
  *v80 = 0;
  v78 = malloc(2u);
  *v78 = 0;
  v6 = malloc(2u);
  v41 = v6;
  *v6 = 0;
  v85 = malloc(2u);
  *v85 = 0;
  v81 = malloc(2u);
  *v81 = 0;
  v74 = malloc(2u);
  *v74 = 0;
  if ( a2 == -1 && a5 )
  {
    v84 = _wcsdup(&gszNullString);
    v82 = _wcsdup(&gszNullString);
    v76 = _wcsdup(&gszNullString);
    v77 = _wcsdup(&gszNullString);
    ppv3 = _wcsdup(&gszNullString);
    v73 = _wcsdup(&gszNullString);
    v7 = &gszNullString;
    if ( a3 )
      v7 = a3;
    v72 = _wcsdup(v7);
    v8 = &gszNullString;
    if ( a3 )
      v8 = a3;
    lpszFileName = _wcsdup(v8);
    LOBYTE(v89) = 14;
    sub_F73FF0(a1, 2, 0xFFFFFFFF, 0, &lpszFileName, &v72, &v73);
    free(lpszFileName);
    free(v72);
    free(v73);
    free(ppv3);
    free(v77);
    free(v76);
    free(v82);
    free(v84);
  }
  CopyStringToString(&a4, L"\\", 0x7FFFFFFFu, 0);
  v9 = PE_CopyString(&ppv, &a4, "*");
  LOBYTE(v89) = 15;
  v10 = sub_F80FC0(*v9, &FindFileData);
  LOBYTE(v89) = 6;
  hFindFile = v10;
  free(ppv);
  if ( v10 != -1 )
  {
    do
    {
      v11 = malloc(2u);
      v40 = v11;
      *v11 = 0;
      if ( FindFileData.cFileName[0] != 46 && _wcsicmp(FindFileData.cFileName, L"AutorunsDisabled") )
      {
        PE_CopyString(&lpszFileName, &a4, FindFileData.cFileName);
        v12 = lpszFileName;
        LOBYTE(v89) = 17;
        v84 = (lpszFileName + 1);
        do
        {
          v13 = *v12;
          ++v12;
        }
        while ( v13 );
        if ( ((v12 - v84) >> 1) < 4 )
          goto LABEL_54;
        v14 = wcschr(lpszFileName, 0);
        if ( _wcsicmp(v14 - 4, L".lnk")
          || (v15 = sub_F74FB0(&ppszArgs, v5, lpszFileName),
              v71 |= 1u,
              v16 = v11,
              v11 = _wcsdup(*v15),
              v40 = v11,
              free(v16),
              v87 = 1,
              !wcslen(v11)) )
        {
LABEL_54:
          v87 = 0;
        }
        if ( v71 & 1 )
        {
          v71 &= 0xFFFFFFFE;
          free(ppszArgs);
        }
        v17 = malloc(2u);
        if ( v87 )
        {
          v82 = v17;
          v84 = v17;
          *v17 = 0;
          a2a = malloc(2u);
          *a2a = 0;
          v43 = 0;
          v44 = 0;
          v45 = 0;
          LOBYTE(v89) = 19;
          sub_F76CC0(v11, &a2a);
          v18 = v81;
          v81 = _wcsdup(lpszFileName);
          free(v18);
          v19 = sub_F74EE0(&v46, a1a, &a2a, 0);
          v20 = v6;
          v6 = _wcsdup(*v19);
          v41 = v6;
          free(v20);
          free(v46);
          if ( wcsrchr(v6, 0x5Cu) )
          {
            v21 = wcsrchr(v6, 0x5Cu);
            v22 = _wcsdup(v21 + 1);
            v84 = v22;
            free(v82);
          }
          else
          {
            v22 = _wcsdup(v6);
            v84 = v22;
            free(v82);
          }
          v23 = sub_F74EE0(&v39, a1a, &a2a, 0);
          v82 = v85;
          v85 = _wcsdup(*v23);
          free(v82);
          free(v39);
          v82 = sub_F74ED0();
          v24 = &gszNullString;
          if ( v79 )
            v24 = v79;
          v77 = _wcsdup(v24);
          v76 = _wcsdup(FindFileData.cFileName);
          LOBYTE(v89) = 21;
          v87 = sub_F73D40(a1a, &v76, &v77, &lpszFileName, &v85, &v80, &v74, &v70);
          free(v76);
          LOBYTE(v89) = 19;
          free(v77);
          if ( v87 )
          {
            if ( a2 != -1 )
              goto LABEL_55;
            if ( sub_F763B0(v22) )
            {
              v57 = _wcsdup(&gszNullString);
              v66 = _wcsdup(&gszNullString);
              v59 = _wcsdup(&gszNullString);
              v60 = _wcsdup(&gszNullString);
              v64 = _wcsdup(&gszNullString);
              v72 = _wcsdup(&gszNullString);
              v25 = &gszNullString;
              if ( v79 )
                v25 = v79;
              v73 = _wcsdup(v25);
              v26 = &gszNullString;
              if ( v79 )
                v26 = v79;
              ppv3 = _wcsdup(v26);
              LOBYTE(v89) = 29;
              a2 = sub_F73FF0(a1a, 2, 0xFFFFFFFF, 0, &ppv3, &v73, &v72);
              free(ppv3);
              free(v73);
              free(v72);
              free(v64);
              free(v60);
              free(v59);
              free(v66);
              free(v57);
              if ( a2 != -1 )
              {
LABEL_55:
                v55 = _wcsdup(&gszNullString);
                v69 = _wcsdup(FindFileData.cFileName);
                LOBYTE(v89) = 31;
                sub_F73FF0(a1a, v82, a2, 7, &v69, &lpszFileName, &v85);
                free(v69);
                free(v55);
              }
            }
          }
          sub_F721F0(&a2a);
          free(v22);
          v5 = a1a;
        }
        else
        {
          v35 = v17;
          *v17 = 0;
          v36 = 0;
          v37 = 0;
          v38 = 0;
          LOBYTE(v89) = 32;
          sub_F77040(lpszFileName, &v35);
          v27 = v81;
          v81 = _wcsdup(lpszFileName);
          free(v27);
          v28 = sub_F74EE0(&v49, a1a, &v35, 0);
          v29 = v85;
          v85 = _wcsdup(*v28);
          free(v29);
          free(v49);
          v5 = a1a;
          v84 = sub_F74ED0();
          v30 = &gszNullString;
          if ( v79 )
            v30 = v79;
          v53 = _wcsdup(v30);
          v62 = _wcsdup(FindFileData.cFileName);
          LOBYTE(v89) = 34;
          v87 = sub_F73D40(v5, &v62, &v53, &lpszFileName, &v85, &v80, &v74, &v70);
          free(v62);
          LOBYTE(v89) = 32;
          free(v53);
          if ( v87 )
          {
            if ( a2 != -1 )
              goto LABEL_56;
            if ( sub_F763B0(FindFileData.cFileName) )
            {
              v67 = _wcsdup(&gszNullString);
              v68 = _wcsdup(&gszNullString);
              v61 = _wcsdup(&gszNullString);
              v56 = _wcsdup(&gszNullString);
              v54 = _wcsdup(&gszNullString);
              v58 = _wcsdup(&gszNullString);
              v31 = &gszNullString;
              if ( v79 )
                v31 = v79;
              v52 = _wcsdup(v31);
              v32 = &gszNullString;
              if ( v79 )
                v32 = v79;
              v51 = _wcsdup(v32);
              LOBYTE(v89) = 42;
              a2 = sub_F73FF0(v5, 2, 0xFFFFFFFF, 0, &v51, &v52, &v58);
              free(v51);
              free(v52);
              free(v58);
              free(v54);
              free(v56);
              free(v61);
              free(v68);
              free(v67);
              if ( a2 != -1 )
              {
LABEL_56:
                v63 = _wcsdup(&gszNullString);
                v65 = _wcsdup(FindFileData.cFileName);
                LOBYTE(v89) = 44;
                sub_F73FF0(v5, v84, a2, 6, &v65, &lpszFileName, &v85);
                free(v65);
                free(v63);
              }
            }
          }
          sub_F721F0(&v35);
        }
        free(lpszFileName);
        LOBYTE(v89) = 6;
        free(v11);
      }
      else
      {
        LOBYTE(v89) = 6;
        free(v11);
      }
      v33 = hFindFile;
    }
    while ( FindNextFileW(hFindFile, &FindFileData) );
    FindClose(v33);
  }
  free(v74);
  free(v81);
  free(v85);
  free(v6);
  free(v78);
  free(v80);
  free(a4);
  return a2;
}

//----- (00F8EFA0) --------------------------------------------------------
void *__cdecl sub_F8EFA0(int a1, int a2, OLECHAR *psz, LPCWSTR lpValueName)
{
  void *v4; // eax

  v4 = sub_F8EFE0(a1, a2, psz, lpValueName, 0xFFFFFFFF, 1);
  return sub_F8EFE0(a1, a2, psz, lpValueName, v4, 0);
}

//----- (00F8EFE0) --------------------------------------------------------
void *__cdecl sub_F8EFE0(int a1, int a2, OLECHAR *psz, LPCWSTR lpValueName, void *a5, char a6)
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
  else if ( sub_F81520(hKey, lpValueName, 0, 0, &ppv) )
  {
    v7 = a5;
    RegCloseKey(hKey);
  }
  else
  {
    if ( !a6 )
    {
      CopyStringToString(&ppv, L"\\", 0x7FFFFFFFu, 0);
      CopyStringToString(&ppv, L"AutorunsDisabled", 0x7FFFFFFFu, 0);
    }
    v7 = sub_F8F0E0(a1, ppv, ppv, a5, a6);
    RegCloseKey(hKey);
  }
  free(ppv);
  return v7;
}

//----- (00F8F0E0) --------------------------------------------------------
void *__cdecl sub_F8F0E0(int a1, wchar_t *a2, wchar_t *a3, void *a4, char a5)
{
  wchar_t *v5; // esi
  wchar_t *v6; // ebx
  wchar_t *v7; // edi
  const wchar_t **v8; // eax
  wchar_t *v9; // edi
  wchar_t *v10; // ebx
  wchar_t *v11; // eax
  void *v12; // ebx
  int v14; // [esp+10h] [ebp-28h]
  int v15; // [esp+14h] [ebp-24h]
  int v16; // [esp+18h] [ebp-20h]
  int v17; // [esp+1Ch] [ebp-1Ch]
  wchar_t *v18; // [esp+20h] [ebp-18h]
  void *v19; // [esp+24h] [ebp-14h]
  wchar_t *v20; // [esp+28h] [ebp-10h]
  int v21; // [esp+34h] [ebp-4h]
  wchar_t *v22; // [esp+48h] [ebp+10h]

  v5 = malloc(2u);
  v18 = v5;
  *v5 = 0;
  v21 = 0;
  v6 = malloc(2u);
  v20 = v6;
  *v6 = 0;
  v7 = a3;
  if ( !a3 )
    v7 = a2;
  v22 = v7;
  v14 = malloc(2u);
  *v14 = 0;
  v15 = 0;
  v16 = 0;
  v17 = 0;
  LOBYTE(v21) = 2;
  sub_F77040(v7, &v14);
  v8 = sub_F74EE0(&v19, a1, &v14, 1);
  v9 = _wcsdup(*v8);
  v20 = v9;
  free(v6);
  free(v19);
  if ( wcslen(v9) )
  {
    v10 = v5;
    v5 = _wcsdup(v22);
    v18 = v5;
    free(v10);
    v11 = _wcsdup(v5);
    v12 = sub_F8E3A0(a1, a4, v22, v11, a5);
  }
  else
  {
    v12 = a4;
  }
  sub_F721F0(&v14);
  free(v9);
  free(v5);
  return v12;
}

//----- (00F8F210) --------------------------------------------------------
int __cdecl PE_CopyString2(WCHAR **pszResult, WCHAR *ppszText1, WCHAR **ppszText2)
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
  PE_CopyStringEx(pszResult, &ppszText1, ppszText2);
  free(pszText1);
  return pszResult;
}

//----- (00F8F260) --------------------------------------------------------
void __cdecl sub_F8F260(int a1, int a2, wchar_t *a3, void *a4, int a5)
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
  Data_t_bstr_t **v22; // eax
  _bstr_t *v23; // eax
  Data_t_bstr_t *v24; // eax
  wchar_t *v25; // eax
  OLECHAR *v26; // edi
  const wchar_t *v27; // eax
  WCHAR *v28; // eax
  WCHAR *v29; // eax
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
  int (__stdcall **v40)(int, void *, wchar_t **); // ecx
  int v41; // ecx
  _WORD *v42; // eax
  Data_t_bstr_t *v43; // edi
  OLECHAR *v44; // eax
  Data_t_bstr_t **v45; // eax
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
  const wchar_t **v57; // eax
  void *v58; // ebx
  tagKeyName *v59; // esi
  unsigned int v60; // eax
  tagKeyName *v61; // eax
  LSTATUS v62; // esi
  int v63; // esi
  wchar_t *v64; // eax
  const wchar_t **v65; // eax
  void *v66; // esi
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
  void *v97; // ecx
  void **v98; // eax
  void *v99; // esi
  const wchar_t *v100; // [esp-14h] [ebp-1B0h]
  int v101; // [esp-10h] [ebp-1ACh]
  int v102; // [esp-Ch] [ebp-1A8h]
  void *v103; // [esp-8h] [ebp-1A4h]
  int *v104; // [esp-4h] [ebp-1A0h]
  int a2a; // [esp+10h] [ebp-18Ch]
  int v106; // [esp+14h] [ebp-188h]
  int v107; // [esp+18h] [ebp-184h]
  int v108; // [esp+1Ch] [ebp-180h]
  WCHAR *pszResult; // [esp+20h] [ebp-17Ch]
  VARIANTARG pvarg; // [esp+24h] [ebp-178h]
  void *v111; // [esp+34h] [ebp-168h]
  int v112; // [esp+38h] [ebp-164h]
  int v113; // [esp+3Ch] [ebp-160h]
  int v114; // [esp+40h] [ebp-15Ch]
  int v115; // [esp+44h] [ebp-158h]
  WCHAR *v116; // [esp+48h] [ebp-154h]
  _bstr_t v117; // [esp+4Ch] [ebp-150h]
  int v118; // [esp+50h] [ebp-14Ch]
  _bstr_t v119; // [esp+54h] [ebp-148h]
  WCHAR *ppv; // [esp+58h] [ebp-144h]
  _bstr_t v121; // [esp+5Ch] [ebp-140h]
  _bstr_t v122; // [esp+60h] [ebp-13Ch]
  void *v123; // [esp+64h] [ebp-138h]
  void *v124; // [esp+68h] [ebp-134h]
  void *v125; // [esp+6Ch] [ebp-130h]
  void *v126; // [esp+70h] [ebp-12Ch]
  void *v127; // [esp+74h] [ebp-128h]
  WCHAR *ppv3; // [esp+78h] [ebp-124h]
  _bstr_t v129; // [esp+7Ch] [ebp-120h]
  void *v130; // [esp+80h] [ebp-11Ch]
  void *v131; // [esp+84h] [ebp-118h]
  _bstr_t v132; // [esp+88h] [ebp-114h]
  void *v133; // [esp+8Ch] [ebp-110h]
  void *v134; // [esp+90h] [ebp-10Ch]
  void *v135; // [esp+94h] [ebp-108h]
  WCHAR *v136; // [esp+98h] [ebp-104h]
  WCHAR *v137; // [esp+9Ch] [ebp-100h]
  void *v138; // [esp+A0h] [ebp-FCh]
  void *v139; // [esp+A4h] [ebp-F8h]
  void *v140; // [esp+A8h] [ebp-F4h]
  void *v141; // [esp+ACh] [ebp-F0h]
  void *v142; // [esp+B0h] [ebp-ECh]
  _bstr_t v143; // [esp+B4h] [ebp-E8h]
  void *v144; // [esp+B8h] [ebp-E4h]
  _bstr_t v145; // [esp+BCh] [ebp-E0h]
  void *v146; // [esp+C0h] [ebp-DCh]
  int v147; // [esp+C4h] [ebp-D8h]
  void *v148; // [esp+C8h] [ebp-D4h]
  void *v149; // [esp+CCh] [ebp-D0h]
  void *v150; // [esp+D0h] [ebp-CCh]
  void *v151; // [esp+D4h] [ebp-C8h]
  void *v152; // [esp+D8h] [ebp-C4h]
  void *v153; // [esp+DCh] [ebp-C0h]
  void *v154; // [esp+E0h] [ebp-BCh]
  void *v155; // [esp+E4h] [ebp-B8h]
  void *v156; // [esp+E8h] [ebp-B4h]
  void *v157; // [esp+ECh] [ebp-B0h]
  volatile LONG *v158; // [esp+F0h] [ebp-ACh]
  BSTR bstrString; // [esp+F4h] [ebp-A8h]
  int v160; // [esp+F8h] [ebp-A4h]
  void *v161; // [esp+FCh] [ebp-A0h]
  _bstr_t v162; // [esp+100h] [ebp-9Ch]
  int v163; // [esp+104h] [ebp-98h]
  _bstr_t v164; // [esp+108h] [ebp-94h]
  _bstr_t v165; // [esp+10Ch] [ebp-90h]
  int v166; // [esp+110h] [ebp-8Ch]
  void *v167; // [esp+114h] [ebp-88h]
  _bstr_t v168; // [esp+118h] [ebp-84h]
  void *v169; // [esp+11Ch] [ebp-80h]
  void *v170; // [esp+120h] [ebp-7Ch]
  HKEY hKey; // [esp+124h] [ebp-78h]
  int *v172; // [esp+128h] [ebp-74h]
  std__List *v173; // [esp+12Ch] [ebp-70h]
  void *v174; // [esp+130h] [ebp-6Ch]
  void *v175; // [esp+134h] [ebp-68h]
  void *v176; // [esp+138h] [ebp-64h]
  int *v177; // [esp+13Ch] [ebp-60h]
  void *v178; // [esp+140h] [ebp-5Ch]
  void *v179; // [esp+144h] [ebp-58h]
  int *v180; // [esp+148h] [ebp-54h]
  void *v181; // [esp+14Ch] [ebp-50h]
  WCHAR *v182; // [esp+150h] [ebp-4Ch]
  OLECHAR *psz; // [esp+154h] [ebp-48h]
  void *v184; // [esp+158h] [ebp-44h]
  void *v185; // [esp+15Ch] [ebp-40h]
  int *v186; // [esp+160h] [ebp-3Ch]
  LPCWSTR lpszKeyName; // [esp+164h] [ebp-38h]
  void *v188; // [esp+168h] [ebp-34h]
  void *v189; // [esp+16Ch] [ebp-30h]
  void *v190; // [esp+170h] [ebp-2Ch]
  OLECHAR *v191; // [esp+174h] [ebp-28h]
  _bstr_t v192; // [esp+178h] [ebp-24h]
  unsigned int v193; // [esp+17Ch] [ebp-20h]
  OLECHAR *ppszText2; // [esp+180h] [ebp-1Ch]
  LPCWSTR lpszText2; // [esp+184h] [ebp-18h]
  wchar_t *v196; // [esp+188h] [ebp-14h]
  bool v197; // [esp+18Fh] [ebp-Dh]
  int v198; // [esp+198h] [ebp-4h]

  v193 = 0;
  lpszKeyName = 0;
  v5 = a5;
  v198 = 0;
  v177 = 0;
  v6 = SysFreeString;
  v7 = InterlockedDecrement;
  if ( (*(*a5 + 56))(a5, 1, &v177) < 0 )
    goto LABEL_196;
  v189 = 0;
  (*(*v177 + 28))(v177, &v189);
  v8 = 0;
  if ( v189 <= 0 )
    goto LABEL_195;
  do
  {
    v186 = 0;
    v184 = v8 + 1;
    pvarg.vt = 3;
    pvarg.lVal = (v8 + 1);
    v9 = _mm_loadu_si128(&pvarg);
    v104 = &v186;
    LOBYTE(v198) = 1;
    v10 = *v177;
    v11 = v177;
    _mm_storeu_si128(&v100, v9);
    v12 = (*(v10 + 32))(v11, v100, v101, v102, v103, v104);
    LOBYTE(v198) = 0;
    VariantClear(&pvarg);
    if ( v12 < 0 )
      goto LABEL_193;
    bstrString = 0;
    v104 = &bstrString;
    v103 = v186;
    if ( (*(*v186 + 28))(v186, &bstrString) < 0 )
      goto LABEL_192;
    _bstr_t::_bstr_t(&v132, bstrString);
    LOBYTE(v198) = 2;
    _bstr_t::_bstr_t(&v143, L"\\");
    LOBYTE(v198) = 3;
    v13 = _bstr_t::operator+(&a4, &v122, &v143);
    LOBYTE(v198) = 4;
    _bstr_t::operator+(&v13->m_Data, &v179, &v132);
    _bstr_t::_Free(&v122);
    _bstr_t::_Free(&v143);
    LOBYTE(v198) = 8;
    _bstr_t::_Free(&v132);
    v147 = 1;
    v104 = &v147;
    v103 = v186;
    (*(*v186 + 40))(v186, &v147);
    v167 = 0;
    v104 = &v167;
    v14 = *v186;
    v197 = v147 != 0;
    v103 = v186;
    if ( (*(v14 + 76))(v186, &v167) < 0 )
      goto LABEL_183;
    v180 = 0;
    v104 = &v180;
    v103 = v167;
    if ( (*(*v167 + 68))(v167, &v180) < 0 )
      goto LABEL_182;
    v15 = 0;
    v104 = &v188;
    v188 = 0;
    v16 = *v180;
    v103 = 1;
    v102 = v180;
    v163 = 0;
    if ( (*(v16 + 32))(v180, 1, &v188) < 0 )
      goto LABEL_181;
    do
    {
      v166 = -1;
      v104 = &v166;
      v103 = v188;
      (*(*v188 + 36))(v188, &v166);
      if ( !v166 )
      {
        v104 = &lpszText2;
        lpszText2 = 0;
        v103 = &unk_104781C;
        v17 = *v188;
        v102 = v188;
        if ( (*v17)(v188, &unk_104781C, &lpszText2) >= 0 )
        {
          v196 = 0;
          lpszKeyName = 0;
          v191 = 0;
          v18 = *lpszText2;
          v104 = &v196;
          v103 = lpszText2;
          if ( (*(v18 + 40))(lpszText2, &v196) >= 0 && v196 )
          {
            v104 = &lpszKeyName;
            v103 = lpszText2;
            (*(*lpszText2 + 48))(lpszText2, &lpszKeyName);
            v104 = &v191;
            v103 = lpszText2;
            (*(*lpszText2 + 56))(lpszText2, &v191);
            v104 = *sub_F7F8D0(&v111, v196);
            LOBYTE(v198) = 9;
            _bstr_t::_bstr_t(&v168, v104);
            free(v111);
            v19 = malloc(2u);
            ppszText2 = v19;
            *v19 = 0;
            v144 = malloc(2u);
            *v144 = 0;
            LOBYTE(v198) = 13;
            v20 = sub_F81150(a1, gpszSystemPathInfo, v196, &v144);
            v21 = v168.m_Data;
            if ( v20 || wcschr(v196, 0x5Cu) || !v191 )
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
              _bstr_t::_bstr_t(&v145, L"\\");
              LOBYTE(v198) = 14;
              v22 = _bstr_t::_bstr_t(&v117, v191);
              LOBYTE(v198) = 15;
              v23 = _bstr_t::operator+(v22, &v119, &v145);
              LOBYTE(v198) = 16;
              v24 = _bstr_t::operator+(&v23->m_Data, &v121, &v168)->m_Data;
              if ( v24 )
                v25 = v24->m_wstr;
              else
                v25 = 0;
              sub_F72280(&ppszText2, v25);
              _bstr_t::_Free(&v121);
              _bstr_t::_Free(&v119);
              _bstr_t::_Free(&v117);
              _bstr_t::_Free(&v145);
              v26 = ppszText2;
            }
            v175 = malloc(2u);
            *v175 = 0;
            v174 = malloc(2u);
            *v174 = 0;
            v28 = PE_CopyString2(&pszResult, L"\"", &ppszText2);
            v29 = PE_CopyString(&ppv, v28, L"\" ");
            PE_CopyString(&v173, v29, lpszKeyName);
            free(ppv);
            free(pszResult);
            a2a = malloc(2u);
            *a2a = 0;
            v106 = 0;
            v107 = 0;
            v108 = 0;
            LOBYTE(v198) = 20;
            sub_F76CC0(v173, &a2a);
            sub_F74EE0(&v176, a1, &a2a, 0);
            LOBYTE(v198) = 21;
            v100 = &v174;
            v160 = sub_F74ED0();
            v170 = malloc(2u);
            *v170 = 0;
            if ( !v21 || (v30 = v21->m_wstr) == 0 )
              v30 = &gszNullString;
            v140 = _wcsdup(v30);
            v31 = &gszNullString;
            if ( a3 )
              v31 = a3;
            v123 = _wcsdup(v31);
            if ( !v21 || (v32 = v21->m_wstr) == 0 )
              v32 = &gszNullString;
            v127 = _wcsdup(v32);
            LOBYTE(v198) = 25;
            v33 = sub_F73D40(a1, &v127, &v123, &v140, &v176, &v175, &v170, &v118);
            free(v127);
            free(v123);
            free(v140);
            if ( v33 )
            {
              if ( *a2 == -1 )
              {
                v148 = _wcsdup(&gszNullString);
                v139 = _wcsdup(&gszNullString);
                v150 = _wcsdup(&gszNullString);
                v141 = _wcsdup(&gszNullString);
                v152 = _wcsdup(&gszNullString);
                v157 = _wcsdup(&gszNullString);
                v34 = &gszNullString;
                if ( a3 )
                  v34 = a3;
                v154 = _wcsdup(v34);
                v35 = &gszNullString;
                if ( a3 )
                  v35 = a3;
                ppv3 = _wcsdup(v35);
                v36 = a1;
                LOBYTE(v198) = 33;
                v37 = sub_F73FF0(a1, 2, *a2, 0, &ppv3, &v154, &v157);
                v104 = ppv3;
                *a2 = v37;
                free(v104);
                free(v154);
                free(v157);
                free(v152);
                free(v141);
                free(v150);
                free(v139);
                free(v148);
              }
              else
              {
                v36 = a1;
              }
              v135 = _wcsdup(&gszNullString);
              if ( !v21 || (v38 = v21->m_wstr) == 0 )
                v38 = &gszNullString;
              v146 = _wcsdup(v38);
              if ( !v179 || (v39 = *v179) == 0 )
                v39 = &gszNullString;
              v137 = _wcsdup(v39);
              v103 = -1;
              v102 = 0;
              v101 = 0;
              LOBYTE(v198) = 36;
              v100 = &v135;
              sub_F73FF0(v36, v160, *a2, 9, &v137, &v146, &v176);
              free(v137);
              free(v146);
              free(v135);
            }
            free(v170);
            free(v176);
            sub_F721F0(&a2a);
            free(v173);
            free(v174);
            free(v175);
            free(v144);
            free(v26);
            LOBYTE(v198) = 8;
            _bstr_t::_Free(&v168);
            v6 = SysFreeString;
            v15 = v163;
          }
          v104 = lpszText2;
          (*(*lpszText2 + 8))(lpszText2);
        }
      }
      if ( v166 != 5 )
        goto LABEL_179;
      v104 = &v196;
      v196 = 0;
      v103 = &unk_104783C;
      v40 = *v188;
      v102 = v188;
      if ( (*v40)(v188, &unk_104783C, &v196) < 0 )
        goto LABEL_179;
      lpszText2 = 0;
      v160 = 0;
      v104 = &lpszText2;
      v41 = *v196;
      v103 = v196;
      (*(v41 + 40))(v196, &lpszText2);
      v104 = &v160;
      v103 = v196;
      (*(*v196 + 48))(v196, &v160);
      v42 = malloc(2u);
      v178 = v42;
      *v42 = 0;
      v43 = 0;
      v192.m_Data = 0;
      v44 = 0;
      LOBYTE(v198) = 38;
      v191 = 0;
      while ( 1 )
      {
        _bstr_t::_bstr_t(&v165, (&off_105AA1C)[v44]);
        LOBYTE(v198) = 39;
        _bstr_t::_bstr_t(&v162, L"\\");
        LOBYTE(v198) = 40;
        _bstr_t::_bstr_t(&v164, lpszText2);
        LOBYTE(v198) = 41;
        v45 = _bstr_t::_bstr_t(&v129, L"CLSID\\");
        LOBYTE(v198) = 42;
        v46 = _bstr_t::operator+(v45, &v131, &v164);
        LOBYTE(v198) = 43;
        v47 = _bstr_t::operator+(&v46->m_Data, &v142, &v162);
        LOBYTE(v198) = 44;
        v48 = _bstr_t::operator+(&v47->m_Data, &v133, &v165);
        if ( &v192 != v48 )
        {
          _bstr_t::_Free(&v192);
          v43 = v48->m_Data;
          v192.m_Data = v43;
          if ( v43 )
            InterlockedIncrement(&v43->m_RefCount);
        }
        v49 = v133;
        if ( v133 )
        {
          if ( !InterlockedDecrement(v133 + 2) && v49 )
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
          v133 = 0;
        }
        v50 = v142;
        if ( v142 )
        {
          if ( !InterlockedDecrement(v142 + 2) && v50 )
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
          v142 = 0;
        }
        v51 = v131;
        if ( v131 )
        {
          if ( !InterlockedDecrement(v131 + 2) && v51 )
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
          v131 = 0;
        }
        v52 = v129.m_Data;
        if ( v129.m_Data )
        {
          if ( !InterlockedDecrement(&v129.m_Data->m_RefCount) && v52 )
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
          v129.m_Data = 0;
        }
        v53 = v164.m_Data;
        if ( v164.m_Data )
        {
          if ( !InterlockedDecrement(&v164.m_Data->m_RefCount) )
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
          v164.m_Data = 0;
        }
        v54 = v162.m_Data;
        if ( v162.m_Data )
        {
          if ( !InterlockedDecrement(&v162.m_Data->m_RefCount) )
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
          v162.m_Data = 0;
        }
        v55 = v165.m_Data;
        LOBYTE(v198) = 38;
        if ( v165.m_Data )
        {
          if ( !InterlockedDecrement(&v165.m_Data->m_RefCount) )
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
          v165.m_Data = 0;
        }
        v56 = _wcsdup(L"HKCR\\CLSID\\");
        lpszKeyName = v56;
        v57 = PE_CopyString(&v116, &lpszKeyName, lpszText2);
        v58 = v178;
        v100 = *v57;
        v178 = _wcsdup(v100);
        free(v58);
        free(v116);
        free(v56);
        if ( v43 )
          v59 = v43->m_wstr;
        else
          v59 = 0;
        v104 = &hKey;
        v60 = TlsGetValue(gdwTlsIndex);
        if ( PE_OpenKey(HKEY_CLASSES_ROOT, v59, 0, v60 | 1, v104) )
        {
          v61 = (v43 ? v43->m_wstr : 0);
          if ( PE_OpenKey(HKEY_CLASSES_ROOT, v61, 0, 1u, &hKey) )
            goto LABEL_126;
        }
        ppszText2 = malloc(2u);
        *ppszText2 = 0;
        LOBYTE(v198) = 45;
        v62 = sub_F81520(hKey, &gszNullString, 0, 0, &ppszText2);
        if ( !v62 )
        {
          _bstr_t::operator=(&v192, ppszText2);
          v43 = v192.m_Data;
        }
        RegCloseKey(hKey);
        v104 = ppszText2;
        if ( !v62 )
          break;
        LOBYTE(v198) = 38;
        free(v104);
LABEL_126:
        v6 = SysFreeString;
        v44 = (v191 + 1);
        v191 = v44;
        if ( v44 >= 4 )
          goto LABEL_129;
      }
      free(v104);
LABEL_129:
      v112 = malloc(2u);
      *v112 = 0;
      v113 = 0;
      v114 = 0;
      v115 = 0;
      v181 = malloc(2u);
      *v181 = 0;
      v169 = malloc(2u);
      *v169 = 0;
      v190 = malloc(2u);
      *v190 = 0;
      v63 = -1;
      LOBYTE(v198) = 49;
      if ( v191 >= 4 )
      {
        _bstr_t::operator=(&v192, lpszText2);
        v43 = v192.m_Data;
        if ( v192.m_Data )
          v67 = v192.m_Data->m_wstr;
        else
          v67 = 0;
        sub_F77040(v67, &v112);
      }
      else
      {
        if ( v43 )
          v64 = v43->m_wstr;
        else
          v64 = 0;
        sub_F77040(v64, &v112);
        v65 = sub_F74EE0(&v125, a1, &v112, 0);
        v66 = v190;
        v190 = _wcsdup(*v65);
        free(v66);
        free(v125);
        v63 = sub_F74ED0();
      }
      v161 = malloc(2u);
      *v161 = 0;
      if ( !wcslen(v190) )
        goto LABEL_243;
      if ( !v43 || (v68 = v43->m_wstr) == 0 )
        v68 = &gszNullString;
      v130 = _wcsdup(v68);
      v69 = &gszNullString;
      v70 = v193 | 1;
      if ( a3 )
        v69 = a3;
      v138 = _wcsdup(v69);
      v71 = v70 | 2;
      if ( !v43 || (v72 = v43->m_wstr) == 0 )
        v72 = &gszNullString;
      v124 = _wcsdup(v72);
      v198 = 53;
      v193 = v71 | 4;
      lpszKeyName = (v71 | 4);
      if ( sub_F73D40(a1, &v124, &v138, &v130, &v190, &v181, &v161, &v158) )
        v73 = 1;
      else
LABEL_243:
        v73 = 0;
      v74 = v193;
      if ( v193 & 4 )
      {
        v193 &= 0xFFFFFFFB;
        free(v124);
        v74 = v193;
      }
      if ( v74 & 2 )
      {
        v193 = v74 & 0xFFFFFFFD;
        free(v138);
        v74 = v193;
      }
      v198 = 50;
      if ( v74 & 1 )
      {
        v193 = v74 & 0xFFFFFFFE;
        free(v130);
      }
      if ( v73 )
      {
        if ( *a2 == -1 )
        {
          v149 = _wcsdup(&gszNullString);
          v151 = _wcsdup(&gszNullString);
          v153 = _wcsdup(&gszNullString);
          v155 = _wcsdup(&gszNullString);
          v156 = _wcsdup(&gszNullString);
          v134 = _wcsdup(&gszNullString);
          v75 = &gszNullString;
          if ( a3 )
            v75 = a3;
          v126 = _wcsdup(v75);
          v76 = &gszNullString;
          if ( a3 )
            v76 = a3;
          v136 = _wcsdup(v76);
          v77 = a1;
          LOBYTE(v198) = 61;
          v78 = sub_F73FF0(a1, 2, *a2, 0, &v136, &v126, &v134);
          v104 = v136;
          *a2 = v78;
          free(v104);
          free(v126);
          free(v134);
          free(v156);
          free(v155);
          free(v153);
          free(v151);
          free(v149);
        }
        else
        {
          v77 = a1;
        }
        psz = _wcsdup(&gszNullString);
        if ( !v43 || (v79 = v43->m_wstr) == 0 )
          v79 = &gszNullString;
        v185 = _wcsdup(v79);
        if ( !v179 || (v80 = *v179) == 0 )
          v80 = &gszNullString;
        v182 = _wcsdup(v80);
        v103 = -1;
        v102 = 0;
        v101 = 0;
        LOBYTE(v198) = 64;
        v100 = &psz;
        sub_F73FF0(v77, v63, *a2, 9, &v182, &v185, &v190);
        free(v182);
        free(v185);
        LOBYTE(v198) = 50;
        free(psz);
      }
      v104 = v196;
      (*(*v196 + 8))(v196);
      free(v161);
      free(v190);
      free(v169);
      free(v181);
      sub_F721F0(&v112);
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
      LOBYTE(v198) = 8;
      free(v178);
      v15 = v163;
LABEL_179:
      v104 = v188;
      (*(*v188 + 8))(v188);
      ++v15;
      v188 = 0;
      v104 = &v188;
      v163 = v15;
      v81 = *v180;
      v103 = (v15 + 1);
      v102 = v180;
      v6 = SysFreeString;
    }
    while ( (*(v81 + 32))(v180, v15 + 1, &v188) >= 0 );
    v7 = InterlockedDecrement;
LABEL_181:
    v104 = v180;
    (*(*v180 + 8))(v180);
LABEL_182:
    v104 = v167;
    (*(*v167 + 8))(v167);
LABEL_183:
    v6(bstrString);
    v82 = v179;
    LOBYTE(v198) = 0;
    if ( v179 )
    {
      if ( !v7(v179 + 2) && v82 )
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
      v179 = 0;
    }
LABEL_192:
    v104 = v186;
    (*(*v186 + 8))(v186);
LABEL_193:
    v8 = v184;
  }
  while ( v184 < v189 );
  v5 = a5;
LABEL_195:
  v104 = v177;
  (*(*v177 + 8))(v177);
LABEL_196:
  v83 = *v5;
  v104 = &v172;
  v103 = 0;
  v102 = v5;
  v172 = 0;
  if ( (*(v83 + 40))(v5, 0, &v172) >= 0 )
  {
    for ( i = 1; ; i = (v182 + 1) )
    {
      v182 = i;
      a5 = 0;
      pvarg.vt = 3;
      pvarg.lVal = i;
      v85 = _mm_loadu_si128(&pvarg);
      v104 = &a5;
      LOBYTE(v198) = 65;
      v86 = *v172;
      v87 = v172;
      _mm_storeu_si128(&v100, v85);
      v88 = (*(v86 + 32))(v87, v100, v101, v102, v103, v104);
      LOBYTE(v198) = 0;
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
      v184 = v90;
      LOBYTE(v198) = 66;
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
      LOBYTE(v198) = 0;
      v158 = v91;
      if ( !v91 )
        goto LABEL_202;
      LOBYTE(v198) = 67;
      v93 = operator new(0xCu);
      v94 = v93;
      v184 = v93;
      LOBYTE(v198) = 68;
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
      LOBYTE(v198) = 67;
      v184 = v94;
      if ( !v94 )
LABEL_202:
        _com_issue_error(-2147024882);
      v104 = a5;
      LOBYTE(v198) = 69;
      v96 = _bstr_t::operator+(&a4, &v185, &v184);
      v103 = v97;
      LOBYTE(v198) = 70;
      _bstr_t::operator+(&v96->m_Data, &v103, &v158);
      sub_F8F260(a1, a2, a3, v103, v104);
      v189 = v185;
      if ( v185 )
      {
        if ( !InterlockedDecrement(v185 + 2) )
        {
          v98 = v189;
          if ( v189 )
          {
            if ( *v189 )
            {
              v6(*v189);
              v98 = v189;
              *v189 = 0;
            }
            if ( v98[1] )
            {
              j_j__free(v98[1]);
              v98 = v189;
              *(v189 + 1) = 0;
            }
            j__free(v98);
          }
        }
        v185 = 0;
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
      LOBYTE(v198) = 0;
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
    v104 = v172;
    (*(*v172 + 8))(v172);
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

//----- (00F90760) --------------------------------------------------------
void __cdecl sub_F90760(int a1)
{
  int v1; // ebx
  _WORD *v2; // eax
  _WORD *v3; // eax
  _WORD *v4; // eax
  const wchar_t *v5; // eax
  const wchar_t *v6; // ecx
  unsigned int dwNameIndex; // esi
  const WCHAR ***v8; // eax
  const WCHAR **v9; // eax
  const WCHAR ***v10; // eax
  const WCHAR **v11; // eax
  WCHAR *v12; // eax
  WCHAR **v13; // eax
  int v14; // eax
  const wchar_t *v15; // edx
  char v16; // bl
  void *v17; // ebx
  const wchar_t *v18; // ecx
  const wchar_t *v19; // ecx
  void *v20; // ST30_4
  int v21; // [esp+10h] [ebp-E0h]
  int v22; // [esp+14h] [ebp-DCh]
  int v23; // [esp+18h] [ebp-D8h]
  int v24; // [esp+1Ch] [ebp-D4h]
  int dwFlags; // [esp+20h] [ebp-D0h]
  _bstr_t bstrAppName; // [esp+24h] [ebp-CCh]
  WCHAR *v27; // [esp+28h] [ebp-C8h]
  LPVOID pszWorkingDirectory; // [esp+2Ch] [ebp-C4h]
  WCHAR *v29; // [esp+30h] [ebp-C0h]
  int a2; // [esp+34h] [ebp-BCh]
  _bstr_t bstrName; // [esp+38h] [ebp-B8h]
  int v32; // [esp+3Ch] [ebp-B4h]
  ITaskTrigger *pTaskTrigger; // [esp+40h] [ebp-B0h]
  void *v34; // [esp+44h] [ebp-ACh]
  void *v35; // [esp+48h] [ebp-A8h]
  WCHAR *v36; // [esp+4Ch] [ebp-A4h]
  void *v37; // [esp+50h] [ebp-A0h]
  LPVOID szApplicationName; // [esp+54h] [ebp-9Ch]
  void *v39; // [esp+58h] [ebp-98h]
  void *v40; // [esp+5Ch] [ebp-94h]
  void *v41; // [esp+60h] [ebp-90h]
  void *v42; // [esp+64h] [ebp-8Ch]
  void *ppv1; // [esp+68h] [ebp-88h]
  void *v44; // [esp+6Ch] [ebp-84h]
  LPCWSTR pszParameters; // [esp+70h] [ebp-80h]
  void *v46; // [esp+74h] [ebp-7Ch]
  void *v47; // [esp+78h] [ebp-78h]
  ITaskScheduler *ppv; // [esp+7Ch] [ebp-74h]
  int v49; // [esp+80h] [ebp-70h]
  void *v50; // [esp+84h] [ebp-6Ch]
  IEnumWorkItems *pEnumWorkItems; // [esp+88h] [ebp-68h]
  void *v52; // [esp+8Ch] [ebp-64h]
  void *wTaskCount; // [esp+90h] [ebp-60h]
  WCHAR *ppv3; // [esp+94h] [ebp-5Ch]
  WCHAR *hKey; // [esp+98h] [ebp-58h]
  void *v56; // [esp+9Ch] [ebp-54h]
  std__List *v57; // [esp+A0h] [ebp-50h]
  LPVOID pszNames; // [esp+A4h] [ebp-4Ch]
  void *cbRet; // [esp+A8h] [ebp-48h]
  ITask *pTask; // [esp+ACh] [ebp-44h]
  TASK_TRIGGER TaskTrigger; // [esp+B0h] [ebp-40h]
  int v62; // [esp+ECh] [ebp-4h]

  v1 = a1;
  v49 = a1;
  if ( !gKeyNameMap._Mypair._Myval2._Mysize )
  {
    if ( GetVersion() < 6u )
    {
      v2 = malloc(2u);
      v52 = v2;
      *v2 = 0;
      v62 = 0;
      v3 = malloc(2u);
      v50 = v3;
      *v3 = 0;
      v4 = malloc(2u);
      v47 = v4;
      *v4 = 0;
      wTaskCount = _wcsdup(&gszNullString);
      pTask = _wcsdup(&gszNullString);
      cbRet = _wcsdup(&gszNullString);
      pszNames = _wcsdup(&gszNullString);
      v56 = _wcsdup(&gszNullString);
      v57 = _wcsdup(&gszNullString);
      v5 = &gszNullString;
      if ( off_105AA18 )
        v5 = off_105AA18;
      hKey = _wcsdup(v5);
      v6 = &gszNullString;
      if ( off_105AA18 )
        v6 = off_105AA18;
      ppv3 = _wcsdup(v6);
      LOBYTE(v62) = 10;
      ppv1 = sub_F73FF0(a1, 2, 0xFFFFFFFF, 0, &ppv3, &hKey, &v57);
      free(ppv3);
      free(hKey);
      free(v57);
      free(v56);
      free(pszNames);
      free(cbRet);
      free(pTask);
      LOBYTE(v62) = 2;
      free(wTaskCount);
      if ( CoInitializeEx(0, 0) >= 0
        && CoCreateInstance(&CLSID_CLSID_CTaskScheduler, 0, 1u, &CLSID_ITaskScheduler, &ppv) >= 0 )
      {
        pEnumWorkItems = 0;
        if ( ppv->lpVtbl->Enum(ppv, &pEnumWorkItems) >= 0 )
        {
          for ( cbRet = 0; pEnumWorkItems->lpVtbl->Next(pEnumWorkItems, 2, &pszNames, &cbRet) >= 0; cbRet = 0 )
          {
            if ( !cbRet )
              break;
            dwNameIndex = 0;
            if ( cbRet )
            {
              do
              {
                if ( ppv->lpVtbl->Activate(ppv, *(pszNames + dwNameIndex), &CLSID_ITask, &pTask) >= 0 )
                {
                  wTaskCount = 0;
                  pTask->lpVtbl->GetTriggerCount(pTask, &wTaskCount);
                  if ( wTaskCount > 0u && pTask->lpVtbl->GetTrigger(pTask, 0, &pTaskTrigger) >= 0 )
                  {
                    *&TaskTrigger.cbTriggerSize = sizeof(TASK_TRIGGER);
                    memset(&TaskTrigger.wBeginYear, 0, 0x2Cu);
                    if ( pTaskTrigger->lpVtbl->GetTrigger(pTaskTrigger, &TaskTrigger) >= 0
                      && pTask->lpVtbl->GetApplicationName(pTask, &szApplicationName) >= 0 )
                    {
                      v8 = *_bstr_t::_bstr_t(&bstrAppName, szApplicationName);
                      if ( !v8 || (v9 = *v8) == 0 )
                        v9 = &gszNullString;
                      hKey = _wcsdup(v9);
                      LOBYTE(v62) = 11;
                      _bstr_t::_Free(&bstrAppName);
                      v10 = *_bstr_t::_bstr_t(&bstrName, *(pszNames + dwNameIndex));
                      if ( !v10 || (v11 = *v10) == 0 )
                        v11 = &gszNullString;
                      ppv3 = _wcsdup(v11);
                      LOBYTE(v62) = 12;
                      _bstr_t::_Free(&bstrName);
                      pTask->lpVtbl->GetParameters(pTask, &pszParameters);
                      pTask->lpVtbl->GetFlags(pTask, &dwFlags);
                      pTask->lpVtbl->GetWorkingDirectory(pTask, &pszWorkingDirectory);
                      v57 = malloc(2u);
                      LOWORD(v57->_Mypair._Myval2._Myhead) = 0;
                      v12 = PE_CopyString(&v29, &hKey, L" ");
                      v13 = PE_CopyString(&v27, v12, pszParameters);
                      CopyStringToString(&v57, *v13, 0x7FFFFFFFu, 0);
                      free(v27);
                      free(v29);
                      v21 = malloc(2u);
                      *v21 = 0;
                      v22 = 0;
                      v23 = 0;
                      v24 = 0;
                      LOBYTE(v62) = 14;
                      sub_F76CC0(v57, &v21);
                      sub_F74EE0(&v56, v1, &v21, 0);
                      LOBYTE(v62) = 15;
                      v14 = sub_F74ED0();
                      v15 = &gszNullString;
                      a2 = v14;
                      if ( off_105AA18 )
                        v15 = off_105AA18;
                      v35 = _wcsdup(v15);
                      LOBYTE(v62) = 16;
                      v16 = sub_F73D40(v1, &ppv3, &v35, &hKey, &v56, &v52, &v47, &v32);
                      free(v35);
                      if ( v16 )
                      {
                        v17 = ppv1;
                        if ( ppv1 == -1 )
                        {
                          v42 = _wcsdup(&gszNullString);
                          v44 = _wcsdup(&gszNullString);
                          v39 = _wcsdup(&gszNullString);
                          v37 = _wcsdup(&gszNullString);
                          v41 = _wcsdup(&gszNullString);
                          v46 = _wcsdup(&gszNullString);
                          v18 = &gszNullString;
                          if ( off_105AA18 )
                            v18 = off_105AA18;
                          v34 = _wcsdup(v18);
                          v19 = &gszNullString;
                          if ( off_105AA18 )
                            v19 = off_105AA18;
                          v36 = _wcsdup(v19);
                          LOBYTE(v62) = 24;
                          v17 = sub_F73FF0(v49, 2, v17, 0, &v36, &v34, &v46);
                          ppv1 = v17;
                          free(v36);
                          free(v34);
                          free(v46);
                          free(v41);
                          free(v37);
                          free(v39);
                          free(v44);
                          free(v42);
                        }
                        v40 = _wcsdup(&gszNullString);
                        LOBYTE(v62) = 25;
                        v20 = v17;
                        v1 = v49;
                        sub_F73FF0(v49, a2, v20, 9, &ppv3, &hKey, &v56);
                        free(v40);
                      }
                      else
                      {
                        v1 = v49;
                      }
                      CoTaskMemFree(szApplicationName);
                      CoTaskMemFree(pszParameters);
                      CoTaskMemFree(pszWorkingDirectory);
                      free(v56);
                      sub_F721F0(&v21);
                      free(v57);
                      free(ppv3);
                      LOBYTE(v62) = 2;
                      free(hKey);
                    }
                  }
                }
                CoTaskMemFree(*(pszNames + dwNameIndex++));
              }
              while ( dwNameIndex < cbRet );
            }
            CoTaskMemFree(pszNames);
          }
          pEnumWorkItems->lpVtbl->Release(pEnumWorkItems);
          ppv->lpVtbl->Release(ppv);
        }
      }
      free(v47);
      free(v50);
      free(v52);
    }
    else
    {
      sub_F90EA0(a1);
    }
  }
}
// 1032AD0: using guessed type GUID CLSID_ITask;

//----- (00F90EA0) --------------------------------------------------------
void __cdecl sub_F90EA0(int a1)
{
  const wchar_t *v1; // esi
  const wchar_t *v2; // eax
  __m128i v3; // xmm0
  __m128i v4; // xmm0
  LPVOID v5; // ecx
  int v6; // edx
  int v7; // edi
  void **v8; // eax
  void *v9; // edx
  int v10; // eax
  int v11; // esi
  void *v12; // ecx
  int v13; // ecx
  void **v14; // [esp-40h] [ebp-F0h]
  void **v15; // [esp-3Ch] [ebp-ECh]
  int v16; // [esp-38h] [ebp-E8h]
  signed int v17; // [esp-34h] [ebp-E4h]
  _bstr_t *v18; // [esp-30h] [ebp-E0h]
  int v19; // [esp-2Ch] [ebp-DCh]
  int v20; // [esp-28h] [ebp-D8h]
  signed int v21; // [esp-24h] [ebp-D4h]
  int v22; // [esp-20h] [ebp-D0h]
  int v23; // [esp-1Ch] [ebp-CCh]
  int v24; // [esp-18h] [ebp-C8h]
  int v25; // [esp-14h] [ebp-C4h]
  int v26; // [esp-10h] [ebp-C0h]
  LPVOID v27; // [esp-Ch] [ebp-BCh]
  void *v28; // [esp-8h] [ebp-B8h]
  void *v29; // [esp-4h] [ebp-B4h]
  __int128 v30; // [esp+Ch] [ebp-A4h]
  __int128 v31; // [esp+1Ch] [ebp-94h]
  __int128 v32; // [esp+2Ch] [ebp-84h]
  VARIANTARG v33; // [esp+3Ch] [ebp-74h]
  VARIANTARG v34; // [esp+4Ch] [ebp-64h]
  VARIANTARG pvarg; // [esp+5Ch] [ebp-54h]
  VARIANTARG v36; // [esp+6Ch] [ebp-44h]
  void *v37; // [esp+7Ch] [ebp-34h]
  void *v38; // [esp+80h] [ebp-30h]
  void *v39; // [esp+84h] [ebp-2Ch]
  void *v40; // [esp+88h] [ebp-28h]
  void *v41; // [esp+8Ch] [ebp-24h]
  void *ppv1; // [esp+90h] [ebp-20h]
  void *v43; // [esp+94h] [ebp-1Ch]
  LPVOID ppv; // [esp+98h] [ebp-18h]
  _bstr_t v45; // [esp+9Ch] [ebp-14h]
  WCHAR *ppv3; // [esp+A0h] [ebp-10h]
  int v47; // [esp+ACh] [ebp-4h]

  ppv1 = -1;
  v45.m_Data = _wcsdup(&gszNullString);
  v47 = 0;
  v43 = _wcsdup(&gszNullString);
  v40 = _wcsdup(&gszNullString);
  v41 = _wcsdup(&gszNullString);
  v39 = _wcsdup(&gszNullString);
  v38 = _wcsdup(&gszNullString);
  v1 = &gszNullString;
  v2 = &gszNullString;
  if ( off_105AA2C )
    v2 = off_105AA2C;
  v37 = _wcsdup(v2);
  if ( off_105AA2C )
    v1 = off_105AA2C;
  ppv3 = _wcsdup(v1);
  v21 = -1;
  v20 = 0;
  v19 = 0;
  LOBYTE(v47) = 7;
  v18 = &v45;
  v17 = 1;
  v16 = 0;
  v15 = &v43;
  v14 = &v40;
  ppv1 = sub_F73FF0(a1, 2, ppv1, 0, &ppv3, &v37, &v38);
  free(ppv3);
  free(v37);
  free(v38);
  free(v39);
  free(v41);
  free(v40);
  free(v43);
  v47 = -1;
  free(v45.m_Data);
  CoInitializeEx(0, 0);
  ppv = 0;
  if ( CoCreateInstance(&stru_10478CC, 0, 1u, &riid, &ppv) >= 0 )
  {
    VariantInit(&pvarg);
    v3 = _mm_loadu_si128(&pvarg);
    v47 = 8;
    _mm_storeu_si128(&v32, v3);
    VariantInit(&v34);
    _mm_storeu_si128(&v31, _mm_loadu_si128(&v34));
    VariantInit(&v33);
    _mm_storeu_si128(&v30, _mm_loadu_si128(&v33));
    VariantInit(&v36);
    v4 = _mm_loadu_si128(&v32);
    v5 = ppv;
    LOBYTE(v47) = 11;
    v6 = *ppv;
    _mm_storeu_si128(&v26, v4);
    _mm_storeu_si128(&v22, _mm_loadu_si128(&v31));
    _mm_storeu_si128(&v18, _mm_loadu_si128(&v30));
    _mm_storeu_si128(&v14, _mm_loadu_si128(&v36));
    v7 = (*(v6 + 40))(v5, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29);
    VariantClear(&v36);
    VariantClear(&v33);
    VariantClear(&v34);
    v47 = -1;
    VariantClear(&pvarg);
    if ( v7 >= 0 )
    {
      if ( Wow64EnableWow64FsRedirection )
      {
        Wow64EnableWow64FsRedirection(0);
        TlsSetValue(gdwTlsIndex, 0x100);
      }
      ppv3 = 0;
      v8 = *_bstr_t::_bstr_t(&v45, L"\\");
      v47 = 12;
      if ( v8 )
        v9 = *v8;
      else
        v9 = 0;
      v29 = &ppv3;
      v28 = v9;
      v27 = ppv;
      v10 = (*(*ppv + 28))(ppv, v9, &ppv3);
      v47 = -1;
      v11 = v10;
      _bstr_t::_Free(&v45);
      if ( v11 >= 0 )
      {
        v29 = ppv3;
        v28 = v12;
        _bstr_t::_bstr_t(&v28, &gszNullString);
        sub_F8F260(a1, &ppv1, off_105AA2C, v28, v29);
        v13 = *ppv3;
        v29 = ppv3;
        (*(v13 + 8))(ppv3);
      }
      if ( Wow64EnableWow64FsRedirection )
      {
        Wow64EnableWow64FsRedirection(1u);
        TlsSetValue(gdwTlsIndex, 0x200);
      }
    }
    v29 = ppv;
    (*(*ppv + 8))(ppv);
  }
  CoUninitialize();
}

//----- (00F911B0) --------------------------------------------------------
wchar_t *__cdecl sub_F911B0(wchar_t *a1, int a2, wchar_t *a3)
{
  wchar_t **v3; // edi
  wchar_t *v4; // eax
  wchar_t *v5; // eax
  wchar_t *v6; // esi
  wchar_t *v7; // esi
  wchar_t *v8; // esi

  v3 = operator new(0x10u);
  if ( v3 )
  {
    v4 = malloc(2u);
    *v3 = v4;
    *v4 = 0;
    v5 = malloc(2u);
    v3[2] = v5;
    *v5 = 0;
  }
  else
  {
    v3 = 0;
  }
  v6 = *v3;
  *v3 = _wcsdup(a1);
  free(v6);
  v7 = v3[2];
  v3[2] = _wcsdup(a3);
  free(v7);
  if ( a2 )
    v3[1] = 1;
  else
    v3[1] = 0;
  v8 = v3[1];
  v3[3] = dword_1064C78;
  dword_1064C78 = v3;
  free(a1);
  free(a3);
  return v8;
}
// 1064C78: using guessed type int dword_1064C78;

//----- (00F91290) --------------------------------------------------------
int __cdecl sub_F91290(wchar_t *a1, int a2)
{
  int v2; // esi
  int result; // eax
  void *v4; // ebx
  int v5; // esi

  v2 = dword_1064C78;
  if ( dword_1064C78 )
  {
    while ( _wcsicmp(a1, *v2) )
    {
      v2 = *(v2 + 12);
      if ( !v2 )
        goto LABEL_4;
    }
    v4 = *a2;
    *a2 = _wcsdup(*(v2 + 8));
    free(v4);
    LeaveCriticalSection(&CriticalSection);
    v5 = *(v2 + 4);
    free(a1);
    result = v5;
  }
  else
  {
LABEL_4:
    free(a1);
    result = 2;
  }
  return result;
}
// 1064C78: using guessed type int dword_1064C78;

//----- (00F91310) --------------------------------------------------------
CSystemProcessInfoMapNode *__thiscall sub_F91310(CSystemProcessInfoMap *this, int *a2)
{
  CSystemProcessInfoMapNode *result; // eax
  CSystemProcessInfoMapNode *v3; // esi
  CSystemProcessInfoMapPair *v4; // edi
  int v5; // eax

  result = std::_Tree_comp_alloc<std::_Tmap_traits<unsigned long,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *>>,0>>::_Buynode0(this);
  v3 = result;
  v4 = &result->_Keyvalue;
  *&result->baseclass._Color = 0;
  if ( result != -16 )
  {
    v5 = *a2;
    v4->_Key = *a2;
    if ( v5 )
      InterlockedIncrement((v5 + 8));
    v4->_Value = a2[1];
    result = v3;
  }
  return result;
}

//----- (00F91350) --------------------------------------------------------
_DWORD *__thiscall sub_F91350(_DWORD *this)
{
  _DWORD *result; // eax

  this[2] = 0;
  result = this;
  this[3] = 0;
  this[4] = 0;
  this[5] = 0;
  this[8] = 0;
  this[9] = 0;
  this[10] = 0;
  return result;
}

//----- (00F91450) --------------------------------------------------------
void *__thiscall std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *>>>,std::_Iterator_base0>::operator--(void *this)
{
  void *v1; // edx
  _DWORD *v2; // eax
  int i; // ecx
  int v5; // eax
  int v6; // ecx

  v1 = this;
  v2 = *this;
  if ( *(*this + 13) )
  {
    *this = v2[2];
    return this;
  }
  i = *v2;
  if ( *(*v2 + 13) )
  {
    for ( i = v2[1]; !*(i + 13); i = *(i + 4) )
    {
      if ( *v1 != *i )
        break;
      *v1 = i;
    }
    if ( *(*v1 + 13) )
      return v1;
    goto LABEL_11;
  }
  v5 = *(i + 8);
  if ( *(v5 + 13) )
  {
LABEL_11:
    *v1 = i;
    return v1;
  }
  do
  {
    v6 = v5;
    v5 = *(v5 + 8);
  }
  while ( !*(v5 + 13) );
  *v1 = v6;
  return v1;
}

//----- (00F914B0) --------------------------------------------------------
// operator==(const _bstr_t::Data_t& r,const _bstr_t::Data_t& l)const
bool __stdcall sub_F914B0(Data_t_bstr_t *a1, Data_t_bstr_t *a2)
{
  const wchar_t *v2; // ecx
  const wchar_t *v3; // eax
  int v4; // eax
  LONG (__stdcall *v5)(volatile LONG *); // ecx
  bool v6; // bl

  if ( a2 )
    v2 = a2->m_wstr;
  else
    v2 = 0;
  if ( a1 )
    v3 = a1->m_wstr;
  else
    v3 = 0;
  v4 = _wcsicmp(v3, v2);
  v5 = InterlockedDecrement;
  v6 = v4 > 0;
  if ( a1 )
  {
    if ( !InterlockedDecrement(&a1->m_RefCount) && a1 )
    {
      if ( a1->m_wstr )
      {
        SysFreeString(a1->m_wstr);
        a1->m_wstr = 0;
      }
      if ( a1->m_str )
      {
        j_j__free(a1->m_str);
        a1->m_str = 0;
      }
      j__free(a1);
    }
    v5 = InterlockedDecrement;
  }
  if ( a2 && !v5(&a2->m_RefCount) && a2 )
  {
    if ( a2->m_wstr )
    {
      SysFreeString(a2->m_wstr);
      a2->m_wstr = 0;
    }
    if ( a2->m_str )
    {
      j_j__free(a2->m_str);
      a2->m_str = 0;
    }
    j__free(a2);
  }
  return v6;
}

//----- (00F91590) --------------------------------------------------------
void __cdecl sub_F91590(char a1, int a2, OLECHAR *a3, OLECHAR *a4, OLECHAR *psz, int a6)
{
  _DWORD *v6; // edi
  _DWORD *v7; // esi
  int v8; // eax
  _DWORD *v9; // esi
  _DWORD *v10; // eax
  _bstr_t v11; // [esp+10h] [ebp-24h]
  _DWORD *v12; // [esp+14h] [ebp-20h]
  char v13; // [esp+18h] [ebp-1Ch]
  _bstr_t v14; // [esp+1Ch] [ebp-18h]
  _DWORD *v15; // [esp+20h] [ebp-14h]
  char v16; // [esp+27h] [ebp-Dh]
  int v17; // [esp+30h] [ebp-4h]

  if ( !byte_1064CCC )
    return;
  EnterCriticalSection(&stru_1064C98);
  v6 = 0;
  v15 = 0;
  _bstr_t::_bstr_t(&v14, psz);
  v7 = *sub_1002F90(&gMap5, &v12, &v14);
  _bstr_t::_Free(&v14);
  v16 = 1;
  if ( a6 == 1 || v7 == gMap5 || (v6 = v7[5], v15 = v6, v8 = v6[1], v8 == 6) || v8 == 5 )
  {
    if ( a6 != 2 )
    {
      if ( v6 )
      {
        *v6 = CreateEventW(0, 1, 0, 0);
      }
      else
      {
        v10 = operator new(0x2Cu);
        if ( v10 )
          v6 = sub_F91350(v10);
        else
          v6 = 0;
        v15 = v6;
        if ( a1 )
          *v6 = CreateEventW(0, 1, 0, 0);
        else
          *v6 = 0;
        _bstr_t::operator=((v6 + 5), psz);
        _bstr_t::operator=((v6 + 2), a3);
        _bstr_t::operator=((v6 + 3), a4);
        _bstr_t::_bstr_t(&v11, psz);
        v12 = v6;
        v17 = 0;
        sub_1001650(&gMap5, &v13, 0, &v11, byte_1064CCD);
        v17 = -1;
        _bstr_t::_Free(&v11);
      }
      v9 = a2;
      *a2 = v6;
      v6[1] = 3 - (a6 != 1);
      if ( a6 == 1 )
      {
        sub_F99380(&gList1, &v15);
        SetEvent(hEvent);
      }
      else
      {
        sub_F917F0(&gList2, &v15);
        SetEvent(dword_1064CB8);
      }
      goto LABEL_8;
    }
  }
  else
  {
    v16 = 0;
  }
  v9 = a2;
LABEL_8:
  LeaveCriticalSection(&stru_1064C98);
  if ( v16 )
  {
    if ( a1 )
    {
      WaitForSingleObject(*v6, 0xFFFFFFFF);
      CloseHandle(*v6);
    }
  }
  *v9 = v6;
}
// 1064CCC: using guessed type char byte_1064CCC;
// 1064CCD: using guessed type char byte_1064CCD;

//----- (00F91780) --------------------------------------------------------
CSystemProcessInfoMapNode *std::_Tree_comp_alloc<std::_Tmap_traits<unsigned long,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *>>,0>>::_Buyheadnode()
{
  CSystemProcessInfoMapNode *result; // eax

  result = operator new(0x18u);
  JUMPOUT(result, 0, std::_Xbad_alloc);
  result->baseclass._Left = result;
  if ( result != -4 )
    result->baseclass._Parent = result;
  if ( result != -8 )
    result->baseclass._Right = result;
  *&result->baseclass._Color = 257;
  return result;
}

//----- (00F917B0) --------------------------------------------------------
CSystemProcessInfoMapNode *__thiscall std::_Tree_comp_alloc<std::_Tmap_traits<unsigned long,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *>>,0>>::_Buynode0(CSystemProcessInfoMap *this)
{
  CSystemProcessInfoMapNode **this_1; // esi
  CSystemProcessInfoMapNode *v2; // edx

  this_1 = this;
  v2 = operator new(0x18u);
  if ( !v2 )
    std::_Xbad_alloc();
  v2->baseclass._Left = *this_1;
  if ( v2 != -4 )
    v2->baseclass._Parent = *this_1;
  if ( v2 != -8 )
    v2->baseclass._Right = *this_1;
  return v2;
}

//----- (00F917F0) --------------------------------------------------------
_DWORD *__thiscall sub_F917F0(int **this, int a2)
{
  int **v2; // esi
  int v3; // edi
  _DWORD *v4; // edx
  int *v5; // eax
  _DWORD *result; // eax

  v2 = this;
  v3 = **this;
  v4 = std::_List_buy<tagEventItem *,std::allocator<tagEventItem *>>::_Buynode<tagEventItem * const &>(
         **this,
         *(v3 + 4),
         a2);
  v5 = v2[1];
  if ( (357913940 - v5) < 1 )
    std::_Xlength_error("list<T> too long");
  v2[1] = (v5 + 1);
  *(v3 + 4) = v4;
  result = v4[1];
  *result = v4;
  return result;
}

//----- (00F91840) --------------------------------------------------------
void *__cdecl sub_F91840(int a1)
{
  void *v1; // eax

  v1 = sub_F91860(a1, 0xFFFFFFFF, 1);
  return sub_F91860(a1, v1, 0);
}

//----- (00F91860) --------------------------------------------------------
void *__cdecl sub_F91860(int a1, void *a2, char a3)
{
  BOOL v3; // esi
  __int16 *v4; // edi
  __int16 v5; // ax
  __int16 *v6; // ecx
  __int16 v7; // ax
  FILE *v8; // eax
  FILE *v9; // edi
  int v10; // eax
  wchar_t *v11; // ebx
  wchar_t *i; // esi
  int v13; // eax
  int v14; // edx
  char *v15; // ecx
  int v16; // edi
  const wchar_t *v17; // ST60_4
  void *v18; // esi
  int v19; // edi
  int v20; // ST54_4
  int v21; // edi
  const wchar_t **v22; // eax
  void *v23; // esi
  int v24; // esi
  char v25; // bl
  int v27; // [esp+10h] [ebp-C9Ch]
  void *v28; // [esp+14h] [ebp-C98h]
  int v29; // [esp+18h] [ebp-C94h]
  void *v30; // [esp+1Ch] [ebp-C90h]
  unsigned int v31; // [esp+20h] [ebp-C8Ch]
  void *v32; // [esp+24h] [ebp-C88h]
  void *v33; // [esp+28h] [ebp-C84h]
  FILE *v34; // [esp+2Ch] [ebp-C80h]
  void *v35; // [esp+30h] [ebp-C7Ch]
  WCHAR *v36; // [esp+34h] [ebp-C78h]
  void *v37; // [esp+38h] [ebp-C74h]
  int v38; // [esp+3Ch] [ebp-C70h]
  void *v39; // [esp+40h] [ebp-C6Ch]
  void *v40; // [esp+44h] [ebp-C68h]
  void *v41; // [esp+48h] [ebp-C64h]
  void *v42; // [esp+4Ch] [ebp-C60h]
  int a2a; // [esp+50h] [ebp-C5Ch]
  int v44; // [esp+54h] [ebp-C58h]
  BOOL v45; // [esp+5Ch] [ebp-C50h]
  void *v46; // [esp+60h] [ebp-C4Ch]
  void *v47; // [esp+64h] [ebp-C48h]
  void *v48; // [esp+68h] [ebp-C44h]
  void *v49; // [esp+6Ch] [ebp-C40h]
  void *v50; // [esp+70h] [ebp-C3Ch]
  void *v51; // [esp+74h] [ebp-C38h]
  void *v52; // [esp+78h] [ebp-C34h]
  WCHAR *v53; // [esp+7Ch] [ebp-C30h]
  void *v54; // [esp+80h] [ebp-C2Ch]
  wchar_t *ppv3; // [esp+84h] [ebp-C28h]
  void *v56; // [esp+88h] [ebp-C24h]
  wchar_t v57; // [esp+8Ch] [ebp-C20h]
  char v58; // [esp+94h] [ebp-C18h]
  wchar_t v59; // [esp+96h] [ebp-C16h]
  __int16 v60; // [esp+88Ah] [ebp-422h]
  WCHAR Buffer; // [esp+88Ch] [ebp-420h]
  int v62; // [esp+CA8h] [ebp-4h]

  v29 = a1;
  v46 = malloc(2u);
  *v46 = 0;
  v62 = 0;
  v41 = malloc(2u);
  *v41 = 0;
  v56 = malloc(2u);
  *v56 = 0;
  v47 = malloc(2u);
  *v47 = 0;
  v3 = 0;
  v45 = 0;
  v40 = malloc(2u);
  *v40 = 0;
  LOBYTE(v62) = 4;
  GetWindowsDirectoryW(&Buffer, 0x208u);
  if ( a3 )
  {
    v6 = &v60;
    do
    {
      v7 = v6[1];
      ++v6;
    }
    while ( v7 );
    *v6 = *L"\\win.ini";
    *(v6 + 1) = *L"in.ini";
    *(v6 + 2) = *L".ini";
    *(v6 + 3) = *L"ni";
    v6[8] = aWinIni[8];
  }
  else
  {
    v4 = &v60;
    do
    {
      v5 = v4[1];
      ++v4;
    }
    while ( v5 );
    qmemcpy(v4, L"\\AutorunsDisabled.ini", 0x2Cu);
    v3 = 0;
  }
  if ( a2 == -1 )
  {
    v49 = _wcsdup(&gszNullString);
    v48 = _wcsdup(&gszNullString);
    v50 = _wcsdup(&gszNullString);
    v53 = _wcsdup(&gszNullString);
    v52 = _wcsdup(&gszNullString);
    v51 = _wcsdup(&gszNullString);
    v54 = _wcsdup(&Buffer);
    ppv3 = _wcsdup(&Buffer);
    LOBYTE(v62) = 12;
    a2 = sub_F73FF0(a1, 2, 0xFFFFFFFF, 0, &ppv3, &v54, &v51);
    free(ppv3);
    free(v54);
    free(v51);
    free(v52);
    free(v53);
    free(v50);
    free(v48);
    LOBYTE(v62) = 4;
    free(v49);
  }
  v8 = _wfopen(&Buffer, L"rt");
  v9 = v8;
  v34 = v8;
  if ( v8 )
  {
    if ( fgetws(&v57, 1024, v8) )
    {
      do
      {
        if ( v57 == 91 )
        {
          v10 = _wcsnicmp(&v57, L"[windows]", 9u);
          v3 = v10 == 0;
          v45 = v10 == 0;
        }
        else if ( v3 )
        {
          if ( !_wcsnicmp(&v57, L"load=", 5u) )
          {
            v11 = &v59;
LABEL_19:
            ppv3 = v11;
            for ( i = wcschr(v11, 0); i > v11; *i = 0 )
            {
              v13 = *(i - 1);
              --i;
              if ( !isspace(v13) )
                break;
            }
            v42 = 0;
            a2a = 0;
            v44 = 0;
            LOBYTE(v62) = 13;
            sub_F76DD0(v11, 44, &v42, 0);
            v14 = a2a;
            v15 = v42;
            v31 = 0;
            if ( (a2a - v42) >> 4 )
            {
              v16 = 0;
              v38 = 0;
              do
              {
                v17 = *&v15[v16];
                v18 = v47;
                v19 = &v15[v16];
                v47 = _wcsdup(v17);
                free(v18);
                v20 = v19;
                v21 = v29;
                v22 = sub_F74EE0(&v28, v29, v20, 0);
                v23 = v56;
                v56 = _wcsdup(*v22);
                free(v23);
                free(v28);
                if ( *v56 )
                {
                  v24 = sub_F74ED0();
                  v50 = _wcsdup(&Buffer);
                  v48 = _wcsdup(&Buffer);
                  v49 = _wcsdup(v11);
                  LOBYTE(v62) = 16;
                  v25 = sub_F73D40(v21, &v49, &v48, &v50, &v56, &v46, &v40, &v27);
                  free(v49);
                  free(v48);
                  LOBYTE(v62) = 13;
                  free(v50);
                  if ( v25 )
                  {
                    if ( a2 == -1 )
                    {
                      v37 = _wcsdup(&gszNullString);
                      v30 = _wcsdup(&gszNullString);
                      v32 = _wcsdup(&gszNullString);
                      v39 = _wcsdup(&gszNullString);
                      v54 = _wcsdup(&gszNullString);
                      v51 = _wcsdup(&gszNullString);
                      v52 = _wcsdup(&Buffer);
                      v53 = _wcsdup(&Buffer);
                      LOBYTE(v62) = 24;
                      a2 = sub_F73FF0(v21, 2, 0xFFFFFFFF, 0, &v53, &v52, &v51);
                      free(v53);
                      free(v52);
                      free(v51);
                      free(v54);
                      free(v39);
                      free(v32);
                      free(v30);
                      free(v37);
                    }
                    v35 = _wcsdup(&gszNullString);
                    v33 = _wcsdup(&Buffer);
                    v11 = ppv3;
                    v36 = _wcsdup(ppv3);
                    LOBYTE(v62) = 27;
                    sub_F73FF0(v21, v24, a2, 4, &v36, &v33, &v56);
                    free(v36);
                    free(v33);
                    LOBYTE(v62) = 13;
                    free(v35);
                  }
                  else
                  {
                    v11 = ppv3;
                  }
                }
                v14 = a2a;
                v15 = v42;
                v16 = v38 + 16;
                ++v31;
                v38 += 16;
              }
              while ( v31 < (a2a - v42) >> 4 );
              v9 = v34;
            }
            LOBYTE(v62) = 4;
            if ( v15 )
            {
              sub_F72BF0(v15, v14);
              j__free(v42);
              v42 = 0;
              a2a = 0;
              v44 = 0;
            }
            v3 = v45;
            continue;
          }
          if ( !_wcsnicmp(&v57, L"run=", 4u) )
          {
            v11 = &v58;
            goto LABEL_19;
          }
        }
      }
      while ( fgetws(&v57, 1024, v9) );
    }
    fclose(v9);
  }
  free(v40);
  free(v47);
  free(v56);
  free(v41);
  free(v46);
  return a2;
}
// 1032C50: using guessed type wchar_t aAutorunsdisabl_1[22];
// 1032C7C: using guessed type wchar_t aWinIni[9];

//----- (00F92060) --------------------------------------------------------
void __cdecl sub_F92060(int a1, void *a2, void *a3)
{
  _WORD *v3; // ST50_4
  WCHAR *v4; // esi
  void *v5; // edi
  const wchar_t **v6; // eax
  wchar_t *v7; // ST54_4

  v3 = malloc(2u);
  *v3 = 0;
  v4 = a3;
  v5 = sub_F92110(a1, a2, *a3, 0xFFFFFFFF);
  v6 = PE_CopyString(&a3, v4, L"\\AutorunsDisabled");
  v7 = _wcsdup(*v6);
  free(v3);
  free(a3);
  sub_F92110(a1, a2, v7, v5);
  free(v7);
}

//----- (00F92110) --------------------------------------------------------
void *__cdecl sub_F92110(int a1, void *a2, wchar_t *psz, void *a4)
{
  DWORD v4; // ebx
  const wchar_t *v5; // eax
  const wchar_t *v6; // eax
  unsigned __int16 **v7; // esi
  unsigned __int16 **v8; // eax
  unsigned int v9; // eax
  tagKeyName *v10; // esi
  unsigned int v11; // eax
  void *v12; // esi
  const wchar_t **v13; // eax
  void *v14; // esi
  const wchar_t *v15; // ecx
  const wchar_t *v16; // eax
  unsigned __int16 **v17; // esi
  unsigned __int16 **v18; // eax
  char v19; // bl
  const wchar_t *v20; // eax
  const wchar_t *v21; // eax
  HKEY v22; // ebx
  unsigned __int16 **v23; // esi
  unsigned __int16 **v24; // eax
  const wchar_t *v25; // eax
  unsigned __int16 **v26; // eax
  int v28; // [esp+10h] [ebp-A0h]
  int v29; // [esp+14h] [ebp-9Ch]
  int v30; // [esp+18h] [ebp-98h]
  int v31; // [esp+1Ch] [ebp-94h]
  WCHAR v32[2]; // [esp+20h] [ebp-90h]
  WCHAR v33[2]; // [esp+24h] [ebp-8Ch]
  WCHAR v34[2]; // [esp+28h] [ebp-88h]
  int a2a; // [esp+2Ch] [ebp-84h]
  void *v36; // [esp+30h] [ebp-80h]
  int v37; // [esp+34h] [ebp-7Ch]
  WCHAR v38[2]; // [esp+38h] [ebp-78h]
  WCHAR v39[2]; // [esp+3Ch] [ebp-74h]
  DWORD v40; // [esp+40h] [ebp-70h]
  void *v41; // [esp+44h] [ebp-6Ch]
  HKEY hKey; // [esp+48h] [ebp-68h]
  void *v43; // [esp+4Ch] [ebp-64h]
  void *v44; // [esp+50h] [ebp-60h]
  void *v45; // [esp+54h] [ebp-5Ch]
  void *v46; // [esp+58h] [ebp-58h]
  void *v47; // [esp+5Ch] [ebp-54h]
  void *a1a; // [esp+60h] [ebp-50h]
  wchar_t *v49; // [esp+64h] [ebp-4Ch]
  void *v50; // [esp+68h] [ebp-48h]
  HKEY hRootKey; // [esp+6Ch] [ebp-44h]
  WCHAR szArg[2]; // [esp+70h] [ebp-40h]
  LPCWSTR v53; // [esp+74h] [ebp-3Ch]
  LPCWSTR v54; // [esp+78h] [ebp-38h]
  LPCWSTR v55; // [esp+7Ch] [ebp-34h]
  LPCWSTR v56; // [esp+80h] [ebp-30h]
  LPCWSTR v57; // [esp+84h] [ebp-2Ch]
  LPCWSTR szArg3; // [esp+88h] [ebp-28h]
  LPCWSTR v59; // [esp+8Ch] [ebp-24h]
  WCHAR *pszText; // [esp+90h] [ebp-20h]
  LPCWSTR szArg4; // [esp+94h] [ebp-1Ch]
  LPCWSTR v62; // [esp+98h] [ebp-18h]
  void *v63; // [esp+9Ch] [ebp-14h]
  LPCWSTR lpszKeyName; // [esp+A0h] [ebp-10h]
  int v65; // [esp+ACh] [ebp-4h]

  v4 = 0;
  v40 = 0;
  v49 = malloc(2u);
  *v49 = 0;
  v65 = 0;
  v63 = malloc(2u);
  *v63 = 0;
  v50 = malloc(2u);
  *v50 = 0;
  v47 = malloc(2u);
  *v47 = 0;
  v45 = malloc(2u);
  *v45 = 0;
  v46 = malloc(2u);
  *v46 = 0;
  LOBYTE(v65) = 5;
  if ( a4 == -1 )
  {
    v56 = _wcsdup(&gszNullString);
    v62 = _wcsdup(&gszNullString);
    v53 = _wcsdup(&gszNullString);
    v55 = _wcsdup(&gszNullString);
    v57 = _wcsdup(&gszNullString);
    v59 = _wcsdup(&gszNullString);
    szArg4 = _wcsdup(&gszNullString);
    v5 = &gszNullString;
    if ( psz )
      v5 = psz;
    pszText = _wcsdup(v5);
    v54 = _wcsdup(&gszNullString);
    v6 = &gszNullString;
    if ( psz )
      v6 = psz;
    szArg3 = _wcsdup(v6);
    LOBYTE(v65) = 15;
    v7 = sub_F77BE0(&a1a, a2, &pszText, &szArg4);
    LOBYTE(v65) = 16;
    v8 = sub_F77BE0(szArg, a2, &szArg3, &v54);
    LOBYTE(v65) = 17;
    a4 = sub_F73FF0(a1, 0, 0xFFFFFFFF, 0, v8, v7, &v59);
    free(*szArg);
    free(a1a);
    free(szArg3);
    free(v54);
    free(pszText);
    free(szArg4);
    free(v59);
    free(v57);
    free(v55);
    free(v53);
    free(v62);
    LOBYTE(v65) = 5;
    free(v56);
  }
  v9 = TlsGetValue(gdwTlsIndex);
  if ( !PE_OpenKey(ghLocalMachineKey, psz, 0, v9 | 0x20019, &hRootKey) )
  {
    lpszKeyName = malloc(2u);
    *lpszKeyName = 0;
    LOBYTE(v65) = 18;
    if ( !PE_LoadKey(hRootKey, 0, &lpszKeyName) )
    {
      do
      {
        v10 = lpszKeyName;
        v11 = TlsGetValue(gdwTlsIndex);
        if ( !PE_OpenKey(hRootKey, v10, 0, v11 | 0x20019, &hKey) )
        {
          if ( !sub_F81520(hKey, L"Dllname", 0, 0, &v49) )
          {
            v28 = malloc(2u);
            *v28 = 0;
            v29 = 0;
            v30 = 0;
            v31 = 0;
            LOBYTE(v65) = 19;
            sub_F77040(v49, &v28);
            v12 = v50;
            v50 = _wcsdup(v49);
            free(v12);
            v13 = sub_F74EE0(&v36, a1, &v28, 0);
            v14 = v63;
            v63 = _wcsdup(*v13);
            free(v14);
            free(v36);
            a2a = sub_F74ED0();
            v15 = &gszNullString;
            if ( psz )
              v15 = psz;
            v53 = _wcsdup(v15);
            v62 = _wcsdup(&gszNullString);
            v16 = &gszNullString;
            if ( psz )
              v16 = psz;
            v56 = _wcsdup(v16);
            LOBYTE(v65) = 22;
            v17 = sub_F77BE0(v39, a2, &v53, &lpszKeyName);
            LOBYTE(v65) = 23;
            v18 = sub_F77BE0(v34, a2, &v56, &v62);
            LOBYTE(v65) = 24;
            v19 = sub_F73D40(a1, &lpszKeyName, v18, v17, &v63, &v47, &v46, &v37);
            free(*v34);
            free(*v39);
            free(v56);
            free(v62);
            free(v53);
            if ( v19 )
            {
              if ( a4 == -1 )
              {
                v43 = _wcsdup(&gszNullString);
                v41 = _wcsdup(&gszNullString);
                v44 = _wcsdup(&gszNullString);
                szArg3 = _wcsdup(&gszNullString);
                v54 = _wcsdup(&gszNullString);
                pszText = _wcsdup(&gszNullString);
                szArg4 = _wcsdup(&gszNullString);
                v20 = &gszNullString;
                if ( psz )
                  v20 = psz;
                v59 = _wcsdup(v20);
                v57 = _wcsdup(&gszNullString);
                v21 = &gszNullString;
                if ( psz )
                  v21 = psz;
                v55 = _wcsdup(v21);
                v22 = a2;
                LOBYTE(v65) = 34;
                v23 = sub_F77BE0(v38, a2, &v59, &szArg4);
                LOBYTE(v65) = 35;
                v24 = sub_F77BE0(v32, a2, &v55, &v57);
                LOBYTE(v65) = 36;
                a4 = sub_F73FF0(a1, 0, 0xFFFFFFFF, 0, v24, v23, &pszText);
                free(*v32);
                free(*v38);
                free(v55);
                free(v57);
                free(v59);
                free(szArg4);
                free(pszText);
                free(v54);
                free(szArg3);
                free(v44);
                free(v41);
                free(v43);
              }
              else
              {
                v22 = a2;
              }
              *szArg = _wcsdup(&gszNullString);
              v25 = &gszNullString;
              if ( psz )
                v25 = psz;
              a1a = _wcsdup(v25);
              LOBYTE(v65) = 38;
              v26 = sub_F77BE0(v33, v22, &a1a, &lpszKeyName);
              LOBYTE(v65) = 39;
              sub_F73FF0(a1, a2a, a4, 3, &lpszKeyName, v26, &v63);
              free(*v33);
              free(a1a);
              free(*szArg);
            }
            LOBYTE(v65) = 18;
            sub_F721F0(&v28);
            v4 = v40;
          }
          RegCloseKey(hKey);
        }
        v40 = ++v4;
      }
      while ( !PE_LoadKey(hRootKey, v4, &lpszKeyName) );
    }
    RegCloseKey(hRootKey);
    free(lpszKeyName);
  }
  free(v46);
  free(v45);
  free(v47);
  free(v50);
  free(v63);
  free(v49);
  return a4;
}

//----- (00F927D0) --------------------------------------------------------
void __cdecl sub_F927D0(int a1, OLECHAR *psz)
{
  _WORD *v2; // edi
  _WORD *v3; // ebx
  _WORD *v4; // esi
  unsigned __int16 **v5; // eax
  int v6; // edi
  DWORD v7; // ebx
  const WCHAR *v8; // esi
  unsigned int v9; // eax
  const wchar_t **v10; // eax
  void *v11; // esi
  wchar_t *v12; // esi
  wchar_t *v13; // eax
  const wchar_t **v14; // eax
  wchar_t *v15; // esi
  HINSTANCE v16; // eax
  unsigned __int16 **v17; // esi
  unsigned __int16 **v18; // eax
  unsigned __int16 **v19; // esi
  unsigned __int16 **v20; // eax
  unsigned __int16 **v21; // eax
  int v22; // [esp+10h] [ebp-2D4h]
  int v23; // [esp+14h] [ebp-2D0h]
  int v24; // [esp+18h] [ebp-2CCh]
  int v25; // [esp+1Ch] [ebp-2C8h]
  void *v26; // [esp+20h] [ebp-2C4h]
  HMODULE hLibModule; // [esp+24h] [ebp-2C0h]
  WCHAR *ppstr; // [esp+28h] [ebp-2BCh]
  WCHAR v29[2]; // [esp+2Ch] [ebp-2B8h]
  WCHAR v30[2]; // [esp+30h] [ebp-2B4h]
  _WORD *v31; // [esp+34h] [ebp-2B0h]
  int v32; // [esp+38h] [ebp-2ACh]
  _WORD *v33; // [esp+3Ch] [ebp-2A8h]
  WCHAR v34[2]; // [esp+40h] [ebp-2A4h]
  _WORD *v35; // [esp+44h] [ebp-2A0h]
  WCHAR v36[2]; // [esp+48h] [ebp-29Ch]
  WCHAR v37[2]; // [esp+4Ch] [ebp-298h]
  int a2; // [esp+50h] [ebp-294h]
  BYTE Data[4]; // [esp+54h] [ebp-290h]
  void *v40; // [esp+58h] [ebp-28Ch]
  void *v41; // [esp+5Ch] [ebp-288h]
  void *ppv1; // [esp+60h] [ebp-284h]
  HKEY hKey; // [esp+64h] [ebp-280h]
  void *v44; // [esp+68h] [ebp-27Ch]
  void *v45; // [esp+6Ch] [ebp-278h]
  void *v46; // [esp+70h] [ebp-274h]
  WCHAR szArg[2]; // [esp+74h] [ebp-270h]
  void *a1a; // [esp+78h] [ebp-26Ch]
  DWORD cbData; // [esp+7Ch] [ebp-268h]
  wchar_t *v50; // [esp+80h] [ebp-264h]
  void *v51; // [esp+84h] [ebp-260h]
  UINT uID; // [esp+88h] [ebp-25Ch]
  HKEY phkResult; // [esp+8Ch] [ebp-258h]
  LPCWSTR v54; // [esp+90h] [ebp-254h]
  void *v55; // [esp+94h] [ebp-250h]
  LPCWSTR v56; // [esp+98h] [ebp-24Ch]
  void *v57; // [esp+9Ch] [ebp-248h]
  void *v58; // [esp+A0h] [ebp-244h]
  LPCWSTR v59; // [esp+A4h] [ebp-240h]
  LPCWSTR szArg4; // [esp+A8h] [ebp-23Ch]
  char v61; // [esp+AFh] [ebp-235h]
  void *v62; // [esp+B0h] [ebp-234h]
  LPCWSTR lpSubKey; // [esp+B4h] [ebp-230h]
  LPCWSTR v64; // [esp+B8h] [ebp-22Ch]
  BYTE v65; // [esp+BCh] [ebp-228h]
  WCHAR Buffer; // [esp+CCh] [ebp-218h]
  int v67; // [esp+2E0h] [ebp-4h]

  uID = a1;
  v67 = 0;
  v62 = malloc(2u);
  *v62 = 0;
  v2 = malloc(2u);
  v35 = v2;
  *v2 = 0;
  v3 = malloc(2u);
  v33 = v3;
  *v3 = 0;
  v57 = malloc(2u);
  *v57 = 0;
  v44 = malloc(2u);
  *v44 = 0;
  v46 = malloc(2u);
  *v46 = 0;
  v4 = malloc(2u);
  v31 = v4;
  *v4 = 0;
  v50 = malloc(2u);
  *v50 = 0;
  v54 = _wcsdup(&gszNullString);
  v56 = _wcsdup(&gszNullString);
  v59 = _wcsdup(&gszNullString);
  v58 = _wcsdup(&gszNullString);
  v51 = _wcsdup(&gszNullString);
  v55 = _wcsdup(&gszNullString);
  szArg4 = _wcsdup(&gszNullString);
  v64 = _wcsdup(&gszNullString);
  LOBYTE(v67) = 16;
  v45 = sub_F77BE0(&a1a, HKEY_LOCAL_MACHINE, &psz, &szArg4);
  LOBYTE(v67) = 17;
  v5 = sub_F77BE0(szArg, HKEY_LOCAL_MACHINE, &psz, &v64);
  LOBYTE(v67) = 18;
  ppv1 = sub_F73FF0(uID, 0, 0xFFFFFFFF, 0, v5, v45, &v55);
  free(*szArg);
  free(a1a);
  free(v64);
  free(szArg4);
  free(v55);
  free(v51);
  free(v58);
  free(v59);
  free(v56);
  LOBYTE(v67) = 8;
  free(v54);
  if ( PE_OpenKey(ghLocalMachineKey, psz, 0, 0x20019u, &hKey) )
  {
    free(v50);
    free(v4);
    free(v46);
    free(v44);
    free(v57);
    free(v3);
    free(v2);
    free(v62);
  }
  else
  {
    lpSubKey = malloc(2u);
    *lpSubKey = 0;
    LOBYTE(v67) = 19;
    if ( !PE_LoadKey(hKey, 0, &lpSubKey) )
    {
      v6 = uID;
      v7 = 0;
      do
      {
        v8 = lpSubKey;
        v9 = TlsGetValue(gdwTlsIndex);
        if ( !RegOpenKeyExW(hKey, v8, 0, v9 | 0x20019, &phkResult) )
        {
          cbData = 0;
          if ( !sub_F81520(phkResult, L"LibraryPath", 0, 0, &v50) )
          {
            v45 = _wcsdup(v50);
            v22 = malloc(2u);
            *v22 = 0;
            v23 = 0;
            v24 = 0;
            v25 = 0;
            LOBYTE(v67) = 21;
            sub_F77040(v50, &v22);
            v10 = sub_F74EE0(&v26, v6, &v22, 0);
            v11 = v62;
            v62 = _wcsdup(*v10);
            free(v11);
            free(v26);
            a2 = sub_F74ED0();
            v64 = _wcsdup(lpSubKey);
            LOBYTE(v67) = 22;
            if ( !sub_F81520(phkResult, L"DisplayString", 0, 0, &v64) && *v64 == 64 )
            {
              v12 = _wcsdup(v64);
              v41 = v12;
              LOBYTE(v67) = 23;
              uID = 0;
              if ( wcschr(v12, 0x2Cu) )
              {
                v13 = wcschr(v12, 0x2Cu);
                *v13 = 0;
                uID = abs(_wtoi(v13 + 1));
              }
              v14 = RequerySystemEnvironmentString(&ppstr, v12 + 1);
              v15 = _wcsdup(*v14);
              free(v41);
              free(ppstr);
              v16 = LoadLibraryExW(v15, 0, 2u);
              hLibModule = v16;
              if ( v16 )
              {
                if ( LoadStringW(v16, uID, &Buffer, 260) )
                {
                  v41 = v64;
                  v64 = _wcsdup(&Buffer);
                  free(v41);
                }
                FreeLibrary(hLibModule);
              }
              free(v15);
            }
            cbData = 4;
            RegQueryValueExW(phkResult, L"Enabled", 0, 0, Data, &cbData);
            cbData = 16;
            if ( !RegQueryValueExW(phkResult, L"ProviderId", 0, 0, &v65, &cbData) )
            {
              v54 = _wcsdup(&gszNullString);
              LOBYTE(v67) = 24;
              v17 = sub_F77BE0(v30, HKEY_LOCAL_MACHINE, &psz, &lpSubKey);
              LOBYTE(v67) = 25;
              v18 = sub_F77BE0(v36, HKEY_LOCAL_MACHINE, &psz, &v54);
              LOBYTE(v67) = 26;
              v61 = sub_F73D40(v6, &lpSubKey, v18, v17, &v62, &v57, &v46, &v32);
              free(*v36);
              free(*v30);
              free(v54);
              if ( v61 )
              {
                if ( ppv1 == -1 )
                {
                  a1a = _wcsdup(&gszNullString);
                  v40 = _wcsdup(&gszNullString);
                  szArg4 = _wcsdup(&gszNullString);
                  v55 = _wcsdup(&gszNullString);
                  v51 = _wcsdup(&gszNullString);
                  v58 = _wcsdup(&gszNullString);
                  v59 = _wcsdup(&gszNullString);
                  v56 = _wcsdup(&gszNullString);
                  LOBYTE(v67) = 34;
                  v19 = sub_F77BE0(v29, HKEY_LOCAL_MACHINE, &psz, &v59);
                  LOBYTE(v67) = 35;
                  v20 = sub_F77BE0(v34, HKEY_LOCAL_MACHINE, &psz, &v56);
                  LOBYTE(v67) = 36;
                  ppv1 = sub_F73FF0(v6, 0, 0xFFFFFFFF, 0, v20, v19, &v58);
                  free(*v34);
                  free(*v29);
                  free(v56);
                  free(v59);
                  free(v58);
                  free(v51);
                  free(v55);
                  free(szArg4);
                  free(v40);
                  free(a1a);
                }
                *szArg = _wcsdup(&gszNullString);
                LOBYTE(v67) = 37;
                v21 = sub_F77BE0(v37, HKEY_LOCAL_MACHINE, &psz, &lpSubKey);
                LOBYTE(v67) = 38;
                sub_F73FF0(v6, a2, ppv1, 16, &v64, v21, &v62);
                free(*v37);
                free(*szArg);
              }
            }
            free(v64);
            sub_F721F0(&v22);
            LOBYTE(v67) = 19;
            free(v45);
          }
          RegCloseKey(phkResult);
        }
        ++v7;
      }
      while ( !PE_LoadKey(hKey, v7, &lpSubKey) );
      v2 = v35;
      v3 = v33;
      v4 = v31;
    }
    RegCloseKey(hKey);
    free(lpSubKey);
    free(v50);
    free(v4);
    free(v46);
    free(v44);
    free(v57);
    free(v3);
    free(v2);
    free(v62);
  }
  free(psz);
}

//----- (00F93190) --------------------------------------------------------
void __cdecl sub_F93190(int a1, OLECHAR *psz)
{
  _WORD *v2; // edi
  _WORD *v3; // ebx
  _WORD *v4; // esi
  unsigned __int16 **v5; // eax
  Data_t_bstr_t *v6; // edi
  DWORD v7; // ebx
  tagKeyName *v8; // esi
  unsigned int v9; // eax
  Data_t_bstr_t *v10; // eax
  const WCHAR **v11; // eax
  Data_t_bstr_t *v12; // esi
  const wchar_t **v13; // eax
  void *v14; // esi
  wchar_t *v15; // esi
  wchar_t *v16; // eax
  const wchar_t **v17; // eax
  wchar_t *v18; // esi
  HINSTANCE v19; // eax
  unsigned __int16 **v20; // esi
  unsigned __int16 **v21; // eax
  unsigned __int16 **v22; // esi
  unsigned __int16 **v23; // eax
  unsigned __int16 **v24; // eax
  int v25; // [esp+10h] [ebp-63Ch]
  int v26; // [esp+14h] [ebp-638h]
  int v27; // [esp+18h] [ebp-634h]
  int v28; // [esp+1Ch] [ebp-630h]
  DWORD cbData; // [esp+20h] [ebp-62Ch]
  WCHAR *ppstr; // [esp+24h] [ebp-628h]
  void *v31; // [esp+28h] [ebp-624h]
  WCHAR v32[2]; // [esp+2Ch] [ebp-620h]
  WCHAR v33[2]; // [esp+30h] [ebp-61Ch]
  _WORD *v34; // [esp+34h] [ebp-618h]
  int v35; // [esp+38h] [ebp-614h]
  _WORD *v36; // [esp+3Ch] [ebp-610h]
  WCHAR v37[2]; // [esp+40h] [ebp-60Ch]
  _WORD *v38; // [esp+44h] [ebp-608h]
  WCHAR v39[2]; // [esp+48h] [ebp-604h]
  WCHAR v40[2]; // [esp+4Ch] [ebp-600h]
  int a2; // [esp+50h] [ebp-5FCh]
  HMODULE hLibModule; // [esp+54h] [ebp-5F8h]
  void *v43; // [esp+58h] [ebp-5F4h]
  void *v44; // [esp+5Ch] [ebp-5F0h]
  void *v45; // [esp+60h] [ebp-5ECh]
  void *ppv1; // [esp+64h] [ebp-5E8h]
  void *v47; // [esp+68h] [ebp-5E4h]
  HKEY hKey; // [esp+6Ch] [ebp-5E0h]
  void *v49; // [esp+70h] [ebp-5DCh]
  HKEY hRootKey; // [esp+74h] [ebp-5D8h]
  void *v51; // [esp+78h] [ebp-5D4h]
  void *v52; // [esp+7Ch] [ebp-5D0h]
  WCHAR szArg[2]; // [esp+80h] [ebp-5CCh]
  void *a1a; // [esp+84h] [ebp-5C8h]
  void *v55; // [esp+88h] [ebp-5C4h]
  LPCWSTR v56; // [esp+8Ch] [ebp-5C0h]
  void *v57; // [esp+90h] [ebp-5BCh]
  LPCWSTR v58; // [esp+94h] [ebp-5B8h]
  Data_t_bstr_t *v59; // [esp+98h] [ebp-5B4h]
  LPCWSTR v60; // [esp+9Ch] [ebp-5B0h]
  UINT uID; // [esp+A0h] [ebp-5ACh]
  void *v62; // [esp+A4h] [ebp-5A8h]
  LPCWSTR szArg4; // [esp+A8h] [ebp-5A4h]
  void *v64; // [esp+ACh] [ebp-5A0h]
  char v65; // [esp+B3h] [ebp-599h]
  LPCWSTR lpszKeyName; // [esp+B4h] [ebp-598h]
  wchar_t *ppv3; // [esp+B8h] [ebp-594h]
  BYTE Data; // [esp+BCh] [ebp-590h]
  WCHAR Buffer; // [esp+434h] [ebp-218h]
  int v70; // [esp+648h] [ebp-4h]

  v59 = a1;
  v70 = 0;
  v64 = malloc(2u);
  *v64 = 0;
  v2 = malloc(2u);
  v38 = v2;
  *v2 = 0;
  v3 = malloc(2u);
  v36 = v3;
  *v3 = 0;
  v55 = malloc(2u);
  *v55 = 0;
  v52 = malloc(2u);
  *v52 = 0;
  v49 = malloc(2u);
  *v49 = 0;
  v4 = malloc(2u);
  v34 = v4;
  *v4 = 0;
  v44 = malloc(2u);
  *v44 = 0;
  uID = _wcsdup(&gszNullString);
  v58 = _wcsdup(&gszNullString);
  v56 = _wcsdup(&gszNullString);
  v60 = _wcsdup(&gszNullString);
  v62 = _wcsdup(&gszNullString);
  v57 = _wcsdup(&gszNullString);
  ppv3 = _wcsdup(&gszNullString);
  szArg4 = _wcsdup(&gszNullString);
  LOBYTE(v70) = 16;
  v51 = sub_F77BE0(&a1a, HKEY_LOCAL_MACHINE, &psz, &ppv3);
  LOBYTE(v70) = 17;
  v5 = sub_F77BE0(szArg, HKEY_LOCAL_MACHINE, &psz, &szArg4);
  LOBYTE(v70) = 18;
  ppv1 = sub_F73FF0(v59, 0, 0xFFFFFFFF, 0, v5, v51, &v57);
  free(*szArg);
  free(a1a);
  free(szArg4);
  free(ppv3);
  free(v57);
  free(v62);
  free(v60);
  free(v56);
  free(v58);
  LOBYTE(v70) = 8;
  free(uID);
  if ( PE_OpenKey(ghLocalMachineKey, psz, 0, 0x20019u, &hRootKey) )
  {
    free(v44);
    free(v4);
    free(v49);
    free(v52);
    free(v55);
    free(v3);
    free(v2);
    free(v64);
  }
  else
  {
    lpszKeyName = malloc(2u);
    *lpszKeyName = 0;
    LOBYTE(v70) = 19;
    if ( !PE_LoadKey(hRootKey, 0, &lpszKeyName) )
    {
      v6 = v59;
      v7 = 0;
      do
      {
        v8 = lpszKeyName;
        v9 = TlsGetValue(gdwTlsIndex);
        if ( !PE_OpenKey(hRootKey, v8, 0, v9 | 0x20019, &hKey) )
        {
          cbData = 888;
          if ( !RegQueryValueExW(hKey, L"PackedCatalogItem", 0, 0, &Data, &cbData) )
          {
            v10 = _bstr_t::_bstr_t(&v59, &Data)->m_Data;
            if ( !v10 || (v11 = v10->m_wstr) == 0 )
              v11 = &gszNullString;
            szArg4 = _wcsdup(v11);
            v12 = v59;
            if ( v59 )
            {
              if ( !InterlockedDecrement(&v59->m_RefCount) && v12 )
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
              v59 = 0;
            }
            v25 = malloc(2u);
            *v25 = 0;
            v26 = 0;
            v27 = 0;
            v28 = 0;
            LOBYTE(v70) = 21;
            sub_F76CC0(szArg4, &v25);
            v13 = sub_F74EE0(&v31, v6, &v25, 0);
            v14 = v64;
            v64 = _wcsdup(*v13);
            free(v14);
            free(v31);
            a2 = sub_F74ED0();
            ppv3 = _wcsdup(lpszKeyName);
            LOBYTE(v70) = 22;
            if ( !sub_F81520(hKey, L"ProtocolName", 0, 0, &ppv3) && *ppv3 == 64 )
            {
              v15 = _wcsdup(ppv3);
              v47 = v15;
              LOBYTE(v70) = 23;
              uID = 0;
              if ( wcschr(v15, 0x2Cu) )
              {
                v16 = wcschr(v15, 0x2Cu);
                *v16 = 0;
                uID = abs(_wtoi(v16 + 1));
              }
              v17 = RequerySystemEnvironmentString(&ppstr, v15 + 1);
              v18 = _wcsdup(*v17);
              free(v47);
              free(ppstr);
              v19 = LoadLibraryExW(v18, 0, 2u);
              hLibModule = v19;
              if ( v19 )
              {
                if ( LoadStringW(v19, uID, &Buffer, 260) )
                {
                  v47 = ppv3;
                  ppv3 = _wcsdup(&Buffer);
                  free(v47);
                }
                FreeLibrary(hLibModule);
              }
              free(v18);
            }
            v58 = _wcsdup(&gszNullString);
            LOBYTE(v70) = 24;
            v20 = sub_F77BE0(v33, HKEY_LOCAL_MACHINE, &psz, &lpszKeyName);
            LOBYTE(v70) = 25;
            v21 = sub_F77BE0(v39, HKEY_LOCAL_MACHINE, &psz, &v58);
            LOBYTE(v70) = 26;
            v65 = sub_F73D40(v6, &lpszKeyName, v21, v20, &v64, &v55, &v49, &v35);
            free(*v39);
            free(*v33);
            free(v58);
            if ( v65 )
            {
              if ( ppv1 == -1 )
              {
                *szArg = _wcsdup(&gszNullString);
                a1a = _wcsdup(&gszNullString);
                v45 = _wcsdup(&gszNullString);
                v43 = _wcsdup(&gszNullString);
                v57 = _wcsdup(&gszNullString);
                v62 = _wcsdup(&gszNullString);
                v60 = _wcsdup(&gszNullString);
                v56 = _wcsdup(&gszNullString);
                LOBYTE(v70) = 34;
                v22 = sub_F77BE0(v32, HKEY_LOCAL_MACHINE, &psz, &v60);
                LOBYTE(v70) = 35;
                v23 = sub_F77BE0(v37, HKEY_LOCAL_MACHINE, &psz, &v56);
                LOBYTE(v70) = 36;
                ppv1 = sub_F73FF0(v6, 0, 0xFFFFFFFF, 0, v23, v22, &v62);
                free(*v37);
                free(*v32);
                free(v56);
                free(v60);
                free(v62);
                free(v57);
                free(v43);
                free(v45);
                free(a1a);
                free(*szArg);
              }
              v51 = _wcsdup(&gszNullString);
              LOBYTE(v70) = 37;
              v24 = sub_F77BE0(v40, HKEY_LOCAL_MACHINE, &psz, &lpszKeyName);
              LOBYTE(v70) = 38;
              sub_F73FF0(v6, a2, ppv1, 11, &ppv3, v24, &v64);
              free(*v40);
              free(v51);
            }
            free(ppv3);
            sub_F721F0(&v25);
            LOBYTE(v70) = 19;
            free(szArg4);
          }
          RegCloseKey(hKey);
        }
        ++v7;
      }
      while ( !PE_LoadKey(hRootKey, v7, &lpszKeyName) );
      v2 = v38;
      v3 = v36;
      v4 = v34;
    }
    RegCloseKey(hRootKey);
    free(lpszKeyName);
    free(v44);
    free(v4);
    free(v49);
    free(v52);
    free(v55);
    free(v3);
    free(v2);
    free(v64);
  }
  free(psz);
}

//----- (00F93B60) --------------------------------------------------------
_DWORD *__thiscall sub_F93B60(_DWORD *this, int a2, _DWORD **a3, int a4)
{
  _DWORD *result; // eax

  result = sub_F96B70(this);
  *(result + 6) = 0;
  if ( result != -16 )
  {
    result[4] = **a3;
    result[5] = 0;
    result[6] = 0;
    result[7] = 0;
  }
  return result;
}

//----- (00F93BA0) --------------------------------------------------------
CSystemProcessInfoMapNode *__thiscall sub_F93BA0(CSystemProcessInfoMap *this, int a2, const wchar_t ***a3, int a4)
{
  CSystemProcessInfoMapNode *result; // eax
  CSystemProcessInfoMapNode *v5; // esi
  _DWORD *v6; // edi

  result = std::_Tree_comp_alloc<std::_Tmap_traits<unsigned long,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *>>,0>>::_Buynode0(this);
  v5 = result;
  v6 = &result->_Keyvalue._Key;
  *&result->baseclass._Color = 0;
  if ( result != -16 )
  {
    *v6 = _wcsdup(**a3);
    v6[1] = 0;
    result = v5;
  }
  return result;
}

//----- (00F93BE0) --------------------------------------------------------
int __thiscall sub_F93BE0(_DWORD *this, int a2, char a3, int a4, int a5, void *a6)
{
  _DWORD *v6; // edi
  unsigned int v7; // eax
  _DWORD *v8; // eax
  int *v9; // ecx
  int *v10; // esi
  int *v11; // edx
  _DWORD *v12; // edx
  void **v13; // ecx
  _DWORD *v14; // edx
  _DWORD *v15; // esi
  int v16; // ecx
  _DWORD *v17; // ecx
  int v18; // edx
  int v19; // ecx
  _DWORD *v20; // ecx
  _DWORD *v21; // ecx
  int result; // eax

  v6 = this;
  v7 = this[1];
  if ( v7 >= 0xAAAAAA9 )
  {
    free(*(a6 + 4));
    j__free(a6);
    std::_Xlength_error("map/set<T> too long");
  }
  this[1] = v7 + 1;
  *(a6 + 1) = a4;
  if ( a4 == *this )
  {
    *(*this + 4) = a6;
    **this = a6;
    *(*this + 8) = a6;
  }
  else if ( a3 )
  {
    *a4 = a6;
    if ( a4 == **this )
      **this = a6;
  }
  else
  {
    *(a4 + 8) = a6;
    if ( a4 == *(*this + 8) )
      *(*this + 8) = a6;
  }
  v8 = a6;
  if ( !*(*(a6 + 1) + 12) )
  {
    do
    {
      v9 = v8[1];
      v10 = v9[1];
      v11 = *v10;
      if ( v9 == *v10 )
      {
        v11 = v10[2];
        if ( *(v11 + 12) )
        {
          if ( v8 == v9[2] )
          {
            v8 = v8[1];
            v12 = v9[2];
            v9[2] = *v12;
            if ( !*(*v12 + 13) )
              *(*v12 + 4) = v9;
            v12[1] = v9[1];
            if ( v9 == *(*v6 + 4) )
            {
              *(*v6 + 4) = v12;
            }
            else
            {
              v13 = v9[1];
              if ( v8 == *v13 )
                *v13 = v12;
              else
                v13[2] = v12;
            }
            *v12 = v8;
            v8[1] = v12;
          }
          *(v8[1] + 12) = 1;
          *(*(v8[1] + 4) + 12) = 0;
          v14 = *(v8[1] + 4);
          v15 = *v14;
          *v14 = *(*v14 + 8);
          v16 = v15[2];
          if ( !*(v16 + 13) )
            *(v16 + 4) = v14;
          v15[1] = v14[1];
          if ( v14 == *(*v6 + 4) )
          {
            *(*v6 + 4) = v15;
            v15[2] = v14;
          }
          else
          {
            v17 = v14[1];
            if ( v14 == v17[2] )
              v17[2] = v15;
            else
              *v17 = v15;
            v15[2] = v14;
          }
LABEL_48:
          v14[1] = v15;
          continue;
        }
      }
      else if ( *(v11 + 12) )
      {
        if ( v8 == *v9 )
        {
          v8 = v8[1];
          v18 = *v9;
          *v9 = *(*v9 + 8);
          v19 = *(v18 + 8);
          if ( !*(v19 + 13) )
            *(v19 + 4) = v8;
          *(v18 + 4) = v8[1];
          if ( v8 == *(*v6 + 4) )
          {
            *(*v6 + 4) = v18;
          }
          else
          {
            v20 = v8[1];
            if ( v8 == v20[2] )
              v20[2] = v18;
            else
              *v20 = v18;
          }
          *(v18 + 8) = v8;
          v8[1] = v18;
        }
        *(v8[1] + 12) = 1;
        *(*(v8[1] + 4) + 12) = 0;
        v14 = *(v8[1] + 4);
        v15 = v14[2];
        v14[2] = *v15;
        if ( !*(*v15 + 13) )
          *(*v15 + 4) = v14;
        v15[1] = v14[1];
        if ( v14 == *(*v6 + 4) )
        {
          *(*v6 + 4) = v15;
        }
        else
        {
          v21 = v14[1];
          if ( v14 == *v21 )
            *v21 = v15;
          else
            v21[2] = v15;
        }
        *v15 = v14;
        goto LABEL_48;
      }
      *(v9 + 12) = 1;
      *(v11 + 12) = 1;
      *(*(v8[1] + 4) + 12) = 0;
      v8 = *(v8[1] + 4);
    }
    while ( !*(v8[1] + 12) );
  }
  *(*(*v6 + 4) + 12) = 1;
  result = a2;
  *a2 = a6;
  return result;
}

//----- (00F93E00) --------------------------------------------------------
int __thiscall sub_F93E00(_DWORD *this, int a2, char a3, int a4, int a5, void *a6)
{
  _DWORD *v6; // edi
  unsigned int v7; // eax
  _DWORD *v8; // eax
  int *v9; // ecx
  int *v10; // esi
  int *v11; // edx
  _DWORD *v12; // edx
  void **v13; // ecx
  _DWORD *v14; // edx
  _DWORD *v15; // esi
  int v16; // ecx
  _DWORD *v17; // ecx
  int v18; // edx
  int v19; // ecx
  _DWORD *v20; // ecx
  _DWORD *v21; // ecx
  int result; // eax

  v6 = this;
  v7 = this[1];
  if ( v7 >= 0x7FFFFFE )
  {
    if ( *(a6 + 5) )
    {
      j__free(*(a6 + 5));
      *(a6 + 5) = 0;
      *(a6 + 6) = 0;
      *(a6 + 7) = 0;
    }
    j__free(a6);
    std::_Xlength_error("map/set<T> too long");
  }
  this[1] = v7 + 1;
  *(a6 + 1) = a4;
  if ( a4 == *this )
  {
    *(*this + 4) = a6;
    **this = a6;
    *(*this + 8) = a6;
  }
  else if ( a3 )
  {
    *a4 = a6;
    if ( a4 == **this )
      **this = a6;
  }
  else
  {
    *(a4 + 8) = a6;
    if ( a4 == *(*this + 8) )
      *(*this + 8) = a6;
  }
  v8 = a6;
  if ( !*(*(a6 + 1) + 12) )
  {
    do
    {
      v9 = v8[1];
      v10 = v9[1];
      v11 = *v10;
      if ( v9 == *v10 )
      {
        v11 = v10[2];
        if ( *(v11 + 12) )
        {
          if ( v8 == v9[2] )
          {
            v8 = v8[1];
            v12 = v9[2];
            v9[2] = *v12;
            if ( !*(*v12 + 13) )
              *(*v12 + 4) = v9;
            v12[1] = v9[1];
            if ( v9 == *(*v6 + 4) )
            {
              *(*v6 + 4) = v12;
            }
            else
            {
              v13 = v9[1];
              if ( v8 == *v13 )
                *v13 = v12;
              else
                v13[2] = v12;
            }
            *v12 = v8;
            v8[1] = v12;
          }
          *(v8[1] + 12) = 1;
          *(*(v8[1] + 4) + 12) = 0;
          v14 = *(v8[1] + 4);
          v15 = *v14;
          *v14 = *(*v14 + 8);
          v16 = v15[2];
          if ( !*(v16 + 13) )
            *(v16 + 4) = v14;
          v15[1] = v14[1];
          if ( v14 == *(*v6 + 4) )
          {
            *(*v6 + 4) = v15;
            v15[2] = v14;
          }
          else
          {
            v17 = v14[1];
            if ( v14 == v17[2] )
              v17[2] = v15;
            else
              *v17 = v15;
            v15[2] = v14;
          }
LABEL_50:
          v14[1] = v15;
          continue;
        }
      }
      else if ( *(v11 + 12) )
      {
        if ( v8 == *v9 )
        {
          v8 = v8[1];
          v18 = *v9;
          *v9 = *(*v9 + 8);
          v19 = *(v18 + 8);
          if ( !*(v19 + 13) )
            *(v19 + 4) = v8;
          *(v18 + 4) = v8[1];
          if ( v8 == *(*v6 + 4) )
          {
            *(*v6 + 4) = v18;
          }
          else
          {
            v20 = v8[1];
            if ( v8 == v20[2] )
              v20[2] = v18;
            else
              *v20 = v18;
          }
          *(v18 + 8) = v8;
          v8[1] = v18;
        }
        *(v8[1] + 12) = 1;
        *(*(v8[1] + 4) + 12) = 0;
        v14 = *(v8[1] + 4);
        v15 = v14[2];
        v14[2] = *v15;
        if ( !*(*v15 + 13) )
          *(*v15 + 4) = v14;
        v15[1] = v14[1];
        if ( v14 == *(*v6 + 4) )
        {
          *(*v6 + 4) = v15;
        }
        else
        {
          v21 = v14[1];
          if ( v14 == *v21 )
            *v21 = v15;
          else
            v21[2] = v15;
        }
        *v15 = v14;
        goto LABEL_50;
      }
      *(v9 + 12) = 1;
      *(v11 + 12) = 1;
      *(*(v8[1] + 4) + 12) = 0;
      v8 = *(v8[1] + 4);
    }
    while ( !*(v8[1] + 12) );
  }
  *(*(*v6 + 4) + 12) = 1;
  result = a2;
  *a2 = a6;
  return result;
}

//----- (00F94040) --------------------------------------------------------
int __thiscall sub_F94040(_DWORD *this, int a2, int a3, int a4, void *a5)
{
  _DWORD *v5; // ebx
  bool v6; // zf
  int result; // eax
  std__Tree_node *v8; // edi
  int v9; // edx
  unsigned int v10; // ecx
  bool v11; // cf
  int v12; // ecx
  int v13; // [esp+0h] [ebp-30h]
  int v14; // [esp+10h] [ebp-20h]
  _DWORD *v15; // [esp+14h] [ebp-1Ch]
  std__Tree_node *v16; // [esp+18h] [ebp-18h]
  std__tree v17; // [esp+1Ch] [ebp-14h]
  int v18; // [esp+2Ch] [ebp-4h]

  v17._Mypair._Myval2._Mysize = &v13;
  v5 = this;
  v15 = this;
  v6 = this[1] == 0;
  v18 = 0;
  if ( v6 )
  {
    sub_F93BE0(this, a2, 1, *this, a4, a5);
    return a2;
  }
  v8 = *this;
  if ( a3 == **this )
  {
    if ( *a4 < *(a3 + 16) )
    {
      sub_F93BE0(this, a2, 1, a3, a4, a5);
      return a2;
    }
    goto LABEL_23;
  }
  if ( a3 == v8 )
  {
    v9 = v8->_Right;
    if ( *(v9 + 16) < *a4 )
    {
      sub_F93BE0(this, a2, 0, v9, a4, a5);
      return a2;
    }
    goto LABEL_23;
  }
  v10 = *(a3 + 16);
  v16 = *a4;
  v11 = v10 < v16;
  if ( v10 > v16 )
  {
    v17._Mypair._Myval2._Myhead = a3;
    std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *>>>,std::_Iterator_base0>::operator--(&v17);
    if ( v17._Mypair._Myval2._Myhead[1]._Left < v16 )
    {
      if ( v17._Mypair._Myval2._Myhead->_Right->_IsNil )
        sub_F93BE0(v5, a2, 0, v17._Mypair._Myval2._Myhead, a4, a5);
      else
        sub_F93BE0(v5, a2, 1, a3, a4, a5);
      return a2;
    }
    v11 = *(a3 + 16) < v16;
  }
  if ( !v11
    || (v17._Mypair._Myval2._Myhead = a3, sub_F94CE0(&v17), v17._Mypair._Myval2._Myhead != v8)
    && v16 >= v17._Mypair._Myval2._Myhead[1]._Left )
  {
LABEL_23:
    v18 = -1;
    v12 = *sub_F944A0(v5, &v14, 0, a4, a5);
    result = a2;
    *a2 = v12;
    return result;
  }
  if ( *(*(a3 + 8) + 13) )
    sub_F93BE0(v5, a2, 0, a3, a4, a5);
  else
    sub_F93BE0(v5, a2, 1, v17._Mypair._Myval2._Myhead, a4, a5);
  return a2;
}
// 10081AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);

//----- (00F94270) --------------------------------------------------------
int __thiscall sub_F94270(_DWORD *this, int a2, int a3, int a4, void *a5)
{
  _DWORD *v5; // ebx
  bool v6; // zf
  int result; // eax
  std__Tree_node *v8; // edi
  int v9; // edx
  unsigned int v10; // ecx
  bool v11; // cf
  int v12; // ecx
  int v13; // [esp+0h] [ebp-30h]
  int v14; // [esp+10h] [ebp-20h]
  _DWORD *v15; // [esp+14h] [ebp-1Ch]
  std__Tree_node *v16; // [esp+18h] [ebp-18h]
  std__tree v17; // [esp+1Ch] [ebp-14h]
  int v18; // [esp+2Ch] [ebp-4h]

  v17._Mypair._Myval2._Mysize = &v13;
  v5 = this;
  v15 = this;
  v6 = this[1] == 0;
  v18 = 0;
  if ( v6 )
  {
    sub_F93E00(this, a2, 1, *this, a4, a5);
    return a2;
  }
  v8 = *this;
  if ( a3 == **this )
  {
    if ( *a4 < *(a3 + 16) )
    {
      sub_F93E00(this, a2, 1, a3, a4, a5);
      return a2;
    }
    goto LABEL_23;
  }
  if ( a3 == v8 )
  {
    v9 = v8->_Right;
    if ( *(v9 + 16) < *a4 )
    {
      sub_F93E00(this, a2, 0, v9, a4, a5);
      return a2;
    }
    goto LABEL_23;
  }
  v10 = *(a3 + 16);
  v16 = *a4;
  v11 = v10 < v16;
  if ( v10 > v16 )
  {
    v17._Mypair._Myval2._Myhead = a3;
    std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *>>>,std::_Iterator_base0>::operator--(&v17);
    if ( v17._Mypair._Myval2._Myhead[1]._Left < v16 )
    {
      if ( v17._Mypair._Myval2._Myhead->_Right->_IsNil )
        sub_F93E00(v5, a2, 0, v17._Mypair._Myval2._Myhead, a4, a5);
      else
        sub_F93E00(v5, a2, 1, a3, a4, a5);
      return a2;
    }
    v11 = *(a3 + 16) < v16;
  }
  if ( !v11
    || (v17._Mypair._Myval2._Myhead = a3, sub_F94CE0(&v17), v17._Mypair._Myval2._Myhead != v8)
    && v16 >= v17._Mypair._Myval2._Myhead[1]._Left )
  {
LABEL_23:
    v18 = -1;
    v12 = *sub_F945C0(v5, &v14, 0, a4, a5);
    result = a2;
    *a2 = v12;
    return result;
  }
  if ( *(*(a3 + 8) + 13) )
    sub_F93E00(v5, a2, 0, a3, a4, a5);
  else
    sub_F93E00(v5, a2, 1, v17._Mypair._Myval2._Myhead, a4, a5);
  return a2;
}
// 10081AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);

//----- (00F944A0) --------------------------------------------------------
int __thiscall sub_F944A0(_DWORD *this, int a2, int a3, int a4, void *a5)
{
  int v5; // edx
  int v6; // edi
  _DWORD *v7; // ebx
  int v8; // eax
  bool v9; // dl
  unsigned int v10; // ecx
  int v11; // esi
  int *v12; // eax
  int v13; // ecx
  int result; // eax
  void *v15; // edi
  int v16; // [esp+0h] [ebp-28h]
  _DWORD *v17; // [esp+10h] [ebp-18h]
  int v18; // [esp+14h] [ebp-14h]
  int *v19; // [esp+18h] [ebp-10h]
  int v20; // [esp+24h] [ebp-4h]

  v19 = &v16;
  v17 = this;
  v5 = *this;
  v6 = *this;
  v7 = a4;
  v20 = 0;
  v8 = *(v5 + 4);
  v9 = 1;
  LOBYTE(v18) = 1;
  if ( !*(v8 + 13) )
  {
    v10 = *a4;
    do
    {
      v6 = v8;
      if ( a3 )
        v9 = *(v8 + 16) >= v10;
      else
        v9 = v10 < *(v8 + 16);
      LOBYTE(v18) = v9;
      if ( v9 )
        v8 = *v8;
      else
        v8 = *(v8 + 8);
    }
    while ( !*(v8 + 13) );
    this = v17;
  }
  v11 = v6;
  a3 = v6;
  if ( v9 )
  {
    if ( v6 == **this )
    {
      v12 = sub_F93BE0(this, &a3, 1, v6, a4, a5);
LABEL_14:
      v13 = *v12;
      result = a2;
      *a2 = v13;
      *(a2 + 4) = 1;
      return result;
    }
    std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *>>>,std::_Iterator_base0>::operator--(&a3);
    v11 = a3;
  }
  if ( *(v11 + 16) < *v7 )
  {
    v12 = sub_F93BE0(v17, &a3, v18, v6, v7, a5);
    goto LABEL_14;
  }
  v15 = a5;
  free(*(a5 + 4));
  j__free(v15);
  result = a2;
  *a2 = v11;
  *(a2 + 4) = 0;
  return result;
}
// 10081AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);

//----- (00F945C0) --------------------------------------------------------
int __thiscall sub_F945C0(_DWORD *this, int a2, int a3, int a4, void *a5)
{
  int v5; // edx
  int v6; // edi
  _DWORD *v7; // ebx
  int v8; // eax
  bool v9; // dl
  unsigned int v10; // ecx
  int v11; // esi
  int *v12; // eax
  int v13; // ecx
  int result; // eax
  _DWORD *v15; // edi
  int v16; // [esp+0h] [ebp-28h]
  _DWORD *v17; // [esp+10h] [ebp-18h]
  int v18; // [esp+14h] [ebp-14h]
  int *v19; // [esp+18h] [ebp-10h]
  int v20; // [esp+24h] [ebp-4h]

  v19 = &v16;
  v17 = this;
  v5 = *this;
  v6 = *this;
  v7 = a4;
  v20 = 0;
  v8 = *(v5 + 4);
  v9 = 1;
  LOBYTE(v18) = 1;
  if ( !*(v8 + 13) )
  {
    v10 = *a4;
    do
    {
      v6 = v8;
      if ( a3 )
        v9 = *(v8 + 16) >= v10;
      else
        v9 = v10 < *(v8 + 16);
      LOBYTE(v18) = v9;
      if ( v9 )
        v8 = *v8;
      else
        v8 = *(v8 + 8);
    }
    while ( !*(v8 + 13) );
    this = v17;
  }
  v11 = v6;
  a3 = v6;
  if ( v9 )
  {
    if ( v6 == **this )
    {
      v12 = sub_F93E00(this, &a3, 1, v6, a4, a5);
LABEL_14:
      v13 = *v12;
      result = a2;
      *a2 = v13;
      *(a2 + 4) = 1;
      return result;
    }
    std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *>>>,std::_Iterator_base0>::operator--(&a3);
    v11 = a3;
  }
  if ( *(v11 + 16) < *v7 )
  {
    v12 = sub_F93E00(v17, &a3, v18, v6, v7, a5);
    goto LABEL_14;
  }
  v15 = a5;
  if ( *(a5 + 5) )
  {
    j__free(*(a5 + 5));
    v15[5] = 0;
    v15[6] = 0;
    v15[7] = 0;
  }
  j__free(v15);
  result = a2;
  *a2 = v11;
  *(a2 + 4) = 0;
  return result;
}
// 10081AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);

//----- (00F94700) --------------------------------------------------------
void **__cdecl sub_F94700(const wchar_t **a1, const wchar_t **a2, void **a3)
{
  const wchar_t **v3; // edi
  void **v4; // ebx
  void *v5; // esi

  v3 = a1;
  if ( a1 == a2 )
    return a3;
  v4 = a3;
  do
  {
    v5 = *v4;
    *v4 = _wcsdup(*v3);
    free(v5);
    ++v3;
    ++v4;
  }
  while ( v3 != a2 );
  return v4;
}

//----- (00F94740) --------------------------------------------------------
void *__thiscall ActiveScriptEventConsumer::ActiveScriptEventConsumer(void *this)
{
  void *v1; // ebx
  _WORD *v2; // eax
  _WORD *v3; // eax
  void *v4; // esi
  void *v5; // esi
  void *v7; // [esp+14h] [ebp-10h]
  int v8; // [esp+20h] [ebp-4h]

  v1 = this;
  v7 = _wcsdup(L"ActiveScriptEventConsumer");
  v8 = 0;
  *v1 = &EventConsumerDescBase::`vftable';
  v2 = malloc(2u);
  *(v1 + 1) = v2;
  *v2 = 0;
  v3 = malloc(2u);
  *(v1 + 2) = v3;
  *v3 = 0;
  LOBYTE(v8) = 2;
  *sub_F94C50(&gMap6, &v7) = v1;
  free(v7);
  *v1 = &ActiveScriptEventConsumer::`vftable';
  v4 = *(v1 + 1);
  *(v1 + 1) = _wcsdup(L"The ActiveScriptEventConsumer class runs a predefined script in an arbitrary scripting ");
  free(v4);
  CopyStringToString(
    v1 + 1,
    L"language when an event is delivered to it. This class is one of the standard event consumers that WMI provides.",
    0x7FFFFFFFu,
    0);
  v5 = *(v1 + 2);
  *(v1 + 2) = _wcsdup(L"http://msdn.microsoft.com/en-us/library/aa384749(v=vs.85).aspx");
  free(v5);
  return v1;
}
// 1032E48: using guessed type void *EventConsumerDescBase::`vftable';
// 1033110: using guessed type void *ActiveScriptEventConsumer::`vftable';

//----- (00F94830) --------------------------------------------------------
void *__thiscall CommandLineEventConsumer::CommandLineEventConsumer(void *this)
{
  void *v1; // ebx
  _WORD *v2; // eax
  _WORD *v3; // eax
  void *v4; // esi
  void *v5; // esi
  void *v7; // [esp+14h] [ebp-10h]
  int v8; // [esp+20h] [ebp-4h]

  v1 = this;
  v7 = _wcsdup(L"CommandLineEventConsumer");
  v8 = 0;
  *v1 = &EventConsumerDescBase::`vftable';
  v2 = malloc(2u);
  *(v1 + 1) = v2;
  *v2 = 0;
  v3 = malloc(2u);
  *(v1 + 2) = v3;
  *v3 = 0;
  LOBYTE(v8) = 2;
  *sub_F94C50(&gMap6, &v7) = v1;
  free(v7);
  *v1 = &CommandLineEventConsumer::`vftable';
  v4 = *(v1 + 1);
  *(v1 + 1) = _wcsdup(L"The CommandLineEventConsumer class starts an arbitrary process in the local system ");
  free(v4);
  CopyStringToString(
    v1 + 1,
    L"when an event is delivered to it. This class is one of the standard event consumers that WMI provides.",
    0x7FFFFFFFu,
    0);
  v5 = *(v1 + 2);
  *(v1 + 2) = _wcsdup(L"http://msdn.microsoft.com/en-us/library/aa389231(v=vs.85).aspx");
  free(v5);
  return v1;
}
// 1032E48: using guessed type void *EventConsumerDescBase::`vftable';
// 1032E60: using guessed type void *CommandLineEventConsumer::`vftable';

//----- (00F94920) --------------------------------------------------------
_DWORD *__thiscall GetQueryEnumObject(IEnumWbemClassObject **ppEnumOut, IWbemServices *pWbemServices, const wchar_t *lpszQuery)
{
  IEnumWbemClassObject **v3; // edi
  OLECHAR ***v4; // esi
  OLECHAR ***v5; // eax
  OLECHAR **v6; // esi
  OLECHAR *v7; // esi
  OLECHAR **v8; // eax
  OLECHAR *v9; // edx
  HRESULT v10; // eax
  wchar_t *v11; // esi
  LONG (__stdcall *v12)(volatile LONG *); // edx
  Data_t_bstr_t *v13; // esi
  _DWORD *result; // eax
  _bstr_t v15; // [esp+10h] [ebp-10h]
  int v16; // [esp+1Ch] [ebp-4h]
  IWbemServices *pWbemServicesa; // [esp+28h] [ebp+8h]

  v3 = ppEnumOut;
  *ppEnumOut = 0;
  v16 = 0;
  v4 = _bstr_t::_bstr_t(&v15, lpszQuery);
  LOBYTE(v16) = 1;
  v5 = _bstr_t::_bstr_t(&lpszQuery, L"WQL");
  v6 = *v4;
  LOBYTE(v16) = 2;
  if ( v6 )
    v7 = *v6;
  else
    v7 = 0;
  v8 = *v5;
  if ( v8 )
    v9 = *v8;
  else
    v9 = 0;
  v10 = pWbemServices->lpVtbl->ExecQuery(pWbemServices, v9, v7, 0, 0, v3);
  v11 = lpszQuery;
  v12 = InterlockedDecrement;
  pWbemServicesa = v10;
  if ( lpszQuery )
  {
    if ( !InterlockedDecrement(lpszQuery + 2) && v11 )
    {
      if ( *v11 )
      {
        SysFreeString(*v11);
        *v11 = 0;
      }
      if ( *(v11 + 1) )
      {
        j_j__free(*(v11 + 1));
        *(v11 + 1) = 0;
      }
      j__free(v11);
    }
    v12 = InterlockedDecrement;
    lpszQuery = 0;
  }
  v13 = v15.m_Data;
  if ( v15.m_Data && !v12(&v15.m_Data->m_RefCount) && v13 )
  {
    if ( v13->m_wstr )
    {
      SysFreeString(v13->m_wstr);
      v13->m_wstr = 0;
    }
    if ( v13->m_str )
    {
      j_j__free(v13->m_str);
      v13->m_str = 0;
    }
    j__free(v13);
  }
  result = v3;
  if ( pWbemServicesa < 0 )
    *v3 = 0;
  return result;
}

//----- (00F94A70) --------------------------------------------------------
volatile LONG *__thiscall sub_F94A70(volatile LONG *this, volatile LONG a2)
{
  volatile LONG *v2; // esi

  v2 = this;
  *this = a2;
  *(this + 3) = 0;
  *(this + 4) = 0;
  *(this + 5) = 0;
  *(this + 6) = 0;
  *(this + 7) = 0;
  *(this + 8) = 0;
  *(this + 1) = 0;
  *(this + 2) = 0;
  InterlockedIncrement(this + 1);
  return v2;
}

//----- (00F94B00) --------------------------------------------------------
void __thiscall sub_F94B00(CSystemProcessInfoMap *this)
{
  CSystemProcessInfoMap *v1; // esi
  int v2; // [esp+4h] [ebp-4h]

  v1 = this;
  sub_F971F0(this, &v2, this->_Header->_Left, this->_Header);
  j__free(v1->_Header);
}

//----- (00F94B60) --------------------------------------------------------
void **__thiscall sub_F94B60(void **this, void **a2)
{
  void **v2; // esi

  v2 = this;
  if ( this != a2 )
  {
    if ( *this )
    {
      j__free(*this);
      *v2 = 0;
      v2[1] = 0;
      v2[2] = 0;
    }
    *v2 = *a2;
    v2[1] = a2[1];
    v2[2] = a2[2];
    *a2 = 0;
    a2[1] = 0;
    a2[2] = 0;
  }
  return v2;
}

//----- (00F94BC0) --------------------------------------------------------
_DWORD *__thiscall sub_F94BC0(int *this, _DWORD *a2)
{
  int *v2; // ebx
  int v3; // esi
  int v4; // eax
  _DWORD *v6; // eax
  _DWORD *v7; // [esp+Ch] [ebp-4h]

  v2 = this;
  v3 = *this;
  v4 = *(*this + 4);
  while ( !*(v4 + 13) )
  {
    if ( *(v4 + 16) >= *a2 )
    {
      v3 = v4;
      v4 = *v4;
    }
    else
    {
      v4 = *(v4 + 8);
    }
  }
  if ( v3 != *this && *a2 >= *(v3 + 16) )
    return (v3 + 20);
  v7 = a2;
  v6 = sub_F93B60(this, &dword_1064D34, &v7, &a2 + 3);
  sub_F94270(v2, &a2, v3, (v6 + 4), v6);
  return a2 + 5;
}
// 1064D34: using guessed type int dword_1064D34;

//----- (00F94C50) --------------------------------------------------------
std__Tree_node **__thiscall sub_F94C50(CSystemProcessInfoMap *this, _DWORD *a2)
{
  CSystemProcessInfoMap *v2; // ebx
  std__Tree_node *v3; // esi
  std__Tree_node *v4; // eax
  CSystemProcessInfoMapNode *v6; // eax
  _DWORD *v7; // [esp+Ch] [ebp-4h]

  v2 = this;
  v3 = this->_Header;
  v4 = this->_Header->_Parent;
  while ( !v4->_IsNil )
  {
    if ( v4[1]._Left >= *a2 )
    {
      v3 = v4;
      v4 = v4->_Left;
    }
    else
    {
      v4 = v4->_Right;
    }
  }
  if ( v3 != this->_Header && *a2 >= v3[1]._Left )
    return &v3[1]._Parent;
  v7 = a2;
  v6 = sub_F93BA0(this, &dword_1064D34, &v7, &a2 + 3);
  sub_F94040(v2, &a2, v3, &v6->_Keyvalue, v6);
  return (a2 + 5);
}
// 1064D34: using guessed type int dword_1064D34;

//----- (00F94CE0) --------------------------------------------------------
std__tree *__thiscall sub_F94CE0(std__tree *this)
{
  std__tree *v1; // edx
  std__Tree_node *v2; // eax
  std__Tree_node *v3; // ecx
  std__Tree_node *v4; // eax
  std__Tree_node *i; // eax

  v1 = this;
  v2 = this->_Mypair._Myval2._Myhead;
  if ( this->_Mypair._Myval2._Myhead->_IsNil )
    return v1;
  v3 = v2->_Right;
  if ( v3->_IsNil )
  {
    for ( i = v2->_Parent; !i->_IsNil; i = i->_Parent )
    {
      if ( v1->_Mypair._Myval2._Myhead != i->_Right )
        break;
      v1->_Mypair._Myval2._Myhead = i;
    }
    v1->_Mypair._Myval2._Myhead = i;
    return v1;
  }
  v4 = v3->_Left;
  if ( !v3->_Left->_IsNil )
  {
    do
    {
      v3 = v4;
      v4 = v4->_Left;
    }
    while ( !v4->_IsNil );
  }
  v1->_Mypair._Myval2._Myhead = v3;
  return v1;
}

//----- (00F94D30) --------------------------------------------------------
void *__thiscall std::error_category::`vector deleting destructor'(void *this, char a2)
{
  void *v2; // esi

  v2 = this;
  *this = &std::error_category::`vftable';
  if ( a2 & 1 )
    j__free(this);
  return v2;
}
// 1032D74: using guessed type void *std::error_category::`vftable';

//----- (00F94D60) --------------------------------------------------------
void sub_F94D60()
{
  tagStreamThreadInfo *v0; // esi
  HANDLE v1; // eax

  v0 = gpStreamThreadInfo;
  if ( gpStreamThreadInfo )
  {
    v1 = gpStreamThreadInfo->hEventLoadFailed;
    gpStreamThreadInfo->bRelease = 1;
    if ( v1 )
      SetEvent(v1);
    StreamThreadInfo_Release(v0);
    gpStreamThreadInfo = 0;
  }
}

//----- (00F94DA0) --------------------------------------------------------
HRESULT __cdecl LoadWbemServices(const wchar_t *lpszServerName, IWbemServices **ppv)
{
  tagStreamThreadInfo *v2; // esi
  volatile LONG *v3; // eax
  HRESULT result; // eax
  HRESULT v5; // edi
  HANDLE v6; // eax

  v2 = gpStreamThreadInfo;
  if ( gpStreamThreadInfo )
  {
    gpStreamThreadInfo->pszServer = lpszServerName;
  }
  else
  {
    v3 = operator new(0x24u);
    if ( v3 )
      v2 = sub_F94A70(v3, lpszServerName);
    else
      v2 = 0;
  }
  result = StreamThreadInfo_Load(v2, ppv);
  v5 = result;
  if ( result >= 0 )
  {
    gpStreamThreadInfo = v2;
  }
  else
  {
    v6 = v2->hEventLoadFailed;
    v2->bRelease = 1;
    if ( v6 )
      SetEvent(v6);
    StreamThreadInfo_Release(v2);
    result = v5;
    gpStreamThreadInfo = 0;
  }
  return result;
}

//----- (00F94E20) --------------------------------------------------------
HRESULT __thiscall StreamThreadInfo_Load(tagStreamThreadInfo *lpParameter, IWbemServices **ppWbemServices)
{
  DWORD v2; // ebx
  tagStreamThreadInfo *v3; // esi
  HANDLE v4; // eax
  HANDLE v5; // eax
  HRESULT result; // eax
  HANDLE v7; // eax
  HANDLE v8; // eax
  HANDLE v9; // eax
  DWORD v10; // eax
  DWORD v11; // eax
  HANDLE Handles; // [esp+Ch] [ebp-10h]
  HANDLE v13; // [esp+10h] [ebp-Ch]
  DWORD ThreadId; // [esp+14h] [ebp-8h]
  DWORD ExitCode; // [esp+18h] [ebp-4h]

  v2 = gdwTimeout;
  v3 = lpParameter;
  if ( bInited && gdwTimeout == 5000 )
    v2 = 20000;
  bInited = 0;
  v4 = lpParameter->hThread;
  if ( v4 )
  {
    if ( !GetExitCodeThread(v4, &ExitCode) || ExitCode != 259 || !SetEvent(v3->hEventLoadFailed) )
    {
      CloseHandle(v3->hThread);
      v3->hThread = 0;
    }
    if ( v3->hThread )
      goto LABEL_22;
    if ( v3->hEvent1 )
    {
      CloseHandle(v3->hEvent1);
      v3->hEvent1 = 0;
    }
    if ( v3->hEvent2 )
    {
      CloseHandle(v3->hEvent2);
      v3->hEvent2 = 0;
    }
    if ( v3->hEventLoadFailed )
    {
      CloseHandle(v3->hEventLoadFailed);
      v3->hEventLoadFailed = 0;
    }
  }
  if ( !v3->hThread )
  {
    v5 = CreateEventW(0, 0, 0, 0);
    v3->hEvent1 = v5;
    if ( !v5 )
      return -2147467259;
    v7 = CreateEventW(0, 0, 0, 0);
    v3->hEvent2 = v7;
    if ( !v7 )
      return -2147467259;
    v8 = CreateEventW(0, 0, 0, 0);
    v3->hEventLoadFailed = v8;
    if ( !v8 )
      return -2147467259;
    v9 = CreateThread(0, 0, StreamToWbemServicesThreadProc, v3, 0, &ThreadId);
    v3->hThread = v9;
    if ( !v9 )
      return -2147467259;
  }
LABEL_22:
  Handles = v3->hThread;
  v13 = v3->hEvent1;
  v10 = WaitForMultipleObjects(2u, &Handles, 0, 0xFFFFFFFF);
  if ( !v10 )
  {
    result = v3->hresult;
    if ( result >= 0 )
      result = -2147467259;
    return result;
  }
  if ( v10 != 1 )
    return -2147467259;
  v13 = v3->hEvent2;
  v11 = WaitForMultipleObjects(2u, &Handles, 0, v2);
  if ( v11 == 1 )
  {
    result = CoGetInterfaceAndReleaseStream(v3->pStream, &CLSID_IWbemServices, ppWbemServices);
    v3->hresult = result;
    if ( result >= 0 )
      v3->pStream = 0;
  }
  else if ( v11 == -1 )
  {
    result = GetLastError();
    if ( result > 0 )
      result = result | 0x80070000;
  }
  else
  {
    result = -2147024638;
  }
  return result;
}
// 105AA38: using guessed type char bInited;

//----- (00F94FE0) --------------------------------------------------------
void *__cdecl sub_F94FE0(int a1, void *a2)
{
  void *result; // eax
  void *v3; // esi
  void *v4; // [esp+8h] [ebp-24h]
  void *v5; // [esp+Ch] [ebp-20h]
  void *v6; // [esp+10h] [ebp-1Ch]
  void *v7; // [esp+14h] [ebp-18h]
  void *v8; // [esp+18h] [ebp-14h]
  void *v9; // [esp+1Ch] [ebp-10h]
  int v10; // [esp+28h] [ebp-4h]

  result = a2;
  if ( a2 == -1 )
  {
    a2 = _wcsdup(L"WMI Database Entries");
    v10 = 0;
    if ( !IsBuiltinAdministrative() )
      CopyStringToString(&a2, L" - run as Administrator for complete scan", 0x7FFFFFFFu, 0);
    v4 = _wcsdup(&gszNullString);
    v5 = _wcsdup(&gszNullString);
    v6 = _wcsdup(&gszNullString);
    v7 = _wcsdup(&gszNullString);
    v8 = _wcsdup(&gszNullString);
    v9 = _wcsdup(&gszNullString);
    LOBYTE(v10) = 6;
    v3 = sub_F73FF0(a1, 2, 0xFFFFFFFF, 0, &a2, &a2, &v9);
    free(v9);
    free(v8);
    free(v7);
    free(v6);
    free(v5);
    free(v4);
    free(a2);
    result = v3;
  }
  return result;
}

//----- (00F95120) --------------------------------------------------------
int __cdecl sub_F95120(IWbemServices *pWbemServices, int a2)
{
  IEnumWbemClassObject *v2; // eax
  HRESULT v3; // eax
  int v4; // ebx
  const WCHAR **v5; // ecx
  wchar_t *v6; // eax
  wchar_t *v7; // esi
  unsigned int v8; // eax
  int v9; // edx
  int v10; // ebx
  int v11; // eax
  unsigned int v12; // edx
  unsigned int v13; // edx
  const wchar_t **v14; // eax
  wchar_t **v15; // ebx
  wchar_t *v16; // eax
  int v17; // edx
  int v18; // eax
  unsigned int v19; // edx
  unsigned int v20; // edx
  VARIANTARG pvarg; // [esp+10h] [ebp-34h]
  unsigned int a2a; // [esp+20h] [ebp-24h]
  int v24; // [esp+24h] [ebp-20h]
  IEnumWbemClassObject *ppEnumOut; // [esp+28h] [ebp-1Ch]
  wchar_t *v26; // [esp+2Ch] [ebp-18h]
  int v27; // [esp+30h] [ebp-14h]
  int v28; // [esp+34h] [ebp-10h]
  int v29; // [esp+40h] [ebp-4h]

  v28 = 0;
  v27 = 0;
  GetQueryEnumObject(&ppEnumOut, pWbemServices, L"SELECT * FROM __NAMESPACE");
  v29 = 0;
  while ( 1 )
  {
    v2 = ppEnumOut;
    if ( !ppEnumOut )
    {
      v4 = v28;
      goto LABEL_41;
    }
    v3 = ppEnumOut->lpVtbl->Next(ppEnumOut, -1, 1, &v27, &v24);
    if ( v3 < 0 || v3 || v24 != 1 )
      break;
    v4 = (*(*v27 + 16))(v27, L"Name", 0, &pvarg, 0, 0);
    v28 = v4;
    (*(*v27 + 8))(v27);
    if ( v4 < 0 )
      goto LABEL_39;
    if ( pvarg.vt != 8 )
    {
      v2 = ppEnumOut;
      v4 = -2147024809;
      goto LABEL_41;
    }
    v5 = &gszNullString;
    if ( pvarg.lVal )
      v5 = pvarg.lVal;
    v6 = _wcsdup(v5);
    v7 = v6;
    v26 = v6;
    v8 = *(a2 + 4);
    LOBYTE(v29) = 1;
    if ( &v26 >= v8 || *a2 > &v26 )
    {
      v17 = *(a2 + 8);
      if ( v8 == v17 && ((v17 - v8) >> 2) < 1 )
      {
        v18 = (v8 - *a2) >> 2;
        if ( (0x3FFFFFFF - v18) < 1 )
LABEL_36:
          std::_Xlength_error("vector<T> too long");
        v19 = (v17 - *a2) >> 2;
        a2a = v18 + 1;
        if ( 0x3FFFFFFF - (v19 >> 1) >= v19 )
          v20 = (v19 >> 1) + v19;
        else
          v20 = 0;
        if ( v20 < a2a )
          v20 = a2a;
        sub_F7FDF0(a2, v20);
      }
      v15 = *(a2 + 4);
      if ( v15 )
      {
        v16 = _wcsdup(v7);
        goto LABEL_34;
      }
    }
    else
    {
      v9 = *(a2 + 8);
      v10 = (&v26 - *a2) >> 2;
      if ( v8 == v9 && ((v9 - v8) >> 2) < 1 )
      {
        v11 = (v8 - *a2) >> 2;
        if ( (0x3FFFFFFF - v11) < 1 )
          goto LABEL_36;
        v12 = (v9 - *a2) >> 2;
        a2a = v11 + 1;
        if ( 0x3FFFFFFF - (v12 >> 1) >= v12 )
          v13 = (v12 >> 1) + v12;
        else
          v13 = 0;
        if ( v13 < a2a )
          v13 = a2a;
        sub_F7FDF0(a2, v13);
      }
      v14 = (*a2 + 4 * v10);
      v15 = *(a2 + 4);
      if ( v15 )
      {
        v16 = _wcsdup(*v14);
LABEL_34:
        *v15 = v16;
        goto LABEL_35;
      }
    }
LABEL_35:
    *(a2 + 4) += 4;
    LOBYTE(v29) = 0;
    free(v7);
    VariantClear(&pvarg);
  }
  v4 = v28;
LABEL_39:
  v2 = ppEnumOut;
LABEL_41:
  v29 = -1;
  if ( v2 )
    v2->lpVtbl->Release(v2);
  return v4;
}

//----- (00F95350) --------------------------------------------------------
char __stdcall sub_F95350(int a1, void *pClassObject, int a3)
{
  IWbemClassObject *v3; // edi
  const wchar_t **v4; // eax
  wchar_t **v5; // ebx
  void *v6; // edi
  wchar_t *v7; // edi
  wchar_t *v8; // ecx
  wchar_t v9; // ax
  char v10; // bl
  wchar_t **v11; // edi
  void *v12; // ebx
  IWbemClassObject v14; // [esp+Ch] [ebp-10h]
  int v15; // [esp+18h] [ebp-4h]

  v3 = pClassObject;
  GetClassObjectName(&pClassObject, pClassObject);
  v15 = 0;
  if ( wcslen(pClassObject) )
  {
    v11 = a3;
    v12 = *a3;
    *v11 = _wcsdup(L"Script embedded in WMI database");
    free(v12);
    goto LABEL_8;
  }
  v4 = GetClassObjectName(&v14, v3);
  v5 = a3;
  v6 = *a3;
  *v5 = _wcsdup(*v4);
  free(v6);
  free(v14.lpVtbl);
  v7 = *v5;
  v8 = *v5;
  do
  {
    v9 = *v8;
    ++v8;
  }
  while ( v9 );
  if ( !(v8 - (*v5 + 1)) )
  {
    *v5 = _wcsdup(L"Incorrectly created script entry");
    free(v7);
LABEL_8:
    v10 = 0;
    goto LABEL_9;
  }
  v10 = 1;
LABEL_9:
  free(pClassObject);
  return v10;
}

//----- (00F95440) --------------------------------------------------------
bool __stdcall sub_F95440(int a1, void *lpszName, void *a3)
{
  const wchar_t **v3; // eax
  std__List **v4; // edi
  void *v5; // esi
  char *v6; // ecx
  __int16 v7; // ax
  const wchar_t **v8; // eax
  std__List *v9; // esi
  char *v10; // ecx
  __int16 v11; // ax
  const wchar_t **v12; // eax
  std__List *v13; // esi
  std__List *v14; // esi
  __int16 v15; // ax
  int v16; // esi
  int a2; // [esp+Ch] [ebp-20h]
  int v19; // [esp+10h] [ebp-1Ch]
  int v20; // [esp+14h] [ebp-18h]
  int v21; // [esp+18h] [ebp-14h]
  IWbemClassObject pClassObject; // [esp+1Ch] [ebp-10h]
  int v23; // [esp+28h] [ebp-4h]

  v3 = GetClassObjectName(&pClassObject, lpszName);
  v4 = a3;
  v5 = *a3;
  *v4 = _wcsdup(*v3);
  free(v5);
  free(pClassObject.lpVtbl);
  v6 = *v4;
  do
  {
    v7 = *v6;
    v6 += 2;
  }
  while ( v7 );
  if ( (v6 - (&(*v4)->_Mypair._Myval2._Myhead + 2)) >> 1 )
    return 0;
  v8 = GetClassObjectName(&lpszName, lpszName);
  v9 = *v4;
  *v4 = _wcsdup(*v8);
  free(v9);
  free(lpszName);
  v10 = *v4;
  do
  {
    v11 = *v10;
    v10 += 2;
  }
  while ( v11 );
  if ( !((v10 - (&(*v4)->_Mypair._Myval2._Myhead + 2)) >> 1) )
    return 0;
  a2 = malloc(2u);
  *a2 = 0;
  v19 = 0;
  v20 = 0;
  v21 = 0;
  v23 = 0;
  if ( !sub_F76CC0(*v4, &a2) )
  {
    sub_F721F0(&a2);
    return 0;
  }
  v12 = sub_F74EE0(&a3, a1, &a2, 0);
  v13 = *v4;
  *v4 = _wcsdup(*v12);
  free(v13);
  free(a3);
  v14 = *v4;
  do
  {
    v15 = v14->_Mypair._Myval2._Myhead;
    v14 = (v14 + 2);
  }
  while ( v15 );
  v16 = v14 - (&(*v4)->_Mypair._Myval2._Myhead + 2);
  sub_F721F0(&a2);
  return v16 >> 1 != 0;
}

//----- (00F955B0) --------------------------------------------------------
int __cdecl sub_F955B0(const wchar_t **a1)
{
  int *v1; // edi
  int *v2; // esi
  int **v3; // eax
  int *j; // eax
  int *i; // eax

  v1 = gMap6;
  v2 = *gMap6;
  if ( *gMap6 == gMap6 )
    return 0;
  while ( _wcsicmp(v2[4], *a1) )
  {
    if ( !*(v2 + 13) )
    {
      v3 = v2[2];
      if ( *(v3 + 13) )
      {
        for ( i = v2[1]; !*(i + 13); i = i[1] )
        {
          if ( v2 != i[2] )
            break;
          v2 = i;
        }
        v2 = i;
      }
      else
      {
        v2 = v2[2];
        for ( j = *v3; !*(j + 13); j = *j )
          v2 = j;
      }
    }
    if ( v2 == v1 )
      return 0;
  }
  return v2[5];
}

//----- (00F95630) --------------------------------------------------------
char __thiscall sub_F95630(void *this, int a2, wchar_t *lpszName, void **a4)
{
  void *v4; // ebx
  const wchar_t **v5; // eax
  void *v6; // esi
  char *v7; // eax
  __int16 v8; // cx
  char result; // al
  IWbemClassObject pClassObject; // [esp+Ch] [ebp-4h]

  v4 = this;
  v5 = GetClassObjectName(&pClassObject, lpszName);
  v6 = *a4;
  *a4 = _wcsdup(*v5);
  free(v6);
  free(pClassObject.lpVtbl);
  v7 = *a4;
  do
  {
    v8 = *v7;
    v7 += 2;
  }
  while ( v8 );
  if ( (v7 - (*a4 + 2)) >> 1 )
    result = 1;
  else
    result = (*(*v4 + 4))(v4, a2, lpszName, a4);
  return result;
}

//----- (00F956B0) --------------------------------------------------------
char __thiscall sub_F956B0(void *this, int a2, wchar_t *lpszName, void **a4)
{
  void *v4; // ebx
  const wchar_t **v5; // eax
  void *v6; // esi
  char *v7; // eax
  __int16 v8; // cx
  char result; // al
  IWbemClassObject pClassObject; // [esp+Ch] [ebp-4h]

  v4 = this;
  v5 = GetClassObjectName(&pClassObject, lpszName);
  v6 = *a4;
  *a4 = _wcsdup(*v5);
  free(v6);
  free(pClassObject.lpVtbl);
  v7 = *a4;
  do
  {
    v8 = *v7;
    v7 += 2;
  }
  while ( v8 );
  if ( (v7 - (*a4 + 2)) >> 1 )
    result = 1;
  else
    result = (*(*v4 + 4))(v4, a2, lpszName, a4);
  return result;
}

//----- (00F95730) --------------------------------------------------------
int __cdecl sub_F95730(LPVOID ppv, int lpszName, OLECHAR *psz, void *lpszText)
{
  int v4; // ebx
  WCHAR *v5; // edi
  const wchar_t **v6; // eax
  WCHAR *v7; // esi
  char v8; // bl
  unsigned int v9; // ecx
  HRESULT v10; // eax
  IWbemClassObject pClassObject; // [esp+10h] [ebp-18h]
  int v13; // [esp+14h] [ebp-14h]
  WCHAR *v14; // [esp+18h] [ebp-10h]
  int v15; // [esp+24h] [ebp-4h]

  v4 = 0;
  v13 = 0;
  v5 = malloc(2u);
  v14 = v5;
  *v5 = 0;
  v15 = 0;
  v6 = GetClassObjectName(&pClassObject, lpszName);
  v7 = _wcsdup(*v6);
  v14 = v7;
  free(v5);
  free(pClassObject.lpVtbl);
  if ( wcslen(v7) )
  {
    if ( lpszText )
    {
      v8 = 0;
      v9 = wcslen(v7);
      if ( v7[v9 - 1] == 34 )
      {
        v8 = 1;
        v7[v9 - 1] = 0;
      }
      CopyStringToString(&v14, lpszText, 0x7FFFFFFFu, 0);
      if ( v8 )
        CopyStringToString(&v14, L"\"", 0x7FFFFFFFu, 0);
      v7 = v14;
    }
    v10 = sub_F95850(ppv, v7, &v13);
    v4 = v13;
    if ( v10 < 0 )
      v4 = 0;
  }
  free(v7);
  return v4;
}

//----- (00F95850) --------------------------------------------------------
HRESULT __cdecl sub_F95850(LPVOID ppv, wchar_t *psz, int a3)
{
  _DWORD *v3; // esi
  OLECHAR *v4; // edi
  wchar_t *v5; // ST14_4
  HRESULT result; // eax
  bool v7; // bl
  int *v8; // edx
  int v9; // edx
  int v10; // eax
  HRESULT v11; // edi
  int v12; // [esp+10h] [ebp-10h]
  int v13; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = psz;
  v5 = psz;
  *a3 = 0;
  result = sub_F95BE0(&ppv, v5);
  if ( result >= 0 )
  {
    v7 = result == 0;
    v8 = *_bstr_t::_bstr_t(&a3, v4);
    v13 = 0;
    if ( v8 )
      v9 = *v8;
    else
      v9 = 0;
    v10 = (*(*ppv + 24))(ppv, v9, 0, 0, &v12, 0);
    v13 = -1;
    v11 = v10;
    _bstr_t::_Free(&a3);
    if ( v11 >= 0 )
      *v3 = v12;
    if ( v7 )
      (*(*ppv + 8))(ppv);
    result = v11;
  }
  return result;
}

//----- (00F95910) --------------------------------------------------------
wchar_t **__stdcall sub_F95910(wchar_t **a1, int a2)
{
  *a1 = _wcsdup(&gszNullString);
  return a1;
}

//----- (00F95940) --------------------------------------------------------
int __stdcall sub_F95940(int pClassObject, void *lpszName)
{
  IWbemClassObject *v2; // esi
  __int16 *v3; // eax
  __int16 v4; // cx
  const wchar_t **v5; // eax
  __int16 *v6; // esi

  v2 = lpszName;
  GetClassObjectName(pClassObject, lpszName);
  v3 = *pClassObject;
  do
  {
    v4 = *v3;
    ++v3;
  }
  while ( v4 );
  if ( !((v3 - *pClassObject - 2) >> 1) )
  {
    v5 = GetClassObjectName(&lpszName, v2);
    v6 = *pClassObject;
    *pClassObject = _wcsdup(*v5);
    free(v6);
    free(lpszName);
  }
  return pClassObject;
}

//----- (00F95A00) --------------------------------------------------------
char __stdcall sub_F95A00(void *lpszName, int a2, int a3)
{
  const wchar_t **v3; // eax
  wchar_t **v4; // edi
  void *v5; // esi
  wchar_t *v6; // eax
  wchar_t v7; // cx
  const wchar_t **v8; // eax
  wchar_t **v9; // esi
  void *v10; // edi
  IWbemClassObject pClassObject; // [esp+8h] [ebp-4h]

  v3 = GetClassObjectName(&pClassObject, lpszName);
  v4 = a3;
  v5 = *a3;
  *v4 = _wcsdup(*v3);
  free(v5);
  free(pClassObject.lpVtbl);
  v6 = *v4;
  do
  {
    v7 = *v6;
    ++v6;
  }
  while ( v7 );
  if ( !(v6 - (*v4 + 1)) )
    return 0;
  v8 = GetClassObjectName(&lpszName, lpszName);
  v9 = a2;
  v10 = *a2;
  *v9 = _wcsdup(*v8);
  free(v10);
  free(lpszName);
  return 1;
}

//----- (00F95AA0) --------------------------------------------------------
char __stdcall sub_F95AA0(int a1, int a2, int a3)
{
  return 0;
}

//----- (00F95AB0) --------------------------------------------------------
int __cdecl GetClassObjectName(wchar_t **lpszName, IWbemClassObject *pClassObject)
{
  const WCHAR **v2; // edx
  const WCHAR *v3; // edx
  HRESULT v4; // eax
  Data_t_bstr_t *v5; // esi
  HRESULT v6; // edi
  const WCHAR **v7; // ecx
  wchar_t *v8; // esi
  int result; // eax
  VARIANTARG pvarg; // [esp+Ch] [ebp-24h]
  int v11; // [esp+1Ch] [ebp-14h]
  _bstr_t v12; // [esp+20h] [ebp-10h]
  int v13; // [esp+2Ch] [ebp-4h]
  OLECHAR *psz; // [esp+40h] [ebp+10h]

  v11 = 0;
  v2 = *_bstr_t::_bstr_t(&v12, psz);
  v13 = 0;
  if ( v2 )
    v3 = *v2;
  else
    v3 = 0;
  v4 = pClassObject->lpVtbl->Get(pClassObject, v3, 0, &pvarg, 0, 0);
  v5 = v12.m_Data;
  v6 = v4;
  if ( v12.m_Data && !InterlockedDecrement(&v12.m_Data->m_RefCount) && v5 )
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
  if ( v6 < 0 || pvarg.vt != 8 )
  {
    *lpszName = _wcsdup(&gszNullString);
    result = lpszName;
  }
  else
  {
    v7 = &gszNullString;
    if ( pvarg.lVal )
      v7 = pvarg.lVal;
    v8 = _wcsdup(v7);
    VariantClear(&pvarg);
    *lpszName = _wcsdup(v8);
    free(v8);
    result = lpszName;
  }
  return result;
}

//----- (00F95BE0) --------------------------------------------------------
HRESULT __cdecl sub_F95BE0(LPVOID *ppv, wchar_t *a2)
{
  wchar_t *v2; // eax
  wchar_t *v3; // edi
  HRESULT result; // eax
  wchar_t *v5; // eax
  HRESULT v6; // esi

  if ( *a2 != 92 )
    return 1;
  v2 = _wcsdup(a2);
  v3 = v2;
  if ( !v2 )
    return -2147024882;
  v5 = wcschr(v2, 0x3Au);
  if ( !v5 )
  {
    free(v3);
    return 1;
  }
  *v5 = 0;
  v6 = LoadWbemServices(v3, ppv);
  free(v3);
  result = 0;
  if ( v6 < 0 )
    result = v6;
  return result;
}

//----- (00F95C50) --------------------------------------------------------
bool __stdcall sub_F95C50(void *pClassObject, int a2)
{
  const wchar_t **v2; // eax
  wchar_t **v3; // edi
  void *v4; // esi
  wchar_t *v5; // eax
  wchar_t v6; // cx

  v2 = GetClassObjectName(&pClassObject, pClassObject);
  v3 = a2;
  v4 = *a2;
  *v3 = _wcsdup(*v2);
  free(v4);
  free(pClassObject);
  v5 = *v3;
  do
  {
    v6 = *v5;
    ++v5;
  }
  while ( v6 );
  return v5 - (*v3 + 1) != 0;
}

//----- (00F95CB0) --------------------------------------------------------
void __thiscall StreamThreadInfo_Release(tagStreamThreadInfo *this)
{
  tagStreamThreadInfo *v1; // esi
  HANDLE v2; // eax
  LPSTREAM v3; // ecx

  v1 = this;
  if ( !InterlockedDecrement(&this->nRefCount) && v1 )
  {
    v2 = v1->hEvent1;
    if ( v2 )
      CloseHandle(v2);
    if ( v1->hEvent2 )
      CloseHandle(v1->hEvent2);
    if ( v1->hEventLoadFailed )
      CloseHandle(v1->hEventLoadFailed);
    if ( v1->hThread )
      CloseHandle(v1->hThread);
    v3 = v1->pStream;
    if ( v3 )
      v3->lpVtbl->Release(v1->pStream);
    j__free(v1);
  }
}

//----- (00F95D10) --------------------------------------------------------
void __cdecl sub_F95D10(int a1)
{
  void **v1; // ebx
  void **v2; // edi
  IEnumWbemClassObject *pEnum_1; // eax
  HRESULT hresult; // eax
  const wchar_t **v5; // eax
  bool v6; // bl
  void **v7; // eax
  const wchar_t **v8; // ebx
  const wchar_t **v9; // esi
  wchar_t *v10; // edi
  void **v11; // esi
  void **v12; // edi
  int v13; // eax
  void *v14; // ebx
  WCHAR **v15; // esi
  IEnumWbemClassObject *v16; // eax
  void *v17; // edi
  int v18; // eax
  void *v19; // eax
  tagStreamThreadInfo *v20; // esi
  HANDLE v21; // eax
  WCHAR *v22; // ebx
  WCHAR *v23; // esi
  IWbemClassObject *v24; // edi
  const wchar_t **v25; // eax
  const wchar_t **v26; // eax
  WCHAR *v27; // edi
  const wchar_t **v28; // eax
  WCHAR *v29; // edi
  WCHAR *v30; // edi
  IWbemClassObject *v31; // edi
  const wchar_t **v32; // eax
  void *v33; // edi
  wchar_t *v34; // edi
  wchar_t *v35; // edi
  void *v36; // edi
  char *v37; // edi
  _WORD *v38; // eax
  _WORD *v39; // eax
  _WORD *v40; // eax
  IWbemClassObject *v41; // ecx
  WCHAR **v42; // eax
  void *v43; // edi
  wchar_t *v44; // eax
  IWbemClassObject **v45; // ebx
  int v46; // ecx
  int v47; // ecx
  WCHAR **v48; // esi
  WCHAR *v49; // edi
  WCHAR *v50; // eax
  WCHAR v51; // cx
  void *v52; // edi
  wchar_t *v53; // eax
  void *v54; // edi
  wchar_t *v55; // eax
  _DWORD *v56; // edi
  WCHAR **v57; // ecx
  WCHAR **v58; // ebx
  WCHAR **v59; // esi
  WCHAR *v60; // eax
  WCHAR *j; // eax
  int i; // eax
  void **k; // esi
  IWbemClassObject v64; // [esp+10h] [ebp-B4h]
  IWbemClassObject v65; // [esp+14h] [ebp-B0h]
  IWbemClassObject v66; // [esp+18h] [ebp-ACh]
  IWbemClassObject v67; // [esp+1Ch] [ebp-A8h]
  void *v68; // [esp+20h] [ebp-A4h]
  void *v69; // [esp+24h] [ebp-A0h]
  int v70; // [esp+28h] [ebp-9Ch]
  int v71; // [esp+2Ch] [ebp-98h]
  void *v72; // [esp+30h] [ebp-94h]
  void *v73; // [esp+34h] [ebp-90h]
  void *v74; // [esp+38h] [ebp-8Ch]
  wchar_t *v75; // [esp+3Ch] [ebp-88h]
  wchar_t *v76; // [esp+40h] [ebp-84h]
  int v77; // [esp+44h] [ebp-80h]
  wchar_t *v78; // [esp+48h] [ebp-7Ch]
  void *v79; // [esp+4Ch] [ebp-78h]
  IWbemClassObject *pClassObject; // [esp+50h] [ebp-74h]
  void *ppv1; // [esp+54h] [ebp-70h]
  void *theMap; // [esp+58h] [ebp-6Ch]
  int v83; // [esp+5Ch] [ebp-68h]
  std__vector v84; // [esp+60h] [ebp-64h]
  void *v85; // [esp+6Ch] [ebp-58h]
  WCHAR **v86; // [esp+70h] [ebp-54h]
  IEnumWbemClassObject *pEnum; // [esp+74h] [ebp-50h]
  void *v88; // [esp+78h] [ebp-4Ch]
  void *cbReturned; // [esp+7Ch] [ebp-48h]
  int v90; // [esp+80h] [ebp-44h]
  void *v91; // [esp+84h] [ebp-40h]
  void *v92; // [esp+88h] [ebp-3Ch]
  int v93; // [esp+8Ch] [ebp-38h]
  IWbemClassObject *v94; // [esp+90h] [ebp-34h]
  char v95; // [esp+97h] [ebp-2Dh]
  IWbemServices *pWbemServices; // [esp+98h] [ebp-2Ch]
  wchar_t *lpszName; // [esp+9Ch] [ebp-28h]
  WCHAR *ppv3; // [esp+A0h] [ebp-24h]
  IEnumWbemClassObject *ppEnumOut; // [esp+A4h] [ebp-20h]
  wchar_t *a2; // [esp+A8h] [ebp-1Ch]
  WCHAR *ppv; // [esp+ACh] [ebp-18h]
  wchar_t *psz; // [esp+B0h] [ebp-14h]
  wchar_t *v103; // [esp+B4h] [ebp-10h]
  int v104; // [esp+C0h] [ebp-4h]

  v1 = 0;
  pWbemServices = 0;
  v2 = 0;
  v84.baseclass_0._Mypair._Myval2._Mylast = 0;
  v84.baseclass_0._Mypair._Myval2._Myfirst = 0;
  v84.baseclass_0._Mypair._Myval2._Myend = 0;
  v104 = 0;
  lpszName = 0;
  v83 = 0;
  theMap = std::_Tree_comp_alloc<std::_Tmap_traits<wchar_t const *,tagKeyName,std::less<wchar_t const *>,std::allocator<std::pair<wchar_t const * const,tagKeyName>>,0>>::_Buyheadnode();
  ppv3 = malloc(2u);
  *ppv3 = 0;
  v85 = malloc(2u);
  *v85 = 0;
  v88 = malloc(2u);
  *v88 = 0;
  v79 = malloc(2u);
  *v79 = 0;
  v74 = malloc(2u);
  *v74 = 0;
  v73 = malloc(2u);
  *v73 = 0;
  psz = malloc(2u);
  *psz = 0;
  v78 = malloc(2u);
  *v78 = 0;
  v76 = malloc(2u);
  *v76 = 0;
  v75 = malloc(2u);
  *v75 = 0;
  LOBYTE(v104) = 11;
  ppv1 = sub_F94FE0(a1, 0xFFFFFFFF);
  if ( CoInitializeEx(0, 0) >= 0 )
  {
    if ( IsBuiltinAdministrative() )
      gdwTimeout *= 4;
    if ( LoadWbemServices(L"ROOT\\subscription", &pWbemServices) >= 0 )
    {
      GetQueryEnumObject(&pEnum, pWbemServices, L"SELECT * FROM __EventConsumer");
      pEnum_1 = pEnum;
      LOBYTE(v104) = 12;
      if ( pEnum )
      {
        while ( pEnum_1 )
        {
          hresult = pEnum_1->lpVtbl->Next(pEnum_1, -1, 1, &lpszName, &cbReturned);
          if ( hresult < 0 || hresult || cbReturned != 1 )
            break;
          v5 = GetClassObjectName(&pClassObject, lpszName);
          v6 = sub_F955B0(v5) != 0;
          free(pClassObject);
          if ( v6 )
          {
            v91 = 0;
            v92 = 0;
            v93 = 0;
            LOBYTE(v104) = 13;
            v7 = sub_F94BC0(&theMap, &lpszName);
            sub_F94B60(v7, &v91);
            LOBYTE(v104) = 12;
            if ( v91 )
            {
              j__free(v91);
              pEnum_1 = pEnum;
              v91 = 0;
              v92 = 0;
              v93 = 0;
            }
            else
            {
              pEnum_1 = pEnum;
            }
          }
          else
          {
            (*(*lpszName + 8))(lpszName);
            pEnum_1 = pEnum;
          }
        }
        v1 = v84.baseclass_0._Mypair._Myval2._Mylast;
      }
      if ( v83 )
      {
        a2 = _wcsdup(L"ROOT");
        LOBYTE(v104) = 14;
        sub_F80530(&v84, &a2);
        LOBYTE(v104) = 12;
        free(a2);
        v8 = v84.baseclass_0._Mypair._Myval2._Mylast;
        v9 = v84.baseclass_0._Mypair._Myval2._Myfirst;
        if ( (v84.baseclass_0._Mypair._Myval2._Mylast - v84.baseclass_0._Mypair._Myval2._Myfirst) & 0xFFFFFFFC )
        {
          do
          {
            v10 = _wcsdup(*v9);
            a2 = v10;
            LOBYTE(v104) = 15;
            sub_F94700(v9 + 1, v8, v9);
            --v8;
            v11 = v8;
            if ( v8 != v84.baseclass_0._Mypair._Myval2._Mylast )
            {
              v12 = v84.baseclass_0._Mypair._Myval2._Mylast;
              do
              {
                free(*v11);
                ++v11;
              }
              while ( v11 != v12 );
              v10 = a2;
            }
            v84.baseclass_0._Mypair._Myval2._Mylast = v8;
            if ( LoadWbemServices(v10, &pWbemServices) >= 0 )
            {
              v91 = 0;
              v92 = 0;
              v93 = 0;
              LOBYTE(v104) = 16;
              v13 = sub_F95120(pWbemServices, &v91);
              v14 = v92;
              v15 = v91;
              if ( v13 >= 0 )
              {
                if ( v91 != v92 )
                {
                  do
                  {
                    ppv = _wcsdup(v10);
                    LOBYTE(v104) = 17;
                    CopyStringToString(&ppv, L"\\", 0x7FFFFFFFu, 0);
                    CopyStringToString(&ppv, *v15, 0x7FFFFFFFu, 0);
                    sub_F80530(&v84, &ppv);
                    LOBYTE(v104) = 16;
                    free(ppv);
                    ++v15;
                  }
                  while ( v15 != v14 );
                }
                v15 = v91;
              }
              GetQueryEnumObject(&ppEnumOut, pWbemServices, L"SELECT * FROM __FilterToConsumerBinding");
              v16 = ppEnumOut;
              LOBYTE(v104) = 18;
              if ( ppEnumOut )
              {
                v17 = ppv1;
                while ( v16 )
                {
                  v18 = v16->lpVtbl->Next(v16, -1, 1, &lpszName, &cbReturned);
                  if ( v18 < 0 || v18 || cbReturned != 1 )
                    break;
                  sub_F96830(a1, v17, pWbemServices, lpszName, &theMap);
                  (*(*lpszName + 8))(lpszName);
                  v16 = ppEnumOut;
                }
                v10 = a2;
              }
              pWbemServices->lpVtbl->Release(pWbemServices);
              LOBYTE(v104) = 16;
              if ( ppEnumOut )
                ppEnumOut->lpVtbl->Release(ppEnumOut);
              if ( v15 )
              {
                v19 = v91;
                if ( v91 != v14 )
                {
                  do
                  {
                    free(*v15);
                    ++v15;
                  }
                  while ( v15 != v14 );
                  v19 = v91;
                }
                j__free(v19);
                v91 = 0;
                v92 = 0;
                v93 = 0;
              }
              LOBYTE(v104) = 12;
              free(v10);
              v8 = v84.baseclass_0._Mypair._Myval2._Mylast;
            }
            else
            {
              LOBYTE(v104) = 12;
              free(v10);
            }
            v9 = v84.baseclass_0._Mypair._Myval2._Myfirst;
          }
          while ( (v8 - v84.baseclass_0._Mypair._Myval2._Myfirst) & 0xFFFFFFFC );
        }
        v20 = gpStreamThreadInfo;
        if ( gpStreamThreadInfo )
        {
          v21 = gpStreamThreadInfo->hEventLoadFailed;
          gpStreamThreadInfo->bRelease = 1;
          if ( v21 )
            SetEvent(v21);
          StreamThreadInfo_Release(v20);
          gpStreamThreadInfo = 0;
        }
        v22 = theMap;
        a2 = theMap;
        v23 = *theMap;
        ppv = v23;
        if ( v23 != theMap )
        {
          do
          {
            v94 = *(v23 + 4);
            v24 = v94;
            v25 = GetClassObjectName(&v65, v94);
            ppEnumOut = sub_F955B0(v25);
            free(v65.lpVtbl);
            pClassObject = 4;
            v77 = 1;
            v26 = GetClassObjectName(&v67, v24);
            v27 = ppv3;
            ppv3 = _wcsdup(*v26);
            free(v27);
            free(v67.lpVtbl);
            if ( wcslen(ppv3) )
            {
              if ( wcslen(ppv3) >= 9 )
              {
                v30 = &ppv3[wcslen(ppv3) - 9];
                if ( !_wcsicmp(v30, L"_disabled") )
                {
                  v77 = 0;
                  *v30 = 0;
                }
              }
            }
            else
            {
              v28 = GetClassObjectName(&v64, v94);
              v29 = ppv3;
              ppv3 = _wcsdup(*v28);
              free(v29);
              free(v64.lpVtbl);
            }
            v31 = v94;
            if ( (ppEnumOut->lpVtbl->AddRef)(a1, v94, &psz) )
            {
              v32 = (ppEnumOut->lpVtbl->QueryInterface)(&v68, v31);
              v33 = v85;
              v85 = _wcsdup(*v32);
              free(v33);
              free(v68);
              if ( (ppEnumOut->lpVtbl->Reset)(v94, &v75) )
              {
                v103 = malloc(2u);
                *v103 = 0;
                LOBYTE(v104) = 19;
                if ( sub_F81150(a1, v75, psz, &v103) )
                {
                  v34 = psz;
                  psz = _wcsdup(v103);
                  free(v34);
                }
                LOBYTE(v104) = 12;
                free(v103);
              }
              pClassObject = sub_F74ED0();
            }
            else
            {
              v35 = psz;
              if ( wcslen(psz) )
              {
                psz = _wcsdup(&gszNullString);
                free(v35);
                v36 = v88;
                v88 = _wcsdup(psz);
                free(v36);
              }
            }
            (ppEnumOut->lpVtbl->Release)(a1, v94, &v73);
            v72 = _wcsdup(L"WMI Database Entries");
            v69 = _wcsdup(&gszNullString);
            LOBYTE(v104) = 21;
            v95 = sub_F73D40(a1, &v69, &v72, &v85, &psz, &v79, &v74, &v70);
            free(v69);
            LOBYTE(v104) = 12;
            free(v72);
            if ( v95 )
            {
              v37 = operator new(0x18u);
              v103 = v37;
              if ( v37 )
              {
                v38 = malloc(2u);
                *(v37 + 3) = v38;
                *v38 = 0;
                v39 = malloc(2u);
                *(v37 + 4) = v39;
                *v39 = 0;
                v40 = malloc(2u);
                *(v37 + 5) = v40;
                *v40 = 0;
                v37[8] = 0;
                *v37 = 0;
                *(v37 + 1) = 0;
              }
              else
              {
                v37 = 0;
                v103 = 0;
              }
              v41 = v94;
              *(v37 + 1) = v94;
              v41->lpVtbl->AddRef(v41);
              v42 = (v37 + 12);
              v43 = *(v37 + 3);
              v86 = v42;
              v44 = _wcsdup(&gszNullString);
              *(v103 + 3) = v44;
              free(v43);
              if ( (*(v23 + 6) - *(v23 + 5)) & 0xFFFFFFFC )
              {
                v45 = *(v23 + 5);
                v46 = *(v23 + 6) - v45;
                v71 = 0;
                v47 = (v46 + 3) >> 2;
                if ( v45 > *(v23 + 6) )
                  v47 = 0;
                v90 = v47;
                if ( v47 )
                {
                  v48 = v86;
                  do
                  {
                    GetClassObjectName(&v66, *v45);
                    v49 = v66.lpVtbl;
                    if ( wcslen(v66.lpVtbl) )
                    {
                      v50 = *v48;
                      do
                      {
                        v51 = *v50;
                        ++v50;
                      }
                      while ( v51 );
                      if ( v50 - (*v48 + 1) )
                        CopyStringToString(v48, L"; ", 0x7FFFFFFFu, 0);
                      CopyStringToString(v48, v49, 0x7FFFFFFFu, 0);
                    }
                    free(v49);
                    ++v45;
                    ++v71;
                  }
                  while ( v71 != v90 );
                  v23 = ppv;
                }
                v22 = a2;
              }
              else
              {
                v77 = 0;
              }
              if ( (ppEnumOut->lpVtbl->Next)(v94, &v78, &v76) )
              {
                v52 = *(v103 + 4);
                v53 = _wcsdup(v78);
                *(v103 + 4) = v53;
                free(v52);
                v54 = *(v103 + 5);
                v55 = _wcsdup(v76);
                *(v103 + 5) = v55;
                free(v54);
                *(v103 + 8) = 1;
              }
              ppv1 = sub_F94FE0(a1, ppv1);
              cbReturned = _wcsdup(&gszNullString);
              LOBYTE(v104) = 22;
              sub_F73FF0(a1, pClassObject, ppv1, 17, &ppv3, &v85, &psz);
              LOBYTE(v104) = 12;
              free(cbReturned);
            }
            v94->lpVtbl->Release(v94);
            v56 = *(v23 + 5);
            v57 = ((*(v23 + 6) - v56 + 3) >> 2);
            if ( v56 > *(v23 + 6) )
              v57 = 0;
            v86 = v57;
            if ( v57 )
            {
              v58 = 0;
              v59 = v57;
              do
              {
                (*(**v56 + 8))(*v56);
                v58 = (v58 + 1);
                ++v56;
              }
              while ( v58 != v59 );
              v23 = ppv;
              v22 = a2;
            }
            if ( !*(v23 + 13) )
            {
              v60 = *(v23 + 2);
              if ( *(v60 + 13) )
              {
                for ( i = *(v23 + 1); !*(i + 13); i = *(i + 4) )
                {
                  if ( v23 != *(i + 8) )
                    break;
                  v23 = i;
                }
                v23 = i;
                ppv = i;
              }
              else
              {
                v23 = *(v23 + 2);
                ppv = v60;
                for ( j = *v60; !*(j + 13); j = *j )
                {
                  v23 = j;
                  ppv = j;
                }
              }
            }
          }
          while ( v23 != v22 );
        }
        v2 = v84.baseclass_0._Mypair._Myval2._Myfirst;
        v1 = v84.baseclass_0._Mypair._Myval2._Mylast;
      }
      else
      {
        sub_F94D60();
      }
      LOBYTE(v104) = 11;
      if ( pEnum )
        pEnum->lpVtbl->Release(pEnum);
    }
  }
  free(v75);
  free(v76);
  free(v78);
  free(psz);
  free(v73);
  free(v74);
  free(v79);
  free(v88);
  free(v85);
  free(ppv3);
  LOBYTE(v104) = 0;
  sub_F971F0(&theMap, &v90, *theMap, theMap);
  j__free(theMap);
  if ( v2 )
  {
    for ( k = v2; k != v1; ++k )
      free(*k);
    j__free(v2);
  }
}

//----- (00F96830) --------------------------------------------------------
unsigned int __cdecl sub_F96830(int a1, int a2, LPVOID ppv, int a4, int a5)
{
  int v5; // eax
  wchar_t *v6; // esi
  int v7; // ebx
  std__Tree_node *v8; // ebx
  std__Tree_node *v9; // esi
  IWbemClassObjectVtbl *v10; // edi
  int v12; // [esp+10h] [ebp-2Ch]
  IWbemClassObject v13; // [esp+14h] [ebp-28h]
  IWbemClassObject pClassObject; // [esp+18h] [ebp-24h]
  wchar_t *lpszName; // [esp+1Ch] [ebp-20h]
  IWbemClassObject v16; // [esp+20h] [ebp-1Ch]
  int v17; // [esp+24h] [ebp-18h]
  std__tree v18; // [esp+28h] [ebp-14h]
  int v19; // [esp+38h] [ebp-4h]

  v18._Mypair._Myval2._Mysize = 0;
  lpszName = sub_F95730(ppv, a4, L"Consumer", 0);
  v5 = sub_F95730(ppv, a4, L"Filter", 0);
  v6 = lpszName;
  v7 = v5;
  v17 = v5;
  v12 = v5;
  if ( lpszName )
  {
    if ( v5 )
    {
      GetClassObjectName(&pClassObject, lpszName);
      v19 = 0;
      if ( sub_F955B0(&pClassObject) )
      {
        GetClassObjectName(&v16, v6);
        LOBYTE(v19) = 1;
        v8 = *a5;
        v9 = **a5;
        v18._Mypair._Myval2._Myhead = v9;
        if ( v9 == v8 )
        {
LABEL_7:
          v7 = v17;
        }
        else
        {
          while ( 1 )
          {
            GetClassObjectName(&v13, v9[1]._Left);
            v10 = v13.lpVtbl;
            LOBYTE(v19) = 2;
            if ( !_wcsicmp(v16.lpVtbl, v13.lpVtbl) )
              break;
            LOBYTE(v19) = 1;
            free(v10);
            sub_F94CE0(&v18);
            v9 = v18._Mypair._Myval2._Myhead;
            if ( v18._Mypair._Myval2._Myhead == v8 )
              goto LABEL_7;
          }
          std::vector<tagAccountInfo *,std::allocator<tagAccountInfo *>>::push_back(&v9[1]._Parent, &v12);
          v7 = 0;
          v18._Mypair._Myval2._Mysize = 1;
          free(v10);
        }
        free(v16.lpVtbl);
        v6 = lpszName;
      }
      v19 = -1;
      free(pClassObject.lpVtbl);
    }
    (*(*v6 + 8))(v6);
  }
  if ( v7 )
    (*(*v7 + 8))(v7);
  return v18._Mypair._Myval2._Mysize;
}

//----- (00F969A0) --------------------------------------------------------
DWORD __stdcall StreamToWbemServicesThreadProc(IWbemLocator *pLocator)
{
  tagStreamThreadInfo *v1; // esi
  HRESULT v2; // eax
  HRESULT v3; // eax
  OLECHAR **v4; // edx
  OLECHAR *v5; // edx
  HRESULT v6; // eax
  Data_t_bstr_t *v7; // edi
  HRESULT v8; // eax
  IWbemServices *pWbemServices; // [esp+10h] [ebp-14h]
  _bstr_t v11; // [esp+14h] [ebp-10h]
  int v12; // [esp+20h] [ebp-4h]

  v1 = pLocator;
  InterlockedIncrement(&pLocator[1]);
  v2 = CoInitializeEx(0, 0);
  v1->hresult = v2;
  if ( v2 >= 0 )
  {
    v3 = CoCreateInstance(&CLSID_WbemLocator, 0, 1u, &IID_IWbemLocator, &pLocator);
    v1->hresult = v3;
    if ( v3 >= 0 )
    {
      while ( SetEvent(v1->hEvent1) )
      {
        v4 = *_bstr_t::_bstr_t(&v11, v1->pszServer);
        v12 = 0;
        if ( v4 )
          v5 = *v4;
        else
          v5 = 0;
        v6 = pLocator->lpVtbl->ConnectServer(pLocator, v5, 0, 0, 0, 128, 0, 0, &pWbemServices);
        v7 = v11.m_Data;
        v1->hresult = v6;
        v12 = -1;
        if ( v7 )
        {
          if ( !InterlockedDecrement(&v7->m_RefCount) && v7 )
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
          v11.m_Data = 0;
        }
        if ( v1->hresult < 0 )
          break;
        v8 = CoMarshalInterThreadInterfaceInStream(&CLSID_IWbemServices, pWbemServices, &v1->pStream);
        v1->hresult = v8;
        if ( v8 < 0 )
          goto LABEL_21;
        if ( !SetEvent(v1->hEvent2) )
        {
          pLocator->lpVtbl->Release(pLocator);
          v1->hresult = -2147467259;
          return 0;
        }
        if ( WaitForSingleObject(v1->hEventLoadFailed, 0xFFFFFFFF) )
        {
          v1->hresult = -2147467259;
LABEL_21:
          pLocator->lpVtbl->Release(pLocator);
          StreamThreadInfo_Release(v1);
          return 1;
        }
        if ( v1->bRelease )
          goto LABEL_21;
      }
      pLocator->lpVtbl->Release(pLocator);
    }
  }
  StreamThreadInfo_Release(v1);
  return 0;
}

//----- (00F96B70) --------------------------------------------------------
_DWORD *__thiscall sub_F96B70(_DWORD *this)
{
  _DWORD *v1; // esi
  _DWORD *v2; // edx

  v1 = this;
  v2 = operator new(0x20u);
  if ( !v2 )
    std::_Xbad_alloc();
  *v2 = *v1;
  if ( v2 != -4 )
    v2[1] = *v1;
  if ( v2 != -8 )
    v2[2] = *v1;
  return v2;
}

//----- (00F96BB0) --------------------------------------------------------
_DWORD *__thiscall sub_F96BB0(_DWORD *this, int a2, size_t a3)
{
  _DWORD *v3; // esi
  unsigned int v4; // edi
  unsigned int v5; // ebx
  unsigned int v6; // ecx
  _DWORD *v7; // eax
  _DWORD *v8; // ecx
  _DWORD *result; // eax
  int v10; // [esp+0h] [ebp-28h]
  _DWORD *v11; // [esp+10h] [ebp-18h]
  _DWORD *v12; // [esp+14h] [ebp-14h]
  int *v13; // [esp+18h] [ebp-10h]
  int v14; // [esp+24h] [ebp-4h]

  v13 = &v10;
  v3 = this;
  v11 = this;
  v4 = a2 | 0xF;
  if ( (a2 | 0xFu) <= 0xFFFFFFFE )
  {
    v5 = this[5];
    v6 = this[5] >> 1;
    if ( v6 > v4 / 3 )
    {
      v4 = v6 + v5;
      if ( v5 > -2 - v6 )
        v4 = -2;
    }
  }
  else
  {
    v4 = a2;
  }
  v14 = 0;
  v7 = 0;
  v12 = 0;
  if ( v4 != -1 )
  {
    if ( v4 + 1 > 0xFFFFFFFF || (v7 = operator new(v4 + 1), (v12 = v7) == 0) )
      std::_Xbad_alloc();
  }
  if ( a3 )
  {
    v8 = v3[5] < 0x10u ? v3 : *v3;
    if ( a3 )
      memmove_0(v7, v8, a3);
  }
  if ( v3[5] >= 0x10u )
    j__free(*v3);
  result = v12;
  *v3 = 0;
  *v3 = result;
  v3[5] = v4;
  v3[4] = a3;
  if ( v4 >= 0x10 )
    v3 = result;
  *(v3 + a3) = 0;
  return result;
}
// 10081AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);

//----- (00F96D00) --------------------------------------------------------
void __stdcall sub_F96D00(void *a1)
{
  if ( *(a1 + 5) )
  {
    j__free(*(a1 + 5));
    *(a1 + 5) = 0;
    *(a1 + 6) = 0;
    *(a1 + 7) = 0;
  }
  j__free(a1);
}

//----- (00F96D40) --------------------------------------------------------
void __stdcall sub_F96D40(void *a1)
{
  free(*(a1 + 4));
  j__free(a1);
}

//----- (00F96D60) --------------------------------------------------------
void __stdcall sub_F96D60(void *a1)
{
  void **v1; // esi
  void **v2; // edi

  v1 = a1;
  v2 = a1;
  if ( !*(a1 + 13) )
  {
    do
    {
      sub_F96D60(v2[2]);
      v2 = *v2;
      if ( v1[5] )
      {
        j__free(v1[5]);
        v1[5] = 0;
        v1[6] = 0;
        v1[7] = 0;
      }
      j__free(v1);
      v1 = v2;
    }
    while ( !*(v2 + 13) );
  }
}

//----- (00F96DC0) --------------------------------------------------------
void __stdcall sub_F96DC0(void *a1)
{
  void **v1; // edi
  void **v2; // esi

  v1 = a1;
  v2 = a1;
  if ( !*(a1 + 13) )
  {
    do
    {
      sub_F96DC0(v2[2]);
      v2 = *v2;
      free(v1[4]);
      j__free(v1);
      v1 = v2;
    }
    while ( !*(v2 + 13) );
  }
}

//----- (00F96E00) --------------------------------------------------------
BOOL __thiscall sub_F96E00(void *this, size_t a2, int a3)
{
  _DWORD *v3; // esi
  size_t v4; // eax
  BOOL result; // eax
  size_t v6; // ebx
  void *v7; // eax
  int v8; // [esp+14h] [ebp+Ch]

  v3 = this;
  if ( a2 > 0xFFFFFFFE )
    std::_Xlength_error("string too long");
  v4 = *(this + 5);
  if ( v4 >= a2 )
  {
    if ( a3 && a2 < 0x10 )
    {
      v6 = *(this + 4);
      if ( a2 < v6 )
        v6 = a2;
      if ( v4 >= 0x10 )
      {
        v7 = *this;
        v8 = *this;
        if ( v6 )
        {
          memmove_0(this, v7, v6);
          v7 = v8;
        }
        j__free(v7);
      }
      v3[4] = v6;
      v3[5] = 15;
      *(v3 + v6) = 0;
      result = a2 > 0;
    }
    else
    {
      if ( !a2 )
      {
        *(this + 4) = 0;
        if ( v4 >= 0x10 )
          v3 = *this;
        *v3 = 0;
      }
      result = a2 > 0;
    }
  }
  else
  {
    sub_F96BB0(this, a2, *(this + 4));
    result = a2 > 0;
  }
  return result;
}

//----- (00F96EC0) --------------------------------------------------------
void *__stdcall sub_F96EC0(size_t a1)
{
  void *v1; // ecx

  v1 = 0;
  if ( a1 )
  {
    if ( a1 > 0xFFFFFFFF || (v1 = operator new(a1)) == 0 )
      std::_Xbad_alloc();
  }
  return v1;
}

//----- (00F96F00) --------------------------------------------------------
_DWORD *__thiscall sub_F96F00(_DWORD *this, int a2, int a3, size_t a4)
{
  int v4; // ebx
  _DWORD *v5; // esi
  int v6; // ecx
  unsigned int v7; // edi
  unsigned int v8; // edi
  int v9; // eax
  bool v10; // cf
  _DWORD *result; // eax
  unsigned int v12; // eax
  void *v13; // edx

  v4 = a2;
  v5 = this;
  v6 = a3;
  v7 = *(a2 + 16);
  if ( v7 < a3 )
    std::_Xout_of_range("invalid string position");
  v8 = v7 - a3;
  if ( a4 < v8 )
    v8 = a4;
  if ( v5 != a2 )
  {
    if ( v8 > 0xFFFFFFFE )
      std::_Xlength_error("string too long");
    v12 = v5[5];
    if ( v12 >= v8 )
    {
      if ( !v8 )
      {
        v5[4] = 0;
        if ( v12 < 0x10 )
        {
          result = v5;
          *v5 = 0;
        }
        else
        {
          **v5 = 0;
          result = v5;
        }
        return result;
      }
    }
    else
    {
      sub_F96BB0(v5, v8, v5[4]);
      v6 = a3;
      if ( !v8 )
        return v5;
    }
    if ( *(a2 + 20) >= 0x10u )
      v4 = *a2;
    if ( v5[5] < 0x10u )
      v13 = v5;
    else
      v13 = *v5;
    if ( v8 )
      memmove_0(v13, (v4 + v6), v8);
    v10 = v5[5] < 0x10u;
    v5[4] = v8;
    if ( !v10 )
    {
      *(*v5 + v8) = 0;
      return v5;
    }
    *(v5 + v8) = 0;
    return v5;
  }
  v9 = v8 + a3;
  if ( v5[4] < v8 + a3 )
    std::_Xout_of_range("invalid string position");
  v10 = v5[5] < 0x10u;
  v5[4] = v9;
  if ( v10 )
    *(v5 + v9) = 0;
  else
    *(*v5 + v9) = 0;
  sub_F97890(v5, 0, a3);
  return v5;
}

//----- (00F97030) --------------------------------------------------------
_DWORD *__thiscall sub_F97030(int this, void *a2, size_t a3)
{
  _DWORD *v3; // esi
  unsigned int v4; // ecx
  unsigned int v5; // eax
  _DWORD *v6; // edx
  _DWORD *result; // eax
  size_t v8; // eax
  void *v9; // eax
  bool v10; // cf

  v3 = this;
  if ( a2 )
  {
    v4 = *(this + 20);
    v5 = (v4 < 0x10 ? v3 : *v3);
    if ( a2 >= v5 )
    {
      v6 = v4 < 0x10 ? v3 : *v3;
      if ( v6 + v3[4] > a2 )
      {
        if ( v4 < 0x10 )
          result = sub_F96F00(v3, v3, a2 - v3, a3);
        else
          result = sub_F96F00(v3, v3, a2 - *v3, a3);
        return result;
      }
    }
  }
  if ( a3 > 0xFFFFFFFE )
    std::_Xlength_error("string too long");
  v8 = v3[5];
  if ( v8 < a3 )
  {
    sub_F96BB0(v3, a3, v3[4]);
    if ( !a3 )
      return v3;
LABEL_16:
    if ( v3[5] < 0x10u )
      v9 = v3;
    else
      v9 = *v3;
    if ( a3 )
      memmove_0(v9, a2, a3);
    v10 = v3[5] < 0x10u;
    v3[4] = a3;
    if ( !v10 )
    {
      *(*v3 + a3) = 0;
      return v3;
    }
    *(v3 + a3) = 0;
    return v3;
  }
  if ( a3 )
    goto LABEL_16;
  v3[4] = 0;
  if ( v8 < 0x10 )
  {
    result = v3;
    *v3 = 0;
  }
  else
  {
    **v3 = 0;
    result = v3;
  }
  return result;
}

//----- (00F97130) --------------------------------------------------------
int *__stdcall std::_System_error_category::default_error_condition(int *a1, int a2)
{
  bool v2; // zf
  int *result; // eax

  v2 = sub_100465F(a2) == 0;
  result = a1;
  *a1 = a2;
  if ( v2 )
    a1[1] = &off_105AA44;
  else
    a1[1] = off_105AA3C;
  return result;
}
// 105AA3C: using guessed type int (__thiscall **off_105AA3C[3])(void *, char);
// 105AA44: using guessed type int (__thiscall **off_105AA44)(void *, char);

//----- (00F97190) --------------------------------------------------------
bool __thiscall std::error_category_equivalent(void *this, _DWORD *a2, int a3)
{
  return this == a2[1] && *a2 == a3;
}

//----- (00F971B0) --------------------------------------------------------
bool __thiscall std::error_category_equivalent2(void *this, int a2, _DWORD *a3)
{
  _DWORD *v3; // eax
  char v5; // [esp+0h] [ebp-8h]

  v3 = (*(*this + 12))(&v5, a2);
  return v3[1] == a3[1] && *v3 == *a3;
}

//----- (00F971F0) --------------------------------------------------------
int __thiscall sub_F971F0(CSystemProcessInfoMap *this, int a2, void *a3, int a4)
{
  void *v4; // eax
  CSystemProcessInfoMap *v5; // esi
  std__Tree_node *v6; // ecx
  std__Tree_node *v7; // eax
  std__Tree_node *v8; // ecx
  int result; // eax
  void *v10; // ecx
  _DWORD *i; // edx
  _BYTE *j; // eax
  int v13; // [esp+4h] [ebp-4h]

  v4 = a3;
  v5 = this;
  v6 = this->_Header;
  if ( a3 != v6->_Left || a4 != v6 )
  {
    for ( ; a3 != a4; v4 = a3 )
    {
      v10 = v4;
      if ( !*(v4 + 13) )
      {
        i = *(v4 + 2);
        if ( *(i + 13) )
        {
          for ( i = *(v4 + 1); !*(i + 13); i = i[1] )
          {
            if ( v4 != i[2] )
              break;
            v4 = i;
          }
        }
        else
        {
          for ( j = *i; !j[13]; j = *j )
            i = j;
        }
        a3 = i;
      }
      sub_F972B0(v5, &v13, v10);
    }
    *a2 = v4;
    result = a2;
  }
  else
  {
    sub_F96D60(v6->_Parent);
    v5->_Header->_Parent = v5->_Header;
    v5->_Header->_Left = v5->_Header;
    v5->_Header->_Right = v5->_Header;
    v7 = v5->_Header;
    v5->_Size = 0;
    v8 = v7->_Left;
    result = a2;
    *a2 = v8;
  }
  return result;
}

//----- (00F972B0) --------------------------------------------------------
int __thiscall sub_F972B0(CSystemProcessInfoMap *this, int a2, void *a3)
{
  std__Tree_node **v3; // ebx
  std__Tree_node *v4; // edi
  std__Tree_node *v5; // ecx
  std__Tree_node *v6; // esi
  std__tree *v7; // edx
  std__Tree_node *v8; // eax
  std__Tree_node *v9; // ecx
  std__Tree_node *v10; // eax
  std__Tree_node_For__bstr_t *v11; // eax
  std__Tree_node_For__bstr_t *i; // ecx
  std__Tree_node **v13; // eax
  bool v14; // cl
  std__Tree_node *v15; // ecx
  std__Tree_node *v16; // ST00_4
  std__tree *v17; // esi
  std__Tree_node *v18; // ST00_4
  unsigned int v19; // eax
  void *v20; // ecx
  int result; // eax
  _BYTE *v22; // [esp+Ch] [ebp-8h]
  std__tree *v23; // [esp+10h] [ebp-4h]

  v3 = a3;
  v23 = this;
  sub_F94CE0(&a3);
  if ( (*v3)->_IsNil )
  {
    v4 = v3[2];
LABEL_6:
    v6 = v3[1];
    if ( !v4->_IsNil )
      v4->_Parent = v6;
    v7 = v23;
    if ( v23->_Mypair._Myval2._Myhead->_Parent == v3 )
    {
      v23->_Mypair._Myval2._Myhead->_Parent = v4;
    }
    else if ( v6->_Left == v3 )
    {
      v6->_Left = v4;
    }
    else
    {
      v6->_Right = v4;
    }
    v8 = v23->_Mypair._Myval2._Myhead;
    if ( v23->_Mypair._Myval2._Myhead->_Left == v3 )
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
        v8 = v23->_Mypair._Myval2._Myhead;
      }
      v8->_Left = v9;
    }
    if ( v23->_Mypair._Myval2._Myhead->_Right == v3 )
    {
      if ( v4->_IsNil )
      {
        v23->_Mypair._Myval2._Myhead->_Right = v6;
      }
      else
      {
        v11 = v4->_Right;
        for ( i = v4; !v11->_IsNil; v11 = v11->_Right )
          i = v11;
        v23->_Mypair._Myval2._Myhead->_Right = i;
      }
    }
    goto LABEL_37;
  }
  if ( v3[2]->_IsNil )
  {
    v4 = *v3;
    goto LABEL_6;
  }
  v5 = a3;
  v22 = a3;
  v4 = *(a3 + 2);
  if ( a3 == v3 )
    goto LABEL_6;
  (*v3)->_Parent = a3;
  v5->_Left = *v3;
  if ( v5 == v3[2] )
  {
    v6 = v5;
  }
  else
  {
    v6 = v5->_Parent;
    if ( !v4->_IsNil )
      v4->_Parent = v6;
    v6->_Left = v4;
    v5->_Right = v3[2];
    v3[2]->_Parent = v5;
  }
  if ( v23->_Mypair._Myval2._Myhead->_Parent == v3 )
  {
    v23->_Mypair._Myval2._Myhead->_Parent = v5;
  }
  else
  {
    v13 = v3[1];
    if ( *v13 == v3 )
      *v13 = v5;
    else
      v13[2] = v5;
  }
  v5->_Parent = v3[1];
  v14 = v5->_Color;
  v22[12] = *(v3 + 12);
  v7 = v23;
  *(v3 + 12) = v14;
LABEL_37:
  if ( *(v3 + 12) == 1 )
  {
    for ( ; v4 != v7->_Mypair._Myval2._Myhead->_Parent; v6 = v6->_Parent )
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
          sub_FF54B0(v7, v6);
          v15 = v6->_Right;
          v7 = v23;
        }
        if ( v15->_IsNil )
          goto LABEL_55;
        if ( v15->_Left->_Color != 1 || v15->_Right->_Color != 1 )
        {
          if ( v15->_Right->_Color == 1 )
          {
            v15->_Left->_Color = 1;
            v15->_Color = 0;
            sub_1002BB0(v7, v15);
            v15 = v6->_Right;
          }
          v15->_Color = v6->_Color;
          v6->_Color = 1;
          v16 = v6;
          v17 = v23;
          v15->_Right->_Color = 1;
          sub_FF54B0(v23, v16);
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
          sub_1002BB0(v7, v6);
          v15 = v6->_Left;
          v7 = v23;
        }
        if ( v15->_IsNil )
          goto LABEL_55;
        if ( v15->_Right->_Color != 1 || v15->_Left->_Color != 1 )
        {
          if ( v15->_Left->_Color == 1 )
          {
            v15->_Right->_Color = 1;
            v15->_Color = 0;
            sub_FF54B0(v7, v15);
            v15 = v6->_Left;
          }
          v15->_Color = v6->_Color;
          v6->_Color = 1;
          v18 = v6;
          v17 = v23;
          v15->_Left->_Color = 1;
          sub_1002BB0(v23, v18);
          v4->_Color = 1;
          goto LABEL_61;
        }
      }
      v15->_Color = 0;
LABEL_55:
      v4 = v6;
    }
    v17 = v23;
    v4->_Color = 1;
  }
  else
  {
    v17 = v23;
  }
LABEL_61:
  if ( v3[5] )
  {
    j__free(v3[5]);
    v3[5] = 0;
    v3[6] = 0;
    v3[7] = 0;
  }
  j__free(v3);
  v19 = v17->_Mypair._Myval2._Mysize;
  v20 = a3;
  if ( v19 )
    v17->_Mypair._Myval2._Mysize = v19 - 1;
  result = a2;
  *a2 = v20;
  return result;
}

//----- (00F97560) --------------------------------------------------------
CSystemProcessInfoMapNode **__thiscall sub_F97560(CSystemProcessInfoMap *this, CSystemProcessInfoMapNode **a2, CSystemProcessInfoMapNode *a3, CSystemProcessInfoMapNode *a4)
{
  CSystemProcessInfoMapNode *v4; // eax
  CSystemProcessInfoMap *v5; // esi
  CSystemProcessInfoMapNode *v6; // ecx
  CSystemProcessInfoMapNode **v7; // eax
  CSystemProcessInfoMapNode *v8; // ecx
  CSystemProcessInfoMapNode **result; // eax
  CSystemProcessInfoMapNode *v10; // ecx
  CSystemProcessInfoMapNode *i; // edx
  CSystemProcessInfoMapNode *v12; // eax
  char v13; // [esp+4h] [ebp-4h]

  v4 = a3;
  v5 = this;
  v6 = this->_Header;
  if ( a3 != v6->baseclass._Left || a4 != v6 )
  {
    for ( ; a3 != a4; v4 = a3 )
    {
      v10 = v4;
      if ( !v4->baseclass._isnil )
      {
        i = v4->baseclass._Right;
        if ( i->baseclass._isnil )
        {
          for ( i = v4->baseclass._Parent; !i->baseclass._isnil; i = i->baseclass._Parent )
          {
            if ( v4 != i->baseclass._Right )
              break;
            v4 = i;
          }
        }
        else
        {
          v12 = i->baseclass._Left;
          if ( !i->baseclass._Left->baseclass._isnil )
          {
            do
            {
              i = v12;
              v12 = v12->baseclass._Left;
            }
            while ( !v12->baseclass._isnil );
          }
        }
        a3 = i;
      }
      sub_F97620(v5, &v13, v10);
    }
    *a2 = v4;
    result = a2;
  }
  else
  {
    sub_F96DC0(v6->baseclass._Parent);
    v5->_Header->_Parent = v5->_Header;
    v5->_Header->_Left = v5->_Header;
    v5->_Header->_Right = v5->_Header;
    v7 = v5->_Header;
    v5->_Size = 0;
    v8 = *v7;
    result = a2;
    *a2 = v8;
  }
  return result;
}

//----- (00F97620) --------------------------------------------------------
CSystemProcessInfoMapNode **__thiscall sub_F97620(CSystemProcessInfoMap *this, CSystemProcessInfoMapNode **a2, CSystemProcessInfoMapNode *a3)
{
  std__tree *v3; // ebx
  CSystemProcessInfoMapNode *v4; // ecx
  CSystemProcessInfoMapNode *v5; // edi
  CSystemProcessInfoMapNode *v6; // edx
  std__Tree_node *v7; // esi
  std__Tree_node *v8; // eax
  std__Tree_node *v9; // edx
  CSystemProcessInfoMapNode *v10; // eax
  CSystemProcessInfoMapNode *v11; // eax
  CSystemProcessInfoMapNode *i; // edx
  CSystemProcessInfoMapNode *v13; // eax
  char v14; // cl
  std__Tree_node *v15; // ecx
  unsigned int v16; // eax
  CSystemProcessInfoMapNode *v17; // ecx
  CSystemProcessInfoMapNode **result; // eax
  CSystemProcessInfoMapNode *v19; // [esp+10h] [ebp-4h]

  v3 = this;
  v19 = a3;
  sub_F94CE0(&a3);
  v4 = v19;
  if ( v19->baseclass._Left->baseclass._isnil )
  {
    v5 = v19->baseclass._Right;
  }
  else if ( v19->baseclass._Right->baseclass._isnil )
  {
    v5 = v19->baseclass._Left;
  }
  else
  {
    v6 = a3;
    v5 = a3->baseclass._Right;
    if ( a3 != v19 )
    {
      v19->baseclass._Left->baseclass._Parent = a3;
      v6->baseclass._Left = v19->baseclass._Left;
      if ( v6 == v19->baseclass._Right )
      {
        v7 = v6;
      }
      else
      {
        v7 = v6->baseclass._Parent;
        if ( !v5->baseclass._isnil )
          v5->baseclass._Parent = v7;
        v7->_Left = v5;
        v6->baseclass._Right = v19->baseclass._Right;
        v19->baseclass._Right->baseclass._Parent = v6;
      }
      if ( v3->_Mypair._Myval2._Myhead->_Parent == v19 )
      {
        v3->_Mypair._Myval2._Myhead->_Parent = v6;
      }
      else
      {
        v13 = v19->baseclass._Parent;
        if ( v13->baseclass._Left == v19 )
          v13->baseclass._Left = v6;
        else
          v13->baseclass._Right = v6;
      }
      v6->baseclass._Parent = v19->baseclass._Parent;
      v14 = v6->baseclass._Color;
      v6->baseclass._Color = v19->baseclass._Color;
      v19->baseclass._Color = v14;
      v4 = v19;
      goto LABEL_37;
    }
  }
  v7 = v19->baseclass._Parent;
  if ( !v5->baseclass._isnil )
    v5->baseclass._Parent = v7;
  if ( v3->_Mypair._Myval2._Myhead->_Parent == v19 )
  {
    v3->_Mypair._Myval2._Myhead->_Parent = v5;
  }
  else if ( v7->_Left == v19 )
  {
    v7->_Left = v5;
  }
  else
  {
    v7->_Right = v5;
  }
  v8 = v3->_Mypair._Myval2._Myhead;
  if ( v3->_Mypair._Myval2._Myhead->_Left == v19 )
  {
    if ( v5->baseclass._isnil )
    {
      v9 = v7;
    }
    else
    {
      v10 = v5->baseclass._Left;
      v9 = v5;
      if ( !v5->baseclass._Left->baseclass._isnil )
      {
        do
        {
          v9 = v10;
          v10 = v10->baseclass._Left;
        }
        while ( !v10->baseclass._isnil );
      }
      v8 = v3->_Mypair._Myval2._Myhead;
    }
    v8->_Left = v9;
  }
  if ( v3->_Mypair._Myval2._Myhead->_Right == v19 )
  {
    if ( v5->baseclass._isnil )
    {
      v3->_Mypair._Myval2._Myhead->_Right = v7;
    }
    else
    {
      v11 = v5->baseclass._Right;
      for ( i = v5; !v11->baseclass._isnil; v11 = v11->baseclass._Right )
        i = v11;
      v3->_Mypair._Myval2._Myhead->_Right = i;
    }
  }
LABEL_37:
  if ( v4->baseclass._Color != 1 )
    goto LABEL_62;
  if ( v5 == v3->_Mypair._Myval2._Myhead->_Parent )
    goto LABEL_61;
  while ( v5->baseclass._Color == 1 )
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
  v4 = v19;
LABEL_61:
  v5->baseclass._Color = 1;
LABEL_62:
  free(v4->_Keyvalue._Key);
  j__free(v19);
  v16 = v3->_Mypair._Myval2._Mysize;
  v17 = a3;
  if ( v16 )
    v3->_Mypair._Myval2._Mysize = v16 - 1;
  result = a2;
  *a2 = v17;
  return result;
}

//----- (00F97890) --------------------------------------------------------
_DWORD *__thiscall sub_F97890(_DWORD *this, unsigned int a2, unsigned int a3)
{
  _DWORD *v3; // esi
  unsigned int v4; // edi
  bool v5; // cf
  _DWORD *result; // eax
  _DWORD *v7; // eax
  unsigned int v8; // edi

  v3 = this;
  v4 = this[4];
  if ( v4 < a2 )
    std::_Xout_of_range("invalid string position");
  if ( v4 - a2 > a3 )
  {
    if ( a3 )
    {
      if ( this[5] < 0x10u )
        v7 = this;
      else
        v7 = *this;
      v8 = v4 - a3;
      if ( v8 != a2 )
        memmove(v7 + a2, v7 + a2 + a3, v8 - a2);
      v5 = v3[5] < 0x10u;
      v3[4] = v8;
      if ( !v5 )
      {
        *(*v3 + v8) = 0;
        return v3;
      }
      *(v3 + v8) = 0;
    }
    result = v3;
  }
  else
  {
    v5 = this[5] < 0x10u;
    this[4] = a2;
    if ( v5 )
    {
      result = this;
      *(this + a2) = 0;
    }
    else
    {
      *(*this + a2) = 0;
      result = this;
    }
  }
  return result;
}

//----- (00F97930) --------------------------------------------------------
int __stdcall std::_Generic_error_category_message(int a1, int a2)
{
  int v2; // eax
  char *v3; // edx

  v2 = sub_100465F(a2);
  v3 = "unknown error";
  if ( v2 )
    v3 = v2;
  *(a1 + 20) = 15;
  *(a1 + 16) = 0;
  *a1 = 0;
  if ( *v3 )
    sub_F97030(a1, v3, strlen(v3));
  else
    sub_F97030(a1, v3, 0);
  return a1;
}

//----- (00F979A0) --------------------------------------------------------
int __stdcall std::_Iostream_error_category_message(int a1, int a2)
{
  if ( a2 == 1 )
  {
    *(a1 + 20) = 15;
    *(a1 + 16) = 0;
    *a1 = 0;
    sub_F97030(a1, "iostream stream error", 0x15u);
  }
  else
  {
    std::_Generic_error_category_message(a1, a2);
  }
  return a1;
}

//----- (00F979F0) --------------------------------------------------------
int __stdcall std::_System_error_category_message(int a1, int a2)
{
  int v2; // eax
  char *v3; // edx

  v2 = sub_1004689(a2);
  v3 = "unknown error";
  if ( v2 )
    v3 = v2;
  *(a1 + 20) = 15;
  *(a1 + 16) = 0;
  *a1 = 0;
  if ( *v3 )
    sub_F97030(a1, v3, strlen(v3));
  else
    sub_F97030(a1, v3, 0);
  return a1;
}

//----- (00F97A60) --------------------------------------------------------
const char *std::_Generic_error_category_name()
{
  return "generic";
}

//----- (00F97A70) --------------------------------------------------------
const char *std::_Iostream_error_category_name()
{
  return "iostream";
}

//----- (00F97A80) --------------------------------------------------------
const char *std::_System_error_category_name()
{
  return "system";
}

//----- (00F97AA0) --------------------------------------------------------
int swprintf(wchar_t *pszBuffer, const wchar_t *lpszFormat, ...)
{
  va_list ArgList; // [esp+10h] [ebp+10h]

  va_start(ArgList, lpszFormat);
  return vswprintf_s(pszBuffer, MAX_PATH, lpszFormat, ArgList);
}

//----- (00F97AC0) --------------------------------------------------------
EventItem *__thiscall tagEventItem::tagEventItem(EventItem *this, const GUID *a2, __int16 a3, __int16 a4, char a5)
{
  EventItem *v5; // edi
  __m128i v6; // xmm0
  EventItem *result; // eax

  v5 = this;
  this->strEventTrace.m_Data = 0;
  this->List._Myheader = 0;
  this->List._Mysize = 0;
  this->List._Myheader = std::_List_alloc<std::_List_base_types<tagEventItem *,std::allocator<tagEventItem *>>>::_Buynode0(
                           0,
                           0);
  v5->strHeader.m_Data = 0;
  v6 = _mm_loadu_si128(a2);
  v5->Type = a3;
  v5->Level = a5;
  v5->Version = a4;
  result = v5;
  _mm_storeu_si128(&v5->guid, v6);
  v5->field_4 = 0;
  return result;
}

//----- (00F97B60) --------------------------------------------------------
_DWORD **__cdecl sub_F97B60(int a1, OLECHAR *psz, int a3, int a4)
{
  _DWORD **result; // eax
  _DWORD *i; // esi
  int v6; // ebx
  _bstr_t *v7; // eax
  _bstr_t *v8; // edi
  int v9; // edi
  int v10; // ebx
  _DWORD *v11; // edx
  int v12; // eax
  void *v13; // [esp+10h] [ebp-10h]
  int v14; // [esp+1Ch] [ebp-4h]

  result = *a1;
  for ( i = **a1; i != *a1; i = *i )
  {
    v6 = i[2];
    v7 = operator new(0x10u);
    v8 = v7;
    v13 = v7;
    v14 = 0;
    if ( v7 )
    {
      _bstr_t::_bstr_t(v7, psz);
      v8[2].m_Data = a3;
      v8[1].m_Data = -1;
      v8[3].m_Data = a4;
    }
    else
    {
      v8 = 0;
    }
    v13 = v8;
    v9 = v6 + 24;
    v14 = -1;
    v10 = *(v6 + 24);
    v11 = std::_List_buy<tagEventItem *,std::allocator<tagEventItem *>>::_Buynode<tagEventItem * const &>(
            v10,
            *(v10 + 4),
            &v13);
    v12 = *(v9 + 4);
    if ( (357913940 - v12) < 1 )
      std::_Xlength_error("list<T> too long");
    *(v9 + 4) = v12 + 1;
    *(v10 + 4) = v11;
    *v11[1] = v11;
    result = a1;
  }
  return result;
}

//----- (00F97C40) --------------------------------------------------------
int *__thiscall sub_F97C40(char *this, _DWORD **a2)
{
  int ***v2; // edi
  int **v3; // esi
  char *v4; // ebx
  _DWORD *v5; // edx
  int v6; // eax
  int *result; // eax
  int **v8; // esi
  EventList *v9; // [esp+8h] [ebp-4h]

  v2 = a2;
  v3 = **a2;
  if ( v3 != *a2 )
  {
    v4 = this + 4;
    do
    {
      a2 = v3[2];
      v9 = *v4;
      v5 = std::_List_buy<tagEventItem *,std::allocator<tagEventItem *>>::_Buynode<tagEventItem * const &>(
             *v4,
             *(*v4 + 4),
             &a2);
      v6 = *(v4 + 1);
      if ( (357913940 - v6) < 1 )
        std::_Xlength_error("list<T> too long");
      *(v4 + 1) = v6 + 1;
      v9->_Mysize = v5;
      *v5[1] = v5;
      v3 = *v3;
    }
    while ( v3 != *v2 );
  }
  result = **v2;
  **v2 = *v2;
  (*v2)[1] = *v2;
  v2[1] = 0;
  if ( result != *v2 )
  {
    do
    {
      v8 = *result;
      j__free(result);
      result = v8;
    }
    while ( v8 != *v2 );
  }
  return result;
}

//----- (00F97CE0) --------------------------------------------------------
LONG __cdecl sub_F97CE0(int a1)
{
  LONG v1; // ebx
  OLECHAR *v2; // edi
  int v3; // esi
  VARIANTARG pvarg; // [esp+8h] [ebp-10h]

  v1 = 1;
  if ( a1 )
  {
    v2 = SysAllocString(L"MAX");
    VariantInit(&pvarg);
    v3 = (*(*a1 + 12))(a1, v2, 0, &pvarg, 0);
    SysFreeString(v2);
    if ( !v3 && pvarg.vt == 3 )
      v1 = pvarg.lVal;
    VariantClear(&pvarg);
  }
  return v1;
}

//----- (00F97D50) --------------------------------------------------------
_bstr_t *__thiscall QueryEventTraceName(tagWbemServicesList *ppWbemServices, GUID *pIID, WORD bVersion, BYTE cLevel, WORD aType)
{
  tagWbemServicesList *pWbemServices_1; // ebx
  OLECHAR *v6; // edi
  tagWbemServicesList *pWbemServices_2; // esi
  OLECHAR *bstrTrace; // edi
  OLECHAR *bstrVersion; // eax
  IWbemServices *v10; // ecx
  int hresult; // esi
  const WCHAR *bstrClass_1; // edi
  OLECHAR *bstrRealName; // esi
  IWbemClassObject *v14; // ecx
  int hres; // esi
  SHORT v16; // si
  _bstr_t *v17; // eax
  VARIANTARG vtValue; // [esp+Ch] [ebp-480h]
  VARIANTARG vtValue_1; // [esp+1Ch] [ebp-470h]
  int v21; // [esp+2Ch] [ebp-460h]
  VARIANTARG vtVersion; // [esp+30h] [ebp-45Ch]
  char a5a[4]; // [esp+40h] [ebp-44Ch]
  BSTR bstrVersion_1; // [esp+44h] [ebp-448h]
  GUID *iid; // [esp+48h] [ebp-444h]
  BSTR bstrGuid; // [esp+4Ch] [ebp-440h]
  int uReturned; // [esp+50h] [ebp-43Ch]
  const WCHAR *bstrClass; // [esp+54h] [ebp-438h]
  _bstr_t *v29; // [esp+58h] [ebp-434h]
  int uRet; // [esp+5Ch] [ebp-430h]
  IWbemClassObject *pClassObject1; // [esp+60h] [ebp-42Ch]
  tagWbemServicesList *pWbemServices1; // [esp+64h] [ebp-428h]
  IWbemQualifierSet *pQualifierSet; // [esp+68h] [ebp-424h]
  IWbemClassObject *pClassObject2; // [esp+6Ch] [ebp-420h]
  IEnumWbemClassObject *pEnum; // [esp+70h] [ebp-41Ch]
  IEnumWbemClassObject *pEnum2; // [esp+74h] [ebp-418h]
  wchar_t szGuid[260]; // [esp+78h] [ebp-414h]
  WCHAR szQualifierValue[260]; // [esp+280h] [ebp-20Ch]

  iid = pIID;
  pWbemServices_1 = ppWbemServices;
  v21 = bVersion;
  a5a[0] = cLevel;
  v6 = 0;
  pWbemServices1 = ppWbemServices;
  pEnum = 0;
  pEnum2 = 0;
  pClassObject1 = 0;
  pClassObject2 = 0;
  pQualifierSet = 0;
  bstrGuid = 0;
  bstrVersion_1 = 0;
  v29 = 0;
  VariantInit(&vtValue_1);
  VariantInit(&vtValue);
  VariantInit(&vtVersion);
  pWbemServices_2 = pWbemServices1;
  if ( !pWbemServices_1->pService && SetProxyAccessRight(pWbemServices1) )
    goto __quit;
  swprintf_s(
    szGuid,
    0x104u,
    L"{%08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x}",
    iid->Data1,
    iid->Data2,
    iid->Data3,
    iid->Data4[0],
    iid->Data4[1],
    iid->Data4[2],
    iid->Data4[3],
    iid->Data4[4],
    iid->Data4[5],
    iid->Data4[6],
    iid->Data4[7]);
  bstrTrace = SysAllocString(L"EventTrace");
  bstrClass = SysAllocString(L"__CLASS");
  bstrGuid = SysAllocString(L"Guid");
  bstrVersion = SysAllocString(L"EventVersion");
  v10 = pWbemServices_2->pService;
  bstrVersion_1 = bstrVersion;
  pEnum = 0;
  hresult = v10->lpVtbl->CreateClassEnum(v10, bstrTrace, 0x20001, 0, &pEnum);// WBEM_FLAG_USE_AMENDED_QUALIFIERS| WBEM_FLAG_SHALLOW
  SysFreeString(bstrTrace);
  if ( hresult )
    goto __cleanup;
  uReturned = 1;
  do
  {
    pClassObject1 = 0;
    if ( pEnum->lpVtbl->Next(pEnum, 5000, 1, &pClassObject1, &uReturned) )
      continue;
    if ( uReturned != 1 )
      break;
    bstrClass_1 = bstrClass;
    if ( pClassObject1->lpVtbl->Get(pClassObject1, bstrClass, 0, &vtValue_1, 0, 0) )
      continue;
    bstrRealName = SysAllocString(vtValue_1.bstrVal);
    pEnum2 = 0;
    pWbemServices1->pService->lpVtbl->CreateClassEnum(pWbemServices1->pService, bstrRealName, 0x20001, 0, &pEnum2);
    SysFreeString(bstrRealName);
    VariantClear(&vtValue_1);
    uRet = 1;
    do
    {
      pClassObject2 = 0;
      if ( pEnum2 )
      {
        if ( pEnum2->lpVtbl->Next(pEnum2, 5000, 1, &pClassObject2, &uRet) )
          continue;
        if ( uRet != 1 )
          break;
        v14 = pClassObject2;
      }
      else
      {
        v14 = pClassObject1;
        uRet = 1;
        pClassObject2 = pClassObject1;
      }
      hres = v14->lpVtbl->Get(v14, bstrClass_1, 0, &vtValue_1, 0, 0);
      VariantClear(&vtValue_1);
      if ( !hres )
      {
        if ( pQualifierSet )
        {
          pQualifierSet->lpVtbl->Release(pQualifierSet);
          pQualifierSet = 0;
        }
        pClassObject2->lpVtbl->GetQualifierSet(pClassObject2, &pQualifierSet);
        if ( !pQualifierSet->lpVtbl->Get(pQualifierSet, bstrGuid, 0, &vtValue, 0) )
        {
          wcscpy_s(szQualifierValue, 0x104u, vtValue.bstrVal);
          VariantClear(&vtValue);
          if ( !wcsstr(szQualifierValue, L"{") )
            swprintf(szQualifierValue, L"{%s}", szQualifierValue);
          if ( !_wcsicmp(szGuid, szQualifierValue) )
          {
            if ( pQualifierSet->lpVtbl->Get(pQualifierSet, bstrVersion_1, 0, &vtVersion, 0) )
            {
              v17 = QueryEventTraceNameEx(pWbemServices1, pClassObject2, iid, 0xFFFFu, a5a[0], aType);
            }
            else
            {
              VariantChangeType(&vtVersion, &vtVersion, 0, 2u);
              v16 = vtVersion.iVal;
              VariantClear(&vtVersion);
              if ( v21 != v16 )
                continue;
              v17 = QueryEventTraceNameEx(pWbemServices1, pClassObject2, iid, v21, a5a[0], aType);
            }
            v29 = v17;
            goto LABEL_31;
          }
        }
      }
    }
    while ( uRet == 1 );
    if ( pEnum2 )
    {
      pEnum2->lpVtbl->Release(pEnum2);
      pEnum2 = 0;
    }
  }
  while ( uReturned == 1 );
LABEL_31:
  if ( pEnum )
  {
    pEnum->lpVtbl->Release(pEnum);
    pEnum = 0;
  }
__cleanup:
  v6 = bstrClass;
__quit:
  VariantClear(&vtValue);
  VariantClear(&vtVersion);
  SysFreeString(bstrGuid);
  SysFreeString(v6);
  SysFreeString(bstrVersion_1);
  if ( pEnum )
  {
    pEnum->lpVtbl->Release(pEnum);
    pEnum = 0;
  }
  if ( pEnum2 )
  {
    pEnum2->lpVtbl->Release(pEnum2);
    pEnum2 = 0;
  }
  if ( pQualifierSet )
    pQualifierSet->lpVtbl->Release(pQualifierSet);
  return v29;
}

//----- (00F98250) --------------------------------------------------------
signed int __usercall sub_F98250@<eax>(int a1@<edi>, int a2@<esi>, int a3, int a4)
{
  signed int result; // eax
  int v5; // ST14_4
  OLECHAR *v6; // edi
  int v7; // esi
  OLECHAR *v8; // edi
  int v9; // esi
  OLECHAR *v10; // edi
  int v11; // esi
  signed int v12; // eax
  OLECHAR *v13; // edi
  int v14; // esi
  signed int v15; // esi
  signed int v16; // [esp+4h] [ebp-A8h]
  VARIANTARG pvarg; // [esp+8h] [ebp-A4h]
  unsigned __int8 v18; // [esp+1Bh] [ebp-91h]
  wchar_t v19; // [esp+1Ch] [ebp-90h]
  wchar_t v20; // [esp+58h] [ebp-54h]
  wchar_t Dst; // [esp+94h] [ebp-18h]

  v18 = 0;
  Dst = 0;
  v19 = 0;
  v20 = 0;
  if ( !a4 )
    return 29;
  v5 = a1;
  v6 = SysAllocString(L"format");
  VariantInit(&pvarg);
  v7 = (*(*a4 + 12))(a4, v6, 0, &pvarg, 0, v5, a2);
  SysFreeString(v6);
  if ( !v7 && pvarg.lVal )
    wcscpy_s(&Dst, 0xAu, pvarg.bstrVal);
  v8 = SysAllocString(L"StringTermination");
  VariantClear(&pvarg);
  v9 = (*(*a4 + 12))(a4, v8, 0, &pvarg, 0);
  SysFreeString(v8);
  if ( !v9 && pvarg.lVal )
    wcscpy_s(&v19, 0x1Eu, pvarg.bstrVal);
  v10 = SysAllocString(L"pointer");
  VariantClear(&pvarg);
  v11 = (*(*a4 + 12))(a4, v10, 0);
  SysFreeString(v10);
  v12 = v18;
  if ( !v11 )
    v12 = 1;
  v16 = v12;
  v13 = SysAllocString(L"extension");
  VariantClear(&pvarg);
  v14 = (*(*a4 + 12))(a4, v13, 0, &pvarg, 0);
  SysFreeString(v13);
  if ( !v14 && pvarg.lVal )
    wcscpy_s(&v20, 0x1Eu, pvarg.bstrVal);
  VariantClear(&pvarg);
  switch ( a3 & 0xFFFFDFFF )
  {
    case 2u:
      v15 = 4;
      goto LABEL_52;
    case 3u:
      goto LABEL_20;
    case 4u:
      v15 = 11;
      goto LABEL_52;
    case 5u:
      v15 = 12;
      goto LABEL_52;
    case 8u:
      if ( _wcsicmp(&v19, L"NullTerminated") )
      {
        if ( _wcsicmp(&v19, L"Counted") )
        {
          if ( _wcsicmp(&v19, L"ReverseCounted") )
            v15 = _wcsicmp(&v19, L"NotCounted") != 0 ? 13 : 23;
          else
            v15 = 18 - (_wcsicmp(&Dst, L"w") != 0);
        }
        else
        {
          v15 = 16 - (_wcsicmp(&Dst, L"w") != 0);
        }
      }
      else
      {
        v15 = 14 - (_wcsicmp(&Dst, L"w") != 0);
      }
      goto LABEL_52;
    case 0xBu:
      v15 = 26;
      goto LABEL_52;
    case 0xDu:
      if ( !_wcsicmp(&v20, L"Port") )
      {
        v15 = 21;
        goto LABEL_52;
      }
      if ( !_wcsicmp(&v20, L"IPAddr") )
        goto LABEL_47;
      if ( _wcsicmp(&v20, L"Sid") )
      {
        if ( _wcsicmp(&v20, L"Guid") )
        {
          if ( !_wcsicmp(&v20, L"SizeT") )
          {
LABEL_20:
            v15 = 6;
            goto LABEL_52;
          }
          if ( _wcsicmp(&v20, L"IPAddrV6") )
          {
            if ( _wcsicmp(&v20, L"IPAddrV4") )
            {
              if ( _wcsicmp(&v20, L"WmiTime") )
                v15 = v16;
              else
                v15 = 28;
            }
            else
            {
LABEL_47:
              v15 = 20;
            }
          }
          else
          {
            v15 = 27;
          }
        }
        else
        {
          v15 = 25;
        }
      }
      else
      {
        v15 = 19;
      }
LABEL_52:
      if ( v16 )
        v15 = 24;
      result = v15;
      break;
    case 0x10u:
      v15 = 3;
      if ( !_wcsicmp(&Dst, L"c") )
        v15 = 0;
      goto LABEL_52;
    case 0x11u:
      v15 = 2;
      goto LABEL_52;
    case 0x12u:
      v15 = 5;
      goto LABEL_52;
    case 0x13u:
      v15 = 7;
      if ( !_wcsicmp(&Dst, L"x") )
        v15 = 8;
      goto LABEL_52;
    case 0x14u:
      v15 = 9;
      goto LABEL_52;
    case 0x15u:
      v15 = 10;
      goto LABEL_52;
    case 0x67u:
      v15 = 1;
      goto LABEL_52;
    default:
      v15 = 29;
      goto LABEL_52;
  }
  return result;
}
// F98250: could not find valid save-restore pair for edi
// F98250: could not find valid save-restore pair for esi

//----- (00F98730) --------------------------------------------------------
_bstr_t *__thiscall sub_F98730(tagWbemServicesList *pWbemServicesList, GUID *pIID, int Type, int Version, int Level)
{
  tagWbemServicesList *pWbemServicesList_1; // ebx
  EventItem *v6; // eax
  EventItem *pItem; // esi
  std__list_node *v8; // edi
  std__list_node *v9; // eax
  unsigned int v10; // edx
  std__list_node *_Myhead; // ecx
  GUID *IID; // ebx
  std__list_node *v13; // eax
  char *pValue; // esi
  GUID *v15; // edi
  _DWORD *v16; // esi
  unsigned int v17; // ebx
  bool v18; // cf
  _bstr_t *v19; // ebx
  signed __int16 v20; // dx
  __int16 v21; // si
  _bstr_t *v22; // edx
  _bstr_t *result; // eax
  EventItem *v24; // eax
  EventItem *v25; // esi
  std__list_node *v26; // edi
  std__list_node *v27; // ecx
  unsigned int v28; // eax
  tagWbemServicesList *pWbemServicesList_2; // [esp+10h] [ebp-1Ch]
  signed __int16 v30; // [esp+14h] [ebp-18h]
  int a3; // [esp+18h] [ebp-14h]
  _bstr_t *v32; // [esp+1Ch] [ebp-10h]
  int v33; // [esp+28h] [ebp-4h]

  pWbemServicesList_1 = pWbemServicesList;
  pWbemServicesList_2 = pWbemServicesList;
  v32 = 0;
  v30 = 0;
  if ( !pWbemServicesList->EventItemList._Mypair._Myval2._Mysize )
  {
    v6 = operator new(0x2Cu);
    a3 = v6;
    v33 = 0;
    pItem = v6 ? tagEventItem::tagEventItem(v6, &GUID_PROCEXP_EVENT, -1, 0, 0) : 0;
    v33 = -1;
    a3 = pItem;
    if ( pItem )
    {
      _bstr_t::operator=(pItem, L"EventTrace");
      _bstr_t::operator=((pItem + 32), L"Header");
      v8 = pWbemServicesList_1->EventItemList._Mypair._Myval2._Myhead;
      v9 = std::_List_buy<tagEventItem *,std::allocator<tagEventItem *>>::_Buynode<tagEventItem * const &>(
             pWbemServicesList_1->EventItemList._Mypair._Myval2._Myhead,
             &v8->_Prev->_Next,
             &a3);
      v10 = pWbemServicesList_1->EventItemList._Mypair._Myval2._Mysize;
      if ( 357913940 - v10 < 1 )
        std::_Xlength_error("list<T> too long");
      pWbemServicesList_1->EventItemList._Mypair._Myval2._Mysize = v10 + 1;
      v8->_Prev = v9;
      v9->_Prev->_Next = v9;
    }
  }
  _Myhead = pWbemServicesList_1->EventItemList._Mypair._Myval2._Myhead;
  IID = pIID;
  v13 = _Myhead->_Next;
  if ( _Myhead->_Next == _Myhead )
    goto LABEL_30;
  while ( 2 )
  {
    pValue = v13->_Myval;
    v15 = IID;
    a3 = 0;
    v16 = pValue + 8;
    v17 = 12;
    while ( *v16 == v15->Data1 )
    {
      ++v16;
      v15 = (v15 + 4);
      v18 = v17 < 4;
      v17 -= 4;
      if ( v18 )
      {
        v19 = v13->_Myval;
        v20 = a3;
        v21 = v19[9].m_Data;
        if ( v21 == Type )
          v20 = 1;
        if ( HIWORD(v19[9].m_Data) == Version )
          ++v20;
        if ( v20 == 2 )
          return v13->_Myval;
        if ( v20 <= v30 )
        {
          v22 = v32;
        }
        else
        {
          v30 = v20;
          v22 = v13->_Myval;
          v32 = v13->_Myval;
        }
        if ( v21 == -1 )
        {
          if ( !v22 )
            v22 = v19;
          v32 = v22;
        }
        break;
      }
    }
    v13 = v13->_Next;
    if ( v13 != _Myhead )
    {
      IID = pIID;
      continue;
    }
    break;
  }
  result = v32;
  if ( !v32 )
  {
    IID = pIID;
LABEL_30:
    result = QueryEventTraceName(pWbemServicesList_2, IID, Version, Level, Type);
    if ( !result )
    {
      v24 = operator new(0x2Cu);
      v33 = 1;
      if ( v24 )
        v25 = tagEventItem::tagEventItem(v24, IID, Type, Version, Level);
      else
        v25 = 0;
      v33 = -1;
      a3 = v25;
      if ( v25 )
      {
        _bstr_t::operator=(v25, L"Unknown");
        v26 = pWbemServicesList_2->EventItemList._Mypair._Myval2._Myhead;
        v27 = std::_List_buy<tagEventItem *,std::allocator<tagEventItem *>>::_Buynode<tagEventItem * const &>(
                pWbemServicesList_2->EventItemList._Mypair._Myval2._Myhead,
                &v26->_Prev->_Next,
                &a3);
        v28 = pWbemServicesList_2->EventItemList._Mypair._Myval2._Mysize;
        if ( 357913940 - v28 < 1 )
          std::_Xlength_error("list<T> too long");
        pWbemServicesList_2->EventItemList._Mypair._Myval2._Mysize = v28 + 1;
        v26->_Prev = v27;
        v27->_Prev->_Next = v27;
      }
      result = &v25->strEventTrace;
    }
  }
  return result;
}

//----- (00F98970) --------------------------------------------------------
_bstr_t *__thiscall QueryEventTraceNameEx(tagWbemServicesList *this, IEnumWbemClassObject *pClassObject_1, const GUID *a3, unsigned __int16 Version, char Level, __int16 Type)
{
  _bstr_t *v6; // ebx
  EventList *v7; // edi
  EventItem *v8; // eax
  EventItem *v9; // eax
  _DWORD *v10; // STE4_4
  _DWORD *v11; // eax
  OLECHAR *v12; // edi
  HRESULT v13; // esi
  HRESULT (__stdcall *v14)(SAFEARRAY *); // esi
  HRESULT (__stdcall *v15)(SAFEARRAY *, LONG *, void *); // ebx
  SAFEARRAY *v16; // ebx
  SAFEARRAY *v17; // esi
  int v18; // ecx
  int v19; // edi
  EventItem *v20; // eax
  EventItem *v21; // esi
  _bstr_t *v22; // eax
  LONG v23; // ecx
  SAFEARRAY *v24; // STE8_4
  __int16 v25; // di
  EventItem *v26; // eax
  EventItem *v27; // esi
  _bstr_t *v28; // ebx
  _bstr_t *v29; // eax
  int v30; // edi
  int v31; // eax
  _DWORD *v32; // edi
  _DWORD *v33; // eax
  _DWORD *v34; // esi
  VARIANTARG v36; // [esp+10h] [ebp-4E0h]
  LONG v37; // [esp+20h] [ebp-4D0h]
  LONG plLbound; // [esp+24h] [ebp-4CCh]
  void *ppvData; // [esp+28h] [ebp-4C8h]
  LONG v40; // [esp+2Ch] [ebp-4C4h]
  void *v41; // [esp+30h] [ebp-4C0h]
  VARIANTARG pvarg; // [esp+34h] [ebp-4BCh]
  VARIANTARG pvargDest; // [esp+44h] [ebp-4ACh]
  VARIANTARG vtClassName; // [esp+54h] [ebp-49Ch]
  IEnumWbemClassObject *pEnum; // [esp+64h] [ebp-48Ch]
  __int16 a4a[2]; // [esp+68h] [ebp-488h]
  BSTR bstrDisplyName; // [esp+6Ch] [ebp-484h]
  BSTR bstrClass; // [esp+70h] [ebp-480h]
  BSTR bstrEventType; // [esp+74h] [ebp-47Ch]
  char a5a[4]; // [esp+78h] [ebp-478h]
  int v51; // [esp+7Ch] [ebp-474h]
  LONG v52; // [esp+80h] [ebp-470h]
  LONG v53; // [esp+84h] [ebp-46Ch]
  int v54; // [esp+88h] [ebp-468h]
  BSTR bstrDataId; // [esp+8Ch] [ebp-464h]
  BSTR bstrTypeName; // [esp+90h] [ebp-460h]
  GUID *a2a; // [esp+94h] [ebp-45Ch]
  tagWbemServicesList *ppWbemServices; // [esp+98h] [ebp-458h]
  void *v59; // [esp+9Ch] [ebp-454h]
  LONG plUbound; // [esp+A0h] [ebp-450h]
  IWbemClassObject *pClassObject; // [esp+A4h] [ebp-44Ch]
  OLECHAR *pv; // [esp+A8h] [ebp-448h]
  void *theList; // [esp+ACh] [ebp-444h]
  int v64; // [esp+B0h] [ebp-440h]
  _bstr_t *v65; // [esp+B4h] [ebp-43Ch]
  _bstr_t *v66; // [esp+B8h] [ebp-438h]
  void *v67; // [esp+BCh] [ebp-434h]
  LONG rgIndices; // [esp+C0h] [ebp-430h]
  IEnumWbemClassObject *pNewObject; // [esp+C4h] [ebp-42Ch]
  SAFEARRAY *psa; // [esp+C8h] [ebp-428h]
  IWbemQualifierSet *v71; // [esp+CCh] [ebp-424h]
  __int16 psz[260]; // [esp+D0h] [ebp-420h]
  WCHAR szText[260]; // [esp+2D8h] [ebp-218h]
  int v74; // [esp+4ECh] [ebp-4h]

  ppWbemServices = this;
  pClassObject = pClassObject_1;
  v6 = 0;
  a2a = a3;
  *a4a = Version;
  a5a[0] = Level;
  pEnum = 0;
  pNewObject = 0;
  v71 = 0;
  pv = 0;
  v64 = 0;
  v7 = std::_List_alloc<std::_List_base_types<tagEventItem *,std::allocator<tagEventItem *>>>::_Buynode0(0, 0);
  theList = v7;
  v74 = 0;
  psa = 0;
  VariantInit(&vtClassName);
  VariantInit(&pvargDest);
  VariantInit(&pvarg);
  VariantInit(&v36);
  bstrClass = SysAllocString(L"__CLASS");
  bstrDataId = SysAllocString(L"WmiDataId");
  bstrEventType = SysAllocString(L"EventType");
  bstrTypeName = SysAllocString(L"EventTypeName");
  bstrDisplyName = SysAllocString(L"DisplayName");
  if ( !pClassObject->lpVtbl->Get(pClassObject, bstrClass, 0, &vtClassName, 0, 0) )
  {
    wcscpy_s(szText, 0x104u, vtClassName.bstrVal);
    if ( v71 )
    {
      v71->lpVtbl->Release(v71);
      v71 = 0;
    }
    pClassObject->lpVtbl->GetQualifierSet(pClassObject, &v71);
    if ( !v71->lpVtbl->Get(v71, bstrDisplyName, 0, &v36, 0) && v36.lVal )
      wcscpy_s(szText, 0x104u, v36.bstrVal);
    v8 = operator new(0x2Cu);
    v59 = v8;
    LOBYTE(v74) = 1;
    v9 = v8 ? tagEventItem::tagEventItem(v8, a2a, -1, -1, -1) : 0;
    v66 = &v9->strEventTrace;
    LOBYTE(v74) = 0;
    v67 = v9;
    if ( v9 )
    {
      _bstr_t::operator=(v9, szText);
      v6 = v66;
      v10 = v7->_Mysize;
      v65 = v66;
      v11 = std::_List_buy<tagEventItem *,std::allocator<tagEventItem *>>::_Buynode<tagEventItem * const &>(
              v7,
              v10,
              &v67);
      v64 = 1;
      v7->_Mysize = v11;
      *v11[1] = v11;
      v12 = SysAllocString(vtClassName.bstrVal);
      v13 = ppWbemServices->pService->lpVtbl->CreateClassEnum(ppWbemServices->pService, v12, 0x20001, 0, &pEnum);
      SysFreeString(v12);
      if ( !v13 )
      {
        v14 = SafeArrayDestroy;
        v15 = SafeArrayGetElement;
        v51 = 1;
        while ( 1 )
        {
          pNewObject = 0;
          if ( pEnum->lpVtbl->Next(pEnum, 5000, 1, &pNewObject, &v51) )
          {
            pNewObject = pClassObject;
            pClassObject->lpVtbl->AddRef(pClassObject);
          }
          if ( v71 )
          {
            v71->lpVtbl->Release(v71);
            v71 = 0;
          }
          (pNewObject->lpVtbl->Reset)(pNewObject, &v71);
          VariantClear(&pvargDest);
          if ( !v71->lpVtbl->Get(v71, bstrEventType, 0, &pvargDest, 0) )
          {
            v16 = 0;
            if ( pvargDest.vt & 0x2000 )
            {
              v17 = pvargDest.parray;
              v59 = pvargDest.bstrVal;
              VariantClear(&pvarg);
              if ( !v71->lpVtbl->Get(v71, bstrTypeName, 0, &pvarg, 0) && pvarg.vt & 0x2000 )
                v16 = pvarg.parray;
              if ( !v17
                || SafeArrayGetLBound(v17, 1u, &plLbound)
                || SafeArrayGetUBound(v17, 1u, &plUbound)
                || plUbound < 0 )
              {
LABEL_80:
                v6 = v65;
                break;
              }
              SafeArrayAccessData(v17, &ppvData);
              if ( v16 )
              {
                if ( SafeArrayGetLBound(v16, 1u, &v37) || SafeArrayGetUBound(v16, 1u, &v52) || v52 < 0 )
                  goto LABEL_80;
                SafeArrayAccessData(v16, &v41);
              }
              v18 = plLbound;
              rgIndices = plLbound;
              if ( plLbound <= plUbound )
              {
                while ( 1 )
                {
                  v19 = *(ppvData + v18);
                  v20 = operator new(0x2Cu);
                  v67 = v20;
                  LOBYTE(v74) = 2;
                  if ( v20 )
                    v21 = tagEventItem::tagEventItem(v20, a2a, v19, a4a[0], a5a[0]);
                  else
                    v21 = 0;
                  LOBYTE(v74) = 0;
                  v67 = v21;
                  if ( v21 )
                  {
                    sub_F99380(&theList, &v67);
                    if ( sub_F80440(v66) )
                      sub_F73A50(&v21->strEventTrace, v66);
                    v22 = v65;
                    if ( Type == v19 )
                      v22 = &v21->strEventTrace;
                    v65 = v22;
                    if ( v16 )
                    {
                      v23 = rgIndices;
                      if ( rgIndices < v37 || rgIndices > v52 )
                        goto LABEL_45;
                      _bstr_t::operator=((v21 + 32), *(v41 + rgIndices));
                    }
                  }
                  v23 = rgIndices;
LABEL_45:
                  v18 = v23 + 1;
                  rgIndices = v18;
                  if ( v18 > plUbound )
                  {
                    v17 = v59;
                    break;
                  }
                }
              }
              SafeArrayUnaccessData(v17);
              v24 = v17;
              v14 = SafeArrayDestroy;
              SafeArrayDestroy(v24);
              VariantInit(&pvargDest);
              if ( v16 )
              {
                SafeArrayUnaccessData(v16);
                SafeArrayDestroy(v16);
                VariantInit(&pvarg);
              }
            }
            else
            {
              VariantChangeType(&pvargDest, &pvargDest, 0, 2u);
              v25 = pvargDest.iVal;
              VariantClear(&pvarg);
              if ( v71->lpVtbl->Get(v71, bstrTypeName, 0, &pvarg, 0) )
                psz[0] = 0;
              else
                wcscpy_s(psz, 0x104u, pvarg.bstrVal);
              v26 = operator new(0x2Cu);
              v59 = v26;
              LOBYTE(v74) = 3;
              if ( v26 )
                v27 = tagEventItem::tagEventItem(v26, a2a, v25, a4a[0], a5a[0]);
              else
                v27 = 0;
              LOBYTE(v74) = 0;
              v67 = v27;
              if ( v27 )
              {
                sub_F99380(&theList, &v67);
                v28 = v66;
                if ( sub_F80440(v66) )
                  sub_F73A50(&v27->strEventTrace, v28);
                v29 = v65;
                if ( Type == v25 )
                  v29 = &v27->strEventTrace;
                v65 = v29;
                _bstr_t::operator=((v27 + 32), psz);
              }
              v14 = SafeArrayDestroy;
            }
            v15 = SafeArrayGetElement;
          }
          VariantClear(&vtClassName);
          psa = 0;
          vtClassName.vt = 3;
          v30 = 1;
          for ( vtClassName.lVal = 1;
                !(pNewObject->lpVtbl->Skip)(pNewObject, bstrDataId, 3, &vtClassName, &psa);
                vtClassName.lVal = ++v30 )
          {
            if ( SafeArrayGetLBound(psa, 1u, &v40) || SafeArrayGetUBound(psa, 1u, &v53) || v53 < 0 )
              break;
            rgIndices = v40;
            if ( v40 <= v53 )
            {
              do
              {
                if ( v15(psa, &rgIndices, &pv) || (pNewObject->lpVtbl->Next)(pNewObject, pv, 0, 0, &v54, 0) )
                  break;
                if ( v71 )
                {
                  v71->lpVtbl->Release(v71);
                  v71 = 0;
                }
                if ( (pNewObject->lpVtbl[1].Reset)(pNewObject, pv, &v71) )
                  break;
                v14 = sub_F98250(v30, v14, v54, v71);
                v31 = v54 & 0x2000 ? sub_F97CE0(v71) : 1;
                sub_F97B60(&theList, pv, v14, v31);
                ++rgIndices;
              }
              while ( rgIndices <= v53 );
              v14 = SafeArrayDestroy;
            }
            v14(psa);
            psa = 0;
          }
          sub_F97C40(ppWbemServices, &theList);
          if ( v51 != 1 )
            goto LABEL_80;
        }
      }
    }
  }
  VariantClear(&vtClassName);
  VariantClear(&pvargDest);
  VariantClear(&v36);
  SysFreeString(bstrClass);
  SysFreeString(bstrDataId);
  SysFreeString(bstrEventType);
  SysFreeString(bstrTypeName);
  SysFreeString(bstrDisplyName);
  sub_F97C40(ppWbemServices, &theList);
  v32 = theList;
  v33 = *theList;
  *v32 = v32;
  v32[1] = v32;
  if ( v33 != v32 )
  {
    do
    {
      v34 = *v33;
      j__free(v33);
      v33 = v34;
    }
    while ( v34 != v32 );
  }
  j__free(v32);
  return v6;
}

//----- (00F992A0) --------------------------------------------------------
int __cdecl sub_F992A0(wchar_t *Dst, size_t SizeInWords, int a3)
{
  return swprintf_s(
           Dst,
           SizeInWords,
           L"{%08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x}",
           *a3,
           *(a3 + 4),
           *(a3 + 6),
           *(a3 + 8),
           *(a3 + 9),
           *(a3 + 10),
           *(a3 + 11),
           *(a3 + 12),
           *(a3 + 13),
           *(a3 + 14),
           *(a3 + 15));
}

//----- (00F992F0) --------------------------------------------------------
HRESULT __cdecl SetProxyAccessRight(tagWbemServicesList *pWbemServicesList)
{
  OLECHAR *strNetworkResource; // edi
  HRESULT v2; // esi
  IWbemLocator *pLocator; // [esp+8h] [ebp-4h]

  pLocator = 0;
  strNetworkResource = SysAllocString(L"root\\wmi");
  CoInitialize(0);
  v2 = CoCreateInstance(&CLSID_WbemLocator, 0, CLSCTX_INPROC_SERVER, &IID_IWbemLocator, &pLocator);
  if ( !v2 )
  {
    v2 = pLocator->lpVtbl->ConnectServer(pLocator, strNetworkResource, 0, 0, 0, 0, 0, 0, pWbemServicesList);
    if ( !v2 )
      // 是为接口代理设置访问权限
      v2 = CoSetProxyBlanket(
             pWbemServicesList->pService,
             RPC_C_AUTHN_WINNT,
             0u,
             0u,
             RPC_C_IMP_LEVEL_DELEGATE,
             RPC_C_IMP_LEVEL_IMPERSONATE,
             0u,
             0u);
  }
  SysFreeString(strNetworkResource);
  if ( pLocator )
    pLocator->lpVtbl->Release(pLocator);
  return v2;
}

//----- (00F99380) --------------------------------------------------------
_DWORD *__thiscall sub_F99380(_DWORD *this, int a2)
{
  _DWORD *v2; // esi
  int v3; // edi
  _DWORD *v4; // edx
  int v5; // eax
  _DWORD *result; // eax

  v2 = this;
  v3 = *this;
  v4 = std::_List_buy<tagEventItem *,std::allocator<tagEventItem *>>::_Buynode<tagEventItem * const &>(
         *this,
         *(*this + 4),
         a2);
  v5 = v2[1];
  if ( (357913940 - v5) < 1 )
    std::_Xlength_error("list<T> too long");
  v2[1] = v5 + 1;
  *(v3 + 4) = v4;
  result = v4[1];
  *result = v4;
  return result;
}

//----- (00F993D0) --------------------------------------------------------
_WORD *__thiscall sub_F993D0(_WORD *this, OLECHAR *psz)
{
  _WORD *v2; // esi
  BSTR v3; // eax

  v2 = this;
  *this = 8;
  v3 = SysAllocString(psz);
  *(v2 + 2) = v3;
  if ( !v3 && psz )
    _com_issue_error(-2147024882);
  return v2;
}

//----- (00F99410) --------------------------------------------------------
int __usercall QueryShellDispatch@<eax>(int a1@<esi>, IShellFolderViewDual *pShellFolderViewDual, GUID *iid, IDispatch *ppDispApplication)
{
  IShellView *v4; // eax
  IDispatch *ppv; // edi
  int result; // eax
  int v7; // esi
  IDispatch *pDisp; // [esp+4h] [ebp-4h]

  v4 = pShellFolderViewDual;
  ppv = ppDispApplication;
  ppDispApplication->lpVtbl = 0;
  result = v4->lpVtbl->GetItemObject(v4, 0, &CLSID_IDispatch, &pDisp);
  if ( result >= 0 )
  {
    v7 = (pDisp->lpVtbl->QueryInterface)(pDisp, &CLSID_IShellFolderViewDual, &pShellFolderViewDual, a1);
    if ( v7 >= 0 )
    {
      v7 = pShellFolderViewDual->lpVtbl->get_Application(pShellFolderViewDual, &ppDispApplication);
      if ( v7 >= 0 )
      {
        v7 = ppDispApplication->lpVtbl->QueryInterface(ppDispApplication, iid, ppv);
        ppDispApplication->lpVtbl->Release(ppDispApplication);
      }
      pShellFolderViewDual->lpVtbl->Release(pShellFolderViewDual);
    }
    (pDisp->lpVtbl->Release)(pDisp);
    result = v7;
  }
  return result;
}
// 10338D0: using guessed type GUID CLSID_IDispatch;
// 10338F0: using guessed type GUID CLSID_IShellFolderViewDual;

//----- (00F994A0) --------------------------------------------------------
HRESULT __usercall QueryShellView@<eax>(_GUID *iid, IShellView **ppv)
{
  int v2; // esi
  IShellView **v3; // edi
  HRESULT result; // eax
  IShellWindows *v5; // eax
  HRESULT hresult; // esi
  __int128 vtLocation; // [esp+4h] [ebp-20h]
  char hWnd; // [esp+14h] [ebp-10h]
  IShellWindows *pShellWindow; // [esp+18h] [ebp-Ch]
  IUnknown *pDisp; // [esp+1Ch] [ebp-8h]
  IShellBrowser *pShellBrowser; // [esp+20h] [ebp-4h]

  v3 = ppv;
  *ppv = 0;
  result = CoCreateInstance(&CLSID_ShellWindows, 0, CLSCTX_LOCAL_SERVER, &CLSID_IShellWindows, &pShellWindow);
  if ( result >= 0 )
  {
    v5 = pShellWindow;
    _mm_storeu_si128(&vtLocation, 0i64);
    if ( (v5->lpVtbl->FindWindowA)(v5, &vtLocation, &vtLocation, SWC_DESKTOP, &hWnd, SWFO_NEEDDISPATCH, &pDisp, v2) )
    {
      (pShellWindow->lpVtbl->Release)(pShellWindow);
      result = E_FAIL;
    }
    else
    {
      hresult = IUnknown_QueryService(pDisp, &CLSID_SID_STopLevelBrowser, &CLSID_IShellBrowser, &pShellBrowser);
      if ( hresult >= 0 )
      {
        hresult = pShellBrowser->lpVtbl->QueryActiveShellView(pShellBrowser, &ppv);
        if ( hresult >= 0 )
        {
          hresult = ((*ppv)->lpVtbl)(ppv, iid, v3);
          ((*ppv)[2].lpVtbl)(ppv);
        }
        pShellBrowser->lpVtbl->Release(pShellBrowser);
      }
      (pDisp->lpVtbl->Release)(pDisp);
      pShellWindow->lpVtbl->Release(pShellWindow);
      result = hresult;
    }
  }
  return result;
}

//----- (00F99580) --------------------------------------------------------
int __usercall PE_ShellExecute@<eax>(const wchar_t *lpszFile, const wchar_t *lpszParameters, const wchar_t *lpszDir)
{
  const WCHAR *v3; // esi
  int hresult; // edi
  bool v5; // zf
  IShellDispatch2 *v6; // ecx
  OLECHAR *bstrFile; // esi
  IShellDispatch2Vtbl *v8; // edx
  VARIANT vtArgs; // [esp-40h] [ebp-84h]
  VARIANT vtDir; // [esp-30h] [ebp-74h]
  VARIANT vtOperation; // [esp-20h] [ebp-64h]
  VARIANT vbShow; // [esp-10h] [ebp-54h]
  void *v14; // [esp-4h] [ebp-48h]
  VARIANTARG vtArgs1; // [esp+Ch] [ebp-38h]
  VARIANTARG vtDir1; // [esp+1Ch] [ebp-28h]
  BSTR bstrFile1; // [esp+2Ch] [ebp-18h]
  IShellView *pShellView; // [esp+30h] [ebp-14h]
  IShellDispatch2 *pShellDisp; // [esp+34h] [ebp-10h]
  int v20; // [esp+40h] [ebp-4h]

  v3 = lpszParameters;
  hresult = QueryShellView(&CLSID_IShellView, &pShellView);
  v5 = hresult == 0;
  if ( hresult >= 0 )
  {
    hresult = QueryShellDispatch(lpszParameters, pShellView, &CLSID_IShellDispatch2, &pShellDisp);
    if ( hresult >= 0 )
    {
      bstrFile1 = SysAllocString(lpszFile);
      hresult = E_OUTOFMEMORY;
      if ( bstrFile1 )
        hresult = 0;
      if ( hresult >= 0 )
      {
        vtArgs1.vt = VT_BSTR;
        vtArgs1.lVal = SysAllocString(lpszParameters);
        if ( !vtArgs1.lVal && lpszParameters )
          _com_issue_error(E_OUTOFMEMORY);
        v20 = 0;
        vtDir1.vt = VT_BSTR;
        vtDir1.lVal = SysAllocString(lpszDir);
        if ( !vtDir1.lVal && lpszDir )
          _com_issue_error(E_OUTOFMEMORY);
        v6 = pShellDisp;
        bstrFile = bstrFile1;
        LOBYTE(v20) = 1;
        v8 = pShellDisp->lpVtbl;
        _mm_storeu_si128(&vbShow, 0i64);
        _mm_storeu_si128(&vtOperation, 0i64);
        _mm_storeu_si128(&vtDir, _mm_loadu_si128(&vtDir1));
        _mm_storeu_si128(&vtArgs, _mm_loadu_si128(&vtArgs1));
        hresult = v8->ShellExecuteA(v6, bstrFile, vtArgs, vtDir, vtOperation, vbShow);
        SysFreeString(bstrFile);
        VariantClear(&vtDir1);
        v20 = -1;
        VariantClear(&vtArgs1);
        v3 = lpszParameters;
      }
      v14 = pShellDisp;
      pShellDisp->lpVtbl->Release(pShellDisp);
    }
    v14 = pShellView;
    pShellView->lpVtbl->Release(pShellView);
    v5 = hresult == 0;
  }
  if ( !v5 && ShellExecuteW(0, 0, lpszFile, v3, 0, 1) > ERROR_SHARING_VIOLATION )
    hresult = 0;
  return hresult;
}

//----- (00F99700) --------------------------------------------------------
CRYPT_PROVIDER_DATA *__cdecl sub_F99700(CRYPT_PROVIDER_DATA *a1, char a2, WINTRUST_DATA **a3, unsigned int *a4, GUID *a5, int a6)
{
  CRYPT_PROVIDER_DATA *result; // eax
  GUID *v7; // ebx
  unsigned int v8; // edi
  WCHAR *v9; // esi
  wchar_t *v10; // edi
  const wchar_t *i; // esi
  wchar_t *v12; // eax
  wchar_t *v13; // eax
  unsigned int v14; // [esp+8h] [ebp-818h]
  unsigned int v15; // [esp+14h] [ebp-80Ch]
  CRYPT_PROVIDER_DATA *v16; // [esp+18h] [ebp-808h]
  WCHAR szName[1024]; // [esp+1Ch] [ebp-804h]

  result = a1;
  v14 = *a4;
  *a4 = 0;
  if ( !a1 )
    return result;
  result = WTHelperProvDataFromStateData(a1);
  if ( !result )
    return result;
  result = WTHelperGetProvSignerFromChain(result, 0, 0, 0);
  if ( !result )
    return result;
  if ( a3 )
  {
    *a3 = result->pWintrustData;
    a3[1] = result->fOpenedFile;
  }
  if ( !a2 )
    goto LABEL_9;
  if ( result->dwRegPolicySettings )
  {
    result = result->sPfns.cbStruct;
LABEL_9:
    v7 = result->pgActionID;
    result = result->hWndParent;
    goto LABEL_10;
  }
  v7 = a5;
  result = 0;
LABEL_10:
  v8 = 0;
  v16 = result;
  v15 = 0;
  if ( result )
  {
    while ( 1 )
    {
      if ( v8 >= v14 )
        return result;
      result = CertGetNameStringW(*&v7->Data2, CERT_NAME_FRIENDLY_DISPLAY_TYPE, 0, 0, szName, 0x400u);
      if ( result )
        break;
LABEL_29:
      v15 = ++v8;
      if ( v8 >= v16 )
        return result;
    }
    if ( wcsstr(szName, L"CN=") )
    {
      v9 = wcsstr(szName, L"CN=") + 3;
    }
    else if ( wcsstr(szName, L"OU=") )
    {
      v10 = wcsstr(szName, L"OU=");
      for ( i = v10 + 1; wcsstr(v10 + 1, L"OU="); i = v10 + 1 )
        v10 = wcsstr(i, L"OU=");
      v12 = wcsstr(v10, L"OU=");
      v8 = v15;
      v9 = v12 + 3;
    }
    else
    {
      v9 = szName;
    }
    if ( *v9 == 34 )
    {
      ++v9;
      v13 = wcschr(v9, '"');
    }
    else
    {
      if ( !wcschr(v9, ',') )
      {
LABEL_26:
        result = _wcsdup(v9);
        *(&a5->Data1 + *a4) = result;
        if ( a6 )
        {
          result = CertDuplicateCertificateContext(*&v7->Data2);
          *(a6 + 4 * *a4) = result;
        }
        v7 = (v7 + v7->Data1);
        ++*a4;
        goto LABEL_29;
      }
      v13 = wcschr(v9, ',');
    }
    *v13 = 0;
    goto LABEL_26;
  }
  return result;
}

//----- (00F99930) --------------------------------------------------------
MACRO_HRESULT __cdecl sub_F99930(HCATADMIN hCatAdmin, int a2, char fdwRevocationChecks, BYTE *pbHash, DWORD cbHash, void *a6, int a7, int a8)
{
  HCATINFO hCatInfo; // edi
  LONG hresult; // esi
  CATALOG_INFO CatInfo; // [esp+18h] [ebp-210h]

  hCatInfo = CryptCATAdminEnumCatalogFromHash(hCatAdmin, pbHash, cbHash, 0, 0);
  if ( !hCatInfo )
    return TRUST_E_NOSIGNATURE;
  while ( 1 )
  {
    memset(&CatInfo, 0, sizeof(CATALOG_INFO));
    CatInfo.cbStruct = sizeof(CATALOG_INFO);
    if ( CryptCATCatalogInfoFromContext(hCatInfo, &CatInfo, 0) )
      break;
    CryptCATAdminReleaseCatalogContext(hCatAdmin, hCatInfo, 0);
    hCatInfo = CryptCATAdminEnumCatalogFromHash(hCatAdmin, pbHash, cbHash, 0, 0);
    if ( !hCatInfo )
      return TRUST_E_NOSIGNATURE;
  }
  hresult = sub_F99A40(a2, fdwRevocationChecks, pbHash, cbHash, a6, CatInfo.wszCatalogFile, a7, a8);
  CryptCATAdminReleaseCatalogContext(hCatAdmin, hCatInfo, 0);
  return hresult;
}

//----- (00F99A40) --------------------------------------------------------
LONG __cdecl sub_F99A40(int a1, char fdwRevocationChecks, int a3, int a4, void *a5, int a6, int a7, int dwIndex)
{
  int v8; // eax
  WINTRUST_DATA_EX *ActionData; // edi
  unsigned int nIndex; // esi
  WCHAR *pszBuffer; // edi
  wchar_t *v12; // eax
  LONG v13; // esi
  wchar_t **v14; // edi
  WINTRUST_SIGNATURE_SETTINGS Settings; // [esp+Ch] [ebp-A4h]
  __int128 v17; // [esp+24h] [ebp-8Ch]
  __int128 v18; // [esp+34h] [ebp-7Ch]
  int v19; // [esp+44h] [ebp-6Ch]
  WINTRUST_DATA_EX *v20; // [esp+48h] [ebp-68h]
  wchar_t **v21; // [esp+4Ch] [ebp-64h]
  int v22; // [esp+50h] [ebp-60h]
  wchar_t *v23; // [esp+54h] [ebp-5Ch]
  WCHAR szBuffer[42]; // [esp+58h] [ebp-58h]

  v8 = a3;
  ActionData = a5;
  nIndex = 0;
  v23 = a6;
  v22 = a3;
  v20 = a5;
  v21 = a7;
  if ( a4 )
  {
    pszBuffer = szBuffer;
    do
    {
      swprintf_s(pszBuffer, 3u, L"%02X", *(v8 + nIndex));
      v8 = v22;
      ++nIndex;
      pszBuffer += 2;
    }
    while ( nIndex < a4 );
    ActionData = v20;
  }
  v12 = v23;
  _mm_storeu_si128(&v17, 0i64);
  *(&v17 + 1) = __PAIR__(szBuffer, v12);
  _mm_storeu_si128(&v18, 0i64);
  LODWORD(v18) = a1;
  v19 = 0;
  LODWORD(v17) = 36;
  *(&v18 + 1) = __PAIR__(a4, v22);
  memset(ActionData, 0, sizeof(WINTRUST_DATA_EX));
  ActionData->dwUIChoice = WTD_UI_NONE;
  ActionData->dwUnionChoice = WTD_CHOICE_CATALOG;
  ActionData->dwStateAction = HANDLE_FLAG_INHERIT;
  ActionData->cbStruct = 4 * (dwIndex != -1) + 0x30;
  ActionData->fdwRevocationChecks = fdwRevocationChecks != 0;// WTD_REVOKE_NONE:WTD_REVOKE_WHOLECHAIN
  ActionData->pFile = &v17;
  if ( dwIndex != -1 )
  {
    _mm_storeu_si128(&Settings, 0i64);
    Settings.cbStruct = sizeof(WINTRUST_SIGNATURE_SETTINGS);
    *&Settings.dwVerifiedSigIndex = 0i64;
    Settings.dwFlags = 1;
    Settings.dwIndex = dwIndex;
    ActionData->pSignatureSettings = &Settings;
  }
  v13 = WinVerifyTrust(0, &GUID_ActionID_0, ActionData);
  if ( !v13 )
  {
    v14 = v21;
    if ( v21 )
      *v14 = _wcsdup(v23);
  }
  return v13;
}

//----- (00F99BB0) --------------------------------------------------------
LONG __cdecl sub_F99BB0(const WCHAR *a1, int a2, HCATADMIN *a3, char a4, int a5, _DWORD *a6, int a7, int a8, int a9, int a10, int a11, wchar_t **a12, int dwIndex)
{
  unsigned int *v13; // ebx
  LPCWSTR v14; // eax
  DWORD dwUnionChoice; // eax
  LONG result; // eax
  LONG v17; // ecx
  wchar_t *v18; // eax
  HANDLE hFile; // ebx
  MACRO_HRESULT v20; // eax
  WINTRUST_SIGNATURE_SETTINGS Settings; // [esp+Ch] [ebp-B0h]
  int dwStateAction; // [esp+24h] [ebp-98h]
  LPCWSTR v23; // [esp+28h] [ebp-94h]
  HCATADMIN *v24; // [esp+34h] [ebp-88h]
  DWORD cbSize; // [esp+38h] [ebp-84h]
  WINTRUST_DATA **v26; // [esp+3Ch] [ebp-80h]
  WINTRUST_DATA_EX ActionData; // [esp+40h] [ebp-7Ch]
  GUID *v28; // [esp+74h] [ebp-48h]
  int v29; // [esp+78h] [ebp-44h]
  GUID *v30; // [esp+7Ch] [ebp-40h]
  int v31; // [esp+80h] [ebp-3Ch]
  int a6a; // [esp+84h] [ebp-38h]
  HCATADMIN phCatAdmin; // [esp+88h] [ebp-34h]
  DWORD dwUnionChoice_1; // [esp+8Ch] [ebp-30h]
  MACRO_HRESULT v35; // [esp+90h] [ebp-2Ch]
  int dwHash; // [esp+94h] [ebp-28h]
  unsigned int *v37; // [esp+98h] [ebp-24h]
  LPCWSTR lpFileName; // [esp+9Ch] [ebp-20h]
  LONG v39; // [esp+A0h] [ebp-1Ch]
  int cbHash; // [esp+A4h] [ebp-18h]

  lpFileName = a1;
  a6a = a2;
  v24 = a3;
  v26 = a5;
  v28 = a7;
  v13 = a9;
  v29 = a8;
  v30 = a10;
  v37 = a9;
  v31 = a11;
  dwHash = 20;
  v35 = TRUST_E_NOSIGNATURE;
  LoadWintrust();
  if ( a12 )
    *a12 = 0;
  v14 = lpFileName;
  _mm_storeu_si128(&dwStateAction, 0i64);
  v23 = v14;
  dwStateAction = 0x10;
  memset(&ActionData, 0, sizeof(WINTRUST_DATA_EX));
  ActionData.dwUIChoice = 2;
  ActionData.dwUnionChoice = 1;
  ActionData.dwStateAction = HANDLE_FLAG_INHERIT;
  cbSize = 4 * (dwIndex != -1) + 0x30;
  ActionData.cbStruct = 4 * (dwIndex != -1) + 0x30;
  dwUnionChoice = 0;
  if ( a4 )
    dwUnionChoice = 0x40;
  dwUnionChoice_1 = dwUnionChoice;
  ActionData.fdwRevocationChecks = dwUnionChoice;
  ActionData.pFile = &dwStateAction;
  if ( dwIndex != -1 )
  {
    _mm_storeu_si128(&Settings, 0i64);
    Settings.cbStruct = sizeof(WINTRUST_SIGNATURE_SETTINGS);
    *&Settings.dwVerifiedSigIndex = 0i64;
    Settings.dwFlags = 1;
    Settings.dwIndex = dwIndex;
    ActionData.pSignatureSettings = &Settings;
  }
  result = WinVerifyTrust(0, &GUID_ActionID, &ActionData);
  v39 = result;
  if ( !result || result == CERT_E_REVOKED )
  {
    if ( a12 )
    {
      *a12 = _wcsdup(lpFileName);
      result = v39;
    }
    goto LABEL_15;
  }
  if ( !a6 )
  {
LABEL_15:
    v17 = TRUST_E_NOSIGNATURE;
    goto LABEL_16;
  }
  memset(&ActionData, 0, sizeof(WINTRUST_DATA_EX));
  ActionData.cbStruct = cbSize;
  ActionData.fdwRevocationChecks = dwUnionChoice_1;
  ActionData.pFile = &dwStateAction;
  ActionData.pSignatureSettings = &Settings;
  ActionData.dwUIChoice = WTD_UI_NONE;
  ActionData.dwUnionChoice = WTD_UI_ALL;
  ActionData.dwStateAction = HANDLE_FLAG_INHERIT;
  ActionData.dwProvFlags = WTD_HASH_ONLY_FLAG;
  v17 = WinVerifyTrust(0, &GUID_ActionID, &ActionData);
  dwUnionChoice_1 = v17;
  if ( v17 || !a12 )
  {
    result = v39;
  }
  else
  {
    v18 = _wcsdup(lpFileName);
    v17 = dwUnionChoice_1;
    *a12 = v18;
    result = v39;
  }
LABEL_16:
  if ( !result || !v17 )
    goto LABEL_36;
  if ( *CryptCATAdminAcquireContext )
  {
    hFile = CreateFileW(lpFileName, GENERIC_READ, FILE_SHARE_READ, 0, 3u, FILE_ATTRIBUTE_NORMAL, 0);
    if ( hFile == INVALID_HANDLE_VALUE )
    {
LABEL_30:
      v13 = v37;
      result = v39;
      goto LABEL_31;
    }
    if ( !CryptCATAdminCalcHashFromFileHandle(hFile, &dwHash, &cbHash, 0) )
    {
      CloseHandle(hFile);
      goto LABEL_30;
    }
    CloseHandle(hFile);
    if ( v24 )
    {
      v20 = sub_F99930(*v24, lpFileName, a4, &cbHash, dwHash, &ActionData, a12, dwIndex);
    }
    else
    {
      if ( !a6a )
        goto LABEL_28;
      v20 = sub_F99A40(lpFileName, a4, &cbHash, dwHash, &ActionData, a6a, a12, dwIndex);
    }
    v35 = v20;
    if ( v20 == 0 )
      goto LABEL_30;
LABEL_28:
    CryptCATAdminAcquireContext(&phCatAdmin, 0, 0);
    v35 = sub_F99930(phCatAdmin, lpFileName, a4, &cbHash, dwHash, &ActionData, a12, dwIndex);
    if ( phCatAdmin )
      CryptCATAdminReleaseContext(phCatAdmin, 0);
    goto LABEL_30;
  }
LABEL_31:
  if ( v35 )
  {
    if ( a6 )
      *a6 = 0;
    if ( v13 )
      *v13 = 0;
    return result;
  }
LABEL_36:
  if ( a6 )
    sub_F99700(ActionData.hWVTStateData, 0, v26, a6, v28, v29);
  if ( v13 )
    sub_F99700(ActionData.hWVTStateData, 1, 0, v13, v30, v31);
  ActionData.dwStateAction = HANDLE_FLAG_PROTECT_FROM_CLOSE;
  WinVerifyTrust(0, &GUID_ActionID, &ActionData);
  return 0;
}
// F99F40: using guessed type bool __cdecl LoadWintrust();

//----- (00F99F40) --------------------------------------------------------
bool LoadWintrust()
{
  HMODULE v0; // eax
  HMODULE v1; // edi
  HMODULE v3; // eax

  if ( !byte_1064D7C )
  {
    byte_1064D7C = 1;
    v0 = LoadLibraryW(L"Wintrust.dll");
    v1 = v0;
    if ( !v0 )
      return 0;
    *WinVerifyTrust = GetProcAddress(v0, "WinVerifyTrust");
    *WTHelperGetProvSignerFromChain = GetProcAddress(v1, "WTHelperGetProvSignerFromChain");
    *WTHelperProvDataFromStateData = GetProcAddress(v1, "WTHelperProvDataFromStateData");
    *CryptCATAdminReleaseContext = GetProcAddress(v1, "CryptCATAdminReleaseContext");
    *CryptCATAdminReleaseCatalogContext = GetProcAddress(v1, "CryptCATAdminReleaseCatalogContext");
    *CryptCATCatalogInfoFromContext = GetProcAddress(v1, "CryptCATCatalogInfoFromContext");
    *CryptCATAdminEnumCatalogFromHash = GetProcAddress(v1, "CryptCATAdminEnumCatalogFromHash");
    *CryptCATAdminCalcHashFromFileHandle = GetProcAddress(v1, "CryptCATAdminCalcHashFromFileHandle");
    *CryptCATAdminAcquireContext = GetProcAddress(v1, "CryptCATAdminAcquireContext");
    *CryptCATAdminAddCatalog = GetProcAddress(v1, "CryptCATAdminAddCatalog");
    *CryptCATAdminRemoveCatalog = GetProcAddress(v1, "CryptCATAdminRemoveCatalog");
    *IsCatalogFile = GetProcAddress(v1, "IsCatalogFile");
    v3 = LoadLibraryW(L"crypt32.dll");
    *CertNameToStrW = GetProcAddress(v3, "CertNameToStrW");
  }
  return *CryptCATAdminAcquireContext != 0;
}
// F99F40: using guessed type bool __cdecl LoadWintrust();
// 1064D7C: using guessed type char byte_1064D7C;

//----- (00F9A040) --------------------------------------------------------
CTreeList *__thiscall CTreeList::CTreeList(CTreeList *this)
{
  CTreeList *result; // eax

  this->baseclass.m_hThemeHandle = 0;
  result = this;
  this->baseclass.vtptr = &CTreeList::`vftable';
  this->m_hWnd = 0;
  this->m_hWndHeaderLeft = 0;
  this->m_hWndHeaderRight = 0;
  this->m_hWndScrollBarRightRight = 0;
  this->m_hWndScrollBarLeftBottom = 0;
  this->m_hWndScrollBarRightBottom = 0;
  this->m_hWndStatic = 0;
  this->m_hWndTooltipOfTreeList = 0;
  this->m_Font = 0;
  this->m_hCursor = 0;
  this->m_ImageList = 0;
  LOBYTE(this->m_NotMyImageList) = 0;
  this->field_40 = 0;
  this->field_44.x = 0;
  this->field_44.y = 0;
  this->m_Child = 0;
  this->field_58 = 0;
  this->m_nChildCount = 0;
  this->m_dwTreeStyle = 0;
  this->field_64 = 0;
  this->m_nHeight = 1;
  this->m_nImageWidth = 2;
  this->m_Height = 3;
  this->field_74 = 0;
  this->m_nChildWidth = 16;
  this->m_ChildLast = 0;
  this->m_nLastVScrollPos = 0;
  this->field_84 = 0;
  this->field_88 = 0;
  this->m_nLastVScrollPos2 = 0;
  this->m_nBottomScrollBarWidthOrHeight = 0;
  this->field_94 = 20;
  this->m_nChildWidthLast = 0;
  *&this->field_9C = 1;
  this->m_nHeaderItemCount = -1;
  this->m_point.x = -1;
  this->m_point.y = 0;
  this->field_B4 = -1;
  this->field_B8 = -1;
  LOBYTE(this->field_BC) = 1;
  LOBYTE(this->m_ptDownLast.y) = 0;
  this->field_D0 = 0;
  this->m_pfnDrawBack = 0;
  this->m_pfnGetChildCursor = 0;
  this->m_Format = 0x8820;
  this->field_50 = 0;
  this->field_4C = 0;
  return result;
}
// 1034188: using guessed type void *CTreeList::`vftable';

//----- (00F9A1F0) --------------------------------------------------------
HTHEME __thiscall CTreeList::~CTreeList(CTreeList *this)
{
  CTreeList *v1; // edi
  int v2; // esi
  HTHEME result; // eax

  v1 = this;
  this->baseclass.vtptr = &CTreeList::`vftable';
  v2 = this->field_D0;
  if ( v2 )
  {
    if ( !InterlockedDecrement((v2 + 8)) && v2 )
    {
      if ( *v2 )
      {
        SysFreeString(*v2);
        *v2 = 0;
      }
      if ( *(v2 + 4) )
      {
        j_j__free(*(v2 + 4));
        *(v2 + 4) = 0;
      }
      j__free(v2);
    }
    v1->field_D0 = 0;
  }
  sub_F9A2C0(&v1->field_40);
  result = v1->baseclass.m_hThemeHandle;
  v1->baseclass.vtptr = &CThemedWindow::`vftable';
  if ( result )
    result = gpfnCloseThemeData(result);
  return result;
}
// 1034130: using guessed type void *CThemedWindow::`vftable';
// 1034188: using guessed type void *CTreeList::`vftable';

//----- (00F9A2C0) --------------------------------------------------------
void __thiscall sub_F9A2C0(tagTreeViewChildItem *this)
{
  tagTreeViewChildItem *v1; // edx
  tagTreeViewChildItem *v2; // edx
  tagTreeViewChildItem *v3; // edx
  tagTreeViewChildItem *v4; // edx
  tagTreeViewChildItem *v5; // eax
  CTreeListData *v6; // edx

  v1 = this->m_Item0C;
  if ( v1 )
    v1->m_Prev = this->m_Prev;
  v2 = this->m_Prev;
  if ( v2 )
    v2->m_Item0C = this->m_Item0C;
  v3 = this->m_Current;
  if ( v3 )
  {
    if ( v3->m_Next == this )
      v3->m_Next = this->m_Prev;
    v4 = this->m_Current;
    if ( v4->m_Item18 == this )
      v4->m_Item18 = this->m_Item0C;
    --this->m_Current->m_nCount;
    v5 = this->m_Current;
    if ( !v5->m_nCount )
      v5->m_dwStyle &= -0x41u;
  }
  v6 = this->m_TreeListData;
  if ( v6 )
    (v6->vtptr->field_14)(v6, this);
}

//----- (00F9A320) --------------------------------------------------------
_bstr_t *__thiscall sub_F9A320(_bstr_t *this, LPCSTR lpString)
{
  _bstr_t *v2; // edi
  Data_t_bstr_t *v3; // esi
  const CHAR *v4; // eax
  Data_t_bstr_t *v5; // eax
  Data_t_bstr_t *v6; // esi

  v2 = this;
  if ( !lpString )
    goto LABEL_16;
  v3 = this->m_Data;
  if ( this->m_Data )
  {
    if ( !v3->m_str )
      v3->m_str = sub_1004270(v3->m_wstr);
    v4 = v3->m_str;
  }
  else
  {
    v4 = 0;
  }
  if ( v4 != lpString )
  {
LABEL_16:
    _bstr_t::_Free(v2);
    v5 = operator new(0xCu);
    v6 = v5;
    if ( v5 )
    {
      v5->m_str = 0;
      v5->m_RefCount = 1;
      v5->m_wstr = _com_util::ConvertBSTRToString(lpString);
    }
    else
    {
      v6 = 0;
    }
    v2->m_Data = v6;
    if ( !v6 )
      _com_issue_error(-2147024882);
  }
  return v2;
}

//----- (00F9A3E0) --------------------------------------------------------
BOOL __thiscall sub_F9A3E0(BSTR **this, BSTR **a2)
{
  Data_t_bstr_t *v2; // ecx
  BSTR *v3; // eax
  OLECHAR *v5; // eax

  v2 = *this;
  v3 = *a2;
  if ( v2 == *a2 )
    return 1;
  if ( !v2 )
  {
    if ( v3 )
    {
      v5 = *v3;
      if ( v5 )
      {
        if ( SysStringLen(v5) )
          return 0;
      }
    }
    return 1;
  }
  if ( v3 )
    return bstr_t::Data_t::Compare(v2, *a2) == 0;
  if ( !v2->m_wstr || !SysStringLen(v2->m_wstr) )
    return 1;
  return 0;
}

//----- (00F9A460) --------------------------------------------------------
void *__thiscall CTreeListData::`scalar deleting destructor'(void *this, char a2)
{
  void *v2; // esi

  v2 = this;
  *this = &CTreeListData::`vftable';
  if ( a2 & 1 )
    j__free(this);
  return v2;
}
// 103414C: using guessed type void *CTreeListData::`vftable';

//----- (00F9A490) --------------------------------------------------------
HWND __cdecl CTreeList::Init(HWND hWndParent, HINSTANCE hInstance, HMENU hMenu, int a4, RECT *lprc)
{
  CTreeList *v5; // eax
  CTreeList *v6; // ebx

  v5 = operator new(0xDCu);
  if ( v5 )
    v6 = CTreeList::CTreeList(v5);
  else
    v6 = 0;
  v6->m_hWnd = CreateWindowExW(
                 0,
                 gAtomTreeList,
                 &gszNullString,
                 a4 | 0x2000000,
                 lprc->left,
                 lprc->top,
                 lprc->right - lprc->left,
                 lprc->bottom - lprc->top,
                 hWndParent,
                 hMenu,
                 hInstance,
                 v6);
  CTreeList::OnInited(v6);
  return v6->m_hWnd;
}
// 1064D9C: using guessed type __int16 gAtomTreeList;

//----- (00F9A510) --------------------------------------------------------
HWND __stdcall CTreeList::CreateTooltips(HINSTANCE hInstance, HWND hWndParent)
{
  HWND v2; // esi
  LPARAM lParam; // [esp+8h] [ebp-34h]
  int v5; // [esp+Ch] [ebp-30h]
  HWND v6; // [esp+10h] [ebp-2Ch]
  struct tagRECT Rect; // [esp+18h] [ebp-24h]
  int v8; // [esp+2Ch] [ebp-10h]
  __int64 v9; // [esp+30h] [ebp-Ch]

  v2 = CreateWindowExW(0, L"tooltips_class32", 0, 0x80000033, 0, 0, 0, 0, hWndParent, 0, hInstance, 0);
  lParam = 48;
  v5 = 256;
  v9 = 0i64;
  _mm_storeu_si128(&v6, 0i64);
  _mm_storeu_si128(&Rect.right, 0i64);
  v6 = hWndParent;
  v8 = -1;
  GetClientRect(hWndParent, &Rect);
  SendMessageW(v2, TTM_ADDTOOLW, 0, &lParam);
  return v2;
}

//----- (00F9A5B0) --------------------------------------------------------
LRESULT __stdcall CThemedWindow::HandleMessage(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
  return DefWindowProcW(hWnd, Msg, wParam, lParam);
}

//----- (00F9A5C0) --------------------------------------------------------
int __stdcall sub_F9A5C0(int pChild)
{
  int v1; // ecx
  int v2; // edi
  CTreeList *v3; // esi
  signed int v4; // eax
  int v5; // eax
  HWND v6; // eax
  LPARAM lParam; // [esp+8h] [ebp-2Ch]
  __int128 v9; // [esp+Ch] [ebp-28h]
  __int128 v10; // [esp+1Ch] [ebp-18h]
  __int64 v11; // [esp+2Ch] [ebp-8h]

  v2 = v1;
  v3 = *pChild;
  v4 = CTreeList::FindChild(*pChild, pChild);
  lParam = 0;
  _mm_storeu_si128(&v9, 0i64);
  DWORD2(v9) = v4;
  v5 = *(v2 + 4);
  v11 = 0i64;
  HIDWORD(v11) = v5;
  _mm_storeu_si128(&v10, 0i64);
  v6 = GetParent(v3->m_hWnd);
  return SendMessageW(v6, 0xFFFFFF99, 0, &lParam);
}

//----- (00F9A620) --------------------------------------------------------
int __thiscall CTreeList::OnDestroy(CTreeList *this)
{
  CTreeList *v1; // esi
  bool v2; // zf
  HWND v3; // ST00_4

  v1 = this;
  v2 = this->m_Child == 0;
  this->m_bSkipTimerForTooltip = 1;
  if ( !v2 )
  {
    do
      sub_F9A7D0(v1, v1->m_Child);
    while ( v1->m_Child );
  }
  v3 = v1->m_hWnd;
  v1->m_bSkipTimerForTooltip = 0;
  InvalidateRect(v3, 0, 0);
  InvalidateRect(v1->m_hWndHeaderLeft, 0, 0);
  InvalidateRect(v1->m_hWndHeaderRight, 0, 0);
  v1->m_nChildWidthLast = CTreeList::GetChildWidth(v1, 0);
  CTreeList::OnSize(v1);
  CTreeList::RepositionHeaders();
  return CTreeList::RepositionTooltips();
}

//----- (00F9A690) --------------------------------------------------------
bool __thiscall sub_F9A690(HWND *this, WPARAM wParam)
{
  CTreeList *v2; // edi
  LRESULT v3; // esi
  LRESULT v4; // eax
  BOOL v5; // eax
  HWND v6; // ST00_4
  LPARAM lParam; // [esp+4h] [ebp-238h]
  int a2; // [esp+8h] [ebp-234h]
  char *v10; // [esp+Ch] [ebp-230h]
  int v11; // [esp+14h] [ebp-228h]
  char v12; // [esp+30h] [ebp-20Ch]

  v2 = this;
  if ( wParam )
  {
    v5 = SendMessageW(this[5], 0x1202u, wParam - 1, 0) != 0;
  }
  else
  {
    v3 = SendMessageW(this[3], 0x1200u, 0, 0);
    v4 = SendMessageW(v2->m_hWndHeaderRight, 0x1200u, 0, 0);
    if ( v3 )
    {
      if ( v4 )
      {
        lParam = 7;
        v10 = &v12;
        v6 = v2->m_hWndHeaderRight;
        v11 = 260;
        SendMessageW(v6, 0x120Bu, 0, &lParam);
        SendMessageW(v2->m_hWndHeaderLeft, 0x1202u, 0, 0);
        SendMessageW(v2->m_hWndHeaderRight, 0x1202u, 0, 0);
        SendMessageW(v2->m_hWndHeaderLeft, 0x120Au, 0, &lParam);
        CTreeList::MoveHeaders(v2, a2);
        LOBYTE(v5) = 1;
      }
      else
      {
        v5 = SendMessageW(v2->m_hWndHeaderLeft, 0x1202u, 0, 0) != 0;
      }
    }
    else
    {
      LOBYTE(v5) = 0;
    }
  }
  return v5;
}

//----- (00F9A7D0) --------------------------------------------------------
void __thiscall sub_F9A7D0(CTreeList *this, tagTreeViewChildItem *pChild)
{
  tagTreeViewChildItem *pChild_1; // edi
  CTreeList *pThis; // esi
  tagTreeViewChildItem *i; // eax
  NMHDR *v5; // eax
  LONG v6; // eax
  bool v7; // zf
  HWND v8; // eax
  WPARAM v9; // ST10_4
  HWND v10; // eax
  tagTreeViewChildItem *v11; // ebx
  NMHDR *lParam; // [esp+Ch] [ebp-1Ch]
  LONG v13; // [esp+10h] [ebp-18h]
  int v14; // [esp+14h] [ebp-14h]
  int v15; // [esp+18h] [ebp-10h]
  tagTreeViewChildItem *v16; // [esp+1Ch] [ebp-Ch]
  int v17; // [esp+20h] [ebp-8h]
  int v18; // [esp+24h] [ebp-4h]
  tagTreeViewChildItem *pChilda; // [esp+30h] [ebp+8h]

  pChild_1 = pChild;
  pThis = this;
  for ( i = pChild->m_Next; i; i = pChild->m_Next )
    sub_F9A7D0(pThis, i);
  v5 = pThis->m_hWnd;
  v14 = 2006;
  lParam = v5;
  v6 = GetWindowLongW(v5, GWLP_ID);
  v7 = LOBYTE(pThis->m_ptDownLast.y) == 0;
  v13 = v6;
  v17 = 0;
  v15 = 0;
  v16 = pChild;
  v18 = 0;
  if ( v7 )
  {
    v9 = v6;
    v10 = GetParent(pThis->m_hWnd);
    SendMessageW(v10, WM_NOTIFY, v9, &lParam);
  }
  else
  {
    v8 = GetParent(pThis->m_hWnd);
    CTreeList::SendNotifyEx(pThis, v8, &lParam);
  }
  if ( pThis->m_ChildLast == pChild )
  {
    CTreeList::SendNotify(pThis, pThis->m_hWnd, 2000, 0, 0, pChild, 0);
    pThis->m_ChildLast = 0;
  }
  if ( pThis->m_point.y == pChild )
    pThis->m_point.y = 0;
  pChilda = CTreeList::FindChild(pThis, pChild);
  CTreeList::SetVScrollbarPos(pChilda, -1);
  v11 = pChild_1->m_Current;
  sub_F9A2C0(pChild_1);
  j__free(pChild_1);
  if ( v11 )
  {
    if ( !(v11->m_dwStyle & 0x40) )
      CTreeList::RedrawZone(pThis, &pChilda[-1].m_dwStyle + 3, &pChilda[-1].m_dwStyle + 3);
  }
}

//----- (00F9A8E0) --------------------------------------------------------
signed int __thiscall TreeViewChildItem_GetSiblingCount(tagTreeViewChildItem *this)
{
  tagTreeViewChildItem *v1; // ecx
  signed int result; // eax

  v1 = this->m_Current;
  for ( result = -1; v1; ++result )
    v1 = v1->m_Current;
  return result;
}

//----- (00F9A900) --------------------------------------------------------
void __thiscall CTreeList::DrawHeader(CTreeList *this, int hWndHeader, HDC hDC, RECT rect)
{
  CTreeList *this_1; // esi
  HDC hdcWindow; // edi
  signed int nCount; // ebx
  HBRUSH v7; // eax
  int *v8; // eax
  signed int nIndex; // edi
  HWND v10; // ST08_4
  RECT *v11; // ecx
  int v12; // eax
  int v13; // ecx
  COLORREF v14; // eax
  HDC hdc_1; // edi
  int v16; // eax
  int *v17; // eax
  HGDIOBJ hOldPen; // [esp+0h] [ebp-2B8h]
  HPEN hPen; // [esp+4h] [ebp-2B4h]
  HGDIOBJ hOldFont; // [esp+8h] [ebp-2B0h]
  int v21; // [esp+Ch] [ebp-2ACh]
  COLORREF BkColor; // [esp+10h] [ebp-2A8h]
  int *pnIds; // [esp+14h] [ebp-2A4h]
  RECT *pRect; // [esp+18h] [ebp-2A0h]
  HDC hdc; // [esp+1Ch] [ebp-29Ch]
  int i; // [esp+20h] [ebp-298h]
  int *pFormat; // [esp+24h] [ebp-294h]
  HWND hWndHeader_1; // [esp+28h] [ebp-290h]
  int *nFormat; // [esp+2Ch] [ebp-28Ch]
  RECT *rcItem; // [esp+30h] [ebp-288h]
  int tm; // [esp+34h] [ebp-284h]
  HDITEMW Item; // [esp+44h] [ebp-274h]
  RECT rc; // [esp+70h] [ebp-248h]
  struct tagSCROLLINFO ScrollInfo; // [esp+80h] [ebp-238h]
  struct tagRECT rcText; // [esp+9Ch] [ebp-21Ch]
  WCHAR chText[260]; // [esp+ACh] [ebp-20Ch]

  this_1 = this;
  hWndHeader_1 = hWndHeader;
  hdc = hDC;
  _mm_storeu_si128(&rc, _mm_loadu_si128(&rect));
  hdcWindow = GetDC(this->m_hWnd);
  SelectObject(hdcWindow, this_1->m_Font);
  GetTextMetricsW(hdcWindow, &tm);
  ReleaseDC(this_1->m_hWnd, hdcWindow);
  if ( this_1->m_ImageList )
    GetSystemMetrics(SM_CYSMICON);
  GetWindowRect(this_1->m_hWndHeaderLeft, &ScrollInfo.nMax);
  if ( hWndHeader_1 == this_1->m_hWndHeaderLeft )
  {
    nCount = 1;
    rcItem = 1;
  }
  else
  {
    rcItem = SendMessageW(this_1->m_hWndHeaderRight, HDM_GETITEMCOUNT, 0, 0);
    if ( !rcItem )
    {
      v7 = GetSysColorBrush(COLOR_WINDOW);
      FillRect(hDC, &rc, v7);
      return;
    }
    nCount = rcItem;
  }
  v8 = operator new[](4 * nCount);
  pnIds = v8;
  if ( hWndHeader_1 == this_1->m_hWndHeaderLeft )
    *v8 = 0;
  else
    SendMessageW(this_1->m_hWndHeaderRight, HDM_GETORDERARRAY, nCount, v8);
  pRect = operator new[](16 * nCount);
  nIndex = 0;
  pFormat = operator new[](4 * nCount);
  for ( i = 0; nIndex < rcItem; i = v13 )
  {
    nFormat = &pRect[nIndex].left;
    SendMessageW(hWndHeader_1, HDM_GETITEMRECT, pnIds[nIndex], &pRect[nIndex]);
    InflateRect(nFormat, -2, -2);
    if ( hWndHeader_1 == this_1->m_hWndHeaderLeft && !nIndex )
    {
      if ( this_1->field_9C )
      {
        ScrollInfo.cbSize = sizeof(SCROLLINFO);
        v10 = this_1->m_hWndScrollBarLeftBottom;
        ScrollInfo.nTrackPos = 0;
        _mm_storeu_si128(&ScrollInfo.nMin, 0i64);
        ScrollInfo.fMask = SIF_POS;
        GetScrollInfo(v10, SB_CTL, &ScrollInfo);
        v11 = pRect;
        v11->left -= ScrollInfo.nPos;
        v12 = v11->left + this_1->m_nChildWidthLast;
        if ( v11->right < v12 )
          v11->right = v12;
      }
    }
    pFormat[nIndex] = this_1->m_Format;
    if ( hWndHeader_1 != this_1->m_hWndHeaderLeft )
    {
      Item.mask = HDI_FORMAT;
      SendMessageW(this_1->m_hWndHeaderRight, HDM_GETITEMW, pnIds[nIndex], &Item);
      if ( Item.fmt & HDF_RIGHT )
        pFormat[nIndex] |= DT_RIGHT;
    }
    if ( nCount > nIndex && nFormat[2] > rc.left )
      nCount = nIndex;
    v13 = i;
    if ( *nFormat < rc.right )
      v13 = nIndex;
    ++nIndex;
  }
  v14 = GetSysColor(COLOR_3DDKSHADOW);
  hdc_1 = hdc;
  hPen = CreatePen(0, 1, v14);
  hOldPen = SelectObject(hdc, hPen);
  hOldFont = SelectObject(hdc, this_1->m_Font);
  if ( nCount <= i )
  {
    nFormat = &pFormat[nCount];
    rcItem = &pRect[nCount];
    v21 = pnIds - pFormat;
    do
    {
      BkColor = GetBkColor(hdc_1);
      if ( hWndHeader_1 == this_1->m_hWndHeaderLeft )
        v16 = nCount;
      else
        v16 = *(nFormat + v21) + 1;
      if ( (this_1->m_pfnDrawBack)(v16, hdc_1, &BkColor) )
      {
        ValidateRect(hWndHeader_1, rcItem);
        hdc = CreateSolidBrush(BkColor);
        GetBkMode(hdc_1);
        Item.pszText = chText;
        Item.mask = HDI_TEXT;
        v17 = nFormat;
        _mm_storeu_si128(&ScrollInfo.nMax, 0i64);
        Item.cchTextMax = 260;
        SendMessageW(hWndHeader_1, HDM_GETITEMW, *(v17 + v21), &Item);
        rcText.left = this_1->m_nImageWidth + rcItem->left;
        rcText.top = this_1->m_Height + rcItem->top;
        rcText.right = rcItem->right - this_1->m_nImageWidth;
        rcText.bottom = rcItem->bottom;
        DrawTextW(hdc_1, chText, -1, &ScrollInfo.nMax, *nFormat | DT_CALCRECT);
        if ( rcText.bottom - rcText.top < ScrollInfo.nTrackPos )
          rcText.top = rcText.bottom - ScrollInfo.nTrackPos;
        SetBkColor(hdc_1, BkColor);
        FillRect(hdc_1, rcItem, hdc);
        DrawTextW(hdc_1, chText, -1, &rcText, *nFormat);
        DeleteObject(hdc);
      }
      ++rcItem;
      ++nCount;
      ++nFormat;
    }
    while ( nCount <= i );
  }
  SelectObject(hdc_1, hOldFont);
  SelectObject(hdc_1, hOldPen);
  DeleteObject(hPen);
  j_j__free(pRect);
  j_j__free(pnIds);
  j_j__free(pFormat);
}

//----- (00F9AE40) --------------------------------------------------------
LRESULT __thiscall CTreeList::SendNotify(CTreeList *this, HWND hWnd, int code, int Msg, tagTreeViewChildItem *pSibling, tagTreeViewChildItem *pChild, int nItem)
{
  CTreeList *v7; // esi
  UINT nID; // eax
  bool v9; // zf
  HWND hWndParent; // eax
  LRESULT result; // eax
  WPARAM v12; // ST08_4
  HWND v13; // eax
  tagTVNMHDR lParam; // [esp+4h] [ebp-1Ch]

  lParam.nmhdr.hwndFrom = code;
  v7 = this;
  lParam.nmhdr.hwndFrom = hWnd;
  nID = GetWindowLongW(hWnd, GWLP_ID);
  v9 = LOBYTE(v7->m_ptDownLast.y) == 0;
  lParam.nItem1 = Msg;
  lParam.pFrom = pChild;
  lParam.pTo = pSibling;
  lParam.nmhdr.idFrom = nID;
  lParam.nItem2 = nItem;
  if ( v9 )
  {
    v12 = nID;
    v13 = GetParent(v7->m_hWnd);
    result = SendMessageW(v13, WM_NOTIFY, v12, &lParam);
  }
  else
  {
    hWndParent = GetParent(v7->m_hWnd);
    result = CTreeList::SendNotifyEx(v7, hWndParent, &lParam);
  }
  return result;
}

//----- (00F9AEC0) --------------------------------------------------------
void __thiscall CTreeList::DrawTree(CTreeList *this, HDC *a2, HRGN a3)
{
  CTreeList *pThis; // ebx
  HDC hDC; // edi
  HWND m_hWnd; // ST20_4
  int v6; // eax
  int v7; // ecx
  UINT v8; // edi
  int nCount; // ebx
  signed int v10; // eax
  int v11; // ecx
  int v12; // eax
  _DWORD *v13; // eax
  CTreeList *v14; // edi
  WPARAM v15; // ecx
  const __m128i *v16; // ebx
  int v17; // edx
  signed int v18; // eax
  int v19; // ecx
  __m128i v20; // xmm1
  int v21; // ecx
  __m128i v22; // xmm0
  _DWORD *v23; // ecx
  int v24; // eax
  int index; // ebx
  int v26; // ecx
  HWND v27; // ST1C_4
  RECT *v28; // ecx
  int v29; // eax
  int v30; // ecx
  int v31; // edx
  int *v32; // eax
  int v33; // eax
  HBRUSH v34; // eax
  COLORREF v35; // eax
  HPEN v36; // eax
  HDC v37; // ST20_4
  HGDIOBJ v38; // eax
  HFONT v39; // ST24_4
  tagTreeViewChildItem *v40; // eax
  struct tagPOINT *v41; // eax
  int v42; // ecx
  LPPOINT v43; // ebx
  int v44; // eax
  COLORREF v45; // eax
  COLORREF v46; // eax
  COLORREF v47; // eax
  COLORREF v48; // eax
  int v49; // edx
  RECT *v50; // edx
  LONG v51; // eax
  LONG v52; // ecx
  LONG v53; // edx
  __m128i v54; // xmm0
  int v55; // eax
  HBRUSH v56; // ebx
  LONG v57; // eax
  LONG v58; // ST20_4
  int v59; // eax
  char v60; // al
  COLORREF v61; // eax
  HBRUSH v62; // eax
  HDC v63; // ST24_4
  int v64; // ebx
  int v65; // eax
  CThemedWindow *v66; // edi
  HDC v67; // ST1C_4
  HBITMAP v68; // eax
  HDC v69; // ST24_4
  HDC v70; // ebx
  HBRUSH v71; // eax
  signed int v72; // eax
  LPPOINT v73; // edx
  int v74; // ebx
  LONG v75; // eax
  LONG v76; // ebx
  bool v77; // zf
  LONG v78; // ecx
  int i; // ST34_4
  UINT v80; // ST24_4
  int v81; // edi
  COLORREF v82; // eax
  CTreeList *v83; // ebx
  int v84; // ST10_4
  HDC v85; // edi
  int v86; // eax
  int v87; // ebx
  const WCHAR *v88; // edi
  int v89; // ST24_4
  HDC v90; // ST14_4
  HGDIOBJ v91; // edi
  LONG v92; // ecx
  LONG v93; // edx
  LONG v94; // ebx
  int v95; // eax
  HBRUSH v96; // eax
  struct tagPOINT *v97; // eax
  LONG v98; // eax
  int v99; // ecx
  RECT *v100; // ebx
  int v101; // ecx
  LONG v102; // eax
  HBRUSH v103; // eax
  HDC v104; // ST20_4
  HGDIOBJ v105; // edi
  void *v106; // ST24_4
  void (__stdcall *v107)(HDC, HGDIOBJ); // edi
  HBRUSH v108; // eax
  RECT *lprc; // [esp-4h] [ebp-364h]
  LONG *v110; // [esp+10h] [ebp-350h]
  int v111; // [esp+18h] [ebp-348h]
  HGDIOBJ v112; // [esp+1Ch] [ebp-344h]
  HGDIOBJ v113; // [esp+20h] [ebp-340h]
  HGDIOBJ h; // [esp+24h] [ebp-33Ch]
  int v115; // [esp+28h] [ebp-338h]
  int v116; // [esp+2Ch] [ebp-334h]
  int v117; // [esp+30h] [ebp-330h]
  HDC hdcDst; // [esp+34h] [ebp-32Ch]
  HGDIOBJ ho; // [esp+38h] [ebp-328h]
  HBRUSH hbr; // [esp+3Ch] [ebp-324h]
  HGDIOBJ v121; // [esp+40h] [ebp-320h]
  int dy; // [esp+44h] [ebp-31Ch]
  int v123; // [esp+48h] [ebp-318h]
  unsigned int v124; // [esp+4Ch] [ebp-314h]
  int j; // [esp+50h] [ebp-310h]
  RECT *pRects; // [esp+54h] [ebp-30Ch]
  int v127; // [esp+58h] [ebp-308h]
  CTreeList *This; // [esp+5Ch] [ebp-304h]
  int nPos; // [esp+60h] [ebp-300h]
  void *v130; // [esp+64h] [ebp-2FCh]
  int tmHeight; // [esp+68h] [ebp-2F8h]
  void *v132; // [esp+6Ch] [ebp-2F4h]
  int v133; // [esp+70h] [ebp-2F0h]
  LPPOINT lpPoints; // [esp+74h] [ebp-2ECh]
  RECT rc; // [esp+78h] [ebp-2E8h]
  struct tagRECT v136; // [esp+88h] [ebp-2D8h]
  int tm; // [esp+98h] [ebp-2C8h]
  LPARAM lParam; // [esp+A8h] [ebp-2B8h]
  struct tagSCROLLINFO v139; // [esp+B8h] [ebp-2A8h]
  int x[4]; // [esp+D4h] [ebp-28Ch]
  struct tagRECT rcDst; // [esp+E4h] [ebp-27Ch]
  RECT rcSrc1; // [esp+F4h] [ebp-26Ch]
  struct tagRECT v143; // [esp+104h] [ebp-25Ch]
  RECT v144; // [esp+114h] [ebp-24Ch]
  RECT rect; // [esp+124h] [ebp-23Ch]
  RECT rcSrc2; // [esp+134h] [ebp-22Ch]
  RECT v147; // [esp+144h] [ebp-21Ch]
  char v148; // [esp+154h] [ebp-20Ch]

  pThis = this;
  This = this;
  hDC = GetDC(this->m_hWnd);
  SelectObject(hDC, pThis->m_Font);
  GetTextMetricsW(hDC, &tm);
  m_hWnd = pThis->m_hWnd;
  tmHeight = tm;
  ReleaseDC(m_hWnd, hDC);
  if ( pThis->m_ImageList )
  {
    v6 = GetSystemMetrics(SM_CYSMICON);
    v7 = tmHeight;
    if ( tmHeight < v6 )
      v7 = v6;
  }
  else
  {
    v7 = tmHeight;
  }
  v127 = v7 + pThis->m_nHeight;
  GetWindowRect(pThis->m_hWndHeaderLeft, &v139.nMax);
  v8 = v139.nTrackPos - v139.nPage;
  nCount = SendMessageW(pThis->m_hWndHeaderRight, HDM_GETITEMCOUNT, 0, 0) + 1;
  v10 = a2[3] - v8;
  v133 = nCount;
  nPos = v10 / v127;
  v11 = (a2[5] - v8) / v127;
  v12 = v10 / v127;
  v116 = (a2[5] - v8) / v127;
  if ( v12 < 0 )
    v12 = 0;
  nPos = v12;
  if ( !nCount || v12 > v11 )
  {
    v108 = GetSysColorBrush(COLOR_WINDOW);
    FillRect(*a2, (a2 + 2), v108);
    return;
  }
  v13 = operator new[](4 * nCount);
  v14 = This;
  v15 = v133 - 1;
  v132 = v13;
  v16 = (v13 + 1);
  *v13 = 0;
  SendMessageW(v14->m_hWndHeaderRight, HDM_GETORDERARRAY, v15, (v13 + 1));
  v17 = v133;
  v18 = 1;
  v19 = v133 - 1;
  if ( v133 > 1 )
  {
    if ( v19 >= 8 )
    {
      v20 = _mm_load_si128(&stru_1034280);
      v121 = (v19 % 8);
      v21 = v133 - v19 % 8;
      do
      {
        v22 = _mm_loadu_si128(v16);
        v18 += 8;
        v16 += 2;
        _mm_storeu_si128(&v16[-2], _mm_add_epi32(v22, v20));
        _mm_storeu_si128(&v16[-1], _mm_add_epi32(_mm_loadu_si128(v16 - 1), v20));
      }
      while ( v18 < v21 );
    }
    if ( v18 < v133 )
    {
      v23 = v132;
      do
        ++v23[v18++];
      while ( v18 < v17 );
    }
  }
  pRects = operator new[](16 * v17);
  v130 = operator new[](4 * v133);
  v24 = v133;
  index = 0;
  v117 = v133;
  for ( j = 0; index < v133; j = v31 )
  {
    lpPoints = &pRects[index];
    v26 = *(v132 + index);
    lprc = &pRects[index];
    if ( v26 )
    {
      SendMessageW(v14->m_hWndHeaderRight, HDM_GETITEMRECT, v26 - 1, lprc);
      MapWindowPoints(v14->m_hWndHeaderRight, v14->m_hWnd, lpPoints, 2u);
    }
    else
    {
      SendMessageW(v14->m_hWndHeaderLeft, HDM_GETITEMRECT, 0, lprc);
      MapWindowPoints(v14->m_hWndHeaderLeft, v14->m_hWnd, lpPoints, 2u);
    }
    if ( !index )
    {
      if ( v14->field_9C )
      {
        v139.cbSize = 28;
        v27 = v14->m_hWndScrollBarLeftBottom;
        v139.nTrackPos = 0;
        _mm_storeu_si128(&v139.nMin, 0i64);
        v139.fMask = 4;
        GetScrollInfo(v27, 2, &v139);
        v28 = pRects;
        v28->left -= v139.nPos;
        v29 = v28->left + v14->m_nChildWidthLast;
        if ( v28->right < v29 )
          v28->right = v29;
      }
    }
    *(v130 + index) = v14->m_Format;
    if ( index )
    {
      lParam = 4;
      SendMessageW(v14->m_hWndHeaderRight, HDM_GETITEMW, *(v132 + index) - 1, &lParam);
      if ( v139.fMask & 1 )
        *(v130 + index) |= 2u;
    }
    v30 = v117;
    if ( v117 > index )
    {
      if ( lpPoints[1].x > a2[2] )
        v30 = index;
      v117 = v30;
    }
    v31 = j;
    v24 = v133;
    if ( lpPoints->x < a2[4] )
      v31 = index;
    ++index;
  }
  v32 = &pRects[v24 - 1].right;
  v110 = v32;
  v33 = *v32;
  if ( a2[4] > v33 )
  {
    _mm_storeu_si128(&v139.nMax, _mm_loadu_si128((a2 + 2)));
    v139.nMax = v33;
    v34 = GetSysColorBrush(COLOR_WINDOW);
    FillRect(*a2, &v139.nMax, v34);
  }
  v35 = GetSysColor(COLOR_3DDKSHADOW);
  v36 = CreatePen(0, 1, v35);
  v37 = *a2;
  v121 = v36;
  v38 = SelectObject(v37, v36);
  v39 = v14->m_Font;
  v113 = v38;
  v112 = SelectObject(*a2, v39);
  v123 = GetSystemMetrics(SM_CXSMICON);
  dy = GetSystemMetrics(SM_CYSMICON);
  v40 = CTreeList::GetCurScrollChildItem(v14);
  v41 = TreeViewChildItem_GetChild(v40, nPos);
  v42 = nPos;
  v43 = v41;
  lpPoints = v41;
  tmHeight = v127 * nPos;
  v44 = v127;
  while ( v43 )
  {
    if ( v43[4].x & 1 )
    {
      if ( GetFocus() == v14->m_hWnd )
      {
        v45 = GetSysColor(COLOR_HIGHLIGHTTEXT);
        SetTextColor(*a2, v45);
        v46 = GetSysColor(COLOR_HIGHLIGHT);
      }
      else
      {
        v47 = GetSysColor(COLOR_WINDOWTEXT);
        SetTextColor(*a2, v47);
        v46 = GetSysColor(COLOR_ACTIVEBORDER);
      }
    }
    else
    {
      v48 = GetSysColor(8);
      SetTextColor(*a2, v48);
      v46 = GetSysColor(COLOR_WINDOW);
    }
    SetBkColor(*a2, v46);
    SetBkMode(*a2, 2);
    v49 = v117;
    v133 = v117;
    if ( v117 <= j )
    {
      while ( 1 )
      {
        v50 = &pRects[v49];
        v51 = v50->left;
        v52 = tmHeight + v50->bottom;
        v53 = v50->right;
        rect.left = v51;
        rect.top = v52;
        rect.bottom = v52 + v127;
        rect.right = v53;
        if ( v133 > 0 && v53 <= v14->m_nBottomScrollBarWidthOrHeight || !RectInRegion(a3, &rect) )
          goto LABEL_93;
        v54 = _mm_loadu_si128(&rect);
        v55 = v133;
        v56 = 0;
        ho = 0;
        _mm_storeu_si128(&rcSrc2, v54);
        if ( v55 )
        {
          if ( v55 > 0 && rect.left < v14->m_nBottomScrollBarWidthOrHeight )
          {
            rcSrc2.left = v14->m_nBottomScrollBarWidthOrHeight;
            goto LABEL_51;
          }
        }
        else
        {
          v57 = v14->m_nBottomScrollBarWidthOrHeight;
          if ( rect.right >= v57 )
          {
            rcSrc2.right = v57 - 1;
LABEL_51:
            v56 = CreateRectRgnIndirect(&rcSrc2);
            ho = v56;
            SelectClipRgn(*a2, v56);
            goto LABEL_56;
          }
        }
        SelectClipRgn(*a2, 0);
LABEL_56:
        SelectObject(*a2, v14->m_Font);
        v58 = lpPoints[4].x;
        v59 = *lpPoints->y;
        v115 = 4 * v133;
        v60 = (*(v59 + 16))(lpPoints, *a2, *(v132 + v133), v58, &rect);
        v14 = This;
        if ( !v60 )
        {
          v61 = GetBkColor(*a2);
          v62 = CreateSolidBrush(v61);
          v63 = *a2;
          hbr = v62;
          GetBkMode(v63);
          v64 = v14->m_nImageWidth + rect.left;
          x[1] = rect.top + v14->field_74;
          v65 = rect.right - v14->m_nImageWidth;
          x[0] = v64;
          x[2] = v65;
          x[3] = rect.bottom;
          v66 = &This->baseclass;
          if ( !*(v132 + v115) )
          {
            v67 = *a2;
            rc.left = 0;
            rc.top = 0;
            rc.right = v65 - v64;
            rc.bottom = rect.bottom - rect.top;
            v68 = CreateCompatibleBitmap(v67, v65 - v64, rect.bottom - rect.top);
            v69 = *a2;
            h = v68;
            v70 = CreateCompatibleDC(v69);
            hdcDst = v70;
            SelectObject(v70, h);
            v71 = GetSysColorBrush(5);
            FillRect(v70, &rc, v71);
            v72 = TreeViewChildItem_GetSiblingCount(lpPoints);
            v73 = lpPoints;
            v74 = v66[15].vtptr * v72 + rc.left;
            v75 = lpPoints[4].x;
            rc.left = v74;
            v124 = v75;
            if ( v75 & 0x40 )
            {
              v136.top = rc.top + (rc.bottom - rc.top - dy) / 2;
              v136.bottom = dy + v136.top;
              v136.right = v74 + v123;
              v136.left = v74;
              sub_F9BC20(v66, v66[1].vtptr, hdcDst, ~(v124 >> 4) & 1, &v136);
              v74 = rc.left;
              v73 = lpPoints;
            }
            v76 = v123 + v74;
            v77 = v66[7].vtptr == 0;
            rc.left = v76;
            if ( v77 )
            {
              v85 = hdcDst;
            }
            else
            {
              v78 = v73->y;
              v124 = 0;
              i = (*(*v78 + 12))(v73, &v124);
              v80 = v124 << 8;
              v81 = rc.top + (rc.bottom - rc.top - dy) / 2;
              v82 = GetSysColor(5);
              v83 = This;
              v84 = v81;
              v85 = hdcDst;
              ImageList_DrawEx(This->m_ImageList, i, hdcDst, rc.left, v84, v123, dy, v82, 0xFFFFFFFF, v80);
              v86 = v123 + v83->m_nImageWidth;
              v76 = v86 + rc.left;
              rc.left += v86;
            }
            BitBlt(*a2, x[0], rect.top, v76, x[3], v85, 0, 0, 0xCC0020u);
            x[0] += rc.left;
            DeleteObject(h);
            DeleteDC(v85);
          }
          v87 = v115;
          v111 = 260;
          v88 = (*(*lpPoints->y + 8))(lpPoints, *(v132 + v115), &v148, &v111);
          DrawTextW(*a2, v88, -1, x, *(v130 + v87));
          v89 = *(v130 + v87) | 0x400;
          v90 = *a2;
          _mm_storeu_si128(&v143, _mm_loadu_si128(x));
          DrawTextW(v90, v88, -1, &v143, v89);
          if ( *(v130 + v87) & 2 )
            OffsetRect(&v143, x[2] - v143.right, 0);
          v91 = ho;
          if ( ho )
          {
            SelectClipRgn(*a2, 0);
            DeleteObject(v91);
            v92 = v143.right;
            v93 = v143.left;
            if ( v143.right > rcSrc2.right )
              v92 = rcSrc2.right;
            v94 = rcSrc2.left;
            v143.right = v92;
            if ( v143.left < rcSrc2.left )
              v93 = rcSrc2.left;
            v143.left = v93;
          }
          else
          {
            v94 = rcSrc2.left;
            v92 = v143.right;
            v93 = v143.left;
          }
          v144.top = rcSrc2.top;
          v147.top = rcSrc2.top;
          rcDst.top = rcSrc2.top;
          v144.left = v94;
          rcDst.bottom = v143.top;
          v144.bottom = rcSrc2.bottom;
          v147.right = rcSrc2.right;
          v147.bottom = rcSrc2.bottom;
          rcSrc1.bottom = rcSrc2.bottom;
          v14 = This;
          v144.right = v93;
          v147.left = v92;
          rcDst.left = v93;
          rcDst.right = v92;
          rcSrc1.left = v93;
          rcSrc1.top = v143.bottom;
          rcSrc1.right = v92;
          if ( !v133 )
          {
            v144.right = rcSrc2.left + This->m_nImageWidth;
            v95 = This->m_nBottomScrollBarWidthOrHeight - 1;
            v139.nPage = rcSrc2.top;
            v139.nMax = v95;
            v139.nPos = v95;
            v139.nTrackPos = rcSrc2.bottom;
            Polyline(*a2, &v139.nMax, 2);
          }
          IntersectRect(&rcDst, &rcDst, &rcSrc2);
          IntersectRect(&rcSrc1, &rcSrc1, &rcSrc2);
          IntersectRect(&v144, &v144, &rcSrc2);
          IntersectRect(&v147, &v147, &rcSrc2);
          v56 = hbr;
          if ( rcDst.left < rcDst.right && rcDst.top < rcDst.bottom )
            FillRect(*a2, &rcDst, hbr);
          if ( rcSrc1.left < rcSrc1.right && rcSrc1.top < rcSrc1.bottom )
            FillRect(*a2, &rcSrc1, v56);
          if ( v133 )
            v96 = v56;
          else
            v96 = GetSysColorBrush(5);
          if ( v144.left < v144.right && v144.top < v144.bottom )
            FillRect(*a2, &v144, v96);
          if ( v147.left < v147.right && v147.top < v147.bottom )
            FillRect(*a2, &v147, v56);
LABEL_92:
          DeleteObject(v56);
          goto LABEL_93;
        }
        if ( v56 )
          goto LABEL_92;
LABEL_93:
        v49 = v133 + 1;
        v133 = v49;
        if ( v49 > j )
        {
          v43 = lpPoints;
          break;
        }
      }
    }
    if ( v43[2].y && (v43[4].x >> 4) & 1 )
    {
      v43 = v43[2].y;
LABEL_104:
      lpPoints = v43;
      goto LABEL_105;
    }
    v97 = v43[2].x;
    if ( !v97 )
    {
      v98 = v43[1].x;
      if ( v98 )
      {
        while ( !*(v98 + 16) )
        {
          v98 = *(v98 + 8);
          if ( !v98 )
            goto LABEL_103;
        }
        v43 = *(v98 + 16);
      }
      else
      {
LABEL_103:
        v43 = 0;
      }
      goto LABEL_104;
    }
    v43 = v43[2].x;
    lpPoints = v97;
LABEL_105:
    v44 = v127;
    v42 = nPos + 1;
    tmHeight += v127;
    nPos = v42;
    if ( v42 > v116 )
    {
      v99 = v116;
      goto LABEL_109;
    }
  }
  v99 = v42 - 1;
LABEL_109:
  v100 = pRects;
  v101 = v44 * (v99 + 1);
  if ( a2[5] <= v101 + pRects->bottom - 1 )
  {
    v107 = SelectObject;
  }
  else
  {
    v102 = v101 + pRects->bottom;
    _mm_storeu_si128(&v147, _mm_loadu_si128((a2 + 2)));
    v147.top = v102;
    v147.right = *v110;
    v103 = GetSysColorBrush(COLOR_WINDOW);
    FillRect(*a2, &v147, v103);
    v104 = *a2;
    v147.left = v14->m_nBottomScrollBarWidthOrHeight - 1;
    v147.right = v147.left;
    v105 = SelectObject(v104, v121);
    Polyline(*a2, &v147, 2);
    v106 = v105;
    v107 = SelectObject;
    SelectObject(*a2, v106);
  }
  v107(*a2, v112);
  v107(*a2, v113);
  DeleteObject(v121);
  j_j__free(v100);
  j_j__free(v132);
  j_j__free(v130);
}
// 1034280: using guessed type RECT stru_1034280;

//----- (00F9BC20) --------------------------------------------------------
HGDIOBJ __thiscall sub_F9BC20(CThemedWindow *this, int a2, HDC hDC, char a4, LPRECT lprc)
{
  int v5; // eax
  CThemedWindow *pThis; // esi
  COLORREF v7; // eax
  HTHEME hThemeHandle; // ecx
  HGDIOBJ hOldPen; // eax
  LONG left; // esi
  LONG top; // edx
  LONG right; // ecx
  LONG v14; // edi
  LONG v15; // ebx
  LONG v16; // esi
  LONG v17; // eax
  LONG v18; // ecx
  LONG v19; // eax
  HDC v20; // esi
  POINT pt[2]; // [esp+Ch] [ebp-58h]
  POINT pt2[2]; // [esp+1Ch] [ebp-48h]
  LPRECT v23; // [esp+2Ch] [ebp-38h]
  HDC hdc; // [esp+30h] [ebp-34h]
  HGDIOBJ h; // [esp+34h] [ebp-30h]
  POINT pt3[5]; // [esp+38h] [ebp-2Ch]

  v5 = dword_1064DA8;
  hdc = hDC;
  pThis = this;
  v23 = lprc;
  if ( !(dword_1064DA8 & 1) )
  {
    dword_1064DA8 |= 1u;
    v7 = GetSysColor(COLOR_3DDKSHADOW);
    ghDarkShadowPen = CreatePen(0, 1, v7);
    v5 = dword_1064DA8;
  }
  if ( !(v5 & 2) )
  {
    dword_1064DA8 = v5 | 2;
    ghBlackPen = GetStockObject(BLACK_PEN);
  }
  hThemeHandle = pThis->m_hThemeHandle;
  if ( hThemeHandle )
    return gpfnDrawThemeBackground(hThemeHandle, hDC, 2, (a4 == 0) + 1, lprc, 0);
  InflateRect(lprc, -4, -4);
  hOldPen = SelectObject(hDC, ghDarkShadowPen);
  left = lprc->left;
  top = lprc->top;
  right = lprc->right;
  h = hOldPen;
  pt3[2].y = lprc->bottom;
  pt3[3].y = pt3[2].y;
  pt3[0].x = left;
  pt3[0].y = top;
  pt3[1].x = right;
  pt3[1].y = top;
  pt3[2].x = right;
  pt3[3].x = left;
  pt3[4].x = left;
  pt3[4].y = top;
  Polyline(hDC, pt3, 5);
  SelectObject(hDC, ghBlackPen);
  v14 = lprc->left;
  v15 = v23->bottom;
  v16 = v23->top;
  pt2[0].x = lprc->left + 2;
  v17 = v23->right;
  pt2[0].y = (v15 - v16) / 2 + v16;
  pt2[1].y = (v15 - v16) / 2 + v16;
  pt2[1].x = v17 - 1;
  v18 = (v17 - v14) / 2 + v14;
  v19 = v16 + 2;
  pt[0].x = v18;
  v20 = hdc;
  pt[0].y = v19;
  pt[1].y = v15 - 1;
  pt[1].x = v18;
  Polyline(hdc, pt2, 2);
  if ( a4 )
    Polyline(v20, pt, 2);
  return SelectObject(v20, h);
}
// 1064DA8: using guessed type int dword_1064DA8;

//----- (00F9BDA0) --------------------------------------------------------
char __thiscall sub_F9BDA0(CTreeList *this, char a2)
{
  char result; // al

  result = a2;
  LOBYTE(this->m_ptDownLast.y) = a2;
  return result;
}

//----- (00F9BDB0) --------------------------------------------------------
char __thiscall CTreeList::UpdateSB(CTreeList *this, char a2)
{
  char result; // al
  CTreeList *v3; // edi
  HWND v4; // esi
  SCROLLINFO v5; // [esp+4h] [ebp-20h]

  result = a2;
  v3 = this;
  this->field_9C = a2;
  if ( !a2 )
  {
    CTreeList::UpdateLeftBottomSB(this, this->m_hWndScrollBarLeftBottom, 0, 1);
    v4 = v3->m_hWndScrollBarLeftBottom;
    v5.cbSize = 28;
    _mm_storeu_si128(&v5.nMin, 0i64);
    v5.nTrackPos = 0;
    v5.fMask = 4;
    v5.nPos = 0;
    SetScrollInfo(v4, 2, &v5, 1);
    result = CTreeList::UpdateHeaderPos(v3, v4, 0);
  }
  return result;
}

//----- (00F9BE30) --------------------------------------------------------
UINT __thiscall sub_F9BE30(CTreeList *this, signed int a2)
{
  CTreeList *v2; // esi
  UINT result; // eax
  HWND v4; // ST04_4
  int v5; // edx
  UINT v6; // ecx
  HWND v7; // ST00_4
  SCROLLINFO v8; // [esp+4h] [ebp-3Ch]
  struct tagSCROLLINFO v9; // [esp+20h] [ebp-20h]

  v2 = this;
  result = GetWindowLongW(this->m_hWndScrollBarRightRight, -16) >> 28;
  if ( result & 1 )
  {
    v9.cbSize = 28;
    v4 = v2->m_hWndScrollBarRightRight;
    v9.nTrackPos = 0;
    _mm_storeu_si128(&v9.nMin, 0i64);
    v9.fMask = 7;
    result = GetScrollInfo(v4, 2, &v9);
    v5 = v9.nPos;
    if ( a2 >= v9.nPos )
    {
      result = v9.nPage + v9.nPos;
      if ( a2 < (v9.nPage + v9.nPos) )
        return result;
      v6 = a2 - v9.nPage - v9.nPos + 1;
    }
    else
    {
      v6 = a2 - v9.nPos;
    }
    if ( v6 )
    {
      v8.cbSize = 28;
      v8.nTrackPos = 0;
      _mm_storeu_si128(&v8.nMin, 0i64);
      v8.nPos = v5 + v6;
      v7 = v2->m_hWndScrollBarRightRight;
      v8.fMask = 4;
      SetScrollInfo(v7, 2, &v8, 1);
      result = CTreeList::UpdateVScrollBars(v2, 0);
    }
  }
  return result;
}

//----- (00F9BF00) --------------------------------------------------------
int __thiscall CTreeList::OnMsg2001(CTreeList *thisIn, tagTreeViewChildItem *pItem, char fChild)
{
  tagTreeViewChildItem *result; // eax
  tagTreeViewChildItem *pItem_1; // esi
  CTreeList *this; // edi
  unsigned __int8 HasChildhild; // bl
  int v7; // eax
  int nChild; // [esp+8h] [ebp-4h]
  int nCount; // [esp+14h] [ebp+8h]

  pItem_1 = pItem;
  this = thisIn;
  if ( !pItem )
  {
    LOBYTE(result) = 1;
    return result;
  }
  HasChildhild = (pItem->m_dwStyle >> 4) & 1;
  if ( fChild != HasChildhild )
  {
    if ( fChild )
    {
      result = CTreeList::SendNotify(thisIn, thisIn->m_hWnd, 0x7D1, 0, pItem, 0, 0);
      if ( !result )
      {
        pItem->m_dwStyle |= 0x30u;
        result = TreeViewChildItem_GetChildCount(pItem);
LABEL_9:
        nCount = result;
        if ( result )
        {
          nChild = CTreeList::FindChild(this, pItem_1);
          CTreeList::RedrawZone(this, nChild, nChild);
          v7 = nCount;
          if ( !fChild )
            v7 = -nCount;
          result = CTreeList::SetVScrollbarPos(nChild + 1, v7);
          if ( !fChild )
          {
            result = this->m_ChildLast;
            if ( result )
            {
              while ( result != pItem_1 )
              {
                result = result->m_Current;
                if ( !result )
                  return HasChildhild;
              }
              CTreeList::RedrawChild(this, pItem_1);
            }
          }
        }
        goto __quit;
      }
    }
    else
    {
      result = CTreeList::SendNotify(thisIn, thisIn->m_hWnd, 2002, 0, pItem, 0, 0);
      if ( !result )
      {
        result = TreeViewChildItem_GetChildCount(pItem);
        pItem->m_dwStyle &= -0x11u;
        goto LABEL_9;
      }
    }
  }
__quit:
  LOBYTE(result) = HasChildhild;
  return result;
}

//----- (00F9BFE0) --------------------------------------------------------
signed int __thiscall CTreeList::FindChild(CTreeList *this, tagTreeViewChildItem *pChild)
{
  tagTreeViewChildItem *pChildren; // ecx
  int index; // esi
  tagTreeViewChildItem *pCurrent; // eax

  if ( !pChild )
    return -1;
  pChildren = this->m_Child;
  index = 0;
  if ( !pChildren )
    return -1;
  while ( pChildren != pChild )
  {
    ++index;
    if ( pChildren->m_Next && (pChildren->m_dwStyle >> 4) & 1 )
    {
      pChildren = pChildren->m_Next;
    }
    else if ( pChildren->m_Prev )
    {
      pChildren = pChildren->m_Prev;
    }
    else
    {
      pCurrent = pChildren->m_Current;
      if ( !pCurrent )
        return -1;
      while ( !pCurrent->m_Prev )
      {
        pCurrent = pCurrent->m_Current;
        if ( !pCurrent )
          return -1;
      }
      pChildren = pCurrent->m_Prev;
    }
    if ( !pChildren )
      return -1;
  }
  return index;
}

//----- (00F9C060) --------------------------------------------------------
CTreeList *__cdecl CTreeList::GetTreeList(HWND hWnd)
{
  return GetPropW(hWnd, gAtomTreeListProperty);
}
// 1064DA0: using guessed type __int16 gAtomTreeListProperty;

//----- (00F9C080) --------------------------------------------------------
int __thiscall CTreeList::GetChildWidth(CTreeList *this, int nChildID)
{
  CTreeList *pThis; // edi
  int nTotalWidth; // ebx
  int dwStyle; // eax
  int smIconWidth1; // eax
  HWND v6; // ST10_4
  HDC hDC; // eax
  HFONT v8; // ST10_4
  HGDIOBJ v9; // eax
  tagTreeViewChildItem *pChildren; // esi
  CTreeListData *v11; // ecx
  const WCHAR *pszText; // eax
  __int32 nFormat; // ST10_4
  HDC hdc_1; // ST00_4
  int nWidth; // edx
  tagTreeViewChildItem *v16; // eax
  signed int i; // ecx
  tagTreeViewChildItem *pCurrent; // eax
  HDC v19; // esi
  int cbText; // [esp+Ch] [ebp-230h]
  int smIconWidth; // [esp+10h] [ebp-22Ch]
  HDC hdc; // [esp+14h] [ebp-228h]
  HGDIOBJ hOldFont; // [esp+18h] [ebp-224h]
  int nID; // [esp+1Ch] [ebp-220h]
  struct tagRECT rcText; // [esp+20h] [ebp-21Ch]
  WCHAR szText[260]; // [esp+30h] [ebp-20Ch]

  pThis = this;
  nID = nChildID;
  nTotalWidth = 0;
  dwStyle = this->m_dwTreeStyle;
  smIconWidth1 = GetSystemMetrics(SM_CXSMICON);
  v6 = pThis->m_hWnd;
  smIconWidth = smIconWidth1;
  hDC = GetDC(v6);
  v8 = pThis->m_Font;
  hdc = hDC;
  v9 = SelectObject(hDC, v8);
  pChildren = pThis->m_Child;
  hOldFont = v9;
  while ( pChildren )
  {
    v11 = pChildren->m_TreeListData;
    cbText = 0x104;
    pszText = (v11->vtptr->GetItemText)(pChildren, nID, szText, &cbText);
    nFormat = pThis->m_Format | DT_CALCRECT;
    hdc_1 = hdc;
    _mm_storeu_si128(&rcText, _mm_load_si128(&stru_1034290));
    DrawTextW(hdc_1, pszText, -1, &rcText, nFormat);
    nWidth = rcText.right - rcText.left;
    if ( !nID )
    {
      v16 = pChildren->m_Current;
      for ( i = -1; v16; ++i )
        v16 = v16->m_Current;
      nWidth += smIconWidth + i * pThis->m_nChildWidth;
      if ( pThis->m_ImageList )
        nWidth += smIconWidth + pThis->m_nImageWidth;
    }
    if ( nWidth > nTotalWidth )
      nTotalWidth = nWidth;
    if ( pChildren->m_Next && (pChildren->m_dwStyle >> 4) & 1 )
    {
      pChildren = pChildren->m_Next;
    }
    else if ( pChildren->m_Prev )
    {
      pChildren = pChildren->m_Prev;
    }
    else
    {
      pCurrent = pChildren->m_Current;
      if ( pCurrent )
      {
        while ( !pCurrent->m_Prev )
        {
          pCurrent = pCurrent->m_Current;
          if ( !pCurrent )
            goto LABEL_17;
        }
        pChildren = pCurrent->m_Prev;
      }
      else
      {
LABEL_17:
        pChildren = 0;
      }
    }
  }
  v19 = hdc;
  ReleaseDC(pThis->m_hWnd, hdc);
  SelectObject(v19, hOldFont);
  return nTotalWidth + 2 * pThis->m_nImageWidth;
}
// 1034290: using guessed type RECT stru_1034290;

//----- (00F9C210) --------------------------------------------------------
char __thiscall sub_F9C210(HWND *this, int a2, int a3, char a4, char a5, int a6, LPARAM lParam)
{
  HWND *v7; // ebx
  HWND v8; // ST04_4
  int v9; // eax
  HWND v10; // ST04_4
  HDC v11; // esi
  int v12; // eax
  LONG v13; // ecx
  int v14; // esi
  UINT v15; // ecx
  int v16; // eax
  signed int i; // ecx
  HWND v18; // eax
  LONG v20; // [esp+Ch] [ebp-7Ch]
  struct tagTEXTMETRICW tm; // [esp+10h] [ebp-78h]
  struct tagSCROLLINFO v22; // [esp+4Ch] [ebp-3Ch]
  struct tagSCROLLINFO v23; // [esp+68h] [ebp-20h]

  v7 = this;
  if ( a3 )
  {
    SendMessageW(this[5], 0x1207u, a3 - 1, lParam);
    MapWindowPoints(v7[5], v7[2], lParam, 2u);
  }
  else
  {
    SendMessageW(this[3], 0x1207u, 0, lParam);
    MapWindowPoints(v7[3], v7[2], lParam, 2u);
    v23.cbSize = 28;
    v8 = v7[8];
    v23.nTrackPos = 0;
    _mm_storeu_si128(&v23.nMin, 0i64);
    v23.fMask = 4;
    GetScrollInfo(v8, 2, &v23);
    v9 = v23.nPos;
    *lParam -= v23.nPos;
    *(lParam + 8) -= v9;
  }
  v22.cbSize = 28;
  v10 = v7[7];
  v22.nTrackPos = 0;
  _mm_storeu_si128(&v22.nMin, 0i64);
  v22.fMask = 4;
  GetScrollInfo(v10, 2, &v22);
  v11 = GetDC(v7[2]);
  SelectObject(v11, v7[12]);
  GetTextMetricsW(v11, &tm);
  v20 = tm.tmHeight;
  ReleaseDC(v7[2], v11);
  if ( v7[14] )
  {
    v12 = GetSystemMetrics(50);
    v13 = v20;
    if ( v20 < v12 )
      v13 = v12;
  }
  else
  {
    v13 = v20;
  }
  v14 = v7[26] + v13;
  GetWindowRect(v7[3], &v23.nMax);
  v15 = v23.nTrackPos + v14 * (a2 - v22.nPos) - v23.nPage;
  *(lParam + 4) = v15;
  *(lParam + 12) = v15 + v14;
  if ( a5 )
  {
    *(lParam + 4) = v7[29] + v15;
    *lParam += v7[27];
    *(lParam + 8) -= v7[27];
    if ( !a3 )
    {
      if ( a6 )
      {
        v16 = *(a6 + 8);
        for ( i = -1; v16; ++i )
          v16 = *(v16 + 8);
        *lParam += i * v7[30];
      }
      *lParam += GetSystemMetrics(49);
      if ( v7[14] )
        *lParam += GetSystemMetrics(49);
      *lParam += v7[27];
    }
  }
  if ( a4 )
  {
    GetClientRect(v7[2], &v23.nMax);
    v18 = v7[36];
    if ( a3 )
    {
      if ( *lParam < v18 )
        *lParam = v18;
    }
    else if ( *(lParam + 8) > v18 )
    {
      *(lParam + 8) = v18;
    }
    if ( *lParam < 0 )
      *lParam = 0;
    if ( *(lParam + 8) > v23.nPos )
      *(lParam + 8) = v23.nPos;
    if ( *lParam > *(lParam + 8) )
      *(lParam + 8) = *lParam;
  }
  return 1;
}

//----- (00F9C420) --------------------------------------------------------
int __thiscall sub_F9C420(_DWORD *this)
{
  return this[1];
}

//----- (00F9C430) --------------------------------------------------------
BOOL __thiscall CTreeList::MapToHeader(CTreeList *this, WPARAM wParam, RECT *lParam)
{
  CTreeList *v3; // edi
  LRESULT v4; // eax
  LRESULT v5; // ebx
  HWND v7; // [esp-10h] [ebp-1Ch]
  HWND v8; // [esp-Ch] [ebp-18h]
  RECT *v9; // [esp-8h] [ebp-14h]

  v3 = this;
  if ( wParam )
  {
    v4 = SendMessageW(this->m_hWndHeaderRight, HDM_GETITEMRECT, wParam - 1, lParam);
    v9 = lParam;
    v8 = v3->m_hWnd;
    v7 = v3->m_hWndHeaderRight;
  }
  else
  {
    v4 = SendMessageW(this->m_hWndHeaderLeft, HDM_GETITEMRECT, 0, lParam);
    v9 = lParam;
    v8 = v3->m_hWnd;
    v7 = v3->m_hWndHeaderLeft;
  }
  v5 = v4;
  MapWindowPoints(v7, v8, v9, 2u);
  return v5 != 0;
}

//----- (00F9C490) --------------------------------------------------------
HWND __thiscall CTreeList::GetTooltipOfRightHeader(CTreeList *this)
{
  return this->m_hWndTooltipOfRightHeader;
}

//----- (00F9C4A0) --------------------------------------------------------
int __stdcall sub_F9C4A0(int pChild, int a2)
{
  int v2; // ecx
  CTreeList *v3; // edi
  int v4; // ebx
  signed int v5; // esi
  LONG v6; // eax
  WPARAM v7; // ST08_4
  HWND v8; // eax
  LPARAM lParam; // [esp+Ch] [ebp-40h]
  LONG v11; // [esp+10h] [ebp-3Ch]
  int v12; // [esp+14h] [ebp-38h]
  int v13; // [esp+18h] [ebp-34h]
  int v14; // [esp+1Ch] [ebp-30h]
  int v15; // [esp+24h] [ebp-28h]
  int v16; // [esp+34h] [ebp-18h]
  int v17; // [esp+38h] [ebp-14h]

  v3 = *pChild;
  v4 = v2;
  v5 = CTreeList::FindChild(*pChild, pChild);
  lParam = 0;
  memset(&v11, 0, 0x3Cu);
  lParam = v3->m_hWnd;
  v6 = GetWindowLongW(v3->m_hWnd, -12);
  v17 = *(v4 + 4);
  v7 = v6;
  v11 = v6;
  v12 = -177;
  v13 = 10;
  v14 = v5;
  v8 = GetParent(v3->m_hWnd);
  SendMessageW(v8, 0x4Eu, v7, &lParam);
  *a2 = v15 >> 8;
  return v16;
}

//----- (00F9C530) --------------------------------------------------------
int __stdcall sub_F9C530(int a1, int a2)
{
  return 0;
}

//----- (00F9C540) --------------------------------------------------------
HIMAGELIST __thiscall CTreeList::GetImageList(CTreeList *this)
{
  return this->m_ImageList;
}

//----- (00F9C550) --------------------------------------------------------
char __thiscall sub_F9C550(_DWORD *this, int a2, struct tagRECT *a3)
{
  _DWORD *v3; // ebx
  HWND v4; // ST00_4
  HDC v5; // esi
  LONG v6; // edi
  int v7; // eax
  int v8; // esi
  LONG v9; // eax
  struct tagTEXTMETRICW tm; // [esp+4h] [ebp-6Ch]
  struct tagRECT Rect; // [esp+40h] [ebp-30h]
  struct tagSCROLLINFO v13; // [esp+50h] [ebp-20h]

  v3 = this;
  v13.cbSize = 28;
  v4 = this[7];
  _mm_storeu_si128(&v13.nMin, 0i64);
  v13.nTrackPos = 0;
  v13.fMask = 4;
  GetScrollInfo(v4, 2, &v13);
  v5 = GetDC(v3[2]);
  SelectObject(v5, v3[12]);
  GetTextMetricsW(v5, &tm);
  v6 = tm.tmHeight;
  ReleaseDC(v3[2], v5);
  if ( v3[14] )
  {
    v7 = GetSystemMetrics(50);
    if ( v6 < v7 )
      v6 = v7;
  }
  v8 = v6 + v3[26];
  GetClientRect(v3[2], a3);
  GetWindowRect(v3[3], &Rect);
  v9 = v8 * (a2 - v13.nPos) - Rect.top + Rect.bottom;
  a3->top = v9;
  a3->bottom = v8 + v9;
  return 1;
}

//----- (00F9C630) --------------------------------------------------------
int __thiscall CTreeList::GetLineHeight(CTreeList *this)
{
  tagTreeViewChildItem *pChild; // esi
  int i; // edi
  int nChildCount; // eax

  if ( !((this->m_dwTreeStyle >> 4) & LVS_REPORT) )
    return 0;
  pChild = this->m_Child;
  for ( i = this->m_nChildCount; pChild; i += nChildCount )
  {
    nChildCount = TreeViewChildItem_GetChildCount(pChild);
    pChild = pChild->m_Prev;
  }
  return i;
}

//----- (00F9C670) --------------------------------------------------------
int __thiscall CTreeList::GetScrollInfos(CTreeList *this_, SCROLLINFO *RightScrollInfo, SCROLLINFO *BottomScrollInfo)
{
  CTreeList *v3; // edi
  LRESULT v4; // esi
  LRESULT v5; // edi
  LRESULT v6; // esi
  HDC v7; // esi
  LONG v8; // edi
  int v9; // eax
  int nLineHeight; // esi
  int nLineCount; // edi
  int nChildCount; // ebx
  tagTreeViewChildItem *pChild; // esi
  int v14; // eax
  UINT nPage; // ecx
  int bottom; // eax
  int result; // eax
  int nLineHeight_1; // [esp+Ch] [ebp-A0h]
  int nClientWidth; // [esp+14h] [ebp-98h]
  int nWidth; // [esp+1Ch] [ebp-90h]
  int cyscroll; // [esp+20h] [ebp-8Ch]
  int cxscroll; // [esp+24h] [ebp-88h]
  CTreeList *this; // [esp+28h] [ebp-84h]
  struct tagTEXTMETRICW tm; // [esp+2Ch] [ebp-80h]
  RECT rcItem2; // [esp+68h] [ebp-44h]
  RECT rcItem1; // [esp+78h] [ebp-34h]
  struct tagRECT rcWindow; // [esp+88h] [ebp-24h]
  struct tagRECT rcClient; // [esp+98h] [ebp-14h]

  v3 = this_;
  this = this_;
  GetClientRect(this_->m_hWnd, &rcClient);
  cxscroll = GetSystemMetrics(SM_CXVSCROLL);
  cyscroll = GetSystemMetrics(SM_CYHSCROLL);
  v4 = SendMessageW(v3->m_hWndHeaderRight, HDM_GETITEMCOUNT, 0, 0);
  v5 = SendMessageW(v3->m_hWndHeaderRight, HDM_ORDERTOINDEX, 0, 0);
  v6 = SendMessageW(this->m_hWndHeaderRight, HDM_ORDERTOINDEX, v4 - 1, 0);
  SendMessageW(this->m_hWndHeaderRight, HDM_GETITEMRECT, v5, &rcItem1);
  SendMessageW(this->m_hWndHeaderRight, HDM_GETITEMRECT, v6, &rcItem2);
  nWidth = rcItem2.right - rcItem1.left;
  nClientWidth = rcClient.right - this->m_nBottomScrollBarWidthOrHeight - rcClient.left;
  v7 = GetDC(this->m_hWnd);
  SelectObject(v7, this->m_Font);
  GetTextMetricsW(v7, &tm);
  v8 = tm.tmHeight;
  ReleaseDC(this->m_hWnd, v7);
  if ( this->m_ImageList )
  {
    v9 = GetSystemMetrics(SM_CYSMICON);
    if ( v8 < v9 )
      v8 = v9;
  }
  nLineHeight = v8 + this->m_nHeight;
  nLineHeight_1 = v8 + this->m_nHeight;
  GetWindowRect(this->m_hWndHeaderLeft, &rcWindow);
  nLineCount = rcClient.bottom + rcWindow.top - rcWindow.bottom - rcClient.top;
  if ( (this->m_dwTreeStyle >> 4) & 1 )
  {
    nChildCount = this->m_nChildCount;
    for ( pChild = this->m_Child; pChild; nChildCount += v14 )
    {
      v14 = TreeViewChildItem_GetChildCount(pChild);
      pChild = pChild->m_Prev;
    }
    nLineHeight = nLineHeight_1;
  }
  else
  {
    nChildCount = 0;
  }
  nPage = nClientWidth;
  bottom = nLineHeight * (nChildCount + 1) - 1;
  if ( nWidth <= nClientWidth )
  {
    if ( bottom > nLineCount )
    {
      nPage = nClientWidth - cxscroll;
      if ( nWidth > nClientWidth - cxscroll )
        goto LABEL_16;
    }
  }
  else
  {
    if ( bottom > nLineCount )
    {
      nPage = nClientWidth - cxscroll;
LABEL_16:
      nLineCount -= cyscroll;
      goto LABEL_17;
    }
    nLineCount -= cyscroll;
    if ( bottom > nLineCount )
      nPage = nClientWidth - cxscroll;
  }
LABEL_17:
  RightScrollInfo->nMax = bottom / nLineHeight;
  RightScrollInfo->nPage = nLineCount / nLineHeight;
  RightScrollInfo->cbSize = sizeof(SCROLLINFO);
  result = nWidth - 1;
  RightScrollInfo->fMask = 3;
  RightScrollInfo->nMin = 0;
  BottomScrollInfo->nPage = nPage;
  BottomScrollInfo->cbSize = sizeof(SCROLLINFO);
  BottomScrollInfo->fMask = 3;
  BottomScrollInfo->nMin = 0;
  BottomScrollInfo->nMax = nWidth - 1;
  return result;
}

//----- (00F9C8A0) --------------------------------------------------------
signed int __thiscall sub_F9C8A0(CTreeList *this, bool *a2)
{
  CTreeList *v2; // edi
  LRESULT v3; // eax
  signed int v4; // edx
  signed int v5; // ebx
  int v6; // esi
  bool v7; // zf
  HDITEMW Item; // [esp+Ch] [ebp-34h]
  int v10; // [esp+38h] [ebp-8h]
  int i; // [esp+3Ch] [ebp-4h]

  v2 = this;
  v3 = SendMessageW(this->m_hWndHeaderRight, HDM_GETITEMCOUNT, 0, 0);
  v4 = -1;
  v5 = 0;
  v10 = v3 + 1;
  v6 = 0;
  for ( i = -1; v6 < v10; ++v6 )
  {
    Item.mask = 0x24;
    if ( v6 )
      SendMessageW(v2->m_hWndHeaderRight, HDM_GETITEMW, v6 - 1, &Item);
    else
      SendMessageW(v2->m_hWndHeaderLeft, HDM_GETITEMW, 0, &Item);
    if ( gbBitmapOnRight )
    {
      if ( !(Item.fmt & 0x600) )
        goto LABEL_10;
      v4 = v6;
      i = v6;
      v5 = (Item.fmt & HDF_SORTDOWN) != 0 ? -1 : 1;
    }
    else
    {
      if ( !(Item.fmt & HDF_IMAGE) )
      {
LABEL_10:
        v4 = i;
        continue;
      }
      v7 = Item.iImage == v2->field_B8;
      v4 = v6;
      i = v6;
      v5 = 2 * !v7 - 1;
    }
  }
  if ( a2 )
    *a2 = v5 < 0;
  return v4;
}
// 106A8F8: using guessed type char gbBitmapOnRight;

//----- (00F9C980) --------------------------------------------------------
int __stdcall CListViewData::GetItemText(tagTreeViewChildItem *pChildItem, UINT iSubItem, WCHAR *pszText, PDWORD cbSize)
{
  int v4; // ecx
  CTreeList *pTreeList; // ebx
  CListViewData *v6; // edi
  int iItem; // esi
  UINT v8; // eax
  WPARAM v9; // ST08_4
  HWND hWndParent; // eax
  NMLVDISPINFOW NMLVDispInfo; // [esp+Ch] [ebp-40h]

  pTreeList = pChildItem->m_TreeList;
  v6 = v4;
  iItem = CTreeList::FindChild(pChildItem->m_TreeList, pChildItem);
  NMLVDispInfo.hdr.hwndFrom = 0;
  memset(&NMLVDispInfo.hdr.idFrom, 0, 0x3Cu);
  NMLVDispInfo.hdr.hwndFrom = pTreeList->m_hWnd;
  v8 = GetWindowLongW(pTreeList->m_hWnd, GWLP_ID);
  NMLVDispInfo.item.iSubItem = iSubItem;
  NMLVDispInfo.item.lParam = v6->m_Value;
  NMLVDispInfo.item.cchTextMax = *cbSize;
  v9 = v8;
  NMLVDispInfo.hdr.idFrom = v8;
  NMLVDispInfo.hdr.code = LVN_GETDISPINFOW;
  NMLVDispInfo.item.mask = LVIF_TEXT;
  NMLVDispInfo.item.iItem = iItem;
  NMLVDispInfo.item.pszText = pszText;
  hWndParent = GetParent(pTreeList->m_hWnd);
  SendMessageW(hWndParent, WM_NOTIFY, v9, &NMLVDispInfo);
  return NMLVDispInfo.item.pszText;
}

//----- (00F9CA20) --------------------------------------------------------
const wchar_t *__stdcall sub_F9CA20(int a1, int a2, int a3, int a4)
{
  return L"not implemented";
}
// 1034164: using guessed type wchar_t aNotImplemented[16];

//----- (00F9CA30) --------------------------------------------------------
const wchar_t *CTreeList::GetName()
{
  return L"treeview";
}
// 1034190: using guessed type wchar_t aTreeview[9];

//----- (00F9CA40) --------------------------------------------------------
HWND __thiscall CTreeList::GetTooltipOfTreeList(CTreeList *this)
{
  return this->m_hWndTooltipOfTreeList;
}

//----- (00F9CA50) --------------------------------------------------------
int __thiscall sub_F9CA50(void *this)
{
  return *this;
}

//----- (00F9CA60) --------------------------------------------------------
int __thiscall TreeViewChildItem_GetChildCount(tagTreeViewChildItem *this)
{
  tagTreeViewChildItem *pNext; // esi
  int ret; // edi
  int nCount; // eax

  if ( !((this->m_dwStyle >> 4) & 1) )
    return 0;
  pNext = this->m_Next;
  for ( ret = this->m_nCount; pNext; ret += nCount )
  {
    nCount = TreeViewChildItem_GetChildCount(pNext);
    pNext = pNext->m_Prev;
  }
  return ret;
}

//----- (00F9CAA0) --------------------------------------------------------
LRESULT __thiscall CTreeList::HeaderWndProc(CTreeList *this, HWND hWndFrom, UINT Msg, WPARAM wParam, tagNMLVGETINFOTIPW *lParamIn)
{
  HWND hWndFrom_1; // ebx
  tagNMLVGETINFOTIPW *lParamIn_2; // esi
  CTreeList *this_1; // edi
  UINT uMsg; // edx
  LRESULT (__stdcall *SendMessageW)(HWND, UINT, WPARAM, LPARAM); // ecx
  HWND hWndTooltip_1; // eax
  UINT code; // edx
  WPARAM v12; // eax
  LONG v13; // eax
  WPARAM nItem; // edx
  LONG v16; // eax
  WPARAM v17; // ecx
  LONG nLineHeight; // eax
  int Format; // ebx
  HDC hDC; // eax
  HGDIOBJ v21; // eax
  HDC v22; // ebx
  void *v23; // esi
  void *dwFlags; // ecx
  HDC v25; // esi
  RECT v26; // [esp-10h] [ebp-9Ch]
  HWND v27; // [esp-Ch] [ebp-98h]
  LONG *v28; // [esp-8h] [ebp-94h]
  HWND hWnd; // [esp-4h] [ebp-90h]
  HDITEMW Item; // [esp+Ch] [ebp-80h]
  __int64 v31; // [esp+30h] [ebp-5Ch]
  HWND hWndFrom_2; // [esp+38h] [ebp-54h]
  CTreeList *this_2; // [esp+3Ch] [ebp-50h]
  LPCWSTR lpchText; // [esp+40h] [ebp-4Ch]
  tagNMLVGETINFOTIPW *lParamIn_1; // [esp+44h] [ebp-48h]
  HWND hWndTooltip; // [esp+48h] [ebp-44h]
  struct tagRECT rc; // [esp+4Ch] [ebp-40h]
  HWND lParam; // [esp+5Ch] [ebp-30h]
  UINT v39; // [esp+60h] [ebp-2Ch]
  WPARAM v40; // [esp+64h] [ebp-28h]
  RECT rcItem_1; // [esp+68h] [ebp-24h]
  RECT rcItem; // [esp+78h] [ebp-14h]

  hWndFrom_1 = hWndFrom;
  lParamIn_2 = lParamIn;
  this_1 = this;
  hWndFrom_2 = hWndFrom;
  this_2 = this;
  lParamIn_1 = lParamIn;
  if ( hWndFrom == this->m_hWndHeaderLeft )
    hWndTooltip = this->m_hWndTooltipOfLeftHeader;
  else
    hWndTooltip = this->m_hWndTooltipOfRightHeader;
  uMsg = Msg;
  SendMessageW = ::SendMessageW;
  // Msg <= WM_XBUTTONDBLCLK
  if ( Msg - 512 <= 13 )
  {
    rcItem.right = lParamIn;
    rcItem.bottom = SHIWORD(lParamIn);
    hWnd = 1;
    v40 = wParam;
    v28 = &rcItem.right;
    v27 = this_1->m_hWnd;
    lParam = hWndFrom;
    v39 = Msg;
    rcItem_1.left = lParamIn;
    *&rcItem_1.top = 0i64;
    rcItem_1.bottom = 0;
    MapWindowPoints(hWndFrom, v27, &rcItem.right, 1u);
    CTreeList::PopTooltip(this_1, hWndTooltip, &rcItem.right);
    ::SendMessageW(hWndTooltip, TTM_RELAYEVENT, 0, &lParam);
    SendMessageW = ::SendMessageW;
    uMsg = Msg;
  }
  if ( uMsg == WM_PAINT )
  {
    if ( this_1->m_pfnDrawBack )
    {
      v25 = GetDC(hWndFrom);
      GetUpdateRect(hWndFrom, &rcItem_1, 0);
      _mm_storeu_si128(&v26, _mm_loadu_si128(&rcItem_1));
      CTreeList::DrawHeader(this_1, hWndFrom, v25, v26);
      ReleaseDC(hWndFrom, v25);
      lParamIn_2 = lParamIn_1;
    }
    goto LABEL_27;
  }
  if ( uMsg != WM_NOTIFY )
    goto LABEL_27;
  hWndTooltip_1 = hWndTooltip;
  if ( lParamIn->hdr.hwndFrom != hWndTooltip )
    goto LABEL_27;
  code = lParamIn->hdr.code;
  if ( code == TTN_GETDISPINFOW )
  {
    Item.mask = 7;
    v31 = 0i64;
    _mm_storeu_si128(&Item.cxy, 0i64);
    lpchText = &lParamIn->pszText;
    Item.pszText = &lParamIn->pszText;
    nItem = this_1->m_nHeaderItemCount;
    Item.cchTextMax = 80;
    _mm_storeu_si128(&Item.fmt, 0i64);
    if ( nItem == -1 )
      goto LABEL_30;
    if ( hWndTooltip_1 != this_1->m_hWndTooltipOfLeftHeader )
      --nItem;
    if ( !SendMessageW(hWndFrom, HDM_GETITEMW, nItem, &Item) )
      goto LABEL_30;
    v16 = ::SendMessageW(hWndFrom, HDM_GETBITMAPMARGIN, 0, 0);
    v17 = this_1->m_nHeaderItemCount;
    rcItem.bottom = v16;
    if ( hWndTooltip != this_1->m_hWndTooltipOfLeftHeader )
      --v17;
    ::SendMessageW(hWndFrom, HDM_GETITEMRECT, v17, &rcItem_1);
    if ( rcItem_1.left >= 0 )
    {
      rc.left = 0;
      rc.top = 0;
      rcItem_1.right -= 2 * rcItem.bottom;
      rc.right = GetSystemMetrics(SM_CXVIRTUALSCREEN);
      nLineHeight = CTreeList::GetLineHeight(this_1);
      Format = this_1->m_Format;
      hWnd = this_1->m_hWnd;
      rc.bottom = nLineHeight;
      hDC = GetDC(hWnd);
      hWnd = this_1->m_Font;
      rcItem.bottom = hDC;
      v21 = SelectObject(hDC, hWnd);
      hWnd = (Format & -0x4C001u | HDF_SORTUP);
      v22 = rcItem.bottom;
      v23 = v21;
      DrawTextW(rcItem.bottom, lpchText, -1, &rc, hWnd);
      SelectObject(v22, v23);
      this_1 = this_2;
      ReleaseDC(this_2->m_hWnd, v22);
      dwFlags = &gszNullString;
      lParamIn_2 = lParamIn_1;
      hWndFrom_1 = hWndFrom_2;
      if ( rc.right - rc.left > rcItem_1.right - rcItem_1.left )
        dwFlags = lpchText;
      lParamIn_1->dwFlags = dwFlags;
    }
    else
    {
LABEL_30:
      lParamIn->dwFlags = &gszNullString;
    }
    goto LABEL_27;
  }
  if ( code != TTN_SHOW )
  {
LABEL_27:
    hWnd = lParamIn_2;
    v28 = wParam;
    v27 = Msg;
    v26.left = hWndFrom_1;
    return CallWindowProcW(this_1->m_HeaderWndProc, hWndFrom_1, Msg, wParam, lParamIn_2);
  }
  v12 = this_1->m_nHeaderItemCount;
  if ( hWndTooltip != this_1->m_hWndTooltipOfLeftHeader )
    --v12;
  SendMessageW(hWndFrom, HDM_GETITEMRECT, v12, &rcItem);
  MapWindowPoints(hWndFrom, 0, &rcItem, 2u);
  v13 = rcItem.bottom - rcItem.top + rcItem.left;
  rcItem.top = rcItem.bottom + rcItem.bottom - rcItem.top;
  rcItem.left = v13;
  SetWindowPos(hWndTooltip, 0, v13, rcItem.top, 0, 0, SWP_NOACTIVATE|SWP_NOZORDER|SWP_NOSIZE);
  ::SendMessageW(hWndTooltip, WM_SETFONT, this_1->m_Font, 0);
  return 1;
}

//----- (00F9CDB0) --------------------------------------------------------
signed int __thiscall CTreeList::Query(CTreeList *this, LONG xPos, LONG yPos, int *pxx, WPARAM *pnItem, tagTreeViewChildItem **pyy)
{
  CTreeList *pThis; // ebx
  signed int result; // eax
  int xOffset; // edi
  WPARAM nIndex; // esi
  int nPos; // esi
  tagTreeViewChildItem *pNewChild; // esi
  int nLeft; // edi
  int v13; // eax
  int nLeft_1; // edi
  int v15; // edi
  signed int nItem; // [esp+10h] [ebp-34h]
  int nRightHeaderItemCount; // [esp+18h] [ebp-2Ch]
  tagTreeViewChildItem *pChild; // [esp+18h] [ebp-2Ch]
  int nLeftHeaderHeight; // [esp+1Ch] [ebp-28h]
  int bottom; // [esp+1Ch] [ebp-28h]
  struct tagRECT rwTreeList; // [esp+20h] [ebp-24h]
  struct tagRECT rwHeaderLeft; // [esp+30h] [ebp-14h]

  pThis = this;
  GetClientRect(this->m_hWnd, &rwTreeList);
  if ( pxx )
    *pxx = -1;
  if ( pnItem )
    *pnItem = -1;
  if ( pyy )
    *pyy = 0;
  if ( xPos < rwTreeList.left )
    return 4;
  if ( xPos >= rwTreeList.right )
    return 8;
  if ( yPos < rwTreeList.top )
    return 1;
  if ( yPos >= rwTreeList.bottom )
    return 2;
  xOffset = 0;
  nItem = -1;
  nIndex = 0;
  nRightHeaderItemCount = SendMessageW(pThis->m_hWndHeaderRight, HDM_GETITEMCOUNT, 0, 0) + 1;
  if ( nRightHeaderItemCount > 0 )
  {
    while ( 1 )
    {
      CTreeList::MapToHeader(pThis, nIndex, &rwHeaderLeft);
      if ( xPos >= rwHeaderLeft.left && xPos < rwHeaderLeft.right )
        break;
      if ( ++nIndex >= nRightHeaderItemCount )
        goto LABEL_22;
    }
    nItem = nIndex;
    xOffset = xPos - rwHeaderLeft.left;
    if ( pnItem )
      *pnItem = nIndex;
  }
LABEL_22:
  GetWindowRect(pThis->m_hWndHeaderLeft, &rwHeaderLeft);
  nLeftHeaderHeight = rwHeaderLeft.bottom - rwHeaderLeft.top;
  if ( yPos < rwHeaderLeft.bottom - rwHeaderLeft.top )
    return 512;
  pChild = CTreeList::GetCurScrollChildItem(pThis);
  if ( !pChild )
    return 16;
  nPos = CTreeList::GetRightScrollbarPos(pThis);
  bottom = nPos + (yPos - nLeftHeaderHeight) / CTreeList::GetLineHeight(pThis);
  pNewChild = TreeViewChildItem_GetChild(pChild, bottom - nPos);
  if ( !pNewChild )
    return 16;
  if ( pxx )
    *pxx = bottom;
  if ( pyy )
    *pyy = pNewChild;
  if ( nItem )
    return 128;
  nLeft = xOffset - pThis->m_nChildWidth * TreeViewChildItem_GetSiblingCount(pNewChild);
  if ( nLeft < 0 )
    return 0x100;
  v13 = GetSystemMetrics(SM_CXSMICON);
  nLeft_1 = nLeft - v13;
  if ( nLeft_1 < 0 )
  {
    result = 0x100;
    if ( (pNewChild->m_dwStyle >> 6) & 1 )
      result = 64;
    return result;
  }
  if ( !pThis->m_ImageList )
    return 128;
  v15 = nLeft_1 - v13;
  result = 32;
  if ( v15 >= 0 )
    return 128;
  return result;
}

//----- (00F9D000) --------------------------------------------------------
int __thiscall CTreeList::UpdateHeaderPos(CTreeList *this, HWND hWnd, int a3)
{
  CTreeList *v3; // esi
  HWND v4; // eax
  HWND *v5; // ecx
  int *v6; // ebx
  int bVisible; // eax
  void (__stdcall *v8)(HWND, int, LPSCROLLINFO); // eax
  int v9; // ebx
  LONG v10; // eax
  int v11; // eax
  LONG v12; // ecx
  RECT *v13; // eax
  int v14; // eax
  LONG v15; // ecx
  LONG v16; // edx
  HWND *v17; // [esp+Ch] [ebp-5Ch]
  int *v18; // [esp+10h] [ebp-58h]
  int v19; // [esp+14h] [ebp-54h]
  LONG v20; // [esp+14h] [ebp-54h]
  SCROLLINFO v21; // [esp+18h] [ebp-50h]
  struct tagRECT v22; // [esp+34h] [ebp-34h]
  struct tagRECT Rect; // [esp+44h] [ebp-24h]
  RECT prcScroll; // [esp+54h] [ebp-14h]

  v3 = this;
  v4 = this->m_hWndScrollBarLeftBottom;
  v5 = &this->m_hWndHeaderLeft;
  if ( hWnd != v4 )
    v5 = &v3->m_hWndHeaderRight;
  v17 = v5;
  v6 = &v3->field_84;
  if ( hWnd != v4 )
    v6 = &v3->field_88;
  v18 = v6;
  bVisible = GetWindowLongW(hWnd, -16) >> 28;
  if ( bVisible & 1 )
  {
    v8 = GetScrollInfo;
    v21.cbSize = 28;
    _mm_storeu_si128(&v21.nMin, 0i64);
    v21.nTrackPos = 0;
    v21.fMask = 4;
    if ( a3 )
    {
      GetScrollInfo(hWnd, 2, &v21);
      v21.nPos += a3;
      SetScrollInfo(hWnd, 2, &v21, 1);
      v8 = GetScrollInfo;
    }
    v8(hWnd, 2, &v21);
    bVisible = v21.nPos;
    v19 = v21.nPos;
    if ( v21.nPos != *v6 )
    {
      GetClientRect(v3->m_hWnd, &Rect);
      v9 = *v6 - v19;
      *v18 = v19;
      v10 = v3->m_nBottomScrollBarWidthOrHeight;
      if ( hWnd == v3->m_hWndScrollBarLeftBottom )
      {
        Rect.right = v10 - 1;
        v10 = Rect.left;
      }
      else
      {
        Rect.left = v3->m_nBottomScrollBarWidthOrHeight;
      }
      if ( v9 >= 0 )
      {
        prcScroll.left = v10;
        GetWindowRect(v3->m_hWndHeaderLeft, &v22);
        prcScroll.top = v22.bottom - v22.top;
        prcScroll.right = Rect.right - v9;
        prcScroll.bottom = Rect.bottom - GetSystemMetrics(3);
        if ( hWnd == v3->m_hWndScrollBarRightBottom && (GetWindowLongW(v3->m_hWndScrollBarRightRight, -16) >> 28) & 1 )
        {
          v14 = GetSystemMetrics(2);
          v15 = prcScroll.right - v14;
          prcScroll.right -= v14;
        }
        else
        {
          v15 = prcScroll.right;
        }
        if ( v15 > prcScroll.left )
        {
          ScrollWindowEx(v3->m_hWnd, v9, 0, &prcScroll, 0, 0, 0, 2u);
          v16 = prcScroll.left;
          bVisible = prcScroll.right - prcScroll.left;
          if ( v9 <= prcScroll.right - prcScroll.left )
            goto LABEL_29;
          prcScroll.left = prcScroll.right;
          prcScroll.right = v16 + v9;
          v13 = &prcScroll;
LABEL_28:
          bVisible = InvalidateRect(v3->m_hWnd, v13, 0);
LABEL_29:
          if ( hWnd == v3->m_hWndScrollBarRightBottom )
          {
            GetWindowRect(*v17, &prcScroll);
            MapWindowPoints(0, v3->m_hWnd, &prcScroll, 2u);
            bVisible = SetWindowPos(
                         *v17,
                         0,
                         v9 + prcScroll.left,
                         prcScroll.top,
                         prcScroll.right - (v9 + prcScroll.left),
                         prcScroll.bottom - prcScroll.top,
                         SWP_NOZORDER);
          }
          return bVisible;
        }
      }
      else
      {
        prcScroll.left = v10 - v9;
        GetWindowRect(v3->m_hWndHeaderLeft, &v22);
        prcScroll.top = v22.bottom - v22.top;
        prcScroll.right = Rect.right;
        prcScroll.bottom = Rect.bottom - GetSystemMetrics(3);
        if ( hWnd == v3->m_hWndScrollBarRightBottom && (GetWindowLongW(v3->m_hWndScrollBarRightRight, -16) >> 28) & 1 )
        {
          v11 = GetSystemMetrics(2);
          v12 = prcScroll.right - v11;
          prcScroll.right -= v11;
        }
        else
        {
          v12 = prcScroll.right;
        }
        if ( v12 > prcScroll.left )
        {
          ScrollWindowEx(v3->m_hWnd, v9, 0, &prcScroll, 0, 0, 0, 2u);
          v20 = prcScroll.left;
          bVisible = -v9;
          if ( -v9 <= prcScroll.right - prcScroll.left )
            goto LABEL_29;
          prcScroll.left = prcScroll.right + v9;
          prcScroll.right = v20;
          v13 = &prcScroll;
          goto LABEL_28;
        }
      }
      v13 = &Rect;
      goto LABEL_28;
    }
  }
  return bVisible;
}

//----- (00F9D2A0) --------------------------------------------------------
int __thiscall CTreeList::SetHScrollPos(CTreeList *this, HWND hwnd, int a3)
{
  CTreeList *v3; // edi
  SCROLLINFO v5; // [esp+0h] [ebp-20h]

  _mm_storeu_si128(&v5.nMin, 0i64);
  v5.nPos = a3;
  v3 = this;
  v5.cbSize = 28;
  v5.nTrackPos = 0;
  v5.fMask = 4;
  SetScrollInfo(hwnd, 2, &v5, 1);
  return CTreeList::UpdateHeaderPos(v3, hwnd, 0);
}

//----- (00F9D310) --------------------------------------------------------
void __thiscall sub_F9D310(CTreeList *this, int a2, int a3)
{
  int v3; // esi
  CTreeList *i; // ebx
  int v5; // edi
  int v6; // ST04_4
  int v7; // eax
  bool v8; // zf
  int v9; // eax
  HDITEMW lParam; // [esp+8h] [ebp-2Ch]

  v3 = 0;
  for ( i = this; v3 < a3; ++v3 )
  {
    v5 = a2 + 12 * v3;
    lParam.mask = 7;
    v6 = *(v5 + 4);
    lParam.pszText = *v5;
    v7 = MulDiv(v6, gLogPixelSize.x, 96);
    v8 = *(v5 + 8) == 0;
    lParam.cxy = v7;
    v9 = 0x4000;
    if ( !v8 )
      v9 = 16385;
    lParam.fmt = v9;
    if ( v3 )
    {
      SendMessageW(i->m_hWndHeaderRight, HDM_INSERTITEMW, v3 - 1, &lParam);
    }
    else
    {
      SendMessageW(i->m_hWndHeaderLeft, HDM_INSERTITEMW, 0, &lParam);
      CTreeList::MoveHeaders(i, lParam.cxy);
    }
  }
}

//----- (00F9D3B0) --------------------------------------------------------
char __thiscall CTreeList::OnInited(CTreeList *hData)
{
  CTreeList *v1; // ebx
  HWND v2; // esi
  int v3; // eax
  HWND v4; // eax
  LONG v5; // eax
  HINSTANCE v6; // ST28_4
  HWND hWndHeader; // eax
  HWND v8; // eax
  HINSTANCE v9; // ST28_4
  HWND v10; // eax
  HINSTANCE v11; // ST28_4
  HWND v12; // eax
  HINSTANCE v13; // ST28_4
  HINSTANCE v14; // esi
  HWND v15; // eax
  LONG v16; // eax
  HWND v17; // ST20_4
  HWND v18; // eax
  HWND v19; // ST2C_4
  HGDIOBJ v20; // eax
  HCURSOR v21; // eax
  HWND v22; // ST24_4
  INITCOMMONCONTROLSEX picce; // [esp+Ch] [ebp-20h]
  HINSTANCE hInstance; // [esp+14h] [ebp-18h]
  struct tagRECT Rect; // [esp+18h] [ebp-14h]

  v1 = hData;
  hInstance = GetModuleHandleW(0);
  GetClientRect(v1->m_hWnd, &Rect);
  SetPropW(v1->m_hWnd, gAtomTreeListProperty, v1);
  v2 = v1->m_hWnd;
  if ( v1->baseclass.m_hThemeHandle )
    gpfnCloseThemeData(v1->baseclass.m_hThemeHandle);
  v1->baseclass.m_hThemeHandle = 0;
  if ( gpfnIsThemeActive && gpfnIsThemeActive() )
  {
    v3 = (v1->baseclass.vtptr->GetName)(v1);
    v1->baseclass.m_hThemeHandle = gpfnOpenThemeData(v2, v3);
  }
  v4 = CreateWindowExW(
         0,
         L"SysHeader32",
         &gszNullString,
         0x44000082u,
         0,
         0,
         0,
         0,
         v1->m_hWnd,
         IDC_HEADERCTRL_1_IN_TREELIST,
         hInstance,
         0);
  v1->m_hWndHeaderLeft = v4;
  SetPropW(v4, gAtomTreeListProperty, v1);
  v5 = SetWindowLongW(v1->m_hWndHeaderLeft, -4, CTreeList::Proxy_HeaderWndProc);
  v6 = hInstance;
  v1->m_HeaderWndProc = v5;
  hWndHeader = CreateWindowExW(
                 0,
                 L"SysHeader32",
                 &gszNullString,
                 0x440000C2u,
                 0,
                 0,
                 0,
                 0,
                 v1->m_hWnd,
                 IDC_HEADERCTRL_2_IN_TREELIST,
                 v6,
                 0);
  v1->m_hWndHeaderRight = hWndHeader;
  SetPropW(hWndHeader, gAtomTreeListProperty, v1);
  SetWindowLongW(v1->m_hWndHeaderRight, -4, CTreeList::Proxy_HeaderWndProc);
  v8 = CreateWindowExW(
         0,
         L"ScrollBar",
         &gszNullString,
         0x44000005u,
         0,
         0,
         0,
         0,
         v1->m_hWnd,
         IDC_SCROLLBAR_1_IN_TREELIST,
         hInstance,
         0);
  v9 = hInstance;
  v1->m_hWndScrollBarRightRight = v8;
  v10 = CreateWindowExW(
          0,
          L"ScrollBar",
          &gszNullString,
          0x44000004u,
          0,
          0,
          0,
          0,
          v1->m_hWnd,
          IDC_SCROLLBAR_2_IN_TREELIST,
          v9,
          0);
  v11 = hInstance;
  v1->m_hWndScrollBarLeftBottom = v10;
  v12 = CreateWindowExW(
          0,
          L"ScrollBar",
          &gszNullString,
          0x44000004u,
          0,
          0,
          0,
          0,
          v1->m_hWnd,
          IDC_SCROLLBAR_3_IN_TREELIST,
          v11,
          0);
  v13 = hInstance;
  v1->m_hWndScrollBarRightBottom = v12;
  v1->m_hWndStatic = CreateWindowExW(
                       0,
                       L"Static",
                       &gszNullString,
                       0x44000000u,
                       0,
                       0,
                       0,
                       0,
                       v1->m_hWnd,
                       IDC_STATIC_IN_TREELIST,
                       v13,
                       0);
  picce.dwSize = 8;
  picce.dwICC = 4;
  InitCommonControlsEx(&picce);
  v14 = hInstance;
  v15 = CTreeList::CreateTooltips(hInstance, v1->m_hWnd);
  v1->m_hWndTooltipOfTreeList = v15;
  SetPropW(v15, gAtomTreeListProperty, v1);
  v16 = SetWindowLongW(v1->m_hWndTooltipOfTreeList, -4, CTreeList::Proxy_TooltipWndProc);
  v17 = v1->m_hWnd;
  v1->m_TooltipWndProc = v16;
  SetTimer(v17, 100u, 500u, 0);
  v18 = CTreeList::CreateTooltips(v14, v1->m_hWndHeaderLeft);
  v19 = v1->m_hWndHeaderRight;
  v1->m_hWndTooltipOfLeftHeader = v18;
  v1->m_hWndTooltipOfRightHeader = CTreeList::CreateTooltips(v14, v19);
  v20 = GetStockObject(17);
  SendMessageW(v1->m_hWnd, WM_SETFONT, v20, 0);
  v21 = LoadCursorW(v14, L"SPLITTER_CURSOR");
  v22 = v1->m_hWnd;
  v1->m_hCursor = v21;
  v1->m_dwTreeStyle = 16;
  InvalidateRect(v22, 0, 1);
  return 1;
}
// 1064D84: using guessed type int (__stdcall *gpfnIsThemeActive)();
// 1064DA0: using guessed type __int16 gAtomTreeListProperty;

//----- (00F9D640) --------------------------------------------------------
int *__thiscall sub_F9D640(_DWORD *this, int a2, CListViewData *pListViewData, int (__cdecl *pfnCallback)(int, _DWORD, int, _DWORD), int a5)
{
  _DWORD *v5; // ebx
  int *v6; // eax
  int *v7; // esi
  int **v8; // eax
  int *result; // eax
  int (__cdecl *v10)(int, int, int, _DWORD); // edx
  int *v11; // edi
  int v12; // ecx
  int v13; // eax
  int v14; // eax
  int **v15; // [esp+8h] [ebp-4h]
  int a2a; // [esp+14h] [ebp+8h]

  v5 = this;
  v6 = operator new(sizeof(TreeViewParamInfo));
  v7 = v6;
  if ( v6 )
  {
    *v6 = a2;
    v6[1] = pListViewData;
    v6[2] = v5;
    v6[5] = 0;
    v6[6] = 0;
    v6[7] = 0;
    v6[8] = 0;
    v6[9] = 0;
  }
  else
  {
    v7 = 0;
  }
  v5[8] |= 0x40u;
  v8 = (v5 + 5);
  ++v5[7];
  v15 = (v5 + 5);
  if ( !v5[5] )
  {
    v5[6] = v7;
    *v8 = v7;
    result = v7;
    v7[4] = 0;
    v7[3] = 0;
    return result;
  }
  v10 = pfnCallback;
  if ( pfnCallback )
  {
    v11 = *v8;
    v12 = 0;
    a2a = 0;
    do
    {
      if ( v10 == 1 )
      {
        v13 = v12++;
        a2a = v12;
        if ( v13 == a5 )
          goto LABEL_10;
      }
      else
      {
        if ( v10(pListViewData, v11[1], a5, 0) < 0 )
        {
LABEL_10:
          *v15 = v7;
          v7[3] = v11[3];
          result = v7;
          v7[4] = v11;
          v11[3] = v7;
          return result;
        }
        v12 = a2a;
        v10 = pfnCallback;
      }
      v14 = (v11 + 4);
      v11 = v11[4];
      v15 = v14;
    }
    while ( v11 );
  }
  *(v5[6] + 16) = v7;
  v7[3] = v5[6];
  result = v7;
  v7[4] = 0;
  v5[6] = v7;
  return result;
}

//----- (00F9D750) --------------------------------------------------------
char __thiscall sub_F9D750(CTreeList *this, int a2, int a3)
{
  int v3; // eax
  CTreeList *v4; // edi
  int v5; // ST04_4
  int v6; // eax
  bool v7; // zf
  signed int v8; // eax
  LPARAM lParam; // [esp+8h] [ebp-2Ch]
  int a2a; // [esp+Ch] [ebp-28h]
  int v12; // [esp+10h] [ebp-24h]
  int v13; // [esp+1Ch] [ebp-18h]

  v3 = *a2;
  v4 = this;
  v5 = *(a2 + 4);
  lParam = 7;
  v12 = v3;
  v6 = MulDiv(v5, gLogPixelSize.x, 96);
  v7 = *(a2 + 8) == 0;
  a2a = v6;
  v8 = 0x4000;
  if ( !v7 )
    v8 = 16385;
  v13 = v8;
  if ( a3 )
  {
    SendMessageW(v4->m_hWndHeaderRight, 0x120Au, a3 - 1, &lParam);
  }
  else
  {
    SendMessageW(v4->m_hWndHeaderLeft, 0x120Au, 0, &lParam);
    CTreeList::MoveHeaders(v4, a2a);
  }
  return 1;
}

//----- (00F9D7E0) --------------------------------------------------------
tagTreeViewChildItem *__thiscall sub_F9D7E0(CTreeList *this, int a2, int a3, int (__cdecl *a4)(int, _DWORD, int, _DWORD), int a5)
{
  int *v5; // esi
  CTreeList *v6; // edi
  tagTreeViewChildItem *v7; // eax
  tagTreeViewChildItem *v8; // ebx
  int v9; // eax

  v5 = a2;
  v6 = this;
  if ( !a2 )
    v5 = &this->field_40;
  v7 = sub_F9D640(v5, this, a3, a4, a5);
  v8 = v7;
  if ( v5[8] & 0x10 )
  {
    v9 = CTreeList::FindChild(v6, v7);
    CTreeList::SetVScrollbarPos(v9, 1);
  }
  return v8;
}

//----- (00F9D830) --------------------------------------------------------
int __stdcall CTreeList::SetVScrollbarPos(int yPos, int cy)
{
  CTreeList *v2; // ecx
  CTreeList *this; // edi
  HWND m_hWndScrollBarRightRight; // ST14_4
  int nLine; // esi
  int v6; // ebx
  LONG v7; // ecx
  HWND v8; // ST00_4
  HWND m_hWnd; // ST00_4
  int result; // eax
  struct tagSCROLLINFO ScrollInfo; // [esp+4h] [ebp-40h]
  struct tagRECT Rect; // [esp+20h] [ebp-24h]
  RECT rcScroll; // [esp+30h] [ebp-14h]

  this = v2;
  if ( cy && !v2->m_bSkipTimerForTooltip )
  {
    ScrollInfo.cbSize = 28;
    m_hWndScrollBarRightRight = v2->m_hWndScrollBarRightRight;
    ScrollInfo.nTrackPos = 0;
    _mm_storeu_si128(&ScrollInfo.nMin, 0i64);
    ScrollInfo.fMask = 4;
    GetScrollInfo(m_hWndScrollBarRightRight, 2, &ScrollInfo);
    nLine = CTreeList::GetLineHeight(this);
    GetClientRect(this->m_hWnd, &Rect);
    v6 = cy * nLine;
    GetWindowRect(this->m_hWndHeaderLeft, &rcScroll);
    rcScroll.left = Rect.left;
    rcScroll.right = Rect.right;
    v7 = rcScroll.bottom + nLine * (yPos - ScrollInfo.nPos) - rcScroll.top;
    if ( cy < 0 )
    {
      rcScroll.bottom = Rect.bottom;
      if ( v7 - v6 < Rect.bottom )
      {
        m_hWnd = this->m_hWnd;
        rcScroll.top = v7 - v6;
        ScrollWindowEx(m_hWnd, 0, v6, &rcScroll, 0, 0, 0, SW_INVALIDATE);
        rcScroll.top = v6 + Rect.bottom;
      }
      else
      {
        rcScroll.top = v7;
      }
      InvalidateRect(this->m_hWnd, &rcScroll, 0);
    }
    else
    {
      rcScroll.bottom = Rect.bottom;
      v8 = this->m_hWnd;
      rcScroll.top = v7;
      ScrollWindowEx(v8, 0, v6, &rcScroll, 0, 0, 0, SW_INVALIDATE);
    }
    if ( this->field_9C )
    {
      this->m_nChildWidthLast = CTreeList::GetChildWidth(this, 0);
      CTreeList::RepositionHeaders();
    }
    result = CTreeList::OnSize(this);
  }
  return result;
}

//----- (00F9D980) --------------------------------------------------------
bool __thiscall sub_F9D980(_DWORD *this, int a2)
{
  _DWORD *v2; // ebx
  HWND v3; // ST00_4
  HDC v4; // esi
  LONG v5; // edi
  int v6; // eax
  int v7; // esi
  struct tagTEXTMETRICW tm; // [esp+Ch] [ebp-7Ch]
  struct tagRECT v10; // [esp+48h] [ebp-40h]
  struct tagRECT Rect; // [esp+58h] [ebp-30h]
  struct tagSCROLLINFO v12; // [esp+68h] [ebp-20h]

  v12.cbSize = 28;
  v2 = this;
  v12.nTrackPos = 0;
  v12.fMask = 4;
  v3 = this[7];
  _mm_storeu_si128(&v12.nMin, 0i64);
  GetScrollInfo(v3, 2, &v12);
  v4 = GetDC(v2[2]);
  SelectObject(v4, v2[12]);
  GetTextMetricsW(v4, &tm);
  v5 = tm.tmHeight;
  ReleaseDC(v2[2], v4);
  if ( v2[14] )
  {
    v6 = GetSystemMetrics(50);
    if ( v5 < v6 )
      v5 = v6;
  }
  v7 = v5 + v2[26];
  GetWindowRect(v2[3], &Rect);
  GetClientRect(v2[2], &v10);
  return a2 >= v12.nPos && a2 <= v12.nPos + (v10.bottom + Rect.top - Rect.bottom) / v7;
}

//----- (00F9DA70) --------------------------------------------------------
tagTreeViewChildItem *__thiscall TreeViewChildItem_GetChild(tagTreeViewChildItem *pItem, int nPos)
{
  int nPos_1; // esi
  tagTreeViewChildItem *v3; // eax
  tagTreeViewChildItem *i; // edx
  tagTreeViewChildItem *pCurrent; // ecx

  if ( !pItem )
    return 0;
  nPos_1 = nPos;
  while ( nPos_1 < 0 )
  {
    v3 = pItem->m_Item0C;
    if ( v3 )
    {
      pItem = pItem->m_Item0C;
      for ( i = v3->m_Item18; i; i = i->m_Item18 )
      {
        if ( !((pItem->m_dwStyle >> 4) & 1) )
          break;
        pItem = i;
      }
    }
    else
    {
      pItem = pItem->m_Current;
      if ( pItem && !pItem->m_TreeListData )
        return 0;
    }
    ++nPos_1;
    if ( !pItem )
      return 0;
  }
  for ( ; pItem; --nPos_1 )
  {
    if ( nPos_1 <= 0 )
      break;
    if ( pItem->m_Next && (pItem->m_dwStyle >> 4) & 1 )
    {
      pItem = pItem->m_Next;
    }
    else if ( pItem->m_Prev )
    {
      pItem = pItem->m_Prev;
    }
    else
    {
      pCurrent = pItem->m_Current;
      if ( pCurrent )
      {
        while ( !pCurrent->m_Prev )
        {
          pCurrent = pCurrent->m_Current;
          if ( !pCurrent )
            goto LABEL_24;
        }
        pItem = pCurrent->m_Prev;
      }
      else
      {
LABEL_24:
        pItem = 0;
      }
    }
  }
  return pItem;
}

//----- (00F9DB30) --------------------------------------------------------
int __thiscall CTreeList::GetLineHeight(CTreeList *this)
{
  CTreeList *v1; // ebx
  HDC v2; // esi
  LONG v3; // edi
  int v4; // eax
  struct tagTEXTMETRICW tm; // [esp+Ch] [ebp-40h]

  v1 = this;
  v2 = GetDC(this->m_hWnd);
  SelectObject(v2, v1->m_Font);
  GetTextMetricsW(v2, &tm);
  v3 = tm.tmHeight;
  ReleaseDC(v1->m_hWnd, v2);
  if ( v1->m_ImageList )
  {
    v4 = GetSystemMetrics(SM_CYSMICON);
    if ( v3 < v4 )
      v3 = v4;
  }
  return v3 + v1->m_nHeight;
}

//----- (00F9DBA0) --------------------------------------------------------
int __cdecl pfnCallback(CListViewData *pListViewData, int a2, int a3)
{
  return (a3)(pListViewData->m_Value, *(a2 + 4));
}

//----- (00F9DBC0) --------------------------------------------------------
int __cdecl sub_F9DBC0(int a1, int a2, int (__stdcall *a3)(_DWORD, _DWORD, int), int a4)
{
  return a3(*(a1 + 4), *(a2 + 4), a4);
}

//----- (00F9DBE0) --------------------------------------------------------
HWND __thiscall CTreeList::HandleListViewMsg(CTreeList *this, HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
  CTreeList *v5; // ebx
  HWND result; // eax
  int v7; // ST0C_4
  bool v8; // zf
  int v9; // eax
  LRESULT v10; // eax
  LONG v11; // ecx
  signed int v12; // ecx
  LONG v13; // edx
  LPARAM v14; // ecx
  int v15; // eax
  int v16; // eax
  int v17; // edx
  int v18; // edx
  unsigned int v19; // edx
  int v20; // eax
  int v21; // eax
  signed int v22; // eax
  __m128i v23; // xmm1
  const __m128i *v24; // ecx
  __m128i v25; // xmm0
  LRESULT v26; // esi
  int v27; // eax
  signed int v28; // esi
  int v29; // ecx
  int v30; // edx
  int v31; // edx
  __m128i v32; // xmm1
  const __m128i *v33; // eax
  __m128i v34; // xmm0
  _DWORD *v35; // eax
  int v36; // ecx
  tagTreeViewChildItem *v37; // eax
  tagTreeViewChildItem *v38; // eax
  tagTreeViewChildItem *v39; // eax
  const wchar_t *v40; // eax
  wchar_t *v41; // ecx
  int v42; // ST14_4
  tagTreeViewChildItem *v43; // ecx
  tagTreeViewChildItem *v44; // eax
  tagTreeViewChildItem *v45; // esi
  char v46; // bl
  CTreeListData *v47; // ecx
  int v48; // ST10_4
  CTreeListData *v49; // ecx
  tagTreeViewChildItem *v50; // ecx
  WPARAM v51; // esi
  LONG v52; // ebx
  tagTreeViewChildItem *v53; // ecx
  unsigned int v54; // eax
  tagTreeViewChildItem *v55; // eax
  tagTreeViewChildItem *v56; // edx
  int i; // ecx
  tagTreeViewChildItem *v58; // eax
  int v59; // ST14_4
  tagTreeViewChildItem *v60; // ecx
  tagTreeViewChildItem *v61; // eax
  char v62; // dl
  LPARAM a5a; // [esp+Ch] [ebp-4Ch]
  WPARAM v64; // [esp+10h] [ebp-48h]
  LPARAM lParam2; // [esp+14h] [ebp-44h]
  __int128 v66; // [esp+18h] [ebp-40h]
  __int128 v67; // [esp+28h] [ebp-30h]
  __int64 v68; // [esp+38h] [ebp-20h]
  int v69; // [esp+40h] [ebp-18h]
  LPARAM v70; // [esp+44h] [ebp-14h]
  int v71; // [esp+48h] [ebp-10h]
  __int64 v72; // [esp+4Ch] [ebp-Ch]

  v5 = this;
  v69 = wParam;
  switch ( Msg )
  {
    case LVM_GETITEMCOUNT:
      return CTreeList::GetLineHeight(this);
    case LVM_DELETEITEM:
      if ( !this->m_nChildCount )
        return 0;
      v38 = TreeViewChildItem_GetChild(this->m_Child, wParam);
      if ( !v38 )
        return 0;
      sub_F9A7D0(v5, v38);
      return 1;
    case LVM_DELETEALLITEMS:
      CTreeList::OnDestroy(this);
      return 1;
    case LVM_GETNEXTITEM:
      if ( !this->m_nChildCount )
        return HWND_MESSAGE|0x2;
      v51 = wParam + 1;
      v58 = TreeViewChildItem_GetChild(this->m_Child, wParam + 1);
      if ( lParam != 2 || !v58 )
        return HWND_MESSAGE|0x2;
      while ( !(v58->m_dwStyle & 1) )
      {
        v58 = sub_F9E650(v58);
        ++v51;
        if ( !v58 )
          return HWND_MESSAGE|0x2;
      }
      return v51;
    case LVM_GETITEMRECT:
      if ( *lParam )
        return 0;
      sub_F9C550(this, wParam, lParam);
      return 1;
    case LVM_HITTEST:
      if ( !(CTreeList::Query(this, *lParam, *(lParam + 4), (lParam + 12), (lParam + 16), 0) & 0xE0) )
        return HWND_MESSAGE|0x2;
      return *(lParam + 12);
    case LVM_ENSUREVISIBLE:
      sub_F9BE30(this, wParam);
      return 1;
    case LVM_REDRAWITEMS:
      CTreeList::RedrawZone(this, wParam, lParam);
      return 1;
    case LVM_DELETECOLUMN:
      return sub_F9A690(this, wParam);
    case LVM_GETCOLUMNWIDTH:
      if ( !CTreeList::MapToHeader(this, wParam, &v70) )
        return 0;
      return (v72 - v70);
    case LVM_GETHEADER:
      return this->m_hWndHeaderLeft;
    case LVM_SETITEMSTATE:
      *&v66 = *(lParam + 12);
      a5a = 8;
      v64 = wParam;
      lParam2 = 0;
      return CTreeList::HandleListViewMsg(this, hWnd, 0x104Cu, wParam, &a5a);
    case LVM_SORTITEMS:
      v53 = this->m_Child;
      if ( v53 && v53 != v5->field_58 )
      {
        v54 = sub_F9F500(&v5->m_Child, v5->m_nChildCount, sub_F9DBC0, lParam, wParam, 0);
        v5->m_Child = v54;
        *(v54 + 12) = 0;
        v55 = v5->m_Child;
        v56 = v55->m_Prev;
        for ( i = &v55->m_Prev; v56; i = *i + 16 )
        {
          v56->m_Item0C = v55;
          v55 = *i;
          v56 = *(*i + 16);
        }
        v5->field_58 = v55;
      }
      InvalidateRect(v5->m_hWnd, 0, 0);
      return 1;
    case LVM_GETSUBITEMRECT:
      if ( *lParam && *lParam != 2 )
        return 0;
      return sub_F9C210(this, wParam, *(lParam + 4), 1, 0, 0, lParam);
    case LVM_SETCOLUMNORDERARRAY:
      if ( wParam <= 1 )
        return ((wParam & 0x80000000) == 0);
      v22 = 1;
      if ( wParam - 1 >= 8 )
      {
        v23 = _mm_load_si128(&stru_1034280);
        v24 = (lParam + 4);
        do
        {
          v25 = _mm_loadu_si128(v24);
          v22 += 8;
          v24 += 2;
          _mm_storeu_si128(&v24[-2], _mm_sub_epi32(v25, v23));
          _mm_storeu_si128(&v24[-1], _mm_sub_epi32(_mm_loadu_si128(v24 - 1), v23));
        }
        while ( v22 < (wParam - (wParam - 1) % 8) );
      }
      for ( ; v22 < wParam; ++v22 )
        --*(lParam + 4 * v22);
      return SendMessageW(v5->m_hWndHeaderRight, 0x1212u, wParam - 1, lParam + 4);
    case LVM_GETCOLUMNORDERARRAY:
      v26 = SendMessageW(this->m_hWndHeaderLeft, 0x1200u, 0, 0);
      v27 = v26 + SendMessageW(v5->m_hWndHeaderRight, 0x1200u, 0, 0);
      v28 = v69;
      if ( v69 != v27 )
        return 0;
      if ( v69 <= 0 )
        return 1;
      *lParam = 0;
      result = SendMessageW(v5->m_hWndHeaderRight, 0x1211u, v28 - 1, lParam + 4);
      v29 = 1;
      v69 = result;
      v30 = v28 - 1;
      if ( v28 > 1 )
      {
        if ( v30 >= 8 )
        {
          v31 = v30 % 8;
          v32 = _mm_load_si128(&stru_1034280);
          v33 = (lParam + 4);
          do
          {
            v34 = _mm_loadu_si128(v33);
            v29 += 8;
            v33 += 2;
            _mm_storeu_si128(&v33[-2], _mm_add_epi32(v34, v32));
            _mm_storeu_si128(&v33[-1], _mm_add_epi32(_mm_loadu_si128(v33 - 1), v32));
          }
          while ( v29 < v28 - v31 );
          result = v69;
        }
        for ( ; v29 < v28; ++v29 )
          ++*(lParam + 4 * v29);
      }
      return result;
    case LVM_GETITEMW:
      if ( !this->m_nChildCount )
        return 0;
      v42 = *(lParam + 4);
      v43 = this->m_Child;
      v69 = *lParam;
      v44 = TreeViewChildItem_GetChild(v43, v42);
      v45 = v44;
      if ( !v44 )
        return 0;
      v46 = v69;
      if ( v69 & 1 )
      {
        v47 = v44->m_TreeListData;
        v46 = v69 & 0xFE;
        v48 = *(lParam + 20);
        v69 = *(lParam + 24);
        *(lParam + 20) = (v47->vtptr->GetItemText)(v44, *(lParam + 8), v48, &v69);
      }
      if ( v46 & 8 )
      {
        v46 &= 0xF7u;
        *(lParam + 12) = 0;
        if ( v45->m_dwStyle & 1 )
          *(lParam + 12) = 2;
      }
      if ( v46 & 4 )
      {
        v46 &= 0xFBu;
        *(lParam + 32) = v45->m_TreeListData->m_dwValue;
      }
      if ( v46 & 2 )
      {
        v49 = v45->m_TreeListData;
        v69 = 0;
        *(lParam + 28) = (v49->vtptr->field_C)(v45, &v69);
      }
      return 1;
    case LVM_SETITEMW:
      if ( !this->m_nChildCount )
        return 0;
      v59 = *(lParam + 4);
      v60 = this->m_Child;
      v69 = *lParam;
      v61 = TreeViewChildItem_GetChild(v60, v59);
      if ( !v61 )
        return 0;
      v62 = v69;
      if ( v69 & 4 )
      {
        v62 = v69 & 0xFB;
        v61->m_TreeListData->m_dwValue = *(lParam + 32);
      }
      if ( !(v62 & 8) )
        return 1;
      if ( v61->m_dwStyle & 1 )
      {
        if ( !(*(lParam + 12) & 3) )
        {
          CTreeList::RedrawChild(v5, 0);
          return 1;
        }
        return 1;
      }
      if ( !(*(lParam + 12) & 3) )
        return 1;
      CTreeList::RedrawChild(v5, v61);
      return 1;
    case LVM_INSERTITEMW:
      v69 = *(lParam + 4);
      v35 = operator new(8u);
      if ( v35 )
      {
        v36 = *(lParam + 32);
        *v35 = &CListViewData::`vftable';
        v35[1] = v36;
      }
      else
      {
        v35 = 0;
      }
      v37 = sub_F9D7E0(v5, wParam, v35, 1, v69);
      return CTreeList::FindChild(v5, v37);
    case LVM_FINDITEMW:
      v50 = this->m_Child;
      v51 = 0;
      if ( !v50 )
        return HWND_MESSAGE|0x2;
      v52 = *lParam;
      while ( v52 != 1 || v50->m_TreeListData->m_dwValue != *(lParam + 8) )
      {
        ++v51;
        v50 = sub_F9E650(v50);
        if ( !v50 )
          return HWND_MESSAGE|0x2;
      }
      return v51;
    case LVM_GETCOLUMNW:
      v8 = (*lParam & 4) == 0;
      _mm_storeu_si128(&v66, 0i64);
      lParam2 = 5;
      _mm_storeu_si128(&v67, 0i64);
      v68 = 0i64;
      if ( !v8 )
      {
        DWORD1(v66) = *(lParam + 12);
        v9 = *(lParam + 16);
        lParam2 = 7;
        HIDWORD(v66) = v9;
      }
      if ( wParam )
        v10 = SendMessageW(this->m_hWndHeaderRight, 0x120Bu, wParam - 1, &lParam2);
      else
        v10 = SendMessageW(this->m_hWndHeaderLeft, 0x120Bu, 0, &lParam2);
      if ( !v10 )
        return 0;
      v11 = *lParam;
      if ( *lParam & 2 )
        *(lParam + 8) = v66;
      result = 1;
      if ( v11 & 1 )
      {
        v12 = 0;
        if ( v67 & 1 )
          v12 = 1;
        *(lParam + 4) = v12;
      }
      return result;
    case LVM_SETCOLUMNW:
      v13 = *lParam;
      v14 = 0;
      v68 = 0i64;
      lParam2 = 0;
      _mm_storeu_si128(&v66, 0i64);
      _mm_storeu_si128(&v67, 0i64);
      if ( v13 & 2 )
      {
        v15 = *(lParam + 8);
        v14 = 1;
        lParam2 = 1;
        LODWORD(v66) = v15;
      }
      if ( v13 & 1 )
      {
        v16 = *(lParam + 4);
        v14 |= 4u;
        v17 = *(lParam + 4) & 1;
        lParam2 = v14;
        v18 = v17 | 0x4000;
        if ( v16 & 0x800 )
          v19 = v18 | 0x1800;
        else
          v19 = v18 & 0xFFFFE7FF;
        LODWORD(v67) = v19;
        v13 = *lParam;
      }
      if ( v13 & 4 )
      {
        v20 = *(lParam + 12);
        v14 |= 2u;
        lParam2 = v14;
        DWORD1(v66) = v20;
      }
      if ( v13 & 0x10 )
      {
        v21 = *(lParam + 24);
        lParam2 = v14 | 0x20;
        DWORD2(v67) = v21;
      }
      if ( wParam )
        result = SendMessageW(v5->m_hWndHeaderRight, 0x120Cu, wParam - 1, &lParam2);
      else
        result = SendMessageW(v5->m_hWndHeaderLeft, 0x120Cu, 0, &lParam2);
      return result;
    case LVM_INSERTCOLUMNW:
      v7 = *(lParam + 8);
      v72 = 0i64;
      LODWORD(v72) = MulDiv(v7, 96, gLogPixelSize.x);
      v71 = *(lParam + 12);
      HIDWORD(v72) = *(lParam + 4) & 1;
      return sub_F9D750(v5, &v71, wParam);
    case LVM_GETITEMTEXTW:
      if ( !this->m_nChildCount )
        return 0;
      v39 = TreeViewChildItem_GetChild(this->m_Child, wParam);
      if ( !v39 )
        return 0;
      v69 = *(lParam + 24);
      v40 = (v39->m_TreeListData->vtptr->GetItemText)(v39, *(lParam + 8), *(lParam + 20), &v69);
      v41 = *(lParam + 20);
      if ( v40 != v41 )
        wcsncpy_s(v41, *(lParam + 24), v40, 0xFFFFFFFF);
      return 1;
    case LVM_SETITEMTEXTW:
      return (*(lParam + 20) == -1);
    case LVM_ISITEMVISIBLE:
      return sub_F9D980(this, wParam);
    default:
      return DefWindowProcW(hWnd, Msg, wParam, lParam);
  }
}
// 1034268: using guessed type void *CListViewData::`vftable';
// 1034280: using guessed type RECT stru_1034280;

//----- (00F9E5D0) --------------------------------------------------------
int __stdcall sub_F9E5D0(int a1)
{
  return *(*(a1 + 4) + 4);
}

//----- (00F9E5E0) --------------------------------------------------------
int __stdcall CTreeList::OnMsg2004(int a1, int a2, int a5)
{
  CTreeList *v3; // ecx
  CTreeList *v4; // edi
  CListViewData *pListViewData; // eax
  int v6; // esi
  tagTreeViewChildItem *v7; // eax
  int v8; // ebx
  int v9; // eax

  v4 = v3;
  pListViewData = operator new(8u);
  if ( pListViewData )
  {
    pListViewData->vtptr = &CListViewData::`vftable';
    pListViewData->m_Value = a2;
  }
  else
  {
    pListViewData = 0;
  }
  v6 = a1;
  if ( !a1 )
    v6 = &v4->field_40;
  v7 = sub_F9D640(v6, v4, pListViewData, pfnCallback, a5);
  v8 = v7;
  if ( *(v6 + 0x20) & 0x10 )
  {
    v9 = CTreeList::FindChild(v4, v7);
    CTreeList::SetVScrollbarPos(v9, 1);
  }
  return v8;
}
// 1034268: using guessed type void *CListViewData::`vftable';

//----- (00F9E650) --------------------------------------------------------
int __thiscall sub_F9E650(_DWORD *this)
{
  int result; // eax
  int v2; // eax

  result = this[5];
  if ( !result || !((this[8] >> 4) & 1) )
  {
    result = this[4];
    if ( !result )
    {
      v2 = this[2];
      if ( v2 )
      {
        while ( !*(v2 + 16) )
        {
          v2 = *(v2 + 8);
          if ( !v2 )
            goto LABEL_7;
        }
        result = *(v2 + 16);
      }
      else
      {
LABEL_7:
        result = 0;
      }
    }
  }
  return result;
}

//----- (00F9E690) --------------------------------------------------------
int __thiscall CTreeList::SendNotifyEx(CTreeList *this, HWND hWndParent, TVNMHDR *pNMHDR)
{
  tagTreeViewChildItem *pSibling; // edi
  CTreeListData *pTreeListData; // ebx
  UINT code; // eax
  UINT v6; // eax
  tagTreeViewChildItem *v7; // edi
  CTreeListData *v8; // eax
  HWND v9; // edi
  int result; // eax
  tagTreeViewChildItem *v11; // eax
  UINT v12; // ST08_4
  UINT v13; // eax
  TVNMHDR lParam; // [esp+Ch] [ebp-34h]
  int v15; // [esp+28h] [ebp-18h]
  int v16; // [esp+2Ch] [ebp-14h]
  __int64 v17; // [esp+34h] [ebp-Ch]
  CTreeList *pThis; // [esp+3Ch] [ebp-4h]

  pThis = this;
  pSibling = pNMHDR->pTo;
  if ( pSibling )
    pTreeListData = pSibling->m_TreeListData;
  else
    pTreeListData = 0;
  code = pNMHDR->nmhdr.code;
  if ( code > 2005 )
  {
    if ( code > -5 )
    {
      if ( code + 3 > 1 )
        return SendMessageW(hWndParent, WM_NOTIFY, pNMHDR->nmhdr.idFrom, pNMHDR);
    }
    else if ( code != -5 )
    {
      if ( code == 2006 )
      {
        _mm_storeu_si128(&lParam.nmhdr.code, 0i64);
        lParam.pFrom = 2006;
        _mm_storeu_si128(&lParam.nItem2, 0i64);
        v17 = 0i64;
        *&lParam.nmhdr.idFrom = *&pNMHDR->nmhdr.hwndFrom;
        lParam.pFrom = LVN_DELETEITEM;
        lParam.pTo = CTreeList::FindChild(this, pSibling);
        HIDWORD(v17) = pTreeListData->m_dwValue;
        SendMessageW(hWndParent, WM_NOTIFY, lParam.nmhdr.code, &lParam.nmhdr.idFrom);
        return 0;
      }
      return SendMessageW(hWndParent, WM_NOTIFY, pNMHDR->nmhdr.idFrom, pNMHDR);
    }
    memset(&lParam.nmhdr.idFrom, 0, 0x2Cu);
    v13 = pNMHDR->nmhdr.code;
    *&lParam.nmhdr.hwndFrom = *&pNMHDR->nmhdr.hwndFrom;
    lParam.nmhdr.code = v13;
    if ( pSibling )
      lParam.pFrom = CTreeList::FindChild(pThis, pSibling);
    else
      lParam.pFrom = -1;
    lParam.pTo = pNMHDR->nItem1;
    if ( pTreeListData )
      LODWORD(v17) = pTreeListData->m_dwValue;
    else
      LODWORD(v17) = 0;
    return SendMessageW(hWndParent, WM_NOTIFY, lParam.nmhdr.idFrom, &lParam);
  }
  if ( code >= 2004 )
    return SendMessageW(hWndParent, WM_NOTIFY, pNMHDR->nmhdr.idFrom, pNMHDR);
  switch ( code )
  {
    case 2000u:
      v6 = pNMHDR->nmhdr.code;
      v7 = pNMHDR->pFrom;
      v17 = 0i64;
      _mm_storeu_si128(&lParam.nmhdr.code, 0i64);
      lParam.pFrom = LVN_ITEMCHANGED;
      _mm_storeu_si128(&lParam.nItem2, 0i64);
      *&lParam.nmhdr.idFrom = *&pNMHDR->nmhdr.hwndFrom;
      if ( v7 )
      {
        lParam.pTo = CTreeList::FindChild(this, v7);
        v8 = v7->m_TreeListData;
        v9 = hWndParent;
        HIDWORD(v17) = v8->m_dwValue;
        v15 = 3;
        lParam.nItem2 = 0;
        v16 = 3;
        SendMessageW(hWndParent, WM_NOTIFY, lParam.nmhdr.code, &lParam.nmhdr.idFrom);
        this = pThis;
      }
      else
      {
        v9 = hWndParent;
      }
      if ( pNMHDR->pTo )
      {
        lParam.pTo = CTreeList::FindChild(this, pNMHDR->pTo);
        HIDWORD(v17) = pTreeListData->m_dwValue;
        lParam.nItem2 = 0;
        v15 = 3;
        v16 = 3;
        SendMessageW(v9, WM_NOTIFY, lParam.nmhdr.code, &lParam.nmhdr.idFrom);
      }
      result = 0;
      break;
    case 2003u:
      v11 = pNMHDR->nmhdr.code;
      _mm_storeu_si128(&lParam.nmhdr.code, 0i64);
      lParam.pFrom = v11;
      lParam.nItem1 = pNMHDR->nItem1;
      v12 = pNMHDR->nmhdr.idFrom;
      _mm_storeu_si128(&lParam.nItem2, 0i64);
      v17 = 0i64;
      *&lParam.nmhdr.idFrom = *&pNMHDR->nmhdr.hwndFrom;
      lParam.pFrom = LVN_COLUMNCLICK;
      lParam.pTo = -1;
      SendMessageW(hWndParent, WM_NOTIFY, v12, &lParam.nmhdr.idFrom);
      result = 0;
      break;
    default:
      return SendMessageW(hWndParent, WM_NOTIFY, pNMHDR->nmhdr.idFrom, pNMHDR);
  }
  return result;
}

//----- (00F9E900) --------------------------------------------------------
BOOL __thiscall sub_F9E900(_DWORD *this, int a2, int a3, int a4, int a5, const __m128i *a6)
{
  _DWORD *v6; // ST20_4
  CTreeList *v7; // ST1C_4
  signed int v8; // edi
  LONG v9; // eax
  __m128i v10; // xmm0
  WPARAM v11; // ST08_4
  HWND v12; // eax
  LPARAM lParam; // [esp+18h] [ebp-34h]
  LONG v15; // [esp+1Ch] [ebp-30h]
  int v16; // [esp+20h] [ebp-2Ch]
  int v17; // [esp+24h] [ebp-28h]
  int v18; // [esp+28h] [ebp-24h]
  HWND v19; // [esp+2Ch] [ebp-20h]
  int v20; // [esp+30h] [ebp-1Ch]
  __int128 v21; // [esp+34h] [ebp-18h]
  int v22; // [esp+44h] [ebp-8h]

  v6 = this;
  v7 = *a2;
  v8 = CTreeList::FindChild(*a2, a2);
  lParam = 0;
  memset(&v15, 0, 0x2Cu);
  v20 = a3;
  v9 = GetWindowLongW(v7->m_hWnd, -12);
  v10 = _mm_loadu_si128(a6);
  lParam = 102;
  v15 = v9;
  v19 = v7->m_hWnd;
  v18 = *(a2 + 32);
  _mm_storeu_si128(&v21, v10);
  v16 = v8;
  v17 = a4;
  v22 = v6[1];
  v11 = v9;
  v12 = GetParent(v7->m_hWnd);
  return SendMessageW(v12, 0x2Bu, v11, &lParam) != 0;
}

//----- (00F9E9C0) --------------------------------------------------------
char __stdcall sub_F9E9C0(int a1, int a2, int a3, int a4, int a5)
{
  return 0;
}

//----- (00F9E9D0) --------------------------------------------------------
int __thiscall sub_F9E9D0(_DWORD *this)
{
  int v1; // edx
  int i; // ecx
  int result; // eax

  v1 = this[3];
  if ( v1 )
  {
    for ( i = *(v1 + 24); i; i = *(i + 24) )
    {
      if ( !((*(v1 + 32) >> 4) & 1) )
        break;
      v1 = i;
    }
    result = v1;
  }
  else
  {
    result = this[2];
    if ( result && !*(result + 4) )
      result = 0;
  }
  return result;
}

//----- (00F9EA10) --------------------------------------------------------
int __thiscall CTreeList::Refresh(CTreeList *this)
{
  CTreeList *v1; // edi

  v1 = this;
  InvalidateRect(this->m_hWnd, 0, 0);
  InvalidateRect(v1->m_hWndHeaderLeft, 0, 0);
  InvalidateRect(v1->m_hWndHeaderRight, 0, 0);
  v1->m_nChildWidthLast = CTreeList::GetChildWidth(v1, 0);
  CTreeList::OnSize(v1);
  CTreeList::RepositionHeaders();
  return CTreeList::RepositionTooltips();
}

//----- (00F9EA60) --------------------------------------------------------
BOOL __thiscall CTreeList::RefreshHeaderItem(CTreeList *this, int nItem)
{
  CTreeList *v2; // esi
  BOOL result; // eax
  RECT lParam; // [esp+4h] [ebp-14h]

  v2 = this;
  if ( nItem )
  {
    SendMessageW(this->m_hWndHeaderRight, HDM_GETITEMRECT, nItem - 1, &lParam);
    result = InvalidateRect(v2->m_hWndHeaderRight, &lParam, 0);
  }
  else
  {
    SendMessageW(this->m_hWndHeaderLeft, HDM_GETITEMRECT, 0, &lParam);
    result = InvalidateRect(v2->m_hWndHeaderLeft, &lParam, 0);
  }
  return result;
}

//----- (00F9EAD0) --------------------------------------------------------
int __thiscall CTreeList::RefreshChildItem(CTreeList *thisIn, tagTreeViewChildItem *pChild)
{
  CTreeList *v2; // esi
  int result; // eax

  v2 = thisIn;
  result = CTreeList::FindChild(thisIn, pChild);
  if ( result >= 0 )
    CTreeList::RedrawZone(v2, result, result);
  return result;
}

//----- (00F9EAF0) --------------------------------------------------------
void __thiscall CTreeList::RedrawZone(CTreeList *thisIn, int nStart, int nEnd)
{
  CTreeList *v3; // ebx
  HWND m_hWndScrollBarRightRight; // ST00_4
  HDC hDC; // esi
  LONG nHeigth; // ebx
  int v7; // eax
  int nTotalHeight; // esi
  CTreeList *this; // [esp+8h] [ebp-80h]
  struct tagTEXTMETRICW tm; // [esp+Ch] [ebp-7Ch]
  struct tagRECT Rect; // [esp+48h] [ebp-40h]
  struct tagSCROLLINFO ScrollInfo; // [esp+58h] [ebp-30h]
  RECT rcClient; // [esp+74h] [ebp-14h]

  v3 = thisIn;
  this = thisIn;
  if ( nEnd >= nStart )
  {
    ScrollInfo.cbSize = sizeof(SCROLLINFO);
    m_hWndScrollBarRightRight = thisIn->m_hWndScrollBarRightRight;
    ScrollInfo.nTrackPos = 0;
    _mm_storeu_si128(&ScrollInfo.nMin, 0i64);
    ScrollInfo.fMask = SIF_POS;
    GetScrollInfo(m_hWndScrollBarRightRight, SB_CTL, &ScrollInfo);
    hDC = GetDC(v3->m_hWnd);
    SelectObject(hDC, v3->m_Font);
    GetTextMetricsW(hDC, &tm);
    nHeigth = tm.tmHeight;
    ReleaseDC(this->m_hWnd, hDC);
    if ( this->m_ImageList )
    {
      v7 = GetSystemMetrics(SM_CYSMICON);
      if ( nHeigth < v7 )
        nHeigth = v7;
    }
    nTotalHeight = nHeigth + this->m_nHeight;
    GetWindowRect(this->m_hWndHeaderLeft, &Rect);
    GetClientRect(this->m_hWnd, &rcClient);
    rcClient.top = Rect.bottom + nTotalHeight * (nStart - ScrollInfo.nPos) - Rect.top;
    rcClient.bottom = Rect.bottom
                    + nTotalHeight * (nStart - ScrollInfo.nPos)
                    - Rect.top
                    + nTotalHeight * (nEnd - nStart + 1);
    InvalidateRect(this->m_hWnd, &rcClient, 0);
  }
}

//----- (00F9EBF0) --------------------------------------------------------
ATOM CTreeList::Register()
{
  WNDCLASSEXW v1; // [esp+0h] [ebp-30h]

  memset(&v1.style, 0, 0x2Cu);
  v1.cbSize = 48;
  v1.lpfnWndProc = CTreeList::WndProc;
  v1.hCursor = LoadCursorW(0, 0x7F00);
  v1.hbrBackground = 0;
  v1.lpszMenuName = 0;
  v1.style = 8;
  v1.lpszClassName = L"TreeListWindowClass";
  return RegisterClassExW(&v1);
}
// 10341A4: using guessed type wchar_t aTreelistwindow[20];

//----- (00F9EC50) --------------------------------------------------------
int __cdecl CTreeList::RepositionTooltips()
{
  CTreeList *v0; // ecx
  CTreeList *this; // esi
  HWND m_hWndScrollBarRightBottom; // ST10_4
  HWND m_hWndScrollBarRightRight; // ST14_4
  int v4; // eax
  LONG right; // edx
  HWND m_hWndHeaderRight; // eax
  tagTOOLINFOW ToolInfo; // [esp+4h] [ebp-70h]
  struct tagRECT rcClient; // [esp+34h] [ebp-40h]
  struct tagSCROLLINFO ScrollInfo; // [esp+44h] [ebp-30h]
  struct tagRECT rcWindow; // [esp+60h] [ebp-14h]

  this = v0;
  GetClientRect(v0->m_hWnd, &rcClient);
  GetWindowRect(this->m_hWndHeaderRight, &rcWindow);
  ScrollInfo.cbSize = sizeof(SCROLLINFO);
  m_hWndScrollBarRightBottom = this->m_hWndScrollBarRightBottom;
  ScrollInfo.nTrackPos = 0;
  _mm_storeu_si128(&ScrollInfo.nMin, 0i64);
  ScrollInfo.fMask = SIF_POS;
  GetScrollInfo(m_hWndScrollBarRightBottom, SB_CTL, &ScrollInfo);
  rcWindow.left = this->m_nBottomScrollBarWidthOrHeight - ScrollInfo.nPos;
  m_hWndScrollBarRightRight = this->m_hWndScrollBarRightRight;
  rcWindow.right = rcClient.right - rcClient.left;
  rcWindow.bottom -= rcWindow.top;
  rcWindow.top = 0;
  if ( (GetWindowLongW(m_hWndScrollBarRightRight, -16) >> 28) & 1 )
  {
    v4 = GetSystemMetrics(SM_CXVSCROLL);
    right = rcWindow.right - v4;
    rcWindow.right -= v4;
  }
  else
  {
    right = rcWindow.right;
  }
  SetWindowPos(
    this->m_hWndHeaderRight,
    0,
    rcWindow.left,
    rcWindow.top,
    right - rcWindow.left,
    rcWindow.bottom - rcWindow.top,
    SWP_NOZORDER);
  m_hWndHeaderRight = this->m_hWndHeaderRight;
  ToolInfo.cbSize = 0x30;
  _mm_storeu_si128(&ToolInfo.hwnd, 0i64);
  ToolInfo.uFlags = 0;
  _mm_storeu_si128(&ToolInfo.rect.right, 0i64);
  ToolInfo.hwnd = m_hWndHeaderRight;
  *&ToolInfo.lParam = 0i64;
  GetClientRect(m_hWndHeaderRight, &ToolInfo.rect);
  // Sets a new bounding rectangle for a tool
  return SendMessageW(this->m_hWndTooltipOfRightHeader, TTM_NEWTOOLRECTW, 0, &ToolInfo);
}

//----- (00F9ED70) --------------------------------------------------------
LRESULT __thiscall CTreeList::MoveHeaders(CTreeList *this, int a2)
{
  CTreeList *v2; // ebx
  HWND v3; // ST10_4
  LONG v4; // edx
  HWND v5; // ST00_4
  HWND v6; // eax
  LPARAM lParam; // [esp+8h] [ebp-8Ch]
  int v9; // [esp+Ch] [ebp-88h]
  HWND v10; // [esp+10h] [ebp-84h]
  struct tagRECT v11; // [esp+18h] [ebp-7Ch]
  __int64 v12; // [esp+30h] [ebp-64h]
  struct tagSCROLLINFO v13; // [esp+38h] [ebp-5Ch]
  struct tagSCROLLINFO v14; // [esp+54h] [ebp-40h]
  struct tagRECT Rect; // [esp+70h] [ebp-24h]
  struct tagRECT v16; // [esp+80h] [ebp-14h]

  v2 = this;
  this->m_nBottomScrollBarWidthOrHeight = a2;
  GetWindowRect(this->m_hWndHeaderLeft, &Rect);
  GetWindowRect(v2->m_hWndHeaderRight, &v16);
  MapWindowPoints(0, v2->m_hWnd, &Rect, 2u);
  MapWindowPoints(0, v2->m_hWnd, &v16, 2u);
  v3 = v2->m_hWndScrollBarLeftBottom;
  v13.cbSize = 28;
  _mm_storeu_si128(&v13.nMin, 0i64);
  v13.nTrackPos = 0;
  v14.cbSize = 28;
  _mm_storeu_si128(&v14.nMin, 0i64);
  v14.nTrackPos = 0;
  v13.fMask = 4;
  v14.fMask = 4;
  GetScrollInfo(v3, 2, &v13);
  GetScrollInfo(v2->m_hWndScrollBarRightBottom, 2, &v14);
  v4 = v2->m_nBottomScrollBarWidthOrHeight;
  v16.left = v2->m_nBottomScrollBarWidthOrHeight - v14.nPos;
  Rect.left = 0;
  v5 = v2->m_hWndHeaderLeft;
  Rect.right = v4;
  SetWindowPos(v5, 0, 0, Rect.top, v4, Rect.bottom - Rect.top, SWP_NOZORDER);
  SetWindowPos(v2->m_hWndHeaderRight, 0, v16.left, v16.top, v16.right - v16.left, v16.bottom - v16.top, SWP_NOZORDER);
  lParam = 48;
  v9 = 0;
  v6 = v2->m_hWndHeaderRight;
  _mm_storeu_si128(&v10, 0i64);
  _mm_storeu_si128(&v11.right, 0i64);
  v10 = v6;
  v12 = 0i64;
  GetClientRect(v6, &v11);
  SendMessageW(v2->m_hWndTooltipOfRightHeader, TTM_NEWTOOLRECTW, 0, &lParam);
  v10 = v2->m_hWndHeaderLeft;
  GetClientRect(v10, &v11);
  return SendMessageW(v2->m_hWndTooltipOfLeftHeader, TTM_NEWTOOLRECTW, 0, &lParam);
}

//----- (00F9EF00) --------------------------------------------------------
int __thiscall CTreeList::OnSize(CTreeList *this)
{
  CTreeList *v1; // ebx
  bool v2; // al
  int result; // eax
  char fHide; // [esp+Bh] [ebp-45h]
  char fSBVisible; // [esp+Fh] [ebp-41h]
  bool v6; // [esp+13h] [ebp-3Dh]
  SCROLLINFO ScrollInfoRight; // [esp+14h] [ebp-3Ch]
  SCROLLINFO ScrollInfoBottom; // [esp+30h] [ebp-20h]

  v1 = this;
  CTreeList::GetScrollInfos(this, &ScrollInfoRight, &ScrollInfoBottom);
  fHide = ScrollInfoRight.nPage <= ScrollInfoRight.nMax;
  fSBVisible = ScrollInfoBottom.nPage <= ScrollInfoBottom.nMax;
  v6 = CTreeList::UpdateRightRightSB(
         v1,
         ScrollInfoRight.nPage <= ScrollInfoRight.nMax,
         ScrollInfoBottom.nPage <= ScrollInfoBottom.nMax);
  CTreeList::UpdateLeftBottomSB(v1, v1->m_hWndScrollBarRightBottom, fSBVisible, fHide);
  v2 = fHide && fSBVisible;
  result = CTreeList::ShowCaption(v1, v2);
  if ( fHide )
  {
    SetScrollInfo(v1->m_hWndScrollBarRightRight, 2, &ScrollInfoRight, 1);
    result = CTreeList::UpdateVScrollBars(v1, 0);
  }
  if ( fSBVisible )
  {
    SetScrollInfo(v1->m_hWndScrollBarRightBottom, 2, &ScrollInfoBottom, 1);
    result = CTreeList::UpdateHeaderPos(v1, v1->m_hWndScrollBarRightBottom, 0);
  }
  if ( v6 )
    result = CTreeList::RepositionTooltips();
  return result;
}

//----- (00F9EFD0) --------------------------------------------------------
int __cdecl CTreeList::RepositionHeaders()
{
  CTreeList *v0; // ecx
  CTreeList *v1; // esi
  int v2; // edi
  bool v3; // bl
  int result; // eax
  HWND v5; // ST00_4
  UINT v6; // [esp+8h] [ebp-34h]
  struct tagRECT Rect; // [esp+Ch] [ebp-30h]
  SCROLLINFO v8; // [esp+1Ch] [ebp-20h]

  v1 = v0;
  if ( v0->field_9C )
  {
    GetClientRect(v0->m_hWnd, &Rect);
    v2 = v1->m_nChildWidthLast;
    v3 = v2 > v1->m_nBottomScrollBarWidthOrHeight;
    v6 = v1->m_nBottomScrollBarWidthOrHeight;
    LOBYTE(result) = CTreeList::UpdateLeftBottomSB(v1, v1->m_hWndScrollBarLeftBottom, v3, 0);
    if ( v3 )
    {
      v8.cbSize = 28;
      _mm_storeu_si128(&v8.nMin, 0i64);
      v8.nTrackPos = 0;
      v8.nMax = v2 - 1;
      v8.nPage = v6;
      v5 = v1->m_hWndScrollBarLeftBottom;
      v8.fMask = 3;
      v8.nMin = 0;
      SetScrollInfo(v5, 2, &v8, 1);
      result = CTreeList::UpdateHeaderPos(v1, v1->m_hWndScrollBarLeftBottom, 0);
    }
  }
  return result;
}

//----- (00F9F090) --------------------------------------------------------
void __thiscall CTreeList::RedrawChild(CTreeList *pThis, tagTreeViewChildItem *pItem)
{
  CTreeList *this; // esi
  tagTreeViewChildItem *pChildLast; // ebx
  int nPos; // eax
  int v5; // eax

  this = pThis;
  pChildLast = pThis->m_ChildLast;
  if ( pItem != pChildLast )
  {
    if ( pChildLast )
    {
      pChildLast->m_dwStyle &= -TVIF_IMAGE;
      nPos = CTreeList::FindChild(pThis, pThis->m_ChildLast);
      if ( nPos >= 0 )
        CTreeList::RedrawZone(this, nPos, nPos);
      this->m_ChildLast = 0;
    }
    if ( pItem )
    {
      pItem->m_dwStyle |= TVIF_TEXT;
      v5 = CTreeList::FindChild(this, pItem);
      if ( v5 >= 0 )
        CTreeList::RedrawZone(this, v5, v5);
      this->m_ChildLast = pItem;
    }
    CTreeList::SendNotify(this, this->m_hWnd, 2000, 0, pItem, pChildLast, 0);
  }
}

//----- (00F9F110) --------------------------------------------------------
LRESULT __thiscall sub_F9F110(HWND *this, int a2, int a3)
{
  LRESULT result; // eax
  LPARAM lParam; // [esp+0h] [ebp-2Ch]
  int v5; // [esp+4h] [ebp-28h]

  v5 = a3;
  lParam = 1;
  if ( a2 )
    result = SendMessageW(this[5], 0x120Cu, a2 - 1, &lParam);
  else
    result = SendMessageW(this[3], 0x120Cu, 0, &lParam);
  return result;
}

//----- (00F9F160) --------------------------------------------------------
int __stdcall CTreeList::OnMsg2000(tagTreeViewChildItem *pItem, char a2)
{
  int result; // eax

  result = pItem;
  if ( a2 )
  {
    pItem->m_dwStyle |= 0x40u;
    if ( !pItem->m_nCount )
      pItem->m_dwStyle &= -0x11u;
  }
  else
  {
    pItem->m_dwStyle &= -0x41u;
  }
  return result;
}

//----- (00F9F190) --------------------------------------------------------
LRESULT __thiscall CTreeList::SetSortFlagsImageList(CTreeList *this, LPARAM lParam, int a3, int a4)
{
  CTreeList *v4; // ebx
  HWND v5; // ST00_4

  v4 = this;
  v5 = this->m_hWndHeaderLeft;
  this->field_B4 = a3;
  this->field_B8 = a4;
  SendMessageW(v5, HDM_SETIMAGELIST, 0, lParam);
  return SendMessageW(v4->m_hWndHeaderRight, HDM_SETIMAGELIST, 0, lParam);
}

//----- (00F9F1E0) --------------------------------------------------------
char __thiscall CTreeList::ResetImageList(CTreeList *this, int a2, char a3)
{
  CTreeList *v3; // esi
  char result; // al

  v3 = this;
  if ( this->m_ImageList && !LOBYTE(this->m_NotMyImageList) )
    ImageList_Destroy(this->m_ImageList);
  v3->m_ImageList = a2;
  result = a3;
  LOBYTE(v3->m_NotMyImageList) = a3;
  return result;
}

//----- (00F9F210) --------------------------------------------------------
int __thiscall sub_F9F210(CTreeList *this, int a2)
{
  int result; // eax

  result = a2;
  this->m_nHeight = a2;
  return result;
}

//----- (00F9F230) --------------------------------------------------------
int __thiscall sub_F9F230(CTreeList *this, int a2)
{
  int result; // eax

  result = a2;
  this->field_74 = a2;
  return result;
}

//----- (00F9F240) --------------------------------------------------------
BOOL __thiscall CTreeList::ShowCaption(CTreeList *this, char fVisible)
{
  CTreeList *v2; // edi
  int v3; // eax
  struct tagRECT rcClient; // [esp+4h] [ebp-14h]

  v2 = this;
  if ( !fVisible )
    return ShowWindow(this->m_hWndStatic, SW_HIDE);
  GetClientRect(this->m_hWnd, &rcClient);
  rcClient.left = rcClient.right - GetSystemMetrics(SM_CXVSCROLL);
  v3 = GetSystemMetrics(SM_CYHSCROLL);
  rcClient.top = rcClient.bottom - v3;
  return SetWindowPos(
           v2->m_hWndStatic,
           0,
           rcClient.left,
           rcClient.bottom - v3,
           rcClient.right - rcClient.left,
           v3,
           SWP_SHOWWINDOW|SWP_NOZORDER);
}

//----- (00F9F2D0) --------------------------------------------------------
bool __thiscall CTreeList::UpdateLeftBottomSB(CTreeList *this, HWND hWnd, char a3, char a4)
{
  CTreeList *v4; // esi
  char v5; // al
  bool v6; // bl
  int v7; // eax
  HWND v8; // ecx
  int v9; // esi
  int v10; // ebx
  int v11; // eax
  bool result; // al
  int v13; // [esp+Ch] [ebp-40h]
  int v14; // [esp+10h] [ebp-3Ch]
  int X; // [esp+14h] [ebp-38h]
  bool v16; // [esp+1Bh] [ebp-31h]
  SCROLLINFO v17; // [esp+1Ch] [ebp-30h]
  struct tagRECT rcClient; // [esp+38h] [ebp-14h]

  v4 = this;
  GetClientRect(this->m_hWnd, &rcClient);
  v5 = (GetWindowLongW(hWnd, -16) >> 28) & 1;
  v6 = v5 != a3;
  v16 = v5 != a3;
  if ( a3 )
  {
    v14 = GetSystemMetrics(SM_CYHSCROLL);
    v7 = GetSystemMetrics(SM_CXVSCROLL);
    v8 = v4->m_hWndScrollBarLeftBottom;
    v13 = v7;
    if ( hWnd == v8 )
      X = 0;
    else
      X = v4->m_nBottomScrollBarWidthOrHeight;
    if ( hWnd == v8 )
      v9 = v4->m_nBottomScrollBarWidthOrHeight;
    else
      v9 = rcClient.right - rcClient.left;
    v10 = rcClient.bottom - rcClient.top - v14;
    v11 = v10 + GetSystemMetrics(3);
    if ( a4 )
      v9 -= v13;
    SetWindowPos(hWnd, 0, X, v10, v9 - X, v11 - v10, SWP_SHOWWINDOW|SWP_NOZORDER);
    result = v16;
  }
  else
  {
    if ( v5 )
    {
      v17.cbSize = 28;
      v17.nTrackPos = 0;
      _mm_storeu_si128(&v17.nMin, 0i64);
      v17.fMask = 4;
      v17.nPos = 0;
      SetScrollInfo(hWnd, 2, &v17, 1);
      CTreeList::UpdateHeaderPos(v4, hWnd, 0);
      ShowWindow(hWnd, 0);
    }
    result = v6;
  }
  return result;
}

//----- (00F9F400) --------------------------------------------------------
bool __thiscall CTreeList::UpdateRightRightSB(CTreeList *this, bool fHide, bool fSBVisible)
{
  CTreeList *v3; // edi
  char bWindowVisible; // al
  bool v5; // bl
  int nLeft; // edx
  int nHeight; // eax
  bool result; // al
  HWND v9; // ST0C_4
  int v10; // [esp+8h] [ebp-34h]
  SCROLLINFO v11; // [esp+Ch] [ebp-30h]
  struct tagRECT Rect; // [esp+28h] [ebp-14h]

  v3 = this;
  GetClientRect(this->m_hWnd, &Rect);
  bWindowVisible = (GetWindowLongW(v3->m_hWndScrollBarRightRight, -16) >> 28) & 1;
  v5 = bWindowVisible != fHide;
  if ( fHide )
  {
    v10 = GetSystemMetrics(SM_CYHSCROLL);
    nLeft = Rect.right - Rect.left - GetSystemMetrics(SM_CXVSCROLL);
    nHeight = Rect.bottom - Rect.top;
    if ( fSBVisible )
      nHeight -= v10;
    SetWindowPos(
      v3->m_hWndScrollBarRightRight,
      0,
      nLeft,
      0,
      Rect.right - Rect.left - nLeft,
      nHeight,
      SWP_SHOWWINDOW|SWP_NOZORDER);
    result = v5;
  }
  else
  {
    if ( bWindowVisible )
    {
      v11.cbSize = 28;
      v9 = v3->m_hWndScrollBarRightRight;
      v11.nTrackPos = 0;
      _mm_storeu_si128(&v11.nMin, 0i64);
      v11.fMask = 4;
      v11.nPos = 0;
      SetScrollInfo(v9, 2, &v11, 1);
      CTreeList::UpdateVScrollBars(v3, 0);
      ShowWindow(v3->m_hWndScrollBarRightRight, 0);
    }
    result = v5;
  }
  return result;
}

//----- (00F9F500) --------------------------------------------------------
unsigned int __cdecl sub_F9F500(unsigned int *a1, unsigned int a2, int (__cdecl *a3)(_DWORD, _DWORD, int, int), int a4, int a5, int a6)
{
  unsigned int result; // eax
  unsigned int v7; // edi
  unsigned int v8; // ebx
  unsigned int v9; // eax
  unsigned int *v10; // esi
  unsigned int v11; // edi
  int v12; // eax

  if ( a2 > 1 )
  {
    v7 = a2 >> 1;
    v8 = sub_F9F500(a1, a2 >> 1, a3, a4, a5, a6);
    v9 = sub_F9F500(a1, a2 - v7, a3, a4, a5, a6);
    a2 = 0;
    v10 = &a2;
    v11 = v9;
    if ( !v8 )
      goto LABEL_12;
    while ( v11 )
    {
      v12 = a3(*(v8 + 4), *(v11 + 4), a4, a5);
      if ( a6 )
        v12 = -v12;
      if ( v12 > 0 )
      {
        *v10 = v11;
        v11 = *(v11 + 16);
      }
      else
      {
        *v10 = v8;
        v8 = *(v8 + 16);
      }
      v10 = (*v10 + 16);
      if ( !v8 )
        goto LABEL_12;
    }
    if ( v8 )
    {
      *v10 = v8;
      result = a2;
    }
    else
    {
LABEL_12:
      *v10 = v11;
      result = a2;
    }
  }
  else
  {
    result = *a1;
    if ( *a1 )
    {
      *a1 = *(result + 16);
      *(result + 16) = 0;
    }
  }
  return result;
}

//----- (00F9F5C0) --------------------------------------------------------
LRESULT __stdcall CTreeList::Proxy_HeaderWndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
  CTreeList *v4; // eax
  LRESULT result; // eax

  v4 = GetPropW(hWnd, gAtomTreeListProperty);
  if ( v4 )
    result = CTreeList::HeaderWndProc(v4, hWnd, Msg, wParam, lParam);
  else
    result = CallWindowProcW(MEMORY[0xC8], hWnd, Msg, wParam, lParam);
  return result;
}
// 1064DA0: using guessed type __int16 gAtomTreeListProperty;

//----- (00F9F610) --------------------------------------------------------
LRESULT __stdcall CTreeList::Proxy_TooltipWndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
  CTreeList *v4; // eax
  LRESULT lResult; // ecx

  v4 = GetPropW(hWnd, gAtomTreeListProperty);
  lResult = 0;
  if ( Msg != WM_TIMER )
    return CallWindowProcW(v4->m_TooltipWndProc, hWnd, Msg, wParam, lParam);
  if ( !v4->m_bSkipTimerForTooltip )
    lResult = CallWindowProcW(v4->m_TooltipWndProc, hWnd, WM_TIMER, wParam, lParam);
  return lResult;
}
// 1064DA0: using guessed type __int16 gAtomTreeListProperty;

//----- (00F9F680) --------------------------------------------------------
HWND __stdcall CTreeList::WndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
  CTreeList *v4; // eax
  HWND result; // eax

  v4 = GetPropW(hWnd, gAtomTreeListProperty);
  if ( v4 )
    result = CTreeList::TreeWndProc(v4, hWnd, Msg, wParam, lParam);
  else
    result = DefWindowProcW(hWnd, Msg, wParam, lParam);
  return result;
}
// 1064DA0: using guessed type __int16 gAtomTreeListProperty;

//----- (00F9F6C0) --------------------------------------------------------
tagTreeViewChildItem *__thiscall CTreeList::GetCurScrollChildItem(CTreeList *this)
{
  CTreeList *pThis; // esi
  HWND v2; // ST00_4
  tagTreeViewChildItem *pChildren; // ecx
  int nIndex; // esi
  tagTreeViewChildItem *pCurrent; // eax
  struct tagSCROLLINFO ScrollInfo; // [esp+4h] [ebp-20h]

  ScrollInfo.cbSize = 28;
  pThis = this;
  ScrollInfo.nTrackPos = 0;
  ScrollInfo.fMask = 4;
  v2 = this->m_hWndScrollBarRightRight;
  _mm_storeu_si128(&ScrollInfo.nMin, 0i64);
  GetScrollInfo(v2, 2, &ScrollInfo);
  pChildren = pThis->m_Child;
  nIndex = 0;
  if ( !pChildren )
    return 0;
  do
  {
    if ( nIndex >= ScrollInfo.nPos )
      break;
    if ( pChildren->m_Next && (pChildren->m_dwStyle >> 4) & 1 )
    {
      pChildren = pChildren->m_Next;
    }
    else if ( pChildren->m_Prev )
    {
      pChildren = pChildren->m_Prev;
    }
    else
    {
      pCurrent = pChildren->m_Current;
      if ( pCurrent )
      {
        while ( !pCurrent->m_Prev )
        {
          pCurrent = pCurrent->m_Current;
          if ( !pCurrent )
            goto LABEL_11;
        }
        pChildren = pCurrent->m_Prev;
      }
      else
      {
LABEL_11:
        pChildren = 0;
      }
    }
    ++nIndex;
  }
  while ( pChildren );
  return pChildren;
}

//----- (00F9F780) --------------------------------------------------------
int __thiscall CTreeList::GetRightScrollbarPos(CTreeList *this)
{
  HWND v1; // ST00_4
  struct tagSCROLLINFO v3; // [esp+0h] [ebp-20h]

  v3.cbSize = 28;
  v1 = this->m_hWndScrollBarRightRight;
  v3.nTrackPos = 0;
  _mm_storeu_si128(&v3.nMin, 0i64);
  v3.fMask = 4;
  GetScrollInfo(v1, 2, &v3);
  return v3.nPos;
}

//----- (00F9F7D0) --------------------------------------------------------
bool __thiscall CTreeList::InitHeaderColumn(CTreeList *this, HWND hWnd, char a3)
{
  CTreeList *v3; // ebx
  HWND v4; // eax
  HWND v5; // edi
  WPARAM v6; // esi
  bool v7; // zf
  void (__stdcall *v8)(HWND, UINT, WPARAM, LPARAM); // ecx
  HWND v9; // eax
  HWND v10; // esi
  signed int v11; // ecx
  LPARAM lParam; // [esp+Ch] [ebp-30h]
  unsigned int v14; // [esp+20h] [ebp-1Ch]
  int v15; // [esp+28h] [ebp-14h]
  bool a2; // [esp+3Bh] [ebp-1h]
  HWND hWnda; // [esp+44h] [ebp+8h]
  bool v18; // [esp+4Bh] [ebp+Fh]

  v3 = this;
  v4 = sub_F9C8A0(this, &a2);
  v5 = hWnd;
  v6 = v4;
  if ( hWnd == v4 )
    v7 = a2 == 0;
  else
    v7 = a3 == 0;
  v8 = SendMessageW;
  v18 = v7;
  if ( v4 >= 0 )
  {
    if ( v4 )
    {
      v9 = v3->m_hWndHeaderRight;
      --v6;
    }
    else
    {
      v9 = v3->m_hWndHeaderLeft;
    }
    hWnda = v9;
    lParam = 4;
    SendMessageW(v9, 0x120Bu, v6, &lParam);
    if ( gbBitmapOnRight )
      v14 &= 0xFFFFF9FF;
    else
      v14 &= 0xFFFFE7FF;
    SendMessageW(hWnda, 0x120Cu, v6, &lParam);
    v8 = SendMessageW;
  }
  if ( v5 >= 0 )
  {
    if ( v5 )
    {
      v10 = v3->m_hWndHeaderRight;
      v5 = (v5 - 1);
    }
    else
    {
      v10 = v3->m_hWndHeaderLeft;
    }
    lParam = 36;
    v8(v10, 0x120Bu, v5, &lParam);
    if ( gbBitmapOnRight )
    {
      v11 = 1024;
      lParam = 4;
      if ( v18 )
        v11 = 512;
      v14 = v14 & 0xFFFFF9FF | v11;
    }
    else
    {
      v14 |= 0x1800u;
      if ( v18 )
        v15 = v3->field_B8;
      else
        v15 = v3->field_B4;
    }
    SendMessageW(v10, 0x120Cu, v5, &lParam);
  }
  return v18;
}
// 106A8F8: using guessed type char gbBitmapOnRight;

//----- (00F9F8F0) --------------------------------------------------------
LRESULT __thiscall CTreeList::PopTooltip(CTreeList *this, HWND hWnd, POINT *pt)
{
  CTreeList *v3; // esi
  tagTreeViewChildItem *v4; // ecx
  LRESULT result; // eax
  int xx; // [esp+4h] [ebp-Ch]
  WPARAM nHeaderItemCount; // [esp+8h] [ebp-8h]
  tagTreeViewChildItem *pChild; // [esp+Ch] [ebp-4h]

  xx = 0;
  nHeaderItemCount = 0;
  pChild = 0;
  v3 = this;
  CTreeList::Query(this, pt->x, pt->y, &xx, &nHeaderItemCount, &pChild);
  v4 = pChild;
  result = nHeaderItemCount;
  if ( v3->m_point.y != pChild || nHeaderItemCount != v3->m_nHeaderItemCount )
  {
    v3->m_nHeaderItemCount = nHeaderItemCount;
    v3->m_point.x = xx;
    v3->m_point.y = v4;
    result = SendMessageW(hWnd, TTM_POP, 0, 0);
  }
  return result;
}

//----- (00F9F970) --------------------------------------------------------
unsigned int __thiscall CTreeList::UpdateVScrollBars(CTreeList *this, int nPos)
{
  CTreeList *v2; // ebx
  unsigned int result; // eax
  int v4; // esi
  int v5; // edi
  int v6; // [esp+4h] [ebp-54h]
  struct tagRECT v7; // [esp+8h] [ebp-50h]
  struct tagRECT Rect; // [esp+18h] [ebp-40h]
  RECT prcScroll; // [esp+28h] [ebp-30h]
  SCROLLINFO ScrollInfo; // [esp+38h] [ebp-20h]

  v2 = this;
  result = GetWindowLongW(this->m_hWndScrollBarRightRight, GWL_STYLE) >> 28;
  if ( result & 1 )
  {
    ScrollInfo.cbSize = 28;
    ScrollInfo.nTrackPos = 0;
    ScrollInfo.fMask = 4;
    _mm_storeu_si128(&ScrollInfo.nMin, 0i64);
    if ( nPos )
    {
      GetScrollInfo(v2->m_hWndScrollBarRightRight, 2, &ScrollInfo);
      ScrollInfo.nPos += nPos;
      SetScrollInfo(v2->m_hWndScrollBarRightRight, 2, &ScrollInfo, 1);
    }
    GetScrollInfo(v2->m_hWndScrollBarRightRight, 2, &ScrollInfo);
    result = ScrollInfo.nPos;
    v6 = ScrollInfo.nPos;
    if ( ScrollInfo.nPos != v2->m_nLastVScrollPos )
    {
      v4 = CTreeList::GetLineHeight(v2);
      GetClientRect(v2->m_hWnd, &Rect);
      v5 = v2->m_nLastVScrollPos - v6;
      v2->m_nLastVScrollPos = v6;
      prcScroll.left = Rect.left;
      GetWindowRect(v2->m_hWndHeaderLeft, &v7);
      prcScroll.top = v7.bottom - v7.top;
      prcScroll.right = Rect.right;
      prcScroll.bottom = Rect.bottom;
      result = ScrollWindowEx(v2->m_hWnd, 0, v4 * v5, &prcScroll, 0, 0, 0, 2u);
    }
  }
  return result;
}

//----- (00F9FA80) --------------------------------------------------------
unsigned int __userpurge CTreeList::SetVScrollPos@<eax>(CTreeList *this@<ecx>, int a2, int a3)
{
  CTreeList *v3; // esi
  HWND v4; // ST00_4
  SCROLLINFO v6; // [esp+0h] [ebp-20h]

  _mm_storeu_si128(&v6.nMin, 0i64);
  v6.nPos = a2;
  v3 = this;
  v6.cbSize = 28;
  v4 = this->m_hWndScrollBarRightRight;
  v6.nTrackPos = 0;
  v6.fMask = 4;
  SetScrollInfo(v4, 2, &v6, 1);
  return CTreeList::UpdateVScrollBars(v3, 0);
}

//----- (00F9FAF0) --------------------------------------------------------
HWND __thiscall CTreeList::TreeWndProc(CTreeList *this, HWND hWndIn, UINT Msg, WPARAM wParamIn, LPARAM lParam)
{
  CTreeList *pThis; // esi
  HWND *lParam_1; // edi
  HWND result; // eax
  HWND v8; // ST18_4
  unsigned int uMsg; // ecx
  LONG dwStyle; // eax
  int dxx; // ecx
  int m_nBottomScrollBarWidthOrHeight; // edx
  int v13; // edi
  int v14; // edi
  HWND hWndHeaderLeft; // ST10_4
  HCURSOR hCursor; // eax
  bool v17; // zf
  HCURSOR v18; // ecx
  int v19; // eax
  HWND hWnd_1; // edx
  HWND v21; // eax
  HCURSOR v22; // ST1C_4
  LRESULT v23; // eax
  HWND v24; // edi
  WPARAM v25; // ecx
  BOOL v26; // edi
  HWND m_hWndHeaderLeft_1; // ST10_4
  HWND m_hWndHeaderLeft; // ST10_4
  HRGN v29; // eax
  HWND v30; // edi
  HWND v31; // eax
  int v32; // eax
  tagTreeViewChildItem *v33; // ST14_4
  LONG v34; // eax
  HWND v35; // ST14_4
  HWND v36; // ST1C_4
  HDC v37; // eax
  HFONT v38; // ST1C_4
  HGDIOBJ v39; // edi
  void *v40; // ST1C_4
  HDC v41; // edi
  Data_t_bstr_t *v42; // ecx
  HWND v43; // ecx
  HWND v44; // edx
  unsigned int v45; // eax
  int v46; // eax
  int v47; // eax
  BOOL v48; // eax
  char *v49; // eax
  int v50; // edi
  HWND v51; // eax
  HWND v52; // edx
  WINDOWPOS *v53; // edi
  int v54; // eax
  int v55; // eax
  WPARAM v56; // ST18_4
  HWND v57; // eax
  int v58; // edi
  int v59; // eax
  _DWORD *v60; // ecx
  tagTreeViewChildItem *v61; // eax
  signed int v62; // edi
  HWND v63; // ST14_4
  tagTreeViewChildItem **v64; // edi
  tagTreeViewChildItem **v65; // eax
  tagTreeViewChildItem **v66; // eax
  signed int v67; // edi
  tagTreeViewChildItem *v68; // ecx
  unsigned int v69; // edx
  unsigned int v70; // eax
  WINDOWPOS *v71; // edx
  signed int v72; // edi
  __int32 v73; // ecx
  int v74; // ecx
  BSTR **v75; // eax
  tagTreeViewChildItem **v76; // eax
  tagTreeViewChildItem **v77; // edx
  WINDOWPOS *v78; // eax
  _DWORD *v79; // eax
  UINT v80; // eax
  signed int v81; // eax
  HWND v82; // ST14_4
  tagTreeViewChildItem *v83; // edi
  LONG v84; // ecx
  int v85; // [esp-14h] [ebp-2E0h]
  Data_t_bstr_t *v86; // [esp-10h] [ebp-2DCh]
  tagTreeViewChildItem *v87; // [esp-Ch] [ebp-2D8h]
  int v88; // [esp+0h] [ebp-2CCh]
  _bstr_t v89; // [esp+Ch] [ebp-2C0h]
  HDLAYOUT Layout; // [esp+10h] [ebp-2BCh]
  LPARAM lParam_2; // [esp+18h] [ebp-2B4h]
  _bstr_t lpchText; // [esp+1Ch] [ebp-2B0h]
  bool v93; // [esp+23h] [ebp-2A9h]
  tagTreeViewChildItem **pChildItem; // [esp+24h] [ebp-2A8h]
  tagTreeViewChildItem *pChild; // [esp+28h] [ebp-2A4h]
  HWND hWnd; // [esp+2Ch] [ebp-2A0h]
  WPARAM wParam; // [esp+30h] [ebp-29Ch]
  HGDIOBJ ho; // [esp+34h] [ebp-298h]
  RECT prcScroll; // [esp+38h] [ebp-294h]
  WINDOWPOS WindowPos; // [esp+48h] [ebp-284h]
  int Paint; // [esp+64h] [ebp-268h]
  int ToolInfo; // [esp+74h] [ebp-258h]
  HDITEMW Item; // [esp+78h] [ebp-254h]
  __int64 v104; // [esp+9Ch] [ebp-230h]
  RECT Rect; // [esp+A4h] [ebp-228h]
  __int16 v106[260]; // [esp+B4h] [ebp-218h]
  int v107; // [esp+2C8h] [ebp-4h]

  pThis = this;
  lParam_1 = lParam;
  hWnd = hWndIn;
  wParam = wParamIn;
  lParam_2 = lParam;
  if ( Msg - LVM_FIRST <= 0xFF )
    return CTreeList::HandleListViewMsg(this, hWnd, Msg, wParamIn, lParam);
  if ( Msg - 512 <= 0xD )
  {
    Rect.right = lParam;
    Rect.bottom = SHIWORD(lParam);
    Item.cchTextMax = hWnd;
    v8 = this->m_hWndTooltipOfTreeList;
    Item.lParam = wParamIn;
    Item.fmt = Msg;
    Item.iImage = lParam;
    *&Item.iOrder = 0i64;
    HIDWORD(v104) = 0;
    CTreeList::PopTooltip(this, v8, &Rect.right);
    SendMessageW(pThis->m_hWndTooltipOfTreeList, TTM_RELAYEVENT, 0, &Item.cchTextMax);
  }
  uMsg = Msg;
  if ( Msg == WM_LBUTTONDOWN )
  {
    if ( LOBYTE(pThis->field_BC) )
    {
      ho = lParam;
      if ( abs(lParam - pThis->m_nBottomScrollBarWidthOrHeight) <= 8 )
      {
        SetCapture(hWnd);
        SetCursor(pThis->m_hCursor);
        pThis->m_ptDownLast.x = ho;
LABEL_9:
        SetFocus(hWnd);
        Rect.bottom = 0;
        pChild = 0;
        dwStyle = CTreeList::Query(pThis, lParam, SHIWORD(lParam), &Rect.bottom, 0, &pChild);
        Rect.bottom = dwStyle;
        if ( dwStyle & (TVIF_INTEGRAL|TVIF_CHILDREN|TVIF_SELECTEDIMAGE) )
        {
          CTreeList::SendNotify(pThis, pThis->m_hWnd, -2, 0, pChild, 0, 0);
          LOWORD(dwStyle) = Rect.bottom;
        }
        if ( dwStyle & TVIF_CHILDREN )
        {
          CTreeList::OnMsg2001(pThis, pChild, ~(pChild->m_dwStyle >> 4) & 1);
        }
        else if ( dwStyle & (TVIF_STATEEX|TVIF_INTEGRAL|TVIF_CHILDREN|TVIF_SELECTEDIMAGE) )
        {
          CTreeList::RedrawChild(pThis, pChild);
        }
        return (pThis->baseclass.vtptr->HandleMessage)(pThis, hWnd, Msg, wParam, lParam_1);
      }
      goto LABEL_40;
    }
LABEL_32:
    hWnd_1 = hWnd;
    goto LABEL_33;
  }
  if ( Msg == WM_MOUSEMOVE )
  {
    if ( LOBYTE(pThis->field_BC) )
    {
      pChild = lParam;
      if ( GetCapture() == hWnd && wParam & 1 )
      {
        dxx = pChild - pThis->m_ptDownLast.x;
        if ( pChild != pThis->m_ptDownLast.x )
        {
          m_nBottomScrollBarWidthOrHeight = pThis->m_nBottomScrollBarWidthOrHeight;
          v13 = pThis->field_94;
          if ( m_nBottomScrollBarWidthOrHeight + dxx < v13 )
            dxx = v13 - m_nBottomScrollBarWidthOrHeight;
          pThis->m_ptDownLast.x += dxx;
          v14 = m_nBottomScrollBarWidthOrHeight + dxx;
          CTreeList::MoveHeaders(pThis, m_nBottomScrollBarWidthOrHeight + dxx);
          Item.mask = 1;
          hWndHeaderLeft = pThis->m_hWndHeaderLeft;
          Item.cxy = v14;
          SendMessageW(hWndHeaderLeft, HDM_SETITEMW, 0, &Item);
          CTreeList::OnSize(pThis);
          lParam_1 = lParam_2;
        }
        SetCursor(pThis->m_hCursor);
        uMsg = WM_MOUSEMOVE;
        goto LABEL_209;
      }
      if ( abs(pChild - pThis->m_nBottomScrollBarWidthOrHeight) <= 8 )
      {
        SetCursor(pThis->m_hCursor);
        uMsg = WM_MOUSEMOVE;
        goto LABEL_209;
      }
      hCursor = GetClassLongW(pThis->m_hWnd, GCL_HCURSOR);
      v17 = pThis->m_pfnGetChildCursor == 0;
      v18 = hCursor;
      ho = hCursor;
      if ( !v17 )
      {
        Layout.pwpos = 0;
        lpchText.m_Data = 0;
        pChildItem = 0;
        CTreeList::Query(pThis, pChild, SHIWORD(lParam), &Layout.pwpos, &lpchText, &pChildItem);
        if ( pChildItem )
        {
          // typedef LRESULT(*LPFN_CALLBACK_D8)(tagTreeViewChildItem* pItem, _bstr_t str);
          v19 = (pThis->m_pfnGetChildCursor)(pChildItem, lpchText.m_Data);
          v18 = ho;
          if ( v19 )
            v18 = v19;
        }
        else
        {
          v18 = ho;
        }
      }
      SetCursor(v18);
      goto LABEL_31;
    }
    goto LABEL_32;
  }
  if ( Msg != WM_LBUTTONUP || !LOBYTE(pThis->field_BC) )
    goto LABEL_32;
  v21 = GetCapture();
  hWnd_1 = hWnd;
  if ( v21 == hWnd )
  {
    ReleaseCapture();
LABEL_40:
    v22 = GetClassLongW(pThis->m_hWnd, GCL_HCURSOR);
    SetCursor(v22);
LABEL_31:
    uMsg = Msg;
    goto LABEL_32;
  }
  uMsg = WM_LBUTTONUP;
LABEL_33:
  if ( uMsg > WM_KEYFIRST )
  {
    if ( uMsg > WM_MOUSEWHEEL )
    {
      switch ( uMsg )
      {
        case TREELIST_MSG_2000:
          CTreeList::OnMsg2000(wParam, lParam != 0);
          return 0;
        case TREELIST_MSG_2001:
          return CTreeList::OnMsg2001(pThis, wParam, lParam != 0);
        case TREELIST_MSG_2002:
          return *(wParam + 0x1C);
        case TREELIST_MSG_2003:
          CTreeList::RefreshChildItem(pThis, wParam);
          return 0;
        case TREELIST_MSG_2004:
          return CTreeList::OnMsg2004(*lParam, *(lParam + 4), *(lParam + 8));
        case TREELIST_MSG_2005:
          return CTreeList::FindChild(pThis, wParam);
        default:
          goto LABEL_82;
      }
      goto LABEL_82;
    }
    if ( uMsg == WM_MOUSEWHEEL )
    {
      Rect.bottom = pThis->m_nLastVScrollPos2 + SHIWORD(wParam);
      v84 = Rect.bottom;
      pThis->m_nLastVScrollPos2 = Rect.bottom;
      if ( abs(v84) >= 40 )
      {
        pThis->m_nLastVScrollPos2 = Rect.bottom - 40 * (v84 / 40);
        CTreeList::UpdateVScrollBars(pThis, Rect.bottom / -40);
      }
      return (pThis->baseclass.vtptr->HandleMessage)(pThis, hWnd, Msg, wParam, lParam_1);
    }
    if ( uMsg <= WM_VSCROLL )
    {
      if ( uMsg == WM_VSCROLL )
      {
        Item.cchTextMax = 28;
        v82 = pThis->m_hWndScrollBarRightRight;
        HIDWORD(v104) = 0;
        _mm_storeu_si128(&Item.lParam, 0i64);
        Item.fmt = 7;
        GetScrollInfo(v82, 2, &Item.cchTextMax);
        switch ( wParam )
        {
          case SB_HORZ:
            LODWORD(v104) = v104 - 1;
            CTreeList::SetVScrollPos(pThis, v104, v88);
            return (pThis->baseclass.vtptr->HandleMessage)(pThis, hWnd, Msg, wParam, lParam_1);
          case SB_VERT:
            LODWORD(v104) = v104 + 1;
            CTreeList::SetVScrollPos(pThis, v104, v88);
            return (pThis->baseclass.vtptr->HandleMessage)(pThis, hWnd, Msg, wParam, lParam_1);
          case SB_CTL:
            LODWORD(v104) = v104 - Item.iOrder;
            CTreeList::SetVScrollPos(pThis, v104, v88);
            return (pThis->baseclass.vtptr->HandleMessage)(pThis, hWnd, Msg, wParam, lParam_1);
          case SB_BOTH:
            LODWORD(v104) = Item.iOrder + v104;
            CTreeList::SetVScrollPos(pThis, v104, v88);
            return (pThis->baseclass.vtptr->HandleMessage)(pThis, hWnd, Msg, wParam, lParam_1);
          case SB_THUMBPOSITION:
          case SB_THUMBTRACK:
            LODWORD(v104) = wParam >> 16;
            CTreeList::SetVScrollPos(pThis, wParam >> 16, v88);
            return (pThis->baseclass.vtptr->HandleMessage)(pThis, hWnd, Msg, wParam, lParam_1);
          case SB_TOP:
            LODWORD(v104) = 0;
            CTreeList::SetVScrollPos(pThis, 0, v88);
            return (pThis->baseclass.vtptr->HandleMessage)(pThis, hWnd, Msg, wParam, lParam_1);
          case SB_BOTTOM:
            LODWORD(v104) = Item.iImage;
            CTreeList::SetVScrollPos(pThis, Item.iImage, v88);
            return (pThis->baseclass.vtptr->HandleMessage)(pThis, hWnd, Msg, wParam, lParam_1);
          case SB_ENDSCROLL:
            return 1;
          default:
            return 0;
        }
        return 0;
      }
      v73 = uMsg - WM_CHAR;
      if ( !v73 )
      {
        if ( pThis->m_nChildCount )
        {
          Layout.pwpos = GetTickCount();
          if ( Layout.pwpos - pThis->m_dwTickCountLast > 0x2EE )
            sub_F9A320(&pThis->field_D0, gszStatusBarText);
          if ( !pThis->m_ChildLast
            || ((v75 = _bstr_t::_bstr_t(&v89, gszStatusBarText),
                 v93 = sub_F9A3E0(&pThis->field_D0, v75),
                 _bstr_t::_Free(&v89),
                 !v93) ? (v76 = pThis->m_ChildLast) : (v76 = sub_F9E650(pThis->m_ChildLast)),
                (pChildItem = v76) == 0) )
          {
            pChildItem = pThis->m_Child;
          }
          pThis->m_dwTickCountLast = Layout.pwpos;
          ho = wParam;
          _bstr_t::_bstr_t(&lpchText, &ho);
          v107 = 0;
          _bstr_t::operator+=(&pThis->field_D0, &lpchText);
          v107 = -1;
          _bstr_t::_Free(&lpchText);
          v77 = pChildItem;
          pChild = pChildItem;
          while ( 1 )
          {
            Rect.bottom = 260;
            v78 = (*(v77[1]->m_TreeList + 8))(v77, 0, v106, &Rect.bottom);
            lParam_1 = lParam_2;
            Layout.pwpos = v78;
            v79 = pThis->field_D0;
            lpchText.m_Data = (v79 ? *v79 : 0);
            v80 = sub_F80440(&pThis->field_D0);
            if ( !_wcsnicmp(Layout.pwpos, lpchText.m_Data, v80) )
              break;
            v77 = sub_F9E650(pChild);
            pChild = v77;
            if ( !v77 )
            {
              v77 = pThis->m_Child;
              pChild = pThis->m_Child;
            }
            if ( v77 == pChildItem )
              return (pThis->baseclass.vtptr->HandleMessage)(pThis, hWnd, Msg, wParam, lParam_1);
          }
          CTreeList::RedrawChild(pThis, pChild);
          v81 = CTreeList::FindChild(pThis, pChild);
          sub_F9BE30(pThis, v81);
        }
        return (pThis->baseclass.vtptr->HandleMessage)(pThis, hWnd, Msg, wParam, lParam_1);
      }
      v74 = v73 - 17;
      if ( !v74 )
      {
        if ( wParam == 100 )
        {
          GetCursorPos(&Rect.right);
          MapWindowPoints(0, hWnd, &Rect.right, 1u);
          CTreeList::PopTooltip(pThis, pThis->m_hWndTooltipOfTreeList, &Rect.right);
        }
        return (pThis->baseclass.vtptr->HandleMessage)(pThis, hWnd, Msg, wParam, lParam_1);
      }
      if ( v74 == 1 )
      {
        if ( !lParam )
          return (pThis->baseclass.vtptr->HandleMessage)(pThis, hWnd, Msg, wParam, lParam_1);
        Item.cchTextMax = 28;
        HIDWORD(v104) = 0;
        _mm_storeu_si128(&Item.lParam, 0i64);
        Item.fmt = 7;
        GetScrollInfo(lParam, 2, &Item.cchTextMax);
        switch ( wParam )
        {
          case SB_HORZ:
            LODWORD(v104) = v104 - 1;
            CTreeList::SetHScrollPos(pThis, lParam, v104);
            return (pThis->baseclass.vtptr->HandleMessage)(pThis, hWnd, Msg, wParam, lParam_1);
          case SB_VERT:
            LODWORD(v104) = v104 + 1;
            CTreeList::SetHScrollPos(pThis, lParam, v104);
            return (pThis->baseclass.vtptr->HandleMessage)(pThis, hWnd, Msg, wParam, lParam_1);
          case SB_CTL:
            LODWORD(v104) = v104 - Item.iOrder;
            CTreeList::SetHScrollPos(pThis, lParam, v104);
            return (pThis->baseclass.vtptr->HandleMessage)(pThis, hWnd, Msg, wParam, lParam_1);
          case SB_BOTH:
            LODWORD(v104) = Item.iOrder + v104;
            CTreeList::SetHScrollPos(pThis, lParam, v104);
            return (pThis->baseclass.vtptr->HandleMessage)(pThis, hWnd, Msg, wParam, lParam_1);
          case SB_THUMBPOSITION:
          case SB_THUMBTRACK:
            LODWORD(v104) = wParam >> 16;
            CTreeList::SetHScrollPos(pThis, lParam, wParam >> 16);
            return (pThis->baseclass.vtptr->HandleMessage)(pThis, hWnd, Msg, wParam, lParam_1);
          case SB_TOP:
            LODWORD(v104) = 0;
            CTreeList::SetHScrollPos(pThis, lParam, 0);
            return (pThis->baseclass.vtptr->HandleMessage)(pThis, hWnd, Msg, wParam, lParam_1);
          case SB_BOTTOM:
            LODWORD(v104) = Item.iImage;
            CTreeList::SetHScrollPos(pThis, lParam, Item.iImage);
            return (pThis->baseclass.vtptr->HandleMessage)(pThis, hWnd, Msg, wParam, lParam_1);
          case SB_ENDSCROLL:
            return 1;
          default:
            return 0;
        }
        return 0;
      }
LABEL_82:
      if ( Msg == WM_THEMECHANGED )
      {
        if ( pThis->baseclass.m_hThemeHandle )
          gpfnCloseThemeData(pThis->baseclass.m_hThemeHandle);
        pThis->baseclass.m_hThemeHandle = 0;
        if ( gpfnIsThemeActive && gpfnIsThemeActive() )
        {
          v47 = (pThis->baseclass.vtptr->GetName)(pThis);
          pThis->baseclass.m_hThemeHandle = gpfnOpenThemeData(hWnd, v47);
        }
      }
__HandleMessage:
      lParam_1 = lParam_2;
      return (pThis->baseclass.vtptr->HandleMessage)(pThis, hWnd, Msg, wParam, lParam_1);
    }
    if ( uMsg == WM_LBUTTONDOWN )
      goto LABEL_9;
LABEL_209:
    // WM_RBUTTONDOWN
    if ( uMsg - WM_LBUTTONDBLCLK <= 1 )
    {
      Rect.bottom = 0;
      lpchText.m_Data = 0;
      ho = 0;
      if ( CTreeList::Query(pThis, lParam_1, SHIWORD(lParam_1), &Rect.bottom, &lpchText, &ho) & (TVIF_INTEGRAL|TVIF_CHILDREN|TVIF_SELECTEDIMAGE) )
      {
        v83 = ho;
        CTreeList::RedrawChild(pThis, ho);
        v87 = v83;
        v86 = lpchText.m_Data;
        v85 = 2 * (Msg == WM_LBUTTONDBLCLK) - 5;
LABEL_81:
        CTreeList::SendNotify(pThis, pThis->m_hWnd, v85, v86, v87, 0, 0);
      }
    }
    goto LABEL_82;
  }
  if ( uMsg == WM_KEYFIRST )
  {
    v17 = LOBYTE(pThis->m_ptDownLast.y) == 0;
    v54 = 2007;
    Item.lParam = hWnd_1;
    if ( !v17 )
      v54 = -155;
    Item.iOrder = v54;
    v55 = GetWindowLongW(hWnd_1, -12);
    LOWORD(v104) = wParam;
    v56 = v55;
    Item.iImage = v55;
    *(&v104 + 2) = 0;
    v57 = GetParent(hWnd);
    SendMessageW(v57, 0x4Eu, v56, &Item.lParam);
    switch ( wParam )
    {
      case VK_PRIOR:
      case VK_NEXT:
        pChildItem = pThis->m_ChildLast;
        if ( !pChildItem )
          return (pThis->baseclass.vtptr->HandleMessage)(pThis, hWnd, Msg, wParam, lParam_1);
        Item.cchTextMax = 28;
        v63 = pThis->m_hWndScrollBarRightRight;
        HIDWORD(v104) = 0;
        _mm_storeu_si128(&Item.lParam, 0i64);
        Item.fmt = 2;
        GetScrollInfo(v63, 2, &Item.cchTextMax);
        ho = 0;
        if ( !Item.iOrder )
          goto LABEL_149;
        v64 = pChildItem;
        break;
      case VK_LEFT:
      case VK_RIGHT:
        v68 = pThis->m_ChildLast;
        if ( !v68 )
          return (pThis->baseclass.vtptr->HandleMessage)(pThis, hWnd, Msg, wParam, lParam_1);
        v69 = v68->m_dwStyle;
        v70 = v68->m_dwStyle;
        if ( wParam == 39 )
        {
          if ( !((v70 >> 6) & 1) )
            return (pThis->baseclass.vtptr->HandleMessage)(pThis, hWnd, Msg, wParam, lParam_1);
          if ( !((v69 >> 4) & 1) )
          {
            CTreeList::OnMsg2001(pThis, v68, 1);
            return (pThis->baseclass.vtptr->HandleMessage)(pThis, hWnd, Msg, wParam, lParam_1);
          }
          return CTreeList::TreeWndProc(pThis, hWnd, 0x100u, 0x28u, 0);
        }
        if ( (v70 >> 4) & 1 && (v69 >> 6) & 1 )
        {
          CTreeList::OnMsg2001(pThis, v68, 0);
          return (pThis->baseclass.vtptr->HandleMessage)(pThis, hWnd, Msg, wParam, lParam_1);
        }
        v71 = v68->m_Current;
        Layout.pwpos = v71;
        if ( v71 && v71 != &pThis->field_40 )
        {
          v72 = CTreeList::FindChild(pThis, v68);
          CTreeList::RedrawChild(pThis, Layout.pwpos);
          sub_F9BE30(pThis, v72);
          goto __HandleMessage;
        }
        return (pThis->baseclass.vtptr->HandleMessage)(pThis, hWnd, Msg, wParam, lParam_1);
      case VK_UP:
      case VK_DOWN:
        v60 = pThis->m_ChildLast;
        if ( !v60 )
          return (pThis->baseclass.vtptr->HandleMessage)(pThis, hWnd, Msg, wParam, lParam_1);
        v61 = (wParam == 40 ? sub_F9E650(v60) : sub_F9E9D0(v60));
        ho = v61;
        if ( !v61 )
          return (pThis->baseclass.vtptr->HandleMessage)(pThis, hWnd, Msg, wParam, lParam_1);
        v62 = CTreeList::FindChild(pThis, v61);
        CTreeList::RedrawChild(pThis, ho);
        sub_F9BE30(pThis, v62);
        goto __HandleMessage;
      case VK_ADD:
        if ( GetKeyState(VK_LCONTROL) )
        {
          if ( SendMessageW(pThis->m_hWndHeaderRight, HDM_GETITEMCOUNT, 0, 0) + 1 > 0 )
          {
            v58 = 0;
            do
            {
              if ( v58 || !pThis->field_9C )
                v59 = CTreeList::GetChildWidth(pThis, v58);
              else
                v59 = pThis->m_nChildWidthLast;
              sub_F9F110(pThis, v58++, v59);
            }
            while ( v58 < SendMessageW(pThis->m_hWndHeaderRight, 0x1200u, 0, 0) + 1 );
            lParam_1 = lParam_2;
          }
          CTreeList::OnSize(pThis);
        }
        return (pThis->baseclass.vtptr->HandleMessage)(pThis, hWnd, Msg, wParam, lParam_1);
      default:
        return (pThis->baseclass.vtptr->HandleMessage)(pThis, hWnd, Msg, wParam, lParam_1);
    }
    do
    {
      if ( wParam == VK_NEXT )
      {
        v65 = sub_F9E650(v64);
        if ( !v65 )
          break;
        v64 = v65;
        pChildItem = v65;
      }
      else
      {
        v66 = sub_F9E9D0(v64);
        if ( !v66 )
          break;
        v64 = v66;
        pChildItem = v66;
      }
      ho = ho + 1;
    }
    while ( ho < Item.iOrder );
    lParam_1 = lParam_2;
LABEL_149:
    if ( !pChildItem )
      return (pThis->baseclass.vtptr->HandleMessage)(pThis, hWnd, Msg, wParam, lParam_1);
    v67 = CTreeList::FindChild(pThis, pChildItem);
    CTreeList::RedrawChild(pThis, pChildItem);
    sub_F9BE30(pThis, v67);
    goto __HandleMessage;
  }
  switch ( uMsg )
  {
    case WM_DESTROY:
      CTreeList::OnDestroy(pThis);
      goto LABEL_82;
    case WM_SIZE:
      CTreeList::OnSize(pThis);
      CTreeList::RepositionHeaders();
      CTreeList::RepositionTooltips();
      v31 = pThis->m_hWnd;
      ToolInfo = 48;
      _mm_storeu_si128(&Item.cxy, 0i64);
      Item.mask = 0;
      _mm_storeu_si128(&Item.fmt, 0i64);
      Item.cxy = v31;
      v104 = 0i64;
      GetClientRect(v31, &Item.hbm);
      SendMessageW(pThis->m_hWndTooltipOfTreeList, TTM_NEWTOOLRECTW, 0, &ToolInfo);
      goto LABEL_82;
    case WM_ACTIVATE|WM_CREATE:
    case 8u:
      if ( pThis->m_ChildLast )
        CTreeList::RefreshChildItem(pThis, pThis->m_ChildLast);
      goto LABEL_82;
    case WM_SETVISIBLE|WM_DESTROY:
      if ( wParam )
      {
        v23 = DefWindowProcW(hWnd_1, uMsg, wParam, lParam);
        pThis->m_bSkipTimerForTooltip = 0;
        v24 = v23;
        CTreeList::Refresh(pThis);
        result = v24;
      }
      else
      {
        pThis->m_bSkipTimerForTooltip = 1;
        result = DefWindowProcW(hWnd_1, uMsg, 0, lParam);
      }
      return result;
    case WM_SETVISIBLE|WM_ACTIVATE:
      v29 = CreateRectRgn(0, 0, 0, 0);
      v30 = hWnd;
      ho = v29;
      if ( GetUpdateRgn(hWnd, v29, 0) != 1 )
      {
        BeginPaint(v30, &Paint);
        CTreeList::DrawTree(pThis, &Paint, ho);
        EndPaint(v30, &Paint);
      }
      DeleteObject(ho);
      return 0;
    case 0x14u:
      return 1;
    case 0x20u:
      if ( wParam != hWnd_1 )
        goto LABEL_82;
      return 1;
    case 0x30u:
      v25 = wParam;
      pThis->m_Font = wParam;
      v26 = lParam != 0;
      m_hWndHeaderLeft_1 = pThis->m_hWndHeaderLeft;
      v93 = lParam != 0;
      SendMessageW(m_hWndHeaderLeft_1, WM_SETFONT, v25, v26);
      SendMessageW(pThis->m_hWndHeaderRight, WM_SETFONT, pThis->m_Font, v26);
      SendMessageW(pThis->m_hWndTooltipOfTreeList, WM_SETFONT, pThis->m_Font, v26);
      SendMessageW(pThis->m_hWndTooltipOfLeftHeader, WM_SETFONT, pThis->m_Font, v26);
      SendMessageW(pThis->m_hWndTooltipOfRightHeader, WM_SETFONT, pThis->m_Font, v26);
      GetClientRect(pThis->m_hWnd, &Item.iImage);
      WindowPos.hwnd = 0;
      Layout.prc = &Item.iImage;
      *&WindowPos.cy = 0i64;
      Layout.pwpos = &WindowPos;
      m_hWndHeaderLeft = pThis->m_hWndHeaderLeft;
      _mm_storeu_si128(&WindowPos.hwndInsertAfter, 0i64);
      SendMessageW(m_hWndHeaderLeft, HDM_LAYOUT, 0, &Layout);
      SetWindowPos(
        pThis->m_hWndHeaderLeft,
        WindowPos.hwndInsertAfter,
        0,
        0,
        pThis->m_nBottomScrollBarWidthOrHeight,
        WindowPos.cy,
        WindowPos.flags | SWP_SHOWWINDOW);
      SetWindowPos(
        pThis->m_hWndHeaderRight,
        pThis->m_hWndHeaderLeft,
        pThis->m_nBottomScrollBarWidthOrHeight,
        0,
        WindowPos.cx - pThis->m_nBottomScrollBarWidthOrHeight,
        WindowPos.cy,
        WindowPos.flags | SWP_SHOWWINDOW);
      if ( !v93 )
        return 0;
      CTreeList::Refresh(pThis);
      return 0;
    case WM_NOTIFY:
      if ( *lParam != pThis->m_hWndTooltipOfTreeList )
        goto LABEL_69;
      v32 = *(lParam + 8);
      if ( v32 == TTN_GETDISPINFOW )
      {
        if ( pThis->m_point.y )
        {
          pChildItem = (lParam + 12);
          *(lParam + 12) = lParam + 16;
          v33 = pThis->m_point.y;
          ho = (lParam + 16);
          if ( CTreeList::SendNotify(pThis, pThis->m_hWnd, 2004, pThis->m_nHeaderItemCount, v33, 0, lParam + 12) )
            return 0;
          v34 = pThis->m_point.y;
          Layout.pwpos = 80;
          lpchText.m_Data = (*(**(v34 + 4) + 8))(v34, pThis->m_nHeaderItemCount, ho, &Layout.pwpos);
          WindowPos.y = 0;
          WindowPos.cx = 0;
          WindowPos.cy = GetSystemMetrics(78);
          WindowPos.flags = CTreeList::GetLineHeight(pThis);
          sub_F9C210(pThis, pThis->m_point.x, pThis->m_nHeaderItemCount, 1, 1, pThis->m_point.y, &prcScroll);
          Item.cchTextMax = 28;
          v35 = pThis->m_hWndScrollBarRightBottom;
          HIDWORD(v104) = 0;
          _mm_storeu_si128(&Item.lParam, 0i64);
          Item.fmt = 4;
          GetScrollInfo(v35, 2, &Item.cchTextMax);
          if ( prcScroll.left == pThis->m_nBottomScrollBarWidthOrHeight )
          {
            if ( v104 )
              return 0;
          }
          v36 = pThis->m_hWnd;
          pChild = (pThis->m_Format & 0xFFFB3FFF | 0x400);
          v37 = GetDC(v36);
          v38 = pThis->m_Font;
          ho = v37;
          v39 = SelectObject(v37, v38);
          DrawTextW(ho, lpchText.m_Data, -1, &WindowPos.y, pChild);
          v40 = v39;
          v41 = ho;
          SelectObject(ho, v40);
          ReleaseDC(pThis->m_hWnd, v41);
          v42 = &gszNullString;
          lParam_1 = lParam_2;
          if ( WindowPos.cy - WindowPos.y > prcScroll.right - prcScroll.left )
            v42 = lpchText.m_Data;
          *pChildItem = v42;
        }
        else
        {
          *(lParam + 12) = &gszNullString;
        }
      }
      else if ( v32 == TTN_SHOW )
      {
        sub_F9C210(pThis, pThis->m_point.x, pThis->m_nHeaderItemCount, 0, 1, pThis->m_point.y, &WindowPos.y);
        SendMessageW(pThis->m_hWndTooltipOfTreeList, 0x41Fu, 1u, &WindowPos.y);
        MapWindowPoints(pThis->m_hWnd, 0, &WindowPos.y, 2u);
        SetWindowPos(
          pThis->m_hWndTooltipOfTreeList,
          0,
          WindowPos.y,
          WindowPos.cx,
          0,
          0,
          SWP_NOACTIVATE|SWP_NOZORDER|SWP_NOSIZE);
        SendMessageW(pThis->m_hWndTooltipOfTreeList, 0x30u, pThis->m_Font, 0);
        CTreeList::SendNotify(
          pThis,
          pThis->m_hWndTooltipOfTreeList,
          2005,
          pThis->m_nHeaderItemCount,
          pThis->m_point.y,
          0,
          0);
        return 1;
      }
LABEL_69:
      v43 = *lParam_1;
      v44 = pThis->m_hWndHeaderLeft;
      if ( *lParam_1 != v44 && v43 != pThis->m_hWndHeaderRight )
        goto LABEL_82;
      v45 = lParam_1[2];
      if ( v45 > 0xFFFFFEC0 )
      {
        if ( v45 == -311 )
        {
          InvalidateRect(pThis->m_hWnd, 0, 0);
          return 0;
        }
        if ( v45 == -5 )
          CTreeList::SendNotify(pThis, v43, -5, 0, 0, 0, 0);
        goto LABEL_82;
      }
      if ( v45 != -320 )
      {
        switch ( v45 )
        {
          case 0xFFFFFEBB:
            v48 = v43 == pThis->m_hWndHeaderRight;
            v17 = (lParam_1[3] + v48) == 0;
            v49 = lParam_1[3] + v48;
            ho = v49;
            if ( v17 && pThis->field_9C )
            {
              v50 = pThis->m_nChildWidthLast;
            }
            else
            {
              v50 = CTreeList::GetChildWidth(pThis, v49);
              v49 = ho;
            }
            sub_F9F110(pThis, v49, v50);
            if ( !ho )
              CTreeList::MoveHeaders(pThis, v50);
            CTreeList::OnSize(pThis);
            break;
          case 0xFFFFFEBE:
            if ( v43 == v44 )
              v46 = 0;
            else
              v46 = lParam_1[3] + 1;
            v87 = 0;
            v86 = v46;
            v85 = 2003;
            goto LABEL_81;
          case 0xFFFFFEBF:
            CTreeList::OnSize(pThis);
            break;
        }
        goto LABEL_82;
      }
      v51 = lParam_1[5];
      if ( !(*v51 & 1) )
        goto LABEL_82;
      v52 = lParam_1[3];
      if ( !v52 && *(v51 + 1) < pThis->field_94 )
        return 1;
      Layout.pwpos = (v52 + (v43 == pThis->m_hWndHeaderRight));
      CTreeList::MapToHeader(pThis, Layout.pwpos, &WindowPos.y);
      GetClientRect(pThis->m_hWnd, &Item.iImage);
      ho = (WindowPos.y + *(lParam_1[5] + 1) - WindowPos.cy);
      if ( !ho )
        return 0;
      v53 = Layout.pwpos;
      prcScroll.top = WindowPos.flags;
      *&prcScroll.right = v104;
      prcScroll.left = WindowPos.cy;
      if ( !Layout.pwpos )
        prcScroll.left = WindowPos.cy - 1;
      if ( (GetWindowLongW(pThis->m_hWndScrollBarRightRight, -16) >> 28) & 1 )
        prcScroll.right -= GetSystemMetrics(2);
      ScrollWindowEx(pThis->m_hWnd, ho, 0, &prcScroll, 0, 0, 0, SWP_NOMOVE);
      if ( (v53 || !pThis->field_9C)
        && (Rect.left = WindowPos.y,
            Rect.top = WindowPos.flags,
            Rect.right = WindowPos.cy,
            Rect.bottom = HIDWORD(v104),
            InvalidateRect(pThis->m_hWnd, &Rect, 0),
            v53) )
      {
        CTreeList::OnSize(pThis);
        UpdateWindow(pThis->m_hWndScrollBarRightBottom);
        result = 0;
      }
      else
      {
        CTreeList::MoveHeaders(pThis, ho + WindowPos.cy);
        CTreeList::OnSize(pThis);
        CTreeList::RepositionHeaders();
        UpdateWindow(pThis->m_hWndHeaderRight);
        UpdateWindow(pThis->m_hWndScrollBarLeftBottom);
        UpdateWindow(pThis->m_hWndScrollBarRightBottom);
        result = 0;
      }
      break;
    case WM_NCDESTROY:
      if ( pThis->m_ImageList && !LOBYTE(pThis->m_NotMyImageList) )
        ImageList_Destroy(pThis->m_ImageList);
      SetPropW(hWnd, gAtomTreeListProperty, 0);
      CTreeList::~CTreeList(pThis);
      j__free(pThis);
      return DefWindowProcW(hWnd, Msg, wParam, lParam);
    case WM_GETDLGCODE:
      return (DefWindowProcW(hWnd_1, uMsg, wParam, lParam) | 1);
    default:
      goto LABEL_82;
  }
  return result;
}
// 1064D84: using guessed type int (__stdcall *gpfnIsThemeActive)();
// 1064DA0: using guessed type __int16 gAtomTreeListProperty;

//----- (00FA11F0) --------------------------------------------------------
CSystemProcessInfoMapNode *__thiscall sub_FA11F0(std__tree *this, int *a2)
{
  CSystemProcessInfoMapNode *result; // eax
  CSystemProcessInfoMapNode *v3; // esi
  CSystemProcessInfoMapPair *v4; // edi
  Data_t_bstr_t *v5; // eax
  Data_t_bstr_t *v6; // eax

  result = std::_Tree_comp_alloc<std::_Tmap_traits<unsigned long,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *>>,0>>::_Buynode0(this);
  v3 = result;
  v4 = &result->_Keyvalue;
  *&result->baseclass._Color = 0;
  if ( result != -16 )
  {
    v5 = *a2;
    v4->_Key = *a2;
    if ( v5 )
      InterlockedIncrement(&v5->m_RefCount);
    v6 = a2[1];
    v4->_Value = v6;
    if ( v6 )
      InterlockedIncrement(&v6->m_RefCount);
    result = v3;
  }
  return result;
}

//----- (00FA1240) --------------------------------------------------------
int __thiscall sub_FA1240(int *this, int a2, int a3, int a4, void *a5)
{
  int *v5; // edx
  int v6; // ecx
  bool v7; // al
  int v8; // ebx
  int v9; // esi
  Data_t_bstr_t *v10; // ecx
  Data_t_bstr_t *v11; // ecx
  int v12; // esi
  int *v13; // eax
  int v14; // ecx
  int result; // eax
  Data_t_bstr_t *v16; // ecx
  void *v17; // edi
  Data_t_bstr_t *v18; // [esp-8h] [ebp-34h]
  Data_t_bstr_t *v19; // [esp-8h] [ebp-34h]
  Data_t_bstr_t *v20; // [esp-8h] [ebp-34h]
  Data_t_bstr_t *v21; // [esp-4h] [ebp-30h]
  Data_t_bstr_t *v22; // [esp-4h] [ebp-30h]
  Data_t_bstr_t *v23; // [esp-4h] [ebp-30h]
  int v24; // [esp+0h] [ebp-2Ch]
  int *v25; // [esp+10h] [ebp-1Ch]
  int v26; // [esp+14h] [ebp-18h]
  int v27; // [esp+18h] [ebp-14h]
  int *v28; // [esp+1Ch] [ebp-10h]
  int v29; // [esp+28h] [ebp-4h]

  v28 = &v24;
  v5 = this;
  v25 = this;
  v6 = *this;
  v7 = 1;
  v8 = a4;
  v29 = 0;
  v9 = *(v6 + 4);
  v27 = v6;
  LOBYTE(v26) = 1;
  if ( !*(v9 + 13) )
  {
    do
    {
      v27 = v9;
      if ( a3 )
      {
        v21 = *v8;
        if ( *v8 )
          InterlockedIncrement((*v8 + 8));
        v10 = *(v9 + 16);
        v18 = v10;
        if ( v10 )
          InterlockedIncrement(&v10->m_RefCount);
        v7 = sub_F914B0(v18, v21) == 0;
      }
      else
      {
        v11 = *(v9 + 16);
        v22 = v11;
        if ( v11 )
          InterlockedIncrement(&v11->m_RefCount);
        v19 = *v8;
        if ( *v8 )
          InterlockedIncrement(&v19->m_RefCount);
        v7 = sub_F914B0(v19, v22);
      }
      LOBYTE(v26) = v7;
      if ( v7 )
        v9 = *v9;
      else
        v9 = *(v9 + 8);
    }
    while ( !*(v9 + 13) );
    v6 = v27;
    v5 = v25;
  }
  v12 = v6;
  a3 = v6;
  if ( v7 )
  {
    if ( v6 == **v5 )
    {
      v13 = sub_FAAEE0(v5, &a3, 1, v6, v8, a5);
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
  v23 = *v8;
  if ( *v8 )
    InterlockedIncrement(&v23->m_RefCount);
  v16 = *(v12 + 16);
  v20 = v16;
  if ( v16 )
    InterlockedIncrement(&v16->m_RefCount);
  if ( sub_F914B0(v20, v23) )
  {
    v13 = sub_FAAEE0(v25, &a3, v26, v27, v8, a5);
    goto LABEL_21;
  }
  v17 = a5;
  sub_FA1430(a5 + 4);
  j__free(v17);
  result = a2;
  *a2 = v12;
  *(a2 + 4) = 0;
  return result;
}
// 10081AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);

//----- (00FA13E0) --------------------------------------------------------
int sub_FA13E0(wchar_t *Dst, wchar_t *Format, ...)
{
  va_list ArgList; // [esp+10h] [ebp+10h]

  va_start(ArgList, Format);
  return vswprintf_s(Dst, 0x10u, Format, ArgList);
}

//----- (00FA1400) --------------------------------------------------------
void __thiscall sub_FA1400(CSystemProcessInfoMap *this)
{
  CSystemProcessInfoMap *v1; // esi
  char v2; // [esp+4h] [ebp-4h]

  v1 = this;
  sub_FA6540(this, &v2, this->_Header->_Left, this->_Header);
  j__free(v1->_Header);
}

//----- (00FA1430) --------------------------------------------------------
void __thiscall sub_FA1430(_bstr_t **this)
{
  _bstr_t **v1; // edi
  LONG (__stdcall *v2)(volatile LONG *); // ecx
  Data_t_bstr_t *v3; // esi
  Data_t_bstr_t *v4; // esi

  v1 = this;
  v2 = InterlockedDecrement;
  v3 = v1[1];
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
    v2 = InterlockedDecrement;
    v1[1] = 0;
  }
  v4 = *v1;
  if ( *v1 )
  {
    if ( !v2(&v4->m_RefCount) && v4 )
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
    *v1 = 0;
  }
}

//----- (00FA14F0) --------------------------------------------------------
_bstr_t *__cdecl sub_FA14F0(_bstr_t *a1, LPCSTR lpString, _bstr_t *a3)
{
  _bstr_t::_bstr_t(a1, lpString);
  _bstr_t::operator+=(a1, a3);
  return a1;
}

//----- (00FA1560) --------------------------------------------------------
bool __stdcall AskForAgreementLicense(HWND hWnd, OLECHAR *psz, char a3, char a4, int a5)
{
  _bstr_t *v5; // esi
  Data_t_bstr_t **v6; // eax
  _bstr_t *v7; // eax
  Data_t_bstr_t *v8; // esi
  Data_t_bstr_t *v9; // esi
  Data_t_bstr_t *v10; // esi
  Data_t_bstr_t *v11; // esi
  const wchar_t *v12; // eax
  char v13; // al
  HWND v14; // ebx
  FILE *v15; // eax
  int v16; // eax
  bool v17; // bl
  Data_t_bstr_t *v18; // esi
  tagRegKeyInfo pThis; // [esp+14h] [ebp-58h]
  _bstr_t v21; // [esp+20h] [ebp-4Ch]
  _bstr_t v22; // [esp+24h] [ebp-48h]
  Data_t_bstr_t *v23; // [esp+28h] [ebp-44h]
  _bstr_t v24; // [esp+2Ch] [ebp-40h]
  _bstr_t v25; // [esp+30h] [ebp-3Ch]
  wchar_t Str; // [esp+34h] [ebp-38h]
  int v27; // [esp+68h] [ebp-4h]

  pThis.nLength = hWnd;
  _bstr_t::_bstr_t(&v24, L"\\VirusTotal");
  v27 = 0;
  v5 = _bstr_t::_bstr_t(&v21, psz);
  LOBYTE(v27) = 1;
  v6 = _bstr_t::_bstr_t(&v22, L"Software\\Sysinternals\\");
  LOBYTE(v27) = 2;
  v7 = _bstr_t::operator+(v6, &v23, v5);
  LOBYTE(v27) = 3;
  _bstr_t::operator+(&v7->m_Data, &v25, &v24);
  v8 = v23;
  if ( v23 )
  {
    if ( !InterlockedDecrement(&v23->m_RefCount) && v8 )
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
    v23 = 0;
  }
  v9 = v22.m_Data;
  if ( v22.m_Data )
  {
    if ( !InterlockedDecrement(&v22.m_Data->m_RefCount) && v9 )
    {
      if ( v9->m_wstr )
      {
        SysFreeString(v9->m_wstr);
        v9->m_wstr = 0;
      }
      if ( v9->m_str )
      {
        j_j__free(v9->m_str);
        v9->m_str = 0;
      }
      j__free(v9);
    }
    v22.m_Data = 0;
  }
  v10 = v21.m_Data;
  if ( v21.m_Data )
  {
    if ( !InterlockedDecrement(&v21.m_Data->m_RefCount) && v10 )
    {
      if ( v10->m_wstr )
      {
        SysFreeString(v10->m_wstr);
        v10->m_wstr = 0;
      }
      if ( v10->m_str )
      {
        j_j__free(v10->m_str);
        v10->m_str = 0;
      }
      j__free(v10);
    }
    v21.m_Data = 0;
  }
  v11 = v24.m_Data;
  if ( v24.m_Data && !InterlockedDecrement(&v24.m_Data->m_RefCount) )
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
  if ( v25.m_Data )
    v12 = v25.m_Data->m_wstr;
  else
    v12 = 0;
  pThis.szKeyName = _wcsdup(v12);
  LOBYTE(v27) = 9;
  LoadConfigItemFromRegistry(&pThis, &pConfigItem);
  v13 = byte_1064DB0;
  if ( byte_1064DB0 )
    goto LABEL_52;
  if ( a4 != byte_1064DB0 )
    goto LABEL_63;
  v14 = pThis.nLength;
  LaunchWebBrowser(pThis.nLength, 0, L"https://www.virustotal.com/about/terms-of-service");
  if ( a3 )
  {
    wprintf(L"%s\n\n", aYouMustAgreeTo);
    wprintf(L"Enter 'y' to agree: ");
    v15 = sub_1007B15();
    fflush(v15 + 1);
    _getws_s(&Str, 0x14u);
    if ( wcschr(&Str, 0x79u) )
    {
      byte_1064DB0 = 1;
      wprintf(L"\n");
    }
    else
    {
      wprintf(L"\nYou must agree to VirusTotal's terms of service to use VirusTotal features.\n\n");
    }
    goto LABEL_48;
  }
  v16 = a5 ? MessageBoxW(v14, a5, L"VirusTotal Terms of Service", 0x24u) : MessageBoxW(
                                                                             v14,
                                                                             L"You must agree to VirusTotal's terms of ser"
                                                                              "vice to use VirusTotal features.\n"
                                                                              "\n",
                                                                             L"VirusTotal Terms of Service",
                                                                             0x24u);
  if ( v16 == 6 )
  {
LABEL_63:
    byte_1064DB0 = 1;
LABEL_51:
    SaveConfigItemToRegistry(&pThis, &pConfigItem);
    v13 = byte_1064DB0;
    goto LABEL_52;
  }
LABEL_48:
  v13 = byte_1064DB0;
  if ( byte_1064DB0 )
    goto LABEL_51;
LABEL_52:
  v17 = v13 == 1;
  free(pThis.szKeyName);
  v18 = v25.m_Data;
  if ( v25.m_Data && !InterlockedDecrement(&v25.m_Data->m_RefCount) && v18 )
  {
    if ( v18->m_wstr )
    {
      SysFreeString(v18->m_wstr);
      v18->m_wstr = 0;
    }
    if ( v18->m_str )
    {
      j_j__free(v18->m_str);
      v18->m_str = 0;
    }
    j__free(v18);
  }
  return v17;
}
// 1034500: using guessed type wchar_t aYouMustAgreeTo_1[78];
// 105C338: using guessed type wchar_t aYouMustAgreeTo[175];
// 1064DB0: using guessed type char byte_1064DB0;

//----- (00FA18A0) --------------------------------------------------------
int __stdcall sub_FA18A0(int a1, FILETIME *lpFileTime)
{
  _bstr_t *v2; // esi
  Data_t_bstr_t **v3; // eax
  _bstr_t *v4; // eax
  _bstr_t *v5; // esi
  Data_t_bstr_t *v6; // eax
  void *v7; // esi
  LONG (__stdcall *v8)(volatile LONG *); // ecx
  void *v9; // esi
  Data_t_bstr_t *v10; // esi
  Data_t_bstr_t *v11; // esi
  Data_t_bstr_t *v12; // esi
  struct _FILETIME LocalFileTime; // [esp+14h] [ebp-140h]
  int v15; // [esp+1Ch] [ebp-138h]
  void *v16; // [esp+20h] [ebp-134h]
  _bstr_t v17; // [esp+24h] [ebp-130h]
  _bstr_t v18; // [esp+28h] [ebp-12Ch]
  void *v19; // [esp+2Ch] [ebp-128h]
  _bstr_t v20; // [esp+30h] [ebp-124h]
  struct _SYSTEMTIME SystemTime; // [esp+34h] [ebp-120h]
  WCHAR TimeStr; // [esp+44h] [ebp-110h]
  WCHAR DateStr; // [esp+C4h] [ebp-90h]
  int v24; // [esp+150h] [ebp-4h]

  *a1 = 0;
  v24 = 0;
  v15 = 1;
  FileTimeToLocalFileTime(lpFileTime, &LocalFileTime);
  FileTimeToSystemTime(&LocalFileTime, &SystemTime);
  GetDateFormatW(0x400u, 0, &SystemTime, L"yyyy-MM-dd", &DateStr, 64);
  GetTimeFormatW(0x400u, 8u, &SystemTime, L"hh:mm:ss", &TimeStr, 64);
  _bstr_t::_bstr_t(&v17, L" ");
  v24 = 1;
  v2 = _bstr_t::_bstr_t(&v20, &TimeStr);
  LOBYTE(v24) = 2;
  v3 = _bstr_t::_bstr_t(&v18, &DateStr);
  LOBYTE(v24) = 3;
  v4 = _bstr_t::operator+(v3, &v16, &v17);
  LOBYTE(v24) = 4;
  v5 = _bstr_t::operator+(&v4->m_Data, &v19, v2);
  if ( a1 != v5 )
  {
    _bstr_t::_Free(a1);
    v6 = v5->m_Data;
    *a1 = v5->m_Data;
    if ( v6 )
      InterlockedIncrement(&v6->m_RefCount);
  }
  v7 = v19;
  v8 = InterlockedDecrement;
  if ( v19 )
  {
    if ( !InterlockedDecrement(v19 + 2) && v7 )
    {
      if ( *v7 )
      {
        SysFreeString(*v7);
        *v7 = 0;
      }
      if ( *(v7 + 1) )
      {
        j_j__free(*(v7 + 1));
        *(v7 + 1) = 0;
      }
      j__free(v7);
    }
    v8 = InterlockedDecrement;
    v19 = 0;
  }
  v9 = v16;
  if ( v16 )
  {
    if ( !v8(v16 + 2) && v9 )
    {
      if ( *v9 )
      {
        SysFreeString(*v9);
        *v9 = 0;
      }
      if ( *(v9 + 1) )
      {
        j_j__free(*(v9 + 1));
        *(v9 + 1) = 0;
      }
      j__free(v9);
    }
    v16 = 0;
  }
  v10 = v18.m_Data;
  if ( v18.m_Data )
  {
    if ( !InterlockedDecrement(&v18.m_Data->m_RefCount) && v10 )
    {
      if ( v10->m_wstr )
      {
        SysFreeString(v10->m_wstr);
        v10->m_wstr = 0;
      }
      if ( v10->m_str )
      {
        j_j__free(v10->m_str);
        v10->m_str = 0;
      }
      j__free(v10);
    }
    v18.m_Data = 0;
  }
  v11 = v20.m_Data;
  if ( v20.m_Data )
  {
    if ( !InterlockedDecrement(&v20.m_Data->m_RefCount) && v11 )
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
    v20.m_Data = 0;
  }
  v12 = v17.m_Data;
  if ( v17.m_Data && !InterlockedDecrement(&v17.m_Data->m_RefCount) )
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
  return a1;
}

//----- (00FA1BC0) --------------------------------------------------------
int __stdcall sub_FA1BC0(int a2, OLECHAR *psz)
{
  OLECHAR *v2; // edi
  Data_t_bstr_t *v3; // eax
  Data_t_bstr_t *v4; // eax
  Data_t_bstr_t *v5; // esi
  BSTR v6; // eax
  Data_t_bstr_t *v7; // eax
  BSTR *v8; // eax
  int v9; // edi
  Data_t_bstr_t *v10; // eax
  Data_t_bstr_t *v11; // esi
  BSTR v12; // eax
  Data_t_bstr_t *v13; // eax
  BSTR *v14; // eax
  int v15; // edi
  Data_t_bstr_t *v16; // edi
  Data_t_bstr_t *v17; // eax
  Data_t_bstr_t *v18; // esi
  BSTR v19; // eax
  Data_t_bstr_t *v20; // eax
  BSTR *v21; // eax
  int v22; // edi
  _bstr_t v24; // [esp+10h] [ebp-18h]
  _bstr_t a3; // [esp+14h] [ebp-14h]
  int v26; // [esp+18h] [ebp-10h]
  int v27; // [esp+24h] [ebp-4h]
  OLECHAR *psza; // [esp+34h] [ebp+Ch]
  OLECHAR *pszb; // [esp+34h] [ebp+Ch]
  OLECHAR *pszc; // [esp+34h] [ebp+Ch]

  *a2 = 0;
  v2 = psz;
  v27 = 0;
  v26 = 1;
  if ( psz )
  {
    while ( 1 )
    {
      v3 = wcschr(v2, 0x5Cu);
      v24.m_Data = v3;
      if ( !v3 )
        break;
      LOWORD(v3->m_wstr) = 0;
      v4 = operator new(0xCu);
      v5 = v4;
      v27 = 1;
      if ( v4 )
      {
        v4->m_str = 0;
        v4->m_RefCount = 1;
        v6 = SysAllocString(v2);
        v5->m_wstr = v6;
        if ( !v6 && v2 )
          goto LABEL_56;
      }
      else
      {
        v5 = 0;
      }
      LOBYTE(v27) = 0;
      a3.m_Data = v5;
      if ( !v5 )
        goto LABEL_56;
      v27 = 2;
      v7 = operator new(0xCu);
      LOBYTE(v27) = 3;
      v8 = v7 ? _bstr_t::Data_t::Data_t(v7, a2, &a3) : 0;
      psza = v8;
      LOBYTE(v27) = 2;
      if ( !v8 )
        goto LABEL_56;
      v9 = *a2;
      if ( *a2 )
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
        v8 = psza;
        *a2 = 0;
      }
      *a2 = v8;
      LOBYTE(v27) = 0;
      if ( !InterlockedDecrement(&v5->m_RefCount) )
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
      v10 = operator new(0xCu);
      v11 = v10;
      v27 = 4;
      if ( v10 )
      {
        v10->m_str = 0;
        v10->m_RefCount = 1;
        v12 = SysAllocString(L"\\\\");
        v11->m_wstr = v12;
        if ( !v12 )
          goto LABEL_56;
      }
      else
      {
        v11 = 0;
      }
      LOBYTE(v27) = 0;
      a3.m_Data = v11;
      if ( !v11 )
        goto LABEL_56;
      v27 = 5;
      v13 = operator new(0xCu);
      LOBYTE(v27) = 6;
      v14 = v13 ? _bstr_t::Data_t::Data_t(v13, a2, &a3) : 0;
      pszb = v14;
      LOBYTE(v27) = 5;
      if ( !v14 )
        goto LABEL_56;
      v15 = *a2;
      if ( *a2 )
      {
        if ( !InterlockedDecrement((v15 + 8)) && v15 )
        {
          if ( *v15 )
          {
            SysFreeString(*v15);
            *v15 = 0;
          }
          if ( *(v15 + 4) )
          {
            j_j__free(*(v15 + 4));
            *(v15 + 4) = 0;
          }
          j__free(v15);
        }
        v14 = pszb;
        *a2 = 0;
      }
      *a2 = v14;
      LOBYTE(v27) = 0;
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
      v16 = v24.m_Data;
      LOWORD(v24.m_Data->m_wstr) = 92;
      v2 = (&v16->m_wstr + 2);
    }
    v17 = operator new(0xCu);
    v18 = v17;
    v27 = 7;
    if ( v17 )
    {
      v17->m_str = 0;
      v17->m_RefCount = 1;
      v19 = SysAllocString(v2);
      v18->m_wstr = v19;
      if ( !v19 && v2 )
        goto LABEL_56;
    }
    else
    {
      v18 = 0;
    }
    LOBYTE(v27) = 0;
    v24.m_Data = v18;
    if ( !v18
      || ((v27 = 8, v20 = operator new(0xCu), LOBYTE(v27) = 9, !v20) ? (v21 = 0) : (v21 = _bstr_t::Data_t::Data_t(
                                                                                            v20,
                                                                                            a2,
                                                                                            &v24)),
          pszc = v21,
          LOBYTE(v27) = 8,
          !v21) )
    {
LABEL_56:
      _com_issue_error(-2147024882);
    }
    v22 = *a2;
    if ( *a2 )
    {
      if ( !InterlockedDecrement((v22 + 8)) && v22 )
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
      v21 = pszc;
      *a2 = 0;
    }
    *a2 = v21;
    if ( !InterlockedDecrement(&v18->m_RefCount) )
    {
      if ( v18->m_wstr )
      {
        SysFreeString(v18->m_wstr);
        v18->m_wstr = 0;
      }
      if ( v18->m_str )
      {
        j_j__free(v18->m_str);
        v18->m_str = 0;
      }
      j__free(v18);
    }
  }
  return a2;
}

//----- (00FA1FC0) --------------------------------------------------------
DWORD __thiscall sub_FA1FC0(_DWORD *this)
{
  _DWORD *v1; // ebx
  CSystemProcessInfoMapNode *v2; // eax
  bool v3; // zf
  DWORD v4; // edi
  _DWORD *v5; // eax
  void (__stdcall *v6)(BSTR); // ebx
  Data_t_bstr_t *v7; // esi
  _DWORD *v8; // edi
  volatile LONG *v9; // eax
  volatile LONG *v10; // ebx
  Data_t_bstr_t *v11; // eax
  _DWORD *v12; // eax
  DWORD v13; // ebx
  Data_t_bstr_t *v14; // eax
  Data_t_bstr_t *v15; // eax
  Data_t_bstr_t *v16; // eax
  Data_t_bstr_t *v17; // esi
  OLECHAR *v18; // eax
  _bstr_t *v19; // eax
  _bstr_t *v20; // eax
  _bstr_t *v21; // ebx
  Data_t_bstr_t *v22; // eax
  BSTR *v23; // eax
  Data_t_bstr_t *v24; // ebx
  void *v25; // ebx
  Data_t_bstr_t *v26; // ebx
  void *v27; // ebx
  Data_t_bstr_t *v28; // eax
  Data_t_bstr_t *v29; // esi
  char *v30; // eax
  OLECHAR *v31; // eax
  _bstr_t *v32; // eax
  _bstr_t *v33; // eax
  _bstr_t *v34; // ebx
  Data_t_bstr_t *v35; // eax
  BSTR *v36; // eax
  DWORD v37; // ebx
  void *v38; // ebx
  Data_t_bstr_t *v39; // ebx
  void *v40; // ebx
  volatile LONG *v41; // eax
  volatile LONG *v42; // ebx
  Data_t_bstr_t *v43; // esi
  _bstr_t *v44; // eax
  Data_t_bstr_t *v45; // eax
  BSTR *v46; // eax
  Data_t_bstr_t *v47; // eax
  Data_t_bstr_t *v48; // eax
  Data_t_bstr_t *v49; // eax
  volatile LONG *v50; // eax
  volatile LONG *v51; // esi
  BSTR v52; // eax
  OLECHAR *v53; // eax
  _bstr_t *v54; // eax
  _bstr_t *v55; // eax
  _bstr_t *v56; // ebx
  Data_t_bstr_t *v57; // eax
  Data_t_bstr_t *v58; // ebx
  void **v59; // eax
  void *v60; // ebx
  Data_t_bstr_t *v61; // ebx
  Data_t_bstr_t *v62; // ebx
  volatile LONG *v63; // eax
  volatile LONG *v64; // esi
  _bstr_t *v65; // eax
  _bstr_t *v66; // eax
  _bstr_t *v67; // ebx
  Data_t_bstr_t *v68; // eax
  Data_t_bstr_t *v69; // ebx
  Data_t_bstr_t *v70; // eax
  Data_t_bstr_t *v71; // ebx
  Data_t_bstr_t *v72; // ebx
  Data_t_bstr_t *v73; // ebx
  volatile LONG *v74; // eax
  volatile LONG *v75; // ebx
  Data_t_bstr_t *v76; // eax
  Data_t_bstr_t *v77; // eax
  volatile LONG *v78; // eax
  volatile LONG *v79; // edi
  Data_t_bstr_t *v80; // eax
  Data_t_bstr_t *v81; // eax
  Data_t_bstr_t *v82; // esi
  void *v83; // ecx
  volatile LONG *v84; // eax
  volatile LONG *v85; // esi
  Data_t_bstr_t **v86; // eax
  CHAR *v87; // ecx
  DWORD v88; // eax
  Data_t_bstr_t *v89; // edi
  DWORD v90; // edi
  Data_t_bstr_t *v91; // ebx
  HINTERNET *v92; // edi
  CHAR *v93; // ecx
  const wchar_t *v94; // eax
  CHAR *v95; // ecx
  const wchar_t *v96; // eax
  const wchar_t *v97; // eax
  _DWORD *v98; // eax
  _DWORD *v99; // esi
  HINTERNET *v100; // ebx
  BSTR **v101; // edi
  Data_t_bstr_t *v102; // eax
  Data_t_bstr_t *v103; // edi
  OLECHAR *v104; // eax
  CSystemProcessInfoMapNode *v105; // ecx
  Data_t_bstr_t *v106; // eax
  const wchar_t *v107; // eax
  CHAR *v108; // ecx
  Data_t_bstr_t *v109; // eax
  BSTR *v110; // edi
  BSTR v111; // eax
  CHAR *v112; // ecx
  Data_t_bstr_t *v113; // eax
  BSTR *v114; // edi
  BSTR v115; // eax
  int v116; // edi
  _DWORD *v117; // eax
  _DWORD *v118; // esi
  int v119; // edi
  OLECHAR **v120; // eax
  OLECHAR *v121; // eax
  Data_t_bstr_t *v122; // esi
  _bstr_t *v123; // ecx
  _DWORD *v124; // eax
  _DWORD *v125; // edi
  HINTERNET *v126; // ebx
  volatile LONG **v127; // eax
  int v128; // esi
  Data_t_bstr_t *v129; // esi
  Data_t_bstr_t *v130; // esi
  _bstr_t *v131; // edi
  _DWORD *v132; // eax
  _DWORD *v133; // edi
  HINTERNET *v134; // ebx
  _bstr_t *v135; // eax
  HINTERNET *v136; // edx
  _DWORD **v137; // eax
  _DWORD *v138; // ecx
  HINTERNET *v139; // ebx
  _DWORD *v140; // esi
  CHAR *v142; // [esp-10h] [ebp-9Ch]
  void *v143; // [esp-Ch] [ebp-98h]
  CSystemProcessInfoMapNode *v144; // [esp-8h] [ebp-94h]
  CHAR *v145; // [esp-4h] [ebp-90h]
  void *v146; // [esp+10h] [ebp-7Ch]
  int v147; // [esp+14h] [ebp-78h]
  void *v148; // [esp+18h] [ebp-74h]
  OLECHAR psz[2]; // [esp+1Ch] [ebp-70h]
  _bstr_t a3; // [esp+20h] [ebp-6Ch]
  _bstr_t v151; // [esp+24h] [ebp-68h]
  _bstr_t v152; // [esp+28h] [ebp-64h]
  _bstr_t v153; // [esp+2Ch] [ebp-60h]
  _bstr_t v154; // [esp+30h] [ebp-5Ch]
  _bstr_t v155; // [esp+34h] [ebp-58h]
  void *v156; // [esp+38h] [ebp-54h]
  _bstr_t v157; // [esp+3Ch] [ebp-50h]
  int v158; // [esp+40h] [ebp-4Ch]
  void *v159; // [esp+44h] [ebp-48h]
  _bstr_t v160; // [esp+48h] [ebp-44h]
  void *v161; // [esp+4Ch] [ebp-40h]
  void *v162; // [esp+50h] [ebp-3Ch]
  _bstr_t a1; // [esp+54h] [ebp-38h]
  void *v164; // [esp+58h] [ebp-34h]
  int v165; // [esp+5Ch] [ebp-30h]
  _bstr_t v166; // [esp+60h] [ebp-2Ch]
  _bstr_t v167; // [esp+64h] [ebp-28h]
  OLECHAR v168[2]; // [esp+68h] [ebp-24h]
  DWORD dwMessageId; // [esp+6Ch] [ebp-20h]
  _bstr_t v170; // [esp+70h] [ebp-1Ch]
  HINTERNET *v171; // [esp+74h] [ebp-18h]
  _bstr_t a2; // [esp+78h] [ebp-14h]
  bool v173; // [esp+7Fh] [ebp-Dh]
  int v174; // [esp+88h] [ebp-4h]

  v1 = this;
  v171 = this;
  v147 = 0;
  v2 = std::_Tree_comp_alloc<std::_Tmap_traits<unsigned long,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *>>,0>>::_Buyheadnode();
  v146 = v2;
  v3 = v1[3] == 0;
  v174 = 0;
  v165 = 0;
  if ( v3 )
  {
    v4 = 0;
    goto LABEL_475;
  }
  _bstr_t::_bstr_t(&a2, L"[");
  v5 = v1[2];
  v6 = SysFreeString;
  v7 = a2.m_Data;
  LOBYTE(v174) = 1;
  v8 = *v5;
  if ( *v5 != v5 )
  {
    do
    {
      v166.m_Data = v8[2];
      _bstr_t::operator=(&v166.m_Data[2], &gszNullString);
      if ( v165 )
      {
        v9 = operator new(0xCu);
        v10 = v9;
        *psz = v9;
        LOBYTE(v174) = 2;
        if ( v9 )
        {
          v145 = ",";
          *(v9 + 1) = 0;
          *(v9 + 2) = 1;
          *v9 = _com_util::ConvertBSTRToString(v145);
        }
        else
        {
          v10 = 0;
        }
        LOBYTE(v174) = 1;
        *v168 = v10;
        if ( !v10 )
          goto LABEL_311;
        LOBYTE(v174) = 3;
        v11 = operator new(0xCu);
        *psz = v11;
        LOBYTE(v174) = 4;
        v7 = (v11 ? _bstr_t::Data_t::Data_t(v11, &a2, v168) : 0);
        LOBYTE(v174) = 3;
        if ( !v7 )
          goto LABEL_311;
        _bstr_t::_Free(&a2);
        a2.m_Data = v7;
        LOBYTE(v174) = 1;
        if ( !InterlockedDecrement(v10 + 2) )
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
      }
      v12 = operator new(0xCu);
      v13 = v12;
      *psz = v12;
      LOBYTE(v174) = 5;
      if ( v12 )
      {
        v145 = L"{";
        v12[1] = 0;
        v12[2] = 1;
        *v12 = _com_util::ConvertBSTRToString(v145);
      }
      else
      {
        v13 = 0;
      }
      LOBYTE(v174) = 1;
      dwMessageId = v13;
      if ( !v13 )
        goto LABEL_311;
      LOBYTE(v174) = 6;
      v14 = operator new(0xCu);
      *psz = v14;
      LOBYTE(v174) = 7;
      v15 = (v14 ? _bstr_t::Data_t::Data_t(v14, &a2, &dwMessageId) : 0);
      *v168 = v15;
      LOBYTE(v174) = 6;
      if ( !v15 )
        goto LABEL_311;
      if ( v7 )
      {
        if ( !InterlockedDecrement(&v7->m_RefCount) )
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
        v15 = *v168;
      }
      a2.m_Data = v15;
      LOBYTE(v174) = 1;
      if ( !InterlockedDecrement((v13 + 8)) )
      {
        if ( *v13 )
        {
          SysFreeString(*v13);
          *v13 = 0;
        }
        if ( *(v13 + 4) )
        {
          j_j__free(*(v13 + 4));
          *(v13 + 4) = 0;
        }
        j__free(v13);
      }
      v16 = operator new(0xCu);
      v17 = v16;
      *psz = v16;
      LOBYTE(v174) = 8;
      if ( v16 )
      {
        v145 = "\", ";
        v16->m_str = 0;
        v16->m_RefCount = 1;
        v16->m_wstr = _com_util::ConvertBSTRToString(v145);
      }
      else
      {
        v17 = 0;
      }
      LOBYTE(v174) = 1;
      a3.m_Data = v17;
      if ( !v17 )
        goto LABEL_311;
      LOBYTE(v174) = 9;
      v18 = (v166.m_Data->m_wstr ? *v166.m_Data->m_wstr : 0);
      v19 = sub_FA1BC0(&v162, v18);
      LOBYTE(v174) = 10;
      v20 = sub_FA14F0(&a1, "\"autostart_location\": \"", v19);
      LOBYTE(v174) = 11;
      v21 = _bstr_t::operator+(&v20->m_Data, &v164, &a3);
      LOBYTE(v174) = 12;
      v22 = operator new(0xCu);
      *psz = v22;
      LOBYTE(v174) = 13;
      v23 = v22 ? _bstr_t::Data_t::Data_t(v22, &a2, v21) : 0;
      dwMessageId = v23;
      LOBYTE(v174) = 12;
      if ( !v23 )
        goto LABEL_311;
      v24 = *v168;
      if ( !InterlockedDecrement((*v168 + 8)) )
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
      v25 = v164;
      a2.m_Data = dwMessageId;
      if ( v164 )
      {
        if ( !InterlockedDecrement(v164 + 2) && v25 )
        {
          if ( *v25 )
          {
            SysFreeString(*v25);
            *v25 = 0;
          }
          if ( *(v25 + 1) )
          {
            j_j__free(*(v25 + 1));
            *(v25 + 1) = 0;
          }
          j__free(v25);
        }
        v164 = 0;
      }
      v26 = a1.m_Data;
      if ( a1.m_Data )
      {
        if ( !InterlockedDecrement(&a1.m_Data->m_RefCount) && v26 )
        {
          if ( v26->m_wstr )
          {
            SysFreeString(v26->m_wstr);
            v26->m_wstr = 0;
          }
          if ( v26->m_str )
          {
            j_j__free(v26->m_str);
            v26->m_str = 0;
          }
          j__free(v26);
        }
        a1.m_Data = 0;
      }
      v27 = v162;
      if ( v162 )
      {
        if ( !InterlockedDecrement(v162 + 2) && v27 )
        {
          if ( *v27 )
          {
            SysFreeString(*v27);
            *v27 = 0;
          }
          if ( *(v27 + 1) )
          {
            j_j__free(*(v27 + 1));
            *(v27 + 1) = 0;
          }
          j__free(v27);
        }
        v162 = 0;
      }
      LOBYTE(v174) = 1;
      if ( !InterlockedDecrement(&v17->m_RefCount) )
      {
        if ( v17->m_wstr )
        {
          SysFreeString(v17->m_wstr);
          v17->m_wstr = 0;
        }
        if ( v17->m_str )
        {
          j_j__free(v17->m_str);
          v17->m_str = 0;
        }
        j__free(v17);
      }
      v28 = operator new(0xCu);
      v29 = v28;
      *psz = v28;
      LOBYTE(v174) = 14;
      if ( v28 )
      {
        v145 = "\", ";
        v28->m_str = 0;
        v28->m_RefCount = 1;
        v28->m_wstr = _com_util::ConvertBSTRToString(v145);
      }
      else
      {
        v29 = 0;
      }
      LOBYTE(v174) = 1;
      a3.m_Data = v29;
      if ( !v29 )
        goto LABEL_311;
      LOBYTE(v174) = 15;
      v30 = v166.m_Data->m_str;
      v31 = (v30 ? *v30 : 0);
      v32 = sub_FA1BC0(&v159, v31);
      LOBYTE(v174) = 16;
      v33 = sub_FA14F0(&v160, "\"autostart_entry\": \"", v32);
      LOBYTE(v174) = 17;
      v34 = _bstr_t::operator+(&v33->m_Data, &v161, &a3);
      LOBYTE(v174) = 18;
      v35 = operator new(0xCu);
      *psz = v35;
      LOBYTE(v174) = 19;
      v36 = v35 ? _bstr_t::Data_t::Data_t(v35, &a2, v34) : 0;
      *v168 = v36;
      LOBYTE(v174) = 18;
      if ( !v36 )
        goto LABEL_311;
      v37 = dwMessageId;
      if ( !InterlockedDecrement((dwMessageId + 8)) )
      {
        if ( *v37 )
        {
          SysFreeString(*v37);
          *v37 = 0;
        }
        if ( *(v37 + 4) )
        {
          j_j__free(*(v37 + 4));
          *(v37 + 4) = 0;
        }
        j__free(v37);
      }
      v38 = v161;
      a2.m_Data = *v168;
      if ( v161 )
      {
        if ( !InterlockedDecrement(v161 + 2) && v38 )
        {
          if ( *v38 )
          {
            SysFreeString(*v38);
            *v38 = 0;
          }
          if ( *(v38 + 1) )
          {
            j_j__free(*(v38 + 1));
            *(v38 + 1) = 0;
          }
          j__free(v38);
        }
        v161 = 0;
      }
      v39 = v160.m_Data;
      if ( v160.m_Data )
      {
        if ( !InterlockedDecrement(&v160.m_Data->m_RefCount) && v39 )
        {
          if ( v39->m_wstr )
          {
            SysFreeString(v39->m_wstr);
            v39->m_wstr = 0;
          }
          if ( v39->m_str )
          {
            j_j__free(v39->m_str);
            v39->m_str = 0;
          }
          j__free(v39);
        }
        v160.m_Data = 0;
      }
      v40 = v159;
      if ( v159 )
      {
        if ( !InterlockedDecrement(v159 + 2) && v40 )
        {
          if ( *v40 )
          {
            SysFreeString(*v40);
            *v40 = 0;
          }
          if ( *(v40 + 1) )
          {
            j_j__free(*(v40 + 1));
            *(v40 + 1) = 0;
          }
          j__free(v40);
        }
        v159 = 0;
      }
      LOBYTE(v174) = 1;
      if ( !InterlockedDecrement(&v29->m_RefCount) )
      {
        if ( v29->m_wstr )
        {
          SysFreeString(v29->m_wstr);
          v29->m_wstr = 0;
        }
        if ( v29->m_str )
        {
          j_j__free(v29->m_str);
          v29->m_str = 0;
        }
        j__free(v29);
      }
      v41 = operator new(0xCu);
      v42 = v41;
      *psz = v41;
      LOBYTE(v174) = 20;
      if ( v41 )
      {
        v145 = "\", ";
        *(v41 + 1) = 0;
        *(v41 + 2) = 1;
        *v41 = _com_util::ConvertBSTRToString(v145);
      }
      else
      {
        v42 = 0;
      }
      LOBYTE(v174) = 1;
      *psz = v42;
      if ( !v42 )
        goto LABEL_311;
      v43 = v166.m_Data->m_RefCount;
      a3.m_Data = v43;
      if ( v43 )
        InterlockedIncrement(&v43->m_RefCount);
      LOBYTE(v174) = 22;
      v44 = sub_FA14F0(&v157, "\"hash\": \"", &a3);
      LOBYTE(v174) = 23;
      dwMessageId = _bstr_t::operator+(&v44->m_Data, &v158, psz);
      LOBYTE(v174) = 24;
      v45 = operator new(0xCu);
      v148 = v45;
      LOBYTE(v174) = 25;
      v46 = v45 ? _bstr_t::Data_t::Data_t(v45, &a2, dwMessageId) : 0;
      dwMessageId = v46;
      LOBYTE(v174) = 24;
      if ( !v46 )
        goto LABEL_311;
      if ( !InterlockedDecrement((*v168 + 8)) )
      {
        v47 = *v168;
        if ( **v168 )
        {
          SysFreeString(**v168);
          v47 = *v168;
          **v168 = 0;
        }
        if ( v47->m_str )
        {
          j_j__free(v47->m_str);
          v47 = *v168;
          *(*v168 + 4) = 0;
        }
        j__free(v47);
      }
      a2.m_Data = dwMessageId;
      *v168 = v158;
      if ( v158 )
      {
        if ( !InterlockedDecrement((v158 + 8)) )
        {
          v48 = *v168;
          if ( *v168 )
          {
            if ( **v168 )
            {
              SysFreeString(**v168);
              v48 = *v168;
              **v168 = 0;
            }
            if ( v48->m_str )
            {
              j_j__free(v48->m_str);
              v48 = *v168;
              *(*v168 + 4) = 0;
            }
            j__free(v48);
          }
        }
        v158 = 0;
      }
      *v168 = v157;
      if ( v157.m_Data )
      {
        if ( !InterlockedDecrement(&v157.m_Data->m_RefCount) )
        {
          v49 = *v168;
          if ( *v168 )
          {
            if ( **v168 )
            {
              SysFreeString(**v168);
              v49 = *v168;
              **v168 = 0;
            }
            if ( v49->m_str )
            {
              j_j__free(v49->m_str);
              v49 = *v168;
              *(*v168 + 4) = 0;
            }
            j__free(v49);
          }
        }
        v157.m_Data = 0;
      }
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
      LOBYTE(v174) = 1;
      if ( !InterlockedDecrement(v42 + 2) )
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
      v50 = operator new(0xCu);
      v51 = v50;
      v148 = v50;
      LOBYTE(v174) = 26;
      if ( v50 )
      {
        v145 = "\", ";
        *(v50 + 1) = 0;
        *(v50 + 2) = 1;
        *v50 = _com_util::ConvertBSTRToString(v145);
      }
      else
      {
        v51 = 0;
      }
      LOBYTE(v174) = 1;
      *psz = v51;
      if ( !v51 )
        goto LABEL_311;
      LOBYTE(v174) = 27;
      v52 = v166.m_Data[1].m_wstr;
      v53 = (v52 ? *v52 : 0);
      v54 = sub_FA1BC0(&v154, v53);
      LOBYTE(v174) = 28;
      v55 = sub_FA14F0(&v155, "\"image_path\": \"", v54);
      LOBYTE(v174) = 29;
      v56 = _bstr_t::operator+(&v55->m_Data, &v156, psz);
      LOBYTE(v174) = 30;
      v57 = operator new(0xCu);
      v148 = v57;
      LOBYTE(v174) = 31;
      if ( v57 )
      {
        v58 = _bstr_t::Data_t::Data_t(v57, &a2, v56);
        *v168 = v58;
      }
      else
      {
        v58 = 0;
        *v168 = 0;
      }
      LOBYTE(v174) = 30;
      if ( !v58 )
        goto LABEL_311;
      if ( !InterlockedDecrement((dwMessageId + 8)) )
      {
        v59 = dwMessageId;
        if ( *dwMessageId )
        {
          SysFreeString(*dwMessageId);
          v59 = dwMessageId;
          *dwMessageId = 0;
        }
        if ( v59[1] )
        {
          j_j__free(v59[1]);
          v59 = dwMessageId;
          *(dwMessageId + 4) = 0;
        }
        j__free(v59);
      }
      a2.m_Data = v58;
      v60 = v156;
      if ( v156 )
      {
        if ( !InterlockedDecrement(v156 + 2) && v60 )
        {
          if ( *v60 )
          {
            SysFreeString(*v60);
            *v60 = 0;
          }
          if ( *(v60 + 1) )
          {
            j_j__free(*(v60 + 1));
            *(v60 + 1) = 0;
          }
          j__free(v60);
        }
        v156 = 0;
      }
      v61 = v155.m_Data;
      if ( v155.m_Data )
      {
        if ( !InterlockedDecrement(&v155.m_Data->m_RefCount) && v61 )
        {
          if ( v61->m_wstr )
          {
            SysFreeString(v61->m_wstr);
            v61->m_wstr = 0;
          }
          if ( v61->m_str )
          {
            j_j__free(v61->m_str);
            v61->m_str = 0;
          }
          j__free(v61);
        }
        v155.m_Data = 0;
      }
      v62 = v154.m_Data;
      if ( v154.m_Data )
      {
        if ( !InterlockedDecrement(&v154.m_Data->m_RefCount) && v62 )
        {
          if ( v62->m_wstr )
          {
            SysFreeString(v62->m_wstr);
            v62->m_wstr = 0;
          }
          if ( v62->m_str )
          {
            j_j__free(v62->m_str);
            v62->m_str = 0;
          }
          j__free(v62);
        }
        v154.m_Data = 0;
      }
      LOBYTE(v174) = 1;
      if ( !InterlockedDecrement(v51 + 2) )
      {
        if ( *v51 )
        {
          SysFreeString(*v51);
          *v51 = 0;
        }
        if ( *(v51 + 1) )
        {
          j_j__free(*(v51 + 1));
          *(v51 + 1) = 0;
        }
        j__free(v51);
      }
      v63 = operator new(0xCu);
      v64 = v63;
      v148 = v63;
      LOBYTE(v174) = 32;
      if ( v63 )
      {
        v145 = "\"";
        *(v63 + 1) = 0;
        *(v63 + 2) = 1;
        *v63 = _com_util::ConvertBSTRToString(v145);
      }
      else
      {
        v64 = 0;
      }
      LOBYTE(v174) = 1;
      *psz = v64;
      if ( !v64 )
        goto LABEL_311;
      LOBYTE(v174) = 33;
      v65 = sub_FA18A0(&v151, &v166.m_Data[1].m_str);
      LOBYTE(v174) = 34;
      v66 = sub_FA14F0(&v152, "\"creation_datetime\": \"", v65);
      LOBYTE(v174) = 35;
      v67 = _bstr_t::operator+(&v66->m_Data, &v153, psz);
      LOBYTE(v174) = 36;
      v68 = operator new(0xCu);
      v148 = v68;
      LOBYTE(v174) = 37;
      if ( v68 )
      {
        v69 = _bstr_t::Data_t::Data_t(v68, &a2, v67);
        v166.m_Data = v69;
      }
      else
      {
        v69 = 0;
        v166.m_Data = 0;
      }
      LOBYTE(v174) = 36;
      if ( !v69 )
        goto LABEL_311;
      if ( !InterlockedDecrement((*v168 + 8)) )
      {
        v70 = *v168;
        if ( **v168 )
        {
          SysFreeString(**v168);
          v70 = *v168;
          **v168 = 0;
        }
        if ( v70->m_str )
        {
          j_j__free(v70->m_str);
          v70 = *v168;
          *(*v168 + 4) = 0;
        }
        j__free(v70);
      }
      a2.m_Data = v69;
      v71 = v153.m_Data;
      if ( v153.m_Data )
      {
        if ( !InterlockedDecrement(&v153.m_Data->m_RefCount) && v71 )
        {
          if ( v71->m_wstr )
          {
            SysFreeString(v71->m_wstr);
            v71->m_wstr = 0;
          }
          if ( v71->m_str )
          {
            j_j__free(v71->m_str);
            v71->m_str = 0;
          }
          j__free(v71);
        }
        v153.m_Data = 0;
      }
      v72 = v152.m_Data;
      if ( v152.m_Data )
      {
        if ( !InterlockedDecrement(&v152.m_Data->m_RefCount) && v72 )
        {
          if ( v72->m_wstr )
          {
            SysFreeString(v72->m_wstr);
            v72->m_wstr = 0;
          }
          if ( v72->m_str )
          {
            j_j__free(v72->m_str);
            v72->m_str = 0;
          }
          j__free(v72);
        }
        v152.m_Data = 0;
      }
      v73 = v151.m_Data;
      if ( v151.m_Data )
      {
        if ( !InterlockedDecrement(&v151.m_Data->m_RefCount) && v73 )
        {
          if ( v73->m_wstr )
          {
            SysFreeString(v73->m_wstr);
            v73->m_wstr = 0;
          }
          if ( v73->m_str )
          {
            j_j__free(v73->m_str);
            v73->m_str = 0;
          }
          j__free(v73);
        }
        v151.m_Data = 0;
      }
      LOBYTE(v174) = 1;
      if ( !InterlockedDecrement(v64 + 2) )
      {
        if ( *v64 )
        {
          SysFreeString(*v64);
          *v64 = 0;
        }
        if ( *(v64 + 1) )
        {
          j_j__free(*(v64 + 1));
          *(v64 + 1) = 0;
        }
        j__free(v64);
      }
      v74 = operator new(0xCu);
      v75 = v74;
      v148 = v74;
      LOBYTE(v174) = 38;
      if ( v74 )
      {
        v145 = "}";
        *(v74 + 1) = 0;
        *(v74 + 2) = 1;
        *v74 = _com_util::ConvertBSTRToString(v145);
      }
      else
      {
        v75 = 0;
      }
      LOBYTE(v174) = 1;
      *psz = v75;
      if ( !v75 )
        goto LABEL_311;
      LOBYTE(v174) = 39;
      v76 = operator new(0xCu);
      v148 = v76;
      LOBYTE(v174) = 40;
      v7 = (v76 ? _bstr_t::Data_t::Data_t(v76, &a2, psz) : 0);
      LOBYTE(v174) = 39;
      if ( !v7 )
        goto LABEL_311;
      if ( !InterlockedDecrement(&v166.m_Data->m_RefCount) )
      {
        v77 = v166.m_Data;
        if ( v166.m_Data->m_wstr )
        {
          SysFreeString(v166.m_Data->m_wstr);
          v77 = v166.m_Data;
          v166.m_Data->m_wstr = 0;
        }
        if ( v77->m_str )
        {
          j_j__free(v77->m_str);
          v77 = v166.m_Data;
          v166.m_Data->m_str = 0;
        }
        j__free(v77);
      }
      a2.m_Data = v7;
      LOBYTE(v174) = 1;
      if ( !InterlockedDecrement(v75 + 2) )
      {
        if ( *v75 )
        {
          SysFreeString(*v75);
          *v75 = 0;
        }
        if ( *(v75 + 1) )
        {
          j_j__free(*(v75 + 1));
          *(v75 + 1) = 0;
        }
        j__free(v75);
      }
      ++v165;
      v8 = *v8;
    }
    while ( v8 != v171[2] );
    v6 = SysFreeString;
  }
  v78 = operator new(0xCu);
  v79 = v78;
  v148 = v78;
  LOBYTE(v174) = 41;
  if ( v78 )
  {
    v145 = "]";
    *(v78 + 1) = 0;
    *(v78 + 2) = 1;
    *v78 = _com_util::ConvertBSTRToString(v145);
  }
  else
  {
    v79 = 0;
  }
  LOBYTE(v174) = 1;
  *psz = v79;
  if ( !v79 )
LABEL_311:
    _com_issue_error(-2147024882);
  LOBYTE(v174) = 42;
  v80 = operator new(0xCu);
  v148 = v80;
  LOBYTE(v174) = 43;
  if ( v80 )
    v81 = _bstr_t::Data_t::Data_t(v80, &a2, psz);
  else
    v81 = 0;
  v151.m_Data = v81;
  LOBYTE(v174) = 42;
  if ( !v81 )
    _com_issue_error(-2147024882);
  if ( v7 && !InterlockedDecrement(&v7->m_RefCount) )
  {
    if ( v7->m_wstr )
    {
      v6(v7->m_wstr);
      v7->m_wstr = 0;
    }
    if ( v7->m_str )
    {
      j_j__free(v7->m_str);
      v7->m_str = 0;
    }
    j__free(v7);
  }
  v82 = v151.m_Data;
  a2.m_Data = v151.m_Data;
  if ( !InterlockedDecrement(v79 + 2) )
  {
    if ( *v79 )
    {
      v6(*v79);
      *v79 = 0;
    }
    if ( *(v79 + 1) )
    {
      j_j__free(*(v79 + 1));
      *(v79 + 1) = 0;
    }
    j__free(v79);
  }
  *v168 = 0;
  v145 = v168;
  v148 = &v144;
  v144 = v82;
  InterlockedIncrement(&v82->m_RefCount);
  v143 = v83;
  a3.m_Data = &v143;
  LOBYTE(v174) = 45;
  _bstr_t::_bstr_t(&v143, L"Content-Type: application/json\r\n");
  LOBYTE(v174) = 46;
  v84 = operator new(0xCu);
  v85 = v84;
  *psz = v84;
  LOBYTE(v174) = 47;
  if ( v84 )
  {
    v142 = "4e3202fdbe953d628f650229af5b3eb49cd46b2d3bfe5546ae3c5fa48b554e0c";
    *(v84 + 1) = 0;
    *(v84 + 2) = 1;
    *v84 = _com_util::ConvertBSTRToString(v142);
  }
  else
  {
    v85 = 0;
  }
  LOBYTE(v174) = 46;
  *psz = v85;
  if ( !v85 )
    _com_issue_error(-2147024882);
  LOBYTE(v174) = 48;
  v86 = _bstr_t::_bstr_t(&v151, L"/partners/sysinternals/file-reports?apikey=");
  v142 = v87;
  LOBYTE(v174) = 49;
  _bstr_t::operator+(v86, &v142, psz);
  LOBYTE(v174) = 51;
  v88 = sub_FA4F00(v171, v142, v143, v144, v145);
  v89 = v151.m_Data;
  dwMessageId = v88;
  if ( v151.m_Data )
  {
    if ( !InterlockedDecrement(&v151.m_Data->m_RefCount) && v89 )
    {
      if ( v89->m_wstr )
      {
        v6(v89->m_wstr);
        v89->m_wstr = 0;
      }
      if ( v89->m_str )
      {
        j_j__free(v89->m_str);
        v89->m_str = 0;
      }
      j__free(v89);
    }
    v151.m_Data = 0;
  }
  LOBYTE(v174) = 44;
  if ( !InterlockedDecrement(v85 + 2) )
  {
    if ( *v85 )
    {
      v6(*v85);
      *v85 = 0;
    }
    if ( *(v85 + 1) )
    {
      j_j__free(*(v85 + 1));
      *(v85 + 1) = 0;
    }
    j__free(v85);
  }
  v90 = dwMessageId;
  v91 = *v168;
  if ( dwMessageId || !*v168 || !**v168 || (v145 = **v168, !SysStringLen(v145)) )
  {
    v130 = 0;
    v170.m_Data = 0;
    LOBYTE(v174) = 56;
    if ( v90 )
    {
      if ( v90 != 232 )
      {
        v131 = sub_FA4320(psz, v90);
        if ( &v170 != v131 )
        {
          _bstr_t::_Free(&v170);
          v130 = v131->m_Data;
          v170.m_Data = v130;
          if ( v130 )
            InterlockedIncrement(&v130->m_RefCount);
        }
        _bstr_t::_Free(psz);
        goto LABEL_455;
      }
      v145 = L"Throttled request. Try again later.";
    }
    else
    {
      v145 = L"Unable to connect to VT";
    }
    _bstr_t::operator=(&v170, v145);
    v130 = v170.m_Data;
LABEL_455:
    v132 = v171[2];
    v133 = *v132;
    if ( *v132 != v132 )
    {
      v134 = v171;
      do
      {
        v135 = (v133[2] + 24);
        *psz = v135;
        if ( v135 != &v170 )
        {
          _bstr_t::_Free(v135);
          **psz = v130;
          if ( v130 )
            InterlockedIncrement(&v130->m_RefCount);
        }
        v133 = *v133;
      }
      while ( v133 != v134[2] );
      v91 = *v168;
    }
    v4 = 13;
    v123 = &v170;
    goto LABEL_463;
  }
  v92 = v171;
  *psz = v91->m_wstr;
  sub_FA4530(v171, &v167, psz, &v146);
  v145 = v93;
  LOBYTE(v174) = 52;
  _bstr_t::_bstr_t(&v145, "result");
  sub_FA4950(&v166, &v146, v145);
  LOBYTE(v174) = 53;
  if ( v166.m_Data )
    v94 = v166.m_Data->m_wstr;
  else
    v94 = 0;
  if ( _wcsicmp(v94, L"-1") )
  {
    v96 = v166.m_Data ? v166.m_Data->m_wstr : 0;
    if ( _wcsicmp(v96, L"0") )
    {
      v145 = v95;
      _bstr_t::_bstr_t(&v145, "data");
      sub_FA4950(&v152, &v146, v145);
      LOBYTE(v174) = 54;
      if ( v152.m_Data )
        v97 = v152.m_Data->m_wstr;
      else
        v97 = 0;
      *psz = wcschr(v97, 0x5Bu) + 1;
      v98 = v92[2];
      v99 = *v98;
      if ( *v98 == v98 )
      {
LABEL_397:
        v117 = v92[2];
        v118 = *v117;
        if ( *v117 != v117 )
        {
          do
          {
            v119 = v118[2];
            v120 = *(v119 + 28);
            if ( !v120 || (v121 = *v120) == 0 || !SysStringLen(v121) )
            {
              if ( *(v171 + 24) )
                dwMessageId = sub_FA55A0(v171, v119, v168);
              else
                _bstr_t::operator=((v119 + 32), L"Unknown");
            }
            v118 = *v118;
          }
          while ( v118 != v171[2] );
          v91 = *v168;
        }
        v122 = v152.m_Data;
        if ( v152.m_Data && !InterlockedDecrement(&v152.m_Data->m_RefCount) && v122 )
        {
          if ( v122->m_wstr )
          {
            SysFreeString(v122->m_wstr);
            v122->m_wstr = 0;
          }
          if ( v122->m_str )
          {
            j_j__free(v122->m_str);
            v122->m_str = 0;
          }
          j__free(v122);
        }
        v4 = dwMessageId;
        _bstr_t::_Free(&v166);
        v123 = &v167;
        goto LABEL_463;
      }
      v100 = v171;
      while ( 1 )
      {
        v165 = v99[2];
        v101 = sub_FA4530(v100, &v151, psz, &v146);
        if ( &v167 == v101 )
          goto LABEL_370;
        _bstr_t::_Free(&v167);
        v102 = *v101;
        v167.m_Data = v102;
        if ( v102 )
          break;
LABEL_371:
        v103 = v151.m_Data;
        if ( v151.m_Data )
        {
          if ( !InterlockedDecrement(&v151.m_Data->m_RefCount) && v103 )
          {
            if ( v103->m_wstr )
            {
              SysFreeString(v103->m_wstr);
              v103->m_wstr = 0;
            }
            if ( v103->m_str )
            {
              j_j__free(v103->m_str);
              v103->m_str = 0;
            }
            j__free(v103);
          }
          v102 = v167.m_Data;
          v151.m_Data = 0;
        }
        if ( v102 )
        {
          v104 = v102->m_wstr;
          if ( v104 )
          {
            if ( SysStringLen(v104) )
            {
              v145 = L"true";
              v144 = v105;
              _bstr_t::_bstr_t(&v144, L"found");
              v106 = sub_FA4950(&a3, &v146, v144)->m_Data;
              v107 = v106 ? v106->m_wstr : 0;
              v173 = _wcsicmp(v107, v145) == 0;
              _bstr_t::_Free(&a3);
              if ( v173 )
              {
                v145 = v108;
                _bstr_t::_bstr_t(&v145, L"detection_ratio");
                v109 = sub_FA4950(&v154, &v146, v145);
                v110 = (v165 + 32);
                v153.m_Data = v109;
                if ( (v165 + 32) != v109 )
                {
                  _bstr_t::_Free((v165 + 32));
                  v111 = v153.m_Data->m_wstr;
                  *v110 = v153.m_Data->m_wstr;
                  if ( v111 )
                    InterlockedIncrement(v111 + 2);
                }
                _bstr_t::_Free(&v154);
                v145 = v112;
                _bstr_t::_bstr_t(&v145, L"Permalink");
                v113 = sub_FA4950(&v155, &v146, v145);
                v114 = (v165 + 28);
                v153.m_Data = v113;
                if ( (v165 + 28) != v113 )
                {
                  _bstr_t::_Free((v165 + 28));
                  v115 = v153.m_Data->m_wstr;
                  *v114 = v153.m_Data->m_wstr;
                  if ( v115 )
                    InterlockedIncrement(v115 + 2);
                }
                _bstr_t::_Free(&v155);
              }
              else
              {
                v116 = v165;
                _bstr_t::operator=((v165 + 32), &gszNullString);
                _bstr_t::operator=((v116 + 28), &gszNullString);
              }
              v99 = *v99;
              if ( v99 != v100[2] )
                continue;
            }
          }
        }
        v91 = *v168;
        v92 = v171;
        goto LABEL_397;
      }
      InterlockedIncrement(&v102->m_RefCount);
LABEL_370:
      v102 = v167.m_Data;
      goto LABEL_371;
    }
  }
  v145 = v95;
  _bstr_t::_bstr_t(&v145, L"message");
  sub_FA4950(&v153, &v146, v145);
  LOBYTE(v174) = 55;
  if ( !v153.m_Data || !v153.m_Data->m_wstr || (v145 = v153.m_Data->m_wstr, !SysStringLen(v145)) )
  {
    v4 = 0;
    goto LABEL_444;
  }
  v124 = v92[2];
  v125 = *v124;
  if ( *v124 == v124 )
    goto LABEL_443;
  v126 = v171;
  do
  {
    v151.m_Data = v125[2];
    v127 = _bstr_t::_bstr_t(&v152, "message");
    v128 = *(*sub_1002F90(&v146, &v148, v127) + 20);
    if ( v128 )
      InterlockedIncrement((v128 + 8));
    if ( &v151.m_Data[2] != psz )
    {
      _bstr_t::_Free(&v151.m_Data[2]);
      v151.m_Data[2].m_wstr = v128;
      if ( !v128 )
        goto LABEL_432;
      InterlockedIncrement((v128 + 8));
    }
    if ( v128 && !InterlockedDecrement((v128 + 8)) )
    {
      if ( *v128 )
      {
        SysFreeString(*v128);
        *v128 = 0;
      }
      if ( *(v128 + 4) )
      {
        j_j__free(*(v128 + 4));
        *(v128 + 4) = 0;
      }
      j__free(v128);
    }
LABEL_432:
    v129 = v152.m_Data;
    if ( v152.m_Data )
    {
      if ( !InterlockedDecrement(&v152.m_Data->m_RefCount) && v129 )
      {
        if ( v129->m_wstr )
        {
          SysFreeString(v129->m_wstr);
          v129->m_wstr = 0;
        }
        if ( v129->m_str )
        {
          j_j__free(v129->m_str);
          v129->m_str = 0;
        }
        j__free(v129);
      }
      v152.m_Data = 0;
    }
    v125 = *v125;
  }
  while ( v125 != v126[2] );
  v91 = *v168;
LABEL_443:
  v4 = dwMessageId;
LABEL_444:
  _bstr_t::_Free(&v153);
  _bstr_t::_Free(&v166);
  v123 = &v167;
LABEL_463:
  _bstr_t::_Free(v123);
  v136 = v171;
  v137 = v171[2];
  v138 = *v137;
  *v137 = v137;
  *(v136[2] + 1) = v136[2];
  v136[3] = 0;
  if ( v138 != v136[2] )
  {
    v139 = v136;
    do
    {
      v140 = *v138;
      j__free(v138);
      v138 = v140;
    }
    while ( v140 != v139[2] );
    v91 = *v168;
  }
  if ( v91 && !InterlockedDecrement(&v91->m_RefCount) )
  {
    if ( v91->m_wstr )
    {
      SysFreeString(v91->m_wstr);
      v91->m_wstr = 0;
    }
    if ( v91->m_str )
    {
      j_j__free(v91->m_str);
      v91->m_str = 0;
    }
    j__free(v91);
  }
  _bstr_t::_Free(&a2);
  v2 = v146;
LABEL_475:
  v145 = v2;
  v144 = v2->baseclass._Left;
  v174 = -1;
  sub_FA6540(&v146, &v148, v144, v2);
  j__free(v146);
  return v4;
}
// 1034790: using guessed type wchar_t aThrottledReque[36];

//----- (00FA37E0) --------------------------------------------------------
Data_t_bstr_t *__thiscall sub_FA37E0(_DWORD *this)
{
  _DWORD *v1; // ebx
  CSystemProcessInfoMapNode *v2; // eax
  char *v3; // esi
  Data_t_bstr_t *v4; // esi
  _bstr_t *v5; // eax
  _bstr_t *v6; // eax
  _DWORD *v7; // eax
  LONG (__stdcall *v8)(volatile LONG *); // ebx
  _DWORD *v9; // edi
  Data_t_bstr_t *v10; // eax
  Data_t_bstr_t *v11; // esi
  Data_t_bstr_t *v12; // eax
  Data_t_bstr_t *v13; // eax
  Data_t_bstr_t *v14; // esi
  Data_t_bstr_t *v15; // eax
  Data_t_bstr_t *v16; // ebx
  Data_t_bstr_t *v17; // ebx
  CSystemProcessInfoMapNode **v18; // ecx
  void *v19; // ecx
  _DWORD *v20; // edi
  Data_t_bstr_t *v21; // ebx
  const wchar_t **v22; // esi
  const wchar_t *v23; // esi
  Data_t_bstr_t *v24; // edi
  void *v25; // ecx
  wchar_t **v26; // eax
  wchar_t *v27; // ebx
  _bstr_t *v28; // esi
  void *v29; // esi
  CSystemProcessInfoMapNode *v30; // ecx
  OLECHAR *v31; // eax
  OLECHAR *v32; // esi
  BSTR v33; // eax
  Data_t_bstr_t *v34; // eax
  const wchar_t *v35; // eax
  int v36; // eax
  wchar_t *v37; // ecx
  void *v38; // esi
  char v39; // al
  wchar_t *v40; // ecx
  _bstr_t *v41; // eax
  Data_t_bstr_t *v42; // eax
  int v43; // edx
  Data_t_bstr_t *v44; // ecx
  int *v45; // eax
  int v46; // esi
  BSTR v47; // eax
  Data_t_bstr_t *v48; // esi
  Data_t_bstr_t *v49; // esi
  Data_t_bstr_t *v50; // esi
  Data_t_bstr_t *v51; // ecx
  int *v52; // eax
  int v53; // esi
  BSTR v54; // eax
  Data_t_bstr_t *v55; // esi
  wchar_t *v56; // eax
  void *v57; // esi
  void *v58; // esi
  LONG (__stdcall *v59)(volatile LONG *); // edi
  void *v60; // ebx
  Data_t_bstr_t *v61; // esi
  Data_t_bstr_t *v63; // esi
  _bstr_t *v64; // edi
  _DWORD *v65; // eax
  _DWORD *v66; // edi
  Data_t_bstr_t *v67; // eax
  BSTR v68; // ebx
  void *v69; // [esp-10h] [ebp-80h]
  OLECHAR *v70; // [esp-Ch] [ebp-7Ch]
  CSystemProcessInfoMapNode *v71; // [esp-8h] [ebp-78h]
  wchar_t *v72; // [esp-4h] [ebp-74h]
  void *v73; // [esp+10h] [ebp-60h]
  int v74; // [esp+14h] [ebp-5Ch]
  void *v75; // [esp+18h] [ebp-58h]
  _bstr_t v76; // [esp+1Ch] [ebp-54h]
  _bstr_t a1; // [esp+20h] [ebp-50h]
  _bstr_t bstr; // [esp+24h] [ebp-4Ch]
  _bstr_t a3; // [esp+28h] [ebp-48h]
  void *v80; // [esp+2Ch] [ebp-44h]
  void *v81; // [esp+30h] [ebp-40h]
  OLECHAR psz[2]; // [esp+34h] [ebp-3Ch]
  _bstr_t bstrResource; // [esp+38h] [ebp-38h]
  void *v84; // [esp+3Ch] [ebp-34h]
  _bstr_t v85; // [esp+40h] [ebp-30h]
  void *v86; // [esp+44h] [ebp-2Ch]
  void *v87; // [esp+48h] [ebp-28h]
  _bstr_t v88; // [esp+4Ch] [ebp-24h]
  int v89; // [esp+50h] [ebp-20h]
  _bstr_t v90; // [esp+54h] [ebp-1Ch]
  _bstr_t a2; // [esp+58h] [ebp-18h]
  _DWORD *v92; // [esp+5Ch] [ebp-14h]
  char v93; // [esp+63h] [ebp-Dh]
  int v94; // [esp+6Ch] [ebp-4h]

  v1 = this;
  v92 = this;
  v74 = 0;
  v2 = std::_Tree_comp_alloc<std::_Tmap_traits<unsigned long,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *>>,0>>::_Buyheadnode();
  v73 = v2;
  v3 = 0;
  v94 = 0;
  v84 = 0;
  if ( !v1[5] )
  {
    v4 = 232;
    goto LABEL_188;
  }
  _bstr_t::_bstr_t(&bstrResource, "&resource=");
  LOBYTE(v94) = 1;
  v5 = _bstr_t::_bstr_t(&bstr, "4e3202fdbe953d628f650229af5b3eb49cd46b2d3bfe5546ae3c5fa48b554e0c");
  LOBYTE(v94) = 2;
  v6 = sub_FA14F0(&a1, "apikey=", v5);
  LOBYTE(v94) = 3;
  _bstr_t::operator+(&v6->m_Data, &a2, &bstrResource);
  _bstr_t::_Free(&a1);
  _bstr_t::_Free(&bstr);
  LOBYTE(v94) = 7;
  _bstr_t::_Free(&bstrResource);
  v7 = v1[4];
  v8 = InterlockedDecrement;
  v9 = *v7;
  if ( *v7 != v7 )
  {
    do
    {
      v80 = v9[2];
      _bstr_t::operator=((v80 + 24), &gszNullString);
      if ( v3 )
      {
        v10 = operator new(0xCu);
        v11 = v10;
        v76.m_Data = v10;
        LOBYTE(v94) = 8;
        if ( v10 )
        {
          v72 = ",";
          v10->m_str = 0;
          v10->m_RefCount = 1;
          v10->m_wstr = _com_util::ConvertBSTRToString(v72);
        }
        else
        {
          v11 = 0;
        }
        LOBYTE(v94) = 7;
        a3.m_Data = v11;
        if ( !v11 )
          goto LABEL_74;
        LOBYTE(v94) = 9;
        v12 = operator new(0xCu);
        v76.m_Data = v12;
        LOBYTE(v94) = 10;
        v13 = (v12 ? _bstr_t::Data_t::Data_t(v12, &a2, &a3) : 0);
        bstrResource.m_Data = v13;
        LOBYTE(v94) = 9;
        if ( !v13 )
          goto LABEL_74;
        _bstr_t::_Free(&a2);
        a2.m_Data = bstrResource.m_Data;
        if ( !v8(&v11->m_RefCount) )
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
      }
      v14 = *(v80 + 2);
      a3.m_Data = v14;
      if ( v14 )
        InterlockedIncrement(&v14->m_RefCount);
      LOBYTE(v94) = 11;
      v15 = operator new(0xCu);
      v76.m_Data = v15;
      LOBYTE(v94) = 12;
      if ( v15 )
      {
        v16 = _bstr_t::Data_t::Data_t(v15, &a2, &a3);
        bstrResource.m_Data = v16;
      }
      else
      {
        v16 = 0;
        bstrResource.m_Data = 0;
      }
      LOBYTE(v94) = 11;
      if ( !v16 )
LABEL_74:
        _com_issue_error(-2147024882);
      v17 = a2.m_Data;
      if ( a2.m_Data && !InterlockedDecrement(&a2.m_Data->m_RefCount) && v17 )
      {
        if ( v17->m_wstr )
        {
          SysFreeString(v17->m_wstr);
          v17->m_wstr = 0;
        }
        if ( v17->m_str )
        {
          j_j__free(v17->m_str);
          v17->m_str = 0;
        }
        j__free(v17);
      }
      v8 = InterlockedDecrement;
      a2.m_Data = bstrResource.m_Data;
      LOBYTE(v94) = 7;
      if ( v14 && !InterlockedDecrement(&v14->m_RefCount) )
      {
        if ( v14->m_wstr )
        {
          SysFreeString(v14->m_wstr);
          v14->m_wstr = 0;
        }
        if ( v14->m_str )
        {
          j_j__free(v14->m_str);
          v14->m_str = 0;
        }
        j__free(v14);
      }
      v9 = *v9;
      v3 = v84 + 1;
      v84 = v84 + 1;
    }
    while ( v9 != v92[4] );
  }
  v84 = 0;
  v72 = &v84;
  v76.m_Data = &v71;
  v18 = &v71;
  v71 = a2.m_Data;
  if ( a2.m_Data )
    InterlockedIncrement(&a2.m_Data->m_RefCount);
  v70 = v18;
  a1.m_Data = &v70;
  LOBYTE(v94) = 14;
  _bstr_t::_bstr_t(&v70, L"Content-Type: application/x-www-form-urlencoded\r\n");
  v69 = v19;
  LOBYTE(v94) = 15;
  _bstr_t::_bstr_t(&v69, L"vtapi/v2/file/report");
  v20 = v92;
  LOBYTE(v94) = 13;
  v21 = sub_FA4F00(v92, v69, v70, v71, v72);
  bstrResource.m_Data = v21;
  if ( !v21 )
  {
    v22 = v84;
    if ( v84 )
    {
      if ( *v84 )
      {
        v72 = *v84;
        if ( SysStringLen(v72) )
        {
          v23 = *v22;
          *psz = v23;
          if ( wcschr(v23, 0x5Bu) )
            *psz = wcschr(v23, 0x5Bu) + 1;
          v24 = 0;
          v85.m_Data = 0;
          v25 = v92;
          LOBYTE(v94) = 16;
          v26 = v92[4];
          v27 = *v26;
          if ( *v26 != v26 )
          {
            do
            {
              v89 = *(v27 + 2);
              v28 = sub_FA4530(v25, &v81, psz, &v73);
              if ( &v85 != v28 )
              {
                if ( v24 && !InterlockedDecrement(&v24->m_RefCount) )
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
                v24 = v28->m_Data;
                v85.m_Data = v24;
                if ( v24 )
                  InterlockedIncrement(&v24->m_RefCount);
              }
              v29 = v81;
              if ( v81 )
              {
                if ( !InterlockedDecrement(v81 + 2) && v29 )
                {
                  if ( *v29 )
                  {
                    SysFreeString(*v29);
                    *v29 = 0;
                  }
                  if ( *(v29 + 1) )
                  {
                    j_j__free(*(v29 + 1));
                    *(v29 + 1) = 0;
                  }
                  j__free(v29);
                }
                v81 = 0;
              }
              if ( !v24 )
                break;
              if ( !v24->m_wstr )
                break;
              v72 = v24->m_wstr;
              if ( !SysStringLen(v72) )
                break;
              v72 = L"1";
              v71 = v30;
              v76.m_Data = &v71;
              v31 = operator new(0xCu);
              v32 = v31;
              v75 = v31;
              LOBYTE(v94) = 17;
              if ( v31 )
              {
                v70 = L"response_code";
                *(v31 + 1) = 0;
                *(v31 + 2) = 1;
                v33 = SysAllocString(v70);
                *v32 = v33;
                if ( !v33 )
                  goto LABEL_74;
              }
              else
              {
                v32 = 0;
              }
              LOBYTE(v94) = 16;
              v76.m_Data->m_wstr = v32;
              if ( !v32 )
                goto LABEL_74;
              v34 = sub_FA4950(&v80, &v73, v71)->m_Data;
              if ( v34 )
                v35 = v34->m_wstr;
              else
                v35 = 0;
              v36 = _wcsicmp(v35, v72);
              v38 = v80;
              v39 = v36 == 0;
              v93 = v39;
              if ( v80 )
              {
                if ( !InterlockedDecrement(v80 + 2) && v38 )
                {
                  if ( *v38 )
                  {
                    SysFreeString(*v38);
                    *v38 = 0;
                  }
                  if ( *(v38 + 1) )
                  {
                    j_j__free(*(v38 + 1));
                    *(v38 + 1) = 0;
                  }
                  j__free(v38);
                }
                v39 = v93;
                v80 = 0;
              }
              if ( v39 )
              {
                v72 = v37;
                _bstr_t::_bstr_t(&v72, L"positives");
                sub_FA4950(&v86, &v73, v72);
                v72 = v40;
                LOBYTE(v94) = 18;
                _bstr_t::_bstr_t(&v72, L"total");
                sub_FA4950(&v87, &v73, v72);
                LOBYTE(v94) = 19;
                _bstr_t::_bstr_t(&v88, L"/");
                LOBYTE(v94) = 20;
                v41 = _bstr_t::operator+(&v86, &bstr, &v88);
                LOBYTE(v94) = 21;
                v42 = _bstr_t::operator+(&v41->m_Data, &a3, &v87);
                v43 = v89;
                v44 = v42;
                v76.m_Data = v42;
                v45 = (v89 + 32);
                if ( (v89 + 32) != v76.m_Data )
                {
                  v46 = *v45;
                  if ( *v45 )
                  {
                    if ( !InterlockedDecrement((v46 + 8)) && v46 )
                    {
                      if ( *v46 )
                      {
                        SysFreeString(*v46);
                        *v46 = 0;
                      }
                      if ( *(v46 + 4) )
                      {
                        j_j__free(*(v46 + 4));
                        *(v46 + 4) = 0;
                      }
                      j__free(v46);
                    }
                    v43 = v89;
                    v44 = v76.m_Data;
                    *(v89 + 32) = 0;
                  }
                  v47 = v44->m_wstr;
                  *(v43 + 32) = v44->m_wstr;
                  if ( v47 )
                    InterlockedIncrement(v47 + 2);
                }
                v48 = a3.m_Data;
                if ( a3.m_Data )
                {
                  if ( !InterlockedDecrement(&a3.m_Data->m_RefCount) && v48 )
                  {
                    if ( v48->m_wstr )
                    {
                      SysFreeString(v48->m_wstr);
                      v48->m_wstr = 0;
                    }
                    if ( v48->m_str )
                    {
                      j_j__free(v48->m_str);
                      v48->m_str = 0;
                    }
                    j__free(v48);
                  }
                  a3.m_Data = 0;
                }
                v49 = bstr.m_Data;
                if ( bstr.m_Data )
                {
                  if ( !InterlockedDecrement(&bstr.m_Data->m_RefCount) && v49 )
                  {
                    if ( v49->m_wstr )
                    {
                      SysFreeString(v49->m_wstr);
                      v49->m_wstr = 0;
                    }
                    if ( v49->m_str )
                    {
                      j_j__free(v49->m_str);
                      v49->m_str = 0;
                    }
                    j__free(v49);
                  }
                  bstr.m_Data = 0;
                }
                v50 = v88.m_Data;
                LOBYTE(v94) = 19;
                if ( v88.m_Data )
                {
                  if ( !InterlockedDecrement(&v88.m_Data->m_RefCount) )
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
                  v88.m_Data = 0;
                }
                v72 = v44;
                _bstr_t::_bstr_t(&v72, L"Permalink");
                v51 = sub_FA4950(&a1, &v73, v72);
                v52 = (v89 + 28);
                v76.m_Data = v51;
                if ( (v89 + 28) != v51 )
                {
                  v53 = *v52;
                  if ( *v52 )
                  {
                    if ( !InterlockedDecrement((v53 + 8)) && v53 )
                    {
                      if ( *v53 )
                      {
                        SysFreeString(*v53);
                        *v53 = 0;
                      }
                      if ( *(v53 + 4) )
                      {
                        j_j__free(*(v53 + 4));
                        *(v53 + 4) = 0;
                      }
                      j__free(v53);
                    }
                    v51 = v76.m_Data;
                    *(v89 + 28) = 0;
                  }
                  v54 = v51->m_wstr;
                  *(v89 + 28) = v51->m_wstr;
                  if ( v54 )
                    InterlockedIncrement(v54 + 2);
                }
                v55 = a1.m_Data;
                if ( a1.m_Data )
                {
                  if ( !InterlockedDecrement(&a1.m_Data->m_RefCount) && v55 )
                  {
                    if ( v55->m_wstr )
                    {
                      SysFreeString(v55->m_wstr);
                      v55->m_wstr = 0;
                    }
                    if ( v55->m_str )
                    {
                      j_j__free(v55->m_str);
                      v55->m_str = 0;
                    }
                    j__free(v55);
                  }
                  a1.m_Data = 0;
                }
                v56 = v27;
                v27 = *v27;
                v72 = v56;
                **(v56 + 1) = *v56;
                *(*v56 + 4) = *(v56 + 1);
                --v92[5];
                j__free(v72);
                v57 = v87;
                if ( v87 )
                {
                  if ( !InterlockedDecrement(v87 + 2) && v57 )
                  {
                    if ( *v57 )
                    {
                      SysFreeString(*v57);
                      *v57 = 0;
                    }
                    if ( *(v57 + 1) )
                    {
                      j_j__free(*(v57 + 1));
                      *(v57 + 1) = 0;
                    }
                    j__free(v57);
                  }
                  v87 = 0;
                }
                v58 = v86;
                LOBYTE(v94) = 16;
                if ( v86 )
                {
                  if ( !InterlockedDecrement(v86 + 2) && v58 )
                  {
                    if ( *v58 )
                    {
                      SysFreeString(*v58);
                      *v58 = 0;
                    }
                    if ( *(v58 + 1) )
                    {
                      j_j__free(*(v58 + 1));
                      *(v58 + 1) = 0;
                    }
                    j__free(v58);
                  }
                  v86 = 0;
                }
              }
              else
              {
                v27 = *v27;
              }
              v25 = v92;
            }
            while ( v27 != v92[4] );
          }
          _bstr_t::_Free(&v85);
          goto LABEL_170;
        }
      }
    }
  }
  v63 = 0;
  v90.m_Data = 0;
  LOBYTE(v94) = 22;
  if ( !v21 )
  {
    v72 = L"Unable to connect to VT";
    goto LABEL_197;
  }
  if ( v21 == 232 )
  {
    v72 = L"Throttled request. Try again later.";
LABEL_197:
    _bstr_t::operator=(&v90, v72);
    v63 = v90.m_Data;
    goto LABEL_198;
  }
  v64 = sub_FA4320(&v76, v21);
  if ( &v90 != v64 )
  {
    _bstr_t::_Free(&v90);
    v63 = v64->m_Data;
    if ( v64->m_Data )
      InterlockedIncrement(&v63->m_RefCount);
  }
  _bstr_t::_Free(&v76);
  v20 = v92;
LABEL_198:
  v65 = v20[4];
  v66 = *v65;
  if ( *v65 != v65 )
  {
    do
    {
      v67 = (v66[2] + 24);
      v76.m_Data = v67;
      if ( v67 != &v90 )
      {
        v68 = v67->m_wstr;
        if ( v67->m_wstr )
        {
          if ( !InterlockedDecrement(v68 + 2) && v68 )
          {
            if ( *v68 )
            {
              SysFreeString(*v68);
              *v68 = 0;
            }
            if ( *(v68 + 1) )
            {
              j_j__free(*(v68 + 1));
              *(v68 + 1) = 0;
            }
            j__free(v68);
          }
          v67 = v76.m_Data;
          v76.m_Data->m_wstr = 0;
        }
        v67->m_wstr = v63;
        if ( v63 )
          InterlockedIncrement(&v63->m_RefCount);
      }
      v66 = *v66;
    }
    while ( v66 != v92[4] );
  }
  bstrResource.m_Data = 13;
  if ( v63 )
  {
    v59 = InterlockedDecrement;
    if ( !InterlockedDecrement(&v63->m_RefCount) )
    {
      if ( v63->m_wstr )
      {
        SysFreeString(v63->m_wstr);
        v63->m_wstr = 0;
      }
      if ( v63->m_str )
      {
        j_j__free(v63->m_str);
        v63->m_str = 0;
      }
      j__free(v63);
    }
    goto LABEL_171;
  }
LABEL_170:
  v59 = InterlockedDecrement;
LABEL_171:
  v60 = v84;
  if ( v84 && !v59(v84 + 2) )
  {
    if ( *v60 )
    {
      SysFreeString(*v60);
      *v60 = 0;
    }
    if ( *(v60 + 1) )
    {
      j_j__free(*(v60 + 1));
      *(v60 + 1) = 0;
    }
    j__free(v60);
  }
  v61 = a2.m_Data;
  if ( a2.m_Data )
  {
    if ( !v59(&a2.m_Data->m_RefCount) && v61 )
    {
      if ( v61->m_wstr )
      {
        SysFreeString(v61->m_wstr);
        v61->m_wstr = 0;
      }
      if ( v61->m_str )
      {
        j_j__free(v61->m_str);
        v61->m_str = 0;
      }
      j__free(v61);
    }
    a2.m_Data = 0;
  }
  v4 = bstrResource.m_Data;
  v2 = v73;
LABEL_188:
  v72 = v2;
  v71 = v2->baseclass._Left;
  v94 = -1;
  sub_FA6540(&v73, &v75, v71, v2);
  j__free(v73);
  return v4;
}
// 1034790: using guessed type wchar_t aThrottledReque[36];

//----- (00FA4320) --------------------------------------------------------
int __stdcall sub_FA4320(int a1, DWORD dwMessageId)
{
  HMODULE v2; // eax
  wchar_t *i; // esi
  int v4; // eax
  WCHAR Buffer; // [esp+Ch] [ebp-804h]

  Buffer = 0;
  if ( !FormatMessageW(0x1200u, 0, dwMessageId, 0, &Buffer, 0x400u, 0) )
  {
    v2 = GetModuleHandleW(L"winhttp.dll");
    FormatMessageW(0xA00u, v2, dwMessageId, 0, &Buffer, 0x400u, 0);
  }
  if ( Buffer )
  {
    for ( i = wcschr(&Buffer, 0); i > &Buffer; *i = 0 )
    {
      v4 = *(i - 1);
      --i;
      if ( !isspace(v4) )
        break;
    }
  }
  else
  {
    _swprintf(&Buffer, L"Error %d (0x%0x)", dwMessageId, dwMessageId);
  }
  _bstr_t::_bstr_t(a1, &Buffer);
  return a1;
}

//----- (00FA4420) --------------------------------------------------------
DWORD __stdcall sub_FA4420(void *a1, int a2, int a3)
{
  const WCHAR *v3; // eax
  HANDLE v4; // esi
  DWORD v5; // edi
  DWORD v6; // edi
  void *v7; // ebx
  LARGE_INTEGER FileSize; // [esp+0h] [ebp-Ch]
  DWORD NumberOfBytesRead; // [esp+8h] [ebp-4h]

  if ( a1 )
    v3 = *a1;
  else
    v3 = 0;
  v4 = CreateFileW(v3, 0x80000000, 7u, 0, 3u, 0, 0);
  if ( v4 == -1 )
  {
    v5 = GetLastError();
  }
  else
  {
    GetFileSizeEx(v4, &FileSize);
    v6 = FileSize.LowPart;
    if ( FileSize.QuadPart <= 0x2000000 )
    {
      v7 = malloc(FileSize.LowPart);
      if ( ReadFile(v4, v7, v6, &NumberOfBytesRead, 0) )
      {
        CloseHandle(v4);
        v5 = 0;
        *a2 = v7;
        *a3 = FileSize.LowPart;
      }
      else
      {
        free(v7);
        CloseHandle(v4);
        v5 = GetLastError();
      }
    }
    else
    {
      v5 = 223;
    }
  }
  if ( a1 && !InterlockedDecrement(a1 + 2) && a1 )
  {
    if ( *a1 )
    {
      SysFreeString(*a1);
      *a1 = 0;
    }
    if ( *(a1 + 1) )
    {
      j_j__free(*(a1 + 1));
      *(a1 + 1) = 0;
    }
    j__free(a1);
  }
  return v5;
}

//----- (00FA4530) --------------------------------------------------------
BSTR **__thiscall sub_FA4530(void *this, int a2, OLECHAR psz, int a4)
{
  std__tree *v4; // esi
  signed int v5; // edi
  bool v6; // bl
  const wchar_t **v7; // eax
  wchar_t *v8; // eax
  OLECHAR *v9; // edx
  OLECHAR *i; // esi
  int v11; // ecx
  BSTR **v12; // ebx
  BSTR v13; // eax
  bool v14; // zf
  CSystemProcessInfoMapNode *v15; // eax
  void *v16; // esi
  void *v17; // esi
  int v19; // [esp+10h] [ebp-2Ch]
  int a2a; // [esp+18h] [ebp-24h]
  void *v21; // [esp+1Ch] [ebp-20h]
  int v22; // [esp+20h] [ebp-1Ch]
  void *v23; // [esp+24h] [ebp-18h]
  void *v24; // [esp+28h] [ebp-14h]
  void *v25; // [esp+2Ch] [ebp-10h]
  int v26; // [esp+38h] [ebp-4h]

  v23 = this;
  *a2 = 0;
  v4 = a4;
  v5 = 1;
  v26 = 0;
  v22 = 1;
  v6 = 0;
  sub_FA6500(*(*a4 + 4));
  v4->_Mypair._Myval2._Myhead->_Parent = v4->_Mypair._Myval2._Myhead;
  v4->_Mypair._Myval2._Myhead->_Left = v4->_Mypair._Myval2._Myhead;
  v4->_Mypair._Myval2._Myhead->_Right = v4->_Mypair._Myval2._Myhead;
  v7 = psz;
  v4->_Mypair._Myval2._Mysize = 0;
  v8 = wcschr(*v7, 0x7Bu);
  if ( v8 )
  {
    v9 = v8 + 1;
    for ( i = v8 + 1; *i; ++i )
    {
      v11 = *i;
      if ( v11 == 125 && v6 != 1 && !v5 )
        break;
      if ( (i != v9 || v11 != 34) && (v11 == 93 || v11 != 34) )
      {
        if ( !v6 )
        {
          if ( v11 == 91 || v11 == 123 )
          {
            ++v5;
          }
          else if ( (v11 == 93 || v11 == 125) && !--v5 )
          {
            break;
          }
        }
      }
      else
      {
        v6 = v6 == 0;
      }
    }
    if ( !*i || v6 )
    {
      v12 = a2;
      _bstr_t::operator=(a2, v9);
      *psz = i;
      v4 = a4;
    }
    else
    {
      v12 = a2;
      *i = 0;
      _bstr_t::operator=(a2, v9);
      *i = 125;
      *psz = i;
      v4 = a4;
    }
  }
  else
  {
    v12 = a2;
  }
  if ( !*v12 || !**v12 || !SysStringLen(**v12) )
    return v12;
  v13 = *v12 ? **v12 : 0;
  v14 = *v13 == 0;
  *&psz = v13;
  if ( v14 )
    return v12;
  do
  {
    sub_FA4810(&v24, &psz, 58);
    v26 = 1;
    sub_FA4810(&v25, &psz, 44);
    a2a = v24;
    if ( v24 )
      InterlockedIncrement(v24 + 2);
    v21 = v25;
    if ( v25 )
      InterlockedIncrement(v25 + 2);
    LOBYTE(v26) = 3;
    v15 = sub_FA11F0(v4, &a2a);
    sub_FA1240(v4, &v19, 0, &v15->_Keyvalue, v15);
    sub_FA1430(&a2a);
    v16 = v25;
    if ( v25 )
    {
      if ( !InterlockedDecrement(v25 + 2) && v16 )
      {
        if ( *v16 )
        {
          SysFreeString(*v16);
          *v16 = 0;
        }
        if ( *(v16 + 1) )
        {
          j_j__free(*(v16 + 1));
          *(v16 + 1) = 0;
        }
        j__free(v16);
      }
      v25 = 0;
    }
    v17 = v24;
    LOBYTE(v26) = 0;
    if ( v24 )
    {
      if ( !InterlockedDecrement(v24 + 2) && v17 )
      {
        if ( *v17 )
        {
          SysFreeString(*v17);
          *v17 = 0;
        }
        if ( *(v17 + 1) )
        {
          j_j__free(*(v17 + 1));
          *(v17 + 1) = 0;
        }
        j__free(v17);
      }
      v24 = 0;
    }
    v4 = a4;
  }
  while ( *psz );
  return a2;
}

//----- (00FA4810) --------------------------------------------------------
int __stdcall sub_FA4810(int a1, OLECHAR *psz, __int16 a3)
{
  char v3; // dl
  int v4; // ecx
  OLECHAR *v5; // edi
  _WORD *v6; // eax
  int v7; // esi
  int v8; // eax
  __int16 v9; // si
  _WORD *v10; // eax
  int result; // eax
  char v12; // [esp+17h] [ebp-Dh]
  OLECHAR *psza; // [esp+30h] [ebp+Ch]

  v3 = 0;
  v4 = 0;
  v12 = 0;
  *a1 = 0;
  v5 = psz;
  if ( **psz )
  {
    do
    {
      if ( **psz != 32 )
        break;
      v6 = (*psz + 2);
      *psz = v6;
    }
    while ( *v6 );
  }
  if ( **psz == 34 )
  {
    v3 = 1;
    v12 = 1;
    *psz += 2;
  }
  v7 = *psz;
  psza = *psz;
  if ( **v5 )
  {
    while ( v4 || v3 || **v5 != a3 )
    {
      v8 = **v5;
      if ( v8 == 34 )
      {
        v3 = v12;
        if ( v12 && !v4 )
          break;
      }
      else
      {
        if ( v8 == 91 )
        {
          ++v4;
        }
        else if ( v8 == 93 )
        {
          --v4;
        }
        else if ( v8 == 92 && **(v5 + 1) == 34 )
        {
          *v5 += 2;
        }
        v3 = v12;
      }
      *v5 += 2;
      if ( !**v5 )
        break;
    }
  }
  if ( v7 )
  {
    v9 = **v5;
    **v5 = 0;
    _bstr_t::operator=(a1, psza);
    **v5 = v9;
  }
  if ( **v5 )
  {
    do
    {
      if ( **v5 == a3 )
        break;
      v10 = (*v5 + 2);
      *v5 = v10;
    }
    while ( *v10 );
  }
  result = a1;
  if ( **v5 == a3 )
    *v5 += 2;
  return result;
}

//----- (00FA4950) --------------------------------------------------------
_bstr_t *__stdcall sub_FA4950(int a1, int a2, void *a3)
{
  _bstr_t *v3; // ebx
  void *v4; // edi
  int v5; // esi
  char v6; // al
  int v7; // esi
  void *v8; // esi
  char v10; // [esp+Ch] [ebp-8h]
  int v11; // [esp+10h] [ebp-4h]

  v3 = a1;
  v4 = a3;
  v11 = 0;
  *a1 = 0;
  a1 = v4;
  if ( v4 )
    InterlockedIncrement(v4 + 2);
  v5 = *a2;
  v6 = *sub_1002F90(a2, &v10, &a1) != v5;
  HIBYTE(a1) = v6;
  if ( v4 )
  {
    if ( !InterlockedDecrement(v4 + 2) )
    {
      if ( *v4 )
      {
        SysFreeString(*v4);
        *v4 = 0;
      }
      if ( *(v4 + 1) )
      {
        j_j__free(*(v4 + 1));
        *(v4 + 1) = 0;
      }
      j__free(v4);
    }
    v6 = HIBYTE(a1);
  }
  if ( v6 )
  {
    a1 = a3;
    if ( a3 )
      InterlockedIncrement(a3 + 2);
    v7 = *(*sub_1002F90(a2, &v10, &a1) + 20);
    a2 = v7;
    if ( v7 )
      InterlockedIncrement((v7 + 8));
    if ( v3 != &a2 )
    {
      _bstr_t::_Free(v3);
      v3->m_Data = v7;
      if ( v7 )
        InterlockedIncrement((v7 + 8));
    }
    _bstr_t::_Free(&a2);
    _bstr_t::_Free(&a1);
  }
  v8 = a3;
  if ( a3 && !InterlockedDecrement(a3 + 2) && v8 )
  {
    if ( *v8 )
    {
      SysFreeString(*v8);
      *v8 = 0;
    }
    if ( *(v8 + 1) )
    {
      j_j__free(*(v8 + 1));
      *(v8 + 1) = 0;
    }
    j__free(v8);
  }
  return v3;
}

//----- (00FA4AA0) --------------------------------------------------------
DWORD __stdcall sub_FA4AA0(HINTERNET hRequest, int a2)
{
  DWORD v2; // ebx
  int v3; // eax
  void *v4; // esi
  const unsigned __int16 *v5; // eax
  int v6; // eax
  CHAR *v7; // eax
  CHAR *v8; // edi
  DWORD v9; // eax
  const unsigned __int16 *v10; // eax
  int v11; // eax
  void *v13; // [esp-4h] [ebp-30h]
  DWORD dwNumberOfBytesRead; // [esp+10h] [ebp-1Ch]
  _bstr_t a2a; // [esp+14h] [ebp-18h]
  void *v16; // [esp+18h] [ebp-14h]
  DWORD dwNumberOfBytesAvailable; // [esp+1Ch] [ebp-10h]
  int v18; // [esp+28h] [ebp-4h]

  v2 = 0;
  dwNumberOfBytesRead = 0;
  v16 = 0;
  v18 = 0;
  v3 = sub_FA4CA0(hRequest, L"StatusCode", 0x13u, &v16);
  v4 = v16;
  if ( v3 >= 0 )
  {
    if ( v16 )
      v5 = *v16;
    else
      v5 = 0;
    v6 = wcscmp(v5, L"200");
    if ( v6 )
      v6 = -(v6 < 0) | 1;
    if ( !v6 )
    {
      while ( 1 )
      {
        dwNumberOfBytesAvailable = 0;
        if ( !WinHttpQueryDataAvailable(hRequest, &dwNumberOfBytesAvailable) )
          break;
        v7 = operator new[](dwNumberOfBytesAvailable + 1);
        v8 = v7;
        if ( !v7 )
        {
          dwNumberOfBytesAvailable = 0;
          goto LABEL_28;
        }
        memset(v7, 0, dwNumberOfBytesAvailable + 1);
        if ( WinHttpReadData(hRequest, v8, dwNumberOfBytesAvailable, &dwNumberOfBytesRead) )
        {
          _bstr_t::_bstr_t(&a2a, v8);
          LOBYTE(v18) = 1;
          _bstr_t::operator+=(a2, &a2a);
          LOBYTE(v18) = 0;
          _bstr_t::_Free(&a2a);
        }
        else
        {
          v2 = GetLastError();
        }
        j_j__free(v8);
        if ( !dwNumberOfBytesAvailable )
          goto LABEL_28;
      }
      v9 = GetLastError();
      goto LABEL_27;
    }
  }
  if ( v16 )
    v10 = *v16;
  else
    v10 = 0;
  v11 = wcscmp(v10, L"204");
  if ( v11 )
    v11 = -(v11 < 0) | 1;
  if ( v11 )
  {
    v13 = v16;
    if ( v16 )
      InterlockedIncrement(v16 + 2);
    v9 = sub_FA4D50(v13);
LABEL_27:
    v2 = v9;
    goto LABEL_28;
  }
  v2 = 232;
LABEL_28:
  if ( v4 && !InterlockedDecrement(v4 + 2) )
  {
    if ( *v4 )
    {
      SysFreeString(*v4);
      *v4 = 0;
    }
    if ( *(v4 + 1) )
    {
      j_j__free(*(v4 + 1));
      *(v4 + 1) = 0;
    }
    j__free(v4);
  }
  return v2;
}
// 10345DC: using guessed type wchar_t a200[4];
// 10345EC: using guessed type wchar_t a204[4];
// 10345F4: using guessed type wchar_t aStatuscode[11];

//----- (00FA4CA0) --------------------------------------------------------
int __stdcall sub_FA4CA0(HINTERNET hRequest, int a2, DWORD dwInfoLevel, int a4)
{
  int v4; // esi
  int result; // eax
  OLECHAR *v6; // ebx
  signed int v7; // eax
  unsigned int v8; // esi
  DWORD dwBufferLength; // [esp+8h] [ebp-4h]

  v4 = 0;
  dwBufferLength = 0;
  if ( WinHttpQueryHeaders(hRequest, dwInfoLevel, 0, 0, &dwBufferLength, 0) || GetLastError() == 122 )
  {
    v6 = malloc(dwBufferLength);
    if ( WinHttpQueryHeaders(hRequest, dwInfoLevel, 0, v6, &dwBufferLength, 0) )
    {
      _bstr_t::operator=(a4, v6);
    }
    else
    {
      v7 = GetLastError();
      v4 = v7;
      if ( v7 > 0 )
      {
        v8 = v7 | 0x80070000;
        free(v6);
        return v8;
      }
    }
    free(v6);
    result = v4;
  }
  else
  {
    result = GetLastError();
    if ( result > 0 )
      result = result | 0x80070000;
  }
  return result;
}

//----- (00FA4D50) --------------------------------------------------------
int __stdcall sub_FA4D50(void *a1)
{
  const unsigned __int16 *v1; // eax
  int v2; // eax
  signed int v3; // edi
  const unsigned __int16 *v4; // eax
  int v5; // eax
  const unsigned __int16 *v6; // eax
  int v7; // eax

  if ( a1 )
    v1 = *a1;
  else
    v1 = 0;
  v2 = wcscmp(v1, L"200");
  if ( v2 )
    v2 = -(v2 < 0) | 1;
  if ( v2 )
  {
    if ( a1 )
      v4 = *a1;
    else
      v4 = 0;
    v5 = wcscmp(v4, L"403");
    if ( v5 )
      v5 = -(v5 < 0) | 1;
    if ( v5 )
    {
      if ( a1 )
        v6 = *a1;
      else
        v6 = 0;
      v7 = wcscmp(v6, L"204");
      if ( v7 )
        v7 = -(v7 < 0) | 1;
      v3 = 1460;
      if ( v7 )
        v3 = 31;
    }
    else
    {
      v3 = 5;
    }
  }
  else
  {
    v3 = 0;
  }
  if ( a1 && !InterlockedDecrement(a1 + 2) && a1 )
  {
    if ( *a1 )
    {
      SysFreeString(*a1);
      *a1 = 0;
    }
    if ( *(a1 + 1) )
    {
      j_j__free(*(a1 + 1));
      *(a1 + 1) = 0;
    }
    j__free(a1);
  }
  return v3;
}
// 10345DC: using guessed type wchar_t a200[4];
// 10345E4: using guessed type wchar_t a403[4];
// 10345EC: using guessed type wchar_t a204[4];

//----- (00FA4E80) --------------------------------------------------------
DWORD __thiscall HttpInfo_Open(tagHttpInfo *this, HWND hWnd, OLECHAR *psz, char a4, char a5, char a6)
{
  tagHttpInfo *v6; // esi
  void *v8; // eax
  HINTERNET v9; // eax

  v6 = this;
  this->field_18 = a6;
  if ( !AskForAgreementLicense(hWnd, psz, a4, a5, 0) )
    return -1;
  v8 = WinHttpOpen(L"VirusTotal", 0, 0, 0, 0);
  v6->m_hSession = v8;
  if ( !v8 )
    return GetLastError();
  v9 = WinHttpConnect(v8, L"www.virustotal.com", 0x1BBu, 0);
  v6->m_hConnect = v9;
  if ( !v9 )
  {
    WinHttpCloseHandle(v6->m_hSession);
    v6->m_hSession = 0;
    return GetLastError();
  }
  return 0;
}

//----- (00FA4F00) --------------------------------------------------------
DWORD __thiscall sub_FA4F00(HINTERNET *this, void *a2, void *a3, void *a4, int a5)
{
  HINTERNET *v5; // esi
  const WCHAR *v6; // eax
  void *v7; // ebx
  BSTR *v8; // esi
  UINT v9; // eax
  DWORD v10; // edi
  BSTR v11; // edx
  DWORD v12; // ecx
  const WCHAR *v13; // eax
  DWORD v14; // eax
  DWORD v15; // edi
  LONG (__stdcall *v16)(volatile LONG *); // ecx
  WINHTTP_AUTOPROXY_OPTIONS pAutoProxyOptions; // [esp+10h] [ebp-38h]
  WINHTTP_PROXY_INFO pProxyInfo; // [esp+28h] [ebp-20h]
  HINTERNET *v20; // [esp+34h] [ebp-14h]
  DWORD dwTotalLength; // [esp+38h] [ebp-10h]
  int v22; // [esp+44h] [ebp-4h]

  v5 = this;
  v20 = this;
  v22 = 2;
  if ( a2 )
    v6 = *a2;
  else
    v6 = 0;
  v7 = WinHttpOpenRequest(this[1], L"POST", v6, 0, 0, 0, 0x800000u);
  pAutoProxyOptions.dwFlags = 1;
  pAutoProxyOptions.dwAutoDetectFlags = 3;
  pAutoProxyOptions.fAutoLogonIfChallenged = 1;
  if ( WinHttpGetProxyForUrl(*v5, L"https://www.virustotal.com", &pAutoProxyOptions, &pProxyInfo) )
    WinHttpSetOption(v7, 0x26u, &pProxyInfo, 0xCu);
  v8 = a4;
  if ( !a4 )
  {
    v12 = 0;
    v10 = 0;
LABEL_21:
    v11 = 0;
    goto LABEL_22;
  }
  if ( *a4 )
  {
    v8 = a4;
    dwTotalLength = SysStringLen(*a4);
  }
  else
  {
    dwTotalLength = 0;
  }
  if ( !v8 )
  {
    v12 = dwTotalLength;
    v10 = 0;
    goto LABEL_21;
  }
  if ( *v8 )
  {
    v9 = SysStringLen(*v8);
    v8 = a4;
    v10 = v9;
  }
  else
  {
    v10 = 0;
  }
  if ( !v8 )
  {
    v12 = dwTotalLength;
    goto LABEL_21;
  }
  if ( !v8[1] )
    v8[1] = sub_1004270(*v8);
  v11 = v8[1];
  v12 = dwTotalLength;
LABEL_22:
  if ( a3 )
    v13 = *a3;
  else
    v13 = 0;
  if ( WinHttpSendRequest(v7, v13, 0, v11, v10, v12, 0) && WinHttpReceiveResponse(v7, 0) )
    v14 = sub_FA4AA0(v7, a5);
  else
    v14 = GetLastError();
  v15 = v14;
  WinHttpCloseHandle(v7);
  v16 = InterlockedDecrement;
  if ( a2 )
  {
    if ( !InterlockedDecrement(a2 + 2) && a2 )
    {
      if ( *a2 )
      {
        SysFreeString(*a2);
        *a2 = 0;
      }
      if ( *(a2 + 1) )
      {
        j_j__free(*(a2 + 1));
        *(a2 + 1) = 0;
      }
      j__free(a2);
    }
    v16 = InterlockedDecrement;
  }
  if ( a3 && !v16(a3 + 2) && a3 )
  {
    if ( *a3 )
    {
      SysFreeString(*a3);
      *a3 = 0;
    }
    if ( *(a3 + 1) )
    {
      j_j__free(*(a3 + 1));
      *(a3 + 1) = 0;
    }
    j__free(a3);
  }
  if ( a4 && !InterlockedDecrement(a4 + 2) && a4 )
  {
    if ( *a4 )
    {
      SysFreeString(*a4);
      *a4 = 0;
    }
    if ( *(a4 + 1) )
    {
      j_j__free(*(a4 + 1));
      *(a4 + 1) = 0;
    }
    j__free(a4);
  }
  return v15;
}

//----- (00FA5160) --------------------------------------------------------
std__list_node *__thiscall sub_FA5160(tagHttpInfo *this, char a2)
{
  std__list_node *v2; // edi
  std__List *v3; // esi
  std__list_node *v4; // edx
  unsigned int v5; // eax
  std__list_node *result; // eax

  v2 = this->m_List._Mypair._Myval2._Myhead;
  v3 = &this->m_List;
  v4 = std::_List_buy<tagEventItem *,std::allocator<tagEventItem *>>::_Buynode<tagEventItem * const &>(
         this->m_List._Mypair._Myval2._Myhead,
         &v2->_Prev->_Next,
         &a2);
  v5 = v3->_Mypair._Myval2._Mysize;
  if ( 357913940 - v5 < 1 )
    std::_Xlength_error("list<T> too long");
  v3->_Mypair._Myval2._Mysize = v5 + 1;
  v2->_Prev = v4;
  result = v4->_Prev;
  result->_Next = v4;
  return result;
}

//----- (00FA51B0) --------------------------------------------------------
char __thiscall LoadConfigItemFromRegistry(tagRegKeyInfo *this, tagConfigItem *pConfigItem)
{
  tagRegKeyInfo *pRegKeyInfo; // esi
  PHKEY phKey; // ebx
  LSTATUS (__stdcall *RegQueryValueExW)(HKEY, LPCWSTR, LPDWORD, LPDWORD, LPBYTE, LPDWORD); // ecx
  PUCHAR pBuffer; // edi
  tagConfigItem *pItem; // ST04_4
  HKEY v7; // ST00_4
  _BYTE *Address; // esi
  signed int dbValue; // ebx
  LSTATUS lRet; // eax
  char v11; // dl
  char v12; // cl
  BYTE *v13; // eax
  const WCHAR *Name; // ST04_4
  HKEY hKey_; // ST00_4
  LSTATUS v16; // eax
  double v17; // xmm0_8
  const WCHAR *pszName; // ST04_4
  HKEY *hKey; // [esp+8h] [ebp-14h]
  DWORD cbData; // [esp+Ch] [ebp-10h]
  FILETIME FileTime; // [esp+10h] [ebp-Ch]
  tagRegKeyInfo *pThis; // [esp+18h] [ebp-4h]

  pRegKeyInfo = this;
  pThis = this;
  phKey = &this->hKey;
  hKey = &this->hKey;
  if ( RegOpenKeyExW(HKEY_CURRENT_USER, this->szKeyName, 0, KEY_READ, &this->hKey) )
    return 0;
  if ( pConfigItem->Name )
  {
    RegQueryValueExW = ::RegQueryValueExW;
    pBuffer = &pConfigItem->dbValue;
    do
    {
      switch ( *(pBuffer - 3) )                 // pConfigItem->RegType
      {
        case KT_None:                           // REG_NONE
          cbData = *pBuffer;                    // cbData = pConfigItem->dwValue1
          pItem = *(pBuffer - 4);               // pItem=pConfigItem->Name
          FileTime.dwLowDateTime = *(pBuffer - 1);// Buffer[0]=pConfigItem->Address
          v7 = *phKey;
          pConfigItem = 4;
          if ( ::RegQueryValueExW(v7, pItem, 0, 0, FileTime.dwHighDateTime, &pConfigItem) )
            *FileTime.dwHighDateTime = cbData;
          goto __Next;
        case KT_Bool:                           // REG_SZ
          Address = *(pBuffer - 1);             // pConfigItem->Address
          dbValue = *pBuffer;
          cbData = 4;
          pConfigItem = *Address;
          // RegQueryValueExW(pThis->hKey,pConfigItem->Name,NULL,NULL,&pConfigItem->Address,&cbData);
          lRet = RegQueryValueExW(pThis->hKey, *(pBuffer - 4), 0, 0, &pConfigItem, &cbData);
          v11 = pConfigItem;
          v12 = dbValue;
          phKey = hKey;
          if ( lRet )
            v11 = v12;
          *Address = v11;
          pRegKeyInfo = pThis;
          goto __Next;
        case KT_Double:                         // REG_EXPAND_SZ
          v13 = *(pBuffer - 1);                 // pConfigItem->Address
          Name = *(pBuffer - 4);                // pConfigItem->Name
          FileTime = *pBuffer;
          hKey_ = *phKey;
          cbData = v13;
          pConfigItem = 8;
          v16 = RegQueryValueExW(hKey_, Name, 0, 0, v13, &pConfigItem);
          RegQueryValueExW = ::RegQueryValueExW;
          if ( v16 )
            *cbData = FileTime;
          break;
        case KT_Short:                          // REG_BINARY
          RegKeyInfo_LoadWord(pRegKeyInfo, *(pBuffer - 4), *(pBuffer - 1), *pBuffer);
          goto __Next;                          // REG_DWORD
        case KT_String:
          v17 = *pBuffer;                       //  pConfigItem->dwValue1
          pConfigItem = *(pBuffer - 2);         // pConfigItem->StructSize
          cbData = v17;
          pszName = *(pBuffer - 4);             // pConfigItem->Name
          FileTime.dwHighDateTime = *(pBuffer - 1);// pConfigItem->Address
          if ( ::RegQueryValueExW(*phKey, pszName, 0, 0, FileTime.dwHighDateTime, &pConfigItem) && cbData )
            wcscpy_s(FileTime.dwHighDateTime, pConfigItem, cbData);
          goto __Next;
        case KT_LongArray:                      // REG_DWORD_BIG_ENDIAN
          RegKeyInfo_LoadDwordArray(pRegKeyInfo, *(pBuffer - 4), *(pBuffer - 2) >> 2, *(pBuffer - 1));
          goto __Next;
        case KT_ShortArray:                     // REG_LINK
          RegKeyInfo_LoadShortArray(pRegKeyInfo, *(pBuffer - 4), *(pBuffer - 2) >> 1, *(pBuffer - 1));
          goto __Next;
        case KT_Structure:                      // REG_MULTI_SZ
          pConfigItem = *(pBuffer - 2);
          // RegQueryValueExW(*hKey,pConfigItem->Name, NULL, NULL, pConfigItem->Address,&pConfigItem->StructSize)
          RegQueryValueExW(*phKey, *(pBuffer - 4), 0, 0, *(pBuffer - 1), &pConfigItem);
__Next:
          RegQueryValueExW = ::RegQueryValueExW;
          break;
        default:
          break;
      }
      pBuffer += sizeof(tagConfigItem);
    }
    while ( *(pBuffer - 4) );                   // pConfigItem->Name
  }
  RegCloseKey(*phKey);
  return 1;
}
// FA538B: CONTAINING_RECORD: no field 'PUCHAR' in struct 'tagConfigItem' at 24

//----- (00FA53E0) --------------------------------------------------------
LSTATUS __thiscall RegKeyInfo_LoadDwordArray(tagRegKeyInfo *pThis, LPCWSTR lpValueName, DWORD cbSize, PVOID pMap)
{
  BYTE *pdwValue; // edi
  LSTATUS lresult; // eax
  DWORD Index; // esi
  DWORD cbData; // [esp+4h] [ebp-2Ch]
  HKEY hSubKey; // [esp+8h] [ebp-28h]
  __int16 ValueName[16]; // [esp+Ch] [ebp-24h]

  pdwValue = pMap;
  lresult = RegOpenKeyExW(pThis->hKey, lpValueName, 0, KEY_READ, &hSubKey);
  if ( !lresult )
  {
    Index = 0;
    if ( cbSize )
    {
      do
      {
        cbData = 4;
        sub_FA13E0(ValueName, L"%d", Index);
        RegQueryValueExW(hSubKey, ValueName, 0, 0, pdwValue, &cbData);
        ++Index;
        pdwValue += 4;
      }
      while ( Index < cbSize );
    }
    lresult = RegCloseKey(hSubKey);
  }
  return lresult;
}

//----- (00FA5480) --------------------------------------------------------
int __thiscall RegKeyInfo_LoadWord(tagRegKeyInfo *this, LPCWSTR lpValueName, WORD *dwValue, DWORD dwDefValue)
{
  WORD *pwValueIn; // esi
  LSTATUS v5; // eax
  signed __int16 v6; // dx
  int result; // eax
  DWORD cbData; // [esp+4h] [ebp-4h]

  pwValueIn = dwValue;
  cbData = 4;
  dwValue = *dwValue;
  v5 = RegQueryValueExW(this->hKey, lpValueName, 0, 0, &dwValue, &cbData);
  v6 = dwValue;
  if ( v5 )
    v6 = dwDefValue;
  *pwValueIn = v6;
  result = MulDiv(v6, gLogPixelSize.x, 96);
  *pwValueIn = result;
  return result;
}

//----- (00FA54E0) --------------------------------------------------------
LSTATUS __thiscall RegKeyInfo_LoadShortArray(tagRegKeyInfo *pThis, LPCWSTR lpValueName, DWORD dwCount, PVOID pArray)
{
  LSTATUS result; // eax
  DWORD v5; // esi
  __int16 v6; // ax
  DWORD cbData; // [esp+0h] [ebp-34h]
  _WORD *pwValue; // [esp+4h] [ebp-30h]
  unsigned __int16 Data[2]; // [esp+8h] [ebp-2Ch]
  HKEY hSubKey; // [esp+Ch] [ebp-28h]
  WCHAR ValueName; // [esp+10h] [ebp-24h]

  pwValue = pArray;
  result = RegOpenKeyExW(pThis->hKey, lpValueName, 0, KEY_READ, &hSubKey);
  if ( !result )
  {
    v5 = 0;
    if ( dwCount )
    {
      do
      {
        cbData = 4;
        sub_FA13E0(&ValueName, L"%d", v5);
        if ( !RegQueryValueExW(hSubKey, &ValueName, 0, 0, Data, &cbData) )
        {
          v6 = MulDiv(Data[0], gLogPixelSize.x, 96);
          pwValue[v5] = v6;
        }
        ++v5;
      }
      while ( v5 < dwCount );
    }
    result = RegCloseKey(hSubKey);
  }
  return result;
}

//----- (00FA55A0) --------------------------------------------------------
DWORD __thiscall sub_FA55A0(HINTERNET *this, int a2, OLECHAR psz)
{
  HINTERNET *v3; // ebx
  int v4; // esi
  volatile LONG *v5; // ecx
  DWORD v6; // eax
  DWORD v7; // edi
  _bstr_t *v8; // esi
  int v9; // eax
  _bstr_t *v10; // ecx
  _bstr_t *v11; // esi
  _bstr_t *v12; // eax
  _bstr_t *v13; // eax
  _bstr_t *v14; // eax
  _bstr_t *v15; // edi
  _bstr_t *v16; // esi
  Data_t_bstr_t **v17; // eax
  _bstr_t *v18; // eax
  _bstr_t *v19; // eax
  _bstr_t *v20; // esi
  _bstr_t *v21; // eax
  _bstr_t *v22; // eax
  _bstr_t *v23; // eax
  _bstr_t *v24; // edi
  _bstr_t *v25; // esi
  Data_t_bstr_t **v26; // eax
  _bstr_t *v27; // eax
  _bstr_t *v28; // eax
  _bstr_t *v29; // edi
  UINT (__stdcall *v30)(BSTR); // eax
  _bstr_t *v31; // esi
  _bstr_t *v32; // eax
  _bstr_t *v33; // eax
  _bstr_t *v34; // eax
  _bstr_t *v35; // esi
  Data_t_bstr_t **v36; // eax
  _bstr_t *v37; // eax
  _bstr_t *v38; // eax
  OLECHAR **v39; // ecx
  _bstr_t *v40; // edi
  OLECHAR *v41; // ecx
  _bstr_t *v42; // esi
  _bstr_t *v43; // eax
  _bstr_t *v44; // eax
  _bstr_t *v45; // eax
  _bstr_t *v46; // esi
  Data_t_bstr_t **v47; // eax
  _bstr_t *v48; // eax
  _bstr_t *v49; // eax
  _bstr_t *v50; // esi
  _bstr_t *v51; // eax
  _bstr_t *v52; // eax
  _bstr_t *v53; // eax
  _bstr_t *v54; // esi
  _bstr_t *v55; // eax
  _bstr_t *v56; // eax
  _bstr_t *v57; // eax
  _bstr_t *v58; // eax
  _bstr_t *v59; // eax
  _bstr_t *v60; // edi
  _bstr_t *v61; // esi
  Data_t_bstr_t **v62; // eax
  _bstr_t *v63; // eax
  _bstr_t *v64; // eax
  _bstr_t *v65; // eax
  _bstr_t *v66; // eax
  void *v67; // esi
  void *v68; // ST0C_4
  _bstr_t *v69; // edi
  _bstr_t *v70; // esi
  Data_t_bstr_t **v71; // eax
  _bstr_t *v72; // eax
  Data_t_bstr_t *v73; // edi
  Data_t_bstr_t *v74; // esi
  UINT v75; // ecx
  const WCHAR *v76; // edx
  void *v77; // edi
  int *v78; // esi
  int v79; // eax
  _bstr_t *v80; // ecx
  char *v81; // ecx
  DWORD v82; // eax
  void *v83; // edi
  char *v84; // ecx
  DWORD v85; // eax
  DWORD v86; // eax
  int *v87; // esi
  int v88; // eax
  _DWORD **v89; // esi
  void *v90; // ecx
  _bstr_t *v91; // eax
  int v92; // edi
  void *v93; // ecx
  _bstr_t *v94; // eax
  _bstr_t *v95; // eax
  void *v96; // ecx
  _bstr_t *v97; // eax
  _bstr_t *v98; // esi
  Data_t_bstr_t *v99; // eax
  volatile LONG *v101; // [esp-Ch] [ebp-A0h]
  void *v102; // [esp-4h] [ebp-98h]
  WINHTTP_AUTOPROXY_OPTIONS pAutoProxyOptions; // [esp+10h] [ebp-84h]
  WINHTTP_PROXY_INFO pProxyInfo; // [esp+28h] [ebp-6Ch]
  void *v105; // [esp+34h] [ebp-60h]
  int v106; // [esp+38h] [ebp-5Ch]
  _bstr_t v107; // [esp+3Ch] [ebp-58h]
  _bstr_t v108; // [esp+40h] [ebp-54h]
  _bstr_t v109; // [esp+44h] [ebp-50h]
  _bstr_t v110; // [esp+48h] [ebp-4Ch]
  _bstr_t v111; // [esp+4Ch] [ebp-48h]
  _bstr_t v112; // [esp+50h] [ebp-44h]
  _bstr_t a1; // [esp+54h] [ebp-40h]
  _bstr_t v114; // [esp+58h] [ebp-3Ch]
  DWORD dwNumberOfBytesWritten; // [esp+5Ch] [ebp-38h]
  DWORD dwMessageId; // [esp+60h] [ebp-34h]
  _bstr_t a2a; // [esp+64h] [ebp-30h]
  _bstr_t v118; // [esp+68h] [ebp-2Ch]
  int v119; // [esp+6Ch] [ebp-28h]
  LPCVOID lpBuffer; // [esp+70h] [ebp-24h]
  HINTERNET hRequest; // [esp+74h] [ebp-20h]
  int v122; // [esp+78h] [ebp-1Ch]
  DWORD dwNumberOfBytesToWrite; // [esp+7Ch] [ebp-18h]
  int v124; // [esp+80h] [ebp-14h]
  _bstr_t v125; // [esp+84h] [ebp-10h]
  int v126; // [esp+90h] [ebp-4h]

  v3 = this;
  v106 = 0;
  v105 = std::_Tree_comp_alloc<std::_Tmap_traits<unsigned long,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *>>,0>>::_Buyheadnode();
  v126 = 0;
  _bstr_t::operator=(psz, &gszNullString);
  v4 = a2;
  v102 = &dwMessageId;
  v111.m_Data = (a2 + 12);
  v5 = *(a2 + 12);
  v101 = v5;
  if ( v5 )
    InterlockedIncrement(v5 + 2);
  v6 = sub_FA4420(v101, &lpBuffer, v102);
  v7 = v6;
  if ( v6 )
  {
    sub_FA4320(&v124, v6);
    v8 = (v4 + 24);
    if ( v8 != &v124 )
    {
      _bstr_t::_Free(v8);
      v9 = v124;
      v8->m_Data = v124;
      if ( v9 )
        InterlockedIncrement((v9 + 8));
    }
    v10 = &v124;
  }
  else
  {
    v125.m_Data = 0;
    LOBYTE(v126) = 1;
    v11 = _bstr_t::_bstr_t(&a1, L"\r\n");
    LOBYTE(v126) = 2;
    v12 = _bstr_t::_bstr_t(&dwNumberOfBytesToWrite, L"---------------------------41184676334");
    LOBYTE(v126) = 3;
    v13 = _bstr_t::operator+(&hRequest, L"--", v12);
    LOBYTE(v126) = 4;
    v14 = _bstr_t::operator+(&v13->m_Data, &a2a, v11);
    LOBYTE(v126) = 5;
    _bstr_t::operator+=(&v125, v14);
    _bstr_t::_Free(&a2a);
    _bstr_t::_Free(&hRequest);
    _bstr_t::_Free(&dwNumberOfBytesToWrite);
    LOBYTE(v126) = 1;
    _bstr_t::_Free(&a1);
    _bstr_t::_bstr_t(&a2a, L"Content-Disposition: form-data; name=\"apikey\"\r\n");
    LOBYTE(v126) = 6;
    _bstr_t::operator+=(&v125, &a2a);
    LOBYTE(v126) = 1;
    _bstr_t::_Free(&a2a);
    v15 = _bstr_t::_bstr_t(&v112, L"\r\n");
    LOBYTE(v126) = 7;
    v16 = _bstr_t::_bstr_t(&dwNumberOfBytesToWrite, "4e3202fdbe953d628f650229af5b3eb49cd46b2d3bfe5546ae3c5fa48b554e0c");
    LOBYTE(v126) = 8;
    v17 = _bstr_t::_bstr_t(&hRequest, L"\r\n");
    LOBYTE(v126) = 9;
    v18 = _bstr_t::operator+(v17, &a2a, v16);
    LOBYTE(v126) = 10;
    v19 = _bstr_t::operator+(&v18->m_Data, &a1, v15);
    LOBYTE(v126) = 11;
    _bstr_t::operator+=(&v125, v19);
    _bstr_t::_Free(&a1);
    _bstr_t::_Free(&a2a);
    _bstr_t::_Free(&hRequest);
    _bstr_t::_Free(&dwNumberOfBytesToWrite);
    LOBYTE(v126) = 1;
    _bstr_t::_Free(&v112);
    v20 = _bstr_t::_bstr_t(&hRequest, L"\r\n");
    LOBYTE(v126) = 12;
    v21 = _bstr_t::_bstr_t(&a2a, L"---------------------------41184676334");
    LOBYTE(v126) = 13;
    v22 = _bstr_t::operator+(&a1, L"--", v21);
    LOBYTE(v126) = 14;
    v23 = _bstr_t::operator+(&v22->m_Data, &v112, v20);
    LOBYTE(v126) = 15;
    _bstr_t::operator+=(&v125, v23);
    _bstr_t::_Free(&v112);
    _bstr_t::_Free(&a1);
    _bstr_t::_Free(&a2a);
    LOBYTE(v126) = 1;
    _bstr_t::_Free(&hRequest);
    _bstr_t::_bstr_t(&a2a, L"Content-Disposition: form-data; name=\"creation_datetime\"\r\n");
    LOBYTE(v126) = 16;
    _bstr_t::operator+=(&v125, &a2a);
    LOBYTE(v126) = 1;
    _bstr_t::_Free(&a2a);
    v24 = _bstr_t::_bstr_t(&dwNumberOfBytesToWrite, L"\r\n");
    LOBYTE(v126) = 17;
    v25 = sub_FA18A0(&hRequest, (a2 + 16));
    LOBYTE(v126) = 18;
    v26 = _bstr_t::_bstr_t(&a2a, L"\r\n");
    LOBYTE(v126) = 19;
    v27 = _bstr_t::operator+(v26, &a1, v25);
    LOBYTE(v126) = 20;
    v28 = _bstr_t::operator+(&v27->m_Data, &v112, v24);
    LOBYTE(v126) = 21;
    _bstr_t::operator+=(&v125, v28);
    _bstr_t::_Free(&v112);
    _bstr_t::_Free(&a1);
    _bstr_t::_Free(&a2a);
    _bstr_t::_Free(&hRequest);
    LOBYTE(v126) = 1;
    _bstr_t::_Free(&dwNumberOfBytesToWrite);
    v29 = a2;
    v30 = SysStringLen;
    if ( *a2 && **a2 )
    {
      if ( SysStringLen(**a2) )
      {
        v31 = _bstr_t::_bstr_t(&hRequest, L"\r\n");
        LOBYTE(v126) = 22;
        v32 = _bstr_t::_bstr_t(&a2a, L"---------------------------41184676334");
        LOBYTE(v126) = 23;
        v33 = _bstr_t::operator+(&a1, L"--", v32);
        LOBYTE(v126) = 24;
        v34 = _bstr_t::operator+(&v33->m_Data, &v112, v31);
        LOBYTE(v126) = 25;
        _bstr_t::operator+=(&v125, v34);
        _bstr_t::_Free(&v112);
        _bstr_t::_Free(&a1);
        _bstr_t::_Free(&a2a);
        LOBYTE(v126) = 1;
        _bstr_t::_Free(&hRequest);
        _bstr_t::_bstr_t(&a2a, L"Content-Disposition: form-data; name=\"autostart_location\"\r\n");
        LOBYTE(v126) = 26;
        _bstr_t::operator+=(&v125, &a2a);
        LOBYTE(v126) = 1;
        _bstr_t::_Free(&a2a);
        v35 = _bstr_t::_bstr_t(&hRequest, L"\r\n");
        LOBYTE(v126) = 27;
        v36 = _bstr_t::_bstr_t(&a2a, L"\r\n");
        LOBYTE(v126) = 28;
        v37 = _bstr_t::operator+(v36, &a1, v29);
        LOBYTE(v126) = 29;
        v38 = _bstr_t::operator+(&v37->m_Data, &v112, v35);
        LOBYTE(v126) = 30;
        _bstr_t::operator+=(&v125, v38);
        _bstr_t::_Free(&v112);
        _bstr_t::_Free(&a1);
        _bstr_t::_Free(&a2a);
        LOBYTE(v126) = 1;
        _bstr_t::_Free(&hRequest);
      }
      v30 = SysStringLen;
    }
    v39 = &v29[1].m_Data->m_wstr;
    v40 = v29 + 1;
    if ( v39 )
    {
      v41 = *v39;
      if ( v41 )
      {
        if ( v30(v41) )
        {
          v42 = _bstr_t::_bstr_t(&hRequest, L"\r\n");
          LOBYTE(v126) = 31;
          v43 = _bstr_t::_bstr_t(&a2a, L"---------------------------41184676334");
          LOBYTE(v126) = 32;
          v44 = _bstr_t::operator+(&a1, L"--", v43);
          LOBYTE(v126) = 33;
          v45 = _bstr_t::operator+(&v44->m_Data, &v112, v42);
          LOBYTE(v126) = 34;
          _bstr_t::operator+=(&v125, v45);
          _bstr_t::_Free(&v112);
          _bstr_t::_Free(&a1);
          _bstr_t::_Free(&a2a);
          LOBYTE(v126) = 1;
          _bstr_t::_Free(&hRequest);
          _bstr_t::_bstr_t(&a2a, L"Content-Disposition: form-data; name=\"autostart_entry\"\r\n");
          LOBYTE(v126) = 35;
          _bstr_t::operator+=(&v125, &a2a);
          LOBYTE(v126) = 1;
          _bstr_t::_Free(&a2a);
          v46 = _bstr_t::_bstr_t(&hRequest, L"\r\n");
          LOBYTE(v126) = 36;
          v47 = _bstr_t::_bstr_t(&a2a, L"\r\n");
          LOBYTE(v126) = 37;
          v48 = _bstr_t::operator+(v47, &a1, v40);
          LOBYTE(v126) = 38;
          v49 = _bstr_t::operator+(&v48->m_Data, &v112, v46);
          LOBYTE(v126) = 39;
          _bstr_t::operator+=(&v125, v49);
          _bstr_t::_Free(&v112);
          _bstr_t::_Free(&a1);
          _bstr_t::_Free(&a2a);
          LOBYTE(v126) = 1;
          _bstr_t::_Free(&hRequest);
        }
      }
    }
    v50 = _bstr_t::_bstr_t(&hRequest, L"\r\n");
    LOBYTE(v126) = 40;
    v51 = _bstr_t::_bstr_t(&a2a, L"---------------------------41184676334");
    LOBYTE(v126) = 41;
    v52 = _bstr_t::operator+(&a1, L"--", v51);
    LOBYTE(v126) = 42;
    v53 = _bstr_t::operator+(&v52->m_Data, &v112, v50);
    LOBYTE(v126) = 43;
    _bstr_t::operator+=(&v125, v53);
    _bstr_t::_Free(&v112);
    _bstr_t::_Free(&a1);
    _bstr_t::_Free(&a2a);
    LOBYTE(v126) = 1;
    _bstr_t::_Free(&hRequest);
    _bstr_t::_bstr_t(&a2a, L"\"");
    LOBYTE(v126) = 44;
    v54 = _bstr_t::_bstr_t(&dwNumberOfBytesToWrite, L"\r\n");
    LOBYTE(v126) = 45;
    v55 = _bstr_t::operator+(&hRequest, L"Content-Disposition: form-data; name=\"file\"; filename=\"", v111.m_Data);
    LOBYTE(v126) = 46;
    v56 = _bstr_t::operator+(&v55->m_Data, &a1, &a2a);
    LOBYTE(v126) = 47;
    v57 = _bstr_t::operator+(&v56->m_Data, &v112, v54);
    LOBYTE(v126) = 48;
    _bstr_t::operator+=(&v125, v57);
    _bstr_t::_Free(&v112);
    _bstr_t::_Free(&a1);
    _bstr_t::_Free(&hRequest);
    _bstr_t::_Free(&dwNumberOfBytesToWrite);
    LOBYTE(v126) = 1;
    _bstr_t::_Free(&a2a);
    v58 = _bstr_t::_bstr_t(&v112, L"\r\n");
    LOBYTE(v126) = 49;
    v59 = _bstr_t::operator+(&v111, L"Content-Type: application/octet-stream\r\n", v58);
    LOBYTE(v126) = 50;
    _bstr_t::operator+=(&v125, v59);
    _bstr_t::_Free(&v111);
    _bstr_t::_Free(&v112);
    a2a.m_Data = 0;
    LOBYTE(v126) = 51;
    _bstr_t::_bstr_t(&dwNumberOfBytesToWrite, L"--");
    LOBYTE(v126) = 52;
    _bstr_t::_bstr_t(&hRequest, L"--");
    LOBYTE(v126) = 53;
    v60 = _bstr_t::_bstr_t(&v107, L"\r\n");
    LOBYTE(v126) = 54;
    v61 = _bstr_t::_bstr_t(&v108, L"---------------------------41184676334");
    LOBYTE(v126) = 55;
    v62 = _bstr_t::_bstr_t(&v109, L"\r\n");
    LOBYTE(v126) = 56;
    v63 = _bstr_t::operator+(v62, &v110, &hRequest);
    LOBYTE(v126) = 57;
    v64 = _bstr_t::operator+(&v63->m_Data, &a1, v61);
    LOBYTE(v126) = 58;
    v65 = _bstr_t::operator+(&v64->m_Data, &v112, &dwNumberOfBytesToWrite);
    LOBYTE(v126) = 59;
    v66 = _bstr_t::operator+(&v65->m_Data, &v111, v60);
    LOBYTE(v126) = 60;
    _bstr_t::operator+=(&a2a, v66);
    _bstr_t::_Free(&v111);
    _bstr_t::_Free(&v112);
    _bstr_t::_Free(&a1);
    _bstr_t::_Free(&v110);
    _bstr_t::_Free(&v109);
    _bstr_t::_Free(&v108);
    _bstr_t::_Free(&v107);
    _bstr_t::_Free(&hRequest);
    LOBYTE(v126) = 51;
    _bstr_t::_Free(&dwNumberOfBytesToWrite);
    v102 = 0x800000;
    v67 = WinHttpOpenRequest(v3[1], L"POST", L"vtapi/v2/file/scan", 0, 0, 0, 0x800000u);
    pAutoProxyOptions.dwFlags = 1;
    hRequest = v67;
    v102 = &pProxyInfo;
    pAutoProxyOptions.dwAutoDetectFlags = 3;
    v68 = *v3;
    pAutoProxyOptions.fAutoLogonIfChallenged = 1;
    if ( WinHttpGetProxyForUrl(v68, L"https://www.virustotal.com", &pAutoProxyOptions, &pProxyInfo) )
      WinHttpSetOption(v67, 0x26u, &pProxyInfo, 0xCu);
    v69 = _bstr_t::_bstr_t(&v110, L"\r\n");
    LOBYTE(v126) = 61;
    v70 = _bstr_t::_bstr_t(&v109, L"---------------------------41184676334");
    LOBYTE(v126) = 62;
    v71 = _bstr_t::_bstr_t(&v108, L"Content-Type: multipart/form-data; boundary=");
    LOBYTE(v126) = 63;
    v72 = _bstr_t::operator+(v71, &v107, v70);
    LOBYTE(v126) = 64;
    _bstr_t::operator+(&v72->m_Data, &v114, v69);
    _bstr_t::_Free(&v107);
    _bstr_t::_Free(&v108);
    _bstr_t::_Free(&v109);
    LOBYTE(v126) = 69;
    _bstr_t::_Free(&v110);
    v73 = v125.m_Data;
    if ( v125.m_Data && v125.m_Data->m_wstr )
      dwNumberOfBytesToWrite = SysStringLen(v125.m_Data->m_wstr);
    else
      dwNumberOfBytesToWrite = 0;
    v74 = a2a.m_Data;
    if ( a2a.m_Data && a2a.m_Data->m_wstr )
      v75 = SysStringLen(a2a.m_Data->m_wstr);
    else
      v75 = 0;
    if ( v114.m_Data )
      v76 = v114.m_Data->m_wstr;
    else
      v76 = 0;
    if ( WinHttpSendRequest(hRequest, v76, 0, 0, 0, dwMessageId + v75 + dwNumberOfBytesToWrite, 0) )
    {
      if ( v73 )
      {
        if ( v73->m_wstr )
          dwNumberOfBytesToWrite = SysStringLen(v73->m_wstr);
        else
          dwNumberOfBytesToWrite = 0;
        if ( !v73->m_str )
          v73->m_str = sub_1004270(v73->m_wstr);
        v81 = v73->m_str;
        v82 = dwNumberOfBytesToWrite;
      }
      else
      {
        v82 = 0;
        v81 = 0;
      }
      v83 = hRequest;
      WinHttpWriteData(hRequest, v81, v82, &dwNumberOfBytesWritten);
      WinHttpWriteData(v83, lpBuffer, dwMessageId, &dwNumberOfBytesWritten);
      if ( v74 )
      {
        if ( v74->m_wstr )
          dwMessageId = SysStringLen(v74->m_wstr);
        else
          dwMessageId = 0;
        if ( !v74->m_str )
          v74->m_str = sub_1004270(v74->m_wstr);
        v84 = v74->m_str;
        v85 = dwMessageId;
      }
      else
      {
        v85 = 0;
        v84 = 0;
      }
      WinHttpWriteData(v83, v84, v85, &dwNumberOfBytesWritten);
      free(lpBuffer);
      if ( WinHttpReceiveResponse(v83, 0) )
      {
        v89 = psz;
        dwMessageId = sub_FA4AA0(v83, psz);
        WinHttpCloseHandle(v83);
        v7 = dwMessageId;
        if ( dwMessageId )
        {
          sub_FA4320(&v118, dwMessageId);
          v98 = (a2 + 24);
          if ( (a2 + 24) != &v118 )
          {
            _bstr_t::_Free((a2 + 24));
            v99 = v118.m_Data;
            v98->m_Data = v118.m_Data;
            if ( v99 )
              InterlockedIncrement(&v99->m_RefCount);
          }
          v80 = &v118;
        }
        else
        {
          if ( *v89 )
            *&psz = **v89;
          else
            *&psz = 0;
          sub_FA4530(v3, &lpBuffer, &psz, &v105);
          LOBYTE(v126) = 70;
          if ( lpBuffer && *lpBuffer && SysStringLen(*lpBuffer) )
          {
            v102 = v90;
            _bstr_t::_bstr_t(&v102, L"permalink");
            v91 = sub_FA4950(&psz, &v105, v102);
            v92 = a2;
            sub_F73A50((a2 + 28), v91);
            _bstr_t::_Free(&psz);
            if ( sub_F80440((v92 + 28)) )
            {
              _bstr_t::operator=((v92 + 32), L"Submitted");
            }
            else
            {
              v102 = v93;
              _bstr_t::_bstr_t(&v102, L"verbose_msg");
              v94 = sub_FA4950(&v107, &v105, v102);
              LOBYTE(v126) = 71;
              v95 = _bstr_t::operator+(&psz, L"Submission error: ", v94);
              sub_F73A50((v92 + 24), v95);
              _bstr_t::_Free(&psz);
              LOBYTE(v126) = 70;
              _bstr_t::_Free(&v107);
            }
            v102 = v96;
            _bstr_t::_bstr_t(&v102, L"scan_id");
            v97 = sub_FA4950(&psz, &v105, v102);
            sub_F73A50((v92 + 8), v97);
            _bstr_t::_Free(&psz);
            sub_F99380(v3 + 4, &a2);
            v7 = dwMessageId;
          }
          v80 = &lpBuffer;
        }
      }
      else
      {
        v86 = GetLastError();
        sub_FA4320(&v119, v86);
        v87 = (a2 + 24);
        if ( (a2 + 24) != &v119 )
        {
          _bstr_t::_Free((a2 + 24));
          v88 = v119;
          *v87 = v119;
          if ( v88 )
            InterlockedIncrement((v88 + 8));
        }
        WinHttpCloseHandle(v83);
        v7 = GetLastError();
        v80 = &v119;
      }
    }
    else
    {
      v77 = lpBuffer;
      free(lpBuffer);
      sub_FA4320(&v122, 0);
      v78 = (a2 + 24);
      if ( (a2 + 24) != &v122 )
      {
        _bstr_t::_Free((a2 + 24));
        v79 = v122;
        *v78 = v122;
        if ( v79 )
          InterlockedIncrement((v79 + 8));
      }
      WinHttpCloseHandle(hRequest);
      free(v77);
      v7 = GetLastError();
      v80 = &v122;
    }
    _bstr_t::_Free(v80);
    _bstr_t::_Free(&v114);
    _bstr_t::_Free(&a2a);
    v10 = &v125;
  }
  _bstr_t::_Free(v10);
  v102 = v105;
  v126 = -1;
  sub_FA6540(&v105, &a2, *v105, v105);
  j__free(v105);
  return v7;
}

//----- (00FA6210) --------------------------------------------------------
LSTATUS __thiscall SaveConfigItemToRegistry(tagRegKeyInfo *pThis, tagConfigItem *pConfigItem)
{
  tagRegKeyInfo *this; // esi
  HKEY *phKey; // ebx
  LSTATUS result; // eax
  void (__stdcall *RegSetValueExW)(HKEY, LPCWSTR, DWORD, DWORD, const BYTE *, DWORD); // edx
  PUCHAR pAddrBuf; // edi
  const WCHAR *v7; // esi
  tagConfigItem **v8; // ecx
  __int16 v9; // ax
  tagConfigItem **v10; // [esp-Ch] [ebp-28h]
  DWORD v11; // [esp-8h] [ebp-24h]
  __int64 v12; // [esp+8h] [ebp-14h]
  tagRegKeyInfo *pRegKeyInfo; // [esp+10h] [ebp-Ch]
  BYTE Data[4]; // [esp+14h] [ebp-8h]
  int v15; // [esp+18h] [ebp-4h]

  this = pThis;
  pRegKeyInfo = pThis;
  phKey = &pThis->hKey;
  result = RegCreateKeyExW(HKEY_CURRENT_USER, pThis->szKeyName, 0, 0, 0, KEY_WRITE, 0, &pThis->hKey, 0);
  if ( !result )
  {
    if ( pConfigItem->Name )
    {
      RegSetValueExW = ::RegSetValueExW;
      pAddrBuf = &pConfigItem->Address;
      do
      {
        switch ( *(pAddrBuf - 2) )
        {
          case KT_None:
            pConfigItem = **pAddrBuf;
            RegSetValueExW(*phKey, *(pAddrBuf - 3), 0, REG_DWORD, &pConfigItem, 4u);
            goto __Next;
          case KT_Bool:
            v15 = **pAddrBuf;
            RegSetValueExW(*phKey, *(pAddrBuf - 3), 0, REG_DWORD, &v15, 4u);
            goto __Next;
          case KT_Double:
            v11 = 8;
            v12 = **pAddrBuf;
            v10 = &v12;
            goto __WriteKey;
          case KT_Short:
            v7 = *(pAddrBuf - 3);
            *Data = MulDiv(**pAddrBuf, 96, gLogPixelSize.x);
            ::RegSetValueExW(*phKey, v7, 0, REG_DWORD, Data, 4u);
            this = pRegKeyInfo;
            goto __Next;
          case KT_String:
            v8 = *pAddrBuf;
            v15 = *pAddrBuf + 2;
            do
            {
              v9 = *v8;
              v8 = (v8 + 2);
            }
            while ( v9 );
            RegSetValueExW(*phKey, *(pAddrBuf - 3), 0, REG_SZ, *pAddrBuf, 2 * ((v8 - v15) >> 1) + 2);
            goto __Next;
          case KT_LongArray:
            RegKeyInfo_SaveLongArray(this, *(pAddrBuf - 3), *(pAddrBuf - 1) >> 2, *pAddrBuf);
            goto __Next;
          case KT_ShortArray:
            RegKeyInfo_SaveShortArray(this, *(pAddrBuf - 3), *(pAddrBuf - 1) >> 1, *pAddrBuf);
            goto __Next;
          case KT_Structure:
            v11 = *(pAddrBuf - 1);
            v10 = *pAddrBuf;
__WriteKey:
            RegSetValueExW(*phKey, *(pAddrBuf - 3), 0, REG_BINARY, v10, v11);
__Next:
            RegSetValueExW = ::RegSetValueExW;
            break;
          default:
            break;
        }
        pAddrBuf += sizeof(tagConfigItem);
      }
      while ( *(pAddrBuf - 3) );
    }
    result = RegCloseKey(*phKey);
  }
  return result;
}
// FA634D: CONTAINING_RECORD: no field 'PUCHAR' in struct 'tagConfigItem' at 24

//----- (00FA6390) --------------------------------------------------------
LSTATUS __thiscall RegKeyInfo_SaveLongArray(HKEY *this, LPCWSTR lpSubKey, int a3, BYTE *lpData)
{
  BYTE *v4; // edi
  LSTATUS result; // eax
  unsigned int v6; // esi
  HKEY phkResult; // [esp+4h] [ebp-28h]
  WCHAR ValueName; // [esp+8h] [ebp-24h]

  v4 = lpData;
  result = RegCreateKeyExW(this[1], lpSubKey, 0, 0, 0, 0x20006u, 0, &phkResult, 0);
  if ( !result )
  {
    v6 = 0;
    if ( a3 )
    {
      do
      {
        sub_FA13E0(&ValueName, L"%d", v6);
        if ( *v4 )
          RegSetValueExW(phkResult, &ValueName, 0, REG_DWORD, v4, 4u);
        else
          RegDeleteValueW(phkResult, &ValueName);
        ++v6;
        v4 += 4;
      }
      while ( v6 < a3 );
    }
    result = RegCloseKey(phkResult);
  }
  return result;
}

//----- (00FA6430) --------------------------------------------------------
LSTATUS __thiscall RegKeyInfo_SaveShortArray(tagRegKeyInfo *pThis, LPCWSTR lpValueName, DWORD dwCount, PVOID pData)
{
  LSTATUS result; // eax
  DWORD v5; // esi
  int Data; // [esp+0h] [ebp-30h]
  _WORD *v7; // [esp+4h] [ebp-2Ch]
  HKEY phkResult; // [esp+8h] [ebp-28h]
  WCHAR ValueName; // [esp+Ch] [ebp-24h]

  v7 = pData;
  result = RegCreateKeyExW(pThis->hKey, lpValueName, 0, 0, 0, 0x20006u, 0, &phkResult, 0);
  if ( !result )
  {
    v5 = 0;
    if ( dwCount )
    {
      do
      {
        sub_FA13E0(&ValueName, L"%d", v5);
        Data = MulDiv(v7[v5], 96, gLogPixelSize.x);
        if ( v7[v5] )
          RegSetValueExW(phkResult, &ValueName, 0, 4u, &Data, 4u);
        else
          RegDeleteValueW(phkResult, &ValueName);
        ++v5;
      }
      while ( v5 < dwCount );
    }
    result = RegCloseKey(phkResult);
  }
  return result;
}

//----- (00FA6500) --------------------------------------------------------
void __stdcall sub_FA6500(void *a1)
{
  _bstr_t **v1; // edi
  _bstr_t *v2; // esi

  v1 = a1;
  v2 = a1;
  if ( !*(a1 + 13) )
  {
    do
    {
      sub_FA6500(v2[2].m_Data);
      v2 = v2->m_Data;
      sub_FA1430(v1 + 4);
      j__free(v1);
      v1 = v2;
    }
    while ( !BYTE1(v2[3].m_Data) );
  }
}

//----- (00FA6540) --------------------------------------------------------
CSystemProcessInfoMapNode **__thiscall sub_FA6540(CSystemProcessInfoMap *this, CSystemProcessInfoMapNode **a2, CSystemProcessInfoMapNode *a3, CSystemProcessInfoMapNode *a4)
{
  CSystemProcessInfoMapNode *v4; // eax
  CSystemProcessInfoMap *v5; // esi
  CSystemProcessInfoMapNode *v6; // ecx
  CSystemProcessInfoMapNode **v7; // eax
  CSystemProcessInfoMapNode *v8; // ecx
  CSystemProcessInfoMapNode **result; // eax
  CSystemProcessInfoMapNode *v10; // ecx
  CSystemProcessInfoMapNode *i; // edx
  CSystemProcessInfoMapNode *v12; // eax
  char v13; // [esp+4h] [ebp-4h]

  v4 = a3;
  v5 = this;
  v6 = this->_Header;
  if ( a3 != v6->baseclass._Left || a4 != v6 )
  {
    for ( ; a3 != a4; v4 = a3 )
    {
      v10 = v4;
      if ( !v4->baseclass._isnil )
      {
        i = v4->baseclass._Right;
        if ( i->baseclass._isnil )
        {
          for ( i = v4->baseclass._Parent; !i->baseclass._isnil; i = i->baseclass._Parent )
          {
            if ( v4 != i->baseclass._Right )
              break;
            v4 = i;
          }
        }
        else
        {
          v12 = i->baseclass._Left;
          if ( !i->baseclass._Left->baseclass._isnil )
          {
            do
            {
              i = v12;
              v12 = v12->baseclass._Left;
            }
            while ( !v12->baseclass._isnil );
          }
        }
        a3 = i;
      }
      sub_FA6600(v5, &v13, v10);
    }
    *a2 = v4;
    result = a2;
  }
  else
  {
    sub_FA6500(v6->baseclass._Parent);
    v5->_Header->_Parent = v5->_Header;
    v5->_Header->_Left = v5->_Header;
    v5->_Header->_Right = v5->_Header;
    v7 = v5->_Header;
    v5->_Size = 0;
    v8 = *v7;
    result = a2;
    *a2 = v8;
  }
  return result;
}

//----- (00FA6600) --------------------------------------------------------
CSystemProcessInfoMapNode **__thiscall sub_FA6600(CSystemProcessInfoMap *this, CSystemProcessInfoMapNode **a2, CSystemProcessInfoMapNode *a3)
{
  std__tree *v3; // ebx
  CSystemProcessInfoMapNode *v4; // ecx
  CSystemProcessInfoMapNode *v5; // edi
  CSystemProcessInfoMapNode *v6; // edx
  std__Tree_node *v7; // esi
  std__Tree_node *v8; // eax
  std__Tree_node *v9; // edx
  CSystemProcessInfoMapNode *v10; // eax
  CSystemProcessInfoMapNode *v11; // eax
  CSystemProcessInfoMapNode *i; // edx
  CSystemProcessInfoMapNode *v13; // eax
  char v14; // cl
  std__Tree_node *v15; // ecx
  unsigned int v16; // eax
  CSystemProcessInfoMapNode *v17; // ecx
  CSystemProcessInfoMapNode **result; // eax
  CSystemProcessInfoMapNode *v19; // [esp+10h] [ebp-4h]

  v3 = this;
  v19 = a3;
  sub_F94CE0(&a3);
  v4 = v19;
  if ( v19->baseclass._Left->baseclass._isnil )
  {
    v5 = v19->baseclass._Right;
  }
  else if ( v19->baseclass._Right->baseclass._isnil )
  {
    v5 = v19->baseclass._Left;
  }
  else
  {
    v6 = a3;
    v5 = a3->baseclass._Right;
    if ( a3 != v19 )
    {
      v19->baseclass._Left->baseclass._Parent = a3;
      v6->baseclass._Left = v19->baseclass._Left;
      if ( v6 == v19->baseclass._Right )
      {
        v7 = v6;
      }
      else
      {
        v7 = v6->baseclass._Parent;
        if ( !v5->baseclass._isnil )
          v5->baseclass._Parent = v7;
        v7->_Left = v5;
        v6->baseclass._Right = v19->baseclass._Right;
        v19->baseclass._Right->baseclass._Parent = v6;
      }
      if ( v3->_Mypair._Myval2._Myhead->_Parent == v19 )
      {
        v3->_Mypair._Myval2._Myhead->_Parent = v6;
      }
      else
      {
        v13 = v19->baseclass._Parent;
        if ( v13->baseclass._Left == v19 )
          v13->baseclass._Left = v6;
        else
          v13->baseclass._Right = v6;
      }
      v6->baseclass._Parent = v19->baseclass._Parent;
      v14 = v6->baseclass._Color;
      v6->baseclass._Color = v19->baseclass._Color;
      v19->baseclass._Color = v14;
      v4 = v19;
      goto LABEL_37;
    }
  }
  v7 = v19->baseclass._Parent;
  if ( !v5->baseclass._isnil )
    v5->baseclass._Parent = v7;
  if ( v3->_Mypair._Myval2._Myhead->_Parent == v19 )
  {
    v3->_Mypair._Myval2._Myhead->_Parent = v5;
  }
  else if ( v7->_Left == v19 )
  {
    v7->_Left = v5;
  }
  else
  {
    v7->_Right = v5;
  }
  v8 = v3->_Mypair._Myval2._Myhead;
  if ( v3->_Mypair._Myval2._Myhead->_Left == v19 )
  {
    if ( v5->baseclass._isnil )
    {
      v9 = v7;
    }
    else
    {
      v10 = v5->baseclass._Left;
      v9 = v5;
      if ( !v5->baseclass._Left->baseclass._isnil )
      {
        do
        {
          v9 = v10;
          v10 = v10->baseclass._Left;
        }
        while ( !v10->baseclass._isnil );
      }
      v8 = v3->_Mypair._Myval2._Myhead;
    }
    v8->_Left = v9;
  }
  if ( v3->_Mypair._Myval2._Myhead->_Right == v19 )
  {
    if ( v5->baseclass._isnil )
    {
      v3->_Mypair._Myval2._Myhead->_Right = v7;
    }
    else
    {
      v11 = v5->baseclass._Right;
      for ( i = v5; !v11->baseclass._isnil; v11 = v11->baseclass._Right )
        i = v11;
      v3->_Mypair._Myval2._Myhead->_Right = i;
    }
  }
LABEL_37:
  if ( v4->baseclass._Color != 1 )
    goto LABEL_62;
  if ( v5 == v3->_Mypair._Myval2._Myhead->_Parent )
    goto LABEL_61;
  while ( v5->baseclass._Color == 1 )
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
  v4 = v19;
LABEL_61:
  v5->baseclass._Color = 1;
LABEL_62:
  sub_FA1430(&v4->_Keyvalue);
  j__free(v19);
  v16 = v3->_Mypair._Myval2._Mysize;
  v17 = a3;
  if ( v16 )
    v3->_Mypair._Myval2._Mysize = v16 - 1;
  result = a2;
  *a2 = v17;
  return result;
}

//----- (00FA6870) --------------------------------------------------------
unsigned int __cdecl sub_FA6870(int a1, const unsigned __int16 *a2)
{
  const unsigned __int16 *v2; // ecx
  unsigned int result; // eax
  unsigned __int16 v4; // dx

  v2 = a2;
  result = wcslen(a2) + 1;
  do
  {
    v4 = *v2;
    ++v2;
    *(v2 + a1 - a2 - 2) = v4;
  }
  while ( v4 );
  return result;
}

//----- (00FA68C0) --------------------------------------------------------
HBRUSH __stdcall DlgLicenseInfo(HWND hDlg, UINT a2, WPARAM a3, LPARAM a4)
{
  HWND v5; // eax
  _BYTE *v6; // ebx
  HWND v7; // eax
  HWND v8; // eax
  LPARAM lParam; // [esp+8h] [ebp-220h]
  int v10; // [esp+Ch] [ebp-21Ch]
  int (__stdcall *v11)(int, void *, int, int); // [esp+10h] [ebp-218h]
  _BYTE *v12; // [esp+14h] [ebp-214h]
  HWND v13; // [esp+18h] [ebp-210h]
  WCHAR String; // [esp+1Ch] [ebp-20Ch]

  v13 = hDlg;
  if ( a2 == 272 )
  {
    v6 = sub_FA6A40();
    v10 = 0;
    v12 = v6;
    lParam = &v12;
    v11 = sub_FA7910;
    _swprintf(&String, L"%s License Agreement", a4);
    SetWindowTextW(hDlg, &String);
    v7 = GetDlgItem(hDlg, 500);
    SendMessageW(v7, 0x435u, 0, 0x100000);
    v8 = GetDlgItem(v13, 500);
    SendMessageW(v8, 0x449u, 2u, &lParam);
    free(v6);
  }
  else
  {
    if ( a2 != 273 )
    {
      if ( a2 == 312 && a4 == GetDlgItem(hDlg, 500) )
        return GetSysColorBrush(5);
      return 0;
    }
    switch ( a3 )
    {
      case 1u:
        EndDialog(hDlg, 1);
        break;
      case 2u:
        EndDialog(hDlg, 0);
        break;
      case 0x1F5u:
        v5 = GetDlgItem(hDlg, 500);
        sub_FA6D40(v5);
        break;
      default:
        return 0;
    }
  }
  return 1;
}

//----- (00FA6A40) --------------------------------------------------------
_BYTE *sub_FA6A40()
{
  const char *v0; // esi
  int v1; // edx
  size_t v2; // edi
  const char *v3; // ecx
  _BYTE *v4; // eax
  int v5; // edi
  _BYTE *i; // ebx
  const char *v7; // eax
  char v8; // cl
  int v10; // [esp+Ch] [ebp-4h]

  v0 = off_105C4C8[0];
  v1 = 0;
  v2 = 1;
  if ( off_105C4C8[0] )
  {
    v3 = off_105C4C8[0];
    do
    {
      ++v1;
      v2 += strlen(v3);
      v3 = off_105C4C8[v1];
    }
    while ( v3 );
  }
  v4 = malloc(v2);
  v5 = 0;
  v10 = 0;
  for ( i = v4; v0; v0 = off_105C4C8[v10] )
  {
    v7 = v0;
    do
    {
      v8 = *v7++;
      v7[v5 - 1 + i - v0] = v8;
    }
    while ( v8 );
    v5 += strlen(v0);
    ++v10;
  }
  i[v5] = 0;
  return i;
}
// 105C4C8: using guessed type char *off_105C4C8[48];

//----- (00FA6AE0) --------------------------------------------------------
BOOL __cdecl License_IsEulaAccepted(HKEY hKey, LPCWSTR lpSubKey)
{
  LSTATUS v2; // esi
  BOOL result; // eax
  DWORD cbData; // [esp+0h] [ebp-Ch]
  BYTE Data[4]; // [esp+4h] [ebp-8h]
  HKEY hSubKey; // [esp+8h] [ebp-4h]

  hSubKey = 0;
  *Data = 0;
  result = 0;
  if ( !RegOpenKeyExW(hKey, lpSubKey, 0, 0x101u, &hSubKey) )
  {
    cbData = 4;
    v2 = RegQueryValueExW(hSubKey, L"EulaAccepted", 0, 0, Data, &cbData);
    RegCloseKey(hSubKey);
    if ( !v2 )
    {
      if ( *Data )
        result = 1;
    }
  }
  return result;
}

//----- (00FA6B60) --------------------------------------------------------
BOOL __cdecl License_CheckEulaAccepted(LPCWSTR lpszText)
{
  BOOL result; // eax
  WCHAR szBuffer[260]; // [esp+0h] [ebp-20Ch]

  _swprintf(szBuffer, L"%s\\%s", L"Software\\Sysinternals", lpszText);
  if ( License_IsEulaAccepted(HKEY_LOCAL_MACHINE, L"Software\\Sysinternals")
    || License_IsEulaAccepted(HKEY_CURRENT_USER, L"Software\\Sysinternals") )
  {
    result = 1;
  }
  else
  {
    result = License_IsEulaAccepted(HKEY_CURRENT_USER, szBuffer) != 0;
  }
  return result;
}

//----- (00FA6C00) --------------------------------------------------------
signed int sub_FA6C00()
{
  signed int v0; // esi
  DWORD Type; // [esp+4h] [ebp-218h]
  DWORD cbData; // [esp+8h] [ebp-214h]
  HKEY phkResult; // [esp+Ch] [ebp-210h]
  wchar_t Data[260]; // [esp+10h] [ebp-20Ch]

  phkResult = 0;
  v0 = 0;
  cbData = 520;
  Type = 0;
  if ( !RegOpenKeyW(HKEY_LOCAL_MACHINE, L"Software\\Microsoft\\windows nt\\currentversion", &phkResult) )
  {
    if ( !RegQueryValueExW(phkResult, L"ProductName", 0, &Type, Data, &cbData) && !_wcsicmp(L"iotuap", Data) )
      v0 = 1;
    RegCloseKey(phkResult);
  }
  return v0;
}

//----- (00FA6CC0) --------------------------------------------------------
signed int sub_FA6CC0()
{
  signed int v0; // esi
  DWORD cbData; // [esp+4h] [ebp-10h]
  BYTE Data[4]; // [esp+8h] [ebp-Ch]
  DWORD Type; // [esp+Ch] [ebp-8h]
  HKEY phkResult; // [esp+10h] [ebp-4h]

  phkResult = 0;
  v0 = 0;
  *Data = 0;
  cbData = 4;
  Type = 0;
  if ( !RegOpenKeyW(
          HKEY_LOCAL_MACHINE,
          L"Software\\Microsoft\\Windows NT\\CurrentVersion\\Server\\ServerLevels",
          &phkResult) )
  {
    if ( !RegQueryValueExW(phkResult, L"NanoServer", 0, &Type, Data, &cbData) && Type == 4 && *Data == 1 )
      v0 = 1;
    RegCloseKey(phkResult);
  }
  return v0;
}

//----- (00FA6D40) --------------------------------------------------------
BOOL __cdecl sub_FA6D40(HWND a1)
{
  BOOL result; // eax
  HCURSOR v2; // eax
  int v3; // edi
  int v4; // ebx
  int v5; // esi
  HWND v6; // ebx
  LRESULT v7; // esi
  DOCINFOW v8; // [esp+4h] [ebp-98h]
  struct tagPDW pPD; // [esp+18h] [ebp-84h]
  HWND hWnd; // [esp+5Ch] [ebp-40h]
  HCURSOR hCursor; // [esp+60h] [ebp-3Ch]
  int v12; // [esp+64h] [ebp-38h]
  LPARAM lParam; // [esp+68h] [ebp-34h]
  HDC v14; // [esp+6Ch] [ebp-30h]
  struct tagRECT rc; // [esp+70h] [ebp-2Ch]
  __int128 v16; // [esp+80h] [ebp-1Ch]
  LRESULT v17; // [esp+90h] [ebp-Ch]
  int v18; // [esp+94h] [ebp-8h]

  hWnd = a1;
  memset(&pPD.hwndOwner, 0, 0x3Eu);
  pPD.lStructSize = 66;
  pPD.hwndOwner = a1;
  pPD.hInstance = GetModuleHandleW(0);
  pPD.Flags = 332;
  result = PrintDlgW(&pPD);
  if ( result )
  {
    v2 = LoadCursorW(0, 0x7F02);
    hCursor = SetCursor(v2);
    v12 = GetDeviceCaps(pPD.hDC, 8);
    v3 = GetDeviceCaps(pPD.hDC, 10);
    v4 = GetDeviceCaps(pPD.hDC, 88);
    v5 = GetDeviceCaps(pPD.hDC, 90);
    lParam = 0;
    memset(&v14, 0, 0x2Cu);
    _mm_storeu_si128(&v8.lpszDocName, 0i64);
    SetMapMode(pPD.hDC, 1);
    lParam = pPD.hDC;
    v14 = pPD.hDC;
    *&v16 = 0i64;
    HIDWORD(v16) = 1440 * (v3 / v5);
    DWORD2(v16) = 1440 * (v12 / v4);
    _mm_storeu_si128(&rc, _mm_loadu_si128(&v16));
    InflateRect(&rc, -1440, -1440);
    v17 = 0;
    v18 = -1;
    v8.cbSize = 20;
    v8.lpszDocName = L"Sysinternals License";
    StartDocW(pPD.hDC, &v8);
    v6 = hWnd;
    v12 = SendMessageW(hWnd, 0xEu, 0, 0);
    StartPage(pPD.hDC);
    v7 = SendMessageW(v6, 0x439u, 1u, &lParam);
    EndPage(pPD.hDC);
    while ( v7 < v12 )
    {
      v17 = v7;
      v18 = -1;
      StartPage(pPD.hDC);
      v7 = SendMessageW(v6, 0x439u, 1u, &lParam);
      EndPage(pPD.hDC);
    }
    SendMessageW(v6, 0x439u, 0, 0);
    EndDoc(pPD.hDC);
    SetCursor(hCursor);
    result = 1;
  }
  return result;
}
// 103ACE4: using guessed type wchar_t aSysinternalsLi[21];

//----- (00FA6F60) --------------------------------------------------------
BOOL __cdecl LicenseCheck(WCHAR *lpszText, int a2, int a3)
{
  int v3; // esi
  signed int ret; // ebx
  signed int Data; // [esp+8h] [ebp-4h]

  Data = 0;
  if ( !a2 || !a3 )
    return sub_FA7390(lpszText, 0, 0);
  v3 = 0;
  if ( *a2 > 0 )
  {
    Data = 0;
    while ( _wcsicmp(*(a3 + 4 * v3), L"/accepteula") && _wcsicmp(*(a3 + 4 * v3), L"-accepteula") )
    {
      if ( ++v3 >= *a2 )
        goto LABEL_12;
    }
    for ( Data = 1; v3 < *a2 - 1; ++v3 )
      *(a3 + 4 * v3) = *(a3 + 4 * v3 + 4);
    --*a2;
  }
LABEL_12:
  ret = Data;
  if ( LicensePropSheet(lpszText, Data) )
    ret = 1;
  return ret != 0;
}

//----- (00FA7020) --------------------------------------------------------
signed int sub_FA7020()
{
  signed int v0; // esi
  char v1; // bh
  char v2; // bl

  v0 = 0;
  v1 = 0;
  wprintf(off_105C58C);
  do
  {
    printf("Accept Eula (Y/N)?");
    v2 = _getch();
    printf("%c\n", v2);
    if ( v2 == 121 || v2 == 89 )
    {
      v0 = 1;
      v1 = 1;
    }
  }
  while ( v2 != 110 && v2 != 78 && v1 != 1 );
  return v0;
}

//----- (00FA7080) --------------------------------------------------------
void __noreturn sub_FA7080()
{
  wprintf_s(L"%ls", off_105C58C);
  wprintf_s(L"This is the first run of this program. You must accept EULA to continue.\n");
  wprintf_s(L"Use -accepteula to accept EULA.\n\n");
  exit(1);
}

//----- (00FA70B0) --------------------------------------------------------
BOOL __cdecl LicensePropSheet(WCHAR *lpszText, BYTE Data)
{
  HANDLE hOutputHandle; // eax
  char *v3; // edi
  char *v4; // esi
  int v5; // esi
  unsigned int v6; // eax
  int v7; // esi
  unsigned int v8; // eax
  int v9; // esi
  unsigned int v10; // eax
  int v11; // esi
  unsigned int v12; // eax
  unsigned int v13; // esi
  int v14; // esi
  HKEY hKey; // [esp+4h] [ebp-210h]
  WCHAR szSubKey[260]; // [esp+8h] [ebp-20Ch]

  hKey = 0;
  _swprintf(szSubKey, L"Software\\Sysinternals\\%s", lpszText);
  if ( Data )
    goto __quit;
  *&Data = License_CheckEulaAccepted(lpszText);
  if ( Data )
    goto __quit;
  if ( sub_FA6C00() )
  {
    *&Data = sub_FA7020();
  }
  else
  {
    if ( sub_FA6CC0() || (hOutputHandle = GetStdHandle(STD_OUTPUT_HANDLE), GetFileType(hOutputHandle) == FILE_TYPE_PIPE) )
      sub_FA7080();
    v3 = LocalAlloc(LMEM_ZEROINIT, 1000u);
    LoadLibraryW(L"Riched32.dll");
    *v3 = 0x80C808D0;
    *(v3 + 10) = 0;
    *(v3 + 14) = 0xB40138;
    *(v3 + 4) = 0;
    *(v3 + 18) = 0;
    v4 = &v3[2 * sub_FA6870((v3 + 22), L"License Agreement") + 22];
    *v4 = 8;
    v5 = &v4[2 * sub_FA6870((v4 + 2), L"MS Shell Dlg") + 5] & 0xFFFFFFFC;
    *(v5 + 8) = 0x30007;
    *(v5 + 12) = 0xE012A;
    *(v5 + 16) = 0xFFFF01F6;
    *v5 = 0x50000000;
    *(v5 + 20) = 130;
    v5 += 22;
    v6 = sub_FA6870(v5, L"You can also use the /accepteula command-line switch to accept the EULA.");
    *(v5 + 2 * v6) = 0;
    ++*(v3 + 4);
    v7 = (v5 + 2 * v6 + 5) & 0xFFFFFFFC;
    *(v7 + 8) = 0x9F00C9;
    *(v7 + 12) = 0xE0032;
    *(v7 + 16) = 0xFFFF0001;
    *v7 = 0x50010000;
    *(v7 + 20) = 128;
    v7 += 22;
    v8 = sub_FA6870(v7, L"&Agree");
    *(v7 + 2 * v8) = 0;
    ++*(v3 + 4);
    v9 = (v7 + 2 * v8 + 5) & 0xFFFFFFFC;
    *(v9 + 8) = 0x9F00FF;
    *(v9 + 12) = 0xE0032;
    *(v9 + 16) = 0xFFFF0002;
    *v9 = 0x50010000;
    *(v9 + 20) = 128;
    v9 += 22;
    v10 = sub_FA6870(v9, L"&Decline");
    *(v9 + 2 * v10) = 0;
    ++*(v3 + 4);
    v11 = (v9 + 2 * v10 + 5) & 0xFFFFFFFC;
    *(v11 + 8) = 0x9F0007;
    *(v11 + 12) = 0xE0032;
    *(v11 + 16) = 0xFFFF01F5;
    *v11 = 0x50010000;
    *(v11 + 20) = 128;
    v11 += 22;
    v12 = sub_FA6870(v11, L"&Print");
    *(v11 + 2 * v12) = 0;
    ++*(v3 + 4);
    v13 = (v11 + 2 * v12 + 5) & 0xFFFFFFFC;
    *(v13 + 8) = 0xE0007;
    *(v13 + 12) = 0x8C012A;
    *(v13 + 16) = 500;
    *v13 = 0x50A11844;
    v14 = v13 + 18 + 2 * sub_FA6870(v13 + 18, L"RICHEDIT");
    *(v14 + 2 * sub_FA6870(v14, L"&Decline")) = 0;
    ++*(v3 + 4);
    *&Data = DialogBoxIndirectParamW(0, v3, 0, DlgLicenseInfo, lpszText);
    LocalFree(v3);
  }
  if ( Data )
  {
__quit:
    if ( !RegCreateKeyW(HKEY_CURRENT_USER, szSubKey, &hKey) )
    {
      RegSetValueExW(hKey, L"EulaAccepted", 0, 4u, &Data, 4u);
      RegCloseKey(hKey);
    }
  }
  return Data != 0;
}
// 103AD8C: using guessed type wchar_t aLicenseAgreeme[18];
// 103ADB0: using guessed type wchar_t aMsShellDlg[13];
// 103ADD0: using guessed type wchar_t aYouCanAlsoUseT[73];
// 103AE64: using guessed type wchar_t aAgree[7];
// 103AE74: using guessed type wchar_t aDecline[9];
// 103AE88: using guessed type wchar_t aPrint[7];
// 103AE98: using guessed type wchar_t aRichedit[9];

//----- (00FA7390) --------------------------------------------------------
BOOL __cdecl sub_FA7390(LPARAM a1, int *a2, int a3)
{
  int v3; // ebx
  int *v4; // edi
  HMODULE v5; // eax
  FARPROC v6; // esi
  LPWSTR v7; // eax
  int v8; // esi
  int v9; // eax
  signed int v10; // ebx
  LSTATUS (__stdcall *v11)(HKEY, LPCWSTR, LPDWORD, LPDWORD, LPBYTE, LPDWORD); // esi
  LSTATUS v12; // esi
  LSTATUS v13; // esi
  signed int v14; // eax
  signed int v16; // eax
  HANDLE v17; // eax
  char *v18; // edi
  const wchar_t *v19; // ecx
  wchar_t v20; // ax
  const wchar_t *v21; // ecx
  wchar_t v22; // ax
  unsigned int v23; // eax
  int v24; // esi
  const wchar_t *v25; // ecx
  int v26; // edx
  wchar_t v27; // ax
  unsigned int v28; // eax
  int v29; // esi
  const wchar_t *v30; // ecx
  int v31; // edx
  wchar_t v32; // ax
  unsigned int v33; // eax
  int v34; // esi
  const wchar_t *v35; // ecx
  int v36; // edx
  wchar_t v37; // ax
  unsigned int v38; // eax
  int v39; // esi
  const wchar_t *v40; // ecx
  int v41; // edx
  wchar_t v42; // ax
  unsigned int v43; // eax
  int v44; // esi
  const wchar_t *v45; // ecx
  int v46; // edx
  wchar_t v47; // ax
  const wchar_t *v48; // ecx
  wchar_t v49; // ax
  LPARAM v50; // ST14_4
  DWORD cbData; // [esp+Ch] [ebp-438h]
  DWORD v52; // [esp+10h] [ebp-434h]
  BYTE Data[4]; // [esp+14h] [ebp-430h]
  LPARAM dwInitParam; // [esp+18h] [ebp-42Ch]
  BYTE v55[4]; // [esp+1Ch] [ebp-428h]
  HKEY v56; // [esp+20h] [ebp-424h]
  HKEY phkResult; // [esp+24h] [ebp-420h]
  HKEY hKey; // [esp+28h] [ebp-41Ch]
  BYTE v59[4]; // [esp+2Ch] [ebp-418h]
  wchar_t Dest; // [esp+30h] [ebp-414h]
  WCHAR SubKey; // [esp+238h] [ebp-20Ch]

  v3 = a3;
  v4 = a2;
  dwInitParam = a1;
  *v59 = 0;
  if ( !a2 || !a3 )
  {
    v5 = LoadLibraryW(L"Shell32.dll");
    v6 = GetProcAddress(v5, "CommandLineToArgvW");
    if ( !v6 )
      goto LABEL_14;
    v4 = &dword_1064DB4;
    v7 = GetCommandLineW();
    v3 = (v6)(v7, &dword_1064DB4);
  }
  v8 = 0;
  if ( *v4 > 0 )
  {
    *v59 = 0;
    while ( _wcsicmp(*(v3 + 4 * v8), L"/accepteula") && _wcsicmp(*(v3 + 4 * v8), L"-accepteula") )
    {
      if ( ++v8 >= *v4 )
        goto LABEL_14;
    }
    v9 = *v4 - 1;
    *v59 = 1;
    if ( v8 < v9 )
    {
      do
      {
        *(v3 + 4 * v8) = *(v3 + 4 * v8 + 4);
        ++v8;
      }
      while ( v8 < *v4 - 1 );
    }
    --*v4;
  }
LABEL_14:
  v10 = *v59;
  v56 = 0;
  _swprintf(&SubKey, L"Software\\Sysinternals\\%s", dwInitParam);
  if ( *v59 )
    goto LABEL_25;
  _swprintf(&Dest, L"%s\\%s", L"Software\\Sysinternals", dwInitParam);
  phkResult = 0;
  *Data = 0;
  v11 = RegQueryValueExW;
  if ( !RegOpenKeyExW(HKEY_LOCAL_MACHINE, L"Software\\Sysinternals", 0, 0x101u, &phkResult) )
  {
    cbData = 4;
    v12 = RegQueryValueExW(phkResult, L"EulaAccepted", 0, 0, Data, &cbData);
    RegCloseKey(phkResult);
    if ( !v12 && *Data )
      goto LABEL_22;
    v11 = RegQueryValueExW;
  }
  hKey = 0;
  *v55 = 0;
  if ( RegOpenKeyExW(HKEY_CURRENT_USER, L"Software\\Sysinternals", 0, 0x101u, &hKey)
    || (v52 = 4, v13 = v11(hKey, L"EulaAccepted", 0, 0, v55, &v52), RegCloseKey(hKey), v13)
    || !*v55 )
  {
    if ( !License_IsEulaAccepted(HKEY_CURRENT_USER, &Dest) )
    {
      v14 = 0;
      goto LABEL_31;
    }
    *v59 = 1;
LABEL_25:
    if ( !RegCreateKeyW(HKEY_CURRENT_USER, &SubKey, &v56) )
    {
      RegSetValueExW(v56, L"EulaAccepted", 0, 4u, v59, 4u);
      RegCloseKey(v56);
    }
    if ( *v59 )
      v10 = 1;
    return v10 != 0;
  }
LABEL_22:
  v14 = 1;
LABEL_31:
  *v59 = v14;
  if ( v14 )
    goto LABEL_25;
  if ( sub_FA6C00() )
  {
    v16 = sub_FA7020();
    *v59 = v16;
  }
  else
  {
    if ( sub_FA6CC0() || (v17 = GetStdHandle(0xFFFFFFF5), GetFileType(v17) == 3) )
      sub_FA7080();
    v18 = LocalAlloc(0x40u, 0x3E8u);
    LoadLibraryW(L"Riched32.dll");
    *v18 = -2134374192;
    v19 = L"License Agreement";
    *(v18 + 10) = 0;
    *(v18 + 14) = 11796792;
    *(v18 + 4) = 0;
    *(v18 + 18) = 0;
    do
    {
      v20 = *v19;
      ++v19;
      *(v19 + v18 + 22 - L"License Agreement" - 2) = v20;
    }
    while ( v20 );
    v21 = L"MS Shell Dlg";
    *(v18 + 29) = 8;
    do
    {
      v22 = *v21;
      ++v21;
      *(v21 + v18 + 60 - L"MS Shell Dlg" - 2) = v22;
    }
    while ( v22 );
    v23 = (v18 + 89) & 0xFFFFFFFC;
    v24 = v23 + 18;
    *(v23 + 16) = 502;
    v25 = L"You can also use the /accepteula command-line switch to accept the EULA.";
    *(v23 + 8) = 196615;
    v26 = v23 + 22 - L"You can also use the /accepteula command-line switch to accept the EULA.";
    *(v23 + 12) = 917802;
    *v23 = 1342177280;
    *(v23 + 18) = 8585215;
    do
    {
      v27 = *v25;
      ++v25;
      *(v25 + v26 - 2) = v27;
    }
    while ( v27 );
    *(v24 + 150) = 0;
    ++*(v18 + 4);
    v28 = (v24 + 155) & 0xFFFFFFFC;
    v29 = v28 + 18;
    *(v28 + 16) = 1;
    v30 = L"&Agree";
    *(v28 + 8) = 10420425;
    v31 = v28 + 22 - L"&Agree";
    *(v28 + 12) = 917554;
    *v28 = 1342242816;
    *(v28 + 18) = 8454143;
    do
    {
      v32 = *v30;
      ++v30;
      *(v30 + v31 - 2) = v32;
    }
    while ( v32 );
    *(v29 + 18) = 0;
    ++*(v18 + 4);
    v33 = (v29 + 23) & 0xFFFFFFFC;
    v34 = v33 + 18;
    *(v33 + 16) = 2;
    v35 = L"&Decline";
    *(v33 + 8) = 10420479;
    v36 = v33 + 22 - L"&Decline";
    *(v33 + 12) = 917554;
    *v33 = 1342242816;
    *(v33 + 18) = 8454143;
    do
    {
      v37 = *v35;
      ++v35;
      *(v35 + v36 - 2) = v37;
    }
    while ( v37 );
    *(v34 + 22) = 0;
    ++*(v18 + 4);
    v38 = (v34 + 27) & 0xFFFFFFFC;
    v39 = v38 + 18;
    *(v38 + 16) = 501;
    v40 = L"&Print";
    *(v38 + 8) = 10420231;
    v41 = v38 + 22 - L"&Print";
    *(v38 + 12) = 917554;
    *v38 = 1342242816;
    *(v38 + 18) = 8454143;
    do
    {
      v42 = *v40;
      ++v40;
      *(v40 + v41 - 2) = v42;
    }
    while ( v42 );
    *(v39 + 18) = 0;
    ++*(v18 + 4);
    v43 = (v39 + 23) & 0xFFFFFFFC;
    v44 = v43 + 18;
    *(v43 + 16) = 500;
    v45 = L"RICHEDIT";
    *(v43 + 8) = 917511;
    *(v43 + 12) = 9175338;
    *v43 = 1352734788;
    v46 = v43 + 18 - L"RICHEDIT";
    do
    {
      v47 = *v45;
      ++v45;
      *(v45 + v46 - 2) = v47;
    }
    while ( v47 );
    v48 = L"&Decline";
    do
    {
      v49 = *v48;
      ++v48;
      *(v48 + v44 + 18 - L"&Decline" - 2) = v49;
    }
    while ( v49 );
    v50 = dwInitParam;
    *(v44 + 36) = 0;
    ++*(v18 + 4);
    *v59 = DialogBoxIndirectParamW(0, v18, 0, DlgLicenseInfo, v50);
    LocalFree(v18);
    v16 = *v59;
  }
  if ( v16 )
    goto LABEL_25;
  return v10 != 0;
}
// 103AD8C: using guessed type wchar_t aLicenseAgreeme[18];
// 103ADB0: using guessed type wchar_t aMsShellDlg[13];
// 103ADD0: using guessed type wchar_t aYouCanAlsoUseT[73];
// 103AE64: using guessed type wchar_t aAgree[7];
// 103AE74: using guessed type wchar_t aDecline[9];
// 103AE88: using guessed type wchar_t aPrint[7];
// 103AE98: using guessed type wchar_t aRichedit[9];
// 1064DB4: using guessed type int dword_1064DB4;

//----- (00FA7910) --------------------------------------------------------
int __stdcall sub_FA7910(int a1, void *a2, int a3, int a4)
{
  int v4; // eax
  int v5; // esi

  *a1;
  v4 = strlen(*a1);
  v5 = a3;
  if ( a3 > v4 )
    v5 = v4;
  memmove_0(a2, *a1, v5);
  *a4 = v5;
  *a1 += v5;
  return 0;
}

//----- (00FA7950) --------------------------------------------------------
signed int CAboutWnd::HandleInitDialog()
{
  return 1;
}

//----- (00FA7960) --------------------------------------------------------
LRESULT __cdecl CAboutWnd::HandleCommand(HWND hWnd, int a2, WPARAM wParam, LPARAM lParam)
{
  return HandleCmdHandler(&CAboutDlg::gCmdHandler, hWnd, wParam, lParam);
}
// 105C5BC: using guessed type struct tagMSGHANDLER CAboutDlg::gCmdHandler;

//----- (00FA7980) --------------------------------------------------------
int __cdecl Command_OkOrCancel(HWND hDlg)
{
  EndDialog(hDlg, 1);
  return 1;
}

//----- (00FA79A0) --------------------------------------------------------
HBRUSH __stdcall DlgAbout(HWND hDlg, UINT Msg, WPARAM hdc, LPARAM lParam)
{
  HWND v4; // edi
  DWORD dwVersionLength; // esi
  void *pVersionInfo; // edi
  const WCHAR *v7; // eax
  const WCHAR *v8; // eax
  COLORREF v10; // ST14_4
  HGDIOBJ v11; // eax
  POINT pt; // ST10_8
  HWND v13; // eax
  int v14; // edx
  POINT pt_1; // ST10_8
  DWORD dwHandle; // [esp+Ch] [ebp-28Ch]
  tagLOGFONTW LogFont; // [esp+10h] [ebp-288h]
  struct tagRECT Rect; // [esp+6Ch] [ebp-22Ch]
  struct tagRECT v19; // [esp+7Ch] [ebp-21Ch]
  WCHAR szFileName[260]; // [esp+8Ch] [ebp-20Ch]

  switch ( Msg )
  {
    case WM_INITDIALOG:
      v4 = ghMainWnd;
      ghDefaultGuiFont = GetStockObject(DEFAULT_GUI_FONT);
      GetObjectW(ghDefaultGuiFont, 92, &LogFont);
      LogFont.lfUnderline = 1;
      ghIndirectFontCreated = CreateFontIndirectW(&LogFont);
      gbIndirectFontCreated = 1;
      ghWndAddressInAbout = GetDlgItem(hDlg, IDD_ABOUT_STATIC_ADDRESS);
      if ( ghWndAddressInAbout )
      {
        GetWindowRect(v4, &Rect);
        GetWindowRect(hDlg, &v19);
        Rect.left += 70;
        Rect.top += 60;
        MoveWindow(hDlg, Rect.left, Rect.top, v19.right - v19.left, v19.bottom - v19.top, 1);
        GetModuleFileNameW(0, szFileName, MAX_PATH);
        dwVersionLength = GetFileVersionInfoSizeW(szFileName, &dwHandle);
        pVersionInfo = malloc(dwVersionLength);
        GetFileVersionInfoW(szFileName, 0, dwVersionLength, pVersionInfo);
        v7 = sub_FDEAA0(pVersionInfo, L"FileVersion");
        SetDlgItemTextW(hDlg, IDD_ABOUT_STATIC_VERSION, v7);
        v8 = sub_FDEAA0(pVersionInfo, L"LegalCopyright");
        SetDlgItemTextW(hDlg, IDD_ABOUT_STATIC_COPYRIGHT, v8);
        free(pVersionInfo);
      }
      else
      {
        ghWndAddressInAbout = GetDlgItem(hDlg, 0x51B);
      }
      ghHandArrow = LoadCursorW(ghInstance, L"HAND");
      ghCursorArrow = LoadCursorW(0, IDC_ARROW);
      return 1;
    case WM_CTLCOLORSTATIC:
      if ( lParam != ghWndAddressInAbout )
        return HandleMsgHandler(&CAboutDlg::gMsgHandler, hDlg, Msg, hdc, lParam);
      SetBkMode(hdc, 1);
      if ( GetSysColorBrush(COLOR_HOTLIGHT) )
      {
        v10 = GetSysColor(COLOR_HOTLIGHT);
        SetTextColor(hdc, v10);
      }
      else
      {
        SetTextColor(hdc, 0xFF0000u);
      }
      v11 = ghDefaultGuiFont;
      if ( gbIndirectFontCreated )
        v11 = ghIndirectFontCreated;
      SelectObject(hdc, v11);
      return GetSysColorBrush(COLOR_BTNFACE);
    case WM_MOUSEFIRST:
      pt.y = lParam >> 16;
      pt.x = lParam;
      v13 = ChildWindowFromPoint(hDlg, pt);
      v14 = gbIndirectFontCreated;
      if ( gbIndirectFontCreated == (v13 == ghWndAddressInAbout) )
      {
        gbIndirectFontCreated = gbIndirectFontCreated == 0;
        InvalidateRect(ghWndAddressInAbout, 0, 0);
        v14 = gbIndirectFontCreated;
      }
      if ( v14 )
        SetCursor(ghCursorArrow);
      else
        SetCursor(ghHandArrow);
      return HandleMsgHandler(&CAboutDlg::gMsgHandler, hDlg, Msg, hdc, lParam);
    case WM_LBUTTONUP:
      pt_1.y = lParam >> 16;
      pt_1.x = lParam;
      if ( ChildWindowFromPoint(hDlg, pt_1) == ghWndAddressInAbout )
      {
        if ( GetDlgItem(hDlg, IDD_ABOUT_STATIC_ADDRESS) )
          ShellExecuteW(hDlg, L"open", L"http://www.sysinternals.com", 0, 0, 1);
        else
          ShellExecuteW(hDlg, L"open", L"http://www.microsoft.com/whdc/devtools/debugging/default.mspx", 0, 0, 1);
      }
      break;
    default:
      return HandleMsgHandler(&CAboutDlg::gMsgHandler, hDlg, Msg, hdc, lParam);
  }
  return HandleMsgHandler(&CAboutDlg::gMsgHandler, hDlg, Msg, hdc, lParam);
}
// 103B0D4: using guessed type wchar_t aFileversion[12];
// 103B0EC: using guessed type wchar_t aLegalcopyright[15];
// 103B118: using guessed type wchar_t aHttpWwwSysinte[28];
// 1064DBC: using guessed type int gbIndirectFontCreated;
// 1064DC0: using guessed type int ghDefaultGuiFont;

//----- (00FA7DC0) --------------------------------------------------------
int __cdecl Command_About(HWND hWndParent)
{
  DialogBoxParamW(ghInstance, L"AboutBox", hWndParent, DlgAbout, 0);
  return 0;
}

//----- (00FA7DF0) --------------------------------------------------------
int *__cdecl sub_FA7DF0(int *a1, const unsigned __int16 *a2)
{
  signed int v2; // esi
  unsigned int v3; // ecx
  int *v4; // edx
  int v5; // eax
  signed int v6; // ebx
  unsigned int v7; // edi
  signed int v8; // ebx
  int v9; // edi
  int v10; // ecx
  int v11; // eax
  int v12; // eax
  char *v13; // ecx
  int v14; // ecx
  int v15; // eax
  int v16; // eax
  _DWORD *v17; // ecx
  _DWORD *v18; // edx
  _WORD **v19; // ecx
  _WORD *v20; // edx
  __int16 v21; // ax
  int v22; // eax
  int v23; // edx
  int v24; // eax
  int v25; // edx
  int v26; // ecx
  int v27; // eax
  _WORD **v28; // ecx
  _WORD *v29; // edx
  __int16 v30; // ax
  int v31; // eax
  _DWORD *v32; // ecx
  int v33; // eax
  int v34; // eax
  int v35; // ecx
  bool v36; // al
  int v37; // esi
  int v38; // ecx
  int v40; // [esp+0h] [ebp-70h]
  void **v41; // [esp+10h] [ebp-60h]
  void **v42; // [esp+24h] [ebp-4Ch]
  void **v43; // [esp+38h] [ebp-38h]
  __int64 v44; // [esp+4Ch] [ebp-24h]
  int v45; // [esp+54h] [ebp-1Ch]
  int v46; // [esp+58h] [ebp-18h]
  unsigned int v47; // [esp+5Ch] [ebp-14h]
  int *v48; // [esp+60h] [ebp-10h]
  int v49; // [esp+6Ch] [ebp-4h]

  v48 = &v40;
  v2 = 0;
  v45 = 0;
  if ( *a2 )
    v3 = wcslen(a2);
  else
    v3 = 0;
  v4 = a1;
  v47 = v3;
  v5 = *(*a1 + 4);
  v6 = *(a1 + v5 + 36);
  v7 = *(a1 + v5 + 32);
  if ( v6 >= 0 && (v6 > 0 || v7 && v6 >= 0 && (v6 > 0 || v7 > v3)) )
  {
    v8 = (__PAIR__(v6, v7) - v3) >> 32;
    v9 = v7 - v3;
  }
  else
  {
    v44 = 0i64;
    v8 = 0;
    v9 = 0;
  }
  v10 = *(a1 + v5 + 56);
  LODWORD(v44) = a1;
  if ( v10 )
  {
    (*(*v10 + 4))();
    v4 = a1;
  }
  v11 = *v4;
  v49 = 0;
  v12 = *(v11 + 4);
  if ( !*(v4 + v12 + 12) )
  {
    v13 = *(v4 + v12 + 60);
    if ( v13 )
    {
      if ( v13 != v4 )
      {
        sub_FA9D10(v13);
        v4 = a1;
      }
    }
  }
  v14 = *(*v4 + 4);
  BYTE4(v44) = *(v4 + v14 + 12) == 0;
  v49 = 1;
  if ( BYTE4(v44) )
  {
    v15 = *(v4 + v14 + 20) & 0x1C0;
    LOBYTE(v49) = 2;
    if ( v15 == 64 )
      goto LABEL_66;
    while ( v8 >= 0 && (v8 > 0 || v9) )
    {
      v16 = *(*v4 + 4);
      v46 = *(v4 + v16 + 64);
      v17 = *(v4 + v16 + 56);
      if ( *v17[8] && (v18 = v17[12], *v18 > 0) )
      {
        --*v18;
        v19 = v17[8];
        v20 = *v19;
        ++*v19;
        v21 = v46;
        *v20 = v46;
      }
      else
      {
        v21 = (*(*v17 + 12))(v46);
      }
      v4 = a1;
      if ( v21 == -1 )
      {
        v2 = 4;
        v45 = 4;
        break;
      }
      v8 = (__PAIR__(v8, v9--) - 1) >> 32;
    }
    if ( !v2 )
    {
LABEL_66:
      v22 = (*(**(v4 + *(*v4 + 4) + 56) + 36))(a2, v47, 0);
      if ( v22 != v47 || v23 )
      {
        v2 = 4;
      }
      else
      {
        while ( v8 >= 0 && (v8 > 0 || v9) )
        {
          v24 = *(*a1 + 4);
          v25 = *(a1 + v24 + 64);
          v26 = *(a1 + v24 + 56);
          v46 = *(a1 + v24 + 64);
          if ( **(v26 + 32) && (v27 = **(v26 + 48), v27 > 0) )
          {
            **(v26 + 48) = v27 - 1;
            v28 = *(v26 + 32);
            v29 = *v28;
            ++*v28;
            v30 = v46;
            *v29 = v46;
          }
          else
          {
            v30 = (*(*v26 + 12))(v25);
          }
          if ( v30 == -1 )
          {
            v2 |= 4u;
            break;
          }
          v8 = (__PAIR__(v8, v9--) - 1) >> 32;
        }
      }
      v4 = a1;
    }
    v31 = *(*v4 + 4);
    *(v4 + v31 + 32) = 0;
    *(v4 + v31 + 36) = 0;
    v49 = 1;
  }
  else
  {
    v2 = 4;
  }
  v32 = (v4 + *(*v4 + 4));
  if ( v2 )
  {
    v33 = v2 | v32[3];
    if ( !v32[14] )
      LOBYTE(v33) = v33 | 4;
    v34 = v33 & 0x17;
    v32[3] = v34;
    v35 = v34 & v32[4];
    if ( v35 )
    {
      if ( v35 & 4 )
      {
        sub_FA8630(&v43, 1, off_105AA40, "ios_base::badbit set");
        v43 = &std::ios_base::failure::`vftable';
        _CxxThrowException(&v43, &_TI5_AVfailure_ios_base_std__);
      }
      if ( v35 & 2 )
      {
        sub_FA8630(&v42, 1, off_105AA40, "ios_base::failbit set");
        v42 = &std::ios_base::failure::`vftable';
        _CxxThrowException(&v42, &_TI5_AVfailure_ios_base_std__);
      }
      sub_FA8630(&v41, 1, off_105AA40, "ios_base::eofbit set");
      v41 = &std::ios_base::failure::`vftable';
      _CxxThrowException(&v41, &_TI5_AVfailure_ios_base_std__);
    }
  }
  v49 = -1;
  v36 = __uncaught_exception();
  v37 = v44;
  if ( !v36 )
    sub_FA92D0(v44);
  v38 = *(*(*v37 + 4) + v37 + 56);
  if ( v38 )
    (*(*v38 + 8))();
  return a1;
}
// 10081AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);
// 103BEB8: using guessed type void *std::ios_base::failure::`vftable';
// 1054548: using guessed type int _TI5_AVfailure_ios_base_std__;
// 105AA40: using guessed type int (__thiscall **off_105AA40[2])(void *, char);

//----- (00FA8150) --------------------------------------------------------
struct std::_Facet_base *__cdecl sub_FA8150(int *a1)
{
  unsigned int v1; // edi
  int v2; // ebx
  int v3; // ecx
  struct std::_Facet_base *v4; // esi
  int v5; // eax
  char v7; // [esp+10h] [ebp-24h]
  char v8; // [esp+1Ch] [ebp-18h]
  char v9; // [esp+20h] [ebp-14h]
  struct std::_Facet_base *v10; // [esp+24h] [ebp-10h]
  int v11; // [esp+30h] [ebp-4h]

  std::_Lockit::_Lockit(&v8, 0);
  v1 = dword_1085868;
  v2 = dword_1064DD0;
  v11 = 0;
  v10 = dword_1064DD0;
  if ( !dword_1085868 )
  {
    std::_Lockit::_Lockit(&v9, dword_1085868);
    if ( dword_1085868 == v1 )
      dword_1085868 = ++dword_1085840;
    std::_Lockit::~_Lockit(&v9);
    v1 = dword_1085868;
  }
  v3 = *a1;
  if ( v1 >= *(*a1 + 12) )
  {
    v4 = 0;
  }
  else
  {
    v4 = *(*(v3 + 8) + 4 * v1);
    if ( v4 )
      goto LABEL_19;
  }
  if ( !*(v3 + 20) )
    goto LABEL_12;
  v5 = sub_1004C4A();
  if ( v1 < *(v5 + 12) )
  {
    v4 = *(*(v5 + 8) + 4 * v1);
LABEL_12:
    if ( v4 )
      goto LABEL_19;
  }
  if ( v2 )
  {
    v4 = v2;
  }
  else
  {
    if ( sub_FA9090(&v10, a1) == -1 )
    {
      sub_1009D12(&v7, "bad cast");
      _CxxThrowException(&v7, &_TI2_AVbad_cast_std__);
    }
    v4 = v10;
    dword_1064DD0 = v10;
    (*(*v10 + 4))(v10);
    std::_Facet_Register(v4);
  }
LABEL_19:
  std::_Lockit::~_Lockit(&v8);
  return v4;
}
// 10081AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);
// 10545C4: using guessed type int _TI2_AVbad_cast_std__;
// 1064DD0: using guessed type int dword_1064DD0;
// 1085840: using guessed type int dword_1085840;

//----- (00FA8270) --------------------------------------------------------
_DWORD *__thiscall sub_FA8270(_DWORD *this)
{
  _DWORD *v1; // esi
  _DWORD *v2; // edi

  v1 = this;
  *this = &std::basic_streambuf<unsigned short,std::char_traits<unsigned short>>::`vftable';
  v2 = operator new(4u);
  if ( v2 )
    *v2 = std::locale::_Init(1);
  else
    v2 = 0;
  v1[13] = v2;
  v1[3] = v1 + 1;
  v1[4] = v1 + 2;
  v1[7] = v1 + 5;
  v1[8] = v1 + 6;
  v1[11] = v1 + 9;
  v1[12] = v1 + 10;
  v1[2] = 0;
  *v1[8] = 0;
  *v1[12] = 0;
  *v1[3] = 0;
  *v1[7] = 0;
  *v1[11] = 0;
  return v1;
}
// 103BF1C: using guessed type void *std::basic_streambuf<unsigned short,std::char_traits<unsigned short>>::`vftable';

//----- (00FA8300) --------------------------------------------------------
char *__thiscall sub_FA8300(char *this, int a2, int a3)
{
  char *v3; // esi
  _Cvtvec v4; // rax
  char v6; // [esp+30h] [ebp-10h]

  v3 = this;
  *(this + 1) = a3;
  *this = &std::ctype<unsigned short>::`vftable';
  _mm_storeu_si128((this + 8), _mm_loadu_si128(_Getctype(&v6)));
  v4 = _Getcvt();
  _mm_storeu_si128((v3 + 24), _mm_loadu_si128(v4._Hand));
  _mm_storeu_si128((v3 + 40), _mm_loadu_si128((v4._Hand + 16)));
  _mm_storel_epi64((v3 + 56), _mm_loadl_epi64((v4._Hand + 32)));
  *(v3 + 16) = *(v4._Hand + 40);
  return v3;
}
// 103BE5C: using guessed type void *std::ctype<unsigned short>::`vftable';

//----- (00FA8360) --------------------------------------------------------
struct std::_Locinfo *__thiscall sub_FA8360(struct std::_Locinfo *this, char *a2)
{
  struct std::_Locinfo *v2; // esi
  void **v4; // [esp+8h] [ebp-1Ch]
  struct std::_Locinfo *v5; // [esp+14h] [ebp-10h]
  int v6; // [esp+20h] [ebp-4h]

  v2 = this;
  v5 = this;
  std::_Lockit::_Lockit(this, 0);
  v6 = 0;
  *(v2 + 1) = 0;
  *(v2 + 8) = 0;
  *(v2 + 3) = 0;
  *(v2 + 16) = 0;
  *(v2 + 5) = 0;
  *(v2 + 12) = 0;
  *(v2 + 7) = 0;
  *(v2 + 16) = 0;
  *(v2 + 9) = 0;
  *(v2 + 40) = 0;
  *(v2 + 11) = 0;
  *(v2 + 48) = 0;
  LOBYTE(v6) = 6;
  if ( !a2 )
  {
    a2 = "bad locale name";
    std::exception::exception(&v4, &a2);
    v4 = &std::runtime_error::`vftable';
    _CxxThrowException(&v4, &_TI2_AVruntime_error_std__);
  }
  std::_Locinfo::_Locinfo_ctor(v2, a2);
  return v2;
}
// 10081AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);
// 103BE30: using guessed type void *std::runtime_error::`vftable';
// 10544F4: using guessed type int _TI2_AVruntime_error_std__;

//----- (00FA8420) --------------------------------------------------------
std::exception *__thiscall sub_FA8420(std::exception *this, int a2, int a3, int a4)
{
  std::exception *v4; // esi
  char *v5; // eax
  bool v6; // cf
  std::exception *result; // eax
  int v8; // [esp+0h] [ebp-4Ch]
  int v9; // [esp+4h] [ebp-48h]
  int v10; // [esp+8h] [ebp-44h]
  int v11; // [esp+Ch] [ebp-40h]
  int v12; // [esp+10h] [ebp-3Ch]
  int v13; // [esp+14h] [ebp-38h]
  char *v14; // [esp+20h] [ebp-2Ch]
  void *v15; // [esp+24h] [ebp-28h]
  unsigned int v16; // [esp+38h] [ebp-14h]
  int v17; // [esp+48h] [ebp-4h]

  v4 = this;
  v13 = 15;
  v12 = 0;
  LOBYTE(v8) = 0;
  sub_F96F00(&v8, a4, 0, 0xFFFFFFFF);
  v5 = sub_FA91F0(&v15, a2, a3, v8, v9, v10, v11, v12, v13);
  v6 = *(v5 + 5) < 0x10u;
  v17 = 0;
  if ( !v6 )
    v5 = *v5;
  v14 = v5;
  std::exception::exception(v4, &v14);
  v6 = v16 < 0x10;
  *v4 = &std::runtime_error::`vftable';
  if ( !v6 )
    j__free(v15);
  result = v4;
  *(v4 + 3) = a2;
  *v4 = &std::_System_error::`vftable';
  *(v4 + 4) = a3;
  return result;
}
// 103BE30: using guessed type void *std::runtime_error::`vftable';
// 103BE9C: using guessed type void *std::_System_error::`vftable';

//----- (00FA84F0) --------------------------------------------------------
std::exception *__thiscall sub_FA84F0(std::exception *this, struct exception *a2)
{
  std::exception *v2; // edi

  v2 = this;
  std::exception::exception(this, a2);
  *v2 = &std::_System_error::`vftable';
  *(v2 + 3) = *(a2 + 3);
  *(v2 + 4) = *(a2 + 4);
  return v2;
}
// 103BE9C: using guessed type void *std::_System_error::`vftable';

//----- (00FA8520) --------------------------------------------------------
std::exception *__thiscall sub_FA8520(std::exception *this, struct exception *a2)
{
  std::exception *v2; // edi
  std::exception *result; // eax

  v2 = this;
  std::exception::exception(this, a2);
  *v2 = &std::_System_error::`vftable';
  *(v2 + 3) = *(a2 + 3);
  *(v2 + 4) = *(a2 + 4);
  result = v2;
  *v2 = &std::ios_base::failure::`vftable';
  return result;
}
// 103BE9C: using guessed type void *std::_System_error::`vftable';
// 103BEB8: using guessed type void *std::ios_base::failure::`vftable';

//----- (00FA8550) --------------------------------------------------------
std::exception *__thiscall sub_FA8550(std::exception *this, struct exception *a2)
{
  std::exception *v2; // esi

  v2 = this;
  std::exception::exception(this, a2);
  *v2 = &std::runtime_error::`vftable';
  return v2;
}
// 103BE30: using guessed type void *std::runtime_error::`vftable';

//----- (00FA8570) --------------------------------------------------------
_DWORD *__thiscall sub_FA8570(_DWORD *this, int a2)
{
  _DWORD *v2; // edi
  int v3; // ecx
  int v4; // eax
  char *v5; // ecx

  v2 = this;
  *this = a2;
  v3 = *(*(*a2 + 4) + a2 + 56);
  if ( v3 )
    (*(*v3 + 4))();
  v4 = *(*a2 + 4);
  if ( !*(v4 + a2 + 12) )
  {
    v5 = *(v4 + a2 + 60);
    if ( v5 )
    {
      if ( v5 != a2 )
        sub_FA9D10(v5);
    }
  }
  *(v2 + 4) = *(*(*a2 + 4) + a2 + 12) == 0;
  return v2;
}

//----- (00FA8600) --------------------------------------------------------
std::exception *__thiscall sub_FA8600(std::exception *this, struct exception *a2)
{
  std::exception *v2; // edi
  std::exception *result; // eax

  v2 = this;
  std::exception::exception(this, a2);
  *v2 = &std::_System_error::`vftable';
  *(v2 + 3) = *(a2 + 3);
  *(v2 + 4) = *(a2 + 4);
  result = v2;
  *v2 = &std::system_error::`vftable';
  return result;
}
// 103BE9C: using guessed type void *std::_System_error::`vftable';
// 103BEAC: using guessed type void *std::system_error::`vftable';

//----- (00FA8630) --------------------------------------------------------
std::exception *__thiscall sub_FA8630(std::exception *this, int a2, int a3, void *a4)
{
  std::exception *v4; // esi
  size_t v5; // ecx
  std::exception *result; // eax
  void *v7; // [esp+Ch] [ebp-28h]
  int v8; // [esp+1Ch] [ebp-18h]
  unsigned int v9; // [esp+20h] [ebp-14h]
  int v10; // [esp+30h] [ebp-4h]

  v4 = this;
  v9 = 15;
  v8 = 0;
  LOBYTE(v7) = 0;
  if ( *a4 )
    v5 = strlen(a4);
  else
    v5 = 0;
  sub_F97030(&v7, a4, v5);
  v10 = 0;
  sub_FA8420(v4, a2, a3, &v7);
  if ( v9 >= 0x10 )
    j__free(v7);
  result = v4;
  *v4 = &std::system_error::`vftable';
  return result;
}
// 103BEAC: using guessed type void *std::system_error::`vftable';

//----- (00FA87D0) --------------------------------------------------------
int __thiscall sub_FA87D0(_DWORD *this)
{
  _DWORD *v1; // edi
  void *v2; // esi
  void (__thiscall ***v3)(_DWORD, signed int); // eax
  int v4; // ecx
  int result; // eax

  v1 = this;
  *(this + *(*(this - 26) + 4) - 104) = &std::basic_stringstream<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>>::`vftable';
  *(v1 + *(*(v1 - 26) + 4) - 108) = *(*(v1 - 26) + 4) - 104;
  *(this - 20) = &std::basic_stringbuf<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>>::`vftable';
  sub_FA9420((this - 20));
  v2 = *(v1 - 7);
  *(v1 - 20) = &std::basic_streambuf<unsigned short,std::char_traits<unsigned short>>::`vftable';
  if ( v2 )
  {
    if ( *v2 )
    {
      v3 = (*(**v2 + 8))();
      if ( v3 )
        (**v3)(v3, 1);
    }
    j__free(v2);
  }
  *(v1 + *(*(v1 - 26) + 4) - 104) = &std::basic_iostream<unsigned short,std::char_traits<unsigned short>>::`vftable';
  *(v1 + *(*(v1 - 26) + 4) - 108) = *(*(v1 - 26) + 4) - 32;
  *(v1 + *(*(v1 - 22) + 4) - 88) = &std::basic_ostream<unsigned short,std::char_traits<unsigned short>>::`vftable';
  *(v1 + *(*(v1 - 22) + 4) - 92) = *(*(v1 - 22) + 4) - 8;
  *(v1 + *(*(v1 - 26) + 4) - 104) = &std::basic_istream<unsigned short,std::char_traits<unsigned short>>::`vftable';
  v4 = *(*(v1 - 26) + 4);
  result = v4 - 24;
  *(v1 + v4 - 108) = v4 - 24;
  return result;
}
// 103BF14: using guessed type void *std::basic_ostream<unsigned short,std::char_traits<unsigned short>>::`vftable';
// 103BF1C: using guessed type void *std::basic_streambuf<unsigned short,std::char_traits<unsigned short>>::`vftable';
// 103BF5C: using guessed type void *std::basic_istream<unsigned short,std::char_traits<unsigned short>>::`vftable';
// 103BF64: using guessed type void *std::basic_iostream<unsigned short,std::char_traits<unsigned short>>::`vftable';
// 103BF6C: using guessed type void *std::basic_stringbuf<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>>::`vftable';
// 103BFAC: using guessed type void *std::basic_stringstream<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>>::`vftable';

//----- (00FA8880) --------------------------------------------------------
int __thiscall sub_FA8880(std::_Lockit *this)
{
  void **v1; // esi

  v1 = this;
  std::_Locinfo::_Locinfo_dtor(this);
  if ( v1[11] )
    free(v1[11]);
  v1[11] = 0;
  if ( v1[9] )
    free(v1[9]);
  v1[9] = 0;
  if ( v1[7] )
    free(v1[7]);
  v1[7] = 0;
  if ( v1[5] )
    free(v1[5]);
  v1[5] = 0;
  if ( v1[3] )
    free(v1[3]);
  v1[3] = 0;
  if ( v1[1] )
    free(v1[1]);
  v1[1] = 0;
  return std::_Lockit::~_Lockit(v1);
}

//----- (00FA8990) --------------------------------------------------------
void __thiscall sub_FA8990(_DWORD *this)
{
  _DWORD *v1; // edx

  v1 = this + 8;
  *(v1 + *(*this + 4) - 32) = &std::basic_iostream<unsigned short,std::char_traits<unsigned short>>::`vftable';
  *(v1 + *(*this + 4) - 36) = *(*this + 4) - 32;
  *(v1 + *(this[4] + 4) - 16) = &std::basic_ostream<unsigned short,std::char_traits<unsigned short>>::`vftable';
  *(v1 + *(this[4] + 4) - 20) = *(this[4] + 4) - 8;
  *(v1 + *(*this + 4) - 32) = &std::basic_istream<unsigned short,std::char_traits<unsigned short>>::`vftable';
  *(v1 + *(*this + 4) - 36) = *(*this + 4) - 24;
  *v1 = &std::ios_base::`vftable';
  std::ios_base::_Ios_base_dtor((this + 8));
}
// 103BEC4: using guessed type void *std::ios_base::`vftable';
// 103BF14: using guessed type void *std::basic_ostream<unsigned short,std::char_traits<unsigned short>>::`vftable';
// 103BF5C: using guessed type void *std::basic_istream<unsigned short,std::char_traits<unsigned short>>::`vftable';
// 103BF64: using guessed type void *std::basic_iostream<unsigned short,std::char_traits<unsigned short>>::`vftable';

//----- (00FA8A1C) --------------------------------------------------------
void __fastcall sub_FA8A1C(unsigned int a1, int a2, int a3)
{
  bool v3; // cf

  v3 = a1 < *(a1 - 4);
  JUMPOUT(&loc_FA8A40);
}

//----- (00FA8A24) --------------------------------------------------------
void __fastcall sub_FA8A24(unsigned int a1, int a2, int a3)
{
  bool v3; // cf

  v3 = a1 < *(a1 - 4);
  JUMPOUT(&loc_FA8A70);
}

//----- (00FA8A2C) --------------------------------------------------------
char *__thiscall sub_FA8A2C(_DWORD *this, char a2)
{
  struct std::ios_base *v2; // ecx
  char *v3; // esi

  v2 = (this - *(this - 1));
  v3 = v2 - 8;
  *(v2 + *(*(v2 - 2) + 4) - 8) = &std::basic_ostream<unsigned short,std::char_traits<unsigned short>>::`vftable';
  *(v2 + *(*(v2 - 2) + 4) - 12) = *(*(v2 - 2) + 4) - 8;
  *v2 = &std::ios_base::`vftable';
  std::ios_base::_Ios_base_dtor(v2);
  if ( a2 & 1 )
    j__free(v3);
  return v3;
}
// 103BEC4: using guessed type void *std::ios_base::`vftable';
// 103BF14: using guessed type void *std::basic_ostream<unsigned short,std::char_traits<unsigned short>>::`vftable';

//----- (00FA8B10) --------------------------------------------------------
void *__thiscall sub_FA8B10(void *this, char a2)
{
  void *v2; // esi
  void *v3; // edi
  void (__thiscall ***v4)(_DWORD, signed int); // eax

  v2 = this;
  v3 = *(this + 13);
  *this = &std::basic_streambuf<unsigned short,std::char_traits<unsigned short>>::`vftable';
  if ( v3 )
  {
    if ( *v3 )
    {
      v4 = (*(**v3 + 8))();
      if ( v4 )
        (**v4)(v4, 1);
    }
    j__free(v3);
  }
  if ( a2 & 1 )
    j__free(v2);
  return v2;
}
// 103BF1C: using guessed type void *std::basic_streambuf<unsigned short,std::char_traits<unsigned short>>::`vftable';

//----- (00FA8B60) --------------------------------------------------------
_DWORD *__thiscall sub_FA8B60(void *this, char a2)
{
  _DWORD *v2; // esi
  void *v3; // edi
  void (__thiscall ***v4)(_DWORD, signed int); // eax

  v2 = this;
  *this = &std::basic_stringbuf<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>>::`vftable';
  sub_FA9420(this);
  v3 = v2[13];
  *v2 = &std::basic_streambuf<unsigned short,std::char_traits<unsigned short>>::`vftable';
  if ( v3 )
  {
    if ( *v3 )
    {
      v4 = (*(**v3 + 8))();
      if ( v4 )
        (**v4)(v4, 1);
    }
    j__free(v3);
  }
  if ( a2 & 1 )
    j__free(v2);
  return v2;
}
// 103BF1C: using guessed type void *std::basic_streambuf<unsigned short,std::char_traits<unsigned short>>::`vftable';
// 103BF6C: using guessed type void *std::basic_stringbuf<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>>::`vftable';

//----- (00FA8BC0) --------------------------------------------------------
_DWORD *__thiscall sub_FA8BC0(struct std::ios_base *this, char a2)
{
  char *v2; // edi
  struct std::ios_base *v3; // esi

  v2 = this - 104;
  v3 = this;
  sub_FA87D0(this);
  *v3 = &std::ios_base::`vftable';
  std::ios_base::_Ios_base_dtor(v3);
  if ( a2 & 1 )
    j__free(v2);
  return v2;
}
// 103BEC4: using guessed type void *std::ios_base::`vftable';

//----- (00FA8C00) --------------------------------------------------------
void **__thiscall sub_FA8C00(void *this, char a2)
{
  void **v2; // esi
  bool v3; // zf

  v2 = this;
  v3 = *(this + 4) == 0;
  *this = &std::ctype<unsigned short>::`vftable';
  if ( !v3 )
    free(*(this + 3));
  free(v2[5]);
  *v2 = &std::_Facet_base::`vftable';
  if ( a2 & 1 )
    j__free(v2);
  return v2;
}
// 103BE4C: using guessed type void *std::_Facet_base::`vftable';
// 103BE5C: using guessed type void *std::ctype<unsigned short>::`vftable';

//----- (00FA8C50) --------------------------------------------------------
void *__thiscall sub_FA8C50(void *this, char a2)
{
  void *v2; // esi

  v2 = this;
  *this = &std::_Facet_base::`vftable';
  if ( a2 & 1 )
    j__free(this);
  return v2;
}
// 103BE4C: using guessed type void *std::_Facet_base::`vftable';

//----- (00FA8C80) --------------------------------------------------------
struct std::ios_base *__thiscall sub_FA8C80(struct std::ios_base *this, char a2)
{
  struct std::ios_base *v2; // esi

  v2 = this;
  *this = &std::ios_base::`vftable';
  std::ios_base::_Ios_base_dtor(this);
  if ( a2 & 1 )
    j__free(v2);
  return v2;
}
// 103BEC4: using guessed type void *std::ios_base::`vftable';

//----- (00FA8CB0) --------------------------------------------------------
void *__thiscall sub_FA8CB0(void *this, char a2)
{
  void *v2; // esi

  v2 = this;
  sub_1009D91(this);
  if ( a2 & 1 )
    j__free(v2);
  return v2;
}

//----- (00FA8CE0) --------------------------------------------------------
void __cdecl sub_FA8CE0(int a1, int a2, wchar_t *a3)
{
  wchar_t *v3; // esi
  const wchar_t *v4; // ecx
  wchar_t v5; // ax
  unsigned int v6; // edi
  int v7; // eax
  char v8; // dl
  wchar_t *v9; // eax
  wchar_t *v10; // ecx
  wchar_t v11; // ax
  _WORD *v12; // eax
  const wchar_t *v13; // ecx
  const wchar_t *v14; // ecx
  wchar_t v15; // ax
  int v16; // [esp+10h] [ebp-E4h]
  _DWORD *v17; // [esp+14h] [ebp-E0h]
  __int64 v18; // [esp+1Ch] [ebp-D8h]
  _DWORD *v19; // [esp+24h] [ebp-D0h]
  void **v20; // [esp+2Ch] [ebp-C8h]
  int v21; // [esp+64h] [ebp-90h]
  int v22; // [esp+68h] [ebp-8Ch]
  int v23; // [esp+78h] [ebp-7Ch]
  void **v24; // [esp+7Ch] [ebp-78h]
  int v25; // [esp+C4h] [ebp-30h]
  char v26; // [esp+CBh] [ebp-29h]
  wchar_t *v27; // [esp+CCh] [ebp-28h]
  int v28; // [esp+DCh] [ebp-18h]
  unsigned int v29; // [esp+E0h] [ebp-14h]
  int v30; // [esp+F0h] [ebp-4h]

  v3 = a3;
  v25 = 0;
  if ( a1 )
  {
    v17 = &unk_103BFB0;
    v19 = dword_103BFB8;
    v30 = 0;
    v25 = 1;
    v24 = &std::basic_istream<unsigned short,std::char_traits<unsigned short>>::`vftable';
    v23 = 80;
    v18 = 0i64;
    sub_FA9E70(&v24, &v20, 0);
    *(&v19 + dword_103BFB8[1]) = &std::basic_ostream<unsigned short,std::char_traits<unsigned short>>::`vftable';
    *(&v18 + v19[1] + 4) = v19[1] - 8;
    *(&v17 + v17[1]) = &std::basic_iostream<unsigned short,std::char_traits<unsigned short>>::`vftable';
    *(&v16 + v17[1]) = v17[1] - 32;
    v30 = 5;
    *(&v17 + v17[1]) = &std::basic_stringstream<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>>::`vftable';
    *(&v16 + v17[1]) = v17[1] - 104;
    sub_FA8270(&v20);
    v20 = &std::basic_stringbuf<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>>::`vftable';
    v21 = 0;
    v22 = 0;
    v30 = 7;
    sub_FA9000(&v17, a1, &dword_105C5C8, 8);
    v26 = 1;
    v6 = 0;
    do
    {
      v7 = wcscmp(a2, (&off_105CB90)[v6]);
      if ( v7 )
        v7 = -(v7 < 0) | 1;
      if ( v7 )
      {
        v8 = v26;
      }
      else
      {
        sub_FA9000(&v17, a1, *(&off_105CB88 + v6 * 4), dword_105CB8C[v6]);
        v8 = 0;
        v26 = 0;
      }
      v6 += 3;
    }
    while ( v6 < 39 );
    if ( v8 )
    {
      if ( a1 )
        sub_FA7DF0(&v19, L"<Unknown>");
      else
        sub_FA7DF0(&v19, L"<None>");
      v9 = sub_FAA6E0(&v17, &v27);
      v10 = v9;
      if ( *(v9 + 5) >= 8u )
        v10 = *v9;
      do
      {
        v11 = *v10;
        ++v10;
        *v3 = v11;
        ++v3;
      }
      while ( v11 );
      if ( v29 >= 8 )
        j__free(v27);
      v29 = 7;
      v28 = 0;
      LOWORD(v27) = 0;
    }
    else
    {
      sub_FAA6E0(&v17, &v27);
      if ( v28 )
      {
        v12 = &v27;
        if ( v29 >= 8 )
          v12 = v27;
        v12[v28 - 3] = 0;
        v13 = &v27;
        if ( v29 >= 8 )
          v13 = v27;
        wcsncpy(a3, v13, v28 - 2);
      }
      else
      {
        v14 = L"<Unknown>";
        do
        {
          v15 = *v14;
          ++v14;
          *(v14 + a3 - L"<Unknown>" - 2) = v15;
        }
        while ( v15 );
      }
      if ( v29 >= 8 )
        j__free(v27);
    }
    v30 = -1;
    sub_FA87D0(&v24);
    v24 = &std::ios_base::`vftable';
    std::ios_base::_Ios_base_dtor(&v24);
  }
  else
  {
    v4 = L"<None>";
    do
    {
      v5 = *v4;
      ++v4;
      *(v4 + a3 - L"<None>" - 2) = v5;
    }
    while ( v5 );
  }
}
// 103BEC4: using guessed type void *std::ios_base::`vftable';
// 103BF14: using guessed type void *std::basic_ostream<unsigned short,std::char_traits<unsigned short>>::`vftable';
// 103BF5C: using guessed type void *std::basic_istream<unsigned short,std::char_traits<unsigned short>>::`vftable';
// 103BF64: using guessed type void *std::basic_iostream<unsigned short,std::char_traits<unsigned short>>::`vftable';
// 103BF6C: using guessed type void *std::basic_stringbuf<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>>::`vftable';
// 103BFAC: using guessed type void *std::basic_stringstream<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>>::`vftable';
// 103BFD8: using guessed type wchar_t aUnknown_0[10];
// 105C5C8: using guessed type int dword_105C5C8;
// 105CB88: using guessed type void *off_105CB88;
// 105CB8C: using guessed type int dword_105CB8C[];
// 105CB90: using guessed type wchar_t *off_105CB90;

//----- (00FA9000) --------------------------------------------------------
int __cdecl sub_FA9000(int a1, int a2, int a3, int a4)
{
  int v4; // esi
  int v5; // ebx
  int *v6; // eax
  int *v7; // eax
  int v8; // eax

  v4 = 0;
  if ( a4 > 0 )
  {
    while ( 1 )
    {
      v5 = a3 + 12 * v4;
      if ( (a2 & *v5) == *v5 )
      {
        if ( a1 )
          v6 = (a1 + 16);
        else
          v6 = 0;
        v7 = sub_FA7DF0(v6, *(v5 + 4));
        sub_FA7DF0(v7, L" | ");
        v8 = *(v5 + 8);
        if ( v8 < 0 )
          return a1;
        v4 += v8;
      }
      if ( ++v4 >= a4 )
        return a1;
    }
  }
  return a1;
}
// 103BFC0: using guessed type wchar_t asc_103BFC0[4];

//----- (00FA9070) --------------------------------------------------------
volatile signed __int32 *__thiscall sub_FA9070(volatile signed __int32 *this)
{
  volatile signed __int32 *result; // eax

  result = 0;
  if ( !_InterlockedExchangeAdd(this + 1, 0xFFFFFFFF) )
    result = this;
  return result;
}

//----- (00FA9090) --------------------------------------------------------
signed int __cdecl sub_FA9090(char **a1, int *a2)
{
  char v2; // bl
  char *v3; // edi
  int v4; // ecx
  char *v5; // eax
  struct std::_Locinfo *v6; // eax
  char *v7; // eax
  char v9; // [esp+10h] [ebp-44h]
  int v10; // [esp+44h] [ebp-10h]
  int v11; // [esp+50h] [ebp-4h]

  v2 = 0;
  v10 = 0;
  if ( a1 && !*a1 )
  {
    v3 = operator new(0x44u);
    v11 = 0;
    if ( v3 )
    {
      v4 = *a2;
      if ( *a2 )
      {
        v5 = *(v4 + 24);
        if ( !v5 )
          v5 = (v4 + 28);
      }
      else
      {
        v5 = gszStatusBarText;
      }
      v6 = sub_FA8360(&v9, v5);
      v2 = 1;
      v7 = sub_FA8300(v3, v6, 0);
    }
    else
    {
      v7 = 0;
    }
    *a1 = v7;
    if ( v2 & 1 )
      sub_FA8880(&v9);
  }
  return 2;
}

//----- (00FA9140) --------------------------------------------------------
__int64 __thiscall sub_FA9140(_DWORD **this)
{
  __int64 result; // rax

  if ( *this[7] )
    result = *this[11];
  else
    result = 0i64;
  return result;
}

//----- (00FA9160) --------------------------------------------------------
signed __int32 __thiscall sub_FA9160(volatile signed __int32 *this)
{
  return _InterlockedExchangeAdd(this + 1, 1u);
}

//----- (00FA9170) --------------------------------------------------------
struct std::locale::_Locimp *__thiscall sub_FA9170(_DWORD *this)
{
  _DWORD *v1; // esi
  struct std::locale::_Locimp *result; // eax
  struct std::locale::_Locimp *v3; // edi

  v1 = this;
  this[12] = 0;
  this[2] = 0;
  this[4] = 0;
  this[5] = 513;
  this[6] = 6;
  this[7] = 0;
  this[8] = 0;
  this[9] = 0;
  this[10] = 0;
  this[11] = 0;
  sub_FA9860(this, 0);
  result = operator new(4u);
  v3 = result;
  if ( result )
  {
    result = std::locale::_Init(1);
    *v3 = result;
    v1[12] = v3;
  }
  else
  {
    v1[12] = 0;
  }
  return result;
}

//----- (00FA91F0) --------------------------------------------------------
void *__cdecl sub_FA91F0(void *a1, char a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
  int v9; // eax
  int v10; // edx
  void *result; // eax
  void *v12; // [esp+Ch] [ebp-28h]
  unsigned int v13; // [esp+20h] [ebp-14h]
  int v14; // [esp+30h] [ebp-4h]

  v14 = 0;
  if ( a8 )
    sub_FA9550(&a4, &unk_103BEA4, 2u);
  v9 = sub_FA9F90(&a2, &v12);
  LOBYTE(v14) = 1;
  sub_FA9490(&a4, v9, 0, -1);
  if ( v13 >= 0x10 )
    j__free(v12);
  *(a1 + 5) = 15;
  *(a1 + 4) = 0;
  *a1 = 0;
  v10 = a9;
  if ( a9 >= 0x10 )
  {
    *a1 = a4;
  }
  else if ( a8 != -1 )
  {
    memmove(a1, &a4, a8 + 1);
    v10 = a9;
  }
  result = a1;
  *(a1 + 4) = a8;
  *(a1 + 5) = v10;
  return result;
}

//----- (00FA92D0) --------------------------------------------------------
int __thiscall sub_FA92D0(_DWORD *this)
{
  _DWORD *v1; // esi
  int v2; // eax
  int result; // eax
  int v4; // ecx
  int v5; // eax
  _DWORD *v6; // ecx
  char v7; // al
  int v8; // ecx
  int v9; // [esp+0h] [ebp-5Ch]
  void **v10; // [esp+10h] [ebp-4Ch]
  void **v11; // [esp+24h] [ebp-38h]
  void **v12; // [esp+38h] [ebp-24h]
  int *v13; // [esp+4Ch] [ebp-10h]
  int v14; // [esp+58h] [ebp-4h]

  v13 = &v9;
  v1 = this;
  v2 = *this;
  v14 = 0;
  result = *(v2 + 4);
  if ( !*(this + result + 12) )
  {
    if ( *(this + result + 20) & 2 )
    {
      result = (*(**(this + result + 56) + 52))();
      if ( result == -1 )
      {
        v4 = *(*v1 + 4);
        v5 = *(v1 + v4 + 12);
        v6 = (v1 + v4);
        v7 = v5 | 4;
        if ( !v6[14] )
          v7 |= 4u;
        result = v7 & 0x17;
        v6[3] = result;
        v8 = result & v6[4];
        if ( v8 )
        {
          if ( v8 & 4 )
          {
            sub_FA8630(&v12, 1, off_105AA40, "ios_base::badbit set");
            v12 = &std::ios_base::failure::`vftable';
            _CxxThrowException(&v12, &_TI5_AVfailure_ios_base_std__);
          }
          if ( v8 & 2 )
          {
            sub_FA8630(&v11, 1, off_105AA40, "ios_base::failbit set");
            v11 = &std::ios_base::failure::`vftable';
            _CxxThrowException(&v11, &_TI5_AVfailure_ios_base_std__);
          }
          sub_FA8630(&v10, 1, off_105AA40, "ios_base::eofbit set");
          v10 = &std::ios_base::failure::`vftable';
          _CxxThrowException(&v10, &_TI5_AVfailure_ios_base_std__);
        }
      }
    }
  }
  return result;
}
// 10081AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);
// 103BEB8: using guessed type void *std::ios_base::failure::`vftable';
// 1054548: using guessed type int _TI5_AVfailure_ios_base_std__;
// 105AA40: using guessed type int (__thiscall **off_105AA40[2])(void *, char);

//----- (00FA9400) --------------------------------------------------------
__int64 __thiscall sub_FA9400(_DWORD **this)
{
  __int64 result; // rax

  if ( *this[8] )
    result = *this[12];
  else
    result = 0i64;
  return result;
}

//----- (00FA9420) --------------------------------------------------------
_DWORD *__thiscall sub_FA9420(int this)
{
  int v1; // esi
  _DWORD *result; // eax

  v1 = this;
  if ( *(this + 60) & 1 )
    j__free(**(this + 12));
  **(v1 + 12) = 0;
  **(v1 + 28) = 0;
  **(v1 + 44) = 0;
  **(v1 + 16) = 0;
  **(v1 + 32) = 0;
  result = *(v1 + 48);
  *result = 0;
  *(v1 + 60) &= 0xFFFFFFFE;
  *(v1 + 56) = 0;
  return result;
}

//----- (00FA9490) --------------------------------------------------------
_DWORD *__thiscall sub_FA9490(void *this, int a2, int a3, int a4)
{
  _DWORD *v4; // edi
  _DWORD *v5; // esi
  unsigned int v6; // eax
  unsigned int v7; // ebx
  unsigned int v8; // eax
  int v9; // ecx
  _DWORD *v10; // ecx
  int v11; // ecx
  bool v12; // cf
  int v14; // [esp+14h] [ebp+8h]

  v4 = a2;
  v5 = this;
  v6 = *(a2 + 16);
  if ( v6 < a3 )
    std::_Xout_of_range("invalid string position");
  v7 = a4;
  v8 = v6 - a3;
  v9 = *(this + 4);
  v14 = v5[4];
  if ( v8 < a4 )
    v7 = v8;
  if ( -1 - v9 <= v7 )
    std::_Xlength_error("string too long");
  if ( v7 && sub_F96E00(v5, v9 + v7, 0) )
  {
    if ( v4[5] >= 0x10u )
      v4 = *v4;
    if ( v5[5] < 0x10u )
      v10 = v5;
    else
      v10 = *v5;
    if ( v7 )
      memmove_0(v10 + v5[4], v4 + a3, v7);
    v11 = v7 + v14;
    v12 = v5[5] < 0x10u;
    v5[4] = v7 + v14;
    if ( !v12 )
    {
      *(*v5 + v11) = 0;
      return v5;
    }
    *(v5 + v11) = 0;
  }
  return v5;
}

//----- (00FA9550) --------------------------------------------------------
_DWORD *__thiscall sub_FA9550(void *this, void *a2, size_t a3)
{
  void *v3; // edi
  _DWORD *v4; // esi
  unsigned int v5; // ecx
  unsigned int v6; // eax
  _DWORD *v7; // edx
  _DWORD *result; // eax
  char *v9; // ecx
  _DWORD *v10; // ecx
  size_t v11; // ecx
  bool v12; // cf
  char *v13; // [esp+10h] [ebp+8h]

  v3 = a2;
  v4 = this;
  if ( a2
    && ((v5 = *(this + 5), v5 < 0x10) ? (v6 = v4) : (v6 = *v4),
        a2 >= v6 && (v5 < 0x10 ? (v7 = v4) : (v7 = *v4), v7 + v4[4] > a2)) )
  {
    if ( v5 < 0x10 )
      result = sub_FA9490(v4, v4, a2 - v4, a3);
    else
      result = sub_FA9490(v4, v4, a2 - *v4, a3);
  }
  else
  {
    v9 = v4[4];
    v13 = v9;
    if ( -1 - v9 <= a3 )
      std::_Xlength_error("string too long");
    if ( a3 && sub_F96E00(v4, &v9[a3], 0) )
    {
      if ( v4[5] < 0x10u )
        v10 = v4;
      else
        v10 = *v4;
      if ( a3 )
        memmove_0(v10 + v4[4], v3, a3);
      v11 = &v13[a3];
      v12 = v4[5] < 0x10u;
      v4[4] = &v13[a3];
      if ( !v12 )
      {
        *(*v4 + v11) = 0;
        return v4;
      }
      *(v4 + v11) = 0;
    }
    result = v4;
  }
  return result;
}

//----- (00FA9640) --------------------------------------------------------
int *__thiscall sub_FA9640(int *this, int *a2, unsigned int a3, unsigned int a4)
{
  int *v4; // ebx
  int *v5; // esi
  unsigned int v6; // ecx
  unsigned int v7; // edi
  unsigned int v8; // edi
  unsigned int v9; // eax
  bool v10; // cf
  int v11; // edx
  int *result; // eax
  unsigned int v13; // eax
  int *v14; // edx

  v4 = a2;
  v5 = this;
  v6 = a3;
  v7 = a2[4];
  if ( v7 < a3 )
    std::_Xout_of_range("invalid string position");
  v8 = v7 - a3;
  if ( a4 < v8 )
    v8 = a4;
  if ( v5 != a2 )
  {
    if ( v8 > 0x7FFFFFFE )
      std::_Xlength_error("string too long");
    v13 = v5[5];
    if ( v13 >= v8 )
    {
      if ( !v8 )
      {
        v5[4] = 0;
        if ( v13 < 8 )
        {
          result = v5;
          *v5 = 0;
        }
        else
        {
          **v5 = 0;
          result = v5;
        }
        return result;
      }
    }
    else
    {
      sub_F7F9D0(v5, v8, v5[4]);
      v6 = a3;
      if ( !v8 )
        return v5;
    }
    if ( a2[5] >= 8 )
      v4 = *a2;
    if ( v5[5] < 8 )
      v14 = v5;
    else
      v14 = *v5;
    if ( v8 )
      memmove_0(v14, v4 + 2 * v6, 2 * v8);
    v10 = v5[5] < 8;
    v5[4] = v8;
    if ( !v10 )
    {
      *(*v5 + 2 * v8) = 0;
      return v5;
    }
    *(v5 + v8) = 0;
    return v5;
  }
  v9 = v8 + a3;
  if ( v5[4] < v8 + a3 )
    std::_Xout_of_range("invalid string position");
  v10 = v5[5] < 8;
  v5[4] = v9;
  if ( v10 )
    v11 = v5;
  else
    v11 = *v5;
  *(v11 + 2 * v9) = 0;
  sub_FA9C60(v5, 0, a3);
  return v5;
}

//----- (00FA9760) --------------------------------------------------------
int *__thiscall sub_FA9760(int *this, void *a2, int a3)
{
  int *v3; // esi
  unsigned int v4; // ecx
  unsigned int v5; // eax
  int v6; // edx
  int v7; // eax
  int *result; // eax
  unsigned int v9; // eax
  int *v10; // ecx
  bool v11; // cf

  v3 = this;
  if ( !a2
    || ((v4 = this[5], v4 < 8) ? (v5 = v3) : (v5 = *v3),
        a2 < v5 || (v4 < 8 ? (v6 = v3) : (v6 = *v3), v6 + 2 * v3[4] <= a2)) )
  {
    if ( a3 > 0x7FFFFFFE )
      std::_Xlength_error("string too long");
    v9 = v3[5];
    if ( v9 >= a3 )
    {
      if ( !a3 )
      {
        v3[4] = 0;
        if ( v9 < 8 )
        {
          result = v3;
          *v3 = 0;
        }
        else
        {
          **v3 = 0;
          result = v3;
        }
        return result;
      }
    }
    else
    {
      sub_F7F9D0(v3, a3, v3[4]);
      if ( !a3 )
        return v3;
    }
    if ( v3[5] < 8 )
      v10 = v3;
    else
      v10 = *v3;
    if ( a3 )
      memmove_0(v10, a2, 2 * a3);
    v11 = v3[5] < 8;
    v3[4] = a3;
    if ( !v11 )
    {
      *(*v3 + 2 * a3) = 0;
      return v3;
    }
    *(v3 + a3) = 0;
    return v3;
  }
  if ( v4 < 8 )
    v7 = v3;
  else
    v7 = *v3;
  return sub_FA9640(v3, v3, (a2 - v7) >> 1, a3);
}

//----- (00FA9860) --------------------------------------------------------
int __thiscall sub_FA9860(_DWORD *this, char a2)
{
  int result; // eax
  int v3; // ecx
  void **v4; // [esp+0h] [ebp-14h]

  result = a2 & 0x17;
  this[3] = result;
  v3 = result & this[4];
  if ( v3 )
  {
    if ( !(v3 & 4) )
    {
      if ( v3 & 2 )
        sub_FA8630(&v4, 1, off_105AA40, "ios_base::failbit set");
      else
        sub_FA8630(&v4, 1, off_105AA40, "ios_base::eofbit set");
      v4 = &std::ios_base::failure::`vftable';
      _CxxThrowException(&v4, &_TI5_AVfailure_ios_base_std__);
    }
    sub_FA8630(&v4, 1, off_105AA40, "ios_base::badbit set");
    v4 = &std::ios_base::failure::`vftable';
    _CxxThrowException(&v4, &_TI5_AVfailure_ios_base_std__);
  }
  return result;
}
// 10081AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);
// 103BEB8: using guessed type void *std::ios_base::failure::`vftable';
// 1054548: using guessed type int _TI5_AVfailure_ios_base_std__;
// 105AA40: using guessed type int (__thiscall **off_105AA40[2])(void *, char);

//----- (00FA9900) --------------------------------------------------------
BOOL __stdcall sub_FA9900(__int16 a1, WCHAR SrcStr)
{
  return (_Getwctype(SrcStr) & a1) != 0;
}

//----- (00FA9930) --------------------------------------------------------
char __thiscall sub_FA9930(const _Cvtvec *this, wchar_t a2, int a3)
{
  int v3; // eax
  char v4; // dl
  mbstate_t v6; // [esp+0h] [ebp-10h]
  char v7; // [esp+4h] [ebp-Ch]

  v6 = 0;
  v3 = _Wcrtomb(&v7, a2, &v6, this + 3);
  v4 = v7;
  if ( v3 != 1 )
    v4 = a3;
  return v4;
}

//----- (00FA9980) --------------------------------------------------------
wchar_t *__thiscall sub_FA9980(const _Cvtvec *this, wchar_t *a2, unsigned int a3, char a4, int a5)
{
  int v5; // ebx
  wchar_t *v6; // esi
  unsigned int v7; // edi
  const _Cvtvec *v8; // ecx
  wchar_t v9; // ax
  int v10; // eax
  char v11; // dl
  int v12; // eax
  const _Cvtvec *v14; // [esp+Ch] [ebp-18h]
  mbstate_t v15; // [esp+10h] [ebp-14h]
  int v16; // [esp+14h] [ebp-10h]
  char v17; // [esp+18h] [ebp-Ch]

  v5 = a5;
  v6 = a2;
  v16 = 0;
  v7 = (a3 - a2 + 1) >> 1;
  if ( a2 > a3 )
    v7 = 0;
  if ( v7 )
  {
    v8 = this + 3;
    v14 = v8;
    do
    {
      v9 = *v6;
      v15 = 0;
      v10 = _Wcrtomb(&v17, v9, &v15, v8);
      ++v5;
      v11 = v17;
      if ( v10 != 1 )
        v11 = a4;
      v8 = v14;
      v12 = v16 + 1;
      *(v5 - 1) = v11;
      ++v6;
      v16 = v12;
    }
    while ( v12 != v7 );
  }
  return v6;
}

//----- (00FA9A20) --------------------------------------------------------
unsigned __int16 *__thiscall sub_FA9A20(void *this, int a2, unsigned __int16 *a3, unsigned __int16 *a4)
{
  unsigned __int16 *v4; // esi
  void *i; // ebx

  v4 = a3;
  for ( i = this; v4 != a4; ++v4 )
  {
    if ( (*(*i + 16))(i, a2, *v4) )
      break;
  }
  return v4;
}

//----- (00FA9A60) --------------------------------------------------------
unsigned __int16 *__thiscall sub_FA9A60(void *this, int a2, unsigned __int16 *a3, unsigned __int16 *a4)
{
  unsigned __int16 *v4; // esi
  void *i; // ebx

  v4 = a3;
  for ( i = this; v4 != a4; ++v4 )
  {
    if ( !(*(*i + 16))(i, a2, *v4) )
      break;
  }
  return v4;
}

//----- (00FA9AA0) --------------------------------------------------------
int __thiscall sub_FA9AA0(void *this, wchar_t Src)
{
  return _Towlower(Src, this + 8);
}

//----- (00FA9AC0) --------------------------------------------------------
wchar_t *__thiscall sub_FA9AC0(char *this, wchar_t *a2, unsigned int a3)
{
  wchar_t *v3; // esi
  unsigned int v4; // ebx
  int v5; // edi
  char *v6; // eax
  char *v8; // [esp+18h] [ebp+Ch]

  v3 = a2;
  v4 = (a3 - a2 + 1) >> 1;
  v5 = 0;
  if ( a2 > a3 )
    v4 = 0;
  if ( v4 )
  {
    v6 = this + 8;
    v8 = this + 8;
    do
    {
      *v3 = _Towlower(*v3, v6);
      ++v5;
      v6 = v8;
      ++v3;
    }
    while ( v5 != v4 );
  }
  return v3;
}

//----- (00FA9B10) --------------------------------------------------------
int __thiscall sub_FA9B10(void *this, wchar_t Src)
{
  return _Towupper(Src, this + 8);
}

//----- (00FA9B30) --------------------------------------------------------
wchar_t *__thiscall sub_FA9B30(char *this, wchar_t *a2, unsigned int a3)
{
  wchar_t *v3; // esi
  unsigned int v4; // ebx
  int v5; // edi
  char *v6; // eax
  char *v8; // [esp+18h] [ebp+Ch]

  v3 = a2;
  v4 = (a3 - a2 + 1) >> 1;
  v5 = 0;
  if ( a2 > a3 )
    v4 = 0;
  if ( v4 )
  {
    v6 = this + 8;
    v8 = this + 8;
    do
    {
      *v3 = _Towupper(*v3, v6);
      ++v5;
      v6 = v8;
      ++v3;
    }
    while ( v5 != v4 );
  }
  return v3;
}

//----- (00FA9B80) --------------------------------------------------------
wchar_t __thiscall sub_FA9B80(const _Cvtvec *this, char a2)
{
  int v2; // eax
  wchar_t v3; // cx
  mbstate_t v5; // [esp+0h] [ebp-8h]
  wchar_t v6; // [esp+4h] [ebp-4h]

  v5 = 0;
  v2 = _Mbrtowc(&v6, &a2, 1u, &v5, this + 3);
  v3 = v6;
  if ( v2 < 0 )
    v3 = -1;
  return v3;
}

//----- (00FA9BD0) --------------------------------------------------------
char *__thiscall sub_FA9BD0(const _Cvtvec *this, wchar_t a2, char a3, mbstate_t a4)
{
  char *v4; // esi
  int v5; // edi
  const _Cvtvec *v6; // ecx
  mbstate_t v7; // ebx
  int v8; // eax
  wchar_t v9; // cx
  const _Cvtvec *v11; // [esp+8h] [ebp-8h]
  int v12; // [esp+Ch] [ebp-4h]

  v4 = a2;
  v5 = a3 - a2;
  v12 = 0;
  if ( a2 > a3 )
    v5 = 0;
  if ( v5 )
  {
    v6 = this + 3;
    v7 = a4;
    v11 = v6;
    do
    {
      a3 = *v4;
      a4 = 0;
      v8 = _Mbrtowc(&a2, &a3, 1u, &a4, v6);
      v9 = a2;
      v7 += 2;
      if ( v8 < 0 )
        v9 = -1;
      *(v7 - 2) = v9;
      v6 = v11;
      ++v4;
      ++v12;
    }
    while ( v12 != v5 );
  }
  return v4;
}

//----- (00FA9C60) --------------------------------------------------------
_DWORD *__thiscall sub_FA9C60(_DWORD *this, unsigned int a2, unsigned int a3)
{
  _DWORD *v3; // esi
  unsigned int v4; // edi
  bool v5; // cf
  _DWORD *result; // eax
  _DWORD *v7; // eax
  unsigned int v8; // edi

  v3 = this;
  v4 = this[4];
  if ( v4 < a2 )
    std::_Xout_of_range("invalid string position");
  if ( v4 - a2 > a3 )
  {
    if ( a3 )
    {
      if ( this[5] < 8u )
        v7 = this;
      else
        v7 = *this;
      v8 = v4 - a3;
      if ( v8 != a2 )
        memmove(v7 + 2 * a2, v7 + 2 * a2 + 2 * a3, 2 * (v8 - a2));
      v5 = v3[5] < 8u;
      v3[4] = v8;
      if ( !v5 )
      {
        *(*v3 + 2 * v8) = 0;
        return v3;
      }
      *(v3 + v8) = 0;
    }
    result = v3;
  }
  else
  {
    v5 = this[5] < 8u;
    this[4] = a2;
    if ( v5 )
    {
      result = this;
      *(this + a2) = 0;
    }
    else
    {
      *(*this + 2 * a2) = 0;
      result = this;
    }
  }
  return result;
}

//----- (00FA9D10) --------------------------------------------------------
char *__thiscall sub_FA9D10(char *this)
{
  char *v1; // esi
  int v2; // ecx
  int v3; // eax
  char *v4; // ecx
  char v5; // al
  int v6; // eax
  int v7; // ecx
  int v8; // ecx
  void **v10; // [esp+8h] [ebp-28h]
  _DWORD *v11; // [esp+1Ch] [ebp-14h]
  char v12; // [esp+20h] [ebp-10h]
  int v13; // [esp+2Ch] [ebp-4h]

  v1 = this;
  if ( *&this[*(*this + 4) + 56] )
  {
    sub_FA8570(&v11, this);
    v13 = 0;
    if ( v12 && (*(**&v1[*(*v1 + 4) + 56] + 52))() == -1 )
    {
      v2 = *(*v1 + 4);
      v3 = *&v1[v2 + 12];
      v4 = &v1[v2];
      v5 = v3 | 4;
      if ( !*(v4 + 14) )
        v5 |= 4u;
      v6 = v5 & 0x17;
      *(v4 + 3) = v6;
      v7 = v6 & *(v4 + 4);
      if ( v7 )
      {
        if ( v7 & 4 )
        {
          sub_FA8630(&v10, 1, off_105AA40, "ios_base::badbit set");
          v10 = &std::ios_base::failure::`vftable';
          _CxxThrowException(&v10, &_TI5_AVfailure_ios_base_std__);
        }
        if ( v7 & 2 )
          sub_FA8630(&v10, 1, off_105AA40, "ios_base::failbit set");
        else
          sub_FA8630(&v10, 1, off_105AA40, "ios_base::eofbit set");
        v10 = &std::ios_base::failure::`vftable';
        _CxxThrowException(&v10, &_TI5_AVfailure_ios_base_std__);
      }
    }
    v13 = -1;
    if ( !__uncaught_exception() )
      sub_FA92D0(v11);
    v8 = *(v11 + *(*v11 + 4) + 56);
    if ( v8 )
      (*(*v8 + 8))();
  }
  return v1;
}
// 10081AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);
// 103BEB8: using guessed type void *std::ios_base::failure::`vftable';
// 1054548: using guessed type int _TI5_AVfailure_ios_base_std__;
// 105AA40: using guessed type int (__thiscall **off_105AA40[2])(void *, char);

//----- (00FA9E40) --------------------------------------------------------
int *__thiscall sub_FA9E40(_DWORD *this, int *a2)
{
  int *v2; // eax
  int v3; // ecx

  v2 = this[12];
  v3 = *v2;
  *a2 = *v2;
  (*(*v3 + 4))();
  return a2;
}

//----- (00FA9E70) --------------------------------------------------------
void __thiscall sub_FA9E70(struct std::ios_base *this, int a2, char a3)
{
  struct std::ios_base *v3; // esi
  int *v4; // eax
  struct std::_Facet_base *v5; // edi
  void (__thiscall ***v6)(_DWORD, signed int); // eax
  __int16 v7; // ax
  bool v8; // zf
  int v9; // ecx
  int v10; // eax
  int v11; // ecx
  void **v12; // [esp+Ch] [ebp-34h]
  void **v13; // [esp+20h] [ebp-20h]
  int v14; // [esp+3Ch] [ebp-4h]

  v3 = this;
  sub_FA9170(this);
  *(v3 + 14) = a2;
  *(v3 + 15) = 0;
  v4 = sub_FA9E40(v3, &a2);
  v14 = -1;
  v5 = sub_FA8150(v4);
  if ( a2 )
  {
    v6 = (*(*a2 + 8))();
    if ( v6 )
      (**v6)(v6, 1);
  }
  v7 = (*(*v5 + 48))(v5, 32);
  v8 = *(v3 + 14) == 0;
  *(v3 + 32) = v7;
  if ( v8 )
  {
    v9 = *(v3 + 4);
    v10 = (*(v3 + 3) | 4) & 0x17;
    *(v3 + 3) = v10;
    v11 = v10 & v9;
    if ( v11 )
    {
      if ( v11 & 4 )
      {
        sub_FA8630(&v13, 1, off_105AA40, "ios_base::badbit set");
      }
      else
      {
        if ( !(v11 & 2) )
        {
          sub_FA8630(&v12, 1, off_105AA40, "ios_base::eofbit set");
          v12 = &std::ios_base::failure::`vftable';
          _CxxThrowException(&v12, &_TI5_AVfailure_ios_base_std__);
        }
        sub_FA8630(&v13, 1, off_105AA40, "ios_base::failbit set");
      }
      v13 = &std::ios_base::failure::`vftable';
      _CxxThrowException(&v13, &_TI5_AVfailure_ios_base_std__);
    }
  }
  if ( a3 )
    std::ios_base::_Addstd(v3);
}
// 10081AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);
// 103BEB8: using guessed type void *std::ios_base::failure::`vftable';
// 1054548: using guessed type int _TI5_AVfailure_ios_base_std__;
// 105AA40: using guessed type int (__thiscall **off_105AA40[2])(void *, char);

//----- (00FA9F90) --------------------------------------------------------
int __thiscall sub_FA9F90(_DWORD **this, int a2)
{
  (*(*this[1] + 8))(a2, *this, 0);
  return a2;
}

//----- (00FA9FC0) --------------------------------------------------------
__int16 __thiscall sub_FA9FC0(_DWORD *this, __int16 a2)
{
  _DWORD *v2; // esi
  int v3; // eax
  __int16 result; // ax
  unsigned int *v5; // edi
  unsigned int v6; // ecx
  unsigned int v7; // edx
  int v8; // eax
  unsigned int v9; // ecx
  _DWORD *v10; // edx
  __int16 **v11; // edx
  __int16 *v12; // esi
  unsigned int v13; // edi
  unsigned int v14; // ecx
  void *v15; // eax
  const void **v16; // ecx
  signed int v17; // ebx
  signed int *v18; // eax
  void *v19; // edi
  bool v20; // zf
  signed int *v21; // eax
  _DWORD *v22; // ecx
  int v23; // edx
  int v24; // ecx
  int v25; // edx
  _DWORD *v26; // eax
  __int16 **v27; // ecx
  __int16 *v28; // edx
  int v29; // [esp+4h] [ebp-8h]
  void *v30; // [esp+8h] [ebp-4h]

  v2 = this;
  v3 = this[15];
  if ( v3 & 2 )
    return -1;
  if ( a2 == -1 )
    return 0;
  if ( v3 & 8 )
  {
    v5 = this[8];
    v6 = *v5;
    if ( *v5 )
    {
      v7 = v2[14];
      if ( v6 < v7 )
      {
        v8 = *v2[12];
        *v5 = v7;
        *v2[12] = (v6 + 2 * v8 - v7) >> 1;
      }
    }
  }
  v9 = *v2[8];
  if ( !v9 )
    goto LABEL_35;
  v10 = v2[12];
  if ( v9 < v9 + 2 * *v10 )
  {
    result = a2;
    --*v10;
    v11 = v2[8];
    v12 = *v11;
    ++*v11;
    *v12 = a2;
    return result;
  }
  if ( v9 )
    v13 = (v9 + 2 * *v2[12] - *v2[3]) >> 1;
  else
LABEL_35:
    v13 = 0;
  v14 = v13 >> 1;
  if ( v13 >> 1 >= 0x20 )
  {
    if ( !v14 )
      return -1;
  }
  else
  {
    v14 = 32;
  }
  do
  {
    if ( 0x7FFFFFFF - v14 >= v13 )
      break;
    v14 >>= 1;
  }
  while ( v14 );
  if ( !v14 )
    return -1;
  v29 = v14 + v13;
  v15 = sub_F7FFE0(v14 + v13);
  v16 = v2[3];
  v17 = v15;
  v30 = *v16;
  if ( v13 && (memmove_0(v15, *v16, 2 * v13), v13) )
  {
    v22 = v2[4];
    v19 = v30;
    v2[14] = v17 + 2 * ((v2[14] - v30) >> 1);
    v23 = v17 + 2 * ((*v2[8] - v30) >> 1);
    *v22 = v17 + 2 * ((*v22 - v30) >> 1);
    *v2[8] = v23;
    *v2[12] = (v17 + 2 * v29 - v23) >> 1;
    if ( v2[15] & 4 )
    {
      *v2[3] = v17;
      *v2[7] = 0;
      *v2[11] = v17 >> 1;
    }
    else
    {
      v24 = v17 + 2 * ((*v2[7] - v30) >> 1);
      v25 = (*v2[8] - v24 + 2) >> 1;
      *v2[3] = v17;
      *v2[7] = v24;
      *v2[11] = v25;
    }
  }
  else
  {
    v18 = v2[4];
    v19 = v30;
    v2[14] = v17;
    *v18 = v17;
    *v2[8] = v17;
    *v2[12] = 2 * v29 >> 1;
    v20 = (v2[15] & 4) == 0;
    *v2[3] = v17;
    v21 = v2[7];
    if ( v20 )
    {
      *v21 = v17;
      *v2[11] = 1;
    }
    else
    {
      *v21 = 0;
      *v2[11] = v17 >> 1;
    }
  }
  if ( v2[15] & 1 )
    j__free(v19);
  v26 = v2[12];
  v2[15] |= 1u;
  --*v26;
  v27 = v2[8];
  v28 = *v27;
  ++*v27;
  result = a2;
  *v28 = a2;
  return result;
}

//----- (00FAA1E0) --------------------------------------------------------
signed int __stdcall sub_FAA1E0(int a1)
{
  return 0xFFFF;
}

//----- (00FAA1F0) --------------------------------------------------------
signed __int16 __thiscall sub_FAA1F0(int this, __int16 a2)
{
  unsigned int v2; // esi

  v2 = **(this + 28);
  if ( !v2 || v2 <= **(this + 12) || -1 != a2 && a2 != *(v2 - 2) && *(this + 60) & 2 )
    return -1;
  ++**(this + 44);
  **(this + 28) -= 2;
  if ( -1 == a2 )
    return 0;
  ***(this + 28) = a2;
  return a2;
}

//----- (00FAA260) --------------------------------------------------------
_DWORD *__stdcall sub_FAA260(_DWORD *a1, int a2, int a3, int a4, int a5)
{
  _DWORD *result; // eax

  result = a1;
  *a1 = -1;
  a1[1] = -1;
  a1[2] = 0;
  a1[3] = 0;
  a1[4] = 0;
  return result;
}

//----- (00FAA290) --------------------------------------------------------
signed int *__thiscall sub_FAA290(int this, signed int *a2, __int64 a3, int a4, char a5)
{
  int v5; // ebx
  unsigned int *v6; // edx
  unsigned int v7; // eax
  int v8; // esi
  signed int v9; // edi
  signed int v10; // esi
  int v11; // ecx
  _DWORD *v12; // eax
  int v13; // edx
  int v14; // ecx
  unsigned int v15; // edx
  int v16; // ecx
  signed int *result; // eax
  int v18; // [esp+Ch] [ebp-4h]
  int v19; // [esp+24h] [ebp+14h]
  int v20; // [esp+28h] [ebp+18h]

  v5 = this;
  v6 = *(this + 32);
  v7 = *v6;
  if ( *v6 && *(this + 56) < v7 )
    *(this + 56) = v7;
  if ( !(a5 & 1) || (v8 = **(this + 28), (v18 = v8) == 0) )
  {
    if ( a5 & 2 && (v15 = *v6) != 0 )
    {
      if ( a4 == 2 )
      {
        v9 = (((*(this + 56) - **(this + 12)) >> 1) + a3) >> 32;
        v10 = ((*(this + 56) - **(this + 12)) >> 1) + a3;
      }
      else if ( a4 == 1 )
      {
        v9 = (((v15 - **(this + 12)) >> 1) + a3) >> 32;
        v10 = ((v15 - **(this + 12)) >> 1) + a3;
      }
      else if ( a4 )
      {
        v10 = -1;
        v9 = -1;
      }
      else
      {
        v9 = HIDWORD(a3);
        v10 = a3;
      }
      if ( v9 >= 0 )
      {
        v16 = **(this + 12);
        if ( __PAIR__(v9, v10) <= (*(v5 + 56) - v16) >> 1 )
        {
          v20 = v10 + ((v16 - v15) >> 1);
          **(v5 + 48) -= v20;
          **(v5 + 32) += 2 * v20;
          goto LABEL_33;
        }
      }
    }
    else
    {
      v9 = HIDWORD(a3);
      v10 = a3;
      if ( !a3 )
        goto LABEL_33;
    }
LABEL_32:
    v10 = -1;
    v9 = -1;
    goto LABEL_33;
  }
  if ( a4 != 2 )
  {
    if ( a4 == 1 )
    {
      if ( !(a5 & 2) )
      {
        v9 = (((v8 - **(this + 12)) >> 1) + a3) >> 32;
        v10 = ((v8 - **(this + 12)) >> 1) + a3;
        goto LABEL_14;
      }
    }
    else if ( !a4 )
    {
      v9 = HIDWORD(a3);
      v10 = a3;
      goto LABEL_14;
    }
    v10 = -1;
    v9 = -1;
    goto LABEL_14;
  }
  v9 = (((*(this + 56) - **(this + 12)) >> 1) + a3) >> 32;
  v10 = ((*(this + 56) - **(this + 12)) >> 1) + a3;
LABEL_14:
  if ( v9 < 0 )
    goto LABEL_32;
  v11 = **(this + 12);
  if ( __PAIR__(v9, v10) > (*(v5 + 56) - v11) >> 1 )
    goto LABEL_32;
  v19 = v10 + ((v11 - v18) >> 1);
  **(v5 + 44) -= v19;
  **(v5 + 28) += 2 * v19;
  if ( a5 & 2 )
  {
    v12 = *(v5 + 32);
    if ( *v12 )
    {
      v13 = **(v5 + 28);
      v14 = (*v12 + 2 * **(v5 + 48) - v13) >> 1;
      **(v5 + 32) = v13;
      **(v5 + 48) = v14;
    }
  }
LABEL_33:
  result = a2;
  a2[1] = v9;
  *a2 = v10;
  a2[2] = 0;
  a2[3] = 0;
  a2[4] = 0;
  return result;
}

//----- (00FAA480) --------------------------------------------------------
_DWORD *__stdcall sub_FAA480(_DWORD *a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  _DWORD *result; // eax

  result = a1;
  *a1 = -1;
  a1[1] = -1;
  a1[2] = 0;
  a1[3] = 0;
  a1[4] = 0;
  return result;
}

//----- (00FAA4B0) --------------------------------------------------------
signed int *__thiscall sub_FAA4B0(int this, signed int *a2, __int64 a3, __int64 a4, int a5, int a6, char a7)
{
  signed int v7; // ebx
  signed int v8; // esi
  int v9; // edi
  unsigned int *v10; // edx
  unsigned int v11; // eax
  int v12; // ecx
  int v13; // ST0C_4
  _DWORD *v14; // eax
  int v15; // edx
  int v16; // ecx
  int v17; // ecx
  signed int *result; // eax
  int v19; // [esp+Ch] [ebp-4h]
  unsigned int v20; // [esp+34h] [ebp+24h]
  int v21; // [esp+34h] [ebp+24h]

  v7 = (a3 + a4) >> 32;
  v8 = a3 + a4;
  v9 = this;
  v10 = *(this + 32);
  v11 = *v10;
  if ( *v10 && *(this + 56) < v11 )
    *(this + 56) = v11;
  if ( v8 != -1 || v7 != -1 )
  {
    if ( a7 & 1 && (v19 = **(this + 28)) != 0 )
    {
      if ( v7 >= 0 )
      {
        v12 = **(this + 12);
        if ( __PAIR__(v7, v8) <= (*(v9 + 56) - v12) >> 1 )
        {
          v13 = v8 + ((v12 - v19) >> 1);
          **(v9 + 44) -= v13;
          **(v9 + 28) += 2 * v13;
          if ( a7 & 2 )
          {
            v14 = *(v9 + 32);
            if ( *v14 )
            {
              v15 = **(v9 + 28);
              v16 = (*v14 + 2 * **(v9 + 48) - v15) >> 1;
              **(v9 + 32) = v15;
              **(v9 + 48) = v16;
            }
          }
          goto LABEL_21;
        }
      }
    }
    else
    {
      if ( !(a7 & 2) || (v20 = *v10) == 0 )
      {
        v7 = -1;
        goto LABEL_20;
      }
      if ( v7 >= 0 )
      {
        v17 = **(this + 12);
        if ( __PAIR__(v7, v8) <= (*(v9 + 56) - v17) >> 1 )
        {
          v21 = v8 + ((v17 - v20) >> 1);
          **(v9 + 48) -= v21;
          **(v9 + 32) += 2 * v21;
          goto LABEL_21;
        }
      }
    }
    v7 = -1;
LABEL_20:
    v8 = -1;
  }
LABEL_21:
  result = a2;
  *a2 = v8;
  a2[1] = v7;
  a2[2] = 0;
  a2[3] = 0;
  a2[4] = 0;
  return result;
}

//----- (00FAA600) --------------------------------------------------------
void *__thiscall sub_FAA600(void *this, int a2, int a3, int a4)
{
  return this;
}

//----- (00FAA610) --------------------------------------------------------
__int64 sub_FAA610()
{
  return 0i64;
}

//----- (00FAA620) --------------------------------------------------------
void *__thiscall sub_FAA620(_DWORD *this, void *a2)
{
  _DWORD *v2; // edx
  int v3; // ecx
  unsigned int v4; // eax
  unsigned int v5; // ecx
  void **v6; // eax
  void *v7; // eax
  _DWORD *v8; // eax
  void *v10; // [esp+8h] [ebp-1Ch]
  int v11; // [esp+18h] [ebp-Ch]
  unsigned int v12; // [esp+1Ch] [ebp-8h]

  v2 = this;
  v3 = this[15];
  if ( !(v3 & 2) )
  {
    v4 = *v2[8];
    if ( v4 )
    {
      v5 = v2[14];
      if ( v5 < v4 )
        v5 = *v2[8];
      v6 = v2[4];
      goto LABEL_6;
    }
  }
  if ( !(v3 & 4) )
  {
    v8 = v2[7];
    if ( *v8 )
    {
      v5 = *v8 + 2 * *v2[11];
      v6 = v2[3];
LABEL_6:
      v7 = *v6;
      v12 = 7;
      v11 = 0;
      LOWORD(v10) = 0;
      sub_FA9760(&v10, v7, (v5 - v7) >> 1);
      goto LABEL_11;
    }
  }
  v12 = 7;
  v11 = 0;
  LOWORD(v10) = 0;
LABEL_11:
  sub_F73530(a2, &v10);
  if ( v12 >= 8 )
    j__free(v10);
  return a2;
}

//----- (00FAA6E0) --------------------------------------------------------
void *__thiscall sub_FAA6E0(_DWORD *this, void *a2)
{
  sub_FAA620(this + 6, a2);
  return a2;
}

//----- (00FAA700) --------------------------------------------------------
signed int __thiscall sub_FAA700(_DWORD **this)
{
  _DWORD **v1; // esi
  unsigned __int16 **v3; // ecx
  unsigned __int16 *v4; // edx

  v1 = this;
  if ( ((*this)[6])() == -1 )
    return 0xFFFF;
  --*v1[11];
  v3 = v1[7];
  v4 = *v3;
  ++*v3;
  return *v4;
}

//----- (00FAA730) --------------------------------------------------------
signed int sub_FAA730()
{
  return 0xFFFF;
}

//----- (00FAA740) --------------------------------------------------------
signed __int16 __thiscall sub_FAA740(int this)
{
  unsigned int *v1; // edi
  unsigned int v2; // esi
  int *v4; // ebx
  unsigned int v5; // eax

  v1 = *(this + 28);
  v2 = *v1;
  if ( !*v1 )
    return -1;
  v4 = *(this + 44);
  if ( v2 < v2 + 2 * *v4 )
    return *v2;
  if ( *(this + 60) & 4 )
    return -1;
  v5 = **(this + 32);
  if ( !v5 || v5 <= v2 && *(this + 56) <= v2 )
    return -1;
  if ( *(this + 56) < v5 )
    *(this + 56) = v5;
  *v4 = (*(this + 56) - *v1) >> 1;
  return ***(this + 28);
}

//----- (00FAA7B0) --------------------------------------------------------
unsigned int __thiscall sub_FAA7B0(_DWORD **this, void *a2, int a3, int a4)
{
  int v4; // ebx
  _DWORD **v5; // edx
  int v6; // edi
  __int64 v7; // rax
  unsigned int v8; // esi
  bool v9; // cf
  __int16 v10; // ax
  int v12; // [esp+8h] [ebp-Ch]
  _DWORD **v13; // [esp+Ch] [ebp-8h]
  unsigned int v14; // [esp+10h] [ebp-4h]
  int v15; // [esp+24h] [ebp+10h]

  v4 = a4;
  v5 = this;
  v13 = this;
  if ( a4 < 0 )
    return 0;
  v6 = a3;
  if ( a4 <= 0 && !a3 )
    return 0;
  v15 = 0;
  v14 = 0;
  do
  {
    v7 = sub_FA9140(v5);
    v12 = HIDWORD(v7);
    v8 = v7;
    if ( v7 >= 0 && (SHIDWORD(v7) > 0 || v7) )
    {
      if ( __PAIR__(v4, v6) < v7 )
      {
        v8 = v6;
        v12 = v4;
      }
      if ( v8 )
        memmove_0(a2, *v13[7], 2 * v8);
      a2 = a2 + 2 * v8;
      v9 = __CFADD__(v8, v14);
      v14 += v8;
      v5 = v13;
      v15 += v12 + v9;
      v4 = (__PAIR__(v4, v6) - __PAIR__(v12, v8)) >> 32;
      v6 -= v8;
      *v13[11] -= v8;
      *v13[7] += 2 * v8;
    }
    else
    {
      v10 = ((*v13)[7])();
      if ( v10 == -1 )
        return v14;
      *a2 = v10;
      a2 = a2 + 2;
      v15 = (__PAIR__(v15, v14++) + 1) >> 32;
      v9 = v6-- != 0;
      v5 = v13;
      v4 = v9 + v4 - 1;
    }
  }
  while ( v4 > 0 || v4 >= 0 && v6 );
  return v14;
}

//----- (00FAA8C0) --------------------------------------------------------
unsigned int __thiscall sub_FAA8C0(_DWORD **this, void *a2, int a3, int a4)
{
  signed int v4; // ebx
  _DWORD **v5; // edx
  int v6; // edi
  __int64 v7; // rax
  unsigned int v8; // esi
  unsigned __int8 v9; // cf
  unsigned int v11; // [esp+8h] [ebp-Ch]
  _DWORD **v12; // [esp+Ch] [ebp-8h]
  unsigned int v13; // [esp+10h] [ebp-4h]
  int v14; // [esp+24h] [ebp+10h]

  v4 = a4;
  v5 = this;
  v12 = this;
  if ( a4 < 0 )
    return 0;
  v6 = a3;
  if ( a4 <= 0 && !a3 )
    return 0;
  v14 = 0;
  v13 = 0;
  do
  {
    v7 = sub_FA9400(v5);
    v11 = HIDWORD(v7);
    v8 = v7;
    if ( v7 >= 0 && (SHIDWORD(v7) > 0 || v7) )
    {
      if ( __PAIR__(v4, v6) < v7 )
      {
        v8 = v6;
        v11 = v4;
      }
      if ( v8 )
        memmove_0(*v12[8], a2, 2 * v8);
      a2 = a2 + 2 * v8;
      v9 = __CFADD__(v8, v13);
      v13 += v8;
      v5 = v12;
      v14 += v11 + v9;
      v4 = (__PAIR__(v4, v6) - __PAIR__(v11, v8)) >> 32;
      v6 -= v8;
      *v12[12] -= v8;
      *v12[8] += 2 * v8;
    }
    else
    {
      if ( ((*v12)[3])(*a2) == -1 )
        return v13;
      v5 = v12;
      a2 = a2 + 2;
      v14 = (__PAIR__(v14, v13++) + 1) >> 32;
      v4 = (__PAIR__(v4, v6--) - 1) >> 32;
    }
  }
  while ( v4 > 0 || v4 >= 0 && v6 );
  return v13;
}

//----- (00FAA9D0) --------------------------------------------------------
void *__thiscall CObjSecurity::`scalar deleting destructor'(void *this, char a2)
{
  void *v2; // esi
  HLOCAL *v3; // edi

  v2 = this;
  v3 = (this + 12);
  *this = &CObjSecurity::`vftable';
  if ( this != -12 )
  {
    if ( *v3 )
      LocalFree(*v3);
    *v3 = 0;
  }
  if ( a2 & 1 )
    j__free(v2);
  return v2;
}
// 103C4C4: using guessed type void *CObjSecurity::`vftable';

//----- (00FAAA10) --------------------------------------------------------
int __cdecl CObjSecurity::~CObjSecurity(int a1)
{
  return (*(*a1 + 8))(a1);
}

//----- (00FAAA20) --------------------------------------------------------
int __cdecl CObjSecurity::Create(tagHANDLELISTITEMPARAM *pItem, LPCWSTR lpszText, CObjSecurity **ppv, int nType, BOOL fObjSecurity)
{
  CObjSecurity *v5; // eax
  CObjSecurity *v6; // esi
  CObjSecurityVTbl *v7; // ecx
  int result; // eax
  int v9; // ebx

  *ppv = 0;
  v5 = operator new(0x1Cu);
  v6 = v5;
  if ( !v5 )
    return -2147024882;
  v5->vtptr = &CObjSecurity::`vftable';
  v7 = v5->vtptr;
  v5->m_nRefCount = 1;
  result = (v7->Init)(v5, 0x213, pItem, lpszText, &gszNullString, nType, fObjSecurity);
  v9 = result;
  if ( result < 0 )
  {
    (v6->vtptr->Destroy)(v6, 1);
    result = v9;
  }
  else
  {
    *ppv = v6;
  }
  return result;
}
// 103C4C4: using guessed type void *CObjSecurity::`vftable';

//----- (00FAAA90) --------------------------------------------------------
int __stdcall CObjSecurity::AddRef(int a1)
{
  int result; // eax

  result = *(a1 + 4) + 1;
  *(a1 + 4) = result;
  return result;
}

//----- (00FAAAB0) --------------------------------------------------------
int __stdcall CObjSecurity::GetAccessRights(int a1, int a2, int a3, _DWORD *a4, _DWORD *a5, _DWORD *a6)
{
  int result; // eax

  switch ( *(a1 + 20) )
  {
    case 0:
      *a4 = &off_105D008;
      *a5 = 9;
      *a6 = 0;
      result = 0;
      break;
    case 2:
      *a4 = &off_105D098;
      *a5 = 5;
      *a6 = 0;
      result = 0;
      break;
    case 3:
      *a4 = &off_105CCD8;
      *a5 = 19;
      *a6 = 0;
      result = 0;
      break;
    case 4:
      *a4 = &off_105CF18;
      *a5 = 15;
      *a6 = 0;
      result = 0;
      break;
    case 5:
      *a4 = &off_105CE08;
      *a5 = 17;
      *a6 = 0;
      result = 0;
      break;
    default:
      *a4 = &off_105CC68;
      *a5 = 7;
      *a6 = 0;
      result = 0;
      break;
  }
  return result;
}
// 105CC68: using guessed type GUID *off_105CC68;
// 105CCD8: using guessed type GUID *off_105CCD8;
// 105CE08: using guessed type GUID *off_105CE08;
// 105CF18: using guessed type GUID *off_105CF18;
// 105D008: using guessed type GUID *off_105D008;
// 105D098: using guessed type GUID *off_105D098;

//----- (00FAABB0) --------------------------------------------------------
int __stdcall CObjSecurity::GetInheritTypes(int a1, _DWORD *a2, _DWORD *a3)
{
  *a2 = &off_105D0E8;
  *a3 = 1;
  return 0;
}
// 105D0E8: using guessed type GUID *off_105D0E8;

//----- (00FAABD0) --------------------------------------------------------
int __stdcall CObjSecurity::GetObjectInformation(_DWORD *a1, _DWORD *a2)
{
  *a2 = a1[2];
  a2[1] = ghMainInstance;
  a2[2] = a1[3];
  a2[3] = a1[4];
  return 0;
}

//----- (00FAAC00) --------------------------------------------------------
int __stdcall CObjSecurity::GetSecurity(int a1, SECURITY_INFORMATION dwSecurityInformation, PSECURITY_DESCRIPTOR lpSecurityDescriptor, int a4)
{
  bool v4; // zf
  _DWORD *v5; // esi
  int result; // eax
  HLOCAL v7; // eax

  v4 = a4 == 0;
  v5 = lpSecurityDescriptor;
  *lpSecurityDescriptor = 0;
  if ( !v4 )
    return -2147467263;
  if ( *(a1 + 20) == 4 )
  {
    QueryServiceObjectSecurity(*(*(a1 + 24) + 44), dwSecurityInformation, v5, 0, &lpSecurityDescriptor);
    if ( GetLastError() == 122 )
    {
      v7 = LocalAlloc(0, lpSecurityDescriptor);
      *v5 = v7;
      if ( QueryServiceObjectSecurity(
             *(*(a1 + 24) + 44),
             dwSecurityInformation,
             v7,
             lpSecurityDescriptor,
             &lpSecurityDescriptor) )
      {
        return 0;
      }
    }
    result = GetLastError();
  }
  else
  {
    result = sub_FDF3E0(*(a1 + 24), dwSecurityInformation, v5);
  }
  if ( result > 0 )
    result = result | 0x80070000;
  return result;
}

//----- (00FAACB0) --------------------------------------------------------
int __stdcall CObjSecurity::Init(CObjSecurity *a1, int a2, int a3, int a4, wchar_t *Src, int a6, int a7)
{
  int result; // eax

  a1->m_dwFlags = a2;
  if ( a7 )
    a1->m_dwFlags = a2 | 4;
  result = CopyServerName(&a1->m_pszServerName, Src);
  a1->m_nRightType = a6;
  a1->m_pszObjectName = a4;
  a1->m_ServerInfo = a3;
  return result;
}

//----- (00FAACF0) --------------------------------------------------------
int __cdecl CopyServerName(int a1, wchar_t *Src)
{
  unsigned int v2; // kr00_4
  wchar_t *v3; // eax

  if ( !a1 || !Src )
    return -2147024809;
  v2 = wcslen(Src);
  v3 = LocalAlloc(0x40u, 2 * (v2 + 1));
  *a1 = v3;
  if ( !v3 )
    return -2147024882;
  wcscpy_s(v3, v2 + 1, Src);
  return 0;
}

//----- (00FAAD60) --------------------------------------------------------
int __stdcall CObjSecurity::MapGeneric(int a1, int a2, int a3, PDWORD AccessMask)
{
  int result; // eax

  if ( *(a1 + 20) == 3 )
  {
    MapGenericMask(AccessMask, &stru_105CC38);
    result = 0;
  }
  else if ( *(a1 + 20) == 4 )
  {
    MapGenericMask(AccessMask, &stru_105CC58);
    result = 0;
  }
  else
  {
    if ( *(a1 + 20) == 5 )
      MapGenericMask(AccessMask, &stru_105CC48);
    else
      MapGenericMask(AccessMask, &GenericMapping);
    result = 0;
  }
  return result;
}

//----- (00FAADD0) --------------------------------------------------------
int __stdcall CObjSecurity::PropertySheetPageCallback(int a1, int a2, int a3, int a4)
{
  return 0;
}

//----- (00FAADE0) --------------------------------------------------------
signed int __stdcall CObjSecurity::QueryInterface(int a1, _DWORD *a2, _DWORD *a3)
{
  _DWORD *v3; // ecx
  _DWORD *v4; // edx
  GUID *v5; // esi
  unsigned int v6; // edi
  bool v7; // cf
  GUID *v9; // edx
  unsigned int v10; // esi

  v3 = a2;
  v4 = a2;
  v5 = &CLSID_IUnknown;
  v6 = 12;
  while ( *v4 == v5->Data1 )
  {
    ++v4;
    v5 = (v5 + 4);
    v7 = v6 < 4;
    v6 -= 4;
    if ( v7 )
    {
      *a3 = a1;
      ++*(a1 + 4);
      return 0;
    }
  }
  v9 = &CLSID_IObjectSecurity;
  v10 = 12;
  while ( *v3 == v9->Data1 )
  {
    ++v3;
    v9 = (v9 + 4);
    v7 = v10 < 4;
    v10 -= 4;
    if ( v7 )
    {
      *a3 = a1;
      ++*(a1 + 4);
      return 0;
    }
  }
  *a3 = 0;
  return -2147467262;
}
// 103C4B0: using guessed type GUID CLSID_IObjectSecurity;
// 1047BBC: using guessed type GUID CLSID_IUnknown;

//----- (00FAAE60) --------------------------------------------------------
int __stdcall CObjSecurity::Release(_DWORD *a1)
{
  bool v1; // zf
  int result; // eax

  v1 = a1[1]-- == 1;
  result = a1[1];
  if ( v1 )
  {
    (*(*a1 + 40))(1);
    result = 0;
  }
  return result;
}

//----- (00FAAE80) --------------------------------------------------------
int __stdcall CObjSecurity::SetSecurity(int a1, SECURITY_INFORMATION dwSecurityInformation, PSECURITY_DESCRIPTOR lpSecurityDescriptor)
{
  int result; // eax

  if ( *(a1 + 20) == 4 )
  {
    if ( SetServiceObjectSecurity(*(*(a1 + 24) + 44), dwSecurityInformation, lpSecurityDescriptor) )
      return 0;
    result = GetLastError();
  }
  else
  {
    result = sub_FDF4D0(*(a1 + 24), dwSecurityInformation, lpSecurityDescriptor, 0, 0);
  }
  if ( result > 0 )
    result = result | 0x80070000;
  return result;
}

//----- (00FAAEE0) --------------------------------------------------------
int __thiscall sub_FAAEE0(_DWORD *this, int a2, char a3, int a4, int a5, void *a6)
{
  _DWORD *v6; // edi
  unsigned int v7; // eax
  _DWORD *v8; // eax
  int *v9; // ecx
  int *v10; // esi
  int *v11; // edx
  _DWORD *v12; // edx
  void **v13; // ecx
  _DWORD *v14; // edx
  _DWORD *v15; // esi
  int v16; // ecx
  _DWORD *v17; // ecx
  int v18; // edx
  int v19; // ecx
  _DWORD *v20; // ecx
  _DWORD *v21; // ecx
  int result; // eax

  v6 = this;
  v7 = this[1];
  if ( v7 >= 0xAAAAAA9 )
  {
    sub_FA1430(a6 + 4);
    j__free(a6);
    std::_Xlength_error("map/set<T> too long");
  }
  this[1] = v7 + 1;
  *(a6 + 1) = a4;
  if ( a4 == *this )
  {
    *(*this + 4) = a6;
    **this = a6;
    *(*this + 8) = a6;
  }
  else if ( a3 )
  {
    *a4 = a6;
    if ( a4 == **this )
      **this = a6;
  }
  else
  {
    *(a4 + 8) = a6;
    if ( a4 == *(*this + 8) )
      *(*this + 8) = a6;
  }
  v8 = a6;
  if ( !*(*(a6 + 1) + 12) )
  {
    do
    {
      v9 = v8[1];
      v10 = v9[1];
      v11 = *v10;
      if ( v9 == *v10 )
      {
        v11 = v10[2];
        if ( *(v11 + 12) )
        {
          if ( v8 == v9[2] )
          {
            v8 = v8[1];
            v12 = v9[2];
            v9[2] = *v12;
            if ( !*(*v12 + 13) )
              *(*v12 + 4) = v9;
            v12[1] = v9[1];
            if ( v9 == *(*v6 + 4) )
            {
              *(*v6 + 4) = v12;
            }
            else
            {
              v13 = v9[1];
              if ( v8 == *v13 )
                *v13 = v12;
              else
                v13[2] = v12;
            }
            *v12 = v8;
            v8[1] = v12;
          }
          *(v8[1] + 12) = 1;
          *(*(v8[1] + 4) + 12) = 0;
          v14 = *(v8[1] + 4);
          v15 = *v14;
          *v14 = *(*v14 + 8);
          v16 = v15[2];
          if ( !*(v16 + 13) )
            *(v16 + 4) = v14;
          v15[1] = v14[1];
          if ( v14 == *(*v6 + 4) )
          {
            *(*v6 + 4) = v15;
            v15[2] = v14;
          }
          else
          {
            v17 = v14[1];
            if ( v14 == v17[2] )
              v17[2] = v15;
            else
              *v17 = v15;
            v15[2] = v14;
          }
LABEL_48:
          v14[1] = v15;
          continue;
        }
      }
      else if ( *(v11 + 12) )
      {
        if ( v8 == *v9 )
        {
          v8 = v8[1];
          v18 = *v9;
          *v9 = *(*v9 + 8);
          v19 = *(v18 + 8);
          if ( !*(v19 + 13) )
            *(v19 + 4) = v8;
          *(v18 + 4) = v8[1];
          if ( v8 == *(*v6 + 4) )
          {
            *(*v6 + 4) = v18;
          }
          else
          {
            v20 = v8[1];
            if ( v8 == v20[2] )
              v20[2] = v18;
            else
              *v20 = v18;
          }
          *(v18 + 8) = v8;
          v8[1] = v18;
        }
        *(v8[1] + 12) = 1;
        *(*(v8[1] + 4) + 12) = 0;
        v14 = *(v8[1] + 4);
        v15 = v14[2];
        v14[2] = *v15;
        if ( !*(*v15 + 13) )
          *(*v15 + 4) = v14;
        v15[1] = v14[1];
        if ( v14 == *(*v6 + 4) )
        {
          *(*v6 + 4) = v15;
        }
        else
        {
          v21 = v14[1];
          if ( v14 == *v21 )
            *v21 = v15;
          else
            v21[2] = v15;
        }
        *v15 = v14;
        goto LABEL_48;
      }
      *(v9 + 12) = 1;
      *(v11 + 12) = 1;
      *(*(v8[1] + 4) + 12) = 0;
      v8 = *(v8[1] + 4);
    }
    while ( !*(v8[1] + 12) );
  }
  *(*(*v6 + 4) + 12) = 1;
  result = a2;
  *a2 = a6;
  return result;
}

//----- (00FAB100) --------------------------------------------------------
int __thiscall sub_FAB100(_DWORD **this, int a2, int a3, int a4, void *a5)
{
  _DWORD *v5; // ebx
  bool v6; // al
  int *v7; // esi
  Data_t_bstr_t *v8; // ecx
  Data_t_bstr_t *v9; // eax
  OLECHAR *v10; // eax
  Data_t_bstr_t *v11; // ecx
  OLECHAR **v12; // eax
  int v13; // eax
  OLECHAR *v14; // eax
  int v15; // esi
  int *v16; // eax
  int v17; // ecx
  int result; // eax
  int v19; // edi
  void *v20; // edi
  int v21; // [esp+0h] [ebp-28h]
  _DWORD **v22; // [esp+10h] [ebp-18h]
  int v23; // [esp+14h] [ebp-14h]
  int *v24; // [esp+18h] [ebp-10h]
  int v25; // [esp+24h] [ebp-4h]

  v24 = &v21;
  v22 = this;
  v5 = *this;
  v6 = 1;
  v25 = 0;
  LOBYTE(v23) = 1;
  v7 = v5[1];
  if ( !*(v7 + 13) )
  {
    while ( 1 )
    {
      v5 = v7;
      if ( !a3 )
      {
        v11 = *a4;
        v12 = v7[4];
        if ( *a4 == v12 )
          goto LABEL_16;
        if ( v11 )
        {
          if ( v12 )
          {
            v13 = bstr_t::Data_t::Compare(v11, v7[4]);
            goto LABEL_27;
          }
          if ( v11->m_wstr && SysStringLen(v11->m_wstr) )
          {
            v13 = 1;
            goto LABEL_27;
          }
        }
        else if ( v12 )
        {
          v14 = *v12;
          if ( v14 )
          {
            if ( SysStringLen(v14) )
            {
              v13 = -1;
              goto LABEL_27;
            }
          }
        }
LABEL_16:
        v13 = 0;
LABEL_27:
        v6 = v13 < 0;
        goto LABEL_28;
      }
      v8 = v7[4];
      v9 = *a4;
      if ( v8 != *a4 )
      {
        if ( v8 )
        {
          if ( v9 )
          {
            v6 = bstr_t::Data_t::Compare(v8, v9) >= 0;
            goto LABEL_28;
          }
          if ( v8->m_wstr && SysStringLen(v8->m_wstr) )
          {
            v6 = 1;
            goto LABEL_28;
          }
        }
        else if ( v9 )
        {
          v10 = v9->m_wstr;
          if ( v10 )
          {
            if ( SysStringLen(v10) )
            {
              v6 = 0;
              goto LABEL_28;
            }
          }
        }
      }
      v6 = 1;
LABEL_28:
      LOBYTE(v23) = v6;
      if ( v6 )
        v7 = *v7;
      else
        v7 = v7[2];
      if ( *(v7 + 13) )
      {
        this = v22;
        break;
      }
    }
  }
  v15 = v5;
  a3 = v5;
  if ( v6 )
  {
    if ( v5 == **this )
    {
      v16 = sub_FAAEE0(this, &a3, 1, v5, a4, a5);
LABEL_36:
      v17 = *v16;
      result = a2;
      *a2 = v17;
      *(a2 + 4) = 1;
      return result;
    }
    std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *>>>,std::_Iterator_base0>::operator--(&a3);
    v15 = a3;
  }
  v19 = a4;
  if ( sub_F73C30((v15 + 16), a4) )
  {
    v16 = sub_FAAEE0(v22, &a3, v23, v5, v19, a5);
    goto LABEL_36;
  }
  v20 = a5;
  sub_FA1430(a5 + 4);
  j__free(v20);
  result = a2;
  *a2 = v15;
  *(a2 + 4) = 0;
  return result;
}
// 10081AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);

//----- (00FAB2D0) --------------------------------------------------------
CString *__thiscall ATL::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>::Format(CString *this, UINT nID)
{
  CString *v2; // esi
  IAtlStringMgr *v3; // ecx
  CHAR *v4; // eax
  int v5; // ecx

  v2 = this;
  v3 = ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>::GetDefaultManager();
  if ( !v3 )
    ATL::AtlThrowImpl(E_FAIL);
  v2->pszData = ((v3->vtptr->GetNilData)() + 16);
  if ( !nID )
  {
    v5 = 0;
    goto LABEL_9;
  }
  if ( nID & 0xFFFF0000 )
  {
    v5 = wcslen(nID);
LABEL_9:
    ATL::CSimpleStringT<wchar_t,0>::SetString(v2, nID, v5);
    return v2;
  }
  v4 = ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>::FindStringResourceInstance(nID, 0);
  if ( v4 )
    ATL::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>::LoadStringW(v2, v4, nID);
  return v2;
}

//----- (00FAB3A0) --------------------------------------------------------
CString *__thiscall ATL::CSimpleStringT<wchar_t,0>::CSimpleStringT<wchar_t,0>(CString *this)
{
  CString *v1; // esi
  IAtlStringMgr *v2; // ecx

  v1 = this;
  v2 = ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>::GetDefaultManager();
  if ( !v2 )
    ATL::AtlThrowImpl(E_FAIL);
  v1->pszData = ((v2->vtptr->GetNilData)() + 16);
  return v1;
}

//----- (00FAB3D0) --------------------------------------------------------
ATL::CAtlStringMgr *__thiscall ATL::CAtlStringMgr::Clone(ATL::CAtlStringMgr *this)
{
  return this;
}

//----- (00FAB3E0) --------------------------------------------------------
volatile signed __int32 *__thiscall ATL::CSimpleStringT<wchar_t,0>::~CSimpleStringT<wchar_t,0>(CString *this)
{
  CStringData *v1; // edx
  volatile signed __int32 *result; // eax

  v1 = (this->pszData - 16);
  result = &v1->nRefs;
  if ( _InterlockedDecrement(&v1->nRefs) <= 0 )
    result = (v1->pStringMgr->vtptr->Free)(v1);
  return result;
}

//----- (00FAB460) --------------------------------------------------------
// CString::operator+(const CString& str1,LPCWSTR lpszText)
CString *__cdecl ATL::CSimpleStringT<wchar_t,0>::Append(CString *str1, CString *str2, WCHAR *lpszSource2)
{
  CStringData *v3; // ecx
  IAtlStringMgr *v4; // edx
  IAtlStringMgr *v5; // eax
  int v6; // edx

  v3 = *(str2->pszData - 4);
  if ( !v3 || (v4 = (v3->pStringMgr[4].vtptr)()) == 0 )
  {
    v5 = ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>::GetDefaultManager();
    v4 = (v5->vtptr->Clone)(v5);
  }
  if ( !v4 )
    ATL::AtlThrowImpl(E_FAIL);
  str1->pszData = ((v4->vtptr->GetNilData)(v4) + 16);
  if ( lpszSource2 )
    v6 = wcslen(lpszSource2);
  else
    v6 = 0;
  ATL::CSimpleStringT<wchar_t,0>::Concatenate(str1, str2->pszData, *(str2->pszData - 3), lpszSource2, v6);
  return str1;
}

//----- (00FAB540) --------------------------------------------------------
void *__thiscall ATL::CAtlStringMgr::`scalar deleting destructor'(void *this, char a2)
{
  void *v2; // esi

  v2 = this;
  *this = &ATL::CAtlStringMgr::`vftable';
  byte_1064DF4 = 0;
  if ( a2 & 1 )
    j__free(this);
  return v2;
}
// 103C510: using guessed type void *ATL::CAtlStringMgr::`vftable';
// 1064DF4: using guessed type char byte_1064DF4;

//----- (00FAB570) --------------------------------------------------------
void *__thiscall ATL::CWin32Heap::`vector deleting destructor'(void *this, char a2)
{
  void *v2; // esi
  bool v3; // zf

  v2 = this;
  v3 = *(this + 8) == 0;
  *this = &ATL::CWin32Heap::`vftable';
  if ( !v3 && *(this + 1) )
    HeapDestroy(*(this + 1));
  if ( a2 & 1 )
    j__free(v2);
  return v2;
}
// 103C4F8: using guessed type void *ATL::CWin32Heap::`vftable';

//----- (00FAB5B0) --------------------------------------------------------
ATL::CAtlStringMgr **__thiscall ATL::CAtlStringMgr::Allocate(ATL::CAtlStringMgr *this, int a2, unsigned int a3)
{
  ATL::CAtlStringMgr *v3; // edi
  ATL::CAtlStringMgr **result; // eax
  int v5; // esi
  unsigned int v6; // eax
  int v7; // ecx

  v3 = this;
  if ( a2 < 0 || 0x7FFFFFFF - a2 < 1 )
    return 0;
  v5 = (a2 + 8) & 0xFFFFFFF8;
  if ( a2 + 1 > v5 )
    return 0;
  v6 = a3 * v5;
  if ( !is_mul_ok(a3, v5) )
    return 0;
  if ( v6 > 0xFFFFFFFF )
    return 0;
  if ( v6 > 0xFFFFFFEF )
    return 0;
  v7 = (***(this + 1))(v6 + 16);
  if ( !v7 )
    return 0;
  *v7 = v3;
  *(v7 + 8) = v5 - 1;
  result = v7;
  *(v7 + 12) = 1;
  *(v7 + 4) = 0;
  return result;
}

//----- (00FAB630) --------------------------------------------------------
LPVOID __thiscall ATL::CWin32Heap::Allocate(HANDLE *this, SIZE_T dwBytes)
{
  return HeapAlloc(this[1], 0, dwBytes);
}

//----- (00FAB650) --------------------------------------------------------
int __cdecl sub_FAB650(int a1)
{
  int result; // eax

  switch ( a1 )
  {
    case 0:
    case 80:
      return a1;
    case 12:
      ATL::AtlThrowImpl(E_OUTOFMEMORY);
      return result;
    case 22:
    case 34:
      ATL::AtlThrowImpl(E_INVALIDARG);
      return result;
    default:
      ATL::AtlThrowImpl(E_FAIL);
      return result;
  }
}

//----- (00FAB6F0) --------------------------------------------------------
CHAR *__cdecl ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>::FindStringResourceInstance(int a1, WORD wLanguage)
{
  CHAR *v2; // esi
  int v3; // edi
  unsigned int v4; // ebx
  HRSRC v5; // eax

  v2 = ATL::CAtlBaseModule::GetHInstanceAt(&ATL::_AtlBaseModule, 0);
  v3 = 1;
  if ( !v2 )
    return 0;
  v4 = a1 >> 4;
  while ( 1 )
  {
    v5 = FindResourceExW(v2, 6, (v4 + 1), wLanguage);
    if ( v5 )
    {
      if ( ATL::AtlGetStringResourceImage(v2, v5, a1) )
        break;
    }
    v2 = ATL::CAtlBaseModule::GetHInstanceAt(&ATL::_AtlBaseModule, v3++);
    if ( !v2 )
      return 0;
  }
  return v2;
}

//----- (00FAB760) --------------------------------------------------------
void __cdecl __noreturn ATL::AtlThrowImpl(int a1)
{
  _CxxThrowException(&a1, &_TI1_AVCAtlException_ATL__);
}
// 10081AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);
// 1054740: using guessed type int _TI1_AVCAtlException_ATL__;

//----- (00FAB780) --------------------------------------------------------
void __cdecl sub_FAB780(HWND hWnd, CString lpCommandLine)
{
  WCHAR *v2; // esi
  CString *v3; // eax
  CStringData *v4; // edx
  CString *v5; // eax
  CString *v6; // eax
  CStringData *v7; // edx
  CStringData *v8; // edx
  CStringData *v9; // edx
  CStringData *v10; // edx
  struct _STARTUPINFOW StartupInfo; // [esp+Ch] [ebp-70h]
  struct _PROCESS_INFORMATION ProcessInformation; // [esp+50h] [ebp-2Ch]
  CString v13; // [esp+60h] [ebp-1Ch]
  CString str1; // [esp+64h] [ebp-18h]
  CString v15; // [esp+68h] [ebp-14h]
  CString lpText; // [esp+6Ch] [ebp-10h]
  int index; // [esp+78h] [ebp-4h]

  v2 = lpCommandLine.pszData;
  if ( *lpCommandLine.pszData == 'H' )
  {
    sub_F77CC0(hWnd, lpCommandLine.pszData);
  }
  else
  {
    StartupInfo.cb = 68;
    StartupInfo.lpReserved = 0;
    memset(&StartupInfo.lpDesktop, 0, 0x3Cu);
    _mm_storeu_si128(&ProcessInformation, 0i64);
    v3 = ATL::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>::Format(&v15, L"explorer /select,");
    index = 0;
    ATL::CSimpleStringT<wchar_t,0>::Append(&lpCommandLine, v3, v2);
    v4 = (v15.pszData - 16);
    LOBYTE(index) = 2;
    if ( _InterlockedDecrement(v15.pszData - 1) <= 0 )
      (v4->pStringMgr->vtptr->Free)(v4);
    if ( CreateProcessW(0, lpCommandLine.pszData, 0, 0, 0, 0, 0, 0, &StartupInfo, &ProcessInformation) )
    {
      CloseHandle(ProcessInformation.hThread);
      CloseHandle(ProcessInformation.hProcess);
    }
    else
    {
      v5 = ATL::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>::Format(
             &v13,
             L"Explorer could not open ");
      LOBYTE(index) = 3;
      v6 = ATL::CSimpleStringT<wchar_t,0>::Append(&str1, v5, v2);
      LOBYTE(index) = 4;
      ATL::CSimpleStringT<wchar_t,0>::Append(&lpText, v6, ".");
      v7 = (str1.pszData - 16);
      LOBYTE(index) = 3;
      if ( _InterlockedDecrement(str1.pszData - 1) <= 0 )
        (v7->pStringMgr->vtptr->Free)(v7);
      v8 = (v13.pszData - 16);
      LOBYTE(index) = 2;
      if ( _InterlockedDecrement(v13.pszData - 1) <= 0 )
        (v8->pStringMgr->vtptr->Free)(v8);
      MessageBoxW(hWnd, lpText.pszData, L"Process Explorer", 0x30u);
      v9 = (lpText.pszData - 16);
      if ( _InterlockedDecrement(lpText.pszData - 1) <= 0 )
        (v9->pStringMgr->vtptr->Free)(v9);
    }
    v10 = (lpCommandLine.pszData - 16);
    index = -1;
    if ( _InterlockedDecrement(lpCommandLine.pszData - 1) <= 0 )
      (v10->pStringMgr->vtptr->Free)(v10);
  }
}
// 103C528: using guessed type wchar_t aExplorerSelect[18];
// 103C54C: using guessed type wchar_t aExplorerCouldN[25];

//----- (00FAB950) --------------------------------------------------------
HANDLE StartBackendThread()
{
  InitializeCriticalSection(&gBstrListLock);
  return _beginthread(BackendThreadProc, 0, 0);
}

//----- (00FAB970) --------------------------------------------------------
CStringData *__cdecl sub_FAB970(CStringData *a1)
{
  IAtlStringMgr *pStringMgr; // eax
  volatile signed __int32 *v2; // edx
  CStringData *result; // eax
  CStringData *pNewData; // eax
  CStringData *v5; // edi

  pStringMgr = (a1->pStringMgr->vtptr->Clone)();
  v2 = &a1->nRefs;
  if ( a1->nRefs < 0 || pStringMgr != a1->pStringMgr )
  {
    pNewData = (pStringMgr->vtptr->Allocate)(pStringMgr, v2, a1->nDataLength, 2);
    v5 = pNewData;
    if ( !pNewData )
      ATL::CSimpleStringT<wchar_t,0>::ThrowMemoryException();
    pNewData->nDataLength = a1->nDataLength;
    memcpy_s(&pNewData[1], 2 * a1->nDataLength + 2, &a1[1], 2 * a1->nDataLength + 2);
    result = v5;
  }
  else
  {
    _InterlockedExchangeAdd(v2, 1u);
    result = a1;
  }
  return result;
}

//----- (00FAB9E0) --------------------------------------------------------
CHAR *__cdecl ATL::CSimpleStringT<wchar_t,0>::Concatenate(CString *this, WCHAR *lpszSource, int nLength, void *lpszSource2, int nLength2)
{
  int v5; // ebx
  CHAR *pszData; // edi
  CHAR *result; // eax

  v5 = nLength2 + nLength;
  if ( nLength2 + nLength < 0 )
    goto LABEL_9;
  if ( ((*(this->pszData - 2) - v5) | (1 - *(this->pszData - 1))) < 0 )
    ATL::CSimpleStringT<wchar_t,0>::PrepareWrite2(this, nLength2 + nLength);
  pszData = this->pszData;
  memcpy_s(this->pszData, 2 * nLength, lpszSource, 2 * nLength);
  memcpy_s(&pszData[2 * nLength], 2 * nLength2, lpszSource2, 2 * nLength2);
  if ( v5 > *(this->pszData - 2) )
LABEL_9:
    ATL::AtlThrowImpl(E_INVALIDARG);
  *(this->pszData - 3) = v5;
  result = this->pszData;
  *&this->pszData[2 * v5] = 0;
  return result;
}

//----- (00FABA60) --------------------------------------------------------
CStringData *__thiscall ATL::CSimpleStringT<wchar_t,0>::Empty(CString *this)
{
  CString *v1; // esi
  CStringData *result; // eax
  CStringData *v3; // edx
  IAtlStringMgr *v4; // edi

  v1 = this;
  result = this->pszData;
  v3 = (this->pszData - 16);
  v4 = v3->pStringMgr;
  if ( *(this->pszData - 3) )
  {
    if ( v3->nRefs >= 0 )
    {
      if ( _InterlockedDecrement(&v3->nRefs) <= 0 )
        (v3->pStringMgr->vtptr->Free)(v3);
      result = ((v4->vtptr->GetNilData)(v4) + 16);
      v1->pszData = result;
    }
    else
    {
      if ( result[-1].nAllocLength < 0 )
        ATL::AtlThrowImpl(E_INVALIDARG);
      result[-1].nDataLength = 0;
      result = this->pszData;
      *this->pszData = 0;
    }
  }
  return result;
}

//----- (00FABAC0) --------------------------------------------------------
volatile signed __int32 *__thiscall ATL::CSimpleStringT<wchar_t,0>::Fork(CString *this, int nLength)
{
  CString *pThis; // ebx
  CStringData *pOldData; // esi
  IAtlStringMgr *v4; // eax
  int nLength_1; // edi
  CStringData *pNewData; // edx
  rsize_t nCharsToCopy; // ST0C_4
  CHAR *pszData; // edi
  volatile signed __int32 *result; // eax
  int nOldLength; // [esp+Ch] [ebp-4h]
  CStringData *pNewData_1; // [esp+18h] [ebp+8h]

  //         CStringData* pOldData = GetData();
  //         int nOldLength = pOldData->nDataLength;
  //         CStringData* pNewData = pOldData->pStringMgr->Clone()->Allocate( nLength, sizeof( XCHAR ) );
  //         if( pNewData == NULL )
  //         {
  //             ThrowMemoryException();
  //         }
  //         int nCharsToCopy = ((nOldLength < nLength) ? nOldLength : nLength)+1;  // Copy '\0'
  //         CopyChars( PXSTR( pNewData->data() ), nCharsToCopy,
  //             PCXSTR( pOldData->data() ), nCharsToCopy );
  //         pNewData->nDataLength = nOldLength;
  //         pOldData->Release();
  //         Attach( pNewData );
  pThis = this;
  pOldData = (this->pszData - 16);
  nOldLength = pOldData->nDataLength;
  v4 = (pOldData->pStringMgr->vtptr->Clone)();
  nLength_1 = nLength;
  pNewData = (v4->vtptr->Allocate)(v4, nLength, 2);
  pNewData_1 = pNewData;
  if ( !pNewData )
    ATL::CSimpleStringT<wchar_t,0>::ThrowMemoryException();
  if ( nOldLength < nLength_1 )
    nLength_1 = nOldLength;
  nCharsToCopy = 2 * (nLength_1 + 1);
  pszData = &pNewData[1];
  memcpy_s(&pNewData[1], nCharsToCopy, &pOldData[1], nCharsToCopy);
  pNewData_1->nDataLength = nOldLength;
  result = &pOldData->nRefs;
  if ( _InterlockedDecrement(&pOldData->nRefs) <= 0 )
    result = (pOldData->pStringMgr->vtptr->Free)(pOldData);
  pThis->pszData = pszData;
  return result;
}

//----- (00FABB40) --------------------------------------------------------
int __thiscall ATL::CAtlStringMgr::Free(ATL::CAtlStringMgr *this, struct CStringData *a2)
{
  return (*(**(this + 1) + 4))();
}

//----- (00FABB50) --------------------------------------------------------
LPVOID __thiscall ATL::CWin32Heap::Free(HANDLE *this, LPVOID lpMem)
{
  LPVOID result; // eax

  result = lpMem;
  if ( lpMem )
    result = HeapFree(this[1], 0, lpMem);
  return result;
}

//----- (00FABB70) --------------------------------------------------------
wchar_t *__cdecl sub_FABB70(wchar_t *a1, wchar_t *a2)
{
  const wchar_t *v2; // esi
  void *v3; // ebx
  int v4; // edi
  const wchar_t **v5; // eax
  const wchar_t *v6; // eax
  _DWORD *v7; // eax
  const wchar_t *v8; // eax
  _bstr_t *v9; // esi
  int *v10; // ebx
  Data_t_bstr_t *v11; // esi
  int *v12; // eax
  wchar_t *v13; // esi
  int v14; // eax
  const wchar_t **v16; // eax
  int v17; // [esp+4h] [ebp-10h]
  int v18; // [esp+8h] [ebp-Ch]
  Data_t_bstr_t *v19; // [esp+Ch] [ebp-8h]
  void *v20; // [esp+10h] [ebp-4h]

  v2 = 0;
  if ( !a2 )
    return _wcsdup(v2);
  v3 = _wcsdup(a2);
  v20 = v3;
  _wcsupr(v3);
  EnterCriticalSection(&gBstrListLock);
  v4 = *gBstrList;
  if ( *gBstrList == gBstrList )
    goto LABEL_27;
  while ( 1 )
  {
    v5 = **(v4 + 8);
    if ( v5 )
      v6 = *v5;
    else
      v6 = 0;
    if ( _wcsicmp(v6, L"System") )
    {
      v7 = **(v4 + 8);
      v8 = (v7 ? *v7 : 0);
      if ( _wcsicmp(v8, a1) )
        goto LABEL_25;
    }
    v9 = *(v4 + 8);
    _bstr_t::_bstr_t(&a2, v3);
    v10 = &v9[1];
    v11 = sub_FAC770(v9 + 1, &a2);
    if ( v11 == *v10 || sub_F73C30(&a2, &v11[1].m_str) )
    {
      v18 = *v10;
      v12 = &v18;
    }
    else
    {
      v19 = v11;
      v12 = &v19;
    }
    v13 = a2;
    v14 = *v12;
    v17 = v14;
    if ( a2 )
    {
      if ( !InterlockedDecrement(a2 + 2) )
      {
        if ( *v13 )
        {
          SysFreeString(*v13);
          *v13 = 0;
        }
        if ( *(v13 + 1) )
        {
          j_j__free(*(v13 + 1));
          *(v13 + 1) = 0;
        }
        j__free(v13);
      }
      v14 = v17;
      a2 = 0;
    }
    if ( v14 != *v10 )
      break;
    v3 = v20;
LABEL_25:
    v4 = *v4;
    if ( v4 == gBstrList )
      goto LABEL_26;
  }
  v16 = *(v14 + 20);
  if ( !v16 )
  {
LABEL_26:
    v2 = 0;
    goto LABEL_27;
  }
  v2 = *v16;
LABEL_27:
  LeaveCriticalSection(&gBstrListLock);
  free(v20);
  return _wcsdup(v2);
}

//----- (00FABCE0) --------------------------------------------------------
IAtlStringMgr *__stdcall ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>::GetDefaultManager()
{
  int v0; // eax
  HANDLE v1; // eax

  v0 = ATL::CAtlStringMgr::sbInited;
  if ( !(ATL::CAtlStringMgr::sbInited & 1) )
  {
    ATL::CAtlStringMgr::sbInited |= 1u;
    v1 = GetProcessHeap();
    strHeap.baseclass.vtptr = &ATL::CWin32Heap::`vftable';
    strHeap.m_hHeap = v1;
    strHeap.m_bOwnHeap = 0;
    atexit(sub_102A7F0);
    v0 = ATL::CAtlStringMgr::sbInited;
  }
  if ( !(v0 & 2) )
  {
    strMgr.baseclass.vtptr = &ATL::CAtlStringMgr::`vftable';
    ATL::CAtlStringMgr::sbInited = v0 | 2;
    strMgr.m_pMemMgr = &strHeap;
    strMgr.m_nil.baseclass.nRefs = 2;
    strMgr.m_nil.baseclass.nDataLength = 0;
    strMgr.m_nil.baseclass.nAllocLength = 0;
    *strMgr.m_nil.achNil = 0;
    strMgr.m_nil.baseclass.pStringMgr = &strMgr;
    atexit(sub_102A820);
  }
  return &strMgr;
}
// 103C4F8: using guessed type void *ATL::CWin32Heap::`vftable';
// 103C510: using guessed type void *ATL::CAtlStringMgr::`vftable';
// 1064E04: using guessed type int ATL::CAtlStringMgr::sbInited;

//----- (00FABD90) --------------------------------------------------------
char *__thiscall ATL::CAtlStringMgr::GetNilString(ATL::CAtlStringMgr *this)
{
  _InterlockedExchangeAdd(this + 5, 1u);
  return this + 8;
}

//----- (00FABDA0) --------------------------------------------------------
SIZE_T __thiscall ATL::CWin32Heap::GetSize(HANDLE *this, LPCVOID lpMem)
{
  return HeapSize(this[1], 0, lpMem);
}

//----- (00FABDC0) --------------------------------------------------------
int __thiscall ATL::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>::LoadStringW(CString *this, HMODULE hModule, int nID)
{
  CString *pThis; // ebx
  HRSRC v4; // eax
  ATLSTRINGRESOURCEIMAGE *pImage; // eax
  ATLSTRINGRESOURCEIMAGE *v6; // edi
  int nDestLength; // esi
  int nSrcLength; // ecx
  unsigned __int16 *pszSrc; // edi
  unsigned int v10; // ecx
  int v11; // eax
  int result; // eax

  pThis = this;
  v4 = FindResourceW(hModule, ((nID >> 4) + 1), 6);
  if ( !v4 )
    return 0;
  pImage = ATL::AtlGetStringResourceImage(hModule, v4, nID);
  v6 = pImage;
  if ( !pImage )
    return 0;
  nDestLength = pImage->nLength;
  if ( ((*(pThis->pszData - 2) - nDestLength) | (1 - *(pThis->pszData - 1))) < 0 )
    ATL::CSimpleStringT<wchar_t,0>::PrepareWrite2(pThis, pImage->nLength);
  nSrcLength = v6->nLength;
  pszSrc = v6->achString;
  if ( nSrcLength == -1 )
  {
    if ( pszSrc )
      v10 = wcslen(pszSrc);
    else
      v10 = 0;
    nSrcLength = v10 + 1;
  }
  v11 = wmemcpy_s(pThis->pszData, nDestLength, pszSrc, nSrcLength);
  sub_FAB650(v11);
  if ( nDestLength > *(pThis->pszData - 2) )
    ATL::AtlThrowImpl(E_INVALIDARG);
  *(pThis->pszData - 3) = nDestLength;
  result = 1;
  *&pThis->pszData[2 * nDestLength] = 0;
  return result;
}

//----- (00FABE90) --------------------------------------------------------
volatile signed __int32 *__thiscall ATL::CSimpleStringT<wchar_t,0>::PrepareWrite2(CString *this, int nLength_1)
{
  int nLength; // esi
  CString *this_1; // edi
  CStringData *v4; // ecx
  volatile signed __int32 *result; // eax
  int nAllocLength; // ecx
  int v7; // ecx
  int v8; // ecx

  nLength = nLength_1;
  this_1 = this;
  v4 = this->pszData;
  if ( v4[-1].nDataLength > nLength_1 )
    nLength = v4[-1].nDataLength;
  if ( v4[-1].nRefs > 1 )
    return ATL::CSimpleStringT<wchar_t,0>::Fork(this_1, nLength);
  nAllocLength = v4[-1].nAllocLength;
  if ( nAllocLength < nLength )
  {
    // 1024 * 1024 * 1024
    if ( nAllocLength <= 0x40000000 )
    {
      v8 = nAllocLength / 2 + nAllocLength;
      if ( v8 < nLength )
        v8 = nLength;
      result = ATL::CSimpleStringT<wchar_t,0>::Reallocate(this_1, v8);
    }
    else
    {
      // 1024 * 1024
      v7 = nAllocLength + 0x100000;
      if ( v7 < nLength )
        v7 = nLength;
      result = ATL::CSimpleStringT<wchar_t,0>::Reallocate(this_1, v7);
    }
  }
  return result;
}

//----- (00FABF00) --------------------------------------------------------
volatile signed __int32 *__cdecl sub_FABF00(OLECHAR *lpszText1, OLECHAR *lpszText2, OLECHAR *lpszText3)
{
  _bstr_t *v3; // esi
  Data_t_bstr_t *v4; // eax
  const wchar_t *v5; // eax
  _bstr_t *pItem_1; // ebx
  Data_t_bstr_t *pItem; // eax
  Data_t_bstr_t *v8; // eax
  Data_t_bstr_t *v9; // esi
  OLECHAR *v10; // eax
  Data_t_bstr_t *v11; // edi
  int *v12; // edi
  _DWORD *v13; // eax
  Data_t_bstr_t *v14; // eax
  Data_t_bstr_t *v15; // edi
  OLECHAR *v16; // eax
  _bstr_t *v17; // ebx
  Data_t_bstr_t *v18; // eax
  Data_t_bstr_t **v19; // esi
  Data_t_bstr_t *v20; // eax
  Data_t_bstr_t *v21; // esi
  bool v22; // zf
  OLECHAR *v23; // ebx
  Data_t_bstr_t *v24; // eax
  Data_t_bstr_t *v25; // edi
  OLECHAR *v26; // eax
  Data_t_bstr_t *v27; // eax
  Data_t_bstr_t *v28; // ebx
  OLECHAR *v29; // eax
  CSystemProcessInfoMapNode *v30; // eax
  IAtlStringMgr *v31; // edx
  IAtlStringMgr *v32; // edx
  IAtlStringMgr *v33; // edx
  int v34; // ecx
  int v35; // ecx
  int v36; // ecx
  CHAR *v37; // edx
  CHAR *v38; // edx
  int v39; // edx
  volatile signed __int32 *result; // eax
  LPARAM lParam; // [esp+10h] [ebp-34h]
  CString v42; // [esp+14h] [ebp-30h]
  CString v43; // [esp+18h] [ebp-2Ch]
  int v44; // [esp+1Ch] [ebp-28h]
  _bstr_t *v45; // [esp+24h] [ebp-20h]
  Data_t_bstr_t *v46; // [esp+28h] [ebp-1Ch]
  void *v47; // [esp+2Ch] [ebp-18h]
  void *pItem_2; // [esp+30h] [ebp-14h]
  int a3a; // [esp+34h] [ebp-10h]
  int v50; // [esp+40h] [ebp-4h]

  EnterCriticalSection(&gBstrListLock);
  v3 = *gBstrList;
  if ( *gBstrList == gBstrList )
    goto LABEL_9;
  while ( 1 )
  {
    v4 = v3[2].m_Data->m_wstr;
    v5 = v4 ? v4->m_wstr : 0;
    if ( !_wcsicmp(v5, lpszText1) )
      break;
    v3 = v3->m_Data;
    if ( v3 == gBstrList )
      goto LABEL_9;
  }
  pItem_1 = v3[2].m_Data;
  if ( !pItem_1 )
  {
LABEL_9:
    pItem = operator new(0xCu);
    pItem_1 = pItem;
    pItem_2 = pItem;
    v50 = 0;
    if ( pItem )
    {
      pItem->m_wstr = 0;
      LOBYTE(v50) = 1;
      pItem->m_str = 0;
      pItem->m_RefCount = 0;
      pItem->m_str = std::_Tree_comp_alloc<std::_Tmap_traits<unsigned long,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *>>,0>>::_Buyheadnode();
    }
    else
    {
      pItem_1 = 0;
    }
    a3a = pItem_1;
    v8 = operator new(0xCu);
    v9 = v8;
    pItem_2 = v8;
    v50 = 2;
    if ( v8 )
    {
      v8->m_str = 0;
      v8->m_RefCount = 1;
      v10 = SysAllocString(lpszText1);
      v9->m_wstr = v10;
      if ( !v10 && lpszText1 )
        _com_issue_error(E_OUTOFMEMORY);
    }
    else
    {
      v9 = 0;
    }
    v50 = -1;
    if ( !v9 )
      _com_issue_error(E_OUTOFMEMORY);
    if ( pItem_1 != &pItem_2 )
    {
      v11 = pItem_1->m_Data;
      if ( pItem_1->m_Data )
      {
        if ( !InterlockedDecrement(&v11->m_RefCount) && v11 )
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
        pItem_1->m_Data = 0;
      }
      pItem_1->m_Data = v9;
      InterlockedIncrement(&v9->m_RefCount);
    }
    if ( !InterlockedDecrement(&v9->m_RefCount) )
    {
      if ( v9->m_wstr )
      {
        SysFreeString(v9->m_wstr);
        v9->m_wstr = 0;
      }
      if ( v9->m_str )
      {
        j_j__free(v9->m_str);
        v9->m_str = 0;
      }
      j__free(v9);
    }
    v12 = gBstrList;
    v13 = std::_List_buy<tagEventItem *,std::allocator<tagEventItem *>>::_Buynode<tagEventItem * const &>(
            gBstrList,
            gBstrList[1],
            &a3a);
    if ( (357913940 - *(&gBstrList + 1)) < 1 )
      std::_Xlength_error("list<T> too long");
    *(&gBstrList + 1) = (*(&gBstrList + 1) + 1);
    v12[1] = v13;
    *v13[1] = v13;
  }
  _wcsupr(lpszText2);
  v14 = operator new(0xCu);
  v15 = v14;
  pItem_2 = v14;
  v50 = 3;
  if ( v14 )
  {
    v14->m_str = 0;
    v14->m_RefCount = 1;
    v16 = SysAllocString(lpszText2);
    v15->m_wstr = v16;
    if ( !v16 && lpszText2 )
      _com_issue_error(E_OUTOFMEMORY);
  }
  else
  {
    v15 = 0;
  }
  v50 = -1;
  pItem_2 = v15;
  if ( !v15 )
    _com_issue_error(E_OUTOFMEMORY);
  v17 = pItem_1 + 1;
  a3a = v17;
  v18 = sub_FAC770(v17, &pItem_2);
  v19 = v18;
  if ( v18 != v17->m_Data )
  {
    v20 = v18[1].m_str;
    if ( v15 == v20 )
      goto LABEL_52;
    if ( !v20 )
    {
      if ( v15->m_wstr )
      {
        SysStringLen(v15->m_wstr);
        pItem_2 = v19;
        goto LABEL_54;
      }
      goto LABEL_52;
    }
    if ( bstr_t::Data_t::Compare(v15, v19[4]) >= 0 )
    {
LABEL_52:
      pItem_2 = v19;
      goto LABEL_54;
    }
  }
  pItem_2 = v17->m_Data;
LABEL_54:
  v21 = pItem_2;
  if ( !InterlockedDecrement(&v15->m_RefCount) )
  {
    if ( v15->m_wstr )
    {
      SysFreeString(v15->m_wstr);
      v15->m_wstr = 0;
    }
    if ( v15->m_str )
    {
      j_j__free(v15->m_str);
      v15->m_str = 0;
    }
    j__free(v15);
  }
  v22 = v21 == v17->m_Data;
  v23 = lpszText3;
  if ( v22 )
  {
    v24 = operator new(0xCu);
    v25 = v24;
    pItem_2 = v24;
    v50 = 4;
    if ( v24 )
    {
      v24->m_str = 0;
      v24->m_RefCount = 1;
      v26 = SysAllocString(lpszText3);
      v25->m_wstr = v26;
      if ( !v26 && lpszText3 )
        _com_issue_error(E_OUTOFMEMORY);
    }
    else
    {
      v25 = 0;
    }
    v50 = -1;
    pItem_2 = v25;
    if ( !v25 )
      _com_issue_error(E_OUTOFMEMORY);
    v50 = 5;
    v27 = operator new(0xCu);
    v28 = v27;
    v47 = v27;
    LOBYTE(v50) = 6;
    if ( v27 )
    {
      v27->m_str = 0;
      v27->m_RefCount = 1;
      v29 = SysAllocString(lpszText2);
      v28->m_wstr = v29;
      if ( !v29 && lpszText2 )
        _com_issue_error(E_OUTOFMEMORY);
    }
    else
    {
      v28 = 0;
    }
    LOBYTE(v50) = 5;
    v47 = v28;
    if ( !v28 )
      _com_issue_error(E_OUTOFMEMORY);
    v45 = v28;
    InterlockedIncrement(&v28->m_RefCount);
    v46 = v25;
    InterlockedIncrement(&v25->m_RefCount);
    LOBYTE(v50) = 8;
    v30 = sub_FA11F0(a3a, &v45);
    sub_FAB100(a3a, &v44, 0, &v30->_Keyvalue, v30);
    sub_FA1430(&v45);
    if ( !InterlockedDecrement(&v28->m_RefCount) )
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
    v50 = -1;
    if ( !InterlockedDecrement(&v25->m_RefCount) )
    {
      if ( v25->m_wstr )
      {
        SysFreeString(v25->m_wstr);
        v25->m_wstr = 0;
      }
      if ( v25->m_str )
      {
        j_j__free(v25->m_str);
        v25->m_str = 0;
      }
      j__free(v25);
    }
    v23 = lpszText3;
  }
  LeaveCriticalSection(&gBstrListLock);
  v31 = ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>::GetDefaultManager();
  if ( !v31 )
    ATL::AtlThrowImpl(-2147467259);
  lParam = (v31->vtptr->GetNilData)(v31) + 16;
  v32 = ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>::GetDefaultManager();
  if ( !v32 )
    ATL::AtlThrowImpl(-2147467259);
  v42.pszData = ((v32->vtptr->GetNilData)(v32) + 16);
  v33 = ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>::GetDefaultManager();
  if ( !v33 )
    ATL::AtlThrowImpl(-2147467259);
  v43.pszData = ((v33->vtptr->GetNilData)(v33) + 16);
  v50 = 9;
  if ( lpszText2 )
    v34 = wcslen(lpszText2);
  else
    v34 = 0;
  ATL::CSimpleStringT<wchar_t,0>::SetString(&v42, lpszText2, v34);
  if ( lpszText1 )
    v35 = wcslen(lpszText1);
  else
    v35 = 0;
  ATL::CSimpleStringT<wchar_t,0>::SetString(&lParam, lpszText1, v35);
  if ( v23 )
    v36 = wcslen(v23);
  else
    v36 = 0;
  ATL::CSimpleStringT<wchar_t,0>::SetString(&v43, v23, v36);
  SendMessageW(ghMainWnd, WM_MSG_7F8, 0, &lParam);
  v37 = v43.pszData - 16;
  v50 = -1;
  if ( _InterlockedDecrement(v43.pszData - 1) <= 0 )
    (*(**v37 + 4))(v37);
  v38 = v42.pszData - 16;
  if ( _InterlockedDecrement(v42.pszData - 1) <= 0 )
    (*(**v38 + 4))(v38);
  v39 = lParam - 16;
  result = (lParam - 16 + 12);
  if ( _InterlockedDecrement(result) <= 0 )
    result = (*(**v39 + 4))(v39);
  return result;
}

//----- (00FAC530) --------------------------------------------------------
CStringData *__thiscall ATL::CSimpleStringT<wchar_t,0>::Reallocate(CString *this, int nLength)
{
  CString *v2; // edi
  CStringData *v3; // edx
  CStringData *pNewData; // eax
  CStringData *result; // eax

  v2 = this;
  v3 = (this->pszData - 16);
  if ( v3->nAllocLength >= nLength
    || nLength <= 0
    || (pNewData = (v3->pStringMgr->vtptr->Reallocate)(v3, nLength, 2)) == 0 )
  {
    ATL::CSimpleStringT<wchar_t,0>::ThrowMemoryException();
  }
  result = pNewData + 1;
  v2->pszData = result;
  return result;
}

//----- (00FAC570) --------------------------------------------------------
int __thiscall ATL::CAtlStringMgr::Reallocate(ATL::CAtlStringMgr *this, struct CStringData *a2, int a3, unsigned int a4)
{
  int result; // eax
  int v5; // esi
  unsigned int v6; // eax

  if ( a3 < 0 || 0x7FFFFFFF - a3 < 1 )
    return 0;
  v5 = (a3 + 8) & 0xFFFFFFF8;
  if ( a3 + 1 > v5 )
    return 0;
  v6 = a4 * v5;
  if ( !is_mul_ok(a4, v5) )
    return 0;
  if ( v6 > 0xFFFFFFFF )
    return 0;
  if ( v6 > 0xFFFFFFEF )
    return 0;
  result = (*(**(this + 1) + 8))(a2, v6 + 16);
  if ( !result )
    return 0;
  *(result + 8) = v5 - 1;
  return result;
}

//----- (00FAC5E0) --------------------------------------------------------
LPVOID __thiscall ATL::CWin32Heap::Reallocate(HANDLE *this, LPVOID lpMem, SIZE_T dwBytes)
{
  if ( !lpMem )
    return (**this)(dwBytes);
  if ( dwBytes )
    return HeapReAlloc(this[1], 0, lpMem, dwBytes);
  (*(*this + 1))(lpMem);
  return 0;
}

//----- (00FAC620) --------------------------------------------------------
CStringData *__thiscall ATL::CSimpleStringT<wchar_t,0>::SetString(CString *this, void *Src, int a3)
{
  int v3; // esi
  CString *pThis; // edi
  CStringData *result; // eax
  void *v6; // edx
  unsigned int v7; // ebx
  CStringData *v8; // ecx
  int v9; // ebx
  unsigned int nLength_1; // [esp+14h] [ebp+Ch]

  v3 = a3;
  pThis = this;
  if ( !a3 )
    return ATL::CSimpleStringT<wchar_t,0>::Empty(this);
  v6 = Src;
  if ( !Src )
    goto LABEL_16;
  v7 = (Src - this->pszData) >> 1;
  nLength_1 = *(this->pszData - 3);
  if ( v3 < 0 )
    ATL::AtlThrowImpl(E_INVALIDARG);
  if ( ((*(this->pszData - 2) - v3) | (1 - *(this->pszData - 1))) < 0 )
  {
    ATL::CSimpleStringT<wchar_t,0>::PrepareWrite2(this, v3);
    v6 = Src;
  }
  v8 = pThis->pszData;
  if ( v7 > nLength_1 )
  {
    v9 = 2 * v3;
    memcpy_s(v8, 2 * v8[-1].nAllocLength, v6, 2 * v3);
  }
  else
  {
    memmove_s(v8, 2 * v8[-1].nAllocLength, v8 + 2 * v7, 2 * v3);
    v9 = 2 * v3;
  }
  if ( v3 > *(pThis->pszData - 2) )
LABEL_16:
    ATL::AtlThrowImpl(E_INVALIDARG);
  *(pThis->pszData - 3) = v3;
  result = pThis->pszData;
  *&pThis->pszData[v9] = 0;
  return result;
}

//----- (00FAC6E0) --------------------------------------------------------
HGLOBAL __cdecl ATL::AtlGetStringResourceImage(HMODULE hModule, HRSRC hResInfo, int id)
{
  HGLOBAL result; // eax
  ATLSTRINGRESOURCEIMAGE *pImage; // esi
  ATLSTRINGRESOURCEIMAGE *v5; // edx
  int iIndex; // ecx

  result = LoadResource(hModule, hResInfo);
  if ( result )
  {
    pImage = LockResource(result);
    if ( !pImage )
      return 0;
    v5 = (pImage + SizeofResource(hModule, hResInfo));
    iIndex = id & 0xF;
    if ( id & 0xF )
    {
      while ( pImage < v5 )
      {
        // pImage = (const ATLSTRINGRESOURCEIMAGE*)(LPBYTE( pImage )+(sizeof( ATLSTRINGRESOURCEIMAGE )+(pImage->nLength*sizeof( WCHAR ))));
        pImage = (pImage + 2 * pImage->nLength + 2);
        if ( !--iIndex )
          goto LABEL_6;
      }
      return 0;
    }
LABEL_6:
    if ( pImage >= v5 )
      return 0;
    if ( !pImage->nLength )
      pImage = 0;
    result = pImage;
  }
  return result;
}

//----- (00FAC750) --------------------------------------------------------
void __stdcall sub_FAC750(void *a1)
{
  sub_FA1430(a1 + 4);
  j__free(a1);
}

//----- (00FAC770) --------------------------------------------------------
Data_t_bstr_t *__thiscall sub_FAC770(_bstr_t *this, _bstr_t *a2)
{
  Data_t_bstr_t *v2; // edi
  char *v3; // esi
  Data_t_bstr_t *v4; // ecx
  Data_t_bstr_t *v5; // eax
  OLECHAR *v6; // eax

  v2 = this->m_Data;
  v3 = this->m_Data->m_str;
  while ( !v3[13] )
  {
    v4 = *(v3 + 4);
    v5 = a2->m_Data;
    if ( v4 != a2->m_Data )
    {
      if ( v4 )
      {
        if ( v5 )
        {
          if ( bstr_t::Data_t::Compare(v4, a2->m_Data) < 0 )
            goto LABEL_14;
        }
        else if ( v4->m_wstr )
        {
          SysStringLen(v4->m_wstr);
        }
      }
      else if ( v5 )
      {
        v6 = v5->m_wstr;
        if ( v6 )
        {
          if ( SysStringLen(v6) )
          {
LABEL_14:
            v3 = *(v3 + 2);
            continue;
          }
        }
      }
    }
    v2 = v3;
    v3 = *v3;
  }
  return v2;
}

//----- (00FAC7E0) --------------------------------------------------------
int __cdecl sub_FAC7E0(int a1, int a2, int a3, _DWORD *a4, unsigned __int8 (__cdecl *a5)(_DWORD, _DWORD))
{
  int v5; // ecx
  int v6; // ebx
  int v7; // esi
  bool i; // zf
  int j; // esi
  int result; // eax

  v5 = a3;
  v6 = a2;
  v7 = 2 * a2 + 2;
  for ( i = v7 == a3; v7 < a3; i = v7 == a3 )
  {
    if ( a5(*(a1 + 4 * v7), *(a1 + 4 * v7 - 4)) )
      --v7;
    v5 = a3;
    *(a1 + 4 * v6) = *(a1 + 4 * v7);
    v6 = v7;
    v7 = 2 * v7 + 2;
  }
  if ( i )
  {
    *(a1 + 4 * v6) = *(a1 + 4 * v5 - 4);
    v6 = v5 - 1;
  }
  for ( j = (v6 - 1) / 2; a2 < v6; j = (j - 1) / 2 )
  {
    if ( !a5(*(a1 + 4 * j), *a4) )
      break;
    *(a1 + 4 * v6) = *(a1 + 4 * j);
    v6 = j;
  }
  result = *a4;
  *(a1 + 4 * v6) = *a4;
  return result;
}

//----- (00FAC880) --------------------------------------------------------
void *__cdecl sub_FAC880(void *a1, int a2, int a3)
{
  void *result; // eax
  _DWORD *v4; // esi
  _DWORD *v5; // edi
  int v6; // ebx
  _DWORD *v7; // esi
  int v8; // ST08_4
  char *v9; // [esp+4h] [ebp-8h]
  _DWORD *v10; // [esp+8h] [ebp-4h]

  result = a2;
  v4 = a1;
  if ( a1 != a2 )
  {
    v5 = a1 + 4;
    v9 = a1 + 4;
    if ( a1 + 4 != a2 )
    {
      do
      {
        v6 = *v5;
        v10 = v5;
        if ( (a3)(*v5, *v4) )
        {
          result = memmove(&v5[-(v5 - v4) + 1], v4, 4 * (v5 - v4));
          *v4 = v6;
        }
        else
        {
          v7 = v5 - 1;
          if ( (a3)(v6, *(v5 - 1)) )
          {
            do
            {
              *v5 = *v7;
              v5 = v7;
              v8 = *(v7 - 1);
              --v7;
            }
            while ( (a3)(v6, v8) );
            v10 = v5;
            v5 = v9;
          }
          result = v10;
          v4 = a1;
          *v10 = v6;
        }
        ++v5;
        v9 = v5;
      }
      while ( v5 != a2 );
    }
  }
  return result;
}

//----- (00FAC930) --------------------------------------------------------
int __cdecl sub_FAC930(int a1, int a2, unsigned __int8 (__cdecl *a3)(_DWORD, _DWORD))
{
  int v3; // edi
  int v4; // ecx
  int result; // eax
  int v6; // edx
  int v7; // esi
  int v8; // eax
  int v9; // edx
  int v10; // esi
  int v11; // ebx
  int v12; // [esp+4h] [ebp-8h]
  int v13; // [esp+8h] [ebp-4h]
  int v14; // [esp+14h] [ebp+8h]
  int v15; // [esp+18h] [ebp+Ch]

  v3 = a1;
  v15 = (a2 - a1) >> 2;
  v4 = v15;
  result = v4 - (v4 >> 31);
  v6 = v15 / 2;
  if ( v15 / 2 > 0 )
  {
    v7 = 2 * v6 + 2;
    do
    {
      v8 = *(v3 + 4 * v6 - 4);
      v9 = v6 - 1;
      v10 = v7 - 2;
      v14 = v9;
      v13 = v10;
      v11 = v9;
      v12 = v8;
      if ( v10 < v4 )
      {
        do
        {
          if ( a3(*(v3 + 4 * v10), *(v3 + 4 * v10 - 4)) )
            --v10;
          v4 = v15;
          *(v3 + 4 * v11) = *(v3 + 4 * v10);
          v11 = v10;
          v10 = 2 * v10 + 2;
        }
        while ( v10 < v15 );
        v9 = v14;
      }
      if ( v10 == v4 )
      {
        *(v3 + 4 * v11) = *(v3 + 4 * v4 - 4);
        v11 = v4 - 1;
      }
      result = sub_FACBC0(v3, v11, v9, &v12, a3);
      v6 = v14;
      v4 = v15;
      v7 = v13;
    }
    while ( v14 > 0 );
  }
  return result;
}

//----- (00FAC9E0) --------------------------------------------------------
int __cdecl sub_FAC9E0(int *a1, int *a2, int *a3, unsigned __int8 (__cdecl *a4)(int, int))
{
  int *v4; // esi
  int v5; // eax
  int v6; // eax
  int v7; // ecx
  int v8; // ST00_4
  int *v9; // ebx
  int v10; // ecx
  int v11; // ecx
  int v12; // ecx
  int v13; // ecx
  int v14; // ecx
  int v15; // ecx
  int *v16; // edi
  int v17; // ecx
  int v18; // ecx
  int v19; // ecx
  int v20; // ecx
  int result; // eax
  int v22; // ecx
  int v23; // ecx
  int v24; // ecx
  int v25; // ecx
  int v26; // ecx
  int v27; // [esp-4h] [ebp-18h]
  int v28; // [esp+Ch] [ebp-8h]
  int *v29; // [esp+10h] [ebp-4h]
  int v30; // [esp+1Ch] [ebp+8h]
  int *v31; // [esp+1Ch] [ebp+8h]

  v4 = a1;
  v5 = a3 - a1;
  v27 = *a1;
  if ( v5 <= 40 )
  {
    if ( a4(*a2, v27) )
    {
      v24 = *a2;
      *a2 = *a1;
      *a1 = v24;
    }
    result = a4(*a3, *a2);
    if ( result )
    {
      v25 = *a3;
      *a3 = *a2;
      *a2 = v25;
      result = a4(v25, *a1);
      if ( result )
      {
        v26 = *a2;
        result = *a1;
        *a2 = *a1;
        *a1 = v26;
      }
    }
  }
  else
  {
    v6 = (v5 + 1) / 8;
    v7 = 8 * v6;
    v6 *= 4;
    v8 = *(a1 + v6);
    v9 = (a1 + v6);
    v28 = v7;
    v30 = v6;
    if ( a4(v8, v27) )
    {
      v10 = *v9;
      *v9 = *v4;
      *v4 = v10;
    }
    if ( a4(*(v4 + v28), *v9) )
    {
      v11 = *(v4 + v28);
      *(v4 + v28) = *v9;
      *v9 = v11;
      if ( a4(v11, *v4) )
      {
        v12 = *v9;
        *v9 = *v4;
        *v4 = v12;
      }
    }
    v29 = (a2 - v30);
    if ( a4(*a2, *(a2 - v30)) )
    {
      v13 = *a2;
      *a2 = *v29;
      *v29 = v13;
    }
    if ( a4(*(a2 + v30), *a2) )
    {
      v14 = *(a2 + v30);
      *(a2 + v30) = *a2;
      *a2 = v14;
      if ( a4(v14, *v29) )
      {
        v15 = *a2;
        *a2 = *v29;
        *v29 = v15;
      }
    }
    v16 = (a3 - v30);
    v31 = (a3 - v28);
    if ( a4(*v16, *(a3 - v28)) )
    {
      v17 = *v16;
      *v16 = *v31;
      *v31 = v17;
    }
    if ( a4(*a3, *v16) )
    {
      v18 = *a3;
      *a3 = *v16;
      *v16 = v18;
      if ( a4(v18, *v31) )
      {
        v19 = *v16;
        *v16 = *v31;
        *v31 = v19;
      }
    }
    if ( a4(*a2, *v9) )
    {
      v20 = *a2;
      *a2 = *v9;
      *v9 = v20;
    }
    result = a4(*v16, *a2);
    if ( result )
    {
      v22 = *v16;
      *v16 = *a2;
      *a2 = v22;
      result = a4(v22, *v9);
      if ( result )
      {
        v23 = *a2;
        result = *v9;
        *a2 = *v9;
        *v9 = v23;
      }
    }
  }
  return result;
}

//----- (00FACBC0) --------------------------------------------------------
int __cdecl sub_FACBC0(int a1, int a2, int a3, _DWORD *a4, unsigned __int8 (__cdecl *a5)(_DWORD, _DWORD))
{
  int v5; // edi
  int v6; // esi
  int result; // eax

  v5 = a2;
  v6 = (a2 - 1) / 2;
  if ( a3 >= a2 )
  {
    result = a1;
    *(a1 + 4 * a2) = *a4;
  }
  else
  {
    do
    {
      if ( !a5(*(a1 + 4 * v6), *a4) )
        break;
      *(a1 + 4 * v5) = *(a1 + 4 * v6);
      v5 = v6;
      v6 = (v6 - 1) / 2;
    }
    while ( a3 < v5 );
    result = *a4;
    *(a1 + 4 * v5) = *a4;
  }
  return result;
}

//----- (00FACC30) --------------------------------------------------------
void *__cdecl sub_FACC30(void *a1, int a2, int a3, int a4)
{
  unsigned __int8 (__cdecl *v4)(int, int); // edx
  int *v5; // esi
  int *v6; // edi
  int v7; // ecx
  int v8; // ebx
  void *result; // eax
  int v10; // [esp+Ch] [ebp-8h]
  void *v11; // [esp+10h] [ebp-4h]

  v4 = a4;
  v5 = a2;
  v6 = a1;
  v7 = (a2 - a1) >> 2;
  if ( v7 <= 32 )
    goto LABEL_8;
  v8 = a3;
  while ( v8 > 0 )
  {
    sub_FACD70(&v10, v6, v5, v4);
    v8 = v8 / 2 / 2 + v8 / 2;
    if ( ((v10 - v6) & 0xFFFFFFFC) >= ((v5 - v11) & 0xFFFFFFFC) )
    {
      result = sub_FACC30(v11, v5, v8, a4);
      v5 = v10;
    }
    else
    {
      result = sub_FACC30(v6, v10, v8, a4);
      v6 = v11;
    }
    v4 = a4;
    v7 = v5 - v6;
    if ( v7 <= 32 )
      goto LABEL_8;
  }
  if ( v7 <= 32 )
  {
LABEL_8:
    if ( v7 > 1 )
      result = sub_FAC880(v6, v5, v4);
  }
  else
  {
    if ( ((v5 - v6) & 0xFFFFFFFC) > 4 )
    {
      sub_FAC930(v6, v5, v4);
      v4 = a4;
    }
    result = sub_FACD10(v6, v5, v4);
  }
  return result;
}

//----- (00FACD10) --------------------------------------------------------
signed int __cdecl sub_FACD10(_DWORD *a1, int a2, unsigned __int8 (__cdecl *a3)(_DWORD, _DWORD))
{
  int v3; // esi
  signed int result; // eax
  unsigned __int8 (__cdecl *v5)(_DWORD, _DWORD); // ebx

  v3 = a2 - a1;
  result = (a2 - a1) & 0xFFFFFFFC;
  if ( result > 4 )
  {
    v5 = a3;
    do
    {
      a2 = *(a1 + v3 - 4);
      *(a1 + v3 - 4) = *a1;
      v3 -= 4;
      sub_FAC7E0(a1, 0, v3 >> 2, &a2, v5);
      result = v3 & 0xFFFFFFFC;
    }
    while ( (v3 & 0xFFFFFFFC) > 4 );
  }
  return result;
}

//----- (00FACD70) --------------------------------------------------------
int **__cdecl sub_FACD70(int **a1, int *a2, int *a3, unsigned __int8 (__cdecl *a4)(int, int))
{
  int v4; // kr00_4
  int *v5; // esi
  int *v6; // edi
  int *v7; // eax
  int *v8; // edx
  int *v9; // ebx
  int *v10; // eax
  int v11; // ecx
  bool v12; // zf
  unsigned int v13; // ebx
  int *v14; // edi
  int v15; // ecx
  int *v16; // eax
  int v17; // ecx
  int *v18; // edx
  int *v19; // edi
  int v20; // ecx
  int v21; // ecx
  int v22; // eax
  int v23; // ecx
  int v24; // ecx
  int **result; // eax
  int *v26; // [esp+Ch] [ebp-Ch]
  int *v27; // [esp+Ch] [ebp-Ch]
  int *v28; // [esp+10h] [ebp-8h]
  int v29; // [esp+14h] [ebp-4h]

  v4 = a3 - a2;
  v5 = &a2[v4 / 2];
  sub_FAC9E0(a2, &a2[v4 / 2], a3 - 1, a4);
  v6 = v5 + 1;
  v29 = (v5 + 1);
  if ( a2 < v5 )
  {
    do
    {
      v26 = v5 - 1;
      if ( a4(*(v5 - 1), *v5) )
        break;
      if ( a4(*v5, *v26) )
        break;
      --v5;
    }
    while ( a2 < v26 );
    v6 = v29;
  }
  v7 = a3;
  if ( v6 < a3 )
  {
    while ( !a4(*v6, *v5) )
    {
      v12 = a4(*v5, *v6) == 0;
      v7 = a3;
      if ( v12 )
      {
        ++v6;
        if ( v6 < a3 )
          continue;
      }
      goto LABEL_12;
    }
    v7 = a3;
LABEL_12:
    v29 = v6;
  }
  v8 = v5;
  v9 = v6;
  v28 = v5;
  while ( 2 )
  {
    while ( 2 )
    {
      v27 = v9;
LABEL_15:
      if ( v9 < v7 )
      {
        do
        {
          if ( !a4(*v5, *v9) )
          {
            if ( a4(*v9, *v5) )
              break;
            v10 = v6;
            ++v6;
            if ( v10 != v9 )
            {
              v11 = *(v6 - 1);
              *(v6 - 1) = *v9;
              *v9 = v11;
            }
          }
          ++v9;
        }
        while ( v9 < a3 );
        v8 = v28;
        v29 = v6;
        v27 = v9;
      }
      v12 = v8 == a2;
      if ( v8 <= a2 )
        goto LABEL_32;
      v13 = v28;
      v14 = v28 - 1;
      while ( a4(*v14, *v5) )
      {
LABEL_28:
        v16 = a2;
        v13 -= 4;
        --v14;
        if ( a2 >= v13 )
          goto LABEL_31;
      }
      if ( !a4(*v5, *v14) )
      {
        --v5;
        if ( v5 != v14 )
        {
          v15 = *v5;
          *v5 = *v14;
          *v14 = v15;
        }
        goto LABEL_28;
      }
      v16 = a2;
LABEL_31:
      v6 = v29;
      v28 = v13;
      v8 = v13;
      v12 = v13 == v16;
      v9 = v27;
LABEL_32:
      if ( !v12 )
      {
        --v8;
        v28 = v8;
        if ( v9 != a3 )
        {
          v24 = *v9;
          *v9 = *v8;
          ++v9;
          v7 = a3;
          *v8 = v24;
          continue;
        }
        --v5;
        if ( v8 != v5 )
        {
          v21 = *v8;
          *v8 = *v5;
          *v5 = v21;
        }
        v22 = *(v6 - 1);
        --v6;
        v23 = *v5;
        *v5 = v22;
        v7 = a3;
        v29 = v6;
        *v6 = v23;
        goto LABEL_15;
      }
      break;
    }
    if ( v9 != a3 )
    {
      if ( v6 != v9 )
      {
        v17 = *v5;
        *v5 = *v6;
        *v6 = v17;
      }
      v18 = v5;
      v29 = (v6 + 1);
      ++v5;
      v19 = v9;
      ++v9;
      v20 = *v18;
      *v18 = *v19;
      v8 = v28;
      v7 = a3;
      *v19 = v20;
      v6 = v29;
      continue;
    }
    break;
  }
  result = a1;
  a1[1] = v6;
  *a1 = v5;
  return result;
}

//----- (00FACF50) --------------------------------------------------------
_DWORD *__cdecl sub_FACF50(_DWORD *a1, _WORD *a2, _WORD *a3, _WORD *a4)
{
  _WORD *i; // ecx
  _DWORD *result; // eax

  for ( i = a2; i != a3; ++i )
  {
    if ( *i == *a4 )
      break;
  }
  result = a1;
  *a1 = i;
  return result;
}

//----- (00FACF80) --------------------------------------------------------
void **__thiscall sub_FACF80(void **this, void *Src, int a3, int a4)
{
  void **v4; // edi
  int v5; // eax
  int v6; // eax

  v4 = this;
  if ( !a4 )
    ATL::AtlThrowImpl(-2147467259);
  if ( !Src && a3 )
    goto LABEL_13;
  v5 = (**a4)(a3, 2);
  if ( !v5 )
    ATL::CSimpleStringT<wchar_t,0>::ThrowMemoryException();
  v6 = v5 + 16;
  *v4 = v6;
  if ( a3 < 0 || a3 > *(v6 - 8) )
LABEL_13:
    ATL::AtlThrowImpl(-2147024809);
  *(v6 - 12) = a3;
  *(*v4 + a3) = 0;
  memcpy_s(*v4, 2 * a3, Src, 2 * a3);
  return v4;
}

//----- (00FAD000) --------------------------------------------------------
AppDomain *__thiscall AppDomain::AppDomain(AppDomain *this, int a2, int a3)
{
  AppDomain *v3; // esi
  IAtlStringMgr *v4; // ecx
  IAtlStringMgr *v5; // ecx
  AppDomain *result; // eax

  v3 = this;
  *(this + 2) = a2;
  *this = &Appdomain::`vftable';
  *(this + 3) = a3;
  *(this + 4) = 0;
  v4 = ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>::GetDefaultManager();
  if ( !v4 )
    ATL::AtlThrowImpl(-2147467259);
  *(v3 + 5) = (v4->vtptr->GetNilData)() + 16;
  v5 = ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>::GetDefaultManager();
  if ( !v5 )
    ATL::AtlThrowImpl(-2147467259);
  *(v3 + 6) = (v5->vtptr->GetNilData)() + 16;
  result = v3;
  *(v3 + 7) = 0;
  *(v3 + 8) = 0;
  *(v3 + 9) = 0;
  return result;
}
// 103C910: using guessed type void *Appdomain::`vftable';

//----- (00FAD080) --------------------------------------------------------
CString *__thiscall Assembly::Assembly(CString *this, int a2, int a3, void *a4, void *Src)
{
  CString *v5; // esi
  IAtlStringMgr *v6; // edx
  IAtlStringMgr *v7; // edx
  IAtlStringMgr *v8; // edx
  IAtlStringMgr *v9; // edx
  int v10; // ecx

  v5 = this;
  this->pszData = &Assembly::`vftable';
  v6 = ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>::GetDefaultManager();
  if ( !v6 )
    ATL::AtlThrowImpl(-2147467259);
  v5[1].pszData = ((v6->vtptr->GetNilData)(v6) + 16);
  v5[2].pszData = a2;
  v5[3].pszData = a3;
  v7 = ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>::GetDefaultManager();
  if ( !v7 )
    ATL::AtlThrowImpl(-2147467259);
  v5[4].pszData = ((v7->vtptr->GetNilData)(v7) + 16);
  v8 = ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>::GetDefaultManager();
  if ( !v8 )
    ATL::AtlThrowImpl(-2147467259);
  v5[5].pszData = ((v8->vtptr->GetNilData)(v8) + 16);
  v9 = ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>::GetDefaultManager();
  if ( !v9 )
    ATL::AtlThrowImpl(-2147467259);
  v5[6].pszData = ((v9->vtptr->GetNilData)(v9) + 16);
  if ( Src )
    v10 = wcslen(Src);
  else
    v10 = 0;
  ATL::CSimpleStringT<wchar_t,0>::SetString(v5 + 5, Src, v10);
  sub_FAFFF0(v5, a4);
  return v5;
}
// 103C930: using guessed type void *Assembly::`vftable';

//----- (00FAD1D0) --------------------------------------------------------
CResizer *__thiscall CResizer::CResizer(CResizer *this, HWND hWnd)
{
  CResizer *v2; // esi

  v2 = this;
  this->baseclass.m_hThemeHandle = 0;
  this->baseclass.vtptr = &CResizer::`vftable';
  this->m_OldWndProc = 0;
  this->m_nXRatio = 50;
  this->m_nYRatio = 67;
  this->m_pItem = 0;
  this->m_dwItemCount = 0;
  this->m_FixedBorder = 1;
  if ( hWnd )
    CResizer::InitWnd(this, hWnd);
  return v2;
}
// 103C888: using guessed type void *CResizer::`vftable';

//----- (00FAD260) --------------------------------------------------------
_DWORD *__thiscall sub_FAD260(_DWORD *this)
{
  _DWORD *result; // eax

  *this = 0;
  result = this;
  this[2] = 0;
  this[3] = 1;
  this[4] = 0;
  this[5] = 0;
  this[6] = 0;
  this[7] = 0;
  this[8] = 0;
  this[9] = 0;
  return result;
}

//----- (00FAD2B0) --------------------------------------------------------
Runtime *__thiscall Runtime::Runtime(Runtime *this, unsigned int a2, unsigned __int16 a3)
{
  Runtime *v3; // esi
  IAtlStringMgr *v4; // ecx
  IAtlStringMgr *v5; // ecx
  IAtlStringMgr *v6; // ecx
  IAtlStringMgr *v7; // ecx
  IAtlStringMgr *v8; // ecx
  Runtime *result; // eax

  v3 = this;
  *this = &Runtime::`vftable';
  v4 = ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>::GetDefaultManager();
  if ( !v4 )
    ATL::AtlThrowImpl(-2147467259);
  *(v3 + 1) = (v4->vtptr->GetNilData)() + 16;
  v5 = ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>::GetDefaultManager();
  if ( !v5 )
    ATL::AtlThrowImpl(-2147467259);
  *(v3 + 2) = (v5->vtptr->GetNilData)() + 16;
  v6 = ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>::GetDefaultManager();
  if ( !v6 )
    ATL::AtlThrowImpl(-2147467259);
  *(v3 + 3) = (v6->vtptr->GetNilData)() + 16;
  v7 = ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>::GetDefaultManager();
  if ( !v7 )
    ATL::AtlThrowImpl(-2147467259);
  *(v3 + 4) = (v7->vtptr->GetNilData)() + 16;
  *(v3 + 10) = a3;
  v8 = ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>::GetDefaultManager();
  if ( !v8 )
    ATL::AtlThrowImpl(-2147467259);
  *(v3 + 6) = (v8->vtptr->GetNilData)() + 16;
  *(v3 + 7) = a2;
  result = v3;
  *(v3 + 8) = 0;
  *(v3 + 9) = 0;
  *(v3 + 10) = 0;
  *(v3 + 11) = 0;
  *(v3 + 12) = 0;
  *(v3 + 13) = 0;
  return result;
}
// 103C8F0: using guessed type void *Runtime::`vftable';

//----- (00FAD3B0) --------------------------------------------------------
volatile signed __int32 *__thiscall AppDomain::~AppDomain(void (__stdcall *****this)(signed int))
{
  void (__stdcall *****v1)(signed int); // ebx
  void (__stdcall ****v2)(signed int); // esi
  int v3; // edi
  unsigned int v4; // ecx
  unsigned int v5; // eax
  volatile signed __int32 *v6; // edx
  volatile signed __int32 *v7; // edx
  volatile signed __int32 *result; // eax
  unsigned int v9; // [esp+14h] [ebp-10h]

  v1 = this;
  *this = &Appdomain::`vftable';
  v2 = this[7];
  v3 = 0;
  v4 = (this[8] - v2 + 3) >> 2;
  if ( v2 > v1[8] )
    v4 = 0;
  v9 = v4;
  if ( v4 )
  {
    v5 = v4;
    do
    {
      if ( *v2 )
      {
        (***v2)(1);
        v5 = v9;
      }
      ++v3;
      ++v2;
    }
    while ( v3 != v5 );
  }
  if ( v1[7] )
  {
    j__free(v1[7]);
    v1[7] = 0;
    v1[8] = 0;
    v1[9] = 0;
  }
  v6 = (v1[6] - 4);
  if ( _InterlockedDecrement(v6 + 3) <= 0 )
    (*(**v6 + 4))(v6);
  v7 = (v1[5] - 4);
  result = v7 + 3;
  if ( _InterlockedDecrement(v7 + 3) <= 0 )
    result = (*(**v7 + 4))(v7);
  *v1 = &CTreeListData::`vftable';
  return result;
}
// 103414C: using guessed type void *CTreeListData::`vftable';
// 103C910: using guessed type void *Appdomain::`vftable';

//----- (00FAD4B0) --------------------------------------------------------
volatile signed __int32 *__thiscall Assembly::~Assembly(Assembly *this)
{
  Assembly *v1; // esi
  volatile signed __int32 *v2; // ebx
  volatile signed __int32 *v3; // edx
  volatile signed __int32 *v4; // edx
  volatile signed __int32 *v5; // edx
  volatile signed __int32 *result; // eax

  v1 = this;
  v2 = (*(this + 6) - 16);
  if ( _InterlockedDecrement(v2 + 3) <= 0 )
    (*(**v2 + 4))(v2);
  v3 = (*(v1 + 5) - 16);
  if ( _InterlockedDecrement(v3 + 3) <= 0 )
    (*(**v3 + 4))(v3);
  v4 = (*(v1 + 4) - 16);
  if ( _InterlockedDecrement(v4 + 3) <= 0 )
    (*(**v4 + 4))(v4);
  v5 = (*(v1 + 1) - 16);
  result = v5 + 3;
  if ( _InterlockedDecrement(v5 + 3) <= 0 )
    result = (*(**v5 + 4))(v5);
  *v1 = &CTreeListData::`vftable';
  return result;
}
// 103414C: using guessed type void *CTreeListData::`vftable';

//----- (00FAD530) --------------------------------------------------------
HTHEME __thiscall CResizer::~CResizer(CResizer *this)
{
  CResizer *v1; // esi
  WNDPROC v2; // ST04_4
  LPRESIZERITEM v3; // ST08_4
  HTHEME result; // eax

  v1 = this;
  v2 = this->m_OldWndProc;
  this->baseclass.vtptr = &CResizer::`vftable';
  if ( GetWindowLongW(v2, GWLP_WNDPROC) == CResizer::Proxy_WndProc )
    SetWindowLongW(v1->m_OldWndProc, GWLP_WNDPROC, v1->m_hWnd);
  v3 = v1->m_pItem;
  v1->m_OldWndProc = 0;
  free(v3);
  result = v1->baseclass.m_hThemeHandle;
  v1->m_pItem = 0;
  v1->m_dwItemCount = 0;
  v1->baseclass.vtptr = &CThemedWindow::`vftable';
  if ( result )
    result = gpfnCloseThemeData(result);
  return result;
}
// 1034130: using guessed type void *CThemedWindow::`vftable';
// 103C888: using guessed type void *CResizer::`vftable';

//----- (00FAD590) --------------------------------------------------------
volatile signed __int32 *__thiscall Process::~Process(void (__stdcall *****this)(signed int))
{
  void (__stdcall *****v1)(signed int); // ebx
  void (__stdcall ****v2)(signed int); // esi
  int v3; // edi
  unsigned int v4; // ecx
  unsigned int v5; // eax
  volatile signed __int32 *v6; // edx
  volatile signed __int32 *result; // eax
  unsigned int v8; // [esp+14h] [ebp-10h]

  v1 = this;
  *this = &Process::`vftable';
  v2 = this[3];
  v3 = 0;
  v4 = (this[4] - v2 + 3) >> 2;
  if ( v2 > v1[4] )
    v4 = 0;
  v8 = v4;
  if ( v4 )
  {
    v5 = v4;
    do
    {
      if ( *v2 )
      {
        (***v2)(1);
        v5 = v8;
      }
      ++v3;
      ++v2;
    }
    while ( v3 != v5 );
  }
  if ( v1[3] )
  {
    j__free(v1[3]);
    v1[3] = 0;
    v1[4] = 0;
    v1[5] = 0;
  }
  v6 = (v1[2] - 4);
  result = v6 + 3;
  if ( _InterlockedDecrement(v6 + 3) <= 0 )
    result = (*(**v6 + 4))(v6);
  *v1 = &CTreeListData::`vftable';
  return result;
}
// 103414C: using guessed type void *CTreeListData::`vftable';
// 103C8D0: using guessed type void *Process::`vftable';

//----- (00FAD670) --------------------------------------------------------
volatile signed __int32 *__thiscall Runtime::~Runtime(void (__stdcall *****this)(signed int))
{
  void (__stdcall *****v1)(signed int); // esi
  void (__stdcall ****v2)(signed int); // edi
  int v3; // ebx
  unsigned int v4; // ecx
  unsigned int v5; // eax
  void (__stdcall ****v6)(signed int); // edi
  int v7; // ebx
  unsigned int v8; // ecx
  unsigned int v9; // eax
  volatile signed __int32 *v10; // edx
  volatile signed __int32 *v11; // edx
  volatile signed __int32 *v12; // edx
  volatile signed __int32 *v13; // edx
  volatile signed __int32 *v14; // edx
  volatile signed __int32 *result; // eax
  unsigned int v16; // [esp+14h] [ebp-10h]
  unsigned int v17; // [esp+14h] [ebp-10h]

  v1 = this;
  *this = &Runtime::`vftable';
  v2 = this[8];
  v3 = 0;
  v4 = (this[9] - v2 + 3) >> 2;
  if ( v2 > v1[9] )
    v4 = 0;
  v16 = v4;
  if ( v4 )
  {
    v5 = v4;
    do
    {
      if ( *v2 )
      {
        (***v2)(1);
        v5 = v16;
      }
      ++v3;
      ++v2;
    }
    while ( v3 != v5 );
  }
  v6 = v1[11];
  v7 = 0;
  v8 = (v1[12] - v6 + 3) >> 2;
  if ( v6 > v1[12] )
    v8 = 0;
  v17 = v8;
  if ( v8 )
  {
    v9 = v8;
    do
    {
      if ( *v6 )
      {
        (***v6)(1);
        v9 = v17;
      }
      ++v7;
      ++v6;
    }
    while ( v7 != v9 );
  }
  if ( v1[11] )
  {
    j__free(v1[11]);
    v1[11] = 0;
    v1[12] = 0;
    v1[13] = 0;
  }
  if ( v1[8] )
  {
    j__free(v1[8]);
    v1[8] = 0;
    v1[9] = 0;
    v1[10] = 0;
  }
  v10 = (v1[6] - 4);
  if ( _InterlockedDecrement(v10 + 3) <= 0 )
    (*(**v10 + 4))(v10);
  v11 = (v1[4] - 4);
  if ( _InterlockedDecrement(v11 + 3) <= 0 )
    (*(**v11 + 4))(v11);
  v12 = (v1[3] - 4);
  if ( _InterlockedDecrement(v12 + 3) <= 0 )
    (*(**v12 + 4))(v12);
  v13 = (v1[2] - 4);
  if ( _InterlockedDecrement(v13 + 3) <= 0 )
    (*(**v13 + 4))(v13);
  v14 = (v1[1] - 4);
  result = v14 + 3;
  if ( _InterlockedDecrement(v14 + 3) <= 0 )
    result = (*(**v14 + 4))(v14);
  *v1 = &CTreeListData::`vftable';
  return result;
}
// 103414C: using guessed type void *CTreeListData::`vftable';
// 103C8F0: using guessed type void *Runtime::`vftable';

//----- (00FAD840) --------------------------------------------------------
CString *__thiscall sub_FAD840(CString *this, void **a2)
{
  CString *v2; // esi
  volatile signed __int32 *v3; // edi
  CStringData *v4; // edx
  CStringData *v5; // eax
  CStringData *v7; // [esp+10h] [ebp+8h]

  v2 = this;
  v3 = (this->pszData - 16);
  v4 = (*a2 - 16);
  if ( v4 == v3 )
    return v2;
  if ( *(v3 + 3) < 0 || v4->pStringMgr != *v3 )
  {
    ATL::CSimpleStringT<wchar_t,0>::SetString(this, *a2, *(*a2 - 3));
    return v2;
  }
  v5 = sub_FAB970(v4);
  v7 = v5;
  if ( _InterlockedDecrement(v3 + 3) <= 0 )
  {
    (*(**v3 + 4))(v3);
    v5 = v7;
  }
  v2->pszData = &v5[1];
  return v2;
}

//----- (00FAD8B0) --------------------------------------------------------
void *__thiscall AppDomain::`vector deleting destructor'(void *this, char a2)
{
  void *v2; // esi

  v2 = this;
  AppDomain::~AppDomain(this);
  if ( a2 & 1 )
    j__free(v2);
  return v2;
}

//----- (00FAD8E0) --------------------------------------------------------
void *__thiscall Assembly::`scalar deleting destructor'(void *this, char a2)
{
  void *v2; // esi

  v2 = this;
  Assembly::~Assembly(this);
  if ( a2 & 1 )
    j__free(v2);
  return v2;
}

//----- (00FAD910) --------------------------------------------------------
void *__thiscall Process::`scalar deleting destructor'(void *this, char a2)
{
  void *v2; // esi

  v2 = this;
  Process::~Process(this);
  if ( a2 & 1 )
    j__free(v2);
  return v2;
}

//----- (00FAD940) --------------------------------------------------------
void *__thiscall Runtime::`scalar deleting destructor'(void *this, char a2)
{
  void *v2; // esi

  v2 = this;
  Runtime::~Runtime(this);
  if ( a2 & 1 )
    j__free(v2);
  return v2;
}

//----- (00FAD970) --------------------------------------------------------
int __thiscall sub_FAD970(_DWORD *this, CTreeList *thisIn)
{
  int v2; // edx
  int *v3; // eax
  CTreeList *v4; // edi
  int v5; // ebx
  tagTreeViewChildItem *v6; // esi
  unsigned int v7; // esi
  int *v8; // edi
  int v9; // eax
  CTreeList *v10; // ecx
  int v11; // ebx
  unsigned int v12; // eax
  unsigned int v13; // esi
  int *v14; // eax
  int v15; // edi
  tagTreeViewChildItem *v16; // eax
  tagTreeViewChildItem *v17; // ebx
  unsigned int v18; // esi
  int *v19; // edi
  int v20; // eax
  CTreeList *v21; // ecx
  int v22; // ebx
  unsigned int v23; // eax
  unsigned int v24; // esi
  _DWORD *v26; // [esp+0h] [ebp-20h]
  int v27; // [esp+4h] [ebp-1Ch]
  CTreeList *v28; // [esp+8h] [ebp-18h]
  int v29; // [esp+Ch] [ebp-14h]
  CTreeList *v30; // [esp+10h] [ebp-10h]
  int *v31; // [esp+14h] [ebp-Ch]
  int *v32; // [esp+18h] [ebp-8h]
  tagTreeViewChildItem *v33; // [esp+1Ch] [ebp-4h]

  v26 = this;
  v2 = this[6];
  v3 = *(v2 + 12);
  v31 = v3;
  if ( v3 != *(v2 + 16) )
  {
    v4 = thisIn;
    while ( 1 )
    {
      v27 = *v3;
      v5 = *v3;
      v6 = sub_F9D7E0(v4, 0, *v3, 0, 0);
      v33 = v6;
      CTreeList::OnMsg2001(v4, v6, 1);
      if ( *(v5 + 20) == -3 )
        break;
      v14 = *(v5 + 32);
      v32 = v14;
      if ( v14 != *(v5 + 36) )
      {
        do
        {
          v15 = *v14;
          v16 = sub_F9D7E0(thisIn, v6, *v14, 0, 0);
          v17 = v16;
          v29 = v16;
          CTreeList::OnMsg2001(thisIn, v16, 1);
          sub_FACC30(*(v15 + 28), *(v15 + 32), (*(v15 + 32) - *(v15 + 28)) >> 2, sub_FAE7A0);
          v18 = *(v15 + 32);
          v19 = *(v15 + 28);
          v20 = sub_F9CA50(v17);
          v21 = v20;
          v28 = v20;
          v22 = 0;
          v23 = (v18 - v19 + 3) >> 2;
          if ( v19 > v18 )
            v23 = 0;
          if ( v23 )
          {
            v24 = v23;
            do
            {
              sub_F9D7E0(v21, v29, *v19, 0, 0);
              v21 = v28;
              ++v19;
              ++v22;
            }
            while ( v22 != v24 );
          }
          v14 = v32 + 1;
          v6 = v33;
          v32 = v14;
        }
        while ( v14 != *(v27 + 36) );
        goto LABEL_17;
      }
LABEL_18:
      v3 = v31 + 1;
      v31 = v3;
      if ( v3 == *(v26[6] + 16) )
        return 0;
    }
    sub_FACC30(*(v5 + 44), *(v5 + 48), (*(v5 + 48) - *(v5 + 44)) >> 2, sub_FAE7A0);
    v7 = *(v5 + 48);
    v8 = *(v5 + 44);
    v9 = sub_F9CA50(v33);
    v10 = v9;
    v30 = v9;
    v11 = 0;
    v12 = (v7 - v8 + 3) >> 2;
    if ( v8 > v7 )
      v12 = 0;
    if ( v12 )
    {
      v13 = v12;
      do
      {
        sub_F9D7E0(v10, v33, *v8, 0, 0);
        v10 = v30;
        ++v8;
        ++v11;
      }
      while ( v11 != v13 );
    }
LABEL_17:
    v4 = thisIn;
    goto LABEL_18;
  }
  return 0;
}

//----- (00FADB10) --------------------------------------------------------
int __cdecl sub_FADB10(wchar_t *Dst, rsize_t SizeInWords, int a3)
{
  return sub_FAE970(Dst, SizeInWords, a3, &unk_105D0F8, 3);
}

//----- (00FADB40) --------------------------------------------------------
CHAR *__thiscall sub_FADB40(CString *this, wchar_t *Src)
{
  CHAR *result; // eax

  if ( Src )
    result = sub_FADB80(this, Src, wcslen(Src));
  else
    result = sub_FADB80(this, 0, 0);
  return result;
}

//----- (00FADB80) --------------------------------------------------------
CHAR *__thiscall sub_FADB80(CString *this, wchar_t *Src, size_t MaxCount)
{
  CString *v3; // edi
  unsigned int v4; // ebx
  int v5; // esi
  size_t v6; // edx
  int v7; // esi
  wchar_t *v8; // ecx
  CHAR *result; // eax
  unsigned int v10; // [esp+Ch] [ebp-4h]
  size_t MaxCounta; // [esp+1Ch] [ebp+Ch]

  v3 = this;
  v4 = (Src - this->pszData) >> 1;
  v5 = *(this->pszData - 3);
  v10 = *(this->pszData - 3);
  if ( (MaxCount & 0x80000000) != 0 )
    goto LABEL_18;
  if ( Src )
  {
    MaxCounta = wcsnlen(Src, MaxCount);
    v6 = MaxCounta;
  }
  else
  {
    v6 = 0;
    MaxCounta = 0;
  }
  if ( (0x7FFFFFFF - v6) < v5 )
    ATL::AtlThrowImpl(-2147024809);
  v7 = v6 + v5;
  if ( v7 < 0 )
    ATL::AtlThrowImpl(-2147024809);
  if ( ((*(v3->pszData - 2) - v7) | (1 - *(v3->pszData - 1))) < 0 )
  {
    ATL::CSimpleStringT<wchar_t,0>::PrepareWrite2(v3, v7);
    v6 = MaxCounta;
  }
  v8 = &v3->pszData[2 * v4];
  if ( v4 > v10 )
    v8 = Src;
  memcpy_s(&v3->pszData[2 * v10], 2 * v6, v8, 2 * v6);
  if ( v7 > *(v3->pszData - 2) )
LABEL_18:
    ATL::AtlThrowImpl(-2147024809);
  *(v3->pszData - 3) = v7;
  result = v3->pszData;
  *&v3->pszData[2 * v7] = 0;
  return result;
}

//----- (00FADC50) --------------------------------------------------------
int __cdecl sub_FADC50(wchar_t *Dst, rsize_t SizeInWords, int a3)
{
  return sub_FAE970(Dst, SizeInWords, a3, &unk_105D110, 4);
}

//----- (00FADC80) --------------------------------------------------------
int __thiscall CResizer::InitWnd(CResizer *hData, HWND hWnd)
{
  CResizer *v2; // edi
  WNDPROC v3; // esi
  int v4; // eax
  int result; // eax
  struct tagRECT Rect; // [esp+8h] [ebp-14h]

  v2 = hData;
  hData->m_OldWndProc = hWnd;
  SetPropW(hWnd, L"ResizerClass", hData);
  v2->m_hWnd = GetWindowLongW(hWnd, GWLP_WNDPROC);
  SetWindowLongW(hWnd, GWLP_WNDPROC, CResizer::Proxy_WndProc);
  v3 = v2->m_OldWndProc;
  if ( v2->baseclass.m_hThemeHandle )
    gpfnCloseThemeData(v2->baseclass.m_hThemeHandle);
  v2->baseclass.m_hThemeHandle = 0;
  if ( gpfnIsThemeActive && gpfnIsThemeActive() )
  {
    v4 = (v2->baseclass.vtptr->GetName)(v2);
    v2->baseclass.m_hThemeHandle = gpfnOpenThemeData(v3, v4);
  }
  GetWindowRect(v2->m_OldWndProc, &Rect);
  v2->m_ptMinTrackSize.x = Rect.right - Rect.left;
  v2->m_ptMinTrackSize.y = Rect.bottom - Rect.top;
  v2->m_nWidth = v2->m_ptMinTrackSize.x;
  result = v2->m_ptMinTrackSize.y;
  v2->m_nHeight = result;
  return result;
}
// 1064D84: using guessed type int (__stdcall *gpfnIsThemeActive)();

//----- (00FADD40) --------------------------------------------------------
ULONG __userpurge sub_FADD40@<eax>(int a1@<ecx>, int a2@<edi>, int a3@<esi>, int a4, int a5)
{
  void *v5; // eax
  void *v6; // ebx
  ULONG v8; // esi
  char *v9; // [esp+0h] [ebp-20h]
  ULONG64 TraceHandle; // [esp+4h] [ebp-1Ch]
  int v11; // [esp+Ch] [ebp-14h]
  __int64 v12; // [esp+10h] [ebp-10h]
  int v13; // [esp+18h] [ebp-8h]

  *(a1 + 12) = a5;
  v9 = a1;
  TraceHandle = 0i64;
  v11 = 0;
  v12 = 0i64;
  v13 = 0;
  if ( a5 )
    sub_FB0200(L"A669021C-C450-4609-A035-5AF59AF4DF18", &v11);
  else
    sub_FB0200(L"E13C0D23-CCBC-4E12-931B-D9CC2EEE27E4", &v11);
  v5 = malloc(0x1078u);
  v6 = v5;
  if ( !v5 )
    return 14;
  memset(v5, 0, 0x1078u);
  *v6 = 4216;
  *(v6 + 11) = 0x20000;
  *(v6 + 16) = 16777472;
  *(v6 + 28) = 120;
  *(v6 + 27) = 2168;
  wcscpy_s(v6 + 60, 0x400u, L"ProcExpLogger");
  StartTraceW(&TraceHandle, v6 + 60, v6);
  ControlTraceW(0i64, v6 + 60, v6, 0);
  TraceHandle = *(v6 + 1);
  EnableTraceEx(&v11, 0, TraceHandle, HIDWORD(TraceHandle), 1, 4, 72, 0, 0, 0, 0, 0, a2, a3);
  sub_FAF840(v9, v6 + 60);
  TraceHandle = 0i64;
  v8 = ControlTraceW(0i64, v6 + 60, v6, 1u);
  free(v6);
  return v8;
}
// FADD40: could not find valid save-restore pair for edi
// FADD40: could not find valid save-restore pair for esi
// 103C960: using guessed type wchar_t aE13c0d23Ccbc4e[37];

//----- (00FADE80) --------------------------------------------------------
int __userpurge sub_FADE80@<eax>(int a1@<edi>, int *a2)
{
  a2[2] = sub_FADD40(*a2, a1, a2, **a2, a2[1]);
  return 0;
}

//----- (00FADEA0) --------------------------------------------------------
signed int __thiscall sub_FADEA0(void *this, int a2, DWORD ThreadId)
{
  void *v3; // esi
  signed int result; // eax
  int v5; // [esp+4h] [ebp-Ch]
  DWORD v6; // [esp+8h] [ebp-8h]
  int v7; // [esp+Ch] [ebp-4h]

  v6 = ThreadId;
  v5 = this;
  v3 = _beginthreadex(0, 0, sub_FADE80, &v5, 0, &ThreadId);
  if ( WaitForSingleObject(v3, 0x3A98u) == 258 )
  {
    TerminateThread(v3, 1u);
    CloseHandle(v3);
    result = 1460;
  }
  else
  {
    CloseHandle(v3);
    result = v7;
  }
  return result;
}

//----- (00FADF10) --------------------------------------------------------
int __thiscall sub_FADF10(DWORD *this)
{
  DWORD *v1; // edi
  void (__stdcall ***v2)(signed int); // ecx
  signed int v3; // ebx
  CTreeList *v4; // esi
  unsigned int v5; // eax
  IAtlStringMgr *v6; // ecx
  __m128i v7; // xmm0
  HMODULE v8; // eax
  HINSTANCE v9; // esi
  HWND v10; // eax
  HCURSOR v11; // eax
  LONG v12; // ecx
  int v13; // ST10_4
  int v14; // ecx
  HWND v15; // ST00_4
  int v16; // eax
  CTreeList *pTreeList_1; // esi
  char v18; // al
  Runtime *v19; // eax
  Runtime *v20; // eax
  Runtime *v21; // eax
  CTreeList *pTreeList; // [esp+10h] [ebp-68h]
  struct tagRECT Rect; // [esp+14h] [ebp-64h]
  RECT rc; // [esp+24h] [ebp-54h]
  struct tagRECT rcDst; // [esp+34h] [ebp-44h]
  int a2; // [esp+44h] [ebp-34h]
  int v28; // [esp+48h] [ebp-30h]
  char v29; // [esp+4Ch] [ebp-2Ch]
  const WCHAR *v30; // [esp+50h] [ebp-28h]
  int v31; // [esp+54h] [ebp-24h]
  char v32; // [esp+58h] [ebp-20h]
  const WCHAR *v33; // [esp+5Ch] [ebp-1Ch]
  int v34; // [esp+60h] [ebp-18h]
  char v35; // [esp+64h] [ebp-14h]
  int v36; // [esp+74h] [ebp-4h]

  v1 = this;
  v2 = this[6];
  v3 = 0;
  if ( v2 )
  {
    (**v2)(1);
    v1[6] = 0;
  }
  v4 = operator new(0x18u);
  pTreeList = v4;
  v36 = 0;
  if ( v4 )
  {
    v5 = *v1;
    LOBYTE(v36) = 1;
    v4->baseclass.vtptr = &Process::`vftable';
    v4->baseclass.m_hThemeHandle = v5;
    v6 = ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>::GetDefaultManager();
    if ( v6 == 0 )
      ATL::AtlThrowImpl(E_FAIL);
    v4->m_hWnd = ((v6->vtptr->GetNilData)() + 16);
    v4->m_hWndHeaderLeft = 0;
    v4->m_hWndTooltipOfLeftHeader = 0;
    v4->m_hWndHeaderRight = 0;
  }
  else
  {
    v4 = 0;
  }
  v7 = _mm_load_si128(&stru_103CB40);
  v36 = -1;
  v1[6] = v4;
  _mm_storeu_si128(&rc, v7);
  v8 = GetModuleHandleW(0);
  v9 = v8;
  v10 = CTreeList::Init(v1[2], v8, 0, 0x50810000, &rc);
  v1[1] = v10;
  pTreeList = CTreeList::GetTreeList(v10);
  CTreeList::UpdateSB(pTreeList, 0);
  v11 = LoadCursorW(v9, 0x6A);
  CTreeList::SetSplitterCursor(pTreeList, v11);
  sub_F9BDA0(pTreeList, 1);
  GetClientRect(v1[2], &Rect);
  CopyRect(&rcDst, &Rect);
  v12 = rcDst.right - 10;
  rcDst.bottom -= 10;
  rcDst.right = v12;
  v13 = rcDst.bottom - (rcDst.top + 10);
  v14 = v12 - (rcDst.left + 10);
  rcDst.left += 10;
  v15 = v1[1];
  rcDst.top += 10;
  MoveWindow(v15, rcDst.left, rcDst.top, v14, v13, 1);
  v16 = 800;
  pTreeList_1 = pTreeList;
  if ( rcDst.right - rcDst.left > 800 )
    v16 = rcDst.right - rcDst.left;
  a2 = L"Structure";
  v34 = v16;
  v28 = 200;
  v29 = 0;
  v30 = L"Flags";
  v31 = 80;
  v32 = 0;
  v33 = L"Path";
  v35 = 0;
  sub_F9D310(pTreeList, &a2, 3);
  if ( !ProcessIsNetCclr(*v1, &pTreeList) )
  {
    v18 = pTreeList;
    if ( pTreeList & 1 )
    {
      v19 = sub_FAEBA0(v1[6], *v1, 0xFFFF);
      ATL::CSimpleStringT<wchar_t,0>::SetString(v19 + 6, L"v1.0.3705", 9);
      v18 = pTreeList;
    }
    if ( v18 & 2 )
    {
      v20 = sub_FAEBA0(v1[6], *v1, 0xFFFE);
      ATL::CSimpleStringT<wchar_t,0>::SetString(v20 + 6, L"v1.1.4322", 9);
      v18 = pTreeList;
    }
    if ( v18 & 4 )
    {
      v21 = sub_FAEBA0(v1[6], *v1, 0xFFFD);
      ATL::CSimpleStringT<wchar_t,0>::SetString(v21 + 6, L"v2.0.50727", 10);
      v3 = sub_FADEA0(v1, *v1, 0);
      if ( v3 )
        return v3;
      v18 = pTreeList;
    }
    if ( !(v18 & 8) || (v3 = sub_FADEA0(v1, *v1, 1u)) == 0 )
      sub_FAD970(v1, pTreeList_1);
  }
  return v3;
}
// 103C8D0: using guessed type void *Process::`vftable';
// 103CA34: using guessed type wchar_t aStructure[10];
// 103CA48: using guessed type wchar_t aV103705[10];
// 103CA5C: using guessed type wchar_t aV114322[10];
// 103CA70: using guessed type wchar_t aV2050727[11];
// 103CB40: using guessed type RECT stru_103CB40;

//----- (00FAE1A0) --------------------------------------------------------
int __stdcall PageProcCclr(HWND hWnd, int a2, WPARAM a3, int a4)
{
  LONG v4; // esi
  int v5; // eax
  HGLOBAL v6; // ebx
  wchar_t *v7; // edi
  HWND v8; // ST38_4
  LRESULT v9; // eax
  HWND v10; // ST38_4
  unsigned int v11; // kr00_4
  unsigned int v12; // kr04_4
  wchar_t *v13; // ecx
  wchar_t v14; // ax
  int v15; // esi
  rsize_t v16; // esi
  HWND v17; // eax
  HWND v19; // ST2C_4
  CTreeList *v20; // eax
  int v21; // eax
  int v22; // eax
  HWND v23; // ST3C_4
  HWND v24; // eax
  HWND v25; // esi
  HWND v26; // eax
  LONG v27; // edi
  CResizer *v28; // eax
  _DWORD *v29; // eax
  DWORD *v30; // ebx
  HCURSOR v31; // eax
  HCURSOR v32; // esi
  HWND v33; // eax
  WPARAM v34; // [esp-8h] [ebp-827Ch]
  LPARAM lParam; // [esp+10h] [ebp-8264h]
  WPARAM wParam; // [esp+14h] [ebp-8260h]
  int v37; // [esp+18h] [ebp-825Ch]
  wchar_t *v38; // [esp+24h] [ebp-8250h]
  int v39; // [esp+28h] [ebp-824Ch]
  __int16 *v40; // [esp+44h] [ebp-8230h]
  int v41; // [esp+48h] [ebp-822Ch]
  struct tagPOINT Point; // [esp+4Ch] [ebp-8228h]
  WPARAM v43; // [esp+54h] [ebp-8220h]
  HWND hDlg; // [esp+58h] [ebp-821Ch]
  wchar_t v45; // [esp+5Ch] [ebp-8218h]
  wchar_t v46; // [esp+405Ch] [ebp-4218h]
  __int16 v47; // [esp+405Eh] [ebp-4216h]
  wchar_t Src; // [esp+805Ch] [ebp-218h]
  int v49; // [esp+8270h] [ebp-4h]

  hDlg = hWnd;
  v4 = GetWindowLongW(hWnd, -21);
  Point.y = v4;
  memset(&wParam, 0, 0x30u);
  if ( a2 > 0x4E )
  {
    if ( a2 == 272 )
    {
      v25 = hDlg;
      v26 = GetParent(hDlg);
      v27 = GetWindowLongW(v26, -21);
      v28 = operator new(0x40u);
      Point.y = v28;
      v49 = 0;
      if ( v28 )
        CResizer::CResizer(v28, v25);
      v49 = -1;
      PropSheet_UpdateTab(v25);
      if ( IsBuiltinAdministrative() && GetVersion() >= 6u )
      {
        v29 = operator new(0x28u);
        if ( v29 )
          v30 = sub_FAD260(v29);
        else
          v30 = 0;
        v30[2] = v25;
        *v30 = *(*(v27 + 4) + 68);
        v31 = LoadCursorW(0, 0x7F02);
        v32 = SetCursor(v31);
        sub_FADF10(v30);
        SendMessageW(v30[1], 0x30u, ghConfigFont, 0);
        SetCursor(v32);
        v25 = hDlg;
      }
      else
      {
        v30 = 0;
      }
      v33 = GetDlgItem(v25, 1610);
      ShowWindow(v33, v30 == 0);
      SetWindowLongW(v25, -21, v30);
      return 1;
    }
    if ( a2 == 273 )
    {
      switch ( a3 )
      {
        case 0x9C41u:
          v34 = 40014;
          goto LABEL_35;
        case 0x9C42u:
          SetEvent(ghRefreshEventHandle);
          return 0;
        case 0x9C9Cu:
        case 0x9C9Du:
          v34 = a3;
LABEL_35:
          v24 = GetParent(hDlg);
          PostMessageW(v24, 0x111u, v34, 0);
          return 0;
        default:
          return 0;
      }
    }
    return 0;
  }
  if ( a2 != 78 )
  {
    if ( a2 == 2 )
    {
      if ( v4 )
      {
        if ( *(v4 + 28) )
        {
          j__free(*(v4 + 28));
          *(v4 + 28) = 0;
          *(v4 + 32) = 0;
          *(v4 + 36) = 0;
        }
        j__free(v4);
      }
      return 1;
    }
    if ( a2 == 5 )
    {
      if ( v4 )
        sub_FB0130(v4);
      return 1;
    }
    return 0;
  }
  v5 = *(a4 + 8);
  if ( v5 != 2004 )
  {
    if ( v5 == 2005 )
    {
      if ( !*(a4 + 20) )
      {
        GetCursorPos(&Point);
        Point.y += 20;
        v19 = *a4;
        Point.x += 10;
        SetWindowPos(v19, 0, Point.x, Point.y, 0, 0, 0x15u);
        return 0;
      }
    }
    else if ( v5 == -155 && *(a4 + 12) == 67 )
    {
      if ( GetKeyState(162) )
      {
        v6 = 0;
        v7 = 0;
        v8 = *(v4 + 4);
        v41 = 0;
        v9 = SendMessageW(v8, 0x100Cu, wParam, 2);
        v43 = v9;
        if ( v9 != -1 )
        {
          do
          {
            v37 = 0;
            v38 = &Src;
            v10 = *(v4 + 4);
            v39 = 260;
            SendMessageW(v10, 0x1073u, v9, &lParam);
            v37 = 1;
            v38 = &v45;
            v39 = 0x2000;
            SendMessageW(*(v4 + 4), 0x1073u, v43, &lParam);
            v37 = 2;
            v38 = &v46;
            v39 = 0x2000;
            SendMessageW(*(v4 + 4), 0x1073u, v43, &lParam);
            v11 = wcslen(&Src);
            v12 = wcslen(&v45);
            v13 = &v46;
            v40 = &v47;
            do
            {
              v14 = *v13;
              ++v13;
            }
            while ( v14 );
            v15 = v11 + ((v13 - v40) >> 1) + v12 + v41 + 5;
            v41 += v11 + ((v13 - v40) >> 1) + v12 + 5;
            if ( v7 )
            {
              v6 = GlobalReAlloc(v6, 2 * v15 + 2, 0);
              v7 = GlobalLock(v6);
            }
            else
            {
              v6 = GlobalAlloc(0x2002u, 2 * v15 + 2);
              v7 = GlobalLock(v6);
              *v7 = 0;
            }
            v16 = v15 + 1;
            wcscat_s(v7, v16, &Src);
            wcscat_s(v7, v16, L"\t");
            wcscat_s(v7, v16, &v45);
            wcscat_s(v7, v16, L"\t");
            wcscat_s(v7, v16, &v46);
            wcscat_s(v7, v16, L"\r\n");
            GlobalUnlock(v6);
            v4 = Point.y;
            v9 = SendMessageW(*(Point.y + 4), 0x100Cu, v43, 2);
            v43 = v9;
          }
          while ( v9 != -1 );
          if ( v6 )
          {
            v17 = GetParent(hDlg);
            if ( OpenClipboard(v17) )
            {
              EmptyClipboard();
              SetClipboardData(0xDu, v6);
              CloseClipboard();
              return 0;
            }
          }
        }
      }
    }
    return 0;
  }
  if ( *(a4 + 20) || !v4 )
    return 0;
  v20 = CTreeList::GetTreeList(*(v4 + 4));
  CTreeList::GetTooltipOfTreeList(v20);
  v21 = sub_F9C420(*(a4 + 16));
  v22 = (*(*v21 + 24))(v21);
  v23 = hDlg;
  **(a4 + 24) = v22;
  SetWindowLongW(v23, 0, 1);
  return 1;
}

//----- (00FAE780) --------------------------------------------------------
BOOL __cdecl sub_FAE780(int a1, int a2)
{
  return *(a1 + 16) < *(a2 + 16);
}

//----- (00FAE7A0) --------------------------------------------------------
bool __cdecl sub_FAE7A0(int a1, int a2)
{
  return _wcsnicmp(*(a1 + 4), *(a2 + 4), 0x400u) < 0;
}

//----- (00FAE7D0) --------------------------------------------------------
LRESULT __thiscall CResizer::HandleMessage(WNDPROC *this, HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
  return CallWindowProcW(this[2], hWnd, Msg, wParam, lParam);
}

//----- (00FAE7F0) --------------------------------------------------------
int __stdcall sub_FAE7F0(int a1)
{
  return sub_FAF0A0(*(a1 + 96), a1);
}

//----- (00FAE810) --------------------------------------------------------
int __thiscall sub_FAE810(_DWORD *this, int a2, int a3)
{
  int v3; // eax
  int v4; // esi
  int *v5; // ebx
  int *v6; // edi
  int v8; // [esp+Ch] [ebp-4h]

  v3 = this[9];
  v4 = this[8];
  v8 = v3;
  if ( v4 == v3 )
    return 0;
  while ( 1 )
  {
    v5 = *(*v4 + 32);
    v6 = *(*v4 + 28);
    if ( v6 != v5 )
    {
      do
      {
        if ( sub_FAF710(*v6, a2, a3) )
          break;
        ++v6;
      }
      while ( v6 != v5 );
      v3 = v8;
      if ( v6 != v5 )
        break;
    }
    v4 += 4;
    if ( v4 == v3 )
      return 0;
  }
  return *v6;
}

//----- (00FAE870) --------------------------------------------------------
struct tagResizerItem *__thiscall CResizer::AddItem(CResizer *this, HWND hWndEdit, int a3)
{
  CResizer *this_1; // ebx
  struct tagResizerItem *result; // eax
  signed int dwItemCount; // edx
  signed int nIndex; // ecx
  LPRESIZERITEM pItem; // edi
  HWND *v8; // eax
  struct tagResizerItem *pNewItem; // edx
  DWORD dwItemCount_1; // eax
  tagResizerItem *pNewItem_1; // ebx
  CResizer *this_2; // [esp+8h] [ebp-4h]

  this_1 = this;
  this_2 = this;
  if ( !hWndEdit )
    return 0;
  dwItemCount = this->m_dwItemCount;
  nIndex = 0;
  if ( dwItemCount <= 0 )
  {
LABEL_7:
    if ( a3 )
    {
      this_1->m_dwItemCount = dwItemCount + 1;
      pNewItem = realloc(this_1->m_pItem, sizeof(tagResizerItem) * (dwItemCount + 1));
      if ( !pNewItem )
      {
        a3 = 8;
        _CxxThrowException(&a3, &_TI1J);
      }
      dwItemCount_1 = this_1->m_dwItemCount;
      this_1->m_pItem = pNewItem;
      pNewItem_1 = &pNewItem[dwItemCount_1];
      pNewItem_1[-1].m_hWnd = hWndEdit;
      pNewItem_1[-1].m_rect1 = stru_103CB50;
      pNewItem_1[-1].m_rect2 = stru_103CB50;
      GetWindowRect(hWndEdit, &pNewItem_1[-1].m_rcWindow);
      ScreenToClient(this_2->m_OldWndProc, &pNewItem_1[-1].m_rcWindow);
      ScreenToClient(this_2->m_OldWndProc, &pNewItem_1[-1].m_rcWindow.right);
      result = pNewItem_1 - 1;
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    pItem = this_1->m_pItem;
    v8 = &pItem->m_hWnd;
    while ( *v8 != hWndEdit )
    {
      ++nIndex;
      v8 += 14;
      if ( nIndex >= dwItemCount )
        goto LABEL_7;
    }
    result = &pItem[nIndex];
  }
  return result;
}
// 10081AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);
// 103CB50: using guessed type RECT stru_103CB50;
// 1054A54: using guessed type int _TI1J;

//----- (00FAE970) --------------------------------------------------------
int __cdecl sub_FAE970(wchar_t *Dst, rsize_t SizeInWords, int a3, int a4, int a5)
{
  int result; // eax
  char v6; // cl
  int v7; // esi
  int v8; // edx

  result = 0;
  *Dst = 0;
  if ( a3 )
  {
    v6 = 1;
    result = a5;
    v7 = 0;
    if ( a5 > 0 )
    {
      result = a4;
      v8 = a5;
      do
      {
        if ( a3 & *(result + 8 * v7) )
        {
          if ( !v6 )
          {
            wcscat_s(Dst, SizeInWords, L", ");
            result = a4;
          }
          wcscat_s(Dst, SizeInWords, *(result + 8 * v7 + 4));
          result = a4;
          v8 = a5;
          v6 = 0;
        }
        ++v7;
      }
      while ( v7 < v8 );
    }
  }
  return result;
}

//----- (00FAE9F0) --------------------------------------------------------
__int16 __thiscall sub_FAE9F0(_WORD *this)
{
  _WORD *v1; // eax
  bool v2; // zf

  v1 = this + 6;
  if ( this[6] )
  {
    do
    {
      v2 = v1[1] == 0;
      ++v1;
    }
    while ( !v2 );
  }
  return v1[3];
}

//----- (00FAEA10) --------------------------------------------------------
__int16 __thiscall sub_FAEA10(_WORD *this)
{
  _WORD *v1; // eax
  bool v2; // zf

  v1 = this + 14;
  if ( this[14] )
  {
    do
    {
      v2 = v1[1] == 0;
      ++v1;
    }
    while ( !v2 );
  }
  return v1[1];
}

//----- (00FAEA30) --------------------------------------------------------
__int16 __thiscall sub_FAEA30(_WORD *this)
{
  _WORD *i; // eax
  _WORD *v2; // eax
  bool v3; // zf

  for ( i = this + 12; *i; ++i )
    ;
  v2 = i + 1;
  if ( *v2 )
  {
    do
    {
      v3 = v2[1] == 0;
      ++v2;
    }
    while ( !v3 );
  }
  return v2[1];
}

//----- (00FAEA70) --------------------------------------------------------
HWND __thiscall CTreeList::GetTooltipOfLeftHeader(CTreeList *this)
{
  return this->m_hWndTooltipOfLeftHeader;
}

//----- (00FAEA80) --------------------------------------------------------
const WCHAR **sub_FAEA80()
{
  return &gszNullString;
}

//----- (00FAEA90) --------------------------------------------------------
int __thiscall sub_FAEA90(_WORD *this)
{
  _WORD *v1; // eax
  bool v2; // zf

  v1 = this + 6;
  if ( this[6] )
  {
    do
    {
      v2 = v1[1] == 0;
      ++v1;
    }
    while ( !v2 );
  }
  return *(v1 + 1);
}

//----- (00FAEAB0) --------------------------------------------------------
_WORD *__thiscall sub_FAEAB0(_WORD *this)
{
  _WORD *i; // eax

  for ( i = this + 12; *i; ++i )
    ;
  return i + 1;
}

//----- (00FAEAD0) --------------------------------------------------------
AppDomain *__thiscall sub_FAEAD0(_DWORD *this, int a2, AppDomain *a3)
{
  int *v3; // esi
  int *v4; // edi
  AppDomain *v5; // ebx
  AppDomain *v7; // eax
  AppDomain *v8; // eax
  std__vector *v9; // [esp+14h] [ebp-10h]

  v3 = this[9];
  v4 = this[8];
  v5 = a3;
  v9 = (this + 8);
  if ( v4 != v3 )
  {
    do
    {
      if ( sub_FAF710(*v4, a2, v5) )
        break;
      ++v4;
    }
    while ( v4 != v3 );
    if ( v4 != v3 )
      return *v4;
  }
  v7 = operator new(0x28u);
  if ( v7 )
    v8 = AppDomain::AppDomain(v7, a2, v5);
  else
    v8 = 0;
  a3 = v8;
  std::vector<tagAccountInfo *,std::allocator<tagAccountInfo *>>::push_back(v9, &a3);
  return a3;
}

//----- (00FAEBA0) --------------------------------------------------------
Runtime *__thiscall sub_FAEBA0(_DWORD *this, unsigned int a2, Runtime *a3)
{
  std__vector *v3; // ebx
  int *v4; // esi
  int *v5; // edi
  void *v7; // eax
  Runtime *v8; // eax
  unsigned int v9; // [esp+10h] [ebp-18h]
  __int16 v10; // [esp+14h] [ebp-14h]
  void *v11; // [esp+18h] [ebp-10h]
  int v12; // [esp+24h] [ebp-4h]

  v3 = (this + 3);
  v4 = this[4];
  v5 = this[3];
  v9 = a2;
  v10 = a3;
  if ( v5 != v4 )
  {
    do
    {
      if ( sub_FAF730(*v5, &v9) )
        break;
      ++v5;
    }
    while ( v5 != v4 );
    if ( v5 != v4 )
      return *v5;
  }
  v7 = operator new(0x38u);
  v11 = v7;
  v12 = 0;
  if ( v7 )
    v8 = Runtime::Runtime(v7, a2, a3);
  else
    v8 = 0;
  a3 = v8;
  v12 = -1;
  std::vector<tagAccountInfo *,std::allocator<tagAccountInfo *>>::push_back(v3, &a3);
  return a3;
}

//----- (00FAEC70) --------------------------------------------------------
int __cdecl ProcessIsNetCclr(DWORD th32ProcessID, PDWORD pdwFlags)
{
  DWORD dwFlags; // esi
  HANDLE hFound; // eax
  void *FoundHandle; // edi
  int result; // eax
  char v6; // bl
  wchar_t *pszFileName; // eax
  wchar_t *pszFileName_1; // eax
  int pszText; // edx
  __int16 *v10; // ecx
  int v11; // ebx
  __int16 v12; // ax
  int chText; // eax
  char v14; // [esp+13h] [ebp-42Dh]
  MODULEENTRY32W ModuleEntry; // [esp+14h] [ebp-42Ch]

  dwFlags = 0;
  v14 = 0;
  *pdwFlags = 0;
  do
  {
    hFound = CreateToolhelp32Snapshot(0x18u, th32ProcessID);// TH32CS_SNAPMODULE32|TH32CS_SNAPMODULE
    FoundHandle = hFound;
  }
  while ( hFound == ERROR_BAD_LENGTH );
  if ( hFound == INVALID_HANDLE_VALUE )
    return 0;
  ModuleEntry.dwSize = sizeof(MODULEENTRY32W);
  if ( !Module32FirstW(hFound, &ModuleEntry) )
  {
    CloseHandle(FoundHandle);
    result = GetLastError();
    if ( result > 0 )
      result = result | 0x80070000;
    return result;
  }
  do
  {
    if ( wcsstr(ModuleEntry.szModule, L"mscorlib") )
    {
      v6 = 1;
      v14 = 1;
      continue;
    }
    if ( !_wcsicmp(ModuleEntry.szModule, L"clr.dll")
      || !_wcsicmp(ModuleEntry.szModule, L"mscorwks.dll")
      || !_wcsicmp(ModuleEntry.szModule, L"mscorsvr.dll") )
    {
      pszFileName = wcsrchr(ModuleEntry.szExePath, '\\');
      if ( pszFileName )
      {
        *pszFileName = 0;
        pszFileName_1 = wcsrchr(ModuleEntry.szExePath, '\\');
        if ( pszFileName_1 )
        {
          pszText = (pszFileName_1 + 1);
          v10 = (pszFileName_1 + 1);
          v11 = (pszFileName_1 + 2);
          do
          {
            v12 = *v10;
            ++v10;
          }
          while ( v12 );
          if ( ((v10 - v11) >> 1) >= 4 )
          {
            chText = *(pszText + 2);
            if ( chText != '1' )
              goto LABEL_22;
            if ( *(pszText + 6) == '0' )
            {
              dwFlags |= 1u;
            }
            else
            {
              if ( *(pszText + 6) != '1' )
              {
LABEL_22:
                if ( chText == '2' )
                {
                  dwFlags |= 4u;
                }
                else if ( chText == '4' || chText == '5' || chText == '6' || chText == '7' )
                {
                  dwFlags |= 8u;
                }
                goto __continue;
              }
              dwFlags |= 2u;
            }
          }
        }
      }
    }
__continue:
    v6 = v14;
  }
  while ( Module32NextW(FoundHandle, &ModuleEntry) );
  CloseHandle(FoundHandle);
  if ( v6 && dwFlags )
    *pdwFlags = dwFlags;
  return 0;
}

//----- (00FAEE50) --------------------------------------------------------
wchar_t *__thiscall sub_FAEE50(_DWORD *this, int a2, int a3, wchar_t *Dst, int a5)
{
  wchar_t *result; // eax

  if ( a3 )
  {
    if ( a3 == 1 )
    {
      result = this[5];
    }
    else
    {
      result = Dst;
      *Dst = 0;
    }
  }
  else
  {
    swprintf_s(Dst, *a5, L"Appdomain: %s", this[6]);
    result = Dst;
  }
  return result;
}