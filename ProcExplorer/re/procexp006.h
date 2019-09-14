

//----- (00FF0760) --------------------------------------------------------
void __cdecl sub_FF0760(int a1)
{
  int v1; // ebx
  _WORD *v2; // eax
  _WORD *v3; // eax
  WCHAR *v4; // eax
  const wchar_t *v5; // eax
  const wchar_t *v6; // ecx
  unsigned int dwNameIndex; // esi
  const WCHAR ***v8; // eax
  const WCHAR **v9; // eax
  const WCHAR ***v10; // eax
  const WCHAR **v11; // eax
  CPEString *v12; // eax
  CPEString *v13; // eax
  int v14; // eax
  const wchar_t *v15; // edx
  char v16; // bl
  void *v17; // ebx
  const wchar_t *v18; // ecx
  const wchar_t *v19; // ecx
  void *v20; // ST30_4
  WCHAR pszText2[2]; // [esp+10h] [ebp-E0h]
  int v22; // [esp+14h] [ebp-DCh]
  int v23; // [esp+18h] [ebp-D8h]
  int v24; // [esp+1Ch] [ebp-D4h]
  int dwFlags; // [esp+20h] [ebp-D0h]
  _bstr_t bstrAppName; // [esp+24h] [ebp-CCh]
  CPEString v27; // [esp+28h] [ebp-C8h]
  LPVOID pszWorkingDirectory; // [esp+2Ch] [ebp-C4h]
  CPEString str; // [esp+30h] [ebp-C0h]
  int a2; // [esp+34h] [ebp-BCh]
  _bstr_t bstrName; // [esp+38h] [ebp-B8h]
  int v32; // [esp+3Ch] [ebp-B4h]
  ITaskTrigger *pTaskTrigger; // [esp+40h] [ebp-B0h]
  CPEString str2; // [esp+44h] [ebp-ACh]
  void *v35; // [esp+48h] [ebp-A8h]
  CPEString str1; // [esp+4Ch] [ebp-A4h]
  void *v37; // [esp+50h] [ebp-A0h]
  LPVOID szApplicationName; // [esp+54h] [ebp-9Ch]
  void *v39; // [esp+58h] [ebp-98h]
  void *v40; // [esp+5Ch] [ebp-94h]
  void *v41; // [esp+60h] [ebp-90h]
  void *v42; // [esp+64h] [ebp-8Ch]
  void *ppv1; // [esp+68h] [ebp-88h]
  void *v44; // [esp+6Ch] [ebp-84h]
  LPCWSTR pszParameters; // [esp+70h] [ebp-80h]
  CPEString v46; // [esp+74h] [ebp-7Ch]
  WCHAR *v47; // [esp+78h] [ebp-78h]
  ITaskScheduler *ppv; // [esp+7Ch] [ebp-74h]
  int v49; // [esp+80h] [ebp-70h]
  void *v50; // [esp+84h] [ebp-6Ch]
  IEnumWorkItems *pEnumWorkItems; // [esp+88h] [ebp-68h]
  void *v52; // [esp+8Ch] [ebp-64h]
  void *wTaskCount; // [esp+90h] [ebp-60h]
  WCHAR *ppv3; // [esp+94h] [ebp-5Ch]
  WCHAR *hKey; // [esp+98h] [ebp-58h]
  CPEString v56; // [esp+9Ch] [ebp-54h]
  CPEString str3; // [esp+A0h] [ebp-50h]
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
      v56.m_String = _wcsdup(&gszNullString);
      str3.m_String = _wcsdup(&gszNullString);
      v5 = &gszNullString;
      if ( off_10BAA18 )
        v5 = off_10BAA18;
      hKey = _wcsdup(v5);
      v6 = &gszNullString;
      if ( off_10BAA18 )
        v6 = off_10BAA18;
      ppv3 = _wcsdup(v6);
      LOBYTE(v62) = 10;
      ppv1 = sub_FD3FF0(a1, 2u, 0xFFFFFFFF, 0, &ppv3, &hKey, &str3);
      free(ppv3);
      free(hKey);
      free(str3.m_String);
      free(v56.m_String);
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
                      str3.m_String = malloc(2u);
                      *str3.m_String = 0;
                      v12 = CPEString::Append(&str, &hKey, L" ");
                      v13 = CPEString::Append(&v27, v12, pszParameters);
                      CPEString::InsertAt(&str3, v13->m_String, 0x7FFFFFFFu, 0);
                      free(v27.m_String);
                      free(str.m_String);
                      *pszText2 = malloc(2u);
                      **pszText2 = 0;
                      v22 = 0;
                      v23 = 0;
                      v24 = 0;
                      LOBYTE(v62) = 14;
                      sub_FD6CC0(str3.m_String, pszText2);
                      sub_FD4EE0(&v56, v1, pszText2, 0);
                      LOBYTE(v62) = 15;
                      v14 = sub_FD4ED0();
                      v15 = &gszNullString;
                      a2 = v14;
                      if ( off_10BAA18 )
                        v15 = off_10BAA18;
                      v35 = _wcsdup(v15);
                      LOBYTE(v62) = 16;
                      v16 = sub_FD3D40(v1, &ppv3, &v35, &hKey, &v56, &v52, &v47, &v32);
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
                          v46.m_String = _wcsdup(&gszNullString);
                          v18 = &gszNullString;
                          if ( off_10BAA18 )
                            v18 = off_10BAA18;
                          str2.m_String = _wcsdup(v18);
                          v19 = &gszNullString;
                          if ( off_10BAA18 )
                            v19 = off_10BAA18;
                          str1.m_String = _wcsdup(v19);
                          LOBYTE(v62) = 24;
                          v17 = sub_FD3FF0(v49, 2u, v17, 0, &str1, &str2, &v46);
                          ppv1 = v17;
                          free(str1.m_String);
                          free(str2.m_String);
                          free(v46.m_String);
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
                        sub_FD3FF0(v49, a2, v20, 9u, &ppv3, &hKey, &v56);
                        free(v40);
                      }
                      else
                      {
                        v1 = v49;
                      }
                      CoTaskMemFree(szApplicationName);
                      CoTaskMemFree(pszParameters);
                      CoTaskMemFree(pszWorkingDirectory);
                      free(v56.m_String);
                      sub_FD21F0(pszText2);
                      free(str3.m_String);
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
      sub_FF0EA0(a1);
    }
  }
}
// 1092AD0: using guessed type GUID CLSID_ITask;

//----- (00FF0EA0) --------------------------------------------------------
void __cdecl sub_FF0EA0(int a1)
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
  CPEString str2; // [esp+7Ch] [ebp-34h]
  CPEString str3; // [esp+80h] [ebp-30h]
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
  str3.m_String = _wcsdup(&gszNullString);
  v1 = &gszNullString;
  v2 = &gszNullString;
  if ( off_10BAA2C )
    v2 = off_10BAA2C;
  str2.m_String = _wcsdup(v2);
  if ( off_10BAA2C )
    v1 = off_10BAA2C;
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
  ppv1 = sub_FD3FF0(a1, 2u, ppv1, 0, &ppv3, &str2, &str3);
  free(ppv3);
  free(str2.m_String);
  free(str3.m_String);
  free(v39);
  free(v41);
  free(v40);
  free(v43);
  v47 = -1;
  free(v45.m_Data);
  CoInitializeEx(0, 0);
  ppv = 0;
  if ( CoCreateInstance(&stru_10A78CC, 0, 1u, &riid, &ppv) >= 0 )
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
        sub_FEF260(a1, &ppv1, off_10BAA2C, v28, v29);
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

//----- (00FF11B0) --------------------------------------------------------
wchar_t *__cdecl sub_FF11B0(wchar_t *a1, int a2, wchar_t *a3)
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
  v3[3] = dword_10C4C78;
  dword_10C4C78 = v3;
  free(a1);
  free(a3);
  return v8;
}
// 10C4C78: using guessed type int dword_10C4C78;

