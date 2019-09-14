
//----- (01004530) --------------------------------------------------------
BSTR **__thiscall sub_1004530(void *this, int a2, OLECHAR psz, int a4)
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
  sub_1006500(*(*a4 + 4));
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
    sub_1004810(&v24, &psz, 58);
    v26 = 1;
    sub_1004810(&v25, &psz, 44);
    a2a = v24;
    if ( v24 )
      InterlockedIncrement(v24 + 2);
    v21 = v25;
    if ( v25 )
      InterlockedIncrement(v25 + 2);
    LOBYTE(v26) = 3;
    v15 = sub_10011F0(v4, &a2a);
    sub_1001240(v4, &v19, 0, &v15->_Keyvalue, v15);
    sub_1001430(&a2a);
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

//----- (01004810) --------------------------------------------------------
int __stdcall sub_1004810(int a1, OLECHAR *psz, __int16 a3)
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

//----- (01004950) --------------------------------------------------------
_bstr_t *__stdcall sub_1004950(int a1, int a2, void *a3)
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
  v6 = *sub_1062F90(a2, &v10, &a1) != v5;
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
    v7 = *(*sub_1062F90(a2, &v10, &a1) + 20);
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

//----- (01004AA0) --------------------------------------------------------
DWORD __stdcall sub_1004AA0(HINTERNET hRequest, int a2)
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
  v3 = sub_1004CA0(hRequest, L"StatusCode", 0x13u, &v16);
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
    v9 = sub_1004D50(v13);
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
// 10945DC: using guessed type wchar_t a200[4];
// 10945EC: using guessed type wchar_t a204[4];
// 10945F4: using guessed type wchar_t aStatuscode[11];

//----- (01004CA0) --------------------------------------------------------
int __stdcall sub_1004CA0(HINTERNET hRequest, int a2, DWORD dwInfoLevel, int a4)
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

//----- (01004D50) --------------------------------------------------------
int __stdcall sub_1004D50(void *a1)
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
// 10945DC: using guessed type wchar_t a200[4];
// 10945E4: using guessed type wchar_t a403[4];
// 10945EC: using guessed type wchar_t a204[4];

//----- (01004E80) --------------------------------------------------------
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

//----- (01004F00) --------------------------------------------------------
DWORD __thiscall sub_1004F00(HINTERNET *this, void *a2, void *a3, void *a4, int a5)
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
    v8[1] = sub_1064270(*v8);
  v11 = v8[1];
  v12 = dwTotalLength;
LABEL_22:
  if ( a3 )
    v13 = *a3;
  else
    v13 = 0;
  if ( WinHttpSendRequest(v7, v13, 0, v11, v10, v12, 0) && WinHttpReceiveResponse(v7, 0) )
    v14 = sub_1004AA0(v7, a5);
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

//----- (01005160) --------------------------------------------------------
std__list_node *__thiscall sub_1005160(tagHttpInfo *this, char a2)
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

//----- (010051B0) --------------------------------------------------------
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
// 100538B: CONTAINING_RECORD: no field 'PUCHAR' in struct 'tagConfigItem' at 24

//----- (010053E0) --------------------------------------------------------
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
        sub_10013E0(ValueName, L"%d", Index);
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

//----- (01005480) --------------------------------------------------------
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

//----- (010054E0) --------------------------------------------------------
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
        sub_10013E0(&ValueName, L"%d", v5);
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

