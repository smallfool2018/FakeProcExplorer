
//----- (00FC79D0) --------------------------------------------------------
int __cdecl sub_FC79D0(int a1, unsigned int a2)
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

//----- (00FC7A00) --------------------------------------------------------
int __cdecl sub_FC7A00(HWND hWnd, int a2, char a3)
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
  v20 = &stru_103F3BC;
  v19 = 1;
  v18 = 0;
  if ( byte_106A09A )
    v17 = &stru_103F40C;
  else
    v17 = &stru_103F3AC;
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
      v6 = sub_FF58D0(hWnd, hWnd, &lParam, v25, &v35);
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
          v12 = sub_FF8A20(v25);
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
          sub_FB73D0(hWnd, v16);
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
// 103F40C: using guessed type GUID stru_103F40C;
// 106A09A: using guessed type char byte_106A09A;

//----- (00FC7DD0) --------------------------------------------------------
signed int __stdcall sub_FC7DD0(int (__stdcall ***a1)(_DWORD, GUID *, int *))
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
  if ( (*v2)(v1, &stru_103FBB8, &a1) || (v3 = a1) == 0 )
  {
    v11 = 0;
    v5 = *v1;
    LOBYTE(v12) = 1;
    if ( !(*v5)(v1, &stru_103FBC8, &v11) )
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
    if ( !(*v7)(v1, &stru_103FBD8, &v10) && v10 )
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
// 103FBB8: using guessed type GUID stru_103FBB8;
// 103FBC8: using guessed type GUID stru_103FBC8;
// 103FBD8: using guessed type GUID stru_103FBD8;

//----- (00FC7F10) --------------------------------------------------------
int __cdecl sub_FC7F10(int a1, LPCWSTR lpsz, int a3)
{
  wchar_t **v3; // eax
  void **v4; // edi

  *a3 = 0;
  *(a3 + 4) = 0;
  v3 = sub_FCE760(a1, lpsz);
  v4 = v3;
  if ( v3 && sub_FCECA0(v3, a3, 0) )
  {
    sub_FCEC80(v4);
    j__free(v4);
  }
  return a3;
}

//----- (00FC7F60) --------------------------------------------------------
int __thiscall sub_FC7F60(_DWORD *this)
{
  return this[7];
}

//----- (00FC7F70) --------------------------------------------------------
void __thiscall sub_FC7F70(_DWORD *this)
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

//----- (00FC7FF0) --------------------------------------------------------
signed int __stdcall sub_FC7FF0(unsigned int a1, _DWORD *a2, unsigned int *a3)
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

//----- (00FC80C0) --------------------------------------------------------
signed int __stdcall sub_FC80C0(int (__stdcall ***a1)(_DWORD, GUID *, int *), _DWORD *a2)
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

  if ( sub_FC7DD0(a1) == 1 )
  {
    v2 = 0;
    v36 = 0;
    if ( a1 )
    {
      v3 = (**a1)(a1, &stru_103FBC8, &v36);
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
          sub_FC8A30(a2, "[AppDomain Transition]", 0, 0, 1);
          v5 = v36;
          v6 = 1;
          break;
        case 4:
          sub_FC8A30(a2, "[Lightweight function]", 0, 0, 1);
          v5 = v36;
          v6 = 1;
          break;
        case 5:
          sub_FC8A30(a2, "[Func Eval]", 0, 0, 1);
          v5 = v36;
          v6 = 1;
          break;
        case 7:
          sub_FC8A30(a2, "[Class Init]", 0, 0, 1);
          v5 = v36;
          v6 = 1;
          break;
        case 8:
          sub_FC8A30(a2, "[Exception]", 0, 0, 1);
          v5 = v36;
          v6 = 1;
          break;
        case 9:
          sub_FC8A30(a2, "[Security]", 0, 0, 1);
          v5 = v36;
          v6 = 1;
          break;
        case 10:
          sub_FC8A30(a2, "[JIT Compilation]", 0, 0, 1);
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
    if ( (*v7)(a1, &stru_103FBB8, &v34) )
    {
      v6 = 0;
    }
    else
    {
      v8 = 0;
      v35 = 0;
      if ( v34 )
      {
        v9 = (**v34)(v34, &stru_103FD30, &v35);
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
            if ( (*(v12 + 56))(v39, &stru_103F3CC, &v38)
              || (*(*v38 + 120))(v38, v30, &v28, &v44, 512, &v21, &v23, &v24, &v18, &v22, &v25)
              || (*(*v38 + 48))(v38, v28, &v43, 512, &v20, &v17, &v19) )
            {
              v6 = 0;
            }
            else
            {
              sub_FC7560(&v31, a1);
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
                  sub_FC8A90(a2, &Dst, v41, 0, 0);
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
// 103F3CC: using guessed type GUID stru_103F3CC;
// 103FBB8: using guessed type GUID stru_103FBB8;
// 103FBC8: using guessed type GUID stru_103FBC8;
// 103FD30: using guessed type GUID stru_103FD30;
// 103FD40: using guessed type wchar_t aUnresolved[13];

//----- (00FC86C0) --------------------------------------------------------
int __stdcall sub_FC86C0(int a1, _DWORD *a2)
{
  *a2 = 0;
  return 0;
}

//----- (00FC86E0) --------------------------------------------------------
int *__cdecl sub_FC86E0(wchar_t *a1, int a2)
{
  int *result; // eax
  int *v3; // esi
  wchar_t Dst; // [esp+Ch] [ebp-20Ch]

  result = sub_FCED60(a2);
  v3 = result;
  if ( result )
  {
    do
    {
      if ( sub_FCE850(v3, &Dst, 0x104u) && !_wcsnicmp(a1, &Dst, wcslen(a1)) )
        break;
      if ( v3 )
        j__free(v3);
      v3 = sub_FCEE00(a2);
    }
    while ( v3 );
    result = v3;
  }
  return result;
}

//----- (00FC8790) --------------------------------------------------------
int __cdecl sub_FC8790(wchar_t *Src, wchar_t *Dst)
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

//----- (00FC87D0) --------------------------------------------------------
int __stdcall sub_FC87D0(int a1, DWORD dwThreadId, int a3, int a4, int a5)
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

//----- (00FC88A0) --------------------------------------------------------
char __thiscall sub_FC88A0(const void **this, unsigned int a2)
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
      sub_FAB650(v9);
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

//----- (00FC8940) --------------------------------------------------------
FARPROC __thiscall sub_FC8940(_DWORD *this, _DWORD *a2)
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
    if ( (result)(&stru_103F3EC, &stru_103F3DC, v2 + 6) )
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
      result = (sub_FC9500(v2, v2[8], v2[6], v11) == 0);
    }
  }
  return result;
}
// 103F3DC: using guessed type GUID stru_103F3DC;
// 103F3EC: using guessed type GUID stru_103F3EC;
// 103F440: using guessed type void *CCorDebugDataTarget::`vftable';
// 103F45C: using guessed type void *CCLRDebuggingLibraryProvider::`vftable';

//----- (00FC8A30) --------------------------------------------------------
int __thiscall sub_FC8A30(_DWORD *this, int a2, int a3, int a4, int a5)
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

//----- (00FC8A90) --------------------------------------------------------
int __thiscall sub_FC8A90(_DWORD *this, int a2, int a3, int a4, int a5)
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

//----- (00FC8AE0) --------------------------------------------------------
void __thiscall sub_FC8AE0(int *this, unsigned int a2, int *a3, unsigned int a4)
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
      if ( !sub_FC9B80(this, a2 + a4, -1) )
        ATL::AtlThrowImpl(-2147024882);
      goto LABEL_16;
    }
LABEL_5:
    ATL::AtlThrowImpl(-2147024362);
  }
  v20 = v5;
  if ( -1 - v5 < a4 )
    goto LABEL_5;
  if ( !sub_FC9B80(this, v5 + a4, -1) )
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
  sub_FAB650(v14);
  v15 = (4 * a2 + *v4);
  v25 = 0;
  sub_FC79A0(v15, a4);
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
// 10081AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);

//----- (00FC8C80) --------------------------------------------------------
int (__stdcall ***__stdcall sub_FC8C80(int (__stdcall ***a1)(_DWORD, GUID *, int *)))(_DWORD, GUID *, int *)
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
    v2 = (**a1)(a1, &stru_103FBC8, &v7);
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
// 103FBC8: using guessed type GUID stru_103FBC8;

//----- (00FC8D10) --------------------------------------------------------
signed int __thiscall sub_FC8D10(_DWORD *this, int a2)
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

//----- (00FC8DE0) --------------------------------------------------------
BOOL __cdecl sub_FC8DE0(int a1)
{
  return !(*(*a1 + 44))(a1, &a1) && (a1 == 6 || a1 == 7 || a1 == 8 || a1 == 9 || a1 == 10);
}

//----- (00FC8E20) --------------------------------------------------------
int __thiscall sub_FC8E20(void *this, int a2, int a3, int *a4, _DWORD *a5, _DWORD *a6, int a7, unsigned int a8, unsigned int *a9)
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
    if ( sub_FC7DD0(*v30) == 1 )
    {
      if ( *a9 < a8 )
        ++*a9;
      v11 = sub_FC8C80(*v30);
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
        v10 = (***(v13 + 4 * v14))(*(v13 + 4 * v14), &stru_103FBC8, &v34) == 0;
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
    if ( (***(v29 + 4 * v20))(*(v29 + 4 * v20), &stru_103FBC8, &v35) )
      goto LABEL_42;
    if ( !sub_FC8DE0(v35) )
      break;
    LOBYTE(v41) = 1;
    if ( v35 )
      ((*v35)[2])(v35);
    if ( ++*a9 >= a8 )
      goto LABEL_92;
  }
  sub_FC7520(&v32, v35);
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
    if ( sub_FC8C80(v35) != 1 )
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
        sub_FC7600(&v34, v35);
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
  sub_FC7600(&v34, *(v29 + 4 * *a9));
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
// 10081AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);
// 103FBC8: using guessed type GUID stru_103FBC8;

//----- (00FC9500) --------------------------------------------------------
signed int __thiscall sub_FC9500(_DWORD *this, int a2, int a3, int a4)
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
       || (*(*a3 + 12))(a3, me.modBaseAddr, me.modBaseAddr >> 31, v9, v10, &v13, &stru_103FBA8, v4 + 7, &v12, &v8) )
  {
    if ( !Module32NextW(v6, &me) )
      goto LABEL_6;
  }
  CloseHandle(v6);
  return 0;
}
// 103FBA8: using guessed type GUID stru_103FBA8;

