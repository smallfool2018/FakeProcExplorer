

//----- (0100A4B0) --------------------------------------------------------
signed int *__thiscall sub_100A4B0(int this, signed int *a2, __int64 a3, __int64 a4, int a5, int a6, char a7)
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

//----- (0100A600) --------------------------------------------------------
void *__thiscall sub_100A600(void *this, int a2, int a3, int a4)
{
  return this;
}

//----- (0100A610) --------------------------------------------------------
__int64 sub_100A610()
{
  return 0i64;
}

//----- (0100A620) --------------------------------------------------------
void *__thiscall sub_100A620(_DWORD *this, void *a2)
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
      sub_1009760(&v10, v7, (v5 - v7) >> 1);
      goto LABEL_11;
    }
  }
  v12 = 7;
  v11 = 0;
  LOWORD(v10) = 0;
LABEL_11:
  sub_FD3530(a2, &v10);
  if ( v12 >= 8 )
    j__free(v10);
  return a2;
}

//----- (0100A6E0) --------------------------------------------------------
void *__thiscall sub_100A6E0(_DWORD *this, void *a2)
{
  sub_100A620(this + 6, a2);
  return a2;
}

//----- (0100A700) --------------------------------------------------------
signed int __thiscall sub_100A700(_DWORD **this)
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

//----- (0100A730) --------------------------------------------------------
signed int sub_100A730()
{
  return 0xFFFF;
}

//----- (0100A740) --------------------------------------------------------
signed __int16 __thiscall sub_100A740(int this)
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

//----- (0100A7B0) --------------------------------------------------------
unsigned int __thiscall sub_100A7B0(_DWORD **this, void *a2, int a3, int a4)
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
    v7 = sub_1009140(v5);
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

//----- (0100A8C0) --------------------------------------------------------
unsigned int __thiscall sub_100A8C0(_DWORD **this, void *a2, int a3, int a4)
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
    v7 = sub_1009400(v5);
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

//----- (0100A9D0) --------------------------------------------------------
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
// 109C4C4: using guessed type void *CObjSecurity::`vftable';

//----- (0100AA10) --------------------------------------------------------
int __cdecl CObjSecurity::~CObjSecurity(int a1)
{
  return (*(*a1 + 8))(a1);
}

//----- (0100AA20) --------------------------------------------------------
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
// 109C4C4: using guessed type void *CObjSecurity::`vftable';

//----- (0100AA90) --------------------------------------------------------
int __stdcall CObjSecurity::AddRef(int a1)
{
  int result; // eax

  result = *(a1 + 4) + 1;
  *(a1 + 4) = result;
  return result;
}

//----- (0100AAB0) --------------------------------------------------------
int __stdcall CObjSecurity::GetAccessRights(int a1, int a2, int a3, _DWORD *a4, _DWORD *a5, _DWORD *a6)
{
  int result; // eax

  switch ( *(a1 + 20) )
  {
    case 0:
      *a4 = &off_10BD008;
      *a5 = 9;
      *a6 = 0;
      result = 0;
      break;
    case 2:
      *a4 = &off_10BD098;
      *a5 = 5;
      *a6 = 0;
      result = 0;
      break;
    case 3:
      *a4 = &off_10BCCD8;
      *a5 = 19;
      *a6 = 0;
      result = 0;
      break;
    case 4:
      *a4 = &off_10BCF18;
      *a5 = 15;
      *a6 = 0;
      result = 0;
      break;
    case 5:
      *a4 = &off_10BCE08;
      *a5 = 17;
      *a6 = 0;
      result = 0;
      break;
    default:
      *a4 = &off_10BCC68;
      *a5 = 7;
      *a6 = 0;
      result = 0;
      break;
  }
  return result;
}
// 10BCC68: using guessed type GUID *off_10BCC68;
// 10BCCD8: using guessed type GUID *off_10BCCD8;
// 10BCE08: using guessed type GUID *off_10BCE08;
// 10BCF18: using guessed type GUID *off_10BCF18;
// 10BD008: using guessed type GUID *off_10BD008;
// 10BD098: using guessed type GUID *off_10BD098;

//----- (0100ABB0) --------------------------------------------------------
int __stdcall CObjSecurity::GetInheritTypes(int a1, _DWORD *a2, _DWORD *a3)
{
  *a2 = &off_10BD0E8;
  *a3 = 1;
  return 0;
}
// 10BD0E8: using guessed type GUID *off_10BD0E8;

//----- (0100ABD0) --------------------------------------------------------
int __stdcall CObjSecurity::GetObjectInformation(_DWORD *a1, _DWORD *a2)
{
  *a2 = a1[2];
  a2[1] = ghMainInstance;
  a2[2] = a1[3];
  a2[3] = a1[4];
  return 0;
}

//----- (0100AC00) --------------------------------------------------------
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
    result = sub_103F3E0(*(a1 + 24), dwSecurityInformation, v5);
  }
  if ( result > 0 )
    result = result | 0x80070000;
  return result;
}

//----- (0100ACB0) --------------------------------------------------------
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

//----- (0100ACF0) --------------------------------------------------------
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

//----- (0100AD60) --------------------------------------------------------
int __stdcall CObjSecurity::MapGeneric(int a1, int a2, int a3, PDWORD AccessMask)
{
  int result; // eax

  if ( *(a1 + 20) == 3 )
  {
    MapGenericMask(AccessMask, &stru_10BCC38);
    result = 0;
  }
  else if ( *(a1 + 20) == 4 )
  {
    MapGenericMask(AccessMask, &stru_10BCC58);
    result = 0;
  }
  else
  {
    if ( *(a1 + 20) == 5 )
      MapGenericMask(AccessMask, &stru_10BCC48);
    else
      MapGenericMask(AccessMask, &GenericMapping);
    result = 0;
  }
  return result;
}

//----- (0100ADD0) --------------------------------------------------------
int __stdcall CObjSecurity::PropertySheetPageCallback(int a1, int a2, int a3, int a4)
{
  return 0;
}

//----- (0100ADE0) --------------------------------------------------------
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
// 109C4B0: using guessed type GUID CLSID_IObjectSecurity;
// 10A7BBC: using guessed type GUID CLSID_IUnknown;

//----- (0100AE60) --------------------------------------------------------
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

//----- (0100AE80) --------------------------------------------------------
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
    result = sub_103F4D0(*(a1 + 24), dwSecurityInformation, lpSecurityDescriptor, 0, 0);
  }
  if ( result > 0 )
    result = result | 0x80070000;
  return result;
}

//----- (0100AEE0) --------------------------------------------------------
int __thiscall sub_100AEE0(_DWORD *this, int a2, char a3, int a4, int a5, void *a6)
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
    sub_1001430(a6 + 2);
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

