
//----- (01026B90) --------------------------------------------------------
bool __cdecl sub_1026B90(HWND hWnd, int a2, int a3)
{
  HWND v3; // esi
  HMODULE v5; // eax
  FARPROC v6; // eax
  HWND v7; // ecx

  v3 = QueryTopMostWindowByProcessID(a3);
  if ( !v3 )
  {
    v7 = ghMainWnd;
    if ( hWnd )
      v7 = hWnd;
    MessageBoxW(v7, L"No visible windows found for this process", L"Process Explorer Warning", 0x30u);
    return v3 != 0;
  }
  if ( a2 <= 40638 )
  {
    if ( a2 == 40638 )
    {
      ShowWindowAsync(v3, 6);
      return v3 != 0;
    }
    if ( a2 == 40084 )
    {
      if ( IsIconic(v3) )
        ShowWindowAsync(v3, 9);
      SetForegroundWindow(v3);
      return v3 != 0;
    }
    return v3 != 0;
  }
  if ( a2 == 40639 )
  {
    ShowWindowAsync(v3, 3);
    return v3 != 0;
  }
  if ( a2 != 40640 )
  {
    if ( a2 == 40641 )
    {
      ShowWindowAsync(v3, 9);
      return v3 != 0;
    }
    return v3 != 0;
  }
  v5 = GetModuleHandleW(L"user32.dll");
  v6 = GetProcAddress(v5, "EndTask");
  if ( v6 )
    (v6)(v3, 0, 0);
  else
    PostMessageW(v3, 0x10u, 0, 0);
  return v3 != 0;
}

//----- (01026C90) --------------------------------------------------------
LSTATUS SaveHiddenProcessesToRegistry()
{
  int v0; // ebx
  int nIndex; // esi
  LSTATUS result; // eax
  WCHAR **ppHiddenProcesses; // edi
  WCHAR **ppHiddenProcesses_1; // eax
  WCHAR *pHiddenProcesses; // eax
  WCHAR *v6; // edx
  WCHAR chText; // cx
  rsize_t nLength; // ebx
  wchar_t *v9; // eax
  int item; // esi
  int nIndex_1; // edx
  WCHAR *pHiddenProcesses_1; // ecx
  int v13; // esi
  WCHAR v14; // ax
  int nLength_1; // ecx
  BYTE *lpData; // [esp+8h] [ebp-14h]
  wchar_t *v17; // [esp+10h] [ebp-Ch]
  int nIndex_2; // [esp+14h] [ebp-8h]
  HKEY hSubKey; // [esp+18h] [ebp-4h]

  v0 = 0;
  nIndex = 0;
  result = RegCreateKeyW(HKEY_CURRENT_USER, L"Software\\Sysinternals\\Process Explorer", &hSubKey);
  if ( !result )
  {
    ppHiddenProcesses = gpHiddenProcesses;
    if ( *gpHiddenProcesses )
    {
      ppHiddenProcesses_1 = gpHiddenProcesses;
      do
      {
        pHiddenProcesses = *ppHiddenProcesses_1;
        ++nIndex;
        v6 = pHiddenProcesses + 1;
        do
        {
          chText = *pHiddenProcesses;
          ++pHiddenProcesses;
        }
        while ( chText );
        v0 += pHiddenProcesses - v6 + 1;
        ppHiddenProcesses_1 = &gpHiddenProcesses[nIndex];
      }
      while ( gpHiddenProcesses[nIndex] );
    }
    nLength = v0 + 1;
    if ( nIndex )
    {
      v9 = malloc(2 * nLength);
      lpData = v9;
      nIndex_2 = 0;
      v17 = v9;
      if ( *ppHiddenProcesses )
      {
        item = 0;
        do
        {
          wcscpy_s(v9, nLength, *ppHiddenProcesses);
          nIndex_1 = nIndex_2++ + 1;
          pHiddenProcesses_1 = gpHiddenProcesses[item];
          v13 = (pHiddenProcesses_1 + 1);
          do
          {
            v14 = *pHiddenProcesses_1;
            ++pHiddenProcesses_1;
          }
          while ( v14 );
          nLength_1 = (pHiddenProcesses_1 - v13) >> 1;
          item = nIndex_1;
          ppHiddenProcesses = &gpHiddenProcesses[nIndex_1];
          v9 = &v17[nLength_1 + 1];
          v17 += nLength_1 + 1;
        }
        while ( *ppHiddenProcesses );
      }
      *v9 = 0;
      RegSetValueExW(hSubKey, L"HiddenProcs", 0, REG_MULTI_SZ, lpData, 2 * nLength);
      result = RegCloseKey(hSubKey);
    }
    else
    {
      RegDeleteValueW(hSubKey, L"HiddenProcs");
      result = RegCloseKey(hSubKey);
    }
  }
  return result;
}

//----- (01026DB0) --------------------------------------------------------
HANDLE __cdecl sub_1026DB0(HANDLE TokenHandle)
{
  DWORD v1; // esi
  unsigned int *v2; // ebx
  int v3; // edi
  unsigned int v4; // esi
  unsigned int *v5; // ecx
  unsigned int v6; // eax
  const __m128i *v7; // esi
  unsigned int v8; // edi
  unsigned int v9; // edx
  _DWORD *v10; // eax
  char *v11; // edx
  void *v12; // ebx
  HMODULE v13; // eax
  FARPROC v14; // eax
  DWORD v15; // eax
  DWORD v16; // esi
  DWORD v17; // eax
  DWORD v18; // esi
  ACL *v19; // edi
  ACL *v20; // ecx
  DWORD v21; // esi
  void *v22; // esi
  struct _SID_AND_ATTRIBUTES v24; // [esp+4h] [ebp-6Ch]
  LPVOID pAce; // [esp+Ch] [ebp-64h]
  PSECURITY_DESCRIPTOR ppSecurityDescriptor; // [esp+10h] [ebp-60h]
  ACL *v27; // [esp+14h] [ebp-5Ch]
  void *v28; // [esp+18h] [ebp-58h]
  PSID TokenInformation; // [esp+1Ch] [ebp-54h]
  int v30; // [esp+20h] [ebp-50h]
  DWORD TokenInformationLength; // [esp+24h] [ebp-4Ch]
  PSID hMem; // [esp+28h] [ebp-48h]
  PSID AccountSid; // [esp+2Ch] [ebp-44h]
  PSID pSid; // [esp+30h] [ebp-40h]
  void *v35; // [esp+34h] [ebp-3Ch]
  PACL ppDacl; // [esp+38h] [ebp-38h]
  unsigned int v37; // [esp+3Ch] [ebp-34h]
  DWORD ReturnLength; // [esp+40h] [ebp-30h]
  void *v39; // [esp+44h] [ebp-2Ch]
  HANDLE handle; // [esp+48h] [ebp-28h]
  struct _SID_IDENTIFIER_AUTHORITY pIdentifierAuthority; // [esp+4Ch] [ebp-24h]
  __int128 v42; // [esp+54h] [ebp-1Ch]
  __int64 v43; // [esp+64h] [ebp-Ch]

  _mm_storeu_si128(&v42, _mm_loadu_si128(L"S-1-16-4096"));
  v28 = TokenHandle;
  *pIdentifierAuthority.Value = 0;
  *&pIdentifierAuthority.Value[4] = 1280;
  pSid = 0;
  AccountSid = 0;
  handle = 0;
  v43 = *L"096";
  hMem = 0;
  TokenInformation = 0;
  v30 = 0;
  AllocateAndInitializeSid(&pIdentifierAuthority, 2u, 0x20u, 0x220u, 0, 0, 0, 0, 0, 0, &pSid);
  v24.Sid = pSid;
  v24.Attributes = 0;
  GetTokenInformation(TokenHandle, TokenPrivileges, 0, 0, &ReturnLength);
  v1 = ReturnLength;
  v35 = malloc(ReturnLength);
  GetTokenInformation(TokenHandle, TokenPrivileges, v35, v1, &ReturnLength);
  v39 = malloc(ReturnLength);
  *v39 = 0;
  AllocateAndInitializeSid(&pIdentifierAuthority, 2u, 0x20u, 0x221u, 0, 0, 0, 0, 0, 0, &AccountSid);
  v2 = sub_1027450(AccountSid);
  if ( !v2 )
  {
    v2 = malloc(0x4Cu);
    v3 = 0;
    v4 = 0;
    *v2 = 0;
    do
    {
      if ( LookupPrivilegeValueW(0, off_10BE0BC[v4], &v2[v3 + 1]) )
        ++*v2;
      ++v4;
      v3 += 3;
    }
    while ( v4 < 5 );
  }
  v5 = v35;
  v6 = 0;
  v37 = 0;
  if ( *v35 )
  {
    v7 = (v35 + 4);
    do
    {
      v8 = *v2;
      v9 = 0;
      if ( *v2 )
      {
        v10 = v2 + 1;
        do
        {
          if ( v7->m128i_i32[0] == *v10 && v7->m128i_i32[1] == v10[1] )
            break;
          ++v9;
          v10 += 3;
        }
        while ( v9 < v8 );
        v6 = v37;
        v5 = v35;
      }
      if ( v9 == v8 )
      {
        v11 = v39 + 12 * *v39;
        v5 = v35;
        ++*v39;
        _mm_storel_epi64((v11 + 4), _mm_loadl_epi64(v7));
        *(v11 + 3) = v7->m128i_i32[2];
        v6 = v37;
      }
      ++v6;
      v7 = (v7 + 12);
      v37 = v6;
    }
    while ( v6 < *v5 );
  }
  free(v5);
  free(v2);
  v12 = v39;
  if ( gpfnCreateRestrictedToken(v28, 0, 1u, &v24, *v39, (v39 + 4), 0, 0, &handle) )
  {
    v13 = LoadLibraryW(L"Advapi32.dll");
    v14 = GetProcAddress(v13, "ConvertStringSidToSidA");
    dword_10CA090 = v14;
    if ( v14 && (v14)(&v42, &hMem) )
    {
      v30 = 32;
      TokenInformation = hMem;
      v15 = GetLengthSid(hMem);
      SetTokenInformation(handle, TokenIntegrityLevel, &TokenInformation, v15 + 8);
      LocalFree(hMem);
    }
  }
  else
  {
    handle = 0;
  }
  GetTokenInformation(handle, TokenUser, 0, 0, &TokenInformationLength);
  v16 = TokenInformationLength;
  v39 = malloc(TokenInformationLength);
  GetTokenInformation(handle, TokenUser, v39, v16, &TokenInformationLength);
  GetSecurityInfo(handle, SE_KERNEL_OBJECT, 4u, 0, 0, &ppDacl, 0, &ppSecurityDescriptor);
  v17 = GetLengthSid(*v39);
  v18 = v17 + ppDacl->AclSize + 8;
  v19 = malloc(v17 + ppDacl->AclSize + 8);
  InitializeAcl(v19, v18, 2u);
  v20 = ppDacl;
  v21 = 0;
  if ( ppDacl->AceCount > 0u )
  {
    do
    {
      GetAce(v20, v21, &pAce);
      AddAce(v19, 2u, v21, pAce, *(pAce + 1));
      v20 = ppDacl;
      ++v21;
    }
    while ( v21 < ppDacl->AceCount );
  }
  v22 = v39;
  AddAccessAllowedAce(v19, 2u, 0x10000000u, *v39);
  SetSecurityInfo(handle, SE_KERNEL_OBJECT, 4u, 0, 0, v19, 0);
  v27 = v19;
  SetTokenInformation(handle, TokenDefaultDacl, &v27, v19->AclSize);
  free(v19);
  free(v22);
  LocalFree(ppSecurityDescriptor);
  FreeSid(pSid);
  FreeSid(AccountSid);
  free(v12);
  return handle;
}
// 109F37C: using guessed type wchar_t aS1164096[12];
// 10BE0BC: using guessed type wchar_t *off_10BE0BC[5];
// 10CA090: using guessed type int dword_10CA090;
// 10CA118: using guessed type int (__stdcall *gpfnCreateRestrictedToken)(void *, unsigned int, unsigned int, struct _SID_AND_ATTRIBUTES *, unsigned int, struct _LUID_AND_ATTRIBUTES *, unsigned int, struct _SID_AND_ATTRIBUTES *, void **);

//----- (01027140) --------------------------------------------------------
BOOL __cdecl QueryCurrentAuthorityInfo(wchar_t **a1)
{
  HANDLE v1; // eax
  wchar_t *v2; // eax
  HANDLE TokenHandle; // [esp+4h] [ebp-80Ch]
  DWORD ReturnLength; // [esp+8h] [ebp-808h]
  void *TokenInformation; // [esp+Ch] [ebp-804h]

  v1 = GetCurrentProcess();
  OpenProcessToken(v1, 8u, &TokenHandle);
  ReturnLength = 2048;
  GetTokenInformation(TokenHandle, TokenUser, &TokenInformation, 0x800u, &ReturnLength);
  ReturnLength = 0;
  QueryAuthorityInfoFromSID(TokenInformation, *a1, &ReturnLength);
  v2 = malloc(2 * ReturnLength);
  *a1 = v2;
  QueryAuthorityInfoFromSID(TokenInformation, v2, &ReturnLength);
  return CloseHandle(TokenHandle);
}

//----- (01027200) --------------------------------------------------------
BOOL __cdecl QueryAuthorityInfoFromSID(PSID pSid, wchar_t *Dst, int a3)
{
  BOOL result; // eax
  PSID_IDENTIFIER_AUTHORITY v4; // edi
  unsigned int v5; // ecx
  int v6; // eax
  int v7; // esi
  int v8; // eax
  DWORD v9; // edi
  int v10; // esi
  PDWORD v11; // eax
  DWORD v12; // [esp+4h] [ebp-4h]

  result = IsValidSid(pSid);
  if ( result )
  {
    v4 = GetSidIdentifierAuthority(pSid);
    v12 = *GetSidSubAuthorityCount(pSid);
    v5 = 12 * v12 + 28;
    if ( *a3 >= v5 )
    {
      v6 = swprintf_s(Dst, *a3, L"S-%lu-", 1);
      v7 = v6;
      if ( v4->Value[0] || v4->Value[1] )
        v8 = swprintf_s(
               &Dst[v6],
               *a3 - v6,
               L"0x%02hx%02hx%02hx%02hx%02hx%02hx",
               v4->Value[0],
               v4->Value[1],
               v4->Value[2],
               v4->Value[3],
               v4->Value[4],
               v4->Value[5]);
      else
        v8 = swprintf_s(
               &Dst[v6],
               *a3 - v6,
               L"%lu",
               v4->Value[5] + ((v4->Value[4] + ((v4->Value[3] + (v4->Value[2] << 8)) << 8)) << 8));
      v9 = 0;
      v10 = v8 + v7;
      if ( v12 )
      {
        do
        {
          v11 = GetSidSubAuthority(pSid, v9++);
          v10 += swprintf_s(&Dst[v10], *a3 - v10, L"-%lu", *v11);
        }
        while ( v9 < v12 );
      }
      result = 1;
    }
    else
    {
      *a3 = v5;
      SetLastError(0x7Au);
      result = 0;
    }
  }
  return result;
}

//----- (01027330) --------------------------------------------------------
char IsBuiltinAdministrative()
{
  HANDLE v0; // eax
  DWORD v1; // esi
  unsigned int *v2; // ebx
  unsigned int v3; // edi
  bool v4; // zf
  _DWORD *v5; // esi
  DWORD ReturnLength; // [esp+0h] [ebp-18h]
  PSID pSid; // [esp+4h] [ebp-14h]
  HANDLE TokenHandle; // [esp+8h] [ebp-10h]
  struct _SID_IDENTIFIER_AUTHORITY pIdentifierAuthority; // [esp+Ch] [ebp-Ch]

  *pIdentifierAuthority.Value = 0;
  *&pIdentifierAuthority.Value[4] = 1280;
  pSid = 0;
  if ( !byte_10CA094 )
  {
    v0 = GetCurrentProcess();
    OpenProcessToken(v0, 8u, &TokenHandle);
    AllocateAndInitializeSid(&pIdentifierAuthority, 2u, 0x20u, 0x220u, 0, 0, 0, 0, 0, 0, &pSid);
    GetTokenInformation(TokenHandle, TokenGroups, 0, 0, &ReturnLength);
    v1 = ReturnLength;
    v2 = malloc(ReturnLength);
    if ( GetTokenInformation(TokenHandle, TokenGroups, v2, v1, &ReturnLength) )
    {
      v3 = 0;
      v4 = *v2 == 0;
      if ( *v2 > 0 )
      {
        v5 = v2 + 2;
        do
        {
          if ( EqualSid(pSid, *(v5 - 1)) && *v5 & 4 && *v5 & 0xFFFFFFEF )
            break;
          ++v3;
          v5 += 2;
        }
        while ( v3 < *v2 );
        v4 = v3 == *v2;
      }
      byte_10CA095 = !v4;
    }
    free(v2);
    FreeSid(pSid);
    CloseHandle(TokenHandle);
    byte_10CA094 = 1;
  }
  return byte_10CA095;
}
// 10CA094: using guessed type char byte_10CA094;
// 10CA095: using guessed type char byte_10CA095;

//----- (01027450) --------------------------------------------------------
_DWORD *__cdecl sub_1027450(PSID AccountSid)
{
  _DWORD *v1; // ebx
  ULONG v2; // esi
  _DWORD *v3; // eax
  ULONG v4; // esi
  struct _LUID *v5; // edi
  struct _LSA_OBJECT_ATTRIBUTES ObjectAttributes; // [esp+4h] [ebp-24h]
  PVOID PolicyHandle; // [esp+1Ch] [ebp-Ch]
  PLSA_UNICODE_STRING UserRights; // [esp+20h] [ebp-8h]
  ULONG CountOfRights; // [esp+24h] [ebp-4h]

  *&ObjectAttributes.SecurityDescriptor = 0i64;
  v1 = 0;
  _mm_storeu_si128(&ObjectAttributes, 0i64);
  if ( !LsaOpenPolicy(0, &ObjectAttributes, 0x800u, &PolicyHandle) )
  {
    if ( !LsaEnumerateAccountRights(PolicyHandle, AccountSid, &UserRights, &CountOfRights) )
    {
      v2 = CountOfRights;
      if ( CountOfRights )
      {
        v3 = malloc(12 * CountOfRights + 16);
        v1 = v3;
        *v3 = v2;
        v4 = 0;
        if ( CountOfRights )
        {
          v5 = (v3 + 1);
          do
          {
            LookupPrivilegeValueW(0, UserRights[v4++].Buffer, v5);
            v5 = (v5 + 12);
          }
          while ( v4 < CountOfRights );
        }
        LsaFreeMemory(UserRights);
      }
    }
    LsaClose(PolicyHandle);
  }
  return v1;
}

//----- (01027500) --------------------------------------------------------
int sub_1027500(wchar_t *Dst, wchar_t *Format, ...)
{
  va_list ArgList; // [esp+10h] [ebp+10h]

  va_start(ArgList, Format);
  return vswprintf_s(Dst, 0x80u, Format, ArgList);
}

//----- (01027520) --------------------------------------------------------
_DWORD *__thiscall sub_1027520(_DWORD *this, int (__stdcall ***a2)(_DWORD, GUID *, _DWORD *))
{
  _DWORD *v2; // esi
  bool v3; // sf
  _DWORD *result; // eax

  v2 = this;
  *this = 0;
  if ( !a2 )
    return this;
  v3 = (**a2)(a2, &stru_109FC40, this) < 0;
  result = v2;
  if ( v3 )
    *v2 = 0;
  return result;
}
// 109FC40: using guessed type GUID stru_109FC40;

//----- (01027560) --------------------------------------------------------
_DWORD *__thiscall sub_1027560(_DWORD *this, int (__stdcall ***a2)(_DWORD, GUID *, _DWORD *))
{
  _DWORD *v2; // esi
  bool v3; // sf
  _DWORD *result; // eax

  v2 = this;
  *this = 0;
  if ( !a2 )
    return this;
  v3 = (**a2)(a2, &stru_109FD30, this) < 0;
  result = v2;
  if ( v3 )
    *v2 = 0;
  return result;
}
// 109FD30: using guessed type GUID stru_109FD30;