//----- (00FC9620) --------------------------------------------------------
signed int __stdcall sub_FC9620(int a1, int a2, int a3, int a4, HMODULE *a5)
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
      sub_FCA440(&LibFileName, 0x105u, me.szExePath, v8 - v9);
      v5 = 1;
LABEL_11:
      CloseHandle(v6);
      if ( !v5 )
        return -2147467259;
      sub_FCA3A0(&LibFileName, 0x105u, a2);
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

//----- (00FC9780) --------------------------------------------------------
signed int __stdcall sub_FC9780(int a1, _DWORD *a2, _DWORD *a3)
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
  v9 = &stru_103F3FC;
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
// 103F3FC: using guessed type GUID stru_103F3FC;
// 1047BBC: using guessed type GUID CLSID_IUnknown;

//----- (00FC9800) --------------------------------------------------------
signed int __stdcall sub_FC9800(int a1, _DWORD *a2, _DWORD *a3)
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
  v9 = &stru_103FB98;
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
// 103FB98: using guessed type GUID stru_103FB98;
// 1047BBC: using guessed type GUID CLSID_IUnknown;

//----- (00FC9880) --------------------------------------------------------
signed int __stdcall sub_FC9880(int a1, _DWORD *a2, _DWORD *a3)
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
// 1047BBC: using guessed type GUID CLSID_IUnknown;

//----- (00FC98D0) --------------------------------------------------------
signed int __stdcall sub_FC98D0(int a1, int a2, int a3)
{
  return -2147467262;
}

//----- (00FC98E0) --------------------------------------------------------
int __stdcall sub_FC98E0(int a1, LPCVOID lpBaseAddress, int a3, LPVOID lpBuffer, SIZE_T nSize, SIZE_T *lpNumberOfBytesRead)
{
  return ReadProcessMemory(*(a1 + 8), lpBaseAddress, lpBuffer, nSize, lpNumberOfBytesRead) != 1 ? 0x80004005 : 0;
}

//----- (00FC9910) --------------------------------------------------------
int __stdcall sub_FC9910(void *a1)
{
  bool v1; // zf

  v1 = (*(a1 + 1))-- == 1;
  if ( !v1 )
    return *(a1 + 1);
  j__free(a1);
  return 0;
}

//----- (00FC9940) --------------------------------------------------------
int __stdcall sub_FC9940(_DWORD *a1)
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

//----- (00FC9960) --------------------------------------------------------
int __stdcall sub_FC9960(void *a1)
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
// 103F430: using guessed type void *NativeFrame::`vftable';

//----- (00FC99B0) --------------------------------------------------------
int __stdcall sub_FC99B0(void *a1)
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
// 103F420: using guessed type void *SymbolInfo::`vftable';

//----- (00FC9A00) --------------------------------------------------------
int __cdecl sub_FC9A00(void *Dst, void *Src, int a3)
{
  int v3; // eax

  v3 = memmove_s(Dst, 4 * a3, Src, 4 * a3);
  return sub_FAB650(v3);
}

//----- (00FC9A30) --------------------------------------------------------
_DWORD *__thiscall sub_FC9A30(_DWORD *this)
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
      sub_FC9A30(v1);
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

//----- (00FC9AC0) --------------------------------------------------------
_DWORD *__thiscall sub_FC9AC0(int *this, _DWORD *a2)
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
    sub_FC9A30(v2);
  return a2;
}

//----- (00FC9B40) --------------------------------------------------------
int __stdcall sub_FC9B40(DWORD dwThreadId)
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

//----- (00FC9B80) --------------------------------------------------------
char __thiscall sub_FC9B80(int this, unsigned int a2, int a3)
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
      result = sub_FC88A0(this, a2);
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
          sub_FC79D0(*v3 + 4 * a2, v9 - a2);
          *(v3 + 4) = a2;
          return 1;
        }
        goto LABEL_18;
      }
    }
    sub_FC79A0((*v3 + 4 * v9), a2 - v9);
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