//----- (00FF1290) --------------------------------------------------------
int __cdecl sub_FF1290(wchar_t *a1, int a2)
{
  int v2; // esi
  int result; // eax
  void *v4; // ebx
  int v5; // esi

  v2 = dword_10C4C78;
  if ( dword_10C4C78 )
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
// 10C4C78: using guessed type int dword_10C4C78;

//----- (00FF1310) --------------------------------------------------------
CSystemProcessInfoMapNode *__thiscall sub_FF1310(CSystemProcessInfoMap *this, int *a2)
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

//----- (00FF1350) --------------------------------------------------------
_DWORD *__thiscall sub_FF1350(_DWORD *this)
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

//----- (00FF1450) --------------------------------------------------------
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

//----- (00FF14B0) --------------------------------------------------------
// operator==(const _bstr_t::Data_t& r,const _bstr_t::Data_t& l)const
bool __stdcall sub_FF14B0(Data_t_bstr_t *a1, Data_t_bstr_t *a2)
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

//----- (00FF1590) --------------------------------------------------------
void __cdecl sub_FF1590(char a1, int a2, OLECHAR *a3, OLECHAR *a4, OLECHAR *psz, int a6)
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

  if ( !byte_10C4CCC )
    return;
  EnterCriticalSection(&stru_10C4C98);
  v6 = 0;
  v15 = 0;
  _bstr_t::_bstr_t(&v14, psz);
  v7 = *sub_1062F90(&gMap5, &v12, &v14);
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
          v6 = sub_FF1350(v10);
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
        sub_1061650(&gMap5, &v13, 0, &v11, byte_10C4CCD);
        v17 = -1;
        _bstr_t::_Free(&v11);
      }
      v9 = a2;
      *a2 = v6;
      v6[1] = 3 - (a6 != 1);
      if ( a6 == 1 )
      {
        sub_FF9380(&gList1, &v15);
        SetEvent(hEvent);
      }
      else
      {
        sub_FF17F0(&gList2, &v15);
        SetEvent(dword_10C4CB8);
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
  LeaveCriticalSection(&stru_10C4C98);
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
// 10C4CCC: using guessed type char byte_10C4CCC;
// 10C4CCD: using guessed type char byte_10C4CCD;

//----- (00FF1780) --------------------------------------------------------
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

//----- (00FF17B0) --------------------------------------------------------
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

//----- (00FF17F0) --------------------------------------------------------
_DWORD *__thiscall sub_FF17F0(int **this, int a2)
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

//----- (00FF1840) --------------------------------------------------------
void *__cdecl sub_FF1840(int a1)
{
  void *v1; // eax

  v1 = sub_FF1860(a1, 0xFFFFFFFF, 1);
  return sub_FF1860(a1, v1, 0);
}

//----- (00FF1860) --------------------------------------------------------
void *__cdecl sub_FF1860(int a1, void *a2, char a3)
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
  int v27; // [esp+10h] [ebp-C9Ch]
  void *v28; // [esp+14h] [ebp-C98h]
  int v29; // [esp+18h] [ebp-C94h]
  void *v30; // [esp+1Ch] [ebp-C90h]
  unsigned int v31; // [esp+20h] [ebp-C8Ch]
  void *v32; // [esp+24h] [ebp-C88h]
  CPEString v33; // [esp+28h] [ebp-C84h]
  FILE *v34; // [esp+2Ch] [ebp-C80h]
  void *v35; // [esp+30h] [ebp-C7Ch]
  CPEString v36; // [esp+34h] [ebp-C78h]
  void *v37; // [esp+38h] [ebp-C74h]
  int v38; // [esp+3Ch] [ebp-C70h]
  void *v39; // [esp+40h] [ebp-C6Ch]
  WCHAR *v40; // [esp+44h] [ebp-C68h]
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
  CPEString str3; // [esp+74h] [ebp-C38h]
  CPEString v52; // [esp+78h] [ebp-C34h]
  CPEString str1; // [esp+7Ch] [ebp-C30h]
  CPEString str2; // [esp+80h] [ebp-C2Ch]
  wchar_t *ppv3; // [esp+84h] [ebp-C28h]
  CPEString v56; // [esp+88h] [ebp-C24h]
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
  v56.m_String = malloc(2u);
  *v56.m_String = 0;
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
    str1.m_String = _wcsdup(&gszNullString);
    v52.m_String = _wcsdup(&gszNullString);
    str3.m_String = _wcsdup(&gszNullString);
    str2.m_String = _wcsdup(&Buffer);
    ppv3 = _wcsdup(&Buffer);
    LOBYTE(v62) = 12;
    a2 = sub_FD3FF0(a1, 2u, 0xFFFFFFFF, 0, &ppv3, &str2, &str3);
    free(ppv3);
    free(str2.m_String);
    free(str3.m_String);
    free(v52.m_String);
    free(str1.m_String);
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
            sub_FD6DD0(v11, 44, &v42, 0);
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
                v22 = sub_FD4EE0(&v28, v29, v20, 0);
                v23 = v56.m_String;
                v56.m_String = _wcsdup(*v22);
                free(v23);
                free(v28);
                if ( *v56.m_String )
                {
                  v24 = sub_FD4ED0();
                  v50 = _wcsdup(&Buffer);
                  v48 = _wcsdup(&Buffer);
                  v49 = _wcsdup(v11);
                  LOBYTE(v62) = 16;
                  v25 = sub_FD3D40(v21, &v49, &v48, &v50, &v56, &v46, &v40, &v27);
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
                      str2.m_String = _wcsdup(&gszNullString);
                      str3.m_String = _wcsdup(&gszNullString);
                      v52.m_String = _wcsdup(&Buffer);
                      str1.m_String = _wcsdup(&Buffer);
                      LOBYTE(v62) = 24;
                      a2 = sub_FD3FF0(v21, 2u, 0xFFFFFFFF, 0, &str1, &v52, &str3);
                      free(str1.m_String);
                      free(v52.m_String);
                      free(str3.m_String);
                      free(str2.m_String);
                      free(v39);
                      free(v32);
                      free(v30);
                      free(v37);
                    }
                    v35 = _wcsdup(&gszNullString);
                    v33.m_String = _wcsdup(&Buffer);
                    v11 = ppv3;
                    v36.m_String = _wcsdup(ppv3);
                    LOBYTE(v62) = 27;
                    sub_FD3FF0(v21, v24, a2, 4u, &v36, &v33, &v56);
                    free(v36.m_String);
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
              sub_FD2BF0(v15, v14);
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
  free(v56.m_String);
  free(v41);
  free(v46);
  return a2;
}
// 1092C50: using guessed type wchar_t aAutorunsdisabl_1[22];
// 1092C7C: using guessed type wchar_t aWinIni[9];

//----- (00FF2060) --------------------------------------------------------
void __cdecl sub_FF2060(int a1, void *a2, void *a3)
{
  _WORD *v3; // ST50_4
  CPEString *v4; // esi
  void *v5; // edi
  CPEString *v6; // eax
  wchar_t *v7; // ST54_4

  v3 = malloc(2u);
  *v3 = 0;
  v4 = a3;
  v5 = sub_FF2110(a1, a2, *a3, 0xFFFFFFFF);
  v6 = CPEString::Append(&a3, v4, L"\\AutorunsDisabled");
  v7 = _wcsdup(v6->m_String);
  free(v3);
  free(a3);
  sub_FF2110(a1, a2, v7, v5);
  free(v7);
}