//----- (0100B100) --------------------------------------------------------
int __thiscall sub_100B100(std__tree *this, int a2, int a3, int a4, void *a5)
{
  std_Tree_node_for_tagKeyName *v5; // ebx
  bool v6; // al
  std_Tree_node_for_tagKeyName *v7; // esi
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
  std__tree *v22; // [esp+10h] [ebp-18h]
  int v23; // [esp+14h] [ebp-14h]
  int *v24; // [esp+18h] [ebp-10h]
  int v25; // [esp+24h] [ebp-4h]

  v24 = &v21;
  v22 = this;
  v5 = this->_Mypair._Myval2._Myhead;
  v6 = 1;
  v25 = 0;
  LOBYTE(v23) = 1;
  v7 = v5->_Parent;
  if ( !v7->_IsNil )
  {
    while ( 1 )
    {
      v5 = v7;
      if ( !a3 )
      {
        v11 = *a4;
        v12 = v7->_Myval.first;
        if ( *a4 == v12 )
          goto LABEL_16;
        if ( v11 )
        {
          if ( v12 )
          {
            v13 = bstr_t::Data_t::Compare(v11, v7->_Myval.first);
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
      v8 = v7->_Myval.first;
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
        v7 = v7->_Left;
      else
        v7 = v7->_Right;
      if ( v7->_IsNil )
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
    if ( v5 == this->_Mypair._Myval2._Myhead->_Left )
    {
      v16 = sub_100AEE0(this, &a3, 1, v5, a4, a5);
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
  if ( sub_FD3C30((v15 + 16), a4) )
  {
    v16 = sub_100AEE0(v22, &a3, v23, v5, v19, a5);
    goto LABEL_36;
  }
  v20 = a5;
  sub_1001430(a5 + 2);
  j__free(v20);
  result = a2;
  *a2 = v15;
  *(a2 + 4) = 0;
  return result;
}
// 10681AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);

//----- (0100B2D0) --------------------------------------------------------
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

//----- (0100B3A0) --------------------------------------------------------
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

//----- (0100B3D0) --------------------------------------------------------
ATL::CAtlStringMgr *__thiscall ATL::CAtlStringMgr::Clone(ATL::CAtlStringMgr *this)
{
  return this;
}

//----- (0100B3E0) --------------------------------------------------------
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

//----- (0100B460) --------------------------------------------------------
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

//----- (0100B540) --------------------------------------------------------
void *__thiscall ATL::CAtlStringMgr::`scalar deleting destructor'(void *this, char a2)
{
  void *v2; // esi

  v2 = this;
  *this = &ATL::CAtlStringMgr::`vftable';
  byte_10C4DF4 = 0;
  if ( a2 & 1 )
    j__free(this);
  return v2;
}
// 109C510: using guessed type void *ATL::CAtlStringMgr::`vftable';
// 10C4DF4: using guessed type char byte_10C4DF4;

//----- (0100B570) --------------------------------------------------------
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
// 109C4F8: using guessed type void *ATL::CWin32Heap::`vftable';

//----- (0100B5B0) --------------------------------------------------------
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

//----- (0100B630) --------------------------------------------------------
LPVOID __thiscall ATL::CWin32Heap::Allocate(HANDLE *this, SIZE_T dwBytes)
{
  return HeapAlloc(this[1], 0, dwBytes);
}

//----- (0100B650) --------------------------------------------------------
int __cdecl sub_100B650(int a1)
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

//----- (0100B6F0) --------------------------------------------------------
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

//----- (0100B760) --------------------------------------------------------
void __cdecl __noreturn ATL::AtlThrowImpl(int a1)
{
  _CxxThrowException(&a1, &_TI1_AVCAtlException_ATL__);
}
// 10681AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);
// 10B4740: using guessed type int _TI1_AVCAtlException_ATL__;

//----- (0100B780) --------------------------------------------------------
void __cdecl sub_100B780(HWND hWnd, CString lpCommandLine)
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
    sub_FD7CC0(hWnd, lpCommandLine.pszData);
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
// 109C528: using guessed type wchar_t aExplorerSelect[18];
// 109C54C: using guessed type wchar_t aExplorerCouldN[25];

//----- (0100B950) --------------------------------------------------------
HANDLE StartBackendThread()
{
  InitializeCriticalSection(&gBstrListLock);
  return _beginthread(BackendThreadProc, 0, 0);
}

//----- (0100B970) --------------------------------------------------------
CStringData *__cdecl sub_100B970(CStringData *a1)
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

//----- (0100B9E0) --------------------------------------------------------
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

//----- (0100BA60) --------------------------------------------------------
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

//----- (0100BAC0) --------------------------------------------------------
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

//----- (0100BB40) --------------------------------------------------------
int __thiscall ATL::CAtlStringMgr::Free(ATL::CAtlStringMgr *this, struct CStringData *a2)
{
  return (*(**(this + 1) + 4))();
}

//----- (0100BB50) --------------------------------------------------------
LPVOID __thiscall ATL::CWin32Heap::Free(HANDLE *this, LPVOID lpMem)
{
  LPVOID result; // eax

  result = lpMem;
  if ( lpMem )
    result = HeapFree(this[1], 0, lpMem);
  return result;
}

//----- (0100BB70) --------------------------------------------------------
wchar_t *__cdecl sub_100BB70(wchar_t *a1, wchar_t *a2)
{
  const wchar_t *v2; // esi
  void *v3; // ebx
  int v4; // edi
  const wchar_t **v5; // eax
  const wchar_t *v6; // eax
  _DWORD *v7; // eax
  const wchar_t *v8; // eax
  int v9; // esi
  int *v10; // ebx
  tagPEStringStruct *v11; // esi
  int *v12; // eax
  wchar_t *v13; // esi
  int v14; // eax
  const wchar_t **v16; // eax
  int v17; // [esp+4h] [ebp-10h]
  int v18; // [esp+8h] [ebp-Ch]
  tagPEStringStruct *v19; // [esp+Ch] [ebp-8h]
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
    v10 = (v9 + 4);
    v11 = sub_100C770((v9 + 4), &a2);
    if ( v11 == *v10 || sub_FD3C30(&a2, &v11->strValue[4]) )
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

//----- (0100BCE0) --------------------------------------------------------
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
    atexit(sub_108A7F0);
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
    atexit(sub_108A820);
  }
  return &strMgr;
}
// 109C4F8: using guessed type void *ATL::CWin32Heap::`vftable';
// 109C510: using guessed type void *ATL::CAtlStringMgr::`vftable';
// 10C4E04: using guessed type int ATL::CAtlStringMgr::sbInited;

//----- (0100BD90) --------------------------------------------------------
char *__thiscall ATL::CAtlStringMgr::GetNilString(ATL::CAtlStringMgr *this)
{
  _InterlockedExchangeAdd(this + 5, 1u);
  return this + 8;
}

//----- (0100BDA0) --------------------------------------------------------
SIZE_T __thiscall ATL::CWin32Heap::GetSize(HANDLE *this, LPCVOID lpMem)
{
  return HeapSize(this[1], 0, lpMem);
}

//----- (0100BDC0) --------------------------------------------------------
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
  sub_100B650(v11);
  if ( nDestLength > *(pThis->pszData - 2) )
    ATL::AtlThrowImpl(E_INVALIDARG);
  *(pThis->pszData - 3) = nDestLength;
  result = 1;
  *&pThis->pszData[2 * nDestLength] = 0;
  return result;
}

//----- (0100BE90) --------------------------------------------------------
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

//----- (0100BF00) --------------------------------------------------------
volatile signed __int32 *__cdecl sub_100BF00(OLECHAR *lpszText1, OLECHAR *lpszText2, OLECHAR *lpszText3)
{
  std__list_node_for_BSTR *_Node; // esi
  Data_t_bstr_t *v4; // eax
  const wchar_t *v5; // eax
  Data_t_bstr_t *pStringItem; // ebx
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
  Data_t_bstr_t *v17; // ebx
  tagPEStringStruct *v18; // eax
  tagPEStringStruct *v19; // esi
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
  int a2; // [esp+1Ch] [ebp-28h]
  std__List theTmpList; // [esp+24h] [ebp-20h]
  void *v46; // [esp+2Ch] [ebp-18h]
  Data_t_bstr_t *pItem_2; // [esp+30h] [ebp-14h]
  Data_t_bstr_t *theTmpMap; // [esp+34h] [ebp-10h]
  int v49; // [esp+40h] [ebp-4h]

  EnterCriticalSection(&gBstrListLock);
  _Node = *gBstrList;
  if ( *gBstrList == gBstrList )
    goto LABEL_9;
  while ( 1 )
  {
    v4 = _Node->__MyVal.pStringItem->strValue[0];
    v5 = v4 ? v4->m_wstr : 0;
    if ( !_wcsicmp(v5, lpszText1) )
      break;
    _Node = _Node->_Next;
    if ( _Node == gBstrList )
      goto LABEL_9;
  }
  pStringItem = _Node->__MyVal.pStringItem;
  if ( !pStringItem )
  {
LABEL_9:
    pItem = operator new(0xCu);
    pStringItem = pItem;
    pItem_2 = pItem;
    v49 = 0;
    if ( pItem )
    {
      pItem->m_wstr = 0;
      LOBYTE(v49) = 1;
      pItem->m_str = 0;
      pItem->m_RefCount = 0;
      pItem->m_str = std::_Tree_comp_alloc<std::_Tmap_traits<unsigned long,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *>>,0>>::_Buyheadnode();
    }
    else
    {
      pStringItem = 0;
    }
    theTmpMap = pStringItem;
    v8 = operator new(0xCu);
    v9 = v8;
    pItem_2 = v8;
    v49 = 2;
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
    v49 = -1;
    if ( !v9 )
      _com_issue_error(E_OUTOFMEMORY);
    if ( pStringItem != &pItem_2 )
    {
      v11 = pStringItem->m_wstr;
      if ( pStringItem->m_wstr )
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
        pStringItem->m_wstr = 0;
      }
      pStringItem->m_wstr = v9;
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
            &theTmpMap);
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
  v49 = 3;
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
  v49 = -1;
  pItem_2 = v15;
  if ( !v15 )
    _com_issue_error(E_OUTOFMEMORY);
  v17 = (pStringItem + 4);
  theTmpMap = v17;
  v18 = sub_100C770(v17, &pItem_2);
  v19 = v18;
  if ( v18 != v17->m_wstr )
  {
    v20 = v18->strValue[4];
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
    if ( bstr_t::Data_t::Compare(v15, v19->strValue[4]) >= 0 )
    {
LABEL_52:
      pItem_2 = v19;
      goto LABEL_54;
    }
  }
  pItem_2 = v17->m_wstr;
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
  v22 = v21 == v17->m_wstr;
  v23 = lpszText3;
  if ( v22 )
  {
    v24 = operator new(0xCu);
    v25 = v24;
    pItem_2 = v24;
    v49 = 4;
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
    v49 = -1;
    pItem_2 = v25;
    if ( !v25 )
      _com_issue_error(E_OUTOFMEMORY);
    v49 = 5;
    v27 = operator new(0xCu);
    v28 = v27;
    v46 = v27;
    LOBYTE(v49) = 6;
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
    LOBYTE(v49) = 5;
    v46 = v28;
    if ( !v28 )
      _com_issue_error(E_OUTOFMEMORY);
    theTmpList._Mypair._Myval2._Myhead = v28;
    InterlockedIncrement(&v28->m_RefCount);
    theTmpList._Mypair._Myval2._Mysize = v25;
    InterlockedIncrement(&v25->m_RefCount);
    LOBYTE(v49) = 8;
    v30 = sub_10011F0(theTmpMap, &theTmpList);
    sub_100B100(theTmpMap, &a2, 0, &v30->_Keyvalue, v30);
    sub_1001430(&theTmpList);
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
    v49 = -1;
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
    ATL::AtlThrowImpl(E_FAIL);
  lParam = (v31->vtptr->GetNilData)(v31) + 16;
  v32 = ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>::GetDefaultManager();
  if ( !v32 )
    ATL::AtlThrowImpl(-2147467259);
  v42.pszData = ((v32->vtptr->GetNilData)(v32) + 16);
  v33 = ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>::GetDefaultManager();
  if ( !v33 )
    ATL::AtlThrowImpl(-2147467259);
  v43.pszData = ((v33->vtptr->GetNilData)(v33) + 16);
  v49 = 9;
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
  v49 = -1;
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

//----- (0100C530) --------------------------------------------------------
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

//----- (0100C570) --------------------------------------------------------
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

//----- (0100C5E0) --------------------------------------------------------
LPVOID __thiscall ATL::CWin32Heap::Reallocate(HANDLE *this, LPVOID lpMem, SIZE_T dwBytes)
{
  if ( !lpMem )
    return (**this)(dwBytes);
  if ( dwBytes )
    return HeapReAlloc(this[1], 0, lpMem, dwBytes);
  (*(*this + 1))(lpMem);
  return 0;
}

//----- (0100C620) --------------------------------------------------------
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

//----- (0100C6E0) --------------------------------------------------------
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

//----- (0100C750) --------------------------------------------------------
void __stdcall sub_100C750(void *a1)
{
  sub_1001430(a1 + 2);
  j__free(a1);
}

//----- (0100C770) --------------------------------------------------------
tagPEStringStruct *__thiscall sub_100C770(tagPEStringStruct *this, _bstr_t *a2)
{
  tagPEStringStruct *v2; // edi
  tagPEStringStruct *v3; // esi
  Data_t_bstr_t *v4; // ecx
  Data_t_bstr_t *v5; // eax
  OLECHAR *v6; // eax

  v2 = this->strValue[0];
  v3 = *(this->strValue[0] + 4);
  while ( !BYTE1(v3->strValue[3]) )
  {
    v4 = v3->strValue[4];
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
            v3 = v3->strValue[2];
            continue;
          }
        }
      }
    }
    v2 = v3;
    v3 = v3->strValue[0];
  }
  return v2;
}

//----- (0100C7E0) --------------------------------------------------------
int __cdecl sub_100C7E0(int a1, int a2, int a3, _DWORD *a4, unsigned __int8 (__cdecl *a5)(_DWORD, _DWORD))
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

//----- (0100C880) --------------------------------------------------------
void *__cdecl sub_100C880(void *a1, int a2, int a3)
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

//----- (0100C930) --------------------------------------------------------
int __cdecl sub_100C930(int a1, int a2, unsigned __int8 (__cdecl *a3)(_DWORD, _DWORD))
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
      result = sub_100CBC0(v3, v11, v9, &v12, a3);
      v6 = v14;
      v4 = v15;
      v7 = v13;
    }
    while ( v14 > 0 );
  }
  return result;
}

//----- (0100C9E0) --------------------------------------------------------
int __cdecl sub_100C9E0(int *a1, int *a2, int *a3, unsigned __int8 (__cdecl *a4)(int, int))
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

//----- (0100CBC0) --------------------------------------------------------
int __cdecl sub_100CBC0(int a1, int a2, int a3, _DWORD *a4, unsigned __int8 (__cdecl *a5)(_DWORD, _DWORD))
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

