

//----- (00FAEEA0) --------------------------------------------------------
wchar_t *__thiscall sub_FAEEA0(int this, int a2, int a3, wchar_t *Dst, int a5)
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
        v7 = sub_FAB970((v6 - 16));
        v8 = &v7[1];
        Dst = &v7[1];
        if ( *a5 < v7->nDataLength + 1 )
        {
          v9 = sub_FAF790(&Dst, &a3, 0, *a5 - 4);
          sub_FAD840(&Dst, v9);
          v10 = a3 - 16;
          if ( _InterlockedDecrement((a3 - 16 + 12)) <= 0 )
            (*(**v10 + 4))(v10);
          sub_FADB40(&Dst, L"...");
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

//----- (00FAEFF0) --------------------------------------------------------
wchar_t *__thiscall sub_FAEFF0(int this, int a2, int a3, wchar_t *Dst, int a5)
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

//----- (00FAF070) --------------------------------------------------------
wchar_t *__stdcall sub_FAF070(int a1, int a2, wchar_t *Dst, int a4)
{
  swprintf_s(Dst, *a4, &gszNullString);
  return Dst;
}

//----- (00FAF090) --------------------------------------------------------
const wchar_t *CResizer::GetName()
{
  return L"status";
}
// 103C890: using guessed type wchar_t aStatus[7];

//----- (00FAF0A0) --------------------------------------------------------
int __thiscall sub_FAF0A0(_DWORD *this, int a2)
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
          v51 = sub_FAEBA0(v3, v4, v50);
          sub_FB01B0(v51);
          v52 = v2[8];
          sub_FACF50(&v58, v2[7], v2[8], &pInfo);
          if ( v58 != v52 )
            sub_FB0840(v2 + 7, &pInfo, v58);
          v19 = v2[7] == v2[8];
          goto LABEL_36;
        case 153:
          v44 = *(a2 + 92);
          v45 = sub_FAEA30(*(a2 + 92));
          v46 = sub_FAEBA0(*pInfo.szUserName, v4, v45);
          v47 = sub_FAE810(v46, *(v44 + 8), *(v44 + 12));
          if ( !v47 )
            return 0;
          if ( *(v44 + 16) & 2 )
            v48 = sub_FAEAB0(v44);
          else
            v48 = (v44 + 24);
          v49 = ATL::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>::Format(&v57, v48)->pszData;
          v63 = 8;
          sub_FB00E0(v47, v49);
          v14 = &v57;
          goto LABEL_32;
        case 155:
          v33 = *(a2 + 92);
          v34 = *(v33 + 8);
          v35 = *(v33 + 12);
          v58 = *v33;
          pInfo.bIsSystemUser = *(v33 + 4);
          v36 = sub_FAEA10(v33);
          v37 = sub_FAEBA0(*pInfo.szUserName, v59, v36);
          v38 = sub_FAEAD0(v37, v34, v35);
          sub_FADC50(&Src, 0x400u, *(v33 + 24));
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
          v29 = sub_FAE9F0(v26);
          v30 = sub_FAEBA0(*pInfo.szUserName, v59, v29);
          v31 = sub_FAEAD0(v30, v27, v28);
          v31[4].pszData = sub_FAEA90(v26);
          v32 = ATL::CStringT<wchar_t,ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>>::Format(&v54, v26 + 12)->pszData;
          v63 = 4;
          sub_FB00E0(v31, v32);
          v63 = -1;
          ATL::CSimpleStringT<wchar_t,0>::~CSimpleStringT<wchar_t,0>(&v54);
          sub_FADB10(&Src, 0x400u, *(v26 + 8));
          sub_FAFEB0(v31, &Src);
          break;
        case 187:
          pInfo.nMenuID = *(a2 + 92);
          v20 = *pInfo.nMenuID;
          v21 = *(pInfo.nMenuID + 14);
          v22 = *(pInfo.nMenuID + 16);
          v23 = *(pInfo.nMenuID + 18);
          pInfo.bIsSystemUser = *(pInfo.nMenuID + 12);
          v56 = v20;
          v59 = sub_FAEBA0(*pInfo.szUserName, v59, v20);
          sub_FAFF00(v59, (pInfo.nMenuID + 25));
          sub_FB0880(v58 + 7, &v56);
          swprintf_s(&Dst, 0x400u, L"v%u.%u.%u.%u", pInfo.bIsSystemUser, v21, v22, v23);
          v24 = v59;
          sub_FB00E0(v59, &Dst);
          v25 = pInfo.nMenuID;
          sub_FAE970(&pInfo.szUserName[2], 0x400u, *(pInfo.nMenuID + 20), &unk_105D178, 15);
          sub_FAFF50(v24, &pInfo.szUserName[2]);
          sub_FB01D0(&Src, 0x400u, *(v25 + 24));
          sub_FAFFA0(v24, &Src);
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
        v8 = sub_FAEBA0(v3, v4, 0xFFFD);
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
            v13 = sub_FAF760(pInfo.szUserName, &pInfo.nMenuID, v12 + 1);
            LOBYTE(v63) = 1;
            sub_FAD840(pInfo.szUserName, v13);
            LOBYTE(v63) = 0;
            ATL::CSimpleStringT<wchar_t,0>::~CSimpleStringT<wchar_t,0>(&pInfo.nMenuID);
          }
        }
        v14 = pInfo.szUserName;
        if ( *(*pInfo.szUserName - 12) )
        {
          v15 = sub_FAFE80(pInfo.szUserName, 0x2Eu);
          if ( v15 >= 0 )
          {
            v16 = sub_FAF790(pInfo.szUserName, &pInfo.nMenuID, 0, v15);
            LOBYTE(v63) = 2;
            sub_FAD840(pInfo.szUserName, v16);
            LOBYTE(v63) = 0;
            ATL::CSimpleStringT<wchar_t,0>::~CSimpleStringT<wchar_t,0>(&pInfo.nMenuID);
          }
          sub_FAE970(&Dst, 0x400u, v7[8], &dword_105D130, 4);
          v17 = operator new(0x20u);
          v57.pszData = v17;
          LOBYTE(v63) = 3;
          if ( v17 )
            v18 = Assembly::Assembly(v17, v9, v9 >> 31, &gszNullString, &Dst);
          else
            v18 = 0;
          LOBYTE(v63) = 0;
          sub_FAFF00(v18, *pInfo.szUserName);
          if ( *(v7 + 4) & 2 )
            v10 = sub_FAEAB0(v7);
          sub_FB00E0(v18, v10);
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
// 105D130: using guessed type int dword_105D130;

//----- (00FAF690) --------------------------------------------------------
int __cdecl sub_FAF690(const unsigned __int16 *a1)
{
  signed int v1; // edi
  int v2; // esi
  signed int i; // edx
  unsigned int v4; // eax
  int v5; // eax

  v1 = 1;
  v2 = 0;
  for ( i = wcslen(a1) - 1; i >= 0; --i )
  {
    v4 = a1[i];
    if ( (v4 == 120 || v4 == 88) && a1[i - 1] == 48 )
      return v2;
    if ( v4 < 0x30 || v4 > 0x39 )
    {
      if ( v4 < 0x61 || v4 > 0x66 )
      {
        if ( v4 < 0x41 || v4 > 0x46 )
          continue;
        v5 = v4 - 55;
      }
      else
      {
        v5 = v4 - 87;
      }
    }
    else
    {
      v5 = v4 - 48;
    }
    v2 |= v5 * v1;
    v1 *= 16;
  }
  return v2;
}

//----- (00FAF710) --------------------------------------------------------
bool __cdecl sub_FAF710(int a1, int a2, int a3)
{
  return *(a1 + 8) == a2 && *(a1 + 12) == a3;
}

//----- (00FAF730) --------------------------------------------------------
bool __cdecl sub_FAF730(int a1, int a2)
{
  return *(a1 + 28) == *a2 && *(a1 + 20) == *(a2 + 4);
}

//----- (00FAF760) --------------------------------------------------------
void **__thiscall sub_FAF760(_DWORD *this, void **a2, int a3)
{
  sub_FAF790(this, a2, a3, *(*this - 12) - a3);
  return a2;
}

//----- (00FAF790) --------------------------------------------------------
void **__thiscall sub_FAF790(_DWORD *this, void **a2, int a3, int a4)
{
  int v4; // esi
  _DWORD *v5; // ebx
  int v6; // edi
  int v7; // edx
  int v8; // ecx
  CStringData *v9; // ecx
  void **result; // eax
  int v11; // ecx
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
  v7 = *this;
  v8 = *(*this - 12);
  if ( v6 + v4 > v8 )
    v4 = v8 - v6;
  if ( v6 > v8 )
    v4 = 0;
  if ( v6 || v4 != v8 )
  {
    v11 = *(v7 - 16);
    if ( !v11 || (v12 = (*(*v11 + 16))()) == 0 )
    {
      v13 = ATL::StrTraitATL<wchar_t,ATL::ChTraitsCRT<wchar_t>>::GetDefaultManager();
      v12 = (v13->vtptr->Clone)(v13);
    }
    sub_FACF80(a2, (*v5 + 2 * v6), v4, v12);
    result = a2;
  }
  else
  {
    v9 = sub_FAB970((v7 - 16)) + 1;
    result = a2;
    *a2 = v9;
  }
  return result;
}

//----- (00FAF840) --------------------------------------------------------
signed int __thiscall sub_FAF840(char *this, WCHAR *a2)
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
  Logfile.u2.EventCallback = sub_FAE7F0;
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

//----- (00FAF920) --------------------------------------------------------
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
// 103CB38: using guessed type double db_four;

//----- (00FAFD80) --------------------------------------------------------
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

//----- (00FAFE80) --------------------------------------------------------
int __thiscall sub_FAFE80(const wchar_t **this, wchar_t a2)
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

//----- (00FAFEB0) --------------------------------------------------------
CStringData *__thiscall sub_FAFEB0(CString *this, void *Src)
{
  CStringData *result; // eax

  if ( Src )
    result = ATL::CSimpleStringT<wchar_t,0>::SetString(this + 5, Src, wcslen(Src));
  else
    result = ATL::CSimpleStringT<wchar_t,0>::SetString(this + 5, 0, 0);
  return result;
}

//----- (00FAFF00) --------------------------------------------------------
CStringData *__thiscall sub_FAFF00(CString *this, void *Src)
{
  CStringData *result; // eax

  if ( Src )
    result = ATL::CSimpleStringT<wchar_t,0>::SetString(this + 1, Src, wcslen(Src));
  else
    result = ATL::CSimpleStringT<wchar_t,0>::SetString(this + 1, 0, 0);
  return result;
}

//----- (00FAFF50) --------------------------------------------------------
CStringData *__thiscall sub_FAFF50(CString *this, void *Src)
{
  CStringData *result; // eax

  if ( Src )
    result = ATL::CSimpleStringT<wchar_t,0>::SetString(this + 2, Src, wcslen(Src));
  else
    result = ATL::CSimpleStringT<wchar_t,0>::SetString(this + 2, 0, 0);
  return result;
}

//----- (00FAFFA0) --------------------------------------------------------
CStringData *__thiscall sub_FAFFA0(CString *this, void *Src)
{
  CStringData *result; // eax

  if ( Src )
    result = ATL::CSimpleStringT<wchar_t,0>::SetString(this + 3, Src, wcslen(Src));
  else
    result = ATL::CSimpleStringT<wchar_t,0>::SetString(this + 3, 0, 0);
  return result;
}

//----- (00FAFFF0) --------------------------------------------------------
int __thiscall sub_FAFFF0(CString *this, void *Src)
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
        v8 = sub_FAF790(v5, &Src, 0, result);
        sub_FAD840(v5, v8);
        v9 = Src - 16;
        result = Src - 4;
        if ( _InterlockedDecrement(result) <= 0 )
          result = (*(**v9 + 4))(v9);
      }
    }
  }
  return result;
}