//----- (010275A0) --------------------------------------------------------
_DWORD *__thiscall sub_10275A0(_DWORD *this)
{
  _DWORD *result; // eax

  *this = &MixedModeStackWalker::`vftable';
  result = this;
  this[1] = 1;
  this[6] = 0;
  this[7] = 0;
  this[8] = 0;
  this[9] = 0;
  this[3] = 0;
  this[4] = 0;
  return result;
}
// 109F470: using guessed type void *MixedModeStackWalker::`vftable';

//----- (01027600) --------------------------------------------------------
int __thiscall sub_1027600(_DWORD *this, int a2)
{
  _DWORD *v2; // esi
  int v3; // eax

  v2 = this;
  if ( *this == a2 )
    return *v2;
  if ( a2 )
    (*(*a2 + 4))(a2);
  v3 = *v2;
  *v2 = a2;
  if ( v3 )
  {
    (*(*v3 + 8))(v3);
    return *v2;
  }
  return a2;
}

//----- (01027640) --------------------------------------------------------
_DWORD *__thiscall sub_1027640(void *this, char a2)
{
  _DWORD *v2; // esi
  int v3; // ecx
  int v4; // ecx
  int v5; // ecx
  int v6; // ecx

  v2 = this;
  *this = &MixedModeStackWalker::`vftable';
  if ( *(this + 3) )
    *(this + 3) = 0;
  v3 = *(this + 9);
  if ( v3 )
    (*(*v3 + 8))(v2[9]);
  v4 = v2[8];
  if ( v4 )
    (*(*v4 + 8))(v4);
  v5 = v2[7];
  if ( v5 )
    (*(*v5 + 8))(v5);
  v6 = v2[6];
  if ( v6 )
    (*(*v6 + 8))(v6);
  if ( a2 & 1 )
    j__free(v2);
  return v2;
}
// 109F470: using guessed type void *MixedModeStackWalker::`vftable';

//----- (010276F0) --------------------------------------------------------
unsigned int __thiscall sub_10276F0(_DWORD *this, int *a2)
{
  _DWORD *v2; // esi
  unsigned int v3; // edi
  int *v4; // ecx
  int v5; // eax

  v2 = this;
  v3 = this[1];
  if ( v3 >= this[2] && !sub_10288A0(this, v3 + 1) )
    ATL::AtlThrowImpl(-2147024882);
  v4 = (*v2 + 4 * v3);
  if ( v4 )
  {
    v5 = *a2;
    *v4 = *a2;
    if ( v5 )
      (*(*v5 + 4))(v5);
  }
  ++v2[1];
  return v3;
}

//----- (01027740) --------------------------------------------------------
_DWORD *__thiscall sub_1027740(_DWORD *this, int *a2)
{
  _DWORD *v2; // edi
  int v3; // ebx
  _DWORD *v4; // esi
  int v5; // edx
  int v6; // ecx
  _DWORD *v7; // eax
  _DWORD *result; // eax
  int v9; // [esp+18h] [ebp-10h]

  v2 = this;
  v3 = this[1];
  sub_1027F70(this);
  v4 = v2[4];
  v5 = *v4;
  v9 = *v4;
  if ( v4 )
  {
    v6 = *a2;
    v4[2] = *a2;
    if ( v6 )
    {
      (*(*v6 + 4))(v6);
      v5 = v9;
    }
  }
  v2[4] = v5;
  v4[1] = v3;
  *v4 = 0;
  ++v2[2];
  v7 = v2[1];
  if ( v7 )
    *v7 = v4;
  else
    *v2 = v4;
  result = v4;
  v2[1] = v4;
  return result;
}

//----- (010277E0) --------------------------------------------------------
void __stdcall sub_10277E0(int *a1)
{
  int *v1; // edx
  unsigned int v2; // edi
  unsigned int v3; // ebx
  unsigned int v4; // ecx
  int v5; // edx
  int v6; // eax
  _DWORD *v7; // eax
  _DWORD *v8; // esi
  int v9; // eax
  _DWORD *v10; // eax
  wchar_t *v11; // ST00_4
  int v12; // eax
  const char *v13; // [esp-4h] [ebp-24h]
  void *v14; // [esp+10h] [ebp-10h]
  int v15; // [esp+1Ch] [ebp-4h]

  v1 = a1;
  v2 = a1[1] - 1;
  v3 = a1[1] - 2;
  if ( (v3 & 0x80000000) == 0 )
  {
    while ( 1 )
    {
      v4 = v1[1];
      if ( v2 >= v4 )
LABEL_26:
        ATL::AtlThrowImpl(-2147024809);
      v5 = *v1;
      if ( *(*(v5 + 4 * v2) + 24) == 3 )
      {
        if ( v3 >= v4 )
          goto LABEL_26;
        v6 = *(v5 + 4 * v3);
        if ( *(v6 + 24) == 1 || !*(v6 + 24) )
          break;
      }
      if ( v3 >= v4 )
        goto LABEL_26;
      if ( *(*(v5 + 4 * v3) + 24) == 3 )
      {
        v9 = *(v5 + 4 * v2);
        if ( *(v9 + 24) == 1 || !*(v9 + 24) )
        {
          v10 = operator new(0x20u);
          v8 = v10;
          v14 = v10;
          v15 = 2;
          if ( v10 )
          {
            *v10 = &SymbolInfo::`vftable';
            v10[1] = 1;
            v10[7] = operator new[](0x800u);
          }
          else
          {
            v8 = 0;
          }
          v15 = -1;
          v14 = v8;
          if ( v8 )
            (*(*v8 + 4))(v8);
          v15 = 3;
          v13 = "[Managed to Unmanaged Transition]";
          goto LABEL_23;
        }
      }
LABEL_24:
      --v2;
      if ( (--v3 & 0x80000000) != 0 )
        return;
      v1 = a1;
    }
    v7 = operator new(0x20u);
    v8 = v7;
    v14 = v7;
    v15 = 0;
    if ( v7 )
    {
      *v7 = &SymbolInfo::`vftable';
      v7[1] = 1;
      v7[7] = operator new[](0x800u);
    }
    else
    {
      v8 = 0;
    }
    v15 = -1;
    v14 = v8;
    if ( v8 )
      (*(*v8 + 4))(v8);
    v15 = 1;
    v13 = "[Unmanaged to Managed Transition]";
LABEL_23:
    v11 = v8[7];
    v8[4] = 0;
    v8[5] = 0;
    swprintf_s(v11, 0x400u, L"%S", v13);
    v8[6] = 1;
    sub_1028AE0(a1, v2, &v14, 1u);
    v12 = *v8;
    v15 = -1;
    (*(v12 + 8))(v8);
    goto LABEL_24;
  }
}
// 109F420: using guessed type void *SymbolInfo::`vftable';

//----- (010279A0) --------------------------------------------------------
void __cdecl sub_10279A0(_DWORD *a1, int a2)
{
  int v2; // ecx
  _DWORD *v3; // eax

  v2 = a2;
  if ( a2 )
  {
    v3 = a1;
    do
    {
      if ( v3 )
        *v3 = 0;
      ++v3;
      --v2;
    }
    while ( v2 );
  }
}

//----- (010279D0) --------------------------------------------------------
int __cdecl sub_10279D0(int a1, unsigned int a2)
{
  unsigned int v2; // esi
  int v3; // ecx
  int result; // eax

  v2 = 0;
  if ( a2 )
  {
    do
    {
      v3 = *(a1 + 4 * v2);
      if ( v3 )
        result = (*(*v3 + 8))(*(a1 + 4 * v2));
      ++v2;
    }
    while ( v2 < a2 );
  }
  return result;
}

//----- (01027A00) --------------------------------------------------------
int __cdecl sub_1027A00(HWND hWnd, int a2, char a3)
{
  void (__stdcall *v3)(HWND, UINT, WPARAM, LPARAM); // edi
  int v4; // esi
  LRESULT v5; // eax
  char v6; // al
  int v7; // ecx
  unsigned int v8; // eax
  IUnknown *v9; // eax
  int v10; // esi
  int v11; // eax
  char v12; // al
  char v13; // cl
  signed int v14; // eax
  char v16; // [esp-22Ch] [ebp-6D0h]
  const IID *v17; // [esp-14h] [ebp-4B8h]
  IUnknown *v18; // [esp-10h] [ebp-4B4h]
  DWORD v19; // [esp-Ch] [ebp-4B0h]
  const IID *v20; // [esp-8h] [ebp-4ACh]
  LPVOID *v21; // [esp-4h] [ebp-4A8h]
  LPARAM lParam; // [esp+Ch] [ebp-498h]
  int v23; // [esp+10h] [ebp-494h]
  int v24; // [esp+14h] [ebp-490h]
  LPARAM v25; // [esp+2Ch] [ebp-478h]
  int v26; // [esp+40h] [ebp-464h]
  LPVOID *v27; // [esp+44h] [ebp-460h]
  int v28; // [esp+48h] [ebp-45Ch]
  void *v29; // [esp+4Ch] [ebp-458h]
  unsigned int v30; // [esp+50h] [ebp-454h]
  LPVOID ppv; // [esp+54h] [ebp-450h]
  int v32; // [esp+58h] [ebp-44Ch]
  LPVOID *v33; // [esp+5Ch] [ebp-448h]
  unsigned int v34; // [esp+60h] [ebp-444h]
  int v35; // [esp+67h] [ebp-43Dh]
  char v36; // [esp+6Ch] [ebp-438h]
  int v37; // [esp+70h] [ebp-434h]
  int v38; // [esp+7Ch] [ebp-428h]
  int v39; // [esp+80h] [ebp-424h]
  wchar_t Dst; // [esp+90h] [ebp-414h]
  wchar_t Src; // [esp+298h] [ebp-20Ch]

  lParam = 0;
  memset(&v23, 0, 0x30u);
  v21 = &ppv;
  v20 = &stru_109F3BC;
  v19 = 1;
  v18 = 0;
  if ( byte_10CA09A )
    v17 = &stru_109F40C;
  else
    v17 = &stru_109F3AC;
  CoCreateInstance(v17, v18, v19, v20, v21);
  v3 = SendMessageW;
  v4 = 0;
  BYTE1(v35) = 0;
  v32 = 0;
  v28 = 0;
  lParam = 4;
  v5 = SendMessageW(hWnd, 0x1004u, 0, 0);
  v24 = 0;
  v23 = v5 - 1;
  if ( SendMessageW(hWnd, 0x104Bu, 0, &lParam) )
  {
    do
    {
      v6 = sub_10558D0(hWnd, hWnd, &lParam, v25, &v35);
      v7 = BYTE1(v35);
      if ( v6 )
        v7 = 1;
      *(&v35 + 1) = v7;
      *(v25 + 8) = 0;
      if ( v35 )
        ++v4;
    }
    while ( SendMessageW(hWnd, 0x104Bu, 0, &lParam) );
    v28 = v4;
  }
  if ( !(*(*ppv + 16))(ppv, a2, &v27) )
  {
    (*(*v27 + 4))(v27, &v33);
    (*(*v33 + 6))(v33, &v34);
    v29 = operator new[](4 * v34);
    (*(*v33 + 7))(v33, v34, v29, &v34);
    v3 = SendMessageW;
    v8 = 0;
    v30 = 0;
    if ( v34 )
    {
      do
      {
        v21 = &Src;
        v26 = 260;
        v20 = &v26;
        v9 = *(v29 + v8);
        v19 = 260;
        v18 = v9;
        (v9->lpVtbl[1].AddRef)(v9, 260, &v26, &Src);
        v10 = 0;
        if ( (v3)(hWnd, 0x1004u, 0, 0) > 0 )
        {
          while ( 1 )
          {
            lParam = 4;
            v23 = v10;
            v24 = 0;
            v3(hWnd, 0x104Bu, 0, &lParam);
            v11 = *(v25 + 16);
            if ( (v11 == 1 || !v11) && !_wcsicmp(&Src, (v25 + 36)) )
              break;
            if ( ++v10 >= (v3)(hWnd, 0x1004u, 0, 0) )
              goto LABEL_22;
          }
          ++v32;
          v12 = sub_1058A20(v25);
          v13 = BYTE1(v35);
          if ( v12 )
            v13 = 1;
          BYTE1(v35) = v13;
        }
LABEL_22:
        if ( v10 == (v3)(hWnd, 0x1004u, 0, 0) )
        {
          BYTE1(v35) = 1;
          memset(&v36, 0, 0x22Cu);
          wcscpy_s(&Dst, 0x104u, &Src);
          v37 = 4;
          v14 = 2;
          v39 = 0;
          if ( a3 )
            v14 = 0;
          v38 = v14;
          qmemcpy(&v16, &v36, 0x22Cu);
          sub_10173D0(hWnd, v16);
          v3 = SendMessageW;
        }
        v8 = v30 + 1;
        v30 = v8;
      }
      while ( v8 < v34 );
      v4 = v28;
    }
    v21 = v33;
    (*(*v33 + 2))(v33);
    j__free(v29);
    if ( v32 != v4 || BYTE1(v35) )
      InvalidateRect(hWnd, 0, 0);
    v21 = v27;
    (*(*v27 + 2))(v27);
  }
  if ( BYTE1(v35) )
    v3(hWnd, 0xBu, 1u, 0);
  v21 = ppv;
  return (*(*ppv + 8))(ppv);
}
// 109F40C: using guessed type GUID stru_109F40C;
// 10CA09A: using guessed type char byte_10CA09A;

//----- (01027DD0) --------------------------------------------------------
signed int __stdcall sub_1027DD0(int (__stdcall ***a1)(_DWORD, GUID *, int *))
{
  int (__stdcall ***v1)(_DWORD, GUID *, int *); // esi
  int (__stdcall **v2)(_DWORD, GUID *, int *); // eax
  int (__stdcall ***v3)(_DWORD, GUID *, int *); // eax
  signed int v4; // esi
  int (__stdcall **v5)(_DWORD, GUID *, int *); // eax
  int v6; // eax
  int (__stdcall **v7)(_DWORD, GUID *, int *); // eax
  int v8; // ecx
  int *v10; // [esp+8h] [ebp-14h]
  int v11; // [esp+Ch] [ebp-10h]
  int v12; // [esp+18h] [ebp-4h]

  v1 = a1;
  if ( !a1 )
    return 3;
  a1 = 0;
  v2 = *v1;
  v12 = 0;
  if ( (*v2)(v1, &stru_109FBB8, &a1) || (v3 = a1) == 0 )
  {
    v11 = 0;
    v5 = *v1;
    LOBYTE(v12) = 1;
    if ( !(*v5)(v1, &stru_109FBC8, &v11) )
    {
      v6 = v11;
      if ( v11 )
      {
        v4 = 1;
LABEL_11:
        LOBYTE(v12) = 0;
        if ( v6 )
          (*(*v6 + 8))(v6);
        v3 = a1;
        goto LABEL_14;
      }
    }
    v10 = 0;
    v7 = *v1;
    LOBYTE(v12) = 2;
    if ( !(*v7)(v1, &stru_109FBD8, &v10) && v10 )
    {
      v8 = *v10;
      v4 = 2;
      LOBYTE(v12) = 1;
      (*(v8 + 8))(v10);
      v6 = v11;
      goto LABEL_11;
    }
    LOBYTE(v12) = 1;
    if ( v10 )
      (*(*v10 + 8))(v10);
    LOBYTE(v12) = 0;
    if ( v11 )
      (*(*v11 + 8))(v11);
    v12 = -1;
    if ( a1 )
      ((*a1)[2])(a1);
    return 3;
  }
  v4 = 0;
LABEL_14:
  v12 = -1;
  if ( v3 )
    ((*v3)[2])(v3);
  return v4;
}
// 109FBB8: using guessed type GUID stru_109FBB8;
// 109FBC8: using guessed type GUID stru_109FBC8;
// 109FBD8: using guessed type GUID stru_109FBD8;

//----- (01027F10) --------------------------------------------------------
int __cdecl sub_1027F10(int a1, LPCWSTR lpsz, int a3)
{
  wchar_t **v3; // eax
  void **v4; // edi

  *a3 = 0;
  *(a3 + 4) = 0;
  v3 = sub_102E760(a1, lpsz);
  v4 = v3;
  if ( v3 && sub_102ECA0(v3, a3, 0) )
  {
    sub_102EC80(v4);
    j__free(v4);
  }
  return a3;
}

//----- (01027F60) --------------------------------------------------------
int __thiscall sub_1027F60(_DWORD *this)
{
  return this[7];
}

//----- (01027F70) --------------------------------------------------------
void __thiscall sub_1027F70(_DWORD *this)
{
  _DWORD *v1; // esi
  unsigned int v2; // edi
  _DWORD *v3; // eax
  int v4; // edx
  _DWORD *v5; // eax
  int i; // edx

  v1 = this;
  if ( !this[4] )
  {
    v2 = 12 * this[5];
    if ( !is_mul_ok(0xCu, this[5]) || v2 > 0xFFFFFFFF || -1 - v2 < 4 || (v3 = malloc(v2 + 4)) == 0 )
      ATL::AtlThrowImpl(-2147024882);
    *v3 = v1[3];
    v1[3] = v3;
    v4 = v1[5];
    v5 = &v3[3 * v4 - 2];
    for ( i = v4 - 1; i >= 0; --i )
    {
      *v5 = v1[4];
      v1[4] = v5;
      v5 -= 3;
    }
  }
}

//----- (01027FF0) --------------------------------------------------------
signed int __stdcall sub_1027FF0(unsigned int a1, _DWORD *a2, unsigned int *a3)
{
  int *v3; // edi
  unsigned int v5; // edx
  void *v6; // esi
  void *v7; // eax
  int v8; // ecx
  void *v9; // eax
  _DWORD *v10; // edi
  unsigned int v11; // edx
  int v12; // [esp+4h] [ebp-4h]

  v3 = a1;
  if ( (*(*a1 + 16))(a1, 0, &a1, 0) )
    return 0;
  v5 = a1;
  v6 = 0;
  if ( a1 )
  {
    v7 = operator new[](4 * a1);
    v8 = *v3;
    v6 = v7;
    v12 = 0;
    if ( (*(v8 + 16))(v3, a1, &v12, v7) )
    {
      j_j__free(v6);
      return 0;
    }
    v5 = a1;
  }
  *a3 = v5;
  if ( v5 )
  {
    v9 = operator new[](4 * v5);
    v10 = a2;
    v11 = 0;
    *a2 = v9;
    if ( a1 )
    {
      do
      {
        *(*v10 + 4 * v11) = *(v6 + v11);
        ++v11;
      }
      while ( v11 < a1 );
    }
  }
  j_j__free(v6);
  return 1;
}

//----- (010280C0) --------------------------------------------------------
signed int __stdcall sub_10280C0(int (__stdcall ***a1)(_DWORD, GUID *, int *), _DWORD *a2)
{
  _DWORD *v2; // ecx
  int v3; // eax
  int v4; // eax
  int v5; // ecx
  signed int v6; // esi
  int (__stdcall **v7)(_DWORD, GUID *, int *); // eax
  _DWORD *v8; // ecx
  int v9; // eax
  int v10; // eax
  int (__stdcall **v11)(_DWORD, GUID *, int *); // eax
  int v12; // ecx
  wchar_t *v13; // ecx
  signed int v14; // edx
  wchar_t v15; // ax
  char v17; // [esp+Ch] [ebp-1B38h]
  char v18; // [esp+10h] [ebp-1B34h]
  char v19; // [esp+14h] [ebp-1B30h]
  char v20; // [esp+18h] [ebp-1B2Ch]
  char v21; // [esp+1Ch] [ebp-1B28h]
  char v22; // [esp+20h] [ebp-1B24h]
  char v23; // [esp+24h] [ebp-1B20h]
  char v24; // [esp+28h] [ebp-1B1Ch]
  char v25; // [esp+2Ch] [ebp-1B18h]
  int v26; // [esp+30h] [ebp-1B14h]
  int v27; // [esp+34h] [ebp-1B10h]
  int v28; // [esp+38h] [ebp-1B0Ch]
  int v29; // [esp+3Ch] [ebp-1B08h]
  int v30; // [esp+40h] [ebp-1B04h]
  int v31; // [esp+44h] [ebp-1B00h]
  int v32; // [esp+48h] [ebp-1AFCh]
  int v33; // [esp+4Ch] [ebp-1AF8h]
  int (__stdcall ***v34)(_DWORD, GUID *, int *); // [esp+50h] [ebp-1AF4h]
  _DWORD *v35; // [esp+54h] [ebp-1AF0h]
  _DWORD *v36; // [esp+58h] [ebp-1AECh]
  int v37; // [esp+5Ch] [ebp-1AE8h]
  int v38; // [esp+60h] [ebp-1AE4h]
  int *v39; // [esp+64h] [ebp-1AE0h]
  int v40; // [esp+68h] [ebp-1ADCh]
  int v41; // [esp+12Ch] [ebp-1A18h]
  wchar_t Dst; // [esp+334h] [ebp-1810h]
  char v43; // [esp+B34h] [ebp-1010h]
  char v44; // [esp+F34h] [ebp-C10h]
  wchar_t Ext; // [esp+1334h] [ebp-810h]
  wchar_t Filename; // [esp+1534h] [ebp-610h]
  wchar_t FullPath; // [esp+1734h] [ebp-410h]
  int v48; // [esp+1B40h] [ebp-4h]

  if ( sub_1027DD0(a1) == 1 )
  {
    v2 = 0;
    v36 = 0;
    if ( a1 )
    {
      v3 = (**a1)(a1, &stru_109FBC8, &v36);
      v2 = v36;
      if ( v3 < 0 )
        v2 = 0;
      v36 = v2;
    }
    v4 = *v2;
    v48 = 0;
    if ( (*(v4 + 44))(v2, &v29) )
    {
LABEL_15:
      v5 = v36;
      v6 = 0;
    }
    else
    {
      switch ( v29 )
      {
        case 3:
          sub_1028A30(a2, "[AppDomain Transition]", 0, 0, 1);
          v5 = v36;
          v6 = 1;
          break;
        case 4:
          sub_1028A30(a2, "[Lightweight function]", 0, 0, 1);
          v5 = v36;
          v6 = 1;
          break;
        case 5:
          sub_1028A30(a2, "[Func Eval]", 0, 0, 1);
          v5 = v36;
          v6 = 1;
          break;
        case 7:
          sub_1028A30(a2, "[Class Init]", 0, 0, 1);
          v5 = v36;
          v6 = 1;
          break;
        case 8:
          sub_1028A30(a2, "[Exception]", 0, 0, 1);
          v5 = v36;
          v6 = 1;
          break;
        case 9:
          sub_1028A30(a2, "[Security]", 0, 0, 1);
          v5 = v36;
          v6 = 1;
          break;
        case 10:
          sub_1028A30(a2, "[JIT Compilation]", 0, 0, 1);
          v5 = v36;
          v6 = 1;
          break;
        default:
          goto LABEL_15;
      }
    }
  }
  else
  {
    v34 = 0;
    v7 = *a1;
    v48 = 1;
    if ( (*v7)(a1, &stru_109FBB8, &v34) )
    {
      v6 = 0;
    }
    else
    {
      v8 = 0;
      v35 = 0;
      if ( v34 )
      {
        v9 = (**v34)(v34, &stru_109FD30, &v35);
        v8 = v35;
        if ( v9 < 0 )
          v8 = 0;
        v35 = v8;
      }
      v33 = 0;
      v10 = *v8;
      LOBYTE(v48) = 3;
      if ( (*(v10 + 52))(v8, &v33) || (memset(&v40, 0, 0x2CCu), v40 = 65539, (*(*v33 + 24))(v33, 716, &v40)) )
      {
        v6 = 0;
      }
      else
      {
        v37 = 0;
        v11 = *a1;
        LOBYTE(v48) = 4;
        if ( (v11[5])(a1, &v37) || (*(*v37 + 20))(v37, &v30) )
        {
          v6 = 0;
        }
        else
        {
          v39 = 0;
          LOBYTE(v48) = 5;
          if ( (*(*v37 + 12))(v37, &v39) )
          {
            v6 = 0;
          }
          else
          {
            v38 = 0;
            v12 = *v39;
            LOBYTE(v48) = 6;
            if ( (*(v12 + 56))(v39, &stru_109F3CC, &v38)
              || (*(*v38 + 120))(v38, v30, &v28, &v44, 512, &v21, &v23, &v24, &v18, &v22, &v25)
              || (*(*v38 + 48))(v38, v28, &v43, 512, &v20, &v17, &v19) )
            {
              v6 = 0;
            }
            else
            {
              sub_1027560(&v31, a1);
              LOBYTE(v48) = 7;
              if ( (*(*v31 + 44))(v31, &v27) )
              {
                v6 = 0;
              }
              else
              {
                v32 = 0;
                LOBYTE(v48) = 8;
                if ( (*(*v39 + 20))(v39, &v32) )
                {
                  v6 = 0;
                }
                else
                {
                  v26 = 512;
                  if ( (*(*v39 + 24))(v39, 512, &v26, &FullPath)
                    || _wsplitpath_s(&FullPath, 0, 0, 0, 0, &Filename, 0x100u, &Ext, 0x100u) )
                  {
                    v13 = &FullPath;
                    v14 = 512;
                    while ( v14 != -2147483134 )
                    {
                      v15 = *(v13 + L"<Unresolved>" - &FullPath);
                      if ( !v15 )
                        break;
                      *v13 = v15;
                      ++v13;
                      if ( !--v14 )
                        goto LABEL_44;
                    }
                    if ( v14 )
                      goto LABEL_45;
LABEL_44:
                    --v13;
LABEL_45:
                    *v13 = 0;
                  }
                  else
                  {
                    swprintf_s(&FullPath, 0x200u, L"%s%s", &Filename, &Ext);
                  }
                  swprintf_s(&Dst, 0x400u, L"%s!%s.%s+0x%x", &FullPath, &v43, &v44, v27);
                  sub_1028A90(a2, &Dst, v41, 0, 0);
                  v6 = 1;
                }
                LOBYTE(v48) = 7;
                if ( v32 )
                  (*(*v32 + 8))(v32);
              }
              LOBYTE(v48) = 6;
              if ( v31 )
                (*(*v31 + 8))(v31);
            }
            LOBYTE(v48) = 5;
            if ( v38 )
              (*(*v38 + 8))(v38);
          }
          LOBYTE(v48) = 4;
          if ( v39 )
            (*(*v39 + 8))(v39);
        }
        LOBYTE(v48) = 3;
        if ( v37 )
          (*(*v37 + 8))(v37);
      }
      LOBYTE(v48) = 2;
      if ( v33 )
        (*(*v33 + 8))(v33);
      LOBYTE(v48) = 1;
      if ( v35 )
        (*(*v35 + 8))(v35);
    }
    v5 = v34;
  }
  v48 = -1;
  if ( v5 )
    (*(*v5 + 8))(v5);
  return v6;
}
// 109F3CC: using guessed type GUID stru_109F3CC;
// 109FBB8: using guessed type GUID stru_109FBB8;
// 109FBC8: using guessed type GUID stru_109FBC8;
// 109FD30: using guessed type GUID stru_109FD30;
// 109FD40: using guessed type wchar_t aUnresolved[13];

//----- (010286C0) --------------------------------------------------------
int __stdcall sub_10286C0(int a1, _DWORD *a2)
{
  *a2 = 0;
  return 0;
}

//----- (010286E0) --------------------------------------------------------
int *__cdecl sub_10286E0(wchar_t *a1, int a2)
{
  int *result; // eax
  int *v3; // esi
  __int16 Dst[260]; // [esp+Ch] [ebp-20Ch]

  result = sub_102ED60(a2);
  v3 = result;
  if ( result )
  {
    do
    {
      if ( sub_102E850(v3, Dst, 0x104u) && !_wcsnicmp(a1, Dst, wcslen(a1)) )
        break;
      if ( v3 )
        j__free(v3);
      v3 = sub_102EE00(a2);
    }
    while ( v3 );
    result = v3;
  }
  return result;
}

//----- (01028790) --------------------------------------------------------
int __cdecl sub_1028790(wchar_t *Src, wchar_t *Dst)
{
  wchar_t *v2; // eax
  int result; // eax

  wcscpy_s(Dst, 0x104u, Src);
  v2 = wcsrchr(Dst, 0x2Eu);
  if ( v2 && v2 != Dst )
    *v2 = 0;
  result = 0;
  Dst[14] = 0;
  return result;
}

//----- (010287D0) --------------------------------------------------------
int __stdcall sub_10287D0(int a1, DWORD dwThreadId, int a3, int a4, int a5)
{
  HANDLE v5; // edi
  HANDLE v7; // eax
  void *v8; // esi
  THREADENTRY32 te; // [esp+10h] [ebp-20h]

  v5 = CreateToolhelp32Snapshot(4u, *(a1 + 12));
  if ( v5 == -1 )
    return -2147467259;
  te.dwSize = 28;
  if ( !Thread32First(v5, &te) )
    goto LABEL_6;
  while ( te.th32OwnerProcessID != *(a1 + 12) || te.th32ThreadID != dwThreadId )
  {
    if ( !Thread32Next(v5, &te) )
      goto LABEL_6;
  }
  v7 = OpenThread(0x1F03FFu, 1, dwThreadId);
  v8 = v7;
  if ( !v7 )
  {
LABEL_6:
    CloseHandle(v5);
    return -2147467259;
  }
  if ( !GetThreadContext(v7, a5) )
  {
    CloseHandle(v8);
    CloseHandle(v5);
    return -2147467259;
  }
  CloseHandle(v8);
  CloseHandle(v5);
  return 0;
}

//----- (010288A0) --------------------------------------------------------
char __thiscall sub_10288A0(const void **this, unsigned int a2)
{
  char *v2; // esi
  const void **v3; // edi
  unsigned int v4; // edx
  void *v5; // eax
  char *v7; // ecx
  void *v8; // ecx
  int v9; // eax
  const void *v10; // [esp+10h] [ebp+8h]

  v2 = a2;
  v3 = this;
  v4 = this[2];
  if ( a2 > v4 )
  {
    if ( *this )
    {
      v7 = this[3];
      if ( !v7 )
      {
        v7 = (v4 >> 1);
        if ( a2 - v4 > v4 >> 1 )
          v7 = (a2 - v4);
      }
      if ( a2 < &v7[v4] )
        v2 = &v7[v4];
      v8 = calloc(v2, 4u);
      v10 = v8;
      if ( !v8 )
        return 0;
      v9 = memmove_s(v8, 4 * v3[1], *v3, 4 * v3[1]);
      sub_100B650(v9);
      free(*v3);
      *v3 = v10;
    }
    else
    {
      if ( this[3] > a2 )
        v2 = this[3];
      v5 = calloc(v2, 4u);
      *v3 = v5;
      if ( !v5 )
        return 0;
    }
    v3[2] = v2;
  }
  return 1;
}

//----- (01028940) --------------------------------------------------------
FARPROC __thiscall sub_1028940(_DWORD *this, _DWORD *a2)
{
  _DWORD *v2; // esi
  HMODULE v3; // eax
  FARPROC result; // eax
  _DWORD *v5; // eax
  _DWORD *v6; // edi
  int v7; // ecx
  int v8; // edx
  int v9; // ecx
  _DWORD *v10; // eax
  int v11; // edi
  int v12; // ecx
  int v13; // ecx

  v2 = this;
  this[5] = a2;
  this[2] = *a2;
  this[3] = a2[3];
  v3 = LoadLibraryW(L"mscoree.dll");
  result = GetProcAddress(v3, "CLRCreateInstance");
  if ( result )
  {
    if ( (result)(&stru_109F3EC, &stru_109F3DC, v2 + 6) )
    {
      result = 0;
    }
    else
    {
      v5 = operator new(0x10u);
      v6 = v5;
      if ( v5 )
      {
        v7 = v2[3];
        v8 = v2[2];
        *v5 = &CCorDebugDataTarget::`vftable';
        v5[1] = 1;
        v5[2] = v7;
        v5[3] = v8;
      }
      else
      {
        v6 = 0;
      }
      v9 = v2[8];
      if ( v9 )
        (*(*v9 + 8))(v2[8]);
      v2[8] = v6;
      v10 = operator new(0xCu);
      v11 = v10;
      if ( v10 )
      {
        v12 = v2[2];
        *v10 = &CCLRDebuggingLibraryProvider::`vftable';
        v10[1] = 1;
        v10[2] = v12;
      }
      else
      {
        v11 = 0;
      }
      v13 = v2[9];
      if ( v13 )
        (*(*v13 + 8))(v2[9]);
      v2[9] = v11;
      result = (sub_1029500(v2, v2[8], v2[6], v11) == 0);
    }
  }
  return result;
}
// 109F3DC: using guessed type GUID stru_109F3DC;
// 109F3EC: using guessed type GUID stru_109F3EC;
// 109F440: using guessed type void *CCorDebugDataTarget::`vftable';
// 109F45C: using guessed type void *CCLRDebuggingLibraryProvider::`vftable';

//----- (01028A30) --------------------------------------------------------
int __thiscall sub_1028A30(_DWORD *this, int a2, int a3, int a4, int a5)
{
  _DWORD *v5; // esi
  wchar_t *v6; // ST00_4
  int result; // eax

  v5 = this;
  if ( a2 )
  {
    v6 = this[7];
    this[4] = a3;
    this[5] = a4;
    swprintf_s(v6, 0x400u, L"%S", a2);
    result = a5;
  }
  else
  {
    result = a5;
    this[4] = 0;
    this[5] = 0;
  }
  v5[6] = a5;
  return result;
}

//----- (01028A90) --------------------------------------------------------
int __thiscall sub_1028A90(_DWORD *this, int a2, int a3, int a4, int a5)
{
  _DWORD *v5; // esi
  wchar_t *v6; // ST00_4
  int result; // eax

  v5 = this;
  if ( a2 )
  {
    v6 = this[7];
    this[4] = a3;
    this[5] = a4;
    swprintf_s(v6, 0x400u, L"%s", a2);
    result = a5;
  }
  else
  {
    result = a5;
    this[7] = 0;
  }
  v5[6] = a5;
  return result;
}

//----- (01028AE0) --------------------------------------------------------
void __thiscall sub_1028AE0(int *this, unsigned int a2, int *a3, unsigned int a4)
{
  int *v4; // ebx
  unsigned int v5; // edi
  unsigned int v6; // esi
  int v7; // eax
  unsigned int v8; // edi
  unsigned int v9; // eax
  unsigned int v10; // ebx
  int v11; // ecx
  int v12; // eax
  const void *v13; // edx
  int v14; // eax
  _DWORD *v15; // eax
  int *v16; // ebx
  int v17; // edi
  int v18; // eax
  int v19; // [esp+0h] [ebp-30h]
  unsigned int v20; // [esp+10h] [ebp-20h]
  int *v21; // [esp+14h] [ebp-1Ch]
  unsigned int v22; // [esp+18h] [ebp-18h]
  unsigned int v23; // [esp+1Ch] [ebp-14h]
  int *v24; // [esp+20h] [ebp-10h]
  int v25; // [esp+2Ch] [ebp-4h]

  v24 = &v19;
  v4 = this;
  v21 = this;
  v5 = this[1];
  v6 = a2;
  v23 = v5;
  if ( a2 >= v5 )
  {
    if ( -1 - a2 >= a4 )
    {
      v22 = a2 + a4;
      if ( !sub_1029B80(this, a2 + a4, -1) )
        ATL::AtlThrowImpl(-2147024882);
      goto LABEL_16;
    }
LABEL_5:
    ATL::AtlThrowImpl(-2147024362);
  }
  v20 = v5;
  if ( -1 - v5 < a4 )
    goto LABEL_5;
  if ( !sub_1029B80(this, v5 + a4, -1) )
    ATL::AtlThrowImpl(-2147024882);
  v7 = *v4 + 4 * v5;
  v8 = 0;
  v22 = v7;
  v9 = a4;
  if ( a4 )
  {
    v10 = v22;
    do
    {
      v11 = *(v10 + 4 * v8);
      if ( v11 )
      {
        (*(*v11 + 8))(*(v10 + 4 * v8));
        v9 = a4;
      }
      ++v8;
    }
    while ( v8 < v9 );
    v4 = v21;
  }
  v12 = *v4;
  v13 = (*v4 + 4 * a2);
  v23 -= a2;
  v22 = a2 + a4;
  v14 = memmove_s((v12 + 4 * (a2 + a4)), 4 * v23, v13, 4 * v23);
  sub_100B650(v14);
  v15 = (4 * a2 + *v4);
  v25 = 0;
  sub_10279A0(v15, a4);
  v25 = -1;
LABEL_16:
  if ( a2 < v22 )
  {
    do
    {
      v16 = (*v4 + 4 * v6);
      v17 = *a3;
      if ( *v16 != *a3 )
      {
        if ( v17 )
          (*(*v17 + 4))(*a3);
        v18 = *v16;
        *v16 = v17;
        if ( v18 )
          (*(*v18 + 8))(v18);
      }
      v4 = v21;
      ++v6;
    }
    while ( v6 < v22 );
  }
}

//----- (01028C80) --------------------------------------------------------
int (__stdcall ***__stdcall sub_1028C80(int (__stdcall ***a1)(_DWORD, GUID *, int *)))(_DWORD, GUID *, int *)
{
  _DWORD *v1; // ecx
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int (__stdcall ***v5)(_DWORD, GUID *, int *); // esi
  _DWORD *v7; // [esp+8h] [ebp-10h]
  int v8; // [esp+14h] [ebp-4h]

  v1 = 0;
  v7 = 0;
  if ( a1 )
  {
    v2 = (**a1)(a1, &stru_109FBC8, &v7);
    v1 = v7;
    if ( v2 < 0 )
      v1 = 0;
    v7 = v1;
  }
  v3 = *v1;
  v8 = 0;
  v4 = (*(v3 + 44))(v1, &a1);
  v5 = a1;
  v8 = -1;
  if ( v4 )
    v5 = 0;
  if ( v7 )
    (*(*v7 + 8))(v7);
  return v5;
}
// 109FBC8: using guessed type GUID stru_109FBC8;

//----- (01028D10) --------------------------------------------------------
signed int __thiscall sub_1028D10(_DWORD *this, int a2)
{
  int v2; // ST08_4
  int v3; // esi
  signed int v4; // esi
  int v6; // [esp+8h] [ebp-18h]
  int v7; // [esp+Ch] [ebp-14h]
  int v8; // [esp+10h] [ebp-10h]
  int v9; // [esp+1Ch] [ebp-4h]

  v8 = 0;
  v2 = this[7];
  v9 = 0;
  if ( !(*(*v2 + 28))(v2, &v8) )
  {
    v7 = 0;
    if ( !(*(*v8 + 28))(v8, 1, &v6, &v7) )
    {
      v3 = a2;
      do
      {
        a2 = 0;
        if ( (*(*v6 + 16))(v6, &a2) )
          break;
        if ( a2 == v3 )
        {
          v4 = 1;
          goto LABEL_8;
        }
      }
      while ( !(*(*v8 + 28))(v8, 1, &v6, &v7) );
    }
  }
  v4 = 0;
LABEL_8:
  v9 = -1;
  if ( v8 )
    (*(*v8 + 8))(v8);
  return v4;
}

//----- (01028DE0) --------------------------------------------------------
BOOL __cdecl sub_1028DE0(int a1)
{
  return !(*(*a1 + 44))(a1, &a1) && (a1 == 6 || a1 == 7 || a1 == 8 || a1 == 9 || a1 == 10);
}

//----- (01028E20) --------------------------------------------------------
int __thiscall sub_1028E20(void *this, int a2, int a3, int *a4, _DWORD *a5, _DWORD *a6, int a7, unsigned int a8, unsigned int *a9)
{
  int v9; // edx
  bool v10; // zf
  int (__stdcall ***v11)(_DWORD, GUID *, int *); // eax
  int v12; // eax
  int v13; // esi
  unsigned int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // esi
  int v19; // eax
  unsigned int v20; // eax
  int v21; // ecx
  int v22; // eax
  unsigned int v23; // edi
  unsigned int v24; // ebx
  int v25; // eax
  int v26; // [esp+10h] [ebp-5E4h]
  __int64 v27; // [esp+14h] [ebp-5E0h]
  __int64 v28; // [esp+1Ch] [ebp-5D8h]
  int v29; // [esp+24h] [ebp-5D0h]
  int *v30; // [esp+28h] [ebp-5CCh]
  __int64 v31; // [esp+2Ch] [ebp-5C8h]
  int *v32; // [esp+34h] [ebp-5C0h]
  _DWORD *v33; // [esp+38h] [ebp-5BCh]
  _DWORD *v34; // [esp+3Ch] [ebp-5B8h]
  int (__stdcall ***v35)(_DWORD, GUID *, int *); // [esp+40h] [ebp-5B4h]
  void *v36; // [esp+44h] [ebp-5B0h]
  int v37; // [esp+48h] [ebp-5ACh]
  int v38; // [esp+4Ch] [ebp-5A8h]
  int v39; // [esp+318h] [ebp-2DCh]
  unsigned int v40; // [esp+3DCh] [ebp-218h]
  int v41; // [esp+5F0h] [ebp-4h]

  v36 = this;
  v9 = a3;
  v10 = *a5 == 1;
  HIDWORD(v28) = a2;
  v30 = a4;
  v37 = a3;
  v29 = a7;
  if ( v10 )
    return 0;
  v10 = *a6 == 1;
  v31 = 0i64;
  if ( !v10 )
  {
    *a6 = 1;
    HIDWORD(v31) = 1;
    goto LABEL_29;
  }
  if ( *v30 )
  {
    if ( sub_1027DD0(*v30) == 1 )
    {
      if ( *a9 < a8 )
        ++*a9;
      v11 = sub_1028C80(*v30);
      v9 = v37;
      if ( v11 == 5 )
        LODWORD(v31) = 1;
      goto LABEL_29;
    }
    v9 = v37;
  }
  v12 = (*(*v9 + 20))(v9);
  if ( v12 == 1250084 )
  {
    *a5 = 1;
    goto LABEL_12;
  }
  if ( v12 < 0 )
    _CxxThrowException(0, 0);
  v9 = v37;
LABEL_29:
  if ( *a5 )
  {
LABEL_12:
    if ( *a9 < a8 )
    {
      v13 = v29;
      while ( 1 )
      {
        v34 = 0;
        v14 = *a9;
        v41 = 8;
        v10 = (***(v13 + 4 * v14))(*(v13 + 4 * v14), &stru_109FBC8, &v34) == 0;
        v15 = v34;
        if ( !v10 )
          break;
        if ( (*(*v34 + 44))(v34, &v31 + 4)
          || HIDWORD(v31) != 6 && HIDWORD(v31) != 7 && HIDWORD(v31) != 8 && HIDWORD(v31) != 9 && HIDWORD(v31) != 10 )
        {
          *v30 = *(v13 + 4 * *a9);
          v25 = v34;
          goto LABEL_95;
        }
        v41 = -1;
        if ( v34 )
          (*(*v34 + 8))(v34);
        if ( ++*a9 >= a8 )
          return 0;
      }
LABEL_45:
      v41 = -1;
      if ( v15 )
        (*(*v15 + 8))(v15);
    }
    return 0;
  }
  v33 = 0;
  v16 = *v9;
  v41 = 0;
  (*(v16 + 24))(v9, &v33);
  v17 = v33;
  if ( !v33 )
  {
    *v30 = v33;
    return v17 + 1;
  }
  v19 = *v33;
  v34 = v33;
  (*(v19 + 4))(v33);
  if ( *a9 >= a8 )
    goto LABEL_92;
  while ( 1 )
  {
    v35 = 0;
    v20 = *a9;
    LOBYTE(v41) = 2;
    if ( (***(v29 + 4 * v20))(*(v29 + 4 * v20), &stru_109FBC8, &v35) )
      goto LABEL_42;
    if ( !sub_1028DE0(v35) )
      break;
    LOBYTE(v41) = 1;
    if ( v35 )
      ((*v35)[2])(v35);
    if ( ++*a9 >= a8 )
      goto LABEL_92;
  }
  sub_1027520(&v32, v35);
  v21 = *v32;
  LOBYTE(v41) = 3;
  if ( (*(v21 + 16))(v32, v17, &v26) )
  {
LABEL_40:
    LOBYTE(v41) = 2;
    if ( v32 )
      (*(*v32 + 8))(v32);
LABEL_42:
    LOBYTE(v41) = 1;
    if ( v35 )
      ((*v35)[2])(v35);
    v22 = *v17;
    LOBYTE(v41) = 0;
    (*(v22 + 8))(v17);
    v15 = v33;
    goto LABEL_45;
  }
  if ( !v26 )
  {
    if ( sub_1028C80(v35) != 1 )
      goto LABEL_88;
    memset(&v38, 0, 0x2CCu);
    v38 = 65539;
    if ( (*(*v37 + 12))(v37, 65539, 716, &v29, &v38) )
      goto LABEL_40;
    v37 = 0;
    LOBYTE(v41) = 4;
    if ( (*(*HIDWORD(v28) + 12))(HIDWORD(v28), &v37) )
    {
LABEL_54:
      LOBYTE(v41) = 3;
      if ( v37 )
        (*(*v37 + 8))(v37);
      goto LABEL_40;
    }
    if ( v31 == 1 || HIDWORD(v31) == 1 )
      (*(*v37 + 16))(v37, 1, 716, &v38);
    else
      (*(*v37 + 16))(v37, 2, 716, &v38);
    v36 = 0;
    v28 = 0i64;
    v27 = 0i64;
    LOBYTE(v41) = 5;
    if ( (*(*v37 + 24))(v37, &v36) )
    {
      v31 = __PAIR__(v28, HIDWORD(v28));
    }
    else
    {
      memset(&v39, 0, 0x2CCu);
      v39 = 65539;
      if ( (*(*v37 + 12))(v37, 65539, 716, &v28 + 4, &v39) )
        goto LABEL_62;
      HIDWORD(v31) = v40;
      LODWORD(v31) = 0;
    }
    LOBYTE(v41) = 4;
    if ( v36 )
      (*(*v36 + 8))(v36);
    if ( (*(*v37 + 20))(v37) )
    {
      v24 = HIDWORD(v27);
      v23 = v27;
    }
    else
    {
      v36 = 0;
      LOBYTE(v41) = 6;
      if ( (*(*v37 + 24))(v37, &v36) )
      {
        v24 = HIDWORD(v27);
        v23 = v27;
      }
      else
      {
        memset(&v39, 0, 0x2CCu);
        v39 = 65539;
        if ( (*(*v37 + 12))(v37, 65539, 716, &v28 + 4, &v39) )
          goto LABEL_62;
        v23 = v40;
        v24 = 0;
      }
      LOBYTE(v41) = 4;
      if ( v36 )
        (*(*v36 + 8))(v36);
    }
    if ( !v31 || !(v24 | v23) || v31 > v24 || v31 >= v24 && HIDWORD(v31) >= v23 )
    {
LABEL_86:
      LOBYTE(v41) = 3;
      if ( v37 )
        (*(*v37 + 8))(v37);
      goto LABEL_88;
    }
    v36 = 0;
    LOBYTE(v41) = 7;
    (*(*v37 + 24))(v37, &v36);
    if ( !(*(*v32 + 16))(v32, v36, &v28 + 4) )
    {
      if ( HIDWORD(v28) )
      {
        sub_1027600(&v34, v35);
        v17 = v34;
      }
      LOBYTE(v41) = 4;
      if ( v36 )
        (*(*v36 + 8))(v36);
      goto LABEL_86;
    }
LABEL_62:
    LOBYTE(v41) = 4;
    if ( v36 )
      (*(*v36 + 8))(v36);
    goto LABEL_54;
  }
  sub_1027600(&v34, *(v29 + 4 * *a9));
  v17 = v34;
LABEL_88:
  LOBYTE(v41) = 2;
  if ( v32 )
    (*(*v32 + 8))(v32);
  LOBYTE(v41) = 1;
  if ( v35 )
    ((*v35)[2])(v35);
LABEL_92:
  LOBYTE(v41) = 0;
  *v30 = v17;
  if ( v17 )
    (*(*v17 + 8))(v17);
  v25 = v33;
LABEL_95:
  v41 = -1;
  if ( v25 )
    (*(*v25 + 8))(v25);
  return 1;
}
// 10681AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);
// 109FBC8: using guessed type GUID stru_109FBC8;

//----- (01029500) --------------------------------------------------------
signed int __thiscall sub_1029500(_DWORD *this, int a2, int a3, int a4)
{
  _DWORD *v4; // edi
  DWORD v5; // ST24_4
  HANDLE v6; // esi
  char v8; // [esp+14h] [ebp-45Ch]
  int v9; // [esp+18h] [ebp-458h]
  int v10; // [esp+1Ch] [ebp-454h]
  MODULEENTRY32W me; // [esp+20h] [ebp-450h]
  __int16 v12; // [esp+448h] [ebp-28h]
  __int16 v13; // [esp+454h] [ebp-1Ch]
  int v14; // [esp+456h] [ebp-1Ah]
  int v15; // [esp+45Ah] [ebp-16h]
  int v16; // [esp+46Ch] [ebp-4h]

  v4 = this;
  v9 = a2;
  v10 = a4;
  v14 = 4;
  v15 = -1;
  v13 = 0;
  v5 = this[2];
  v16 = 0;
  v12 = 0;
  v6 = CreateToolhelp32Snapshot(8u, v5);
  if ( v6 == -1 )
    return -2147467259;
  me.dwSize = 1064;
  if ( !Module32FirstW(v6, &me) )
  {
LABEL_6:
    CloseHandle(v6);
    return -2147467259;
  }
  while ( me.th32ProcessID != v4[2]
       || (*(*a3 + 12))(a3, me.modBaseAddr, me.modBaseAddr >> 31, v9, v10, &v13, &stru_109FBA8, v4 + 7, &v12, &v8) )
  {
    if ( !Module32NextW(v6, &me) )
      goto LABEL_6;
  }
  CloseHandle(v6);
  return 0;
}
// 109FBA8: using guessed type GUID stru_109FBA8;

//----- (01029620) --------------------------------------------------------
signed int __stdcall sub_1029620(int a1, int a2, int a3, int a4, HMODULE *a5)
{
  signed int v5; // edi
  HANDLE v6; // ebx
  int v7; // eax
  int v8; // edi
  int v9; // eax
  HMODULE v11; // eax
  MODULEENTRY32W me; // [esp+10h] [ebp-638h]
  WCHAR LibFileName; // [esp+438h] [ebp-210h]

  v5 = 0;
  v6 = CreateToolhelp32Snapshot(8u, *(a1 + 8));
  if ( v6 != -1 )
  {
    me.dwSize = 1064;
    if ( Module32FirstW(v6, &me) )
    {
      while ( 1 )
      {
        if ( me.th32ProcessID == *(a1 + 8) )
        {
          v7 = wcscmp(L"clr.dll", me.szModule);
          if ( v7 )
            v7 = -(v7 < 0) | 1;
          if ( !v7 )
            break;
        }
        if ( !Module32NextW(v6, &me) )
          goto LABEL_11;
      }
      v8 = lstrlenW(me.szExePath);
      v9 = lstrlenW(me.szModule);
      sub_102A440(&LibFileName, 0x105u, me.szExePath, v8 - v9);
      v5 = 1;
LABEL_11:
      CloseHandle(v6);
      if ( !v5 )
        return -2147467259;
      sub_102A3A0(&LibFileName, 0x105u, a2);
      v11 = LoadLibraryExW(&LibFileName, 0, 8u);
      if ( !v11 )
        return -2147467259;
      *a5 = v11;
    }
    else
    {
      CloseHandle(v6);
    }
  }
  return 0;
}

//----- (01029780) --------------------------------------------------------
signed int __stdcall sub_1029780(int a1, _DWORD *a2, _DWORD *a3)
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
      return 0;
    }
  }
  v9 = &stru_109F3FC;
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
      (*(*a1 + 4))(a1, v9, a1);
      return 0;
    }
  }
  return -2147467262;
}
// 109F3FC: using guessed type GUID stru_109F3FC;
// 10A7BBC: using guessed type GUID CLSID_IUnknown;