//----- (00FF2110) --------------------------------------------------------
void *__cdecl sub_FF2110(int a1, void *a2, wchar_t *psz, void *a4)
{
  DWORD v4; // ebx
  const wchar_t *v5; // eax
  const wchar_t *v6; // eax
  CPEString *v7; // esi
  CPEString *v8; // eax
  unsigned int v9; // eax
  const WCHAR *v10; // esi
  unsigned int v11; // eax
  void *v12; // esi
  const wchar_t **v13; // eax
  WCHAR *v14; // esi
  const wchar_t *v15; // ecx
  const wchar_t *v16; // eax
  CPEString *v17; // esi
  CPEString *v18; // eax
  char v19; // bl
  const wchar_t *v20; // eax
  const wchar_t *v21; // eax
  HKEY v22; // ebx
  CPEString *v23; // esi
  CPEString *v24; // eax
  const wchar_t *v25; // eax
  CPEString *v26; // eax
  tagPEStringStruct v28; // [esp+10h] [ebp-A0h]
  int a2a; // [esp+2Ch] [ebp-84h]
  void *v30; // [esp+30h] [ebp-80h]
  int v31; // [esp+34h] [ebp-7Ch]
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
  wchar_t *v43; // [esp+64h] [ebp-4Ch]
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
  CPEString str3; // [esp+9Ch] [ebp-14h]
  LPCWSTR lpszKeyName; // [esp+A0h] [ebp-10h]
  int v59; // [esp+ACh] [ebp-4h]

  v4 = 0;
  v34 = 0;
  v43 = malloc(2u);
  *v43 = 0;
  v59 = 0;
  str3.m_String = malloc(2u);
  *str3.m_String = 0;
  v44 = malloc(2u);
  *v44 = 0;
  v41 = malloc(2u);
  *v41 = 0;
  v39 = malloc(2u);
  *v39 = 0;
  ppv3 = malloc(2u);
  *ppv3 = 0;
  LOBYTE(v59) = 5;
  if ( a4 == -1 )
  {
    v50 = _wcsdup(&gszNullString);
    v56 = _wcsdup(&gszNullString);
    szKeyName = _wcsdup(&gszNullString);
    v49 = _wcsdup(&gszNullString);
    v51 = _wcsdup(&gszNullString);
    v53 = _wcsdup(&gszNullString);
    szArg4 = _wcsdup(&gszNullString);
    v5 = &gszNullString;
    if ( psz )
      v5 = psz;
    pszText = _wcsdup(v5);
    v48 = _wcsdup(&gszNullString);
    v6 = &gszNullString;
    if ( psz )
      v6 = psz;
    szArg3 = _wcsdup(v6);
    LOBYTE(v59) = 15;
    v7 = MakeRegistryKeyName(&a1a, a2, &pszText, &szArg4);
    LOBYTE(v59) = 16;
    v8 = MakeRegistryKeyName(szArg, a2, &szArg3, &v48);
    LOBYTE(v59) = 17;
    a4 = sub_FD3FF0(a1, 0, 0xFFFFFFFF, 0, v8, v7, &v53);
    free(*szArg);
    free(a1a);
    free(szArg3);
    free(v48);
    free(pszText);
    free(szArg4);
    free(v53);
    free(v51);
    free(v49);
    free(szKeyName);
    free(v56);
    LOBYTE(v59) = 5;
    free(v50);
  }
  v9 = TlsGetValue(gdwTlsIndex);
  if ( !PE_OpenKey(ghLocalMachineKey, psz, 0, v9 | 0x20019, &hRootKey) )
  {
    lpszKeyName = malloc(2u);
    *lpszKeyName = 0;
    LOBYTE(v59) = 18;
    if ( !PE_LoadRegKeys(hRootKey, 0, &lpszKeyName) )
    {
      do
      {
        v10 = lpszKeyName;
        v11 = TlsGetValue(gdwTlsIndex);
        if ( !PE_OpenKey(hRootKey, v10, 0, v11 | 0x20019, &hKey) )
        {
          if ( !PE_ReadRegKey(hKey, L"Dllname", 0, 0, &v43) )
          {
            v28.strValue[0] = malloc(2u);
            *v28.strValue[0] = 0;
            v28.strValue[1] = 0;
            v28.strValue[2] = 0;
            v28.strValue[3] = 0;
            LOBYTE(v59) = 19;
            sub_FD7040(v43, &v28);
            v12 = v44;
            v44 = _wcsdup(v43);
            free(v12);
            v13 = sub_FD4EE0(&v30, a1, &v28, 0);
            v14 = str3.m_String;
            str3.m_String = _wcsdup(*v13);
            free(v14);
            free(v30);
            a2a = sub_FD4ED0();
            v15 = &gszNullString;
            if ( psz )
              v15 = psz;
            szKeyName = _wcsdup(v15);
            v56 = _wcsdup(&gszNullString);
            v16 = &gszNullString;
            if ( psz )
              v16 = psz;
            v50 = _wcsdup(v16);
            LOBYTE(v59) = 22;
            v17 = MakeRegistryKeyName(v33, a2, &szKeyName, &lpszKeyName);
            LOBYTE(v59) = 23;
            v18 = MakeRegistryKeyName(&v28.strValue[6], a2, &v50, &v56);
            LOBYTE(v59) = 24;
            v19 = sub_FD3D40(a1, &lpszKeyName, v18, v17, &str3, &v41, &ppv3, &v31);
            free(v28.strValue[6]);
            free(*v33);
            free(v50);
            free(v56);
            free(szKeyName);
            if ( v19 )
            {
              if ( a4 == -1 )
              {
                v37 = _wcsdup(&gszNullString);
                v35 = _wcsdup(&gszNullString);
                v38 = _wcsdup(&gszNullString);
                szArg3 = _wcsdup(&gszNullString);
                v48 = _wcsdup(&gszNullString);
                pszText = _wcsdup(&gszNullString);
                szArg4 = _wcsdup(&gszNullString);
                v20 = &gszNullString;
                if ( psz )
                  v20 = psz;
                v53 = _wcsdup(v20);
                v51 = _wcsdup(&gszNullString);
                v21 = &gszNullString;
                if ( psz )
                  v21 = psz;
                v49 = _wcsdup(v21);
                v22 = a2;
                LOBYTE(v59) = 34;
                v23 = MakeRegistryKeyName(v32, a2, &v53, &szArg4);
                LOBYTE(v59) = 35;
                v24 = MakeRegistryKeyName(&v28.strValue[4], a2, &v49, &v51);
                LOBYTE(v59) = 36;
                a4 = sub_FD3FF0(a1, 0, 0xFFFFFFFF, 0, v24, v23, &pszText);
                free(v28.strValue[4]);
                free(*v32);
                free(v49);
                free(v51);
                free(v53);
                free(szArg4);
                free(pszText);
                free(v48);
                free(szArg3);
                free(v38);
                free(v35);
                free(v37);
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
              LOBYTE(v59) = 38;
              v26 = MakeRegistryKeyName(&v28.strValue[5], v22, &a1a, &lpszKeyName);
              LOBYTE(v59) = 39;
              sub_FD3FF0(a1, a2a, a4, 3u, &lpszKeyName, v26, &str3);
              free(v28.strValue[5]);
              free(a1a);
              free(*szArg);
            }
            LOBYTE(v59) = 18;
            sub_FD21F0(&v28);
            v4 = v34;
          }
          RegCloseKey(hKey);
        }
        v34 = ++v4;
      }
      while ( !PE_LoadRegKeys(hRootKey, v4, &lpszKeyName) );
    }
    RegCloseKey(hRootKey);
    free(lpszKeyName);
  }
  free(ppv3);
  free(v39);
  free(v41);
  free(v44);
  free(str3.m_String);
  free(v43);
  return a4;
}

//----- (00FF27D0) --------------------------------------------------------
void __cdecl sub_FF27D0(int a1, OLECHAR *psz)
{
  _WORD *v2; // edi
  _WORD *v3; // ebx
  _WORD *v4; // esi
  CPEString *v5; // eax
  int v6; // edi
  DWORD v7; // ebx
  const WCHAR *v8; // esi
  unsigned int v9; // eax
  const wchar_t **v10; // eax
  WCHAR *v11; // esi
  wchar_t *v12; // esi
  wchar_t *v13; // eax
  const wchar_t **v14; // eax
  wchar_t *v15; // esi
  HMODULE v16; // eax
  CPEString *v17; // esi
  CPEString *v18; // eax
  CPEString *v19; // esi
  CPEString *v20; // eax
  CPEString *v21; // eax
  tagPEStringStruct v22; // [esp+10h] [ebp-2D4h]
  WCHAR v23[2]; // [esp+2Ch] [ebp-2B8h]
  WCHAR v24[2]; // [esp+30h] [ebp-2B4h]
  _WORD *v25; // [esp+34h] [ebp-2B0h]
  int v26; // [esp+38h] [ebp-2ACh]
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
  CPEString *str2; // [esp+6Ch] [ebp-278h]
  WCHAR *ppv3; // [esp+70h] [ebp-274h]
  WCHAR szArg[2]; // [esp+74h] [ebp-270h]
  void *a1a; // [esp+78h] [ebp-26Ch]
  DWORD cbData; // [esp+7Ch] [ebp-268h]
  wchar_t *v44; // [esp+80h] [ebp-264h]
  void *v45; // [esp+84h] [ebp-260h]
  UINT uID; // [esp+88h] [ebp-25Ch]
  HKEY phkResult; // [esp+8Ch] [ebp-258h]
  LPCWSTR v48; // [esp+90h] [ebp-254h]
  CPEString str3; // [esp+94h] [ebp-250h]
  LPCWSTR v50; // [esp+98h] [ebp-24Ch]
  void *v51; // [esp+9Ch] [ebp-248h]
  CPEString v52; // [esp+A0h] [ebp-244h]
  LPCWSTR v53; // [esp+A4h] [ebp-240h]
  LPCWSTR szArg4; // [esp+A8h] [ebp-23Ch]
  char v55; // [esp+AFh] [ebp-235h]
  CPEString v56; // [esp+B0h] [ebp-234h]
  LPCWSTR lpSubKey; // [esp+B4h] [ebp-230h]
  LPCWSTR v58; // [esp+B8h] [ebp-22Ch]
  BYTE v59; // [esp+BCh] [ebp-228h]
  WCHAR Buffer; // [esp+CCh] [ebp-218h]
  int v61; // [esp+2E0h] [ebp-4h]

  uID = a1;
  v61 = 0;
  v56.m_String = malloc(2u);
  *v56.m_String = 0;
  v2 = malloc(2u);
  v29 = v2;
  *v2 = 0;
  v3 = malloc(2u);
  v27 = v3;
  *v3 = 0;
  v51 = malloc(2u);
  *v51 = 0;
  v38 = malloc(2u);
  *v38 = 0;
  ppv3 = malloc(2u);
  *ppv3 = 0;
  v4 = malloc(2u);
  v25 = v4;
  *v4 = 0;
  v44 = malloc(2u);
  *v44 = 0;
  v48 = _wcsdup(&gszNullString);
  v50 = _wcsdup(&gszNullString);
  v53 = _wcsdup(&gszNullString);
  v52.m_String = _wcsdup(&gszNullString);
  v45 = _wcsdup(&gszNullString);
  str3.m_String = _wcsdup(&gszNullString);
  szArg4 = _wcsdup(&gszNullString);
  v58 = _wcsdup(&gszNullString);
  LOBYTE(v61) = 16;
  str2 = MakeRegistryKeyName(&a1a, HKEY_LOCAL_MACHINE, &psz, &szArg4);
  LOBYTE(v61) = 17;
  v5 = MakeRegistryKeyName(szArg, HKEY_LOCAL_MACHINE, &psz, &v58);
  LOBYTE(v61) = 18;
  ppv1 = sub_FD3FF0(uID, 0, 0xFFFFFFFF, 0, v5, str2, &str3);
  free(*szArg);
  free(a1a);
  free(v58);
  free(szArg4);
  free(str3.m_String);
  free(v45);
  free(v52.m_String);
  free(v53);
  free(v50);
  LOBYTE(v61) = 8;
  free(v48);
  if ( PE_OpenKey(ghLocalMachineKey, psz, 0, 0x20019u, &hKey) )
  {
    free(v44);
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
    lpSubKey = malloc(2u);
    *lpSubKey = 0;
    LOBYTE(v61) = 19;
    if ( !PE_LoadRegKeys(hKey, 0, &lpSubKey) )
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
          if ( !PE_ReadRegKey(phkResult, L"LibraryPath", 0, 0, &v44) )
          {
            str2 = _wcsdup(v44);
            v22.strValue[0] = malloc(2u);
            *v22.strValue[0] = 0;
            v22.strValue[1] = 0;
            v22.strValue[2] = 0;
            v22.strValue[3] = 0;
            LOBYTE(v61) = 21;
            sub_FD7040(v44, &v22);
            v10 = sub_FD4EE0(&v22.strValue[4], v6, &v22, 0);
            v11 = v56.m_String;
            v56.m_String = _wcsdup(*v10);
            free(v11);
            free(v22.strValue[4]);
            a2 = sub_FD4ED0();
            v58 = _wcsdup(lpSubKey);
            LOBYTE(v61) = 22;
            if ( !PE_ReadRegKey(phkResult, L"DisplayString", 0, 0, &v58) && *v58 == 64 )
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
              v14 = RequerySystemEnvironmentString(&v22.strValue[6], v12 + 1);
              v15 = _wcsdup(*v14);
              free(v35);
              free(v22.strValue[6]);
              v16 = LoadLibraryExW(v15, 0, 2u);
              v22.strValue[5] = v16;
              if ( v16 )
              {
                if ( LoadStringW(v16, uID, &Buffer, 260) )
                {
                  v35 = v58;
                  v58 = _wcsdup(&Buffer);
                  free(v35);
                }
                FreeLibrary(v22.strValue[5]);
              }
              free(v15);
            }
            cbData = 4;
            RegQueryValueExW(phkResult, L"Enabled", 0, 0, Data, &cbData);
            cbData = 16;
            if ( !RegQueryValueExW(phkResult, L"ProviderId", 0, 0, &v59, &cbData) )
            {
              v48 = _wcsdup(&gszNullString);
              LOBYTE(v61) = 24;
              v17 = MakeRegistryKeyName(v24, HKEY_LOCAL_MACHINE, &psz, &lpSubKey);
              LOBYTE(v61) = 25;
              v18 = MakeRegistryKeyName(v30, HKEY_LOCAL_MACHINE, &psz, &v48);
              LOBYTE(v61) = 26;
              v55 = sub_FD3D40(v6, &lpSubKey, v18, v17, &v56, &v51, &ppv3, &v26);
              free(*v30);
              free(*v24);
              free(v48);
              if ( v55 )
              {
                if ( ppv1 == -1 )
                {
                  a1a = _wcsdup(&gszNullString);
                  v34 = _wcsdup(&gszNullString);
                  szArg4 = _wcsdup(&gszNullString);
                  str3.m_String = _wcsdup(&gszNullString);
                  v45 = _wcsdup(&gszNullString);
                  v52.m_String = _wcsdup(&gszNullString);
                  v53 = _wcsdup(&gszNullString);
                  v50 = _wcsdup(&gszNullString);
                  LOBYTE(v61) = 34;
                  v19 = MakeRegistryKeyName(v23, HKEY_LOCAL_MACHINE, &psz, &v53);
                  LOBYTE(v61) = 35;
                  v20 = MakeRegistryKeyName(v28, HKEY_LOCAL_MACHINE, &psz, &v50);
                  LOBYTE(v61) = 36;
                  ppv1 = sub_FD3FF0(v6, 0, 0xFFFFFFFF, 0, v20, v19, &v52);
                  free(*v28);
                  free(*v23);
                  free(v50);
                  free(v53);
                  free(v52.m_String);
                  free(v45);
                  free(str3.m_String);
                  free(szArg4);
                  free(v34);
                  free(a1a);
                }
                *szArg = _wcsdup(&gszNullString);
                LOBYTE(v61) = 37;
                v21 = MakeRegistryKeyName(v31, HKEY_LOCAL_MACHINE, &psz, &lpSubKey);
                LOBYTE(v61) = 38;
                sub_FD3FF0(v6, a2, ppv1, 0x10u, &v58, v21, &v56);
                free(*v31);
                free(*szArg);
              }
            }
            free(v58);
            sub_FD21F0(&v22);
            LOBYTE(v61) = 19;
            free(str2);
          }
          RegCloseKey(phkResult);
        }
        ++v7;
      }
      while ( !PE_LoadRegKeys(hKey, v7, &lpSubKey) );
      v2 = v29;
      v3 = v27;
      v4 = v25;
    }
    RegCloseKey(hKey);
    free(lpSubKey);
    free(v44);
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