//----- (0100CC30) --------------------------------------------------------
void *__cdecl sub_100CC30(void *a1, int a2, int a3, int a4)
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
    sub_100CD70(&v10, v6, v5, v4);
    v8 = v8 / 2 / 2 + v8 / 2;
    if ( ((v10 - v6) & 0xFFFFFFFC) >= ((v5 - v11) & 0xFFFFFFFC) )
    {
      result = sub_100CC30(v11, v5, v8, a4);
      v5 = v10;
    }
    else
    {
      result = sub_100CC30(v6, v10, v8, a4);
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
      result = sub_100C880(v6, v5, v4);
  }
  else
  {
    if ( ((v5 - v6) & 0xFFFFFFFC) > 4 )
    {
      sub_100C930(v6, v5, v4);
      v4 = a4;
    }
    result = sub_100CD10(v6, v5, v4);
  }
  return result;
}

//----- (0100CD10) --------------------------------------------------------
signed int __cdecl sub_100CD10(_DWORD *a1, int a2, unsigned __int8 (__cdecl *a3)(_DWORD, _DWORD))
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
      sub_100C7E0(a1, 0, v3 >> 2, &a2, v5);
      result = v3 & 0xFFFFFFFC;
    }
    while ( (v3 & 0xFFFFFFFC) > 4 );
  }
  return result;
}

//----- (0100CD70) --------------------------------------------------------
int **__cdecl sub_100CD70(int **a1, int *a2, int *a3, unsigned __int8 (__cdecl *a4)(int, int))
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
  sub_100C9E0(a2, &a2[v4 / 2], a3 - 1, a4);
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

//----- (0100CF50) --------------------------------------------------------
_DWORD *__cdecl sub_100CF50(_DWORD *a1, _WORD *a2, _WORD *a3, _WORD *a4)
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

//----- (0100CF80) --------------------------------------------------------
void **__thiscall sub_100CF80(void **this, void *Src, int a3, int a4)
{
  void **v4; // edi
  int v5; // eax
  int v6; // eax

  v4 = this;
  if ( !a4 )
    ATL::AtlThrowImpl(0x80004005);
  if ( !Src && a3 )
    goto LABEL_13;
  v5 = (**a4)(a3, 2);
  if ( !v5 )
    ATL::CSimpleStringT<wchar_t,0>::ThrowMemoryException();
  v6 = v5 + 16;
  *v4 = v6;
  if ( a3 < 0 || a3 > *(v6 - 8) )
LABEL_13:
    ATL::AtlThrowImpl(0x80070057);
  *(v6 - 12) = a3;
  *(*v4 + a3) = 0;
  memcpy_s(*v4, 2 * a3, Src, 2 * a3);
  return v4;
}

//----- (0100D000) --------------------------------------------------------
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
// 109C910: using guessed type void *Appdomain::`vftable';

//----- (0100D080) --------------------------------------------------------
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
  sub_100FFF0(v5, a4);
  return v5;
}
// 109C930: using guessed type void *Assembly::`vftable';

//----- (0100D1D0) --------------------------------------------------------
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
// 109C888: using guessed type void *CResizer::`vftable';

//----- (0100D260) --------------------------------------------------------
_DWORD *__thiscall sub_100D260(_DWORD *this)
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

//----- (0100D2B0) --------------------------------------------------------
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
// 109C8F0: using guessed type void *Runtime::`vftable';

//----- (0100D3B0) --------------------------------------------------------
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
// 109414C: using guessed type void *CTreeListData::`vftable';
// 109C910: using guessed type void *Appdomain::`vftable';

//----- (0100D4B0) --------------------------------------------------------
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
// 109414C: using guessed type void *CTreeListData::`vftable';

//----- (0100D530) --------------------------------------------------------
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
// 1094130: using guessed type void *CThemedWindow::`vftable';
// 109C888: using guessed type void *CResizer::`vftable';

//----- (0100D590) --------------------------------------------------------
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
// 109414C: using guessed type void *CTreeListData::`vftable';
// 109C8D0: using guessed type void *Process::`vftable';

//----- (0100D670) --------------------------------------------------------
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
// 109414C: using guessed type void *CTreeListData::`vftable';
// 109C8F0: using guessed type void *Runtime::`vftable';

//----- (0100D840) --------------------------------------------------------
CString *__thiscall sub_100D840(CString *this, void **a2)
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
  v5 = sub_100B970(v4);
  v7 = v5;
  if ( _InterlockedDecrement(v3 + 3) <= 0 )
  {
    (*(**v3 + 4))(v3);
    v5 = v7;
  }
  v2->pszData = &v5[1];
  return v2;
}

//----- (0100D8B0) --------------------------------------------------------
void *__thiscall AppDomain::`vector deleting destructor'(void *this, char a2)
{
  void *v2; // esi

  v2 = this;
  AppDomain::~AppDomain(this);
  if ( a2 & 1 )
    j__free(v2);
  return v2;
}

//----- (0100D8E0) --------------------------------------------------------
void *__thiscall Assembly::`scalar deleting destructor'(void *this, char a2)
{
  void *v2; // esi

  v2 = this;
  Assembly::~Assembly(this);
  if ( a2 & 1 )
    j__free(v2);
  return v2;
}

//----- (0100D910) --------------------------------------------------------
void *__thiscall Process::`scalar deleting destructor'(void *this, char a2)
{
  void *v2; // esi

  v2 = this;
  Process::~Process(this);
  if ( a2 & 1 )
    j__free(v2);
  return v2;
}

//----- (0100D940) --------------------------------------------------------
void *__thiscall Runtime::`scalar deleting destructor'(void *this, char a2)
{
  void *v2; // esi

  v2 = this;
  Runtime::~Runtime(this);
  if ( a2 & 1 )
    j__free(v2);
  return v2;
}

//----- (0100D970) --------------------------------------------------------
int __thiscall sub_100D970(_DWORD *this, CTreeList *thisIn)
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
      v6 = sub_FFD7E0(v4, 0, *v3, 0, 0);
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
          v16 = sub_FFD7E0(thisIn, v6, *v14, 0, 0);
          v17 = v16;
          v29 = v16;
          CTreeList::OnMsg2001(thisIn, v16, 1);
          sub_100CC30(*(v15 + 28), *(v15 + 32), (*(v15 + 32) - *(v15 + 28)) >> 2, sub_100E7A0);
          v18 = *(v15 + 32);
          v19 = *(v15 + 28);
          v20 = sub_FFCA50(v17);
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
              sub_FFD7E0(v21, v29, *v19, 0, 0);
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
    sub_100CC30(*(v5 + 44), *(v5 + 48), (*(v5 + 48) - *(v5 + 44)) >> 2, sub_100E7A0);
    v7 = *(v5 + 48);
    v8 = *(v5 + 44);
    v9 = sub_FFCA50(v33);
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
        sub_FFD7E0(v10, v33, *v8, 0, 0);
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

//----- (0100DB10) --------------------------------------------------------
int __cdecl sub_100DB10(wchar_t *Dst, rsize_t SizeInWords, int a3)
{
  return sub_100E970(Dst, SizeInWords, a3, &unk_10BD0F8, 3);
}

//----- (0100DB40) --------------------------------------------------------
CHAR *__thiscall sub_100DB40(CString *this, wchar_t *Src)
{
  CHAR *result; // eax

  if ( Src )
    result = sub_100DB80(this, Src, wcslen(Src));
  else
    result = sub_100DB80(this, 0, 0);
  return result;
}

//----- (0100DB80) --------------------------------------------------------
CHAR *__thiscall sub_100DB80(CString *this, wchar_t *Src, size_t MaxCount)
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

//----- (0100DC50) --------------------------------------------------------
int __cdecl sub_100DC50(wchar_t *Dst, rsize_t SizeInWords, int a3)
{
  return sub_100E970(Dst, SizeInWords, a3, &unk_10BD110, 4);
}

//----- (0100DC80) --------------------------------------------------------
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
// 10C4D84: using guessed type int (__stdcall *gpfnIsThemeActive)();

//----- (0100DD40) --------------------------------------------------------
ULONG __userpurge sub_100DD40@<eax>(int a1@<ecx>, int a2@<edi>, int a3@<esi>, int a4, int a5)
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
    sub_1010200(L"A669021C-C450-4609-A035-5AF59AF4DF18", &v11);
  else
    sub_1010200(L"E13C0D23-CCBC-4E12-931B-D9CC2EEE27E4", &v11);
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
  sub_100F840(v9, v6 + 60);
  TraceHandle = 0i64;
  v8 = ControlTraceW(0i64, v6 + 60, v6, 1u);
  free(v6);
  return v8;
}
// 100DD40: could not find valid save-restore pair for edi
// 100DD40: could not find valid save-restore pair for esi
// 109C960: using guessed type wchar_t aE13c0d23Ccbc4e[37];

//----- (0100DE80) --------------------------------------------------------
int __userpurge sub_100DE80@<eax>(int a1@<edi>, int *a2)
{
  a2[2] = sub_100DD40(*a2, a1, a2, **a2, a2[1]);
  return 0;
}

//----- (0100DEA0) --------------------------------------------------------
signed int __thiscall sub_100DEA0(void *this, int a2, DWORD ThreadId)
{
  void *v3; // esi
  signed int result; // eax
  int v5; // [esp+4h] [ebp-Ch]
  DWORD v6; // [esp+8h] [ebp-8h]
  int v7; // [esp+Ch] [ebp-4h]

  v6 = ThreadId;
  v5 = this;
  v3 = _beginthreadex(0, 0, sub_100DE80, &v5, 0, &ThreadId);
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

//----- (0100DF10) --------------------------------------------------------
int __thiscall sub_100DF10(DWORD *this)
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
  v7 = _mm_load_si128(&stru_109CB40);
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
  sub_FFBDA0(pTreeList, 1);
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
  sub_FFD310(pTreeList, &a2, 3);
  if ( !ProcessIsNetCclr(*v1, &pTreeList) )
  {
    v18 = pTreeList;
    if ( pTreeList & 1 )
    {
      v19 = sub_100EBA0(v1[6], *v1, 0xFFFF);
      ATL::CSimpleStringT<wchar_t,0>::SetString(v19 + 6, L"v1.0.3705", 9);
      v18 = pTreeList;
    }
    if ( v18 & 2 )
    {
      v20 = sub_100EBA0(v1[6], *v1, 0xFFFE);
      ATL::CSimpleStringT<wchar_t,0>::SetString(v20 + 6, L"v1.1.4322", 9);
      v18 = pTreeList;
    }
    if ( v18 & 4 )
    {
      v21 = sub_100EBA0(v1[6], *v1, 0xFFFD);
      ATL::CSimpleStringT<wchar_t,0>::SetString(v21 + 6, L"v2.0.50727", 10);
      v3 = sub_100DEA0(v1, *v1, 0);
      if ( v3 )
        return v3;
      v18 = pTreeList;
    }
    if ( !(v18 & 8) || (v3 = sub_100DEA0(v1, *v1, 1u)) == 0 )
      sub_100D970(v1, pTreeList_1);
  }
  return v3;
}
// 109C8D0: using guessed type void *Process::`vftable';
// 109CA34: using guessed type wchar_t aStructure[10];
// 109CA48: using guessed type wchar_t aV103705[10];
// 109CA5C: using guessed type wchar_t aV114322[10];
// 109CA70: using guessed type wchar_t aV2050727[11];
// 109CB40: using guessed type RECT stru_109CB40;