//----- (01029800) --------------------------------------------------------
signed int __stdcall sub_1029800(int a1, _DWORD *a2, _DWORD *a3)
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
      return 0;
    }
  }
  v9 = &stru_109FB98;
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
      (*(*a1 + 4))(a1, v9, a1);
      return 0;
    }
  }
  return -2147467262;
}
// 109FB98: using guessed type GUID stru_109FB98;
// 10A7BBC: using guessed type GUID CLSID_IUnknown;

//----- (01029880) --------------------------------------------------------
signed int __stdcall sub_1029880(int a1, _DWORD *a2, _DWORD *a3)
{
  _DWORD *v3; // ecx
  GUID *v4; // edx
  unsigned int v5; // esi
  bool v6; // cf

  v3 = a2;
  v4 = &CLSID_IUnknown;
  v5 = 12;
  while ( *v3 == v4->Data1 )
  {
    ++v3;
    v4 = (v4 + 4);
    v6 = v5 < 4;
    v5 -= 4;
    if ( v6 )
    {
      *a3 = a1;
      (*(*a1 + 4))(a1, v4, a1);
      return 0;
    }
  }
  return -2147467262;
}
// 10A7BBC: using guessed type GUID CLSID_IUnknown;

//----- (010298D0) --------------------------------------------------------
signed int __stdcall sub_10298D0(int a1, int a2, int a3)
{
  return -2147467262;
}