//----- (00FC9C50) --------------------------------------------------------
int __thiscall sub_FC9C50(_DWORD *this, int a2, int a3, int a4)
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
            result = sub_FC80C0(v8, v10);
            if ( result )
            {
              v11 = *(a4 + 4);
              v59 = v11;
              if ( v11 >= *(a4 + 8) && !sub_FC88A0(a4, v11 + 1) )
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
      sub_FC9AC0(v4, &v59);
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
      if ( v17 >= *(a4 + 8) && !sub_FC88A0(a4, v17 + 1) )
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
      sub_FC9AC0(v4, &v53);
      v24 = v53;
      while ( 1 )
      {
        v60 = 0;
        v25 = *v22;
        LOBYTE(v63) = 8;
        if ( (*v25)(v22, &stru_103FC40, &v60) )
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
        if ( sub_FC80C0(v22, v27) )
        {
          v28 = v59;
          v29 = *(v59 + 4);
          v58 = v29;
          if ( v29 >= *(v59 + 8) )
          {
            if ( !sub_FC88A0(v59, v29 + 1) )
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
      if ( v38 >= *(v59 + 8) && !sub_FC88A0(v59, v38 + 1) )
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
      result = sub_FC80C0(v44, v48);
      if ( result )
      {
        v49 = *(v5 + 4);
        v58 = v49;
        if ( v49 >= *(v5 + 8) && !sub_FC88A0(v5, v49 + 1) )
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
// 103F420: using guessed type void *SymbolInfo::`vftable';
// 103FC40: using guessed type GUID stru_103FC40;

//----- (00FCA3A0) --------------------------------------------------------
signed int __stdcall sub_FCA3A0(_WORD *a1, unsigned int a2, int a3)
{
  signed int result; // eax
  _WORD *v4; // eax
  unsigned int v5; // edx
  signed int v6; // ecx
  int v7; // edi
  __int16 v8; // si
  int v9; // [esp+8h] [ebp-4h]

  result = sub_FCA500(a1, a2, &v9, 0x7FFFFFFFu);
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

//----- (00FCA440) --------------------------------------------------------
signed int __stdcall sub_FCA440(_WORD *a1, unsigned int a2, int a3, unsigned int a4)
{
  signed int result; // eax

  result = 0;
  if ( !a2 || a2 > 0x7FFFFFFF )
    result = -2147024809;
  if ( result >= 0 )
  {
    if ( a4 <= 0x7FFFFFFE )
    {
      result = sub_FCA490(a1, a2, 0, a3, a4);
    }
    else
    {
      *a1 = 0;
      result = -2147024809;
    }
  }
  return result;
}

//----- (00FCA490) --------------------------------------------------------
signed int __stdcall sub_FCA490(_WORD *a1, int a2, _DWORD *a3, int a4, int a5)
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

//----- (00FCA500) --------------------------------------------------------
signed int __stdcall sub_FCA500(_WORD *a1, unsigned int a2, _DWORD *a3, unsigned int a4)
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

//----- (00FCA570) --------------------------------------------------------
HANDLE __thiscall sub_FCA570(void *this, DWORD dwThreadId, int a3, int a4, int a5, int a6, int a7)
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
      sub_FDDD60(1, v9, &v32, v7[3], 0, 0, *(v12 + 20), *(v12 + 16));
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
        sub_FC7F70(a7);
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
// 103F430: using guessed type void *NativeFrame::`vftable';

//----- (00FCA870) --------------------------------------------------------
char __cdecl sub_FCA870(int a1, WPARAM wParam)
{
  char v2; // bl
  wchar_t *v3; // eax
  int v4; // esi
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
  PE_PerfInfo v78; // [esp+2Ch] [ebp-250h]
  int v79[2]; // [esp+3Ch] [ebp-240h]
  int v80; // [esp+44h] [ebp-238h]
  unsigned int v81; // [esp+4Ch] [ebp-230h]
  int v82; // [esp+54h] [ebp-228h]
  int v83; // [esp+58h] [ebp-224h]
  void *v84[2]; // [esp+60h] [ebp-21Ch]
  void *v85; // [esp+68h] [ebp-214h]
  void *v86; // [esp+6Ch] [ebp-210h]
  wchar_t Dst; // [esp+70h] [ebp-20Ch]
  __int16 v88; // [esp+8Ch] [ebp-1F0h]

  v2 = 0;
  if ( !*(a1 + 1284) )
    return 0;
  wcscpy_s(&Dst, 0x104u, *(a1 + 60));
  v3 = wcsrchr(&Dst, 0x2Eu);
  if ( v3 && v3 != &Dst )
    *v3 = 0;
  v4 = *(a1 + 1284);
  v82 = *(a1 + 1284);
  v88 = 0;
  unknown_libname_3(&v78, &gPerformanceInfoInMemory, &gPerformanceInfo);
  v5 = PE_PerfInfo::Load(&v78, L".NET CLR Jit");
  v6 = wParam;
  v85 = v5;
  if ( v5 )
  {
    v7 = sub_FC86E0(&Dst, v5);
    v86 = v7;
    if ( v7 )
    {
      v8 = sub_FC7F10(v7, L"# of methods Jitted", &v83);
      v9 = ghWndTreeListView;
      v10 = sub_FFF920(*v8, *v8 >> 32, v4);
      v11 = RedrawColumn(v10, v9, 1094, wParam);
      sub_FC7F10(v86, L"% time in JIT", &v80);
      v84[1] = sub_FCE840(v86);
      sub_FCECA0(v84[1], &v81, 0);
      v12 = 0.0;
      if ( v81 != 0.0 )
        v12 = v80 * 100.0 / v81;
      v13 = ghWndTreeListView;
      v14 = sub_FFF8F0(v12, (v4 + 8));
      v2 = RedrawColumn(v14, v13, 1095, wParam) | v11;
      if ( v84[1] )
      {
        sub_FCEC80(v84[1]);
        j__free(v84[1]);
      }
      j__free(v86);
    }
    j__free(v85);
  }
  v15 = PE_PerfInfo::Load(&v78, L".NET CLR Loading");
  v85 = v15;
  if ( v15 )
  {
    v16 = sub_FC86E0(&Dst, v15);
    v86 = v16;
    if ( v16 )
    {
      v17 = sub_FC7F10(v16, L"Current AppDomains", &v83);
      v18 = ghWndTreeListView;
      v19 = sub_FFF920(*v17, *v17 >> 32, (v4 + 16));
      v20 = RedrawColumn(v19, v18, 1096, wParam) | v2;
      v21 = sub_FC7F10(v86, L"Current Assemblies", &v83);
      v22 = ghWndTreeListView;
      v23 = sub_FFF920(*v21, *v21 >> 32, (v4 + 48));
      v24 = RedrawColumn(v23, v22, 1097, wParam) | v20;
      v25 = sub_FC7F10(v86, L"Current Classes Loaded", &v83);
      v26 = ghWndTreeListView;
      v27 = sub_FFF920(*v25, *v25 >> 32, (v4 + 32));
      v28 = RedrawColumn(v27, v26, 1098, wParam) | v24;
      v29 = sub_FC7F10(v86, L"Total AppDomains", &v83);
      v30 = ghWndTreeListView;
      v31 = sub_FFF920(*v29, *v29 >> 32, (v4 + 24));
      v32 = RedrawColumn(v31, v30, 1099, wParam) | v28;
      v33 = sub_FC7F10(v86, L"Total Assemblies", &v83);
      v34 = ghWndTreeListView;
      v35 = sub_FFF920(*v33, *v33 >> 32, (v4 + 56));
      v36 = RedrawColumn(v35, v34, 1100, wParam) | v32;
      v37 = sub_FC7F10(v86, L"Total Classes Loaded", &v83);
      v38 = ghWndTreeListView;
      v39 = sub_FFF920(*v37, *v37 >> 32, (v4 + 40));
      v2 = RedrawColumn(v39, v38, 1101, wParam) | v36;
      j__free(v86);
    }
    j__free(v85);
  }
  v40 = PE_PerfInfo::Load(&v78, L".NET CLR LocksAndThreads");
  v84[1] = v40;
  if ( v40 )
  {
    v41 = sub_FC86E0(&Dst, v40);
    v85 = v41;
    if ( v41 )
    {
      v42 = sub_FC7F10(v41, L"Total # of contentions", &v83);
      v43 = ghWndTreeListView;
      v44 = sub_FFF920(*v42, *v42 >> 32, (v4 + 128));
      v2 |= RedrawColumn(v44, v43, 1110, wParam);
      j__free(v85);
    }
    j__free(v84[1]);
  }
  v45 = PE_PerfInfo::Load(&v78, L".NET CLR Memory");
  v85 = v45;
  if ( v45 )
  {
    v46 = sub_FC86E0(&Dst, v45);
    v86 = v46;
    if ( v46 )
    {
      v47 = sub_FC7F10(v46, L"# bytes in all heaps", &v83);
      v48 = ghWndTreeListView;
      v49 = sub_FFF920(*v47, *v47 >> 32, (v4 + 112));
      v50 = RedrawColumn(v49, v48, 1103, wParam) | v2;
      v51 = sub_FC7F10(v86, L"# Gen 0 collections", &v83);
      v52 = ghWndTreeListView;
      v53 = sub_FFF920(*v51, *v51 >> 32, (v4 + 64));
      v54 = RedrawColumn(v53, v52, 1104, wParam) | v50;
      v55 = sub_FC7F10(v86, L"# Gen 1 collections", &v83);
      v56 = ghWndTreeListView;
      v57 = sub_FFF920(*v55, *v55 >> 32, (v4 + 72));
      v58 = RedrawColumn(v57, v56, 1105, wParam) | v54;
      v59 = sub_FC7F10(v86, L"# Gen 2 collections", &v83);
      v60 = ghWndTreeListView;
      v61 = sub_FFF920(*v59, *v59 >> 32, (v4 + 80));
      v62 = RedrawColumn(v61, v60, 1106, wParam) | v58;
      sub_FC7F10(v86, L"Allocated bytes/sec", v79);
      v63 = v79[1];
      *v84 = *v79;
      *v84 = *v79 - *(v82 + 96);
      v64 = (*v84 / ((*&gLoadNetClrMemoryPerfInfoTime - *&gLoadNetClrMemoryPerfInfoTimeLast) / 10000000.0));
      v65 = v64;
      LODWORD(v64) = v82;
      *(v82 + 96) = v79[0];
      v4 = v64;
      *(v64 + 100) = v63;
      v6 = wParam;
      v66 = ghWndTreeListView;
      v67 = sub_FFF920(v65, SHIDWORD(v64), (v64 + 104));
      v68 = RedrawColumn(v67, v66, 1108, wParam) | v62;
      sub_FC7F10(v86, L"% time in GC", &v80);
      v84[1] = sub_FCE840(v86);
      sub_FCECA0(v84[1], &v81, 0);
      v69 = 0.0;
      if ( v81 != 0.0 )
        v69 = v80 * 100.0 / v81;
      v70 = ghWndTreeListView;
      v71 = sub_FFF8F0(v69, (v4 + 88));
      v2 = RedrawColumn(v71, v70, 1107, wParam) | v68;
      if ( v84[1] )
      {
        sub_FCEC80(v84[1]);
        j__free(v84[1]);
      }
      j__free(v86);
    }
    j__free(v85);
  }
  v72 = PE_PerfInfo::Load(&v78, L".NET CLR Security");
  v84[1] = v72;
  if ( v72 )
  {
    v73 = sub_FC86E0(&Dst, v72);
    v85 = v73;
    if ( v73 )
    {
      v74 = sub_FC7F10(v73, L"Total runtime checks", &v83);
      v75 = ghWndTreeListView;
      v76 = sub_FFF920(*v74, *v74 >> 32, (v4 + 120));
      v2 |= RedrawColumn(v76, v75, 1109, v6);
      j__free(v85);
    }
    j__free(v84[1]);
  }
  return v2;
}
// 103CDC0: using guessed type double db_onehundred;
// 106A0A8: using guessed type struct _FILETIME gLoadNetClrMemoryPerfInfoTimeLast;

//----- (00FCB0A0) --------------------------------------------------------
int __thiscall sub_FCB0A0(_DWORD *this, DWORD dwThreadId, int a3)
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
  result = sub_FC8D10(this, dwThreadId);
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
    v13 = (**v53)(v53, &stru_103FC50, &v58);
    v12 = v58;
    if ( v13 < 0 )
      v12 = 0;
    v58 = v12;
  }
  if ( !v12 )
  {
    sub_FC9B40(dwThreadId);
    v9 = 0;
    goto LABEL_70;
  }
  v54 = 0;
  v14 = *v12;
  LOBYTE(v62) = 2;
  if ( (*(v14 + 12))(v12, &v54) )
  {
    sub_FC9B40(dwThreadId);
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
  if ( !sub_FC7FF0(v58, &v41, &v42) )
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
          v17 = (**v15)(v15, &stru_103FC60, &v56);
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
      v20 = sub_FC8E20(v3, v58, v54, &v55, &v46, &v51, v41, v42, &v48);
      v15 = v55;
      v49 = v55;
      if ( v20 )
      {
        if ( v16 )
          break;
      }
      if ( v20 != 1 )
      {
        sub_FCA570(v3, dwThreadId, &v61, 716, -1, 0x7FFFFFFF, &v35);
        sub_FC9C50(v3, &v29, &v35, v52);
        sub_FC9A30(&v35);
        sub_FC9B40(dwThreadId);
        sub_FC77E0(v52);
        v9 = 1;
        goto LABEL_63;
      }
      if ( !sub_FCB680(v3, dwThreadId, v55, v54, &v29, &v35, &v43, &v60, &v44, &v61, v28, v52) )
      {
        sub_FC9B40(dwThreadId);
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
  v21 = (**v16)(v16, &stru_103FC60, &v59);
  v22 = v59;
  if ( v21 < 0 )
    v22 = 0;
  v59 = v22;
  v57 = 0;
  v23 = *v15;
  LOBYTE(v62) = 10;
  v24 = (*v23)(v15, &stru_103FC60, &v57);
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
  sub_FC9A30(&v35);
  sub_FC9A30(&v29);
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
// 103FC50: using guessed type GUID stru_103FC50;
// 103FC60: using guessed type GUID stru_103FC60;

//----- (00FCB680) --------------------------------------------------------
int __thiscall sub_FCB680(_DWORD *this, DWORD dwThreadId, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12)
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
    v13 = sub_FC7DD0(a3);
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
          sub_FCA570(v12, dwThreadId, a10, 716, *v17, v17[1], a6);
        v19 = v18;
        v20 = a5;
        sub_FC9C50(v12, a5, v19, a12);
        v21 = a6;
        *a9 = 0;
        sub_FC9A30(v21);
        sub_FC9A30(v20);
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
        v25 = sub_FC7DD0(a3);
        if ( v25 && (v26 = v25 - 1) != 0 )
        {
          if ( v26 != 2 )
            goto LABEL_22;
          sub_FC8A30(v23, "[Native Frame: IL Method without Metadata]", 0, 0, 3);
        }
        else if ( !sub_FC80C0(a3, v23) )
        {
          goto LABEL_22;
        }
        sub_FC76F0(a12, &a9);
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
      sub_FC7740(a5, &a12);
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
// 103F420: using guessed type void *SymbolInfo::`vftable';

//----- (00FCB8A0) --------------------------------------------------------
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
// 106A098: using guessed type char gNetClrMemoryPerfInfoLoaded;
// 106A0A8: using guessed type struct _FILETIME gLoadNetClrMemoryPerfInfoTimeLast;

//----- (00FCB9D0) --------------------------------------------------------
void *__cdecl sub_FCB9D0(int a1)
{
  void *v1; // esi
  int v3; // [esp+0h] [ebp-Ch]
  int v4; // [esp+4h] [ebp-8h]
  LPVOID ppv; // [esp+8h] [ebp-4h]

  if ( !gNetClrMemoryPerfInfoLoaded )
    return 0;
  v3 = 0;
  if ( byte_106A09A )
    CoCreateInstance(&stru_103F40C, 0, 1u, &stru_103F3BC, &ppv);
  else
    CoCreateInstance(&stru_103F3AC, 0, 1u, &stru_103F3BC, &ppv);
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
// 103F40C: using guessed type GUID stru_103F40C;
// 106A098: using guessed type char gNetClrMemoryPerfInfoLoaded;
// 106A09A: using guessed type char byte_106A09A;

//----- (00FCBA80) --------------------------------------------------------
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
        v28 = dword_106A0CC;
        v29 = GetDlgItem(hWnd, 1094);
        sub_FC7A00(v29, v28, 0);
        PerformanceInfoInMemory::Load(*(v5 + 804), 0, (v5 + 28));
        unknown_libname_3(&v46, *(v5 + 804), &gPerformanceInfo);
        v30 = PE_PerfInfo::Load(&v46, (v5 + 28));
        if ( v30 )
        {
          pDrawItemStruct = sub_FC86E0((v5 + 284), v30);
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
              if ( pDrawItemStruct && sub_FC7F10(pDrawItemStruct, &sz, v54) )
              {
                v33 = sub_FCE760(pDrawItemStruct, &sz);
                v34 = v33;
                if ( v33 && v33[1] & 0x20000 )
                {
                  v34 = sub_FCE840(pDrawItemStruct);
                  sub_FCECA0(v34, &v50, 0);
                  v35 = 0.0;
                  if ( v50 != 0.0 )
                    v35 = *v54 * 100.0 / v50;
                  sub_FC7500(&Dst, L"%02.02f", LODWORD(v35), HIDWORD(v35));
                }
                else
                {
                  sub_FC7500(&Dst, L"%I64d", *v54, v55);
                  sub_FC3290(&Dst, 0x80u);
                }
                if ( v34 )
                {
                  sub_FCEC80(v34);
                  j__free(v34);
                }
                v31 = v57;
              }
              else
              {
                sub_FC7500(&Dst, L"0");
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
        v23 = sub_FCED60(v22);
        v57 = v23;
        if ( v23 )
        {
          v24 = sub_FCE830(v23);
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
                  sub_FF7F90(*(v5 + 16), &Dst, &gszNullString);
              }
              sub_FCEC80(v24);
              j__free(v24);
              v24 = sub_FCE840(v25);
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
    CTreeView::InitListHeader(*(v9 + 6), &pnIDs, pnWidths, 1u);
    v13 = *(v9 + 6);
    dword_106A0CC = pDrawItemStruct[1].hwndItem;
    sub_FC7A00(v13, dword_106A0CC, 1);
    SendMessageW(*(v9 + 6), 0x101Eu, 0, 65534);
    sub_FC8790(pDrawItemStruct[1].itemAction, v9 + 142);
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
    CTreeView::InitListHeader(*(v9 + 4), &v48, v53, 2u);
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
// 103CDC0: using guessed type double db_onehundred;
// 103F4BC: using guessed type wchar_t aNetClrExceptio[20];
// 103F518: using guessed type wchar_t aNetClrData[14];
// 103F534: using guessed type wchar_t aNetClrInterop[17];
// 103F57C: using guessed type wchar_t aNetClrRemoting[18];
// 103F5C4: using guessed type wchar_t aNotDisplayed[14];

//----- (00FCC500) --------------------------------------------------------
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
// 106A098: using guessed type char gNetClrMemoryPerfInfoLoaded;
// 106A0A8: using guessed type struct _FILETIME gLoadNetClrMemoryPerfInfoTimeLast;

//----- (00FCC540) --------------------------------------------------------
char __cdecl sub_FCC540(int a1, WPARAM wParam)
{
  char result; // al

  result = 0;
  if ( !byte_106A099 )
    result = sub_FCA870(a1, wParam);
  return result;
}
// 106A099: using guessed type char byte_106A099;

//----- (00FCC600) --------------------------------------------------------
CSystemProcessInfoMapNode *__thiscall std::_Tree_comp_alloc<std::_Tmap_traits<unsigned long,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *>>,0>>::_Buynode<std::piecewise_construct_t const &,std::tuple<unsigned long &&>,std::tuple<>>(CSystemProcessInfoMap *this, CSystemProcessInfoMapPair *a1)
{
  CSystemProcessInfoMapNode *result; // eax

  result = std::_Tree_comp_alloc<std::_Tmap_traits<unsigned long,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const,_SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION *>>,0>>::_Buynode0(this);
  *&result->baseclass._Color = 0;
  if ( result != -16 )
    result->_Keyvalue = *a1;
  return result;
}

//----- (00FCC630) --------------------------------------------------------
CSystemProcessInfoMapNode **__thiscall sub_FCC630(CSystemProcessInfoMap *thisMap, CSystemProcessInfoMapNode **ppNode, char a3, CSystemProcessInfoMapNode *pNode, CSystemProcessInfoMapPair *pair, int a6)
{
  CSystemProcessInfoMap *this; // edi
  CSystemProcessInfoMapNode *v7; // eax
  CSystemProcessInfoMapNode *v8; // ebx
  std__Tree_node *v9; // eax
  std__Tree_node *v10; // eax
  std__Tree_node *v11; // ecx
  std__Tree_node *v12; // esi
  std__Tree_node *v13; // edx
  std__Tree_node *v14; // edx
  std__Tree_node *v15; // ecx
  std__Tree_node *v16; // edx
  std__Tree_node *v17; // esi
  std__Tree_node_For__bstr_t *v18; // ecx
  std__Tree_node *v19; // ecx
  std__Tree_node *v20; // edx
  std__Tree_node_For__bstr_t *v21; // ecx
  std__Tree_node *v22; // ecx
  std__Tree_node *v23; // ecx
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

//----- (00FCC840) --------------------------------------------------------
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
      v13 = sub_FCC630(v5, &a3, 1, v9, dwThreadId, a5);
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
    v13 = sub_FCC630(v5, &dwThreadId, v19, v9, v8, a5);
    goto LABEL_14;
  }
  *a2 = v12;
  result = a2;
  *(a2 + 4) = 0;
  return result;
}
// 10081AA: using guessed type void __stdcall __noreturn _CxxThrowException(_DWORD, _DWORD);

//----- (00FCCA10) --------------------------------------------------------
signed int __stdcall LogBufferCallback(int a1)
{
  return 1;
}

//----- (00FCCA20) --------------------------------------------------------
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
          byte_106A100);
      }
      while ( Thread32Next(hFound_1, &ThreadEntry) );
    }
    hFound = CloseHandle(hFound_1);
  }
  return hFound;
}
// 106A100: using guessed type char byte_106A100;

//----- (00FCCAB0) --------------------------------------------------------
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
// 1040784: using guessed type wchar_t aProcexpTrace[14];
// 1064E54: using guessed type int gdwVersion;

//----- (00FCCBD0) --------------------------------------------------------
ULONG __stdcall TraceEventThreadProcEx(EVENT_TRACE_PROPERTIES_EXT *a1)
{
  return TraceEventThreadProc(a1);
}

//----- (00FCCBE0) --------------------------------------------------------
__int64 __thiscall PE_ComputeTime(PE_TIME *this, __int64 time)
{
  __int64 result; // rax

  if ( time >= 0 )
    result = (10000000 * (time % this->Frequency)) / this->Frequency + 10000000 * (time / this->Frequency);
  else
    result = -PE_ComputeTime(this, -time);
  return result;
}

//----- (00FCCC70) --------------------------------------------------------
unsigned __int8 *__cdecl sub_FCCC70(int a1, int a2, int a3, wchar_t *Dst, rsize_t SizeInWords)
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
        if ( dword_105E0D0 == 64 )
          v31 = (a1 + 16);
        else
          v31 = (a1 + 8);
        v32 = 4 * v31[1] + 8;
        sub_FCE4E0(&a1, v31);
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
      if ( dword_105E0D0 == 64 )
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
      sub_F992A0(Dst, SizeInWords, a1);
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
// 103E200: using guessed type wchar_t a0x08x[7];
// 105E0D0: using guessed type int dword_105E0D0;

//----- (00FCD220) --------------------------------------------------------
ULONG __thiscall PE_FlushTrace(LPEVENT_TRACE_PROPERTIES_EXT Properties)
{
  return FlushTraceW(Properties->TraceHandle, 0, &Properties->baseclass);
}

//----- (00FCD240) --------------------------------------------------------
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

//----- (00FCD2B0) --------------------------------------------------------
std__Tree_node *__cdecl sub_FCD2B0(unsigned int a1)
{
  std__Tree_node *v1; // ecx
  std__Tree_node *v2; // eax
  std__Tree_node *result; // eax
  std__Tree_node *v4; // [esp+4h] [ebp-4h]

  v1 = gThreadProcessMap._Header;
  v2 = gThreadProcessMap._Header->_Parent;
  if ( v2->_IsNil )
    goto LABEL_14;
  do
  {
    if ( v2[1]._Left >= a1 )
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

//----- (00FCD310) --------------------------------------------------------
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
    _mm_storeu_si128(&Properties->baseclass.Wnode.Guid, _mm_loadu_si128(&stru_10400E0));
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
// 10400E0: using guessed type GUID stru_10400E0;
// 1040784: using guessed type wchar_t aProcexpTrace[14];
// 1064E54: using guessed type int gdwVersion;

//----- (00FCD510) --------------------------------------------------------
void __cdecl sub_FCD510(EVENT_TRACE *EventTrace, EventList *Param)
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
            if ( dword_105E0D0 == 64 )
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
            if ( dword_105E0D0 == 64 )
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
              ProcessId = sub_FCD2B0(v31);
            goto LABEL_69;
          default:
LABEL_34:
            psz[0] = 0;
            v15 = (v15 + sub_FCCC70(v15, v13->MofData + v13->MofLength, v17, psz, 0x400u));
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
  sub_FF5250(&ProcessId);
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
// 10406FC: using guessed type NetworkMsgItem gReadWriteMsgItem[3];
// 105E0D0: using guessed type int dword_105E0D0;

//----- (00FCDB10) --------------------------------------------------------
void __stdcall LogEventCallback(PEVENT_TRACE EventTrace)
{
  _bstr_t *v1; // eax

  if ( EventTrace )
  {
    v1 = sub_F98730(
           &gWbemServiceList,
           &EventTrace->Header.u3.Guid,
           EventTrace->Header.u2.Class.Type,
           EventTrace->Header.u2.Class.Version,
           EventTrace->Header.u2.Class.Level);
    if ( v1 )
      sub_FCDB50(EventTrace, v1);
  }
}

//----- (00FCDB50) --------------------------------------------------------
void __cdecl sub_FCDB50(EVENT_TRACE *EventTrace, EventList *a2)
{
  EventListNode *v2; // esi
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
    v2 = a2->_Myheader;
    if ( a2->_Myheader )
      v3 = v2->field_0;
    else
      v3 = 0;
    v4 = wcscmp(v3, L"DiskIo");
    if ( v4 )
      v4 = -(v4 < 0) | 1;
    if ( v4 )
    {
      if ( v2 )
        v5 = v2->field_0;
      else
        v5 = 0;
      v6 = wcscmp(v5, L"Thread");
      if ( v6 )
        v6 = -(v6 < 0) | 1;
      if ( v6 )
      {
        if ( v2 )
          v7 = v2->field_0;
        else
          v7 = 0;
        v8 = wcscmp(v7, L"TcpIp");
        if ( v8 )
          v8 = -(v8 < 0) | 1;
        if ( !v8 )
          goto LABEL_38;
        if ( v2 )
          v9 = v2->field_0;
        else
          v9 = 0;
        v10 = wcscmp(v9, L"UdpIp");
        if ( v10 )
          v10 = -(v10 < 0) | 1;
        if ( !v10 )
          goto LABEL_38;
        v11 = (v2 ? v2->field_0 : 0);
        v12 = wcscmp(v11, L"MSNT_TcpIpInformation");
        if ( v12 )
          v12 = -(v12 < 0) | 1;
        if ( !v12 )
LABEL_38:
          sub_FCDCE0(EventTrace, a2);
      }
      else
      {
        sub_FCE310(EventTrace, a2);
      }
    }
    else
    {
      sub_FCD510(EventTrace, a2);
    }
  }
}
// 1040730: using guessed type wchar_t aDiskio[7];
// 1040740: using guessed type wchar_t aTcpip[6];
// 104074C: using guessed type wchar_t aUdpip[6];
// 1040758: using guessed type wchar_t aMsntTcpipinfor[22];

//----- (00FCDCE0) --------------------------------------------------------
void __cdecl sub_FCDCE0(EVENT_TRACE *EventTrace, EventList *a2)
{
  ULONG v2; // eax
  Data_t_bstr_t *v3; // eax
  Data_t_bstr_t *v4; // esi
  EventList *v5; // edi
  const wchar_t *v6; // eax
  OLECHAR **v7; // eax
  OLECHAR *v8; // eax
  const unsigned __int16 **v9; // edi
  int nIndex; // esi
  const unsigned __int16 *v11; // eax
  int v12; // eax
  EVENT_TRACE *v13; // edx
  EventListNode *v14; // eax
  unsigned int v15; // esi
  EventListNode *v16; // edi
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
  EventList *v41; // [esp+1Ch] [ebp-868h]
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
  OLECHAR psz; // [esp+74h] [ebp-810h]
  int v56; // [esp+880h] [ebp-4h]

  v41 = a2;
  v42 = EventTrace;
  memset(&v44, 0, 0x48u);
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
  _mm_storeu_si128(&v49, 0i64);
  _mm_storeu_si128(&v51, 0i64);
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
  LOBYTE(v56) = 0;
  v54.m_Data = v4;
  if ( !v4 )
    _com_issue_error(E_OUTOFMEMORY);
  v5 = v41;
  v46 = PE_ComputeTime(&gTime, EventTrace->Header.u4.s.KernelTime + EventTrace->Header.u4.s.UserTime);
  if ( v41->_Myheader )
    v6 = v41->_Myheader->field_0;
  else
    v6 = 0;
  v47 = 2 - (_wcsnicmp(v6, L"Udp", 3u) != 0);
  v7 = v41[4]._Myheader;
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
  v9 = v41[4]._Myheader;
  nIndex = 0;
  v45 = 0;
  while ( 1 )
  {
    if ( v9 )
      v11 = *v9;
    else
      v11 = 0;
    v12 = wcscmp(v11, gNetworkMsgItem[nIndex].szText);
    if ( v12 )
      v12 = -(v12 < 0) | 1;
    if ( !v12 )
      break;
    if ( ++nIndex >= 24 )
      goto LABEL_74;
  }
  v45 = gNetworkMsgItem[nIndex].nID;
  if ( v45 )
  {
    v13 = v42;
    v5 = v41;
LABEL_25:
    v14 = v5[3]._Myheader;
    v15 = v13->MofData;
    v16 = v14->field_0;
    if ( v14->field_0 != v14 )
    {
      do
      {
        if ( v15 >= v13->MofData + v13->MofLength )
          break;
        v17 = v16[1].field_0;
        a2a = v17;
        v18 = *(v17 + 4) + 1;
        while ( 2 )
        {
          switch ( v18 )
          {
            case 0u:
              if ( *v17 )
                v20 = **v17;
              else
                v20 = 0;
              v21 = NetworkMsgItem2_FindID(v20);
              v17 = a2a;
              a2a[1].m_Data = v21;
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
              if ( *(v17 + 8) == 27 )
              {
                LOBYTE(v51) = 1;
                v25 = _mm_loadu_si128(v15);
                v15 += 16;
                _mm_storeu_si128((&v51 + 4), v25);
              }
              else
              {
                LOBYTE(v51) = 0;
                v26 = *v15;
                v15 += 4;
                DWORD1(v51) = v26;
              }
              break;
            case 5u:
              if ( *(v17 + 8) == 27 )
              {
                LOBYTE(v49) = 1;
                v27 = _mm_loadu_si128(v15);
                v15 += 16;
                _mm_storeu_si128((&v49 + 4), v27);
              }
              else
              {
                LOBYTE(v49) = 0;
                v28 = *v15;
                v15 += 4;
                DWORD1(v49) = v28;
              }
              break;
            case 6u:
              HIWORD(v53) = ntohs(*v15);
              v15 += 2;
              break;
            case 7u:
              LOWORD(v53) = ntohs(*v15);
              v15 += 2;
              break;
            case 8u:
              v29 = *v15;
              v15 += 4;
              v48 = v29;
              break;
            case 9u:
              v30 = *v15;
              v15 += 4;
              v43 = v30;
              break;
            default:
LABEL_37:
              psz = 0;
              v38 = &sub_FCCC70(v15, v13->MofData + v13->MofLength, v17, &psz, 0x400u)[v15];
              _bstr_t::operator+=(&v54, a2a);
              _bstr_t::operator+=(&v54, &gNullString);
              _bstr_t::_bstr_t(&v40, &psz);
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
                    j_j__free(v22->m_str);
                    v22->m_str = 0;
                  }
                  j__free(v22);
                }
                v40.m_Data = 0;
              }
              _bstr_t::operator+=(&v54, &gNullString);
              v15 = v38;
              break;
          }
          break;
        }
        v16 = v16->field_0;
        v13 = v42;
      }
      while ( v16 != v41[3]._Myheader );
    }
    v23 = operator new(0xCu);
    LOBYTE(v56) = 3;
    if ( v23 )
      v24 = _bstr_t::Data_t::Data_t(v23, &v54, &gNullString);
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
        j_j__free(v31->m_str);
        v31->m_str = 0;
      }
      j__free(v31);
    }
    v54.m_Data = v24;
    if ( v47 == 2 && v45 == 3 )
    {
      v32 = _mm_loadu_si128(&v51);
      v33 = v52;
      v34 = _mm_loadu_si128(&v49);
      v35 = HIWORD(v53);
      v52 = v50;
      v36 = v53;
      _mm_storeu_si128(&v51, v34);
      HIWORD(v53) = v36;
      _mm_storeu_si128(&v49, v32);
      v50 = v33;
      LOWORD(v53) = v35;
    }
    sub_FF5310(&v43);
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
      j_j__free(v37->m_str);
      v37->m_str = 0;
    }
    j__free(v37);
  }
}