//----- (010055A0) --------------------------------------------------------
DWORD __thiscall sub_10055A0(HINTERNET *this, int a2, OLECHAR psz)
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
  _bstr_t *v17; // eax
  _bstr_t *v18; // eax
  _bstr_t *v19; // eax
  _bstr_t *v20; // esi
  _bstr_t *v21; // eax
  _bstr_t *v22; // eax
  _bstr_t *v23; // eax
  _bstr_t *v24; // edi
  _bstr_t *v25; // esi
  _bstr_t *v26; // eax
  _bstr_t *v27; // eax
  _bstr_t *v28; // eax
  _bstr_t *v29; // edi
  UINT (__stdcall *v30)(BSTR); // eax
  _bstr_t *v31; // esi
  _bstr_t *v32; // eax
  _bstr_t *v33; // eax
  _bstr_t *v34; // eax
  _bstr_t *v35; // esi
  _bstr_t *v36; // eax
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
  _bstr_t *v47; // eax
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
  _bstr_t *v62; // eax
  _bstr_t *v63; // eax
  _bstr_t *v64; // eax
  _bstr_t *v65; // eax
  _bstr_t *v66; // eax
  void *v67; // esi
  void *v68; // ST0C_4
  _bstr_t *v69; // edi
  _bstr_t *v70; // esi
  _bstr_t *v71; // eax
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
  v6 = sub_1004420(v101, &lpBuffer, v102);
  v7 = v6;
  if ( v6 )
  {
    sub_1004320(&v124, v6);
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
    v14 = _bstr_t::operator+(v13, &a2a, v11);
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
    v19 = _bstr_t::operator+(v18, &a1, v15);
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
    v23 = _bstr_t::operator+(v22, &v112, v20);
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
    v25 = sub_10018A0(&hRequest, (a2 + 16));
    LOBYTE(v126) = 18;
    v26 = _bstr_t::_bstr_t(&a2a, L"\r\n");
    LOBYTE(v126) = 19;
    v27 = _bstr_t::operator+(v26, &a1, v25);
    LOBYTE(v126) = 20;
    v28 = _bstr_t::operator+(v27, &v112, v24);
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
        v34 = _bstr_t::operator+(v33, &v112, v31);
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
        v38 = _bstr_t::operator+(v37, &v112, v35);
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
          v45 = _bstr_t::operator+(v44, &v112, v42);
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
          v49 = _bstr_t::operator+(v48, &v112, v46);
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
    v53 = _bstr_t::operator+(v52, &v112, v50);
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
    v56 = _bstr_t::operator+(v55, &a1, &a2a);
    LOBYTE(v126) = 47;
    v57 = _bstr_t::operator+(v56, &v112, v54);
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
    v64 = _bstr_t::operator+(v63, &a1, v61);
    LOBYTE(v126) = 58;
    v65 = _bstr_t::operator+(v64, &v112, &dwNumberOfBytesToWrite);
    LOBYTE(v126) = 59;
    v66 = _bstr_t::operator+(v65, &v111, v60);
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
    _bstr_t::operator+(v72, &v114, v69);
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
          v73->m_str = sub_1064270(v73->m_wstr);
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
          v74->m_str = sub_1064270(v74->m_wstr);
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
        dwMessageId = sub_1004AA0(v83, psz);
        WinHttpCloseHandle(v83);
        v7 = dwMessageId;
        if ( dwMessageId )
        {
          sub_1004320(&v118, dwMessageId);
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
          sub_1004530(v3, &lpBuffer, &psz, &v105);
          LOBYTE(v126) = 70;
          if ( lpBuffer && *lpBuffer && SysStringLen(*lpBuffer) )
          {
            v102 = v90;
            _bstr_t::_bstr_t(&v102, L"permalink");
            v91 = sub_1004950(&psz, &v105, v102);
            v92 = a2;
            sub_FD3A50((a2 + 28), v91);
            _bstr_t::_Free(&psz);
            if ( sub_FE0440((v92 + 28)) )
            {
              _bstr_t::operator=((v92 + 32), L"Submitted");
            }
            else
            {
              v102 = v93;
              _bstr_t::_bstr_t(&v102, L"verbose_msg");
              v94 = sub_1004950(&v107, &v105, v102);
              LOBYTE(v126) = 71;
              v95 = _bstr_t::operator+(&psz, L"Submission error: ", v94);
              sub_FD3A50((v92 + 24), v95);
              _bstr_t::_Free(&psz);
              LOBYTE(v126) = 70;
              _bstr_t::_Free(&v107);
            }
            v102 = v96;
            _bstr_t::_bstr_t(&v102, L"scan_id");
            v97 = sub_1004950(&psz, &v105, v102);
            sub_FD3A50((v92 + 8), v97);
            _bstr_t::_Free(&psz);
            sub_FF9380(v3 + 4, &a2);
            v7 = dwMessageId;
          }
          v80 = &lpBuffer;
        }
      }
      else
      {
        v86 = GetLastError();
        sub_1004320(&v119, v86);
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
      sub_1004320(&v122, 0);
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
  sub_1006540(&v105, &a2, *v105, v105);
  j__free(v105);
  return v7;
}

//----- (01006210) --------------------------------------------------------
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
// 100634D: CONTAINING_RECORD: no field 'PUCHAR' in struct 'tagConfigItem' at 24

//----- (01006390) --------------------------------------------------------
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
        sub_10013E0(&ValueName, L"%d", v6);
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

//----- (01006430) --------------------------------------------------------
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
        sub_10013E0(&ValueName, L"%d", v5);
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

//----- (01006500) --------------------------------------------------------
void __stdcall sub_1006500(void *a1)
{
  std__List *v1; // edi
  std__List *v2; // esi

  v1 = a1;
  v2 = a1;
  if ( !*(a1 + 13) )
  {
    do
    {
      sub_1006500(v2[1]._Mypair._Myval2._Myhead);
      v2 = v2->_Mypair._Myval2._Myhead;
      sub_1001430(v1 + 2);
      j__free(v1);
      v1 = v2;
    }
    while ( !BYTE1(v2[1]._Mypair._Myval2._Mysize) );
  }
}

//----- (01006540) --------------------------------------------------------
CSystemProcessInfoMapNode **__thiscall sub_1006540(CSystemProcessInfoMap *this, CSystemProcessInfoMapNode **a2, CSystemProcessInfoMapNode *a3, CSystemProcessInfoMapNode *a4)
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
      sub_1006600(v5, &v13, v10);
    }
    *a2 = v4;
    result = a2;
  }
  else
  {
    sub_1006500(v6->baseclass._Parent);
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

//----- (01006600) --------------------------------------------------------
CSystemProcessInfoMapNode **__thiscall sub_1006600(CSystemProcessInfoMap *this, CSystemProcessInfoMapNode **a2, CSystemProcessInfoMapNode *a3)
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
  sub_1001430(&v4->_Keyvalue);
  j__free(v19);
  v16 = v3->_Mypair._Myval2._Mysize;
  v17 = a3;
  if ( v16 )
    v3->_Mypair._Myval2._Mysize = v16 - 1;
  result = a2;
  *a2 = v17;
  return result;
}

//----- (01006870) --------------------------------------------------------
unsigned int __cdecl sub_1006870(int a1, const unsigned __int16 *a2)
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

//----- (010068C0) --------------------------------------------------------
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
    v6 = sub_1006A40();
    v10 = 0;
    v12 = v6;
    lParam = &v12;
    v11 = sub_1007910;
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
        sub_1006D40(v5);
        break;
      default:
        return 0;
    }
  }
  return 1;
}

//----- (01006A40) --------------------------------------------------------
_BYTE *sub_1006A40()
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

  v0 = off_10BC4C8[0];
  v1 = 0;
  v2 = 1;
  if ( off_10BC4C8[0] )
  {
    v3 = off_10BC4C8[0];
    do
    {
      ++v1;
      v2 += strlen(v3);
      v3 = off_10BC4C8[v1];
    }
    while ( v3 );
  }
  v4 = malloc(v2);
  v5 = 0;
  v10 = 0;
  for ( i = v4; v0; v0 = off_10BC4C8[v10] )
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
// 10BC4C8: using guessed type char *off_10BC4C8[48];