//----- (00FB00E0) --------------------------------------------------------
CStringData *__thiscall sub_FB00E0(CString *this, void *Src)
{
  CStringData *result; // eax

  if ( Src )
    result = ATL::CSimpleStringT<wchar_t,0>::SetString(this + 6, Src, wcslen(Src));
  else
    result = ATL::CSimpleStringT<wchar_t,0>::SetString(this + 6, 0, 0);
  return result;
}

//----- (00FB0130) --------------------------------------------------------
int __thiscall sub_FB0130(HWND *this)
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

//----- (00FB01B0) --------------------------------------------------------
void *__thiscall sub_FB01B0(int this)
{
  return sub_FACC30(*(this + 32), *(this + 36), (*(this + 36) - *(this + 32)) >> 2, sub_FAE780);
}

//----- (00FB01D0) --------------------------------------------------------
int __cdecl sub_FB01D0(wchar_t *Dst, rsize_t SizeInWords, int a3)
{
  return sub_FAE970(Dst, SizeInWords, a3, &unk_105D150, 5);
}

//----- (00FB0200) --------------------------------------------------------
int __cdecl sub_FB0200(wchar_t *Src, int a2)
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
  *a2 = sub_FAF690(&Dst);
  wcsncpy_s(&Dst, 0xAu, Src + 9, 4u);
  v9 = 0;
  *(a2 + 4) = sub_FAF690(&Dst);
  wcsncpy_s(&Dst, 0xAu, Src + 14, 4u);
  v9 = 0;
  *(a2 + 6) = sub_FAF690(&Dst);
  v2 = 0;
  v3 = Src + 19;
  do
  {
    wcsncpy_s(&Dst, 0xAu, v3, 2u);
    v8 = 0;
    *(a2 + 8 + v2++) = sub_FAF690(&Dst);
    v3 += 2;
  }
  while ( v2 < 2 );
  v4 = 2;
  v5 = Src + 24;
  do
  {
    wcsncpy_s(&Dst, 0xAu, v5, 2u);
    v8 = 0;
    result = sub_FAF690(&Dst);
    *(a2 + 8 + v4++) = result;
    v5 += 2;
  }
  while ( v4 < 8 );
  return result;
}

//----- (00FB0310) --------------------------------------------------------
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
// 1064D84: using guessed type int (__stdcall *gpfnIsThemeActive)();

//----- (00FB0650) --------------------------------------------------------
char *__thiscall sub_FB0650(const void **this, unsigned int a2)
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

//----- (00FB06D0) --------------------------------------------------------
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

//----- (00FB0750) --------------------------------------------------------
unsigned int __thiscall sub_FB0750(int this, unsigned int a2)
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
      result = sub_FB0650(this, v8);
    }
    else
    {
      v7 = 0;
      if ( v5 > 0 )
        v7 = v5;
      result = sub_FB0650(this, v7);
    }
  }
  return result;
}

//----- (00FB07C0) --------------------------------------------------------
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

//----- (00FB0840) --------------------------------------------------------
int __thiscall sub_FB0840(_DWORD *this, int a2, void *a3)
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

