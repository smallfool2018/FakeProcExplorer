
//----- (00FF7930) --------------------------------------------------------
int __stdcall std::_Generic_error_category_message(int a1, int a2)
{
  int v2; // eax
  char *v3; // edx

  v2 = sub_106465F(a2);
  v3 = "unknown error";
  if ( v2 )
    v3 = v2;
  *(a1 + 20) = 15;
  *(a1 + 16) = 0;
  *a1 = 0;
  if ( *v3 )
    sub_FF7030(a1, v3, strlen(v3));
  else
    sub_FF7030(a1, v3, 0);
  return a1;
}

//----- (00FF79A0) --------------------------------------------------------
int __stdcall std::_Iostream_error_category_message(int a1, int a2)
{
  if ( a2 == 1 )
  {
    *(a1 + 20) = 15;
    *(a1 + 16) = 0;
    *a1 = 0;
    sub_FF7030(a1, "iostream stream error", 0x15u);
  }
  else
  {
    std::_Generic_error_category_message(a1, a2);
  }
  return a1;
}

//----- (00FF79F0) --------------------------------------------------------
int __stdcall std::_System_error_category_message(int a1, int a2)
{
  int v2; // eax
  char *v3; // edx

  v2 = sub_1064689(a2);
  v3 = "unknown error";
  if ( v2 )
    v3 = v2;
  *(a1 + 20) = 15;
  *(a1 + 16) = 0;
  *a1 = 0;
  if ( *v3 )
    sub_FF7030(a1, v3, strlen(v3));
  else
    sub_FF7030(a1, v3, 0);
  return a1;
}

//----- (00FF7A60) --------------------------------------------------------
const char *std::_Generic_error_category_name()
{
  return "generic";
}

//----- (00FF7A70) --------------------------------------------------------
const char *std::_Iostream_error_category_name()
{
  return "iostream";
}

//----- (00FF7A80) --------------------------------------------------------
const char *std::_System_error_category_name()
{
  return "system";
}

//----- (00FF7AA0) --------------------------------------------------------
int swprintf(wchar_t *pszBuffer, const wchar_t *lpszFormat, ...)
{
  va_list ArgList; // [esp+10h] [ebp+10h]

  va_start(ArgList, lpszFormat);
  return vswprintf_s(pszBuffer, MAX_PATH, lpszFormat, ArgList);
}

//----- (00FF7AC0) --------------------------------------------------------
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

//----- (00FF7B60) --------------------------------------------------------
_DWORD **__cdecl sub_FF7B60(int a1, OLECHAR *psz, int a3, int a4)
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

//----- (00FF7C40) --------------------------------------------------------
int *__thiscall sub_FF7C40(char *this, _DWORD **a2)
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

//----- (00FF7CE0) --------------------------------------------------------
LONG __cdecl sub_FF7CE0(int a1)
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

//----- (00FF7D50) --------------------------------------------------------
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

//----- (00FF8250) --------------------------------------------------------
signed int __usercall sub_FF8250@<eax>(int a1@<edi>, int a2@<esi>, int a3, int a4)
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
// FF8250: could not find valid save-restore pair for edi
// FF8250: could not find valid save-restore pair for esi

//----- (00FF8730) --------------------------------------------------------
_bstr_t *__thiscall sub_FF8730(tagWbemServicesList *pWbemServicesList, GUID *pIID, int Type, int Version, int Level)
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

//----- (00FF8970) --------------------------------------------------------
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
                    sub_FF9380(&theList, &v67);
                    if ( sub_FE0440(v66) )
                      sub_FD3A50(&v21->strEventTrace, v66);
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
                sub_FF9380(&theList, &v67);
                v28 = v66;
                if ( sub_FE0440(v66) )
                  sub_FD3A50(&v27->strEventTrace, v28);
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
                v14 = sub_FF8250(v30, v14, v54, v71);
                v31 = v54 & 0x2000 ? sub_FF7CE0(v71) : 1;
                sub_FF7B60(&theList, pv, v14, v31);
                ++rgIndices;
              }
              while ( rgIndices <= v53 );
              v14 = SafeArrayDestroy;
            }
            v14(psa);
            psa = 0;
          }
          sub_FF7C40(ppWbemServices, &theList);
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
  sub_FF7C40(ppWbemServices, &theList);
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