//----- (01006AE0) --------------------------------------------------------
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

//----- (01006B60) --------------------------------------------------------
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

//----- (01006C00) --------------------------------------------------------
signed int sub_1006C00()
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

//----- (01006CC0) --------------------------------------------------------
signed int sub_1006CC0()
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

//----- (01006D40) --------------------------------------------------------
BOOL __cdecl sub_1006D40(HWND a1)
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
// 109ACE4: using guessed type wchar_t aSysinternalsLi[21];

//----- (01006F60) --------------------------------------------------------
BOOL __cdecl LicenseCheck(WCHAR *lpszText, int a2, int a3)
{
  int v3; // esi
  signed int ret; // ebx
  signed int Data; // [esp+8h] [ebp-4h]

  Data = 0;
  if ( !a2 || !a3 )
    return sub_1007390(lpszText, 0, 0);
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

//----- (01007020) --------------------------------------------------------
signed int sub_1007020()
{
  signed int v0; // esi
  char v1; // bh
  char v2; // bl

  v0 = 0;
  v1 = 0;
  wprintf(off_10BC58C);
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

//----- (01007080) --------------------------------------------------------
void __noreturn sub_1007080()
{
  wprintf_s(L"%ls", off_10BC58C);
  wprintf_s(L"This is the first run of this program. You must accept EULA to continue.\n");
  wprintf_s(L"Use -accepteula to accept EULA.\n\n");
  exit(1);
}

//----- (010070B0) --------------------------------------------------------
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
  if ( sub_1006C00() )
  {
    *&Data = sub_1007020();
  }
  else
  {
    if ( sub_1006CC0()
      || (hOutputHandle = GetStdHandle(STD_OUTPUT_HANDLE), GetFileType(hOutputHandle) == FILE_TYPE_PIPE) )
    {
      sub_1007080();
    }
    v3 = LocalAlloc(LMEM_ZEROINIT, 1000u);
    LoadLibraryW(L"Riched32.dll");
    *v3 = 0x80C808D0;
    *(v3 + 10) = 0;
    *(v3 + 14) = 0xB40138;
    *(v3 + 4) = 0;
    *(v3 + 18) = 0;
    v4 = &v3[2 * sub_1006870((v3 + 22), L"License Agreement") + 22];
    *v4 = 8;
    v5 = &v4[2 * sub_1006870((v4 + 2), L"MS Shell Dlg") + 5] & 0xFFFFFFFC;
    *(v5 + 8) = 0x30007;
    *(v5 + 12) = 0xE012A;
    *(v5 + 16) = 0xFFFF01F6;
    *v5 = 0x50000000;
    *(v5 + 20) = 130;
    v5 += 22;
    v6 = sub_1006870(v5, L"You can also use the /accepteula command-line switch to accept the EULA.");
    *(v5 + 2 * v6) = 0;
    ++*(v3 + 4);
    v7 = (v5 + 2 * v6 + 5) & 0xFFFFFFFC;
    *(v7 + 8) = 0x9F00C9;
    *(v7 + 12) = 0xE0032;
    *(v7 + 16) = 0xFFFF0001;
    *v7 = 0x50010000;
    *(v7 + 20) = 128;
    v7 += 22;
    v8 = sub_1006870(v7, L"&Agree");
    *(v7 + 2 * v8) = 0;
    ++*(v3 + 4);
    v9 = (v7 + 2 * v8 + 5) & 0xFFFFFFFC;
    *(v9 + 8) = 0x9F00FF;
    *(v9 + 12) = 0xE0032;
    *(v9 + 16) = 0xFFFF0002;
    *v9 = 0x50010000;
    *(v9 + 20) = 128;
    v9 += 22;
    v10 = sub_1006870(v9, L"&Decline");
    *(v9 + 2 * v10) = 0;
    ++*(v3 + 4);
    v11 = (v9 + 2 * v10 + 5) & 0xFFFFFFFC;
    *(v11 + 8) = 0x9F0007;
    *(v11 + 12) = 0xE0032;
    *(v11 + 16) = 0xFFFF01F5;
    *v11 = 0x50010000;
    *(v11 + 20) = 128;
    v11 += 22;
    v12 = sub_1006870(v11, L"&Print");
    *(v11 + 2 * v12) = 0;
    ++*(v3 + 4);
    v13 = (v11 + 2 * v12 + 5) & 0xFFFFFFFC;
    *(v13 + 8) = 0xE0007;
    *(v13 + 12) = 0x8C012A;
    *(v13 + 16) = 500;
    *v13 = 0x50A11844;
    v14 = v13 + 18 + 2 * sub_1006870(v13 + 18, L"RICHEDIT");
    *(v14 + 2 * sub_1006870(v14, L"&Decline")) = 0;
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
// 109AD8C: using guessed type wchar_t aLicenseAgreeme[18];
// 109ADB0: using guessed type wchar_t aMsShellDlg[13];
// 109ADD0: using guessed type wchar_t aYouCanAlsoUseT[73];
// 109AE64: using guessed type wchar_t aAgree[7];
// 109AE74: using guessed type wchar_t aDecline[9];
// 109AE88: using guessed type wchar_t aPrint[7];
// 109AE98: using guessed type wchar_t aRichedit[9];

//----- (01007390) --------------------------------------------------------
BOOL __cdecl sub_1007390(LPARAM a1, int *a2, int a3)
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
    v4 = &dword_10C4DB4;
    v7 = GetCommandLineW();
    v3 = (v6)(v7, &dword_10C4DB4);
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
  if ( sub_1006C00() )
  {
    v16 = sub_1007020();
    *v59 = v16;
  }
  else
  {
    if ( sub_1006CC0() || (v17 = GetStdHandle(0xFFFFFFF5), GetFileType(v17) == 3) )
      sub_1007080();
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
// 109AD8C: using guessed type wchar_t aLicenseAgreeme[18];
// 109ADB0: using guessed type wchar_t aMsShellDlg[13];
// 109ADD0: using guessed type wchar_t aYouCanAlsoUseT[73];
// 109AE64: using guessed type wchar_t aAgree[7];
// 109AE74: using guessed type wchar_t aDecline[9];
// 109AE88: using guessed type wchar_t aPrint[7];
// 109AE98: using guessed type wchar_t aRichedit[9];
// 10C4DB4: using guessed type int dword_10C4DB4;

//----- (01007910) --------------------------------------------------------
int __stdcall sub_1007910(int a1, void *a2, int a3, int a4)
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

//----- (01007950) --------------------------------------------------------
signed int CAboutWnd::HandleInitDialog()
{
  return 1;
}

//----- (01007960) --------------------------------------------------------
LRESULT __cdecl CAboutWnd::HandleCommand(HWND hWnd, int a2, WPARAM wParam, LPARAM lParam)
{
  return HandleCmdHandler(&CAboutDlg::gCmdHandler, hWnd, wParam, lParam);
}
// 10BC5BC: using guessed type struct tagMSGHANDLER CAboutDlg::gCmdHandler;

//----- (01007980) --------------------------------------------------------
int __cdecl Command_OkOrCancel(HWND hDlg)
{
  EndDialog(hDlg, 1);
  return 1;
}

//----- (010079A0) --------------------------------------------------------
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
        v7 = PE_QueryFileVersionBlock(pVersionInfo, L"FileVersion");
        SetDlgItemTextW(hDlg, IDD_ABOUT_STATIC_VERSION, v7);
        v8 = PE_QueryFileVersionBlock(pVersionInfo, L"LegalCopyright");
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
// 109B118: using guessed type wchar_t aHttpWwwSysinte[28];
// 10C4DBC: using guessed type int gbIndirectFontCreated;
// 10C4DC0: using guessed type int ghDefaultGuiFont;

//----- (01007DC0) --------------------------------------------------------
int __cdecl Command_About(HWND hWndParent)
{
  DialogBoxParamW(ghInstance, L"AboutBox", hWndParent, DlgAbout, 0);
  return 0;
}

//----- (01007DF0) --------------------------------------------------------
int *__cdecl sub_1007DF0(int *a1, const unsigned __int16 *a2)
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
        sub_1009D10(v13);
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
        sub_1008630(&v43, 1, off_10BAA40, "ios_base::badbit set");
        v43 = &std::ios_base::failure::`vftable';
        _CxxThrowException(&v43, &_TI5_AVfailure_ios_base_std__);
      }
      if ( v35 & 2 )
      {
        sub_1008630(&v42, 1, off_10BAA40, "ios_base::failbit set");
        v42 = &std::ios_base::failure::`vftable';
        _CxxThrowException(&v42, &_TI5_AVfailure_ios_base_std__);
      }
      sub_1008630(&v41, 1, off_10BAA40, "ios_base::eofbit set");
      v41 = &std::ios_base::failure::`vftable';
      _CxxThrowException(&v41, &_TI5_AVfailure_ios_base_std__);
    }
  }
  v49 = -1;
  v36 = __uncaught_exception();
  v37 = v44;
  if ( !v36 )
    sub_10092D0(v44);
  v38 = *(*(*v37 + 4) + v37 + 56);
  if ( v38 )
    (*(*v38 + 8))();
  return a1;
}
// 10681AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);
// 109BEB8: using guessed type void *std::ios_base::failure::`vftable';
// 10B4548: using guessed type int _TI5_AVfailure_ios_base_std__;
// 10BAA40: using guessed type int (__thiscall **off_10BAA40[2])(void *, char);

//----- (01008150) --------------------------------------------------------
struct std::_Facet_base *__cdecl sub_1008150(int *a1)
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
  v1 = dword_10E5868;
  v2 = dword_10C4DD0;
  v11 = 0;
  v10 = dword_10C4DD0;
  if ( !dword_10E5868 )
  {
    std::_Lockit::_Lockit(&v9, dword_10E5868);
    if ( dword_10E5868 == v1 )
      dword_10E5868 = ++dword_10E5840;
    std::_Lockit::~_Lockit(&v9);
    v1 = dword_10E5868;
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
  v5 = sub_1064C4A();
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
    if ( sub_1009090(&v10, a1) == -1 )
    {
      sub_1069D12(&v7, "bad cast");
      _CxxThrowException(&v7, &_TI2_AVbad_cast_std__);
    }
    v4 = v10;
    dword_10C4DD0 = v10;
    (*(*v10 + 4))(v10);
    std::_Facet_Register(v4);
  }
LABEL_19:
  std::_Lockit::~_Lockit(&v8);
  return v4;
}
// 10681AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);
// 10B45C4: using guessed type int _TI2_AVbad_cast_std__;
// 10C4DD0: using guessed type int dword_10C4DD0;
// 10E5840: using guessed type int dword_10E5840;

//----- (01008270) --------------------------------------------------------
_DWORD *__thiscall sub_1008270(_DWORD *this)
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
// 109BF1C: using guessed type void *std::basic_streambuf<unsigned short,std::char_traits<unsigned short>>::`vftable';

//----- (01008300) --------------------------------------------------------
char *__thiscall sub_1008300(char *this, int a2, int a3)
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
// 109BE5C: using guessed type void *std::ctype<unsigned short>::`vftable';

//----- (01008360) --------------------------------------------------------
struct std::_Locinfo *__thiscall sub_1008360(struct std::_Locinfo *this, char *a2)
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
// 10681AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);
// 109BE30: using guessed type void *std::runtime_error::`vftable';
// 10B44F4: using guessed type int _TI2_AVruntime_error_std__;

//----- (01008420) --------------------------------------------------------
std::exception *__thiscall sub_1008420(std::exception *this, int a2, int a3, int a4)
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
  sub_FF6F00(&v8, a4, 0, 0xFFFFFFFF);
  v5 = sub_10091F0(&v15, a2, a3, v8, v9, v10, v11, v12, v13);
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
// 109BE30: using guessed type void *std::runtime_error::`vftable';
// 109BE9C: using guessed type void *std::_System_error::`vftable';

//----- (010084F0) --------------------------------------------------------
std::exception *__thiscall sub_10084F0(std::exception *this, struct exception *a2)
{
  std::exception *v2; // edi

  v2 = this;
  std::exception::exception(this, a2);
  *v2 = &std::_System_error::`vftable';
  *(v2 + 3) = *(a2 + 3);
  *(v2 + 4) = *(a2 + 4);
  return v2;
}
// 109BE9C: using guessed type void *std::_System_error::`vftable';

//----- (01008520) --------------------------------------------------------
std::exception *__thiscall sub_1008520(std::exception *this, struct exception *a2)
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
// 109BE9C: using guessed type void *std::_System_error::`vftable';
// 109BEB8: using guessed type void *std::ios_base::failure::`vftable';

//----- (01008550) --------------------------------------------------------
std::exception *__thiscall sub_1008550(std::exception *this, struct exception *a2)
{
  std::exception *v2; // esi

  v2 = this;
  std::exception::exception(this, a2);
  *v2 = &std::runtime_error::`vftable';
  return v2;
}
// 109BE30: using guessed type void *std::runtime_error::`vftable';

//----- (01008570) --------------------------------------------------------
_DWORD *__thiscall sub_1008570(_DWORD *this, int a2)
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
        sub_1009D10(v5);
    }
  }
  *(v2 + 4) = *(*(*a2 + 4) + a2 + 12) == 0;
  return v2;
}

//----- (01008600) --------------------------------------------------------
std::exception *__thiscall sub_1008600(std::exception *this, struct exception *a2)
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
// 109BE9C: using guessed type void *std::_System_error::`vftable';
// 109BEAC: using guessed type void *std::system_error::`vftable';

//----- (01008630) --------------------------------------------------------
std::exception *__thiscall sub_1008630(std::exception *this, int a2, int a3, void *a4)
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
  sub_FF7030(&v7, a4, v5);
  v10 = 0;
  sub_1008420(v4, a2, a3, &v7);
  if ( v9 >= 0x10 )
    j__free(v7);
  result = v4;
  *v4 = &std::system_error::`vftable';
  return result;
}
// 109BEAC: using guessed type void *std::system_error::`vftable';

//----- (010087D0) --------------------------------------------------------
int __thiscall sub_10087D0(_DWORD *this)
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
  sub_1009420((this - 20));
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
// 109BF14: using guessed type void *std::basic_ostream<unsigned short,std::char_traits<unsigned short>>::`vftable';
// 109BF1C: using guessed type void *std::basic_streambuf<unsigned short,std::char_traits<unsigned short>>::`vftable';
// 109BF5C: using guessed type void *std::basic_istream<unsigned short,std::char_traits<unsigned short>>::`vftable';
// 109BF64: using guessed type void *std::basic_iostream<unsigned short,std::char_traits<unsigned short>>::`vftable';
// 109BF6C: using guessed type void *std::basic_stringbuf<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>>::`vftable';
// 109BFAC: using guessed type void *std::basic_stringstream<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>>::`vftable';

//----- (01008880) --------------------------------------------------------
int __thiscall sub_1008880(std::_Lockit *this)
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

//----- (01008990) --------------------------------------------------------
void __thiscall sub_1008990(_DWORD *this)
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
// 109BEC4: using guessed type void *std::ios_base::`vftable';
// 109BF14: using guessed type void *std::basic_ostream<unsigned short,std::char_traits<unsigned short>>::`vftable';
// 109BF5C: using guessed type void *std::basic_istream<unsigned short,std::char_traits<unsigned short>>::`vftable';
// 109BF64: using guessed type void *std::basic_iostream<unsigned short,std::char_traits<unsigned short>>::`vftable';

//----- (01008A1C) --------------------------------------------------------
void __fastcall sub_1008A1C(unsigned int a1, int a2, int a3)
{
  bool v3; // cf

  v3 = a1 < *(a1 - 4);
  JUMPOUT(&loc_1008A40);
}

//----- (01008A24) --------------------------------------------------------
void __fastcall sub_1008A24(unsigned int a1, int a2, int a3)
{
  bool v3; // cf

  v3 = a1 < *(a1 - 4);
  JUMPOUT(&loc_1008A70);
}

//----- (01008A2C) --------------------------------------------------------
char *__thiscall sub_1008A2C(_DWORD *this, char a2)
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
// 109BEC4: using guessed type void *std::ios_base::`vftable';
// 109BF14: using guessed type void *std::basic_ostream<unsigned short,std::char_traits<unsigned short>>::`vftable';

//----- (01008B10) --------------------------------------------------------
void *__thiscall sub_1008B10(void *this, char a2)
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
// 109BF1C: using guessed type void *std::basic_streambuf<unsigned short,std::char_traits<unsigned short>>::`vftable';

//----- (01008B60) --------------------------------------------------------
_DWORD *__thiscall sub_1008B60(void *this, char a2)
{
  _DWORD *v2; // esi
  void *v3; // edi
  void (__thiscall ***v4)(_DWORD, signed int); // eax

  v2 = this;
  *this = &std::basic_stringbuf<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>>::`vftable';
  sub_1009420(this);
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
// 109BF1C: using guessed type void *std::basic_streambuf<unsigned short,std::char_traits<unsigned short>>::`vftable';
// 109BF6C: using guessed type void *std::basic_stringbuf<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>>::`vftable';

//----- (01008BC0) --------------------------------------------------------
_DWORD *__thiscall sub_1008BC0(struct std::ios_base *this, char a2)
{
  char *v2; // edi
  struct std::ios_base *v3; // esi

  v2 = this - 104;
  v3 = this;
  sub_10087D0(this);
  *v3 = &std::ios_base::`vftable';
  std::ios_base::_Ios_base_dtor(v3);
  if ( a2 & 1 )
    j__free(v2);
  return v2;
}
// 109BEC4: using guessed type void *std::ios_base::`vftable';

//----- (01008C00) --------------------------------------------------------
void **__thiscall sub_1008C00(void *this, char a2)
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
// 109BE4C: using guessed type void *std::_Facet_base::`vftable';
// 109BE5C: using guessed type void *std::ctype<unsigned short>::`vftable';

//----- (01008C50) --------------------------------------------------------
void *__thiscall sub_1008C50(void *this, char a2)
{
  void *v2; // esi

  v2 = this;
  *this = &std::_Facet_base::`vftable';
  if ( a2 & 1 )
    j__free(this);
  return v2;
}
// 109BE4C: using guessed type void *std::_Facet_base::`vftable';

//----- (01008C80) --------------------------------------------------------
struct std::ios_base *__thiscall sub_1008C80(struct std::ios_base *this, char a2)
{
  struct std::ios_base *v2; // esi

  v2 = this;
  *this = &std::ios_base::`vftable';
  std::ios_base::_Ios_base_dtor(this);
  if ( a2 & 1 )
    j__free(v2);
  return v2;
}
// 109BEC4: using guessed type void *std::ios_base::`vftable';

//----- (01008CB0) --------------------------------------------------------
void *__thiscall sub_1008CB0(void *this, char a2)
{
  void *v2; // esi

  v2 = this;
  std::_system_error::~_system_error(this);
  if ( a2 & 1 )
    j__free(v2);
  return v2;
}

//----- (01008CE0) --------------------------------------------------------
void __cdecl sub_1008CE0(int a1, int a2, wchar_t *a3)
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
    v17 = &unk_109BFB0;
    v19 = dword_109BFB8;
    v30 = 0;
    v25 = 1;
    v24 = &std::basic_istream<unsigned short,std::char_traits<unsigned short>>::`vftable';
    v23 = 80;
    v18 = 0i64;
    sub_1009E70(&v24, &v20, 0);
    *(&v19 + dword_109BFB8[1]) = &std::basic_ostream<unsigned short,std::char_traits<unsigned short>>::`vftable';
    *(&v18 + v19[1] + 4) = v19[1] - 8;
    *(&v17 + v17[1]) = &std::basic_iostream<unsigned short,std::char_traits<unsigned short>>::`vftable';
    *(&v16 + v17[1]) = v17[1] - 32;
    v30 = 5;
    *(&v17 + v17[1]) = &std::basic_stringstream<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>>::`vftable';
    *(&v16 + v17[1]) = v17[1] - 104;
    sub_1008270(&v20);
    v20 = &std::basic_stringbuf<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>>::`vftable';
    v21 = 0;
    v22 = 0;
    v30 = 7;
    sub_1009000(&v17, a1, &dword_10BC5C8, 8);
    v26 = 1;
    v6 = 0;
    do
    {
      v7 = wcscmp(a2, (&off_10BCB90)[v6]);
      if ( v7 )
        v7 = -(v7 < 0) | 1;
      if ( v7 )
      {
        v8 = v26;
      }
      else
      {
        sub_1009000(&v17, a1, *(&off_10BCB88 + v6 * 4), dword_10BCB8C[v6]);
        v8 = 0;
        v26 = 0;
      }
      v6 += 3;
    }
    while ( v6 < 39 );
    if ( v8 )
    {
      if ( a1 )
        sub_1007DF0(&v19, L"<Unknown>");
      else
        sub_1007DF0(&v19, L"<None>");
      v9 = sub_100A6E0(&v17, &v27);
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
      sub_100A6E0(&v17, &v27);
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
    sub_10087D0(&v24);
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
// 109BEC4: using guessed type void *std::ios_base::`vftable';
// 109BF14: using guessed type void *std::basic_ostream<unsigned short,std::char_traits<unsigned short>>::`vftable';
// 109BF5C: using guessed type void *std::basic_istream<unsigned short,std::char_traits<unsigned short>>::`vftable';
// 109BF64: using guessed type void *std::basic_iostream<unsigned short,std::char_traits<unsigned short>>::`vftable';
// 109BF6C: using guessed type void *std::basic_stringbuf<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>>::`vftable';
// 109BFAC: using guessed type void *std::basic_stringstream<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>>::`vftable';
// 109BFD8: using guessed type wchar_t aUnknown_0[10];
// 10BC5C8: using guessed type int dword_10BC5C8;
// 10BCB88: using guessed type void *off_10BCB88;
// 10BCB8C: using guessed type int dword_10BCB8C[];
// 10BCB90: using guessed type wchar_t *off_10BCB90;

//----- (01009000) --------------------------------------------------------
int __cdecl sub_1009000(int a1, int a2, int a3, int a4)
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
        v7 = sub_1007DF0(v6, *(v5 + 4));
        sub_1007DF0(v7, L" | ");
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
// 109BFC0: using guessed type wchar_t asc_109BFC0[4];

//----- (01009070) --------------------------------------------------------
volatile signed __int32 *__thiscall sub_1009070(volatile signed __int32 *this)
{
  volatile signed __int32 *result; // eax

  result = 0;
  if ( !_InterlockedExchangeAdd(this + 1, 0xFFFFFFFF) )
    result = this;
  return result;
}

//----- (01009090) --------------------------------------------------------
signed int __cdecl sub_1009090(char **a1, int *a2)
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
      v6 = sub_1008360(&v9, v5);
      v2 = 1;
      v7 = sub_1008300(v3, v6, 0);
    }
    else
    {
      v7 = 0;
    }
    *a1 = v7;
    if ( v2 & 1 )
      sub_1008880(&v9);
  }
  return 2;
}

//----- (01009140) --------------------------------------------------------
__int64 __thiscall sub_1009140(_DWORD **this)
{
  __int64 result; // rax

  if ( *this[7] )
    result = *this[11];
  else
    result = 0i64;
  return result;
}

//----- (01009160) --------------------------------------------------------
signed __int32 __thiscall sub_1009160(volatile signed __int32 *this)
{
  return _InterlockedExchangeAdd(this + 1, 1u);
}

//----- (01009170) --------------------------------------------------------
struct std::locale::_Locimp *__thiscall sub_1009170(_DWORD *this)
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
  sub_1009860(this, 0);
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

//----- (010091F0) --------------------------------------------------------
void *__cdecl sub_10091F0(void *a1, char a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
  int v9; // eax
  int v10; // edx
  void *result; // eax
  void *v12; // [esp+Ch] [ebp-28h]
  unsigned int v13; // [esp+20h] [ebp-14h]
  int v14; // [esp+30h] [ebp-4h]

  v14 = 0;
  if ( a8 )
    sub_1009550(&a4, &unk_109BEA4, 2u);
  v9 = sub_1009F90(&a2, &v12);
  LOBYTE(v14) = 1;
  sub_1009490(&a4, v9, 0, -1);
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

//----- (010092D0) --------------------------------------------------------
int __thiscall sub_10092D0(_DWORD *this)
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
            sub_1008630(&v12, 1, off_10BAA40, "ios_base::badbit set");
            v12 = &std::ios_base::failure::`vftable';
            _CxxThrowException(&v12, &_TI5_AVfailure_ios_base_std__);
          }
          if ( v8 & 2 )
          {
            sub_1008630(&v11, 1, off_10BAA40, "ios_base::failbit set");
            v11 = &std::ios_base::failure::`vftable';
            _CxxThrowException(&v11, &_TI5_AVfailure_ios_base_std__);
          }
          sub_1008630(&v10, 1, off_10BAA40, "ios_base::eofbit set");
          v10 = &std::ios_base::failure::`vftable';
          _CxxThrowException(&v10, &_TI5_AVfailure_ios_base_std__);
        }
      }
    }
  }
  return result;
}
// 10681AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);
// 109BEB8: using guessed type void *std::ios_base::failure::`vftable';
// 10B4548: using guessed type int _TI5_AVfailure_ios_base_std__;
// 10BAA40: using guessed type int (__thiscall **off_10BAA40[2])(void *, char);

//----- (01009400) --------------------------------------------------------
__int64 __thiscall sub_1009400(_DWORD **this)
{
  __int64 result; // rax

  if ( *this[8] )
    result = *this[12];
  else
    result = 0i64;
  return result;
}

//----- (01009420) --------------------------------------------------------
_DWORD *__thiscall sub_1009420(int this)
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

//----- (01009490) --------------------------------------------------------
_DWORD *__thiscall sub_1009490(void *this, int a2, int a3, int a4)
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
  if ( v7 && sub_FF6E00(v5, v9 + v7, 0) )
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

//----- (01009550) --------------------------------------------------------
_DWORD *__thiscall sub_1009550(void *this, void *a2, size_t a3)
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
      result = sub_1009490(v4, v4, a2 - v4, a3);
    else
      result = sub_1009490(v4, v4, a2 - *v4, a3);
  }
  else
  {
    v9 = v4[4];
    v13 = v9;
    if ( -1 - v9 <= a3 )
      std::_Xlength_error("string too long");
    if ( a3 && sub_FF6E00(v4, &v9[a3], 0) )
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

//----- (01009640) --------------------------------------------------------
int *__thiscall sub_1009640(int *this, int *a2, unsigned int a3, unsigned int a4)
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
      sub_FDF9D0(v5, v8, v5[4]);
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
  sub_1009C60(v5, 0, a3);
  return v5;
}

//----- (01009760) --------------------------------------------------------
int *__thiscall sub_1009760(int *this, void *a2, int a3)
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
      sub_FDF9D0(v3, a3, v3[4]);
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
  return sub_1009640(v3, v3, (a2 - v7) >> 1, a3);
}

