
//----- (00C01780) --------------------------------------------------------
CSystemProcessInfoMapNode *std::_Tree_comp_alloc<std::_Tmap_traits<unsigned long,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *>>,0>>::_Buyheadnode()
{
  CSystemProcessInfoMapNode *result; // eax

  result = (CSystemProcessInfoMapNode *)operator new(0x18u);
  JUMPOUT(result, 0, std::_Xbad_alloc);
  result->baseclass._Left = result;
  if ( result != (CSystemProcessInfoMapNode *)-4 )
    result->baseclass._Parent = result;
  if ( result != (CSystemProcessInfoMapNode *)-8 )
    result->baseclass._Right = result;
  *(_WORD *)&result->baseclass._Color = 257;
  return result;
}

//----- (00C017B0) --------------------------------------------------------
CSystemProcessInfoMapNode *__thiscall std::_Tree_comp_alloc<std::_Tmap_traits<unsigned long,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *>>,0>>::_Buynode0(CSystemProcessInfoMap *this)
{
  CSystemProcessInfoMapNode **this_1; // esi
  CSystemProcessInfoMapNode *v2; // edx

  this_1 = (CSystemProcessInfoMapNode **)this;
  v2 = (CSystemProcessInfoMapNode *)operator new(0x18u);
  if ( !v2 )
    std::_Xbad_alloc();
  v2->baseclass._Left = *this_1;
  if ( v2 != (CSystemProcessInfoMapNode *)-4 )
    v2->baseclass._Parent = *this_1;
  if ( v2 != (CSystemProcessInfoMapNode *)-8 )
    v2->baseclass._Right = *this_1;
  return v2;
}

//----- (00C017F0) --------------------------------------------------------
std__list_node *__thiscall sub_C017F0(int **this, int a2)
{
  int **v2; // esi
  int v3; // edi
  std__list_node *v4; // edx
  int *v5; // eax
  std__list_node *result; // eax

  v2 = this;
  v3 = **this;
  v4 = std::_List_buy<tagEventItem *,std::allocator<tagEventItem *>>::_Buynode<tagEventItem * const &>(
         (EventList *)**this,
         *(_DWORD **)(v3 + 4),
         (_DWORD *)a2);
  v5 = v2[1];
  if ( (unsigned int)(357913940 - (_DWORD)v5) < 1 )
    std::_Xlength_error("list<T> too long");
  v2[1] = (int *)((char *)v5 + 1);
  *(_DWORD *)(v3 + 4) = v4;
  result = v4->_Prev;
  result->_Next = v4;
  return result;
}

//----- (00C01840) --------------------------------------------------------
void *__cdecl sub_C01840(int a1)
{
  void *v1; // eax

  v1 = sub_C01860(a1, (void *)0xFFFFFFFF, 1);
  return sub_C01860(a1, v1, 0);
}

//----- (00C01860) --------------------------------------------------------
void *__cdecl sub_C01860(int a1, void *a2, char a3)
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
  WCHAR *v23; // esi
  signed int v24; // esi
  char v25; // bl
  int a8; // [esp+10h] [ebp-C9Ch]
  void *v28; // [esp+14h] [ebp-C98h]
  int v29; // [esp+18h] [ebp-C94h]
  void *v30; // [esp+1Ch] [ebp-C90h]
  unsigned int v31; // [esp+20h] [ebp-C8Ch]
  void *v32; // [esp+24h] [ebp-C88h]
  CCmdString v33; // [esp+28h] [ebp-C84h]
  FILE *v34; // [esp+2Ch] [ebp-C80h]
  void *v35; // [esp+30h] [ebp-C7Ch]
  CCmdString strText; // [esp+34h] [ebp-C78h]
  void *v37; // [esp+38h] [ebp-C74h]
  int v38; // [esp+3Ch] [ebp-C70h]
  void *v39; // [esp+40h] [ebp-C6Ch]
  CCmdString v40; // [esp+44h] [ebp-C68h]
  void *v41; // [esp+48h] [ebp-C64h]
  void *v42; // [esp+4Ch] [ebp-C60h]
  int a2a; // [esp+50h] [ebp-C5Ch]
  int v44; // [esp+54h] [ebp-C58h]
  BOOL v45; // [esp+5Ch] [ebp-C50h]
  void *v46; // [esp+60h] [ebp-C4Ch]
  void *v47; // [esp+64h] [ebp-C48h]
  void *v48; // [esp+68h] [ebp-C44h]
  CCmdString v49; // [esp+6Ch] [ebp-C40h]
  void *v50; // [esp+70h] [ebp-C3Ch]
  CCmdString str3; // [esp+74h] [ebp-C38h]
  CCmdString strId; // [esp+78h] [ebp-C34h]
  CCmdString str1; // [esp+7Ch] [ebp-C30h]
  CCmdString str2; // [esp+80h] [ebp-C2Ch]
  wchar_t *ppv3; // [esp+84h] [ebp-C28h]
  CCmdString strValue; // [esp+88h] [ebp-C24h]
  wchar_t v57; // [esp+8Ch] [ebp-C20h]
  char v58; // [esp+94h] [ebp-C18h]
  wchar_t v59; // [esp+96h] [ebp-C16h]
  __int16 v60; // [esp+88Ah] [ebp-422h]
  WCHAR Buffer; // [esp+88Ch] [ebp-420h]
  int v62; // [esp+CA8h] [ebp-4h]

  v29 = a1;
  v46 = malloc(2u);
  *(_WORD *)v46 = 0;
  v62 = 0;
  v41 = malloc(2u);
  *(_WORD *)v41 = 0;
  strValue.m_String = (WCHAR *)malloc(2u);
  *strValue.m_String = 0;
  v47 = malloc(2u);
  *(_WORD *)v47 = 0;
  v3 = 0;
  v45 = 0;
  v40.m_String = (WCHAR *)malloc(2u);
  *v40.m_String = 0;
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
    *(_DWORD *)v6 = *(_DWORD *)L"\\win.ini";
    *((_DWORD *)v6 + 1) = *(_DWORD *)L"in.ini";
    *((_DWORD *)v6 + 2) = *(_DWORD *)L".ini";
    *((_DWORD *)v6 + 3) = *(_DWORD *)L"ni";
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
  if ( a2 == (void *)-1 )
  {
    v49.m_String = _wcsdup((const wchar_t *)&gszNullString);
    v48 = _wcsdup((const wchar_t *)&gszNullString);
    v50 = _wcsdup((const wchar_t *)&gszNullString);
    str1.m_String = _wcsdup((const wchar_t *)&gszNullString);
    strId.m_String = _wcsdup((const wchar_t *)&gszNullString);
    str3.m_String = _wcsdup((const wchar_t *)&gszNullString);
    str2.m_String = _wcsdup(&Buffer);
    ppv3 = _wcsdup(&Buffer);
    LOBYTE(v62) = 12;
    a2 = (void *)PE_UpdateSystemKey(a1, 2u, (HANDLE)0xFFFFFFFF, 0, (CCmdString *)&ppv3, &str2, &str3);
    free(ppv3);
    free(str2.m_String);
    free(str3.m_String);
    free(strId.m_String);
    free(str1.m_String);
    free(v50);
    free(v48);
    LOBYTE(v62) = 4;
    free(v49.m_String);
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
            sub_BE6DD0(v11, 44, (int)&v42, 0);
            v14 = a2a;
            v15 = (char *)v42;
            v31 = 0;
            if ( (a2a - (signed int)v42) >> 4 )
            {
              v16 = 0;
              v38 = 0;
              do
              {
                v17 = *(const wchar_t **)&v15[v16];
                v18 = v47;
                v19 = (int)&v15[v16];
                v47 = _wcsdup(v17);
                free(v18);
                v20 = v19;
                v21 = v29;
                v22 = (const wchar_t **)sub_BE4EE0((int)&v28, v29, v20, 0);
                v23 = strValue.m_String;
                strValue.m_String = _wcsdup(*v22);
                free(v23);
                free(v28);
                if ( *strValue.m_String )
                {
                  v24 = sub_BE4ED0();
                  v50 = _wcsdup(&Buffer);
                  v48 = _wcsdup(&Buffer);
                  v49.m_String = _wcsdup(v11);
                  LOBYTE(v62) = 16;
                  v25 = sub_BE3D40(
                          v21,
                          (CCmdString)&v49,
                          (int)&v48,
                          (int)&v50,
                          (int)&strValue,
                          (int)&v46,
                          (CCmdString)&v40,
                          (int)&a8);
                  free(v49.m_String);
                  free(v48);
                  LOBYTE(v62) = 13;
                  free(v50);
                  if ( v25 )
                  {
                    if ( a2 == (void *)-1 )
                    {
                      v37 = _wcsdup((const wchar_t *)&gszNullString);
                      v30 = _wcsdup((const wchar_t *)&gszNullString);
                      v32 = _wcsdup((const wchar_t *)&gszNullString);
                      v39 = _wcsdup((const wchar_t *)&gszNullString);
                      str2.m_String = _wcsdup((const wchar_t *)&gszNullString);
                      str3.m_String = _wcsdup((const wchar_t *)&gszNullString);
                      strId.m_String = _wcsdup(&Buffer);
                      str1.m_String = _wcsdup(&Buffer);
                      LOBYTE(v62) = 24;
                      a2 = (void *)PE_UpdateSystemKey(v21, 2u, (HANDLE)0xFFFFFFFF, 0, &str1, &strId, &str3);
                      free(str1.m_String);
                      free(strId.m_String);
                      free(str3.m_String);
                      free(str2.m_String);
                      free(v39);
                      free(v32);
                      free(v30);
                      free(v37);
                    }
                    v35 = _wcsdup((const wchar_t *)&gszNullString);
                    v33.m_String = _wcsdup(&Buffer);
                    v11 = ppv3;
                    strText.m_String = _wcsdup(ppv3);
                    LOBYTE(v62) = 27;
                    PE_UpdateSystemKey(v21, v24, a2, 4u, &strText, &v33, &strValue);
                    free(strText.m_String);
                    free(v33.m_String);
                    LOBYTE(v62) = 13;
                    free(v35);
                  }
                  else
                  {
                    v11 = ppv3;
                  }
                }
                v14 = a2a;
                v15 = (char *)v42;
                v16 = v38 + 16;
                ++v31;
                v38 += 16;
              }
              while ( v31 < (a2a - (signed int)v42) >> 4 );
              v9 = v34;
            }
            LOBYTE(v62) = 4;
            if ( v15 )
            {
              sub_BE2BF0((int)v15, v14);
              operator delete(v42);
              v42 = 0;
              a2a = 0;
              v44 = 0;
            }
            v3 = v45;
            continue;
          }
          if ( !_wcsnicmp(&v57, L"run=", 4u) )
          {
            v11 = (wchar_t *)&v58;
            goto LABEL_19;
          }
        }
      }
      while ( fgetws(&v57, 1024, v9) );
    }
    fclose(v9);
  }
  free(v40.m_String);
  free(v47);
  free(strValue.m_String);
  free(v41);
  free(v46);
  return a2;
}
// CA2C50: using guessed type wchar_t aAutorunsdisabl_1[22];
// CA2C7C: using guessed type wchar_t aWinIni[9];

//----- (00C02060) --------------------------------------------------------
void __cdecl sub_C02060(int a1, void *a2, void *a3)
{
  _WORD *v3; // ST50_4
  CCmdString *v4; // esi
  void *v5; // edi
  CCmdString *v6; // eax
  wchar_t *v7; // ST54_4

  v3 = malloc(2u);
  *v3 = 0;
  v4 = (CCmdString *)a3;
  v5 = sub_C02110(a1, a2, *(wchar_t **)a3, (void *)0xFFFFFFFF);
  v6 = CCmdString::operator+((CCmdString *)&a3, v4, L"\\AutorunsDisabled");
  v7 = _wcsdup(v6->m_String);
  free(v3);
  free(a3);
  sub_C02110(a1, a2, v7, v5);
  free(v7);
}

//----- (00C02110) --------------------------------------------------------
void *__cdecl sub_C02110(int a1, void *a2, wchar_t *psz, void *a4)
{
  DWORD v4; // ebx
  const wchar_t *v5; // eax
  const wchar_t *v6; // eax
  CCmdString *v7; // esi
  CCmdString *v8; // eax
  unsigned int v9; // eax
  const WCHAR *v10; // esi
  unsigned int v11; // eax
  void *v12; // esi
  const wchar_t **v13; // eax
  WCHAR *v14; // esi
  const wchar_t *v15; // ecx
  const wchar_t *v16; // eax
  CCmdString *v17; // esi
  CCmdString *v18; // eax
  char v19; // bl
  const wchar_t *v20; // eax
  const wchar_t *v21; // eax
  HKEY v22; // ebx
  CCmdString *v23; // esi
  CCmdString *v24; // eax
  const wchar_t *v25; // eax
  CCmdString *v26; // eax
  CCmdString strResult[7]; // [esp+10h] [ebp-A0h]
  int a2a; // [esp+2Ch] [ebp-84h]
  void *v30; // [esp+30h] [ebp-80h]
  int a8; // [esp+34h] [ebp-7Ch]
  WCHAR v32[2]; // [esp+38h] [ebp-78h]
  WCHAR v33[2]; // [esp+3Ch] [ebp-74h]
  DWORD v34; // [esp+40h] [ebp-70h]
  void *v35; // [esp+44h] [ebp-6Ch]
  HKEY hKey; // [esp+48h] [ebp-68h]
  void *v37; // [esp+4Ch] [ebp-64h]
  void *v38; // [esp+50h] [ebp-60h]
  void *v39; // [esp+54h] [ebp-5Ch]
  WCHAR *ppv3; // [esp+58h] [ebp-58h]
  void *v41; // [esp+5Ch] [ebp-54h]
  void *a1a; // [esp+60h] [ebp-50h]
  CCmdString ppv; // [esp+64h] [ebp-4Ch]
  void *v44; // [esp+68h] [ebp-48h]
  HKEY hRootKey; // [esp+6Ch] [ebp-44h]
  WCHAR szArg[2]; // [esp+70h] [ebp-40h]
  LPCWSTR szKeyName; // [esp+74h] [ebp-3Ch]
  LPCWSTR v48; // [esp+78h] [ebp-38h]
  LPCWSTR v49; // [esp+7Ch] [ebp-34h]
  LPCWSTR v50; // [esp+80h] [ebp-30h]
  LPCWSTR v51; // [esp+84h] [ebp-2Ch]
  LPCWSTR szArg3; // [esp+88h] [ebp-28h]
  LPCWSTR v53; // [esp+8Ch] [ebp-24h]
  WCHAR *pszText; // [esp+90h] [ebp-20h]
  LPCWSTR szArg4; // [esp+94h] [ebp-1Ch]
  LPCWSTR v56; // [esp+98h] [ebp-18h]
  CCmdString str3; // [esp+9Ch] [ebp-14h]
  LPCWSTR lpszKeyName; // [esp+A0h] [ebp-10h]
  int v59; // [esp+ACh] [ebp-4h]

  v4 = 0;
  v34 = 0;
  ppv.m_String = (WCHAR *)malloc(2u);
  *ppv.m_String = 0;
  v59 = 0;
  str3.m_String = (WCHAR *)malloc(2u);
  *str3.m_String = 0;
  v44 = malloc(2u);
  *(_WORD *)v44 = 0;
  v41 = malloc(2u);
  *(_WORD *)v41 = 0;
  v39 = malloc(2u);
  *(_WORD *)v39 = 0;
  ppv3 = (WCHAR *)malloc(2u);
  *ppv3 = 0;
  LOBYTE(v59) = 5;
  if ( a4 == (void *)-1 )
  {
    v50 = _wcsdup((const wchar_t *)&gszNullString);
    v56 = _wcsdup((const wchar_t *)&gszNullString);
    szKeyName = _wcsdup((const wchar_t *)&gszNullString);
    v49 = _wcsdup((const wchar_t *)&gszNullString);
    v51 = _wcsdup((const wchar_t *)&gszNullString);
    v53 = _wcsdup((const wchar_t *)&gszNullString);
    szArg4 = _wcsdup((const wchar_t *)&gszNullString);
    v5 = (const wchar_t *)&gszNullString;
    if ( psz )
      v5 = psz;
    pszText = _wcsdup(v5);
    v48 = _wcsdup((const wchar_t *)&gszNullString);
    v6 = (const wchar_t *)&gszNullString;
    if ( psz )
      v6 = psz;
    szArg3 = _wcsdup(v6);
    LOBYTE(v59) = 15;
    v7 = MakeRegistryKeyName((CCmdString *)&a1a, (HKEY)a2, (CCmdString *)&pszText, (CCmdString *)&szArg4);
    LOBYTE(v59) = 16;
    v8 = MakeRegistryKeyName((CCmdString *)szArg, (HKEY)a2, (CCmdString *)&szArg3, (CCmdString *)&v48);
    LOBYTE(v59) = 17;
    a4 = (void *)PE_UpdateSystemKey(a1, 0, (HANDLE)0xFFFFFFFF, 0, v8, v7, (CCmdString *)&v53);
    free(*(void **)szArg);
    free(a1a);
    free((void *)szArg3);
    free((void *)v48);
    free(pszText);
    free((void *)szArg4);
    free((void *)v53);
    free((void *)v51);
    free((void *)v49);
    free((void *)szKeyName);
    free((void *)v56);
    LOBYTE(v59) = 5;
    free((void *)v50);
  }
  v9 = (unsigned int)TlsGetValue(gdwTlsIndex);
  if ( !PE_OpenKey(ghLocalMachineKey, psz, 0, v9 | 0x20019, &hRootKey) )
  {
    lpszKeyName = (LPCWSTR)malloc(2u);
    *lpszKeyName = 0;
    LOBYTE(v59) = 18;
    if ( !PE_LoadRegKeys(hRootKey, 0, (CCmdString *)&lpszKeyName) )
    {
      do
      {
        v10 = lpszKeyName;
        v11 = (unsigned int)TlsGetValue(gdwTlsIndex);
        if ( !PE_OpenKey(hRootKey, v10, 0, v11 | 0x20019, &hKey) )
        {
          if ( !PE_ReadRegKey(hKey, L"Dllname", 0, 0, &ppv) )
          {
            strResult[0].m_String = (WCHAR *)malloc(2u);
            *strResult[0].m_String = 0;
            strResult[1].m_String = 0;
            strResult[2].m_String = 0;
            strResult[3].m_String = 0;
            LOBYTE(v59) = 19;
            sub_BE7040(ppv.m_String, (StringItem *)strResult);
            v12 = v44;
            v44 = _wcsdup(ppv.m_String);
            free(v12);
            v13 = (const wchar_t **)sub_BE4EE0((int)&v30, a1, (int)strResult, 0);
            v14 = str3.m_String;
            str3.m_String = _wcsdup(*v13);
            free(v14);
            free(v30);
            a2a = sub_BE4ED0();
            v15 = (const wchar_t *)&gszNullString;
            if ( psz )
              v15 = psz;
            szKeyName = _wcsdup(v15);
            v56 = _wcsdup((const wchar_t *)&gszNullString);
            v16 = (const wchar_t *)&gszNullString;
            if ( psz )
              v16 = psz;
            v50 = _wcsdup(v16);
            LOBYTE(v59) = 22;
            v17 = MakeRegistryKeyName((CCmdString *)v33, (HKEY)a2, (CCmdString *)&szKeyName, (CCmdString *)&lpszKeyName);
            LOBYTE(v59) = 23;
            v18 = MakeRegistryKeyName(&strResult[6], (HKEY)a2, (CCmdString *)&v50, (CCmdString *)&v56);
            LOBYTE(v59) = 24;
            v19 = sub_BE3D40(
                    a1,
                    (CCmdString)&lpszKeyName,
                    (int)v18,
                    (int)v17,
                    (int)&str3,
                    (int)&v41,
                    (CCmdString)&ppv3,
                    (int)&a8);
            free(strResult[6].m_String);
            free(*(void **)v33);
            free((void *)v50);
            free((void *)v56);
            free((void *)szKeyName);
            if ( v19 )
            {
              if ( a4 == (void *)-1 )
              {
                v37 = _wcsdup((const wchar_t *)&gszNullString);
                v35 = _wcsdup((const wchar_t *)&gszNullString);
                v38 = _wcsdup((const wchar_t *)&gszNullString);
                szArg3 = _wcsdup((const wchar_t *)&gszNullString);
                v48 = _wcsdup((const wchar_t *)&gszNullString);
                pszText = _wcsdup((const wchar_t *)&gszNullString);
                szArg4 = _wcsdup((const wchar_t *)&gszNullString);
                v20 = (const wchar_t *)&gszNullString;
                if ( psz )
                  v20 = psz;
                v53 = _wcsdup(v20);
                v51 = _wcsdup((const wchar_t *)&gszNullString);
                v21 = (const wchar_t *)&gszNullString;
                if ( psz )
                  v21 = psz;
                v49 = _wcsdup(v21);
                v22 = (HKEY)a2;
                LOBYTE(v59) = 34;
                v23 = MakeRegistryKeyName((CCmdString *)v32, (HKEY)a2, (CCmdString *)&v53, (CCmdString *)&szArg4);
                LOBYTE(v59) = 35;
                v24 = MakeRegistryKeyName(&strResult[4], (HKEY)a2, (CCmdString *)&v49, (CCmdString *)&v51);
                LOBYTE(v59) = 36;
                a4 = (void *)PE_UpdateSystemKey(a1, 0, (HANDLE)0xFFFFFFFF, 0, v24, v23, (CCmdString *)&pszText);
                free(strResult[4].m_String);
                free(*(void **)v32);
                free((void *)v49);
                free((void *)v51);
                free((void *)v53);
                free((void *)szArg4);
                free(pszText);
                free((void *)v48);
                free((void *)szArg3);
                free(v38);
                free(v35);
                free(v37);
              }
              else
              {
                v22 = (HKEY)a2;
              }
              *(_DWORD *)szArg = _wcsdup((const wchar_t *)&gszNullString);
              v25 = (const wchar_t *)&gszNullString;
              if ( psz )
                v25 = psz;
              a1a = _wcsdup(v25);
              LOBYTE(v59) = 38;
              v26 = MakeRegistryKeyName(&strResult[5], v22, (CCmdString *)&a1a, (CCmdString *)&lpszKeyName);
              LOBYTE(v59) = 39;
              PE_UpdateSystemKey(a1, a2a, a4, 3u, (CCmdString *)&lpszKeyName, v26, &str3);
              free(strResult[5].m_String);
              free(a1a);
              free(*(void **)szArg);
            }
            LOBYTE(v59) = 18;
            StringItem::~StringItem((tagPEStringStruct *)strResult);
            v4 = v34;
          }
          RegCloseKey(hKey);
        }
        v34 = ++v4;
      }
      while ( !PE_LoadRegKeys(hRootKey, v4, (CCmdString *)&lpszKeyName) );
    }
    RegCloseKey(hRootKey);
    free((void *)lpszKeyName);
  }
  free(ppv3);
  free(v39);
  free(v41);
  free(v44);
  free(str3.m_String);
  free(ppv.m_String);
  return a4;
}

//----- (00C027D0) --------------------------------------------------------
void __cdecl sub_C027D0(int a1, OLECHAR *psz)
{
  _WORD *v2; // edi
  _WORD *v3; // ebx
  _WORD *v4; // esi
  CCmdString *v5; // eax
  int v6; // edi
  DWORD v7; // ebx
  const WCHAR *v8; // esi
  unsigned int v9; // eax
  const wchar_t **v10; // eax
  WCHAR *v11; // esi
  wchar_t *v12; // esi
  wchar_t *v13; // eax
  CCmdString *v14; // eax
  wchar_t *v15; // esi
  HMODULE v16; // eax
  CCmdString *v17; // esi
  CCmdString *v18; // eax
  CCmdString *v19; // esi
  CCmdString *v20; // eax
  CCmdString *v21; // eax
  CCmdString strCmd[7]; // [esp+10h] [ebp-2D4h]
  WCHAR v23[2]; // [esp+2Ch] [ebp-2B8h]
  WCHAR v24[2]; // [esp+30h] [ebp-2B4h]
  _WORD *v25; // [esp+34h] [ebp-2B0h]
  int a8; // [esp+38h] [ebp-2ACh]
  _WORD *v27; // [esp+3Ch] [ebp-2A8h]
  WCHAR v28[2]; // [esp+40h] [ebp-2A4h]
  _WORD *v29; // [esp+44h] [ebp-2A0h]
  WCHAR v30[2]; // [esp+48h] [ebp-29Ch]
  WCHAR v31[2]; // [esp+4Ch] [ebp-298h]
  int a2; // [esp+50h] [ebp-294h]
  BYTE Data[4]; // [esp+54h] [ebp-290h]
  void *v34; // [esp+58h] [ebp-28Ch]
  void *v35; // [esp+5Ch] [ebp-288h]
  void *ppv1; // [esp+60h] [ebp-284h]
  HKEY hKey; // [esp+64h] [ebp-280h]
  void *v38; // [esp+68h] [ebp-27Ch]
  CCmdString *str2; // [esp+6Ch] [ebp-278h]
  WCHAR *ppv3; // [esp+70h] [ebp-274h]
  WCHAR szArg[2]; // [esp+74h] [ebp-270h]
  void *a1a; // [esp+78h] [ebp-26Ch]
  DWORD cbData; // [esp+7Ch] [ebp-268h]
  CCmdString ppv; // [esp+80h] [ebp-264h]
  void *v45; // [esp+84h] [ebp-260h]
  UINT uID; // [esp+88h] [ebp-25Ch]
  HKEY phkResult; // [esp+8Ch] [ebp-258h]
  LPCWSTR v48; // [esp+90h] [ebp-254h]
  CCmdString str3; // [esp+94h] [ebp-250h]
  LPCWSTR v50; // [esp+98h] [ebp-24Ch]
  void *v51; // [esp+9Ch] [ebp-248h]
  CCmdString strValue; // [esp+A0h] [ebp-244h]
  LPCWSTR v53; // [esp+A4h] [ebp-240h]
  LPCWSTR szArg4; // [esp+A8h] [ebp-23Ch]
  char v55; // [esp+AFh] [ebp-235h]
  CCmdString v56; // [esp+B0h] [ebp-234h]
  LPCWSTR lpSubKey; // [esp+B4h] [ebp-230h]
  LPCWSTR v58; // [esp+B8h] [ebp-22Ch]
  BYTE v59; // [esp+BCh] [ebp-228h]
  WCHAR Buffer; // [esp+CCh] [ebp-218h]
  int v61; // [esp+2E0h] [ebp-4h]

  uID = a1;
  v61 = 0;
  v56.m_String = (WCHAR *)malloc(2u);
  *v56.m_String = 0;
  v2 = malloc(2u);
  v29 = v2;
  *v2 = 0;
  v3 = malloc(2u);
  v27 = v3;
  *v3 = 0;
  v51 = malloc(2u);
  *(_WORD *)v51 = 0;
  v38 = malloc(2u);
  *(_WORD *)v38 = 0;
  ppv3 = (WCHAR *)malloc(2u);
  *ppv3 = 0;
  v4 = malloc(2u);
  v25 = v4;
  *v4 = 0;
  ppv.m_String = (WCHAR *)malloc(2u);
  *ppv.m_String = 0;
  v48 = _wcsdup((const wchar_t *)&gszNullString);
  v50 = _wcsdup((const wchar_t *)&gszNullString);
  v53 = _wcsdup((const wchar_t *)&gszNullString);
  strValue.m_String = _wcsdup((const wchar_t *)&gszNullString);
  v45 = _wcsdup((const wchar_t *)&gszNullString);
  str3.m_String = _wcsdup((const wchar_t *)&gszNullString);
  szArg4 = _wcsdup((const wchar_t *)&gszNullString);
  v58 = _wcsdup((const wchar_t *)&gszNullString);
  LOBYTE(v61) = 16;
  str2 = MakeRegistryKeyName((CCmdString *)&a1a, HKEY_LOCAL_MACHINE, (CCmdString *)&psz, (CCmdString *)&szArg4);
  LOBYTE(v61) = 17;
  v5 = MakeRegistryKeyName((CCmdString *)szArg, HKEY_LOCAL_MACHINE, (CCmdString *)&psz, (CCmdString *)&v58);
  LOBYTE(v61) = 18;
  ppv1 = (void *)PE_UpdateSystemKey(uID, 0, (HANDLE)0xFFFFFFFF, 0, v5, str2, &str3);
  free(*(void **)szArg);
  free(a1a);
  free((void *)v58);
  free((void *)szArg4);
  free(str3.m_String);
  free(v45);
  free(strValue.m_String);
  free((void *)v53);
  free((void *)v50);
  LOBYTE(v61) = 8;
  free((void *)v48);
  if ( PE_OpenKey(ghLocalMachineKey, psz, 0, 0x20019u, &hKey) )
  {
    free(ppv.m_String);
    free(v4);
    free(ppv3);
    free(v38);
    free(v51);
    free(v3);
    free(v2);
    free(v56.m_String);
  }
  else
  {
    lpSubKey = (LPCWSTR)malloc(2u);
    *lpSubKey = 0;
    LOBYTE(v61) = 19;
    if ( !PE_LoadRegKeys(hKey, 0, (CCmdString *)&lpSubKey) )
    {
      v6 = uID;
      v7 = 0;
      do
      {
        v8 = lpSubKey;
        v9 = (unsigned int)TlsGetValue(gdwTlsIndex);
        if ( !RegOpenKeyExW(hKey, v8, 0, v9 | 0x20019, &phkResult) )
        {
          cbData = 0;
          if ( !PE_ReadRegKey(phkResult, L"LibraryPath", 0, 0, &ppv) )
          {
            str2 = (CCmdString *)_wcsdup(ppv.m_String);
            strCmd[0].m_String = (WCHAR *)malloc(2u);
            *strCmd[0].m_String = 0;
            strCmd[1].m_String = 0;
            strCmd[2].m_String = 0;
            strCmd[3].m_String = 0;
            LOBYTE(v61) = 21;
            sub_BE7040(ppv.m_String, (StringItem *)strCmd);
            v10 = (const wchar_t **)sub_BE4EE0((int)&strCmd[4], v6, (int)strCmd, 0);
            v11 = v56.m_String;
            v56.m_String = _wcsdup(*v10);
            free(v11);
            free(strCmd[4].m_String);
            a2 = sub_BE4ED0();
            v58 = _wcsdup(lpSubKey);
            LOBYTE(v61) = 22;
            if ( !PE_ReadRegKey(phkResult, L"DisplayString", 0, 0, (CCmdString *)&v58) && *v58 == 64 )
            {
              v12 = _wcsdup(v58);
              v35 = v12;
              LOBYTE(v61) = 23;
              uID = 0;
              if ( wcschr(v12, 0x2Cu) )
              {
                v13 = wcschr(v12, 0x2Cu);
                *v13 = 0;
                uID = abs(_wtoi(v13 + 1));
              }
              v14 = RequerySystemEnvironmentString(&strCmd[6], (CCmdString *)(v12 + 1));
              v15 = _wcsdup(v14->m_String);
              free(v35);
              free(strCmd[6].m_String);
              v16 = LoadLibraryExW(v15, 0, 2u);
              strCmd[5].m_String = (WCHAR *)v16;
              if ( v16 )
              {
                if ( LoadStringW(v16, uID, &Buffer, 260) )
                {
                  v35 = (void *)v58;
                  v58 = _wcsdup(&Buffer);
                  free(v35);
                }
                FreeLibrary((HMODULE)strCmd[5].m_String);
              }
              free(v15);
            }
            cbData = 4;
            RegQueryValueExW(phkResult, L"Enabled", 0, 0, Data, &cbData);
            cbData = 16;
            if ( !RegQueryValueExW(phkResult, L"ProviderId", 0, 0, &v59, &cbData) )
            {
              v48 = _wcsdup((const wchar_t *)&gszNullString);
              LOBYTE(v61) = 24;
              v17 = MakeRegistryKeyName(
                      (CCmdString *)v24,
                      HKEY_LOCAL_MACHINE,
                      (CCmdString *)&psz,
                      (CCmdString *)&lpSubKey);
              LOBYTE(v61) = 25;
              v18 = MakeRegistryKeyName((CCmdString *)v30, HKEY_LOCAL_MACHINE, (CCmdString *)&psz, (CCmdString *)&v48);
              LOBYTE(v61) = 26;
              v55 = sub_BE3D40(
                      v6,
                      (CCmdString)&lpSubKey,
                      (int)v18,
                      (int)v17,
                      (int)&v56,
                      (int)&v51,
                      (CCmdString)&ppv3,
                      (int)&a8);
              free(*(void **)v30);
              free(*(void **)v24);
              free((void *)v48);
              if ( v55 )
              {
                if ( ppv1 == (void *)-1 )
                {
                  a1a = _wcsdup((const wchar_t *)&gszNullString);
                  v34 = _wcsdup((const wchar_t *)&gszNullString);
                  szArg4 = _wcsdup((const wchar_t *)&gszNullString);
                  str3.m_String = _wcsdup((const wchar_t *)&gszNullString);
                  v45 = _wcsdup((const wchar_t *)&gszNullString);
                  strValue.m_String = _wcsdup((const wchar_t *)&gszNullString);
                  v53 = _wcsdup((const wchar_t *)&gszNullString);
                  v50 = _wcsdup((const wchar_t *)&gszNullString);
                  LOBYTE(v61) = 34;
                  v19 = MakeRegistryKeyName(
                          (CCmdString *)v23,
                          HKEY_LOCAL_MACHINE,
                          (CCmdString *)&psz,
                          (CCmdString *)&v53);
                  LOBYTE(v61) = 35;
                  v20 = MakeRegistryKeyName(
                          (CCmdString *)v28,
                          HKEY_LOCAL_MACHINE,
                          (CCmdString *)&psz,
                          (CCmdString *)&v50);
                  LOBYTE(v61) = 36;
                  ppv1 = (void *)PE_UpdateSystemKey(v6, 0, (HANDLE)0xFFFFFFFF, 0, v20, v19, &strValue);
                  free(*(void **)v28);
                  free(*(void **)v23);
                  free((void *)v50);
                  free((void *)v53);
                  free(strValue.m_String);
                  free(v45);
                  free(str3.m_String);
                  free((void *)szArg4);
                  free(v34);
                  free(a1a);
                }
                *(_DWORD *)szArg = _wcsdup((const wchar_t *)&gszNullString);
                LOBYTE(v61) = 37;
                v21 = MakeRegistryKeyName(
                        (CCmdString *)v31,
                        HKEY_LOCAL_MACHINE,
                        (CCmdString *)&psz,
                        (CCmdString *)&lpSubKey);
                LOBYTE(v61) = 38;
                PE_UpdateSystemKey(v6, a2, ppv1, 0x10u, (CCmdString *)&v58, v21, &v56);
                free(*(void **)v31);
                free(*(void **)szArg);
              }
            }
            free((void *)v58);
            StringItem::~StringItem((tagPEStringStruct *)strCmd);
            LOBYTE(v61) = 19;
            free(str2);
          }
          RegCloseKey(phkResult);
        }
        ++v7;
      }
      while ( !PE_LoadRegKeys(hKey, v7, (CCmdString *)&lpSubKey) );
      v2 = v29;
      v3 = v27;
      v4 = v25;
    }
    RegCloseKey(hKey);
    free((void *)lpSubKey);
    free(ppv.m_String);
    free(v4);
    free(ppv3);
    free(v38);
    free(v51);
    free(v3);
    free(v2);
    free(v56.m_String);
  }
  free(psz);
}

//----- (00C03190) --------------------------------------------------------
void __cdecl sub_C03190(int a1, OLECHAR *psz)
{
  _WORD *v2; // edi
  _WORD *v3; // ebx
  _WORD *v4; // esi
  CCmdString *v5; // eax
  Data_t_bstr_t *v6; // edi
  DWORD v7; // ebx
  const WCHAR *v8; // esi
  unsigned int v9; // eax
  Data_t_bstr_t *v10; // eax
  const WCHAR **v11; // eax
  Data_t_bstr_t *v12; // esi
  const wchar_t **v13; // eax
  WCHAR *v14; // esi
  wchar_t *v15; // esi
  wchar_t *v16; // eax
  CCmdString *v17; // eax
  wchar_t *v18; // esi
  HINSTANCE v19; // eax
  CCmdString *v20; // esi
  CCmdString *v21; // eax
  CCmdString *v22; // esi
  CCmdString *v23; // eax
  CCmdString *v24; // eax
  WCHAR pszText2[2]; // [esp+10h] [ebp-63Ch]
  int v26; // [esp+14h] [ebp-638h]
  int v27; // [esp+18h] [ebp-634h]
  int v28; // [esp+1Ch] [ebp-630h]
  DWORD cbData; // [esp+20h] [ebp-62Ch]
  WCHAR *ppstr; // [esp+24h] [ebp-628h]
  void *v31; // [esp+28h] [ebp-624h]
  WCHAR v32[2]; // [esp+2Ch] [ebp-620h]
  WCHAR v33[2]; // [esp+30h] [ebp-61Ch]
  _WORD *v34; // [esp+34h] [ebp-618h]
  int a8; // [esp+38h] [ebp-614h]
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
  CCmdString v49; // [esp+70h] [ebp-5DCh]
  HKEY hRootKey; // [esp+74h] [ebp-5D8h]
  CCmdString *str2; // [esp+78h] [ebp-5D4h]
  void *v52; // [esp+7Ch] [ebp-5D0h]
  WCHAR szArg[2]; // [esp+80h] [ebp-5CCh]
  void *a1a; // [esp+84h] [ebp-5C8h]
  void *v55; // [esp+88h] [ebp-5C4h]
  LPCWSTR v56; // [esp+8Ch] [ebp-5C0h]
  CCmdString str3; // [esp+90h] [ebp-5BCh]
  LPCWSTR v58; // [esp+94h] [ebp-5B8h]
  Data_t_bstr_t *v59; // [esp+98h] [ebp-5B4h]
  LPCWSTR v60; // [esp+9Ch] [ebp-5B0h]
  UINT uID; // [esp+A0h] [ebp-5ACh]
  CCmdString strValue; // [esp+A4h] [ebp-5A8h]
  LPCWSTR szArg4; // [esp+A8h] [ebp-5A4h]
  CCmdString v64; // [esp+ACh] [ebp-5A0h]
  char v65; // [esp+B3h] [ebp-599h]
  LPCWSTR lpszKeyName; // [esp+B4h] [ebp-598h]
  wchar_t *ppv3; // [esp+B8h] [ebp-594h]
  BYTE Data; // [esp+BCh] [ebp-590h]
  WCHAR Buffer; // [esp+434h] [ebp-218h]
  int v70; // [esp+648h] [ebp-4h]

  v59 = (Data_t_bstr_t *)a1;
  v70 = 0;
  v64.m_String = (WCHAR *)malloc(2u);
  *v64.m_String = 0;
  v2 = malloc(2u);
  v38 = v2;
  *v2 = 0;
  v3 = malloc(2u);
  v36 = v3;
  *v3 = 0;
  v55 = malloc(2u);
  *(_WORD *)v55 = 0;
  v52 = malloc(2u);
  *(_WORD *)v52 = 0;
  v49.m_String = (WCHAR *)malloc(2u);
  *v49.m_String = 0;
  v4 = malloc(2u);
  v34 = v4;
  *v4 = 0;
  v44 = malloc(2u);
  *(_WORD *)v44 = 0;
  uID = (UINT)_wcsdup((const wchar_t *)&gszNullString);
  v58 = _wcsdup((const wchar_t *)&gszNullString);
  v56 = _wcsdup((const wchar_t *)&gszNullString);
  v60 = _wcsdup((const wchar_t *)&gszNullString);
  strValue.m_String = _wcsdup((const wchar_t *)&gszNullString);
  str3.m_String = _wcsdup((const wchar_t *)&gszNullString);
  ppv3 = _wcsdup((const wchar_t *)&gszNullString);
  szArg4 = _wcsdup((const wchar_t *)&gszNullString);
  LOBYTE(v70) = 16;
  str2 = MakeRegistryKeyName((CCmdString *)&a1a, HKEY_LOCAL_MACHINE, (CCmdString *)&psz, (CCmdString *)&ppv3);
  LOBYTE(v70) = 17;
  v5 = MakeRegistryKeyName((CCmdString *)szArg, HKEY_LOCAL_MACHINE, (CCmdString *)&psz, (CCmdString *)&szArg4);
  LOBYTE(v70) = 18;
  ppv1 = (void *)PE_UpdateSystemKey((int)v59, 0, (HANDLE)0xFFFFFFFF, 0, v5, str2, &str3);
  free(*(void **)szArg);
  free(a1a);
  free((void *)szArg4);
  free(ppv3);
  free(str3.m_String);
  free(strValue.m_String);
  free((void *)v60);
  free((void *)v56);
  free((void *)v58);
  LOBYTE(v70) = 8;
  free((void *)uID);
  if ( PE_OpenKey(ghLocalMachineKey, psz, 0, 0x20019u, &hRootKey) )
  {
    free(v44);
    free(v4);
    free(v49.m_String);
    free(v52);
    free(v55);
    free(v3);
    free(v2);
    free(v64.m_String);
  }
  else
  {
    lpszKeyName = (LPCWSTR)malloc(2u);
    *lpszKeyName = 0;
    LOBYTE(v70) = 19;
    if ( !PE_LoadRegKeys(hRootKey, 0, (CCmdString *)&lpszKeyName) )
    {
      v6 = v59;
      v7 = 0;
      do
      {
        v8 = lpszKeyName;
        v9 = (unsigned int)TlsGetValue(gdwTlsIndex);
        if ( !PE_OpenKey(hRootKey, v8, 0, v9 | 0x20019, &hKey) )
        {
          cbData = 888;
          if ( !RegQueryValueExW(hKey, L"PackedCatalogItem", 0, 0, &Data, &cbData) )
          {
            v10 = _bstr_t::_bstr_t((_bstr_t *)&v59, (LPCSTR)&Data)->m_Data;
            if ( !v10 || (v11 = (const WCHAR **)v10->m_wstr) == 0 )
              v11 = &gszNullString;
            szArg4 = _wcsdup((const wchar_t *)v11);
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
                  operator delete[](v12->m_str);
                  v12->m_str = 0;
                }
                operator delete(v12);
              }
              v59 = 0;
            }
            *(_DWORD *)pszText2 = malloc(2u);
            **(_WORD **)pszText2 = 0;
            v26 = 0;
            v27 = 0;
            v28 = 0;
            LOBYTE(v70) = 21;
            sub_BE6CC0((WCHAR *)szArg4, (StringItem *)pszText2);
            v13 = (const wchar_t **)sub_BE4EE0((int)&v31, (int)v6, (int)pszText2, 0);
            v14 = v64.m_String;
            v64.m_String = _wcsdup(*v13);
            free(v14);
            free(v31);
            a2 = sub_BE4ED0();
            ppv3 = _wcsdup(lpszKeyName);
            LOBYTE(v70) = 22;
            if ( !PE_ReadRegKey(hKey, L"ProtocolName", 0, 0, (CCmdString *)&ppv3) && *ppv3 == 64 )
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
              v17 = RequerySystemEnvironmentString((CCmdString *)&ppstr, (CCmdString *)(v15 + 1));
              v18 = _wcsdup(v17->m_String);
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
            v58 = _wcsdup((const wchar_t *)&gszNullString);
            LOBYTE(v70) = 24;
            v20 = MakeRegistryKeyName(
                    (CCmdString *)v33,
                    HKEY_LOCAL_MACHINE,
                    (CCmdString *)&psz,
                    (CCmdString *)&lpszKeyName);
            LOBYTE(v70) = 25;
            v21 = MakeRegistryKeyName((CCmdString *)v39, HKEY_LOCAL_MACHINE, (CCmdString *)&psz, (CCmdString *)&v58);
            LOBYTE(v70) = 26;
            v65 = sub_BE3D40(
                    (int)v6,
                    (CCmdString)&lpszKeyName,
                    (int)v21,
                    (int)v20,
                    (int)&v64,
                    (int)&v55,
                    (CCmdString)&v49,
                    (int)&a8);
            free(*(void **)v39);
            free(*(void **)v33);
            free((void *)v58);
            if ( v65 )
            {
              if ( ppv1 == (void *)-1 )
              {
                *(_DWORD *)szArg = _wcsdup((const wchar_t *)&gszNullString);
                a1a = _wcsdup((const wchar_t *)&gszNullString);
                v45 = _wcsdup((const wchar_t *)&gszNullString);
                v43 = _wcsdup((const wchar_t *)&gszNullString);
                str3.m_String = _wcsdup((const wchar_t *)&gszNullString);
                strValue.m_String = _wcsdup((const wchar_t *)&gszNullString);
                v60 = _wcsdup((const wchar_t *)&gszNullString);
                v56 = _wcsdup((const wchar_t *)&gszNullString);
                LOBYTE(v70) = 34;
                v22 = MakeRegistryKeyName((CCmdString *)v32, HKEY_LOCAL_MACHINE, (CCmdString *)&psz, (CCmdString *)&v60);
                LOBYTE(v70) = 35;
                v23 = MakeRegistryKeyName((CCmdString *)v37, HKEY_LOCAL_MACHINE, (CCmdString *)&psz, (CCmdString *)&v56);
                LOBYTE(v70) = 36;
                ppv1 = (void *)PE_UpdateSystemKey((int)v6, 0, (HANDLE)0xFFFFFFFF, 0, v23, v22, &strValue);
                free(*(void **)v37);
                free(*(void **)v32);
                free((void *)v56);
                free((void *)v60);
                free(strValue.m_String);
                free(str3.m_String);
                free(v43);
                free(v45);
                free(a1a);
                free(*(void **)szArg);
              }
              str2 = (CCmdString *)_wcsdup((const wchar_t *)&gszNullString);
              LOBYTE(v70) = 37;
              v24 = MakeRegistryKeyName(
                      (CCmdString *)v40,
                      HKEY_LOCAL_MACHINE,
                      (CCmdString *)&psz,
                      (CCmdString *)&lpszKeyName);
              LOBYTE(v70) = 38;
              PE_UpdateSystemKey((int)v6, a2, ppv1, 0xBu, (CCmdString *)&ppv3, v24, &v64);
              free(*(void **)v40);
              free(str2);
            }
            free(ppv3);
            StringItem::~StringItem((tagPEStringStruct *)pszText2);
            LOBYTE(v70) = 19;
            free((void *)szArg4);
          }
          RegCloseKey(hKey);
        }
        ++v7;
      }
      while ( !PE_LoadRegKeys(hRootKey, v7, (CCmdString *)&lpszKeyName) );
      v2 = v38;
      v3 = v36;
      v4 = v34;
    }
    RegCloseKey(hRootKey);
    free((void *)lpszKeyName);
    free(v44);
    free(v4);
    free(v49.m_String);
    free(v52);
    free(v55);
    free(v3);
    free(v2);
    free(v64.m_String);
  }
  free(psz);
}

//----- (00C03B60) --------------------------------------------------------
std_Tree_node_for_tagKeyName **__thiscall sub_C03B60(std__tree *this, int a2, _DWORD **a3, int a4)
{
  std_Tree_node_for_tagKeyName **result; // eax

  result = (std_Tree_node_for_tagKeyName **)sub_C06B70(this);
  *((_WORD *)result + 6) = 0;
  if ( result != (std_Tree_node_for_tagKeyName **)-16 )
  {
    result[4] = (std_Tree_node_for_tagKeyName *)**a3;
    result[5] = 0;
    result[6] = 0;
    result[7] = 0;
  }
  return result;
}

//----- (00C03BA0) --------------------------------------------------------
CSystemProcessInfoMapNode *__thiscall sub_C03BA0(CSystemProcessInfoMap *this, int a2, const wchar_t ***a3, int a4)
{
  CSystemProcessInfoMapNode *result; // eax
  CSystemProcessInfoMapNode *v5; // esi
  _DWORD *v6; // edi

  result = std::_Tree_comp_alloc<std::_Tmap_traits<unsigned long,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *>>,0>>::_Buynode0(this);
  v5 = result;
  v6 = &result->_Keyvalue._Key;
  *(_WORD *)&result->baseclass._Color = 0;
  if ( result != (CSystemProcessInfoMapNode *)-16 )
  {
    *v6 = _wcsdup(**a3);
    v6[1] = 0;
    result = v5;
  }
  return result;
}

//----- (00C03BE0) --------------------------------------------------------
int __thiscall sub_C03BE0(_DWORD *this, int a2, char a3, int a4, int a5, void *a6)
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
    free(*((void **)a6 + 4));
    operator delete(a6);
    std::_Xlength_error("map/set<T> too long");
  }
  this[1] = v7 + 1;
  *((_DWORD *)a6 + 1) = a4;
  if ( a4 == *this )
  {
    *(_DWORD *)(*this + 4) = a6;
    *(_DWORD *)*this = a6;
    *(_DWORD *)(*this + 8) = a6;
  }
  else if ( a3 )
  {
    *(_DWORD *)a4 = a6;
    if ( a4 == *(_DWORD *)*this )
      *(_DWORD *)*this = a6;
  }
  else
  {
    *(_DWORD *)(a4 + 8) = a6;
    if ( a4 == *(_DWORD *)(*this + 8) )
      *(_DWORD *)(*this + 8) = a6;
  }
  v8 = a6;
  if ( !*(_BYTE *)(*((_DWORD *)a6 + 1) + 12) )
  {
    do
    {
      v9 = (int *)v8[1];
      v10 = (int *)v9[1];
      v11 = (int *)*v10;
      if ( v9 == (int *)*v10 )
      {
        v11 = (int *)v10[2];
        if ( *((_BYTE *)v11 + 12) )
        {
          if ( v8 == (_DWORD *)v9[2] )
          {
            v8 = (_DWORD *)v8[1];
            v12 = (_DWORD *)v9[2];
            v9[2] = *v12;
            if ( !*(_BYTE *)(*v12 + 13) )
              *(_DWORD *)(*v12 + 4) = v9;
            v12[1] = v9[1];
            if ( v9 == *(int **)(*v6 + 4) )
            {
              *(_DWORD *)(*v6 + 4) = v12;
            }
            else
            {
              v13 = (void **)v9[1];
              if ( v8 == *v13 )
                *v13 = v12;
              else
                v13[2] = v12;
            }
            *v12 = v8;
            v8[1] = v12;
          }
          *(_BYTE *)(v8[1] + 12) = 1;
          *(_BYTE *)(*(_DWORD *)(v8[1] + 4) + 12) = 0;
          v14 = *(_DWORD **)(v8[1] + 4);
          v15 = (_DWORD *)*v14;
          *v14 = *(_DWORD *)(*v14 + 8);
          v16 = v15[2];
          if ( !*(_BYTE *)(v16 + 13) )
            *(_DWORD *)(v16 + 4) = v14;
          v15[1] = v14[1];
          if ( v14 == *(_DWORD **)(*v6 + 4) )
          {
            *(_DWORD *)(*v6 + 4) = v15;
            v15[2] = v14;
          }
          else
          {
            v17 = (_DWORD *)v14[1];
            if ( v14 == (_DWORD *)v17[2] )
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
      else if ( *((_BYTE *)v11 + 12) )
      {
        if ( v8 == (_DWORD *)*v9 )
        {
          v8 = (_DWORD *)v8[1];
          v18 = *v9;
          *v9 = *(_DWORD *)(*v9 + 8);
          v19 = *(_DWORD *)(v18 + 8);
          if ( !*(_BYTE *)(v19 + 13) )
            *(_DWORD *)(v19 + 4) = v8;
          *(_DWORD *)(v18 + 4) = v8[1];
          if ( v8 == *(_DWORD **)(*v6 + 4) )
          {
            *(_DWORD *)(*v6 + 4) = v18;
          }
          else
          {
            v20 = (_DWORD *)v8[1];
            if ( v8 == (_DWORD *)v20[2] )
              v20[2] = v18;
            else
              *v20 = v18;
          }
          *(_DWORD *)(v18 + 8) = v8;
          v8[1] = v18;
        }
        *(_BYTE *)(v8[1] + 12) = 1;
        *(_BYTE *)(*(_DWORD *)(v8[1] + 4) + 12) = 0;
        v14 = *(_DWORD **)(v8[1] + 4);
        v15 = (_DWORD *)v14[2];
        v14[2] = *v15;
        if ( !*(_BYTE *)(*v15 + 13) )
          *(_DWORD *)(*v15 + 4) = v14;
        v15[1] = v14[1];
        if ( v14 == *(_DWORD **)(*v6 + 4) )
        {
          *(_DWORD *)(*v6 + 4) = v15;
        }
        else
        {
          v21 = (_DWORD *)v14[1];
          if ( v14 == (_DWORD *)*v21 )
            *v21 = v15;
          else
            v21[2] = v15;
        }
        *v15 = v14;
        goto LABEL_48;
      }
      *((_BYTE *)v9 + 12) = 1;
      *((_BYTE *)v11 + 12) = 1;
      *(_BYTE *)(*(_DWORD *)(v8[1] + 4) + 12) = 0;
      v8 = *(_DWORD **)(v8[1] + 4);
    }
    while ( !*(_BYTE *)(v8[1] + 12) );
  }
  *(_BYTE *)(*(_DWORD *)(*v6 + 4) + 12) = 1;
  result = a2;
  *(_DWORD *)a2 = a6;
  return result;
}

//----- (00C03E00) --------------------------------------------------------
int __thiscall sub_C03E00(std__tree *this, int a2, char a3, int a4, int a5, void *a6)
{
  std__tree *v6; // edi
  unsigned int v7; // eax
  std_Tree_node_for_tagKeyName *v8; // eax
  std_Tree_node_for_tagKeyName *v9; // ecx
  std_Tree_node_for_tagKeyName *v10; // esi
  std_Tree_node_for_tagKeyName *v11; // edx
  std_Tree_node_for_tagKeyName *v12; // edx
  void **v13; // ecx
  std_Tree_node_for_tagKeyName *v14; // edx
  std_Tree_node_for_tagKeyName *v15; // esi
  std_Tree_node_for_tagKeyName *v16; // ecx
  std_Tree_node_for_tagKeyName *v17; // ecx
  std_Tree_node_for_tagKeyName *v18; // edx
  std_Tree_node_for_tagKeyName *v19; // ecx
  std_Tree_node_for_tagKeyName *v20; // ecx
  std_Tree_node_for_tagKeyName *v21; // ecx
  int result; // eax

  v6 = this;
  v7 = this->_Mypair._Myval2._Mysize;
  if ( v7 >= 0x7FFFFFE )
  {
    if ( *((_DWORD *)a6 + 5) )
    {
      operator delete(*((void **)a6 + 5));
      *((_DWORD *)a6 + 5) = 0;
      *((_DWORD *)a6 + 6) = 0;
      *((_DWORD *)a6 + 7) = 0;
    }
    operator delete(a6);
    std::_Xlength_error("map/set<T> too long");
  }
  this->_Mypair._Myval2._Mysize = v7 + 1;
  *((_DWORD *)a6 + 1) = a4;
  if ( (std__Tree_node *)a4 == this->_Mypair._Myval2._Myhead )
  {
    this->_Mypair._Myval2._Myhead->_Parent = (std_Tree_node_for_tagKeyName *)a6;
    this->_Mypair._Myval2._Myhead->_Left = (std_Tree_node_for_tagKeyName *)a6;
    this->_Mypair._Myval2._Myhead->_Right = (std__Tree_node_For__bstr_t *)a6;
  }
  else if ( a3 )
  {
    *(_DWORD *)a4 = a6;
    if ( (std_Tree_node_for_tagKeyName *)a4 == this->_Mypair._Myval2._Myhead->_Left )
      this->_Mypair._Myval2._Myhead->_Left = (std_Tree_node_for_tagKeyName *)a6;
  }
  else
  {
    *(_DWORD *)(a4 + 8) = a6;
    if ( (std__Tree_node_For__bstr_t *)a4 == this->_Mypair._Myval2._Myhead->_Right )
      this->_Mypair._Myval2._Myhead->_Right = (std__Tree_node_For__bstr_t *)a6;
  }
  v8 = (std_Tree_node_for_tagKeyName *)a6;
  if ( !*(_BYTE *)(*((_DWORD *)a6 + 1) + 12) )
  {
    do
    {
      v9 = v8->_Parent;
      v10 = v9->_Parent;
      v11 = v10->_Left;
      if ( v9 == v10->_Left )
      {
        v11 = v10->_Right;
        if ( v11->_Color )
        {
          if ( v8 == v9->_Right )
          {
            v8 = v8->_Parent;
            v12 = v9->_Right;
            v9->_Right = v12->_Left;
            if ( !v12->_Left->_IsNil )
              v12->_Left->_Parent = v9;
            v12->_Parent = v9->_Parent;
            if ( v9 == v6->_Mypair._Myval2._Myhead->_Parent )
            {
              v6->_Mypair._Myval2._Myhead->_Parent = v12;
            }
            else
            {
              v13 = (void **)&v9->_Parent->_Left;
              if ( v8 == *v13 )
                *v13 = v12;
              else
                v13[2] = v12;
            }
            v12->_Left = v8;
            v8->_Parent = v12;
          }
          v8->_Parent->_Color = 1;
          v8->_Parent->_Parent->_Color = 0;
          v14 = v8->_Parent->_Parent;
          v15 = v14->_Left;
          v14->_Left = v14->_Left->_Right;
          v16 = v15->_Right;
          if ( !v16->_IsNil )
            v16->_Parent = v14;
          v15->_Parent = v14->_Parent;
          if ( v14 == v6->_Mypair._Myval2._Myhead->_Parent )
          {
            v6->_Mypair._Myval2._Myhead->_Parent = v15;
            v15->_Right = v14;
          }
          else
          {
            v17 = v14->_Parent;
            if ( v14 == v17->_Right )
              v17->_Right = v15;
            else
              v17->_Left = v15;
            v15->_Right = v14;
          }
LABEL_50:
          v14->_Parent = v15;
          continue;
        }
      }
      else if ( v11->_Color )
      {
        if ( v8 == v9->_Left )
        {
          v8 = v8->_Parent;
          v18 = v9->_Left;
          v9->_Left = v9->_Left->_Right;
          v19 = v18->_Right;
          if ( !v19->_IsNil )
            v19->_Parent = v8;
          v18->_Parent = v8->_Parent;
          if ( v8 == v6->_Mypair._Myval2._Myhead->_Parent )
          {
            v6->_Mypair._Myval2._Myhead->_Parent = v18;
          }
          else
          {
            v20 = v8->_Parent;
            if ( v8 == v20->_Right )
              v20->_Right = v18;
            else
              v20->_Left = v18;
          }
          v18->_Right = v8;
          v8->_Parent = v18;
        }
        v8->_Parent->_Color = 1;
        v8->_Parent->_Parent->_Color = 0;
        v14 = v8->_Parent->_Parent;
        v15 = v14->_Right;
        v14->_Right = v15->_Left;
        if ( !v15->_Left->_IsNil )
          v15->_Left->_Parent = v14;
        v15->_Parent = v14->_Parent;
        if ( v14 == v6->_Mypair._Myval2._Myhead->_Parent )
        {
          v6->_Mypair._Myval2._Myhead->_Parent = v15;
        }
        else
        {
          v21 = v14->_Parent;
          if ( v14 == v21->_Left )
            v21->_Left = v15;
          else
            v21->_Right = v15;
        }
        v15->_Left = v14;
        goto LABEL_50;
      }
      v9->_Color = 1;
      v11->_Color = 1;
      v8->_Parent->_Parent->_Color = 0;
      v8 = v8->_Parent->_Parent;
    }
    while ( !v8->_Parent->_Color );
  }
  v6->_Mypair._Myval2._Myhead->_Parent->_Color = 1;
  result = a2;
  *(_DWORD *)a2 = a6;
  return result;
}

//----- (00C04040) --------------------------------------------------------
int __thiscall sub_C04040(_DWORD *this, int a2, int a3, int a4, void *a5)
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
  std_Tree_node_for_tagKeyName *v16; // [esp+18h] [ebp-18h]
  std__tree v17; // [esp+1Ch] [ebp-14h]
  int v18; // [esp+2Ch] [ebp-4h]

  v17._Mypair._Myval2._Mysize = (unsigned int)&v13;
  v5 = this;
  v15 = this;
  v6 = this[1] == 0;
  v18 = 0;
  if ( v6 )
  {
    sub_C03BE0(this, a2, 1, *this, a4, a5);
    return a2;
  }
  v8 = (std__Tree_node *)*this;
  if ( a3 == *(_DWORD *)*this )
  {
    if ( *(_DWORD *)a4 < *(_DWORD *)(a3 + 16) )
    {
      sub_C03BE0(this, a2, 1, a3, a4, a5);
      return a2;
    }
    goto LABEL_23;
  }
  if ( (std__Tree_node *)a3 == v8 )
  {
    v9 = (int)v8->_Right;
    if ( *(_DWORD *)(v9 + 16) < *(_DWORD *)a4 )
    {
      sub_C03BE0(this, a2, 0, v9, a4, a5);
      return a2;
    }
    goto LABEL_23;
  }
  v10 = *(_DWORD *)(a3 + 16);
  v16 = *(std_Tree_node_for_tagKeyName **)a4;
  v11 = v10 < (unsigned int)v16;
  if ( v10 > (unsigned int)v16 )
  {
    v17._Mypair._Myval2._Myhead = (std__Tree_node *)a3;
    std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned long const,MAPITEM *>>>,std::_Iterator_base0>::operator--(&v17);
    if ( v17._Mypair._Myval2._Myhead[1]._Left < v16 )
    {
      if ( v17._Mypair._Myval2._Myhead->_Right->_IsNil )
        sub_C03BE0(v5, a2, 0, (int)v17._Mypair._Myval2._Myhead, a4, a5);
      else
        sub_C03BE0(v5, a2, 1, a3, a4, a5);
      return a2;
    }
    v11 = *(_DWORD *)(a3 + 16) < (unsigned int)v16;
  }
  if ( !v11
    || (v17._Mypair._Myval2._Myhead = (std__Tree_node *)a3, sub_C04CE0(&v17), v17._Mypair._Myval2._Myhead != v8)
    && v16 >= v17._Mypair._Myval2._Myhead[1]._Left )
  {
LABEL_23:
    v18 = -1;
    v12 = *(_DWORD *)sub_C044A0(v5, (int)&v14, 0, a4, a5);
    result = a2;
    *(_DWORD *)a2 = v12;
    return result;
  }
  if ( *(_BYTE *)(*(_DWORD *)(a3 + 8) + 13) )
    sub_C03BE0(v5, a2, 0, a3, a4, a5);
  else
    sub_C03BE0(v5, a2, 1, (int)v17._Mypair._Myval2._Myhead, a4, a5);
  return a2;
}
// C781AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);

//----- (00C04270) --------------------------------------------------------
int __thiscall sub_C04270(std__tree *this, int a2, int a3, int a4, void *a5)
{
  std__tree *v5; // ebx
  bool v6; // zf
  int result; // eax
  std__Tree_node *v8; // edi
  int v9; // edx
  unsigned int v10; // ecx
  bool v11; // cf
  int v12; // ecx
  int v13; // [esp+0h] [ebp-30h]
  int v14; // [esp+10h] [ebp-20h]
  std__tree *v15; // [esp+14h] [ebp-1Ch]
  std_Tree_node_for_tagKeyName *v16; // [esp+18h] [ebp-18h]
  std__tree v17; // [esp+1Ch] [ebp-14h]
  int v18; // [esp+2Ch] [ebp-4h]

  v17._Mypair._Myval2._Mysize = (unsigned int)&v13;
  v5 = this;
  v15 = this;
  v6 = this->_Mypair._Myval2._Mysize == 0;
  v18 = 0;
  if ( v6 )
  {
    sub_C03E00(this, a2, 1, (int)this->_Mypair._Myval2._Myhead, a4, a5);
    return a2;
  }
  v8 = this->_Mypair._Myval2._Myhead;
  if ( (std_Tree_node_for_tagKeyName *)a3 == this->_Mypair._Myval2._Myhead->_Left )
  {
    if ( *(_DWORD *)a4 < *(_DWORD *)(a3 + 16) )
    {
      sub_C03E00(this, a2, 1, a3, a4, a5);
      return a2;
    }
    goto LABEL_23;
  }
  if ( (std__Tree_node *)a3 == v8 )
  {
    v9 = (int)v8->_Right;
    if ( *(_DWORD *)(v9 + 16) < *(_DWORD *)a4 )
    {
      sub_C03E00(this, a2, 0, v9, a4, a5);
      return a2;
    }
    goto LABEL_23;
  }
  v10 = *(_DWORD *)(a3 + 16);
  v16 = *(std_Tree_node_for_tagKeyName **)a4;
  v11 = v10 < (unsigned int)v16;
  if ( v10 > (unsigned int)v16 )
  {
    v17._Mypair._Myval2._Myhead = (std__Tree_node *)a3;
    std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned long const,MAPITEM *>>>,std::_Iterator_base0>::operator--(&v17);
    if ( v17._Mypair._Myval2._Myhead[1]._Left < v16 )
    {
      if ( v17._Mypair._Myval2._Myhead->_Right->_IsNil )
        sub_C03E00(v5, a2, 0, (int)v17._Mypair._Myval2._Myhead, a4, a5);
      else
        sub_C03E00(v5, a2, 1, a3, a4, a5);
      return a2;
    }
    v11 = *(_DWORD *)(a3 + 16) < (unsigned int)v16;
  }
  if ( !v11
    || (v17._Mypair._Myval2._Myhead = (std__Tree_node *)a3, sub_C04CE0(&v17), v17._Mypair._Myval2._Myhead != v8)
    && v16 >= v17._Mypair._Myval2._Myhead[1]._Left )
  {
LABEL_23:
    v18 = -1;
    v12 = *(_DWORD *)sub_C045C0(v5, (int)&v14, 0, a4, a5);
    result = a2;
    *(_DWORD *)a2 = v12;
    return result;
  }
  if ( *(_BYTE *)(*(_DWORD *)(a3 + 8) + 13) )
    sub_C03E00(v5, a2, 0, a3, a4, a5);
  else
    sub_C03E00(v5, a2, 1, (int)v17._Mypair._Myval2._Myhead, a4, a5);
  return a2;
}
// C781AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);

//----- (00C044A0) --------------------------------------------------------
int __thiscall sub_C044A0(_DWORD *this, int a2, int a3, int a4, void *a5)
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
  v7 = (_DWORD *)a4;
  v20 = 0;
  v8 = *(_DWORD *)(v5 + 4);
  v9 = 1;
  LOBYTE(v18) = 1;
  if ( !*(_BYTE *)(v8 + 13) )
  {
    v10 = *(_DWORD *)a4;
    do
    {
      v6 = v8;
      if ( (_BYTE)a3 )
        v9 = *(_DWORD *)(v8 + 16) >= v10;
      else
        v9 = v10 < *(_DWORD *)(v8 + 16);
      LOBYTE(v18) = v9;
      if ( v9 )
        v8 = *(_DWORD *)v8;
      else
        v8 = *(_DWORD *)(v8 + 8);
    }
    while ( !*(_BYTE *)(v8 + 13) );
    this = v17;
  }
  v11 = v6;
  a3 = v6;
  if ( v9 )
  {
    if ( v6 == *(_DWORD *)*this )
    {
      v12 = (int *)sub_C03BE0(this, (int)&a3, 1, v6, a4, a5);
LABEL_14:
      v13 = *v12;
      result = a2;
      *(_DWORD *)a2 = v13;
      *(_BYTE *)(a2 + 4) = 1;
      return result;
    }
    std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned long const,MAPITEM *>>>,std::_Iterator_base0>::operator--((std__tree *)&a3);
    v11 = a3;
  }
  if ( *(_DWORD *)(v11 + 16) < *v7 )
  {
    v12 = (int *)sub_C03BE0(v17, (int)&a3, v18, v6, (int)v7, a5);
    goto LABEL_14;
  }
  v15 = a5;
  free(*((void **)a5 + 4));
  operator delete(v15);
  result = a2;
  *(_DWORD *)a2 = v11;
  *(_BYTE *)(a2 + 4) = 0;
  return result;
}
// C781AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);

//----- (00C045C0) --------------------------------------------------------
int __thiscall sub_C045C0(std__tree *this, int a2, int a3, int a4, void *a5)
{
  std__Tree_node *v5; // edx
  std__Tree_node *v6; // edi
  _DWORD *v7; // ebx
  std__Tree_node *v8; // eax
  bool v9; // dl
  std_Tree_node_for_tagKeyName *v10; // ecx
  int v11; // esi
  int *v12; // eax
  int v13; // ecx
  int result; // eax
  _DWORD *v15; // edi
  int v16; // [esp+0h] [ebp-28h]
  std__tree *v17; // [esp+10h] [ebp-18h]
  int v18; // [esp+14h] [ebp-14h]
  int *v19; // [esp+18h] [ebp-10h]
  int v20; // [esp+24h] [ebp-4h]

  v19 = &v16;
  v17 = this;
  v5 = this->_Mypair._Myval2._Myhead;
  v6 = this->_Mypair._Myval2._Myhead;
  v7 = (_DWORD *)a4;
  v20 = 0;
  v8 = (std__Tree_node *)v5->_Parent;
  v9 = 1;
  LOBYTE(v18) = 1;
  if ( !v8->_IsNil )
  {
    v10 = *(std_Tree_node_for_tagKeyName **)a4;
    do
    {
      v6 = v8;
      if ( (_BYTE)a3 )
        v9 = v8[1]._Left >= v10;
      else
        v9 = v10 < v8[1]._Left;
      LOBYTE(v18) = v9;
      if ( v9 )
        v8 = (std__Tree_node *)v8->_Left;
      else
        v8 = (std__Tree_node *)v8->_Right;
    }
    while ( !v8->_IsNil );
    this = v17;
  }
  v11 = (int)v6;
  a3 = (int)v6;
  if ( v9 )
  {
    if ( v6 == (std__Tree_node *)this->_Mypair._Myval2._Myhead->_Left )
    {
      v12 = (int *)sub_C03E00(this, (int)&a3, 1, (int)v6, a4, a5);
LABEL_14:
      v13 = *v12;
      result = a2;
      *(_DWORD *)a2 = v13;
      *(_BYTE *)(a2 + 4) = 1;
      return result;
    }
    std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned long const,MAPITEM *>>>,std::_Iterator_base0>::operator--((std__tree *)&a3);
    v11 = a3;
  }
  if ( *(_DWORD *)(v11 + 16) < *v7 )
  {
    v12 = (int *)sub_C03E00(v17, (int)&a3, v18, (int)v6, (int)v7, a5);
    goto LABEL_14;
  }
  v15 = a5;
  if ( *((_DWORD *)a5 + 5) )
  {
    operator delete(*((void **)a5 + 5));
    v15[5] = 0;
    v15[6] = 0;
    v15[7] = 0;
  }
  operator delete(v15);
  result = a2;
  *(_DWORD *)a2 = v11;
  *(_BYTE *)(a2 + 4) = 0;
  return result;
}
// C781AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);

//----- (00C04700) --------------------------------------------------------
StringItem *__cdecl sub_C04700(int a1, const wchar_t **a2, StringItem *a3)
{
  const wchar_t **v3; // edi
  StringItem *v4; // ebx
  void *v5; // esi

  v3 = (const wchar_t **)a1;
  if ( (const wchar_t **)a1 == a2 )
    return a3;
  v4 = a3;
  do
  {
    v5 = (void *)v4->strText;
    v4->strText = (int)_wcsdup(*v3);
    free(v5);
    ++v3;
    v4 = (StringItem *)((char *)v4 + 4);
  }
  while ( v3 != a2 );
  return v4;
}

//----- (00C04740) --------------------------------------------------------
EventConsumerDescBase *__thiscall ActiveScriptEventConsumer::ActiveScriptEventConsumer(void *this)
{
  EventConsumerDescBase *v1; // ebx
  WCHAR *v2; // eax
  WCHAR *v3; // eax
  WCHAR *v4; // esi
  WCHAR *v5; // esi
  void *v7; // [esp+14h] [ebp-10h]
  int v8; // [esp+20h] [ebp-4h]

  v1 = (EventConsumerDescBase *)this;
  v7 = _wcsdup(L"ActiveScriptEventConsumer");
  v8 = 0;
  v1->vtptr = (EventConsumerDescBaseVTbl *)&EventConsumerDescBase::`vftable';
  v2 = (WCHAR *)malloc(2u);
  v1->m_pszDescription = v2;
  *v2 = 0;
  v3 = (WCHAR *)malloc(2u);
  v1->m_pszURL = v3;
  *v3 = 0;
  LOBYTE(v8) = 2;
  *sub_C04C50((CSystemProcessInfoMap *)&gEventConsumerMap, &v7) = (std_Tree_node_for_tagKeyName *)v1;
  free(v7);
  v1->vtptr = (EventConsumerDescBaseVTbl *)&ActiveScriptEventConsumer::`vftable';
  v4 = v1->m_pszDescription;
  v1->m_pszDescription = _wcsdup(L"The ActiveScriptEventConsumer class runs a predefined script in an arbitrary scripting ");
  free(v4);
  CCmdString::InsertAt(
    (CCmdString *)&v1->m_pszDescription,
    L"language when an event is delivered to it. This class is one of the standard event consumers that WMI provides.",
    0x7FFFFFFFu,
    0);
  v5 = v1->m_pszURL;
  v1->m_pszURL = _wcsdup(L"http://msdn.microsoft.com/en-us/library/aa384749(v=vs.85).aspx");
  free(v5);
  return v1;
}
// CA2E48: using guessed type void *EventConsumerDescBase::`vftable';
// CA3110: using guessed type void *ActiveScriptEventConsumer::`vftable';

//----- (00C04830) --------------------------------------------------------
CommandLineEventConsumer *__thiscall CommandLineEventConsumer::CommandLineEventConsumer(CommandLineEventConsumer *this)
{
  CommandLineEventConsumer *v1; // ebx
  WCHAR *v2; // eax
  WCHAR *v3; // eax
  WCHAR *v4; // esi
  WCHAR *v5; // esi
  void *v7; // [esp+14h] [ebp-10h]
  int v8; // [esp+20h] [ebp-4h]

  v1 = this;
  v7 = _wcsdup(L"CommandLineEventConsumer");
  v8 = 0;
  v1->baseclass.vtptr = (EventConsumerDescBaseVTbl *)&EventConsumerDescBase::`vftable';
  v2 = (WCHAR *)malloc(2u);
  v1->baseclass.m_pszDescription = v2;
  *v2 = 0;
  v3 = (WCHAR *)malloc(2u);
  v1->baseclass.m_pszURL = v3;
  *v3 = 0;
  LOBYTE(v8) = 2;
  *sub_C04C50((CSystemProcessInfoMap *)&gEventConsumerMap, &v7) = (std_Tree_node_for_tagKeyName *)v1;
  free(v7);
  v1->baseclass.vtptr = (EventConsumerDescBaseVTbl *)&CommandLineEventConsumer::`vftable';
  v4 = v1->baseclass.m_pszDescription;
  v1->baseclass.m_pszDescription = _wcsdup(
                                     L"The CommandLineEventConsumer class starts an arbitrary process in the local system ");
  free(v4);
  CCmdString::InsertAt(
    (CCmdString *)&v1->baseclass.m_pszDescription,
    L"when an event is delivered to it. This class is one of the standard event consumers that WMI provides.",
    0x7FFFFFFFu,
    0);
  v5 = v1->baseclass.m_pszURL;
  v1->baseclass.m_pszURL = _wcsdup(L"http://msdn.microsoft.com/en-us/library/aa389231(v=vs.85).aspx");
  free(v5);
  return v1;
}
// CA2E48: using guessed type void *EventConsumerDescBase::`vftable';
// CA2E60: using guessed type void *CommandLineEventConsumer::`vftable';

//----- (00C04920) --------------------------------------------------------
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
  v4 = _bstr_t::_bstr_t((tagEventSetItem *)&v15, (OLECHAR *)lpszQuery);
  LOBYTE(v16) = 1;
  v5 = _bstr_t::_bstr_t((tagEventSetItem *)&lpszQuery, L"WQL");
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
  v11 = (wchar_t *)lpszQuery;
  v12 = InterlockedDecrement;
  pWbemServicesa = (IWbemServices *)v10;
  if ( lpszQuery )
  {
    if ( !InterlockedDecrement((volatile LONG *)lpszQuery + 2) && v11 )
    {
      if ( *(_DWORD *)v11 )
      {
        SysFreeString(*(BSTR *)v11);
        *(_DWORD *)v11 = 0;
      }
      if ( *((_DWORD *)v11 + 1) )
      {
        operator delete[](*((void **)v11 + 1));
        *((_DWORD *)v11 + 1) = 0;
      }
      operator delete(v11);
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
      operator delete[](v13->m_str);
      v13->m_str = 0;
    }
    operator delete(v13);
  }
  result = v3;
  if ( (signed int)pWbemServicesa < 0 )
    *v3 = 0;
  return result;
}

//----- (00C04A70) --------------------------------------------------------
tagStreamThreadInfo *__thiscall tagStreamThreadInfo_SetServer(tagStreamThreadInfo *this, volatile LONG a2)
{
  tagStreamThreadInfo *v2; // esi

  v2 = this;
  this->pszServer = (WCHAR *)a2;
  this->hEvent1 = 0;
  this->hEvent2 = 0;
  this->hEventLoadFailed = 0;
  this->hThread = 0;
  this->pStream = 0;
  this->bRelease = 0;
  this->nRefCount = 0;
  this->hresult = 0;
  InterlockedIncrement(&this->nRefCount);
  return v2;
}

//----- (00C04B00) --------------------------------------------------------
void __thiscall sub_C04B00(CSystemProcessInfoMap *this)
{
  CSystemProcessInfoMap *v1; // esi
  int v2; // [esp+4h] [ebp-4h]

  v1 = this;
  sub_C071F0(this, (int)&v2, this->_Header->_Left, (int)this->_Header);
  operator delete(v1->_Header);
}

//----- (00C04B60) --------------------------------------------------------
std__tree *__thiscall sub_C04B60(std__tree *this, void **a2)
{
  std__tree *v2; // esi

  v2 = this;
  if ( this != (std__tree *)a2 )
  {
    if ( this->_Mypair._Myval2._Myhead )
    {
      operator delete(this->_Mypair._Myval2._Myhead);
      v2->_Mypair._Myval2._Myhead = 0;
      v2->_Mypair._Myval2._Mysize = 0;
      v2[1]._Mypair._Myval2._Myhead = 0;
    }
    v2->_Mypair._Myval2._Myhead = (std__Tree_node *)*a2;
    v2->_Mypair._Myval2._Mysize = (unsigned int)a2[1];
    v2[1]._Mypair._Myval2._Myhead = (std__Tree_node *)a2[2];
    *a2 = 0;
    a2[1] = 0;
    a2[2] = 0;
  }
  return v2;
}

//----- (00C04BC0) --------------------------------------------------------
std_Tree_node_for_tagKeyName **__thiscall sub_C04BC0(std__tree *this, IWbemClassObject *a2)
{
  std__tree *v2; // ebx
  std__Tree_node *v3; // esi
  std_Tree_node_for_tagKeyName *v4; // eax
  std_Tree_node_for_tagKeyName **v6; // eax
  _DWORD *a3; // [esp+Ch] [ebp-4h]

  v2 = this;
  v3 = this->_Mypair._Myval2._Myhead;
  v4 = this->_Mypair._Myval2._Myhead->_Parent;
  while ( !v4->_IsNil )
  {
    if ( (IWbemClassObjectVtbl *)v4->_Myval.first >= a2->lpVtbl )
    {
      v3 = (std__Tree_node *)v4;
      v4 = v4->_Left;
    }
    else
    {
      v4 = v4->_Right;
    }
  }
  if ( v3 != this->_Mypair._Myval2._Myhead && a2->lpVtbl >= (IWbemClassObjectVtbl *)v3[1]._Left )
    return &v3[1]._Parent;
  a3 = &a2->lpVtbl;
  v6 = sub_C03B60(this, (int)&dword_CD4D34, &a3, (int)&a2 + 3);
  sub_C04270(v2, (int)&a2, (int)v3, (int)(v6 + 4), v6);
  return (std_Tree_node_for_tagKeyName **)&a2[5];
}
// CD4D34: using guessed type int dword_CD4D34;

//----- (00C04C50) --------------------------------------------------------
std_Tree_node_for_tagKeyName **__thiscall sub_C04C50(CSystemProcessInfoMap *this, _DWORD *a2)
{
  CSystemProcessInfoMap *v2; // ebx
  std__Tree_node *v3; // esi
  std_Tree_node_for_tagKeyName *v4; // eax
  CSystemProcessInfoMapNode *v6; // eax
  _DWORD *v7; // [esp+Ch] [ebp-4h]

  v2 = this;
  v3 = this->_Header;
  v4 = this->_Header->_Parent;
  while ( !v4->_IsNil )
  {
    if ( (unsigned int)v4->_Myval.first >= *a2 )
    {
      v3 = (std__Tree_node *)v4;
      v4 = v4->_Left;
    }
    else
    {
      v4 = v4->_Right;
    }
  }
  if ( v3 != this->_Header && (std_Tree_node_for_tagKeyName *)*a2 >= v3[1]._Left )
    return &v3[1]._Parent;
  v7 = a2;
  v6 = sub_C03BA0(this, (int)&dword_CD4D34, (const wchar_t ***)&v7, (int)&a2 + 3);
  sub_C04040(v2, (int)&a2, (int)v3, (int)&v6->_Keyvalue, v6);
  return (std_Tree_node_for_tagKeyName **)(a2 + 5);
}
// CD4D34: using guessed type int dword_CD4D34;

//----- (00C04CE0) --------------------------------------------------------
std__tree *__thiscall sub_C04CE0(std__tree *this)
{
  std__tree *v1; // edx
  std__Tree_node *v2; // eax
  std__Tree_node *v3; // ecx
  std__Tree_node *v4; // eax
  std_Tree_node_for_tagKeyName *i; // eax

  v1 = this;
  v2 = this->_Mypair._Myval2._Myhead;
  if ( this->_Mypair._Myval2._Myhead->_IsNil )
    return v1;
  v3 = (std__Tree_node *)v2->_Right;
  if ( v3->_IsNil )
  {
    for ( i = v2->_Parent; !i->_IsNil; i = i->_Parent )
    {
      if ( v1->_Mypair._Myval2._Myhead != (std__Tree_node *)i->_Right )
        break;
      v1->_Mypair._Myval2._Myhead = (std__Tree_node *)i;
    }
    v1->_Mypair._Myval2._Myhead = (std__Tree_node *)i;
    return v1;
  }
  v4 = (std__Tree_node *)v3->_Left;
  if ( !v3->_Left->_IsNil )
  {
    do
    {
      v3 = v4;
      v4 = (std__Tree_node *)v4->_Left;
    }
    while ( !v4->_IsNil );
  }
  v1->_Mypair._Myval2._Myhead = v3;
  return v1;
}

//----- (00C04D30) --------------------------------------------------------
void *__thiscall std::error_category::`vector deleting destructor'(void *this, char a2)
{
  void *v2; // esi

  v2 = this;
  *(_DWORD *)this = &std::error_category::`vftable';
  if ( a2 & 1 )
    operator delete(this);
  return v2;
}
// CA2D74: using guessed type void *std::error_category::`vftable';

//----- (00C04D60) --------------------------------------------------------
void sub_C04D60()
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

//----- (00C04DA0) --------------------------------------------------------
HRESULT __cdecl LoadWbemServices(const wchar_t *lpszServerName, IWbemServices **ppv)
{
  tagStreamThreadInfo *v2; // esi
  tagStreamThreadInfo *v3; // eax
  HRESULT result; // eax
  HRESULT v5; // edi
  HANDLE v6; // eax

  v2 = gpStreamThreadInfo;
  if ( gpStreamThreadInfo )
  {
    gpStreamThreadInfo->pszServer = (WCHAR *)lpszServerName;
  }
  else
  {
    v3 = (tagStreamThreadInfo *)operator new(0x24u);
    if ( v3 )
      v2 = tagStreamThreadInfo_SetServer(v3, (volatile LONG)lpszServerName);
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

//----- (00C04E20) --------------------------------------------------------
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
    v9 = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)StreamToWbemServicesThreadProc, v3, 0, &ThreadId);
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
    result = CoGetInterfaceAndReleaseStream(v3->pStream, &CLSID_IWbemServices, (LPVOID *)ppWbemServices);
    v3->hresult = result;
    if ( result >= 0 )
      v3->pStream = 0;
  }
  else if ( v11 == -1 )
  {
    result = GetLastError();
    if ( result > 0 )
      result = (unsigned __int16)result | 0x80070000;
  }
  else
  {
    result = -2147024638;
  }
  return result;
}
// CCAA38: using guessed type char bInited;

//----- (00C04FE0) --------------------------------------------------------
WCHAR *__cdecl sub_C04FE0(int a1, CCmdString a2)
{
  WCHAR *result; // eax
  WCHAR *v3; // esi
  void *v4; // [esp+8h] [ebp-24h]
  void *v5; // [esp+Ch] [ebp-20h]
  void *v6; // [esp+10h] [ebp-1Ch]
  void *v7; // [esp+14h] [ebp-18h]
  void *v8; // [esp+18h] [ebp-14h]
  CCmdString str3; // [esp+1Ch] [ebp-10h]
  int v10; // [esp+28h] [ebp-4h]

  result = a2.m_String;
  if ( a2.m_String == (WCHAR *)-1 )
  {
    a2.m_String = _wcsdup(L"WMI Database Entries");
    v10 = 0;
    if ( !IsBuiltinAdministrative() )
      CCmdString::InsertAt(&a2, L" - run as Administrator for complete scan", 0x7FFFFFFFu, 0);
    v4 = _wcsdup((const wchar_t *)&gszNullString);
    v5 = _wcsdup((const wchar_t *)&gszNullString);
    v6 = _wcsdup((const wchar_t *)&gszNullString);
    v7 = _wcsdup((const wchar_t *)&gszNullString);
    v8 = _wcsdup((const wchar_t *)&gszNullString);
    str3.m_String = _wcsdup((const wchar_t *)&gszNullString);
    LOBYTE(v10) = 6;
    v3 = (WCHAR *)PE_UpdateSystemKey(a1, 2u, (HANDLE)0xFFFFFFFF, 0, &a2, &a2, &str3);
    free(str3.m_String);
    free(v8);
    free(v7);
    free(v6);
    free(v5);
    free(v4);
    free(a2.m_String);
    result = v3;
  }
  return result;
}

//----- (00C05120) --------------------------------------------------------
HRESULT __cdecl sub_C05120(IWbemServices *pWbemServices, std__vector *arr)
{
  IEnumWbemClassObject *v2; // eax
  HRESULT hr; // eax
  HRESULT v4; // ebx
  const WCHAR **v5; // ecx
  wchar_t *v6; // eax
  wchar_t *v7; // esi
  int *v8; // eax
  int *v9; // edx
  int v10; // ebx
  signed int v11; // eax
  unsigned int v12; // edx
  unsigned int v13; // edx
  const wchar_t **v14; // eax
  _DWORD *v15; // ebx
  wchar_t *v16; // eax
  int *v17; // edx
  signed int v18; // eax
  unsigned int v19; // edx
  unsigned int v20; // edx
  VARIANTARG vtName; // [esp+10h] [ebp-34h]
  unsigned int a2a; // [esp+20h] [ebp-24h]
  int nRet; // [esp+24h] [ebp-20h]
  IEnumWbemClassObject *ppEnumOut; // [esp+28h] [ebp-1Ch]
  wchar_t *v26; // [esp+2Ch] [ebp-18h]
  IWbemClassObject *pClassObject; // [esp+30h] [ebp-14h]
  HRESULT v28; // [esp+34h] [ebp-10h]
  int v29; // [esp+40h] [ebp-4h]

  v28 = 0;
  pClassObject = 0;
  GetQueryEnumObject(&ppEnumOut, pWbemServices, L"SELECT * FROM __NAMESPACE");
  v29 = 0;
  while ( 1 )
  {
    v2 = ppEnumOut;
    if ( !ppEnumOut )
    {
      v4 = v28;
      goto __quit;
    }
    hr = ppEnumOut->lpVtbl->Next(ppEnumOut, -1, 1, &pClassObject, (ULONG *)&nRet);
    if ( hr < 0 || hr || nRet != 1 )
      break;
    v4 = pClassObject->lpVtbl->Get(pClassObject, L"Name", 0, &vtName, 0, 0);
    v28 = v4;
    pClassObject->lpVtbl->Release(pClassObject);
    if ( v4 < 0 )
      goto LABEL_39;
    if ( vtName.vt != 8 )
    {
      v2 = ppEnumOut;
      v4 = E_INVALIDARG;
      goto __quit;
    }
    v5 = &gszNullString;
    if ( vtName.lVal )
      v5 = (const WCHAR **)vtName.lVal;
    v6 = _wcsdup((const wchar_t *)v5);
    v7 = v6;
    v26 = v6;
    v8 = (int *)arr->baseclass_0._Mypair._Myval2._Mylast;
    LOBYTE(v29) = 1;
    if ( &v26 >= (wchar_t **)v8 || arr->baseclass_0._Mypair._Myval2._Myfirst > &v26 )
    {
      v17 = (int *)arr->baseclass_0._Mypair._Myval2._Myend;
      if ( v8 == v17 && (unsigned int)(v17 - v8) < 1 )
      {
        v18 = ((char *)v8 - (char *)arr->baseclass_0._Mypair._Myval2._Myfirst) >> 2;
        if ( (unsigned int)(0x3FFFFFFF - v18) < 1 )
LABEL_36:
          std::_Xlength_error("vector<T> too long");
        v19 = ((char *)v17 - (char *)arr->baseclass_0._Mypair._Myval2._Myfirst) >> 2;
        a2a = v18 + 1;
        if ( 0x3FFFFFFF - (v19 >> 1) >= v19 )
          v20 = (v19 >> 1) + v19;
        else
          v20 = 0;
        if ( v20 < a2a )
          v20 = a2a;
        sub_BEFDF0(arr, v20);
      }
      v15 = arr->baseclass_0._Mypair._Myval2._Mylast;
      if ( v15 )
      {
        v16 = _wcsdup(v7);
        goto LABEL_34;
      }
    }
    else
    {
      v9 = (int *)arr->baseclass_0._Mypair._Myval2._Myend;
      v10 = ((char *)&v26 - (char *)arr->baseclass_0._Mypair._Myval2._Myfirst) >> 2;
      if ( v8 == v9 && (unsigned int)(v9 - v8) < 1 )
      {
        v11 = ((char *)v8 - (char *)arr->baseclass_0._Mypair._Myval2._Myfirst) >> 2;
        if ( (unsigned int)(0x3FFFFFFF - v11) < 1 )
          goto LABEL_36;
        v12 = ((char *)v9 - (char *)arr->baseclass_0._Mypair._Myval2._Myfirst) >> 2;
        a2a = v11 + 1;
        if ( 0x3FFFFFFF - (v12 >> 1) >= v12 )
          v13 = (v12 >> 1) + v12;
        else
          v13 = 0;
        if ( v13 < a2a )
          v13 = a2a;
        sub_BEFDF0(arr, v13);
      }
      v14 = (const wchar_t **)((char *)arr->baseclass_0._Mypair._Myval2._Myfirst + 4 * v10);
      v15 = arr->baseclass_0._Mypair._Myval2._Mylast;
      if ( v15 )
      {
        v16 = _wcsdup(*v14);
LABEL_34:
        *v15 = v16;
        goto LABEL_35;
      }
    }
LABEL_35:
    arr->baseclass_0._Mypair._Myval2._Mylast = (char *)arr->baseclass_0._Mypair._Myval2._Mylast + 4;
    LOBYTE(v29) = 0;
    free(v7);
    VariantClear(&vtName);
  }
  v4 = v28;
LABEL_39:
  v2 = ppEnumOut;
__quit:
  v29 = -1;
  if ( v2 )
    v2->lpVtbl->Release(v2);
  return v4;
}

//----- (00C05350) --------------------------------------------------------
char __stdcall sub_C05350(int a1, IWbemClassObject *pClassObject, CCmdString *a3)
{
  IWbemClassObject *v3; // edi
  CCmdString *v4; // eax
  CCmdString *v5; // ebx
  WCHAR *v6; // edi
  WCHAR *v7; // edi
  WCHAR *v8; // ecx
  WCHAR v9; // ax
  char v10; // bl
  CCmdString *v11; // edi
  WCHAR *v12; // ebx
  CCmdString strText; // [esp+Ch] [ebp-10h]
  int v15; // [esp+18h] [ebp-4h]

  v3 = pClassObject;
  GetClassObjectName((CCmdString *)&pClassObject, pClassObject, L"ScriptText");
  v15 = 0;
  if ( wcslen((const unsigned __int16 *)pClassObject) )
  {
    v11 = a3;
    v12 = a3->m_String;
    v11->m_String = _wcsdup(L"Script embedded in WMI database");
    free(v12);
    goto LABEL_8;
  }
  v4 = GetClassObjectName(&strText, v3, L"ScriptFileName");
  v5 = a3;
  v6 = a3->m_String;
  v5->m_String = _wcsdup(v4->m_String);
  free(v6);
  free(strText.m_String);
  v7 = v5->m_String;
  v8 = v5->m_String;
  do
  {
    v9 = *v8;
    ++v8;
  }
  while ( v9 );
  if ( !(v8 - (v5->m_String + 1)) )
  {
    v5->m_String = _wcsdup(L"Incorrectly created script entry");
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

//----- (00C05440) --------------------------------------------------------
bool __stdcall sub_C05440(int a1, void *lpszName, void *a3)
{
  CCmdString *v3; // eax
  WCHAR **v4; // edi
  void *v5; // esi
  WCHAR *v6; // ecx
  WCHAR v7; // ax
  CCmdString *v8; // eax
  WCHAR *v9; // esi
  WCHAR *v10; // ecx
  WCHAR v11; // ax
  const wchar_t **v12; // eax
  WCHAR *v13; // esi
  WCHAR *v14; // esi
  WCHAR v15; // ax
  int v16; // esi
  int a2; // [esp+Ch] [ebp-20h]
  int v19; // [esp+10h] [ebp-1Ch]
  int v20; // [esp+14h] [ebp-18h]
  int v21; // [esp+18h] [ebp-14h]
  IWbemClassObject pClassObject; // [esp+1Ch] [ebp-10h]
  int v23; // [esp+28h] [ebp-4h]

  v3 = GetClassObjectName((CCmdString *)&pClassObject, (IWbemClassObject *)lpszName, L"ExecutablePath");
  v4 = (WCHAR **)a3;
  v5 = *(void **)a3;
  *v4 = _wcsdup(v3->m_String);
  free(v5);
  free(pClassObject.lpVtbl);
  v6 = *v4;
  do
  {
    v7 = *v6;
    ++v6;
  }
  while ( v7 );
  if ( v6 - (*v4 + 1) )
    return 0;
  v8 = GetClassObjectName((CCmdString *)&lpszName, (IWbemClassObject *)lpszName, L"CommandLineTemplate");
  v9 = *v4;
  *v4 = _wcsdup(v8->m_String);
  free(v9);
  free(lpszName);
  v10 = *v4;
  do
  {
    v11 = *v10;
    ++v10;
  }
  while ( v11 );
  if ( !(v10 - (*v4 + 1)) )
    return 0;
  a2 = (int)malloc(2u);
  *(_WORD *)a2 = 0;
  v19 = 0;
  v20 = 0;
  v21 = 0;
  v23 = 0;
  if ( !sub_BE6CC0(*v4, (StringItem *)&a2) )
  {
    StringItem::~StringItem((tagPEStringStruct *)&a2);
    return 0;
  }
  v12 = (const wchar_t **)sub_BE4EE0((int)&a3, a1, (int)&a2, 0);
  v13 = *v4;
  *v4 = _wcsdup(*v12);
  free(v13);
  free(a3);
  v14 = *v4;
  do
  {
    v15 = *v14;
    ++v14;
  }
  while ( v15 );
  v16 = (char *)v14 - (char *)(*v4 + 1);
  StringItem::~StringItem((tagPEStringStruct *)&a2);
  return v16 >> 1 != 0;
}

//----- (00C055B0) --------------------------------------------------------
Data_t_bstr_t *__cdecl sub_C055B0(CCmdString *a1)
{
  std__Tree_node *v1; // edi
  std_Tree_node_for_tagKeyName *v2; // esi
  std_Tree_node_for_tagKeyName *v3; // eax
  std_Tree_node_for_tagKeyName *j; // eax
  std_Tree_node_for_tagKeyName *i; // eax

  v1 = gEventConsumerMap._Mypair._Myval2._Myhead;
  v2 = gEventConsumerMap._Mypair._Myval2._Myhead->_Left;
  if ( gEventConsumerMap._Mypair._Myval2._Myhead->_Left == (std_Tree_node_for_tagKeyName *)gEventConsumerMap._Mypair._Myval2._Myhead )
    return 0;
  while ( _wcsicmp((const wchar_t *)v2->_Myval.first, a1->m_String) )
  {
    if ( !v2->_IsNil )
    {
      v3 = v2->_Right;
      if ( v3->_IsNil )
      {
        for ( i = v2->_Parent; !i->_IsNil; i = i->_Parent )
        {
          if ( v2 != i->_Right )
            break;
          v2 = i;
        }
        v2 = i;
      }
      else
      {
        v2 = v2->_Right;
        for ( j = v3->_Left; !j->_IsNil; j = j->_Left )
          v2 = j;
      }
    }
    if ( v2 == (std_Tree_node_for_tagKeyName *)v1 )
      return 0;
  }
  return v2->_Myval.second.bstrText1.m_Data;
}

//----- (00C05630) --------------------------------------------------------
char __thiscall sub_C05630(void *this, int a2, IWbemClassObject *pObject, void **a4)
{
  IWbemClassObject *v4; // ebx
  CCmdString *v5; // eax
  void *v6; // esi
  char *v7; // eax
  __int16 v8; // cx
  char result; // al
  CCmdString strText; // [esp+Ch] [ebp-4h]

  v4 = (IWbemClassObject *)this;
  v5 = GetClassObjectName(&strText, pObject, L"ScriptFileName");
  v6 = *a4;
  *a4 = _wcsdup(v5->m_String);
  free(v6);
  free(strText.m_String);
  v7 = (char *)*a4;
  do
  {
    v8 = *(_WORD *)v7;
    v7 += 2;
  }
  while ( v8 );
  if ( (v7 - ((_BYTE *)*a4 + 2)) >> 1 )
    result = 1;
  else
    result = ((int (__thiscall *)(IWbemClassObject *, int, IWbemClassObject *, void **))v4->lpVtbl->AddRef)(
               v4,
               a2,
               pObject,
               a4);
  return result;
}

//----- (00C056B0) --------------------------------------------------------
char __thiscall sub_C056B0(void *this, int a2, IWbemClassObject *lpszName, void **a4)
{
  void *v4; // ebx
  CCmdString *v5; // eax
  void *v6; // esi
  char *v7; // eax
  __int16 v8; // cx
  char result; // al
  IWbemClassObject pClassObject; // [esp+Ch] [ebp-4h]

  v4 = this;
  v5 = GetClassObjectName((CCmdString *)&pClassObject, lpszName, L"CommandLineTemplate");
  v6 = *a4;
  *a4 = _wcsdup(v5->m_String);
  free(v6);
  free(pClassObject.lpVtbl);
  v7 = (char *)*a4;
  do
  {
    v8 = *(_WORD *)v7;
    v7 += 2;
  }
  while ( v8 );
  if ( (v7 - ((_BYTE *)*a4 + 2)) >> 1 )
    result = 1;
  else
    result = (*(int (__thiscall **)(void *, int, IWbemClassObject *, void **))(*(_DWORD *)v4 + 4))(v4, a2, lpszName, a4);
  return result;
}

//----- (00C05730) --------------------------------------------------------
IWbemContext *__cdecl PE_GetWbemContext(IWbemServices *pWbemServices, IWbemClassObject *pClassObject, OLECHAR *psz, void *lpszText)
{
  IWbemContext *v4; // ebx
  WCHAR *v5; // edi
  CCmdString *v6; // eax
  WCHAR *pszServiceName; // esi
  char v8; // bl
  unsigned int v9; // ecx
  MACRO_HRESULT v10; // eax
  CCmdString strName; // [esp+10h] [ebp-18h]
  IWbemContext *pContext; // [esp+14h] [ebp-14h]
  CCmdString v14; // [esp+18h] [ebp-10h]
  int v15; // [esp+24h] [ebp-4h]

  v4 = 0;
  pContext = 0;
  v5 = (WCHAR *)malloc(2u);
  v14.m_String = v5;
  *v5 = 0;
  v15 = 0;
  v6 = GetClassObjectName(&strName, pClassObject, psz);
  pszServiceName = _wcsdup(v6->m_String);
  v14.m_String = pszServiceName;
  free(v5);
  free(strName.m_String);
  if ( wcslen(pszServiceName) )
  {
    if ( lpszText )
    {
      v8 = 0;
      v9 = wcslen(pszServiceName);
      if ( pszServiceName[v9 - 1] == 34 )
      {
        v8 = 1;
        pszServiceName[v9 - 1] = 0;
      }
      CCmdString::InsertAt(&v14, (const wchar_t *)lpszText, 0x7FFFFFFFu, 0);
      if ( v8 )
        CCmdString::InsertAt(&v14, L"\"", 0x7FFFFFFFu, 0);
      pszServiceName = v14.m_String;
    }
    v10 = PE_LoadWbemContext(pWbemServices, pszServiceName, &pContext);
    v4 = pContext;
    if ( (v10 & 0x80000000) != 0 )
      v4 = 0;
  }
  free(pszServiceName);
  return v4;
}

//----- (00C05850) --------------------------------------------------------
MACRO_HRESULT __cdecl PE_LoadWbemContext(IWbemServices *pWbemServices, LPCWSTR lpszServiceName, IWbemContext **ppContext)
{
  IWbemContext **v3; // esi
  OLECHAR *v4; // edi
  const WCHAR *v5; // ST14_4
  MACRO_HRESULT result; // eax
  bool v7; // bl
  OLECHAR **v8; // edx
  OLECHAR *v9; // edx
  HRESULT v10; // eax
  HRESULT v11; // edi
  IWbemContext *pWbemContet; // [esp+10h] [ebp-10h]
  int v13; // [esp+1Ch] [ebp-4h]

  v3 = ppContext;
  v4 = (OLECHAR *)lpszServiceName;
  v5 = lpszServiceName;
  *ppContext = 0;
  result = PE_LoadWbemServices((IWbemServices *)&pWbemServices, v5);
  if ( (result & 0x80000000) == 0 )
  {
    v7 = result == 0;
    v8 = *_bstr_t::_bstr_t((tagEventSetItem *)&ppContext, v4);
    v13 = 0;
    if ( v8 )
      v9 = *v8;
    else
      v9 = 0;
    v10 = pWbemServices->lpVtbl->GetObjectA(pWbemServices, v9, 0, 0, (IWbemClassObject **)&pWbemContet, 0);
    v13 = -1;
    v11 = v10;
    _bstr_t::_Free((_bstr_t *)&ppContext);
    if ( v11 >= 0 )
      *v3 = pWbemContet;
    if ( v7 )
      pWbemServices->lpVtbl->Release(pWbemServices);
    result = v11;
  }
  return result;
}

//----- (00C05910) --------------------------------------------------------
int __stdcall sub_C05910(CCmdString a1, int a2)
{
  *(_DWORD *)a1.m_String = _wcsdup((const wchar_t *)&gszNullString);
  return (int)a1.m_String;
}

//----- (00C05940) --------------------------------------------------------
int __stdcall sub_C05940(int pClassObject, void *lpszName)
{
  IWbemClassObject *v2; // esi
  __int16 *v3; // eax
  __int16 v4; // cx
  CCmdString *v5; // eax
  __int16 *v6; // esi

  v2 = (IWbemClassObject *)lpszName;
  GetClassObjectName((CCmdString *)pClassObject, (IWbemClassObject *)lpszName, L"CommandLineTemplate");
  v3 = *(__int16 **)pClassObject;
  do
  {
    v4 = *v3;
    ++v3;
  }
  while ( v4 );
  if ( !((signed int)((char *)v3 - *(_DWORD *)pClassObject - 2) >> 1) )
  {
    v5 = GetClassObjectName((CCmdString *)&lpszName, v2, L"ExecutablePath");
    v6 = *(__int16 **)pClassObject;
    *(_DWORD *)pClassObject = _wcsdup(v5->m_String);
    free(v6);
    free(lpszName);
  }
  return pClassObject;
}

//----- (00C05A00) --------------------------------------------------------
char __stdcall sub_C05A00(void *lpszName, int a2, int a3)
{
  CCmdString *v3; // eax
  wchar_t **v4; // edi
  void *v5; // esi
  wchar_t *v6; // eax
  wchar_t v7; // cx
  CCmdString *v8; // eax
  wchar_t **v9; // esi
  void *v10; // edi
  IWbemClassObject pClassObject; // [esp+8h] [ebp-4h]

  v3 = GetClassObjectName((CCmdString *)&pClassObject, (IWbemClassObject *)lpszName, L"ScriptText");
  v4 = (wchar_t **)a3;
  v5 = *(void **)a3;
  *v4 = _wcsdup(v3->m_String);
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
  v8 = GetClassObjectName((CCmdString *)&lpszName, (IWbemClassObject *)lpszName, L"ScriptingEngine");
  v9 = (wchar_t **)a2;
  v10 = *(void **)a2;
  *v9 = _wcsdup(v8->m_String);
  free(v10);
  free(lpszName);
  return 1;
}

//----- (00C05AA0) --------------------------------------------------------
char __stdcall sub_C05AA0(int a1, int a2, int a3)
{
  return 0;
}

//----- (00C05AB0) --------------------------------------------------------
CCmdString *__cdecl GetClassObjectName(CCmdString *strText, IWbemClassObject *pClassObject, LPCWSTR lpszText)
{
  const WCHAR **v3; // edx
  const WCHAR *v4; // edx
  HRESULT v5; // eax
  Data_t_bstr_t *v6; // esi
  HRESULT v7; // edi
  const WCHAR **v8; // ecx
  wchar_t *v9; // esi
  CCmdString *result; // eax
  VARIANTARG pvarg; // [esp+Ch] [ebp-24h]
  int v12; // [esp+1Ch] [ebp-14h]
  _bstr_t v13; // [esp+20h] [ebp-10h]
  int v14; // [esp+2Ch] [ebp-4h]

  v12 = 0;
  v3 = (const WCHAR **)*_bstr_t::_bstr_t((tagEventSetItem *)&v13, (OLECHAR *)lpszText);
  v14 = 0;
  if ( v3 )
    v4 = *v3;
  else
    v4 = 0;
  v5 = pClassObject->lpVtbl->Get(pClassObject, v4, 0, &pvarg, 0, 0);
  v6 = v13.m_Data;
  v7 = v5;
  if ( v13.m_Data && !InterlockedDecrement(&v13.m_Data->m_RefCount) && v6 )
  {
    if ( v6->m_wstr )
    {
      SysFreeString(v6->m_wstr);
      v6->m_wstr = 0;
    }
    if ( v6->m_str )
    {
      operator delete[](v6->m_str);
      v6->m_str = 0;
    }
    operator delete(v6);
  }
  if ( v7 < 0 || pvarg.vt != 8 )
  {
    strText->m_String = _wcsdup((const wchar_t *)&gszNullString);
    result = strText;
  }
  else
  {
    v8 = &gszNullString;
    if ( pvarg.lVal )
      v8 = (const WCHAR **)pvarg.lVal;
    v9 = _wcsdup((const wchar_t *)v8);
    VariantClear(&pvarg);
    strText->m_String = _wcsdup(v9);
    free(v9);
    result = strText;
  }
  return result;
}

//----- (00C05BE0) --------------------------------------------------------
MACRO_HRESULT __cdecl PE_LoadWbemServices(IWbemServices *pWbemServices, LPCWSTR lpszServiceName)
{
  WCHAR *v2; // eax
  CCmdString strServiceName; // edi
  MACRO_HRESULT result; // eax
  wchar_t *v5; // eax
  HRESULT v6; // esi

  if ( *lpszServiceName != '\\' )
    return 1;
  v2 = _wcsdup(lpszServiceName);
  strServiceName.m_String = v2;
  if ( !v2 )
    return E_OUTOFMEMORY;
  v5 = wcschr(v2, ':');
  if ( !v5 )
  {
    free(strServiceName.m_String);
    return 1;
  }
  *v5 = 0;
  v6 = LoadWbemServices(strServiceName.m_String, (IWbemServices **)pWbemServices);
  free(strServiceName.m_String);
  result = 0;
  if ( v6 < 0 )
    result = v6;
  return result;
}

//----- (00C05C50) --------------------------------------------------------
bool __stdcall sub_C05C50(void *pClassObject, int a2)
{
  CCmdString *v2; // eax
  wchar_t **v3; // edi
  void *v4; // esi
  wchar_t *v5; // eax
  wchar_t v6; // cx

  v2 = GetClassObjectName((CCmdString *)&pClassObject, (IWbemClassObject *)pClassObject, L"WorkingDirectory");
  v3 = (wchar_t **)a2;
  v4 = *(void **)a2;
  *v3 = _wcsdup(v2->m_String);
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

//----- (00C05CB0) --------------------------------------------------------
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
    operator delete(v1);
  }
}

//----- (00C05D10) --------------------------------------------------------
void __cdecl sub_C05D10(int a1)
{
  void **v1; // ebx
  void **v2; // edi
  IEnumWbemClassObject *pEnum_1; // eax
  HRESULT hresult; // eax
  CCmdString *v5; // eax
  bool v6; // bl
  std_Tree_node_for_tagKeyName **v7; // eax
  const wchar_t **v8; // ebx
  const wchar_t **v9; // esi
  wchar_t *v10; // edi
  void **v11; // esi
  void **v12; // edi
  HRESULT v13; // eax
  void *v14; // ebx
  const wchar_t **v15; // esi
  IEnumWbemClassObject *v16; // eax
  void *v17; // edi
  int v18; // eax
  void *v19; // eax
  tagStreamThreadInfo *v20; // esi
  HANDLE v21; // eax
  std__Tree_node *v22; // ebx
  std__Tree_node *v23; // esi
  IWbemClassObject *v24; // edi
  CCmdString *v25; // eax
  CCmdString *v26; // eax
  WCHAR *v27; // edi
  CCmdString *v28; // eax
  WCHAR *v29; // edi
  WCHAR *v30; // edi
  IWbemClassObject *v31; // edi
  const wchar_t **v32; // eax
  WCHAR *v33; // edi
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
  CCmdString *v48; // esi
  IWbemClassObjectVtbl *v49; // edi
  WCHAR *v50; // eax
  WCHAR v51; // cx
  void *v52; // edi
  wchar_t *v53; // eax
  void *v54; // edi
  wchar_t *v55; // eax
  std_Tree_node_for_tagKeyName *v56; // edi
  WCHAR **v57; // ecx
  WCHAR **v58; // ebx
  WCHAR **v59; // esi
  std__Tree_node_For__bstr_t *v60; // eax
  std__Tree_node *j; // eax
  std_Tree_node_for_tagKeyName *i; // eax
  void **k; // esi
  IWbemClassObject v64; // [esp+10h] [ebp-B4h]
  IWbemClassObject v65; // [esp+14h] [ebp-B0h]
  IWbemClassObject v66; // [esp+18h] [ebp-ACh]
  IWbemClassObject v67; // [esp+1Ch] [ebp-A8h]
  void *v68; // [esp+20h] [ebp-A4h]
  CCmdString v69; // [esp+24h] [ebp-A0h]
  int a8; // [esp+28h] [ebp-9Ch]
  int v71; // [esp+2Ch] [ebp-98h]
  void *v72; // [esp+30h] [ebp-94h]
  void *v73; // [esp+34h] [ebp-90h]
  CCmdString v74; // [esp+38h] [ebp-8Ch]
  LPCWSTR lpszSystemPath; // [esp+3Ch] [ebp-88h]
  wchar_t *v76; // [esp+40h] [ebp-84h]
  int v77; // [esp+44h] [ebp-80h]
  wchar_t *v78; // [esp+48h] [ebp-7Ch]
  void *v79; // [esp+4Ch] [ebp-78h]
  CCmdString strName; // [esp+50h] [ebp-74h]
  void *ppv1; // [esp+54h] [ebp-70h]
  std__tree theMap; // [esp+58h] [ebp-6Ch]
  std__vector v83; // [esp+60h] [ebp-64h]
  CCmdString str2; // [esp+6Ch] [ebp-58h]
  WCHAR **v85; // [esp+70h] [ebp-54h]
  IEnumWbemClassObject *pEnum; // [esp+74h] [ebp-50h]
  void *v87; // [esp+78h] [ebp-4Ch]
  void *cbReturned; // [esp+7Ch] [ebp-48h]
  int v89; // [esp+80h] [ebp-44h]
  std__vector arr; // [esp+84h] [ebp-40h]
  IWbemClassObject *pClassObject; // [esp+90h] [ebp-34h]
  char v92; // [esp+97h] [ebp-2Dh]
  IWbemServices *pWbemServices; // [esp+98h] [ebp-2Ch]
  IWbemClassObject *pClassObject1; // [esp+9Ch] [ebp-28h]
  WCHAR *ppv3; // [esp+A0h] [ebp-24h]
  IEnumWbemClassObject *ppEnumOut; // [esp+A4h] [ebp-20h]
  wchar_t *a2; // [esp+A8h] [ebp-1Ch]
  WCHAR *ppv; // [esp+ACh] [ebp-18h]
  wchar_t *psz; // [esp+B0h] [ebp-14h]
  wchar_t *a4; // [esp+B4h] [ebp-10h]
  int v101; // [esp+C0h] [ebp-4h]

  v1 = 0;
  pWbemServices = 0;
  v2 = 0;
  v83.baseclass_0._Mypair._Myval2._Mylast = 0;
  v83.baseclass_0._Mypair._Myval2._Myfirst = 0;
  v83.baseclass_0._Mypair._Myval2._Myend = 0;
  v101 = 0;
  pClassObject1 = 0;
  theMap._Mypair._Myval2._Mysize = 0;
  theMap._Mypair._Myval2._Myhead = (std__Tree_node *)std::_Tree_comp_alloc<std::_Tmap_traits<wchar_t const *,tagKeyName,std::less<wchar_t const *>,std::allocator<std::pair<wchar_t const * const,tagKeyName>>,0>>::_Buyheadnode();
  ppv3 = (WCHAR *)malloc(2u);
  *ppv3 = 0;
  str2.m_String = (WCHAR *)malloc(2u);
  *str2.m_String = 0;
  v87 = malloc(2u);
  *(_WORD *)v87 = 0;
  v79 = malloc(2u);
  *(_WORD *)v79 = 0;
  v74.m_String = (WCHAR *)malloc(2u);
  *v74.m_String = 0;
  v73 = malloc(2u);
  *(_WORD *)v73 = 0;
  psz = (wchar_t *)malloc(2u);
  *psz = 0;
  v78 = (wchar_t *)malloc(2u);
  *v78 = 0;
  v76 = (wchar_t *)malloc(2u);
  *v76 = 0;
  lpszSystemPath = (LPCWSTR)malloc(2u);
  *lpszSystemPath = 0;
  LOBYTE(v101) = 11;
  ppv1 = sub_C04FE0(a1, (CCmdString)-1);
  if ( CoInitializeEx(0, 0) >= 0 )
  {
    if ( IsBuiltinAdministrative() )
      gdwTimeout *= 4;
    if ( LoadWbemServices(L"ROOT\\subscription", &pWbemServices) >= 0 )
    {
      GetQueryEnumObject(&pEnum, pWbemServices, L"SELECT * FROM __EventConsumer");
      pEnum_1 = pEnum;
      LOBYTE(v101) = 12;
      if ( pEnum )
      {
        while ( pEnum_1 )
        {
          hresult = pEnum_1->lpVtbl->Next(pEnum_1, -1, 1, &pClassObject1, (ULONG *)&cbReturned);
          if ( hresult < 0 || hresult || cbReturned != (void *)1 )
            break;
          v5 = GetClassObjectName(&strName, pClassObject1, L"__CLASS");
          v6 = sub_C055B0(v5) != 0;
          free(strName.m_String);
          if ( v6 )
          {
            arr.baseclass_0._Mypair._Myval2._Myfirst = 0;
            arr.baseclass_0._Mypair._Myval2._Mylast = 0;
            arr.baseclass_0._Mypair._Myval2._Myend = 0;
            LOBYTE(v101) = 13;
            v7 = sub_C04BC0(&theMap, (IWbemClassObject *)&pClassObject1);
            sub_C04B60((std__tree *)v7, &arr.baseclass_0._Mypair._Myval2._Myfirst);
            LOBYTE(v101) = 12;
            if ( arr.baseclass_0._Mypair._Myval2._Myfirst )
            {
              operator delete(arr.baseclass_0._Mypair._Myval2._Myfirst);
              pEnum_1 = pEnum;
              arr.baseclass_0._Mypair._Myval2._Myfirst = 0;
              arr.baseclass_0._Mypair._Myval2._Mylast = 0;
              arr.baseclass_0._Mypair._Myval2._Myend = 0;
            }
            else
            {
              pEnum_1 = pEnum;
            }
          }
          else
          {
            pClassObject1->lpVtbl->Release(pClassObject1);
            pEnum_1 = pEnum;
          }
        }
        v1 = (void **)v83.baseclass_0._Mypair._Myval2._Mylast;
      }
      if ( theMap._Mypair._Myval2._Mysize )
      {
        a2 = _wcsdup(L"ROOT");
        LOBYTE(v101) = 14;
        sub_BF0530(&v83, (const wchar_t **)&a2);
        LOBYTE(v101) = 12;
        free(a2);
        v8 = (const wchar_t **)v83.baseclass_0._Mypair._Myval2._Mylast;
        v9 = (const wchar_t **)v83.baseclass_0._Mypair._Myval2._Myfirst;
        if ( (v83.baseclass_0._Mypair._Myval2._Mylast - v83.baseclass_0._Mypair._Myval2._Myfirst) & 0xFFFFFFFC )
        {
          do
          {
            v10 = _wcsdup(*v9);
            a2 = v10;
            LOBYTE(v101) = 15;
            sub_C04700((int)(v9 + 1), v8, (StringItem *)v9);
            --v8;
            v11 = (void **)v8;
            if ( v8 != v83.baseclass_0._Mypair._Myval2._Mylast )
            {
              v12 = (void **)v83.baseclass_0._Mypair._Myval2._Mylast;
              do
              {
                free(*v11);
                ++v11;
              }
              while ( v11 != v12 );
              v10 = a2;
            }
            v83.baseclass_0._Mypair._Myval2._Mylast = v8;
            if ( LoadWbemServices(v10, &pWbemServices) >= 0 )
            {
              arr.baseclass_0._Mypair._Myval2._Myfirst = 0;
              arr.baseclass_0._Mypair._Myval2._Mylast = 0;
              arr.baseclass_0._Mypair._Myval2._Myend = 0;
              LOBYTE(v101) = 16;
              v13 = sub_C05120(pWbemServices, &arr);
              v14 = arr.baseclass_0._Mypair._Myval2._Mylast;
              v15 = (const wchar_t **)arr.baseclass_0._Mypair._Myval2._Myfirst;
              if ( v13 >= 0 )
              {
                if ( arr.baseclass_0._Mypair._Myval2._Myfirst != arr.baseclass_0._Mypair._Myval2._Mylast )
                {
                  do
                  {
                    ppv = _wcsdup(v10);
                    LOBYTE(v101) = 17;
                    CCmdString::InsertAt((CCmdString *)&ppv, L"\\", 0x7FFFFFFFu, 0);
                    CCmdString::InsertAt((CCmdString *)&ppv, *v15, 0x7FFFFFFFu, 0);
                    sub_BF0530(&v83, (const wchar_t **)&ppv);
                    LOBYTE(v101) = 16;
                    free(ppv);
                    ++v15;
                  }
                  while ( v15 != v14 );
                }
                v15 = (const wchar_t **)arr.baseclass_0._Mypair._Myval2._Myfirst;
              }
              GetQueryEnumObject(&ppEnumOut, pWbemServices, L"SELECT * FROM __FilterToConsumerBinding");
              v16 = ppEnumOut;
              LOBYTE(v101) = 18;
              if ( ppEnumOut )
              {
                v17 = ppv1;
                while ( v16 )
                {
                  v18 = v16->lpVtbl->Next(v16, -1, 1, &pClassObject1, (ULONG *)&cbReturned);
                  if ( v18 < 0 || v18 || cbReturned != (void *)1 )
                    break;
                  sub_C06830(a1, (int)v17, pWbemServices, pClassObject1, &theMap);
                  pClassObject1->lpVtbl->Release(pClassObject1);
                  v16 = ppEnumOut;
                }
                v10 = a2;
              }
              pWbemServices->lpVtbl->Release(pWbemServices);
              LOBYTE(v101) = 16;
              if ( ppEnumOut )
                ppEnumOut->lpVtbl->Release(ppEnumOut);
              if ( v15 )
              {
                v19 = arr.baseclass_0._Mypair._Myval2._Myfirst;
                if ( arr.baseclass_0._Mypair._Myval2._Myfirst != v14 )
                {
                  do
                  {
                    free((void *)*v15);
                    ++v15;
                  }
                  while ( v15 != v14 );
                  v19 = arr.baseclass_0._Mypair._Myval2._Myfirst;
                }
                operator delete(v19);
                arr.baseclass_0._Mypair._Myval2._Myfirst = 0;
                arr.baseclass_0._Mypair._Myval2._Mylast = 0;
                arr.baseclass_0._Mypair._Myval2._Myend = 0;
              }
              LOBYTE(v101) = 12;
              free(v10);
              v8 = (const wchar_t **)v83.baseclass_0._Mypair._Myval2._Mylast;
            }
            else
            {
              LOBYTE(v101) = 12;
              free(v10);
            }
            v9 = (const wchar_t **)v83.baseclass_0._Mypair._Myval2._Myfirst;
          }
          while ( ((char *)v8 - (char *)v83.baseclass_0._Mypair._Myval2._Myfirst) & 0xFFFFFFFC );
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
        v22 = theMap._Mypair._Myval2._Myhead;
        a2 = (wchar_t *)theMap._Mypair._Myval2._Myhead;
        v23 = (std__Tree_node *)theMap._Mypair._Myval2._Myhead->_Left;
        ppv = (WCHAR *)v23;
        if ( v23 != theMap._Mypair._Myval2._Myhead )
        {
          do
          {
            pClassObject = (IWbemClassObject *)v23[1]._Left;
            v24 = pClassObject;
            v25 = GetClassObjectName((CCmdString *)&v65, pClassObject, L"__CLASS");
            ppEnumOut = (IEnumWbemClassObject *)sub_C055B0(v25);
            free(v65.lpVtbl);
            strName.m_String = (WCHAR *)4;
            v77 = 1;
            v26 = GetClassObjectName((CCmdString *)&v67, v24, L"Name");
            v27 = ppv3;
            ppv3 = _wcsdup(v26->m_String);
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
              v28 = GetClassObjectName((CCmdString *)&v64, pClassObject, L"__PATH");
              v29 = ppv3;
              ppv3 = _wcsdup(v28->m_String);
              free(v29);
              free(v64.lpVtbl);
            }
            v31 = pClassObject;
            if ( ((unsigned __int8 (__stdcall *)(int, IWbemClassObject *, wchar_t **))ppEnumOut->lpVtbl->AddRef)(
                   a1,
                   pClassObject,
                   &psz) )
            {
              v32 = (const wchar_t **)((int (__stdcall *)(void **, IWbemClassObject *))ppEnumOut->lpVtbl->QueryInterface)(
                                        &v68,
                                        v31);
              v33 = str2.m_String;
              str2.m_String = _wcsdup(*v32);
              free(v33);
              free(v68);
              if ( ((unsigned __int8 (__stdcall *)(IWbemClassObject *, LPCWSTR *))ppEnumOut->lpVtbl->Reset)(
                     pClassObject,
                     &lpszSystemPath) )
              {
                a4 = (wchar_t *)malloc(2u);
                *a4 = 0;
                LOBYTE(v101) = 19;
                if ( PE_GetPathName(a1, lpszSystemPath, psz, (CCmdString *)&a4) )
                {
                  v34 = psz;
                  psz = _wcsdup(a4);
                  free(v34);
                }
                LOBYTE(v101) = 12;
                free(a4);
              }
              strName.m_String = (WCHAR *)sub_BE4ED0();
            }
            else
            {
              v35 = psz;
              if ( wcslen(psz) )
              {
                psz = _wcsdup((const wchar_t *)&gszNullString);
                free(v35);
                v36 = v87;
                v87 = _wcsdup(psz);
                free(v36);
              }
            }
            ((void (__stdcall *)(int, IWbemClassObject *, void **))ppEnumOut->lpVtbl->Release)(a1, pClassObject, &v73);
            v72 = _wcsdup(L"WMI Database Entries");
            v69.m_String = _wcsdup((const wchar_t *)&gszNullString);
            LOBYTE(v101) = 21;
            v92 = sub_BE3D40(
                    a1,
                    (CCmdString)&v69,
                    (int)&v72,
                    (int)&str2,
                    (int)&psz,
                    (int)&v79,
                    (CCmdString)&v74,
                    (int)&a8);
            free(v69.m_String);
            LOBYTE(v101) = 12;
            free(v72);
            if ( v92 )
            {
              v37 = (char *)operator new(0x18u);
              a4 = (wchar_t *)v37;
              if ( v37 )
              {
                v38 = malloc(2u);
                *((_DWORD *)v37 + 3) = v38;
                *v38 = 0;
                v39 = malloc(2u);
                *((_DWORD *)v37 + 4) = v39;
                *v39 = 0;
                v40 = malloc(2u);
                *((_DWORD *)v37 + 5) = v40;
                *v40 = 0;
                v37[8] = 0;
                *(_DWORD *)v37 = 0;
                *((_DWORD *)v37 + 1) = 0;
              }
              else
              {
                v37 = 0;
                a4 = 0;
              }
              v41 = pClassObject;
              *((_DWORD *)v37 + 1) = pClassObject;
              v41->lpVtbl->AddRef(v41);
              v42 = (WCHAR **)(v37 + 12);
              v43 = (void *)*((_DWORD *)v37 + 3);
              v85 = v42;
              v44 = _wcsdup((const wchar_t *)&gszNullString);
              *((_DWORD *)a4 + 3) = v44;
              free(v43);
              if ( ((char *)v23[1]._Right - (char *)v23[1]._Parent) & 0xFFFFFFFC )
              {
                v45 = (IWbemClassObject **)v23[1]._Parent;
                v46 = (char *)v23[1]._Right - (char *)v45;
                v71 = 0;
                v47 = (unsigned int)(v46 + 3) >> 2;
                if ( (std__Tree_node_For__bstr_t *)v45 > v23[1]._Right )
                  v47 = 0;
                v89 = v47;
                if ( v47 )
                {
                  v48 = (CCmdString *)v85;
                  do
                  {
                    GetClassObjectName((CCmdString *)&v66, *v45, L"Query");
                    v49 = v66.lpVtbl;
                    if ( wcslen((const unsigned __int16 *)v66.lpVtbl) )
                    {
                      v50 = v48->m_String;
                      do
                      {
                        v51 = *v50;
                        ++v50;
                      }
                      while ( v51 );
                      if ( v50 - (v48->m_String + 1) )
                        CCmdString::InsertAt(v48, L"; ", 0x7FFFFFFFu, 0);
                      CCmdString::InsertAt(v48, (const wchar_t *)v49, 0x7FFFFFFFu, 0);
                    }
                    free(v49);
                    ++v45;
                    ++v71;
                  }
                  while ( v71 != v89 );
                  v23 = (std__Tree_node *)ppv;
                }
                v22 = (std__Tree_node *)a2;
              }
              else
              {
                v77 = 0;
              }
              if ( ((unsigned __int8 (__stdcall *)(IWbemClassObject *, wchar_t **, wchar_t **))ppEnumOut->lpVtbl->Next)(
                     pClassObject,
                     &v78,
                     &v76) )
              {
                v52 = (void *)*((_DWORD *)a4 + 4);
                v53 = _wcsdup(v78);
                *((_DWORD *)a4 + 4) = v53;
                free(v52);
                v54 = (void *)*((_DWORD *)a4 + 5);
                v55 = _wcsdup(v76);
                *((_DWORD *)a4 + 5) = v55;
                free(v54);
                *((_BYTE *)a4 + 8) = 1;
              }
              ppv1 = sub_C04FE0(a1, (CCmdString)ppv1);
              cbReturned = _wcsdup((const wchar_t *)&gszNullString);
              LOBYTE(v101) = 22;
              PE_UpdateSystemKey(
                a1,
                (DWORD)strName.m_String,
                ppv1,
                0x11u,
                (CCmdString *)&ppv3,
                &str2,
                (CCmdString *)&psz);
              LOBYTE(v101) = 12;
              free(cbReturned);
            }
            pClassObject->lpVtbl->Release(pClassObject);
            v56 = v23[1]._Parent;
            v57 = (WCHAR **)((unsigned int)((char *)v23[1]._Right - (char *)v56 + 3) >> 2);
            if ( (std__Tree_node_For__bstr_t *)v56 > v23[1]._Right )
              v57 = 0;
            v85 = v57;
            if ( v57 )
            {
              v58 = 0;
              v59 = v57;
              do
              {
                ((void (__stdcall *)(std_Tree_node_for_tagKeyName *))v56->_Left->_Left->_Right)(v56->_Left);
                v58 = (WCHAR **)((char *)v58 + 1);
                v56 = (std_Tree_node_for_tagKeyName *)((char *)v56 + 4);
              }
              while ( v58 != v59 );
              v23 = (std__Tree_node *)ppv;
              v22 = (std__Tree_node *)a2;
            }
            if ( !v23->_IsNil )
            {
              v60 = v23->_Right;
              if ( v60->_IsNil )
              {
                for ( i = v23->_Parent; !i->_IsNil; i = i->_Parent )
                {
                  if ( v23 != (std__Tree_node *)i->_Right )
                    break;
                  v23 = (std__Tree_node *)i;
                }
                v23 = (std__Tree_node *)i;
                ppv = (WCHAR *)i;
              }
              else
              {
                v23 = (std__Tree_node *)v23->_Right;
                ppv = (WCHAR *)v60;
                for ( j = (std__Tree_node *)v60->_Left; !j->_IsNil; j = (std__Tree_node *)j->_Left )
                {
                  v23 = j;
                  ppv = (WCHAR *)j;
                }
              }
            }
          }
          while ( v23 != v22 );
        }
        v2 = (void **)v83.baseclass_0._Mypair._Myval2._Myfirst;
        v1 = (void **)v83.baseclass_0._Mypair._Myval2._Mylast;
      }
      else
      {
        sub_C04D60();
      }
      LOBYTE(v101) = 11;
      if ( pEnum )
        pEnum->lpVtbl->Release(pEnum);
    }
  }
  free((void *)lpszSystemPath);
  free(v76);
  free(v78);
  free(psz);
  free(v73);
  free(v74.m_String);
  free(v79);
  free(v87);
  free(str2.m_String);
  free(ppv3);
  LOBYTE(v101) = 0;
  sub_C071F0(
    (CSystemProcessInfoMap *)&theMap,
    (int)&v89,
    theMap._Mypair._Myval2._Myhead->_Left,
    (int)theMap._Mypair._Myval2._Myhead);
  operator delete(theMap._Mypair._Myval2._Myhead);
  if ( v2 )
  {
    for ( k = v2; k != v1; ++k )
      free(*k);
    operator delete(v2);
  }
}

//----- (00C06830) --------------------------------------------------------
unsigned int __cdecl sub_C06830(int a1, int a2, IWbemServices *pWbemServices, IWbemClassObject *pClassObjectIn, std__tree *a5)
{
  IWbemContext *v5; // eax
  IWbemContext *v6; // esi
  IWbemContext *v7; // ebx
  int v8; // ebx
  int v9; // esi
  WCHAR *v10; // edi
  IWbemContext *pContext2; // [esp+10h] [ebp-2Ch]
  CCmdString v13; // [esp+14h] [ebp-28h]
  CCmdString strClassName2; // [esp+18h] [ebp-24h]
  IWbemContext *pContext; // [esp+1Ch] [ebp-20h]
  CCmdString strText; // [esp+20h] [ebp-1Ch]
  IWbemContext *v17; // [esp+24h] [ebp-18h]
  std__tree v18; // [esp+28h] [ebp-14h]
  int v19; // [esp+38h] [ebp-4h]

  v18._Mypair._Myval2._Mysize = 0;
  pContext = PE_GetWbemContext(pWbemServices, pClassObjectIn, L"Consumer", 0);
  v5 = PE_GetWbemContext(pWbemServices, pClassObjectIn, L"Filter", 0);
  v6 = pContext;
  v7 = v5;
  v17 = v5;
  pContext2 = v5;
  if ( pContext )
  {
    if ( v5 )
    {
      GetClassObjectName(&strClassName2, (IWbemClassObject *)pContext, L"__CLASS");
      v19 = 0;
      if ( sub_C055B0(&strClassName2) )
      {
        GetClassObjectName(&strText, (IWbemClassObject *)v6, L"__PATH");
        LOBYTE(v19) = 1;
        v8 = (int)a5->_Mypair._Myval2._Myhead;
        v9 = (int)a5->_Mypair._Myval2._Myhead->_Left;
        v18._Mypair._Myval2._Myhead = (std__Tree_node *)v9;
        if ( v9 == v8 )
        {
LABEL_7:
          v7 = v17;
        }
        else
        {
          while ( 1 )
          {
            GetClassObjectName(&v13, *(IWbemClassObject **)(v9 + 16), L"__PATH");
            v10 = v13.m_String;
            LOBYTE(v19) = 2;
            if ( !_wcsicmp(strText.m_String, v13.m_String) )
              break;
            LOBYTE(v19) = 1;
            free(v10);
            sub_C04CE0(&v18);
            v9 = (int)v18._Mypair._Myval2._Myhead;
            if ( v18._Mypair._Myval2._Myhead == (std__Tree_node *)v8 )
              goto LABEL_7;
          }
          std::vector<tagAccountInfo *,std::allocator<tagAccountInfo *>>::push_back(
            (std__vector *)(v9 + 0x14),
            (tagAccountInfo *)&pContext2);
          v7 = 0;
          v18._Mypair._Myval2._Mysize = 1;
          free(v10);
        }
        free(strText.m_String);
        v6 = pContext;
      }
      v19 = -1;
      free(strClassName2.m_String);
    }
    v6->lpVtbl->Release(v6);
  }
  if ( v7 )
    v7->lpVtbl->Release(v7);
  return v18._Mypair._Myval2._Mysize;
}

//----- (00C069A0) --------------------------------------------------------
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

  v1 = (tagStreamThreadInfo *)pLocator;
  InterlockedIncrement((volatile LONG *)&pLocator[1]);
  v2 = CoInitializeEx(0, 0);
  v1->hresult = v2;
  if ( v2 >= 0 )
  {
    v3 = CoCreateInstance(&CLSID_WbemLocator, 0, 1u, &IID_IWbemLocator, (LPVOID *)&pLocator);
    v1->hresult = v3;
    if ( v3 >= 0 )
    {
      while ( SetEvent(v1->hEvent1) )
      {
        v4 = *_bstr_t::_bstr_t((tagEventSetItem *)&v11, v1->pszServer);
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
              operator delete[](v7->m_str);
              v7->m_str = 0;
            }
            operator delete(v7);
          }
          v11.m_Data = 0;
        }
        if ( v1->hresult < 0 )
          break;
        v8 = CoMarshalInterThreadInterfaceInStream(&CLSID_IWbemServices, (LPUNKNOWN)pWbemServices, &v1->pStream);
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

//----- (00C06B70) --------------------------------------------------------
std__Tree_node **__thiscall sub_C06B70(std__tree *this)
{
  std__tree *v1; // esi
  std__Tree_node **v2; // edx

  v1 = this;
  v2 = (std__Tree_node **)operator new(0x20u);
  if ( !v2 )
    std::_Xbad_alloc();
  *v2 = v1->_Mypair._Myval2._Myhead;
  if ( v2 != (std__Tree_node **)-4 )
    v2[1] = v1->_Mypair._Myval2._Myhead;
  if ( v2 != (std__Tree_node **)-8 )
    v2[2] = v1->_Mypair._Myval2._Myhead;
  return v2;
}

//----- (00C06BB0) --------------------------------------------------------
_DWORD *__thiscall sub_C06BB0(_DWORD *this, int a2, size_t a3)
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
    operator delete((void *)*v3);
  result = v12;
  *(_BYTE *)v3 = 0;
  *v3 = result;
  v3[5] = v4;
  v3[4] = a3;
  if ( v4 >= 0x10 )
    v3 = result;
  *((_BYTE *)v3 + a3) = 0;
  return result;
}
// C781AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);

//----- (00C06D00) --------------------------------------------------------
void __stdcall sub_C06D00(void *a1)
{
  if ( *((_DWORD *)a1 + 5) )
  {
    operator delete(*((void **)a1 + 5));
    *((_DWORD *)a1 + 5) = 0;
    *((_DWORD *)a1 + 6) = 0;
    *((_DWORD *)a1 + 7) = 0;
  }
  operator delete(a1);
}

//----- (00C06D40) --------------------------------------------------------
void __stdcall sub_C06D40(void *a1)
{
  free(*((void **)a1 + 4));
  operator delete(a1);
}

//----- (00C06D60) --------------------------------------------------------
void __stdcall sub_C06D60(void *a1)
{
  void **v1; // esi
  void **v2; // edi

  v1 = (void **)a1;
  v2 = (void **)a1;
  if ( !*((_BYTE *)a1 + 13) )
  {
    do
    {
      sub_C06D60(v2[2]);
      v2 = (void **)*v2;
      if ( v1[5] )
      {
        operator delete(v1[5]);
        v1[5] = 0;
        v1[6] = 0;
        v1[7] = 0;
      }
      operator delete(v1);
      v1 = v2;
    }
    while ( !*((_BYTE *)v2 + 13) );
  }
}

//----- (00C06DC0) --------------------------------------------------------
void __stdcall sub_C06DC0(void *a1)
{
  void **v1; // edi
  void **v2; // esi

  v1 = (void **)a1;
  v2 = (void **)a1;
  if ( !*((_BYTE *)a1 + 13) )
  {
    do
    {
      sub_C06DC0(v2[2]);
      v2 = (void **)*v2;
      free(v1[4]);
      operator delete(v1);
      v1 = v2;
    }
    while ( !*((_BYTE *)v2 + 13) );
  }
}

//----- (00C06E00) --------------------------------------------------------
BOOL __thiscall sub_C06E00(void *this, size_t a2, int a3)
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
  v4 = *((_DWORD *)this + 5);
  if ( v4 >= a2 )
  {
    if ( (_BYTE)a3 && a2 < 0x10 )
    {
      v6 = *((_DWORD *)this + 4);
      if ( a2 < v6 )
        v6 = a2;
      if ( v4 >= 0x10 )
      {
        v7 = *(void **)this;
        v8 = *(_DWORD *)this;
        if ( v6 )
        {
          memmove_0(this, v7, v6);
          v7 = (void *)v8;
        }
        operator delete(v7);
      }
      v3[4] = v6;
      v3[5] = 15;
      *((_BYTE *)v3 + v6) = 0;
      result = a2 > 0;
    }
    else
    {
      if ( !a2 )
      {
        *((_DWORD *)this + 4) = 0;
        if ( v4 >= 0x10 )
          v3 = *(_DWORD **)this;
        *(_BYTE *)v3 = 0;
      }
      result = a2 > 0;
    }
  }
  else
  {
    sub_C06BB0(this, a2, *((_DWORD *)this + 4));
    result = a2 > 0;
  }
  return result;
}

//----- (00C06EC0) --------------------------------------------------------
void *__stdcall sub_C06EC0(size_t a1)
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

//----- (00C06F00) --------------------------------------------------------
string *__thiscall sub_C06F00(string *this, int a2, int a3, size_t a4)
{
  int v4; // ebx
  string *v5; // esi
  int v6; // ecx
  unsigned int v7; // edi
  unsigned int v8; // edi
  int v9; // eax
  bool v10; // cf
  string *result; // eax
  unsigned int v12; // eax
  string *v13; // edx

  v4 = a2;
  v5 = this;
  v6 = a3;
  v7 = *(_DWORD *)(a2 + 16);
  if ( v7 < a3 )
    std::_Xout_of_range("invalid string position");
  v8 = v7 - a3;
  if ( a4 < v8 )
    v8 = a4;
  if ( v5 != (string *)a2 )
  {
    if ( v8 > 0xFFFFFFFE )
      std::_Xlength_error("string too long");
    v12 = v5->_Myval2._Myres;
    if ( v12 >= v8 )
    {
      if ( !v8 )
      {
        v5->_Myval2._Mysize = 0;
        if ( v12 < 0x10 )
        {
          result = v5;
          v5->_Myval2._Bx._Alias[0] = 0;
        }
        else
        {
          *v5->_Myval2._Bx._Ptr = 0;
          result = v5;
        }
        return result;
      }
    }
    else
    {
      sub_C06BB0(v5, v8, v5->_Myval2._Mysize);
      v6 = a3;
      if ( !v8 )
        return v5;
    }
    if ( *(_DWORD *)(a2 + 20) >= 0x10u )
      v4 = *(_DWORD *)a2;
    if ( v5->_Myval2._Myres < 0x10 )
      v13 = v5;
    else
      v13 = (string *)v5->_Myval2._Bx._Ptr;
    if ( v8 )
      memmove_0(v13, (const void *)(v4 + v6), v8);
    v10 = v5->_Myval2._Myres < 0x10;
    v5->_Myval2._Mysize = v8;
    if ( !v10 )
    {
      v5->_Myval2._Bx._Ptr[v8] = 0;
      return v5;
    }
    v5->_Myval2._Bx._Alias[v8] = 0;
    return v5;
  }
  v9 = v8 + a3;
  if ( v5->_Myval2._Mysize < v8 + a3 )
    std::_Xout_of_range("invalid string position");
  v10 = v5->_Myval2._Myres < 0x10;
  v5->_Myval2._Mysize = v9;
  if ( v10 )
    v5->_Myval2._Bx._Alias[v9] = 0;
  else
    v5->_Myval2._Bx._Ptr[v9] = 0;
  sub_C07890(v5, 0, a3);
  return v5;
}

//----- (00C07030) --------------------------------------------------------
string *__thiscall sub_C07030(string *this, void *a2, size_t a3)
{
  string *v3; // esi
  size_t v4; // ecx
  unsigned int v5; // eax
  string *v6; // edx
  string *result; // eax
  size_t v8; // eax
  string *v9; // eax
  bool v10; // cf

  v3 = this;
  if ( a2 )
  {
    v4 = this->_Myval2._Myres;
    v5 = (unsigned int)(v4 < 0x10 ? v3 : v3->_Myval2._Bx._Ptr);
    if ( (unsigned int)a2 >= v5 )
    {
      v6 = v4 < 0x10 ? v3 : v3->_Myval2._Bx._Ptr;
      if ( (char *)v6 + v3->_Myval2._Mysize > a2 )
      {
        if ( v4 < 0x10 )
          result = sub_C06F00(v3, (int)v3, (_BYTE *)a2 - (_BYTE *)v3, a3);
        else
          result = sub_C06F00(v3, (int)v3, (int)a2 - (unsigned int)v3->_Myval2._Bx._Ptr, a3);
        return result;
      }
    }
  }
  if ( a3 > 0xFFFFFFFE )
    std::_Xlength_error("string too long");
  v8 = v3->_Myval2._Myres;
  if ( v8 < a3 )
  {
    sub_C06BB0(v3, a3, v3->_Myval2._Mysize);
    if ( !a3 )
      return v3;
LABEL_16:
    if ( v3->_Myval2._Myres < 0x10 )
      v9 = v3;
    else
      v9 = (string *)v3->_Myval2._Bx._Ptr;
    if ( a3 )
      memmove_0(v9, a2, a3);
    v10 = v3->_Myval2._Myres < 0x10;
    v3->_Myval2._Mysize = a3;
    if ( !v10 )
    {
      v3->_Myval2._Bx._Ptr[a3] = 0;
      return v3;
    }
    v3->_Myval2._Bx._Alias[a3] = 0;
    return v3;
  }
  if ( a3 )
    goto LABEL_16;
  v3->_Myval2._Mysize = 0;
  if ( v8 < 0x10 )
  {
    result = v3;
    v3->_Myval2._Bx._Alias[0] = 0;
  }
  else
  {
    *v3->_Myval2._Bx._Ptr = 0;
    result = v3;
  }
  return result;
}

//----- (00C07130) --------------------------------------------------------
int *__stdcall std::_System_error_category::default_error_condition(int *a1, int a2)
{
  bool v2; // zf
  int *result; // eax

  v2 = sub_C7465F(a2) == 0;
  result = a1;
  *a1 = a2;
  if ( v2 )
    a1[1] = (int)&off_CCAA44;
  else
    a1[1] = (int)off_CCAA3C;
  return result;
}
// CCAA3C: using guessed type int (__thiscall **off_CCAA3C[3])(void *, char);
// CCAA44: using guessed type int (__thiscall **off_CCAA44)(void *, char);

//----- (00C07190) --------------------------------------------------------
bool __thiscall std::error_category_equivalent(void *this, _DWORD *a2, int a3)
{
  return this == (void *)a2[1] && *a2 == a3;
}

//----- (00C071B0) --------------------------------------------------------
bool __thiscall std::error_category_equivalent2(void *this, int a2, _DWORD *a3)
{
  _DWORD *v3; // eax
  char v5; // [esp+0h] [ebp-8h]

  v3 = (_DWORD *)(*(int (__stdcall **)(char *, int))(*(_DWORD *)this + 12))(&v5, a2);
  return v3[1] == a3[1] && *v3 == *a3;
}

//----- (00C071F0) --------------------------------------------------------
int __thiscall sub_C071F0(CSystemProcessInfoMap *this, int a2, void *a3, int a4)
{
  void *v4; // eax
  CSystemProcessInfoMap *v5; // esi
  std__Tree_node *v6; // ecx
  std__Tree_node *v7; // eax
  std_Tree_node_for_tagKeyName *v8; // ecx
  int result; // eax
  void *v10; // ecx
  _DWORD *i; // edx
  _BYTE *j; // eax
  int v13; // [esp+4h] [ebp-4h]

  v4 = a3;
  v5 = this;
  v6 = this->_Header;
  if ( a3 != v6->_Left || (std__Tree_node *)a4 != v6 )
  {
    for ( ; a3 != (void *)a4; v4 = a3 )
    {
      v10 = v4;
      if ( !*((_BYTE *)v4 + 13) )
      {
        i = (_DWORD *)*((_DWORD *)v4 + 2);
        if ( *((_BYTE *)i + 13) )
        {
          for ( i = (_DWORD *)*((_DWORD *)v4 + 1); !*((_BYTE *)i + 13); i = (_DWORD *)i[1] )
          {
            if ( v4 != (void *)i[2] )
              break;
            v4 = i;
          }
        }
        else
        {
          for ( j = (_BYTE *)*i; !j[13]; j = *(_BYTE **)j )
            i = j;
        }
        a3 = i;
      }
      sub_C072B0(v5, (int)&v13, v10);
    }
    *(_DWORD *)a2 = v4;
    result = a2;
  }
  else
  {
    sub_C06D60(v6->_Parent);
    v5->_Header->_Parent = (std_Tree_node_for_tagKeyName *)v5->_Header;
    v5->_Header->_Left = (std_Tree_node_for_tagKeyName *)v5->_Header;
    v5->_Header->_Right = (std__Tree_node_For__bstr_t *)v5->_Header;
    v7 = v5->_Header;
    v5->_Size = 0;
    v8 = v7->_Left;
    result = a2;
    *(_DWORD *)a2 = v8;
  }
  return result;
}

//----- (00C072B0) --------------------------------------------------------
int __thiscall sub_C072B0(CSystemProcessInfoMap *this, int a2, void *a3)
{
  std_Tree_node_for_tagKeyName **v3; // ebx
  std_Tree_node_for_tagKeyName *v4; // edi
  std_Tree_node_for_tagKeyName *v5; // ecx
  std__Tree_node *v6; // esi
  std__tree *v7; // edx
  std__Tree_node *v8; // eax
  std__Tree_node *v9; // ecx
  std__Tree_node *v10; // eax
  std__Tree_node_For__bstr_t *v11; // eax
  std__Tree_node_For__bstr_t *i; // ecx
  std_Tree_node_for_tagKeyName ***v13; // eax
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

  v3 = (std_Tree_node_for_tagKeyName **)a3;
  v23 = (std__tree *)this;
  sub_C04CE0((std__tree *)&a3);
  if ( (*v3)->_IsNil )
  {
    v4 = v3[2];
LABEL_6:
    v6 = (std__Tree_node *)v3[1];
    if ( !v4->_IsNil )
      v4->_Parent = (std_Tree_node_for_tagKeyName *)v6;
    v7 = v23;
    if ( (std_Tree_node_for_tagKeyName **)v23->_Mypair._Myval2._Myhead->_Parent == v3 )
    {
      v23->_Mypair._Myval2._Myhead->_Parent = v4;
    }
    else if ( (std_Tree_node_for_tagKeyName **)v6->_Left == v3 )
    {
      v6->_Left = v4;
    }
    else
    {
      v6->_Right = (std__Tree_node_For__bstr_t *)v4;
    }
    v8 = v23->_Mypair._Myval2._Myhead;
    if ( v23->_Mypair._Myval2._Myhead->_Left == (std_Tree_node_for_tagKeyName *)v3 )
    {
      if ( v4->_IsNil )
      {
        v9 = v6;
      }
      else
      {
        v10 = (std__Tree_node *)v4->_Left;
        v9 = (std__Tree_node *)v4;
        if ( !v4->_Left->_IsNil )
        {
          do
          {
            v9 = v10;
            v10 = (std__Tree_node *)v10->_Left;
          }
          while ( !v10->_IsNil );
        }
        v8 = v23->_Mypair._Myval2._Myhead;
      }
      v8->_Left = (std_Tree_node_for_tagKeyName *)v9;
    }
    if ( (std_Tree_node_for_tagKeyName **)v23->_Mypair._Myval2._Myhead->_Right == v3 )
    {
      if ( v4->_IsNil )
      {
        v23->_Mypair._Myval2._Myhead->_Right = (std__Tree_node_For__bstr_t *)v6;
      }
      else
      {
        v11 = (std__Tree_node_For__bstr_t *)v4->_Right;
        for ( i = (std__Tree_node_For__bstr_t *)v4; !v11->_IsNil; v11 = (std__Tree_node_For__bstr_t *)v11->_Right )
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
  v5 = (std_Tree_node_for_tagKeyName *)a3;
  v22 = a3;
  v4 = (std_Tree_node_for_tagKeyName *)*((_DWORD *)a3 + 2);
  if ( a3 == v3 )
    goto LABEL_6;
  (*v3)->_Parent = (std_Tree_node_for_tagKeyName *)a3;
  v5->_Left = *v3;
  if ( v5 == v3[2] )
  {
    v6 = (std__Tree_node *)v5;
  }
  else
  {
    v6 = (std__Tree_node *)v5->_Parent;
    if ( !v4->_IsNil )
      v4->_Parent = (std_Tree_node_for_tagKeyName *)v6;
    v6->_Left = v4;
    v5->_Right = v3[2];
    v3[2]->_Parent = v5;
  }
  if ( (std_Tree_node_for_tagKeyName **)v23->_Mypair._Myval2._Myhead->_Parent == v3 )
  {
    v23->_Mypair._Myval2._Myhead->_Parent = v5;
  }
  else
  {
    v13 = (std_Tree_node_for_tagKeyName ***)v3[1];
    if ( *v13 == v3 )
      *v13 = &v5->_Left;
    else
      v13[2] = &v5->_Left;
  }
  v5->_Parent = v3[1];
  v14 = v5->_Color;
  v22[12] = *((_BYTE *)v3 + 12);
  v7 = v23;
  *((_BYTE *)v3 + 12) = v14;
LABEL_37:
  if ( *((_BYTE *)v3 + 12) == 1 )
  {
    for ( ; v4 != v7->_Mypair._Myval2._Myhead->_Parent; v6 = (std__Tree_node *)v6->_Parent )
    {
      if ( v4->_Color != 1 )
        break;
      v15 = (std__Tree_node *)v6->_Left;
      if ( v4 == v6->_Left )
      {
        v15 = (std__Tree_node *)v6->_Right;
        if ( !v15->_Color )
        {
          v15->_Color = 1;
          v6->_Color = 0;
          sub_C654B0(v7, v6);
          v15 = (std__Tree_node *)v6->_Right;
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
            sub_C72BB0(v7, v15);
            v15 = (std__Tree_node *)v6->_Right;
          }
          v15->_Color = v6->_Color;
          v6->_Color = 1;
          v16 = v6;
          v17 = v23;
          v15->_Right->_Color = 1;
          sub_C654B0(v23, v16);
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
          sub_C72BB0(v7, v6);
          v15 = (std__Tree_node *)v6->_Left;
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
            sub_C654B0(v7, v15);
            v15 = (std__Tree_node *)v6->_Left;
          }
          v15->_Color = v6->_Color;
          v6->_Color = 1;
          v18 = v6;
          v17 = v23;
          v15->_Left->_Color = 1;
          sub_C72BB0(v23, v18);
          v4->_Color = 1;
          goto LABEL_61;
        }
      }
      v15->_Color = 0;
LABEL_55:
      v4 = (std_Tree_node_for_tagKeyName *)v6;
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
    operator delete(v3[5]);
    v3[5] = 0;
    v3[6] = 0;
    v3[7] = 0;
  }
  operator delete(v3);
  v19 = v17->_Mypair._Myval2._Mysize;
  v20 = a3;
  if ( v19 )
    v17->_Mypair._Myval2._Mysize = v19 - 1;
  result = a2;
  *(_DWORD *)a2 = v20;
  return result;
}

//----- (00C07560) --------------------------------------------------------
CSystemProcessInfoMapNode **__thiscall sub_C07560(CSystemProcessInfoMap *this, CSystemProcessInfoMapNode **a2, CSystemProcessInfoMapNode *a3, CSystemProcessInfoMapNode *a4)
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
  v6 = (CSystemProcessInfoMapNode *)this->_Header;
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
      sub_C07620(v5, (CSystemProcessInfoMapNode **)&v13, v10);
    }
    *a2 = v4;
    result = a2;
  }
  else
  {
    sub_C06DC0(v6->baseclass._Parent);
    v5->_Header->_Parent = (std_Tree_node_for_tagKeyName *)v5->_Header;
    v5->_Header->_Left = (std_Tree_node_for_tagKeyName *)v5->_Header;
    v5->_Header->_Right = (std__Tree_node_For__bstr_t *)v5->_Header;
    v7 = (CSystemProcessInfoMapNode **)v5->_Header;
    v5->_Size = 0;
    v8 = *v7;
    result = a2;
    *a2 = v8;
  }
  return result;
}

//----- (00C07620) --------------------------------------------------------
CSystemProcessInfoMapNode **__thiscall sub_C07620(CSystemProcessInfoMap *this, CSystemProcessInfoMapNode **a2, CSystemProcessInfoMapNode *a3)
{
  std__tree *v3; // ebx
  CSystemProcessInfoMapNode *v4; // ecx
  CSystemProcessInfoMapNode *v5; // edi
  CSystemProcessInfoMapNode *v6; // edx
  std__Tree_node *v7; // esi
  std__Tree_node *v8; // eax
  std_Tree_node_for_tagKeyName *v9; // edx
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

  v3 = (std__tree *)this;
  v19 = a3;
  sub_C04CE0((std__tree *)&a3);
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
        v7 = (std__Tree_node *)v6;
      }
      else
      {
        v7 = (std__Tree_node *)v6->baseclass._Parent;
        if ( !v5->baseclass._isnil )
          v5->baseclass._Parent = (CSystemProcessInfoMapNode *)v7;
        v7->_Left = (std_Tree_node_for_tagKeyName *)v5;
        v6->baseclass._Right = v19->baseclass._Right;
        v19->baseclass._Right->baseclass._Parent = v6;
      }
      if ( (CSystemProcessInfoMapNode *)v3->_Mypair._Myval2._Myhead->_Parent == v19 )
      {
        v3->_Mypair._Myval2._Myhead->_Parent = (std_Tree_node_for_tagKeyName *)v6;
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
  v7 = (std__Tree_node *)v19->baseclass._Parent;
  if ( !v5->baseclass._isnil )
    v5->baseclass._Parent = (CSystemProcessInfoMapNode *)v7;
  if ( (CSystemProcessInfoMapNode *)v3->_Mypair._Myval2._Myhead->_Parent == v19 )
  {
    v3->_Mypair._Myval2._Myhead->_Parent = (std_Tree_node_for_tagKeyName *)v5;
  }
  else if ( (CSystemProcessInfoMapNode *)v7->_Left == v19 )
  {
    v7->_Left = (std_Tree_node_for_tagKeyName *)v5;
  }
  else
  {
    v7->_Right = (std__Tree_node_For__bstr_t *)v5;
  }
  v8 = v3->_Mypair._Myval2._Myhead;
  if ( v3->_Mypair._Myval2._Myhead->_Left == (std_Tree_node_for_tagKeyName *)v19 )
  {
    if ( v5->baseclass._isnil )
    {
      v9 = (std_Tree_node_for_tagKeyName *)v7;
    }
    else
    {
      v10 = v5->baseclass._Left;
      v9 = (std_Tree_node_for_tagKeyName *)v5;
      if ( !v5->baseclass._Left->baseclass._isnil )
      {
        do
        {
          v9 = (std_Tree_node_for_tagKeyName *)v10;
          v10 = v10->baseclass._Left;
        }
        while ( !v10->baseclass._isnil );
      }
      v8 = v3->_Mypair._Myval2._Myhead;
    }
    v8->_Left = v9;
  }
  if ( (CSystemProcessInfoMapNode *)v3->_Mypair._Myval2._Myhead->_Right == v19 )
  {
    if ( v5->baseclass._isnil )
    {
      v3->_Mypair._Myval2._Myhead->_Right = (std__Tree_node_For__bstr_t *)v7;
    }
    else
    {
      v11 = v5->baseclass._Right;
      for ( i = v5; !v11->baseclass._isnil; v11 = v11->baseclass._Right )
        i = v11;
      v3->_Mypair._Myval2._Myhead->_Right = (std__Tree_node_For__bstr_t *)i;
    }
  }
LABEL_37:
  if ( v4->baseclass._Color != 1 )
    goto LABEL_62;
  if ( v5 == (CSystemProcessInfoMapNode *)v3->_Mypair._Myval2._Myhead->_Parent )
    goto LABEL_61;
  while ( v5->baseclass._Color == 1 )
  {
    v15 = (std__Tree_node *)v7->_Left;
    if ( v5 == (CSystemProcessInfoMapNode *)v7->_Left )
    {
      v15 = (std__Tree_node *)v7->_Right;
      if ( !v15->_Color )
      {
        v15->_Color = 1;
        v7->_Color = 0;
        sub_C654B0(v3, v7);
        v15 = (std__Tree_node *)v7->_Right;
      }
      if ( v15->_IsNil )
        goto LABEL_55;
      if ( v15->_Left->_Color != 1 || v15->_Right->_Color != 1 )
      {
        if ( v15->_Right->_Color == 1 )
        {
          v15->_Left->_Color = 1;
          v15->_Color = 0;
          sub_C72BB0(v3, v15);
          v15 = (std__Tree_node *)v7->_Right;
        }
        v15->_Color = v7->_Color;
        v7->_Color = 1;
        v15->_Right->_Color = 1;
        sub_C654B0(v3, v7);
        break;
      }
    }
    else
    {
      if ( !v15->_Color )
      {
        v15->_Color = 1;
        v7->_Color = 0;
        sub_C72BB0(v3, v7);
        v15 = (std__Tree_node *)v7->_Left;
      }
      if ( v15->_IsNil )
        goto LABEL_55;
      if ( v15->_Right->_Color != 1 || v15->_Left->_Color != 1 )
      {
        if ( v15->_Left->_Color == 1 )
        {
          v15->_Right->_Color = 1;
          v15->_Color = 0;
          sub_C654B0(v3, v15);
          v15 = (std__Tree_node *)v7->_Left;
        }
        v15->_Color = v7->_Color;
        v7->_Color = 1;
        v15->_Left->_Color = 1;
        sub_C72BB0(v3, v7);
        break;
      }
    }
    v15->_Color = 0;
LABEL_55:
    v5 = (CSystemProcessInfoMapNode *)v7;
    v7 = (std__Tree_node *)v7->_Parent;
    if ( v5 == (CSystemProcessInfoMapNode *)v3->_Mypair._Myval2._Myhead->_Parent )
      break;
  }
  v4 = v19;
LABEL_61:
  v5->baseclass._Color = 1;
LABEL_62:
  free((void *)v4->_Keyvalue._Key);
  operator delete(v19);
  v16 = v3->_Mypair._Myval2._Mysize;
  v17 = a3;
  if ( v16 )
    v3->_Mypair._Myval2._Mysize = v16 - 1;
  result = a2;
  *a2 = v17;
  return result;
}

//----- (00C07890) --------------------------------------------------------
CHAR **__thiscall sub_C07890(string *this, unsigned int a2, unsigned int a3)
{
  string *v3; // esi
  unsigned int v4; // edi
  bool v5; // cf
  CHAR **result; // eax
  string *v7; // eax
  unsigned int v8; // edi

  v3 = this;
  v4 = this->_Myval2._Mysize;
  if ( v4 < a2 )
    std::_Xout_of_range("invalid string position");
  if ( v4 - a2 > a3 )
  {
    if ( a3 )
    {
      if ( this->_Myval2._Myres < 0x10 )
        v7 = this;
      else
        v7 = (string *)this->_Myval2._Bx._Ptr;
      v8 = v4 - a3;
      if ( v8 != a2 )
        memmove((char *)v7 + a2, (char *)v7 + a2 + a3, v8 - a2);
      v5 = v3->_Myval2._Myres < 0x10;
      v3->_Myval2._Mysize = v8;
      if ( !v5 )
      {
        v3->_Myval2._Bx._Ptr[v8] = 0;
        return (CHAR **)v3;
      }
      v3->_Myval2._Bx._Alias[v8] = 0;
    }
    result = (CHAR **)v3;
  }
  else
  {
    v5 = this->_Myval2._Myres < 0x10;
    this->_Myval2._Mysize = a2;
    if ( v5 )
    {
      result = (CHAR **)this;
      this->_Myval2._Bx._Alias[a2] = 0;
    }
    else
    {
      this->_Myval2._Bx._Ptr[a2] = 0;
      result = (CHAR **)this;
    }
  }
  return result;
}

//----- (00C07930) --------------------------------------------------------
int __stdcall std::_Generic_error_category_message(int a1, int a2)
{
  int v2; // eax
  char *v3; // edx

  v2 = sub_C7465F(a2);
  v3 = "unknown error";
  if ( v2 )
    v3 = (char *)v2;
  *(_DWORD *)(a1 + 20) = 15;
  *(_DWORD *)(a1 + 16) = 0;
  *(_BYTE *)a1 = 0;
  if ( *v3 )
    sub_C07030((string *)a1, v3, strlen(v3));
  else
    sub_C07030((string *)a1, v3, 0);
  return a1;
}

//----- (00C079A0) --------------------------------------------------------
int __stdcall std::_Iostream_error_category_message(int a1, int a2)
{
  if ( a2 == 1 )
  {
    *(_DWORD *)(a1 + 20) = 15;
    *(_DWORD *)(a1 + 16) = 0;
    *(_BYTE *)a1 = 0;
    sub_C07030((string *)a1, "iostream stream error", 0x15u);
  }
  else
  {
    std::_Generic_error_category_message(a1, a2);
  }
  return a1;
}

//----- (00C079F0) --------------------------------------------------------
int __stdcall std::_System_error_category_message(int a1, int a2)
{
  int v2; // eax
  char *v3; // edx

  v2 = sub_C74689(a2);
  v3 = "unknown error";
  if ( v2 )
    v3 = (char *)v2;
  *(_DWORD *)(a1 + 20) = 15;
  *(_DWORD *)(a1 + 16) = 0;
  *(_BYTE *)a1 = 0;
  if ( *v3 )
    sub_C07030((string *)a1, v3, strlen(v3));
  else
    sub_C07030((string *)a1, v3, 0);
  return a1;
}

//----- (00C07A60) --------------------------------------------------------
const char *std::_Generic_error_category_name()
{
  return "generic";
}

//----- (00C07A70) --------------------------------------------------------
const char *std::_Iostream_error_category_name()
{
  return "iostream";
}

//----- (00C07A80) --------------------------------------------------------
const char *std::_System_error_category_name()
{
  return "system";
}

//----- (00C07AA0) --------------------------------------------------------
int swprintf(wchar_t *pszBuffer, const wchar_t *lpszFormat, ...)
{
  va_list ArgList; // [esp+10h] [ebp+10h]

  va_start(ArgList, lpszFormat);
  return vswprintf_s(pszBuffer, MAX_PATH, lpszFormat, ArgList);
}

//----- (00C07AC0) --------------------------------------------------------
tagEventItem *__thiscall tagEventItem::tagEventItem(tagEventItem *this, const GUID *a2, __int16 a3, __int16 a4, char a5)
{
  tagEventItem *v5; // edi
  __m128i v6; // xmm0
  tagEventItem *result; // eax

  v5 = this;
  this->strEventTrace.m_Data = 0;
  this->ItemList._Mypair._Myval2._Myhead = 0;
  this->ItemList._Mypair._Myval2._Mysize = 0;
  this->ItemList._Mypair._Myval2._Myhead = (std__list_node *)std::_List_alloc<std::_List_base_types<tagEventItem *,std::allocator<tagEventItem *>>>::_Buynode0(
                                                               0,
                                                               0);
  v5->strHeader.m_Data = 0;
  v6 = _mm_loadu_si128((const __m128i *)a2);
  v5->Type = a3;
  v5->Level = a5;
  v5->Version = a4;
  result = v5;
  _mm_storeu_si128((__m128i *)&v5->guid, v6);
  v5->field_4 = 0;
  return result;
}

//----- (00C07B60) --------------------------------------------------------
_DWORD **__cdecl sub_C07B60(std__List *a1, OLECHAR *psz, int nType, int nMaxValue)
{
  _DWORD **result; // eax
  std__list_node *i; // esi
  tagEventItem *v6; // ebx
  tagEventSetItem *v7; // eax
  tagEventSetItem *v8; // edi
  std__List *v9; // edi
  std__list_node *v10; // ebx
  std__list_node *v11; // edx
  unsigned int v12; // eax
  void *v13; // [esp+10h] [ebp-10h]
  int v14; // [esp+1Ch] [ebp-4h]

  result = (_DWORD **)a1->_Mypair._Myval2._Myhead;
  for ( i = a1->_Mypair._Myval2._Myhead->_Next; i != a1->_Mypair._Myval2._Myhead; i = i->_Next )
  {
    v6 = (tagEventItem *)i->_Myval;
    v7 = (tagEventSetItem *)operator new(0x10u);
    v8 = v7;
    v13 = v7;
    v14 = 0;
    if ( v7 )
    {
      _bstr_t::_bstr_t(v7, psz);
      v8->field_8 = nType;
      v8->field_4 = -1;
      v8->nMaxValue = nMaxValue;
    }
    else
    {
      v8 = 0;
    }
    v13 = v8;
    v9 = &v6->ItemList;
    v14 = -1;
    v10 = v6->ItemList._Mypair._Myval2._Myhead;
    v11 = std::_List_buy<tagEventItem *,std::allocator<tagEventItem *>>::_Buynode<tagEventItem * const &>(
            (EventList *)v10,
            &v10->_Prev->_Next,
            &v13);
    v12 = v9->_Mypair._Myval2._Mysize;
    if ( 357913940 - v12 < 1 )
      std::_Xlength_error("list<T> too long");
    v9->_Mypair._Myval2._Mysize = v12 + 1;
    v10->_Prev = v11;
    v11->_Prev->_Next = v11;
    result = (_DWORD **)a1;
  }
  return result;
}

//----- (00C07C40) --------------------------------------------------------
int *__thiscall WbemServicesList_AppendList(tagWbemServicesList *this, std__List *a2)
{
  std__List *v2; // edi
  std__list_node *v3; // esi
  std__List *v4; // ebx
  std__list_node *v5; // edx
  unsigned int v6; // eax
  int *result; // eax
  int *v8; // esi
  EventList *v9; // [esp+8h] [ebp-4h]

  v2 = a2;
  v3 = a2->_Mypair._Myval2._Myhead->_Next;
  if ( v3 != a2->_Mypair._Myval2._Myhead )
  {
    v4 = &this->EventItemList;
    do
    {
      a2 = (std__List *)v3->_Myval;
      v9 = (EventList *)v4->_Mypair._Myval2._Myhead;
      v5 = std::_List_buy<tagEventItem *,std::allocator<tagEventItem *>>::_Buynode<tagEventItem * const &>(
             (EventList *)v4->_Mypair._Myval2._Myhead,
             &v4->_Mypair._Myval2._Myhead->_Prev->_Next,
             &a2);
      v6 = v4->_Mypair._Myval2._Mysize;
      if ( 357913940 - v6 < 1 )
        std::_Xlength_error("list<T> too long");
      v4->_Mypair._Myval2._Mysize = v6 + 1;
      v9->_Mysize = (int)v5;
      v5->_Prev->_Next = v5;
      v3 = v3->_Next;
    }
    while ( v3 != v2->_Mypair._Myval2._Myhead );
  }
  result = (int *)v2->_Mypair._Myval2._Myhead->_Next;
  v2->_Mypair._Myval2._Myhead->_Next = v2->_Mypair._Myval2._Myhead;
  v2->_Mypair._Myval2._Myhead->_Prev = v2->_Mypair._Myval2._Myhead;
  v2->_Mypair._Myval2._Mysize = 0;
  if ( result != (int *)v2->_Mypair._Myval2._Myhead )
  {
    do
    {
      v8 = (int *)*result;
      operator delete(result);
      result = v8;
    }
    while ( v8 != (int *)v2->_Mypair._Myval2._Myhead );
  }
  return result;
}

//----- (00C07CE0) --------------------------------------------------------
LONG __cdecl WbemQualifierSet_GetMax(IWbemQualifierSet *a1)
{
  LONG v1; // ebx
  WCHAR *v2; // edi
  HRESULT v3; // esi
  VARIANTARG pvarg; // [esp+8h] [ebp-10h]

  v1 = 1;
  if ( a1 )
  {
    v2 = SysAllocString(L"MAX");
    VariantInit(&pvarg);
    v3 = a1->lpVtbl->Get(a1, v2, 0, &pvarg, 0);
    SysFreeString(v2);
    if ( !v3 && pvarg.vt == VT_I4 )
      v1 = pvarg.lVal;
    VariantClear(&pvarg);
  }
  return v1;
}

//----- (00C07D50) --------------------------------------------------------
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
    if ( pEnum->lpVtbl->Next(pEnum, 5000, 1, &pClassObject1, (ULONG *)&uReturned) )
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
        if ( pEnum2->lpVtbl->Next(pEnum2, 5000, 1, &pClassObject2, (ULONG *)&uRet) )
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
              v17 = QueryEventTraceNameEx(
                      pWbemServices1,
                      (IEnumWbemClassObject *)pClassObject2,
                      iid,
                      0xFFFFu,
                      a5a[0],
                      aType);
            }
            else
            {
              VariantChangeType(&vtVersion, &vtVersion, 0, 2u);
              v16 = vtVersion.iVal;
              VariantClear(&vtVersion);
              if ( (_WORD)v21 != v16 )
                continue;
              v17 = QueryEventTraceNameEx(
                      pWbemServices1,
                      (IEnumWbemClassObject *)pClassObject2,
                      iid,
                      v21,
                      a5a[0],
                      aType);
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
  v6 = (OLECHAR *)bstrClass;
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

//----- (00C08250) --------------------------------------------------------
signed int __usercall WbemQualifierSet_GetType@<eax>(int a1@<edi>, int a2@<esi>, CIMTYPE ImType, IWbemQualifierSet *pWbemQualifierSet)
{
  signed int result; // eax
  WCHAR *bstrFormat; // edi
  HRESULT v6; // esi
  WCHAR *v7; // edi
  HRESULT v8; // esi
  OLECHAR *v9; // edi
  int v10; // esi
  signed int v11; // eax
  WCHAR *v12; // edi
  HRESULT v13; // esi
  signed int ret; // esi
  signed int v15; // [esp+4h] [ebp-A8h]
  VARIANTARG vtValue; // [esp+8h] [ebp-A4h]
  int v17; // [esp+18h] [ebp-94h]
  __int16 StringTermination[30]; // [esp+1Ch] [ebp-90h]
  __int16 extension[30]; // [esp+58h] [ebp-54h]
  __int16 format[10]; // [esp+94h] [ebp-18h]

  HIBYTE(v17) = 0;
  format[0] = 0;
  StringTermination[0] = 0;
  extension[0] = 0;
  if ( !pWbemQualifierSet )
    return 29;
  bstrFormat = SysAllocString(L"format");
  VariantInit(&vtValue);
  v6 = pWbemQualifierSet->lpVtbl->Get(pWbemQualifierSet, bstrFormat, 0, &vtValue, 0);
  SysFreeString(bstrFormat);
  if ( !v6 && vtValue.lVal )
    wcscpy_s((wchar_t *)format, 0xAu, vtValue.bstrVal);
  v7 = SysAllocString(L"StringTermination");
  VariantClear(&vtValue);
  v8 = pWbemQualifierSet->lpVtbl->Get(pWbemQualifierSet, v7, 0, &vtValue, 0);
  SysFreeString(v7);
  if ( !v8 && vtValue.lVal )
    wcscpy_s((wchar_t *)StringTermination, 0x1Eu, vtValue.bstrVal);
  v9 = SysAllocString(L"pointer");
  VariantClear(&vtValue);
  v10 = ((int (__stdcall *)(IWbemQualifierSet *, OLECHAR *, _DWORD))pWbemQualifierSet->lpVtbl->Get)(
          pWbemQualifierSet,
          v9,
          0);
  SysFreeString(v9);
  v11 = HIBYTE(v17);
  if ( !v10 )
    v11 = 1;
  v15 = v11;
  v12 = SysAllocString(L"extension");
  VariantClear(&vtValue);
  v13 = pWbemQualifierSet->lpVtbl->Get(pWbemQualifierSet, v12, 0, &vtValue, 0);
  SysFreeString(v12);
  if ( !v13 && vtValue.lVal )
    wcscpy_s((wchar_t *)extension, 0x1Eu, vtValue.bstrVal);
  VariantClear(&vtValue);
  switch ( ImType & -0x2001u )
  {
    case WBEM_FLAG_IGNORE_OBJECT_SOURCE:
      ret = 4;
      goto LABEL_52;
    case WBEM_FLAG_IGNORE_OBJECT_SOURCE|WBEM_FLAG_IGNORE_QUALIFIERS:
      goto LABEL_20;
    case WBEM_FLAG_IGNORE_DEFAULT_VALUES:
      ret = 11;
      goto LABEL_52;
    case WBEM_FLAG_IGNORE_DEFAULT_VALUES|WBEM_FLAG_IGNORE_QUALIFIERS:
      ret = 12;
      goto LABEL_52;
    case WBEM_FLAG_IGNORE_CLASS:
      if ( _wcsicmp((const wchar_t *)StringTermination, L"NullTerminated") )
      {
        if ( _wcsicmp((const wchar_t *)StringTermination, L"Counted") )
        {
          if ( _wcsicmp((const wchar_t *)StringTermination, L"ReverseCounted") )
            ret = _wcsicmp((const wchar_t *)StringTermination, L"NotCounted") != 0 ? 13 : 23;
          else
            ret = 18 - (_wcsicmp((const wchar_t *)format, L"w") != 0);
        }
        else
        {
          ret = 16 - (_wcsicmp((const wchar_t *)format, L"w") != 0);
        }
      }
      else
      {
        ret = 14 - (_wcsicmp((const wchar_t *)format, L"w") != 0);
      }
      goto LABEL_52;
    case WBEM_FLAG_IGNORE_CLASS|WBEM_FLAG_IGNORE_OBJECT_SOURCE|WBEM_FLAG_IGNORE_QUALIFIERS:
      ret = 26;
      goto LABEL_52;
    case WBEM_FLAG_IGNORE_CLASS|WBEM_FLAG_IGNORE_DEFAULT_VALUES|WBEM_FLAG_IGNORE_QUALIFIERS:
      if ( !_wcsicmp((const wchar_t *)extension, L"Port") )
      {
        ret = 21;
        goto LABEL_52;
      }
      if ( !_wcsicmp((const wchar_t *)extension, L"IPAddr") )
        goto LABEL_47;
      if ( _wcsicmp((const wchar_t *)extension, L"Sid") )
      {
        if ( _wcsicmp((const wchar_t *)extension, L"Guid") )
        {
          if ( !_wcsicmp((const wchar_t *)extension, L"SizeT") )
          {
LABEL_20:
            ret = 6;
            goto LABEL_52;
          }
          if ( _wcsicmp((const wchar_t *)extension, L"IPAddrV6") )
          {
            if ( _wcsicmp((const wchar_t *)extension, L"IPAddrV4") )
            {
              if ( _wcsicmp((const wchar_t *)extension, L"WmiTime") )
                ret = v15;
              else
                ret = 28;
            }
            else
            {
LABEL_47:
              ret = 20;
            }
          }
          else
          {
            ret = 27;
          }
        }
        else
        {
          ret = 25;
        }
      }
      else
      {
        ret = 19;
      }
LABEL_52:
      if ( (_BYTE)v15 )
        ret = 24;
      result = ret;
      break;
    case WBEM_FLAG_IGNORE_CASE:
      ret = 3;
      if ( !_wcsicmp((const wchar_t *)format, L"c") )
        ret = 0;
      goto LABEL_52;
    case WBEM_FLAG_IGNORE_CASE|WBEM_FLAG_IGNORE_QUALIFIERS:
      ret = 2;
      goto LABEL_52;
    case WBEM_FLAG_IGNORE_CASE|WBEM_FLAG_IGNORE_OBJECT_SOURCE:
      ret = 5;
      goto LABEL_52;
    case WBEM_FLAG_IGNORE_CASE|WBEM_FLAG_IGNORE_OBJECT_SOURCE|WBEM_FLAG_IGNORE_QUALIFIERS:
      ret = 7;
      if ( !_wcsicmp((const wchar_t *)format, L"x") )
        ret = 8;
      goto LABEL_52;
    case WBEM_FLAG_IGNORE_CASE|WBEM_FLAG_IGNORE_DEFAULT_VALUES:
      ret = 9;
      goto LABEL_52;
    case WBEM_FLAG_IGNORE_CASE|WBEM_FLAG_IGNORE_DEFAULT_VALUES|WBEM_FLAG_IGNORE_QUALIFIERS:
      ret = 10;
      goto LABEL_52;
    case WBEM_FLAG_IGNORE_FLAVOR|WBEM_FLAG_IGNORE_DEFAULT_VALUES|WBEM_FLAG_IGNORE_OBJECT_SOURCE|WBEM_FLAG_IGNORE_QUALIFIERS|0x40:
      ret = 1;
      goto LABEL_52;
    default:
      ret = 29;
      goto LABEL_52;
  }
  return result;
}
// C08250: could not find valid save-restore pair for edi
// C08250: could not find valid save-restore pair for esi

//----- (00C08730) --------------------------------------------------------
_bstr_t *__thiscall WbemServiceList_LogEvent(tagWbemServicesList *pWbemServicesList, GUID *pIID, int Type, int Version, int Level)
{
  tagWbemServicesList *pWbemServicesList_1; // ebx
  tagEventItem *v6; // eax
  tagEventItem *pItem; // esi
  std__list_node *v8; // edi
  std__list_node *v9; // eax
  unsigned int v10; // edx
  std__list_node *_Myhead; // ecx
  GUID *IID; // ebx
  std__list_node *v13; // eax
  tagEventItem *pValue; // esi
  GUID *v15; // edi
  GUID *v16; // esi
  unsigned int v17; // ebx
  bool v18; // cf
  tagEventItem *v19; // ebx
  signed __int16 v20; // dx
  __int16 v21; // si
  tagEventItem *v22; // edx
  _bstr_t *result; // eax
  tagEventItem *v24; // eax
  EventItem *v25; // esi
  std__list_node *v26; // edi
  std__list_node *v27; // ecx
  unsigned int v28; // eax
  tagWbemServicesList *pWbemServicesList_2; // [esp+10h] [ebp-1Ch]
  signed __int16 v30; // [esp+14h] [ebp-18h]
  int a3; // [esp+18h] [ebp-14h]
  tagEventItem *v32; // [esp+1Ch] [ebp-10h]
  int v33; // [esp+28h] [ebp-4h]

  pWbemServicesList_1 = pWbemServicesList;
  pWbemServicesList_2 = pWbemServicesList;
  v32 = 0;
  v30 = 0;
  if ( !pWbemServicesList->EventItemList._Mypair._Myval2._Mysize )
  {
    v6 = (tagEventItem *)operator new(0x2Cu);
    a3 = (int)v6;
    v33 = 0;
    pItem = v6 ? tagEventItem::tagEventItem(v6, (const GUID *)&GUID_PROCEXP_EVENT, -1, 0, 0) : 0;
    v33 = -1;
    a3 = (int)pItem;
    if ( pItem )
    {
      _bstr_t::operator=((EventItem *)pItem, L"EventTrace");
      _bstr_t::operator=((EventItem *)&pItem->strHeader, L"Header");
      v8 = pWbemServicesList_1->EventItemList._Mypair._Myval2._Myhead;
      v9 = std::_List_buy<tagEventItem *,std::allocator<tagEventItem *>>::_Buynode<tagEventItem * const &>(
             (EventList *)pWbemServicesList_1->EventItemList._Mypair._Myval2._Myhead,
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
    pValue = (tagEventItem *)v13->_Myval;
    v15 = IID;
    a3 = 0;
    v16 = &pValue->guid;
    v17 = 12;
    while ( v16->Data1 == v15->Data1 )
    {
      v16 = (GUID *)((char *)v16 + 4);
      v15 = (GUID *)((char *)v15 + 4);
      v18 = v17 < 4;
      v17 -= 4;
      if ( v18 )
      {
        v19 = (tagEventItem *)v13->_Myval;
        v20 = a3;
        v21 = v19->Type;
        if ( v21 == (_WORD)Type )
          v20 = 1;
        if ( v19->Version == (_WORD)Version )
          ++v20;
        if ( v20 == 2 )
          return (_bstr_t *)v13->_Myval;
        if ( v20 <= v30 )
        {
          v22 = v32;
        }
        else
        {
          v30 = v20;
          v22 = (tagEventItem *)v13->_Myval;
          v32 = (tagEventItem *)v13->_Myval;
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
  result = &v32->strEventTrace;
  if ( !v32 )
  {
    IID = pIID;
LABEL_30:
    result = QueryEventTraceName(pWbemServicesList_2, IID, Version, Level, Type);
    if ( !result )
    {
      v24 = (tagEventItem *)operator new(sizeof(EventItem));
      v33 = 1;
      if ( v24 )
        v25 = (EventItem *)tagEventItem::tagEventItem(v24, IID, Type, Version, Level);
      else
        v25 = 0;
      v33 = -1;
      a3 = (int)v25;
      if ( v25 )
      {
        _bstr_t::operator=(v25, L"Unknown");
        v26 = pWbemServicesList_2->EventItemList._Mypair._Myval2._Myhead;
        v27 = std::_List_buy<tagEventItem *,std::allocator<tagEventItem *>>::_Buynode<tagEventItem * const &>(
                (EventList *)pWbemServicesList_2->EventItemList._Mypair._Myval2._Myhead,
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

//----- (00C08970) --------------------------------------------------------
_bstr_t *__thiscall QueryEventTraceNameEx(tagWbemServicesList *this, IEnumWbemClassObject *pClassObjectIn, const GUID *pGuid, unsigned __int16 Version, char Level, __int16 Type)
{
  tagEventItem *v6; // ebx
  EventList *v7; // edi
  tagEventItem *v8; // eax
  tagEventItem *pItem; // eax
  _DWORD *v10; // ST100_4
  std__list_node *v11; // eax
  OLECHAR *bstrSuperClass; // edi
  HRESULT hResult; // esi
  HRESULT (__stdcall *SafeArrayDestroy)(SAFEARRAY *); // esi
  HRESULT (__stdcall *SafeArrayGetElement)(SAFEARRAY *, LONG *, void *); // ebx
  SAFEARRAY *pArray; // ebx
  SAFEARRAY *parray; // esi
  int lBound_2; // ecx
  int wTypeNew; // edi
  tagEventItem *v20; // eax
  tagEventItem *pItemNew; // esi
  tagEventItem *v22; // eax
  LONG lBound_3; // ecx
  SAFEARRAY *v24; // ST104_4
  __int16 v25; // di
  tagEventItem *v26; // eax
  tagEventItem *v27; // esi
  tagEventItem *v28; // ebx
  tagEventItem *v29; // eax
  int iVal; // edi
  int v31; // eax
  _DWORD *v32; // edi
  _DWORD *v33; // eax
  _DWORD *v34; // esi
  VARIANTARG vtRet; // [esp+10h] [ebp-4E0h]
  LONG lBound2; // [esp+20h] [ebp-4D0h]
  LONG lBound; // [esp+24h] [ebp-4CCh]
  PUCHAR pArrayData; // [esp+28h] [ebp-4C8h]
  LONG lBound3; // [esp+2Ch] [ebp-4C4h]
  PUCHAR pArrayData2; // [esp+30h] [ebp-4C0h]
  VARIANTARG vtTypeNameValue; // [esp+34h] [ebp-4BCh]
  VARIANTARG vtEventTypeValue; // [esp+44h] [ebp-4ACh]
  VARIANTARG vtValue; // [esp+54h] [ebp-49Ch]
  IEnumWbemClassObject *pEnum; // [esp+64h] [ebp-48Ch]
  int VersionIn; // [esp+68h] [ebp-488h]
  BSTR bstrDisplyName; // [esp+6Ch] [ebp-484h]
  BSTR bstrClass; // [esp+70h] [ebp-480h]
  BSTR bstrEventType; // [esp+74h] [ebp-47Ch]
  __int16 LevelIn; // [esp+78h] [ebp-478h]
  int cbRet; // [esp+7Ch] [ebp-474h]
  LONG uBound2; // [esp+80h] [ebp-470h]
  LONG uBound3; // [esp+84h] [ebp-46Ch]
  int ImType; // [esp+88h] [ebp-468h]
  BSTR bstrDataId; // [esp+8Ch] [ebp-464h]
  BSTR bstrTypeName; // [esp+90h] [ebp-460h]
  GUID *GuidIn; // [esp+94h] [ebp-45Ch]
  tagWbemServicesList *ppWbemServices; // [esp+98h] [ebp-458h]
  void *bstrVal; // [esp+9Ch] [ebp-454h]
  LONG uBound; // [esp+A0h] [ebp-450h]
  IWbemClassObject *pClassObject; // [esp+A4h] [ebp-44Ch]
  WCHAR *pszElement; // [esp+A8h] [ebp-448h]
  void *theList; // [esp+ACh] [ebp-444h]
  int v64; // [esp+B0h] [ebp-440h]
  tagEventItem *pItemTmp; // [esp+B4h] [ebp-43Ch]
  tagEventItem *pItem_1; // [esp+B8h] [ebp-438h]
  void *v67; // [esp+BCh] [ebp-434h]
  LONG lIndex; // [esp+C0h] [ebp-430h]
  IWbemClassObject *pNewObject; // [esp+C4h] [ebp-42Ch]
  SAFEARRAY *arrNames; // [esp+C8h] [ebp-428h]
  IWbemQualifierSet *pQualifierSet; // [esp+CCh] [ebp-424h]
  __int16 psz[260]; // [esp+D0h] [ebp-420h]
  WCHAR szText[260]; // [esp+2D8h] [ebp-218h]
  int v74; // [esp+4ECh] [ebp-4h]

  ppWbemServices = this;
  pClassObject = (IWbemClassObject *)pClassObjectIn;
  v6 = 0;
  GuidIn = (GUID *)pGuid;
  VersionIn = Version;
  LOBYTE(LevelIn) = Level;
  pEnum = 0;
  pNewObject = 0;
  pQualifierSet = 0;
  pszElement = 0;
  v64 = 0;
  v7 = (EventList *)std::_List_alloc<std::_List_base_types<tagEventItem *,std::allocator<tagEventItem *>>>::_Buynode0(
                      0,
                      0);
  theList = v7;
  v74 = 0;
  arrNames = 0;
  VariantInit(&vtValue);
  VariantInit(&vtEventTypeValue);
  VariantInit(&vtTypeNameValue);
  VariantInit(&vtRet);
  bstrClass = SysAllocString(L"__CLASS");
  bstrDataId = SysAllocString(L"WmiDataId");
  bstrEventType = SysAllocString(L"EventType");
  bstrTypeName = SysAllocString(L"EventTypeName");
  bstrDisplyName = SysAllocString(L"DisplayName");
  if ( !pClassObject->lpVtbl->Get(pClassObject, bstrClass, 0, &vtValue, 0, 0) )
  {
    wcscpy_s(szText, 0x104u, vtValue.bstrVal);
    if ( pQualifierSet )
    {
      pQualifierSet->lpVtbl->Release(pQualifierSet);
      pQualifierSet = 0;
    }
    pClassObject->lpVtbl->GetQualifierSet(pClassObject, &pQualifierSet);
    if ( !pQualifierSet->lpVtbl->Get(pQualifierSet, bstrDisplyName, 0, &vtRet, 0) && vtRet.lVal )
      wcscpy_s(szText, 0x104u, vtRet.bstrVal);
    v8 = (tagEventItem *)operator new(0x2Cu);
    bstrVal = v8;
    LOBYTE(v74) = 1;
    pItem = v8 ? tagEventItem::tagEventItem(v8, GuidIn, -1, -1, -1) : 0;
    pItem_1 = pItem;
    LOBYTE(v74) = 0;
    v67 = pItem;
    if ( pItem )
    {
      _bstr_t::operator=((EventItem *)pItem, szText);
      v6 = pItem_1;
      v10 = (_DWORD *)v7->_Mysize;
      pItemTmp = pItem_1;
      v11 = std::_List_buy<tagEventItem *,std::allocator<tagEventItem *>>::_Buynode<tagEventItem * const &>(
              v7,
              v10,
              &v67);
      v64 = 1;
      v7->_Mysize = (int)v11;
      v11->_Prev->_Next = v11;
      bstrSuperClass = SysAllocString(vtValue.bstrVal);
      hResult = ppWbemServices->pService->lpVtbl->CreateClassEnum(
                  ppWbemServices->pService,
                  bstrSuperClass,
                  0x20001,
                  0,
                  &pEnum);
      SysFreeString(bstrSuperClass);
      if ( !hResult )
      {
        SafeArrayDestroy = ::SafeArrayDestroy;
        SafeArrayGetElement = ::SafeArrayGetElement;
        cbRet = 1;
        while ( 1 )
        {
          pNewObject = 0;
          if ( pEnum->lpVtbl->Next(pEnum, 5000, 1, &pNewObject, (ULONG *)&cbRet) )
          {
            pNewObject = pClassObject;
            pClassObject->lpVtbl->AddRef(pClassObject);
          }
          if ( pQualifierSet )
          {
            pQualifierSet->lpVtbl->Release(pQualifierSet);
            pQualifierSet = 0;
          }
          pNewObject->lpVtbl->GetQualifierSet(pNewObject, &pQualifierSet);
          VariantClear(&vtEventTypeValue);
          if ( !pQualifierSet->lpVtbl->Get(pQualifierSet, bstrEventType, 0, &vtEventTypeValue, 0) )
          {
            pArray = 0;
            if ( vtEventTypeValue.vt & VT_ARRAY )
            {
              parray = vtEventTypeValue.parray;
              bstrVal = vtEventTypeValue.bstrVal;
              VariantClear(&vtTypeNameValue);
              if ( !pQualifierSet->lpVtbl->Get(pQualifierSet, bstrTypeName, 0, &vtTypeNameValue, 0)
                && vtTypeNameValue.vt & 0x2000 )
              {
                pArray = vtTypeNameValue.parray;
              }
              if ( !parray
                || SafeArrayGetLBound(parray, 1u, &lBound)
                || SafeArrayGetUBound(parray, 1u, &uBound)
                || uBound < 0 )
              {
LABEL_80:
                v6 = pItemTmp;
                break;
              }
              SafeArrayAccessData(parray, (void **)&pArrayData);
              if ( pArray )
              {
                if ( SafeArrayGetLBound(pArray, 1u, &lBound2) || SafeArrayGetUBound(pArray, 1u, &uBound2) || uBound2 < 0 )
                  goto LABEL_80;
                SafeArrayAccessData(pArray, (void **)&pArrayData2);
              }
              lBound_2 = lBound;
              lIndex = lBound;
              if ( lBound <= uBound )
              {
                while ( 1 )
                {
                  wTypeNew = *(_DWORD *)&pArrayData[4 * lBound_2];
                  v20 = (tagEventItem *)operator new(0x2Cu);
                  v67 = v20;
                  LOBYTE(v74) = 2;
                  if ( v20 )
                    pItemNew = tagEventItem::tagEventItem(v20, GuidIn, wTypeNew, VersionIn, LevelIn);
                  else
                    pItemNew = 0;
                  LOBYTE(v74) = 0;
                  v67 = pItemNew;
                  if ( pItemNew )
                  {
                    std::list<tagEventItem *,std::allocator<tagEventItem *>>::push_back(
                      (std__List *)&theList,
                      (int)&v67);
                    if ( _bstr_t::length(pItem_1) )
                      _bstr_t::operator=(&pItemNew->strEventTrace, &pItem_1->strEventTrace);
                    v22 = pItemTmp;
                    if ( Type == (_WORD)wTypeNew )
                      v22 = pItemNew;
                    pItemTmp = v22;
                    if ( pArray )
                    {
                      lBound_3 = lIndex;
                      if ( lIndex < lBound2 || lIndex > uBound2 )
                        goto LABEL_45;
                      _bstr_t::operator=((EventItem *)&pItemNew->strHeader, *(OLECHAR **)&pArrayData2[4 * lIndex]);
                    }
                  }
                  lBound_3 = lIndex;
LABEL_45:
                  lBound_2 = lBound_3 + 1;
                  lIndex = lBound_2;
                  if ( lBound_2 > uBound )
                  {
                    parray = (SAFEARRAY *)bstrVal;
                    break;
                  }
                }
              }
              SafeArrayUnaccessData(parray);
              v24 = parray;
              SafeArrayDestroy = ::SafeArrayDestroy;
              ::SafeArrayDestroy(v24);
              VariantInit(&vtEventTypeValue);
              if ( pArray )
              {
                SafeArrayUnaccessData(pArray);
                ::SafeArrayDestroy(pArray);
                VariantInit(&vtTypeNameValue);
              }
            }
            else
            {
              VariantChangeType(&vtEventTypeValue, &vtEventTypeValue, 0, VT_I2);
              v25 = vtEventTypeValue.iVal;
              VariantClear(&vtTypeNameValue);
              if ( pQualifierSet->lpVtbl->Get(pQualifierSet, bstrTypeName, 0, &vtTypeNameValue, 0) )
                psz[0] = 0;
              else
                wcscpy_s((wchar_t *)psz, 0x104u, vtTypeNameValue.bstrVal);
              v26 = (tagEventItem *)operator new(0x2Cu);
              bstrVal = v26;
              LOBYTE(v74) = 3;
              if ( v26 )
                v27 = tagEventItem::tagEventItem(v26, GuidIn, v25, VersionIn, LevelIn);
              else
                v27 = 0;
              LOBYTE(v74) = 0;
              v67 = v27;
              if ( v27 )
              {
                std::list<tagEventItem *,std::allocator<tagEventItem *>>::push_back((std__List *)&theList, (int)&v67);
                v28 = pItem_1;
                if ( _bstr_t::length(pItem_1) )
                  _bstr_t::operator=(&v27->strEventTrace, &v28->strEventTrace);
                v29 = pItemTmp;
                if ( Type == v25 )
                  v29 = v27;
                pItemTmp = v29;
                _bstr_t::operator=((EventItem *)&v27->strHeader, (OLECHAR *)psz);
              }
              SafeArrayDestroy = ::SafeArrayDestroy;
            }
            SafeArrayGetElement = ::SafeArrayGetElement;
          }
          VariantClear(&vtValue);
          arrNames = 0;
          vtValue.vt = VT_I4;
          iVal = 1;
          for ( vtValue.lVal = 1;
                !pNewObject->lpVtbl->GetNames(pNewObject, bstrDataId, 3, &vtValue, &arrNames);
                vtValue.lVal = ++iVal )
          {
            if ( SafeArrayGetLBound(arrNames, 1u, &lBound3) || SafeArrayGetUBound(arrNames, 1u, &uBound3) || uBound3 < 0 )
              break;
            lIndex = lBound3;
            if ( lBound3 <= uBound3 )
            {
              do
              {
                if ( SafeArrayGetElement(arrNames, &lIndex, &pszElement)
                  || pNewObject->lpVtbl->Get(pNewObject, pszElement, 0, 0, &ImType, 0) )
                {
                  break;
                }
                if ( pQualifierSet )
                {
                  pQualifierSet->lpVtbl->Release(pQualifierSet);
                  pQualifierSet = 0;
                }
                if ( pNewObject->lpVtbl->GetPropertyQualifierSet(pNewObject, pszElement, &pQualifierSet) )
                  break;
                SafeArrayDestroy = (HRESULT (__stdcall *)(SAFEARRAY *))WbemQualifierSet_GetType(
                                                                         iVal,
                                                                         (int)SafeArrayDestroy,
                                                                         ImType,
                                                                         pQualifierSet);
                v31 = ImType & WBEM_MAX_PATH ? WbemQualifierSet_GetMax(pQualifierSet) : 1;
                sub_C07B60((std__List *)&theList, pszElement, (int)SafeArrayDestroy, v31);
                ++lIndex;
              }
              while ( lIndex <= uBound3 );
              SafeArrayDestroy = ::SafeArrayDestroy;
            }
            SafeArrayDestroy(arrNames);
            arrNames = 0;
          }
          WbemServicesList_AppendList(ppWbemServices, (std__List *)&theList);
          if ( cbRet != 1 )
            goto LABEL_80;
        }
      }
    }
  }
  VariantClear(&vtValue);
  VariantClear(&vtEventTypeValue);
  VariantClear(&vtRet);
  SysFreeString(bstrClass);
  SysFreeString(bstrDataId);
  SysFreeString(bstrEventType);
  SysFreeString(bstrTypeName);
  SysFreeString(bstrDisplyName);
  WbemServicesList_AppendList(ppWbemServices, (std__List *)&theList);
  v32 = theList;
  v33 = *(_DWORD **)theList;
  *v32 = v32;
  v32[1] = v32;
  if ( v33 != v32 )
  {
    do
    {
      v34 = (_DWORD *)*v33;
      operator delete(v33);
      v33 = v34;
    }
    while ( v34 != v32 );
  }
  operator delete(v32);
  return &v6->strEventTrace;
}

//----- (00C092A0) --------------------------------------------------------
int __cdecl sub_C092A0(wchar_t *Dst, size_t SizeInWords, int a3)
{
  return swprintf_s(
           Dst,
           SizeInWords,
           L"{%08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x}",
           *(_DWORD *)a3,
           *(unsigned __int16 *)(a3 + 4),
           *(unsigned __int16 *)(a3 + 6),
           *(unsigned __int8 *)(a3 + 8),
           *(unsigned __int8 *)(a3 + 9),
           *(unsigned __int8 *)(a3 + 10),
           *(unsigned __int8 *)(a3 + 11),
           *(unsigned __int8 *)(a3 + 12),
           *(unsigned __int8 *)(a3 + 13),
           *(unsigned __int8 *)(a3 + 14),
           *(unsigned __int8 *)(a3 + 15));
}

//----- (00C092F0) --------------------------------------------------------
HRESULT __cdecl SetProxyAccessRight(tagWbemServicesList *pWbemServicesList)
{
  OLECHAR *strNetworkResource; // edi
  HRESULT v2; // esi
  IWbemLocator *pLocator; // [esp+8h] [ebp-4h]

  pLocator = 0;
  strNetworkResource = SysAllocString(L"root\\wmi");
  CoInitialize(0);
  v2 = CoCreateInstance(&CLSID_WbemLocator, 0, CLSCTX_INPROC_SERVER, &IID_IWbemLocator, (LPVOID *)&pLocator);
  if ( !v2 )
  {
    v2 = pLocator->lpVtbl->ConnectServer(
           pLocator,
           strNetworkResource,
           0,
           0,
           0,
           0,
           0,
           0,
           (IWbemServices **)pWbemServicesList);
    if ( !v2 )
      // 是为接口代理设置访问权限
      v2 = CoSetProxyBlanket(
             (IUnknown *)pWbemServicesList->pService,
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

//----- (00C09380) --------------------------------------------------------
std__list_node *__thiscall std::list<tagEventItem *,std::allocator<tagEventItem *>>::push_back(std__List *this, int a2)
{
  std__List *v2; // esi
  std__list_node *v3; // edi
  std__list_node *v4; // edx
  unsigned int v5; // eax
  std__list_node *result; // eax

  v2 = this;
  v3 = this->_Mypair._Myval2._Myhead;
  v4 = std::_List_buy<tagEventItem *,std::allocator<tagEventItem *>>::_Buynode<tagEventItem * const &>(
         (EventList *)this->_Mypair._Myval2._Myhead,
         &this->_Mypair._Myval2._Myhead->_Prev->_Next,
         (_DWORD *)a2);
  v5 = v2->_Mypair._Myval2._Mysize;
  if ( 357913940 - v5 < 1 )
    std::_Xlength_error("list<T> too long");
  v2->_Mypair._Myval2._Mysize = v5 + 1;
  v3->_Prev = v4;
  result = v4->_Prev;
  result->_Next = v4;
  return result;
}

//----- (00C093D0) --------------------------------------------------------
_WORD *__thiscall sub_C093D0(_WORD *this, OLECHAR *psz)
{
  _WORD *v2; // esi
  BSTR v3; // eax

  v2 = this;
  *this = 8;
  v3 = SysAllocString(psz);
  *((_DWORD *)v2 + 2) = v3;
  if ( !v3 && psz )
    _com_issue_error(-2147024882);
  return v2;
}

//----- (00C09410) --------------------------------------------------------
int __usercall QueryShellDispatch@<eax>(int a1@<esi>, IShellFolderViewDual *pShellFolderViewDual, GUID *iid, IDispatch *ppDispApplication)
{
  IShellView *v4; // eax
  IDispatch *ppv; // edi
  int result; // eax
  int v7; // esi
  IDispatch *pDisp; // [esp+4h] [ebp-4h]

  v4 = (IShellView *)pShellFolderViewDual;
  ppv = ppDispApplication;
  ppDispApplication->lpVtbl = 0;
  result = v4->lpVtbl->GetItemObject(v4, 0, &CLSID_IDispatch, (LPVOID *)&pDisp);
  if ( result >= 0 )
  {
    v7 = ((int (__stdcall *)(IDispatch *, GUID *, IShellFolderViewDual **, int))pDisp->lpVtbl->QueryInterface)(
           pDisp,
           &CLSID_IShellFolderViewDual,
           &pShellFolderViewDual,
           a1);
    if ( v7 >= 0 )
    {
      v7 = pShellFolderViewDual->lpVtbl->get_Application(pShellFolderViewDual, (IDispatch *)&ppDispApplication);
      if ( v7 >= 0 )
      {
        v7 = ppDispApplication->lpVtbl->QueryInterface(ppDispApplication, iid, (void **)ppv);
        ppDispApplication->lpVtbl->Release(ppDispApplication);
      }
      pShellFolderViewDual->lpVtbl->Release(pShellFolderViewDual);
    }
    ((void (__cdecl *)(IDispatch *))pDisp->lpVtbl->Release)(pDisp);
    result = v7;
  }
  return result;
}
// CA38D0: using guessed type GUID CLSID_IDispatch;
// CA38F0: using guessed type GUID CLSID_IShellFolderViewDual;

//----- (00C094A0) --------------------------------------------------------
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
  result = CoCreateInstance(&CLSID_ShellWindows, 0, CLSCTX_LOCAL_SERVER, &CLSID_IShellWindows, (LPVOID *)&pShellWindow);
  if ( result >= 0 )
  {
    v5 = pShellWindow;
    _mm_storeu_si128((__m128i *)&vtLocation, (__m128i)0i64);
    if ( ((int (__stdcall *)(IShellWindows *, __int128 *, __int128 *, ShellWindowTypeConstants, char *, ShellWindowFindWindowOptions, IUnknown **, int))v5->lpVtbl->FindWindowA)(
           v5,
           &vtLocation,
           &vtLocation,
           SWC_DESKTOP,
           &hWnd,
           SWFO_NEEDDISPATCH,
           &pDisp,
           v2) )
    {
      ((void (__cdecl *)(IShellWindows *))pShellWindow->lpVtbl->Release)(pShellWindow);
      result = E_FAIL;
    }
    else
    {
      hresult = IUnknown_QueryService(pDisp, &CLSID_SID_STopLevelBrowser, &CLSID_IShellBrowser, (void **)&pShellBrowser);
      if ( hresult >= 0 )
      {
        hresult = pShellBrowser->lpVtbl->QueryActiveShellView(pShellBrowser, (IShellView **)&ppv);
        if ( hresult >= 0 )
        {
          hresult = ((int (__stdcall *)(IShellView **, _GUID *, IShellView **))(*ppv)->lpVtbl)(ppv, iid, v3);
          ((void (__stdcall *)(IShellView **))(*ppv)[2].lpVtbl)(ppv);
        }
        pShellBrowser->lpVtbl->Release(pShellBrowser);
      }
      ((void (__cdecl *)(IUnknown *))pDisp->lpVtbl->Release)(pDisp);
      pShellWindow->lpVtbl->Release(pShellWindow);
      result = hresult;
    }
  }
  return result;
}

//----- (00C09580) --------------------------------------------------------
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
    hresult = QueryShellDispatch(
                (int)lpszParameters,
                (IShellFolderViewDual *)pShellView,
                &CLSID_IShellDispatch2,
                (IDispatch *)&pShellDisp);
    if ( hresult >= 0 )
    {
      bstrFile1 = SysAllocString(lpszFile);
      hresult = E_OUTOFMEMORY;
      if ( bstrFile1 )
        hresult = 0;
      if ( hresult >= 0 )
      {
        vtArgs1.vt = VT_BSTR;
        vtArgs1.lVal = (LONG)SysAllocString(lpszParameters);
        if ( !vtArgs1.lVal && lpszParameters )
          _com_issue_error(E_OUTOFMEMORY);
        v20 = 0;
        vtDir1.vt = VT_BSTR;
        vtDir1.lVal = (LONG)SysAllocString(lpszDir);
        if ( !vtDir1.lVal && lpszDir )
          _com_issue_error(E_OUTOFMEMORY);
        v6 = pShellDisp;
        bstrFile = bstrFile1;
        LOBYTE(v20) = 1;
        v8 = pShellDisp->lpVtbl;
        _mm_storeu_si128((__m128i *)&vbShow, (__m128i)0i64);
        _mm_storeu_si128((__m128i *)&vtOperation, (__m128i)0i64);
        _mm_storeu_si128((__m128i *)&vtDir, _mm_loadu_si128((const __m128i *)&vtDir1));
        _mm_storeu_si128((__m128i *)&vtArgs, _mm_loadu_si128((const __m128i *)&vtArgs1));
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
  if ( !v5 && (unsigned int)ShellExecuteW(0, 0, lpszFile, v3, 0, 1) > ERROR_SHARING_VIOLATION )
    hresult = 0;
  return hresult;
}

//----- (00C09700) --------------------------------------------------------
CRYPT_PROVIDER_SGNR *__cdecl sub_C09700(HANDLE StateHandle, char bFlags, WINTRUST_DATA_EX **ActionData, PDWORD pdwValues, _CRYPT_PROVIDER_CERT **ppCertProviderContext, PCCERT_CONTEXT *ppCertContext)
{
  CRYPT_PROVIDER_SGNR *pProviderSgnr; // eax
  _CRYPT_PROVIDER_CERT *pProviderContext; // ebx
  unsigned int pProviderSgnr3; // edi
  WCHAR *pstr; // esi
  wchar_t *pstr1; // edi
  const wchar_t *pstr2; // esi
  wchar_t *v12; // eax
  wchar_t *pstr3; // eax
  DWORD dwValue; // [esp+8h] [ebp-818h]
  unsigned int nIndex; // [esp+14h] [ebp-80Ch]
  CRYPT_PROVIDER_SGNR *pProviderSgnr2; // [esp+18h] [ebp-808h]
  WCHAR szName[1024]; // [esp+1Ch] [ebp-804h]

  pProviderSgnr = (CRYPT_PROVIDER_SGNR *)StateHandle;
  dwValue = *pdwValues;
  *pdwValues = 0;
  if ( !StateHandle )
    return pProviderSgnr;
  pProviderSgnr = (CRYPT_PROVIDER_SGNR *)WTHelperProvDataFromStateData(StateHandle);
  if ( !pProviderSgnr )
    return pProviderSgnr;
  pProviderSgnr = WTHelperGetProvSignerFromChain((CRYPT_PROVIDER_DATA *)pProviderSgnr, 0, 0, 0);
  if ( !pProviderSgnr )
    return pProviderSgnr;
  if ( ActionData )
  {
    *ActionData = (WINTRUST_DATA_EX *)pProviderSgnr->sftVerifyAsOf.dwLowDateTime;
    ActionData[1] = (WINTRUST_DATA_EX *)pProviderSgnr->sftVerifyAsOf.dwHighDateTime;
  }
  if ( !bFlags )
    goto LABEL_9;
  if ( pProviderSgnr->csCounterSigners )
  {
    pProviderSgnr = pProviderSgnr->pasCounterSigners;
LABEL_9:
    pProviderContext = pProviderSgnr->pasCertChain;
    pProviderSgnr = (CRYPT_PROVIDER_SGNR *)pProviderSgnr->csCertChain;
    goto __quit3;
  }
  pProviderContext = (_CRYPT_PROVIDER_CERT *)ppCertProviderContext;
  pProviderSgnr = 0;
__quit3:
  pProviderSgnr3 = 0;
  pProviderSgnr2 = pProviderSgnr;
  nIndex = 0;
  if ( pProviderSgnr )
  {
    while ( 1 )
    {
      if ( pProviderSgnr3 >= dwValue )
        return pProviderSgnr;
      pProviderSgnr = (CRYPT_PROVIDER_SGNR *)CertGetNameStringW(
                                               pProviderContext->pCert,
                                               CERT_NAME_FRIENDLY_DISPLAY_TYPE,
                                               0,
                                               0,
                                               szName,
                                               0x400u);
      if ( pProviderSgnr )
        break;
LABEL_29:
      nIndex = ++pProviderSgnr3;
      if ( pProviderSgnr3 >= (unsigned int)pProviderSgnr2 )
        return pProviderSgnr;
    }
    if ( wcsstr(szName, L"CN=") )
    {
      pstr = wcsstr(szName, L"CN=") + 3;
    }
    else if ( wcsstr(szName, L"OU=") )
    {
      pstr1 = wcsstr(szName, L"OU=");
      for ( pstr2 = pstr1 + 1; wcsstr(pstr1 + 1, L"OU="); pstr2 = pstr1 + 1 )
        pstr1 = wcsstr(pstr2, L"OU=");
      v12 = wcsstr(pstr1, L"OU=");
      pProviderSgnr3 = nIndex;
      pstr = v12 + 3;
    }
    else
    {
      pstr = szName;
    }
    if ( *pstr == '"' )
    {
      ++pstr;
      pstr3 = wcschr(pstr, '"');
    }
    else
    {
      if ( !wcschr(pstr, ',') )
      {
LABEL_26:
        pProviderSgnr = (CRYPT_PROVIDER_SGNR *)_wcsdup(pstr);
        ppCertProviderContext[*pdwValues] = (_CRYPT_PROVIDER_CERT *)pProviderSgnr;
        if ( ppCertContext )
        {
          pProviderSgnr = (CRYPT_PROVIDER_SGNR *)CertDuplicateCertificateContext(pProviderContext->pCert);
          ppCertContext[*pdwValues] = (PCCERT_CONTEXT)pProviderSgnr;
        }
        pProviderContext = (_CRYPT_PROVIDER_CERT *)((char *)pProviderContext + pProviderContext->cbStruct);
        ++*pdwValues;
        goto LABEL_29;
      }
      pstr3 = wcschr(pstr, ',');
    }
    *pstr3 = 0;
    goto LABEL_26;
  }
  return pProviderSgnr;
}

//----- (00C09930) --------------------------------------------------------
MACRO_HRESULT __cdecl PE_CryptedVerify(HCATADMIN hCatAdmin, WCHAR *pcwszMemberFilePath, char fdwRevocationChecks, BYTE *pbHash, DWORD cbHash, WINTRUST_DATA_EX *pActionData, WCHAR **ppcwszCatalogFilePathIn, int dwIndex)
{
  HCATINFO hCatInfo; // edi
  LONG hresult; // esi
  CATALOG_INFO psCatInfo; // [esp+18h] [ebp-210h]

  hCatInfo = CryptCATAdminEnumCatalogFromHash(hCatAdmin, pbHash, cbHash, 0, NULL);
  if ( !hCatInfo )
    return TRUST_E_NOSIGNATURE;
  while ( 1 )
  {
    memset(&psCatInfo, 0, sizeof(CATALOG_INFO));
    psCatInfo.cbStruct = sizeof(CATALOG_INFO);
    if ( CryptCATCatalogInfoFromContext(hCatInfo, &psCatInfo, 0) )
      break;
    CryptCATAdminReleaseCatalogContext(hCatAdmin, hCatInfo, 0);
    hCatInfo = CryptCATAdminEnumCatalogFromHash(hCatAdmin, pbHash, cbHash, 0, NULL);
    if ( !hCatInfo )
      return TRUST_E_NOSIGNATURE;
  }
  hresult = PE_VerifyFile(
              pcwszMemberFilePath,
              fdwRevocationChecks,
              (WCHAR *)pbHash,
              cbHash,
              pActionData,
              (WCHAR *)psCatInfo.wszCatalogFile,
              ppcwszCatalogFilePathIn,
              dwIndex);
  CryptCATAdminReleaseCatalogContext(hCatAdmin, hCatInfo, 0);
  return hresult;
}

//----- (00C09A40) --------------------------------------------------------
LONG __cdecl PE_VerifyFile(WCHAR *pcwszMemberFilePath, char fdwRevocationChecks, WCHAR *lpszText, DWORD TextLen, WINTRUST_DATA_EX *pActionData, WCHAR *pcwszCatalogFilePathIn, WCHAR **ppcwszCatalogFilePath, int dwIndex)
{
  WCHAR *pszText1; // eax
  WINTRUST_DATA_EX *ActionData; // edi
  DWORD dwIdx; // esi
  wchar_t *pszBuffer; // edi
  wchar_t *pcwszCatalogFilePath; // eax
  LONG ret; // esi
  WCHAR **v14; // edi
  WINTRUST_SIGNATURE_SETTINGS Settings; // [esp+Ch] [ebp-A4h]
  WINTRUST_CATALOG_INFO_EX FileInfo; // [esp+24h] [ebp-8Ch]
  WINTRUST_DATA_EX *pActionData_; // [esp+48h] [ebp-68h]
  WCHAR **ppcwszCatalogFilePathIn; // [esp+4Ch] [ebp-64h]
  WCHAR *pszText; // [esp+50h] [ebp-60h]
  wchar_t *cwszCatalogFilePath; // [esp+54h] [ebp-5Ch]
  wchar_t szBuffer[46]; // [esp+58h] [ebp-58h]

  pszText1 = lpszText;
  ActionData = pActionData;
  dwIdx = 0;
  cwszCatalogFilePath = pcwszCatalogFilePathIn;
  pszText = lpszText;
  pActionData_ = pActionData;
  ppcwszCatalogFilePathIn = ppcwszCatalogFilePath;
  if ( TextLen )
  {
    pszBuffer = szBuffer;
    do
    {
      swprintf_s(pszBuffer, 3u, L"%02X", *((unsigned __int8 *)pszText1 + dwIdx));
      pszText1 = pszText;
      ++dwIdx;
      pszBuffer += 2;
    }
    while ( dwIdx < TextLen );
    ActionData = pActionData_;
  }
  pcwszCatalogFilePath = cwszCatalogFilePath;
  _mm_storeu_si128((__m128i *)&FileInfo, (__m128i)0i64);
  FileInfo.pcwszCatalogFilePath = pcwszCatalogFilePath;
  _mm_storeu_si128((__m128i *)&FileInfo.pcwszMemberFilePath, (__m128i)0i64);
  FileInfo.pcwszMemberFilePath = pcwszMemberFilePath;
  FileInfo.pcwszMemberTag = szBuffer;
  FileInfo.field_20 = 0;
  FileInfo.cbStruct = sizeof(WINTRUST_CATALOG_INFO_EX);
  FileInfo.TextLen = TextLen;
  FileInfo.pszText = (int)pszText;
  memset(ActionData, 0, sizeof(WINTRUST_DATA_EX));
  ActionData->dwUIChoice = WTD_UI_NONE;
  ActionData->dwUnionChoice = WTD_CHOICE_CATALOG;
  ActionData->dwStateAction = HANDLE_FLAG_INHERIT;
  ActionData->cbStruct = 4 * (dwIndex != -1) + 0x30;
  ActionData->fdwRevocationChecks = fdwRevocationChecks != 0;
  ActionData->pFile = (DWORD)&FileInfo;
  if ( dwIndex != -1 )
  {
    _mm_storeu_si128((__m128i *)&Settings, (__m128i)0i64);
    Settings.cbStruct = sizeof(WINTRUST_SIGNATURE_SETTINGS_);
    *(_QWORD *)&Settings.dwVerifiedSigIndex = 0i64;
    Settings.dwFlags = 1;
    Settings.dwIndex = dwIndex;
    ActionData->pSignatureSettings = &Settings;
  }
  ret = WinVerifyTrust(0, &GUID_DefaultId_1_3_6_1_5_5_7_3_3, ActionData);
  if ( !ret )
  {
    v14 = ppcwszCatalogFilePathIn;
    if ( ppcwszCatalogFilePathIn )
      *v14 = _wcsdup(cwszCatalogFilePath);
  }
  return ret;
}

//----- (00C09BB0) --------------------------------------------------------
LONG __cdecl PE_DoubleVerify(LPCWSTR pcwszMemberFilePath, LPCWSTR pcwszCatalogFilePath, HCATADMIN hCatAdmin, bool fdwRevocationChecks, WINTRUST_DATA_EX **ppActionData, DWORD *pdwCertEncodingTypeCount1, PCCERT_CONTEXT *ppCertContext1, PCCERT_CHAIN_CONTEXT *ppCertChainContext1, DWORD *pdwCertEncodingTypeCount2, PCCERT_CONTEXT *ppCertContext2, PCCERT_CHAIN_CONTEXT *ppChainContext2, WCHAR **ppcwszCatalogFilePath, DWORD dwIndex)
{
  DWORD *pdwCertEncodingTypeCount2_1_1; // ebx
  const WCHAR *v14; // eax
  DWORD dwUnionChoice; // eax
  LONG result; // eax
  LONG lError1; // ecx
  WCHAR *v18; // eax
  HANDLE hFile; // ebx
  MACRO_HRESULT v20; // eax
  WINTRUST_SIGNATURE_SETTINGS Settings; // [esp+Ch] [ebp-B0h]
  WINTRUST_FILE_INFO_EX FileInfo; // [esp+24h] [ebp-98h]
  HCATADMIN *hCatAdmin_1; // [esp+34h] [ebp-88h]
  DWORD v24; // [esp+38h] [ebp-84h]
  WINTRUST_DATA_EX **ppActionData_1; // [esp+3Ch] [ebp-80h]
  WINTRUST_DATA_EX ActionData; // [esp+40h] [ebp-7Ch]
  PCERT_CONTEXT *ppCertrContext1_1; // [esp+74h] [ebp-48h]
  PCCERT_CONTEXT *ppCertChainContext1_1; // [esp+78h] [ebp-44h]
  PCERT_CONTEXT ppCertContext2_1; // [esp+7Ch] [ebp-40h]
  int ppChainContext2_1; // [esp+80h] [ebp-3Ch]
  LPCWSTR pcwszCatalogFilePath_1; // [esp+84h] [ebp-38h]
  HCATADMIN phCatAdmin; // [esp+88h] [ebp-34h]
  DWORD dwUnionChoice_1; // [esp+8Ch] [ebp-30h]
  MACRO_HRESULT lResult; // [esp+90h] [ebp-2Ch]
  int dwHash; // [esp+94h] [ebp-28h]
  DWORD *pdwCertEncodingTypeCount2_1; // [esp+98h] [ebp-24h]
  LPCWSTR pcwszMemberFilePathIn; // [esp+9Ch] [ebp-20h]
  LONG lError; // [esp+A0h] [ebp-1Ch]
  WCHAR cbHash[10]; // [esp+A4h] [ebp-18h]

  pcwszMemberFilePathIn = pcwszMemberFilePath;
  pcwszCatalogFilePath_1 = pcwszCatalogFilePath;
  hCatAdmin_1 = (HCATADMIN *)hCatAdmin;
  ppActionData_1 = ppActionData;
  ppCertrContext1_1 = (PCERT_CONTEXT *)ppCertContext1;
  pdwCertEncodingTypeCount2_1_1 = pdwCertEncodingTypeCount2;
  ppCertChainContext1_1 = (PCCERT_CONTEXT *)ppCertChainContext1;
  ppCertContext2_1 = (PCERT_CONTEXT)ppCertContext2;
  pdwCertEncodingTypeCount2_1 = pdwCertEncodingTypeCount2;
  ppChainContext2_1 = (int)ppChainContext2;
  dwHash = 20;
  lResult = TRUST_E_NOSIGNATURE;
  LoadWintrust();
  if ( ppcwszCatalogFilePath )
    *ppcwszCatalogFilePath = 0;
  v14 = pcwszMemberFilePathIn;
  _mm_storeu_si128((__m128i *)&FileInfo, (__m128i)0i64);
  FileInfo.pcwszFilePath = v14;
  FileInfo.cbStruct = sizeof(WINTRUST_FILE_INFO_EX);
  memset(&ActionData, 0, sizeof(WINTRUST_DATA_EX));
  ActionData.dwUIChoice = WTD_UI_NONE;
  ActionData.dwUnionChoice = WTD_CHOICE_FILE;
  ActionData.dwStateAction = HANDLE_FLAG_INHERIT;
  v24 = 4 * (dwIndex != -1) + 0x30;
  ActionData.cbStruct = 4 * (dwIndex != -1) + 0x30;
  dwUnionChoice = 0;
  if ( fdwRevocationChecks )
    dwUnionChoice = WTD_REVOCATION_CHECK_CHAIN;
  dwUnionChoice_1 = dwUnionChoice;
  ActionData.fdwRevocationChecks = dwUnionChoice;
  ActionData.pFile = (DWORD)&FileInfo;
  if ( dwIndex != -1 )
  {
    _mm_storeu_si128((__m128i *)&Settings, (__m128i)0i64);
    Settings.cbStruct = sizeof(WINTRUST_SIGNATURE_SETTINGS);
    *(_QWORD *)&Settings.dwVerifiedSigIndex = 0i64;
    Settings.dwFlags = 1;
    Settings.dwIndex = dwIndex;
    ActionData.pSignatureSettings = &Settings;
  }
  result = WinVerifyTrust(0, &GUID_ActionID, &ActionData);
  lError = result;
  if ( !result || result == CERT_E_REVOKED )
  {
    if ( ppcwszCatalogFilePath )
    {
      *ppcwszCatalogFilePath = _wcsdup(pcwszMemberFilePathIn);
      result = lError;
    }
    goto LABEL_15;
  }
  if ( !pdwCertEncodingTypeCount1 )
  {
LABEL_15:
    lError1 = TRUST_E_NOSIGNATURE;
    goto LABEL_16;
  }
  memset(&ActionData, 0, sizeof(WINTRUST_DATA_EX));
  ActionData.cbStruct = v24;
  ActionData.fdwRevocationChecks = dwUnionChoice_1;
  ActionData.pFile = (DWORD)&FileInfo;
  ActionData.pSignatureSettings = &Settings;
  ActionData.dwUIChoice = WTD_UI_NONE;
  ActionData.dwUnionChoice = WTD_UI_ALL;
  ActionData.dwStateAction = HANDLE_FLAG_INHERIT;
  ActionData.dwProvFlags = WTD_HASH_ONLY_FLAG;
  lError1 = WinVerifyTrust(0, &GUID_ActionID, &ActionData);
  dwUnionChoice_1 = lError1;
  if ( lError1 || !ppcwszCatalogFilePath )
  {
    result = lError;
  }
  else
  {
    v18 = _wcsdup(pcwszMemberFilePathIn);
    lError1 = dwUnionChoice_1;
    *ppcwszCatalogFilePath = v18;
    result = lError;
  }
LABEL_16:
  if ( !result || !lError1 )
    goto __returnZERO;
  if ( *(_DWORD *)CryptCATAdminAcquireContext )
  {
    hFile = CreateFileW(pcwszMemberFilePathIn, GENERIC_READ, FILE_SHARE_READ, 0, 3u, FILE_ATTRIBUTE_NORMAL, 0);
    if ( hFile == (HANDLE)INVALID_HANDLE_VALUE )
    {
LABEL_30:
      pdwCertEncodingTypeCount2_1_1 = pdwCertEncodingTypeCount2_1;
      result = lError;
      goto __returnOK;
    }
    if ( !CryptCATAdminCalcHashFromFileHandle(hFile, (DWORD *)&dwHash, (BYTE *)cbHash, 0) )
    {
      CloseHandle(hFile);
      goto LABEL_30;
    }
    CloseHandle(hFile);
    if ( hCatAdmin_1 )
    {
      v20 = PE_CryptedVerify(
              *hCatAdmin_1,
              (WCHAR *)pcwszMemberFilePathIn,
              fdwRevocationChecks,
              (BYTE *)cbHash,
              dwHash,
              &ActionData,
              ppcwszCatalogFilePath,
              dwIndex);
    }
    else
    {
      if ( !pcwszCatalogFilePath_1 )
        goto LABEL_28;
      v20 = PE_VerifyFile(
              (WCHAR *)pcwszMemberFilePathIn,
              fdwRevocationChecks,
              cbHash,
              dwHash,
              &ActionData,
              (WCHAR *)pcwszCatalogFilePath_1,
              ppcwszCatalogFilePath,
              dwIndex);
    }
    lResult = v20;
    if ( v20 == 0 )
      goto LABEL_30;
LABEL_28:
    CryptCATAdminAcquireContext(&phCatAdmin, 0, 0);
    lResult = PE_CryptedVerify(
                phCatAdmin,
                (WCHAR *)pcwszMemberFilePathIn,
                fdwRevocationChecks,
                (BYTE *)cbHash,
                dwHash,
                &ActionData,
                ppcwszCatalogFilePath,
                dwIndex);
    if ( phCatAdmin )
      CryptCATAdminReleaseContext(phCatAdmin, 0);
    goto LABEL_30;
  }
__returnOK:
  if ( lResult )
  {
    if ( pdwCertEncodingTypeCount1 )
      *pdwCertEncodingTypeCount1 = 0;
    if ( pdwCertEncodingTypeCount2_1_1 )
      *pdwCertEncodingTypeCount2_1_1 = 0;
    return result;
  }
__returnZERO:
  if ( pdwCertEncodingTypeCount1 )
    sub_C09700(
      (HANDLE)ActionData.hWVTStateData,
      0,
      ppActionData_1,
      pdwCertEncodingTypeCount1,
      (_CRYPT_PROVIDER_CERT **)ppCertrContext1_1,
      ppCertChainContext1_1);
  if ( pdwCertEncodingTypeCount2_1_1 )
    sub_C09700(
      (HANDLE)ActionData.hWVTStateData,
      1,
      0,
      pdwCertEncodingTypeCount2_1_1,
      (_CRYPT_PROVIDER_CERT **)ppCertContext2_1,
      (PCCERT_CONTEXT *)ppChainContext2_1);
  ActionData.dwStateAction = HANDLE_FLAG_PROTECT_FROM_CLOSE;
  WinVerifyTrust(0, &GUID_ActionID, &ActionData);
  return 0;
}
// C09F40: using guessed type bool __cdecl LoadWintrust();

//----- (00C09F40) --------------------------------------------------------
bool LoadWintrust()
{
  HMODULE v0; // eax
  HMODULE v1; // edi
  HMODULE v3; // eax

  if ( !byte_CD4D7C )
  {
    byte_CD4D7C = 1;
    v0 = LoadLibraryW(L"Wintrust.dll");
    v1 = v0;
    if ( !v0 )
      return 0;
    *(_DWORD *)WinVerifyTrust = GetProcAddress(v0, "WinVerifyTrust");
    *(_DWORD *)WTHelperGetProvSignerFromChain = GetProcAddress(v1, "WTHelperGetProvSignerFromChain");
    *(_DWORD *)WTHelperProvDataFromStateData = GetProcAddress(v1, "WTHelperProvDataFromStateData");
    *(_DWORD *)CryptCATAdminReleaseContext = GetProcAddress(v1, "CryptCATAdminReleaseContext");
    *(_DWORD *)CryptCATAdminReleaseCatalogContext = GetProcAddress(v1, "CryptCATAdminReleaseCatalogContext");
    *(_DWORD *)CryptCATCatalogInfoFromContext = GetProcAddress(v1, "CryptCATCatalogInfoFromContext");
    *(_DWORD *)CryptCATAdminEnumCatalogFromHash = GetProcAddress(v1, "CryptCATAdminEnumCatalogFromHash");
    *(_DWORD *)CryptCATAdminCalcHashFromFileHandle = GetProcAddress(v1, "CryptCATAdminCalcHashFromFileHandle");
    *(_DWORD *)CryptCATAdminAcquireContext = GetProcAddress(v1, "CryptCATAdminAcquireContext");
    *(_DWORD *)CryptCATAdminAddCatalog = GetProcAddress(v1, "CryptCATAdminAddCatalog");
    *(_DWORD *)CryptCATAdminRemoveCatalog = GetProcAddress(v1, "CryptCATAdminRemoveCatalog");
    *(_DWORD *)IsCatalogFile = GetProcAddress(v1, "IsCatalogFile");
    v3 = LoadLibraryW(L"crypt32.dll");
    *(_DWORD *)CertNameToStrW = GetProcAddress(v3, "CertNameToStrW");
  }
  return *(_DWORD *)CryptCATAdminAcquireContext != 0;
}
// C09F40: using guessed type bool __cdecl LoadWintrust();
// CD4D7C: using guessed type char byte_CD4D7C;

//----- (00C0A040) --------------------------------------------------------
CTreeList *__thiscall CTreeList::CTreeList(CTreeList *this)
{
  CTreeList *result; // eax

  this->baseclass.m_hThemeHandle = 0;
  result = this;
  this->baseclass.vtptr = (CThemedWindowVTable *)&CTreeList::`vftable';
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
  this->m_Item_40 = 0;
  this->field_44.x = 0;
  this->field_44.y = 0;
  this->m_ChildItem = 0;
  this->m_ChildLastSort = 0;
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
  this->m_nHeaderHeight = 20;
  this->m_nChildWidthLast = 0;
  *(_WORD *)&this->m_bValue1 = 1;
  this->m_nHeaderItemCount = -1;
  this->field_A8 = -1;
  this->field_AC = 0;
  this->field_B4 = -1;
  this->field_B8 = -1;
  this->field_BC = 1;
  LOBYTE(this->m_ptDownLast.y) = 0;
  this->m_KeyName = 0;
  this->m_pfnDrawBack = 0;
  this->m_pfnGetChildCursor = 0;
  this->m_Format = 0x8820;
  this->field_50 = 0;
  this->field_4C = 0;
  return result;
}
// CA4188: using guessed type void *CTreeList::`vftable';

//----- (00C0A1F0) --------------------------------------------------------
HTHEME __thiscall CTreeList::~CTreeList(CTreeList *this)
{
  CTreeList *v1; // edi
  tagKeyName v2; // esi
  HTHEME result; // eax

  v1 = this;
  this->baseclass.vtptr = (CThemedWindowVTable *)&CTreeList::`vftable';
  v2.bstrText1.m_Data = (Data_t_bstr_t *)this->m_KeyName;
  if ( v2.bstrText1.m_Data )
  {
    if ( !InterlockedDecrement(&v2.bstrText1.m_Data->m_RefCount) && v2.bstrText1.m_Data )
    {
      if ( v2.bstrText1.m_Data->m_wstr )
      {
        SysFreeString(v2.bstrText1.m_Data->m_wstr);
        v2.bstrText1.m_Data->m_wstr = 0;
      }
      if ( v2.bstrText1.m_Data->m_str )
      {
        operator delete[](v2.bstrText1.m_Data->m_str);
        v2.bstrText1.m_Data->m_str = 0;
      }
      operator delete(v2.bstrText1.m_Data);
    }
    v1->m_KeyName = 0;
  }
  sub_C0A2C0((tagTreeViewChildItem *)&v1->m_Item_40);
  result = v1->baseclass.m_hThemeHandle;
  v1->baseclass.vtptr = (CThemedWindowVTable *)&CThemedWindow::`vftable';
  if ( result )
    result = (HTHEME)gpfnCloseThemeData(result);
  return result;
}
// CA4130: using guessed type void *CThemedWindow::`vftable';
// CA4188: using guessed type void *CTreeList::`vftable';

//----- (00C0A2C0) --------------------------------------------------------
void __thiscall sub_C0A2C0(tagTreeViewChildItem *this)
{
  tagTreeViewChildItem *v1; // edx
  tagTreeViewChildItem *v2; // edx
  tagTreeViewChildItem *v3; // edx
  tagTreeViewChildItem *v4; // edx
  tagTreeViewChildItem *v5; // eax
  CTreeListData *v6; // edx

  v1 = this->m_Item0C;
  if ( v1 )
    v1->m_Sibling = this->m_Sibling;
  v2 = this->m_Sibling;
  if ( v2 )
    v2->m_Item0C = this->m_Item0C;
  v3 = this->m_Current;
  if ( v3 )
  {
    if ( v3->m_Child == this )
      v3->m_Child = this->m_Sibling;
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
    v6->vtptr->Delete(v6, this);
}

//----- (00C0A320) --------------------------------------------------------
_bstr_t *__thiscall _bstr_t::operator=(_bstr_t *this, LPCSTR lpString)
{
  _bstr_t *v2; // edi
  _bstr_t v3; // esi
  char *v4; // eax
  Data_t_bstr_t *v5; // eax
  Data_t_bstr_t *v6; // esi

  v2 = this;
  if ( !lpString )
    goto LABEL_16;
  v3.m_Data = this->m_Data;
  if ( this->m_Data )
  {
    if ( !v3.m_Data->m_str )
      v3.m_Data->m_str = _com_util::ConvertBSTRToString(v3.m_Data->m_wstr);
    v4 = v3.m_Data->m_str;
  }
  else
  {
    v4 = 0;
  }
  if ( v4 != lpString )
  {
LABEL_16:
    _bstr_t::_Free(v2);
    v5 = (Data_t_bstr_t *)operator new(0xCu);
    v6 = v5;
    if ( v5 )
    {
      v5->m_str = 0;
      v5->m_RefCount = 1;
      v5->m_wstr = _com_util::ConvertStringToBSTR(lpString);
    }
    else
    {
      v6 = 0;
    }
    v2->m_Data = v6;
    if ( !v6 )
      _com_issue_error(E_OUTOFMEMORY);
  }
  return v2;
}

//----- (00C0A3E0) --------------------------------------------------------
BOOL __thiscall _bstr_t::operator==(_bstr_t *this, _bstr_t *rOther)
{
  _bstr_t *pThis; // ecx
  Data_t_bstr_t *pOther; // eax
  OLECHAR *v5; // eax

  pThis = (_bstr_t *)this->m_Data;
  pOther = rOther->m_Data;
  if ( pThis == (_bstr_t *)rOther->m_Data )
    return 1;
  if ( !pThis )
  {
    if ( pOther )
    {
      v5 = pOther->m_wstr;
      if ( v5 )
      {
        if ( SysStringLen(v5) )
          return 0;
      }
    }
    return 1;
  }
  if ( pOther )
    return _bstr_t::Data_t::Compare((Data_t_bstr_t *)pThis, rOther->m_Data) == 0;
  if ( !pThis->m_Data || !SysStringLen((BSTR)pThis->m_Data) )
    return 1;
  return 0;
}

//----- (00C0A460) --------------------------------------------------------
void *__thiscall CTreeListData::`scalar deleting destructor'(void *this, char a2)
{
  void *v2; // esi

  v2 = this;
  *(_DWORD *)this = &CTreeListData::`vftable';
  if ( a2 & 1 )
    operator delete(this);
  return v2;
}
// CA414C: using guessed type void *CTreeListData::`vftable';

//----- (00C0A490) --------------------------------------------------------
HWND __cdecl CTreeList::Init(HWND hWndParent, HINSTANCE hInstance, HMENU hMenu, int a4, #153 *lprc)
{
  CTreeList *v5; // eax
  CTreeList *v6; // ebx

  v5 = (CTreeList *)operator new(0xDCu);
  if ( v5 )
    v6 = CTreeList::CTreeList(v5);
  else
    v6 = 0;
  v6->m_hWnd = CreateWindowExW(
                 0,
                 (LPCWSTR)(unsigned __int16)gAtomTreeList,
                 (LPCWSTR)&gszNullString,
                 a4 | 0x2000000,
                 *(_DWORD *)lprc,
                 *((_DWORD *)lprc + 1),
                 *((_DWORD *)lprc + 2) - *(_DWORD *)lprc,
                 *((_DWORD *)lprc + 3) - *((_DWORD *)lprc + 1),
                 hWndParent,
                 hMenu,
                 hInstance,
                 v6);
  CTreeList::OnInited(v6);
  return v6->m_hWnd;
}
// CD4D9C: using guessed type __int16 gAtomTreeList;

//----- (00C0A510) --------------------------------------------------------
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
  _mm_storeu_si128((__m128i *)&v6, (__m128i)0i64);
  _mm_storeu_si128((__m128i *)&Rect.right, (__m128i)0i64);
  v6 = hWndParent;
  v8 = -1;
  GetClientRect(hWndParent, &Rect);
  SendMessageW(v2, TTM_ADDTOOLW, 0, (LPARAM)&lParam);
  return v2;
}

//----- (00C0A5B0) --------------------------------------------------------
LRESULT __stdcall CThemedWindow::HandleMessage(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
  return DefWindowProcW(hWnd, Msg, wParam, lParam);
}

//----- (00C0A5C0) --------------------------------------------------------
int __stdcall CListViewData::Delete(tagTreeViewChildItem *pChild)
{
  CListViewData *v1; // ecx
  CListViewData *v2; // edi
  CTreeList *v3; // esi
  int nItem; // eax
  tagTREEVIEWLISTITEMPARAM *v5; // eax
  HWND v6; // eax
  NMLISTVIEW NmListView; // [esp+8h] [ebp-2Ch]

  v2 = v1;
  v3 = pChild->m_TreeList;
  nItem = CTreeList::FindChild(pChild->m_TreeList, pChild);
  NmListView.hdr.hwndFrom = 0;
  _mm_storeu_si128((__m128i *)&NmListView.hdr.idFrom, (__m128i)0i64);
  NmListView.iItem = nItem;
  v5 = v2->m_TreeItem;
  *(_QWORD *)&NmListView.ptAction.y = 0i64;
  NmListView.lParam = v5;
  _mm_storeu_si128((__m128i *)&NmListView.uNewState, (__m128i)0i64);
  v6 = GetParent(v3->m_hWnd);
  return SendMessageW(v6, LVN_DELETEITEM, 0, (LPARAM)&NmListView);
}

//----- (00C0A620) --------------------------------------------------------
int __thiscall CTreeList::OnDestroy(CTreeList *this)
{
  CTreeList *v1; // esi
  bool v2; // zf
  HWND v3; // ST00_4

  v1 = this;
  v2 = this->m_ChildItem == 0;
  this->m_bSkipTimerForTooltip = 1;
  if ( !v2 )
  {
    do
      CTreeList::RemoveItem(v1, v1->m_ChildItem);
    while ( v1->m_ChildItem );
  }
  v3 = v1->m_hWnd;
  v1->m_bSkipTimerForTooltip = 0;
  InvalidateRect(v3, 0, 0);
  InvalidateRect(v1->m_hWndHeaderLeft, 0, 0);
  InvalidateRect(v1->m_hWndHeaderRight, 0, 0);
  v1->m_nChildWidthLast = CTreeList::GetChildWidth(v1, 0);
  CTreeList::Resize(v1);
  CTreeList::RepositionHeaders();
  return CTreeList::RepositionTooltips();
}

//----- (00C0A690) --------------------------------------------------------
bool __thiscall CTreeList::DeleteColumn(CTreeList *this, int nColumn)
{
  CTreeList *v2; // edi
  LRESULT nCountLeft; // esi
  LRESULT nCountRight; // eax
  HWND v6; // ST00_4
  HDITEMW Item; // [esp+4h] [ebp-238h]
  char v8[520]; // [esp+30h] [ebp-20Ch]

  v2 = this;
  if ( nColumn )
    return SendMessageW(this->m_hWndHeaderRight, HDM_DELETEITEM, nColumn - 1, 0) != 0;
  nCountLeft = SendMessageW(this->m_hWndHeaderLeft, HDM_GETITEMCOUNT, 0, 0);
  nCountRight = SendMessageW(v2->m_hWndHeaderRight, HDM_GETITEMCOUNT, 0, 0);
  if ( !nCountLeft )
    return 0;
  if ( !nCountRight )
    return SendMessageW(v2->m_hWndHeaderLeft, HDM_DELETEITEM, 0, 0) != 0;
  Item.mask = 7;
  Item.pszText = (LPWSTR)v8;
  v6 = v2->m_hWndHeaderRight;
  Item.cchTextMax = 260;
  SendMessageW(v6, HDM_GETITEMW, 0, (LPARAM)&Item);
  SendMessageW(v2->m_hWndHeaderLeft, HDM_DELETEITEM, 0, 0);
  SendMessageW(v2->m_hWndHeaderRight, HDM_DELETEITEM, 0, 0);
  SendMessageW(v2->m_hWndHeaderLeft, HDM_INSERTITEMW, 0, (LPARAM)&Item);
  CTreeList::MoveHeaders(v2, Item.cxy);
  return 1;
}

//----- (00C0A7D0) --------------------------------------------------------
void __thiscall CTreeList::RemoveItem(CTreeList *this, tagTreeViewChildItem *pChild)
{
  tagTreeViewChildItem *pChild_1; // edi
  CTreeList *pThis; // esi
  tagTreeViewChildItem *i; // eax
  HWND v5; // eax
  UINT nCtrlId; // eax
  bool v7; // zf
  HWND v8; // eax
  WPARAM v9; // ST10_4
  HWND v10; // eax
  tagTreeViewChildItem *v11; // ebx
  NMHDR nmhdr; // [esp+Ch] [ebp-1Ch]
  int v13; // [esp+18h] [ebp-10h]
  tagTreeViewChildItem *v14; // [esp+1Ch] [ebp-Ch]
  int v15; // [esp+20h] [ebp-8h]
  int v16; // [esp+24h] [ebp-4h]
  tagTreeViewChildItem *pChilda; // [esp+30h] [ebp+8h]

  pChild_1 = pChild;
  pThis = this;
  for ( i = pChild->m_Child; i; i = pChild->m_Child )
    CTreeList::RemoveItem(pThis, i);
  v5 = pThis->m_hWnd;
  nmhdr.code = 0x7D6;
  nmhdr.hwndFrom = v5;
  nCtrlId = GetWindowLongW(v5, GWLP_ID);
  v7 = LOBYTE(pThis->m_ptDownLast.y) == 0;
  nmhdr.idFrom = nCtrlId;
  v15 = 0;
  v13 = 0;
  v14 = pChild;
  v16 = 0;
  if ( v7 )
  {
    v9 = nCtrlId;
    v10 = GetParent(pThis->m_hWnd);
    SendMessageW(v10, WM_NOTIFY, v9, (LPARAM)&nmhdr);
  }
  else
  {
    v8 = GetParent(pThis->m_hWnd);
    CTreeList::SendNotifyEx(pThis, v8, (TVNMHDR *)&nmhdr);
  }
  if ( pThis->m_ChildLast == pChild )
  {
    CTreeList::SendNotify(pThis, pThis->m_hWnd, 0x7D0, 0, 0, pChild, 0);
    pThis->m_ChildLast = 0;
  }
  if ( pThis->field_AC == pChild )
    pThis->field_AC = 0;
  pChilda = (tagTreeViewChildItem *)CTreeList::FindChild(pThis, pChild);
  CTreeList::SetVScrollbarPos((int)pChilda, -1);
  v11 = pChild_1->m_Current;
  sub_C0A2C0(pChild_1);
  operator delete(pChild_1);
  if ( v11 )
  {
    if ( !(v11->m_dwStyle & 0x40) )
      CTreeList::RedrawZone(pThis, (int)&pChilda[-1].m_dwReserved + 3, (int)&pChilda[-1].m_dwReserved + 3);
  }
}

//----- (00C0A8E0) --------------------------------------------------------
signed int __thiscall TreeViewChildItem_GetSiblingCount(tagTreeViewChildItem *this)
{
  tagTreeViewChildItem *v1; // ecx
  signed int result; // eax

  v1 = this->m_Current;
  for ( result = -1; v1; ++result )
    v1 = v1->m_Current;
  return result;
}

//----- (00C0A900) --------------------------------------------------------
void __thiscall CTreeList::DrawHeader(CTreeList *this, HWND hWndHeader, HDC hDC, struct tagRECT a4)
{
  CTreeList *this_1; // esi
  HDC hdcWindow; // edi
  signed int nCount; // ebx
  HBRUSH v7; // eax
  int *v8; // eax
  signed int nIndex; // edi
  HWND v10; // ST08_4
  #153 *v11; // ecx
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
  #153 *pRect; // [esp+18h] [ebp-2A0h]
  HDC hdc; // [esp+1Ch] [ebp-29Ch]
  int i; // [esp+20h] [ebp-298h]
  int *pFormat; // [esp+24h] [ebp-294h]
  HWND hWndHeader_1; // [esp+28h] [ebp-290h]
  int *nFormat; // [esp+2Ch] [ebp-28Ch]
  RECT *rcItem; // [esp+30h] [ebp-288h]
  int tm; // [esp+34h] [ebp-284h]
  HDITEMW Item; // [esp+44h] [ebp-274h]
  int rc; // [esp+70h] [ebp-248h]
  int v34; // [esp+78h] [ebp-240h]
  struct tagSCROLLINFO ScrollInfo; // [esp+80h] [ebp-238h]
  struct tagRECT rcText; // [esp+9Ch] [ebp-21Ch]
  WCHAR chText[260]; // [esp+ACh] [ebp-20Ch]

  this_1 = this;
  hWndHeader_1 = hWndHeader;
  hdc = hDC;
  _mm_storeu_si128((__m128i *)&rc, _mm_loadu_si128((const __m128i *)&a4));
  hdcWindow = GetDC(this->m_hWnd);
  SelectObject(hdcWindow, this_1->m_Font);
  GetTextMetricsW(hdcWindow, (LPTEXTMETRICW)&tm);
  ReleaseDC(this_1->m_hWnd, hdcWindow);
  if ( this_1->m_ImageList )
    GetSystemMetrics(SM_CYSMICON);
  GetWindowRect(this_1->m_hWndHeaderLeft, (LPRECT)&ScrollInfo.nMax);
  if ( hWndHeader_1 == this_1->m_hWndHeaderLeft )
  {
    nCount = 1;
    rcItem = (RECT *)1;
  }
  else
  {
    rcItem = (RECT *)SendMessageW(this_1->m_hWndHeaderRight, HDM_GETITEMCOUNT, 0, 0);
    if ( !rcItem )
    {
      v7 = GetSysColorBrush(COLOR_WINDOW);
      FillRect(hDC, (const RECT *)&rc, v7);
      return;
    }
    nCount = (signed int)rcItem;
  }
  v8 = (int *)operator new[](4 * nCount);
  pnIds = v8;
  if ( hWndHeader_1 == this_1->m_hWndHeaderLeft )
    *v8 = 0;
  else
    SendMessageW(this_1->m_hWndHeaderRight, HDM_GETORDERARRAY, nCount, (LPARAM)v8);
  pRect = (#153 *)operator new[](16 * nCount);
  nIndex = 0;
  pFormat = (int *)operator new[](4 * nCount);
  for ( i = 0; nIndex < (signed int)rcItem; i = v13 )
  {
    nFormat = (int *)((char *)pRect + 16 * nIndex);
    SendMessageW(hWndHeader_1, HDM_GETITEMRECT, pnIds[nIndex], (LPARAM)pRect + 16 * nIndex);
    InflateRect((LPRECT)nFormat, -2, -2);
    if ( hWndHeader_1 == this_1->m_hWndHeaderLeft && !nIndex )
    {
      if ( this_1->m_bValue1 )
      {
        ScrollInfo.cbSize = sizeof(SCROLLINFO);
        v10 = this_1->m_hWndScrollBarLeftBottom;
        ScrollInfo.nTrackPos = 0;
        _mm_storeu_si128((__m128i *)&ScrollInfo.nMin, (__m128i)0i64);
        ScrollInfo.fMask = SIF_POS;
        GetScrollInfo(v10, SB_CTL, &ScrollInfo);
        v11 = pRect;
        *(_DWORD *)v11 -= ScrollInfo.nPos;
        v12 = *(_DWORD *)v11 + this_1->m_nChildWidthLast;
        if ( *((_DWORD *)v11 + 2) < v12 )
          *((_DWORD *)v11 + 2) = v12;
      }
    }
    pFormat[nIndex] = this_1->m_Format;
    if ( hWndHeader_1 != this_1->m_hWndHeaderLeft )
    {
      Item.mask = HDI_FORMAT;
      SendMessageW(this_1->m_hWndHeaderRight, HDM_GETITEMW, pnIds[nIndex], (LPARAM)&Item);
      if ( Item.fmt & HDF_RIGHT )
        pFormat[nIndex] |= DT_RIGHT;
    }
    if ( nCount > nIndex && nFormat[2] > rc )
      nCount = nIndex;
    v13 = i;
    if ( *nFormat < v34 )
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
    rcItem = (RECT *)((char *)pRect + 16 * nCount);
    v21 = (char *)pnIds - (char *)pFormat;
    do
    {
      BkColor = GetBkColor(hdc_1);
      if ( hWndHeader_1 == this_1->m_hWndHeaderLeft )
        v16 = nCount;
      else
        v16 = *(int *)((char *)nFormat + v21) + 1;
      if ( ((unsigned __int8 (__cdecl *)(int, HDC, COLORREF *))this_1->m_pfnDrawBack)(v16, hdc_1, &BkColor) )
      {
        ValidateRect(hWndHeader_1, rcItem);
        hdc = (HDC)CreateSolidBrush(BkColor);
        GetBkMode(hdc_1);
        Item.pszText = chText;
        Item.mask = HDI_TEXT;
        v17 = nFormat;
        _mm_storeu_si128((__m128i *)&ScrollInfo.nMax, (__m128i)0i64);
        Item.cchTextMax = 260;
        SendMessageW(hWndHeader_1, HDM_GETITEMW, *(int *)((char *)v17 + v21), (LPARAM)&Item);
        rcText.left = this_1->m_nImageWidth + rcItem->left;
        rcText.top = this_1->m_Height + rcItem->top;
        rcText.right = rcItem->right - this_1->m_nImageWidth;
        rcText.bottom = rcItem->bottom;
        DrawTextW(hdc_1, chText, -1, (LPRECT)&ScrollInfo.nMax, *nFormat | DT_CALCRECT);
        if ( rcText.bottom - rcText.top < ScrollInfo.nTrackPos )
          rcText.top = rcText.bottom - ScrollInfo.nTrackPos;
        SetBkColor(hdc_1, BkColor);
        FillRect(hdc_1, rcItem, (HBRUSH)hdc);
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
  operator delete[]((void *)pRect);
  operator delete[](pnIds);
  operator delete[](pFormat);
}

//----- (00C0AE40) --------------------------------------------------------
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

  lParam.nmhdr.hwndFrom = (HWND)code;
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
    result = SendMessageW(v13, WM_NOTIFY, v12, (LPARAM)&lParam);
  }
  else
  {
    hWndParent = GetParent(v7->m_hWnd);
    result = CTreeList::SendNotifyEx(v7, hWndParent, &lParam);
  }
  return result;
}

//----- (00C0AEC0) --------------------------------------------------------
void __thiscall CTreeList::DrawTree(CTreeList *this, LPPAINTSTRUCT lpps, HRGN hRgn)
{
  CTreeList *pThis; // ebx
  HDC hDC; // edi
  HWND m_hWnd; // ST20_4
  int v6; // eax
  int TextHeight; // ecx
  UINT nHeaderLeftHeight; // edi
  int nCount; // ebx
  int top; // eax
  int nEndLine; // ecx
  int nStartLine; // eax
  UINT *pnIDs; // eax
  CTreeList *THIS; // edi
  WPARAM nRightCount; // ecx
  const __m128i *pnIDs_First; // ebx
  int nCount_1; // edx
  signed int nIndex; // eax
  int v19; // ecx
  __m128i v20; // xmm1
  int v21; // ecx
  __m128i v22; // xmm0
  UINT *v23; // ecx
  int nCount2_1; // eax
  int index; // ebx
  UINT nID; // ecx
  HWND m_hWndScrollBarLeftBottom; // ST1C_4
  RECT *lpRect; // ecx
  int v29; // eax
  int v30; // ecx
  int j_1; // edx
  LPPOINT pt; // eax
  int Right; // eax
  HBRUSH v34; // eax
  COLORREF v35; // eax
  HPEN hPen; // eax
  HDC hDC_1; // ST20_4
  HGDIOBJ hOldPen; // eax
  HFONT v39; // ST24_4
  tagTreeViewChildItem *pChild; // eax
  tagTreeViewChildItem *pNewChild; // eax
  int v42; // ecx
  tagTreeViewChildItem *pNewChild_1; // ebx
  int nHeight_1; // eax
  COLORREF v45; // eax
  COLORREF BackColor; // eax
  COLORREF v47; // eax
  COLORREF v48; // eax
  int nCount2_3; // edx
  RECT *lprect; // edx
  int left; // eax
  int bottom; // ecx
  int right; // edx
  __m128i v54; // xmm0
  int v55; // eax
  HBRUSH v56; // ebx
  int nBottomScrollBarWidthOrHeight; // eax
  int v58; // ST20_4
  CTreeListDataVTable *v59; // eax
  char v60; // al
  COLORREF v61; // eax
  HBRUSH v62; // eax
  HDC v63; // ST24_4
  LONG v64; // ebx
  LONG v65; // eax
  CThemedWindow *v66; // edi
  HDC v67; // ST1C_4
  HBITMAP v68; // eax
  HDC v69; // ST24_4
  HDC v70; // ebx
  HBRUSH v71; // eax
  signed int v72; // eax
  tagTreeViewChildItem *v73; // edx
  LONG v74; // ebx
  int v75; // eax
  int v76; // ebx
  bool v77; // zf
  CTreeListData *v78; // ecx
  int i; // ST34_4
  UINT v80; // ST24_4
  int v81; // edi
  COLORREF v82; // eax
  CTreeList *v83; // ebx
  int v84; // ST10_4
  HDC v85; // edi
  int v86; // eax
  unsigned int v87; // ebx
  const WCHAR *v88; // edi
  UINT v89; // ST24_4
  HDC v90; // ST14_4
  HGDIOBJ v91; // edi
  int v92; // ecx
  int v93; // edx
  int v94; // ebx
  int v95; // eax
  HBRUSH v96; // eax
  tagTreeViewChildItem *v97; // eax
  tagTreeViewChildItem *v98; // eax
  int v99; // ecx
  RECT *v100; // ebx
  int v101; // ecx
  int v102; // eax
  HBRUSH v103; // eax
  HDC v104; // ST20_4
  HGDIOBJ v105; // edi
  void *v106; // ST24_4
  void (__stdcall *SelectObject)(HDC, HGDIOBJ); // edi
  HBRUSH v108; // eax
  RECT *lprc; // [esp-4h] [ebp-364h]
  LPPOINT x_1; // [esp+10h] [ebp-350h]
  int v111; // [esp+18h] [ebp-348h]
  HGDIOBJ hOldFont; // [esp+1Ch] [ebp-344h]
  HGDIOBJ hPenOld; // [esp+20h] [ebp-340h]
  HGDIOBJ h; // [esp+24h] [ebp-33Ch]
  unsigned int v115; // [esp+28h] [ebp-338h]
  int v116; // [esp+2Ch] [ebp-334h]
  int nCount2_2; // [esp+30h] [ebp-330h]
  HDC hdcDst; // [esp+34h] [ebp-32Ch]
  HGDIOBJ ho; // [esp+38h] [ebp-328h]
  HBRUSH hbr; // [esp+3Ch] [ebp-324h]
  HGDIOBJ v121; // [esp+40h] [ebp-320h]
  int yy; // [esp+44h] [ebp-31Ch]
  int xx; // [esp+48h] [ebp-318h]
  unsigned int v124; // [esp+4Ch] [ebp-314h]
  int j; // [esp+50h] [ebp-310h]
  RECT *pRects; // [esp+54h] [ebp-30Ch]
  int nHeight; // [esp+58h] [ebp-308h]
  CTreeList *This; // [esp+5Ch] [ebp-304h]
  int nStartLine_1; // [esp+60h] [ebp-300h]
  UINT *pnFormats; // [esp+64h] [ebp-2FCh]
  int tmHeight; // [esp+68h] [ebp-2F8h]
  UINT *pnIDsTemp; // [esp+6Ch] [ebp-2F4h]
  int nCount2; // [esp+70h] [ebp-2F0h]
  tagTreeViewChildItem *pNewChild_2; // [esp+74h] [ebp-2ECh]
  LONG rc; // [esp+78h] [ebp-2E8h]
  int v136; // [esp+7Ch] [ebp-2E4h]
  int v137; // [esp+80h] [ebp-2E0h]
  int v138; // [esp+84h] [ebp-2DCh]
  struct tagRECT v139; // [esp+88h] [ebp-2D8h]
  int tm; // [esp+98h] [ebp-2C8h]
  MACRO_HDI lParam; // [esp+A8h] [ebp-2B8h]
  struct tagSCROLLINFO v142; // [esp+B8h] [ebp-2A8h]
  RECT x; // [esp+D4h] [ebp-28Ch]
  struct tagRECT rcDst; // [esp+E4h] [ebp-27Ch]
  int v145; // [esp+F4h] [ebp-26Ch]
  LONG v146; // [esp+F8h] [ebp-268h]
  int v147; // [esp+FCh] [ebp-264h]
  LONG v148; // [esp+100h] [ebp-260h]
  struct tagRECT v149; // [esp+104h] [ebp-25Ch]
  int v150; // [esp+114h] [ebp-24Ch]
  LONG v151; // [esp+118h] [ebp-248h]
  int v152; // [esp+11Ch] [ebp-244h]
  LONG v153; // [esp+120h] [ebp-240h]
  int rect; // [esp+124h] [ebp-23Ch]
  int v155; // [esp+128h] [ebp-238h]
  int v156; // [esp+12Ch] [ebp-234h]
  LONG v157; // [esp+130h] [ebp-230h]
  LONG rcSrc2; // [esp+134h] [ebp-22Ch]
  int v159; // [esp+138h] [ebp-228h]
  LONG v160; // [esp+13Ch] [ebp-224h]
  LONG v161; // [esp+140h] [ebp-220h]
  int v162; // [esp+144h] [ebp-21Ch]
  int v163; // [esp+148h] [ebp-218h]
  LONG v164; // [esp+14Ch] [ebp-214h]
  LONG v165; // [esp+150h] [ebp-210h]
  char v166; // [esp+154h] [ebp-20Ch]

  pThis = this;
  This = this;
  hDC = GetDC(this->m_hWnd);
  ::SelectObject(hDC, pThis->m_Font);
  GetTextMetricsW(hDC, (LPTEXTMETRICW)&tm);
  m_hWnd = pThis->m_hWnd;
  tmHeight = tm;
  ReleaseDC(m_hWnd, hDC);
  if ( pThis->m_ImageList )
  {
    v6 = GetSystemMetrics(SM_CYSMICON);
    TextHeight = tmHeight;
    if ( tmHeight < v6 )
      TextHeight = v6;
  }
  else
  {
    TextHeight = tmHeight;
  }
  nHeight = TextHeight + pThis->m_nHeight;
  GetWindowRect(pThis->m_hWndHeaderLeft, (LPRECT)&v142.nMax);
  nHeaderLeftHeight = v142.nTrackPos - v142.nPage;
  nCount = SendMessageW(pThis->m_hWndHeaderRight, HDM_GETITEMCOUNT, 0, 0) + 1;
  top = *(_DWORD *)&lpps->gap8[4] - nHeaderLeftHeight;
  nCount2 = nCount;
  nStartLine_1 = top / nHeight;
  nEndLine = (signed int)(*(_DWORD *)&lpps->gap8[12] - nHeaderLeftHeight) / nHeight;
  nStartLine = top / nHeight;
  v116 = (signed int)(*(_DWORD *)&lpps->gap8[12] - nHeaderLeftHeight) / nHeight;
  if ( nStartLine < 0 )
    nStartLine = 0;
  nStartLine_1 = nStartLine;
  if ( !nCount || nStartLine > nEndLine )
  {
    v108 = GetSysColorBrush(COLOR_WINDOW);
    FillRect(lpps->hdc, (const RECT *)lpps->gap8, v108);
    return;
  }
  pnIDs = (UINT *)operator new[](4 * nCount);
  THIS = This;
  nRightCount = nCount2 - 1;
  pnIDsTemp = pnIDs;
  pnIDs_First = (const __m128i *)(pnIDs + 1);
  *pnIDs = 0;
  SendMessageW(THIS->m_hWndHeaderRight, HDM_GETORDERARRAY, nRightCount, (LPARAM)(pnIDs + 1));
  nCount_1 = nCount2;
  nIndex = 1;
  v19 = nCount2 - 1;
  if ( nCount2 > 1 )
  {
    if ( (unsigned int)v19 >= 8 )
    {
      v20 = _mm_load_si128((const __m128i *)&stru_CA4280);
      v121 = (HGDIOBJ)(v19 % 8);
      v21 = nCount2 - v19 % 8;
      do
      {
        v22 = _mm_loadu_si128(pnIDs_First);
        nIndex += 8;
        pnIDs_First += 2;
        _mm_storeu_si128((__m128i *)&pnIDs_First[-2], _mm_add_epi32(v22, v20));
        _mm_storeu_si128((__m128i *)&pnIDs_First[-1], _mm_add_epi32(_mm_loadu_si128(pnIDs_First - 1), v20));
      }
      while ( nIndex < v21 );
    }
    if ( nIndex < nCount2 )
    {
      v23 = pnIDsTemp;
      do
        ++v23[nIndex++];
      while ( nIndex < nCount_1 );
    }
  }
  pRects = (RECT *)operator new[](16 * nCount_1);
  pnFormats = (UINT *)operator new[](4 * nCount2);
  nCount2_1 = nCount2;
  index = 0;
  nCount2_2 = nCount2;
  for ( j = 0; index < nCount2; j = j_1 )
  {
    pNewChild_2 = (tagTreeViewChildItem *)&pRects[index];
    nID = pnIDsTemp[index];
    lprc = &pRects[index];
    if ( nID )
    {
      SendMessageW(THIS->m_hWndHeaderRight, HDM_GETITEMRECT, nID - 1, (LPARAM)lprc);
      MapWindowPoints(THIS->m_hWndHeaderRight, THIS->m_hWnd, (LPPOINT)pNewChild_2, 2u);
    }
    else
    {
      SendMessageW(THIS->m_hWndHeaderLeft, HDM_GETITEMRECT, 0, (LPARAM)lprc);
      MapWindowPoints(THIS->m_hWndHeaderLeft, THIS->m_hWnd, (LPPOINT)pNewChild_2, 2u);
    }
    if ( !index )
    {
      if ( THIS->m_bValue1 )
      {
        v142.cbSize = 28;
        m_hWndScrollBarLeftBottom = THIS->m_hWndScrollBarLeftBottom;
        v142.nTrackPos = 0;
        _mm_storeu_si128((__m128i *)&v142.nMin, (__m128i)0i64);
        v142.fMask = 4;
        GetScrollInfo(m_hWndScrollBarLeftBottom, 2, &v142);
        lpRect = pRects;
        lpRect->left -= v142.nPos;
        v29 = lpRect->left + THIS->m_nChildWidthLast;
        if ( lpRect->right < v29 )
          lpRect->right = v29;
      }
    }
    pnFormats[index] = THIS->m_Format;
    if ( index )
    {
      lParam = HDI_FORMAT;
      SendMessageW(THIS->m_hWndHeaderRight, HDM_GETITEMW, pnIDsTemp[index] - 1, (LPARAM)&lParam);
      if ( v142.fMask & HDF_RIGHT )
        pnFormats[index] |= DT_RIGHT;
    }
    v30 = nCount2_2;
    if ( nCount2_2 > index )
    {
      if ( (_DWORD)pNewChild_2->m_Current > *(_DWORD *)lpps->gap8 )
        v30 = index;
      nCount2_2 = v30;
    }
    j_1 = j;
    nCount2_1 = nCount2;
    if ( (_DWORD)pNewChild_2->m_TreeList < *(_DWORD *)&lpps->gap8[8] )
      j_1 = index;
    ++index;
  }
  pt = (LPPOINT)&pRects[nCount2_1 - 1].right;
  x_1 = pt;
  Right = pt->x;
  if ( *(_DWORD *)&lpps->gap8[8] > Right )
  {
    _mm_storeu_si128((__m128i *)&v142.nMax, _mm_loadu_si128((const __m128i *)lpps->gap8));
    v142.nMax = Right;
    v34 = GetSysColorBrush(COLOR_WINDOW);
    FillRect(lpps->hdc, (const RECT *)&v142.nMax, v34);
  }
  v35 = GetSysColor(COLOR_3DDKSHADOW);
  hPen = CreatePen(PS_SOLID, 1, v35);
  hDC_1 = lpps->hdc;
  v121 = hPen;
  hOldPen = ::SelectObject(hDC_1, hPen);
  v39 = THIS->m_Font;
  hPenOld = hOldPen;
  hOldFont = ::SelectObject(lpps->hdc, v39);
  xx = GetSystemMetrics(SM_CXSMICON);
  yy = GetSystemMetrics(SM_CYSMICON);
  pChild = CTreeList::GetCurScrollChildItem(THIS);
  pNewChild = TreeViewChildItem_GetChild(pChild, nStartLine_1);
  v42 = nStartLine_1;
  pNewChild_1 = pNewChild;
  pNewChild_2 = pNewChild;
  tmHeight = nHeight * nStartLine_1;
  nHeight_1 = nHeight;
  while ( pNewChild_1 )
  {
    if ( pNewChild_1->m_dwStyle & 1 )
    {
      if ( GetFocus() == THIS->m_hWnd )
      {
        v45 = GetSysColor(COLOR_HIGHLIGHTTEXT);
        SetTextColor(lpps->hdc, v45);
        BackColor = GetSysColor(COLOR_HIGHLIGHT);
      }
      else
      {
        v47 = GetSysColor(COLOR_WINDOWTEXT);
        SetTextColor(lpps->hdc, v47);
        BackColor = GetSysColor(COLOR_ACTIVEBORDER);
      }
    }
    else
    {
      v48 = GetSysColor(COLOR_WINDOWTEXT);
      SetTextColor(lpps->hdc, v48);
      BackColor = GetSysColor(COLOR_WINDOW);
    }
    SetBkColor(lpps->hdc, BackColor);
    SetBkMode(lpps->hdc, OPAQUE);
    nCount2_3 = nCount2_2;
    nCount2 = nCount2_2;
    if ( nCount2_2 <= j )
    {
      while ( 1 )
      {
        lprect = &pRects[nCount2_3];
        left = lprect->left;
        bottom = tmHeight + lprect->bottom;
        right = lprect->right;
        rect = left;
        v155 = bottom;
        v157 = bottom + nHeight;
        v156 = right;
        if ( nCount2 > 0 && right <= THIS->m_nBottomScrollBarWidthOrHeight || !RectInRegion(hRgn, (const RECT *)&rect) )
          goto LABEL_93;
        v54 = _mm_loadu_si128((const __m128i *)&rect);
        v55 = nCount2;
        v56 = 0;
        ho = 0;
        _mm_storeu_si128((__m128i *)&rcSrc2, v54);
        if ( v55 )
        {
          if ( v55 > 0 && rect < THIS->m_nBottomScrollBarWidthOrHeight )
          {
            rcSrc2 = THIS->m_nBottomScrollBarWidthOrHeight;
            goto LABEL_51;
          }
        }
        else
        {
          nBottomScrollBarWidthOrHeight = THIS->m_nBottomScrollBarWidthOrHeight;
          if ( v156 >= nBottomScrollBarWidthOrHeight )
          {
            v160 = nBottomScrollBarWidthOrHeight - 1;
LABEL_51:
            v56 = (HBRUSH)CreateRectRgnIndirect((const RECT *)&rcSrc2);
            ho = v56;
            SelectClipRgn(lpps->hdc, (HRGN)v56);
            goto LABEL_56;
          }
        }
        SelectClipRgn(lpps->hdc, 0);
LABEL_56:
        ::SelectObject(lpps->hdc, THIS->m_Font);
        v58 = pNewChild_2->m_dwStyle;
        v59 = pNewChild_2->m_TreeListData->vtptr;
        v115 = 4 * nCount2;
        v60 = ((int (__stdcall *)(tagTreeViewChildItem *, HDC, UINT, int, int *))v59->DrawItem)(
                pNewChild_2,
                lpps->hdc,
                pnIDsTemp[nCount2],
                v58,
                &rect);
        THIS = This;
        if ( !v60 )
        {
          v61 = GetBkColor(lpps->hdc);
          v62 = CreateSolidBrush(v61);
          v63 = lpps->hdc;
          hbr = v62;
          GetBkMode(v63);
          v64 = THIS->m_nImageWidth + rect;
          x.top = v155 + THIS->field_74;
          v65 = v156 - THIS->m_nImageWidth;
          x.left = v64;
          x.right = v65;
          x.bottom = v157;
          v66 = &This->baseclass;
          if ( !pnIDsTemp[v115 / 4] )
          {
            v67 = lpps->hdc;
            rc = 0;
            v136 = 0;
            v137 = v65 - v64;
            v138 = v157 - v155;
            v68 = CreateCompatibleBitmap(v67, v65 - v64, v157 - v155);
            v69 = lpps->hdc;
            h = v68;
            v70 = CreateCompatibleDC(v69);
            hdcDst = v70;
            ::SelectObject(v70, h);
            v71 = GetSysColorBrush(5);
            FillRect(v70, (const RECT *)&rc, v71);
            v72 = TreeViewChildItem_GetSiblingCount(pNewChild_2);
            v73 = pNewChild_2;
            v74 = (_DWORD)v66[15].vtptr * v72 + rc;
            v75 = pNewChild_2->m_dwStyle;
            rc = v74;
            v124 = v75;
            if ( v75 & 0x40 )
            {
              v139.top = v136 + (v138 - v136 - yy) / 2;
              v139.bottom = yy + v139.top;
              v139.right = v74 + xx;
              v139.left = v74;
              sub_C0BC20(v66, (int)v66[1].vtptr, hdcDst, ~(unsigned __int8)(v124 >> 4) & 1, &v139);
              v74 = rc;
              v73 = pNewChild_2;
            }
            v76 = xx + v74;
            v77 = v66[7].vtptr == 0;
            rc = v76;
            if ( v77 )
            {
              v85 = hdcDst;
            }
            else
            {
              v78 = v73->m_TreeListData;
              v124 = 0;
              i = ((int (__stdcall *)(tagTreeViewChildItem *, unsigned int *))v78->vtptr->GetItemImage)(v73, &v124);
              v80 = v124 << 8;
              v81 = v136 + (v138 - v136 - yy) / 2;
              v82 = GetSysColor(5);
              v83 = This;
              v84 = v81;
              v85 = hdcDst;
              ImageList_DrawEx(This->m_ImageList, i, hdcDst, rc, v84, xx, yy, v82, 0xFFFFFFFF, v80);
              v86 = xx + v83->m_nImageWidth;
              v76 = v86 + rc;
              rc += v86;
            }
            BitBlt(lpps->hdc, x.left, v155, v76, x.bottom, v85, 0, 0, 0xCC0020u);
            x.left += rc;
            DeleteObject(h);
            DeleteDC(v85);
          }
          v87 = v115;
          v111 = 260;
          v88 = (const WCHAR *)((int (__stdcall *)(tagTreeViewChildItem *, UINT, char *, int *))pNewChild_2->m_TreeListData->vtptr->GetItemText)(
                                 pNewChild_2,
                                 pnIDsTemp[v115 / 4],
                                 &v166,
                                 &v111);
          DrawTextW(lpps->hdc, v88, -1, &x, *(UINT *)((char *)pnFormats + v87));
          v89 = *(UINT *)((char *)pnFormats + v87) | 0x400;
          v90 = lpps->hdc;
          _mm_storeu_si128((__m128i *)&v149, _mm_loadu_si128((const __m128i *)&x));
          DrawTextW(v90, v88, -1, &v149, v89);
          if ( *((_BYTE *)pnFormats + v87) & 2 )
            OffsetRect(&v149, x.right - v149.right, 0);
          v91 = ho;
          if ( ho )
          {
            SelectClipRgn(lpps->hdc, 0);
            DeleteObject(v91);
            v92 = v149.right;
            v93 = v149.left;
            if ( v149.right > v160 )
              v92 = v160;
            v94 = rcSrc2;
            v149.right = v92;
            if ( v149.left < rcSrc2 )
              v93 = rcSrc2;
            v149.left = v93;
          }
          else
          {
            v94 = rcSrc2;
            v92 = v149.right;
            v93 = v149.left;
          }
          v151 = v159;
          v163 = v159;
          rcDst.top = v159;
          v150 = v94;
          rcDst.bottom = v149.top;
          v153 = v161;
          v164 = v160;
          v165 = v161;
          v148 = v161;
          THIS = This;
          v152 = v93;
          v162 = v92;
          rcDst.left = v93;
          rcDst.right = v92;
          v145 = v93;
          v146 = v149.bottom;
          v147 = v92;
          if ( !nCount2 )
          {
            v152 = rcSrc2 + This->m_nImageWidth;
            v95 = This->m_nBottomScrollBarWidthOrHeight - 1;
            v142.nPage = v159;
            v142.nMax = v95;
            v142.nPos = v95;
            v142.nTrackPos = v161;
            Polyline(lpps->hdc, (const POINT *)&v142.nMax, 2);
          }
          IntersectRect(&rcDst, &rcDst, (const RECT *)&rcSrc2);
          IntersectRect((LPRECT)&v145, (const RECT *)&v145, (const RECT *)&rcSrc2);
          IntersectRect((LPRECT)&v150, (const RECT *)&v150, (const RECT *)&rcSrc2);
          IntersectRect((LPRECT)&v162, (const RECT *)&v162, (const RECT *)&rcSrc2);
          v56 = hbr;
          if ( rcDst.left < rcDst.right && rcDst.top < rcDst.bottom )
            FillRect(lpps->hdc, &rcDst, hbr);
          if ( v145 < v147 && v146 < v148 )
            FillRect(lpps->hdc, (const RECT *)&v145, v56);
          if ( nCount2 )
            v96 = v56;
          else
            v96 = GetSysColorBrush(5);
          if ( v150 < v152 && v151 < v153 )
            FillRect(lpps->hdc, (const RECT *)&v150, v96);
          if ( v162 < v164 && v163 < v165 )
            FillRect(lpps->hdc, (const RECT *)&v162, v56);
LABEL_92:
          DeleteObject(v56);
          goto LABEL_93;
        }
        if ( v56 )
          goto LABEL_92;
LABEL_93:
        nCount2_3 = nCount2 + 1;
        nCount2 = nCount2_3;
        if ( nCount2_3 > j )
        {
          pNewChild_1 = pNewChild_2;
          break;
        }
      }
    }
    if ( pNewChild_1->m_Child && ((unsigned int)pNewChild_1->m_dwStyle >> 4) & 1 )
    {
      pNewChild_1 = pNewChild_1->m_Child;
LABEL_104:
      pNewChild_2 = pNewChild_1;
      goto LABEL_105;
    }
    v97 = pNewChild_1->m_Sibling;
    if ( !v97 )
    {
      v98 = pNewChild_1->m_Current;
      if ( v98 )
      {
        while ( !v98->m_Sibling )
        {
          v98 = v98->m_Current;
          if ( !v98 )
            goto LABEL_103;
        }
        pNewChild_1 = v98->m_Sibling;
      }
      else
      {
LABEL_103:
        pNewChild_1 = 0;
      }
      goto LABEL_104;
    }
    pNewChild_1 = pNewChild_1->m_Sibling;
    pNewChild_2 = v97;
LABEL_105:
    nHeight_1 = nHeight;
    v42 = nStartLine_1 + 1;
    tmHeight += nHeight;
    nStartLine_1 = v42;
    if ( v42 > v116 )
    {
      v99 = v116;
      goto LABEL_109;
    }
  }
  v99 = v42 - 1;
LABEL_109:
  v100 = pRects;
  v101 = nHeight_1 * (v99 + 1);
  if ( *(_DWORD *)&lpps->gap8[12] <= v101 + pRects->bottom - 1 )
  {
    SelectObject = (void (__stdcall *)(HDC, HGDIOBJ))::SelectObject;
  }
  else
  {
    v102 = v101 + pRects->bottom;
    _mm_storeu_si128((__m128i *)&v162, _mm_loadu_si128((const __m128i *)lpps->gap8));
    v163 = v102;
    v164 = x_1->x;
    v103 = GetSysColorBrush(COLOR_WINDOW);
    FillRect(lpps->hdc, (const RECT *)&v162, v103);
    v104 = lpps->hdc;
    v162 = THIS->m_nBottomScrollBarWidthOrHeight - 1;
    v164 = v162;
    v105 = ::SelectObject(v104, v121);
    Polyline(lpps->hdc, (const POINT *)&v162, 2);
    v106 = v105;
    SelectObject = (void (__stdcall *)(HDC, HGDIOBJ))::SelectObject;
    ::SelectObject(lpps->hdc, v106);
  }
  SelectObject(lpps->hdc, hOldFont);
  SelectObject(lpps->hdc, hPenOld);
  DeleteObject(v121);
  operator delete[](v100);
  operator delete[](pnIDsTemp);
  operator delete[](pnFormats);
}
// CA4280: using guessed type tagRECT stru_CA4280;

//----- (00C0BC20) --------------------------------------------------------
HGDIOBJ __thiscall sub_C0BC20(CThemedWindow *this, int a2, HDC hDC, char a4, LPRECT lprc)
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

  v5 = dword_CD4DA8;
  hdc = hDC;
  pThis = this;
  v23 = lprc;
  if ( !(dword_CD4DA8 & 1) )
  {
    dword_CD4DA8 |= 1u;
    v7 = GetSysColor(COLOR_3DDKSHADOW);
    ghDarkShadowPen = CreatePen(0, 1, v7);
    v5 = dword_CD4DA8;
  }
  if ( !(v5 & 2) )
  {
    dword_CD4DA8 = v5 | 2;
    ghBlackPen = GetStockObject(BLACK_PEN);
  }
  hThemeHandle = pThis->m_hThemeHandle;
  if ( hThemeHandle )
    return (HGDIOBJ)gpfnDrawThemeBackground(hThemeHandle, hDC, 2, (a4 == 0) + 1, lprc, 0);
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
// CD4DA8: using guessed type int dword_CD4DA8;

//----- (00C0BDA0) --------------------------------------------------------
char __thiscall sub_C0BDA0(CTreeList *this, char a2)
{
  char result; // al

  result = a2;
  LOBYTE(this->m_ptDownLast.y) = a2;
  return result;
}

//----- (00C0BDB0) --------------------------------------------------------
char __thiscall CTreeList::UpdateSB(CTreeList *this, char a2)
{
  char result; // al
  CTreeList *v3; // edi
  HWND v4; // esi
  SCROLLINFO v5; // [esp+4h] [ebp-20h]

  result = a2;
  v3 = this;
  this->m_bValue1 = a2;
  if ( !a2 )
  {
    CTreeList::UpdateLeftBottomSB(this, this->m_hWndScrollBarLeftBottom, 0, 1);
    v4 = v3->m_hWndScrollBarLeftBottom;
    v5.cbSize = 28;
    _mm_storeu_si128((__m128i *)&v5.nMin, (__m128i)0i64);
    v5.nTrackPos = 0;
    v5.fMask = 4;
    v5.nPos = 0;
    SetScrollInfo(v4, 2, &v5, 1);
    result = CTreeList::UpdateHeaderPos(v3, v4, 0);
  }
  return result;
}

//----- (00C0BE30) --------------------------------------------------------
UINT __thiscall CTreeList::EnsureVisible(CTreeList *this, int nItem)
{
  CTreeList *v2; // esi
  UINT bMaximized; // eax
  HWND v4; // ST04_4
  int v5; // edx
  UINT v6; // ecx
  HWND v7; // ST00_4
  SCROLLINFO v8; // [esp+4h] [ebp-3Ch]
  struct tagSCROLLINFO ScrollInfo; // [esp+20h] [ebp-20h]

  v2 = this;
  bMaximized = (unsigned int)GetWindowLongW(this->m_hWndScrollBarRightRight, GWL_STYLE) >> 28;
  if ( bMaximized & 1 )
  {
    ScrollInfo.cbSize = 28;
    v4 = v2->m_hWndScrollBarRightRight;
    ScrollInfo.nTrackPos = 0;
    _mm_storeu_si128((__m128i *)&ScrollInfo.nMin, (__m128i)0i64);
    ScrollInfo.fMask = 7;
    bMaximized = GetScrollInfo(v4, 2, &ScrollInfo);
    v5 = ScrollInfo.nPos;
    if ( nItem >= ScrollInfo.nPos )
    {
      bMaximized = ScrollInfo.nPage + ScrollInfo.nPos;
      if ( nItem < (signed int)(ScrollInfo.nPage + ScrollInfo.nPos) )
        return bMaximized;
      v6 = nItem - ScrollInfo.nPage - ScrollInfo.nPos + 1;
    }
    else
    {
      v6 = nItem - ScrollInfo.nPos;
    }
    if ( v6 )
    {
      v8.cbSize = 28;
      v8.nTrackPos = 0;
      _mm_storeu_si128((__m128i *)&v8.nMin, (__m128i)0i64);
      v8.nPos = v5 + v6;
      v7 = v2->m_hWndScrollBarRightRight;
      v8.fMask = 4;
      SetScrollInfo(v7, 2, &v8, 1);
      bMaximized = CTreeList::UpdateVScrollBars(v2, 0);
    }
  }
  return bMaximized;
}

//----- (00C0BF00) --------------------------------------------------------
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
    return (int)result;
  }
  HasChildhild = ((unsigned int)pItem->m_dwStyle >> 4) & 1;
  if ( fChild != HasChildhild )
  {
    if ( fChild )
    {
      result = (tagTreeViewChildItem *)CTreeList::SendNotify(thisIn, thisIn->m_hWnd, 0x7D1, 0, pItem, 0, 0);
      if ( !result )
      {
        pItem->m_dwStyle |= 0x30u;
        result = (tagTreeViewChildItem *)TreeViewChildItem_GetChildCount(pItem);
LABEL_9:
        nCount = (int)result;
        if ( result )
        {
          nChild = CTreeList::FindChild(this, pItem_1);
          CTreeList::RedrawZone(this, nChild, nChild);
          v7 = nCount;
          if ( !fChild )
            v7 = -nCount;
          result = (tagTreeViewChildItem *)CTreeList::SetVScrollbarPos(nChild + 1, v7);
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
      result = (tagTreeViewChildItem *)CTreeList::SendNotify(thisIn, thisIn->m_hWnd, 2002, 0, pItem, 0, 0);
      if ( !result )
      {
        result = (tagTreeViewChildItem *)TreeViewChildItem_GetChildCount(pItem);
        pItem->m_dwStyle &= -0x11u;
        goto LABEL_9;
      }
    }
  }
__quit:
  LOBYTE(result) = HasChildhild;
  return (int)result;
}

//----- (00C0BFE0) --------------------------------------------------------
signed int __thiscall CTreeList::FindChild(CTreeList *this, tagTreeViewChildItem *pChild)
{
  tagTreeViewChildItem *pChildren; // ecx
  int index; // esi
  tagTreeViewChildItem *pCurrent; // eax

  if ( !pChild )
    return -1;
  pChildren = this->m_ChildItem;
  index = 0;
  if ( !pChildren )
    return -1;
  while ( pChildren != pChild )
  {
    ++index;
    if ( pChildren->m_Child && ((unsigned int)pChildren->m_dwStyle >> 4) & 1 )
    {
      pChildren = pChildren->m_Child;
    }
    else if ( pChildren->m_Sibling )
    {
      pChildren = pChildren->m_Sibling;
    }
    else
    {
      pCurrent = pChildren->m_Current;
      if ( !pCurrent )
        return -1;
      while ( !pCurrent->m_Sibling )
      {
        pCurrent = pCurrent->m_Current;
        if ( !pCurrent )
          return -1;
      }
      pChildren = pCurrent->m_Sibling;
    }
    if ( !pChildren )
      return -1;
  }
  return index;
}

//----- (00C0C060) --------------------------------------------------------
CTreeList *__cdecl CTreeList::GetTreeList(HWND hWnd)
{
  return (CTreeList *)GetPropW(hWnd, (LPCWSTR)(unsigned __int16)gAtomTreeListProperty);
}
// CD4DA0: using guessed type __int16 gAtomTreeListProperty;

//----- (00C0C080) --------------------------------------------------------
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
  pChildren = pThis->m_ChildItem;
  hOldFont = v9;
  while ( pChildren )
  {
    v11 = pChildren->m_TreeListData;
    cbText = 0x104;
    pszText = (const WCHAR *)((int (__stdcall *)(tagTreeViewChildItem *, int, WCHAR *, int *))v11->vtptr->GetItemText)(
                               pChildren,
                               nID,
                               szText,
                               &cbText);
    nFormat = pThis->m_Format | DT_CALCRECT;
    hdc_1 = hdc;
    _mm_storeu_si128((__m128i *)&rcText, _mm_load_si128((const __m128i *)&stru_CA4290));
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
    if ( pChildren->m_Child && ((unsigned int)pChildren->m_dwStyle >> 4) & 1 )
    {
      pChildren = pChildren->m_Child;
    }
    else if ( pChildren->m_Sibling )
    {
      pChildren = pChildren->m_Sibling;
    }
    else
    {
      pCurrent = pChildren->m_Current;
      if ( pCurrent )
      {
        while ( !pCurrent->m_Sibling )
        {
          pCurrent = pCurrent->m_Current;
          if ( !pCurrent )
            goto LABEL_17;
        }
        pChildren = pCurrent->m_Sibling;
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
// CA4290: using guessed type tagRECT stru_CA4290;

//----- (00C0C210) --------------------------------------------------------
char __thiscall CTreeList::GetSubItemRect(CTreeList *THIS, int xPos, int nItem, char bFlags, char bFlags2, tagTreeViewChildItem *pChild, RECT *lprc)
{
  CTreeList *this; // ebx
  HWND v8; // ST04_4
  int v9; // eax
  HWND v10; // ST04_4
  HDC v11; // esi
  int v12; // eax
  LONG TextHeight; // ecx
  int nHeight; // esi
  LONG v15; // ecx
  tagTreeViewChildItem *v16; // eax
  signed int i; // ecx
  LONG v18; // eax
  LONG v20; // [esp+Ch] [ebp-7Ch]
  struct tagTEXTMETRICW tm; // [esp+10h] [ebp-78h]
  struct tagSCROLLINFO v22; // [esp+4Ch] [ebp-3Ch]
  struct tagSCROLLINFO v23; // [esp+68h] [ebp-20h]

  this = THIS;
  if ( nItem )
  {
    SendMessageW(THIS->m_hWndHeaderRight, HDM_GETITEMRECT, nItem - 1, (LPARAM)lprc);
    MapWindowPoints(this->m_hWndHeaderRight, this->m_hWnd, (LPPOINT)lprc, 2u);
  }
  else
  {
    SendMessageW(THIS->m_hWndHeaderLeft, HDM_GETITEMRECT, 0, (LPARAM)lprc);
    MapWindowPoints(this->m_hWndHeaderLeft, this->m_hWnd, (LPPOINT)lprc, 2u);
    v23.cbSize = 28;
    v8 = this->m_hWndScrollBarLeftBottom;
    v23.nTrackPos = 0;
    _mm_storeu_si128((__m128i *)&v23.nMin, (__m128i)0i64);
    v23.fMask = 4;
    GetScrollInfo(v8, 2, &v23);
    v9 = v23.nPos;
    lprc->left -= v23.nPos;
    lprc->right -= v9;
  }
  v22.cbSize = 28;
  v10 = this->m_hWndScrollBarRightRight;
  v22.nTrackPos = 0;
  _mm_storeu_si128((__m128i *)&v22.nMin, (__m128i)0i64);
  v22.fMask = 4;
  GetScrollInfo(v10, 2, &v22);
  v11 = GetDC(this->m_hWnd);
  SelectObject(v11, this->m_Font);
  GetTextMetricsW(v11, &tm);
  v20 = tm.tmHeight;
  ReleaseDC(this->m_hWnd, v11);
  if ( this->m_ImageList )
  {
    v12 = GetSystemMetrics(50);
    TextHeight = v20;
    if ( v20 < v12 )
      TextHeight = v12;
  }
  else
  {
    TextHeight = v20;
  }
  nHeight = TextHeight + this->m_nHeight;
  GetWindowRect(this->m_hWndHeaderLeft, (LPRECT)&v23.nMax);
  v15 = v23.nTrackPos + nHeight * (xPos - v22.nPos) - v23.nPage;
  lprc->top = v15;
  lprc->bottom = v15 + nHeight;
  if ( bFlags2 )
  {
    lprc->top = v15 + this->field_74;
    lprc->left += this->m_nImageWidth;
    lprc->right -= this->m_nImageWidth;
    if ( !nItem )
    {
      if ( pChild )
      {
        v16 = pChild->m_Current;
        for ( i = -1; v16; ++i )
          v16 = v16->m_Current;
        lprc->left += i * this->m_nChildWidth;
      }
      lprc->left += GetSystemMetrics(49);
      if ( this->m_ImageList )
        lprc->left += GetSystemMetrics(49);
      lprc->left += this->m_nImageWidth;
    }
  }
  if ( bFlags )
  {
    GetClientRect(this->m_hWnd, (LPRECT)&v23.nMax);
    v18 = this->m_nBottomScrollBarWidthOrHeight;
    if ( nItem )
    {
      if ( lprc->left < v18 )
        lprc->left = v18;
    }
    else if ( lprc->right > v18 )
    {
      lprc->right = v18;
    }
    if ( lprc->left < 0 )
      lprc->left = 0;
    if ( lprc->right > v23.nPos )
      lprc->right = v23.nPos;
    if ( lprc->left > lprc->right )
      lprc->right = lprc->left;
  }
  return 1;
}

//----- (00C0C420) --------------------------------------------------------
int __thiscall sub_C0C420(_DWORD *this)
{
  return this[1];
}

//----- (00C0C430) --------------------------------------------------------
BOOL __thiscall CTreeList::HeaderToClient(CTreeList *this, WPARAM wParam, RECT *lParam)
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
    v4 = SendMessageW(this->m_hWndHeaderRight, HDM_GETITEMRECT, wParam - 1, (LPARAM)lParam);
    v9 = lParam;
    v8 = v3->m_hWnd;
    v7 = v3->m_hWndHeaderRight;
  }
  else
  {
    v4 = SendMessageW(this->m_hWndHeaderLeft, HDM_GETITEMRECT, 0, (LPARAM)lParam);
    v9 = lParam;
    v8 = v3->m_hWnd;
    v7 = v3->m_hWndHeaderLeft;
  }
  v5 = v4;
  MapWindowPoints(v7, v8, (LPPOINT)v9, 2u);
  return v5 != 0;
}

//----- (00C0C490) --------------------------------------------------------
HWND __thiscall CTreeList::GetTooltipOfRightHeader(CTreeList *this)
{
  return this->m_hWndTooltipOfRightHeader;
}

//----- (00C0C4A0) --------------------------------------------------------
int __stdcall CListViewData::GetItemImage(tagTreeViewChildItem *pChild, PDWORD pcbRet)
{
  CListViewData *pThis; // ecx
  CTreeList *pTreeList; // edi
  CListViewData *This; // ebx
  int nItem; // esi
  UINT v6; // eax
  WPARAM v7; // ST08_4
  HWND v8; // eax
  NMLVDISPINFOW lParam; // [esp+Ch] [ebp-40h]

  pTreeList = pChild->m_TreeList;
  This = pThis;
  nItem = CTreeList::FindChild(pChild->m_TreeList, pChild);
  lParam.hdr.hwndFrom = 0;
  memset(&lParam.hdr.idFrom, 0, 0x3Cu);
  lParam.hdr.hwndFrom = pTreeList->m_hWnd;
  v6 = GetWindowLongW(pTreeList->m_hWnd, GWLP_ID);
  lParam.item.lParam = This->m_TreeItem;
  v7 = v6;
  lParam.hdr.idFrom = v6;
  lParam.hdr.code = LVN_GETDISPINFOW;
  lParam.item.mask = LVIF_STATE|LVIF_IMAGE;
  lParam.item.iItem = nItem;
  v8 = GetParent(pTreeList->m_hWnd);
  SendMessageW(v8, WM_NOTIFY, v7, (LPARAM)&lParam);
  *pcbRet = (unsigned __int16)(LOWORD(lParam.item.state) >> 8);
  return lParam.item.iImage;
}

//----- (00C0C530) --------------------------------------------------------
int __stdcall CTreeListData::GetItemImage(int a1, int a2)
{
  return 0;
}

//----- (00C0C540) --------------------------------------------------------
HIMAGELIST __thiscall CTreeList::GetImageList(CTreeList *this)
{
  return this->m_ImageList;
}

//----- (00C0C550) --------------------------------------------------------
char __thiscall CTreeList::GetItemRect(CTreeList *this, int iItem, struct tagRECT *lprc)
{
  CTreeList *This; // ebx
  HWND v4; // ST00_4
  HDC hDC; // esi
  LONG nHeight; // edi
  int v7; // eax
  int v8; // esi
  LONG v9; // eax
  struct tagTEXTMETRICW tm; // [esp+4h] [ebp-6Ch]
  struct tagRECT rw; // [esp+40h] [ebp-30h]
  struct tagSCROLLINFO ScrollInfo; // [esp+50h] [ebp-20h]

  This = this;
  ScrollInfo.cbSize = 28;
  v4 = this->m_hWndScrollBarRightRight;
  _mm_storeu_si128((__m128i *)&ScrollInfo.nMin, (__m128i)0i64);
  ScrollInfo.nTrackPos = 0;
  ScrollInfo.fMask = 4;
  GetScrollInfo(v4, 2, &ScrollInfo);
  hDC = GetDC(This->m_hWnd);
  SelectObject(hDC, This->m_Font);
  GetTextMetricsW(hDC, &tm);
  nHeight = tm.tmHeight;
  ReleaseDC(This->m_hWnd, hDC);
  if ( This->m_ImageList )
  {
    v7 = GetSystemMetrics(SM_CYSMICON);
    if ( nHeight < v7 )
      nHeight = v7;
  }
  v8 = nHeight + This->m_nHeight;
  GetClientRect(This->m_hWnd, lprc);
  GetWindowRect(This->m_hWndHeaderLeft, &rw);
  v9 = v8 * (iItem - ScrollInfo.nPos) - rw.top + rw.bottom;
  lprc->top = v9;
  lprc->bottom = v8 + v9;
  return 1;
}

//----- (00C0C630) --------------------------------------------------------
int __thiscall CTreeList::GetItemCount(CTreeList *this)
{
  tagTreeViewChildItem *pChild; // esi
  int i; // edi
  int nChildCount; // eax

  if ( !(((unsigned int)this->m_dwTreeStyle >> 4) & 1) )
    return 0;
  pChild = this->m_ChildItem;
  for ( i = this->m_nChildCount; pChild; i += nChildCount )
  {
    nChildCount = TreeViewChildItem_GetChildCount(pChild);
    pChild = pChild->m_Sibling;
  }
  return i;
}

//----- (00C0C670) --------------------------------------------------------
int __thiscall CTreeList::GetScrollInfos(CTreeList *this_, SCROLLINFO *RightScrollInfo, SCROLLINFO *BottomScrollInfo)
{
  CTreeList *v3; // edi
  LRESULT nCount; // esi
  LRESULT nStartItem; // edi
  LRESULT nEndItem; // esi
  HDC hDC; // esi
  LONG nTextHeight; // edi
  int v9; // eax
  int nLineHeight; // esi
  int nHeight; // edi
  int nChildCount; // ebx
  tagTreeViewChildItem *pChild; // esi
  int v14; // eax
  UINT nVPage; // ecx
  int bottom; // eax
  int result; // eax
  int nLineHeight_1; // [esp+Ch] [ebp-A0h]
  int nClientWidth; // [esp+14h] [ebp-98h]
  int nMaxWidth; // [esp+1Ch] [ebp-90h]
  int cyscroll; // [esp+20h] [ebp-8Ch]
  int cxscroll; // [esp+24h] [ebp-88h]
  CTreeList *this; // [esp+28h] [ebp-84h]
  struct tagTEXTMETRICW tm; // [esp+2Ch] [ebp-80h]
  int rcEndItem; // [esp+68h] [ebp-44h]
  int v26; // [esp+70h] [ebp-3Ch]
  int rcStartItem; // [esp+78h] [ebp-34h]
  struct tagRECT rcWindow; // [esp+88h] [ebp-24h]
  struct tagRECT rcClient; // [esp+98h] [ebp-14h]

  v3 = this_;
  this = this_;
  GetClientRect(this_->m_hWnd, &rcClient);
  cxscroll = GetSystemMetrics(SM_CXVSCROLL);
  cyscroll = GetSystemMetrics(SM_CYHSCROLL);
  nCount = SendMessageW(v3->m_hWndHeaderRight, HDM_GETITEMCOUNT, 0, 0);
  nStartItem = SendMessageW(v3->m_hWndHeaderRight, HDM_ORDERTOINDEX, 0, 0);
  nEndItem = SendMessageW(this->m_hWndHeaderRight, HDM_ORDERTOINDEX, nCount - 1, 0);
  SendMessageW(this->m_hWndHeaderRight, HDM_GETITEMRECT, nStartItem, (LPARAM)&rcStartItem);
  SendMessageW(this->m_hWndHeaderRight, HDM_GETITEMRECT, nEndItem, (LPARAM)&rcEndItem);
  nMaxWidth = v26 - rcStartItem;
  nClientWidth = rcClient.right - this->m_nBottomScrollBarWidthOrHeight - rcClient.left;
  hDC = GetDC(this->m_hWnd);
  SelectObject(hDC, this->m_Font);
  GetTextMetricsW(hDC, &tm);
  nTextHeight = tm.tmHeight;
  ReleaseDC(this->m_hWnd, hDC);
  if ( this->m_ImageList )
  {
    v9 = GetSystemMetrics(SM_CYSMICON);
    if ( nTextHeight < v9 )
      nTextHeight = v9;
  }
  nLineHeight = nTextHeight + this->m_nHeight;
  nLineHeight_1 = nTextHeight + this->m_nHeight;
  GetWindowRect(this->m_hWndHeaderLeft, &rcWindow);
  nHeight = rcClient.bottom + rcWindow.top - rcWindow.bottom - rcClient.top;
  if ( ((unsigned int)this->m_dwTreeStyle >> 4) & 1 )
  {
    nChildCount = this->m_nChildCount;
    for ( pChild = this->m_ChildItem; pChild; nChildCount += v14 )
    {
      v14 = TreeViewChildItem_GetChildCount(pChild);
      pChild = pChild->m_Sibling;
    }
    nLineHeight = nLineHeight_1;
  }
  else
  {
    nChildCount = 0;
  }
  nVPage = nClientWidth;
  bottom = nLineHeight * (nChildCount + 1) - 1;
  if ( nMaxWidth <= nClientWidth )
  {
    if ( bottom > nHeight )
    {
      nVPage = nClientWidth - cxscroll;
      if ( nMaxWidth > nClientWidth - cxscroll )
        goto LABEL_16;
    }
  }
  else
  {
    if ( bottom > nHeight )
    {
      nVPage = nClientWidth - cxscroll;
LABEL_16:
      nHeight -= cyscroll;
      goto LABEL_17;
    }
    nHeight -= cyscroll;
    if ( bottom > nHeight )
      nVPage = nClientWidth - cxscroll;
  }
LABEL_17:
  RightScrollInfo->nMax = bottom / nLineHeight;
  RightScrollInfo->nPage = nHeight / nLineHeight;
  RightScrollInfo->cbSize = sizeof(SCROLLINFO);
  result = nMaxWidth - 1;
  RightScrollInfo->fMask = 3;
  RightScrollInfo->nMin = 0;
  BottomScrollInfo->nPage = nVPage;
  BottomScrollInfo->cbSize = sizeof(SCROLLINFO);
  BottomScrollInfo->fMask = 3;
  BottomScrollInfo->nMin = 0;
  BottomScrollInfo->nMax = nMaxWidth - 1;
  return result;
}

//----- (00C0C8A0) --------------------------------------------------------
signed int __thiscall sub_C0C8A0(CTreeList *this, bool *a2)
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
      SendMessageW(v2->m_hWndHeaderRight, HDM_GETITEMW, v6 - 1, (LPARAM)&Item);
    else
      SendMessageW(v2->m_hWndHeaderLeft, HDM_GETITEMW, 0, (LPARAM)&Item);
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
// CDA8F8: using guessed type char gbBitmapOnRight;

//----- (00C0C980) --------------------------------------------------------
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
  v6 = (CListViewData *)v4;
  iItem = CTreeList::FindChild(pChildItem->m_TreeList, pChildItem);
  NMLVDispInfo.hdr.hwndFrom = 0;
  memset(&NMLVDispInfo.hdr.idFrom, 0, 0x3Cu);
  NMLVDispInfo.hdr.hwndFrom = pTreeList->m_hWnd;
  v8 = GetWindowLongW(pTreeList->m_hWnd, GWLP_ID);
  NMLVDispInfo.item.iSubItem = iSubItem;
  NMLVDispInfo.item.lParam = v6->m_TreeItem;
  NMLVDispInfo.item.cchTextMax = *cbSize;
  v9 = v8;
  NMLVDispInfo.hdr.idFrom = v8;
  NMLVDispInfo.hdr.code = LVN_GETDISPINFOW;
  NMLVDispInfo.item.mask = LVIF_TEXT;
  NMLVDispInfo.item.iItem = iItem;
  NMLVDispInfo.item.pszText = pszText;
  hWndParent = GetParent(pTreeList->m_hWnd);
  SendMessageW(hWndParent, WM_NOTIFY, v9, (LPARAM)&NMLVDispInfo);
  return (int)NMLVDispInfo.item.pszText;
}

//----- (00C0CA20) --------------------------------------------------------
const wchar_t *__stdcall CTreeListData::GetItemText(int a1, int a2, int a3, int a4)
{
  return L"not implemented";
}
// CA4164: using guessed type wchar_t aNotImplemented[16];

//----- (00C0CA30) --------------------------------------------------------
const wchar_t *CTreeList::GetName()
{
  return L"treeview";
}
// CA4190: using guessed type wchar_t aTreeview[9];

//----- (00C0CA40) --------------------------------------------------------
HWND __thiscall CTreeList::GetTooltipOfTreeList(CTreeList *this)
{
  return this->m_hWndTooltipOfTreeList;
}

//----- (00C0CA50) --------------------------------------------------------
int __thiscall sub_C0CA50(void *this)
{
  return *(_DWORD *)this;
}

//----- (00C0CA60) --------------------------------------------------------
int __thiscall TreeViewChildItem_GetChildCount(tagTreeViewChildItem *this)
{
  tagTreeViewChildItem *pNext; // esi
  int ret; // edi
  int nCount; // eax

  if ( !(((unsigned int)this->m_dwStyle >> 4) & 1) )
    return 0;
  pNext = this->m_Child;
  for ( ret = this->m_nCount; pNext; ret += nCount )
  {
    nCount = TreeViewChildItem_GetChildCount(pNext);
    pNext = pNext->m_Sibling;
  }
  return ret;
}

//----- (00C0CAA0) --------------------------------------------------------
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
  int v13; // eax
  WPARAM nItem; // edx
  HDC v16; // eax
  WPARAM v17; // ecx
  LONG nLineHeight; // eax
  int Format; // ebx
  HDC hDC; // eax
  HGDIOBJ v21; // eax
  HDC v22; // ebx
  void *v23; // esi
  void *dwFlags; // ecx
  HDC v25; // esi
  struct tagRECT v26; // [esp-10h] [ebp-9Ch]
  HWND v27; // [esp-Ch] [ebp-98h]
  int *v28; // [esp-8h] [ebp-94h]
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
  tagNMLVGETINFOTIPW *rcItem_1; // [esp+68h] [ebp-24h]
  __int64 v42; // [esp+6Ch] [ebp-20h]
  int v43; // [esp+74h] [ebp-18h]
  int v44; // [esp+78h] [ebp-14h]
  int v45; // [esp+7Ch] [ebp-10h]
  int v46; // [esp+80h] [ebp-Ch]
  HDC v47; // [esp+84h] [ebp-8h]

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
    v46 = (signed __int16)lParamIn;
    v47 = (HDC)SHIWORD(lParamIn);
    hWnd = (HWND)1;
    v40 = wParam;
    v28 = &v46;
    v27 = this_1->m_hWnd;
    lParam = hWndFrom;
    v39 = Msg;
    rcItem_1 = lParamIn;
    v42 = 0i64;
    v43 = 0;
    MapWindowPoints(hWndFrom, v27, (LPPOINT)&v46, 1u);
    CTreeList::PopTooltip(this_1, hWndTooltip, (POINT *)&v46);
    ::SendMessageW(hWndTooltip, TTM_RELAYEVENT, 0, (LPARAM)&lParam);
    SendMessageW = ::SendMessageW;
    uMsg = Msg;
  }
  if ( uMsg == WM_PAINT )
  {
    if ( this_1->m_pfnDrawBack )
    {
      v25 = GetDC(hWndFrom);
      GetUpdateRect(hWndFrom, (LPRECT)&rcItem_1, 0);
      _mm_storeu_si128((__m128i *)&v26, _mm_loadu_si128((const __m128i *)&rcItem_1));
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
    _mm_storeu_si128((__m128i *)&Item.cxy, (__m128i)0i64);
    lpchText = (LPCWSTR)&lParamIn->pszText;
    Item.pszText = (LPWSTR)&lParamIn->pszText;
    nItem = this_1->m_nHeaderItemCount;
    Item.cchTextMax = 80;
    _mm_storeu_si128((__m128i *)&Item.fmt, (__m128i)0i64);
    if ( nItem == -1 )
      goto LABEL_30;
    if ( hWndTooltip_1 != this_1->m_hWndTooltipOfLeftHeader )
      --nItem;
    if ( !SendMessageW(hWndFrom, HDM_GETITEMW, nItem, (LPARAM)&Item) )
      goto LABEL_30;
    v16 = (HDC)::SendMessageW(hWndFrom, HDM_GETBITMAPMARGIN, 0, 0);
    v17 = this_1->m_nHeaderItemCount;
    v47 = v16;
    if ( hWndTooltip != this_1->m_hWndTooltipOfLeftHeader )
      --v17;
    ::SendMessageW(hWndFrom, HDM_GETITEMRECT, v17, (LPARAM)&rcItem_1);
    if ( (signed int)rcItem_1 >= 0 )
    {
      rc.left = 0;
      rc.top = 0;
      HIDWORD(v42) -= 2 * (_DWORD)v47;
      rc.right = GetSystemMetrics(SM_CXVIRTUALSCREEN);
      nLineHeight = CTreeList::GetLineHeight(this_1);
      Format = this_1->m_Format;
      hWnd = this_1->m_hWnd;
      rc.bottom = nLineHeight;
      hDC = GetDC(hWnd);
      hWnd = (HWND)this_1->m_Font;
      v47 = hDC;
      v21 = SelectObject(hDC, hWnd);
      hWnd = (HWND)(Format & -0x4C001u | HDF_SORTUP);
      v22 = v47;
      v23 = v21;
      DrawTextW(v47, lpchText, -1, &rc, (UINT)hWnd);
      SelectObject(v22, v23);
      this_1 = this_2;
      ReleaseDC(this_2->m_hWnd, v22);
      dwFlags = &gszNullString;
      lParamIn_2 = lParamIn_1;
      hWndFrom_1 = hWndFrom_2;
      if ( rc.right - rc.left > HIDWORD(v42) - (signed int)rcItem_1 )
        dwFlags = (void *)lpchText;
      lParamIn_1->dwFlags = (DWORD)dwFlags;
    }
    else
    {
LABEL_30:
      lParamIn->dwFlags = (DWORD)&gszNullString;
    }
    goto LABEL_27;
  }
  if ( code != TTN_SHOW )
  {
LABEL_27:
    hWnd = (HWND)lParamIn_2;
    v28 = (int *)wParam;
    v27 = (HWND)Msg;
    v26.left = (LONG)hWndFrom_1;
    return CallWindowProcW((WNDPROC)this_1->m_HeaderWndProc, hWndFrom_1, Msg, wParam, (LPARAM)lParamIn_2);
  }
  v12 = this_1->m_nHeaderItemCount;
  if ( hWndTooltip != this_1->m_hWndTooltipOfLeftHeader )
    --v12;
  SendMessageW(hWndFrom, HDM_GETITEMRECT, v12, (LPARAM)&v44);
  MapWindowPoints(hWndFrom, 0, (LPPOINT)&v44, 2u);
  v13 = (int)v47 + v44 - v45;
  v45 = (int)v47 + (_DWORD)v47 - v45;
  v44 = v13;
  SetWindowPos(hWndTooltip, 0, v13, v45, 0, 0, SWP_NOACTIVATE|SWP_NOZORDER|SWP_NOSIZE);
  ::SendMessageW(hWndTooltip, WM_SETFONT, (WPARAM)this_1->m_Font, 0);
  return 1;
}

//----- (00C0CDB0) --------------------------------------------------------
signed int __thiscall CTreeList::HitTest(CTreeList *this, LONG xPos, LONG yPos, int *pnItem, int *pnSubItem, tagTreeViewChildItem **ppChild)
{
  CTreeList *pThis; // ebx
  signed int result; // eax
  int xOffset; // edi
  WPARAM nIndex; // esi
  int nScrollPos; // esi
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
  struct tagRECT rcTreeList; // [esp+20h] [ebp-24h]
  struct tagRECT rwHeaderLeft; // [esp+30h] [ebp-14h]

  pThis = this;
  GetClientRect(this->m_hWnd, &rcTreeList);
  if ( pnItem )
    *pnItem = -1;
  if ( pnSubItem )
    *pnSubItem = -1;
  if ( ppChild )
    *ppChild = 0;
  if ( xPos < rcTreeList.left )
    return HTGROWBOX;
  if ( xPos >= rcTreeList.right )
    return HTMINBUTTON;
  if ( yPos < rcTreeList.top )
    return HTCLIENT;
  if ( yPos >= rcTreeList.bottom )
    return HTCAPTION;
  xOffset = 0;
  nItem = -1;
  nIndex = 0;
  nRightHeaderItemCount = SendMessageW(pThis->m_hWndHeaderRight, HDM_GETITEMCOUNT, 0, 0) + 1;
  if ( nRightHeaderItemCount > 0 )
  {
    while ( 1 )
    {
      CTreeList::HeaderToClient(pThis, nIndex, &rwHeaderLeft);
      if ( xPos >= rwHeaderLeft.left && xPos < rwHeaderLeft.right )
        break;
      if ( (signed int)++nIndex >= nRightHeaderItemCount )
        goto LABEL_22;
    }
    nItem = nIndex;
    xOffset = xPos - rwHeaderLeft.left;
    if ( pnSubItem )
      *pnSubItem = nIndex;
  }
LABEL_22:
  GetWindowRect(pThis->m_hWndHeaderLeft, &rwHeaderLeft);
  nLeftHeaderHeight = rwHeaderLeft.bottom - rwHeaderLeft.top;
  if ( yPos < rwHeaderLeft.bottom - rwHeaderLeft.top )
    return 0x200;
  pChild = CTreeList::GetCurScrollChildItem(pThis);
  if ( !pChild )
    return HTBOTTOMLEFT;
  nScrollPos = CTreeList::GetRightScrollbarPos(pThis);
  bottom = nScrollPos + (yPos - nLeftHeaderHeight) / CTreeList::GetLineHeight(pThis);
  pNewChild = TreeViewChildItem_GetChild(pChild, bottom - nScrollPos);
  if ( !pNewChild )
    return HTBOTTOMLEFT;
  if ( pnItem )
    *pnItem = bottom;
  if ( ppChild )
    *ppChild = pNewChild;
  if ( nItem )
    return 0x80;
  nLeft = xOffset - pThis->m_nChildWidth * TreeViewChildItem_GetSiblingCount(pNewChild);
  if ( nLeft < 0 )
    return 0x100;
  v13 = GetSystemMetrics(SM_CXSMICON);
  nLeft_1 = nLeft - v13;
  if ( nLeft_1 < 0 )
  {
    result = 0x100;
    if ( ((unsigned int)pNewChild->m_dwStyle >> 6) & 1 )
      result = 64;
    return result;
  }
  if ( !pThis->m_ImageList )
    return 0x80;
  v15 = nLeft_1 - v13;
  result = 32;
  if ( v15 >= 0 )
    return 0x80;
  return result;
}

//----- (00C0D000) --------------------------------------------------------
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
  int v12; // ecx
  struct tagRECT *v13; // eax
  int v14; // eax
  int v15; // ecx
  int v16; // edx
  HWND *v17; // [esp+Ch] [ebp-5Ch]
  int *v18; // [esp+10h] [ebp-58h]
  int v19; // [esp+14h] [ebp-54h]
  LONG v20; // [esp+14h] [ebp-54h]
  SCROLLINFO v21; // [esp+18h] [ebp-50h]
  struct tagRECT v22; // [esp+34h] [ebp-34h]
  struct tagRECT Rect; // [esp+44h] [ebp-24h]
  int prcScroll; // [esp+54h] [ebp-14h]
  int v25; // [esp+58h] [ebp-10h]
  LONG v26; // [esp+5Ch] [ebp-Ch]
  int v27; // [esp+60h] [ebp-8h]

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
  bVisible = (unsigned int)GetWindowLongW(hWnd, -16) >> 28;
  if ( bVisible & 1 )
  {
    v8 = (void (__stdcall *)(HWND, int, LPSCROLLINFO))GetScrollInfo;
    v21.cbSize = 28;
    _mm_storeu_si128((__m128i *)&v21.nMin, (__m128i)0i64);
    v21.nTrackPos = 0;
    v21.fMask = 4;
    if ( a3 )
    {
      GetScrollInfo(hWnd, 2, &v21);
      v21.nPos += a3;
      SetScrollInfo(hWnd, 2, &v21, 1);
      v8 = (void (__stdcall *)(HWND, int, LPSCROLLINFO))GetScrollInfo;
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
        prcScroll = v10;
        GetWindowRect(v3->m_hWndHeaderLeft, &v22);
        v25 = v22.bottom - v22.top;
        v26 = Rect.right - v9;
        v27 = Rect.bottom - GetSystemMetrics(3);
        if ( hWnd == v3->m_hWndScrollBarRightBottom
          && ((unsigned int)GetWindowLongW(v3->m_hWndScrollBarRightRight, -16) >> 28) & 1 )
        {
          v14 = GetSystemMetrics(2);
          v15 = v26 - v14;
          v26 -= v14;
        }
        else
        {
          v15 = v26;
        }
        if ( v15 > prcScroll )
        {
          ScrollWindowEx(v3->m_hWnd, v9, 0, (const RECT *)&prcScroll, 0, 0, 0, 2u);
          v16 = prcScroll;
          bVisible = v26 - prcScroll;
          if ( v9 <= v26 - prcScroll )
            goto LABEL_29;
          prcScroll = v26;
          v26 = v16 + v9;
          v13 = (struct tagRECT *)&prcScroll;
LABEL_28:
          bVisible = InvalidateRect(v3->m_hWnd, v13, 0);
LABEL_29:
          if ( hWnd == v3->m_hWndScrollBarRightBottom )
          {
            GetWindowRect(*v17, (LPRECT)&prcScroll);
            MapWindowPoints(0, v3->m_hWnd, (LPPOINT)&prcScroll, 2u);
            bVisible = SetWindowPos(*v17, 0, v9 + prcScroll, v25, v26 - (v9 + prcScroll), v27 - v25, SWP_NOZORDER);
          }
          return bVisible;
        }
      }
      else
      {
        prcScroll = v10 - v9;
        GetWindowRect(v3->m_hWndHeaderLeft, &v22);
        v25 = v22.bottom - v22.top;
        v26 = Rect.right;
        v27 = Rect.bottom - GetSystemMetrics(3);
        if ( hWnd == v3->m_hWndScrollBarRightBottom
          && ((unsigned int)GetWindowLongW(v3->m_hWndScrollBarRightRight, -16) >> 28) & 1 )
        {
          v11 = GetSystemMetrics(2);
          v12 = v26 - v11;
          v26 -= v11;
        }
        else
        {
          v12 = v26;
        }
        if ( v12 > prcScroll )
        {
          ScrollWindowEx(v3->m_hWnd, v9, 0, (const RECT *)&prcScroll, 0, 0, 0, 2u);
          v20 = prcScroll;
          bVisible = -v9;
          if ( -v9 <= v26 - prcScroll )
            goto LABEL_29;
          prcScroll = v26 + v9;
          v26 = v20;
          v13 = (struct tagRECT *)&prcScroll;
          goto LABEL_28;
        }
      }
      v13 = &Rect;
      goto LABEL_28;
    }
  }
  return bVisible;
}

//----- (00C0D2A0) --------------------------------------------------------
int __thiscall CTreeList::SetHScrollPos(CTreeList *this, HWND hwnd, int a3)
{
  CTreeList *v3; // edi
  SCROLLINFO v5; // [esp+0h] [ebp-20h]

  _mm_storeu_si128((__m128i *)&v5.nMin, (__m128i)0i64);
  v5.nPos = a3;
  v3 = this;
  v5.cbSize = 28;
  v5.nTrackPos = 0;
  v5.fMask = 4;
  SetScrollInfo(hwnd, 2, &v5, 1);
  return CTreeList::UpdateHeaderPos(v3, hwnd, 0);
}

//----- (00C0D310) --------------------------------------------------------
void __thiscall sub_C0D310(CTreeList *this, int nStart, int nCount)
{
  int index; // esi
  CTreeList *i; // ebx
  int v5; // edi
  int v6; // ST04_4
  int v7; // eax
  bool v8; // zf
  int v9; // eax
  HDITEMW item; // [esp+8h] [ebp-2Ch]

  index = 0;
  for ( i = this; index < nCount; ++index )
  {
    v5 = nStart + 12 * index;
    item.mask = 7;
    v6 = *(_DWORD *)(v5 + 4);
    item.pszText = *(LPWSTR *)v5;
    v7 = MulDiv(v6, gLogPixelSize.x, 96);
    v8 = *(_BYTE *)(v5 + 8) == 0;
    item.cxy = v7;
    v9 = 0x4000;
    if ( !v8 )
      v9 = 0x4001;
    item.fmt = v9;
    if ( index )
    {
      SendMessageW(i->m_hWndHeaderRight, HDM_INSERTITEMW, index - 1, (LPARAM)&item);
    }
    else
    {
      SendMessageW(i->m_hWndHeaderLeft, HDM_INSERTITEMW, 0, (LPARAM)&item);
      CTreeList::MoveHeaders(i, item.cxy);
    }
  }
}

//----- (00C0D3B0) --------------------------------------------------------
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
  SetPropW(v1->m_hWnd, (LPCWSTR)(unsigned __int16)gAtomTreeListProperty, v1);
  v2 = v1->m_hWnd;
  if ( v1->baseclass.m_hThemeHandle )
    gpfnCloseThemeData(v1->baseclass.m_hThemeHandle);
  v1->baseclass.m_hThemeHandle = 0;
  if ( gpfnIsThemeActive && gpfnIsThemeActive() )
  {
    v3 = ((int (__thiscall *)(CTreeList *))v1->baseclass.vtptr->GetName)(v1);
    v1->baseclass.m_hThemeHandle = (HTHEME)gpfnOpenThemeData(v2, v3);
  }
  v4 = CreateWindowExW(
         0,
         L"SysHeader32",
         (LPCWSTR)&gszNullString,
         0x44000082u,
         0,
         0,
         0,
         0,
         v1->m_hWnd,
         (HMENU)IDC_HEADERCTRL_1_IN_TREELIST,
         hInstance,
         0);
  v1->m_hWndHeaderLeft = v4;
  SetPropW(v4, (LPCWSTR)(unsigned __int16)gAtomTreeListProperty, v1);
  v5 = SetWindowLongW(v1->m_hWndHeaderLeft, -4, (LONG)CTreeList::Proxy_HeaderWndProc);
  v6 = hInstance;
  v1->m_HeaderWndProc = v5;
  hWndHeader = CreateWindowExW(
                 0,
                 L"SysHeader32",
                 (LPCWSTR)&gszNullString,
                 0x440000C2u,
                 0,
                 0,
                 0,
                 0,
                 v1->m_hWnd,
                 (HMENU)IDC_HEADERCTRL_2_IN_TREELIST,
                 v6,
                 0);
  v1->m_hWndHeaderRight = hWndHeader;
  SetPropW(hWndHeader, (LPCWSTR)(unsigned __int16)gAtomTreeListProperty, v1);
  SetWindowLongW(v1->m_hWndHeaderRight, -4, (LONG)CTreeList::Proxy_HeaderWndProc);
  v8 = CreateWindowExW(
         0,
         L"ScrollBar",
         (LPCWSTR)&gszNullString,
         0x44000005u,
         0,
         0,
         0,
         0,
         v1->m_hWnd,
         (HMENU)IDC_SCROLLBAR_1_IN_TREELIST,
         hInstance,
         0);
  v9 = hInstance;
  v1->m_hWndScrollBarRightRight = v8;
  v10 = CreateWindowExW(
          0,
          L"ScrollBar",
          (LPCWSTR)&gszNullString,
          0x44000004u,
          0,
          0,
          0,
          0,
          v1->m_hWnd,
          (HMENU)IDC_SCROLLBAR_2_IN_TREELIST,
          v9,
          0);
  v11 = hInstance;
  v1->m_hWndScrollBarLeftBottom = v10;
  v12 = CreateWindowExW(
          0,
          L"ScrollBar",
          (LPCWSTR)&gszNullString,
          0x44000004u,
          0,
          0,
          0,
          0,
          v1->m_hWnd,
          (HMENU)IDC_SCROLLBAR_3_IN_TREELIST,
          v11,
          0);
  v13 = hInstance;
  v1->m_hWndScrollBarRightBottom = v12;
  v1->m_hWndStatic = CreateWindowExW(
                       0,
                       L"Static",
                       (LPCWSTR)&gszNullString,
                       0x44000000u,
                       0,
                       0,
                       0,
                       0,
                       v1->m_hWnd,
                       (HMENU)IDC_STATIC_IN_TREELIST,
                       v13,
                       0);
  picce.dwSize = 8;
  picce.dwICC = 4;
  InitCommonControlsEx(&picce);
  v14 = hInstance;
  v15 = CTreeList::CreateTooltips(hInstance, v1->m_hWnd);
  v1->m_hWndTooltipOfTreeList = v15;
  SetPropW(v15, (LPCWSTR)(unsigned __int16)gAtomTreeListProperty, v1);
  v16 = SetWindowLongW(v1->m_hWndTooltipOfTreeList, -4, (LONG)CTreeList::Proxy_TooltipWndProc);
  v17 = v1->m_hWnd;
  v1->m_TooltipWndProc = v16;
  SetTimer(v17, 100u, 500u, 0);
  v18 = CTreeList::CreateTooltips(v14, v1->m_hWndHeaderLeft);
  v19 = v1->m_hWndHeaderRight;
  v1->m_hWndTooltipOfLeftHeader = v18;
  v1->m_hWndTooltipOfRightHeader = CTreeList::CreateTooltips(v14, v19);
  v20 = GetStockObject(17);
  SendMessageW(v1->m_hWnd, WM_SETFONT, (WPARAM)v20, 0);
  v21 = LoadCursorW(v14, L"SPLITTER_CURSOR");
  v22 = v1->m_hWnd;
  v1->m_hCursor = v21;
  v1->m_dwTreeStyle = 16;
  InvalidateRect(v22, 0, 1);
  return 1;
}
// CD4D84: using guessed type int (__stdcall *gpfnIsThemeActive)();
// CD4DA0: using guessed type __int16 gAtomTreeListProperty;

//----- (00C0D640) --------------------------------------------------------
int *__thiscall TreeViewChildItem_Init(tagTreeViewChildItem *pThis, CTreeList *pTreeList, CListViewData *pListViewData, int (__cdecl *pfnCallback)(int, _DWORD, int, _DWORD), int nItem)
{
  tagTreeViewChildItem *this; // ebx
  tagTreeViewChildItem *pNew; // eax
  int *pNewItem; // esi
  _DWORD *ppChild; // eax
  int *result; // eax
  int (__cdecl *pfnCb)(int, _DWORD, int, _DWORD); // edx
  _DWORD *pChild; // edi
  CTreeList *v12; // ecx
  CTreeList *v13; // eax
  int v14; // eax
  _DWORD *ppChild2; // [esp+8h] [ebp-4h]
  CTreeList *a2a; // [esp+14h] [ebp+8h]

  this = pThis;
  pNew = (tagTreeViewChildItem *)operator new(0x28u);
  pNewItem = (int *)pNew;
  if ( pNew )
  {
    pNew->m_TreeList = pTreeList;
    pNew->m_TreeListData = (CTreeListData *)pListViewData;
    pNew->m_Current = this;
    pNew->m_Child = 0;
    pNew->m_Item18 = 0;
    pNew->m_nCount = 0;
    pNew->m_dwStyle = 0;
    pNew->m_dwReserved = 0;
  }
  else
  {
    pNewItem = 0;
  }
  this->m_dwStyle |= 0x40u;
  ppChild = &this->m_Child;
  ++this->m_nCount;
  ppChild2 = &this->m_Child;
  if ( !this->m_Child )
  {
    this->m_Item18 = (tagTreeViewChildItem *)pNewItem;
    *ppChild = pNewItem;
    result = pNewItem;
    pNewItem[4] = 0;
    pNewItem[3] = 0;
    return result;
  }
  pfnCb = pfnCallback;
  if ( pfnCallback )
  {
    pChild = (_DWORD *)*ppChild;
    v12 = 0;
    a2a = 0;
    do
    {
      if ( pfnCb == (int (__cdecl *)(int, _DWORD, int, _DWORD))1 )
      {
        v13 = v12;
        v12 = (CTreeList *)((char *)v12 + 1);
        a2a = v12;
        if ( v13 == (CTreeList *)nItem )
          goto LABEL_10;
      }
      else
      {
        if ( pfnCb((int)pListViewData, pChild[1], nItem, 0) < 0 )
        {
LABEL_10:
          *ppChild2 = pNewItem;
          pNewItem[3] = pChild[3];
          result = pNewItem;
          pNewItem[4] = (int)pChild;
          pChild[3] = pNewItem;
          return result;
        }
        v12 = a2a;
        pfnCb = pfnCallback;
      }
      v14 = (int)(pChild + 4);
      pChild = (_DWORD *)pChild[4];
      ppChild2 = (_DWORD *)v14;
    }
    while ( pChild );
  }
  this->m_Item18->m_Sibling = (tagTreeViewChildItem *)pNewItem;
  pNewItem[3] = (int)this->m_Item18;
  result = pNewItem;
  pNewItem[4] = 0;
  this->m_Item18 = (tagTreeViewChildItem *)pNewItem;
  return result;
}

//----- (00C0D750) --------------------------------------------------------
char __thiscall CTreeList::InsertColumn(CTreeList *this, tagTVLSCOLUMNW *pColumnInfo, int nColumn)
{
  WCHAR *v3; // eax
  CTreeList *v4; // edi
  int v5; // ST04_4
  int v6; // eax
  bool v7; // zf
  int v8; // eax
  HDITEMW hditem; // [esp+8h] [ebp-2Ch]

  v3 = pColumnInfo->pszText;
  v4 = this;
  v5 = pColumnInfo->cchTextMax;
  hditem.mask = 7;
  hditem.pszText = v3;
  v6 = MulDiv(v5, gLogPixelSize.x, 96);
  v7 = pColumnInfo->fmt == 0;
  hditem.cxy = v6;
  v8 = HDF_STRING;
  if ( !v7 )
    v8 = 0x4001;
  hditem.fmt = v8;
  if ( nColumn )
  {
    SendMessageW(v4->m_hWndHeaderRight, HDM_INSERTITEMW, nColumn - 1, (LPARAM)&hditem);
  }
  else
  {
    SendMessageW(v4->m_hWndHeaderLeft, HDM_INSERTITEMW, 0, (LPARAM)&hditem);
    CTreeList::MoveHeaders(v4, hditem.cxy);
  }
  return 1;
}

//----- (00C0D7E0) --------------------------------------------------------
tagTreeViewChildItem *__thiscall CTreeList::_InsertItem(CTreeList *this, int wParam, CListViewData *pListViewData, int (__cdecl *pfnCallback)(int, _DWORD, int, _DWORD), int nItem)
{
  tagTreeViewChildItem *pChild; // esi
  CTreeList *v6; // edi
  tagTreeViewChildItem *v7; // eax
  tagTreeViewChildItem *pNew; // ebx
  int v9; // eax

  pChild = (tagTreeViewChildItem *)wParam;
  v6 = this;
  if ( !wParam )
    pChild = (tagTreeViewChildItem *)&this->m_Item_40;
  v7 = (tagTreeViewChildItem *)TreeViewChildItem_Init(pChild, this, pListViewData, pfnCallback, nItem);
  pNew = v7;
  if ( pChild->m_dwStyle & TVLS_HASCHILD )
  {
    v9 = CTreeList::FindChild(v6, v7);
    CTreeList::SetVScrollbarPos(v9, 1);
  }
  return pNew;
}

//----- (00C0D830) --------------------------------------------------------
int __stdcall CTreeList::SetVScrollbarPos(int yPos, int bRefresh)
{
  CTreeList *v2; // ecx
  CTreeList *this; // edi
  HWND m_hWndScrollBarRightRight; // ST14_4
  int nLineHeight; // esi
  int nLineHeight1; // ebx
  int bottom; // ecx
  HWND v8; // ST00_4
  HWND m_hWnd; // ST00_4
  int result; // eax
  struct tagSCROLLINFO ScrollInfo; // [esp+4h] [ebp-40h]
  struct tagRECT rcClient; // [esp+20h] [ebp-24h]
  LONG rwHeaderLeft; // [esp+30h] [ebp-14h]
  int v14; // [esp+34h] [ebp-10h]
  LONG v15; // [esp+38h] [ebp-Ch]
  LONG v16; // [esp+3Ch] [ebp-8h]

  this = v2;
  if ( bRefresh && !v2->m_bSkipTimerForTooltip )
  {
    ScrollInfo.cbSize = 28;
    m_hWndScrollBarRightRight = v2->m_hWndScrollBarRightRight;
    ScrollInfo.nTrackPos = 0;
    _mm_storeu_si128((__m128i *)&ScrollInfo.nMin, (__m128i)0i64);
    ScrollInfo.fMask = 4;
    GetScrollInfo(m_hWndScrollBarRightRight, 2, &ScrollInfo);
    nLineHeight = CTreeList::GetLineHeight(this);
    GetClientRect(this->m_hWnd, &rcClient);
    nLineHeight1 = bRefresh * nLineHeight;
    GetWindowRect(this->m_hWndHeaderLeft, (LPRECT)&rwHeaderLeft);
    rwHeaderLeft = rcClient.left;
    v15 = rcClient.right;
    bottom = v16 + nLineHeight * (yPos - ScrollInfo.nPos) - v14;
    if ( bRefresh < 0 )
    {
      v16 = rcClient.bottom;
      if ( bottom - nLineHeight1 < rcClient.bottom )
      {
        m_hWnd = this->m_hWnd;
        v14 = bottom - nLineHeight1;
        ScrollWindowEx(m_hWnd, 0, nLineHeight1, (const RECT *)&rwHeaderLeft, 0, 0, 0, SW_INVALIDATE);
        v14 = nLineHeight1 + rcClient.bottom;
      }
      else
      {
        v14 = bottom;
      }
      InvalidateRect(this->m_hWnd, (const RECT *)&rwHeaderLeft, 0);
    }
    else
    {
      v16 = rcClient.bottom;
      v8 = this->m_hWnd;
      v14 = bottom;
      ScrollWindowEx(v8, 0, nLineHeight1, (const RECT *)&rwHeaderLeft, 0, 0, 0, SW_INVALIDATE);
    }
    if ( this->m_bValue1 )
    {
      this->m_nChildWidthLast = CTreeList::GetChildWidth(this, 0);
      CTreeList::RepositionHeaders();
    }
    result = CTreeList::Resize(this);
  }
  return result;
}

//----- (00C0D980) --------------------------------------------------------
bool __thiscall CTreeList::IsItemVisible(CTreeList *this, int a2)
{
  CTreeList *pThis; // ebx
  HWND hWnd; // ST00_4
  HDC hDC; // esi
  LONG nFontHeight; // edi
  int cy; // eax
  int nHeight; // esi
  struct tagTEXTMETRICW tm; // [esp+Ch] [ebp-7Ch]
  struct tagRECT rcClient; // [esp+48h] [ebp-40h]
  struct tagRECT rwHeaderLeft; // [esp+58h] [ebp-30h]
  struct tagSCROLLINFO ScrollInfo; // [esp+68h] [ebp-20h]

  ScrollInfo.cbSize = 28;
  pThis = this;
  ScrollInfo.nTrackPos = 0;
  ScrollInfo.fMask = 4;
  hWnd = this->m_hWndScrollBarRightRight;
  _mm_storeu_si128((__m128i *)&ScrollInfo.nMin, (__m128i)0i64);
  GetScrollInfo(hWnd, 2, &ScrollInfo);
  hDC = GetDC(pThis->m_hWnd);
  SelectObject(hDC, pThis->m_Font);
  GetTextMetricsW(hDC, &tm);
  nFontHeight = tm.tmHeight;
  ReleaseDC(pThis->m_hWnd, hDC);
  if ( pThis->m_ImageList )
  {
    cy = GetSystemMetrics(SM_CYSMICON);
    if ( nFontHeight < cy )
      nFontHeight = cy;
  }
  nHeight = nFontHeight + pThis->m_nHeight;
  GetWindowRect(pThis->m_hWndHeaderLeft, &rwHeaderLeft);
  GetClientRect(pThis->m_hWnd, &rcClient);
  return a2 >= ScrollInfo.nPos
      && a2 <= ScrollInfo.nPos + (rcClient.bottom + rwHeaderLeft.top - rwHeaderLeft.bottom) / nHeight;
}

//----- (00C0DA70) --------------------------------------------------------
tagTreeViewChildItem *__thiscall TreeViewChildItem_GetChild(tagTreeViewChildItem *pItem, int nPosIn)
{
  int nPos; // esi
  tagTreeViewChildItem *pNode; // eax
  tagTreeViewChildItem *p; // edx
  tagTreeViewChildItem *pCurrent; // ecx

  if ( !pItem )
    return 0;
  nPos = nPosIn;
  while ( nPos < 0 )
  {
    pNode = pItem->m_Item0C;
    if ( pNode )
    {
      pItem = pItem->m_Item0C;
      for ( p = pNode->m_Item18; p; p = p->m_Item18 )
      {
        if ( !(((unsigned int)pItem->m_dwStyle >> 4) & 1) )
          break;
        pItem = p;
      }
    }
    else
    {
      pItem = pItem->m_Current;
      if ( pItem && !pItem->m_TreeListData )
        return 0;
    }
    ++nPos;
    if ( !pItem )
      return 0;
  }
  for ( ; pItem; --nPos )
  {
    if ( nPos <= 0 )
      break;
    if ( pItem->m_Child && ((unsigned int)pItem->m_dwStyle >> 4) & 1 )
    {
      pItem = pItem->m_Child;
    }
    else if ( pItem->m_Sibling )
    {
      pItem = pItem->m_Sibling;
    }
    else
    {
      pCurrent = pItem->m_Current;
      if ( pCurrent )
      {
        while ( !pCurrent->m_Sibling )
        {
          pCurrent = pCurrent->m_Current;
          if ( !pCurrent )
            goto LABEL_24;
        }
        pItem = pCurrent->m_Sibling;
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

//----- (00C0DB30) --------------------------------------------------------
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

//----- (00C0DBA0) --------------------------------------------------------
int __cdecl pfnCallback(CListViewData *pListViewData, int a2, int a3)
{
  return ((int (__cdecl *)(tagTREEVIEWLISTITEMPARAM *, _DWORD))a3)(pListViewData->m_TreeItem, *(_DWORD *)(a2 + 4));
}

//----- (00C0DBC0) --------------------------------------------------------
int __cdecl CTreeList::SortCallback(int a1, int a2, int arg8, int a4)
{
  return ((int (__stdcall *)(_DWORD, _DWORD, int))arg8)(*(_DWORD *)(a1 + 4), *(_DWORD *)(a2 + 4), a4);
}

//----- (00C0DBE0) --------------------------------------------------------
HWND __thiscall CTreeList::HandleListViewMsg(CTreeList *this, HWND hWnd, UINT Msg, WPARAM wParam, UINT *pnIDs)
{
  CTreeList *pThis; // ebx
  HWND result; // eax
  int v7; // ST0C_4
  bool bNoText; // zf
  int v9; // eax
  LRESULT bRet; // eax
  UINT v11; // ecx
  UINT v12; // ecx
  UINT fMask; // edx
  UINT dwMask_1; // ecx
  int v15; // eax
  UINT dwFormat; // eax
  unsigned __int32 fRight; // edx
  __int32 bRight; // edx
  int v19; // edx
  WCHAR *v20; // eax
  int v21; // eax
  signed int dwIndex; // eax
  __m128i dwValue1; // xmm1
  UINT *dwValue2; // ecx
  __m128i dwValue3; // xmm0
  LRESULT nLeftColumnCount; // esi
  int nColumnCount; // eax
  signed int nColumn; // esi
  int nIndex; // ecx
  int nLeftColumn; // edx
  int v31; // edx
  __m128i temp; // xmm1
  const __m128i *pnIDsTemp; // eax
  __m128i v34; // xmm0
  CListViewData *pListViewData; // eax
  tagTREEVIEWLISTITEMPARAM *v36; // ecx
  tagTreeViewChildItem *v37; // eax
  tagTreeViewChildItem *pItem; // eax
  tagTreeViewChildItem *v39; // eax
  const wchar_t *v40; // eax
  wchar_t *v41; // ecx
  int iItem; // ST14_4
  tagTreeViewChildItem *m_ChildItem; // ecx
  tagTreeViewChildItem *pNewChild; // eax
  tagTreeViewChildItem *v45; // esi
  char v46; // bl
  CTreeListData *v47; // ecx
  UINT v48; // ST10_4
  CTreeListData *v49; // ecx
  tagTreeViewChildItem *pChild; // ecx
  WPARAM nFound; // esi
  UINT Flags; // ebx
  tagTreeViewChildItem *pChildItem; // ecx
  tagTreeViewChildItem *pNewSorted; // eax
  tagTreeViewChildItem *v55; // eax
  tagTreeViewChildItem *v56; // edx
  tagTreeViewChildItem *i; // ecx
  tagTreeViewChildItem *pItem_1; // eax
  int v59; // ST14_4
  tagTreeViewChildItem *v60; // ecx
  tagTreeViewChildItem *pNewChild_1; // eax
  char v62; // dl
  MACRO_LVIF hditem; // [esp+Ch] [ebp-4Ch]
  WPARAM v64; // [esp+10h] [ebp-48h]
  HDITEMW hditem_1; // [esp+14h] [ebp-44h]
  __int64 v66; // [esp+38h] [ebp-20h]
  int wParamIn; // [esp+40h] [ebp-18h]
  RECT rc; // [esp+44h] [ebp-14h]

  pThis = this;
  wParamIn = wParam;
  switch ( Msg )
  {
    case LVM_GETITEMCOUNT:
      return (HWND)CTreeList::GetItemCount(this);
    case LVM_DELETEITEM:
      if ( !this->m_nChildCount )
        return 0;
      pItem = TreeViewChildItem_GetChild(this->m_ChildItem, wParam);
      if ( !pItem )
        return 0;
      CTreeList::RemoveItem(pThis, pItem);
      return (HWND)1;
    case LVM_DELETEALLITEMS:
      CTreeList::OnDestroy(this);
      return (HWND)1;
    case LVM_GETNEXTITEM:
      if ( !this->m_nChildCount )
        return HWND_MESSAGE|0x2;
      nFound = wParam + 1;
      pItem_1 = TreeViewChildItem_GetChild(this->m_ChildItem, wParam + 1);
      if ( pnIDs != (UINT *)LVFI_STRING || !pItem_1 )
        return HWND_MESSAGE|0x2;
      while ( !(pItem_1->m_dwStyle & 1) )
      {
        pItem_1 = TreeViewChildItem_GetNextChild(pItem_1);
        ++nFound;
        if ( !pItem_1 )
          return HWND_MESSAGE|0x2;
      }
      return (HWND)nFound;
    case LVM_GETITEMRECT:
      if ( *pnIDs )
        return 0;
      CTreeList::GetItemRect(this, wParam, (struct tagRECT *)pnIDs);
      return (HWND)1;
    case LVM_HITTEST:
      if ( !(CTreeList::HitTest(this, *pnIDs, pnIDs[1], (int *)pnIDs + 3, (int *)pnIDs + 4, 0) & 0xE0) )
        return HWND_MESSAGE|0x2;
      return (HWND)pnIDs[3];
    case LVM_ENSUREVISIBLE:
      CTreeList::EnsureVisible(this, wParam);
      return (HWND)1;
    case LVM_REDRAWITEMS:
      CTreeList::RedrawZone(this, wParam, (int)pnIDs);
      return (HWND)1;
    case LVM_DELETECOLUMN:
      return (HWND)CTreeList::DeleteColumn(this, wParam);
    case LVM_GETCOLUMNWIDTH:
      if ( !(unsigned __int8)CTreeList::HeaderToClient(this, wParam, &rc) )
        return 0;
      return (HWND)(rc.right - rc.left);
    case LVM_GETHEADER:
      return this->m_hWndHeaderLeft;
    case LVM_SETITEMSTATE:
      hditem_1.pszText = (LPWSTR)pnIDs[4];
      hditem_1.cxy = pnIDs[3];
      hditem = LVIF_STATE;
      v64 = wParam;
      hditem_1.mask = 0;
      return CTreeList::HandleListViewMsg(this, hWnd, LVM_SETITEMW, wParam, (UINT *)&hditem);
    case LVM_SORTITEMS:
      pChildItem = this->m_ChildItem;
      if ( pChildItem && pChildItem != pThis->m_ChildLastSort )
      {
        pNewSorted = (tagTreeViewChildItem *)CTreeList::Sort(
                                               (tagTreeViewChildItem *)&pThis->m_ChildItem,
                                               pThis->m_nChildCount,
                                               CTreeList::SortCallback,
                                               (int)pnIDs,
                                               wParam,
                                               0);
        pThis->m_ChildItem = pNewSorted;
        pNewSorted->m_Item0C = 0;
        v55 = pThis->m_ChildItem;
        v56 = v55->m_Sibling;
        for ( i = (tagTreeViewChildItem *)((char *)v55 + 0x10);
              v56;
              i = (tagTreeViewChildItem *)&i->m_TreeList->m_hWndTooltipOfLeftHeader )
        {
          v56->m_Item0C = v55;
          v55 = (tagTreeViewChildItem *)i->m_TreeList;
          v56 = (tagTreeViewChildItem *)i->m_TreeList->m_hWndTooltipOfLeftHeader;
        }
        pThis->m_ChildLastSort = v55;
      }
      InvalidateRect(pThis->m_hWnd, 0, 0);
      return (HWND)1;
    case LVM_GETSUBITEMRECT:
      if ( *pnIDs && *pnIDs != 2 )
        return 0;
      return (HWND)(unsigned __int8)CTreeList::GetSubItemRect(this, wParam, pnIDs[1], 1, 0, 0, (RECT *)pnIDs);
    case LVM_SETCOLUMNORDERARRAY:
      if ( (signed int)wParam <= 1 )
        return (HWND)((wParam & 0x80000000) == 0);
      dwIndex = 1;
      if ( wParam - 1 >= 8 )
      {
        dwValue1 = _mm_load_si128((const __m128i *)&stru_CA4280);
        dwValue2 = pnIDs + 1;
        do
        {
          dwValue3 = _mm_loadu_si128((const __m128i *)dwValue2);
          dwIndex += 8;
          dwValue2 += 8;
          _mm_storeu_si128((__m128i *)dwValue2 - 2, _mm_sub_epi32(dwValue3, dwValue1));
          _mm_storeu_si128(
            (__m128i *)dwValue2 - 1,
            _mm_sub_epi32(_mm_loadu_si128((const __m128i *)dwValue2 - 1), dwValue1));
        }
        while ( dwIndex < (signed int)(wParam - (signed int)(wParam - 1) % 8) );
      }
      for ( ; dwIndex < (signed int)wParam; ++dwIndex )
        --pnIDs[dwIndex];
      return (HWND)SendMessageW(pThis->m_hWndHeaderRight, HDM_SETORDERARRAY, wParam - 1, (LPARAM)(pnIDs + 1));
    case LVM_GETCOLUMNORDERARRAY:
      nLeftColumnCount = SendMessageW(this->m_hWndHeaderLeft, HDM_GETITEMCOUNT, 0, 0);
      nColumnCount = nLeftColumnCount + SendMessageW(pThis->m_hWndHeaderRight, HDM_GETITEMCOUNT, 0, 0);
      nColumn = wParamIn;
      if ( wParamIn != nColumnCount )
        return 0;
      if ( wParamIn <= 0 )
        return (HWND)1;
      *pnIDs = 0;
      result = (HWND)SendMessageW(pThis->m_hWndHeaderRight, HDM_GETORDERARRAY, nColumn - 1, (LPARAM)(pnIDs + 1));
      nIndex = 1;
      wParamIn = (int)result;
      nLeftColumn = nColumn - 1;
      if ( nColumn > 1 )
      {
        if ( (unsigned int)nLeftColumn >= 8 )
        {
          v31 = nLeftColumn % 8;
          temp = _mm_load_si128((const __m128i *)&stru_CA4280);
          pnIDsTemp = (const __m128i *)(pnIDs + 1);
          do
          {
            v34 = _mm_loadu_si128(pnIDsTemp);
            nIndex += 8;
            pnIDsTemp += 2;
            _mm_storeu_si128((__m128i *)&pnIDsTemp[-2], _mm_add_epi32(v34, temp));
            _mm_storeu_si128((__m128i *)&pnIDsTemp[-1], _mm_add_epi32(_mm_loadu_si128(pnIDsTemp - 1), temp));
          }
          while ( nIndex < nColumn - v31 );
          result = (HWND)wParamIn;
        }
        for ( ; nIndex < nColumn; ++nIndex )
          ++pnIDs[nIndex];
      }
      return result;
    case LVM_GETITEMW:
      if ( !this->m_nChildCount )
        return 0;
      iItem = pnIDs[1];
      m_ChildItem = this->m_ChildItem;
      wParamIn = *pnIDs;
      pNewChild = TreeViewChildItem_GetChild(m_ChildItem, iItem);
      v45 = pNewChild;
      if ( !pNewChild )
        return 0;
      v46 = wParamIn;
      if ( wParamIn & LVIF_TEXT )
      {
        v47 = pNewChild->m_TreeListData;
        v46 = wParamIn & -2;
        v48 = pnIDs[5];
        wParamIn = pnIDs[6];
        pnIDs[5] = ((int (__stdcall *)(tagTreeViewChildItem *, UINT, UINT, int *))v47->vtptr->GetItemText)(
                     pNewChild,
                     pnIDs[2],
                     v48,
                     &wParamIn);
      }
      if ( v46 & LVIF_STATE )
      {
        v46 &= -9u;
        pnIDs[3] = 0;
        if ( v45->m_dwStyle & 1 )
          pnIDs[3] = LVIS_SELECTED;
      }
      if ( v46 & LVIF_PARAM )
      {
        v46 &= -5u;
        pnIDs[8] = v45->m_TreeListData->m_TreeItem;
      }
      if ( v46 & LVIF_IMAGE )
      {
        v49 = v45->m_TreeListData;
        wParamIn = 0;
        pnIDs[7] = ((int (__stdcall *)(tagTreeViewChildItem *, int *))v49->vtptr->GetItemImage)(v45, &wParamIn);
      }
      return (HWND)1;
    case LVM_SETITEMW:
      if ( !this->m_nChildCount )
        return 0;
      v59 = pnIDs[1];
      v60 = this->m_ChildItem;
      wParamIn = *pnIDs;
      pNewChild_1 = TreeViewChildItem_GetChild(v60, v59);
      if ( !pNewChild_1 )
        return 0;
      v62 = wParamIn;
      if ( wParamIn & LVIF_PARAM )
      {
        v62 = wParamIn & -5;
        pNewChild_1->m_TreeListData->m_TreeItem = pnIDs[8];
      }
      if ( !(v62 & LVIF_STATE) )
        return (HWND)1;
      if ( pNewChild_1->m_dwStyle & 1 )
      {
        if ( !(pnIDs[3] & 3) )
        {
          CTreeList::RedrawChild(pThis, 0);
          return (HWND)1;
        }
        return (HWND)1;
      }
      if ( !(pnIDs[3] & 3) )
        return (HWND)1;
      CTreeList::RedrawChild(pThis, pNewChild_1);
      return (HWND)1;
    case LVM_INSERTITEMW:
      wParamIn = pnIDs[1];
      pListViewData = (CListViewData *)operator new(8u);
      if ( pListViewData )
      {
        v36 = (tagTREEVIEWLISTITEMPARAM *)pnIDs[8];
        pListViewData->vtptr = (int)&CListViewData::`vftable';
        pListViewData->m_TreeItem = v36;
      }
      else
      {
        pListViewData = 0;
      }
      v37 = CTreeList::_InsertItem(pThis, wParam, pListViewData, (int (__cdecl *)(int, _DWORD, int, _DWORD))1, wParamIn);
      return (HWND)CTreeList::FindChild(pThis, v37);
    case LVM_FINDITEMW:
      pChild = this->m_ChildItem;
      nFound = 0;
      if ( !pChild )
        return HWND_MESSAGE|0x2;
      Flags = *pnIDs;
      while ( Flags != 1 || pChild->m_TreeListData->m_TreeItem != pnIDs[2] )
      {
        ++nFound;
        pChild = TreeViewChildItem_GetNextChild(pChild);
        if ( !pChild )
          return HWND_MESSAGE|0x2;
      }
      return (HWND)nFound;
    case LVM_GETCOLUMNW:
      bNoText = (*(_BYTE *)pnIDs & LVCF_TEXT) == 0;
      _mm_storeu_si128((__m128i *)&hditem_1.cxy, (__m128i)0i64);
      hditem_1.mask = 5;
      _mm_storeu_si128((__m128i *)&hditem_1.fmt, (__m128i)0i64);
      v66 = 0i64;
      if ( !bNoText )
      {
        hditem_1.pszText = (LPWSTR)pnIDs[3];
        v9 = pnIDs[4];
        hditem_1.mask = 7;
        hditem_1.cchTextMax = v9;
      }
      if ( wParam )
        bRet = SendMessageW(this->m_hWndHeaderRight, HDM_GETITEMW, wParam - 1, (LPARAM)&hditem_1);
      else
        bRet = SendMessageW(this->m_hWndHeaderLeft, HDM_GETITEMW, 0, (LPARAM)&hditem_1);
      if ( !bRet )
        return 0;
      v11 = *pnIDs;
      if ( *pnIDs & LVCF_WIDTH )
        pnIDs[2] = hditem_1.cxy;
      result = (HWND)HDF_RIGHT;
      if ( v11 & HDF_RIGHT )
      {
        v12 = 0;
        if ( hditem_1.fmt & HDF_RIGHT )
          v12 = HDF_RIGHT;
        pnIDs[1] = v12;
      }
      return result;
    case LVM_SETCOLUMNW:
      fMask = *pnIDs;
      dwMask_1 = 0;
      v66 = 0i64;
      hditem_1.mask = 0;
      _mm_storeu_si128((__m128i *)&hditem_1.cxy, (__m128i)0i64);
      _mm_storeu_si128((__m128i *)&hditem_1.fmt, (__m128i)0i64);
      if ( fMask & LVCF_WIDTH )
      {
        v15 = pnIDs[2];
        dwMask_1 = 1;
        hditem_1.mask = 1;
        hditem_1.cxy = v15;
      }
      if ( fMask & LVCF_FMT )
      {
        dwFormat = pnIDs[1];
        dwMask_1 |= HDI_FORMAT;
        fRight = pnIDs[1] & LVCFMT_RIGHT;
        hditem_1.mask = dwMask_1;
        bRight = fRight | HDF_STRING;
        if ( dwFormat & LVCFMT_IMAGE )
          v19 = bRight | 0x1800;
        else
          v19 = bRight & -0x1801u;
        hditem_1.fmt = v19;
        fMask = *pnIDs;
      }
      if ( fMask & LVCF_TEXT )
      {
        v20 = (WCHAR *)pnIDs[3];
        dwMask_1 |= HDI_TEXT;
        hditem_1.mask = dwMask_1;
        hditem_1.pszText = v20;
      }
      if ( fMask & LVCF_IMAGE )
      {
        v21 = pnIDs[6];
        hditem_1.mask = dwMask_1 | HDI_IMAGE;
        hditem_1.iImage = v21;
      }
      if ( wParam )
        result = (HWND)SendMessageW(pThis->m_hWndHeaderRight, HDM_SETITEMW, wParam - 1, (LPARAM)&hditem_1);
      else
        result = (HWND)SendMessageW(pThis->m_hWndHeaderLeft, HDM_SETITEMW, 0, (LPARAM)&hditem_1);
      return result;
    case LVM_INSERTCOLUMNW:
      v7 = pnIDs[2];
      *(_QWORD *)&rc.right = 0i64;
      rc.right = MulDiv(v7, 96, gLogPixelSize.x);
      rc.top = pnIDs[3];
      rc.bottom = pnIDs[1] & 1;
      return (HWND)(unsigned __int8)CTreeList::InsertColumn(pThis, (tagTVLSCOLUMNW *)&rc.top, wParam);
    case LVM_GETITEMTEXTW:
      if ( !this->m_nChildCount )
        return 0;
      v39 = TreeViewChildItem_GetChild(this->m_ChildItem, wParam);
      if ( !v39 )
        return 0;
      wParamIn = pnIDs[6];
      v40 = (const wchar_t *)((int (__stdcall *)(tagTreeViewChildItem *, UINT, UINT, int *))v39->m_TreeListData->vtptr->GetItemText)(
                               v39,
                               pnIDs[2],
                               pnIDs[5],
                               &wParamIn);
      v41 = (wchar_t *)pnIDs[5];
      if ( v40 != v41 )
        wcsncpy_s(v41, pnIDs[6], v40, 0xFFFFFFFF);
      return (HWND)1;
    case LVM_SETITEMTEXTW:
      return (HWND)(pnIDs[5] == -1);
    case LVM_ISITEMVISIBLE:
      return (HWND)CTreeList::IsItemVisible(this, wParam);
    default:
      return (HWND)DefWindowProcW(hWnd, Msg, wParam, (LPARAM)pnIDs);
  }
}
// CA4268: using guessed type void *CListViewData::`vftable';
// CA4280: using guessed type tagRECT stru_CA4280;

//----- (00C0E5D0) --------------------------------------------------------
int __stdcall sub_C0E5D0(int a1)
{
  return *(_DWORD *)(*(_DWORD *)(a1 + 4) + 4);
}

//----- (00C0E5E0) --------------------------------------------------------
int __stdcall CTreeList::OnMsg2004(tagTreeViewChildItem *pThis, tagTREEVIEWLISTITEMPARAM *a2, int a5)
{
  CTreeList *v3; // ecx
  CTreeList *v4; // edi
  CListViewData *pListViewData; // eax
  tagTreeViewChildItem *pChildItem; // esi
  int *v7; // eax
  int v8; // ebx
  int v9; // eax

  v4 = v3;
  pListViewData = (CListViewData *)operator new(8u);
  if ( pListViewData )
  {
    pListViewData->vtptr = (int)&CListViewData::`vftable';
    pListViewData->m_TreeItem = a2;
  }
  else
  {
    pListViewData = 0;
  }
  pChildItem = pThis;
  if ( !pThis )
    pChildItem = (tagTreeViewChildItem *)&v4->m_Item_40;
  v7 = TreeViewChildItem_Init(pChildItem, v4, pListViewData, (int (__cdecl *)(int, _DWORD, int, _DWORD))pfnCallback, a5);
  v8 = (int)v7;
  if ( pChildItem->m_dwStyle & 0x10 )
  {
    v9 = CTreeList::FindChild(v4, (tagTreeViewChildItem *)v7);
    CTreeList::SetVScrollbarPos(v9, 1);
  }
  return v8;
}
// CA4268: using guessed type void *CListViewData::`vftable';

//----- (00C0E650) --------------------------------------------------------
tagTreeViewChildItem *__thiscall TreeViewChildItem_GetNextChild(tagTreeViewChildItem *pThis)
{
  tagTreeViewChildItem *result; // eax
  tagTreeViewChildItem *v2; // eax

  result = pThis->m_Child;
  if ( !result || !(((unsigned int)pThis->m_dwStyle >> 4) & 1) )
  {
    result = pThis->m_Sibling;
    if ( !result )
    {
      v2 = pThis->m_Current;
      if ( v2 )
      {
        while ( !v2->m_Sibling )
        {
          v2 = v2->m_Current;
          if ( !v2 )
            goto LABEL_7;
        }
        result = v2->m_Sibling;
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

//----- (00C0E690) --------------------------------------------------------
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
        return SendMessageW(hWndParent, WM_NOTIFY, pNMHDR->nmhdr.idFrom, (LPARAM)pNMHDR);
    }
    else if ( code != -5 )
    {
      if ( code == 2006 )
      {
        _mm_storeu_si128((__m128i *)&lParam.nmhdr.code, (__m128i)0i64);
        lParam.pFrom = (tagTreeViewChildItem *)2006;
        _mm_storeu_si128((__m128i *)&lParam.nItem2, (__m128i)0i64);
        v17 = 0i64;
        *(_QWORD *)&lParam.nmhdr.idFrom = *(_QWORD *)&pNMHDR->nmhdr.hwndFrom;
        lParam.pFrom = (tagTreeViewChildItem *)LVN_DELETEITEM;
        lParam.pTo = (tagTreeViewChildItem *)CTreeList::FindChild(this, pSibling);
        HIDWORD(v17) = pTreeListData->m_TreeItem;
        SendMessageW(hWndParent, WM_NOTIFY, lParam.nmhdr.code, (LPARAM)&lParam.nmhdr.idFrom);
        return 0;
      }
      return SendMessageW(hWndParent, WM_NOTIFY, pNMHDR->nmhdr.idFrom, (LPARAM)pNMHDR);
    }
    memset(&lParam.nmhdr.idFrom, 0, 0x2Cu);
    v13 = pNMHDR->nmhdr.code;
    *(_QWORD *)&lParam.nmhdr.hwndFrom = *(_QWORD *)&pNMHDR->nmhdr.hwndFrom;
    lParam.nmhdr.code = v13;
    if ( pSibling )
      lParam.pFrom = (tagTreeViewChildItem *)CTreeList::FindChild(pThis, pSibling);
    else
      lParam.pFrom = (tagTreeViewChildItem *)-1;
    lParam.pTo = (tagTreeViewChildItem *)pNMHDR->nItem1;
    if ( pTreeListData )
      LODWORD(v17) = pTreeListData->m_TreeItem;
    else
      LODWORD(v17) = 0;
    return SendMessageW(hWndParent, WM_NOTIFY, lParam.nmhdr.idFrom, (LPARAM)&lParam);
  }
  if ( code >= 2004 )
    return SendMessageW(hWndParent, WM_NOTIFY, pNMHDR->nmhdr.idFrom, (LPARAM)pNMHDR);
  switch ( code )
  {
    case 2000u:
      v6 = pNMHDR->nmhdr.code;
      v7 = pNMHDR->pFrom;
      v17 = 0i64;
      _mm_storeu_si128((__m128i *)&lParam.nmhdr.code, (__m128i)0i64);
      lParam.pFrom = (tagTreeViewChildItem *)LVN_ITEMCHANGED;
      _mm_storeu_si128((__m128i *)&lParam.nItem2, (__m128i)0i64);
      *(_QWORD *)&lParam.nmhdr.idFrom = *(_QWORD *)&pNMHDR->nmhdr.hwndFrom;
      if ( v7 )
      {
        lParam.pTo = (tagTreeViewChildItem *)CTreeList::FindChild(this, v7);
        v8 = v7->m_TreeListData;
        v9 = hWndParent;
        HIDWORD(v17) = v8->m_TreeItem;
        v15 = 3;
        lParam.nItem2 = 0;
        v16 = 3;
        SendMessageW(hWndParent, WM_NOTIFY, lParam.nmhdr.code, (LPARAM)&lParam.nmhdr.idFrom);
        this = pThis;
      }
      else
      {
        v9 = hWndParent;
      }
      if ( pNMHDR->pTo )
      {
        lParam.pTo = (tagTreeViewChildItem *)CTreeList::FindChild(this, pNMHDR->pTo);
        HIDWORD(v17) = pTreeListData->m_TreeItem;
        lParam.nItem2 = 0;
        v15 = 3;
        v16 = 3;
        SendMessageW(v9, WM_NOTIFY, lParam.nmhdr.code, (LPARAM)&lParam.nmhdr.idFrom);
      }
      result = 0;
      break;
    case 2003u:
      v11 = (tagTreeViewChildItem *)pNMHDR->nmhdr.code;
      _mm_storeu_si128((__m128i *)&lParam.nmhdr.code, (__m128i)0i64);
      lParam.pFrom = v11;
      lParam.nItem1 = pNMHDR->nItem1;
      v12 = pNMHDR->nmhdr.idFrom;
      _mm_storeu_si128((__m128i *)&lParam.nItem2, (__m128i)0i64);
      v17 = 0i64;
      *(_QWORD *)&lParam.nmhdr.idFrom = *(_QWORD *)&pNMHDR->nmhdr.hwndFrom;
      lParam.pFrom = (tagTreeViewChildItem *)LVN_COLUMNCLICK;
      lParam.pTo = (tagTreeViewChildItem *)-1;
      SendMessageW(hWndParent, WM_NOTIFY, v12, (LPARAM)&lParam.nmhdr.idFrom);
      result = 0;
      break;
    default:
      return SendMessageW(hWndParent, WM_NOTIFY, pNMHDR->nmhdr.idFrom, (LPARAM)pNMHDR);
  }
  return result;
}

//----- (00C0E900) --------------------------------------------------------
BOOL __thiscall CListViewData::DrawItem(CListViewData *this, tagTreeViewChildItem *pChild, HDC hdc, int itemAction, int a5, const RECT *lprc)
{
  CListViewData *v6; // ST20_4
  CTreeList *pTreeList; // ST1C_4
  UINT nItem; // edi
  UINT nID; // eax
  __m128i v10; // xmm0
  WPARAM v11; // ST08_4
  HWND v12; // eax
  DRAWITEMSTRUCT DrawItemStruct; // [esp+18h] [ebp-34h]

  v6 = this;
  pTreeList = pChild->m_TreeList;
  nItem = CTreeList::FindChild(pChild->m_TreeList, pChild);
  DrawItemStruct.CtlType = 0;
  memset(&DrawItemStruct.CtlID, 0, 0x2Cu);
  DrawItemStruct.hDC = hdc;
  nID = GetWindowLongW(pTreeList->m_hWnd, GWLP_ID);
  v10 = _mm_loadu_si128((const __m128i *)lprc);
  DrawItemStruct.CtlType = ODT_LISTVIEW;
  DrawItemStruct.CtlID = nID;
  DrawItemStruct.hwndItem = pTreeList->m_hWnd;
  DrawItemStruct.itemState = pChild->m_dwStyle;
  _mm_storeu_si128((__m128i *)DrawItemStruct.gap1C, v10);
  DrawItemStruct.itemID = nItem;
  DrawItemStruct.itemAction = itemAction;
  DrawItemStruct.itemData = (DWORD)v6->m_TreeItem;
  v11 = nID;
  v12 = GetParent(pTreeList->m_hWnd);
  return SendMessageW(v12, WM_DRAWITEM, v11, (LPARAM)&DrawItemStruct) != 0;
}

//----- (00C0E9C0) --------------------------------------------------------
char __stdcall CTreeListData::DrawItem(int a1, int a2, int a3, int a4, int a5)
{
  return 0;
}

//----- (00C0E9D0) --------------------------------------------------------
tagTreeViewChildItem *__thiscall sub_C0E9D0(tagTreeViewChildItem *this)
{
  tagTreeViewChildItem *v1; // edx
  tagTreeViewChildItem *i; // ecx
  tagTreeViewChildItem *result; // eax

  v1 = this->m_Item0C;
  if ( v1 )
  {
    for ( i = v1->m_Item18; i; i = i->m_Item18 )
    {
      if ( !(((unsigned int)v1->m_dwStyle >> 4) & 1) )
        break;
      v1 = i;
    }
    result = v1;
  }
  else
  {
    result = this->m_Current;
    if ( result && !result->m_TreeListData )
      result = 0;
  }
  return result;
}

//----- (00C0EA10) --------------------------------------------------------
int __thiscall CTreeList::Refresh(CTreeList *this)
{
  CTreeList *v1; // edi

  v1 = this;
  InvalidateRect(this->m_hWnd, 0, 0);
  InvalidateRect(v1->m_hWndHeaderLeft, 0, 0);
  InvalidateRect(v1->m_hWndHeaderRight, 0, 0);
  v1->m_nChildWidthLast = CTreeList::GetChildWidth(v1, 0);
  CTreeList::Resize(v1);
  CTreeList::RepositionHeaders();
  return CTreeList::RepositionTooltips();
}

//----- (00C0EA60) --------------------------------------------------------
BOOL __thiscall CTreeList::RefreshHeaderItem(CTreeList *this, int nItem)
{
  CTreeList *v2; // esi
  BOOL result; // eax
  int lParam; // [esp+4h] [ebp-14h]

  v2 = this;
  if ( nItem )
  {
    SendMessageW(this->m_hWndHeaderRight, HDM_GETITEMRECT, nItem - 1, (LPARAM)&lParam);
    result = InvalidateRect(v2->m_hWndHeaderRight, (const RECT *)&lParam, 0);
  }
  else
  {
    SendMessageW(this->m_hWndHeaderLeft, HDM_GETITEMRECT, 0, (LPARAM)&lParam);
    result = InvalidateRect(v2->m_hWndHeaderLeft, (const RECT *)&lParam, 0);
  }
  return result;
}

//----- (00C0EAD0) --------------------------------------------------------
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

//----- (00C0EAF0) --------------------------------------------------------
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
  int rcClient; // [esp+74h] [ebp-14h]
  int v14; // [esp+78h] [ebp-10h]
  int v15; // [esp+80h] [ebp-8h]

  v3 = thisIn;
  this = thisIn;
  if ( nEnd >= nStart )
  {
    ScrollInfo.cbSize = sizeof(SCROLLINFO);
    m_hWndScrollBarRightRight = thisIn->m_hWndScrollBarRightRight;
    ScrollInfo.nTrackPos = 0;
    _mm_storeu_si128((__m128i *)&ScrollInfo.nMin, (__m128i)0i64);
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
    GetClientRect(this->m_hWnd, (LPRECT)&rcClient);
    v14 = Rect.bottom + nTotalHeight * (nStart - ScrollInfo.nPos) - Rect.top;
    v15 = Rect.bottom + nTotalHeight * (nStart - ScrollInfo.nPos) - Rect.top + nTotalHeight * (nEnd - nStart + 1);
    InvalidateRect(this->m_hWnd, (const RECT *)&rcClient, 0);
  }
}

//----- (00C0EBF0) --------------------------------------------------------
ATOM CTreeList::Register()
{
  WNDCLASSEXW v1; // [esp+0h] [ebp-30h]

  memset(&v1.style, 0, 0x2Cu);
  v1.cbSize = 48;
  v1.lpfnWndProc = (WNDPROC)CTreeList::WndProc;
  v1.hCursor = LoadCursorW(0, (LPCWSTR)0x7F00);
  v1.hbrBackground = 0;
  v1.lpszMenuName = 0;
  v1.style = 8;
  v1.lpszClassName = L"TreeListWindowClass";
  return RegisterClassExW(&v1);
}
// CA41A4: using guessed type wchar_t aTreelistwindow[20];

//----- (00C0EC50) --------------------------------------------------------
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
  struct tagRECT rwHeaderRight; // [esp+60h] [ebp-14h]

  this = v0;
  GetClientRect(v0->m_hWnd, &rcClient);
  GetWindowRect(this->m_hWndHeaderRight, &rwHeaderRight);
  ScrollInfo.cbSize = sizeof(SCROLLINFO);
  m_hWndScrollBarRightBottom = this->m_hWndScrollBarRightBottom;
  ScrollInfo.nTrackPos = 0;
  _mm_storeu_si128((__m128i *)&ScrollInfo.nMin, (__m128i)0i64);
  ScrollInfo.fMask = SIF_POS;
  GetScrollInfo(m_hWndScrollBarRightBottom, SB_CTL, &ScrollInfo);
  rwHeaderRight.left = this->m_nBottomScrollBarWidthOrHeight - ScrollInfo.nPos;
  m_hWndScrollBarRightRight = this->m_hWndScrollBarRightRight;
  rwHeaderRight.right = rcClient.right - rcClient.left;
  rwHeaderRight.bottom -= rwHeaderRight.top;
  rwHeaderRight.top = 0;
  if ( ((unsigned int)GetWindowLongW(m_hWndScrollBarRightRight, GWL_STYLE) >> 28) & 1 )
  {
    v4 = GetSystemMetrics(SM_CXVSCROLL);
    right = rwHeaderRight.right - v4;
    rwHeaderRight.right -= v4;
  }
  else
  {
    right = rwHeaderRight.right;
  }
  SetWindowPos(
    this->m_hWndHeaderRight,
    0,
    rwHeaderRight.left,
    rwHeaderRight.top,
    right - rwHeaderRight.left,
    rwHeaderRight.bottom - rwHeaderRight.top,
    SWP_NOZORDER);
  m_hWndHeaderRight = this->m_hWndHeaderRight;
  ToolInfo.cbSize = 0x30;
  _mm_storeu_si128((__m128i *)&ToolInfo.hwnd, (__m128i)0i64);
  ToolInfo.uFlags = 0;
  _mm_storeu_si128((__m128i *)&ToolInfo.gap10[8], (__m128i)0i64);
  ToolInfo.hwnd = m_hWndHeaderRight;
  *(_QWORD *)&ToolInfo.lParam = 0i64;
  GetClientRect(m_hWndHeaderRight, (LPRECT)ToolInfo.gap10);
  // Sets a new bounding rectangle for a tool
  return SendMessageW(this->m_hWndTooltipOfRightHeader, TTM_NEWTOOLRECTW, 0, (LPARAM)&ToolInfo);
}

//----- (00C0ED70) --------------------------------------------------------
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
  MapWindowPoints(0, v2->m_hWnd, (LPPOINT)&Rect, 2u);
  MapWindowPoints(0, v2->m_hWnd, (LPPOINT)&v16, 2u);
  v3 = v2->m_hWndScrollBarLeftBottom;
  v13.cbSize = 28;
  _mm_storeu_si128((__m128i *)&v13.nMin, (__m128i)0i64);
  v13.nTrackPos = 0;
  v14.cbSize = 28;
  _mm_storeu_si128((__m128i *)&v14.nMin, (__m128i)0i64);
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
  _mm_storeu_si128((__m128i *)&v10, (__m128i)0i64);
  _mm_storeu_si128((__m128i *)&v11.right, (__m128i)0i64);
  v10 = v6;
  v12 = 0i64;
  GetClientRect(v6, &v11);
  SendMessageW(v2->m_hWndTooltipOfRightHeader, TTM_NEWTOOLRECTW, 0, (LPARAM)&lParam);
  v10 = v2->m_hWndHeaderLeft;
  GetClientRect(v10, &v11);
  return SendMessageW(v2->m_hWndTooltipOfLeftHeader, TTM_NEWTOOLRECTW, 0, (LPARAM)&lParam);
}

//----- (00C0EF00) --------------------------------------------------------
int __thiscall CTreeList::Resize(CTreeList *this)
{
  CTreeList *v1; // ebx
  bool v2; // al
  int result; // eax
  bool bRightFlags; // [esp+Bh] [ebp-45h]
  bool bBottomFlags; // [esp+Fh] [ebp-41h]
  bool v6; // [esp+13h] [ebp-3Dh]
  SCROLLINFO RightScrollInfo; // [esp+14h] [ebp-3Ch]
  SCROLLINFO BottomScrollInfo; // [esp+30h] [ebp-20h]

  v1 = this;
  CTreeList::GetScrollInfos(this, &RightScrollInfo, &BottomScrollInfo);
  bRightFlags = (signed int)RightScrollInfo.nPage <= RightScrollInfo.nMax;
  bBottomFlags = (signed int)BottomScrollInfo.nPage <= BottomScrollInfo.nMax;
  v6 = CTreeList::UpdateRightRightSB(
         v1,
         (signed int)RightScrollInfo.nPage <= RightScrollInfo.nMax,
         (signed int)BottomScrollInfo.nPage <= BottomScrollInfo.nMax);
  CTreeList::UpdateLeftBottomSB(v1, v1->m_hWndScrollBarRightBottom, bBottomFlags, bRightFlags);
  v2 = bRightFlags && bBottomFlags;
  result = CTreeList::ShowCaption(v1, v2);
  if ( bRightFlags )
  {
    SetScrollInfo(v1->m_hWndScrollBarRightRight, 2, &RightScrollInfo, 1);
    result = CTreeList::UpdateVScrollBars(v1, 0);
  }
  if ( bBottomFlags )
  {
    SetScrollInfo(v1->m_hWndScrollBarRightBottom, 2, &BottomScrollInfo, 1);
    result = CTreeList::UpdateHeaderPos(v1, v1->m_hWndScrollBarRightBottom, 0);
  }
  if ( v6 )
    result = CTreeList::RepositionTooltips();
  return result;
}

//----- (00C0EFD0) --------------------------------------------------------
int __cdecl CTreeList::RepositionHeaders()
{
  CTreeList *v0; // ecx
  CTreeList *this; // esi
  int nMax; // edi
  bool v3; // bl
  int result; // eax
  HWND v5; // ST00_4
  UINT nPage; // [esp+8h] [ebp-34h]
  struct tagRECT rcclient; // [esp+Ch] [ebp-30h]
  SCROLLINFO v8; // [esp+1Ch] [ebp-20h]

  this = v0;
  if ( v0->m_bValue1 )
  {
    GetClientRect(v0->m_hWnd, &rcclient);
    nMax = this->m_nChildWidthLast;
    v3 = nMax > this->m_nBottomScrollBarWidthOrHeight;
    nPage = this->m_nBottomScrollBarWidthOrHeight;
    LOBYTE(result) = CTreeList::UpdateLeftBottomSB(this, this->m_hWndScrollBarLeftBottom, v3, 0);
    if ( v3 )
    {
      v8.cbSize = 28;
      _mm_storeu_si128((__m128i *)&v8.nMin, (__m128i)0i64);
      v8.nTrackPos = 0;
      v8.nMax = nMax - 1;
      v8.nPage = nPage;
      v5 = this->m_hWndScrollBarLeftBottom;
      v8.fMask = 3;
      v8.nMin = 0;
      SetScrollInfo(v5, 2, &v8, 1);
      result = CTreeList::UpdateHeaderPos(this, this->m_hWndScrollBarLeftBottom, 0);
    }
  }
  return result;
}

//----- (00C0F090) --------------------------------------------------------
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

//----- (00C0F110) --------------------------------------------------------
int __stdcall CTreeList::UpdateColumnHeight(int nItem, int nWidth)
{
  CTreeList *v2; // ecx
  int result; // eax
  HDITEMW item; // [esp+0h] [ebp-2Ch]

  item.cxy = nWidth;
  item.mask = HDI_HEIGHT;
  if ( nItem )
    result = SendMessageW(v2->m_hWndHeaderRight, HDM_SETITEMW, nItem - 1, (LPARAM)&item);
  else
    result = SendMessageW(v2->m_hWndHeaderLeft, HDM_SETITEMW, 0, (LPARAM)&item);
  return result;
}

//----- (00C0F160) --------------------------------------------------------
int __stdcall CTreeList::OnMsg2000(tagTreeViewChildItem *pItem, char a2)
{
  int result; // eax

  result = (int)pItem;
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

//----- (00C0F190) --------------------------------------------------------
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

//----- (00C0F1E0) --------------------------------------------------------
char __thiscall CTreeList::ResetImageList(CTreeList *this, int a2, char a3)
{
  CTreeList *v3; // esi
  char result; // al

  v3 = this;
  if ( this->m_ImageList && !LOBYTE(this->m_NotMyImageList) )
    ImageList_Destroy(this->m_ImageList);
  v3->m_ImageList = (HIMAGELIST)a2;
  result = a3;
  LOBYTE(v3->m_NotMyImageList) = a3;
  return result;
}

//----- (00C0F210) --------------------------------------------------------
int __thiscall sub_C0F210(CTreeList *this, int a2)
{
  int result; // eax

  result = a2;
  this->m_nHeight = a2;
  return result;
}

//----- (00C0F230) --------------------------------------------------------
int __thiscall sub_C0F230(CTreeList *this, int a2)
{
  int result; // eax

  result = a2;
  this->field_74 = a2;
  return result;
}

//----- (00C0F240) --------------------------------------------------------
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

//----- (00C0F2D0) --------------------------------------------------------
bool __thiscall CTreeList::UpdateLeftBottomSB(CTreeList *this, HWND hWnd, bool fBottomIsVisible, bool bRightIsVisible)
{
  CTreeList *This; // esi
  char v5; // al
  bool v6; // bl
  int cxVScroll; // eax
  HWND hWndScrollbar; // ecx
  int nRight; // esi
  int nTop; // ebx
  int nBottom; // eax
  bool result; // al
  int v13; // [esp+Ch] [ebp-40h]
  int cyHScroll; // [esp+10h] [ebp-3Ch]
  int nLeft; // [esp+14h] [ebp-38h]
  bool v16; // [esp+1Bh] [ebp-31h]
  SCROLLINFO v17; // [esp+1Ch] [ebp-30h]
  struct tagRECT rcClient; // [esp+38h] [ebp-14h]

  This = this;
  GetClientRect(this->m_hWnd, &rcClient);
  v5 = ((unsigned int)GetWindowLongW(hWnd, -16) >> 28) & 1;
  v6 = v5 != fBottomIsVisible;
  v16 = v5 != fBottomIsVisible;
  if ( fBottomIsVisible )
  {
    cyHScroll = GetSystemMetrics(SM_CYHSCROLL);
    cxVScroll = GetSystemMetrics(SM_CXVSCROLL);
    hWndScrollbar = This->m_hWndScrollBarLeftBottom;
    v13 = cxVScroll;
    if ( hWnd == hWndScrollbar )
      nLeft = 0;
    else
      nLeft = This->m_nBottomScrollBarWidthOrHeight;
    if ( hWnd == hWndScrollbar )
      nRight = This->m_nBottomScrollBarWidthOrHeight;
    else
      nRight = rcClient.right - rcClient.left;
    nTop = rcClient.bottom - rcClient.top - cyHScroll;
    nBottom = nTop + GetSystemMetrics(SM_CYHSCROLL);
    if ( bRightIsVisible )
      nRight -= v13;
    SetWindowPos(hWnd, 0, nLeft, nTop, nRight - nLeft, nBottom - nTop, SWP_SHOWWINDOW|SWP_NOZORDER);
    result = v16;
  }
  else
  {
    if ( v5 )
    {
      v17.cbSize = 28;
      v17.nTrackPos = 0;
      _mm_storeu_si128((__m128i *)&v17.nMin, (__m128i)0i64);
      v17.fMask = 4;
      v17.nPos = 0;
      SetScrollInfo(hWnd, 2, &v17, 1);
      CTreeList::UpdateHeaderPos(This, hWnd, 0);
      ShowWindow(hWnd, 0);
    }
    result = v6;
  }
  return result;
}

//----- (00C0F400) --------------------------------------------------------
bool __thiscall CTreeList::UpdateRightRightSB(CTreeList *this, bool fRightIsVisible, bool fBottomIsVisible)
{
  CTreeList *v3; // edi
  char bWindowVisible; // al
  bool v5; // bl
  int nMaxRight; // edx
  int nMaxBottom; // eax
  bool result; // al
  HWND v9; // ST0C_4
  int v10; // [esp+8h] [ebp-34h]
  SCROLLINFO v11; // [esp+Ch] [ebp-30h]
  struct tagRECT rcClient; // [esp+28h] [ebp-14h]

  v3 = this;
  GetClientRect(this->m_hWnd, &rcClient);
  bWindowVisible = ((unsigned int)GetWindowLongW(v3->m_hWndScrollBarRightRight, -16) >> 28) & 1;
  v5 = bWindowVisible != fRightIsVisible;
  if ( fRightIsVisible )
  {
    v10 = GetSystemMetrics(SM_CYHSCROLL);
    nMaxRight = rcClient.right - rcClient.left - GetSystemMetrics(SM_CXVSCROLL);
    nMaxBottom = rcClient.bottom - rcClient.top;
    if ( fBottomIsVisible )
      nMaxBottom -= v10;
    SetWindowPos(
      v3->m_hWndScrollBarRightRight,
      0,
      nMaxRight,
      0,
      rcClient.right - rcClient.left - nMaxRight,
      nMaxBottom,
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
      _mm_storeu_si128((__m128i *)&v11.nMin, (__m128i)0i64);
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

//----- (00C0F500) --------------------------------------------------------
unsigned int __cdecl CTreeList::Sort(tagTreeViewChildItem *pChild, unsigned int a2, int (__cdecl *a3)(_DWORD, _DWORD, int, int), int a4, int a5, int a6)
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
    v8 = CTreeList::Sort(pChild, a2 >> 1, a3, a4, a5, a6);
    v9 = CTreeList::Sort(pChild, a2 - v7, a3, a4, a5, a6);
    a2 = 0;
    v10 = &a2;
    v11 = v9;
    if ( !v8 )
      goto LABEL_12;
    while ( v11 )
    {
      v12 = a3(*(_DWORD *)(v8 + 4), *(_DWORD *)(v11 + 4), a4, a5);
      if ( (_BYTE)a6 )
        v12 = -v12;
      if ( v12 > 0 )
      {
        *v10 = v11;
        v11 = *(_DWORD *)(v11 + 16);
      }
      else
      {
        *v10 = v8;
        v8 = *(_DWORD *)(v8 + 16);
      }
      v10 = (unsigned int *)(*v10 + 16);
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
    result = (unsigned int)pChild->m_TreeList;
    if ( pChild->m_TreeList )
    {
      pChild->m_TreeList = *(CTreeList **)(result + 16);
      *(_DWORD *)(result + 16) = 0;
    }
  }
  return result;
}

//----- (00C0F5C0) --------------------------------------------------------
LRESULT __stdcall CTreeList::Proxy_HeaderWndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
  CTreeList *v4; // eax
  LRESULT result; // eax

  v4 = (CTreeList *)GetPropW(hWnd, (LPCWSTR)(unsigned __int16)gAtomTreeListProperty);
  if ( v4 )
    result = CTreeList::HeaderWndProc(v4, hWnd, Msg, wParam, (tagNMLVGETINFOTIPW *)lParam);
  else
    result = CallWindowProcW(MEMORY[0xC8], hWnd, Msg, wParam, lParam);
  return result;
}
// CD4DA0: using guessed type __int16 gAtomTreeListProperty;

//----- (00C0F610) --------------------------------------------------------
LRESULT __stdcall CTreeList::Proxy_TooltipWndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
  CTreeList *v4; // eax
  LRESULT lResult; // ecx

  v4 = (CTreeList *)GetPropW(hWnd, (LPCWSTR)(unsigned __int16)gAtomTreeListProperty);
  lResult = 0;
  if ( Msg != WM_TIMER )
    return CallWindowProcW((WNDPROC)v4->m_TooltipWndProc, hWnd, Msg, wParam, lParam);
  if ( !v4->m_bSkipTimerForTooltip )
    lResult = CallWindowProcW((WNDPROC)v4->m_TooltipWndProc, hWnd, WM_TIMER, wParam, lParam);
  return lResult;
}
// CD4DA0: using guessed type __int16 gAtomTreeListProperty;

//----- (00C0F680) --------------------------------------------------------
HWND __stdcall CTreeList::WndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
  CTreeList *v4; // eax
  HWND result; // eax

  v4 = (CTreeList *)GetPropW(hWnd, (LPCWSTR)(unsigned __int16)gAtomTreeListProperty);
  if ( v4 )
    result = CTreeList::TreeWndProc(v4, hWnd, Msg, wParam, (NMLVDISPINFOW *)lParam);
  else
    result = (HWND)DefWindowProcW(hWnd, Msg, wParam, lParam);
  return result;
}
// CD4DA0: using guessed type __int16 gAtomTreeListProperty;

//----- (00C0F6C0) --------------------------------------------------------
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
  _mm_storeu_si128((__m128i *)&ScrollInfo.nMin, (__m128i)0i64);
  GetScrollInfo(v2, 2, &ScrollInfo);
  pChildren = pThis->m_ChildItem;
  nIndex = 0;
  if ( !pChildren )
    return 0;
  do
  {
    if ( nIndex >= ScrollInfo.nPos )
      break;
    if ( pChildren->m_Child && ((unsigned int)pChildren->m_dwStyle >> 4) & 1 )
    {
      pChildren = pChildren->m_Child;
    }
    else if ( pChildren->m_Sibling )
    {
      pChildren = pChildren->m_Sibling;
    }
    else
    {
      pCurrent = pChildren->m_Current;
      if ( pCurrent )
      {
        while ( !pCurrent->m_Sibling )
        {
          pCurrent = pCurrent->m_Current;
          if ( !pCurrent )
            goto LABEL_11;
        }
        pChildren = pCurrent->m_Sibling;
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

//----- (00C0F780) --------------------------------------------------------
int __thiscall CTreeList::GetRightScrollbarPos(CTreeList *this)
{
  HWND v1; // ST00_4
  struct tagSCROLLINFO v3; // [esp+0h] [ebp-20h]

  v3.cbSize = 28;
  v1 = this->m_hWndScrollBarRightRight;
  v3.nTrackPos = 0;
  _mm_storeu_si128((__m128i *)&v3.nMin, (__m128i)0i64);
  v3.fMask = 4;
  GetScrollInfo(v1, 2, &v3);
  return v3.nPos;
}

//----- (00C0F7D0) --------------------------------------------------------
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
  v4 = (HWND)sub_C0C8A0(this, &a2);
  v5 = hWnd;
  v6 = (WPARAM)v4;
  if ( hWnd == v4 )
    v7 = a2 == 0;
  else
    v7 = a3 == 0;
  v8 = (void (__stdcall *)(HWND, UINT, WPARAM, LPARAM))SendMessageW;
  v18 = v7;
  if ( (signed int)v4 >= 0 )
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
    SendMessageW(v9, HDM_GETITEMW, v6, (LPARAM)&lParam);
    if ( gbBitmapOnRight )
      v14 &= 0xFFFFF9FF;
    else
      v14 &= 0xFFFFE7FF;
    SendMessageW(hWnda, HDM_SETITEMW, v6, (LPARAM)&lParam);
    v8 = (void (__stdcall *)(HWND, UINT, WPARAM, LPARAM))SendMessageW;
  }
  if ( (signed int)v5 >= 0 )
  {
    if ( v5 )
    {
      v10 = v3->m_hWndHeaderRight;
      v5 = (HWND)((char *)v5 - 1);
    }
    else
    {
      v10 = v3->m_hWndHeaderLeft;
    }
    lParam = 36;
    v8(v10, HDM_GETITEMW, (WPARAM)v5, (LPARAM)&lParam);
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
    SendMessageW(v10, HDM_SETITEMW, (WPARAM)v5, (LPARAM)&lParam);
  }
  return v18;
}
// CDA8F8: using guessed type char gbBitmapOnRight;

//----- (00C0F8F0) --------------------------------------------------------
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
  CTreeList::HitTest(this, pt->x, pt->y, &xx, (int *)&nHeaderItemCount, &pChild);
  v4 = pChild;
  result = nHeaderItemCount;
  if ( v3->field_AC != pChild || nHeaderItemCount != v3->m_nHeaderItemCount )
  {
    v3->m_nHeaderItemCount = nHeaderItemCount;
    v3->field_A8 = xx;
    v3->field_AC = v4;
    result = SendMessageW(hWnd, TTM_POP, 0, 0);
  }
  return result;
}

//----- (00C0F970) --------------------------------------------------------
unsigned int __thiscall CTreeList::UpdateVScrollBars(CTreeList *this, int nPos)
{
  CTreeList *v2; // ebx
  unsigned int result; // eax
  int v4; // esi
  int v5; // edi
  int v6; // [esp+4h] [ebp-54h]
  struct tagRECT v7; // [esp+8h] [ebp-50h]
  struct tagRECT Rect; // [esp+18h] [ebp-40h]
  LONG prcScroll; // [esp+28h] [ebp-30h]
  int v10; // [esp+2Ch] [ebp-2Ch]
  LONG v11; // [esp+30h] [ebp-28h]
  LONG v12; // [esp+34h] [ebp-24h]
  SCROLLINFO ScrollInfo; // [esp+38h] [ebp-20h]

  v2 = this;
  result = (unsigned int)GetWindowLongW(this->m_hWndScrollBarRightRight, GWL_STYLE) >> 28;
  if ( result & 1 )
  {
    ScrollInfo.cbSize = 28;
    ScrollInfo.nTrackPos = 0;
    ScrollInfo.fMask = 4;
    _mm_storeu_si128((__m128i *)&ScrollInfo.nMin, (__m128i)0i64);
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
      prcScroll = Rect.left;
      GetWindowRect(v2->m_hWndHeaderLeft, &v7);
      v10 = v7.bottom - v7.top;
      v11 = Rect.right;
      v12 = Rect.bottom;
      result = ScrollWindowEx(v2->m_hWnd, 0, v4 * v5, (const RECT *)&prcScroll, 0, 0, 0, 2u);
    }
  }
  return result;
}

//----- (00C0FA80) --------------------------------------------------------
unsigned int __userpurge CTreeList::SetVScrollPos@<eax>(CTreeList *this@<ecx>, int a2, int a3)
{
  CTreeList *v3; // esi
  HWND v4; // ST00_4
  SCROLLINFO v6; // [esp+0h] [ebp-20h]

  _mm_storeu_si128((__m128i *)&v6.nMin, (__m128i)0i64);
  v6.nPos = a2;
  v3 = this;
  v6.cbSize = 28;
  v4 = this->m_hWndScrollBarRightRight;
  v6.nTrackPos = 0;
  v6.fMask = 4;
  SetScrollInfo(v4, 2, &v6, 1);
  return CTreeList::UpdateVScrollBars(v3, 0);
}

//----- (00C0FAF0) --------------------------------------------------------
HWND __thiscall CTreeList::TreeWndProc(CTreeList *this, HWND hWndIn, UINT Msg, WPARAM wParamIn, NMLVDISPINFOW *lParam)
{
  CTreeList *This; // esi
  NMHEADERW *lParamIn; // edi
  HWND result; // eax
  HWND v8; // ST18_4
  unsigned int uMsg; // ecx
  signed int nHitTest; // eax
  int v11; // ecx
  int v12; // edx
  int v13; // edi
  int v14; // edi
  HWND v15; // ST10_4
  int v16; // eax
  bool v17; // zf
  HCURSOR v18; // ecx
  int v19; // eax
  HWND v20; // edx
  HWND v21; // eax
  HCURSOR v22; // ST1C_4
  LRESULT v23; // eax
  HWND v24; // edi
  WPARAM v25; // ecx
  BOOL v26; // edi
  HWND v27; // ST10_4
  HWND v28; // ST10_4
  HRGN v29; // eax
  HWND v30; // edi
  HWND v31; // eax
  UINT nmcode; // eax
  tagTreeViewChildItem *v33; // ST14_4
  tagTreeViewChildItem *v34; // eax
  HWND v35; // ST14_4
  HWND v36; // ST1C_4
  HDC v37; // eax
  HFONT v38; // ST1C_4
  HGDIOBJ v39; // edi
  void *v40; // ST1C_4
  HDC v41; // edi
  const WCHAR **v42; // ecx
  HWND hWndFrom; // ecx
  HWND v44; // edx
  UINT nCode; // eax
  int v46; // eax
  int v47; // eax
  BOOL v48; // eax
  int v49; // eax
  int v50; // edi
  HDITEMW *pHeaderItem; // eax
  int nItem; // edx
  int iHeaderItem; // edi
  LONG v54; // eax
  LONG v55; // eax
  WPARAM v56; // ST18_4
  HWND v57; // eax
  int v58; // edi
  int v59; // eax
  tagTreeViewChildItem *v60; // ecx
  tagTreeViewChildItem *v61; // eax
  int v62; // edi
  HWND v63; // ST14_4
  tagTreeViewChildItem *v64; // edi
  tagTreeViewChildItem *v65; // eax
  tagTreeViewChildItem *v66; // eax
  int v67; // edi
  tagTreeViewChildItem *v68; // ecx
  unsigned int v69; // edx
  unsigned int v70; // eax
  int v71; // edx
  int v72; // edi
  __int32 v73; // ecx
  int v74; // ecx
  _bstr_t *v75; // eax
  tagTreeViewChildItem *v76; // eax
  tagTreeViewChildItem *v77; // edx
  int v78; // eax
  _DWORD *v79; // eax
  size_t v80; // eax
  int v81; // eax
  HWND v82; // ST14_4
  int v83; // edi
  LONG v84; // ecx
  int v85; // [esp-14h] [ebp-2E0h]
  int v86; // [esp-10h] [ebp-2DCh]
  tagTreeViewChildItem *v87; // [esp-Ch] [ebp-2D8h]
  int v88; // [esp+0h] [ebp-2CCh]
  _bstr_t v89; // [esp+Ch] [ebp-2C0h]
  LPARAM v90; // [esp+10h] [ebp-2BCh]
  int pnItem; // [esp+14h] [ebp-2B8h]
  NMLVDISPINFOW *LPARAM; // [esp+18h] [ebp-2B4h]
  int pnSubItem; // [esp+1Ch] [ebp-2B0h]
  bool v94; // [esp+23h] [ebp-2A9h]
  tagTreeViewChildItem *pThis; // [esp+24h] [ebp-2A8h]
  tagTreeViewChildItem *ppChild; // [esp+28h] [ebp-2A4h]
  HWND hWnd; // [esp+2Ch] [ebp-2A0h]
  WPARAM wParam; // [esp+30h] [ebp-29Ch]
  int left; // [esp+34h] [ebp-298h]
  RECT rcScroll; // [esp+38h] [ebp-294h]
  int v101; // [esp+48h] [ebp-284h]
  HWND hWndInsertAfter; // [esp+4Ch] [ebp-280h]
  RECT rcHeader; // [esp+54h] [ebp-278h]
  int Paint; // [esp+64h] [ebp-268h]
  LPARAM v105; // [esp+74h] [ebp-258h]
  LPARAM v106; // [esp+78h] [ebp-254h]
  HWND v107; // [esp+7Ch] [ebp-250h]
  struct tagRECT v108; // [esp+84h] [ebp-248h]
  RECT rcClient; // [esp+94h] [ebp-238h]
  RECT Rect; // [esp+A4h] [ebp-228h]
  char v111; // [esp+B4h] [ebp-218h]
  int v112; // [esp+2C8h] [ebp-4h]

  This = this;
  lParamIn = (NMHEADERW *)lParam;
  hWnd = hWndIn;
  wParam = wParamIn;
  LPARAM = lParam;
  if ( Msg - LVM_FIRST <= 0xFF )
    return CTreeList::HandleListViewMsg(this, hWnd, Msg, wParamIn, (UINT *)lParam);
  if ( Msg - WM_MOUSEFIRST <= 0xD )
  {
    Rect.right = (signed __int16)lParam;
    Rect.bottom = SHIWORD(lParam);
    v108.top = (LONG)hWnd;
    v8 = this->m_hWndTooltipOfTreeList;
    v108.bottom = wParamIn;
    v108.right = Msg;
    rcClient.left = (LONG)lParam;
    *(_QWORD *)&rcClient.top = 0i64;
    rcClient.bottom = 0;
    CTreeList::PopTooltip(this, v8, (POINT *)&Rect.right);
    SendMessageW(This->m_hWndTooltipOfTreeList, TTM_RELAYEVENT, 0, (LPARAM)&v108.top);
  }
  uMsg = Msg;
  if ( Msg == WM_LBUTTONDOWN )
  {
    if ( This->field_BC )
    {
      left = (signed __int16)lParam;
      if ( abs((signed __int16)lParam - This->m_nBottomScrollBarWidthOrHeight) <= 8 )
      {
        SetCapture(hWnd);
        SetCursor(This->m_hCursor);
        This->m_ptDownLast.x = left;
LABEL_9:
        SetFocus(hWnd);
        Rect.bottom = 0;
        ppChild = 0;
        nHitTest = CTreeList::HitTest(This, (signed __int16)lParam, SHIWORD(lParam), &Rect.bottom, 0, &ppChild);
        Rect.bottom = nHitTest;
        if ( nHitTest & 0xE0 )
        {
          CTreeList::SendNotify(This, This->m_hWnd, -2, 0, ppChild, 0, 0);
          LOWORD(nHitTest) = Rect.bottom;
        }
        if ( nHitTest & 0x40 )
        {
          CTreeList::OnMsg2001(This, ppChild, ~(unsigned __int8)((unsigned int)ppChild->m_dwStyle >> 4) & 1);
        }
        else if ( nHitTest & 0x1E0 )
        {
          CTreeList::RedrawChild(This, ppChild);
        }
        return (HWND)This->baseclass.vtptr->HandleMessage(This, hWnd, Msg, wParam, (tagMSG2004Item *)lParamIn);
      }
      goto LABEL_40;
    }
LABEL_32:
    v20 = hWnd;
    goto LABEL_33;
  }
  if ( Msg == WM_MOUSEMOVE )
  {
    if ( This->field_BC )
    {
      ppChild = (tagTreeViewChildItem *)(signed __int16)lParam;
      if ( GetCapture() == hWnd && wParam & 1 )
      {
        v11 = (int)ppChild - This->m_ptDownLast.x;
        if ( ppChild != (tagTreeViewChildItem *)This->m_ptDownLast.x )
        {
          v12 = This->m_nBottomScrollBarWidthOrHeight;
          v13 = This->m_nHeaderHeight;
          if ( v12 + v11 < v13 )
            v11 = v13 - v12;
          This->m_ptDownLast.x += v11;
          v14 = v12 + v11;
          CTreeList::MoveHeaders(This, v12 + v11);
          v106 = 1;
          v15 = This->m_hWndHeaderLeft;
          v107 = (HWND)v14;
          SendMessageW(v15, HDM_SETITEMW, 0, (LPARAM)&v106);
          CTreeList::Resize(This);
          lParamIn = (NMHEADERW *)LPARAM;
        }
        SetCursor(This->m_hCursor);
        uMsg = WM_MOUSEMOVE;
        goto ___WM_RBUTTONDOWN;
      }
      if ( abs((char *)ppChild - This->m_nBottomScrollBarWidthOrHeight) <= 8 )
      {
        SetCursor(This->m_hCursor);
        uMsg = WM_MOUSEMOVE;
        goto ___WM_RBUTTONDOWN;
      }
      v16 = GetClassLongW(This->m_hWnd, -12);
      v17 = This->m_pfnGetChildCursor == 0;
      v18 = (HCURSOR)v16;
      left = v16;
      if ( !v17 )
      {
        pnItem = 0;
        pnSubItem = 0;
        pThis = 0;
        CTreeList::HitTest(This, (LONG)ppChild, SHIWORD(lParam), &pnItem, &pnSubItem, &pThis);
        if ( pThis )
        {
          v19 = ((int (__cdecl *)(tagTreeViewChildItem *, int))This->m_pfnGetChildCursor)(pThis, pnSubItem);
          v18 = (HCURSOR)left;
          if ( v19 )
            v18 = (HCURSOR)v19;
        }
        else
        {
          v18 = (HCURSOR)left;
        }
      }
      SetCursor(v18);
      goto LABEL_31;
    }
    goto LABEL_32;
  }
  if ( Msg != WM_LBUTTONUP || !This->field_BC )
    goto LABEL_32;
  v21 = GetCapture();
  v20 = hWnd;
  if ( v21 == hWnd )
  {
    ReleaseCapture();
LABEL_40:
    v22 = (HCURSOR)GetClassLongW(This->m_hWnd, GCL_HCURSOR);
    SetCursor(v22);
LABEL_31:
    uMsg = Msg;
    goto LABEL_32;
  }
  uMsg = WM_LBUTTONUP;
LABEL_33:
  if ( uMsg > WM_KEYDOWN )
  {
    if ( uMsg > WM_MOUSEWHEEL )
    {
      switch ( uMsg )
      {
        case TREELIST_MSG_2000:
          CTreeList::OnMsg2000((tagTreeViewChildItem *)wParam, lParam != 0);
          return 0;
        case TREELIST_MSG_2001:
          return (HWND)(unsigned __int8)CTreeList::OnMsg2001(This, (tagTreeViewChildItem *)wParam, lParam != 0);
        case TREELIST_MSG_2002:
          return *(HWND *)(wParam + 28);
        case TREELIST_MSG_2003:
          CTreeList::RefreshChildItem(This, (tagTreeViewChildItem *)wParam);
          return 0;
        case TREELIST_MSG_2004:
          return (HWND)CTreeList::OnMsg2004(
                         (tagTreeViewChildItem *)lParam->hdr.hwndFrom,
                         (tagTREEVIEWLISTITEMPARAM *)lParam->hdr.idFrom,
                         lParam->hdr.code);
        case TREELIST_MSG_2005:
          return (HWND)CTreeList::FindChild(This, (tagTreeViewChildItem *)wParam);
        default:
          goto __WM_THEMECHANGED;
      }
      goto __WM_THEMECHANGED;
    }
    if ( uMsg == WM_MOUSEWHEEL )
    {
      Rect.bottom = This->m_nLastVScrollPos2 + SHIWORD(wParam);
      v84 = Rect.bottom;
      This->m_nLastVScrollPos2 = Rect.bottom;
      if ( abs(v84) >= 40 )
      {
        This->m_nLastVScrollPos2 = Rect.bottom - 40 * (v84 / 40);
        CTreeList::UpdateVScrollBars(This, Rect.bottom / -40);
      }
      return (HWND)This->baseclass.vtptr->HandleMessage(This, hWnd, Msg, wParam, (tagMSG2004Item *)lParamIn);
    }
    if ( uMsg <= WM_VSCROLL )
    {
      if ( uMsg == WM_VSCROLL )
      {
        v108.top = 28;
        v82 = This->m_hWndScrollBarRightRight;
        rcClient.bottom = 0;
        _mm_storeu_si128((__m128i *)&v108.bottom, (__m128i)0i64);
        v108.right = 7;
        GetScrollInfo(v82, 2, (LPSCROLLINFO)&v108.top);
        switch ( (unsigned __int16)wParam )
        {
          case 0u:
            --rcClient.right;
            CTreeList::SetVScrollPos(This, rcClient.right, v88);
            return (HWND)This->baseclass.vtptr->HandleMessage(This, hWnd, Msg, wParam, (tagMSG2004Item *)lParamIn);
          case VK_LBUTTON:
            ++rcClient.right;
            CTreeList::SetVScrollPos(This, rcClient.right, v88);
            return (HWND)This->baseclass.vtptr->HandleMessage(This, hWnd, Msg, wParam, (tagMSG2004Item *)lParamIn);
          case VK_RBUTTON:
            rcClient.right -= rcClient.top;
            CTreeList::SetVScrollPos(This, rcClient.right, v88);
            return (HWND)This->baseclass.vtptr->HandleMessage(This, hWnd, Msg, wParam, (tagMSG2004Item *)lParamIn);
          case VK_CANCEL:
            rcClient.right += rcClient.top;
            CTreeList::SetVScrollPos(This, rcClient.right, v88);
            return (HWND)This->baseclass.vtptr->HandleMessage(This, hWnd, Msg, wParam, (tagMSG2004Item *)lParamIn);
          case VK_MBUTTON:
          case VK_XBUTTON1:
            rcClient.right = wParam >> 16;
            CTreeList::SetVScrollPos(This, wParam >> 16, v88);
            return (HWND)This->baseclass.vtptr->HandleMessage(This, hWnd, Msg, wParam, (tagMSG2004Item *)lParamIn);
          case VK_XBUTTON2:
            rcClient.right = 0;
            CTreeList::SetVScrollPos(This, 0, v88);
            return (HWND)This->baseclass.vtptr->HandleMessage(This, hWnd, Msg, wParam, (tagMSG2004Item *)lParamIn);
          case VK_XBUTTON2|VK_LBUTTON:
            rcClient.right = rcClient.left;
            CTreeList::SetVScrollPos(This, rcClient.left, v88);
            return (HWND)This->baseclass.vtptr->HandleMessage(This, hWnd, Msg, wParam, (tagMSG2004Item *)lParamIn);
          case VK_BACK:
            return (HWND)1;
          default:
            return 0;
        }
        return 0;
      }
      v73 = uMsg - WM_CHAR;
      if ( !v73 )
      {
        // WM_CHAR
        if ( This->m_nChildCount )
        {
          pnItem = GetTickCount();
          if ( (unsigned int)(pnItem - This->m_dwTickCountLast) > 0x2EE )
            _bstr_t::operator=((_bstr_t *)&This->m_KeyName, gszStatusBarText);
          if ( !This->m_ChildLast
            || ((v75 = _bstr_t::_bstr_t(&v89, gszStatusBarText),
                 v94 = _bstr_t::operator==((_bstr_t *)&This->m_KeyName, v75),
                 _bstr_t::_Free(&v89),
                 !v94) ? (v76 = This->m_ChildLast) : (v76 = TreeViewChildItem_GetNextChild(This->m_ChildLast)),
                (pThis = v76) == 0) )
          {
            pThis = This->m_ChildItem;
          }
          This->m_dwTickCountLast = pnItem;
          left = (unsigned __int16)wParam;
          _bstr_t::_bstr_t((tagEventSetItem *)&pnSubItem, (OLECHAR *)&left);
          v112 = 0;
          _bstr_t::operator+=((_bstr_t *)&This->m_KeyName, (_bstr_t *)&pnSubItem);
          v112 = -1;
          _bstr_t::_Free((_bstr_t *)&pnSubItem);
          v77 = pThis;
          ppChild = pThis;
          while ( 1 )
          {
            Rect.bottom = 260;
            v78 = ((int (__stdcall *)(tagTreeViewChildItem *, _DWORD, char *, LONG *))v77->m_TreeListData->vtptr->GetItemText)(
                    v77,
                    0,
                    &v111,
                    &Rect.bottom);
            lParamIn = (NMHEADERW *)LPARAM;
            pnItem = v78;
            v79 = (_DWORD *)This->m_KeyName;
            pnSubItem = v79 ? *v79 : 0;
            v80 = _bstr_t::length((tagEventItem *)&This->m_KeyName);
            if ( !_wcsnicmp((const wchar_t *)pnItem, (const wchar_t *)pnSubItem, v80) )
              break;
            v77 = TreeViewChildItem_GetNextChild(ppChild);
            ppChild = v77;
            if ( !v77 )
            {
              v77 = This->m_ChildItem;
              ppChild = This->m_ChildItem;
            }
            if ( v77 == pThis )
              return (HWND)This->baseclass.vtptr->HandleMessage(This, hWnd, Msg, wParam, (tagMSG2004Item *)lParamIn);
          }
          CTreeList::RedrawChild(This, ppChild);
          v81 = CTreeList::FindChild(This, ppChild);
          CTreeList::EnsureVisible(This, v81);
        }
        return (HWND)This->baseclass.vtptr->HandleMessage(This, hWnd, Msg, wParam, (tagMSG2004Item *)lParamIn);
      }
      v74 = v73 - 17;
      if ( !v74 )
      {
        // WM_TIMER
        if ( wParam == 100 )
        {
          GetCursorPos((LPPOINT)&Rect.right);
          MapWindowPoints(0, hWnd, (LPPOINT)&Rect.right, 1u);
          CTreeList::PopTooltip(This, This->m_hWndTooltipOfTreeList, (POINT *)&Rect.right);
        }
        return (HWND)This->baseclass.vtptr->HandleMessage(This, hWnd, Msg, wParam, (tagMSG2004Item *)lParamIn);
      }
      if ( v74 == 1 )
      {
        // WM_HSCROLL
        if ( !lParam )
          return (HWND)This->baseclass.vtptr->HandleMessage(This, hWnd, Msg, wParam, (tagMSG2004Item *)lParamIn);
        v108.top = 28;
        rcClient.bottom = 0;
        _mm_storeu_si128((__m128i *)&v108.bottom, (__m128i)0i64);
        v108.right = 7;
        GetScrollInfo((HWND)lParam, 2, (LPSCROLLINFO)&v108.top);
        switch ( (unsigned __int16)wParam )
        {
          case 0u:
            --rcClient.right;
            CTreeList::SetHScrollPos(This, (HWND)lParam, rcClient.right);
            return (HWND)This->baseclass.vtptr->HandleMessage(This, hWnd, Msg, wParam, (tagMSG2004Item *)lParamIn);
          case VK_LBUTTON:
            ++rcClient.right;
            CTreeList::SetHScrollPos(This, (HWND)lParam, rcClient.right);
            return (HWND)This->baseclass.vtptr->HandleMessage(This, hWnd, Msg, wParam, (tagMSG2004Item *)lParamIn);
          case VK_RBUTTON:
            rcClient.right -= rcClient.top;
            CTreeList::SetHScrollPos(This, (HWND)lParam, rcClient.right);
            return (HWND)This->baseclass.vtptr->HandleMessage(This, hWnd, Msg, wParam, (tagMSG2004Item *)lParamIn);
          case VK_CANCEL:
            rcClient.right += rcClient.top;
            CTreeList::SetHScrollPos(This, (HWND)lParam, rcClient.right);
            return (HWND)This->baseclass.vtptr->HandleMessage(This, hWnd, Msg, wParam, (tagMSG2004Item *)lParamIn);
          case VK_MBUTTON:
          case VK_XBUTTON1:
            rcClient.right = wParam >> 16;
            CTreeList::SetHScrollPos(This, (HWND)lParam, wParam >> 16);
            return (HWND)This->baseclass.vtptr->HandleMessage(This, hWnd, Msg, wParam, (tagMSG2004Item *)lParamIn);
          case VK_XBUTTON2:
            rcClient.right = 0;
            CTreeList::SetHScrollPos(This, (HWND)lParam, 0);
            return (HWND)This->baseclass.vtptr->HandleMessage(This, hWnd, Msg, wParam, (tagMSG2004Item *)lParamIn);
          case VK_XBUTTON2|VK_LBUTTON:
            rcClient.right = rcClient.left;
            CTreeList::SetHScrollPos(This, (HWND)lParam, rcClient.left);
            return (HWND)This->baseclass.vtptr->HandleMessage(This, hWnd, Msg, wParam, (tagMSG2004Item *)lParamIn);
          case VK_BACK:
            return (HWND)1;
          default:
            return 0;
        }
        return 0;
      }
__WM_THEMECHANGED:
      if ( Msg == WM_THEMECHANGED )
      {
        if ( This->baseclass.m_hThemeHandle )
          gpfnCloseThemeData(This->baseclass.m_hThemeHandle);
        This->baseclass.m_hThemeHandle = 0;
        if ( gpfnIsThemeActive && gpfnIsThemeActive() )
        {
          v47 = ((int (__thiscall *)(CTreeList *))This->baseclass.vtptr->GetName)(This);
          This->baseclass.m_hThemeHandle = (HTHEME)gpfnOpenThemeData(hWnd, v47);
        }
      }
__HandleMessage:
      lParamIn = (NMHEADERW *)LPARAM;
      return (HWND)This->baseclass.vtptr->HandleMessage(This, hWnd, Msg, wParam, (tagMSG2004Item *)lParamIn);
    }
    if ( uMsg == WM_LBUTTONDOWN )
      goto LABEL_9;
___WM_RBUTTONDOWN:
    if ( uMsg - WM_LBUTTONDBLCLK <= 1 )
    {
      // WM_RBUTTONDOWN
      Rect.bottom = 0;
      pnSubItem = 0;
      left = 0;
      if ( CTreeList::HitTest(
             This,
             (signed __int16)lParamIn,
             SHIWORD(lParamIn),
             &Rect.bottom,
             &pnSubItem,
             (tagTreeViewChildItem **)&left) & 0xE0 )
      {
        v83 = left;
        CTreeList::RedrawChild(This, (tagTreeViewChildItem *)left);
        v87 = (tagTreeViewChildItem *)v83;
        v86 = pnSubItem;
        v85 = 2 * (Msg == 515) - 5;
__SendNotify:
        CTreeList::SendNotify(This, This->m_hWnd, v85, v86, v87, 0, 0);
      }
    }
    goto __WM_THEMECHANGED;
  }
  if ( uMsg == WM_KEYDOWN )
  {
    v17 = LOBYTE(This->m_ptDownLast.y) == 0;
    v54 = TVN_7D7;
    v108.bottom = (LONG)v20;
    if ( !v17 )
      v54 = LVN_KEYDOWN;
    rcClient.top = v54;
    v55 = GetWindowLongW(v20, -12);
    LOWORD(rcClient.right) = wParam;
    v56 = v55;
    rcClient.left = v55;
    *(LONG *)((char *)&rcClient.right + 2) = 0;
    v57 = GetParent(hWnd);
    SendMessageW(v57, WM_NOTIFY, v56, (LPARAM)&v108.bottom);
    switch ( wParam )
    {
      case VK_PRIOR:
      case VK_NEXT:
        pThis = This->m_ChildLast;
        if ( !pThis )
          return (HWND)This->baseclass.vtptr->HandleMessage(This, hWnd, Msg, wParam, (tagMSG2004Item *)lParamIn);
        v108.top = 28;
        v63 = This->m_hWndScrollBarRightRight;
        rcClient.bottom = 0;
        _mm_storeu_si128((__m128i *)&v108.bottom, (__m128i)0i64);
        v108.right = 2;
        GetScrollInfo(v63, 2, (LPSCROLLINFO)&v108.top);
        left = 0;
        if ( !rcClient.top )
          goto LABEL_149;
        v64 = pThis;
        break;
      case VK_LEFT:
      case VK_RIGHT:
        v68 = This->m_ChildLast;
        if ( !v68 )
          return (HWND)This->baseclass.vtptr->HandleMessage(This, hWnd, Msg, wParam, (tagMSG2004Item *)lParamIn);
        v69 = v68->m_dwStyle;
        v70 = v68->m_dwStyle;
        if ( wParam == 39 )
        {
          if ( !((v70 >> 6) & 1) )
            return (HWND)This->baseclass.vtptr->HandleMessage(This, hWnd, Msg, wParam, (tagMSG2004Item *)lParamIn);
          if ( !((v69 >> 4) & 1) )
          {
            CTreeList::OnMsg2001(This, v68, 1);
            return (HWND)This->baseclass.vtptr->HandleMessage(This, hWnd, Msg, wParam, (tagMSG2004Item *)lParamIn);
          }
          return CTreeList::TreeWndProc(This, hWnd, 0x100u, 0x28u, 0);
        }
        if ( (v70 >> 4) & 1 && (v69 >> 6) & 1 )
        {
          CTreeList::OnMsg2001(This, v68, 0);
          return (HWND)This->baseclass.vtptr->HandleMessage(This, hWnd, Msg, wParam, (tagMSG2004Item *)lParamIn);
        }
        v71 = (int)v68->m_Current;
        pnItem = v71;
        if ( v71 && (tagTreeViewChildItem **)v71 != &This->m_Item_40 )
        {
          v72 = CTreeList::FindChild(This, v68);
          CTreeList::RedrawChild(This, (tagTreeViewChildItem *)pnItem);
          CTreeList::EnsureVisible(This, v72);
          goto __HandleMessage;
        }
        return (HWND)This->baseclass.vtptr->HandleMessage(This, hWnd, Msg, wParam, (tagMSG2004Item *)lParamIn);
      case VK_UP:
      case VK_DOWN:
        v60 = This->m_ChildLast;
        if ( !v60 )
          return (HWND)This->baseclass.vtptr->HandleMessage(This, hWnd, Msg, wParam, (tagMSG2004Item *)lParamIn);
        v61 = wParam == VK_DOWN ? TreeViewChildItem_GetNextChild(v60) : sub_C0E9D0(v60);
        left = (int)v61;
        if ( !v61 )
          return (HWND)This->baseclass.vtptr->HandleMessage(This, hWnd, Msg, wParam, (tagMSG2004Item *)lParamIn);
        v62 = CTreeList::FindChild(This, v61);
        CTreeList::RedrawChild(This, (tagTreeViewChildItem *)left);
        CTreeList::EnsureVisible(This, v62);
        goto __HandleMessage;
      case VK_ADD:
        if ( GetKeyState(VK_LCONTROL) )
        {
          if ( SendMessageW(This->m_hWndHeaderRight, HDM_GETITEMCOUNT, 0, 0) + 1 > 0 )
          {
            v58 = 0;
            do
            {
              if ( v58 || !This->m_bValue1 )
                v59 = CTreeList::GetChildWidth(This, v58);
              else
                v59 = This->m_nChildWidthLast;
              CTreeList::UpdateColumnHeight(v58++, v59);
            }
            while ( v58 < SendMessageW(This->m_hWndHeaderRight, HDM_GETITEMCOUNT, 0, 0) + 1 );
            lParamIn = (NMHEADERW *)LPARAM;
          }
          CTreeList::Resize(This);
        }
        return (HWND)This->baseclass.vtptr->HandleMessage(This, hWnd, Msg, wParam, (tagMSG2004Item *)lParamIn);
      default:
        return (HWND)This->baseclass.vtptr->HandleMessage(This, hWnd, Msg, wParam, (tagMSG2004Item *)lParamIn);
    }
    do
    {
      if ( wParam == VK_NEXT )
      {
        v65 = TreeViewChildItem_GetNextChild(v64);
        if ( !v65 )
          break;
        v64 = v65;
        pThis = v65;
      }
      else
      {
        v66 = sub_C0E9D0(v64);
        if ( !v66 )
          break;
        v64 = v66;
        pThis = v66;
      }
      ++left;
    }
    while ( (unsigned int)left < rcClient.top );
    lParamIn = (NMHEADERW *)LPARAM;
LABEL_149:
    if ( !pThis )
      return (HWND)This->baseclass.vtptr->HandleMessage(This, hWnd, Msg, wParam, (tagMSG2004Item *)lParamIn);
    v67 = CTreeList::FindChild(This, pThis);
    CTreeList::RedrawChild(This, pThis);
    CTreeList::EnsureVisible(This, v67);
    goto __HandleMessage;
  }
  switch ( uMsg )
  {
    case 2u:
      CTreeList::OnDestroy(This);
      goto __WM_THEMECHANGED;
    case 5u:
      CTreeList::Resize(This);
      CTreeList::RepositionHeaders();
      CTreeList::RepositionTooltips();
      v31 = This->m_hWnd;
      v105 = 48;
      _mm_storeu_si128((__m128i *)&v107, (__m128i)0i64);
      v106 = 0;
      _mm_storeu_si128((__m128i *)&v108.right, (__m128i)0i64);
      v107 = v31;
      *(_QWORD *)&rcClient.right = 0i64;
      GetClientRect(v31, &v108);
      SendMessageW(This->m_hWndTooltipOfTreeList, 0x434u, 0, (LPARAM)&v105);
      goto __WM_THEMECHANGED;
    case WM_SETFOCUS:
    case WM_KILLFOCUS:
      if ( This->m_ChildLast )
        CTreeList::RefreshChildItem(This, This->m_ChildLast);
      goto __WM_THEMECHANGED;
    case WM_SETREDRAW:
      if ( wParam )
      {
        v23 = DefWindowProcW(v20, uMsg, wParam, (LPARAM)lParam);
        This->m_bSkipTimerForTooltip = 0;
        v24 = (HWND)v23;
        CTreeList::Refresh(This);
        result = v24;
      }
      else
      {
        This->m_bSkipTimerForTooltip = 1;
        result = (HWND)DefWindowProcW(v20, uMsg, 0, (LPARAM)lParam);
      }
      return result;
    case WM_PAINT:
      v29 = CreateRectRgn(0, 0, 0, 0);
      v30 = hWnd;
      left = (int)v29;
      if ( GetUpdateRgn(hWnd, v29, 0) != 1 )
      {
        BeginPaint(v30, (LPPAINTSTRUCT)&Paint);
        CTreeList::DrawTree(This, (LPPAINTSTRUCT)&Paint, (HRGN)left);
        EndPaint(v30, (const PAINTSTRUCT *)&Paint);
      }
      DeleteObject((HGDIOBJ)left);
      return 0;
    case WM_ERASEBKGND:
      return (HWND)1;
    case WM_SETCURSOR:
      if ( (HWND)wParam != v20 )
        goto __WM_THEMECHANGED;
      return (HWND)1;
    case WM_SETFONT:
      v25 = wParam;
      This->m_Font = (HFONT)wParam;
      v26 = (_WORD)lParam != 0;
      v27 = This->m_hWndHeaderLeft;
      v94 = (_WORD)lParam != 0;
      SendMessageW(v27, 0x30u, v25, v26);
      SendMessageW(This->m_hWndHeaderRight, 0x30u, (WPARAM)This->m_Font, v26);
      SendMessageW(This->m_hWndTooltipOfTreeList, 0x30u, (WPARAM)This->m_Font, v26);
      SendMessageW(This->m_hWndTooltipOfLeftHeader, 0x30u, (WPARAM)This->m_Font, v26);
      SendMessageW(This->m_hWndTooltipOfRightHeader, 0x30u, (WPARAM)This->m_Font, v26);
      GetClientRect(This->m_hWnd, &rcClient);
      v101 = 0;
      v90 = (LPARAM)&rcClient;
      *(_QWORD *)&rcHeader.right = 0i64;
      pnItem = (int)&v101;
      v28 = This->m_hWndHeaderLeft;
      _mm_storeu_si128((__m128i *)&hWndInsertAfter, (__m128i)0i64);
      SendMessageW(v28, 0x1205u, 0, (LPARAM)&v90);
      SetWindowPos(
        This->m_hWndHeaderLeft,
        hWndInsertAfter,
        0,
        0,
        This->m_nBottomScrollBarWidthOrHeight,
        rcHeader.right,
        rcHeader.bottom | 0x40);
      SetWindowPos(
        This->m_hWndHeaderRight,
        This->m_hWndHeaderLeft,
        This->m_nBottomScrollBarWidthOrHeight,
        0,
        rcHeader.top - This->m_nBottomScrollBarWidthOrHeight,
        rcHeader.right,
        rcHeader.bottom | 0x40);
      if ( !v94 )
        return 0;
      CTreeList::Refresh(This);
      return 0;
    case 0x4Eu:
      // WM_NOTIFY
      if ( lParam->hdr.hwndFrom != This->m_hWndTooltipOfTreeList )
        goto LABEL_69;
      nmcode = lParam->hdr.code;
      if ( nmcode == TTN_GETDISPINFOW )
      {
        if ( This->field_AC )
        {
          pThis = (tagTreeViewChildItem *)&lParam->item;
          lParam->item.mask = (UINT)&lParam->item.iItem;
          v33 = This->field_AC;
          left = (int)&lParam->item.iItem;
          if ( CTreeList::SendNotify(This, This->m_hWnd, 2004, This->m_nHeaderItemCount, v33, 0, (int)&lParam->item) )
            return 0;
          v34 = This->field_AC;
          pnItem = 80;
          pnSubItem = ((int (__stdcall *)(tagTreeViewChildItem *, int, int, int *))v34->m_TreeListData->vtptr->GetItemText)(
                        v34,
                        This->m_nHeaderItemCount,
                        left,
                        &pnItem);
          rcHeader.left = 0;
          rcHeader.top = 0;
          rcHeader.right = GetSystemMetrics(SM_CXVIRTUALSCREEN);
          rcHeader.bottom = CTreeList::GetLineHeight(This);
          CTreeList::GetSubItemRect(This, This->field_A8, This->m_nHeaderItemCount, 1, 1, This->field_AC, &rcScroll);
          v108.top = 28;
          v35 = This->m_hWndScrollBarRightBottom;
          rcClient.bottom = 0;
          _mm_storeu_si128((__m128i *)&v108.bottom, (__m128i)0i64);
          v108.right = 4;
          GetScrollInfo(v35, 2, (LPSCROLLINFO)&v108.top);
          if ( rcScroll.left == This->m_nBottomScrollBarWidthOrHeight )
          {
            if ( rcClient.right )
              return 0;
          }
          v36 = This->m_hWnd;
          ppChild = (tagTreeViewChildItem *)(This->m_Format & 0xFFFB3FFF | 0x400);
          v37 = GetDC(v36);
          v38 = This->m_Font;
          left = (int)v37;
          v39 = SelectObject(v37, v38);
          DrawTextW((HDC)left, (LPCWSTR)pnSubItem, -1, &rcHeader, (UINT)ppChild);
          v40 = v39;
          v41 = (HDC)left;
          SelectObject((HDC)left, v40);
          ReleaseDC(This->m_hWnd, v41);
          v42 = &gszNullString;
          lParamIn = (NMHEADERW *)LPARAM;
          if ( rcHeader.right - rcHeader.left > rcScroll.right - rcScroll.left )
            v42 = (const WCHAR **)pnSubItem;
          pThis->m_TreeList = (CTreeList *)v42;
        }
        else
        {
          lParam->item.mask = (UINT)&gszNullString;
        }
      }
      else if ( nmcode == TTN_SHOW )
      {
        CTreeList::GetSubItemRect(This, This->field_A8, This->m_nHeaderItemCount, 0, 1, This->field_AC, &rcHeader);
        SendMessageW(This->m_hWndTooltipOfTreeList, TTM_ADJUSTRECT, 1u, (LPARAM)&rcHeader);
        MapWindowPoints(This->m_hWnd, 0, (LPPOINT)&rcHeader, 2u);
        SetWindowPos(This->m_hWndTooltipOfTreeList, 0, rcHeader.left, rcHeader.top, 0, 0, 0x15u);
        SendMessageW(This->m_hWndTooltipOfTreeList, WM_SETFONT, (WPARAM)This->m_Font, 0);
        CTreeList::SendNotify(
          This,
          This->m_hWndTooltipOfTreeList,
          TVN_7D5,
          This->m_nHeaderItemCount,
          This->field_AC,
          0,
          0);
        return (HWND)1;
      }
LABEL_69:
      hWndFrom = lParamIn->hdr.hwndFrom;
      v44 = This->m_hWndHeaderLeft;
      if ( lParamIn->hdr.hwndFrom != v44 && hWndFrom != This->m_hWndHeaderRight )
        goto __WM_THEMECHANGED;
      nCode = lParamIn->hdr.code;
      if ( nCode > HDN_ITEMCHANGINGW )
      {
        if ( nCode == HDN_ENDDRAG )
        {
          InvalidateRect(This->m_hWnd, 0, 0);
          return 0;
        }
        if ( nCode == -5 )
          // NM_RCLICK
          CTreeList::SendNotify(This, hWndFrom, -5, 0, 0, 0, 0);
        goto __WM_THEMECHANGED;
      }
      if ( nCode != HDN_ITEMCHANGINGW )
      {
        switch ( nCode )
        {
          case HDN_DIVIDERDBLCLICKW:
            v48 = hWndFrom == This->m_hWndHeaderRight;
            v17 = lParamIn->iItem + v48 == 0;
            v49 = lParamIn->iItem + v48;
            left = v49;
            if ( v17 && This->m_bValue1 )
            {
              v50 = This->m_nChildWidthLast;
            }
            else
            {
              v50 = CTreeList::GetChildWidth(This, v49);
              v49 = left;
            }
            CTreeList::UpdateColumnHeight(v49, v50);
            if ( !left )
              CTreeList::MoveHeaders(This, v50);
            CTreeList::Resize(This);
            break;
          case HDN_ITEMCLICKW:
            if ( hWndFrom == v44 )
              v46 = 0;
            else
              v46 = lParamIn->iItem + 1;
            v87 = 0;
            v86 = v46;
            v85 = 2003;
            goto __SendNotify;
          case HDN_ITEMCHANGEDW:
            CTreeList::Resize(This);
            break;
        }
        goto __WM_THEMECHANGED;
      }
      // HDN_ITEMCHANGINGW
      pHeaderItem = lParamIn->pitem;
      if ( !(pHeaderItem->mask & 1) )
        goto __WM_THEMECHANGED;
      nItem = lParamIn->iItem;
      if ( !nItem && pHeaderItem->cxy < This->m_nHeaderHeight )
        return (HWND)1;
      pnItem = nItem + (hWndFrom == This->m_hWndHeaderRight);
      CTreeList::HeaderToClient(This, pnItem, &rcHeader);
      GetClientRect(This->m_hWnd, &rcClient);
      left = rcHeader.left + lParamIn->pitem->cxy - rcHeader.right;
      if ( !left )
        return 0;
      iHeaderItem = pnItem;
      rcScroll.top = rcHeader.bottom;
      rcScroll.right = rcClient.right;
      rcScroll.left = rcHeader.right;
      rcScroll.bottom = rcClient.bottom;
      if ( !pnItem )
        rcScroll.left = rcHeader.right - 1;
      if ( ((unsigned int)GetWindowLongW(This->m_hWndScrollBarRightRight, -16) >> 28) & 1 )
        rcScroll.right -= GetSystemMetrics(2);
      ScrollWindowEx(This->m_hWnd, left, 0, &rcScroll, 0, 0, 0, 2u);
      if ( (iHeaderItem || !This->m_bValue1)
        && (Rect.left = rcHeader.left,
            Rect.top = rcHeader.bottom,
            Rect.right = rcHeader.right,
            Rect.bottom = rcClient.bottom,
            InvalidateRect(This->m_hWnd, &Rect, 0),
            iHeaderItem) )
      {
        CTreeList::Resize(This);
        UpdateWindow(This->m_hWndScrollBarRightBottom);
        result = 0;
      }
      else
      {
        CTreeList::MoveHeaders(This, left + rcHeader.right);
        CTreeList::Resize(This);
        CTreeList::RepositionHeaders();
        UpdateWindow(This->m_hWndHeaderRight);
        UpdateWindow(This->m_hWndScrollBarLeftBottom);
        UpdateWindow(This->m_hWndScrollBarRightBottom);
        result = 0;
      }
      break;
    case WM_NCDESTROY:	///WM_NCDESTROY
      if ( This->m_ImageList && !LOBYTE(This->m_NotMyImageList) )
        ImageList_Destroy(This->m_ImageList);
      SetPropW(hWnd, (LPCWSTR)(unsigned __int16)gAtomTreeListProperty, 0);
      CTreeList::~CTreeList(This);
      operator delete(This);
      return (HWND)DefWindowProcW(hWnd, Msg, wParam, (LPARAM)lParam);
    case WM_GETDLGCODE:
      return (HWND)(DefWindowProcW(v20, uMsg, wParam, (LPARAM)lParam) | 1);
    default:
      goto __WM_THEMECHANGED;
  }
  return result;
}
// CD4D84: using guessed type int (__stdcall *gpfnIsThemeActive)();
// CD4DA0: using guessed type __int16 gAtomTreeListProperty;

//----- (00C111F0) --------------------------------------------------------
CSystemProcessInfoMapNode *__thiscall sub_C111F0(std__tree *this, std__List *a2)
{
  CSystemProcessInfoMapNode *result; // eax
  CSystemProcessInfoMapNode *v3; // esi
  _DWORD *v4; // edi
  Data_t_bstr_t *v5; // eax
  Data_t_bstr_t *v6; // eax

  result = std::_Tree_comp_alloc<std::_Tmap_traits<unsigned long,_SYSTEM_PROCESS_INFORMATION *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const,_SYSTEM_PROCESS_INFORMATION *>>,0>>::_Buynode0((CSystemProcessInfoMap *)this);
  v3 = result;
  v4 = &result->_Keyvalue._Key;
  *(_WORD *)&result->baseclass._Color = 0;
  if ( result != (CSystemProcessInfoMapNode *)-16 )
  {
    v5 = (Data_t_bstr_t *)a2->_Mypair._Myval2._Myhead;
    *v4 = a2->_Mypair._Myval2._Myhead;
    if ( v5 )
      InterlockedIncrement(&v5->m_RefCount);
    v6 = (Data_t_bstr_t *)a2->_Mypair._Myval2._Mysize;
    v4[1] = v6;
    if ( v6 )
      InterlockedIncrement(&v6->m_RefCount);
    result = v3;
  }
  return result;
}

//----- (00C11240) --------------------------------------------------------
int __thiscall sub_C11240(int *this, int a2, int a3, int a4, void *a5)
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
  v9 = *(_DWORD *)(v6 + 4);
  v27 = v6;
  LOBYTE(v26) = 1;
  if ( !*(_BYTE *)(v9 + 13) )
  {
    do
    {
      v27 = v9;
      if ( (_BYTE)a3 )
      {
        v21 = *(Data_t_bstr_t **)v8;
        if ( *(_DWORD *)v8 )
          InterlockedIncrement((volatile LONG *)(*(_DWORD *)v8 + 8));
        v10 = *(Data_t_bstr_t **)(v9 + 16);
        v18 = v10;
        if ( v10 )
          InterlockedIncrement(&v10->m_RefCount);
        v7 = sub_C014B0(v18, v21) == 0;
      }
      else
      {
        v11 = *(Data_t_bstr_t **)(v9 + 16);
        v22 = v11;
        if ( v11 )
          InterlockedIncrement(&v11->m_RefCount);
        v19 = *(Data_t_bstr_t **)v8;
        if ( *(_DWORD *)v8 )
          InterlockedIncrement(&v19->m_RefCount);
        v7 = sub_C014B0(v19, v22);
      }
      LOBYTE(v26) = v7;
      if ( v7 )
        v9 = *(_DWORD *)v9;
      else
        v9 = *(_DWORD *)(v9 + 8);
    }
    while ( !*(_BYTE *)(v9 + 13) );
    v6 = v27;
    v5 = v25;
  }
  v12 = v6;
  a3 = v6;
  if ( v7 )
  {
    if ( v6 == *(_DWORD *)*v5 )
    {
      v13 = (int *)sub_C1AEE0(v5, (int)&a3, 1, v6, v8, a5);
LABEL_21:
      v14 = *v13;
      result = a2;
      *(_DWORD *)a2 = v14;
      *(_BYTE *)(a2 + 4) = 1;
      return result;
    }
    std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned long const,MAPITEM *>>>,std::_Iterator_base0>::operator--((std__tree *)&a3);
    v12 = a3;
  }
  v23 = *(Data_t_bstr_t **)v8;
  if ( *(_DWORD *)v8 )
    InterlockedIncrement(&v23->m_RefCount);
  v16 = *(Data_t_bstr_t **)(v12 + 16);
  v20 = v16;
  if ( v16 )
    InterlockedIncrement(&v16->m_RefCount);
  if ( sub_C014B0(v20, v23) )
  {
    v13 = (int *)sub_C1AEE0(v25, (int)&a3, v26, v27, v8, a5);
    goto LABEL_21;
  }
  v17 = a5;
  sub_C11430((std__List *)a5 + 2);
  operator delete(v17);
  result = a2;
  *(_DWORD *)a2 = v12;
  *(_BYTE *)(a2 + 4) = 0;
  return result;
}
// C781AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);

//----- (00C113E0) --------------------------------------------------------
int sub_C113E0(wchar_t *Dst, wchar_t *Format, ...)
{
  va_list ArgList; // [esp+10h] [ebp+10h]

  va_start(ArgList, Format);
  return vswprintf_s(Dst, 0x10u, Format, ArgList);
}

//----- (00C11400) --------------------------------------------------------
void __thiscall sub_C11400(CSystemProcessInfoMap *this)
{
  CSystemProcessInfoMap *v1; // esi
  char v2; // [esp+4h] [ebp-4h]

  v1 = this;
  sub_C16540(
    this,
    (CSystemProcessInfoMapNode **)&v2,
    (CSystemProcessInfoMapNode *)this->_Header->_Left,
    (CSystemProcessInfoMapNode *)this->_Header);
  operator delete(v1->_Header);
}

//----- (00C11430) --------------------------------------------------------
void __thiscall sub_C11430(std__List *this)
{
  std__List *v1; // edi
  LONG (__stdcall *v2)(volatile LONG *); // ecx
  Data_t_bstr_t *v3; // esi
  Data_t_bstr_t *v4; // esi

  v1 = this;
  v2 = InterlockedDecrement;
  v3 = (Data_t_bstr_t *)v1->_Mypair._Myval2._Mysize;
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
        operator delete[](v3->m_str);
        v3->m_str = 0;
      }
      operator delete(v3);
    }
    v2 = InterlockedDecrement;
    v1->_Mypair._Myval2._Mysize = 0;
  }
  v4 = (Data_t_bstr_t *)v1->_Mypair._Myval2._Myhead;
  if ( v1->_Mypair._Myval2._Myhead )
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
        operator delete[](v4->m_str);
        v4->m_str = 0;
      }
      operator delete(v4);
    }
    v1->_Mypair._Myval2._Myhead = 0;
  }
}

//----- (00C114F0) --------------------------------------------------------
_bstr_t *__cdecl sub_C114F0(_bstr_t *a1, LPCSTR lpString, _bstr_t *a3)
{
  _bstr_t::_bstr_t(a1, lpString);
  _bstr_t::operator+=(a1, a3);
  return a1;
}

//----- (00C11560) --------------------------------------------------------
bool __stdcall AskForAgreementLicense(HWND hWnd, OLECHAR *psz, char a3, char a4, int a5)
{
  _bstr_t *v5; // esi
  _bstr_t *v6; // eax
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
  Data_t_bstr_t *bstrRet; // [esp+28h] [ebp-44h]
  _bstr_t v24; // [esp+2Ch] [ebp-40h]
  _bstr_t v25; // [esp+30h] [ebp-3Ch]
  wchar_t Str; // [esp+34h] [ebp-38h]
  int v27; // [esp+68h] [ebp-4h]

  pThis.nLength = (int)hWnd;
  _bstr_t::_bstr_t((tagEventSetItem *)&v24, L"\\VirusTotal");
  v27 = 0;
  v5 = (_bstr_t *)_bstr_t::_bstr_t((tagEventSetItem *)&v21, psz);
  LOBYTE(v27) = 1;
  v6 = (_bstr_t *)_bstr_t::_bstr_t((tagEventSetItem *)&v22, L"Software\\Sysinternals\\");
  LOBYTE(v27) = 2;
  v7 = _bstr_t::operator+(v6, (_bstr_t *)&bstrRet, v5);
  LOBYTE(v27) = 3;
  _bstr_t::operator+(v7, &v25, &v24);
  v8 = bstrRet;
  if ( bstrRet )
  {
    if ( !InterlockedDecrement(&bstrRet->m_RefCount) && v8 )
    {
      if ( v8->m_wstr )
      {
        SysFreeString(v8->m_wstr);
        v8->m_wstr = 0;
      }
      if ( v8->m_str )
      {
        operator delete[](v8->m_str);
        v8->m_str = 0;
      }
      operator delete(v8);
    }
    bstrRet = 0;
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
        operator delete[](v9->m_str);
        v9->m_str = 0;
      }
      operator delete(v9);
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
        operator delete[](v10->m_str);
        v10->m_str = 0;
      }
      operator delete(v10);
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
      operator delete[](v11->m_str);
      v11->m_str = 0;
    }
    operator delete(v11);
  }
  if ( v25.m_Data )
    v12 = v25.m_Data->m_wstr;
  else
    v12 = 0;
  pThis.szKeyName = (int)_wcsdup(v12);
  LOBYTE(v27) = 9;
  LoadConfigItemFromRegistry(&pThis, (tagConfigItem *)&pConfigItem);
  v13 = byte_CD4DB0;
  if ( byte_CD4DB0 )
    goto LABEL_52;
  if ( a4 != byte_CD4DB0 )
    goto LABEL_63;
  v14 = (HWND)pThis.nLength;
  LaunchWebBrowser((HWND)pThis.nLength, 0, L"https://www.virustotal.com/about/terms-of-service");
  if ( a3 )
  {
    wprintf(L"%s\n\n", aYouMustAgreeTo);
    wprintf(L"Enter 'y' to agree: ");
    v15 = __acrt_iob_func();
    fflush(v15 + 1);
    _getws_s(&Str, 0x14u);
    if ( wcschr(&Str, 0x79u) )
    {
      byte_CD4DB0 = 1;
      wprintf(L"\n");
    }
    else
    {
      wprintf(L"\nYou must agree to VirusTotal's terms of service to use VirusTotal features.\n\n");
    }
    goto LABEL_48;
  }
  v16 = a5 ? MessageBoxW(v14, (LPCWSTR)a5, L"VirusTotal Terms of Service", 0x24u) : MessageBoxW(
                                                                                      v14,
                                                                                      L"You must agree to VirusTotal's ter"
                                                                                       "ms of service to use VirusTotal features.\n\n",
                                                                                      L"VirusTotal Terms of Service",
                                                                                      0x24u);
  if ( v16 == 6 )
  {
LABEL_63:
    byte_CD4DB0 = 1;
LABEL_51:
    SaveConfigItemToRegistry(&pThis, (tagConfigItem *)&pConfigItem);
    v13 = byte_CD4DB0;
    goto LABEL_52;
  }
LABEL_48:
  v13 = byte_CD4DB0;
  if ( byte_CD4DB0 )
    goto LABEL_51;
LABEL_52:
  v17 = v13 == 1;
  free((void *)pThis.szKeyName);
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
      operator delete[](v18->m_str);
      v18->m_str = 0;
    }
    operator delete(v18);
  }
  return v17;
}
// CA4500: using guessed type wchar_t aYouMustAgreeTo_1[78];
// CCC338: using guessed type wchar_t aYouMustAgreeTo[175];
// CD4DB0: using guessed type char byte_CD4DB0;