//----- (00FCE310) --------------------------------------------------------
int **__cdecl sub_FCE310(int a1, int a2)
{
  int *v2; // edi
  const unsigned __int16 **v3; // eax
  const unsigned __int16 *v4; // eax
  int v5; // eax
  const unsigned __int16 **v6; // eax
  const unsigned __int16 *v7; // eax
  int **result; // eax
  int v9; // ecx
  int v10; // edx
  _DWORD *v11; // eax
  int **v12; // ebx
  _DWORD *v13; // esi
  int v14; // edi
  int v15; // eax
  WCHAR *v16; // eax
  int *v17; // eax
  const unsigned __int16 **v18; // eax
  const unsigned __int16 *v19; // eax
  int v20; // eax
  int dwThreadId; // [esp+8h] [ebp-10h]
  int *v22; // [esp+Ch] [ebp-Ch]
  int a2a; // [esp+10h] [ebp-8h]
  int *a4; // [esp+14h] [ebp-4h]

  v2 = -1;
  a4 = -1;
  v22 = -1;
  v3 = *(a2 + 32);
  if ( v3 )
    v4 = *v3;
  else
    v4 = 0;
  v5 = wcscmp(v4, L"Start");
  if ( v5 )
    v5 = -(v5 < 0) | 1;
  if ( !v5 )
    goto LABEL_39;
  v6 = *(a2 + 32);
  if ( v6 )
    v7 = *v6;
  else
    v7 = 0;
  result = wcscmp(v7, L"End");
  if ( result )
    result = (-(result < 0) | 1);
  if ( !result )
  {
LABEL_39:
    v9 = a1;
    v10 = a2;
    v11 = *(a2 + 24);
    v12 = *(a1 + 72);
    v13 = *v11;
    if ( *v11 != v11 )
    {
      while ( 1 )
      {
        if ( v12 >= *(v9 + 72) + *(v9 + 76) )
          goto LABEL_29;
        v14 = v13[2];
        v15 = *(v14 + 4);
        if ( v15 == -1 )
        {
          do
          {
            if ( *v14 )
              v16 = **v14;
            else
              v16 = 0;
            v15 = NetworkMsgItem2_FindID(v16);
            *(v14 + 4) = v15;
          }
          while ( v15 == -1 );
          v9 = a1;
          v10 = a2;
        }
        if ( v15 == 53 )
          break;
        v2 = v22;
        if ( v15 != 54 )
          goto LABEL_25;
        v17 = *v12;
        ++v12;
        a4 = v17;
LABEL_26:
        if ( v2 == -1 || v17 == -1 )
        {
          v13 = *v13;
          if ( v13 != *(v10 + 24) )
            continue;
        }
        goto LABEL_29;
      }
      v2 = *v12;
      ++v12;
      v22 = v2;
LABEL_25:
      v17 = a4;
      goto LABEL_26;
    }
LABEL_29:
    v18 = *(v10 + 32);
    if ( v18 )
      v19 = *v18;
    else
      v19 = 0;
    v20 = wcscmp(v19, L"Start");
    if ( v20 )
      v20 = -(v20 < 0) | 1;
    if ( v20 )
    {
      sub_FCE560(&gThreadProcessMap, &a2a, &v22);
      result = sub_FF5510(&gThreadProcessMap, &a2, a2a, a4);
    }
    else
    {
      v22 = a4;
      dwThreadId = v2;
      result = std::map<unsigned long,unsigned long,std::less<unsigned long>,std::allocator<std::pair<unsigned long const,unsigned long>>>::operator[](
                 &gThreadProcessMap,
                 &a2a,
                 0,
                 &dwThreadId,
                 byte_106A100);
    }
  }
  return result;
}
// 10406F4: using guessed type wchar_t aEnd[4];
// 106A100: using guessed type char byte_106A100;