//----- (0100E1A0) --------------------------------------------------------
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
          v30 = sub_100D260(v29);
        else
          v30 = 0;
        v30[2] = v25;
        *v30 = *(*(v27 + 4) + 68);
        v31 = LoadCursorW(0, 0x7F02);
        v32 = SetCursor(v31);
        sub_100DF10(v30);
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
        sub_1010130(v4);
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
  v21 = sub_FFC420(*(a4 + 16));
  v22 = (*(*v21 + 24))(v21);
  v23 = hDlg;
  **(a4 + 24) = v22;
  SetWindowLongW(v23, 0, 1);
  return 1;
}

//----- (0100E780) --------------------------------------------------------
BOOL __cdecl sub_100E780(int a1, int a2)
{
  return *(a1 + 16) < *(a2 + 16);
}

//----- (0100E7A0) --------------------------------------------------------
bool __cdecl sub_100E7A0(int a1, int a2)
{
  return _wcsnicmp(*(a1 + 4), *(a2 + 4), 0x400u) < 0;
}

//----- (0100E7D0) --------------------------------------------------------
LRESULT __thiscall CResizer::HandleMessage(WNDPROC *this, HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
  return CallWindowProcW(this[2], hWnd, Msg, wParam, lParam);
}

//----- (0100E7F0) --------------------------------------------------------
int __stdcall sub_100E7F0(int a1)
{
  return sub_100F0A0(*(a1 + 96), a1);
}

//----- (0100E810) --------------------------------------------------------
int __thiscall sub_100E810(_DWORD *this, int a2, int a3)
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
        if ( sub_100F710(*v6, a2, a3) )
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

//----- (0100E870) --------------------------------------------------------
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
      pNewItem_1[-1].m_rect1 = stru_109CB50;
      pNewItem_1[-1].m_rect2 = stru_109CB50;
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
// 10681AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);
// 109CB50: using guessed type RECT stru_109CB50;
// 10B4A54: using guessed type int _TI1J;

//----- (0100E970) --------------------------------------------------------
int __cdecl sub_100E970(wchar_t *Dst, rsize_t SizeInWords, int a3, int a4, int a5)
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

//----- (0100E9F0) --------------------------------------------------------
__int16 __thiscall sub_100E9F0(_WORD *this)
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

//----- (0100EA10) --------------------------------------------------------
__int16 __thiscall sub_100EA10(_WORD *this)
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

//----- (0100EA30) --------------------------------------------------------
__int16 __thiscall sub_100EA30(_WORD *this)
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

//----- (0100EA70) --------------------------------------------------------
HWND __thiscall CTreeList::GetTooltipOfLeftHeader(CTreeList *this)
{
  return this->m_hWndTooltipOfLeftHeader;
}

//----- (0100EA80) --------------------------------------------------------
const WCHAR **sub_100EA80()
{
  return &gszNullString;
}

//----- (0100EA90) --------------------------------------------------------
int __thiscall sub_100EA90(_WORD *this)
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

//----- (0100EAB0) --------------------------------------------------------
_WORD *__thiscall sub_100EAB0(_WORD *this)
{
  _WORD *i; // eax

  for ( i = this + 12; *i; ++i )
    ;
  return i + 1;
}

//----- (0100EAD0) --------------------------------------------------------
AppDomain *__thiscall sub_100EAD0(_DWORD *this, int a2, AppDomain *a3)
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
      if ( sub_100F710(*v4, a2, v5) )
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

//----- (0100EBA0) --------------------------------------------------------
Runtime *__thiscall sub_100EBA0(_DWORD *this, unsigned int a2, Runtime *a3)
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
      if ( sub_100F730(*v5, &v9) )
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

//----- (0100EC70) --------------------------------------------------------
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

//----- (0100EE50) --------------------------------------------------------
wchar_t *__thiscall sub_100EE50(_DWORD *this, int a2, int a3, wchar_t *Dst, int a5)
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

//----- (0100EEA0) --------------------------------------------------------
wchar_t *__thiscall sub_100EEA0(int this, int a2, int a3, wchar_t *Dst, int a5)
{
  wchar_t *v5; // edi
  int v6; // eax
  CStringData *v7; // eax
  wchar_t *v8; // esi
  void **v9; // eax
  int v10; // edx
  volatile signed __int32 *v11; // esi

  v5 = Dst;
  *Dst = 0;
  switch ( a3 )
  {
    case 0:
      return *(this + 4);
    case 1:
      wcscat_s(v5, *a5, *(this + 20));
      break;
    case 2:
      v6 = *(this + 24);
      if ( *(v6 - 12) )
      {
        v7 = sub_100B970((v6 - 16));
        v8 = &v7[1];
        Dst = &v7[1];
        if ( *a5 < v7->nDataLength + 1 )
        {
          v9 = sub_100F790(&Dst, &a3, 0, *a5 - 4);
          sub_100D840(&Dst, v9);
          v10 = a3 - 16;
          if ( _InterlockedDecrement((a3 - 16 + 12)) <= 0 )
            (*(**v10 + 4))(v10);
          sub_100DB40(&Dst, L"...");
          v8 = Dst;
        }
        wcscat_s(v5, *a5, v8);
        v11 = (v8 - 8);
        if ( _InterlockedDecrement(v11 + 3) <= 0 )
        {
          (*(**v11 + 4))(v11);
          return v5;
        }
      }
      break;
  }
  return v5;
}

//----- (0100EFF0) --------------------------------------------------------
wchar_t *__thiscall sub_100EFF0(int this, int a2, int a3, wchar_t *Dst, int a5)
{
  int v6; // eax
  wchar_t *v7; // esi
  int v8; // [esp-4h] [ebp-8h]

  if ( a3 )
  {
    if ( a3 != 1 || *(this + 20) == -3 )
    {
      *Dst = 0;
      return Dst;
    }
    v6 = *(this + 8);
    v8 = *(this + 12);
    v7 = Dst;
    if ( *(v6 - 12) )
    {
      swprintf_s(Dst, *a5, L"%s, %s", v6, v8);
      return Dst;
    }
    swprintf_s(Dst, *a5, L"%s", v8);
  }
  else
  {
    v7 = Dst;
    swprintf_s(Dst, *a5, L"CLR %s", *(this + 24));
  }
  return v7;
}

//----- (0100F070) --------------------------------------------------------
wchar_t *__stdcall sub_100F070(int a1, int a2, wchar_t *Dst, int a4)
{
  swprintf_s(Dst, *a4, &gszNullString);
  return Dst;
}

//----- (0100F090) --------------------------------------------------------
const wchar_t *CResizer::GetName()
{
  return L"status";
}
// 109C890: using guessed type wchar_t aStatus[7];