//----- (01009860) --------------------------------------------------------
int __thiscall sub_1009860(_DWORD *this, char a2)
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
        sub_1008630(&v4, 1, off_10BAA40, "ios_base::failbit set");
      else
        sub_1008630(&v4, 1, off_10BAA40, "ios_base::eofbit set");
      v4 = &std::ios_base::failure::`vftable';
      _CxxThrowException(&v4, &_TI5_AVfailure_ios_base_std__);
    }
    sub_1008630(&v4, 1, off_10BAA40, "ios_base::badbit set");
    v4 = &std::ios_base::failure::`vftable';
    _CxxThrowException(&v4, &_TI5_AVfailure_ios_base_std__);
  }
  return result;
}
// 10681AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);
// 109BEB8: using guessed type void *std::ios_base::failure::`vftable';
// 10B4548: using guessed type int _TI5_AVfailure_ios_base_std__;
// 10BAA40: using guessed type int (__thiscall **off_10BAA40[2])(void *, char);

//----- (01009900) --------------------------------------------------------
BOOL __stdcall sub_1009900(__int16 a1, WCHAR SrcStr)
{
  return (_Getwctype(SrcStr) & a1) != 0;
}

//----- (01009930) --------------------------------------------------------
char __thiscall sub_1009930(const _Cvtvec *this, wchar_t a2, int a3)
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