//----- (00FF3190) --------------------------------------------------------
void __cdecl sub_FF3190(int a1, OLECHAR *psz)
{
  _WORD *v2; // edi
  _WORD *v3; // ebx
  _WORD *v4; // esi
  CPEString *v5; // eax
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
  const wchar_t **v17; // eax
  wchar_t *v18; // esi
  HINSTANCE v19; // eax
  CPEString *v20; // esi
  CPEString *v21; // eax
  CPEString *v22; // esi
  CPEString *v23; // eax
  CPEString *v24; // eax
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
  WCHAR *v49; // [esp+70h] [ebp-5DCh]
  HKEY hRootKey; // [esp+74h] [ebp-5D8h]
  CPEString *str2; // [esp+78h] [ebp-5D4h]
  void *v52; // [esp+7Ch] [ebp-5D0h]
  WCHAR szArg[2]; // [esp+80h] [ebp-5CCh]
  void *a1a; // [esp+84h] [ebp-5C8h]
  void *v55; // [esp+88h] [ebp-5C4h]
  LPCWSTR v56; // [esp+8Ch] [ebp-5C0h]
  CPEString str3; // [esp+90h] [ebp-5BCh]
  LPCWSTR v58; // [esp+94h] [ebp-5B8h]
  Data_t_bstr_t *v59; // [esp+98h] [ebp-5B4h]
  LPCWSTR v60; // [esp+9Ch] [ebp-5B0h]
  UINT uID; // [esp+A0h] [ebp-5ACh]
  CPEString v62; // [esp+A4h] [ebp-5A8h]
  LPCWSTR szArg4; // [esp+A8h] [ebp-5A4h]
  CPEString v64; // [esp+ACh] [ebp-5A0h]
  char v65; // [esp+B3h] [ebp-599h]
  LPCWSTR lpszKeyName; // [esp+B4h] [ebp-598h]
  wchar_t *ppv3; // [esp+B8h] [ebp-594h]
  BYTE Data; // [esp+BCh] [ebp-590h]
  WCHAR Buffer; // [esp+434h] [ebp-218h]
  int v70; // [esp+648h] [ebp-4h]

  v59 = a1;
  v70 = 0;
  v64.m_String = malloc(2u);
  *v64.m_String = 0;
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
  v62.m_String = _wcsdup(&gszNullString);
  str3.m_String = _wcsdup(&gszNullString);
  ppv3 = _wcsdup(&gszNullString);
  szArg4 = _wcsdup(&gszNullString);
  LOBYTE(v70) = 16;
  str2 = MakeRegistryKeyName(&a1a, HKEY_LOCAL_MACHINE, &psz, &ppv3);
  LOBYTE(v70) = 17;
  v5 = MakeRegistryKeyName(szArg, HKEY_LOCAL_MACHINE, &psz, &szArg4);
  LOBYTE(v70) = 18;
  ppv1 = sub_FD3FF0(v59, 0, 0xFFFFFFFF, 0, v5, str2, &str3);
  free(*szArg);
  free(a1a);
  free(szArg4);
  free(ppv3);
  free(str3.m_String);
  free(v62.m_String);
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
    free(v64.m_String);
  }
  else
  {
    lpszKeyName = malloc(2u);
    *lpszKeyName = 0;
    LOBYTE(v70) = 19;
    if ( !PE_LoadRegKeys(hRootKey, 0, &lpszKeyName) )
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
            *pszText2 = malloc(2u);
            **pszText2 = 0;
            v26 = 0;
            v27 = 0;
            v28 = 0;
            LOBYTE(v70) = 21;
            sub_FD6CC0(szArg4, pszText2);
            v13 = sub_FD4EE0(&v31, v6, pszText2, 0);
            v14 = v64.m_String;
            v64.m_String = _wcsdup(*v13);
            free(v14);
            free(v31);
            a2 = sub_FD4ED0();
            ppv3 = _wcsdup(lpszKeyName);
            LOBYTE(v70) = 22;
            if ( !PE_ReadRegKey(hKey, L"ProtocolName", 0, 0, &ppv3) && *ppv3 == 64 )
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
            v20 = MakeRegistryKeyName(v33, HKEY_LOCAL_MACHINE, &psz, &lpszKeyName);
            LOBYTE(v70) = 25;
            v21 = MakeRegistryKeyName(v39, HKEY_LOCAL_MACHINE, &psz, &v58);
            LOBYTE(v70) = 26;
            v65 = sub_FD3D40(v6, &lpszKeyName, v21, v20, &v64, &v55, &v49, &v35);
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
                str3.m_String = _wcsdup(&gszNullString);
                v62.m_String = _wcsdup(&gszNullString);
                v60 = _wcsdup(&gszNullString);
                v56 = _wcsdup(&gszNullString);
                LOBYTE(v70) = 34;
                v22 = MakeRegistryKeyName(v32, HKEY_LOCAL_MACHINE, &psz, &v60);
                LOBYTE(v70) = 35;
                v23 = MakeRegistryKeyName(v37, HKEY_LOCAL_MACHINE, &psz, &v56);
                LOBYTE(v70) = 36;
                ppv1 = sub_FD3FF0(v6, 0, 0xFFFFFFFF, 0, v23, v22, &v62);
                free(*v37);
                free(*v32);
                free(v56);
                free(v60);
                free(v62.m_String);
                free(str3.m_String);
                free(v43);
                free(v45);
                free(a1a);
                free(*szArg);
              }
              str2 = _wcsdup(&gszNullString);
              LOBYTE(v70) = 37;
              v24 = MakeRegistryKeyName(v40, HKEY_LOCAL_MACHINE, &psz, &lpszKeyName);
              LOBYTE(v70) = 38;
              sub_FD3FF0(v6, a2, ppv1, 0xBu, &ppv3, v24, &v64);
              free(*v40);
              free(str2);
            }
            free(ppv3);
            sub_FD21F0(pszText2);
            LOBYTE(v70) = 19;
            free(szArg4);
          }
          RegCloseKey(hKey);
        }
        ++v7;
      }
      while ( !PE_LoadRegKeys(hRootKey, v7, &lpszKeyName) );
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
    free(v64.m_String);
  }
  free(psz);
}