//----- (00FB0880) --------------------------------------------------------
__int16 __thiscall sub_FB0880(_DWORD *this, _WORD *a2)
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
      LOWORD(v3) = sub_FB0750(this, 1u);
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
    LOWORD(v3) = sub_FB0750(this, 1u);
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

//----- (00FB08F0) --------------------------------------------------------
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

//----- (00FB0960) --------------------------------------------------------
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

//----- (00FB09A0) --------------------------------------------------------
int __cdecl sub_FB09A0(wchar_t *Dst, int a2, __int64 a3)
{
  int result; // eax

  if ( gConfig.bShowCpuFractions )
    result = swprintf_s(Dst, 0x20u, L"%s%0.2f%%", a2, a3);
  else
    result = swprintf_s(Dst, 0x20u, L"%s%0.0f%%", a2, a3);
  return result;
}

//----- (00FB09F0) --------------------------------------------------------
int __cdecl sub_FB09F0(wchar_t *Dst, int a2, __int64 a3)
{
  int result; // eax

  if ( gConfig.bShowCpuFractions )
    result = swprintf_s(Dst, 0x400u, L"%s%0.2f%%", a2, a3);
  else
    result = swprintf_s(Dst, 0x400u, L"%s%0.0f%%", a2, a3);
  return result;
}

//----- (00FB0A40) --------------------------------------------------------
errno_t __cdecl sub_FB0A40(wchar_t *a1, int a2, __int64 a3)
{
  return sub_FB2410(a1, 0x400u, a2, a3);
}

//----- (00FB0A70) --------------------------------------------------------
int wsprintfW(wchar_t *Dst, wchar_t *Format, ...)
{
  va_list ArgList; // [esp+10h] [ebp+10h]

  va_start(ArgList, Format);
  return vswprintf_s(Dst, 0x400u, Format, ArgList);
}

//----- (00FB0A90) --------------------------------------------------------
int __thiscall sub_FB0A90(BitmapItem *this, int a2, int a3, int a4, int a5, unsigned int a6, int a7)
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
    sub_FB0E50(this, a3, a2, a3, this->nHeight, v8, 0);
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
          LOBYTE(result) = sub_FB0E50(v21, v11, v9, v11, v21->nHeight, v20, 0);
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
        sub_FB0E50(v21, v11, v9, v11, v21->nHeight, v20, 0);
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

//----- (00FB0CA0) --------------------------------------------------------
char __thiscall BitmapItem_Create(BitmapItem *this, LONG nWidth, signed int nHeight)
{
  BitmapItem *v3; // ST24_4
  HDC hDC; // ebx
  HDC v5; // eax
  void *v6; // ST14_4
  BITMAPINFO bi; // [esp+10h] [ebp-2Ch]

  v3 = this;
  hDC = GetDC(0);
  _mm_storeu_si128(&bi.bmiHeader.biWidth, 0i64);
  bi.bmiHeader.biClrImportant = 0;
  bi.bmiHeader.biSize = offsetof(BITMAPINFO, bmiColors);
  bi.bmiHeader.biHeight = -nHeight;
  bi.bmiHeader.biWidth = nWidth;
  *&bi.bmiHeader.biPlanes = 0x200001;
  _mm_storeu_si128(&bi.bmiHeader.biSizeImage, 0i64);
  bi.bmiHeader.biClrUsed = 0;
  bi.bmiHeader.biCompression = 0;
  bi.bmiHeader.biSizeImage = 0;
  v3->hBitmapHandle = CreateDIBSection(hDC, &bi, 0, &v3->pBits, 0, 0);
  v3->nHeight = nHeight;
  v3->nWidth = nWidth;
  v5 = CreateCompatibleDC(hDC);
  v6 = v3->hBitmapHandle;
  v3->CompatibleDC = v5;
  SelectObject(v5, v6);
  ReleaseDC(0, hDC);
  return 1;
}

//----- (00FB0D60) --------------------------------------------------------
char __thiscall BitmapItem_SetRectColor(BitmapItem *this, RECT *lprc, unsigned int color)
{
  RECT *v3; // edx
  LONG left; // esi
  BitmapItem *pItem; // ebx
  LONG top; // eax
  int right; // ecx
  LONG y; // edi
  LONG bottom; // eax
  int nHeight; // edx
  LONG x; // eax
  int nBit; // edx
  int i; // [esp+Ch] [ebp-8h]
  LONG left_1; // [esp+10h] [ebp-4h]
  RECT *nWidth; // [esp+1Ch] [ebp+8h]

  v3 = lprc;
  left = 0;
  pItem = this;
  if ( lprc->left > 0 )
    left = lprc->left;
  top = lprc->top;
  right = this->nWidth;
  left_1 = left;
  if ( lprc->right < right )
    right = lprc->right;
  y = 0;
  nWidth = right;
  if ( top > 0 )
    y = top;
  bottom = v3->bottom;
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
        pItem->pBits[nBit] = (color & 0xFF00) | (color << 16) | (color >> 16) & 0xFF;
        right = nWidth;
      }
      while ( x < nWidth );
      left = left_1;
      nHeight = i;
    }
  }
  return 1;
}

//----- (00FB0E00) --------------------------------------------------------
int __cdecl sub_FB0E00(wchar_t *Dst, size_t SizeInWords, int a3, __int64 a4)
{
  int result; // eax

  if ( gConfig.bShowCpuFractions )
    result = swprintf_s(Dst, SizeInWords, L"%s%0.2f%%", a3, a4);
  else
    result = swprintf_s(Dst, SizeInWords, L"%s%0.0f%%", a3, a4);
  return result;
}

//----- (00FB0E50) --------------------------------------------------------
char __thiscall sub_FB0E50(BitmapItem *this, int a2, int a3, int a4, int a5, unsigned int a6, int a7)
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
  sub_FB0A90(v8, v12, v7, v14, v10, a6, a7);
  return 1;
}

//----- (00FB0ED0) --------------------------------------------------------
char __thiscall sub_FB0ED0(_DWORD *this, int a2, int a3, int a4, int a5, unsigned int a6, char a7)
{
  int v7; // esi
  _DWORD *v8; // ebx
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
    v9 = this[2];
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
    v11 = this[2];
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
    v13 = v8[1];
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
    v15 = v8[1];
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
          v20 = (a6 >> 1) | (((BYTE1(a6) | ((BYTE2(a6) & 0xFE) << 8)) & 0xFFFE) << 7);
        else
          v20 = a6;
        v21 = (v20 & 0xFF00) | (v20 << 16) | (v20 >> 16) & 0xFF;
        v22 = v7++ + v12 * v8[2];
        *(v8[4] + 4 * v22) = v21;
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
      v16 = (a6 >> 1) | (((BYTE1(a6) | ((BYTE2(a6) & 0xFE) << 8)) & 0xFFFE) << 7);
    else
      v16 = a6;
    v17 = (v16 & 0xFF00) | (v16 << 16) | (v16 >> 16) & 0xFF;
    v18 = v12++ * v8[2];
    *(v8[4] + 4 * (v7 + v18)) = v17;
  }
  while ( v12 < a5 );
  return 1;
}