//----- (00FCE4E0) --------------------------------------------------------
int __cdecl sub_FCE4E0(int a1, PSID Sid)
{
  LPWSTR StringSid; // [esp+Ch] [ebp-10h]
  int v4; // [esp+18h] [ebp-4h]

  StringSid = 0;
  *a1 = 0;
  v4 = 0;
  if ( ConvertSidToStringSidW(Sid, &StringSid) )
  {
    _bstr_t::operator=(a1, StringSid);
    LocalFree(StringSid);
  }
  return a1;
}

//----- (00FCE560) --------------------------------------------------------
_DWORD *__thiscall sub_FCE560(int *this, _DWORD *a2, unsigned int *a3)
{
  int v3; // ebx
  int v4; // edx
  int v5; // eax
  int v6; // ecx
  unsigned int v7; // edi
  unsigned int v8; // esi
  _DWORD *result; // eax

  v3 = *this;
  v4 = *this;
  v5 = *(*this + 4);
  v6 = *(*this + 4);
  if ( !*(v6 + 13) )
  {
    v7 = *a3;
    do
    {
      v8 = *(v6 + 16);
      if ( v8 >= v7 )
      {
        if ( *(v4 + 13) && v7 < v8 )
          v4 = v6;
        v3 = v6;
        v6 = *v6;
      }
      else
      {
        v6 = *(v6 + 8);
      }
    }
    while ( !*(v6 + 13) );
  }
  if ( !*(v4 + 13) )
    v5 = *v4;
  while ( !*(v5 + 13) )
  {
    if ( *a3 >= *(v5 + 16) )
    {
      v5 = *(v5 + 8);
    }
    else
    {
      v4 = v5;
      v5 = *v5;
    }
  }
  result = a2;
  *a2 = v3;
  a2[1] = v4;
  return result;
}