//----- (00FF3B60) --------------------------------------------------------
_DWORD *__thiscall sub_FF3B60(_DWORD *this, int a2, _DWORD **a3, int a4)
{
  _DWORD *result; // eax

  result = sub_FF6B70(this);
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

//----- (00FF3BA0) --------------------------------------------------------
CSystemProcessInfoMapNode *__thiscall sub_FF3BA0(CSystemProcessInfoMap *this, int a2, const wchar_t ***a3, int a4)
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

//----- (00FF3BE0) --------------------------------------------------------
int __thiscall sub_FF3BE0(_DWORD *this, int a2, char a3, int a4, int a5, void *a6)
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

//----- (00FF3E00) --------------------------------------------------------
int __thiscall sub_FF3E00(_DWORD *this, int a2, char a3, int a4, int a5, void *a6)
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

//----- (00FF4040) --------------------------------------------------------
int __thiscall sub_FF4040(_DWORD *this, int a2, int a3, int a4, void *a5)
{
  _DWORD *v5; // ebx
  bool v6; // zf
  int result; // eax
  std_Tree_node_for_tagKeyName *v8; // edi
  int v9; // edx
  unsigned int v10; // ecx
  bool v11; // cf
  int v12; // ecx
  int v13; // [esp+0h] [ebp-30h]
  int v14; // [esp+10h] [ebp-20h]
  _DWORD *v15; // [esp+14h] [ebp-1Ch]
  unsigned int v16; // [esp+18h] [ebp-18h]
  std__tree v17; // [esp+1Ch] [ebp-14h]
  int v18; // [esp+2Ch] [ebp-4h]

  v17._Mypair._Myval2._Mysize = &v13;
  v5 = this;
  v15 = this;
  v6 = this[1] == 0;
  v18 = 0;
  if ( v6 )
  {
    sub_FF3BE0(this, a2, 1, *this, a4, a5);
    return a2;
  }
  v8 = *this;
  if ( a3 == **this )
  {
    if ( *a4 < *(a3 + 16) )
    {
      sub_FF3BE0(this, a2, 1, a3, a4, a5);
      return a2;
    }
    goto LABEL_23;
  }
  if ( a3 == v8 )
  {
    v9 = v8->_Right;
    if ( *(v9 + 16) < *a4 )
    {
      sub_FF3BE0(this, a2, 0, v9, a4, a5);
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
    if ( v17._Mypair._Myval2._Myhead->_Myval.first < v16 )
    {
      if ( v17._Mypair._Myval2._Myhead->_Right->_IsNil )
        sub_FF3BE0(v5, a2, 0, v17._Mypair._Myval2._Myhead, a4, a5);
      else
        sub_FF3BE0(v5, a2, 1, a3, a4, a5);
      return a2;
    }
    v11 = *(a3 + 16) < v16;
  }
  if ( !v11
    || (v17._Mypair._Myval2._Myhead = a3, sub_FF4CE0(&v17), v17._Mypair._Myval2._Myhead != v8)
    && v16 >= v17._Mypair._Myval2._Myhead->_Myval.first )
  {
LABEL_23:
    v18 = -1;
    v12 = *sub_FF44A0(v5, &v14, 0, a4, a5);
    result = a2;
    *a2 = v12;
    return result;
  }
  if ( *(*(a3 + 8) + 13) )
    sub_FF3BE0(v5, a2, 0, a3, a4, a5);
  else
    sub_FF3BE0(v5, a2, 1, v17._Mypair._Myval2._Myhead, a4, a5);
  return a2;
}
// 10681AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);

//----- (00FF4270) --------------------------------------------------------
int __thiscall sub_FF4270(_DWORD *this, int a2, int a3, int a4, void *a5)
{
  _DWORD *v5; // ebx
  bool v6; // zf
  int result; // eax
  std_Tree_node_for_tagKeyName *v8; // edi
  int v9; // edx
  unsigned int v10; // ecx
  bool v11; // cf
  int v12; // ecx
  int v13; // [esp+0h] [ebp-30h]
  int v14; // [esp+10h] [ebp-20h]
  _DWORD *v15; // [esp+14h] [ebp-1Ch]
  unsigned int v16; // [esp+18h] [ebp-18h]
  std__tree v17; // [esp+1Ch] [ebp-14h]
  int v18; // [esp+2Ch] [ebp-4h]

  v17._Mypair._Myval2._Mysize = &v13;
  v5 = this;
  v15 = this;
  v6 = this[1] == 0;
  v18 = 0;
  if ( v6 )
  {
    sub_FF3E00(this, a2, 1, *this, a4, a5);
    return a2;
  }
  v8 = *this;
  if ( a3 == **this )
  {
    if ( *a4 < *(a3 + 16) )
    {
      sub_FF3E00(this, a2, 1, a3, a4, a5);
      return a2;
    }
    goto LABEL_23;
  }
  if ( a3 == v8 )
  {
    v9 = v8->_Right;
    if ( *(v9 + 16) < *a4 )
    {
      sub_FF3E00(this, a2, 0, v9, a4, a5);
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
    if ( v17._Mypair._Myval2._Myhead->_Myval.first < v16 )
    {
      if ( v17._Mypair._Myval2._Myhead->_Right->_IsNil )
        sub_FF3E00(v5, a2, 0, v17._Mypair._Myval2._Myhead, a4, a5);
      else
        sub_FF3E00(v5, a2, 1, a3, a4, a5);
      return a2;
    }
    v11 = *(a3 + 16) < v16;
  }
  if ( !v11
    || (v17._Mypair._Myval2._Myhead = a3, sub_FF4CE0(&v17), v17._Mypair._Myval2._Myhead != v8)
    && v16 >= v17._Mypair._Myval2._Myhead->_Myval.first )
  {
LABEL_23:
    v18 = -1;
    v12 = *sub_FF45C0(v5, &v14, 0, a4, a5);
    result = a2;
    *a2 = v12;
    return result;
  }
  if ( *(*(a3 + 8) + 13) )
    sub_FF3E00(v5, a2, 0, a3, a4, a5);
  else
    sub_FF3E00(v5, a2, 1, v17._Mypair._Myval2._Myhead, a4, a5);
  return a2;
}
// 10681AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);

//----- (00FF44A0) --------------------------------------------------------
int __thiscall sub_FF44A0(_DWORD *this, int a2, int a3, int a4, void *a5)
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
      v12 = sub_FF3BE0(this, &a3, 1, v6, a4, a5);
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
    v12 = sub_FF3BE0(v17, &a3, v18, v6, v7, a5);
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
// 10681AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);

//----- (00FF45C0) --------------------------------------------------------
int __thiscall sub_FF45C0(_DWORD *this, int a2, int a3, int a4, void *a5)
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
      v12 = sub_FF3E00(this, &a3, 1, v6, a4, a5);
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
    v12 = sub_FF3E00(v17, &a3, v18, v6, v7, a5);
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
// 10681AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);

//----- (00FF4700) --------------------------------------------------------
void **__cdecl sub_FF4700(const wchar_t **a1, const wchar_t **a2, void **a3)
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

//----- (00FF4740) --------------------------------------------------------
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
  *sub_FF4C50(&gMap6, &v7) = v1;
  free(v7);
  *v1 = &ActiveScriptEventConsumer::`vftable';
  v4 = *(v1 + 1);
  *(v1 + 1) = _wcsdup(L"The ActiveScriptEventConsumer class runs a predefined script in an arbitrary scripting ");
  free(v4);
  CPEString::InsertAt(
    v1 + 1,
    L"language when an event is delivered to it. This class is one of the standard event consumers that WMI provides.",
    0x7FFFFFFFu,
    0);
  v5 = *(v1 + 2);
  *(v1 + 2) = _wcsdup(L"http://msdn.microsoft.com/en-us/library/aa384749(v=vs.85).aspx");
  free(v5);
  return v1;
}
// 1092E48: using guessed type void *EventConsumerDescBase::`vftable';
// 1093110: using guessed type void *ActiveScriptEventConsumer::`vftable';

//----- (00FF4830) --------------------------------------------------------
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
  *sub_FF4C50(&gMap6, &v7) = v1;
  free(v7);
  *v1 = &CommandLineEventConsumer::`vftable';
  v4 = *(v1 + 1);
  *(v1 + 1) = _wcsdup(L"The CommandLineEventConsumer class starts an arbitrary process in the local system ");
  free(v4);
  CPEString::InsertAt(
    v1 + 1,
    L"when an event is delivered to it. This class is one of the standard event consumers that WMI provides.",
    0x7FFFFFFFu,
    0);
  v5 = *(v1 + 2);
  *(v1 + 2) = _wcsdup(L"http://msdn.microsoft.com/en-us/library/aa389231(v=vs.85).aspx");
  free(v5);
  return v1;
}
// 1092E48: using guessed type void *EventConsumerDescBase::`vftable';
// 1092E60: using guessed type void *CommandLineEventConsumer::`vftable';

//----- (00FF4920) --------------------------------------------------------
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

//----- (00FF4A70) --------------------------------------------------------
volatile LONG *__thiscall sub_FF4A70(volatile LONG *this, volatile LONG a2)
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

//----- (00FF4B00) --------------------------------------------------------
void __thiscall sub_FF4B00(CSystemProcessInfoMap *this)
{
  CSystemProcessInfoMap *v1; // esi
  int v2; // [esp+4h] [ebp-4h]

  v1 = this;
  sub_FF71F0(this, &v2, this->_Header->_Left, this->_Header);
  j__free(v1->_Header);
}

//----- (00FF4B60) --------------------------------------------------------
void **__thiscall sub_FF4B60(void **this, void **a2)
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

//----- (00FF4BC0) --------------------------------------------------------
_DWORD *__thiscall sub_FF4BC0(int *this, _DWORD *a2)
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
  v6 = sub_FF3B60(this, &dword_10C4D34, &v7, &a2 + 3);
  sub_FF4270(v2, &a2, v3, (v6 + 4), v6);
  return a2 + 5;
}
// 10C4D34: using guessed type int dword_10C4D34;

//----- (00FF4C50) --------------------------------------------------------
std_Tree_node_for_tagKeyName **__thiscall sub_FF4C50(CSystemProcessInfoMap *this, _DWORD *a2)
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
    if ( v4->_Myval.first >= *a2 )
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
  v6 = sub_FF3BA0(this, &dword_10C4D34, &v7, &a2 + 3);
  sub_FF4040(v2, &a2, v3, &v6->_Keyvalue, v6);
  return (a2 + 5);
}
// 10C4D34: using guessed type int dword_10C4D34;

//----- (00FF4CE0) --------------------------------------------------------
std__tree *__thiscall sub_FF4CE0(std__tree *this)
{
  std__tree *v1; // edx
  std_Tree_node_for_tagKeyName *v2; // eax
  std_Tree_node_for_tagKeyName *v3; // ecx
  std_Tree_node_for_tagKeyName *v4; // eax
  std_Tree_node_for_tagKeyName *i; // eax

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

//----- (00FF4D30) --------------------------------------------------------
void *__thiscall std::error_category::`vector deleting destructor'(void *this, char a2)
{
  void *v2; // esi

  v2 = this;
  *this = &std::error_category::`vftable';
  if ( a2 & 1 )
    j__free(this);
  return v2;
}
// 1092D74: using guessed type void *std::error_category::`vftable';

//----- (00FF4D60) --------------------------------------------------------
void sub_FF4D60()
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

//----- (00FF4DA0) --------------------------------------------------------
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
      v2 = sub_FF4A70(v3, lpszServerName);
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

//----- (00FF4E20) --------------------------------------------------------
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
// 10BAA38: using guessed type char bInited;

//----- (00FF4FE0) --------------------------------------------------------
void *__cdecl sub_FF4FE0(int a1, void *a2)
{
  void *result; // eax
  void *v3; // esi
  void *v4; // [esp+8h] [ebp-24h]
  void *v5; // [esp+Ch] [ebp-20h]
  void *v6; // [esp+10h] [ebp-1Ch]
  void *v7; // [esp+14h] [ebp-18h]
  void *v8; // [esp+18h] [ebp-14h]
  CPEString str3; // [esp+1Ch] [ebp-10h]
  int v10; // [esp+28h] [ebp-4h]

  result = a2;
  if ( a2 == -1 )
  {
    a2 = _wcsdup(L"WMI Database Entries");
    v10 = 0;
    if ( !IsBuiltinAdministrative() )
      CPEString::InsertAt(&a2, L" - run as Administrator for complete scan", 0x7FFFFFFFu, 0);
    v4 = _wcsdup(&gszNullString);
    v5 = _wcsdup(&gszNullString);
    v6 = _wcsdup(&gszNullString);
    v7 = _wcsdup(&gszNullString);
    v8 = _wcsdup(&gszNullString);
    str3.m_String = _wcsdup(&gszNullString);
    LOBYTE(v10) = 6;
    v3 = sub_FD3FF0(a1, 2u, 0xFFFFFFFF, 0, &a2, &a2, &str3);
    free(str3.m_String);
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

//----- (00FF5120) --------------------------------------------------------
int __cdecl sub_FF5120(IWbemServices *pWbemServices, int a2)
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
        sub_FDFDF0(a2, v20);
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
        sub_FDFDF0(a2, v13);
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

//----- (00FF5350) --------------------------------------------------------
char __stdcall sub_FF5350(int a1, void *pClassObject, int a3)
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

//----- (00FF5440) --------------------------------------------------------
bool __stdcall sub_FF5440(int a1, void *lpszName, void *a3)
{
  const wchar_t **v3; // eax
  WCHAR **v4; // edi
  void *v5; // esi
  WCHAR *v6; // ecx
  WCHAR v7; // ax
  const wchar_t **v8; // eax
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
  if ( v6 - (*v4 + 1) )
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
    ++v10;
  }
  while ( v11 );
  if ( !(v10 - (*v4 + 1)) )
    return 0;
  a2 = malloc(2u);
  *a2 = 0;
  v19 = 0;
  v20 = 0;
  v21 = 0;
  v23 = 0;
  if ( !sub_FD6CC0(*v4, &a2) )
  {
    sub_FD21F0(&a2);
    return 0;
  }
  v12 = sub_FD4EE0(&a3, a1, &a2, 0);
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
  v16 = v14 - (*v4 + 1);
  sub_FD21F0(&a2);
  return v16 >> 1 != 0;
}

//----- (00FF55B0) --------------------------------------------------------
int __cdecl sub_FF55B0(const wchar_t **a1)
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

//----- (00FF5630) --------------------------------------------------------
char __thiscall sub_FF5630(void *this, int a2, wchar_t *lpszName, void **a4)
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

//----- (00FF56B0) --------------------------------------------------------
char __thiscall sub_FF56B0(void *this, int a2, wchar_t *lpszName, void **a4)
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

//----- (00FF5730) --------------------------------------------------------
int __cdecl sub_FF5730(LPVOID ppv, int lpszName, OLECHAR *psz, void *lpszText)
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
  CPEString v14; // [esp+18h] [ebp-10h]
  int v15; // [esp+24h] [ebp-4h]

  v4 = 0;
  v13 = 0;
  v5 = malloc(2u);
  v14.m_String = v5;
  *v5 = 0;
  v15 = 0;
  v6 = GetClassObjectName(&pClassObject, lpszName);
  v7 = _wcsdup(*v6);
  v14.m_String = v7;
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
      CPEString::InsertAt(&v14, lpszText, 0x7FFFFFFFu, 0);
      if ( v8 )
        CPEString::InsertAt(&v14, L"\"", 0x7FFFFFFFu, 0);
      v7 = v14.m_String;
    }
    v10 = sub_FF5850(ppv, v7, &v13);
    v4 = v13;
    if ( v10 < 0 )
      v4 = 0;
  }
  free(v7);
  return v4;
}