//----- (00FB1020) --------------------------------------------------------
void __cdecl CGraphData_Update(CGraphData *pGraphData, FILETIME time, double dbMemorySize, double a5, wchar_t *a6)
{
  WCHAR *v5; // ebx
  WCHAR **v6; // edx
  int v7; // ecx
  int v8; // ecx
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
    if ( a5 <= pGraphData->m_Item[0].dbMemorySize )
    {
      if ( a5 < 0.0 )
        a5 = 0.0;
    }
    else
    {
      a5 = db_onehundred;
    }
    v5 = _wcsdup(a6);
    EnterCriticalSection(&pGraphData->m_Lock.m_Lock);
    v6 = pGraphData->m_pBuffer;
    if ( v6 )
    {
      v7 = pGraphData->m_nWidth;
      if ( v6[v7] )
        free(v6[v7]);
      v8 = pGraphData->m_nWidth;
      v9 = pGraphData->m_pBuffer;
      if ( a6 )
        v9[v8] = v5;
      else
        v9[v8] = 0;
    }
    pGraphData->m_pBuffer1[pGraphData->m_nWidth] = (*&time - *&pGraphData->m_Time) / 10000000;
    pGraphData->m_Item[0].pBuffer[pGraphData->m_nWidth] = dbMemorySize_1;
    v10 = pGraphData->m_Item[1].pBuffer;
    if ( v10 )
      v10[pGraphData->m_nWidth] = a5;
    if ( ++pGraphData->m_nWidth >= gdwVirtualScreenWidth )
      pGraphData->m_nWidth = 0;
    LeaveCriticalSection(&pGraphData->m_Lock.m_Lock);
  }
}
// 103CDC0: using guessed type double db_onehundred;
// 1064E28: using guessed type int gdwVirtualScreenWidth;

//----- (00FB1160) --------------------------------------------------------
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
  result = malloc(sizeof(CGraphData) * nCount);
  pGrahData = result;
  if ( nCount > 0 )
  {
    lpSystemTimeAsFileTime = &result->m_Time;
    pBuffer = &result->m_pBuffer;
    do
    {
      memset(pBuffer - 2144, 0, sizeof(CGraphData));
      pGrahData->m_nChildID = nChildID;
      InitializeCriticalSection((pBuffer - 2144));
      GetSystemTimeAsFileTime(lpSystemTimeAsFileTime);
      v6 = malloc(4 * gdwVirtualScreenWidth);
      *(pBuffer + 3) = v6;
      memset(v6, 0, 4 * gdwVirtualScreenWidth);
      if ( fFlags )
      {
        v7 = malloc(4 * gdwVirtualScreenWidth);
        *pBuffer = v7;
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
          *v8 = v10;
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
// FB125E: CONTAINING_RECORD: no field 'UCHAR *' in struct 'CGraphData' at 2200
// 1064E28: using guessed type int gdwVirtualScreenWidth;

//----- (00FB1280) --------------------------------------------------------
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
      v3 = &pGraphData->m_pBuffer;
      v9 = &pGraphData->m_pBuffer;
      do
      {
        free(v3[3]);
        if ( *v3 )
        {
          v4 = gdwVirtualScreenWidth;
          for ( i = 0; i < v4; ++i )
          {
            if ( *(*v3 + i) )
            {
              free(*(*v3 + i));
              v4 = gdwVirtualScreenWidth;
            }
          }
          free(*v3);
        }
        v6 = 0;
        if ( v2->m_nChildID > 0 )
        {
          v7 = v3 - 523;
          do
          {
            free(*v7);
            ++v6;
            v7 += 6;
          }
          while ( v6 < pGraphData->m_nChildID );
          v3 = v9;
          v2 = pGraphData;
        }
        DeleteCriticalSection((v3 - 536));
        v3 += 550;
        v8 = nCount-- == 1;
        v9 = v3;
      }
      while ( !v8 );
    }
    free(v2);
  }
}
// 1064E28: using guessed type int gdwVirtualScreenWidth;

//----- (00FB1340) --------------------------------------------------------
HWND __cdecl CreateGraphWindow(HWND hDlg, int nIDDlgItem, PVOID pParam)
{
  HWND v3; // eax
  HWND v4; // eax
  HWND hWnd; // eax
  struct tagRECT Rect; // [esp+Ch] [ebp-14h]

  v3 = GetDlgItem(hDlg, nIDDlgItem);
  GetWindowRect(v3, &Rect);
  MapWindowPoints(0, hDlg, &Rect, 2u);
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
    || nIDDlgItem >= IDC_SYSINFO_CPU_STATIC_CPU_CHART && nIDDlgItem < 2500
    || nIDDlgItem >= IDC_SYSINFO_GPU_NODES_STATIC_GRAPH && nIDDlgItem < 2600 )
  {
    hWnd = CreateWindowExW(
             0,
             L"CpuGraphClassGraph",
             &gszNullString,
             0x50000000u,
             Rect.left,
             Rect.top,
             Rect.right - Rect.left,
             Rect.bottom - Rect.top,
             hDlg,
             nIDDlgItem,
             ghInstance,
             pParam);
  }
  else
  {
    hWnd = CreateWindowExW(
             0,
             L"CpuGraphClassChart",
             &gszNullString,
             0x50000000u,
             Rect.left,
             Rect.top,
             Rect.right - Rect.left,
             Rect.bottom - Rect.top,
             hDlg,
             nIDDlgItem,
             ghInstance,
             pParam);
  }
  return hWnd;
}
// 103CB88: using guessed type wchar_t aCpugraphclassc[19];

//----- (00FB1470) --------------------------------------------------------
HGDIOBJ __cdecl GraphData_DrawGraph(CGraphData *pGraphData, HDC hDC, RECT *lprc)
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
  LONG v16; // ebx
  double v17; // xmm2_8
  int v18; // edx
  double v19; // xmm3_8
  double v20; // xmm1_8
  CGraphData *v21; // eax
  LONG v22; // ecx
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
  const wchar_t *v35; // [esp+4h] [ebp-108h]
  double v36; // [esp+14h] [ebp-F8h]
  int v37[2]; // [esp+1Ch] [ebp-F0h]
  unsigned int v38; // [esp+24h] [ebp-E8h]
  LONG v39; // [esp+28h] [ebp-E4h]
  HDC v40; // [esp+2Ch] [ebp-E0h]
  RECT *v41; // [esp+30h] [ebp-DCh]
  int v42; // [esp+34h] [ebp-D8h]
  double v43; // [esp+38h] [ebp-D4h]
  LONG v44; // [esp+40h] [ebp-CCh]
  CGraphData *v45; // [esp+44h] [ebp-C8h]
  HGDIOBJ ho; // [esp+48h] [ebp-C4h]
  int cy; // [esp+4Ch] [ebp-C0h]
  int v48; // [esp+50h] [ebp-BCh]
  HDC hdc; // [esp+54h] [ebp-B8h]
  void *v50; // [esp+58h] [ebp-B4h]
  __int64 v51; // [esp+5Ch] [ebp-B0h]
  int a2a; // [esp+64h] [ebp-A8h]
  struct tagRECT rc; // [esp+68h] [ebp-A4h]
  RECT rect; // [esp+78h] [ebp-94h]
  __int16 Dst[32]; // [esp+88h] [ebp-84h]
  __int16 chText[32]; // [esp+C8h] [ebp-44h]

  v40 = hDC;
  v45 = pGraphData;
  v3 = lprc->right - lprc->left;
  v42 = lprc->bottom - lprc->top;
  v41 = lprc;
  cy = 0;
  v48 = 0;
  hdc = 0;
  ho = 0;
  v39 = v3;
  BitmapItem_Create(&ho, v3, v42);
  EnterCriticalSection(&pGraphData->m_Lock.m_Lock);
  v4 = pGraphData->m_nWidth - 1;
  if ( v4 < 0 )
    v4 = gdwVirtualScreenWidth - 1;
  v7 = __OFSUB__(pGraphData->m_nChildID, 1);
  v5 = pGraphData->m_nChildID == 1;
  v6 = (pGraphData->m_nChildID - 1) < 0;
  v51 = *&pGraphData->m_Item[0].pBuffer[v4];
  if ( (v6 ^ v7) | v5 )
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
      if ( pGraphData->m_nChildID != 1 && *&v51 <= v43 )
        v9 = *&v43;
      sub_FB09A0(chText, &gszNullString, v9);
      goto LABEL_18;
    case 1u:
    case 3u:
    case 5u:
    case 6u:
    case 7u:
      wcscpy_s(Dst, 0x20u, L" KB");
      v10 = v51;
      if ( *&v51 <= 1048576.0 )
      {
        if ( *&v51 <= 1024.0 )
          goto LABEL_16;
        v11 = *&v51 * 0.0009765625;
        v35 = L" MB";
      }
      else
      {
        v11 = *&v51 * 0.00000095367431640625;
        v35 = L" GB";
      }
      *&v51 = v11;
      wcscpy_s(Dst, 0x20u, v35);
      v10 = v51;