//----- (00FCE5E0) --------------------------------------------------------
void __stdcall sub_FCE5E0(CSystemProcessInfoMapNode *a1)
{
  CSystemProcessInfoMapNode *v1; // edi
  CSystemProcessInfoMapNode *i; // esi

  v1 = a1;
  for ( i = a1; !i->baseclass._isnil; v1 = i )
  {
    sub_FCE5E0(i->baseclass._Right);
    i = i->baseclass._Left;
    j__free(v1);
  }
}

//----- (00FCE620) --------------------------------------------------------
CSystemProcessInfoMapNode *__thiscall sub_FCE620(CSystemProcessInfoMap *this)
{
  CSystemProcessInfoMap *v1; // edi
  std__Tree_node *v2; // ebx
  std__Tree_node *i; // esi
  CSystemProcessInfoMapNode *result; // eax

  v1 = this;
  v2 = this->_Header->_Parent;
  for ( i = v2; !i->_IsNil; v2 = i )
  {
    sub_FCE5E0(i->_Right);
    i = i->_Left;
    j__free(v2);
  }
  v1->_Header->_Parent = v1->_Header;
  v1->_Header->_Left = v1->_Header;
  result = v1->_Header;
  result->baseclass._Right = result;
  v1->_Size = 0;
  return result;
}

//----- (00FCE670) --------------------------------------------------------
_DWORD *__thiscall sub_FCE670(_DWORD *this, int a2, int a3, int a4, int a5, int a6)
{
  *this = a2;
  this[3] = a3;
  this[1] = a4;
  this[4] = a5;
  this[6] = a6;
  return this;
}

//----- (00FCE6A0) --------------------------------------------------------
wchar_t **__thiscall sub_FCE6A0(int **this, wchar_t *a2)
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
  if ( a2 >= this[1] )
    goto LABEL_13;
  v4 = this[3];
  if ( a2 )
  {
    do
    {
      v4 = (v4 + *v4);
      v3 = (v3 - 1);
    }
    while ( v3 );
  }
  if ( *v4 && ((v8 = sub_FB2D20(this[4], v4[1]), !v2[6]) ? (v5 = **v2) : (v5 = 0), (v6 = operator new(0x10u)) != 0) )
    result = sub_FCEC40(v6, v8, v4[7], *v2 + v4[9] + v5, v4[8]);
  else
LABEL_13:
    result = 0;
  return result;
}

//----- (00FCE760) --------------------------------------------------------
wchar_t **__thiscall sub_FCE760(PerformanceInfo **this, LPCWSTR lpsz)
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
  while ( v5->m_LastCounterOfLastHelp != v3 )
  {
    v5 = (v5 + v5->m_dwLastCounterOfLastHelp);
    v2[2] = (v2[2] + 1);
    if ( v2[2] >= v4 )
      goto LABEL_5;
  }
  lpsza = sub_FB2D20(v2[4], v5->m_LastCounterOfLastHelp);
  v7 = v2[6] ? 0 : (*v2)->m_dwLastCounterOfLastHelp;
  v8 = operator new(0x10u);
  if ( v8 )
    result = sub_FCEC40(
               v8,
               lpsza,
               v5[2].m_LastCounterOfLastHelp,
               *v2 + v5[3].m_dwLastCounterOfLastHelp + v7,
               v5[2].m_PerfValue);
  else
LABEL_5:
    result = 0;
  return result;
}

//----- (00FCE830) --------------------------------------------------------
wchar_t **__thiscall sub_FCE830(int this)
{
  *(this + 8) = 0;
  return sub_FCE6A0(this, 0);
}

//----- (00FCE840) --------------------------------------------------------
wchar_t **__thiscall sub_FCE840(int this)
{
  return sub_FCE6A0(this, ++*(this + 8));
}

//----- (00FCE850) --------------------------------------------------------
int __thiscall sub_FCE850(int *this, wchar_t *Dst, rsize_t SizeInWords)
{
  int v4; // ecx

  if ( this[6] )
  {
    *Dst = 0;
    return 0;
  }
  v4 = *this;
  if ( SizeInWords < *(v4 + 20) >> 1 )
    return 0;
  wcscpy_s(Dst, SizeInWords, (v4 + *(v4 + 16)));
  return 1;
}

//----- (00FCE8B0) --------------------------------------------------------
PE_PerfInfo_Item *__thiscall PE_PerfInfo::Load(PE_PerfInfo *this, LPCWSTR lpszName)
{
  PE_PerfInfo *v2; // ebx
  WCHAR *pszText; // esi
  unsigned int v4; // edi
  PE_PerfInfo_Item *result; // eax
  PE_PerfInfo_Item *pItem; // eax
  LPCWSTR index; // [esp+24h] [ebp+8h]

  v2 = this;
  index = PerformanceInfo::FindPerf(this->m_PerfInfo, lpszName);
  if ( !index )
    goto LABEL_5;
  pszText = sub_FCEFA0(v2->m_PerfInfoInMemory);
  v4 = 0;
  if ( !sub_FCEF90(v2->m_PerfInfoInMemory) )
    goto LABEL_5;
  while ( *(pszText + 3) != index )
  {
    ++v4;
    pszText = (pszText + *pszText);
    if ( v4 >= sub_FCEF90(v2->m_PerfInfoInMemory) )
      goto LABEL_5;
  }
  pItem = operator new(0x10u);
  if ( pItem )
    result = sub_FCED40(pItem, pszText, v2->m_PerfInfo);
  else
LABEL_5:
    result = 0;
  return result;
}

