//----- (00C38790) --------------------------------------------------------
int __cdecl sub_C38790(wchar_t *Src, wchar_t *Dst)
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

//----- (00C387D0) --------------------------------------------------------
MACRO_HRESULT __stdcall CCorDebugDataTarget::OpenThread(CCorDebugDataTarget *a1, DWORD dwThreadId, int a3, int a4, CONTEXT *pContext)
{
  HANDLE v5; // edi
  HANDLE v7; // eax
  void *v8; // esi
  THREADENTRY32 te; // [esp+10h] [ebp-20h]

  v5 = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, a1->m_dwProcessId);
  if ( v5 == (HANDLE)-1 )
    return E_FAIL;
  te.dwSize = 28;
  if ( !Thread32First(v5, &te) )
    goto LABEL_6;
  while ( te.th32OwnerProcessID != a1->m_dwProcessId || te.th32ThreadID != dwThreadId )
  {
    if ( !Thread32Next(v5, &te) )
      goto LABEL_6;
  }
  v7 = OpenThread(THREAD_ALL_ACCESS, 1, dwThreadId);
  v8 = v7;
  if ( !v7 )
  {
LABEL_6:
    CloseHandle(v5);
    return E_FAIL;
  }
  if ( !GetThreadContext(v7, pContext) )
  {
    CloseHandle(v8);
    CloseHandle(v5);
    return E_FAIL;
  }
  CloseHandle(v8);
  CloseHandle(v5);
  return 0;
}

//----- (00C388A0) --------------------------------------------------------
char __thiscall sub_C388A0(const void **this, unsigned int a2)
{
  char *v2; // esi
  const void **v3; // edi
  unsigned int v4; // edx
  void *v5; // eax
  char *v7; // ecx
  void *v8; // ecx
  int v9; // eax
  const void *v10; // [esp+10h] [ebp+8h]

  v2 = (char *)a2;
  v3 = this;
  v4 = (unsigned int)this[2];
  if ( a2 > v4 )
  {
    if ( *this )
    {
      v7 = (char *)this[3];
      if ( !v7 )
      {
        v7 = (char *)(v4 >> 1);
        if ( a2 - v4 > v4 >> 1 )
          v7 = (char *)(a2 - v4);
      }
      if ( a2 < (unsigned int)&v7[v4] )
        v2 = &v7[v4];
      v8 = calloc((size_t)v2, 4u);
      v10 = v8;
      if ( !v8 )
        return 0;
      v9 = memmove_s(v8, 4 * (_DWORD)v3[1], *v3, 4 * (_DWORD)v3[1]);
      sub_C1B650(v9);
      free((void *)*v3);
      *v3 = v10;
    }
    else
    {
      if ( (unsigned int)this[3] > a2 )
        v2 = (char *)this[3];
      v5 = calloc((size_t)v2, 4u);
      *v3 = v5;
      if ( !v5 )
        return 0;
    }
    v3[2] = v2;
  }
  return 1;
}

//----- (00C38940) --------------------------------------------------------
FARPROC __thiscall sub_C38940(MixedModeStackWalker *This, int a2)
{
  MixedModeStackWalker *this; // esi
  HMODULE v3; // eax
  FARPROC CLRCreateInstance; // eax
  CCorDebugDataTarget *v5; // eax
  CCorDebugDataTarget *v6; // edi
  void *v7; // ecx
  int v8; // edx
  CCorDebugDataTarget *v9; // ecx
  CCLRDebuggingLibraryProvider *v10; // eax
  CCLRDebuggingLibraryProvider *pDebuggingLibraryProvider; // edi
  int v12; // ecx
  CCLRDebuggingLibraryProvider *v13; // ecx

  this = This;
  This->field_14 = a2;
  This->m_dwProcessId = *(_DWORD *)a2;
  This->m_hProcess = *(_DWORD *)(a2 + 0xC);
  v3 = LoadLibraryW(L"mscoree.dll");
  CLRCreateInstance = GetProcAddress(v3, "CLRCreateInstance");
  if ( CLRCreateInstance )
  {
    if ( ((int (__stdcall *)(GUID *, GUID *, int *))CLRCreateInstance)(
           &CLSID_CLRDebugging,
           &IID_ICLRDebugging,
           &this->m_ICLRDebugging) )
    {
      CLRCreateInstance = 0;
    }
    else
    {
      v5 = (CCorDebugDataTarget *)operator new(0x10u);
      v6 = v5;
      if ( v5 )
      {
        v7 = (void *)this->m_hProcess;
        v8 = this->m_dwProcessId;
        v5->vtptr = (CCorDebugDataTargetVtbl *)&CCorDebugDataTarget::`vftable';
        v5->m_nRefCount = 1;
        v5->m_hProcess = v7;
        v5->m_dwProcessId = v8;
      }
      else
      {
        v6 = 0;
      }
      v9 = this->DebugDataTarget;
      if ( v9 )
        ((void (__stdcall *)(CCorDebugDataTarget *))v9->vtptr->Release)(this->DebugDataTarget);
      this->DebugDataTarget = v6;
      v10 = (CCLRDebuggingLibraryProvider *)operator new(0xCu);
      pDebuggingLibraryProvider = v10;
      if ( v10 )
      {
        v12 = this->m_dwProcessId;
        v10->vtptr = (CCLRDebuggingLibraryProviderVtbl *)&CCLRDebuggingLibraryProvider::`vftable';
        v10->m_nRefCount = 1;
        v10->m_dwProcessId = v12;
      }
      else
      {
        pDebuggingLibraryProvider = 0;
      }
      v13 = this->DebuggingLibraryProvider;
      if ( v13 )
        ((void (__stdcall *)(CCLRDebuggingLibraryProvider *))v13->vtptr->Release)(this->DebuggingLibraryProvider);
      this->DebuggingLibraryProvider = pDebuggingLibraryProvider;
      CLRCreateInstance = (FARPROC)(sub_C39500(
                                      this,
                                      (int)this->DebugDataTarget,
                                      (CCorDebugDataTarget *)this->m_ICLRDebugging,
                                      pDebuggingLibraryProvider) == 0);
    }
  }
  return CLRCreateInstance;
}
// CAF3DC: using guessed type GUID IID_ICLRDebugging;
// CAF3EC: using guessed type GUID CLSID_CLRDebugging;
// CAF440: using guessed type void *CCorDebugDataTarget::`vftable';
// CAF45C: using guessed type void *CCLRDebuggingLibraryProvider::`vftable';

//----- (00C38A30) --------------------------------------------------------
int __thiscall sub_C38A30(_DWORD *this, int a2, int a3, int a4, int a5)
{
  _DWORD *v5; // esi
  wchar_t *v6; // ST00_4
  int result; // eax

  v5 = this;
  if ( a2 )
  {
    v6 = (wchar_t *)this[7];
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

//----- (00C38A90) --------------------------------------------------------
int __thiscall sub_C38A90(_DWORD *this, int a2, int a3, int a4, int a5)
{
  _DWORD *v5; // esi
  wchar_t *v6; // ST00_4
  int result; // eax

  v5 = this;
  if ( a2 )
  {
    v6 = (wchar_t *)this[7];
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

//----- (00C38AE0) --------------------------------------------------------
void __thiscall sub_C38AE0(int *this, unsigned int a2, int *a3, unsigned int a4)
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
      if ( !sub_C39B80((int)this, a2 + a4, -1) )
        ATL::AtlThrowImpl(-2147024882);
      goto LABEL_16;
    }
LABEL_5:
    ATL::AtlThrowImpl(-2147024362);
  }
  v20 = v5;
  if ( -1 - v5 < a4 )
    goto LABEL_5;
  if ( !sub_C39B80((int)this, v5 + a4, -1) )
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
      v11 = *(_DWORD *)(v10 + 4 * v8);
      if ( v11 )
      {
        (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v11 + 8))(*(_DWORD *)(v10 + 4 * v8));
        v9 = a4;
      }
      ++v8;
    }
    while ( v8 < v9 );
    v4 = v21;
  }
  v12 = *v4;
  v13 = (const void *)(*v4 + 4 * a2);
  v23 -= a2;
  v22 = a2 + a4;
  v14 = memmove_s((void *)(v12 + 4 * (a2 + a4)), 4 * v23, v13, 4 * v23);
  sub_C1B650(v14);
  v15 = (_DWORD *)(4 * a2 + *v4);
  v25 = 0;
  sub_C379A0(v15, a4);
  v25 = -1;
LABEL_16:
  if ( a2 < v22 )
  {
    do
    {
      v16 = (int *)(*v4 + 4 * v6);
      v17 = *a3;
      if ( *v16 != *a3 )
      {
        if ( v17 )
          (*(void (__stdcall **)(int))(*(_DWORD *)v17 + 4))(*a3);
        v18 = *v16;
        *v16 = v17;
        if ( v18 )
          (*(void (__stdcall **)(int))(*(_DWORD *)v18 + 8))(v18);
      }
      v4 = v21;
      ++v6;
    }
    while ( v6 < v22 );
  }
}
// C781AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);

//----- (00C38C80) --------------------------------------------------------
int (__stdcall ***__stdcall sub_C38C80(int (__stdcall ***a1)(_DWORD, GUID *, int *)))(_DWORD, GUID *, int *)
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
    v2 = (**a1)(a1, &IID_ICorDebugInternalFrame, (int *)&v7);
    v1 = v7;
    if ( v2 < 0 )
      v1 = 0;
    v7 = v1;
  }
  v3 = *v1;
  v8 = 0;
  v4 = (*(int (__stdcall **)(_DWORD *, int (__stdcall ****)(_DWORD, GUID *, int *)))(v3 + 44))(v1, &a1);
  v5 = a1;
  v8 = -1;
  if ( v4 )
    v5 = 0;
  if ( v7 )
    (*(void (__stdcall **)(_DWORD *))(*v7 + 8))(v7);
  return v5;
}
// CAFBC8: using guessed type GUID IID_ICorDebugInternalFrame;

//----- (00C38D10) --------------------------------------------------------
signed int __thiscall sub_C38D10(MixedModeStackWalker *this, int a2)
{
  int v2; // ST08_4
  int v3; // esi
  signed int v4; // esi
  int v6; // [esp+8h] [ebp-18h]
  int v7; // [esp+Ch] [ebp-14h]
  int v8; // [esp+10h] [ebp-10h]
  int v9; // [esp+1Ch] [ebp-4h]

  v8 = 0;
  v2 = this->field_1C;
  v9 = 0;
  if ( !(*(int (__stdcall **)(int, int *))(*(_DWORD *)v2 + 28))(v2, &v8) )
  {
    v7 = 0;
    if ( !(*(int (__stdcall **)(int, signed int, int *, int *))(*(_DWORD *)v8 + 28))(v8, 1, &v6, &v7) )
    {
      v3 = a2;
      do
      {
        a2 = 0;
        if ( (*(int (__stdcall **)(int, int *))(*(_DWORD *)v6 + 16))(v6, &a2) )
          break;
        if ( a2 == v3 )
        {
          v4 = 1;
          goto LABEL_8;
        }
      }
      while ( !(*(int (__stdcall **)(int, signed int, int *, int *))(*(_DWORD *)v8 + 28))(v8, 1, &v6, &v7) );
    }
  }
  v4 = 0;
LABEL_8:
  v9 = -1;
  if ( v8 )
    (*(void (__stdcall **)(int))(*(_DWORD *)v8 + 8))(v8);
  return v4;
}

//----- (00C38DE0) --------------------------------------------------------
BOOL __cdecl sub_C38DE0(int a1)
{
  return !(*(int (__stdcall **)(int, int *))(*(_DWORD *)a1 + 44))(a1, &a1)
      && (a1 == 6 || a1 == 7 || a1 == 8 || a1 == 9 || a1 == 10);
}

//----- (00C38E20) --------------------------------------------------------
int __userpurge sub_C38E20@<eax>(MixedModeStackWalker *this@<ecx>, __int128 _XMM0@<xmm0>, int a2, int a3, int *a4, _DWORD *a5, _DWORD *a6, int a7, unsigned int a8, unsigned int *a9)
{
  int v10; // edx
  bool v11; // zf
  int (__stdcall ***v12)(_DWORD, GUID *, int *); // eax
  int v13; // eax
  int v14; // esi
  unsigned int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // esi
  int v20; // eax
  unsigned int v21; // eax
  int v22; // ecx
  int v23; // eax
  unsigned int v24; // edi
  unsigned int v25; // ebx
  int v26; // eax
  int v27; // [esp+10h] [ebp-5E4h]
  __int64 v28; // [esp+14h] [ebp-5E0h]
  __int64 v29; // [esp+1Ch] [ebp-5D8h]
  int v30; // [esp+24h] [ebp-5D0h]
  int *v31; // [esp+28h] [ebp-5CCh]
  __int64 v32; // [esp+2Ch] [ebp-5C8h]
  int *v33; // [esp+34h] [ebp-5C0h]
  _DWORD *v34; // [esp+38h] [ebp-5BCh]
  _DWORD *v35; // [esp+3Ch] [ebp-5B8h]
  int (__stdcall ***v36)(_DWORD, GUID *, int *); // [esp+40h] [ebp-5B4h]
  MixedModeStackWalker *This; // [esp+44h] [ebp-5B0h]
  int v38; // [esp+48h] [ebp-5ACh]
  int v39; // [esp+4Ch] [ebp-5A8h]
  int v40[49]; // [esp+318h] [ebp-2DCh]
  int v41[130]; // [esp+3DCh] [ebp-218h]
  int v42; // [esp+5F0h] [ebp-4h]

  This = this;
  v10 = a3;
  v11 = *a5 == 1;
  HIDWORD(v29) = a2;
  v31 = a4;
  v38 = a3;
  v30 = a7;
  if ( v11 )
    return 0;
  v11 = *a6 == 1;
  v32 = 0i64;
  if ( !v11 )
  {
    *a6 = 1;
    HIDWORD(v32) = 1;
    goto LABEL_29;
  }
  if ( *v31 )
  {
    if ( sub_C37DD0((int (__stdcall ***)(_DWORD, GUID *, int *))*v31) == 1 )
    {
      if ( *a9 < a8 )
        ++*a9;
      v12 = sub_C38C80((int (__stdcall ***)(_DWORD, GUID *, int *))*v31);
      v10 = v38;
      if ( v12 == (int (__stdcall ***)(_DWORD, GUID *, int *))5 )
        LODWORD(v32) = 1;
      goto LABEL_29;
    }
    v10 = v38;
  }
  v13 = (*(int (__stdcall **)(int))(*(_DWORD *)v10 + 20))(v10);
  if ( v13 == 1250084 )
  {
    *a5 = 1;
    goto LABEL_12;
  }
  if ( v13 < 0 )
    _CxxThrowException(0, 0);
  v10 = v38;
LABEL_29:
  if ( *a5 )
  {
LABEL_12:
    if ( *a9 < a8 )
    {
      v14 = v30;
      while ( 1 )
      {
        v35 = 0;
        v15 = *a9;
        v42 = 8;
        v11 = (***(int (__stdcall ****)(_DWORD, GUID *, int *))(v14 + 4 * v15))(
                *(_DWORD *)(v14 + 4 * v15),
                &IID_ICorDebugInternalFrame,
                (int *)&v35) == 0;
        v16 = (int)v35;
        if ( !v11 )
          break;
        if ( (*(int (__stdcall **)(_DWORD *, char *))(*v35 + 44))(v35, (char *)&v32 + 4)
          || HIDWORD(v32) != 6 && HIDWORD(v32) != 7 && HIDWORD(v32) != 8 && HIDWORD(v32) != 9 && HIDWORD(v32) != 10 )
        {
          *v31 = *(_DWORD *)(v14 + 4 * *a9);
          v26 = (int)v35;
          goto LABEL_95;
        }
        v42 = -1;
        if ( v35 )
          (*(void (__stdcall **)(_DWORD *))(*v35 + 8))(v35);
        if ( ++*a9 >= a8 )
          return 0;
      }
LABEL_45:
      v42 = -1;
      if ( v16 )
        (*(void (__stdcall **)(int))(*(_DWORD *)v16 + 8))(v16);
    }
    return 0;
  }
  v34 = 0;
  v17 = *(_DWORD *)v10;
  v42 = 0;
  (*(void (__stdcall **)(int, _DWORD **))(v17 + 24))(v10, &v34);
  v18 = (int)v34;
  if ( !v34 )
  {
    *v31 = (int)v34;
    return v18 + 1;
  }
  v20 = *v34;
  v35 = v34;
  (*(void (__stdcall **)(_DWORD *))(v20 + 4))(v34);
  if ( *a9 >= a8 )
    goto LABEL_92;
  while ( 1 )
  {
    v36 = 0;
    v21 = *a9;
    LOBYTE(v42) = 2;
    if ( (***(int (__stdcall ****)(_DWORD, GUID *, _DWORD))(v30 + 4 * v21))(
           *(_DWORD *)(v30 + 4 * v21),
           &IID_ICorDebugInternalFrame,
           &v36) )
    {
      goto LABEL_42;
    }
    if ( !sub_C38DE0((int)v36) )
      break;
    LOBYTE(v42) = 1;
    if ( v36 )
      ((void (__stdcall *)(int (__stdcall ***)(_DWORD, GUID *, int *)))(*v36)[2])(v36);
    if ( ++*a9 >= a8 )
      goto LABEL_92;
  }
  sub_C37520(&v33, v36);
  v22 = *v33;
  LOBYTE(v42) = 3;
  if ( (*(int (__stdcall **)(int *, int, int *))(v22 + 16))(v33, v18, &v27) )
  {
LABEL_40:
    LOBYTE(v42) = 2;
    if ( v33 )
      (*(void (__stdcall **)(int *))(*v33 + 8))(v33);
LABEL_42:
    LOBYTE(v42) = 1;
    if ( v36 )
      ((void (__stdcall *)(int (__stdcall ***)(_DWORD, GUID *, int *)))(*v36)[2])(v36);
    v23 = *(_DWORD *)v18;
    LOBYTE(v42) = 0;
    (*(void (__stdcall **)(int))(v23 + 8))(v18);
    v16 = (int)v34;
    goto LABEL_45;
  }
  if ( !v27 )
  {
    if ( sub_C38C80(v36) != (int (__stdcall ***)(_DWORD, GUID *, int *))1 )
      goto LABEL_88;
    memset(&v39, 0, 0x2CCu);
    v39 = 0x10003;
    if ( (*(int (__stdcall **)(int, signed int, signed int, int *, int *))(*(_DWORD *)v38 + 12))(
           v38,
           0x10003,
           716,
           &v30,
           &v39) )
    {
      goto LABEL_40;
    }
    v38 = 0;
    LOBYTE(v42) = 4;
    if ( (*(int (__stdcall **)(_DWORD, int *))(*(_DWORD *)HIDWORD(v29) + 12))(HIDWORD(v29), &v38) )
    {
LABEL_54:
      LOBYTE(v42) = 3;
      if ( v38 )
        (*(void (__stdcall **)(int))(*(_DWORD *)v38 + 8))(v38);
      goto LABEL_40;
    }
    if ( (_DWORD)v32 == 1 || HIDWORD(v32) == 1 )
      (*(void (__stdcall **)(int, signed int, signed int, int *))(*(_DWORD *)v38 + 16))(v38, 1, 716, &v39);
    else
      (*(void (__stdcall **)(int, signed int, signed int, int *))(*(_DWORD *)v38 + 16))(v38, 2, 716, &v39);
    This = 0;
    v29 = 0i64;
    v28 = 0i64;
    LOBYTE(v42) = 5;
    if ( (*(int (__stdcall **)(int, MixedModeStackWalker **))(*(_DWORD *)v38 + 24))(v38, &This) )
    {
      v32 = __PAIR__(v29, HIDWORD(v29));
    }
    else
    {
      memset(v40, 0, 0x2CCu);
      v40[0] = 65539;
      if ( (*(int (__stdcall **)(int, signed int, signed int, char *, int *))(*(_DWORD *)v38 + 12))(
             v38,
             65539,
             716,
             (char *)&v29 + 4,
             v40) )
      {
        goto LABEL_62;
      }
      HIDWORD(v32) = v41[0];
      LODWORD(v32) = 0;
    }
    LOBYTE(v42) = 4;
    if ( This )
      This->vtptr->Release((IUnknown *)This);
    if ( (*(int (__stdcall **)(int))(*(_DWORD *)v38 + 20))(v38) )
    {
      v25 = HIDWORD(v28);
      v24 = v28;
    }
    else
    {
      This = 0;
      LOBYTE(v42) = 6;
      if ( (*(int (__stdcall **)(int, MixedModeStackWalker **))(*(_DWORD *)v38 + 24))(v38, &This) )
      {
        v25 = HIDWORD(v28);
        v24 = v28;
      }
      else
      {
        memset(v40, 0, 0x2CCu);
        v40[0] = 65539;
        if ( (*(int (__stdcall **)(int, signed int, signed int, char *, int *))(*(_DWORD *)v38 + 12))(
               v38,
               65539,
               716,
               (char *)&v29 + 4,
               v40) )
        {
          goto LABEL_62;
        }
        v24 = v41[0];
        v25 = 0;
      }
      LOBYTE(v42) = 4;
      if ( This )
        This->vtptr->Release((IUnknown *)This);
    }
    if ( !v32 || !(v25 | v24) || (unsigned int)v32 > v25 || (unsigned int)v32 >= v25 && HIDWORD(v32) >= v24 )
    {
LABEL_86:
      LOBYTE(v42) = 3;
      if ( v38 )
        (*(void (__stdcall **)(int))(*(_DWORD *)v38 + 8))(v38);
      goto LABEL_88;
    }
    This = 0;
    LOBYTE(v42) = 7;
    (*(void (__stdcall **)(int, MixedModeStackWalker **))(*(_DWORD *)v38 + 24))(v38, &This);
    if ( !(*(int (__stdcall **)(int *, MixedModeStackWalker *, char *))(*v33 + 16))(v33, This, (char *)&v29 + 4) )
    {
      if ( HIDWORD(v29) )
      {
        sub_C37600(&v35, (int)v36);
        v18 = (int)v35;
      }
      LOBYTE(v42) = 4;
      if ( This )
        This->vtptr->Release((IUnknown *)This);
      goto LABEL_86;
    }
LABEL_62:
    LOBYTE(v42) = 4;
    if ( This )
      This->vtptr->Release((IUnknown *)This);
    goto LABEL_54;
  }
  sub_C37600(&v35, *(_DWORD *)(v30 + 4 * *a9));
  v18 = (int)v35;
LABEL_88:
  LOBYTE(v42) = 2;
  if ( v33 )
    (*(void (__stdcall **)(int *))(*v33 + 8))(v33);
  LOBYTE(v42) = 1;
  if ( v36 )
    ((void (__stdcall *)(int (__stdcall ***)(_DWORD, GUID *, int *)))(*v36)[2])(v36);
LABEL_92:
  LOBYTE(v42) = 0;
  *v31 = v18;
  if ( v18 )
    (*(void (__stdcall **)(int))(*(_DWORD *)v18 + 8))(v18);
  v26 = (int)v34;
LABEL_95:
  v42 = -1;
  if ( v26 )
    (*(void (__stdcall **)(int))(*(_DWORD *)v26 + 8))(v26);
  return 1;
}
// C781AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);
// CAFBC8: using guessed type GUID IID_ICorDebugInternalFrame;

//----- (00C39500) --------------------------------------------------------
MACRO_HRESULT __thiscall sub_C39500(MixedModeStackWalker *this, int a2, CCorDebugDataTarget *pDebugDataTarget, CCLRDebuggingLibraryProvider *pDebuggingLibraryProvider)
{
  MixedModeStackWalker *pThis; // edi
  int dwProcessId; // ST24_4
  HANDLE v6; // esi
  char v8; // [esp+14h] [ebp-45Ch]
  int thisa; // [esp+18h] [ebp-458h]
  CCLRDebuggingLibraryProvider *This; // [esp+1Ch] [ebp-454h]
  MODULEENTRY32W me; // [esp+20h] [ebp-450h]
  __int16 v12; // [esp+448h] [ebp-28h]
  __int16 v13; // [esp+454h] [ebp-1Ch]
  int v14; // [esp+456h] [ebp-1Ah]
  int v15; // [esp+45Ah] [ebp-16h]
  int v16; // [esp+46Ch] [ebp-4h]

  pThis = this;
  thisa = a2;
  This = pDebuggingLibraryProvider;
  v14 = 4;
  v15 = -1;
  v13 = 0;
  dwProcessId = this->m_dwProcessId;
  v16 = 0;
  v12 = 0;
  v6 = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, dwProcessId);
  if ( v6 == (HANDLE)-1 )
    return E_FAIL;
  me.dwSize = sizeof(MODULEENTRY32W);
  if ( !Module32FirstW(v6, &me) )
  {
LABEL_6:
    CloseHandle(v6);
    return E_FAIL;
  }
  while ( me.th32ProcessID != pThis->m_dwProcessId
       || ((int (__stdcall *)(CCorDebugDataTarget *, BYTE *, _DWORD, int, CCLRDebuggingLibraryProvider *, __int16 *, GUID *, int *, __int16 *, char *))pDebugDataTarget->vtptr->field_C)(
            pDebugDataTarget,
            me.modBaseAddr,
            (_DWORD)me.modBaseAddr >> 31,
            thisa,
            This,
            &v13,
            &IID_ICorDebugProcess,
            &pThis->field_1C,
            &v12,
            &v8) )
  {
    if ( !Module32NextW(v6, &me) )
      goto LABEL_6;
  }
  CloseHandle(v6);
  return 0;
}
// CAFBA8: using guessed type GUID IID_ICorDebugProcess;

//----- (00C39620) --------------------------------------------------------
int __stdcall CCLRDebuggingLibraryProvider::Load(CCLRDebuggingLibraryProvider *a1, int a2, int a3, int a4, HMODULE *phModule)
{
  signed int v5; // edi
  HANDLE hFound; // ebx
  int v7; // eax
  int v8; // edi
  int v9; // eax
  HMODULE v11; // eax
  MODULEENTRY32W me; // [esp+10h] [ebp-638h]
  __int16 szFileName[262]; // [esp+438h] [ebp-210h]

  v5 = 0;
  hFound = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, a1->m_dwProcessId);
  if ( hFound != (HANDLE)-1 )
  {
    me.dwSize = 1064;
    if ( Module32FirstW(hFound, &me) )
    {
      while ( 1 )
      {
        if ( me.th32ProcessID == a1->m_dwProcessId )
        {
          v7 = wcscmp(L"clr.dll", me.szModule);
          if ( v7 )
            v7 = -(v7 < 0) | 1;
          if ( !v7 )
            break;
        }
        if ( !Module32NextW(hFound, &me) )
          goto LABEL_11;
      }
      v8 = lstrlenW(me.szExePath);
      v9 = lstrlenW(me.szModule);
      wcsncpy_s_0((WCHAR *)szFileName, 0x105u, me.szExePath, v8 - v9);
      v5 = 1;
LABEL_11:
      CloseHandle(hFound);
      if ( !v5 )
        return E_FAIL;
      wcsncat_s((WCHAR *)szFileName, 0x105u, (LPCWSTR)a2);
      v11 = LoadLibraryExW((LPCWSTR)szFileName, 0, LOAD_WITH_ALTERED_SEARCH_PATH);
      if ( !v11 )
        return E_FAIL;
      *phModule = v11;
    }
    else
    {
      CloseHandle(hFound);
    }
  }
  return 0;
}

//----- (00C39780) --------------------------------------------------------
signed int __stdcall CCLRDebuggingLibraryProvider::QueryInterface(int a1, _DWORD *a2, _DWORD *a3)
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
    v5 = (GUID *)((char *)v5 + 4);
    v7 = v6 < 4;
    v6 -= 4;
    if ( v7 )
    {
      *a3 = a1;
      return 0;
    }
  }
  v9 = &IID_CLRDebuggingLibraryProvider;
  v10 = 12;
  while ( *v3 == v9->Data1 )
  {
    ++v3;
    v9 = (GUID *)((char *)v9 + 4);
    v7 = v10 < 4;
    v10 -= 4;
    if ( v7 )
    {
      *a3 = a1;
      (*(void (__fastcall **)(int, GUID *, int))(*(_DWORD *)a1 + 4))(a1, v9, a1);
      return 0;
    }
  }
  return -2147467262;
}
// CAF3FC: using guessed type GUID IID_CLRDebuggingLibraryProvider;
// CB7BBC: using guessed type GUID CLSID_IUnknown;

//----- (00C39800) --------------------------------------------------------
signed int __stdcall CCorDebugDataTarget::QueryInterface(int a1, _DWORD *a2, _DWORD *a3)
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
    v5 = (GUID *)((char *)v5 + 4);
    v7 = v6 < 4;
    v6 -= 4;
    if ( v7 )
    {
      *a3 = a1;
      return 0;
    }
  }
  v9 = &IID_CCorDebugDataTarget;
  v10 = 12;
  while ( *v3 == v9->Data1 )
  {
    ++v3;
    v9 = (GUID *)((char *)v9 + 4);
    v7 = v10 < 4;
    v10 -= 4;
    if ( v7 )
    {
      *a3 = a1;
      (*(void (__fastcall **)(int, GUID *, int))(*(_DWORD *)a1 + 4))(a1, v9, a1);
      return 0;
    }
  }
  return -2147467262;
}
// CAFB98: using guessed type GUID IID_CCorDebugDataTarget;
// CB7BBC: using guessed type GUID CLSID_IUnknown;

//----- (00C39880) --------------------------------------------------------
MACRO_HRESULT __stdcall MixedModeStackWalker::QueryInterface(int a1, _DWORD *a2, _DWORD *a3)
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
    v4 = (GUID *)((char *)v4 + 4);
    v6 = v5 < 4;
    v5 -= 4;
    if ( v6 )
    {
      *a3 = a1;
      (*(void (__fastcall **)(int, GUID *, int))(*(_DWORD *)a1 + 4))(a1, v4, a1);
      return 0;
    }
  }
  return E_NOINTERFACE;
}
// CB7BBC: using guessed type GUID CLSID_IUnknown;

//----- (00C398D0) --------------------------------------------------------
MACRO_HRESULT __stdcall SymbolInfo::QueryInterface(int a1, int a2, int a3)
{
  return E_NOINTERFACE;
}

//----- (00C398E0) --------------------------------------------------------
unsigned int __stdcall CCorDebugDataTarget::ReadMemory(CCorDebugDataTarget *a1, LPCVOID lpBaseAddress, int a3, LPVOID lpBuffer, SIZE_T nSize, SIZE_T *lpNumberOfBytesRead)
{
  return ReadProcessMemory(a1->m_hProcess, lpBaseAddress, lpBuffer, nSize, lpNumberOfBytesRead) != 1 ? (unsigned int)E_FAIL : 0;
}

//----- (00C39910) --------------------------------------------------------
int __stdcall CCorDebugDataTarget::Release(void *a1)
{
  bool v1; // zf

  v1 = (*((_DWORD *)a1 + 1))-- == 1;
  if ( !v1 )
    return *((_DWORD *)a1 + 1);
  operator delete(a1);
  return 0;
}

//----- (00C39940) --------------------------------------------------------
int __stdcall MixedModeStackWalker::Release(_DWORD *a1)
{
  bool v1; // zf
  int result; // eax

  v1 = a1[1]-- == 1;
  result = a1[1];
  if ( v1 )
  {
    (*(void (__stdcall **)(signed int))(*a1 + 12))(1);
    result = 0;
  }
  return result;
}

//----- (00C39960) --------------------------------------------------------
int __stdcall NativeFrame::Release(void *a1)
{
  bool v1; // zf
  void *v2; // eax

  v1 = (*((_DWORD *)a1 + 1))-- == 1;
  if ( !v1 )
    return *((_DWORD *)a1 + 1);
  v2 = (void *)*((_DWORD *)a1 + 6);
  *(_DWORD *)a1 = &NativeFrame::`vftable';
  if ( v2 )
  {
    operator delete(v2);
    *((_DWORD *)a1 + 6) = 0;
  }
  operator delete(a1);
  return 0;
}
// CAF430: using guessed type void *NativeFrame::`vftable';

//----- (00C399B0) --------------------------------------------------------
int __stdcall SymbolInfo::Release(void *a1)
{
  bool v1; // zf
  void *v2; // eax

  v1 = (*((_DWORD *)a1 + 1))-- == 1;
  if ( !v1 )
    return *((_DWORD *)a1 + 1);
  v2 = (void *)*((_DWORD *)a1 + 7);
  *(_DWORD *)a1 = &SymbolInfo::`vftable';
  if ( v2 )
  {
    operator delete(v2);
    *((_DWORD *)a1 + 7) = 0;
  }
  operator delete(a1);
  return 0;
}
// CAF420: using guessed type void *SymbolInfo::`vftable';

//----- (00C39A00) --------------------------------------------------------
int __cdecl sub_C39A00(void *Dst, void *Src, int a3)
{
  int v3; // eax

  v3 = memmove_s(Dst, 4 * a3, Src, 4 * a3);
  return sub_C1B650(v3);
}

//----- (00C39A30) --------------------------------------------------------
_DWORD *__thiscall sub_C39A30(int this)
{
  _DWORD *v1; // esi
  _DWORD *v2; // edi
  int v3; // ecx
  bool v4; // zf
  _DWORD *result; // eax
  _DWORD *v6; // edi

  v1 = (_DWORD *)this;
  while ( v1[2] )
  {
    v2 = (_DWORD *)*v1;
    if ( !*v1 )
      ATL::AtlThrowImpl(-2147467259);
    *v1 = *v2;
    v3 = v2[2];
    if ( v3 )
      (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v3 + 8))(v2[2]);
    *v2 = v1[4];
    v4 = v1[2]-- == 1;
    v1[4] = v2;
    if ( v4 )
      sub_C39A30((int)v1);
  }
  result = (_DWORD *)v1[3];
  *v1 = 0;
  v1[1] = 0;
  v1[4] = 0;
  if ( result )
  {
    do
    {
      v6 = (_DWORD *)*result;
      free(result);
      result = v6;
    }
    while ( v6 );
    v1[3] = 0;
  }
  return result;
}

//----- (00C39AC0) --------------------------------------------------------
_DWORD *__thiscall sub_C39AC0(int *this, _DWORD *a2)
{
  int *v2; // esi
  int *v3; // edi
  int v4; // ecx
  int v5; // eax
  int v6; // ecx
  bool v7; // zf

  v2 = this;
  v3 = (int *)*this;
  if ( !*this )
    ATL::AtlThrowImpl(-2147467259);
  v4 = v3[2];
  *a2 = v4;
  if ( v4 )
    (*(void (__stdcall **)(int))(*(_DWORD *)v4 + 4))(v4);
  v5 = *v3;
  *v2 = *v3;
  if ( v5 )
    *(_DWORD *)(v5 + 4) = 0;
  else
    v2[1] = 0;
  v6 = v3[2];
  if ( v6 )
    (*(void (__stdcall **)(int))(*(_DWORD *)v6 + 8))(v3[2]);
  *v3 = v2[4];
  v7 = v2[2]-- == 1;
  v2[4] = (int)v3;
  if ( v7 )
    sub_C39A30((int)v2);
  return a2;
}

//----- (00C39B40) --------------------------------------------------------
int __stdcall PE_ResumeThreadById(DWORD dwThreadId)
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

//----- (00C39B80) --------------------------------------------------------
char __thiscall sub_C39B80(int this, unsigned int a2, int a3)
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
    *(_DWORD *)(this + 12) = a3;
  v4 = a2;
  if ( a2 )
  {
    if ( a2 > *(_DWORD *)(this + 8) )
    {
      result = sub_C388A0((const void **)this, a2);
      if ( !result )
        return result;
      v9 = *(_DWORD *)(v3 + 4);
    }
    else
    {
      v9 = *(_DWORD *)(this + 4);
      if ( v9 >= a2 )
      {
        if ( v9 > a2 )
        {
          sub_C379D0(*(_DWORD *)v3 + 4 * a2, v9 - a2);
          *(_DWORD *)(v3 + 4) = a2;
          return 1;
        }
        goto LABEL_18;
      }
    }
    sub_C379A0((_DWORD *)(*(_DWORD *)v3 + 4 * v9), a2 - v9);
LABEL_18:
    *(_DWORD *)(v3 + 4) = a2;
    return 1;
  }
  v5 = *(_DWORD *)this;
  if ( *(_DWORD *)this )
  {
    v6 = *(_DWORD *)(this + 4);
    v10 = v6;
    if ( v6 )
    {
      do
      {
        v7 = *(_DWORD *)(v5 + 4 * v4);
        if ( v7 )
        {
          (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v7 + 8))(*(_DWORD *)(v5 + 4 * v4));
          v6 = v10;
        }
        ++v4;
      }
      while ( v4 < v6 );
    }
    free(*(void **)v3);
    *(_DWORD *)v3 = 0;
  }
  *(_DWORD *)(v3 + 4) = 0;
  result = 1;
  *(_DWORD *)(v3 + 8) = 0;
  return result;
}

//----- (00C39C50) --------------------------------------------------------
int __thiscall sub_C39C50(_DWORD *this, int a2, int a3, int a4)
{
  SymbolInfo *v4; // edi
  int v5; // ebx
  int result; // eax
  SymbolInfo *v7; // ecx
  SymbolInfo *v8; // esi
  SymbolInfo *v9; // eax
  SymbolInfo *v10; // edi
  unsigned int v11; // eax
  SymbolInfo *v12; // eax
  SymbolInfo *pSymbolInfo; // edi
  _DWORD *v14; // esi
  int v15; // ecx
  wchar_t *v16; // ST00_4
  SymbolInfo *v17; // eax
  SymbolInfo **v18; // eax
  SymbolInfoVtbl *v19; // eax
  int v20; // eax
  int *v21; // ecx
  SymbolInfo *v22; // esi
  bool v23; // zf
  int v24; // edi
  SymbolInfoVtbl *v25; // eax
  SymbolInfo *v26; // eax
  SymbolInfo *v27; // ebx
  _DWORD *v28; // ecx
  void *v29; // eax
  SymbolInfo **v30; // eax
  int *v31; // eax
  SymbolInfo *v32; // ecx
  SymbolInfo *v33; // eax
  SymbolInfo *v34; // eax
  SymbolInfo *v35; // ebx
  int v36; // ecx
  wchar_t *v37; // ST00_4
  SymbolInfo *v38; // eax
  SymbolInfo **v39; // eax
  SymbolInfo *v40; // ecx
  SymbolInfo *v41; // ecx
  int v42; // eax
  int *v43; // ecx
  int (__stdcall ***v44)(_DWORD, GUID *, int *); // edi
  SymbolInfo *v45; // eax
  void *v46; // eax
  SymbolInfo *v47; // ecx
  SymbolInfo *v48; // eax
  void *v49; // eax
  SymbolInfo *v50; // ecx
  unsigned __int64 v51; // [esp+10h] [ebp-103Ch]
  SymbolInfo *v52; // [esp+18h] [ebp-1034h]
  int (__stdcall ***v53)(_DWORD, GUID *, int *); // [esp+1Ch] [ebp-1030h]
  SymbolInfo *v54; // [esp+20h] [ebp-102Ch]
  SymbolInfoVtbl **v55; // [esp+24h] [ebp-1028h]
  int *v56; // [esp+28h] [ebp-1024h]
  SymbolInfo *v57; // [esp+2Ch] [ebp-1020h]
  void *v58; // [esp+30h] [ebp-101Ch]
  int v59; // [esp+34h] [ebp-1018h]
  SymbolInfo *pICorDebugInternalFrame2; // [esp+38h] [ebp-1014h]
  wchar_t v61; // [esp+3Ch] [ebp-1010h]
  wchar_t Dst; // [esp+83Ch] [ebp-810h]
  int v63; // [esp+1048h] [ebp-4h]

  v55 = (SymbolInfoVtbl **)this;
  v4 = (SymbolInfo *)a3;
  v5 = a4;
  v54 = (SymbolInfo *)a3;
  result = *(_DWORD *)(a3 + 8);
  v59 = a4;
  if ( !result )
  {
    if ( *(_DWORD *)(a2 + 8) )
    {
      if ( *(_DWORD *)(a2 + 8) > 0u )
      {
        v7 = *(SymbolInfo **)a2;
        if ( *(_DWORD *)a2 )
        {
          while ( v7 )
          {
            v8 = (SymbolInfo *)v7->field_8;
            pICorDebugInternalFrame2 = (SymbolInfo *)v7->vtptr;
            v57 = v8;
            if ( v8 )
              ((void (__stdcall *)(SymbolInfo *))v8->vtptr->AddRef)(v8);
            v63 = 0;
            v54 = 0;
            v9 = (SymbolInfo *)operator new(0x20u);
            v10 = v9;
            v52 = v9;
            LOBYTE(v63) = 2;
            if ( v9 )
            {
              v9->vtptr = (SymbolInfoVtbl *)&SymbolInfo::`vftable';
              v9->m_nRefCount = 1;
              v9->pszText = (int)operator new[](0x800u);
            }
            else
            {
              v10 = 0;
            }
            LOBYTE(v63) = 1;
            v54 = v10;
            result = sub_C380C0(v8, v10);
            if ( result )
            {
              v11 = *(_DWORD *)(a4 + 4);
              v59 = v11;
              if ( v11 >= *(_DWORD *)(a4 + 8) && !sub_C388A0((const void **)a4, v11 + 1) )
                goto LABEL_24;
              result = *(_DWORD *)a4 + 4 * v59;
              if ( result )
              {
                *(_DWORD *)result = v10;
                if ( v10 )
                  result = ((int (__stdcall *)(SymbolInfo *))v10->vtptr->AddRef)(v10);
              }
              ++*(_DWORD *)(a4 + 4);
            }
            LOBYTE(v63) = 0;
            if ( v10 )
              result = ((int (__stdcall *)(SymbolInfo *))v10->vtptr->Release)(v10);
            v63 = -1;
            if ( v8 )
              result = ((int (__stdcall *)(SymbolInfo *))v8->vtptr->Release)(v8);
            v7 = pICorDebugInternalFrame2;
            if ( !pICorDebugInternalFrame2 )
              return result;
          }
          goto LABEL_41;
        }
      }
    }
    return result;
  }
  if ( !*(_DWORD *)(a2 + 8) )
  {
    while ( 1 )
    {
      sub_C39AC0((int *)v4, &v59);
      v63 = 3;
      v55 = 0;
      LOBYTE(v63) = 4;
      v12 = (SymbolInfo *)operator new(0x20u);
      pSymbolInfo = v12;
      v57 = v12;
      LOBYTE(v63) = 5;
      if ( v12 )
      {
        v12->vtptr = (SymbolInfoVtbl *)&SymbolInfo::`vftable';
        v12->m_nRefCount = 1;
        v12->pszText = (int)operator new[](0x800u);
      }
      else
      {
        pSymbolInfo = 0;
      }
      v14 = (_DWORD *)v59;
      LOBYTE(v63) = 4;
      v55 = &pSymbolInfo->vtptr;
      if ( v59 )
        (*(void (__stdcall **)(int))(*(_DWORD *)v59 + 4))(v59);
      swprintf_s(&Dst, 0x400u, L"%s", v14[6]);
      v15 = v14[3];
      pSymbolInfo->field_10 = v14[2];
      v16 = (wchar_t *)pSymbolInfo->pszText;
      pSymbolInfo->field_14 = v15;
      swprintf_s(v16, 0x400u, L"%s", &Dst);
      pSymbolInfo->field_18 = 3;
      (*(void (__stdcall **)(_DWORD *))(*v14 + 8))(v14);
      v17 = *(SymbolInfo **)(a4 + 4);
      pICorDebugInternalFrame2 = v17;
      if ( (unsigned int)v17 >= *(_DWORD *)(a4 + 8) && !sub_C388A0((const void **)a4, (unsigned int)&v17->vtptr + 1) )
        break;
      v18 = (SymbolInfo **)(*(_DWORD *)a4 + 4 * (_DWORD)pICorDebugInternalFrame2);
      if ( v18 )
      {
        *v18 = pSymbolInfo;
        ((void (__stdcall *)(SymbolInfo *))pSymbolInfo->vtptr->AddRef)(pSymbolInfo);
      }
      ++*(_DWORD *)(a4 + 4);
      v19 = pSymbolInfo->vtptr;
      LOBYTE(v63) = 3;
      ((void (__stdcall *)(SymbolInfo *))v19->Release)(pSymbolInfo);
      v20 = *v14;
      v63 = -1;
      result = (*(int (__stdcall **)(_DWORD *))(v20 + 8))(v14);
      v4 = v54;
      if ( !v54->field_8 )
        return result;
    }
    goto LABEL_24;
  }
  if ( !result || !*(_DWORD *)(a2 + 8) )
    return result;
  v21 = *(int **)a2;
  v56 = v21;
  result = v21 != 0;
  if ( !v21 )
    goto LABEL_41;
  v22 = (SymbolInfo *)v21[2];
  v52 = v22;
  if ( v22 )
    result = ((int (__stdcall *)(SymbolInfo *))v22->vtptr->AddRef)(v22);
  v23 = *(_DWORD *)(a3 + 8) == 0;
  v63 = 6;
  if ( !v23 )
  {
    while ( 1 )
    {
      sub_C39AC0((int *)v4, &v53);
      v24 = (int)v53;
      while ( 1 )
      {
        pICorDebugInternalFrame2 = 0;
        v25 = v22->vtptr;
        LOBYTE(v63) = 8;
        if ( ((int (__stdcall *)(SymbolInfo *, GUID *, SymbolInfo **))v25->QueryInterface)(
               v22,
               &IID_ICorDebugInternalFrame2,
               &pICorDebugInternalFrame2) )
        {
          break;
        }
        ((void (__stdcall *)(SymbolInfo *, unsigned __int64 *))pICorDebugInternalFrame2->vtptr[1].QueryInterface)(
          pICorDebugInternalFrame2,
          &v51);
        LOBYTE(v63) = 7;
        if ( pICorDebugInternalFrame2 )
          ((void (__stdcall *)(SymbolInfo *))pICorDebugInternalFrame2->vtptr->Release)(pICorDebugInternalFrame2);
        if ( !v56 || v51 >= *(_QWORD *)(v24 + 8) )
          goto LABEL_71;
        pICorDebugInternalFrame2 = 0;
        LOBYTE(v63) = 9;
        v26 = (SymbolInfo *)operator new(0x20u);
        v27 = v26;
        v57 = v26;
        LOBYTE(v63) = 10;
        if ( v26 )
        {
          v26->vtptr = (SymbolInfoVtbl *)&SymbolInfo::`vftable';
          v26->m_nRefCount = 1;
          v26->pszText = (int)operator new[](0x800u);
        }
        else
        {
          v27 = 0;
        }
        LOBYTE(v63) = 9;
        pICorDebugInternalFrame2 = v27;
        if ( sub_C380C0(v22, v27) )
        {
          v28 = (_DWORD *)v59;
          v29 = *(void **)(v59 + 4);
          v58 = v29;
          if ( (unsigned int)v29 >= *(_DWORD *)(v59 + 8) )
          {
            if ( !sub_C388A0((const void **)v59, (unsigned int)v29 + 1) )
              goto LABEL_24;
            v28 = (_DWORD *)v59;
          }
          v30 = (SymbolInfo **)(*v28 + 4 * (_DWORD)v58);
          if ( v30 )
          {
            *v30 = v27;
            if ( v27 )
            {
              ((void (__stdcall *)(SymbolInfo *))v27->vtptr->AddRef)(v27);
              v28 = (_DWORD *)v59;
            }
          }
          ++v28[1];
        }
        v31 = v56;
        v56 = (int *)*v56;
        v32 = (SymbolInfo *)v31[2];
        v58 = v32;
        if ( v22 != v32 )
        {
          if ( v32 )
          {
            ((void (__stdcall *)(SymbolInfo *))v32->vtptr->AddRef)(v32);
            v32 = (SymbolInfo *)v58;
          }
          v33 = v22;
          v22 = v32;
          v52 = v32;
          if ( v33 )
            ((void (__stdcall *)(SymbolInfo *))v33->vtptr->Release)(v33);
        }
        LOBYTE(v63) = 7;
        if ( v27 )
          ((void (__stdcall *)(SymbolInfo *))v27->vtptr->Release)(v27);
      }
      LOBYTE(v63) = 7;
      if ( pICorDebugInternalFrame2 )
        ((void (__stdcall *)(SymbolInfo *))pICorDebugInternalFrame2->vtptr->Release)(pICorDebugInternalFrame2);
LABEL_71:
      v58 = 0;
      LOBYTE(v63) = 11;
      v34 = (SymbolInfo *)operator new(0x20u);
      v35 = v34;
      pICorDebugInternalFrame2 = v34;
      v57 = v34;
      LOBYTE(v63) = 12;
      if ( v34 )
      {
        v34->vtptr = (SymbolInfoVtbl *)&SymbolInfo::`vftable';
        v34->m_nRefCount = 1;
        v34->pszText = (int)operator new[](0x800u);
      }
      else
      {
        v35 = 0;
        pICorDebugInternalFrame2 = 0;
      }
      LOBYTE(v63) = 11;
      v58 = v35;
      if ( v24 )
        (*(void (__stdcall **)(int))(*(_DWORD *)v24 + 4))(v24);
      swprintf_s(&v61, 0x400u, L"%s", *(_DWORD *)(v24 + 24));
      v36 = *(_DWORD *)(v24 + 12);
      v35->field_10 = *(_DWORD *)(v24 + 8);
      v37 = (wchar_t *)v35->pszText;
      v35->field_14 = v36;
      swprintf_s(v37, 0x400u, L"%s", &v61);
      v35->field_18 = 3;
      (*(void (__stdcall **)(int))(*(_DWORD *)v24 + 8))(v24);
      v5 = v59;
      v38 = *(SymbolInfo **)(v59 + 4);
      v57 = v38;
      if ( (unsigned int)v38 >= *(_DWORD *)(v59 + 8) && !sub_C388A0((const void **)v59, (unsigned int)&v38->vtptr + 1) )
        break;
      v39 = (SymbolInfo **)(*(_DWORD *)v5 + 4 * (_DWORD)v57);
      if ( v39 )
      {
        v40 = pICorDebugInternalFrame2;
        *v39 = pICorDebugInternalFrame2;
        ((void (__stdcall *)(SymbolInfo *))v40->vtptr->AddRef)(v40);
      }
      v41 = pICorDebugInternalFrame2;
      ++*(_DWORD *)(v5 + 4);
      LOBYTE(v63) = 7;
      ((void (__stdcall *)(SymbolInfo *))v41->vtptr->Release)(v41);
      v42 = *(_DWORD *)v24;
      LOBYTE(v63) = 6;
      result = (*(int (__stdcall **)(int))(v42 + 8))(v24);
      v4 = v54;
      if ( !v54->field_8 )
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
      v44 = (int (__stdcall ***)(_DWORD, GUID *, int *))v43[2];
      v56 = (int *)*v43;
      v53 = v44;
      if ( v44 )
        ((void (__stdcall *)(int (__stdcall ***)(_DWORD, GUID *, int *)))(*v44)[1])(v44);
      v57 = 0;
      LOBYTE(v63) = 14;
      v45 = (SymbolInfo *)operator new(0x20u);
      pICorDebugInternalFrame2 = v45;
      v58 = v45;
      LOBYTE(v63) = 15;
      if ( v45 )
      {
        v45->vtptr = (SymbolInfoVtbl *)&SymbolInfo::`vftable';
        v45->m_nRefCount = 1;
        v46 = operator new[](0x800u);
        v47 = pICorDebugInternalFrame2;
        pICorDebugInternalFrame2->pszText = (int)v46;
        v48 = v47;
      }
      else
      {
        v48 = 0;
        pICorDebugInternalFrame2 = 0;
      }
      LOBYTE(v63) = 14;
      v57 = v48;
      result = sub_C380C0(v44, v48);
      if ( result )
      {
        v49 = *(void **)(v5 + 4);
        v58 = v49;
        if ( (unsigned int)v49 >= *(_DWORD *)(v5 + 8) && !sub_C388A0((const void **)v5, (unsigned int)v49 + 1) )
          goto LABEL_24;
        result = *(_DWORD *)v5 + 4 * (_DWORD)v58;
        if ( result )
        {
          v50 = pICorDebugInternalFrame2;
          *(_DWORD *)result = pICorDebugInternalFrame2;
          if ( v50 )
            result = ((int (__stdcall *)(SymbolInfo *))v50->vtptr->AddRef)(v50);
        }
        ++*(_DWORD *)(v5 + 4);
      }
      LOBYTE(v63) = 13;
      if ( pICorDebugInternalFrame2 )
        result = ((int (__stdcall *)(SymbolInfo *))pICorDebugInternalFrame2->vtptr->Release)(pICorDebugInternalFrame2);
      LOBYTE(v63) = 6;
      if ( v44 )
        result = ((int (__stdcall *)(int (__stdcall ***)(_DWORD, GUID *, int *)))(*v44)[2])(v44);
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
    result = ((int (__stdcall *)(SymbolInfo *))v22->vtptr->Release)(v22);
  return result;
}
// CAF420: using guessed type void *SymbolInfo::`vftable';
// CAFC40: using guessed type GUID IID_ICorDebugInternalFrame2;

//----- (00C3A3A0) --------------------------------------------------------
signed int __stdcall wcsncat_s(WCHAR *pszBuffer, DWORD MaxLength, LPCWSTR lpszSource)
{
  signed int result; // eax
  WCHAR *pszBuf; // eax
  DWORD dwLength; // edx
  signed int dwMaxLength; // ecx
  char *dwOffset; // edi
  WCHAR chText; // si
  int Index; // [esp+8h] [ebp-4h]

  result = sub_C3A500(pszBuffer, MaxLength, (DWORD *)&Index, 0x7FFFFFFFu);
  if ( result >= 0 )
  {
    pszBuf = &pszBuffer[Index];
    dwLength = MaxLength - Index;
    if ( MaxLength == Index )
      goto LABEL_13;
    dwMaxLength = 0x7FFFFFFF;
    dwOffset = (char *)((char *)lpszSource - (char *)pszBuf);
    while ( dwMaxLength )
    {
      chText = *(WCHAR *)((char *)pszBuf + (_DWORD)dwOffset);
      if ( !chText )
        break;
      *pszBuf = chText;
      --dwMaxLength;
      ++pszBuf;
      if ( !--dwLength )
      {
        *(pszBuf - 1) = 0;
        return STRSAFE_E_INSUFFICIENT_BUFFER;
      }
    }
    if ( dwLength )
    {
      *pszBuf = 0;
      result = 0;
    }
    else
    {
LABEL_13:
      *(pszBuf - 1) = 0;
      result = STRSAFE_E_INSUFFICIENT_BUFFER;
    }
  }
  return result;
}

//----- (00C3A440) --------------------------------------------------------
signed int __stdcall wcsncpy_s_0(WCHAR *pszDest, DWORD DestLength, LPCWSTR lpszSource, DWORD SourceLength)
{
  signed int result; // eax

  result = 0;
  if ( !DestLength || DestLength > 0x7FFFFFFF )
    result = E_INVALIDARG;
  if ( result >= 0 )
  {
    if ( SourceLength <= 0x7FFFFFFE )
    {
      result = sub_C3A490(pszDest, DestLength, 0, lpszSource, SourceLength);
    }
    else
    {
      *pszDest = 0;
      result = E_INVALIDARG;
    }
  }
  return result;
}

//----- (00C3A490) --------------------------------------------------------
signed int __stdcall sub_C3A490(WCHAR *pszDest, DWORD DestLength, WCHAR **ppsz, LPCWSTR lpszSource, DWORD SourceLength)
{
  DWORD dwDestLength; // ecx
  WCHAR *nIndex; // edx
  WCHAR *pszDestBuf; // eax
  DWORD dwSourceLength; // esi
  WCHAR chText; // di
  signed int ret; // edi

  dwDestLength = DestLength;
  nIndex = 0;
  pszDestBuf = pszDest;
  if ( !DestLength )
    goto LABEL_15;
  dwSourceLength = SourceLength;
  while ( dwSourceLength )
  {
    chText = *(WCHAR *)((char *)pszDestBuf + (char *)lpszSource - (char *)pszDest);
    if ( !chText )
      break;
    *pszDestBuf = chText;
    --dwSourceLength;
    ++pszDestBuf;
    nIndex = (WCHAR *)((char *)nIndex + 1);
    if ( !--dwDestLength )
    {
      --pszDestBuf;
      ret = STRSAFE_E_INSUFFICIENT_BUFFER;
      nIndex = (WCHAR *)((char *)nIndex - 1);
      goto LABEL_10;
    }
  }
  if ( dwDestLength )
  {
    ret = 0;
  }
  else
  {
LABEL_15:
    --pszDestBuf;
    ret = STRSAFE_E_INSUFFICIENT_BUFFER;
    nIndex = (WCHAR *)((char *)nIndex - 1);
  }
LABEL_10:
  *pszDestBuf = 0;
  if ( ppsz )
    *ppsz = nIndex;
  return ret;
}

//----- (00C3A500) --------------------------------------------------------
signed int __stdcall sub_C3A500(WCHAR *pszText, DWORD TextLength, DWORD *pdwIndex, DWORD dwMaxSize)
{
  signed int result; // eax
  WCHAR *pszTextBuf; // eax
  DWORD dwTextLength; // ecx
  signed int hret; // esi

  result = 0;
  if ( !TextLength || TextLength > dwMaxSize )
    result = STRSAFE_E_INVALID_PARAMETER;
  if ( result < 0 )
  {
    *pdwIndex = 0;
  }
  else
  {
    pszTextBuf = pszText;
    dwTextLength = TextLength;
    hret = 0;
    if ( !TextLength )
      goto LABEL_10;
    while ( *pszTextBuf )
    {
      ++pszTextBuf;
      if ( !--dwTextLength )
        goto LABEL_10;
    }
    if ( !dwTextLength )
LABEL_10:
      hret = STRSAFE_E_INVALID_PARAMETER;
    if ( pdwIndex )
    {
      if ( hret >= 0 )
      {
        *pdwIndex = TextLength - dwTextLength;
        return hret;
      }
      *pdwIndex = 0;
    }
    result = hret;
  }
  return result;
}

//----- (00C3A570) --------------------------------------------------------
HANDLE __thiscall sub_C3A570(void *this, DWORD dwThreadId, int a3, int a4, int a5, int a6, int a7)
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
  ContextRecord = (PVOID)a3;
  result = OpenThread(0x1F03FFu, 1, dwThreadId);
  hThread = result;
  if ( result )
  {
    memset(&StackFrame, 0, 0x108u);
    v9 = *(_DWORD *)(a3 + 184);
    StackFrame.AddrStack.Offset = *(unsigned int *)(a3 + 196);
    v10 = *(_DWORD *)(a3 + 180);
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
      sub_C4DD60(1, v9, (int)&v32, v7[3], 0, 0, *(_DWORD *)(v12 + 20), *(unsigned int **)(v12 + 16));
      if ( v11 )
      {
        v25 = 0;
        LOBYTE(v35) = 1;
        v13 = operator new(0x20u);
        v14 = (int)v13;
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
        *(_QWORD *)(v14 + 8) = StackFrame.AddrFrame.Offset;
        v25 = v14;
        v15 = wcslen((const unsigned __int16 *)&v33);
        v16 = (wchar_t *)operator new[](2 * (v15 + 1));
        *(_DWORD *)(v14 + 24) = v16;
        swprintf_s(v16, v15 + 1, L"%s", &v33);
        v27 = *(_DWORD *)(a7 + 4);
        sub_C37F70((_DWORD *)a7);
        v17 = *(int **)(a7 + 16);
        v23 = v17;
        v22 = v17;
        v18 = *v17;
        v24 = *v17;
        LOBYTE(v35) = 2;
        if ( v17 )
        {
          v17[2] = v14;
          (*(void (__stdcall **)(int))(*(_DWORD *)v14 + 4))(v14);
          v18 = v24;
        }
        *(_DWORD *)(a7 + 16) = v18;
        v17[1] = v27;
        *v17 = 0;
        ++*(_DWORD *)(a7 + 8);
        v19 = *(int ***)(a7 + 4);
        if ( v19 )
          *v19 = v17;
        else
          *(_DWORD *)a7 = v17;
        *(_DWORD *)(a7 + 4) = v17;
        v20 = *(_DWORD *)v14;
        LOBYTE(v35) = 0;
        (*(void (__stdcall **)(int))(v20 + 8))(v14);
        v11 = v28;
        v7 = v26;
      }
      if ( !StackWalk64(
              0x14Cu,
              (HANDLE)v7[3],
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
    while ( StackFrame.AddrFrame.Offset < __PAIR__((unsigned int)a6, a5) );
    result = HANDLE_FLAG_INHERIT;
  }
  return result;
}
// CAF430: using guessed type void *NativeFrame::`vftable';

//----- (00C3A870) --------------------------------------------------------
char __cdecl sub_C3A870(tagTREEVIEWLISTITEMPARAM *pItem, WPARAM wParam)
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
  unknown_libname_3(&PerfInfo, (int)&gPerformanceInfoInMemory, (int)&gPerformanceInfo);
  v5 = PE_PerfInfo::Load(&PerfInfo, L".NET CLR Jit");
  v6 = wParam;
  v85 = v5;
  if ( v5 )
  {
    v7 = sub_C386E0(szBuffer, (int)v5);
    v86 = v7;
    if ( v7 )
    {
      v8 = (_QWORD *)sub_C37F10((int)v7, L"# of methods Jitted", (int)&v83);
      v9 = ghWndTreeListView;
      v10 = sub_C6F920(*v8, *v8 >> 32, v4);
      v11 = RedrawColumn(v10, v9, IDS_METHODS_JITTED, wParam);
      sub_C37F10((int)v86, L"% time in JIT", (int)&v80);
      v84[1] = sub_C3E840((int)v86);
      sub_C3ECA0((int)v84[1], &v81, 0);
      v12 = 0.0;
      if ( (double)v81 != 0.0 )
        v12 = (double)(unsigned int)v80 * 100.0 / (double)v81;
      v13 = ghWndTreeListView;
      v14 = sub_C6F8F0(v12, (double *)&v4->field_8);
      v2 = RedrawColumn(v14, v13, IDS_TIME_IN_JIT, wParam) | v11;
      if ( v84[1] )
      {
        sub_C3EC80((void **)v84[1]);
        operator delete(v84[1]);
      }
      operator delete(v86);
    }
    operator delete(v85);
  }
  v15 = PE_PerfInfo::Load(&PerfInfo, L".NET CLR Loading");
  v85 = v15;
  if ( v15 )
  {
    v16 = sub_C386E0(szBuffer, (int)v15);
    v86 = v16;
    if ( v16 )
    {
      v17 = (_QWORD *)sub_C37F10((int)v16, L"Current AppDomains", (int)&v83);
      v18 = ghWndTreeListView;
      v19 = sub_C6F920(*v17, *v17 >> 32, &v4->field_10);
      v20 = RedrawColumn(v19, v18, IDS_APPDOMAINS, wParam) | v2;
      v21 = (_QWORD *)sub_C37F10((int)v86, L"Current Assemblies", (int)&v83);
      v22 = ghWndTreeListView;
      v23 = sub_C6F920(*v21, *v21 >> 32, &v4->field_30);
      v24 = RedrawColumn(v23, v22, IDS_ASSEMBLIES, wParam) | v20;
      v25 = (_QWORD *)sub_C37F10((int)v86, L"Current Classes Loaded", (int)&v83);
      v26 = ghWndTreeListView;
      v27 = sub_C6F920(*v25, *v25 >> 32, &v4->field_20);
      v28 = RedrawColumn(v27, v26, IDS_CLASSES_LOADED, wParam) | v24;
      v29 = (_QWORD *)sub_C37F10((int)v86, L"Total AppDomains", (int)&v83);
      v30 = ghWndTreeListView;
      v31 = sub_C6F920(*v29, *v29 >> 32, &v4->field_18);
      v32 = RedrawColumn(v31, v30, IDS_TOTAL_APPDOMAINS, wParam) | v28;
      v33 = (_QWORD *)sub_C37F10((int)v86, L"Total Assemblies", (int)&v83);
      v34 = ghWndTreeListView;
      v35 = sub_C6F920(*v33, *v33 >> 32, &v4->field_38);
      v36 = RedrawColumn(v35, v34, IDS_TOTAL_ASSEMBLIES, wParam) | v32;
      v37 = (_QWORD *)sub_C37F10((int)v86, L"Total Classes Loaded", (int)&v83);
      v38 = ghWndTreeListView;
      v39 = sub_C6F920(*v37, *v37 >> 32, &v4->field_28);
      v2 = RedrawColumn(v39, v38, IDS_TOTAL_CLASSES_LOADED, wParam) | v36;
      operator delete(v86);
    }
    operator delete(v85);
  }
  v40 = PE_PerfInfo::Load(&PerfInfo, L".NET CLR LocksAndThreads");
  v84[1] = v40;
  if ( v40 )
  {
    v41 = sub_C386E0(szBuffer, (int)v40);
    v85 = v41;
    if ( v41 )
    {
      v42 = (_QWORD *)sub_C37F10((int)v41, L"Total # of contentions", (int)&v83);
      v43 = ghWndTreeListView;
      v44 = sub_C6F920(*v42, *v42 >> 32, &v4->field_80);
      v2 |= RedrawColumn(v44, v43, 1110, wParam);
      operator delete(v85);
    }
    operator delete(v84[1]);
  }
  v45 = PE_PerfInfo::Load(&PerfInfo, L".NET CLR Memory");
  v85 = v45;
  if ( v45 )
  {
    v46 = sub_C386E0(szBuffer, (int)v45);
    v86 = v46;
    if ( v46 )
    {
      v47 = (_QWORD *)sub_C37F10((int)v46, L"# bytes in all heaps", (int)&v83);
      v48 = ghWndTreeListView;
      v49 = sub_C6F920(*v47, *v47 >> 32, &v4->field_70);
      v50 = RedrawColumn(v49, v48, 1103, wParam) | v2;
      v51 = (_QWORD *)sub_C37F10((int)v86, L"# Gen 0 collections", (int)&v83);
      v52 = ghWndTreeListView;
      v53 = sub_C6F920(*v51, *v51 >> 32, &v4->field_40);
      v54 = RedrawColumn(v53, v52, 1104, wParam) | v50;
      v55 = (_QWORD *)sub_C37F10((int)v86, L"# Gen 1 collections", (int)&v83);
      v56 = ghWndTreeListView;
      v57 = sub_C6F920(*v55, *v55 >> 32, &v4->field_48);
      v58 = RedrawColumn(v57, v56, 1105, wParam) | v54;
      v59 = (_QWORD *)sub_C37F10((int)v86, L"# Gen 2 collections", (int)&v83);
      v60 = ghWndTreeListView;
      v61 = sub_C6F920(*v59, *v59 >> 32, &v4->field_50);
      v62 = RedrawColumn(v61, v60, 1106, wParam) | v58;
      sub_C37F10((int)v86, L"Allocated bytes/sec", (int)v79);
      v63 = v79[1];
      *(double *)v84 = (double)*(signed __int64 *)v79;
      *(double *)v84 = (double)*(signed __int64 *)v79 - (double)*(signed __int64 *)&v82->field_60;
      v64 = (signed __int64)(*(double *)v84
                           / (((double)*(signed __int64 *)&gLoadNetClrMemoryPerfInfoTime
                             - (double)*(signed __int64 *)&gLoadNetClrMemoryPerfInfoTimeLast)
                            / 10000000.0));
      v65 = v64;
      LODWORD(v64) = v82;
      v82->field_60 = v79[0];
      v4 = (tagNetCclrInfo *)v64;
      *(_DWORD *)(v64 + 100) = v63;
      v6 = wParam;
      v66 = ghWndTreeListView;
      v67 = sub_C6F920(v65, SHIDWORD(v64), (_DWORD *)(v64 + 104));
      v68 = RedrawColumn(v67, v66, 1108, wParam) | v62;
      sub_C37F10((int)v86, L"% time in GC", (int)&v80);
      v84[1] = sub_C3E840((int)v86);
      sub_C3ECA0((int)v84[1], &v81, 0);
      v69 = 0.0;
      if ( (double)v81 != 0.0 )
        v69 = (double)(unsigned int)v80 * 100.0 / (double)v81;
      v70 = ghWndTreeListView;
      v71 = sub_C6F8F0(v69, (double *)&v4->field_58);
      v2 = RedrawColumn(v71, v70, 1107, wParam) | v68;
      if ( v84[1] )
      {
        sub_C3EC80((void **)v84[1]);
        operator delete(v84[1]);
      }
      operator delete(v86);
    }
    operator delete(v85);
  }
  v72 = PE_PerfInfo::Load(&PerfInfo, L".NET CLR Security");
  v84[1] = v72;
  if ( v72 )
  {
    v73 = sub_C386E0(szBuffer, (int)v72);
    v85 = v73;
    if ( v73 )
    {
      v74 = (_QWORD *)sub_C37F10((int)v73, L"Total runtime checks", (int)&v83);
      v75 = ghWndTreeListView;
      v76 = sub_C6F920(*v74, *v74 >> 32, &v4->field_78);
      v2 |= RedrawColumn(v76, v75, 1109, v6);
      operator delete(v85);
    }
    operator delete(v84[1]);
  }
  return v2;
}
// CACDC0: using guessed type double db_onehundred;
// CDA0A8: using guessed type struct _FILETIME gLoadNetClrMemoryPerfInfoTimeLast;

//----- (00C3B0A0) --------------------------------------------------------
int __userpurge sub_C3B0A0@<eax>(MixedModeStackWalker *this@<ecx>, __int128 _XMM0@<xmm0>, DWORD dwThreadId, int a3)
{
  MixedModeStackWalker *This; // ebx
  int result; // eax
  int *v6; // ST20_4
  int v7; // ecx
  HANDLE v8; // eax
  void *v9; // esi
  signed int v10; // ebx
  HANDLE v11; // eax
  void *v12; // esi
  int *v13; // ecx
  int v14; // eax
  int v15; // eax
  int v16; // edi
  int v17; // esi
  int v18; // eax
  int v19; // ecx
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // ecx
  int (__stdcall **v24)(int, GUID *, int *); // eax
  int v25; // eax
  int v26; // ecx
  int v27; // eax
  int (__stdcall **v28)(int, GUID *, int *); // eax
  int v29[2]; // [esp+10h] [ebp-62Ch]
  MixedModeStackWalker MixedModeStackWalker; // [esp+18h] [ebp-624h]
  int v31; // [esp+40h] [ebp-5FCh]
  int v32; // [esp+44h] [ebp-5F8h]
  int a7; // [esp+48h] [ebp-5F4h]
  unsigned int a8; // [esp+4Ch] [ebp-5F0h]
  int v35; // [esp+50h] [ebp-5ECh]
  int v36; // [esp+54h] [ebp-5E8h]
  int v37; // [esp+58h] [ebp-5E4h]
  int a5; // [esp+5Ch] [ebp-5E0h]
  int v39; // [esp+60h] [ebp-5DCh]
  unsigned int a9; // [esp+64h] [ebp-5D8h]
  int v41; // [esp+68h] [ebp-5D4h]
  int v42; // [esp+6Ch] [ebp-5D0h]
  int a6; // [esp+70h] [ebp-5CCh]
  int v44; // [esp+74h] [ebp-5C8h]
  int v45; // [esp+78h] [ebp-5C4h]
  int a3a; // [esp+7Ch] [ebp-5C0h]
  int a4; // [esp+80h] [ebp-5BCh]
  int v48; // [esp+84h] [ebp-5B8h]
  int pICorDebugInternalFrame2; // [esp+88h] [ebp-5B4h]
  int a2; // [esp+8Ch] [ebp-5B0h]
  int v51; // [esp+90h] [ebp-5ACh]
  int v52; // [esp+94h] [ebp-5A8h]
  int v53; // [esp+360h] [ebp-2DCh]
  int v54; // [esp+638h] [ebp-4h]

  This = this;
  v44 = a3;
  result = sub_C38D10(this, dwThreadId);
  if ( !result )
    return result;
  v45 = 0;
  v6 = (int *)This->field_1C;
  v7 = *v6;
  v54 = 0;
  (*(void (__stdcall **)(int *, DWORD, int *))(v7 + 0x3C))(v6, dwThreadId, &v45);
  if ( !v45 )
  {
    v8 = OpenThread(THREAD_ALL_ACCESS, 1, dwThreadId);
    v9 = v8;
    if ( v8 )
    {
      ResumeThread(v8);
      CloseHandle(v9);
    }
    v10 = 0;
    goto LABEL_72;
  }
  v11 = OpenThread(THREAD_ALL_ACCESS, 1, dwThreadId);
  v12 = v11;
  if ( v11 )
  {
    SuspendThread(v11);
    CloseHandle(v12);
  }
  v13 = 0;
  a2 = 0;
  if ( v45 )
  {
    v14 = (**(int (__stdcall ***)(int, GUID *, int *))v45)(v45, &IID_ICorDebugThread3, &a2);
    v13 = (int *)a2;
    if ( v14 < 0 )
      v13 = 0;
    a2 = (int)v13;
  }
  if ( !v13 )
  {
    PE_ResumeThreadById(dwThreadId);
    v10 = 0;
    goto LABEL_70;
  }
  a3a = 0;
  v15 = *v13;
  LOBYTE(v54) = 2;
  if ( (*(int (__stdcall **)(int *, int *))(v15 + 12))(v13, &a3a) )
  {
    PE_ResumeThreadById(dwThreadId);
    v10 = 0;
    goto LABEL_68;
  }
  v35 = 0;
  v36 = 0;
  MixedModeStackWalker.vtptr = 0;
  MixedModeStackWalker.m_nRefCount = 0;
  MixedModeStackWalker.m_dwProcessId = 0;
  MixedModeStackWalker.m_hProcess = 0;
  MixedModeStackWalker.field_10 = 0;
  MixedModeStackWalker.field_14 = 10;
  a9 = 0;
  MixedModeStackWalker.m_ICLRDebugging = 0;
  MixedModeStackWalker.field_1C = 0;
  MixedModeStackWalker.DebugDataTarget = 0;
  MixedModeStackWalker.DebuggingLibraryProvider = 0;
  v31 = 0;
  v32 = 10;
  LOBYTE(v54) = 4;
  if ( !sub_C37FF0(a2, &a7, &a8) )
  {
    v10 = 0;
    goto LABEL_67;
  }
  a6 = 0;
  v16 = 0;
  *(_QWORD *)v29 = 0i64;
  a5 = 0;
  v41 = 0;
  v17 = 0;
  v42 = 0;
  LOBYTE(v54) = 6;
  while ( 1 )
  {
    while ( 1 )
    {
      if ( a6 == 1 )
      {
        v39 = v16;
        if ( v16 )
          (*(void (__stdcall **)(int))(*(_DWORD *)v16 + 4))(v16);
        LOBYTE(v54) = 7;
        if ( v16 )
        {
          a4 = 0;
          v48 = 0;
          v18 = (**(int (__stdcall ***)(int, GUID *, int *))v16)(v16, &IID_ICorDebugNativeFrame2, &v48);
          v19 = v48;
          if ( v18 < 0 )
            v19 = 0;
          v48 = v19;
          LOBYTE(v54) = 8;
          if ( v19 )
          {
            (*(void (__stdcall **)(int, int *))(*(_DWORD *)v19 + 12))(v19, &a4);
            if ( a4 == 1 && v17 != v16 )
            {
              (*(void (__stdcall **)(int))(*(_DWORD *)v16 + 4))(v16);
              v20 = v17;
              v17 = v16;
              v42 = v16;
              if ( v20 )
                (*(void (__stdcall **)(int))(*(_DWORD *)v20 + 8))(v20);
            }
            v19 = v48;
          }
          LOBYTE(v54) = 7;
          if ( v19 )
            (*(void (__stdcall **)(int))(*(_DWORD *)v19 + 8))(v19);
        }
        LOBYTE(v54) = 6;
        if ( v16 )
          (*(void (__stdcall **)(int))(*(_DWORD *)v16 + 8))(v16);
      }
      v41 = 0;
      a4 = v16;
      v21 = sub_C38E20(This, 0i64, a2, a3a, &a4, &a5, &a6, a7, a8, &a9);
      v16 = a4;
      v41 = a4;
      if ( v21 )
      {
        if ( v17 )
          break;
      }
      if ( v21 != 1 )
      {
        sub_C3A570(This, dwThreadId, (int)&v53, 716, -1, 0x7FFFFFFF, (int)&MixedModeStackWalker.m_ICLRDebugging);
        sub_C39C50(This, (int)&MixedModeStackWalker, (int)&MixedModeStackWalker.m_ICLRDebugging, v44);
        sub_C39A30((int)&MixedModeStackWalker.m_ICLRDebugging);
        PE_ResumeThreadById(dwThreadId);
        sub_C377E0((int *)v44);
        v10 = 1;
        goto LABEL_63;
      }
      if ( !sub_C3B680(
              This,
              dwThreadId,
              a4,
              a3a,
              (int)&MixedModeStackWalker,
              (int)&MixedModeStackWalker.m_ICLRDebugging,
              (int)&v35,
              (int)&v52,
              (int)&v36,
              (int)&v53,
              (int)v29,
              v44) )
      {
        PE_ResumeThreadById(dwThreadId);
        v10 = 0;
        goto LABEL_63;
      }
    }
    v39 = a4;
    if ( a4 )
      (*(void (__stdcall **)(int))(*(_DWORD *)a4 + 4))(a4);
    LOBYTE(v54) = 9;
    if ( v16 )
      break;
LABEL_52:
    LOBYTE(v54) = 6;
    if ( v16 )
      (*(void (__stdcall **)(int))(*(_DWORD *)v16 + 8))(v16);
  }
  v51 = 0;
  v22 = (**(int (__stdcall ***)(int, GUID *, int *))v17)(v17, &IID_ICorDebugNativeFrame2, &v51);
  v23 = v51;
  if ( v22 < 0 )
    v23 = 0;
  v51 = v23;
  pICorDebugInternalFrame2 = 0;
  v24 = *(int (__stdcall ***)(int, GUID *, int *))v16;
  LOBYTE(v54) = 10;
  v25 = (*v24)(v16, &IID_ICorDebugNativeFrame2, &pICorDebugInternalFrame2);
  v26 = pICorDebugInternalFrame2;
  if ( v25 < 0 )
    v26 = 0;
  pICorDebugInternalFrame2 = v26;
  LOBYTE(v54) = 11;
  if ( !(*(int (__stdcall **)(int, int, int *))(*(_DWORD *)v51 + 16))(v51, v26, &v37) )
  {
    if ( v37 == 1 )
    {
      v27 = v17;
      v17 = 0;
      v42 = 0;
      if ( v27 )
        (*(void (__stdcall **)(int))(*(_DWORD *)v27 + 8))(v27);
    }
    LOBYTE(v54) = 10;
    if ( pICorDebugInternalFrame2 )
      (*(void (__stdcall **)(int))(*(_DWORD *)pICorDebugInternalFrame2 + 8))(pICorDebugInternalFrame2);
    LOBYTE(v54) = 9;
    if ( v51 )
      (*(void (__stdcall **)(int))(*(_DWORD *)v51 + 8))(v51);
    goto LABEL_52;
  }
  LOBYTE(v54) = 10;
  if ( pICorDebugInternalFrame2 )
    (*(void (__stdcall **)(int))(*(_DWORD *)pICorDebugInternalFrame2 + 8))(pICorDebugInternalFrame2);
  LOBYTE(v54) = 9;
  if ( v51 )
    (*(void (__stdcall **)(int))(*(_DWORD *)v51 + 8))(v51);
  v28 = *(int (__stdcall ***)(int, GUID *, int *))v16;
  LOBYTE(v54) = 6;
  ((void (__stdcall *)(int))v28[2])(v16);
  v10 = 0;
LABEL_63:
  LOBYTE(v54) = 5;
  if ( v17 )
    (*(void (__stdcall **)(int))(*(_DWORD *)v17 + 8))(v17);
  LOBYTE(v54) = 4;
  if ( v16 )
    (*(void (__stdcall **)(int))(*(_DWORD *)v16 + 8))(v16);
LABEL_67:
  sub_C39A30((int)&MixedModeStackWalker.m_ICLRDebugging);
  sub_C39A30((int)&MixedModeStackWalker);
LABEL_68:
  LOBYTE(v54) = 1;
  if ( a3a )
    (*(void (__stdcall **)(int))(*(_DWORD *)a3a + 8))(a3a);
LABEL_70:
  LOBYTE(v54) = 0;
  if ( a2 )
    (*(void (__stdcall **)(int))(*(_DWORD *)a2 + 8))(a2);
LABEL_72:
  v54 = -1;
  if ( v45 )
    (*(void (__stdcall **)(int))(*(_DWORD *)v45 + 8))(v45);
  return v10;
}
// CAFC50: using guessed type GUID IID_ICorDebugThread3;
// CAFC60: using guessed type GUID IID_ICorDebugNativeFrame2;

//----- (00C3B680) --------------------------------------------------------
int __thiscall sub_C3B680(_DWORD *this, DWORD dwThreadId, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12)
{
  _DWORD *v12; // ebx
  signed int v13; // eax
  _DWORD *v14; // esi
  _DWORD *v16; // edx
  int *v17; // ecx
  int v18; // esi
  int v19; // ST10_4
  int v20; // esi
  int v21; // ecx
  SymbolInfo *v22; // eax
  SymbolInfo *v23; // esi
  int v24; // eax
  signed int v25; // eax
  int v26; // eax

  v12 = this;
  if ( a3 )
  {
    v13 = sub_C37DD0((int (__stdcall ***)(_DWORD, GUID *, int *))a3);
    if ( v13 != 2 )
    {
      v14 = (_DWORD *)a7;
      if ( v13 != 1 )
      {
        if ( (*(int (__stdcall **)(int, signed int, signed int, int *, int))(*(_DWORD *)a4 + 12))(
               a4,
               65539,
               716,
               &a4,
               a8) )
        {
          return 0;
        }
        v16 = (_DWORD *)a9;
        *v14 = 1;
LABEL_7:
        v17 = (int *)a11;
        *(_DWORD *)a11 = -1;
        v17[1] = 0x7FFFFFFF;
        if ( *v14 == 1 )
        {
          *v17 = *(_DWORD *)(a8 + 196);
          v17[1] = 0;
        }
        v18 = a6;
        if ( *v16 == 1 )
          sub_C3A570(v12, dwThreadId, a10, 716, *v17, v17[1], a6);
        v19 = v18;
        v20 = a5;
        sub_C39C50(v12, a5, v19, a12);
        v21 = a6;
        *(_DWORD *)a9 = 0;
        sub_C39A30(v21);
        sub_C39A30(v20);
        a9 = 0;
        v22 = (SymbolInfo *)operator new(0x20u);
        v23 = v22;
        a8 = (int)v22;
        if ( v22 )
        {
          v22->vtptr = (SymbolInfoVtbl *)&SymbolInfo::`vftable';
          v22->m_nRefCount = 1;
          v22->pszText = (int)operator new[](0x800u);
        }
        else
        {
          v23 = 0;
        }
        a9 = (int)v23;
        v25 = sub_C37DD0((int (__stdcall ***)(_DWORD, GUID *, int *))a3);
        if ( v25 && (v26 = v25 - 1) != 0 )
        {
          if ( v26 != 2 )
            goto LABEL_22;
          sub_C38A30(v23, (int)"[Native Frame: IL Method without Metadata]", 0, 0, 3);
        }
        else if ( !sub_C380C0((int (__stdcall ***)(_DWORD, GUID *, int *))a3, v23) )
        {
          goto LABEL_22;
        }
        sub_C376F0((_DWORD *)a12, &a9);
LABEL_22:
        if ( v23 )
          ((void (__stdcall *)(SymbolInfo *))v23->vtptr->Release)(v23);
        return 1;
      }
      v16 = (_DWORD *)a9;
      if ( !*(_DWORD *)a9 )
        goto LABEL_7;
      v24 = *(_DWORD *)a3;
      a12 = a3;
      (*(void (__stdcall **)(int))(v24 + 4))(a3);
      sub_C37740((_DWORD *)a5, &a12);
      (*(void (__stdcall **)(int))(*(_DWORD *)a3 + 8))(a3);
    }
  }
  else
  {
    if ( (*(int (__stdcall **)(int, signed int, signed int, int *, int))(*(_DWORD *)a4 + 12))(a4, 65539, 716, &a8, a10) )
      return 0;
    *(_DWORD *)a9 = 1;
    *(_DWORD *)a7 = 0;
  }
  return 1;
}
// CAF420: using guessed type void *SymbolInfo::`vftable';

//----- (00C3B8A0) --------------------------------------------------------
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
  unknown_libname_3((PE_PerfInfo *)PEPerfInfo, (int)&Item, (int)&Info);
  gNetClrMemoryPerfInfoLoaded = PE_PerfInfo::Load((PE_PerfInfo *)PEPerfInfo, L".NET CLR Memory") != 0;
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
  PerformanceInfo::~PerformanceInfo((void **)&Info);
}
// CDA098: using guessed type char gNetClrMemoryPerfInfoLoaded;
// CDA0A8: using guessed type struct _FILETIME gLoadNetClrMemoryPerfInfoTimeLast;

//----- (00C3B9D0) --------------------------------------------------------
void *__cdecl sub_C3B9D0(int a1)
{
  void *v1; // esi
  int v3; // [esp+0h] [ebp-Ch]
  int v4; // [esp+4h] [ebp-8h]
  LPVOID ppv; // [esp+8h] [ebp-4h]

  if ( !gNetClrMemoryPerfInfoLoaded )
    return 0;
  v3 = 0;
  if ( byte_CDA09A )
    CoCreateInstance(&stru_CAF40C, 0, 1u, &IID_ICorPublish, &ppv);
  else
    CoCreateInstance(&CLSID_CorpubPublish, 0, 1u, &IID_ICorPublish, &ppv);
  if ( !ppv )
    return 0;
  if ( !(*(int (__stdcall **)(LPVOID, int, int *))(*(_DWORD *)ppv + 16))(ppv, a1, &v4) )
  {
    (*(void (__stdcall **)(int, int *))(*(_DWORD *)v4 + 12))(v4, &v3);
    (*(void (__stdcall **)(int))(*(_DWORD *)v4 + 8))(v4);
  }
  (*(void (__stdcall **)(LPVOID))(*(_DWORD *)ppv + 8))(ppv);
  if ( !v3 )
    return 0;
  v1 = malloc(0x88u);
  memset(v1, 0, 0x88u);
  return v1;
}
// CAF40C: using guessed type GUID stru_CAF40C;
// CDA098: using guessed type char gNetClrMemoryPerfInfoLoaded;
// CDA09A: using guessed type char byte_CDA09A;

//----- (00C3BA80) --------------------------------------------------------
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
  pDrawItemStruct = (LPDRAWITEMSTRUCT)a4;
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
        v28 = dword_CDA0CC;
        v29 = GetDlgItem(hWnd, 1094);
        sub_C37A00(v29, v28, 0);
        PerformanceInfoInMemory::Load(*(PerformanceInfoInMemory **)(v5 + 804), 0, (LPCWSTR)(v5 + 28));
        unknown_libname_3(&v46, *(_DWORD *)(v5 + 804), (int)&gPerformanceInfo);
        v30 = PE_PerfInfo::Load(&v46, (LPCWSTR)(v5 + 28));
        if ( v30 )
        {
          pDrawItemStruct = (LPDRAWITEMSTRUCT)sub_C386E0((wchar_t *)(v5 + 284), (int)v30);
          GetSystemTimeAsFileTime((LPFILETIME)(v5 + 8));
          v31 = 0;
          v32 = *(HWND *)(v5 + 16);
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
              SendMessageW(*(HWND *)(v5 + 16), LVM_GETITEMW, 0, (LPARAM)&v47);
              if ( pDrawItemStruct && sub_C37F10((int)pDrawItemStruct, &sz, (int)v54) )
              {
                v33 = sub_C3E760((PerformanceInfo **)pDrawItemStruct, &sz);
                v34 = (void **)v33;
                if ( v33 && (unsigned int)v33[1] & 0x20000 )
                {
                  v34 = (void **)sub_C3E840((int)pDrawItemStruct);
                  sub_C3ECA0((int)v34, &v50, 0);
                  v35 = 0.0;
                  if ( (double)v50 != 0.0 )
                    v35 = (double)*(unsigned int *)v54 * 100.0 / (double)v50;
                  sub_C37500(&Dst, L"%02.02f", LODWORD(v35), HIDWORD(v35));
                }
                else
                {
                  sub_C37500(&Dst, L"%I64d", *(_DWORD *)v54, v55);
                  PE_GetNumberFormat(&Dst, 0x80u);
                }
                if ( v34 )
                {
                  sub_C3EC80(v34);
                  operator delete(v34);
                }
                v31 = v57;
              }
              else
              {
                sub_C37500(&Dst, L"0");
              }
              v41 = 1;
              v44 = &v59;
              v36 = *(HWND *)(v5 + 16);
              v45 = 128;
              SendMessageW(v36, 0x1073u, v31, (LPARAM)&lParam);
              v37 = wcscmp((const unsigned __int16 *)&v59, &Dst);
              if ( v37 )
                v37 = -(v37 < 0) | 1;
              if ( v37 )
              {
                v47.mask = 1;
                v47.pszText = &Dst;
                v47.iSubItem = 1;
                v47.cchTextMax = 128;
                SendMessageW(*(HWND *)(v5 + 16), 0x104Cu, 0, (LPARAM)&v47);
                SendMessageW(*(HWND *)(v5 + 16), 0x1015u, v47.iItem, v47.iItem);
              }
              v38 = *(HWND *)(v5 + 16);
              v57 = ++v31;
            }
            while ( v31 < SendMessageW(v38, 0x1004u, 0, 0) );
          }
        }
        *(_DWORD *)v5 = *(_DWORD *)(v5 + 8);
        *(_DWORD *)(v5 + 4) = *(_DWORD *)(v5 + 12);
        return 0;
      case 0x133u:
      case 0x136u:
      case 0x138u:
        return PE_FillControl((int)hWnd, (HDC)wParam);
      default:
        return 0;
    }
    return 0;
  }
  if ( a2 == 273 )
  {
    switch ( (unsigned __int16)wParam )
    {
      case IDM_FILE_EXIT:
        ArgList = 40014;
        goto LABEL_25;
      case IDM_VIEW_REFRESH_NOW:
        SetEvent(ghRefreshEventHandle);
        break;
      case IDC_DLG_RUNDLG_BUTTON_BROWSE|IDC_FILE_STANDBY|IDS_REFRESH_PROCESS_LIST:
      case IDC_DLG_RUNDLG_BUTTON_BROWSE|IDC_FILE_STANDBY|IDS_REFRESH_PROCESS_LIST|0x1:
        ArgList = wParam;
LABEL_25:
        v20 = GetParent(hWnd);
        PostMessageW(v20, WM_COMMAND, ArgList, 0);
        break;
      default:
        break;
    }
    if ( wParam >> 16 == 1 && (_WORD)wParam == 1093 )
    {
      SendMessageW(*(HWND *)(v5 + 16), LVM_DELETEALLITEMS, 0, 0);
      v21 = SendMessageW(*(HWND *)(v5 + 20), CB_GETCURSEL, 0, 0);
      SendMessageW(*(HWND *)(v5 + 20), CB_GETLBTEXT, v21, v5 + 28);
      PerformanceInfoInMemory::Load(*(PerformanceInfoInMemory **)(v5 + 804), 0, (LPCWSTR)(v5 + 28));
      unknown_libname_3(&v46, *(_DWORD *)(v5 + 804), (int)&gPerformanceInfo);
      v22 = PE_PerfInfo::Load(&v46, (LPCWSTR)(v5 + 28));
      if ( v22 )
      {
        v23 = sub_C3ED60(v22);
        v57 = (WPARAM)v23;
        if ( v23 )
        {
          v24 = sub_C3E830((int)v23);
          if ( v24 )
          {
            v25 = v57;
            do
            {
              if ( !((unsigned int)v24[1] & 0x400000) )
              {
                wcscpy_s(&Dst, 0x80u, *v24);
                v26 = wcscmp(L"Not Displayed", &Dst);
                if ( v26 )
                  v26 = -(v26 < 0) | 1;
                if ( v26 )
                  sub_C67F90(*(HWND *)(v5 + 16), (int)&Dst, (int)&gszNullString);
              }
              sub_C3EC80((void **)v24);
              operator delete(v24);
              v24 = sub_C3E840(v25);
            }
            while ( v24 );
            v4 = v51;
          }
        }
      }
      SendMessageW(v4, 0x113u, 0, 0);
      SendMessageW(*(HWND *)(v5 + 16), 0x101Eu, 0, 0xFFFF);
      SendMessageW(*(HWND *)(v5 + 16), 0x101Eu, 1u, 65534);
      v43 = 2;
      v27 = *(HWND *)(v5 + 16);
      v42 = 2;
      SendMessageW(v27, 0x102Bu, 0, (LPARAM)&lParam);
    }
    return 0;
  }
  if ( a2 > 0x2C )
  {
    if ( a2 == 256 )
    {
      if ( wParam == 116 )
        PostMessageW(hWnd, WM_TIMER, 1u, 0);
      return 0;
    }
    if ( a2 != 272 )
      return 0;
    v8 = (CResizer *)operator new(0x40u);
    if ( v8 )
      CResizer::CResizer(v8, hWnd);
    PropSheet_UpdateTab(hWnd);
    v9 = (wchar_t *)malloc(0x328u);
    memset(v9, 0, 0x328u);
    SetWindowLongW(hWnd, -21, (LONG)v9);
    v10 = GetDlgItem(hWnd, 1094);
    *((_DWORD *)v9 + 6) = v10;
    v11 = GetWindowLongW(v10, -16);
    SetWindowLongW(*((HWND *)v9 + 6), -16, v11 & 0xFFFFFFFD | 1);
    SetWindowLongW(*((HWND *)v9 + 6), -21, 1);
    SendMessageW(*((HWND *)v9 + 6), 0x1036u, 0x4020u, 16416);
    v12 = (HWND)SendMessageW(*((HWND *)v9 + 6), 0x104Eu, 0, 0);
    CTreeList::InitToolTips(v12);
    gOldListWndProc = (WNDPROC)SetWindowLongW(*((HWND *)v9 + 6), -4, (LONG)Proxy_ListCtrlWndProc);
    SendMessageW(*((HWND *)v9 + 6), 0x30u, (WPARAM)ghConfigFont, 0);
    InitListHeader(*((HWND *)v9 + 6), &pnIDs, pnWidths, 1);
    v13 = (HWND)*((_DWORD *)v9 + 6);
    dword_CDA0CC = (int)pDrawItemStruct[1].hwndItem;
    sub_C37A00(v13, dword_CDA0CC, 1);
    SendMessageW(*((HWND *)v9 + 6), 0x101Eu, 0, 65534);
    sub_C38790((wchar_t *)pDrawItemStruct[1].itemAction, v9 + 142);
    v14 = GetDlgItem(hWnd, 1093);
    *((_DWORD *)v9 + 5) = v14;
    SendMessageW(v14, 0x143u, 0, (LPARAM)L".NET CLR Memory");
    SendMessageW(*((HWND *)v9 + 5), 0x143u, 0, (LPARAM)L".NET CLR Jit");
    SendMessageW(*((HWND *)v9 + 5), 0x143u, 0, (LPARAM)L".NET CLR Exceptions");
    SendMessageW(*((HWND *)v9 + 5), 0x143u, 0, (LPARAM)L".NET CLR LocksAndThreads");
    SendMessageW(*((HWND *)v9 + 5), 0x143u, 0, (LPARAM)L".NET CLR Data");
    SendMessageW(*((HWND *)v9 + 5), 0x143u, 0, (LPARAM)L".NET CLR Interop");
    SendMessageW(*((HWND *)v9 + 5), 0x143u, 0, (LPARAM)L".NET CLR Loading");
    SendMessageW(*((HWND *)v9 + 5), 0x143u, 0, (LPARAM)L".NET CLR Remoting");
    SendMessageW(*((HWND *)v9 + 5), 0x143u, 0, (LPARAM)L".NET CLR Security");
    SendMessageW(*((HWND *)v9 + 5), 0x14Eu, 0, 0);
    v15 = GetDlgItem(hWnd, 1091);
    *((_DWORD *)v9 + 4) = v15;
    v16 = GetWindowLongW(v15, -16);
    SetWindowLongW(*((HWND *)v9 + 4), -16, v16 & 0xFFFFFFFD | 1);
    v17 = (PerformanceInfoInMemory *)operator new(8u);
    if ( v17 )
      v18 = PE_PerfInfo::PE_PerfInfo(v17, (PerformanceInfo *)&gPerformanceInfo);
    else
      v18 = 0;
    v19 = (HWND)*((_DWORD *)v9 + 4);
    *((_DWORD *)v9 + 201) = v18;
    SendMessageW(v19, 0x1036u, 0x4020u, 16416);
    gOldListWndProc = (WNDPROC)SetWindowLongW(*((HWND *)v9 + 4), -4, (LONG)Proxy_ListCtrlWndProc);
    SendMessageW(*((HWND *)v9 + 4), 0x30u, (WPARAM)ghConfigFont, 0);
    InitListHeader(*((HWND *)v9 + 4), &v48, v53, 2);
    SendMessageW(hWnd, 0x111u, 0x10445u, 0);
    SendMessageW(*((HWND *)v9 + 4), 0x101Eu, 0, 0xFFFF);
    SendMessageW(*((HWND *)v9 + 4), 0x101Eu, 1u, 65534);
    *(_DWORD *)v9 = 0;
    *((_DWORD *)v9 + 1) = 0;
    SendMessageW(hWnd, 0x113u, 0, 0);
    result = 1;
  }
  else
  {
    if ( a2 != 44 )
    {
      if ( a2 == 2 )
      {
        v7 = *(void **)(v5 + 804);
        if ( v7 )
        {
          PerformanceInfoInMemory::~PerformanceInfoInMemory(*(PerformanceInfoInMemory **)(v5 + 804));
          operator delete(v7);
        }
        free((void *)v5);
      }
      else if ( a2 == 43 )
      {
        CMainWnd::DrawItem(pDrawItemStruct);
      }
      return 0;
    }
    result = CMainWnd::HandleMeasureItem(hWnd, 0x2Cu, wParam, (LPMEASUREITEMSTRUCT)pDrawItemStruct);
  }
  return result;
}
// CACDC0: using guessed type double db_onehundred;
// CAF4BC: using guessed type wchar_t aNetClrExceptio[20];
// CAF518: using guessed type wchar_t aNetClrData[14];
// CAF534: using guessed type wchar_t aNetClrInterop[17];
// CAF57C: using guessed type wchar_t aNetClrRemoting[18];
// CAF5C4: using guessed type wchar_t aNotDisplayed[14];

//----- (00C3C500) --------------------------------------------------------
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
// CDA098: using guessed type char gNetClrMemoryPerfInfoLoaded;
// CDA0A8: using guessed type struct _FILETIME gLoadNetClrMemoryPerfInfoTimeLast;

//----- (00C3C540) --------------------------------------------------------
char __cdecl sub_C3C540(tagTREEVIEWLISTITEMPARAM *a1, WPARAM wParam)
{
  char result; // al

  result = 0;
  if ( !byte_CDA099 )
    result = sub_C3A870(a1, wParam);
  return result;
}
// CDA099: using guessed type char byte_CDA099;

//----- (00C3C600) --------------------------------------------------------
CSystemProcessInfoMapNode *__thiscall std::_Tree_comp_alloc<std::_Tmap_traits<unsigned long,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *>>,0>>::_Buynode<std::piecewise_construct_t const &,std::tuple<unsigned long &&>,std::tuple<>>(CSystemProcessInfoMap *this, CSystemProcessInfoMapPair *a1)
{
  CSystemProcessInfoMapNode *result; // eax

  result = std::_Tree_comp_alloc<std::_Tmap_traits<unsigned long,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *>>,0>>::_Buynode0(this);
  *(_WORD *)&result->baseclass._Color = 0;
  if ( result != (CSystemProcessInfoMapNode *)-16 )
    result->_Keyvalue = *a1;
  return result;
}

//----- (00C3C630) --------------------------------------------------------
CSystemProcessInfoMapNode **__thiscall sub_C3C630(CSystemProcessInfoMap *thisMap, CSystemProcessInfoMapNode **ppNode, char a3, CSystemProcessInfoMapNode *pNode, CSystemProcessInfoMapPair *pair, int a6)
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
  if ( pNode == (CSystemProcessInfoMapNode *)this->_Header )
  {
    this->_Header->_Parent = (std_Tree_node_for_tagKeyName *)v7;
    this->_Header->_Left = (std_Tree_node_for_tagKeyName *)v7;
    v9 = this->_Header;
LABEL_8:
    v9->_Right = (std__Tree_node_For__bstr_t *)v8;
    goto LABEL_9;
  }
  if ( !a3 )
  {
    pNode->baseclass._Right = v7;
    v9 = this->_Header;
    if ( pNode != (CSystemProcessInfoMapNode *)this->_Header->_Right )
      goto LABEL_9;
    goto LABEL_8;
  }
  pNode->baseclass._Left = v7;
  if ( pNode == (CSystemProcessInfoMapNode *)this->_Header->_Left )
    this->_Header->_Left = (std_Tree_node_for_tagKeyName *)v7;
LABEL_9:
  v10 = (std_Tree_node_for_tagKeyName *)v8;
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

//----- (00C3C840) --------------------------------------------------------
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
  v8 = (CSystemProcessInfoMapPair *)dwThreadId;
  v9 = (CSystemProcessInfoMapNode *)v6;
  v21 = 0;
  v18 = v6;
  v10 = (CSystemProcessInfoMapNode *)v6->_Parent;
  LOBYTE(v19) = 1;
  if ( !v10->baseclass._isnil )
  {
    v11 = *dwThreadId;
    do
    {
      v9 = v10;
      if ( (_BYTE)a3 )
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
    if ( v9 == (CSystemProcessInfoMapNode *)v6->_Left )
    {
      v13 = sub_C3C630(v5, (CSystemProcessInfoMapNode **)&a3, 1, v9, (CSystemProcessInfoMapPair *)dwThreadId, a5);
LABEL_14:
      v14 = *v13;
      result = a2;
      *(_DWORD *)a2 = v14;
      *(_BYTE *)(a2 + 4) = 1;
      return result;
    }
    std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned long const,MAPITEM *>>>,std::_Iterator_base0>::operator--((std__tree *)&a3);
    v12 = (CSystemProcessInfoMapNode *)a3;
  }
  if ( (unsigned int)v12->_Keyvalue._Key < v8->_Key )
  {
    v13 = sub_C3C630(v5, (CSystemProcessInfoMapNode **)&dwThreadId, v19, v9, v8, a5);
    goto LABEL_14;
  }
  *(_DWORD *)a2 = v12;
  result = a2;
  *(_BYTE *)(a2 + 4) = 0;
  return result;
}
// C781AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);

//----- (00C3CA10) --------------------------------------------------------
signed int __stdcall LogBufferCallback(int a1)
{
  return 1;
}

//----- (00C3CA20) --------------------------------------------------------
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
  if ( hFound != (HANDLE)INVALID_HANDLE_VALUE )
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
          (int)&a2,
          0,
          &ThreadId,
          (unsigned __int8)byte_CDA100);
      }
      while ( Thread32Next(hFound_1, &ThreadEntry) );
    }
    hFound = (HANDLE)CloseHandle(hFound_1);
  }
  return hFound;
}
// CDA100: using guessed type char byte_CDA100;

//----- (00C3CAB0) --------------------------------------------------------
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
  LogFile.BufferCallback = (PEVENT_TRACE_BUFFER_CALLBACKW)LogBufferCallback;
  if ( gdwVersion < 3 )
    pszLoggerName = L"NT Kernel Logger";
  LogFile.BuffersRead = 0;
  LogFile.LoggerName = pszLoggerName;
  LogFile.CurrentTime = 0i64;
  LogFile.u2.EventCallback = LogEventCallback;
  LogFile.u.LogFileMode = 0x1100;
  v4 = OpenTraceW_0(&LogFile);
  *(_DWORD *)v2 = v4;
  HIDWORD(Properties->TraceHandle) = HIDWORD(v4);
  if ( v4 )
  {
    do
    {
      ret = ProcessTrace_0((PTRACEHANDLE)&Properties->TraceHandle, 1u, 0, 0);
      if ( ret )
        break;
      if ( WaitForSingleObject(Properties->EventHandle, 0) == WAIT_TIMEOUT )
      {
        ret = PE_RunTrace(Properties, 1);
        v6 = OpenTraceW_0(&LogFile);
        *(_DWORD *)v2 = v6;
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
// CB0784: using guessed type wchar_t aProcexpTrace[14];
// CD4E54: using guessed type int gdwVersion;

//----- (00C3CBD0) --------------------------------------------------------
ULONG __stdcall TraceEventThreadProcEx(EVENT_TRACE_PROPERTIES_EXT *a1)
{
  return TraceEventThreadProc(a1);
}

//----- (00C3CBE0) --------------------------------------------------------
__int64 __thiscall PE_ComputeTime(PE_TIME *this, __int64 time)
{
  __int64 result; // rax

  if ( time >= 0 )
    result = (unsigned __int64)(10000000 * (time % this->Frequency)) / this->Frequency
           + 10000000 * (time / this->Frequency);
  else
    result = -PE_ComputeTime(this, -time);
  return result;
}

//----- (00C3CC70) --------------------------------------------------------
unsigned __int8 *__cdecl sub_C3CC70(int a1, int a2, int a3, wchar_t *Dst, rsize_t SizeInWords)
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
  v6 = *(_DWORD *)(a3 + 8);
  v7 = (wchar_t *)a1;
  v36 = a1;
  switch ( v6 )
  {
    case 0:
      v8 = Dst;
      v9 = 0;
      if ( *(_DWORD *)(a3 + 12) )
      {
        do
        {
          v10 = *(char *)v7;
          v7 = (wchar_t *)((char *)v7 + 1);
          v8[v9++] = v10;
        }
        while ( v9 < *(_DWORD *)(v5 + 12) );
      }
      goto LABEL_4;
    case 1:
      v8 = Dst;
      v14 = 0;
      if ( !*(_DWORD *)(a3 + 12) )
        goto LABEL_4;
      do
      {
        v15 = *v7;
        ++v7;
        v8[v14++] = v15;
      }
      while ( v14 < *(_DWORD *)(v5 + 12) );
      v8[*(_DWORD *)(v5 + 12)] = 0;
      return (unsigned __int8 *)v7 - v36;
    case 2:
      v8 = Dst;
      v12 = 0;
      if ( *(_DWORD *)(a3 + 12) )
      {
        do
        {
          v13 = *(unsigned __int8 *)v7;
          v7 = (wchar_t *)((char *)v7 + 1);
          v8[v12++] = v13;
        }
        while ( v12 < *(_DWORD *)(v5 + 12) );
        v8[*(_DWORD *)(v5 + 12)] = 0;
        result = (unsigned __int8 *)v7 - v36;
      }
      else
      {
LABEL_4:
        v8[*(_DWORD *)(v5 + 12)] = 0;
        result = (unsigned __int8 *)v7 - v36;
      }
      return result;
    case 3:
      swprintf_s(Dst, SizeInWords, L"%d", *(char *)a1);
      return (unsigned __int8 *)((char *)v7 - v36 + 1);
    case 4:
      swprintf_s(Dst, SizeInWords, L"%d", *(signed __int16 *)a1);
      return (unsigned __int8 *)((char *)v7 - v36 + 2);
    case 5:
      swprintf_s(Dst, SizeInWords, L"%u", *(unsigned __int16 *)a1);
      return (unsigned __int8 *)((char *)v7 - v36 + 2);
    case 6:
      swprintf_s(Dst, SizeInWords, L"%d", *(_DWORD *)a1);
      goto LABEL_69;
    case 7:
      swprintf_s(Dst, SizeInWords, L"%lu", *(_DWORD *)a1);
      goto LABEL_69;
    case 8:
      goto LABEL_17;
    case 9:
      v16 = a1 + 8;
      swprintf_s(Dst, SizeInWords, L"%I64d", *(_DWORD *)a1, *(_DWORD *)(a1 + 4));
      return (unsigned __int8 *)(v16 - v36);
    case 10:
      v17 = a1 + 8;
      swprintf_s(Dst, SizeInWords, L"%I64u", *(_DWORD *)a1, *(_DWORD *)(a1 + 4));
      return (unsigned __int8 *)(v17 - v36);
    case 11:
      v18 = a1 + 4;
      v19 = *(float *)a1;
      goto LABEL_21;
    case 12:
      v19 = *(double *)a1;
      v18 = a1 + 8;
LABEL_21:
      swprintf_s(Dst, SizeInWords, L"%f", LODWORD(v19), HIDWORD(v19));
      return (unsigned __int8 *)(v18 - v36);
    case 13:
    case 15:
    case 17:
    case 22:
      switch ( v6 )
      {
        case 13:
        case 22:
          v21 = a1;
          v22 = strlen((const char *)a1);
          for ( i = a1 + 1 + v22; v22; --v22 )
          {
            if ( *(char *)(a1 + v22 - 1) != 255 )
              break;
          }
          break;
        case 15:
          v22 = *(unsigned __int8 *)a1;
          v7 = (wchar_t *)(a1 + 1);
          v21 = a1 + 1;
          i = v22 + a1 + 1;
          break;
        case 17:
          v22 = *(unsigned __int8 *)(a1 + 1) + (*(unsigned __int8 *)a1 << 8);
          v7 = (wchar_t *)(a1 + 2);
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
      return (unsigned __int8 *)(i - v36);
    case 14:
    case 16:
    case 18:
    case 23:
      switch ( v6 )
      {
        case 14:
          v24 = a1;
          v25 = wcslen((const unsigned __int16 *)a1);
          v26 = a1 + 2 + 2 * v25;
          if ( v25 )
          {
            v27 = (_WORD *)(a1 - 2 + 2 * v25);
            do
            {
              v7 = (wchar_t *)a1;
              if ( *v27 != -1 )
                break;
              --v27;
              --v25;
            }
            while ( v25 );
          }
          break;
        case 16:
          v29 = *(unsigned __int8 *)a1;
          v7 = (wchar_t *)(a1 + 1);
          v24 = a1 + 1;
          v26 = v29 + a1 + 1;
          v25 = v29 >> 1;
          break;
        case 18:
          v7 = (wchar_t *)(a1 + 2);
          v24 = a1 + 2;
          v28 = *(unsigned __int8 *)(a1 + 1) + (*(unsigned __int8 *)a1 << 8);
          v26 = v28 + a1 + 2;
          v25 = v28 >> 1;
          break;
        case 23:
          v24 = a1;
          v26 = a2;
          v25 = (unsigned int)(a2 - a1) >> 1;
          break;
        default:
          v24 = a1;
          v25 = a1;
          v26 = a1;
          break;
      }
      if ( 2 * v25 > a2 - v24 )
        v25 = (unsigned int)(a2 - v24) >> 1;
      if ( v25 > SizeInWords - 3 )
        v25 = SizeInWords - 3;
      swprintf_s(Dst, SizeInWords, L"\"%*ws\"", v25, v7);
      return (unsigned __int8 *)(v26 - v36);
    case 19:
      if ( *(_DWORD *)a1 )
      {
        if ( dword_CCE0D0 == 64 )
          v31 = (unsigned __int8 *)(a1 + 16);
        else
          v31 = (unsigned __int8 *)(a1 + 8);
        v32 = 4 * v31[1] + 8;
        sub_C3E4E0((int)&a1, v31);
        if ( a1 )
          v33 = *(const wchar_t **)a1;
        else
          v33 = 0;
        v34 = Dst;
        wcscpy_s(Dst, SizeInWords, v33);
        *v34 = 0;
        _bstr_t::_Free((_bstr_t *)&a1);
        result = &v31[v32 - v36];
      }
      else
      {
        v30 = a1 + 4;
        swprintf_s(Dst, SizeInWords, L"0");
        result = (unsigned __int8 *)(v30 - v36);
      }
      return result;
    case 20:
      swprintf_s(
        Dst,
        SizeInWords,
        L"%03d.%03d.%03d.%03d",
        (unsigned __int8)*(_DWORD *)a1,
        (unsigned __int16)*(_DWORD *)a1 >> 8,
        (*(_DWORD *)a1 >> 16) & 0xFF,
        *(_DWORD *)a1 >> 24);
      return (unsigned __int8 *)((char *)v7 - v36 + 4);
    case 21:
      v20 = ntohs(*(_WORD *)a1);
      swprintf_s(Dst, SizeInWords, L"%u", v20);
      return (unsigned __int8 *)((char *)v7 - v36 + 2);
    case 24:
      if ( dword_CCE0D0 == 64 )
      {
        swprintf_s(Dst, SizeInWords, L"0x%X", *(_QWORD *)a1);
        result = (unsigned __int8 *)((char *)v7 - v36 + 8);
      }
      else
      {
LABEL_17:
        swprintf_s(Dst, SizeInWords, L"0x%08X", *(_DWORD *)a1);
LABEL_69:
        result = (unsigned __int8 *)((char *)v7 - v36 + 4);
      }
      return result;
    case 25:
      sub_C092A0(Dst, SizeInWords, a1);
      return (unsigned __int8 *)((char *)v7 - v36 + 16);
    case 26:
      v35 = L"TRUE";
      if ( !*(_BYTE *)a1 )
        v35 = L"FALSE";
      swprintf_s(Dst, SizeInWords, L"%s", v35);
      goto LABEL_69;
    case 27:
      swprintf_s(
        Dst,
        SizeInWords,
        L"%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x",
        *(unsigned __int8 *)a1,
        *(unsigned __int8 *)(a1 + 1),
        *(unsigned __int8 *)(a1 + 2),
        *(unsigned __int8 *)(a1 + 3),
        *(unsigned __int8 *)(a1 + 4),
        *(unsigned __int8 *)(a1 + 5),
        *(unsigned __int8 *)(a1 + 6),
        *(unsigned __int8 *)(a1 + 7),
        *(unsigned __int8 *)(a1 + 8),
        *(unsigned __int8 *)(a1 + 9),
        *(unsigned __int8 *)(a1 + 10),
        *(unsigned __int8 *)(a1 + 11),
        *(unsigned __int8 *)(a1 + 12),
        *(unsigned __int8 *)(a1 + 13),
        *(unsigned __int8 *)(a1 + 14),
        *(unsigned __int8 *)(a1 + 15));
      return (unsigned __int8 *)((char *)v7 - v36 + 16);
    default:
      goto LABEL_69;
  }
}
// CAE200: using guessed type wchar_t a0x08x[7];
// CCE0D0: using guessed type int dword_CCE0D0;

//----- (00C3D220) --------------------------------------------------------
ULONG __thiscall PE_FlushTrace(LPEVENT_TRACE_PROPERTIES_EXT Properties)
{
  return FlushTraceW(Properties->TraceHandle, 0, &Properties->baseclass);
}

//----- (00C3D240) --------------------------------------------------------
int __cdecl NetworkMsgItem2_FindID(WCHAR *lpszText)
{
  int index; // esi
  int v2; // eax

  index = 0;
  while ( 1 )
  {
    v2 = wcscmp((const unsigned __int16 *)gNetworkMsgItem2[index].szText, lpszText);
    if ( v2 )
      v2 = -(v2 < 0) | 1;
    if ( !v2 )
      break;
    if ( (unsigned int)++index >= 56 )
      return 0;
  }
  return gNetworkMsgItem2[index].nID;
}

//----- (00C3D2B0) --------------------------------------------------------
std_Tree_node_for_tagKeyName *__cdecl sub_C3D2B0(unsigned int a1)
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
      v1 = (std__Tree_node *)v2;
      v2 = v2->_Left;
    }
    else
    {
      v2 = v2->_Right;
    }
  }
  while ( !v2->_IsNil );
  if ( v1 == gThreadProcessMap._Header || (v4 = v1, (std_Tree_node_for_tagKeyName *)a1 < v1[1]._Left) )
LABEL_14:
    v4 = gThreadProcessMap._Header;
  if ( v4 == gThreadProcessMap._Header )
    result = (std_Tree_node_for_tagKeyName *)-1;
  else
    result = v4[1]._Parent;
  return result;
}

//----- (00C3D310) --------------------------------------------------------
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
    StartTraceW_0 = (int (__stdcall *)(PTRACEHANDLE, LPCWSTR, PEVENT_TRACE_PROPERTIES))GetProcAddress(v4, "StartTraceW");
    ControlTraceW_0 = (int (__stdcall *)(TRACEHANDLE, LPCWSTR, PEVENT_TRACE_PROPERTIES, ULONG))GetProcAddress(
                                                                                                 v4,
                                                                                                 "ControlTraceW");
    *(_DWORD *)OpenTraceW_0 = GetProcAddress(v4, "OpenTraceW");
    *(_DWORD *)ProcessTrace_0 = GetProcAddress(v4, "ProcessTrace");
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
    _mm_storeu_si128((__m128i *)&Properties->baseclass.Wnode.Guid, _mm_loadu_si128((const __m128i *)&stru_CB00E0));
  Properties->baseclass.LoggerNameOffset = 120;
  Properties->baseclass.LogFileNameOffset = 640;
  pszSessionName = L"PROCEXP TRACE";
  if ( gdwVersion < WINDOWS_8 )
    pszSessionName = L"NT Kernel Logger";
  wcscpy_s((wchar_t *)Properties->szSessionName, MAX_PATH, pszSessionName);
  wcscpy_s((wchar_t *)Properties->szLogFileName, MAX_PATH, (const wchar_t *)&gszNullString);
  EnableFlags = Properties->baseclass.EnableFlags | 0x10100;// EVENT_TRACE_FLAG_DISK_IO|EVENT_TRACE_FLAG_NETWORK_TCPIP
  Properties->baseclass.EnableFlags = EnableFlags;
  if ( gdwVersion >= WINDOWS_8 )
    Properties->baseclass.EnableFlags = EnableFlags | EVENT_TRACE_FLAG_THREAD;
  if ( fStart )
  {
    uret = StartTraceW_0(&Properties->SessionHandle, (LPCWSTR)Properties->szSessionName, &Properties->baseclass);
    lRet = uret;
    if ( !uret || uret == ERROR_ALREADY_EXISTS )
    {
      Properties->fTraceStarted = 1;
      lRet = 0;
      Properties->ThreadHandle = (HANDLE)_beginthreadex(
                                           0,
                                           0,
                                           (int)TraceEventThreadProcEx,
                                           (int)Properties,
                                           0,
                                           &ThreadId);
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
             (LPCWSTR)Properties->szSessionName,
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
// CB00E0: using guessed type GUID stru_CB00E0;
// CB0784: using guessed type wchar_t aProcexpTrace[14];
// CD4E54: using guessed type int gdwVersion;

//----- (00C3D510) --------------------------------------------------------
void __cdecl sub_C3D510(EVENT_TRACE *EventTrace, tagEventItem *pEventItem)
{
  ULONG ThreadId; // eax
  Data_t_bstr_t *v3; // eax
  Data_t_bstr_t *v4; // esi
  Data_t_bstr_t *v5; // eax
  OLECHAR *v6; // eax
  Data_t_bstr_t *v7; // edi
  int v8; // esi
  const unsigned __int16 *v9; // eax
  int v10; // eax
  int v11; // eax
  UCHAR Type; // cl
  EVENT_TRACE *v13; // ecx
  std__list_node *v14; // eax
  int *MofData; // ebx
  std__list_node *v16; // edi
  tagEventSetItem *v17; // esi
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
  tagEventItem *ParamIn; // [esp+6Ch] [ebp-820h]
  void *v46; // [esp+70h] [ebp-81Ch]
  _bstr_t a3; // [esp+74h] [ebp-818h]
  EVENT_TRACE *EventTrace_1; // [esp+78h] [ebp-814h]
  WCHAR psz[1024]; // [esp+7Ch] [ebp-810h]
  int v50; // [esp+888h] [ebp-4h]

  EventTrace_1 = EventTrace;
  ParamIn = pEventItem;
  memset(Buffer, 0, 0x4Cu);
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
  *(_QWORD *)&Buffer[3] = PE_ComputeTime(&gTime, v41);
  v3 = (Data_t_bstr_t *)operator new(0xCu);
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
  v5 = pEventItem->strHeader.m_Data;
  if ( v5 && (v6 = v5->m_wstr) != 0 && SysStringLen(v6) )
  {
    v7 = pEventItem->strHeader.m_Data;
    v8 = 0;
    Buffer[1] = 0;
    while ( 1 )
    {
      if ( v7 )
        v9 = v7->m_wstr;
      else
        v9 = 0;
      v10 = wcscmp(v9, (const unsigned __int16 *)gReadWriteMsgItem[v8].szText);
      if ( v10 )
        v10 = -(v10 < 0) | 1;
      if ( !v10 )
        break;
      if ( (unsigned int)++v8 >= 3 )
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
  v14 = ParamIn->ItemList._Mypair._Myval2._Myhead;
  MofData = (int *)EventTrace_1->MofData;
  v16 = v14->_Next;
  if ( v14->_Next != v14 )
  {
    while ( (char *)MofData < (char *)v13->MofData + v13->MofLength )
    {
      v17 = (tagEventSetItem *)v16->_Myval;
      v18 = v17->field_4 + 1;
      while ( 2 )
      {
        switch ( v18 )
        {
          case 0u:
            if ( v17->bstrName )
              v19 = *(WCHAR **)v17->bstrName;
            else
              v19 = 0;
            v20 = NetworkMsgItem2_FindID(v19);
            v17->field_4 = v20;
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
            v23 = *MofData;
            ++MofData;
            Buffer[5] = v23;
            goto LABEL_69;
          case 0xEu:
            v24 = *MofData;
            ++MofData;
            Buffer[6] = v24;
            goto LABEL_69;
          case 0xFu:
            v25 = *MofData;
            ++MofData;
            Buffer[7] = v25;
            Buffer[8] = 0;
            goto LABEL_69;
          case 0x10u:
            v26 = *MofData;
            ++MofData;
            Buffer[9] = v26;
            goto LABEL_69;
          case 0x11u:
            Buffer[11] = *MofData;
            v27 = MofData[1];
            MofData += 2;
            Buffer[12] = v27;
            goto LABEL_69;
          case 0x12u:
            Buffer[13] = *MofData;
            if ( dword_CCE0D0 == 64 )
            {
              v28 = MofData[1];
              MofData += 2;
              Buffer[14] = v28;
            }
            else
            {
              Buffer[14] = 0;
              ++MofData;
            }
            goto LABEL_69;
          case 0x13u:
            Buffer[15] = *MofData;
            if ( dword_CCE0D0 == 64 )
            {
              v29 = MofData[1];
              MofData += 2;
              Buffer[16] = v29;
            }
            else
            {
              Buffer[16] = 0;
              ++MofData;
            }
            goto LABEL_69;
          case 0x14u:
            Buffer[17] = *MofData;
            v30 = MofData[1];
            MofData += 2;
            Buffer[18] = v30;
            goto LABEL_69;
          case 0x15u:
            v31 = *MofData;
            Buffer[0] = *MofData;
            if ( ProcessId == -1 )
              ProcessId = (ULONG)sub_C3D2B0(v31);
            goto LABEL_69;
          default:
LABEL_34:
            psz[0] = 0;
            MofData = (int *)((char *)MofData
                            + (_DWORD)sub_C3CC70(
                                        (int)MofData,
                                        (int)v13->MofData + v13->MofLength,
                                        (int)v17,
                                        psz,
                                        0x400u));
            _bstr_t::operator+=(&a2a, (_bstr_t *)v17);
            v21 = (Data_t_bstr_t *)operator new(0xCu);
            v46 = v21;
            LOBYTE(v50) = 2;
            if ( v21 )
              v22 = (Data_t_bstr_t *)_bstr_t::Data_t::Data_t(v21, &a2a, &gNullString);
            else
              v22 = 0;
            LOBYTE(v50) = 0;
            if ( !v22 )
              goto LABEL_7;
            _bstr_t::_Free(&a2a);
            a2a.m_Data = v22;
            _bstr_t::_bstr_t((tagEventSetItem *)&a3, psz);
            LOBYTE(v50) = 3;
            v32 = (Data_t_bstr_t *)operator new(0xCu);
            v46 = v32;
            LOBYTE(v50) = 4;
            v33 = (Data_t_bstr_t *)(v32 ? _bstr_t::Data_t::Data_t(v32, &a2a, &a3) : 0);
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
                  operator delete[](v34->m_str);
                  v34->m_str = 0;
                }
                operator delete(v34);
              }
              a3.m_Data = 0;
            }
            v35 = (Data_t_bstr_t *)operator new(0xCu);
            v46 = v35;
            LOBYTE(v50) = 5;
            v36 = (Data_t_bstr_t *)(v35 ? _bstr_t::Data_t::Data_t(v35, &a2a, &gNullString) : 0);
            LOBYTE(v50) = 0;
            if ( !v36 )
              goto LABEL_7;
            _bstr_t::_Free(&a2a);
            a2a.m_Data = v36;
LABEL_69:
            v16 = v16->_Next;
            v13 = EventTrace_1;
            if ( v16 == ParamIn->ItemList._Mypair._Myval2._Myhead )
              goto LABEL_70;
            break;
        }
        break;
      }
    }
  }
LABEL_70:
  v37 = (Data_t_bstr_t *)operator new(0xCu);
  v46 = v37;
  LOBYTE(v50) = 6;
  if ( v37 )
    v38 = (Data_t_bstr_t *)_bstr_t::Data_t::Data_t(v37, &a2a, &gNullString);
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
      operator delete[](v39->m_str);
      v39->m_str = 0;
    }
    operator delete(v39);
  }
  a2a.m_Data = v38;
  sub_C65250((int *)&ProcessId);
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
      operator delete[](v40->m_str);
      v40->m_str = 0;
    }
    operator delete(v40);
  }
}
// CB06FC: using guessed type NetworkMsgItem gReadWriteMsgItem[3];
// CCE0D0: using guessed type int dword_CCE0D0;

//----- (00C3DB10) --------------------------------------------------------
void __stdcall LogEventCallback(PEVENT_TRACE EventTrace)
{
  tagEventItem *v1; // eax

  if ( EventTrace )
  {
    v1 = (tagEventItem *)WbemServiceList_LogEvent(
                           (tagWbemServicesList *)&gWbemServiceList,
                           &EventTrace->Header.u3.Guid,
                           EventTrace->Header.u2.Class.Type,
                           EventTrace->Header.u2.Class.Version,
                           EventTrace->Header.u2.Class.Level);
    if ( v1 )
      sub_C3DB50(EventTrace, v1);
  }
}

//----- (00C3DB50) --------------------------------------------------------
void __cdecl sub_C3DB50(EVENT_TRACE *EventTrace, tagEventItem *a2)
{
  Data_t_bstr_t *v2; // esi
  const unsigned __int16 *v3; // eax
  int v4; // eax
  const unsigned __int16 *v5; // eax
  int v6; // eax
  const unsigned __int16 *v7; // eax
  int v8; // eax
  const unsigned __int16 *v9; // eax
  int v10; // eax
  const unsigned __int16 *v11; // eax
  int v12; // eax

  if ( EventTrace->MofData || !EventTrace->MofLength )
  {
    v2 = a2->strEventTrace.m_Data;
    if ( a2->strEventTrace.m_Data )
      v3 = v2->m_wstr;
    else
      v3 = 0;
    v4 = wcscmp(v3, L"DiskIo");
    if ( v4 )
      v4 = -(v4 < 0) | 1;
    if ( v4 )
    {
      if ( v2 )
        v5 = v2->m_wstr;
      else
        v5 = 0;
      v6 = wcscmp(v5, L"Thread");
      if ( v6 )
        v6 = -(v6 < 0) | 1;
      if ( v6 )
      {
        if ( v2 )
          v7 = v2->m_wstr;
        else
          v7 = 0;
        v8 = wcscmp(v7, L"TcpIp");
        if ( v8 )
          v8 = -(v8 < 0) | 1;
        if ( !v8 )
          goto LABEL_38;
        if ( v2 )
          v9 = v2->m_wstr;
        else
          v9 = 0;
        v10 = wcscmp(v9, L"UdpIp");
        if ( v10 )
          v10 = -(v10 < 0) | 1;
        if ( !v10 )
          goto LABEL_38;
        v11 = v2 ? v2->m_wstr : 0;
        v12 = wcscmp(v11, L"MSNT_TcpIpInformation");
        if ( v12 )
          v12 = -(v12 < 0) | 1;
        if ( !v12 )
LABEL_38:
          sub_C3DCE0(EventTrace, a2);
      }
      else
      {
        sub_C3E310(EventTrace, a2);
      }
    }
    else
    {
      sub_C3D510(EventTrace, a2);
    }
  }
}
// CB0730: using guessed type wchar_t aDiskio[7];
// CB0740: using guessed type wchar_t aTcpip[6];
// CB074C: using guessed type wchar_t aUdpip[6];
// CB0758: using guessed type wchar_t aMsntTcpipinfor[22];

//----- (00C3DCE0) --------------------------------------------------------
void __cdecl sub_C3DCE0(EVENT_TRACE *EventTrace, tagEventItem *a2)
{
  ULONG v2; // eax
  Data_t_bstr_t *v3; // eax
  Data_t_bstr_t *v4; // esi
  tagEventItem *v5; // edi
  const wchar_t *v6; // eax
  OLECHAR **v7; // eax
  OLECHAR *v8; // eax
  const unsigned __int16 **v9; // edi
  int nIndex; // esi
  const unsigned __int16 *v11; // eax
  int v12; // eax
  EVENT_TRACE *v13; // edx
  std__list_node *v14; // eax
  unsigned int v15; // esi
  std__list_node *v16; // edi
  int v17; // ecx
  unsigned int v18; // eax
  UCHAR v19; // cl
  WCHAR *v20; // eax
  int v21; // eax
  Data_t_bstr_t *v22; // esi
  Data_t_bstr_t *v23; // eax
  Data_t_bstr_t *v24; // edi
  __m128i v25; // xmm0
  int v26; // eax
  __m128i v27; // xmm0
  int v28; // eax
  int v29; // eax
  ULONG v30; // eax
  Data_t_bstr_t *v31; // esi
  __m128i v32; // xmm1
  int v33; // edx
  __m128i v34; // xmm0
  __int16 v35; // cx
  __int16 v36; // ax
  Data_t_bstr_t *v37; // esi
  unsigned __int8 *v38; // [esp+10h] [ebp-874h]
  _bstr_t *a2a; // [esp+14h] [ebp-870h]
  _bstr_t v40; // [esp+18h] [ebp-86Ch]
  tagEventItem *v41; // [esp+1Ch] [ebp-868h]
  EVENT_TRACE *v42; // [esp+20h] [ebp-864h]
  ULONG v43; // [esp+24h] [ebp-860h]
  ULONG v44; // [esp+28h] [ebp-85Ch]
  int v45; // [esp+2Ch] [ebp-858h]
  __int64 v46; // [esp+34h] [ebp-850h]
  int v47; // [esp+3Ch] [ebp-848h]
  int v48; // [esp+40h] [ebp-844h]
  __int128 v49; // [esp+44h] [ebp-840h]
  int v50; // [esp+54h] [ebp-830h]
  __int128 v51; // [esp+58h] [ebp-82Ch]
  int v52; // [esp+68h] [ebp-81Ch]
  int v53; // [esp+6Ch] [ebp-818h]
  _bstr_t v54; // [esp+70h] [ebp-814h]
  __int16 psz[1024]; // [esp+74h] [ebp-810h]
  int v56; // [esp+880h] [ebp-4h]

  v41 = a2;
  v42 = EventTrace;
  memset(&v44, 0, sizeof(STATSTG));
  v54.m_Data = 0;
  v43 = EventTrace->Header.ProcessId;
  v2 = EventTrace->Header.ThreadId;
  v56 = 0;
  if ( v2 == -1 )
    v2 = 0;
  v47 = 0;
  v44 = v2;
  v45 = 1;
  v48 = 0;
  v50 = 0;
  v52 = 0;
  v53 = 0;
  _mm_storeu_si128((__m128i *)&v49, (__m128i)0i64);
  _mm_storeu_si128((__m128i *)&v51, (__m128i)0i64);
  v3 = (Data_t_bstr_t *)operator new(0xCu);
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
  LOBYTE(v56) = 0;
  v54.m_Data = v4;
  if ( !v4 )
    _com_issue_error(E_OUTOFMEMORY);
  v5 = v41;
  v46 = PE_ComputeTime(&gTime, EventTrace->Header.u4.s.KernelTime + EventTrace->Header.u4.s.UserTime);
  if ( v41->strEventTrace.m_Data )
    v6 = v41->strEventTrace.m_Data->m_wstr;
  else
    v6 = 0;
  v47 = 2 - (_wcsnicmp(v6, L"Udp", 3u) != 0);
  v7 = &v41->strHeader.m_Data->m_wstr;
  if ( !v7 || (v8 = *v7) == 0 || !SysStringLen(v8) )
  {
    v13 = v42;
    v19 = v42->Header.u2.Class.Type;
    if ( v19 == 11 )
      v45 = 3;
    else
      v45 = (v19 == 10) + 1;
    goto LABEL_25;
  }
  v9 = (const unsigned __int16 **)&v41->strHeader.m_Data->m_wstr;
  nIndex = 0;
  v45 = 0;
  while ( 1 )
  {
    if ( v9 )
      v11 = *v9;
    else
      v11 = 0;
    v12 = wcscmp(v11, (const unsigned __int16 *)gNetworkMsgItem[nIndex].szText);
    if ( v12 )
      v12 = -(v12 < 0) | 1;
    if ( !v12 )
      break;
    if ( (unsigned int)++nIndex >= 24 )
      goto LABEL_74;
  }
  v45 = gNetworkMsgItem[nIndex].nID;
  if ( v45 )
  {
    v13 = v42;
    v5 = v41;
LABEL_25:
    v14 = v5->ItemList._Mypair._Myval2._Myhead;
    v15 = (unsigned int)v13->MofData;
    v16 = v14->_Next;
    if ( v14->_Next != v14 )
    {
      do
      {
        if ( (PVOID)v15 >= (char *)v13->MofData + v13->MofLength )
          break;
        v17 = (int)v16->_Myval;
        a2a = (_bstr_t *)v17;
        v18 = *(_DWORD *)(v17 + 4) + 1;
        while ( 2 )
        {
          switch ( v18 )
          {
            case 0u:
              if ( *(_DWORD *)v17 )
                v20 = **(WCHAR ***)v17;
              else
                v20 = 0;
              v21 = NetworkMsgItem2_FindID(v20);
              v17 = (int)a2a;
              a2a[1].m_Data = (Data_t_bstr_t *)v21;
              v18 = v21 + 1;
              if ( v18 <= 9 )
                continue;
              goto LABEL_36;
            case 1u:
            case 2u:
            case 3u:
LABEL_36:
              v13 = v42;
              goto LABEL_37;
            case 4u:
              if ( *(_DWORD *)(v17 + 8) == 27 )
              {
                LOBYTE(v51) = 1;
                v25 = _mm_loadu_si128((const __m128i *)v15);
                v15 += 16;
                _mm_storeu_si128((__m128i *)((char *)&v51 + 4), v25);
              }
              else
              {
                LOBYTE(v51) = 0;
                v26 = *(_DWORD *)v15;
                v15 += 4;
                DWORD1(v51) = v26;
              }
              break;
            case 5u:
              if ( *(_DWORD *)(v17 + 8) == 27 )
              {
                LOBYTE(v49) = 1;
                v27 = _mm_loadu_si128((const __m128i *)v15);
                v15 += 16;
                _mm_storeu_si128((__m128i *)((char *)&v49 + 4), v27);
              }
              else
              {
                LOBYTE(v49) = 0;
                v28 = *(_DWORD *)v15;
                v15 += 4;
                DWORD1(v49) = v28;
              }
              break;
            case 6u:
              HIWORD(v53) = ntohs(*(_WORD *)v15);
              v15 += 2;
              break;
            case 7u:
              LOWORD(v53) = ntohs(*(_WORD *)v15);
              v15 += 2;
              break;
            case 8u:
              v29 = *(_DWORD *)v15;
              v15 += 4;
              v48 = v29;
              break;
            case 9u:
              v30 = *(_DWORD *)v15;
              v15 += 4;
              v43 = v30;
              break;
            default:
LABEL_37:
              psz[0] = 0;
              v38 = &sub_C3CC70(v15, (int)v13->MofData + v13->MofLength, v17, (wchar_t *)psz, 0x400u)[v15];
              _bstr_t::operator+=(&v54, a2a);
              _bstr_t::operator+=(&v54, &gNullString);
              _bstr_t::_bstr_t((tagEventSetItem *)&v40, (OLECHAR *)psz);
              LOBYTE(v56) = 2;
              _bstr_t::operator+=(&v54, &v40);
              v22 = v40.m_Data;
              LOBYTE(v56) = 0;
              if ( v40.m_Data )
              {
                if ( !InterlockedDecrement(&v40.m_Data->m_RefCount) )
                {
                  if ( v22->m_wstr )
                  {
                    SysFreeString(v22->m_wstr);
                    v22->m_wstr = 0;
                  }
                  if ( v22->m_str )
                  {
                    operator delete[](v22->m_str);
                    v22->m_str = 0;
                  }
                  operator delete(v22);
                }
                v40.m_Data = 0;
              }
              _bstr_t::operator+=(&v54, &gNullString);
              v15 = (unsigned int)v38;
              break;
          }
          break;
        }
        v16 = v16->_Next;
        v13 = v42;
      }
      while ( v16 != v41->ItemList._Mypair._Myval2._Myhead );
    }
    v23 = (Data_t_bstr_t *)operator new(0xCu);
    LOBYTE(v56) = 3;
    if ( v23 )
      v24 = (Data_t_bstr_t *)_bstr_t::Data_t::Data_t(v23, &v54, &gNullString);
    else
      v24 = 0;
    LOBYTE(v56) = 0;
    if ( !v24 )
      _com_issue_error(E_OUTOFMEMORY);
    v31 = v54.m_Data;
    if ( v54.m_Data && !InterlockedDecrement(&v54.m_Data->m_RefCount) && v31 )
    {
      if ( v31->m_wstr )
      {
        SysFreeString(v31->m_wstr);
        v31->m_wstr = 0;
      }
      if ( v31->m_str )
      {
        operator delete[](v31->m_str);
        v31->m_str = 0;
      }
      operator delete(v31);
    }
    v54.m_Data = v24;
    if ( v47 == 2 && v45 == 3 )
    {
      v32 = _mm_loadu_si128((const __m128i *)&v51);
      v33 = v52;
      v34 = _mm_loadu_si128((const __m128i *)&v49);
      v35 = HIWORD(v53);
      v52 = v50;
      v36 = v53;
      _mm_storeu_si128((__m128i *)&v51, v34);
      HIWORD(v53) = v36;
      _mm_storeu_si128((__m128i *)&v49, v32);
      v50 = v33;
      LOWORD(v53) = v35;
    }
    sub_C65310((int *)&v43);
  }
LABEL_74:
  v37 = v54.m_Data;
  if ( v54.m_Data && !InterlockedDecrement(&v54.m_Data->m_RefCount) && v37 )
  {
    if ( v37->m_wstr )
    {
      SysFreeString(v37->m_wstr);
      v37->m_wstr = 0;
    }
    if ( v37->m_str )
    {
      operator delete[](v37->m_str);
      v37->m_str = 0;
    }
    operator delete(v37);
  }
}

//----- (00C3E310) --------------------------------------------------------
int **__cdecl sub_C3E310(EVENT_TRACE *EventTrace, tagEventItem *pEventItem)
{
  signed int v2; // edi
  Data_t_bstr_t *v3; // eax
  const unsigned __int16 *v4; // eax
  int fStart; // eax
  Data_t_bstr_t *v6; // eax
  const unsigned __int16 *v7; // eax
  int **fEnd; // eax
  EVENT_TRACE *EventTrace_1; // ecx
  tagEventItem *pEventItem_1; // edx
  std__list_node *_Myhead; // eax
  int **v12; // ebx
  std__list_node *v13; // esi
  tagEventSetItem *pEventSetItem; // edi
  int v15; // eax
  WCHAR *v16; // eax
  int *v17; // eax
  const unsigned __int16 **v18; // eax
  const unsigned __int16 *v19; // eax
  int v20; // eax
  int dwThreadId; // [esp+8h] [ebp-10h]
  unsigned int a3; // [esp+Ch] [ebp-Ch]
  int a2a; // [esp+10h] [ebp-8h]
  int *a4; // [esp+14h] [ebp-4h]

  v2 = -1;
  a4 = (int *)-1;
  a3 = -1;
  v3 = pEventItem->strHeader.m_Data;
  if ( v3 )
    v4 = v3->m_wstr;
  else
    v4 = 0;
  fStart = wcscmp(v4, L"Start");
  if ( fStart )
    fStart = -(fStart < 0) | 1;
  if ( !fStart )
    goto LABEL_39;
  v6 = pEventItem->strHeader.m_Data;
  if ( v6 )
    v7 = v6->m_wstr;
  else
    v7 = 0;
  fEnd = (int **)wcscmp(v7, L"End");
  if ( fEnd )
    fEnd = (int **)(-((signed int)fEnd < 0) | 1);
  if ( !fEnd )
  {
LABEL_39:
    EventTrace_1 = EventTrace;
    pEventItem_1 = pEventItem;
    _Myhead = pEventItem->ItemList._Mypair._Myval2._Myhead;
    v12 = (int **)EventTrace->MofData;
    v13 = _Myhead->_Next;
    if ( _Myhead->_Next != _Myhead )
    {
      while ( 1 )
      {
        if ( (char *)v12 >= (char *)EventTrace_1->MofData + EventTrace_1->MofLength )
          goto LABEL_29;
        pEventSetItem = (tagEventSetItem *)v13->_Myval;
        v15 = pEventSetItem->field_4;
        if ( v15 == -1 )
        {
          do
          {
            if ( pEventSetItem->bstrName )
              v16 = *(WCHAR **)pEventSetItem->bstrName;
            else
              v16 = 0;
            v15 = NetworkMsgItem2_FindID(v16);
            pEventSetItem->field_4 = v15;
          }
          while ( v15 == -1 );
          EventTrace_1 = EventTrace;
          pEventItem_1 = pEventItem;
        }
        if ( v15 == 53 )
          break;
        v2 = a3;
        if ( v15 != 54 )
          goto LABEL_25;
        v17 = *v12;
        ++v12;
        a4 = v17;
LABEL_26:
        if ( v2 == -1 || v17 == (int *)-1 )
        {
          v13 = v13->_Next;
          if ( v13 != pEventItem_1->ItemList._Mypair._Myval2._Myhead )
            continue;
        }
        goto LABEL_29;
      }
      v2 = (signed int)*v12;
      ++v12;
      a3 = v2;
LABEL_25:
      v17 = a4;
      goto LABEL_26;
    }
LABEL_29:
    v18 = (const unsigned __int16 **)&pEventItem_1->strHeader.m_Data->m_wstr;
    if ( v18 )
      v19 = *v18;
    else
      v19 = 0;
    v20 = wcscmp(v19, L"Start");
    if ( v20 )
      v20 = -(v20 < 0) | 1;
    if ( v20 )
    {
      sub_C3E560((std__tree *)&gThreadProcessMap, &a2a, &a3);
      fEnd = sub_C65510((std__tree *)&gThreadProcessMap, (int **)&pEventItem, (std__Tree_node *)a2a, a4);
    }
    else
    {
      a3 = (unsigned int)a4;
      dwThreadId = v2;
      fEnd = (int **)std::map<unsigned long,unsigned long,std::less<unsigned long>,std::allocator<std::pair<unsigned long const,unsigned long>>>::operator[](
                       &gThreadProcessMap,
                       (int)&a2a,
                       0,
                       &dwThreadId,
                       (unsigned __int8)byte_CDA100);
    }
  }
  return fEnd;
}
// CB06F4: using guessed type wchar_t aEnd[4];
// CDA100: using guessed type char byte_CDA100;

//----- (00C3E4E0) --------------------------------------------------------
int __cdecl sub_C3E4E0(int a1, PSID Sid)
{
  LPWSTR StringSid; // [esp+Ch] [ebp-10h]
  int v4; // [esp+18h] [ebp-4h]

  StringSid = 0;
  *(_DWORD *)a1 = 0;
  v4 = 0;
  if ( ConvertSidToStringSidW(Sid, &StringSid) )
  {
    _bstr_t::operator=((EventItem *)a1, StringSid);
    LocalFree(StringSid);
  }
  return a1;
}

//----- (00C3E560) --------------------------------------------------------
_DWORD *__thiscall sub_C3E560(std__tree *this, _DWORD *a2, unsigned int *a3)
{
  std__Tree_node *v3; // ebx
  std__Tree_node *v4; // edx
  std_Tree_node_for_tagKeyName *v5; // eax
  std_Tree_node_for_tagKeyName *v6; // ecx
  unsigned int v7; // edi
  unsigned int v8; // esi
  _DWORD *result; // eax

  v3 = this->_Mypair._Myval2._Myhead;
  v4 = this->_Mypair._Myval2._Myhead;
  v5 = this->_Mypair._Myval2._Myhead->_Parent;
  v6 = this->_Mypair._Myval2._Myhead->_Parent;
  if ( !v6->_IsNil )
  {
    v7 = *a3;
    do
    {
      v8 = v6->_Myval.first;
      if ( v8 >= v7 )
      {
        if ( v4->_IsNil && v7 < v8 )
          v4 = (std__Tree_node *)v6;
        v3 = (std__Tree_node *)v6;
        v6 = v6->_Left;
      }
      else
      {
        v6 = v6->_Right;
      }
    }
    while ( !v6->_IsNil );
  }
  if ( !v4->_IsNil )
    v5 = v4->_Left;
  while ( !v5->_IsNil )
  {
    if ( *a3 >= v5->_Myval.first )
    {
      v5 = v5->_Right;
    }
    else
    {
      v4 = (std__Tree_node *)v5;
      v5 = v5->_Left;
    }
  }
  result = a2;
  *a2 = v3;
  a2[1] = v4;
  return result;
}

//----- (00C3E5E0) --------------------------------------------------------
void __stdcall sub_C3E5E0(std__Tree_node *a1)
{
  std__Tree_node *v1; // edi
  std__Tree_node *i; // esi

  v1 = a1;
  for ( i = a1; !i->_IsNil; v1 = i )
  {
    sub_C3E5E0((std__Tree_node *)i->_Right);
    i = (std__Tree_node *)i->_Left;
    operator delete(v1);
  }
}

//----- (00C3E620) --------------------------------------------------------
std__Tree_node *__thiscall sub_C3E620(std__tree *this)
{
  std__tree *v1; // edi
  std__Tree_node *v2; // ebx
  std__Tree_node *i; // esi
  std__Tree_node *result; // eax

  v1 = this;
  v2 = (std__Tree_node *)this->_Mypair._Myval2._Myhead->_Parent;
  for ( i = v2; !i->_IsNil; v2 = i )
  {
    sub_C3E5E0((std__Tree_node *)i->_Right);
    i = (std__Tree_node *)i->_Left;
    operator delete(v2);
  }
  v1->_Mypair._Myval2._Myhead->_Parent = (std_Tree_node_for_tagKeyName *)v1->_Mypair._Myval2._Myhead;
  v1->_Mypair._Myval2._Myhead->_Left = (std_Tree_node_for_tagKeyName *)v1->_Mypair._Myval2._Myhead;
  result = v1->_Mypair._Myval2._Myhead;
  result->_Right = (std__Tree_node_For__bstr_t *)result;
  v1->_Mypair._Myval2._Mysize = 0;
  return result;
}

//----- (00C3E670) --------------------------------------------------------
_DWORD *__thiscall sub_C3E670(_DWORD *this, int a2, int a3, int a4, int a5, int a6)
{
  *this = a2;
  this[3] = a3;
  this[1] = a4;
  this[4] = a5;
  this[6] = a6;
  return this;
}

//----- (00C3E6A0) --------------------------------------------------------
wchar_t **__thiscall sub_C3E6A0(int **this, wchar_t *a2)
{
  int **v2; // edi
  wchar_t *v3; // eax
  int *v4; // esi
  int v5; // ebx
  wchar_t **v6; // eax
  wchar_t **result; // eax
  wchar_t *v8; // [esp+28h] [ebp+8h]

  v2 = this;
  v3 = a2;
  if ( a2 >= (wchar_t *)this[1] )
    goto LABEL_13;
  v4 = this[3];
  if ( a2 )
  {
    do
    {
      v4 = (int *)((char *)v4 + *v4);
      v3 = (wchar_t *)((char *)v3 - 1);
    }
    while ( v3 );
  }
  if ( *v4
    && ((v8 = (wchar_t *)sub_C22D20((unsigned int *)this[4], v4[1]), !v2[6]) ? (v5 = **v2) : (v5 = 0),
        (v6 = (wchar_t **)operator new(0x10u)) != 0) )
  {
    result = sub_C3EC40(v6, v8, v4[7], (char *)*v2 + v4[9] + v5, v4[8]);
  }
  else
  {
LABEL_13:
    result = 0;
  }
  return result;
}

//----- (00C3E760) --------------------------------------------------------
wchar_t **__thiscall sub_C3E760(PerformanceInfo **this, LPCWSTR lpsz)
{
  PerformanceInfo **v2; // esi
  int v3; // eax
  PerformanceInfo *v4; // ecx
  PerformanceInfo *v5; // edi
  wchar_t **result; // eax
  signed int v7; // ebx
  wchar_t **v8; // eax
  wchar_t *lpsza; // [esp+28h] [ebp+8h]

  v2 = this;
  v3 = PerformanceInfo::FindPerf(this[4], lpsz);
  if ( !v3 )
    goto LABEL_5;
  v4 = v2[1];
  v5 = v2[3];
  v2[2] = 0;
  if ( !v4 )
    goto LABEL_5;
  while ( v5->m_LastCounterOfLastHelp != (WCHAR **)v3 )
  {
    v5 = (PerformanceInfo *)((char *)v5 + v5->m_dwLastCounterOfLastHelp);
    v2[2] = (PerformanceInfo *)((char *)v2[2] + 1);
    if ( v2[2] >= v4 )
      goto LABEL_5;
  }
  lpsza = (wchar_t *)sub_C22D20((unsigned int *)v2[4], (unsigned int)v5->m_LastCounterOfLastHelp);
  v7 = v2[6] ? 0 : (*v2)->m_dwLastCounterOfLastHelp;
  v8 = (wchar_t **)operator new(0x10u);
  if ( v8 )
    result = sub_C3EC40(
               v8,
               lpsza,
               (int)v5[2].m_LastCounterOfLastHelp,
               (char *)*v2 + v5[3].m_dwLastCounterOfLastHelp + v7,
               (unsigned int)v5[2].m_PerfValue);
  else
LABEL_5:
    result = 0;
  return result;
}

//----- (00C3E830) --------------------------------------------------------
wchar_t **__thiscall sub_C3E830(int this)
{
  *(_DWORD *)(this + 8) = 0;
  return sub_C3E6A0((int **)this, 0);
}

//----- (00C3E840) --------------------------------------------------------
wchar_t **__thiscall sub_C3E840(int this)
{
  return sub_C3E6A0((int **)this, (wchar_t *)++*(_DWORD *)(this + 8));
}

//----- (00C3E850) --------------------------------------------------------
int __thiscall sub_C3E850(int *this, wchar_t *Dst, rsize_t SizeInWords)
{
  int v4; // ecx

  if ( this[6] )
  {
    *Dst = 0;
    return 0;
  }
  v4 = *this;
  if ( SizeInWords < *(_DWORD *)(v4 + 20) >> 1 )
    return 0;
  wcscpy_s(Dst, SizeInWords, (const wchar_t *)(v4 + *(_DWORD *)(v4 + 16)));
  return 1;
}

//----- (00C3E8B0) --------------------------------------------------------
PE_PerfInfo_Item *__thiscall PE_PerfInfo::Load(PE_PerfInfo *this, LPCWSTR lpszName)
{
  PE_PerfInfo *v2; // ebx
  WCHAR *pszText; // esi
  unsigned int v4; // edi
  PE_PerfInfo_Item *result; // eax
  PE_PerfInfo_Item *pItem; // eax
  LPCWSTR index; // [esp+24h] [ebp+8h]

  v2 = this;
  index = (LPCWSTR)PerformanceInfo::FindPerf((PerformanceInfo *)this->m_PerfInfo, lpszName);
  if ( !index )
    goto LABEL_5;
  pszText = sub_C3EFA0((PerformanceInfoInMemory *)v2->m_PerfInfoInMemory);
  v4 = 0;
  if ( !sub_C3EF90((PerformanceInfoInMemory *)v2->m_PerfInfoInMemory) )
    goto LABEL_5;
  while ( *((LPCWSTR *)pszText + 3) != index )
  {
    ++v4;
    pszText = (WCHAR *)((char *)pszText + *(_DWORD *)pszText);
    if ( v4 >= sub_C3EF90((PerformanceInfoInMemory *)v2->m_PerfInfoInMemory) )
      goto LABEL_5;
  }
  pItem = (PE_PerfInfo_Item *)operator new(0x10u);
  if ( pItem )
    result = sub_C3ED40(pItem, (int)pszText, (PerformanceInfo *)v2->m_PerfInfo);
  else
LABEL_5:
    result = 0;
  return result;
}

//----- (00C3E970) --------------------------------------------------------
char __cdecl PE_CheckExeFile(LPCWSTR lpFileName, DWORD *pTimeDateStamp, BOOL *pbRet, LPCVOID lpBaseAddress)
{
  _WORD *pDllCharacteristics; // ebx
  BOOL *pnRet; // edi
  HANDLE hFile; // eax
  void *FileHandle; // esi
  BOOL *hMapping; // eax
  _IMAGE_DOS_HEADER *pImageBase; // eax
  _IMAGE_NT_HEADERS *pImageNtHeaders; // esi
  WORD Machine; // ax
  _IMAGE_NT_HEADERS *pImageNtHeaders2; // esi
  FAKE_IMAGE_SECTION_HEADER_ITEM *pItem; // eax
  signed int dwSectionIndex; // edx
  signed int NumberOfSections; // esi
  int Characteristics_1; // ecx
  _IMAGE_SECTION_HEADER *pSectionHeader; // ecx
  signed int dwNumberOfSections; // esi
  signed int dwSectionIndex_1; // edi
  DWORD Characteristics; // edx
  DWORD PhysicalAddress; // eax
  DWORD PhysicalAddress_1; // eax
  HANDLE hFileHandle; // [esp+Ch] [ebp-8h]
  char bRet; // [esp+13h] [ebp-1h]
  BOOL *hObjecta; // [esp+24h] [ebp+10h]
  _IMAGE_DOS_HEADER *lpBaseAddressa; // [esp+28h] [ebp+14h]

  pDllCharacteristics = lpBaseAddress;
  pnRet = pbRet;
  *(_WORD *)lpBaseAddress = 0;
  *pTimeDateStamp = 0;
  bRet = 0;
  *(_BYTE *)pbRet = 0;
  hFile = CreateFileW(lpFileName, GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, 0x80u, 0);
  FileHandle = hFile;
  hFileHandle = hFile;
  if ( hFile == (HANDLE)-1 )
    return 0;
  hMapping = (BOOL *)CreateFileMappingW(hFile, 0, PAGE_READONLY, 0, 0, 0);
  hObjecta = hMapping;
  if ( !hMapping )
  {
    CloseHandle(FileHandle);
    return 0;
  }
  pImageBase = (_IMAGE_DOS_HEADER *)MapViewOfFile(hMapping, FILE_MAP_READ, 0, 0, 0);
  lpBaseAddressa = pImageBase;
  if ( !pImageBase )
  {
    CloseHandle(hObjecta);
    CloseHandle(hFileHandle);
    return 0;
  }
  if ( pImageBase->e_magic == 0x5A4D )
  {
    pImageNtHeaders = (_IMAGE_NT_HEADERS *)((char *)pImageBase + pImageBase->e_lfanew);
    if ( pImageNtHeaders->FileHeader.Characteristics & IMAGE_FILE_32BIT_MACHINE
      && (Machine = pImageNtHeaders->FileHeader.Machine, Machine != IMAGE_FILE_MACHINE_AMD64)
      && Machine != IMAGE_FILE_MACHINE_IA64 )
    {
      *(_BYTE *)pnRet = 1;
    }
    else
    {
      *(_BYTE *)pnRet = 2;
    }
    *pTimeDateStamp = pImageNtHeaders->FileHeader.TimeDateStamp;
    *pDllCharacteristics = pImageNtHeaders->OptionalHeader.DllCharacteristics | IMAGE_FILE_RELOCS_STRIPPED;
    if ( *(_BYTE *)pnRet == 2 )
    {
      pImageNtHeaders2 = (_IMAGE_NT_HEADERS *)((char *)lpBaseAddressa + lpBaseAddressa->e_lfanew);
      if ( IsBadReadPtr((char *)lpBaseAddressa + lpBaseAddressa->e_lfanew, 0x108u) )
        goto __quit;
      if ( pImageNtHeaders2->Signature != 0x4550 )
        goto __quit;
      // &(pImageSectionHeaders)->SizeOfRawData
      pItem = (FAKE_IMAGE_SECTION_HEADER_ITEM *)&pImageNtHeaders2[1].FileHeader.NumberOfSymbols;
      dwSectionIndex = 1;
      NumberOfSections = pImageNtHeaders2->FileHeader.NumberOfSections;
      if ( NumberOfSections < 1 )
        goto __quit;
      while ( 1 )
      {
        if ( !*(_DWORD *)&pItem->NumberOfRelocations
          && (pItem->SizeOfRawData != 'xet.' || pItem->PointerToRawData != 'ssbt')
          && (pItem->SizeOfRawData != 'slt.' || pItem->PointerToRawData)
          && (pItem->SizeOfRawData != 'ssb.'
           || pItem->PointerToRawData && (pItem->SizeOfRawData != 'ssb.' || pItem->PointerToRawData))
          && (pItem->SizeOfRawData != 'b_tr' || pItem->PointerToRawData != 'ss') )
        {
          Characteristics_1 = pItem[1].SizeOfRawData;
          if ( Characteristics_1 & IMAGE_SCN_MEM_EXECUTE )
          {
            if ( Characteristics_1 & 0xC0 )
              break;
          }
        }
        ++dwSectionIndex;
        pItem = (FAKE_IMAGE_SECTION_HEADER_ITEM *)((char *)pItem + sizeof(_IMAGE_SECTION_HEADER));
        if ( dwSectionIndex > NumberOfSections )
          goto __quit;
      }
    }
    else
    {
      if ( IsBadReadPtr(pImageNtHeaders, sizeof(_IMAGE_NT_HEADERS)) )
        goto __quit;
      if ( pImageNtHeaders->Signature != 0x4550 )
        goto __quit;
      pSectionHeader = (_IMAGE_SECTION_HEADER *)&pImageNtHeaders[1];
      dwNumberOfSections = pImageNtHeaders->FileHeader.NumberOfSections;
      dwSectionIndex_1 = 1;
      if ( dwNumberOfSections < 1 )
        goto __quit;
      while ( 1 )
      {
        Characteristics = pSectionHeader->Characteristics;
        if ( Characteristics & IMAGE_SCN_CNT_CODE )
        {
          PhysicalAddress = pSectionHeader->Misc.PhysicalAddress;
          if ( PhysicalAddress > 4096 && pSectionHeader->SizeOfRawData < PhysicalAddress - 4096 )
            break;
        }
        if ( *(_DWORD *)pSectionHeader->Name == 'xet.' && *(_DWORD *)&pSectionHeader->Name[4] == 't' )
        {
          PhysicalAddress_1 = pSectionHeader->Misc.PhysicalAddress;
          if ( PhysicalAddress_1 > 4096 && pSectionHeader->SizeOfRawData < PhysicalAddress_1 - 4096 )
            break;
        }
        if ( !pSectionHeader->Name[0] && pSectionHeader->SizeOfRawData < pSectionHeader->Misc.PhysicalAddress
          || !pSectionHeader->SizeOfRawData
          && pSectionHeader->Misc.PhysicalAddress >= 4096
          && (*(_DWORD *)pSectionHeader->Name != 0x7865742E || *(_DWORD *)&pSectionHeader->Name[4] != 0x73736274)
          && (*(_DWORD *)pSectionHeader->Name != 0x736C742E || *(_DWORD *)&pSectionHeader->Name[4])
          && (*(_DWORD *)pSectionHeader->Name != 0x7373622E || *(_DWORD *)&pSectionHeader->Name[4])
          && (*(_DWORD *)pSectionHeader->Name != 0x7461642E || *(_DWORD *)&pSectionHeader->Name[4] != 0x61)
          && Characteristics & IMAGE_SCN_MEM_EXECUTE
          && Characteristics & 0xC0 )
        {
          break;
        }
        ++dwSectionIndex_1;
        ++pSectionHeader;
        if ( dwSectionIndex_1 > dwNumberOfSections )
          goto __quit;
      }
    }
    bRet = 1;
  }
__quit:
  UnmapViewOfFile(lpBaseAddressa);
  CloseHandle(hObjecta);
  CloseHandle(hFileHandle);
  return bRet;
}
// C3EB17: CONTAINING_RECORD: no field 'FAKE_IMAGE_SECTION_HEADER_ITEM *' in struct '_IMAGE_SECTION_HEADER' at 40

//----- (00C3EC40) --------------------------------------------------------
wchar_t **__thiscall sub_C3EC40(wchar_t **this, wchar_t *a2, int a3, void *a4, unsigned int a5)
{
  wchar_t **v5; // esi
  wchar_t *v6; // eax
  size_t v7; // ST08_4

  v5 = this;
  *this = _wcsdup(a2);
  v5[1] = (wchar_t *)a3;
  v5[3] = (wchar_t *)a5;
  v6 = (wchar_t *)operator new[](a5);
  v7 = (size_t)v5[3];
  v5[2] = v6;
  memmove_0(v6, a4, v7);
  return v5;
}

//----- (00C3EC80) --------------------------------------------------------
void __thiscall sub_C3EC80(void **this)
{
  void **v1; // esi

  v1 = this;
  free(*this);
  operator delete[](v1[2]);
}

//----- (00C3ECA0) --------------------------------------------------------
signed int __thiscall sub_C3ECA0(int this, _DWORD *a2, int a3)
{
  __int64 v3; // rax
  signed int result; // eax
  __int64 v5; // rax
  _DWORD *v6; // edx

  switch ( *(_DWORD *)(this + 12) )
  {
    case 1:
      v3 = **(unsigned __int8 **)(this + 8);
      *a2 = v3;
      result = 1;
      a2[1] = HIDWORD(v3);
      break;
    case 2:
      v5 = **(unsigned __int16 **)(this + 8);
      *a2 = v5;
      result = 1;
      a2[1] = HIDWORD(v5);
      break;
    case 4:
      *a2 = **(_DWORD **)(this + 8);
      result = 1;
      a2[1] = 0;
      break;
    case 8:
      v6 = *(_DWORD **)(this + 8);
      *a2 = *v6;
      a2[1] = v6[1];
      result = 1;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//----- (00C3ED40) --------------------------------------------------------
PE_PerfInfo_Item *__thiscall sub_C3ED40(PE_PerfInfo_Item *this, int a2, PerformanceInfo *a3)
{
  this->m_Text = a2;
  this->m_PerfInfo = (int)a3;
  return this;
}

//----- (00C3ED60) --------------------------------------------------------
_DWORD *__thiscall sub_C3ED60(_DWORD *this)
{
  _DWORD *v1; // esi
  int v2; // ecx
  _DWORD *v3; // edi
  _DWORD *result; // eax

  v1 = this;
  v2 = *this;
  v1[1] = 0;
  if ( *(_DWORD *)(v2 + 40) && (v1[2] = v2 + *(_DWORD *)(v2 + 4), (v3 = operator new(0x1Cu)) != 0) )
    result = sub_C3E670(
               v3,
               v1[2],
               *v1 + *(_DWORD *)(*v1 + 8),
               *(_DWORD *)(*v1 + 32),
               v1[3],
               *(_DWORD *)(*v1 + 40) == -1);
  else
    result = 0;
  return result;
}

//----- (00C3EE00) --------------------------------------------------------
_DWORD *__thiscall sub_C3EE00(_DWORD *this)
{
  _DWORD *v1; // esi
  int v2; // ecx
  _DWORD *v3; // ecx
  _DWORD *v4; // edx
  _DWORD *result; // eax

  v1 = this;
  v2 = *this;
  if ( *(_DWORD *)(v2 + 40) != -1
    && (++v1[1], v1[1] < *(_DWORD *)(v2 + 40))
    && (v3 = (_DWORD *)(*(_DWORD *)v1[2] + v1[2]), v1[2] = (char *)v3 + *v3, (v4 = operator new(0x1Cu)) != 0) )
  {
    result = sub_C3E670(v4, v1[2], *v1 + *(_DWORD *)(*v1 + 8), *(_DWORD *)(*v1 + 32), v1[3], 0);
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00C3EEA0) --------------------------------------------------------
PerformanceInfoInMemory *__thiscall PE_PerfInfo::PE_PerfInfo(PerformanceInfoInMemory *this, PerformanceInfo *a2)
{
  PerformanceInfoInMemory *result; // eax

  this->m_PerfInfo = (int)a2;
  result = this;
  this->m_pBuffer = 0;
  return result;
}

//----- (00C3EEC0) --------------------------------------------------------
int __thiscall PerformanceInfoInMemory::FindPerf(PerformanceInfoInMemory *this, LPCWSTR lpszName, wchar_t *pszBuffer, int nLength)
{
  wchar_t *pszBuf; // esi
  wchar_t *pszName; // edi
  int nPerfIndex; // eax
  int nLen; // eax
  wchar_t *lpszName_1; // [esp+4h] [ebp-Ch]
  PerformanceInfoInMemory *v10; // [esp+8h] [ebp-8h]
  wchar_t *Context; // [esp+Ch] [ebp-4h]
  LPCWSTR lpsza; // [esp+18h] [ebp+8h]

  v10 = this;
  if ( IsBadStringPtrW(lpszName, 0xFFFFFFFF) )
    return 0;
  lpszName_1 = _wcsdup(lpszName);
  pszBuf = pszBuffer;
  Context = 0;
  pszName = wcstok_s(lpszName_1, ",", &Context);
  if ( pszName )
  {
    lpsza = (LPCWSTR)(2 * nLength);
    do
    {
      nPerfIndex = PerformanceInfo::FindPerf((PerformanceInfo *)v10->m_PerfInfo, pszName);
      if ( nPerfIndex )
        nLen = swprintf_s(pszBuf, ((signed int)pszBuffer + (char *)lpsza - (char *)pszBuf) >> 1, L"%u ", nPerfIndex);
      else
        nLen = swprintf_s(pszBuf, ((signed int)pszBuffer + (char *)lpsza - (char *)pszBuf) >> 1, L"%s ", pszName);
      pszBuf += nLen;
      pszName = wcstok_s(0, ",", &Context);
    }
    while ( pszName );
  }
  free(lpszName_1);
  return 1;
}
// CB0800: using guessed type wchar_t aU_0[4];

//----- (00C3EF90) --------------------------------------------------------
int __thiscall sub_C3EF90(PerformanceInfoInMemory *this)
{
  int result; // eax

  if ( this->m_pBuffer )
    result = *((_DWORD *)this->m_pBuffer + 7);
  else
    result = 0;
  return result;
}

//----- (00C3EFA0) --------------------------------------------------------
WCHAR *__thiscall sub_C3EFA0(PerformanceInfoInMemory *this)
{
  WCHAR *v1; // ecx
  WCHAR *result; // eax

  v1 = this->m_pBuffer;
  if ( v1 )
    result = (WCHAR *)((char *)v1 + *((_DWORD *)v1 + 6));
  else
    result = 0;
  return result;
}

//----- (00C3EFB0) --------------------------------------------------------
int __thiscall PerformanceInfoInMemory::Load(PerformanceInfoInMemory *pThis, LPCWSTR lpszRootName, LPCWSTR lpszName)
{
  PerformanceInfoInMemory *this; // edi
  unsigned int dwLength; // esi
  LSTATUS lRet; // eax
  WCHAR *v6; // eax
  HKEY hSubKey; // [esp+Ch] [ebp-20Ch]
  DWORD cbData; // [esp+10h] [ebp-208h]
  WCHAR szValueName[256]; // [esp+14h] [ebp-204h]

  this = pThis;
  operator delete(pThis->m_pBuffer);
  this->m_pBuffer = 0;
  if ( lpszRootName )
  {
    if ( RegConnectRegistryW(lpszRootName, HKEY_PERFORMANCE_DATA, &hSubKey) )
      return 0;
  }
  else
  {
    hSubKey = HKEY_PERFORMANCE_DATA;
  }
  if ( PerformanceInfoInMemory::FindPerf(this, lpszName, szValueName, 256) )
  {
    dwLength = 0;
    cbData = 0;
    this->m_pBuffer = 0;
    lRet = RegQueryValueExW(hSubKey, szValueName, 0, 0, 0, &cbData);
    if ( lRet )
    {
      while ( lRet == ERROR_MORE_DATA )
      {
        operator delete[](this->m_pBuffer);
        if ( cbData <= dwLength )
          dwLength += 4096;
        else
          dwLength = cbData + 4096;
        v6 = (WCHAR *)operator new[](dwLength);
        this->m_pBuffer = v6;
        if ( !v6 )
          break;
        cbData = dwLength;
        lRet = RegQueryValueExW(hSubKey, szValueName, 0, 0, (LPBYTE)v6, &cbData);
        if ( !lRet )
          goto LABEL_13;
      }
    }
    else
    {
LABEL_13:
      if ( *(_DWORD *)this->m_pBuffer == 0x450050 && *((_DWORD *)this->m_pBuffer + 1) == 0x460052 )
        return 1;
    }
    operator delete[](this->m_pBuffer);
    this->m_pBuffer = 0;
  }
  return 0;
}

//----- (00C3F110) --------------------------------------------------------
int __cdecl CMainWnd::HandleMsg7FD(int _8, int a2, int a3, void *a1)
{
  TreeViewListItemParam_Release((tagTREEVIEWLISTITEMPARAM *)a1);
  return 0;
}

//----- (00C3F130) --------------------------------------------------------
int __cdecl CMainWnd::HandleDeviceChange(HWND a1, unsigned int a2, unsigned int wParam, _DEV_BROADCAST_HDR *lParam)
{
  if ( wParam == DBT_DEVICEARRIVAL && lParam->dbch_devicetype == DBT_DEVTYP_VOLUME )
    GetDriverNameAndLinkInfo();
  return 0;
}

//----- (00C3F150) --------------------------------------------------------
int __cdecl CMainWnd::HandleMsg7F9(int a1, int a2, int a3, int a4)
{
  tagTREEVIEWLISTITEMPARAM *v4; // esi
  tagTREEVIEWLISTITEMPARAM *v5; // ebx
  ListItemData1 *v6; // edi
  char v7; // dl
  WCHAR *v8; // ecx
  const wchar_t **v9; // eax
  const wchar_t *v10; // eax
  tagDLLLISTITEMPARAM *v11; // esi
  char v12; // bl
  const wchar_t *v13; // eax
  const wchar_t **v14; // ecx
  const wchar_t *v15; // ecx
  char v17; // [esp+23h] [ebp+17h]

  v4 = gpTreeViewListItemParam;
  v5 = 0;
  v6 = (ListItemData1 *)a4;
  if ( a4 )
  {
    v7 = 0;
    v17 = 0;
    if ( gpTreeViewListItemParam )
    {
      do
      {
        v8 = v4->szProcessName;
        if ( v4->dwProcessId == gdwProcessIdSelected )
          v5 = v4;
        if ( v8 )
        {
          v9 = (const wchar_t **)v6[2].field_4;
          if ( v9 )
            v10 = *v9;
          else
            v10 = 0;
          if ( _wcsicmp(v8, v10) )
          {
            v7 = v17;
          }
          else
          {
            v7 = 1;
            v4->m_ItemDataForVirusTotal = v6;
            v17 = 1;
          }
        }
        v4 = v4->m_Prev;
      }
      while ( v4 );
      if ( v7 )
      {
        if ( RedrawColumn(1, ghWndTreeListView, 1670, 0) )
        {
          InvalidateRect(ghWndTreeListView, 0, 0);
          PE_ResortList(0x65u);
        }
        else if ( IsColumnIDValid(ghWndTreeListView, 0x686u) )
        {
          InvalidateRect(ghWndTreeListView, 0, 0);
        }
      }
      if ( v5 )
      {
        if ( IsWindowVisible(ghWndDllsListCtrl) )
        {
          v11 = gpDllListItemParamHeader;
          v12 = 0;
          if ( gpDllListItemParamHeader )
          {
            do
            {
              v13 = (const wchar_t *)v11->m_strPath.pszData;
              if ( v13 )
              {
                v14 = (const wchar_t **)v6[2].field_4;
                if ( v14 )
                  v15 = *v14;
                else
                  v15 = 0;
                if ( !_wcsicmp(v13, v15) )
                {
                  v11->m_HashData = (int)v6;
                  v12 = 1;
                }
              }
              v11 = v11->m_Prev;
            }
            while ( v11 );
            if ( v12 )
            {
              InvalidateRect(ghWndDllsListCtrl, 0, 0);
              PE_ResortList(0x68u);
              return 0;
            }
          }
        }
      }
    }
  }
  else
  {
    if ( RedrawColumn(1, ghWndTreeListView, 1670, 0) )
    {
      InvalidateRect(ghWndTreeListView, 0, 0);
      PE_ResortList(0x65u);
    }
    else if ( IsColumnIDValid(ghWndTreeListView, 0x686u) )
    {
      InvalidateRect(ghWndTreeListView, 0, 0);
    }
    if ( IsWindowVisible(ghWndDllsListCtrl) )
    {
      InvalidateRect(ghWndDllsListCtrl, 0, 0);
      PE_ResortList(0x68u);
    }
  }
  return 0;
}

//----- (00C3F350) --------------------------------------------------------
int __cdecl Command_CreateDump(HWND a1, __int16 a2)
{
  HWND v2; // esi
  LRESULT v3; // eax
  int v4; // esi
  HANDLE v5; // ebx
  int result; // eax
  HANDLE v7; // edi
  HCURSOR v8; // eax
  LPARAM lParam; // [esp+Ch] [ebp-4A4h]
  LRESULT v10; // [esp+10h] [ebp-4A0h]
  int v11; // [esp+14h] [ebp-49Ch]
  int v12; // [esp+2Ch] [ebp-484h]
  struct tagOFNW v13; // [esp+40h] [ebp-470h]
  HCURSOR hCursor; // [esp+98h] [ebp-418h]
  wchar_t pszBuffer; // [esp+9Ch] [ebp-414h]
  wchar_t Dst; // [esp+2A4h] [ebp-20Ch]
  char v17; // [esp+2A6h] [ebp-20Ah]

  lParam = 0;
  memset(&v10, 0, 0x30u);
  Dst = 0;
  memset(&v17, 0, 0x206u);
  v2 = ghWndTreeListView;
  v3 = SendMessageW(ghWndTreeListView, 0x100Cu, 0xFFFFFFFF, 2);
  if ( v3 == -1
    || (v10 = v3, v11 = 0, lParam = 4, !SendMessageW(v2, 0x104Bu, 0, (LPARAM)&lParam))
    || (v4 = v12, SetFocus(ghWndTreeListView), !v4) )
  {
    MessageBoxW(ghWndTreeListView, L"No process is selected", L"Process Explorer Error", 0x10u);
    return 0;
  }
  v5 = OpenProcess(0x10000000u, 0, *(_DWORD *)(v4 + 68));
  if ( !v5 )
  {
    ReportMsg(L"Error opening process", ghMainWnd);
    return 0;
  }
  wcscpy_s(&Dst, 0x104u, *(const wchar_t **)(v4 + 60));
  if ( wcschr(&Dst, 0x2Eu) )
    *wcschr(&Dst, 0x2Eu) = 0;
  swprintf(&pszBuffer, L"Create dump of %s", *(_DWORD *)(v4 + 60));
  wcscat_s(&Dst, 0x104u, L".dmp");
  v13.hwndOwner = ghMainWnd;
  v13.hInstance = ghInstance;
  v13.lpstrFile = &Dst;
  *(_DWORD *)&v13.nFileOffset = 0;
  v13.lpfnHook = 0;
  v13.lpstrTitle = &pszBuffer;
  v13.lStructSize = 76;
  v13.lpstrCustomFilter = 0;
  v13.nMaxCustFilter = 0;
  v13.nFilterIndex = 1;
  v13.nMaxFile = 256;
  v13.lpstrFileTitle = 0;
  v13.nMaxFileTitle = 0;
  v13.lpstrInitialDir = 0;
  v13.Flags = 2097156;
  v13.lpstrDefExt = L"*.dmp";
  v13.lpstrFilter = L"Dump File (*.DMP)";
  if ( !GetSaveFileNameW(&v13) )
    return 0;
  v7 = CreateFileW(&Dst, 0x40000000u, 7u, 0, 2u, 0x80u, 0);
  if ( v7 == (HANDLE)-1 )
  {
    ReportMsg(L"Error creating dump file", ghMainWnd);
    result = 0;
  }
  else
  {
    v8 = LoadCursorW(0, (LPCWSTR)0x7F02);
    hCursor = SetCursor(v8);
    if ( !(unsigned __int8)DumpFileProcess((int)v7, v5, a2 == -24806) )
    {
      ReportMsg(L"Error writing dump file", ghMainWnd);
      DeleteFileW(&Dst);
    }
    SetCursor(hCursor);
    CloseHandle(v5);
    CloseHandle(v7);
    result = 0;
  }
  return result;
}
// CB20E4: using guessed type wchar_t aDmp_0[6];
// CB20F0: using guessed type wchar_t aDumpFileDmp[18];

//----- (00C3F670) --------------------------------------------------------
int Command_RestartProcess()
{
  HWND v0; // esi
  LRESULT v1; // eax
  int v2; // esi
  const unsigned __int16 *v3; // eax
  int v4; // eax
  struct _STARTUPINFOW StartupInfo; // [esp+4h] [ebp-88h]
  LPARAM lParam; // [esp+48h] [ebp-44h]
  LRESULT v8; // [esp+4Ch] [ebp-40h]
  int v9; // [esp+50h] [ebp-3Ch]
  int v10; // [esp+68h] [ebp-24h]
  struct _PROCESS_INFORMATION ProcessInformation; // [esp+7Ch] [ebp-10h]

  lParam = 0;
  memset(&v8, 0, 0x30u);
  v0 = ghWndTreeListView;
  v1 = SendMessageW(ghWndTreeListView, 0x100Cu, 0xFFFFFFFF, 2);
  if ( v1 == -1
    || (v8 = v1, v9 = 0, lParam = 4, !SendMessageW(v0, 0x104Bu, 0, (LPARAM)&lParam))
    || (v2 = v10, SetFocus(ghWndTreeListView), !v2) )
  {
    MessageBoxW(ghWndTreeListView, L"No process is selected", L"Process Explorer Error", 0x10u);
    return 0;
  }
  v3 = *(const unsigned __int16 **)(v2 + 88);
  if ( !v3 )
    goto LABEL_18;
  v4 = wcscmp(gszMainTitle, v3);
  if ( v4 )
    v4 = -(v4 < 0) | 1;
  if ( v4 )
  {
LABEL_18:
    if ( MessageBoxW(
           ghWndTreeListView,
           L"The selected process is running in a different account than Process Explorer and so may fail to run, behave d"
            "ifferently, and run with different security rights when restarted under Process Explorer's credentials.\n"
            "\n"
            "Continue with process restart?",
           L"Process Explorer Warning",
           0x34u) == 7 )
      return 0;
  }
  if ( !PE_ConfirmToKillProcess(*(LPCWSTR *)(v2 + 60), *(_DWORD *)(v2 + 68)) )
    return 0;
  memset(&StartupInfo, 0, 0x44u);
  StartupInfo.cb = 68;
  StartupInfo.dwFlags = 1;
  StartupInfo.wShowWindow = 5;
  if ( CreateProcessW(
         *(LPCWSTR *)(v2 + 792),
         *(LPWSTR *)(v2 + 800),
         0,
         0,
         0,
         0x400u,
         *(LPVOID *)(v2 + 808),
         *(LPCWSTR *)(v2 + 804),
         &StartupInfo,
         &ProcessInformation) )
  {
    CloseHandle(ProcessInformation.hThread);
    CloseHandle(ProcessInformation.hProcess);
  }
  else
  {
    ReportMsg(L"Error restarting process", ghMainWnd);
  }
  return 0;
}

//----- (00C3F820) --------------------------------------------------------
int Command_KillProcessTree()
{
  int nItem; // eax
  LVITEMW v2; // [esp+4h] [ebp-68h]
  LVITEMW Item; // [esp+38h] [ebp-34h]

  Item.mask = 0;
  memset(&Item.iItem, 0, 0x30u);
  nItem = SendMessageW(ghWndTreeListView, LVM_GETNEXTITEM, 0xFFFFFFFF, 2);
  if ( nItem == -1 )
  {
    MessageBoxW(ghWndTreeListView, L"No process selected", L"Process Explorer Error", MB_ICONERROR);
  }
  else
  {
    Item.iItem = nItem;
    Item.iSubItem = 0;
    Item.mask = 4;
    if ( SendMessageW(ghWndTreeListView, LVM_GETITEMW, 0, (LPARAM)&Item) )
    {
      PE_ConfirmToKillProcessTree(Item.lParam->szProcessName2, Item.lParam->dwProcessId);
      SetEvent(ghRefreshEventHandle);
      v2.stateMask = LVIS_SELECTED;
      v2.state = LVIS_SELECTED;
      SendMessageW(ghWndTreeListView, LVM_SETITEMSTATE, 0, (LPARAM)&v2);
      return 0;
    }
  }
  return 0;
}

//----- (00C3F8F0) --------------------------------------------------------
int __cdecl Command_Exit(HWND hWnd)
{
  DestroyWindow(hWnd);
  return 0;
}

//----- (00C3F900) --------------------------------------------------------
int Command_OpenProcExp()
{
  int result; // eax
  WINDOWPLACEMENT wp; // [esp+0h] [ebp-30h]

  wp.length = 44;
  GetWindowPlacement(ghMainWnd, &wp);
  ShowWindow(ghMainWnd, 4 * (wp.showCmd == SW_SHOWMINIMIZED) + 5);
  SetForegroundWindow(ghMainWnd);
  SetFocus(ghMainWnd);
  result = 0;
  gbMainWndMinimized1 = 1;
  gbMainWndMinimized = 0;
  return result;
}
// CDA389: using guessed type char gbMainWndMinimized;
// CDA393: using guessed type char gbMainWndMinimized1;

//----- (00C3F980) --------------------------------------------------------
int Command_CopyAllThreadStack()
{
  HWND v0; // eax
  HWND v1; // esi
  HGLOBAL v2; // ebx
  wchar_t *v3; // edi
  LONG v4; // eax
  HWND v5; // edx
  int v6; // ecx
  tagLVITEMW lvitem; // [esp+4h] [ebp-1074h]
  tagLVITEMW lvitem_1; // [esp+38h] [ebp-1040h]
  int v10; // [esp+6Ch] [ebp-100Ch]
  int v11; // [esp+70h] [ebp-1008h]
  wchar_t Dst; // [esp+74h] [ebp-1004h]

  lvitem_1.mask = 0;
  memset(&lvitem_1.iItem, 0, 0x30u);
  v0 = GetFocus();
  v1 = v0;
  if ( v0 == ghWndTreeListView || v0 == ghWndDllsListCtrl || v0 == ghWndHandlesListCtrl )
  {
    lvitem_1.iItem = SendMessageW(v0, LVM_GETNEXTITEM, 0xFFFFFFFF, 2);
    if ( lvitem_1.iItem != -1 )
    {
      v2 = 0;
      v3 = 0;
      v10 = 0;
      lvitem_1.iSubItem = 0;
      v4 = GetWindowLongW(v1, GWLP_USERDATA);
      v5 = ghWndTreeListView;
      v11 = v4;
      if ( v1 == ghWndTreeListView )
        v11 = ++v4;
      v6 = 0;
      lvitem_1.iSubItem = 0;
      if ( v4 > 0 )
      {
        while ( 1 )
        {
          if ( v1 != v5 || v3 )
          {
            lvitem.iSubItem = v6;
            lvitem.pszText = &Dst;
            lvitem.cchTextMax = 2048;
            SendMessageW(v1, LVM_GETITEMTEXTW, lvitem_1.iItem, (LPARAM)&lvitem);
          }
          else
          {
            lvitem_1.mask = 4;
            if ( SendMessageW(v1, LVM_GETITEMW, 0, (LPARAM)&lvitem_1) )
            {
              wcscpy_s(&Dst, 0x800u, lvitem_1.lParam->szProcessName2);
              --lvitem_1.iSubItem;
              --v11;
            }
          }
          v10 += 2 * wcslen(&Dst) + 1;
          if ( v3 )
          {
            v2 = GlobalReAlloc(v2, 2 * v10 + 2, 0);
            v3 = (wchar_t *)GlobalLock(v2);
            wcscat_s(v3, v10 + 1, L"\t");
          }
          else
          {
            v2 = GlobalAlloc(0x2002u, 2 * v10 + 2);
            v3 = (wchar_t *)GlobalLock(v2);
            *v3 = 0;
          }
          wcscat_s(v3, v10 + 1, &Dst);
          GlobalUnlock(v2);
          v6 = lvitem_1.iSubItem + 1;
          lvitem_1.iSubItem = v6;
          if ( v6 >= v11 )
            break;
          v5 = ghWndTreeListView;
        }
        if ( v2 && OpenClipboard(ghMainWnd) )
        {
          EmptyClipboard();
          SetClipboardData(0xDu, v2);
          CloseClipboard();
        }
      }
    }
  }
  return 0;
}

//----- (00C3FBD0) --------------------------------------------------------
int Command_RefreshNow()
{
  SetEvent(ghTimerRefreshEvent);
  return 0;
}

//----- (00C3FBE0) --------------------------------------------------------
int __cdecl Command_SelectColumn(HWND hWnd, signed __int16 uID)
{
  signed __int16 nID; // di
  HWND hWndFocus; // eax
  UINT nStartPage; // eax
  signed int nPageIndex_1; // esi
  char bAdministrative; // al
  HINSTANCE ghInstance; // ecx
  signed int nPageIndex_2; // eax
  int nPageIndex_3; // esi
  bool fNoAdapterRuntime; // zf
  int nPageIndex_4; // eax
  int nPageIndex_5; // eax
  UINT nPageIndex_6; // edx
  int nPageIndex_7; // esi
  int nPageIndex_8; // eax
  int nPageIndex; // esi
  int nPageIndex_9; // eax
  int nPageIndex_10; // eax
  PROPSHEETHEADERW PropSheet; // [esp+Ch] [ebp-4E8h]
  char ZeroParam; // [esp+43h] [ebp-4B1h]
  PE_PROPSHEETPAGEW Pages[13]; // [esp+44h] [ebp-4B0h]
  WCHAR Dst[260]; // [esp+2E8h] [ebp-20Ch]

  ZeroParam = 0;
  nID = uID;
  PropSheet.dwSize = 0;
  if ( uID == 40041 )
  {
    hWndFocus = GetFocus();
    if ( hWndFocus == ghWndTreeListView )
    {
      nID = 40105;
    }
    else if ( hWndFocus == ghWndDllsListCtrl )
    {
      nID = 40104;
    }
    else if ( hWndFocus == ghWndHandlesListCtrl )
    {
      nID = 40106;
    }
  }
  Pages[0].dwSize = (DWORD)&ZeroParam;
  nStartPage = PropSheet.nStartPage;
  Pages[0].dwSize = sizeof(PE_PROPSHEETPAGEW);
  Pages[0].dwFlags = PSP_USETITLE;
  if ( nID == 40105 )
    nStartPage = 0;
  Pages[0].hInstance = ::ghInstance;
  PropSheet.nStartPage = nStartPage;
  nPageIndex_1 = 3;
  Pages[0].u.pszTemplate = L"PROCCOLUMNS";
  Pages[0].u2.hIcon = 0;
  Pages[0].pfnDlgProc = PropColumnSetsForProcess;
  Pages[0].pszTitle = L"Process Image";
  Pages[0].pfnCallback = 0;
  Pages[1].dwSize = sizeof(PE_PROPSHEETPAGEW);
  Pages[1].dwFlags = PSP_USETITLE;
  Pages[1].hInstance = ::ghInstance;
  Pages[1].u.pszTemplate = L"PROCPERFCOLUMNS";
  Pages[1].u2.hIcon = 0;
  Pages[1].pfnDlgProc = PropColumnSetsForProcess;
  Pages[1].pszTitle = L"Process Performance";
  Pages[1].lParam = (LPARAM)&ZeroParam;
  Pages[1].pfnCallback = 0;
  Pages[2].dwSize = sizeof(PE_PROPSHEETPAGEW);
  Pages[2].dwFlags = PSP_USETITLE;
  Pages[2].hInstance = ::ghInstance;
  Pages[2].u.pszTemplate = L"PROCIOCOLUMNS";
  Pages[2].u2.hIcon = 0;
  Pages[2].pfnDlgProc = PropColumnSetsForProcess;
  Pages[2].pszTitle = L"Process I/O";
  Pages[2].lParam = (LPARAM)&ZeroParam;
  Pages[2].pfnCallback = 0;
  bAdministrative = IsBuiltinAdministrative();
  ghInstance = ::ghInstance;
  if ( bAdministrative || gConfig.bETWStandardUserWarning == 1 )
  {
    Pages[3].dwSize = sizeof(PE_PROPSHEETPAGEW);
    Pages[3].dwFlags = PSP_USETITLE;
    nPageIndex_1 = 5;
    Pages[3].hInstance = ::ghInstance;
    Pages[3].u.pszTemplate = L"PROCNETWORKCOLUMNS";
    Pages[3].u2.hIcon = 0;
    Pages[3].pfnDlgProc = PropColumnSetsForProcess;
    Pages[3].pszTitle = L"Process Network";
    Pages[3].lParam = (LPARAM)&ZeroParam;
    Pages[3].pfnCallback = 0;
    Pages[4].dwSize = sizeof(PE_PROPSHEETPAGEW);
    Pages[4].dwFlags = PSP_USETITLE;
    Pages[4].hInstance = ::ghInstance;
    Pages[4].u.pszTemplate = L"PROCDISKCOLUMNS";
    Pages[4].u2.hIcon = 0;
    Pages[4].pfnDlgProc = PropColumnSetsForProcess;
    Pages[4].pszTitle = L"Process Disk";
    Pages[4].lParam = (LPARAM)&ZeroParam;
    Pages[4].pfnCallback = 0;
  }
  nPageIndex_2 = nPageIndex_1;
  nPageIndex_3 = nPageIndex_1 + 1;
  fNoAdapterRuntime = gdwAdapterRuntingTime == 0;
  Pages[nPageIndex_2].dwSize = sizeof(PE_PROPSHEETPAGEW);
  Pages[nPageIndex_2].dwFlags = PSP_USETITLE;
  Pages[nPageIndex_2].hInstance = ghInstance;
  Pages[nPageIndex_2].u.pszTemplate = L"PROCMEMCOLUMNS";
  Pages[nPageIndex_2].u2.hIcon = 0;
  Pages[nPageIndex_2].pfnDlgProc = PropColumnSetsForProcess;
  Pages[nPageIndex_2].pszTitle = L"Process Memory";
  Pages[nPageIndex_2].lParam = (LPARAM)&ZeroParam;
  Pages[nPageIndex_2].pfnCallback = 0;
  if ( !fNoAdapterRuntime )
  {
    nPageIndex_4 = nPageIndex_3++;
    Pages[nPageIndex_4].dwSize = sizeof(PE_PROPSHEETPAGEW);
    Pages[nPageIndex_4].dwFlags = PSP_USETITLE;
    Pages[nPageIndex_4].hInstance = ghInstance;
    Pages[nPageIndex_4].u.pszTemplate = L"PROCGPUCOLUMNS";
    Pages[nPageIndex_4].u2.hIcon = 0;
    Pages[nPageIndex_4].pfnDlgProc = PropColumnSetsForProcess;
    Pages[nPageIndex_4].pszTitle = L"Process GPU";
    Pages[nPageIndex_4].lParam = (LPARAM)&ZeroParam;
    Pages[nPageIndex_4].pfnCallback = 0;
  }
  nPageIndex_5 = nPageIndex_3;
  Pages[nPageIndex_5].lParam = (LPARAM)&ZeroParam;
  nPageIndex_6 = PropSheet.nStartPage;
  Pages[nPageIndex_5].dwSize = sizeof(PE_PROPSHEETPAGEW);
  if ( nID == 40106 )
    nPageIndex_6 = nPageIndex_3;
  Pages[nPageIndex_5].dwFlags = PSP_USETITLE;
  nPageIndex_7 = nPageIndex_3 + 1;
  Pages[nPageIndex_5].hInstance = ghInstance;
  Pages[nPageIndex_5].u.pszTemplate = L"HANDLECOLUMNS";
  Pages[nPageIndex_5].u2.hIcon = 0;
  Pages[nPageIndex_5].pfnDlgProc = PropColumnSetsForHandles;
  Pages[nPageIndex_5].pszTitle = L"Handle";
  Pages[nPageIndex_5].pfnCallback = 0;
  nPageIndex_8 = nPageIndex_7;
  Pages[nPageIndex_8].dwSize = sizeof(PE_PROPSHEETPAGEW);
  Pages[nPageIndex_8].dwFlags = PSP_USETITLE;
  Pages[nPageIndex_8].hInstance = ghInstance;
  Pages[nPageIndex_8].u.pszTemplate = L"DLLCOLUMNS";
  Pages[nPageIndex_8].u2.hIcon = 0;
  Pages[nPageIndex_8].pfnDlgProc = PropColumnSetsForDlls;
  Pages[nPageIndex_8].pszTitle = L"DLL";
  Pages[nPageIndex_8].lParam = (LPARAM)&ZeroParam;
  Pages[nPageIndex_8].pfnCallback = 0;
  if ( nID == 40104 )
    nPageIndex_6 = nPageIndex_7;
  nPageIndex = nPageIndex_7 + 1;
  if ( gNetClrMemoryPerfInfoLoaded )
  {
    nPageIndex_9 = nPageIndex++;
    Pages[nPageIndex_9].dwSize = sizeof(PE_PROPSHEETPAGEW);
    Pages[nPageIndex_9].dwFlags = PSP_USETITLE;
    Pages[nPageIndex_9].hInstance = ghInstance;
    Pages[nPageIndex_9].u.pszTemplate = L"NETCOLUMNS";
    Pages[nPageIndex_9].u2.hIcon = 0;
    Pages[nPageIndex_9].pfnDlgProc = PropColumnSetsForNet;
    Pages[nPageIndex_9].pszTitle = L".NET";
    Pages[nPageIndex_9].lParam = (LPARAM)&ZeroParam;
    Pages[nPageIndex_9].pfnCallback = 0;
  }
  nPageIndex_10 = nPageIndex;
  PropSheet.dwFlags = 0x88;                     // PSH_NOAPPLYNOW| PSH_PROPSHEETPAGE
  PropSheet.dwSize = sizeof(PROPSHEETHEADERW);
  PropSheet.hInstance = ghInstance;
  Pages[nPageIndex_10].dwSize = sizeof(PE_PROPSHEETPAGEW);
  Pages[nPageIndex_10].dwFlags = PSP_USETITLE;
  Pages[nPageIndex_10].hInstance = ghInstance;
  Pages[nPageIndex_10].u.pszTemplate = L"STATUSBARCOLUMNS";
  Pages[nPageIndex_10].u2.hIcon = 0;
  Pages[nPageIndex_10].pfnDlgProc = PropColumnSetsForStatusBar;
  Pages[nPageIndex_10].pszTitle = L"Status Bar";
  Pages[nPageIndex_10].lParam = 0;
  Pages[nPageIndex_10].pfnCallback = 0;
  PropSheet.nPages = nPageIndex + 1;
  PropSheet.ppsp = (LPCPROPSHEETPAGEW)Pages;
  if ( nID == 40107 )
    nPageIndex_6 = nPageIndex;
  PropSheet.hwndParent = ghMainWnd;
  PropSheet.nStartPage = nPageIndex_6;
  swprintf(Dst, L"Select Columns");
  PropSheet.pfnCallback = 0;
  PropSheet.pszCaption = Dst;
  PropertySheetW(&PropSheet);
  if ( ZeroParam )
    UpdateWindowPlacement(ghMainWnd, 1);
  return 0;
}
// CB1188: using guessed type wchar_t aProccolumns[12];
// CB11A0: using guessed type wchar_t aProcessImage[14];
// CB11BC: using guessed type wchar_t aProcperfcolumn[16];
// CB11DC: using guessed type wchar_t aProcessPerform[20];
// CB1204: using guessed type wchar_t aProciocolumns[14];
// CB1220: using guessed type wchar_t aProcessIO[12];
// CB1238: using guessed type wchar_t aProcnetworkcol[19];
// CB1260: using guessed type wchar_t aProcessNetwork[16];
// CB1280: using guessed type wchar_t aProcdiskcolumn[16];
// CB12A0: using guessed type wchar_t aProcessDisk[13];
// CB12BC: using guessed type wchar_t aProcmemcolumns[15];
// CB12DC: using guessed type wchar_t aProcessMemory[15];
// CB12FC: using guessed type wchar_t aProcgpucolumns[15];
// CB131C: using guessed type wchar_t aProcessGpu[12];
// CB1334: using guessed type wchar_t aHandlecolumns_0[14];
// CB1350: using guessed type wchar_t aHandle[7];
// CB1360: using guessed type wchar_t aDllcolumns_0[11];
// CB1380: using guessed type wchar_t aNetcolumns[11];
// CB1398: using guessed type wchar_t aNet[5];
// CB13A4: using guessed type wchar_t aStatusbarcolum_0[17];
// CB13C8: using guessed type wchar_t aStatusBar[11];
// CDA098: using guessed type char gNetClrMemoryPerfInfoLoaded;
// C40037: user specified stroff has not been processed: PROPSHEETHEADERW offset 52

//----- (00C40150) --------------------------------------------------------
int __cdecl Command_ShowDllsPane(HWND hWnd)
{
  HMENU v1; // eax
  signed int v2; // eax
  UINT v3; // ST10_4
  HMENU v4; // eax
  LPARAM v5; // eax
  int v6; // eax
  int v7; // eax
  HMENU v8; // eax
  UINT_PTR v9; // ST0C_4
  HMENU v10; // eax
  LRESULT v11; // eax

  gConfig.bShowDllView = 1;
  v1 = GetMenu(hWnd);
  CheckMenuItem(v1, IDM_VIEW_LOWERPANEVIEW_DLLS, 8u);
  v2 = 0;
  if ( !gConfig.bShowDllView )
    v2 = 8;
  v3 = v2;
  v4 = GetMenu(hWnd);
  CheckMenuItem(v4, IDM_VIEW_LOWERPANEVIEW_HANDLES, v3);
  v5 = 1;
  if ( gConfig.bShowDllView )
    v5 = 4;
  PostMessageW(ghWndToolbar, TB_CHANGEBITMAP, IDM_POPUP_DLL_PROPERTIES, v5);
  InvalidateRect(ghWndToolbar, 0, 1);
  if ( hWnd )
    SetEvent(ghRefreshEventHandle);
  v6 = 5;
  if ( gConfig.bShowDllView )
    v6 = 0;
  ShowWindow(ghWndHandlesListCtrl, v6);
  v7 = 0;
  if ( gConfig.bShowDllView )
    v7 = 5;
  ShowWindow(ghWndDllsListCtrl, v7);
  if ( gConfig.bShowLowerPane )
  {
    v8 = GetMenu(ghMainWnd);
    RemoveMenu(v8, 5u, 0x400u);
    v9 = ghDllMenuPopup;
    v10 = GetMenu(ghMainWnd);
    InsertMenuW(v10, 5u, 0x410u, v9, L"&DLL");
  }
  v11 = SendMessageW(ghWndDllsListCtrl, LVM_GETNEXTITEM, 0xFFFFFFFF, 2);
  UpdateMenuStatus(v11 != -1, 5);
  DrawMenuBar(ghMainWnd);
  if ( !gConfig.bShowLowerPane )
    Command_ShowLowerPane(ghMainWnd);
  return 0;
}

//----- (00C402B0) --------------------------------------------------------
int __cdecl Command_ShowHandlesPane(HWND hWnd)
{
  HMENU v1; // eax
  signed int v2; // eax
  UINT v3; // ST10_4
  HMENU v4; // eax
  LPARAM v5; // eax
  int v6; // eax
  int v7; // eax
  HMENU v8; // eax
  UINT_PTR v9; // ST0C_4
  HMENU v10; // eax
  LRESULT v11; // eax

  gConfig.bShowDllView = 0;
  v1 = GetMenu(hWnd);
  CheckMenuItem(v1, IDM_VIEW_LOWERPANEVIEW_DLLS, 0);
  v2 = 0;
  if ( !gConfig.bShowDllView )
    v2 = 8;
  v3 = v2;
  v4 = GetMenu(hWnd);
  CheckMenuItem(v4, IDM_VIEW_LOWERPANEVIEW_HANDLES, v3);
  v5 = 1;
  if ( gConfig.bShowDllView )
    v5 = BMP_VIEW_HANDLES;
  PostMessageW(ghWndToolbar, TB_CHANGEBITMAP, IDM_POPUP_DLL_PROPERTIES, v5);
  PostMessageW(ghWndToolbar, TB_ENABLEBUTTON, IDM_VIEW_SHOW_UNNAMED_HANDLES_AND_MAPPINGS, gConfig.bShowDllView == 0);
  InvalidateRect(ghWndToolbar, 0, 1);
  if ( hWnd )
    SetEvent(ghRefreshEventHandle);
  v6 = 5;
  if ( gConfig.bShowDllView )
    v6 = 0;
  ShowWindow(ghWndHandlesListCtrl, v6);
  v7 = 0;
  if ( gConfig.bShowDllView )
    v7 = 5;
  ShowWindow(ghWndDllsListCtrl, v7);
  if ( !gConfig.bShowLowerPane )
    goto LABEL_17;
  v8 = GetMenu(ghMainWnd);
  RemoveMenu(v8, 5u, 0x400u);
  v9 = ghHandlesMenuPopup;
  v10 = GetMenu(ghMainWnd);
  InsertMenuW(v10, 5u, 0x410u, v9, L"H&andle");
  v11 = SendMessageW(ghWndHandlesListCtrl, LVM_GETNEXTITEM, 0xFFFFFFFF, 2);
  UpdateMenuStatus(v11 != -1, 5);
  DrawMenuBar(ghMainWnd);
  if ( !gConfig.bShowLowerPane )
LABEL_17:
    Command_ShowLowerPane(ghMainWnd);
  return 0;
}

//----- (00C40430) --------------------------------------------------------
int __cdecl Command_ViewDllsProperties(HWND hWnd)
{
  if ( gConfig.bShowDllView )
    Command_ShowHandlesPane(hWnd);
  else
    Command_ShowDllsPane(hWnd);
  if ( ghFindDlg )
    SendMessageW(ghFindDlg, 0x18u, 0, 0);
  return 0;
}

//----- (00C40480) --------------------------------------------------------
int __cdecl Command_UnnamedHandlesAndMappings(HWND hWnd)
{
  signed int v1; // eax
  bool v2; // zf
  UINT v3; // ST0C_4
  HMENU v4; // eax

  v1 = 0;
  v2 = gConfig.bShowUnnamedHandles != 0;
  gConfig.bShowUnnamedHandles = gConfig.bShowUnnamedHandles == 0;
  if ( !v2 )
    v1 = 8;
  v3 = v1;
  v4 = GetMenu(hWnd);
  CheckMenuItem(v4, 0x9C47u, v3);
  if ( gConfig.bShowLowerPane && gdwProcessIdSelected != -1 )
    SetEvent(ghEvent2);
  SendMessageW(ghWndToolbar, 0x403u, 0x9C47u, gConfig.bShowUnnamedHandles);
  return 0;
}

//----- (00C40500) --------------------------------------------------------
int __cdecl Command_HighlightRelocatedDlls(HWND hWnd)
{
  signed int v1; // eax
  bool v2; // zf
  UINT v3; // ST08_4
  HMENU v4; // eax

  v1 = 0;
  v2 = gConfig.bHighlightRelocatedDlls != 0;
  gConfig.bHighlightRelocatedDlls = gConfig.bHighlightRelocatedDlls == 0;
  if ( !v2 )
    v1 = 8;
  v3 = v1;
  v4 = GetMenu(hWnd);
  CheckMenuItem(v4, 0x9C50u, v3);
  InvalidateRgn(ghWndDllsListCtrl, 0, 1);
  return 0;
}

//----- (00C40550) --------------------------------------------------------
int __cdecl Command_ScrollToNewProcess(HWND hWnd)
{
  signed int v1; // eax
  bool v2; // zf
  UINT v3; // ST08_4
  HMENU v4; // eax

  v1 = 0;
  v2 = gConfig.bShowNewProcesses != 0;
  gConfig.bShowNewProcesses = gConfig.bShowNewProcesses == 0;
  if ( !v2 )
    v1 = 8;
  v3 = v1;
  v4 = GetMenu(hWnd);
  CheckMenuItem(v4, 0x9F0Du, v3);
  UpdateWindowPlacement(ghMainWnd, 1);
  return 0;
}

//----- (00C405A0) --------------------------------------------------------
int __cdecl Command_Help(int a1)
{
  wchar_t *v1; // eax
  WCHAR FileName; // [esp+4h] [ebp-414h]
  WCHAR Filename; // [esp+20Ch] [ebp-20Ch]

  GetModuleFileNameW(0, &Filename, 0x104u);
  v1 = wcsrchr(&Filename, 0x5Cu);
  wcscpy_s(v1, 260 - (v1 - &Filename), L"\\procexp.chm");
  swprintf(&FileName, L"%s:Zone.Identifier", &Filename);
  DeleteFileW(&FileName);
  if ( !Fake_HtmlHelp(a1, (int)&Filename, 0, 0) )
  {
    SetLastError(0);
    ReportMsg(L"Unable to open help file", ghMainWnd);
  }
  return 0;
}

//----- (00C40660) --------------------------------------------------------
int __cdecl Command_SearchOnline(HWND hWnd, __int16 a2)
{
  HWND v2; // esi
  HWND v3; // eax
  LRESULT v4; // eax
  const WCHAR *v5; // eax
  int v6; // esi
  LPARAM lParam; // [esp+4h] [ebp-34h]
  LRESULT v9; // [esp+8h] [ebp-30h]
  int v10; // [esp+Ch] [ebp-2Ch]
  int v11; // [esp+24h] [ebp-14h]

  lParam = 0;
  memset(&v9, 0, 0x30u);
  if ( a2 == -25424 )
  {
    v2 = ghWndDllsListCtrl;
  }
  else
  {
    v3 = GetFocus();
    v2 = ghWndTreeListView;
    if ( v3 == ghWndDllsListCtrl )
      v2 = ghWndDllsListCtrl;
  }
  v4 = SendMessageW(v2, 0x100Cu, 0xFFFFFFFF, 2);
  if ( v4 != -1 )
  {
    v9 = v4;
    v10 = 0;
    lParam = 4;
    if ( SendMessageW(v2, 0x104Bu, 0, (LPARAM)&lParam) )
    {
      if ( v2 == ghWndTreeListView )
      {
        v5 = *(const WCHAR **)(v11 + 60);
      }
      else
      {
        v6 = v11;
        if ( *(_BYTE *)(v11 + 44) & 8 )
        {
          MessageBoxW(
            ghWndTreeListView,
            L"Search not supported on pagefile-backed sections",
            L"Process Explorer Error",
            0x10u);
          return 0;
        }
        if ( wcsrchr(*(const wchar_t **)(v11 + 344), 0x5Cu) )
          v5 = wcsrchr(*(const wchar_t **)(v6 + 344), 0x5Cu) + 1;
        else
          v5 = *(const WCHAR **)(v6 + 344);
      }
      LaunchWebBrowser(hWnd, 1, v5);
    }
  }
  return 0;
}

//----- (00C40770) --------------------------------------------------------
int __cdecl Command_FindInProcess(HWND a1, __int16 nID)
{
  byte_CCE104 = nID == 40062;
  if ( ghFindDlg )
  {
    ShowWindow(ghFindDlg, 5);
    SetFocus(ghFindDlg);
  }
  else
  {
    ghFindDlg = CreateDialogParamW(ghInstance, L"FINDDIALOG", ghMainWnd, DlgFind, (LPARAM)ghFindDlg);
  }
  return 0;
}
// CCE104: using guessed type char byte_CCE104;

//----- (00C407D0) --------------------------------------------------------
int __cdecl Command_Cancel(HWND hWnd)
{
  int result; // eax

  if ( gbWindowFinding )
  {
    SearchWindow(hWnd);
    result = 0;
  }
  else
  {
    if ( gConfig.bHideWhenMinimized )
      CMainWnd::Hide(ghMainWnd);
    else
      CMainWnd::HandleDestroy(hWnd);
    result = 0;
  }
  return result;
}
// CDA38B: using guessed type char gbWindowFinding;

//----- (00C40830) --------------------------------------------------------
int Options_ShowHiddenProcess()
{
  WCHAR **v0; // eax
  int v1; // esi
  WCHAR **v2; // ecx
  WCHAR **v3; // eax
  tagTREEVIEWLISTITEMPARAM *i; // eax
  HMENU v5; // eax

  v0 = gpHiddenProcesses;
  v1 = 0;
  if ( *gpHiddenProcesses )
  {
    v2 = gpHiddenProcesses;
    do
    {
      free(*v2);
      v0 = gpHiddenProcesses;
      v2 = &gpHiddenProcesses[++v1];
    }
    while ( *v2 );
  }
  free(v0);
  v3 = (WCHAR **)malloc(4u);
  gpHiddenProcesses = v3;
  *v3 = 0;
  for ( i = gpTreeViewListItemParam; i; i = i->m_Prev )
    i->dwStyle &= 0xFFFFFFFE;
  SaveHiddenProcessesToRegistry();
  v5 = GetMenu(ghMainWnd);
  EnableMenuItem(v5, 0x9C9Bu, 1u);
  SetEvent(ghTimerRefreshEvent);
  return 0;
}

//----- (00C408C0) --------------------------------------------------------
int __cdecl Command_Font(HWND hWnd)
{
  PE_SelectFont(hWnd);
  return 0;
}

//----- (00C408E0) --------------------------------------------------------
int Command_OnProperties()
{
  HWND v0; // esi
  int nIndex; // eax
  tagLVITEMW ItemInfo; // [esp+4h] [ebp-34h]

  ItemInfo.mask = 0;
  memset(&ItemInfo.iItem, 0, 0x30u);
  v0 = ghWndTreeListView;
  nIndex = SendMessageW(ghWndTreeListView, LVM_GETNEXTITEM, 0xFFFFFFFF, LVFI_STRING);
  if ( nIndex != -1 )
  {
    ItemInfo.iItem = nIndex;
    ItemInfo.iSubItem = 0;
    ItemInfo.mask = LVIF_PARAM;
    if ( SendMessageW(v0, LVM_GETITEMW, 0, (LPARAM)&ItemInfo) )
    {
      InterlockedIncrement(&ItemInfo.lParam->field_0);
      ItemInfo.lParam->dwProcessId = gdwProcessIdSelected;
      _beginthread((int)PropertiesThreadProc, 0, (int)ItemInfo.lParam);
    }
  }
  return 0;
}

//----- (00C40970) --------------------------------------------------------
int __cdecl sub_C40970(int a1, __int16 a2)
{
  tagTREEVIEWLISTITEMPARAM *v2; // esi
  tagTREEVIEWLISTITEMPARAM *FindInfoParam; // eax
  int v4; // ecx
  int v5; // eax
  unsigned int v6; // eax
  LRESULT v7; // eax
  tagLVITEMW ItemInfo2; // [esp+0h] [ebp-80h]
  tagLVITEMW ItemInfo; // [esp+34h] [ebp-4Ch]
  tagLVFINDINFOW FindInfo; // [esp+68h] [ebp-18h]

  if ( GetFocus() != ghWndTreeListView )
    return 0;
  ItemInfo.iItem = SendMessageW(ghWndTreeListView, LVM_GETNEXTITEM, 0xFFFFFFFF, 2);
  if ( ItemInfo.iItem != -1 )
  {
    ItemInfo.iSubItem = 0;
    ItemInfo.mask = 4;
    if ( SendMessageW(ghWndTreeListView, LVM_GETITEMW, 0, (LPARAM)&ItemInfo) )
    {
      v2 = ItemInfo.lParam;
      if ( a2 == 40087 )
      {
        if ( ItemInfo.lParam->dwStyle & 4 )
        {
          ItemInfo2.stateMask = 3;
          ++ItemInfo.iItem;
          ItemInfo2.state = 3;
          SendMessageW(ghWndTreeListView, LVM_SETITEMSTATE, ItemInfo.iItem, (LPARAM)&ItemInfo2);
LABEL_20:
          v7 = SendMessageW(ghWndTreeListView, LVM_GETNEXTITEM, 0xFFFFFFFF, 2);
          SendMessageW(ghWndTreeListView, LVM_ENSUREVISIBLE, v7, 0);
          return 0;
        }
      }
      else if ( a2 == 40088 && !(ItemInfo.lParam->dwStyle & 4) )
      {
        FindInfoParam = ItemInfo.lParam->pItemParam;
        if ( FindInfoParam )
        {
          while ( 1 )
          {
            v4 = FindInfoParam->dwStyle;
            if ( v4 & 2 )
            {
              if ( !(v4 & 1) || !gConfig.byte_14012ADFE )
                break;
            }
            FindInfoParam = FindInfoParam->pItemParam;
            if ( !FindInfoParam )
              goto LABEL_20;
          }
          FindInfo.lParam = (LPARAM)FindInfoParam;
          FindInfo.flags = 1;
          ItemInfo.iItem = SendMessageW(ghWndTreeListView, LVM_FINDITEMW, 0xFFFFFFFF, (LPARAM)&FindInfo);
          ItemInfo2.stateMask = 3;
          ItemInfo2.state = 3;
          SendMessageW(ghWndTreeListView, LVM_SETITEMSTATE, ItemInfo.iItem, (LPARAM)&ItemInfo2);
        }
        goto LABEL_20;
      }
      v5 = ItemInfo.lParam->dwStyle;
      if ( v5 & 4 )
        v6 = v5 & 0xFFFFFFFB;
      else
        v6 = v5 | 4;
      ItemInfo.lParam->dwStyle = v6;
      SendMessageW(ghWndTreeListView, TREELIST_MSG_2001, v2->field_5B8, (v6 >> 2) & 1);
      sub_C28DA0(v2);
      goto LABEL_20;
    }
  }
  return 0;
}

//----- (00C40B10) --------------------------------------------------------
int Command_OptionsToConfirmKill()
{
  signed int v0; // eax
  bool v1; // zf
  UINT v2; // ST08_4
  HMENU v3; // eax

  v0 = 0;
  v1 = gConfig.bConfirmKill != 0;
  gConfig.bConfirmKill = gConfig.bConfirmKill == 0;
  if ( !v1 )
    v0 = 8;
  v2 = v0;
  v3 = GetMenu(ghMainWnd);
  CheckMenuItem(v3, IDM_OPTIONS_CONFIRM_KILL, v2);
  UpdateWindowPlacement(ghMainWnd, 1);
  return 0;
}

//----- (00C40B60) --------------------------------------------------------
int Command_ShowNewProcesses()
{
  signed int v0; // eax
  bool v1; // zf
  UINT v2; // ST08_4
  HMENU v3; // eax

  v0 = 0;
  v1 = gConfig.bFormatIoBytes != 0;
  gConfig.bFormatIoBytes = gConfig.bFormatIoBytes == 0;
  if ( !v1 )
    v0 = 8;
  v2 = v0;
  v3 = GetMenu(ghMainWnd);
  CheckMenuItem(v3, 0x9F25u, v2);
  UpdateWindowPlacement(ghMainWnd, 1);
  InvalidateRect(ghMainWnd, 0, 0);
  return 0;
}

//----- (00C40BC0) --------------------------------------------------------
int Command_SaveHiddenProcesses()
{
  int v0; // eax
  tagTREEVIEWLISTITEMPARAM *v1; // esi
  tagTREEVIEWLISTITEMPARAM *i; // edi
  int v3; // eax
  unsigned int v4; // eax
  int v5; // esi
  HMENU v6; // eax
  WCHAR **v8; // eax
  int v9; // ecx
  bool v10; // zf
  WCHAR **j; // ecx
  tagLVITEMW ItemInfo; // [esp+4h] [ebp-34h]

  ItemInfo.mask = 0;
  memset(&ItemInfo.iItem, 0, 0x30u);
  v0 = SendMessageW(ghWndTreeListView, LVM_GETNEXTITEM, 0xFFFFFFFF, 2);
  if ( v0 == -1 )
    return 0;
  ItemInfo.iItem = v0;
  ItemInfo.iSubItem = 0;
  ItemInfo.mask = LVIF_PARAM;
  if ( !SendMessageW(ghWndTreeListView, LVM_GETITEMW, 0, (LPARAM)&ItemInfo) )
    return 0;
  v1 = gpTreeViewListItemParam;
  for ( i = ItemInfo.lParam; v1; v1 = v1->m_Prev )
  {
    if ( !_wcsicmp(v1->szProcessName2, i->szProcessName2) )
    {
      v3 = v1->dwStyle;
      if ( v3 & 1 )
        v4 = v3 & 0xFFFFFFFE;
      else
        v4 = v3 | 1;
      v1->dwStyle = v4;
    }
  }
  v5 = 0;
  if ( !(i->dwStyle & 1) )
  {
    v8 = gpHiddenProcesses;
    if ( *gpHiddenProcesses )
    {
      v9 = 0;
      while ( 1 )
      {
        v10 = _wcsicmp(v8[v9], i->szProcessName2) == 0;
        v8 = gpHiddenProcesses;
        if ( v10 )
          break;
        v9 = ++v5;
        if ( !gpHiddenProcesses[v5] )
        {
          SaveHiddenProcessesToRegistry();
          return 0;
        }
      }
      free(gpHiddenProcesses[v5]);
      for ( j = &gpHiddenProcesses[v5]; gpHiddenProcesses[v5]; j = &gpHiddenProcesses[v5] )
      {
        ++v5;
        *j = j[1];
      }
    }
    SaveHiddenProcessesToRegistry();
    return 0;
  }
  if ( *gpHiddenProcesses )
  {
    do
      ++v5;
    while ( gpHiddenProcesses[v5] );
  }
  gpHiddenProcesses = (WCHAR **)realloc(gpHiddenProcesses, 4 * v5 + 8);
  gpHiddenProcesses[v5] = _wcsdup(i->szProcessName2);
  gpHiddenProcesses[v5 + 1] = 0;
  SetEvent(ghTimerRefreshEvent);
  v6 = GetMenu(ghMainWnd);
  EnableMenuItem(v6, IDM_VIEW_SHOW_HIDDEN_PROCESSES, 0);
  SaveHiddenProcessesToRegistry();
  return 0;
}

//----- (00C40D80) --------------------------------------------------------
int __cdecl Command_DifferenceHiliteDuration(HWND hWndParent)
{
  DialogBoxParamW(ghInstance, L"DIFFDURATION", hWndParent, DlgDifferenceHiliteDuration, 0);
  return 0;
}

//----- (00C40DB0) --------------------------------------------------------
int Command_Save()
{
  PE_Save(0);
  return 0;
}

//----- (00C40DC0) --------------------------------------------------------
int __cdecl Command_CpuHistory(HWND hWndParent)
{
  HWND v1; // esi
  LRESULT v2; // eax
  HANDLE v3; // eax
  void *v4; // esi
  LPARAM lParam; // [esp+4h] [ebp-34h]
  LRESULT v7; // [esp+8h] [ebp-30h]
  int v8; // [esp+Ch] [ebp-2Ch]
  int v9; // [esp+24h] [ebp-14h]

  lParam = 0;
  memset(&v7, 0, 0x30u);
  v1 = ghWndTreeListView;
  v2 = SendMessageW(ghWndTreeListView, 0x100Cu, 0xFFFFFFFF, 2);
  if ( v2 != -1 )
  {
    v7 = v2;
    v8 = 0;
    lParam = 4;
    if ( SendMessageW(v1, 0x104Bu, 0, (LPARAM)&lParam) )
    {
      if ( v1 == ghWndTreeListView )
      {
        v3 = OpenProcess(0x600u, 0, *(_DWORD *)(v9 + 68));
        v4 = v3;
        if ( !v3 )
        {
          ReportMsg(L"Unable to set process affinity", ghMainWnd);
          return 0;
        }
        DialogBoxParamW(ghInstance, L"CPUAFFINITY", hWndParent, DialogFunc, (LPARAM)v3);
        CloseHandle(v4);
      }
    }
  }
  return 0;
}

//----- (00C40E90) --------------------------------------------------------
int Command_SaveAs()
{
  PE_Save(1);
  return 0;
}

//----- (00C40EA0) --------------------------------------------------------
int Command_CloseHandle()
{
  HWND hWndFocus; // esi
  int nItem; // eax
  tagHANDLELISTITEMPARAM *pHandleItem; // esi
  LVITEMW v4; // [esp+8h] [ebp-78h]
  LVITEMW lParam; // [esp+3Ch] [ebp-44h]
  int InBuffer; // [esp+70h] [ebp-10h]
  int v7; // [esp+74h] [ebp-Ch]
  int v8; // [esp+7Ch] [ebp-4h]

  lParam.mask = 0;
  memset(&lParam.iItem, 0, 0x30u);
  hWndFocus = GetFocus();
  if ( hWndFocus == ghWndDllsListCtrl )
    hWndFocus = ghWndTreeListView;
  nItem = SendMessageW(hWndFocus, LVM_GETNEXTITEM, 0xFFFFFFFF, 2);
  if ( nItem == -1 )
  {
    if ( hWndFocus == ghWndTreeListView )
    {
      MessageBoxW(ghWndTreeListView, L"No process selected", L"Process Explorer Error", MB_ICONERROR);
      return 0;
    }
    if ( hWndFocus == ghWndHandlesListCtrl )
    {
      MessageBoxW(ghWndTreeListView, L"No handle selected", L"Process Explorer Error", MB_ICONERROR);
      return 0;
    }
    MessageBoxW(ghWndTreeListView, L"No handle or process selected", L"Process Explorer Error", MB_ICONERROR);
    return 0;
  }
  lParam.iItem = nItem;
  lParam.iSubItem = 0;
  lParam.mask = 4;
  if ( !SendMessageW(hWndFocus, LVM_GETITEMW, 0, (LPARAM)&lParam) )
    return 0;
  if ( hWndFocus == ghWndTreeListView || hWndFocus == ghWndDllsListCtrl )
  {
    if ( PE_ConfirmToKillProcess(lParam.lParam->szProcessName2, lParam.lParam->dwProcessId) )
    {
      SetEvent(ghRefreshEventHandle);
      v4.stateMask = 3;
      v4.state = 3;
      SendMessageW(ghWndTreeListView, LVM_SETITEMSTATE, lParam.iItem - 1, (LPARAM)&v4);
      return 0;
    }
    return 0;
  }
  if ( hWndFocus != ghWndHandlesListCtrl )
    return 0;
  pHandleItem = (tagHANDLELISTITEMPARAM *)lParam.lParam;
  if ( !IsBuiltinAdministrative() )
  {
    MessageBoxW(
      ghWndHandlesListCtrl,
      L"Closing handles requires administrative rights.",
      L"Process Explorer Error",
      MB_ICONERROR);
    return 0;
  }
  if ( !pHandleItem->field_24 )
  {
    MessageBoxW(
      ghWndHandlesListCtrl,
      L"Handles in the Idle process cannot be closed.",
      L"Process Explorer Error",
      MB_ICONERROR);
    return 0;
  }
  if ( gConfig.bConfirmKill
    && MessageBoxW(
         ghWndHandlesListCtrl,
         L"Forcing a handle closed can lead to an application crash and system instability.\nContinue with close?",
         L"Process Explorer Warning",
         0x34u) != MB_CANCELTRYCONTINUE )
  {
    return 0;
  }
  v8 = pHandleItem->field_2C;
  InBuffer = pHandleItem->field_24;
  v7 = pHandleItem->field_28;
  if ( CDriver::Control(CTRLCODE_OPEN_PROCESS, &InBuffer, 0x10u, 0, 0) )
  {
    SetEvent(ghRefreshEventHandle);
    v4.stateMask = 3;
    v4.state = 3;
    SendMessageW(ghWndHandlesListCtrl, LVM_SETITEMSTATE, lParam.iItem - 1, (LPARAM)&v4);
    SetFocus(ghWndHandlesListCtrl);
  }
  else
  {
    ReportMsg(L"Error opening process", ghMainWnd);
  }
  return 0;
}

//----- (00C410F0) --------------------------------------------------------
int Command_SuspendProcess()
{
  HWND hWndTreeListView; // esi
  int nItem; // eax
  tagTREEVIEWLISTITEMPARAM *pItemParam; // esi
  int v3; // eax
  unsigned int v4; // eax
  const WCHAR *v5; // eax
  const WCHAR *v6; // ST10_4
  HMENU v7; // eax
  int result; // eax
  LVITEMW Item; // [esp+8h] [ebp-38h]
  BOOL bRet; // [esp+3Ch] [ebp-4h]

  Item.mask = 0;
  memset(&Item.iItem, 0, 0x30u);
  hWndTreeListView = ghWndTreeListView;
  nItem = SendMessageW(ghWndTreeListView, LVM_GETNEXTITEM, 0xFFFFFFFF, LVFI_STRING);
  if ( nItem != -1
    && (Item.iItem = nItem,
        Item.iSubItem = 0,
        Item.mask = 4,
        SendMessageW(hWndTreeListView, LVM_GETITEMW, 0, (LPARAM)&Item))
    && (pItemParam = Item.lParam, SetFocus(ghWndTreeListView), pItemParam) )
  {
    if ( PE_SuspendProcess(
           ~(unsigned __int8)((unsigned int)pItemParam->dwStyle >> 7) & 1,
           pItemParam->dwProcessId,
           &bRet) )
    {
      ReportMsg(L"Unable to suspend the process", ghMainWnd);
    }
    else
    {
      v3 = pItemParam->dwStyle;
      if ( (v3 & 0x80u) == 0 )
        v4 = v3 | 0x80;
      else
        v4 = v3 & -0x81u;
      pItemParam->dwStyle = v4;
    }
    SendMessageW(ghWndTreeListView, LVM_REDRAWITEMS, Item.iItem, Item.iItem);
    v5 = L"R&esume";
    if ( SLOBYTE(Item.lParam->dwStyle) >= 0 )
      v5 = L"S&uspend";
    v6 = v5;
    v7 = GetMenu(ghMainWnd);
    ModifyMenuW(v7, IDM_PROCESS_SUSPEND, 0, IDM_PROCESS_SUSPEND, v6);
    result = 0;
  }
  else
  {
    MessageBoxW(ghWndTreeListView, L"No process is selected", L"Process Explorer Error", MB_ICONERROR);
    result = 0;
  }
  return result;
}
// CAE398: using guessed type wchar_t aREsume[8];

//----- (00C41230) --------------------------------------------------------
int __cdecl Command_ShowLowerPane(HWND hWnd)
{
  HMENU v1; // ebx
  UINT v2; // ecx
  bool v3; // zf
  HMENU v4; // eax
  HWND hWndLV; // edi
  LRESULT v7; // eax
  const WCHAR *v8; // eax
  UINT_PTR hHandleMenuPopup; // eax
  LRESULT nItem; // eax
  const WCHAR *v11; // [esp-4h] [ebp-24h]
  struct tagRECT Rect; // [esp+Ch] [ebp-14h]

  v1 = GetMenu(ghMainWnd);
  v2 = 0;
  v3 = gConfig.bShowLowerPane != 0;
  gConfig.bShowLowerPane = gConfig.bShowLowerPane == 0;
  if ( !v3 )
    v2 = 8;
  CheckMenuItem(v1, IDM_VIEW_SHOW_LOWER_PANE, v2);
  SendMessageW(ghWndToolbar, TB_CHANGEBITMAP, IDM_VIEW_SHOW_LOWER_PANE, (gConfig.bShowLowerPane != 0) + 9);
  InvalidateRect(ghWndToolbar, 0, 1);
  GetClientRect(ghMainWnd, &Rect);
  if ( gConfig.bShowLowerPane )
  {
    gConfig.dbDivider = gConfig.dbSavedDivider;
    CMainWnd::HandleSize(
      ghMainWnd,
      0,
      0,
      (unsigned __int16)(LOWORD(Rect.right) - LOWORD(Rect.left)) | ((unsigned __int16)(LOWORD(Rect.bottom)
                                                                                     - LOWORD(Rect.top)) << 16));
    hWndLV = ghWndHandlesListCtrl;
    if ( gConfig.bShowDllView )
      hWndLV = ghWndDllsListCtrl;
    v7 = SendMessageW(ghWndTreeListView, LVM_GETNEXTITEM, 0xFFFFFFFF, 2);
    SendMessageW(ghWndTreeListView, LVM_ENSUREVISIBLE, v7, 0);
    ShowWindow(hWndLV, 5);
    if ( hWnd )
      SetEvent(ghRefreshEventHandle);
    v8 = L"&DLL";
    if ( !gConfig.bShowDllView )
      v8 = L"H&andle";
    v11 = v8;
    hHandleMenuPopup = ghHandlesMenuPopup;
    if ( gConfig.bShowDllView )
      hHandleMenuPopup = ghDllMenuPopup;
    InsertMenuW(v1, 5u, 0x410u, hHandleMenuPopup, v11);
    DrawMenuBar(ghMainWnd);
    nItem = SendMessageW(hWndLV, LVM_GETNEXTITEM, 0xFFFFFFFF, 2);
    UpdateMenuStatus(nItem != -1, 5);
  }
  else if ( IsWindowVisible(ghWndHandlesListCtrl) || IsWindowVisible(ghWndDllsListCtrl) )
  {
    ShowWindow(ghWndHandlesListCtrl, 0);
    ShowWindow(ghWndDllsListCtrl, 0);
    v4 = GetMenu(ghMainWnd);
    RemoveMenu(v4, 5u, MF_BYPOSITION);
    DrawMenuBar(ghMainWnd);
    gConfig.dbSavedDivider = gConfig.dbDivider;
    gConfig.dbDivider = db_one;
    CMainWnd::HandleSize(
      ghMainWnd,
      0,
      0,
      (unsigned __int16)(LOWORD(Rect.right) - LOWORD(Rect.left)) | ((unsigned __int16)(LOWORD(Rect.bottom)
                                                                                     - LOWORD(Rect.top)) << 16));
    return 0;
  }
  return 0;
}

//----- (00C41490) --------------------------------------------------------
int __cdecl OnProperties(HWND a1, __int16 nID)
{
  HWND hWnd; // esi
  int nItem; // eax
  tagTREEVIEWLISTITEMPARAM *v4; // esi
  tagLVITEMW ItemInfo; // [esp+4h] [ebp-34h]

  ItemInfo.mask = 0;
  memset(&ItemInfo.iItem, 0, 0x30u);
  switch ( nID )
  {
    case IDM_DLL_PROPERTIES:
      hWnd = ghWndDllsListCtrl;
      break;
    case IDM_HANDLE_PROPERTIES:
      hWnd = ghWndHandlesListCtrl;
      break;
    case IDM_PROCESS_PROPERTIES:
      hWnd = ghWndTreeListView;
      break;
    default:
      hWnd = GetFocus();
      break;
  }
  nItem = SendMessageW(hWnd, LVM_GETNEXTITEM, 0xFFFFFFFF, LVFI_STRING);
  if ( nItem == -1 )
  {
    if ( hWnd == ghWndTreeListView )
    {
      MessageBoxW(ghWndTreeListView, L"No process is selected", L"Process Explorer Error", MB_ICONSTOP);
      return 0;
    }
    if ( hWnd == ghWndDllsListCtrl )
    {
      MessageBoxW(ghWndTreeListView, L"No DLL is selected", L"Process Explorer Error", MB_ICONHAND);
      return 0;
    }
    if ( hWnd == ghWndHandlesListCtrl )
      MessageBoxW(ghWndTreeListView, L"No object is selected", L"Process Explorer Error", MB_ICONHAND);
    return 0;
  }
  ItemInfo.iItem = nItem;
  ItemInfo.iSubItem = 0;
  ItemInfo.mask = LVIF_PARAM;
  if ( !SendMessageW(hWnd, LVM_GETITEMW, 0, (LPARAM)&ItemInfo) )
    return 0;
  if ( hWnd == ghWndDllsListCtrl )
  {
    v4 = ItemInfo.lParam;
    if ( ItemInfo.lParam->field_2C & 8 )
    {
      MessageBoxW(
        ghWndTreeListView,
        L"Properties not supported on pagefile-backed sections",
        L"Process Explorer Error",
        MB_ICONHAND);
      return 0;
    }
    if ( *(_DWORD *)&ItemInfo.lParam->gap154[4] )
    {
      InterlockedIncrement(&ItemInfo.lParam->field_0);
      v4->dwStyle = gdwProcessIdSelected;
      _beginthread((int)PropertiesThreadProc, 0, (int)v4);
      return 0;
    }
    return 0;
  }
  if ( hWnd == ghWndHandlesListCtrl )
    FillHandleListParam(hWnd, (tagHANDLELISTITEMPARAM *)ItemInfo.lParam);
  else
    CTreeList::FillTreeViewParam(ItemInfo.lParam);
  return 0;
}

//----- (00C41620) --------------------------------------------------------
int __cdecl UpdateSpeedOptions_Update(HWND a1, UINT a2)
{
  signed int v2; // eax
  UINT v3; // ebx
  signed int v4; // eax
  HMENU v5; // eax
  HMENU v6; // eax
  UINT v8; // [esp-14h] [ebp-14h]

  v2 = gConfig.dwRefreshRate;
  if ( gdwRefreshMenuIDLast == -1 )
  {
    if ( (signed int)gConfig.dwRefreshRate > 2000 )
    {
      if ( gConfig.dwRefreshRate == 5000 )
      {
        gdwRefreshMenuIDLast = IDM_VIEW_UPDATESPEED_FIVE_SECONDS;
      }
      else if ( gConfig.dwRefreshRate == 10000 )
      {
        gdwRefreshMenuIDLast = 40022;
      }
    }
    else if ( gConfig.dwRefreshRate == 2000 )
    {
      gdwRefreshMenuIDLast = 40019;
    }
    else if ( gConfig.dwRefreshRate )
    {
      if ( gConfig.dwRefreshRate == 500 )
      {
        gdwRefreshMenuIDLast = 40023;
      }
      else if ( gConfig.dwRefreshRate == 1000 )
      {
        gdwRefreshMenuIDLast = 40021;
      }
    }
    else
    {
      gdwRefreshMenuIDLast = 40018;
    }
  }
  LOWORD(v3) = a2;
  if ( (_WORD)a2 == -25518 && !gConfig.dwRefreshRate )
  {
    SendMessageW(ghWndStatusBar, SB_SETTEXTW, gnStatusBarItemCount - 1, (LPARAM)&gszNullString);
    v4 = gdwRefreshMenuIDLast;
    if ( gdwRefreshMenuIDLast == -1 )
      v4 = 1000;
    v3 = (unsigned __int16)v4;
    gdwRefreshMenuIDLast = v4;
    v2 = gConfig.dwRefreshRate;
    a2 = v3;
  }
  if ( v2 > 2000 )
  {
    if ( v2 == 5000 )
    {
      v8 = 40020;
    }
    else
    {
      if ( v2 != 10000 )
        goto LABEL_34;
      v8 = 40022;
    }
  }
  else if ( v2 == 2000 )
  {
    v8 = 40019;
  }
  else if ( v2 )
  {
    if ( v2 == 500 )
    {
      v8 = 40023;
    }
    else
    {
      if ( v2 != 1000 )
        goto LABEL_34;
      v8 = 40021;
    }
  }
  else
  {
    v8 = 40018;
  }
  v5 = GetMenu(ghMainWnd);
  CheckMenuItem(v5, v8, 0);
LABEL_34:
  v3 = (unsigned __int16)v3;
  switch ( (unsigned __int16)v3 )
  {
    case 0x9C52u:
      gConfig.dwRefreshRate = 0;
      SendMessageW(ghWndStatusBar, 0x40Bu, gnStatusBarItemCount - 1, (LPARAM)L"Paused");
      break;
    case 0x9C53u:
      gConfig.dwRefreshRate = 2000;
      break;
    case 0x9C54u:
      gConfig.dwRefreshRate = 5000;
      break;
    case 0x9C55u:
      gConfig.dwRefreshRate = 1000;
      break;
    case 0x9C56u:
      gConfig.dwRefreshRate = 10000;
      break;
    case 0x9C57u:
      gConfig.dwRefreshRate = 500;
      break;
    default:
      break;
  }
  v6 = GetMenu(ghMainWnd);
  CheckMenuItem(v6, v3, 8u);
  if ( (_WORD)a2 != -25518 )
  {
    SendMessageW(ghWndStatusBar, 0x40Bu, gnStatusBarItemCount - 1, (LPARAM)&gszNullString);
    SetEvent(ghRefreshEventHandle);
    gdwRefreshMenuIDLast = v3;
  }
  return 0;
}
// CB0D80: using guessed type wchar_t aPaused[7];
// CCE10C: using guessed type int gdwRefreshMenuIDLast;
// CF5720: using guessed type int gnStatusBarItemCount;

//----- (00C41850) --------------------------------------------------------
int OnProcessProperties()
{
  tagLVKEYDOWNEX keydow; // [esp+0h] [ebp-2Ch]
  int v2; // [esp+14h] [ebp-18h]
  __int64 v3; // [esp+24h] [ebp-8h]

  keydow.hdr.hwndFrom = ghWndTreeListView;
  _mm_storeu_si128((__m128i *)&keydow.hdr.idFrom, (__m128i)0i64);
  gConfig.bShowProcessTree = 0;
  gConfig.bProcessSortDirection = 0;
  _mm_storeu_si128((__m128i *)&v2, (__m128i)0i64);
  keydow.hdr.idFrom = IDC_TREEVIEW_LIST;
  v3 = 0i64;
  *(_DWORD *)&keydow.uID = 0;
  CMainWnd::HandleLVNColumnClick(101u, (LPNMLVKEYDOWN)&keydow);
  return 0;
}

//----- (00C418A0) --------------------------------------------------------
int __usercall ProcessPriority_Update@<eax>(int a1@<edi>, HWND a2, __int16 a3)
{
  HWND v3; // esi
  LRESULT v4; // eax
  signed int v5; // ebx
  UINT v6; // esi
  signed int v7; // edi
  HANDLE v8; // eax
  DWORD v9; // ST0C_4
  void *v10; // edi
  HMENU v11; // eax
  int v13; // [esp-4h] [ebp-4Ch]
  int v14; // [esp+0h] [ebp-48h]
  LPARAM lParam; // [esp+8h] [ebp-40h]
  WPARAM wParam; // [esp+Ch] [ebp-3Ch]
  int v17; // [esp+10h] [ebp-38h]
  int v18; // [esp+28h] [ebp-20h]
  UINT v19; // [esp+3Ch] [ebp-Ch]
  int v20; // [esp+40h] [ebp-8h]
  int v21; // [esp+44h] [ebp-4h]

  lParam = 0;
  memset(&wParam, 0, 0x30u);
  v3 = ghWndTreeListView;
  v4 = SendMessageW(ghWndTreeListView, 0x100Cu, 0xFFFFFFFF, 2);
  if ( v4 == -1 )
  {
    if ( v3 == ghWndTreeListView )
      MessageBoxW(ghWndTreeListView, L"No process selected", L"Process Explorer Error", 0x10u);
    return 0;
  }
  wParam = v4;
  v17 = 0;
  lParam = 4;
  if ( !SendMessageW(v3, 0x104Bu, 0, (LPARAM)&lParam) || v3 != ghWndTreeListView )
    return 0;
  v13 = a1;
  switch ( a3 )
  {
    case 0x9CBB:
      v5 = 4;
      v6 = 40123;
      v7 = 64;
      break;
    case 0x9CBC:
      v5 = 4;
      v6 = 40124;
      v7 = 64;
      break;
    case 0x9CBD:
      v5 = 6;
      v6 = 40125;
      v7 = 0x4000;
      break;
    case 0x9CBE:
      v5 = 8;
      v6 = 40126;
      v7 = 32;
      break;
    case 0x9CBF:
      v5 = 10;
      v6 = 40127;
      v7 = 0x8000;
      break;
    case 0x9CC0:
      v5 = 13;
      v6 = 40128;
      v7 = 128;
      break;
    case 0x9CC1:
      v5 = 24;
      v6 = 40129;
      v7 = 256;
      break;
    default:
      v5 = v19;
      v6 = v19;
      v7 = v19;
      break;
  }
  v8 = OpenProcess(0x200u, 0, *(_DWORD *)(v18 + 68));
  if ( v8 )
  {
    v9 = v7;
    v10 = v8;
    if ( SetPriorityClass(v8, v9) )
    {
      if ( v6 == 40124 )
      {
        v21 = 0;
        NtSetInformationProcess(v10, 33, &v21, 4, v13);
        v20 = 1;
      }
      else
      {
        v21 = 2;
        NtSetInformationProcess(v10, 33, &v21, 4, v13);
        v20 = 5;
      }
      NtSetInformationProcess(v10, 39, &v20, 4, v14);
      *(_DWORD *)(v18 + 1368) = v5;
      v11 = GetMenu(ghMainWnd);
      CheckMenuRadioItem(v11, 0x9CBBu, 0x9CC1u, v6, 0);
      SendMessageW(ghWndTreeListView, 0x1015u, wParam, wParam);
      goto LABEL_21;
    }
  }
  else
  {
    v10 = 0;
  }
  MessageBoxW(ghWndTreeListView, L"Unable to set process priority", L"Process Explorer Error", 0x10u);
LABEL_21:
  if ( v10 )
    CloseHandle(v10);
  return 0;
}
// C418A0: could not find valid save-restore pair for edi
// CDB1C8: using guessed type int (__stdcall *NtSetInformationProcess)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD);

//----- (00C41AD0) --------------------------------------------------------
int Options_AllowOneInstance()
{
  signed int v0; // eax
  bool v1; // zf
  UINT v2; // ST08_4
  HMENU v3; // eax

  v0 = 0;
  v1 = gConfig.bAllOneInstance != 0;
  gConfig.bAllOneInstance = gConfig.bAllOneInstance == 0;
  if ( !v1 )
    v0 = 8;
  v2 = v0;
  v3 = GetMenu(ghMainWnd);
  CheckMenuItem(v3, IDM_OPTIONS_ALLOW_ONLY_ONE_INSTANCE, v2);
  UpdateWindowPlacement(ghMainWnd, 1);
  return 0;
}

//----- (00C41B20) --------------------------------------------------------
int __cdecl Command_Run(HWND hWndParent, int a2)
{
  HMODULE v2; // eax
  FARPROC v3; // eax

  v2 = LoadLibraryW(L"shell32.dll");
  v3 = GetProcAddress(v2, (LPCSTR)0x3D);
  gpfnRunFileDlg = (int)v3;
  if ( v3 )
    ((void (__stdcall *)(HWND, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))v3)(hWndParent, 0, 0, 0, 0, 0);
  else
    DialogBoxParamW(ghInstance, L"RUNDLG", hWndParent, DlgRun, (unsigned __int16)a2);
  return 0;
}
// CDA8D8: using guessed type int gpfnRunFileDlg;

//----- (00C41B80) --------------------------------------------------------
int __cdecl Command_RunAs(HWND hWndParent, int a2)
{
  DialogBoxParamW(ghInstance, L"RUNDLG", hWndParent, DlgRun, (unsigned __int16)a2);
  return 0;
}

//----- (00C41BB0) --------------------------------------------------------
int __cdecl Options_HideWhenMinimized(HWND hWnd)
{
  signed int v1; // eax
  bool v2; // zf
  UINT v3; // ST0C_4
  HMENU v4; // eax

  v1 = 0;
  v2 = gConfig.bHideWhenMinimized != 0;
  gConfig.bHideWhenMinimized = gConfig.bHideWhenMinimized == 0;
  if ( !v2 )
    v1 = 8;
  v3 = v1;
  v4 = GetMenu(hWnd);
  CheckMenuItem(v4, 0x9C75u, v3);
  if ( gConfig.bHideWhenMinimized
    && !gConfig.bTrayCPUHistory
    && !gConfig.bShowCommitTray
    && !gConfig.bShowPhysTray
    && !gConfig.bShowIoTray )
  {
    Command_ViewCpuHistory(hWnd);
  }
  UpdateWindowPlacement(ghMainWnd, 1);
  return 0;
}

//----- (00C41C40) --------------------------------------------------------
int __cdecl OpacityOptions_Update(HWND hWnd, int a2)
{
  UINT v2; // ST08_4
  HMENU v3; // eax
  LONG v4; // eax
  UINT v5; // ST08_4
  HMENU v6; // eax

  v2 = ((signed int)((unsigned __int64)(1717986919i64 * (signed int)gConfig.dwOpacity) >> 32) >> 2)
     + ((unsigned int)((unsigned __int64)(1717986919i64 * (signed int)gConfig.dwOpacity) >> 32) >> 31)
     + 40093;
  v3 = GetMenu(hWnd);
  CheckMenuItem(v3, v2, 0);
  gConfig.dwOpacity = 10 * ((unsigned __int16)a2 - 40093);
  v4 = GetWindowLongW(ghMainWnd, -20);
  if ( gConfig.dwOpacity == 100 )
  {
    SetWindowLongW(ghMainWnd, -20, v4 & 0xFFF7FFFF);
  }
  else
  {
    SetWindowLongW(ghMainWnd, -20, v4 | 0x80000);
    SetLayeredWindowAttributes(ghMainWnd, 0, (signed int)(255 * gConfig.dwOpacity) / 100, 2u);
  }
  RedrawWindow(ghMainWnd, 0, 0, 0x485u);
  v5 = ((signed int)((unsigned __int64)(1717986919i64 * (signed int)gConfig.dwOpacity) >> 32) >> 2)
     + ((unsigned int)((unsigned __int64)(1717986919i64 * (signed int)gConfig.dwOpacity) >> 32) >> 31)
     + 40093;
  v6 = GetMenu(hWnd);
  CheckMenuItem(v6, v5, 8u);
  return 0;
}

//----- (00C41D40) --------------------------------------------------------
int __cdecl UserAccount_Refresh(HWND a1, __int16 a2)
{
  char v2; // al
  char v4; // [esp+7h] [ebp-405h]
  WCHAR Text; // [esp+8h] [ebp-404h]
  wchar_t Dst; // [esp+208h] [ebp-204h]

  switch ( a2 )
  {
    case 0x9C84:
      wcscpy_s(&Dst, 0x100u, L"logoff");
      break;
    case 0x9C85:
      wcscpy_s(&Dst, 0x100u, L"shutdown");
      break;
    case 0x9C86:
      wcscpy_s(&Dst, 0x100u, L"restart");
      break;
    case 0x9C87:
      wcscpy_s(&Dst, 0x100u, L"hibernate");
      break;
    case 0x9C88:
      wcscpy_s(&Dst, 0x100u, L"stand by");
      break;
    case 0x9C92:
      wcscpy_s(&Dst, 0x100u, L"lock the computer");
      break;
    default:
      break;
  }
  wsprintf(&Text, L"Do you really want to %s?", &Dst);
  if ( MessageBoxW(ghWndTreeListView, &Text, L"Process Explorer Shutdown", 0x24u) != 7 )
  {
    UpdateWindowPlacement(ghMainWnd, 1);
    TmAdjustPrivilege(L"SeShutdownPrivilege");
    switch ( a2 )
    {
      case 0:
        v2 = ExitWindowsEx(0, 0);
        break;
      case 1:
        if ( (unsigned __int8)ExitWindowsEx(8u, 0) )
          return 0;
        v2 = ExitWindowsEx(1u, 0);
        break;
      case 2:
        v2 = ExitWindowsEx(2u, 0);
        break;
      case 3:
        v2 = SetSuspendState(1u, 1u, 0);
        break;
      case 4:
        v2 = SetSuspendState(0, 1u, 0);
        break;
      case 0xE:
        v2 = LockWorkStation();
        break;
      default:
        v2 = v4;
        break;
    }
    if ( !v2 )
    {
      wsprintf(&Text, L"Error trying to %s", &Dst);
      ReportMsg(&Text, ghMainWnd);
    }
  }
  return 0;
}
// CB1C74: using guessed type wchar_t aShutdown[9];
// CB1C88: using guessed type wchar_t aRestart[8];
// CB1C98: using guessed type wchar_t aLogoff[7];
// CB1CA8: using guessed type wchar_t aHibernate[10];
// CB1CBC: using guessed type wchar_t aStandBy[9];

//----- (00C41F10) --------------------------------------------------------
int __cdecl Command_ReplaceTaskManager(HWND hWnd)
{
  HKEY v1; // ecx
  UINT v2; // ST08_4
  HMENU v3; // eax

  if ( gdwVersion < 1 || IsBuiltinAdministrative() )
  {
    if ( CanReplaceTaskManager() )
      sub_C35E40(v1);
    else
      ReplaceTaskManager(hWnd, 1);
  }
  else
  {
    sub_C36180(L"/rt", 5, 1);
  }
  v2 = CanReplaceTaskManager() != 0 ? 8 : 0;
  v3 = GetMenu(hWnd);
  CheckMenuItem(v3, 0x9C7Bu, v2);
  return 0;
}
// CB16AC: using guessed type wchar_t aRt_0[4];
// CD4E54: using guessed type int gdwVersion;

//----- (00C41F80) --------------------------------------------------------
int __cdecl Command_ConfigSymbols(HWND hWndParent)
{
  DialogBoxParamW(ghInstance, L"SYMBOLCONFIG", hWndParent, DlgSymbolConfig, 0);
  return 0;
}

//----- (00C41FB0) --------------------------------------------------------
int Command_SystemInformation()
{
  HCURSOR v1; // eax
  HCURSOR v2; // esi

  if ( ghWndSysinfoPropSheet )
  {
    ShowWindow(ghWndSysinfoPropSheet, SW_RESTORE);
    SetFocus(ghWndSysinfoPropSheet);
    SetForegroundWindow(ghWndSysinfoPropSheet);
  }
  else
  {
    v1 = LoadCursorW(0, (LPCWSTR)IDC_WAIT);
    v2 = SetCursor(v1);
    _beginthread((int)BackendSysInfoPropSheetThreadProc, 0, 0);
    WaitForSingleObject(ghSystemInfoSheetThreadEvent, 0xFFFFFFFF);
    SetCursor(v2);
  }
  return 0;
}

//----- (00C42020) --------------------------------------------------------
int __cdecl Command_ConfirmToKillProcess(HWND hWnd)
{
  signed int v1; // eax
  bool v2; // zf
  UINT v3; // ST08_4
  HMENU v4; // eax

  v1 = 0;
  v2 = gConfig.bShowCpuFractions != 0;
  gConfig.bShowCpuFractions = gConfig.bShowCpuFractions == 0;
  if ( !v2 )
    v1 = 8;
  v3 = v1;
  v4 = GetMenu(hWnd);
  CheckMenuItem(v4, 0x9C6Du, v3);
  InvalidateRgn(ghWndTreeListView, 0, 1);
  return 0;
}

//----- (00C42070) --------------------------------------------------------
int __cdecl Command_ConfigColors(HWND hWndParent)
{
  DialogBoxParamW(ghInstance, L"CHOOSECOLORS", hWndParent, (DLGPROC)DlgSelectColor, 0);
  return 0;
}

//----- (00C420A0) --------------------------------------------------------
int Process_CleanMemory()
{
  HWND ghWndTreeListView; // esi
  int nCurItem; // eax
  HANDLE ProcessHandle; // eax
  void *v3; // esi
  LVITEMW Item; // [esp+4h] [ebp-34h]

  Item.mask = 0;
  memset(&Item.iItem, 0, 0x30u);
  ghWndTreeListView = ::ghWndTreeListView;
  nCurItem = SendMessageW(::ghWndTreeListView, 0x100Cu, 0xFFFFFFFF, 2);
  if ( nCurItem == -1 )
  {
    if ( ghWndTreeListView == ::ghWndTreeListView )
      MessageBoxW(::ghWndTreeListView, L"No process selected", L"Process Explorer Error", MB_ICONSTOP);
  }
  else
  {
    Item.iItem = nCurItem;
    Item.iSubItem = 0;
    Item.mask = LVIF_PARAM;
    if ( SendMessageW(ghWndTreeListView, LVM_GETITEMW, 0, (LPARAM)&Item) )
    {
      ProcessHandle = OpenProcess(0x100u, 0, Item.lParam->dwProcessId);
      v3 = ProcessHandle;
      // If both dwMinimumWorkingSetSize and dwMaximumWorkingSetSize have the value (SIZE_T)â€?, the function removes as many pages as possible from the working set of the specified process.
      if ( ProcessHandle && SetProcessWorkingSetSize(ProcessHandle, 0xFFFFFFFF, 0xFFFFFFFF) )
        SetEvent(ghRefreshEventHandle);
      else
        ReportMsg(L"Unable to trim process working set", ghMainWnd);
      if ( v3 )
      {
        CloseHandle(v3);
        return 0;
      }
    }
  }
  return 0;
}

//----- (00C42190) --------------------------------------------------------
int __cdecl WindowOptions_Refresh(HWND a1, int a2)
{
  HWND v2; // esi
  LRESULT v3; // eax
  tagTREEVIEWLISTITEMPARAM *v4; // esi
  LPARAM lParam; // [esp+4h] [ebp-34h]
  LRESULT v7; // [esp+8h] [ebp-30h]
  int v8; // [esp+Ch] [ebp-2Ch]
  tagTREEVIEWLISTITEMPARAM *pItem; // [esp+24h] [ebp-14h]

  lParam = 0;
  memset(&v7, 0, 0x30u);
  v2 = ghWndTreeListView;
  v3 = SendMessageW(ghWndTreeListView, 0x100Cu, 0xFFFFFFFF, 2);
  if ( v3 != -1 )
  {
    v7 = v3;
    v8 = 0;
    lParam = 4;
    if ( SendMessageW(v2, 0x104Bu, 0, (LPARAM)&lParam) )
    {
      v4 = pItem;
      sub_C36B90(0, a2, pItem->dwProcessId);
      RefreshMenuWithTreeViewItemStatus(v4);
    }
  }
  return 0;
}

//----- (00C42210) --------------------------------------------------------
int Command_ShowColumnHeatmaps()
{
  signed int v0; // eax
  bool v1; // zf
  UINT v2; // ST08_4
  HMENU v3; // eax

  v0 = 0;
  v1 = gConfig.bShowColumnHeatmaps != 0;
  gConfig.bShowColumnHeatmaps = gConfig.bShowColumnHeatmaps == 0;
  if ( !v1 )
    v0 = 8;
  v2 = v0;
  v3 = GetMenu(ghMainWnd);
  CheckMenuItem(v3, 0x9C99u, v2);
  SetEvent(ghTimerRefreshEvent);
  return 0;
}

//----- (00C42260) --------------------------------------------------------
int __cdecl Command_VerifyImage(HWND hWnd)
{
  signed int v1; // eax
  bool v2; // zf
  UINT v3; // ST24_4
  HMENU v4; // eax
  int v5; // edi
  tagTREEVIEWLISTITEMPARAM *v6; // esi
  tagLVITEMW ItemInfo; // [esp+0h] [ebp-34h]

  ItemInfo.mask = 0;
  memset(&ItemInfo.iItem, 0, 0x30u);
  v1 = 0;
  v2 = gConfig.bVerifySignatures != 0;
  gConfig.bVerifySignatures = gConfig.bVerifySignatures == 0;
  if ( !v2 )
    v1 = 8;
  v3 = v1;
  v4 = GetMenu(hWnd);
  CheckMenuItem(v4, IDM_OPTIONS_VERIFY_IMAGE_SIGNATURE, v3);
  if ( !gConfig.bVerifySignatures )
    return 0;
  CTreeList_InsertVerifyColumn(
    ghWndTreeListView,
    IDS_VERIFIED_SIGNER,
    gConfig.dwProcessColumnMap,
    (int)&gConfig.dwProcessColumnCount);
  CTreeList_InsertVerifyColumn(
    ghWndDllsListCtrl,
    IDS_VERIFIED_SIGNER,
    (int *)gConfig.dwDllColumnMap,
    (int)&gConfig.dwDllColumnCount);
  v5 = SendMessageW(ghWndTreeListView, LVM_GETITEMCOUNT, 0, 0);
  ItemInfo.iItem = 0;
  if ( v5 <= 0 )
    return 0;
  do
  {
    ItemInfo.iSubItem = 0;
    ItemInfo.mask = LVIF_PARAM;
    if ( SendMessageW(ghWndTreeListView, LVM_GETITEMW, 0, (LPARAM)&ItemInfo) )
    {
      v6 = ItemInfo.lParam;
      InterlockedIncrement(&ItemInfo.lParam->nRefCount);
      _beginthread((int)VerifyImageThreadProc, 0, (int)v6);
    }
    ++ItemInfo.iItem;
  }
  while ( ItemInfo.iItem < v5 );
  return 0;
}

//----- (00C42390) --------------------------------------------------------
int __cdecl Command_CheckVirusTotalDotCom(HWND hWnd)
{
  signed int v1; // eax
  UINT v2; // ST0C_4
  HMENU v3; // eax
  BOOL v4; // ST0C_4
  HMENU v5; // eax
  tagDLLLISTITEMPARAM *v6; // esi
  tagDLLLISTITEMPARAM *v7; // edi
  WCHAR *v8; // eax
  tagDLLLISTITEMPARAM *i; // esi
  int v10; // eax

  if ( !SubmitExeToVirusTotalDotCom() )
    return 0;
  v1 = 0;
  gConfig.bCheckVirusTotal = gConfig.bCheckVirusTotal == 0;
  if ( gConfig.bCheckVirusTotal )
    v1 = 8;
  v2 = v1;
  v3 = GetMenu(hWnd);
  CheckMenuItem(v3, 0x9CB3u, v2);
  v4 = gConfig.bCheckVirusTotal == 0;
  v5 = GetMenu(hWnd);
  EnableMenuItem(v5, 0x9F36u, v4);
  if ( gConfig.bCheckVirusTotal )
  {
    v6 = (tagDLLLISTITEMPARAM *)gpTreeViewListItemParam;
    v7 = 0;
    CTreeList_InsertVerifyColumn(
      ghWndTreeListView,
      0x686u,
      gConfig.dwProcessColumnMap,
      (int)&gConfig.dwProcessColumnCount);
    for ( ; v6; v6 = (tagDLLLISTITEMPARAM *)v6[3].field_118 )
    {
      v8 = v6[2].m_szProcessName2;
      if ( v6->m_dwProcessId == gdwProcessIdSelected )
        v7 = v6;
      if ( v8 && *((_DWORD *)v8 + 1) == 1 )
        *((_DWORD *)v8 + 1) = 6;
      if ( v6[2].field_8 )
        sub_C71C30(v6, 1, 0);
    }
    InvalidateRect(ghWndTreeListView, 0, 0);
    CTreeList_InsertVerifyColumn(
      ghWndDllsListCtrl,
      0x686u,
      (int *)gConfig.dwDllColumnMap,
      (int)&gConfig.dwDllColumnCount);
    if ( v7 && IsWindowVisible(ghWndDllsListCtrl) )
    {
      for ( i = gpDllListItemParamHeader; i; i = i->m_Prev )
      {
        v10 = i->m_HashData;
        if ( v10 && *(_DWORD *)(v10 + 4) == 1 )
          *(_DWORD *)(v10 + 4) = 6;
        if ( i->m_strPath.pszData )
          sub_C71C30(i, ~(unsigned __int8)((unsigned int)i->field_2C >> 1) & 1, 0);
      }
      InvalidateRect(ghWndDllsListCtrl, 0, 0);
    }
  }
  return 0;
}

//----- (00C42520) --------------------------------------------------------
int __cdecl Command_SubmitUnkownExecutables(HWND hWnd)
{
  signed int v1; // eax
  bool v2; // zf
  UINT v3; // ST10_4
  HMENU v4; // eax
  tagDLLLISTITEMPARAM *v5; // esi
  tagDLLLISTITEMPARAM *v6; // edi
  WCHAR *v7; // eax
  tagDLLLISTITEMPARAM *i; // esi
  int v9; // eax
  unsigned int v10; // eax

  if ( !SubmitExeToVirusTotalDotCom() )
    return 0;
  v1 = 0;
  v2 = gConfig.bVirusTotalSubmitUnknown != 0;
  gConfig.bVirusTotalSubmitUnknown = gConfig.bVirusTotalSubmitUnknown == 0;
  if ( !v2 )
    v1 = 8;
  v3 = v1;
  v4 = GetMenu(hWnd);
  CheckMenuItem(v4, 0x9F36u, v3);
  if ( !gConfig.bVirusTotalSubmitUnknown )
    return 0;
  v5 = (tagDLLLISTITEMPARAM *)gpTreeViewListItemParam;
  v6 = 0;
  if ( gpTreeViewListItemParam )
  {
    do
    {
      v7 = v5[2].m_szProcessName2;
      if ( v5->m_dwProcessId == gdwProcessIdSelected )
        v6 = v5;
      if ( v7 && *((_DWORD *)v7 + 1) == 6 && *(_BYTE *)v7 )
        sub_C71C30(v5, 1, 1);
      v5 = (tagDLLLISTITEMPARAM *)v5[3].field_118;
    }
    while ( v5 );
  }
  InvalidateRect(ghWndTreeListView, 0, 0);
  if ( v6 && IsWindowVisible(ghWndDllsListCtrl) )
  {
    for ( i = gpDllListItemParamHeader; i; i = i->m_Prev )
    {
      v9 = i->m_HashData;
      if ( v9 && *(_DWORD *)(v9 + 4) == 6 )
      {
        v10 = (unsigned int)i->field_2C >> 1;
        if ( !(v10 & 1) )
          sub_C71C30(i, ~(_BYTE)v10 & 1, 1);
      }
    }
    InvalidateRect(ghWndDllsListCtrl, 0, 0);
  }
  return 0;
}

//----- (00C42640) --------------------------------------------------------
int Command_CheckVirusTotalDotCom()
{
  HWND v0; // esi
  char v1; // bl
  LRESULT v2; // eax
  tagDLLLISTITEMPARAM *v3; // esi
  WCHAR *v4; // eax
  LPARAM lParam; // [esp+8h] [ebp-34h]
  LRESULT v7; // [esp+Ch] [ebp-30h]
  int v8; // [esp+10h] [ebp-2Ch]
  tagDLLLISTITEMPARAM *pItemParam; // [esp+28h] [ebp-14h]

  lParam = 0;
  memset(&v7, 0, 0x30u);
  v0 = ghWndTreeListView;
  v1 = 0;
  v2 = SendMessageW(ghWndTreeListView, 0x100Cu, 0xFFFFFFFF, 2);
  if ( v2 != -1 )
  {
    v7 = v2;
    v8 = 0;
    lParam = 4;
    if ( SendMessageW(v0, 0x104Bu, 0, (LPARAM)&lParam) )
    {
      v3 = pItemParam;
      SetFocus(ghWndTreeListView);
      if ( v3 )
      {
        if ( SubmitExeToVirusTotalDotCom() )
        {
          CTreeList_InsertVerifyColumn(
            ghWndTreeListView,
            0x686u,
            gConfig.dwProcessColumnMap,
            (int)&gConfig.dwProcessColumnCount);
          v4 = v3[2].m_szProcessName2;
          if ( v4 )
          {
            if ( *((_DWORD *)v4 + 1) == 6 )
            {
              v1 = 1;
            }
            else if ( v4 && *((_DWORD *)v4 + 1) == 1 )
            {
              *((_DWORD *)v4 + 1) = 6;
            }
          }
          sub_C71C30(v3, 1, v1 != 0);
          InvalidateRect(ghWndTreeListView, 0, 0);
        }
      }
    }
  }
  return 0;
}

//----- (00C42740) --------------------------------------------------------
int Command_Check_VirusTotalDotCom()
{
  HWND v0; // esi
  char v1; // bl
  LRESULT v2; // eax
  tagDLLLISTITEMPARAM *v3; // esi
  int v4; // eax
  LPARAM lParam; // [esp+8h] [ebp-34h]
  LRESULT v7; // [esp+Ch] [ebp-30h]
  int v8; // [esp+10h] [ebp-2Ch]
  tagDLLLISTITEMPARAM *pItemParam; // [esp+28h] [ebp-14h]

  lParam = 0;
  memset(&v7, 0, 0x30u);
  v0 = ghWndDllsListCtrl;
  v1 = 0;
  v2 = SendMessageW(ghWndDllsListCtrl, 0x100Cu, 0xFFFFFFFF, 2);
  if ( v2 != -1 )
  {
    v7 = v2;
    v8 = 0;
    lParam = 4;
    if ( SendMessageW(v0, 0x104Bu, 0, (LPARAM)&lParam) )
    {
      v3 = pItemParam;
      SetFocus(ghWndTreeListView);
      if ( v3 )
      {
        if ( SubmitExeToVirusTotalDotCom() )
        {
          CTreeList_InsertVerifyColumn(
            ghWndDllsListCtrl,
            0x686u,
            (int *)gConfig.dwDllColumnMap,
            (int)&gConfig.dwDllColumnCount);
          v4 = v3->m_HashData;
          if ( v4 )
          {
            if ( *(_DWORD *)(v4 + 4) == 6 )
            {
              v1 = 1;
            }
            else if ( v4 && *(_DWORD *)(v4 + 4) == 1 )
            {
              *(_DWORD *)(v4 + 4) = 6;
            }
          }
          sub_C71C30(v3, 1, v1 != 0);
          InvalidateRect(ghWndDllsListCtrl, 0, 0);
        }
      }
    }
  }
  return 0;
}

//----- (00C42840) --------------------------------------------------------
int Command_ShowDetailsForAllProcesses()
{
  DWORD v0; // eax

  UpdateWindowPlacement(ghMainWnd, 1);
  CreateEventW(0, 0, 1, L"ProcessExplorerElevating");
  v0 = sub_C36180((const WCHAR *)gszCmdLine, 5, 0);
  if ( v0 )
  {
    if ( v0 != 1223 )
    {
      ReportMsg(L"Error elevating", ghMainWnd);
      return 0;
    }
  }
  else
  {
    DestroyWindow(ghMainWnd);
  }
  return 0;
}
// CDA38C: using guessed type int gszCmdLine;

//----- (00C428B0) --------------------------------------------------------
int __cdecl Command_SetTopmost(HWND hWnd)
{
  signed int v1; // eax
  UINT v2; // ST18_4
  HMENU v3; // eax

  v1 = 0;
  gConfig.bAlwaysOntop = gConfig.bAlwaysOntop == 0;
  if ( gConfig.bAlwaysOntop )
    v1 = 8;
  v2 = v1;
  v3 = GetMenu(hWnd);
  CheckMenuItem(v3, 0x9C82u, v2);
  if ( gConfig.bAlwaysOntop )
  {
    SetWindowPos(hWnd, HWND_MESSAGE|0x2, 0, 0, 0, 0, SWP_NOMOVE|SWP_NOSIZE);
    if ( ghWndSysinfoPropSheet )
    {
      SetWindowPos(ghWndSysinfoPropSheet, HWND_MESSAGE|0x2, 0, 0, 0, 0, SWP_NOMOVE|SWP_NOSIZE);
      return 0;
    }
  }
  else
  {
    if ( ghWndSysinfoPropSheet )
      SetWindowPos(ghWndSysinfoPropSheet, (HWND)HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE|SWP_NOSIZE);
    SetWindowPos(hWnd, (HWND)HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE|SWP_NOSIZE);
  }
  return 0;
}

//----- (00C42960) --------------------------------------------------------
int __cdecl Command_ViewCpuHistory(HWND hWnd)
{
  signed int v1; // eax
  UINT v2; // ST08_4
  HMENU v3; // eax

  if ( !sub_C479E0(gConfig.bTrayCPUHistory == 0) )
  {
    v1 = 0;
    gConfig.bTrayCPUHistory = gConfig.bTrayCPUHistory == 0;
    if ( gConfig.bTrayCPUHistory )
      v1 = 8;
    v2 = v1;
    v3 = GetMenu(hWnd);
    CheckMenuItem(v3, 0x9EC4u, v2);
    HandleTaskbarCreated();
  }
  return 0;
}

//----- (00C429C0) --------------------------------------------------------
int __cdecl Command_ViewIoHistory(HWND hWnd)
{
  signed int v1; // eax
  UINT v2; // ST08_4
  HMENU v3; // eax

  if ( !sub_C479E0(gConfig.bShowIoTray == 0) )
  {
    v1 = 0;
    gConfig.bShowIoTray = gConfig.bShowIoTray == 0;
    if ( gConfig.bShowIoTray )
      v1 = 8;
    v2 = v1;
    v3 = GetMenu(hWnd);
    CheckMenuItem(v3, 0x9F0Fu, v2);
    HandleTaskbarCreated();
  }
  return 0;
}

//----- (00C42A20) --------------------------------------------------------
int __cdecl Command_CommitNetworkHistory(HWND hWnd)
{
  signed int v1; // eax
  UINT v2; // ST08_4
  HMENU v3; // eax

  if ( !sub_C479E0(gConfig.bShowNetTray == 0) )
  {
    v1 = 0;
    gConfig.bShowNetTray = gConfig.bShowNetTray == 0;
    if ( gConfig.bShowNetTray )
      v1 = 8;
    v2 = v1;
    v3 = GetMenu(hWnd);
    CheckMenuItem(v3, 0x9F2Bu, v2);
    HandleTaskbarCreated();
  }
  return 0;
}

//----- (00C42A80) --------------------------------------------------------
int __cdecl Command_CommitDiskHistory(HWND hWnd)
{
  signed int v1; // eax
  UINT v2; // ST08_4
  HMENU v3; // eax

  if ( !sub_C479E0(gConfig.bShowDiskTray == 0) )
  {
    v1 = 0;
    gConfig.bShowDiskTray = gConfig.bShowDiskTray == 0;
    if ( gConfig.bShowDiskTray )
      v1 = 8;
    v2 = v1;
    v3 = GetMenu(hWnd);
    CheckMenuItem(v3, 0x9F2Au, v2);
    HandleTaskbarCreated();
  }
  return 0;
}

//----- (00C42AE0) --------------------------------------------------------
int __cdecl Command_CommitGPUHistory(HWND hWnd)
{
  signed int v1; // eax
  UINT v2; // ST08_4
  HMENU v3; // eax

  if ( !sub_C479E0(gConfig.bShowGpuHistory == 0) )
  {
    v1 = 0;
    gConfig.bShowGpuHistory = gConfig.bShowGpuHistory == 0;
    if ( gConfig.bShowGpuHistory )
      v1 = 8;
    v2 = v1;
    v3 = GetMenu(hWnd);
    CheckMenuItem(v3, 0x9F2Cu, v2);
    HandleTaskbarCreated();
  }
  return 0;
}

//----- (00C42B40) --------------------------------------------------------
int __usercall Command_RunAtLogon@<eax>(_DWORD *a1@<edi>, HWND hWnd)
{
  bool v2; // al
  UINT v3; // ST08_4
  HMENU v4; // eax
  int savedregs; // [esp+0h] [ebp+0h]

  v2 = IsProcessExplorerRunAtStartup((int)&savedregs, a1);
  sub_C337F0(v2 == 0);
  v3 = IsProcessExplorerRunAtStartup((int)&savedregs, a1) != 0 ? 8 : 0;
  v4 = GetMenu(hWnd);
  CheckMenuItem(v4, 0x9F30u, v3);
  return 0;
}

//----- (00C42B90) --------------------------------------------------------
int __cdecl Command_ViewCommitHistory(HWND hWnd)
{
  signed int v1; // eax
  UINT v2; // ST08_4
  HMENU v3; // eax

  if ( !sub_C479E0(gConfig.bShowCommitTray == 0) )
  {
    v1 = 0;
    gConfig.bShowCommitTray = gConfig.bShowCommitTray == 0;
    if ( gConfig.bShowCommitTray )
      v1 = 8;
    v2 = v1;
    v3 = GetMenu(hWnd);
    CheckMenuItem(v3, 0x9F16u, v2);
    HandleTaskbarCreated();
  }
  return 0;
}

//----- (00C42BF0) --------------------------------------------------------
int __cdecl Command_ViewPhysicalMemoryHistory(HWND hWnd)
{
  signed int v1; // eax
  UINT v2; // ST08_4
  HMENU v3; // eax

  if ( !sub_C479E0(gConfig.bShowPhysTray == 0) )
  {
    v1 = 0;
    gConfig.bShowPhysTray = gConfig.bShowPhysTray == 0;
    if ( gConfig.bShowPhysTray )
      v1 = 8;
    v2 = v1;
    v3 = GetMenu(hWnd);
    CheckMenuItem(v3, 0x9F17u, v2);
    HandleTaskbarCreated();
  }
  return 0;
}

//----- (00C42C50) --------------------------------------------------------
signed int __usercall Command_SetColumn@<eax>(double a1@<st0>, double a2@<st1>, double a3@<st2>, double st1_0@<st6>, double st2_0@<st5>, double a6@<st4>, double a7@<st3>, HWND hWnd, unsigned __int16 uID)
{
  __int32 index; // esi
  BOOL v11; // ST2C_4
  HMENU v12; // eax
  LRESULT v13; // eax
  double a4; // [esp+0h] [ebp-A0h]
  double a5; // [esp+8h] [ebp-98h]
  tagLVKEYDOWNEX pThis; // [esp+10h] [ebp-90h]
  int v17; // [esp+24h] [ebp-7Ch]
  __int64 v18; // [esp+34h] [ebp-6Ch]
  tagPEStatusBarItem StatusBarItem; // [esp+3Ch] [ebp-64h]
  struct tagRECT Rect; // [esp+8Ch] [ebp-14h]

  index = uID - IDM_PROCESS_PRIORITY_BASE;
  pThis.hdr.hwndFrom = 0;
  _mm_storeu_si128((__m128i *)&pThis.hdr.idFrom, (__m128i)0i64);
  _mm_storeu_si128((__m128i *)&v17, (__m128i)0i64);
  v18 = 0i64;
  if ( index >= (signed int)gConfig.dwNumColumnsets )
    return 1;
  SendMessageW(ghWndTreeListView, WM_SETREDRAW, 0, 0);
  SendMessageW(ghWndHandlesListCtrl, WM_SETREDRAW, 0, 0);
  SendMessageW(ghWndDllsListCtrl, WM_SETREDRAW, 0, 0);
  qmemcpy(gConfig.szColumnSetName, &gConfig.strMenuCulumnSet[index], 1524u);
  sub_C47930((int)gConfig.szColumnSetName);
  InitListHeader(
    ghWndTreeListView,
    (UINT *)gConfig.dwProcessColumnMap,
    (WORD *)gConfig.dwProcessColumns,
    gConfig.dwProcessColumnCount);
  InitListHeader(
    ghWndHandlesListCtrl,
    gConfig.dwIdsOfHandleColumnMap,
    gConfig.dwHandleColumns,
    gConfig.dwHandleColumnCount);
  InitListHeader(ghWndDllsListCtrl, gConfig.dwDllColumnMap, gConfig.dwDllColumns, gConfig.dwDllColumnCount);
  GetClientRect(ghMainWnd, &Rect);
  CMainWnd::HandleSize(ghMainWnd, 0, 0, LOWORD(Rect.right) | (LOWORD(Rect.bottom) << 16));
  CTreeList::InitHeaderColumn(
    ghWndHandlesListCtrl,
    0xFFFFFFFF,
    (HWND)gConfig.dwHandleSortColumn,
    gConfig.bHandleSortDirection);
  CTreeList::InitHeaderColumn(ghWndDllsListCtrl, 0xFFFFFFFF, (HWND)gConfig.dwDllSortColumn, gConfig.bDllSortDirection);
  pThis.hdr.idFrom = 101;
  pThis.hdr.hwndFrom = ghWndTreeListView;
  if ( gConfig.bShowProcessTree )
  {
    gConfig.bShowProcessTree = 0;
    gConfig.bProcessSortDirection = 0;
    *(_DWORD *)&pThis.uID = 0;
  }
  else
  {
    gConfig.bProcessSortDirection = gConfig.bProcessSortDirection == 0;
    *(_DWORD *)&pThis.uID = gConfig.dwProcessSortColumn;
  }
  CMainWnd::HandleLVNColumnClick(0x65u, (LPNMLVKEYDOWN)&pThis);
  SendMessageW(ghWndToolbar, TB_ENABLEBUTTON, IDM_VIEW_SHOW_PROCESS_TREE, gConfig.bShowProcessTree == 0);
  v11 = gConfig.bShowProcessTree != 0;
  v12 = GetMenu(ghMainWnd);
  EnableMenuItem(v12, IDM_VIEW_SHOW_PROCESS_TREE, v11);
  memset(&StatusBarItem, 0, 0x50u);
  sub_C70410(a1, a2, a3, a7, a6, st2_0, st1_0, 0, &StatusBarItem, &a4, &a5);
  CMainWnd::InitStatusBar(ghWndStatusBar);
  PE_ResortList(0x66u);
  PE_ResortList(0x68u);
  SendMessageW(ghWndTreeListView, 0xBu, 1u, 0);
  SendMessageW(ghWndHandlesListCtrl, 0xBu, 1u, 0);
  SendMessageW(ghWndDllsListCtrl, 0xBu, 1u, 0);
  v13 = SendMessageW(ghWndTreeListView, LVM_GETNEXTITEM, 0xFFFFFFFF, 2);
  SendMessageW(ghWndTreeListView, LVM_ENSUREVISIBLE, v13, 0);
  return 0;
}

//----- (00C42F00) --------------------------------------------------------
int sub_C42F00()
{
  gConfig.bUseGoogle = 1;
  return 0;
}

//----- (00C42F10) --------------------------------------------------------
int sub_C42F10()
{
  gConfig.bUseGoogle = 0;
  return 0;
}

//----- (00C42F20) --------------------------------------------------------
int __cdecl Command_LaunchDepends(HWND a1, __int16 a2)
{
  HWND v2; // edi
  const WCHAR *v3; // esi
  LRESULT v4; // eax
  struct _STARTUPINFOW StartupInfo; // [esp+8h] [ebp-8E8h]
  SHELLEXECUTEINFOW pExecInfo; // [esp+4Ch] [ebp-8A4h]
  LPARAM lParam; // [esp+88h] [ebp-868h]
  LRESULT v9; // [esp+8Ch] [ebp-864h]
  int v10; // [esp+90h] [ebp-860h]
  int v11; // [esp+A8h] [ebp-848h]
  struct _PROCESS_INFORMATION ProcessInformation; // [esp+BCh] [ebp-834h]
  WCHAR CommandLine; // [esp+CCh] [ebp-824h]

  lParam = 0;
  memset(&v9, 0, 0x30u);
  v2 = ghWndTreeListView;
  v3 = 0;
  if ( a2 == -25504 )
    v2 = ghWndDllsListCtrl;
  if ( v2 == ghWndHandlesListCtrl )
    v2 = ghWndTreeListView;
  v4 = SendMessageW(v2, 0x100Cu, 0xFFFFFFFF, 2);
  if ( v4 != -1 )
  {
    v9 = v4;
    v10 = 0;
    lParam = 4;
    if ( SendMessageW(v2, 0x104Bu, 0, (LPARAM)&lParam) )
    {
      if ( v2 == ghWndDllsListCtrl )
      {
        if ( *(_BYTE *)(v11 + 44) & 8 )
        {
          MessageBoxW(
            ghWndTreeListView,
            L"Depends not supported on pagefile-backed sections",
            L"Process Explorer Error",
            0x10u);
          return 0;
        }
        v3 = *(const WCHAR **)(v11 + 344);
        SetFocus(ghWndDllsListCtrl);
      }
      else
      {
        v3 = *(const WCHAR **)(v11 + 792);
        if ( !v3 )
        {
          MessageBoxW(ghWndTreeListView, L"No process image file.", L"Process Explorer Error", 0x10u);
          return 0;
        }
        SetFocus(ghWndTreeListView);
      }
    }
  }
  if ( !*v3 )
  {
    MessageBoxW(ghWndTreeListView, L"No process or DLL is selected", L"Process Explorer Error", 0x10u);
    return 0;
  }
  if ( gstrApplicationName )
  {
    sub_C468E0(&CommandLine, L"depends \"%s\"", v3);
    memset(&StartupInfo, 0, 0x44u);
    StartupInfo.dwFlags = 1;
    StartupInfo.cb = 68;
    StartupInfo.wShowWindow = 5;
    _mm_storeu_si128((__m128i *)&ProcessInformation, (__m128i)0i64);
    if ( CreateProcessW(&gstrApplicationName, &CommandLine, 0, 0, 0, 0x200u, 0, 0, &StartupInfo, &ProcessInformation) )
    {
      CloseHandle(ProcessInformation.hThread);
      CloseHandle(ProcessInformation.hProcess);
      return 0;
    }
  }
  else
  {
    memset(&pExecInfo, 0, 0x3Cu);
    pExecInfo.cbSize = 60;
    pExecInfo.lpFile = v3;
    pExecInfo.lpVerb = L"View Dependencies";
    pExecInfo.fMask = 0;
    pExecInfo.nShow = 5;
    ShellExecuteExW(&pExecInfo);
  }
  return 0;
}
// CB1F14: using guessed type wchar_t aViewDependenci[18];

//----- (00C431A0) --------------------------------------------------------
int Command_DebugProcess()
{
  HWND v0; // edi
  int v1; // esi
  LRESULT v2; // eax
  struct _STARTUPINFOW StartupInfo; // [esp+8h] [ebp-49Ch]
  LPARAM lParam; // [esp+4Ch] [ebp-458h]
  LRESULT v6; // [esp+50h] [ebp-454h]
  int v7; // [esp+54h] [ebp-450h]
  int v8; // [esp+6Ch] [ebp-438h]
  struct _PROCESS_INFORMATION ProcessInformation; // [esp+80h] [ebp-424h]
  WCHAR CommandLine; // [esp+90h] [ebp-414h]

  lParam = 0;
  memset(&v6, 0, 0x30u);
  v0 = ghWndTreeListView;
  v1 = 0;
  v2 = SendMessageW(ghWndTreeListView, 0x100Cu, 0xFFFFFFFF, 2);
  if ( v2 != -1
    && (v6 = v2, v7 = 0, lParam = 4, SendMessageW(v0, 0x104Bu, 0, (LPARAM)&lParam))
    && (v1 = v8, SetFocus(ghWndTreeListView), v1) )
  {
    if ( MessageBoxW(
           ghWndTreeListView,
           L"WARNING: Debugging this process may result in loss of data.\nAre you sure you wish to attach the debugger?",
           L"Process Explorer Warning",
           0x31u) == 2 )
      return 0;
  }
  else
  {
    MessageBoxW(ghWndTreeListView, L"No process is selected", L"Process Explorer Error", 0x10u);
  }
  MakeHandlePropSheetCaption(&CommandLine, L"\"%s\" -p %d", gszAeDebuggerPath, *(_DWORD *)(v1 + 68));
  memset(&StartupInfo, 0, 0x44u);
  StartupInfo.dwFlags = 1;
  StartupInfo.cb = 68;
  StartupInfo.wShowWindow = 5;
  _mm_storeu_si128((__m128i *)&ProcessInformation, (__m128i)0i64);
  if ( CreateProcessW(0, &CommandLine, 0, 0, 0, 0x200u, 0, 0, &StartupInfo, &ProcessInformation) )
  {
    CloseHandle(ProcessInformation.hThread);
    CloseHandle(ProcessInformation.hProcess);
  }
  return 0;
}

//----- (00C43330) --------------------------------------------------------
int __cdecl Command_ShowProcessesForAllUsers(HWND hWnd)
{
  MACRO_MF v1; // eax
  bool v2; // zf
  UINT v3; // ST0C_4
  HMENU v4; // eax
  tagTREEVIEWLISTITEMPARAM *i; // eax
  int v6; // ecx
  LRESULT nCount; // ebx
  tagTREEVIEWLISTITEMPARAM **v8; // edi
  int v9; // esi
  LRESULT j; // edi
  tagTREEVIEWLISTITEMPARAM *v11; // esi
  int v12; // eax
  LVITEMW lParam; // [esp+Ch] [ebp-38h]
  void *ppItems; // [esp+40h] [ebp-4h]

  SendMessageW(ghWndTreeListView, WM_SETREDRAW, 0, 0);
  v1 = MF_UNCHECKED;
  v2 = gConfig.bShowAllUsers != 0;
  gConfig.bShowAllUsers = gConfig.bShowAllUsers == 0;
  if ( !v2 )
    v1 = MF_CHECKED;
  v3 = v1;
  v4 = GetMenu(hWnd);
  CheckMenuItem(v4, IDM_VIEW_SHOW_PROCESSES_FROM_ALL_USERS, v3);
  for ( i = gpTreeViewListItemParam; i; i = i->m_Prev )
  {
    if ( gConfig.bShowAllUsers || (v6 = i->dwStyle, v6 & 0x40) )
      i->dwStyle |= 2u;
    else
      i->dwStyle = v6 & -3u;
  }
  nCount = SendMessageW(ghWndTreeListView, LVM_GETITEMCOUNT, 0, 0);
  v8 = (tagTREEVIEWLISTITEMPARAM **)operator new[](4 * nCount);
  v9 = 0;
  for ( ppItems = v8; v9 < nCount; ++v9 )
  {
    lParam.iItem = v9;
    lParam.iSubItem = 0;
    lParam.mask = 4;
    SendMessageW(ghWndTreeListView, LVM_GETITEMW, 0, (LPARAM)&lParam);
    v8[v9] = lParam.lParam;
  }
  SendMessageW(ghWndTreeListView, LVM_DELETEALLITEMS, 0, 0);
  for ( j = 0; j < nCount; v11->field_5B8 = v12 )
  {
    v11 = (tagTREEVIEWLISTITEMPARAM *)*((_DWORD *)ppItems + j);
    v12 = sub_C27F20(ghWndTreeListView, *((tagTREEVIEWLISTITEMPARAM **)ppItems + j++));
  }
  operator delete[](ppItems);
  gbDllsOrHandlesSorting = 1;
  SetEvent(ghTimerRefreshEvent);
  return 0;
}
// CD53B5: using guessed type char gbDllsOrHandlesSorting;

//----- (00C43490) --------------------------------------------------------
int __cdecl Command_SaveColumnSet(HWND hWndParent)
{
  DialogBoxParamW(ghInstance, L"COLUMNSETSAVE", hWndParent, DlgColumnSetSave, 0);
  return 0;
}

//----- (00C434C0) --------------------------------------------------------
int __cdecl Command_OrganizeColumnSets(HWND hWnd)
{
  if ( gConfig.dwNumColumnsets )
    DialogBoxParamW(ghInstance, L"COLUMNSETS", hWnd, (DLGPROC)DlgColumnSets, 0);
  else
    MessageBoxW(
      hWnd,
      L"There are no column sets defined. Use View->Save Column Set to save a column set.",
      L"Process Explorer",
      0x30u);
  return 0;
}

//----- (00C43510) --------------------------------------------------------
LRESULT __cdecl CMainWnd::HandleCommand(HWND hWnd, int a2, WPARAM wParam, LPARAM lParam)
{
  return HandleCmdHandler((int)&CMainWnd::gCmdHandler, hWnd, wParam, lParam);
}
// CCE11C: using guessed type struct tagMSGHANDLER CMainWnd::gCmdHandler;

//----- (00C43530) --------------------------------------------------------
int __cdecl CMainWnd::HandlePaint(HWND hWnd)
{
  HDC v1; // eax
  struct tagPAINTSTRUCT Paint; // [esp+4h] [ebp-44h]

  v1 = BeginPaint(hWnd, &Paint);
  if ( gConfig.bShowLowerPane )
    DrawEdge(v1, &gRectPane_0, 5u, 0x80Au);
  EndPaint(hWnd, &Paint);
  return 0;
}

//----- (00C43590) --------------------------------------------------------
int __cdecl CMainWnd::HandleSize(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
  int nSBHeight; // edi
  HWND hWndRebar; // eax
  LONG bottom; // ebx
  int v8; // ST14_4
  int v9; // ST10_4
  HWND v10; // eax
  struct tagRECT rcStatusBar; // [esp+Ch] [ebp-24h]
  struct tagRECT rcReBar; // [esp+1Ch] [ebp-14h]

  if ( wParam == 1 )
  {
    if ( gConfig.bHideWhenMinimized )
    {
      CMainWnd::Hide(ghMainWnd);
      return 0;
    }
  }
  else
  {
    GetWindowRect(ghWndStatusBar, &rcStatusBar);
    nSBHeight = rcStatusBar.bottom - rcStatusBar.top;
    hWndRebar = GetParent(ghWndCPUGraph);
    GetWindowRect(hWndRebar, &rcReBar);
    GetClientRect(hWnd, &gRectWindow);
    bottom = ((unsigned int)lParam >> 16) - (rcReBar.bottom - rcReBar.top + gRectWindow.top);
    gRectWindow.top += rcReBar.bottom - rcReBar.top;
    gRectWindow.right = (unsigned __int16)lParam;
    gRectWindow.bottom = bottom;
    InvalidateRect(hWnd, &gRectPane_0, 0);
    gRectPane_0.right = (unsigned __int16)lParam;
    gRectPane_0.top = (signed int)((double)(gRectWindow.top + gRectWindow.bottom - nSBHeight) * gConfig.dbDivider);
    gRectPane_0.bottom = gRectPane_0.top + 7;
    MoveWindow(ghWndTreeListView, 0, gRectWindow.top, (unsigned __int16)lParam, gRectPane_0.top - gRectWindow.top, 1);
    MoveWindow(
      ghWndHandlesListCtrl,
      0,
      gRectPane_0.bottom - 1,
      (unsigned __int16)lParam,
      gRectWindow.bottom - gRectPane_0.bottom - nSBHeight + gRectWindow.top + 1,
      TRUE);
    MoveWindow(
      ghWndDllsListCtrl,
      0,
      gRectPane_0.bottom - 1,
      (unsigned __int16)lParam,
      gRectWindow.bottom - gRectPane_0.bottom - nSBHeight + gRectWindow.top + 1,
      TRUE);
    MoveWindow(
      ghWndStatusBar,
      0,
      gRectWindow.top + gRectWindow.bottom - nSBHeight,
      (unsigned __int16)lParam,
      nSBHeight,
      1);
    v8 = gnToolbarHeight;
    v9 = gRectWindow.right;
    v10 = GetDlgItem(hWnd, IDC_MAINTOOLBAR);
    MoveWindow(v10, 0, 0, v9, v8, TRUE);
    InvalidateRgn(ghWndStatusBar, 0, FALSE);
    MoveWindow(ghWndReBar, 0, 0, gRectWindow.right - gRectWindow.left, 0, TRUE);
  }
  return 0;
}

//----- (00C43780) --------------------------------------------------------
int __cdecl CMainWnd::HandleGetMinmaxInfo(HWND a1, unsigned int a2, unsigned int a3, MINMAXINFO *a4)
{
  a4->ptMinTrackSize.x = 200;
  a4->ptMinTrackSize.y = 200;
  return 0;
}

//----- (00C437A0) --------------------------------------------------------
int __cdecl CMainWnd::HandleLBtnDown(HWND hWnd, int a2, int a3, int a4)
{
  POINT v4; // ST04_8

  v4.y = (unsigned int)a4 >> 16;
  v4.x = (unsigned __int16)a4;
  if ( PtInRect(&gRectPane_0, v4) )
  {
    SetCursor(ghResizeCursor);
    SetCapture(hWnd);
    DrawLine(hWnd, ((unsigned int)a4 >> 16) - 6);
    gyMouseDown = ((unsigned int)a4 >> 16) - 6;
  }
  return 0;
}

//----- (00C437F0) --------------------------------------------------------
int __cdecl CMainWnd::HandleLBtnUp(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
  signed int v4; // esi
  struct tagRECT Rect; // [esp+Ch] [ebp-14h]

  v4 = (unsigned int)lParam >> 16;
  if ( gbWindowFinding )
  {
    SearchWindow(hWnd);
    return 0;
  }
  if ( GetCapture() )
  {
    SetCursor(ghResizeCursor);
    ReleaseCapture();
    DrawLine(hWnd, gyMouseDown);
    if ( v4 > gRectWindow.bottom - 30 )
      return Command_ShowLowerPane(hWnd);
    if ( v4 < gRectWindow.top + 40 )
      LOWORD(v4) = LOWORD(gRectWindow.top) + 40;
    gRectPane_0.top = (unsigned __int16)v4 - 3;
    gRectPane_0.bottom = gRectPane_0.top + 7;
    gConfig.dbDivider = (double)((unsigned __int16)v4 - 3) / (double)(gRectWindow.top + gRectWindow.bottom);
    GetClientRect(ghMainWnd, &Rect);
    CMainWnd::HandleSize(
      ghMainWnd,
      0,
      0,
      (unsigned __int16)(LOWORD(Rect.right) - LOWORD(Rect.left)) | ((unsigned __int16)(LOWORD(Rect.bottom)
                                                                                     - LOWORD(Rect.top)) << 16));
    InvalidateRect(hWnd, &gRectPane_0, 0);
  }
  return 0;
}
// CDA38B: using guessed type char gbWindowFinding;

//----- (00C43940) --------------------------------------------------------
int __cdecl CMainWnd::HandleMouseMove(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
  signed int y; // esi
  HWND hWndTemp; // edi
  HWND hWndParent; // eax
  HCURSOR v7; // eax
  int result; // eax
  HCURSOR v9; // eax
  int v10; // esi
  POINT v11; // ST08_8
  struct tagPOINT Point; // [esp+8h] [ebp-8h]

  y = (unsigned int)lParam >> 16;
  if ( gbWindowFinding )
  {
    Point.x = (signed __int16)lParam;
    Point.y = SHIWORD(lParam);
    ClientToScreen(hWnd, &Point);
    hWndTemp = WindowFromPoint(Point);
    if ( hWndTemp != ghWndHungWindow )
    {
      if ( ghWndHungWindow )
        DrawHungWindow(ghWndHungWindow);
      hWndParent = hWndTemp;
      while ( hWndParent != ghMainWnd )
      {
        hWndParent = GetParent(hWndParent);
        if ( !hWndParent )
        {
          if ( ghMainWnd )
          {
            ghWndHungWindow = hWndTemp;
            DrawHungWindow(hWndTemp);
            v7 = LoadCursorW(ghInstance, (LPCWSTR)10);
            SetCursor(v7);
            return 0;
          }
          break;
        }
      }
      ghWndHungWindow = 0;
    }
    v9 = LoadCursorW(ghInstance, (LPCWSTR)0xA);
    SetCursor(v9);
    result = 0;
  }
  else if ( GetCapture() )
  {
    if ( y > gRectWindow.bottom - 5 )
      LOWORD(y) = LOWORD(gRectWindow.bottom) - 5;
    if ( (unsigned __int16)y < gRectWindow.top + 40 )
      LOWORD(y) = LOWORD(gRectWindow.top) + 40;
    DrawLine(hWnd, gyMouseDown);
    v10 = (unsigned __int16)(y - 3);
    DrawLine(hWnd, (unsigned __int16)v10);
    gyMouseDown = v10;
    result = 0;
  }
  else
  {
    v11.y = (unsigned int)lParam >> 16;
    v11.x = (unsigned __int16)lParam;
    if ( PtInRect(&gRectPane_0, v11) )
      SetCursor(ghResizeCursor);
    result = 0;
  }
  return result;
}
// CDA38B: using guessed type char gbWindowFinding;

//----- (00C43AA0) --------------------------------------------------------
BOOL __cdecl CMainWnd::HandleMeasureItem(HWND a1, unsigned int a2, unsigned int a3, LPMEASUREITEMSTRUCT lpmis)
{
  HDC hDC; // ebx
  BOOL result; // eax
  int v6; // edi
  struct tagTEXTMETRICW tm; // [esp+8h] [ebp-40h]

  if ( lpmis->CtlType == IDC_LISTCTRL_HANDLES || lpmis->CtlID == IDC_TREEVIEW_LIST )
  {
    hDC = GetDC(ghWndTreeListView);
    SelectObject(hDC, ghConfigFont);
    result = GetTextMetricsW(hDC, &tm);
    if ( !result )
      return result;
    if ( lpmis->CtlID == IDC_TREEVIEW_LIST )
    {
      v6 = tm.tmHeight + 2;
      if ( v6 <= GetSystemMetrics(SM_CYSMICON) )
        v6 = GetSystemMetrics(SM_CYSMICON);
      lpmis->itemHeight = v6;
    }
    else
    {
      lpmis->itemHeight = tm.tmHeight + 2;
    }
    ReleaseDC(ghWndTreeListView, hDC);
  }
  else if ( lpmis->CtlType == ODT_MENU )
  {
    lpmis->itemWidth = 16;
    lpmis->itemHeight = 16;
  }
  return 1;
}

//----- (00C43B70) --------------------------------------------------------
int __cdecl CMainWnd::HandleNotify(HWND hWnd, UINT msg, WPARAM wParam, LPNMTOOLBARW lParam)
{
  UINT code; // eax
  int v5; // eax
  struct tagPOINT Point; // [esp+4h] [ebp-1Ch]
  struct tagRECT Rect; // [esp+Ch] [ebp-14h]

  code = lParam->hdr.code;
  if ( code > 0xFFFFFF4F )
  {
    switch ( code )
    {
      case 0xFFFFFF51:
        return 1;
      case 0xFFFFFF65:
        return CMainWnd::HandleLVMKeydown(wParam, (LPNMLVKEYDOWN)lParam);
      case 0xFFFFFF94:
        return CMainWnd::HandleLVNColumnClick(wParam, (LPNMLVKEYDOWN)lParam);
      case 0xFFFFFF99:
        return CMainWnd::HandleLVNDeleteItem(wParam, (LPNMLISTVIEW)lParam);
      case 0xFFFFFF9B:
        return CMainWnd::HandleLVNItemChanged((HMENU)wParam);
      case 0xFFFFFFEA:
        if ( wParam == IDC_MAINTOOLBAR )
          AutoSetToolbarButtonSize();           // NM_THEMECHANGED
        return 0;
      case 0xFFFFFFFB:
        GetCursorPos(&Point);
        return CMainWnd::UpdateListViewContextMenu(wParam, (HWND)lParam, &Point);
      case 0xFFFFFFFD:
        return CMainWnd::HandleNmDblClk(wParam);
      case 0xFFFFFFFE:
        return CMainWnd::HandleNmClick(wParam, (LPNMITEMACTIVATE)lParam);
      default:
        return 0;
    }
  }
  else
  {
    if ( code == 0xFFFFFF4F )
      return CMainWnd::HandleLVNGetDispInfoW(wParam, (int)lParam);
    if ( code > 0xFFFFFCC1 )
    {
      switch ( code )
      {
        case 0xFFFFFD43:
          if ( lParam->iItem == IDM_FIND_PROCESS_BY_WINDOW )
          {
            SearchWindow(hWnd);
            return 0;
          }
          break;
        case 0xFFFFFDEE:
          return CMainWnd::HandleTTNGetDispInfo(wParam, lParam);
        case 0xFFFFFF4D:
          return CMainWnd::HandleLVNOdFindItemW(wParam);
      }
    }
    else
    {
      if ( code == 0xFFFFFCC1 )
      {
        // RBN_HEIGHTCHANGE
        GetClientRect(ghMainWnd, &Rect);
        CMainWnd::HandleSize(
          ghMainWnd,
          0,
          0,
          (unsigned __int16)(LOWORD(Rect.right) - LOWORD(Rect.left)) | ((unsigned __int16)(LOWORD(Rect.bottom)
                                                                                         - LOWORD(Rect.top)) << 16));
        InvalidateRect(ghWndTreeListView, 0, 0);
        return 0;
      }
      if ( code > 0x7D4 )
      {
        if ( code == 0x7D5 )
          return CMainWnd::HandleTVSN7D5(wParam, (int)lParam);
        if ( code == 0xFFFFFCB9 )
        {
          // RBN_CHILDSIZE
          InvalidateRect(lParam->hdr.hwndFrom, 0, 0);
          return 0;
        }
      }
      else
      {
        if ( code == 0x7D4 )
          return CMainWnd::HandleTVSN7D4(wParam, &lParam->hdr.hwndFrom);
        v5 = code - 0x7D1;
        if ( !v5 )
          return CMainWnd::HandleTVSN7D1();
        if ( v5 == 1 )
          return CMainWnd::HandleTVSN7D2();
      }
    }
  }
  return 0;
}

//----- (00C43F40) --------------------------------------------------------
int __cdecl CMainWnd::HandleCreate(HWND hWnd)
{
  HMODULE v1; // eax
  bool v2; // al
  HMENU hMainMenuHandle; // edi
  HCURSOR v4; // eax
  HGDIOBJ v5; // eax
  int dwMenuItemPosLast; // ST20_4
  HMENU hMainMenu; // eax
  HMENU hSubMenuView_1; // eax
  HMENU v9; // eax
  signed int i; // esi
  int nIdIndex; // eax
  int v12; // ST1C_4
  HMENU hMainMenu_1; // eax
  HMENU hSubMenuView; // eax
  HMENU v15; // eax
  HMENU v16; // eax
  HMENU hFileSubMenu; // eax
  HMENU hSubMenuFile; // eax
  HMENU hSubMenuFile_1; // eax
  HMENU (__stdcall *GetMenu)(HWND); // esi
  HMENU hMainMenu_2; // eax
  HMENU hOpacityPopupMenuHandle; // eax
  UINT v23; // eax
  UINT v24; // eax
  MACRO_MF v25; // eax
  UINT v26; // ST28_4
  HMENU v27; // eax
  MACRO_MF v28; // eax
  UINT v29; // ST28_4
  HMENU v30; // eax
  MACRO_MF v31; // eax
  UINT v32; // ST28_4
  HMENU v33; // eax
  MACRO_MF v34; // eax
  UINT v35; // ST28_4
  HMENU v36; // eax
  UINT v37; // eax
  UINT v38; // eax
  UINT v39; // eax
  UINT v40; // eax
  UINT v41; // eax
  UINT v42; // eax
  MACRO_MF v43; // eax
  UINT v44; // ST28_4
  HMENU v45; // eax
  float v46; // xmm0_4
  double v47; // xmm0_8
  float v48; // xmm0_4
  double v49; // xmm0_8
  UINT v50; // ST28_4
  HMENU v51; // eax
  UINT v52; // ST28_4
  HMENU v53; // eax
  UINT v54; // eax
  DWORD dwProcessId; // ST04_4
  HANDLE hProcessHandle; // eax
  const WCHAR **psz_1; // eax
  unsigned int nLength; // kr00_4
  HMENU hProcessMenu; // eax
  int NumberOfProcessors; // eax
  int index; // esi
  CGraphData *v62; // ecx
  CGraphData *v63; // edx
  HMODULE v64; // eax
  HMODULE v65; // eax
  HMODULE v66; // eax
  HMODULE v67; // eax
  HMODULE v68; // eax
  HMODULE v69; // eax
  HMENU v70; // eax
  UINT v71; // ecx
  signed int v72; // eax
  UINT v73; // ST28_4
  HMENU v74; // eax
  void (__stdcall *RegCloseKey)(HKEY); // esi
  DWORD dwRet; // eax
  DWORD dwSize; // esi
  int dwSize_1; // ST24_4
  wchar_t *pszPath_1; // esi
  wchar_t *psz; // eax
  HWND hWnd_2; // esi
  HINSTANCE hInst; // ST1C_4
  HWND hWndTreeListView; // eax
  CTreeList *pTreeList; // eax
  CTreeList *pTreeList_1; // esi
  HCURSOR v87; // eax
  HWND v88; // eax
  HWND v89; // eax
  HWND v90; // eax
  int dwProcessColumnCount; // eax
  __int16 wProcessImageColumnWidth; // ax
  int v93; // ST18_4
  int v94; // eax
  HIMAGELIST hImgList; // eax
  CTreeList *pTreeList_2; // esi
  HICON v97; // ST28_4
  _IMAGELIST *v98; // eax
  struct _IMAGELIST *v99; // eax
  HWND v100; // esi
  HWND v101; // ecx
  HWND v102; // ecx
  signed int v103; // eax
  UINT v104; // ST28_4
  HMENU v105; // eax
  HMENU v106; // eax
  HMENU v107; // eax
  LPARAM nBmpIndex; // eax
  BOOL v109; // ST28_4
  HMENU v110; // eax
  HMENU v111; // eax
  double v112; // xmm0_8
  signed int v113; // eax
  UINT v114; // ST28_4
  HMENU v115; // eax
  signed int v116; // eax
  UINT v117; // ST28_4
  HMENU v118; // eax
  HWND v119; // ebx
  signed int v120; // eax
  UINT v121; // ST28_4
  HMENU v122; // eax
  HMENU hMenuMain; // eax
  HMENU hMenuMain_1; // eax
  HMODULE v125; // eax
  HMODULE v126; // eax
  int (__stdcall *v127)(HWND, #153 *, DWORD, DWORD); // eax
  signed int dwOpacity; // ecx
  LONG v129; // eax
  UINT uId; // ST24_4
  HMENU v131; // eax
  UINT v132; // [esp-8h] [ebp-CE4h]
  const WCHAR *v133; // [esp-4h] [ebp-CE0h]
  tagLVITEMW lvItem; // [esp+Ch] [ebp-CD0h]
  tagLVITEMW Item; // [esp+40h] [ebp-C9Ch]
  DWORD Type; // [esp+74h] [ebp-C68h]
  __int64 dwNbSegments; // [esp+78h] [ebp-C64h]
  __int64 dwMinSegments; // [esp+80h] [ebp-C5Ch]
  int pSessionInfo; // [esp+88h] [ebp-C54h]
  int nSessionCount; // [esp+8Ch] [ebp-C50h]
  HCURSOR hCursor_____; // [esp+90h] [ebp-C4Ch]
  wchar_t *pszPath; // [esp+94h] [ebp-C48h]
  HKEY hSubKey; // [esp+98h] [ebp-C44h]
  size_t cbData; // [esp+9Ch] [ebp-C40h]
  HWND hWnd_1; // [esp+A0h] [ebp-C3Ch]
  struct WSAData WSAData; // [esp+A4h] [ebp-C38h]
  tagLOGFONTW LogFont; // [esp+234h] [ebp-AA8h]
  int rcTreeList; // [esp+290h] [ebp-A4Ch]
  struct tagRECT rcToolbar; // [esp+2A0h] [ebp-A3Ch]
  wchar_t szUserName[260]; // [esp+2B0h] [ebp-A2Ch]
  wchar_t szMenuItemName[260]; // [esp+4B8h] [ebp-824h]
  __int16 szDomainName[260]; // [esp+6C0h] [ebp-61Ch]
  WCHAR szMainName[260]; // [esp+8C8h] [ebp-414h]
  WCHAR szPathName[260]; // [esp+AD0h] [ebp-20Ch]
  int savedregs; // [esp+CDCh] [ebp+0h]

  hWnd_1 = hWnd;
  _mm_storeu_si128((__m128i *)&rcToolbar, (__m128i)0i64);
  lvItem.mask = 0;
  memset(&lvItem.iItem, 0, 0x30u);
  CoInitialize(0);
  WSAStartup(0x101u, &WSAData);
  GetLocaleInfoW(0x400u, 0xEu, &gszLocaleInfo, 16);
  InitializeCriticalSection(&gSysInfoPropSheetLock);
  InitializeCriticalSection(&gLock2);
  InitializeCriticalSection(&gLock3);
  InitializeCriticalSection(&gPE_ImageItemVerifiedLock);
  LoadHiddenProcessesFromRegistry();
  LoadProcessCommentsFromRegistry();
  v1 = LoadLibraryW(L"Advapi32.dll");
  gpfnCreateRestrictedToken = (int (__stdcall *)(void *, unsigned int, unsigned int, struct _SID_AND_ATTRIBUTES *, unsigned int, struct _LUID_AND_ATTRIBUTES *, unsigned int, struct _SID_AND_ATTRIBUTES *, void **))GetProcAddress(v1, "CreateRestrictedToken");
  gbWintrustInited = LoadWintrust();
  v2 = GetProcessDEPStatus();
  ghMainWnd = hWnd;
  gbIsProcessDEPEnabled = v2;
  hMainMenuHandle = ::GetMenu(hWnd);
  v4 = LoadCursorW(0, (LPCWSTR)IDC_WAIT);
  hCursor_____ = SetCursor(v4);
  ghArrowCursor = LoadCursorW(0, (LPCWSTR)IDC_ARROW);
  ghFindCursor = LoadCursorW(ghInstance, (LPCWSTR)10);
  EnableMenuItem(hMainMenuHandle, IDM_VIEW_SHOW_HIDDEN_PROCESSES, *gpHiddenProcesses == 0);
  v5 = GetStockObject(DEFAULT_GUI_FONT);
  GetObjectW(v5, sizeof(LOGFONTW), &LogFont);
  LogFont.lfUnderline = 1;
  ghDefaultUnderlineFontHandle = CreateFontIndirectW(&LogFont);
  gdwComdlg_FindReplaceMessageID = RegisterWindowMessageW(L"commdlg_FindReplace");
  DeleteMenu(hMainMenuHandle, IDM_VIEW_LOADCOLUMNSET_TEST, 0);
  dwMenuItemPosLast = gdwMenuItemPosLast;
  hMainMenu = ::GetMenu(ghMainWnd);
  hSubMenuView_1 = GetSubMenu(hMainMenu, 2);
  v9 = GetSubMenu(hSubMenuView_1, dwMenuItemPosLast);
  DeleteMenu(v9, 0, MF_BYPOSITION);
  for ( i = 0; i < (signed int)gConfig.dwNumColumnsets; ++i )
  {
    if ( i >= 10 )
    {
      wcscpy_s(szMenuItemName, MAX_PATH, gConfig.strMenuCulumnSet[i].ColumnSetName);
    }
    else
    {
      if ( i == 9 )
        nIdIndex = 0;
      else
        nIdIndex = i + 1;
      swprintf(szMenuItemName, L"%s\tCtrl+%i", &gConfig.strMenuCulumnSet[i], nIdIndex);
    }
    v12 = gdwMenuItemPosLast;
    hMainMenu_1 = ::GetMenu(ghMainWnd);
    hSubMenuView = GetSubMenu(hMainMenu_1, 2);
    v15 = GetSubMenu(hSubMenuView, v12);
    AppendMenuW(v15, 0, i + IDM_PROCESS_PRIORITY_BASE, szMenuItemName);
  }
  ghPriorityPopMenuHandle = LoadMenuW(ghInstance, L"PRIORITY");
  if ( gpfnCreateRestrictedToken )
  {
    v16 = GetSubMenu(hMainMenuHandle, 0);
    InsertMenuW(v16, 1u, MF_BYPOSITION, IDM_RUN_AS_LIMITED_USER, L"Run as &Limited User...");
    ++gdwMenuItemCountAppendedInRuntime;
  }
  if ( gdwVersion < 1 )
  {
    v133 = L"R&unas...";
    goto LABEL_15;
  }
  if ( !IsBuiltinAdministrative() )
  {
    v133 = L"R&un as Administrator...";
LABEL_15:
    hFileSubMenu = GetSubMenu(hMainMenuHandle, 0);
    InsertMenuW(hFileSubMenu, 1u, MF_BYPOSITION, IDM_RUN_AS, v133);
    ++gdwMenuItemCountAppendedInRuntime;
  }
  InsertMenuW(hMainMenuHandle, IDM_PRIORITY_NORMAL, 0, IDM_PROCESS_SETPRIORITY_ABOVE_NORMAL_TEN, L"&Above Normal: 10");
  InsertMenuW(
    ghPriorityPopMenuHandle,
    IDM_PROCESS_SETPRIORITY_NORMAL,
    0,
    IDM_PROCESS_SETPRIORITY_ABOVE_NORMAL_TEN,
    L"&Above Normal: 10");
  InsertMenuW(
    hMainMenuHandle,
    IDM_PROCESS_SETPRIORITY_IDLE,
    0,
    IDM_PROCESS_SETPRIORITY_BELOW_NORMAL_SIX,
    L"&Below Normal: 6");
  InsertMenuW(
    ghPriorityPopMenuHandle,
    IDM_PROCESS_SETPRIORITY_IDLE,
    0,
    IDM_PROCESS_SETPRIORITY_BELOW_NORMAL_SIX,
    L"&Below Normal: 6");
  if ( gdwVersion < WINDOWS_VISTA
    || (InsertMenuW(
          hMainMenuHandle,
          IDM_PRIORITY_IDLE,
          0,
          IDM_PROCESS_SETPRIORITY_BACKGROUND_FOUR,
          L"Back&ground: 4 (Low I/O and Memory Priority)"),
        InsertMenuW(
          ghPriorityPopMenuHandle,
          IDM_PRIORITY_IDLE,
          0,
          IDM_PROCESS_SETPRIORITY_BACKGROUND_FOUR,
          L"Back&ground: 4 (Low I/O and Memory Priority)"),
        gdwVersion < WINDOWS_VISTA)
    || IsBuiltinAdministrative() )
  {
    if ( ChangeWindowMessageFilter )
      ChangeWindowMessageFilter(WM_MSG_7F2, 1);
    GetMenu = ::GetMenu;
  }
  else
  {
    hSubMenuFile = GetSubMenu(hMainMenuHandle, 0);
    InsertMenuW(hSubMenuFile, 3u, 0xC00u, 0, 0);// 0xC00 = MF_BYPOSITION|MF_SEPARATOR
    ++gdwMenuItemCountAppendedInRuntime;
    hSubMenuFile_1 = GetSubMenu(hMainMenuHandle, 0);
    InsertMenuW(
      hSubMenuFile_1,
      4u,
      MF_BYPOSITION,
      IDM_SHOW_DETAILS_FOR_ALL_PROCESSES,
      L"Show &Details for All Processes");
    GetMenu = ::GetMenu;
    hMainMenu_2 = ::GetMenu(hWnd_1);
    ReplaceMenuIconFromStockIcon(hMainMenu_2, IDM_SHOW_DETAILS_FOR_ALL_PROCESSES);
    ++gdwMenuItemCountAppendedInRuntime;
  }
  hOpacityPopupMenuHandle = LoadMenuW(ghInstance, L"OPACITY");
  InsertMenuW(hMainMenuHandle, IDM_VIEW_SHOW_LOWER_PANE, MF_POPUP, (UINT_PTR)hOpacityPopupMenuHandle, L"Opacity");
  InsertMenuW(hMainMenuHandle, IDM_VIEW_SHOW_LOWER_PANE, MF_SEPARATOR, 0, 0);
  v23 = 0;
  if ( gConfig.bVerifySignatures )
    v23 = MF_CHECKED;
  CheckMenuItem(hMainMenuHandle, IDM_OPTIONS_VERIFY_IMAGE_SIGNATURE, v23);
  v24 = 0;
  if ( gConfig.bCheckVirusTotal )
    v24 = MF_CHECKED;
  CheckMenuItem(hMainMenuHandle, IDM_OPTIONS_CHECK_VIRTULTOALDOTCOM, v24);
  EnableMenuItem(hMainMenuHandle, IDM_OPTIONS_SUBMIT_UNKNOWN_EXECUTABLES, gConfig.bCheckVirusTotal == 0);
  if ( gConfig.bCheckVirusTotal )
    SubmitExeToVirusTotalDotCom();
  v25 = 0;
  if ( gConfig.bTrayCPUHistory )
    v25 = MF_CHECKED;
  v26 = v25;
  v27 = GetMenu(hWnd_1);
  CheckMenuItem(v27, IDM_OPTIONS_TRAYICON_CPU_HISTORY, v26);
  v28 = 0;
  if ( gConfig.bShowIoTray )
    v28 = MF_CHECKED;
  v29 = v28;
  v30 = GetMenu(hWnd_1);
  CheckMenuItem(v30, IDM_OPTIONS_TRAYICON_IO_HISTORY, v29);
  v31 = 0;
  if ( gConfig.bShowCommitTray )
    v31 = MF_CHECKED;
  v32 = v31;
  v33 = GetMenu(hWnd_1);
  CheckMenuItem(v33, IDM_OPTIONS_TRAYICON_COMMIT_HISTORY, v32);
  v34 = 0;
  if ( gConfig.bShowPhysTray )
    v34 = MF_CHECKED;
  v35 = v34;
  v36 = GetMenu(hWnd_1);
  CheckMenuItem(v36, IDM_OPTIONS_TRAYICON_PHYSICAL_MEMORY_HISTORY, v35);
  v37 = 0;
  if ( gConfig.bAllOneInstance )
    v37 = MF_CHECKED;
  CheckMenuItem(hMainMenuHandle, IDM_OPTIONS_ALLOW_ONLY_ONE_INSTANCE, v37);
  v38 = 0;
  if ( gConfig.bHideWhenMinimized )
    v38 = MF_CHECKED;
  CheckMenuItem(hMainMenuHandle, IDM_OPTIONS_HIDE_WHEN_MINIMIZED, v38);
  v39 = 0;
  if ( gConfig.bShowColumnHeatmaps )
    v39 = MF_CHECKED;
  CheckMenuItem(hMainMenuHandle, IDM_VIEW_SHOW_COLUMN_HEATMAPS, v39);
  gConfig.bAlwaysOntop = gConfig.bAlwaysOntop == 0;
  Command_SetTopmost(ghMainWnd);
  v40 = 0;
  if ( gConfig.bShowCpuFractions )
    v40 = MF_CHECKED;
  CheckMenuItem(hMainMenuHandle, IDM_PROCESS_CONFIRM_TO_KILL, v40);
  v41 = 0;
  if ( gConfig.bConfirmKill )
    v41 = MF_CHECKED;
  CheckMenuItem(hMainMenuHandle, IDM_OPTIONS_CONFIRM_KILL, v41);
  v42 = 0;
  if ( gConfig.bFormatIoBytes )
    v42 = MF_CHECKED;
  CheckMenuItem(hMainMenuHandle, IDM_SHOW_NEW_PROCESS, v42);
  v43 = 0;
  if ( gConfig.bShowNewProcesses )
    v43 = MF_CHECKED;
  v44 = v43;
  v45 = GetMenu(hWnd_1);
  CheckMenuItem(v45, IDM_VIEW_SCROLL_TO_NEW_PROCESSES, v44);
  InsertMenuW(
    hMainMenuHandle,
    IDM_VIEW_SHOW_PROCESS_TREE,
    0,
    IDM_TRAYMENU_CONTEXT_SYSTEM_INFORMATION,
    L"System &Information...\tCtrl+I");
  if ( (unsigned __int8)Init3DStatistics((unsigned __int64 *)&dwMinSegments, (unsigned __int64 *)&dwNbSegments) )
  {
    gpGraphInfoOfGPU = InitGraphData(1, 1, 1);
    gpGraphInfoOfGPU->m_nItemID = GRAPHID_IO;
    gpGraphInfoOfGPU->m_Color = 0x8080FF;
    gpGraphInfoOfGPU->m_dbMemorySize = db_onehundred;
    gpGraphInfoOfSystemMemory = InitGraphData(1, 1, 0);
    gpGraphInfoOfSystemMemory->m_nItemID = GRAPHID_Network;
    gpGraphInfoOfSystemMemory->m_Color = 0xAAAA;
    if ( dwMinSegments )
    {
      v46 = (double)dwMinSegments;
      v47 = v46;
    }
    else
    {
      v47 = db_one;
    }
    gpGraphInfoOfSystemMemory->m_dbMemorySize = v47;
    gpGraphInfoOfDedicatedMemory = InitGraphData(1, 1, 0);
    gpGraphInfoOfDedicatedMemory->m_nItemID = GRAPHID_Disk;
    gpGraphInfoOfDedicatedMemory->m_Color = 0x4080FF;
    if ( dwNbSegments )
    {
      v48 = (double)dwNbSegments;
      v49 = v48;
    }
    else
    {
      v49 = db_one;
    }
    gpGraphInfoOfDedicatedMemory->m_dbMemorySize = v49;
  }
  InsertMenuW(hMainMenuHandle, IDM_VIEW_SHOW_PROCESS_TREE, MF_SEPARATOR, 0, 0);
  InsertMenuW(
    hMainMenuHandle,
    IDM_OPTIONS_HIDE_WHEN_MINIMIZED,
    0,
    IDM_OPTIONS_REPLACE_TASK_MANAGER,
    L"Replace &Task Manager");
  v50 = CanReplaceTaskManager() != 0 ? (unsigned int)MF_CHECKED : 0;
  v51 = GetMenu(hWnd_1);
  CheckMenuItem(v51, IDM_OPTIONS_REPLACE_TASK_MANAGER, v50);
  if ( gdwVersion >= 1 && !IsBuiltinAdministrative() )
    ReplaceMenuIconFromStockIcon(hMainMenuHandle, IDM_OPTIONS_REPLACE_TASK_MANAGER);
  if ( CanReplaceTaskManager() )
    ReplaceTaskManager(hWnd_1, 0);
  v52 = IsProcessExplorerRunAtStartup((int)&savedregs, hMainMenuHandle) != 0 ? (unsigned int)MF_CHECKED : 0;
  v53 = GetMenu(hWnd_1);
  CheckMenuItem(v53, IDM_OPTIONS_RUN_AT_LOGON, v52);
  v54 = 0;
  if ( gConfig.bShowAllUsers )
    v54 = MF_CHECKED;
  CheckMenuItem(hMainMenuHandle, IDM_VIEW_SHOW_PROCESSES_FROM_ALL_USERS, v54);
  InsertMenuW(
    hMainMenuHandle,
    IDM_OPTIONS_DIFFERENCE_HIGHLIGHT_DURATION,
    0,
    IDM_VIEW_CONFIGURE_SYMBOLS,
    L"Configure &Symbols...");
  DeleteMenu(hMainMenuHandle, IDM_OPTIONS_HIGHLIGHT_RELOCATED_DLLS, 0);
  InsertMenuW(
    hMainMenuHandle,
    IDM_OPTIONS_DIFFERENCE_HIGHLIGHT_DURATION,
    0,
    IDM_VIEW_CONFIGURE_COLORS,
    L"&Configure Colors...");
  if ( WTSEnumerateSessionsW
    && *(_DWORD *)SetMenuInfo
    && WTSEnumerateSessionsW(0, 0, 1u, (PWTS_SESSION_INFOW *)&pSessionInfo, (DWORD *)&nSessionCount)
    && nSessionCount )
  {
    Item.cchTextMax = sizeof(MENUINFO);
    Item.iImage = 0x80000010;
    Item.lParam = (tagTREEVIEWLISTITEMPARAM *)MNS_NOTIFYBYPOS;
    SetMenuInfo(hMainMenuHandle, (LPCMENUINFO)&Item.cchTextMax);
    ghUserPopupMenuHandle = CreateMenu();
    InsertMenuW(hMainMenuHandle, 5u, 0x410u, (UINT_PTR)ghUserPopupMenuHandle, L"&Users");
    WTSFreeMemory((PWTS_SESSION_INFOW)pSessionInfo);
  }
  dwProcessId = GetCurrentProcessId();
  hProcessHandle = GetCurrentProcess();
  QueryProcessUsers(hProcessHandle, dwProcessId, 0, szUserName, MAX_PATH, (WCHAR *)szDomainName, MAX_PATH, 0, 0, 0, 0);
  if ( !szDomainName[0] || (psz_1 = (const WCHAR **)L"\\", !szUserName[0]) )
    psz_1 = &gszNullString;
  swprintf(gszMainTitle, L"%s%s%s", szDomainName, psz_1, szUserName);
  GetWindowTextW(ghMainWnd, szMainName, 260);
  nLength = wcslen(szMainName);
  swprintf_s(&szMainName[nLength], 260 - nLength, L" [%s]", gszMainTitle);
  SetWindowTextW(ghMainWnd, szMainName);
  gColorCustomized[0] = gConfig.ColorOwn;
  gColorCustomized[1] = gConfig.ColorService;
  gColorCustomized[2] = gConfig.ColorRelocatedDlls;
  gColorCustomized[3] = gConfig.ColorJobs;
  gColorCustomized[4] = gConfig.ColorNet;
  QueryCurrentAuthorityInfo(&gpszCurAuthInfo);
  if ( gSystemInfo.dwNumberOfProcessors > 1 )
  {
    hProcessMenu = GetSubMenu(hMainMenuHandle, 3);
    InsertMenuW(hProcessMenu, 2u, MF_BYPOSITION, IDC_PROCESS_SET_AFFINITY, L"Set &Affinity...");
    CheckMenuItem(hMainMenuHandle, (gConfig.bShowAllCpus != 0) + IDM_PROCESSOR_ONE_GRAPH_ALL_CPUS, MF_CHECKED);
    if ( *(_DWORD *)GetLogicalProcessorInformation )
    {
      cbData = 0;
      GetLogicalProcessorInformation(0, &cbData);
      if ( GetLastError() == ERROR_INSUFFICIENT_BUFFER )
      {
        gpLogicalProcessorInfo = (SYSTEM_LOGICAL_PROCESSOR_INFORMATION *)malloc(cbData);
        GetLogicalProcessorInformation(gpLogicalProcessorInfo, &cbData);
        gdwLogicalProcessorInfoItemCount = cbData / sizeof(SYSTEM_LOGICAL_PROCESSOR_INFORMATION);
      }
    }
    else
    {
      gpLogicalProcessorInfo = (SYSTEM_LOGICAL_PROCESSOR_INFORMATION *)Fake_GetLogicalProcessorInformation(&gdwLogicalProcessorInfoItemCount);
    }
    gppGraphInfo = (CGraphData **)malloc(4 * gSystemInfo.dwNumberOfProcessors);
    NumberOfProcessors = gSystemInfo.dwNumberOfProcessors;
    for ( index = 0; index < (signed int)gSystemInfo.dwNumberOfProcessors; ++index )
    {
      gppGraphInfo[index] = InitGraphData(NumberOfProcessors, 2, 0);
      gppGraphInfo[index]->m_ProcessorID = index;
      sub_C33E70(
        gpLogicalProcessorInfo,
        gdwLogicalProcessorInfoItemCount,
        index,
        &gppGraphInfo[index]->NodeCount,
        &gppGraphInfo[index]->NodeCoreMode);
      gppGraphInfo[index]->m_nChildID = 2;
      gppGraphInfo[index]->m_nItemID = 0;
      gppGraphInfo[index]->m_Color = 0x3C943C;
      gppGraphInfo[index]->m_dbMemorySize = db_onehundred;
      gppGraphInfo[index]->m_Item[0].Color = 255;
      gppGraphInfo[index]->m_Item[0].dbMemorySize = db_onehundred;
      gppGraphInfo[index]->m_GraphData = gpGraphInfoOfCPU;
      if ( index )
      {
        v62 = *gppGraphInfo;
        v63 = gppGraphInfo[index];
        v63->m_Time.dwLowDateTime = (*gppGraphInfo)->m_Time.dwLowDateTime;
        v63->m_Time.dwHighDateTime = v62->m_Time.dwHighDateTime;
      }
      NumberOfProcessors = gSystemInfo.dwNumberOfProcessors;
    }
    GetMenu = ::GetMenu;
  }
  v64 = LoadLibraryW(L"Powrprof.dll");
  *(_DWORD *)SetSuspendState = GetProcAddress(v64, "SetSuspendState");
  if ( *(_DWORD *)SetSuspendState )
  {
    v65 = LoadLibraryW(L"Powrprof.dll");
    *(_DWORD *)IsPwrHibernateAllowed = GetProcAddress(v65, "IsPwrHibernateAllowed");
    if ( IsPwrHibernateAllowed() )
      InsertMenuW(hMainMenuHandle, IDM_FILE_SHUTDOWN_RESTART, MF_BYCOMMAND, IDC_FILE_HIBERNATE, L"&Hibernate");
    v66 = LoadLibraryW(L"Powrprof.dll");
    *(_DWORD *)IsPwrSuspendAllowed = GetProcAddress(v66, "IsPwrSuspendAllowed");
    if ( IsPwrSuspendAllowed() )
      InsertMenuW(hMainMenuHandle, IDM_FILE_SHUTDOWN_RESTART, MF_BYCOMMAND, IDC_FILE_STANDBY, L"Stand &By");
  }
  v67 = LoadLibraryW(L"User32.dll");
  *(_DWORD *)LockWorkStation = GetProcAddress(v67, "LockWorkStation");
  if ( *(_DWORD *)LockWorkStation )
    InsertMenuW(hMainMenuHandle, IDM_FILE_SHUTDOWN_RESTART, MF_BYCOMMAND, IDC_THREADSTACK_BUTTON_COPY, L"Loc&k");
  v68 = LoadLibraryW(L"User32.dll");
  *(_DWORD *)GetMonitorInfoA = GetProcAddress(v68, "GetMonitorInfoA");
  v69 = LoadLibraryW(L"User32.dll");
  *(_DWORD *)MonitorFromPoint = GetProcAddress(v69, "MonitorFromPoint");
  v70 = LoadMenuW(ghInstance, L"DLLMENU");
  v71 = 0;
  ghDllMenuPopup = (UINT_PTR)v70;
  if ( gConfig.bHighlightRelocatedDlls )
    v71 = 8;
  CheckMenuItem(v70, IDM_OPTIONS_HIGHLIGHT_RELOCATED_DLLS, v71);
  ghHandlesMenuPopup = (UINT_PTR)LoadMenuW(ghInstance, L"HANDLEMENU");
  v72 = 0;
  if ( gConfig.bShowUnnamedHandles )
    v72 = 8;
  v73 = v72;
  v74 = GetMenu(hWnd_1);
  CheckMenuItem(v74, IDM_VIEW_SHOW_UNNAMED_HANDLES_AND_MAPPINGS, v73);
  RegCloseKey = (void (__stdcall *)(HKEY))::RegCloseKey;
  if ( RegOpenKeyW(HKEY_CLASSES_ROOT, L"exefile\\shell\\View Dependencies", &hSubKey) )
  {
    gstrApplicationName = 0;
    dwRet = GetEnvironmentVariableW(L"PATH", 0, 0);
    dwSize = dwRet;
    if ( dwRet )
    {
      pszPath = (wchar_t *)malloc(2 * dwRet + 2);
      GetEnvironmentVariableW(L"PATH", pszPath, dwSize);
      dwSize_1 = dwSize;
      pszPath_1 = pszPath;
      if ( MakeApplicationName(L"depends.exe", pszPath, dwSize_1, (wchar_t *)&gstrApplicationName) )
      {
        InsertMenuW(hMainMenuHandle, IDM_PROCESS_TEMP, MF_BYCOMMAND, IDM_PROCESS_LAUNCH_DEPENDS, L"&Launch Depends...");
        InsertMenuW(
          (HMENU)ghDllMenuPopup,
          IDM_DLLMENU_BASE_ITEM,
          MF_BYCOMMAND,
          IDM_DLLMENU_LAUNCH_DEPENDS,
          L"&Launch Depends...");
        gbLaunchDepends = 1;
      }
      else
      {
        gstrApplicationName = 0;
      }
      free(pszPath_1);
    }
    RegCloseKey = (void (__stdcall *)(HKEY))::RegCloseKey;
  }
  else
  {
    gbLaunchDepends = 1;
    InsertMenuW(hMainMenuHandle, IDM_PROCESS_TEMP, MF_BYCOMMAND, IDM_PROCESS_LAUNCH_DEPENDS, L"&Launch Depends...");
    InsertMenuW(
      (HMENU)ghDllMenuPopup,
      IDM_DLLMENU_BASE_ITEM,
      MF_BYCOMMAND,
      IDM_DLLMENU_LAUNCH_DEPENDS,
      L"&Launch Depends...");
    gstrApplicationName = 0;
    ::RegCloseKey(hSubKey);
  }
  if ( !RegOpenKeyW(HKEY_LOCAL_MACHINE, L"Software\\Microsoft\\Windows NT\\CurrentVersion\\AeDebug", &hSubKey) )
  {
    cbData = 520;
    if ( !RegQueryValueExW(hSubKey, L"Debugger", 0, &Type, (LPBYTE)szPathName, &cbData) )
    {
      _wcslwr_s(gszAeDebuggerPath, MAX_PATH);
      if ( szPathName[0] == '"' )
      {
        wcscpy_s(gszAeDebuggerPath, MAX_PATH, &szPathName[1]);
        if ( wcschr(gszAeDebuggerPath, '"') )
        {
          psz = wcschr(gszAeDebuggerPath, '"');
LABEL_110:
          *psz = 0;
          goto LABEL_111;
        }
      }
      else
      {
        wcscpy_s(gszAeDebuggerPath, MAX_PATH, szPathName);
        if ( wcschr(gszAeDebuggerPath, ' ') )
        {
          psz = wcschr(gszAeDebuggerPath, ' ');
          goto LABEL_110;
        }
      }
    }
LABEL_111:
    RegCloseKey(hSubKey);
  }
  if ( gszAeDebuggerPath[0] )
    InsertMenuW(hMainMenuHandle, IDM_PROCESS_TEMP, MF_BYCOMMAND, IDM_PROCESS_DEBUG, L"&Debug");
  DeleteMenu(hMainMenuHandle, IDM_PROCESS_TEMP, MF_BYCOMMAND);
  hWnd_2 = hWnd_1;
  ghWndToolbar = CMainWnd::InitToolbar(hWnd_1, IDC_MAINTOOLBAR);
  if ( !ghWndToolbar )
    return -1;
  UpdateMenuStatus(0, 3);
  GetWindowRect(ghWndToolbar, &rcToolbar);
  gnToolbarHeight = rcToolbar.bottom - rcToolbar.top + 2;
  hInst = ghInstance;
  _mm_storeu_si128((__m128i *)&rcTreeList, (__m128i)0i64);
  hWndTreeListView = CTreeList::Init(hWnd_2, hInst, (HMENU)IDC_TREEVIEW_LIST, 0x40810200, (#153 *)&rcTreeList);
  ghWndTreeListView = hWndTreeListView;
  if ( !hWndTreeListView )
    return -1;
  CTreeList::InitListCtrl(hWndTreeListView, (WPARAM)ghConfigFont);
  pTreeList = CTreeList::GetTreeList(ghWndTreeListView);
  pTreeList_1 = pTreeList;
  pszPath = (wchar_t *)pTreeList;
  pTreeList->m_pfnDrawBack = (int)CMainWnd::Draw;
  CTreeList::UpdateSB(pTreeList, 0);
  pTreeList_1->m_pfnGetChildCursor = (int)CMainWnd::GetDynamicCursor;
  v87 = LoadCursorW(ghInstance, (LPCWSTR)0x6A);
  CTreeList::SetSplitterCursor(pTreeList_1, v87);
  sub_C0BDA0(pTreeList_1, 1);
  sub_C0F210(pTreeList_1, 0);
  sub_C0F230(pTreeList_1, 0);
  v88 = CTreeList::GetTooltipOfTreeList(pTreeList_1);
  CTreeList::InitToolTips(v88);
  v89 = CTreeList::GetTooltipOfLeftHeader(pTreeList_1);
  CTreeList::InitToolTips(v89);
  v90 = CTreeList::GetTooltipOfRightHeader(pTreeList_1);
  CTreeList::InitToolTips(v90);
  dwProcessColumnCount = gConfig.dwProcessColumnCount;
  if ( gConfig.dwProcessColumnMap[0] != IDS_PROCESS )
  {
    memmove(&gConfig.dwProcessColumnMap[1], gConfig.dwProcessColumnMap, 4 * gConfig.dwProcessColumnCount);
    gConfig.dwProcessColumnMap[0] = IDS_PROCESS;
    memmove(&gConfig.dwProcessColumns[1], gConfig.dwProcessColumns, 2 * gConfig.dwProcessColumnCount);
    wProcessImageColumnWidth = gConfig.wProcessImageColumnWidth;
    if ( !gConfig.wProcessImageColumnWidth )
      wProcessImageColumnWidth = 200;
    gConfig.dwProcessColumns[0] = wProcessImageColumnWidth;
    dwProcessColumnCount = gConfig.dwProcessColumnCount++ + 1;
  }
  if ( !InitListHeader(
          ghWndTreeListView,
          (UINT *)gConfig.dwProcessColumnMap,
          (WORD *)gConfig.dwProcessColumns,
          dwProcessColumnCount) )
    return -1;
  v93 = GetSystemMetrics(SM_CYSMICON);
  v94 = GetSystemMetrics(SM_CXSMICON);
  hImgList = ImageList_Create(v94, v93, 0x21u, 256, 256);
  pTreeList_2 = (CTreeList *)pszPath;
  CTreeList::ResetImageList((CTreeList *)pszPath, (int)hImgList, 0);
  v97 = LoadIconW(0, (LPCWSTR)IDC_ARROW);
  v98 = CTreeList::GetImageList(pTreeList_2);
  ImageList_ReplaceIcon(v98, -1, v97);
  v99 = InitSortableImageList();
  CTreeList::SetSortFlagsImageList(pTreeList_2, (LPARAM)v99, 1, 0);
  if ( !gConfig.bShowProcessTree )
    CTreeList::InitHeaderColumn(
      ghWndTreeListView,
      0xFFFFFFFF,
      (HWND)gConfig.dwProcessSortColumn,
      gConfig.bProcessSortDirection);
  v100 = hWnd_1;
  v101 = CreateListCtrl(
           hWnd_1,
           0x40810605u,
           (int)gConfig.dwIdsOfHandleColumnMap,
           (int)gConfig.dwHandleColumns,
           gConfig.dwHandleColumnCount,
           (HMENU)IDC_LISTCTRL_HANDLES);
  ghWndHandlesListCtrl = v101;
  if ( !v101 )
    return -1;
  CTreeList::InitHeaderColumn(v101, 0xFFFFFFFF, (HWND)gConfig.dwHandleSortColumn, gConfig.bHandleSortDirection);
  v102 = CreateListCtrl(
           v100,
           0x40810605u,
           (int)gConfig.dwDllColumnMap,
           (int)gConfig.dwDllColumns,
           gConfig.dwDllColumnCount,
           (HMENU)IDC_LISTCTRL_DLLS);
  ghWndDllsListCtrl = v102;
  if ( !v102 )
    return -1;
  CTreeList::InitHeaderColumn(v102, 0xFFFFFFFF, (HWND)gConfig.dwDllSortColumn, gConfig.bDllSortDirection);
  ghWndStatusBar = CreateStatusWindowW(0x50000000, (LPCWSTR)&gszNullString, v100, 0x6Au);
  CMainWnd::InitStatusBar(ghWndStatusBar);
  ghResizeCursor = LoadCursorW(ghInstance, (LPCWSTR)0x69);
  if ( !ghResizeCursor )
    ghResizeCursor = LoadCursorW(0, (LPCWSTR)0x7F00);
  ghSplitterCursor = (int)LoadCursorW(ghInstance, (LPCWSTR)0x6A);
  if ( !ghSplitterCursor )
    ghSplitterCursor = (int)LoadCursorW(0, (LPCWSTR)0x7F00);
  v103 = 0;
  if ( gConfig.bHighlightRelocatedDlls )
    v103 = 8;
  v104 = v103;
  v105 = ::GetMenu(v100);
  CheckMenuItem(v105, IDM_OPTIONS_HIGHLIGHT_RELOCATED_DLLS, v104);
  ShowWindow(ghWndTreeListView, SW_SHOW);
  if ( gConfig.bShowLowerPane )
  {
    if ( gConfig.bShowDllView )
    {
      v106 = ::GetMenu(hWnd_1);
      CheckMenuItem(v106, IDM_VIEW_LOWERPANEVIEW_DLLS, MF_CHECKED);
      ShowWindow(ghWndDllsListCtrl, SW_SHOW);
    }
    else
    {
      v107 = ::GetMenu(hWnd_1);
      CheckMenuItem(v107, IDM_VIEW_LOWERPANEVIEW_HANDLES, MF_CHECKED);
      ShowWindow(ghWndHandlesListCtrl, SW_SHOW);
    }
  }
  nBmpIndex = 1;
  if ( gConfig.bShowDllView )
    nBmpIndex = 4;
  SendMessageW(ghWndToolbar, TB_CHANGEBITMAP, IDM_POPUP_DLL_PROPERTIES, nBmpIndex);
  SendMessageW(ghWndToolbar, TB_ENABLEBUTTON, IDM_VIEW_SHOW_PROCESS_TREE, gConfig.bShowProcessTree == 0);
  v109 = gConfig.bShowProcessTree != 0;
  v110 = ::GetMenu(ghMainWnd);
  EnableMenuItem(v110, IDM_VIEW_SHOW_PROCESS_TREE, v109);
  v111 = ::GetMenu(ghMainWnd);
  EnableMenuItem(v111, IDM_PROCESS_KILL_PROCESS_TREE, MF_GRAYED);
  ghSystemInfoSheetThreadEvent = CreateEventW(0, 0, 0, 0);
  GetClientRect(hWnd_1, &gRectWindow);
  gRectPane_0.left = 0;
  gRectWindow.top = gRectWindow.top - 1 + gnToolbarHeight;
  gRectWindow.bottom -= gRectWindow.top;
  gRectPane_0.top = gRectWindow.top + (signed int)((double)(gRectWindow.bottom - gRectWindow.top) * gConfig.dbDivider);
  gRectPane_0.bottom = gRectPane_0.top + 7;
  gRectPane_0.right = gRectWindow.right;
  if ( gConfig.bShowLowerPane )
    v112 = gConfig.dbSavedDivider;
  else
    v112 = db_one;
  gConfig.dbDivider = v112;
  gConfig.bShowLowerPane = gConfig.bShowLowerPane == 0;
  Command_ShowLowerPane(0);
  gShellIconMsg = RegisterWindowMessageW(L"TaskbarCreated");
  StartBackendThread();
  CTreeList::InitTreeList(ghWndTreeListView, 1);
  SendMessageW(ghMainWnd, WM_TREEVIEW_SORT, IDC_TREEVIEW_LIST, (unsigned __int8)gConfig.bShowProcessTree);
  SetFocus(ghWndTreeListView);
  lvItem.iItem = SendMessageW(ghWndTreeListView, LVM_GETNEXTITEM, 0xFFFFFFFF, LVFI_STRING);
  lvItem.iSubItem = 0;
  lvItem.mask = 4;
  SendMessageW(ghWndTreeListView, LVM_GETITEMW, 0, (LPARAM)&lvItem);
  RefreshVirusTotalMenuItem(lvItem.lParam);
  Item.stateMask = 3;
  Item.state = 3;
  SendMessageW(ghWndDllsListCtrl, LVM_SETITEMSTATE, 0, (LPARAM)&Item);
  Item.stateMask = 3;
  Item.state = 3;
  SendMessageW(ghWndHandlesListCtrl, LVM_SETITEMSTATE, 0, (LPARAM)&Item);
  if ( IsBuiltinAdministrative() && !PE_RunTrace(&gProperties, 1) )
  {
    InsertMenuW(
      hMainMenuHandle,
      IDM_OPTIONS_TRAYICON_COMMIT_HISTORY,
      MF_BYCOMMAND,
      IDM_OPTIONS_COMMIT_DISK_HISTORY,
      L"&Disk History");
    v113 = 0;
    if ( gConfig.bShowDiskTray )
      v113 = 8;
    v114 = v113;
    v115 = ::GetMenu(hWnd_1);
    CheckMenuItem(v115, IDM_OPTIONS_COMMIT_DISK_HISTORY, v114);
    InsertMenuW(hMainMenuHandle, 40726u, MF_BYCOMMAND, IDM_OPTIONS_COMMIT_NETWORK_HISTORY, L"&Network History");
    v116 = 0;
    if ( gConfig.bShowNetTray )
      v116 = 8;
    v117 = v116;
    v118 = ::GetMenu(hWnd_1);
    CheckMenuItem(v118, IDM_OPTIONS_COMMIT_NETWORK_HISTORY, v117);
  }
  if ( gdwAdapterRuntingTime )
  {
    InsertMenuW(hMainMenuHandle, IDM_OPTIONS_TRAYICON_COMMIT_HISTORY, MF_BYCOMMAND, 40748u, L"&GPU History");
    v119 = hWnd_1;
    v120 = 0;
    if ( gConfig.bShowGpuHistory )
      v120 = 8;
    v121 = v120;
    v122 = ::GetMenu(hWnd_1);
    CheckMenuItem(v122, IDM_OPTIONS_COMMIT_GPU_HISTORY, v121);
  }
  else
  {
    v119 = hWnd_1;
  }
  ghRefreshEventHandle = CreateEventW(0, 0, 0, 0);
  ghEvent2 = CreateEventW(0, 0, 0, 0);
  ghEvent3 = CreateEventW(0, 1, 0, 0);
  ghTimerRefreshEvent = CreateEventW(0, 0, 0, 0);
  ghTimerRefreshProcPageEventHandle = CreateEventW(0, 1, 0, 0);
  ghEvent6 = CreateEventW(0, 0, 0, 0);
  ghBackupRefreshThreadHandle = (HANDLE)_beginthreadex(0, 0, (int)CMainWnd::BackendRefreshThreadProc, 0, 0, 0);
  if ( (signed int)gConfig.dwRefreshRate > 2000 )
  {
    if ( gConfig.dwRefreshRate == 5000 )
    {
      v132 = IDM_VIEW_UPDATESPEED_FIVE_SECONDS;
      goto __RefreshMenuItem;
    }
    if ( gConfig.dwRefreshRate == 10000 )
    {
      v132 = IDM_VIEW_UPDATESPEED_TEN_SECONDS;
      goto __RefreshMenuItem;
    }
  }
  else
  {
    if ( gConfig.dwRefreshRate == 2000 )
    {
      v132 = IDM_VIEW_UPDATESPEED_TWO_SECONDS;
      goto __RefreshMenuItem;
    }
    if ( gConfig.dwRefreshRate )
    {
      if ( gConfig.dwRefreshRate == 500 )
      {
        v132 = IDM_VIEW_UPDATESPEED_HALF_SECONDS;
        goto __RefreshMenuItem;
      }
      if ( gConfig.dwRefreshRate == 1000 )
      {
        v132 = IDM_VIEW_UPDATESPEED_ONE_SECOND;
__RefreshMenuItem:
        hMenuMain_1 = ::GetMenu(ghMainWnd);
        CheckMenuRadioItem(hMenuMain_1, IDM_VIEW_UPDATESPEED_PAUSED_SPACE, IDM_VIEW_UPDATESPEED_HALF_SECONDS, v132, 0);
        goto LABEL_167;
      }
    }
    else
    {
      hMenuMain = ::GetMenu(ghMainWnd);
      CheckMenuRadioItem(
        hMenuMain,
        IDM_VIEW_UPDATESPEED_PAUSED_SPACE,
        IDM_VIEW_UPDATESPEED_HALF_SECONDS,
        IDM_VIEW_UPDATESPEED_PAUSED_SPACE,
        0);
      SendMessageW(ghWndStatusBar, SB_SETTEXTW, gnStatusBarItemCount - 1, (LPARAM)L"Paused");
    }
  }
LABEL_167:
  InvalidateRect(ghWndToolbar, 0, 1);
  SetCursor(hCursor_____);
  if ( !gIOGraphInfo.pGraphData )
    DeleteMenu(hMainMenuHandle, IDM_OPTIONS_TRAYICON_IO_HISTORY, 0);
  HandleTaskbarCreated();
  v125 = GetModuleHandleW(L"Shlwapi.dll");
  gpfnSHAutoComplete = (int (__stdcall *)(struct HWND__ *, unsigned int))GetProcAddress(v125, "SHAutoComplete");
  v126 = LoadLibraryW(L"user32.dll");
  v127 = (int (__stdcall *)(HWND, #153 *, DWORD, DWORD))GetProcAddress(v126, "SetLayeredWindowAttributes");
  dwOpacity = gConfig.dwOpacity;
  SetLayeredWindowAttributes = v127;
  if ( gConfig.dwOpacity != 100 )
  {
    v129 = GetWindowLongW(ghMainWnd, GWL_EXSTYLE);
    SetWindowLongW(ghMainWnd, -20, v129 | WS_EX_LAYERED);
    SetLayeredWindowAttributes(ghMainWnd, 0, (signed int)(255 * gConfig.dwOpacity) / 100, LWA_ALPHA);
    RedrawWindow(ghMainWnd, 0, 0, 0x485u);
    dwOpacity = gConfig.dwOpacity;
  }
  uId = ((signed int)((unsigned __int64)(0x66666667i64 * dwOpacity) >> 32) >> 2)
      + ((unsigned int)((unsigned __int64)(0x66666667i64 * dwOpacity) >> 32) >> 31)
      + 40093;
  v131 = ::GetMenu(v119);
  CheckMenuItem(v131, uId, 8u);
  if ( gbHide )
    CMainWnd::Hide(ghMainWnd);
  return 0;
}
// C09F40: using guessed type bool __cdecl LoadWintrust();
// C66620: using guessed type bool __cdecl GetProcessDEPStatus();
// CACDC0: using guessed type double db_onehundred;
// CB08AC: using guessed type wchar_t aRUnAsAdministr[25];
// CB0D80: using guessed type wchar_t aPaused[7];
// CD4E54: using guessed type int gdwVersion;
// CDA118: using guessed type int (__stdcall *gpfnCreateRestrictedToken)(void *, unsigned int, unsigned int, struct _SID_AND_ATTRIBUTES *, unsigned int, struct _LUID_AND_ATTRIBUTES *, unsigned int, struct _SID_AND_ATTRIBUTES *, void **);
// CDA32C: using guessed type int gdwComdlg_FindReplaceMessageID;
// CDA388: using guessed type char gbHide;
// CDA390: using guessed type char gbIsProcessDEPEnabled;
// CDA391: using guessed type char gbWintrustInited;
// CDA392: using guessed type char gbLaunchDepends;
// CDA884: using guessed type int gShellIconMsg;
// CDA8F4: using guessed type int (__stdcall *gpfnSHAutoComplete)(struct HWND__ *, unsigned int);
// CDA908: using guessed type int ghSplitterCursor;
// CDF360: using guessed type int (__stdcall *ChangeWindowMessageFilter)(_DWORD, _DWORD);
// CF5720: using guessed type int gnStatusBarItemCount;

//----- (00C457D0) --------------------------------------------------------
int __cdecl CMainWnd::HandleClose(HWND hWnd)
{
  if ( gConfig.bHideWhenMinimized )
    CMainWnd::Hide(ghMainWnd);
  else
    CMainWnd::HandleDestroy(hWnd);
  return 0;
}

//----- (00C45810) --------------------------------------------------------
int CMainWnd::HandleEndSession()
{
  UpdateWindowPlacement(ghMainWnd, 1);
  return 0;
}

//----- (00C45830) --------------------------------------------------------
int __cdecl CMainWnd::HandleDestroy(HWND hWnd)
{
  signed int nIndex; // esi
  HANDLE v2; // eax

  ShowWindow(hWnd, 0);
  UpdateWindowPlacement(ghMainWnd, 1);
  nIndex = 1;
  do
    TrayIcon_Delete(hWnd, nIndex++);
  while ( nIndex < 8 );
  SetEvent(ghEvent3);
  PE_RunTrace(&gProperties, 0);
  TerminateThread(ghBackupRefreshThreadHandle, 0);
  v2 = GetCurrentProcess();
  TerminateProcess(v2, 0);
  PostQuitMessage(0);
  return 0;
}

//----- (00C458B0) --------------------------------------------------------
int __cdecl CMainWnd::HandleDrawItem(HWND a1, unsigned int a2, unsigned int a3, LPDRAWITEMSTRUCT a4)
{
  if ( a4->CtlType != 1 )
    return (unsigned __int8)CMainWnd::DrawItem(a4);
  DrawIconEx(a4->hDC, *(_DWORD *)a4->gap1C - 15, *(_DWORD *)&a4->gap1C[4], (HICON)a4->itemData, 16, 16, 0, 0, 3u);
  return 0;
}

//----- (00C458F0) --------------------------------------------------------
signed int __cdecl CMainWnd::HandleSetFocus(HWND a1)
{
  signed int result; // eax

  gdwTickLast = GetTickCount();
  if ( ghWndFocusedLast )
  {
    SetFocus(ghWndFocusedLast);
    result = 1;
  }
  else if ( a1 == ghMainWnd )
  {
    SetFocus(ghWndTreeListView);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}
// CDA380: using guessed type unsigned int gdwTickLast;

//----- (00C45940) --------------------------------------------------------
LRESULT __cdecl CMainWnd::HandleContextMenu(HWND hWnd_1, UINT Msg, HWND hWnd, LPARAM a4)
{
  UINT uID; // edi
  LRESULT v5; // eax
  HWND hWnd_2; // [esp+8h] [ebp-48h]
  struct tagPOINT Point; // [esp+34h] [ebp-1Ch]
  int lParam; // [esp+3Ch] [ebp-14h]
  LONG v10; // [esp+48h] [ebp-8h]

  if ( hWnd == ghWndTreeListView )
  {
    uID = IDC_TREEVIEW_LIST;
  }
  else if ( hWnd == ghWndHandlesListCtrl )
  {
    uID = IDC_LISTCTRL_HANDLES;
  }
  else
  {
    if ( hWnd != ghWndDllsListCtrl )
      return DefWindowProcW(hWnd_1, Msg, (WPARAM)hWnd, a4);
    uID = IDC_LISTCTRL_DLLS;
  }
  hWnd_2 = hWnd_1;
  Point.x = (signed __int16)a4;
  Point.y = SHIWORD(a4);
  if ( (signed __int16)a4 != -1 )
    return 0;
  v5 = SendMessageW(hWnd, LVM_GETNEXTITEM, (signed __int16)a4, 2);
  if ( v5 != -1 )
  {
    lParam = 0;
    SendMessageW(hWnd, LVM_GETITEMRECT, v5, (LPARAM)&lParam);
    Point.y = v10;
    Point.x = lParam + 10;
    ClientToScreen(hWnd, &Point);
  }
  return CMainWnd::UpdateListViewContextMenu(uID, (HWND)&hWnd_2, &Point);
}

//----- (00C45A40) --------------------------------------------------------
int __cdecl CMainWnd::HandleMsg7EF(int _8, int a2, int a3, void *a1)
{
  sub_C28460((tagTREEVIEWLISTITEMPARAM *)a1);
  return 0;
}

//----- (00C45A60) --------------------------------------------------------
int __cdecl CMainWnd::HandleMsg7F8(HWND a1, unsigned int a2, unsigned int a3, const wchar_t **a4)
{
  tagTREEVIEWLISTITEMPARAM *v4; // esi
  char v5; // cl
  tagTREEVIEWLISTITEMPARAM *v6; // ebx
  const wchar_t *v7; // eax
  wchar_t *v8; // eax
  const wchar_t *v9; // eax
  tagDLLLISTITEMPARAM *v10; // esi
  char v11; // bl
  const wchar_t *v12; // eax
  char v14; // [esp+Bh] [ebp-1h]

  v4 = gpTreeViewListItemParam;
  v5 = 0;
  v6 = 0;
  v14 = 0;
  if ( !gpTreeViewListItemParam )
    return 0;
  do
  {
    v7 = v4->szProcessName;
    if ( v4->dwProcessId == gdwProcessIdSelected )
      v6 = v4;
    if ( v7 )
    {
      if ( _wcsicmp(v7, a4[1]) || _wcsicmp(L"system", *a4) && _wcsicmp((const wchar_t *)v4->pszName, *a4) )
      {
        v5 = v14;
      }
      else
      {
        v8 = _wcsdup(a4[2]);
        v5 = 1;
        v4->field_33C = (int)v8;
        v14 = 1;
      }
    }
    v4 = v4->m_Prev;
  }
  while ( v4 );
  if ( v5 )
  {
    if ( RedrawColumn(1, ghWndTreeListView, 1656, 0) )
    {
      InvalidateRect(ghWndTreeListView, 0, 0);
      PE_ResortList(0x65u);
    }
    else if ( IsColumnIDValid(ghWndTreeListView, 0x678u) )
    {
      InvalidateRect(ghWndTreeListView, 0, 0);
    }
  }
  if ( v6 )
  {
    if ( IsWindowVisible(ghWndDllsListCtrl) )
    {
      if ( !_wcsicmp(L"system", *a4) || (v9 = (const wchar_t *)v6->pszName) != 0 && !_wcsicmp(v9, *a4) )
      {
        v10 = gpDllListItemParamHeader;
        v11 = 0;
        if ( gpDllListItemParamHeader )
        {
          do
          {
            v12 = (const wchar_t *)v10->m_strPath.pszData;
            if ( v12 && !_wcsicmp(v12, a4[1]) )
            {
              v10->m_strLocation = (int)_wcsdup(a4[2]);
              v11 = 1;
            }
            v10 = v10->m_Prev;
          }
          while ( v10 );
          if ( v11 )
          {
            InvalidateRect(ghWndDllsListCtrl, 0, 0);
            PE_ResortList(0x68u);
          }
        }
      }
    }
  }
  return 0;
}

//----- (00C45C10) --------------------------------------------------------
int __cdecl CMainWnd::HandleMsg7F6(int a1, int a2, int a3, HWND hWnd)
{
  InvalidateRect(hWnd, 0, 0);
  return 0;
}

//----- (00C45C30) --------------------------------------------------------
signed int CMainWnd::HandleKillFocus()
{
  ghWndFocusedLast = GetFocus();
  return 1;
}

//----- (00C45C50) --------------------------------------------------------
int __cdecl CMainWnd::HandleMsg7F0(HWND a1, unsigned int a2, unsigned int a3, int pListItem)
{
  if ( *(_DWORD *)(pListItem + 4) )
  {
    if ( *(_DWORD *)(pListItem + 356) )
      free(*(void **)(pListItem + 356));
    *(_DWORD *)(pListItem + 356) = _wcsdup(*(const wchar_t **)(pListItem + 360));
    if ( IsColumnIDValid(ghWndDllsListCtrl, 0x4A3u) )
      InvalidateRect(ghWndDllsListCtrl, 0, 0);
  }
  else
  {
    if ( *(_DWORD *)(pListItem + 836) )
      free(*(void **)(pListItem + 836));
    *(_DWORD *)(pListItem + 836) = _wcsdup(*(const wchar_t **)(pListItem + 840));
    if ( RedrawColumn(1, ghWndTreeListView, 1187, 0) )
    {
      InvalidateRect(ghWndTreeListView, 0, 0);
      PE_ResortList(0x65u);
      return 0;
    }
    if ( IsColumnIDValid(ghWndTreeListView, 0x4A3u) )
    {
      InvalidateRect(ghWndTreeListView, 0, 0);
      return 0;
    }
  }
  return 0;
}

//----- (00C45D40) --------------------------------------------------------
_DWORD *__cdecl CMainWnd::HandleMsg7EE(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
  LRESULT ret; // esi
  tagTREEVIEWLISTITEMPARAM *nItem; // ebx

  ret = -1;
  if ( !gConfig.bShowNewProcesses )
  {
    ret = SendMessageW(ghWndTreeListView, LVM_GETNEXTITEM, 0xFFFFFFFF, 2);
    if ( !SendMessageW(ghWndTreeListView, LVM_ISITEMVISIBLE, ret, 0) )
      ret = -1;
  }
  nItem = CTreeList::FindItem(ghWndTreeListView, (tagTREEVIEWLISTITEMPARAM *)lParam);
  if ( ret != -1 )
    SendMessageW(ghWndTreeListView, LVM_ENSUREVISIBLE, ret, 0);
  return &nItem->field_0;
}

//----- (00C45DC0) --------------------------------------------------------
int __cdecl CMainWnd::HandleInitMenuPopup(HWND hWnd, unsigned int nPos, HMENU hMenu)
{
  UINT v3; // esi
  DWORD v4; // esi
  int nIndex; // ebx
  HMENU hMenuUser; // esi
  UINT_PTR v7; // ST0C_4
  UINT v8; // esi
  MENUINFO MenuInfo; // [esp+0h] [ebp-244h]
  DWORD cbRet; // [esp+1Ch] [ebp-228h]
  UINT uPosition; // [esp+20h] [ebp-224h]
  PWTS_SESSION_INFOW pszDomainName; // [esp+24h] [ebp-220h]
  DWORD v14; // [esp+28h] [ebp-21Ch]
  PWTS_SESSION_INFOW pszUserName; // [esp+2Ch] [ebp-218h]
  DWORD nCount; // [esp+30h] [ebp-214h]
  PWTS_SESSION_INFOW pSessionInfo; // [esp+34h] [ebp-210h]
  __int16 NewItem[260]; // [esp+38h] [ebp-20Ch]

  if ( hMenu != ghUserPopupMenuHandle )
    return 0;
  nCount = GetMenuItemCount(ghUserPopupMenuHandle);
  v3 = nCount - 1;
  if ( nCount )
  {
    do
      DeleteMenu(ghUserPopupMenuHandle, v3--, MF_BYPOSITION);
    while ( v3 != -1 );
  }
  if ( WTSEnumerateSessionsW(0, 0, 1u, &pSessionInfo, &nCount) )
  {
    v4 = 0;
    uPosition = 0;
    v14 = 0;
    if ( nCount )
    {
      nIndex = 0;
      do
      {
        if ( WTSQuerySessionInformationW(0, pSessionInfo[nIndex].SessionId, WTSUserName, (LPWSTR *)&pszUserName, &cbRet) )
        {
          if ( WTSQuerySessionInformationW(
                 0,
                 pSessionInfo[nIndex].SessionId,
                 WTSDomainName,
                 (LPWSTR *)&pszDomainName,
                 &cbRet) )
          {
            if ( LOWORD(pszUserName->SessionId) )
            {
              swprintf((wchar_t *)NewItem, L"%d: %s\\%s", pSessionInfo[nIndex].SessionId, pszDomainName, pszUserName);
              hMenuUser = LoadMenuW(ghInstance, L"USERS");
              MenuInfo.cbSize = 28;
              MenuInfo.fMask = 0x80000018;
              MenuInfo.dwStyle = MNS_NOTIFYBYPOS;
              MenuInfo.dwMenuData = pSessionInfo[nIndex].SessionId;
              SetMenuInfo(hMenuUser, &MenuInfo);
              switch ( pSessionInfo[nIndex].State )
              {
                case WTSActive:
                case WTSShadow:
                  break;
                case WTSConnected:
                  EnableMenuItem(hMenuUser, IDM_USERS_CONNECT, MF_GRAYED);
                  EnableMenuItem(hMenuUser, IDM_USERS_LOGOFF, MF_GRAYED);
                  EnableMenuItem(hMenuUser, IDM_USERS_SEND_MESSAGE, MF_GRAYED);
                  break;
                case WTSDisconnected:
                  EnableMenuItem(hMenuUser, IDM_USERS_DISCONNECT, MF_GRAYED);
                  EnableMenuItem(hMenuUser, IDM_USERS_SEND_MESSAGE, MF_GRAYED);
                  break;
                default:
                  EnableMenuItem(hMenuUser, IDM_USERS_CONNECT, MF_GRAYED);
                  EnableMenuItem(hMenuUser, IDM_USERS_SEND_MESSAGE, MF_GRAYED);
                  EnableMenuItem(hMenuUser, IDM_USERS_LOGOFF, MF_GRAYED);
                  EnableMenuItem(hMenuUser, IDM_USERS_DISCONNECT, MF_GRAYED);
                  EnableMenuItem(hMenuUser, IDM_USERS_REMOTE_CONTROL, MF_GRAYED);
                  break;
              }
              v7 = (UINT_PTR)hMenuUser;
              v8 = uPosition;
              InsertMenuW(ghUserPopupMenuHandle, uPosition, 0x410u, v7, (LPCWSTR)NewItem);
              uPosition = v8 + 1;
              v4 = v14;
            }
            WTSFreeMemory(pszDomainName);
          }
          WTSFreeMemory(pszUserName);
        }
        ++v4;
        ++nIndex;
        v14 = v4;
      }
      while ( v4 < nCount );
    }
    WTSFreeMemory(pSessionInfo);
  }
  return 0;
}

//----- (00C46050) --------------------------------------------------------
LRESULT __cdecl CMainWnd::HandleMenuCommand(HWND hWnd, int a2, int nPos, HMENU hMenu)
{
  UINT uID; // eax
  UINT v5; // esi
  LRESULT result; // eax
  DWORD v7; // eax
  const WCHAR **v8; // eax
  const WCHAR *pszPassword; // eax
  char v10; // bl
  DWORD v11; // eax
  struct _CREDUI_INFOW UiInfo; // [esp+Ch] [ebp-458h]
  struct tagMENUINFO MenuInfo; // [esp+20h] [ebp-444h]
  LPWSTR ppBuffer; // [esp+3Ch] [ebp-428h]
  _bstr_t bstrPassword; // [esp+40h] [ebp-424h]
  BOOL save; // [esp+44h] [ebp-420h]
  DWORD pSessionID; // [esp+48h] [ebp-41Ch]
  DWORD nSize; // [esp+4Ch] [ebp-418h]
  __int16 Buffer[260]; // [esp+50h] [ebp-414h]
  __int16 psz[260]; // [esp+258h] [ebp-20Ch]

  psz[0] = 0;
  memset(&psz[1], 0, 0x206u);
  uID = GetMenuItemID(hMenu, nPos);
  v5 = uID;
  if ( uID != IDM_USERS_DISCONNECT
    && uID != IDM_USERS_LOGOFF
    && uID != IDM_USERS_SEND_MESSAGE
    && uID != IDM_USERS_PROPERTIES
    && uID != IDM_USERS_CONNECT
    && uID != IDM_USERS_REMOTE_CONTROL )
  {
    return HandleCmdHandler((int)&CMainWnd::gCmdHandler, hWnd, uID, 0);
  }
  MenuInfo.cbSize = 28;
  MenuInfo.fMask = 8;
  GetMenuInfo(hMenu, &MenuInfo);
  switch ( v5 )
  {
    case IDM_USERS_DISCONNECT:
      if ( WTSDisconnectSession(0, MenuInfo.dwMenuData, 0) )
        goto __quit;
      ReportMsg(L"Error disconnecting session", ghMainWnd);
      return 0;
    case IDM_USERS_LOGOFF:
      if ( WTSLogoffSession(0, MenuInfo.dwMenuData, 0) )
        goto __quit;
      ReportMsg(L"Error logging off session", ghMainWnd);
      return 0;
    case IDM_USERS_SEND_MESSAGE:
      DialogBoxParamW(ghInstance, L"SENDMESSAGE", ghMainWnd, (DLGPROC)DlgSendMessage, MenuInfo.dwMenuData);
      goto __quit;
    case IDM_USERS_PROPERTIES:
      DialogBoxParamW(ghInstance, L"TSINFO", ghMainWnd, DlgTsInfo, MenuInfo.dwMenuData);
      goto __quit;
    case IDM_USERS_CONNECT:
      if ( WTSQuerySessionInformationW(0, MenuInfo.dwMenuData, WTSUserName, &ppBuffer, &nSize) )
      {
        UiInfo.hwndParent = hWnd;
        save = 0;
        UiInfo.cbSize = 20;
        UiInfo.pszMessageText = L"Enter the selected user's password";
        UiInfo.pszCaptionText = L"Process Explorer Connect Password";
        UiInfo.hbmBanner = 0;
        do
        {
          v7 = CredUIPromptForCredentialsW(
                 &UiInfo,
                 (PWSTR)&gszNullString,
                 0,
                 0x52Eu,
                 ppBuffer,
                 nSize,
                 (PWSTR)psz,
                 0x104u,
                 &save,
                 0x140082u);
          if ( !v7 )
          {
            v8 = (const WCHAR **)*_bstr_t::_bstr_t((tagEventSetItem *)&bstrPassword, (OLECHAR *)psz);
            if ( v8 )
              pszPassword = *v8;
            else
              pszPassword = 0;
            v10 = WinStationConnectW(0, MenuInfo.dwMenuData, 0xFFFFFFFF, pszPassword, 1);
            _bstr_t::_Free(&bstrPassword);
            if ( v10 )
              goto __quit;
            v7 = GetLastError();
          }
        }
        while ( v7 == 1326 );
      }
      else
      {
        v7 = GetLastError();
      }
      if ( !v7 )
        goto __quit;
      SetLastError(v7);
      ReportMsg(L"Error connecting to session", ghMainWnd);
      result = 0;
      break;
    case IDM_USERS_REMOTE_CONTROL:
      v11 = GetCurrentProcessId();
      gpfnProcessIdToSessionId(v11, &pSessionID);
      if ( WTSGetActiveConsoleSessionId() == pSessionID )
      {
        ReportMsg(L"Remote control is not supported from a console session", ghMainWnd);
        result = 0;
      }
      else
      {
        nSize = 260;
        GetComputerNameW((LPWSTR)Buffer, &nSize);
        if ( (unsigned __int8)WinStationShadow(0, (LPCWSTR)Buffer, MenuInfo.dwMenuData, VK_F1, 2u) )
        {
__quit:
          result = 0;
        }
        else
        {
          ReportMsg(L"Error starting remote control", ghMainWnd);
          result = 0;
        }
      }
      break;
    default:
      goto __quit;
  }
  return result;
}
// CB0F50: using guessed type wchar_t aEnterTheSelect[35];
// CB0F98: using guessed type wchar_t aProcessExplore_5[34];
// CB10F8: using guessed type wchar_t aSendmessage[12];
// CCE11C: using guessed type struct tagMSGHANDLER CMainWnd::gCmdHandler;

//----- (00C46470) --------------------------------------------------------
signed int __cdecl CMainWnd::HandleCopyData(HWND hWnd, UINT msg, WPARAM wParam, PCOPYDATASTRUCT lParam)
{
  tagTREEVIEWLISTITEMPARAM *pItemParam; // esi
  signed int ret; // esi
  CHAR *v6; // edi
  CString strData; // [esp+8h] [ebp-34h]
  WINDOWPLACEMENT wndpl; // [esp+Ch] [ebp-30h]

  pItemParam = gpTreeViewListItemParam;
  ATL::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>(
    &strData,
    (LPCSTR)lParam->lpData,
    lParam->cbData);
  if ( pItemParam )
  {
    while ( _wcsicmp(pItemParam->szProcessName2, (const wchar_t *)strData.pszData) )
    {
      pItemParam = pItemParam->m_Prev;
      if ( !pItemParam )
        goto LABEL_4;
    }
    CTreeList::FillTreeViewParam(pItemParam);
    if ( !IsWindowVisible(ghMainWnd) )
    {
      wndpl.length = 44;
      GetWindowPlacement(ghMainWnd, &wndpl);
      ShowWindow(ghMainWnd, 4 * (wndpl.showCmd == 2) + 5);
      SetForegroundWindow(ghMainWnd);
      SetFocus(ghMainWnd);
      gbMainWndMinimized1 = 1;
      gbMainWndMinimized = 0;
    }
    ret = 2;
  }
  else
  {
LABEL_4:
    ret = 1;
  }
  v6 = strData.pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)strData.pszData - 1) <= 0 )
    (*(void (__stdcall **)(CHAR *))(**(_DWORD **)v6 + 4))(v6);
  return ret;
}
// CDA389: using guessed type char gbMainWndMinimized;
// CDA393: using guessed type char gbMainWndMinimized1;

//----- (00C46570) --------------------------------------------------------
int __cdecl CMainWnd::HandleMsg7F3(HWND a1, unsigned int a2, unsigned int a3, int a4)
{
  CTreeList *v4; // eax
  HICON v5; // ST08_4
  _IMAGELIST *v6; // eax

  v4 = CTreeList::GetTreeList(ghWndTreeListView);
  if ( *(_DWORD *)(a4 + 52) )
  {
    v5 = *(HICON *)(a4 + 52);
    v6 = CTreeList::GetImageList(v4);
    *(_DWORD *)(a4 + 64) = ImageList_ReplaceIcon(v6, -1, v5);
  }
  else
  {
    *(_DWORD *)(a4 + 64) = 0;
  }
  return 0;
}

//----- (00C465C0) --------------------------------------------------------
int __cdecl CMainWnd::HandleMsg7E8(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
  HWND hWndLV; // esi
  LRESULT nItem; // edi

  switch ( wParam )
  {
    case IDC_TREEVIEW_LIST:
      hWndLV = ghWndTreeListView;
      break;
    case IDC_LISTCTRL_HANDLES:
      hWndLV = ghWndHandlesListCtrl;
      break;
    case IDM_ABOUT:
      hWndLV = ghWndDllsListCtrl;
      break;
    default:
      hWndLV = (HWND)wParam;
      break;
  }
  nItem = -1;
  if ( !gConfig.bShowNewProcesses )
  {
    nItem = SendMessageW(hWndLV, LVM_GETNEXTITEM, 0xFFFFFFFF, 2);
    if ( !SendMessageW(hWndLV, LVM_ISITEMVISIBLE, nItem, 0) )
      nItem = -1;
  }
  if ( wParam == IDC_TREEVIEW_LIST )
    sub_C66020(gpTreeViewListItemParam);
  PE_ResortList(wParam);
  if ( nItem != -1 )
    SendMessageW(hWndLV, LVM_ENSUREVISIBLE, nItem, 0);
  return 0;
}

//----- (00C46660) --------------------------------------------------------
int __cdecl CMainWnd::HandleMsg7E9(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
  HMENU v4; // eax
  HMENU v5; // eax
  int v6; // ST14_4
  HMENU v7; // edi
  HMENU v8; // eax
  HMENU v9; // eax
  HMENU v10; // eax
  HMODULE v12; // eax
  void (*EndMenu)(void); // eax
  struct tagPOINT Point; // [esp+4h] [ebp-38h]
  WINDOWPLACEMENT wndpl; // [esp+Ch] [ebp-30h]

  if ( lParam == 123 )
    goto LABEL_4;
  if ( lParam != 513 )
  {
    if ( lParam != 517 )
      return 0;
LABEL_4:
    GetCursorPos(&Point);
    SetForegroundWindow(hWnd);
    v4 = LoadMenuW(ghInstance, L"TRAYMENU");
    v5 = GetSubMenu(v4, 0);
    v6 = gdwMenuItemCountAppendedInRuntime;
    v7 = v5;
    v8 = GetMenu(hWnd);
    v9 = GetSubMenu(v8, 0);
    v10 = GetSubMenu(v9, v6);
    InsertMenuW(v7, 0, 0x410u, (UINT_PTR)v10, L"S&hutdown");
    TrackPopupMenu(v7, 0, Point.x, Point.y, 0, hWnd, 0);
    return 0;
  }
  v12 = GetModuleHandleW(L"user32.dll");
  EndMenu = (void (*)(void))GetProcAddress(v12, "EndMenu");
  if ( EndMenu )
    EndMenu();
  else
    SendMessageW(hWnd, WM_CANCELMODE, 0, 0);
  wndpl.length = 44;
  GetWindowPlacement(ghMainWnd, &wndpl);
  if ( !IsWindowVisible(ghMainWnd) || wndpl.showCmd == SW_SHOWMINIMIZED )
  {
LABEL_14:
    gbMainWndMinimized1 = 1;
    Command_OpenProcExp();
    return 0;
  }
  if ( sub_C47A60(ghWndTreeListView) )
  {
    if ( gConfig.bHideWhenMinimized )
    {
      CMainWnd::Hide(ghMainWnd);
      return 0;
    }
    goto LABEL_14;
  }
  SetForegroundWindow(ghMainWnd);
  return 0;
}
// CDA393: using guessed type char gbMainWndMinimized1;

//----- (00C467F0) --------------------------------------------------------
LRESULT __cdecl CMainWnd::HandleSysCommand(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
  if ( !gConfig.bHideWhenMinimized || wParam != SC_MINIMIZE )
    return DefWindowProcW(hWnd, Msg, wParam, lParam);
  gbMainWndMinimized = 1;
  CMainWnd::Hide(hWnd);
  return 0;
}
// CDA389: using guessed type char gbMainWndMinimized;

//----- (00C46830) --------------------------------------------------------
int __cdecl CMainWnd::HandleMsg7EB(int a1, int a2, WPARAM wParam, WPARAM wParam_1)
{
  CTreeList *v4; // eax
  int result; // eax
  int v6; // [esp+0h] [ebp-14h]
  int v7; // [esp+4h] [ebp-10h]
  int v8; // [esp+8h] [ebp-Ch]
  int v9; // [esp+Ch] [ebp-8h]

  if ( wParam == -2 )
  {
    v4 = CTreeList::GetTreeList(ghWndTreeListView);
    CTreeList::RefreshHeaderItem(v4, wParam_1);
    result = 0;
  }
  else
  {
    if ( wParam_1 == -1 )
    {
      SendMessageW(ghWndTreeListView, 0x1015u, wParam, wParam);
    }
    else
    {
      sub_C2A880(ghWndTreeListView, wParam, wParam_1, (#153 *)&v6);
      v8 += v6;
      v9 += v7;
      InvalidateRect(ghWndTreeListView, (const RECT *)&v6, 0);
    }
    result = 0;
  }
  return result;
}

//----- (00C468E0) --------------------------------------------------------
int sub_C468E0(wchar_t *Dst, wchar_t *Format, ...)
{
  va_list ArgList; // [esp+10h] [ebp+10h]

  va_start(ArgList, Format);
  return vswprintf_s(Dst, 0x410u, Format, ArgList);
}

//----- (00C46900) --------------------------------------------------------
CString *__thiscall ATL::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>(CString *this, LPCSTR lpMultiByteStr, int cbMultiByte)
{
  CString *v3; // esi
  IAtlStringMgr *v4; // ecx
  int v5; // eax
  int v6; // edi

  v3 = this;
  v4 = ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>::GetDefaultManager();
  if ( !v4 )
    ATL::AtlThrowImpl(E_FAIL);
  v3->pszData = (CHAR *)(((int (*)(void))v4->vtptr->GetNilData)() + 16);
  if ( cbMultiByte > 0 )
  {
    if ( !lpMultiByteStr )
      goto LABEL_15;
    v5 = MultiByteToWideChar(3u, 0, lpMultiByteStr, cbMultiByte, 0, 0);
    v6 = v5;
    if ( v5 < 0 )
      ATL::AtlThrowImpl(E_INVALIDARG);
    if ( ((*((_DWORD *)v3->pszData - 2) - v5) | (1 - *((_DWORD *)v3->pszData - 1))) < 0 )
      ATL::CSimpleStringT<wchar_t,0>::PrepareWrite2(v3, v5);
    MultiByteToWideChar(3u, 0, lpMultiByteStr, cbMultiByte, (LPWSTR)v3->pszData, v6);
    if ( v6 > *((_DWORD *)v3->pszData - 2) )
LABEL_15:
      ATL::AtlThrowImpl(E_INVALIDARG);
    *((_DWORD *)v3->pszData - 3) = v6;
    *(_WORD *)&v3->pszData[2 * v6] = 0;
  }
  return v3;
}

//----- (00C469F0) --------------------------------------------------------
HBRUSH __stdcall DlgSelectColor(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
  COLORREF v4; // esi
  HBRUSH result; // eax
  COLORREF v6; // esi
  BOOL v7; // ST08_4
  BOOL v8; // ST08_4
  BOOL v9; // ST08_4
  BOOL v10; // ST08_4
  BOOL v11; // ST08_4
  BOOL v12; // ST08_4
  BOOL v13; // ST08_4
  BOOL v14; // ST08_4
  BOOL v15; // ST08_4
  BOOL v16; // ST08_4
  UINT v17; // eax
  UINT v18; // eax
  UINT v19; // eax
  UINT v20; // eax
  UINT v21; // eax
  UINT v22; // eax
  UINT v23; // eax
  UINT v24; // eax
  UINT v25; // eax
  UINT v26; // eax
  HWND v27; // eax
  HWND v28; // eax
  HWND v29; // eax
  HWND v30; // eax
  HWND v31; // eax
  HWND v32; // eax
  HWND v33; // eax
  HWND v34; // eax
  HWND v35; // eax
  HWND v36; // eax
  HWND v37; // eax
  HWND v38; // eax
  HWND v39; // eax

  if ( uMsg == WM_INITDIALOG )
  {
    gColorOwnProcessStatic = gConfig.ColorOwn;
    gColorServices = gConfig.ColorService;
    gColorRelocatedDlls = gConfig.ColorRelocatedDlls;
    gColorJobs = gConfig.ColorJobs;
    gColorDotNetProcesses = gConfig.ColorNet;
    gColorNewObjectes = gConfig.ColorNewProc;
    gColorDeletedObjects = gConfig.ColorDelProc;
    gColorPackedImages = gConfig.ColorPacked;
    gColorPagingListsStandby = gConfig.ColorGraphBk;
    gColorWSShared = gConfig.ColorImmersive;
    gColorSuspendedProcess = gConfig.ColorSuspend;
    gColorProtectedProcess = gConfig.ColorProtected;
    CheckDlgButton(hDlg, IDD_CHOOSECOLORS_CHECKBOX_DELETED_OBJECTS, gConfig.bHighlightDelProc != 0);
    CheckDlgButton(hDlg, IDD_CHOOSECOLORS_CHECKBOX_NEW_OBJECTS, gConfig.bHighlightNewProc != 0);
    CheckDlgButton(hDlg, IDD_CHOOSECOLORS_CHECKBOX_OWN_PROCESSES, gConfig.bHighlightOwnProcesses != 0);
    CheckDlgButton(hDlg, IDD_CHOOSECOLORS_CHECKBOX_SERVICES, gConfig.bHighlightServices != 0);
    CheckDlgButton(hDlg, IDD_CHOOSECOLORS_CHECKBOX_RELOCATED_DLLS, gConfig.bHighlightRelocatedDlls != 0);
    CheckDlgButton(hDlg, IDD_CHOOSECOLORS_CHECKBOX_PACKED_IMAGES, gConfig.bHighlightPacked != 0);
    CheckDlgButton(hDlg, IDD_CHOOSECOLORS_CHECKBOX_SUSPENDED_PROCESSES, gConfig.bHighlightSuspend != 0);
    CheckDlgButton(hDlg, IDD_CHOOSECOLORS_CHECKBOX_PROTECTED_PROCESS, gConfig.bHighlightProtected != 0);
    v27 = GetDlgItem(hDlg, IDD_CHOOSECOLORS_CHECKBOX_IMMERSIVE_PROCESS);
    EnableWindow(v27, 0);
    if ( gdwVersion >= 1 && IsBuiltinAdministrative() )
    {
      v28 = GetDlgItem(hDlg, IDD_CHOOSECOLORS_CHECKBOX_PROTECTED_PROCESS);
      EnableWindow(v28, 1);
      v29 = GetDlgItem(hDlg, IDD_CHOOSECOLORS_STATIC_PROTECTED_PROCESS);
      EnableWindow(v29, 1);
      v30 = GetDlgItem(hDlg, IDD_CHOOSECOLORS_BUTTON_PROTECTED_PROCESS_CHANGE);
      EnableWindow(v30, 1);
    }
    if ( *(_DWORD *)IsProcessInJob )
    {
      v31 = GetDlgItem(hDlg, IDD_CHOOSECOLORS_CHECKBOX_JOBS);
      EnableWindow(v31, 1);
      v32 = GetDlgItem(hDlg, IDD_CHOOSECOLORS_BUTTON_JOBS_CHANGE);
      EnableWindow(v32, 1);
      CheckDlgButton(hDlg, IDD_CHOOSECOLORS_CHECKBOX_JOBS, gConfig.bHighlightJobs != 0);
    }
    v33 = GetDlgItem(hDlg, IDD_CHOOSECOLORS_STATIC_JOBS);
    EnableWindow(v33, 1);
    if ( IsImmersiveProcess )
    {
      v34 = GetDlgItem(hDlg, IDD_CHOOSECOLORS_CHECKBOX_IMMERSIVE_PROCESS);
      EnableWindow(v34, 1);
      v35 = GetDlgItem(hDlg, IDD_CHOOSECOLORS_BUTTON_IMMERSIVE_PROCESS_CHANGE);
      EnableWindow(v35, 1);
      CheckDlgButton(hDlg, IDD_CHOOSECOLORS_CHECKBOX_IMMERSIVE_PROCESS, gConfig.bHighlightImmersive != 0);
    }
    v36 = GetDlgItem(hDlg, IDD_CHOOSECOLORS_STATIC_IMMERSIVE_PROCESS);
    EnableWindow(v36, 1);
    if ( gNetClrMemoryPerfInfoLoaded )
    {
      v37 = GetDlgItem(hDlg, IDD_CHOOSECOLORS_CHECKBOX_DOTNET_PROCESSES);
      EnableWindow(v37, 1);
      v38 = GetDlgItem(hDlg, IDD_CHOOSECOLORS_BUTTON_DOTNET_PROCESSES_CHANGE);
      EnableWindow(v38, 1);
      CheckDlgButton(hDlg, IDD_CHOOSECOLORS_CHECKBOX_DOTNET_PROCESSES, gConfig.bHighliteNetProcess != 0);
    }
    v39 = GetDlgItem(hDlg, IDD_CHOOSECOLORS_STATIC_DOTNET_PROCESSES);
    EnableWindow(v39, 1);
    result = (HBRUSH)1;
  }
  else
  {
    if ( uMsg != WM_COMMAND )
    {
      if ( uMsg == WM_CTLCOLORSTATIC )
      {
        if ( (HWND)lParam == GetDlgItem(hDlg, IDD_CHOOSECOLORS_STATIC_OWN_PROCESSES) )
        {
          SetBkColor((HDC)wParam, gColorOwnProcessStatic);
          v4 = gColorOwnProcessStatic;
          if ( gBrushOfOwnProcessStatic )
            DeleteObject(gBrushOfOwnProcessStatic);
          result = CreateSolidBrush(v4);
          gBrushOfOwnProcessStatic = result;
          return result;
        }
        if ( (HWND)lParam == GetDlgItem(hDlg, IDD_CHOOSECOLORS_STATIC_IMMERSIVE_PROCESS) )
        {
          SetBkColor((HDC)wParam, gColorWSShared);
          v6 = gColorWSShared;
          if ( gBrushImmsiveProcess )
            DeleteObject(gBrushImmsiveProcess);
          result = CreateSolidBrush(v6);
          gBrushImmsiveProcess = result;
          return result;
        }
        if ( (HWND)lParam == GetDlgItem(hDlg, IDD_CHOOSECOLORS_STATIC_SERVICES) )
        {
          SetBkColor((HDC)wParam, gColorServices);
          return BrushFromColor(gColorServices, (HBRUSH *)&gBrushServices);
        }
        if ( (HWND)lParam == GetDlgItem(hDlg, IDD_CHOOSECOLORS_STATIC_GRAPH_BACKGROUND) )
        {
          SetTextColor((HDC)wParam, 255 - gColorPagingListsStandby);
          SetBkColor((HDC)wParam, gColorPagingListsStandby);
          return BrushFromColor(gColorPagingListsStandby, (HBRUSH *)&gBrushPagingListsStandby);
        }
        if ( (HWND)lParam == GetDlgItem(hDlg, IDD_CHOOSECOLORS_STATIC_RELOCATED_DLLS) )
        {
          SetBkColor((HDC)wParam, gColorRelocatedDlls);
          return BrushFromColor(gColorRelocatedDlls, (HBRUSH *)&gBrushRelocatedDlls);
        }
        if ( (HWND)lParam == GetDlgItem(hDlg, IDD_CHOOSECOLORS_STATIC_PACKED_IMAGES) )
        {
          SetBkColor((HDC)wParam, gColorPackedImages);
          return BrushFromColor(gColorPackedImages, (HBRUSH *)&gBrushPackedImages);
        }
        if ( (HWND)lParam == GetDlgItem(hDlg, IDD_CHOOSECOLORS_STATIC_SUSPENDED_PROCESSES) )
        {
          SetBkColor((HDC)wParam, gColorSuspendedProcess);
          return BrushFromColor(gColorSuspendedProcess, (HBRUSH *)&gBrushSuspendedProcess);
        }
        if ( (HWND)lParam == GetDlgItem(hDlg, IDD_CHOOSECOLORS_STATIC_JOBS) )
        {
          SetBkColor((HDC)wParam, gColorJobs);
          return BrushFromColor(gColorJobs, (HBRUSH *)&gBrushJobs);
        }
        if ( (HWND)lParam == GetDlgItem(hDlg, IDD_CHOOSECOLORS_STATIC_DOTNET_PROCESSES) )
        {
          SetBkColor((HDC)wParam, gColorDotNetProcesses);
          return BrushFromColor(gColorDotNetProcesses, (HBRUSH *)&gBrushDotNetProcesses);
        }
        if ( (HWND)lParam == GetDlgItem(hDlg, IDD_CHOOSECOLORS_STATIC_NEW_OBJECTS) )
        {
          SetBkColor((HDC)wParam, gColorNewObjectes);
          return BrushFromColor(gColorNewObjectes, (HBRUSH *)&gBrushNewObjects);
        }
        if ( (HWND)lParam == GetDlgItem(hDlg, IDD_CHOOSECOLORS_STATIC_DELETED_OBJECTS) )
        {
          SetBkColor((HDC)wParam, gColorDeletedObjects);
          return BrushFromColor(gColorDeletedObjects, (HBRUSH *)&gBrushDeletedObjects);
        }
        if ( (HWND)lParam == GetDlgItem(hDlg, IDD_CHOOSECOLORS_STATIC_PROTECTED_PROCESS)
          && IsWindowEnabled((HWND)lParam) )
        {
          SetBkColor((HDC)wParam, gColorProtectedProcess);
          return BrushFromColor(gColorProtectedProcess, (HBRUSH *)&gBrushDeletedObjects);
        }
      }
      return 0;
    }
    if ( !(wParam >> 16) )
    {
      switch ( (unsigned __int16)wParam )
      {
        case IDD_CHOOSECOLORS_STATIC_OWN_PROCESSES:
          v7 = IsDlgButtonChecked(hDlg, IDD_CHOOSECOLORS_CHECKBOX_OWN_PROCESSES) != 1;
          CheckDlgButton(hDlg, IDD_CHOOSECOLORS_CHECKBOX_OWN_PROCESSES, v7);
          break;
        case IDD_CHOOSECOLORS_STATIC_SERVICES:
          v8 = IsDlgButtonChecked(hDlg, IDD_CHOOSECOLORS_CHECKBOX_SERVICES) != 1;
          CheckDlgButton(hDlg, IDD_CHOOSECOLORS_CHECKBOX_SERVICES, v8);
          break;
        case IDD_CHOOSECOLORS_STATIC_RELOCATED_DLLS:
          v10 = IsDlgButtonChecked(hDlg, IDD_CHOOSECOLORS_CHECKBOX_RELOCATED_DLLS) != 1;
          CheckDlgButton(hDlg, IDD_CHOOSECOLORS_CHECKBOX_RELOCATED_DLLS, v10);
          break;
        case IDD_CHOOSECOLORS_STATIC_JOBS:
          v11 = IsDlgButtonChecked(hDlg, IDD_CHOOSECOLORS_CHECKBOX_JOBS) != 1;
          CheckDlgButton(hDlg, IDD_CHOOSECOLORS_CHECKBOX_JOBS, v11);
          break;
        case IDD_CHOOSECOLORS_STATIC_DOTNET_PROCESSES:
          v12 = IsDlgButtonChecked(hDlg, IDD_CHOOSECOLORS_CHECKBOX_DOTNET_PROCESSES) != 1;
          CheckDlgButton(hDlg, IDD_CHOOSECOLORS_CHECKBOX_DOTNET_PROCESSES, v12);
          break;
        case IDD_CHOOSECOLORS_STATIC_DELETED_OBJECTS:
          v15 = IsDlgButtonChecked(hDlg, IDD_CHOOSECOLORS_CHECKBOX_DELETED_OBJECTS) != 1;
          CheckDlgButton(hDlg, IDD_CHOOSECOLORS_CHECKBOX_DELETED_OBJECTS, v15);
          break;
        case IDD_CHOOSECOLORS_STATIC_NEW_OBJECTS:
          v14 = IsDlgButtonChecked(hDlg, IDD_CHOOSECOLORS_CHECKBOX_NEW_OBJECTS) != 1;
          CheckDlgButton(hDlg, IDD_CHOOSECOLORS_CHECKBOX_NEW_OBJECTS, v14);
          break;
        case IDD_CHOOSECOLORS_STATIC_PACKED_IMAGES:
          v9 = IsDlgButtonChecked(hDlg, IDD_CHOOSECOLORS_CHECKBOX_PACKED_IMAGES) != 1;
          CheckDlgButton(hDlg, IDD_CHOOSECOLORS_CHECKBOX_PACKED_IMAGES, v9);
          break;
        case IDS_COMPANY_NAME:
          v13 = IsDlgButtonChecked(hDlg, IDD_CHOOSECOLORS_CHECKBOX_SUSPENDED_PROCESSES) != 1;
          CheckDlgButton(hDlg, IDD_CHOOSECOLORS_CHECKBOX_SUSPENDED_PROCESSES, v13);
          break;
        case IDD_ABOUT_STATIC_ADDRESS:
          v16 = IsDlgButtonChecked(hDlg, IDD_CHOOSECOLORS_CHECKBOX_PROTECTED_PROCESS) != 1;
          CheckDlgButton(hDlg, IDD_CHOOSECOLORS_CHECKBOX_PROTECTED_PROCESS, v16);
          break;
        default:
          break;
      }
    }
    if ( wParam <= IDD_CHOOSECOLORS_BUTTON_OWN_PROCESSES_CHANGE )
    {
      switch ( wParam )
      {
        case IDD_CHOOSECOLORS_BUTTON_OWN_PROCESSES_CHANGE:
          return (HBRUSH)SelectColor(hDlg, &gColorOwnProcessStatic);
        case 1u:
          gConfig.ColorJobs = gColorJobs;
          DeleteObject(gBrushJobs);
          v17 = IsDlgButtonChecked(hDlg, IDD_CHOOSECOLORS_CHECKBOX_JOBS);
          gConfig.ColorRelocatedDlls = gColorRelocatedDlls;
          gConfig.bHighlightJobs = v17 == 1;
          DeleteObject(gBrushRelocatedDlls);
          v18 = IsDlgButtonChecked(hDlg, IDD_CHOOSECOLORS_CHECKBOX_RELOCATED_DLLS);
          gConfig.ColorOwn = gColorOwnProcessStatic;
          gConfig.bHighlightRelocatedDlls = v18 == 1;
          DeleteObject(gBrushOfOwnProcessStatic);
          v19 = IsDlgButtonChecked(hDlg, IDD_CHOOSECOLORS_CHECKBOX_OWN_PROCESSES);
          gConfig.ColorService = gColorServices;
          gConfig.bHighlightOwnProcesses = v19 == 1;
          DeleteObject(gBrushServices);
          v20 = IsDlgButtonChecked(hDlg, IDD_CHOOSECOLORS_CHECKBOX_SERVICES);
          gConfig.ColorNet = gColorDotNetProcesses;
          gConfig.bHighlightServices = v20 == 1;
          DeleteObject(gBrushDotNetProcesses);
          v21 = IsDlgButtonChecked(hDlg, IDD_CHOOSECOLORS_CHECKBOX_DOTNET_PROCESSES);
          gConfig.ColorSuspend = gColorSuspendedProcess;
          gConfig.bHighliteNetProcess = v21 == 1;
          DeleteObject(gBrushSuspendedProcess);
          v22 = IsDlgButtonChecked(hDlg, IDD_CHOOSECOLORS_CHECKBOX_SUSPENDED_PROCESSES);
          gConfig.ColorNewProc = gColorNewObjectes;
          gConfig.bHighlightSuspend = v22 == 1;
          DeleteObject(gBrushNewObjects);
          v23 = IsDlgButtonChecked(hDlg, IDD_CHOOSECOLORS_CHECKBOX_NEW_OBJECTS);
          gConfig.ColorDelProc = gColorDeletedObjects;
          gConfig.bHighlightNewProc = v23 == 1;
          DeleteObject(gBrushDeletedObjects);
          v24 = IsDlgButtonChecked(hDlg, IDD_CHOOSECOLORS_CHECKBOX_DELETED_OBJECTS);
          gConfig.ColorPacked = gColorPackedImages;
          gConfig.bHighlightDelProc = v24 == 1;
          DeleteObject(gBrushPackedImages);
          gConfig.bHighlightPacked = IsDlgButtonChecked(hDlg, IDD_CHOOSECOLORS_CHECKBOX_PACKED_IMAGES) == 1;
          gConfig.ColorGraphBk = gColorPagingListsStandby;
          DeleteObject(gBrushPagingListsStandby);
          v25 = IsDlgButtonChecked(hDlg, IDD_CHOOSECOLORS_CHECKBOX_IMMERSIVE_PROCESS);
          gConfig.ColorImmersive = gColorWSShared;
          gConfig.bHighlightImmersive = v25 == 1;
          DeleteObject(gBrushImmsiveProcess);
          v26 = IsDlgButtonChecked(hDlg, IDD_CHOOSECOLORS_CHECKBOX_PROTECTED_PROCESS);
          gConfig.ColorProtected = gColorProtectedProcess;
          gConfig.bHighlightProtected = v26 == 1;
          DeleteObject(ho);
          SetEvent(ghTimerRefreshEvent);
          break;
        case IDC_MYICON:
          break;
        default:
          return 0;
      }
      EndDialog(hDlg, 0);
      return 0;
    }
    switch ( wParam )
    {
      case IDD_CHOOSECOLORS_BUTTON_SERVICES_CHANGE:
        result = (HBRUSH)SelectColor(hDlg, &gColorServices);
        break;
      case IDD_CHOOSECOLORS_BUTTON_RELOCATED_DLLS_CHANGE:
        result = (HBRUSH)SelectColor(hDlg, &gColorRelocatedDlls);
        break;
      case IDD_CHOOSECOLORS_BUTTON_JOBS_CHANGE:
        result = (HBRUSH)SelectColor(hDlg, &gColorJobs);
        break;
      case IDD_CHOOSECOLORS_BUTTON_DELETE_OBJECTS_CHANGE:
        result = (HBRUSH)SelectColor(hDlg, &gColorDeletedObjects);
        break;
      case IDD_CHOOSECOLORS_BUTTON_DOTNET_PROCESSES_CHANGE:
        result = (HBRUSH)SelectColor(hDlg, &gColorDotNetProcesses);
        break;
      case IDD_CHOOSECOLORS_BUTTON_NEW_OBJECTS_CHANGE:
        result = (HBRUSH)SelectColor(hDlg, &gColorNewObjectes);
        break;
      case IDD_CHOOSECOLORS_BUTTON_PACKED_IMAGES_CHANGE:
        result = (HBRUSH)SelectColor(hDlg, &gColorPackedImages);
        break;
      case IDC_SYSINFO_MEMORY_STATIC_PAGING_LISTS_STANDBY_VALUE:
        SelectColor(hDlg, &gColorPagingListsStandby);
        result = (HBRUSH)1;
        break;
      case IDS_WS_SHARED:
        result = (HBRUSH)SelectColor(hDlg, &gColorWSShared);
        break;
      case IDD_CHOOSECOLORS_BUTTON_SUSPENDED_PROCESSES_CHANGE:
        result = (HBRUSH)SelectColor(hDlg, &gColorSuspendedProcess);
        break;
      case IDD_CHOOSECOLORS_BUTTON_PROTECTED_PROCESS_CHANGE:
        result = (HBRUSH)SelectColor(hDlg, &gColorProtectedProcess);
        break;
      case IDD_CHOOSECOLORS_BUTTON_DEFAULTS:
        gColorOwnProcessStatic = 0xFFD0D0;
        gColorServices = 0xD0D0FF;
        gColorRelocatedDlls = 0xA0FFFF;
        gColorJobs = 0x6CD0;
        gColorDotNetProcesses = 0xA0FFFF;
        gColorWSShared = 0xEAEA00;
        gColorNewObjectes = 0x46FF46;
        gColorDeletedObjects = 0x4646FF;
        gColorPackedImages = 0xFF0080;
        gColorSuspendedProcess = 0x808080;
        gColorProtectedProcess = 0x8000FF;
        gColorPagingListsStandby = GetSysColor(COLOR_BTNFACE);
        InvalidateRect(hDlg, 0, 0);
        result = (HBRUSH)1;
        break;
      default:
        return 0;
    }
  }
  return result;
}
// CD4E54: using guessed type int gdwVersion;
// CDA098: using guessed type char gNetClrMemoryPerfInfoLoaded;
// CEBA4C: using guessed type int (__stdcall *IsImmersiveProcess)(_DWORD);

//----- (00C474D0) --------------------------------------------------------
int __stdcall PropColumnSetsForStatusBar(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
  double v4; // st1
  double v5; // st2
  double v6; // st3
  double v7; // st4
  double v8; // st5
  double v9; // st6
  double v10; // st7
  __int16 v11; // ax
  double a5; // [esp+8h] [ebp-64h]
  double a4; // [esp+10h] [ebp-5Ch]
  tagPEStatusBarItem a3; // [esp+18h] [ebp-54h]

  if ( msg == 78 )
  {
    if ( *(_DWORD *)(lParam + 8) == -202 )
    {
      gConfig.dwStatusBarColumns = 0;
      if ( IsDlgButtonChecked(hWnd, 1107) == 1 )
        gConfig.dwStatusBarColumns |= 1u;
      if ( IsDlgButtonChecked(hWnd, 1114) == 1 )
        gConfig.dwStatusBarColumns |= 2u;
      if ( IsDlgButtonChecked(hWnd, 1109) == 1 )
        gConfig.dwStatusBarColumns |= 4u;
      if ( IsDlgButtonChecked(hWnd, 1115) == 1 )
        gConfig.dwStatusBarColumns |= 8u;
      if ( IsDlgButtonChecked(hWnd, 1108) == 1 )
        gConfig.dwStatusBarColumns |= 0x10u;
      if ( IsDlgButtonChecked(hWnd, 1111) == 1 )
        gConfig.dwStatusBarColumns |= 0x20u;
      if ( IsDlgButtonChecked(hWnd, 1112) == 1 )
        gConfig.dwStatusBarColumns |= 0x40u;
      if ( IsDlgButtonChecked(hWnd, 1116) == 1 )
        gConfig.dwStatusBarColumns |= 0x80u;
      if ( IsDlgButtonChecked(hWnd, 1110) == 1 )
        gConfig.dwStatusBarColumns |= 0x100u;
      if ( IsDlgButtonChecked(hWnd, 1117) == 1 )
        gConfig.dwStatusBarColumns |= 0x200u;
      if ( IsDlgButtonChecked(hWnd, 1113) == 1 )
        gConfig.dwStatusBarColumns |= 0x400u;
      if ( IsDlgButtonChecked(hWnd, 1118) == 1 )
        gConfig.dwStatusBarColumns |= 0x800u;
      if ( IsDlgButtonChecked(hWnd, 1325) == 1 )
        gConfig.dwStatusBarColumns |= 0x1000u;
      if ( IsDlgButtonChecked(hWnd, 1119) == 1 )
        gConfig.dwStatusBarColumns |= 0x2000u;
      if ( IsDlgButtonChecked(hWnd, 1120) == 1 )
        gConfig.dwStatusBarColumns |= 0x4000u;
      memset(&a3, 0, 0x50u);
      sub_C70410(v10, v9, v8, v7, v6, v5, v4, 0, &a3, &a4, &a5);
      CMainWnd::InitStatusBar(ghWndStatusBar);
      SetEvent(ghRefreshEventHandle);
      return 1;
    }
    return 0;
  }
  if ( msg != 272 )
    return 0;
  v11 = gConfig.dwStatusBarColumns;
  if ( gConfig.dwStatusBarColumns & 1 )
  {
    CheckDlgButton(hWnd, 1107, 1u);
    v11 = gConfig.dwStatusBarColumns;
  }
  if ( v11 & 2 )
  {
    CheckDlgButton(hWnd, 1114, 1u);
    v11 = gConfig.dwStatusBarColumns;
  }
  if ( v11 & 4 )
  {
    CheckDlgButton(hWnd, 1109, 1u);
    v11 = gConfig.dwStatusBarColumns;
  }
  if ( v11 & 8 )
  {
    CheckDlgButton(hWnd, 1115, 1u);
    v11 = gConfig.dwStatusBarColumns;
  }
  if ( v11 & 0x10 )
  {
    CheckDlgButton(hWnd, 1108, 1u);
    v11 = gConfig.dwStatusBarColumns;
  }
  if ( v11 & 0x20 )
  {
    CheckDlgButton(hWnd, 1111, 1u);
    v11 = gConfig.dwStatusBarColumns;
  }
  if ( v11 & 0x40 )
  {
    CheckDlgButton(hWnd, 1112, 1u);
    v11 = gConfig.dwStatusBarColumns;
  }
  if ( (v11 & 0x80u) != 0 )
  {
    CheckDlgButton(hWnd, 1116, 1u);
    v11 = gConfig.dwStatusBarColumns;
  }
  if ( v11 & 0x100 )
  {
    CheckDlgButton(hWnd, 1110, 1u);
    v11 = gConfig.dwStatusBarColumns;
  }
  if ( v11 & 0x200 )
  {
    CheckDlgButton(hWnd, 1117, 1u);
    v11 = gConfig.dwStatusBarColumns;
  }
  if ( v11 & 0x400 )
  {
    CheckDlgButton(hWnd, 1113, 1u);
    v11 = gConfig.dwStatusBarColumns;
  }
  if ( v11 & 0x800 )
  {
    CheckDlgButton(hWnd, 1118, 1u);
    v11 = gConfig.dwStatusBarColumns;
  }
  if ( v11 & 0x1000 )
  {
    CheckDlgButton(hWnd, 1325, 1u);
    v11 = gConfig.dwStatusBarColumns;
  }
  if ( v11 & 0x2000 )
  {
    CheckDlgButton(hWnd, 1119, 1u);
    v11 = gConfig.dwStatusBarColumns;
  }
  if ( v11 & 0x4000 )
    CheckDlgButton(hWnd, 1120, 1u);
  return 1;
}

//----- (00C47810) --------------------------------------------------------
BOOL __stdcall DlgDifferenceHiliteDuration(HWND hDlg, UINT a2, WPARAM a3, LPARAM a4)
{
  BOOL result; // eax
  HWND v5; // eax
  HWND v6; // eax
  __int16 String[256]; // [esp+4h] [ebp-204h]

  if ( a2 == 272 )
  {
    wsprintf((wchar_t *)String, L"%d", (signed int)gConfig.dwHighlightDuration / 1000);
    SetDlgItemTextW(hDlg, IDC_DLG_DIFFDURATION_EDIT_SAMPLE, (LPCWSTR)String);
    v5 = GetDlgItem(hDlg, IDC_DLG_DIFFDURATION_EDIT_SAMPLE);
    SendMessageW(v5, EM_LIMITTEXT, 1u, 0);
    v6 = GetDlgItem(hDlg, IDC_DLG_DIFFDURATION_SPIN);
    SendMessageW(v6, PSM_SETCURSEL, 0, 9);
    result = 1;
  }
  else
  {
    if ( a2 == 273 )
    {
      if ( a3 == 1 )
      {
        GetDlgItemTextW(hDlg, IDC_DLG_DIFFDURATION_EDIT_SAMPLE, (LPWSTR)String, 2);
        String[2] = 0;
        gConfig.dwHighlightDuration = 1000 * _wtoi((const wchar_t *)String);
      }
      else if ( a3 != 2 )
      {
        return 0;
      }
      EndDialog(hDlg, 0);
    }
    result = 0;
  }
  return result;
}

//----- (00C47930) --------------------------------------------------------
void __cdecl sub_C47930(int a1)
{
  int v1; // eax
  signed __int16 v2; // ax

  if ( *(_DWORD *)(a1 + 720) != 3 )
  {
    memmove((void *)(a1 + 724), (const void *)(a1 + 720), 4 * *(_DWORD *)(a1 + 524));
    v1 = *(_DWORD *)(a1 + 524);
    *(_DWORD *)(a1 + 720) = 3;
    memmove((void *)(a1 + 530), (const void *)(a1 + 528), 2 * v1);
    v2 = *(_WORD *)(a1 + 520);
    if ( !v2 )
      v2 = 200;
    ++*(_DWORD *)(a1 + 524);
    *(_WORD *)(a1 + 528) = v2;
  }
}

//----- (00C479B0) --------------------------------------------------------
HBRUSH __cdecl BrushFromColor(COLORREF color, HBRUSH *BrushHandle)
{
  HBRUSH result; // eax

  if ( *BrushHandle )
    DeleteObject(*BrushHandle);
  result = CreateSolidBrush(color);
  *BrushHandle = result;
  return result;
}

//----- (00C479E0) --------------------------------------------------------
char __cdecl sub_C479E0(char a1)
{
  if ( a1
    || !gConfig.bHideWhenMinimized
    || gConfig.bShowPhysTray
     + gConfig.bShowIoTray
     + gConfig.bTrayCPUHistory
     + gConfig.bShowCommitTray
     + gConfig.bShowNetTray
     + gConfig.bShowGpuHistory
     + gConfig.bShowDiskTray != 1 )
  {
    return 0;
  }
  MessageBoxW(
    ghWndTreeListView,
    L"Because the Hide When Minimized option is selected, you must maintain at least one tray icon so that you can activat"
     "e Process Explorer when it is minimized.",
    L"Process Explorer Error",
    0x10u);
  return 1;
}

//----- (00C47A60) --------------------------------------------------------
BOOL __cdecl sub_C47A60(HWND hWnd)
{
  POINT v1; // ST00_8
  struct tagRECT Rect; // [esp+4h] [ebp-14h]

  if ( !IsWindow(hWnd) )
    return 0;
  GetWindowRect(hWnd, &Rect);
  v1.y = Rect.top + (Rect.bottom - Rect.top) / 2;
  v1.x = Rect.left + (Rect.right - Rect.left) / 2;
  return WindowFromPoint(v1) == hWnd;
}

//----- (00C47AE0) --------------------------------------------------------
int __cdecl SelectColor(HWND hWnd, COLORREF *ColorReturned)
{
  struct tagCHOOSECOLORW cc; // [esp+8h] [ebp-24h]

  cc.hInstance = (HWND)ghInstance;
  cc.rgbResult = *ColorReturned;
  cc.lStructSize = 36;
  cc.hwndOwner = hWnd;
  cc.lpCustColors = gColorCustomized;
  cc.lCustData = 0;
  cc.Flags = 1;
  if ( ChooseColorW(&cc) )
  {
    *ColorReturned = cc.rgbResult;
    InvalidateRect(ghWndTreeListView, 0, 1);
    InvalidateRect(ghWndDllsListCtrl, 0, 1);
    InvalidateRect(ghWndHandlesListCtrl, 0, 1);
    InvalidateRect(hWnd, 0, 1);
  }
  return 0;
}

//----- (00C47B70) --------------------------------------------------------
int __stdcall CMainWnd::BackendRefreshThreadProc(struct VOID *a1)
{
  char v1; // bl
  DWORD dwTimeout; // ecx
  DWORD dwRet; // esi
  DWORD v4; // ebx
  float v5; // xmm1_4
  float v6; // xmm1_4
  float v7; // xmm1_4
  float v8; // xmm1_4
  float v9; // xmm1_4
  __int16 v10; // bx
  DWORD dwTimeoutNew; // ecx
  char v13; // [esp+2h] [ebp-76h]
  char v14; // [esp+3h] [ebp-75h]
  MEMORYSTATUSEX MemoryStatusEx; // [esp+4h] [ebp-74h]
  struct _MEMORYSTATUS MemoryStatus; // [esp+44h] [ebp-34h]
  HANDLE Handles[4]; // [esp+64h] [ebp-14h]

  Handles[0] = ghRefreshEventHandle;
  Handles[1] = ghTimerRefreshEvent;
  Handles[2] = ghEvent2;
  Handles[3] = ghEvent3;
  if ( gNetClrMemoryPerfInfoLoaded )
    CoInitialize(0);
  v1 = gbFlagsInProcPropSheet;
  v13 = gbFlagsInProcPropSheet;
  SetErrorMode(SEM_FAILCRITICALERRORS);
  dwTimeout = -1;
  if ( gConfig.dwRefreshRate )
    dwTimeout = gConfig.dwRefreshRate;
  for ( dwRet = WaitForMultipleObjects(4u, Handles, 0, dwTimeout);
        dwRet != 3;
        dwRet = WaitForMultipleObjects(4u, Handles, 0, dwTimeoutNew) )
  {
    if ( dwRet == 2 )
    {
      gdwValue_4F10B8[0] = -1;
      gdwValue_4F10B8[1] = -1;
      gdwValue_4F10B8[2] = -1;
    }
    if ( gConfig.dwRefreshRate || dwRet != WAIT_TIMEOUT )
    {
      if ( ghWndSysinfoPropSheet )
        PostMessageW(ghWndSysinfoPropSheet, WM_TIMER, 0, 0);
      ++gdwRefreshCount;
      if ( v1 )
        PE_RunTrace(&gProperties, 1);
      if ( dwRet != 2 )
      {
        v4 = GetTickCount();
        if ( (signed int)(v4 - gdwRefreshTickCountLast) > 10000 )
        {
          GraphInfo_Refresh(&gIOGraphInfo);
          GraphInfo_Refresh(&gNetworkGraphInfo);
          GraphInfo_Refresh(&gDiskGraphInfo);
          gdwRefreshTickCountLast = v4;
        }
        if ( GlobalMemoryStatusEx )
        {
          MemoryStatusEx.dwLength = 64;
          GlobalMemoryStatusEx(&MemoryStatusEx);
          v5 = (double)(signed __int64)MemoryStatusEx.ullTotalPageFile;
          v6 = v5 * 0.0009765625;
          if ( v6 > gpGraphInfoOfMemory->m_dbMemorySize )
            gpGraphInfoOfMemory->m_dbMemorySize = v6;
          v7 = (double)(signed __int64)MemoryStatusEx.ullTotalPhys;
          v8 = v7 * 0.0009765625;
        }
        else
        {
          MemoryStatus.dwLength = 32;
          GlobalMemoryStatus(&MemoryStatus);
          v9 = (float)MemoryStatus.dwTotalPageFile * 0.0009765625;
          if ( v9 > gpGraphInfoOfMemory->m_dbMemorySize )
            gpGraphInfoOfMemory->m_dbMemorySize = v9;
          v8 = (float)MemoryStatus.dwTotalPhys * 0.0009765625;
        }
        if ( v8 > gpGraphInfoOfPhysicalMemory->m_dbMemorySize )
          gpGraphInfoOfPhysicalMemory->m_dbMemorySize = v8;
      }
      v10 = 0;
      v14 = 0;
      if ( dwRet != 2 )
      {
        v14 = CTreeList::InitTreeList(ghWndTreeListView, dwRet == 1);
        PulseEvent(ghTimerRefreshProcPageEventHandle);
        PostMessageW(ghWndCPUGraph, WM_USER, 0, 0);
        PostMessageW(ghWndMemoryGraph, WM_USER, 0, 0);
        PostMessageW(ghWndPhysicalMemoryGraph, WM_USER, 0, 0);
        if ( ghWndIOGraphCtrl )
          PostMessageW(ghWndIOGraphCtrl, WM_USER, 0, 0);
        if ( ghWndNetworkGraph )
          PostMessageW(ghWndNetworkGraph, WM_USER, 0, 0);
        if ( ghWndDiskGraph )
          PostMessageW(ghWndDiskGraph, WM_USER, 0, 0);
        if ( ghWndGPUGraph )
          PostMessageW(ghWndGPUGraph, WM_USER, 0, 0);
      }
      if ( !gbMainWndMinimized )
      {
        if ( gdwProcessIdSelected == -1 )
        {
          gdwValue_4F10B8[0] = -2;
          gdwValue_4F10B8[2] = -1;
          gdwValue_4F10B8[1] = -2;
          if ( gConfig.bShowDllView )
            SendMessageW(ghWndDllsListCtrl, LVM_DELETEALLITEMS, 0, 0);
          else
            SendMessageW(ghWndHandlesListCtrl, LVM_DELETEALLITEMS, 0, 0);
        }
        else if ( gConfig.bShowDllView )
        {
          HIBYTE(v10) = CMainWnd::RefreshDllsView(0, ghWndDllsListCtrl, gdwProcessIdSelected, 0);
        }
        else
        {
          LOBYTE(v10) = CMainWnd::RefreshHandlesView(0, ghWndHandlesListCtrl, gdwProcessIdSelected, 0);
        }
      }
      ++gdwRefreshCount;
      if ( v14 )
        PostMessageW(ghMainWnd, WM_TREEVIEW_SORT, IDC_TREEVIEW_LIST, (unsigned __int8)gConfig.bShowProcessTree);
      if ( (_BYTE)v10 )
        PostMessageW(ghMainWnd, WM_TREEVIEW_SORT, IDC_LISTCTRL_HANDLES, 0);
      if ( HIBYTE(v10) )
        PostMessageW(ghMainWnd, WM_TREEVIEW_SORT, IDC_LISTCTRL_DLLS, 0);
      v1 = v13;
    }
    dwTimeoutNew = -1;
    if ( gConfig.dwRefreshRate )
      dwTimeoutNew = gConfig.dwRefreshRate;
  }
  return 0;
}
// CD10B8: using guessed type int gdwValue_4F10B8[3];
// CD5390: using guessed type char gbFlagsInProcPropSheet;
// CDA098: using guessed type char gNetClrMemoryPerfInfoLoaded;
// CDA11C: using guessed type int gdwRefreshCount;
// CDA389: using guessed type char gbMainWndMinimized;
// CDA90C: using guessed type int gdwRefreshTickCountLast;
// CDF2E8: using guessed type int (__stdcall *GlobalMemoryStatusEx)(_DWORD);

//----- (00C47F60) --------------------------------------------------------
BOOL __stdcall DlgRun(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
  wchar_t *v4; // eax
  int v6; // eax
  int v7; // eax
  HANDLE v8; // eax
  HANDLE v9; // esi
  HANDLE v10; // ST28_4
  DWORD v11; // ecx
  HINSTANCE v12; // eax
  HWND v13; // eax
  LONG v14; // eax
  unsigned int v15; // esi
  struct HWND__ *v16; // eax
  struct _STARTUPINFOW StartupInfo; // [esp+Ch] [ebp-6F8h]
  struct _PROCESS_INFORMATION ProcessInformation; // [esp+50h] [ebp-6B4h]
  struct tagOFNW OpenFileName; // [esp+60h] [ebp-6A4h]
  LPARAM lParama; // [esp+B8h] [ebp-64Ch]
  int v21; // [esp+BCh] [ebp-648h]
  WCHAR *v22; // [esp+C0h] [ebp-644h]
  HANDLE TokenHandle; // [esp+E0h] [ebp-624h]
  HKEY phkResult; // [esp+E4h] [ebp-620h]
  DWORD cbData; // [esp+E8h] [ebp-61Ch]
  DWORD dwErrCode; // [esp+ECh] [ebp-618h]
  wchar_t v27[260]; // [esp+F0h] [ebp-614h]
  __int16 szText[260]; // [esp+2F8h] [ebp-40Ch]
  char Data[512]; // [esp+500h] [ebp-204h]

  *(_WORD *)Data = 0;
  memset(&Data[2], 0, 0x1FEu);
  dwErrCode = 65;
  if ( msg == WM_INITDIALOG )
  {
    SetPropW(hWnd, L"Runas", (HANDLE)lParam);
    if ( lParam == IDM_RUN_AS )
    {
      SetWindowTextW(hWnd, L"Runas");
      SetDlgItemTextW(hWnd, IDC_DLG_RUNDLG_STATIC_RUN, L"Runas:");
      SetDlgItemTextW(
        hWnd,
        IDC_DLG_RUNDLG_STATIC_TIPS,
        L"Select the program to run and then you will be prompted for alternate credentials.");
    }
    else if ( lParam == 40122 )
    {
      SetWindowTextW(hWnd, L"Run as Limited User");
      SetDlgItemTextW(hWnd, IDC_DLG_RUNDLG_STATIC_TIPS, L"Select the program to run with standard user privileges.");
    }
    v13 = GetDlgItem(hWnd, IDC_DLG_RUNDLG_COMBOBOX_PATH);
    shWndComboBoxInRunDlg = v13;
    v14 = GetWindowLongW(v13, -16);
    SetWindowLongW(shWndComboBoxInRunDlg, -16, v14 | 0x40);
    v21 = -1;
    lParama = 1;
    if ( sszCommandLine[0] )
    {
      v22 = sszCommandLine;
      SendMessageW(shWndComboBoxInRunDlg, CBEM_INSERTITEMW, 0, (LPARAM)&lParama);
    }
    SendMessageW(shWndComboBoxInRunDlg, CB_LIMITTEXT, 0x104u, 0);
    if ( !RegOpenKeyW(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\RunMRU", &phkResult) )
    {
      cbData = 512;
      RegQueryValueExW(phkResult, L"MRUList", 0, 0, (LPBYTE)Data, &cbData);
      v15 = 0;
      if ( wcslen((const unsigned __int16 *)Data) )
      {
        do
        {
          LOWORD(dwErrCode) = *(_WORD *)&Data[2 * v15];
          cbData = 520;
          if ( !RegQueryValueExW(phkResult, (LPCWSTR)&dwErrCode, 0, 0, (LPBYTE)v27, &cbData) )
          {
            if ( wcsrchr(v27, '\\') )
              *wcsrchr(v27, '\\') = 0;
            v22 = v27;
            SendMessageW(shWndComboBoxInRunDlg, CBEM_INSERTITEMW, 0, (LPARAM)&lParama);
          }
          ++v15;
        }
        while ( v15 < wcslen((const unsigned __int16 *)Data) );
      }
      RegCloseKey(phkResult);
    }
    SetFocus(shWndComboBoxInRunDlg);
    if ( gpfnSHAutoComplete )
    {
      v16 = (struct HWND__ *)SendMessageW(shWndComboBoxInRunDlg, CBEM_GETEDITCONTROL, 0, 0);
      gpfnSHAutoComplete(v16, 1u);
    }
    SendMessageW(shWndComboBoxInRunDlg, CB_SETCURSEL, 0, 0);
    SendMessageW(shWndComboBoxInRunDlg, CB_SETEDITSEL, 0, -1);
    SetFocus(shWndComboBoxInRunDlg);
    return 1;
  }
  if ( msg != WM_COMMAND )
    return 0;
  if ( wParam == 1 )
  {
    GetDlgItemTextW(hWnd, IDC_DLG_RUNDLG_COMBOBOX_PATH, sszCommandLine, 260);
    v6 = (unsigned __int16)GetPropW(hWnd, L"Runas") - 40061;
    if ( v6 )
    {
      v7 = v6 - 60;
      if ( v7 )
      {
        if ( v7 == 1 )
        {
          v8 = GetCurrentProcess();
          OpenProcessToken(v8, 0xF01FFu, &TokenHandle);
          v9 = sub_C36DB0(TokenHandle);
          if ( !v9 )
          {
            ReportMsg(L"Unable to execute process", ghMainWnd);
            return 0;
          }
          memset(&StartupInfo, 0, 0x44u);
          StartupInfo.cb = 68;
          StartupInfo.dwFlags = 1;
          StartupInfo.wShowWindow = 5;
          v10 = TokenHandle;
          _mm_storeu_si128((__m128i *)&ProcessInformation, (__m128i)0i64);
          CloseHandle(v10);
          if ( !CreateProcessAsUserW(v9, 0, sszCommandLine, 0, 0, 0, 0x10u, 0, 0, &StartupInfo, &ProcessInformation) )
          {
            ReportMsg(L"Unable to execute process", ghMainWnd);
            CloseHandle(v9);
            return 0;
          }
          SaveCmdLineToMRUList(sszCommandLine);
          EndDialog(hWnd, 0);
          CloseHandle(v9);
          return 0;
        }
        v11 = dwErrCode;
        goto LABEL_23;
      }
      v12 = ShellExecuteW(hWnd, L"runas", sszCommandLine, 0, 0, 1);
    }
    else
    {
      v12 = ShellExecuteW(hWnd, L"open", sszCommandLine, 0, 0, 1);
    }
    v11 = (DWORD)v12;
LABEL_23:
    switch ( v11 )
    {
      case 0u:
      case 8u:
        v11 = 8;
        break;
      case 1u:
      case 2u:
      case 3u:
      case 4u:
      case 6u:
      case 7u:
      case 9u:
      case 0xAu:
      case 0xBu:
      case 0xCu:
      case 0xDu:
      case 0xEu:
      case 0xFu:
      case 0x10u:
      case 0x11u:
      case 0x12u:
      case 0x13u:
      case 0x14u:
      case 0x15u:
      case 0x16u:
      case 0x17u:
      case 0x18u:
      case 0x19u:
      case 0x1Bu:
      case 0x1Cu:
      case 0x1Du:
      case 0x1Eu:
      case 0x1Fu:
        break;
      case 5u:
        v11 = 5;
        break;
      case 0x1Au:
        v11 = 32;
        break;
      case 0x20u:
        v11 = 2;
        break;
      default:
        SaveCmdLineToMRUList(sszCommandLine);
        goto LABEL_30;
    }
    SetLastError(v11);
    ReportMsg(L"Unable to execute process", ghMainWnd);
    SetFocus(shWndComboBoxInRunDlg);
    return 0;
  }
  if ( wParam != 2 )
  {
    if ( wParam == 4 )
    {
      memset(&OpenFileName, 0, 0x58u);
      OpenFileName.lStructSize = sizeof(tagOFNW);
      OpenFileName.hwndOwner = hWnd;
      OpenFileName.hInstance = ghInstance;
      OpenFileName.nMaxFile = 256;
      OpenFileName.Flags = 2097156;
      OpenFileName.lpstrTitle = L"Specify executable...";
      OpenFileName.lpstrDefExt = L"*.exe";
      OpenFileName.nFilterIndex = 1;
      OpenFileName.lpstrFilter = L"Executables";
      GetDlgItemTextW(hWnd, IDC_DLG_RUNDLG_COMBOBOX_PATH, sszCommandLine, 260);
      if ( wcschr(sszCommandLine, '\\') )
      {
        wcscpy_s((wchar_t *)szText, 0x104u, sszCommandLine);
        v4 = wcschr((const wchar_t *)szText, '\\');
        wcscpy_s(sszCommandLine, 0x104u, v4 + 1);
        wcschr((const wchar_t *)szText, '\\')[1] = 0;
        OpenFileName.lpstrInitialDir = (LPCWSTR)szText;
      }
      OpenFileName.lpstrFile = sszCommandLine;
      if ( GetOpenFileNameW(&OpenFileName) )
      {
        SetDlgItemTextW(hWnd, IDC_DLG_RUNDLG_COMBOBOX_PATH, sszCommandLine);
        return 0;
      }
    }
    return 0;
  }
LABEL_30:
  EndDialog(hWnd, 0);
  return 0;
}
// CB19EC: using guessed type wchar_t aSpecifyExecuta[22];
// CB1A18: using guessed type wchar_t aExe_0[6];
// CB1A28: using guessed type wchar_t aExecutables[12];
// CB1A6C: using guessed type wchar_t aRunas_0[6];
// CDA8F4: using guessed type int (__stdcall *gpfnSHAutoComplete)(struct HWND__ *, unsigned int);

//----- (00C485F0) --------------------------------------------------------
int __stdcall DlgSendMessage(HWND hDlg, int a2, int a3, int a4)
{
  HWND v4; // eax
  HWND v5; // eax
  unsigned int v6; // kr00_4
  WCHAR *v7; // edx
  WCHAR v8; // ax
  HWND v9; // eax
  HWND v10; // eax
  HWND v11; // eax
  HWND v13; // eax
  DWORD v14; // ST14_4
  HANDLE v15; // eax
  HWND v16; // eax
  HWND v17; // eax
  HWND v18; // eax
  DWORD pResponse; // [esp+Ch] [ebp-82Ch]
  __int16 *v20; // [esp+10h] [ebp-828h]
  char ArgList; // [esp+14h] [ebp-824h]
  wchar_t Dst; // [esp+21Ch] [ebp-61Ch]
  WCHAR pTitle; // [esp+424h] [ebp-414h]
  __int16 v24; // [esp+426h] [ebp-412h]
  WCHAR String; // [esp+62Ch] [ebp-20Ch]

  if ( a2 != 272 )
  {
    if ( a2 != 273 )
      return 0;
    if ( (unsigned __int16)a3 == 1 )
    {
      v4 = GetDlgItem(hDlg, 1302);
      GetWindowTextW(v4, &String, 260);
      v5 = GetDlgItem(hDlg, 1303);
      GetWindowTextW(v5, &pTitle, 260);
      v6 = wcslen(&String);
      v7 = &pTitle;
      v20 = &v24;
      do
      {
        v8 = *v7;
        ++v7;
      }
      while ( v8 );
      if ( !WTSSendMessageW(
              0,
              sdwSessionIdInDlgSendMessage,
              &pTitle,
              2 * (((char *)v7 - (char *)v20) >> 1),
              &String,
              2 * v6,
              0,
              0,
              &pResponse,
              0) )
        ReportMsg(L"Error sending message", ghMainWnd);
    }
    else if ( (unsigned __int16)a3 != 2 )
    {
LABEL_11:
      if ( (unsigned int)a3 >> 16 == 768 )
      {
        v9 = GetDlgItem(hDlg, 1302);
        GetWindowTextW(v9, &String, 260);
        v10 = GetDlgItem(hDlg, 1303);
        GetWindowTextW(v10, &pTitle, 260);
        if ( String && pTitle )
        {
          v11 = GetDlgItem(hDlg, 1);
          EnableWindow(v11, 1);
          return 0;
        }
        v13 = GetDlgItem(hDlg, 1);
        EnableWindow(v13, 0);
      }
      return 0;
    }
    EndDialog(hDlg, 0);
    goto LABEL_11;
  }
  sdwSessionIdInDlgSendMessage = a4;
  v14 = GetCurrentProcessId();
  v15 = GetCurrentProcess();
  QueryProcessUsers(v15, v14, 0, &Dst, 0x104u, (WCHAR *)&ArgList, 0x104u, 0, 0, 0, 0);
  swprintf(&String, L"Message from %s\\%s", &ArgList, &Dst);
  v16 = GetDlgItem(hDlg, 1303);
  SetWindowTextW(v16, &String);
  v17 = GetDlgItem(hDlg, 1302);
  SetWindowTextW(v17, (LPCWSTR)&gszNullString);
  v18 = GetDlgItem(hDlg, 1303);
  SetFocus(v18);
  return 1;
}