//----- (0100F0A0) --------------------------------------------------------
int __thiscall sub_100F0A0(_DWORD *this, int a2)
{
  _DWORD *v2; // ebx
  _DWORD *v3; // edx
  Runtime *v4; // edi
  int v5; // esi
  int v6; // eax
  unsigned __int16 *v7; // esi
  Runtime *v8; // eax
  int v9; // edi
  _WORD *v10; // ebx
  wchar_t *v11; // eax
  int v12; // eax
  void **v13; // eax
  CString *v14; // ecx
  int v15; // eax
  void **v16; // eax
  CHAR *v17; // ecx
  CString *v18; // edi
  bool v19; // zf
  void *v20; // eax
  int v21; // ebx
  int v22; // edi
  int v23; // esi
  CString *v24; // esi
  UINT v25; // ebx
  int v26; // ebx
  int v27; // edi
  AppDomain *v28; // esi
  unsigned __int16 v29; // ax
  Runtime *v30; // eax
  CString *v31; // esi
  CHAR *v32; // ST18_4
  int v33; // ebx
  int v34; // edi
  AppDomain *v35; // esi
  unsigned __int16 v36; // ax
  Runtime *v37; // eax
  AppDomain *v38; // edi
  CString *v39; // esi
  CString *v40; // eax
  CHAR *v41; // ST14_4
  char v42; // bl
  CString *v43; // esi
  int v44; // esi
  unsigned __int16 v45; // ax
  Runtime *v46; // eax
  CString *v47; // edi
  _WORD *v48; // eax
  CHAR *v49; // ST18_4
  Runtime *v50; // eax
  Runtime *v51; // eax
  void *v52; // esi
  CString v54; // [esp+10h] [ebp-1834h]
  CString v55; // [esp+14h] [ebp-1830h]
  void *v56; // [esp+18h] [ebp-182Ch]
  CString v57; // [esp+1Ch] [ebp-1828h]
  void *v58; // [esp+20h] [ebp-1824h]
  Runtime *v59; // [esp+24h] [ebp-1820h]
  tagAccountInfo pInfo; // [esp+28h] [ebp-181Ch]
  wchar_t Dst; // [esp+834h] [ebp-1010h]
  wchar_t Src; // [esp+1034h] [ebp-810h]
  int v63; // [esp+1840h] [ebp-4h]

  v2 = this;
  v58 = this;
  pInfo.nMenuID = 0;
  v3 = this[6];
  *pInfo.szUserName = v3;
  v4 = *(a2 + 12);
  v5 = *(a2 + 40);
  v6 = *(a2 + 45);
  v59 = v4;
  if ( v4 == v3[1] )
  {
    if ( this[3] )
    {
      switch ( v5 )
      {
        case 145:
          v50 = **(a2 + 92);
          pInfo.bIsSystemUser = **(a2 + 92);
          v51 = sub_100EBA0(v3, v4, v50);
          sub_10101B0(v51);
          v52 = v2[8];
          sub_100CF50(&v58, v2[7], v2[8], &pInfo);
          if ( v58 != v52 )
            sub_1010840(v2 + 7, &pInfo, v58);
          v19 = v2[7] == v2[8];
          goto LABEL_36;
        case 153:
          v44 = *(a2 + 92);
          v45 = sub_100EA30(*(a2 + 92));
          v46 = sub_100EBA0(*pInfo.szUserName, v4, v45);
          v47 = sub_100E810(v46, *(v44 + 8), *(v44 + 12));
          if ( !v47 )
            return 0;
          if ( *(v44 + 16) & 2 )
            v48 = sub_100EAB0(v44);
          else
            v48 = (v44 + 24);
          v49 = ATL::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>::Format(&v57, v48)->pszData;
          v63 = 8;
          sub_10100E0(v47, v49);
          v14 = &v57;
          goto LABEL_32;
        case 155:
          v33 = *(a2 + 92);
          v34 = *(v33 + 8);
          v35 = *(v33 + 12);
          v58 = *v33;
          pInfo.bIsSystemUser = *(v33 + 4);
          v36 = sub_100EA10(v33);
          v37 = sub_100EBA0(*pInfo.szUserName, v59, v36);
          v38 = sub_100EAD0(v37, v34, v35);
          sub_100DC50(&Src, 0x400u, *(v33 + 24));
          v39 = operator new(0x20u);
          v56 = v39;
          v63 = 5;
          if ( v39 )
          {
            v40 = ATL::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>::Format(&v55, v33 + 28);
            LOBYTE(v63) = 6;
            v41 = v40->pszData;
            v42 = 1;
            pInfo.nMenuID = 1;
            v43 = Assembly::Assembly(v39, v58, pInfo.bIsSystemUser, v41, &Src);
          }
          else
          {
            v42 = pInfo.nMenuID;
            v43 = 0;
          }
          v63 = -1;
          if ( v42 & 1 )
            ATL::CSimpleStringT<wchar_t,0>::~CSimpleStringT<wchar_t,0>(&v55);
          pInfo.bIsSystemUser = v43;
          std::vector<tagAccountInfo *,std::allocator<tagAccountInfo *>>::push_back((v38 + 28), &pInfo);
          break;
        case 157:
          v26 = *(a2 + 92);
          v27 = *v26;
          v28 = *(v26 + 4);
          v29 = sub_100E9F0(v26);
          v30 = sub_100EBA0(*pInfo.szUserName, v59, v29);
          v31 = sub_100EAD0(v30, v27, v28);
          v31[4].pszData = sub_100EA90(v26);
          v32 = ATL::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>::Format(&v54, v26 + 12)->pszData;
          v63 = 4;
          sub_10100E0(v31, v32);
          v63 = -1;
          ATL::CSimpleStringT<wchar_t,0>::~CSimpleStringT<wchar_t,0>(&v54);
          sub_100DB10(&Src, 0x400u, *(v26 + 8));
          sub_100FEB0(v31, &Src);
          break;
        case 187:
          pInfo.nMenuID = *(a2 + 92);
          v20 = *pInfo.nMenuID;
          v21 = *(pInfo.nMenuID + 14);
          v22 = *(pInfo.nMenuID + 16);
          v23 = *(pInfo.nMenuID + 18);
          pInfo.bIsSystemUser = *(pInfo.nMenuID + 12);
          v56 = v20;
          v59 = sub_100EBA0(*pInfo.szUserName, v59, v20);
          sub_100FF00(v59, (pInfo.nMenuID + 25));
          sub_1010880(v58 + 7, &v56);
          swprintf_s(&Dst, 0x400u, L"v%u.%u.%u.%u", pInfo.bIsSystemUser, v21, v22, v23);
          v24 = v59;
          sub_10100E0(v59, &Dst);
          v25 = pInfo.nMenuID;
          sub_100E970(&pInfo.szUserName[2], 0x400u, *(pInfo.nMenuID + 20), &unk_10BD178, 15);
          sub_100FF50(v24, &pInfo.szUserName[2]);
          sub_10101D0(&Src, 0x400u, *(v25 + 24));
          sub_100FFA0(v24, &Src);
          break;
        default:
          return 0;
      }
    }
    else if ( !v5 )
    {
      if ( v6 == 35 )
      {
        v7 = *(a2 + 92);
        v8 = sub_100EBA0(v3, v4, 0xFFFD);
        v9 = *v7;
        v10 = v7 + 12;
        v59 = v8;
        ATL::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>::Format(pInfo.szUserName, (v7 + 12));
        v63 = 0;
        v11 = wcsrchr(*pInfo.szUserName, 0x5Cu);
        if ( v11 )
        {
          v12 = (v11 - *pInfo.szUserName) >> 1;
          if ( v12 >= 0 )
          {
            v13 = sub_100F760(pInfo.szUserName, &pInfo.nMenuID, v12 + 1);
            LOBYTE(v63) = 1;
            sub_100D840(pInfo.szUserName, v13);
            LOBYTE(v63) = 0;
            ATL::CSimpleStringT<wchar_t,0>::~CSimpleStringT<wchar_t,0>(&pInfo.nMenuID);
          }
        }
        v14 = pInfo.szUserName;
        if ( *(*pInfo.szUserName - 12) )
        {
          v15 = sub_100FE80(pInfo.szUserName, 0x2Eu);
          if ( v15 >= 0 )
          {
            v16 = sub_100F790(pInfo.szUserName, &pInfo.nMenuID, 0, v15);
            LOBYTE(v63) = 2;
            sub_100D840(pInfo.szUserName, v16);
            LOBYTE(v63) = 0;
            ATL::CSimpleStringT<wchar_t,0>::~CSimpleStringT<wchar_t,0>(&pInfo.nMenuID);
          }
          sub_100E970(&Dst, 0x400u, v7[8], &dword_10BD130, 4);
          v17 = operator new(0x20u);
          v57.pszData = v17;
          LOBYTE(v63) = 3;
          if ( v17 )
            v18 = Assembly::Assembly(v17, v9, v9 >> 31, &gszNullString, &Dst);
          else
            v18 = 0;
          LOBYTE(v63) = 0;
          sub_100FF00(v18, *pInfo.szUserName);
          if ( *(v7 + 4) & 2 )
            v10 = sub_100EAB0(v7);
          sub_10100E0(v18, v10);
          pInfo.nMenuID = v18;
          std::vector<tagAccountInfo *,std::allocator<tagAccountInfo *>>::push_back((v59 + 44), (&pInfo + 4));
          ATL::CSimpleStringT<wchar_t,0>::~CSimpleStringT<wchar_t,0>(pInfo.szUserName);
        }
        else
        {
LABEL_32:
          ATL::CSimpleStringT<wchar_t,0>::~CSimpleStringT<wchar_t,0>(v14);
        }
      }
      else
      {
        v19 = v6 == 14;
LABEL_36:
        if ( v19 )
          CloseTrace(*(v2 + 2));
      }
    }
  }
  return 0;
}
// 10BD130: using guessed type int dword_10BD130;

//----- (0100F690) --------------------------------------------------------
int __cdecl sub_100F690(const unsigned __int16 *a1)
{
  signed int v1; // edi
  int v2; // esi
  signed int i; // edx
  unsigned int chText; // eax
  int v5; // eax

  v1 = 1;
  v2 = 0;
  for ( i = wcslen(a1) - 1; i >= 0; --i )
  {
    chText = a1[i];
    if ( (chText == 'x' || chText == 'X') && a1[i - 1] == '0' )
      return v2;
    if ( chText < '0' || chText > '9' )
    {
      if ( chText < 'a' || chText > 'f' )
      {
        if ( chText < 'A' || chText > 'F' )
          continue;
        v5 = chText - '7';
      }
      else
      {
        v5 = chText - 'W';
      }
    }
    else
    {
      v5 = chText - '0';
    }
    v2 |= v5 * v1;
    v1 *= 16;
  }
  return v2;
}

//----- (0100F710) --------------------------------------------------------
bool __cdecl sub_100F710(int a1, int a2, int a3)
{
  return *(a1 + 8) == a2 && *(a1 + 12) == a3;
}

//----- (0100F730) --------------------------------------------------------
bool __cdecl sub_100F730(int a1, int a2)
{
  return *(a1 + 28) == *a2 && *(a1 + 20) == *(a2 + 4);
}

//----- (0100F760) --------------------------------------------------------
void **__thiscall sub_100F760(_DWORD *this, void **a2, int a3)
{
  sub_100F790(this, a2, a3, *(*this - 12) - a3);
  return a2;
}

//----- (0100F790) --------------------------------------------------------
void **__thiscall sub_100F790(CString *this, void **a2, int a3, int a4)
{
  int v4; // esi
  CString *v5; // ebx
  int v6; // edi
  CHAR *v7; // edx
  int v8; // ecx
  CStringData *v9; // ecx
  void **result; // eax
  IAtlStringMgr *v11; // ecx
  int v12; // eax
  IAtlStringMgr *v13; // eax

  v4 = a4;
  v5 = this;
  v6 = a3;
  if ( a3 < 0 )
    v6 = 0;
  if ( a4 < 0 )
    v4 = 0;
  if ( 0x7FFFFFFF - v6 < v4 )
    ATL::AtlThrowImpl(-2147024362);
  v7 = this->pszData;
  v8 = *(this->pszData - 3);
  if ( v6 + v4 > v8 )
    v4 = v8 - v6;
  if ( v6 > v8 )
    v4 = 0;
  if ( v6 || v4 != v8 )
  {
    v11 = *(v7 - 4);
    if ( !v11 || (v12 = (v11->vtptr->Clone)()) == 0 )
    {
      v13 = ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>::GetDefaultManager();
      v12 = (v13->vtptr->Clone)(v13);
    }
    sub_100CF80(a2, &v5->pszData[2 * v6], v4, v12);
    result = a2;
  }
  else
  {
    v9 = sub_100B970(v7 - 1) + 1;
    result = a2;
    *a2 = v9;
  }
  return result;
}

//----- (0100F840) --------------------------------------------------------
signed int __thiscall sub_100F840(char *this, WCHAR *a2)
{
  char *v2; // edi
  int v3; // edi
  TRACEHANDLE v4; // rax
  signed int result; // eax
  struct _EVENT_TRACE_LOGFILEW Logfile; // [esp+8h] [ebp-1A4h]

  v2 = this;
  memset(&Logfile.LoggerName, 0, 0x19Cu);
  Logfile.Context = v2;
  Logfile.LogFileName = 0;
  Logfile.LoggerName = a2;
  v3 = (v2 + 16);
  Logfile.u.LogFileMode = 268435712;
  Logfile.BufferCallback = LogBufferCallback;
  Logfile.u2.EventCallback = sub_100E7F0;
  v4 = OpenTraceW(&Logfile);
  *v3 = v4;
  if ( v4 == 0xFFFFFFFF )
  {
    result = GetLastError();
    if ( result > 0 )
      result = result | 0x80070000;
    *v3 = 0;
    *(v3 + 4) = 0;
  }
  else
  {
    result = ProcessTrace(v3, 1u, 0, 0);
    if ( result )
    {
      result = GetLastError();
      if ( result > 0 )
        result = result | 0x80070000;
    }
  }
  return result;
}