//----- (00FCE970) --------------------------------------------------------
char __cdecl sub_FCE970(LPCWSTR lpFileName, int a2, HANDLE hObject, LPCVOID lpBaseAddress)
{
  _WORD *v4; // ebx
  _BYTE *v5; // edi
  HANDLE v6; // eax
  void *v7; // esi
  HANDLE v8; // eax
  _DWORD *v10; // eax
  _DWORD *v11; // esi
  __int16 v12; // ax
  int v13; // esi
  _DWORD *v14; // eax
  signed int v15; // edx
  signed int v16; // esi
  int v17; // ecx
  _DWORD *v18; // ecx
  signed int v19; // esi
  signed int v20; // edi
  int v21; // edx
  unsigned int v22; // eax
  unsigned int v23; // eax
  HANDLE v24; // [esp+Ch] [ebp-8h]
  char v25; // [esp+13h] [ebp-1h]
  HANDLE hObjecta; // [esp+24h] [ebp+10h]
  _DWORD *lpBaseAddressa; // [esp+28h] [ebp+14h]

  v4 = lpBaseAddress;
  v5 = hObject;
  *lpBaseAddress = 0;
  *a2 = 0;
  v25 = 0;
  *hObject = 0;
  v6 = CreateFileW(lpFileName, 0x80000000, 1u, 0, 3u, 0x80u, 0);
  v7 = v6;
  v24 = v6;
  if ( v6 == -1 )
    return 0;
  v8 = CreateFileMappingW(v6, 0, 2u, 0, 0, 0);
  hObjecta = v8;
  if ( !v8 )
  {
    CloseHandle(v7);
    return 0;
  }
  v10 = MapViewOfFile(v8, 4u, 0, 0, 0);
  lpBaseAddressa = v10;
  if ( !v10 )
  {
    CloseHandle(hObjecta);
    CloseHandle(v24);
    return 0;
  }
  if ( *v10 == 23117 )
  {
    v11 = (v10 + v10[15]);
    if ( *(v11 + 11) & 0x100 && (v12 = *(v11 + 2), v12 != -31132) && v12 != 512 )
      *v5 = 1;
    else
      *v5 = 2;
    *a2 = v11[2];
    *v4 = *(v11 + 47) | 1;
    if ( *v5 == 2 )
    {
      v13 = lpBaseAddressa + lpBaseAddressa[15];
      if ( IsBadReadPtr(lpBaseAddressa + lpBaseAddressa[15], 0x108u) )
        goto LABEL_59;
      if ( *v13 != 17744 )
        goto LABEL_59;
      v14 = (v13 + 264);
      v15 = 1;
      v16 = *(v13 + 6);
      if ( v16 < 1 )
        goto LABEL_59;
      while ( 1 )
      {
        if ( !v14[4]
          && (*v14 != 2019914798 || v14[1] != 1936941684)
          && (*v14 != 1936487470 || v14[1])
          && (*v14 != 1936941614 || v14[1] && (*v14 != 1936941614 || v14[1]))
          && (*v14 != 1650422898 || v14[1] != 29555) )
        {
          v17 = v14[9];
          if ( v17 & 0x20000000 )
          {
            if ( v17 & 0xC0 )
              break;
          }
        }
        ++v15;
        v14 += 10;
        if ( v15 > v16 )
          goto LABEL_59;
      }
    }
    else
    {
      if ( IsBadReadPtr(v11, 0xF8u) )
        goto LABEL_59;
      if ( *v11 != 17744 )
        goto LABEL_59;
      v18 = v11 + 62;
      v19 = *(v11 + 3);
      v20 = 1;
      if ( v19 < 1 )
        goto LABEL_59;
      while ( 1 )
      {
        v21 = v18[9];
        if ( v21 & 0x20 )
        {
          v22 = v18[2];
          if ( v22 > 0x1000 && v18[4] < v22 - 4096 )
            break;
        }
        if ( *v18 == 2019914798 && v18[1] == 116 )
        {
          v23 = v18[2];
          if ( v23 > 0x1000 && v18[4] < v23 - 4096 )
            break;
        }
        if ( !*v18 && v18[4] < v18[2]
          || !v18[4]
          && v18[2] >= 0x1000u
          && (*v18 != 2019914798 || v18[1] != 1936941684)
          && (*v18 != 1936487470 || v18[1])
          && (*v18 != 1936941614 || v18[1])
          && (*v18 != 1952539694 || v18[1] != 97)
          && v21 & 0x20000000
          && v21 & 0xC0 )
        {
          break;
        }
        ++v20;
        v18 += 10;
        if ( v20 > v19 )
          goto LABEL_59;
      }
    }
    v25 = 1;
  }
LABEL_59:
  UnmapViewOfFile(lpBaseAddressa);
  CloseHandle(hObjecta);
  CloseHandle(v24);
  return v25;
}

//----- (00FCEC40) --------------------------------------------------------
wchar_t **__thiscall sub_FCEC40(wchar_t **this, wchar_t *a2, int a3, void *a4, unsigned int a5)
{
  wchar_t **v5; // esi
  wchar_t *v6; // eax
  size_t v7; // ST08_4

  v5 = this;
  *this = _wcsdup(a2);
  v5[1] = a3;
  v5[3] = a5;
  v6 = operator new[](a5);
  v7 = v5[3];
  v5[2] = v6;
  memmove_0(v6, a4, v7);
  return v5;
}

//----- (00FCEC80) --------------------------------------------------------
void __thiscall sub_FCEC80(void **this)
{
  void **v1; // esi

  v1 = this;
  free(*this);
  j_j__free(v1[2]);
}

//----- (00FCECA0) --------------------------------------------------------
signed int __thiscall sub_FCECA0(int this, _DWORD *a2, int a3)
{
  __int64 v3; // rax
  signed int result; // eax
  __int64 v5; // rax
  _DWORD *v6; // edx

  switch ( *(this + 12) )
  {
    case 1:
      v3 = **(this + 8);
      *a2 = v3;
      result = 1;
      a2[1] = HIDWORD(v3);
      break;
    case 2:
      v5 = **(this + 8);
      *a2 = v5;
      result = 1;
      a2[1] = HIDWORD(v5);
      break;
    case 4:
      *a2 = **(this + 8);
      result = 1;
      a2[1] = 0;
      break;
    case 8:
      v6 = *(this + 8);
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

//----- (00FCED40) --------------------------------------------------------
PE_PerfInfo_Item *__thiscall sub_FCED40(PE_PerfInfo_Item *this, int a2, PerformanceInfo *a3)
{
  this->m_Text = a2;
  this->m_PerfInfo = a3;
  return this;
}

//----- (00FCED60) --------------------------------------------------------
_DWORD *__thiscall sub_FCED60(_DWORD *this)
{
  _DWORD *v1; // esi
  int v2; // ecx
  _DWORD *v3; // edi
  _DWORD *result; // eax

  v1 = this;
  v2 = *this;
  v1[1] = 0;
  if ( *(v2 + 40) && (v1[2] = v2 + *(v2 + 4), (v3 = operator new(0x1Cu)) != 0) )
    result = sub_FCE670(v3, v1[2], *v1 + *(*v1 + 8), *(*v1 + 32), v1[3], *(*v1 + 40) == -1);
  else
    result = 0;
  return result;
}

//----- (00FCEE00) --------------------------------------------------------
_DWORD *__thiscall sub_FCEE00(_DWORD *this)
{
  _DWORD *v1; // esi
  int v2; // ecx
  _DWORD *v3; // ecx
  _DWORD *v4; // edx
  _DWORD *result; // eax

  v1 = this;
  v2 = *this;
  if ( *(v2 + 40) != -1
    && (++v1[1], v1[1] < *(v2 + 40))
    && (v3 = (*v1[2] + v1[2]), v1[2] = v3 + *v3, (v4 = operator new(0x1Cu)) != 0) )
  {
    result = sub_FCE670(v4, v1[2], *v1 + *(*v1 + 8), *(*v1 + 32), v1[3], 0);
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00FCEEA0) --------------------------------------------------------
PerformanceInfoInMemory *__thiscall PE_PerfInfo::PE_PerfInfo(PerformanceInfoInMemory *this, PerformanceInfo *a2)
{
  PerformanceInfoInMemory *result; // eax

  this->m_PerfInfo = a2;
  result = this;
  this->m_pBuffer = 0;
  return result;
}

//----- (00FCEEC0) --------------------------------------------------------
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
    lpsza = (2 * nLength);
    do
    {
      nPerfIndex = PerformanceInfo::FindPerf(v10->m_PerfInfo, pszName);
      if ( nPerfIndex )
        nLen = swprintf_s(pszBuf, (pszBuffer + lpsza - pszBuf) >> 1, L"%u ", nPerfIndex);
      else
        nLen = swprintf_s(pszBuf, (pszBuffer + lpsza - pszBuf) >> 1, L"%s ", pszName);
      pszBuf += nLen;
      pszName = wcstok_s(0, ",", &Context);
    }
    while ( pszName );
  }
  free(lpszName_1);
  return 1;
}
// 1040800: using guessed type wchar_t aU_0[4];

//----- (00FCEF90) --------------------------------------------------------
int __thiscall sub_FCEF90(PerformanceInfoInMemory *this)
{
  int result; // eax

  if ( this->m_pBuffer )
    result = *(this->m_pBuffer + 7);
  else
    result = 0;
  return result;
}

//----- (00FCEFA0) --------------------------------------------------------
WCHAR *__thiscall sub_FCEFA0(PerformanceInfoInMemory *this)
{
  WCHAR *v1; // ecx
  WCHAR *result; // eax

  v1 = this->m_pBuffer;
  if ( v1 )
    result = (v1 + *(v1 + 6));
  else
    result = 0;
  return result;
}

//----- (00FCEFB0) --------------------------------------------------------
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
  j__free(pThis->m_pBuffer);
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
        j_j__free(this->m_pBuffer);
        if ( cbData <= dwLength )
          dwLength += 4096;
        else
          dwLength = cbData + 4096;
        v6 = operator new[](dwLength);
        this->m_pBuffer = v6;
        if ( !v6 )
          break;
        cbData = dwLength;
        lRet = RegQueryValueExW(hSubKey, szValueName, 0, 0, v6, &cbData);
        if ( !lRet )
          goto LABEL_13;
      }
    }
    else
    {
LABEL_13:
      if ( *this->m_pBuffer == 0x450050 && *(this->m_pBuffer + 1) == 0x460052 )
        return 1;
    }
    j_j__free(this->m_pBuffer);
    this->m_pBuffer = 0;
  }
  return 0;
}

//----- (00FCF110) --------------------------------------------------------
int __cdecl CMainWnd::HandleMsg7FD(int _8, int a2, int a3, void *a1)
{
  TreeViewListItemParam_Release(a1);
  return 0;
}

//----- (00FCF130) --------------------------------------------------------
int __cdecl CMainWnd::HandleDeviceChange(HWND a1, unsigned int a2, unsigned int wParam, _DEV_BROADCAST_HDR *lParam)
{
  if ( wParam == DBT_DEVICEARRIVAL && lParam->dbch_devicetype == DBT_DEVTYP_VOLUME )
    GetDriverNameAndLinkInfo();
  return 0;
}