//----- (00FF5850) --------------------------------------------------------
HRESULT __cdecl sub_FF5850(LPVOID ppv, wchar_t *psz, int a3)
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
  result = sub_FF5BE0(&ppv, v5);
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

//----- (00FF5910) --------------------------------------------------------
wchar_t **__stdcall sub_FF5910(wchar_t **a1, int a2)
{
  *a1 = _wcsdup(&gszNullString);
  return a1;
}

//----- (00FF5940) --------------------------------------------------------
int __stdcall sub_FF5940(int pClassObject, void *lpszName)
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

//----- (00FF5A00) --------------------------------------------------------
char __stdcall sub_FF5A00(void *lpszName, int a2, int a3)
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

//----- (00FF5AA0) --------------------------------------------------------
char __stdcall sub_FF5AA0(int a1, int a2, int a3)
{
  return 0;
}

//----- (00FF5AB0) --------------------------------------------------------
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

//----- (00FF5BE0) --------------------------------------------------------
HRESULT __cdecl sub_FF5BE0(LPVOID *ppv, wchar_t *a2)
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

//----- (00FF5C50) --------------------------------------------------------
bool __stdcall sub_FF5C50(void *pClassObject, int a2)
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

//----- (00FF5CB0) --------------------------------------------------------
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

//----- (00FF5D10) --------------------------------------------------------
void __cdecl sub_FF5D10(int a1)
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
  const wchar_t **v15; // esi
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
  CPEString *v48; // esi
  IWbemClassObjectVtbl *v49; // edi
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
  WCHAR *v74; // [esp+38h] [ebp-8Ch]
  LPCWSTR lpszSystemPath; // [esp+3Ch] [ebp-88h]
  wchar_t *v76; // [esp+40h] [ebp-84h]
  int v77; // [esp+44h] [ebp-80h]
  wchar_t *v78; // [esp+48h] [ebp-7Ch]
  void *v79; // [esp+4Ch] [ebp-78h]
  IWbemClassObject *pClassObject; // [esp+50h] [ebp-74h]
  void *ppv1; // [esp+54h] [ebp-70h]
  void *theMap; // [esp+58h] [ebp-6Ch]
  int v83; // [esp+5Ch] [ebp-68h]
  std__vector v84; // [esp+60h] [ebp-64h]
  CPEString str2; // [esp+6Ch] [ebp-58h]
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
  wchar_t *a4; // [esp+B4h] [ebp-10h]
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
  str2.m_String = malloc(2u);
  *str2.m_String = 0;
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
  lpszSystemPath = malloc(2u);
  *lpszSystemPath = 0;
  LOBYTE(v104) = 11;
  ppv1 = sub_FF4FE0(a1, 0xFFFFFFFF);
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
          v6 = sub_FF55B0(v5) != 0;
          free(pClassObject);
          if ( v6 )
          {
            v91 = 0;
            v92 = 0;
            v93 = 0;
            LOBYTE(v104) = 13;
            v7 = sub_FF4BC0(&theMap, &lpszName);
            sub_FF4B60(v7, &v91);
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
        sub_FE0530(&v84, &a2);
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
            sub_FF4700(v9 + 1, v8, v9);
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
              v13 = sub_FF5120(pWbemServices, &v91);
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
                    CPEString::InsertAt(&ppv, L"\\", 0x7FFFFFFFu, 0);
                    CPEString::InsertAt(&ppv, *v15, 0x7FFFFFFFu, 0);
                    sub_FE0530(&v84, &ppv);
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
                  sub_FF6830(a1, v17, pWbemServices, lpszName, &theMap);
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
            ppEnumOut = sub_FF55B0(v25);
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
              v33 = str2.m_String;
              str2.m_String = _wcsdup(*v32);
              free(v33);
              free(v68);
              if ( (ppEnumOut->lpVtbl->Reset)(v94, &lpszSystemPath) )
              {
                a4 = malloc(2u);
                *a4 = 0;
                LOBYTE(v104) = 19;
                if ( PE_GetPathName(a1, lpszSystemPath, psz, &a4) )
                {
                  v34 = psz;
                  psz = _wcsdup(a4);
                  free(v34);
                }
                LOBYTE(v104) = 12;
                free(a4);
              }
              pClassObject = sub_FD4ED0();
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
            v95 = sub_FD3D40(a1, &v69, &v72, &str2, &psz, &v79, &v74, &v70);
            free(v69);
            LOBYTE(v104) = 12;
            free(v72);
            if ( v95 )
            {
              v37 = operator new(0x18u);
              a4 = v37;
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
                a4 = 0;
              }
              v41 = v94;
              *(v37 + 1) = v94;
              v41->lpVtbl->AddRef(v41);
              v42 = (v37 + 12);
              v43 = *(v37 + 3);
              v86 = v42;
              v44 = _wcsdup(&gszNullString);
              *(a4 + 3) = v44;
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
                      v50 = v48->m_String;
                      do
                      {
                        v51 = *v50;
                        ++v50;
                      }
                      while ( v51 );
                      if ( v50 - (v48->m_String + 1) )
                        CPEString::InsertAt(v48, L"; ", 0x7FFFFFFFu, 0);
                      CPEString::InsertAt(v48, v49, 0x7FFFFFFFu, 0);
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
                v52 = *(a4 + 4);
                v53 = _wcsdup(v78);
                *(a4 + 4) = v53;
                free(v52);
                v54 = *(a4 + 5);
                v55 = _wcsdup(v76);
                *(a4 + 5) = v55;
                free(v54);
                *(a4 + 8) = 1;
              }
              ppv1 = sub_FF4FE0(a1, ppv1);
              cbReturned = _wcsdup(&gszNullString);
              LOBYTE(v104) = 22;
              sub_FD3FF0(a1, pClassObject, ppv1, 0x11u, &ppv3, &str2, &psz);
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
        sub_FF4D60();
      }
      LOBYTE(v104) = 11;
      if ( pEnum )
        pEnum->lpVtbl->Release(pEnum);
    }
  }
  free(lpszSystemPath);
  free(v76);
  free(v78);
  free(psz);
  free(v73);
  free(v74);
  free(v79);
  free(v88);
  free(str2.m_String);
  free(ppv3);
  LOBYTE(v104) = 0;
  sub_FF71F0(&theMap, &v90, *theMap, theMap);
  j__free(theMap);
  if ( v2 )
  {
    for ( k = v2; k != v1; ++k )
      free(*k);
    j__free(v2);
  }
}