//----- (01009980) --------------------------------------------------------
wchar_t *__thiscall sub_1009980(const _Cvtvec *this, wchar_t *a2, unsigned int a3, char a4, int a5)
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

//----- (01009A20) --------------------------------------------------------
unsigned __int16 *__thiscall sub_1009A20(void *this, int a2, unsigned __int16 *a3, unsigned __int16 *a4)
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

//----- (01009A60) --------------------------------------------------------
unsigned __int16 *__thiscall sub_1009A60(void *this, int a2, unsigned __int16 *a3, unsigned __int16 *a4)
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

//----- (01009AA0) --------------------------------------------------------
int __thiscall sub_1009AA0(void *this, wchar_t Src)
{
  return _Towlower(Src, this + 8);
}

//----- (01009AC0) --------------------------------------------------------
wchar_t *__thiscall sub_1009AC0(char *this, wchar_t *a2, unsigned int a3)
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

//----- (01009B10) --------------------------------------------------------
int __thiscall sub_1009B10(void *this, wchar_t Src)
{
  return _Towupper(Src, this + 8);
}

//----- (01009B30) --------------------------------------------------------
wchar_t *__thiscall sub_1009B30(char *this, wchar_t *a2, unsigned int a3)
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

//----- (01009B80) --------------------------------------------------------
wchar_t __thiscall sub_1009B80(const _Cvtvec *this, char a2)
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

