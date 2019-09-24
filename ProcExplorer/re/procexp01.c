
//----- (00BEF610) --------------------------------------------------------
char __cdecl UpdateMenuItemWithAccountInfo(HWND hWnd, tagAccountInfo *pInfo, DWORD dwMenuId)
{
  CCmdString *v3; // edi
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
  CCmdString *v15; // eax
  CCmdString *v16; // eax
  WCHAR *v17; // esi
  const WCHAR *v18; // esi
  int v19; // eax
  wchar_t *v20; // esi
  CCmdString *v21; // eax
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

  v3 = (CCmdString *)malloc(2u);
  hKey.unused = (int)v3;
  LOWORD(v3->m_String) = 0;
  v38 = 0;
  lpszFile = (WCHAR *)malloc(2u);
  v31.unused = (int)lpszFile;
  *lpszFile = 0;
  ret = 0;
  v5 = malloc(2u);
  index = 0;
  v29 = v5;
  *v5 = 0;
  v7 = (tagAccountInfo **)garrAccountInfo.baseclass_0._Mypair._Myval2._Myfirst;
  nCount = (_DWORD)(garrAccountInfo.baseclass_0._Mypair._Myval2._Mylast
                  - garrAccountInfo.baseclass_0._Mypair._Myval2._Myfirst) >> 2;
  LOBYTE(v38) = 2;
  if ( nCount )
  {
    while ( 1 )
    {
      v9 = v7[index];
      v7 = (tagAccountInfo **)garrAccountInfo.baseclass_0._Mypair._Myval2._Myfirst;
      if ( v9->nMenuID == dwMenuId )
        break;
      if ( ++index >= nCount )
        goto LABEL_4;
    }
    pInfoTemp = (tagAccountInfo *)*((_DWORD *)garrAccountInfo.baseclass_0._Mypair._Myval2._Myfirst + index);
  }
  else
  {
LABEL_4:
    pInfoTemp = (tagAccountInfo *)KeyHandle;
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
    if ( pInfoTemp != (tagAccountInfo *)-1048 )
      v13 = (const WCHAR **)pInfoTemp->szProfileImgPath;
    v14 = _wcsdup((const wchar_t *)v13);
    hKey.unused = (int)v14;
    v15 = CCmdString::operator+((CCmdString *)&ppstr, (CCmdString *)&hKey, L"\\ntuser.dat");
    dwMessageId = (DWORD)v3;
    v3 = (CCmdString *)_wcsdup(v15->m_String);
    hKey.unused = (int)v3;
    free((void *)dwMessageId);
    free(ppstr);
    free(v14);
    v16 = RequerySystemEnvironmentString((CCmdString *)&ppstr, v3);
    v17 = lpszFile;
    lpszFile = _wcsdup(v16->m_String);
    v31.unused = (int)lpszFile;
    free(v17);
    free(ppstr);
    v18 = pInfoTemp_1->szUserName;
    dwMessageId = RegLoadKeyW(HKEY_USERS, pInfoTemp_1->szUserName, lpszFile);
    if ( dwMessageId )
    {
      v20 = _wcsdup(L"Error loading profile for ");
      v31.unused = (int)v20;
      v21 = CCmdString::operator+((CCmdString *)&ppstr, (CCmdString *)&v31, lpszKeyName);
      v22 = (WCHAR *)v3;
      v3 = (CCmdString *)_wcsdup(v21->m_String);
      free(v22);
      free(ppstr);
      free(v20);
      v23 = __acrt_iob_func();
      fputws((const wchar_t *)v3, v23 + 2);
      PE_OutputErrorMsg(dwMessageId);
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
// C9D238: using guessed type wchar_t aNtAuthoritySys[20];

//----- (00BEF8D0) --------------------------------------------------------
CCmdString *__cdecl sub_BEF8D0(CCmdString *a1, wchar_t *a2)
{
  const wchar_t *v2; // ecx
  WCHAR *pstr; // eax
  WCHAR *v4; // ecx
  WCHAR *v5; // edx
  WCHAR i; // ax

  v2 = (const wchar_t *)&gszNullString;
  if ( a2 )
    v2 = a2;
  pstr = _wcsdup(v2);
  v4 = pstr;
  v5 = pstr;
  a1->m_String = pstr;
  for ( i = *pstr; i; ++v4 )
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

//----- (00BEF930) --------------------------------------------------------
char __thiscall sub_BEF930(StringItem *this, unsigned int a2)
{
  StringItem *v2; // esi
  char *v4; // eax

  v2 = this;
  this->strText = 0;
  this->arrTexts.baseclass_0._Mypair._Myval2._Myfirst = 0;
  this->arrTexts.baseclass_0._Mypair._Myval2._Mylast = 0;
  if ( !a2 )
    return 0;
  if ( a2 > 0x3FFFFFFF )
    std::_Xlength_error("vector<T> too long");
  v4 = (char *)operator new(4 * a2);
  if ( !v4 )
    std::_Xbad_alloc();
  v2->strText = (int)v4;
  v2->arrTexts.baseclass_0._Mypair._Myval2._Myfirst = v4;
  v2->arrTexts.baseclass_0._Mypair._Myval2._Mylast = &v4[4 * a2];
  return 1;
}

//----- (00BEF9A0) --------------------------------------------------------
_DWORD *std::_Tree_comp_alloc<std::_Tmap_traits<wchar_t const *,tagKeyName,std::less<wchar_t const *>,std::allocator<std::pair<wchar_t const * const,tagKeyName>>,0>>::_Buyheadnode()
{
  _DWORD *result; // eax

  result = operator new(0x20u);
  JUMPOUT(result, 0, std::_Xbad_alloc);
  *result = result;
  if ( result != (_DWORD *)-4 )
    result[1] = result;
  if ( result != (_DWORD *)-8 )
    result[2] = result;
  *((_WORD *)result + 6) = 257;
  return result;
}

//----- (00BEF9D0) --------------------------------------------------------
int __thiscall sub_BEF9D0(string *this, unsigned int a2, int a3)
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
    if ( v7 > 0x7FFFFFFF || (v8 = (CHAR *)operator new(2 * v7), (v14 = v8) == 0) )
      std::_Xbad_alloc();
  }
  if ( a3 )
  {
    v9 = v3->_Myval2._Myres < 8 ? v3 : v3->_Myval2._Bx._Ptr;
    if ( a3 )
      memmove_0(v8, v9, 2 * a3);
  }
  if ( v3->_Myval2._Myres >= 8 )
    operator delete(v3->_Myval2._Bx._Ptr);
  v10 = (int)v14;
  v3->_Myval2._Bx._Ptr = v14;
  v3->_Myval2._Myres = v4;
  v3->_Myval2._Mysize = a3;
  if ( v4 >= 8 )
    v3 = (string *)v10;
  result = 0;
  v3->_Myval2._Bx._Buf[a3] = 0;
  return result;
}
// C781AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);

//----- (00BEFB40) --------------------------------------------------------
void __stdcall std::_Tree<std::_Tmap_traits<wchar_t const *,tagKeyName,std::less<wchar_t const *>,std::allocator<std::pair<wchar_t const * const,tagKeyName>>,0>>::clear(std__Tree_node *a1)
{
  std__Tree_node_For__bstr_t *v1; // edi
  std__Tree_node_For__bstr_t *v2; // ebx
  Data_t_bstr_t *v3; // esi
  Data_t_bstr_t *v4; // esi

  v1 = (std__Tree_node_For__bstr_t *)a1;
  v2 = (std__Tree_node_For__bstr_t *)a1;
  if ( !a1->_IsNil )
  {
    do
    {
      std::_Tree<std::_Tmap_traits<wchar_t const *,tagKeyName,std::less<wchar_t const *>,std::allocator<std::pair<wchar_t const * const,tagKeyName>>,0>>::clear(v2->_Right);
      v3 = v1->_bstrText2.m_Data;
      v2 = (std__Tree_node_For__bstr_t *)v2->_Left;
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
            operator delete[](v4->m_str);
            v4->m_str = 0;
          }
          operator delete(v4);
        }
        v1->_bstrText1.m_Data = 0;
      }
      operator delete(v1);
      v1 = v2;
    }
    while ( !v2->_IsNil );
  }
}

//----- (00BEFC40) --------------------------------------------------------
BOOL __thiscall sub_BEFC40(string *this, int a2, int a3)
{
  string *v3; // esi
  size_t v4; // eax
  BOOL result; // eax
  unsigned int v6; // ebx
  CHAR *v7; // ecx
  int v8; // [esp+14h] [ebp+Ch]

  v3 = this;
  if ( (unsigned int)a2 > 0x7FFFFFFE )
    std::_Xlength_error("string too long");
  v4 = this->_Myval2._Myres;
  if ( v4 >= a2 )
  {
    if ( (_BYTE)a3 && (unsigned int)a2 < 8 )
    {
      v6 = this->_Myval2._Mysize;
      if ( a2 < v6 )
        v6 = a2;
      if ( v4 >= 8 )
      {
        v7 = this->_Myval2._Bx._Ptr;
        v8 = (int)v3->_Myval2._Bx._Ptr;
        if ( v6 )
        {
          memmove_0(v3, v7, 2 * v6);
          v7 = (CHAR *)v8;
        }
        operator delete(v7);
      }
      v3->_Myval2._Mysize = v6;
      v3->_Myval2._Myres = 7;
      v3->_Myval2._Bx._Buf[v6] = 0;
      result = (unsigned int)a2 > 0;
    }
    else
    {
      if ( !a2 )
      {
        this->_Myval2._Mysize = 0;
        if ( v4 >= 8 )
          v3 = (string *)this->_Myval2._Bx._Ptr;
        v3->_Myval2._Bx._Buf[0] = 0;
      }
      result = (unsigned int)a2 > 0;
    }
  }
  else
  {
    sub_BEF9D0(this, a2, this->_Myval2._Mysize);
    result = (unsigned int)a2 > 0;
  }
  return result;
}

//----- (00BEFD00) --------------------------------------------------------
int *__thiscall sub_BEFD00(int *this, unsigned int a2)
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
    if ( a2 > 0xFFFFFFF || (v4 = (char *)operator new(16 * a2), (v10 = v4) == 0) )
      std::_Xbad_alloc();
  }
  v13 = 0;
  sub_BE3440(*v2, v2[1], (int)v4);
  v5 = *v2;
  v6 = v2[1];
  v7 = v2[1] - *v2;
  if ( v5 )
  {
    sub_BE2BF0(v5, v6);
    operator delete((void *)*v11);
  }
  result = v11;
  v11[2] = (int)&v4[16 * v3];
  result[1] = (int)&v4[v7 & 0xFFFFFFF0];
  *result = (int)v4;
  return result;
}
// C781AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);

//----- (00BEFDF0) --------------------------------------------------------
const wchar_t **__thiscall sub_BEFDF0(std__vector *this, unsigned int a2)
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
    if ( a2 > 0x3FFFFFFF || (v3 = (char *)operator new(4 * a2), (v11 = v3) == 0) )
      std::_Xbad_alloc();
  }
  v13 = 0;
  sub_BE34F0(
    (std__vector *)v2->baseclass_0._Mypair._Myval2._Myfirst,
    (const wchar_t **)v2->baseclass_0._Mypair._Myval2._Mylast,
    (wchar_t **)v3);
  v4 = (std__vector *)v2->baseclass_0._Mypair._Myval2._Mylast;
  v5 = (std__vector *)v2->baseclass_0._Mypair._Myval2._Myfirst;
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
        v5 = (std__vector *)((char *)v5 + 4);
      }
      while ( v5 != v11 );
    }
    operator delete(v2->baseclass_0._Mypair._Myval2._Myfirst);
    v7 = v10;
  }
  v2->baseclass_0._Mypair._Myval2._Myfirst = v3;
  v2->baseclass_0._Mypair._Myval2._Myend = &v3[4 * a2];
  result = (const wchar_t **)&v3[4 * v7];
  v2->baseclass_0._Mypair._Myval2._Mylast = result;
  return result;
}
// C781AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);

//----- (00BEFEE0) --------------------------------------------------------
int *__thiscall sub_BEFEE0(int *this, unsigned int a2)
{
  int v2; // esi
  int *result; // eax
  int v4; // esi
  unsigned int v5; // esi
  unsigned int v6; // edx
  unsigned int v7; // edx
  unsigned int v8; // edx

  v2 = this[1];
  result = (int *)((this[2] - v2) >> 4);
  if ( (unsigned int)result < a2 )
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
      result = sub_BEFD00(this, v8);
    }
    else
    {
      v7 = 0;
      if ( v5 > 0 )
        v7 = v5;
      result = sub_BEFD00(this, v7);
    }
  }
  return result;
}

//----- (00BEFF60) --------------------------------------------------------
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
      result = (unsigned int)sub_BEFDF0(this, v8);
    }
    else
    {
      v7 = 0;
      if ( v5 > 0 )
        v7 = v5;
      result = (unsigned int)sub_BEFDF0(this, v7);
    }
  }
  return result;
}

//----- (00BEFFE0) --------------------------------------------------------
void *__stdcall sub_BEFFE0(unsigned int a1)
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

//----- (00BF0010) --------------------------------------------------------
void *__thiscall sub_BF0010(std__vector *this)
{
  std__vector *v1; // edi
  void *v2; // ebx
  void **v3; // esi
  void *result; // eax

  v1 = this;
  v2 = this->baseclass_0._Mypair._Myval2._Mylast;
  v3 = (void **)this->baseclass_0._Mypair._Myval2._Myfirst;
  if ( this->baseclass_0._Mypair._Myval2._Myfirst == v2 )
  {
    result = this->baseclass_0._Mypair._Myval2._Myfirst;
    this->baseclass_0._Mypair._Myval2._Mylast = v3;
  }
  else
  {
    do
    {
      free(*v3);
      ++v3;
    }
    while ( v3 != v2 );
    result = v1->baseclass_0._Mypair._Myval2._Myfirst;
    v1->baseclass_0._Mypair._Myval2._Mylast = v1->baseclass_0._Mypair._Myval2._Myfirst;
  }
  return result;
}

//----- (00BF0050) --------------------------------------------------------
int __thiscall std::_Tree<std::_Tmap_traits<wchar_t const *,tagKeyName,std::less<wchar_t const *>,std::allocator<std::pair<wchar_t const * const,tagKeyName>>,0>>::erase(std__tree *this, std__Tree_node **a2, std__Tree_node *a3, std__Tree_node *Node)
{
  std__Tree_node *v4; // eax
  std__tree *v5; // esi
  std__Tree_node *_Myhead; // ecx
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
  if ( a3 != (std__Tree_node *)_Myhead->_Left || Node != _Myhead )
  {
    for ( ; a3 != Node; v4 = a3 )
    {
      v10 = v4;
      if ( !v4->_IsNil )
      {
        i = (std__Tree_node *)v4->_Right;
        if ( i->_IsNil )
        {
          for ( i = (std__Tree_node *)v4->_Parent; !i->_IsNil; i = (std__Tree_node *)i->_Parent )
          {
            if ( v4 != (std__Tree_node *)i->_Right )
              break;
            v4 = i;
          }
        }
        else
        {
          v12 = (std__Tree_node *)i->_Left;
          if ( !i->_Left->_IsNil )
          {
            do
            {
              i = v12;
              v12 = (std__Tree_node *)v12->_Left;
            }
            while ( !v12->_IsNil );
          }
        }
        a3 = i;
      }
      std::_Tree<std::_Tmap_traits<wchar_t const *,tagKeyName,std::less<wchar_t const *>,std::allocator<std::pair<wchar_t const * const,tagKeyName>>,0>>::erase(
        v5,
        (int)&v13,
        v10);
    }
    *a2 = v4;
    result = (int)a2;
  }
  else
  {
    std::_Tree<std::_Tmap_traits<wchar_t const *,tagKeyName,std::less<wchar_t const *>,std::allocator<std::pair<wchar_t const * const,tagKeyName>>,0>>::clear((std__Tree_node *)_Myhead->_Parent);
    v5->_Mypair._Myval2._Myhead->_Parent = (std_Tree_node_for_tagKeyName *)v5->_Mypair._Myval2._Myhead;
    v5->_Mypair._Myval2._Myhead->_Left = (std_Tree_node_for_tagKeyName *)v5->_Mypair._Myval2._Myhead;
    v5->_Mypair._Myval2._Myhead->_Right = (std__Tree_node_For__bstr_t *)v5->_Mypair._Myval2._Myhead;
    v7 = (std__Tree_node **)v5->_Mypair._Myval2._Myhead;
    v5->_Mypair._Myval2._Mysize = 0;
    v8 = *v7;
    result = (int)a2;
    *a2 = v8;
  }
  return result;
}

//----- (00BF0110) --------------------------------------------------------
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

  v3 = (std__Tree_node_For__bstr_t *)a3;
  This = this;
  sub_C04CE0((std__tree *)&a3);
  if ( v3->_Left->_IsNil )
  {
    v4 = (std_Tree_node_for_tagKeyName *)v3->_Right;
LABEL_6:
    v6 = v3->_Parent;
    if ( !v4->_IsNil )
      v4->_Parent = (std_Tree_node_for_tagKeyName *)v6;
    pThis = This;
    if ( (std__Tree_node_For__bstr_t *)This->_Mypair._Myval2._Myhead->_Parent == v3 )
    {
      This->_Mypair._Myval2._Myhead->_Parent = v4;
    }
    else if ( (std__Tree_node_For__bstr_t *)v6->_Left == v3 )
    {
      v6->_Left = v4;
    }
    else
    {
      v6->_Right = (std__Tree_node_For__bstr_t *)v4;
    }
    v8 = This->_Mypair._Myval2._Myhead;
    if ( This->_Mypair._Myval2._Myhead->_Left == (std_Tree_node_for_tagKeyName *)v3 )
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
        v8 = This->_Mypair._Myval2._Myhead;
      }
      v8->_Left = (std_Tree_node_for_tagKeyName *)v9;
    }
    if ( This->_Mypair._Myval2._Myhead->_Right == v3 )
    {
      if ( v4->_IsNil )
      {
        This->_Mypair._Myval2._Myhead->_Right = (std__Tree_node_For__bstr_t *)v6;
      }
      else
      {
        v11 = (std__Tree_node *)v4->_Right;
        for ( i = (std__Tree_node *)v4; !v11->_IsNil; v11 = (std__Tree_node *)v11->_Right )
          i = v11;
        This->_Mypair._Myval2._Myhead->_Right = (std__Tree_node_For__bstr_t *)i;
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
  v4 = (std_Tree_node_for_tagKeyName *)a3->_Right;
  if ( a3 == (std__Tree_node *)v3 )
    goto LABEL_6;
  v3->_Left->_Parent = (std_Tree_node_for_tagKeyName *)a3;
  v5->_Left = v3->_Left;
  if ( v5 == v3->_Right )
  {
    v6 = v5;
  }
  else
  {
    v6 = (std__Tree_node *)v5->_Parent;
    if ( !v4->_IsNil )
      v4->_Parent = (std_Tree_node_for_tagKeyName *)v6;
    v6->_Left = v4;
    v5->_Right = (std__Tree_node_For__bstr_t *)v3->_Right;
    v3->_Right->_Parent = (std_Tree_node_for_tagKeyName *)v5;
  }
  if ( (std__Tree_node_For__bstr_t *)This->_Mypair._Myval2._Myhead->_Parent == v3 )
  {
    This->_Mypair._Myval2._Myhead->_Parent = (std_Tree_node_for_tagKeyName *)v5;
  }
  else
  {
    v13 = v3->_Parent;
    if ( (std__Tree_node_For__bstr_t *)v13->_Left == v3 )
      v13->_Left = (std_Tree_node_for_tagKeyName *)v5;
    else
      v13->_Right = (std__Tree_node_For__bstr_t *)v5;
  }
  v5->_Parent = (std_Tree_node_for_tagKeyName *)v3->_Parent;
  v14 = v5->_Color;
  v25->_Color = v3->_Color;
  pThis = This;
  v3->_Color = v14;
LABEL_37:
  if ( v3->_Color == 1 )
  {
    for ( ; v4 != pThis->_Mypair._Myval2._Myhead->_Parent; v6 = (std__Tree_node *)v6->_Parent )
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
          sub_C654B0(pThis, v6);
          v15 = (std__Tree_node *)v6->_Right;
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
            sub_C72BB0(pThis, v15);
            v15 = (std__Tree_node *)v6->_Right;
          }
          v15->_Color = v6->_Color;
          v6->_Color = 1;
          v16 = v6;
          v17 = (std__Tree_node *)This;
          v15->_Right->_Color = 1;
          sub_C654B0(This, v16);
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
          sub_C72BB0(pThis, v6);
          v15 = (std__Tree_node *)v6->_Left;
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
            sub_C654B0(pThis, v15);
            v15 = (std__Tree_node *)v6->_Left;
          }
          v15->_Color = v6->_Color;
          v6->_Color = 1;
          v18 = v6;
          v17 = (std__Tree_node *)This;
          v15->_Left->_Color = 1;
          sub_C72BB0(This, v18);
          v4->_Color = 1;
          goto LABEL_61;
        }
      }
      v15->_Color = 0;
LABEL_55:
      v4 = (std_Tree_node_for_tagKeyName *)v6;
    }
    v17 = (std__Tree_node *)This;
    v4->_Color = 1;
  }
  else
  {
    v17 = (std__Tree_node *)This;
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
        operator delete[](v19->m_str);
        v19->m_str = 0;
      }
      operator delete(v19);
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
        operator delete[](v21->m_str);
        v21->m_str = 0;
      }
      operator delete(v21);
    }
    v3->_bstrText1.m_Data = 0;
  }
  operator delete(v3);
  v22 = v17->_Parent;
  v23 = a3;
  if ( v22 )
    v17->_Parent = (std_Tree_node_for_tagKeyName *)((char *)v22 - 1);
  result = a2;
  *(_DWORD *)a2 = v23;
  return result;
}

//----- (00BF0440) --------------------------------------------------------
UINT __thiscall _bstr_t::length(tagEventItem *this)
{
  UINT result; // eax

  if ( this->strEventTrace.m_Data && this->strEventTrace.m_Data->m_wstr )
    result = SysStringLen(this->strEventTrace.m_Data->m_wstr);
  else
    result = 0;
  return result;
}

//----- (00BF0460) --------------------------------------------------------
const wchar_t **__thiscall sub_BF0460(int *this, StringItem *a2)
{
  int *v2; // esi
  const wchar_t **result; // eax
  StringItem *v4; // edi
  int v5; // ecx
  unsigned int v6; // edi
  int v7; // ebx

  v2 = this;
  result = (const wchar_t **)this[1];
  v4 = a2;
  if ( a2 >= (StringItem *)result || (v5 = *this, *v2 > (unsigned int)a2) )
  {
    if ( result == (const wchar_t **)v2[2] )
      result = (const wchar_t **)sub_BEFEE0(v2, 1u);
    v7 = v2[1];
    if ( v7 )
    {
      *(_DWORD *)v7 = _wcsdup((const wchar_t *)a2->strText);
      goto LABEL_11;
    }
  }
  else
  {
    v6 = (unsigned int)a2 - v5;
    if ( result == (const wchar_t **)v2[2] )
      result = (const wchar_t **)sub_BEFEE0(v2, 1u);
    v7 = v2[1];
    v4 = (StringItem *)(*v2 + (v6 & 0xFFFFFFF0));
    if ( v7 )
    {
      *(_DWORD *)v7 = _wcsdup((const wchar_t *)v4->strText);
LABEL_11:
      result = (const wchar_t **)sub_BE35A0((StringItem *)(v7 + 4), (const wchar_t ***)&v4->arrTexts);
      goto LABEL_12;
    }
  }
LABEL_12:
  v2[1] += 16;
  return result;
}

//----- (00BF0530) --------------------------------------------------------
const wchar_t **__thiscall sub_BF0530(std__vector *this, const wchar_t **a2)
{
  std__vector *v2; // esi
  const wchar_t **result; // eax
  _BYTE *v4; // ecx
  int v5; // edi
  _DWORD *v6; // ebx

  v2 = this;
  result = (const wchar_t **)this->baseclass_0._Mypair._Myval2._Mylast;
  if ( a2 >= result || (v4 = this->baseclass_0._Mypair._Myval2._Myfirst, v2->baseclass_0._Mypair._Myval2._Myfirst > a2) )
  {
    if ( result == v2->baseclass_0._Mypair._Myval2._Myend )
      result = (const wchar_t **)std::vector<wchar_t const *,std::allocator<wchar_t const *>>::_Reserve(v2, 1u);
    v6 = v2->baseclass_0._Mypair._Myval2._Mylast;
    if ( v6 )
    {
      result = (const wchar_t **)_wcsdup(*a2);
      goto LABEL_11;
    }
  }
  else
  {
    v5 = ((char *)a2 - v4) >> 2;
    if ( result == v2->baseclass_0._Mypair._Myval2._Myend )
      result = (const wchar_t **)std::vector<wchar_t const *,std::allocator<wchar_t const *>>::_Reserve(v2, 1u);
    v6 = v2->baseclass_0._Mypair._Myval2._Mylast;
    if ( v6 )
    {
      result = (const wchar_t **)_wcsdup(*((const wchar_t **)v2->baseclass_0._Mypair._Myval2._Myfirst + v5));
LABEL_11:
      *v6 = result;
      goto LABEL_12;
    }
  }
LABEL_12:
  v2->baseclass_0._Mypair._Myval2._Mylast = (char *)v2->baseclass_0._Mypair._Myval2._Mylast + 4;
  return result;
}

//----- (00BF05A0) --------------------------------------------------------
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

  _bstr_t::_bstr_t((tagEventSetItem *)&bstrAutorunsDisabled, L"AutorunsDisabled");
  v19 = 0;
  v4 = (_bstr_t *)_bstr_t::_bstr_t((tagEventSetItem *)&bstrSlash, L"\\");
  LOBYTE(v19) = 1;
  bstrKeyName = _bstr_t::operator+(&bstrKeyNameTemp, (OLECHAR *)lpszKeyName, v4);
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
        operator delete[](v6->m_str);
        v6->m_str = 0;
      }
      operator delete(v6);
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
        operator delete[](v7->m_str);
        v7->m_str = 0;
      }
      operator delete(v7);
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
      operator delete[](v8->m_str);
      v8->m_str = 0;
    }
    operator delete(v8);
  }
  Handle = sub_BF0790(a1, hKey, lpszKeyName, lpValueName, (HANDLE)0xFFFFFFFF);
  if ( bstrKeyName_1.m_Data )
    v10 = bstrKeyName_1.m_Data->m_wstr;
  else
    v10 = 0;
  v11 = sub_BF0790(a1, hKey, v10, lpValueName, Handle);
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
      operator delete[](v12->m_str);
      v12->m_str = 0;
    }
    operator delete(v12);
  }
  return v13;
}

//----- (00BF0790) --------------------------------------------------------
void *__cdecl sub_BF0790(int a1, HKEY hKey, LPCWSTR lpszKeyName, LPCWSTR lpszValueName, HANDLE Handle)
{
  HANDLE v5; // edi
  const WCHAR *v6; // esi
  int v7; // ebx
  const wchar_t *v8; // eax
  const wchar_t *v9; // eax
  const wchar_t *v10; // eax
  const wchar_t *v11; // eax
  CCmdString *str1; // esi
  CCmdString *str2; // eax
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
  CCmdString *v28; // esi
  CCmdString *v29; // eax
  char v30; // bl
  LPCWSTR v31; // ebx
  const wchar_t *v32; // eax
  const wchar_t *v33; // eax
  const wchar_t *v34; // eax
  const wchar_t *v35; // eax
  CCmdString *v36; // esi
  CCmdString *v37; // eax
  CCmdString *v38; // ST34_4
  int v39; // esi
  const WCHAR **v40; // eax
  const wchar_t *v41; // eax
  CCmdString *v42; // eax
  WCHAR v43[2]; // [esp+10h] [ebp-A4h]
  WCHAR v44[2]; // [esp+14h] [ebp-A0h]
  WCHAR v45[2]; // [esp+18h] [ebp-9Ch]
  WCHAR v46[2]; // [esp+1Ch] [ebp-98h]
  WCHAR v47[2]; // [esp+20h] [ebp-94h]
  int a8; // [esp+24h] [ebp-90h]
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
  CCmdString strValue; // [esp+60h] [ebp-54h]
  LPCWSTR v64; // [esp+64h] [ebp-50h]
  LPCWSTR v65; // [esp+68h] [ebp-4Ch]
  void *v66; // [esp+6Ch] [ebp-48h]
  CCmdString a1a; // [esp+70h] [ebp-44h]
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
  CCmdString strKeyName; // [esp+9Ch] [ebp-18h]
  CCmdString strValueName; // [esp+A0h] [ebp-14h]
  CCmdString str3; // [esp+A4h] [ebp-10h]
  int v81; // [esp+B0h] [ebp-4h]

  v5 = Handle;
  v6 = lpszValueName;
  v7 = a1;
  if ( Handle == (HANDLE)-1 )
  {
    v71 = _wcsdup((const wchar_t *)&gszNullString);
    v81 = 0;
    v73 = _wcsdup((const wchar_t *)&gszNullString);
    szKeyName = _wcsdup((const wchar_t *)&gszNullString);
    v74 = _wcsdup((const wchar_t *)&gszNullString);
    v72 = _wcsdup((const wchar_t *)&gszNullString);
    str3.m_String = _wcsdup((const wchar_t *)&gszNullString);
    v8 = (const wchar_t *)&gszNullString;
    if ( lpszValueName )
      v8 = lpszValueName;
    strValueName.m_String = _wcsdup(v8);
    v9 = (const wchar_t *)&gszNullString;
    if ( lpszKeyName )
      v9 = lpszKeyName;
    strKeyName.m_String = _wcsdup(v9);
    v10 = (const wchar_t *)&gszNullString;
    if ( lpszValueName )
      v10 = lpszValueName;
    pszValueName2 = _wcsdup(v10);
    v11 = (const wchar_t *)&gszNullString;
    if ( lpszKeyName )
      v11 = lpszKeyName;
    pszKeyName2 = _wcsdup(v11);
    LOBYTE(v81) = 9;
    str1 = MakeRegistryKeyName(&a1a, hKey, &strKeyName, &strValueName);
    LOBYTE(v81) = 10;
    str2 = MakeRegistryKeyName((CCmdString *)szArg, hKey, (CCmdString *)&pszKeyName2, (CCmdString *)&pszValueName2);
    LOBYTE(v81) = 11;
    v5 = (HANDLE)PE_UpdateSystemKey(a1, 0, (HANDLE)0xFFFFFFFF, 0, str2, str1, &str3);
    Handle = v5;
    free(*(void **)szArg);
    free(a1a.m_String);
    free((void *)pszKeyName2);
    free((void *)pszValueName2);
    free(strKeyName.m_String);
    free(strValueName.m_String);
    free(str3.m_String);
    free(v72);
    free((void *)v74);
    free((void *)szKeyName);
    free((void *)v73);
    v81 = -1;
    free((void *)v71);
    v6 = lpszValueName;
  }
  hSubKey = 0;
  PE_OpenKey(hKey, lpszKeyName, 0, KEY_READ, &hSubKey);
  if ( !hSubKey )
    return v5;
  cbData = 0;
  if ( !RegQueryValueExW(hSubKey, v6, 0, 0, 0, &cbData) )
  {
    v15 = (WCHAR *)malloc(2u);
    strKeyName.m_String = v15;
    *v15 = 0;
    v81 = 12;
    pszValueNames = (wchar_t *)operator new[](2 * ((cbData >> 1) + 2));
    RegQueryValueExW(hSubKey, v6, 0, 0, (LPBYTE)pszValueNames, &cbData);
    v17 = cbData >> 1;
    cbData = v17;
    if ( v17 > 2 )
    {
      pszValueNames[v17 - 1] = 0;
      for ( pszValueNames[cbData] = 0; *pszValueNames; pszValueNames = wcschr(pszValueNames + 1, 0) + 1 )
      {
        v18 = malloc(2u);
        a2 = (int)v18;
        *v18 = 0;
        v51 = 0;
        v52 = 0;
        v53 = 0;
        LOBYTE(v81) = 13;
        sub_BE6CC0(pszValueNames, (StringItem *)&a2);
        v19 = strKeyName.m_String;
        strKeyName.m_String = _wcsdup(pszValueNames);
        free(v19);
        sub_BE4EE0((int)&str3, v7, (int)&a2, 0);
        v20 = str3.m_String;
        if ( str3.m_String )
        {
          if ( !_wcsnicmp(str3.m_String, L"File not found: ", 0x10u) && !_wcsnicmp(pszValueNames, L"autocheck ", 0xAu) )
          {
            v21 = _wcsdup(pszValueNames);
            dwValue = (DWORD)v21;
            LOBYTE(v81) = 15;
            sub_BE6CC0(pszValueNames + 10, (StringItem *)&a2);
            v22 = (const wchar_t **)sub_BE4EE0((int)&v49, v7, (int)&a2, 0);
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
          strValueName.m_String = (WCHAR *)malloc(2u);
          *strValueName.m_String = 0;
          pszKeyName2 = (LPCWSTR)malloc(2u);
          *pszKeyName2 = 0;
          pszValueName2 = (LPCWSTR)malloc(2u);
          *pszValueName2 = 0;
          LOBYTE(v81) = 18;
          dwValue = sub_BE4ED0();
          v72 = _wcsdup(pszValueNames);
          v24 = (const wchar_t *)&gszNullString;
          if ( lpszValueName )
            v24 = lpszValueName;
          v74 = _wcsdup(v24);
          v25 = (const wchar_t *)&gszNullString;
          if ( lpszKeyName )
            v25 = lpszKeyName;
          szKeyName = _wcsdup(v25);
          v26 = (const wchar_t *)&gszNullString;
          if ( lpszValueName )
            v26 = lpszValueName;
          v73 = _wcsdup(v26);
          v27 = (const wchar_t *)&gszNullString;
          if ( lpszKeyName )
            v27 = lpszKeyName;
          v71 = _wcsdup(v27);
          LOBYTE(v81) = 23;
          v28 = MakeRegistryKeyName((CCmdString *)v43, hKey, (CCmdString *)&szKeyName, (CCmdString *)&v74);
          LOBYTE(v81) = 24;
          v29 = MakeRegistryKeyName((CCmdString *)v47, hKey, (CCmdString *)&v71, (CCmdString *)&v73);
          LOBYTE(v81) = 25;
          v30 = sub_BE3D40(
                  v7,
                  (CCmdString)v29,
                  (int)v28,
                  (int)&v72,
                  (int)&str3,
                  (int)&strValueName,
                  (CCmdString)&pszValueName2,
                  (int)&a8);
          free(*(void **)v47);
          free(*(void **)v43);
          free((void *)v71);
          free((void *)v73);
          free((void *)szKeyName);
          free((void *)v74);
          free(v72);
          if ( v30 )
          {
            if ( Handle == (HANDLE)-1 )
            {
              v58 = _wcsdup((const wchar_t *)&gszNullString);
              v56 = _wcsdup((const wchar_t *)&gszNullString);
              v60 = _wcsdup((const wchar_t *)&gszNullString);
              v55 = _wcsdup((const wchar_t *)&gszNullString);
              v66 = _wcsdup((const wchar_t *)&gszNullString);
              strValue.m_String = _wcsdup((const wchar_t *)&gszNullString);
              v31 = lpszValueName;
              v32 = (const wchar_t *)&gszNullString;
              if ( lpszValueName )
                v32 = lpszValueName;
              v59 = _wcsdup(v32);
              v33 = (const wchar_t *)&gszNullString;
              if ( lpszKeyName )
                v33 = lpszKeyName;
              v64 = _wcsdup(v33);
              v34 = (const wchar_t *)&gszNullString;
              if ( lpszValueName )
                v34 = lpszValueName;
              v65 = _wcsdup(v34);
              v35 = (const wchar_t *)&gszNullString;
              if ( lpszKeyName )
                v35 = lpszKeyName;
              v57 = _wcsdup(v35);
              LOBYTE(v81) = 35;
              v36 = MakeRegistryKeyName((CCmdString *)v46, hKey, (CCmdString *)&v64, (CCmdString *)&v59);
              LOBYTE(v81) = 36;
              v37 = MakeRegistryKeyName((CCmdString *)v44, hKey, (CCmdString *)&v57, (CCmdString *)&v65);
              LOBYTE(v81) = 37;
              v38 = v36;
              v39 = a1;
              Handle = (HANDLE)PE_UpdateSystemKey(a1, 0, (HANDLE)0xFFFFFFFF, 0, v37, v38, &strValue);
              free(*(void **)v44);
              free(*(void **)v46);
              free((void *)v57);
              free((void *)v65);
              free((void *)v64);
              free((void *)v59);
              free(strValue.m_String);
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
            *(_DWORD *)szArg = _wcsdup((const wchar_t *)&gszNullString);
            v40 = &gszNullString;
            if ( v31 )
              v40 = (const WCHAR **)v31;
            a1a.m_String = _wcsdup((const wchar_t *)v40);
            v41 = (const wchar_t *)&gszNullString;
            if ( lpszKeyName )
              v41 = lpszKeyName;
            v61 = _wcsdup(v41);
            ppv3 = _wcsdup(pszValueNames);
            LOBYTE(v81) = 41;
            v42 = MakeRegistryKeyName((CCmdString *)v45, hKey, (CCmdString *)&v61, &a1a);
            LOBYTE(v81) = 42;
            PE_UpdateSystemKey(v39, dwValue, Handle, 5u, (CCmdString *)&ppv3, v42, &str3);
            free(*(void **)v45);
            free(ppv3);
            free((void *)v61);
            free(a1a.m_String);
            free(*(void **)szArg);
          }
          free((void *)pszValueName2);
          free((void *)pszKeyName2);
          free(strValueName.m_String);
          v20 = str3.m_String;
        }
        free(v20);
        LOBYTE(v81) = 12;
        StringItem::~StringItem((tagPEStringStruct *)&a2);
        v7 = a1;
      }
    }
    free(strKeyName.m_String);
  }
  RegCloseKey(hSubKey);
  return Handle;
}

//----- (00BF0F50) --------------------------------------------------------
CCmdString *__cdecl RequerySystemEnvironmentString(CCmdString *strCmd, CCmdString *lpszName)
{
  DWORD nLength; // eax
  DWORD v3; // edi
  WCHAR *pBuffer; // eax
  size_t v5; // edi
  WCHAR *v6; // eax
  DWORD nSize; // [esp+Ch] [ebp-4h]

  nLength = ExpandEnvironmentStringsW((LPCWSTR)lpszName, 0, 0);
  v3 = nLength;
  nSize = nLength;
  pBuffer = (WCHAR *)malloc(2u);
  v5 = 2 * v3 + 2;
  strCmd->m_String = pBuffer;
  *pBuffer = 0;
  v6 = (WCHAR *)realloc(strCmd->m_String, v5);
  strCmd->m_String = v6;
  if ( v6 )
    memset(v6, 0, v5);
  ExpandEnvironmentStringsW((LPCWSTR)lpszName, strCmd->m_String, nSize);
  return strCmd;
}

//----- (00BF0FC0) --------------------------------------------------------
HANDLE __cdecl sub_BF0FC0(OLECHAR *psz, LPWIN32_FIND_DATAW lpFindFileData)
{
  Data_t_bstr_t *v2; // esi
  const WCHAR *v3; // eax
  HANDLE v4; // edi
  _bstr_t bstrText; // [esp+8h] [ebp-4h]

  sub_BE7AB0(&gKeyNameMap, (tagKeyName *)&bstrText, psz);
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
      operator delete[](v2->m_str);
      v2->m_str = 0;
    }
    operator delete(v2);
  }
  return v4;
}

//----- (00BF1040) --------------------------------------------------------
DWORD __cdecl PE_GetFileAttributes(OLECHAR *lpszKeyName)
{
  Data_t_bstr_t *v1; // esi
  const WCHAR *v2; // eax
  DWORD v3; // edi
  _bstr_t bstrText; // [esp+8h] [ebp-4h]

  sub_BE7AB0(&gKeyNameMap, (tagKeyName *)&bstrText, lpszKeyName);
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
      operator delete[](v1->m_str);
      v1->m_str = 0;
    }
    operator delete(v1);
  }
  return v3;
}

//----- (00BF10C0) --------------------------------------------------------
DWORD_PTR __cdecl GetSHFileInfo(OLECHAR *lpszKeyName, DWORD dwFileAttributes, SHFILEINFOW *pFileInfo, UINT cbFileInfo, UINT uFlags)
{
  Data_t_bstr_t *v5; // esi
  const WCHAR *pszPathName; // eax
  DWORD_PTR v7; // edi
  _bstr_t bstrText; // [esp+8h] [ebp-4h]

  sub_BE7AB0(&gKeyNameMap, (tagKeyName *)&bstrText, lpszKeyName);
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
      operator delete[](v5->m_str);
      v5->m_str = 0;
    }
    operator delete(v5);
  }
  return v7;
}

//----- (00BF1150) --------------------------------------------------------
bool __cdecl PE_GetPathName(int a1, LPCWSTR lpszSystemPath, LPCWSTR lpszPathName, CCmdString *strRet)
{
  int v4; // eax
  Data_t_bstr_t *v5; // esi
  const WCHAR *v6; // eax
  WCHAR *v7; // ebx
  char v8; // bl
  const wchar_t *v9; // ecx
  CCmdString strSystemPath; // edi
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
  if ( (_WORD)v4 && lpszPathName[1] == ':' || v4 == '\\' )
  {
    sub_BE7AB0(&gKeyNameMap, &KeyName, lpszPathName);
    v5 = KeyName.bstrText1.m_Data;
    if ( KeyName.bstrText1.m_Data )
      v6 = KeyName.bstrText1.m_Data->m_wstr;
    else
      v6 = 0;
    KeyName.bstrText1.m_Data = (Data_t_bstr_t *)GetFileAttributesW(v6);
    v7 = strRet->m_String;
    strRet->m_String = _wcsdup(lpszPathName);
    free(v7);
    v8 = KeyName.bstrText1.m_Data != (Data_t_bstr_t *)INVALID_FILE_ATTRIBUTES
      && !((_DWORD)KeyName.bstrText1.m_Data & FILE_ATTRIBUTE_DIRECTORY);
    if ( v5 && !InterlockedDecrement(&v5->m_RefCount) )
    {
      if ( v5->m_wstr )
      {
        SysFreeString(v5->m_wstr);
        v5->m_wstr = 0;
      }
      if ( v5->m_str )
      {
        operator delete[](v5->m_str);
        v5->m_str = 0;
      }
      operator delete(v5);
    }
  }
  else
  {
    v9 = (const wchar_t *)&gszNullString;
    if ( lpszSystemPath )
      v9 = lpszSystemPath;
    strSystemPath.m_String = _wcsdup(v9);
    v11 = *strSystemPath.m_String == 0;
    pszSystemPath = strSystemPath.m_String;
    v26 = 0;
    KeyName.dwValue = (int)strSystemPath.m_String;
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
        KeyName.bstrText2.m_Data = (Data_t_bstr_t *)malloc(2 * v17);
        swprintf_s((wchar_t *)KeyName.bstrText2.m_Data, v17, L"%s\\%s", KeyName.dwValue, lpszPathName);
        if ( pstr )
        {
          v18 = (const WCHAR **)(pstr + 1);
          *pstr = ';';
        }
        else
        {
          v18 = &gszNullString;
        }
        v19 = KeyName.bstrText2.m_Data;
        KeyName.dwValue = (int)v18;
        sub_BE7AB0(&gKeyNameMap, &KeyName, (LPCWSTR)KeyName.bstrText2.m_Data);
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
              operator delete[](v20->m_str);
              v20->m_str = 0;
            }
            operator delete(v20);
          }
          KeyName.bstrText1.m_Data = 0;
        }
        pszSystemPath = (const wchar_t *)KeyName.dwValue;
        if ( !*(_WORD *)KeyName.dwValue )
          goto LABEL_42;
      }
      v24 = strRet->m_String;
      strRet->m_String = _wcsdup((const wchar_t *)KeyName.bstrText2.m_Data);
      free(v24);
      free(KeyName.bstrText2.m_Data);
      _bstr_t::_Free(&KeyName.bstrText1);
      v8 = 1;
    }
    free(strSystemPath.m_String);
  }
  return v8;
}

//----- (00BF13D0) --------------------------------------------------------
LSTATUS __cdecl PE_LoadRegKeys(HKEY hKey, DWORD dwIndex, CCmdString *ppszKey)
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
    v6 = (WCHAR *)realloc(ppszKey->m_String, v5);
    ppszKey->m_String = v6;
    if ( v6 )
      memset(v6, 0, v5);
    result = RegEnumKeyW(hKey, dwIndex, ppszKey->m_String, cbMaxSubKeyLen);
  }
  return result;
}

//----- (00BF1450) --------------------------------------------------------
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
    v8 = (WCHAR *)realloc(*ppszValueName, v7);
    *ppszValueName = v8;
    if ( v8 )
      memset(v8, 0, v7);
    v9 = 2 * (((cbMaxValueLen + 1) >> 1) + 1);
    v10 = realloc(*ppv, 2 * (((cbMaxValueLen + 1) >> 1) + 1));
    *ppv = v10;
    if ( v10 )
      memset(v10, 0, v9);
    result = RegEnumValueW(
               hKey,
               dwIndex,
               *ppszValueName,
               &cbMaxValueNameLen,
               lpReserved,
               lpType,
               (LPBYTE)*ppv,
               &cbMaxValueLen);
  }
  return result;
}

//----- (00BF1520) --------------------------------------------------------
LSTATUS __cdecl PE_ReadRegKey(HKEY hKey, LPCWSTR lpValueName, LPDWORD lpReserved, LPDWORD lpType, CCmdString *ppv)
{
  LSTATUS result; // eax
  WCHAR *v6; // eax
  DWORD nLength; // [esp+0h] [ebp-8h]
  DWORD cbData; // [esp+4h] [ebp-4h]

  cbData = 0;
  result = RegQueryValueExW(hKey, lpValueName, lpReserved, 0, 0, &cbData);
  if ( !result )
  {
    nLength = 2 * (((cbData + 1) >> 1) + 1);
    v6 = (WCHAR *)realloc(ppv->m_String, 2 * (((cbData + 1) >> 1) + 1));
    ppv->m_String = v6;
    if ( v6 )
      memset(v6, 0, nLength);
    result = RegQueryValueExW(hKey, lpValueName, lpReserved, lpType, (LPBYTE)ppv->m_String, &cbData);
  }
  return result;
}

//----- (00BF15A0) --------------------------------------------------------
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
    v5 = 2 * (((unsigned int)(cbData + 1) >> 1) + 1);
    v4 = (WCHAR *)realloc(*ppszValues, 2 * (((unsigned int)(cbData + 1) >> 1) + 1));
    *ppszValues = v4;
    if ( v4 )
      memset(v4, 0, v5);
    result = RegQueryValueW(hKey, lpSubKey, *ppszValues, &cbData);
  }
  return result;
}

//----- (00BF1610) --------------------------------------------------------
HANDLE __cdecl sub_BF1610(int arg0, void *hKey, wchar_t *psz)
{
  DWORD v3; // ebx
  _WORD *v4; // eax
  WCHAR *v5; // eax
  WCHAR *v6; // eax
  WCHAR *v7; // eax
  _WORD *v8; // eax
  WCHAR *v9; // eax
  WCHAR *v10; // eax
  _WORD *v11; // eax
  const wchar_t *v12; // eax
  const wchar_t *v13; // eax
  CCmdString *v14; // esi
  CCmdString *v15; // eax
  HANDLE v16; // esi
  LSTATUS (__stdcall *RegQueryValueExW)(HKEY, LPCWSTR, LPDWORD, LPDWORD, LPBYTE, LPDWORD); // esi
  LSTATUS v18; // eax
  void *v19; // esi
  CCmdString *v20; // eax
  CCmdString *v21; // eax
  void *v22; // esi
  const wchar_t **v23; // eax
  WCHAR *v24; // esi
  HMODULE v25; // eax
  int (__stdcall *v26)(HKEY, LPCWSTR, LPWSTR, DWORD, LPDWORD, DWORD, LPCWSTR); // eax
  size_t v27; // esi
  WCHAR *v28; // eax
  WCHAR *v29; // esi
  const wchar_t *v30; // eax
  const wchar_t *v31; // eax
  CCmdString *v32; // esi
  CCmdString *v33; // eax
  char v34; // bl
  const wchar_t *v35; // eax
  const wchar_t *v36; // eax
  CCmdString *v37; // esi
  CCmdString *v38; // eax
  const wchar_t *v39; // eax
  CCmdString *v40; // eax
  BYTE v42; // [esp+10h] [ebp-2C4h]
  void *v43; // [esp+14h] [ebp-2C0h]
  BYTE v44[4]; // [esp+18h] [ebp-2BCh]
  BYTE Data[4]; // [esp+1Ch] [ebp-2B8h]
  CCmdString v46; // [esp+20h] [ebp-2B4h]
  CCmdString str; // [esp+24h] [ebp-2B0h]
  DWORD dwValue; // [esp+28h] [ebp-2ACh]
  CCmdString v49; // [esp+2Ch] [ebp-2A8h]
  int a8; // [esp+30h] [ebp-2A4h]
  CCmdString pszResult; // [esp+34h] [ebp-2A0h]
  CCmdString v52; // [esp+38h] [ebp-29Ch]
  CCmdString v53; // [esp+3Ch] [ebp-298h]
  CCmdString v54; // [esp+40h] [ebp-294h]
  void *v55; // [esp+44h] [ebp-290h]
  void *v56; // [esp+48h] [ebp-28Ch]
  void *v57; // [esp+4Ch] [ebp-288h]
  WCHAR *ppv3; // [esp+50h] [ebp-284h]
  CCmdString strResult; // [esp+54h] [ebp-280h]
  void *v60; // [esp+58h] [ebp-27Ch]
  HANDLE Handle; // [esp+5Ch] [ebp-278h]
  CCmdString v62; // [esp+60h] [ebp-274h]
  HKEY KeyHandle; // [esp+64h] [ebp-270h]
  DWORD v64; // [esp+68h] [ebp-26Ch]
  CCmdString v65; // [esp+6Ch] [ebp-268h]
  CCmdString strKeyName; // [esp+70h] [ebp-264h]
  CCmdString v67; // [esp+74h] [ebp-260h]
  CCmdString v68; // [esp+78h] [ebp-25Ch]
  CCmdString str1; // [esp+7Ch] [ebp-258h]
  CCmdString v70; // [esp+80h] [ebp-254h]
  CCmdString v71; // [esp+84h] [ebp-250h]
  CCmdString v72; // [esp+88h] [ebp-24Ch]
  CCmdString strValueName; // [esp+8Ch] [ebp-248h]
  CCmdString str3; // [esp+90h] [ebp-244h]
  CCmdString v75; // [esp+94h] [ebp-240h]
  int a1; // [esp+98h] [ebp-23Ch]
  void *v77; // [esp+9Ch] [ebp-238h]
  void *ppv; // [esp+A0h] [ebp-234h]
  CCmdString strValue; // [esp+A4h] [ebp-230h]
  HKEY v80; // [esp+A8h] [ebp-22Ch]
  DWORD cbData; // [esp+ACh] [ebp-228h]
  CCmdString v82; // [esp+B0h] [ebp-224h]
  HKEY Hkey; // [esp+B4h] [ebp-220h]
  WCHAR *ppszKey; // [esp+B8h] [ebp-21Ch]
  wchar_t pszOutBuf; // [esp+BCh] [ebp-218h]
  int v86; // [esp+2D0h] [ebp-4h]

  v3 = 0;
  a1 = arg0;
  v80 = (HKEY)hKey;
  v64 = 0;
  v4 = malloc(2u);
  ppv = v4;
  *v4 = 0;
  v86 = 0;
  v5 = (WCHAR *)malloc(2u);
  ppszKey = v5;
  *v5 = 0;
  v6 = (WCHAR *)malloc(2u);
  str1.m_String = v6;
  *v6 = 0;
  v7 = (WCHAR *)malloc(2u);
  strValue.m_String = v7;
  *v7 = 0;
  v8 = malloc(2u);
  v60 = v8;
  *v8 = 0;
  v9 = (WCHAR *)malloc(2u);
  v82.m_String = v9;
  *v9 = 0;
  v10 = (WCHAR *)malloc(2u);
  ppv3 = v10;
  *v10 = 0;
  v11 = malloc(2u);
  v77 = v11;
  *v11 = 0;
  v72.m_String = _wcsdup((const wchar_t *)&gszNullString);
  v65.m_String = _wcsdup((const wchar_t *)&gszNullString);
  v67.m_String = _wcsdup((const wchar_t *)&gszNullString);
  v75.m_String = _wcsdup((const wchar_t *)&gszNullString);
  v71.m_String = _wcsdup((const wchar_t *)&gszNullString);
  str3.m_String = _wcsdup((const wchar_t *)&gszNullString);
  strValueName.m_String = _wcsdup((const wchar_t *)&gszNullString);
  v12 = (const wchar_t *)&gszNullString;
  if ( psz )
    v12 = psz;
  strKeyName.m_String = _wcsdup(v12);
  v70.m_String = _wcsdup((const wchar_t *)&gszNullString);
  v13 = (const wchar_t *)&gszNullString;
  if ( psz )
    v13 = psz;
  v68.m_String = _wcsdup(v13);
  LOBYTE(v86) = 17;
  v14 = MakeRegistryKeyName(&strResult, (HKEY)hKey, &strKeyName, &strValueName);
  LOBYTE(v86) = 18;
  v15 = MakeRegistryKeyName(&v62, v80, &v68, &v70);
  LOBYTE(v86) = 19;
  v16 = (HANDLE)PE_UpdateSystemKey(a1, 0, (HANDLE)0xFFFFFFFF, 0, v15, v14, &str3);
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
    if ( !PE_LoadRegKeys(KeyHandle, 0, (CCmdString *)&ppszKey) )
    {
      RegQueryValueExW = ::RegQueryValueExW;
      do
      {
        if ( !PE_OpenKey(KeyHandle, ppszKey, 0, 0x20019u, &Hkey) )
        {
          cbData = 4;
          if ( !RegQueryValueExW(Hkey, L"Type", 0, 0, Data, &cbData) && *(_DWORD *)Data <= 2u )
          {
            cbData = 4;
            if ( !RegQueryValueExW(Hkey, L"Start", 0, 0, v44, &cbData) )
            {
              cbData = 4;
              if ( *(_DWORD *)v44 != 4 || !RegQueryValueExW(Hkey, L"AutorunsDisabled", 0, 0, &v42, &cbData) )
              {
                v18 = PE_ReadRegKey(Hkey, L"ImagePath", 0, 0, (CCmdString *)&ppv);
                v19 = v77;
                if ( v18 )
                {
                  v77 = _wcsdup(ppszKey);
                  free(v19);
                  v20 = operator+(&pszResult, L"\\SystemRoot\\System32\\Drivers\\", (CCmdString *)&ppszKey);
                  v21 = CCmdString::operator+(&str, v20, L".sys");
                  v22 = ppv;
                  ppv = _wcsdup(v21->m_String);
                  free(v22);
                  free(str.m_String);
                  free(pszResult.m_String);
                }
                else
                {
                  v77 = _wcsdup((const wchar_t *)ppv);
                  free(v19);
                }
                v23 = (const wchar_t **)sub_BE4F20((int)&v43, a1, (wchar_t *)ppv);
                v24 = strValue.m_String;
                strValue.m_String = _wcsdup(*v23);
                free(v24);
                free(v43);
                dwValue = sub_BE4ED0();
                PE_ReadRegKey(Hkey, L"Description", 0, 0, &v82);
                if ( *v82.m_String == 64 )
                {
                  v25 = LoadLibraryW(L"Advapi32.dll");
                  v26 = (int (__stdcall *)(HKEY, LPCWSTR, LPWSTR, DWORD, LPDWORD, DWORD, LPCWSTR))GetProcAddress(
                                                                                                    v25,
                                                                                                    "RegLoadMUIStringW");
                  RegLoadMUIStringW = v26;
                  if ( v26 )
                  {
                    if ( !((int (__stdcall *)())v26)() )
                    {
                      v27 = 2 * cbData + 4;
                      v28 = (WCHAR *)realloc(v82.m_String, v27);
                      v82.m_String = v28;
                      if ( v28 )
                      {
                        memset(v28, 0, v27);
                        v28 = v82.m_String;
                      }
                      wcscpy_s(&pszOutBuf, v28, cbData + 1);
                    }
                  }
                }
                v29 = str1.m_String;
                str1.m_String = _wcsdup(ppszKey);
                free(v29);
                v30 = (const wchar_t *)&gszNullString;
                if ( psz )
                  v30 = psz;
                v67.m_String = _wcsdup(v30);
                v65.m_String = _wcsdup((const wchar_t *)&gszNullString);
                v31 = (const wchar_t *)&gszNullString;
                if ( psz )
                  v31 = psz;
                v72.m_String = _wcsdup(v31);
                LOBYTE(v86) = 22;
                v32 = MakeRegistryKeyName(&v54, v80, &v67, (CCmdString *)&ppszKey);
                LOBYTE(v86) = 23;
                v33 = MakeRegistryKeyName(&v49, v80, &v72, &v65);
                LOBYTE(v86) = 24;
                v34 = sub_BE3D40(
                        a1,
                        (CCmdString)v33,
                        (int)v32,
                        (int)&str1,
                        (int)&strValue,
                        (int)&v60,
                        (CCmdString)&ppv3,
                        (int)&a8);
                free(v49.m_String);
                free(v54.m_String);
                free(v72.m_String);
                free(v65.m_String);
                LOBYTE(v86) = 7;
                free(v67.m_String);
                if ( v34 )
                {
                  if ( Handle == (HANDLE)-1 )
                  {
                    v57 = _wcsdup((const wchar_t *)&gszNullString);
                    v56 = _wcsdup((const wchar_t *)&gszNullString);
                    v55 = _wcsdup((const wchar_t *)&gszNullString);
                    v68.m_String = _wcsdup((const wchar_t *)&gszNullString);
                    v70.m_String = _wcsdup((const wchar_t *)&gszNullString);
                    strKeyName.m_String = _wcsdup((const wchar_t *)&gszNullString);
                    strValueName.m_String = _wcsdup((const wchar_t *)&gszNullString);
                    v35 = (const wchar_t *)&gszNullString;
                    if ( psz )
                      v35 = psz;
                    str3.m_String = _wcsdup(v35);
                    v71.m_String = _wcsdup((const wchar_t *)&gszNullString);
                    v36 = (const wchar_t *)&gszNullString;
                    if ( psz )
                      v36 = psz;
                    v75.m_String = _wcsdup(v36);
                    LOBYTE(v86) = 34;
                    v37 = MakeRegistryKeyName(&v52, v80, &str3, &strValueName);
                    LOBYTE(v86) = 35;
                    v38 = MakeRegistryKeyName(&v53, v80, &v75, &v71);
                    LOBYTE(v86) = 36;
                    Handle = (HANDLE)PE_UpdateSystemKey(a1, 0, (HANDLE)0xFFFFFFFF, 0, v38, v37, &strKeyName);
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
                  v62.m_String = _wcsdup((const wchar_t *)&gszNullString);
                  v39 = (const wchar_t *)&gszNullString;
                  if ( psz )
                    v39 = psz;
                  strResult.m_String = _wcsdup(v39);
                  LOBYTE(v86) = 38;
                  v40 = MakeRegistryKeyName(&v46, v80, &strResult, (CCmdString *)&ppszKey);
                  LOBYTE(v86) = 39;
                  PE_UpdateSystemKey(a1, dwValue, Handle, 13u, &str1, v40, &strValue);
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
      while ( !PE_LoadRegKeys(KeyHandle, v3, (CCmdString *)&ppszKey) );
      v16 = Handle;
    }
    RegCloseKey(KeyHandle);
  }
  free(v77);
  free(ppv3);
  free(v82.m_String);
  free(v60);
  free(strValue.m_String);
  free(str1.m_String);
  free(ppszKey);
  free(ppv);
  return v16;
}

//----- (00BF2060) --------------------------------------------------------
void *__cdecl sub_BF2060(int a1, int a2, int *a3)
{
  void *v3; // eax

  v3 = sub_BF2090(a1, a2, *a3, (void *)0xFFFFFFFF, 1);
  return sub_BF2090(a1, a2, *a3, v3, 0);
}

//----- (00BF2090) --------------------------------------------------------
void *__cdecl sub_BF2090(int a1, int a2, int a3, void *a4, char a5)
{
  wchar_t *v5; // edi
  const wchar_t *v6; // ecx
  const WCHAR **v7; // eax
  wchar_t *v8; // esi
  CCmdString *v9; // eax
  CCmdString *v10; // eax
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
  CCmdString *v23; // eax
  CCmdString *v24; // eax
  CCmdString *v25; // eax
  CCmdString *v26; // eax
  WCHAR *v27; // ebx
  int v28; // ebx
  CCmdString *v29; // eax
  int v30; // ebx
  void **v31; // ebx
  WCHAR *v32; // esi
  unsigned int v33; // eax
  LSTATUS v34; // eax
  const WCHAR *v35; // esi
  unsigned int v36; // eax
  void *v37; // esi
  wchar_t *v38; // eax
  WCHAR *v39; // esi
  WCHAR *v40; // esi
  unsigned int v41; // eax
  LSTATUS v42; // eax
  int v43; // ebx
  const WCHAR *v44; // esi
  unsigned int v45; // eax
  CCmdString *v46; // eax
  CCmdString *v47; // eax
  CCmdString *v48; // eax
  CCmdString *v49; // eax
  CCmdString *v50; // eax
  wchar_t *v51; // esi
  const wchar_t **v52; // eax
  WCHAR *v53; // esi
  tagPEStringStruct *v54; // ecx
  const wchar_t **v55; // eax
  WCHAR *v56; // esi
  CCmdString *v57; // eax
  CCmdString *v58; // eax
  CCmdString *v59; // eax
  CCmdString *v60; // eax
  void *v61; // esi
  StringItem StringItem; // [esp+10h] [ebp-118h]
  int a2a; // [esp+20h] [ebp-108h]
  HKEY v65; // [esp+24h] [ebp-104h]
  wchar_t *v66; // [esp+28h] [ebp-100h]
  CCmdString v67; // [esp+2Ch] [ebp-FCh]
  int a8; // [esp+30h] [ebp-F8h]
  CCmdString v69; // [esp+34h] [ebp-F4h]
  WCHAR *ppv1; // [esp+38h] [ebp-F0h]
  HKEY KeyHandle; // [esp+3Ch] [ebp-ECh]
  CCmdString v72; // [esp+40h] [ebp-E8h]
  CCmdString v73; // [esp+44h] [ebp-E4h]
  wchar_t *psz; // [esp+48h] [ebp-E0h]
  CCmdString str1[7]; // [esp+4Ch] [ebp-DCh]
  WCHAR *ppv3; // [esp+68h] [ebp-C0h]
  void *v77; // [esp+6Ch] [ebp-BCh]
  DWORD dwValue; // [esp+70h] [ebp-B8h]
  void *v79; // [esp+74h] [ebp-B4h]
  WCHAR v80[2]; // [esp+78h] [ebp-B0h]
  void *v81; // [esp+7Ch] [ebp-ACh]
  void *v82; // [esp+80h] [ebp-A8h]
  int a1a; // [esp+84h] [ebp-A4h]
  CCmdString v84; // [esp+88h] [ebp-A0h]
  HKEY hRootKey; // [esp+8Ch] [ebp-9Ch]
  void *v86; // [esp+90h] [ebp-98h]
  HKEY__ v87; // [esp+94h] [ebp-94h]
  WCHAR *ppv; // [esp+98h] [ebp-90h]
  CCmdString v89; // [esp+9Ch] [ebp-8Ch]
  CCmdString v90; // [esp+A0h] [ebp-88h]
  CCmdString str; // [esp+A4h] [ebp-84h]
  void *v92; // [esp+A8h] [ebp-80h]
  CCmdString v93; // [esp+ACh] [ebp-7Ch]
  HKEY__ v94; // [esp+B0h] [ebp-78h]
  CCmdString strValue; // [esp+B4h] [ebp-74h]
  CCmdString v96; // [esp+B8h] [ebp-70h]
  CCmdString v97; // [esp+BCh] [ebp-6Ch]
  HKEY__ v98; // [esp+C0h] [ebp-68h]
  HKEY hKey; // [esp+C4h] [ebp-64h]
  LPCWSTR lpAppName; // [esp+C8h] [ebp-60h]
  HKEY__ v101; // [esp+CCh] [ebp-5Ch]
  LPCWSTR v102; // [esp+D0h] [ebp-58h]
  CCmdString str3; // [esp+D4h] [ebp-54h]
  LPCWSTR lpFileName; // [esp+D8h] [ebp-50h]
  WCHAR KeyName; // [esp+DCh] [ebp-4Ch]
  int v106; // [esp+124h] [ebp-4h]

  a1a = a1;
  hRootKey = (HKEY)a2;
  psz = (wchar_t *)a3;
  hKey = 0;
  v102 = (LPCWSTR)malloc(2u);
  *v102 = 0;
  v106 = 0;
  v5 = (wchar_t *)malloc(2u);
  v66 = v5;
  *v5 = 0;
  v101.unused = (int)malloc(2u);
  *(_WORD *)v101.unused = 0;
  lpAppName = (LPCWSTR)malloc(2u);
  *lpAppName = 0;
  *(_DWORD *)v80 = malloc(2u);
  **(_WORD **)v80 = 0;
  str1[4].m_String = (WCHAR *)malloc(2u);
  *str1[4].m_String = 0;
  v98.unused = (int)malloc(2u);
  *(_WORD *)v98.unused = 0;
  v87.unused = (int)malloc(2u);
  *(_WORD *)v87.unused = 0;
  v92 = malloc(2u);
  *(_WORD *)v92 = 0;
  v82 = malloc(2u);
  *(_WORD *)v82 = 0;
  v90.m_String = (WCHAR *)malloc(2u);
  v97.m_String = v90.m_String;
  *v90.m_String = 0;
  v84.m_String = (WCHAR *)malloc(2u);
  *v84.m_String = 0;
  v6 = L"HKCU";
  LOBYTE(v106) = 11;
  if ( (HKEY)a2 != ghCurrentUserKey )
    v6 = L"HKLM";
  v7 = &gszNullString;
  if ( v6 )
    v7 = (const WCHAR **)v6;
  v8 = _wcsdup((const wchar_t *)v7);
  v94.unused = (int)v8;
  v9 = CCmdString::operator+((CCmdString *)&ppv, (CCmdString *)&v94, L"\\");
  v10 = CCmdString::operator+(&str, v9, psz);
  v11 = (void *)v101.unused;
  v101.unused = (int)_wcsdup(v10->m_String);
  free(v11);
  free(str.m_String);
  free(ppv);
  free(v8);
  if ( a4 == (void *)-1 )
  {
    v96.m_String = _wcsdup((const wchar_t *)&gszNullString);
    strValue.m_String = _wcsdup((const wchar_t *)&gszNullString);
    v89.m_String = _wcsdup((const wchar_t *)&gszNullString);
    v93.m_String = _wcsdup((const wchar_t *)&gszNullString);
    lpFileName = _wcsdup((const wchar_t *)&gszNullString);
    str3.m_String = _wcsdup((const wchar_t *)&gszNullString);
    LOBYTE(v106) = 17;
    a4 = (void *)PE_UpdateSystemKey(a1a, 0, (HANDLE)0xFFFFFFFF, 0, (CCmdString *)&v101, (CCmdString *)&v101, &str3);
    free(str3.m_String);
    free((void *)lpFileName);
    free(v93.m_String);
    free(v89.m_String);
    free(strValue.m_String);
    LOBYTE(v106) = 11;
    free(v96.m_String);
  }
  v12 = _wcsdup(psz);
  v97.m_String = v12;
  free(v90.m_String);
  if ( !a5 )
  {
    CCmdString::InsertAt(&v97, L"\\AutorunsDisabled", 0x7FFFFFFFu, 0);
    v12 = v97.m_String;
  }
  v13 = (unsigned int)TlsGetValue(gdwTlsIndex);
  v14 = (void (__stdcall *)(HKEY))RegCloseKey;
  if ( !PE_OpenKey(hRootKey, v12, 0, v13 | 0x20019, &hKey) )
  {
    v94.unused = 0;
    if ( !PE_LoadRegValues(hKey, 0, (LPWSTR *)&lpAppName, 0, 0, (void **)&v98) )
    {
      do
      {
        CCmdString::operator+((CCmdString *)&lpFileName, (CCmdString *)&v98, L"\\Scripts.Ini");
        if ( GetFileAttributesW(lpFileName) == -1 )
        {
          LOBYTE(v106) = 11;
          free((void *)lpFileName);
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
            v17 = (WCHAR *)realloc(v16, 0x412u);
            v18 = v17;
            ppv = v17;
            if ( v17 )
              memset(v17, 0, 0x412u);
            dwValue = GetPrivateProfileStringW(lpAppName, &KeyName, (LPCWSTR)&gszNullString, v18, 0x208u, lpFileName);
            if ( !dwValue )
              break;
            _swprintf(&KeyName, L"%dParameters", v15);
            v19 = malloc(2u);
            *v19 = 0;
            v20 = (WCHAR *)realloc(v19, 0x412u);
            v21 = v20;
            ppv3 = v20;
            if ( v20 )
              memset(v20, 0, 0x412u);
            GetPrivateProfileStringW(lpAppName, &KeyName, (LPCWSTR)&gszNullString, v21, 0x208u, lpFileName);
            if ( (signed int)dwValue > 2 && (!wcsncmp(v18, L"\\\\", 2u) || v18[1] == 58) )
            {
              v22 = (WCHAR *)v102;
              v102 = _wcsdup(v18);
              free(v22);
            }
            else
            {
              v23 = CCmdString::operator+(&v72, (CCmdString *)&v98, L"\\");
              v24 = CCmdString::Append((CCmdString *)&ppv1, v23, (CCmdString *)&lpAppName);
              v25 = CCmdString::operator+(&v73, v24, L"\\");
              v26 = CCmdString::Append(&v67, v25, (CCmdString *)&ppv);
              v27 = (WCHAR *)v102;
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
              v15 = (WCHAR *)((char *)str.m_String + 1);
            }
            else
            {
              str1[0].m_String = (WCHAR *)malloc(2u);
              *str1[0].m_String = 0;
              str1[1].m_String = 0;
              str1[2].m_String = 0;
              str1[3].m_String = 0;
              LOBYTE(v106) = 21;
              sub_BE7040((wchar_t *)v102, (StringItem *)str1);
              v28 = a1a;
              sub_BE4EE0((int)&str3, a1a, (int)str1, 0);
              LOBYTE(v106) = 22;
              dwValue = sub_BE4ED0();
              v29 = CCmdString::operator+(&v69, (CCmdString *)&v102, L" ");
              CCmdString::Append(&v90, v29, (CCmdString *)&ppv3);
              free(v69.m_String);
              v96.m_String = _wcsdup(&KeyName);
              LOBYTE(v106) = 24;
              LOBYTE(v28) = sub_BE3D40(
                              v28,
                              (CCmdString)&v101,
                              (int)&v96,
                              (int)&v90,
                              (int)&str3,
                              (int)&v92,
                              (CCmdString)&v84,
                              (int)&a8);
              free(v96.m_String);
              if ( (_BYTE)v28 )
              {
                if ( a4 == (void *)-1 )
                {
                  v79 = _wcsdup((const wchar_t *)&gszNullString);
                  v77 = _wcsdup((const wchar_t *)&gszNullString);
                  v81 = _wcsdup((const wchar_t *)&gszNullString);
                  v93.m_String = _wcsdup((const wchar_t *)&gszNullString);
                  v89.m_String = _wcsdup((const wchar_t *)&gszNullString);
                  strValue.m_String = _wcsdup((const wchar_t *)&gszNullString);
                  v30 = a1a;
                  LOBYTE(v106) = 30;
                  a4 = (void *)PE_UpdateSystemKey(
                                 a1a,
                                 0,
                                 (HANDLE)0xFFFFFFFF,
                                 0,
                                 (CCmdString *)&v101,
                                 (CCmdString *)&v101,
                                 &strValue);
                  free(strValue.m_String);
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
                v86 = _wcsdup((const wchar_t *)&gszNullString);
                str1[6].m_String = _wcsdup(&KeyName);
                LOBYTE(v106) = 32;
                PE_UpdateSystemKey(v30, dwValue, a4, 0xAu, &str1[6], (CCmdString *)&v102, &str3);
                free(str1[6].m_String);
                free(v86);
              }
              free(v90.m_String);
              free(str3.m_String);
              v31 = (void **)str1[1].m_String;
              if ( str1[1].m_String )
              {
                if ( str1[1].m_String != str1[2].m_String )
                {
                  v32 = str1[2].m_String;
                  do
                  {
                    free(*v31);
                    ++v31;
                  }
                  while ( v31 != (void **)v32 );
                  v31 = (void **)str1[1].m_String;
                  v18 = ppv;
                }
                operator delete(v31);
                str1[1].m_String = 0;
                str1[2].m_String = 0;
                str1[3].m_String = 0;
              }
              free(str1[0].m_String);
              free(v21);
              free(v18);
              v15 = (WCHAR *)((char *)str.m_String + 1);
            }
          }
          free(v18);
          LOBYTE(v106) = 11;
          free((void *)lpFileName);
        }
        ++v94.unused;
      }
      while ( !PE_LoadRegValues(hKey, v94.unused, (LPWSTR *)&lpAppName, 0, 0, (void **)&v98) );
      v12 = v97.m_String;
      v5 = v66;
      v14 = (void (__stdcall *)(HKEY))RegCloseKey;
    }
    v14(hKey);
  }
  v33 = (unsigned int)TlsGetValue(gdwTlsIndex);
  if ( PE_OpenKey(hRootKey, psz, 0, v33 | 0x20019, &hKey) )
    goto LABEL_74;
  v81 = 0;
  v34 = PE_LoadRegKeys(hKey, 0, (CCmdString *)&lpAppName);
  if ( v34 == 259 )
    goto LABEL_73;
  while ( !v34 )
  {
    v35 = lpAppName;
    v36 = (unsigned int)TlsGetValue(gdwTlsIndex);
    if ( !PE_OpenKey(hKey, v35, 0, v36 | 0x20019, &KeyHandle) )
    {
      str3.m_String = (WCHAR *)malloc(2u);
      *str3.m_String = 0;
      LOBYTE(v106) = 33;
      if ( PE_ReadRegKey(KeyHandle, L"DisplayName", 0, 0, &str3) )
        goto LABEL_69;
      v37 = (void *)v87.unused;
      v87.unused = (int)_wcsdup((const wchar_t *)&gszNullString);
      free(v37);
      PE_ReadRegKey(KeyHandle, L"FileSysPath", 0, 0, (CCmdString *)&v87);
      v38 = wcsrchr(psz, 0x5Cu);
      v39 = str1[4].m_String;
      str1[4].m_String = _wcsdup(v38);
      free(v39);
      v40 = v12;
      v12 = _wcsdup(lpAppName);
      v97.m_String = v12;
      free(v40);
      if ( !a5 )
      {
        CCmdString::InsertAt(&v97, L"\\AutorunsDisabled", 0x7FFFFFFFu, 0);
        v12 = v97.m_String;
      }
      v41 = (unsigned int)TlsGetValue(gdwTlsIndex);
      if ( !PE_OpenKey(hKey, v12, 0, v41 | 0x20019, (PHKEY)&str1[5]) )
      {
        v77 = 0;
        v42 = PE_LoadRegKeys((HKEY)str1[5].m_String, 0, (CCmdString *)v80);
        if ( v42 != 259 )
        {
          v43 = a1a;
          do
          {
            if ( v42 )
              break;
            v44 = *(const WCHAR **)v80;
            v45 = (unsigned int)TlsGetValue(gdwTlsIndex);
            if ( !PE_OpenKey((HKEY)str1[5].m_String, v44, 0, v45 | 0x20019, &v65) )
            {
              if ( !PE_ReadRegKey(v65, L"Script", 0, 0, (CCmdString *)&v102) )
              {
                lpFileName = (LPCWSTR)malloc(2u);
                *lpFileName = 0;
                if ( *(_WORD *)v87.unused && *v102 != 92 && v102[1] != 58 )
                {
                  v46 = CCmdString::operator+(&v73, (CCmdString *)&v87, L"\\");
                  v47 = CCmdString::operator+((CCmdString *)&ppv1, v46, L"Scripts");
                  v48 = CCmdString::Append(&v72, v47, &str1[4]);
                  v49 = CCmdString::operator+((CCmdString *)&ppv3, v48, L"\\");
                  v50 = CCmdString::Append(&v69, v49, (CCmdString *)&v102);
                  v51 = v5;
                  v5 = _wcsdup(v50->m_String);
                  v66 = v5;
                  free(v51);
                  free(v69.m_String);
                  free(ppv3);
                  free(v72.m_String);
                  free(ppv1);
                  free(v73.m_String);
                  StringItem::StringItem(&StringItem);
                  LOBYTE(v106) = 35;
                  sub_BE7040(v5, &StringItem);
                  v52 = (const wchar_t **)sub_BE4EE0((int)&v67, v43, (int)&StringItem, 0);
                  v53 = (WCHAR *)lpFileName;
                  lpFileName = _wcsdup(*v52);
                  free(v53);
                  free(v67.m_String);
                  v54 = (tagPEStringStruct *)&StringItem;
                }
                else
                {
                  str1[0].m_String = (WCHAR *)malloc(2u);
                  *str1[0].m_String = 0;
                  str1[1].m_String = 0;
                  str1[2].m_String = 0;
                  str1[3].m_String = 0;
                  LOBYTE(v106) = 36;
                  sub_BE7040((wchar_t *)v102, (StringItem *)str1);
                  v55 = (const wchar_t **)sub_BE4EE0((int)&dwValue, v43, (int)str1, 0);
                  v56 = (WCHAR *)lpFileName;
                  lpFileName = _wcsdup(*v55);
                  free(v56);
                  free((void *)dwValue);
                  v54 = (tagPEStringStruct *)str1;
                }
                LOBYTE(v106) = 34;
                StringItem::~StringItem(v54);
                a2a = sub_BE4ED0();
                v57 = CCmdString::operator+(&v93, (CCmdString *)&v101, L"\\");
                v58 = CCmdString::Append(&v89, v57, (CCmdString *)&lpAppName);
                v59 = CCmdString::operator+(&strValue, v58, L"\\");
                v60 = CCmdString::Append(&v96, v59, (CCmdString *)v80);
                v61 = (void *)v98.unused;
                v98.unused = (int)_wcsdup(v60->m_String);
                free(v61);
                free(v96.m_String);
                free(strValue.m_String);
                free(v89.m_String);
                free(v93.m_String);
                if ( (unsigned __int8)sub_BE3D40(
                                        v43,
                                        (CCmdString)&v101,
                                        (int)&v98,
                                        (int)&str3,
                                        (int)&lpFileName,
                                        (int)&v92,
                                        (CCmdString)&v84,
                                        (int)&a8) )
                {
                  if ( a4 == (void *)-1 )
                  {
                    v86 = _wcsdup((const wchar_t *)&gszNullString);
                    v90.m_String = _wcsdup((const wchar_t *)&gszNullString);
                    ppv = _wcsdup((const wchar_t *)&gszNullString);
                    str.m_String = _wcsdup((const wchar_t *)&gszNullString);
                    v94.unused = (int)_wcsdup((const wchar_t *)&gszNullString);
                    hRootKey = (HKEY)_wcsdup((const wchar_t *)&gszNullString);
                    LOBYTE(v106) = 42;
                    a4 = (void *)PE_UpdateSystemKey(
                                   v43,
                                   0,
                                   (HANDLE)0xFFFFFFFF,
                                   0,
                                   (CCmdString *)&v101,
                                   (CCmdString *)&v101,
                                   (CCmdString *)&hRootKey);
                    free(hRootKey);
                    free((void *)v94.unused);
                    free(str.m_String);
                    free(ppv);
                    free(v90.m_String);
                    free(v86);
                  }
                  v79 = _wcsdup((const wchar_t *)&gszNullString);
                  str1[6].m_String = _wcsdup((const wchar_t *)&gszNullString);
                  LOBYTE(v106) = 44;
                  PE_UpdateSystemKey(v43, a2a, a4, 3u, &str3, (CCmdString *)&v98, (CCmdString *)&lpFileName);
                  free(str1[6].m_String);
                  free(v79);
                }
                LOBYTE(v106) = 33;
                free((void *)lpFileName);
              }
              RegCloseKey(v65);
            }
            v77 = (char *)v77 + 1;
            v42 = PE_LoadRegKeys((HKEY)str1[5].m_String, (DWORD)v77, (CCmdString *)v80);
          }
          while ( v42 != 259 );
          v12 = v97.m_String;
        }
        RegCloseKey((HKEY)str1[5].m_String);
LABEL_69:
        RegCloseKey(KeyHandle);
      }
      LOBYTE(v106) = 11;
      free(str3.m_String);
    }
    v81 = (char *)v81 + 1;
    v34 = PE_LoadRegKeys(hKey, (DWORD)v81, (CCmdString *)&lpAppName);
    if ( v34 == 259 )
      break;
  }
  v14 = (void (__stdcall *)(HKEY))RegCloseKey;
LABEL_73:
  v14(hKey);
LABEL_74:
  free(v84.m_String);
  free(v12);
  free(v82);
  free(v92);
  free((void *)v87.unused);
  free((void *)v98.unused);
  free(str1[4].m_String);
  free(*(void **)v80);
  free((void *)lpAppName);
  free((void *)v101.unused);
  free(v5);
  free((void *)v102);
  return a4;
}

//----- (00BF3070) --------------------------------------------------------
CCmdString *__cdecl CCmdString::Append(CCmdString *ppv, CCmdString *lpszText1, CCmdString *lpszText2)
{
  ppv->m_String = _wcsdup(lpszText1->m_String);
  CCmdString::InsertAt(ppv, lpszText2->m_String, -0x80000001, 0);
  return ppv;
}

//----- (00BF30B0) --------------------------------------------------------
void __cdecl sub_BF30B0(int a1, void *a2, void *a3)
{
  _WORD *v3; // ST50_4
  CCmdString *v4; // esi
  void *v5; // edi
  CCmdString *v6; // eax
  wchar_t *v7; // ST54_4

  v3 = malloc(2u);
  *v3 = 0;
  v4 = (CCmdString *)a3;
  v5 = sub_BF3160(a1, a2, *(wchar_t **)a3, (void *)0xFFFFFFFF);
  v6 = CCmdString::operator+((CCmdString *)&a3, v4, L"\\AutorunsDisabled");
  v7 = _wcsdup(v6->m_String);
  free(v3);
  free(a3);
  sub_BF3160(a1, a2, v7, v5);
  free(v7);
}

//----- (00BF3160) --------------------------------------------------------
void *__cdecl sub_BF3160(int a1, void *a2, wchar_t *psz, void *a4)
{
  const wchar_t *v4; // eax
  const wchar_t *v5; // eax
  CCmdString *v6; // esi
  CCmdString *v7; // eax
  unsigned int v8; // eax
  void (__stdcall *v9)(HKEY); // ebx
  const WCHAR *v10; // esi
  unsigned int v11; // eax
  CCmdString *v12; // eax
  CCmdString *v13; // eax
  WCHAR *v14; // esi
  CCmdString *v15; // eax
  WCHAR *v16; // esi
  const WCHAR *v17; // esi
  unsigned int v18; // eax
  WCHAR *v19; // esi
  const wchar_t **v20; // eax
  WCHAR *v21; // esi
  const wchar_t *v22; // ecx
  const wchar_t *v23; // eax
  CCmdString *v24; // esi
  CCmdString *v25; // eax
  char v26; // bl
  const wchar_t *v27; // eax
  const wchar_t *v28; // eax
  HKEY v29; // ebx
  CCmdString *v30; // esi
  CCmdString *v31; // eax
  const wchar_t *v32; // eax
  CCmdString *v33; // eax
  DWORD v34; // esi
  CCmdString strResult[7]; // [esp+10h] [ebp-B0h]
  WCHAR *ppv; // [esp+2Ch] [ebp-94h]
  WCHAR v38[2]; // [esp+30h] [ebp-90h]
  int a8; // [esp+34h] [ebp-8Ch]
  void *v40; // [esp+38h] [ebp-88h]
  WCHAR v41[2]; // [esp+3Ch] [ebp-84h]
  WCHAR v42[2]; // [esp+40h] [ebp-80h]
  WCHAR *pszResult; // [esp+44h] [ebp-7Ch]
  CCmdString str3; // [esp+48h] [ebp-78h]
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
  *(_WORD *)v60 = 0;
  v71 = 0;
  v56 = malloc(2u);
  *(_WORD *)v56 = 0;
  ppv3 = (WCHAR *)malloc(2u);
  *ppv3 = 0;
  LOBYTE(v71) = 2;
  if ( a4 == (void *)-1 )
  {
    szKeyName = _wcsdup((const wchar_t *)&gszNullString);
    v63 = _wcsdup((const wchar_t *)&gszNullString);
    szArg3 = _wcsdup((const wchar_t *)&gszNullString);
    v64 = _wcsdup((const wchar_t *)&gszNullString);
    v70 = _wcsdup((const wchar_t *)&gszNullString);
    lpszKeyName = _wcsdup((const wchar_t *)&gszNullString);
    szArg4 = _wcsdup((const wchar_t *)&gszNullString);
    v4 = (const wchar_t *)&gszNullString;
    if ( psz )
      v4 = psz;
    pszText = _wcsdup(v4);
    ppszText2 = _wcsdup((const wchar_t *)&gszNullString);
    v5 = (const wchar_t *)&gszNullString;
    if ( psz )
      v5 = psz;
    hKey = (HKEY)_wcsdup(v5);
    LOBYTE(v71) = 12;
    v6 = MakeRegistryKeyName((CCmdString *)&a1a, (HKEY)a2, (CCmdString *)&pszText, (CCmdString *)&szArg4);
    LOBYTE(v71) = 13;
    v7 = MakeRegistryKeyName((CCmdString *)szArg, (HKEY)a2, (CCmdString *)&hKey, (CCmdString *)&ppszText2);
    LOBYTE(v71) = 14;
    a4 = (void *)PE_UpdateSystemKey(a1, 0, (HANDLE)0xFFFFFFFF, 0, v7, v6, (CCmdString *)&lpszKeyName);
    free(*(void **)szArg);
    free(a1a);
    free(hKey);
    free(ppszText2);
    free(pszText);
    free((void *)szArg4);
    free((void *)lpszKeyName);
    free((void *)v70);
    free((void *)v64);
    free((void *)szArg3);
    free((void *)v63);
    LOBYTE(v71) = 2;
    free((void *)szKeyName);
  }
  v8 = (unsigned int)TlsGetValue(gdwTlsIndex);
  if ( !PE_OpenKey((HKEY)a2, psz, 0, v8 | 0x20019, &KeyHandle) )
  {
    *(_DWORD *)szArg = 0;
    lpszKeyName = (LPCWSTR)malloc(2u);
    *lpszKeyName = 0;
    ppszText2 = (WCHAR *)malloc(2u);
    *ppszText2 = 0;
    v70 = (LPCWSTR)malloc(2u);
    *v70 = 0;
    szArg4 = (LPCWSTR)malloc(2u);
    *szArg4 = 0;
    pszText = (WCHAR *)malloc(2u);
    *pszText = 0;
    LOBYTE(v71) = 19;
    v9 = (void (__stdcall *)(HKEY))RegCloseKey;
    if ( !PE_LoadRegKeys(KeyHandle, 0, (CCmdString *)&lpszKeyName) )
    {
      do
      {
        v10 = lpszKeyName;
        v11 = (unsigned int)TlsGetValue(gdwTlsIndex);
        if ( !PE_OpenKey(KeyHandle, v10, 0, v11 | 0x20019, &hKey) )
        {
          if ( PE_ReadRegKey(hKey, L"CLSID", 0, 0, (CCmdString *)&ppszText2) )
          {
            v9(hKey);
          }
          else
          {
            v9(hKey);
            v12 = operator+((CCmdString *)&pszResult, L"CLSID\\", (CCmdString *)&ppszText2);
            v13 = CCmdString::operator+((CCmdString *)&ppv, v12, L"\\InprocServer32");
            v14 = (WCHAR *)v70;
            v70 = _wcsdup(v13->m_String);
            free(v14);
            free(ppv);
            free(pszResult);
            v15 = operator+(&strResult[4], L"HKCR\\CLSID\\", (CCmdString *)&ppszText2);
            v16 = pszText;
            pszText = _wcsdup(v15->m_String);
            free(v16);
            free(strResult[4].m_String);
            v17 = v70;
            v18 = (unsigned int)TlsGetValue(gdwTlsIndex);
            if ( !PE_OpenKey(HKEY_CLASSES_ROOT, v17, 0, v18 | KEY_READ, &hKey) )
            {
              v19 = (WCHAR *)v70;
              v70 = _wcsdup((const wchar_t *)&gszNullString);
              free(v19);
              PE_ReadRegKey(hKey, (LPCWSTR)&gszNullString, 0, 0, (CCmdString *)&v70);
              v9(hKey);
              if ( wcslen(v70) )
              {
                strResult[0].m_String = (WCHAR *)malloc(2u);
                *strResult[0].m_String = 0;
                strResult[1].m_String = 0;
                strResult[2].m_String = 0;
                strResult[3].m_String = 0;
                LOBYTE(v71) = 20;
                sub_BE7040((wchar_t *)v70, (StringItem *)strResult);
                v20 = (const wchar_t **)sub_BE4EE0((int)&v40, a1, (int)strResult, 0);
                v21 = (WCHAR *)szArg4;
                szArg4 = _wcsdup(*v20);
                free(v21);
                free(v40);
                a2a = sub_BE4ED0();
                v22 = (const wchar_t *)&gszNullString;
                if ( psz )
                  v22 = psz;
                szArg3 = _wcsdup(v22);
                v63 = _wcsdup((const wchar_t *)&gszNullString);
                v23 = (const wchar_t *)&gszNullString;
                if ( psz )
                  v23 = psz;
                szKeyName = _wcsdup(v23);
                LOBYTE(v71) = 23;
                v24 = MakeRegistryKeyName(
                        (CCmdString *)v38,
                        (HKEY)a2,
                        (CCmdString *)&szArg3,
                        (CCmdString *)&lpszKeyName);
                LOBYTE(v71) = 24;
                v25 = MakeRegistryKeyName(&strResult[6], (HKEY)a2, (CCmdString *)&szKeyName, (CCmdString *)&v63);
                LOBYTE(v71) = 25;
                v26 = sub_BE3D40(
                        a1,
                        (CCmdString)&lpszKeyName,
                        (int)v25,
                        (int)v24,
                        (int)&szArg4,
                        (int)&v60,
                        (CCmdString)&ppv3,
                        (int)&a8);
                free(strResult[6].m_String);
                free(*(void **)v38);
                free((void *)szKeyName);
                free((void *)v63);
                free((void *)szArg3);
                if ( v26 )
                {
                  if ( a4 == (void *)-1 )
                  {
                    v52 = _wcsdup((const wchar_t *)&gszNullString);
                    v53 = _wcsdup((const wchar_t *)&gszNullString);
                    v49 = _wcsdup((const wchar_t *)&gszNullString);
                    v47 = _wcsdup((const wchar_t *)&gszNullString);
                    v54 = _wcsdup((const wchar_t *)&gszNullString);
                    str3.m_String = _wcsdup((const wchar_t *)&gszNullString);
                    v46 = _wcsdup((const wchar_t *)&gszNullString);
                    v27 = (const wchar_t *)&gszNullString;
                    if ( psz )
                      v27 = psz;
                    v48 = _wcsdup(v27);
                    v51 = _wcsdup((const wchar_t *)&gszNullString);
                    v28 = (const wchar_t *)&gszNullString;
                    if ( psz )
                      v28 = psz;
                    v64 = _wcsdup(v28);
                    v29 = (HKEY)a2;
                    LOBYTE(v71) = 35;
                    v30 = MakeRegistryKeyName((CCmdString *)v41, (HKEY)a2, (CCmdString *)&v48, (CCmdString *)&v46);
                    LOBYTE(v71) = 36;
                    v31 = MakeRegistryKeyName((CCmdString *)v42, (HKEY)a2, (CCmdString *)&v64, (CCmdString *)&v51);
                    LOBYTE(v71) = 37;
                    a4 = (void *)PE_UpdateSystemKey(a1, 0, (HANDLE)0xFFFFFFFF, 0, v31, v30, &str3);
                    free(*(void **)v42);
                    free(*(void **)v41);
                    free((void *)v64);
                    free((void *)v51);
                    free((void *)v48);
                    free((void *)v46);
                    free(str3.m_String);
                    free(v54);
                    free(v47);
                    free(v49);
                    free(v53);
                    free(v52);
                  }
                  else
                  {
                    v29 = (HKEY)a2;
                  }
                  a1a = _wcsdup((const wchar_t *)&gszNullString);
                  v32 = (const wchar_t *)&gszNullString;
                  if ( psz )
                    v32 = psz;
                  v50 = _wcsdup(v32);
                  LOBYTE(v71) = 39;
                  v33 = MakeRegistryKeyName(&strResult[5], v29, (CCmdString *)&v50, (CCmdString *)&lpszKeyName);
                  LOBYTE(v71) = 40;
                  PE_UpdateSystemKey(a1, a2a, a4, 3u, (CCmdString *)&lpszKeyName, v33, (CCmdString *)&szArg4);
                  free(strResult[5].m_String);
                  free((void *)v50);
                  free(a1a);
                }
                StringItem::~StringItem((tagPEStringStruct *)strResult);
                free(pszText);
                free((void *)szArg4);
                free((void *)v70);
                free(ppszText2);
                free((void *)lpszKeyName);
                v9 = (void (__stdcall *)(HKEY))RegCloseKey;
                goto LABEL_31;
              }
            }
          }
        }
        free(pszText);
        free((void *)szArg4);
        free((void *)v70);
        free(ppszText2);
        free((void *)lpszKeyName);
LABEL_31:
        v34 = ++*(_DWORD *)szArg;
        lpszKeyName = (LPCWSTR)malloc(2u);
        *lpszKeyName = 0;
        ppszText2 = (WCHAR *)malloc(2u);
        *ppszText2 = 0;
        v70 = (LPCWSTR)malloc(2u);
        *v70 = 0;
        szArg4 = (LPCWSTR)malloc(2u);
        *szArg4 = 0;
        pszText = (WCHAR *)malloc(2u);
        *pszText = 0;
        LOBYTE(v71) = 19;
      }
      while ( !PE_LoadRegKeys(KeyHandle, v34, (CCmdString *)&lpszKeyName) );
    }
    free(pszText);
    free((void *)szArg4);
    free((void *)v70);
    free(ppszText2);
    free((void *)lpszKeyName);
    v9(KeyHandle);
  }
  free(ppv3);
  free(v56);
  free(v60);
  return a4;
}

//----- (00BF39D0) --------------------------------------------------------
void __cdecl sub_BF39D0(int a1, void *a2, void *a3)
{
  _WORD *v3; // ST50_4
  CCmdString *v4; // esi
  void *v5; // edi
  CCmdString *v6; // eax
  wchar_t *v7; // ST54_4

  v3 = malloc(2u);
  *v3 = 0;
  v4 = (CCmdString *)a3;
  v5 = sub_BF3A80(a1, a2, *(wchar_t **)a3, (void *)0xFFFFFFFF);
  v6 = CCmdString::operator+((CCmdString *)&a3, v4, L"\\AutorunsDisabled");
  v7 = _wcsdup(v6->m_String);
  free(v3);
  free(a3);
  sub_BF3A80(a1, a2, v7, v5);
  free(v7);
}

//----- (00BF3A80) --------------------------------------------------------
void *__cdecl sub_BF3A80(int a1, void *a2, wchar_t *psz, void *a4)
{
  DWORD v4; // ebx
  _WORD *v5; // esi
  wchar_t *v6; // edi
  const wchar_t *v7; // eax
  const wchar_t *v8; // eax
  CCmdString *v9; // edi
  CCmdString *v10; // eax
  unsigned int v11; // eax
  void *v12; // esi
  const WCHAR *v13; // edi
  unsigned int v14; // eax
  const wchar_t **v15; // eax
  WCHAR *v16; // edi
  signed int v17; // eax
  const wchar_t *v18; // ecx
  const wchar_t *v19; // eax
  CCmdString *v20; // edi
  CCmdString *v21; // eax
  char v22; // bl
  wchar_t *v23; // ebx
  const wchar_t *v24; // eax
  const wchar_t *v25; // eax
  CCmdString *v26; // edi
  CCmdString *v27; // eax
  const WCHAR **v28; // eax
  CCmdString *v29; // eax
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
  int a8; // [esp+3Ch] [ebp-74h]
  WCHAR v43[2]; // [esp+40h] [ebp-70h]
  HKEY hKey; // [esp+44h] [ebp-6Ch]
  void *v45; // [esp+48h] [ebp-68h]
  LPCWSTR v46; // [esp+4Ch] [ebp-64h]
  void *v47; // [esp+50h] [ebp-60h]
  CCmdString ppv; // [esp+54h] [ebp-5Ch]
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
  CCmdString str3; // [esp+9Ch] [ebp-14h]
  LPCWSTR lpszKeyName; // [esp+A0h] [ebp-10h]
  int v68; // [esp+ACh] [ebp-4h]

  v4 = 0;
  v50 = 0;
  ppv.m_String = (WCHAR *)malloc(2u);
  *ppv.m_String = 0;
  v68 = 0;
  lpszKeyName = (LPCWSTR)malloc(2u);
  *lpszKeyName = 0;
  v5 = malloc(2u);
  v36 = v5;
  *v5 = 0;
  str3.m_String = (WCHAR *)malloc(2u);
  *str3.m_String = 0;
  v52 = malloc(2u);
  *(_WORD *)v52 = 0;
  v51 = malloc(2u);
  *(_WORD *)v51 = 0;
  ppv3 = (WCHAR *)malloc(2u);
  *ppv3 = 0;
  v6 = psz;
  LOBYTE(v68) = 6;
  if ( a4 == (void *)-1 )
  {
    v59 = _wcsdup((const wchar_t *)&gszNullString);
    szKeyName = _wcsdup((const wchar_t *)&gszNullString);
    v56 = _wcsdup((const wchar_t *)&gszNullString);
    v58 = _wcsdup((const wchar_t *)&gszNullString);
    v60 = _wcsdup((const wchar_t *)&gszNullString);
    v62 = _wcsdup((const wchar_t *)&gszNullString);
    szArg4 = _wcsdup((const wchar_t *)&gszNullString);
    v7 = (const wchar_t *)&gszNullString;
    if ( psz )
      v7 = psz;
    pszText = _wcsdup(v7);
    v57 = _wcsdup((const wchar_t *)&gszNullString);
    v8 = (const wchar_t *)&gszNullString;
    if ( psz )
      v8 = psz;
    szArg3 = _wcsdup(v8);
    LOBYTE(v68) = 16;
    v9 = MakeRegistryKeyName((CCmdString *)&a1a, (HKEY)a2, (CCmdString *)&pszText, (CCmdString *)&szArg4);
    LOBYTE(v68) = 17;
    v10 = MakeRegistryKeyName((CCmdString *)szArg, (HKEY)a2, (CCmdString *)&szArg3, (CCmdString *)&v57);
    LOBYTE(v68) = 18;
    a4 = (void *)PE_UpdateSystemKey(a1, 0, (HANDLE)0xFFFFFFFF, 0, v10, v9, (CCmdString *)&v62);
    free(*(void **)szArg);
    free(a1a);
    free((void *)szArg3);
    free((void *)v57);
    free(pszText);
    free((void *)szArg4);
    free((void *)v62);
    free((void *)v60);
    free((void *)v58);
    free((void *)v56);
    free((void *)szKeyName);
    LOBYTE(v68) = 6;
    free((void *)v59);
    v6 = psz;
  }
  v11 = (unsigned int)TlsGetValue(gdwTlsIndex);
  if ( !PE_OpenKey((HKEY)a2, v6, 0, v11 | 0x20019, &KeyHandle) )
  {
    if ( !PE_LoadRegKeys(KeyHandle, 0, (CCmdString *)&lpszKeyName) )
    {
      v12 = a4;
      do
      {
        v13 = lpszKeyName;
        v14 = (unsigned int)TlsGetValue(gdwTlsIndex);
        if ( !PE_OpenKey(KeyHandle, v13, 0, v14 | 0x20019, &hKey) )
        {
          if ( !PE_ReadRegKey(hKey, L"Source", 0, 0, &ppv) )
          {
            a2a = (int)malloc(2u);
            *(_WORD *)a2a = 0;
            v32 = 0;
            v33 = 0;
            v34 = 0;
            LOBYTE(v68) = 19;
            if ( sub_BE6CC0(ppv.m_String, (StringItem *)&a2a) )
            {
              v15 = (const wchar_t **)sub_BE4EE0((int)&v39, a1, (int)&a2a, 0);
              v16 = str3.m_String;
              str3.m_String = _wcsdup(*v15);
              free(v16);
              free(v39);
              v17 = sub_BE4ED0();
              v18 = (const wchar_t *)&gszNullString;
              dwValue = v17;
              if ( psz )
                v18 = psz;
              szKeyName = _wcsdup(v18);
              v59 = _wcsdup((const wchar_t *)&gszNullString);
              v19 = (const wchar_t *)&gszNullString;
              if ( psz )
                v19 = psz;
              a4 = _wcsdup(v19);
              LOBYTE(v68) = 22;
              v20 = MakeRegistryKeyName(
                      (CCmdString *)v37,
                      (HKEY)a2,
                      (CCmdString *)&szKeyName,
                      (CCmdString *)&lpszKeyName);
              LOBYTE(v68) = 23;
              v21 = MakeRegistryKeyName((CCmdString *)v41, (HKEY)a2, (CCmdString *)&a4, (CCmdString *)&v59);
              LOBYTE(v68) = 24;
              v22 = sub_BE3D40(
                      a1,
                      (CCmdString)&lpszKeyName,
                      (int)v21,
                      (int)v20,
                      (int)&str3,
                      (int)&v52,
                      (CCmdString)&ppv3,
                      (int)&a8);
              free(*(void **)v41);
              free(*(void **)v37);
              free(a4);
              free((void *)v59);
              free((void *)szKeyName);
              if ( v22 )
              {
                if ( v12 == (void *)-1 )
                {
                  v45 = _wcsdup((const wchar_t *)&gszNullString);
                  v47 = _wcsdup((const wchar_t *)&gszNullString);
                  szArg3 = _wcsdup((const wchar_t *)&gszNullString);
                  v57 = _wcsdup((const wchar_t *)&gszNullString);
                  pszText = _wcsdup((const wchar_t *)&gszNullString);
                  szArg4 = _wcsdup((const wchar_t *)&gszNullString);
                  v62 = _wcsdup((const wchar_t *)&gszNullString);
                  v23 = psz;
                  v24 = (const wchar_t *)&gszNullString;
                  if ( psz )
                    v24 = psz;
                  v60 = _wcsdup(v24);
                  v58 = _wcsdup((const wchar_t *)&gszNullString);
                  v25 = (const wchar_t *)&gszNullString;
                  if ( psz )
                    v25 = psz;
                  v56 = _wcsdup(v25);
                  LOBYTE(v68) = 34;
                  v26 = MakeRegistryKeyName((CCmdString *)v35, (HKEY)a2, (CCmdString *)&v60, (CCmdString *)&v62);
                  LOBYTE(v68) = 35;
                  v27 = MakeRegistryKeyName((CCmdString *)v43, (HKEY)a2, (CCmdString *)&v56, (CCmdString *)&v58);
                  LOBYTE(v68) = 36;
                  v12 = (void *)PE_UpdateSystemKey(a1, 0, (HANDLE)0xFFFFFFFF, 0, v27, v26, (CCmdString *)&szArg4);
                  free(*(void **)v43);
                  free(*(void **)v35);
                  free((void *)v56);
                  free((void *)v58);
                  free((void *)v60);
                  free((void *)v62);
                  free((void *)szArg4);
                  free(pszText);
                  free((void *)v57);
                  free((void *)szArg3);
                  free(v47);
                  free(v45);
                }
                else
                {
                  v23 = psz;
                }
                *(_DWORD *)szArg = _wcsdup((const wchar_t *)&gszNullString);
                a1a = _wcsdup((const wchar_t *)&gszNullString);
                v28 = &gszNullString;
                if ( v23 )
                  v28 = (const WCHAR **)v23;
                v46 = _wcsdup((const wchar_t *)v28);
                LOBYTE(v68) = 39;
                v29 = MakeRegistryKeyName((CCmdString *)v38, (HKEY)a2, (CCmdString *)&v46, (CCmdString *)&lpszKeyName);
                LOBYTE(v68) = 40;
                PE_UpdateSystemKey(a1, dwValue, v12, 3u, (CCmdString *)&lpszKeyName, v29, &str3);
                free(*(void **)v38);
                free((void *)v46);
                free(a1a);
                free(*(void **)szArg);
              }
              v4 = v50;
            }
            LOBYTE(v68) = 6;
            StringItem::~StringItem((tagPEStringStruct *)&a2a);
          }
          RegCloseKey(hKey);
        }
        v50 = ++v4;
      }
      while ( !PE_LoadRegKeys(KeyHandle, v4, (CCmdString *)&lpszKeyName) );
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
  free((void *)lpszKeyName);
  free(ppv.m_String);
  return a4;
}

//----- (00BF4150) --------------------------------------------------------
void __cdecl sub_BF4150(int a1, void *a2, void *a3)
{
  _WORD *v3; // ST50_4
  CCmdString *v4; // esi
  void *v5; // edi
  CCmdString *v6; // eax
  wchar_t *v7; // ST54_4

  v3 = malloc(2u);
  *v3 = 0;
  v4 = (CCmdString *)a3;
  v5 = sub_BF4200(a1, a2, *(wchar_t **)a3, (void *)0xFFFFFFFF);
  v6 = CCmdString::operator+((CCmdString *)&a3, v4, L"\\AutorunsDisabled");
  v7 = _wcsdup(v6->m_String);
  free(v3);
  free(a3);
  sub_BF4200(a1, a2, v7, v5);
  free(v7);
}

//----- (00BF4200) --------------------------------------------------------
void *__cdecl sub_BF4200(int a1, void *a2, wchar_t *psz, void *a4)
{
  wchar_t *v4; // edi
  const wchar_t *v5; // eax
  const wchar_t *v6; // eax
  CCmdString *v7; // esi
  CCmdString *v8; // eax
  unsigned int v9; // eax
  void (__stdcall *v10)(HKEY); // ebx
  OLECHAR *v11; // esi
  unsigned int v12; // eax
  wchar_t *v13; // ebx
  UINT v14; // edi
  wchar_t *v15; // eax
  CCmdString *v16; // eax
  wchar_t *v17; // esi
  HMODULE v18; // ebx
  wchar_t *v19; // edi
  LSTATUS v20; // eax
  CCmdString *v21; // eax
  CCmdString *v22; // eax
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
  CCmdString *v36; // esi
  CCmdString *v37; // eax
  const WCHAR **v38; // eax
  const WCHAR **v39; // eax
  HKEY v40; // ebx
  CCmdString *v41; // esi
  CCmdString *v42; // eax
  const WCHAR **v43; // eax
  CCmdString *v44; // eax
  HKEY v45; // [esp-4h] [ebp-2E0h]
  CCmdString str[7]; // [esp+10h] [ebp-2CCh]
  WCHAR v47[2]; // [esp+2Ch] [ebp-2B0h]
  WCHAR v48[2]; // [esp+30h] [ebp-2ACh]
  wchar_t *v49; // [esp+34h] [ebp-2A8h]
  WCHAR v50[2]; // [esp+38h] [ebp-2A4h]
  int a8; // [esp+3Ch] [ebp-2A0h]
  WCHAR *ppstr; // [esp+40h] [ebp-29Ch]
  WCHAR v53[2]; // [esp+44h] [ebp-298h]
  WCHAR *pszResult; // [esp+48h] [ebp-294h]
  int a2a; // [esp+4Ch] [ebp-290h]
  void *v56; // [esp+50h] [ebp-28Ch]
  void *v57; // [esp+54h] [ebp-288h]
  void *v58; // [esp+58h] [ebp-284h]
  CCmdString str3; // [esp+5Ch] [ebp-280h]
  void *v60; // [esp+60h] [ebp-27Ch]
  LPCWSTR v61; // [esp+64h] [ebp-278h]
  LPCWSTR v62; // [esp+68h] [ebp-274h]
  LPCWSTR v63; // [esp+6Ch] [ebp-270h]
  void *v64; // [esp+70h] [ebp-26Ch]
  void *v65; // [esp+74h] [ebp-268h]
  CCmdString v66; // [esp+78h] [ebp-264h]
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
  v67 = (HKEY)a2;
  v49 = psz;
  ppv3 = (wchar_t *)malloc(2u);
  *ppv3 = 0;
  v86 = 0;
  v71 = malloc(2u);
  *(_WORD *)v71 = 0;
  v65 = malloc(2u);
  *(_WORD *)v65 = 0;
  v66.m_String = (WCHAR *)malloc(2u);
  *v66.m_String = 0;
  v72 = malloc(2u);
  *(_WORD *)v72 = 0;
  LOBYTE(v86) = 4;
  if ( a4 == (void *)-1 )
  {
    szKeyName = _wcsdup((const wchar_t *)&gszNullString);
    v75 = _wcsdup((const wchar_t *)&gszNullString);
    szArg3 = _wcsdup((const wchar_t *)&gszNullString);
    v74 = _wcsdup((const wchar_t *)&gszNullString);
    v76 = _wcsdup((const wchar_t *)&gszNullString);
    lpszKeyName = _wcsdup((const wchar_t *)&gszNullString);
    szArg4 = _wcsdup((const wchar_t *)&gszNullString);
    v5 = (const wchar_t *)&gszNullString;
    if ( psz )
      v5 = psz;
    pszText = _wcsdup(v5);
    hKey = (HKEY)_wcsdup((const wchar_t *)&gszNullString);
    v6 = (const wchar_t *)&gszNullString;
    if ( psz )
      v6 = psz;
    ppszText2 = _wcsdup(v6);
    LOBYTE(v86) = 14;
    v7 = MakeRegistryKeyName((CCmdString *)&a1a, (HKEY)a2, (CCmdString *)&pszText, (CCmdString *)&szArg4);
    LOBYTE(v86) = 15;
    v8 = MakeRegistryKeyName((CCmdString *)szArg, (HKEY)a2, (CCmdString *)&ppszText2, (CCmdString *)&hKey);
    LOBYTE(v86) = 16;
    a4 = (void *)PE_UpdateSystemKey(v78, 0, (HANDLE)0xFFFFFFFF, 0, v8, v7, (CCmdString *)&lpszKeyName);
    free(*(void **)szArg);
    free(a1a);
    free(ppszText2);
    free(hKey);
    free(pszText);
    free((void *)szArg4);
    free((void *)lpszKeyName);
    free((void *)v76);
    free((void *)v74);
    free((void *)szArg3);
    free((void *)v75);
    LOBYTE(v86) = 4;
    free((void *)szKeyName);
  }
  v9 = (unsigned int)TlsGetValue(gdwTlsIndex);
  if ( !PE_OpenKey((HKEY)a2, psz, 0, v9 | 0x20019, &KeyHandle) )
  {
    *(_DWORD *)szArg = 0;
    pszText = (OLECHAR *)malloc(2u);
    *pszText = 0;
    ppszText2 = (WCHAR *)malloc(2u);
    *ppszText2 = 0;
    lpszKeyName = (LPCWSTR)malloc(2u);
    *lpszKeyName = 0;
    szArg4 = (LPCWSTR)malloc(2u);
    *szArg4 = 0;
    LOBYTE(v86) = 20;
    v10 = (void (__stdcall *)(HKEY))RegCloseKey;
    if ( !PE_LoadRegKeys(KeyHandle, 0, (CCmdString *)&pszText) )
    {
      while ( 1 )
      {
        v11 = pszText;
        v12 = (unsigned int)TlsGetValue(gdwTlsIndex);
        if ( !PE_OpenKey(KeyHandle, v11, 0, v12 | 0x20019, &hKey) )
        {
          if ( PE_ReadRegKey(hKey, L"MenuText", 0, 0, (CCmdString *)&ppv3)
            && PE_ReadRegKey(hKey, L"ButtonText", 0, 0, (CCmdString *)&ppv3) )
          {
            goto LABEL_25;
          }
          if ( *ppv3 == 64 )
          {
            v13 = _wcsdup(ppv3);
            a2a = (int)v13;
            LOBYTE(v86) = 21;
            v14 = 0;
            if ( wcschr(v13, 0x2Cu) )
            {
              v15 = wcschr(v13, 0x2Cu);
              *v15 = 0;
              v14 = abs(_wtoi(v15 + 1));
            }
            v16 = RequerySystemEnvironmentString((CCmdString *)&ppstr, (CCmdString *)(v13 + 1));
            v17 = _wcsdup(v16->m_String);
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
            v10 = (void (__stdcall *)(HKEY))RegCloseKey;
            v4 = v49;
          }
          if ( !PE_ReadRegKey(hKey, L"Exec", 0, 0, (CCmdString *)&lpszKeyName) )
            goto LABEL_36;
          if ( !PE_ReadRegKey(hKey, L"Script", 0, 0, (CCmdString *)&lpszKeyName) )
          {
            if ( !_wcsnicmp(lpszKeyName, L"res://", 6u) )
            {
              v28 = (WCHAR *)lpszKeyName;
              v29 = lpszKeyName + 6;
              goto LABEL_35;
            }
            if ( !_wcsnicmp(lpszKeyName, L"file://", 7u) )
            {
              v28 = (WCHAR *)lpszKeyName;
              v29 = lpszKeyName + 7;
LABEL_35:
              lpszKeyName = _wcsdup(v29);
              free(v28);
            }
LABEL_36:
            v10(hKey);
            str[0].m_String = (WCHAR *)malloc(2u);
            *str[0].m_String = 0;
            str[1].m_String = 0;
            str[2].m_String = 0;
            str[3].m_String = 0;
            LOBYTE(v86) = 22;
            sub_BE7040((wchar_t *)lpszKeyName, (StringItem *)str);
            v30 = v72;
            v72 = _wcsdup(lpszKeyName);
            free(v30);
            v31 = (const wchar_t **)sub_BE4EE0((int)&str[4], v78, (int)str, 0);
            v32 = (WCHAR *)szArg4;
            szArg4 = _wcsdup(*v31);
            free(v32);
            free(str[4].m_String);
            a2a = sub_BE4ED0();
            v33 = &gszNullString;
            if ( v4 )
              v33 = (const WCHAR **)v4;
            szArg3 = _wcsdup((const wchar_t *)v33);
            v75 = _wcsdup((const wchar_t *)&gszNullString);
            v34 = &gszNullString;
            if ( v4 )
              v34 = (const WCHAR **)v4;
            szKeyName = _wcsdup((const wchar_t *)v34);
            v35 = v67;
            LOBYTE(v86) = 25;
            v36 = MakeRegistryKeyName(&str[6], v67, (CCmdString *)&szArg3, (CCmdString *)&pszText);
            LOBYTE(v86) = 26;
            v37 = MakeRegistryKeyName((CCmdString *)v50, v35, (CCmdString *)&szKeyName, (CCmdString *)&v75);
            LOBYTE(v86) = 27;
            LOBYTE(v35) = sub_BE3D40(
                            v78,
                            (CCmdString)&ppv3,
                            (int)v37,
                            (int)v36,
                            (int)&szArg4,
                            (int)&v71,
                            (CCmdString)&v66,
                            (int)&a8);
            free(*(void **)v50);
            free(str[6].m_String);
            free((void *)szKeyName);
            free((void *)v75);
            free((void *)szArg3);
            if ( (_BYTE)v35 )
            {
              if ( a4 == (void *)-1 )
              {
                v56 = _wcsdup((const wchar_t *)&gszNullString);
                v60 = _wcsdup((const wchar_t *)&gszNullString);
                v58 = _wcsdup((const wchar_t *)&gszNullString);
                v57 = _wcsdup((const wchar_t *)&gszNullString);
                v64 = _wcsdup((const wchar_t *)&gszNullString);
                str3.m_String = _wcsdup((const wchar_t *)&gszNullString);
                v61 = _wcsdup((const wchar_t *)&gszNullString);
                v38 = &gszNullString;
                if ( v4 )
                  v38 = (const WCHAR **)v4;
                v62 = _wcsdup((const wchar_t *)v38);
                v76 = _wcsdup((const wchar_t *)&gszNullString);
                v39 = &gszNullString;
                if ( v4 )
                  v39 = (const WCHAR **)v4;
                v74 = _wcsdup((const wchar_t *)v39);
                v40 = v67;
                LOBYTE(v86) = 37;
                v41 = MakeRegistryKeyName((CCmdString *)v53, v67, (CCmdString *)&v62, (CCmdString *)&v61);
                LOBYTE(v86) = 38;
                v42 = MakeRegistryKeyName((CCmdString *)v48, v40, (CCmdString *)&v74, (CCmdString *)&v76);
                LOBYTE(v86) = 39;
                a4 = (void *)PE_UpdateSystemKey(v78, 0, (HANDLE)0xFFFFFFFF, 0, v42, v41, &str3);
                free(*(void **)v48);
                free(*(void **)v53);
                free((void *)v74);
                free((void *)v76);
                free((void *)v62);
                free((void *)v61);
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
              a1a = _wcsdup((const wchar_t *)&gszNullString);
              v43 = &gszNullString;
              if ( v4 )
                v43 = (const WCHAR **)v4;
              v63 = _wcsdup((const wchar_t *)v43);
              LOBYTE(v86) = 41;
              v44 = MakeRegistryKeyName((CCmdString *)v47, v40, (CCmdString *)&v63, (CCmdString *)&pszText);
              LOBYTE(v86) = 42;
              PE_UpdateSystemKey(v78, a2a, a4, 3u, (CCmdString *)&ppv3, v44, (CCmdString *)&szArg4);
              free(*(void **)v47);
              free((void *)v63);
              free(a1a);
            }
            StringItem::~StringItem((tagPEStringStruct *)str);
            free((void *)szArg4);
            free((void *)lpszKeyName);
            free(ppszText2);
            free(pszText);
            v10 = (void (__stdcall *)(HKEY))RegCloseKey;
            goto LABEL_28;
          }
          v20 = PE_ReadRegKey(hKey, L"ClsidExtension", 0, 0, (CCmdString *)&ppszText2);
          v45 = hKey;
          if ( v20 )
            goto LABEL_26;
          v10(hKey);
          v21 = operator+((CCmdString *)&pszResult, L"CLSID\\", (CCmdString *)&ppszText2);
          v22 = CCmdString::operator+(&str[5], v21, L"\\InprocServer32");
          v23 = (WCHAR *)lpszKeyName;
          lpszKeyName = _wcsdup(v22->m_String);
          free(v23);
          free(str[5].m_String);
          free(pszResult);
          v24 = lpszKeyName;
          v25 = (unsigned int)TlsGetValue(gdwTlsIndex);
          if ( !PE_OpenKey(HKEY_CLASSES_ROOT, v24, 0, v25 | 0x20019, &hKey) )
            break;
        }
LABEL_27:
        free((void *)szArg4);
        free((void *)lpszKeyName);
        free(ppszText2);
        free(pszText);
LABEL_28:
        v26 = ++*(_DWORD *)szArg;
        pszText = (OLECHAR *)malloc(2u);
        *pszText = 0;
        ppszText2 = (WCHAR *)malloc(2u);
        *ppszText2 = 0;
        lpszKeyName = (LPCWSTR)malloc(2u);
        *lpszKeyName = 0;
        szArg4 = (LPCWSTR)malloc(2u);
        *szArg4 = 0;
        LOBYTE(v86) = 20;
        if ( PE_LoadRegKeys(KeyHandle, v26, (CCmdString *)&pszText) )
          goto LABEL_29;
      }
      if ( !PE_ReadRegKey(hKey, (LPCWSTR)&gszNullString, 0, 0, (CCmdString *)&lpszKeyName) )
        goto LABEL_36;
LABEL_25:
      v45 = hKey;
LABEL_26:
      v10(v45);
      goto LABEL_27;
    }
LABEL_29:
    free((void *)szArg4);
    free((void *)lpszKeyName);
    free(ppszText2);
    free(pszText);
    v10(KeyHandle);
  }
  free(v72);
  free(v66.m_String);
  free(v65);
  free(v71);
  free(ppv3);
  return a4;
}

//----- (00BF4E10) --------------------------------------------------------
void *__cdecl PE_RefreshRegistry_0(int a1, void *a2, OLECHAR *psz)
{
  _bstr_t *v3; // eax
  _bstr_t *v4; // eax
  Data_t_bstr_t *v5; // esi
  Data_t_bstr_t *v6; // esi
  Data_t_bstr_t *v7; // esi
  void *v8; // eax
  void *v9; // eax
  Data_t_bstr_t *v10; // esi
  void *v11; // edi
  _bstr_t bstrRet; // [esp+10h] [ebp-1Ch]
  _bstr_t a3; // [esp+14h] [ebp-18h]
  _bstr_t v15; // [esp+18h] [ebp-14h]
  _bstr_t a1a; // [esp+1Ch] [ebp-10h]
  int v17; // [esp+28h] [ebp-4h]

  _bstr_t::_bstr_t((tagEventSetItem *)&a3, L"AutorunsDisabled");
  v17 = 0;
  v3 = (_bstr_t *)_bstr_t::_bstr_t((tagEventSetItem *)&v15, L"\\");
  LOBYTE(v17) = 1;
  v4 = _bstr_t::operator+(&a1a, psz, v3);
  LOBYTE(v17) = 2;
  _bstr_t::operator+(v4, &bstrRet, &a3);
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
        operator delete[](v5->m_str);
        v5->m_str = 0;
      }
      operator delete(v5);
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
        operator delete[](v6->m_str);
        v6->m_str = 0;
      }
      operator delete(v6);
    }
    v15.m_Data = 0;
  }
  v7 = a3.m_Data;
  LOBYTE(v17) = 6;
  if ( a3.m_Data && !InterlockedDecrement(&a3.m_Data->m_RefCount) )
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
  v8 = sub_BF4FF0(a1, a2, psz, (void *)0xFFFFFFFF, 1);
  v9 = sub_BF4FF0(a1, a2, psz, v8, 0);
  v10 = bstrRet.m_Data;
  v11 = v9;
  if ( bstrRet.m_Data && !InterlockedDecrement(&bstrRet.m_Data->m_RefCount) && v10 )
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
  return v11;
}

//----- (00BF4FF0) --------------------------------------------------------
void *__cdecl sub_BF4FF0(int a1, void *a2, wchar_t *psz, void *a4, char a5)
{
  void *v5; // esi
  const wchar_t *v6; // eax
  const wchar_t *v7; // eax
  CCmdString *v8; // esi
  CCmdString *v9; // eax
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
  CCmdString *v24; // eax
  CCmdString *v25; // edi
  CCmdString *v26; // eax
  wchar_t *v27; // edi
  const wchar_t *v28; // eax
  const WCHAR **v29; // eax
  CCmdString *v30; // esi
  CCmdString *v31; // eax
  const WCHAR **v32; // eax
  wchar_t *v33; // esi
  CCmdString *v34; // eax
  CCmdString *v35; // eax
  unsigned int v36; // eax
  wchar_t *v37; // esi
  const wchar_t *v38; // eax
  const WCHAR **v39; // eax
  HKEY v40; // edi
  CCmdString *v41; // esi
  CCmdString *v42; // eax
  CCmdString *v43; // eax
  const WCHAR *v44; // eax
  wchar_t *v45; // eax
  wchar_t *v46; // edi
  const wchar_t *v47; // eax
  wchar_t *v48; // eax
  wchar_t *v49; // esi
  CCmdString *v50; // eax
  CCmdString *v51; // eax
  int v52; // eax
  WCHAR *v53; // esi
  CCmdString strResult[7]; // [esp+10h] [ebp-528h]
  BYTE v55[4]; // [esp+2Ch] [ebp-50Ch]
  WCHAR v56[2]; // [esp+30h] [ebp-508h]
  CCmdString v57; // [esp+34h] [ebp-504h]
  WCHAR v58[2]; // [esp+38h] [ebp-500h]
  CCmdString v59; // [esp+3Ch] [ebp-4FCh]
  CCmdString v60; // [esp+40h] [ebp-4F8h]
  CCmdString v61; // [esp+44h] [ebp-4F4h]
  WCHAR *pszResult; // [esp+48h] [ebp-4F0h]
  WCHAR *ppv1; // [esp+4Ch] [ebp-4ECh]
  WCHAR v64[2]; // [esp+50h] [ebp-4E8h]
  WCHAR v65[2]; // [esp+54h] [ebp-4E4h]
  CCmdString str; // [esp+58h] [ebp-4E0h]
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
  CCmdString strValue; // [esp+ACh] [ebp-48Ch]
  void *v88; // [esp+B0h] [ebp-488h]
  LPCWSTR v89; // [esp+B4h] [ebp-484h]
  CCmdString str3; // [esp+B8h] [ebp-480h]
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
  v105 = (HKEY)a2;
  v98 = psz;
  v111 = 0;
  v102 = 0;
  if ( a4 == (void *)-1 )
  {
    ppszText2 = _wcsdup((const wchar_t *)&gszNullString);
    v116 = 0;
    lpszKeyName = _wcsdup((const wchar_t *)&gszNullString);
    szKeyName = _wcsdup((const wchar_t *)&gszNullString);
    v101 = _wcsdup((const wchar_t *)&gszNullString);
    szArg3 = _wcsdup((const wchar_t *)&gszNullString);
    KeyHandle = (HKEY)_wcsdup((const wchar_t *)&gszNullString);
    szArg4 = _wcsdup((const wchar_t *)&gszNullString);
    v6 = (const wchar_t *)&gszNullString;
    if ( psz )
      v6 = psz;
    pszText = _wcsdup(v6);
    v104 = _wcsdup((const wchar_t *)&gszNullString);
    v7 = (const wchar_t *)&gszNullString;
    if ( psz )
      v7 = psz;
    v110.unused = (int)_wcsdup(v7);
    LOBYTE(v116) = 9;
    v8 = MakeRegistryKeyName((CCmdString *)&a1a, (HKEY)a2, (CCmdString *)&pszText, (CCmdString *)&szArg4);
    LOBYTE(v116) = 10;
    v9 = MakeRegistryKeyName((CCmdString *)szArg, (HKEY)a2, (CCmdString *)&v110, (CCmdString *)&v104);
    LOBYTE(v116) = 11;
    v5 = (void *)PE_UpdateSystemKey(v106, 0, (HANDLE)0xFFFFFFFF, 0, v9, v8, (CCmdString *)&KeyHandle);
    a4 = v5;
    free(*(void **)szArg);
    free(a1a);
    free((void *)v110.unused);
    free((void *)v104);
    free(pszText);
    free((void *)szArg4);
    free(KeyHandle);
    free((void *)szArg3);
    free((void *)v101);
    free((void *)szKeyName);
    free((void *)lpszKeyName);
    v116 = -1;
    free(ppszText2);
  }
  hKey = 0;
  v10 = (unsigned int)TlsGetValue(gdwTlsIndex);
  if ( PE_OpenKey((HKEY)a2, psz, 0, v10 | 0x20019, &hKey) )
    return v5;
  *(_DWORD *)szArg = 0;
  if ( !RegEnumKeyW(hKey, 0, &Name, 0x104u) )
  {
    v12 = (WCHAR *)lpszKeyName;
    do
    {
      KeyHandle = 0;
      if ( a5 )
      {
        v13 = ppszText2;
        lpszKeyName = (LPCWSTR)&gszNullString;
      }
      else
      {
        v13 = _wcsdup(L"AutorunsDisabled");
        ppszText2 = v13;
        v14 = v111 | 1;
        v15 = operator+((CCmdString *)&pszResult, L"\\", (CCmdString *)&ppszText2)->m_String;
        v111 = v14 | 2;
        v102 = v14 | 2;
        lpszKeyName = v15;
      }
      v16 = _wcsdup(&Name);
      v17 = v16;
      v110.unused = (int)v16;
      v116 = 14;
      lpszKeyName = CCmdString::operator+((CCmdString *)&ppv, (CCmdString *)&v110, lpszKeyName)->m_String;
      LOBYTE(v116) = 15;
      v18 = (unsigned int)TlsGetValue(gdwTlsIndex);
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
        if ( !RegQueryValueExW(KeyHandle, L"Debugger", 0, 0, (LPBYTE)Data, &cbData) )
        {
          pszText = (WCHAR *)malloc(2u);
          *pszText = 0;
          v116 = 16;
          v110.unused = (int)malloc(2u);
          *(_WORD *)v110.unused = 0;
          v104 = (LPCWSTR)malloc(2u);
          *v104 = 0;
          strResult[0].m_String = (WCHAR *)malloc(2u);
          *strResult[0].m_String = 0;
          strResult[1].m_String = 0;
          strResult[2].m_String = 0;
          strResult[3].m_String = 0;
          LOBYTE(v116) = 19;
          sub_BE7040(Data, (StringItem *)strResult);
          sub_BE4EE0((int)&szArg4, v106, (int)strResult, 0);
          LOBYTE(v116) = 20;
          v94.unused = sub_BE4ED0();
          v82 = _wcsdup(&Name);
          v20 = v98;
          v21 = (const wchar_t *)&gszNullString;
          if ( v98 )
            v21 = v98;
          szArg3 = _wcsdup(v21);
          v101 = _wcsdup((const wchar_t *)&gszNullString);
          v22 = &gszNullString;
          if ( v20 )
            v22 = (const WCHAR **)v20;
          szKeyName = _wcsdup((const wchar_t *)v22);
          v23 = _wcsdup(&Name);
          lpszKeyName = v23;
          v24 = CCmdString::operator+(&str, (CCmdString *)&lpszKeyName, L"\\Debugger");
          LOBYTE(v116) = 26;
          v25 = MakeRegistryKeyName(&strResult[5], v105, (CCmdString *)&szArg3, v24);
          LOBYTE(v116) = 27;
          v26 = MakeRegistryKeyName(&strResult[4], v105, (CCmdString *)&szKeyName, (CCmdString *)&v101);
          LOBYTE(v116) = 28;
          v112 = sub_BE3D40(
                   v106,
                   (CCmdString)v26,
                   (int)v25,
                   (int)&v82,
                   (int)&szArg4,
                   (int)&pszText,
                   (CCmdString)&v104,
                   (int)&strResult[6]);
          free(strResult[4].m_String);
          free(strResult[5].m_String);
          free(str.m_String);
          free(v23);
          free((void *)szKeyName);
          free((void *)v101);
          free((void *)szArg3);
          free(v82);
          if ( v112 )
          {
            if ( a4 == (void *)-1 )
            {
              v86 = _wcsdup((const wchar_t *)&gszNullString);
              v78 = _wcsdup((const wchar_t *)&gszNullString);
              v88 = _wcsdup((const wchar_t *)&gszNullString);
              v74 = _wcsdup((const wchar_t *)&gszNullString);
              v73 = _wcsdup((const wchar_t *)&gszNullString);
              str3.m_String = _wcsdup((const wchar_t *)&gszNullString);
              v69 = _wcsdup((const wchar_t *)&gszNullString);
              v27 = v98;
              v28 = (const wchar_t *)&gszNullString;
              if ( v98 )
                v28 = v98;
              v71 = _wcsdup(v28);
              v75 = _wcsdup((const wchar_t *)&gszNullString);
              v29 = &gszNullString;
              if ( v27 )
                v29 = (const WCHAR **)v27;
              v77 = _wcsdup((const wchar_t *)v29);
              LOBYTE(v116) = 38;
              v30 = MakeRegistryKeyName((CCmdString *)v64, v105, (CCmdString *)&v71, (CCmdString *)&v69);
              LOBYTE(v116) = 39;
              v31 = MakeRegistryKeyName((CCmdString *)v58, v105, (CCmdString *)&v77, (CCmdString *)&v75);
              LOBYTE(v116) = 40;
              a4 = (void *)PE_UpdateSystemKey(v106, 0, (HANDLE)0xFFFFFFFF, 0, v31, v30, &str3);
              free(*(void **)v58);
              free(*(void **)v64);
              free((void *)v77);
              free((void *)v75);
              free((void *)v71);
              free((void *)v69);
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
            v92 = _wcsdup((const wchar_t *)&gszNullString);
            v76 = _wcsdup(Data);
            v32 = &gszNullString;
            if ( v27 )
              v32 = (const WCHAR **)v27;
            v84 = _wcsdup((const wchar_t *)v32);
            ppv3 = _wcsdup(&Name);
            v33 = _wcsdup(&Name);
            lpszKeyName = v33;
            v34 = CCmdString::operator+(&v60, (CCmdString *)&lpszKeyName, L"\\Debugger");
            LOBYTE(v116) = 46;
            v35 = MakeRegistryKeyName((CCmdString *)v56, v105, (CCmdString *)&v84, v34);
            LOBYTE(v116) = 47;
            PE_UpdateSystemKey(v106, v94.unused, a4, 1u, (CCmdString *)&ppv3, v35, (CCmdString *)&szArg4);
            free(*(void **)v56);
            free(v60.m_String);
            free(v33);
            free(ppv3);
            free((void *)v84);
            free(v76);
            free(v92);
          }
          free((void *)szArg4);
          StringItem::~StringItem((tagPEStringStruct *)strResult);
          free((void *)v104);
          free((void *)v110.unused);
          v116 = -1;
          free(pszText);
        }
        RegCloseKey(KeyHandle);
      }
      v36 = (unsigned int)TlsGetValue(gdwTlsIndex);
      if ( !PE_OpenKey(hKey, &Name, 0, v36 | 0x20019, &KeyHandle) )
      {
        cbData = 4;
        if ( !RegQueryValueExW(KeyHandle, L"GlobalFlag", 0, 0, v55, &cbData) && *(_WORD *)v55 & 0x100 )
        {
          if ( a4 == (void *)-1 )
          {
            a1a = _wcsdup((const wchar_t *)&gszNullString);
            v116 = 48;
            v79 = _wcsdup((const wchar_t *)&gszNullString);
            v81 = _wcsdup((const wchar_t *)&gszNullString);
            v83 = _wcsdup((const wchar_t *)&gszNullString);
            v85 = _wcsdup((const wchar_t *)&gszNullString);
            strValue.m_String = _wcsdup((const wchar_t *)&gszNullString);
            v89 = _wcsdup((const wchar_t *)&gszNullString);
            v37 = v98;
            v38 = (const wchar_t *)&gszNullString;
            if ( v98 )
              v38 = v98;
            v91 = _wcsdup(v38);
            v80 = _wcsdup((const wchar_t *)&gszNullString);
            v39 = &gszNullString;
            if ( v37 )
              v39 = (const WCHAR **)v37;
            v72 = _wcsdup((const wchar_t *)v39);
            v40 = v105;
            LOBYTE(v116) = 57;
            v41 = MakeRegistryKeyName((CCmdString *)v65, v105, (CCmdString *)&v91, (CCmdString *)&v89);
            LOBYTE(v116) = 58;
            v42 = MakeRegistryKeyName((CCmdString *)v67, v40, (CCmdString *)&v72, (CCmdString *)&v80);
            LOBYTE(v116) = 59;
            a4 = (void *)PE_UpdateSystemKey(v106, 0, (HANDLE)0xFFFFFFFF, 0, v42, v41, &strValue);
            free(*(void **)v67);
            free(*(void **)v65);
            free((void *)v72);
            free((void *)v80);
            free((void *)v91);
            free((void *)v89);
            free(strValue.m_String);
            free(v85);
            free(v83);
            free(v81);
            free(v79);
            free(a1a);
          }
          if ( a5 )
          {
            lpszKeyName = (LPCWSTR)&gszNullString;
          }
          else
          {
            v12 = _wcsdup(L"AutorunsDisabled");
            lpszKeyName = v12;
            v43 = operator+(&v59, L"\\", (CCmdString *)&lpszKeyName);
            v111 |= 0xCu;
            v44 = v43->m_String;
            v102 = v111;
            lpszKeyName = v44;
          }
          v45 = _wcsdup(&Name);
          v46 = v45;
          v110.unused = (int)v45;
          v47 = (const wchar_t *)&gszNullString;
          if ( v98 )
            v47 = v98;
          v48 = _wcsdup(v47);
          v49 = v48;
          v94.unused = (int)v48;
          v50 = CCmdString::operator+(&v61, (CCmdString *)&v94, L"\\");
          v51 = CCmdString::Append((CCmdString *)&ppv1, v50, (CCmdString *)&v110);
          CCmdString::operator+(&v57, v51, lpszKeyName);
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
          sub_BF6A10(v106, v105, v57.m_String, L"VerifierDlls", &Name, 32, a4);
          v116 = -1;
          free(v53);
        }
        RegCloseKey(KeyHandle);
      }
      ++*(_DWORD *)szArg;
    }
    while ( !RegEnumKeyW(hKey, *(DWORD *)szArg, &Name, 0x104u) );
  }
  RegCloseKey(hKey);
  return a4;
}

//----- (00BF5E10) --------------------------------------------------------
void __cdecl PE_UpdateRegistry2(unsigned int dwValue, HKEY__ *hKey, const wchar_t *lpszKeyName)
{
  _bstr_t *v3; // eax
  _bstr_t *v4; // eax
  Data_t_bstr_t *v5; // esi
  Data_t_bstr_t *v6; // esi
  Data_t_bstr_t *v7; // esi
  void *v8; // eax
  Data_t_bstr_t *v9; // esi
  _bstr_t bstrRet; // [esp+10h] [ebp-1Ch]
  _bstr_t a3; // [esp+14h] [ebp-18h]
  _bstr_t v12; // [esp+18h] [ebp-14h]
  _bstr_t a1; // [esp+1Ch] [ebp-10h]
  int v14; // [esp+28h] [ebp-4h]

  _bstr_t::_bstr_t((tagEventSetItem *)&a3, L"AutorunsDisabled");
  v14 = 0;
  v3 = (_bstr_t *)_bstr_t::_bstr_t((tagEventSetItem *)&v12, L"\\");
  LOBYTE(v14) = 1;
  v4 = _bstr_t::operator+(&a1, (OLECHAR *)lpszKeyName, v3);
  LOBYTE(v14) = 2;
  _bstr_t::operator+(v4, &bstrRet, &a3);
  v5 = a1.m_Data;
  if ( a1.m_Data )
  {
    if ( !InterlockedDecrement(&a1.m_Data->m_RefCount) && v5 )
    {
      if ( v5->m_wstr )
      {
        SysFreeString(v5->m_wstr);
        v5->m_wstr = 0;
      }
      if ( v5->m_str )
      {
        operator delete[](v5->m_str);
        v5->m_str = 0;
      }
      operator delete(v5);
    }
    a1.m_Data = 0;
  }
  v6 = v12.m_Data;
  if ( v12.m_Data )
  {
    if ( !InterlockedDecrement(&v12.m_Data->m_RefCount) && v6 )
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
    v12.m_Data = 0;
  }
  v7 = a3.m_Data;
  LOBYTE(v14) = 6;
  if ( a3.m_Data && !InterlockedDecrement(&a3.m_Data->m_RefCount) )
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
  v8 = sub_BF5FF0(dwValue, hKey, (wchar_t *)lpszKeyName, (void *)0xFFFFFFFF, 1);
  sub_BF5FF0(dwValue, hKey, (wchar_t *)lpszKeyName, v8, 0);
  v9 = bstrRet.m_Data;
  if ( bstrRet.m_Data && !InterlockedDecrement(&bstrRet.m_Data->m_RefCount) && v9 )
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
}

//----- (00BF5FF0) --------------------------------------------------------
void *__cdecl sub_BF5FF0(int a1, void *a2, wchar_t *a3, void *a4, char a5)
{
  const wchar_t *v5; // eax
  const wchar_t *v6; // eax
  CCmdString *v7; // esi
  CCmdString *v8; // eax
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
  CCmdString *v20; // eax
  CCmdString *v21; // eax
  CCmdString *v22; // eax
  CCmdString *v23; // eax
  unsigned int v24; // eax
  wchar_t *v25; // esi
  CCmdString *v26; // eax
  WCHAR *v27; // edi
  unsigned int v28; // eax
  int v29; // eax
  const WCHAR **v30; // edi
  const WCHAR **v31; // ecx
  const WCHAR **v32; // eax
  const WCHAR **v33; // eax
  CCmdString *v34; // esi
  CCmdString *v35; // eax
  const WCHAR **v36; // esi
  const WCHAR **v37; // eax
  const WCHAR **v38; // eax
  CCmdString *v39; // eax
  const WCHAR **v40; // eax
  CCmdString *v41; // eax
  DWORD cbData[7]; // [esp+10h] [ebp-494h]
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
  CCmdString str3; // [esp+58h] [ebp-44Ch]
  CCmdString v56; // [esp+5Ch] [ebp-448h]
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
  hRootKey = (HKEY)a2;
  *(_DWORD *)szArg = a3;
  if ( a4 == (void *)-1 )
  {
    v62 = _wcsdup((const wchar_t *)&gszNullString);
    v68 = 0;
    v49 = _wcsdup((const wchar_t *)&gszNullString);
    ppv1 = _wcsdup((const wchar_t *)&gszNullString);
    ppv = _wcsdup((const wchar_t *)&gszNullString);
    szKeyName = _wcsdup((const wchar_t *)&gszNullString);
    str3.m_String = _wcsdup((const wchar_t *)&gszNullString);
    szArg4 = _wcsdup((const wchar_t *)&gszNullString);
    v5 = (const wchar_t *)&gszNullString;
    if ( a3 )
      v5 = a3;
    pszText = _wcsdup(v5);
    v52 = _wcsdup((const wchar_t *)&gszNullString);
    v6 = (const wchar_t *)&gszNullString;
    if ( a3 )
      v6 = a3;
    szArg3 = _wcsdup(v6);
    LOBYTE(v68) = 9;
    v7 = MakeRegistryKeyName((CCmdString *)&a1a, (HKEY)a2, (CCmdString *)&pszText, (CCmdString *)&szArg4);
    LOBYTE(v68) = 10;
    v8 = MakeRegistryKeyName((CCmdString *)&v63, (HKEY)a2, (CCmdString *)&szArg3, (CCmdString *)&v52);
    LOBYTE(v68) = 11;
    a4 = (void *)PE_UpdateSystemKey(v48, 0, (HANDLE)0xFFFFFFFF, 0, v8, v7, &str3);
    free((void *)v63.unused);
    free(a1a);
    free((void *)szArg3);
    free((void *)v52);
    free(pszText);
    free((void *)szArg4);
    free(str3.m_String);
    free((void *)szKeyName);
    free(ppv);
    free(ppv1);
    free(v49);
    free((void *)v62);
  }
  v62 = (LPCWSTR)malloc(2u);
  *v62 = 0;
  v68 = 12;
  hKey = 0;
  v9 = _wcsdup(a3);
  szArg3 = v9;
  v10 = wcsrchr(v9, 0x5Cu);
  *v10 = 0;
  v11 = (int)(v10 + 1);
  *(_DWORD *)v46 = v10 + 1;
  if ( a5 )
  {
    v12 = _wcsdup(a3);
    v49 = v12;
    free((void *)v62);
  }
  else
  {
    v13 = &gszNullString;
    if ( v11 )
      v13 = (const WCHAR **)v11;
    v14 = _wcsdup((const wchar_t *)v13);
    v15 = v14;
    ppv3 = v14;
    v16 = _wcsdup(L"AutorunsDisabled");
    v17 = v16;
    a1a = v16;
    v18 = (const wchar_t *)&gszNullString;
    if ( szArg3 )
      v18 = szArg3;
    v19 = _wcsdup(v18);
    v63.unused = (int)v19;
    v20 = CCmdString::operator+((CCmdString *)&ppv, (CCmdString *)&v63, L"\\");
    v21 = CCmdString::Append((CCmdString *)&ppv1, v20, (CCmdString *)&a1a);
    v22 = CCmdString::operator+((CCmdString *)&v59, v21, L"\\");
    v23 = CCmdString::Append(&v56, v22, (CCmdString *)&ppv3);
    v49 = _wcsdup(v23->m_String);
    free((void *)v62);
    free(v56.m_String);
    free((void *)v59);
    free(ppv1);
    free(ppv);
    free(v19);
    free(v17);
    free(v15);
    v12 = v49;
  }
  v24 = (unsigned int)TlsGetValue(gdwTlsIndex);
  if ( !PE_OpenKey(hRootKey, (LPCWSTR)v12, 0, v24 | 0x20019, &hKey) )
  {
    KeyHandle = 0;
    cbData[6] = 520;
    if ( !RegQueryValueExW(hKey, 0, 0, 0, (LPBYTE)Data, &cbData[6]) )
    {
      v25 = _wcsdup(Data);
      v63.unused = (int)v25;
      v26 = operator+((CCmdString *)&ppv3, L"Software\\Classes\\", (CCmdString *)&v63);
      v27 = CCmdString::operator+((CCmdString *)&a1a, v26, L"\\shell\\open\\command")->m_String;
      LOBYTE(v68) = 15;
      v28 = (unsigned int)TlsGetValue(gdwTlsIndex);
      v65 = PE_OpenKey(hRootKey, v27, 0, v28 | 0x20019, &KeyHandle) == 0;
      free(a1a);
      free(ppv3);
      LOBYTE(v68) = 12;
      free(v25);
      if ( v65 )
      {
        cbData[6] = 520;
        if ( !RegQueryValueExW(KeyHandle, 0, 0, 0, (LPBYTE)v67, &cbData[6]) )
        {
          v29 = wcscmp(v67, L"\"%1\" %*");
          if ( v29 )
            v29 = -(v29 < 0) | 1;
          if ( v29 )
          {
            szArg4 = (LPCWSTR)malloc(2u);
            *szArg4 = 0;
            v52 = (LPCWSTR)malloc(2u);
            *v52 = 0;
            pszText = (WCHAR *)malloc(2u);
            *pszText = 0;
            StringItem::StringItem((StringItem *)cbData);
            LOBYTE(v68) = 19;
            sub_BE7040(v67, (StringItem *)cbData);
            sub_BE4EE0((int)&str3, v48, (int)cbData, 0);
            LOBYTE(v68) = 20;
            cbData[5] = sub_BE4ED0();
            v59 = _wcsdup((const wchar_t *)&gszNullString);
            v30 = *(const WCHAR ***)szArg;
            v31 = &gszNullString;
            if ( *(_DWORD *)szArg )
              v31 = *(const WCHAR ***)szArg;
            szKeyName = _wcsdup((const wchar_t *)v31);
            ppv = _wcsdup((const wchar_t *)&gszNullString);
            v32 = &gszNullString;
            if ( v30 )
              v32 = v30;
            ppv1 = _wcsdup((const wchar_t *)v32);
            v33 = &gszNullString;
            if ( v30 )
              v33 = v30;
            v62 = _wcsdup((const wchar_t *)v33);
            LOBYTE(v68) = 25;
            v34 = MakeRegistryKeyName((CCmdString *)&a1a, hRootKey, (CCmdString *)&szKeyName, (CCmdString *)&v59);
            LOBYTE(v68) = 26;
            v35 = MakeRegistryKeyName((CCmdString *)&v63, hRootKey, (CCmdString *)&ppv1, (CCmdString *)&ppv);
            LOBYTE(v68) = 27;
            v65 = sub_BE3D40(
                    v48,
                    (CCmdString)&v62,
                    (int)v35,
                    (int)v34,
                    (int)&str3,
                    (int)&szArg4,
                    (CCmdString)&pszText,
                    (int)&cbData[4]);
            free((void *)v63.unused);
            free(a1a);
            free((void *)v62);
            free(ppv1);
            free(ppv);
            free((void *)szKeyName);
            LOBYTE(v68) = 20;
            free((void *)v59);
            if ( v65 )
            {
              if ( a4 == (void *)-1 )
              {
                v63.unused = (int)_wcsdup((const wchar_t *)&gszNullString);
                a1a = _wcsdup((const wchar_t *)&gszNullString);
                ppv3 = _wcsdup((const wchar_t *)&gszNullString);
                v56.m_String = _wcsdup((const wchar_t *)&gszNullString);
                szKeyName = _wcsdup((const wchar_t *)&gszNullString);
                ppv = _wcsdup((const wchar_t *)&gszNullString);
                ppv1 = _wcsdup((const wchar_t *)&gszNullString);
                v36 = &gszNullString;
                v37 = &gszNullString;
                if ( v30 )
                  v37 = v30;
                v62 = _wcsdup((const wchar_t *)v37);
                v38 = &gszNullString;
                if ( *(_DWORD *)v46 )
                  v38 = *(const WCHAR ***)v46;
                v59 = _wcsdup((const wchar_t *)v38);
                LOBYTE(v68) = 36;
                v39 = MakeRegistryKeyName((CCmdString *)szArg, hRootKey, (CCmdString *)&v62, (CCmdString *)&ppv1);
                LOBYTE(v68) = 37;
                a4 = (void *)PE_UpdateSystemKey(
                               v48,
                               0,
                               (HANDLE)0xFFFFFFFF,
                               0,
                               (CCmdString *)&v59,
                               v39,
                               (CCmdString *)&ppv);
                free(*(void **)szArg);
                free((void *)v59);
                free((void *)v62);
                free(ppv1);
                free(ppv);
                free((void *)szKeyName);
                free(v56.m_String);
                free(ppv3);
                free(a1a);
                free((void *)v63.unused);
              }
              else
              {
                v36 = &gszNullString;
              }
              v59 = _wcsdup((const wchar_t *)&gszNullString);
              v56.m_String = _wcsdup(v67);
              ppv3 = _wcsdup((const wchar_t *)&gszNullString);
              v40 = &gszNullString;
              if ( v30 )
                v40 = v30;
              a1a = _wcsdup((const wchar_t *)v40);
              if ( v30 )
                v36 = v30;
              v63.unused = (int)_wcsdup((const wchar_t *)v36);
              LOBYTE(v68) = 42;
              v41 = MakeRegistryKeyName((CCmdString *)v46, hRootKey, (CCmdString *)&a1a, (CCmdString *)&ppv3);
              LOBYTE(v68) = 43;
              PE_UpdateSystemKey(v48, cbData[5], a4, 3u, (CCmdString *)&v63, v41, &str3);
              free(*(void **)v46);
              free((void *)v63.unused);
              free(a1a);
              free(ppv3);
              free(v56.m_String);
              free((void *)v59);
            }
            free(str3.m_String);
            StringItem::~StringItem((tagPEStringStruct *)cbData);
            free(pszText);
            free((void *)v52);
            free((void *)szArg4);
          }
        }
        RegCloseKey(KeyHandle);
      }
    }
    RegCloseKey(hKey);
  }
  free((void *)szArg3);
  free(v12);
  return a4;
}
// CA244C: using guessed type wchar_t a1_0[8];

//----- (00BF6A10) --------------------------------------------------------
void *__cdecl sub_BF6A10(int a1, void *a2, wchar_t *psz, LPCWSTR lpValueName, wchar_t *a5, int a6, void *a7)
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
  CCmdString *v18; // esi
  CCmdString *v19; // eax
  char v20; // bl
  const wchar_t *v21; // eax
  const wchar_t *v22; // eax
  const wchar_t *v23; // eax
  const wchar_t *v24; // eax
  CCmdString *v25; // eax
  void *v27; // [esp+10h] [ebp-78h]
  int v28; // [esp+14h] [ebp-74h]
  int v29; // [esp+18h] [ebp-70h]
  WCHAR v30[2]; // [esp+1Ch] [ebp-6Ch]
  int a2a; // [esp+20h] [ebp-68h]
  int a8; // [esp+24h] [ebp-64h]
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
  CCmdString v48; // [esp+64h] [ebp-24h]
  CCmdString ppv; // [esp+68h] [ebp-20h]
  void *v50; // [esp+6Ch] [ebp-1Ch]
  void *v51; // [esp+70h] [ebp-18h]
  CCmdString str3; // [esp+74h] [ebp-14h]
  int v53; // [esp+84h] [ebp-4h]

  str3.m_String = (WCHAR *)malloc(2u);
  *str3.m_String = 0;
  v53 = 0;
  v50 = malloc(2u);
  *(_WORD *)v50 = 0;
  v47 = malloc(2u);
  *(_WORD *)v47 = 0;
  v48.m_String = (WCHAR *)malloc(2u);
  *v48.m_String = 0;
  v51 = malloc(2u);
  *(_WORD *)v51 = 0;
  LOBYTE(v53) = 4;
  v7 = (unsigned int)TlsGetValue(gdwTlsIndex);
  if ( !PE_OpenKey((HKEY)a2, psz, 0, v7 | 0x20019, &hKey) )
  {
    ppv.m_String = (WCHAR *)malloc(2u);
    *ppv.m_String = 0;
    LOBYTE(v53) = 5;
    if ( !PE_ReadRegKey(hKey, lpValueName, 0, 0, &ppv) && wcslen(ppv.m_String) )
    {
      v27 = 0;
      v28 = 0;
      v29 = 0;
      LOBYTE(v53) = 6;
      sub_BE6DD0(ppv.m_String, 44, (int)&v27, 0);
      v8 = v28;
      v9 = (char *)v27;
      v38 = 0;
      if ( (v28 - (signed int)v27) >> 4 )
      {
        v10 = 0;
        v37 = 0;
        do
        {
          v11 = (int)&v9[v10];
          v12 = v51;
          v51 = _wcsdup(**(const wchar_t ***)&v9[v10 + 4]);
          free(v12);
          v13 = (const wchar_t **)sub_BE4EE0((int)&v35, a1, v11, 0);
          v14 = str3.m_String;
          str3.m_String = _wcsdup(*v13);
          free(v14);
          free(v35);
          a2a = sub_BE4ED0();
          v15 = (const wchar_t *)&gszNullString;
          if ( lpValueName )
            v15 = lpValueName;
          szArg4 = _wcsdup(v15);
          v16 = (const wchar_t *)&gszNullString;
          if ( psz )
            v16 = psz;
          pszText = _wcsdup(v16);
          v45 = _wcsdup((const wchar_t *)&gszNullString);
          v17 = (const wchar_t *)&gszNullString;
          if ( psz )
            v17 = psz;
          szArg3 = _wcsdup(v17);
          LOBYTE(v53) = 10;
          v18 = MakeRegistryKeyName((CCmdString *)&a1a, (HKEY)a2, (CCmdString *)&pszText, (CCmdString *)&szArg4);
          LOBYTE(v53) = 11;
          v19 = MakeRegistryKeyName((CCmdString *)szArg, (HKEY)a2, (CCmdString *)&szArg3, (CCmdString *)&v45);
          LOBYTE(v53) = 12;
          v20 = sub_BE3D40(a1, (CCmdString)v19, (int)v18, v11, (int)&str3, (int)&v50, (CCmdString)&v48, (int)&a8);
          free(*(void **)szArg);
          free(a1a);
          free((void *)szArg3);
          free((void *)v45);
          free(pszText);
          LOBYTE(v53) = 6;
          free((void *)szArg4);
          if ( v20 )
          {
            v21 = (const wchar_t *)&gszNullString;
            if ( lpValueName )
              v21 = lpValueName;
            v39 = _wcsdup(v21);
            v22 = (const wchar_t *)&gszNullString;
            if ( lpValueName )
              v22 = lpValueName;
            v40 = _wcsdup(v22);
            v23 = (const wchar_t *)&gszNullString;
            if ( psz )
              v23 = psz;
            szKeyName = _wcsdup(v23);
            v24 = (const wchar_t *)&gszNullString;
            if ( a5 )
              v24 = a5;
            ppv3 = _wcsdup(v24);
            LOBYTE(v53) = 16;
            v25 = MakeRegistryKeyName((CCmdString *)v30, (HKEY)a2, (CCmdString *)&szKeyName, (CCmdString *)&v40);
            LOBYTE(v53) = 17;
            PE_UpdateSystemKey(a1, a2a, a7, 1u, (CCmdString *)&ppv3, v25, &str3);
            free(*(void **)v30);
            free(ppv3);
            free((void *)szKeyName);
            free((void *)v40);
            LOBYTE(v53) = 6;
            free(v39);
          }
          v8 = v28;
          v9 = (char *)v27;
          v10 = v37 + 16;
          ++v38;
          v37 += 16;
        }
        while ( v38 < (v28 - (signed int)v27) >> 4 );
      }
      if ( v9 )
      {
        sub_BE2BF0((int)v9, v8);
        operator delete(v27);
      }
    }
    RegCloseKey(hKey);
    free(ppv.m_String);
  }
  free(v51);
  free(v48.m_String);
  free(v47);
  free(v50);
  free(str3.m_String);
  return a7;
}

//----- (00BF6E10) --------------------------------------------------------
void *__cdecl sub_BF6E10(int a1, void *a2, OLECHAR *psz, LPCWSTR lpValueName)
{
  _bstr_t *v4; // eax
  _bstr_t *v5; // eax
  Data_t_bstr_t *v6; // esi
  Data_t_bstr_t *v7; // esi
  Data_t_bstr_t *v8; // esi
  void *v9; // eax
  wchar_t *v10; // ecx
  void *v11; // eax
  Data_t_bstr_t *v12; // esi
  void *v13; // edi
  _bstr_t bstrRet; // [esp+10h] [ebp-1Ch]
  _bstr_t a3; // [esp+14h] [ebp-18h]
  _bstr_t v17; // [esp+18h] [ebp-14h]
  _bstr_t a1a; // [esp+1Ch] [ebp-10h]
  int v19; // [esp+28h] [ebp-4h]

  _bstr_t::_bstr_t((tagEventSetItem *)&a3, L"AutorunsDisabled");
  v19 = 0;
  v4 = (_bstr_t *)_bstr_t::_bstr_t((tagEventSetItem *)&v17, L"\\");
  LOBYTE(v19) = 1;
  v5 = _bstr_t::operator+(&a1a, psz, v4);
  LOBYTE(v19) = 2;
  _bstr_t::operator+(v5, &bstrRet, &a3);
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
        operator delete[](v6->m_str);
        v6->m_str = 0;
      }
      operator delete(v6);
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
        operator delete[](v7->m_str);
        v7->m_str = 0;
      }
      operator delete(v7);
    }
    v17.m_Data = 0;
  }
  v8 = a3.m_Data;
  LOBYTE(v19) = 6;
  if ( a3.m_Data && !InterlockedDecrement(&a3.m_Data->m_RefCount) )
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
  v9 = sub_BF7000(a1, a2, psz, lpValueName, -1);
  if ( bstrRet.m_Data )
    v10 = bstrRet.m_Data->m_wstr;
  else
    v10 = 0;
  v11 = sub_BF7000(a1, a2, v10, lpValueName, (int)v9);
  v12 = bstrRet.m_Data;
  v13 = v11;
  if ( bstrRet.m_Data && !InterlockedDecrement(&bstrRet.m_Data->m_RefCount) && v12 )
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
  return v13;
}

//----- (00BF7000) --------------------------------------------------------
void *__cdecl sub_BF7000(int a1, void *a2, wchar_t *psz, LPCWSTR lpValueName, int a5)
{
  void *v5; // ebx
  const wchar_t *v6; // eax
  const wchar_t *v7; // eax
  const wchar_t *v8; // eax
  const wchar_t *v9; // eax
  CCmdString *v10; // esi
  CCmdString *v11; // eax
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
  CCmdString *v23; // edi
  CCmdString *v24; // eax
  int v25; // ST40_4
  char v26; // bl
  const wchar_t *v27; // eax
  const wchar_t *v28; // eax
  const wchar_t *v29; // eax
  const wchar_t *v30; // eax
  CCmdString *v31; // edi
  CCmdString *v32; // eax
  const WCHAR **v33; // eax
  const wchar_t *v34; // eax
  CCmdString *v35; // eax
  int a2a; // [esp+10h] [ebp-A4h]
  int v37; // [esp+14h] [ebp-A0h]
  int v38; // [esp+18h] [ebp-9Ch]
  int v39; // [esp+1Ch] [ebp-98h]
  WCHAR v40[2]; // [esp+20h] [ebp-94h]
  WCHAR v41[2]; // [esp+24h] [ebp-90h]
  WCHAR v42[2]; // [esp+28h] [ebp-8Ch]
  DWORD dwValue; // [esp+2Ch] [ebp-88h]
  WCHAR v44[2]; // [esp+30h] [ebp-84h]
  int a8; // [esp+34h] [ebp-80h]
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
  CCmdString str3; // [esp+60h] [ebp-54h]
  LPCWSTR v57; // [esp+64h] [ebp-50h]
  void *v58; // [esp+68h] [ebp-4Ch]
  void *a1a; // [esp+6Ch] [ebp-48h]
  HKEY hKey; // [esp+70h] [ebp-44h]
  WCHAR szArg[2]; // [esp+74h] [ebp-40h]
  LPCWSTR szKeyName; // [esp+78h] [ebp-3Ch]
  CCmdString v63; // [esp+7Ch] [ebp-38h]
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

  v5 = (void *)a5;
  ppv1 = (void *)a5;
  if ( dword_CD31D8 && a5 == -1 )
  {
    v63.m_String = _wcsdup((const wchar_t *)&gszNullString);
    v74 = 0;
    v65 = _wcsdup((const wchar_t *)&gszNullString);
    v66 = _wcsdup((const wchar_t *)&gszNullString);
    szKeyName = _wcsdup((const wchar_t *)&gszNullString);
    v64 = _wcsdup((const wchar_t *)&gszNullString);
    v67 = _wcsdup((const wchar_t *)&gszNullString);
    v6 = (const wchar_t *)&gszNullString;
    if ( lpValueName )
      v6 = lpValueName;
    szArg4 = _wcsdup(v6);
    v7 = (const wchar_t *)&gszNullString;
    if ( psz )
      v7 = psz;
    pszText = _wcsdup(v7);
    v8 = (const wchar_t *)&gszNullString;
    if ( lpValueName )
      v8 = lpValueName;
    v70 = _wcsdup(v8);
    v9 = (const wchar_t *)&gszNullString;
    if ( psz )
      v9 = psz;
    szArg3 = _wcsdup(v9);
    LOBYTE(v74) = 9;
    v10 = MakeRegistryKeyName((CCmdString *)&a1a, (HKEY)a2, (CCmdString *)&pszText, (CCmdString *)&szArg4);
    LOBYTE(v74) = 10;
    v11 = MakeRegistryKeyName((CCmdString *)szArg, (HKEY)a2, (CCmdString *)&szArg3, (CCmdString *)&v70);
    LOBYTE(v74) = 11;
    v5 = (void *)PE_UpdateSystemKey(a1, 0, (HANDLE)0xFFFFFFFF, 0, v11, v10, (CCmdString *)&v67);
    ppv1 = v5;
    free(*(void **)szArg);
    free(a1a);
    free((void *)szArg3);
    free((void *)v70);
    free(pszText);
    free((void *)szArg4);
    free((void *)v67);
    free((void *)v64);
    free((void *)szKeyName);
    free((void *)v66);
    free((void *)v65);
    v74 = -1;
    free(v63.m_String);
  }
  hKey = 0;
  PE_OpenKey((HKEY)a2, psz, 0, 0x20019u, &hKey);
  if ( !hKey )
    return v5;
  v13 = lpValueName;
  cbData = 0;
  RegQueryValueExW(hKey, lpValueName, 0, 0, 0, &cbData);
  v14 = (wchar_t *)operator new[](2 * ((cbData >> 1) + 2));
  RegQueryValueExW(hKey, lpValueName, 0, 0, (LPBYTE)v14, &cbData);
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
        a2a = (int)v17;
        *v17 = 0;
        v37 = 0;
        v38 = 0;
        v39 = 0;
        v74 = 12;
        sub_BE6CC0(v14, (StringItem *)&a2a);
        *(_DWORD *)szArg = _wcsdup(v14);
        LOBYTE(v74) = 13;
        sub_BE4EE0((int)&szArg4, v16, (int)&a2a, 0);
        v18 = (WCHAR *)szArg4;
        if ( *szArg4 )
        {
          pszText = (WCHAR *)malloc(2u);
          *pszText = 0;
          szArg3 = (LPCWSTR)malloc(2u);
          *szArg3 = 0;
          v70 = (LPCWSTR)malloc(2u);
          *v70 = 0;
          LOBYTE(v74) = 17;
          dwValue = sub_BE4ED0();
          v19 = &gszNullString;
          if ( v13 )
            v19 = (const WCHAR **)v13;
          v64 = _wcsdup((const wchar_t *)v19);
          v20 = (const wchar_t *)&gszNullString;
          if ( psz )
            v20 = psz;
          szKeyName = _wcsdup(v20);
          v21 = &gszNullString;
          if ( v13 )
            v21 = (const WCHAR **)v13;
          v66 = _wcsdup((const wchar_t *)v21);
          v22 = (const wchar_t *)&gszNullString;
          if ( psz )
            v22 = psz;
          v65 = _wcsdup(v22);
          v63.m_String = _wcsdup(v14);
          LOBYTE(v74) = 22;
          v23 = MakeRegistryKeyName((CCmdString *)v44, (HKEY)a2, (CCmdString *)&szKeyName, (CCmdString *)&v64);
          LOBYTE(v74) = 23;
          v24 = MakeRegistryKeyName((CCmdString *)v46, (HKEY)a2, (CCmdString *)&v65, (CCmdString *)&v66);
          LOBYTE(v74) = 24;
          v25 = (int)v23;
          v16 = a1;
          v26 = sub_BE3D40(a1, (CCmdString)&v63, (int)v24, v25, (int)&szArg4, (int)&pszText, (CCmdString)&v70, (int)&a8);
          free(*(void **)v46);
          free(*(void **)v44);
          free(v63.m_String);
          free((void *)v65);
          free((void *)v66);
          free((void *)szKeyName);
          free((void *)v64);
          if ( v26 )
          {
            if ( ppv1 == (void *)-1 )
            {
              v48 = _wcsdup((const wchar_t *)&gszNullString);
              v52 = _wcsdup((const wchar_t *)&gszNullString);
              v47 = _wcsdup((const wchar_t *)&gszNullString);
              v54 = _wcsdup((const wchar_t *)&gszNullString);
              v58 = _wcsdup((const wchar_t *)&gszNullString);
              str3.m_String = _wcsdup((const wchar_t *)&gszNullString);
              v13 = lpValueName;
              v27 = (const wchar_t *)&gszNullString;
              if ( lpValueName )
                v27 = lpValueName;
              v55 = _wcsdup(v27);
              v28 = (const wchar_t *)&gszNullString;
              if ( psz )
                v28 = psz;
              v57 = _wcsdup(v28);
              v29 = (const wchar_t *)&gszNullString;
              if ( lpValueName )
                v29 = lpValueName;
              v49 = _wcsdup(v29);
              v30 = (const wchar_t *)&gszNullString;
              if ( psz )
                v30 = psz;
              v67 = _wcsdup(v30);
              LOBYTE(v74) = 34;
              v31 = MakeRegistryKeyName((CCmdString *)v42, (HKEY)a2, (CCmdString *)&v57, (CCmdString *)&v55);
              LOBYTE(v74) = 35;
              v32 = MakeRegistryKeyName((CCmdString *)v40, (HKEY)a2, (CCmdString *)&v67, (CCmdString *)&v49);
              LOBYTE(v74) = 36;
              ppv1 = (void *)PE_UpdateSystemKey(a1, 0, (HANDLE)0xFFFFFFFF, 0, v32, v31, &str3);
              free(*(void **)v40);
              free(*(void **)v42);
              free((void *)v67);
              free((void *)v49);
              free((void *)v57);
              free((void *)v55);
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
            a1a = _wcsdup((const wchar_t *)&gszNullString);
            v33 = &gszNullString;
            if ( v13 )
              v33 = (const WCHAR **)v13;
            v51 = _wcsdup((const wchar_t *)v33);
            v34 = (const wchar_t *)&gszNullString;
            if ( psz )
              v34 = psz;
            v53 = _wcsdup(v34);
            ppv3 = _wcsdup(v14);
            LOBYTE(v74) = 40;
            v35 = MakeRegistryKeyName((CCmdString *)v41, (HKEY)a2, (CCmdString *)&v53, (CCmdString *)&v51);
            v16 = a1;
            LOBYTE(v74) = 41;
            PE_UpdateSystemKey(a1, dwValue, ppv1, 5u, (CCmdString *)&ppv3, v35, (CCmdString *)&szArg4);
            free(*(void **)v41);
            free(ppv3);
            free((void *)v53);
            free((void *)v51);
            free(a1a);
          }
          else
          {
            v13 = lpValueName;
          }
          free((void *)v70);
          free((void *)szArg3);
          free(pszText);
          v18 = (WCHAR *)szArg4;
        }
        free(v18);
        free(*(void **)szArg);
        v74 = -1;
        StringItem::~StringItem((tagPEStringStruct *)&a2a);
        v14 = wcschr(v14 + 1, 0) + 1;
      }
      while ( *v14 );
    }
  }
  RegCloseKey(hKey);
  return ppv1;
}
// CD31D8: using guessed type int dword_CD31D8;

//----- (00BF7710) --------------------------------------------------------
void __cdecl sub_BF7710(int a1, void *a2, void *a3)
{
  _WORD *v3; // ST50_4
  CCmdString *v4; // esi
  void *v5; // edi
  CCmdString *v6; // eax
  wchar_t *v7; // ST54_4

  v3 = malloc(2u);
  *v3 = 0;
  v4 = (CCmdString *)a3;
  v5 = sub_BF77C0(a1, a2, *(wchar_t **)a3, (void *)0xFFFFFFFF);
  v6 = CCmdString::operator+((CCmdString *)&a3, v4, L"\\AutorunsDisabled");
  v7 = _wcsdup(v6->m_String);
  free(v3);
  free(a3);
  sub_BF77C0(a1, a2, v7, v5);
  free(v7);
}

//----- (00BF77C0) --------------------------------------------------------
void *__cdecl sub_BF77C0(int a1, void *a2, wchar_t *psz, void *a4)
{
  WCHAR *v4; // edi
  WCHAR *v5; // ebx
  wchar_t *v6; // esi
  const wchar_t *v7; // eax
  const wchar_t *v8; // eax
  CCmdString *v9; // esi
  CCmdString *v10; // eax
  CCmdString *v11; // ebx
  WCHAR *v12; // eax
  WCHAR *v13; // edx
  WCHAR v14; // cx
  WCHAR *v15; // esi
  CCmdString *v16; // eax
  WCHAR *v17; // esi
  CCmdString *v18; // eax
  WCHAR *v19; // eax
  const wchar_t **v20; // eax
  WCHAR *v21; // esi
  const wchar_t *v22; // eax
  const wchar_t *v23; // eax
  CCmdString *v24; // esi
  CCmdString *v25; // eax
  const wchar_t *v26; // eax
  const wchar_t *v27; // eax
  CCmdString *v28; // esi
  CCmdString *v29; // eax
  const wchar_t *v30; // eax
  CCmdString *v31; // eax
  WCHAR v32; // cx
  CCmdString strResult[7]; // [esp+10h] [ebp-BCh]
  WCHAR v35[2]; // [esp+2Ch] [ebp-A0h]
  WCHAR v36[2]; // [esp+30h] [ebp-9Ch]
  int a8; // [esp+34h] [ebp-98h]
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
  CCmdString v50; // [esp+68h] [ebp-64h]
  HKEY hKey; // [esp+6Ch] [ebp-60h]
  void *a1a; // [esp+70h] [ebp-5Ch]
  WCHAR szArg[2]; // [esp+74h] [ebp-58h]
  void *v54; // [esp+78h] [ebp-54h]
  CCmdString v55; // [esp+7Ch] [ebp-50h]
  WCHAR *ppv2; // [esp+80h] [ebp-4Ch]
  CCmdString v57; // [esp+84h] [ebp-48h]
  CCmdString v58; // [esp+88h] [ebp-44h]
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
  CCmdString str3; // [esp+B8h] [ebp-14h]
  char v71; // [esp+BFh] [ebp-Dh]
  int v72; // [esp+C8h] [ebp-4h]

  v58.m_String = (WCHAR *)malloc(2u);
  *v58.m_String = 0;
  v72 = 0;
  v4 = (WCHAR *)malloc(2u);
  ppv2 = v4;
  *v4 = 0;
  v57.m_String = (WCHAR *)malloc(2u);
  *v57.m_String = 0;
  v5 = (WCHAR *)malloc(2u);
  strResult[5].m_String = v5;
  *v5 = 0;
  str3.m_String = (WCHAR *)malloc(2u);
  *str3.m_String = 0;
  v54 = malloc(2u);
  *(_WORD *)v54 = 0;
  v55.m_String = (WCHAR *)malloc(2u);
  *v55.m_String = 0;
  v50.m_String = (WCHAR *)malloc(2u);
  *v50.m_String = 0;
  v6 = psz;
  LOBYTE(v72) = 7;
  if ( a4 == (void *)-1 )
  {
    v64 = _wcsdup((const wchar_t *)&gszNullString);
    v59 = _wcsdup((const wchar_t *)&gszNullString);
    szKeyName = _wcsdup((const wchar_t *)&gszNullString);
    v63 = _wcsdup((const wchar_t *)&gszNullString);
    v66 = _wcsdup((const wchar_t *)&gszNullString);
    v67 = _wcsdup((const wchar_t *)&gszNullString);
    szArg4 = _wcsdup((const wchar_t *)&gszNullString);
    v7 = (const wchar_t *)&gszNullString;
    if ( psz )
      v7 = psz;
    pszText = _wcsdup(v7);
    v60 = _wcsdup((const wchar_t *)&gszNullString);
    v8 = (const wchar_t *)&gszNullString;
    if ( psz )
      v8 = psz;
    szArg3 = _wcsdup(v8);
    LOBYTE(v72) = 17;
    v9 = MakeRegistryKeyName((CCmdString *)&a1a, (HKEY)a2, (CCmdString *)&pszText, (CCmdString *)&szArg4);
    LOBYTE(v72) = 18;
    v10 = MakeRegistryKeyName((CCmdString *)szArg, (HKEY)a2, (CCmdString *)&szArg3, (CCmdString *)&v60);
    LOBYTE(v72) = 19;
    a4 = (void *)PE_UpdateSystemKey(a1, 0, (HANDLE)0xFFFFFFFF, 0, v10, v9, (CCmdString *)&v67);
    free(*(void **)szArg);
    free(a1a);
    free((void *)szArg3);
    free((void *)v60);
    free(pszText);
    free((void *)szArg4);
    free((void *)v67);
    free((void *)v66);
    free((void *)v63);
    free((void *)szKeyName);
    free((void *)v59);
    LOBYTE(v72) = 7;
    free((void *)v64);
    v6 = psz;
  }
  if ( !PE_OpenKey(ghLocalMachineKey, v6, 0, 1u, &KeyHandle) )
  {
    if ( !PE_ReadRegKey(KeyHandle, L"ProviderOrder", 0, 0, &v58) )
    {
      v11 = (CCmdString *)operator new(4u);
      if ( v11 )
        v11->m_String = _wcsdup(v58.m_String);
      else
        v11 = 0;
      v12 = v58.m_String;
      szArg3 = v58.m_String;
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
        v16 = CCmdString::Append(&strResult[4], (CCmdString *)&ppv2, v11);
        ppv3 = v4;
        v4 = _wcsdup(v16->m_String);
        ppv2 = v4;
        free(ppv3);
        free(strResult[4].m_String);
        free(v15);
        v17 = _wcsdup(L"\\NetworkProvider");
        ppv3 = v17;
        v18 = CCmdString::Append((CCmdString *)&ppv, (CCmdString *)&ppv2, (CCmdString *)&ppv3);
        LOBYTE(v72) = 21;
        v71 = PE_OpenKey((HKEY)a2, v18->m_String, 0, 1u, &hKey) == 0;
        free(ppv);
        LOBYTE(v72) = 7;
        free(v17);
        if ( v71 )
        {
          if ( !PE_ReadRegKey(hKey, L"ProviderPath", 0, 0, &v57) )
          {
            v19 = (WCHAR *)malloc(2u);
            strResult[0].m_String = v19;
            *v19 = 0;
            strResult[1].m_String = 0;
            strResult[2].m_String = 0;
            strResult[3].m_String = 0;
            LOBYTE(v72) = 22;
            sub_BE7040(v57.m_String, (StringItem *)strResult);
            *(_DWORD *)szArg = _wcsdup(v57.m_String);
            LOBYTE(v72) = 23;
            v20 = (const wchar_t **)sub_BE4EE0((int)&v38, a1, (int)strResult, 0);
            v21 = str3.m_String;
            str3.m_String = _wcsdup(*v20);
            free(v21);
            free(v38);
            ppv3 = (WCHAR *)sub_BE4ED0();
            PE_ReadRegKey(hKey, L"Name", 0, 0, &v55);
            v63 = _wcsdup(L"ProviderOrder");
            v22 = (const wchar_t *)&gszNullString;
            if ( psz )
              v22 = psz;
            szKeyName = _wcsdup(v22);
            v59 = _wcsdup((const wchar_t *)&gszNullString);
            v23 = (const wchar_t *)&gszNullString;
            if ( psz )
              v23 = psz;
            v64 = _wcsdup(v23);
            LOBYTE(v72) = 27;
            v24 = MakeRegistryKeyName((CCmdString *)v36, (HKEY)a2, (CCmdString *)&szKeyName, (CCmdString *)&v63);
            LOBYTE(v72) = 28;
            v25 = MakeRegistryKeyName(&strResult[6], (HKEY)a2, (CCmdString *)&v64, (CCmdString *)&v59);
            LOBYTE(v72) = 29;
            v71 = sub_BE3D40(a1, (CCmdString)v11, (int)v25, (int)v24, (int)&str3, (int)&v54, (CCmdString)&v50, (int)&a8);
            free(strResult[6].m_String);
            free(*(void **)v36);
            free((void *)v64);
            free((void *)v59);
            free((void *)szKeyName);
            free((void *)v63);
            if ( v71 )
            {
              if ( a4 == (void *)-1 )
              {
                v47 = _wcsdup((const wchar_t *)&gszNullString);
                v42 = _wcsdup((const wchar_t *)&gszNullString);
                v46 = _wcsdup((const wchar_t *)&gszNullString);
                v49 = _wcsdup((const wchar_t *)&gszNullString);
                v48 = _wcsdup((const wchar_t *)&gszNullString);
                v60 = _wcsdup((const wchar_t *)&gszNullString);
                pszText = _wcsdup((const wchar_t *)&gszNullString);
                v26 = (const wchar_t *)&gszNullString;
                if ( psz )
                  v26 = psz;
                szArg4 = _wcsdup(v26);
                v67 = _wcsdup((const wchar_t *)&gszNullString);
                v27 = (const wchar_t *)&gszNullString;
                if ( psz )
                  v27 = psz;
                v66 = _wcsdup(v27);
                LOBYTE(v72) = 39;
                v28 = MakeRegistryKeyName((CCmdString *)v39, (HKEY)a2, (CCmdString *)&szArg4, (CCmdString *)&pszText);
                LOBYTE(v72) = 40;
                v29 = MakeRegistryKeyName((CCmdString *)v40, (HKEY)a2, (CCmdString *)&v66, (CCmdString *)&v67);
                LOBYTE(v72) = 41;
                a4 = (void *)PE_UpdateSystemKey(a1, 0, (HANDLE)0xFFFFFFFF, 0, v29, v28, (CCmdString *)&v60);
                free(*(void **)v40);
                free(*(void **)v39);
                free((void *)v66);
                free((void *)v67);
                free((void *)szArg4);
                free(pszText);
                free((void *)v60);
                free(v48);
                free(v49);
                free(v46);
                free(v42);
                free(v47);
              }
              a1a = _wcsdup((const wchar_t *)&gszNullString);
              v45 = _wcsdup(L"ProviderOrder");
              v30 = (const wchar_t *)&gszNullString;
              if ( psz )
                v30 = psz;
              v43 = _wcsdup(v30);
              LOBYTE(v72) = 44;
              v31 = MakeRegistryKeyName((CCmdString *)v35, (HKEY)a2, (CCmdString *)&v43, (CCmdString *)&v45);
              LOBYTE(v72) = 45;
              PE_UpdateSystemKey(a1, (DWORD)ppv3, a4, 5u, v11, v31, &str3);
              free(*(void **)v35);
              free((void *)v43);
              free((void *)v45);
              free(a1a);
            }
            free(*(void **)szArg);
            LOBYTE(v72) = 7;
            StringItem::~StringItem((tagPEStringStruct *)strResult);
          }
          RegCloseKey(hKey);
        }
        v12 = (WCHAR *)szArg3;
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
      v5 = strResult[5].m_String;
    }
    RegCloseKey(KeyHandle);
  }
  free(v50.m_String);
  free(v55.m_String);
  free(v54);
  free(str3.m_String);
  free(v5);
  free(v57.m_String);
  free(v4);
  free(v58.m_String);
  return a4;
}

//----- (00BF7FE0) --------------------------------------------------------
void __cdecl PE_RefreshRegistry(unsigned int dwValue, HKEY__ *hKey, CCmdString *strKeyName)
{
  WCHAR *v3; // ST20_4

  v3 = (WCHAR *)malloc(2u);
  *v3 = 0;
  sub_BF8050(dwValue, hKey, strKeyName->m_String, (HANDLE)0xFFFFFFFF);
  free(v3);
}

//----- (00BF8050) --------------------------------------------------------
void *__cdecl sub_BF8050(int a1, HKEY hKey, LPCWSTR lpszKeyName, HANDLE Handle)
{
  const wchar_t *v4; // eax
  const wchar_t *v5; // eax
  CCmdString *v6; // esi
  CCmdString *v7; // eax
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
  CCmdString *v18; // eax
  CCmdString *v19; // eax
  wchar_t *v20; // esi
  CCmdString *v21; // eax
  void *v22; // esi
  wchar_t *v23; // esi
  unsigned int v24; // eax
  const wchar_t **v25; // eax
  WCHAR *v26; // esi
  WCHAR *v27; // esi
  CCmdString *v28; // eax
  wchar_t *v29; // edi
  WCHAR *v30; // esi
  wchar_t *v31; // esi
  unsigned int v32; // eax
  WCHAR *v33; // esi
  const wchar_t *v34; // eax
  const wchar_t *v35; // eax
  CCmdString *v36; // esi
  CCmdString *v37; // eax
  char v38; // bl
  LPCWSTR v39; // ebx
  const wchar_t *v40; // eax
  const wchar_t *v41; // eax
  CCmdString *v42; // esi
  CCmdString *v43; // eax
  const WCHAR **v44; // eax
  CCmdString *v45; // eax
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
  int a8; // [esp+30h] [ebp-ACh]
  CCmdString str; // [esp+34h] [ebp-A8h]
  WCHAR v60[2]; // [esp+38h] [ebp-A4h]
  CCmdString v61; // [esp+3Ch] [ebp-A0h]
  WCHAR v62[2]; // [esp+40h] [ebp-9Ch]
  void *v63; // [esp+44h] [ebp-98h]
  WCHAR *ppv2; // [esp+48h] [ebp-94h]
  void *v65; // [esp+4Ch] [ebp-90h]
  BYTE Data[4]; // [esp+50h] [ebp-8Ch]
  void *v67; // [esp+54h] [ebp-88h]
  CCmdString str3; // [esp+58h] [ebp-84h]
  void *v69; // [esp+5Ch] [ebp-80h]
  LPCWSTR v70; // [esp+60h] [ebp-7Ch]
  void *v71; // [esp+64h] [ebp-78h]
  LPCWSTR v72; // [esp+68h] [ebp-74h]
  void *v73; // [esp+6Ch] [ebp-70h]
  void *v74; // [esp+70h] [ebp-6Ch]
  CCmdString v75; // [esp+74h] [ebp-68h]
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

  ppv3 = (WCHAR *)malloc(2u);
  *ppv3 = 0;
  v92 = 0;
  v81 = malloc(2u);
  *(_WORD *)v81 = 0;
  v74 = malloc(2u);
  *(_WORD *)v74 = 0;
  v75.m_String = (WCHAR *)malloc(2u);
  *v75.m_String = 0;
  v80 = malloc(2u);
  *(_WORD *)v80 = 0;
  v77 = (LPCWSTR)malloc(2u);
  *v77 = 0;
  LOBYTE(v92) = 5;
  *(_DWORD *)Data = 0;
  if ( Handle == (HANDLE)-1 )
  {
    v82.strValue[5] = (int)_wcsdup((const wchar_t *)&gszNullString);
    v82.strValue[4] = (int)_wcsdup((const wchar_t *)&gszNullString);
    v82.strValue[6] = (int)_wcsdup((const wchar_t *)&gszNullString);
    v84 = _wcsdup((const wchar_t *)&gszNullString);
    v85 = _wcsdup((const wchar_t *)&gszNullString);
    v83 = _wcsdup((const wchar_t *)&gszNullString);
    v91.unused = (int)_wcsdup((const wchar_t *)&gszNullString);
    v4 = (const wchar_t *)&gszNullString;
    if ( lpszKeyName )
      v4 = lpszKeyName;
    pszText = _wcsdup(v4);
    hKeya = (HKEY)_wcsdup((const wchar_t *)&gszNullString);
    v5 = (const wchar_t *)&gszNullString;
    if ( lpszKeyName )
      v5 = lpszKeyName;
    szArg3 = _wcsdup(v5);
    LOBYTE(v92) = 15;
    v6 = MakeRegistryKeyName((CCmdString *)&a1a, hKey, (CCmdString *)&pszText, (CCmdString *)&v91);
    LOBYTE(v92) = 16;
    v7 = MakeRegistryKeyName((CCmdString *)&szArg, hKey, (CCmdString *)&szArg3, (CCmdString *)&hKeya);
    LOBYTE(v92) = 17;
    Handle = (HANDLE)PE_UpdateSystemKey(a1, 0, (HANDLE)0xFFFFFFFF, 0, v7, v6, (CCmdString *)&v83);
    free(szArg);
    free(a1a);
    free((void *)szArg3);
    free(hKeya);
    free(pszText);
    free((void *)v91.unused);
    free((void *)v83);
    free((void *)v85);
    free((void *)v84);
    free((void *)v82.strValue[6]);
    free((void *)v82.strValue[4]);
    LOBYTE(v92) = 5;
    free((void *)v82.strValue[5]);
  }
  TlsGetValue = ::TlsGetValue;
  DesiredAccess = (unsigned int)::TlsGetValue(gdwTlsIndex) | KEY_READ;
  if ( !PE_OpenKey(hKey, lpszKeyName, 0, DesiredAccess, &KeyHandle) )
  {
    szArg = 0;
    pszText = (wchar_t *)malloc(2u);
    *pszText = 0;
    v91.unused = (int)malloc(2u);
    *(_WORD *)v91.unused = 0;
    szArg3 = (LPCWSTR)malloc(2u);
    *szArg3 = 0;
    v82.strValue[0] = (int)malloc(2u);
    *(_WORD *)v82.strValue[0] = 0;
    v82.strValue[1] = 0;
    v82.strValue[2] = 0;
    v82.strValue[3] = 0;
    LOBYTE(v92) = 21;
    v10 = (void (__stdcall *)(HKEY))RegCloseKey;
    if ( !PE_LoadRegKeys(KeyHandle, 0, (CCmdString *)&v91) )
    {
      while ( 1 )
      {
        v11 = (WCHAR *)v77;
        v77 = _wcsdup((const wchar_t *)v91.unused);
        free(v11);
        v12 = (const WCHAR *)v91.unused;
        v13 = (unsigned int)TlsGetValue(gdwTlsIndex);
        if ( !PE_OpenKey(KeyHandle, v12, 0, v13 | KEY_READ, &hKeya) )
        {
          RegQueryValueExW(hKeya, L"LoadBehavior", 0, 0, Data, &cbData);
          v10(hKeya);
        }
        v87 = *(_DWORD *)Data > 1u;
        v14 = CCmdString::operator+((CCmdString *)&ppv, (CCmdString *)&v91, L"\\CLSID")->m_String;
        LOBYTE(v92) = 22;
        v15 = (unsigned int)TlsGetValue(gdwTlsIndex);
        v16 = PE_OpenKey(HKEY_CLASSES_ROOT, v14, 0, v15 | KEY_READ, &hKeya);
        LOBYTE(v92) = 21;
        v17 = v16 == 0;
        free(ppv);
        if ( !v17 )
          goto LABEL_39;
        if ( PE_ReadRegKey(hKeya, (LPCWSTR)&gszNullString, 0, 0, (CCmdString *)&v91) )
          break;
        v10(hKeya);
        v18 = operator+((CCmdString *)&pszResult, L"CLSID\\", (CCmdString *)&v91);
        v19 = CCmdString::operator+(&str, v18, L"\\InprocServer32");
        v20 = pszText;
        pszText = _wcsdup(v19->m_String);
        free(v20);
        free(str.m_String);
        free(pszResult);
        v21 = operator+(&v61, L"HKCR\\CLSID\\", (CCmdString *)&v91);
        v22 = v80;
        v80 = _wcsdup(v21->m_String);
        free(v22);
        free(v61.m_String);
        v23 = pszText;
        TlsGetValue = ::TlsGetValue;
        v24 = (unsigned int)::TlsGetValue(gdwTlsIndex);
        if ( PE_OpenKey(HKEY_CLASSES_ROOT, v23, 0, v24 | 0x20019, &hKeya) )
          goto LABEL_16;
        if ( !PE_ReadRegKey(hKeya, (LPCWSTR)&gszNullString, 0, 0, (CCmdString *)&pszText) )
        {
          sub_BE7040(pszText, (StringItem *)&v82);
          v25 = (const wchar_t **)sub_BE4EE0((int)&v63, a1, (int)&v82, 0);
          v26 = (WCHAR *)szArg3;
          szArg3 = _wcsdup(*v25);
          free(v26);
          free(v63);
          v10(hKeya);
LABEL_16:
          a2 = sub_BE4ED0();
          v27 = _wcsdup(L"CLSID\\");
          ppv2 = v27;
          v28 = CCmdString::Append((CCmdString *)&ppv1, (CCmdString *)&ppv2, (CCmdString *)&v91);
          v29 = pszText;
          pszText = _wcsdup(v28->m_String);
          free(v29);
          free(ppv1);
          free(v27);
          v30 = ppv3;
          ppv3 = _wcsdup((const wchar_t *)v91.unused);
          free(v30);
          v31 = pszText;
          v32 = (unsigned int)::TlsGetValue(gdwTlsIndex);
          if ( PE_OpenKey(HKEY_CLASSES_ROOT, v31, 0, v32 | 0x20019, &hKeya) )
          {
            v10 = (void (__stdcall *)(HKEY))RegCloseKey;
          }
          else
          {
            if ( !PE_ReadRegKey(hKeya, (LPCWSTR)&gszNullString, 0, 0, (CCmdString *)&pszText) && wcslen(pszText) )
            {
              v33 = ppv3;
              ppv3 = _wcsdup(pszText);
              free(v33);
            }
            v10 = (void (__stdcall *)(HKEY))RegCloseKey;
            RegCloseKey(hKeya);
          }
          v34 = (const wchar_t *)&gszNullString;
          if ( lpszKeyName )
            v34 = lpszKeyName;
          v82.strValue[6] = (int)_wcsdup(v34);
          v82.strValue[4] = (int)_wcsdup((const wchar_t *)&gszNullString);
          v35 = (const wchar_t *)&gszNullString;
          if ( lpszKeyName )
            v35 = lpszKeyName;
          v82.strValue[5] = (int)_wcsdup(v35);
          LOBYTE(v92) = 25;
          v36 = MakeRegistryKeyName((CCmdString *)v53, hKey, (CCmdString *)&v82.strValue[6], (CCmdString *)&v91);
          LOBYTE(v92) = 26;
          v37 = MakeRegistryKeyName(
                  (CCmdString *)v57,
                  hKey,
                  (CCmdString *)&v82.strValue[5],
                  (CCmdString *)&v82.strValue[4]);
          LOBYTE(v92) = 27;
          v38 = sub_BE3D40(
                  a1,
                  (CCmdString)&ppv3,
                  (int)v37,
                  (int)v36,
                  (int)&szArg3,
                  (int)&v81,
                  (CCmdString)&v75,
                  (int)&a8);
          free(*(void **)v57);
          free(*(void **)v53);
          free((void *)v82.strValue[5]);
          free((void *)v82.strValue[4]);
          free((void *)v82.strValue[6]);
          if ( v38 )
          {
            if ( Handle == (HANDLE)-1 )
            {
              v65 = _wcsdup((const wchar_t *)&gszNullString);
              v69 = _wcsdup((const wchar_t *)&gszNullString);
              v67 = _wcsdup((const wchar_t *)&gszNullString);
              v73 = _wcsdup((const wchar_t *)&gszNullString);
              v71 = _wcsdup((const wchar_t *)&gszNullString);
              str3.m_String = _wcsdup((const wchar_t *)&gszNullString);
              v70 = _wcsdup((const wchar_t *)&gszNullString);
              v39 = lpszKeyName;
              v40 = (const wchar_t *)&gszNullString;
              if ( lpszKeyName )
                v40 = lpszKeyName;
              v83 = _wcsdup(v40);
              v85 = _wcsdup((const wchar_t *)&gszNullString);
              v41 = (const wchar_t *)&gszNullString;
              if ( lpszKeyName )
                v41 = lpszKeyName;
              v84 = _wcsdup(v41);
              LOBYTE(v92) = 37;
              v42 = MakeRegistryKeyName((CCmdString *)v60, hKey, (CCmdString *)&v83, (CCmdString *)&v70);
              LOBYTE(v92) = 38;
              v43 = MakeRegistryKeyName((CCmdString *)v62, hKey, (CCmdString *)&v84, (CCmdString *)&v85);
              LOBYTE(v92) = 39;
              Handle = (HANDLE)PE_UpdateSystemKey(a1, 0, (HANDLE)0xFFFFFFFF, 0, v43, v42, &str3);
              free(*(void **)v62);
              free(*(void **)v60);
              free((void *)v84);
              free((void *)v85);
              free((void *)v83);
              free((void *)v70);
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
            a1a = _wcsdup((const wchar_t *)&gszNullString);
            v44 = &gszNullString;
            if ( v39 )
              v44 = (const WCHAR **)v39;
            v72 = _wcsdup((const wchar_t *)v44);
            LOBYTE(v92) = 41;
            v45 = MakeRegistryKeyName((CCmdString *)v54, hKey, (CCmdString *)&v72, (CCmdString *)&v77);
            LOBYTE(v92) = 42;
            PE_UpdateSystemKey(a1, a2, Handle, 0x12u, (CCmdString *)&ppv3, v45, (CCmdString *)&szArg3);
            free(*(void **)v54);
            free((void *)v72);
            free(a1a);
          }
LABEL_39:
          StringItem::~StringItem(&v82);
          free((void *)szArg3);
          free((void *)v91.unused);
          free(pszText);
          TlsGetValue = ::TlsGetValue;
          goto LABEL_40;
        }
        v10(hKeya);
        StringItem::~StringItem(&v82);
        free((void *)szArg3);
        free((void *)v91.unused);
        free(pszText);
LABEL_40:
        szArg = (WCHAR *)((char *)szArg + 1);
        v46 = szArg;
        pszText = (wchar_t *)malloc(2u);
        *pszText = 0;
        v91.unused = (int)malloc(2u);
        *(_WORD *)v91.unused = 0;
        szArg3 = (LPCWSTR)malloc(2u);
        *szArg3 = 0;
        v82.strValue[0] = (int)malloc(2u);
        *(_WORD *)v82.strValue[0] = 0;
        v82.strValue[1] = 0;
        v82.strValue[2] = 0;
        v82.strValue[3] = 0;
        LOBYTE(v92) = 21;
        if ( PE_LoadRegKeys(KeyHandle, (DWORD)v46, (CCmdString *)&v91) )
          goto LABEL_41;
      }
      v10(hKeya);
      goto LABEL_39;
    }
LABEL_41:
    v47 = (void **)v82.strValue[1];
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
        while ( v47 != (void **)v48 );
        v47 = (void **)v82.strValue[1];
      }
      operator delete(v47);
      v82.strValue[1] = 0;
      v82.strValue[2] = 0;
      v82.strValue[3] = 0;
    }
    free((void *)v82.strValue[0]);
    free((void *)szArg3);
    free((void *)v91.unused);
    free(pszText);
    v10(KeyHandle);
  }
  free((void *)v77);
  free(v80);
  free(v75.m_String);
  free(v74);
  free(v81);
  free(ppv3);
  return Handle;
}

//----- (00BF8A90) --------------------------------------------------------
void __cdecl LoadPrintServiceDirectory(DWORD dwValue, HKEY hRootKey, LPCWSTR lpszKeyName, DWORD dwArgs)
{
  WCHAR *pszNewKeyName; // esi
  void *v5; // ebx
  CCmdString *v6; // eax
  WCHAR *v7; // edi
  HKEY hKey; // [esp+14h] [ebp-10h]
  int v9; // [esp+20h] [ebp-4h]

  pszNewKeyName = (WCHAR *)malloc(2u);
  *pszNewKeyName = 0;
  v9 = 0;
  if ( gbPrintDirectoryInited )
  {
LABEL_10:
    v5 = sub_BF8C20(dwValue, hRootKey, *(LPCWSTR *)lpszKeyName, (HANDLE)0xFFFFFFFF, 1, dwArgs);
    v6 = CCmdString::operator+((CCmdString *)&hKey, (CCmdString *)lpszKeyName, L"\\AutorunsDisabled");
    v7 = pszNewKeyName;
    pszNewKeyName = _wcsdup(v6->m_String);
    free(v7);
    free(hKey);
    sub_BF8C20(dwValue, hRootKey, pszNewKeyName, v5, 0, dwArgs);
    goto LABEL_11;
  }
  if ( !PE_OpenKey(ghLocalMachineKey, L"SYSTEM\\CurrentControlSet\\Control\\Print", 0, KEY_READ, &hKey)
    || !dword_CD3628[0] )
  {
    if ( !PE_OpenKey(
            ghLocalMachineKey,
            L"SYSTEM\\CurrentControlSet\\Control\\Print\\Environments\\Windows NT x86",
            0,
            0x20019u,
            &hKey) )
    {
      PE_ReadRegKey(hKey, L"Directory", 0, 0, &gszPrintDirectoryForNTX86);
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
// CD3628: using guessed type int dword_CD3628[140];
// CD4C58: using guessed type char gbPrintDirectoryInited;

//----- (00BF8C20) --------------------------------------------------------
void *__cdecl sub_BF8C20(DWORD dwValue, HKEY hRootKey, LPCWSTR lpszKeyName, HANDLE Handle, bool bFlags, DWORD dwArgs)
{
  LPCWSTR v6; // edi
  int v7; // ebx
  const wchar_t *v8; // eax
  const wchar_t *v9; // eax
  CCmdString *pstr1; // esi
  CCmdString *pstr2; // eax
  unsigned int v12; // eax
  const WCHAR *v13; // esi
  unsigned int v14; // eax
  const wchar_t **v15; // eax
  WCHAR *v16; // esi
  CCmdString *v17; // edi
  WCHAR *v18; // esi
  CCmdString *v19; // eax
  CCmdString *v20; // eax
  wchar_t *v21; // esi
  const wchar_t **v22; // eax
  wchar_t *v23; // edi
  WCHAR *v24; // edi
  const WCHAR **v25; // ecx
  const WCHAR **v26; // eax
  CCmdString *v27; // esi
  CCmdString *v28; // eax
  char v29; // bl
  const WCHAR **v30; // eax
  const WCHAR **v31; // eax
  CCmdString *v32; // esi
  CCmdString *v33; // eax
  const WCHAR **v34; // eax
  CCmdString *v35; // eax
  CCmdString pszResult[7]; // [esp+10h] [ebp-B0h]
  int a8; // [esp+2Ch] [ebp-94h]
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
  CCmdString v54; // [esp+6Ch] [ebp-54h]
  std__Vector_val a1; // [esp+70h] [ebp-50h]
  WCHAR szArg[2]; // [esp+7Ch] [ebp-44h]
  std__list_node str1; // [esp+80h] [ebp-40h]
  LPCWSTR pszArgs2; // [esp+8Ch] [ebp-34h]
  LPCWSTR pszNewKeyName2; // [esp+90h] [ebp-30h]
  LPCWSTR pszArgs1; // [esp+94h] [ebp-2Ch]
  std__list_node str2; // [esp+98h] [ebp-28h]
  WCHAR *pszNewKeyName; // [esp+A4h] [ebp-1Ch]
  CCmdString str3; // [esp+A8h] [ebp-18h]
  LPCWSTR lpszKeyNamea; // [esp+ACh] [ebp-14h]
  WCHAR szText2[2]; // [esp+B0h] [ebp-10h]
  int v66; // [esp+BCh] [ebp-4h]

  v48 = 0;
  *(_DWORD *)szText2 = malloc(2u);
  **(_WORD **)szText2 = 0;
  v66 = 0;
  str3.m_String = (WCHAR *)malloc(2u);
  *str3.m_String = 0;
  a1._Mylast = malloc(2u);
  *(_WORD *)a1._Mylast = 0;
  v53 = malloc(2u);
  *(_WORD *)v53 = 0;
  v54.m_String = (WCHAR *)malloc(2u);
  *v54.m_String = 0;
  v6 = lpszKeyName;
  v7 = dwValue;
  LOBYTE(v66) = 4;
  if ( Handle == (HANDLE)-1 )
  {
    str1._Next = (std__list_node *)_wcsdup((const wchar_t *)&gszNullString);
    str1._Next = (std__list_node *)_wcsdup((const wchar_t *)&gszNullString);
    str1._Myval = _wcsdup((const wchar_t *)&gszNullString);
    str2._Next = (std__list_node *)_wcsdup((const wchar_t *)&gszNullString);
    str2._Prev = (std__list_node *)_wcsdup((const wchar_t *)&gszNullString);
    str2._Myval = _wcsdup((const wchar_t *)&gszNullString);
    pszArgs1 = _wcsdup((const wchar_t *)&gszNullString);
    v8 = (const wchar_t *)&gszNullString;
    if ( lpszKeyName )
      v8 = lpszKeyName;
    pszNewKeyName = _wcsdup(v8);
    pszArgs2 = _wcsdup((const wchar_t *)&gszNullString);
    v9 = (const wchar_t *)&gszNullString;
    if ( lpszKeyName )
      v9 = lpszKeyName;
    pszNewKeyName2 = _wcsdup(v9);
    LOBYTE(v66) = 14;
    pstr1 = MakeRegistryKeyName((CCmdString *)&a1, hRootKey, (CCmdString *)&pszNewKeyName, (CCmdString *)&pszArgs1);
    LOBYTE(v66) = 15;
    pstr2 = MakeRegistryKeyName((CCmdString *)szArg, hRootKey, (CCmdString *)&pszNewKeyName2, (CCmdString *)&pszArgs2);
    LOBYTE(v66) = 16;
    Handle = (HANDLE)PE_UpdateSystemKey(dwValue, 0, (HANDLE)0xFFFFFFFF, 0, pstr2, pstr1, (CCmdString *)&str2._Myval);
    free(*(void **)szArg);
    free(a1._Myfirst);
    free((void *)pszNewKeyName2);
    free((void *)pszArgs2);
    free(pszNewKeyName);
    free((void *)pszArgs1);
    free(str2._Myval);
    free(str2._Prev);
    free(str2._Next);
    free(str1._Myval);
    free(str1._Next);
    LOBYTE(v66) = 4;
    free(str1._Prev);
  }
  v12 = (unsigned int)TlsGetValue(gdwTlsIndex);
  if ( !PE_OpenKey(ghLocalMachineKey, lpszKeyName, 0, v12 | KEY_READ, (PHKEY)&a1._Myend) )
  {
    lpszKeyNamea = (LPCWSTR)malloc(2u);
    *lpszKeyNamea = 0;
    LOBYTE(v66) = 17;
    if ( !PE_LoadRegKeys((HKEY)a1._Myend, 0, (CCmdString *)&lpszKeyNamea) )
    {
      do
      {
        v13 = lpszKeyNamea;
        v14 = (unsigned int)TlsGetValue(gdwTlsIndex);
        if ( !PE_OpenKey((HKEY)a1._Myend, v13, 0, v14 | 0x20019, &hKey) )
        {
          if ( !PE_ReadRegKey(hKey, L"Driver", 0, 0, (CCmdString *)szText2) )
          {
            pszResult[0].m_String = (WCHAR *)malloc(2u);
            *pszResult[0].m_String = 0;
            pszResult[1].m_String = 0;
            pszResult[2].m_String = 0;
            pszResult[3].m_String = 0;
            LOBYTE(v66) = 18;
            sub_BE7040(*(wchar_t **)szText2, (StringItem *)pszResult);
            *(_DWORD *)szArg = _wcsdup(*(const wchar_t **)szText2);
            LOBYTE(v66) = 19;
            v15 = (const wchar_t **)sub_BE4EE0((int)&v41, v7, (int)pszResult, 0);
            v16 = str3.m_String;
            str3.m_String = _wcsdup(*v15);
            free(v16);
            free(v41);
            if ( !wcschr(*(const wchar_t **)szText2, 0x5Cu) )
            {
              v17 = &gszPrintDirectoryForX86;
              if ( !dwArgs )
                v17 = &gszPrintDirectoryForNTX86;
              v18 = _wcsdup(L"\\");
              ppv3 = v18;
              v19 = operator+(&pszResult[4], L"\\SystemRoot\\System32\\Spool\\Prtprocs\\", v17);
              v20 = CCmdString::Append((CCmdString *)&ppv1, v19, (CCmdString *)&ppv3);
              CCmdString::Append((CCmdString *)&ppv, v20, (CCmdString *)szText2);
              LOBYTE(v66) = 20;
              free(ppv1);
              free(pszResult[4].m_String);
              free(v18);
              v21 = ppv;
              v22 = (const wchar_t **)sub_BE4F20((int)&pszResult[6], v7, ppv);
              v23 = *(wchar_t **)szText2;
              *(_DWORD *)szText2 = _wcsdup(*v22);
              free(v23);
              free(pszResult[6].m_String);
              if ( wcsncmp(*(const wchar_t **)szText2, L"File not found: ", 0x10u) )
              {
                v24 = str3.m_String;
                str3.m_String = _wcsdup(*(const wchar_t **)szText2);
                free(v24);
              }
              LOBYTE(v66) = 19;
              free(v21);
              v6 = lpszKeyName;
            }
            ppv3 = (WCHAR *)sub_BE4ED0();
            v25 = &gszNullString;
            if ( v6 )
              v25 = (const WCHAR **)v6;
            str1._Myval = _wcsdup((const wchar_t *)v25);
            str1._Next = (std__list_node *)_wcsdup((const wchar_t *)&gszNullString);
            v26 = &gszNullString;
            if ( v6 )
              v26 = (const WCHAR **)v6;
            str1._Prev = (std__list_node *)_wcsdup((const wchar_t *)v26);
            LOBYTE(v66) = 23;
            v27 = MakeRegistryKeyName(
                    (CCmdString *)v44,
                    hRootKey,
                    (CCmdString *)&str1._Myval,
                    (CCmdString *)&lpszKeyNamea);
            LOBYTE(v66) = 24;
            v28 = MakeRegistryKeyName((CCmdString *)v39, hRootKey, (CCmdString *)&str1._Prev, (CCmdString *)&str1);
            LOBYTE(v66) = 25;
            v29 = sub_BE3D40(
                    v7,
                    (CCmdString)&lpszKeyNamea,
                    (int)v28,
                    (int)v27,
                    (int)&str3,
                    (int)&a1._Mylast,
                    (CCmdString)&v54,
                    (int)&a8);
            free(*(void **)v39);
            free(*(void **)v44);
            free(str1._Prev);
            free(str1._Next);
            free(str1._Myval);
            if ( v29 )
            {
              if ( Handle == (HANDLE)-1 )
              {
                v47 = _wcsdup((const wchar_t *)&gszNullString);
                v51 = _wcsdup((const wchar_t *)&gszNullString);
                v49 = _wcsdup((const wchar_t *)&gszNullString);
                pszNewKeyName2 = _wcsdup((const wchar_t *)&gszNullString);
                pszArgs2 = _wcsdup((const wchar_t *)&gszNullString);
                pszNewKeyName = _wcsdup((const wchar_t *)&gszNullString);
                pszArgs1 = _wcsdup((const wchar_t *)&gszNullString);
                v30 = &gszNullString;
                if ( v6 )
                  v30 = (const WCHAR **)v6;
                str2._Myval = _wcsdup((const wchar_t *)v30);
                str2._Prev = (std__list_node *)_wcsdup((const wchar_t *)&gszNullString);
                v31 = &gszNullString;
                if ( v6 )
                  v31 = (const WCHAR **)v6;
                str2._Next = (std__list_node *)_wcsdup((const wchar_t *)v31);
                LOBYTE(v66) = 35;
                v32 = MakeRegistryKeyName(
                        (CCmdString *)v40,
                        hRootKey,
                        (CCmdString *)&str2._Myval,
                        (CCmdString *)&pszArgs1);
                LOBYTE(v66) = 36;
                v33 = MakeRegistryKeyName((CCmdString *)v42, hRootKey, (CCmdString *)&str2, (CCmdString *)&str2._Prev);
                LOBYTE(v66) = 37;
                v7 = dwValue;
                Handle = (HANDLE)PE_UpdateSystemKey(
                                   dwValue,
                                   0,
                                   (HANDLE)0xFFFFFFFF,
                                   0,
                                   v33,
                                   v32,
                                   (CCmdString *)&pszNewKeyName);
                free(*(void **)v42);
                free(*(void **)v40);
                free(str2._Next);
                free(str2._Prev);
                free(str2._Myval);
                free((void *)pszArgs1);
                free(pszNewKeyName);
                free((void *)pszArgs2);
                free((void *)pszNewKeyName2);
                free(v49);
                free(v51);
                free(v47);
              }
              else
              {
                v7 = dwValue;
              }
              a1._Myfirst = _wcsdup((const wchar_t *)&gszNullString);
              v34 = &gszNullString;
              if ( v6 )
                v34 = (const WCHAR **)v6;
              szKeyName = _wcsdup((const wchar_t *)v34);
              LOBYTE(v66) = 39;
              v35 = MakeRegistryKeyName(&pszResult[5], hRootKey, (CCmdString *)&szKeyName, (CCmdString *)&lpszKeyNamea);
              LOBYTE(v66) = 40;
              PE_UpdateSystemKey(v7, (DWORD)ppv3, Handle, 3u, (CCmdString *)&lpszKeyNamea, v35, &str3);
              free(pszResult[5].m_String);
              free((void *)szKeyName);
              free(a1._Myfirst);
            }
            else
            {
              v7 = dwValue;
            }
            free(*(void **)szArg);
            LOBYTE(v66) = 17;
            StringItem::~StringItem((tagPEStringStruct *)pszResult);
          }
          RegCloseKey(hKey);
        }
        ++v48;
      }
      while ( !PE_LoadRegKeys((HKEY)a1._Myend, v48, (CCmdString *)&lpszKeyNamea) );
    }
    RegCloseKey((HKEY)a1._Myend);
    free((void *)lpszKeyNamea);
  }
  free(v54.m_String);
  free(v53);
  free(a1._Mylast);
  free(str3.m_String);
  free(*(void **)szText2);
  return Handle;
}

//----- (00BF93C0) --------------------------------------------------------
char __cdecl PE_GetServiceDescription(LPCWSTR lpServiceName, CCmdString *strServiceDescription)
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
        (::QueryServiceConfig2W_0 = (int (__stdcall *)(SC_HANDLE, DWORD, LPBYTE, DWORD, LPDWORD))QueryServiceConfig2W_0) != 0) )
  {
    if ( !((int (__stdcall *)(SC_HANDLE, signed int, _DWORD, _DWORD, size_t *))QueryServiceConfig2W_0)(
            v5,
            1,
            0,
            0,
            &cbBufSize) )
    {
      v9 = cbBufSize;
      ServiceDesriptor = (_SERVICE_DESCRIPTIONW *)malloc(cbBufSize);
      if ( ::QueryServiceConfig2W_0(hService, SERVICE_CONFIG_DESCRIPTION, (LPBYTE)ServiceDesriptor, v9, &cbBufSize) )
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
          if ( (unsigned int)(pstrDesc1 - (lpDescription + 1)) > 3 )
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
        CCmdString::Reset(strServiceDescription, ServiceDesriptor->lpDescription);
        v2 = 1;
      }
      free(ServiceDesriptor);
      v5 = hService;
    }
  }
  CloseServiceHandle(v5);
  CloseServiceHandle(v4);
LABEL_5:
  free((void *)lpServiceName);
  return v2;
}

//----- (00BF9580) --------------------------------------------------------
void *__cdecl sub_BF9580(int a1, void *a2, wchar_t *psz)
{
  WCHAR *v3; // eax
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
  CCmdString *v14; // esi
  CCmdString *v15; // eax
  void *v16; // esi
  LSTATUS (__stdcall *v17)(HKEY, LPCWSTR, LPDWORD, LPDWORD, LPBYTE, LPDWORD); // esi
  WCHAR *v18; // esi
  void *v19; // esi
  const wchar_t **v20; // eax
  WCHAR *v21; // esi
  void *v22; // esi
  CCmdString *v23; // eax
  void *v24; // esi
  CCmdString *v25; // eax
  void *v26; // esi
  wchar_t *v27; // eax
  CCmdString *v28; // eax
  wchar_t *v29; // eax
  WCHAR *v30; // esi
  const WCHAR **v31; // eax
  const WCHAR **v32; // eax
  CCmdString *v33; // esi
  CCmdString *v34; // eax
  char v35; // bl
  const wchar_t *v36; // eax
  const wchar_t *v37; // eax
  CCmdString *v38; // esi
  CCmdString *v39; // eax
  const WCHAR **v40; // eax
  CCmdString *v41; // eax
  int a2a; // [esp+10h] [ebp-F4h]
  tagPEStringStruct v44; // [esp+20h] [ebp-E4h]
  int v45; // [esp+3Ch] [ebp-C8h]
  CCmdString strResult; // [esp+40h] [ebp-C4h]
  BYTE v47; // [esp+44h] [ebp-C0h]
  BYTE v48; // [esp+48h] [ebp-BCh]
  void *v49; // [esp+50h] [ebp-B4h]
  WCHAR v50[2]; // [esp+54h] [ebp-B0h]
  WCHAR v51[2]; // [esp+58h] [ebp-ACh]
  void *v52; // [esp+5Ch] [ebp-A8h]
  WCHAR *v53; // [esp+60h] [ebp-A4h]
  int a8; // [esp+64h] [ebp-A0h]
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
  CCmdString v65; // [esp+90h] [ebp-74h]
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
  CCmdString str3; // [esp+ECh] [ebp-18h]
  CCmdString v89; // [esp+F0h] [ebp-14h]
  char v90; // [esp+F7h] [ebp-Dh]
  int v91; // [esp+100h] [ebp-4h]

  v66 = 0;
  v3 = (WCHAR *)malloc(2u);
  v89.m_String = v3;
  *v3 = 0;
  v91 = 0;
  v4 = (WCHAR *)malloc(2u);
  lpszKeyName = v4;
  *v4 = 0;
  v5 = (WCHAR *)malloc(2u);
  ppv3 = v5;
  *v5 = 0;
  v6 = (WCHAR *)malloc(2u);
  str3.m_String = v6;
  *v6 = 0;
  v7 = malloc(2u);
  v71 = v7;
  *v7 = 0;
  v8 = malloc(2u);
  ppv = v8;
  *v8 = 0;
  v9 = (WCHAR *)malloc(2u);
  v65.m_String = v9;
  *v9 = 0;
  v10 = malloc(2u);
  v86 = v10;
  *v10 = 0;
  v72 = _wcsdup((const wchar_t *)&gszNullString);
  v74 = _wcsdup((const wchar_t *)&gszNullString);
  szKeyName = _wcsdup((const wchar_t *)&gszNullString);
  v78 = _wcsdup((const wchar_t *)&gszNullString);
  v80 = _wcsdup((const wchar_t *)&gszNullString);
  v81 = _wcsdup((const wchar_t *)&gszNullString);
  szArg4 = _wcsdup((const wchar_t *)&gszNullString);
  v11 = psz;
  v12 = (const wchar_t *)&gszNullString;
  if ( psz )
    v12 = psz;
  pszText = _wcsdup(v12);
  v79 = _wcsdup((const wchar_t *)&gszNullString);
  v13 = (const wchar_t *)&gszNullString;
  if ( psz )
    v13 = psz;
  szArg3 = _wcsdup(v13);
  LOBYTE(v91) = 17;
  v14 = MakeRegistryKeyName((CCmdString *)&a1a, (HKEY)a2, (CCmdString *)&pszText, (CCmdString *)&szArg4);
  LOBYTE(v91) = 18;
  v15 = MakeRegistryKeyName((CCmdString *)szArg, (HKEY)a2, (CCmdString *)&szArg3, (CCmdString *)&v79);
  LOBYTE(v91) = 19;
  v16 = (void *)PE_UpdateSystemKey(a1, 0, (HANDLE)0xFFFFFFFF, 0, v15, v14, (CCmdString *)&v81);
  ppv1 = v16;
  free(*(void **)szArg);
  free(a1a);
  free((void *)szArg3);
  free((void *)v79);
  free(pszText);
  free((void *)szArg4);
  free((void *)v81);
  free((void *)v80);
  free((void *)v78);
  free((void *)szKeyName);
  free((void *)v74);
  LOBYTE(v91) = 7;
  free((void *)v72);
  if ( PE_OpenKey(ghLocalMachineKey, psz, 0, 0x20019u, &hRootKey) )
    goto LABEL_64;
  if ( PE_LoadRegKeys(hRootKey, 0, (CCmdString *)&lpszKeyName) )
    goto LABEL_63;
  v17 = RegQueryValueExW;
  do
  {
    if ( PE_OpenKey(hRootKey, lpszKeyName, 0, 0x20019u, &hKey) )
      goto LABEL_61;
    cbData = 4;
    if ( v17(hKey, L"Start", 0, 0, Data, &cbData)
      || *(_DWORD *)Data != 2 && *(_DWORD *)Data != 4 && *(_DWORD *)Data != 3 )
    {
      goto LABEL_60;
    }
    cbData = 4;
    if ( *(_DWORD *)Data == 4 )
    {
      if ( v17(hKey, L"AutorunsDisabled", 0, 0, Data, &cbData) )
        goto LABEL_60;
      v90 = 0;
    }
    else
    {
      v90 = 1;
    }
    if ( v17(hKey, L"Type", 0, 0, &v48, &cbData) || *(_DWORD *)&v48 <= 2u )
      goto LABEL_60;
    v18 = str3.m_String;
    str3.m_String = _wcsdup((const wchar_t *)&gszNullString);
    free(v18);
    if ( PE_ReadRegKey(hKey, L"ServiceDll", 0, 0, &v89) )
    {
      if ( !PE_OpenKey(hKey, L"Parameters", 0, 1u, &KeyHandle) )
      {
        if ( !PE_ReadRegKey(KeyHandle, L"ServiceDll", 0, 0, &v89) )
        {
          v22 = v86;
          v86 = _wcsdup(v89.m_String);
          free(v22);
          StringItem::StringItem((StringItem *)&v44);
          LOBYTE(v91) = 21;
          sub_BE7040(v89.m_String, (StringItem *)&v44);
          v23 = (CCmdString *)sub_BE4EE0((int)&v49, a1, (int)&v44, 0);
          CCmdString::Reset(&str3, v23);
          free(v49);
          LOBYTE(v91) = 7;
          StringItem::~StringItem(&v44);
        }
        RegCloseKey(KeyHandle);
      }
    }
    else
    {
      v19 = v86;
      v86 = _wcsdup(v89.m_String);
      free(v19);
      v44.strValue[4] = (int)malloc(2u);
      *(_WORD *)v44.strValue[4] = 0;
      v44.strValue[5] = 0;
      v44.strValue[6] = 0;
      v45 = 0;
      LOBYTE(v91) = 20;
      sub_BE7040(v89.m_String, (StringItem *)&v44.strValue[4]);
      v20 = (const wchar_t **)sub_BE4EE0((int)&v52, a1, (int)&v44.strValue[4], 0);
      v21 = str3.m_String;
      str3.m_String = _wcsdup(*v20);
      free(v21);
      free(v52);
      LOBYTE(v91) = 7;
      StringItem::~StringItem((tagPEStringStruct *)((char *)&v44 + 16));
    }
    if ( *str3.m_String )
    {
LABEL_36:
      dwValue = sub_BE4ED0();
      PE_ReadRegKey(hKey, L"Description", 0, 0, (CCmdString *)&ppv);
      if ( wcslen((const unsigned __int16 *)ppv) && *(_WORD *)ppv == 64 )
      {
        v29 = _wcsdup(lpszKeyName);
        PE_GetServiceDescription(v29, (CCmdString *)&ppv);
      }
      else if ( wcslen((const unsigned __int16 *)ppv) > 3
             && *((_WORD *)ppv + wcslen((const unsigned __int16 *)ppv) - 1) == 10 )
      {
        *((_WORD *)ppv + wcslen((const unsigned __int16 *)ppv) - 1) = 0;
        if ( *((_WORD *)ppv + wcslen((const unsigned __int16 *)ppv) - 1) == 13 )
          *((_WORD *)ppv + wcslen((const unsigned __int16 *)ppv) - 1) = 0;
      }
      v30 = ppv3;
      ppv3 = _wcsdup(lpszKeyName);
      free(v30);
      v31 = &gszNullString;
      if ( v11 )
        v31 = (const WCHAR **)v11;
      szKeyName = _wcsdup((const wchar_t *)v31);
      v74 = _wcsdup((const wchar_t *)&gszNullString);
      v32 = &gszNullString;
      if ( v11 )
        v32 = (const WCHAR **)v11;
      v72 = _wcsdup((const wchar_t *)v32);
      LOBYTE(v91) = 25;
      v33 = MakeRegistryKeyName(&strResult, (HKEY)a2, (CCmdString *)&szKeyName, (CCmdString *)&lpszKeyName);
      LOBYTE(v91) = 26;
      v34 = MakeRegistryKeyName((CCmdString *)v51, (HKEY)a2, (CCmdString *)&v72, (CCmdString *)&v74);
      LOBYTE(v91) = 27;
      v35 = sub_BE3D40(a1, (CCmdString)&ppv3, (int)v34, (int)v33, (int)&str3, (int)&v71, (CCmdString)&v65, (int)&a8);
      free(*(void **)v51);
      free(strResult.m_String);
      free((void *)v72);
      free((void *)v74);
      LOBYTE(v91) = 7;
      free((void *)szKeyName);
      if ( v35 )
      {
        if ( ppv1 == (void *)-1 )
        {
          v60 = _wcsdup((const wchar_t *)&gszNullString);
          v59 = _wcsdup((const wchar_t *)&gszNullString);
          v61 = _wcsdup((const wchar_t *)&gszNullString);
          szArg3 = _wcsdup((const wchar_t *)&gszNullString);
          v79 = _wcsdup((const wchar_t *)&gszNullString);
          pszText = _wcsdup((const wchar_t *)&gszNullString);
          szArg4 = _wcsdup((const wchar_t *)&gszNullString);
          v11 = psz;
          v36 = (const wchar_t *)&gszNullString;
          if ( psz )
            v36 = psz;
          v81 = _wcsdup(v36);
          v80 = _wcsdup((const wchar_t *)&gszNullString);
          v37 = (const wchar_t *)&gszNullString;
          if ( psz )
            v37 = psz;
          v78 = _wcsdup(v37);
          LOBYTE(v91) = 37;
          v38 = MakeRegistryKeyName((CCmdString *)v56, (HKEY)a2, (CCmdString *)&v81, (CCmdString *)&szArg4);
          LOBYTE(v91) = 38;
          v39 = MakeRegistryKeyName((CCmdString *)v57, (HKEY)a2, (CCmdString *)&v78, (CCmdString *)&v80);
          LOBYTE(v91) = 39;
          ppv1 = (void *)PE_UpdateSystemKey(a1, 0, (HANDLE)0xFFFFFFFF, 0, v39, v38, (CCmdString *)&pszText);
          free(*(void **)v57);
          free(*(void **)v56);
          free((void *)v78);
          free((void *)v80);
          free((void *)v81);
          free((void *)szArg4);
          free(pszText);
          free((void *)v79);
          free((void *)szArg3);
          free(v61);
          free(v59);
          free(v60);
        }
        else
        {
          v11 = psz;
        }
        *(_DWORD *)szArg = _wcsdup((const wchar_t *)&gszNullString);
        v40 = &gszNullString;
        if ( v11 )
          v40 = (const WCHAR **)v11;
        a1a = _wcsdup((const wchar_t *)v40);
        LOBYTE(v91) = 41;
        v41 = MakeRegistryKeyName((CCmdString *)v50, (HKEY)a2, (CCmdString *)&a1a, (CCmdString *)&lpszKeyName);
        LOBYTE(v91) = 42;
        PE_UpdateSystemKey(a1, dwValue, ppv1, 8u, (CCmdString *)&ppv3, v41, &str3);
        free(*(void **)v50);
        free(a1a);
        LOBYTE(v91) = 7;
        free(*(void **)szArg);
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
        v86 = _wcsdup(v89.m_String);
        free(v24);
        StringItem::StringItem((StringItem *)&a2a);
        LOBYTE(v91) = 22;
        sub_BE6CC0(v89.m_String, (StringItem *)&a2a);
        v25 = (CCmdString *)sub_BE4EE0((int)&v55, a1, (int)&a2a, 0);
        CCmdString::Reset(&str3, v25);
        free(v55);
        LOBYTE(v91) = 7;
        StringItem::~StringItem((tagPEStringStruct *)&a2a);
      }
      else
      {
        if ( !*(_DWORD *)&v47 )
          goto LABEL_35;
        if ( Wow64EnableWow64FsRedirection )
        {
          Wow64EnableWow64FsRedirection(1u);
          TlsSetValue(gdwTlsIndex, (LPVOID)0x200);
        }
        v26 = v86;
        v86 = _wcsdup(v89.m_String);
        free(v26);
        v27 = _wcsdup(v89.m_String);
        PE_GetSystemPathInfo(&v53, v27);
        free(v53);
        v28 = (CCmdString *)sub_BE4F20((int)&v58, a1, v89.m_String);
        CCmdString::Reset(&str3, v28);
        free(v58);
        if ( Wow64EnableWow64FsRedirection )
        {
          Wow64EnableWow64FsRedirection(0);
          TlsSetValue(gdwTlsIndex, (LPVOID)0x100);
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
  while ( !PE_LoadRegKeys(hRootKey, v66, (CCmdString *)&lpszKeyName) );
  v16 = ppv1;
LABEL_63:
  RegCloseKey(hRootKey);
LABEL_64:
  free(v86);
  free(v65.m_String);
  free(ppv);
  free(v71);
  free(str3.m_String);
  free(ppv3);
  free((void *)lpszKeyName);
  free(v89.m_String);
  return v16;
}

//----- (00BFA070) --------------------------------------------------------
void __cdecl sub_BFA070(int a1, void *a2, void *a3)
{
  _WORD *v3; // ST50_4
  CCmdString *v4; // esi
  void *v5; // edi
  CCmdString *v6; // eax
  wchar_t *v7; // ST54_4

  v3 = malloc(2u);
  *v3 = 0;
  v4 = (CCmdString *)a3;
  v5 = sub_BFA120(a1, a2, *(wchar_t **)a3, (void *)0xFFFFFFFF);
  v6 = CCmdString::operator+((CCmdString *)&a3, v4, L"\\AutorunsDisabled");
  v7 = _wcsdup(v6->m_String);
  free(v3);
  free(a3);
  sub_BFA120(a1, a2, v7, v5);
  free(v7);
}

//----- (00BFA120) --------------------------------------------------------
void *__cdecl sub_BFA120(int a1, void *a2, wchar_t *psz, void *a4)
{
  const wchar_t *v4; // eax
  const wchar_t *v5; // eax
  CCmdString *v6; // esi
  CCmdString *v7; // eax
  unsigned int v8; // eax
  void (__stdcall *RegCloseKey)(HKEY); // ebx
  LPVOID (__stdcall *TlsGetValue)(DWORD); // edi
  CCmdString *v11; // eax
  WCHAR *v12; // esi
  const WCHAR *v13; // esi
  unsigned int v14; // eax
  wchar_t *v15; // esi
  wchar_t *v16; // esi
  unsigned int v17; // eax
  wchar_t *v18; // esi
  CCmdString *v19; // eax
  CCmdString *v20; // eax
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
  CCmdString *v33; // eax
  WCHAR *v34; // edi
  WCHAR *v35; // esi
  const WCHAR *v36; // esi
  unsigned int v37; // eax
  WCHAR *v38; // esi
  const wchar_t *v39; // eax
  const wchar_t *v40; // eax
  CCmdString *v41; // esi
  CCmdString *v42; // eax
  char v43; // bl
  const wchar_t *v44; // eax
  const wchar_t *v45; // eax
  CCmdString *v46; // esi
  CCmdString *v47; // eax
  int v48; // ebx
  const wchar_t *v49; // eax
  WCHAR *v50; // esi
  __int16 *v51; // edx
  __int16 v52; // cx
  const wchar_t *v53; // eax
  CCmdString *v54; // eax
  DWORD v55; // esi
  void **v56; // esi
  WCHAR *v57; // edi
  CCmdString v59; // [esp+10h] [ebp-C4h]
  WCHAR *ppv; // [esp+14h] [ebp-C0h]
  WCHAR v61[2]; // [esp+18h] [ebp-BCh]
  WCHAR v62[2]; // [esp+1Ch] [ebp-B8h]
  int a2a; // [esp+20h] [ebp-B4h]
  WCHAR *pszResult; // [esp+24h] [ebp-B0h]
  int a8; // [esp+28h] [ebp-ACh]
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
  CCmdString str3; // [esp+54h] [ebp-80h]
  void *v77; // [esp+58h] [ebp-7Ch]
  LPCWSTR v78; // [esp+5Ch] [ebp-78h]
  void *v79; // [esp+60h] [ebp-74h]
  void *v80; // [esp+64h] [ebp-70h]
  void *v81; // [esp+68h] [ebp-6Ch]
  CCmdString v82; // [esp+6Ch] [ebp-68h]
  void *v83; // [esp+70h] [ebp-64h]
  WCHAR szArg[2]; // [esp+74h] [ebp-60h]
  HKEY KeyHandle; // [esp+78h] [ebp-5Ch]
  void *a1a; // [esp+7Ch] [ebp-58h]
  void *v87; // [esp+80h] [ebp-54h]
  LPCWSTR v88; // [esp+84h] [ebp-50h]
  CCmdString strKeyName[7]; // [esp+88h] [ebp-4Ch]
  LPCWSTR szArg3; // [esp+A4h] [ebp-30h]
  WCHAR *ppv2; // [esp+A8h] [ebp-2Ch]
  wchar_t *ppszText2; // [esp+ACh] [ebp-28h]
  CCmdString str1; // [esp+B0h] [ebp-24h]
  wchar_t *pszText; // [esp+B4h] [ebp-20h]
  HKEY hKey; // [esp+B8h] [ebp-1Ch]
  LPCWSTR szArg4; // [esp+BCh] [ebp-18h]
  wchar_t *ppv3; // [esp+C0h] [ebp-14h]
  LPCWSTR lpszKeyName; // [esp+C4h] [ebp-10h]
  int v99; // [esp+D0h] [ebp-4h]

  str1.m_String = (WCHAR *)malloc(2u);
  *str1.m_String = 0;
  v99 = 0;
  ppszText2 = (wchar_t *)malloc(2u);
  *ppszText2 = 0;
  v87 = malloc(2u);
  *(_WORD *)v87 = 0;
  v83 = malloc(2u);
  *(_WORD *)v83 = 0;
  v82.m_String = (WCHAR *)malloc(2u);
  *v82.m_String = 0;
  LOBYTE(v99) = 4;
  if ( a4 == (void *)-1 )
  {
    strKeyName[4].m_String = _wcsdup((const wchar_t *)&gszNullString);
    strKeyName[6].m_String = _wcsdup((const wchar_t *)&gszNullString);
    szArg3 = _wcsdup((const wchar_t *)&gszNullString);
    strKeyName[5].m_String = _wcsdup((const wchar_t *)&gszNullString);
    v88 = _wcsdup((const wchar_t *)&gszNullString);
    lpszKeyName = _wcsdup((const wchar_t *)&gszNullString);
    szArg4 = _wcsdup((const wchar_t *)&gszNullString);
    v4 = (const wchar_t *)&gszNullString;
    if ( psz )
      v4 = psz;
    ppv3 = _wcsdup(v4);
    hKey = (HKEY)_wcsdup((const wchar_t *)&gszNullString);
    v5 = (const wchar_t *)&gszNullString;
    if ( psz )
      v5 = psz;
    pszText = _wcsdup(v5);
    LOBYTE(v99) = 14;
    v6 = MakeRegistryKeyName((CCmdString *)&a1a, (HKEY)a2, (CCmdString *)&ppv3, (CCmdString *)&szArg4);
    LOBYTE(v99) = 15;
    v7 = MakeRegistryKeyName((CCmdString *)szArg, (HKEY)a2, (CCmdString *)&pszText, (CCmdString *)&hKey);
    LOBYTE(v99) = 16;
    a4 = (void *)PE_UpdateSystemKey(a1, 0, (HANDLE)0xFFFFFFFF, 0, v7, v6, (CCmdString *)&lpszKeyName);
    free(*(void **)szArg);
    free(a1a);
    free(pszText);
    free(hKey);
    free(ppv3);
    free((void *)szArg4);
    free((void *)lpszKeyName);
    free((void *)v88);
    free(strKeyName[5].m_String);
    free((void *)szArg3);
    free(strKeyName[6].m_String);
    LOBYTE(v99) = 4;
    free(strKeyName[4].m_String);
  }
  v8 = (unsigned int)::TlsGetValue(gdwTlsIndex);
  if ( !PE_OpenKey((HKEY)a2, psz, 0, v8 | 0x20019, &KeyHandle) )
  {
    *(_DWORD *)szArg = 0;
    pszText = (wchar_t *)malloc(2u);
    *pszText = 0;
    lpszKeyName = (LPCWSTR)malloc(2u);
    *lpszKeyName = 0;
    ppv3 = (wchar_t *)malloc(2u);
    *ppv3 = 0;
    szArg4 = (LPCWSTR)malloc(2u);
    *szArg4 = 0;
    strKeyName[0].m_String = (WCHAR *)malloc(2u);
    *strKeyName[0].m_String = 0;
    strKeyName[1].m_String = 0;
    strKeyName[2].m_String = 0;
    strKeyName[3].m_String = 0;
    LOBYTE(v99) = 21;
    RegCloseKey = (void (__stdcall *)(HKEY))::RegCloseKey;
    if ( !PE_LoadRegKeys(KeyHandle, 0, (CCmdString *)&ppszText2) )
    {
      TlsGetValue = ::TlsGetValue;
      do
      {
        v11 = operator+((CCmdString *)&pszResult, L"CLSID\\", (CCmdString *)&ppszText2);
        v12 = (WCHAR *)lpszKeyName;
        lpszKeyName = _wcsdup(v11->m_String);
        free(v12);
        free(pszResult);
        v13 = lpszKeyName;
        v14 = (unsigned int)TlsGetValue(gdwTlsIndex);
        if ( PE_OpenKey(HKEY_CLASSES_ROOT, v13, 0, v14 | 0x20019, &hKey) )
        {
          v16 = ppszText2;
          v17 = (unsigned int)TlsGetValue(gdwTlsIndex);
          if ( PE_OpenKey(KeyHandle, v16, 0, v17 | 0x20019, &hKey) )
            goto LABEL_52;
          if ( PE_ReadRegKey(hKey, (LPCWSTR)&gszNullString, 0, 0, (CCmdString *)&ppv3) )
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
          PE_ReadRegKey(hKey, (LPCWSTR)&gszNullString, 0, 0, (CCmdString *)&pszText);
        }
        RegCloseKey(hKey);
        v19 = operator+(&v59, L"CLSID\\", (CCmdString *)&ppv3);
        v20 = CCmdString::operator+((CCmdString *)&ppv, v19, L"\\InprocServer32");
        v21 = (WCHAR *)lpszKeyName;
        lpszKeyName = _wcsdup(v20->m_String);
        free(v21);
        free(ppv);
        free(v59.m_String);
        v22 = lpszKeyName;
        v23 = (unsigned int)TlsGetValue(gdwTlsIndex);
        if ( !PE_OpenKey(HKEY_CLASSES_ROOT, v22, 0, v23 | 0x20019, &hKey) )
        {
          if ( !PE_ReadRegKey(hKey, L"CodeBase", 0, 0, (CCmdString *)&lpszKeyName) )
          {
            if ( !wcscspn(lpszKeyName, L"file:////") )
            {
              v24 = (const wchar_t *)&gszNullString;
              if ( lpszKeyName != (LPCWSTR)-18 )
                v24 = lpszKeyName + 9;
              v25 = _wcsdup(v24);
              v26 = (WCHAR *)lpszKeyName;
              v27 = v25;
              lpszKeyName = _wcsdup(v25);
              free(v26);
              free(v27);
            }
            sub_BE7040((wchar_t *)lpszKeyName, (StringItem *)strKeyName);
            v28 = (const wchar_t **)sub_BE4EE0((int)&v71, a1, (int)strKeyName, 0);
            v29 = (WCHAR *)szArg4;
            szArg4 = _wcsdup(*v28);
            free(v29);
            free((void *)v71);
            goto LABEL_24;
          }
          if ( !PE_ReadRegKey(hKey, (LPCWSTR)&gszNullString, 0, 0, (CCmdString *)&lpszKeyName) )
          {
            sub_BE7040((wchar_t *)lpszKeyName, (StringItem *)strKeyName);
            v30 = (const wchar_t **)sub_BE4EE0((int)&v68, a1, (int)strKeyName, 0);
            v31 = (WCHAR *)szArg4;
            szArg4 = _wcsdup(*v30);
            free(v31);
            free(v68);
LABEL_24:
            RegCloseKey(hKey);
            a2a = sub_BE4ED0();
            v32 = _wcsdup(L"CLSID\\");
            ppv2 = v32;
            v33 = CCmdString::Append((CCmdString *)&ppv1, (CCmdString *)&ppv2, (CCmdString *)&ppv3);
            v34 = (WCHAR *)lpszKeyName;
            lpszKeyName = _wcsdup(v33->m_String);
            free(v34);
            free(ppv1);
            free(v32);
            operator+((CCmdString *)&a1a, L"HKCR\\CLSID\\", (CCmdString *)&ppv3);
            v35 = str1.m_String;
            LOBYTE(v99) = 22;
            str1.m_String = _wcsdup(ppv3);
            free(v35);
            v36 = lpszKeyName;
            v37 = (unsigned int)::TlsGetValue(gdwTlsIndex);
            if ( !PE_OpenKey(HKEY_CLASSES_ROOT, v36, 0, v37 | 0x20019, &hKey) )
            {
              if ( !PE_ReadRegKey(hKey, (LPCWSTR)&gszNullString, 0, 0, (CCmdString *)&lpszKeyName)
                && wcslen(lpszKeyName) )
              {
                v38 = str1.m_String;
                str1.m_String = _wcsdup(lpszKeyName);
                free(v38);
              }
              RegCloseKey(hKey);
            }
            v39 = (const wchar_t *)&gszNullString;
            if ( psz )
              v39 = psz;
            szArg3 = _wcsdup(v39);
            strKeyName[6].m_String = _wcsdup((const wchar_t *)&gszNullString);
            v40 = (const wchar_t *)&gszNullString;
            if ( psz )
              v40 = psz;
            strKeyName[4].m_String = _wcsdup(v40);
            LOBYTE(v99) = 25;
            v41 = MakeRegistryKeyName((CCmdString *)v70, (HKEY)a2, (CCmdString *)&szArg3, (CCmdString *)&ppszText2);
            LOBYTE(v99) = 26;
            v42 = MakeRegistryKeyName((CCmdString *)v62, (HKEY)a2, &strKeyName[4], &strKeyName[6]);
            LOBYTE(v99) = 27;
            v43 = sub_BE3D40(
                    a1,
                    (CCmdString)&str1,
                    (int)v42,
                    (int)v41,
                    (int)&szArg4,
                    (int)&v87,
                    (CCmdString)&v82,
                    (int)&a8);
            free(*(void **)v62);
            free(*(void **)v70);
            free(strKeyName[4].m_String);
            free(strKeyName[6].m_String);
            free((void *)szArg3);
            if ( v43 )
            {
              if ( a4 == (void *)-1 )
              {
                v77 = _wcsdup((const wchar_t *)&gszNullString);
                v75 = _wcsdup((const wchar_t *)&gszNullString);
                v81 = _wcsdup((const wchar_t *)&gszNullString);
                v79 = _wcsdup((const wchar_t *)&gszNullString);
                v72 = _wcsdup((const wchar_t *)&gszNullString);
                str3.m_String = _wcsdup((const wchar_t *)&gszNullString);
                v78 = _wcsdup((const wchar_t *)&gszNullString);
                v44 = (const wchar_t *)&gszNullString;
                if ( psz )
                  v44 = psz;
                v74 = _wcsdup(v44);
                v88 = _wcsdup((const wchar_t *)&gszNullString);
                v45 = (const wchar_t *)&gszNullString;
                if ( psz )
                  v45 = psz;
                strKeyName[5].m_String = _wcsdup(v45);
                LOBYTE(v99) = 37;
                v46 = MakeRegistryKeyName((CCmdString *)v67, (HKEY)a2, (CCmdString *)&v74, (CCmdString *)&v78);
                LOBYTE(v99) = 38;
                v47 = MakeRegistryKeyName((CCmdString *)v69, (HKEY)a2, &strKeyName[5], (CCmdString *)&v88);
                LOBYTE(v99) = 39;
                v48 = a1;
                a4 = (void *)PE_UpdateSystemKey(a1, 0, (HANDLE)0xFFFFFFFF, 0, v47, v46, &str3);
                free(*(void **)v69);
                free(*(void **)v67);
                free(strKeyName[5].m_String);
                free((void *)v88);
                free((void *)v74);
                free((void *)v78);
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
                v49 = (const wchar_t *)v83;
                v51 = (__int16 *)v83;
                ppv2 = (WCHAR *)((char *)v83 + 2);
                do
                {
                  v52 = *v51;
                  ++v51;
                }
                while ( v52 );
                if ( ((char *)v51 - (char *)ppv2) >> 1 )
                {
LABEL_63:
                  str1.m_String = _wcsdup(v49);
                  free(v50);
                }
              }
              v80 = _wcsdup((const wchar_t *)&gszNullString);
              v53 = (const wchar_t *)&gszNullString;
              if ( psz )
                v53 = psz;
              v73 = _wcsdup(v53);
              LOBYTE(v99) = 41;
              v54 = MakeRegistryKeyName((CCmdString *)v61, (HKEY)a2, (CCmdString *)&v73, (CCmdString *)&ppszText2);
              LOBYTE(v99) = 42;
              PE_UpdateSystemKey(v48, a2a, a4, 3u, &str1, v54, (CCmdString *)&szArg4);
              free(*(void **)v61);
              free((void *)v73);
              free(v80);
            }
            free(a1a);
            StringItem::~StringItem((tagPEStringStruct *)strKeyName);
            free((void *)szArg4);
            free(ppv3);
            free((void *)lpszKeyName);
            free(pszText);
            RegCloseKey = (void (__stdcall *)(HKEY))::RegCloseKey;
            TlsGetValue = ::TlsGetValue;
            goto LABEL_53;
          }
LABEL_51:
          RegCloseKey(hKey);
        }
LABEL_52:
        StringItem::~StringItem((tagPEStringStruct *)strKeyName);
        free((void *)szArg4);
        free(ppv3);
        free((void *)lpszKeyName);
        free(pszText);
LABEL_53:
        v55 = ++*(_DWORD *)szArg;
        pszText = (wchar_t *)malloc(2u);
        *pszText = 0;
        lpszKeyName = (LPCWSTR)malloc(2u);
        *lpszKeyName = 0;
        ppv3 = (wchar_t *)malloc(2u);
        *ppv3 = 0;
        szArg4 = (LPCWSTR)malloc(2u);
        *szArg4 = 0;
        strKeyName[0].m_String = (WCHAR *)malloc(2u);
        *strKeyName[0].m_String = 0;
        strKeyName[1].m_String = 0;
        strKeyName[2].m_String = 0;
        strKeyName[3].m_String = 0;
        LOBYTE(v99) = 21;
      }
      while ( !PE_LoadRegKeys(KeyHandle, v55, (CCmdString *)&ppszText2) );
    }
    v56 = (void **)strKeyName[1].m_String;
    if ( strKeyName[1].m_String )
    {
      v57 = strKeyName[2].m_String;
      if ( strKeyName[1].m_String != strKeyName[2].m_String )
      {
        do
        {
          free(*v56);
          ++v56;
        }
        while ( v56 != (void **)v57 );
        v56 = (void **)strKeyName[1].m_String;
      }
      operator delete(v56);
      strKeyName[1].m_String = 0;
      strKeyName[2].m_String = 0;
      strKeyName[3].m_String = 0;
    }
    free(strKeyName[0].m_String);
    free((void *)szArg4);
    free(ppv3);
    free((void *)lpszKeyName);
    free(pszText);
    RegCloseKey(KeyHandle);
  }
  free(v82.m_String);
  free(v83);
  free(v87);
  free(ppszText2);
  free(str1.m_String);
  return a4;
}

//----- (00BFAC50) --------------------------------------------------------
int __stdcall cbstrList::getInstance(int a1, int arg4, int a2)
{
  int result; // eax
  int v4; // esi

  result = (int)cbstrList::cbstrList((_DWORD *)a1, (_DWORD *)arg4);
  v4 = result;
  if ( result != -8 )
  {
    tagPEStringStruct::tagPEStringStruct((tagPEStringStruct *)(result + 8), a2);
    result = v4;
  }
  return result;
}

//----- (00BFAC80) --------------------------------------------------------
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
  this->strValue[0] = *(_DWORD *)a2;
  LOBYTE(this->strValue[1]) = *(_BYTE *)(a2 + 4);
  v3 = *(_DWORD *)(a2 + 8);
  this->strValue[2] = v3;
  if ( v3 )
    InterlockedIncrement((volatile LONG *)(v3 + 8));
  v4 = *(_DWORD *)(a2 + 12);
  v2->strValue[3] = v4;
  if ( v4 )
    InterlockedIncrement((volatile LONG *)(v4 + 8));
  v5 = *(_DWORD *)(a2 + 16);
  v2->strValue[4] = v5;
  if ( v5 )
    InterlockedIncrement((volatile LONG *)(v5 + 8));
  v6 = *(_DWORD *)(a2 + 20);
  v2->strValue[5] = v6;
  if ( v6 )
    InterlockedIncrement((volatile LONG *)(v6 + 8));
  v7 = *(_DWORD *)(a2 + 24);
  v2->strValue[6] = v7;
  if ( v7 )
    InterlockedIncrement((volatile LONG *)(v7 + 8));
  v8 = *(_DWORD *)(a2 + 28);
  v2[1].strValue[0] = v8;
  if ( v8 )
    InterlockedIncrement((volatile LONG *)(v8 + 8));
  v9 = *(_DWORD *)(a2 + 32);
  v2[1].strValue[1] = v9;
  if ( v9 )
    InterlockedIncrement((volatile LONG *)(v9 + 8));
  return v2;
}

//----- (00BFAD20) --------------------------------------------------------
// _bstr_t::_bstr_t(const _variant_t &var)
EventItem *__thiscall _bstr_t::_bstr_t(_bstr_t *this, VARIANTARG *pvarSrc)
{
  EventItem *v2; // esi
  int v3; // eax
  VARIANTARG pvarg; // [esp+Ch] [ebp-1Ch]
  int v6; // [esp+24h] [ebp-4h]

  v2 = (EventItem *)this;
  this->m_Data = 0;
  if ( pvarSrc->vt == VT_BSTR )
  {
    _bstr_t::operator=((EventItem *)this, pvarSrc->bstrVal);
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

//----- (00BFADD0) --------------------------------------------------------
_bstr_t *__thiscall _bstr_t::_bstr_t(_bstr_t *this, LPCSTR lpString)
{
  _bstr_t *v2; // edi
  Data_t_bstr_t *v3; // eax
  Data_t_bstr_t *v4; // esi

  v2 = this;
  v3 = (Data_t_bstr_t *)operator new(0xCu);
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

//----- (00BFAE80) --------------------------------------------------------
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
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 8)) && v3 )
    {
      if ( *(_DWORD *)v3 )
      {
        SysFreeString(*(BSTR *)v3);
        *(_DWORD *)v3 = 0;
      }
      if ( *(_DWORD *)(v3 + 4) )
      {
        operator delete[](*(void **)(v3 + 4));
        *(_DWORD *)(v3 + 4) = 0;
      }
      operator delete((void *)v3);
    }
    v2 = InterlockedDecrement;
    v1[1].strValue[1] = 0;
  }
  v4 = v1[1].strValue[0];
  if ( v4 )
  {
    if ( !v2((volatile LONG *)(v4 + 8)) && v4 )
    {
      if ( *(_DWORD *)v4 )
      {
        SysFreeString(*(BSTR *)v4);
        *(_DWORD *)v4 = 0;
      }
      if ( *(_DWORD *)(v4 + 4) )
      {
        operator delete[](*(void **)(v4 + 4));
        *(_DWORD *)(v4 + 4) = 0;
      }
      operator delete((void *)v4);
    }
    v1[1].strValue[0] = 0;
  }
  v5 = v1->strValue[6];
  if ( v5 )
  {
    if ( !InterlockedDecrement((volatile LONG *)(v5 + 8)) && v5 )
    {
      if ( *(_DWORD *)v5 )
      {
        SysFreeString(*(BSTR *)v5);
        *(_DWORD *)v5 = 0;
      }
      if ( *(_DWORD *)(v5 + 4) )
      {
        operator delete[](*(void **)(v5 + 4));
        *(_DWORD *)(v5 + 4) = 0;
      }
      operator delete((void *)v5);
    }
    v1->strValue[6] = 0;
  }
  v6 = v1->strValue[5];
  if ( v6 )
  {
    if ( !InterlockedDecrement((volatile LONG *)(v6 + 8)) && v6 )
    {
      if ( *(_DWORD *)v6 )
      {
        SysFreeString(*(BSTR *)v6);
        *(_DWORD *)v6 = 0;
      }
      if ( *(_DWORD *)(v6 + 4) )
      {
        operator delete[](*(void **)(v6 + 4));
        *(_DWORD *)(v6 + 4) = 0;
      }
      operator delete((void *)v6);
    }
    v1->strValue[5] = 0;
  }
  v7 = v1->strValue[4];
  if ( v7 )
  {
    if ( !InterlockedDecrement((volatile LONG *)(v7 + 8)) && v7 )
    {
      if ( *(_DWORD *)v7 )
      {
        SysFreeString(*(BSTR *)v7);
        *(_DWORD *)v7 = 0;
      }
      if ( *(_DWORD *)(v7 + 4) )
      {
        operator delete[](*(void **)(v7 + 4));
        *(_DWORD *)(v7 + 4) = 0;
      }
      operator delete((void *)v7);
    }
    v1->strValue[4] = 0;
  }
  v8 = v1->strValue[3];
  if ( v8 )
  {
    if ( !InterlockedDecrement((volatile LONG *)(v8 + 8)) && v8 )
    {
      if ( *(_DWORD *)v8 )
      {
        SysFreeString(*(BSTR *)v8);
        *(_DWORD *)v8 = 0;
      }
      if ( *(_DWORD *)(v8 + 4) )
      {
        operator delete[](*(void **)(v8 + 4));
        *(_DWORD *)(v8 + 4) = 0;
      }
      operator delete((void *)v8);
    }
    v1->strValue[3] = 0;
  }
  v9 = v1->strValue[2];
  if ( v9 )
  {
    if ( !InterlockedDecrement((volatile LONG *)(v9 + 8)) && v9 )
    {
      if ( *(_DWORD *)v9 )
      {
        SysFreeString(*(BSTR *)v9);
        *(_DWORD *)v9 = 0;
      }
      if ( *(_DWORD *)(v9 + 4) )
      {
        operator delete[](*(void **)(v9 + 4));
        *(_DWORD *)(v9 + 4) = 0;
      }
      operator delete((void *)v9);
    }
    v1->strValue[2] = 0;
  }
}

//----- (00BFB0D0) --------------------------------------------------------
Data_t_bstr_t *__thiscall _bstr_t::Assign(_bstr_t *this, wchar_t *s)
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
        operator delete[](v3->m_str);
        v3->m_str = 0;
      }
      operator delete(v3);
    }
    v2->m_Data = 0;
  }
  result = (Data_t_bstr_t *)operator new(0xCu);
  if ( result )
  {
    result->m_str = 0;
    result->m_RefCount = 1;
    result->m_wstr = s;
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

//----- (00BFB1A0) --------------------------------------------------------
char __cdecl PE_LoadConfig(_bstr_t *bstrConfigFile, std__List *pList)
{
  HMODULE v2; // eax
  HMODULE v3; // eax
  int v4; // esi
  int v5; // edi
  const WCHAR *pszFileName; // eax
  std__list_node *v7; // eax
  std__list_node *v8; // ecx
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
  IXMLDOMNodeList *v19; // esi
  IXMLDOMNode *v20; // esi
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
  Data_t_bstr_t *v43; // esi
  IXMLDOMParseError *v44; // esi
  HMODULE v45; // eax
  FARPROC v46; // eax
  HANDLE v47; // eax
  wchar_t *v48; // edx
  WCHAR *v49; // ST70_4
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
  const wchar_t *v72; // eax
  void *v73; // eax
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
  const wchar_t *v97; // eax
  Data_t_bstr_t *v98; // eax
  IXMLDOMParseErrorVtbl *v99; // eax
  IXMLDOMParseError *v100; // ecx
  IXMLDOMParseError *v101; // eax
  _bstr_t *v102; // eax
  void **v103; // eax
  IXMLDOMParseError *v104; // eax
  const wchar_t *v105; // eax
  Data_t_bstr_t *v106; // eax
  IXMLDOMParseErrorVtbl *v107; // eax
  IXMLDOMParseError *v108; // ecx
  IXMLDOMParseError *v109; // eax
  _bstr_t *v110; // eax
  void **v111; // eax
  IXMLDOMParseError *v112; // eax
  const wchar_t *v113; // eax
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
  const OLECHAR *v132; // ST54_4
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
  OLECHAR *v143; // ST50_4
  HRESULT hresult; // eax
  LONG v145; // eax
  IXMLDOMParseError *v146; // eax
  Data_t_bstr_t *v147; // eax
  IXMLDOMParseErrorVtbl *v148; // eax
  IXMLDOMParseError *v149; // edx
  OLECHAR *v150; // ST50_4
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
  _bstr_t v212; // [esp+7Ch] [ebp-554h]
  _bstr_t a3; // [esp+80h] [ebp-550h]
  _bstr_t v214; // [esp+84h] [ebp-54Ch]
  _bstr_t v215; // [esp+88h] [ebp-548h]
  _bstr_t v216; // [esp+8Ch] [ebp-544h]
  IXMLDOMNode *pIXMLDOMNode3; // [esp+90h] [ebp-540h]
  int v218; // [esp+94h] [ebp-53Ch]
  _bstr_t bstrSectionName_1; // [esp+98h] [ebp-538h]
  _bstr_t bstrDisabled; // [esp+9Ch] [ebp-534h]
  IXMLDOMNamedNodeMap *pIXMLDOMNamedNodeMap; // [esp+A0h] [ebp-530h]
  _bstr_t v222; // [esp+A4h] [ebp-52Ch]
  DWORD NumberOfBytesRead; // [esp+A8h] [ebp-528h]
  _bstr_t bstrRet; // [esp+ACh] [ebp-524h]
  _bstr_t v225; // [esp+B0h] [ebp-520h]
  void *v226; // [esp+B4h] [ebp-51Ch]
  _bstr_t v227; // [esp+B8h] [ebp-518h]
  _bstr_t bstrSectionName_2; // [esp+BCh] [ebp-514h]
  _bstr_t v229; // [esp+C0h] [ebp-510h]
  int vtFlags; // [esp+C4h] [ebp-50Ch]
  std__List *v231; // [esp+C8h] [ebp-508h]
  tagPEStringStruct StringItem; // [esp+CCh] [ebp-504h]
  _bstr_t v233; // [esp+E8h] [ebp-4E8h]
  _bstr_t v234; // [esp+ECh] [ebp-4E4h]
  int v235; // [esp+F0h] [ebp-4E0h]
  IXMLDOMDocument *pIXMLDOMDocument; // [esp+F4h] [ebp-4DCh]
  tagPEConfigFile *pConfigFile_1; // [esp+F8h] [ebp-4D8h]
  void *nLineNumber; // [esp+FCh] [ebp-4D4h]
  IXMLDOMNodeList *pIXMLDOMNodeList; // [esp+100h] [ebp-4D0h]
  IXMLDOMNode *pIXMLDOMNode; // [esp+104h] [ebp-4CCh]
  IXMLDOMNode *bstrResult; // [esp+108h] [ebp-4C8h]
  _bstr_t bstrTemp; // [esp+10Ch] [ebp-4C4h]
  std__List *theDwordList; // [esp+110h] [ebp-4C0h]
  int v244; // [esp+114h] [ebp-4BCh]
  std__List *v245; // [esp+118h] [ebp-4B8h]
  int v246; // [esp+11Ch] [ebp-4B4h]
  _bstr_t *bstrDisabled_1; // [esp+120h] [ebp-4B0h]
  IXMLDOMNamedNodeMap *pIXMLDOMNamedNodeMap2; // [esp+124h] [ebp-4ACh]
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

  pConfigFile_1 = (tagPEConfigFile *)bstrConfigFile;
  v231 = pList;
  if ( !GetSystemDefaultLocaleName )
  {
    v2 = LoadLibraryW(L"Kernel32.dll");
    GetSystemDefaultLocaleName = (int (__stdcall *)(_DWORD, _DWORD))GetProcAddress(v2, "GetSystemDefaultLocaleName");
    v3 = LoadLibraryW(L"Kernel32.dll");
    GetUserDefaultLocaleName = (int (__stdcall *)(_DWORD, _DWORD))GetProcAddress(v3, "GetUserDefaultLocaleName");
  }
  sub_BFE360(pList);
  v4 = 0;
  v244 = 0;
  theDwordList = (std__List *)std::_List_alloc<std::_List_base_types<tagEventItem *,std::allocator<tagEventItem *>>>::_Buynode0(
                                0,
                                0);
  v5 = 0;
  nStep = 0;
  _swprintf((wchar_t *)szSectioName, L"Section%d", 0);
  szValue[0] = 0;
  memset(&szValue[1], 0, 0x206u);
  pszFileName = (const WCHAR *)tagPEConfigFile::GetFileName(pConfigFile_1);
  if ( GetPrivateProfileStringW(
         L"Root",
         (LPCWSTR)szSectioName,
         (LPCWSTR)&gszNullString,
         (LPWSTR)szValue,
         0x104u,
         pszFileName) )
  {
    do
    {
      bstrDisabled_1 = (_bstr_t *)_wtoi((const wchar_t *)szValue);
      v7 = std::_List_buy<tagEventItem *,std::allocator<tagEventItem *>>::_Buynode<tagEventItem * const &>(
             (EventList *)theDwordList,
             (_DWORD *)theDwordList->_Mypair._Myval2._Mysize,
             &bstrDisabled_1);
      if ( (unsigned int)(357913940 - v4) < 1 )
LABEL_10:
        std::_Xlength_error("list<T> too long");
      ++v5;
      ++v4;
      theDwordList->_Mypair._Myval2._Mysize = (unsigned int)v7;
      v8 = v7->_Prev;
      v244 = v4;
      v8->_Next = v7;
      _swprintf((wchar_t *)szSectioName, L"Section%d", v5);
      szValue[0] = 0;
      memset(&szValue[1], 0, 0x206u);
      v9 = (const WCHAR *)tagPEConfigFile::GetFileName(pConfigFile_1);
    }
    while ( GetPrivateProfileStringW(
              L"Root",
              (LPCWSTR)szSectioName,
              (LPCWSTR)&gszNullString,
              (LPWSTR)szValue,
              0x104u,
              v9) );
  }
  pIXMLDOMNamedNodeMap2 = 0;
  bstrTemp.m_Data = (Data_t_bstr_t *)-1;
  while ( 1 )
  {
    szValue[0] = 0;
    memset(&szValue[1], 0, 0x206u);
    v10 = (Data_t_bstr_t *)operator new(0xCu);
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
    bstrDisabled_1 = (_bstr_t *)v11;
    if ( !v11 )
LABEL_9:
      _com_issue_error(E_OUTOFMEMORY);
    LOBYTE(nStep) = 2;
    // _bstr_t bstrResult = bstrConfigFile + bstrDisabled;
    v13 = (const WCHAR ***)_bstr_t::operator+(
                             (_bstr_t *)pConfigFile_1,
                             (_bstr_t *)&bstrResult,
                             (_bstr_t *)&bstrDisabled_1);
    LOBYTE(nStep) = 3;
    v14 = MakeSectionName((_bstr_t *)&pIXMLDOMNodeList, (int)pIXMLDOMNamedNodeMap2);
    if ( *v13 )
      pszConfigFile = **v13;
    else
      pszConfigFile = 0;
    v16 = (const WCHAR **)&v14->m_Data->m_wstr;
    if ( v16 )
      pszSectionName = *v16;
    else
      pszSectionName = 0;
    dwRet = GetPrivateProfileStringW(
              pszSectionName,
              L"PrivateSetting_GadgetName",
              (LPCWSTR)&gszNullString,
              (LPWSTR)szValue,
              0x104u,
              pszConfigFile);
    v19 = pIXMLDOMNodeList;
    v257 = dwRet == 0;
    if ( pIXMLDOMNodeList )
    {
      if ( !InterlockedDecrement((volatile LONG *)&pIXMLDOMNodeList[2]) && v19 )
      {
        if ( v19->lpVtbl )
        {
          SysFreeString((BSTR)v19->lpVtbl);
          v19->lpVtbl = 0;
        }
        if ( v19[1].lpVtbl )
        {
          operator delete[](v19[1].lpVtbl);
          v19[1].lpVtbl = 0;
        }
        operator delete(v19);
      }
      pIXMLDOMNodeList = 0;
    }
    v20 = bstrResult;
    if ( bstrResult )
    {
      if ( !InterlockedDecrement((volatile LONG *)&bstrResult[2]) && v20 )
      {
        if ( v20->lpVtbl )
        {
          SysFreeString((BSTR)v20->lpVtbl);
          v20->lpVtbl = 0;
        }
        if ( v20[1].lpVtbl )
        {
          operator delete[](v20[1].lpVtbl);
          v20[1].lpVtbl = 0;
        }
        operator delete(v20);
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
        operator delete[](v11->m_str);
        v11->m_str = 0;
      }
      operator delete(v11);
    }
    if ( v257 )
      break;
    v21 = bstrTemp.m_Data;
    bstrDisabled_1 = (_bstr_t *)bstrTemp.m_Data;
    v22 = std::_List_buy<tagEventItem *,std::allocator<tagEventItem *>>::_Buynode<tagEventItem * const &>(
            (EventList *)theDwordList,
            (_DWORD *)theDwordList->_Mypair._Myval2._Mysize,
            &bstrDisabled_1);
    if ( (unsigned int)(357913940 - v244) < 1 )
      goto LABEL_10;
    pIXMLDOMNamedNodeMap2 = (IXMLDOMNamedNodeMap *)((char *)pIXMLDOMNamedNodeMap2 + 1);
    ++v244;
    bstrTemp.m_Data = (Data_t_bstr_t *)((char *)v21 - 1);
    theDwordList->_Mypair._Myval2._Mysize = (unsigned int)v22;
    v22->_Prev->_Next = v22;
  }
  v23 = (std__List *)theDwordList->_Mypair._Myval2._Myhead;
  v245 = v23;
  if ( v23 != theDwordList )
  {
    while ( 1 )
    {
      StringItem.strValue[6] = 0;
      _mm_storeu_si128((__m128i *)&StringItem.strValue[2], (__m128i)0i64);
      v233.m_Data = 0;
      v234.m_Data = 0;
      dwSectionID = v23[1]._Mypair._Myval2._Myhead;
      szValue[0] = 0;
      LOBYTE(nStep) = 4;
      nLinePosition = dwSectionID;
      StringItem.strValue[0] = (int)dwSectionID;
      memset(&szValue[1], 0, 0x206u);
      if ( (signed int)dwSectionID < 0 )
      {
        LOBYTE(StringItem.strValue[1]) = 0;
      }
      else
      {
        v25 = MakeSectionName(&bstrSectionName_1, (int)dwSectionID);
        if ( v25->m_Data )
          v26 = v25->m_Data->m_wstr;
        else
          v26 = 0;
        v27 = (const WCHAR *)tagPEConfigFile::GetFileName(pConfigFile_1);
        GetPrivateProfileStringW(v26, L"PrivateSetting_Enabled", (LPCWSTR)&gszNullString, (LPWSTR)szValue, 0x104u, v27);
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
              operator delete[](v28->m_str);
              v28->m_str = 0;
            }
            operator delete(v28);
          }
          bstrSectionName_1.m_Data = 0;
        }
        v29 = _wcsicmp((const wchar_t *)szValue, L"false");
        dwSectionID = nLinePosition;
        LOBYTE(StringItem.strValue[1]) = v29 != 0;
      }
      szValue[0] = 0;
      if ( (signed int)dwSectionID < 0 )
      {
        v34 = (IXMLDOMParseError *)operator new(0xCu);
        v35 = (Data_t_bstr_t *)v34;
        pIXMLDOMParseError = v34;
        bstrReason = v34;
        LOBYTE(nStep) = 5;
        if ( v34 )
        {
          v34[1].lpVtbl = 0;
          v34[2].lpVtbl = (IXMLDOMParseErrorVtbl *)1;
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
        v37 = (const WCHAR ***)_bstr_t::operator+((_bstr_t *)pConfigFile_1, &bstrRet, (_bstr_t *)&bstrSourceText);
        LOBYTE(nStep) = 7;
        v38 = MakeSectionName((_bstr_t *)&v226, -1 - (_DWORD)nLinePosition);
        if ( *v37 )
          v39 = **v37;
        else
          v39 = 0;
        v40 = (const WCHAR **)&v38->m_Data->m_wstr;
        if ( v40 )
          v41 = *v40;
        else
          v41 = 0;
        GetPrivateProfileStringW(
          v41,
          L"PrivateSetting_GadgetName",
          (LPCWSTR)&gszNullString,
          (LPWSTR)szValue,
          0x104u,
          v39);
        v42 = v226;
        if ( v226 )
        {
          if ( !InterlockedDecrement((volatile LONG *)v226 + 2) && v42 )
          {
            if ( *(_DWORD *)v42 )
            {
              SysFreeString(*(BSTR *)v42);
              *(_DWORD *)v42 = 0;
            }
            if ( *((_DWORD *)v42 + 1) )
            {
              operator delete[](*((void **)v42 + 1));
              *((_DWORD *)v42 + 1) = 0;
            }
            operator delete(v42);
          }
          v226 = 0;
        }
        v43 = bstrRet.m_Data;
        if ( bstrRet.m_Data )
        {
          if ( !InterlockedDecrement(&bstrRet.m_Data->m_RefCount) && v43 )
          {
            if ( v43->m_wstr )
            {
              SysFreeString(v43->m_wstr);
              v43->m_wstr = 0;
            }
            if ( v43->m_str )
            {
              operator delete[](v43->m_str);
              v43->m_str = 0;
            }
            operator delete(v43);
          }
          bstrRet.m_Data = 0;
        }
        v44 = pIXMLDOMParseError;
        LOBYTE(nStep) = 4;
        if ( !InterlockedDecrement((volatile LONG *)&pIXMLDOMParseError[2]) )
        {
          if ( v44->lpVtbl )
          {
            SysFreeString((BSTR)v44->lpVtbl);
            v44->lpVtbl = 0;
          }
          if ( v44[1].lpVtbl )
          {
            operator delete[](v44[1].lpVtbl);
            v44[1].lpVtbl = 0;
          }
          operator delete(v44);
        }
      }
      else
      {
        v30 = MakeSectionName(&bstrSectionName_2, (int)dwSectionID);
        if ( v30->m_Data )
          v31 = v30->m_Data->m_wstr;
        else
          v31 = 0;
        v32 = (const WCHAR *)tagPEConfigFile::GetFileName(pConfigFile_1);
        GetPrivateProfileStringW(
          v31,
          L"PrivateSetting_GadgetName",
          (LPCWSTR)&gszNullString,
          (LPWSTR)szValue,
          0x104u,
          v32);
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
              operator delete[](v33->m_str);
              v33->m_str = 0;
            }
            operator delete(v33);
          }
          bstrSectionName_2.m_Data = 0;
        }
      }
      pcchUnescaped = 260;
      UrlUnescapeW((LPWSTR)szValue, 0, &pcchUnescaped, 0x100000u);
      if ( dword_CD4C68 & 1 )
      {
        v46 = (FARPROC)IsWow64Process;
      }
      else
      {
        dword_CD4C68 |= 1u;
        v45 = GetModuleHandleW(L"kernel32");
        v46 = GetProcAddress(v45, "IsWow64Process");
        IsWow64Process = (int (__stdcall *)(_DWORD, _DWORD))v46;
      }
      v218 = 0;
      if ( v46 )
      {
        v47 = GetCurrentProcess();
        if ( IsWow64Process(v47, &v218) )
        {
          if ( v218 )
          {
            v48 = wcsstr((const wchar_t *)szValue, L"%PROGRAMFILES%");
            if ( v48 )
            {
              v196 = *(_DWORD *)L"2";
              _mm_storeu_si128((__m128i *)&v194, _mm_loadu_si128((const __m128i *)L"%ProgramW6432"));
              v195 = *(_QWORD *)L"W6432";
              memmove_0(v48, &v194, 2 * wcslen((const unsigned __int16 *)&v194));
            }
          }
        }
      }
      v49 = RequerySystemEnvironmentString((CCmdString *)&ppstr, (CCmdString *)szValue)->m_String;
      LOBYTE(nStep) = 8;
      _bstr_t::operator=((EventItem *)&StringItem.strValue[2], v49);
      free(ppstr);
      EventItem = 0;
      v50 = 0;
      v250 = 0;
      LOBYTE(nStep) = 10;
      if ( !GetUserDefaultLocaleName(szLocalName, 260) )
        goto LABEL_532;
      v51 = (IXMLDOMParseError *)operator new(0xCu);
      pIXMLDOMParseError = v51;
      bstrReason = v51;
      LOBYTE(nStep) = 11;
      if ( v51 )
      {
        v51[1].lpVtbl = 0;
        v51[2].lpVtbl = (IXMLDOMParseErrorVtbl *)1;
        v52 = (IXMLDOMParseErrorVtbl *)SysAllocString(L"\\Gadget.xml");
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
      v55 = (Data_t_bstr_t *)operator new(0xCu);
      nNumberOfBytesToRead = v55;
      nLineNumber = v55;
      LOBYTE(nStep) = 13;
      if ( v55 )
      {
        v55->m_str = 0;
        v55->m_RefCount = 1;
        v56 = SysAllocString((const OLECHAR *)szLocalName);
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
      v59 = (Data_t_bstr_t *)operator new(0xCu);
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
      v63 = _bstr_t::operator+((_bstr_t *)&StringItem.strValue[2], &v212, (_bstr_t *)&nLinePosition);
      LOBYTE(nStep) = 17;
      v64 = _bstr_t::operator+(v63, &v214, (_bstr_t *)&nLineNumber);
      LOBYTE(nStep) = 18;
      v65 = _bstr_t::operator+(v64, &v216, (_bstr_t *)&bstrReason);
      if ( &v250 != (Data_t_bstr_t **)v65 )
      {
        v50 = v65->m_Data;
        v250 = v50;
        if ( v50 )
          InterlockedIncrement(&v50->m_RefCount);
      }
      nLinePosition = v216.m_Data;
      if ( v216.m_Data )
      {
        if ( !InterlockedDecrement(&v216.m_Data->m_RefCount) )
        {
          v66 = (void **)nLinePosition;
          if ( nLinePosition )
          {
            if ( *(_DWORD *)nLinePosition )
            {
              SysFreeString(*(BSTR *)nLinePosition);
              v66 = (void **)nLinePosition;
              *(_DWORD *)nLinePosition = 0;
            }
            if ( v66[1] )
            {
              operator delete[](v66[1]);
              v66 = (void **)nLinePosition;
              *((_DWORD *)nLinePosition + 1) = 0;
            }
            operator delete(v66);
          }
        }
        v216.m_Data = 0;
      }
      nLinePosition = v214.m_Data;
      if ( v214.m_Data )
      {
        if ( !InterlockedDecrement(&v214.m_Data->m_RefCount) )
        {
          v67 = (void **)nLinePosition;
          if ( nLinePosition )
          {
            if ( *(_DWORD *)nLinePosition )
            {
              SysFreeString(*(BSTR *)nLinePosition);
              v67 = (void **)nLinePosition;
              *(_DWORD *)nLinePosition = 0;
            }
            if ( v67[1] )
            {
              operator delete[](v67[1]);
              v67 = (void **)nLinePosition;
              *((_DWORD *)nLinePosition + 1) = 0;
            }
            operator delete(v67);
          }
        }
        v214.m_Data = 0;
      }
      nLinePosition = v212.m_Data;
      if ( v212.m_Data )
      {
        if ( !InterlockedDecrement(&v212.m_Data->m_RefCount) )
        {
          v68 = (void **)nLinePosition;
          if ( nLinePosition )
          {
            if ( *(_DWORD *)nLinePosition )
            {
              SysFreeString(*(BSTR *)nLinePosition);
              v68 = (void **)nLinePosition;
              *(_DWORD *)nLinePosition = 0;
            }
            if ( v68[1] )
            {
              operator delete[](v68[1]);
              v68 = (void **)nLinePosition;
              *((_DWORD *)nLinePosition + 1) = 0;
            }
            operator delete(v68);
          }
        }
        v212.m_Data = 0;
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
          operator delete[](v69->m_str);
          v69 = bstrSourceText;
          bstrSourceText->m_str = 0;
        }
        operator delete(v69);
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
          operator delete[](v70->m_str);
          v70 = nNumberOfBytesToRead;
          nNumberOfBytesToRead->m_str = 0;
        }
        operator delete(v70);
      }
      LOBYTE(nStep) = 10;
      if ( !InterlockedDecrement((volatile LONG *)&pIXMLDOMParseError[2]) )
      {
        v71 = pIXMLDOMParseError;
        if ( pIXMLDOMParseError->lpVtbl )
        {
          SysFreeString((BSTR)pIXMLDOMParseError->lpVtbl);
          v71 = pIXMLDOMParseError;
          pIXMLDOMParseError->lpVtbl = 0;
        }
        if ( v71[1].lpVtbl )
        {
          operator delete[](v71[1].lpVtbl);
          v71 = pIXMLDOMParseError;
          pIXMLDOMParseError[1].lpVtbl = 0;
        }
        operator delete(v71);
      }
      v72 = v50 ? v50->m_wstr : 0;
      v73 = PE_OpenFile(v72, 0x80000000, 1u, 0, 3u, 0, 0);
      nLinePosition = v73;
      if ( v73 == (void *)-1 )
      {
LABEL_532:
        if ( !GetSystemDefaultLocaleName(szLocalName, 260) )
          goto LABEL_533;
        v74 = (Data_t_bstr_t *)operator new(0xCu);
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
        v78 = (Data_t_bstr_t *)operator new(0xCu);
        bstrSourceText = v78;
        bstrReason = v78;
        LOBYTE(nStep) = 21;
        if ( v78 )
        {
          v78->m_str = 0;
          v78->m_RefCount = 1;
          v79 = SysAllocString((const OLECHAR *)szLocalName);
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
        v82 = (Data_t_bstr_t *)operator new(0xCu);
        pIXMLDOMParseError = (IXMLDOMParseError *)v82;
        bstrReason = v82;
        LOBYTE(nStep) = 23;
        if ( v82 )
        {
          v82->m_str = 0;
          v82->m_RefCount = 1;
          v83 = (IXMLDOMParseErrorVtbl *)SysAllocString(L"\\");
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
        v86 = _bstr_t::operator+((_bstr_t *)&StringItem.strValue[2], &v229, (_bstr_t *)&bstrReason);
        LOBYTE(nStep) = 25;
        v87 = _bstr_t::operator+(v86, &v222, (_bstr_t *)&nLineNumber);
        LOBYTE(nStep) = 26;
        v88 = _bstr_t::operator+(v87, &v227, (_bstr_t *)&nLinePosition);
        nLinePosition = v88;
        if ( &v250 != (Data_t_bstr_t **)v88 )
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
                operator delete[](v50->m_str);
                v50->m_str = 0;
              }
              operator delete(v50);
            }
            v88 = (_bstr_t *)nLinePosition;
          }
          v50 = v88->m_Data;
          v250 = v50;
          if ( v50 )
            InterlockedIncrement(&v50->m_RefCount);
        }
        nLinePosition = v227.m_Data;
        if ( v227.m_Data )
        {
          if ( !InterlockedDecrement(&v227.m_Data->m_RefCount) )
          {
            v89 = (void **)nLinePosition;
            if ( nLinePosition )
            {
              if ( *(_DWORD *)nLinePosition )
              {
                SysFreeString(*(BSTR *)nLinePosition);
                v89 = (void **)nLinePosition;
                *(_DWORD *)nLinePosition = 0;
              }
              if ( v89[1] )
              {
                operator delete[](v89[1]);
                v89 = (void **)nLinePosition;
                *((_DWORD *)nLinePosition + 1) = 0;
              }
              operator delete(v89);
            }
          }
          v227.m_Data = 0;
        }
        nLinePosition = v222.m_Data;
        if ( v222.m_Data )
        {
          if ( !InterlockedDecrement(&v222.m_Data->m_RefCount) )
          {
            v90 = (void **)nLinePosition;
            if ( nLinePosition )
            {
              if ( *(_DWORD *)nLinePosition )
              {
                SysFreeString(*(BSTR *)nLinePosition);
                v90 = (void **)nLinePosition;
                *(_DWORD *)nLinePosition = 0;
              }
              if ( v90[1] )
              {
                operator delete[](v90[1]);
                v90 = (void **)nLinePosition;
                *((_DWORD *)nLinePosition + 1) = 0;
              }
              operator delete(v90);
            }
          }
          v222.m_Data = 0;
        }
        nLinePosition = v229.m_Data;
        if ( v229.m_Data )
        {
          if ( !InterlockedDecrement(&v229.m_Data->m_RefCount) )
          {
            v91 = (void **)nLinePosition;
            if ( nLinePosition )
            {
              if ( *(_DWORD *)nLinePosition )
              {
                SysFreeString(*(BSTR *)nLinePosition);
                v91 = (void **)nLinePosition;
                *(_DWORD *)nLinePosition = 0;
              }
              if ( v91[1] )
              {
                operator delete[](v91[1]);
                v91 = (void **)nLinePosition;
                *((_DWORD *)nLinePosition + 1) = 0;
              }
              operator delete(v91);
            }
          }
          v229.m_Data = 0;
        }
        if ( !InterlockedDecrement((volatile LONG *)&pIXMLDOMParseError[2]) )
        {
          v92 = pIXMLDOMParseError;
          if ( pIXMLDOMParseError->lpVtbl )
          {
            SysFreeString((BSTR)pIXMLDOMParseError->lpVtbl);
            v92 = pIXMLDOMParseError;
            pIXMLDOMParseError->lpVtbl = 0;
          }
          if ( v92[1].lpVtbl )
          {
            operator delete[](v92[1].lpVtbl);
            v92 = pIXMLDOMParseError;
            pIXMLDOMParseError[1].lpVtbl = 0;
          }
          operator delete(v92);
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
            operator delete[](v93->m_str);
            v93 = bstrSourceText;
            bstrSourceText->m_str = 0;
          }
          operator delete(v93);
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
            operator delete[](v95);
            v96 = nNumberOfBytesToRead;
            nNumberOfBytesToRead->m_str = 0;
          }
          else
          {
            v96 = nNumberOfBytesToRead;
          }
          operator delete(v96);
        }
        v97 = v50 ? v50->m_wstr : 0;
        v73 = PE_OpenFile(v97, 0x80000000, 1u, 0, 3u, 0, 0);
        nLinePosition = v73;
        if ( v73 == (void *)-1 )
        {
LABEL_533:
          v98 = (Data_t_bstr_t *)operator new(0xCu);
          pIXMLDOMParseError = (IXMLDOMParseError *)v98;
          bstrReason = v98;
          LOBYTE(nStep) = 27;
          if ( v98 )
          {
            v98->m_str = 0;
            v98->m_RefCount = 1;
            v99 = (IXMLDOMParseErrorVtbl *)SysAllocString(L"\\en-us\\Gadget.xml");
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
          v102 = _bstr_t::operator+((_bstr_t *)&StringItem.strValue[2], &v225, (_bstr_t *)&bstrReason);
          nLinePosition = v102;
          if ( &v250 != (Data_t_bstr_t **)v102 )
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
                  operator delete[](v50->m_str);
                  v50->m_str = 0;
                }
                operator delete(v50);
              }
              v102 = (_bstr_t *)nLinePosition;
            }
            v50 = v102->m_Data;
            v250 = v50;
            if ( v50 )
              InterlockedIncrement(&v50->m_RefCount);
          }
          nLinePosition = v225.m_Data;
          if ( v225.m_Data )
          {
            if ( !InterlockedDecrement(&v225.m_Data->m_RefCount) )
            {
              v103 = (void **)nLinePosition;
              if ( nLinePosition )
              {
                if ( *(_DWORD *)nLinePosition )
                {
                  SysFreeString(*(BSTR *)nLinePosition);
                  v103 = (void **)nLinePosition;
                  *(_DWORD *)nLinePosition = 0;
                }
                if ( v103[1] )
                {
                  operator delete[](v103[1]);
                  v103 = (void **)nLinePosition;
                  *((_DWORD *)nLinePosition + 1) = 0;
                }
                operator delete(v103);
              }
            }
            v225.m_Data = 0;
          }
          LOBYTE(nStep) = 10;
          if ( !InterlockedDecrement((volatile LONG *)&pIXMLDOMParseError[2]) )
          {
            v104 = pIXMLDOMParseError;
            if ( pIXMLDOMParseError->lpVtbl )
            {
              SysFreeString((BSTR)pIXMLDOMParseError->lpVtbl);
              v104 = pIXMLDOMParseError;
              pIXMLDOMParseError->lpVtbl = 0;
            }
            if ( v104[1].lpVtbl )
            {
              operator delete[](v104[1].lpVtbl);
              v104 = pIXMLDOMParseError;
              pIXMLDOMParseError[1].lpVtbl = 0;
            }
            operator delete(v104);
          }
          v105 = v50 ? v50->m_wstr : 0;
          v73 = PE_OpenFile(v105, 0x80000000, 1u, 0, 3u, 0, 0);
          nLinePosition = v73;
          if ( v73 == (void *)-1 )
          {
            v106 = (Data_t_bstr_t *)operator new(0xCu);
            pIXMLDOMParseError = (IXMLDOMParseError *)v106;
            bstrReason = v106;
            LOBYTE(nStep) = 29;
            if ( v106 )
            {
              v106->m_str = 0;
              v106->m_RefCount = 1;
              v107 = (IXMLDOMParseErrorVtbl *)SysAllocString(L"\\Gadget.xml");
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
            v110 = _bstr_t::operator+((_bstr_t *)&StringItem.strValue[2], &v215, (_bstr_t *)&bstrReason);
            nLinePosition = v110;
            if ( &v250 != (Data_t_bstr_t **)v110 )
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
                    operator delete[](v50->m_str);
                    v50->m_str = 0;
                  }
                  operator delete(v50);
                }
                v110 = (_bstr_t *)nLinePosition;
              }
              v50 = v110->m_Data;
              v250 = v50;
              if ( v50 )
                InterlockedIncrement(&v50->m_RefCount);
            }
            nLinePosition = v215.m_Data;
            if ( v215.m_Data )
            {
              if ( !InterlockedDecrement(&v215.m_Data->m_RefCount) )
              {
                v111 = (void **)nLinePosition;
                if ( nLinePosition )
                {
                  if ( *(_DWORD *)nLinePosition )
                  {
                    SysFreeString(*(BSTR *)nLinePosition);
                    v111 = (void **)nLinePosition;
                    *(_DWORD *)nLinePosition = 0;
                  }
                  if ( v111[1] )
                  {
                    operator delete[](v111[1]);
                    v111 = (void **)nLinePosition;
                    *((_DWORD *)nLinePosition + 1) = 0;
                  }
                  operator delete(v111);
                }
              }
              v215.m_Data = 0;
            }
            LOBYTE(nStep) = 10;
            if ( !InterlockedDecrement((volatile LONG *)&pIXMLDOMParseError[2]) )
            {
              v112 = pIXMLDOMParseError;
              if ( pIXMLDOMParseError->lpVtbl )
              {
                SysFreeString((BSTR)pIXMLDOMParseError->lpVtbl);
                v112 = pIXMLDOMParseError;
                pIXMLDOMParseError->lpVtbl = 0;
              }
              if ( v112[1].lpVtbl )
              {
                operator delete[](v112[1].lpVtbl);
                v112 = pIXMLDOMParseError;
                pIXMLDOMParseError[1].lpVtbl = 0;
              }
              operator delete(v112);
            }
            v113 = v50 ? v50->m_wstr : 0;
            v73 = PE_OpenFile(v113, 0x80000000, 1u, 0, 3u, 0, 0);
            nLinePosition = v73;
            if ( v73 == (void *)-1 )
            {
              _bstr_t::operator=((EventItem *)&EventItem, (OLECHAR *)&gszNullString);
              if ( StringItem.strValue[3] && !InterlockedDecrement((volatile LONG *)(StringItem.strValue[3] + 8)) )
              {
                v114 = (void **)StringItem.strValue[3];
                if ( *(_DWORD *)StringItem.strValue[3] )
                {
                  SysFreeString(*(BSTR *)StringItem.strValue[3]);
                  v114 = (void **)StringItem.strValue[3];
                  *(_DWORD *)StringItem.strValue[3] = 0;
                }
                if ( v114[1] )
                {
                  operator delete[](v114[1]);
                  v114 = (void **)StringItem.strValue[3];
                  *(_DWORD *)(StringItem.strValue[3] + 4) = 0;
                }
                operator delete(v114);
              }
              StringItem.strValue[3] = StringItem.strValue[2];
              if ( StringItem.strValue[2] )
              {
                v115 = (volatile LONG *)(StringItem.strValue[2] + 8);
LABEL_367:
                InterlockedIncrement(v115);
                goto LABEL_368;
              }
              goto LABEL_368;
            }
          }
        }
      }
      nNumberOfBytesToRead = (Data_t_bstr_t *)GetFileSize(v73, 0);
      pIXMLDOMParseError = (IXMLDOMParseError *)operator new[]((unsigned int)nNumberOfBytesToRead);
      bstrSourceText = (Data_t_bstr_t *)operator new[](2 * ((_DWORD)nNumberOfBytesToRead + 1));
      NumberOfBytesRead = 0;
      ReadFile(nLinePosition, pIXMLDOMParseError, (DWORD)nNumberOfBytesToRead, &NumberOfBytesRead, 0);
      if ( NumberOfBytesRead >= 3
        && LOBYTE(pIXMLDOMParseError->lpVtbl) == 0357u
        && BYTE1(pIXMLDOMParseError->lpVtbl) == 0xBBu
        && BYTE2(pIXMLDOMParseError->lpVtbl) == 0xBFu )
      {
        break;
      }
      if ( NumberOfBytesRead < 2 || LOBYTE(pIXMLDOMParseError->lpVtbl) != -1 || BYTE1(pIXMLDOMParseError->lpVtbl) != -2 )
      {
        v116 = MultiByteToWideChar(
                 0,
                 0,
                 (LPCSTR)pIXMLDOMParseError,
                 (int)nNumberOfBytesToRead,
                 (LPWSTR)bstrSourceText,
                 (int)nNumberOfBytesToRead);
        goto LABEL_357;
      }
      v117 = 1;
      v118 = (Data_t_bstr_t *)((unsigned int)nNumberOfBytesToRead >> 1);
      nNumberOfBytesToRead = v118;
      if ( (unsigned int)v118 > 1 )
      {
        v119 = bstrSourceText;
        v120 = v118;
        v121 = pIXMLDOMParseError;
        do
        {
          v122 = *((_WORD *)&v121->lpVtbl + v117);
          v119 = (Data_t_bstr_t *)((char *)v119 + 2);
          ++v117;
          HIWORD(v119[-1].m_RefCount) = v122;
        }
        while ( v117 < (unsigned int)v120 );
        v50 = v250;
        v23 = v245;
        v118 = nNumberOfBytesToRead;
      }
      *((_WORD *)bstrSourceText + (_DWORD)v118 - 1) = 0;
LABEL_358:
      _bstr_t::operator=((EventItem *)&EventItem, (OLECHAR *)bstrSourceText);
      operator delete[](bstrSourceText);
      operator delete[](pIXMLDOMParseError);
      CloseHandle(nLinePosition);
      if ( StringItem.strValue[3] && !InterlockedDecrement((volatile LONG *)(StringItem.strValue[3] + 8)) )
      {
        v123 = (void **)StringItem.strValue[3];
        if ( *(_DWORD *)StringItem.strValue[3] )
        {
          SysFreeString(*(BSTR *)StringItem.strValue[3]);
          v123 = (void **)StringItem.strValue[3];
          *(_DWORD *)StringItem.strValue[3] = 0;
        }
        if ( v123[1] )
        {
          operator delete[](v123[1]);
          v123 = (void **)StringItem.strValue[3];
          *(_DWORD *)(StringItem.strValue[3] + 4) = 0;
        }
        operator delete(v123);
      }
      StringItem.strValue[3] = (int)v50;
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
          operator delete[](v50->m_str);
          v50->m_str = 0;
        }
        operator delete(v50);
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
        v131 = (Data_t_bstr_t *)operator new(0xCu);
        nNumberOfBytesToRead = v131;
        bstrReason = v131;
        LOBYTE(nStep) = 31;
        if ( v131 )
        {
          v132 = (const OLECHAR *)nLinePosition;
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
              operator delete[](v124->m_str);
              v124->m_str = 0;
            }
            operator delete(v124);
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
            operator delete[](v136->m_str);
            v136 = nNumberOfBytesToRead;
            nNumberOfBytesToRead->m_str = 0;
          }
          operator delete(v136);
        }
      }
      CoInitializeEx(0, 0);
      pIXMLDOMDocument = 0;
      if ( ::Wow64EnableWow64FsRedirection )
      {
        ::Wow64EnableWow64FsRedirection(1u);
        TlsSetValue(gdwTlsIndex, (LPVOID)0x200);
      }
      hResult = (void *)CoCreateInstance(
                          &CLSID_XMLDOMDocument,
                          0,
                          1u,
                          &CLSID_IXMLDOMDocument,
                          (LPVOID *)&pIXMLDOMDocument);
      Wow64EnableWow64FsRedirection = ::Wow64EnableWow64FsRedirection;
      bstrReason = hResult;
      if ( ::Wow64EnableWow64FsRedirection )
      {
        ::Wow64EnableWow64FsRedirection(0);
        TlsSetValue(gdwTlsIndex, (LPVOID)0x100);
        Wow64EnableWow64FsRedirection = ::Wow64EnableWow64FsRedirection;
        hResult = bstrReason;
      }
      if ( !hResult )
      {
        vtFlags = 0;
        if ( Wow64EnableWow64FsRedirection )
        {
          Wow64EnableWow64FsRedirection(1);
          TlsSetValue(gdwTlsIndex, (LPVOID)0x200);
        }
        if ( v124 )
          v139 = v124->m_wstr;
        else
          v139 = 0;
        pIXMLDOMDocument->lpVtbl->loadXML(pIXMLDOMDocument, v139, (VARIANT_BOOL *)&vtFlags);
        v23 = v245;
        if ( ::Wow64EnableWow64FsRedirection )
        {
          ::Wow64EnableWow64FsRedirection(0);
          TlsSetValue(gdwTlsIndex, (LPVOID)0x100);
        }
        if ( (_WORD)vtFlags )
          goto LABEL_531;
        pIXMLDOMParseError = 0;
        pIXMLDOMDocument->lpVtbl->get_parseError(pIXMLDOMDocument, &pIXMLDOMParseError);
        if ( pIXMLDOMParseError )
        {
          bstrReason = 0;
          nLineNumber = (void *)-1;
          nLinePosition = (HANDLE)-1;
          bstrSourceText = 0;
          pIXMLDOMParseError->lpVtbl->get_reason(pIXMLDOMParseError, (BSTR *)&bstrReason);
          pIXMLDOMParseError->lpVtbl->get_line(pIXMLDOMParseError, (int *)&nLineNumber);
          pIXMLDOMParseError->lpVtbl->get_linepos(pIXMLDOMParseError, (int *)&nLinePosition);
          pIXMLDOMParseError->lpVtbl->get_srcText(pIXMLDOMParseError, (BSTR *)&bstrSourceText);
          pIXMLDOMParseError->lpVtbl->Release(pIXMLDOMParseError);
        }
        if ( (_WORD)vtFlags )
        {
LABEL_531:
          v140 = (Data_t_bstr_t *)operator new(0xCu);
          pIXMLDOMParseError = (IXMLDOMParseError *)v140;
          bstrReason = v140;
          LOBYTE(nStep) = 32;
          if ( v140 )
          {
            v140->m_str = 0;
            v140->m_RefCount = 1;
            v141 = (IXMLDOMParseErrorVtbl *)_com_util::ConvertStringToBSTR("gadget");
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
          v143 = (OLECHAR *)v142->lpVtbl;
          LOBYTE(nStep) = 33;
          hresult = pIXMLDOMDocument->lpVtbl->selectSingleNode(pIXMLDOMDocument, v143, &pIXMLDOMNode);
          LOBYTE(nStep) = 9;
          v257 = hresult == 0;
          v145 = InterlockedDecrement((volatile LONG *)&pIXMLDOMParseError[2]);
          v124 = EventItem;
          if ( !v145 )
          {
            v146 = pIXMLDOMParseError;
            if ( pIXMLDOMParseError->lpVtbl )
            {
              SysFreeString((BSTR)pIXMLDOMParseError->lpVtbl);
              v146 = pIXMLDOMParseError;
              pIXMLDOMParseError->lpVtbl = 0;
            }
            if ( v146[1].lpVtbl )
            {
              operator delete[](v146[1].lpVtbl);
              v146 = pIXMLDOMParseError;
              pIXMLDOMParseError[1].lpVtbl = 0;
            }
            operator delete(v146);
          }
          if ( v257 )
          {
            v147 = (Data_t_bstr_t *)operator new(0xCu);
            pIXMLDOMParseError = (IXMLDOMParseError *)v147;
            bstrReason = v147;
            LOBYTE(nStep) = 34;
            if ( v147 )
            {
              v147->m_str = 0;
              v147->m_RefCount = 1;
              v148 = (IXMLDOMParseErrorVtbl *)_com_util::ConvertStringToBSTR("name");
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
            v150 = (OLECHAR *)v149->lpVtbl;
            LOBYTE(nStep) = 35;
            v151 = pIXMLDOMNode->lpVtbl->selectSingleNode(pIXMLDOMNode, v150, &pIXMLDOMNode2);
            LOBYTE(nStep) = 9;
            v257 = v151 == 0;
            if ( !InterlockedDecrement((volatile LONG *)&pIXMLDOMParseError[2]) )
            {
              v152 = pIXMLDOMParseError;
              if ( pIXMLDOMParseError->lpVtbl )
              {
                SysFreeString((BSTR)pIXMLDOMParseError->lpVtbl);
                v152 = pIXMLDOMParseError;
                pIXMLDOMParseError->lpVtbl = 0;
              }
              if ( v152[1].lpVtbl )
              {
                operator delete[](v152[1].lpVtbl);
                v152 = pIXMLDOMParseError;
                pIXMLDOMParseError[1].lpVtbl = 0;
              }
              operator delete(v152);
            }
            if ( v257 )
            {
              _bstr_t::Assign((_bstr_t *)&StringItem.strValue[4], 0);
              pIXMLDOMNode2->lpVtbl->get_text(pIXMLDOMNode2, (BSTR *)StringItem.strValue[4]);
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
              _bstr_t::Assign((_bstr_t *)&StringItem.strValue[6], 0);
              pIXMLDOMNode2->lpVtbl->get_text(pIXMLDOMNode2, (BSTR *)StringItem.strValue[6]);
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
                  _bstr_t::Assign((_bstr_t *)&StringItem.strValue[5], 0);
                  pIXMLDOMNode3->lpVtbl->get_text(pIXMLDOMNode3, (BSTR *)StringItem.strValue[5]);
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
              _bstr_t::Assign(&v233, 0);
              pIXMLDOMNode2->lpVtbl->get_text(pIXMLDOMNode2, (BSTR *)v233.m_Data);
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
              if ( !pIXMLDOMNode2->lpVtbl->get_childNodes(pIXMLDOMNode2, &pIXMLDOMNodeList) )
              {
                bstrReason = (void *)4096;
                if ( !pIXMLDOMNodeList->lpVtbl->nextNode(pIXMLDOMNodeList, &bstrResult) )
                {
                  v168 = (char *)bstrReason;
                  do
                  {
                    if ( !bstrResult->lpVtbl->get_attributes(bstrResult, &pIXMLDOMNamedNodeMap2) )
                    {
                      VariantInit(&pvarSrc);
                      LOBYTE(nStep) = 42;
                      v169 = _bstr_t::_bstr_t(&v209, "height")->m_Data;
                      LOBYTE(nStep) = 43;
                      if ( v169 )
                        v170 = v169->m_wstr;
                      else
                        v170 = 0;
                      v171 = pIXMLDOMNamedNodeMap2->lpVtbl->getNamedItem(
                               pIXMLDOMNamedNodeMap2,
                               v170,
                               (IXMLDOMNode **)&v246);
                      LOBYTE(nStep) = 42;
                      v257 = v171 == 0;
                      _bstr_t::_Free(&v209);
                      if ( v257 )
                      {
                        (*(void (__stdcall **)(int, VARIANTARG *))(*(_DWORD *)v246 + 32))(v246, &pvarSrc);
                        v172 = _bstr_t::_bstr_t(&v199, &pvarSrc)->strEventTrace.m_Data;
                        if ( v172 )
                          v173 = v172->m_wstr;
                        else
                          v173 = 0;
                        v235 = _wtoi(v173);
                        _bstr_t::_Free(&v199);
                        (*(void (__stdcall **)(int))(*(_DWORD *)v246 + 8))(v246);
                      }
                      v174 = _bstr_t::_bstr_t(&v207, "width")->m_Data;
                      LOBYTE(nStep) = 44;
                      if ( v174 )
                        v175 = v174->m_wstr;
                      else
                        v175 = 0;
                      v176 = pIXMLDOMNamedNodeMap2->lpVtbl->getNamedItem(
                               pIXMLDOMNamedNodeMap2,
                               v175,
                               (IXMLDOMNode **)&v246);
                      LOBYTE(nStep) = 42;
                      v257 = v176 == 0;
                      _bstr_t::_Free(&v207);
                      v177 = v235;
                      if ( v257 )
                      {
                        (*(void (__stdcall **)(int, VARIANTARG *))(*(_DWORD *)v246 + 32))(v246, &pvarSrc);
                        v178 = _bstr_t::_bstr_t(&v206, &pvarSrc)->strEventTrace.m_Data;
                        if ( v178 )
                          v179 = v178->m_wstr;
                        else
                          v179 = 0;
                        bstrDisabled_1 = (_bstr_t *)_wtoi(v179);
                        _bstr_t::_Free(&v206);
                        (*(void (__stdcall **)(int))(*(_DWORD *)v246 + 8))(v246);
                      }
                      if ( v177 >= 16
                        && (signed int)bstrDisabled_1 >= 16
                        && (signed int)bstrDisabled_1 + v177 < (signed int)v168 )
                      {
                        v180 = _bstr_t::_bstr_t(&v204, "src")->m_Data;
                        LOBYTE(nStep) = 45;
                        v181 = v180 ? v180->m_wstr : 0;
                        v182 = pIXMLDOMNamedNodeMap2->lpVtbl->getNamedItem(
                                 pIXMLDOMNamedNodeMap2,
                                 v181,
                                 (IXMLDOMNode **)&v246);
                        LOBYTE(nStep) = 42;
                        v257 = v182 == 0;
                        _bstr_t::_Free(&v204);
                        v183 = v235;
                        if ( v257 )
                        {
                          (*(void (__stdcall **)(int, VARIANTARG *))(*(_DWORD *)v246 + 32))(v246, &pvarSrc);
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
                          _bstr_t::_bstr_t((tagEventSetItem *)&a3, L"\\");
                          LOBYTE(nStep) = 47;
                          v186 = _bstr_t::operator+((_bstr_t *)&StringItem.strValue[2], &bstrDisabled, &a3);
                          LOBYTE(nStep) = 48;
                          bstrReason = _bstr_t::operator+(v186, &v201, &bstrTemp);
                          if ( &v234 != bstrReason )
                          {
                            _bstr_t::_Free(&v234);
                            v187 = *(Data_t_bstr_t **)bstrReason;
                            v234.m_Data = v187;
                            if ( v187 )
                              InterlockedIncrement(&v187->m_RefCount);
                          }
                          _bstr_t::_Free(&v201);
                          _bstr_t::_Free(&bstrDisabled);
                          LOBYTE(nStep) = 46;
                          _bstr_t::_Free(&a3);
                          v168 = (char *)bstrDisabled_1 + v183;
                          (*(void (__stdcall **)(int))(*(_DWORD *)v246 + 8))(v246);
                          LOBYTE(nStep) = 42;
                          _bstr_t::_Free(&bstrTemp);
                        }
                      }
                      pIXMLDOMNamedNodeMap2->lpVtbl->Release(pIXMLDOMNamedNodeMap2);
                      LOBYTE(nStep) = 9;
                      VariantClear(&pvarSrc);
                    }
                    bstrResult->lpVtbl->Release(bstrResult);
                  }
                  while ( !pIXMLDOMNodeList->lpVtbl->nextNode(pIXMLDOMNodeList, &bstrResult) );
                  v124 = EventItem;
                  v23 = v245;
                }
                pIXMLDOMNodeList->lpVtbl->Release(pIXMLDOMNodeList);
              }
              pIXMLDOMNode2->lpVtbl->Release(pIXMLDOMNode2);
            }
            pIXMLDOMNode->lpVtbl->Release(pIXMLDOMNode);
          }
        }
      }
      bstrReason = v231->_Mypair._Myval2._Myhead;
      v188 = cbstrList::getInstance((int)bstrReason, *((_DWORD *)bstrReason + 1), (int)&StringItem);
      v189 = v231->_Mypair._Myval2._Mysize;
      if ( 97612892 - v189 < 1 )
        goto LABEL_10;
      v231->_Mypair._Myval2._Mysize = v189 + 1;
      *((_DWORD *)bstrReason + 1) = v188;
      **(_DWORD **)(v188 + 4) = v188;
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
          operator delete[](v124->m_str);
          v124->m_str = 0;
        }
        operator delete(v124);
      }
      LOBYTE(nStep) = 0;
      tagPEStringStruct::~tagPEStringStruct(&StringItem);
      v23 = (std__List *)v23->_Mypair._Myval2._Myhead;
      v245 = v23;
      if ( v23 == theDwordList )
        goto LABEL_526;
    }
    v116 = MultiByteToWideChar(
             CP_UTF8,
             0,
             (LPCSTR)&pIXMLDOMParseError->lpVtbl + 3,
             (int)&nNumberOfBytesToRead[-1].m_RefCount + 1,
             (LPWSTR)bstrSourceText,
             (int)nNumberOfBytesToRead);
LABEL_357:
    *((_WORD *)&bstrSourceText->m_wstr + v116) = 0;
    goto LABEL_358;
  }
LABEL_526:
  v190 = theDwordList;
  v191 = theDwordList->_Mypair._Myval2._Myhead;
  v190->_Mypair._Myval2._Myhead = (std__list_node *)v190;
  v190->_Mypair._Myval2._Mysize = (unsigned int)v190;
  if ( v191 != (std__list_node *)v190 )
  {
    do
    {
      v192 = v191->_Next;
      operator delete(v191);
      v191 = v192;
    }
    while ( v192 != (std__list_node *)v190 );
  }
  operator delete(v190);
  return 1;
}
// CA28CC: using guessed type wchar_t aProgramw6432[14];
// CD4C64: using guessed type int (__stdcall *IsWow64Process)(_DWORD, _DWORD);
// CD4C68: using guessed type int dword_CD4C68;
// CD4C6C: using guessed type int (__stdcall *GetSystemDefaultLocaleName)(_DWORD, _DWORD);
// CD4C70: using guessed type int (__stdcall *GetUserDefaultLocaleName)(_DWORD, _DWORD);

//----- (00BFD790) --------------------------------------------------------
void *__cdecl sub_BFD790(HWND hWndIn)
{
  HWND v1; // ebx
  HMODULE v2; // eax
  Data_t_bstr_t *v3; // esi
  const wchar_t *v4; // eax
  const WCHAR **v5; // eax
  std__list_node *v6; // eax
  Data_t_bstr_t *v7; // edi
  std__list_node *i; // esi
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
  const WCHAR **v23; // eax
  int v24; // ebx
  const WCHAR *pszPath; // eax
  WCHAR *v26; // ST40_4
  _IMAGELIST *hImgList; // eax
  WCHAR *v28; // ST40_4
  _IMAGELIST *v29; // eax
  std__list_node *v30; // eax
  OLECHAR *v31; // eax
  HICON v32; // ST44_4
  _IMAGELIST *v33; // eax
  std__list_node *v34; // eax
  OLECHAR *pszPathName; // eax
  HICON v36; // ST44_4
  _IMAGELIST *v37; // eax
  OLECHAR **v38; // eax
  OLECHAR *v39; // eax
  WCHAR *v40; // eax
  WCHAR *v41; // eax
  std__list_node *v42; // eax
  std__list_node *v43; // eax
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
  std__list_node *v56; // eax
  std__list_node *v57; // eax
  void *v58; // ST40_4
  int v59; // ST34_4
  DWORD v60; // ST08_4
  std__list_node *v61; // ebx
  std__list_node *v62; // esi
  int a8; // [esp+10h] [ebp-344h]
  void *v65; // [esp+14h] [ebp-340h]
  CCmdString str1; // [esp+18h] [ebp-33Ch]
  void *v67; // [esp+1Ch] [ebp-338h]
  CCmdString str2; // [esp+20h] [ebp-334h]
  void *v69; // [esp+24h] [ebp-330h]
  void *v70; // [esp+28h] [ebp-32Ch]
  void *v71; // [esp+2Ch] [ebp-328h]
  void *v72; // [esp+30h] [ebp-324h]
  IShellItem2 *pShellItem2; // [esp+34h] [ebp-320h]
  void *v74; // [esp+38h] [ebp-31Ch]
  void *v75; // [esp+3Ch] [ebp-318h]
  void *v76; // [esp+40h] [ebp-314h]
  void *v77; // [esp+44h] [ebp-310h]
  CCmdString strValue; // [esp+48h] [ebp-30Ch]
  void *v79; // [esp+4Ch] [ebp-308h]
  CCmdString strId; // [esp+50h] [ebp-304h]
  CCmdString strText; // [esp+54h] [ebp-300h]
  CCmdString str3; // [esp+58h] [ebp-2FCh]
  std__List pList; // [esp+5Ch] [ebp-2F8h]
  _bstr_t bstrText; // [esp+64h] [ebp-2F0h]
  CCmdString v85; // [esp+68h] [ebp-2ECh]
  CCmdString a2; // [esp+6Ch] [ebp-2E8h]
  CCmdString v87; // [esp+70h] [ebp-2E4h]
  void *ppv1; // [esp+74h] [ebp-2E0h]
  CCmdString ppv3; // [esp+78h] [ebp-2DCh]
  CCmdString pIShellItemImageFactory; // [esp+7Ch] [ebp-2D8h]
  CCmdString v91; // [esp+80h] [ebp-2D4h]
  HWND hWnd; // [esp+84h] [ebp-2D0h]
  CCmdString hSmallImage; // [esp+88h] [ebp-2CCh]
  CCmdString hLargeImage; // [esp+8Ch] [ebp-2C8h]
  SHFILEINFOW FileInfo; // [esp+90h] [ebp-2C4h]
  int v96; // [esp+350h] [ebp-4h]

  v1 = hWndIn;
  hWnd = hWndIn;
  QuerySideBarConfigPath(&bstrText);
  v96 = 0;
  if ( !SHCreateItemFromParsingName )
  {
    v2 = LoadLibraryW(L"Shell32.dll");
    SHCreateItemFromParsingName = (int (__stdcall *)(PCWSTR, IBindCtx *, GUID *, void **))GetProcAddress(
                                                                                            v2,
                                                                                            "SHCreateItemFromParsingName");
  }
  a2.m_String = _wcsdup((const wchar_t *)&gszNullString);
  v87.m_String = _wcsdup((const wchar_t *)&gszNullString);
  v85.m_String = _wcsdup((const wchar_t *)&gszNullString);
  pIShellItemImageFactory.m_String = _wcsdup((const wchar_t *)&gszNullString);
  v91.m_String = _wcsdup((const wchar_t *)&gszNullString);
  hSmallImage.m_String = _wcsdup((const wchar_t *)&gszNullString);
  v3 = bstrText.m_Data;
  if ( !bstrText.m_Data || (v4 = bstrText.m_Data->m_wstr) == 0 )
    v4 = (const wchar_t *)&gszNullString;
  hLargeImage.m_String = _wcsdup(v4);
  if ( !v3 || (v5 = (const WCHAR **)v3->m_wstr) == 0 )
    v5 = &gszNullString;
  ppv3.m_String = _wcsdup((const wchar_t *)v5);
  LOBYTE(v96) = 8;
  ppv1 = (void *)PE_UpdateSystemKey((int)hWndIn, 7u, (HANDLE)0xFFFFFFFF, 7u, &ppv3, &hLargeImage, &hSmallImage);
  free(ppv3.m_String);
  free(hLargeImage.m_String);
  free(hSmallImage.m_String);
  free(v91.m_String);
  free(pIShellItemImageFactory.m_String);
  free(v85.m_String);
  free(v87.m_String);
  LOBYTE(v96) = 0;
  free(a2.m_String);
  pList._Mypair._Myval2._Mysize = 0;
  pList._Mypair._Myval2._Myhead = (std__list_node *)cbstrList::cbstrList(0, 0);
  LOBYTE(v96) = 9;
  PE_LoadConfig(&bstrText, &pList);
  v6 = pList._Mypair._Myval2._Myhead;
  v7 = bstrText.m_Data;
  for ( i = pList._Mypair._Myval2._Myhead->_Next; i != pList._Mypair._Myval2._Myhead; v6 = pList._Mypair._Myval2._Myhead )
  {
    v9 = (OLECHAR **)i[1]._Prev;
    if ( v9 )
    {
      v10 = *v9;
      if ( v10 )
      {
        if ( SysStringLen(v10) )
        {
          v11 = (WCHAR *)malloc(2u);
          ppv3.m_String = v11;
          *v11 = 0;
          v12 = (const WCHAR ***)i[2]._Prev;
          if ( !v12 || (v13 = *v12) == 0 )
            v13 = &gszNullString;
          v65 = _wcsdup((const wchar_t *)v13);
          v14 = (const WCHAR ***)i[1]._Myval;
          if ( !v14 || (v15 = *v14) == 0 )
            v15 = &gszNullString;
          v79 = _wcsdup((const wchar_t *)v15);
          if ( !v7 || (v16 = v7->m_wstr) == 0 )
            v16 = (const wchar_t *)&gszNullString;
          v85.m_String = _wcsdup(v16);
          if ( !v7 || (v17 = (const WCHAR **)v7->m_wstr) == 0 )
            v17 = &gszNullString;
          v87.m_String = _wcsdup((const wchar_t *)v17);
          v18 = (const WCHAR ***)i[2]._Next;
          if ( !v18 || (v19 = *v18) == 0 )
            v19 = &gszNullString;
          a2.m_String = _wcsdup((const wchar_t *)v19);
          LOBYTE(v96) = 15;
          v20 = sub_BE3D40(
                  (int)v1,
                  (CCmdString)&a2,
                  (int)&v87,
                  (int)&v85,
                  (int)&v79,
                  (int)&v65,
                  (CCmdString)&ppv3,
                  (int)&a8);
          free(a2.m_String);
          free(v87.m_String);
          free(v85.m_String);
          free(v79);
          LOBYTE(v96) = 10;
          free(v65);
          if ( v20 )
          {
            if ( ppv1 == (void *)-1 )
            {
              v69 = _wcsdup((const wchar_t *)&gszNullString);
              v75 = _wcsdup((const wchar_t *)&gszNullString);
              v67 = _wcsdup((const wchar_t *)&gszNullString);
              v77 = _wcsdup((const wchar_t *)&gszNullString);
              v71 = _wcsdup((const wchar_t *)&gszNullString);
              str3.m_String = _wcsdup((const wchar_t *)&gszNullString);
              if ( !v7 || (v21 = (const WCHAR **)v7->m_wstr) == 0 )
                v21 = &gszNullString;
              str2.m_String = _wcsdup((const wchar_t *)v21);
              if ( !v7 || (v22 = (const WCHAR **)v7->m_wstr) == 0 )
                v22 = &gszNullString;
              str1.m_String = _wcsdup((const wchar_t *)v22);
              LOBYTE(v96) = 23;
              ppv1 = (void *)PE_UpdateSystemKey((int)hWnd, 7u, (HANDLE)0xFFFFFFFF, 7u, &str1, &str2, &str3);
              free(str1.m_String);
              free(str2.m_String);
              free(str3.m_String);
              free(v71);
              free(v77);
              free(v67);
              free(v75);
              LOBYTE(v96) = 10;
              free(v69);
            }
            v23 = (const WCHAR **)i[3]._Prev;
            v24 = -1;
            v91.m_String = (WCHAR *)-1;
            if ( v23 )
              pszPath = *v23;
            else
              pszPath = 0;
            // Creates and initializes a Shell item object from a parsing name.
            if ( SHCreateItemFromParsingName(pszPath, 0, &CLSID_IShellItem2, (void **)&pShellItem2) >= 0 )
            {
              pIShellItemImageFactory.m_String = 0;
              if ( pShellItem2->lpVtbl->QueryInterface(
                     pShellItem2,
                     &CLSID_IShellItemImageFactory,
                     (void **)&pIShellItemImageFactory) >= 0 )
              {
                hSmallImage.m_String = 0;
                hLargeImage.m_String = 0;
                (*(void (__stdcall **)(WCHAR *, signed int, signed int, _DWORD, CCmdString *))(*(_DWORD *)pIShellItemImageFactory.m_String
                                                                                             + 12))(
                  pIShellItemImageFactory.m_String,
                  16,
                  16,
                  0,
                  &hSmallImage);
                (*(void (__stdcall **)(WCHAR *, signed int, signed int, _DWORD, CCmdString *))(*(_DWORD *)pIShellItemImageFactory.m_String
                                                                                             + 12))(
                  pIShellItemImageFactory.m_String,
                  32,
                  32,
                  0,
                  &hLargeImage);
                if ( hSmallImage.m_String )
                {
                  v26 = hSmallImage.m_String;
                  hImgList = (_IMAGELIST *)SendMessageW(hWnd, LVM_GETIMAGELIST, 1u, 0);
                  v24 = ImageList_Add(hImgList, (HBITMAP)v26, 0);
                  DeleteObject(hSmallImage.m_String);
                }
                if ( hLargeImage.m_String )
                {
                  v28 = hLargeImage.m_String;
                  v29 = (_IMAGELIST *)SendMessageW(hWnd, LVM_GETIMAGELIST, 0, 0);
                  v91.m_String = (WCHAR *)ImageList_Add(v29, (HBITMAP)v28, 0);
                  DeleteObject(hLargeImage.m_String);
                }
                (*(void (__stdcall **)(WCHAR *))(*(_DWORD *)pIShellItemImageFactory.m_String + 8))(pIShellItemImageFactory.m_String);
              }
              pShellItem2->lpVtbl->Release(pShellItem2);
            }
            if ( v24 < 0 )
            {
              FileInfo.hIcon = 0;
              memset(&FileInfo.iIcon, 0, 0x2B0u);
              v30 = i[3]._Prev;
              v31 = (OLECHAR *)(v30 ? v30->_Next : 0);
              if ( GetSHFileInfo(v31, 0, &FileInfo, sizeof(SHFILEINFOW), 0x101u) )
              {
                v32 = FileInfo.hIcon;
                v33 = (_IMAGELIST *)SendMessageW(hWnd, LVM_GETIMAGELIST, 1u, 0);
                v24 = ImageList_ReplaceIcon(v33, -1, v32);
                DestroyIcon(FileInfo.hIcon);
              }
            }
            if ( (signed int)v91.m_String < 0 )
            {
              FileInfo.hIcon = 0;
              memset(&FileInfo.iIcon, 0, 0x2B0u);
              v34 = i[3]._Prev;
              pszPathName = (OLECHAR *)(v34 ? v34->_Next : 0);
              if ( GetSHFileInfo(pszPathName, 0, &FileInfo, sizeof(SHFILEINFOW), 0x100u) )
              {
                v36 = FileInfo.hIcon;
                v37 = (_IMAGELIST *)SendMessageW(hWnd, LVM_GETIMAGELIST, 0, 0);
                v91.m_String = (WCHAR *)ImageList_ReplaceIcon(v37, -1, v36);
                DestroyIcon(FileInfo.hIcon);
              }
            }
            v38 = (OLECHAR **)i[3]._Prev;
            if ( v38 )
            {
              v39 = *v38;
              if ( v39 )
              {
                if ( SysStringLen(v39) && v24 < 0 )
                {
                  v40 = (WCHAR *)malloc(2u);
                  hSmallImage.m_String = v40;
                  *v40 = 0;
                  v41 = (WCHAR *)malloc(2u);
                  hLargeImage.m_String = v41;
                  *v41 = 0;
                  v42 = i[3]._Prev;
                  LOBYTE(v96) = 25;
                  if ( v42 )
                    v43 = v42->_Next;
                  v24 = sub_BE4ED0();
                  free(hLargeImage.m_String);
                  free(hSmallImage.m_String);
                }
              }
            }
            v70 = _wcsdup((const wchar_t *)&gszNullString);
            v44 = (const WCHAR ***)i[1]._Prev;
            if ( !v44 || (v45 = *v44) == 0 )
              v45 = &gszNullString;
            v72 = _wcsdup((const wchar_t *)v45);
            v46 = (const WCHAR ***)i[2]._Myval;
            if ( !v46 || (v47 = *v46) == 0 )
              v47 = &gszNullString;
            v74 = _wcsdup((const wchar_t *)v47);
            v48 = (const WCHAR ***)i[2]._Prev;
            if ( !v48 || (v49 = *v48) == 0 )
              v49 = &gszNullString;
            v76 = _wcsdup((const wchar_t *)v49);
            v50 = (const WCHAR ***)i[1]._Myval;
            if ( !v50 || (v51 = *v50) == 0 )
              v51 = &gszNullString;
            strValue.m_String = _wcsdup((const wchar_t *)v51);
            v52 = (const WCHAR ***)i[1]._Prev;
            if ( !v52 || (v53 = *v52) == 0 )
              v53 = &gszNullString;
            strId.m_String = _wcsdup((const wchar_t *)v53);
            v54 = (const WCHAR ***)i[2]._Next;
            if ( !v54 || (v55 = *v54) == 0 )
              v55 = &gszNullString;
            strText.m_String = _wcsdup((const wchar_t *)v55);
            v56 = i[3]._Next;
            LOBYTE(v96) = 32;
            if ( v56 )
              v57 = v56->_Next;
            v58 = i->_Myval;
            v59 = LOBYTE(i[1]._Next);
            v60 = v24;
            v1 = hWnd;
            PE_UpdateSystemKey((int)hWnd, v60, ppv1, 0xFu, &strText, &strId, &strValue);
            free(strText.m_String);
            free(strId.m_String);
            free(strValue.m_String);
            free(v76);
            free(v74);
            free(v72);
            free(v70);
          }
          else
          {
            v1 = hWnd;
          }
          LOBYTE(v96) = 9;
          free(ppv3.m_String);
        }
      }
    }
    i = i->_Next;
  }
  v61 = v6->_Next;
  v6->_Next = v6;
  v6->_Prev = v6;
  if ( v61 != v6 )
  {
    do
    {
      v62 = v61->_Next;
      tagPEStringStruct::~tagPEStringStruct((tagPEStringStruct *)&v61->_Myval);
      operator delete(v61);
      v6 = pList._Mypair._Myval2._Myhead;
      v61 = v62;
    }
    while ( v62 != pList._Mypair._Myval2._Myhead );
  }
  operator delete(v6);
  if ( v7 && !InterlockedDecrement(&v7->m_RefCount) )
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
  return ppv1;
}
// CB7B6C: using guessed type GUID CLSID_IShellItemImageFactory;

//----- (00BFE1B0) --------------------------------------------------------
_bstr_t *__cdecl MakeSectionName(_bstr_t *a1, int a2)
{
  __int16 Dest[260]; // [esp+8h] [ebp-20Ch]

  _swprintf((wchar_t *)Dest, L"Section %d", a2);
  _bstr_t::_bstr_t((tagEventSetItem *)a1, (OLECHAR *)Dest);
  return a1;
}

//----- (00BFE210) --------------------------------------------------------
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
    v4 = (char *)szAppPath - (char *)gpAccountInfo->szProfileImgPath;
    do
    {
      v5 = *szProfileImgPath;
      ++szProfileImgPath;
      *(WCHAR *)((char *)szProfileImgPath + v4 - 2) = v5;
    }
    while ( v5 );
    v6 = (_WORD *)((char *)&v11 + 2);
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
    SHGetFolderPathW = *(FARPROC *)::SHGetFolderPathW;
    if ( !*(_DWORD *)::SHGetFolderPathW )
    {
      v2 = LoadLibraryW(L"shell32.dll");
      SHGetFolderPathW = GetProcAddress(v2, "SHGetFolderPathW");
      *(_DWORD *)::SHGetFolderPathW = SHGetFolderPathW;
    }
    ((void (__stdcall *)(_DWORD, MACRO_CSIDL, _DWORD, _DWORD, WCHAR *))SHGetFolderPathW)(
      0,
      CSIDL_LOCAL_APPDATA,
      0,
      0,
      szAppPath);
  }
  v8 = (_WORD *)((char *)&v11 + 2);
  do
  {
    v9 = v8[1];
    ++v8;
  }
  while ( v9 );
  qmemcpy(v8, L"\\Microsoft\\Windows Sidebar\\Settings.ini", 80u);
  _bstr_t::_bstr_t((tagEventSetItem *)bstrText, szAppPath);
  return bstrText;
}
// CA2848: using guessed type wchar_t aAppdataLocal[15];
// CA2868: using guessed type wchar_t aMicrosoftWindo[40];

//----- (00BFE320) --------------------------------------------------------
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
  if ( result != (_DWORD *)-4 )
    result[1] = v4;
  return result;
}

//----- (00BFE360) --------------------------------------------------------
void __thiscall sub_BFE360(std__List *this)
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
      tagPEStringStruct::~tagPEStringStruct((tagPEStringStruct *)&v2->_Myval);
      operator delete(v2);
      v2 = v3;
    }
    while ( v3 != v1->_Mypair._Myval2._Myhead );
  }
}

//----- (00BFE3A0) --------------------------------------------------------
void *__cdecl sub_BFE3A0(int a1, void *a2, wchar_t *a3, void *a4, char a5)
{
  HWND v5; // edi
  wchar_t *v6; // ebx
  const wchar_t *v7; // eax
  const wchar_t *v8; // eax
  CCmdString *v9; // eax
  HANDLE v10; // esi
  unsigned __int16 *v11; // esi
  LPCWSTR v12; // edx
  WCHAR v13; // cx
  wchar_t *v14; // eax
  CCmdString *v15; // eax
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
  CCmdString strText; // [esp+50h] [ebp-2F4h]
  CCmdString strId; // [esp+54h] [ebp-2F0h]
  void *v47; // [esp+58h] [ebp-2ECh]
  void *v48; // [esp+5Ch] [ebp-2E8h]
  void *v49; // [esp+60h] [ebp-2E4h]
  void *v50; // [esp+64h] [ebp-2E0h]
  void *v51; // [esp+68h] [ebp-2DCh]
  CCmdString v52; // [esp+6Ch] [ebp-2D8h]
  void *v53; // [esp+70h] [ebp-2D4h]
  void *v54; // [esp+74h] [ebp-2D0h]
  void *v55; // [esp+78h] [ebp-2CCh]
  CCmdString v56; // [esp+7Ch] [ebp-2C8h]
  void *v57; // [esp+80h] [ebp-2C4h]
  void *v58; // [esp+84h] [ebp-2C0h]
  CCmdString v59; // [esp+88h] [ebp-2BCh]
  void *v60; // [esp+8Ch] [ebp-2B8h]
  void *v61; // [esp+90h] [ebp-2B4h]
  void *v62; // [esp+94h] [ebp-2B0h]
  CCmdString str1; // [esp+98h] [ebp-2ACh]
  int a8; // [esp+9Ch] [ebp-2A8h]
  int v65; // [esp+A0h] [ebp-2A4h]
  CCmdString str2; // [esp+A4h] [ebp-2A0h]
  CCmdString str3; // [esp+A8h] [ebp-29Ch]
  CCmdString v68; // [esp+ACh] [ebp-298h]
  WCHAR *ppv3; // [esp+B0h] [ebp-294h]
  CCmdString v70; // [esp+B4h] [ebp-290h]
  void *v71; // [esp+B8h] [ebp-28Ch]
  void *v72; // [esp+BCh] [ebp-288h]
  wchar_t *v73; // [esp+C0h] [ebp-284h]
  void *v74; // [esp+C4h] [ebp-280h]
  void *v75; // [esp+C8h] [ebp-27Ch]
  DWORD dwValue; // [esp+CCh] [ebp-278h]
  int a1a; // [esp+D0h] [ebp-274h]
  DWORD v78; // [esp+D4h] [ebp-270h]
  CCmdString strValue; // [esp+D8h] [ebp-26Ch]
  LPCWSTR lpszFileName; // [esp+DCh] [ebp-268h]
  char v81; // [esp+E3h] [ebp-261h]
  struct _WIN32_FIND_DATAW FindFileData; // [esp+E4h] [ebp-260h]
  int v83; // [esp+340h] [ebp-4h]

  v5 = (HWND)a1;
  a1a = a1;
  v73 = a3;
  v65 = 0;
  v83 = 0;
  v74 = malloc(2u);
  *(_WORD *)v74 = 0;
  v72 = malloc(2u);
  *(_WORD *)v72 = 0;
  v6 = (wchar_t *)malloc(2u);
  v35.strValue[6] = (int)v6;
  *v6 = 0;
  strValue.m_String = (WCHAR *)malloc(2u);
  *strValue.m_String = 0;
  v75 = malloc(2u);
  *(_WORD *)v75 = 0;
  v68.m_String = (WCHAR *)malloc(2u);
  *v68.m_String = 0;
  if ( a2 == (void *)-1 && a5 )
  {
    v78 = (DWORD)_wcsdup((const wchar_t *)&gszNullString);
    dwValue = (DWORD)_wcsdup((const wchar_t *)&gszNullString);
    v70.m_String = _wcsdup((const wchar_t *)&gszNullString);
    v71 = _wcsdup((const wchar_t *)&gszNullString);
    ppv3 = _wcsdup((const wchar_t *)&gszNullString);
    str3.m_String = _wcsdup((const wchar_t *)&gszNullString);
    v7 = (const wchar_t *)&gszNullString;
    if ( a3 )
      v7 = a3;
    str2.m_String = _wcsdup(v7);
    v8 = (const wchar_t *)&gszNullString;
    if ( a3 )
      v8 = a3;
    lpszFileName = _wcsdup(v8);
    LOBYTE(v83) = 14;
    PE_UpdateSystemKey(a1, 2u, (HANDLE)0xFFFFFFFF, 0, (CCmdString *)&lpszFileName, &str2, &str3);
    free((void *)lpszFileName);
    free(str2.m_String);
    free(str3.m_String);
    free(ppv3);
    free(v71);
    free(v70.m_String);
    free((void *)dwValue);
    free((void *)v78);
  }
  CCmdString::InsertAt((CCmdString *)&a4, L"\\", 0x7FFFFFFFu, 0);
  v9 = CCmdString::operator+((CCmdString *)&ppv, (CCmdString *)&a4, "*");
  LOBYTE(v83) = 15;
  v10 = sub_BF0FC0(v9->m_String, &FindFileData);
  LOBYTE(v83) = 6;
  hFindFile = v10;
  free(ppv);
  if ( v10 != (HANDLE)-1 )
  {
    do
    {
      v11 = (unsigned __int16 *)malloc(2u);
      v35.strValue[5] = (int)v11;
      *v11 = 0;
      if ( FindFileData.cFileName[0] != 46 && _wcsicmp(FindFileData.cFileName, L"AutorunsDisabled") )
      {
        CCmdString::operator+((CCmdString *)&lpszFileName, (CCmdString *)&a4, FindFileData.cFileName);
        v12 = lpszFileName;
        LOBYTE(v83) = 17;
        v78 = (DWORD)(lpszFileName + 1);
        do
        {
          v13 = *v12;
          ++v12;
        }
        while ( v13 );
        if ( (unsigned int)((signed int)((signed int)v12 - v78) >> 1) < 4 )
          goto LABEL_54;
        v14 = wcschr(lpszFileName, 0);
        if ( _wcsicmp(v14 - 4, L".lnk")
          || (v15 = PE_LoadFileName((CCmdString *)&ppszArgs, v5, lpszFileName),
              v65 |= 1u,
              v16 = v11,
              v11 = _wcsdup(v15->m_String),
              v35.strValue[5] = (int)v11,
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
          dwValue = (DWORD)v17;
          v78 = (DWORD)v17;
          *v17 = 0;
          a2a = (int)malloc(2u);
          *(_WORD *)a2a = 0;
          v37 = 0;
          v38 = 0;
          v39 = 0;
          LOBYTE(v83) = 19;
          sub_BE6CC0(v11, (StringItem *)&a2a);
          v18 = v75;
          v75 = _wcsdup(lpszFileName);
          free(v18);
          v19 = (const wchar_t **)sub_BE4EE0((int)&v40, a1a, (int)&a2a, 0);
          v20 = v6;
          v6 = _wcsdup(*v19);
          v35.strValue[6] = (int)v6;
          free(v20);
          free(v40);
          if ( wcsrchr(v6, 0x5Cu) )
          {
            v21 = wcsrchr(v6, 0x5Cu);
            v22 = _wcsdup(v21 + 1);
            v78 = (DWORD)v22;
            free((void *)dwValue);
          }
          else
          {
            v22 = _wcsdup(v6);
            v78 = (DWORD)v22;
            free((void *)dwValue);
          }
          v23 = (const wchar_t **)sub_BE4EE0((int)&v35.strValue[4], a1a, (int)&a2a, 0);
          dwValue = (DWORD)strValue.m_String;
          strValue.m_String = _wcsdup(*v23);
          free((void *)dwValue);
          free((void *)v35.strValue[4]);
          dwValue = sub_BE4ED0();
          v24 = (const wchar_t *)&gszNullString;
          if ( v73 )
            v24 = v73;
          v71 = _wcsdup(v24);
          v70.m_String = _wcsdup(FindFileData.cFileName);
          LOBYTE(v83) = 21;
          v81 = sub_BE3D40(
                  a1a,
                  (CCmdString)&v70,
                  (int)&v71,
                  (int)&lpszFileName,
                  (int)&strValue,
                  (int)&v74,
                  (CCmdString)&v68,
                  (int)&a8);
          free(v70.m_String);
          LOBYTE(v83) = 19;
          free(v71);
          if ( v81 )
          {
            if ( a2 != (void *)-1 )
              goto LABEL_55;
            if ( sub_BE63B0(v22) )
            {
              v51 = _wcsdup((const wchar_t *)&gszNullString);
              v60 = _wcsdup((const wchar_t *)&gszNullString);
              v53 = _wcsdup((const wchar_t *)&gszNullString);
              v54 = _wcsdup((const wchar_t *)&gszNullString);
              v58 = _wcsdup((const wchar_t *)&gszNullString);
              str2.m_String = _wcsdup((const wchar_t *)&gszNullString);
              v25 = (const wchar_t *)&gszNullString;
              if ( v73 )
                v25 = v73;
              str3.m_String = _wcsdup(v25);
              v26 = (const wchar_t *)&gszNullString;
              if ( v73 )
                v26 = v73;
              ppv3 = _wcsdup(v26);
              LOBYTE(v83) = 29;
              a2 = (void *)PE_UpdateSystemKey(a1a, 2u, (HANDLE)0xFFFFFFFF, 0, (CCmdString *)&ppv3, &str3, &str2);
              free(ppv3);
              free(str3.m_String);
              free(str2.m_String);
              free(v58);
              free(v54);
              free(v53);
              free(v60);
              free(v51);
              if ( a2 != (void *)-1 )
              {
LABEL_55:
                v49 = _wcsdup((const wchar_t *)&gszNullString);
                str1.m_String = _wcsdup(FindFileData.cFileName);
                LOBYTE(v83) = 31;
                PE_UpdateSystemKey(a1a, dwValue, a2, 7u, &str1, (CCmdString *)&lpszFileName, &strValue);
                free(str1.m_String);
                free(v49);
              }
            }
          }
          StringItem::~StringItem((tagPEStringStruct *)&a2a);
          free(v22);
          v5 = (HWND)a1a;
        }
        else
        {
          v35.strValue[0] = (int)v17;
          *v17 = 0;
          v35.strValue[1] = 0;
          v35.strValue[2] = 0;
          v35.strValue[3] = 0;
          LOBYTE(v83) = 32;
          sub_BE7040((wchar_t *)lpszFileName, (StringItem *)&v35);
          v27 = v75;
          v75 = _wcsdup(lpszFileName);
          free(v27);
          v28 = (const wchar_t **)sub_BE4EE0((int)&v43, a1a, (int)&v35, 0);
          v29 = strValue.m_String;
          strValue.m_String = _wcsdup(*v28);
          free(v29);
          free(v43);
          v5 = (HWND)a1a;
          v78 = sub_BE4ED0();
          v30 = (const wchar_t *)&gszNullString;
          if ( v73 )
            v30 = v73;
          v47 = _wcsdup(v30);
          v56.m_String = _wcsdup(FindFileData.cFileName);
          LOBYTE(v83) = 34;
          v81 = sub_BE3D40(
                  (int)v5,
                  (CCmdString)&v56,
                  (int)&v47,
                  (int)&lpszFileName,
                  (int)&strValue,
                  (int)&v74,
                  (CCmdString)&v68,
                  (int)&a8);
          free(v56.m_String);
          LOBYTE(v83) = 32;
          free(v47);
          if ( v81 )
          {
            if ( a2 != (void *)-1 )
              goto LABEL_56;
            if ( sub_BE63B0(FindFileData.cFileName) )
            {
              v61 = _wcsdup((const wchar_t *)&gszNullString);
              v62 = _wcsdup((const wchar_t *)&gszNullString);
              v55 = _wcsdup((const wchar_t *)&gszNullString);
              v50 = _wcsdup((const wchar_t *)&gszNullString);
              v48 = _wcsdup((const wchar_t *)&gszNullString);
              v52.m_String = _wcsdup((const wchar_t *)&gszNullString);
              v31 = (const wchar_t *)&gszNullString;
              if ( v73 )
                v31 = v73;
              strId.m_String = _wcsdup(v31);
              v32 = (const wchar_t *)&gszNullString;
              if ( v73 )
                v32 = v73;
              strText.m_String = _wcsdup(v32);
              LOBYTE(v83) = 42;
              a2 = (void *)PE_UpdateSystemKey((int)v5, 2u, (HANDLE)0xFFFFFFFF, 0, &strText, &strId, &v52);
              free(strText.m_String);
              free(strId.m_String);
              free(v52.m_String);
              free(v48);
              free(v50);
              free(v55);
              free(v62);
              free(v61);
              if ( a2 != (void *)-1 )
              {
LABEL_56:
                v57 = _wcsdup((const wchar_t *)&gszNullString);
                v59.m_String = _wcsdup(FindFileData.cFileName);
                LOBYTE(v83) = 44;
                PE_UpdateSystemKey((int)v5, v78, a2, 6u, &v59, (CCmdString *)&lpszFileName, &strValue);
                free(v59.m_String);
                free(v57);
              }
            }
          }
          StringItem::~StringItem(&v35);
        }
        free((void *)lpszFileName);
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
  free(v68.m_String);
  free(v75);
  free(strValue.m_String);
  free(v6);
  free(v72);
  free(v74);
  free(a4);
  return a2;
}

//----- (00BFEFA0) --------------------------------------------------------
void *__cdecl sub_BFEFA0(int a1, int a2, OLECHAR *psz, LPCWSTR lpValueName)
{
  void *v4; // eax

  v4 = sub_BFEFE0(a1, a2, psz, lpValueName, (void *)0xFFFFFFFF, 1);
  return sub_BFEFE0(a1, a2, psz, lpValueName, v4, 0);
}

//----- (00BFEFE0) --------------------------------------------------------
void *__cdecl sub_BFEFE0(int a1, int a2, OLECHAR *psz, LPCWSTR lpValueName, void *a5, char a6)
{
  unsigned int v6; // eax
  void *v7; // esi
  HKEY hKey; // [esp+8h] [ebp-14h]
  wchar_t *ppv; // [esp+Ch] [ebp-10h]
  int v11; // [esp+18h] [ebp-4h]

  ppv = (wchar_t *)malloc(2u);
  *ppv = 0;
  v11 = 0;
  v6 = (unsigned int)TlsGetValue(gdwTlsIndex);
  if ( PE_OpenKey((HKEY)a2, psz, 0, v6 | 0x20019, &hKey) )
  {
    v7 = a5;
  }
  else if ( PE_ReadRegKey(hKey, lpValueName, 0, 0, (CCmdString *)&ppv) )
  {
    v7 = a5;
    RegCloseKey(hKey);
  }
  else
  {
    if ( !a6 )
    {
      CCmdString::InsertAt((CCmdString *)&ppv, L"\\", 0x7FFFFFFFu, 0);
      CCmdString::InsertAt((CCmdString *)&ppv, L"AutorunsDisabled", 0x7FFFFFFFu, 0);
    }
    v7 = sub_BFF0E0(a1, ppv, ppv, a5, a6);
    RegCloseKey(hKey);
  }
  free(ppv);
  return v7;
}

//----- (00BFF0E0) --------------------------------------------------------
void *__cdecl sub_BFF0E0(int a1, wchar_t *a2, wchar_t *a3, void *a4, char a5)
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

  v5 = (wchar_t *)malloc(2u);
  v14.strValue[4] = (int)v5;
  *v5 = 0;
  v15 = 0;
  v6 = malloc(2u);
  v14.strValue[6] = (int)v6;
  *v6 = 0;
  v7 = a3;
  if ( !a3 )
    v7 = a2;
  v16 = v7;
  v14.strValue[0] = (int)malloc(2u);
  *(_WORD *)v14.strValue[0] = 0;
  v14.strValue[1] = 0;
  v14.strValue[2] = 0;
  v14.strValue[3] = 0;
  LOBYTE(v15) = 2;
  sub_BE7040(v7, (StringItem *)&v14);
  v8 = (const wchar_t **)sub_BE4EE0((int)&v14.strValue[5], a1, (int)&v14, 1);
  v9 = _wcsdup(*v8);
  v14.strValue[6] = (int)v9;
  free(v6);
  free((void *)v14.strValue[5]);
  if ( wcslen(v9) )
  {
    v10 = v5;
    v5 = _wcsdup(v16);
    v14.strValue[4] = (int)v5;
    free(v10);
    v11 = _wcsdup(v5);
    v12 = sub_BFE3A0(a1, a4, v16, v11, a5);
  }
  else
  {
    v12 = a4;
  }
  StringItem::~StringItem(&v14);
  free(v9);
  free(v5);
  return v12;
}

//----- (00BFF210) --------------------------------------------------------
CCmdString *__cdecl operator+(CCmdString *pszResult, LPCWSTR ppszText1, CCmdString *ppszText2)
{
  const wchar_t *v3; // ecx
  WCHAR *v4; // eax
  WCHAR *pszText1; // esi

  v3 = (const wchar_t *)&gszNullString;
  if ( ppszText1 )
    v3 = ppszText1;
  v4 = _wcsdup(v3);
  pszText1 = v4;
  ppszText1 = v4;
  CCmdString::Append(pszResult, (CCmdString *)&ppszText1, ppszText2);
  free(pszText1);
  return pszResult;
}

//----- (00BFF260) --------------------------------------------------------
void __cdecl sub_BFF260(int a1, int a2, wchar_t *a3, void *a4, ITaskFolder *pTaskFolder)
{
  ITaskFolder *v5; // esi
  void (__stdcall *v6)(BSTR); // ebx
  LONG (__stdcall *v7)(volatile LONG *); // edi
  Data_t_bstr_t *v8; // ecx
  __m128i v9; // xmm0
  IRegisteredTaskCollectionVtbl *v10; // edx
  IRegisteredTaskCollection *v11; // ST4C_4
  HRESULT v12; // esi
  _bstr_t *v13; // eax
  IRegisteredTaskVtbl *v14; // ecx
  int v15; // esi
  IActionCollectionVtbl *v16; // ecx
  IRegisteredTaskVtbl *v17; // ecx
  IExecActionVtbl *v18; // ecx
  OLECHAR *v19; // ebx
  bool v20; // al
  Data_t_bstr_t *v21; // esi
  _bstr_t *v22; // eax
  _bstr_t *v23; // eax
  Data_t_bstr_t *v24; // eax
  wchar_t *v25; // eax
  OLECHAR *v26; // edi
  const wchar_t *v27; // eax
  CCmdString *v28; // eax
  CCmdString *v29; // eax
  const WCHAR **v30; // eax
  const wchar_t *v31; // eax
  const WCHAR **v32; // eax
  char v33; // bl
  const wchar_t *v34; // eax
  const wchar_t *v35; // eax
  int v36; // ebx
  int v37; // eax
  const WCHAR **v38; // eax
  const wchar_t *v39; // eax
  IRegisteredTaskVtbl *v40; // ecx
  IComHandlerActionVtbl *v41; // ecx
  _WORD *v42; // eax
  Data_t_bstr_t *v43; // edi
  OLECHAR *v44; // eax
  _bstr_t *v45; // eax
  _bstr_t *v46; // eax
  _bstr_t *v47; // eax
  _bstr_t *v48; // esi
  Data_t_bstr_t *v49; // esi
  Data_t_bstr_t *v50; // esi
  Data_t_bstr_t *v51; // esi
  Data_t_bstr_t *v52; // esi
  Data_t_bstr_t *v53; // esi
  Data_t_bstr_t *v54; // esi
  Data_t_bstr_t *v55; // esi
  wchar_t *v56; // esi
  CCmdString *v57; // eax
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
  const wchar_t *v80; // eax
  IActionCollectionVtbl *v81; // edx
  Data_t_bstr_t *v82; // esi
  ITaskFolderVtbl *v83; // eax
  WCHAR *i; // eax
  __m128i v85; // xmm0
  IRegisteredTask v86; // edx
  IRegisteredTask *v87; // ST4C_4
  int v88; // esi
  IRegisteredTask *v89; // esi
  Data_t_bstr_t *v90; // eax
  Data_t_bstr_t *v91; // edi
  BSTR v92; // eax
  Data_t_bstr_t *v93; // eax
  Data_t_bstr_t *v94; // esi
  BSTR v95; // eax
  _bstr_t *v96; // eax
  GUID *v97; // ecx
  void **v98; // eax
  void *v99; // esi
  const wchar_t *v100; // [esp-14h] [ebp-1B0h]
  int v101; // [esp-10h] [ebp-1ACh]
  IActionCollection *v102; // [esp-Ch] [ebp-1A8h]
  GUID *v103; // [esp-8h] [ebp-1A4h]
  IRegisteredTask *pIRegisteredTask; // [esp-4h] [ebp-1A0h]
  int a2a; // [esp+10h] [ebp-18Ch]
  int v106; // [esp+14h] [ebp-188h]
  int v107; // [esp+18h] [ebp-184h]
  int v108; // [esp+1Ch] [ebp-180h]
  WCHAR *pszResult; // [esp+20h] [ebp-17Ch]
  VARIANTARG pvarg; // [esp+24h] [ebp-178h]
  CCmdString v111; // [esp+34h] [ebp-168h]
  tagPEStringStruct v112; // [esp+38h] [ebp-164h]
  _bstr_t v113; // [esp+54h] [ebp-148h]
  WCHAR *ppv; // [esp+58h] [ebp-144h]
  _bstr_t v115; // [esp+5Ch] [ebp-140h]
  _bstr_t bstrRet; // [esp+60h] [ebp-13Ch]
  void *v117; // [esp+64h] [ebp-138h]
  CCmdString v118; // [esp+68h] [ebp-134h]
  void *v119; // [esp+6Ch] [ebp-130h]
  CCmdString v120; // [esp+70h] [ebp-12Ch]
  CCmdString v121; // [esp+74h] [ebp-128h]
  WCHAR *ppv3; // [esp+78h] [ebp-124h]
  _bstr_t v123; // [esp+7Ch] [ebp-120h]
  void *v124; // [esp+80h] [ebp-11Ch]
  _bstr_t v125; // [esp+84h] [ebp-118h]
  _bstr_t v126; // [esp+88h] [ebp-114h]
  _bstr_t v127; // [esp+8Ch] [ebp-110h]
  CCmdString v128; // [esp+90h] [ebp-10Ch]
  void *v129; // [esp+94h] [ebp-108h]
  CCmdString strText; // [esp+98h] [ebp-104h]
  CCmdString str1; // [esp+9Ch] [ebp-100h]
  void *v132; // [esp+A0h] [ebp-FCh]
  void *v133; // [esp+A4h] [ebp-F8h]
  void *v134; // [esp+A8h] [ebp-F4h]
  void *v135; // [esp+ACh] [ebp-F0h]
  _bstr_t v136; // [esp+B0h] [ebp-ECh]
  _bstr_t v137; // [esp+B4h] [ebp-E8h]
  WCHAR *a4a; // [esp+B8h] [ebp-E4h]
  _bstr_t v139; // [esp+BCh] [ebp-E0h]
  CCmdString strId; // [esp+C0h] [ebp-DCh]
  int v141; // [esp+C4h] [ebp-D8h]
  void *v142; // [esp+C8h] [ebp-D4h]
  void *v143; // [esp+CCh] [ebp-D0h]
  void *v144; // [esp+D0h] [ebp-CCh]
  void *v145; // [esp+D4h] [ebp-C8h]
  void *v146; // [esp+D8h] [ebp-C4h]
  void *v147; // [esp+DCh] [ebp-C0h]
  CCmdString str2; // [esp+E0h] [ebp-BCh]
  void *v149; // [esp+E4h] [ebp-B8h]
  void *v150; // [esp+E8h] [ebp-B4h]
  CCmdString str3; // [esp+ECh] [ebp-B0h]
  _bstr_t v152; // [esp+F0h] [ebp-ACh]
  BSTR bstrString; // [esp+F4h] [ebp-A8h]
  DWORD dwValue; // [esp+F8h] [ebp-A4h]
  CCmdString v155; // [esp+FCh] [ebp-A0h]
  _bstr_t v156; // [esp+100h] [ebp-9Ch]
  int v157; // [esp+104h] [ebp-98h]
  _bstr_t v158; // [esp+108h] [ebp-94h]
  _bstr_t v159; // [esp+10Ch] [ebp-90h]
  int v160; // [esp+110h] [ebp-8Ch]
  ITaskDefinition *pITaskDefinition; // [esp+114h] [ebp-88h]
  _bstr_t v162; // [esp+118h] [ebp-84h]
  void *v163; // [esp+11Ch] [ebp-80h]
  CCmdString v164; // [esp+120h] [ebp-7Ch]
  HKEY hKey; // [esp+124h] [ebp-78h]
  IRegisteredTask *v166; // [esp+128h] [ebp-74h]
  CCmdString str; // [esp+12Ch] [ebp-70h]
  void *v168; // [esp+130h] [ebp-6Ch]
  void *v169; // [esp+134h] [ebp-68h]
  CCmdString strValue; // [esp+138h] [ebp-64h]
  IRegisteredTaskCollection *pIRegisteredTaskCollection; // [esp+13Ch] [ebp-60h]
  void *v172; // [esp+140h] [ebp-5Ch]
  _bstr_t v173; // [esp+144h] [ebp-58h]
  IActionCollection *pIActionCollection; // [esp+148h] [ebp-54h]
  void *v175; // [esp+14Ch] [ebp-50h]
  CCmdString v176; // [esp+150h] [ebp-4Ch]
  OLECHAR *psz; // [esp+154h] [ebp-48h]
  _bstr_t a3a; // [esp+158h] [ebp-44h]
  CCmdString v179; // [esp+15Ch] [ebp-40h]
  IRegisteredTask *v180; // [esp+160h] [ebp-3Ch]
  LPCWSTR lpszKeyName; // [esp+164h] [ebp-38h]
  IRegisteredTask *v182; // [esp+168h] [ebp-34h]
  void *v183; // [esp+16Ch] [ebp-30h]
  CCmdString v184; // [esp+170h] [ebp-2Ch]
  OLECHAR *v185; // [esp+174h] [ebp-28h]
  _bstr_t v186; // [esp+178h] [ebp-24h]
  unsigned int v187; // [esp+17Ch] [ebp-20h]
  OLECHAR *ppszText2; // [esp+180h] [ebp-1Ch]
  IExecAction *pIExecAction; // [esp+184h] [ebp-18h]
  IComHandlerAction *pIComHandlerAction; // [esp+188h] [ebp-14h]
  bool v191; // [esp+18Fh] [ebp-Dh]
  int v192; // [esp+198h] [ebp-4h]

  v187 = 0;
  lpszKeyName = 0;
  v5 = pTaskFolder;
  v192 = 0;
  pIRegisteredTaskCollection = 0;
  v6 = SysFreeString;
  v7 = InterlockedDecrement;
  if ( pTaskFolder->lpVtbl->GetTasks(pTaskFolder, 1, &pIRegisteredTaskCollection) < 0 )
    goto LABEL_196;
  v183 = 0;
  pIRegisteredTaskCollection->lpVtbl->get_Count(pIRegisteredTaskCollection, (LONG *)&v183);
  v8 = 0;
  if ( (signed int)v183 <= 0 )
    goto LABEL_195;
  do
  {
    v180 = 0;
    a3a.m_Data = (Data_t_bstr_t *)((char *)v8 + 1);
    pvarg.vt = 3;
    pvarg.lVal = (LONG)&v8->m_wstr + 1;
    v9 = _mm_loadu_si128((const __m128i *)&pvarg);
    pIRegisteredTask = (IRegisteredTask *)&v180;
    LOBYTE(v192) = 1;
    v10 = pIRegisteredTaskCollection->lpVtbl;
    v11 = pIRegisteredTaskCollection;
    _mm_storeu_si128((__m128i *)&v100, v9);
    v12 = v10->get_Item(v11, *(VARIANT *)&v100, (IRegisteredTask **)pIRegisteredTask);
    LOBYTE(v192) = 0;
    VariantClear(&pvarg);
    if ( v12 < 0 )
      goto LABEL_193;
    bstrString = 0;
    pIRegisteredTask = (IRegisteredTask *)&bstrString;
    v103 = (GUID *)v180;
    if ( v180->lpVtbl->get_Name(v180, &bstrString) < 0 )
      goto LABEL_192;
    _bstr_t::_bstr_t((tagEventSetItem *)&v126, bstrString);
    LOBYTE(v192) = 2;
    _bstr_t::_bstr_t((tagEventSetItem *)&v137, L"\\");
    LOBYTE(v192) = 3;
    v13 = _bstr_t::operator+((_bstr_t *)&a4, &bstrRet, &v137);
    LOBYTE(v192) = 4;
    _bstr_t::operator+(v13, &v173, &v126);
    _bstr_t::_Free(&bstrRet);
    _bstr_t::_Free(&v137);
    LOBYTE(v192) = 8;
    _bstr_t::_Free(&v126);
    v141 = 1;
    pIRegisteredTask = (IRegisteredTask *)&v141;
    v103 = (GUID *)v180;
    v180->lpVtbl->get_Enabled(v180, (VARIANT_BOOL *)&v141);
    pITaskDefinition = 0;
    pIRegisteredTask = (IRegisteredTask *)&pITaskDefinition;
    v14 = v180->lpVtbl;
    v191 = (_WORD)v141 != 0;
    v103 = (GUID *)v180;
    if ( v14->get_Definition(v180, &pITaskDefinition) < 0 )
      goto LABEL_183;
    pIActionCollection = 0;
    pIRegisteredTask = (IRegisteredTask *)&pIActionCollection;
    v103 = (GUID *)pITaskDefinition;
    if ( pITaskDefinition->lpVtbl->get_Actions(pITaskDefinition, &pIActionCollection) < 0 )
      goto LABEL_182;
    v15 = 0;
    pIRegisteredTask = (IRegisteredTask *)&v182;
    v182 = 0;
    v16 = pIActionCollection->lpVtbl;
    v103 = (GUID *)1;
    v102 = pIActionCollection;
    v157 = 0;
    if ( v16->get_Item(pIActionCollection, 1, (IAction **)&v182) < 0 )
      goto LABEL_181;
    do
    {
      v160 = -1;
      pIRegisteredTask = (IRegisteredTask *)&v160;
      v103 = (GUID *)v182;
      v182->lpVtbl->get_State(v182, (TASK_STATE *)&v160);
      if ( !v160 )
      {
        pIRegisteredTask = (IRegisteredTask *)&pIExecAction;
        pIExecAction = 0;
        v103 = &CLSID_IExecAction;
        v17 = v182->lpVtbl;
        v102 = (IActionCollection *)v182;
        if ( v17->QueryInterface(v182, &CLSID_IExecAction, (void **)&pIExecAction) >= 0 )
        {
          pIComHandlerAction = 0;
          lpszKeyName = 0;
          v185 = 0;
          v18 = pIExecAction->lpVtbl;
          pIRegisteredTask = (IRegisteredTask *)&pIComHandlerAction;
          v103 = (GUID *)pIExecAction;
          if ( v18->get_Path(pIExecAction, (BSTR *)&pIComHandlerAction) >= 0 && pIComHandlerAction )
          {
            pIRegisteredTask = (IRegisteredTask *)&lpszKeyName;
            v103 = (GUID *)pIExecAction;
            pIExecAction->lpVtbl->get_Arguments(pIExecAction, (BSTR *)&lpszKeyName);
            pIRegisteredTask = (IRegisteredTask *)&v185;
            v103 = (GUID *)pIExecAction;
            pIExecAction->lpVtbl->get_WorkingDirectory(pIExecAction, &v185);
            pIRegisteredTask = (IRegisteredTask *)sub_BEF8D0(&v111, (wchar_t *)pIComHandlerAction)->m_String;
            LOBYTE(v192) = 9;
            _bstr_t::_bstr_t((tagEventSetItem *)&v162, (OLECHAR *)pIRegisteredTask);
            free(v111.m_String);
            v19 = (OLECHAR *)malloc(2u);
            ppszText2 = v19;
            *v19 = 0;
            a4a = (WCHAR *)malloc(2u);
            *a4a = 0;
            LOBYTE(v192) = 13;
            v20 = PE_GetPathName(a1, gpszSystemPathInfo, (LPCWSTR)pIComHandlerAction, (CCmdString *)&a4a);
            v21 = v162.m_Data;
            if ( v20 || wcschr((const wchar_t *)pIComHandlerAction, 0x5Cu) || !v185 )
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
              _bstr_t::_bstr_t((tagEventSetItem *)&v139, L"\\");
              LOBYTE(v192) = 14;
              v22 = (_bstr_t *)_bstr_t::_bstr_t((tagEventSetItem *)&v112.strValue[5], v185);
              LOBYTE(v192) = 15;
              v23 = _bstr_t::operator+(v22, &v113, &v139);
              LOBYTE(v192) = 16;
              v24 = _bstr_t::operator+(v23, &v115, &v162)->m_Data;
              if ( v24 )
                v25 = v24->m_wstr;
              else
                v25 = 0;
              CCmdString::Reset((CCmdString *)&ppszText2, v25);
              _bstr_t::_Free(&v115);
              _bstr_t::_Free(&v113);
              _bstr_t::_Free((_bstr_t *)&v112.strValue[5]);
              _bstr_t::_Free(&v139);
              v26 = ppszText2;
            }
            v169 = malloc(2u);
            *(_WORD *)v169 = 0;
            v168 = malloc(2u);
            *(_WORD *)v168 = 0;
            v28 = operator+((CCmdString *)&pszResult, L"\"", (CCmdString *)&ppszText2);
            v29 = CCmdString::operator+((CCmdString *)&ppv, v28, L"\" ");
            CCmdString::operator+(&str, v29, lpszKeyName);
            free(ppv);
            free(pszResult);
            a2a = (int)malloc(2u);
            *(_WORD *)a2a = 0;
            v106 = 0;
            v107 = 0;
            v108 = 0;
            LOBYTE(v192) = 20;
            sub_BE6CC0(str.m_String, (StringItem *)&a2a);
            sub_BE4EE0((int)&strValue, a1, (int)&a2a, 0);
            LOBYTE(v192) = 21;
            v100 = (const wchar_t *)&v168;
            dwValue = sub_BE4ED0();
            v164.m_String = (WCHAR *)malloc(2u);
            *v164.m_String = 0;
            if ( !v21 || (v30 = (const WCHAR **)v21->m_wstr) == 0 )
              v30 = &gszNullString;
            v134 = _wcsdup((const wchar_t *)v30);
            v31 = (const wchar_t *)&gszNullString;
            if ( a3 )
              v31 = a3;
            v117 = _wcsdup(v31);
            if ( !v21 || (v32 = (const WCHAR **)v21->m_wstr) == 0 )
              v32 = &gszNullString;
            v121.m_String = _wcsdup((const wchar_t *)v32);
            LOBYTE(v192) = 25;
            v33 = sub_BE3D40(
                    a1,
                    (CCmdString)&v121,
                    (int)&v117,
                    (int)&v134,
                    (int)&strValue,
                    (int)&v169,
                    (CCmdString)&v164,
                    (int)&v112.strValue[6]);
            free(v121.m_String);
            free(v117);
            free(v134);
            if ( v33 )
            {
              if ( *(_DWORD *)a2 == -1 )
              {
                v142 = _wcsdup((const wchar_t *)&gszNullString);
                v133 = _wcsdup((const wchar_t *)&gszNullString);
                v144 = _wcsdup((const wchar_t *)&gszNullString);
                v135 = _wcsdup((const wchar_t *)&gszNullString);
                v146 = _wcsdup((const wchar_t *)&gszNullString);
                str3.m_String = _wcsdup((const wchar_t *)&gszNullString);
                v34 = (const wchar_t *)&gszNullString;
                if ( a3 )
                  v34 = a3;
                str2.m_String = _wcsdup(v34);
                v35 = (const wchar_t *)&gszNullString;
                if ( a3 )
                  v35 = a3;
                ppv3 = _wcsdup(v35);
                v36 = a1;
                LOBYTE(v192) = 33;
                v37 = PE_UpdateSystemKey(a1, 2u, *(HANDLE *)a2, 0, (CCmdString *)&ppv3, &str2, &str3);
                pIRegisteredTask = (IRegisteredTask *)ppv3;
                *(_DWORD *)a2 = v37;
                free(pIRegisteredTask);
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
              v129 = _wcsdup((const wchar_t *)&gszNullString);
              if ( !v21 || (v38 = (const WCHAR **)v21->m_wstr) == 0 )
                v38 = &gszNullString;
              strId.m_String = _wcsdup((const wchar_t *)v38);
              if ( !v173.m_Data || (v39 = v173.m_Data->m_wstr) == 0 )
                v39 = (const wchar_t *)&gszNullString;
              str1.m_String = _wcsdup(v39);
              v103 = (GUID *)-1;
              v102 = 0;
              v101 = 0;
              LOBYTE(v192) = 36;
              v100 = (const wchar_t *)&v129;
              PE_UpdateSystemKey(v36, dwValue, *(HANDLE *)a2, 9u, &str1, &strId, &strValue);
              free(str1.m_String);
              free(strId.m_String);
              free(v129);
            }
            free(v164.m_String);
            free(strValue.m_String);
            StringItem::~StringItem((tagPEStringStruct *)&a2a);
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
          pIRegisteredTask = (IRegisteredTask *)pIExecAction;
          pIExecAction->lpVtbl->Release(pIExecAction);
        }
      }
      if ( v160 != 5 )
        goto LABEL_179;
      pIRegisteredTask = (IRegisteredTask *)&pIComHandlerAction;
      pIComHandlerAction = 0;
      v103 = &CLSID_IComHandlerAction;
      v40 = v182->lpVtbl;
      v102 = (IActionCollection *)v182;
      if ( v40->QueryInterface(v182, &CLSID_IComHandlerAction, (void **)&pIComHandlerAction) < 0 )
        goto LABEL_179;
      pIExecAction = 0;
      dwValue = 0;
      pIRegisteredTask = (IRegisteredTask *)&pIExecAction;
      v41 = pIComHandlerAction->lpVtbl;
      v103 = (GUID *)pIComHandlerAction;
      v41->get_ClassId(pIComHandlerAction, (BSTR *)&pIExecAction);
      pIRegisteredTask = (IRegisteredTask *)&dwValue;
      v103 = (GUID *)pIComHandlerAction;
      pIComHandlerAction->lpVtbl->get_Data(pIComHandlerAction, (BSTR *)&dwValue);
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
        _bstr_t::_bstr_t((tagEventSetItem *)&v159, (&gpszServiceType)[(_DWORD)v44]);
        LOBYTE(v192) = 39;
        _bstr_t::_bstr_t((tagEventSetItem *)&v156, L"\\");
        LOBYTE(v192) = 40;
        _bstr_t::_bstr_t((tagEventSetItem *)&v158, (OLECHAR *)pIExecAction);
        LOBYTE(v192) = 41;
        v45 = (_bstr_t *)_bstr_t::_bstr_t((tagEventSetItem *)&v123, L"CLSID\\");
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
        v49 = v127.m_Data;
        if ( v127.m_Data )
        {
          if ( !InterlockedDecrement(&v127.m_Data->m_RefCount) && v49 )
          {
            if ( v49->m_wstr )
            {
              v6(v49->m_wstr);
              v49->m_wstr = 0;
            }
            if ( v49->m_str )
            {
              operator delete[](v49->m_str);
              v49->m_str = 0;
            }
            operator delete(v49);
          }
          v127.m_Data = 0;
        }
        v50 = v136.m_Data;
        if ( v136.m_Data )
        {
          if ( !InterlockedDecrement(&v136.m_Data->m_RefCount) && v50 )
          {
            if ( v50->m_wstr )
            {
              v6(v50->m_wstr);
              v50->m_wstr = 0;
            }
            if ( v50->m_str )
            {
              operator delete[](v50->m_str);
              v50->m_str = 0;
            }
            operator delete(v50);
          }
          v136.m_Data = 0;
        }
        v51 = v125.m_Data;
        if ( v125.m_Data )
        {
          if ( !InterlockedDecrement(&v125.m_Data->m_RefCount) && v51 )
          {
            if ( v51->m_wstr )
            {
              v6(v51->m_wstr);
              v51->m_wstr = 0;
            }
            if ( v51->m_str )
            {
              operator delete[](v51->m_str);
              v51->m_str = 0;
            }
            operator delete(v51);
          }
          v125.m_Data = 0;
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
              operator delete[](v52->m_str);
              v52->m_str = 0;
            }
            operator delete(v52);
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
              operator delete[](v53->m_str);
              v53->m_str = 0;
            }
            operator delete(v53);
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
              operator delete[](v54->m_str);
              v54->m_str = 0;
            }
            operator delete(v54);
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
              operator delete[](v55->m_str);
              v55->m_str = 0;
            }
            operator delete(v55);
          }
          v159.m_Data = 0;
        }
        v56 = _wcsdup(L"HKCR\\CLSID\\");
        lpszKeyName = v56;
        v57 = CCmdString::operator+((CCmdString *)&v112.strValue[4], (CCmdString *)&lpszKeyName, (LPCWSTR)pIExecAction);
        v58 = v172;
        v100 = v57->m_String;
        v172 = _wcsdup(v100);
        free(v58);
        free((void *)v112.strValue[4]);
        free(v56);
        if ( v43 )
          v59 = v43->m_wstr;
        else
          v59 = 0;
        pIRegisteredTask = (IRegisteredTask *)&hKey;
        v60 = (unsigned int)TlsGetValue(gdwTlsIndex);
        if ( PE_OpenKey(HKEY_CLASSES_ROOT, v59, 0, v60 | 1, (PHKEY)pIRegisteredTask) )
        {
          v61 = v43 ? v43->m_wstr : 0;
          if ( PE_OpenKey(HKEY_CLASSES_ROOT, v61, 0, 1u, &hKey) )
            goto LABEL_126;
        }
        ppszText2 = (OLECHAR *)malloc(2u);
        *ppszText2 = 0;
        LOBYTE(v192) = 45;
        v62 = PE_ReadRegKey(hKey, (LPCWSTR)&gszNullString, 0, 0, (CCmdString *)&ppszText2);
        if ( !v62 )
        {
          _bstr_t::operator=((EventItem *)&v186, ppszText2);
          v43 = v186.m_Data;
        }
        RegCloseKey(hKey);
        pIRegisteredTask = (IRegisteredTask *)ppszText2;
        if ( !v62 )
          break;
        LOBYTE(v192) = 38;
        free(pIRegisteredTask);
LABEL_126:
        v6 = SysFreeString;
        v44 = (OLECHAR *)((char *)v185 + 1);
        v185 = v44;
        if ( (unsigned int)v44 >= 4 )
          goto LABEL_129;
      }
      free(pIRegisteredTask);
LABEL_129:
      v112.strValue[0] = (int)malloc(2u);
      *(_WORD *)v112.strValue[0] = 0;
      v112.strValue[1] = 0;
      v112.strValue[2] = 0;
      v112.strValue[3] = 0;
      v175 = malloc(2u);
      *(_WORD *)v175 = 0;
      v163 = malloc(2u);
      *(_WORD *)v163 = 0;
      v184.m_String = (WCHAR *)malloc(2u);
      *v184.m_String = 0;
      v63 = -1;
      LOBYTE(v192) = 49;
      if ( (unsigned int)v185 >= 4 )
      {
        _bstr_t::operator=((EventItem *)&v186, (OLECHAR *)pIExecAction);
        v43 = v186.m_Data;
        if ( v186.m_Data )
          v67 = v186.m_Data->m_wstr;
        else
          v67 = 0;
        sub_BE7040(v67, (StringItem *)&v112);
      }
      else
      {
        if ( v43 )
          v64 = v43->m_wstr;
        else
          v64 = 0;
        sub_BE7040(v64, (StringItem *)&v112);
        v65 = (const wchar_t **)sub_BE4EE0((int)&v119, a1, (int)&v112, 0);
        v66 = v184.m_String;
        v184.m_String = _wcsdup(*v65);
        free(v66);
        free(v119);
        v63 = sub_BE4ED0();
      }
      v155.m_String = (WCHAR *)malloc(2u);
      *v155.m_String = 0;
      if ( !wcslen(v184.m_String) )
        goto LABEL_243;
      if ( !v43 || (v68 = (const WCHAR **)v43->m_wstr) == 0 )
        v68 = &gszNullString;
      v124 = _wcsdup((const wchar_t *)v68);
      v69 = (const wchar_t *)&gszNullString;
      v70 = v187 | 1;
      if ( a3 )
        v69 = a3;
      v132 = _wcsdup(v69);
      v71 = v70 | 2;
      if ( !v43 || (v72 = (const WCHAR **)v43->m_wstr) == 0 )
        v72 = &gszNullString;
      v118.m_String = _wcsdup((const wchar_t *)v72);
      v192 = 53;
      v187 = v71 | 4;
      lpszKeyName = (LPCWSTR)(v71 | 4);
      if ( (unsigned __int8)sub_BE3D40(
                              a1,
                              (CCmdString)&v118,
                              (int)&v132,
                              (int)&v124,
                              (int)&v184,
                              (int)&v175,
                              (CCmdString)&v155,
                              (int)&v152) )
        v73 = 1;
      else
LABEL_243:
        v73 = 0;
      v74 = v187;
      if ( v187 & 4 )
      {
        v187 &= 0xFFFFFFFB;
        free(v118.m_String);
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
        if ( *(_DWORD *)a2 == -1 )
        {
          v143 = _wcsdup((const wchar_t *)&gszNullString);
          v145 = _wcsdup((const wchar_t *)&gszNullString);
          v147 = _wcsdup((const wchar_t *)&gszNullString);
          v149 = _wcsdup((const wchar_t *)&gszNullString);
          v150 = _wcsdup((const wchar_t *)&gszNullString);
          v128.m_String = _wcsdup((const wchar_t *)&gszNullString);
          v75 = (const wchar_t *)&gszNullString;
          if ( a3 )
            v75 = a3;
          v120.m_String = _wcsdup(v75);
          v76 = (const wchar_t *)&gszNullString;
          if ( a3 )
            v76 = a3;
          strText.m_String = _wcsdup(v76);
          v77 = a1;
          LOBYTE(v192) = 61;
          v78 = PE_UpdateSystemKey(a1, 2u, *(HANDLE *)a2, 0, &strText, &v120, &v128);
          pIRegisteredTask = (IRegisteredTask *)strText.m_String;
          *(_DWORD *)a2 = v78;
          free(pIRegisteredTask);
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
        psz = _wcsdup((const wchar_t *)&gszNullString);
        if ( !v43 || (v79 = (const WCHAR **)v43->m_wstr) == 0 )
          v79 = &gszNullString;
        v179.m_String = _wcsdup((const wchar_t *)v79);
        if ( !v173.m_Data || (v80 = v173.m_Data->m_wstr) == 0 )
          v80 = (const wchar_t *)&gszNullString;
        v176.m_String = _wcsdup(v80);
        v103 = (GUID *)-1;
        v102 = 0;
        v101 = 0;
        LOBYTE(v192) = 64;
        v100 = (const wchar_t *)&psz;
        PE_UpdateSystemKey(v77, v63, *(HANDLE *)a2, 9u, &v176, &v179, &v184);
        free(v176.m_String);
        free(v179.m_String);
        LOBYTE(v192) = 50;
        free(psz);
      }
      pIRegisteredTask = (IRegisteredTask *)pIComHandlerAction;
      pIComHandlerAction->lpVtbl->Release(pIComHandlerAction);
      free(v155.m_String);
      free(v184.m_String);
      free(v163);
      free(v175);
      StringItem::~StringItem(&v112);
      if ( v43 && !InterlockedDecrement(&v43->m_RefCount) )
      {
        if ( v43->m_wstr )
        {
          SysFreeString(v43->m_wstr);
          v43->m_wstr = 0;
        }
        if ( v43->m_str )
        {
          operator delete[](v43->m_str);
          v43->m_str = 0;
        }
        operator delete(v43);
      }
      LOBYTE(v192) = 8;
      free(v172);
      v15 = v157;
LABEL_179:
      pIRegisteredTask = v182;
      v182->lpVtbl->Release(v182);
      ++v15;
      v182 = 0;
      pIRegisteredTask = (IRegisteredTask *)&v182;
      v157 = v15;
      v81 = pIActionCollection->lpVtbl;
      v103 = (GUID *)(v15 + 1);
      v102 = pIActionCollection;
      v6 = SysFreeString;
    }
    while ( v81->get_Item(pIActionCollection, v15 + 1, (IAction **)&v182) >= 0 );
    v7 = InterlockedDecrement;
LABEL_181:
    pIRegisteredTask = (IRegisteredTask *)pIActionCollection;
    pIActionCollection->lpVtbl->Release(pIActionCollection);
LABEL_182:
    pIRegisteredTask = (IRegisteredTask *)pITaskDefinition;
    pITaskDefinition->lpVtbl->Release(pITaskDefinition);
LABEL_183:
    v6(bstrString);
    v82 = v173.m_Data;
    LOBYTE(v192) = 0;
    if ( v173.m_Data )
    {
      if ( !v7(&v173.m_Data->m_RefCount) && v82 )
      {
        if ( v82->m_wstr )
        {
          v6(v82->m_wstr);
          v82->m_wstr = 0;
        }
        if ( v82->m_str )
        {
          operator delete[](v82->m_str);
          v82->m_str = 0;
        }
        operator delete(v82);
      }
      v173.m_Data = 0;
    }
LABEL_192:
    pIRegisteredTask = v180;
    v180->lpVtbl->Release(v180);
LABEL_193:
    v8 = a3a.m_Data;
  }
  while ( (signed int)a3a.m_Data < (signed int)v183 );
  v5 = pTaskFolder;
LABEL_195:
  pIRegisteredTask = (IRegisteredTask *)pIRegisteredTaskCollection;
  pIRegisteredTaskCollection->lpVtbl->Release(pIRegisteredTaskCollection);
LABEL_196:
  v83 = v5->lpVtbl;
  pIRegisteredTask = (IRegisteredTask *)&v166;
  v103 = 0;
  v102 = (IActionCollection *)v5;
  v166 = 0;
  if ( v83->GetFolders(v5, 0, (ITaskFolderCollection **)&v166) >= 0 )
  {
    for ( i = (WCHAR *)1; ; i = (WCHAR *)((char *)v176.m_String + 1) )
    {
      v176.m_String = i;
      pTaskFolder = 0;
      pvarg.vt = 3;
      pvarg.lVal = (LONG)i;
      v85 = _mm_loadu_si128((const __m128i *)&pvarg);
      pIRegisteredTask = (IRegisteredTask *)&pTaskFolder;
      LOBYTE(v192) = 65;
      v86.lpVtbl = v166->lpVtbl;
      v87 = v166;
      _mm_storeu_si128((__m128i *)&v100, v85);
      v88 = ((int (__stdcall *)(IRegisteredTask *, const wchar_t *, int, IActionCollection *, GUID *, IRegisteredTask *))v86.lpVtbl->get_Path)(
              v87,
              v100,
              v101,
              v102,
              v103,
              pIRegisteredTask);
      LOBYTE(v192) = 0;
      VariantClear(&pvarg);
      if ( v88 < 0 )
        break;
      psz = 0;
      pIRegisteredTask = (IRegisteredTask *)&psz;
      v103 = (GUID *)pTaskFolder;
      pTaskFolder->lpVtbl->get_Name(pTaskFolder, &psz);
      v89 = (IRegisteredTask *)psz;
      v90 = (Data_t_bstr_t *)operator new(0xCu);
      v91 = v90;
      a3a.m_Data = v90;
      LOBYTE(v192) = 66;
      if ( v90 )
      {
        pIRegisteredTask = v89;
        v90->m_str = 0;
        v90->m_RefCount = 1;
        v92 = SysAllocString((const OLECHAR *)pIRegisteredTask);
        v91->m_wstr = v92;
        if ( !v92 && v89 )
          goto LABEL_202;
      }
      else
      {
        v91 = 0;
      }
      LOBYTE(v192) = 0;
      v152.m_Data = v91;
      if ( !v91 )
        goto LABEL_202;
      LOBYTE(v192) = 67;
      v93 = (Data_t_bstr_t *)operator new(0xCu);
      v94 = v93;
      a3a.m_Data = v93;
      LOBYTE(v192) = 68;
      if ( v93 )
      {
        pIRegisteredTask = (IRegisteredTask *)L"\\";
        v93->m_str = 0;
        v93->m_RefCount = 1;
        v95 = SysAllocString((const OLECHAR *)pIRegisteredTask);
        v94->m_wstr = v95;
        if ( !v95 )
          goto LABEL_202;
      }
      else
      {
        v94 = 0;
      }
      LOBYTE(v192) = 67;
      a3a.m_Data = v94;
      if ( !v94 )
LABEL_202:
        _com_issue_error(-2147024882);
      pIRegisteredTask = (IRegisteredTask *)pTaskFolder;
      LOBYTE(v192) = 69;
      v96 = _bstr_t::operator+((_bstr_t *)&a4, (_bstr_t *)&v179, &a3a);
      v103 = v97;
      LOBYTE(v192) = 70;
      _bstr_t::operator+(v96, (_bstr_t *)&v103, &v152);
      sub_BFF260(a1, a2, a3, v103, (ITaskFolder *)pIRegisteredTask);
      v183 = v179.m_String;
      if ( v179.m_String )
      {
        if ( !InterlockedDecrement((volatile LONG *)v179.m_String + 2) )
        {
          v98 = (void **)v183;
          if ( v183 )
          {
            if ( *(_DWORD *)v183 )
            {
              v6(*(BSTR *)v183);
              v98 = (void **)v183;
              *(_DWORD *)v183 = 0;
            }
            if ( v98[1] )
            {
              operator delete[](v98[1]);
              v98 = (void **)v183;
              *((_DWORD *)v183 + 1) = 0;
            }
            operator delete(v98);
          }
        }
        v179.m_String = 0;
      }
      if ( !InterlockedDecrement(&v94->m_RefCount) )
      {
        if ( v94->m_wstr )
        {
          v6(v94->m_wstr);
          v94->m_wstr = 0;
        }
        if ( v94->m_str )
        {
          operator delete[](v94->m_str);
          v94->m_str = 0;
        }
        operator delete(v94);
      }
      LOBYTE(v192) = 0;
      if ( !InterlockedDecrement(&v91->m_RefCount) )
      {
        if ( v91->m_wstr )
        {
          v6(v91->m_wstr);
          v91->m_wstr = 0;
        }
        if ( v91->m_str )
        {
          operator delete[](v91->m_str);
          v91->m_str = 0;
        }
        operator delete(v91);
      }
      pIRegisteredTask = (IRegisteredTask *)pTaskFolder;
      pTaskFolder->lpVtbl->Release(pTaskFolder);
    }
    pIRegisteredTask = v166;
    v166->lpVtbl->Release(v166);
    v7 = InterlockedDecrement;
  }
  v99 = a4;
  if ( a4 && !v7((volatile LONG *)a4 + 2) && v99 )
  {
    if ( *(_DWORD *)v99 )
    {
      v6(*(BSTR *)v99);
      *(_DWORD *)v99 = 0;
    }
    if ( *((_DWORD *)v99 + 1) )
    {
      operator delete[](*((void **)v99 + 1));
      *((_DWORD *)v99 + 1) = 0;
    }
    operator delete(v99);
  }
}
// C8C4A8: using guessed type int (__stdcall *)(_DWORD);
// CB781C: using guessed type GUID CLSID_IExecAction;
// CB783C: using guessed type GUID CLSID_IComHandlerAction;

//----- (00C00760) --------------------------------------------------------
void __cdecl sub_C00760(int a1)
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
  CCmdString *v12; // eax
  CCmdString *v13; // eax
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
  CCmdString v27; // [esp+28h] [ebp-C8h]
  LPVOID pszWorkingDirectory; // [esp+2Ch] [ebp-C4h]
  CCmdString str; // [esp+30h] [ebp-C0h]
  int a2; // [esp+34h] [ebp-BCh]
  _bstr_t bstrName; // [esp+38h] [ebp-B8h]
  int a8; // [esp+3Ch] [ebp-B4h]
  ITaskTrigger *pTaskTrigger; // [esp+40h] [ebp-B0h]
  CCmdString str2; // [esp+44h] [ebp-ACh]
  void *v35; // [esp+48h] [ebp-A8h]
  CCmdString str1; // [esp+4Ch] [ebp-A4h]
  void *v37; // [esp+50h] [ebp-A0h]
  LPVOID szApplicationName; // [esp+54h] [ebp-9Ch]
  void *v39; // [esp+58h] [ebp-98h]
  void *v40; // [esp+5Ch] [ebp-94h]
  void *v41; // [esp+60h] [ebp-90h]
  void *v42; // [esp+64h] [ebp-8Ch]
  void *ppv1; // [esp+68h] [ebp-88h]
  void *v44; // [esp+6Ch] [ebp-84h]
  LPCWSTR pszParameters; // [esp+70h] [ebp-80h]
  CCmdString strValue; // [esp+74h] [ebp-7Ch]
  CCmdString v47; // [esp+78h] [ebp-78h]
  ITaskScheduler *ppv; // [esp+7Ch] [ebp-74h]
  int v49; // [esp+80h] [ebp-70h]
  void *v50; // [esp+84h] [ebp-6Ch]
  IEnumWorkItems *pEnumWorkItems; // [esp+88h] [ebp-68h]
  void *v52; // [esp+8Ch] [ebp-64h]
  void *wTaskCount; // [esp+90h] [ebp-60h]
  WCHAR *ppv3; // [esp+94h] [ebp-5Ch]
  WCHAR *hKey; // [esp+98h] [ebp-58h]
  CCmdString v56; // [esp+9Ch] [ebp-54h]
  CCmdString str3; // [esp+A0h] [ebp-50h]
  LPVOID pszNames; // [esp+A4h] [ebp-4Ch]
  void *cbRet; // [esp+A8h] [ebp-48h]
  ITask *pTask; // [esp+ACh] [ebp-44h]
  TASK_TRIGGER TaskTrigger; // [esp+B0h] [ebp-40h]
  int v62; // [esp+ECh] [ebp-4h]

  v1 = a1;
  v49 = a1;
  if ( !gKeyNameMap._Mypair._Myval2._Mysize )
  {
    if ( (unsigned __int8)GetVersion() < 6u )
    {
      v2 = malloc(2u);
      v52 = v2;
      *v2 = 0;
      v62 = 0;
      v3 = malloc(2u);
      v50 = v3;
      *v3 = 0;
      v4 = (WCHAR *)malloc(2u);
      v47.m_String = v4;
      *v4 = 0;
      wTaskCount = _wcsdup((const wchar_t *)&gszNullString);
      pTask = (ITask *)_wcsdup((const wchar_t *)&gszNullString);
      cbRet = _wcsdup((const wchar_t *)&gszNullString);
      pszNames = _wcsdup((const wchar_t *)&gszNullString);
      v56.m_String = _wcsdup((const wchar_t *)&gszNullString);
      str3.m_String = _wcsdup((const wchar_t *)&gszNullString);
      v5 = (const wchar_t *)&gszNullString;
      if ( gpszTaskScheduler )
        v5 = gpszTaskScheduler;
      hKey = _wcsdup(v5);
      v6 = (const wchar_t *)&gszNullString;
      if ( gpszTaskScheduler )
        v6 = gpszTaskScheduler;
      ppv3 = _wcsdup(v6);
      LOBYTE(v62) = 10;
      ppv1 = (void *)PE_UpdateSystemKey(a1, 2u, (HANDLE)0xFFFFFFFF, 0, (CCmdString *)&ppv3, (CCmdString *)&hKey, &str3);
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
        && CoCreateInstance(&CLSID_CLSID_CTaskScheduler, 0, 1u, &CLSID_ITaskScheduler, (LPVOID *)&ppv) >= 0 )
      {
        pEnumWorkItems = 0;
        if ( ppv->lpVtbl->Enum(ppv, &pEnumWorkItems) >= 0 )
        {
          for ( cbRet = 0;
                pEnumWorkItems->lpVtbl->Next(pEnumWorkItems, 2, (LPWSTR **)&pszNames, (ULONG *)&cbRet) >= 0;
                cbRet = 0 )
          {
            if ( !cbRet )
              break;
            dwNameIndex = 0;
            if ( cbRet )
            {
              do
              {
                if ( ppv->lpVtbl->Activate(
                       ppv,
                       (LPCWSTR)*((_DWORD *)pszNames + dwNameIndex),
                       &CLSID_ITask,
                       (IUnknown **)&pTask) >= 0 )
                {
                  wTaskCount = 0;
                  pTask->lpVtbl->GetTriggerCount(pTask, (WORD *)&wTaskCount);
                  if ( (unsigned __int16)wTaskCount > 0u && pTask->lpVtbl->GetTrigger(pTask, 0, &pTaskTrigger) >= 0 )
                  {
                    *(_DWORD *)&TaskTrigger.cbTriggerSize = sizeof(TASK_TRIGGER);
                    memset(&TaskTrigger.wBeginYear, 0, 0x2Cu);
                    if ( pTaskTrigger->lpVtbl->GetTrigger(pTaskTrigger, &TaskTrigger) >= 0
                      && pTask->lpVtbl->GetApplicationName(pTask, (LPWSTR *)&szApplicationName) >= 0 )
                    {
                      v8 = (const WCHAR ***)*_bstr_t::_bstr_t(
                                               (tagEventSetItem *)&bstrAppName,
                                               (OLECHAR *)szApplicationName);
                      if ( !v8 || (v9 = *v8) == 0 )
                        v9 = &gszNullString;
                      hKey = _wcsdup((const wchar_t *)v9);
                      LOBYTE(v62) = 11;
                      _bstr_t::_Free(&bstrAppName);
                      v10 = (const WCHAR ***)*_bstr_t::_bstr_t(
                                                (tagEventSetItem *)&bstrName,
                                                *((OLECHAR **)pszNames + dwNameIndex));
                      if ( !v10 || (v11 = *v10) == 0 )
                        v11 = &gszNullString;
                      ppv3 = _wcsdup((const wchar_t *)v11);
                      LOBYTE(v62) = 12;
                      _bstr_t::_Free(&bstrName);
                      pTask->lpVtbl->GetParameters(pTask, (LPWSTR *)&pszParameters);
                      pTask->lpVtbl->GetFlags(pTask, (DWORD *)&dwFlags);
                      pTask->lpVtbl->GetWorkingDirectory(pTask, (LPWSTR *)&pszWorkingDirectory);
                      str3.m_String = (WCHAR *)malloc(2u);
                      *str3.m_String = 0;
                      v12 = CCmdString::operator+(&str, (CCmdString *)&hKey, L" ");
                      v13 = CCmdString::operator+(&v27, v12, pszParameters);
                      CCmdString::InsertAt(&str3, v13->m_String, 0x7FFFFFFFu, 0);
                      free(v27.m_String);
                      free(str.m_String);
                      *(_DWORD *)pszText2 = malloc(2u);
                      **(_WORD **)pszText2 = 0;
                      v22 = 0;
                      v23 = 0;
                      v24 = 0;
                      LOBYTE(v62) = 14;
                      sub_BE6CC0(str3.m_String, (StringItem *)pszText2);
                      sub_BE4EE0((int)&v56, v1, (int)pszText2, 0);
                      LOBYTE(v62) = 15;
                      v14 = sub_BE4ED0();
                      v15 = (const wchar_t *)&gszNullString;
                      a2 = v14;
                      if ( gpszTaskScheduler )
                        v15 = gpszTaskScheduler;
                      v35 = _wcsdup(v15);
                      LOBYTE(v62) = 16;
                      v16 = sub_BE3D40(
                              v1,
                              (CCmdString)&ppv3,
                              (int)&v35,
                              (int)&hKey,
                              (int)&v56,
                              (int)&v52,
                              (CCmdString)&v47,
                              (int)&a8);
                      free(v35);
                      if ( v16 )
                      {
                        v17 = ppv1;
                        if ( ppv1 == (void *)-1 )
                        {
                          v42 = _wcsdup((const wchar_t *)&gszNullString);
                          v44 = _wcsdup((const wchar_t *)&gszNullString);
                          v39 = _wcsdup((const wchar_t *)&gszNullString);
                          v37 = _wcsdup((const wchar_t *)&gszNullString);
                          v41 = _wcsdup((const wchar_t *)&gszNullString);
                          strValue.m_String = _wcsdup((const wchar_t *)&gszNullString);
                          v18 = (const wchar_t *)&gszNullString;
                          if ( gpszTaskScheduler )
                            v18 = gpszTaskScheduler;
                          str2.m_String = _wcsdup(v18);
                          v19 = (const wchar_t *)&gszNullString;
                          if ( gpszTaskScheduler )
                            v19 = gpszTaskScheduler;
                          str1.m_String = _wcsdup(v19);
                          LOBYTE(v62) = 24;
                          v17 = (void *)PE_UpdateSystemKey(v49, 2u, v17, 0, &str1, &str2, &strValue);
                          ppv1 = v17;
                          free(str1.m_String);
                          free(str2.m_String);
                          free(strValue.m_String);
                          free(v41);
                          free(v37);
                          free(v39);
                          free(v44);
                          free(v42);
                        }
                        v40 = _wcsdup((const wchar_t *)&gszNullString);
                        LOBYTE(v62) = 25;
                        v20 = v17;
                        v1 = v49;
                        PE_UpdateSystemKey(v49, a2, v20, 9u, (CCmdString *)&ppv3, (CCmdString *)&hKey, &v56);
                        free(v40);
                      }
                      else
                      {
                        v1 = v49;
                      }
                      CoTaskMemFree(szApplicationName);
                      CoTaskMemFree((LPVOID)pszParameters);
                      CoTaskMemFree(pszWorkingDirectory);
                      free(v56.m_String);
                      StringItem::~StringItem((tagPEStringStruct *)pszText2);
                      free(str3.m_String);
                      free(ppv3);
                      LOBYTE(v62) = 2;
                      free(hKey);
                    }
                  }
                }
                CoTaskMemFree(*((LPVOID *)pszNames + dwNameIndex++));
              }
              while ( dwNameIndex < (unsigned int)cbRet );
            }
            CoTaskMemFree(pszNames);
          }
          pEnumWorkItems->lpVtbl->Release(pEnumWorkItems);
          ppv->lpVtbl->Release(ppv);
        }
      }
      free(v47.m_String);
      free(v50);
      free(v52);
    }
    else
    {
      sub_C00EA0(a1);
    }
  }
}
// CA2AD0: using guessed type GUID CLSID_ITask;

//----- (00C00EA0) --------------------------------------------------------
void __cdecl sub_C00EA0(int a1)
{
  const wchar_t *v1; // esi
  const wchar_t *v2; // eax
  __m128i v3; // xmm0
  __m128i v4; // xmm0
  ITaskService *v5; // ecx
  ITaskServiceVtbl *v6; // edx
  int v7; // edi
  OLECHAR **v8; // eax
  OLECHAR *v9; // edx
  HRESULT v10; // eax
  HRESULT v11; // esi
  OLECHAR *v12; // ecx
  ITaskFolderVtbl *v13; // ecx
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
  ITaskService *v27; // [esp-Ch] [ebp-BCh]
  OLECHAR *v28; // [esp-8h] [ebp-B8h]
  ITaskFolder *v29; // [esp-4h] [ebp-B4h]
  __int128 v30; // [esp+Ch] [ebp-A4h]
  __int128 v31; // [esp+1Ch] [ebp-94h]
  __int128 v32; // [esp+2Ch] [ebp-84h]
  VARIANTARG v33; // [esp+3Ch] [ebp-74h]
  VARIANTARG v34; // [esp+4Ch] [ebp-64h]
  VARIANTARG pvarg; // [esp+5Ch] [ebp-54h]
  VARIANTARG v36; // [esp+6Ch] [ebp-44h]
  CCmdString str2; // [esp+7Ch] [ebp-34h]
  CCmdString str3; // [esp+80h] [ebp-30h]
  void *v39; // [esp+84h] [ebp-2Ch]
  void *v40; // [esp+88h] [ebp-28h]
  void *v41; // [esp+8Ch] [ebp-24h]
  void *ppv1; // [esp+90h] [ebp-20h]
  void *v43; // [esp+94h] [ebp-1Ch]
  ITaskService *pITaskService; // [esp+98h] [ebp-18h]
  _bstr_t v45; // [esp+9Ch] [ebp-14h]
  ITaskFolder *pTaskFolder; // [esp+A0h] [ebp-10h]
  int v47; // [esp+ACh] [ebp-4h]

  ppv1 = (void *)-1;
  v45.m_Data = (Data_t_bstr_t *)_wcsdup((const wchar_t *)&gszNullString);
  v47 = 0;
  v43 = _wcsdup((const wchar_t *)&gszNullString);
  v40 = _wcsdup((const wchar_t *)&gszNullString);
  v41 = _wcsdup((const wchar_t *)&gszNullString);
  v39 = _wcsdup((const wchar_t *)&gszNullString);
  str3.m_String = _wcsdup((const wchar_t *)&gszNullString);
  v1 = (const wchar_t *)&gszNullString;
  v2 = (const wchar_t *)&gszNullString;
  if ( gpszTaskScheduler_0 )
    v2 = gpszTaskScheduler_0;
  str2.m_String = _wcsdup(v2);
  if ( gpszTaskScheduler_0 )
    v1 = gpszTaskScheduler_0;
  pTaskFolder = (ITaskFolder *)_wcsdup(v1);
  v21 = -1;
  v20 = 0;
  v19 = 0;
  LOBYTE(v47) = 7;
  v18 = &v45;
  v17 = 1;
  v16 = 0;
  v15 = &v43;
  v14 = &v40;
  ppv1 = (void *)PE_UpdateSystemKey(a1, 2u, ppv1, 0, (CCmdString *)&pTaskFolder, &str2, &str3);
  free(pTaskFolder);
  free(str2.m_String);
  free(str3.m_String);
  free(v39);
  free(v41);
  free(v40);
  free(v43);
  v47 = -1;
  free(v45.m_Data);
  CoInitializeEx(0, 0);
  pITaskService = 0;
  if ( CoCreateInstance(&CLSID_ITaskService_1, 0, 1u, &CLSID_ITaskService_0, (LPVOID *)&pITaskService) >= 0 )
  {
    VariantInit(&pvarg);
    v3 = _mm_loadu_si128((const __m128i *)&pvarg);
    v47 = 8;
    _mm_storeu_si128((__m128i *)&v32, v3);
    VariantInit(&v34);
    _mm_storeu_si128((__m128i *)&v31, _mm_loadu_si128((const __m128i *)&v34));
    VariantInit(&v33);
    _mm_storeu_si128((__m128i *)&v30, _mm_loadu_si128((const __m128i *)&v33));
    VariantInit(&v36);
    v4 = _mm_loadu_si128((const __m128i *)&v32);
    v5 = pITaskService;
    LOBYTE(v47) = 11;
    v6 = pITaskService->lpVtbl;
    _mm_storeu_si128((__m128i *)&v26, v4);
    _mm_storeu_si128((__m128i *)&v22, _mm_loadu_si128((const __m128i *)&v31));
    _mm_storeu_si128((__m128i *)&v18, _mm_loadu_si128((const __m128i *)&v30));
    _mm_storeu_si128((__m128i *)&v14, _mm_loadu_si128((const __m128i *)&v36));
    v7 = ((int (__stdcall *)(ITaskService *, void **, void **, int, signed int, _bstr_t *, int, int, signed int, int, int, int, int, int, ITaskService *, OLECHAR *, ITaskFolder *))v6->Connect)(
           v5,
           v14,
           v15,
           v16,
           v17,
           v18,
           v19,
           v20,
           v21,
           v22,
           v23,
           v24,
           v25,
           v26,
           v27,
           v28,
           v29);
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
        TlsSetValue(gdwTlsIndex, (LPVOID)0x100);
      }
      pTaskFolder = 0;
      v8 = *_bstr_t::_bstr_t((tagEventSetItem *)&v45, L"\\");
      v47 = 12;
      if ( v8 )
        v9 = *v8;
      else
        v9 = 0;
      v29 = (ITaskFolder *)&pTaskFolder;
      v28 = v9;
      v27 = pITaskService;
      v10 = pITaskService->lpVtbl->GetFolder(pITaskService, v9, &pTaskFolder);
      v47 = -1;
      v11 = v10;
      _bstr_t::_Free(&v45);
      if ( v11 >= 0 )
      {
        v29 = pTaskFolder;
        v28 = v12;
        _bstr_t::_bstr_t((tagEventSetItem *)&v28, (OLECHAR *)&gszNullString);
        sub_BFF260(a1, (int)&ppv1, gpszTaskScheduler_0, v28, v29);
        v13 = pTaskFolder->lpVtbl;
        v29 = pTaskFolder;
        v13->Release(pTaskFolder);
      }
      if ( Wow64EnableWow64FsRedirection )
      {
        Wow64EnableWow64FsRedirection(1u);
        TlsSetValue(gdwTlsIndex, (LPVOID)0x200);
      }
    }
    v29 = (ITaskFolder *)pITaskService;
    pITaskService->lpVtbl->Release(pITaskService);
  }
  CoUninitialize();
}

//----- (00C011B0) --------------------------------------------------------
wchar_t *__cdecl sub_C011B0(wchar_t *a1, int a2, wchar_t *a3)
{
  wchar_t **v3; // edi
  wchar_t *v4; // eax
  wchar_t *v5; // eax
  wchar_t *v6; // esi
  wchar_t *v7; // esi
  wchar_t *v8; // esi

  v3 = (wchar_t **)operator new(0x10u);
  if ( v3 )
  {
    v4 = (wchar_t *)malloc(2u);
    *v3 = v4;
    *v4 = 0;
    v5 = (wchar_t *)malloc(2u);
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
    v3[1] = (wchar_t *)1;
  else
    v3[1] = 0;
  v8 = v3[1];
  v3[3] = (wchar_t *)dword_CD4C78;
  dword_CD4C78 = (int)v3;
  free(a1);
  free(a3);
  return v8;
}
// CD4C78: using guessed type int dword_CD4C78;

//----- (00C01290) --------------------------------------------------------
int __cdecl sub_C01290(wchar_t *a1, int a2)
{
  int v2; // esi
  int result; // eax
  void *v4; // ebx
  int v5; // esi

  v2 = dword_CD4C78;
  if ( dword_CD4C78 )
  {
    while ( _wcsicmp(a1, *(const wchar_t **)v2) )
    {
      v2 = *(_DWORD *)(v2 + 12);
      if ( !v2 )
        goto LABEL_4;
    }
    v4 = *(void **)a2;
    *(_DWORD *)a2 = _wcsdup(*(const wchar_t **)(v2 + 8));
    free(v4);
    LeaveCriticalSection(&CriticalSection);
    v5 = *(_DWORD *)(v2 + 4);
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
// CD4C78: using guessed type int dword_CD4C78;

//----- (00C01310) --------------------------------------------------------
CSystemProcessInfoMapNode *__thiscall sub_C01310(CSystemProcessInfoMap *this, int *a2)
{
  CSystemProcessInfoMapNode *result; // eax
  CSystemProcessInfoMapNode *v3; // esi
  CSystemProcessInfoMapPair *v4; // edi
  int v5; // eax

  result = std::_Tree_comp_alloc<std::_Tmap_traits<unsigned long,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *>>,0>>::_Buynode0(this);
  v3 = result;
  v4 = &result->_Keyvalue;
  *(_WORD *)&result->baseclass._Color = 0;
  if ( result != (CSystemProcessInfoMapNode *)-16 )
  {
    v5 = *a2;
    v4->_Key = *a2;
    if ( v5 )
      InterlockedIncrement((volatile LONG *)(v5 + 8));
    v4->_Value = (SYSTEM_PROCESS_INFORMATION *)a2[1];
    result = v3;
  }
  return result;
}

//----- (00C01350) --------------------------------------------------------
_DWORD *__thiscall sub_C01350(_DWORD *this)
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

//----- (00C01450) --------------------------------------------------------
std__tree *__thiscall std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned long const,MAPITEM *>>>,std::_Iterator_base0>::operator--(std__tree *this)
{
  std__tree *This; // edx
  std__Tree_node *_Myhead; // eax
  std__Tree_node *i; // ecx
  std__Tree_node *v5; // eax
  std__Tree_node *v6; // ecx

  This = this;
  _Myhead = this->_Mypair._Myval2._Myhead;
  if ( this->_Mypair._Myval2._Myhead->_IsNil )
  {
    this->_Mypair._Myval2._Myhead = (std__Tree_node *)_Myhead->_Right;
    return this;
  }
  i = (std__Tree_node *)_Myhead->_Left;
  if ( _Myhead->_Left->_IsNil )
  {
    for ( i = (std__Tree_node *)_Myhead->_Parent; !i->_IsNil; i = (std__Tree_node *)i->_Parent )
    {
      if ( This->_Mypair._Myval2._Myhead != (std__Tree_node *)i->_Left )
        break;
      This->_Mypair._Myval2._Myhead = i;
    }
    if ( This->_Mypair._Myval2._Myhead->_IsNil )
      return This;
    goto LABEL_11;
  }
  v5 = (std__Tree_node *)i->_Right;
  if ( v5->_IsNil )
  {
LABEL_11:
    This->_Mypair._Myval2._Myhead = i;
    return This;
  }
  do
  {
    v6 = v5;
    v5 = (std__Tree_node *)v5->_Right;
  }
  while ( !v5->_IsNil );
  This->_Mypair._Myval2._Myhead = v6;
  return This;
}

//----- (00C014B0) --------------------------------------------------------
// operator==(const _bstr_t::Data_t& r,const _bstr_t::Data_t& l)const
bool __stdcall sub_C014B0(Data_t_bstr_t *a1, Data_t_bstr_t *a2)
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
        operator delete[](a1->m_str);
        a1->m_str = 0;
      }
      operator delete(a1);
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
      operator delete[](a2->m_str);
      a2->m_str = 0;
    }
    operator delete(a2);
  }
  return v6;
}

//----- (00C01590) --------------------------------------------------------
void __cdecl sub_C01590(char a1, int a2, OLECHAR *a3, OLECHAR *a4, OLECHAR *psz, int a6)
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
  int a2a; // [esp+20h] [ebp-14h]
  char v16; // [esp+27h] [ebp-Dh]
  int v17; // [esp+30h] [ebp-4h]

  if ( !byte_CD4CCC )
    return;
  EnterCriticalSection(&stru_CD4C98);
  v6 = 0;
  a2a = 0;
  _bstr_t::_bstr_t((tagEventSetItem *)&v14, psz);
  v7 = (_DWORD *)*sub_C72F90((int *)&gMap5, (int *)&v12, (volatile LONG **)&v14);
  _bstr_t::_Free(&v14);
  v16 = 1;
  if ( a6 == 1 || v7 == gMap5 || (v6 = (_DWORD *)v7[5], a2a = (int)v6, v8 = v6[1], v8 == 6) || v8 == 5 )
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
          v6 = sub_C01350(v10);
        else
          v6 = 0;
        a2a = (int)v6;
        if ( a1 )
          *v6 = CreateEventW(0, 1, 0, 0);
        else
          *v6 = 0;
        _bstr_t::operator=((EventItem *)(v6 + 5), psz);
        _bstr_t::operator=((EventItem *)(v6 + 2), a3);
        _bstr_t::operator=((EventItem *)(v6 + 3), a4);
        _bstr_t::_bstr_t((tagEventSetItem *)&v11, psz);
        v12 = v6;
        v17 = 0;
        sub_C71650((CSystemProcessInfoMap *)&gMap5, (int)&v13, 0, (int *)&v11, (unsigned __int8)byte_CD4CCD);
        v17 = -1;
        _bstr_t::_Free(&v11);
      }
      v9 = (_DWORD *)a2;
      *(_DWORD *)a2 = v6;
      v6[1] = 3 - (a6 != 1);
      if ( a6 == 1 )
      {
        std::list<tagEventItem *,std::allocator<tagEventItem *>>::push_back(&gList1, (int)&a2a);
        SetEvent(hEvent);
      }
      else
      {
        sub_C017F0((int **)&gList2, (int)&a2a);
        SetEvent(dword_CD4CB8);
      }
      goto LABEL_8;
    }
  }
  else
  {
    v16 = 0;
  }
  v9 = (_DWORD *)a2;
LABEL_8:
  LeaveCriticalSection(&stru_CD4C98);
  if ( v16 )
  {
    if ( a1 )
    {
      WaitForSingleObject((HANDLE)*v6, 0xFFFFFFFF);
      CloseHandle((HANDLE)*v6);
    }
  }
  *v9 = v6;
}
// CD4CCC: using guessed type char byte_CD4CCC;
// CD4CCD: using guessed type char byte_CD4CCD;