LABEL_16:
      swprintf_s(chText, 0x20u, L"%s%0.1f", &gszNullString, v10, HIDWORD(v10));
      wcscat_s(chText, 0x20u, Dst);
LABEL_18:
      SetBkColor(hdc, 0);
      SetTextColor(hdc, 0);
      v12 = DrawTextW(hdc, chText, -1, &rc, DT_CALCRECT);
      rect.top = 0;
      rect.left = (v3 / 3.0 * 0.5);
      rect.right = v3 - rect.left;
      HIDWORD(v51) = v42 - v12;
      rect.bottom = v42 - v12 - 2;
      v13 = GetSysColor(5);
      if ( v50 && cy * v48 )
        memset32(v50, (v13 & 0xFF00) | (v13 << 16) | (v13 >> 16) & 0xFF, cy * v48);
      BitmapItem_SetRectColor(&ho, &rect, gConfig.ColorGraphBk);
      v14 = pGraphData->m_nChildID;
      v15 = 0;
      v16 = rect.top;
      v44 = rect.top;
      if ( v14 > 0 )
      {
        v17 = rect.bottom;
        v18 = &v45->m_dbMemorySize;
        v19 = (rect.bottom - rect.top);
        do
        {
          v20 = *(*(v18 + 12) + 8 * v4) / *v18;
          v18 += 24;
          v37[v15++] = (v17 - v20 * v19);
        }
        while ( v15 < v14 );
      }
      if ( v16 < rect.bottom )
      {
        v21 = v45;
        v22 = rect.bottom;
        while ( 1 )
        {
          v23 = 0;
          v24 = 0x828282;
          if ( v21->m_nChildID > 0 )
            break;
LABEL_52:
          v44 = ++v16;
          if ( v16 >= v22 )
            goto LABEL_53;
        }
        v25 = &v21->m_Color;
        a2a = &v21->m_Color;
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
              v25 = a2a;
              v16 = v44;
              v24 = (((BYTE1(v24) + (256 - BYTE1(v24)) / 2) | ((BYTE2(v24) + (256 - BYTE2(v24)) / 2) << 8)) << 8) | (BYTE4(v43) + (256 - BYTE4(v43)) / 2);
            }
          }
          v21 = v45;
          ++v23;
          v25 += 6;
          a2a = v25;
        }
        while ( v23 < v45->m_nChildID );
        if ( v24 == 0x828282 )
        {
LABEL_51:
          v22 = rect.bottom;
          goto LABEL_52;
        }
        v27 = rect.left;
        v28 = v16;
        v29 = rect.right;
        a2a = v16;
        if ( rect.left >= 0 )
        {
          if ( rect.left >= v48 )
            v27 = v48 - 1;
        }
        else
        {
          v27 = 0;
        }
        if ( rect.right >= 0 )
        {
          if ( rect.right >= v48 )
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
            sub_FB0A90(&ho, a2a, v27, v28, v29, v24, 0);
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
      ++rect.right;
      v31 = v30;
      FrameRect(hdc, &rect, v30);
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
      DrawTextW(hdc, chText, -1, &rc, 5u);
      BitBlt(v40, v41->left, v41->top, v48, cy, hdc, 0, 0, 0xCC0020u);
      if ( hdc )
        DeleteDC(hdc);
      result = ho;
      if ( ho )
        result = DeleteObject(ho);
      return result;
    case 2u:
    case 8u:
    case 9u:
      sub_FC3C40(chText, 0x20u, COERCE__INT64(*&v51 - v43 + v43));
      goto LABEL_18;
    default:
      goto LABEL_18;
  }
}
// 103CBE0: using guessed type wchar_t aGb[4];
// 1064E28: using guessed type int gdwVirtualScreenWidth;
// FB1470: using guessed type int var_F0[2];