//----- (01009BD0) --------------------------------------------------------
char *__thiscall sub_1009BD0(const _Cvtvec *this, wchar_t a2, char a3, mbstate_t a4)
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

//----- (01009C60) --------------------------------------------------------
_DWORD *__thiscall sub_1009C60(_DWORD *this, unsigned int a2, unsigned int a3)
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

//----- (01009D10) --------------------------------------------------------
char *__thiscall sub_1009D10(char *this)
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
    sub_1008570(&v11, this);
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
          sub_1008630(&v10, 1, off_10BAA40, "ios_base::badbit set");
          v10 = &std::ios_base::failure::`vftable';
          _CxxThrowException(&v10, &_TI5_AVfailure_ios_base_std__);
        }
        if ( v7 & 2 )
          sub_1008630(&v10, 1, off_10BAA40, "ios_base::failbit set");
        else
          sub_1008630(&v10, 1, off_10BAA40, "ios_base::eofbit set");
        v10 = &std::ios_base::failure::`vftable';
        _CxxThrowException(&v10, &_TI5_AVfailure_ios_base_std__);
      }
    }
    v13 = -1;
    if ( !__uncaught_exception() )
      sub_10092D0(v11);
    v8 = *(v11 + *(*v11 + 4) + 56);
    if ( v8 )
      (*(*v8 + 8))();
  }
  return v1;
}
// 10681AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);
// 109BEB8: using guessed type void *std::ios_base::failure::`vftable';
// 10B4548: using guessed type int _TI5_AVfailure_ios_base_std__;
// 10BAA40: using guessed type int (__thiscall **off_10BAA40[2])(void *, char);