//----- (00FCF150) --------------------------------------------------------
int __cdecl CMainWnd::HandleMsg7F9(int a1, int a2, int a3, int a4)
{
  tagTREEVIEWLISTITEMPARAM *v4; // esi
  tagTREEVIEWLISTITEMPARAM *v5; // ebx
  ListItemData1 *v6; // edi
  char v7; // dl
  WCHAR *v8; // ecx
  const wchar_t **v9; // eax
  const wchar_t *v10; // eax
  DLLLISTITEMPARAM *v11; // esi
  char v12; // bl
  const wchar_t *v13; // eax
  const wchar_t **v14; // ecx
  const wchar_t *v15; // ecx
  char v17; // [esp+23h] [ebp+17h]

  v4 = gpTreeViewListItemParam;
  v5 = 0;
  v6 = a4;
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
          v9 = v6[2].field_4;
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
          sub_FBFAA0(0x65);
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
              v13 = v11->m_strPath.pszData;
              if ( v13 )
              {
                v14 = v6[2].field_4;
                if ( v14 )
                  v15 = *v14;
                else
                  v15 = 0;
                if ( !_wcsicmp(v13, v15) )
                {
                  v11->m_HashData = v6;
                  v12 = 1;
                }
              }
              v11 = v11->m_Prev;
            }
            while ( v11 );
            if ( v12 )
            {
              InvalidateRect(ghWndDllsListCtrl, 0, 0);
              sub_FBFAA0(0x68);
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
      sub_FBFAA0(0x65);
    }
    else if ( IsColumnIDValid(ghWndTreeListView, 0x686u) )
    {
      InvalidateRect(ghWndTreeListView, 0, 0);
    }
    if ( IsWindowVisible(ghWndDllsListCtrl) )
    {
      InvalidateRect(ghWndDllsListCtrl, 0, 0);
      sub_FBFAA0(0x68);
    }
  }
  return 0;
}

//----- (00FCF350) --------------------------------------------------------
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
    || (v10 = v3, v11 = 0, lParam = 4, !SendMessageW(v2, 0x104Bu, 0, &lParam))
    || (v4 = v12, SetFocus(ghWndTreeListView), !v4) )
  {
    MessageBoxW(ghWndTreeListView, L"No process is selected", L"Process Explorer Error", 0x10u);
    return 0;
  }
  v5 = OpenProcess(0x10000000u, 0, *(v4 + 68));
  if ( !v5 )
  {
    ReportMsg(L"Error opening process", ghMainWnd);
    return 0;
  }
  wcscpy_s(&Dst, 0x104u, *(v4 + 60));
  if ( wcschr(&Dst, 0x2Eu) )
    *wcschr(&Dst, 0x2Eu) = 0;
  swprintf(&pszBuffer, L"Create dump of %s", *(v4 + 60));
  wcscat_s(&Dst, 0x104u, L".dmp");
  v13.hwndOwner = ghMainWnd;
  v13.hInstance = ghInstance;
  v13.lpstrFile = &Dst;
  *&v13.nFileOffset = 0;
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
  if ( v7 == -1 )
  {
    ReportMsg(L"Error creating dump file", ghMainWnd);
    result = 0;
  }
  else
  {
    v8 = LoadCursorW(0, 0x7F02);
    hCursor = SetCursor(v8);
    if ( !DumpFileProcess(v7, v5, a2 == -24806) )
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
// 1042088: using guessed type wchar_t aErrorOpeningPr[22];
// 10420E4: using guessed type wchar_t aDmp_0[6];
// 10420F0: using guessed type wchar_t aDumpFileDmp[18];
// 1042140: using guessed type wchar_t aErrorCreatingD[25];
// 1042174: using guessed type wchar_t aErrorWritingDu[24];

//----- (00FCF670) --------------------------------------------------------
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
    || (v8 = v1, v9 = 0, lParam = 4, !SendMessageW(v0, 0x104Bu, 0, &lParam))
    || (v2 = v10, SetFocus(ghWndTreeListView), !v2) )
  {
    MessageBoxW(ghWndTreeListView, L"No process is selected", L"Process Explorer Error", 0x10u);
    return 0;
  }
  v3 = *(v2 + 88);
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
  if ( !sub_FF8030(*(v2 + 60), *(v2 + 68)) )
    return 0;
  memset(&StartupInfo, 0, 0x44u);
  StartupInfo.cb = 68;
  StartupInfo.dwFlags = 1;
  StartupInfo.wShowWindow = 5;
  if ( CreateProcessW(
         *(v2 + 792),
         *(v2 + 800),
         0,
         0,
         0,
         0x400u,
         *(v2 + 808),
         *(v2 + 804),
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
// 1042394: using guessed type wchar_t aErrorRestartin[25];

//----- (00FCF820) --------------------------------------------------------
int Command_KillProcess()
{
  LRESULT v0; // eax
  LPARAM v2; // [esp+4h] [ebp-68h]
  int v3; // [esp+10h] [ebp-5Ch]
  int v4; // [esp+14h] [ebp-58h]
  LPARAM lParam; // [esp+38h] [ebp-34h]
  LRESULT v6; // [esp+3Ch] [ebp-30h]
  int v7; // [esp+40h] [ebp-2Ch]
  int v8; // [esp+58h] [ebp-14h]

  lParam = 0;
  memset(&v6, 0, 0x30u);
  v0 = SendMessageW(ghWndTreeListView, 0x100Cu, 0xFFFFFFFF, 2);
  if ( v0 == -1 )
  {
    MessageBoxW(ghWndTreeListView, L"No process selected", L"Process Explorer Error", 0x10u);
  }
  else
  {
    v6 = v0;
    v7 = 0;
    lParam = 4;
    if ( SendMessageW(ghWndTreeListView, 0x104Bu, 0, &lParam) )
    {
      sub_FF8140(*(v8 + 60), *(v8 + 68));
      SetEvent(ghRefreshEventHandle);
      v4 = 2;
      v3 = 2;
      SendMessageW(ghWndTreeListView, 0x102Bu, 0, &v2);
      return 0;
    }
  }
  return 0;
}

//----- (00FCF8F0) --------------------------------------------------------
int __cdecl Command_Exit(HWND hWnd)
{
  DestroyWindow(hWnd);
  return 0;
}

//----- (00FCF900) --------------------------------------------------------
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
// 106A389: using guessed type char gbMainWndMinimized;
// 106A393: using guessed type char gbMainWndMinimized1;

//----- (00FCF980) --------------------------------------------------------
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
            SendMessageW(v1, LVM_GETITEMTEXTW, lvitem_1.iItem, &lvitem);
          }
          else
          {
            lvitem_1.mask = 4;
            if ( SendMessageW(v1, LVM_GETITEMW, 0, &lvitem_1) )
            {
              wcscpy_s(&Dst, 0x800u, lvitem_1.lParam->field_3C);
              --lvitem_1.iSubItem;
              --v11;
            }
          }
          v10 += 2 * wcslen(&Dst) + 1;
          if ( v3 )
          {
            v2 = GlobalReAlloc(v2, 2 * v10 + 2, 0);
            v3 = GlobalLock(v2);
            wcscat_s(v3, v10 + 1, L"\t");
          }
          else
          {
            v2 = GlobalAlloc(0x2002u, 2 * v10 + 2);
            v3 = GlobalLock(v2);
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

//----- (00FCFBD0) --------------------------------------------------------
int Command_RefreshNow()
{
  SetEvent(ghTimerRefreshEvent);
  return 0;
}

//----- (00FCFBE0) --------------------------------------------------------
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
  Pages[0].dwSize = &ZeroParam;
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
  Pages[1].lParam = &ZeroParam;
  Pages[1].pfnCallback = 0;
  Pages[2].dwSize = sizeof(PE_PROPSHEETPAGEW);
  Pages[2].dwFlags = PSP_USETITLE;
  Pages[2].hInstance = ::ghInstance;
  Pages[2].u.pszTemplate = L"PROCIOCOLUMNS";
  Pages[2].u2.hIcon = 0;
  Pages[2].pfnDlgProc = PropColumnSetsForProcess;
  Pages[2].pszTitle = L"Process I/O";
  Pages[2].lParam = &ZeroParam;
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
    Pages[3].lParam = &ZeroParam;
    Pages[3].pfnCallback = 0;
    Pages[4].dwSize = sizeof(PE_PROPSHEETPAGEW);
    Pages[4].dwFlags = PSP_USETITLE;
    Pages[4].hInstance = ::ghInstance;
    Pages[4].u.pszTemplate = L"PROCDISKCOLUMNS";
    Pages[4].u2.hIcon = 0;
    Pages[4].pfnDlgProc = PropColumnSetsForProcess;
    Pages[4].pszTitle = L"Process Disk";
    Pages[4].lParam = &ZeroParam;
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
  Pages[nPageIndex_2].lParam = &ZeroParam;
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
    Pages[nPageIndex_4].lParam = &ZeroParam;
    Pages[nPageIndex_4].pfnCallback = 0;
  }
  nPageIndex_5 = nPageIndex_3;
  Pages[nPageIndex_5].lParam = &ZeroParam;
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
  Pages[nPageIndex_8].lParam = &ZeroParam;
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
    Pages[nPageIndex_9].lParam = &ZeroParam;
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
  PropSheet.ppsp = Pages;
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
// 1041188: using guessed type wchar_t aProccolumns[12];
// 10411A0: using guessed type wchar_t aProcessImage[14];
// 10411BC: using guessed type wchar_t aProcperfcolumn[16];
// 10411DC: using guessed type wchar_t aProcessPerform[20];
// 1041204: using guessed type wchar_t aProciocolumns[14];
// 1041220: using guessed type wchar_t aProcessIO[12];
// 1041238: using guessed type wchar_t aProcnetworkcol[19];
// 1041260: using guessed type wchar_t aProcessNetwork[16];
// 1041280: using guessed type wchar_t aProcdiskcolumn[16];
// 10412A0: using guessed type wchar_t aProcessDisk[13];
// 10412BC: using guessed type wchar_t aProcmemcolumns[15];
// 10412DC: using guessed type wchar_t aProcessMemory[15];
// 10412FC: using guessed type wchar_t aProcgpucolumns[15];
// 104131C: using guessed type wchar_t aProcessGpu[12];
// 1041334: using guessed type wchar_t aHandlecolumns_0[14];
// 1041350: using guessed type wchar_t aHandle[7];
// 1041360: using guessed type wchar_t aDllcolumns_0[11];
// 1041380: using guessed type wchar_t aNetcolumns[11];
// 1041398: using guessed type wchar_t aNet[5];
// 10413A4: using guessed type wchar_t aStatusbarcolum_0[17];
// 10413C8: using guessed type wchar_t aStatusBar[11];
// 106A098: using guessed type char gNetClrMemoryPerfInfoLoaded;
// FD0037: user specified stroff has not been processed: PROPSHEETHEADERW offset 52