//----- (00FF92A0) --------------------------------------------------------
int __cdecl sub_FF92A0(wchar_t *Dst, size_t SizeInWords, int a3)
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

//----- (00FF92F0) --------------------------------------------------------
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

//----- (00FF9380) --------------------------------------------------------
_DWORD *__thiscall sub_FF9380(_DWORD *this, int a2)
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

//----- (00FF93D0) --------------------------------------------------------
_WORD *__thiscall sub_FF93D0(_WORD *this, OLECHAR *psz)
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

//----- (00FF9410) --------------------------------------------------------
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
// 10938D0: using guessed type GUID CLSID_IDispatch;
// 10938F0: using guessed type GUID CLSID_IShellFolderViewDual;

//----- (00FF94A0) --------------------------------------------------------
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

//----- (00FF9580) --------------------------------------------------------
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

//----- (00FF9700) --------------------------------------------------------
CRYPT_PROVIDER_SGNR *__cdecl sub_FF9700(HANDLE StateHandle, char bFlags, WINTRUST_DATA_EX **ActionData, PDWORD pdwValues, _CRYPT_PROVIDER_CERT **ppCertProviderContext, PCCERT_CONTEXT *ppCertContext)
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

  pProviderSgnr = StateHandle;
  dwValue = *pdwValues;
  *pdwValues = 0;
  if ( !StateHandle )
    return pProviderSgnr;
  pProviderSgnr = WTHelperProvDataFromStateData(StateHandle);
  if ( !pProviderSgnr )
    return pProviderSgnr;
  pProviderSgnr = WTHelperGetProvSignerFromChain(pProviderSgnr, 0, 0, 0);
  if ( !pProviderSgnr )
    return pProviderSgnr;
  if ( ActionData )
  {
    *ActionData = pProviderSgnr->sftVerifyAsOf.dwLowDateTime;
    ActionData[1] = pProviderSgnr->sftVerifyAsOf.dwHighDateTime;
  }
  if ( !bFlags )
    goto LABEL_9;
  if ( pProviderSgnr->csCounterSigners )
  {
    pProviderSgnr = pProviderSgnr->pasCounterSigners;
LABEL_9:
    pProviderContext = pProviderSgnr->pasCertChain;
    pProviderSgnr = pProviderSgnr->csCertChain;
    goto __quit3;
  }
  pProviderContext = ppCertProviderContext;
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
      pProviderSgnr = CertGetNameStringW(pProviderContext->pCert, CERT_NAME_FRIENDLY_DISPLAY_TYPE, 0, 0, szName, 0x400u);
      if ( pProviderSgnr )
        break;
LABEL_29:
      nIndex = ++pProviderSgnr3;
      if ( pProviderSgnr3 >= pProviderSgnr2 )
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
        pProviderSgnr = _wcsdup(pstr);
        ppCertProviderContext[*pdwValues] = pProviderSgnr;
        if ( ppCertContext )
        {
          pProviderSgnr = CertDuplicateCertificateContext(pProviderContext->pCert);
          ppCertContext[*pdwValues] = pProviderSgnr;
        }
        pProviderContext = (pProviderContext + pProviderContext->cbStruct);
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

//----- (00FF9930) --------------------------------------------------------
LONG __cdecl PE_CryptedVerify(HCATADMIN hCatAdmin, WCHAR *pcwszMemberFilePath, char fdwRevocationChecks, BYTE *pbHash, DWORD cbHash, WINTRUST_DATA_EX *pActionData, WCHAR **ppcwszCatalogFilePathIn, int dwIndex)
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
              pbHash,
              cbHash,
              pActionData,
              psCatInfo.wszCatalogFile,
              ppcwszCatalogFilePathIn,
              dwIndex);
  CryptCATAdminReleaseCatalogContext(hCatAdmin, hCatInfo, 0);
  return hresult;
}