//----- (00FB1A60) --------------------------------------------------------
HICON __cdecl GraphData_DrawChart(CGraphData *pGraphData, HDC hDC, RECT *lprc, COLORREF Color, DWORD dwValue, double dbValue)
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
  LONG bottom_1; // eax
  LONG index; // edi
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
  RECT *lprc_1; // [esp+40h] [ebp-4Ch]
  int v64; // [esp+44h] [ebp-48h]
  int v65; // [esp+48h] [ebp-44h]
  int v66; // [esp+4Ch] [ebp-40h]
  BitmapItem BitmapItem; // [esp+50h] [ebp-3Ch]
  LONG bottom; // [esp+64h] [ebp-28h]
  int right; // [esp+68h] [ebp-24h]
  unsigned int a6; // [esp+6Ch] [ebp-20h]
  tagGraphItem *pItem_1; // [esp+70h] [ebp-1Ch]
  int v72; // [esp+74h] [ebp-18h]
  RECT rc; // [esp+78h] [ebp-14h]
  COLORREF Colora; // [esp+A0h] [ebp+14h]

  hCompatibleDC = 0;
  lprc_1 = lprc;
  nWidth = lprc->right - lprc->left;
  nHeight = lprc->bottom - lprc->top;
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
  DeleteObject = ::DeleteObject;
  if ( hDC && (!nWidth || !nHeight) )
    goto LABEL_111;
  BitmapItem_Create(&BitmapItem, nWidth, nHeight);
  nSize = BitmapItem.nHeight * BitmapItem.nWidth;
  if ( BitmapItem.pBits && nSize )
    memset32(BitmapItem.pBits, (Colora & 0xFF00) | (Colora << 16) | (Colora >> 16) & 0xFF, nSize);
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
    v16 = (v14 - pGraphData_1->m_nChildID) < 0;
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
      if ( v21 <= v20 )
        a6 = a6 < v20 ? 0xFF0000 : 255;
      else
        a6 = a6 < v21 ? 0xFF00 : 255;
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
        v27 = v26 * bottom;
        v28 = bottom - v27;
        if ( v23 != -1 && v25 != 0.0 )
        {
          v29 = v72;
          v30 = bottom - v27;
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
          sub_FB0A90(&BitmapItem, v30, v29, v23, v31, a6, 1);
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
    if ( lprc_1->bottom > 0 )
    {
      y = 0;
      do
      {
        if ( y >= bottom_1 )
          break;
        if ( !(index % 15) )
          sub_FB0ED0(&BitmapItem, 0, y, right, y, 0x828282u, 0);
        ++index;
        y += 2;
        bottom_1 = bottom;
      }
      while ( index < lprc_1->bottom );
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
        v42 = v41 * bottom;
        v43 = bottom - v42;
        v44 = v72;
        v65 = bottom - v42;
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
      pItem_1 = a6;
      v45 = a6 + 2;
      v57 = a6 + 2;
      v46 = bottom - v42;
      v58 = *(&pGraphData->m_Color + 6 * v66);
      v47 = v72;
      if ( (a6 & 0x80000000) != 0 )
      {
        pItem_1 = 0;
        goto LABEL_73;
      }
      if ( a6 >= BitmapItem.nWidth )
      {
        pItem_1 = (BitmapItem.nWidth - 1);
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
      sub_FB0A90(&BitmapItem, v46, pItem_1, v47, v48, v58, 0);
      v49 = v43 + 1;
      if ( v43 + 1 < bottom )
      {
        v50 = v72 + 1;
        pItem_1 = a6;
        if ( (a6 & 0x80000000) != 0 )
        {
          v51 = 0;
          goto LABEL_92;
        }
        if ( a6 >= BitmapItem.nWidth )
        {
          v51 = (BitmapItem.nWidth - 1);
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
        sub_FB0A90(&BitmapItem, v49, pItem_1, v50, v45, *(&pGraphData->m_Color + 6 * v66), 0);
      }
      gdwVirtualScreenWidth = ::gdwVirtualScreenWidth;
      goto LABEL_107;
    }
LABEL_108:
    nChildID = v61;
    pGraphData_1 = pGraphData;
  }
  hBrush = CreateSolidBrush(0x828282u);
  rc.left = 0;
  rc.right = right;
  rc.bottom = bottom;
  rc.top = 0;
  FrameRect(BitmapItem.CompatibleDC, &rc, hBrush);
  DeleteObject = ::DeleteObject;
  ::DeleteObject(hBrush);
  if ( hdc )
  {
    BitBlt(
      hdc,
      lprc_1->left,
      lprc_1->top,
      BitmapItem.nWidth,
      BitmapItem.nHeight,
      BitmapItem.CompatibleDC,
      0,
      0,
      0xCC0020u);
    hCompatibleDC = BitmapItem.CompatibleDC;
LABEL_111:
    v53 = 0;
    goto __quit;
  }
  piconinfo.hbmColor = BitmapItem.hBitmapHandle;
  piconinfo.hbmMask = BitmapItem.hBitmapHandle;
  piconinfo.fIcon = 1;
  piconinfo.xHotspot = 0;
  piconinfo.yHotspot = 0;
  v53 = CreateIconIndirect(&piconinfo);
  hCompatibleDC = BitmapItem.CompatibleDC;
__quit:
  if ( hCompatibleDC )
    DeleteDC(hCompatibleDC);
  if ( BitmapItem.hBitmapHandle )
    DeleteObject(BitmapItem.hBitmapHandle);
  return v53;
}
// 1064E28: using guessed type int gdwVirtualScreenWidth;

//----- (00FB1FD0) --------------------------------------------------------
char *__cdecl sub_FB1FD0(FILETIME *a1, HDC hDC, RECT *lprc, COLORREF ColorBack)
{
  char *nWidth; // eax
  signed int nHeight; // ecx
  COLORREF Color; // ebx
  unsigned int nSize; // ecx
  float v8; // xmm0_4
  char *v9; // edi
  float v10; // xmm0_4
  LONG v11; // ebx
  HBRUSH hBrush; // esi
  RECT rect; // [esp+8h] [ebp-64h]
  struct _FILETIME FileTime; // [esp+18h] [ebp-54h]
  RECT *v15; // [esp+20h] [ebp-4Ch]
  char *nWidth_1; // [esp+24h] [ebp-48h]
  LONG nHeight_1; // [esp+28h] [ebp-44h]
  HDC hdc; // [esp+2Ch] [ebp-40h]
  BitmapItem BitmapItem; // [esp+30h] [ebp-3Ch]
  float v20; // [esp+44h] [ebp-28h]
  struct _SYSTEMTIME SystemTime; // [esp+48h] [ebp-24h]
  RECT rc; // [esp+58h] [ebp-14h]

  v20 = *&a1;
  nWidth = (lprc->right - lprc->left);
  nHeight = lprc->bottom - lprc->top;
  Color = ColorBack;
  if ( ColorBack == -1 )
    Color = gConfig.ColorGraphBk;
  hdc = hDC;
  v15 = lprc;
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
      memset32(BitmapItem.pBits, (Color & 0xFF00) | (Color << 16) | (Color >> 16) & 0xFF, nSize);
    GetSystemTime(&SystemTime);
    SystemTimeToFileTime(&SystemTime, &FileTime);
    rect.top = 0;
    v8 = (*&FileTime - *LODWORD(v20));
    v20 = v8;
    v9 = nWidth_1;
    v10 = (*&FileTime - *&gCreateTimeLast);
    v11 = nHeight_1;
    rect.right = nWidth_1;
    rect.bottom = nHeight_1;
    rect.left = &nWidth_1[-((v20 / v10) * nWidth_1)];
    BitmapItem_SetRectColor(&BitmapItem, &rect, 0x9ECA9Eu);
    hBrush = CreateSolidBrush(0x828282u);
    rc.left = 0;
    rc.top = 0;
    rc.right = v9;
    rc.bottom = v11;
    FrameRect(BitmapItem.CompatibleDC, &rc, hBrush);
    DeleteObject(hBrush);
    BitBlt(hdc, v15->left, v15->top, BitmapItem.nWidth, BitmapItem.nHeight, BitmapItem.CompatibleDC, 0, 0, 0xCC0020u);
    if ( BitmapItem.CompatibleDC )
      DeleteDC(BitmapItem.CompatibleDC);
    nWidth = BitmapItem.hBitmapHandle;
    if ( BitmapItem.hBitmapHandle )
      nWidth = DeleteObject(BitmapItem.hBitmapHandle);
  }
  return nWidth;
}

//----- (00FB21A0) --------------------------------------------------------
int __cdecl GraphData_QueryData(CGraphData *pGraphData, double *pArg1, double *pArg2)
{
  int nWidth; // edi

  EnterCriticalSection(&pGraphData->m_Lock.m_Lock);
  nWidth = pGraphData->m_nWidth - 1;
  if ( nWidth < 0 )
    nWidth = gdwVirtualScreenWidth - 1;
  *pArg1 = pGraphData->m_Item[0].pBuffer[nWidth];
  if ( pArg2 && pGraphData->m_nChildID > 1 )
    *pArg2 = pGraphData->m_Item[1].pBuffer[nWidth];
  LeaveCriticalSection(&pGraphData->m_Lock.m_Lock);
  return nWidth;
}
// 1064E28: using guessed type int gdwVirtualScreenWidth;