//----- (00FF6830) --------------------------------------------------------
unsigned int __cdecl sub_FF6830(int a1, int a2, LPVOID ppv, int a4, int a5)
{
  int v5; // eax
  wchar_t *v6; // esi
  int v7; // ebx
  std_Tree_node_for_tagKeyName *v8; // ebx
  std_Tree_node_for_tagKeyName *v9; // esi
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
  lpszName = sub_FF5730(ppv, a4, L"Consumer", 0);
  v5 = sub_FF5730(ppv, a4, L"Filter", 0);
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
      if ( sub_FF55B0(&pClassObject) )
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
            GetClassObjectName(&v13, v9->_Myval.first);
            v10 = v13.lpVtbl;
            LOBYTE(v19) = 2;
            if ( !_wcsicmp(v16.lpVtbl, v13.lpVtbl) )
              break;
            LOBYTE(v19) = 1;
            free(v10);
            sub_FF4CE0(&v18);
            v9 = v18._Mypair._Myval2._Myhead;
            if ( v18._Mypair._Myval2._Myhead == v8 )
              goto LABEL_7;
          }
          std::vector<tagAccountInfo *,std::allocator<tagAccountInfo *>>::push_back(&v9->_Myval.second, &v12);
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

//----- (00FF69A0) --------------------------------------------------------
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