//----- (010298E0) --------------------------------------------------------
int __stdcall sub_10298E0(int a1, LPCVOID lpBaseAddress, int a3, LPVOID lpBuffer, SIZE_T nSize, SIZE_T *lpNumberOfBytesRead)
{
  return ReadProcessMemory(*(a1 + 8), lpBaseAddress, lpBuffer, nSize, lpNumberOfBytesRead) != 1 ? 0x80004005 : 0;
}

//----- (01029910) --------------------------------------------------------
int __stdcall sub_1029910(void *a1)
{
  bool v1; // zf

  v1 = (*(a1 + 1))-- == 1;
  if ( !v1 )
    return *(a1 + 1);
  j__free(a1);
  return 0;
}

//----- (01029940) --------------------------------------------------------
int __stdcall sub_1029940(_DWORD *a1)
{
  bool v1; // zf
  int result; // eax

  v1 = a1[1]-- == 1;
  result = a1[1];
  if ( v1 )
  {
    (*(*a1 + 12))(1);
    result = 0;
  }
  return result;
}

//----- (01029960) --------------------------------------------------------
int __stdcall sub_1029960(void *a1)
{
  bool v1; // zf
  void *v2; // eax

  v1 = (*(a1 + 1))-- == 1;
  if ( !v1 )
    return *(a1 + 1);
  v2 = *(a1 + 6);
  *a1 = &NativeFrame::`vftable';
  if ( v2 )
  {
    j__free(v2);
    *(a1 + 6) = 0;
  }
  j__free(a1);
  return 0;
}
// 109F430: using guessed type void *NativeFrame::`vftable';

//----- (010299B0) --------------------------------------------------------
int __stdcall sub_10299B0(void *a1)
{
  bool v1; // zf
  void *v2; // eax

  v1 = (*(a1 + 1))-- == 1;
  if ( !v1 )
    return *(a1 + 1);
  v2 = *(a1 + 7);
  *a1 = &SymbolInfo::`vftable';
  if ( v2 )
  {
    j__free(v2);
    *(a1 + 7) = 0;
  }
  j__free(a1);
  return 0;
}
// 109F420: using guessed type void *SymbolInfo::`vftable';

//----- (01029A00) --------------------------------------------------------
int __cdecl sub_1029A00(void *Dst, void *Src, int a3)
{
  int v3; // eax

  v3 = memmove_s(Dst, 4 * a3, Src, 4 * a3);
  return sub_100B650(v3);
}

//----- (01029A30) --------------------------------------------------------
_DWORD *__thiscall sub_1029A30(_DWORD *this)
{
  _DWORD *v1; // esi
  _DWORD *v2; // edi
  int v3; // ecx
  bool v4; // zf
  _DWORD *result; // eax
  _DWORD *v6; // edi

  v1 = this;
  while ( v1[2] )
  {
    v2 = *v1;
    if ( !*v1 )
      ATL::AtlThrowImpl(-2147467259);
    *v1 = *v2;
    v3 = v2[2];
    if ( v3 )
      (*(*v3 + 8))(v2[2]);
    *v2 = v1[4];
    v4 = v1[2]-- == 1;
    v1[4] = v2;
    if ( v4 )
      sub_1029A30(v1);
  }
  result = v1[3];
  *v1 = 0;
  v1[1] = 0;
  v1[4] = 0;
  if ( result )
  {
    do
    {
      v6 = *result;
      free(result);
      result = v6;
    }
    while ( v6 );
    v1[3] = 0;
  }
  return result;
}

//----- (01029AC0) --------------------------------------------------------
_DWORD *__thiscall sub_1029AC0(int *this, _DWORD *a2)
{
  int *v2; // esi
  int *v3; // edi
  int v4; // ecx
  int v5; // eax
  int v6; // ecx
  bool v7; // zf

  v2 = this;
  v3 = *this;
  if ( !*this )
    ATL::AtlThrowImpl(-2147467259);
  v4 = v3[2];
  *a2 = v4;
  if ( v4 )
    (*(*v4 + 4))(v4);
  v5 = *v3;
  *v2 = *v3;
  if ( v5 )
    *(v5 + 4) = 0;
  else
    v2[1] = 0;
  v6 = v3[2];
  if ( v6 )
    (*(*v6 + 8))(v3[2]);
  *v3 = v2[4];
  v7 = v2[2]-- == 1;
  v2[4] = v3;
  if ( v7 )
    sub_1029A30(v2);
  return a2;
}

//----- (01029B40) --------------------------------------------------------
int __stdcall sub_1029B40(DWORD dwThreadId)
{
  HANDLE v1; // eax
  void *v2; // esi

  v1 = OpenThread(0x1F03FFu, 1, dwThreadId);
  v2 = v1;
  if ( !v1 )
    return -2147467259;
  ResumeThread(v1);
  CloseHandle(v2);
  return 0;
}

//----- (01029B80) --------------------------------------------------------
char __thiscall sub_1029B80(int this, unsigned int a2, int a3)
{
  int v3; // esi
  unsigned int v4; // edi
  int v5; // ebx
  unsigned int v6; // eax
  int v7; // ecx
  char result; // al
  unsigned int v9; // ecx
  unsigned int v10; // [esp+14h] [ebp+Ch]

  v3 = this;
  if ( a3 != -1 )
    *(this + 12) = a3;
  v4 = a2;
  if ( a2 )
  {
    if ( a2 > *(this + 8) )
    {
      result = sub_10288A0(this, a2);
      if ( !result )
        return result;
      v9 = *(v3 + 4);
    }
    else
    {
      v9 = *(this + 4);
      if ( v9 >= a2 )
      {
        if ( v9 > a2 )
        {
          sub_10279D0(*v3 + 4 * a2, v9 - a2);
          *(v3 + 4) = a2;
          return 1;
        }
        goto LABEL_18;
      }
    }
    sub_10279A0((*v3 + 4 * v9), a2 - v9);
LABEL_18:
    *(v3 + 4) = a2;
    return 1;
  }
  v5 = *this;
  if ( *this )
  {
    v6 = *(this + 4);
    v10 = v6;
    if ( v6 )
    {
      do
      {
        v7 = *(v5 + 4 * v4);
        if ( v7 )
        {
          (*(*v7 + 8))(*(v5 + 4 * v4));
          v6 = v10;
        }
        ++v4;
      }
      while ( v4 < v6 );
    }
    free(*v3);
    *v3 = 0;
  }
  *(v3 + 4) = 0;
  result = 1;
  *(v3 + 8) = 0;
  return result;
}

//----- (01029C50) --------------------------------------------------------
int __thiscall sub_1029C50(_DWORD *this, int a2, int a3, int a4)
{
  int *v4; // edi
  int v5; // ebx
  int result; // eax
  int *v7; // ecx
  void *v8; // esi
  int *v9; // eax
  int *v10; // edi
  unsigned int v11; // eax
  _DWORD *v12; // eax
  _DWORD *v13; // edi
  _DWORD *v14; // esi
  int v15; // ecx
  wchar_t *v16; // ST00_4
  unsigned int v17; // eax
  _DWORD *v18; // eax
  int v19; // eax
  int v20; // eax
  int *v21; // ecx
  void *v22; // esi
  bool v23; // zf
  int v24; // edi
  int (__stdcall **v25)(void *, GUID *, int *); // eax
  _DWORD *v26; // eax
  _DWORD *v27; // ebx
  _DWORD *v28; // ecx
  void *v29; // eax
  _DWORD *v30; // eax
  int *v31; // eax
  void *v32; // ecx
  void *v33; // eax
  _DWORD *v34; // eax
  _DWORD *v35; // ebx
  int v36; // ecx
  wchar_t *v37; // ST00_4
  void *v38; // eax
  _DWORD *v39; // eax
  int v40; // ecx
  int v41; // ecx
  int v42; // eax
  int *v43; // ecx
  int (__stdcall ***v44)(_DWORD, GUID *, int *); // edi
  _DWORD *v45; // eax
  void *v46; // eax
  int v47; // ecx
  _DWORD *v48; // eax
  void *v49; // eax
  int v50; // ecx
  unsigned __int64 v51; // [esp+10h] [ebp-103Ch]
  void *v52; // [esp+18h] [ebp-1034h]
  int (__stdcall ***v53)(_DWORD, GUID *, int *); // [esp+1Ch] [ebp-1030h]
  int *v54; // [esp+20h] [ebp-102Ch]
  _DWORD *v55; // [esp+24h] [ebp-1028h]
  int *v56; // [esp+28h] [ebp-1024h]
  void *v57; // [esp+2Ch] [ebp-1020h]
  void *v58; // [esp+30h] [ebp-101Ch]
  int v59; // [esp+34h] [ebp-1018h]
  int v60; // [esp+38h] [ebp-1014h]
  wchar_t v61; // [esp+3Ch] [ebp-1010h]
  wchar_t Dst; // [esp+83Ch] [ebp-810h]
  int v63; // [esp+1048h] [ebp-4h]

  v55 = this;
  v4 = a3;
  v5 = a4;
  v54 = a3;
  result = *(a3 + 8);
  v59 = a4;
  if ( !result )
  {
    if ( *(a2 + 8) )
    {
      if ( *(a2 + 8) > 0u )
      {
        v7 = *a2;
        if ( *a2 )
        {
          while ( v7 )
          {
            v8 = v7[2];
            v60 = *v7;
            v57 = v8;
            if ( v8 )
              (*(*v8 + 4))(v8);
            v63 = 0;
            v54 = 0;
            v9 = operator new(0x20u);
            v10 = v9;
            v52 = v9;
            LOBYTE(v63) = 2;
            if ( v9 )
            {
              *v9 = &SymbolInfo::`vftable';
              v9[1] = 1;
              v9[7] = operator new[](0x800u);
            }
            else
            {
              v10 = 0;
            }
            LOBYTE(v63) = 1;
            v54 = v10;
            result = sub_10280C0(v8, v10);
            if ( result )
            {
              v11 = *(a4 + 4);
              v59 = v11;
              if ( v11 >= *(a4 + 8) && !sub_10288A0(a4, v11 + 1) )
                goto LABEL_24;
              result = *a4 + 4 * v59;
              if ( result )
              {
                *result = v10;
                if ( v10 )
                  result = (*(*v10 + 4))(v10);
              }
              ++*(a4 + 4);
            }
            LOBYTE(v63) = 0;
            if ( v10 )
              result = (*(*v10 + 8))(v10);
            v63 = -1;
            if ( v8 )
              result = (*(*v8 + 8))(v8);
            v7 = v60;
            if ( !v60 )
              return result;
          }
          goto LABEL_41;
        }
      }
    }
    return result;
  }
  if ( !*(a2 + 8) )
  {
    while ( 1 )
    {
      sub_1029AC0(v4, &v59);
      v63 = 3;
      v55 = 0;
      LOBYTE(v63) = 4;
      v12 = operator new(0x20u);
      v13 = v12;
      v57 = v12;
      LOBYTE(v63) = 5;
      if ( v12 )
      {
        *v12 = &SymbolInfo::`vftable';
        v12[1] = 1;
        v12[7] = operator new[](0x800u);
      }
      else
      {
        v13 = 0;
      }
      v14 = v59;
      LOBYTE(v63) = 4;
      v55 = v13;
      if ( v59 )
        (*(*v59 + 4))(v59);
      swprintf_s(&Dst, 0x400u, L"%s", v14[6]);
      v15 = v14[3];
      v13[4] = v14[2];
      v16 = v13[7];
      v13[5] = v15;
      swprintf_s(v16, 0x400u, L"%s", &Dst);
      v13[6] = 3;
      (*(*v14 + 8))(v14);
      v17 = *(a4 + 4);
      v60 = v17;
      if ( v17 >= *(a4 + 8) && !sub_10288A0(a4, v17 + 1) )
        break;
      v18 = (*a4 + 4 * v60);
      if ( v18 )
      {
        *v18 = v13;
        (*(*v13 + 4))(v13);
      }
      ++*(a4 + 4);
      v19 = *v13;
      LOBYTE(v63) = 3;
      (*(v19 + 8))(v13);
      v20 = *v14;
      v63 = -1;
      result = (*(v20 + 8))(v14);
      v4 = v54;
      if ( !v54[2] )
        return result;
    }
    goto LABEL_24;
  }
  if ( !result || !*(a2 + 8) )
    return result;
  v21 = *a2;
  v56 = v21;
  result = v21 != 0;
  if ( !v21 )
    goto LABEL_41;
  v22 = v21[2];
  v52 = v22;
  if ( v22 )
    result = (*(*v22 + 4))(v22);
  v23 = *(a3 + 8) == 0;
  v63 = 6;
  if ( !v23 )
  {
    while ( 1 )
    {
      sub_1029AC0(v4, &v53);
      v24 = v53;
      while ( 1 )
      {
        v60 = 0;
        v25 = *v22;
        LOBYTE(v63) = 8;
        if ( (*v25)(v22, &stru_109FC40, &v60) )
          break;
        (*(*v60 + 12))(v60, &v51);
        LOBYTE(v63) = 7;
        if ( v60 )
          (*(*v60 + 8))(v60);
        if ( !v56 || v51 >= *(v24 + 8) )
          goto LABEL_71;
        v60 = 0;
        LOBYTE(v63) = 9;
        v26 = operator new(0x20u);
        v27 = v26;
        v57 = v26;
        LOBYTE(v63) = 10;
        if ( v26 )
        {
          *v26 = &SymbolInfo::`vftable';
          v26[1] = 1;
          v26[7] = operator new[](0x800u);
        }
        else
        {
          v27 = 0;
        }
        LOBYTE(v63) = 9;
        v60 = v27;
        if ( sub_10280C0(v22, v27) )
        {
          v28 = v59;
          v29 = *(v59 + 4);
          v58 = v29;
          if ( v29 >= *(v59 + 8) )
          {
            if ( !sub_10288A0(v59, v29 + 1) )
              goto LABEL_24;
            v28 = v59;
          }
          v30 = (*v28 + 4 * v58);
          if ( v30 )
          {
            *v30 = v27;
            if ( v27 )
            {
              (*(*v27 + 4))(v27);
              v28 = v59;
            }
          }
          ++v28[1];
        }
        v31 = v56;
        v56 = *v56;
        v32 = v31[2];
        v58 = v32;
        if ( v22 != v32 )
        {
          if ( v32 )
          {
            (*(*v32 + 4))(v32);
            v32 = v58;
          }
          v33 = v22;
          v22 = v32;
          v52 = v32;
          if ( v33 )
            (*(*v33 + 8))(v33);
        }
        LOBYTE(v63) = 7;
        if ( v27 )
          (*(*v27 + 8))(v27);
      }
      LOBYTE(v63) = 7;
      if ( v60 )
        (*(*v60 + 8))(v60);
LABEL_71:
      v58 = 0;
      LOBYTE(v63) = 11;
      v34 = operator new(0x20u);
      v35 = v34;
      v60 = v34;
      v57 = v34;
      LOBYTE(v63) = 12;
      if ( v34 )
      {
        *v34 = &SymbolInfo::`vftable';
        v34[1] = 1;
        v34[7] = operator new[](0x800u);
      }
      else
      {
        v35 = 0;
        v60 = 0;
      }
      LOBYTE(v63) = 11;
      v58 = v35;
      if ( v24 )
        (*(*v24 + 4))(v24);
      swprintf_s(&v61, 0x400u, L"%s", *(v24 + 24));
      v36 = *(v24 + 12);
      v35[4] = *(v24 + 8);
      v37 = v35[7];
      v35[5] = v36;
      swprintf_s(v37, 0x400u, L"%s", &v61);
      v35[6] = 3;
      (*(*v24 + 8))(v24);
      v5 = v59;
      v38 = *(v59 + 4);
      v57 = v38;
      if ( v38 >= *(v59 + 8) && !sub_10288A0(v59, v38 + 1) )
        break;
      v39 = (*v5 + 4 * v57);
      if ( v39 )
      {
        v40 = v60;
        *v39 = v60;
        (*(*v40 + 4))(v40);
      }
      v41 = v60;
      ++*(v5 + 4);
      LOBYTE(v63) = 7;
      (*(*v41 + 8))(v41);
      v42 = *v24;
      LOBYTE(v63) = 6;
      result = (*(v42 + 8))(v24);
      v4 = v54;
      if ( !v54[2] )
        goto LABEL_81;
    }
LABEL_24:
    ATL::AtlThrowImpl(-2147024882);
  }
LABEL_81:
  v43 = v56;
  if ( v56 )
  {
    while ( v43 )
    {
      v44 = v43[2];
      v56 = *v43;
      v53 = v44;
      if ( v44 )
        ((*v44)[1])(v44);
      v57 = 0;
      LOBYTE(v63) = 14;
      v45 = operator new(0x20u);
      v60 = v45;
      v58 = v45;
      LOBYTE(v63) = 15;
      if ( v45 )
      {
        *v45 = &SymbolInfo::`vftable';
        v45[1] = 1;
        v46 = operator new[](0x800u);
        v47 = v60;
        *(v60 + 28) = v46;
        v48 = v47;
      }
      else
      {
        v48 = 0;
        v60 = 0;
      }
      LOBYTE(v63) = 14;
      v57 = v48;
      result = sub_10280C0(v44, v48);
      if ( result )
      {
        v49 = *(v5 + 4);
        v58 = v49;
        if ( v49 >= *(v5 + 8) && !sub_10288A0(v5, v49 + 1) )
          goto LABEL_24;
        result = *v5 + 4 * v58;
        if ( result )
        {
          v50 = v60;
          *result = v60;
          if ( v50 )
            result = (*(*v50 + 4))(v50);
        }
        ++*(v5 + 4);
      }
      LOBYTE(v63) = 13;
      if ( v60 )
        result = (*(*v60 + 8))(v60);
      LOBYTE(v63) = 6;
      if ( v44 )
        result = ((*v44)[2])(v44);
      v43 = v56;
      if ( !v56 )
        goto LABEL_100;
    }
LABEL_41:
    ATL::AtlThrowImpl(-2147467259);
  }
LABEL_100:
  v63 = -1;
  if ( v22 )
    result = (*(*v22 + 8))(v22);
  return result;
}
// 109F420: using guessed type void *SymbolInfo::`vftable';
// 109FC40: using guessed type GUID stru_109FC40;

//----- (0102A3A0) --------------------------------------------------------
signed int __stdcall sub_102A3A0(_WORD *a1, unsigned int a2, int a3)
{
  signed int result; // eax
  _WORD *v4; // eax
  unsigned int v5; // edx
  signed int v6; // ecx
  int v7; // edi
  __int16 v8; // si
  int v9; // [esp+8h] [ebp-4h]

  result = sub_102A500(a1, a2, &v9, 0x7FFFFFFFu);
  if ( result >= 0 )
  {
    v4 = &a1[v9];
    v5 = a2 - v9;
    if ( a2 == v9 )
      goto LABEL_13;
    v6 = 0x7FFFFFFF;
    v7 = a3 - v4;
    while ( v6 )
    {
      v8 = *(v4 + v7);
      if ( !v8 )
        break;
      *v4 = v8;
      --v6;
      ++v4;
      if ( !--v5 )
      {
        *(v4 - 1) = 0;
        return -2147024774;
      }
    }
    if ( v5 )
    {
      *v4 = 0;
      result = 0;
    }
    else
    {
LABEL_13:
      *(v4 - 1) = 0;
      result = -2147024774;
    }
  }
  return result;
}

//----- (0102A440) --------------------------------------------------------
signed int __stdcall sub_102A440(_WORD *a1, unsigned int a2, int a3, unsigned int a4)
{
  signed int result; // eax

  result = 0;
  if ( !a2 || a2 > 0x7FFFFFFF )
    result = -2147024809;
  if ( result >= 0 )
  {
    if ( a4 <= 0x7FFFFFFE )
    {
      result = sub_102A490(a1, a2, 0, a3, a4);
    }
    else
    {
      *a1 = 0;
      result = -2147024809;
    }
  }
  return result;
}

//----- (0102A490) --------------------------------------------------------
signed int __stdcall sub_102A490(_WORD *a1, int a2, _DWORD *a3, int a4, int a5)
{
  int v5; // ecx
  int v6; // edx
  _WORD *v7; // eax
  int v8; // esi
  __int16 v9; // di
  signed int v10; // edi

  v5 = a2;
  v6 = 0;
  v7 = a1;
  if ( !a2 )
    goto LABEL_15;
  v8 = a5;
  while ( v8 )
  {
    v9 = *(v7 + a4 - a1);
    if ( !v9 )
      break;
    *v7 = v9;
    --v8;
    ++v7;
    ++v6;
    if ( !--v5 )
    {
      --v7;
      v10 = -2147024774;
      --v6;
      goto LABEL_10;
    }
  }
  if ( v5 )
  {
    v10 = 0;
  }
  else
  {
LABEL_15:
    --v7;
    v10 = -2147024774;
    --v6;
  }
LABEL_10:
  *v7 = 0;
  if ( a3 )
    *a3 = v6;
  return v10;
}

//----- (0102A500) --------------------------------------------------------
signed int __stdcall sub_102A500(_WORD *a1, unsigned int a2, _DWORD *a3, unsigned int a4)
{
  signed int result; // eax
  _WORD *v5; // eax
  unsigned int v6; // ecx
  signed int v7; // esi

  result = 0;
  if ( !a2 || a2 > a4 )
    result = -2147024809;
  if ( result < 0 )
  {
    *a3 = 0;
  }
  else
  {
    v5 = a1;
    v6 = a2;
    v7 = 0;
    if ( !a2 )
      goto LABEL_10;
    while ( *v5 )
    {
      ++v5;
      if ( !--v6 )
        goto LABEL_10;
    }
    if ( !v6 )
LABEL_10:
      v7 = -2147024809;
    if ( a3 )
    {
      if ( v7 >= 0 )
      {
        *a3 = a2 - v6;
        return v7;
      }
      *a3 = 0;
    }
    result = v7;
  }
  return result;
}

//----- (0102A570) --------------------------------------------------------
HANDLE __thiscall sub_102A570(void *this, DWORD dwThreadId, int a3, int a4, int a5, int a6, int a7)
{
  _DWORD *v7; // edi
  HANDLE result; // eax
  unsigned int v9; // ecx
  unsigned int v10; // eax
  signed int v11; // esi
  int v12; // eax
  _DWORD *v13; // eax
  int v14; // esi
  unsigned int v15; // kr00_4
  wchar_t *v16; // eax
  int *v17; // edi
  int v18; // eax
  int **v19; // eax
  int v20; // eax
  int v21; // [esp+0h] [ebp-3E0h]
  int *v22; // [esp+10h] [ebp-3D0h]
  int *v23; // [esp+14h] [ebp-3CCh]
  int v24; // [esp+18h] [ebp-3C8h]
  int v25; // [esp+1Ch] [ebp-3C4h]
  _DWORD *v26; // [esp+20h] [ebp-3C0h]
  int v27; // [esp+24h] [ebp-3BCh]
  int v28; // [esp+28h] [ebp-3B8h]
  HANDLE hThread; // [esp+2Ch] [ebp-3B4h]
  PVOID ContextRecord; // [esp+30h] [ebp-3B0h]
  struct _tagSTACKFRAME64 StackFrame; // [esp+34h] [ebp-3ACh]
  char v32; // [esp+13Ch] [ebp-2A4h]
  char v33; // [esp+170h] [ebp-270h]
  int *v34; // [esp+3D0h] [ebp-10h]
  int v35; // [esp+3DCh] [ebp-4h]

  v34 = &v21;
  v7 = this;
  v26 = this;
  ContextRecord = a3;
  result = OpenThread(0x1F03FFu, 1, dwThreadId);
  hThread = result;
  if ( result )
  {
    memset(&StackFrame, 0, 0x108u);
    v9 = *(a3 + 184);
    StackFrame.AddrStack.Offset = *(a3 + 196);
    v10 = *(a3 + 180);
    v11 = 0;
    StackFrame.AddrFrame.Offset = v10;
    StackFrame.AddrBStore.Offset = v10;
    StackFrame.AddrPC.Offset = v9;
    StackFrame.AddrPC.Mode = 3;
    StackFrame.AddrStack.Mode = 3;
    StackFrame.AddrFrame.Mode = 3;
    StackFrame.AddrBStore.Mode = 3;
    StackFrame.AddrReturn.Mode = 3;
    do
    {
      v35 = 0;
      if ( StackFrame.Virtual == 1 )
        v11 = 1;
      v12 = v7[5];
      v28 = v11;
      sub_103DD60(1, v9, &v32, v7[3], 0, 0, *(v12 + 20), *(v12 + 16));
      if ( v11 )
      {
        v25 = 0;
        LOBYTE(v35) = 1;
        v13 = operator new(0x20u);
        v14 = v13;
        if ( v13 )
        {
          *v13 = &NativeFrame::`vftable';
          v13[1] = 1;
          v13[6] = 0;
        }
        else
        {
          v14 = 0;
        }
        *(v14 + 8) = StackFrame.AddrFrame.Offset;
        v25 = v14;
        v15 = wcslen(&v33);
        v16 = operator new[](2 * (v15 + 1));
        *(v14 + 24) = v16;
        swprintf_s(v16, v15 + 1, L"%s", &v33);
        v27 = *(a7 + 4);
        sub_1027F70(a7);
        v17 = *(a7 + 16);
        v23 = v17;
        v22 = v17;
        v18 = *v17;
        v24 = *v17;
        LOBYTE(v35) = 2;
        if ( v17 )
        {
          v17[2] = v14;
          (*(*v14 + 4))(v14);
          v18 = v24;
        }
        *(a7 + 16) = v18;
        v17[1] = v27;
        *v17 = 0;
        ++*(a7 + 8);
        v19 = *(a7 + 4);
        if ( v19 )
          *v19 = v17;
        else
          *a7 = v17;
        *(a7 + 4) = v17;
        v20 = *v14;
        LOBYTE(v35) = 0;
        (*(v20 + 8))(v14);
        v11 = v28;
        v7 = v26;
      }
      if ( !StackWalk64(
              0x14Cu,
              v7[3],
              hThread,
              &StackFrame,
              ContextRecord,
              0,
              SymFunctionTableAccess64,
              SymGetModuleBase64,
              0) )
        break;
      v9 = StackFrame.AddrPC.Offset;
      v35 = -1;
      if ( !StackFrame.AddrPC.Offset )
        break;
    }
    while ( StackFrame.AddrFrame.Offset < __PAIR__(a6, a5) );
    result = HANDLE_FLAG_INHERIT;
  }
  return result;
}
// 109F430: using guessed type void *NativeFrame::`vftable';

//----- (0102A870) --------------------------------------------------------
char __cdecl sub_102A870(tagTREEVIEWLISTITEMPARAM *pItem, WPARAM wParam)
{
  char v2; // bl
  wchar_t *v3; // eax
  tagNetCclrInfo *v4; // esi
  PE_PerfInfo_Item *v5; // eax
  WPARAM v6; // edi
  int *v7; // eax
  _QWORD *v8; // eax
  HWND v9; // ST10_4
  unsigned __int8 v10; // al
  char v11; // bl
  double v12; // xmm0_8
  HWND v13; // ST10_4
  bool v14; // al
  PE_PerfInfo_Item *v15; // eax
  int *v16; // eax
  _QWORD *v17; // eax
  HWND v18; // ST10_4
  unsigned __int8 v19; // al
  char v20; // bl
  _QWORD *v21; // eax
  HWND v22; // ST10_4
  unsigned __int8 v23; // al
  char v24; // bl
  _QWORD *v25; // eax
  HWND v26; // ST10_4
  unsigned __int8 v27; // al
  char v28; // bl
  _QWORD *v29; // eax
  HWND v30; // ST10_4
  unsigned __int8 v31; // al
  char v32; // bl
  _QWORD *v33; // eax
  HWND v34; // ST10_4
  unsigned __int8 v35; // al
  char v36; // bl
  _QWORD *v37; // eax
  HWND v38; // ST10_4
  unsigned __int8 v39; // al
  PE_PerfInfo_Item *v40; // eax
  int *v41; // eax
  _QWORD *v42; // eax
  HWND v43; // ST10_4
  unsigned __int8 v44; // al
  PE_PerfInfo_Item *v45; // eax
  int *v46; // eax
  _QWORD *v47; // eax
  HWND v48; // ST10_4
  unsigned __int8 v49; // al
  char v50; // bl
  _QWORD *v51; // eax
  HWND v52; // ST10_4
  unsigned __int8 v53; // al
  char v54; // bl
  _QWORD *v55; // eax
  HWND v56; // ST10_4
  unsigned __int8 v57; // al
  char v58; // bl
  _QWORD *v59; // eax
  HWND v60; // ST10_4
  unsigned __int8 v61; // al
  char v62; // bl
  int v63; // edi
  signed __int64 v64; // rax
  int v65; // ecx
  HWND v66; // ST10_4
  unsigned __int8 v67; // al
  char v68; // bl
  double v69; // xmm0_8
  HWND v70; // ST10_4
  bool v71; // al
  PE_PerfInfo_Item *v72; // eax
  int *v73; // eax
  _QWORD *v74; // eax
  HWND v75; // ST10_4
  unsigned __int8 v76; // al
  PE_PerfInfo PerfInfo; // [esp+2Ch] [ebp-250h]
  int v79[2]; // [esp+3Ch] [ebp-240h]
  int v80; // [esp+44h] [ebp-238h]
  unsigned int v81; // [esp+4Ch] [ebp-230h]
  tagNetCclrInfo *v82; // [esp+54h] [ebp-228h]
  int v83; // [esp+58h] [ebp-224h]
  void *v84[2]; // [esp+60h] [ebp-21Ch]
  void *v85; // [esp+68h] [ebp-214h]
  void *v86; // [esp+6Ch] [ebp-210h]
  WCHAR szBuffer[260]; // [esp+70h] [ebp-20Ch]

  v2 = 0;
  if ( !pItem->pNetCclrInfo )
    return 0;
  wcscpy_s(szBuffer, 0x104u, pItem->szProcessName2);
  v3 = wcsrchr(szBuffer, 0x2Eu);
  if ( v3 && v3 != szBuffer )
    *v3 = 0;
  v4 = pItem->pNetCclrInfo;
  v82 = pItem->pNetCclrInfo;
  szBuffer[14] = 0;
  unknown_libname_3(&PerfInfo, &gPerformanceInfoInMemory, &gPerformanceInfo);
  v5 = PE_PerfInfo::Load(&PerfInfo, L".NET CLR Jit");
  v6 = wParam;
  v85 = v5;
  if ( v5 )
  {
    v7 = sub_10286E0(szBuffer, v5);
    v86 = v7;
    if ( v7 )
    {
      v8 = sub_1027F10(v7, L"# of methods Jitted", &v83);
      v9 = ghWndTreeListView;
      v10 = sub_105F920(*v8, *v8 >> 32, v4);
      v11 = RedrawColumn(v10, v9, IDS_METHODS_JITTED, wParam);
      sub_1027F10(v86, L"% time in JIT", &v80);
      v84[1] = sub_102E840(v86);
      sub_102ECA0(v84[1], &v81, 0);
      v12 = 0.0;
      if ( v81 != 0.0 )
        v12 = v80 * 100.0 / v81;
      v13 = ghWndTreeListView;
      v14 = sub_105F8F0(v12, &v4->field_8);
      v2 = RedrawColumn(v14, v13, IDS_TIME_IN_JIT, wParam) | v11;
      if ( v84[1] )
      {
        sub_102EC80(v84[1]);
        j__free(v84[1]);
      }
      j__free(v86);
    }
    j__free(v85);
  }
  v15 = PE_PerfInfo::Load(&PerfInfo, L".NET CLR Loading");
  v85 = v15;
  if ( v15 )
  {
    v16 = sub_10286E0(szBuffer, v15);
    v86 = v16;
    if ( v16 )
    {
      v17 = sub_1027F10(v16, L"Current AppDomains", &v83);
      v18 = ghWndTreeListView;
      v19 = sub_105F920(*v17, *v17 >> 32, &v4->field_10);
      v20 = RedrawColumn(v19, v18, IDS_APPDOMAINS, wParam) | v2;
      v21 = sub_1027F10(v86, L"Current Assemblies", &v83);
      v22 = ghWndTreeListView;
      v23 = sub_105F920(*v21, *v21 >> 32, &v4->field_30);
      v24 = RedrawColumn(v23, v22, IDS_ASSEMBLIES, wParam) | v20;
      v25 = sub_1027F10(v86, L"Current Classes Loaded", &v83);
      v26 = ghWndTreeListView;
      v27 = sub_105F920(*v25, *v25 >> 32, &v4->field_20);
      v28 = RedrawColumn(v27, v26, IDS_CLASSES_LOADED, wParam) | v24;
      v29 = sub_1027F10(v86, L"Total AppDomains", &v83);
      v30 = ghWndTreeListView;
      v31 = sub_105F920(*v29, *v29 >> 32, &v4->field_18);
      v32 = RedrawColumn(v31, v30, IDS_TOTAL_APPDOMAINS, wParam) | v28;
      v33 = sub_1027F10(v86, L"Total Assemblies", &v83);
      v34 = ghWndTreeListView;
      v35 = sub_105F920(*v33, *v33 >> 32, &v4->field_38);
      v36 = RedrawColumn(v35, v34, IDS_TOTAL_ASSEMBLIES, wParam) | v32;
      v37 = sub_1027F10(v86, L"Total Classes Loaded", &v83);
      v38 = ghWndTreeListView;
      v39 = sub_105F920(*v37, *v37 >> 32, &v4->field_28);
      v2 = RedrawColumn(v39, v38, IDS_TOTAL_CLASSES_LOADED, wParam) | v36;
      j__free(v86);
    }
    j__free(v85);
  }
  v40 = PE_PerfInfo::Load(&PerfInfo, L".NET CLR LocksAndThreads");
  v84[1] = v40;
  if ( v40 )
  {
    v41 = sub_10286E0(szBuffer, v40);
    v85 = v41;
    if ( v41 )
    {
      v42 = sub_1027F10(v41, L"Total # of contentions", &v83);
      v43 = ghWndTreeListView;
      v44 = sub_105F920(*v42, *v42 >> 32, &v4->field_80);
      v2 |= RedrawColumn(v44, v43, 1110, wParam);
      j__free(v85);
    }
    j__free(v84[1]);
  }
  v45 = PE_PerfInfo::Load(&PerfInfo, L".NET CLR Memory");
  v85 = v45;
  if ( v45 )
  {
    v46 = sub_10286E0(szBuffer, v45);
    v86 = v46;
    if ( v46 )
    {
      v47 = sub_1027F10(v46, L"# bytes in all heaps", &v83);
      v48 = ghWndTreeListView;
      v49 = sub_105F920(*v47, *v47 >> 32, &v4->field_70);
      v50 = RedrawColumn(v49, v48, 1103, wParam) | v2;
      v51 = sub_1027F10(v86, L"# Gen 0 collections", &v83);
      v52 = ghWndTreeListView;
      v53 = sub_105F920(*v51, *v51 >> 32, &v4->field_40);
      v54 = RedrawColumn(v53, v52, 1104, wParam) | v50;
      v55 = sub_1027F10(v86, L"# Gen 1 collections", &v83);
      v56 = ghWndTreeListView;
      v57 = sub_105F920(*v55, *v55 >> 32, &v4->field_48);
      v58 = RedrawColumn(v57, v56, 1105, wParam) | v54;
      v59 = sub_1027F10(v86, L"# Gen 2 collections", &v83);
      v60 = ghWndTreeListView;
      v61 = sub_105F920(*v59, *v59 >> 32, &v4->field_50);
      v62 = RedrawColumn(v61, v60, 1106, wParam) | v58;
      sub_1027F10(v86, L"Allocated bytes/sec", v79);
      v63 = v79[1];
      *v84 = *v79;
      *v84 = *v79 - *&v82->field_60;
      v64 = (*v84 / ((*&gLoadNetClrMemoryPerfInfoTime - *&gLoadNetClrMemoryPerfInfoTimeLast) / 10000000.0));
      v65 = v64;
      LODWORD(v64) = v82;
      v82->field_60 = v79[0];
      v4 = v64;
      *(v64 + 100) = v63;
      v6 = wParam;
      v66 = ghWndTreeListView;
      v67 = sub_105F920(v65, SHIDWORD(v64), (v64 + 104));
      v68 = RedrawColumn(v67, v66, 1108, wParam) | v62;
      sub_1027F10(v86, L"% time in GC", &v80);
      v84[1] = sub_102E840(v86);
      sub_102ECA0(v84[1], &v81, 0);
      v69 = 0.0;
      if ( v81 != 0.0 )
        v69 = v80 * 100.0 / v81;
      v70 = ghWndTreeListView;
      v71 = sub_105F8F0(v69, &v4->field_58);
      v2 = RedrawColumn(v71, v70, 1107, wParam) | v68;
      if ( v84[1] )
      {
        sub_102EC80(v84[1]);
        j__free(v84[1]);
      }
      j__free(v86);
    }
    j__free(v85);
  }
  v72 = PE_PerfInfo::Load(&PerfInfo, L".NET CLR Security");
  v84[1] = v72;
  if ( v72 )
  {
    v73 = sub_10286E0(szBuffer, v72);
    v85 = v73;
    if ( v73 )
    {
      v74 = sub_1027F10(v73, L"Total runtime checks", &v83);
      v75 = ghWndTreeListView;
      v76 = sub_105F920(*v74, *v74 >> 32, &v4->field_78);
      v2 |= RedrawColumn(v76, v75, 1109, v6);
      j__free(v85);
    }
    j__free(v84[1]);
  }
  return v2;
}
// 109CDC0: using guessed type double db_onehundred;
// 10CA0A8: using guessed type struct _FILETIME gLoadNetClrMemoryPerfInfoTimeLast;

//----- (0102B0A0) --------------------------------------------------------
int __thiscall sub_102B0A0(_DWORD *this, DWORD dwThreadId, int a3)
{
  _DWORD *v3; // ebx
  int result; // eax
  int *v5; // ST20_4
  int v6; // ecx
  HANDLE v7; // eax
  void *v8; // esi
  signed int v9; // ebx
  HANDLE v10; // eax
  void *v11; // esi
  int *v12; // ecx
  int v13; // eax
  int v14; // eax
  int v15; // edi
  int v16; // esi
  int v17; // eax
  int v18; // ecx
  int v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // ecx
  int (__stdcall **v23)(int, GUID *, int *); // eax
  int v24; // eax
  int v25; // ecx
  int v26; // eax
  int (__stdcall **v27)(int, GUID *, int *); // eax
  int v28[2]; // [esp+10h] [ebp-62Ch]
  int v29; // [esp+18h] [ebp-624h]
  int v30; // [esp+1Ch] [ebp-620h]
  int v31; // [esp+20h] [ebp-61Ch]
  int v32; // [esp+24h] [ebp-618h]
  int v33; // [esp+28h] [ebp-614h]
  int v34; // [esp+2Ch] [ebp-610h]
  int v35; // [esp+30h] [ebp-60Ch]
  int v36; // [esp+34h] [ebp-608h]
  int v37; // [esp+38h] [ebp-604h]
  int v38; // [esp+3Ch] [ebp-600h]
  int v39; // [esp+40h] [ebp-5FCh]
  int v40; // [esp+44h] [ebp-5F8h]
  int v41; // [esp+48h] [ebp-5F4h]
  unsigned int v42; // [esp+4Ch] [ebp-5F0h]
  int v43; // [esp+50h] [ebp-5ECh]
  int v44; // [esp+54h] [ebp-5E8h]
  int v45; // [esp+58h] [ebp-5E4h]
  int v46; // [esp+5Ch] [ebp-5E0h]
  int v47; // [esp+60h] [ebp-5DCh]
  int v48; // [esp+64h] [ebp-5D8h]
  int v49; // [esp+68h] [ebp-5D4h]
  int v50; // [esp+6Ch] [ebp-5D0h]
  int v51; // [esp+70h] [ebp-5CCh]
  int v52; // [esp+74h] [ebp-5C8h]
  int v53; // [esp+78h] [ebp-5C4h]
  int v54; // [esp+7Ch] [ebp-5C0h]
  int v55; // [esp+80h] [ebp-5BCh]
  int v56; // [esp+84h] [ebp-5B8h]
  int v57; // [esp+88h] [ebp-5B4h]
  unsigned int v58; // [esp+8Ch] [ebp-5B0h]
  int v59; // [esp+90h] [ebp-5ACh]
  int v60; // [esp+94h] [ebp-5A8h]
  int v61; // [esp+360h] [ebp-2DCh]
  int v62; // [esp+638h] [ebp-4h]

  v3 = this;
  v52 = a3;
  result = sub_1028D10(this, dwThreadId);
  if ( !result )
    return result;
  v53 = 0;
  v5 = v3[7];
  v6 = *v5;
  v62 = 0;
  (*(v6 + 60))(v5, dwThreadId, &v53);
  if ( !v53 )
  {
    v7 = OpenThread(0x1F03FFu, 1, dwThreadId);
    v8 = v7;
    if ( v7 )
    {
      ResumeThread(v7);
      CloseHandle(v8);
    }
    v9 = 0;
    goto LABEL_72;
  }
  v10 = OpenThread(0x1F03FFu, 1, dwThreadId);
  v11 = v10;
  if ( v10 )
  {
    SuspendThread(v10);
    CloseHandle(v11);
  }
  v12 = 0;
  v58 = 0;
  if ( v53 )
  {
    v13 = (**v53)(v53, &stru_109FC50, &v58);
    v12 = v58;
    if ( v13 < 0 )
      v12 = 0;
    v58 = v12;
  }
  if ( !v12 )
  {
    sub_1029B40(dwThreadId);
    v9 = 0;
    goto LABEL_70;
  }
  v54 = 0;
  v14 = *v12;
  LOBYTE(v62) = 2;
  if ( (*(v14 + 12))(v12, &v54) )
  {
    sub_1029B40(dwThreadId);
    v9 = 0;
    goto LABEL_68;
  }
  v43 = 0;
  v44 = 0;
  v29 = 0;
  v30 = 0;
  v31 = 0;
  v32 = 0;
  v33 = 0;
  v34 = 10;
  v48 = 0;
  v35 = 0;
  v36 = 0;
  v37 = 0;
  v38 = 0;
  v39 = 0;
  v40 = 10;
  LOBYTE(v62) = 4;
  if ( !sub_1027FF0(v58, &v41, &v42) )
  {
    v9 = 0;
    goto LABEL_67;
  }
  v51 = 0;
  v15 = 0;
  *v28 = 0i64;
  v46 = 0;
  v49 = 0;
  v16 = 0;
  v50 = 0;
  LOBYTE(v62) = 6;
  while ( 1 )
  {
    while ( 1 )
    {
      if ( v51 == 1 )
      {
        v47 = v15;
        if ( v15 )
          (*(*v15 + 4))(v15);
        LOBYTE(v62) = 7;
        if ( v15 )
        {
          v55 = 0;
          v56 = 0;
          v17 = (**v15)(v15, &stru_109FC60, &v56);
          v18 = v56;
          if ( v17 < 0 )
            v18 = 0;
          v56 = v18;
          LOBYTE(v62) = 8;
          if ( v18 )
          {
            (*(*v18 + 12))(v18, &v55);
            if ( v55 == 1 && v16 != v15 )
            {
              (*(*v15 + 4))(v15);
              v19 = v16;
              v16 = v15;
              v50 = v15;
              if ( v19 )
                (*(*v19 + 8))(v19);
            }
            v18 = v56;
          }
          LOBYTE(v62) = 7;
          if ( v18 )
            (*(*v18 + 8))(v18);
        }
        LOBYTE(v62) = 6;
        if ( v15 )
          (*(*v15 + 8))(v15);
      }
      v49 = 0;
      v55 = v15;
      v20 = sub_1028E20(v3, v58, v54, &v55, &v46, &v51, v41, v42, &v48);
      v15 = v55;
      v49 = v55;
      if ( v20 )
      {
        if ( v16 )
          break;
      }
      if ( v20 != 1 )
      {
        sub_102A570(v3, dwThreadId, &v61, 716, -1, 0x7FFFFFFF, &v35);
        sub_1029C50(v3, &v29, &v35, v52);
        sub_1029A30(&v35);
        sub_1029B40(dwThreadId);
        sub_10277E0(v52);
        v9 = 1;
        goto LABEL_63;
      }
      if ( !sub_102B680(v3, dwThreadId, v55, v54, &v29, &v35, &v43, &v60, &v44, &v61, v28, v52) )
      {
        sub_1029B40(dwThreadId);
        v9 = 0;
        goto LABEL_63;
      }
    }
    v47 = v55;
    if ( v55 )
      (*(*v55 + 4))(v55);
    LOBYTE(v62) = 9;
    if ( v15 )
      break;
LABEL_52:
    LOBYTE(v62) = 6;
    if ( v15 )
      (*(*v15 + 8))(v15);
  }
  v59 = 0;
  v21 = (**v16)(v16, &stru_109FC60, &v59);
  v22 = v59;
  if ( v21 < 0 )
    v22 = 0;
  v59 = v22;
  v57 = 0;
  v23 = *v15;
  LOBYTE(v62) = 10;
  v24 = (*v23)(v15, &stru_109FC60, &v57);
  v25 = v57;
  if ( v24 < 0 )
    v25 = 0;
  v57 = v25;
  LOBYTE(v62) = 11;
  if ( !(*(*v59 + 16))(v59, v25, &v45) )
  {
    if ( v45 == 1 )
    {
      v26 = v16;
      v16 = 0;
      v50 = 0;
      if ( v26 )
        (*(*v26 + 8))(v26);
    }
    LOBYTE(v62) = 10;
    if ( v57 )
      (*(*v57 + 8))(v57);
    LOBYTE(v62) = 9;
    if ( v59 )
      (*(*v59 + 8))(v59);
    goto LABEL_52;
  }
  LOBYTE(v62) = 10;
  if ( v57 )
    (*(*v57 + 8))(v57);
  LOBYTE(v62) = 9;
  if ( v59 )
    (*(*v59 + 8))(v59);
  v27 = *v15;
  LOBYTE(v62) = 6;
  (v27[2])(v15);
  v9 = 0;
LABEL_63:
  LOBYTE(v62) = 5;
  if ( v16 )
    (*(*v16 + 8))(v16);
  LOBYTE(v62) = 4;
  if ( v15 )
    (*(*v15 + 8))(v15);
LABEL_67:
  sub_1029A30(&v35);
  sub_1029A30(&v29);
LABEL_68:
  LOBYTE(v62) = 1;
  if ( v54 )
    (*(*v54 + 8))(v54);
LABEL_70:
  LOBYTE(v62) = 0;
  if ( v58 )
    (*(*v58 + 8))(v58);
LABEL_72:
  v62 = -1;
  if ( v53 )
    (*(*v53 + 8))(v53);
  return v9;
}
// 109FC50: using guessed type GUID stru_109FC50;
// 109FC60: using guessed type GUID stru_109FC60;

//----- (0102B680) --------------------------------------------------------
int __thiscall sub_102B680(_DWORD *this, DWORD dwThreadId, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12)
{
  _DWORD *v12; // ebx
  signed int v13; // eax
  _DWORD *v14; // esi
  _DWORD *v16; // edx
  int *v17; // ecx
  int v18; // esi
  int v19; // ST10_4
  _DWORD *v20; // esi
  _DWORD *v21; // ecx
  _DWORD *v22; // eax
  _DWORD *v23; // esi
  int v24; // eax
  signed int v25; // eax
  int v26; // eax

  v12 = this;
  if ( a3 )
  {
    v13 = sub_1027DD0(a3);
    if ( v13 != 2 )
    {
      v14 = a7;
      if ( v13 != 1 )
      {
        if ( (*(*a4 + 12))(a4, 65539, 716, &a4, a8) )
          return 0;
        v16 = a9;
        *v14 = 1;
LABEL_7:
        v17 = a11;
        *a11 = -1;
        v17[1] = 0x7FFFFFFF;
        if ( *v14 == 1 )
        {
          *v17 = *(a8 + 196);
          v17[1] = 0;
        }
        v18 = a6;
        if ( *v16 == 1 )
          sub_102A570(v12, dwThreadId, a10, 716, *v17, v17[1], a6);
        v19 = v18;
        v20 = a5;
        sub_1029C50(v12, a5, v19, a12);
        v21 = a6;
        *a9 = 0;
        sub_1029A30(v21);
        sub_1029A30(v20);
        a9 = 0;
        v22 = operator new(0x20u);
        v23 = v22;
        a8 = v22;
        if ( v22 )
        {
          *v22 = &SymbolInfo::`vftable';
          v22[1] = 1;
          v22[7] = operator new[](0x800u);
        }
        else
        {
          v23 = 0;
        }
        a9 = v23;
        v25 = sub_1027DD0(a3);
        if ( v25 && (v26 = v25 - 1) != 0 )
        {
          if ( v26 != 2 )
            goto LABEL_22;
          sub_1028A30(v23, "[Native Frame: IL Method without Metadata]", 0, 0, 3);
        }
        else if ( !sub_10280C0(a3, v23) )
        {
          goto LABEL_22;
        }
        sub_10276F0(a12, &a9);
LABEL_22:
        if ( v23 )
          (*(*v23 + 8))(v23);
        return 1;
      }
      v16 = a9;
      if ( !*a9 )
        goto LABEL_7;
      v24 = *a3;
      a12 = a3;
      (*(v24 + 4))(a3);
      sub_1027740(a5, &a12);
      (*(*a3 + 8))(a3);
    }
  }
  else
  {
    if ( (*(*a4 + 12))(a4, 65539, 716, &a8, a10) )
      return 0;
    *a9 = 1;
    *a7 = 0;
  }
  return 1;
}
// 109F420: using guessed type void *SymbolInfo::`vftable';

//----- (0102B8A0) --------------------------------------------------------
void LoadNetClrMemoryPerformanceInfo()
{
  int v0; // [esp+0h] [ebp-44h]
  int PEPerfInfo[4]; // [esp+10h] [ebp-34h]
  PerformanceInfo Info; // [esp+20h] [ebp-24h]
  PerformanceInfoInMemory Item; // [esp+2Ch] [ebp-18h]
  int *v4; // [esp+34h] [ebp-10h]
  int v5; // [esp+40h] [ebp-4h]

  v4 = &v0;
  SetEnvironmentVariableW(L"COMPLUS_FodPath", L"c:\\no-fod.exe");
  v5 = 0;
  PerformanceInfo::PerformanceInfo(&Info, 0);
  LOBYTE(v5) = 1;
  PE_PerfInfo::PE_PerfInfo(&Item, &Info);
  LOBYTE(v5) = 2;
  PerformanceInfoInMemory::Load(&Item, 0, L".NET CLR Memory");
  unknown_libname_3(PEPerfInfo, &Item, &Info);
  gNetClrMemoryPerfInfoLoaded = PE_PerfInfo::Load(PEPerfInfo, L".NET CLR Memory") != 0;
  if ( gNetClrMemoryPerfInfoLoaded )
  {
    CoInitialize(0);
    if ( gNetClrMemoryPerfInfoLoaded )
    {
      gLoadNetClrMemoryPerfInfoTimeLast = gLoadNetClrMemoryPerfInfoTime;
      GetSystemTimeAsFileTime(&gLoadNetClrMemoryPerfInfoTime);
      PerformanceInfoInMemory::Load(
        &gPerformanceInfoInMemory,
        0,
        L".NET CLR Memory,.NET CLR Exceptions,.NET CLR Remoting,.NET CLR LocksAndThreads,.NET CLR Security,.NET CLR Jit,.N"
         "ET CLR Loading,.NET CLR Interop,.NET CLR Data");
    }
  }
  LOBYTE(v5) = 1;
  PerformanceInfoInMemory::~PerformanceInfoInMemory(&Item);
  LOBYTE(v5) = 0;
  PerformanceInfo::~PerformanceInfo(&Info);
}
// 10CA098: using guessed type char gNetClrMemoryPerfInfoLoaded;
// 10CA0A8: using guessed type struct _FILETIME gLoadNetClrMemoryPerfInfoTimeLast;

//----- (0102B9D0) --------------------------------------------------------
void *__cdecl sub_102B9D0(int a1)
{
  void *v1; // esi
  int v3; // [esp+0h] [ebp-Ch]
  int v4; // [esp+4h] [ebp-8h]
  LPVOID ppv; // [esp+8h] [ebp-4h]

  if ( !gNetClrMemoryPerfInfoLoaded )
    return 0;
  v3 = 0;
  if ( byte_10CA09A )
    CoCreateInstance(&stru_109F40C, 0, 1u, &stru_109F3BC, &ppv);
  else
    CoCreateInstance(&stru_109F3AC, 0, 1u, &stru_109F3BC, &ppv);
  if ( !ppv )
    return 0;
  if ( !(*(*ppv + 16))(ppv, a1, &v4) )
  {
    (*(*v4 + 12))(v4, &v3);
    (*(*v4 + 8))(v4);
  }
  (*(*ppv + 8))(ppv);
  if ( !v3 )
    return 0;
  v1 = malloc(0x88u);
  memset(v1, 0, 0x88u);
  return v1;
}
// 109F40C: using guessed type GUID stru_109F40C;
// 10CA098: using guessed type char gNetClrMemoryPerfInfoLoaded;
// 10CA09A: using guessed type char byte_10CA09A;

//----- (0102BA80) --------------------------------------------------------
int __stdcall PageProcNet(HWND hWnd, unsigned int a2, WPARAM wParam, int a4)
{
  HWND v4; // ebx
  LONG v5; // edi
  int result; // eax
  void *v7; // esi
  CResizer *v8; // eax
  wchar_t *v9; // edi
  HWND v10; // eax
  LONG v11; // eax
  HWND v12; // eax
  HWND v13; // ST0C_4
  HWND v14; // eax
  HWND v15; // eax
  LONG v16; // eax
  PerformanceInfoInMemory *v17; // eax
  PerformanceInfoInMemory *v18; // eax
  HWND v19; // ST08_4
  HWND v20; // eax
  LRESULT v21; // eax
  PE_PerfInfo_Item *v22; // eax
  _DWORD *v23; // eax
  wchar_t **v24; // esi
  int v25; // ebx
  int v26; // eax
  HWND v27; // ST08_4
  int v28; // ST10_4
  HWND v29; // eax
  PE_PerfInfo_Item *v30; // eax
  LRESULT v31; // esi
  HWND v32; // ST08_4
  wchar_t **v33; // eax
  void **v34; // esi
  double v35; // xmm0_8
  HWND v36; // ST08_4
  int v37; // eax
  HWND v38; // ST08_4
  WPARAM ArgList; // [esp+0h] [ebp-3BCh]
  LPARAM lParam; // [esp+14h] [ebp-3A8h]
  int v41; // [esp+1Ch] [ebp-3A0h]
  int v42; // [esp+20h] [ebp-39Ch]
  int v43; // [esp+24h] [ebp-398h]
  char *v44; // [esp+28h] [ebp-394h]
  int v45; // [esp+2Ch] [ebp-390h]
  PE_PerfInfo v46; // [esp+48h] [ebp-374h]
  LVITEMW v47; // [esp+58h] [ebp-364h]
  UINT v48; // [esp+8Ch] [ebp-330h]
  int v49; // [esp+90h] [ebp-32Ch]
  unsigned int v50; // [esp+94h] [ebp-328h]
  HWND v51; // [esp+98h] [ebp-324h]
  UINT pnIDs; // [esp+9Ch] [ebp-320h]
  WORD v53[2]; // [esp+A0h] [ebp-31Ch]
  char v54[4]; // [esp+A4h] [ebp-318h]
  int v55; // [esp+A8h] [ebp-314h]
  WORD pnWidths[2]; // [esp+ACh] [ebp-310h]
  WPARAM v57; // [esp+B0h] [ebp-30Ch]
  LPDRAWITEMSTRUCT pDrawItemStruct; // [esp+B4h] [ebp-308h]
  char v59; // [esp+B8h] [ebp-304h]
  WCHAR sz; // [esp+1B8h] [ebp-204h]
  wchar_t Dst; // [esp+2B8h] [ebp-104h]

  v4 = hWnd;
  pDrawItemStruct = a4;
  v51 = hWnd;
  v47.mask = 0;
  memset(&v47.iItem, 0, 0x30u);
  v5 = GetWindowLongW(hWnd, -21);
  v48 = 1093;
  v49 = 1058;
  v53[0] = MulDiv(100, gLogPixelSize.x, 96);
  v53[1] = MulDiv(-100, gLogPixelSize.x, 96);
  pnIDs = 1096;
  pnWidths[0] = MulDiv(100, gLogPixelSize.x, 96);
  if ( a2 > 0x111 )
  {
    switch ( a2 )
    {
      case 0x113u:
        v28 = dword_10CA0CC;
        v29 = GetDlgItem(hWnd, 1094);
        sub_1027A00(v29, v28, 0);
        PerformanceInfoInMemory::Load(*(v5 + 804), 0, (v5 + 28));
        unknown_libname_3(&v46, *(v5 + 804), &gPerformanceInfo);
        v30 = PE_PerfInfo::Load(&v46, (v5 + 28));
        if ( v30 )
        {
          pDrawItemStruct = sub_10286E0((v5 + 284), v30);
          GetSystemTimeAsFileTime((v5 + 8));
          v31 = 0;
          v32 = *(v5 + 16);
          v57 = 0;
          if ( SendMessageW(v32, LVM_GETITEMCOUNT, 0, 0) > 0 )
          {
            do
            {
              v47.mask = 1;
              v47.pszText = &sz;
              v47.iItem = v31;
              v47.iSubItem = 0;
              v47.cchTextMax = 128;
              SendMessageW(*(v5 + 16), LVM_GETITEMW, 0, &v47);
              if ( pDrawItemStruct && sub_1027F10(pDrawItemStruct, &sz, v54) )
              {
                v33 = sub_102E760(pDrawItemStruct, &sz);
                v34 = v33;
                if ( v33 && v33[1] & 0x20000 )
                {
                  v34 = sub_102E840(pDrawItemStruct);
                  sub_102ECA0(v34, &v50, 0);
                  v35 = 0.0;
                  if ( v50 != 0.0 )
                    v35 = *v54 * 100.0 / v50;
                  sub_1027500(&Dst, L"%02.02f", LODWORD(v35), HIDWORD(v35));
                }
                else
                {
                  sub_1027500(&Dst, L"%I64d", *v54, v55);
                  PE_GetNumberFormat(&Dst, 0x80u);
                }
                if ( v34 )
                {
                  sub_102EC80(v34);
                  j__free(v34);
                }
                v31 = v57;
              }
              else
              {
                sub_1027500(&Dst, L"0");
              }
              v41 = 1;
              v44 = &v59;
              v36 = *(v5 + 16);
              v45 = 128;
              SendMessageW(v36, 0x1073u, v31, &lParam);
              v37 = wcscmp(&v59, &Dst);
              if ( v37 )
                v37 = -(v37 < 0) | 1;
              if ( v37 )
              {
                v47.mask = 1;
                v47.pszText = &Dst;
                v47.iSubItem = 1;
                v47.cchTextMax = 128;
                SendMessageW(*(v5 + 16), 0x104Cu, 0, &v47);
                SendMessageW(*(v5 + 16), 0x1015u, v47.iItem, v47.iItem);
              }
              v38 = *(v5 + 16);
              v57 = ++v31;
            }
            while ( v31 < SendMessageW(v38, 0x1004u, 0, 0) );
          }
        }
        *v5 = *(v5 + 8);
        *(v5 + 4) = *(v5 + 12);
        return 0;
      case 0x133u:
      case 0x136u:
      case 0x138u:
        return PE_FillControl(hWnd, wParam);
      default:
        return 0;
    }
    return 0;
  }
  if ( a2 == 273 )
  {
    switch ( wParam )
    {
      case 0x9C41u:
        ArgList = 40014;
        goto LABEL_25;
      case 0x9C42u:
        SetEvent(ghRefreshEventHandle);
        break;
      case 0x9C9Cu:
      case 0x9C9Du:
        ArgList = wParam;
LABEL_25:
        v20 = GetParent(hWnd);
        PostMessageW(v20, 0x111u, ArgList, 0);
        break;
      default:
        break;
    }
    if ( wParam >> 16 == 1 && wParam == 1093 )
    {
      SendMessageW(*(v5 + 16), 0x1009u, 0, 0);
      v21 = SendMessageW(*(v5 + 20), 0x147u, 0, 0);
      SendMessageW(*(v5 + 20), 0x148u, v21, v5 + 28);
      PerformanceInfoInMemory::Load(*(v5 + 804), 0, (v5 + 28));
      unknown_libname_3(&v46, *(v5 + 804), &gPerformanceInfo);
      v22 = PE_PerfInfo::Load(&v46, (v5 + 28));
      if ( v22 )
      {
        v23 = sub_102ED60(v22);
        v57 = v23;
        if ( v23 )
        {
          v24 = sub_102E830(v23);
          if ( v24 )
          {
            v25 = v57;
            do
            {
              if ( !(v24[1] & 0x400000) )
              {
                wcscpy_s(&Dst, 0x80u, *v24);
                v26 = wcscmp(L"Not Displayed", &Dst);
                if ( v26 )
                  v26 = -(v26 < 0) | 1;
                if ( v26 )
                  sub_1057F90(*(v5 + 16), &Dst, &gszNullString);
              }
              sub_102EC80(v24);
              j__free(v24);
              v24 = sub_102E840(v25);
            }
            while ( v24 );
            v4 = v51;
          }
        }
      }
      SendMessageW(v4, 0x113u, 0, 0);
      SendMessageW(*(v5 + 16), 0x101Eu, 0, 0xFFFF);
      SendMessageW(*(v5 + 16), 0x101Eu, 1u, 65534);
      v43 = 2;
      v27 = *(v5 + 16);
      v42 = 2;
      SendMessageW(v27, 0x102Bu, 0, &lParam);
    }
    return 0;
  }
  if ( a2 > 0x2C )
  {
    if ( a2 == 256 )
    {
      if ( wParam == 116 )
        PostMessageW(hWnd, 0x113u, 1u, 0);
      return 0;
    }
    if ( a2 != 272 )
      return 0;
    v8 = operator new(0x40u);
    if ( v8 )
      CResizer::CResizer(v8, hWnd);
    PropSheet_UpdateTab(hWnd);
    v9 = malloc(0x328u);
    memset(v9, 0, 0x328u);
    SetWindowLongW(hWnd, -21, v9);
    v10 = GetDlgItem(hWnd, 1094);
    *(v9 + 6) = v10;
    v11 = GetWindowLongW(v10, -16);
    SetWindowLongW(*(v9 + 6), -16, v11 & 0xFFFFFFFD | 1);
    SetWindowLongW(*(v9 + 6), -21, 1);
    SendMessageW(*(v9 + 6), 0x1036u, 0x4020u, 16416);
    v12 = SendMessageW(*(v9 + 6), 0x104Eu, 0, 0);
    CTreeList::InitToolTips(v12);
    gOldListWndProc = SetWindowLongW(*(v9 + 6), -4, Proxy_ListCtrlWndProc);
    SendMessageW(*(v9 + 6), 0x30u, ghConfigFont, 0);
    InitListHeader(*(v9 + 6), &pnIDs, pnWidths, 1);
    v13 = *(v9 + 6);
    dword_10CA0CC = pDrawItemStruct[1].hwndItem;
    sub_1027A00(v13, dword_10CA0CC, 1);
    SendMessageW(*(v9 + 6), 0x101Eu, 0, 65534);
    sub_1028790(pDrawItemStruct[1].itemAction, v9 + 142);
    v14 = GetDlgItem(hWnd, 1093);
    *(v9 + 5) = v14;
    SendMessageW(v14, 0x143u, 0, L".NET CLR Memory");
    SendMessageW(*(v9 + 5), 0x143u, 0, L".NET CLR Jit");
    SendMessageW(*(v9 + 5), 0x143u, 0, L".NET CLR Exceptions");
    SendMessageW(*(v9 + 5), 0x143u, 0, L".NET CLR LocksAndThreads");
    SendMessageW(*(v9 + 5), 0x143u, 0, L".NET CLR Data");
    SendMessageW(*(v9 + 5), 0x143u, 0, L".NET CLR Interop");
    SendMessageW(*(v9 + 5), 0x143u, 0, L".NET CLR Loading");
    SendMessageW(*(v9 + 5), 0x143u, 0, L".NET CLR Remoting");
    SendMessageW(*(v9 + 5), 0x143u, 0, L".NET CLR Security");
    SendMessageW(*(v9 + 5), 0x14Eu, 0, 0);
    v15 = GetDlgItem(hWnd, 1091);
    *(v9 + 4) = v15;
    v16 = GetWindowLongW(v15, -16);
    SetWindowLongW(*(v9 + 4), -16, v16 & 0xFFFFFFFD | 1);
    v17 = operator new(8u);
    if ( v17 )
      v18 = PE_PerfInfo::PE_PerfInfo(v17, &gPerformanceInfo);
    else
      v18 = 0;
    v19 = *(v9 + 4);
    *(v9 + 201) = v18;
    SendMessageW(v19, 0x1036u, 0x4020u, 16416);
    gOldListWndProc = SetWindowLongW(*(v9 + 4), -4, Proxy_ListCtrlWndProc);
    SendMessageW(*(v9 + 4), 0x30u, ghConfigFont, 0);
    InitListHeader(*(v9 + 4), &v48, v53, 2);
    SendMessageW(hWnd, 0x111u, 0x10445u, 0);
    SendMessageW(*(v9 + 4), 0x101Eu, 0, 0xFFFF);
    SendMessageW(*(v9 + 4), 0x101Eu, 1u, 65534);
    *v9 = 0;
    *(v9 + 1) = 0;
    SendMessageW(hWnd, 0x113u, 0, 0);
    result = 1;
  }
  else
  {
    if ( a2 != 44 )
    {
      if ( a2 == 2 )
      {
        v7 = *(v5 + 804);
        if ( v7 )
        {
          PerformanceInfoInMemory::~PerformanceInfoInMemory(*(v5 + 804));
          j__free(v7);
        }
        free(v5);
      }
      else if ( a2 == 43 )
      {
        CMainWnd::DrawList(pDrawItemStruct);
      }
      return 0;
    }
    result = CMainWnd::HandleMeasureItem(hWnd, 0x2Cu, wParam, pDrawItemStruct);
  }
  return result;
}
// 109CDC0: using guessed type double db_onehundred;
// 109F4BC: using guessed type wchar_t aNetClrExceptio[20];
// 109F518: using guessed type wchar_t aNetClrData[14];
// 109F534: using guessed type wchar_t aNetClrInterop[17];
// 109F57C: using guessed type wchar_t aNetClrRemoting[18];
// 109F5C4: using guessed type wchar_t aNotDisplayed[14];

//----- (0102C500) --------------------------------------------------------
int dynamic_initializer_for_gPerformanceInfoInMemory__()
{
  int result; // eax

  if ( gNetClrMemoryPerfInfoLoaded )
  {
    gLoadNetClrMemoryPerfInfoTimeLast = gLoadNetClrMemoryPerfInfoTime;
    GetSystemTimeAsFileTime(&gLoadNetClrMemoryPerfInfoTime);
    result = PerformanceInfoInMemory::Load(
               &gPerformanceInfoInMemory,
               0,
               L".NET CLR Memory,.NET CLR Exceptions,.NET CLR Remoting,.NET CLR LocksAndThreads,.NET CLR Security,.NET CLR"
                " Jit,.NET CLR Loading,.NET CLR Interop,.NET CLR Data");
  }
  return result;
}
// 10CA098: using guessed type char gNetClrMemoryPerfInfoLoaded;
// 10CA0A8: using guessed type struct _FILETIME gLoadNetClrMemoryPerfInfoTimeLast;

//----- (0102C540) --------------------------------------------------------
char __cdecl sub_102C540(tagTREEVIEWLISTITEMPARAM *a1, WPARAM wParam)
{
  char result; // al

  result = 0;
  if ( !byte_10CA099 )
    result = sub_102A870(a1, wParam);
  return result;
}
// 10CA099: using guessed type char byte_10CA099;

//----- (0102C600) --------------------------------------------------------
CSystemProcessInfoMapNode *__thiscall std::_Tree_comp_alloc<std::_Tmap_traits<unsigned long,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *>>,0>>::_Buynode<std::piecewise_construct_t const &,std::tuple<unsigned long &&>,std::tuple<>>(CSystemProcessInfoMap *this, CSystemProcessInfoMapPair *a1)
{
  CSystemProcessInfoMapNode *result; // eax

  result = std::_Tree_comp_alloc<std::_Tmap_traits<unsigned long,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *>>,0>>::_Buynode0(this);
  *&result->baseclass._Color = 0;
  if ( result != -16 )
    result->_Keyvalue = *a1;
  return result;
}

//----- (0102C630) --------------------------------------------------------
CSystemProcessInfoMapNode **__thiscall sub_102C630(CSystemProcessInfoMap *thisMap, CSystemProcessInfoMapNode **ppNode, char a3, CSystemProcessInfoMapNode *pNode, CSystemProcessInfoMapPair *pair, int a6)
{
  CSystemProcessInfoMap *this; // edi
  CSystemProcessInfoMapNode *v7; // eax
  CSystemProcessInfoMapNode *v8; // ebx
  std__Tree_node *v9; // eax
  std_Tree_node_for_tagKeyName *v10; // eax
  std_Tree_node_for_tagKeyName *v11; // ecx
  std_Tree_node_for_tagKeyName *v12; // esi
  std_Tree_node_for_tagKeyName *v13; // edx
  std_Tree_node_for_tagKeyName *v14; // edx
  std_Tree_node_for_tagKeyName *v15; // ecx
  std_Tree_node_for_tagKeyName *v16; // edx
  std_Tree_node_for_tagKeyName *v17; // esi
  std_Tree_node_for_tagKeyName *v18; // ecx
  std_Tree_node_for_tagKeyName *v19; // ecx
  std_Tree_node_for_tagKeyName *v20; // edx
  std_Tree_node_for_tagKeyName *v21; // ecx
  std_Tree_node_for_tagKeyName *v22; // ecx
  std_Tree_node_for_tagKeyName *v23; // ecx
  CSystemProcessInfoMapNode **result; // eax

  this = thisMap;
  if ( thisMap->_Size >= 0xAAAAAA9u )
    std::_Xlength_error("map/set<T> too long");
  v7 = std::_Tree_comp_alloc<std::_Tmap_traits<unsigned long,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *>>,0>>::_Buynode<std::piecewise_construct_t const &,std::tuple<unsigned long &&>,std::tuple<>>(
         thisMap,
         pair);
  ++this->_Size;
  v8 = v7;
  v7->baseclass._Parent = pNode;
  if ( pNode == this->_Header )
  {
    this->_Header->_Parent = v7;
    this->_Header->_Left = v7;
    v9 = this->_Header;
LABEL_8:
    v9->_Right = v8;
    goto LABEL_9;
  }
  if ( !a3 )
  {
    pNode->baseclass._Right = v7;
    v9 = this->_Header;
    if ( pNode != this->_Header->_Right )
      goto LABEL_9;
    goto LABEL_8;
  }
  pNode->baseclass._Left = v7;
  if ( pNode == this->_Header->_Left )
    this->_Header->_Left = v7;
LABEL_9:
  v10 = v8;
  if ( !v8->baseclass._Parent->baseclass._Color )
  {
    do
    {
      v11 = v10->_Parent;
      v12 = v11->_Parent;
      v13 = v12->_Left;
      if ( v11 == v12->_Left )
      {
        v13 = v12->_Right;
        if ( v13->_Color )
        {
          if ( v10 == v11->_Right )
          {
            v10 = v10->_Parent;
            v14 = v11->_Right;
            v11->_Right = v14->_Left;
            if ( !v14->_Left->_IsNil )
              v14->_Left->_Parent = v11;
            v14->_Parent = v11->_Parent;
            if ( v11 == this->_Header->_Parent )
            {
              this->_Header->_Parent = v14;
            }
            else
            {
              v15 = v11->_Parent;
              if ( v10 == v15->_Left )
                v15->_Left = v14;
              else
                v15->_Right = v14;
            }
            v14->_Left = v10;
            v10->_Parent = v14;
          }
          v10->_Parent->_Color = 1;
          v10->_Parent->_Parent->_Color = 0;
          v16 = v10->_Parent->_Parent;
          v17 = v16->_Left;
          v16->_Left = v16->_Left->_Right;
          v18 = v17->_Right;
          if ( !v18->_IsNil )
            v18->_Parent = v16;
          v17->_Parent = v16->_Parent;
          if ( v16 == this->_Header->_Parent )
          {
            this->_Header->_Parent = v17;
            v17->_Right = v16;
          }
          else
          {
            v19 = v16->_Parent;
            if ( v16 == v19->_Right )
              v19->_Right = v17;
            else
              v19->_Left = v17;
            v17->_Right = v16;
          }
LABEL_48:
          v16->_Parent = v17;
          continue;
        }
      }
      else if ( v13->_Color )
      {
        if ( v10 == v11->_Left )
        {
          v10 = v10->_Parent;
          v20 = v11->_Left;
          v11->_Left = v11->_Left->_Right;
          v21 = v20->_Right;
          if ( !v21->_IsNil )
            v21->_Parent = v10;
          v20->_Parent = v10->_Parent;
          if ( v10 == this->_Header->_Parent )
          {
            this->_Header->_Parent = v20;
          }
          else
          {
            v22 = v10->_Parent;
            if ( v10 == v22->_Right )
              v22->_Right = v20;
            else
              v22->_Left = v20;
          }
          v20->_Right = v10;
          v10->_Parent = v20;
        }
        v10->_Parent->_Color = 1;
        v10->_Parent->_Parent->_Color = 0;
        v16 = v10->_Parent->_Parent;
        v17 = v16->_Right;
        v16->_Right = v17->_Left;
        if ( !v17->_Left->_IsNil )
          v17->_Left->_Parent = v16;
        v17->_Parent = v16->_Parent;
        if ( v16 == this->_Header->_Parent )
        {
          this->_Header->_Parent = v17;
        }
        else
        {
          v23 = v16->_Parent;
          if ( v16 == v23->_Left )
            v23->_Left = v17;
          else
            v23->_Right = v17;
        }
        v17->_Left = v16;
        goto LABEL_48;
      }
      v11->_Color = 1;
      v13->_Color = 1;
      v10->_Parent->_Parent->_Color = 0;
      v10 = v10->_Parent->_Parent;
    }
    while ( !v10->_Parent->_Color );
  }
  this->_Header->_Parent->_Color = 1;
  result = ppNode;
  *ppNode = v8;
  return result;
}

//----- (0102C840) --------------------------------------------------------
int __thiscall std::map<unsigned long,unsigned long,std::less<unsigned long>,std::allocator<std::pair<unsigned long const,unsigned long>>>::operator[](CSystemProcessInfoMap *thisMap, int a2, _DWORD *a3, _DWORD *dwThreadId, int a5)
{
  CSystemProcessInfoMap *v5; // ebx
  std__Tree_node *v6; // ecx
  bool v7; // dl
  CSystemProcessInfoMapPair *v8; // edi
  CSystemProcessInfoMapNode *v9; // esi
  CSystemProcessInfoMapNode *v10; // eax
  unsigned int v11; // ecx
  CSystemProcessInfoMapNode *v12; // eax
  CSystemProcessInfoMapNode **v13; // eax
  CSystemProcessInfoMapNode *v14; // ecx
  int result; // eax
  int v16; // [esp+0h] [ebp-2Ch]
  CSystemProcessInfoMap *v17; // [esp+10h] [ebp-1Ch]
  std__Tree_node *v18; // [esp+14h] [ebp-18h]
  int v19; // [esp+18h] [ebp-14h]
  int *v20; // [esp+1Ch] [ebp-10h]
  int v21; // [esp+28h] [ebp-4h]

  v20 = &v16;
  v5 = thisMap;
  v17 = thisMap;
  v6 = thisMap->_Header;
  v7 = 1;
  v8 = dwThreadId;
  v9 = v6;
  v21 = 0;
  v18 = v6;
  v10 = v6->_Parent;
  LOBYTE(v19) = 1;
  if ( !v10->baseclass._isnil )
  {
    v11 = *dwThreadId;
    do
    {
      v9 = v10;
      if ( a3 )
        v7 = v10->_Keyvalue._Key >= v11;
      else
        v7 = v11 < v10->_Keyvalue._Key;
      LOBYTE(v19) = v7;
      if ( v7 )
        v10 = v10->baseclass._Left;
      else
        v10 = v10->baseclass._Right;
    }
    while ( !v10->baseclass._isnil );
    v6 = v18;
    v5 = v17;
  }
  v12 = v9;
  a3 = &v9->baseclass._Left;
  if ( v7 )
  {
    if ( v9 == v6->_Left )
    {
      v13 = sub_102C630(v5, &a3, 1, v9, dwThreadId, a5);
LABEL_14:
      v14 = *v13;
      result = a2;
      *a2 = v14;
      *(a2 + 4) = 1;
      return result;
    }
    std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *>>>,std::_Iterator_base0>::operator--(&a3);
    v12 = a3;
  }
  if ( v12->_Keyvalue._Key < v8->_Key )
  {
    v13 = sub_102C630(v5, &dwThreadId, v19, v9, v8, a5);
    goto LABEL_14;
  }
  *a2 = v12;
  result = a2;
  *(a2 + 4) = 0;
  return result;
}
// 10681AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);

//----- (0102CA10) --------------------------------------------------------
signed int __stdcall LogBufferCallback(int a1)
{
  return 1;
}

//----- (0102CA20) --------------------------------------------------------
HANDLE ScanAllThreads()
{
  HANDLE hFound; // eax
  HANDLE hFound_1; // esi
  int a2; // [esp+4h] [ebp-30h]
  DWORD ThreadId; // [esp+Ch] [ebp-28h]
  DWORD v4; // [esp+10h] [ebp-24h]
  THREADENTRY32 ThreadEntry; // [esp+14h] [ebp-20h]

  hFound = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);
  hFound_1 = hFound;
  if ( hFound != INVALID_HANDLE_VALUE )
  {
    ThreadEntry.dwSize = sizeof(THREADENTRY32);
    if ( Thread32First(hFound, &ThreadEntry) )
    {
      do
      {
        ThreadId = ThreadEntry.th32ThreadID;
        v4 = ThreadEntry.th32OwnerProcessID;
        std::map<unsigned long,unsigned long,std::less<unsigned long>,std::allocator<std::pair<unsigned long const,unsigned long>>>::operator[](
          &gThreadProcessMap,
          &a2,
          0,
          &ThreadId,
          byte_10CA100);
      }
      while ( Thread32Next(hFound_1, &ThreadEntry) );
    }
    hFound = CloseHandle(hFound_1);
  }
  return hFound;
}
// 10CA100: using guessed type char byte_10CA100;

//----- (0102CAB0) --------------------------------------------------------
ULONG __thiscall TraceEventThreadProc(EVENT_TRACE_PROPERTIES_EXT *this)
{
  EVENT_TRACE_PROPERTIES_EXT *Properties; // edi
  __int64 *v2; // ebx
  WCHAR *pszLoggerName; // eax
  TRACEHANDLE v4; // rax
  ULONG ret; // esi
  TRACEHANDLE v6; // rax
  ULONG result; // eax
  _EVENT_TRACE_LOGFILEW LogFile; // [esp+8h] [ebp-1A4h]

  Properties = this;
  memset(&LogFile.LoggerName, 0, 0x19Cu);
  LogFile.LogFileName = 0;
  v2 = &Properties->TraceHandle;
  LogFile.Context = 0;
  pszLoggerName = L"PROCEXP TRACE";
  LogFile.BufferCallback = LogBufferCallback;
  if ( gdwVersion < 3 )
    pszLoggerName = L"NT Kernel Logger";
  LogFile.BuffersRead = 0;
  LogFile.LoggerName = pszLoggerName;
  LogFile.CurrentTime = 0i64;
  LogFile.u2.EventCallback = LogEventCallback;
  LogFile.u.LogFileMode = 0x1100;
  v4 = OpenTraceW_0(&LogFile);
  *v2 = v4;
  HIDWORD(Properties->TraceHandle) = HIDWORD(v4);
  if ( v4 )
  {
    do
    {
      ret = ProcessTrace_0(&Properties->TraceHandle, 1u, 0, 0);
      if ( ret )
        break;
      if ( WaitForSingleObject(Properties->EventHandle, 0) == WAIT_TIMEOUT )
      {
        ret = PE_RunTrace(Properties, 1);
        v6 = OpenTraceW_0(&LogFile);
        *v2 = v6;
        HIDWORD(Properties->TraceHandle) = HIDWORD(v6);
        if ( ret )
          break;
      }
    }
    while ( WaitForSingleObject(Properties->EventHandle, 0) == WAIT_TIMEOUT );
    result = ret;
  }
  else
  {
    result = -1;
  }
  Properties->fTraceStarted = 0;
  return result;
}
// 10A0784: using guessed type wchar_t aProcexpTrace[14];
// 10C4E54: using guessed type int gdwVersion;

//----- (0102CBD0) --------------------------------------------------------
ULONG __stdcall TraceEventThreadProcEx(EVENT_TRACE_PROPERTIES_EXT *a1)
{
  return TraceEventThreadProc(a1);
}

//----- (0102CBE0) --------------------------------------------------------
__int64 __thiscall PE_ComputeTime(PE_TIME *this, __int64 time)
{
  __int64 result; // rax

  if ( time >= 0 )
    result = (10000000 * (time % this->Frequency)) / this->Frequency + 10000000 * (time / this->Frequency);
  else
    result = -PE_ComputeTime(this, -time);
  return result;
}

//----- (0102CC70) --------------------------------------------------------
unsigned __int8 *__cdecl sub_102CC70(int a1, int a2, int a3, wchar_t *Dst, rsize_t SizeInWords)
{
  int v5; // ecx
  int v6; // eax
  wchar_t *v7; // edi
  wchar_t *v8; // esi
  unsigned int v9; // edx
  wchar_t v10; // ax
  unsigned __int8 *result; // eax
  unsigned int v12; // edx
  wchar_t v13; // ax
  unsigned int v14; // edx
  wchar_t v15; // ax
  int v16; // edi
  int v17; // edi
  int v18; // edi
  double v19; // xmm0_8
  int v20; // ST48_4
  int v21; // ecx
  unsigned int v22; // edx
  int i; // esi
  int v24; // ebx
  rsize_t v25; // edx
  int v26; // esi
  _WORD *v27; // eax
  unsigned int v28; // edx
  unsigned int v29; // edx
  int v30; // edi
  unsigned __int8 *v31; // edi
  int v32; // ebx
  const wchar_t *v33; // eax
  wchar_t *v34; // esi
  const wchar_t *v35; // eax
  int v36; // [esp+14h] [ebp-4h]

  v5 = a3;
  v6 = *(a3 + 8);
  v7 = a1;
  v36 = a1;
  switch ( v6 )
  {
    case 0:
      v8 = Dst;
      v9 = 0;
      if ( *(a3 + 12) )
      {
        do
        {
          v10 = *v7;
          v7 = (v7 + 1);
          v8[v9++] = v10;
        }
        while ( v9 < *(v5 + 12) );
      }
      goto LABEL_4;
    case 1:
      v8 = Dst;
      v14 = 0;
      if ( !*(a3 + 12) )
        goto LABEL_4;
      do
      {
        v15 = *v7;
        ++v7;
        v8[v14++] = v15;
      }
      while ( v14 < *(v5 + 12) );
      v8[*(v5 + 12)] = 0;
      return v7 - v36;
    case 2:
      v8 = Dst;
      v12 = 0;
      if ( *(a3 + 12) )
      {
        do
        {
          v13 = *v7;
          v7 = (v7 + 1);
          v8[v12++] = v13;
        }
        while ( v12 < *(v5 + 12) );
        v8[*(v5 + 12)] = 0;
        result = v7 - v36;
      }
      else
      {
LABEL_4:
        v8[*(v5 + 12)] = 0;
        result = v7 - v36;
      }
      return result;
    case 3:
      swprintf_s(Dst, SizeInWords, L"%d", *a1);
      return (v7 - v36 + 1);
    case 4:
      swprintf_s(Dst, SizeInWords, L"%d", *a1);
      return (v7 - v36 + 2);
    case 5:
      swprintf_s(Dst, SizeInWords, L"%u", *a1);
      return (v7 - v36 + 2);
    case 6:
      swprintf_s(Dst, SizeInWords, L"%d", *a1);
      goto LABEL_69;
    case 7:
      swprintf_s(Dst, SizeInWords, L"%lu", *a1);
      goto LABEL_69;
    case 8:
      goto LABEL_17;
    case 9:
      v16 = a1 + 8;
      swprintf_s(Dst, SizeInWords, L"%I64d", *a1, *(a1 + 4));
      return (v16 - v36);
    case 10:
      v17 = a1 + 8;
      swprintf_s(Dst, SizeInWords, L"%I64u", *a1, *(a1 + 4));
      return (v17 - v36);
    case 11:
      v18 = a1 + 4;
      v19 = *a1;
      goto LABEL_21;
    case 12:
      v19 = *a1;
      v18 = a1 + 8;
LABEL_21:
      swprintf_s(Dst, SizeInWords, L"%f", LODWORD(v19), HIDWORD(v19));
      return (v18 - v36);
    case 13:
    case 15:
    case 17:
    case 22:
      switch ( v6 )
      {
        case 13:
        case 22:
          v21 = a1;
          v22 = strlen(a1);
          for ( i = a1 + 1 + v22; v22; --v22 )
          {
            if ( *(a1 + v22 - 1) != 255 )
              break;
          }
          break;
        case 15:
          v22 = *a1;
          v7 = (a1 + 1);
          v21 = a1 + 1;
          i = v22 + a1 + 1;
          break;
        case 17:
          v22 = *(a1 + 1) + (*a1 << 8);
          v7 = (a1 + 2);
          v21 = a1 + 2;
          i = v22 + a1 + 2;
          break;
        default:
          v21 = a1;
          v22 = a1;
          i = a1;
          break;
      }
      if ( v22 > a2 - v21 )
        v22 = a2 - v21;
      if ( v22 > SizeInWords - 3 )
        v22 = SizeInWords - 3;
      swprintf_s(Dst, SizeInWords, L"\"%*S\"", v22, v7);
      return (i - v36);
    case 14:
    case 16:
    case 18:
    case 23:
      switch ( v6 )
      {
        case 14:
          v24 = a1;
          v25 = wcslen(a1);
          v26 = a1 + 2 + 2 * v25;
          if ( v25 )
          {
            v27 = (a1 - 2 + 2 * v25);
            do
            {
              v7 = a1;
              if ( *v27 != -1 )
                break;
              --v27;
              --v25;
            }
            while ( v25 );
          }
          break;
        case 16:
          v29 = *a1;
          v7 = (a1 + 1);
          v24 = a1 + 1;
          v26 = v29 + a1 + 1;
          v25 = v29 >> 1;
          break;
        case 18:
          v7 = (a1 + 2);
          v24 = a1 + 2;
          v28 = *(a1 + 1) + (*a1 << 8);
          v26 = v28 + a1 + 2;
          v25 = v28 >> 1;
          break;
        case 23:
          v24 = a1;
          v26 = a2;
          v25 = (a2 - a1) >> 1;
          break;
        default:
          v24 = a1;
          v25 = a1;
          v26 = a1;
          break;
      }
      if ( 2 * v25 > a2 - v24 )
        v25 = (a2 - v24) >> 1;
      if ( v25 > SizeInWords - 3 )
        v25 = SizeInWords - 3;
      swprintf_s(Dst, SizeInWords, L"\"%*ws\"", v25, v7);
      return (v26 - v36);
    case 19:
      if ( *a1 )
      {
        if ( dword_10BE0D0 == 64 )
          v31 = (a1 + 16);
        else
          v31 = (a1 + 8);
        v32 = 4 * v31[1] + 8;
        sub_102E4E0(&a1, v31);
        if ( a1 )
          v33 = *a1;
        else
          v33 = 0;
        v34 = Dst;
        wcscpy_s(Dst, SizeInWords, v33);
        *v34 = 0;
        _bstr_t::_Free(&a1);
        result = &v31[v32 - v36];
      }
      else
      {
        v30 = a1 + 4;
        swprintf_s(Dst, SizeInWords, L"0");
        result = (v30 - v36);
      }
      return result;
    case 20:
      swprintf_s(Dst, SizeInWords, L"%03d.%03d.%03d.%03d", *a1, *a1 >> 8, (*a1 >> 16) & 0xFF, *a1 >> 24);
      return (v7 - v36 + 4);
    case 21:
      v20 = ntohs(*a1);
      swprintf_s(Dst, SizeInWords, L"%u", v20);
      return (v7 - v36 + 2);
    case 24:
      if ( dword_10BE0D0 == 64 )
      {
        swprintf_s(Dst, SizeInWords, L"0x%X", *a1);
        result = (v7 - v36 + 8);
      }
      else
      {
LABEL_17:
        swprintf_s(Dst, SizeInWords, L"0x%08X", *a1);
LABEL_69:
        result = (v7 - v36 + 4);
      }
      return result;
    case 25:
      sub_FF92A0(Dst, SizeInWords, a1);
      return (v7 - v36 + 16);
    case 26:
      v35 = L"TRUE";
      if ( !*a1 )
        v35 = L"FALSE";
      swprintf_s(Dst, SizeInWords, L"%s", v35);
      goto LABEL_69;
    case 27:
      swprintf_s(
        Dst,
        SizeInWords,
        L"%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x",
        *a1,
        *(a1 + 1),
        *(a1 + 2),
        *(a1 + 3),
        *(a1 + 4),
        *(a1 + 5),
        *(a1 + 6),
        *(a1 + 7),
        *(a1 + 8),
        *(a1 + 9),
        *(a1 + 10),
        *(a1 + 11),
        *(a1 + 12),
        *(a1 + 13),
        *(a1 + 14),
        *(a1 + 15));
      return (v7 - v36 + 16);
    default:
      goto LABEL_69;
  }
}
// 109E200: using guessed type wchar_t a0x08x[7];
// 10BE0D0: using guessed type int dword_10BE0D0;

//----- (0102D220) --------------------------------------------------------
ULONG __thiscall PE_FlushTrace(LPEVENT_TRACE_PROPERTIES_EXT Properties)
{
  return FlushTraceW(Properties->TraceHandle, 0, &Properties->baseclass);
}

//----- (0102D240) --------------------------------------------------------
int __cdecl NetworkMsgItem2_FindID(WCHAR *lpszText)
{
  int index; // esi
  int v2; // eax

  index = 0;
  while ( 1 )
  {
    v2 = wcscmp(gNetworkMsgItem2[index].szText, lpszText);
    if ( v2 )
      v2 = -(v2 < 0) | 1;
    if ( !v2 )
      break;
    if ( ++index >= 56 )
      return 0;
  }
  return gNetworkMsgItem2[index].nID;
}

//----- (0102D2B0) --------------------------------------------------------
std_Tree_node_for_tagKeyName *__cdecl sub_102D2B0(unsigned int a1)
{
  std__Tree_node *v1; // ecx
  std_Tree_node_for_tagKeyName *v2; // eax
  std_Tree_node_for_tagKeyName *result; // eax
  std__Tree_node *v4; // [esp+4h] [ebp-4h]

  v1 = gThreadProcessMap._Header;
  v2 = gThreadProcessMap._Header->_Parent;
  if ( v2->_IsNil )
    goto LABEL_14;
  do
  {
    if ( v2->_Myval.first >= a1 )
    {
      v1 = v2;
      v2 = v2->_Left;
    }
    else
    {
      v2 = v2->_Right;
    }
  }
  while ( !v2->_IsNil );
  if ( v1 == gThreadProcessMap._Header || (v4 = v1, a1 < v1[1]._Left) )
LABEL_14:
    v4 = gThreadProcessMap._Header;
  if ( v4 == gThreadProcessMap._Header )
    result = -1;
  else
    result = v4[1]._Parent;
  return result;
}

//----- (0102D310) --------------------------------------------------------
signed int __thiscall PE_RunTrace(EVENT_TRACE_PROPERTIES_EXT *PropertiesIn, char fStart)
{
  EVENT_TRACE_PROPERTIES_EXT *Properties; // ebx
  HMODULE v4; // edi
  MACRO_EVENT_TRACE_TYPE LogMode; // eax
  bool v6; // sf
  unsigned __int8 v7; // of
  const wchar_t *pszSessionName; // eax
  int EnableFlags; // eax
  int uret; // eax
  int lRet; // esi
  HANDLE v12; // ST14_4
  DWORD ThreadId; // [esp+4h] [ebp-4h]

  Properties = PropertiesIn;
  if ( PropertiesIn->fTraceStarted == fStart )
    return 0;
  if ( !PropertiesIn->ApiLoaded )
  {
    v4 = LoadLibraryW(L"advapi32.dll");
    StartTraceW_0 = GetProcAddress(v4, "StartTraceW");
    ControlTraceW_0 = GetProcAddress(v4, "ControlTraceW");
    *OpenTraceW_0 = GetProcAddress(v4, "OpenTraceW");
    *ProcessTrace_0 = GetProcAddress(v4, "ProcessTrace");
    Properties->ApiLoaded = 1;
  }
  if ( !StartTraceW_0 )
    return 1;
  LogMode = 0;
  Properties->baseclass.Wnode.BufferSize = 0x4B0;
  Properties->baseclass.Wnode.Flags = WNODE_FLAG_TRACED_GUID;
  Properties->baseclass.FlushTimer = 1;
  v7 = __OFSUB__(gdwVersion, 3);
  v6 = gdwVersion - 3 < 0;
  Properties->baseclass.Wnode.ClientContext = 1;
  if ( !(v6 ^ v7) )
    LogMode = EVENT_TRACE_FLAG_FILE_IO;
  Properties->baseclass.LogFileMode = LogMode | EVENT_TRACE_REAL_TIME_MODE;
  if ( gdwVersion < 3 )
    _mm_storeu_si128(&Properties->baseclass.Wnode.Guid, _mm_loadu_si128(&stru_10A00E0));
  Properties->baseclass.LoggerNameOffset = 120;
  Properties->baseclass.LogFileNameOffset = 640;
  pszSessionName = L"PROCEXP TRACE";
  if ( gdwVersion < 3 )
    pszSessionName = L"NT Kernel Logger";
  wcscpy_s(Properties->szSessionName, MAX_PATH, pszSessionName);
  wcscpy_s(Properties->szLogFileName, MAX_PATH, &gszNullString);
  EnableFlags = Properties->baseclass.EnableFlags | 0x10100;// EVENT_TRACE_FLAG_DISK_IO|EVENT_TRACE_FLAG_NETWORK_TCPIP
  Properties->baseclass.EnableFlags = EnableFlags;
  if ( gdwVersion >= 3 )
    Properties->baseclass.EnableFlags = EnableFlags | EVENT_TRACE_FLAG_THREAD;
  if ( fStart )
  {
    uret = StartTraceW_0(&Properties->SessionHandle, Properties->szSessionName, &Properties->baseclass);
    lRet = uret;
    if ( !uret || uret == ERROR_ALREADY_EXISTS )
    {
      Properties->fTraceStarted = 1;
      lRet = 0;
      Properties->ThreadHandle = _beginthreadex(0, 0, TraceEventThreadProcEx, Properties, 0, &ThreadId);
      if ( gdwVersion >= 3 )
      {
        ScanAllThreads();
        return 0;
      }
    }
  }
  else
  {
    SetEvent(Properties->EventHandle);
    lRet = ControlTraceW_0(
             Properties->SessionHandle,
             Properties->szSessionName,
             &Properties->baseclass,
             EVENT_TRACE_CONTROL_STOP);
    WaitForSingleObject(Properties->ThreadHandle, 0xFFFFFFFF);
    CloseHandle(Properties->ThreadHandle);
    v12 = Properties->EventHandle;
    Properties->ThreadHandle = 0;
    ResetEvent(v12);
  }
  return lRet;
}
// 10A00E0: using guessed type GUID stru_10A00E0;
// 10A0784: using guessed type wchar_t aProcexpTrace[14];
// 10C4E54: using guessed type int gdwVersion;

//----- (0102D510) --------------------------------------------------------
void __cdecl sub_102D510(EVENT_TRACE *EventTrace, EventList *Param)
{
  ULONG ThreadId; // eax
  Data_t_bstr_t *v3; // eax
  Data_t_bstr_t *v4; // esi
  EventListNode *v5; // eax
  OLECHAR *v6; // eax
  EventListNode *v7; // edi
  int v8; // esi
  const unsigned __int16 *v9; // eax
  int v10; // eax
  int v11; // eax
  UCHAR Type; // cl
  EVENT_TRACE *v13; // ecx
  EventListNode *v14; // eax
  int *v15; // ebx
  EventListNode *v16; // edi
  _bstr_t *v17; // esi
  unsigned int v18; // eax
  WCHAR *v19; // eax
  int v20; // eax
  Data_t_bstr_t *v21; // eax
  Data_t_bstr_t *v22; // esi
  int v23; // eax
  int v24; // eax
  int v25; // eax
  int v26; // eax
  int v27; // eax
  int v28; // eax
  int v29; // eax
  int v30; // eax
  unsigned int v31; // eax
  Data_t_bstr_t *v32; // eax
  Data_t_bstr_t *v33; // esi
  Data_t_bstr_t *v34; // esi
  Data_t_bstr_t *v35; // eax
  Data_t_bstr_t *v36; // esi
  Data_t_bstr_t *v37; // eax
  Data_t_bstr_t *v38; // edi
  Data_t_bstr_t *v39; // esi
  Data_t_bstr_t *v40; // esi
  __int64 v41; // [esp-8h] [ebp-894h]
  ULONG ProcessId; // [esp+14h] [ebp-878h]
  int Buffer[19]; // [esp+18h] [ebp-874h]
  _bstr_t a2a; // [esp+64h] [ebp-828h]
  EventList *ParamIn; // [esp+6Ch] [ebp-820h]
  void *v46; // [esp+70h] [ebp-81Ch]
  _bstr_t a3; // [esp+74h] [ebp-818h]
  EVENT_TRACE *EventTrace_1; // [esp+78h] [ebp-814h]
  WCHAR psz[1024]; // [esp+7Ch] [ebp-810h]
  int v50; // [esp+888h] [ebp-4h]

  EventTrace_1 = EventTrace;
  ParamIn = Param;
  memset(Buffer, 0, 76u);
  a2a.m_Data = 0;
  ProcessId = EventTrace->Header.ProcessId;
  ThreadId = EventTrace->Header.ThreadId;
  HIDWORD(v41) = 0;
  if ( ThreadId == -1 )
    ThreadId = 0;
  v50 = 0;
  Buffer[0] = ThreadId;
  LODWORD(v41) = EventTrace->Header.u4.s.KernelTime + EventTrace->Header.u4.s.UserTime;
  Buffer[1] = 1;
  *&Buffer[3] = PE_ComputeTime(&gTime, v41);
  v3 = operator new(0xCu);
  v4 = v3;
  if ( v3 )
  {
    v3->m_str = 0;
    v3->m_RefCount = 1;
    v3->m_wstr = SysAllocString(0);
  }
  else
  {
    v4 = 0;
  }
  LOBYTE(v50) = 0;
  a2a.m_Data = v4;
  if ( !v4 )
LABEL_7:
    _com_issue_error(E_OUTOFMEMORY);
  v5 = Param[4]._Myheader;
  if ( v5 && (v6 = v5->field_0) != 0 && SysStringLen(v6) )
  {
    v7 = Param[4]._Myheader;
    v8 = 0;
    Buffer[1] = 0;
    while ( 1 )
    {
      if ( v7 )
        v9 = v7->field_0;
      else
        v9 = 0;
      v10 = wcscmp(v9, gReadWriteMsgItem[v8].szText);
      if ( v10 )
        v10 = -(v10 < 0) | 1;
      if ( !v10 )
        break;
      if ( ++v8 >= 3 )
        goto LABEL_25;
    }
    v11 = gReadWriteMsgItem[v8].nID;
  }
  else
  {
    Type = EventTrace->Header.u2.Class.Type;
    if ( Type == 0xB )
    {
      Buffer[1] = 3;
      goto LABEL_25;
    }
    v11 = (Type == 10) + 1;
  }
  Buffer[1] = v11;
LABEL_25:
  v13 = EventTrace_1;
  v14 = ParamIn[3]._Myheader;
  v15 = EventTrace_1->MofData;
  v16 = v14->field_0;
  if ( v14->field_0 != v14 )
  {
    while ( v15 < v13->MofData + v13->MofLength )
    {
      v17 = v16[1].field_0;
      v18 = &v17[1].m_Data->m_wstr + 1;
      while ( 2 )
      {
        switch ( v18 )
        {
          case 0u:
            if ( v17->m_Data )
              v19 = v17->m_Data->m_wstr;
            else
              v19 = 0;
            v20 = NetworkMsgItem2_FindID(v19);
            v17[1].m_Data = v20;
            v18 = v20 + 1;
            if ( v18 > 0x15 )
              goto LABEL_33;
            continue;
          case 1u:
          case 2u:
          case 3u:
          case 4u:
          case 5u:
          case 6u:
          case 7u:
          case 8u:
          case 9u:
          case 0xAu:
          case 0xBu:
          case 0xCu:
LABEL_33:
            v13 = EventTrace_1;
            goto LABEL_34;
          case 0xDu:
            v23 = *v15;
            ++v15;
            Buffer[5] = v23;
            goto LABEL_69;
          case 0xEu:
            v24 = *v15;
            ++v15;
            Buffer[6] = v24;
            goto LABEL_69;
          case 0xFu:
            v25 = *v15;
            ++v15;
            Buffer[7] = v25;
            Buffer[8] = 0;
            goto LABEL_69;
          case 0x10u:
            v26 = *v15;
            ++v15;
            Buffer[9] = v26;
            goto LABEL_69;
          case 0x11u:
            Buffer[11] = *v15;
            v27 = v15[1];
            v15 += 2;
            Buffer[12] = v27;
            goto LABEL_69;
          case 0x12u:
            Buffer[13] = *v15;
            if ( dword_10BE0D0 == 64 )
            {
              v28 = v15[1];
              v15 += 2;
              Buffer[14] = v28;
            }
            else
            {
              Buffer[14] = 0;
              ++v15;
            }
            goto LABEL_69;
          case 0x13u:
            Buffer[15] = *v15;
            if ( dword_10BE0D0 == 64 )
            {
              v29 = v15[1];
              v15 += 2;
              Buffer[16] = v29;
            }
            else
            {
              Buffer[16] = 0;
              ++v15;
            }
            goto LABEL_69;
          case 0x14u:
            Buffer[17] = *v15;
            v30 = v15[1];
            v15 += 2;
            Buffer[18] = v30;
            goto LABEL_69;
          case 0x15u:
            v31 = *v15;
            Buffer[0] = *v15;
            if ( ProcessId == -1 )
              ProcessId = sub_102D2B0(v31);
            goto LABEL_69;
          default:
LABEL_34:
            psz[0] = 0;
            v15 = (v15 + sub_102CC70(v15, v13->MofData + v13->MofLength, v17, psz, 0x400u));
            _bstr_t::operator+=(&a2a, v17);
            v21 = operator new(0xCu);
            v46 = v21;
            LOBYTE(v50) = 2;
            if ( v21 )
              v22 = _bstr_t::Data_t::Data_t(v21, &a2a, &gNullString);
            else
              v22 = 0;
            LOBYTE(v50) = 0;
            if ( !v22 )
              goto LABEL_7;
            _bstr_t::_Free(&a2a);
            a2a.m_Data = v22;
            _bstr_t::_bstr_t(&a3, psz);
            LOBYTE(v50) = 3;
            v32 = operator new(0xCu);
            v46 = v32;
            LOBYTE(v50) = 4;
            v33 = (v32 ? _bstr_t::Data_t::Data_t(v32, &a2a, &a3) : 0);
            LOBYTE(v50) = 3;
            if ( !v33 )
              goto LABEL_7;
            _bstr_t::_Free(&a2a);
            a2a.m_Data = v33;
            v34 = a3.m_Data;
            LOBYTE(v50) = 0;
            if ( a3.m_Data )
            {
              if ( !InterlockedDecrement(&a3.m_Data->m_RefCount) )
              {
                if ( v34->m_wstr )
                {
                  SysFreeString(v34->m_wstr);
                  v34->m_wstr = 0;
                }
                if ( v34->m_str )
                {
                  j_j__free(v34->m_str);
                  v34->m_str = 0;
                }
                j__free(v34);
              }
              a3.m_Data = 0;
            }
            v35 = operator new(0xCu);
            v46 = v35;
            LOBYTE(v50) = 5;
            v36 = (v35 ? _bstr_t::Data_t::Data_t(v35, &a2a, &gNullString) : 0);
            LOBYTE(v50) = 0;
            if ( !v36 )
              goto LABEL_7;
            _bstr_t::_Free(&a2a);
            a2a.m_Data = v36;
LABEL_69:
            v16 = v16->field_0;
            v13 = EventTrace_1;
            if ( v16 == ParamIn[3]._Myheader )
              goto LABEL_70;
            break;
        }
        break;
      }
    }
  }
LABEL_70:
  v37 = operator new(0xCu);
  v46 = v37;
  LOBYTE(v50) = 6;
  if ( v37 )
    v38 = _bstr_t::Data_t::Data_t(v37, &a2a, &gNullString);
  else
    v38 = 0;
  LOBYTE(v50) = 0;
  if ( !v38 )
    _com_issue_error(E_OUTOFMEMORY);
  v39 = a2a.m_Data;
  if ( a2a.m_Data && !InterlockedDecrement(&a2a.m_Data->m_RefCount) && v39 )
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
  a2a.m_Data = v38;
  sub_1055250(&ProcessId);
  v40 = a2a.m_Data;
  if ( a2a.m_Data && !InterlockedDecrement(&a2a.m_Data->m_RefCount) && v40 )
  {
    if ( v40->m_wstr )
    {
      SysFreeString(v40->m_wstr);
      v40->m_wstr = 0;
    }
    if ( v40->m_str )
    {
      j_j__free(v40->m_str);
      v40->m_str = 0;
    }
    j__free(v40);
  }
}
// 10A06FC: using guessed type NetworkMsgItem gReadWriteMsgItem[3];
// 10BE0D0: using guessed type int dword_10BE0D0;

//----- (0102DB10) --------------------------------------------------------
void __stdcall LogEventCallback(PEVENT_TRACE EventTrace)
{
  _bstr_t *v1; // eax

  if ( EventTrace )
  {
    v1 = sub_FF8730(
           &gWbemServiceList,
           &EventTrace->Header.u3.Guid,
           EventTrace->Header.u2.Class.Type,
           EventTrace->Header.u2.Class.Version,
           EventTrace->Header.u2.Class.Level);
    if ( v1 )
      sub_102DB50(EventTrace, v1);
  }
}