//----- (0100F920) --------------------------------------------------------
BOOL __stdcall CResizer::EnumChildCallback(HWND hWnd, CResizer *a2)
{
  double v2; // xmm0_8
  int v3; // ecx
  int v4; // esi
  int v5; // eax
  __int32 v6; // eax
  int v7; // edx
  int v8; // esi
  double v9; // xmm5_8
  double v10; // xmm3_8
  tagResizerItem *pItem; // ecx
  HWND *v12; // eax
  int v13; // eax
  int v14; // eax
  LONG v15; // eax
  double v16; // xmm1_8
  int v17; // eax
  int v18; // eax
  double v20; // [esp+10h] [ebp-244h]
  int v21; // [esp+18h] [ebp-23Ch]
  int v22; // [esp+1Ch] [ebp-238h]
  double v23; // [esp+20h] [ebp-234h]
  double v24; // [esp+28h] [ebp-22Ch]
  LONG v25; // [esp+30h] [ebp-224h]
  char v26; // [esp+37h] [ebp-21Dh]
  struct tagRECT Rect; // [esp+38h] [ebp-21Ch]
  WCHAR szClassName[260]; // [esp+48h] [ebp-20Ch]

  v26 = 1;
  if ( GetParent(hWnd) == a2->m_OldWndProc )
  {
    GetWindowRect(hWnd, &Rect);
    ScreenToClient(a2->m_OldWndProc, &Rect);
    ScreenToClient(a2->m_OldWndProc, &Rect.right);
    v2 = 0.0;
    v3 = a2->m_ptMinTrackSize.y * a2->m_nYRatio;
    v4 = a2->m_ptMinTrackSize.x * a2->m_nXRatio / 100;
    v22 = v4;
    v5 = v3 / 100;
    v21 = v3 / 100;
    if ( Rect.left >= v4 )
      v24 = db_one;
    else
      v24 = 0.0;
    if ( Rect.right >= v4 )
      v23 = db_one;
    else
      v23 = 0.0;
    if ( Rect.top >= v5 )
      v20 = db_one;
    else
      v20 = 0.0;
    if ( Rect.bottom >= v5 )
      v2 = db_one;
    szClassName[0] = 0;
    memset(&szClassName[1], 0, 0x206u);
    GetClassNameW(hWnd, szClassName, 260);
    if ( !_wcsicmp(szClassName, L"Button") )
    {
      v6 = GetWindowLongW(hWnd, GWL_STYLE) & BS_TYPEMASK;
      if ( !v6 || v6 == BS_DEFPUSHBUTTON || v6 == BS_OWNERDRAW || v6 == BS_USERBUTTON )
        v26 = 0;
    }
    if ( !_wcsicmp(szClassName, L"Static") )
      InvalidateRect(hWnd, 0, 0);
    v7 = Rect.bottom;
    v8 = Rect.top;
    v25 = Rect.right;
    if ( v26 )
    {
      v10 = v2;
      v9 = v20;
    }
    else
    {
      if ( v22 - Rect.left < Rect.right - v22 )
        v24 = v23;
      else
        v23 = v24;
      if ( v21 - Rect.top < Rect.bottom - v21 )
      {
        v10 = v2;
        v9 = v2;
      }
      else
      {
        v9 = v20;
        v10 = v20;
      }
    }
    pItem = 0;
    if ( hWnd )
    {
      if ( a2->m_dwItemCount <= 0 )
      {
LABEL_34:
        pItem = 0;
      }
      else
      {
        v12 = &a2->m_pItem->m_hWnd;
        while ( *v12 != hWnd )
        {
          pItem = (pItem + 1);
          v12 += 14;
          if ( pItem >= a2->m_dwItemCount )
            goto LABEL_34;
        }
        pItem = &a2->m_pItem[pItem];
        if ( pItem )
        {
          if ( *&pItem->m_rect1.left >= 0.0 )
            v24 = *&pItem->m_rect1.left;
          if ( *&pItem->m_rect1.right >= 0.0 )
            v23 = *&pItem->m_rect1.right;
          if ( *&pItem->m_rect2.left >= 0.0 )
            v9 = *&pItem->m_rect2.left;
          if ( *&pItem->m_rect2.right >= 0.0 )
            v10 = *&pItem->m_rect2.right;
        }
      }
    }
    if ( v24 != 0.0 )
    {
      v13 = a2->m_nWidth3;
      if ( v24 == 1.0 )
        Rect.left += v13 - a2->m_ptMinTrackSize.x;
      else
        Rect.left = ((v13 - a2->m_nWidth) * *&pItem->m_rect1.left + pItem->m_rcWindow.left);
    }
    if ( v23 != 0.0 )
    {
      v14 = a2->m_nWidth3;
      if ( v23 == 1.0 )
      {
        v25 = v14 - a2->m_ptMinTrackSize.x + Rect.right;
        v15 = v14 - a2->m_ptMinTrackSize.x + Rect.right;
      }
      else
      {
        v16 = (v14 - a2->m_nWidth) * *&pItem->m_rect1.right + pItem->m_rcWindow.right;
        v15 = v16;
        v25 = v16;
      }
      Rect.right = v15;
    }
    if ( v9 != 0.0 )
    {
      v17 = a2->m_nHeight3;
      if ( v9 == 1.0 )
        v8 = v17 - a2->m_ptMinTrackSize.y + Rect.top;
      else
        v8 = ((v17 - a2->m_nHeight) * *&pItem->m_rect2.left + pItem->m_rcWindow.top);
      Rect.top = v8;
    }
    if ( v10 == 4.0 )
    {
      v7 = v8 + pItem->m_rcWindow.bottom - pItem->m_rcWindow.top;
    }
    else
    {
      if ( v10 == 0.0 )
      {
LABEL_65:
        a2->m_hDWP = DeferWindowPos(a2->m_hDWP, hWnd, 0, Rect.left, v8, v25 - Rect.left, v7 - v8, 4u);
        return 1;
      }
      v18 = a2->m_nHeight3;
      if ( v10 == 1.0 )
        v7 = v18 - a2->m_ptMinTrackSize.y + Rect.bottom;
      else
        v7 = ((v18 - a2->m_nHeight) * *&pItem->m_rect2.right + pItem->m_rcWindow.bottom);
    }
    Rect.bottom = v7;
    goto LABEL_65;
  }
  return 1;
}
// 109CB38: using guessed type double db_four;

//----- (0100FD80) --------------------------------------------------------
int __thiscall CResizer::Refresh(CResizer *lParam)
{
  CResizer *v1; // ebx
  int result; // eax
  HDWP v3; // eax
  HWND v4; // ST00_4
  int v5; // edi
  int v6; // eax
  LONG v7; // ecx
  int v8; // ST08_4
  int v9; // eax
  HWND v10; // ST00_4
  struct tagRECT rcDst; // [esp+4h] [ebp-44h]
  struct tagRECT rc; // [esp+14h] [ebp-34h]
  struct tagRECT Rect; // [esp+24h] [ebp-24h]
  RECT rcSrc2; // [esp+34h] [ebp-14h]

  v1 = lParam;
  if ( lParam->m_ptMinTrackSize.y != lParam->m_nHeight3
    || (result = lParam->m_ptMinTrackSize.x, result != lParam->m_nWidth3) )
  {
    v3 = BeginDeferWindowPos(512);
    v4 = v1->m_OldWndProc;
    v1->m_hDWP = v3;
    EnumChildWindows(v4, CResizer::EnumChildCallback, v1);
    EndDeferWindowPos(v1->m_hDWP);
    GetClientRect(v1->m_OldWndProc, &Rect);
    v5 = GetSystemMetrics(SM_CXHSCROLL);
    v6 = GetSystemMetrics(SM_CYVSCROLL);
    rcSrc2.left = Rect.right - v5;
    v7 = Rect.bottom - v6;
    rcSrc2.right = Rect.right;
    v8 = v1->m_ptMinTrackSize.y - v1->m_nHeight3;
    v9 = v1->m_ptMinTrackSize.x - v1->m_nWidth3;
    rcSrc2.top = v7;
    rcSrc2.bottom = Rect.bottom;
    _mm_storeu_si128(&rc, _mm_loadu_si128(&rcSrc2));
    OffsetRect(&rc, v9, v8);
    UnionRect(&rcDst, &rc, &rcSrc2);
    InvalidateRect(v1->m_OldWndProc, &rcDst, TRUE);
    v10 = v1->m_OldWndProc;
    v1->m_ptMinTrackSize.x = v1->m_nWidth3;
    v1->m_ptMinTrackSize.y = v1->m_nHeight3;
    result = InvalidateRect(v10, 0, TRUE);
  }
  return result;
}

//----- (0100FE80) --------------------------------------------------------
int __thiscall sub_100FE80(const wchar_t **this, wchar_t a2)
{
  const wchar_t **v2; // esi
  wchar_t *v3; // eax
  int result; // eax

  v2 = this;
  v3 = wcsrchr(*this, a2);
  if ( v3 )
    result = v3 - *v2;
  else
    result = -1;
  return result;
}

//----- (0100FEB0) --------------------------------------------------------
CStringData *__thiscall sub_100FEB0(CString *this, void *Src)
{
  CStringData *result; // eax

  if ( Src )
    result = ATL::CSimpleStringT<wchar_t,0>::SetString(this + 5, Src, wcslen(Src));
  else
    result = ATL::CSimpleStringT<wchar_t,0>::SetString(this + 5, 0, 0);
  return result;
}

//----- (0100FF00) --------------------------------------------------------
CStringData *__thiscall sub_100FF00(CString *this, void *Src)
{
  CStringData *result; // eax

  if ( Src )
    result = ATL::CSimpleStringT<wchar_t,0>::SetString(this + 1, Src, wcslen(Src));
  else
    result = ATL::CSimpleStringT<wchar_t,0>::SetString(this + 1, 0, 0);
  return result;
}

//----- (0100FF50) --------------------------------------------------------
CStringData *__thiscall sub_100FF50(CString *this, void *Src)
{
  CStringData *result; // eax

  if ( Src )
    result = ATL::CSimpleStringT<wchar_t,0>::SetString(this + 2, Src, wcslen(Src));
  else
    result = ATL::CSimpleStringT<wchar_t,0>::SetString(this + 2, 0, 0);
  return result;
}

//----- (0100FFA0) --------------------------------------------------------
CStringData *__thiscall sub_100FFA0(CString *this, void *Src)
{
  CStringData *result; // eax

  if ( Src )
    result = ATL::CSimpleStringT<wchar_t,0>::SetString(this + 3, Src, wcslen(Src));
  else
    result = ATL::CSimpleStringT<wchar_t,0>::SetString(this + 3, 0, 0);
  return result;
}

//----- (0100FFF0) --------------------------------------------------------
int __thiscall sub_100FFF0(CString *this, void *Src)
{
  CString *v2; // edi
  unsigned __int16 *v3; // esi
  int v4; // edx
  CString *v5; // edi
  int v6; // ecx
  int result; // eax
  void **v8; // eax
  char *v9; // edx

  v2 = this;
  v3 = Src;
  if ( Src )
    v4 = wcslen(Src);
  else
    v4 = 0;
  ATL::CSimpleStringT<wchar_t,0>::SetString(this + 4, Src, v4);
  v5 = v2 + 1;
  if ( v3 )
    v6 = wcslen(v3);
  else
    v6 = 0;
  ATL::CSimpleStringT<wchar_t,0>::SetString(v5, v3, v6);
  result = v5->pszData;
  if ( *(v5->pszData - 3) > 0 )
  {
    result = wcschr(result, 0x2Cu);
    if ( result )
    {
      result = (result - v5->pszData) >> 1;
      if ( result >= 0 )
      {
        v8 = sub_100F790(v5, &Src, 0, result);
        sub_100D840(v5, v8);
        v9 = Src - 16;
        result = Src - 4;
        if ( _InterlockedDecrement(result) <= 0 )
          result = (*(**v9 + 4))(v9);
      }
    }
  }
  return result;
}