//----- (00FF6B70) --------------------------------------------------------
_DWORD *__thiscall sub_FF6B70(_DWORD *this)
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

//----- (00FF6BB0) --------------------------------------------------------
_DWORD *__thiscall sub_FF6BB0(_DWORD *this, int a2, size_t a3)
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
// 10681AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);

//----- (00FF6D00) --------------------------------------------------------
void __stdcall sub_FF6D00(void *a1)
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

//----- (00FF6D40) --------------------------------------------------------
void __stdcall sub_FF6D40(void *a1)
{
  free(*(a1 + 4));
  j__free(a1);
}

//----- (00FF6D60) --------------------------------------------------------
void __stdcall sub_FF6D60(void *a1)
{
  void **v1; // esi
  void **v2; // edi

  v1 = a1;
  v2 = a1;
  if ( !*(a1 + 13) )
  {
    do
    {
      sub_FF6D60(v2[2]);
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

//----- (00FF6DC0) --------------------------------------------------------
void __stdcall sub_FF6DC0(void *a1)
{
  void **v1; // edi
  void **v2; // esi

  v1 = a1;
  v2 = a1;
  if ( !*(a1 + 13) )
  {
    do
    {
      sub_FF6DC0(v2[2]);
      v2 = *v2;
      free(v1[4]);
      j__free(v1);
      v1 = v2;
    }
    while ( !*(v2 + 13) );
  }
}

//----- (00FF6E00) --------------------------------------------------------
BOOL __thiscall sub_FF6E00(void *this, size_t a2, int a3)
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
    sub_FF6BB0(this, a2, *(this + 4));
    result = a2 > 0;
  }
  return result;
}

//----- (00FF6EC0) --------------------------------------------------------
void *__stdcall sub_FF6EC0(size_t a1)
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

//----- (00FF6F00) --------------------------------------------------------
string *__thiscall sub_FF6F00(string *this, int a2, int a3, size_t a4)
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
      sub_FF6BB0(v5, v8, v5->_Myval2._Mysize);
      v6 = a3;
      if ( !v8 )
        return v5;
    }
    if ( *(a2 + 20) >= 0x10u )
      v4 = *a2;
    if ( v5->_Myval2._Myres < 0x10 )
      v13 = v5;
    else
      v13 = v5->_Myval2._Bx._Ptr;
    if ( v8 )
      memmove_0(v13, (v4 + v6), v8);
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
  sub_FF7890(v5, 0, a3);
  return v5;
}

//----- (00FF7030) --------------------------------------------------------
string *__thiscall sub_FF7030(string *this, void *a2, size_t a3)
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
    v5 = (v4 < 0x10 ? v3 : v3->_Myval2._Bx._Ptr);
    if ( a2 >= v5 )
    {
      v6 = v4 < 0x10 ? v3 : v3->_Myval2._Bx._Ptr;
      if ( v6 + v3->_Myval2._Mysize > a2 )
      {
        if ( v4 < 0x10 )
          result = sub_FF6F00(v3, v3, a2 - v3, a3);
        else
          result = sub_FF6F00(v3, v3, a2 - v3->_Myval2._Bx._Ptr, a3);
        return result;
      }
    }
  }
  if ( a3 > 0xFFFFFFFE )
    std::_Xlength_error("string too long");
  v8 = v3->_Myval2._Myres;
  if ( v8 < a3 )
  {
    sub_FF6BB0(v3, a3, v3->_Myval2._Mysize);
    if ( !a3 )
      return v3;
LABEL_16:
    if ( v3->_Myval2._Myres < 0x10 )
      v9 = v3;
    else
      v9 = v3->_Myval2._Bx._Ptr;
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

//----- (00FF7130) --------------------------------------------------------
int *__stdcall std::_System_error_category::default_error_condition(int *a1, int a2)
{
  bool v2; // zf
  int *result; // eax

  v2 = sub_106465F(a2) == 0;
  result = a1;
  *a1 = a2;
  if ( v2 )
    a1[1] = &off_10BAA44;
  else
    a1[1] = off_10BAA3C;
  return result;
}
// 10BAA3C: using guessed type int (__thiscall **off_10BAA3C[3])(void *, char);
// 10BAA44: using guessed type int (__thiscall **off_10BAA44)(void *, char);

//----- (00FF7190) --------------------------------------------------------
bool __thiscall std::error_category_equivalent(void *this, _DWORD *a2, int a3)
{
  return this == a2[1] && *a2 == a3;
}

//----- (00FF71B0) --------------------------------------------------------
bool __thiscall std::error_category_equivalent2(void *this, int a2, _DWORD *a3)
{
  _DWORD *v3; // eax
  char v5; // [esp+0h] [ebp-8h]

  v3 = (*(*this + 12))(&v5, a2);
  return v3[1] == a3[1] && *v3 == *a3;
}

//----- (00FF71F0) --------------------------------------------------------
int __thiscall sub_FF71F0(CSystemProcessInfoMap *this, int a2, void *a3, int a4)
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
      sub_FF72B0(v5, &v13, v10);
    }
    *a2 = v4;
    result = a2;
  }
  else
  {
    sub_FF6D60(v6->_Parent);
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

//----- (00FF72B0) --------------------------------------------------------
int __thiscall sub_FF72B0(CSystemProcessInfoMap *this, int a2, void *a3)
{
  std_Tree_node_for_tagKeyName **v3; // ebx
  std_Tree_node_for_tagKeyName *v4; // edi
  std_Tree_node_for_tagKeyName *v5; // ecx
  std__Tree_node *v6; // esi
  std__tree *v7; // edx
  std_Tree_node_for_tagKeyName *v8; // eax
  std__Tree_node *v9; // ecx
  std__Tree_node *v10; // eax
  std_Tree_node_for_tagKeyName *v11; // eax
  std_Tree_node_for_tagKeyName *i; // ecx
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

  v3 = a3;
  v23 = this;
  sub_FF4CE0(&a3);
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
      *v13 = &v5->_Left;
    else
      v13[2] = &v5->_Left;
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
          sub_10554B0(v7, v6);
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
            sub_1062BB0(v7, v15);
            v15 = v6->_Right;
          }
          v15->_Color = v6->_Color;
          v6->_Color = 1;
          v16 = v6;
          v17 = v23;
          v15->_Right->_Color = 1;
          sub_10554B0(v23, v16);
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
          sub_1062BB0(v7, v6);
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
            sub_10554B0(v7, v15);
            v15 = v6->_Left;
          }
          v15->_Color = v6->_Color;
          v6->_Color = 1;
          v18 = v6;
          v17 = v23;
          v15->_Left->_Color = 1;
          sub_1062BB0(v23, v18);
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

//----- (00FF7560) --------------------------------------------------------
CSystemProcessInfoMapNode **__thiscall sub_FF7560(CSystemProcessInfoMap *this, CSystemProcessInfoMapNode **a2, CSystemProcessInfoMapNode *a3, CSystemProcessInfoMapNode *a4)
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
      sub_FF7620(v5, &v13, v10);
    }
    *a2 = v4;
    result = a2;
  }
  else
  {
    sub_FF6DC0(v6->baseclass._Parent);
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

//----- (00FF7620) --------------------------------------------------------
CSystemProcessInfoMapNode **__thiscall sub_FF7620(CSystemProcessInfoMap *this, CSystemProcessInfoMapNode **a2, CSystemProcessInfoMapNode *a3)
{
  std__tree *v3; // ebx
  CSystemProcessInfoMapNode *v4; // ecx
  CSystemProcessInfoMapNode *v5; // edi
  CSystemProcessInfoMapNode *v6; // edx
  std__Tree_node *v7; // esi
  std_Tree_node_for_tagKeyName *v8; // eax
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

  v3 = this;
  v19 = a3;
  sub_FF4CE0(&a3);
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

//----- (00FF7890) --------------------------------------------------------
_DWORD *__thiscall sub_FF7890(_DWORD *this, unsigned int a2, unsigned int a3)
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