//----- (00FB2200) --------------------------------------------------------
int __cdecl sub_FB2200(char a1, wchar_t *a2, size_t SizeInWords, __int64 a4, __int64 a5, __int64 a6)
{
  char v6; // al
  char v7; // dl
  int v8; // esi
  __int64 v9; // xmm3_8
  __int64 v10; // xmm0_8
  __int64 v11; // xmm1_8
  __int64 v12; // xmm4_8
  __int64 v13; // xmm2_8
  double v14; // xmm0_8
  double v15; // xmm1_8
  signed int v16; // edi
  size_t v17; // ecx
  double v18; // xmm0_8
  int v19; // eax
  const wchar_t *v20; // eax
  char v22; // [esp+1Eh] [ebp-1Eh]
  char v23; // [esp+1Fh] [ebp-1Dh]
  __int64 v24; // [esp+20h] [ebp-1Ch]
  double v25; // [esp+28h] [ebp-14h]
  __int64 v26; // [esp+30h] [ebp-Ch]

  v6 = 0;
  v7 = 0;
  v22 = 0;
  v8 = 0;
  v23 = 0;
  if ( !a1 )
    return sub_FC3C40(a2, SizeInWords, COERCE__INT64(*&a4 + *&a5));
  v9 = a6;
  v10 = a5;
  if ( *&a6 <= *&a5 )
    v11 = a6;
  else
    v11 = a5;
  if ( *&a5 <= *&a6 )
    v10 = a6;
  v12 = a4;
  if ( *&v10 <= *&a4 )
    v13 = v10;
  else
    v13 = a4;
  if ( *&a4 > *&v10 )
    v10 = a4;
  v24 = v10;
  v14 = *&v13;
  if ( *&v11 <= *&v13 )
    v13 = v11;
  if ( v14 <= *&v11 )
    v14 = *&v11;
  v15 = *&dbl_103CDD8;
  *a2 = 0;
  v16 = 0;
  v17 = SizeInWords;
  v25 = v14;
  v26 = v13;
  do
  {
    v18 = *(&v24 + v16);
    if ( v18 != v15 )
    {
      if ( v8 > 0 )
      {
        v18 = *(&v24 + v16);
        v9 = a6;
        v8 += swprintf_s(&a2[v8], v17 - v8, L"\n");
        v15 = *&dbl_103CDD8;
        v12 = a4;
        v17 = SizeInWords;
        v6 = v22;
        v7 = v23;
      }
      if ( v18 != *&a5 || v7 )
      {
        if ( v18 != *&v12 || v6 )
        {
          v19 = swprintf_s(&a2[v8], v17 - v8, L"O: ");
        }
        else
        {
          v20 = L"R";
          if ( *&v9 == v15 )
            v20 = L"R+O";
          v19 = swprintf_s(&a2[v8], v17 - v8, L"%s: ", v20);
          v22 = 1;
        }
      }
      else
      {
        v19 = swprintf_s(&a2[v8], v17 - v8, L"W: ");
        v23 = 1;
      }
      v9 = a6;
      v15 = *&dbl_103CDD8;
      v8 += sub_FC3C40(&a2[v19 + v8], SizeInWords - (v19 + v8), *(&v24 + v16)) + v19;
      v12 = a4;
      v17 = SizeInWords;
      v6 = v22;
      v7 = v23;
    }
    ++v16;
  }
  while ( v16 < 3 );
  return v8;
}
// 103CBB8: using guessed type wchar_t aR[2];
// 103CBBC: using guessed type wchar_t aRO[4];

//----- (00FB2410) --------------------------------------------------------
errno_t __cdecl sub_FB2410(wchar_t *a1, rsize_t SizeInWords, int a3, __int64 a4)
{
  double v4; // xmm0_8
  const wchar_t *v6; // [esp+4h] [ebp-50h]
  wchar_t Dst; // [esp+10h] [ebp-44h]

  wcscpy_s(&Dst, 0x20u, L" KB");
  v4 = *&a4;
  if ( *&a4 > 1048576.0 )
  {
    v4 = *&a4 * 0.00000095367431640625;
    v6 = L" GB";
LABEL_5:
    wcscpy_s(&Dst, 0x20u, v6);
    goto LABEL_6;
  }
  if ( *&a4 > 1024.0 )
  {
    v4 = *&a4 * 0.0009765625;
    v6 = L" MB";
    goto LABEL_5;
  }
LABEL_6:
  swprintf_s(a1, SizeInWords, L"%s%0.1f", a3, LODWORD(v4), HIDWORD(v4));
  return wcscat_s(a1, SizeInWords, &Dst);
}
// 103CBE0: using guessed type wchar_t aGb[4];