//----- (010100E0) --------------------------------------------------------
CStringData *__thiscall sub_10100E0(CString *this, void *Src)
{
  CStringData *result; // eax

  if ( Src )
    result = ATL::CSimpleStringT<wchar_t,0>::SetString(this + 6, Src, wcslen(Src));
  else
    result = ATL::CSimpleStringT<wchar_t,0>::SetString(this + 6, 0, 0);
  return result;
}

//----- (01010130) --------------------------------------------------------
int __thiscall sub_1010130(HWND *this)
{
  HWND *v1; // edi
  LONG v2; // ecx
  int v3; // ST10_4
  int v4; // ecx
  HWND v5; // ST00_4
  struct tagRECT Rect; // [esp+8h] [ebp-24h]
  struct tagRECT rcDst; // [esp+18h] [ebp-14h]

  v1 = this;
  GetClientRect(this[2], &Rect);
  CopyRect(&rcDst, &Rect);
  v2 = rcDst.right - 10;
  rcDst.bottom -= 10;
  rcDst.right = v2;
  v3 = rcDst.bottom - (rcDst.top + 10);
  v4 = v2 - (rcDst.left + 10);
  rcDst.left += 10;
  v5 = v1[1];
  rcDst.top += 10;
  MoveWindow(v5, rcDst.left, rcDst.top, v4, v3, 1);
  return rcDst.right - rcDst.left;
}

//----- (010101B0) --------------------------------------------------------
void *__thiscall sub_10101B0(int this)
{
  return sub_100CC30(*(this + 32), *(this + 36), (*(this + 36) - *(this + 32)) >> 2, sub_100E780);
}

//----- (010101D0) --------------------------------------------------------
int __cdecl sub_10101D0(wchar_t *Dst, rsize_t SizeInWords, int a3)
{
  return sub_100E970(Dst, SizeInWords, a3, &unk_10BD150, 5);
}

//----- (01010200) --------------------------------------------------------
int __cdecl sub_1010200(wchar_t *Src, int a2)
{
  signed int v2; // edi
  const wchar_t *v3; // ebx
  signed int v4; // esi
  const wchar_t *v5; // edi
  int result; // eax
  wchar_t Dst; // [esp+14h] [ebp-18h]
  __int16 v8; // [esp+18h] [ebp-14h]
  __int16 v9; // [esp+1Ch] [ebp-10h]
  __int16 v10; // [esp+24h] [ebp-8h]

  wcsncpy_s(&Dst, 0xAu, Src, 8u);
  v10 = 0;
  *a2 = sub_100F690(&Dst);
  wcsncpy_s(&Dst, 0xAu, Src + 9, 4u);
  v9 = 0;
  *(a2 + 4) = sub_100F690(&Dst);
  wcsncpy_s(&Dst, 0xAu, Src + 14, 4u);
  v9 = 0;
  *(a2 + 6) = sub_100F690(&Dst);
  v2 = 0;
  v3 = Src + 19;
  do
  {
    wcsncpy_s(&Dst, 0xAu, v3, 2u);
    v8 = 0;
    *(a2 + 8 + v2++) = sub_100F690(&Dst);
    v3 += 2;
  }
  while ( v2 < 2 );
  v4 = 2;
  v5 = Src + 24;
  do
  {
    wcsncpy_s(&Dst, 0xAu, v5, 2u);
    v8 = 0;
    result = sub_100F690(&Dst);
    *(a2 + 8 + v4++) = result;
    v5 += 2;
  }
  while ( v4 < 8 );
  return result;
}

//----- (01010310) --------------------------------------------------------
LRESULT __stdcall CResizer::Proxy_WndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
  LPARAM v4; // esi
  CResizer *v5; // eax
  WPARAM v6; // edx
  CResizer *v7; // edi
  UINT Msg_1; // eax
  LRESULT result; // eax
  int v10; // edx
  int v11; // ecx
  bool v12; // sf
  unsigned __int8 v13; // of
  int v14; // eax
  LRESULT v15; // edi
  POINT v16; // ST10_8
  LONG v17; // ecx
  HTHEME v18; // eax
  LRESULT (__stdcall *v19)(HWND, UINT, WPARAM, LPARAM); // esi
  HDC hdc; // [esp+Ch] [ebp-5Ch]
  struct tagPAINTSTRUCT Paint; // [esp+14h] [ebp-54h]
  struct tagRECT Rect; // [esp+54h] [ebp-14h]

  v4 = lParam;
  v5 = GetPropW(hWnd, L"ResizerClass");
  v6 = wParam;
  v7 = v5;
  Msg_1 = Msg;
  switch ( Msg )
  {
    case WM_DESTROY:
      v19 = v7->m_hWnd;
      SetWindowLongW(hWnd, GWLP_WNDPROC, v7->m_hWnd);
      CResizer::~CResizer(v7);
      j__free(v7);
      return CallWindowProcW(v19, hWnd, Msg, wParam, lParam);
    case WM_SIZE:
      if ( !v7->m_FixedBorder || wParam != SIZE_MAXIMIZED && wParam )
        goto LABEL_13;
      if ( GetWindowRect(hWnd, &Rect) )
      {
        v10 = Rect.right - Rect.left;
        v11 = Rect.bottom - Rect.top;
        if ( Rect.right - Rect.left < v7->m_nWidth )
          v10 = v7->m_nWidth;
        v13 = __OFSUB__(v11, v7->m_nHeight);
        v12 = v11 - v7->m_nHeight < 0;
        v7->m_nWidth3 = v10;
        if ( v12 ^ v13 )
          v11 = v7->m_nHeight;
        v7->m_nHeight3 = v11;
        CResizer::Refresh(v7);
      }
      goto LABEL_12;
    case WM_SETVISIBLE|WM_ACTIVATE:
      if ( !(GetWindowLongW(hWnd, GWL_STYLE) & WS_CHILD) && !IsZoomed(hWnd) )
      {
        hdc = BeginPaint(hWnd, &Paint);
        GetClientRect(hWnd, &Rect);
        Rect.left = Rect.right - GetSystemMetrics(21);
        v17 = Rect.bottom - GetSystemMetrics(20);
        v18 = v7->baseclass.m_hThemeHandle;
        Rect.top = v17;
        if ( v18 )
          gpfnDrawThemeBackground(v18, hdc, 3, 0, &Rect, 0);
        else
          DrawFrameControl(hdc, &Rect, 3u, 8u);
        EndPaint(hWnd, &Paint);
        v4 = lParam;
      }
LABEL_12:
      Msg_1 = Msg;
      goto LABEL_13;
    case 0x24u:
      *(lParam + 24) = v7->m_nWidth;
      *(lParam + 28) = v7->m_nHeight;
      result = 0;
      break;
    case WM_NCHITTEST:
      v15 = CallWindowProcW(v7->m_hWnd, hWnd, Msg, wParam, lParam);
      if ( GetWindowLongW(hWnd, GWL_STYLE) & WS_CHILD
        || v15 != 1
        || IsZoomed(hWnd)
        || (GetWindowRect(hWnd, &Rect),
            Rect.left = Rect.right - GetSystemMetrics(21),
            Rect.top = Rect.bottom - GetSystemMetrics(20),
            v16.y = SHIWORD(lParam),
            v16.x = lParam,
            !PtInRect(&Rect, v16)) )
      {
        result = v15;
      }
      else
      {
        result = 17;
      }
      break;
    default:
LABEL_13:
      if ( Msg_1 == WM_THEMECHANGED )
      {
        if ( v7->baseclass.m_hThemeHandle )
          gpfnCloseThemeData(v7->baseclass.m_hThemeHandle);
        v7->baseclass.m_hThemeHandle = 0;
        if ( gpfnIsThemeActive )
        {
          if ( gpfnIsThemeActive() )
          {
            v14 = (v7->baseclass.vtptr->GetName)(v7);
            v7->baseclass.m_hThemeHandle = gpfnOpenThemeData(hWnd, v14);
          }
        }
      }
      result = (v7->baseclass.vtptr->HandleMessage)(v7, v6, hWnd, Msg, wParam, v4);
      break;
  }
  return result;
}
// 10C4D84: using guessed type int (__stdcall *gpfnIsThemeActive)();

//----- (01010650) --------------------------------------------------------
char *__thiscall sub_1010650(const void **this, unsigned int a2)
{
  unsigned int v2; // ebx
  char *v3; // esi
  const void **v4; // edi
  char *result; // eax
  int v6; // [esp+14h] [ebp+8h]

  v2 = a2;
  v3 = 0;
  v4 = this;
  if ( a2 )
  {
    if ( a2 > 0x7FFFFFFF || (v3 = operator new(2 * a2)) == 0 )
      std::_Xbad_alloc();
  }
  memmove(v3, *v4, (v4[1] - *v4) & 0xFFFFFFFE);
  v6 = (v4[1] - *v4) >> 1;
  if ( *v4 )
    j__free(*v4);
  *v4 = v3;
  v4[2] = &v3[2 * v2];
  result = &v3[2 * v6];
  v4[1] = result;
  return result;
}

//----- (010106D0) --------------------------------------------------------
char *__thiscall std::vector<tagAccountInfo *,std::allocator<tagAccountInfo *>>::_Reallocate(std__vector *this, unsigned int a2)
{
  unsigned int v2; // ebx
  char *v3; // esi
  std__vector *v4; // edi
  char *result; // eax
  int v6; // [esp+14h] [ebp+8h]

  v2 = a2;
  v3 = 0;
  v4 = this;
  if ( a2 )
  {
    if ( a2 > 0x3FFFFFFF || (v3 = operator new(4 * a2)) == 0 )
      std::_Xbad_alloc();
  }
  memmove(
    v3,
    v4->baseclass_0._Mypair._Myval2._Myfirst,
    (v4->baseclass_0._Mypair._Myval2._Mylast - v4->baseclass_0._Mypair._Myval2._Myfirst) & 0xFFFFFFFC);
  v6 = (v4->baseclass_0._Mypair._Myval2._Mylast - v4->baseclass_0._Mypair._Myval2._Myfirst) >> 2;
  if ( v4->baseclass_0._Mypair._Myval2._Myfirst )
    j__free(v4->baseclass_0._Mypair._Myval2._Myfirst);
  v4->baseclass_0._Mypair._Myval2._Myfirst = v3;
  v4->baseclass_0._Mypair._Myval2._Myend = &v3[4 * v2];
  result = &v3[4 * v6];
  v4->baseclass_0._Mypair._Myval2._Mylast = result;
  return result;
}