//----- (00FF9A40) --------------------------------------------------------
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
      swprintf_s(pszBuffer, 3u, L"%02X", *(pszText1 + dwIdx));
      pszText1 = pszText;
      ++dwIdx;
      pszBuffer += 2;
    }
    while ( dwIdx < TextLen );
    ActionData = pActionData_;
  }
  pcwszCatalogFilePath = cwszCatalogFilePath;
  _mm_storeu_si128(&FileInfo, 0i64);
  FileInfo.pcwszCatalogFilePath = pcwszCatalogFilePath;
  _mm_storeu_si128(&FileInfo.pcwszMemberFilePath, 0i64);
  FileInfo.pcwszMemberFilePath = pcwszMemberFilePath;
  FileInfo.pcwszMemberTag = szBuffer;
  FileInfo.field_20 = 0;
  FileInfo.cbStruct = sizeof(WINTRUST_CATALOG_INFO_EX);
  FileInfo.TextLen = TextLen;
  FileInfo.pszText = pszText;
  memset(ActionData, 0, sizeof(WINTRUST_DATA_EX));
  ActionData->dwUIChoice = WTD_UI_NONE;
  ActionData->dwUnionChoice = WTD_CHOICE_CATALOG;
  ActionData->dwStateAction = HANDLE_FLAG_INHERIT;
  ActionData->cbStruct = 4 * (dwIndex != -1) + 0x30;
  ActionData->fdwRevocationChecks = fdwRevocationChecks != 0;
  ActionData->pFile = &FileInfo;
  if ( dwIndex != -1 )
  {
    _mm_storeu_si128(&Settings, 0i64);
    Settings.cbStruct = sizeof(WINTRUST_SIGNATURE_SETTINGS_);
    *&Settings.dwVerifiedSigIndex = 0i64;
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

//----- (00FF9BB0) --------------------------------------------------------
LONG __cdecl PE_DoubleVerify(LPCWSTR pcwszMemberFilePath, LPCWSTR pcwszCatalogFilePath, HCATADMIN hCatAdmin, bool fdwRevocationChecks, WINTRUST_DATA_EX **ppActionData, DWORD *pdwCertEncodingTypeCount1, PCCERT_CONTEXT *ppCertContext1, PCCERT_CHAIN_CONTEXT *ppCertChainContext1, DWORD *pdwCertEncodingTypeCount2, PCCERT_CONTEXT *ppCertContext2, PCCERT_CHAIN_CONTEXT *ppChainContext2, WCHAR **ppcwszCatalogFilePath, DWORD dwIndex)
{
  DWORD *pdwCertEncodingTypeCount2_1_1; // ebx
  const WCHAR *v14; // eax
  DWORD dwUnionChoice; // eax
  LONG result; // eax
  LONG lError1; // ecx
  WCHAR *v18; // eax
  HANDLE hFile; // ebx
  LONG v20; // eax
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
  LONG lResult; // [esp+90h] [ebp-2Ch]
  int dwHash; // [esp+94h] [ebp-28h]
  DWORD *pdwCertEncodingTypeCount2_1; // [esp+98h] [ebp-24h]
  LPCWSTR pcwszMemberFilePathIn; // [esp+9Ch] [ebp-20h]
  LONG lError; // [esp+A0h] [ebp-1Ch]
  WCHAR cbHash[10]; // [esp+A4h] [ebp-18h]

  pcwszMemberFilePathIn = pcwszMemberFilePath;
  pcwszCatalogFilePath_1 = pcwszCatalogFilePath;
  hCatAdmin_1 = hCatAdmin;
  ppActionData_1 = ppActionData;
  ppCertrContext1_1 = ppCertContext1;
  pdwCertEncodingTypeCount2_1_1 = pdwCertEncodingTypeCount2;
  ppCertChainContext1_1 = ppCertChainContext1;
  ppCertContext2_1 = ppCertContext2;
  pdwCertEncodingTypeCount2_1 = pdwCertEncodingTypeCount2;
  ppChainContext2_1 = ppChainContext2;
  dwHash = 20;
  lResult = TRUST_E_NOSIGNATURE;
  LoadWintrust();
  if ( ppcwszCatalogFilePath )
    *ppcwszCatalogFilePath = 0;
  v14 = pcwszMemberFilePathIn;
  _mm_storeu_si128(&FileInfo, 0i64);
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
  ActionData.pFile = &FileInfo;
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
  ActionData.pFile = &FileInfo;
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
  if ( *CryptCATAdminAcquireContext )
  {
    hFile = CreateFileW(pcwszMemberFilePathIn, GENERIC_READ, FILE_SHARE_READ, 0, 3u, FILE_ATTRIBUTE_NORMAL, 0);
    if ( hFile == INVALID_HANDLE_VALUE )
    {
LABEL_30:
      pdwCertEncodingTypeCount2_1_1 = pdwCertEncodingTypeCount2_1;
      result = lError;
      goto __returnOK;
    }
    if ( !CryptCATAdminCalcHashFromFileHandle(hFile, &dwHash, cbHash, 0) )
    {
      CloseHandle(hFile);
      goto LABEL_30;
    }
    CloseHandle(hFile);
    if ( hCatAdmin_1 )
    {
      v20 = PE_CryptedVerify(
              *hCatAdmin_1,
              pcwszMemberFilePathIn,
              fdwRevocationChecks,
              cbHash,
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
              pcwszMemberFilePathIn,
              fdwRevocationChecks,
              cbHash,
              dwHash,
              &ActionData,
              pcwszCatalogFilePath_1,
              ppcwszCatalogFilePath,
              dwIndex);
    }
    lResult = v20;
    if ( !v20 )
      goto LABEL_30;
LABEL_28:
    CryptCATAdminAcquireContext(&phCatAdmin, 0, 0);
    lResult = PE_CryptedVerify(
                phCatAdmin,
                pcwszMemberFilePathIn,
                fdwRevocationChecks,
                cbHash,
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
    sub_FF9700(
      ActionData.hWVTStateData,
      0,
      ppActionData_1,
      pdwCertEncodingTypeCount1,
      ppCertrContext1_1,
      ppCertChainContext1_1);
  if ( pdwCertEncodingTypeCount2_1_1 )
    sub_FF9700(ActionData.hWVTStateData, 1, 0, pdwCertEncodingTypeCount2_1_1, ppCertContext2_1, ppChainContext2_1);
  ActionData.dwStateAction = HANDLE_FLAG_PROTECT_FROM_CLOSE;
  WinVerifyTrust(0, &GUID_ActionID, &ActionData);
  return 0;
}
// FF9F40: using guessed type bool __cdecl LoadWintrust();

//----- (00FF9F40) --------------------------------------------------------
bool LoadWintrust()
{
  HMODULE v0; // eax
  HMODULE v1; // edi
  HMODULE v3; // eax

  if ( !byte_10C4D7C )
  {
    byte_10C4D7C = 1;
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
// FF9F40: using guessed type bool __cdecl LoadWintrust();
// 10C4D7C: using guessed type char byte_10C4D7C;

//----- (00FFA040) --------------------------------------------------------
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
// 1094188: using guessed type void *CTreeList::`vftable';

//----- (00FFA1F0) --------------------------------------------------------
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
  sub_FFA2C0(&v1->field_40);
  result = v1->baseclass.m_hThemeHandle;
  v1->baseclass.vtptr = &CThemedWindow::`vftable';
  if ( result )
    result = gpfnCloseThemeData(result);
  return result;
}
// 1094130: using guessed type void *CThemedWindow::`vftable';
// 1094188: using guessed type void *CTreeList::`vftable';

//----- (00FFA2C0) --------------------------------------------------------
void __thiscall sub_FFA2C0(tagTreeViewChildItem *this)
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

//----- (00FFA320) --------------------------------------------------------
_bstr_t *__thiscall sub_FFA320(_bstr_t *this, LPCSTR lpString)
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
      v3->m_str = sub_1064270(v3->m_wstr);
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
      v5->m_wstr = _com_util::ConvertStringToBSTR(lpString);
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

//----- (00FFA3E0) --------------------------------------------------------
BOOL __thiscall sub_FFA3E0(BSTR **this, BSTR **a2)
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

//----- (00FFA460) --------------------------------------------------------
void *__thiscall CTreeListData::`scalar deleting destructor'(void *this, char a2)
{
  void *v2; // esi

  v2 = this;
  *this = &CTreeListData::`vftable';
  if ( a2 & 1 )
    j__free(this);
  return v2;
}
// 109414C: using guessed type void *CTreeListData::`vftable';

//----- (00FFA490) --------------------------------------------------------
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
// 10C4D9C: using guessed type __int16 gAtomTreeList;

//----- (00FFA510) --------------------------------------------------------
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

//----- (00FFA5B0) --------------------------------------------------------
LRESULT __stdcall CThemedWindow::HandleMessage(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
  return DefWindowProcW(hWnd, Msg, wParam, lParam);
}

//----- (00FFA5C0) --------------------------------------------------------
int __stdcall sub_FFA5C0(int pChild)
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

//----- (00FFA620) --------------------------------------------------------
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
      sub_FFA7D0(v1, v1->m_Child);
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

//----- (00FFA690) --------------------------------------------------------
bool __thiscall sub_FFA690(HWND *this, WPARAM wParam)
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

//----- (00FFA7D0) --------------------------------------------------------
void __thiscall sub_FFA7D0(CTreeList *this, tagTreeViewChildItem *pChild)
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
    sub_FFA7D0(pThis, i);
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
  sub_FFA2C0(pChild_1);
  j__free(pChild_1);
  if ( v11 )
  {
    if ( !(v11->m_dwStyle & 0x40) )
      CTreeList::RedrawZone(pThis, &pChilda[-1].m_dwStyle + 3, &pChilda[-1].m_dwStyle + 3);
  }
}

//----- (00FFA8E0) --------------------------------------------------------
signed int __thiscall TreeViewChildItem_GetSiblingCount(tagTreeViewChildItem *this)
{
  tagTreeViewChildItem *v1; // ecx
  signed int result; // eax

  v1 = this->m_Current;
  for ( result = -1; v1; ++result )
    v1 = v1->m_Current;
  return result;
}

//----- (00FFA900) --------------------------------------------------------
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

//----- (00FFAE40) --------------------------------------------------------
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

//----- (00FFAEC0) --------------------------------------------------------
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
      v20 = _mm_load_si128(&stru_1094280);
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
              sub_FFBC20(v66, v66[1].vtptr, hdcDst, ~(v124 >> 4) & 1, &v136);
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
// 1094280: using guessed type RECT stru_1094280;

//----- (00FFBC20) --------------------------------------------------------
HGDIOBJ __thiscall sub_FFBC20(CThemedWindow *this, int a2, HDC hDC, char a4, LPRECT lprc)
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

  v5 = dword_10C4DA8;
  hdc = hDC;
  pThis = this;
  v23 = lprc;
  if ( !(dword_10C4DA8 & 1) )
  {
    dword_10C4DA8 |= 1u;
    v7 = GetSysColor(COLOR_3DDKSHADOW);
    ghDarkShadowPen = CreatePen(0, 1, v7);
    v5 = dword_10C4DA8;
  }
  if ( !(v5 & 2) )
  {
    dword_10C4DA8 = v5 | 2;
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
// 10C4DA8: using guessed type int dword_10C4DA8;

//----- (00FFBDA0) --------------------------------------------------------
char __thiscall sub_FFBDA0(CTreeList *this, char a2)
{
  char result; // al

  result = a2;
  LOBYTE(this->m_ptDownLast.y) = a2;
  return result;
}

//----- (00FFBDB0) --------------------------------------------------------
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

//----- (00FFBE30) --------------------------------------------------------
UINT __thiscall sub_FFBE30(CTreeList *this, signed int a2)
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

//----- (00FFBF00) --------------------------------------------------------
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

//----- (00FFBFE0) --------------------------------------------------------
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

//----- (00FFC060) --------------------------------------------------------
CTreeList *__cdecl CTreeList::GetTreeList(HWND hWnd)
{
  return GetPropW(hWnd, gAtomTreeListProperty);
}
// 10C4DA0: using guessed type __int16 gAtomTreeListProperty;

//----- (00FFC080) --------------------------------------------------------
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
    _mm_storeu_si128(&rcText, _mm_load_si128(&stru_1094290));
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
// 1094290: using guessed type RECT stru_1094290;

//----- (00FFC210) --------------------------------------------------------
char __thiscall sub_FFC210(HWND *this, int a2, int a3, char a4, char a5, int a6, LPARAM lParam)
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

//----- (00FFC420) --------------------------------------------------------
int __thiscall sub_FFC420(_DWORD *this)
{
  return this[1];
}

//----- (00FFC430) --------------------------------------------------------
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

//----- (00FFC490) --------------------------------------------------------
HWND __thiscall CTreeList::GetTooltipOfRightHeader(CTreeList *this)
{
  return this->m_hWndTooltipOfRightHeader;
}

//----- (00FFC4A0) --------------------------------------------------------
int __stdcall sub_FFC4A0(int pChild, int a2)
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

//----- (00FFC530) --------------------------------------------------------
int __stdcall sub_FFC530(int a1, int a2)
{
  return 0;
}

//----- (00FFC540) --------------------------------------------------------
HIMAGELIST __thiscall CTreeList::GetImageList(CTreeList *this)
{
  return this->m_ImageList;
}

//----- (00FFC550) --------------------------------------------------------
char __thiscall sub_FFC550(_DWORD *this, int a2, struct tagRECT *a3)
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

//----- (00FFC630) --------------------------------------------------------
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

//----- (00FFC670) --------------------------------------------------------
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

//----- (00FFC8A0) --------------------------------------------------------
signed int __thiscall sub_FFC8A0(CTreeList *this, bool *a2)
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
// 10CA8F8: using guessed type char gbBitmapOnRight;

//----- (00FFC980) --------------------------------------------------------
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

//----- (00FFCA20) --------------------------------------------------------
const wchar_t *__stdcall sub_FFCA20(int a1, int a2, int a3, int a4)
{
  return L"not implemented";
}
// 1094164: using guessed type wchar_t aNotImplemented[16];

//----- (00FFCA30) --------------------------------------------------------
const wchar_t *CTreeList::GetName()
{
  return L"treeview";
}
// 1094190: using guessed type wchar_t aTreeview[9];

//----- (00FFCA40) --------------------------------------------------------
HWND __thiscall CTreeList::GetTooltipOfTreeList(CTreeList *this)
{
  return this->m_hWndTooltipOfTreeList;
}

//----- (00FFCA50) --------------------------------------------------------
int __thiscall sub_FFCA50(void *this)
{
  return *this;
}

//----- (00FFCA60) --------------------------------------------------------
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

//----- (00FFCAA0) --------------------------------------------------------
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

//----- (00FFCDB0) --------------------------------------------------------
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

//----- (00FFD000) --------------------------------------------------------
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

//----- (00FFD2A0) --------------------------------------------------------
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

//----- (00FFD310) --------------------------------------------------------
void __thiscall sub_FFD310(CTreeList *this, int a2, int a3)
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

//----- (00FFD3B0) --------------------------------------------------------
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
// 10C4D84: using guessed type int (__stdcall *gpfnIsThemeActive)();
// 10C4DA0: using guessed type __int16 gAtomTreeListProperty;

//----- (00FFD640) --------------------------------------------------------
int *__thiscall sub_FFD640(_DWORD *this, int a2, CListViewData *pListViewData, int (__cdecl *pfnCallback)(int, _DWORD, int, _DWORD), int a5)
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

//----- (00FFD750) --------------------------------------------------------
char __thiscall sub_FFD750(CTreeList *this, int a2, int a3)
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

//----- (00FFD7E0) --------------------------------------------------------
tagTreeViewChildItem *__thiscall sub_FFD7E0(CTreeList *this, int a2, int a3, int (__cdecl *a4)(int, _DWORD, int, _DWORD), int a5)
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
  v7 = sub_FFD640(v5, this, a3, a4, a5);
  v8 = v7;
  if ( v5[8] & 0x10 )
  {
    v9 = CTreeList::FindChild(v6, v7);
    CTreeList::SetVScrollbarPos(v9, 1);
  }
  return v8;
}

//----- (00FFD830) --------------------------------------------------------
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

//----- (00FFD980) --------------------------------------------------------
bool __thiscall sub_FFD980(_DWORD *this, int a2)
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

//----- (00FFDA70) --------------------------------------------------------
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

//----- (00FFDB30) --------------------------------------------------------
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

//----- (00FFDBA0) --------------------------------------------------------
int __cdecl pfnCallback(CListViewData *pListViewData, int a2, int a3)
{
  return (a3)(pListViewData->m_Value, *(a2 + 4));
}

//----- (00FFDBC0) --------------------------------------------------------
int __cdecl sub_FFDBC0(int a1, int a2, int (__stdcall *a3)(_DWORD, _DWORD, int), int a4)
{
  return a3(*(a1 + 4), *(a2 + 4), a4);
}

//----- (00FFDBE0) --------------------------------------------------------
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
      sub_FFA7D0(v5, v38);
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
        v58 = sub_FFE650(v58);
        ++v51;
        if ( !v58 )
          return HWND_MESSAGE|0x2;
      }
      return v51;
    case LVM_GETITEMRECT:
      if ( *lParam )
        return 0;
      sub_FFC550(this, wParam, lParam);
      return 1;
    case LVM_HITTEST:
      if ( !(CTreeList::Query(this, *lParam, *(lParam + 4), (lParam + 12), (lParam + 16), 0) & 0xE0) )
        return HWND_MESSAGE|0x2;
      return *(lParam + 12);
    case LVM_ENSUREVISIBLE:
      sub_FFBE30(this, wParam);
      return 1;
    case LVM_REDRAWITEMS:
      CTreeList::RedrawZone(this, wParam, lParam);
      return 1;
    case LVM_DELETECOLUMN:
      return sub_FFA690(this, wParam);
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
        v54 = sub_FFF500(&v5->m_Child, v5->m_nChildCount, sub_FFDBC0, lParam, wParam, 0);
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
      return sub_FFC210(this, wParam, *(lParam + 4), 1, 0, 0, lParam);
    case LVM_SETCOLUMNORDERARRAY:
      if ( wParam <= 1 )
        return ((wParam & 0x80000000) == 0);
      v22 = 1;
      if ( wParam - 1 >= 8 )
      {
        v23 = _mm_load_si128(&stru_1094280);
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
          v32 = _mm_load_si128(&stru_1094280);
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
      v37 = sub_FFD7E0(v5, wParam, v35, 1, v69);
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
        v50 = sub_FFE650(v50);
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
      return sub_FFD750(v5, &v71, wParam);
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
      return sub_FFD980(this, wParam);
    default:
      return DefWindowProcW(hWnd, Msg, wParam, lParam);
  }
}
// 1094268: using guessed type void *CListViewData::`vftable';
// 1094280: using guessed type RECT stru_1094280;

//----- (00FFE5D0) --------------------------------------------------------
int __stdcall sub_FFE5D0(int a1)
{
  return *(*(a1 + 4) + 4);
}