//----- (00FB24C0) --------------------------------------------------------
void __cdecl sub_FB24C0(int a1)
{
  wchar_t *v1; // edi
  __int16 v2; // si
  int v3; // esi
  int v4; // edx
  _DWORD *v5; // edx
  int v6; // eax
  __int16 *v7; // ecx
  __int16 v8; // ax
  wchar_t *v9; // eax
  int v10; // ecx
  int v11; // eax
  int v12; // edx
  __int16 *v13; // ecx
  __int16 v14; // ax
  int v15; // ecx
  const wchar_t *v16; // eax
  int v17; // ecx
  __int64 v18; // ST14_8
  __int64 v19; // [esp+10h] [ebp-2D4h]
  int v20; // [esp+14h] [ebp-2D0h]
  int v21; // [esp+14h] [ebp-2D0h]
  struct _FILETIME LocalFileTime; // [esp+24h] [ebp-2C0h]
  FILETIME FileTime; // [esp+2Ch] [ebp-2B8h]
  int v24; // [esp+34h] [ebp-2B0h]
  struct _SYSTEMTIME SystemTime; // [esp+38h] [ebp-2ACh]
  struct tagRECT Rect; // [esp+48h] [ebp-29Ch]
  wchar_t Dst; // [esp+58h] [ebp-28Ch]
  WCHAR TimeStr; // [esp+260h] [ebp-84h]

  v1 = (a1 + 4);
  *(a1 + 4) = 0;
  GetClientRect(*a1, &Rect);
  v2 = *(a1 + 2052);
  if ( (Rect.right - v2 - 1) / 2 <= gdwVirtualScreenWidth )
  {
    EnterCriticalSection(*(a1 + 2056));
    v3 = (*(*(a1 + 2056) + 24) - (Rect.right - *(a1 + 2052)) / 2 + gdwVirtualScreenWidth - 1) % gdwVirtualScreenWidth;
    v4 = *(a1 + 2056);
    if ( !*(*(v4 + 2156) + 4 * v3) )
    {
LABEL_52:
      LeaveCriticalSection(*(a1 + 2056));
      *(a1 + 2052) += 20;
      *(a1 + 2054) += 20;
      goto LABEL_53;
    }
    switch ( *(v4 + 32) )
    {
      case 0:
        wsprintfW(v1, L"CPU\n");
        break;
      case 2:
        wsprintfW(v1, L"I/O\n");
        break;
      case 4:
        wsprintfW(v1, L"GPU\n");
        break;
      case 8:
        wsprintfW(v1, L"Disk\n");
        break;
      case 9:
        wsprintfW(v1, L"Network\n");
        break;
      default:
        break;
    }
    v5 = *(a1 + 2056);
    if ( v5[536] )
    {
      v6 = v5[8];
      if ( !v6 || v6 == 4 )
      {
        v7 = (a1 + 4);
        v24 = a1 + 6;
        do
        {
          v8 = *v7;
          ++v7;
        }
        while ( v8 );
        sub_FB0E00((a1 + 4 + 2 * ((v7 - v24) >> 1)), 1024 - ((v7 - v24) >> 1), &gszNullString, *(v5[13] + 8 * v3));
        wcscat_s(v1, 0x400u, L"\n");
      }
      v9 = *(*(*(a1 + 2056) + 2144) + 4 * v3);
      if ( !v9 || !*v9 )
        goto LABEL_51;
    }
    else
    {
      if ( !v5[543] )
      {
        *v1 = 0;
        if ( *(v5[539] + 4 * v3) )
        {
          v15 = v5[8];
          switch ( v15 )
          {
            case 0:
            case 4:
              v16 = L"GPU\n";
              v19 = *(v5[13] + 8 * v3);
              if ( v15 != 4 )
                v16 = L"CPU\n";
              sub_FB09F0(v1, v16, v19);
              break;
            case 1:
              sub_FB0A40(v1, L"System Commit\n", *(v5[13] + 8 * v3));
              break;
            case 2:
              wsprintfW(v1, L"I/O\n");
              goto LABEL_48;
            case 3:
              sub_FB0A40(v1, L"Physical Memory\n", *(v5[13] + 8 * v3));
              break;
            case 5:
              sub_FB0A40(v1, L"GPU System Memory\n", *(v5[13] + 8 * v3));
              break;
            case 6:
              sub_FB0A40(v1, L"GPU Dedicated Memory\n", *(v5[13] + 8 * v3));
              break;
            case 7:
              sub_FB0A40(v1, L"GPU Committed Memory\n", *(v5[13] + 8 * v3));
              break;
            case 8:
              wsprintfW(v1, L"Disk\n");
              goto LABEL_48;
            case 9:
              wsprintfW(v1, L"Network\n");
LABEL_48:
              v17 = *(a1 + 2056);
              v18 = *(*(v17 + 76) + 8 * v3);
              sub_FB2200(1, v1, 0x400u, COERCE__INT64(*(*(v17 + 52) + 8 * v3) - *&v18), v18, dbl_103CDD8);
              break;
            default:
              break;
          }
          if ( *v1 )
            wcscat_s(v1, 0x400u, L"\n");
        }
        goto LABEL_51;
      }
      v20 = v5[542];
      if ( v5[8] == 4 )
      {
        wsprintfW(v1, L"GPU Engine %d: ", v20);
      }
      else
      {
        v10 = wsprintfW(v1, L"CPU %d", v20);
        v11 = *(a1 + 2056);
        v12 = *(v11 + 2160);
        if ( v12 != -1 )
        {
          v21 = *(v11 + 2164);
          if ( v12 == 1 )
            swprintf_s((a1 + 4 + 2 * v10), 1024 - v10, L" (Node %d)", v21);
          else
            swprintf_s((a1 + 4 + 2 * v10), 1024 - v10, L" (Core %d)", v21);
        }
      }
      wcscat_s(v1, 0x400u, L" ");
      v13 = (a1 + 4);
      do
      {
        v14 = *v13;
        ++v13;
      }
      while ( v14 );
      sub_FB0E00(
        (a1 + 4 + 2 * ((v13 - a1 - 6) >> 1)),
        1024 - ((v13 - a1 - 6) >> 1),
        &gszNullString,
        *(*(*(a1 + 2056) + 52) + 8 * v3));
      if ( !*(*(*(*(a1 + 2056) + 2172) + 2144) + 4 * v3) )
      {
LABEL_51:
        FileTime = (*(*(a1 + 2056) + 2148) + 10000000i64 * *(*(*(a1 + 2056) + 2156) + 4 * v3));
        FileTimeToLocalFileTime(&FileTime, &LocalFileTime);
        FileTimeToSystemTime(&LocalFileTime, &SystemTime);
        GetTimeFormatW(0x400u, 0, &SystemTime, 0, &TimeStr, 64);
        wcscat_s(v1, 0x400u, &TimeStr);
        goto LABEL_52;
      }
      if ( *v1 )
        wcscat_s(v1, 0x400u, L"\n");
      wcscpy_s(&Dst, 0x104u, *(*(*(*(a1 + 2056) + 2172) + 2144) + 4 * v3));
      if ( wcschr(&Dst, 0xAu) )
        *wcschr(&Dst, 0xAu) = 32;
      v9 = &Dst;
    }
    wcscat_s(v1, 0x400u, v9);
    wcscat_s(v1, 0x400u, L"\n");
    goto LABEL_51;
  }
  *(a1 + 2054) += 10;
  *(a1 + 2052) = v2 + 10;
LABEL_53:
  *(a1 + 2060) = 1;
}
// 103CC54: using guessed type wchar_t aCpu[5];
// 103CC9C: using guessed type wchar_t aNodeD[11];
// 103CCCC: using guessed type wchar_t aPhysicalMemory[17];
// 103CCF0: using guessed type wchar_t aSystemCommit[15];
// 103CD10: using guessed type wchar_t aGpuDedicatedMe[22];
// 103CD3C: using guessed type wchar_t aGpuSystemMemor[19];
// 103CD64: using guessed type wchar_t aGpuCommittedMe[22];
// 1064E28: using guessed type int gdwVirtualScreenWidth;

//----- (00FB2A70) --------------------------------------------------------
int __cdecl sub_FB2A70(HWND hWnd)
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

//----- (00FB2AE0) --------------------------------------------------------
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
    if ( Flags != 1 )
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
    if ( RegQueryValueExW(hSubKey, szValueName, 0, 0, pThis, &cbData) )
    {
      RegCloseKey(hSubKey);
      return pThis;
    }
    RegCloseKey(hSubKey);
    if ( !RegQueryValueExW(HKEY_PERFORMANCE_DATA, szPerfValueName, 0, 0, 0, &cbData_1) )
    {
      v7 = operator new[](2 * cbData_1);
      pThis->m_PerfValue = v7;
      if ( RegQueryValueExW(HKEY_PERFORMANCE_DATA, szPerfValueName, 0, 0, v7, &cbData_1)
        || (v8 = operator new[](4 * (pThis->m_dwLastCounterOfLastHelp + 1)), (pThis->m_LastCounterOfLastHelp = v8) == 0) )
      {
        j_j__free(pThis->m_PerfValue);
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
        pThis->m_LastCounterOfLastHelp[dwCounter] = psz1;
        psz = &psz1[lstrlenW(psz1) + 1];
      }
    }
  }
  return pThis;
}
// 103CE14: using guessed type wchar_t aExplain009[12];
// 103CE2C: using guessed type wchar_t aLastHelp[10];

//----- (00FB2C80) --------------------------------------------------------
void __thiscall PerformanceInfo::~PerformanceInfo(void **this)
{
  void **v1; // esi
  void *v2; // ST00_4

  v1 = this;
  j_j__free(this[1]);
  v2 = v1[2];
  v1[1] = 0;
  j_j__free(v2);
  v1[2] = 0;
  *v1 = 0;
}

//----- (00FB2CB0) --------------------------------------------------------
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
    if ( ++index > this->m_dwLastCounterOfLastHelp )
      return 0;
  }
  return index;
}

//----- (00FB2D20) --------------------------------------------------------
int __thiscall sub_FB2D20(unsigned int *this, unsigned int a2)
{
  int result; // eax

  if ( a2 <= *this )
    result = *(this[1] + 4 * a2);
  else
    result = 0;
  return result;
}

//----- (00FB2D40) --------------------------------------------------------
LRESULT __cdecl HandleCmdHandler(int a1, HWND hWnd, WPARAM wParam, LPARAM lParam)
{
  int v4; // ecx
  int v5; // esi
  LRESULT result; // eax

  v4 = 0;
  v5 = *(a1 + 4);
  if ( *a1 <= 0 )
  {
LABEL_4:
    switch ( *(a1 + 8) )
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
    while ( *(v5 + 8 * v4) != wParam )
    {
      if ( ++v4 >= *a1 )
        goto LABEL_4;
    }
    result = (*(v5 + 8 * v4 + 4))(hWnd, wParam, wParam >> 16, lParam);
  }
  return result;
}