//----- (01010750) --------------------------------------------------------
unsigned int __thiscall sub_1010750(int this, unsigned int a2)
{
  int v2; // esi
  unsigned int result; // eax
  int v4; // esi
  unsigned int v5; // esi
  unsigned int v6; // edx
  unsigned int v7; // edx
  unsigned int v8; // edx

  v2 = *(this + 4);
  result = (*(this + 8) - v2) >> 1;
  if ( result < a2 )
  {
    v4 = (v2 - *this) >> 1;
    if ( 0x7FFFFFFF - v4 < a2 )
      std::_Xlength_error("vector<T> too long");
    v5 = a2 + v4;
    v6 = (*(this + 8) - *this) >> 1;
    if ( 0x7FFFFFFF - (v6 >> 1) >= v6 )
    {
      v8 = (v6 >> 1) + v6;
      if ( v8 < v5 )
        v8 = v5;
      result = sub_1010650(this, v8);
    }
    else
    {
      v7 = 0;
      if ( v5 > 0 )
        v7 = v5;
      result = sub_1010650(this, v7);
    }
  }
  return result;
}

//----- (010107C0) --------------------------------------------------------
unsigned int __thiscall std::vector<tagAccountInfo *,std::allocator<tagAccountInfo *>>::_Reserve(std__vector *this, unsigned int a2)
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
      result = std::vector<tagAccountInfo *,std::allocator<tagAccountInfo *>>::_Reallocate(this, v8);
    }
    else
    {
      v7 = 0;
      if ( v5 > 0 )
        v7 = v5;
      result = std::vector<tagAccountInfo *,std::allocator<tagAccountInfo *>>::_Reallocate(this, v7);
    }
  }
  return result;
}

//----- (01010840) --------------------------------------------------------
int __thiscall sub_1010840(_DWORD *this, int a2, void *a3)
{
  _DWORD *v3; // edi
  int result; // eax

  v3 = this;
  memmove(a3, a3 + 2, (this[1] - (a3 + 2)) & 0xFFFFFFFE);
  result = a2;
  v3[1] -= 2;
  *a2 = a3;
  return result;
}

//----- (01010880) --------------------------------------------------------
__int16 __thiscall sub_1010880(_DWORD *this, _WORD *a2)
{
  _DWORD *v2; // esi
  unsigned int v3; // eax
  int v4; // edi
  _WORD *v5; // ecx
  _WORD *v6; // ecx

  v2 = this;
  v3 = this[1];
  if ( a2 >= v3 || *this > a2 )
  {
    if ( v3 == this[2] )
      LOWORD(v3) = sub_1010750(this, 1u);
    v6 = v2[1];
    if ( v6 )
    {
      LOWORD(v3) = *a2;
      *v6 = *a2;
    }
    goto LABEL_11;
  }
  v4 = (a2 - *this) >> 1;
  if ( v3 == this[2] )
    LOWORD(v3) = sub_1010750(this, 1u);
  v5 = v2[1];
  if ( !v5 )
  {
LABEL_11:
    v2[1] += 2;
    return v3;
  }
  LOWORD(v3) = *(*v2 + 2 * v4);
  *v5 = v3;
  v2[1] += 2;
  return v3;
}

//----- (010108F0) --------------------------------------------------------
tagAccountInfo *__thiscall std::vector<tagAccountInfo *,std::allocator<tagAccountInfo *>>::push_back(std__vector *this, tagAccountInfo *pInfo)
{
  std__vector *v2; // esi
  tagAccountInfo *result; // eax
  int v4; // edi
  _DWORD *v5; // ecx
  _DWORD *v6; // ecx

  v2 = this;
  result = this->baseclass_0._Mypair._Myval2._Mylast;
  if ( pInfo >= result || this->baseclass_0._Mypair._Myval2._Myfirst > pInfo )
  {
    if ( result == this->baseclass_0._Mypair._Myval2._Myend )
      result = std::vector<tagAccountInfo *,std::allocator<tagAccountInfo *>>::_Reserve(this, 1u);
    v6 = v2->baseclass_0._Mypair._Myval2._Mylast;
    if ( v6 )
    {
      result = pInfo->bIsSystemUser;
      *v6 = pInfo->bIsSystemUser;
    }
  }
  else
  {
    v4 = (pInfo - this->baseclass_0._Mypair._Myval2._Myfirst) >> 2;
    if ( result == this->baseclass_0._Mypair._Myval2._Myend )
      result = std::vector<tagAccountInfo *,std::allocator<tagAccountInfo *>>::_Reserve(this, 1u);
    v5 = v2->baseclass_0._Mypair._Myval2._Mylast;
    if ( v5 )
    {
      result = *(v2->baseclass_0._Mypair._Myval2._Myfirst + v4);
      *v5 = result;
      v2->baseclass_0._Mypair._Myval2._Mylast = v2->baseclass_0._Mypair._Myval2._Mylast + 4;
      return result;
    }
  }
  v2->baseclass_0._Mypair._Myval2._Mylast = v2->baseclass_0._Mypair._Myval2._Mylast + 4;
  return result;
}

//----- (01010960) --------------------------------------------------------
bool __cdecl ProcessIsNetCclr_0(tagTREEVIEWLISTITEMPARAM *a1)
{
  int v1; // eax
  DWORD pdwFlags; // [esp+0h] [ebp-4h]

  pdwFlags = 0;
  v1 = a1->dwProcessId;
  if ( !v1 || !EnableTraceEx )
    return 0;
  ProcessIsNetCclr(v1, &pdwFlags);
  return pdwFlags != 0;
}

//----- (010109A0) --------------------------------------------------------
int __cdecl sub_10109A0(wchar_t *Dst, int a2, __int64 a3)
{
  int result; // eax

  if ( gConfig.bShowCpuFractions )
    result = swprintf_s(Dst, 0x20u, L"%s%0.2f%%", a2, a3);
  else
    result = swprintf_s(Dst, 0x20u, L"%s%0.0f%%", a2, a3);
  return result;
}

//----- (010109F0) --------------------------------------------------------
int __cdecl sub_10109F0(wchar_t *Dst, int a2, __int64 a3)
{
  int result; // eax

  if ( gConfig.bShowCpuFractions )
    result = swprintf_s(Dst, 0x400u, L"%s%0.2f%%", a2, a3);
  else
    result = swprintf_s(Dst, 0x400u, L"%s%0.0f%%", a2, a3);
  return result;
}

//----- (01010A40) --------------------------------------------------------
errno_t __cdecl sub_1010A40(wchar_t *a1, int a2, __int64 a3)
{
  return sub_1012410(a1, 0x400u, a2, a3);
}

//----- (01010A70) --------------------------------------------------------
int wsprintfW(wchar_t *Dst, wchar_t *Format, ...)
{
  va_list ArgList; // [esp+10h] [ebp+10h]

  va_start(ArgList, Format);
  return vswprintf_s(Dst, 0x400u, Format, ArgList);
}

//----- (01010A90) --------------------------------------------------------
int __thiscall sub_1010A90(BitmapItem *this, int a2, int a3, int a4, int a5, unsigned int a6, int a7)
{
  char v7; // al
  int v8; // edx
  int v9; // edi
  int v10; // ebx
  int v11; // esi
  int result; // eax
  int v13; // ecx
  int v14; // edx
  int v15; // ebx
  int *v16; // eax
  bool v17; // zf
  int v18; // [esp+Ch] [ebp-10h]
  int v19; // [esp+10h] [ebp-Ch]
  int v20; // [esp+14h] [ebp-8h]
  BitmapItem *v21; // [esp+18h] [ebp-4h]
  signed int v22; // [esp+24h] [ebp+8h]
  signed int v23; // [esp+28h] [ebp+Ch]
  int v24; // [esp+2Ch] [ebp+10h]
  int v25; // [esp+30h] [ebp+14h]
  int *v26; // [esp+30h] [ebp+14h]
  int v27; // [esp+30h] [ebp+14h]

  v7 = a7;
  v21 = this;
  if ( a7 )
  {
    v7 = a7;
    v20 = (a6 + (256 - a6) / 2) | (((BYTE1(a6) + (256 - BYTE1(a6)) / 2) | ((BYTE2(a6) + (256 - BYTE2(a6)) / 2) << 8)) << 8);
    v8 = (a6 + (256 - a6) / 2) | (((BYTE1(a6) + (256 - BYTE1(a6)) / 2) | ((BYTE2(a6) + (256 - BYTE2(a6)) / 2) << 8)) << 8);
  }
  else
  {
    v8 = a7;
    v20 = a7;
  }
  v9 = a2;
  v10 = a4 - a2;
  v11 = a3;
  v25 = a5 - a3;
  if ( v7 )
    sub_1010E50(this, a3, a2, a3, this->nHeight, v8, 0);
  else
    this->pBits[a3 + a2 * this->nWidth] = (a6 & 0xFF00) | (a6 << 16) | (a6 >> 16) & 0xFF;
  if ( v10 >= 0 )
  {
    v22 = 1;
  }
  else
  {
    v22 = -1;
    v10 = -v10;
  }
  result = v25;
  if ( v25 >= 0 )
  {
    v23 = 1;
  }
  else
  {
    v23 = -1;
    result = -v25;
  }
  v13 = 2 * v10;
  v14 = 2 * result;
  v19 = 2 * v10;
  v18 = 2 * result;
  if ( 2 * result < 2 * v10 )
  {
    if ( v10 > 0 )
    {
      v27 = v10;
      do
      {
        v9 += v22;
        v10 += v14;
        if ( v10 > v13 )
        {
          v11 += v23;
          v10 -= v13;
        }
        if ( a7 )
        {
          LOBYTE(result) = sub_1010E50(v21, v11, v9, v11, v21->nHeight, v20, 0);
        }
        else
        {
          result = v21->pBits;
          *(result + 4 * (v11 + v9 * v21->nWidth)) = (a6 & 0xFF00) | (a6 << 16) | (a6 >> 16) & 0xFF;
        }
        v17 = v27-- == 1;
        v13 = v19;
        v14 = v18;
      }
      while ( !v17 );
    }
  }
  else if ( result > 0 )
  {
    v15 = result;
    v24 = result;
    do
    {
      v11 += v23;
      v16 = (v13 + result);
      v26 = v16;
      if ( v16 > v14 )
      {
        v9 += v22;
        v26 = (v16 - v14);
      }
      if ( a7 )
      {
        sub_1010E50(v21, v11, v9, v11, v21->nHeight, v20, 0);
        v15 = v24;
      }
      else
      {
        v21->pBits[v11 + v9 * v21->nWidth] = (a6 & 0xFF00) | (a6 << 16) | (a6 >> 16) & 0xFF;
      }
      result = v26;
      --v15;
      v13 = v19;
      v14 = v18;
      v24 = v15;
    }
    while ( v15 );
  }
  return result;
}
