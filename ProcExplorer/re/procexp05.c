//----- (00C1C770) --------------------------------------------------------
tagPEStringStruct *__thiscall sub_C1C770(tagPEStringStruct *this, _bstr_t *a2)
{
  tagPEStringStruct *v2; // edi
  tagPEStringStruct *v3; // esi
  Data_t_bstr_t *v4; // ecx
  Data_t_bstr_t *v5; // eax
  OLECHAR *v6; // eax

  v2 = (tagPEStringStruct *)this->strValue[0];
  v3 = *(tagPEStringStruct **)(this->strValue[0] + 4);
  while ( !BYTE1(v3->strValue[3]) )
  {
    v4 = (Data_t_bstr_t *)v3->strValue[4];
    v5 = a2->m_Data;
    if ( v4 != a2->m_Data )
    {
      if ( v4 )
      {
        if ( v5 )
        {
          if ( _bstr_t::Data_t::Compare(v4, a2->m_Data) < 0 )
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
            v3 = (tagPEStringStruct *)v3->strValue[2];
            continue;
          }
        }
      }
    }
    v2 = v3;
    v3 = (tagPEStringStruct *)v3->strValue[0];
  }
  return v2;
}

//----- (00C1C7E0) --------------------------------------------------------
int __cdecl sub_C1C7E0(int a1, int a2, int a3, _DWORD *a4, unsigned __int8 (__cdecl *a5)(_DWORD, _DWORD))
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
    if ( a5(*(_DWORD *)(a1 + 4 * v7), *(_DWORD *)(a1 + 4 * v7 - 4)) )
      --v7;
    v5 = a3;
    *(_DWORD *)(a1 + 4 * v6) = *(_DWORD *)(a1 + 4 * v7);
    v6 = v7;
    v7 = 2 * v7 + 2;
  }
  if ( i )
  {
    *(_DWORD *)(a1 + 4 * v6) = *(_DWORD *)(a1 + 4 * v5 - 4);
    v6 = v5 - 1;
  }
  for ( j = (v6 - 1) / 2; a2 < v6; j = (j - 1) / 2 )
  {
    if ( !a5(*(_DWORD *)(a1 + 4 * j), *a4) )
      break;
    *(_DWORD *)(a1 + 4 * v6) = *(_DWORD *)(a1 + 4 * j);
    v6 = j;
  }
  result = *a4;
  *(_DWORD *)(a1 + 4 * v6) = *a4;
  return result;
}

//----- (00C1C880) --------------------------------------------------------
void *__cdecl sub_C1C880(void *a1, int a2, int a3)
{
  void *result; // eax
  _DWORD *v4; // esi
  _DWORD *v5; // edi
  int v6; // ebx
  _DWORD *v7; // esi
  int v8; // ST08_4
  char *v9; // [esp+4h] [ebp-8h]
  _DWORD *v10; // [esp+8h] [ebp-4h]

  result = (void *)a2;
  v4 = a1;
  if ( a1 != (void *)a2 )
  {
    v5 = (char *)a1 + 4;
    v9 = (char *)a1 + 4;
    if ( (char *)a1 + 4 != (void *)a2 )
    {
      do
      {
        v6 = *v5;
        v10 = v5;
        if ( ((unsigned __int8 (__cdecl *)(_DWORD, _DWORD))a3)(*v5, *v4) )
        {
          result = memmove(&v5[-(v5 - v4) + 1], v4, 4 * (v5 - v4));
          *v4 = v6;
        }
        else
        {
          v7 = v5 - 1;
          if ( ((unsigned __int8 (__cdecl *)(int, _DWORD))a3)(v6, *(v5 - 1)) )
          {
            do
            {
              *v5 = *v7;
              v5 = v7;
              v8 = *(v7 - 1);
              --v7;
            }
            while ( ((unsigned __int8 (__cdecl *)(int, int))a3)(v6, v8) );
            v10 = v5;
            v5 = v9;
          }
          result = v10;
          v4 = a1;
          *v10 = v6;
        }
        ++v5;
        v9 = (char *)v5;
      }
      while ( v5 != (_DWORD *)a2 );
    }
  }
  return result;
}

//----- (00C1C930) --------------------------------------------------------
int __cdecl sub_C1C930(int a1, int a2, unsigned __int8 (__cdecl *a3)(_DWORD, _DWORD))
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
      v8 = *(_DWORD *)(v3 + 4 * v6 - 4);
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
          if ( a3(*(_DWORD *)(v3 + 4 * v10), *(_DWORD *)(v3 + 4 * v10 - 4)) )
            --v10;
          v4 = v15;
          *(_DWORD *)(v3 + 4 * v11) = *(_DWORD *)(v3 + 4 * v10);
          v11 = v10;
          v10 = 2 * v10 + 2;
        }
        while ( v10 < v15 );
        v9 = v14;
      }
      if ( v10 == v4 )
      {
        *(_DWORD *)(v3 + 4 * v11) = *(_DWORD *)(v3 + 4 * v4 - 4);
        v11 = v4 - 1;
      }
      result = sub_C1CBC0(v3, v11, v9, &v12, a3);
      v6 = v14;
      v4 = v15;
      v7 = v13;
    }
    while ( v14 > 0 );
  }
  return result;
}

//----- (00C1C9E0) --------------------------------------------------------
int __cdecl sub_C1C9E0(int *a1, int *a2, int *a3, unsigned __int8 (__cdecl *a4)(int, int))
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
    if ( (_BYTE)result )
    {
      v25 = *a3;
      *a3 = *a2;
      *a2 = v25;
      result = a4(v25, *a1);
      if ( (_BYTE)result )
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
    v8 = *(int *)((char *)a1 + v6);
    v9 = (int *)((char *)a1 + v6);
    v28 = v7;
    v30 = v6;
    if ( a4(v8, v27) )
    {
      v10 = *v9;
      *v9 = *v4;
      *v4 = v10;
    }
    if ( a4(*(int *)((char *)v4 + v28), *v9) )
    {
      v11 = *(int *)((char *)v4 + v28);
      *(int *)((char *)v4 + v28) = *v9;
      *v9 = v11;
      if ( a4(v11, *v4) )
      {
        v12 = *v9;
        *v9 = *v4;
        *v4 = v12;
      }
    }
    v29 = (int *)((char *)a2 - v30);
    if ( a4(*a2, *(int *)((char *)a2 - v30)) )
    {
      v13 = *a2;
      *a2 = *v29;
      *v29 = v13;
    }
    if ( a4(*(int *)((char *)a2 + v30), *a2) )
    {
      v14 = *(int *)((char *)a2 + v30);
      *(int *)((char *)a2 + v30) = *a2;
      *a2 = v14;
      if ( a4(v14, *v29) )
      {
        v15 = *a2;
        *a2 = *v29;
        *v29 = v15;
      }
    }
    v16 = (int *)((char *)a3 - v30);
    v31 = (int *)((char *)a3 - v28);
    if ( a4(*v16, *(int *)((char *)a3 - v28)) )
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
    if ( (_BYTE)result )
    {
      v22 = *v16;
      *v16 = *a2;
      *a2 = v22;
      result = a4(v22, *v9);
      if ( (_BYTE)result )
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

//----- (00C1CBC0) --------------------------------------------------------
int __cdecl sub_C1CBC0(int a1, int a2, int a3, _DWORD *a4, unsigned __int8 (__cdecl *a5)(_DWORD, _DWORD))
{
  int v5; // edi
  int v6; // esi
  int result; // eax

  v5 = a2;
  v6 = (a2 - 1) / 2;
  if ( a3 >= a2 )
  {
    result = a1;
    *(_DWORD *)(a1 + 4 * a2) = *a4;
  }
  else
  {
    do
    {
      if ( !a5(*(_DWORD *)(a1 + 4 * v6), *a4) )
        break;
      *(_DWORD *)(a1 + 4 * v5) = *(_DWORD *)(a1 + 4 * v6);
      v5 = v6;
      v6 = (v6 - 1) / 2;
    }
    while ( a3 < v5 );
    result = *a4;
    *(_DWORD *)(a1 + 4 * v5) = *a4;
  }
  return result;
}

//----- (00C1CC30) --------------------------------------------------------
void *__cdecl sub_C1CC30(void *a1, int a2, int a3, int a4)
{
  unsigned __int8 (__cdecl *v4)(int, int); // edx
  int *v5; // esi
  int *v6; // edi
  int v7; // ecx
  int v8; // ebx
  void *result; // eax
  int v10; // [esp+Ch] [ebp-8h]
  void *v11; // [esp+10h] [ebp-4h]

  v4 = (unsigned __int8 (__cdecl *)(int, int))a4;
  v5 = (int *)a2;
  v6 = (int *)a1;
  v7 = (a2 - (signed int)a1) >> 2;
  if ( v7 <= 32 )
    goto LABEL_8;
  v8 = a3;
  while ( v8 > 0 )
  {
    sub_C1CD70((int **)&v10, v6, v5, v4);
    v8 = v8 / 2 / 2 + v8 / 2;
    if ( (signed int)((v10 - (_DWORD)v6) & 0xFFFFFFFC) >= (signed int)(((char *)v5 - (_BYTE *)v11) & 0xFFFFFFFC) )
    {
      result = sub_C1CC30(v11, (int)v5, v8, a4);
      v5 = (int *)v10;
    }
    else
    {
      result = sub_C1CC30(v6, v10, v8, a4);
      v6 = (int *)v11;
    }
    v4 = (unsigned __int8 (__cdecl *)(int, int))a4;
    v7 = v5 - v6;
    if ( v7 <= 32 )
      goto LABEL_8;
  }
  if ( v7 <= 32 )
  {
LABEL_8:
    if ( v7 > 1 )
      result = sub_C1C880(v6, (int)v5, (int)v4);
  }
  else
  {
    if ( (signed int)(((char *)v5 - (char *)v6) & 0xFFFFFFFC) > 4 )
    {
      sub_C1C930((int)v6, (int)v5, v4);
      v4 = (unsigned __int8 (__cdecl *)(int, int))a4;
    }
    result = (void *)sub_C1CD10(v6, (int)v5, v4);
  }
  return result;
}

//----- (00C1CD10) --------------------------------------------------------
signed int __cdecl sub_C1CD10(_DWORD *a1, int a2, unsigned __int8 (__cdecl *a3)(_DWORD, _DWORD))
{
  int v3; // esi
  signed int result; // eax
  unsigned __int8 (__cdecl *v5)(_DWORD, _DWORD); // ebx

  v3 = a2 - (_DWORD)a1;
  result = (a2 - (_DWORD)a1) & 0xFFFFFFFC;
  if ( result > 4 )
  {
    v5 = a3;
    do
    {
      a2 = *(_DWORD *)((char *)a1 + v3 - 4);
      *(_DWORD *)((char *)a1 + v3 - 4) = *a1;
      v3 -= 4;
      sub_C1C7E0((int)a1, 0, v3 >> 2, &a2, v5);
      result = v3 & 0xFFFFFFFC;
    }
    while ( (signed int)(v3 & 0xFFFFFFFC) > 4 );
  }
  return result;
}

//----- (00C1CD70) --------------------------------------------------------
int **__cdecl sub_C1CD70(int **a1, int *a2, int *a3, unsigned __int8 (__cdecl *a4)(int, int))
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
  sub_C1C9E0(a2, &a2[v4 / 2], a3 - 1, a4);
  v6 = v5 + 1;
  v29 = (int)(v5 + 1);
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
    v6 = (int *)v29;
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
    v29 = (int)v6;
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
        v29 = (int)v6;
        v27 = v9;
      }
      v12 = v8 == a2;
      if ( v8 <= a2 )
        goto LABEL_32;
      v13 = (unsigned int)v28;
      v14 = v28 - 1;
      while ( a4(*v14, *v5) )
      {
LABEL_28:
        v16 = a2;
        v13 -= 4;
        --v14;
        if ( (unsigned int)a2 >= v13 )
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
      v6 = (int *)v29;
      v28 = (int *)v13;
      v8 = (int *)v13;
      v12 = v13 == (_DWORD)v16;
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
        v29 = (int)v6;
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
      v29 = (int)(v6 + 1);
      ++v5;
      v19 = v9;
      ++v9;
      v20 = *v18;
      *v18 = *v19;
      v8 = v28;
      v7 = a3;
      *v19 = v20;
      v6 = (int *)v29;
      continue;
    }
    break;
  }
  result = a1;
  a1[1] = v6;
  *a1 = v5;
  return result;
}

//----- (00C1CF50) --------------------------------------------------------
_DWORD *__cdecl sub_C1CF50(_DWORD *a1, _WORD *a2, _WORD *a3, _WORD *a4)
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

//----- (00C1CF80) --------------------------------------------------------
void **__thiscall sub_C1CF80(void **this, void *Src, int a3, int a4)
{
  void **v4; // edi
  int v5; // eax
  int v6; // eax

  v4 = this;
  if ( !a4 )
    ATL::AtlThrowImpl(0x80004005);
  if ( !Src && a3 )
    goto LABEL_13;
  v5 = (**(int (__stdcall ***)(int, signed int))a4)(a3, 2);
  if ( !v5 )
    ATL::CSimpleStringT<wchar_t,0>::ThrowMemoryException();
  v6 = v5 + 16;
  *v4 = (void *)v6;
  if ( a3 < 0 || a3 > *(_DWORD *)(v6 - 8) )
LABEL_13:
    ATL::AtlThrowImpl(0x80070057);
  *(_DWORD *)(v6 - 12) = a3;
  *((_WORD *)*v4 + a3) = 0;
  memcpy_s(*v4, 2 * a3, Src, 2 * a3);
  return v4;
}

//----- (00C1D000) --------------------------------------------------------
AppDomain *__thiscall AppDomain::AppDomain(AppDomain *this, int a2, int a3)
{
  AppDomain *v3; // esi
  IAtlStringMgr *v4; // ecx
  IAtlStringMgr *v5; // ecx
  AppDomain *result; // eax

  v3 = this;
  *((_DWORD *)this + 2) = a2;
  *(_DWORD *)this = &Appdomain::`vftable';
  *((_DWORD *)this + 3) = a3;
  *((_DWORD *)this + 4) = 0;
  v4 = ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>::GetDefaultManager();
  if ( !v4 )
    ATL::AtlThrowImpl(-2147467259);
  *((_DWORD *)v3 + 5) = ((int (*)(void))v4->vtptr->GetNilData)() + 16;
  v5 = ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>::GetDefaultManager();
  if ( !v5 )
    ATL::AtlThrowImpl(-2147467259);
  *((_DWORD *)v3 + 6) = ((int (*)(void))v5->vtptr->GetNilData)() + 16;
  result = v3;
  *((_DWORD *)v3 + 7) = 0;
  *((_DWORD *)v3 + 8) = 0;
  *((_DWORD *)v3 + 9) = 0;
  return result;
}
// CAC910: using guessed type void *Appdomain::`vftable';

//----- (00C1D080) --------------------------------------------------------
CString *__thiscall Assembly::Assembly(CString *this, int a2, int a3, void *a4, void *Src)
{
  CString *v5; // esi
  IAtlStringMgr *v6; // edx
  IAtlStringMgr *v7; // edx
  IAtlStringMgr *v8; // edx
  IAtlStringMgr *v9; // edx
  int v10; // ecx

  v5 = this;
  this->pszData = (CHAR *)&Assembly::`vftable';
  v6 = ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>::GetDefaultManager();
  if ( !v6 )
    ATL::AtlThrowImpl(-2147467259);
  v5[1].pszData = (CHAR *)(((int (__thiscall *)(IAtlStringMgr *))v6->vtptr->GetNilData)(v6) + 16);
  v5[2].pszData = (CHAR *)a2;
  v5[3].pszData = (CHAR *)a3;
  v7 = ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>::GetDefaultManager();
  if ( !v7 )
    ATL::AtlThrowImpl(-2147467259);
  v5[4].pszData = (CHAR *)(((int (__thiscall *)(IAtlStringMgr *))v7->vtptr->GetNilData)(v7) + 16);
  v8 = ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>::GetDefaultManager();
  if ( !v8 )
    ATL::AtlThrowImpl(-2147467259);
  v5[5].pszData = (CHAR *)(((int (__thiscall *)(IAtlStringMgr *))v8->vtptr->GetNilData)(v8) + 16);
  v9 = ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>::GetDefaultManager();
  if ( !v9 )
    ATL::AtlThrowImpl(-2147467259);
  v5[6].pszData = (CHAR *)(((int (__thiscall *)(IAtlStringMgr *))v9->vtptr->GetNilData)(v9) + 16);
  if ( Src )
    v10 = wcslen((const unsigned __int16 *)Src);
  else
    v10 = 0;
  ATL::CSimpleStringT<wchar_t,0>::SetString(v5 + 5, Src, v10);
  sub_C1FFF0(v5, a4);
  return v5;
}
// CAC930: using guessed type void *Assembly::`vftable';

//----- (00C1D1D0) --------------------------------------------------------
CResizer *__thiscall CResizer::CResizer(CResizer *this, HWND hWnd)
{
  CResizer *v2; // esi

  v2 = this;
  this->baseclass.m_hThemeHandle = 0;
  this->baseclass.vtptr = (CThemedWindowVTable *)&CResizer::`vftable';
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
// CAC888: using guessed type void *CResizer::`vftable';

//----- (00C1D260) --------------------------------------------------------
_DWORD *__thiscall sub_C1D260(_DWORD *this)
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

//----- (00C1D2B0) --------------------------------------------------------
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
  *(_DWORD *)this = &Runtime::`vftable';
  v4 = ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>::GetDefaultManager();
  if ( !v4 )
    ATL::AtlThrowImpl(-2147467259);
  *((_DWORD *)v3 + 1) = ((int (*)(void))v4->vtptr->GetNilData)() + 16;
  v5 = ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>::GetDefaultManager();
  if ( !v5 )
    ATL::AtlThrowImpl(-2147467259);
  *((_DWORD *)v3 + 2) = ((int (*)(void))v5->vtptr->GetNilData)() + 16;
  v6 = ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>::GetDefaultManager();
  if ( !v6 )
    ATL::AtlThrowImpl(-2147467259);
  *((_DWORD *)v3 + 3) = ((int (*)(void))v6->vtptr->GetNilData)() + 16;
  v7 = ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>::GetDefaultManager();
  if ( !v7 )
    ATL::AtlThrowImpl(-2147467259);
  *((_DWORD *)v3 + 4) = ((int (*)(void))v7->vtptr->GetNilData)() + 16;
  *((_WORD *)v3 + 10) = a3;
  v8 = ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>::GetDefaultManager();
  if ( !v8 )
    ATL::AtlThrowImpl(-2147467259);
  *((_DWORD *)v3 + 6) = ((int (*)(void))v8->vtptr->GetNilData)() + 16;
  *((_DWORD *)v3 + 7) = a2;
  result = v3;
  *((_DWORD *)v3 + 8) = 0;
  *((_DWORD *)v3 + 9) = 0;
  *((_DWORD *)v3 + 10) = 0;
  *((_DWORD *)v3 + 11) = 0;
  *((_DWORD *)v3 + 12) = 0;
  *((_DWORD *)v3 + 13) = 0;
  return result;
}
// CAC8F0: using guessed type void *Runtime::`vftable';

//----- (00C1D3B0) --------------------------------------------------------
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
  *this = (void (__stdcall ****)(signed int))&Appdomain::`vftable';
  v2 = this[7];
  v3 = 0;
  v4 = (unsigned int)((char *)this[8] - (char *)v2 + 3) >> 2;
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
    operator delete(v1[7]);
    v1[7] = 0;
    v1[8] = 0;
    v1[9] = 0;
  }
  v6 = (volatile signed __int32 *)(v1[6] - 4);
  if ( _InterlockedDecrement(v6 + 3) <= 0 )
    (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v6 + 4))(v6);
  v7 = (volatile signed __int32 *)(v1[5] - 4);
  result = v7 + 3;
  if ( _InterlockedDecrement(v7 + 3) <= 0 )
    result = (volatile signed __int32 *)(*(int (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v7 + 4))(v7);
  *v1 = (void (__stdcall ****)(signed int))&CTreeListData::`vftable';
  return result;
}
// CA414C: using guessed type void *CTreeListData::`vftable';
// CAC910: using guessed type void *Appdomain::`vftable';

//----- (00C1D4B0) --------------------------------------------------------
volatile signed __int32 *__thiscall Assembly::~Assembly(Assembly *this)
{
  Assembly *v1; // esi
  volatile signed __int32 *v2; // ebx
  volatile signed __int32 *v3; // edx
  volatile signed __int32 *v4; // edx
  volatile signed __int32 *v5; // edx
  volatile signed __int32 *result; // eax

  v1 = this;
  v2 = (volatile signed __int32 *)(*((_DWORD *)this + 6) - 16);
  if ( _InterlockedDecrement(v2 + 3) <= 0 )
    (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v2 + 4))(v2);
  v3 = (volatile signed __int32 *)(*((_DWORD *)v1 + 5) - 16);
  if ( _InterlockedDecrement(v3 + 3) <= 0 )
    (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v3 + 4))(v3);
  v4 = (volatile signed __int32 *)(*((_DWORD *)v1 + 4) - 16);
  if ( _InterlockedDecrement(v4 + 3) <= 0 )
    (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v4 + 4))(v4);
  v5 = (volatile signed __int32 *)(*((_DWORD *)v1 + 1) - 16);
  result = v5 + 3;
  if ( _InterlockedDecrement(v5 + 3) <= 0 )
    result = (volatile signed __int32 *)(*(int (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v5 + 4))(v5);
  *(_DWORD *)v1 = &CTreeListData::`vftable';
  return result;
}
// CA414C: using guessed type void *CTreeListData::`vftable';

//----- (00C1D530) --------------------------------------------------------
HTHEME __thiscall CResizer::~CResizer(CResizer *this)
{
  CResizer *v1; // esi
  WNDPROC v2; // ST04_4
  LPRESIZERITEM v3; // ST08_4
  HTHEME result; // eax

  v1 = this;
  v2 = this->m_OldWndProc;
  this->baseclass.vtptr = (CThemedWindowVTable *)&CResizer::`vftable';
  if ( (LRESULT (__stdcall *)(HWND, UINT, WPARAM, LPARAM))GetWindowLongW((HWND)v2, GWLP_WNDPROC) == CResizer::Proxy_WndProc )
    SetWindowLongW((HWND)v1->m_OldWndProc, GWLP_WNDPROC, (LONG)v1->m_hWnd);
  v3 = v1->m_pItem;
  v1->m_OldWndProc = 0;
  free(v3);
  result = v1->baseclass.m_hThemeHandle;
  v1->m_pItem = 0;
  v1->m_dwItemCount = 0;
  v1->baseclass.vtptr = (CThemedWindowVTable *)&CThemedWindow::`vftable';
  if ( result )
    result = (HTHEME)gpfnCloseThemeData(result);
  return result;
}
// CA4130: using guessed type void *CThemedWindow::`vftable';
// CAC888: using guessed type void *CResizer::`vftable';

//----- (00C1D590) --------------------------------------------------------
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
  *this = (void (__stdcall ****)(signed int))&Process::`vftable';
  v2 = this[3];
  v3 = 0;
  v4 = (unsigned int)((char *)this[4] - (char *)v2 + 3) >> 2;
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
    operator delete(v1[3]);
    v1[3] = 0;
    v1[4] = 0;
    v1[5] = 0;
  }
  v6 = (volatile signed __int32 *)(v1[2] - 4);
  result = v6 + 3;
  if ( _InterlockedDecrement(v6 + 3) <= 0 )
    result = (volatile signed __int32 *)(*(int (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v6 + 4))(v6);
  *v1 = (void (__stdcall ****)(signed int))&CTreeListData::`vftable';
  return result;
}
// CA414C: using guessed type void *CTreeListData::`vftable';
// CAC8D0: using guessed type void *Process::`vftable';

//----- (00C1D670) --------------------------------------------------------
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
  *this = (void (__stdcall ****)(signed int))&Runtime::`vftable';
  v2 = this[8];
  v3 = 0;
  v4 = (unsigned int)((char *)this[9] - (char *)v2 + 3) >> 2;
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
  v8 = (unsigned int)((char *)v1[12] - (char *)v6 + 3) >> 2;
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
    operator delete(v1[11]);
    v1[11] = 0;
    v1[12] = 0;
    v1[13] = 0;
  }
  if ( v1[8] )
  {
    operator delete(v1[8]);
    v1[8] = 0;
    v1[9] = 0;
    v1[10] = 0;
  }
  v10 = (volatile signed __int32 *)(v1[6] - 4);
  if ( _InterlockedDecrement(v10 + 3) <= 0 )
    (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v10 + 4))(v10);
  v11 = (volatile signed __int32 *)(v1[4] - 4);
  if ( _InterlockedDecrement(v11 + 3) <= 0 )
    (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v11 + 4))(v11);
  v12 = (volatile signed __int32 *)(v1[3] - 4);
  if ( _InterlockedDecrement(v12 + 3) <= 0 )
    (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v12 + 4))(v12);
  v13 = (volatile signed __int32 *)(v1[2] - 4);
  if ( _InterlockedDecrement(v13 + 3) <= 0 )
    (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v13 + 4))(v13);
  v14 = (volatile signed __int32 *)(v1[1] - 4);
  result = v14 + 3;
  if ( _InterlockedDecrement(v14 + 3) <= 0 )
    result = (volatile signed __int32 *)(*(int (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v14 + 4))(v14);
  *v1 = (void (__stdcall ****)(signed int))&CTreeListData::`vftable';
  return result;
}
// CA414C: using guessed type void *CTreeListData::`vftable';
// CAC8F0: using guessed type void *Runtime::`vftable';

//----- (00C1D840) --------------------------------------------------------
CString *__thiscall sub_C1D840(CString *this, void **a2)
{
  CString *v2; // esi
  volatile signed __int32 *v3; // edi
  CStringData *v4; // edx
  CStringData *v5; // eax
  CStringData *v7; // [esp+10h] [ebp+8h]

  v2 = this;
  v3 = (volatile signed __int32 *)(this->pszData - 16);
  v4 = (CStringData *)((char *)*a2 - 16);
  if ( v4 == (CStringData *)v3 )
    return v2;
  if ( *((_DWORD *)v3 + 3) < 0 || v4->pStringMgr != (IAtlStringMgr *)*v3 )
  {
    ATL::CSimpleStringT<wchar_t,0>::SetString(this, *a2, *((_DWORD *)*a2 - 3));
    return v2;
  }
  v5 = sub_C1B970(v4);
  v7 = v5;
  if ( _InterlockedDecrement(v3 + 3) <= 0 )
  {
    (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v3 + 4))(v3);
    v5 = v7;
  }
  v2->pszData = (CHAR *)&v5[1];
  return v2;
}

//----- (00C1D8B0) --------------------------------------------------------
void *__thiscall AppDomain::`vector deleting destructor'(void *this, char a2)
{
  void *v2; // esi

  v2 = this;
  AppDomain::~AppDomain((void (__stdcall *****)(signed int))this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (00C1D8E0) --------------------------------------------------------
void *__thiscall Assembly::`scalar deleting destructor'(void *this, char a2)
{
  void *v2; // esi

  v2 = this;
  Assembly::~Assembly((Assembly *)this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (00C1D910) --------------------------------------------------------
void *__thiscall Process::`scalar deleting destructor'(void *this, char a2)
{
  void *v2; // esi

  v2 = this;
  Process::~Process((void (__stdcall *****)(signed int))this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (00C1D940) --------------------------------------------------------
void *__thiscall Runtime::`scalar deleting destructor'(void *this, char a2)
{
  void *v2; // esi

  v2 = this;
  Runtime::~Runtime((void (__stdcall *****)(signed int))this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (00C1D970) --------------------------------------------------------
int __thiscall sub_C1D970(_DWORD *this, CTreeList *thisIn)
{
  int v2; // edx
  CListViewData **v3; // eax
  CTreeList *v4; // edi
  CListViewData *v5; // ebx
  tagTreeViewChildItem *v6; // esi
  unsigned int v7; // esi
  CListViewData **v8; // edi
  int v9; // eax
  CTreeList *v10; // ecx
  int v11; // ebx
  unsigned int v12; // eax
  unsigned int v13; // esi
  CListViewData **v14; // eax
  CListViewData *v15; // edi
  tagTreeViewChildItem *v16; // eax
  tagTreeViewChildItem *v17; // ebx
  unsigned int v18; // esi
  CListViewData **v19; // edi
  int v20; // eax
  CTreeList *v21; // ecx
  int v22; // ebx
  unsigned int v23; // eax
  unsigned int v24; // esi
  _DWORD *v26; // [esp+0h] [ebp-20h]
  CListViewData *v27; // [esp+4h] [ebp-1Ch]
  CTreeList *v28; // [esp+8h] [ebp-18h]
  int v29; // [esp+Ch] [ebp-14h]
  CTreeList *v30; // [esp+10h] [ebp-10h]
  CListViewData **v31; // [esp+14h] [ebp-Ch]
  CListViewData **v32; // [esp+18h] [ebp-8h]
  tagTreeViewChildItem *wParam; // [esp+1Ch] [ebp-4h]

  v26 = this;
  v2 = this[6];
  v3 = *(CListViewData ***)(v2 + 12);
  v31 = v3;
  if ( v3 != *(CListViewData ***)(v2 + 16) )
  {
    v4 = thisIn;
    while ( 1 )
    {
      v27 = *v3;
      v5 = *v3;
      v6 = CTreeList::_InsertItem(v4, 0, *v3, 0, 0);
      wParam = v6;
      CTreeList::OnMsg2001(v4, v6, 1);
      if ( LOWORD(v5[2].m_TreeItem) == -3 )
        break;
      v14 = (CListViewData **)v5[4].vtptr;
      v32 = v14;
      if ( v14 != (CListViewData **)v5[4].m_TreeItem )
      {
        do
        {
          v15 = *v14;
          v16 = CTreeList::_InsertItem(thisIn, (int)v6, *v14, 0, 0);
          v17 = v16;
          v29 = (int)v16;
          CTreeList::OnMsg2001(thisIn, v16, 1);
          sub_C1CC30(
            v15[3].m_TreeItem,
            v15[4].vtptr,
            (signed int)(v15[4].vtptr - (unsigned int)v15[3].m_TreeItem) >> 2,
            (int)sub_C1E7A0);
          v18 = v15[4].vtptr;
          v19 = (CListViewData **)v15[3].m_TreeItem;
          v20 = sub_C0CA50(v17);
          v21 = (CTreeList *)v20;
          v28 = (CTreeList *)v20;
          v22 = 0;
          v23 = (v18 - (unsigned int)v19 + 3) >> 2;
          if ( (unsigned int)v19 > v18 )
            v23 = 0;
          if ( v23 )
          {
            v24 = v23;
            do
            {
              CTreeList::_InsertItem(v21, v29, *v19, 0, 0);
              v21 = v28;
              ++v19;
              ++v22;
            }
            while ( v22 != v24 );
          }
          v14 = v32 + 1;
          v6 = wParam;
          v32 = v14;
        }
        while ( v14 != (CListViewData **)v27[4].m_TreeItem );
        goto LABEL_17;
      }
LABEL_18:
      v3 = v31 + 1;
      v31 = v3;
      if ( v3 == *(CListViewData ***)(v26[6] + 16) )
        return 0;
    }
    sub_C1CC30(
      v5[5].m_TreeItem,
      v5[6].vtptr,
      (signed int)(v5[6].vtptr - (unsigned int)v5[5].m_TreeItem) >> 2,
      (int)sub_C1E7A0);
    v7 = v5[6].vtptr;
    v8 = (CListViewData **)v5[5].m_TreeItem;
    v9 = sub_C0CA50(wParam);
    v10 = (CTreeList *)v9;
    v30 = (CTreeList *)v9;
    v11 = 0;
    v12 = (v7 - (unsigned int)v8 + 3) >> 2;
    if ( (unsigned int)v8 > v7 )
      v12 = 0;
    if ( v12 )
    {
      v13 = v12;
      do
      {
        CTreeList::_InsertItem(v10, (int)wParam, *v8, 0, 0);
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

//----- (00C1DB10) --------------------------------------------------------
int __cdecl sub_C1DB10(wchar_t *Dst, rsize_t SizeInWords, int a3)
{
  return sub_C1E970(Dst, SizeInWords, (unsigned __int16)a3, (int)&unk_CCD0F8, 3);
}

//----- (00C1DB40) --------------------------------------------------------
CHAR *__thiscall sub_C1DB40(CString *this, wchar_t *Src)
{
  CHAR *result; // eax

  if ( Src )
    result = sub_C1DB80(this, Src, wcslen(Src));
  else
    result = sub_C1DB80(this, 0, 0);
  return result;
}

//----- (00C1DB80) --------------------------------------------------------
CHAR *__thiscall sub_C1DB80(CString *this, wchar_t *Src, size_t MaxCount)
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
  v4 = ((char *)Src - this->pszData) >> 1;
  v5 = *((_DWORD *)this->pszData - 3);
  v10 = *((_DWORD *)this->pszData - 3);
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
  if ( (signed int)(0x7FFFFFFF - v6) < v5 )
    ATL::AtlThrowImpl(-2147024809);
  v7 = v6 + v5;
  if ( v7 < 0 )
    ATL::AtlThrowImpl(-2147024809);
  if ( ((*((_DWORD *)v3->pszData - 2) - v7) | (1 - *((_DWORD *)v3->pszData - 1))) < 0 )
  {
    ATL::CSimpleStringT<wchar_t,0>::PrepareWrite2(v3, v7);
    v6 = MaxCounta;
  }
  v8 = (wchar_t *)&v3->pszData[2 * v4];
  if ( v4 > v10 )
    v8 = Src;
  memcpy_s(&v3->pszData[2 * v10], 2 * v6, v8, 2 * v6);
  if ( v7 > *((_DWORD *)v3->pszData - 2) )
LABEL_18:
    ATL::AtlThrowImpl(-2147024809);
  *((_DWORD *)v3->pszData - 3) = v7;
  result = v3->pszData;
  *(_WORD *)&v3->pszData[2 * v7] = 0;
  return result;
}

//----- (00C1DC50) --------------------------------------------------------
int __cdecl sub_C1DC50(wchar_t *Dst, rsize_t SizeInWords, int a3)
{
  return sub_C1E970(Dst, SizeInWords, (unsigned __int16)a3, (int)&unk_CCD110, 4);
}

//----- (00C1DC80) --------------------------------------------------------
int __thiscall CResizer::InitWnd(CResizer *hData, HWND hWnd)
{
  CResizer *v2; // edi
  WNDPROC v3; // esi
  int v4; // eax
  int result; // eax
  struct tagRECT Rect; // [esp+8h] [ebp-14h]

  v2 = hData;
  hData->m_OldWndProc = (WNDPROC)hWnd;
  SetPropW(hWnd, L"ResizerClass", hData);
  v2->m_hWnd = (HWND)GetWindowLongW(hWnd, GWLP_WNDPROC);
  SetWindowLongW(hWnd, GWLP_WNDPROC, (LONG)CResizer::Proxy_WndProc);
  v3 = v2->m_OldWndProc;
  if ( v2->baseclass.m_hThemeHandle )
    gpfnCloseThemeData(v2->baseclass.m_hThemeHandle);
  v2->baseclass.m_hThemeHandle = 0;
  if ( gpfnIsThemeActive && gpfnIsThemeActive() )
  {
    v4 = ((int (__thiscall *)(CResizer *))v2->baseclass.vtptr->GetName)(v2);
    v2->baseclass.m_hThemeHandle = (HTHEME)gpfnOpenThemeData(v3, v4);
  }
  GetWindowRect((HWND)v2->m_OldWndProc, &Rect);
  v2->m_ptMinTrackSize.x = Rect.right - Rect.left;
  v2->m_ptMinTrackSize.y = Rect.bottom - Rect.top;
  v2->m_nWidth = v2->m_ptMinTrackSize.x;
  result = v2->m_ptMinTrackSize.y;
  v2->m_nHeight = result;
  return result;
}
// CD4D84: using guessed type int (__stdcall *gpfnIsThemeActive)();

//----- (00C1DD40) --------------------------------------------------------
ULONG __userpurge sub_C1DD40@<eax>(int a1@<ecx>, int a2@<edi>, int a3@<esi>, int a4, int a5)
{
  void *v5; // eax
  void *v6; // ebx
  ULONG v8; // esi
  char *v9; // [esp+0h] [ebp-20h]
  ULONG64 TraceHandle; // [esp+4h] [ebp-1Ch]
  int v11; // [esp+Ch] [ebp-14h]
  __int64 v12; // [esp+10h] [ebp-10h]
  int v13; // [esp+18h] [ebp-8h]

  *(_DWORD *)(a1 + 12) = a5;
  v9 = (char *)a1;
  TraceHandle = 0i64;
  v11 = 0;
  v12 = 0i64;
  v13 = 0;
  if ( a5 )
    sub_C20200(L"A669021C-C450-4609-A035-5AF59AF4DF18", (int)&v11);
  else
    sub_C20200(L"E13C0D23-CCBC-4E12-931B-D9CC2EEE27E4", (int)&v11);
  v5 = malloc(0x1078u);
  v6 = v5;
  if ( !v5 )
    return 14;
  memset(v5, 0, 0x1078u);
  *(_DWORD *)v6 = 4216;
  *((_DWORD *)v6 + 11) = 0x20000;
  *((_DWORD *)v6 + 16) = 16777472;
  *((_DWORD *)v6 + 28) = 120;
  *((_DWORD *)v6 + 27) = 2168;
  wcscpy_s((wchar_t *)v6 + 60, 0x400u, L"ProcExpLogger");
  StartTraceW(&TraceHandle, (LPCWSTR)v6 + 60, (PEVENT_TRACE_PROPERTIES)v6);
  ControlTraceW(0i64, (LPCWSTR)v6 + 60, (PEVENT_TRACE_PROPERTIES)v6, 0);
  TraceHandle = *((_QWORD *)v6 + 1);
  EnableTraceEx(&v11, 0, TraceHandle, HIDWORD(TraceHandle), 1, 4, 72, 0, 0, 0, 0, 0, a2, a3);
  sub_C1F840(v9, (WCHAR *)v6 + 60);
  TraceHandle = 0i64;
  v8 = ControlTraceW(0i64, (LPCWSTR)v6 + 60, (PEVENT_TRACE_PROPERTIES)v6, 1u);
  free(v6);
  return v8;
}
// C1DD40: could not find valid save-restore pair for edi
// C1DD40: could not find valid save-restore pair for esi
// CAC960: using guessed type wchar_t aE13c0d23Ccbc4e[37];

//----- (00C1DE80) --------------------------------------------------------
int __userpurge sub_C1DE80@<eax>(int a1@<edi>, int *a2)
{
  a2[2] = sub_C1DD40(*a2, a1, (int)a2, *(_DWORD *)*a2, a2[1]);
  return 0;
}

//----- (00C1DEA0) --------------------------------------------------------
signed int __thiscall sub_C1DEA0(void *this, int a2, DWORD ThreadId)
{
  void *v3; // esi
  signed int result; // eax
  int v5; // [esp+4h] [ebp-Ch]
  DWORD v6; // [esp+8h] [ebp-8h]
  int v7; // [esp+Ch] [ebp-4h]

  v6 = ThreadId;
  v5 = (int)this;
  v3 = (void *)_beginthreadex(0, 0, (int)sub_C1DE80, (int)&v5, 0, &ThreadId);
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

//----- (00C1DF10) --------------------------------------------------------
int __thiscall sub_C1DF10(int this)
{
  int v1; // edi
  void (__stdcall ***v2)(signed int); // ecx
  signed int v3; // ebx
  int v4; // esi
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
  int rc; // [esp+24h] [ebp-54h]
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
  v2 = *(void (__stdcall ****)(signed int))(this + 24);
  v3 = 0;
  if ( v2 )
  {
    (**v2)(1);
    *(_DWORD *)(v1 + 24) = 0;
  }
  v4 = (int)operator new(0x18u);
  pTreeList = (CTreeList *)v4;
  v36 = 0;
  if ( v4 )
  {
    v5 = *(_DWORD *)v1;
    LOBYTE(v36) = 1;
    *(_DWORD *)v4 = &Process::`vftable';
    *(_DWORD *)(v4 + 4) = v5;
    v6 = ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>::GetDefaultManager();
    if ( v6 == 0 )
      ATL::AtlThrowImpl(E_FAIL);
    *(_DWORD *)(v4 + 8) = ((int (*)(void))v6->vtptr->GetNilData)() + 16;
    *(_DWORD *)(v4 + 12) = 0;
    *(_DWORD *)(v4 + 16) = 0;
    *(_DWORD *)(v4 + 20) = 0;
  }
  else
  {
    v4 = 0;
  }
  v7 = _mm_load_si128((const __m128i *)&xmmword_CACB40);
  v36 = -1;
  *(_DWORD *)(v1 + 24) = v4;
  _mm_storeu_si128((__m128i *)&rc, v7);
  v8 = GetModuleHandleW(0);
  v9 = v8;
  v10 = CTreeList::Init(*(HWND *)(v1 + 8), v8, 0, 0x50810000, (#153 *)&rc);
  *(_DWORD *)(v1 + 4) = v10;
  pTreeList = CTreeList::GetTreeList(v10);
  CTreeList::UpdateSB(pTreeList, 0);
  v11 = LoadCursorW(v9, (LPCWSTR)0x6A);
  CTreeList::SetSplitterCursor(pTreeList, v11);
  sub_C0BDA0(pTreeList, 1);
  GetClientRect(*(HWND *)(v1 + 8), &Rect);
  CopyRect(&rcDst, &Rect);
  v12 = rcDst.right - 10;
  rcDst.bottom -= 10;
  rcDst.right = v12;
  v13 = rcDst.bottom - (rcDst.top + 10);
  v14 = v12 - (rcDst.left + 10);
  rcDst.left += 10;
  v15 = *(HWND *)(v1 + 4);
  rcDst.top += 10;
  MoveWindow(v15, rcDst.left, rcDst.top, v14, v13, 1);
  v16 = 800;
  pTreeList_1 = pTreeList;
  if ( rcDst.right - rcDst.left > 800 )
    v16 = rcDst.right - rcDst.left;
  a2 = (int)L"Structure";
  v34 = v16;
  v28 = 200;
  v29 = 0;
  v30 = L"Flags";
  v31 = 80;
  v32 = 0;
  v33 = L"Path";
  v35 = 0;
  sub_C0D310(pTreeList, (int)&a2, 3);
  if ( !ProcessIsNetCclr(*(_DWORD *)v1, (PDWORD)&pTreeList) )
  {
    v18 = (char)pTreeList;
    if ( (unsigned __int8)pTreeList & 1 )
    {
      v19 = sub_C1EBA0(*(_DWORD **)(v1 + 24), *(_DWORD *)v1, (Runtime *)0xFFFF);
      ATL::CSimpleStringT<wchar_t,0>::SetString((CString *)v19 + 6, L"v1.0.3705", 9);
      v18 = (char)pTreeList;
    }
    if ( v18 & 2 )
    {
      v20 = sub_C1EBA0(*(_DWORD **)(v1 + 24), *(_DWORD *)v1, (Runtime *)0xFFFE);
      ATL::CSimpleStringT<wchar_t,0>::SetString((CString *)v20 + 6, L"v1.1.4322", 9);
      v18 = (char)pTreeList;
    }
    if ( v18 & 4 )
    {
      v21 = sub_C1EBA0(*(_DWORD **)(v1 + 24), *(_DWORD *)v1, (Runtime *)0xFFFD);
      ATL::CSimpleStringT<wchar_t,0>::SetString((CString *)v21 + 6, L"v2.0.50727", 10);
      v3 = sub_C1DEA0((void *)v1, *(_DWORD *)v1, 0);
      if ( v3 )
        return v3;
      v18 = (char)pTreeList;
    }
    if ( !(v18 & 8) || (v3 = sub_C1DEA0((void *)v1, *(_DWORD *)v1, 1u)) == 0 )
      sub_C1D970((_DWORD *)v1, pTreeList_1);
  }
  return v3;
}
// CAC8D0: using guessed type void *Process::`vftable';
// CACA34: using guessed type wchar_t aStructure[10];
// CACA48: using guessed type wchar_t aV103705[10];
// CACA5C: using guessed type wchar_t aV114322[10];
// CACA70: using guessed type wchar_t aV2050727[11];
// CACB40: using guessed type __int128 xmmword_CACB40;

//----- (00C1E1A0) --------------------------------------------------------
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
  _DWORD *v30; // ebx
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
  if ( (unsigned int)a2 > 0x4E )
  {
    if ( a2 == 272 )
    {
      v25 = hDlg;
      v26 = GetParent(hDlg);
      v27 = GetWindowLongW(v26, -21);
      v28 = (CResizer *)operator new(0x40u);
      Point.y = (LONG)v28;
      v49 = 0;
      if ( v28 )
        CResizer::CResizer(v28, v25);
      v49 = -1;
      PropSheet_UpdateTab(v25);
      if ( IsBuiltinAdministrative() && (unsigned __int8)GetVersion() >= 6u )
      {
        v29 = operator new(sizeof(BITMAPINFOHEADER));
        if ( v29 )
          v30 = sub_C1D260(v29);
        else
          v30 = 0;
        v30[2] = v25;
        *v30 = *(_DWORD *)(*(_DWORD *)(v27 + 4) + 68);
        v31 = LoadCursorW(0, (LPCWSTR)0x7F02);
        v32 = SetCursor(v31);
        sub_C1DF10((int)v30);
        SendMessageW((HWND)v30[1], 0x30u, (WPARAM)ghConfigFont, 0);
        SetCursor(v32);
        v25 = hDlg;
      }
      else
      {
        v30 = 0;
      }
      v33 = GetDlgItem(v25, 1610);
      ShowWindow(v33, v30 == 0);
      SetWindowLongW(v25, -21, (LONG)v30);
      return 1;
    }
    if ( a2 == 273 )
    {
      switch ( (unsigned __int16)a3 )
      {
        case IDM_FILE_EXIT:
          v34 = 40014;
          goto LABEL_35;
        case IDM_VIEW_REFRESH_NOW:
          SetEvent(ghRefreshEventHandle);
          return 0;
        case IDC_DLG_RUNDLG_BUTTON_BROWSE|IDC_FILE_STANDBY|IDS_REFRESH_PROCESS_LIST:
        case IDC_DLG_RUNDLG_BUTTON_BROWSE|IDC_FILE_STANDBY|IDS_REFRESH_PROCESS_LIST|0x1:
          v34 = a3;
LABEL_35:
          v24 = GetParent(hDlg);
          PostMessageW(v24, WM_COMMAND, v34, 0);
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
        if ( *(_DWORD *)(v4 + 28) )
        {
          operator delete(*(void **)(v4 + 28));
          *(_DWORD *)(v4 + 28) = 0;
          *(_DWORD *)(v4 + 32) = 0;
          *(_DWORD *)(v4 + 36) = 0;
        }
        operator delete((void *)v4);
      }
      return 1;
    }
    if ( a2 == 5 )
    {
      if ( v4 )
        sub_C20130((HWND *)v4);
      return 1;
    }
    return 0;
  }
  v5 = *(_DWORD *)(a4 + 8);
  if ( v5 != 2004 )
  {
    if ( v5 == 2005 )
    {
      if ( !*(_DWORD *)(a4 + 20) )
      {
        GetCursorPos(&Point);
        Point.y += 20;
        v19 = *(HWND *)a4;
        Point.x += 10;
        SetWindowPos(v19, 0, Point.x, Point.y, 0, 0, 0x15u);
        return 0;
      }
    }
    else if ( v5 == -155 && *(_WORD *)(a4 + 12) == 67 )
    {
      if ( GetKeyState(162) )
      {
        v6 = 0;
        v7 = 0;
        v8 = *(HWND *)(v4 + 4);
        v41 = 0;
        v9 = SendMessageW(v8, 0x100Cu, wParam, 2);
        v43 = v9;
        if ( v9 != -1 )
        {
          do
          {
            v37 = 0;
            v38 = &Src;
            v10 = *(HWND *)(v4 + 4);
            v39 = 260;
            SendMessageW(v10, 0x1073u, v9, (LPARAM)&lParam);
            v37 = 1;
            v38 = &v45;
            v39 = 0x2000;
            SendMessageW(*(HWND *)(v4 + 4), 0x1073u, v43, (LPARAM)&lParam);
            v37 = 2;
            v38 = &v46;
            v39 = 0x2000;
            SendMessageW(*(HWND *)(v4 + 4), 0x1073u, v43, (LPARAM)&lParam);
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
            v15 = v11 + (((char *)v13 - (char *)v40) >> 1) + v12 + v41 + 5;
            v41 += v11 + (((char *)v13 - (char *)v40) >> 1) + v12 + 5;
            if ( v7 )
            {
              v6 = GlobalReAlloc(v6, 2 * v15 + 2, 0);
              v7 = (wchar_t *)GlobalLock(v6);
            }
            else
            {
              v6 = GlobalAlloc(0x2002u, 2 * v15 + 2);
              v7 = (wchar_t *)GlobalLock(v6);
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
            v9 = SendMessageW(*(HWND *)(Point.y + 4), 0x100Cu, v43, 2);
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
  if ( *(_DWORD *)(a4 + 20) || !v4 )
    return 0;
  v20 = CTreeList::GetTreeList(*(HWND *)(v4 + 4));
  CTreeList::GetTooltipOfTreeList(v20);
  v21 = sub_C0C420(*(_DWORD **)(a4 + 16));
  v22 = (*(int (__thiscall **)(int))(*(_DWORD *)v21 + 24))(v21);
  v23 = hDlg;
  **(_DWORD **)(a4 + 24) = v22;
  SetWindowLongW(v23, 0, 1);
  return 1;
}

//----- (00C1E780) --------------------------------------------------------
BOOL __cdecl sub_C1E780(int a1, int a2)
{
  return *(_DWORD *)(a1 + 16) < *(_DWORD *)(a2 + 16);
}

//----- (00C1E7A0) --------------------------------------------------------
bool __cdecl sub_C1E7A0(int a1, int a2)
{
  return _wcsnicmp(*(const wchar_t **)(a1 + 4), *(const wchar_t **)(a2 + 4), 0x400u) < 0;
}

//----- (00C1E7D0) --------------------------------------------------------
LRESULT __thiscall CResizer::HandleMessage(WNDPROC *this, HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
  return CallWindowProcW(this[2], hWnd, Msg, wParam, lParam);
}

//----- (00C1E7F0) --------------------------------------------------------
int __stdcall sub_C1E7F0(int a1)
{
  return sub_C1F0A0(*(_DWORD **)(a1 + 96), a1);
}

//----- (00C1E810) --------------------------------------------------------
int __thiscall sub_C1E810(_DWORD *this, int a2, int a3)
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
    v5 = *(int **)(*(_DWORD *)v4 + 32);
    v6 = *(int **)(*(_DWORD *)v4 + 28);
    if ( v6 != v5 )
    {
      do
      {
        if ( sub_C1F710(*v6, a2, a3) )
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

//----- (00C1E870) --------------------------------------------------------
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
    if ( (_BYTE)a3 )
    {
      this_1->m_dwItemCount = dwItemCount + 1;
      pNewItem = (struct tagResizerItem *)realloc(this_1->m_pItem, sizeof(tagResizerItem) * (dwItemCount + 1));
      if ( !pNewItem )
      {
        a3 = 8;
        _CxxThrowException(&a3, &_TI1J);
      }
      dwItemCount_1 = this_1->m_dwItemCount;
      this_1->m_pItem = pNewItem;
      pNewItem_1 = &pNewItem[dwItemCount_1];
      pNewItem_1[-1].m_hWnd = hWndEdit;
      *(_OWORD *)pNewItem_1[-1].gap0 = xmmword_CACB50;
      *(_OWORD *)&pNewItem_1[-1].gap0[16] = xmmword_CACB50;
      GetWindowRect(hWndEdit, (LPRECT)&pNewItem_1[-1].gap0[32]);
      ScreenToClient((HWND)this_2->m_OldWndProc, (LPPOINT)&pNewItem_1[-1].gap0[32]);
      ScreenToClient((HWND)this_2->m_OldWndProc, (LPPOINT)&pNewItem_1[-1].gap0[40]);
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
// C781AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);
// CACB50: using guessed type __int128 xmmword_CACB50;
// CC4A54: using guessed type int _TI1J;

//----- (00C1E970) --------------------------------------------------------
int __cdecl sub_C1E970(wchar_t *Dst, rsize_t SizeInWords, int a3, int a4, int a5)
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
    result = (unsigned __int16)a5;
    v7 = 0;
    if ( (signed int)(unsigned __int16)a5 > 0 )
    {
      result = a4;
      v8 = (unsigned __int16)a5;
      do
      {
        if ( a3 & *(_DWORD *)(result + 8 * v7) )
        {
          if ( !v6 )
          {
            wcscat_s(Dst, SizeInWords, L", ");
            result = a4;
          }
          wcscat_s(Dst, SizeInWords, *(const wchar_t **)(result + 8 * v7 + 4));
          result = a4;
          v8 = (unsigned __int16)a5;
          v6 = 0;
        }
        ++v7;
      }
      while ( v7 < v8 );
    }
  }
  return result;
}

//----- (00C1E9F0) --------------------------------------------------------
__int16 __thiscall sub_C1E9F0(_WORD *this)
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

//----- (00C1EA10) --------------------------------------------------------
__int16 __thiscall sub_C1EA10(_WORD *this)
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

//----- (00C1EA30) --------------------------------------------------------
__int16 __thiscall sub_C1EA30(_WORD *this)
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

//----- (00C1EA70) --------------------------------------------------------
HWND __thiscall CTreeList::GetTooltipOfLeftHeader(CTreeList *this)
{
  return this->m_hWndTooltipOfLeftHeader;
}

//----- (00C1EA80) --------------------------------------------------------
const WCHAR **sub_C1EA80()
{
  return &gszNullString;
}

//----- (00C1EA90) --------------------------------------------------------
int __thiscall sub_C1EA90(_WORD *this)
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
  return *(_DWORD *)(v1 + 1);
}

//----- (00C1EAB0) --------------------------------------------------------
_WORD *__thiscall sub_C1EAB0(_WORD *this)
{
  _WORD *i; // eax

  for ( i = this + 12; *i; ++i )
    ;
  return i + 1;
}

//----- (00C1EAD0) --------------------------------------------------------
AppDomain *__thiscall sub_C1EAD0(_DWORD *this, int a2, AppDomain *a3)
{
  int *v3; // esi
  int *v4; // edi
  AppDomain *v5; // ebx
  AppDomain *v7; // eax
  AppDomain *v8; // eax
  std__vector *v9; // [esp+14h] [ebp-10h]

  v3 = (int *)this[9];
  v4 = (int *)this[8];
  v5 = a3;
  v9 = (std__vector *)(this + 8);
  if ( v4 != v3 )
  {
    do
    {
      if ( sub_C1F710(*v4, a2, (int)v5) )
        break;
      ++v4;
    }
    while ( v4 != v3 );
    if ( v4 != v3 )
      return (AppDomain *)*v4;
  }
  v7 = (AppDomain *)operator new(0x28u);
  if ( v7 )
    v8 = AppDomain::AppDomain(v7, a2, (int)v5);
  else
    v8 = 0;
  a3 = v8;
  std::vector<tagAccountInfo *,std::allocator<tagAccountInfo *>>::push_back(v9, (tagAccountInfo *)&a3);
  return a3;
}

//----- (00C1EBA0) --------------------------------------------------------
Runtime *__thiscall sub_C1EBA0(_DWORD *this, unsigned int a2, Runtime *a3)
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

  v3 = (std__vector *)(this + 3);
  v4 = (int *)this[4];
  v5 = (int *)this[3];
  v9 = a2;
  v10 = (signed __int16)a3;
  if ( v5 != v4 )
  {
    do
    {
      if ( sub_C1F730(*v5, (int)&v9) )
        break;
      ++v5;
    }
    while ( v5 != v4 );
    if ( v5 != v4 )
      return (Runtime *)*v5;
  }
  v7 = operator new(0x38u);
  v11 = v7;
  v12 = 0;
  if ( v7 )
    v8 = Runtime::Runtime((Runtime *)v7, a2, (unsigned __int16)a3);
  else
    v8 = 0;
  a3 = v8;
  v12 = -1;
  std::vector<tagAccountInfo *,std::allocator<tagAccountInfo *>>::push_back(v3, (tagAccountInfo *)&a3);
  return a3;
}

//----- (00C1EC70) --------------------------------------------------------
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
  while ( hFound == (HANDLE)ERROR_BAD_LENGTH );
  if ( hFound == (HANDLE)INVALID_HANDLE_VALUE )
    return 0;
  ModuleEntry.dwSize = sizeof(MODULEENTRY32W);
  if ( !Module32FirstW(hFound, &ModuleEntry) )
  {
    CloseHandle(FoundHandle);
    result = GetLastError();
    if ( result > 0 )
      result = (unsigned __int16)result | 0x80070000;
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
          pszText = (int)(pszFileName_1 + 1);
          v10 = (__int16 *)(pszFileName_1 + 1);
          v11 = (int)(pszFileName_1 + 2);
          do
          {
            v12 = *v10;
            ++v10;
          }
          while ( v12 );
          if ( (unsigned int)(((signed int)v10 - v11) >> 1) >= 4 )
          {
            chText = *(unsigned __int16 *)(pszText + 2);
            if ( chText != '1' )
              goto LABEL_22;
            if ( *(_WORD *)(pszText + 6) == '0' )
            {
              dwFlags |= 1u;
            }
            else
            {
              if ( *(_WORD *)(pszText + 6) != '1' )
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

//----- (00C1EE50) --------------------------------------------------------
wchar_t *__thiscall sub_C1EE50(_DWORD *this, int a2, int a3, wchar_t *Dst, int a5)
{
  wchar_t *result; // eax

  if ( a3 )
  {
    if ( a3 == 1 )
    {
      result = (wchar_t *)this[5];
    }
    else
    {
      result = Dst;
      *Dst = 0;
    }
  }
  else
  {
    swprintf_s(Dst, *(_DWORD *)a5, L"Appdomain: %s", this[6]);
    result = Dst;
  }
  return result;
}

//----- (00C1EEA0) --------------------------------------------------------
wchar_t *__thiscall sub_C1EEA0(int this, int a2, int a3, wchar_t *Dst, int a5)
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
      return *(wchar_t **)(this + 4);
    case 1:
      wcscat_s(v5, *(_DWORD *)a5, *(const wchar_t **)(this + 20));
      break;
    case 2:
      v6 = *(_DWORD *)(this + 24);
      if ( *(_DWORD *)(v6 - 12) )
      {
        v7 = sub_C1B970((CStringData *)(v6 - 16));
        v8 = (wchar_t *)&v7[1];
        Dst = (wchar_t *)&v7[1];
        if ( *(_DWORD *)a5 < v7->nDataLength + 1 )
        {
          v9 = sub_C1F790((CString *)&Dst, (void **)&a3, 0, *(_DWORD *)a5 - 4);
          sub_C1D840((CString *)&Dst, v9);
          v10 = a3 - 16;
          if ( _InterlockedDecrement((volatile signed __int32 *)(a3 - 16 + 12)) <= 0 )
            (*(void (__stdcall **)(int))(**(_DWORD **)v10 + 4))(v10);
          sub_C1DB40((CString *)&Dst, L"...");
          v8 = Dst;
        }
        wcscat_s(v5, *(_DWORD *)a5, v8);
        v11 = (volatile signed __int32 *)(v8 - 8);
        if ( _InterlockedDecrement(v11 + 3) <= 0 )
        {
          (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v11 + 4))(v11);
          return v5;
        }
      }
      break;
  }
  return v5;
}

//----- (00C1EFF0) --------------------------------------------------------
wchar_t *__thiscall sub_C1EFF0(int this, int a2, int a3, wchar_t *Dst, int a5)
{
  int v6; // eax
  wchar_t *v7; // esi
  int v8; // [esp-4h] [ebp-8h]

  if ( a3 )
  {
    if ( a3 != 1 || *(_WORD *)(this + 20) == -3 )
    {
      *Dst = 0;
      return Dst;
    }
    v6 = *(_DWORD *)(this + 8);
    v8 = *(_DWORD *)(this + 12);
    v7 = Dst;
    if ( *(_DWORD *)(v6 - 12) )
    {
      swprintf_s(Dst, *(_DWORD *)a5, L"%s, %s", v6, v8);
      return Dst;
    }
    swprintf_s(Dst, *(_DWORD *)a5, L"%s", v8);
  }
  else
  {
    v7 = Dst;
    swprintf_s(Dst, *(_DWORD *)a5, L"CLR %s", *(_DWORD *)(this + 24));
  }
  return v7;
}

//----- (00C1F070) --------------------------------------------------------
wchar_t *__stdcall sub_C1F070(int a1, int a2, wchar_t *Dst, int a4)
{
  swprintf_s(Dst, *(_DWORD *)a4, (const wchar_t *)&gszNullString);
  return Dst;
}

//----- (00C1F090) --------------------------------------------------------
const wchar_t *CResizer::GetName()
{
  return L"status";
}
// CAC890: using guessed type wchar_t aStatus[7];

//----- (00C1F0A0) --------------------------------------------------------
int __thiscall sub_C1F0A0(_DWORD *this, int a2)
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
  v3 = (_DWORD *)this[6];
  *(_DWORD *)pInfo.szUserName = v3;
  v4 = *(Runtime **)(a2 + 12);
  v5 = *(unsigned __int16 *)(a2 + 40);
  v6 = *(unsigned __int8 *)(a2 + 45);
  v59 = v4;
  if ( v4 == (Runtime *)v3[1] )
  {
    if ( this[3] )
    {
      switch ( v5 )
      {
        case 145:
          v50 = (Runtime *)**(unsigned __int16 **)(a2 + 92);
          pInfo.bIsSystemUser = **(unsigned __int16 **)(a2 + 92);
          v51 = sub_C1EBA0(v3, (unsigned int)v4, v50);
          sub_C201B0((int)v51);
          v52 = (void *)v2[8];
          sub_C1CF50(&v58, (_WORD *)v2[7], (_WORD *)v2[8], &pInfo);
          if ( v58 != v52 )
            sub_C20840(v2 + 7, (int)&pInfo, v58);
          v19 = v2[7] == v2[8];
          goto LABEL_36;
        case 153:
          v44 = *(_DWORD *)(a2 + 92);
          v45 = sub_C1EA30(*(_WORD **)(a2 + 92));
          v46 = sub_C1EBA0(*(_DWORD **)pInfo.szUserName, (unsigned int)v4, (Runtime *)v45);
          v47 = (CString *)sub_C1E810(v46, *(_DWORD *)(v44 + 8), *(_DWORD *)(v44 + 12));
          if ( !v47 )
            return 0;
          if ( *(_DWORD *)(v44 + 16) & 2 )
            v48 = sub_C1EAB0((_WORD *)v44);
          else
            v48 = (_WORD *)(v44 + 24);
          v49 = ATL::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>::Format(&v57, (UINT)v48)->pszData;
          v63 = 8;
          sub_C200E0(v47, v49);
          v14 = &v57;
          goto LABEL_32;
        case 155:
          v33 = *(_DWORD *)(a2 + 92);
          v34 = *(_DWORD *)(v33 + 8);
          v35 = *(AppDomain **)(v33 + 12);
          v58 = *(void **)v33;
          pInfo.bIsSystemUser = *(_DWORD *)(v33 + 4);
          v36 = sub_C1EA10((_WORD *)v33);
          v37 = sub_C1EBA0(*(_DWORD **)pInfo.szUserName, (unsigned int)v59, (Runtime *)v36);
          v38 = sub_C1EAD0(v37, v34, v35);
          sub_C1DC50(&Src, 0x400u, *(unsigned __int16 *)(v33 + 24));
          v39 = (CString *)operator new(0x20u);
          v56 = v39;
          v63 = 5;
          if ( v39 )
          {
            v40 = ATL::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>::Format(&v55, v33 + 28);
            LOBYTE(v63) = 6;
            v41 = v40->pszData;
            v42 = 1;
            pInfo.nMenuID = 1;
            v43 = Assembly::Assembly(v39, (int)v58, pInfo.bIsSystemUser, v41, &Src);
          }
          else
          {
            v42 = pInfo.nMenuID;
            v43 = 0;
          }
          v63 = -1;
          if ( v42 & 1 )
            ATL::CSimpleStringT<wchar_t,0>::~CSimpleStringT<wchar_t,0>(&v55);
          pInfo.bIsSystemUser = (BOOL)v43;
          std::vector<tagAccountInfo *,std::allocator<tagAccountInfo *>>::push_back(
            (std__vector *)((char *)v38 + 28),
            &pInfo);
          break;
        case 157:
          v26 = *(_DWORD *)(a2 + 92);
          v27 = *(_DWORD *)v26;
          v28 = *(AppDomain **)(v26 + 4);
          v29 = sub_C1E9F0((_WORD *)v26);
          v30 = sub_C1EBA0(*(_DWORD **)pInfo.szUserName, (unsigned int)v59, (Runtime *)v29);
          v31 = (CString *)sub_C1EAD0(v30, v27, v28);
          v31[4].pszData = (CHAR *)sub_C1EA90((_WORD *)v26);
          v32 = ATL::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>::Format(&v54, v26 + 12)->pszData;
          v63 = 4;
          sub_C200E0(v31, v32);
          v63 = -1;
          ATL::CSimpleStringT<wchar_t,0>::~CSimpleStringT<wchar_t,0>(&v54);
          sub_C1DB10(&Src, 0x400u, *(unsigned __int16 *)(v26 + 8));
          sub_C1FEB0(v31, &Src);
          break;
        case 187:
          pInfo.nMenuID = *(_DWORD *)(a2 + 92);
          v20 = (void *)*(unsigned __int16 *)pInfo.nMenuID;
          v21 = *(unsigned __int16 *)(pInfo.nMenuID + 14);
          v22 = *(unsigned __int16 *)(pInfo.nMenuID + 16);
          v23 = *(unsigned __int16 *)(pInfo.nMenuID + 18);
          pInfo.bIsSystemUser = *(unsigned __int16 *)(pInfo.nMenuID + 12);
          v56 = v20;
          v59 = sub_C1EBA0(*(_DWORD **)pInfo.szUserName, (unsigned int)v59, (Runtime *)v20);
          sub_C1FF00((CString *)v59, (void *)(pInfo.nMenuID + 25));
          sub_C20880((_DWORD *)v58 + 7, &v56);
          swprintf_s(&Dst, 0x400u, L"v%u.%u.%u.%u", pInfo.bIsSystemUser, v21, v22, v23);
          v24 = (CString *)v59;
          sub_C200E0((CString *)v59, &Dst);
          v25 = pInfo.nMenuID;
          sub_C1E970(&pInfo.szUserName[2], 0x400u, *(_DWORD *)(pInfo.nMenuID + 20), (int)&unk_CCD178, 15);
          sub_C1FF50(v24, &pInfo.szUserName[2]);
          sub_C201D0(&Src, 0x400u, *(unsigned __int8 *)(v25 + 24));
          sub_C1FFA0(v24, &Src);
          break;
        default:
          return 0;
      }
    }
    else if ( !(_WORD)v5 )
    {
      if ( v6 == 35 )
      {
        v7 = *(unsigned __int16 **)(a2 + 92);
        v8 = sub_C1EBA0(v3, (unsigned int)v4, (Runtime *)0xFFFD);
        v9 = *v7;
        v10 = v7 + 12;
        v59 = v8;
        ATL::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>::Format(
          (CString *)pInfo.szUserName,
          (UINT)(v7 + 12));
        v63 = 0;
        v11 = wcsrchr(*(const wchar_t **)pInfo.szUserName, 0x5Cu);
        if ( v11 )
        {
          v12 = ((signed int)v11 - *(_DWORD *)pInfo.szUserName) >> 1;
          if ( v12 >= 0 )
          {
            v13 = sub_C1F760(pInfo.szUserName, (void **)&pInfo.nMenuID, v12 + 1);
            LOBYTE(v63) = 1;
            sub_C1D840((CString *)pInfo.szUserName, v13);
            LOBYTE(v63) = 0;
            ATL::CSimpleStringT<wchar_t,0>::~CSimpleStringT<wchar_t,0>((CString *)&pInfo.nMenuID);
          }
        }
        v14 = (CString *)pInfo.szUserName;
        if ( *(_DWORD *)(*(_DWORD *)pInfo.szUserName - 12) )
        {
          v15 = sub_C1FE80((const wchar_t **)pInfo.szUserName, 0x2Eu);
          if ( v15 >= 0 )
          {
            v16 = sub_C1F790((CString *)pInfo.szUserName, (void **)&pInfo.nMenuID, 0, v15);
            LOBYTE(v63) = 2;
            sub_C1D840((CString *)pInfo.szUserName, v16);
            LOBYTE(v63) = 0;
            ATL::CSimpleStringT<wchar_t,0>::~CSimpleStringT<wchar_t,0>((CString *)&pInfo.nMenuID);
          }
          sub_C1E970(&Dst, 0x400u, v7[8], (int)&dword_CCD130, 4);
          v17 = (CHAR *)operator new(0x20u);
          v57.pszData = v17;
          LOBYTE(v63) = 3;
          if ( v17 )
            v18 = Assembly::Assembly((CString *)v17, v9, v9 >> 31, &gszNullString, &Dst);
          else
            v18 = 0;
          LOBYTE(v63) = 0;
          sub_C1FF00(v18, *(void **)pInfo.szUserName);
          if ( *((_DWORD *)v7 + 4) & 2 )
            v10 = sub_C1EAB0(v7);
          sub_C200E0(v18, v10);
          pInfo.nMenuID = (UINT)v18;
          std::vector<tagAccountInfo *,std::allocator<tagAccountInfo *>>::push_back(
            (std__vector *)((char *)v59 + 44),
            (tagAccountInfo *)((char *)&pInfo + 4));
          ATL::CSimpleStringT<wchar_t,0>::~CSimpleStringT<wchar_t,0>((CString *)pInfo.szUserName);
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
          CloseTrace(*((_QWORD *)v2 + 2));
      }
    }
  }
  return 0;
}
// CCD130: using guessed type int dword_CCD130;

//----- (00C1F690) --------------------------------------------------------
int __cdecl sub_C1F690(const unsigned __int16 *a1)
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

//----- (00C1F710) --------------------------------------------------------
bool __cdecl sub_C1F710(int a1, int a2, int a3)
{
  return *(_DWORD *)(a1 + 8) == a2 && *(_DWORD *)(a1 + 12) == a3;
}

//----- (00C1F730) --------------------------------------------------------
bool __cdecl sub_C1F730(int a1, int a2)
{
  return *(_DWORD *)(a1 + 28) == *(_DWORD *)a2 && *(_WORD *)(a1 + 20) == *(_WORD *)(a2 + 4);
}

//----- (00C1F760) --------------------------------------------------------
void **__thiscall sub_C1F760(_DWORD *this, void **a2, int a3)
{
  sub_C1F790((CString *)this, a2, a3, *(_DWORD *)(*this - 12) - a3);
  return a2;
}

//----- (00C1F790) --------------------------------------------------------
void **__thiscall sub_C1F790(CString *this, void **a2, int a3, int a4)
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
  v8 = *((_DWORD *)this->pszData - 3);
  if ( v6 + v4 > v8 )
    v4 = v8 - v6;
  if ( v6 > v8 )
    v4 = 0;
  if ( v6 || v4 != v8 )
  {
    v11 = (IAtlStringMgr *)*((_DWORD *)v7 - 4);
    if ( !v11 || (v12 = ((int (*)(void))v11->vtptr->Clone)()) == 0 )
    {
      v13 = ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>::GetDefaultManager();
      v12 = ((int (__thiscall *)(IAtlStringMgr *))v13->vtptr->Clone)(v13);
    }
    sub_C1CF80(a2, &v5->pszData[2 * v6], v4, v12);
    result = a2;
  }
  else
  {
    v9 = sub_C1B970((CStringData *)v7 - 1) + 1;
    result = a2;
    *a2 = v9;
  }
  return result;
}

//----- (00C1F840) --------------------------------------------------------
signed int __thiscall sub_C1F840(char *this, WCHAR *a2)
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
  v3 = (int)(v2 + 16);
  Logfile.u.LogFileMode = 268435712;
  Logfile.BufferCallback = (PEVENT_TRACE_BUFFER_CALLBACKW)LogBufferCallback;
  Logfile.u2.EventCallback = (PEVENT_CALLBACK)sub_C1E7F0;
  v4 = OpenTraceW(&Logfile);
  *(_QWORD *)v3 = v4;
  if ( v4 == 0xFFFFFFFF )
  {
    result = GetLastError();
    if ( result > 0 )
      result = (unsigned __int16)result | 0x80070000;
    *(_DWORD *)v3 = 0;
    *(_DWORD *)(v3 + 4) = 0;
  }
  else
  {
    result = ProcessTrace((PTRACEHANDLE)v3, 1u, 0, 0);
    if ( result )
    {
      result = GetLastError();
      if ( result > 0 )
        result = (unsigned __int16)result | 0x80070000;
    }
  }
  return result;
}

//----- (00C1F920) --------------------------------------------------------
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
  if ( GetParent(hWnd) == (HWND)a2->m_OldWndProc )
  {
    GetWindowRect(hWnd, &Rect);
    ScreenToClient((HWND)a2->m_OldWndProc, (LPPOINT)&Rect);
    ScreenToClient((HWND)a2->m_OldWndProc, (LPPOINT)&Rect.right);
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
      if ( (signed int)a2->m_dwItemCount <= 0 )
      {
LABEL_34:
        pItem = 0;
      }
      else
      {
        v12 = &a2->m_pItem->m_hWnd;
        while ( *v12 != hWnd )
        {
          pItem = (tagResizerItem *)((char *)pItem + 1);
          v12 += 14;
          if ( (signed int)pItem >= (signed int)a2->m_dwItemCount )
            goto LABEL_34;
        }
        pItem = &a2->m_pItem[(_DWORD)pItem];
        if ( pItem )
        {
          if ( *(double *)pItem->gap0 >= 0.0 )
            v24 = *(double *)pItem->gap0;
          if ( *(double *)&pItem->gap0[8] >= 0.0 )
            v23 = *(double *)&pItem->gap0[8];
          if ( *(double *)&pItem->gap0[16] >= 0.0 )
            v9 = *(double *)&pItem->gap0[16];
          if ( *(double *)&pItem->gap0[24] >= 0.0 )
            v10 = *(double *)&pItem->gap0[24];
        }
      }
    }
    if ( v24 != 0.0 )
    {
      v13 = a2->m_nWidth3;
      if ( v24 == 1.0 )
        Rect.left += v13 - a2->m_ptMinTrackSize.x;
      else
        Rect.left = (signed int)((double)(v13 - a2->m_nWidth) * *(double *)pItem->gap0
                               + (double)*(signed int *)&pItem->gap0[32]);
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
        v16 = (double)(v14 - a2->m_nWidth) * *(double *)&pItem->gap0[8] + (double)*(signed int *)&pItem->gap0[40];
        v15 = (signed int)v16;
        v25 = (signed int)v16;
      }
      Rect.right = v15;
    }
    if ( v9 != 0.0 )
    {
      v17 = a2->m_nHeight3;
      if ( v9 == 1.0 )
        v8 = v17 - a2->m_ptMinTrackSize.y + Rect.top;
      else
        v8 = (signed int)((double)(v17 - a2->m_nHeight) * *(double *)&pItem->gap0[16]
                        + (double)*(signed int *)&pItem->gap0[36]);
      Rect.top = v8;
    }
    if ( v10 == 4.0 )
    {
      v7 = v8 + *(_DWORD *)&pItem->gap0[44] - *(_DWORD *)&pItem->gap0[36];
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
        v7 = (signed int)((double)(v18 - a2->m_nHeight) * *(double *)&pItem->gap0[24]
                        + (double)*(signed int *)&pItem->gap0[44]);
    }
    Rect.bottom = v7;
    goto LABEL_65;
  }
  return 1;
}
// CACB38: using guessed type double db_four;

//----- (00C1FD80) --------------------------------------------------------
int __thiscall CResizer::Refresh(CResizer *lParam)
{
  CResizer *v1; // ebx
  int result; // eax
  HDWP v3; // eax
  HWND v4; // ST00_4
  int v5; // edi
  int v6; // eax
  int v7; // ecx
  int v8; // ST08_4
  int v9; // eax
  HWND v10; // ST00_4
  struct tagRECT rcDst; // [esp+4h] [ebp-44h]
  struct tagRECT rc; // [esp+14h] [ebp-34h]
  struct tagRECT Rect; // [esp+24h] [ebp-24h]
  int rcSrc2; // [esp+34h] [ebp-14h]
  int v15; // [esp+38h] [ebp-10h]
  LONG v16; // [esp+3Ch] [ebp-Ch]
  LONG v17; // [esp+40h] [ebp-8h]

  v1 = lParam;
  if ( lParam->m_ptMinTrackSize.y != lParam->m_nHeight3
    || (result = lParam->m_ptMinTrackSize.x, result != lParam->m_nWidth3) )
  {
    v3 = BeginDeferWindowPos(512);
    v4 = (HWND)v1->m_OldWndProc;
    v1->m_hDWP = v3;
    EnumChildWindows(v4, (WNDENUMPROC)CResizer::EnumChildCallback, (LPARAM)v1);
    EndDeferWindowPos(v1->m_hDWP);
    GetClientRect((HWND)v1->m_OldWndProc, &Rect);
    v5 = GetSystemMetrics(SM_CXHSCROLL);
    v6 = GetSystemMetrics(SM_CYVSCROLL);
    rcSrc2 = Rect.right - v5;
    v7 = Rect.bottom - v6;
    v16 = Rect.right;
    v8 = v1->m_ptMinTrackSize.y - v1->m_nHeight3;
    v9 = v1->m_ptMinTrackSize.x - v1->m_nWidth3;
    v15 = v7;
    v17 = Rect.bottom;
    _mm_storeu_si128((__m128i *)&rc, _mm_loadu_si128((const __m128i *)&rcSrc2));
    OffsetRect(&rc, v9, v8);
    UnionRect(&rcDst, &rc, (const RECT *)&rcSrc2);
    InvalidateRect((HWND)v1->m_OldWndProc, &rcDst, TRUE);
    v10 = (HWND)v1->m_OldWndProc;
    v1->m_ptMinTrackSize.x = v1->m_nWidth3;
    v1->m_ptMinTrackSize.y = v1->m_nHeight3;
    result = InvalidateRect(v10, 0, TRUE);
  }
  return result;
}

//----- (00C1FE80) --------------------------------------------------------
int __thiscall sub_C1FE80(const wchar_t **this, wchar_t a2)
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

//----- (00C1FEB0) --------------------------------------------------------
CStringData *__thiscall sub_C1FEB0(CString *this, void *Src)
{
  CStringData *result; // eax

  if ( Src )
    result = ATL::CSimpleStringT<wchar_t,0>::SetString(this + 5, Src, wcslen((const unsigned __int16 *)Src));
  else
    result = ATL::CSimpleStringT<wchar_t,0>::SetString(this + 5, 0, 0);
  return result;
}

//----- (00C1FF00) --------------------------------------------------------
CStringData *__thiscall sub_C1FF00(CString *this, void *Src)
{
  CStringData *result; // eax

  if ( Src )
    result = ATL::CSimpleStringT<wchar_t,0>::SetString(this + 1, Src, wcslen((const unsigned __int16 *)Src));
  else
    result = ATL::CSimpleStringT<wchar_t,0>::SetString(this + 1, 0, 0);
  return result;
}

//----- (00C1FF50) --------------------------------------------------------
CStringData *__thiscall sub_C1FF50(CString *this, void *Src)
{
  CStringData *result; // eax

  if ( Src )
    result = ATL::CSimpleStringT<wchar_t,0>::SetString(this + 2, Src, wcslen((const unsigned __int16 *)Src));
  else
    result = ATL::CSimpleStringT<wchar_t,0>::SetString(this + 2, 0, 0);
  return result;
}

//----- (00C1FFA0) --------------------------------------------------------
CStringData *__thiscall sub_C1FFA0(CString *this, void *Src)
{
  CStringData *result; // eax

  if ( Src )
    result = ATL::CSimpleStringT<wchar_t,0>::SetString(this + 3, Src, wcslen((const unsigned __int16 *)Src));
  else
    result = ATL::CSimpleStringT<wchar_t,0>::SetString(this + 3, 0, 0);
  return result;
}

//----- (00C1FFF0) --------------------------------------------------------
int __thiscall sub_C1FFF0(CString *this, void *Src)
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
  v3 = (unsigned __int16 *)Src;
  if ( Src )
    v4 = wcslen((const unsigned __int16 *)Src);
  else
    v4 = 0;
  ATL::CSimpleStringT<wchar_t,0>::SetString(this + 4, Src, v4);
  v5 = v2 + 1;
  if ( v3 )
    v6 = wcslen(v3);
  else
    v6 = 0;
  ATL::CSimpleStringT<wchar_t,0>::SetString(v5, v3, v6);
  result = (int)v5->pszData;
  if ( *((_DWORD *)v5->pszData - 3) > 0 )
  {
    result = (int)wcschr((const wchar_t *)result, 0x2Cu);
    if ( result )
    {
      result = (signed int)(result - (unsigned int)v5->pszData) >> 1;
      if ( result >= 0 )
      {
        v8 = sub_C1F790(v5, &Src, 0, result);
        sub_C1D840(v5, v8);
        v9 = (char *)Src - 16;
        result = (int)Src - 4;
        if ( _InterlockedDecrement((volatile signed __int32 *)result) <= 0 )
          result = (*(int (__stdcall **)(char *))(**(_DWORD **)v9 + 4))(v9);
      }
    }
  }
  return result;
}

//----- (00C200E0) --------------------------------------------------------
CStringData *__thiscall sub_C200E0(CString *this, void *Src)
{
  CStringData *result; // eax

  if ( Src )
    result = ATL::CSimpleStringT<wchar_t,0>::SetString(this + 6, Src, wcslen((const unsigned __int16 *)Src));
  else
    result = ATL::CSimpleStringT<wchar_t,0>::SetString(this + 6, 0, 0);
  return result;
}

//----- (00C20130) --------------------------------------------------------
int __thiscall sub_C20130(HWND *this)
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

//----- (00C201B0) --------------------------------------------------------
void *__thiscall sub_C201B0(int this)
{
  return sub_C1CC30(
           *(void **)(this + 32),
           *(_DWORD *)(this + 36),
           (*(_DWORD *)(this + 36) - *(_DWORD *)(this + 32)) >> 2,
           (int)sub_C1E780);
}

//----- (00C201D0) --------------------------------------------------------
int __cdecl sub_C201D0(wchar_t *Dst, rsize_t SizeInWords, int a3)
{
  return sub_C1E970(Dst, SizeInWords, (unsigned __int16)a3, (int)&unk_CCD150, 5);
}

//----- (00C20200) --------------------------------------------------------
int __cdecl sub_C20200(wchar_t *Src, int a2)
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
  *(_DWORD *)a2 = sub_C1F690(&Dst);
  wcsncpy_s(&Dst, 0xAu, Src + 9, 4u);
  v9 = 0;
  *(_WORD *)(a2 + 4) = sub_C1F690(&Dst);
  wcsncpy_s(&Dst, 0xAu, Src + 14, 4u);
  v9 = 0;
  *(_WORD *)(a2 + 6) = sub_C1F690(&Dst);
  v2 = 0;
  v3 = Src + 19;
  do
  {
    wcsncpy_s(&Dst, 0xAu, v3, 2u);
    v8 = 0;
    *(_BYTE *)(a2 + 8 + v2++) = sub_C1F690(&Dst);
    v3 += 2;
  }
  while ( v2 < 2 );
  v4 = 2;
  v5 = Src + 24;
  do
  {
    wcsncpy_s(&Dst, 0xAu, v5, 2u);
    v8 = 0;
    result = sub_C1F690(&Dst);
    *(_BYTE *)(a2 + 8 + v4++) = result;
    v5 += 2;
  }
  while ( v4 < 8 );
  return result;
}

//----- (00C20310) --------------------------------------------------------
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
  v5 = (CResizer *)GetPropW(hWnd, L"ResizerClass");
  v6 = wParam;
  v7 = v5;
  Msg_1 = Msg;
  switch ( Msg )
  {
    case WM_DESTROY:
      v19 = (LRESULT (__stdcall *)(HWND, UINT, WPARAM, LPARAM))v7->m_hWnd;
      SetWindowLongW(hWnd, GWLP_WNDPROC, (LONG)v7->m_hWnd);
      CResizer::~CResizer(v7);
      operator delete(v7);
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
      *(_DWORD *)(lParam + 24) = v7->m_nWidth;
      *(_DWORD *)(lParam + 28) = v7->m_nHeight;
      result = 0;
      break;
    case WM_NCHITTEST:
      v15 = CallWindowProcW((WNDPROC)v7->m_hWnd, hWnd, Msg, wParam, lParam);
      if ( GetWindowLongW(hWnd, GWL_STYLE) & WS_CHILD
        || v15 != 1
        || IsZoomed(hWnd)
        || (GetWindowRect(hWnd, &Rect),
            Rect.left = Rect.right - GetSystemMetrics(21),
            Rect.top = Rect.bottom - GetSystemMetrics(20),
            v16.y = SHIWORD(lParam),
            v16.x = (signed __int16)lParam,
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
            v14 = ((int (__thiscall *)(CResizer *))v7->baseclass.vtptr->GetName)(v7);
            v7->baseclass.m_hThemeHandle = (HTHEME)gpfnOpenThemeData(hWnd, v14);
          }
        }
      }
      result = ((int (__fastcall *)(CResizer *, WPARAM, HWND, UINT, WPARAM, LPARAM))v7->baseclass.vtptr->HandleMessage)(
                 v7,
                 v6,
                 hWnd,
                 Msg,
                 wParam,
                 v4);
      break;
  }
  return result;
}
// CD4D84: using guessed type int (__stdcall *gpfnIsThemeActive)();

//----- (00C20650) --------------------------------------------------------
char *__thiscall sub_C20650(const void **this, unsigned int a2)
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
    if ( a2 > 0x7FFFFFFF || (v3 = (char *)operator new(2 * a2)) == 0 )
      std::_Xbad_alloc();
  }
  memmove(v3, *v4, ((_BYTE *)v4[1] - (_BYTE *)*v4) & 0xFFFFFFFE);
  v6 = ((_BYTE *)v4[1] - (_BYTE *)*v4) >> 1;
  if ( *v4 )
    operator delete((void *)*v4);
  *v4 = v3;
  v4[2] = &v3[2 * v2];
  result = &v3[2 * v6];
  v4[1] = result;
  return result;
}

//----- (00C206D0) --------------------------------------------------------
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
    if ( a2 > 0x3FFFFFFF || (v3 = (char *)operator new(4 * a2)) == 0 )
      std::_Xbad_alloc();
  }
  memmove(
    v3,
    v4->baseclass_0._Mypair._Myval2._Myfirst,
    (v4->baseclass_0._Mypair._Myval2._Mylast - v4->baseclass_0._Mypair._Myval2._Myfirst) & 0xFFFFFFFC);
  v6 = (_DWORD)(v4->baseclass_0._Mypair._Myval2._Mylast - v4->baseclass_0._Mypair._Myval2._Myfirst) >> 2;
  if ( v4->baseclass_0._Mypair._Myval2._Myfirst )
    operator delete(v4->baseclass_0._Mypair._Myval2._Myfirst);
  v4->baseclass_0._Mypair._Myval2._Myfirst = v3;
  v4->baseclass_0._Mypair._Myval2._Myend = &v3[4 * v2];
  result = &v3[4 * v6];
  v4->baseclass_0._Mypair._Myval2._Mylast = result;
  return result;
}

//----- (00C20750) --------------------------------------------------------
unsigned int __thiscall sub_C20750(int this, unsigned int a2)
{
  int v2; // esi
  unsigned int result; // eax
  int v4; // esi
  unsigned int v5; // esi
  unsigned int v6; // edx
  unsigned int v7; // edx
  unsigned int v8; // edx

  v2 = *(_DWORD *)(this + 4);
  result = (*(_DWORD *)(this + 8) - v2) >> 1;
  if ( result < a2 )
  {
    v4 = (v2 - *(_DWORD *)this) >> 1;
    if ( 0x7FFFFFFF - v4 < a2 )
      std::_Xlength_error("vector<T> too long");
    v5 = a2 + v4;
    v6 = (*(_DWORD *)(this + 8) - *(_DWORD *)this) >> 1;
    if ( 0x7FFFFFFF - (v6 >> 1) >= v6 )
    {
      v8 = (v6 >> 1) + v6;
      if ( v8 < v5 )
        v8 = v5;
      result = (unsigned int)sub_C20650((const void **)this, v8);
    }
    else
    {
      v7 = 0;
      if ( v5 > 0 )
        v7 = v5;
      result = (unsigned int)sub_C20650((const void **)this, v7);
    }
  }
  return result;
}

//----- (00C207C0) --------------------------------------------------------
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
  result = (_DWORD)(this->baseclass_0._Mypair._Myval2._Myend - v2) >> 2;
  if ( result < a2 )
  {
    v4 = (signed int)((signed int)v2 - (unsigned int)this->baseclass_0._Mypair._Myval2._Myfirst) >> 2;
    if ( 0x3FFFFFFF - v4 < a2 )
      std::_Xlength_error("vector<T> too long");
    v5 = a2 + v4;
    v6 = (_DWORD)(this->baseclass_0._Mypair._Myval2._Myend - this->baseclass_0._Mypair._Myval2._Myfirst) >> 2;
    if ( 0x3FFFFFFF - (v6 >> 1) >= v6 )
    {
      v8 = (v6 >> 1) + v6;
      if ( v8 < v5 )
        v8 = v5;
      result = (unsigned int)std::vector<tagAccountInfo *,std::allocator<tagAccountInfo *>>::_Reallocate(this, v8);
    }
    else
    {
      v7 = 0;
      if ( v5 > 0 )
        v7 = v5;
      result = (unsigned int)std::vector<tagAccountInfo *,std::allocator<tagAccountInfo *>>::_Reallocate(this, v7);
    }
  }
  return result;
}

//----- (00C20840) --------------------------------------------------------
int __thiscall sub_C20840(_DWORD *this, int a2, void *a3)
{
  _DWORD *v3; // edi
  int result; // eax

  v3 = this;
  memmove(a3, (char *)a3 + 2, (this[1] - ((_DWORD)a3 + 2)) & 0xFFFFFFFE);
  result = a2;
  v3[1] -= 2;
  *(_DWORD *)a2 = a3;
  return result;
}

//----- (00C20880) --------------------------------------------------------
__int16 __thiscall sub_C20880(_DWORD *this, _WORD *a2)
{
  _DWORD *v2; // esi
  unsigned int v3; // eax
  int v4; // edi
  _WORD *v5; // ecx
  _WORD *v6; // ecx

  v2 = this;
  v3 = this[1];
  if ( (unsigned int)a2 >= v3 || *this > (unsigned int)a2 )
  {
    if ( v3 == this[2] )
      LOWORD(v3) = sub_C20750((int)this, 1u);
    v6 = (_WORD *)v2[1];
    if ( v6 )
    {
      LOWORD(v3) = *a2;
      *v6 = *a2;
    }
    goto LABEL_11;
  }
  v4 = ((signed int)a2 - *this) >> 1;
  if ( v3 == this[2] )
    LOWORD(v3) = sub_C20750((int)this, 1u);
  v5 = (_WORD *)v2[1];
  if ( !v5 )
  {
LABEL_11:
    v2[1] += 2;
    return v3;
  }
  LOWORD(v3) = *(_WORD *)(*v2 + 2 * v4);
  *v5 = v3;
  v2[1] += 2;
  return v3;
}

//----- (00C208F0) --------------------------------------------------------
tagAccountInfo *__thiscall std::vector<tagAccountInfo *,std::allocator<tagAccountInfo *>>::push_back(std__vector *this, tagAccountInfo *pInfo)
{
  std__vector *v2; // esi
  tagAccountInfo *result; // eax
  int v4; // edi
  _DWORD *v5; // ecx
  _DWORD *v6; // ecx

  v2 = this;
  result = (tagAccountInfo *)this->baseclass_0._Mypair._Myval2._Mylast;
  if ( pInfo >= result || this->baseclass_0._Mypair._Myval2._Myfirst > pInfo )
  {
    if ( result == this->baseclass_0._Mypair._Myval2._Myend )
      result = (tagAccountInfo *)std::vector<tagAccountInfo *,std::allocator<tagAccountInfo *>>::_Reserve(this, 1u);
    v6 = v2->baseclass_0._Mypair._Myval2._Mylast;
    if ( v6 )
    {
      result = (tagAccountInfo *)pInfo->bIsSystemUser;
      *v6 = pInfo->bIsSystemUser;
    }
  }
  else
  {
    v4 = ((char *)pInfo - (char *)this->baseclass_0._Mypair._Myval2._Myfirst) >> 2;
    if ( result == this->baseclass_0._Mypair._Myval2._Myend )
      result = (tagAccountInfo *)std::vector<tagAccountInfo *,std::allocator<tagAccountInfo *>>::_Reserve(this, 1u);
    v5 = v2->baseclass_0._Mypair._Myval2._Mylast;
    if ( v5 )
    {
      result = (tagAccountInfo *)*((_DWORD *)v2->baseclass_0._Mypair._Myval2._Myfirst + v4);
      *v5 = result;
      v2->baseclass_0._Mypair._Myval2._Mylast = (char *)v2->baseclass_0._Mypair._Myval2._Mylast + 4;
      return result;
    }
  }
  v2->baseclass_0._Mypair._Myval2._Mylast = (char *)v2->baseclass_0._Mypair._Myval2._Mylast + 4;
  return result;
}

//----- (00C20960) --------------------------------------------------------
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

//----- (00C209A0) --------------------------------------------------------
int __cdecl sub_C209A0(wchar_t *Dst, int a2, __int64 a3)
{
  int result; // eax

  if ( gConfig.bShowCpuFractions )
    result = swprintf_s(Dst, 0x20u, L"%s%0.2f%%", a2, a3);
  else
    result = swprintf_s(Dst, 0x20u, L"%s%0.0f%%", a2, a3);
  return result;
}

//----- (00C209F0) --------------------------------------------------------
int __cdecl sub_C209F0(wchar_t *Dst, int a2, __int64 a3)
{
  int result; // eax

  if ( gConfig.bShowCpuFractions )
    result = swprintf_s(Dst, 0x400u, L"%s%0.2f%%", a2, a3);
  else
    result = swprintf_s(Dst, 0x400u, L"%s%0.0f%%", a2, a3);
  return result;
}

//----- (00C20A40) --------------------------------------------------------
errno_t __cdecl sub_C20A40(wchar_t *a1, int a2, __int64 a3)
{
  return sub_C22410(a1, 0x400u, a2, a3);
}

//----- (00C20A70) --------------------------------------------------------
int wsprintfW(wchar_t *Dst, wchar_t *Format, ...)
{
  va_list ArgList; // [esp+10h] [ebp+10h]

  va_start(ArgList, Format);
  return vswprintf_s(Dst, 0x400u, Format, ArgList);
}

//----- (00C20A90) --------------------------------------------------------
int *__thiscall sub_C20A90(BitmapItem *this, int a2, int a3, int a4, int a5, unsigned int a6, int a7)
{
  char v7; // al
  int v8; // edx
  int v9; // edi
  int v10; // ebx
  int v11; // esi
  int *result; // eax
  int v13; // ecx
  int v14; // edx
  int v15; // ebx
  int v16; // eax
  bool v17; // zf
  int v18; // [esp+Ch] [ebp-10h]
  int v19; // [esp+10h] [ebp-Ch]
  int a6a; // [esp+14h] [ebp-8h]
  BitmapItem *v21; // [esp+18h] [ebp-4h]
  int a3a; // [esp+24h] [ebp+8h]
  int a2a; // [esp+28h] [ebp+Ch]
  int v24; // [esp+2Ch] [ebp+10h]
  int v25; // [esp+30h] [ebp+14h]
  int v26; // [esp+30h] [ebp+14h]
  int v27; // [esp+30h] [ebp+14h]

  v7 = a7;
  v21 = this;
  if ( (_BYTE)a7 )
  {
    v7 = a7;
    a6a = (unsigned __int8)(a6 + (256 - (unsigned __int8)a6) / 2) | (((unsigned __int8)(BYTE1(a6) + (256 - BYTE1(a6)) / 2) | ((unsigned __int8)(BYTE2(a6) + (256 - BYTE2(a6)) / 2) << 8)) << 8);
    v8 = (unsigned __int8)(a6 + (256 - (unsigned __int8)a6) / 2) | (((unsigned __int8)(BYTE1(a6) + (256 - BYTE1(a6)) / 2) | ((unsigned __int8)(BYTE2(a6) + (256 - BYTE2(a6)) / 2) << 8)) << 8);
  }
  else
  {
    v8 = a7;
    a6a = a7;
  }
  v9 = a2;
  v10 = a4 - a2;
  v11 = a3;
  v25 = a5 - a3;
  if ( v7 )
    sub_C20E50(this, a3, a2, a3, this->nHeight, v8, 0);
  else
    this->pBits[a3 + a2 * this->nWidth] = (unsigned __int16)(a6 & 0xFF00) | ((unsigned __int8)a6 << 16) | (a6 >> 16) & 0xFF;
  if ( v10 >= 0 )
  {
    a3a = 1;
  }
  else
  {
    a3a = -1;
    v10 = -v10;
  }
  result = (int *)v25;
  if ( v25 >= 0 )
  {
    a2a = 1;
  }
  else
  {
    a2a = -1;
    result = (int *)-v25;
  }
  v13 = 2 * v10;
  v14 = 2 * (_DWORD)result;
  v19 = 2 * v10;
  v18 = 2 * (_DWORD)result;
  if ( 2 * (signed int)result < 2 * v10 )
  {
    if ( v10 > 0 )
    {
      v27 = v10;
      do
      {
        v9 += a3a;
        v10 += v14;
        if ( v10 > v13 )
        {
          v11 += a2a;
          v10 -= v13;
        }
        if ( (_BYTE)a7 )
        {
          LOBYTE(result) = sub_C20E50(v21, v11, v9, v11, v21->nHeight, a6a, 0);
        }
        else
        {
          result = v21->pBits;
          result[v11 + v9 * v21->nWidth] = (unsigned __int16)(a6 & 0xFF00) | ((unsigned __int8)a6 << 16) | (a6 >> 16) & 0xFF;
        }
        v17 = v27-- == 1;
        v13 = v19;
        v14 = v18;
      }
      while ( !v17 );
    }
  }
  else if ( (signed int)result > 0 )
  {
    v15 = (int)result;
    v24 = (int)result;
    do
    {
      v11 += a2a;
      v16 = (int)result + v13;
      v26 = v16;
      if ( v16 > v14 )
      {
        v9 += a3a;
        v26 = v16 - v14;
      }
      if ( (_BYTE)a7 )
      {
        sub_C20E50(v21, v11, v9, v11, v21->nHeight, a6a, 0);
        v15 = v24;
      }
      else
      {
        v21->pBits[v11 + v9 * v21->nWidth] = (unsigned __int16)(a6 & 0xFF00) | ((unsigned __int8)a6 << 16) | (a6 >> 16) & 0xFF;
      }
      result = (int *)v26;
      --v15;
      v13 = v19;
      v14 = v18;
      v24 = v15;
    }
    while ( v15 );
  }
  return result;
}

//----- (00C20CA0) --------------------------------------------------------
char __thiscall BitmapItem_Create(BitmapItem *this, LONG nWidth, signed int nHeight)
{
  BitmapItem *v3; // ST24_4
  HDC hDC; // ebx
  HDC v5; // eax
  void *v6; // ST14_4
  BITMAPINFO bi; // [esp+10h] [ebp-2Ch]

  v3 = this;
  hDC = GetDC(0);
  _mm_storeu_si128((__m128i *)&bi.bmiHeader.biWidth, (__m128i)0i64);
  bi.bmiHeader.biClrImportant = 0;
  bi.bmiHeader.biSize = offsetof(BITMAPINFO, bmiColors);
  bi.bmiHeader.biHeight = -nHeight;
  bi.bmiHeader.biWidth = nWidth;
  *(_DWORD *)&bi.bmiHeader.biPlanes = 0x200001;
  _mm_storeu_si128((__m128i *)&bi.bmiHeader.biSizeImage, (__m128i)0i64);
  bi.bmiHeader.biClrUsed = 0;
  bi.bmiHeader.biCompression = 0;
  bi.bmiHeader.biSizeImage = 0;
  v3->hBitmapHandle = (int)CreateDIBSection(hDC, &bi, 0, (void **)&v3->pBits, 0, 0);
  v3->nHeight = nHeight;
  v3->nWidth = nWidth;
  v5 = CreateCompatibleDC(hDC);
  v6 = (void *)v3->hBitmapHandle;
  v3->CompatibleDC = (int)v5;
  SelectObject(v5, v6);
  ReleaseDC(0, hDC);
  return 1;
}

//----- (00C20D60) --------------------------------------------------------
char __thiscall BitmapItem_SetRectColor(BitmapItem *this, #153 *lprc, unsigned int color)
{
  #153 *v3; // edx
  int left; // esi
  BitmapItem *pItem; // ebx
  int top; // eax
  int right; // ecx
  int y; // edi
  int bottom; // eax
  int nHeight; // edx
  signed int x; // eax
  int nBit; // edx
  int i; // [esp+Ch] [ebp-8h]
  int left_1; // [esp+10h] [ebp-4h]
  #153 *nWidth; // [esp+1Ch] [ebp+8h]

  v3 = lprc;
  left = 0;
  pItem = this;
  if ( *(_DWORD *)lprc > 0 )
    left = *(_DWORD *)lprc;
  top = *((_DWORD *)lprc + 1);
  right = this->nWidth;
  left_1 = left;
  if ( *((_DWORD *)lprc + 2) < right )
    right = *((_DWORD *)lprc + 2);
  y = 0;
  nWidth = (#153 *)right;
  if ( top > 0 )
    y = top;
  bottom = *((_DWORD *)v3 + 3);
  nHeight = pItem->nHeight;
  if ( bottom < nHeight )
    nHeight = bottom;
  for ( i = nHeight; y < nHeight; ++y )
  {
    x = left;
    if ( left < right )
    {
      do
      {
        nBit = x++ + y * pItem->nWidth;
        pItem->pBits[nBit] = (unsigned __int16)(color & 0xFF00) | ((unsigned __int8)color << 16) | (color >> 16) & 0xFF;
        right = (int)nWidth;
      }
      while ( x < (signed int)nWidth );
      left = left_1;
      nHeight = i;
    }
  }
  return 1;
}

//----- (00C20E00) --------------------------------------------------------
int __cdecl sub_C20E00(wchar_t *Dst, size_t SizeInWords, int a3, __int64 a4)
{
  int result; // eax

  if ( gConfig.bShowCpuFractions )
    result = swprintf_s(Dst, SizeInWords, L"%s%0.2f%%", a3, a4);
  else
    result = swprintf_s(Dst, SizeInWords, L"%s%0.0f%%", a3, a4);
  return result;
}

//----- (00C20E50) --------------------------------------------------------
char __thiscall sub_C20E50(BitmapItem *this, int a2, int a3, int a4, int a5, unsigned int a6, int a7)
{
  int v7; // eax
  BitmapItem *v8; // esi
  int v9; // ecx
  int v10; // ecx
  int v11; // edx
  int v12; // edx
  int v13; // edi
  int v14; // edi
  int v15; // ebx

  v7 = a2;
  v8 = this;
  if ( a2 >= 0 )
  {
    v9 = this->nWidth;
    if ( a2 >= v9 )
      v7 = v9 - 1;
  }
  else
  {
    v7 = 0;
  }
  v10 = a4;
  if ( a4 >= 0 )
  {
    v11 = v8->nWidth;
    if ( a4 >= v11 )
      v10 = v11 - 1;
  }
  else
  {
    v10 = 0;
  }
  v12 = a3;
  if ( a3 >= 0 )
  {
    v13 = v8->nHeight;
    if ( a3 >= v13 )
      v12 = v13 - 1;
  }
  else
  {
    v12 = 0;
  }
  v14 = a5;
  if ( a5 >= 0 )
  {
    v15 = v8->nHeight;
    if ( a5 >= v15 )
      v14 = v15 - 1;
  }
  else
  {
    v14 = 0;
  }
  sub_C20A90(v8, v12, v7, v14, v10, a6, a7);
  return 1;
}

//----- (00C20ED0) --------------------------------------------------------
char __thiscall sub_C20ED0(BitmapItem *this, int a2, int a3, int a4, int a5, unsigned int a6, char a7)
{
  int v7; // esi
  BitmapItem *v8; // ebx
  int v9; // eax
  int v10; // eax
  int v11; // ecx
  int v12; // edi
  int v13; // ecx
  int v14; // ecx
  int v15; // edx
  unsigned int v16; // ecx
  int v17; // edx
  int v18; // ecx
  unsigned int v20; // ecx
  int v21; // edx
  int v22; // ecx

  v7 = a2;
  v8 = this;
  if ( a2 >= 0 )
  {
    v9 = this->nWidth;
    if ( a2 >= v9 )
      v7 = v9 - 1;
  }
  else
  {
    v7 = 0;
  }
  v10 = a4;
  if ( a4 >= 0 )
  {
    v11 = this->nWidth;
    if ( a4 < v11 )
      goto LABEL_10;
    v10 = v11 - 1;
  }
  else
  {
    v10 = 0;
  }
  a4 = v10;
LABEL_10:
  v12 = a3;
  if ( a3 >= 0 )
  {
    v13 = v8->nHeight;
    if ( a3 >= v13 )
      v12 = v13 - 1;
  }
  else
  {
    v12 = 0;
  }
  v14 = a5;
  if ( a5 >= 0 )
  {
    v15 = v8->nHeight;
    if ( a5 < v15 )
      goto LABEL_19;
    v14 = v15 - 1;
  }
  else
  {
    v14 = 0;
  }
  a5 = v14;
LABEL_19:
  if ( v7 != v10 )
  {
    if ( v7 < v10 )
    {
      do
      {
        if ( a7 )
          v20 = ((unsigned int)(unsigned __int8)a6 >> 1) | ((unsigned __int16)((BYTE1(a6) | (unsigned __int16)((unsigned __int8)(BYTE2(a6) & 0xFE) << 8)) & 0xFFFE) << 7);
        else
          v20 = a6;
        v21 = (unsigned __int16)(v20 & 0xFF00) | ((unsigned __int8)v20 << 16) | (v20 >> 16) & 0xFF;
        v22 = v7++ + v12 * v8->nWidth;
        v8->pBits[v22] = v21;
      }
      while ( v7 < a4 );
    }
    return 1;
  }
  if ( v12 >= v14 )
    return 1;
  do
  {
    if ( a7 )
      v16 = ((unsigned int)(unsigned __int8)a6 >> 1) | ((unsigned __int16)((BYTE1(a6) | (unsigned __int16)((unsigned __int8)(BYTE2(a6) & 0xFE) << 8)) & 0xFFFE) << 7);
    else
      v16 = a6;
    v17 = (unsigned __int16)(v16 & 0xFF00) | ((unsigned __int8)v16 << 16) | (v16 >> 16) & 0xFF;
    v18 = v12++ * v8->nWidth;
    v8->pBits[v7 + v18] = v17;
  }
  while ( v12 < a5 );
  return 1;
}

//----- (00C21020) --------------------------------------------------------
void __cdecl CGraphData_Update(CGraphData *pGraphData, FILETIME time, double dbMemorySize, double dbMemorySize_2, wchar_t *lpszText)
{
  WCHAR *v5; // ebx
  WCHAR **v6; // edx
  int v7; // ecx
  int m_nWidth; // ecx
  WCHAR **v9; // eax
  double *v10; // ecx
  double dbMemorySize_1; // [esp+4h] [ebp-8h]

  if ( pGraphData )
  {
    dbMemorySize_1 = dbMemorySize;
    if ( pGraphData->m_nItemID )
    {
      if ( dbMemorySize > pGraphData->m_dbMemorySize )
        pGraphData->m_dbMemorySize = dbMemorySize * 1.200000047683716;
    }
    else if ( dbMemorySize <= pGraphData->m_dbMemorySize )
    {
      if ( dbMemorySize < 0.0 )
        dbMemorySize_1 = 0.0;
    }
    else
    {
      dbMemorySize_1 = pGraphData->m_dbMemorySize;
    }
    if ( dbMemorySize_2 <= pGraphData->m_Item[0].dbMemorySize )
    {
      if ( dbMemorySize_2 < 0.0 )
        dbMemorySize_2 = 0.0;
    }
    else
    {
      dbMemorySize_2 = db_onehundred;
    }
    v5 = _wcsdup(lpszText);
    EnterCriticalSection(&pGraphData->m_Lock.m_Lock);
    v6 = pGraphData->m_pBuffer;
    if ( v6 )
    {
      v7 = pGraphData->m_nWidth;
      if ( v6[v7] )
        free(v6[v7]);
      m_nWidth = pGraphData->m_nWidth;
      v9 = pGraphData->m_pBuffer;
      if ( lpszText )
        v9[m_nWidth] = v5;
      else
        v9[m_nWidth] = 0;
    }
    pGraphData->m_pBuffer1[pGraphData->m_nWidth] = (signed __int64)(*(_QWORD *)&time - *(_QWORD *)&pGraphData->m_Time)
                                                 / 10000000;
    pGraphData->m_Item[0].pBuffer[pGraphData->m_nWidth] = dbMemorySize_1;
    v10 = pGraphData->m_Item[1].pBuffer;
    if ( v10 )
      v10[pGraphData->m_nWidth] = dbMemorySize_2;
    if ( ++pGraphData->m_nWidth >= gdwVirtualScreenWidth )
      pGraphData->m_nWidth = 0;
    LeaveCriticalSection(&pGraphData->m_Lock.m_Lock);
  }
}
// CACDC0: using guessed type double db_onehundred;
// CD4E28: using guessed type int gdwVirtualScreenWidth;

//----- (00C21160) --------------------------------------------------------
CGraphData *__cdecl InitGraphData(int nCount, int nChildID, BOOL fFlags)
{
  int nCount_1; // edi
  CGraphData *result; // eax
  UCHAR *pBuffer; // ebx
  void *v6; // eax
  void *v7; // eax
  UCHAR *v8; // esi
  int nChildID_1; // edi
  void *v10; // eax
  struct _FILETIME *lpSystemTimeAsFileTime; // [esp+4h] [ebp-8h]
  CGraphData *pGrahData; // [esp+8h] [ebp-4h]

  nCount_1 = nCount;
  result = (CGraphData *)malloc(sizeof(CGraphData) * nCount);
  pGrahData = result;
  if ( nCount > 0 )
  {
    lpSystemTimeAsFileTime = &result->m_Time;
    pBuffer = (UCHAR *)&result->m_pBuffer;
    do
    {
      memset(pBuffer - 2144, 0, sizeof(CGraphData));
      pGrahData->m_nChildID = nChildID;
      InitializeCriticalSection((LPCRITICAL_SECTION)(pBuffer - 2144));
      GetSystemTimeAsFileTime(lpSystemTimeAsFileTime);
      v6 = malloc(4 * gdwVirtualScreenWidth);
      *((_DWORD *)pBuffer + 3) = v6;
      memset(v6, 0, 4 * gdwVirtualScreenWidth);
      if ( fFlags )
      {
        v7 = malloc(4 * gdwVirtualScreenWidth);
        *(_DWORD *)pBuffer = v7;
        memset(v7, 0, 4 * gdwVirtualScreenWidth);
      }
      if ( nChildID > 0 )
      {
        // pItem = &ppGraphDatap[i]->m_Item
        v8 = pBuffer - 2092;
        nChildID_1 = nChildID;
        do
        {
          v10 = malloc(8 * gdwVirtualScreenWidth);
          *(_DWORD *)v8 = v10;
          memset(v10, 0, 8 * gdwVirtualScreenWidth);
          v8 += 24;
          // for(i = 0; i < nChildID;i++)
          // {
          // pItem[i].pBuffer = malloc(...);
          // ZeroMemory(pItem[i].pBuffer,...);
          // }
          --nChildID_1;
        }
        while ( nChildID_1 );
        nCount_1 = nCount;
      }
      pBuffer += sizeof(CGraphData);
      nCount = --nCount_1;
    }
    while ( nCount_1 );
    result = pGrahData;
  }
  return result;
}
// C2125E: CONTAINING_RECORD: no field 'UCHAR *' in struct 'CGraphData' at 2200
// CD4E28: using guessed type int gdwVirtualScreenWidth;

//----- (00C21280) --------------------------------------------------------
void __cdecl GraphData_Release(CGraphData *pGraphData, int nCount)
{
  CGraphData *v2; // edi
  void **v3; // ebx
  int v4; // ecx
  int i; // esi
  signed int v6; // esi
  void **v7; // edi
  bool v8; // zf
  void **v9; // [esp+4h] [ebp-4h]

  v2 = pGraphData;
  if ( pGraphData )
  {
    if ( nCount > 0 )
    {
      v3 = (void **)&pGraphData->m_pBuffer;
      v9 = (void **)&pGraphData->m_pBuffer;
      do
      {
        free(v3[3]);
        if ( *v3 )
        {
          v4 = gdwVirtualScreenWidth;
          for ( i = 0; i < v4; ++i )
          {
            if ( *((_DWORD *)*v3 + i) )
            {
              free(*((void **)*v3 + i));
              v4 = gdwVirtualScreenWidth;
            }
          }
          free(*v3);
        }
        v6 = 0;
        if ( (signed int)v2->m_nChildID > 0 )
        {
          v7 = v3 - 523;
          do
          {
            free(*v7);
            ++v6;
            v7 += 6;
          }
          while ( v6 < (signed int)pGraphData->m_nChildID );
          v3 = v9;
          v2 = pGraphData;
        }
        DeleteCriticalSection((LPCRITICAL_SECTION)(v3 - 536));
        v3 += 550;
        v8 = nCount-- == 1;
        v9 = v3;
      }
      while ( !v8 );
    }
    free(v2);
  }
}
// CD4E28: using guessed type int gdwVirtualScreenWidth;

//----- (00C21340) --------------------------------------------------------
HWND __cdecl CreateGraphWindow(HWND hDlg, int nIDDlgItem, PVOID pParam)
{
  HWND v3; // eax
  HWND v4; // eax
  HWND hWnd; // eax
  struct tagRECT Rect; // [esp+Ch] [ebp-14h]

  v3 = GetDlgItem(hDlg, nIDDlgItem);
  GetWindowRect(v3, &Rect);
  MapWindowPoints(0, hDlg, (LPPOINT)&Rect, 2u);
  v4 = GetDlgItem(hDlg, nIDDlgItem);
  DestroyWindow(v4);
  if ( nIDDlgItem == IDC_SYSINFO_IO_STATIC_IO_CHART
    || nIDDlgItem == IDC_SYSINFO_SUM_STATIC_SYSTEM_COMMIT_CHART
    || nIDDlgItem == IDC_SYSINFO_SUM_STATIC_PHYSICAL_MEMORY_CHART
    || nIDDlgItem == IDC_SYSINFO_IOETW_STATIC_NETWORK_CHART
    || nIDDlgItem == IDC_SYSINFO_IOETW_STATIC_DISK_CHART
    || nIDDlgItem == IDC_SYSINFO_GPU_STATIC_GPU_DEDICATED_MEMORY_CHART
    || nIDDlgItem == IDC_SYSINFO_GPU_STATIC_GPU_SYSTEM_MEMORY_CHART
    || nIDDlgItem == 2603
    || nIDDlgItem >= (unsigned int)IDC_SYSINFO_CPU_STATIC_CPU_CHART && (unsigned int)nIDDlgItem < 2500
    || nIDDlgItem >= (unsigned int)IDC_SYSINFO_GPU_NODES_STATIC_GRAPH && (unsigned int)nIDDlgItem < 2600 )
  {
    hWnd = CreateWindowExW(
             0,
             L"CpuGraphClassGraph",
             (LPCWSTR)&gszNullString,
             0x50000000u,
             Rect.left,
             Rect.top,
             Rect.right - Rect.left,
             Rect.bottom - Rect.top,
             hDlg,
             (HMENU)nIDDlgItem,
             ghInstance,
             pParam);
  }
  else
  {
    hWnd = CreateWindowExW(
             0,
             L"CpuGraphClassChart",
             (LPCWSTR)&gszNullString,
             0x50000000u,
             Rect.left,
             Rect.top,
             Rect.right - Rect.left,
             Rect.bottom - Rect.top,
             hDlg,
             (HMENU)nIDDlgItem,
             ghInstance,
             pParam);
  }
  return hWnd;
}
// CACB88: using guessed type wchar_t aCpugraphclassc[19];

//----- (00C21470) --------------------------------------------------------
HGDIOBJ __cdecl GraphData_DrawGraph(CGraphData *pGraphData, HDC hDC, #153 *lprc)
{
  LONG v3; // edi
  int v4; // esi
  bool v5; // zf
  bool v6; // sf
  unsigned __int8 v7; // of
  double v8; // xmm0_8
  __int64 v9; // xmm0_8
  __int64 v10; // xmm0_8
  double v11; // xmm0_8
  int v12; // eax
  DWORD v13; // eax
  signed int v14; // edi
  signed int v15; // ecx
  int v16; // ebx
  double v17; // xmm2_8
  int v18; // edx
  double v19; // xmm3_8
  double v20; // xmm1_8
  CGraphData *v21; // eax
  int v22; // ecx
  signed int v23; // edi
  unsigned int v24; // edx
  int *v25; // ecx
  int v26; // eax
  int v27; // esi
  int v28; // edi
  int v29; // eax
  HBRUSH v30; // eax
  HBRUSH v31; // esi
  HGDIOBJ v32; // eax
  COLORREF v33; // eax
  HGDIOBJ result; // eax
  const wchar_t *dbValue_4; // [esp+4h] [ebp-108h]
  double v36; // [esp+14h] [ebp-F8h]
  int v37[2]; // [esp+1Ch] [ebp-F0h]
  unsigned int v38; // [esp+24h] [ebp-E8h]
  LONG v39; // [esp+28h] [ebp-E4h]
  HDC v40; // [esp+2Ch] [ebp-E0h]
  int *v41; // [esp+30h] [ebp-DCh]
  int v42; // [esp+34h] [ebp-D8h]
  double v43; // [esp+38h] [ebp-D4h]
  int v44; // [esp+40h] [ebp-CCh]
  CGraphData *v45; // [esp+44h] [ebp-C8h]
  HGDIOBJ ho; // [esp+48h] [ebp-C4h]
  int cy; // [esp+4Ch] [ebp-C0h]
  int v48; // [esp+50h] [ebp-BCh]
  HDC hdc; // [esp+54h] [ebp-B8h]
  void *v50; // [esp+58h] [ebp-B4h]
  __int64 v51; // [esp+5Ch] [ebp-B0h]
  int a2a; // [esp+64h] [ebp-A8h]
  struct tagRECT rc; // [esp+68h] [ebp-A4h]
  int v54; // [esp+78h] [ebp-94h]
  int v55; // [esp+7Ch] [ebp-90h]
  int v56; // [esp+80h] [ebp-8Ch]
  int v57; // [esp+84h] [ebp-88h]
  __int16 Dst[32]; // [esp+88h] [ebp-84h]
  __int16 chText[32]; // [esp+C8h] [ebp-44h]

  v40 = hDC;
  v45 = pGraphData;
  v3 = *((_DWORD *)lprc + 2) - *(_DWORD *)lprc;
  v42 = *((_DWORD *)lprc + 3) - *((_DWORD *)lprc + 1);
  v41 = (int *)lprc;
  cy = 0;
  v48 = 0;
  hdc = 0;
  ho = 0;
  v39 = v3;
  BitmapItem_Create((BitmapItem *)&ho, v3, v42);
  EnterCriticalSection(&pGraphData->m_Lock.m_Lock);
  v4 = pGraphData->m_nWidth - 1;
  if ( v4 < 0 )
    v4 = gdwVirtualScreenWidth - 1;
  v7 = __OFSUB__(pGraphData->m_nChildID, 1);
  v5 = pGraphData->m_nChildID == 1;
  v6 = (signed int)(pGraphData->m_nChildID - 1) < 0;
  v51 = *(__int64 *)&pGraphData->m_Item[0].pBuffer[v4];
  if ( (unsigned __int8)(v6 ^ v7) | v5 )
    v8 = v36;
  else
    v8 = pGraphData->m_Item[1].pBuffer[v4];
  v43 = v8;
  LeaveCriticalSection(&pGraphData->m_Lock.m_Lock);
  switch ( pGraphData->m_nItemID )
  {
    case 0u:
    case 4u:
      v9 = v51;
      if ( pGraphData->m_nChildID != 1 && *(double *)&v51 <= v43 )
        v9 = *(_QWORD *)&v43;
      sub_C209A0((wchar_t *)chText, (int)&gszNullString, v9);
      goto LABEL_18;
    case 1u:
    case 3u:
    case 5u:
    case 6u:
    case 7u:
      wcscpy_s((wchar_t *)Dst, 0x20u, L" KB");
      v10 = v51;
      if ( *(double *)&v51 <= 1048576.0 )
      {
        if ( *(double *)&v51 <= 1024.0 )
          goto LABEL_16;
        v11 = *(double *)&v51 * 0.0009765625;
        dbValue_4 = L" MB";
      }
      else
      {
        v11 = *(double *)&v51 * 0.00000095367431640625;
        dbValue_4 = L" GB";
      }
      *(double *)&v51 = v11;
      wcscpy_s((wchar_t *)Dst, 0x20u, dbValue_4);
      v10 = v51;
LABEL_16:
      swprintf_s((wchar_t *)chText, 0x20u, L"%s%0.1f", &gszNullString, (_DWORD)v10, HIDWORD(v10));
      wcscat_s((wchar_t *)chText, 0x20u, (const wchar_t *)Dst);
LABEL_18:
      SetBkColor(hdc, 0);
      SetTextColor(hdc, 0);
      v12 = DrawTextW(hdc, (LPCWSTR)chText, -1, &rc, DT_CALCRECT);
      v55 = 0;
      v54 = (signed int)((double)v3 / 3.0 * 0.5);
      v56 = v3 - v54;
      HIDWORD(v51) = v42 - v12;
      v57 = v42 - v12 - 2;
      v13 = GetSysColor(5);
      if ( v50 && cy * v48 )
        memset32(v50, (unsigned __int16)(v13 & 0xFF00) | ((unsigned __int8)v13 << 16) | (v13 >> 16) & 0xFF, cy * v48);
      BitmapItem_SetRectColor((BitmapItem *)&ho, (#153 *)&v54, gConfig.ColorGraphBk);
      v14 = pGraphData->m_nChildID;
      v15 = 0;
      v16 = v55;
      v44 = v55;
      if ( v14 > 0 )
      {
        v17 = (double)v57;
        v18 = (int)&v45->m_dbMemorySize;
        v19 = (double)(v57 - v55);
        do
        {
          v20 = *(double *)(*(_DWORD *)(v18 + 12) + 8 * v4) / *(double *)v18;
          v18 += 24;
          v37[v15++] = (signed int)(v17 - v20 * v19);
        }
        while ( v15 < v14 );
      }
      if ( v16 < v57 )
      {
        v21 = v45;
        v22 = v57;
        while ( 1 )
        {
          v23 = 0;
          v24 = 0x828282;
          if ( (signed int)v21->m_nChildID > 0 )
            break;
LABEL_52:
          v44 = ++v16;
          if ( v16 >= v22 )
            goto LABEL_53;
        }
        v25 = &v21->m_Color;
        a2a = (int)&v21->m_Color;
        do
        {
          v26 = v37[v23];
          if ( v16 >= v26 )
          {
            v24 = *v25;
            HIDWORD(v43) = *v25;
            if ( v16 > v26 + 1 )
            {
              v38 = v24 >> 8;
              v25 = (int *)a2a;
              v16 = v44;
              v24 = (((unsigned __int8)(BYTE1(v24) + (256 - BYTE1(v24)) / 2) | ((unsigned __int8)(BYTE2(v24)
                                                                                                + (256 - BYTE2(v24)) / 2) << 8)) << 8) | (unsigned __int8)(BYTE4(v43) + (256 - BYTE4(v43)) / 2);
            }
          }
          v21 = v45;
          ++v23;
          v25 += 6;
          a2a = (int)v25;
        }
        while ( v23 < (signed int)v45->m_nChildID );
        if ( v24 == 0x828282 )
        {
LABEL_51:
          v22 = v57;
          goto LABEL_52;
        }
        v27 = v54;
        v28 = v16;
        v29 = v56;
        a2a = v16;
        if ( v54 >= 0 )
        {
          if ( v54 >= v48 )
            v27 = v48 - 1;
        }
        else
        {
          v27 = 0;
        }
        if ( v56 >= 0 )
        {
          if ( v56 >= v48 )
            v29 = v48 - 1;
        }
        else
        {
          v29 = 0;
        }
        if ( v16 >= 0 )
        {
          if ( v16 < cy )
          {
LABEL_46:
            if ( v16 >= 0 )
            {
              if ( v16 >= cy )
                v28 = cy - 1;
            }
            else
            {
              v28 = 0;
            }
            sub_C20A90((BitmapItem *)&ho, a2a, v27, v28, v29, v24, 0);
            v21 = v45;
            goto LABEL_51;
          }
          a2a = cy - 1;
        }
        else
        {
          a2a = 0;
        }
        v16 = v44;
        goto LABEL_46;
      }
LABEL_53:
      v30 = CreateSolidBrush(0x828282u);
      ++v56;
      v31 = v30;
      FrameRect(hdc, (const RECT *)&v54, v30);
      DeleteObject(v31);
      rc.top = HIDWORD(v51);
      rc.bottom = v42;
      rc.left = 0;
      rc.right = v39;
      v32 = GetStockObject(17);
      SelectObject(hdc, v32);
      v33 = GetSysColor(5);
      SetBkColor(hdc, v33);
      SetTextColor(hdc, 0);
      DrawTextW(hdc, (LPCWSTR)chText, -1, &rc, 5u);
      BitBlt(v40, *v41, v41[1], v48, cy, hdc, 0, 0, 0xCC0020u);
      if ( hdc )
        DeleteDC(hdc);
      result = ho;
      if ( ho )
        result = (HGDIOBJ)DeleteObject(ho);
      return result;
    case 2u:
    case 8u:
    case 9u:
      PE_FormatDoubleFlow((WCHAR *)chText, 0x20u, *(double *)&v51 - v43 + v43);
      goto LABEL_18;
    default:
      goto LABEL_18;
  }
}
// CACBE0: using guessed type wchar_t aGb[4];
// CD4E28: using guessed type int gdwVirtualScreenWidth;
// C21470: using guessed type int var_F0[2];

//----- (00C21A60) --------------------------------------------------------
HICON __cdecl GraphData_DrawChart(CGraphData *pGraphData, HDC hDC, #153 *lprc, COLORREF Color, DWORD dwValue, double dbValue)
{
  HDC hCompatibleDC; // eax
  LONG nWidth; // ebx
  signed int nHeight; // edx
  COLORREF Color_1; // ecx
  void (__stdcall *DeleteObject)(HGDIOBJ); // edi
  unsigned int nSize; // ecx
  CGraphData *pGraphData_1; // edi
  int gdwVirtualScreenWidth; // ecx
  int v14; // edx
  tagGraphItem *pItem; // esi
  bool v16; // sf
  unsigned __int8 v17; // of
  unsigned int v18; // edx
  unsigned int v19; // eax
  unsigned int v20; // edx
  unsigned int v21; // eax
  int v22; // edx
  int v23; // edi
  int v24; // esi
  double v25; // xmm2_8
  double v26; // xmm1_8
  double v27; // xmm1_8
  int v28; // esi
  int v29; // edx
  int v30; // ecx
  int v31; // eax
  int bottom_1; // eax
  int index; // edi
  int y; // esi
  int nChildID; // edx
  int v36; // edx
  int v37; // edi
  int v38; // edx
  int v39; // esi
  double v40; // xmm1_8
  double v41; // xmm1_8
  double v42; // xmm1_8
  int v43; // edi
  int v44; // eax
  signed int v45; // esi
  int v46; // edx
  int v47; // ecx
  int v48; // ebx
  int v49; // ecx
  int v50; // edx
  tagGraphItem *v51; // edi
  HBRUSH hBrush; // esi
  HICON v53; // esi
  ICONINFO piconinfo; // [esp+Ch] [ebp-80h]
  HDC hdc; // [esp+20h] [ebp-6Ch]
  unsigned int v57; // [esp+24h] [ebp-68h]
  unsigned int v58; // [esp+28h] [ebp-64h]
  double v59; // [esp+2Ch] [ebp-60h]
  int v60; // [esp+34h] [ebp-58h]
  int v61; // [esp+38h] [ebp-54h]
  int nGraphWidth; // [esp+3Ch] [ebp-50h]
  int *lprc_1; // [esp+40h] [ebp-4Ch]
  int v64; // [esp+44h] [ebp-48h]
  int v65; // [esp+48h] [ebp-44h]
  int v66; // [esp+4Ch] [ebp-40h]
  BitmapItem BitmapItem; // [esp+50h] [ebp-3Ch]
  int bottom; // [esp+64h] [ebp-28h]
  int right; // [esp+68h] [ebp-24h]
  unsigned int a6; // [esp+6Ch] [ebp-20h]
  tagGraphItem *pItem_1; // [esp+70h] [ebp-1Ch]
  int v72; // [esp+74h] [ebp-18h]
  int rc; // [esp+78h] [ebp-14h]
  int v74; // [esp+7Ch] [ebp-10h]
  int v75; // [esp+80h] [ebp-Ch]
  int v76; // [esp+84h] [ebp-8h]
  COLORREF Colora; // [esp+A0h] [ebp+14h]

  hCompatibleDC = 0;
  lprc_1 = (int *)lprc;
  nWidth = *((_DWORD *)lprc + 2) - *(_DWORD *)lprc;
  nHeight = *((_DWORD *)lprc + 3) - *((_DWORD *)lprc + 1);
  Color_1 = Color;
  if ( Color == -1 )
    Color_1 = gConfig.ColorGraphBk;
  hdc = hDC;
  BitmapItem.nHeight = 0;
  BitmapItem.nWidth = 0;
  BitmapItem.CompatibleDC = 0;
  BitmapItem.hBitmapHandle = 0;
  right = nWidth;
  bottom = nHeight;
  v59 = 0.0;
  Colora = Color_1;
  DeleteObject = (void (__stdcall *)(HGDIOBJ))::DeleteObject;
  if ( hDC && (!nWidth || !nHeight) )
    goto LABEL_111;
  BitmapItem_Create(&BitmapItem, nWidth, nHeight);
  nSize = BitmapItem.nHeight * BitmapItem.nWidth;
  if ( BitmapItem.pBits && nSize )
    memset32(
      BitmapItem.pBits,
      (unsigned __int16)(Colora & 0xFF00) | ((unsigned __int8)Colora << 16) | (Colora >> 16) & 0xFF,
      nSize);
  pGraphData_1 = pGraphData;
  gdwVirtualScreenWidth = ::gdwVirtualScreenWidth;
  nGraphWidth = pGraphData->m_nWidth - 1;
  if ( nGraphWidth < 0 )
    nGraphWidth = ::gdwVirtualScreenWidth - 1;
  v14 = 0;
  for ( pItem = pGraphData->m_Item; ; ++pItem )
  {
    pItem_1 = pItem;
    v17 = __OFSUB__(v14, pGraphData_1->m_nChildID);
    v16 = (signed int)(v14 - pGraphData_1->m_nChildID) < 0;
    v65 = v14;
    if ( !(v16 ^ v17) )
      break;
    v18 = pItem[-1].Color;
    a6 = pItem[-1].Color;
    if ( Colora && right <= 20 && bottom <= 20 )
    {
      v19 = v18;
      v20 = v18 >> 16;
      v21 = v19 >> 8;
      if ( (unsigned __int8)v21 <= (unsigned __int8)v20 )
        a6 = (unsigned __int8)a6 < (unsigned __int8)v20 ? 0xFF0000 : 255;
      else
        a6 = (unsigned __int8)a6 < (unsigned __int8)v21 ? 0xFF00 : 255;
    }
    v22 = 0;
    v23 = -1;
    v66 = 0;
    if ( gdwVirtualScreenWidth > 0 )
    {
      v24 = 0;
      v64 = 0;
      v72 = right - 1;
      do
      {
        if ( v24 >= right + 1 )
          break;
        v25 = pItem_1->pBuffer[(nGraphWidth + gdwVirtualScreenWidth - v22) % gdwVirtualScreenWidth];
        if ( v25 > v59 )
          v59 = pItem_1->pBuffer[(nGraphWidth + gdwVirtualScreenWidth - v22) % gdwVirtualScreenWidth];
        if ( dbValue == 0.0 )
          v26 = v25 / pItem_1[-1].dbMemorySize;
        else
          v26 = v25 / dbValue;
        v27 = v26 * (double)bottom;
        v28 = bottom - (signed int)v27;
        if ( v23 != -1 && v25 != 0.0 )
        {
          v29 = v72;
          v30 = bottom - (signed int)v27;
          v31 = v72 + 2;
          if ( v72 >= 0 )
          {
            if ( v72 >= BitmapItem.nWidth )
              v29 = BitmapItem.nWidth - 1;
          }
          else
          {
            v29 = 0;
          }
          if ( v31 >= 0 )
          {
            if ( v31 >= BitmapItem.nWidth )
              v31 = BitmapItem.nWidth - 1;
          }
          else
          {
            v31 = 0;
          }
          if ( v28 >= 0 )
          {
            if ( v28 >= BitmapItem.nHeight )
              v30 = BitmapItem.nHeight - 1;
          }
          else
          {
            v30 = 0;
          }
          if ( v23 >= 0 )
          {
            if ( v23 >= BitmapItem.nHeight )
              v23 = BitmapItem.nHeight - 1;
          }
          else
          {
            v23 = 0;
          }
          sub_C20A90(&BitmapItem, v30, v29, v23, v31, a6, 1);
          gdwVirtualScreenWidth = ::gdwVirtualScreenWidth;
        }
        v23 = v28;
        v22 = v66 + 1;
        v72 -= 2;
        v24 = v64 + 2;
        v66 = v22;
        v64 += 2;
      }
      while ( v22 < gdwVirtualScreenWidth );
      pItem = pItem_1;
    }
    pGraphData_1 = pGraphData;
    v14 = v65 + 1;
  }
  bottom_1 = bottom;
  if ( bottom > 60 )
  {
    index = 0;
    if ( lprc_1[3] > 0 )
    {
      y = 0;
      do
      {
        if ( y >= bottom_1 )
          break;
        if ( !(index % 15) )
          sub_C20ED0(&BitmapItem, 0, y, right, y, 0x828282u, 0);
        ++index;
        y += 2;
        bottom_1 = bottom;
      }
      while ( index < lprc_1[3] );
      gdwVirtualScreenWidth = ::gdwVirtualScreenWidth;
    }
    pGraphData_1 = pGraphData;
  }
  nChildID = pGraphData_1->m_nChildID;
  while ( 1 )
  {
    v36 = nChildID - 1;
    v61 = v36;
    if ( v36 < 0 )
      break;
    v37 = pGraphData_1->m_nChildID - v36 - 1;
    v72 = -1;
    v38 = 0;
    v66 = v37;
    v64 = 0;
    if ( gdwVirtualScreenWidth > 0 )
    {
      v39 = 0;
      v60 = 0;
      a6 = right - 1;
      while ( 1 )
      {
        if ( v39 >= right + 1 )
          goto LABEL_108;
        v40 = pGraphData->m_Item[v37].pBuffer[(nGraphWidth + gdwVirtualScreenWidth - v38) % gdwVirtualScreenWidth];
        if ( v40 > v59 )
          v59 = pGraphData->m_Item[v37].pBuffer[(nGraphWidth + gdwVirtualScreenWidth - v38) % gdwVirtualScreenWidth];
        v41 = dbValue == 0.0 ? v40 / *(&pGraphData->m_dbMemorySize + 3 * v37) : v40 / dbValue;
        v42 = v41 * (double)bottom;
        v43 = bottom - (signed int)v42;
        v44 = v72;
        v65 = bottom - (signed int)v42;
        if ( v72 != -1 )
          break;
LABEL_107:
        a6 -= 2;
        v39 = v60 + 2;
        v37 = v66;
        v72 = v65;
        v38 = v64 + 1;
        v60 += 2;
        v64 = v38;
        if ( v38 >= gdwVirtualScreenWidth )
          goto LABEL_108;
      }
      pItem_1 = (tagGraphItem *)a6;
      v45 = a6 + 2;
      v57 = a6 + 2;
      v46 = bottom - (signed int)v42;
      v58 = *(&pGraphData->m_Color + 6 * v66);
      v47 = v72;
      if ( (a6 & 0x80000000) != 0 )
      {
        pItem_1 = 0;
        goto LABEL_73;
      }
      if ( (signed int)a6 >= BitmapItem.nWidth )
      {
        pItem_1 = (tagGraphItem *)(BitmapItem.nWidth - 1);
LABEL_73:
        v44 = v72;
      }
      if ( v45 >= 0 )
      {
        if ( v45 < BitmapItem.nWidth )
          v48 = v57;
        else
          v48 = BitmapItem.nWidth - 1;
      }
      else
      {
        v48 = 0;
      }
      if ( v43 >= 0 )
      {
        if ( v43 >= BitmapItem.nHeight )
          v46 = BitmapItem.nHeight - 1;
      }
      else
      {
        v46 = 0;
      }
      if ( v44 >= 0 )
      {
        if ( v44 >= BitmapItem.nHeight )
          v47 = BitmapItem.nHeight - 1;
      }
      else
      {
        v47 = 0;
      }
      sub_C20A90(&BitmapItem, v46, (int)pItem_1, v47, v48, v58, 0);
      v49 = v43 + 1;
      if ( v43 + 1 < bottom )
      {
        v50 = v72 + 1;
        pItem_1 = (tagGraphItem *)a6;
        if ( (a6 & 0x80000000) != 0 )
        {
          v51 = 0;
          goto LABEL_92;
        }
        if ( (signed int)a6 >= BitmapItem.nWidth )
        {
          v51 = (tagGraphItem *)(BitmapItem.nWidth - 1);
LABEL_92:
          pItem_1 = v51;
        }
        if ( v45 >= 0 )
        {
          if ( v45 >= BitmapItem.nWidth )
            v45 = BitmapItem.nWidth - 1;
        }
        else
        {
          v45 = 0;
        }
        if ( v49 >= 0 )
        {
          if ( v49 >= BitmapItem.nHeight )
            v49 = BitmapItem.nHeight - 1;
        }
        else
        {
          v49 = 0;
        }
        if ( v50 >= 0 )
        {
          if ( v50 >= BitmapItem.nHeight )
            v50 = BitmapItem.nHeight - 1;
        }
        else
        {
          v50 = 0;
        }
        sub_C20A90(&BitmapItem, v49, (int)pItem_1, v50, v45, *(&pGraphData->m_Color + 6 * v66), 0);
      }
      gdwVirtualScreenWidth = ::gdwVirtualScreenWidth;
      goto LABEL_107;
    }
LABEL_108:
    nChildID = v61;
    pGraphData_1 = pGraphData;
  }
  hBrush = CreateSolidBrush(0x828282u);
  rc = 0;
  v75 = right;
  v76 = bottom;
  v74 = 0;
  FrameRect((HDC)BitmapItem.CompatibleDC, (const RECT *)&rc, hBrush);
  DeleteObject = (void (__stdcall *)(HGDIOBJ))::DeleteObject;
  ::DeleteObject(hBrush);
  if ( hdc )
  {
    BitBlt(
      hdc,
      *lprc_1,
      lprc_1[1],
      BitmapItem.nWidth,
      BitmapItem.nHeight,
      (HDC)BitmapItem.CompatibleDC,
      0,
      0,
      0xCC0020u);
    hCompatibleDC = (HDC)BitmapItem.CompatibleDC;
LABEL_111:
    v53 = 0;
    goto __quit;
  }
  piconinfo.hbmColor = (HBITMAP)BitmapItem.hBitmapHandle;
  piconinfo.hbmMask = (HBITMAP)BitmapItem.hBitmapHandle;
  piconinfo.fIcon = 1;
  piconinfo.xHotspot = 0;
  piconinfo.yHotspot = 0;
  v53 = CreateIconIndirect(&piconinfo);
  hCompatibleDC = (HDC)BitmapItem.CompatibleDC;
__quit:
  if ( hCompatibleDC )
    DeleteDC(hCompatibleDC);
  if ( BitmapItem.hBitmapHandle )
    DeleteObject((HGDIOBJ)BitmapItem.hBitmapHandle);
  return v53;
}
// CD4E28: using guessed type int gdwVirtualScreenWidth;

//----- (00C21FD0) --------------------------------------------------------
int __cdecl sub_C21FD0(FILETIME *pFileTime, HDC hDC, #153 *lprc, COLORREF ColorBack)
{
  int nWidth; // eax
  signed int nHeight; // ecx
  COLORREF Color; // ebx
  unsigned int nSize; // ecx
  float v8; // xmm0_4
  int v9; // edi
  float v10; // xmm0_4
  int v11; // ebx
  HBRUSH hBrush; // esi
  int v13; // [esp+8h] [ebp-64h]
  int v14; // [esp+Ch] [ebp-60h]
  int v15; // [esp+10h] [ebp-5Ch]
  int v16; // [esp+14h] [ebp-58h]
  struct _FILETIME FileTime; // [esp+18h] [ebp-54h]
  int *v18; // [esp+20h] [ebp-4Ch]
  int nWidth_1; // [esp+24h] [ebp-48h]
  int nHeight_1; // [esp+28h] [ebp-44h]
  HDC hdc; // [esp+2Ch] [ebp-40h]
  BitmapItem BitmapItem; // [esp+30h] [ebp-3Ch]
  float pFileTime_1; // [esp+44h] [ebp-28h]
  struct _SYSTEMTIME SystemTime; // [esp+48h] [ebp-24h]
  int rc; // [esp+58h] [ebp-14h]
  int v26; // [esp+5Ch] [ebp-10h]
  int v27; // [esp+60h] [ebp-Ch]
  int v28; // [esp+64h] [ebp-8h]

  pFileTime_1 = *(float *)&pFileTime;
  nWidth = *((_DWORD *)lprc + 2) - *(_DWORD *)lprc;
  nHeight = *((_DWORD *)lprc + 3) - *((_DWORD *)lprc + 1);
  Color = ColorBack;
  if ( ColorBack == -1 )
    Color = gConfig.ColorGraphBk;
  hdc = hDC;
  v18 = (int *)lprc;
  BitmapItem.nHeight = 0;
  BitmapItem.nWidth = 0;
  BitmapItem.CompatibleDC = 0;
  BitmapItem.hBitmapHandle = 0;
  nWidth_1 = nWidth;
  nHeight_1 = nHeight;
  if ( !hDC || nWidth && nHeight )
  {
    BitmapItem_Create(&BitmapItem, nWidth, nHeight);
    nSize = BitmapItem.nHeight * BitmapItem.nWidth;
    if ( BitmapItem.pBits && nSize )
      memset32(
        BitmapItem.pBits,
        (unsigned __int16)(Color & 0xFF00) | ((unsigned __int8)Color << 16) | (Color >> 16) & 0xFF,
        nSize);
    GetSystemTime(&SystemTime);
    SystemTimeToFileTime(&SystemTime, &FileTime);
    v14 = 0;
    v8 = (double)(signed __int64)(*(_QWORD *)&FileTime - *(_QWORD *)LODWORD(pFileTime_1));
    pFileTime_1 = v8;
    v9 = nWidth_1;
    v10 = (double)(signed __int64)(*(_QWORD *)&FileTime - *(_QWORD *)&gCreateTimeLast);
    v11 = nHeight_1;
    v15 = nWidth_1;
    v16 = nHeight_1;
    v13 = nWidth_1 - (signed int)(float)((float)(pFileTime_1 / v10) * (float)nWidth_1);
    BitmapItem_SetRectColor(&BitmapItem, (#153 *)&v13, 0x9ECA9Eu);
    hBrush = CreateSolidBrush(0x828282u);
    rc = 0;
    v26 = 0;
    v27 = v9;
    v28 = v11;
    FrameRect((HDC)BitmapItem.CompatibleDC, (const RECT *)&rc, hBrush);
    DeleteObject(hBrush);
    BitBlt(hdc, *v18, v18[1], BitmapItem.nWidth, BitmapItem.nHeight, (HDC)BitmapItem.CompatibleDC, 0, 0, 0xCC0020u);
    if ( BitmapItem.CompatibleDC )
      DeleteDC((HDC)BitmapItem.CompatibleDC);
    nWidth = BitmapItem.hBitmapHandle;
    if ( BitmapItem.hBitmapHandle )
      nWidth = DeleteObject((HGDIOBJ)BitmapItem.hBitmapHandle);
  }
  return nWidth;
}

//----- (00C221A0) --------------------------------------------------------
int __cdecl GraphData_QueryData(CGraphData *pGraphData, double *pArg1, double *pArg2)
{
  int nWidth; // edi

  EnterCriticalSection(&pGraphData->m_Lock.m_Lock);
  nWidth = pGraphData->m_nWidth - 1;
  if ( nWidth < 0 )
    nWidth = gdwVirtualScreenWidth - 1;
  *pArg1 = pGraphData->m_Item[0].pBuffer[nWidth];
  if ( pArg2 && (signed int)pGraphData->m_nChildID > 1 )
    *pArg2 = pGraphData->m_Item[1].pBuffer[nWidth];
  LeaveCriticalSection(&pGraphData->m_Lock.m_Lock);
  return nWidth;
}
// CD4E28: using guessed type int gdwVirtualScreenWidth;

//----- (00C22200) --------------------------------------------------------
int __cdecl PE_FormatDouble(bool bFlags, wchar_t *pszText, unsigned int dwLength, long double dbValue1, long double dbValue2, long double dbValue3)
{
  char v6; // al
  char v7; // dl
  int offset; // esi
  double dbValue9; // xmm3_8
  double dbValue10; // xmm0_8
  double dbValue11; // xmm1_8
  double dbValue12; // xmm4_8
  double dbValue13; // xmm2_8
  double dbValue14; // xmm0_8
  double v15; // xmm1_8
  signed int index; // edi
  unsigned int dwLength_1; // ecx
  double dbValue18; // xmm0_8
  int nLength; // eax
  const wchar_t *v20; // eax
  char bRet1; // [esp+1Eh] [ebp-1Eh]
  char bRet2; // [esp+1Fh] [ebp-1Dh]
  double dbValue[3]; // [esp+20h] [ebp-1Ch]

  v6 = 0;
  v7 = 0;
  bRet1 = 0;
  offset = 0;
  bRet2 = 0;
  if ( !bFlags )
    return PE_FormatDoubleFlow(pszText, dwLength, dbValue1 + dbValue2);
  dbValue9 = dbValue3;
  dbValue10 = dbValue2;
  if ( dbValue3 <= dbValue2 )
    dbValue11 = dbValue3;
  else
    dbValue11 = dbValue2;
  if ( dbValue2 <= dbValue3 )
    dbValue10 = dbValue3;
  dbValue12 = dbValue1;
  if ( dbValue10 <= dbValue1 )
    dbValue13 = dbValue10;
  else
    dbValue13 = dbValue1;
  if ( dbValue1 > dbValue10 )
    dbValue10 = dbValue1;
  dbValue[0] = dbValue10;
  dbValue14 = dbValue13;
  if ( dbValue11 <= dbValue13 )
    dbValue13 = dbValue11;
  if ( dbValue14 <= dbValue11 )
    dbValue14 = dbValue11;
  v15 = ::dbValue3;
  *pszText = 0;
  index = 0;
  dwLength_1 = dwLength;
  dbValue[1] = dbValue14;
  dbValue[2] = dbValue13;
  do
  {
    dbValue18 = dbValue[index];
    if ( dbValue18 != v15 )
    {
      if ( offset > 0 )
      {
        dbValue18 = dbValue[index];
        dbValue9 = dbValue3;
        offset += swprintf_s(&pszText[offset], dwLength_1 - offset, L"\n");
        v15 = ::dbValue3;
        dbValue12 = dbValue1;
        dwLength_1 = dwLength;
        v6 = bRet1;
        v7 = bRet2;
      }
      if ( dbValue18 != dbValue2 || v7 )
      {
        if ( dbValue18 != dbValue12 || v6 )
        {
          nLength = swprintf_s(&pszText[offset], dwLength_1 - offset, L"O: ");
        }
        else
        {
          v20 = L"R";
          if ( dbValue9 == v15 )
            v20 = L"R+O";
          nLength = swprintf_s(&pszText[offset], dwLength_1 - offset, L"%s: ", v20);
          bRet1 = 1;
        }
      }
      else
      {
        nLength = swprintf_s(&pszText[offset], dwLength_1 - offset, L"W: ");
        bRet2 = 1;
      }
      dbValue9 = dbValue3;
      v15 = ::dbValue3;
      offset += PE_FormatDoubleFlow(&pszText[nLength + offset], dwLength - (nLength + offset), dbValue[index]) + nLength;
      dbValue12 = dbValue1;
      dwLength_1 = dwLength;
      v6 = bRet1;
      v7 = bRet2;
    }
    ++index;
  }
  while ( index < 3 );
  return offset;
}
// CACBB8: using guessed type wchar_t aR[2];
// CACBBC: using guessed type wchar_t aRO[4];

//----- (00C22410) --------------------------------------------------------
errno_t __cdecl sub_C22410(wchar_t *a1, rsize_t SizeInWords, int a3, __int64 a4)
{
  double v4; // xmm0_8
  const wchar_t *v6; // [esp+4h] [ebp-50h]
  wchar_t Dst; // [esp+10h] [ebp-44h]

  wcscpy_s(&Dst, 0x20u, L" KB");
  v4 = *(double *)&a4;
  if ( *(double *)&a4 > 1048576.0 )
  {
    v4 = *(double *)&a4 * 0.00000095367431640625;
    v6 = L" GB";
LABEL_5:
    wcscpy_s(&Dst, 0x20u, v6);
    goto LABEL_6;
  }
  if ( *(double *)&a4 > 1024.0 )
  {
    v4 = *(double *)&a4 * 0.0009765625;
    v6 = L" MB";
    goto LABEL_5;
  }
LABEL_6:
  swprintf_s(a1, SizeInWords, L"%s%0.1f", a3, LODWORD(v4), HIDWORD(v4));
  return wcscat_s(a1, SizeInWords, &Dst);
}
// CACBE0: using guessed type wchar_t aGb[4];

//----- (00C224C0) --------------------------------------------------------
void __cdecl GraphWnd_GenerateTipText(GraphWndTipText *TipTextInfo)
{
  wchar_t *v1; // edi
  __int16 v2; // si
  int v3; // esi
  CGraphData *pGraphData; // edx
  CGraphData *v5; // edx
  UINT v6; // eax
  __int16 *v7; // ecx
  __int16 v8; // ax
  wchar_t *v9; // eax
  int v10; // ecx
  CGraphData *v11; // eax
  int v12; // edx
  __int16 *v13; // ecx
  __int16 v14; // ax
  UINT v15; // ecx
  const wchar_t *v16; // eax
  CGraphData *v17; // ecx
  long double dbValue2; // ST14_8
  __int64 dbValue3; // [esp+10h] [ebp-2D4h]
  int dbValue3_4; // [esp+14h] [ebp-2D0h]
  int dbValue3_4a; // [esp+14h] [ebp-2D0h]
  struct _FILETIME LocalFileTime; // [esp+24h] [ebp-2C0h]
  FILETIME FileTime; // [esp+2Ch] [ebp-2B8h]
  __int16 *v24; // [esp+34h] [ebp-2B0h]
  struct _SYSTEMTIME SystemTime; // [esp+38h] [ebp-2ACh]
  struct tagRECT Rect; // [esp+48h] [ebp-29Ch]
  wchar_t Dst; // [esp+58h] [ebp-28Ch]
  WCHAR TimeStr; // [esp+260h] [ebp-84h]

  v1 = (wchar_t *)TipTextInfo->szText;
  TipTextInfo->szText[0] = 0;
  GetClientRect((HWND)TipTextInfo->hWnd, &Rect);
  v2 = TipTextInfo->x;
  if ( (Rect.right - v2 - 1) / 2 <= gdwVirtualScreenWidth )
  {
    EnterCriticalSection(&TipTextInfo->pGraphData->m_Lock.m_Lock);
    v3 = (TipTextInfo->pGraphData->m_nWidth - (Rect.right - TipTextInfo->x) / 2 + gdwVirtualScreenWidth - 1)
       % gdwVirtualScreenWidth;
    pGraphData = TipTextInfo->pGraphData;
    if ( !*(_QWORD *)&pGraphData->m_pBuffer1[v3] )
    {
LABEL_52:
      LeaveCriticalSection(&TipTextInfo->pGraphData->m_Lock.m_Lock);
      TipTextInfo->x += 20;
      TipTextInfo->y += 20;
      goto LABEL_53;
    }
    switch ( pGraphData->m_nItemID )
    {
      case 0u:
        wsprintfW(v1, L"CPU\n");
        break;
      case 2u:
        wsprintfW(v1, L"I/O\n");
        break;
      case 4u:
        wsprintfW(v1, L"GPU\n");
        break;
      case 8u:
        wsprintfW(v1, L"Disk\n");
        break;
      case 9u:
        wsprintfW(v1, L"Network\n");
        break;
      default:
        break;
    }
    v5 = TipTextInfo->pGraphData;
    if ( v5->m_pBuffer )
    {
      v6 = v5->m_nItemID;
      if ( !v6 || v6 == 4 )
      {
        v7 = TipTextInfo->szText;
        v24 = &TipTextInfo->szText[1];
        do
        {
          v8 = *v7;
          ++v7;
        }
        while ( v8 );
        sub_C20E00(
          (wchar_t *)&TipTextInfo->szText[v7 - v24],
          1024 - (v7 - v24),
          (int)&gszNullString,
          *(_QWORD *)&v5->m_Item[0].pBuffer[v3]);
        wcscat_s(v1, 0x400u, L"\n");
      }
      v9 = TipTextInfo->pGraphData->m_pBuffer[v3];
      if ( !v9 || !*v9 )
        goto LABEL_51;
    }
    else
    {
      if ( !v5->m_GraphData )
      {
        *v1 = 0;
        if ( *(_QWORD *)&v5->m_pBuffer1[v3] )
        {
          v15 = v5->m_nItemID;
          switch ( v15 )
          {
            case 0u:
            case 4u:
              v16 = L"GPU\n";
              dbValue3 = *(_QWORD *)&v5->m_Item[0].pBuffer[v3];
              if ( v15 != 4 )
                v16 = L"CPU\n";
              sub_C209F0(v1, (int)v16, dbValue3);
              break;
            case 1u:
              sub_C20A40(v1, (int)L"System Commit\n", *(_QWORD *)&v5->m_Item[0].pBuffer[v3]);
              break;
            case 2u:
              wsprintfW(v1, L"I/O\n");
              goto LABEL_48;
            case 3u:
              sub_C20A40(v1, (int)L"Physical Memory\n", *(_QWORD *)&v5->m_Item[0].pBuffer[v3]);
              break;
            case 5u:
              sub_C20A40(v1, (int)L"GPU System Memory\n", *(_QWORD *)&v5->m_Item[0].pBuffer[v3]);
              break;
            case 6u:
              sub_C20A40(v1, (int)L"GPU Dedicated Memory\n", *(_QWORD *)&v5->m_Item[0].pBuffer[v3]);
              break;
            case 7u:
              sub_C20A40(v1, (int)L"GPU Committed Memory\n", *(_QWORD *)&v5->m_Item[0].pBuffer[v3]);
              break;
            case 8u:
              wsprintfW(v1, L"Disk\n");
              goto LABEL_48;
            case 9u:
              wsprintfW(v1, L"Network\n");
LABEL_48:
              v17 = TipTextInfo->pGraphData;
              dbValue2 = v17->m_Item[1].pBuffer[v3];
              PE_FormatDouble(1, v1, 0x400u, v17->m_Item[0].pBuffer[v3] - dbValue2, dbValue2, -1.0);
              break;
            default:
              break;
          }
          if ( *v1 )
            wcscat_s(v1, 0x400u, L"\n");
        }
        goto LABEL_51;
      }
      dbValue3_4 = v5->m_ProcessorID;
      if ( v5->m_nItemID == 4 )
      {
        wsprintfW(v1, L"GPU Engine %d: ", dbValue3_4);
      }
      else
      {
        v10 = wsprintfW(v1, L"CPU %d", dbValue3_4);
        v11 = TipTextInfo->pGraphData;
        v12 = v11->NodeCoreMode;
        if ( v12 != -1 )
        {
          dbValue3_4a = v11->NodeCount;
          if ( v12 == 1 )
            swprintf_s((wchar_t *)&TipTextInfo->szText[v10], 1024 - v10, L" (Node %d)", dbValue3_4a);
          else
            swprintf_s((wchar_t *)&TipTextInfo->szText[v10], 1024 - v10, L" (Core %d)", dbValue3_4a);
        }
      }
      wcscat_s(v1, 0x400u, L" ");
      v13 = TipTextInfo->szText;
      do
      {
        v14 = *v13;
        ++v13;
      }
      while ( v14 );
      sub_C20E00(
        (wchar_t *)&TipTextInfo->szText[v13 - &TipTextInfo->szText[1]],
        1024 - (v13 - &TipTextInfo->szText[1]),
        (int)&gszNullString,
        *(_QWORD *)&TipTextInfo->pGraphData->m_Item[0].pBuffer[v3]);
      if ( !TipTextInfo->pGraphData->m_GraphData->m_pBuffer[v3] )
      {
LABEL_51:
        FileTime = (FILETIME)(*(_QWORD *)&TipTextInfo->pGraphData->m_Time
                            + 10000000i64 * TipTextInfo->pGraphData->m_pBuffer1[v3]);
        FileTimeToLocalFileTime(&FileTime, &LocalFileTime);
        FileTimeToSystemTime(&LocalFileTime, &SystemTime);
        GetTimeFormatW(0x400u, 0, &SystemTime, 0, &TimeStr, 64);
        wcscat_s(v1, 0x400u, &TimeStr);
        goto LABEL_52;
      }
      if ( *v1 )
        wcscat_s(v1, 0x400u, L"\n");
      wcscpy_s(&Dst, 0x104u, TipTextInfo->pGraphData->m_GraphData->m_pBuffer[v3]);
      if ( wcschr(&Dst, 0xAu) )
        *wcschr(&Dst, 0xAu) = 32;
      v9 = &Dst;
    }
    wcscat_s(v1, 0x400u, v9);
    wcscat_s(v1, 0x400u, L"\n");
    goto LABEL_51;
  }
  TipTextInfo->y += 10;
  TipTextInfo->x = v2 + 10;
LABEL_53:
  TipTextInfo->bValid = 1;
}
// CACC54: using guessed type wchar_t aCpu[5];
// CACC9C: using guessed type wchar_t aNodeD[11];
// CACCCC: using guessed type wchar_t aPhysicalMemory[17];
// CACCF0: using guessed type wchar_t aSystemCommit[15];
// CACD10: using guessed type wchar_t aGpuDedicatedMe[22];
// CACD3C: using guessed type wchar_t aGpuSystemMemor[19];
// CACD64: using guessed type wchar_t aGpuCommittedMe[22];
// CD4E28: using guessed type int gdwVirtualScreenWidth;

//----- (00C22A70) --------------------------------------------------------
int __cdecl sub_C22A70(HWND hWnd)
{
  HWND v1; // esi
  HWND v2; // edi
  HWND i; // eax
  int result; // eax
  HWND v5; // [esp+Ch] [ebp-4h]

  v1 = hWnd;
  if ( GetParent(hWnd) )
  {
    v1 = GetParent(hWnd);
    v2 = GetParent(v1);
  }
  else
  {
    v2 = v5;
  }
  if ( !IsWindowVisible(v1) )
    goto LABEL_13;
  for ( i = GetFocus(); v1 != i; i = GetParent(i) )
  {
    if ( v2 == i )
      break;
    if ( !i )
      goto LABEL_13;
  }
  if ( i && (v1 == i || v2 == i) )
    result = 1;
  else
LABEL_13:
    result = 0;
  return result;
}

//----- (00C22AE0) --------------------------------------------------------
PerformanceInfo *__thiscall PerformanceInfo::PerformanceInfo(PerformanceInfo *this, HKEY hSubKey)
{
  HKEY Flags; // eax
  PerformanceInfo *pThis; // edi
  const WCHAR *szPerfValueName; // esi
  const WCHAR *szValueName; // ebx
  BYTE *v7; // eax
  WCHAR **v8; // ecx
  const WCHAR *psz; // esi
  int i; // ebx
  unsigned int dwCounter; // eax
  const WCHAR *psz1; // esi
  DWORD cbData; // [esp+Ch] [ebp-8h]
  DWORD cbData_1; // [esp+10h] [ebp-4h]

  Flags = hSubKey;
  pThis = this;
  this->m_dwLastCounterOfLastHelp = 0;
  this->m_LastCounterOfLastHelp = 0;
  this->m_PerfValue = 0;
  if ( Flags )
  {
    if ( Flags != (HKEY)1 )
      return pThis;
    szPerfValueName = L"Explain 009";
    szValueName = L"Last Help";
  }
  else
  {
    szPerfValueName = L"Counter 009";
    szValueName = L"Last Counter";
  }
  hSubKey = 0;
  cbData = 4;
  if ( !RegOpenKeyExW(
          HKEY_LOCAL_MACHINE,
          L"software\\microsoft\\windows nt\\currentversion\\perflib",
          0,
          KEY_READ,
          &hSubKey) )
  {
    if ( RegQueryValueExW(hSubKey, szValueName, 0, 0, (LPBYTE)pThis, &cbData) )
    {
      RegCloseKey(hSubKey);
      return pThis;
    }
    RegCloseKey(hSubKey);
    if ( !RegQueryValueExW(HKEY_PERFORMANCE_DATA, szPerfValueName, 0, 0, 0, &cbData_1) )
    {
      v7 = (BYTE *)operator new[](2 * cbData_1);
      pThis->m_PerfValue = (WCHAR *)v7;
      if ( RegQueryValueExW(HKEY_PERFORMANCE_DATA, szPerfValueName, 0, 0, v7, &cbData_1)
        || (v8 = (WCHAR **)operator new[](4 * (pThis->m_dwLastCounterOfLastHelp + 1)),
            (pThis->m_LastCounterOfLastHelp = v8) == 0) )
      {
        operator delete[](pThis->m_PerfValue);
        return pThis;
      }
      memset(v8, 0, 4 * pThis->m_dwLastCounterOfLastHelp + 4);
      psz = pThis->m_PerfValue;
      for ( i = lstrlenW(pThis->m_PerfValue); i; i = lstrlenW(psz) )
      {
        dwCounter = _wtoi(psz);
        if ( dwCounter > pThis->m_dwLastCounterOfLastHelp )
          break;
        psz1 = &psz[i + 1];
        pThis->m_LastCounterOfLastHelp[dwCounter] = (WCHAR *)psz1;
        psz = &psz1[lstrlenW(psz1) + 1];
      }
    }
  }
  return pThis;
}
// CACE14: using guessed type wchar_t aExplain009[12];
// CACE2C: using guessed type wchar_t aLastHelp[10];

//----- (00C22C80) --------------------------------------------------------
void __thiscall PerformanceInfo::~PerformanceInfo(void **this)
{
  void **v1; // esi
  void *v2; // ST00_4

  v1 = this;
  operator delete[](this[1]);
  v2 = v1[2];
  v1[1] = 0;
  operator delete[](v2);
  v1[2] = 0;
  *v1 = 0;
}

//----- (00C22CB0) --------------------------------------------------------
int __thiscall PerformanceInfo::FindPerf(PerformanceInfo *pThis, LPCWSTR lpszName)
{
  PerformanceInfo *this; // edi
  signed int index; // esi

  this = pThis;
  if ( IsBadStringPtrW(lpszName, 0xFFFFFFFF) || !this->m_dwLastCounterOfLastHelp || !this->m_LastCounterOfLastHelp )
    return 0;
  index = 1;
  if ( this->m_dwLastCounterOfLastHelp < 1u )
    return 0;
  while ( !this->m_LastCounterOfLastHelp[index] || _wcsicmp(lpszName, this->m_LastCounterOfLastHelp[index]) )
  {
    if ( (unsigned int)++index > this->m_dwLastCounterOfLastHelp )
      return 0;
  }
  return index;
}

//----- (00C22D20) --------------------------------------------------------
int __thiscall sub_C22D20(unsigned int *this, unsigned int a2)
{
  int result; // eax

  if ( a2 <= *this )
    result = *(_DWORD *)(this[1] + 4 * a2);
  else
    result = 0;
  return result;
}

//----- (00C22D40) --------------------------------------------------------
LRESULT __cdecl HandleCmdHandler(int a1, HWND hWnd, WPARAM wParam, LPARAM lParam)
{
  int v4; // ecx
  int v5; // esi
  LRESULT result; // eax

  v4 = 0;
  v5 = *(_DWORD *)(a1 + 4);
  if ( *(_DWORD *)a1 <= 0 )
  {
LABEL_4:
    switch ( *(_DWORD *)(a1 + 8) )
    {
      case 1:
        result = DefWindowProcW(hWnd, 0x111u, wParam, lParam);
        break;
      case 2:
        result = DefDlgProcW(hWnd, 0x111u, wParam, lParam);
        break;
      case 3:
        result = DefMDIChildProcW(hWnd, 0x111u, wParam, lParam);
        break;
      case 4:
        result = DefFrameProcW(hWnd, 0, 0x111u, wParam, lParam);
        break;
      default:
        result = 0;
        break;
    }
  }
  else
  {
    while ( *(_WORD *)(v5 + 8 * v4) != (_WORD)wParam )
    {
      if ( ++v4 >= *(_DWORD *)a1 )
        goto LABEL_4;
    }
    result = (*(int (__cdecl **)(HWND, WPARAM, WPARAM, LPARAM))(v5 + 8 * v4 + 4))(hWnd, wParam, wParam >> 16, lParam);
  }
  return result;
}

//----- (00C22E00) --------------------------------------------------------
LRESULT __cdecl HandleMsgHandler(tagMSGHANDLER *pMsgHander, HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
  int nIndex; // eax
  PMSGFUNC WindowMsgFunc; // esi
  LRESULT result; // eax

  nIndex = 0;
  WindowMsgFunc = pMsgHander->WindowMsgFunc;
  if ( (signed int)pMsgHander->nLength <= 0 )
  {
LABEL_4:
    switch ( pMsgHander->Flags )
    {
      case 1:
        result = DefWindowProcW(hWnd, Msg, wParam, lParam);
        break;
      case 2:
        result = DefDlgProcW(hWnd, Msg, wParam, lParam);
        break;
      case 3:
        result = DefMDIChildProcW(hWnd, Msg, wParam, lParam);
        break;
      case 4:
        result = DefFrameProcW(hWnd, 0, Msg, wParam, lParam);
        break;
      default:
        result = 0;
        break;
    }
  }
  else
  {
    while ( WindowMsgFunc[nIndex].msg != Msg )
    {
      if ( ++nIndex >= (signed int)pMsgHander->nLength )
        goto LABEL_4;
    }
    result = ((int (__cdecl *)(HWND, UINT, WPARAM, LPARAM))WindowMsgFunc[nIndex].pfn)(hWnd, Msg, wParam, lParam);
  }
  return result;
}

//----- (00C22EC0) --------------------------------------------------------
bool __cdecl CDriver::SaveDriverFromResource(LPCWSTR lpName, const wchar_t *lpszFileName)
{
  HRSRC hRsrc; // eax
  HRSRC hRsrc_1; // edi
  HGLOBAL hGlobal; // esi
  DWORD dwSize; // edi
  const void *pBuffer; // esi
  FILE *pFile; // [esp+4h] [ebp-4h]

  hRsrc = FindResourceW(0, lpName, L"BINRES");
  hRsrc_1 = hRsrc;
  if ( !hRsrc )
    return 0;
  hGlobal = LoadResource(0, hRsrc);
  dwSize = SizeofResource(0, hRsrc_1);
  pBuffer = LockResource(hGlobal);
  if ( _wfopen_s(&pFile, lpszFileName, L"wb") )
    return 0;
  fwrite(pBuffer, 1u, dwSize, pFile);
  fclose(pFile);
  return 1;
}

//----- (00C22F50) --------------------------------------------------------
BOOL __cdecl CDriver::OpenEx(const WCHAR *lpszDriverName, WCHAR *lpszPathName, PHANDLE DriverHandle)
{
  BOOL result; // eax
  HMODULE v4; // eax
  FARPROC RtlInitUnicodeString; // eax
  HMODULE v6; // eax
  WCHAR *v7; // esi
  DWORD (__stdcall *v8)(LONG); // eax
  HMODULE v9; // eax
  DWORD v10; // eax
  HANDLE v11; // eax
  UNICODE_STRING strKeyName; // [esp+8h] [ebp-A40h]
  WCHAR *lpszPathName_1; // [esp+10h] [ebp-A38h]
  HKEY hKey; // [esp+14h] [ebp-A34h]
  DWORD dwValue; // [esp+18h] [ebp-A30h]
  WCHAR szSubKeyName[260]; // [esp+1Ch] [ebp-A2Ch]
  WCHAR szBuffer[260]; // [esp+224h] [ebp-824h]
  WCHAR FileName[260]; // [esp+42Ch] [ebp-61Ch]
  WCHAR pszBuffer[260]; // [esp+634h] [ebp-414h]
  WCHAR szKeyName[260]; // [esp+83Ch] [ebp-20Ch]

  lpszPathName_1 = lpszPathName;
  TmAdjustPrivilege(L"SeLoadDriverPrivilege");
  swprintf(szKeyName, L"System\\CurrentControlSet\\Services\\%s", lpszDriverName);
  if ( RegCreateKeyW(HKEY_LOCAL_MACHINE, szKeyName, &hKey) )
    return 0;
  dwValue = 1;
  RegSetValueExW(hKey, L"Type", 0, REG_DWORD, (const BYTE *)&dwValue, 4u);
  dwValue = 1;
  RegSetValueExW(hKey, L"ErrorControl", 0, REG_DWORD, (const BYTE *)&dwValue, 4u);
  dwValue = 3;
  RegSetValueExW(hKey, L"Start", 0, REG_DWORD, (const BYTE *)&dwValue, 4u);
  swprintf(szBuffer, L"\\??\\%s", lpszPathName_1);
  RegSetValueExW(hKey, L"ImagePath", 0, REG_SZ, (const BYTE *)szBuffer, 2 * wcslen(szBuffer));
  RegCloseKey(hKey);
  v4 = GetModuleHandleW(L"ntdll.dll");
  lpszPathName_1 = (WCHAR *)GetProcAddress(v4, "NtLoadDriver");
  swprintf(szSubKeyName, L"\\Registry\\Machine\\System\\CurrentControlSet\\Services\\%s", lpszDriverName);
  RtlInitUnicodeString = *(FARPROC *)gpfnRtlInitUnicodeString;
  if ( !*(_DWORD *)gpfnRtlInitUnicodeString )
  {
    v6 = GetModuleHandleW(L"ntdll.dll");
    RtlInitUnicodeString = GetProcAddress(v6, "RtlInitUnicodeString");
    *(_DWORD *)gpfnRtlInitUnicodeString = RtlInitUnicodeString;
  }
  ((void (__stdcall *)(UNICODE_STRING *, WCHAR *))RtlInitUnicodeString)(&strKeyName, szSubKeyName);
  lpszPathName_1 = (WCHAR *)((int (__stdcall *)(UNICODE_STRING *))lpszPathName_1)(&strKeyName);
  swprintf(pszBuffer, L"%s\\Enum", szKeyName);
  RegDeleteKeyW(HKEY_LOCAL_MACHINE, pszBuffer);
  swprintf(pszBuffer, L"%s\\Security", szKeyName);
  RegDeleteKeyW(HKEY_LOCAL_MACHINE, pszBuffer);
  RegDeleteKeyW(HKEY_LOCAL_MACHINE, szKeyName);
  v7 = lpszPathName_1;
  if ( lpszPathName_1 && lpszPathName_1 != (WCHAR *)STATUS_IMAGE_ALREADY_LOADED )
  {
    v8 = gpfnRtlNtStatusToDosError;
    if ( !gpfnRtlNtStatusToDosError )
    {
      v9 = GetModuleHandleW(L"ntdll.dll");
      v8 = (DWORD (__stdcall *)(LONG))GetProcAddress(v9, "RtlNtStatusToDosError");
      gpfnRtlNtStatusToDosError = v8;
    }
    v10 = v8((LONG)v7);
    SetLastError(v10);
    result = 0;
  }
  else
  {
    swprintf(FileName, L"\\\\.\\%s", lpszDriverName);
    v11 = CreateFileW(FileName, GENERIC_WRITE|GENERIC_READ, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
    *DriverHandle = v11;
    if ( v11 == (HANDLE)-1 )
    {
      swprintf(FileName, L"\\\\.\\Global\\%s", lpszDriverName);
      *DriverHandle = CreateFileW(FileName, GENERIC_WRITE|GENERIC_READ, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
    }
    result = (char *)*DriverHandle + 1 != 0;
  }
  return result;
}

//----- (00C23260) --------------------------------------------------------
BOOL __cdecl CDriver::Open(const WCHAR *lpszDriverName, PHANDLE DriverHandle)
{
  HANDLE Handle; // eax
  WCHAR szFileName[260]; // [esp+8h] [ebp-20Ch]

  swprintf(szFileName, L"\\\\.\\%s", lpszDriverName);
  Handle = CreateFileW(szFileName, GENERIC_WRITE|GENERIC_READ, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
  *DriverHandle = Handle;
  if ( Handle == (HANDLE)INVALID_HANDLE_VALUE )
  {
    swprintf(szFileName, L"\\\\.\\Global\\%s", lpszDriverName);
    *DriverHandle = CreateFileW(szFileName, GENERIC_WRITE|GENERIC_READ, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
  }
  return (char *)*DriverHandle + 1 != 0;
}

//----- (00C23310) --------------------------------------------------------
_DWORD *__stdcall sub_C23310(_DWORD *a1, _DWORD *a2, _DWORD *a3)
{
  _DWORD *result; // eax

  result = std::_List_alloc<std::_List_base_types<_LUID,std::allocator<_LUID>>>::_Buynode0(a1, a2);
  if ( result != (_DWORD *)-8 )
  {
    result[2] = *a3;
    result[3] = a3[1];
  }
  return result;
}

//----- (00C23340) --------------------------------------------------------
char __cdecl sub_C23340(HANDLE ProcessHandle, int a2, int a3, int time, int time_4, tagTREEVIEWLISTITEMPARAM *pItemParam, WPARAM wParam)
{
  tagTREEVIEWLISTITEMPARAM *pItemParam_1; // ecx
  unsigned int v8; // edi
  std__list_node_for_AdapterLuid *_Node; // esi
  int v10; // ebx
  ULONG NodeIndex; // ebx
  signed int fDone; // edi
  int v13; // eax
  HANDLE ProcessHandle_1; // ebx
  ULONG NbSegmentIndex; // edi
  ULONG v16; // eax
  int v17; // esi
  int v18; // edx
  int v19; // eax
  float v20; // xmm2_4
  float v21; // xmm0_4
  float v22; // ST4C_4
  float v23; // ST40_4
  float v24; // xmm0_4
  HWND hWndTreeListView; // ST14_4
  bool v26; // al
  char v27; // ST57_1
  HWND v28; // ST14_4
  unsigned __int8 v29; // al
  char v30; // ST57_1
  float v31; // xmm0_4
  HWND v32; // ST14_4
  unsigned __int8 v33; // al
  char v34; // ST57_1
  float v35; // xmm0_4
  HWND v36; // ST14_4
  unsigned __int8 v37; // al
  char v38; // ST57_1
  float v39; // xmm0_4
  int v41; // [esp+24h] [ebp-FD0h]
  unsigned int NodeSum; // [esp+28h] [ebp-FCCh]
  int CommitLimitSum; // [esp+2Ch] [ebp-FC8h]
  ULONG NodeCount; // [esp+38h] [ebp-FBCh]
  int v45; // [esp+3Ch] [ebp-FB8h]
  int v46; // [esp+40h] [ebp-FB4h]
  int NbSegmentsSum; // [esp+44h] [ebp-FB0h]
  char v48; // [esp+4Fh] [ebp-FA5h]
  _D3DKMT_QUERYSTATISTICS Statistics3; // [esp+50h] [ebp-FA4h]
  _D3DKMT_QUERYSTATISTICS Statistics2; // [esp+370h] [ebp-C84h]
  _D3DKMT_QUERYSTATISTICS Statistics4; // [esp+690h] [ebp-964h]
  _D3DKMT_QUERYSTATISTICS Statistics5; // [esp+9B0h] [ebp-644h]
  _D3DKMT_QUERYSTATISTICS Statistics1; // [esp+CD0h] [ebp-324h]

  pItemParam_1 = pItemParam;
  v48 = 0;
  v8 = 0;
  _Node = (std__list_node_for_AdapterLuid *)gAdapterList._Mypair._Myval2._Myhead->_Next;
  v10 = 0;
  NodeSum = 0;
  v46 = 0;
  v45 = 0;
  v41 = 0;
  if ( gAdapterList._Mypair._Myval2._Myhead->_Next == gAdapterList._Mypair._Myval2._Myhead )
  {
    v17 = 0;
  }
  else
  {
    CommitLimitSum = 0;
    NbSegmentsSum = 0;
    do
    {
      memset(&Statistics1, 0, sizeof(_D3DKMT_QUERYSTATISTICS));
      Statistics1.Type = 0;
      Statistics1.AdapterLuid.LowPart = _Node->_Myval.LowPart;
      Statistics1.AdapterLuid.HighPart = _Node->_Myval.HighPart;
      if ( !D3DKMTQueryStatistics(&Statistics1) )
      {
        NodeIndex = 0;
        NodeCount = Statistics1.QueryResult.AdapterInformation.NodeCount;
        if ( Statistics1.QueryResult.AdapterInformation.NodeCount )
        {
          fDone = 1;
          do
          {
            memset(&Statistics2, 0, sizeof(_D3DKMT_QUERYSTATISTICS));
            Statistics2.Type = D3DKMT_QUERYSTATISTICS_PROCESS_NODE;
            Statistics2.AdapterLuid.LowPart = _Node->_Myval.LowPart;
            Statistics2.AdapterLuid.HighPart = _Node->_Myval.HighPart;
            Statistics2.hProcess = ProcessHandle;
            Statistics2.QuerySegment.SegmentId = NodeIndex;
            if ( !D3DKMTQueryStatistics(&Statistics2) && fDone & gConfig.dwGpuNodeUsageMask )
            {
              ++NodeSum;
              v13 = (Statistics2.QueryResult.SegmentInformation.CommitLimit + __PAIR__(CommitLimitSum, NbSegmentsSum)) >> 32;
              NbSegmentsSum += Statistics2.QueryResult.AdapterInformation.NbSegments;
              CommitLimitSum = v13;
            }
            ++NodeIndex;
            fDone = __ROL4__(fDone, 1);
          }
          while ( NodeIndex < NodeCount );
        }
        if ( v48 )
        {
          ProcessHandle_1 = ProcessHandle;
        }
        else
        {
          memset(&Statistics3, 0, sizeof(_D3DKMT_QUERYSTATISTICS));
          ProcessHandle_1 = ProcessHandle;
          Statistics3.Type = D3DKMT_QUERYSTATISTICS_PROCESS;
          Statistics3.hProcess = ProcessHandle;
          Statistics3.AdapterLuid.LowPart = _Node->_Myval.LowPart;
          Statistics3.AdapterLuid.HighPart = _Node->_Myval.HighPart;
          if ( !D3DKMTQueryStatistics(&Statistics3) )
          {
            v41 = Statistics3.QueryResult.AdapterInformation.VidPnSourceCount >> 10;
            v48 = 1;
          }
        }
        NbSegmentIndex = 0;
        if ( Statistics1.QueryResult.AdapterInformation.NbSegments )
        {
          do
          {
            memset(&Statistics4, 0, sizeof(_D3DKMT_QUERYSTATISTICS));
            Statistics4.Type = D3DKMT_QUERYSTATISTICS_PROCESS_SEGMENT;
            Statistics4.hProcess = ProcessHandle_1;
            Statistics4.AdapterLuid.LowPart = _Node->_Myval.LowPart;
            Statistics4.AdapterLuid.HighPart = _Node->_Myval.HighPart;
            Statistics4.QuerySegment.SegmentId = NbSegmentIndex;
            if ( D3DKMTQueryStatistics(&Statistics4) )
              goto __Next;
            memset(&Statistics5, 0, sizeof(_D3DKMT_QUERYSTATISTICS));
            Statistics5.Type = D3DKMT_QUERYSTATISTICS_SEGMENT;
            Statistics5.AdapterLuid.LowPart = _Node->_Myval.LowPart;
            Statistics5.AdapterLuid.HighPart = _Node->_Myval.HighPart;
            Statistics5.QuerySegment.SegmentId = NbSegmentIndex;
            if ( D3DKMTQueryStatistics(&Statistics5) )
              goto __Next;
            v16 = Statistics4.QueryResult.AdapterInformation.NbSegments >> 10;
            if ( gdwVersion < 3 )
            {
              if ( Statistics5.QueryResult.SegmentInformationV1.Aperture )
              {
LABEL_22:
                v45 += v16;
                goto __Next;
              }
              v46 += v16;
            }
            else
            {
              if ( Statistics5.QueryResult.AdapterInformation.ReferenceDmaBuffer.NbCall )
                goto LABEL_22;
              v46 += v16;
            }
__Next:
            ++NbSegmentIndex;
          }
          while ( NbSegmentIndex < Statistics1.QueryResult.AdapterInformation.NbSegments );
        }
      }
      _Node = (std__list_node_for_AdapterLuid *)_Node->_Next;
    }
    while ( _Node != (std__list_node_for_AdapterLuid *)gAdapterList._Mypair._Myval2._Myhead );
    v8 = NodeSum;
    v10 = CommitLimitSum;
    v17 = NbSegmentsSum;
    pItemParam_1 = pItemParam;
  }
  v18 = pItemParam_1->field_578;
  v19 = pItemParam_1->field_57C;
  if ( v17 != v18 || v10 != v19 )
  {
    v21 = (double)(__PAIR__(v10, v17) - __PAIR__(v19, v18));
    v22 = v21;
    v23 = (double)v8;
    v24 = (double)__PAIR__(a3, a2);
    v20 = (float)(v22 / (float)(v23 * v24)) * 100.0;
    if ( v20 >= 0.0 )
    {
      if ( v20 > 100.0 )
        v20 = 100.0;
    }
    else
    {
      v20 = 0.0;
    }
  }
  else
  {
    v20 = 0.0;
  }
  pItemParam->field_578 = v17;
  pItemParam->field_57C = v10;
  hWndTreeListView = ghWndTreeListView;
  v26 = sub_C6F8F0(v20, (double *)&pItemParam->m_Gpu2);
  v27 = RedrawColumn(v26, hWndTreeListView, IDS_GPU2, wParam);
  CGraphData_Update(
    pItemParam->pGraphData4,
    (FILETIME)__PAIR__(time_4, time),
    (float)*(double *)&pItemParam->m_Gpu2,
    0.0,
    0);
  v28 = ghWndTreeListView;
  v29 = sub_C6F920(v41, 0, &pItemParam->m_GpuCommitedByes);
  v30 = RedrawColumn(v29, v28, IDS_GPU_COMMITTED_BYTES, wParam) | v27;
  v31 = (double)pItemParam->m_GpuCommitedByes;
  CGraphData_Update(pItemParam->pGraphData5, (FILETIME)__PAIR__(time_4, time), v31, 0.0, 0);
  v32 = ghWndTreeListView;
  v33 = sub_C6F920(v45, 0, &pItemParam->m_GpuSystemBytes);
  v34 = RedrawColumn(v33, v32, IDS_GPU_SYSTEM_BYTES, wParam) | v30;
  v35 = (double)pItemParam->m_GpuSystemBytes;
  CGraphData_Update((CGraphData *)pItemParam->pGraphData6, (FILETIME)__PAIR__(time_4, time), v35, 0.0, 0);
  v36 = ghWndTreeListView;
  v37 = sub_C6F920(v46, 0, &pItemParam->m_GpuDedicatedBytes);
  v38 = RedrawColumn(v37, v36, IDS_GPU_DEDICATED_BYTES, wParam) | v34;
  v39 = (double)pItemParam->m_GpuDedicatedBytes;
  CGraphData_Update(pItemParam->pGraphData7, (FILETIME)__PAIR__(time_4, time), v39, 0.0, 0);
  return v38;
}
// CACDC0: using guessed type double db_onehundred;
// CD4E54: using guessed type int gdwVersion;

//----- (00C238F0) --------------------------------------------------------
void __cdecl sub_C238F0(FILETIME time, signed __int64 a2, int a3, int a4, int a5, CGraphData *a6, CGraphData *a7)
{
  unsigned int v7; // ecx
  unsigned int v8; // ebx
  std__list_node *v9; // esi
  unsigned int v10; // edi
  ULONG v11; // edi
  signed int v12; // ebx
  int v13; // eax
  bool v14; // zf
  ULONG v15; // ebx
  ULONG v16; // edi
  float v17; // xmm0_4
  float v18; // ST64_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  int v21; // edi
  ULONG v22; // edi
  unsigned int v23; // eax
  ULONG v24; // ecx
  ULONG v25; // eax
  float v26; // xmm0_4
  float v27; // ST7C_4
  float v28; // ST58_4
  float v29; // xmm0_4
  float v30; // xmm0_4
  WCHAR *v31; // eax
  float v32; // xmm1_4
  float v33; // xmm1_4
  __int64 ArgList_4; // [esp+10h] [ebp-11D4h]
  int a5_4; // [esp+18h] [ebp-11CCh]
  int v36; // [esp+1Ch] [ebp-11C8h]
  ULONG v37; // [esp+38h] [ebp-11ACh]
  unsigned int v38; // [esp+40h] [ebp-11A4h]
  signed int v39; // [esp+48h] [ebp-119Ch]
  unsigned int v40; // [esp+50h] [ebp-1194h]
  ULONG v41; // [esp+58h] [ebp-118Ch]
  unsigned int v42; // [esp+5Ch] [ebp-1188h]
  unsigned int v43; // [esp+68h] [ebp-117Ch]
  unsigned int v44; // [esp+6Ch] [ebp-1178h]
  unsigned int v45; // [esp+70h] [ebp-1174h]
  int v46; // [esp+74h] [ebp-1170h]
  unsigned int v47; // [esp+78h] [ebp-116Ch]
  int v48; // [esp+7Ch] [ebp-1168h]
  float v49; // [esp+7Ch] [ebp-1168h]
  _D3DKMT_QUERYSTATISTICS Statitcs2; // [esp+80h] [ebp-1164h]
  _D3DKMT_QUERYSTATISTICS Statitcs; // [esp+3A0h] [ebp-E44h]
  _D3DKMT_QUERYSTATISTICS Statitcs3; // [esp+6C0h] [ebp-B24h]
  WCHAR szBuffer[1024]; // [esp+9E0h] [ebp-804h]

  v40 = 0;
  szBuffer[0] = 0;
  v46 = 0;
  memset(&szBuffer[1], 0, 2046u);
  v7 = 0;
  v8 = 0;
  v9 = gAdapterList._Mypair._Myval2._Myhead->_Next;
  v10 = 0;
  v42 = 0;
  if ( gAdapterList._Mypair._Myval2._Myhead->_Next == gAdapterList._Mypair._Myval2._Myhead )
  {
    v43 = 0;
    v44 = 0;
    v49 = 0.0;
  }
  else
  {
    v45 = 0;
    v43 = 0;
    v44 = 0;
    v38 = 0;
    v47 = 0;
    do
    {
      memset(&Statitcs, 0, sizeof(_D3DKMT_QUERYSTATISTICS));
      Statitcs.Type = D3DKMT_QUERYSTATISTICS_ADAPTER;
      Statitcs.AdapterLuid.LowPart = (DWORD)v9->_Myval;
      Statitcs.AdapterLuid.HighPart = (LONG)v9[1]._Next;
      if ( !D3DKMTQueryStatistics(&Statitcs) )
      {
        v11 = 0;
        v41 = Statitcs.QueryResult.AdapterInformation.NodeCount;
        v37 = 0;
        if ( Statitcs.QueryResult.AdapterInformation.NodeCount )
        {
          v12 = 1;
          v39 = 1;
          v13 = a5 + 0x888 + 0x898 * v46;
          v46 += Statitcs.QueryResult.NodeInformation.GlobalInformation.RunningTime.HighPart;
          v48 = v13;
          do
          {
            memset(&Statitcs2, 0, sizeof(_D3DKMT_QUERYSTATISTICS));
            Statitcs2.Type = D3DKMT_QUERYSTATISTICS_NODE;
            Statitcs2.AdapterLuid.LowPart = (DWORD)v9->_Myval;
            Statitcs2.AdapterLuid.HighPart = (LONG)v9[1]._Next;
            Statitcs2.QuerySegment.SegmentId = v11;
            if ( D3DKMTQueryStatistics(&Statitcs2) )
            {
              v15 = 0;
              v16 = 0;
            }
            else
            {
              v14 = (v12 & gConfig.dwGpuNodeUsageMask) == 0;
              v15 = Statitcs2.QueryResult.AdapterInformation.NodeCount;
              v16 = Statitcs2.QueryResult.AdapterInformation.NbSegments;
              if ( !v14 )
              {
                ++v40;
                v42 = (Statitcs2.QueryResult.SegmentInformation.CommitLimit + __PAIR__(v42, v45)) >> 32;
                v45 += Statitcs2.QueryResult.AdapterInformation.NbSegments;
              }
            }
            if ( a5 )
            {
              if ( v15 | v16 && *(_QWORD *)v48 )
              {
                v17 = (double)(signed __int64)(__PAIR__(v15, v16) - *(_QWORD *)v48);
                v18 = v17;
                v19 = (double)a2;
                v20 = (float)(v18 / v19) * 100.0;
              }
              else
              {
                v20 = 0.0;
              }
              if ( v20 > 100.0 )
                v20 = 100.0;
              *(_DWORD *)v48 = v16;
              v21 = v48;
              *(_DWORD *)(v48 + 4) = v15;
              CGraphData_Update((CGraphData *)(v48 - 0x888), time, v20, 0.0, 0);
            }
            else
            {
              v21 = v48;
            }
            v48 = v21 + 0x898;
            v11 = v37 + 1;
            v12 = __ROL4__(v39, 1);
            v37 = v11;
            v39 = __ROL4__(v39, 1);
          }
          while ( v11 < v41 );
          v8 = v38;
        }
        v22 = 0;
        if ( Statitcs.QueryResult.AdapterInformation.NbSegments )
        {
          do
          {
            memset(&Statitcs3, 0, sizeof(_D3DKMT_QUERYSTATISTICS));
            Statitcs3.Type = D3DKMT_QUERYSTATISTICS_SEGMENT;
            Statitcs3.AdapterLuid.LowPart = (DWORD)v9->_Myval;
            Statitcs3.AdapterLuid.HighPart = (LONG)v9[1]._Next;
            Statitcs3.QuerySegment.SegmentId = v22;
            if ( !D3DKMTQueryStatistics(&Statitcs3) )
            {
              if ( gdwVersion < 3 )
              {
                v25 = Statitcs3.QueryResult.AdapterInformation.VidPnSourceCount >> 10;
                if ( Statitcs3.QueryResult.SegmentInformationV1.Aperture )
                {
                  v43 = (v25 + __PAIR__(v43, v44)) >> 32;
                  v44 += v25;
                }
                else
                {
                  v8 = (v25 + __PAIR__(v8, v47)) >> 32;
                  v47 += v25;
                }
              }
              else
              {
                v23 = Statitcs3.QueryResult.SegmentInformationV1.Memory.TotalBytesEvicted >> 10;
                v24 = Statitcs3.QueryResult.NodeInformation.GlobalInformation.PreemptionStatistics.PreemptionCounter[2] >> 10;
                if ( Statitcs3.QueryResult.AdapterInformation.ReferenceDmaBuffer.NbCall )
                {
                  v43 = (__PAIR__(v24, v23) + __PAIR__(v43, v44)) >> 32;
                  v44 += v23;
                }
                else
                {
                  v8 = (__PAIR__(v24, v23) + __PAIR__(v8, v47)) >> 32;
                  v47 += v23;
                }
              }
            }
            ++v22;
          }
          while ( v22 < Statitcs.QueryResult.AdapterInformation.NbSegments );
          v38 = v8;
        }
      }
      v9 = v9->_Next;
    }
    while ( v9 != gAdapterList._Mypair._Myval2._Myhead );
    if ( v42 | v45 && *(_QWORD *)(a3 + 0x888) )
    {
      v26 = (double)(signed __int64)(__PAIR__(v42, v45) - *(_QWORD *)(a3 + 0x888));
      v27 = v26;
      v28 = (double)v40;
      v29 = (double)a2;
      v30 = (float)(v27 / (float)(v28 * v29)) * 100.0;
      v49 = v30;
      if ( v30 <= 100.0 )
      {
        if ( v30 < 0.0 )
          v49 = 0.0;
      }
      else
      {
        v49 = 100.0;
      }
      v10 = v47;
      v7 = v45;
    }
    else
    {
      v7 = v45;
      v10 = v47;
      v49 = 0.0;
    }
  }
  *(_DWORD *)(a3 + 0x888) = v7;
  *(_DWORD *)(a3 + 0x88C) = v42;
  if ( a4 )
  {
    v36 = *(_DWORD *)(a4 + 0x44);
    a5_4 = *(_DWORD *)(a4 + 0x3C);
    ArgList_4 = *(_QWORD *)(a4 + 0x568);
    if ( gConfig.bShowCpuFractions )
      wsprintfW(szBuffer, L"%02.02f%% %s:%d", ArgList_4, a5_4, v36);
    else
      wsprintfW(szBuffer, L"%02.0f%% %s:%d", ArgList_4, a5_4, v36);
  }
  v31 = szBuffer;
  if ( !a4 )
    v31 = 0;
  CGraphData_Update((CGraphData *)a3, time, v49, 0.0, v31);
  v32 = (double)(signed __int64)__PAIR__(v43, v44);
  if ( v32 > a6->m_dbMemorySize )
    a6->m_dbMemorySize = (float)(v32 * 1.2);
  CGraphData_Update(a6, time, v32, 0.0, 0);
  v33 = (double)(signed __int64)__PAIR__(v8, v10);
  if ( v33 > a6->m_dbMemorySize )
    a7->m_dbMemorySize = (float)(v33 * 1.2);
  CGraphData_Update(a7, time, v33, 0.0, 0);
}
// CACDC0: using guessed type double db_onehundred;
// CD4E54: using guessed type int gdwVersion;

//----- (00C23FB0) --------------------------------------------------------
BOOL __cdecl Init3DStatistics(unsigned __int64 *a1, unsigned __int64 *a2)
{
  HMODULE v2; // eax
  HMODULE v3; // eax
  HMODULE v4; // eax
  HDEVINFO v5; // edi
  DWORD v6; // ebx
  struct _SP_DEVICE_INTERFACE_DETAIL_DATA_W *pData; // edi
  std__list_node *v8; // ebx
  std__list_node *v9; // eax
  unsigned int v10; // edi
  _DWORD *v11; // ebx
  signed int v12; // edi
  unsigned int v13; // edx
  ULONG v14; // eax
  unsigned __int64 *v15; // ebx
  int v16; // edx
  ULONG v17; // ecx
  char v18; // al
  D3DKMT_OPENADAPTERFROMDEVICENAME DeviceName; // [esp+Ch] [ebp-68Ch]
  HDEVINFO DeviceInfoSet; // [esp+1Ch] [ebp-67Ch]
  unsigned __int64 *v22; // [esp+20h] [ebp-678h]
  unsigned int v23; // [esp+24h] [ebp-674h]
  struct _SP_DEVICE_INTERFACE_DETAIL_DATA_W *v24; // [esp+28h] [ebp-670h]
  DWORD v25; // [esp+2Ch] [ebp-66Ch]
  DWORD RequiredSize; // [esp+30h] [ebp-668h]
  char v27; // [esp+37h] [ebp-661h]
  _D3DKMT_QUERYSTATISTICS StatisticsAdapter; // [esp+38h] [ebp-660h]
  _D3DKMT_QUERYSTATISTICS StatisticsSegment; // [esp+358h] [ebp-340h]
  struct _SP_DEVICE_INTERFACE_DATA DeviceInterfaceData; // [esp+678h] [ebp-20h]

  *a2 = 0i64;
  v22 = a1;
  *a1 = 0i64;
  v2 = LoadLibraryW(L"gdi32.dll");
  D3DKMTOpenAdapterFromDeviceName = (int (__stdcall *)(D3DKMT_OPENADAPTERFROMDEVICENAME *))GetProcAddress(
                                                                                             v2,
                                                                                             "D3DKMTOpenAdapterFromDeviceName");
  v3 = LoadLibraryW(L"gdi32.dll");
  D3DKMTCloseAdapter = (int)GetProcAddress(v3, "D3DKMTCloseAdapter");
  v4 = LoadLibraryW(L"gdi32.dll");
  D3DKMTQueryStatistics = (int (__stdcall *)(_D3DKMT_QUERYSTATISTICS *))GetProcAddress(v4, "D3DKMTQueryStatistics");
  if ( D3DKMTOpenAdapterFromDeviceName )
  {
    DeviceInterfaceData.Reserved = 0;
    v5 = SetupDiGetClassDevsW(&CLSID_GUID_DISPLAY_DEVICE_ARRIVAL, 0, 0, 0x12u);
    *(_QWORD *)&DeviceInterfaceData.InterfaceClassGuid.Data4[4] = 0i64;
    v6 = 0;
    DeviceInfoSet = v5;
    _mm_storeu_si128((__m128i *)&DeviceInterfaceData, (__m128i)0i64);
    DeviceInterfaceData.cbSize = 28;
    v27 = 0;
    v25 = 0;
    do
    {
      if ( SetupDiEnumDeviceInterfaces(v5, 0, &CLSID_GUID_DISPLAY_DEVICE_ARRIVAL, v6, &DeviceInterfaceData) )
      {
        RequiredSize = 0;
        if ( SetupDiGetDeviceInterfaceDetailW(v5, &DeviceInterfaceData, 0, 0, &RequiredSize, 0) || GetLastError() == 122 )
        {
          pData = (struct _SP_DEVICE_INTERFACE_DETAIL_DATA_W *)operator new[](RequiredSize);
          v24 = pData;
          memset(pData, 0, RequiredSize);
          pData->cbSize = 6;
          SetupDiGetDeviceInterfaceDetailW(DeviceInfoSet, &DeviceInterfaceData, pData, RequiredSize, 0, 0);
          _mm_storeu_si128((__m128i *)&DeviceName, (__m128i)0i64);
          DeviceName.pDeviceName = pData->DevicePath;
          if ( !D3DKMTOpenAdapterFromDeviceName(&DeviceName) )
          {
            memset(&StatisticsAdapter, 0, sizeof(_D3DKMT_QUERYSTATISTICS));
            StatisticsAdapter.AdapterLuid.LowPart = DeviceName.AdapterLuid.LowPart;
            StatisticsAdapter.AdapterLuid.HighPart = DeviceName.AdapterLuid.HighPart;
            StatisticsAdapter.Type = 0;
            if ( !D3DKMTQueryStatistics(&StatisticsAdapter) )
              gdwAdapterRuntingTime += StatisticsAdapter.QueryResult.NodeInformation.GlobalInformation.RunningTime.HighPart;
            v8 = gAdapterList._Mypair._Myval2._Myhead;
            v9 = (std__list_node *)sub_C23310(
                                     &gAdapterList._Mypair._Myval2._Myhead->_Next,
                                     &gAdapterList._Mypair._Myval2._Myhead->_Prev->_Next,
                                     &DeviceName.AdapterLuid.LowPart);
            if ( 0xFFFFFFE - gAdapterList._Mypair._Myval2._Mysize < 1 )
              std::_Xlength_error("list<T> too long");
            ++gAdapterList._Mypair._Myval2._Mysize;
            v8->_Prev = v9;
            v9->_Prev->_Next = v9;
            v10 = 0;
            v23 = 0;
            if ( StatisticsAdapter.QueryResult.AdapterInformation.NbSegments )
            {
              do
              {
                memset(&StatisticsSegment, 0, sizeof(_D3DKMT_QUERYSTATISTICS));
                StatisticsSegment.AdapterLuid.LowPart = DeviceName.AdapterLuid.LowPart;
                StatisticsSegment.AdapterLuid.HighPart = DeviceName.AdapterLuid.HighPart;
                StatisticsSegment.Type = D3DKMT_QUERYSTATISTICS_SEGMENT;
                StatisticsSegment.QuerySegment.SegmentId = v10;
                if ( !D3DKMTQueryStatistics(&StatisticsSegment) )
                {
                  if ( gdwVersion < 3 )
                  {
                    v14 = StatisticsSegment.QueryResult.AdapterInformation.NbSegments >> 10;
                    if ( StatisticsSegment.QueryResult.SegmentInformationV1.Aperture )
                    {
                      v15 = v22;
                      v16 = *((_DWORD *)v22 + 1);
                      v17 = *(_DWORD *)v22;
                      if ( v16 < 0 || v16 <= 0 && v17 <= v14 )
                      {
                        v17 = StatisticsSegment.QueryResult.AdapterInformation.NbSegments >> 10;
                        v16 = 0;
                      }
                      *(_DWORD *)v22 = v17;
                      *((_DWORD *)v15 + 1) = v16;
                    }
                    else
                    {
                      *a2 += v14;
                    }
                  }
                  else if ( StatisticsSegment.QueryResult.AdapterInformation.ReferenceDmaBuffer.NbCall )
                  {
                    v11 = v22;
                    v12 = *((_DWORD *)v22 + 1);
                    v13 = *(_DWORD *)v22;
                    if ( v12 < (signed int)(StatisticsSegment.QueryResult.AdapterInformation.NodeCount >> 10)
                      || v12 <= (signed int)(StatisticsSegment.QueryResult.AdapterInformation.NodeCount >> 10)
                      && v13 <= (unsigned int)(StatisticsSegment.QueryResult.SegmentInformation.CommitLimit >> 10) )
                    {
                      v13 = StatisticsSegment.QueryResult.SegmentInformation.CommitLimit >> 10;
                      v12 = StatisticsSegment.QueryResult.AdapterInformation.NodeCount >> 10;
                    }
                    *((_DWORD *)v22 + 1) = v12;
                    v10 = v23;
                    *v11 = v13;
                  }
                  else
                  {
                    *a2 += StatisticsSegment.QueryResult.SegmentInformation.CommitLimit >> 10;
                  }
                }
                v23 = ++v10;
              }
              while ( v10 < StatisticsAdapter.QueryResult.AdapterInformation.NbSegments );
            }
            pData = v24;
            v6 = v25;
          }
          operator delete[](pData);
          v5 = DeviceInfoSet;
        }
        v18 = v27;
      }
      else
      {
        v18 = 1;
        v27 = 1;
      }
      v25 = ++v6;
    }
    while ( !v18 );
    SetupDiDestroyDeviceInfoList(v5);
  }
  return gdwAdapterRuntingTime != 0;
}
// CD4E38: using guessed type int D3DKMTCloseAdapter;
// CD4E54: using guessed type int gdwVersion;

//----- (00C24360) --------------------------------------------------------
_DWORD *__stdcall std::_List_alloc<std::_List_base_types<_LUID,std::allocator<_LUID>>>::_Buynode0(_DWORD *a1, _DWORD *a2)
{
  _DWORD *result; // eax
  _DWORD *v3; // ecx
  _DWORD *v4; // edx

  result = operator new(0x10u);
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
  if ( result != (_DWORD *)-4 )
    result[1] = v4;
  return result;
}

//----- (00C243A0) --------------------------------------------------------
CGraphData *__thiscall GraphInfo_Init(tagGraphInfo *pThis)
{
  tagGraphInfo *this; // esi
  CGraphData *pGraphData; // eax
  UINT v3; // ecx
  CGraphData *result; // eax

  this = pThis;
  pGraphData = InitGraphData(1, 2, 1);
  v3 = this->nItemID;
  this->pGraphData = pGraphData;
  pGraphData->m_nItemID = v3;
  this->pGraphData->m_dbMemorySize = db_onehundred;
  this->pGraphData->m_Buffer2 = (PVOID)1;
  this->pGraphData->m_Color = 0xC83C1E;
  this->pGraphData->m_Item[0].nItemID = this->nItemID;
  this->pGraphData->m_Item[0].dbMemorySize = db_onehundred;
  result = this->pGraphData;
  result->m_Item[0].Color = 0xC83CC8;
  return result;
}
// CACDC0: using guessed type double db_onehundred;

//----- (00C24400) --------------------------------------------------------
signed __int64 __thiscall GraphInfo_Refresh(tagGraphInfo *pGrahInfo_1)
{
  int nIndex; // edx
  tagGraphInfo *pGrahInfo; // esi
  int i; // ecx
  CGraphData *pGraphData; // edi
  double v5; // xmm0_8
  signed int nChild; // edx
  signed int v7; // ecx
  signed __int64 result; // rax

  nIndex = 0;
  pGrahInfo = pGrahInfo_1;
  pGrahInfo_1->pGraphData->m_dbMemorySize = db_one;
  for ( i = gdwVirtualScreenWidth; nIndex < i; ++nIndex )
  {
    pGraphData = pGrahInfo->pGraphData;
    v5 = pGraphData->m_Item[0].pBuffer[nIndex];
    if ( v5 > pGraphData->m_dbMemorySize )
    {
      pGraphData->m_dbMemorySize = v5 * 1.200000047683716;
      i = gdwVirtualScreenWidth;
    }
  }
  nChild = 1;
  if ( (signed int)pGrahInfo->pGraphData->m_nChildID > 1 )
  {
    v7 = 0x18;
    do
    {
      v7 += sizeof(tagGraphItem);
      ++nChild;
      *(double *)((char *)&pGrahInfo->pGraphData->m_Lock.m_Lock.LockSemaphore + v7) = pGrahInfo->pGraphData->m_dbMemorySize;
    }
    while ( nChild < (signed int)pGrahInfo->pGraphData->m_nChildID );
  }
  result = (signed __int64)pGrahInfo->pGraphData->m_dbMemorySize;
  pGrahInfo->dbMemorySize = result;
  return result;
}
// CD4E28: using guessed type int gdwVirtualScreenWidth;

//----- (00C244A0) --------------------------------------------------------
void __thiscall sub_C244A0(tagGraphInfo *this, TreeList_Item1 *pItem)
{
  tagGraphInfo *pGraphInfo; // edi
  int v3; // esi
  __int64 v4; // kr10_8
  signed __int64 v5; // kr20_8
  float v6; // xmm0_4
  int v7; // eax
  float v8; // xmm0_4
  float v9; // xmm0_4
  __int64 dbValue3; // ST1C_8
  float v11; // xmm0_4
  float v12; // xmm0_4
  __int64 v13; // ST1C_8
  float v14; // xmm0_4
  __int64 a5; // ST14_8
  float v16; // xmm0_4
  float v17; // xmm0_4
  __int64 v18; // ST1C_8
  float v19; // xmm0_4
  __int64 v20; // ST14_8
  float v21; // xmm0_4
  WCHAR szBuffer[1024]; // [esp+30h] [ebp-804h]

  szBuffer[0] = 0;
  pGraphInfo = this;
  memset(&szBuffer[1], 0, 2046u);
  if ( *(_QWORD *)&pItem->field_58 + *(_QWORD *)&pItem->field_50 + *(_QWORD *)&pItem->field_48 )
  {
    v3 = wsprintfW(szBuffer, L"%s:%d\n", *(_DWORD *)(pItem->field_60 + 60), *(_DWORD *)(pItem->field_60 + 68));
    PE_FormatDouble(
      1,
      &szBuffer[v3],
      1024 - v3,
      (double)*(signed __int64 *)&pItem->field_50,
      (double)*(signed __int64 *)&pItem->field_48,
      (double)*(signed __int64 *)&pItem->field_58);
    v4 = *(_QWORD *)&pItem->field_58 + *(_QWORD *)&pItem->field_50 + *(_QWORD *)&pItem->field_48;
    if ( v4 > pGraphInfo->dbMemorySize )
      pGraphInfo->dbMemorySize = v4;
  }
  v5 = *(_QWORD *)&pItem->field_20 + *(_QWORD *)&pItem->field_18 + *(_QWORD *)&pItem->field_28;
  if ( (double)v5 >= pGraphInfo->pGraphData->m_dbMemorySize )
  {
    v6 = (double)v5;
    pGraphInfo->pGraphData->m_dbMemorySize = (float)(v6 * 1.2);
    pGraphInfo->pGraphData->m_Item[0].dbMemorySize = pGraphInfo->pGraphData->m_dbMemorySize;
  }
  v7 = HIDWORD(pGraphInfo->dbMemorySize) | LODWORD(pGraphInfo->dbMemorySize);
  if ( !pGraphInfo->dbMemorySize )
  {
    LODWORD(pGraphInfo->dbMemorySize) = 1;
    HIDWORD(pGraphInfo->dbMemorySize) = v7;
  }
  v8 = (double)pGraphInfo->dbMemorySize;
  pGraphInfo->pGraphData->m_dbMemorySize = v8;
  pGraphInfo->pGraphData->m_Item[0].dbMemorySize = pGraphInfo->pGraphData->m_dbMemorySize;
  CGraphData_Update(
    pGraphInfo->pGraphData,
    gTimeQuerySystemInfo,
    (double)(signed __int64)(*(_QWORD *)&pItem->field_20 + *(_QWORD *)&pItem->field_18 + *(_QWORD *)&pItem->field_28),
    (double)*(signed __int64 *)&pItem->field_18,
    szBuffer);
  if ( pGraphInfo == &gIOGraphInfo )
  {
    v9 = (double)*(signed __int64 *)&pItem->field_28;
    *(double *)&dbValue3 = v9;
    v11 = (double)*(signed __int64 *)&pItem->field_20;
    sub_C70130(
      pGraphInfo->pGraphData,
      pItem->field_60,
      COERCE__INT64((double)*(signed __int64 *)&pItem->field_18),
      *(__int64 *)&v11,
      dbValue3);
  }
  else if ( pGraphInfo == &gDiskGraphInfo )
  {
    v12 = (double)*(signed __int64 *)&pItem->field_28;
    *(double *)&v13 = v12;
    v14 = (double)*(signed __int64 *)&pItem->field_20;
    *(double *)&a5 = v14;
    v16 = (double)*(signed __int64 *)&pItem->field_18;
    sub_C70010(pGraphInfo->pGraphData, pItem->field_60, *(__int64 *)&v16, a5, v13);
  }
  else if ( pGraphInfo == &gNetworkGraphInfo )
  {
    v17 = (double)*(signed __int64 *)&pItem->field_28;
    *(double *)&v18 = v17;
    v19 = (double)*(signed __int64 *)&pItem->field_20;
    *(double *)&v20 = v19;
    v21 = (double)*(signed __int64 *)&pItem->field_18;
    sub_C70250(pGraphInfo->pGraphData, pItem->field_60, *(__int64 *)&v21, v20, v18);
  }
}

//----- (00C247C0) --------------------------------------------------------
int __stdcall sub_C247C0(int a1, TreeList_Item1 *a2)
{
  TreeList_Item1 *v2; // ecx
  TreeList_Item1 *v3; // edx
  int v4; // eax
  unsigned __int8 v5; // cf
  int v6; // eax
  int v7; // eax
  int result; // eax
  int v9; // [esp+Ch] [ebp-4h]

  v3 = v2;
  v3->field_4 += a2->field_10;
  v3->field_0 += a2->field_30;
  v3->field_8 += a2->field_50;
  v4 = a2->field_38;
  v5 = __CFADD__(v4, v2->field_18);
  v3->field_18 += v4;
  v3->field_1C += a2->field_3C + v5;
  v6 = a2->field_18;
  v5 = __CFADD__(v6, v2->field_20);
  v3->field_20 += v6;
  v3->field_24 += a2->field_1C + v5;
  v7 = *(_DWORD *)&a2->field_58;
  v5 = __CFADD__(v7, v2->field_28);
  v3->field_28 += v7;
  v3->field_2C += *(int *)((char *)&a2->field_59 + 3) + v5;
  v9 = a2->field_3C;
  result = (*(_QWORD *)&v3->field_48 + *(_QWORD *)&v3->field_58 + *(_QWORD *)&v3->field_50) >> 32;
  if ( *(_QWORD *)&a2->field_38 + *(_QWORD *)&a2->field_58 + *(_QWORD *)&a2->field_18 > *(_QWORD *)&v3->field_48
                                                                                      + *(_QWORD *)&v3->field_58
                                                                                      + *(_QWORD *)&v3->field_50 )
  {
    v2->field_48 = a2->field_38;
    v2->field_4C = v9;
    v2->field_50 = a2->field_18;
    v2->field_54 = a2->field_1C;
    *(_DWORD *)&v2->field_58 = *(_DWORD *)&a2->field_58;
    *(int *)((char *)&v2->field_59 + 3) = *(int *)((char *)&a2->field_59 + 3);
    result = a1;
    v2->field_60 = a1;
  }
  return result;
}

//----- (00C24870) --------------------------------------------------------
int __cdecl CMainWnd::Create(HINSTANCE hInstance, int nCmdShow)
{
  HANDLE v2; // eax
  int v3; // ST28_4
  int v4; // eax
  HWND hMainWnd; // esi
  HWND v7; // eax
  UINT showCmd; // eax
  int v9; // edi
  int v10; // edx
  UINT v11; // ecx
  UINT v12; // eax
  UINT v13; // ecx
  UINT v14; // eax
  int v15; // eax
  char v16; // cl
  WNDCLASSEXW wc; // [esp+8h] [ebp-30h]

  LoadStringW(hInstance, IDS_MAINCLASSNAME, &gszMainClassName, 9);
  LoadStringW(hInstance, IDS_MAINWINDOWNAME, &gszMainWindowName, 40);
  ghInstance = hInstance;
  InitDrawEngine();
  if ( gConfig.bAllOneInstance )
  {
    v2 = OpenEventW(SYNCHRONIZE, 0, L"ProcessExplorerElevating");
    if ( v2 )
    {
      CloseHandle(v2);
    }
    else
    {
      v7 = FindWindowW(&gszMainClassName, 0);
      if ( v7 )
      {
        PostMessageW(v7, WM_MSG_7F2, 0, 0);
        return 0;
      }
    }
  }
  if ( !OnBeforeInit() )
    return 0;
  ghWaitCursor = (HINSTANCE)LoadCursorW(0, (LPCWSTR)IDC_WAIT);
  wc.cbSize = 48;
  wc.style = 0;
  wc.lpfnWndProc = CMainWnd::MainWndProc;
  wc.cbClsExtra = 0;
  wc.cbWndExtra = 0;
  wc.hInstance = hInstance;
  wc.hIcon = LoadIconW(hInstance, (LPCWSTR)0x65);
  wc.hCursor = 0;
  wc.hbrBackground = 0;
  wc.lpszMenuName = L"PROCEXPLORER";
  wc.lpszClassName = &gszMainClassName;
  v3 = GetSystemMetrics(50);
  v4 = GetSystemMetrics(49);
  wc.hIconSm = (HICON)LoadImageW(hInstance, (LPCWSTR)0x65, 1u, v4, v3, 0);
  if ( !RegisterClassExW(&wc) && !RegisterClassW((const WNDCLASSW *)&wc.style) )
    return 0;
  memset(&wc, 0, sizeof(WNDCLASSEXW));
  wc.cbSize = sizeof(WNDCLASSEXW);
  wc.lpfnWndProc = CGraphWnd::ChartWndProc;
  wc.hInstance = ghInstance;
  wc.hbrBackground = CreateSolidBrush(0xFFFFFFu);
  wc.lpszClassName = L"CpuGraphClassChart";
  wc.hCursor = LoadCursorW(0, (LPCWSTR)IDC_ARROW);
  RegisterClassExW(&wc);
  memset(&wc, 0, sizeof(WNDCLASSEXW));
  wc.cbSize = sizeof(WNDCLASSEXW);
  wc.lpfnWndProc = CGraphWnd::ChartWndProc;
  wc.hInstance = ghInstance;
  wc.hbrBackground = CreateSolidBrush(gConfig.ColorGraphBk);
  wc.lpszClassName = L"CpuGraphClassGraph";
  wc.hCursor = LoadCursorW(0, (LPCWSTR)IDC_ARROW);
  RegisterClassExW(&wc);
  hMainWnd = CreateWindowExW(
               0,
               &gszMainClassName,
               L"Process Explorer - Sysinternals: www.sysinternals.com",
               0xCF0000u,
               0,
               0,
               780,
               550,
               0,
               0,
               hInstance,
               0);
  if ( !hMainWnd )
    return 0;
  if ( gConfig.WindowPlacement[0].length )
  {
    showCmd = gConfig.WindowPlacement[0].showCmd;
    if ( gConfig.WindowPlacement[0].showCmd == SW_MINIMIZE )
      showCmd = 1;
    if ( gbHide )
      showCmd = 0;
    gConfig.WindowPlacement[0].showCmd = showCmd;
    v9 = GetSystemMetrics(SM_CXVIRTUALSCREEN);
    if ( !v9 )
      v9 = GetSystemMetrics(SM_CXFULLSCREEN);
    v10 = GetSystemMetrics(SM_CYVIRTUALSCREEN);
    if ( !v10 )
      v10 = GetSystemMetrics(SM_CYFULLSCREEN);
    v11 = gConfig.WindowPlacement[1].length;
    v12 = gConfig.WindowPlacement[1].showCmd;
    if ( (signed int)gConfig.WindowPlacement[1].length >= v9 - 10 )
      v11 = 100;
    gConfig.WindowPlacement[1].length = v11;
    v13 = gConfig.WindowPlacement[1].flags;
    if ( (signed int)gConfig.WindowPlacement[1].showCmd > v9 )
      v12 = v9;
    gConfig.WindowPlacement[1].showCmd = v12;
    if ( (signed int)gConfig.WindowPlacement[1].flags >= v10 - 10 )
      v13 = 100;
    gConfig.WindowPlacement[1].flags = v13;
    if ( nCmdShow == SW_SHOWMINNOACTIVE )
    {
      v14 = gConfig.WindowPlacement[0].showCmd;
      if ( gConfig.bHideWhenMinimized )
        v14 = 0;
      gConfig.WindowPlacement[0].showCmd = v14;
    }
    SetWindowPlacement(hMainWnd, gConfig.WindowPlacement);
  }
  else
  {
    v15 = 5;
    if ( gbHide )
      v15 = 0;
    ShowWindow(hMainWnd, v15);
  }
  v16 = gbMainWndMinimized;
  if ( gbHide )
    v16 = 1;
  gbMainWndMinimized = v16;
  UpdateWindow(hMainWnd);
  return 1;
}
// CACB88: using guessed type wchar_t aCpugraphclassc[19];
// CDA388: using guessed type char gbHide;
// CDA389: using guessed type char gbMainWndMinimized;

//----- (00C24B90) --------------------------------------------------------
int wsprintf(wchar_t *Dst, wchar_t *Format, ...)
{
  va_list ArgList; // [esp+10h] [ebp+10h]

  va_start(ArgList, Format);
  return vswprintf_s(Dst, 0x100u, Format, ArgList);
}

//----- (00C24BB0) --------------------------------------------------------
int MakeHandlePropSheetCaption(wchar_t *Dst, wchar_t *Format, ...)
{
  va_list ArgList; // [esp+10h] [ebp+10h]

  va_start(ArgList, Format);
  return vswprintf_s(Dst, 0x208u, Format, ArgList);
}

//----- (00C24BD0) --------------------------------------------------------
CString *__thiscall sub_C24BD0(CString *this, LPCSTR lpMultiByteStr)
{
  CString *v2; // esi
  IAtlStringMgr *v3; // ecx
  CHAR *v4; // eax

  v2 = this;
  v3 = ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>::GetDefaultManager();
  if ( !v3 )
    ATL::AtlThrowImpl(E_FAIL);
  v2->pszData = (CHAR *)(((int (*)(void))v3->vtptr->GetNilData)() + 16);
  if ( !lpMultiByteStr || (unsigned int)lpMultiByteStr & 0xFFFF0000 )
  {
    ATL::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>::operator=(v2, lpMultiByteStr);
  }
  else
  {
    v4 = ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>::FindStringResourceInstance(
           (unsigned __int16)lpMultiByteStr,
           0);
    if ( v4 )
      ATL::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>::LoadStringW(
        v2,
        (HMODULE)v4,
        (unsigned __int16)lpMultiByteStr);
  }
  return v2;
}

//----- (00C24C70) --------------------------------------------------------
CString *__thiscall ATL::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>::operator=(CString *this, LPCSTR lpMultiByteStr)
{
  CString *v2; // edi
  int v3; // esi
  CString *result; // eax

  v2 = this;
  if ( lpMultiByteStr && (v3 = MultiByteToWideChar(3u, 0, lpMultiByteStr, -1, 0, 0) - 1, v3 > 0) )
  {
    if ( ((*((_DWORD *)v2->pszData - 2) - v3) | (1 - *((_DWORD *)v2->pszData - 1))) < 0 )
      ATL::CSimpleStringT<wchar_t,0>::PrepareWrite2(v2, v3);
    MultiByteToWideChar(3u, 0, lpMultiByteStr, -1, (LPWSTR)v2->pszData, v3);
    if ( v3 > *((_DWORD *)v2->pszData - 2) )
      ATL::AtlThrowImpl(E_INVALIDARG);
    *((_DWORD *)v2->pszData - 3) = v3;
    *(_WORD *)&v2->pszData[2 * v3] = 0;
    result = v2;
  }
  else
  {
    ATL::CSimpleStringT<wchar_t,0>::Empty(v2);
    result = v2;
  }
  return result;
}

//----- (00C24D00) --------------------------------------------------------
int __cdecl PE_AutoAppendPostfix(HDC__ *hDC, wchar_t *pszText, unsigned int dwLength, int nWidth)
{
  HANDLE v4; // eax
  wchar_t *pBuffer; // eax
  unsigned __int16 *pszBuffer; // edi
  int nLen; // esi
  HANDLE v8; // eax
  unsigned int v10; // ecx
  unsigned int nBytesToCopy; // esi
  HANDLE v12; // eax
  struct tagSIZE size3; // [esp+Ch] [ebp-20h]
  struct tagSIZE size2; // [esp+14h] [ebp-18h]
  struct tagSIZE size1; // [esp+1Ch] [ebp-10h]
  struct tagSIZE size; // [esp+24h] [ebp-8h]
  unsigned int nWidtha; // [esp+40h] [ebp+14h]

  nWidtha = nWidth - 4;
  v4 = GetProcessHeap();
  pBuffer = (wchar_t *)HeapAlloc(v4, 8u, 2 * dwLength);
  pszBuffer = pBuffer;
  if ( !pBuffer )
    return 0;
  wcscpy_s(pBuffer, dwLength, pszText);
  nLen = wcslen(pszBuffer);
  if ( !GetTextExtentPoint32W(hDC, pszBuffer, nLen, &size) )
  {
LABEL_3:
    v8 = GetProcessHeap();
    HeapFree(v8, 0, pszBuffer);
    return 0;
  }
  if ( size.cx > nWidtha )
  {
    if ( !GetTextExtentPoint32W(hDC, L"...", wcslen(L"..."), &size1)
      || !GetTextExtentPoint32W(hDC, L"..", wcslen(L".."), &size2)
      || !GetTextExtentPoint32W(hDC, L".", wcslen(L"."), &size3) )
    {
      goto LABEL_3;
    }
    if ( nLen > 0 )
    {
      while ( 1 )
      {
        pszBuffer[--nLen] = 0;
        if ( !GetTextExtentPoint32W(hDC, pszBuffer, nLen, &size) )
          goto LABEL_3;
        v10 = nWidtha;
        if ( size.cx + size1.cx <= nWidtha || nLen <= 0 )
          goto LABEL_15;
      }
    }
    v10 = nWidtha;
LABEL_15:
    *pszBuffer = *pszText;
    if ( size.cx + size1.cx > v10 )
    {
      if ( size.cx + size2.cx > v10 )
      {
        if ( size.cx + size3.cx > v10 )
        {
          nBytesToCopy = dwLength;
          *pszBuffer = *pszText;
        }
        else
        {
          nBytesToCopy = dwLength;
          wcscat_s(pszBuffer, dwLength, L".");
        }
      }
      else
      {
        nBytesToCopy = dwLength;
        wcscat_s(pszBuffer, dwLength, L"..");
      }
    }
    else
    {
      nBytesToCopy = dwLength;
      wcscat_s(pszBuffer, dwLength, L"...");
    }
    wcscpy_s(pszText, nBytesToCopy, pszBuffer);
  }
  v12 = GetProcessHeap();
  HeapFree(v12, 0, pszBuffer);
  return 1;
}

//----- (00C24EF0) --------------------------------------------------------
signed int __cdecl sub_C24EF0(unsigned int *a1, _DWORD *a2)
{
  unsigned int v2; // ecx
  unsigned int v3; // edx
  signed int result; // eax
  __int64 v5; // rdi
  bool v6; // zf
  bool v7; // sf
  unsigned __int8 v8; // of

  v2 = *a1;
  v3 = a1[1];
  if ( *(_QWORD *)a1 )
  {
    HIDWORD(v5) = *a2;
    LODWORD(v5) = a2[1];
    if ( !v5 )
      return 1;
    if ( HIDWORD(v5) == v2 )
    {
      v8 = __OFSUB__(v3, (_DWORD)v5);
      v6 = v3 == (_DWORD)v5;
      v7 = (signed int)(v3 - v5) < 0;
      if ( v3 == (_DWORD)v5 )
        return 0;
    }
    else
    {
      v8 = __OFSUB__(v3, (_DWORD)v5);
      v6 = v3 == (_DWORD)v5;
      v7 = (signed int)(v3 - v5) < 0;
    }
    if ( !(v7 ^ v8) && (!((unsigned __int8)(v7 ^ v8) | v6) || v2 > HIDWORD(v5)) )
      return 1;
    result = -1;
  }
  else if ( *(_QWORD *)a2 )
  {
    result = -1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00C24F50) --------------------------------------------------------
char __cdecl sub_C24F50(CRegSettings *pConfig, DWORD *pdwValue, unsigned int a3)
{
  DWORD *pdwValue_1; // edx
  CRegSettings *v4; // ebx
  DWORD *v5; // esi
  CRegSettings *v6; // eoff
  volatile signed __int32 *v7; // eax
  const void *v8; // esi
  signed int v9; // ecx
  unsigned int v10; // esi
  const wchar_t **v11; // eax
  bool *v12; // edx
  const wchar_t **v13; // eax
  bool *v14; // edx
  DWORD *v15; // ecx

  pdwValue_1 = pdwValue;
  v4 = pConfig;
  v5 = pdwValue + 12;
  v6 = pConfig;
  _mm_storeu_si128((__m128i *)pConfig, _mm_loadu_si128((const __m128i *)(pdwValue + 1)));
  _mm_storeu_si128(
    (__m128i *)&v4->WindowPlacement[0].ptMinPosition.y,
    _mm_loadu_si128((const __m128i *)(pdwValue_1 + 5)));
  _mm_storel_epi64((__m128i *)&v4->WindowPlacement[1].flags, _mm_loadl_epi64((const __m128i *)(pdwValue_1 + 9)));
  v7 = (volatile signed __int32 *)pdwValue_1[11];
  v4->WindowPlacement[1].ptMinPosition.x = (LONG)v7;
  qmemcpy(&v6->UnicodeFont, v5, sizeof(v6->UnicodeFont));
  v8 = pdwValue_1 + 97;
  v4->dbDivider = *((double *)pdwValue_1 + 18);
  _mm_storeu_si128((__m128i *)v4->dwProcessColumns, _mm_loadu_si128((const __m128i *)(pdwValue_1 + 38)));
  _mm_storeu_si128((__m128i *)&v4->dwProcessColumns[8], _mm_loadu_si128((const __m128i *)(pdwValue_1 + 42)));
  _mm_storeu_si128((__m128i *)&v4->dwProcessColumns[16], _mm_loadu_si128((const __m128i *)(pdwValue_1 + 46)));
  _mm_storeu_si128((__m128i *)&v4->dwProcessColumns[24], _mm_loadu_si128((const __m128i *)(pdwValue_1 + 50)));
  _mm_storeu_si128((__m128i *)v4->dwHandleColumns, _mm_loadu_si128((const __m128i *)(pdwValue_1 + 54)));
  _mm_storeu_si128((__m128i *)&v4->dwHandleColumns[8], _mm_loadu_si128((const __m128i *)(pdwValue_1 + 58)));
  _mm_storeu_si128((__m128i *)&v4->dwHandleColumns[16], _mm_loadu_si128((const __m128i *)(pdwValue_1 + 62)));
  _mm_storeu_si128((__m128i *)&v4->dwHandleColumns[24], _mm_loadu_si128((const __m128i *)(pdwValue_1 + 66)));
  _mm_storeu_si128((__m128i *)v4->dwDllColumns, _mm_loadu_si128((const __m128i *)(pdwValue_1 + 70)));
  _mm_storeu_si128((__m128i *)&v4->dwDllColumns[8], _mm_loadu_si128((const __m128i *)(pdwValue_1 + 74)));
  _mm_storeu_si128((__m128i *)&v4->dwDllColumns[16], _mm_loadu_si128((const __m128i *)(pdwValue_1 + 78)));
  _mm_storeu_si128((__m128i *)&v4->dwDllColumns[24], _mm_loadu_si128((const __m128i *)(pdwValue_1 + 82)));
  if ( pdwValue_1[97] )
  {
    v9 = 32;
  }
  else
  {
    v8 = pdwValue_1 + 0x176;
    v9 = 64;
  }
  qmemcpy(v4->dwProcessColumnMap, v8, 4 * v9);
  qmemcpy(v4->dwDllColumnMap, pdwValue_1 + 130, sizeof(v4->dwDllColumnMap));
  qmemcpy(v4->dwIdsOfHandleColumnMap, pdwValue_1 + 163, sizeof(v4->dwIdsOfHandleColumnMap));
  v10 = a3;
  if ( a3 > 0x158 )
  {
    LOBYTE(v7) = *((_BYTE *)pdwValue_1 + 344);
    v4->bShowUnnamedHandles = (char)v7;
  }
  if ( v10 > 0x15C )
  {
    LOBYTE(v7) = *((_BYTE *)pdwValue_1 + 348);
    v4->bShowDllView = (char)v7;
  }
  if ( v10 > 0x160 )
  {
    v7 = (volatile signed __int32 *)pdwValue_1[88];
    v4->dwHandleSortColumn = (DWORD)v7;
  }
  if ( v10 > 0x164 )
  {
    LOBYTE(v7) = *((_BYTE *)pdwValue_1 + 356);
    LOBYTE(v4->bHandleSortDirection) = (_BYTE)v7;
  }
  if ( v10 > 0x168 )
  {
    v7 = (volatile signed __int32 *)pdwValue_1[90];
    v4->dwDllSortColumn = (DWORD)v7;
  }
  if ( v10 > 0x16C )
  {
    LOBYTE(v7) = *((_BYTE *)pdwValue_1 + 364);
    LOBYTE(v4->bDllSortDirection) = (_BYTE)v7;
  }
  if ( v10 > 0x170 )
  {
    v7 = (volatile signed __int32 *)pdwValue_1[92];
    v4->dwProcessSortColumn = (DWORD)v7;
  }
  if ( v10 > 0x174 )
  {
    LOBYTE(v7) = *((_BYTE *)pdwValue_1 + 372);
    v4->bProcessSortDirection = (char)v7;
  }
  if ( v10 > 0x175 )
  {
    LOBYTE(v7) = *((_BYTE *)pdwValue_1 + 373);
    v4->bHighlightServices = (char)v7;
  }
  if ( v10 > 0x176 )
  {
    LOBYTE(v7) = *((_BYTE *)pdwValue_1 + 374);
    v4->bHighlightOwnProcesses = (char)v7;
  }
  if ( v10 > 0x178 )
  {
    LOBYTE(v7) = *((_BYTE *)pdwValue_1 + 376);
    v4->bHighlightRelocatedDlls = (char)v7;
  }
  if ( v10 > 0x17C )
  {
    v7 = (volatile signed __int32 *)pdwValue_1[95];
    v4->dwRefreshRate = (DWORD)v7;
  }
  if ( v10 > 0x180 )
  {
    v7 = (volatile signed __int32 *)pdwValue_1[96];
    v4->dwProcessColumnCount = (int)v7;
  }
  if ( v10 > 0x204 )
  {
    v7 = (volatile signed __int32 *)pdwValue_1[129];
    v4->dwDllColumnCount = (DWORD)v7;
  }
  if ( v10 > 0x288 )
  {
    v7 = (volatile signed __int32 *)pdwValue_1[162];
    v4->dwHandleColumnCount = (DWORD)v7;
  }
  if ( v10 > 0x30C )
  {
    LOBYTE(v7) = *((_BYTE *)pdwValue_1 + 780);
    v4->bHighlightJobs = (char)v7;
  }
  if ( v10 > 0x30D )
  {
    LOBYTE(v7) = *((_BYTE *)pdwValue_1 + 781);
    v4->bShowCpuFractions = (char)v7;
  }
  if ( v10 > 0x310 )
    v4->dbSavedDivider = *((double *)pdwValue_1 + 98);
  if ( v10 > 0x318 )
  {
    LOBYTE(v7) = *((_BYTE *)pdwValue_1 + 792);
    v4->bShowLowerPane = (char)v7;
  }
  if ( v10 > 0x319 )
  {
    LOBYTE(v7) = *((_BYTE *)pdwValue_1 + 793);
    v4->bShowAllUsers = (char)v7;
  }
  if ( v10 > 0x41E )
  {
    LOBYTE(v7) = *((_BYTE *)pdwValue_1 + 1054);
    LOBYTE(v4->bSymbolWarningShown) = (_BYTE)v7;
  }
  if ( v10 > 0x523 )
  {
    LOBYTE(v7) = *((_BYTE *)pdwValue_1 + 1315);
    v4->bHighliteNetProcess = (char)v7;
  }
  if ( v10 > 0x524 )
  {
    LOBYTE(v7) = *((_BYTE *)pdwValue_1 + 1316);
    v4->byReserved_00 = (char)v7;
  }
  if ( v10 > 0x525 )
  {
    LOBYTE(v7) = *((_BYTE *)pdwValue_1 + 1317);
    v4->bHideWhenMinimized = (char)v7;
  }
  if ( v10 > 0x554 )
  {
    v7 = (volatile signed __int32 *)pdwValue_1[341];
    v4->ColorOwn = (COLORREF)v7;
  }
  if ( v10 > 0x568 )
  {
    v7 = (volatile signed __int32 *)pdwValue_1[346];
    v4->ColorProtected = (COLORREF)v7;
  }
  if ( v10 > 0x558 )
  {
    v7 = (volatile signed __int32 *)pdwValue_1[342];
    v4->ColorService = (COLORREF)v7;
  }
  if ( v10 > 0x55C )
  {
    v7 = (volatile signed __int32 *)pdwValue_1[343];
    v4->ColorRelocatedDlls = (COLORREF)v7;
  }
  if ( v10 > 0x560 )
  {
    v7 = (volatile signed __int32 *)pdwValue_1[344];
    v4->ColorJobs = (COLORREF)v7;
  }
  if ( v10 > 0x564 )
  {
    v7 = (volatile signed __int32 *)pdwValue_1[345];
    v4->ColorNet = (COLORREF)v7;
  }
  if ( v10 > 0x56C )
  {
    v7 = (volatile signed __int32 *)pdwValue_1[347];
    v4->dwHighlightDuration = (DWORD)v7;
  }
  if ( v10 > 0x570 )
  {
    LOBYTE(v7) = *((_BYTE *)pdwValue_1 + 1392);
    v4->bAlwaysOntop = (char)v7;
  }
  if ( v10 > 0x571 )
  {
    LOBYTE(v7) = *((_BYTE *)pdwValue_1 + 1393);
    v4->bShowProcessTree = (char)v7;
  }
  if ( v10 > 0x574 )
  {
    v7 = (volatile signed __int32 *)pdwValue_1[349];
    v4->dwStatusBarColumns = (DWORD)v7;
  }
  if ( v10 > 0x578 )
  {
    v7 = (volatile signed __int32 *)pdwValue_1[350];
    v4->dwOpacity = (DWORD)v7;
  }
  if ( v10 > 0x5D4 )
  {
    LOBYTE(v7) = *((_BYTE *)pdwValue_1 + 1492);
    v4->bConfirmKill = (char)v7;
  }
  if ( v10 > 0x6D8 )
  {
    v7 = (volatile signed __int32 *)pdwValue_1[438];
    v4->dwDefaultProcPropPage = (DWORD)v7;
  }
  if ( v10 > 0x6F4 )
  {
    LOBYTE(v7) = *((_BYTE *)pdwValue_1 + 1780);
    v4->bVerifySignatures = (char)v7;
  }
  if ( v10 > 0x6F5 )
  {
    LOBYTE(v7) = *((_BYTE *)pdwValue_1 + 1781);
    v4->bShowAllCpus = (char)v7;
  }
  if ( v10 > 0x31A )
  {
    v11 = (const wchar_t **)sub_C24BD0((CString *)&pConfig, (LPCSTR)pdwValue_1 + 794);
    wcscpy_s(v4->strDbgHelpModuleName, 0x104u, *v11);
    v12 = &pConfig[-1].ToolBandInfo[6].fBreak;
    v7 = (volatile signed __int32 *)&pConfig[-1].ToolBandInfo[7].fBreak;
    if ( _InterlockedDecrement(v7) <= 0 )
      LOBYTE(v7) = (*(int (__stdcall **)(bool *))(**(_DWORD **)v12 + 4))(v12);
    pdwValue_1 = pdwValue;
  }
  if ( v10 > 0x41F )
  {
    v13 = (const wchar_t **)sub_C24BD0((CString *)&pConfig, (LPCSTR)pdwValue_1 + 0x41F);
    wcscpy_s(v4->strNtSymbolPath, 0x104u, *v13);
    v14 = &pConfig[-1].ToolBandInfo[6].fBreak;
    v7 = (volatile signed __int32 *)&pConfig[-1].ToolBandInfo[7].fBreak;
    if ( _InterlockedDecrement(v7) <= 0 )
      LOBYTE(v7) = (*(int (__stdcall **)(bool *))(**(_DWORD **)v14 + 4))(v14);
  }
  v15 = pdwValue;
  if ( v10 > 0x528 )
  {
    _mm_storeu_si128(
      (__m128i *)&v4->WindowPlacement[1].ptMinPosition.y,
      _mm_loadu_si128((const __m128i *)(pdwValue + 330)));
    _mm_storeu_si128((__m128i *)&v4->WindowPlacement[2].flags, _mm_loadu_si128((const __m128i *)(v15 + 334)));
    _mm_storel_epi64((__m128i *)&v4->WindowPlacement[2].ptMaxPosition, _mm_loadl_epi64((const __m128i *)(v15 + 338)));
    v7 = (volatile signed __int32 *)v15[340];
    v4->WindowPlacement[3].length = (UINT)v7;
  }
  if ( v10 > 0x57C )
  {
    _mm_storeu_si128((__m128i *)&v4->WindowPlacement[3].flags, _mm_loadu_si128((const __m128i *)(v15 + 351)));
    _mm_storeu_si128((__m128i *)&v4->WindowPlacement[3].ptMaxPosition, _mm_loadu_si128((const __m128i *)(v15 + 355)));
    _mm_storel_epi64((__m128i *)&v4->WindowPlacement[4].showCmd, _mm_loadl_epi64((const __m128i *)(v15 + 359)));
    v7 = (volatile signed __int32 *)v15[361];
    v4->WindowPlacement[4].ptMinPosition.y = (LONG)v7;
  }
  if ( v10 > 0x5A8 )
  {
    _mm_storeu_si128((__m128i *)&v4->WindowPlacement[6].showCmd, _mm_loadu_si128((const __m128i *)(v15 + 362)));
    _mm_storeu_si128((__m128i *)&v4->WindowPlacement[6].ptMaxPosition.y, _mm_loadu_si128((const __m128i *)(v15 + 366)));
    _mm_storel_epi64((__m128i *)&v4->WindowPlacement[7].ptMinPosition, _mm_loadl_epi64((const __m128i *)(v15 + 370)));
    v7 = (volatile signed __int32 *)v15[372];
    v4->WindowPlacement[7].ptMaxPosition.x = (LONG)v7;
  }
  if ( v10 > 0x6DC )
  {
    _mm_storel_epi64((__m128i *)v4->ToolBandInfo, _mm_loadl_epi64((const __m128i *)(v15 + 439)));
    v7 = (volatile signed __int32 *)v15[441];
    *(_DWORD *)&v4->ToolBandInfo[0].fBreak = v7;
  }
  if ( v10 > 0x6E8 )
  {
    _mm_storel_epi64((__m128i *)&v4->ToolBandInfo[1], _mm_loadl_epi64((const __m128i *)(v15 + 442)));
    v7 = (volatile signed __int32 *)v15[444];
    *(_DWORD *)&v4->ToolBandInfo[1].fBreak = v7;
  }
  if ( v10 > 0x6F4 )
  {
    _mm_storel_epi64((__m128i *)&v4->ToolBandInfo[1], _mm_loadl_epi64((const __m128i *)(v15 + 445)));
    v7 = (volatile signed __int32 *)v15[447];
    *(_DWORD *)&v4->ToolBandInfo[1].fBreak = v7;
  }
  if ( v10 > 0x700 )
  {
    _mm_storel_epi64((__m128i *)&v4->ToolBandInfo[1], _mm_loadl_epi64((const __m128i *)v15 + 112));
    v7 = (volatile signed __int32 *)v15[450];
    *(_DWORD *)&v4->ToolBandInfo[1].fBreak = v7;
  }
  if ( v10 > 0x70C )
  {
    _mm_storel_epi64((__m128i *)&v4->ToolBandInfo[1], _mm_loadl_epi64((const __m128i *)(v15 + 451)));
    v7 = (volatile signed __int32 *)v15[453];
    *(_DWORD *)&v4->ToolBandInfo[1].fBreak = v7;
  }
  return (char)v7;
}

//----- (00C255D0) --------------------------------------------------------
int __cdecl PE_DrawText(HDC__ *hDC, const wchar_t *lpszText, tagRECT *lprc, int fAlignRight)
{
  signed int v4; // ecx
  int v5; // esi
  int v6; // eax
  __int16 String[8192]; // [esp+Ch] [ebp-4004h]

  if ( wcslen(lpszText) > 8191 )
  {
    wcsncpy_s((wchar_t *)String, 0x2000u, lpszText, 0xFFFFFFFF);
    __report_rangecheckfailure();
    __debugbreak();
    JUMPOUT(*(_DWORD *)sub_C256D0);
  }
  wcscpy_s((wchar_t *)String, 0x2000u, lpszText);
  v4 = 2;
  if ( fAlignRight )
    v4 = 8;
  PE_AutoAppendPostfix(hDC, (wchar_t *)String, 0x2000u, lprc->right - v4 - lprc->left);
  if ( fAlignRight )
  {
    SetTextAlign(hDC, TA_RIGHT);
    v5 = lprc->right - 10;
  }
  else
  {
    SetTextAlign(hDC, 0);
    v5 = lprc->left + 2;
  }
  v6 = lstrlenW((LPCWSTR)String);
  return ExtTextOutW(hDC, v5, lprc->top + 1, 6u, lprc, (LPCWSTR)String, v6, 0);
}
// C767E8: using guessed type int __report_rangecheckfailure(void);

//----- (00C256D0) --------------------------------------------------------
char __cdecl sub_C256D0(char a1, tagTREEVIEWLISTITEMPARAM *pTreeItem, WORD uID, HDC hDC, RECT *lprc)
{
  int nID; // esi
  HBRUSH v6; // eax
  RECT *rc; // esi
  HDC hdc; // ebx
  HBRUSH v10; // eax
  RECT *v11; // esi
  HDC v12; // ebx
  HBRUSH v13; // eax
  RECT *v14; // ebx
  float v15; // xmm0_4
  HBRUSH v16; // eax
  RECT *v17; // esi
  HDC v18; // ebx
  float v19; // xmm0_4
  HDC v20; // edi
  double v21; // xmm0_8
  COLORREF v22; // eax
  WORD pwHue[4]; // [esp+1Ch] [ebp-Ch]
  WORD pwSaturation[2]; // [esp+24h] [ebp-4h]

  nID = uID;
  switch ( uID )
  {
    case IDS_CPU_HISTORY:
      v6 = GetSysColorBrush(5);
      rc = lprc;
      hdc = hDC;
      FrameRect(hDC, lprc, v6);
      ++rc->top;
      --rc->right;
      if ( !pTreeItem->pGraphData1 )
        TreeViewItemParam_InitGraph(pTreeItem);
      GraphData_DrawChart(pTreeItem->pGraphData1, hdc, (#153 *)rc, gConfig.ColorGraphBk, 1u, 0.0);
      return 1;
    case IDS_PROCESS_TIMELINE:
      v10 = GetSysColorBrush(5);
      v11 = lprc;
      v12 = hDC;
      FrameRect(hDC, lprc, v10);
      ++v11->top;
      --v11->right;
      if ( !pTreeItem->pGraphData1 )
        TreeViewItemParam_InitGraph(pTreeItem);
      sub_C21FD0(&pTreeItem->CreateTime, v12, (#153 *)v11, gConfig.ColorGraphBk);
      return 1;
    case IDS_PRIVATE_BYTES_HISTORY:
      v13 = GetSysColorBrush(5);
      v14 = lprc;
      FrameRect(hDC, lprc, v13);
      ++v14->top;
      --v14->right;
      if ( !pTreeItem->pGraphData2 )
        TreeViewItemParam_InitGraph(pTreeItem);
      v15 = (double)(unsigned __int64)qword_CEBA40;
      GraphData_DrawChart(
        pTreeItem->pGraphData2,
        hDC,
        (#153 *)v14,
        gConfig.ColorGraphBk,
        1u,
        (float)((float)(v15 * 0.2 + (double)(unsigned __int64)qword_CEBA40) * 0.0009765625));
      return 1;
  }
  if ( uID != 1330 )
  {
    v20 = hDC;
    if ( uID == IDS_VIRUSTOTAL && sub_C71820(pTreeItem->m_ItemDataForVirusTotal) )
    {
      if ( sub_C72910(pTreeItem->m_ItemDataForVirusTotal) )
        SetTextColor(v20, 0xFFu);
      else
        SetTextColor(v20, 0xFF0000u);
      SelectObject(v20, ghConfigUnderlineFont);
    }
    if ( a1 || !gConfig.bShowColumnHeatmaps )
      return 0;
    *(_DWORD *)&uID = 0;
    switch ( nID )
    {
      case IDS_CPU:
        ColorRGBToHLS(0x3C943Cu, &pwHue[2], &uID, pwSaturation);
        if ( pTreeItem->dwProcessId )
        {
          v21 = *(double *)&pTreeItem->m_CPU / 100.0;
          if ( v21 > 1.0 )
            v21 = db_one;
        }
        else
        {
          v21 = 0.0;
        }
        break;
      case IDS_PRIVATE_BYTES:
        ColorRGBToHLS(0x82A0u, &pwHue[2], &uID, pwSaturation);
        v21 = (double)(unsigned int)pTreeItem->PagefileUsage * 0.0009765625 / gpGraphInfoOfMemory->m_dbMemorySize;
        break;
      case IDS_WORKING_SET:
        ColorRGBToHLS(0x4080FFu, &pwHue[2], &uID, pwSaturation);
        v21 = (double)(unsigned int)pTreeItem->WorkingSetSize
            * 0.0009765625
            / gpGraphInfoOfPhysicalMemory->m_dbMemorySize;
        break;
      case IDS_GPU2:
        ColorRGBToHLS(0x8080FFu, &pwHue[2], &uID, pwSaturation);
        v21 = *(double *)&pTreeItem->m_Gpu2 / 100.0;
        break;
      default:
        return 0;
    }
    if ( uID )
    {
      *(_DWORD *)&uID = sub_C26210(v21, 130u, 230u);
      if ( uID >= 110u )
        SetTextColor(v20, 0);
      else
        SetTextColor(v20, 0xFFFFFFu);
      v22 = ColorHLSToRGB(pwHue[2], uID, pwSaturation[0]);
      SetBkColor(v20, v22);
    }
    return 0;
  }
  v16 = GetSysColorBrush(5);
  v17 = lprc;
  v18 = hDC;
  FrameRect(hDC, lprc, v16);
  ++v17->top;
  --v17->right;
  if ( !pTreeItem->pGraphDataPROCCPU )
    TreeViewItemParam_InitGraph(pTreeItem);
  v19 = (double)gIOGraphInfo.dbMemorySize;
  GraphData_DrawChart(pTreeItem->pGraphDataPROCCPU, v18, (#153 *)v17, gConfig.ColorGraphBk, 1u, (float)(v19 * 1.2));
  return 1;
}
// CACDC0: using guessed type double db_onehundred;
// CEBA40: using guessed type __int64 qword_CEBA40;

//----- (00C25AD0) --------------------------------------------------------
errno_t __cdecl sub_C25AD0(int a1, int a2, int a3, int a4, int a5, wchar_t *Dst, rsize_t SizeInWords)
{
  double v7; // xmm1_8
  errno_t result; // eax
  char v9; // fl
  bool v10; // cf
  bool v11; // zf
  char v12; // sf
  char v13; // of
  char v14; // pf

  v7 = *(double *)a1;
  if ( *(double *)a1 == 0.0 && !__PAIR__(a3, a2) && !__PAIR__(a5, a4) )
    return wcscpy_s(Dst, SizeInWords, (const wchar_t *)&gszNullString);
  if ( gConfig.bShowCpuFractions )
  {
    if ( v7 >= 0.006 )
      return swprintf_s(Dst, SizeInWords, L"%02.2f", LODWORD(v7), HIDWORD(v7));
    result = swprintf_s(Dst, SizeInWords, L"< 0.01", LODWORD(v7), HIDWORD(v7));
  }
  else
  {
    if ( v7 >= 0.6 )
      return swprintf_s(Dst, SizeInWords, L"%0.0f", LODWORD(v7), HIDWORD(v7));
    result = swprintf_s(Dst, SizeInWords, L"< 1", LODWORD(v7), HIDWORD(v7));
  }
  v10 = *(double *)a1 < 0.0;
  v14 = 0;
  v11 = *(double *)a1 == 0.0;
  v12 = 0;
  v13 = 0;
  BYTE1(result) = v9;
  if ( *(double *)a1 == 0.0 )
    *(double *)a1 = db_zeropointzerozerofive;
  return result;
}
// CAE04C: using guessed type wchar_t a001[7];
// CAE9C8: using guessed type double db_zeropointzerozerofive;

//----- (00C25BB0) --------------------------------------------------------
LPCWSTR __cdecl PE_GetDoubleString(wchar_t *pszText, double dbValue)
{
  if ( dbValue == 0.0 )
    return (LPCWSTR)wcscpy_s(pszText, MAX_PATH, (const wchar_t *)&gszNullString);
  if ( gConfig.bFormatIoBytes )
    return (LPCWSTR)PE_FormatDouble(0, pszText, 0x104u, dbValue, 0.0, COERCE_LONG_DOUBLE(0i64 >> 63));
  swprintf(pszText, L"%f", dbValue);
  return PE_GetNumberFormat(pszText, 0x104u);
}

//----- (00C25C30) --------------------------------------------------------
char __cdecl QueryListItemColor(HWND hWnd, int nItem, BOOL bFocused, COLORREF *pTextColor, COLORREF *pBackColor)
{
  bool v5; // cl
  int v6; // ebx
  DWORD (__stdcall *v7)(int); // esi
  char result; // al
  DWORD (__stdcall *v9)(int); // ecx
  COLORREF v10; // eax
  bool v11; // [esp+Ah] [ebp-2h]
  char v12; // [esp+Bh] [ebp-1h]

  v5 = GetFocus() == hWnd;
  v12 = 0;
  v11 = hWnd == ghWndTreeListView;
  if ( nItem <= 1000 )
  {
    v6 = bFocused;
  }
  else
  {
    v6 = *(_DWORD *)(nItem + 16);
    if ( *(_DWORD *)(nItem + 8) == gdwRefreshCount && v6 == 1 )
      v6 = *(_DWORD *)(nItem + 12);
  }
  if ( (_BYTE)bFocused )
  {
    v7 = GetSysColor;
    if ( v5 )
    {
      *pTextColor = GetSysColor(14);
      *pBackColor = GetSysColor(13);
      return 0;
    }
    goto LABEL_9;
  }
  if ( nItem >= 1000 )
  {
    v9 = GetSysColor;
    switch ( v6 )
    {
      case 0:
        v10 = GetSysColor(5);
        v9 = GetSysColor;
        goto LABEL_18;
      case 1:
        v10 = gConfig.ColorDelProc;
        goto LABEL_17;
      case 2:
      case 3:
        v10 = gConfig.ColorNewProc;
LABEL_17:
        v12 = 1;
LABEL_18:
        *pBackColor = v10;
        break;
      default:
        break;
    }
    *pTextColor = v9(8);
    if ( !v6 )
    {
      if ( hWnd == ghWndDllsListCtrl && gConfig.bHighlightRelocatedDlls && *(_BYTE *)(nItem + 44) & 1 )
        *pBackColor = gConfig.ColorRelocatedDlls;
      if ( v11 )
      {
        if ( gConfig.bHighlightOwnProcesses && gConfig.bShowAllUsers && *(_BYTE *)(nItem + 40) & 0x40 )
          *pBackColor = gConfig.ColorOwn;
        if ( gConfig.bHighlightServices && *(_BYTE *)(nItem + 40) & 0x20 )
          *pBackColor = gConfig.ColorService;
        if ( *(_DWORD *)(nItem + 40) & 0x800 && gConfig.bHighlightJobs )
          *pBackColor = gConfig.ColorJobs;
        if ( (*(_BYTE *)(nItem + 1288) || *(_DWORD *)(nItem + 1284)) && gConfig.bHighliteNetProcess )
          *pBackColor = gConfig.ColorNet;
      }
      if ( gConfig.bHighlightPacked
        && (v11 && *(_DWORD *)(nItem + 40) & 0x100 || hWnd == ghWndDllsListCtrl && *(_BYTE *)(nItem + 44) & 4) )
      {
        *pBackColor = gConfig.ColorPacked;
      }
      if ( v11 )
      {
        if ( gConfig.bHighlightProtected && *(_DWORD *)(nItem + 40) & 0x400 )
          *pBackColor = gConfig.ColorProtected;
        if ( gConfig.bHighlightImmersive && *(_DWORD *)(nItem + 40) & 0x1000 )
          *pBackColor = gConfig.ColorImmersive;
        if ( gConfig.bHighlightSuspend )
        {
          if ( *(_BYTE *)(nItem + 40) < 0 )
            *pBackColor = gConfig.ColorSuspend;
        }
      }
    }
    result = v12;
  }
  else
  {
    v7 = GetSysColor;
    if ( !nItem )
    {
LABEL_9:
      *pTextColor = v7(8);
      *pBackColor = v7(10);
      return 0;
    }
    *pTextColor = GetSysColor(8);
    *pBackColor = GetSysColor(5);
    result = 0;
  }
  return result;
}
// CDA11C: using guessed type int gdwRefreshCount;

//----- (00C25E60) --------------------------------------------------------
BOOL __cdecl CTreeList::SetHeaderItem(HWND hWndHeader, WPARAM wParam, int fImage)
{
  BOOL result; // eax
  MACRO_HDF Format; // ecx
  HDITEMW Item; // [esp+Ch] [ebp-2Ch]

  if ( fImage )
  {
    if ( gbBitmapOnRight )
    {
      Item.mask = HDI_FORMAT;
      SendMessageW(hWndHeader, HDM_GETITEMW, wParam, (LPARAM)&Item);
      Format = HDF_SORTDOWN;
      if ( fImage >= 0 )
        Format = HDF_SORTUP;
      Item.fmt = Item.fmt & -0x2601u | Format;
    }
    else
    {
      Item.mask = HDI_IMAGE|HDI_FORMAT;
      SendMessageW(hWndHeader, HDM_GETITEMW, wParam, (LPARAM)&Item);
      Item.fmt |= 0x1800u;
      Item.iImage = fImage < 0;
    }
    SendMessageW(hWndHeader, HDM_SETITEMW, wParam, (LPARAM)&Item);
    result = UpdateWindow(hWndHeader);
  }
  else
  {
    Item.mask = 4;
    SendMessageW(hWndHeader, HDM_GETITEMW, wParam, (LPARAM)&Item);
    if ( gbBitmapOnRight )
      Item.fmt &= -0x2601u;
    else
      Item.fmt &= -0x1801u;
    SendMessageW(hWndHeader, HDM_SETITEMW, wParam, (LPARAM)&Item);
    result = UpdateWindow(hWndHeader);
  }
  return result;
}
// CDA8F8: using guessed type char gbBitmapOnRight;

//----- (00C25F60) --------------------------------------------------------
BOOL __stdcall EnumFunc(HWND hWnd, LPARAM arg4)
{
  _bstr_t *v2; // ecx
  _bstr_t *v3; // ecx
  DWORD dwProcessId; // [esp+Ch] [ebp-220h]
  _bstr_t a2; // [esp+10h] [ebp-21Ch]
  WCHAR ClassName; // [esp+14h] [ebp-218h]
  int v8; // [esp+228h] [ebp-4h]

  GetWindowThreadProcessId(hWnd, &dwProcessId);
  if ( dwProcessId == *(_DWORD *)(*(_DWORD *)arg4 + 68)
    && GetClassNameW(hWnd, &ClassName, 260)
    && !_wcsicmp(&ClassName, L"TabThumbnailWindow")
    && GetWindowTextW(hWnd, &ClassName, 260) )
  {
    _bstr_t::_bstr_t((tagEventSetItem *)&a2, L"\n   ");
    v2 = *(_bstr_t **)(arg4 + 4);
    v8 = 0;
    _bstr_t::operator+=(v2, &a2);
    v8 = -1;
    _bstr_t::_Free(&a2);
    _bstr_t::_bstr_t((tagEventSetItem *)&a2, &ClassName);
    v3 = *(_bstr_t **)(arg4 + 4);
    v8 = 1;
    _bstr_t::operator+=(v3, &a2);
    _bstr_t::_Free(&a2);
  }
  return 1;
}

//----- (00C26090) --------------------------------------------------------
char __cdecl IsStringID(signed int uID)
{
  bool v1; // zf

  if ( uID > 1111 )
  {
    if ( uID <= 1656 )
    {
      if ( uID < 1654 )
      {
        switch ( uID )
        {
          case 1180:
          case 1181:
          case 1187:
          case 1191:
          case 1193:
          case 1196:
          case 1199:
          case 1308:
          case 1330:
          case 1336:
          case 1337:
          case 1338:
          case 1340:
            return 0;
          default:
            return 1;
        }
        return 1;
      }
      return 0;
    }
    if ( uID > 1674 )
    {
      v1 = uID == IDS_CONTROL_FLOW_GUARD;
    }
    else
    {
      if ( uID >= 1673 || uID == 1667 )
        return 0;
      v1 = uID == 1670;
    }
  }
  else
  {
    if ( uID == 1111 )
      return 0;
    if ( uID <= 35 )
    {
      if ( uID != 35 )
      {
        switch ( uID )
        {
          case 3:
          case 19:
          case 21:
          case 22:
          case 25:
          case 26:
          case 30:
            return 0;
          default:
            return 1;
        }
        return 1;
      }
      return 0;
    }
    if ( uID > 1033 )
    {
      v1 = uID == 1061;
    }
    else
    {
      if ( uID >= 1032 || uID == 38 )
        return 0;
      v1 = uID == 42;
    }
  }
  if ( !v1 )
    return 1;
  return 0;
}

//----- (00C26210) --------------------------------------------------------
unsigned __int16 __cdecl sub_C26210(double a1, unsigned __int16 a2, unsigned __int16 a3)
{
  unsigned __int16 result; // ax

  if ( a1 == 0.0 )
    result = a3;
  else
    result = a3 - 5 * ((unsigned __int16)(signed int)((double)(a3 - a2) * a1) / 5);
  return result;
}

//----- (00C26270) --------------------------------------------------------
int __cdecl sub_C26270(int a1, int a2)
{
  int v2; // edi
  _WORD *v3; // eax
  int v4; // eax
  _WORD *v5; // eax
  int v6; // eax
  _WORD *v7; // eax
  int v8; // eax
  Data_t_bstr_t *v9; // eax
  Data_t_bstr_t *v10; // ebx
  Data_t_bstr_t *v11; // edx
  int v12; // eax
  __int16 v13; // cx
  Data_t_bstr_t *v14; // edx
  OLECHAR *v15; // edx
  int *v16; // ebx
  Data_t_bstr_t *v17; // edi
  __int16 v18; // si
  Data_t_bstr_t *v19; // eax
  __int16 *v20; // ecx
  int v21; // esi
  __int16 v22; // ax
  _WORD *v23; // eax
  int v24; // eax
  _WORD *v25; // eax
  int v26; // eax
  _WORD *v27; // eax
  int v28; // eax
  int i; // esi
  signed int v30; // esi
  signed int v31; // ebx
  Data_t_bstr_t *v32; // eax
  Data_t_bstr_t *v33; // edx
  Data_t_bstr_t *v34; // ecx
  _bstr_t *v35; // esi
  _bstr_t *v36; // eax
  _bstr_t *v37; // eax
  _bstr_t *v38; // eax
  _bstr_t *v39; // eax
  const wchar_t *v40; // eax
  wchar_t *v41; // eax
  signed int v42; // esi
  Data_t_bstr_t *v43; // edi
  int v44; // eax
  OLECHAR *v45; // esi
  _bstr_t *v46; // eax
  _bstr_t *v47; // eax
  BSTR v48; // ecx
  int v49; // edx
  OLECHAR v50; // ax
  int v51; // ecx
  BSTR v52; // eax
  Data_t_bstr_t *v53; // esi
  LPARAM lParam; // [esp+14h] [ebp-40h]
  _bstr_t v56; // [esp+18h] [ebp-3Ch]
  _bstr_t v57; // [esp+1Ch] [ebp-38h]
  _bstr_t a1a; // [esp+20h] [ebp-34h]
  _bstr_t bstrRet; // [esp+24h] [ebp-30h]
  _bstr_t v60; // [esp+28h] [ebp-2Ch]
  OLECHAR **v61; // [esp+2Ch] [ebp-28h]
  _bstr_t a3; // [esp+30h] [ebp-24h]
  _bstr_t v63; // [esp+34h] [ebp-20h]
  _bstr_t a2a; // [esp+38h] [ebp-1Ch]
  _bstr_t v65; // [esp+3Ch] [ebp-18h]
  _bstr_t v66; // [esp+40h] [ebp-14h]
  _bstr_t v67; // [esp+44h] [ebp-10h]
  int v68; // [esp+50h] [ebp-4h]

  if ( !(dword_CD9E5C & 1) )
  {
    dword_CD9E5C |= 1u;
    v68 = 0;
    _bstr_t::_bstr_t((tagEventSetItem *)&::a2, L"\r\n");
    atexit(sub_C9A910);
  }
  v67.m_Data = 0;
  v2 = a2;
  v68 = 1;
  v3 = *(_WORD **)(a2 + 784);
  if ( v3 && *v3 )
  {
    v4 = 0;
    if ( gConfig.dwProcessColumnCount <= 0 )
    {
LABEL_8:
      _bstr_t::operator+=(&v67, &::a2);
      _bstr_t::_bstr_t((tagEventSetItem *)&a2a, *(OLECHAR **)(v2 + 784));
      LOBYTE(v68) = 2;
      _bstr_t::operator+=(&v67, &a2a);
      LOBYTE(v68) = 1;
      _bstr_t::_Free(&a2a);
    }
    else
    {
      while ( gConfig.dwProcessColumnMap[v4] != 38 )
      {
        if ( ++v4 >= gConfig.dwProcessColumnCount )
          goto LABEL_8;
      }
    }
  }
  v5 = *(_WORD **)(v2 + 788);
  if ( v5 && *v5 )
  {
    v6 = 0;
    if ( gConfig.dwProcessColumnCount <= 0 )
    {
LABEL_14:
      _bstr_t::operator+=(&v67, &::a2);
      _bstr_t::_bstr_t((tagEventSetItem *)&a2a, *(OLECHAR **)(v2 + 788));
      LOBYTE(v68) = 3;
      _bstr_t::operator+=(&v67, &a2a);
      LOBYTE(v68) = 1;
      _bstr_t::_Free(&a2a);
    }
    else
    {
      while ( gConfig.dwProcessColumnMap[v6] != 1033 )
      {
        if ( ++v6 >= gConfig.dwProcessColumnCount )
          goto LABEL_14;
      }
    }
  }
  v7 = *(_WORD **)(v2 + 800);
  if ( v7 && *v7 )
  {
    v8 = 0;
    if ( gConfig.dwProcessColumnCount <= 0 )
    {
LABEL_20:
      _bstr_t::operator+=(&v67, &::a2);
      _bstr_t::_bstr_t((tagEventSetItem *)&a2a, L"Command Line:\n   ");
      LOBYTE(v68) = 4;
      _bstr_t::operator+=(&v67, &a2a);
      LOBYTE(v68) = 1;
      _bstr_t::_Free(&a2a);
      v9 = (Data_t_bstr_t *)_wcsdup(*(const wchar_t **)(v2 + 800));
      v10 = v9;
      v11 = v9;
      v66.m_Data = v9;
      v12 = (int)&v9->m_wstr + 2;
      do
      {
        v13 = (__int16)v11->m_wstr;
        v11 = (Data_t_bstr_t *)((char *)v11 + 2);
      }
      while ( v13 );
      if ( (unsigned int)(((signed int)v11 - v12) >> 1) <= 0x64 )
      {
        _bstr_t::_bstr_t((tagEventSetItem *)&a2a, *(OLECHAR **)(v2 + 800));
        LOBYTE(v68) = 8;
      }
      else
      {
        v14 = 0;
        if ( wcslen((const unsigned __int16 *)v10) > 0x64 )
        {
          v15 = (OLECHAR *)v10;
          v16 = &v10[16].m_RefCount;
          v17 = 0;
          do
          {
            v18 = *(_WORD *)v16;
            *(_WORD *)v16 = 0;
            _bstr_t::_bstr_t((tagEventSetItem *)&a2a, v15);
            LOBYTE(v68) = 5;
            _bstr_t::operator+=(&v67, &a2a);
            LOBYTE(v68) = 1;
            _bstr_t::_Free(&a2a);
            _bstr_t::_bstr_t((tagEventSetItem *)&v65, L"\n     ");
            LOBYTE(v68) = 6;
            _bstr_t::operator+=(&v67, &v65);
            LOBYTE(v68) = 1;
            _bstr_t::_Free(&v65);
            v19 = v66.m_Data;
            v16 += 50;
            v17 = (Data_t_bstr_t *)((char *)v17 + 100);
            *((_WORD *)v16 - 100) = v18;
            v15 = (OLECHAR *)((char *)v19 + 2 * (_DWORD)v17);
            v20 = (__int16 *)((char *)v19 + 2 * (_DWORD)v17);
            v21 = (int)(v20 + 1);
            do
            {
              v22 = *v20;
              ++v20;
            }
            while ( v22 );
          }
          while ( (unsigned int)(((signed int)v20 - v21) >> 1) > 0x64 );
          v10 = v66.m_Data;
          a3.m_Data = v17;
          v2 = a2;
          v14 = a3.m_Data;
        }
        _bstr_t::_bstr_t((tagEventSetItem *)&a2a, (OLECHAR *)v10 + (_DWORD)v14);
        LOBYTE(v68) = 7;
      }
      _bstr_t::operator+=(&v67, &a2a);
      LOBYTE(v68) = 1;
      _bstr_t::_Free(&a2a);
    }
    else
    {
      while ( gConfig.dwProcessColumnMap[v8] != 1032 )
      {
        if ( ++v8 >= gConfig.dwProcessColumnCount )
          goto LABEL_20;
      }
    }
  }
  v23 = *(_WORD **)(v2 + 792);
  if ( v23 && *v23 )
  {
    v24 = 0;
    if ( gConfig.dwProcessColumnCount <= 0 )
    {
LABEL_37:
      _bstr_t::operator+=(&v67, &::a2);
      _bstr_t::_bstr_t((tagEventSetItem *)&a2a, L"Path:\n   ");
      LOBYTE(v68) = 9;
      _bstr_t::operator+=(&v67, &a2a);
      LOBYTE(v68) = 1;
      _bstr_t::_Free(&a2a);
      _bstr_t::_bstr_t((tagEventSetItem *)&a2a, *(OLECHAR **)(v2 + 792));
      LOBYTE(v68) = 10;
      _bstr_t::operator+=(&v67, &a2a);
      LOBYTE(v68) = 1;
      _bstr_t::_Free(&a2a);
    }
    else
    {
      while ( gConfig.dwProcessColumnMap[v24] != 1061 )
      {
        if ( ++v24 >= gConfig.dwProcessColumnCount )
          goto LABEL_37;
      }
    }
  }
  v25 = *(_WORD **)(v2 + 824);
  if ( v25 && *v25 )
  {
    v26 = 0;
    if ( gConfig.dwProcessColumnCount <= 0 )
    {
LABEL_43:
      _bstr_t::operator+=(&v67, &::a2);
      _bstr_t::_bstr_t(&a2a, "Package:\n   ");
      LOBYTE(v68) = 11;
      _bstr_t::operator+=(&v67, &a2a);
      LOBYTE(v68) = 1;
      _bstr_t::_Free(&a2a);
      _bstr_t::_bstr_t((tagEventSetItem *)&a2a, *(OLECHAR **)(v2 + 824));
      LOBYTE(v68) = 12;
      _bstr_t::operator+=(&v67, &a2a);
      LOBYTE(v68) = 1;
      _bstr_t::_Free(&a2a);
    }
    else
    {
      while ( gConfig.dwProcessColumnMap[v26] != 1654 )
      {
        if ( ++v26 >= gConfig.dwProcessColumnCount )
          goto LABEL_43;
      }
    }
  }
  v27 = *(_WORD **)(v2 + 796);
  if ( v27 && *v27 )
  {
    v28 = 0;
    if ( gConfig.dwProcessColumnCount <= 0 )
    {
LABEL_49:
      _bstr_t::operator+=(&v67, &::a2);
      _bstr_t::_bstr_t((tagEventSetItem *)&a2a, L"Comment:\n   ");
      LOBYTE(v68) = 13;
      _bstr_t::operator+=(&v67, &a2a);
      LOBYTE(v68) = 1;
      _bstr_t::_Free(&a2a);
      _bstr_t::_bstr_t((tagEventSetItem *)&a2a, *(OLECHAR **)(v2 + 796));
      LOBYTE(v68) = 14;
      _bstr_t::operator+=(&v67, &a2a);
      LOBYTE(v68) = 1;
      _bstr_t::_Free(&a2a);
    }
    else
    {
      while ( gConfig.dwProcessColumnMap[v28] != 1181 )
      {
        if ( ++v28 >= gConfig.dwProcessColumnCount )
          goto LABEL_49;
      }
    }
  }
  if ( *(_DWORD *)(v2 + 860) )
  {
    _bstr_t::operator+=(&v67, &::a2);
    if ( _wcsicmp(*(const wchar_t **)(v2 + 60), L"rundll32.exe") )
    {
      _bstr_t::_bstr_t((tagEventSetItem *)&a2, L"COM Class:\n   ");
      LOBYTE(v68) = 16;
      _bstr_t::operator+=(&v67, (_bstr_t *)&a2);
      LOBYTE(v68) = 1;
      _bstr_t::_Free((_bstr_t *)&a2);
      if ( !*(_DWORD *)(v2 + 848) )
      {
LABEL_56:
        _bstr_t::_bstr_t((tagEventSetItem *)&a2, *(OLECHAR **)(v2 + 860));
        LOBYTE(v68) = 19;
        _bstr_t::operator+=(&v67, (_bstr_t *)&a2);
        LOBYTE(v68) = 1;
        _bstr_t::_Free((_bstr_t *)&a2);
        if ( *(_DWORD *)(v2 + 856) )
        {
          _bstr_t::_bstr_t((tagEventSetItem *)&a2, L"\n   ");
          LOBYTE(v68) = 20;
          _bstr_t::operator+=(&v67, (_bstr_t *)&a2);
          LOBYTE(v68) = 1;
          _bstr_t::_Free((_bstr_t *)&a2);
          _bstr_t::_bstr_t((tagEventSetItem *)&a2, *(OLECHAR **)(v2 + 856));
          LOBYTE(v68) = 21;
          _bstr_t::operator+=(&v67, (_bstr_t *)&a2);
          LOBYTE(v68) = 1;
          _bstr_t::_Free((_bstr_t *)&a2);
        }
        if ( *(_DWORD *)(v2 + 852) )
        {
          _bstr_t::_bstr_t((tagEventSetItem *)&a2, L"\n   ");
          LOBYTE(v68) = 22;
          _bstr_t::operator+=(&v67, (_bstr_t *)&a2);
          LOBYTE(v68) = 1;
          _bstr_t::_Free((_bstr_t *)&a2);
          _bstr_t::_bstr_t((tagEventSetItem *)&a2, *(OLECHAR **)(v2 + 852));
          LOBYTE(v68) = 23;
          _bstr_t::operator+=(&v67, (_bstr_t *)&a2);
          LOBYTE(v68) = 1;
          _bstr_t::_Free((_bstr_t *)&a2);
        }
        goto LABEL_93;
      }
      _bstr_t::_bstr_t((tagEventSetItem *)&a2, *(OLECHAR **)(v2 + 848));
      LOBYTE(v68) = 17;
      _bstr_t::operator+=(&v67, (_bstr_t *)&a2);
      LOBYTE(v68) = 1;
      _bstr_t::_Free((_bstr_t *)&a2);
      _bstr_t::_bstr_t((tagEventSetItem *)&a2, L"\n   ");
      LOBYTE(v68) = 18;
    }
    else
    {
      _bstr_t::_bstr_t((tagEventSetItem *)&a2, L"Rundll Target:\n   ");
      LOBYTE(v68) = 15;
    }
    _bstr_t::operator+=(&v67, (_bstr_t *)&a2);
    LOBYTE(v68) = 1;
    _bstr_t::_Free((_bstr_t *)&a2);
    goto LABEL_56;
  }
  if ( _wcsicmp(*(const wchar_t **)(v2 + 60), L"taskeng.exe")
    && _wcsicmp(*(const wchar_t **)(v2 + 60), L"taskhost.exe")
    && _wcsicmp(*(const wchar_t **)(v2 + 60), L"taskhostex.exe")
    && _wcsicmp(*(const wchar_t **)(v2 + 60), L"taskhostw.exe") )
  {
    if ( _wcsicmp(*(const wchar_t **)(v2 + 60), L"iexplore.exe")
      && _wcsicmp(*(const wchar_t **)(v2 + 60), L"iexplore.exe") )
    {
      if ( *(_DWORD *)(v2 + 868) )
      {
        _bstr_t::operator+=(&v67, &::a2);
        _bstr_t::_bstr_t((tagEventSetItem *)&a2, L"WMI Providers:");
        LOBYTE(v68) = 27;
        _bstr_t::operator+=(&v67, (_bstr_t *)&a2);
        LOBYTE(v68) = 1;
        _bstr_t::_Free((_bstr_t *)&a2);
        for ( i = *(_DWORD *)(v2 + 868); i; i = *(_DWORD *)(i + 12) )
        {
          _bstr_t::_bstr_t((tagEventSetItem *)&a2, L"\n   [");
          LOBYTE(v68) = 28;
          _bstr_t::operator+=(&v67, (_bstr_t *)&a2);
          LOBYTE(v68) = 1;
          _bstr_t::_Free((_bstr_t *)&a2);
          _bstr_t::_bstr_t((tagEventSetItem *)&a2a, *(OLECHAR **)i);
          LOBYTE(v68) = 29;
          _bstr_t::operator+=(&v67, &a2a);
          LOBYTE(v68) = 1;
          _bstr_t::_Free(&a2a);
          _bstr_t::_bstr_t((tagEventSetItem *)&v65, L"]\n       Namespace: ");
          LOBYTE(v68) = 30;
          _bstr_t::operator+=(&v67, &v65);
          LOBYTE(v68) = 1;
          _bstr_t::_Free(&v65);
          _bstr_t::_bstr_t((tagEventSetItem *)&v66, *(OLECHAR **)(i + 4));
          LOBYTE(v68) = 31;
          _bstr_t::operator+=(&v67, &v66);
          LOBYTE(v68) = 1;
          _bstr_t::_Free(&v66);
          _bstr_t::_bstr_t((tagEventSetItem *)&v63, L"\n       DLL: ");
          LOBYTE(v68) = 32;
          _bstr_t::operator+=(&v67, &v63);
          LOBYTE(v68) = 1;
          _bstr_t::_Free(&v63);
          _bstr_t::_bstr_t((tagEventSetItem *)&a3, *(OLECHAR **)(i + 8));
          LOBYTE(v68) = 33;
          _bstr_t::operator+=(&v67, &a3);
          LOBYTE(v68) = 1;
          _bstr_t::_Free(&a3);
        }
      }
      else if ( *(_BYTE *)(v2 + 40) & 0x20 )
      {
        if ( *(_DWORD *)(v2 + 864) )
        {
          _bstr_t::_bstr_t((tagEventSetItem *)&a3, L" (");
          LOBYTE(v68) = 34;
          _bstr_t::operator+=(&v67, &a3);
          LOBYTE(v68) = 1;
          _bstr_t::_Free(&a3);
          _bstr_t::_bstr_t((tagEventSetItem *)&a3, *(OLECHAR **)(v2 + 864));
          LOBYTE(v68) = 35;
          _bstr_t::operator+=(&v67, &a3);
          LOBYTE(v68) = 1;
          _bstr_t::_Free(&a3);
          _bstr_t::_bstr_t((tagEventSetItem *)&a3, L")");
          LOBYTE(v68) = 36;
          _bstr_t::operator+=(&v67, &a3);
          LOBYTE(v68) = 1;
          _bstr_t::_Free(&a3);
        }
        _bstr_t::operator+=(&v67, &::a2);
        _bstr_t::_bstr_t((tagEventSetItem *)&a3, L"Services:");
        LOBYTE(v68) = 37;
        _bstr_t::operator+=(&v67, &a3);
        LOBYTE(v68) = 1;
        _bstr_t::_Free(&a3);
        EnterCriticalSection(&gServiceLock);
        v30 = gdwServiceReturned;
        v31 = 0;
        v32 = (Data_t_bstr_t *)malloc(4 * gdwServiceReturned);
        v33 = 0;
        v66.m_Data = v32;
        v63.m_Data = 0;
        if ( v30 > 0 )
        {
          v34 = 0;
          a2a.m_Data = 0;
          do
          {
            v61 = (LPWSTR *)((char *)&gpszServiceNames->lpServiceName + (_DWORD)v34);
            if ( *(DWORD *)((char *)&gpszServiceNames->ServiceStatusProcess.dwProcessId + (_DWORD)v34) == *(_DWORD *)(v2 + 68) )
            {
              v65.m_Data = 0;
              LOBYTE(v68) = 38;
              _bstr_t::_bstr_t((tagEventSetItem *)&a3, *v61);
              LOBYTE(v68) = 39;
              v35 = _bstr_t::_bstr_t(&v56, "]");
              LOBYTE(v68) = 40;
              v36 = _bstr_t::_bstr_t(&v57, " [");
              LOBYTE(v68) = 41;
              v37 = _bstr_t::operator+(
                      &a1a,
                      *(OLECHAR **)((char *)&a2a.m_Data->m_str + (unsigned int)gpszServiceNames),
                      v36);
              LOBYTE(v68) = 42;
              v38 = _bstr_t::operator+(v37, &bstrRet, &a3);
              LOBYTE(v68) = 43;
              v39 = _bstr_t::operator+(v38, &v60, v35);
              _bstr_t::operator=(&v65, v39);
              _bstr_t::_Free(&v60);
              _bstr_t::_Free(&bstrRet);
              _bstr_t::_Free(&a1a);
              _bstr_t::_Free(&v57);
              _bstr_t::_Free(&v56);
              _bstr_t::_Free(&a3);
              if ( v65.m_Data )
                v40 = v65.m_Data->m_wstr;
              else
                v40 = 0;
              v41 = _wcsdup(v40);
              LOBYTE(v68) = 1;
              *((_DWORD *)&v66.m_Data->m_wstr + v31++) = v41;
              _bstr_t::_Free(&v65);
              v30 = gdwServiceReturned;
              v34 = a2a.m_Data;
              v33 = v63.m_Data;
            }
            v33 = (Data_t_bstr_t *)((char *)v33 + 1);
            v34 = (Data_t_bstr_t *)((char *)v34 + 44);
            v63.m_Data = v33;
            a2a.m_Data = v34;
          }
          while ( (signed int)v33 < v30 );
          v32 = v66.m_Data;
        }
        qsort(v32, v31, 4u, sub_C35A60);
        v42 = 0;
        if ( v31 > 0 )
        {
          v43 = v66.m_Data;
          do
          {
            _bstr_t::_bstr_t((tagEventSetItem *)&a3, L"\n   ");
            LOBYTE(v68) = 44;
            _bstr_t::operator+=(&v67, &a3);
            LOBYTE(v68) = 1;
            _bstr_t::_Free(&a3);
            _bstr_t::_bstr_t((tagEventSetItem *)&v63, *(&v43->m_wstr + v42));
            LOBYTE(v68) = 45;
            _bstr_t::operator+=(&v67, &v63);
            LOBYTE(v68) = 1;
            _bstr_t::_Free(&v63);
            free(*((void **)&v43->m_wstr + v42++));
          }
          while ( v42 < v31 );
          v2 = a2;
        }
        LeaveCriticalSection(&gServiceLock);
        free(v66.m_Data);
      }
    }
    else if ( *(_WORD *)(v2 + 654) >= 0x37u )
    {
      v44 = *(_DWORD *)(v2 + 84);
      if ( v44 )
      {
        if ( !_wcsicmp(*(const wchar_t **)(v44 + 60), L"iexplore.exe") )
        {
          _bstr_t::operator+=(&v67, &::a2);
          _bstr_t::_bstr_t((tagEventSetItem *)&a2, L"Tabs:");
          LOBYTE(v68) = 26;
          _bstr_t::operator+=(&v67, (_bstr_t *)&a2);
          LOBYTE(v68) = 1;
          _bstr_t::_Free((_bstr_t *)&a2);
          lParam = v2;
          v56.m_Data = (Data_t_bstr_t *)&v67;
          EnumWindows(EnumFunc, (LPARAM)&lParam);
        }
      }
    }
  }
  else
  {
    v45 = sub_C34990(*(_DWORD *)(v2 + 68));
    if ( v45 )
    {
      _bstr_t::operator+=(&v67, &::a2);
      v46 = (_bstr_t *)_bstr_t::_bstr_t((tagEventSetItem *)&v56, v45);
      LOBYTE(v68) = 24;
      v47 = _bstr_t::operator+((_bstr_t *)&a2, L"Tasks:\n", v46);
      LOBYTE(v68) = 25;
      _bstr_t::operator+=(&v67, v47);
      _bstr_t::_Free((_bstr_t *)&a2);
      LOBYTE(v68) = 1;
      _bstr_t::_Free(&v56);
      free(v45);
    }
  }
LABEL_93:
  if ( !v67.m_Data || !v67.m_Data->m_wstr || !SysStringLen(v67.m_Data->m_wstr) )
  {
    _bstr_t::operator+=(&v67, &::a2);
    _bstr_t::_bstr_t((tagEventSetItem *)&a2, *(OLECHAR **)(v2 + 60));
    LOBYTE(v68) = 46;
    _bstr_t::operator+=(&v67, (_bstr_t *)&a2);
    LOBYTE(v68) = 1;
    _bstr_t::_Free((_bstr_t *)&a2);
  }
  if ( ::a2.m_Data )
    v48 = ::a2.m_Data->m_wstr;
  else
    v48 = 0;
  v49 = (int)(v48 + 1);
  do
  {
    v50 = *v48;
    ++v48;
  }
  while ( v50 );
  v51 = ((signed int)v48 - v49) >> 1;
  if ( v67.m_Data )
    v52 = v67.m_Data->m_wstr;
  else
    v52 = 0;
  _bstr_t::_bstr_t((tagEventSetItem *)a1, &v52[v51]);
  v53 = v67.m_Data;
  if ( v67.m_Data && !InterlockedDecrement(&v67.m_Data->m_RefCount) && v53 )
  {
    if ( v53->m_wstr )
    {
      SysFreeString(v53->m_wstr);
      v53->m_wstr = 0;
    }
    if ( v53->m_str )
    {
      operator delete[](v53->m_str);
      v53->m_str = 0;
    }
    operator delete(v53);
  }
  return a1;
}
// CD9E5C: using guessed type int dword_CD9E5C;

//----- (00C26F30) --------------------------------------------------------
void __cdecl RegVar_ReadWrite(int fSave, int nCount, CRegVar *pVariable)
{
  wchar_t *pConfigItem; // [esp+0h] [ebp-3F4h]
  tagConfigItem ConfigItems[20]; // [esp+8h] [ebp-3ECh]
  WCHAR pszBuffer[260]; // [esp+1E8h] [ebp-20Ch]

  ConfigItems[1].dbValue = db_twohundred;
  ConfigItems[3].dbValue = db_six;
  ConfigItems[1].Address = &pVariable->ProcessImageColumnWidth;
  ConfigItems[4].llValue = 0i64;
  ConfigItems[2].Address = pVariable->ProcessColumns;
  ConfigItems[3].Address = &pVariable->PrcessColumnCount;
  *(_QWORD *)&ConfigItems[4].Address = (unsigned int)pVariable->ProcessColumnMap;
  ConfigItems[5].Address = &pVariable->DllColumnCount;
  ConfigItems[6].Address = pVariable->DllColumns;
  ConfigItems[7].Address = pVariable->DllColumnMap;
  ConfigItems[5].dbValue = db_four;
  ConfigItems[8].Address = &pVariable->HandleColumnCount;
  ConfigItems[7].llValue = 0i64;
  ConfigItems[9].Address = pVariable->HandleColumnMap;
  ConfigItems[8].dbValue = db_two;
  ConfigItems[10].Address = pVariable->HandleColumns;
  ConfigItems[0].Name = L"ColumnSetName";
  ConfigItems[0].KeyType = KT_String;
  ConfigItems[0].StructSize = 520;
  ConfigItems[0].Address = pVariable;
  ConfigItems[0].llValue = 0i64;
  ConfigItems[1].Name = L"ProcessImageColumnWidth";
  ConfigItems[1].KeyType = 3;
  ConfigItems[1].StructSize = 2;
  ConfigItems[2].Name = L"ProcessColumns";
  ConfigItems[2].KeyType = 6;
  ConfigItems[2].StructSize = 192;
  ConfigItems[2].llValue = 0i64;
  ConfigItems[3].Name = L"PrcessColumnCount";
  ConfigItems[3].KeyType = 0;
  ConfigItems[3].StructSize = 0;
  ConfigItems[4].Name = L"ProcessColumnMap";
  ConfigItems[4].KeyType = 5;
  ConfigItems[4].StructSize = 384;
  ConfigItems[5].Name = L"DllColumnCount";
  ConfigItems[5].KeyType = 0;
  ConfigItems[5].StructSize = 0;
  ConfigItems[6].Name = L"DllColumns";
  ConfigItems[6].KeyType = 6;
  ConfigItems[6].StructSize = 64;
  ConfigItems[6].llValue = 0i64;
  ConfigItems[7].Name = L"DllColumnMap";
  ConfigItems[7].KeyType = 5;
  ConfigItems[7].StructSize = 128;
  ConfigItems[8].Name = L"HandleColumnCount";
  ConfigItems[8].KeyType = 0;
  ConfigItems[8].StructSize = 0;
  ConfigItems[9].Name = L"HandleColumnMap";
  ConfigItems[9].KeyType = 5;
  ConfigItems[9].StructSize = 128;
  ConfigItems[9].llValue = 0i64;
  ConfigItems[10].Name = L"HandleColumns";
  ConfigItems[10].KeyType = 6;
  ConfigItems[10].StructSize = 64;
  ConfigItems[10].llValue = 0i64;
  ConfigItems[11].Name = L"HandleSortColumn";
  ConfigItems[11].KeyType = 0;
  ConfigItems[11].StructSize = 0;
  ConfigItems[11].Address = &pVariable->HandleSortColumn;
  ConfigItems[11].llValue = 0i64;
  ConfigItems[12].Name = L"HandleSortDirection";
  ConfigItems[12].Address = &pVariable->HandleSortDirection;
  ConfigItems[13].Address = &pVariable->DllSortColumn;
  ConfigItems[14].Address = &pVariable->DllSortDirection;
  ConfigItems[15].Address = &pVariable->ProcessSortColumn;
  ConfigItems[16].Address = &pVariable->ProcessSortDirection;
  ConfigItems[17].Address = &pVariable->ShowProcessTree;
  ConfigItems[18].Address = &pVariable->StatusBarColumns;
  ConfigItems[15].dbValue = dbl_CAEA40;
  ConfigItems[12].KeyType = KT_Bool;
  ConfigItems[12].StructSize = 0;
  ConfigItems[12].dbValue = db_one;
  ConfigItems[13].Name = L"DllSortColumn";
  ConfigItems[13].KeyType = 0;
  ConfigItems[13].StructSize = 0;
  ConfigItems[13].llValue = 0i64;
  ConfigItems[14].Name = L"DllSortDirection";
  ConfigItems[14].KeyType = 1;
  ConfigItems[14].StructSize = 0;
  ConfigItems[14].dbValue = db_one;
  ConfigItems[15].Name = L"ProcessSortColumn";
  ConfigItems[15].KeyType = 0;
  ConfigItems[15].StructSize = 0;
  ConfigItems[16].Name = L"ProcessSortDirection";
  ConfigItems[16].KeyType = 1;
  ConfigItems[16].StructSize = 0;
  ConfigItems[16].dbValue = db_one;
  ConfigItems[17].Name = L"ShowProcessTree";
  ConfigItems[17].KeyType = 1;
  ConfigItems[17].StructSize = 0;
  ConfigItems[17].dbValue = db_one;
  ConfigItems[18].Name = L"StatusBarColumns";
  ConfigItems[18].KeyType = 0;
  ConfigItems[18].StructSize = 0;
  ConfigItems[18].dbValue = db_twenty21;
  ConfigItems[19].Name = 0;
  ConfigItems[19].KeyType = 0;
  ConfigItems[19].StructSize = 0;
  ConfigItems[19].Address = 0;
  ConfigItems[19].llValue = 0i64;
  swprintf(pszBuffer, L"Software\\Sysinternals\\Process Explorer\\ColumnSet%d", nCount);
  pConfigItem = _wcsdup(pszBuffer);
  if ( fSave )
    SaveConfigItemToRegistry((tagRegKeyInfo *)&pConfigItem, ConfigItems);
  else
    LoadConfigItemFromRegistry((tagRegKeyInfo *)&pConfigItem, ConfigItems);
  free(pConfigItem);
}
// CACB38: using guessed type double db_four;
// CAD414: using guessed type wchar_t aProcesscolumns[15];
// CAD434: using guessed type wchar_t aProcessimageco[24];
// CAD464: using guessed type wchar_t aHandlecolumns[14];
// CAD480: using guessed type wchar_t aDllcolumns[11];
// CAD4D8: using guessed type wchar_t aHandlesortcolu[17];
// CAD4FC: using guessed type wchar_t aHandlesortdire[20];
// CAD524: using guessed type wchar_t aDllsortcolumn[14];
// CAD540: using guessed type wchar_t aDllsortdirecti[17];
// CAD564: using guessed type wchar_t aProcesssortcol[18];
// CAD588: using guessed type wchar_t aProcesssortdir[21];
// CAD7D4: using guessed type wchar_t aShowprocesstre[16];
// CAD8BC: using guessed type wchar_t aPrcesscolumnco[18];
// CAD8E0: using guessed type wchar_t aProcesscolumnm[17];
// CAD904: using guessed type wchar_t aDllcolumncount[15];
// CAD924: using guessed type wchar_t aDllcolumnmap[13];
// CAD940: using guessed type wchar_t aHandlecolumnco[18];
// CAD964: using guessed type wchar_t aHandlecolumnma[16];
// CADB90: using guessed type wchar_t aStatusbarcolum[17];
// CADE18: using guessed type wchar_t aColumnsetname[14];
// CAE9E8: using guessed type double db_two;
// CAE9F0: using guessed type double db_six;
// CAE9F8: using guessed type double db_twenty21;
// CAEA00: using guessed type double db_twohundred;
// CAEA40: using guessed type double dbl_CAEA40;

//----- (00C273D0) --------------------------------------------------------
int __cdecl sub_C273D0(HWND hWnd, char a2)
{
  int v2; // eax
  int result; // eax
  LPARAM lParam; // [esp+Ch] [ebp-464h]
  int v5; // [esp+10h] [ebp-460h]
  int v6; // [esp+14h] [ebp-45Ch]
  int v7; // [esp+18h] [ebp-458h]
  int v8; // [esp+1Ch] [ebp-454h]
  WCHAR *v9; // [esp+20h] [ebp-450h]
  int v10; // [esp+24h] [ebp-44Ch]
  int v11; // [esp+28h] [ebp-448h]
  int v12; // [esp+2Ch] [ebp-444h]
  char v13; // [esp+40h] [ebp-430h]
  wchar_t Src; // [esp+64h] [ebp-40Ch]
  WCHAR String; // [esp+26Ch] [ebp-204h]

  qmemcpy(&v13, &a2, 0x22Cu);
  memset(&v5, 0, 0x30u);
  wcscpy_s(&String, 0x100u, &Src);
  lParam = 13;
  v5 = 0x7FFFFFFF;
  v6 = 0;
  v7 = 0;
  v8 = 0;
  v9 = &String;
  v2 = lstrlenW(&String);
  v11 = 0;
  v10 = v2 + 1;
  result = (int)malloc(0x22Cu);
  if ( result )
  {
    qmemcpy((void *)result, &v13, 0x22Cu);
    v12 = result;
    result = SendMessageW(hWnd, 0x104Du, 0, (LPARAM)&lParam) != -1;
  }
  return result;
}

//----- (00C274F0) --------------------------------------------------------
char __cdecl CTreeList_InsertVerifyColumn(HWND hWnd, UINT uID, int *pnIDs, int pnLength)
{
  int idx; // eax
  int i; // ecx
  bool v6; // zf
  char v7; // cl
  HWND hWnd_1; // edi
  WPARAM nItem; // ecx
  tagLVCOLUMNW ColumnInfo; // [esp+Ch] [ebp-A8h]
  HWND hWndIn; // [esp+2Ch] [ebp-88h]
  WCHAR Buffer[64]; // [esp+30h] [ebp-84h]

  hWndIn = hWnd;
  idx = 0;
  for ( i = *(_DWORD *)pnLength; idx < i; ++idx )
  {
    if ( pnIDs[idx] == uID )
      break;
  }
  if ( idx != i )
    return 0;
  ColumnInfo.iSubItem = *(_DWORD *)pnLength;
  ColumnInfo.cx = MulDiv(100, gLogPixelSize.x, 96);
  LoadStringW(ghInstance, uID, Buffer, 64);
  pnIDs[*(_DWORD *)pnLength] = uID;
  ColumnInfo.mask = 7;
  ColumnInfo.cchTextMax = 64;
  ColumnInfo.pszText = Buffer;
  if ( (signed int)uID > IDS_PATH2 )
  {
    if ( (signed int)uID <= IDS_AUTOSTART_LOCATION )
    {
      if ( (signed int)uID < IDS_PACKAGE_NAME )
      {
        switch ( uID )
        {
          case IDS_DESKTOP_INTEGRITY_LEVEL:
          case IDS_COMMENT:
          case IDS_VERIFIED_SIGNER:
          case IDS_CPU_HISTORY:
          case IDS_PRIVATE_BYTES_HISTORY:
          case IDS_WINDOW_STATUS:
          case IDS_DEP:
          case IDS_DECODED_ACCESS:
          case IDS_IO_HISTORY:
          case IDC_SYSINFO_IOETW_STATIC_DISK:
          case IDC_PAGE_PROCTHREADS_STATIC_IO_PRIORITY:
          case IDC_PAGE_PROCTHREADS_STATIC_MEMORY_PRIORITY:
          case IDC_PAGE_PROCTHREADS_STATIC_IO_PRIORITY_VALUE:
            goto LABEL_25;
          default:
            goto LABEL_24;
        }
        goto LABEL_24;
      }
      goto LABEL_25;
    }
    if ( (signed int)uID > IDS_UI_ACCESS )
    {
      v6 = uID == IDS_CONTROL_FLOW_GUARD;
    }
    else
    {
      if ( (signed int)uID >= IDS_PROTECTION || uID == IDS_DPI_AWARENESS )
        goto LABEL_25;
      v6 = uID == IDS_VIRUSTOTAL;
    }
  }
  else
  {
    if ( uID == IDS_PATH2 )
      goto LABEL_25;
    if ( (signed int)uID <= IDS_WINDOW_TITLE )
    {
      if ( uID != IDS_WINDOW_TITLE )
      {
        switch ( uID )
        {
          case IDS_PROCESS:
          case IDS_USER_NAME:
          case IDS_TYPE:
          case IDS_NAME1:
          case IDS_VERSION:
          case IDS_NAME2:
          case IDS_TIME:
            goto LABEL_25;
          default:
            goto LABEL_24;
        }
        goto LABEL_24;
      }
LABEL_25:
      v7 = 0;
      goto LABEL_26;
    }
    if ( (signed int)uID > IDS_COMPANY_NAME )
    {
      v6 = uID == IDS_PATH;
    }
    else
    {
      if ( (signed int)uID >= IDS_COMMAND_LINE || uID == IDS_DESCRIPTION )
        goto LABEL_25;
      v6 = uID == IDS_DESCRIPTION2;
    }
  }
  if ( v6 )
    goto LABEL_25;
LABEL_24:
  v7 = 1;
LABEL_26:
  hWnd_1 = hWndIn;
  v6 = v7 == 0;
  nItem = *(_DWORD *)pnLength;
  ColumnInfo.fmt = !v6;
  *(_DWORD *)pnLength = nItem + 1;
  SendMessageW(hWnd_1, LVM_INSERTCOLUMNW, nItem, (LPARAM)&ColumnInfo);
  SetWindowLongW(hWnd_1, GWLP_USERDATA, *(_DWORD *)pnLength);
  if ( uID == IDS_VIRUSTOTAL && !gConfig.bCheckVirusTotal )
    MessageBoxW(
      hWnd_1,
      L"You can enable lookup of VirusTotal results for all files displayed in the process and DLL views by selecting the "
       "Check VirusTotal entry in the Options menu or check individual  files on-demand using the process and DLL properties dialogs.",
      L"VirusTotal",
      0x40u);
  return 1;
}

//----- (00C27790) --------------------------------------------------------
int __cdecl sub_C27790(HWND hWnd, char a2)
{
  tagDLLLISTITEMPARAM *pItemParam; // eax
  tagDLLLISTITEMPARAM *pItemParam_1; // ebx
  int v5; // eax
  tagLVITEMW ItemInfo; // [esp+4h] [ebp-34h]

  memset(&ItemInfo.iItem, 0, 0x30u);
  ItemInfo.mask = 13;
  ItemInfo.iItem = 0x7FFFFFFF;
  ItemInfo.iSubItem = 0;
  ItemInfo.state = 0;
  ItemInfo.stateMask = 0;
  ItemInfo.pszText = (LPWSTR)-1;
  ItemInfo.iImage = 0;
  pItemParam = (tagDLLLISTITEMPARAM *)malloc(sizeof(tagDLLLISTITEMPARAM));
  pItemParam_1 = pItemParam;
  if ( !pItemParam )
    return 0;
  qmemcpy(pItemParam, &a2, sizeof(tagDLLLISTITEMPARAM));
  pItemParam->m_nRefCount = 1;
  pItemParam->field_164 = 0;
  pItemParam->field_168 = 0;
  pItemParam->field_160 = 0;
  pItemParam->m_Type = 1;
  pItemParam->field_8 = gdwRefreshCount + 1;
  ItemInfo.lParam = (tagTREEVIEWLISTITEMPARAM *)pItemParam;
  if ( SendMessageW(hWnd, LVM_INSERTITEMW, 0, (LPARAM)&ItemInfo) == -1 )
    return 0;
  pItemParam_1->m_Next = 0;
  pItemParam_1->m_Prev = gpDllListItemParamHeader;
  if ( gpDllListItemParamHeader )
    gpDllListItemParamHeader->m_Next = pItemParam_1;
  gpDllListItemParamHeader = pItemParam_1;
  if ( gConfig.bVerifySignatures )
  {
    InterlockedIncrement(&pItemParam_1->m_nRefCount);
    _beginthread((int)VerifyImageThreadProc, 0, (int)pItemParam_1);
  }
  v5 = 2;
  if ( gConfig.bCheckVirusTotal )
    v5 = 0;
  sub_C71C30(pItemParam_1, ~(unsigned __int8)((unsigned int)pItemParam_1->field_2C >> 1) & 1, v5);
  return 1;
}
// CDA11C: using guessed type int gdwRefreshCount;

//----- (00C278D0) --------------------------------------------------------
wchar_t *__cdecl sub_C278D0(HWND a1, wchar_t *a2)
{
  const WCHAR *v2; // eax
  int v3; // eax
  wchar_t *result; // eax
  HWND v5; // esi
  HWND v6; // eax
  LPARAM v7; // [esp+4h] [ebp-270h]
  int v8; // [esp+Ch] [ebp-268h]
  wchar_t *v9; // [esp+18h] [ebp-25Ch]
  LPARAM lParam; // [esp+38h] [ebp-23Ch]
  int v11; // [esp+3Ch] [ebp-238h]
  int v12; // [esp+40h] [ebp-234h]
  int v13; // [esp+44h] [ebp-230h]
  int v14; // [esp+48h] [ebp-22Ch]
  const WCHAR *v15; // [esp+4Ch] [ebp-228h]
  int v16; // [esp+50h] [ebp-224h]
  int v17; // [esp+54h] [ebp-220h]
  wchar_t *v18; // [esp+58h] [ebp-21Ch]
  HWND hWnd; // [esp+6Ch] [ebp-208h]
  wchar_t Dst; // [esp+70h] [ebp-204h]

  hWnd = a1;
  memset(&v11, 0, 0x30u);
  v2 = (const WCHAR *)*((_DWORD *)a2 + 9);
  lParam = 13;
  v11 = 0x7FFFFFFF;
  v12 = 0;
  v13 = 0;
  v14 = 0;
  v15 = v2;
  v3 = lstrlenW(v2);
  v17 = 0;
  v16 = v3 + 1;
  result = (wchar_t *)malloc(0xB8u);
  if ( result )
  {
    qmemcpy(result, a2, 0xB8u);
    v5 = hWnd;
    v18 = result;
    hWnd = (HWND)SendMessageW(hWnd, 0x104Du, 0, (LPARAM)&lParam);
    if ( hWnd == HWND_MESSAGE|0x2 )
    {
      result = 0;
    }
    else
    {
      wsprintf(&Dst, L"%d", *((_DWORD *)a2 + 42));
      v8 = 1;
      v9 = &Dst;
      SendMessageW(v5, 0x1074u, (WPARAM)hWnd, (LPARAM)&v7);
      v8 = 2;
      v9 = a2 + 20;
      SendMessageW(v5, 0x1074u, (WPARAM)hWnd, (LPARAM)&v7);
      v9 = (wchar_t *)*((_DWORD *)a2 + 45);
      v8 = 3;
      SendMessageW(v5, 0x1074u, (WPARAM)hWnd, (LPARAM)&v7);
      v6 = GetParent(v5);
      SendMessageW(v6, 0x465u, 0, 0);
      result = (wchar_t *)1;
    }
  }
  return result;
}

//----- (00C27A90) --------------------------------------------------------
int sub_C27A90(HWND hWnd, ...)
{
  int v1; // esi
  int result; // eax
  LVITEMW lParam; // [esp+8h] [ebp-10F8h]
  char v4; // [esp+3Ch] [ebp-10C4h]
  va_list va; // [esp+110Ch] [ebp+Ch]

  va_start(va, hWnd);
  memmove_0(&v4, va, 0x10C0u);
  memset(&lParam.iItem, 0, 0x30u);
  lParam.mask = 13;
  lParam.iItem = 0x7FFFFFFF;
  lParam.iSubItem = 0;
  lParam.state = 0;
  lParam.stateMask = 0;
  lParam.pszText = (LPWSTR)-1;
  lParam.iImage = 0;
  v1 = (int)malloc(0x10C0u);
  if ( !v1 )
    return 0;
  memmove_0((void *)v1, &v4, 0x10C0u);
  *(_DWORD *)(v1 + 4) = 2;
  *(_DWORD *)(v1 + 8) = gdwRefreshCount + 1;
  lParam.lParam = (tagTREEVIEWLISTITEMPARAM *)v1;
  if ( SendMessageW(hWnd, LVM_INSERTITEMW, 0, (LPARAM)&lParam) == -1 )
    return 0;
  *(_DWORD *)(v1 + 4284) = 0;
  *(_DWORD *)(v1 + 4280) = pItemParam;
  if ( pItemParam )
    *(_DWORD *)(pItemParam + 0x10BC) = v1;
  result = 1;
  pItemParam = v1;
  return result;
}
// CDA11C: using guessed type int gdwRefreshCount;

//----- (00C27BC0) --------------------------------------------------------
tagTREEVIEWLISTITEMPARAM *__cdecl CTreeList::FindItem(HWND hWnd, tagTREEVIEWLISTITEMPARAM *lParam)
{
  tagTREEVIEWLISTITEMPARAM *pItemParam; // eax
  tagTREEVIEWLISTITEMPARAM *pItemParam_1; // ebx
  WCHAR *v4; // eax
  tagTREEVIEWLISTITEMPARAM *pItemParam_2; // ecx
  CTreeList *pTreeList; // eax
  HICON v7; // ST0C_4
  _IMAGELIST *v8; // eax
  int nImage; // eax
  bool v10; // zf
  LRESULT (__stdcall *SendMessageW)(HWND, UINT, WPARAM, LPARAM); // esi
  tagTREEVIEWLISTITEMPARAM *v12; // eax
  LRESULT v13; // eax
  WPARAM v14; // eax
  LVFINDINFOW FindInfo; // [esp+4h] [ebp-18h]

  ::SendMessageW(hWnd, WM_SETREDRAW, 0, 0);
  pItemParam = (tagTREEVIEWLISTITEMPARAM *)malloc(sizeof(tagTREEVIEWLISTITEMPARAM));
  pItemParam_1 = pItemParam;
  if ( pItemParam )
  {
    qmemcpy(pItemParam, lParam, sizeof(tagTREEVIEWLISTITEMPARAM));
    pItemParam->nRefCount = 1;
    pItemParam->nListType = 0;
    pItemParam->dwRefreshCount = gdwRefreshCount + 1;
    v4 = pItemParam->szProcessName;
    if ( !v4 )
      v4 = pItemParam_1->szProcessName2;
    pItemParam_1->pszComments = (int)ProcessComment_Find(v4);
    pItemParam_1->field_2C = -1;
    pItemParam_1->m_Next = 0;
    pItemParam_1->m_Prev = gpTreeViewListItemParam;
    if ( gpTreeViewListItemParam )
      gpTreeViewListItemParam->m_Next = pItemParam_1;
    gpTreeViewListItemParam = pItemParam_1;
    if ( pItemParam_1->dwProcessId )
    {
      pItemParam_2 = pItemParam_1;
      while ( pItemParam_1->InheritedFromUniqueProcessId != pItemParam_2->dwProcessId
           || *(_QWORD *)&pItemParam_2->CreateTime > *(_QWORD *)&pItemParam_1->CreateTime )
      {
        pItemParam_2 = pItemParam_2->m_Prev;
        if ( !pItemParam_2 )
          goto LABEL_17;
      }
      pItemParam_1->pItemParam = pItemParam_2;
      while ( pItemParam_2->dwStyle & TVIF_PARAM )
      {
        pItemParam_2 = pItemParam_2->pItemParam;
        if ( !pItemParam_2 )
          goto LABEL_17;
      }
      pItemParam_1->dwStyle &= -3u;
    }
LABEL_17:
    pTreeList = CTreeList::GetTreeList(hWnd);
    if ( pItemParam_1->hIcon )
    {
      v7 = pItemParam_1->hIcon;
      v8 = CTreeList::GetImageList(pTreeList);
      nImage = ImageList_ReplaceIcon(v8, -1, v7);
    }
    else
    {
      nImage = 0;
    }
    v10 = (pItemParam_1->dwStyle & TVIF_IMAGE) == 0;
    pItemParam_1->nImage = nImage;
    if ( v10
      || (!sub_C350E0(pItemParam_1->szProcessName2) ? (pItemParam_1->dwStyle &= -2u) : (pItemParam_1->dwStyle |= 1u),
          pItemParam_1->dwStyle & 1 && gConfig.byte_14012ADFE) )
    {
      SendMessageW = ::SendMessageW;
    }
    else
    {
      sub_C27F20(hWnd, pItemParam_1);
      SendMessageW = ::SendMessageW;
      ::SendMessageW(ghWndTreeListView, 0x2000u, pItemParam_1->field_5B8, pItemParam_1->field_30 != 0);
    }
    v12 = pItemParam_1->pItemParam;
    if ( v12 )
    {
      if ( ++v12->field_30 == 1 )
      {
        if ( pItemParam_1->pItemParam->dwStyle & TVIF_IMAGE )
        {
          FindInfo.flags = 1;
          FindInfo.lParam = (LPARAM)pItemParam_1->pItemParam;
          v13 = SendMessageW(ghWndTreeListView, LVM_FINDITEMW, 0xFFFFFFFF, (LPARAM)&FindInfo);
          SendMessageW(ghWndTreeListView, LVM_REDRAWITEMS, v13, v13);
          v14 = pItemParam_1->pItemParam->field_5B8;
          if ( v14 )
          {
            SendMessageW(ghWndTreeListView, TREELIST_MSG_2000, v14, 1);
            if ( pItemParam_1->dwStyle & TVIF_IMAGE )
              SendMessageW(ghWndTreeListView, TREELIST_MSG_2001, pItemParam_1->pItemParam->field_5B8, 1);
          }
        }
      }
    }
    pItemParam = pItemParam_1;
  }
  return pItemParam;
}
// CDA11C: using guessed type int gdwRefreshCount;

//----- (00C27DD0) --------------------------------------------------------
tagTREEVIEWLISTITEMPARAM *__cdecl sub_C27DD0(HWND hWnd, void *pItem)
{
  tagTREEVIEWLISTITEMPARAM *result; // eax
  tagTREEVIEWLISTITEMPARAM *v3; // ebx
  LVITEMW lParam; // [esp+4h] [ebp-34h]

  memset(&lParam.iItem, 0, 0x30u);
  lParam.mask = 13;
  lParam.iItem = 0x7FFFFFFF;
  lParam.iSubItem = 0;
  lParam.state = 0;
  lParam.stateMask = 0;
  lParam.pszText = (LPWSTR)-1;
  lParam.iImage = 0;
  lParam.lParam = 0;
  result = (tagTREEVIEWLISTITEMPARAM *)malloc(0x890u);
  v3 = result;
  if ( result )
  {
    qmemcpy(result, &pItem, 0x890u);
    lParam.lParam = result;
    if ( SendMessageW(hWnd, LVM_INSERTITEMW, 0, (LPARAM)&lParam) == -1 )
      v3 = 0;
    result = v3;
  }
  return result;
}

//----- (00C27E70) --------------------------------------------------------
tagItem290_PageProcThreads *__cdecl tagItem290_PageProcThreads_InsertToList(HWND hWnd, char a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, int a19, int a20, int a21, int a22, int a23, int a24, int a25, int a26, int a27, int a28, int a29, int a30, int a31, int a32, int a33, int a34, int a35, int a36, int a37, int a38, int a39, int a40, int a41, int a42, int a43, int a44, int a45, int a46, int a47, int a48, int a49, int a50, int a51, int a52, int a53, int a54, int a55, int a56, int a57, int a58, int a59, int a60, int a61, int a62, int a63)
{
  tagItem290_PageProcThreads *result; // eax
  tagItem290_PageProcThreads **v66; // ecx
  LVITEMW Item; // [esp+0h] [ebp-34h]

  memset(&Item.iItem, 0, 0x30u);
  Item.mask = 0xD;
  Item.iItem = 0x7FFFFFFF;
  Item.iSubItem = 0;
  Item.state = 0;
  Item.stateMask = 0;
  Item.pszText = (LPWSTR)-1;
  Item.iImage = 0;
  Item.lParam = 0;
  result = (tagItem290_PageProcThreads *)malloc(0x290u);
  if ( result )
  {
    qmemcpy(result, &a2, sizeof(tagItem290_PageProcThreads));
    v66 = (tagItem290_PageProcThreads **)a65;
    Item.lParam = (tagTREEVIEWLISTITEMPARAM *)result;
    result->m_Next = *(_DWORD *)a65;
    *v66 = result;
    result = (tagItem290_PageProcThreads *)(SendMessageW(hWnd, LVM_INSERTITEMW, 0, (LPARAM)&Item) != -1);
  }
  return result;
}
// C27E70: too many input arguments, some ignored

//----- (00C27F20) --------------------------------------------------------
int __cdecl sub_C27F20(HWND hWnd, tagTREEVIEWLISTITEMPARAM *pItemParam)
{
  int result; // eax
  tagTREEVIEWLISTITEMPARAM *v3; // ecx
  tagTREEVIEWLISTITEMPARAM *v4; // eax
  LRESULT v5; // eax
  int v6; // eax
  bool v7; // zf
  tagTREEVIEWLISTITEMPARAM *v8; // eax
  LPARAM lParam; // [esp+4h] [ebp-10h]
  tagTREEVIEWLISTITEMPARAM *v10; // [esp+8h] [ebp-Ch]
  int (__cdecl *v11)(_DWORD *, _DWORD *); // [esp+Ch] [ebp-8h]
  bool v12; // [esp+13h] [ebp-1h]

  v12 = gConfig.bShowProcessTree != 0;
  result = pItemParam->field_5B8;
  if ( !result )
  {
    if ( gConfig.bShowProcessTree && (v3 = pItemParam->pItemParam) != 0 && v3->dwStyle & 2 )
    {
      v4 = (tagTREEVIEWLISTITEMPARAM *)v3->field_5B8;
      if ( !v4 )
      {
        if ( pItemParam->dwStyle & TVIF_IMAGE )
          v4 = (tagTREEVIEWLISTITEMPARAM *)sub_C27F20(hWnd, pItemParam->pItemParam);
        else
          v4 = pItemParam;
      }
    }
    else
    {
      v4 = 0;
    }
    lParam = (LPARAM)v4;
    v10 = pItemParam;
    v11 = sub_C31AF0;
    v5 = SendMessageW(hWnd, TREELIST_MSG_2004, 0, (LPARAM)&lParam);
    pItemParam->field_5B8 = v5;
    v6 = SendMessageW(hWnd, TREELIST_MSG_2005, v5, 0);
    v7 = v12 == 0;
    pItemParam->field_2C = v6;
    if ( v7 )
    {
      if ( pItemParam->field_30 )
        SendMessageW(hWnd, TREELIST_MSG_2000, pItemParam->field_5B8, 1);
      SendMessageW(hWnd, TREELIST_MSG_2001, pItemParam->field_5B8, ((unsigned int)pItemParam->dwStyle >> 2) & 1);
      v8 = pItemParam->pItemParam;
      if ( v8 && !v8->field_30 )
      {
        if ( !v8->field_5B8 )
          sub_C27F20(hWnd, pItemParam->pItemParam);
        SendMessageW(hWnd, TREELIST_MSG_2000, pItemParam->pItemParam->field_5B8, 1);
        SendMessageW(
          hWnd,
          TREELIST_MSG_2001,
          pItemParam->pItemParam->field_5B8,
          ((unsigned int)pItemParam->pItemParam->dwStyle >> TVIF_IMAGE) & 1);
      }
    }
    else
    {
      if ( pItemParam->field_30 )
        SendMessageW(hWnd, TREELIST_MSG_2000, pItemParam->field_5B8, 1);
      SendMessageW(hWnd, TREELIST_MSG_2001, pItemParam->field_5B8, ((unsigned int)pItemParam->dwStyle >> 2) & 1);
    }
    result = pItemParam->field_5B8;
  }
  return result;
}

//----- (00C28070) --------------------------------------------------------
void __cdecl TreeViewItemParam_InitGraph(tagTREEVIEWLISTITEMPARAM *pItem)
{
  CGraphData *v1; // eax
  CGraphData *v2; // eax
  int v3; // eax
  CGraphData *v4; // eax
  CGraphData *v5; // eax
  CGraphData *v6; // eax
  CGraphData *v7; // eax
  CGraphData *v8; // eax
  CGraphData *v9; // eax

  if ( !pItem->pGraphData1 )
  {
    v1 = InitGraphData(1, 2, 0);
    pItem->pGraphData1 = v1;
    v1->m_nItemID = 0;
    pItem->pGraphData1->m_Color = 0x3C943C;
    pItem->pGraphData1->m_dbMemorySize = db_onehundred;
    v2 = pItem->pGraphData1;
    if ( v2->m_nChildID == 2 )
    {
      v2->m_Item[0].Color = 255;
      pItem->pGraphData1->m_Item[0].dbMemorySize = db_onehundred;
    }
    v3 = pItem->dwProcessId;
    if ( v3 )
    {
      if ( v3 == -10 )
        pItem->pGraphData1->m_Color = 255;
    }
    else
    {
      pItem->pGraphData1->m_Item[0].Color = 0x3C943C;
    }
  }
  if ( !pItem->pGraphData2 )
  {
    v4 = InitGraphData(1, 1, 0);
    pItem->pGraphData2 = v4;
    v4->m_nItemID = 1;
    pItem->pGraphData2->m_Color = 0xAAAA;
    pItem->pGraphData2->m_dbMemorySize = db_onehundred;
  }
  if ( !pItem->pGraphDataPROCCPU )
  {
    v5 = InitGraphData(1, 2, 0);
    pItem->pGraphDataPROCCPU = v5;
    v5->m_nItemID = 2;
    pItem->pGraphDataPROCCPU->m_Color = 0xC83C1E;
    pItem->pGraphDataPROCCPU->m_dbMemorySize = db_one;
    pItem->pGraphDataPROCCPU->m_Item[0].Color = 0xC83CC8;
    pItem->pGraphDataPROCCPU->m_Item[0].dbMemorySize = db_one;
  }
  if ( gdwAdapterRuntingTime )
  {
    v6 = InitGraphData(1, 1, 0);
    pItem->pGraphData4 = v6;
    v6->m_nItemID = 4;
    pItem->pGraphData4->m_Color = 0x8080FF;
    pItem->pGraphData4->m_dbMemorySize = db_onehundred;
    v7 = InitGraphData(1, 1, 0);
    pItem->pGraphData5 = v7;
    v7->m_nItemID = 7;
    pItem->pGraphData5->m_Color = 0xFFC080;
    pItem->pGraphData5->m_dbMemorySize = db_one;
    v8 = InitGraphData(1, 1, 0);
    LODWORD(pItem->pGraphData6) = v8;
    v8->m_nItemID = 5;
    *(_DWORD *)(LODWORD(pItem->pGraphData6) + 48) = 0xAAAA;
    *(double *)(LODWORD(pItem->pGraphData6) + 40) = db_one;
    v9 = InitGraphData(1, 1, 0);
    pItem->pGraphData7 = v9;
    v9->m_nItemID = 6;
    pItem->pGraphData7->m_Color = 0x4080FF;
    pItem->pGraphData7->m_dbMemorySize = db_one;
  }
}
// CACDC0: using guessed type double db_onehundred;

//----- (00C282A0) --------------------------------------------------------
struct _IMAGELIST *InitSortableImageList()
{
  _IMAGELIST *himl; // ST20_4
  HICON v1; // edi
  HICON v2; // ebx

  himl = ImageList_Create(16, 16, 1u, 256, 256);
  v1 = LoadIconW(ghInstance, (LPCWSTR)0xCB);
  v2 = LoadIconW(ghInstance, (LPCWSTR)0x71);
  ImageList_ReplaceIcon(himl, -1, v1);
  ImageList_ReplaceIcon(himl, -1, v2);
  return himl;
}

//----- (00C28300) --------------------------------------------------------
HWND __cdecl CreateListCtrl(HWND hWnd, DWORD dwStyle, int a3, int a4, LONG dwNewLong, HMENU hMenu)
{
  HWND v6; // eax
  HWND v7; // esi
  HFONT v9; // ST28_4
  HWND v10; // eax
  HWND v11; // eax
  struct _IMAGELIST *v12; // esi
  LONG v13; // eax
  HWND v14; // [esp+8h] [ebp-18h]
  struct tagRECT Rect; // [esp+Ch] [ebp-14h]

  _mm_storeu_si128((__m128i *)&Rect, (__m128i)0i64);
  InitCommonControls();
  GetClientRect(hWnd, &Rect);
  v6 = CreateWindowExW(
         0,
         L"SysListView32",
         (LPCWSTR)&gszNullString,
         dwStyle,
         Rect.left,
         Rect.top,
         Rect.right,
         Rect.bottom,
         hWnd,
         hMenu,
         ghInstance,
         0);
  v7 = v6;
  v14 = v6;
  if ( !v6 )
    return 0;
  if ( !InitListHeader(v6, (UINT *)a3, (WORD *)a4, dwNewLong) )
  {
    DestroyWindow(v7);
    return 0;
  }
  SetClassLongW(v7, -12, 0);
  gOldListWndProc = (WNDPROC)SetWindowLongW(v7, -4, (LONG)Proxy_ListCtrlWndProc);
  SendMessageW(v7, 0x1036u, 0x4030u, 16432);
  v9 = ghConfigFont;
  v10 = (HWND)SendMessageW(v7, 0x101Fu, 0, 0);
  SendMessageW(v10, 0x30u, (WPARAM)v9, 0);
  SendMessageW(v7, 0x30u, (WPARAM)ghConfigFont, 0);
  v11 = (HWND)SendMessageW(v7, 0x104Eu, 0, 0);
  CTreeList::InitToolTips(v11);
  v12 = InitSortableImageList();
  v13 = GetWindowLongW(v14, -16);
  SetWindowLongW(v14, -16, v13 | 0x40);
  SendMessageW(v14, 0x1003u, 1u, (LPARAM)v12);
  return v14;
}

//----- (00C28460) --------------------------------------------------------
void __cdecl sub_C28460(tagTREEVIEWLISTITEMPARAM *a1)
{
  tagTREEVIEWLISTITEMPARAM *v1; // eax
  bool v2; // zf
  LRESULT nItem; // eax
  int v4; // eax
  tagTREEVIEWLISTITEMPARAM *v5; // ecx
  tagTREEVIEWLISTITEMPARAM *v6; // ecx
  tagTREEVIEWLISTITEMPARAM *i; // eax
  LVFINDINFOW FindInfo; // [esp+8h] [ebp-18h]

  SendMessageW(ghWndTreeListView, 0xBu, 0, 0);
  gbDllsOrHandlesSorting = 1;
  v1 = a1->pItemParam;
  if ( v1 )
  {
    v2 = v1->field_30-- == 1;
    if ( v2 )
    {
      if ( a1->pItemParam->dwStyle & 2 )
      {
        FindInfo.lParam = (LPARAM)a1->pItemParam;
        FindInfo.flags = LVFI_PARAM;
        nItem = SendMessageW(ghWndTreeListView, LVM_FINDITEMW, 0xFFFFFFFF, (LPARAM)&FindInfo);
        SendMessageW(ghWndTreeListView, LVM_REDRAWITEMS, nItem, nItem);
        v4 = a1->pItemParam->field_5B8;
        if ( v4 )
          SendMessageW(ghWndTreeListView, 0x2000u, v4, 0);
      }
    }
  }
  v5 = a1->m_Next;
  if ( v5 )
    v5->m_Prev = a1->m_Prev;
  else
    gpTreeViewListItemParam = a1->m_Prev;
  v6 = a1->m_Prev;
  if ( v6 )
    v6->m_Next = a1->m_Next;
  for ( i = gpTreeViewListItemParam; i; i = i->m_Prev )
  {
    if ( i->InheritedFromUniqueProcessId == a1->dwProcessId )
    {
      i->pItemParam = 0;
      if ( gConfig.bShowAllUsers || i->dwStyle & 0x40 )
        i->dwStyle |= 2u;
      if ( !(a1->dwStyle & 4) )
        i->dwStyle &= 0xFFFFFFFB;
    }
  }
  TreeViewListItemParam_Release(a1);
}
// CD53B5: using guessed type char gbDllsOrHandlesSorting;

//----- (00C28570) --------------------------------------------------------
tagTREEVIEWLISTITEMPARAM *__cdecl sub_C28570(HWND hWnd, tagTREEVIEWLISTITEMPARAM *pItem)
{
  tagTREEVIEWLISTITEMPARAM *result; // eax
  LVFINDINFOW lParam; // [esp+Ch] [ebp-18h]

  lParam.flags = 1;
  lParam.lParam = (LPARAM)pItem;
  result = (tagTREEVIEWLISTITEMPARAM *)SendMessageW(hWnd, LVM_FINDITEMW, 0xFFFFFFFF, (LPARAM)&lParam);
  if ( (signed int)result >= 0 )
  {
    SendMessageW(hWnd, LVM_DELETEITEM, (WPARAM)result, 0);
    result = pItem->pItemParam;
    if ( result )
    {
      if ( result->field_30 )
      {
        result = (tagTREEVIEWLISTITEMPARAM *)result->field_5B8;
        if ( result )
        {
          result = (tagTREEVIEWLISTITEMPARAM *)SendMessageW(hWnd, 0x2002u, (WPARAM)result, 0);
          if ( !result )
          {
            SendMessageW(hWnd, 0x2000u, pItem->pItemParam->field_5B8, 1);
            result = (tagTREEVIEWLISTITEMPARAM *)SendMessageW(hWnd, 0x2003u, pItem->pItemParam->field_5B8, 0);
          }
        }
      }
    }
  }
  return result;
}

//----- (00C28600) --------------------------------------------------------
void __cdecl DLLLISTITEMPARAM_Release(tagTREEVIEWLISTITEMPARAM *lpAddend)
{
  if ( !InterlockedDecrement(&lpAddend->field_0) )
  {
    if ( *(_DWORD *)lpAddend->gap154 )
      free(*(void **)lpAddend->gap154);
    if ( lpAddend->field_150 )
      free((void *)lpAddend->field_150);
    if ( *(_DWORD *)&lpAddend->gap154[4] )
      free(*(void **)&lpAddend->gap154[4]);
    if ( *(_DWORD *)&lpAddend->gap154[16] )
      free(*(void **)&lpAddend->gap154[16]);
    if ( *(_DWORD *)&lpAddend->gap154[20] )
      free(*(void **)&lpAddend->gap154[20]);
    if ( *(_DWORD *)&lpAddend->gap154[8] )
      free(*(void **)&lpAddend->gap154[8]);
    free(lpAddend);
  }
}

//----- (00C28690) --------------------------------------------------------
void __cdecl TreeViewListItemParam_Release(tagTREEVIEWLISTITEMPARAM *a1)
{
  CGraphData *v1; // eax
  CGraphData *v2; // eax
  CGraphData *v3; // eax

  if ( !InterlockedDecrement(&a1->nRefCount) )
  {
    if ( a1->hIcon )
      DestroyIcon(a1->hIcon);
    if ( a1->hFileIcon )
      DestroyIcon((HICON)a1->hFileIcon);
    if ( a1->field_344 )
      free(a1->field_344);
    if ( a1->pszValue314 )
      free((void *)a1->pszValue314);
    if ( a1->pszTitle )
      free((void *)a1->pszTitle);
    if ( a1->pNetCclrInfo )
      free(a1->pNetCclrInfo);
    if ( a1->szProcessName )
      free(a1->szProcessName);
    if ( a1->szProcessName2 )
      free(a1->szProcessName2);
    if ( a1->pszName )
      free((void *)a1->pszName);
    if ( a1->pszSystemName )
      free((void *)a1->pszSystemName);
    if ( a1->pszComments )
      free((void *)a1->pszComments);
    if ( a1->pszCommandLine )
      free((void *)a1->pszCommandLine);
    if ( a1->pszEnvBlock )
      free((void *)a1->pszEnvBlock);
    if ( a1->pszCurrentDirectory )
      free((void *)a1->pszCurrentDirectory);
    if ( a1->field_350 )
      free((void *)a1->field_350);
    if ( a1->pszCompany )
      free((void *)a1->pszCompany);
    if ( a1->pszFileDesc )
      free((void *)a1->pszFileDesc);
    if ( a1->m_ExtensionName )
      free(a1->m_ExtensionName);
    if ( a1->pszFullUserName )
      free((void *)a1->pszFullUserName);
    if ( a1->field_334 )
      free((void *)a1->field_334);
    if ( a1->pszPackageFullName )
      free((void *)a1->pszPackageFullName);
    if ( a1->field_33C )
      free((void *)a1->field_33C);
    if ( a1->bSupportWMIProviders )
      sub_C739A0(&a1->bSupportWMIProviders);
    if ( a1->field_3A0 )
      free((void *)a1->field_3A0);
    v1 = a1->pGraphData1;
    if ( v1 )
      GraphData_Release(v1, 1);
    v2 = a1->pGraphData2;
    if ( v2 )
      GraphData_Release(v2, 1);
    v3 = a1->pGraphDataPROCCPU;
    if ( v3 )
      GraphData_Release(v3, 1);
    free(a1);
  }
}

//----- (00C288B0) --------------------------------------------------------
char __cdecl CMainWnd::DrawItem(LPDRAWITEMSTRUCT pDrawItemStruct)
{
  LONG nColumn; // eax
  int nItem; // ecx
  WPARAM mCol; // edi
  char isFocused; // si
  unsigned int v6; // ecx
  __m128i v7; // xmm1
  char *v8; // edx
  unsigned int v9; // eax
  __m128i v10; // xmm0
  unsigned int nIndexFound; // esi
  unsigned int v12; // edi
  int v13; // ecx
  unsigned int nColIndex; // edi
  __m128i v15; // xmm1
  char *v16; // ecx
  unsigned int v17; // eax
  __m128i v18; // xmm0
  DWORD v19; // edi
  int iSubItem; // eax
  HWND v21; // edi
  COLORREF v22; // eax
  COLORREF v23; // eax
  LVITEMW ItemText; // [esp+Ch] [ebp-43B0h]
  tagLVITEMW lvitem; // [esp+40h] [ebp-437Ch]
  LVCOLUMNW ColumnInfo; // [esp+74h] [ebp-4348h]
  unsigned int v27; // [esp+94h] [ebp-4328h]
  COLORREF TextColor; // [esp+98h] [ebp-4324h]
  DWORD bFocused; // [esp+9Ch] [ebp-4320h]
  COLORREF BackColor; // [esp+A0h] [ebp-431Ch]
  HWND hWnd; // [esp+A4h] [ebp-4318h]
  COLORREF rect; // [esp+A8h] [ebp-4314h]
  int v33; // [esp+ACh] [ebp-4310h]
  COLORREF v34; // [esp+B0h] [ebp-430Ch]
  int v35; // [esp+B4h] [ebp-4308h]
  LPARAM lParam[4]; // [esp+B8h] [ebp-4304h]
  char v37; // [esp+C8h] [ebp-42F4h]
  WPARAM wParam[4]; // [esp+238h] [ebp-4184h]
  char v39; // [esp+248h] [ebp-4174h]
  __int16 szText[8192]; // [esp+3B8h] [ebp-4004h]

  hWnd = pDrawItemStruct->hwndItem;
  nColumn = GetWindowLongW(hWnd, GWLP_USERDATA);
  nItem = pDrawItemStruct->itemID;
  mCol = nColumn;
  v27 = nColumn;
  lvitem.mask = 0xE;
  lvitem.iItem = nItem;
  lvitem.iSubItem = 0;
  SendMessageW(hWnd, LVM_GETITEMW, 0, (LPARAM)&lvitem);
  LOBYTE(bFocused) = pDrawItemStruct->itemState & LVIS_FOCUSED;
  isFocused = bFocused;
  QueryListItemColor(hWnd, pDrawItemStruct->itemData, bFocused, &TextColor, &BackColor);
  SetTextColor(pDrawItemStruct->hDC, TextColor);
  SetBkMode(pDrawItemStruct->hDC, 2);
  SetBkColor(pDrawItemStruct->hDC, BackColor);
  if ( hWnd == ghWndTreeListView )
    return sub_C256D0(
             isFocused,
             (tagTREEVIEWLISTITEMPARAM *)pDrawItemStruct->itemData,
             gConfig.dwProcessColumnMap[pDrawItemStruct->itemAction],
             pDrawItemStruct->hDC,
             (RECT *)pDrawItemStruct->gap1C);
  if ( !SendMessageW(hWnd, LVM_GETCOLUMNORDERARRAY, mCol, (LPARAM)wParam) )
  {
    v6 = 0;
    if ( mCol )
    {
      if ( mCol >= 8 )
      {
        v7 = _mm_load_si128((const __m128i *)&gIntArray);
        v8 = &v39;
        do
        {
          v9 = v6 + 4;
          v8 += 32;
          v10 = _mm_add_epi32(_mm_shuffle_epi32(_mm_cvtsi32_si128(v6), 0), v7);
          v6 += 8;
          _mm_storeu_si128((__m128i *)v8 - 3, v10);
          _mm_storeu_si128((__m128i *)v8 - 2, _mm_add_epi32(_mm_shuffle_epi32(_mm_cvtsi32_si128(v9), 0), v7));
        }
        while ( v6 < mCol - (mCol & 7) );
      }
      for ( ; v6 < mCol; ++v6 )
        wParam[v6] = v6;
    }
  }
  nIndexFound = 0;
  BackColor = 0;
  if ( mCol )
  {
    do
    {
      ColumnInfo.mask = 3;
      v12 = nIndexFound;
      SendMessageW(hWnd, LVM_GETCOLUMNW, wParam[nIndexFound], (LPARAM)&ColumnInfo);
      v13 = *(_DWORD *)pDrawItemStruct->gap1C;
      bFocused = ColumnInfo.cx;
      rect = v13 + BackColor;
      v33 = *(_DWORD *)&pDrawItemStruct->gap1C[4];
      v35 = *(_DWORD *)&pDrawItemStruct->gap1C[12];
      v34 = BackColor + v13 + ColumnInfo.cx;
      if ( hWnd == ghWndDllsListCtrl )
      {
        nColIndex = GetWindowLongW(hWnd, GWLP_USERDATA);
        if ( !SendMessageW(hWnd, LVM_GETCOLUMNORDERARRAY, nColIndex, (LPARAM)lParam) )
        {
          nIndexFound = 0;
          if ( nColIndex )
          {
            if ( nColIndex >= 8 )
            {
              v15 = _mm_load_si128((const __m128i *)&gIntArray);
              v16 = &v37;
              do
              {
                v17 = nIndexFound + 4;
                v16 += 32;
                v18 = _mm_add_epi32(_mm_shuffle_epi32(_mm_cvtsi32_si128(nIndexFound), 0), v15);
                nIndexFound += 8;
                _mm_storeu_si128((__m128i *)v16 - 3, v18);
                _mm_storeu_si128((__m128i *)v16 - 2, _mm_add_epi32(_mm_shuffle_epi32(_mm_cvtsi32_si128(v17), 0), v15));
              }
              while ( nIndexFound < nColIndex - (nColIndex & 7) );
            }
            for ( ; nIndexFound < nColIndex; ++nIndexFound )
              lParam[nIndexFound] = nIndexFound;
          }
        }
        if ( gConfig.dwDllColumnMap[lParam[nIndexFound]] == IDS_VIRUSTOTAL )
        {
          v19 = pDrawItemStruct->itemData;
          if ( sub_C71820(*(ListItemData1 **)(v19 + 364)) )
          {
            if ( sub_C72910(*(ListItemData1 **)(v19 + 364)) )
              SetTextColor(pDrawItemStruct->hDC, 0xFFu);
            else
              SetTextColor(pDrawItemStruct->hDC, 0xFF0000u);
            SelectObject(pDrawItemStruct->hDC, ghConfigUnderlineFont);
          }
        }
        else
        {
          SetTextColor(pDrawItemStruct->hDC, TextColor);
          SelectObject(pDrawItemStruct->hDC, ghConfigFont);
        }
        v12 = nIndexFound;
      }
      ItemText.cchTextMax = 0x1FFF;
      szText[0] = 0;
      iSubItem = wParam[v12];
      v21 = hWnd;
      ItemText.iSubItem = iSubItem;
      ItemText.pszText = (LPWSTR)szText;
      SendMessageW(hWnd, LVM_GETITEMTEXTW, pDrawItemStruct->itemID, (LPARAM)&ItemText);
      PE_DrawText(pDrawItemStruct->hDC, (const wchar_t *)szText, (tagRECT *)&rect, ColumnInfo.fmt & 1);
      ++nIndexFound;
      BackColor += bFocused;
    }
    while ( nIndexFound < v27 );
  }
  else
  {
    v21 = hWnd;
  }
  if ( pDrawItemStruct->itemState & 1 )
  {
    v22 = GetSysColor(8);
    SetTextColor(pDrawItemStruct->hDC, v22);
    v23 = GetSysColor(5);
    SetBkColor(pDrawItemStruct->hDC, v23);
  }
  if ( v21 == ghWndTreeListView )
  {
    rect = 0;
    SendMessageW(ghWndTreeListView, LVM_GETITEMRECT, 0, (LPARAM)&rect);
    if ( v33 != sdwRectTopInDrawItem )
    {
      sdwRectTopInDrawItem = v33;
      InvalidateRect(ghWndTreeListView, 0, 0);
    }
  }
  return 1;
}
// CAEA50: using guessed type tagRECT gIntArray;
// CDA338: using guessed type int sdwRectTopInDrawItem;

//----- (00C28D00) --------------------------------------------------------
int __cdecl UpdateMenuStatus(char bEnabled, int nPos)
{
  HMENU v2; // eax
  HMENU hSubMenu; // eax
  HMENU hSubMenu_1; // ebx
  int nCount; // eax
  UINT nIndex; // edi
  WPARAM uID; // esi
  int nCount_1; // [esp+8h] [ebp-4h]

  v2 = GetMenu(ghMainWnd);
  hSubMenu = GetSubMenu(v2, nPos);
  hSubMenu_1 = hSubMenu;
  nCount = GetMenuItemCount(hSubMenu);
  nIndex = 0;
  nCount_1 = nCount;
  if ( nCount > 0 )
  {
    while ( 1 )
    {
      nCount = GetMenuItemID(hSubMenu_1, nIndex);
      uID = nCount;
      if ( nCount == IDM_VIEW_SHOW_UNNAMED_HANDLES_AND_MAPPINGS || nCount == IDM_OPTIONS_HIGHLIGHT_RELOCATED_DLLS )
        goto LABEL_9;
      nCount = EnableMenuItem(hSubMenu_1, nIndex, (bEnabled == 0) | (unsigned int)MF_BYPOSITION);
      if ( uID == IDM_PROCESS_PROPERTIES )
        break;
      if ( uID == IDM_PROCESS_KILL_PROCESS )
        goto LABEL_8;
LABEL_9:
      if ( (signed int)++nIndex >= nCount_1 )
        return nCount;
    }
    uID = IDM_VIEW_PROCESS_PROPERTIES;
LABEL_8:
    nCount = SendMessageW(ghWndToolbar, TB_ENABLEBUTTON, uID, (unsigned __int8)bEnabled);
    goto LABEL_9;
  }
  return nCount;
}

//----- (00C28DA0) --------------------------------------------------------
BOOL __cdecl sub_C28DA0(tagTREEVIEWLISTITEMPARAM *pItemParam)
{
  tagTREEVIEWLISTITEMPARAM *i; // edx
  tagTREEVIEWLISTITEMPARAM *v2; // eax
  char v3; // bl

  SendMessageW(ghWndTreeListView, WM_SETREDRAW, 0, 0);
  for ( i = gpTreeViewListItemParam; i; i = i->m_Prev )
  {
    v2 = i->pItemParam;
    v3 = 1;
    if ( v2 )
    {
      while ( 1 )
      {
        v3 = (v2->dwStyle & 4) != 0 ? v3 : 0;
        if ( v2 == pItemParam )
          break;
        v2 = v2->pItemParam;
        if ( !v2 )
          goto LABEL_11;
      }
      if ( v3 && (gConfig.bShowAllUsers || i->dwStyle & 0x40) )
        i->dwStyle |= 2u;
      else
        i->dwStyle &= -3u;
    }
LABEL_11:
    ;
  }
  gbDllsOrHandlesSorting = 1;
  return SetEvent(ghTimerRefreshEvent);
}
// CD53B5: using guessed type char gbDllsOrHandlesSorting;

//----- (00C28E30) --------------------------------------------------------
char __cdecl ProcStrings_FindItem(HWND hDlg, HWND hWndList, tagFINDREPLACEW *pFindReplace, LPCWSTR lpszFindWhat, PBOOL pbFound, wchar_t *pszBuffer)
{
  tagFINDREPLACEW *FindrePlace; // ebx
  char fDownFind; // al
  LRESULT nCount; // esi
  int v9; // eax
  LRESULT nItemCount; // eax
  const wchar_t *lpstrFindWhat; // ST0C_4
  HWND hWndListCtrl; // edi
  int v14; // esi
  unsigned int v15; // kr00_4
  const wchar_t *v16; // edi
  LPWSTR v17; // edx
  int v18; // esi
  WCHAR v19; // ax
  int v20; // esi
  wchar_t *v21; // eax
  int v22; // eax
  LPWSTR v23; // edx
  WCHAR v24; // ax
  wchar_t *v25; // ebx
  tagFINDREPLACEW *v26; // esi
  const wchar_t *v27; // ecx
  int v28; // edx
  wchar_t v29; // ax
  int v30; // eax
  wchar_t v31; // ax
  unsigned int v32; // kr04_4
  LPWSTR v33; // edx
  int v34; // esi
  WCHAR v35; // ax
  signed int v36; // ecx
  HWND hWndListCtrl_1; // ebx
  HWND v38; // ST00_4
  LRESULT i; // eax
  WPARAM v40; // edi
  tagLVCOLUMNW ColumnInfo; // [esp+Ch] [ebp-427Ch]
  LVITEMW Item; // [esp+2Ch] [ebp-425Ch]
  LRESULT nNumberItem; // [esp+60h] [ebp-4228h]
  WPARAM nColumnIndex; // [esp+64h] [ebp-4224h]
  tagFINDREPLACEW *FindReplace; // [esp+68h] [ebp-4220h]
  unsigned int v46; // [esp+6Ch] [ebp-421Ch]
  HWND hWndDlg; // [esp+70h] [ebp-4218h]
  PBOOL pfbFound; // [esp+74h] [ebp-4214h]
  HWND hWndLC; // [esp+78h] [ebp-4210h]
  WPARAM nItem; // [esp+7Ch] [ebp-420Ch]
  char bDownFind; // [esp+83h] [ebp-4205h]
  wchar_t v52[8192]; // [esp+84h] [ebp-4204h]
  __int16 Text[256]; // [esp+4084h] [ebp-204h]

  FindrePlace = pFindReplace;
  hWndDlg = hDlg;
  pfbFound = pbFound;
  fDownFind = pFindReplace->Flags & FR_DOWN;
  hWndLC = hWndList;
  FindReplace = pFindReplace;
  bDownFind = fDownFind;
  nItem = SendMessageW(hWndList, LVM_GETNEXTITEM, 0xFFFFFFFF, 2);
  nCount = SendMessageW(hWndList, LVM_GETITEMCOUNT, 0, 0);
  if ( (nItem & 0x80000000) != 0 )
  {
    if ( bDownFind )
    {
      nItem = 0;
    }
    else
    {
      if ( *(_BYTE *)pfbFound )
      {
__FoundNothingAndQuit:
        wsprintf((wchar_t *)Text, L"Cannot find string \"%s\"", FindrePlace->lpstrFindWhat);
        MessageBoxW(hWndDlg, (LPCWSTR)Text, L"Process Explorer", 0x30u);
        return 0;
      }
      nItem = nCount;
    }
  }
  if ( *(_BYTE *)pfbFound )
  {
    v9 = wcscmp(lpszFindWhat, pszBuffer);
    if ( v9 )
      v9 = -(v9 < 0) | 1;
    if ( !v9 )
    {
      if ( bDownFind )
      {
        if ( (signed int)++nItem >= nCount )
          goto __FoundNothingAndQuit;
      }
      else if ( (--nItem & 0x80000000) != 0 )
      {
        goto __FoundNothingAndQuit;
      }
    }
  }
  nItemCount = SendMessageW(hWndLC, LVM_GETITEMCOUNT, 0, 0);
  lpstrFindWhat = pFindReplace->lpstrFindWhat;
  nNumberItem = nItemCount;
  wcscpy_s(pszBuffer, 0x2000u, lpstrFindWhat);
  hWndListCtrl = hWndLC;
  while ( 1 )
  {
    ColumnInfo.mask = 2;
    v14 = 0;
    nColumnIndex = 0;
    if ( SendMessageW(hWndListCtrl, LVM_GETCOLUMNW, 0, (LPARAM)&ColumnInfo) )
      break;
LABEL_46:
    v36 = 2 * (bDownFind != 0) - 1 + nItem;
    nItem = v36;
    if ( v36 <= 0 || v36 == nNumberItem + 1 )
      goto __FoundNothingAndQuit;
  }
  while ( 1 )
  {
    Item.iSubItem = v14;
    v52[0] = 0;
    Item.pszText = v52;
    Item.cchTextMax = 0x2000;
    SendMessageW(hWndListCtrl, LVM_GETITEMTEXTW, nItem, (LPARAM)&Item);
    v15 = wcslen(v52);
    v16 = FindrePlace->lpstrFindWhat;
    v17 = FindrePlace->lpstrFindWhat;
    v18 = (int)(v17 + 1);
    do
    {
      v19 = *v17;
      ++v17;
    }
    while ( v19 );
    if ( v15 >= ((signed int)v17 - v18) >> 1 )
    {
      if ( !(FindrePlace->Flags & 2) )
      {
        v23 = FindrePlace->lpstrFindWhat;
        v46 = 0;
        do
        {
          v24 = *v23;
          ++v23;
        }
        while ( v24 );
        if ( v15 - (v23 - (v16 + 1)) != -1 )
        {
          v25 = v52;
          do
          {
            v26 = FindReplace;
            v27 = v16;
            v28 = (int)(v16 + 1);
            if ( FindReplace->Flags & 4 )
            {
              do
              {
                v29 = *v27;
                ++v27;
              }
              while ( v29 );
              v30 = wcsncmp(v25, v16, ((signed int)v27 - v28) >> 1);
            }
            else
            {
              do
              {
                v31 = *v27;
                ++v27;
              }
              while ( v31 );
              v30 = _wcsnicmp(v25, v16, ((signed int)v27 - v28) >> 1);
            }
            if ( v30 == 0 )
              goto LABEL_49;
            ++v46;
            ++v25;
            v32 = wcslen(v52);
            v16 = v26->lpstrFindWhat;
            v33 = v26->lpstrFindWhat;
            v34 = (int)(v33 + 1);
            do
            {
              v35 = *v33;
              ++v33;
            }
            while ( v35 );
          }
          while ( v46 < v32 - (((signed int)v33 - v34) >> 1) + 1 );
          FindrePlace = FindReplace;
        }
        goto LABEL_45;
      }
      v20 = 0;
      if ( v52[0] )
        break;
    }
LABEL_45:
    hWndListCtrl = hWndLC;
    v14 = nColumnIndex++ + 1;
    if ( !SendMessageW(hWndLC, LVM_GETCOLUMNW, nColumnIndex, (LPARAM)&ColumnInfo) )
      goto LABEL_46;
  }
  v21 = v52;
  if ( !v52[0] )
    goto LABEL_24;
  while ( 1 )
  {
    do
    {
      if ( *v21 == 32 )
        break;
      v21 = &v52[++v20];
    }
    while ( v52[v20] );
LABEL_24:
    if ( FindrePlace->Flags & 4 )
    {
      v22 = wcscmp(v52, FindrePlace->lpstrFindWhat);
      if ( v22 )
        v22 = -(v22 < 0) | 1;
    }
    else
    {
      v22 = _wcsicmp(v52, FindrePlace->lpstrFindWhat);
    }
    if ( v22 == 0 )
      break;
    v21 = &v52[++v20];
    if ( !v52[v20] )
      goto LABEL_45;
  }
LABEL_49:
  hWndListCtrl_1 = hWndLC;
  v38 = hWndLC;
  *(_BYTE *)pfbFound = 1;
  for ( i = SendMessageW(v38, LVM_GETNEXTITEM, 0xFFFFFFFF, 2);
        i != -1;
        i = SendMessageW(hWndListCtrl_1, LVM_GETNEXTITEM, 0xFFFFFFFF, 2) )
  {
    Item.stateMask = 3;
    Item.state = 0;
    SendMessageW(hWndListCtrl_1, LVM_SETITEMSTATE, i, (LPARAM)&Item);
  }
  v40 = nItem;
  Item.stateMask = 3;
  Item.state = 3;
  SendMessageW(hWndListCtrl_1, LVM_SETITEMSTATE, nItem, (LPARAM)&Item);
  SendMessageW(hWndListCtrl_1, LVM_ENSUREVISIBLE, v40, 0);
  SetFocus(hWndListCtrl_1);
  return 1;
}

//----- (00C29300) --------------------------------------------------------
void InitDrawEngine()
{
  int index; // esi
  int v1; // eax
  int v2; // ST10_4
  signed int v3; // esi
  int v4; // ST10_4
  signed int v5; // esi
  int v6; // ST10_4
  HGDIOBJ v7; // eax
  int v8; // eax
  int v9; // eax
  unsigned __int16 v10; // cx
  signed int v11; // ecx
  int v12; // eax
  unsigned __int16 v13; // cx
  signed int v14; // ecx
  int nItem; // eax
  unsigned __int16 v16; // cx
  signed int uID_2; // ecx
  int v18; // eax
  unsigned __int16 v19; // cx
  signed int uID_1; // ecx
  DWORD dwOpacity; // eax
  COLORREF v22; // eax
  int index_1; // edi
  SHORT *pwProcessColumns; // ebx
  int *pdwProcessColumnMap; // esi
  int index_2; // esi
  signed int index_3; // edi
  int uID; // eax
  int dwIndex_2; // esi
  CRegVar *var; // edi
  tagRegKeyInfo KeyInfo; // [esp+Ch] [ebp-768h]
  HKEY hSubKey; // [esp+18h] [ebp-75Ch]
  DWORD dwValue[446]; // [esp+1Ch] [ebp-758h]
  tagLOGFONTW LogFont; // [esp+714h] [ebp-60h]

  RegDeleteKeyW(HKEY_CURRENT_USER, L"Software\\Systems Internals\\Process Explorer");
  memset(&gConfig, 0, 0x47E0u);
  gConfig.WindowPlacement[0].showCmd = SW_SHOWNORMAL;
  gConfig.WindowPlacement[1].flags = MulDiv(50, gLogPixelSize.y, 96);
  gConfig.WindowPlacement[1].ptMinPosition.x = MulDiv(650, gLogPixelSize.y, 96);
  gConfig.WindowPlacement[1].length = MulDiv(100, gLogPixelSize.x, 96);
  gConfig.WindowPlacement[1].showCmd = MulDiv(900, gLogPixelSize.x, 96);
  gConfig.WindowPlacement[0].length = 0x2C;
  gConfig.WindowPlacement[PropWindowplacement].ptMaxPosition.x = MulDiv(150, gLogPixelSize.y, 96);
  gConfig.WindowPlacement[PropWindowplacement].ptMinPosition.y = MulDiv(150, gLogPixelSize.x, 96);
  gConfig.WindowPlacement[FindWindowplacement].ptMinPosition.y = 0x2C;
  gConfig.WindowPlacement[SysinfoWindowplacement].showCmd = MulDiv(40, gLogPixelSize.y, 96);
  gConfig.WindowPlacement[SysinfoWindowplacement].flags = MulDiv(40, gLogPixelSize.x, 96);
  gConfig.WindowPlacement[DllPropWindowplacement].flags = 0x2C;
  gConfig.WindowPlacement[StackWindowPlacement].ptMaxPosition.y = MulDiv(40, gLogPixelSize.y, 96);
  gConfig.WindowPlacement[StackWindowPlacement].ptMaxPosition.x = MulDiv(40, gLogPixelSize.x, 96);
  gConfig.WindowPlacement[SysinfoWindowplacement].ptMaxPosition.x = 0x2C;
  gConfig.WindowPlacement[StackWindowPlacement|PropWindowplacement].ptMinPosition.x = MulDiv(40, gLogPixelSize.y, 96);
  gConfig.WindowPlacement[StackWindowPlacement|PropWindowplacement].showCmd = MulDiv(40, gLogPixelSize.x, 96);
  gConfig.WindowPlacement[SysinfoWindowplacement|PropWindowplacement].showCmd = 0x2C;
  gConfig.ToolBandInfo[0].nWidth = -1;
  gConfig.ToolBandInfo[1].nWidth = -1;
  gConfig.ToolBandInfo[2].nWidth = -1;
  gConfig.ToolBandInfo[3].nWidth = -1;
  index = 0;
  gConfig.ToolBandInfo[4].nWidth = -1;
  gConfig.ToolBandInfo[5].nWidth = -1;
  gConfig.ToolBandInfo[6].nWidth = -1;
  gConfig.ToolBandInfo[7].nWidth = -1;
  gConfig.dwProcessColumnCount = 6;
  do
  {
    v1 = gProcessColumns[index].wID;
    v2 = gLogPixelSize.x;
    dwValue[index + 97] = v1;
    gConfig.dwProcessColumnMap[index] = v1;
    gConfig.dwProcessColumns[index] = MulDiv((unsigned __int16)word_CCD1F2[2 * index], v2, 96);
    ++index;
  }
  while ( index < gConfig.dwProcessColumnCount );
  gConfig.dwHandleColumnCount = 2;
  v3 = 0;
  do
  {
    v4 = gLogPixelSize.x;
    gConfig.dwIdsOfHandleColumnMap[v3] = gHandleColumns[v3].wID;
    gConfig.dwHandleColumns[v3] = MulDiv(gHandleColumns[v3].nWidth, v4, 96);
    ++v3;
  }
  while ( v3 < (signed int)gConfig.dwHandleColumnCount );
  gConfig.dwDllColumnCount = 4;
  v5 = 0;
  do
  {
    v6 = gLogPixelSize.x;
    gConfig.dwDllColumnMap[v5] = gDllColumns[v5].wID;
    gConfig.dwDllColumns[v5] = MulDiv(gDllColumns[v5].nWidth, v6, 96);
    ++v5;
  }
  while ( v5 < (signed int)gConfig.dwDllColumnCount );
  v7 = GetStockObject(DEFAULT_GUI_FONT);
  GetObjectW(v7, sizeof(LOGFONTW), &LogFont);
  LogFont.lfWeight = 400;
  v8 = MulDiv(8, gLogPixelSize.y, 72);
  LogFont.lfWidth = 0;
  LogFont.lfHeight = -v8;
  qmemcpy(&gConfig.UnicodeFont, &LogFont, sizeof(gConfig.UnicodeFont));
  KeyInfo.szKeyName = (int)_wcsdup(L"Software\\Sysinternals\\Process Explorer");
  LoadConfigItemFromRegistry(&KeyInfo, gConfigItems);
  if ( gConfig.UnicodeFont.lfHeight > 0 )
    gConfig.UnicodeFont.lfHeight = -MulDiv(gConfig.UnicodeFont.lfHeight, gLogPixelSize.y, 72);
  if ( !RegOpenKeyW(HKEY_CURRENT_USER, L"Software\\Sysinternals\\Process Explorer", &hSubKey) )
  {
    KeyInfo.nLength = 0x6F8;
    if ( !RegQueryValueExW(hSubKey, L"Settings", 0, 0, (LPBYTE)dwValue, (LPDWORD)&KeyInfo.nLength)
      && dwValue[0] - 501 <= 320 )
    {
      v9 = 0;
      if ( (signed int)dwValue[96] <= 0 )
      {
__Loop:
        nItem = 0;
        if ( (signed int)dwValue[129] <= 0 )
        {
LABEL_31:
          v18 = 0;
          if ( (signed int)dwValue[162] <= 0 )
          {
LABEL_37:
            sub_C24F50(&gConfig, dwValue, KeyInfo.nLength);
            RegDeleteValueW(hSubKey, L"Settings");
            CloseHandle(hSubKey);
            dwOpacity = gConfig.dwOpacity;
            if ( !gConfig.dwOpacity )
              dwOpacity = 100;
            gConfig.dwOpacity = dwOpacity;
            v22 = gConfig.ColorOwn;
            if ( !gConfig.ColorOwn )
              v22 = 0xFFD0D0;
            gConfig.ColorOwn = v22;
            if ( !gConfig.dwProcessColumnMap[0] )
              qmemcpy(gConfig.dwProcessColumnMap, &dwValue[97], 0x80u);
          }
          else
          {
            while ( 1 )
            {
              v19 = *((_WORD *)&dwValue[54] + v18);
              if ( !v19 )
                break;
              if ( v19 > 2000u )
                break;
              uID_1 = dwValue[v18 + 163];
              if ( uID_1 <= 0 || uID_1 > 41000 )
                break;
              if ( ++v18 >= (signed int)dwValue[162] )
                goto LABEL_37;
            }
          }
        }
        else
        {
          while ( 1 )
          {
            v16 = *((_WORD *)&dwValue[70] + nItem);
            if ( !v16 )
              break;
            if ( v16 > 2000u )
              break;
            uID_2 = dwValue[nItem + 130];
            if ( uID_2 <= 0 || uID_2 > 41000 )
              break;
            if ( ++nItem >= (signed int)dwValue[129] )
              goto LABEL_31;
          }
        }
      }
      else
      {
        while ( 1 )
        {
          v10 = *((_WORD *)&dwValue[38] + v9);
          if ( !v10 )
            break;
          if ( v10 > 2000u )
            break;
          v11 = dwValue[v9 + 374];
          if ( v11 <= 0 || v11 > 41000 )
            break;
          if ( ++v9 >= (signed int)dwValue[96] )
            goto __Loop;
        }
        v12 = 0;
        while ( 1 )
        {
          v13 = *((_WORD *)&dwValue[38] + v12);
          if ( !v13 )
            break;
          if ( v13 > 2000u )
            break;
          v14 = dwValue[v12 + 97];
          if ( v14 <= 0 || v14 > 41000 )
            break;
          if ( ++v12 >= (signed int)dwValue[96] )
            goto __Loop;
        }
      }
    }
  }
  index_1 = 0;
  if ( gConfig.dwProcessColumnCount > 0 )
  {
    pwProcessColumns = gConfig.dwProcessColumns;
    pdwProcessColumnMap = gConfig.dwProcessColumnMap;
    do
    {
      if ( *pdwProcessColumnMap == 3 )
      {
        memmove_0(pdwProcessColumnMap, pdwProcessColumnMap + 1, 4 * (--gConfig.dwProcessColumnCount - index_1));
        memmove_0(pwProcessColumns, pwProcessColumns + 1, 2 * (gConfig.dwProcessColumnCount - index_1));
      }
      ++index_1;
      ++pdwProcessColumnMap;
      ++pwProcessColumns;
    }
    while ( index_1 < gConfig.dwProcessColumnCount );
  }
  index_2 = 0;
  index_3 = -1;
  if ( gConfig.dwProcessColumnCount <= 0 )
    goto LABEL_68;
  do
  {
    if ( gConfig.dwProcessColumnMap[index_2] == IDS_PID )
    {
      index_3 = index_2;
      if ( gConfig.bETWStandardUserWarning )
        break;
    }
    else if ( !IsBuiltinAdministrative() && !gConfig.bETWStandardUserWarning )
    {
      uID = gConfig.dwProcessColumnMap[index_2];
      if ( uID >= IDS_NETWORK_RECEIVES && uID <= IDS_DISK_DELTA_TOTAL_BYTES )
      {
        gConfig.bETWStandardUserWarning = 1;
        MessageBoxW(
          0,
          L"Note that Disk and Networking information requires administrative rights",
          L"Process Explorer",
          MB_ICONEXCLAMATION);
        if ( index_3 != -1 )
          goto LABEL_60;
      }
    }
    ++index_2;
  }
  while ( index_2 < gConfig.dwProcessColumnCount );
  if ( index_3 == -1 )
  {
LABEL_68:
    gConfig.dwProcessColumnMap[index_2] = IDS_PID;
    gConfig.dwProcessColumns[index_2] = 200;
    ++gConfig.dwProcessColumnCount;
  }
LABEL_60:
  dwIndex_2 = 0;
  if ( (signed int)gConfig.dwNumColumnsets > 0 )
  {
    var = gConfig.strMenuCulumnSet;
    do
    {
      RegVar_ReadWrite(0, dwIndex_2++, var);
      ++var;
    }
    while ( dwIndex_2 < (signed int)gConfig.dwNumColumnsets );
  }
  if ( !gConfig.strNtSymbolPath[0] )
    GetEnvironmentVariableW(L"_NT_SYMBOL_PATH", gConfig.strNtSymbolPath, 0x104u);
  ghConfigFont = CreateFontIndirectW(&gConfig.UnicodeFont);
  qmemcpy(&LogFont, &gConfig.UnicodeFont, sizeof(LogFont));
  LogFont.lfUnderline = 1;
  ghConfigUnderlineFont = CreateFontIndirectW(&LogFont);
  free((void *)KeyInfo.szKeyName);
}
// C293A1: user specified stroff has not been processed: WINDOWPLACEMENT offset 44
// C293D0: user specified stroff has not been processed: WINDOWPLACEMENT offset 44
// C293FC: user specified stroff has not been processed: WINDOWPLACEMENT offset 44
// C29428: user specified stroff has not been processed: WINDOWPLACEMENT offset 44
// C2944A: user specified stroff has not been processed: WINDOWPLACEMENT offset 44