//----- (01009E40) --------------------------------------------------------
int *__thiscall sub_1009E40(_DWORD *this, int *a2)
{
  int *v2; // eax
  int v3; // ecx

  v2 = this[12];
  v3 = *v2;
  *a2 = *v2;
  (*(*v3 + 4))();
  return a2;
}

//----- (01009E70) --------------------------------------------------------
void __thiscall sub_1009E70(struct std::ios_base *this, int a2, char a3)
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
  sub_1009170(this);
  *(v3 + 14) = a2;
  *(v3 + 15) = 0;
  v4 = sub_1009E40(v3, &a2);
  v14 = -1;
  v5 = sub_1008150(v4);
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
        sub_1008630(&v13, 1, off_10BAA40, "ios_base::badbit set");
      }
      else
      {
        if ( !(v11 & 2) )
        {
          sub_1008630(&v12, 1, off_10BAA40, "ios_base::eofbit set");
          v12 = &std::ios_base::failure::`vftable';
          _CxxThrowException(&v12, &_TI5_AVfailure_ios_base_std__);
        }
        sub_1008630(&v13, 1, off_10BAA40, "ios_base::failbit set");
      }
      v13 = &std::ios_base::failure::`vftable';
      _CxxThrowException(&v13, &_TI5_AVfailure_ios_base_std__);
    }
  }
  if ( a3 )
    std::ios_base::_Addstd(v3);
}
// 10681AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);
// 109BEB8: using guessed type void *std::ios_base::failure::`vftable';
// 10B4548: using guessed type int _TI5_AVfailure_ios_base_std__;
// 10BAA40: using guessed type int (__thiscall **off_10BAA40[2])(void *, char);

//----- (01009F90) --------------------------------------------------------
int __thiscall sub_1009F90(_DWORD **this, int a2)
{
  (*(*this[1] + 8))(a2, *this, 0);
  return a2;
}

//----- (01009FC0) --------------------------------------------------------
__int16 __thiscall sub_1009FC0(_DWORD *this, __int16 a2)
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
  v15 = sub_FDFFE0(v14 + v13);
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

//----- (0100A1E0) --------------------------------------------------------
signed int __stdcall sub_100A1E0(int a1)
{
  return 0xFFFF;
}

//----- (0100A1F0) --------------------------------------------------------
signed __int16 __thiscall sub_100A1F0(int this, __int16 a2)
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

//----- (0100A260) --------------------------------------------------------
_DWORD *__stdcall sub_100A260(_DWORD *a1, int a2, int a3, int a4, int a5)
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

//----- (0100A290) --------------------------------------------------------
signed int *__thiscall sub_100A290(int this, signed int *a2, __int64 a3, int a4, char a5)
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

//----- (0100A480) --------------------------------------------------------
_DWORD *__stdcall sub_100A480(_DWORD *a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
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